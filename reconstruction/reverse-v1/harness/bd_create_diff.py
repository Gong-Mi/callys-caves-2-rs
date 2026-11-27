#!/usr/bin/env python3
"""spBoneData_create — L5 oracle arm #17.

32 insns @ 0x285a44: calloc(1,52,tag,36) + index store + MALLOC_STR(name)
+ parent store + defaults (scaleX/scaleY=1.0f, inheritRotation/Scale=1).

The _calloc/_malloc internal wrappers chain to PLT. The oracle hooks PLT.
Test: create with various (index, name, parent) and dump the 52B result.
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

SPBONEDATA_CREATE = 0x285a44
SEED = 0xB0DA

C_DRIVER = r'''
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

/* spBoneData: 52B layout (binary-observed) */
typedef struct {
    int32_t  index;           /* +0x00 */
    char*    name;            /* +0x04 */
    void*    parent;          /* +0x08 */
    float    length;          /* +0x0c */
    float    x, y;            /* +0x10, +0x14 */
    float    rotation;        /* +0x18 */
    float    scaleX, scaleY;  /* +0x1c, +0x20 */
    float    shearX, shearY;  /* +0x24, +0x28 */
    int32_t  inheritRotation; /* +0x2c */
    int32_t  inheritScale;    /* +0x30 */
} spBoneData;

static spBoneData* bd_create(int index, const char* name, void* parent) {
    spBoneData* bd = calloc(1, sizeof(spBoneData));
    if (!bd) return NULL;
    bd->index = index;
    bd->name = strdup(name);
    bd->parent = parent;
    /* defaults from create's tail (0x285a9c-0x285aa4):
     * scaleX/scaleY = 1.0f, inheritRotation/inheritScale = 1 */
    bd->scaleX = 1.0f;
    bd->scaleY = 1.0f;
    bd->inheritRotation = 1;
    bd->inheritScale = 1;
    return bd;
}

int main(void) {
    char line[256];
    while (fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\n")] = 0;
        if (strcmp(line, "END") == 0) break;
        int index; char name[64]; uint32_t parent;
        sscanf(line, "%d %63s %u", &index, name, &parent);
        spBoneData* bd = bd_create(index, name, (void*)(uintptr_t)parent);
        if (!bd) { printf("NULL\n"); continue; }
        /* dump raw bits via field addresses (host-arch independent) */
        uint32_t sx = *(uint32_t*)(void*)&bd->scaleX;
        uint32_t sy = *(uint32_t*)(void*)&bd->scaleY;
        printf("%d %s %u %08x %08x %d %d\n",
               bd->index, bd->name, (uint32_t)(uintptr_t)bd->parent,
               sx, sy, bd->inheritRotation, bd->inheritScale);
        free(bd->name); free(bd);
    }
    return 0;
}
'''


def main():
    BUILD.mkdir(exist_ok=True)
    src = BUILD / 'bd_create_driver.c'
    src.write_text(C_DRIVER)
    exe = BUILD / 'bd_create_driver'
    r = subprocess.run(['clang', '-std=c11', '-O0', '-g', str(src), '-o', str(exe)],
                       capture_output=True, text=True, timeout=60)
    if r.returncode != 0:
        print(f'C driver build failed: {r.stderr}')
        sys.exit(1)

    cases = [
        (0, 'root', 0),
        (1, 'child', 0x2000),
        (42, 'long_name_with_underscores', 0x3000),
        (0x7FFFFFFF, 'max_index', 0),
        (0, 'a', 0xFFFFFFFF),
        (5, 'bone5', 0x1234),
        (2, 'with-dash', 0x5678),
    ]

    # === Arm A: original in Unicorn ===
    oracle = Oracle(libc=True, guard_plt=True)
    # Wire the GameMaker allocator GOT slots so internal _malloc/_free
    # wrappers call through to the hooked PLT entries:
    #   0x3f7790 = malloc slot, 0x3f7794 = free slot
    #   0x756bc4 = malloc override (BSS, zero → fallback path)
    oracle.write(0x3f7790, struct.pack('<I', 0xb6544))  # malloc@plt
    oracle.write(0x3f7794, struct.pack('<I', 0xb655c))  # free@plt
    a_results = []
    for index, name, parent in cases:
        # name string in guest memory
        name_bytes = name.encode() + b'\x00'
        name_addr = oracle.alloc(len(name_bytes), align=4)
        oracle.write(name_addr, name_bytes)
        try:
            ret = oracle.call(SPBONEDATA_CREATE, r0=index, r1=name_addr, r2=parent)
            # ret = pointer to 52B spBoneData in guest memory
            if ret and ret > 0x1000:
                raw = oracle.read(ret, 52)
                vals = struct.unpack('<13I', raw)
                # name pointer: follow and read string
                name_ptr = vals[1]
                got_name = b''
                if name_ptr and name_ptr > 0x1000:
                    got_name = oracle.read(name_ptr, 64).split(b'\x00')[0]
                a_results.append({
                    'index': vals[0], 'name': got_name.decode('utf-8', 'replace'),
                    'parent': vals[2],
                    'scaleX_raw': vals[7], 'scaleY_raw': vals[8],
                    'inheritRot': vals[11], 'inheritScale': vals[12],
                })
            else:
                a_results.append({'error': f'return {ret:#x}'})
        except Exception as e:
            a_results.append({'error': str(e)[:80]})

    # === Arm B: C ===
    c_input = '\n'.join(f'{i} {n} {p}' for i, n, p in cases) + '\nEND\n'
    cr = subprocess.run([str(exe)], input=c_input, capture_output=True, text=True, timeout=30)
    if cr.returncode != 0:
        print(f'C driver failed: {cr.stderr}')
        sys.exit(1)
    c_lines = cr.stdout.strip().split('\n')
    c_results = []
    for line in c_lines:
        parts = line.split()
        if parts and parts[0] != 'NULL':
            c_results.append({
                'index': int(parts[0]), 'name': parts[1], 'parent': int(parts[2]),
                'scaleX_raw': int(parts[3], 16), 'scaleY_raw': int(parts[4], 16),
                'inheritRot': int(parts[5]), 'inheritScale': int(parts[6]),
            })

    # === Gates ===
    mismatches = []
    for i, ((idx, name, parent), a, c) in enumerate(zip(cases, a_results, c_results)):
        if 'error' in a:
            mismatches.append({'case': i, 'orig': a, 'c': c})
            continue
        for field in ('index', 'name', 'parent', 'scaleX_raw', 'scaleY_raw',
                      'inheritRot', 'inheritScale'):
            if a[field] != c[field]:
                mismatches.append({'case': i, 'field': field,
                                   'orig': a[field], 'c': c[field]})

    non_degenerate = (a_results[0]['scaleX_raw'] == 0x3f800000 if a_results and 'scaleX_raw' in a_results[0] else False)

    # TEETH: no defaults (scaleX = 0)
    m1 = C_DRIVER.replace('bd->scaleX = 1.0f;', '/* MUTANT1 */')
    m1_path = BUILD / 'bd_mut1.c'
    m1_path.write_text(m1)
    m1_exe = BUILD / 'bd_mut1'
    subprocess.run(['clang', '-std=c11', '-O0', str(m1_path), '-o', str(m1_exe)],
                   capture_output=True, timeout=60)
    m1_r = subprocess.run([str(m1_exe)], input=c_input, capture_output=True, text=True, timeout=30)
    m1_lines = m1_r.stdout.strip().split('\n')
    m1_caught = any(l.split()[3] == '00000000' for l in m1_lines if l and l != 'NULL')

    # TEETH: index not stored
    m2 = C_DRIVER.replace('bd->index = index;', '/* MUTANT2 */')
    m2_path = BUILD / 'bd_mut2.c'
    m2_path.write_text(m2)
    m2_exe = BUILD / 'bd_mut2'
    subprocess.run(['clang', '-std=c11', '-O0', str(m2_path), '-o', str(m2_exe)],
                   capture_output=True, timeout=60)
    m2_r = subprocess.run([str(m2_exe)], input=c_input, capture_output=True, text=True, timeout=30)
    m2_lines = m2_r.stdout.strip().split('\n')
    m2_caught = any(l.split()[0] == '0' for l in m2_lines if l and l != 'NULL')

    teeth = [
        {'mutant': 'no_scaleX_default', 'caught': m1_caught,
         'status': 'PASS' if m1_caught else 'FAIL'},
        {'mutant': 'no_index_store', 'caught': m2_caught,
         'status': 'PASS' if m2_caught else 'FAIL'},
    ]

    all_pass = (not mismatches and non_degenerate
                and all(t['status'] == 'PASS' for t in teeth))

    receipt = {
        'schema': 'cally-bonedata-create-diff/1',
        'function': 'spBoneData_create',
        'entry': hex(SPBONEDATA_CREATE),
        'original_sha256': hashlib.sha256(open(oracle.so, 'rb').read()).hexdigest(),
        'seed': SEED,
        'n_cases': len(cases),
        'gates': {
            'identity': {'pass': not mismatches, 'mismatches': mismatches[:5]},
            'non_degenerate': {'pass': non_degenerate,
                               'detail': 'scaleX default = 0x3f800000'},
            'teeth': teeth,
        },
        'status': 'PASS' if all_pass else 'FAIL',
        'scope': 'spBoneData_create: calloc 52B + MALLOC_STR(name) + defaults; 7 cases',
        'timestamp': time.strftime('%Y%m%dT%H%M%S'),
    }

    RECEIPTS.mkdir(exist_ok=True)
    receipt_path = RECEIPTS / f'bd_create_diff-{time.strftime("%Y%m%dT%H%M%S")}.json'
    receipt_path.write_text(json.dumps(receipt, ensure_ascii=False, indent=2) + '\n')

    print(f'spBoneData_create differential: {receipt["status"]}')
    print(f'  identity:     {"PASS" if not mismatches else f"FAIL ({len(mismatches)} mismatches)"}')
    print(f'  non-degen:   {"PASS" if non_degenerate else "FAIL"}')
    for t in teeth:
        print(f'    TEETH {t["mutant"]}: {t["status"]}')
    print(f'  receipt: {receipt_path}')

    sys.exit(0 if all_pass else 1)


if __name__ == '__main__':
    main()
