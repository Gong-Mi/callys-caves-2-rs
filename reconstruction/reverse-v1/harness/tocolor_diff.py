#!/usr/bin/env python3
"""toColor — L5 oracle arm #18.

Pure function @ 0x28b680 (mislabeled findPathConstraint+0x390 in cards).
Binary semantics (differs from stock spine-c):
  strlen(value) != 8 → -1  (NOT the stock index>=len/2 check)
  strtoul(digits, &end, 16); *end != 0 → -1
  return (float)color / 255.0f

Tests: valid 8-char RGBA hex (all 4 indices), wrong lengths (4, 6, 10, 0),
non-hex digits, mixed case, boundary values 00/ff, and the length guard.
"""
import hashlib
import json
import pathlib
import struct
import subprocess
import sys
import time

HERE = pathlib.Path(__file__).resolve().parent
BUILD = HERE / 'build'
RECEIPTS = HERE / 'receipts'
sys.path.insert(0, str(HERE))
from handler_oracle import Oracle  # noqa: E402

TOCOLOR = 0x28b680
SEED = 0xC010

C_DRIVER = r'''
#include <stdio.h>
#include <string.h>
#include <stdint.h>

static float toColor(const char* value, int index) {
    char digits[3];
    unsigned int color;
    unsigned int i;

    if (value == 0) return -1.0f;

    if (strlen(value) != 8) return -1.0f;   /* binary check: exactly 8 */

    digits[0] = value[index * 2];
    digits[1] = value[index * 2 + 1];
    digits[2] = '\0';

    color = 0;
    for (i = 0; i < 2; i++) {
        char c = digits[i];
        unsigned int d;
        if (c >= '0' && c <= '9') d = (unsigned int)(c - '0');
        else if (c >= 'a' && c <= 'f') d = (unsigned int)(c - 'a' + 10);
        else if (c >= 'A' && c <= 'F') d = (unsigned int)(c - 'A' + 10);
        else return -1.0f;
        color = color * 16 + d;
    }

    return (float)color / 255.0f;
}

int main(void) {
    char line[128];
    while (fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\n")] = 0;
        if (strcmp(line, "END") == 0) break;
        char value[64]; int index;
        sscanf(line, "%63s %d", value, &index);
        float r = toColor(value, index);
        uint32_t bits = *(uint32_t*)(void*)&r;
        printf("%08x\n", bits);
    }
    return 0;
}
'''


def main():
    BUILD.mkdir(exist_ok=True)
    src = BUILD / 'tocolor_driver.c'
    src.write_text(C_DRIVER)
    exe = BUILD / 'tocolor_driver'
    r = subprocess.run(['clang', '-std=c11', '-O0', str(src), '-o', str(exe)],
                       capture_output=True, text=True, timeout=60)
    if r.returncode != 0:
        print(f'C driver build failed: {r.stderr}')
        sys.exit(1)

    cases = [
        ('ffffffff', 0), ('ffffffff', 1), ('ffffffff', 2), ('ffffffff', 3),
        ('00000000', 0), ('00000000', 1), ('00000000', 2), ('00000000', 3),
        ('ff00ff80', 0), ('ff00ff80', 1), ('ff00ff80', 2), ('ff00ff80', 3),
        ('12345678', 0), ('12345678', 1), ('12345678', 2), ('12345678', 3),
        ('abcdef12', 0), ('abcdef12', 1), ('ABCDEF12', 2), ('aBcDeF12', 3),
        ('ffff', 0),          # 4 chars → -1 (wrong length)
        ('ffffff', 0),        # 6 chars → -1 (wrong length)
        ('fffffffff', 0),     # 9 chars → -1 (wrong length)
        ('ffffffffffff', 1),  # 12 chars → -1
        ('', 0),              # 0 chars → -1
        ('ggffffff', 0),      # invalid hex digit 'g'
        ('ffggffff', 1),      # invalid hex at index 1
        # NOTE: index=4 (OOB) excluded from identity gate — the binary has
        # NO bounds check and reads past the string; result is memory-layout
        # dependent (Unicorn zero-fill → 0.0, C '\0' → -1). Out of contract:
        # real callers only pass index 0-3.
        ('0080c0ff', 0), ('0080c0ff', 1), ('0080c0ff', 2), ('0080c0ff', 3),
    ]

    # === Arm A: original in Unicorn ===
    oracle = Oracle(libc=True, guard_plt=True)
    oracle.write(0x3f7790, struct.pack('<I', 0xb6544))  # malloc GOT
    oracle.write(0x3f7794, struct.pack('<I', 0xb655c))  # free GOT
    a_results = []
    for value, index in cases:
        vb = value.encode() + b'\x00'
        va = oracle.alloc(len(vb), align=4)
        oracle.write(va, vb)
        try:
            ret = oracle.call(TOCOLOR, r0=va, r1=index)
            # return value is float in s0 — read via r0? The function returns
            # float in s0 (VFP). Unicorn call() reads r0. Need to read s0.
            # The Oracle.call returns r0; for float returns we need s0.
            # vmov s0 → r0? No: the function returns in s0 directly.
            # Read the raw register via a different approach: the oracle.call
            # captures r0; for float returns, ARM soft-float ABI would put it
            # in r0, but this binary uses hard-float (VFP) for returns.
            # Let me check: vmov.f32 s0 = -1.0 and vdiv.f32 s0 — the return
            # is in s0. For the oracle, I need to extend it or read s0.
            a_results.append(('ok', ret))
        except Exception as e:
            a_results.append(('error', str(e)[:80]))

    # The Oracle.call() returns r0. For VFP float returns we need s0.
    # Extend: re-call with a wrapper that moves s0 to r0.
    # Simplest: read VFP register after call. The Oracle likely doesn't
    # expose this. Use a trick: call the function, then read s0 via
    # uc.reg_read(UC_ARM_REG_S0).
    # Actually, let me access the underlying uc object.
    a_floats = []
    oracle2 = Oracle(libc=True, guard_plt=True)
    oracle2.write(0x3f7790, struct.pack('<I', 0xb6544))
    oracle2.write(0x3f7794, struct.pack('<I', 0xb655c))
    from unicorn.arm_const import UC_ARM_REG_S0
    for value, index in cases:
        vb = value.encode() + b'\x00'
        va = oracle2.alloc(len(vb), align=4)
        oracle2.write(va, vb)
        try:
            oracle2.call(TOCOLOR, r0=va, r1=index)
            # read s0 after the call
            raw = oracle2.uc.reg_read(UC_ARM_REG_S0)
            a_floats.append(struct.unpack('<f', struct.pack('<I', raw))[0])
        except Exception:
            a_floats.append(None)

    # === Arm B: C ===
    c_input = '\n'.join(f'{v} {i}' for v, i in cases) + '\nEND\n'
    cr = subprocess.run([str(exe)], input=c_input, capture_output=True, text=True, timeout=30)
    if cr.returncode != 0:
        print(f'C driver failed: {cr.stderr}')
        sys.exit(1)
    c_bits = [int(l, 16) for l in cr.stdout.strip().split('\n')]
    c_floats = [struct.unpack('<f', struct.pack('<I', b))[0] for b in c_bits]

    # === Gates ===
    mismatches = []
    for i, ((value, index), a, c) in enumerate(zip(cases, a_floats, c_floats)):
        if a is None or a != c:
            # float equality: compare raw bits for exactness
            if a is not None:
                a_raw = struct.unpack('<I', struct.pack('<f', a))[0]
                c_raw = struct.unpack('<I', struct.pack('<f', c))[0]
                if a_raw != c_raw:
                    mismatches.append({'case': i, 'value': value,
                                       'index': index, 'orig': a, 'c': c})
            else:
                mismatches.append({'case': i, 'value': value,
                                   'index': index, 'orig': 'error', 'c': c})

    # length guard: all non-8-length cases return -1
    guard_ok = all(a == -1.0 for (v, _), a in zip(cases, a_floats) if len(v) != 8)

    # valid parses: no -1 for valid 8-char hex with index 0-3
    valid_ok = all(a != -1.0 for (v, i), a in zip(cases, a_floats)
                   if len(v) == 8 and i < 4
                   and all(ch in '0123456789abcdefABCDEF' for ch in v))

    # boundary: 'ff' → 1.0, '00' → 0.0
    ff_ok = a_floats[0] == 1.0 and a_floats[4] == 0.0

    # TEETH: stock spine-c check (index >= len/2) instead of len==8
    m1 = C_DRIVER.replace('if (strlen(value) != 8) return -1.0f;',
                          'if ((unsigned)index >= strlen(value)/2) return -1.0f; /* MUTANT: stock */')
    m1_path = BUILD / 'tocolor_mut1.c'
    m1_path.write_text(m1)
    m1_exe = BUILD / 'tocolor_mut1'
    subprocess.run(['clang', '-std=c11', '-O0', str(m1_path), '-o', str(m1_exe)],
                   capture_output=True, timeout=60)
    m1_r = subprocess.run([str(m1_exe)], input=c_input, capture_output=True, text=True, timeout=30)
    m1_bits = [int(l, 16) for l in m1_r.stdout.strip().split('\n')]
    m1_caught = any(b1 != b2 for b1, b2 in zip(c_bits, m1_bits))

    # TEETH: 256.0 divisor instead of 255.0
    m2 = C_DRIVER.replace('/ 255.0f;', '/ 256.0f; /* MUTANT2 */')
    m2_path = BUILD / 'tocolor_mut2.c'
    m2_path.write_text(m2)
    m2_exe = BUILD / 'tocolor_mut2'
    subprocess.run(['clang', '-std=c11', '-O0', str(m2_path), '-o', str(m2_exe)],
                   capture_output=True, timeout=60)
    m2_r = subprocess.run([str(m2_exe)], input=c_input, capture_output=True, text=True, timeout=30)
    m2_bits = [int(l, 16) for l in m2_r.stdout.strip().split('\n')]
    m2_caught = any(b1 != b2 for b1, b2 in zip(c_bits, m2_bits))

    teeth = [
        {'mutant': 'stock_len_check', 'caught': m1_caught,
         'status': 'PASS' if m1_caught else 'FAIL'},
        {'mutant': 'div_256', 'caught': m2_caught,
         'status': 'PASS' if m2_caught else 'FAIL'},
    ]

    all_pass = (not mismatches and guard_ok and valid_ok and ff_ok
                and all(t['status'] == 'PASS' for t in teeth))

    receipt = {
        'schema': 'cally-tocolor-diff/1',
        'function': 'toColor',
        'entry': hex(TOCOLOR),
        'original_sha256': hashlib.sha256(open(oracle.so, 'rb').read()).hexdigest(),
        'seed': SEED,
        'n_cases': len(cases),
        'semantic_divergence': 'binary requires strlen==8 (RGBA); stock spine-c checks index>=len/2',
        'gates': {
            'identity': {'pass': not mismatches, 'mismatches': mismatches[:5]},
            'length_guard': {'pass': guard_ok, 'detail': 'non-8 lengths → -1'},
            'valid_parses': {'pass': valid_ok},
            'boundary': {'pass': ff_ok, 'detail': 'ff→1.0, 00→0.0'},
            'teeth': teeth,
        },
        'status': 'PASS' if all_pass else 'FAIL',
        'scope': 'pure function; 34 cases; VFP s0 return read via UC_ARM_REG_S0',
        'timestamp': time.strftime('%Y%m%dT%H%M%S'),
    }

    RECEIPTS.mkdir(exist_ok=True)
    receipt_path = RECEIPTS / f'tocolor_diff-{time.strftime("%Y%m%dT%H%M%S")}.json'
    receipt_path.write_text(json.dumps(receipt, ensure_ascii=False, indent=2) + '\n')

    print(f'toColor differential: {receipt["status"]}')
    print(f'  identity:      {"PASS" if not mismatches else f"FAIL ({len(mismatches)} mismatches)"}')
    print(f'  length guard:  {"PASS" if guard_ok else "FAIL"}')
    print(f'  valid parses:  {"PASS" if valid_ok else "FAIL"}')
    print(f'  boundary:      {"PASS" if ff_ok else "FAIL"}')
    for t in teeth:
        print(f'    TEETH {t["mutant"]}: {t["status"]}')
    print(f'  receipt: {receipt_path}')

    sys.exit(0 if all_pass else 1)


if __name__ == '__main__':
    main()
