#!/usr/bin/env python3
"""spIkConstraintData_create — L5 oracle arm #19.

26 insns @ 0x2866f0: calloc(1,24,tag,36) + MALLOC_STR(name) at +0x00 +
defaults bendDirection=1 (+0x10) and mix=1.0f (+0x14).
Uses GOT-wired allocator chain (0x3f7790/0x3f7794).
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

IKC_CREATE = 0x2866f0
SEED = 0x1

C_DRIVER = r'''
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
    char*    name;           /* +0x00 */
    int32_t  bonesCount;     /* +0x04 (set by caller loop) */
    void**   bones;          /* +0x08 (set by caller loop) */
    void*    target;         /* +0x0c (set by caller loop) */
    int32_t  bendDirection;  /* +0x10 (default 1) */
    float    mix;            /* +0x14 (default 1.0f) */
} spIkConstraintData;

static spIkConstraintData* ikc_create(const char* name) {
    spIkConstraintData* c = calloc(1, sizeof(spIkConstraintData));
    if (!c) return NULL;
    c->name = strdup(name);
    c->bonesCount = 0;
    c->bones = NULL;
    c->target = NULL;
    c->bendDirection = 1;
    c->mix = 1.0f;
    return c;
}

int main(void) {
    char line[256];
    while (fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\n")] = 0;
        if (strcmp(line, "END") == 0) break;
        char name[64];
        sscanf(line, "%63s", name);
        spIkConstraintData* c = ikc_create(name);
        if (!c) { printf("NULL\n"); continue; }
        uint32_t mix_bits = *(uint32_t*)(void*)&c->mix;
        printf("%s %d %d %08x\n", c->name, c->bonesCount,
               c->bendDirection, mix_bits);
        free(c->name); free(c);
    }
    return 0;
}
'''


def main():
    BUILD.mkdir(exist_ok=True)
    src = BUILD / 'ikc_create_driver.c'
    src.write_text(C_DRIVER)
    exe = BUILD / 'ikc_create_driver'
    r = subprocess.run(['clang', '-std=c11', '-O0', str(src), '-o', str(exe)],
                       capture_output=True, text=True, timeout=60)
    if r.returncode != 0:
        print(f'C driver build failed: {r.stderr}')
        sys.exit(1)

    cases = [
        'ik1', 'constraint_name', 'a',
        'long_ik_constraint_name_with_underscores',
        'x', 'bend', 'target_bone_42',
    ]

    # === Arm A: original in Unicorn ===
    oracle = Oracle(libc=True, guard_plt=True)
    oracle.write(0x3f7790, struct.pack('<I', 0xb6544))  # malloc GOT
    oracle.write(0x3f7794, struct.pack('<I', 0xb655c))  # free GOT
    a_results = []
    for name in cases:
        nb = name.encode() + b'\x00'
        na = oracle.alloc(len(nb), align=4)
        oracle.write(na, nb)
        try:
            ret = oracle.call(IKC_CREATE, r0=na)
            if ret and ret > 0x1000:
                raw = oracle.read(ret, 24)
                vals = struct.unpack('<6I', raw)
                name_ptr = vals[0]
                got_name = b''
                if name_ptr and name_ptr > 0x1000:
                    got_name = oracle.read(name_ptr, 64).split(b'\x00')[0]
                a_results.append({
                    'name': got_name.decode('utf-8', 'replace'),
                    'bonesCount': vals[1],
                    'bendDirection': vals[4],
                    'mix_raw': vals[5],
                })
            else:
                a_results.append({'error': f'ret {ret:#x}'})
        except Exception as e:
            a_results.append({'error': str(e)[:80]})

    # === Arm B: C ===
    c_input = '\n'.join(cases) + '\nEND\n'
    cr = subprocess.run([str(exe)], input=c_input, capture_output=True, text=True, timeout=30)
    if cr.returncode != 0:
        print(f'C driver failed: {cr.stderr}')
        sys.exit(1)
    c_results = []
    for line in cr.stdout.strip().split('\n'):
        parts = line.split()
        if parts and parts[0] != 'NULL':
            c_results.append({
                'name': parts[0],
                'bonesCount': int(parts[1]),
                'bendDirection': int(parts[2]),
                'mix_raw': int(parts[3], 16),
            })

    # === Gates ===
    mismatches = []
    for i, (name, a, c) in enumerate(zip(cases, a_results, c_results)):
        if 'error' in a:
            mismatches.append({'case': i, 'name': name, 'orig': a, 'c': c})
            continue
        for field in ('name', 'bonesCount', 'bendDirection', 'mix_raw'):
            if a[field] != c[field]:
                mismatches.append({'case': i, 'name': name, 'field': field,
                                   'orig': a[field], 'c': c[field]})

    non_degenerate = (a_results[0]['bendDirection'] == 1
                      and a_results[0]['mix_raw'] == 0x3f800000)

    # TEETH: no bendDirection default
    m1 = C_DRIVER.replace('c->bendDirection = 1;', '/* MUTANT1 */')
    m1_path = BUILD / 'ikc_mut1.c'
    m1_path.write_text(m1)
    m1_exe = BUILD / 'ikc_mut1'
    subprocess.run(['clang', '-std=c11', '-O0', str(m1_path), '-o', str(m1_exe)],
                   capture_output=True, timeout=60)
    m1_r = subprocess.run([str(m1_exe)], input=c_input, capture_output=True, text=True, timeout=30)
    m1_caught = any(l.split()[2] == '0' for l in m1_r.stdout.strip().split('\n')
                    if l and l != 'NULL')

    # TEETH: mix default 0 instead of 1.0
    m2 = C_DRIVER.replace('c->mix = 1.0f;', 'c->mix = 0.0f; /* MUTANT2 */')
    m2_path = BUILD / 'ikc_mut2.c'
    m2_path.write_text(m2)
    m2_exe = BUILD / 'ikc_mut2'
    subprocess.run(['clang', '-std=c11', '-O0', str(m2_path), '-o', str(m2_exe)],
                   capture_output=True, timeout=60)
    m2_r = subprocess.run([str(m2_exe)], input=c_input, capture_output=True, text=True, timeout=30)
    m2_caught = any(l.split()[3] == '00000000' for l in m2_r.stdout.strip().split('\n')
                    if l and l != 'NULL')

    teeth = [
        {'mutant': 'no_benddir_default', 'caught': m1_caught,
         'status': 'PASS' if m1_caught else 'FAIL'},
        {'mutant': 'mix_zero', 'caught': m2_caught,
         'status': 'PASS' if m2_caught else 'FAIL'},
    ]

    all_pass = (not mismatches and non_degenerate
                and all(t['status'] == 'PASS' for t in teeth))

    receipt = {
        'schema': 'cally-ikc-create-diff/1',
        'function': 'spIkConstraintData_create',
        'entry': hex(IKC_CREATE),
        'original_sha256': hashlib.sha256(open(oracle.so, 'rb').read()).hexdigest(),
        'seed': 0x1,
        'n_cases': len(cases),
        'gates': {
            'identity': {'pass': not mismatches, 'mismatches': mismatches[:5]},
            'non_degenerate': {'pass': non_degenerate,
                               'detail': 'bendDirection=1, mix=1.0f'},
            'teeth': teeth,
        },
        'status': 'PASS' if all_pass else 'FAIL',
        'spIkConstraintData_layout': {
            'size': 24,
            '+0x00': 'name', '+0x04': 'bonesCount', '+0x08': 'bones',
            '+0x0c': 'target', '+0x10': 'bendDirection (def 1)', '+0x14': 'mix (def 1.0f)'
        },
        'scope': 'calloc 24B + MALLOC_STR + 2 defaults; 7 cases; GOT-wired allocators',
        'timestamp': time.strftime('%Y%m%dT%H%M%S'),
    }

    RECEIPTS.mkdir(exist_ok=True)
    receipt_path = RECEIPTS / f'ikc_create_diff-{time.strftime("%Y%m%dT%H%M%S")}.json'
    receipt_path.write_text(json.dumps(receipt, ensure_ascii=False, indent=2) + '\n')

    print(f'spIkConstraintData_create differential: {receipt["status"]}')
    print(f'  identity:     {"PASS" if not mismatches else f"FAIL ({len(mismatches)} mismatches)"}')
    print(f'  non-degen:   {"PASS" if non_degenerate else "FAIL"}')
    for t in teeth:
        print(f'    TEETH {t["mutant"]}: {t["status"]}')
    print(f'  receipt: {receipt_path}')

    sys.exit(0 if all_pass else 1)


if __name__ == '__main__':
    main()
