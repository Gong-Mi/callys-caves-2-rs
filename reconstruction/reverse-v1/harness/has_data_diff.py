#!/usr/bin/env python3
"""CSkeletonSprite::HasData — L5 oracle arm #14.

12 instructions: check three fields non-zero, return boolean.

  0xbd96c ldr r3, [r0]        → field at +0x00
  0xbd970 cmp r3, #0
  0xbd974 beq return_field     → if 0, return that value (r3)
  0xbd978 ldr r3, [r0, #0x4]   → field at +0x04
  0xbd97c cmp r3, #0
  0xbd980 beq return_field     → if 0, return that value
  0xbd984 ldr r0, [r0, #0x8]   → field at +0x08
  0xbd988 adds r0, r0, #0      → set flags on +0x08
  0xbd98c movne r0, #1         → if non-zero, return 1
  0xbd990 bx lr
  0xbd994 mov r0, r3            → return the field value (0)
  0xbd998 bx lr
"""
import hashlib
import json
import pathlib
import random
import struct
import subprocess
import sys
import time

HERE = pathlib.Path(__file__).resolve().parent
RV1 = HERE.parent
BUILD = HERE / 'build'
RECEIPTS = HERE / 'receipts'
sys.path.insert(0, str(HERE))
from handler_oracle import Oracle  # noqa: E402

HAS_DATA = 0xbd96c
SEED = 0xDA7A

C_DRIVER = r'''
#include <stdio.h>
#include <string.h>
#include <stdint.h>

/* CSkeletonSprite layout: three fields at +0x00, +0x04, +0x08 */
typedef struct {
    uint32_t field_00;  /* +0x00 (skeleton ptr?) */
    uint32_t field_04;  /* +0x04 (skeleton data ptr?) */
    uint32_t field_08;  /* +0x08 (count or pointer) */
} test_sprite_t;

/* Original: if any field is 0, return that 0; else if field_08 != 0, return 1 */
static int has_data(test_sprite_t* s) {
    uint32_t f0 = s->field_00;
    if (f0 == 0) return 0;  /* beq → return r3 (= 0) */
    uint32_t f4 = s->field_04;
    if (f4 == 0) return 0;  /* beq → return r3 (= 0) */
    uint32_t f8 = s->field_08;
    return (f8 != 0) ? 1 : 0;  /* adds + movne */
}

int main(void) {
    char line[64];
    while (fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\n")] = 0;
        if (strcmp(line, "END") == 0) break;
        uint32_t f0, f4, f8;
        sscanf(line, "%u %u %u", &f0, &f4, &f8);
        test_sprite_t s = {f0, f4, f8};
        printf("%d\n", has_data(&s));
    }
    return 0;
}
'''


def build_c_driver():
    BUILD.mkdir(exist_ok=True)
    src = BUILD / 'has_data_driver.c'
    src.write_text(C_DRIVER)
    exe = BUILD / 'has_data_driver'
    r = subprocess.run(['clang', '-std=c11', '-O0', '-g', str(src), '-o', str(exe)],
                       capture_output=True, text=True, timeout=60)
    if r.returncode != 0:
        raise RuntimeError(f'C driver build failed:\n{r.stderr}')
    return exe


def main():
    random.seed(SEED)

    # Test cases: (f0, f4, f8) covering all 2^3 combinations + edge values
    cases = []
    for f0 in (0, 1, 0xdead, 0xFFFFFFFF):
        for f4 in (0, 1, 0xbeef, 0xFFFFFFFF):
            for f8 in (0, 1, 0x1234, 0xFFFFFFFF):
                cases.append((f0, f4, f8))

    # Add some random cases
    for _ in range(20):
        cases.append((random.randint(0, 0xFFFFFFFF),
                      random.randint(0, 0xFFFFFFFF),
                      random.randint(0, 0xFFFFFFFF)))

    exe = build_c_driver()

    # Run arm A (original)
    oracle = Oracle(libc=True, guard_plt=True)
    a_results = []
    for f0, f4, f8 in cases:
        # Allocate object (12 bytes)
        obj = oracle.alloc(12, align=4)
        oracle.write(obj, struct.pack('<III', f0, f4, f8))
        ret = oracle.call(HAS_DATA, r0=obj)
        a_results.append(ret)

    # Run arm B (C)
    c_input = '\n'.join(f'{f0} {f4} {f8}' for f0, f4, f8 in cases) + '\nEND\n'
    r = subprocess.run([str(exe)], input=c_input, capture_output=True, text=True, timeout=30)
    if r.returncode != 0:
        print(f'C driver failed: {r.stderr}')
        sys.exit(1)
    c_results = [int(x) for x in r.stdout.strip().split('\n')]

    # === Gate: identity ===
    mismatches = []
    for i, ((f0, f4, f8), a, c) in enumerate(zip(cases, a_results, c_results)):
        if a != c:
            mismatches.append({'case': i, 'f0': f0, 'f4': f4, 'f8': f8, 'orig': a, 'c': c})

    # === Gate: coverage ===
    # All 8 combinations of (0, non-zero) for the three fields
    covered = set()
    for f0, f4, f8 in cases:
        b0 = 0 if f0 == 0 else 1
        b4 = 0 if f4 == 0 else 1
        b8 = 0 if f8 == 0 else 1
        covered.add((b0, b4, b8))
    all_combos = len(covered) == 8

    # === Gate: non-degenerate ===
    has_zero = any(a == 0 for a in a_results)
    has_one = any(a == 1 for a in a_results)

    # === Gate: TEETH ===
    teeth = []
    orig_src = C_DRIVER

    # MUTANT1: skip the field_04 check
    m1 = orig_src.replace('if (f4 == 0) return 0;', '/* MUTANT1 */')
    m1_src = BUILD / 'has_data_mut1.c'
    m1_src.write_text(m1)
    m1_exe = BUILD / 'has_data_mut1'
    subprocess.run(['clang', '-std=c11', '-O0', str(m1_src), '-o', str(m1_exe)],
                   capture_output=True, timeout=60)
    m1_r = subprocess.run([str(m1_exe)], input=c_input, capture_output=True, text=True, timeout=30)
    if m1_r.returncode == 0:
        m1_res = [int(x) for x in m1_r.stdout.strip().split('\n')]
        caught = sum(1 for a, m in zip(a_results, m1_res) if a != m)
        teeth.append({'mutant': 'skip_f4_check', 'caught': caught,
                      'status': 'PASS' if caught > 0 else 'FAIL'})

    # MUTANT2: return 0 for field_08 non-zero (inverted)
    m2 = orig_src.replace('return (f8 != 0) ? 1 : 0;', 'return 0; /* MUTANT2 */')
    m2_src = BUILD / 'has_data_mut2.c'
    m2_src.write_text(m2)
    m2_exe = BUILD / 'has_data_mut2'
    subprocess.run(['clang', '-std=c11', '-O0', str(m2_src), '-o', str(m2_exe)],
                   capture_output=True, timeout=60)
    m2_r = subprocess.run([str(m2_exe)], input=c_input, capture_output=True, text=True, timeout=30)
    if m2_r.returncode == 0:
        m2_res = [int(x) for x in m2_r.stdout.strip().split('\n')]
        caught = sum(1 for a, m in zip(a_results, m2_res) if a != m)
        teeth.append({'mutant': 'always_zero', 'caught': caught,
                      'status': 'PASS' if caught > 0 else 'FAIL'})

    # MUTANT3: return 1 when field_00 is zero (inverted first check)
    m3 = orig_src.replace('if (f0 == 0) return 0;', 'if (f0 == 0) return 1; /* MUTANT3 */')
    m3_src = BUILD / 'has_data_mut3.c'
    m3_src.write_text(m3)
    m3_exe = BUILD / 'has_data_mut3'
    subprocess.run(['clang', '-std=c11', '-O0', str(m3_src), '-o', str(m3_exe)],
                   capture_output=True, timeout=60)
    m3_r = subprocess.run([str(m3_exe)], input=c_input, capture_output=True, text=True, timeout=30)
    if m3_r.returncode == 0:
        m3_res = [int(x) for x in m3_r.stdout.strip().split('\n')]
        caught = sum(1 for a, m in zip(a_results, m3_res) if a != m)
        teeth.append({'mutant': 'f0_zero_returns_1', 'caught': caught,
                      'status': 'PASS' if caught > 0 else 'FAIL'})

    all_pass = (not mismatches and all_combos and has_zero and has_one
                and all(t['status'] == 'PASS' for t in teeth))

    receipt = {
        'schema': 'cally-hasdata-diff/1',
        'function': 'CSkeletonSprite::HasData',
        'entry': hex(HAS_DATA),
        'original_sha256': hashlib.sha256(open(oracle.so, 'rb').read()).hexdigest(),
        'c_source': 'inline (3-field non-zero check)',
        'seed': SEED,
        'n_cases': len(cases),
        'gates': {
            'identity': {'pass': not mismatches, 'mismatches': mismatches[:5]},
            'coverage': {'pass': all_combos, 'detail': f'{len(covered)}/8 combos'},
            'non_degenerate': {'pass': has_zero and has_one},
            'teeth': teeth,
        },
        'status': 'PASS' if all_pass else 'FAIL',
        'stubbed_imports': 'none (pure function)',
        'scope': 'pure 3-field boolean; 12 insns; no external calls',
        'timestamp': time.strftime('%Y%m%dT%H%M%S'),
    }

    RECEIPTS.mkdir(exist_ok=True)
    receipt_path = RECEIPTS / f'has_data_diff-{time.strftime("%Y%m%dT%H%M%S")}.json'
    receipt_path.write_text(json.dumps(receipt, ensure_ascii=False, indent=2) + '\n')

    print(f'HasData differential: {receipt["status"]}')
    print(f'  identity:    {"PASS" if not mismatches else f"FAIL ({len(mismatches)} mismatches)"}')
    print(f'  coverage:    {"PASS" if all_combos else "FAIL"} ({len(covered)}/8)')
    print(f'  non-degen:   {"PASS" if has_zero and has_one else "FAIL"}')
    print(f'  teeth:       {all(t["status"] == "PASS" for t in teeth)}')
    for t in teeth:
        print(f'    {t["mutant"]}: {t["status"]} (caught={t.get("caught", "?")})')
    print(f'  receipt: {receipt_path}')

    sys.exit(0 if all_pass else 1)


if __name__ == '__main__':
    main()
