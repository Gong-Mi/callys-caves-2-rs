#!/usr/bin/env python3
"""Opcode differential case generator (milestone 1).

Feeds `reconstruction/contracts/opcode-diff-protocol.md`:

    python3 diff/gen_cases.py --seed 0xCA11 --per-op 200 --out diff/cases.jsonl

Determinism: the byte stream is a pure function of (seed, per-op). The RNG is a
local SplitMix64, not `random`, and no set/dict iteration order leaks into the
output, so two runs must be byte-identical on any CPython/uarch.

Per opcode (200 cases each by default) the generator emits, in this order:
  * a tag sweep 0..14 + 0x00FFFFFF, so every opcode sees every tag;
  * curated operand pairs: real 0/+13 (NaN payloads, +/-Inf, +/-0, 1e308,
    5e-324, 2^53), int32/int64 INT_MIN/MAX/0/-1, mixed widths, strings
    "", "12", "1e", "0x10", "abc", undefined/array/pointer/malformed tags,
    divide-by-zero and INT_MIN/-1 overflow;
  * a mode x type sweep over the real DoAdd/DoSet/DoConv format-code pairs
    plus out-of-table codes, so error branches are exercised too;
  * opcode-specific specials (16-bit immediates, conv src x dst table, dup
    modes, zero divisors, malformed-tag operands);
  * seeded random fill up to --per-op.

At least three cases are designed to fail (divide by zero, tag/type mismatch,
undefined operand). They are marked `expect: "error"` in the sidecar meta file;
cases.jsonl itself stays exactly id/op/mode/type/a/b so a strict reader cannot
trip on unknown keys.

Encoding contract (both implementations must decode it the same way)
--------------------------------------------------------------------
16-byte RValue image, little-endian hex, 32 chars:
    +0..+11   payload
    +12..+15  u32 tag word: low 24 bits = tag, high 8 bits = flags (always 0)

    tag 0, 13   f64 at +0 (bytes 8..11 zero)
    tag 7       i32 at +0 (bytes 4..11 zero)
    tag 10      i64 at +0 (bytes 8..11 zero)
    tag 1       inline ASCII, NUL padded, max 11 bytes + NUL. A real YYString*
                needs a heap; pointer-backed strings are milestone 2, so this
                file cannot express strings longer than 11 bytes.
    tag 2,3,4,   zero payload. These are error-path tags ("illegal array use",
    6,8,9,11,    "illegal pointer use", "Malformed variable"); zero keeps a
    12,14        buggy implementation from dereferencing a fake pointer.
    tag 5        undefined: the .bss zero constant, payload zero.
    0x00FFFFFF   unresolved variable placeholder, payload zero.

`a` is the left operand (deeper on the stack), `b` the right operand (stack
top). `type` is the (left << 4) | right storage-class byte used by
DoAdd/DoSet/DoConv:
    0 double 8B, 1 f32 4B, 2 i32 4B, 3 i64 8B, 4 bool 4B,
    5 RValue 16B (dispatch on +12 tag), 6 string pointer 4B.

`mode` is the opcode's mode nibble, except push_immediate where it is the
signed 16-bit immediate (may be negative, per the protocol).
"""

from __future__ import annotations

import argparse
import hashlib
import json
import struct
import sys
from dataclasses import dataclass
from pathlib import Path
from typing import Sequence

MASK64 = (1 << 64) - 1

OPS: tuple[str, ...] = (
    "push_immediate", "dup", "conv",
    "add", "sub", "mul", "div", "rem", "mod",
    "and", "or", "xor", "shl", "shr",
    "neg", "not",
    "set_lt", "set_le", "set_eq", "set_ne", "set_ge", "set_gt",
)

ARITH = frozenset(("add", "sub", "mul", "div", "rem", "mod",
                   "and", "or", "xor", "shl", "shr"))
UNARY = frozenset(("neg", "not"))
SET_K = {"set_lt": 1, "set_le": 2, "set_eq": 3,
         "set_ne": 4, "set_ge": 5, "set_gt": 6}

TAGS: tuple[int, ...] = (0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 0x00FFFFFF)
TAG_LABEL = {
    0: "real0", 1: "string", 2: "array", 3: "pointer", 4: "tag4(4B?)",
    5: "undefined", 6: "tag6(4B?)", 7: "int32", 8: "tag8", 9: "tag9",
    10: "int64", 11: "tag11", 12: "null(0.0)", 13: "real13", 14: "tag14(4B?)",
    0x00FFFFFF: "unresolved",
}

# DoAdd/DoSet format-code pairs (left << 4 | right).
ARITH_TYPES = (0x00, 0x02, 0x03, 0x20, 0x22, 0x23, 0x30, 0x32, 0x33, 0x66,
               0x05, 0x25, 0x35, 0x50, 0x52, 0x53, 0x55, 0x56, 0x65)
SET_TYPES = (0x00, 0x02, 0x04, 0x20, 0x22, 0x23, 0x24, 0x30, 0x32, 0x33,
             0x40, 0x42, 0x44, 0x46, 0x64, 0x66, 0xFF)
BAD_TYPES = (0x01, 0x06, 0x07, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16,
             0x17, 0x26, 0x27, 0x34, 0x36, 0x41, 0x43, 0x45, 0x47, 0x51,
             0x54, 0x57, 0x60, 0x61, 0x62, 0x63, 0x65, 0x67, 0x70, 0x99,
             0xFE)

CLASS_NAME = {0: "real", 1: "f32", 2: "int32", 3: "int64",
              4: "bool", 5: "rvalue", 6: "string"}


# ---------------------------------------------------------------- RNG --------

class Rng:
    """SplitMix64: reproducible across Python versions and platforms."""

    def __init__(self, seed: int) -> None:
        self.state = seed & MASK64

    def next_u64(self) -> int:
        self.state = (self.state + 0x9E3779B97F4A7C15) & MASK64
        z = self.state
        z = ((z ^ (z >> 30)) * 0xBF58476D1CE4E5B9) & MASK64
        z = ((z ^ (z >> 27)) * 0x94D049BB133111EB) & MASK64
        return (z ^ (z >> 31)) & MASK64

    def below(self, n: int) -> int:
        if n <= 0:
            raise ValueError("below() needs n > 0")
        return self.next_u64() % n

    def choice(self, seq: Sequence):
        return seq[self.below(len(seq))]

    def randrange(self, lo: int, hi: int) -> int:
        """[lo, hi) — deterministic, modulo bias is irrelevant here."""
        return lo + self.below(hi - lo)


# ----------------------------------------------------------- RValue ---------

def image(payload: bytes, tag: int) -> dict:
    if len(payload) > 12:
        raise ValueError(f"payload {len(payload)}B does not fit +0..+11")
    buf = bytearray(16)
    buf[: len(payload)] = payload
    struct.pack_into("<I", buf, 12, tag & 0xFFFFFFFF)
    return {"bytes": bytes(buf).hex(), "tag": tag}


def real(x: float, tag: int = 0) -> dict:
    return image(struct.pack("<d", x), tag)


def real_bits(bits: int, tag: int = 0) -> dict:
    return image(struct.pack("<Q", bits & MASK64), tag)


def i32(v: int) -> dict:
    return image(struct.pack("<i", v), 7)


def i64(v: int) -> dict:
    return image(struct.pack("<q", v), 10)


def text(s: str, tag: int = 1) -> dict:
    raw = s.encode("ascii")
    if len(raw) > 11:
        raise ValueError(f"inline string {s!r} longer than 11 bytes")
    return image(raw + b"\x00", tag)


def zero(tag: int) -> dict:
    return image(b"", tag)


class Opd:
    """A named operand plus the storage class its `type` nibble should carry."""

    __slots__ = ("label", "cls", "rv")

    def __init__(self, label: str, cls: int, rv: dict) -> None:
        self.label = label
        self.cls = cls
        self.rv = rv


REAL_OPDS = (
    Opd("0.0", 0, real(0.0)),
    Opd("-0.0", 0, real_bits(0x8000000000000000)),
    Opd("1.0", 0, real(1.0)),
    Opd("-1.0", 0, real(-1.0)),
    Opd("0.5", 0, real(0.5)),
    Opd("2.5", 0, real(2.5)),
    Opd("+inf", 0, real_bits(0x7FF0000000000000)),
    Opd("-inf", 0, real_bits(0xFFF0000000000000)),
    Opd("nan", 0, real_bits(0x7FF8000000000000)),
    Opd("nan-payload", 0, real_bits(0x7FF0000000000001)),
    Opd("nan-neg", 0, real_bits(0xFFF8000000000000)),
    Opd("1e308", 0, real(1e308)),
    Opd("-1e308", 0, real(-1e308)),
    Opd("5e-324", 0, real(5e-324)),
    Opd("2^53", 0, real(9007199254740992.0)),
    Opd("1e-300", 0, real(1e-300)),
    Opd("pi", 0, real(3.141592653589793)),
    Opd("real13", 13, real(1.0, 13)),
)

INT32_OPDS = (
    Opd("i32.min", 2, i32(-2147483648)),
    Opd("i32.max", 2, i32(2147483647)),
    Opd("i32.0", 2, i32(0)),
    Opd("i32.-1", 2, i32(-1)),
    Opd("i32.1", 2, i32(1)),
    Opd("i32.-2", 2, i32(-2)),
    Opd("i32.65536", 2, i32(65536)),
    Opd("i32.-65536", 2, i32(-65536)),
)

INT64_OPDS = (
    Opd("i64.min", 3, i64(-9223372036854775808)),
    Opd("i64.max", 3, i64(9223372036854775807)),
    Opd("i64.0", 3, i64(0)),
    Opd("i64.-1", 3, i64(-1)),
    Opd("i64.1", 3, i64(1)),
    Opd("i64.2^32", 3, i64(1 << 32)),
    Opd("i64.-2^31", 3, i64(-(1 << 31))),
    Opd("i64.2^31", 3, i64(1 << 31)),
)

STRING_OPDS = (
    Opd('str""', 6, text("")),
    Opd('str"12"', 6, text("12")),
    Opd('str"1e"', 6, text("1e")),
    Opd('str"0x10"', 6, text("0x10")),
    Opd('str"abc"', 6, text("abc")),
    Opd('str"12abc"', 6, text("12abc")),
    Opd('str" 12"', 6, text(" 12")),
    Opd('str"-0"', 6, text("-0")),
    Opd('str"1.5"', 6, text("1.5")),
    Opd('str"NaN"', 6, text("NaN")),
    Opd('str"Infinity"', 6, text("Infinity")),
    Opd('str"abcdefghijk"', 6, text("abcdefghijk")),
)

ZERO_OPDS = {tag: Opd(TAG_LABEL[tag], 5, zero(tag))
             for tag in (2, 3, 4, 5, 6, 8, 9, 11, 12, 14, 0x00FFFFFF)}

UNUSED_A = real(0.0)
UNUSED_B = zero(5)

POOL_BY_TAG = {
    0: REAL_OPDS, 13: REAL_OPDS,
    1: STRING_OPDS,
    7: INT32_OPDS, 10: INT64_OPDS,
}


def operand_for_tag(tag: int, idx: int) -> Opd:
    pool = POOL_BY_TAG.get(tag)
    if pool is None:
        return ZERO_OPDS[tag]
    opd = pool[idx % len(pool)]
    if tag == 13 and opd.rv["tag"] == 0:
        return Opd(opd.label + "/t13", 0, real(
            struct.unpack("<d", bytes.fromhex(opd.rv["bytes"])[:8])[0], 13))
    return opd


def operand_for_class(cls: int, idx: int) -> Opd:
    if cls == 0:
        return REAL_OPDS[idx % len(REAL_OPDS)]
    if cls == 2:
        return INT32_OPDS[idx % len(INT32_OPDS)]
    if cls == 3:
        return INT64_OPDS[idx % len(INT64_OPDS)]
    if cls == 6:
        return STRING_OPDS[idx % len(STRING_OPDS)]
    pool = (ZERO_OPDS[2], ZERO_OPDS[3], ZERO_OPDS[5], ZERO_OPDS[4], ZERO_OPDS[6])
    return pool[idx % len(pool)]


# ------------------------------------------------------------- cases --------

@dataclass
class Case:
    op: str
    mode: int
    type: int
    a: dict
    b: dict
    shape: str = ""
    note: str = ""
    expect: str = "either"       # ok | error | either
    error_hint: str = ""
    id: int = -1

    def line(self) -> dict:
        if self.id < 0:
            raise ValueError("case has no id")
        return {"id": self.id, "op": self.op, "mode": self.mode,
                "type": self.type, "a": self.a, "b": self.b}


def C(op: str, mode: int, type_: int, a: dict, b: dict, shape: str = "",
      note: str = "", expect: str = "either", hint: str = "") -> Case:
    return Case(op=op, mode=mode, type=type_, a=a, b=b,
                shape=shape, note=note, expect=expect, error_hint=hint)


def family(op: str) -> str:
    if op in ARITH:
        return "arith"
    if op in UNARY:
        return "unary"
    if op.startswith("set_"):
        return "set"
    if op == "conv":
        return "conv"
    return "misc"


def natural_type(a: Opd, b: Opd) -> int:
    return (a.cls << 4) | b.cls


# Curated pairs. dispatch=True means "both operands are 16B RValue slots"
# (type 0x55), the shape a variable read produces; the runtime then dispatches
# on the +12 tag.
PAIRS: tuple[tuple[Opd, Opd, str, bool, str | None, str], ...] = (
    (REAL_OPDS[0], REAL_OPDS[0], "real 0.0 / 0.0", False, "ok", ""),
    (REAL_OPDS[1], REAL_OPDS[0], "real -0.0 / 0.0", False, "ok", ""),
    (REAL_OPDS[6], REAL_OPDS[2], "real +inf / 1.0", False, "either", ""),
    (REAL_OPDS[7], REAL_OPDS[6], "real -inf / +inf", False, "either", ""),
    (REAL_OPDS[8], REAL_OPDS[2], "real nan / 1.0", False, "either", ""),
    (REAL_OPDS[9], REAL_OPDS[2], "real nan(payload) / 1.0", False, "either", ""),
    (REAL_OPDS[11], REAL_OPDS[11], "real 1e308 / 1e308", False, "either", ""),
    (REAL_OPDS[13], REAL_OPDS[2], "real 5e-324 / 1.0", False, "either", ""),
    (REAL_OPDS[14], REAL_OPDS[2], "real 2^53 / 1.0", False, "either", ""),
    (REAL_OPDS[17], REAL_OPDS[2], "real13 1.0 / 1.0", False, "either", ""),
    (INT32_OPDS[0], INT32_OPDS[3], "i32 INT_MIN / -1", False, "either", ""),
    (INT32_OPDS[1], INT32_OPDS[4], "i32 INT_MAX / 1", False, "either", ""),
    (INT32_OPDS[2], INT32_OPDS[2], "i32 0 / 0", False, "either", ""),
    (INT32_OPDS[3], INT32_OPDS[4], "i32 -1 / 1", False, "either", ""),
    (INT32_OPDS[1], INT32_OPDS[0], "i32 MAX / MIN", False, "either", ""),
    (INT64_OPDS[0], INT64_OPDS[3], "i64 INT_MIN / -1", False, "either", ""),
    (INT64_OPDS[1], INT64_OPDS[4], "i64 INT_MAX / 1", False, "either", ""),
    (INT64_OPDS[2], INT64_OPDS[2], "i64 0 / 0", False, "either", ""),
    (INT64_OPDS[5], INT64_OPDS[3], "i64 2^32 / -1", False, "either", ""),
    (STRING_OPDS[0], STRING_OPDS[0], 'str "" / ""', False, "either", ""),
    (STRING_OPDS[1], STRING_OPDS[1], 'str "12" / "12"', False, "either", ""),
    (STRING_OPDS[2], STRING_OPDS[3], 'str "1e" / "0x10"', False, "either", ""),
    (STRING_OPDS[4], STRING_OPDS[4], 'str "abc" / "abc"', False, "either", ""),
    (STRING_OPDS[1], INT32_OPDS[4], 'str "12" / i32 1', False, "either", ""),
    (INT32_OPDS[4], STRING_OPDS[1], 'i32 1 / str "12"', False, "either", ""),
    (REAL_OPDS[4], INT32_OPDS[4], "real 0.5 / i32 1", False, "either", ""),
    (INT32_OPDS[4], REAL_OPDS[4], "i32 1 / real 0.5", False, "either", ""),
    (REAL_OPDS[4], INT64_OPDS[4], "real 0.5 / i64 1", False, "either", ""),
    (INT64_OPDS[4], REAL_OPDS[4], "i64 1 / real 0.5", False, "either", ""),
    (INT32_OPDS[1], INT64_OPDS[4], "i32 MAX / i64 1", False, "either", ""),
    (INT64_OPDS[4], INT32_OPDS[1], "i64 1 / i32 MAX", False, "either", ""),
    (INT32_OPDS[2], INT32_OPDS[2], "i32 0 divisor 0", False, "error",
     "DoDiv :: Divide by zero"),
    (INT64_OPDS[2], INT64_OPDS[2], "i64 0 divisor 0", False, "error",
     "DoDiv :: Divide by zero"),
    (REAL_OPDS[2], REAL_OPDS[0], "real 1.0 / 0.0", False, "either", ""),
    (ZERO_OPDS[5], ZERO_OPDS[5], "undefined / undefined", True, "error", ""),
    (ZERO_OPDS[2], ZERO_OPDS[2], "array / array", True, "error", ""),
    (ZERO_OPDS[3], ZERO_OPDS[3], "pointer / pointer", True, "error", ""),
    (ZERO_OPDS[4], ZERO_OPDS[4], "tag4 / tag4", True, "either", ""),
    (ZERO_OPDS[6], ZERO_OPDS[6], "tag6 / tag6", True, "either", ""),
    (ZERO_OPDS[8], ZERO_OPDS[9], "tag8 / tag9", True, "either", ""),
    (ZERO_OPDS[11], ZERO_OPDS[12], "tag11 / null", True, "either", ""),
    (ZERO_OPDS[14], ZERO_OPDS[14], "tag14 / tag14", True, "either", ""),
    (ZERO_OPDS[0x00FFFFFF], ZERO_OPDS[0x00FFFFFF], "unresolved / unresolved",
     True, "either", ""),
    (ZERO_OPDS[0x00FFFFFF], REAL_OPDS[2], "unresolved / real", True, "either", ""),
    (STRING_OPDS[4], ZERO_OPDS[5], 'str "abc" / undefined', True, "either", ""),
)


def modes_for(op: str) -> tuple[int, ...]:
    if op in SET_K:
        k = SET_K[op]
        return (k, 0, 7, 11, 12, 15)
    if op in ("neg", "not"):
        return (0, 1, 2, 3, 15)
    if op == "conv":
        return (0, 1, 2, 4, 8, 12)
    if op == "dup":
        return (0, 0, 0, 1, 2, 3, 15)
    if op == "push_immediate":
        return (0,)
    if op == "div" or op == "shl":
        return (0, 0, 1, 2, 3, 15)      # 1 = JS coercion slow path
    if op == "mod":
        return (0, 0, 1, 2, 15)         # 1 = constant path (NaN, not error)
    return (0, 0, 1, 2, 3, 15)


def types_for(op: str) -> tuple[int, ...]:
    fam = family(op)
    if fam == "arith":
        return ARITH_TYPES
    if fam == "set":
        return SET_TYPES
    if fam == "unary":
        return tuple(range(16))
    if fam == "conv":
        return tuple((dst << 4) | src for dst in range(8) for src in range(8))
    return (0,)


UNUSED_B_OPD = Opd("unused", 5, UNUSED_B)


def core_pair(op: str) -> tuple[Opd, Opd]:
    fam = family(op)
    if op == "shl" or op == "shr":
        return INT32_OPDS[4], INT32_OPDS[4]
    if op == "div" or op == "rem" or op == "mod":
        return INT32_OPDS[1], INT32_OPDS[4]
    if fam == "set":
        return INT32_OPDS[1], INT32_OPDS[3]
    if fam == "unary":
        return INT32_OPDS[1], UNUSED_B_OPD
    if op == "conv":
        return INT32_OPDS[1], UNUSED_B_OPD
    return INT32_OPDS[1], INT32_OPDS[4]


def build_tag_sweep(op: str) -> list[Case]:
    out: list[Case] = []
    fam = family(op)
    for i, tag in enumerate(TAGS):
        a = operand_for_tag(tag, i)
        b = operand_for_tag(tag, i + 1)
        if op == "push_immediate":
            out.append(C(op, 0, 0, a.rv, b.rv, f"tag{tag}",
                         f"tag sweep {TAG_LABEL[tag]}"))
        elif fam == "unary":
            out.append(C(op, 0, a.cls & 0xF, a.rv, UNUSED_B, f"tag{tag}",
                         f"tag sweep {TAG_LABEL[tag]}"))
        elif op == "conv":
            out.append(C(op, 0, (0 << 4) | (a.cls & 0xF), a.rv, UNUSED_B,
                         f"tag{tag}", f"tag sweep {TAG_LABEL[tag]}"))
        elif op == "dup":
            out.append(C(op, 0, 0, a.rv, b.rv, f"tag{tag}",
                         f"tag sweep {TAG_LABEL[tag]}"))
        else:
            out.append(C(op, 0, 0x55, a.rv, b.rv, f"tag{tag}",
                         f"tag sweep {TAG_LABEL[tag]}"))
    return out


def build_pair_block(op: str) -> list[Case]:
    out: list[Case] = []
    fam = family(op)
    if op in ("push_immediate", "dup"):
        return out
    for a, b, note, dispatch, want_error, hint in PAIRS:
        exp = "either"
        used_hint = ""
        if fam == "unary":
            ty = a.cls & 0xF
            mode = 0
        elif op == "conv":
            ty = (0 << 4) | (a.cls & 0xF)
            mode = 0
        else:
            ty = 0x55 if dispatch else natural_type(a, b)
            mode = SET_K.get(op, 0)
            if mode == 0:
                # The divide-by-zero pair only divides on div/rem/mod; the same
                # operand pair is a perfectly legal addend elsewhere.
                if want_error == "error" and hint.startswith("DoDiv") \
                        and op == "div":
                    exp, used_hint = "error", hint
                elif want_error == "error" and dispatch \
                        and op in ("add", "sub", "mul") and (
                        a.rv["tag"] in (2, 3, 5) or b.rv["tag"] in (2, 3, 5)):
                    exp = "error"
                    bad = (a.rv["tag"] if a.rv["tag"] in (2, 3, 5)
                           else b.rv["tag"])
                    if op == "add":
                        used_hint = {2: "DoAdd :: illegal array use",
                                     3: "DoAdd :: illegal pointer use",
                                     5: "DoAdd :: undefined value"}[bad]
        out.append(C(op, mode, ty, a.rv, b.rv,
                     f"{a.label}/{b.label}", note, exp, used_hint))
    return out


def build_mode_type_sweep(op: str) -> list[Case]:
    out: list[Case] = []
    fam = family(op)
    if op == "push_immediate":
        for imm in (-32768, -32767, -256, -1, 0, 1, 255, 256, 32767):
            out.append(C(op, imm, 0, UNUSED_A, UNUSED_B, "immediate",
                         f"immediate {imm}"))
        return out
    if op == "conv":
        for dst in range(0, 8):
            for src in range(0, 8):
                a = operand_for_class(min(src, 6), src + dst)
                exp = "error" if dst > 6 else ("ok" if src <= 6 else "either")
                note = ("destination class out of the 0..6 range"
                        if dst > 6 else "src x dst dispatch table")
                out.append(C(op, 0, (dst << 4) | src, a.rv, UNUSED_B,
                             f"conv {CLASS_NAME.get(src, src)}->"
                             f"{CLASS_NAME.get(dst, dst)}", note, exp))
        return out
    if op == "dup":
        for mode in range(0, 16):
            a = operand_for_tag(TAGS[mode], mode)
            out.append(C(op, mode, 0, a.rv, UNUSED_B, f"dup mode{mode}",
                         "dup mode sweep"))
        return out
    a, b = core_pair(op)
    types = types_for(op)
    modes = modes_for(op)
    for mi, mode in enumerate(modes):
        for ti in range(6):
            ty = types[(mi * 6 + ti) % len(types)]
            out.append(C(op, mode, ty, a.rv, b.rv,
                         f"{a.label}/{b.label}",
                         f"mode {mode} type 0x{ty:02x}"))
    return out


def build_specials(op: str) -> list[Case]:
    out: list[Case] = []
    fam = family(op)

    if op == "div":
        for a, b, note, ty in (
            (INT32_OPDS[1], INT32_OPDS[2], "i32 INT_MAX / 0", 0x22),
            (INT64_OPDS[1], INT64_OPDS[2], "i64 INT_MAX / 0", 0x33),
            (REAL_OPDS[2], REAL_OPDS[0], "real 1.0 / 0.0", 0x00),
            (INT32_OPDS[0], INT32_OPDS[3], "i32 INT_MIN / -1", 0x22),
            (INT64_OPDS[0], INT64_OPDS[3], "i64 INT_MIN / -1", 0x33),
        ):
            for mode in (0, 1):
                zero = " / 0" in note
                # INT_MIN / -1 is implementation-defined (__divsi3 returns
                # INT_MIN on ARM), not a card-documented error.
                is_error = mode == 0 and zero and "real" not in note
                out.append(C(op, mode, ty, a.rv, b.rv, note,
                             "zero divisor (fast path)" if mode == 0 and zero
                             else ("overflow divisor (fast path)"
                                   if mode == 0 else
                                   "same divisor on the JS coercion path"),
                             "error" if is_error else "either",
                             "DoDiv :: Divide by zero" if is_error else ""))
    elif op == "rem":
        for a, b, note, ty in (
            (INT32_OPDS[1], INT32_OPDS[2], "i32 INT_MAX rem 0", 0x22),
            (INT64_OPDS[1], INT64_OPDS[2], "i64 INT_MAX rem 0", 0x33),
            (REAL_OPDS[2], REAL_OPDS[4], "real 7.0 rem 0.5", 0x00),
        ):
            out.append(C(op, 0, ty, a.rv, b.rv, note, "zero divisor (rem)",
                         "error", "DoRem :: Divide by zero"))
    elif op == "mod":
        for a, b, note, ty in (
            (INT32_OPDS[1], INT32_OPDS[2], "i32 INT_MAX mod 0", 0x22),
            (INT64_OPDS[1], INT64_OPDS[2], "i64 INT_MAX mod 0", 0x33),
            (REAL_OPDS[2], REAL_OPDS[0], "real 1.0 mod 0.0", 0x00),
        ):
            for mode in (0, 1):
                if mode == 0:
                    out.append(C(op, mode, ty, a.rv, b.rv, note,
                                 "zero divisor (mod fast path)", "error",
                                 "DoMod :: Divide by zero"))
                else:
                    out.append(C(op, mode, ty, a.rv, b.rv, note,
                                 "constant path: NaN, no error", "either"))
    elif op in ("add", "sub", "mul", "and", "or", "xor", "shl", "shr"):
        for tag in (2, 3, 4, 5, 6, 8, 9, 11, 12, 14, 0x00FFFFFF):
            a = ZERO_OPDS[tag]
            b = INT32_OPDS[4]
            hint = ""
            if op == "add":
                hint = {2: "DoAdd :: illegal array use",
                        3: "DoAdd :: illegal pointer use",
                        5: "DoAdd :: undefined value"}.get(tag, "")
            out.append(C(op, 0, 0x55, a.rv, b.rv,
                         f"{a.label}/i32.1",
                         "malformed tag in an RValue slot",
                         "error" if tag in (2, 3, 4, 5, 6) else "either",
                         hint))
        s = STRING_OPDS[4]
        out.append(C(op, 0, 0x66, s.rv, s.rv, "str/str",
                     "string operand on an arithmetic op", "either"))
    elif op in UNARY:
        for tag in (1, 2, 3, 5, 4, 6, 8, 9, 11, 12, 14, 0x00FFFFFF):
            a = ZERO_OPDS[tag] if tag not in (1,) else STRING_OPDS[4]
            out.append(C(op, 0, 5, a.rv, UNUSED_B, f"{a.label}",
                         "dynamic RValue slot, tag dispatches",
                         "error" if tag in (1, 2, 3, 5) else "either"))
        for mode in (1, 2):
            a = ZERO_OPDS[0x00FFFFFF]
            out.append(C(op, mode, 5, a.rv, UNUSED_B, "unresolved",
                         "unresolved placeholder", "error"))
    elif fam == "set":
        for tag in (2, 3, 5, 4, 6, 0x00FFFFFF):
            a = ZERO_OPDS[tag]
            b = INT32_OPDS[4]
            # DoSet's K=1..6 path compares numbers; non-numeric tags are a
            # value question, not a documented error, so no expectation here.
            out.append(C(op, SET_K[op], 0x55, a.rv, b.rv,
                         f"{a.label}/i32.1", "malformed tag in comparison",
                         "either"))
        out.append(C(op, SET_K[op], 0x22, STRING_OPDS[1].rv, INT32_OPDS[4].rv,
                     'str"12"/i32.1', "tag does not match declared type",
                     "either"))
    elif op == "conv":
        for dst in range(7, 16):
            a = INT32_OPDS[1]
            out.append(C(op, 0, (dst << 4) | 2, a.rv, UNUSED_B,
                         f"i32->dst{dst}", "destination class out of range",
                         "error"))
        for src, table in ((0, REAL_OPDS[2]), (2, INT32_OPDS[1]),
                           (3, INT64_OPDS[1]), (6, STRING_OPDS[1])):
            for flag in (1, 2, 4, 8, 12):
                out.append(C(op, flag, (0 << 4) | src, table.rv, UNUSED_B,
                             f"{CLASS_NAME[src]}->real flag{flag}",
                             "conv flag path (ToBoolean/ToNumber)"))
    return out


def random_operand(rng: Rng) -> Opd:
    roll = rng.below(100)
    if roll < 30:
        return operand_for_tag(0, rng.below(len(REAL_OPDS)))
    if roll < 50:
        return operand_for_tag(7, rng.below(len(INT32_OPDS)))
    if roll < 65:
        return operand_for_tag(10, rng.below(len(INT64_OPDS)))
    if roll < 80:
        return operand_for_tag(1, rng.below(len(STRING_OPDS)))
    tags = (2, 3, 4, 5, 6, 8, 9, 11, 12, 13, 14, 0x00FFFFFF)
    return operand_for_tag(tags[rng.below(len(tags))], rng.below(4))


def random_case(op: str, rng: Rng) -> Case:
    fam = family(op)
    if op == "push_immediate":
        imm = rng.randrange(-32768, 32768)
        return C(op, imm, 0, UNUSED_A, UNUSED_B, "immediate",
                 f"random immediate {imm}")
    if op == "dup":
        a = random_operand(rng)
        mode = rng.below(16) if rng.below(4) == 0 else 0
        return C(op, mode, 0, a.rv, UNUSED_B, a.label, "random dup")
    if op == "conv":
        src = rng.below(7)
        a = operand_for_class(src, rng.below(6))
        dst = rng.below(16) if rng.below(4) == 0 else rng.below(7)
        return C(op, 0, (dst << 4) | src, a.rv, UNUSED_B,
                 f"{CLASS_NAME[src]}->{CLASS_NAME.get(dst, dst)}",
                 "random conv", "error" if dst > 6 else "either")
    a = random_operand(rng)
    b = random_operand(rng)
    modes = modes_for(op)
    mode = modes[rng.below(len(modes))]
    if fam == "unary":
        ty = (a.rv["tag"] & 0xF) if rng.below(4) else rng.below(16)
        return C(op, mode, ty, a.rv, UNUSED_B, a.label, "random unary")
    if fam == "set":
        pool = SET_TYPES
    else:
        pool = ARITH_TYPES
    if rng.below(10) < 7:
        ty = natural_type(a, b)
    elif rng.below(3) == 0:
        ty = BAD_TYPES[rng.below(len(BAD_TYPES))]
    else:
        ty = pool[rng.below(len(pool))]
    return C(op, mode, ty & 0xFF, a.rv, b.rv,
             f"{a.label}/{b.label}", "random")


def build_op_cases(op: str, per_op: int, rng: Rng) -> list[Case]:
    systematic = (build_tag_sweep(op) + build_pair_block(op)
                  + build_mode_type_sweep(op) + build_specials(op))
    dropped = 0
    if len(systematic) > per_op:
        dropped = len(systematic) - per_op
        systematic = systematic[:per_op]
    cases = systematic
    while len(cases) < per_op:
        cases.append(random_case(op, rng))
    if dropped:
        print(f"gen_cases: warning: {op}: --per-op {per_op} too small, "
              f"dropped {dropped} systematic cases (coverage reduced)",
              file=sys.stderr)
    return cases


# ---------------------------------------------------------- coverage --------

def check_coverage(cases: list[Case]) -> None:
    """Fail loudly if a required boundary silently disappears."""
    by_op: dict[str, list[Case]] = {op: [] for op in OPS}
    for case in cases:
        by_op[case.op].append(case)

    for op, block in by_op.items():
        seen = {c.a["tag"] for c in block} | {c.b["tag"] for c in block}
        missing = set(TAGS) - seen
        if missing:
            raise AssertionError(f"{op}: tag sweep lost {sorted(missing)}")

    def payload(case: Case, key: str) -> bytes:
        return bytes.fromhex(case.__getattribute__(key)["bytes"])

    def any_case(op: str, pred) -> bool:
        return any(pred(c) for c in by_op[op])

    # divide by zero, int32 and int64, fast path
    for tag, width in ((7, 4), (10, 8)):
        if not any_case("div", lambda c, t=tag, w=width: (
                c.mode == 0 and c.b["tag"] == t
                and payload(c, "b")[:w] == b"\x00" * w)):
            raise AssertionError(f"div: no int{width * 8} divide-by-zero case")

    # undefined and array participating in arithmetic
    for op in ("add", "sub", "mul"):
        for tag in (5, 2, 3):
            if not any_case(op, lambda c, t=tag: c.mode == 0
                            and (c.a["tag"] == t or c.b["tag"] == t)
                            and c.expect == "error"):
                raise AssertionError(f"{op}: no designed failure for tag {tag}")

    # unary tag dispatch error
    if not any_case("neg", lambda c: c.mode == 0 and c.a["tag"] == 2
                    and c.expect == "error"):
        raise AssertionError("neg: no illegal-array-use case")

    # strings, real specials and integer boundaries must be reachable
    wanted_text = (b"\x00", b"12\x00", b"1e\x00", b"0x10\x00", b"abc\x00")
    for raw in wanted_text:
        if not any(payload(c, k).startswith(raw)
                   for c in cases for k in ("a", "b")):
            raise AssertionError(f"string {raw!r} missing")
    real_bits = {struct.unpack("<Q", payload(c, k)[:8])[0]
                 for c in cases for k in ("a", "b") if c.__getattribute__(k)["tag"] in (0, 13)}
    for bits, label in ((0x7FF8000000000000, "nan"),
                        (0x7FF0000000000000, "+inf"),
                        (0xFFF0000000000000, "-inf"),
                        (0x8000000000000000, "-0.0"),
                        (0x0000000000000000, "+0.0")):
        if bits not in real_bits:
            raise AssertionError(f"real {label} missing")
    i32_vals = {struct.unpack("<i", payload(c, k)[:4])[0]
                for c in cases for k in ("a", "b") if c.__getattribute__(k)["tag"] == 7}
    for v in (-2147483648, 2147483647, 0, -1):
        if v not in i32_vals:
            raise AssertionError(f"int32 {v} missing")
    i64_vals = {struct.unpack("<q", payload(c, k)[:8])[0]
                for c in cases for k in ("a", "b") if c.__getattribute__(k)["tag"] == 10}
    for v in (-9223372036854775808, 9223372036854775807, 0, -1):
        if v not in i64_vals:
            raise AssertionError(f"int64 {v} missing")


# ------------------------------------------------------------ output --------

def validate(case: Case, idx: int) -> None:
    def check_rv(name: str, rv: dict) -> None:
        raw = bytes.fromhex(rv["bytes"])
        if len(raw) != 16:
            raise AssertionError(f"case {idx}: {name} is {len(raw)}B, want 16")
        if rv["tag"] not in TAGS:
            raise AssertionError(f"case {idx}: {name} tag {rv['tag']:#x} "
                                 "outside the protocol tag set")
        stored = struct.unpack_from("<I", raw, 12)[0]
        if stored != rv["tag"]:
            raise AssertionError(f"case {idx}: {name} tag word {stored:#x} "
                                 f"!= tag field {rv['tag']:#x}")
    if case.op not in OPS:
        raise AssertionError(f"case {idx}: unknown op {case.op!r}")
    if not (-32768 <= case.mode <= 0xFFFF):
        raise AssertionError(f"case {idx}: mode {case.mode} out of range")
    if not (0 <= case.type <= 0xFF):
        raise AssertionError(f"case {idx}: type {case.type} is not a byte")
    check_rv("a", case.a)
    check_rv("b", case.b)


def main(argv: Sequence[str] | None = None) -> int:
    ap = argparse.ArgumentParser(
        description="Generate deterministic opcode differential cases.")
    ap.add_argument("--seed", default="0xCA11",
                    help="integer seed, 0x... accepted (default 0xCA11)")
    ap.add_argument("--per-op", type=int, default=200,
                    help="cases per opcode (default 200)")
    ap.add_argument("--out", default="diff/cases.jsonl",
                    help="output JSONL path (default diff/cases.jsonl)")
    ap.add_argument("--no-meta", action="store_true",
                    help="do not write the <out>.meta.json sidecar")
    args = ap.parse_args(argv)

    try:
        seed = int(args.seed, 0)
    except ValueError:
        print(f"gen_cases: error: --seed {args.seed!r} is not an integer",
              file=sys.stderr)
        return 2
    if args.per_op < 1:
        print("gen_cases: error: --per-op must be >= 1", file=sys.stderr)
        return 2

    rng = Rng(seed)
    all_cases: list[Case] = []
    per_op_counts: dict[str, int] = {}
    for op in OPS:
        block = build_op_cases(op, args.per_op, rng)
        per_op_counts[op] = len(block)
        all_cases.extend(block)

    for i, case in enumerate(all_cases):
        case.id = i
        validate(case, i)
    try:
        check_coverage(all_cases)
    except AssertionError as exc:
        print(f"gen_cases: error: {exc}; --per-op {args.per_op} is too small "
              f"to keep the required tag/boundary coverage (use >= 160)",
              file=sys.stderr)
        return 2

    lines = []
    for case in all_cases:
        obj = case.line()
        lines.append(json.dumps(obj, separators=(",", ":"), ensure_ascii=True))
    payload = ("\n".join(lines) + "\n").encode("utf-8")
    digest = hashlib.sha256(payload).hexdigest()

    out = Path(args.out)
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_bytes(payload)

    tag_occ: dict[int, int] = {t: 0 for t in TAGS}
    tag_cases: dict[int, int] = {t: 0 for t in TAGS}
    mode_hist: dict[int, int] = {}
    imm_hist: dict[int, int] = {}
    type_hist: dict[int, int] = {}
    expect_counts: dict[str, int] = {}
    error_ids: list[int] = []
    for case in all_cases:
        for rv in (case.a, case.b):
            tag_occ[rv["tag"]] += 1
        for t in dict.fromkeys((case.a["tag"], case.b["tag"])):
            tag_cases[t] += 1
        if case.op == "push_immediate":
            imm_hist[case.mode] = imm_hist.get(case.mode, 0) + 1
        else:
            mode_hist[case.mode] = mode_hist.get(case.mode, 0) + 1
        type_hist[case.type] = type_hist.get(case.type, 0) + 1
        expect_counts[case.expect] = expect_counts.get(case.expect, 0) + 1
        if case.expect == "error":
            error_ids.append(case.id)

    print(f"gen_cases: seed=0x{seed:08X} per_op={args.per_op} "
          f"ops={len(OPS)} cases={len(all_cases)}", file=sys.stderr)
    print(f"gen_cases: wrote {out} ({len(all_cases)} lines, "
          f"{len(payload)} bytes, sha256={digest})", file=sys.stderr)
    print("gen_cases: per-op counts", file=sys.stderr)
    for op in OPS:
        print(f"  {op:<16} {per_op_counts[op]:>5}", file=sys.stderr)
    print("gen_cases: tag coverage (cases containing tag | operand slots)",
          file=sys.stderr)
    for tag in TAGS:
        label = TAG_LABEL[tag]
        shown = "0x00FFFFFF" if tag == 0x00FFFFFF else f"{tag:#04x}"
        print(f"  tag {shown:<10} {label:<12} cases={tag_cases[tag]:>5} "
              f"slots={tag_occ[tag]:>5}", file=sys.stderr)
    modes = ", ".join(f"{m}:{n}" for m, n in sorted(mode_hist.items()))
    print(f"gen_cases: mode nibble histogram (all ops but push_immediate) "
          f"{modes}", file=sys.stderr)
    print(f"gen_cases: push_immediate argument range "
          f"[{min(imm_hist)}, {max(imm_hist)}], {len(imm_hist)} distinct",
          file=sys.stderr)
    print(f"gen_cases: distinct type bytes {len(type_hist)} "
          f"(top: {', '.join(f'0x{t:02x}:{n}' for t, n in sorted(type_hist.items(), key=lambda kv: -kv[1])[:8])})",
          file=sys.stderr)
    print("gen_cases: coverage assertions passed "
          f"({len(OPS)} ops x {len(TAGS)} tags, boundary values present)",
          file=sys.stderr)
    print(f"gen_cases: expectations {expect_counts}", file=sys.stderr)
    shown = ", ".join(str(i) for i in error_ids[:12])
    more = "" if len(error_ids) <= 12 else f", … (+{len(error_ids) - 12})"
    print(f"gen_cases: designed-failure ids [{shown}{more}]", file=sys.stderr)

    if not args.no_meta:
        meta_path = Path(str(out) + ".meta.json")
        meta = {
            "protocol": "reconstruction/contracts/opcode-diff-protocol.md",
            "seed": args.seed,
            "seed_value": seed,
            "per_op": args.per_op,
            "count": len(all_cases),
            "cases_sha256": digest,
            "ops": list(OPS),
            "cases": [
                {"id": c.id, "op": c.op, "shape": c.shape, "note": c.note,
                 "expect": c.expect, "error_hint": c.error_hint}
                for c in all_cases
            ],
        }
        meta_path.write_text(json.dumps(meta, indent=1, ensure_ascii=False) + "\n",
                             encoding="utf-8")
        print(f"gen_cases: wrote {meta_path} ({len(all_cases)} entries)",
              file=sys.stderr)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
