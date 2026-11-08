#!/usr/bin/env python3
"""Original is read-only. Execute only rebuilt ARM32 C plus synthetic
heap/libc/JSON/timeline providers. PASS is a scoped reconstructed-consumer
verdict, never an original-equivalence claim.

Subject: B17, the path-constraint MIX timeline block of
spSkeletonJson_readSkeletonData @0x28b84c
  0x28e8ec..0x28ea0c (73 insns / 292 B) — reached ONLY from B13's
  0x28e538 `bne 0x28e8ec`:
    * 0x28e8ec..0x28e8fc  strcmp(name,"mix"); `beq 0x28e048` skips the node
    * 0x28e900..0x28e91c  create(declared count); frame=NULL test;
                          +0x14 index store runs BEFORE the test
    * 0x28e920..0x28e944  keys "time"(0.0f) / "rotateMix"(1.0f) /
                          "translateMix"(1.0f) at pools 0x28eb10/14/18
    * 0x28e948..0x28e9c4  frame loop; setFrame 0x283080 (5 args); readCurve
                          0x28e9b0 (B17's own site)
    * 0x28e9cc..0x28ea0c  publish + duration tail with a THREE-float stride
                          (0x28e9e8) back to the shared node advance 0x28e048

THE PUZZLE (determined from the instruction stream, pinned statically and at
run time): 0x28e8fc's target is the same node-advance instruction 0x28e048
(`ldr r4,[r4]`) that every published timeline falls into.  A sub-key named
exactly "mix" is silently skipped by NOBODY else — no other block in the
function compares a path sub-key against "mix" — while every OTHER name falls
through and IS loaded as a mix timeline.  The fixture pins both directions and
both orders.

DECODE CORRECTION: the key literal at pool 0x28eb14 is resolved by the add at
0x28e938 (PC base 0x28e940) to 0x357cc0 "rotateMix" — the START of the same
literal B12 uses at 0x28dcd8.  It is NOT a "+4 suffix" ("teMix" @0x357cc4);
the sibling path checker passed 0x28e93c (a `str`, not an `add`) as the add
site.  This checker pins the true site and cross-resolves B12's site.

Real recovered chain under test (all bodies recovered, no stubs):
  Json_getFloat / Json_getItem        c/json_interface
  readCurve                           c/spine_read_curve
  _malloc / _free / _calloc           c/spine_alloc

Declared synthetic boundaries (NOT recovered bodies):
  spPathConstraintMixTimeline_create 0x283068, spPathConstraintMixTimeline_
  setFrame 0x283080, spCurveTimeline_setStepped/setCurve 0x2817c0/0x2817d8,
  fixture heap + allocator roster, libc providers, hand-built Json nodes.

Nothing here executes original libyoyo bytes. Static anchors (SHA, dynsym,
instruction words, pc-relative literals, anonymous-callee call sites, the B17
BL roster and the five foreign islands inside the census B17 span) are
checked before any run.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import subprocess
from elftools.elf.elffile import ELFFile

C = Path(__file__).resolve().parents[2]
MOD = C / 'spine_read_tl_path_mix'
FIX = MOD / 'fixture/check.c'
BODY = MOD / 'src/spine_read_tl_path_mix.c'
HEADER = MOD / 'src/spine_read_tl_path_mix.h'
PIN = '3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a'
CURVE_SRC = C / 'spine_read_curve/src/spine_read_curve.c'
JSON_SRC = C / 'json_interface/src/json_interface.c'
SOURCES = [C / p for p in (
    'spine_alloc/src/spine_alloc.c',
    'json_interface/src/json_interface.c',
    'spine_skeleton_data/src/spine_skeleton_data.c',
    'spine_json_support/src/spine_json_support.c',
    'spine_json_error/src/spine_json_error.c',
    'spine_read_curve/src/spine_read_curve.c',
    'spine_read_tl_path_mix/src/spine_read_tl_path_mix.c',
    'csprite_resources/fixture/arm32_support.c',
    'spine_linked_postpass/fixture/reporter_adapter.c',
    'spine_read_tl_path_mix/fixture/check.c',
)]
INCLUDES = [C / p / 'src' for p in (
    'spine_alloc', 'spine_attachment', 'spine_skeleton_data', 'json_interface',
    'spine_color', 'spine_read_mesh', 'spine_mesh', 'spine_read_vertices',
    'spine_atlas_attachment', 'spine_read_slots', 'spine_json_error',
    'spine_json_support', 'spine_read_curve', 'spine_read_tl_path_mix',
)]
FLAGS = ['--target=armv7a-none-eabi', '-march=armv7-a', '-marm', '-mfpu=vfpv3',
         '-mfloat-abi=softfp', '-std=c11', '-ffreestanding', '-fno-builtin',
         '-ffp-contract=off', '-fstack-protector-strong',
         '-mstack-protector-guard=global', '-ffunction-sections',
         '-fdata-sections', '-Wall', '-Wextra', '-Werror', '-nostdlib',
         '-static', '-fuse-ld=lld', '-Wl,--gc-sections', '-Wl,-e,_start']
# Contract names emitted by the fixture, in execution order.
TESTS = ['mix_name_skipped', 'other_name_creates_mix', 'mix_between_others',
         'empty_frames_index_store', 'frame_values_and_defaults',
         'frame_index_and_stride', 'read_curve_paths', 'duration_stride_three',
         'declared_vs_child_count', 'duration_max', 'index_cell_values',
         'key_literals_exact', 'skip_is_transparent']
SUMMARY = 'SUMMARY all declared path-mix timeline family contracts passed'
# Raw original instruction words: the puzzle branch, the key pools, the
# conditional/unconditional exits, the 3-float tail and the sibling advance.
# Every word below was re-read from the image, not transcribed.
WORD_PINS = {
    0x28e8e8: 0xeafffc55,  # b 0x28da44                 — no fall-through into B17
    0x28e8ec: 0xe1a00006,  # mov r0,r6                  — name for strcmp
    0x28e8f0: 0xe59d1048,  # ldr r1,[sp,#0x48]          — "mix" spilled by B13
    0x28e8f4: 0xebf89f1e,  # bl strcmp@plt
    0x28e8fc: 0x0afffdd1,  # beq 0x28e048               — THE PUZZLE BRANCH
    0x28e900: 0xe594000c,  # ldr r0,[r4,#0xc]           — declared count
    0x28e904: 0xebffd1d7,  # bl spPathConstraintMixTimeline_create
    0x28e908: 0xe5945004,  # ldr r5,[r4,#0x4]           — frames
    0x28e910: 0xe1a06000,  # mov r6,r0                  — r6 = timeline
    0x28e914: 0xe59d002c,  # ldr r0,[sp,#0x2c]          — B13's index cell
    0x28e918: 0xe5860014,  # str r0,[r6,#0x14]          — BEFORE the NULL test
    0x28e91c: 0x0a00002a,  # beq 0x28e9cc               — no frames -> tail
    0x28e920: 0xe59f81e8,  # ldr r8,[pc,#0x1e8]         — pool 0x28eb10
    0x28e928: 0xe59f11e4,  # ldr r1,[pc,#0x1e4]         — pool 0x28eb14
    0x28e930: 0xe59f21e0,  # ldr r2,[pc,#0x1e0]         — pool 0x28eb18
    0x28e934: 0xe08f8008,  # add r8,pc,r8               — "time"
    0x28e938: 0xe08f1001,  # add r1,pc,r1               — "rotateMix", NOT +4
    0x28e940: 0xe08f2002,  # add r2,pc,r2               — "translateMix"
    0x28e948: 0xe1a00005,  # mov r0,r5                  — loop head 0x28e948
    0x28e950: 0xe3a02000,  # mov r2,#0                  — "time" default 0.0f
    0x28e958: 0xebffe2b9,  # bl Json_getFloat
    0x28e960: 0xe3a025fe,  # mov r2,#1065353216         — 1.0f
    0x28e970: 0xebffe2b3,  # bl Json_getFloat           — rotateMix
    0x28e978: 0xe3a025fe,  # mov r2,#1065353216         — 1.0f
    0x28e984: 0xebffe2ae,  # bl Json_getFloat           — translateMix
    0x28e998: 0xe58d0000,  # str r0,[sp]                — 5th arg on the stack
    0x28e9a0: 0xebffd1b6,  # bl spPathConstraintMixTimeline_setFrame
    0x28e9b0: 0xebfff265,  # bl readCurve               — B17's OWN site
    0x28e9b4: 0xe5955000,  # ldr r5,[r5]                — frame = frame->next
    0x28e9b8: 0xe2877001,  # add r7,r7,#1               — frameIndex++
    0x28e9c4: 0x1affffdf,  # bne 0x28e948               — frame loop back edge
    0x28e9cc: 0xe594200c,  # ldr r2,[r4,#0xc]           — declared count (tail)
    0x28e9dc: 0xe2422001,  # sub r2,r2,#1
    0x28e9e8: 0xe0822082,  # add r2,r2,r2,lsl#1         — THREE-float stride
    0x28e9ec: 0xe7816103,  # str r6,[r1,r3,lsl#2]       — timelines[count]
    0x28e9f4: 0xe0833102,  # add r3,r3,r2,lsl#2
    0x28e9fc: 0xeeb47ae7,  # vcmpe.f32 s14,s15
    0x28ea04: 0xcef07a47,  # vmovgt.f32 s15,s14
    0x28ea08: 0xedcb7a01,  # vstr s15,[r11,#4]          — duration store
    0x28ea0c: 0xeafffd8d,  # b 0x28e048                 — shared node advance
    0x28e048: 0xe5944000,  # ldr r4,[r4]                — beq target semantics
    0x28e050: 0x1affffb9,  # bne 0x28df3c               — B13 inner loop head
    0x28e538: 0x1a0000eb,  # bne 0x28e8ec               — the ONLY B17 entry
}
SYMBOL_PINS = {
    'spSkeletonJson_readSkeletonData': (0x28b84c, 13044),
    'Json_getFloat': (0x287444, 28),
    'Json_getItem': (0x2873c4, 100),
    'spPathConstraintMixTimeline_create': (0x283068, 24),
    'spPathConstraintMixTimeline_setFrame': (0x283080, 48),
    'spPathConstraintPositionTimeline_create': (0x283010, 24),
    'spPathConstraintPositionTimeline_setFrame': (0x283028, 20),
    'spPathConstraintSpacingTimeline_create': (0x28303c, 24),
    '_spBaseTimeline_create': (0x282a10, 128),
    '_spCurveTimeline_init': (0x2816d8, 68),
    '_spTimeline_init': (0x281328, 60),
    'spCurveTimeline_setStepped': (0x2817c0, 24),
    'spCurveTimeline_setCurve': (0x2817d8, 264),
}
# Anonymous callee: no .dynsym/.symtab entry, so the ONLY proof is the call
# site plus the claim that no symbol range covers the address.  0x28e9b0 is
# B17's site; 0x28dff4 is B13's (pinned separately as a sibling, not as ours).
ANON_CALLEES = {
    'readCurve': {'target': 0x28b34c, 'first_word': 0xe92d4030,
                  'sites': [0x28e9b0]},
}
SIBLING_READCURVE_SITE = 0x28dff4
# (literal pool word address, the ADD site whose +8 PC base resolves it,
#  expected text).  va = add_site + 8 + pool_word — pass the ADD address.
KEY_PINS = (
    (0x28eb10, 0x28e934, 'time'),          # B17 loop key 1
    (0x28eb14, 0x28e938, 'rotateMix'),     # B17 loop key 2 — NOT "teMix"
    (0x28eb18, 0x28e940, 'translateMix'),  # B17 loop key 3
    (0x28eabc, 0x28dec4, 'mix'),           # B13 spill [sp+0x48], B17 guard key
    (0x28ea9c, 0x28dcd8, 'rotateMix'),     # B12 site: must resolve to the SAME VA
)
# The 73-instruction B17 body may call ONLY these targets.  This is the
# static form of "B17 has no lookup, no scan and no error path".
B17_CALLS = [
    (0x28e8f4, 0x000b6574, 'strcmp@plt'),
    (0x28e904, 0x000283068, 'spPathConstraintMixTimeline_create'),
    (0x28e958, 0x000287444, 'Json_getFloat'),
    (0x28e970, 0x000287444, 'Json_getFloat'),
    (0x28e984, 0x000287444, 'Json_getFloat'),
    (0x28e9a0, 0x000283080, 'spPathConstraintMixTimeline_setFrame'),
    (0x28e9b0, 0x00028b34c, 'readCurve'),
]
FORBIDDEN_TARGETS = {
    0x28b784: '_spSkeletonJson_setError',
    0x28147c: 'spAnimation_dispose',
    0x28b2f0: 'spSkeletonData_findPathConstraint',
    0x28adf8: 'spSkeletonData_dispose',
}
# (island start, first instruction word, entering branch site, its word,
#  entering target).  All five islands inside the census B17 span
# 0x28e8ec..0x28ea88 are entered from OUTSIDE it; B17's 0x28ea0c is `b`.
FOREIGN_ISLANDS = (
    (0x28ea10, 0xe1a0000b, 0x28d538, 0x0a000534, 0x28ea10),  # B5 slot-not-found
    (0x28ea40, 0xe1a03002, 0x28d3c8, 0x0a00059c, 0x28ea40),  # B4 sum island
    (0x28ea48, 0xe59d8020, 0x28dee4, 0x0a0002d7, 0x28ea48),  # E7 path-not-found
    (0x28ea74, 0xe59d0020, 0x28e550, 0x9a000147, 0x28ea74),  # B13 spacing scale
    (0x28ea80, 0xe59d3030, 0x28d3bc, 0x0a0005af, 0x28ea80),  # B4 sum island
)


def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def run(argv, timeout=60):
    return subprocess.run([str(x) for x in argv], text=True, capture_output=True,
                          timeout=timeout)


def replace_once(text, old, new):
    if text.count(old) != 1:
        raise ValueError('mutation site not unique: ' + old)
    return text.replace(old, new, 1)


def bl_target(word, addr):
    """ARM32 BL: 0xeb??????, imm24<<2 signed, pc = addr+8."""
    if (word >> 24) != 0xeb:
        raise ValueError(f'not a BL at {addr:#x}: {word:#x}')
    imm = word & 0xffffff
    if imm & 0x800000:
        imm -= 0x1000000
    return (addr + 8 + (imm << 2)) & 0xffffffff


def b_target(word, addr):
    """ARM32 B / conditional B: imm24<<2 signed, pc = addr+8."""
    if (word & 0x0f000000) not in (0x0a000000, 0x0b000000):
        raise ValueError(f'not a B at {addr:#x}: {word:#x}')
    imm = word & 0xffffff
    if imm & 0x800000:
        imm -= 0x1000000
    return (addr + 8 + (imm << 2)) & 0xffffffff


def static(so):
    if sha(so) != PIN:
        raise ValueError('original SHA mismatch')
    with so.open('rb') as f:
        e = ELFFile(f)
        segs = [(s['p_vaddr'], s.data()) for s in e.iter_segments()
                if s['p_type'] == 'PT_LOAD']
        # This library has no .symtab; .dynsym is the authoritative table.
        sec = e.get_section_by_name('.dynsym')
        if sec is None:
            raise ValueError('.dynsym missing')
        syms = []
        found = {}
        for sym in sec.iter_symbols():
            if sym.name:
                syms.append((sym.name, sym['st_value'], sym['st_size']))
                if sym.name not in found:
                    found[sym.name] = (sym['st_value'], sym['st_size'])
        for name, (va, size) in SYMBOL_PINS.items():
            if found.get(name) != (va, size):
                raise ValueError(f'symbol pin drifted: {name}: {found.get(name)}')

        def raw(a, n):
            for va, data in segs:
                if va <= a and a + n <= va + len(data):
                    return data[a - va:a - va + n]
            raise ValueError('unmapped original ' + hex(a))

        def covered_by_symbol(addr):
            hits = []
            for name, value, size in syms:
                if size and value <= addr < value + size:
                    hits.append((name, hex(value), size))
            return hits

        words = {hex(a): struct.unpack('<I', raw(a, 4))[0] for a in WORD_PINS}
        for a, want in WORD_PINS.items():
            if words[hex(a)] != want:
                raise ValueError(f'word pin drifted at {a:#x}: '
                                 f'{words[hex(a)]:#x} != {want:#x}')
        keys = []
        for pool, add_site, want in KEY_PINS:
            w = struct.unpack('<I', raw(pool, 4))[0]
            va = (add_site + 8 + w) & 0xffffffff
            value = raw(va, 96).split(b'\0', 1)[0].decode('ascii')
            if value != want:
                raise ValueError(f'pc-relative key mismatch {add_site:#x}: '
                                 f'{value!r} != {want!r}')
            keys.append({'pool': hex(pool), 'add_site': hex(add_site),
                         'va': hex(va), 'value': value})
        # The corrected +4 claim: B17's second key and B12's literal must be
        # the SAME VA (plain sharing), and the byte at +4 must not be used.
        if keys[1]['va'] != keys[4]['va']:
            raise ValueError('B17 rotateMix and B12 rotateMix no longer share a VA')
        if int(keys[1]['va'], 16) != 0x357cc0:
            raise ValueError('rotateMix VA is not 0x357cc0')
        if raw(0x357cc4, 5) != b'teMix':
            raise ValueError('the +4 suffix claim cannot be reproduced as a control')
        anon = {}
        for name, spec in ANON_CALLEES.items():
            target = spec['target']
            if name in found:
                raise ValueError(f'{name} unexpectedly present in .dynsym')
            if covered_by_symbol(target):
                raise ValueError(f'{target:#x} is covered by a symbol: '
                                 f'{covered_by_symbol(target)}')
            if struct.unpack('<I', raw(target, 4))[0] != spec['first_word']:
                raise ValueError(f'{name} first instruction drifted at {target:#x}')
            sites = []
            for site in spec['sites']:
                w = struct.unpack('<I', raw(site, 4))[0]
                got = bl_target(w, site)
                if got != target:
                    raise ValueError(f'{name} call site {site:#x} targets '
                                     f'{got:#x}, not {target:#x}')
                sites.append({'site': hex(site), 'word': hex(w), 'target': hex(got)})
            anon[name] = {'address': hex(target), 'sites': sites,
                          'proof': 'no .dynsym entry and no symbol range covers the address'}
        # B17's BL roster: exactly seven calls, no error/lookup/dispose.
        roster = []
        for a in range(0x28e8ec, 0x28ea10, 4):
            w = struct.unpack('<I', raw(a, 4))[0]
            if (w >> 24) == 0xeb:
                roster.append((a, bl_target(w, a)))
        want_roster = [(site, target) for site, target, _ in B17_CALLS]
        if roster != want_roster:
            raise ValueError(f'B17 BL roster drifted: {[(hex(a), hex(t)) for a, t in roster]}')
        for _, target in roster:
            if target in FORBIDDEN_TARGETS:
                raise ValueError(f'B17 calls forbidden {FORBIDDEN_TARGETS[target]}')
        # The sibling readCurve site must be distinct and target the same body.
        sw = struct.unpack('<I', raw(SIBLING_READCURVE_SITE, 4))[0]
        if bl_target(sw, SIBLING_READCURVE_SITE) != 0x28b34c:
            raise ValueError('B13 readCurve site drifted')
        if SIBLING_READCURVE_SITE == ANON_CALLEES['readCurve']['sites'][0]:
            raise ValueError('B17 and B13 readCurve sites are not distinct')
        # The five foreign islands inside the census span.
        islands = []
        for start, first_word, site, site_word, target in FOREIGN_ISLANDS:
            got = struct.unpack('<I', raw(start, 4))[0]
            if got != first_word:
                raise ValueError(f'island first word drifted at {start:#x}')
            sw2 = struct.unpack('<I', raw(site, 4))[0]
            if sw2 != site_word:
                raise ValueError(f'island branch word drifted at {site:#x}')
            if b_target(sw2, site) != target:
                raise ValueError(f'island branch at {site:#x} no longer targets {target:#x}')
            islands.append({'start': hex(start), 'first_word': hex(first_word),
                            'entered_from': hex(site), 'branch_word': hex(site_word),
                            'target': hex(target)})
        # B17's last instruction must be an unconditional branch, so the
        # foreign block at 0x28ea10 cannot be reached by fall-through; the
        # instruction before B17 must also branch away (entry is the single
        # 0x28e538 bne).
        last = struct.unpack('<I', raw(0x28ea0c, 4))[0]
        if (last >> 24) != 0xea or b_target(last, 0x28ea0c) != 0x28e048:
            raise ValueError('B17 does not end with `b 0x28e048`')
        prev = struct.unpack('<I', raw(0x28e8e8, 4))[0]
        if (prev >> 24) != 0xea or b_target(prev, 0x28e8e8) != 0x28da44:
            raise ValueError('B17 is not preceded by an unconditional branch')
    return {'original_sha256': PIN,
            'symbol_pins': {k: [hex(v[0]), v[1]] for k, v in SYMBOL_PINS.items()},
            'anonymous_callees': anon,
            'sibling_readCurve_site': {'site': hex(SIBLING_READCURVE_SITE),
                                       'word': hex(sw),
                                       'target': hex(bl_target(sw, SIBLING_READCURVE_SITE))},
            'b17_call_roster': [{'site': hex(a), 'target': hex(t), 'symbol': n}
                                for a, t, n in B17_CALLS],
            'foreign_islands': islands,
            'word_pins': words, 'segment_key_literals': keys,
            'key_decode_note': ('B17 key 2 resolves to 0x357cc0 "rotateMix" via the add at '
                                '0x28e938; 0x28e93c is `str r1,[sp,#0x30]`. The sibling '
                                'path checker used 0x28e93c and recorded a phantom '
                                '+4 "teMix" (0x357cc4).'),
            'note': 'Static anchors, not original execution/equivalence'}


def dependency_binding():
    flags = [f for f in FLAGS if not f.startswith(('-Wl,', '-fuse-ld='))
             and f not in ('-nostdlib', '-static')]
    deps = set(SOURCES) | {Path(__file__).resolve()}
    for src in SOURCES:
        p = run(['clang', *flags, *['-I' + str(i) for i in INCLUDES], '-MM', src])
        if p.returncode:
            raise RuntimeError(p.stderr)
        text = p.stdout.replace('\\\n', ' ')
        deps.update(Path(x).resolve() for x in text.split(':', 1)[1].split())
    return {str(p): sha(p) for p in sorted(deps)}


def build(out, name, opt='-O2', overrides=None, extra=(), omit=()):
    used = [(overrides or {}).get(p, p) for p in SOURCES if p not in omit]
    binary = out / (name + '.arm')
    argv = ['clang', *FLAGS, opt, *extra,
            *['-I' + str(i) for i in INCLUDES], *used, '-o', binary]
    p = run(argv)
    (out / (name + '.build.log')).write_text(p.stdout + p.stderr)
    result = {'compile_rc': p.returncode,
              'compile_command': [str(x) for x in argv]}
    if p.returncode:
        return {**result, 'diagnostic': p.stderr}
    before = sha(binary)
    result['binary_sha256'] = before
    result['translation_units'] = {str(s): sha(s) for s in used}
    print('BINDING v1 entry=tl-path-mix run=' + name
          + ' original_sha256=' + PIN + ' fixture_sha256=' + sha(FIX)
          + ' binary_sha256=' + before, flush=True)
    p = run(['qemu-arm', binary], 15)
    (out / (name + '.log')).write_text(p.stdout + p.stderr)
    if sha(binary) != before:
        raise RuntimeError('executed binary drift')
    return {**result, 'exit_code': p.returncode, 'stdout': p.stdout,
            'stderr': p.stderr,
            'passes': re.findall(r'^PASS (.+)$', p.stdout, re.M),
            'failures': re.findall(r'^FAIL (.+)$', p.stdout, re.M)}


def mutations():
    """Thirteen mutants of the BODY text only; each must be refused by a
    NAMED runtime assertion.  Every mutant still compiles cleanly."""
    return [
        # --- the puzzle guard -------------------------------------------
        ('mix_guard_inverted', BODY, [
            ('    if (strcmp(timelineNode->name, "mix") == 0)',
             '    if (strcmp(timelineNode->name, "mix") != 0)   /* mutated: inverted */')],
         'exits through 0x28e8fc beq 0x28e048'),
        ('mix_guard_dropped', BODY, [
            ('    if (strcmp(timelineNode->name, "mix") == 0)',
             '    if (0)   /* mutated: the skip is gone */')],
         'exits through 0x28e8fc beq 0x28e048'),
        ('mix_guard_literal', BODY, [
            ('    if (strcmp(timelineNode->name, "mix") == 0)',
             '    if (strcmp(timelineNode->name, "mux") == 0)   /* mutated: key */')],
         'exits through 0x28e8fc beq 0x28e048'),
        # --- create / index store ---------------------------------------
        ('create_count_one', BODY, [
            ('        spPathConstraintMixTimeline_create((int)timelineNode->unk_0c);',
             '        spPathConstraintMixTimeline_create(1);   /* mutated: count */')],
         'create receives the declared count from Json+0x0c (0x28e900)'),
        ('index_store_dropped', BODY, [
            ('    timeline->pathConstraintIndex = path_constraint_index;',
             '    timeline->pathConstraintIndex = 0; (void)path_constraint_index;   /* mutated: no cell read */')],
         'the [sp+0x2c] cell value is stored at timeline+0x14 (0x28e918)'),
        # --- frame loop -------------------------------------------------
        ('time_default_one', BODY, [
            ('            float time = Json_getFloat(frame, "time", 0.0f);',
             '            float time = Json_getFloat(frame, "time", 1.0f);   /* mutated */')],
         'an absent "time" yields the 0.0f default (0x28e950 mov r2,#0)'),
        ('translate_default_zero', BODY, [
            ('            float translateMix = Json_getFloat(frame, "translateMix", 1.0f);',
             '            float translateMix = Json_getFloat(frame, "translateMix", 0.0f);   /* mutated */')],
         'an absent "translateMix" yields the 1.0f default (0x28e978 mov r2,#1065353216)'),
        ('rotate_translate_swap', BODY, [
            ('                                                 time, rotateMix, translateMix);',
             '                                                 time, translateMix, rotateMix);   /* mutated */')],
         'setFrame receives (time, rotateMix, translateMix) in AAPCS order'),
        ('rotate_key_literal', BODY, [
            ('            float rotateMix = Json_getFloat(frame, "rotateMix", 1.0f);',
             '            float rotateMix = Json_getFloat(frame, "rotateMixx", 1.0f);   /* mutated */')],
         'setFrame receives (time, rotateMix, translateMix) in AAPCS order'),
        ('readcurve_dropped', BODY, [
            ('            readCurve(frame, (void*)timeline, frameIndex);',
             '            (void)frameIndex;   /* mutated: readCurve is gone */')],
         'readCurve runs once per frame after setFrame (0x28e9b0)'),
        ('frame_index_stuck', BODY, [
            ('            ++frameIndex;                                /* 0x28e9b8 add r7,r7,#1 */',
             '            /* mutated: the frameIndex increment is gone */')],
         'setFrame runs once per frame with a 0-based incrementing index'),
        # --- the tail ---------------------------------------------------
        ('tail_stride_two', BODY, [
            ('        word_index = (declared - 1u) * 3u;',
             '        word_index = (declared - 1u) * 2u;   /* mutated: stride 2 */')],
         'duration reads frames[(declared-1)*3] = the last frame\'s TIME'),
        ('duration_compare_polarity', BODY, [
            ('        if (duration > last)',
             '        if (duration < last)   /* mutated: polarity */')],
         'duration reads frames[(declared-1)*3] = the last frame\'s TIME'),
    ]


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--so', type=Path, required=True)
    ap.add_argument('--out', type=Path, required=True)
    ap.add_argument('--smoke', action='store_true')
    ns = ap.parse_args()
    ns.out.mkdir(parents=True, exist_ok=False)
    tmp = ns.out / 'compiler-tmp'
    tmp.mkdir()
    os.environ['TMPDIR'] = str(tmp)
    report = {'schema': 'cally-tl-path-mix-check/1', 'tier': 'test_anchored',
              'original_executed': False,
              'entry': ('path-constraint MIX timeline block B17 '
                        '0x28e8ec-0x28ea0c (73 insns) inside census span '
                        '0x28e8ec-0x28ea88'),
              'scope': (
                  'Reconstructed B17 only: the "mix" skip guard, the immediate '
                  'create + unconditional +0x14 index store, the time/rotateMix/'
                  'translateMix frame loop with readCurve, and the three-float '
                  'publish/duration tail. Real Json_getFloat, real readCurve, real '
                  '_malloc/_free/_calloc and the real error chain are linked. '
                  'Synthetic boundaries: spPathConstraintMixTimeline_create/'
                  'setFrame (argument recorders whose store shape follows the '
                  'disassembled bodies), spCurveTimeline_setStepped/setCurve '
                  'recorders, fixture heap + allocator roster, libc providers, '
                  'hand-built Json nodes. The census span also contains five '
                  'foreign islands entered from outside B17; they are pinned as '
                  'boundary evidence and NOT translated here. Not an '
                  'original-equivalence claim.'),
              'puzzle': {
                  'branch': '0x28e8fc beq 0x28e048',
                  'target_semantics': ('0x28e048 ldr r4,[r4] = the shared '
                                       'timeline-node advance; 0x28e04c cmp / '
                                       '0x28e050 bne 0x28df3c continues B13\'s '
                                       'inner dispatch loop'),
                  'conclusion': ('a path sub-key named exactly "mix" is handled by '
                                 'NOBODY: B17 skips it silently (no create, no '
                                 'setFrame, no readCurve, no publish, no duration '
                                 'update, no error). Every OTHER name falls through '
                                 'and IS loaded as a mix timeline (type 13). The '
                                 'compiled guard is `strcmp(name,"mix") == 0 -> '
                                 'goto next`; a missing `== 0` at source level is a '
                                 'hypothesis, not a bytecode claim.'),
                  'observable': ('fixture mix_name_skipped / other_name_creates_mix / '
                                 'mix_between_others / skip_is_transparent'),
                  'who_else_compares_mix': ('B13 compares only "position"/'
                                            '"spacing"; B6/B12/B14-B16 do not see '
                                            'path sub-keys. No other block claims '
                                            'the name.')},
              'boundary': {
                  'b17_body': '0x28e8ec-0x28ea0c (73 insns / 292 B)',
                  'census_span': ('0x28e8ec-0x28ea88 (412 B / 103 insns) also '
                                  'contains 30 foreign instructions'),
                  'foreign_islands': [
                      '0x28ea10-0x28ea3c (12) B5 slot-not-found error, from 0x28d538',
                      '0x28ea40-0x28ea44 (2) B4 sum island, from 0x28d3c8',
                      '0x28ea48-0x28ea70 (11) E7 path-not-found, from 0x28dee4 '
                      '(already in c/spine_read_tl_path)',
                      '0x28ea74-0x28ea7c (3) B13 spacing scale, from 0x28e550 '
                      '(already in c/spine_read_tl_path)',
                      '0x28ea80-0x28ea84 (2) B4 sum island, from 0x28d3bc'],
                  'b17_has_no_error_block': ('its BL roster is strcmp / create / '
                                             'Json_getFloat x3 / setFrame / '
                                             'readCurve only'),
                  'b17_has_no_lookup_or_scan': ('no spSkeletonData_findPathConstraint '
                                                'call; it consumes B13\'s [sp+0x2c] '
                                                'cell at 0x28e914'),
                  'key_decode_correction': ('pool 0x28eb14 + add 0x28e938 (PC base '
                                            '0x28e940) = 0x357cc0 "rotateMix"; there '
                                            'is no +4 "teMix" suffix. The sibling '
                                            'path checker used 0x28e93c (a str) as '
                                            'the add site.')},
              'subject': {'body': str(BODY), 'header': str(HEADER), 'fixture': str(FIX)},
              'runs': [], 'teeth': [], 'compile_guards': [],
              'declared_tests': TESTS, 'declared_summary': SUMMARY,
              'status': 'INCOMPLETE'}
    try:
        report['static'] = static(ns.so)
        report['source_binding'] = dependency_binding()
        report['toolchain'] = {n: run([n, '--version']).stdout.splitlines()[0]
                               for n in ('clang', 'qemu-arm')}
        configs = [('O2', '-O2', ())] if ns.smoke else [
            ('O0', '-O0', ()), ('O2', '-O2', ()), ('O3', '-O3', ()),
            ('ubsan', '-O2', ('-fsanitize=undefined,float-cast-overflow',
                              '-fsanitize-trap=all'))]
        for name, opt, extra in configs:
            r = build(ns.out, name, opt, extra=extra)
            report['runs'].append({'name': name, **r})
            if (r.get('compile_rc') or r['exit_code'] or r['passes'] != TESTS
                    or r['failures'] or SUMMARY not in r['stdout']):
                raise RuntimeError(f'{name}: acceptance failed {r}')
            print('PASS', name, 'declared_tests=' + str(len(TESTS)), flush=True)
        if not ns.smoke:
            for name, subject, edits, expect in mutations():
                text = subject.read_text()
                for old, new in edits:
                    text = replace_once(text, old, new)
                candidate = ns.out / (name + '.c')
                candidate.write_text(text)
                r = build(ns.out, name, overrides={subject: candidate})
                hit = [f for f in r.get('failures', []) if expect in f]
                caught = (r.get('compile_rc') == 0 and r.get('exit_code') == 1
                          and len(hit) == 1)
                report['teeth'].append({'name': name,
                                        'expected_failure_substring': expect,
                                        'failed_by': hit,
                                        'caught_by_named_assertion': caught, **r})
                if not caught:
                    raise RuntimeError('mutant not rejected by named runtime '
                                       f'assertion: {name}: {r}')
                print('TEETH', name, hit, flush=True)
            missing = build(ns.out, 'missing-tl-path-mix-body', omit=(BODY,))
            if (not missing['compile_rc']
                    or 'undefined symbol: readSkeletonData_pathMixTimeline'
                    not in missing['diagnostic']):
                raise RuntimeError('missing path-mix body not refused')
            report['compile_guards'].append({'name': 'missing-tl-path-mix-body',
                                             'refused': True, **missing})
            print('GUARD missing-tl-path-mix-body refused', flush=True)
            # Second door: the real readCurve translation unit must be linked,
            # otherwise the call at 0x28e9b0 has no definition.  A stub would
            # satisfy the link, so this proves the source, not a placeholder.
            nostub = build(ns.out, 'unlinked-read-curve', omit=(CURVE_SRC,))
            if (not nostub['compile_rc']
                    or 'undefined symbol: readCurve' not in nostub['diagnostic']):
                raise RuntimeError('readCurve source removal not refused')
            report['compile_guards'].append({'name': 'unlinked-read-curve',
                                             'refused': True, **nostub})
            print('GUARD unlinked-read-curve refused', flush=True)
            # Third door: the Json accessors must come from c/json_interface.
            nojson = build(ns.out, 'unlinked-json-interface', omit=(JSON_SRC,))
            if (not nojson['compile_rc']
                    or 'undefined symbol: Json_getFloat' not in nojson['diagnostic']):
                raise RuntimeError('Json accessor source removal not refused')
            report['compile_guards'].append({'name': 'unlinked-json-interface',
                                             'refused': True, **nojson})
            print('GUARD unlinked-json-interface refused', flush=True)
            # Fourth door: B17 has no constraint lookup and no scan.  A body
            # that calls findPathConstraint cannot link because the fixture
            # deliberately does not provide it.
            nolookup_text = BODY.read_text()
            nolookup_text = replace_once(
                nolookup_text,
                'int\nreadSkeletonData_pathMixTimeline(',
                'extern void* spSkeletonData_findPathConstraint(void*, const char*);\n'
                'int\nreadSkeletonData_pathMixTimeline(')
            nolookup_text = replace_once(
                nolookup_text,
                '    timeline = (spPathConstraintTimelineMixShape*)\n'
                '        spPathConstraintMixTimeline_create((int)timelineNode->unk_0c);',
                '    (void)spSkeletonData_findPathConstraint(0, timelineNode->name);\n'
                '    timeline = (spPathConstraintTimelineMixShape*)\n'
                '        spPathConstraintMixTimeline_create((int)timelineNode->unk_0c);')
            nl = ns.out / 'b17-lookup-inserted.c'
            nl.write_text(nolookup_text)
            nolook = build(ns.out, 'b17-lookup-not-a-callsite',
                           overrides={BODY: nl})
            if (not nolook['compile_rc']
                    or 'undefined symbol: spSkeletonData_findPathConstraint'
                    not in nolook['diagnostic']):
                raise RuntimeError('a body that calls findPathConstraint linked; '
                                   'B17\'s no-lookup claim is not pinned')
            report['compile_guards'].append(
                {'name': 'b17-lookup-not-a-callsite', 'refused': True, **nolook})
            print('GUARD b17-lookup-not-a-callsite refused', flush=True)
            # Fifth door: the setFrame call target must be the MIX symbol
            # 0x283080.  The position twin 0x283028 is not defined by the
            # fixture, so a body that calls it cannot link.
            twin_text = BODY.read_text()
            twin_text = replace_once(
                twin_text,
                'int\nreadSkeletonData_pathMixTimeline(',
                'extern void spPathConstraintPositionTimeline_setFrame'
                '(void*, int, float, float);\n'
                'int\nreadSkeletonData_pathMixTimeline(')
            twin_text = replace_once(
                twin_text,
                '            spPathConstraintMixTimeline_setFrame((void*)timeline, frameIndex,',
                '            (void)translateMix;   /* the 4-arg twin does not take it */\n'
                '            spPathConstraintPositionTimeline_setFrame((void*)timeline, frameIndex,')
            twin_text = replace_once(
                twin_text,
                '                                                 time, rotateMix, translateMix);',
                '                                                 time, rotateMix);   /* mutated: 4 args */')
            tw = ns.out / 'position-setframe.c'
            tw.write_text(twin_text)
            twinbuilt = build(ns.out, 'position-setframe-not-a-callsite',
                              overrides={BODY: tw})
            if (not twinbuilt['compile_rc']
                    or 'undefined symbol: spPathConstraintPositionTimeline_setFrame'
                    not in twinbuilt['diagnostic']):
                raise RuntimeError('position setFrame twin (0x283028) was linkable; '
                                   'the 0x28e9a0 call target is not pinned')
            report['compile_guards'].append(
                {'name': 'position-setframe-not-a-callsite', 'refused': True,
                 **twinbuilt})
            print('GUARD position-setframe-not-a-callsite refused', flush=True)
        if any(sha(p) != v for p, v in report['source_binding'].items()):
            raise RuntimeError('bound source/header/checker drift')
        report['status'] = 'SMOKE_PASS' if ns.smoke else 'PASS'
    except Exception as ex:
        report['error'] = str(ex)
        raise
    finally:
        (ns.out / 'receipt.json').write_text(
            json.dumps(report, ensure_ascii=False, indent=2) + '\n')
    print('RESULT ' + report['status'] + '; ORIGINAL NOT EXECUTED; receipt='
          + str(ns.out / 'receipt.json'), flush=True)


if __name__ == '__main__':
    main()
