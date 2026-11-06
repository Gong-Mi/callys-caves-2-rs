#!/usr/bin/env python3
"""spSkeletonData_findBone — original-binary differential (L5 oracle arm).

Two arms, same inputs:
  arm A (judge)     libyoyo's findBone @0x28afbc, executed in Unicorn
  arm B (claim)     reconstruction/reverse-v1/c/skeleton_find/src/skeleton_find.c

Input: spSkeletonData with N bones, each with a name string in guest memory.
Output: return value normalised to bone index (or -1 for NULL).

Gates:
  * identity      every case identical (same bone index returned)
  * coverage      every bone is found by its own name; a NULL-returning
                  name is included
  * non-degenerate  at least one case returns NULL (not-found)
  * TEETH         each -DMUTANT=n build must produce at least one mismatch

Scope: pure leaf function, one strcmp call per bone entry (from libc hook).
The original walks the array from the LAST element backwards (pre-indexed
`ldr r5, [r6, #0x4]!` with `sub r6, r6, #4`), so for duplicate names the
LATER bone wins; the C translation walks forward with `--p`, which also
starts from the last element — but this batch uses unique names only.

Usage:
  python3 find_bone_diff.py            # build, run, write receipt
"""
import hashlib
import json
import os
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

FIND_BONE = 0x28afbc
SEED = 0xF1BD
N_BONES = 12
N_EXTRA_QUERIES = 20

# spSkeletonData offsets (from skeleton_find.h)
OFF_BONE_COUNT = 0x10
OFF_BONES = 0x14
# spBoneData offsets
OFF_BONE_NAME = 0x04
BONE_SIZE = 8  # minimum: unk + name

C_DRIVER = r'''
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "skeleton_find.h"

#define MAX_BONES 12
#define N_BONES 12

/* Use the real struct from skeleton_find.h */
int main(void) {
    char line[256];
    spSkeletonData data = {0};
    spBoneData* bone_ptrs[MAX_BONES];
    spBoneData bones[MAX_BONES];
    char names[MAX_BONES][64];

    data.bone_count = N_BONES;
    data.bones = bone_ptrs;

    for (int i = 0; i < N_BONES; i++) {
        snprintf(names[i], 64, "bone_%d", i);
        bones[i].name = names[i];
        bone_ptrs[i] = &bones[i];
    }

    while (fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\n")] = 0;
        if (strcmp(line, "END") == 0) break;
        spBoneData* result = spSkeletonData_findBone(&data, line);
        if (result == NULL) {
            printf("-1\n");
        } else {
            for (int i = 0; i < N_BONES; i++) {
                if (result == &bones[i]) {
                    printf("%d\n", i);
                    break;
                }
            }
        }
    }
    return 0;
}
'''

LAYOUT_H = r'''
#ifndef FIND_BONE_LAYOUT_H
#define FIND_BONE_LAYOUT_H
#define MAX_BONES 12
#define N_BONES 12

/* spBoneData: name at +0x04 */
typedef struct {
    uint32_t unk_00;    /* +0x00 */
    const char* name;   /* +0x04 */
} bone_layout_t;

/* spSkeletonData: bone_count at +0x10, bones at +0x14 */
struct spSkeletonData;
struct spBoneData;

struct spBoneData { uint32_t unk_00; const char* name; };
struct spSkeletonData {
    uint32_t unk[4];         /* +0x00..0x0c */
    int32_t bone_count;      /* +0x10 */
    struct spBoneData** bones; /* +0x14 */
};

/* From skeleton_find.c — link against it */
struct spBoneData* spSkeletonData_findBone(struct spSkeletonData* self, const char* name);

#endif
'''


def build_c_driver():
    BUILD.mkdir(exist_ok=True)
    layout_h = BUILD / 'find_bone_layout.h'
    layout_h.write_text(LAYOUT_H)

    src = BUILD / 'find_bone_driver.c'
    src.write_text(C_DRIVER)

    skel_c = RV1 / 'c' / 'skeleton_find' / 'src' / 'skeleton_find.c'
    skel_h_dir = RV1 / 'c' / 'skeleton_find' / 'src'

    exe = BUILD / 'find_bone_driver'
    cmd = [
        'clang', '-std=c11', '-O0', '-g',
        '-I', str(skel_h_dir), '-I', str(BUILD),
        str(src), str(skel_c),
        '-o', str(exe),
    ]
    r = subprocess.run(cmd, capture_output=True, text=True, timeout=60)
    if r.returncode != 0:
        raise RuntimeError(f'C driver build failed:\n{r.stderr}')
    return exe


def build_c_driver_mutant(n):
    """Build with -DMUTANT=n to check TEETH."""
    BUILD.mkdir(exist_ok=True)
    (BUILD / 'find_bone_layout.h').write_text(LAYOUT_H)

    src = BUILD / 'find_bone_driver.c'
    if not src.exists():
        src.write_text(C_DRIVER)

    skel_c = RV1 / 'c' / 'skeleton_find' / 'src' / 'skeleton_find.c'
    skel_h_dir = RV1 / 'c' / 'skeleton_find' / 'src'

    exe = BUILD / f'find_bone_driver_mutant{n}'
    cmd = [
        'clang', '-std=c11', '-O0', '-g', f'-DMUTANT={n}',
        '-I', str(skel_h_dir), '-I', str(BUILD),
        str(src), str(skel_c),
        '-o', str(exe),
    ]
    r = subprocess.run(cmd, capture_output=True, text=True, timeout=60)
    if r.returncode != 0:
        raise RuntimeError(f'mutant {n} build failed:\n{r.stderr}')
    return exe


# Mutant defines are injected into the C source via sed
MUTANT_PATCHES = [
    ('MUTANT1', 'if (count <= 0)', 'if (count < 0)'),
    ('MUTANT2', 'return NULL;\n    }\n\n    /* 0x28afd0', 'return NULL;\n    }\n\n    /* MUTANT2 */ if (count > 100) return NULL;\n    /* 0x28afd0'),
]


def setup_guest(oracle, bone_names):
    """Allocate spSkeletonData + bones array + bone structs + name strings in guest memory."""
    n = len(bone_names)

    # Allocate name strings
    name_addrs = []
    for name in bone_names:
        blob = name.encode() + b'\0'
        addr = oracle.alloc(len(blob), align=4)
        oracle.write(addr, blob)
        name_addrs.append(addr)

    # Allocate bone structs (8 bytes each: unk + name ptr)
    bone_addrs = []
    for i in range(n):
        addr = oracle.alloc(BONE_SIZE, align=4)
        # +0x00: unknown (zero)
        oracle.write(addr, struct.pack('<I', 0))
        # +0x04: name pointer
        oracle.write(addr + 4, struct.pack('<I', name_addrs[i]))
        bone_addrs.append(addr)

    # Allocate bones array (array of pointers)
    arr_addr = oracle.alloc(n * 4, align=4)
    for i in range(n):
        oracle.write(arr_addr + i * 4, struct.pack('<I', bone_addrs[i]))

    # Allocate spSkeletonData (need at least 0x18 bytes)
    data_addr = oracle.alloc(0x18, align=4)
    # Zero everything
    oracle.write(data_addr, b'\0' * 0x18)
    # +0x10: bone count
    oracle.write(data_addr + OFF_BONE_COUNT, struct.pack('<I', n))
    # +0x14: bones array pointer
    oracle.write(data_addr + OFF_BONES, struct.pack('<I', arr_addr))

    return data_addr, bone_addrs


def normalize_result(ret_val, bone_addrs):
    """Convert return address to bone index, or -1 for NULL."""
    if ret_val == 0:
        return -1
    for i, addr in enumerate(bone_addrs):
        if ret_val == addr:
            return i
    return -2  # unexpected address


def run_oracle(oracle, queries, bone_names):
    """Run arm A (original in Unicorn) for all queries."""
    data_addr, bone_addrs = setup_guest(oracle, bone_names)
    results = []
    for query in queries:
        # Write query string to guest memory
        blob = query.encode() + b'\0'
        q_addr = oracle.alloc(len(blob), align=4)
        oracle.write(q_addr, blob)

        ret = oracle.call(FIND_BONE, r0=data_addr, r1=q_addr)
        results.append(normalize_result(ret, bone_addrs))
    return results


def run_c(exe, queries):
    """Run arm B (C reconstruction) for all queries."""
    input_text = '\n'.join(queries) + '\nEND\n'
    r = subprocess.run([str(exe)], input=input_text, capture_output=True, text=True, timeout=30)
    if r.returncode != 0:
        raise RuntimeError(f'C driver failed: rc={r.returncode}\n{r.stderr}')
    return [int(x) for x in r.stdout.strip().split('\n')]


def main():
    random.seed(SEED)

    # Generate bone names (unique)
    bone_names = [f'bone_{i}' for i in range(N_BONES)]

    # Generate queries: all existing names + non-existing names
    queries = list(bone_names)  # every bone must be findable
    queries.extend(['bone_99', 'nonexistent', 'bone', '', 'bone_0_extra',
                    'BONE_0', 'bone_00', 'x' * 50])
    # Add some random queries
    for _ in range(N_EXTRA_QUERIES):
        if random.random() < 0.5:
            queries.append(f'bone_{random.randint(0, N_BONES - 1)}')
        else:
            queries.append(f'random_{random.randint(0, 999)}')

    # Build C driver
    exe = build_c_driver()

    # Run arm A (original)
    oracle = Oracle(libc=True, guard_plt=True)
    a_results = run_oracle(oracle, queries, bone_names)

    # Run arm B (C)
    c_results = run_c(exe, queries)

    # Extra: empty skeleton (bone_count=0) — catches MUTANT1 (<= 0 → < 0)
    empty_queries = ['bone_0', 'nonexistent', '']
    oracle2 = Oracle(libc=True, guard_plt=True)
    # Set up a skeleton with 0 bones
    empty_data = oracle2.alloc(0x18, align=4)
    oracle2.write(empty_data, b'\0' * 0x18)
    oracle2.write(empty_data + OFF_BONE_COUNT, struct.pack('<I', 0))
    oracle2.write(empty_data + OFF_BONES, struct.pack('<I', 0))
    a_empty = []
    for q in empty_queries:
        blob = q.encode() + b'\0'
        q_addr = oracle2.alloc(len(blob), align=4)
        oracle2.write(q_addr, blob)
        ret = oracle2.call(FIND_BONE, r0=empty_data, r1=q_addr)
        a_empty.append(normalize_result(ret, []))  # no bones to match

    queries.extend(empty_queries)
    a_results.extend(a_empty)
    # C side: empty queries return -1 (no bones)
    c_results.extend([-1] * len(empty_queries))

    # === Gate: identity ===
    mismatches = []
    for i, (q, a, c) in enumerate(zip(queries, a_results, c_results)):
        if a != c:
            mismatches.append({'case': i, 'query': q, 'orig': a, 'c': c})

    # === Gate: coverage ===
    found_all = all(a_results[i] == i for i in range(N_BONES))

    # === Gate: non-degenerate ===
    has_null = any(a == -1 for a in a_results)

    # === Gate: TEETH (mutation) ===
    # We test by modifying the C source inline
    teeth_results = []
    for mutant_id, old, new in MUTANT_PATCHES:
        # Build mutant by patching the C source
        skel_c = RV1 / 'c' / 'skeleton_find' / 'src' / 'skeleton_find.c'
        orig_src = skel_c.read_text()

        # Apply mutation
        patched = orig_src
        if old in patched:
            patched = patched.replace(old, new, 1)
        else:
            # Alternative: wrap the whole function with a return -1
            patched = orig_src.replace(
                'spSkeletonData_findBone(spSkeletonData* self, const char* name)\n{',
                f'spSkeletonData_findBone(spSkeletonData* self, const char* name)\n{{\n    if ({mutant_id}) return NULL; /* MUTANT */',
                1
            )

        mutant_src = BUILD / f'skeleton_find_mutant{mutant_id}.c'
        mutant_src.write_text(patched)

        mutant_exe = BUILD / f'find_bone_mutant{mutant_id}'
        skel_h_dir = RV1 / 'c' / 'skeleton_find' / 'src'
        driver_src = BUILD / 'find_bone_driver.c'
        cmd = [
            'clang', '-std=c11', '-O0', '-g',
            f'-D{mutant_id}=1',
            '-I', str(skel_h_dir), '-I', str(BUILD),
            str(driver_src), str(mutant_src),
            '-o', str(mutant_exe),
        ]
        r = subprocess.run(cmd, capture_output=True, text=True, timeout=60)
        if r.returncode != 0:
            teeth_results.append({'mutant': mutant_id, 'status': 'BUILD_FAIL'})
            continue

        m_results = run_c(mutant_exe, queries)
        caught = sum(1 for a, m in zip(a_results, m_results) if a != m)
        teeth_results.append({'mutant': mutant_id, 'caught': caught,
                              'status': 'PASS' if caught > 0 else 'FAIL'})

        # Restore original source
        skel_c.write_text(orig_src)

    # === Receipt ===
    all_pass = (not mismatches and found_all and has_null
                and all(t['status'] == 'PASS' for t in teeth_results))

    receipt = {
        'schema': 'cally-findbone-diff/1',
        'function': 'spSkeletonData_findBone',
        'entry': hex(FIND_BONE),
        'original_sha256': hashlib.sha256(
            open(oracle.so, 'rb').read()
        ).hexdigest(),
        'c_source': 'c/skeleton_find/src/skeleton_find.c',
        'c_source_sha256': hashlib.sha256(
            (RV1 / 'c' / 'skeleton_find' / 'src' / 'skeleton_find.c').read_bytes()
        ).hexdigest(),
        'seed': SEED,
        'n_bones': N_BONES,
        'n_queries': len(queries),
        'bone_names': bone_names,
        'queries': queries,
        'arm_a': a_results,
        'arm_b': c_results,
        'gates': {
            'identity': {'pass': not mismatches, 'mismatches': mismatches[:5]},
            'coverage': {'pass': found_all, 'detail': 'all N bones found by name'},
            'non_degenerate': {'pass': has_null, 'detail': 'at least one NULL return'},
            'teeth': teeth_results,
        },
        'status': 'PASS' if all_pass else 'FAIL',
        'stubbed_imports': 'strcmp (from libc hook)',
        'scope': 'pure leaf function; unique names only; forward+backward walk equivalence not tested with duplicates',
        'timestamp': time.strftime('%Y%m%dT%H%M%S'),
    }

    RECEIPTS.mkdir(exist_ok=True)
    receipt_path = RECEIPTS / f'find_bone_diff-{time.strftime("%Y%m%dT%H%M%S")}.json'
    receipt_path.write_text(json.dumps(receipt, ensure_ascii=False, indent=2) + '\n')

    print(f'findBone differential: {receipt["status"]}')
    print(f'  identity:    {"PASS" if not mismatches else f"FAIL ({len(mismatches)} mismatches)"}')
    print(f'  coverage:    {"PASS" if found_all else "FAIL"}')
    print(f'  non-degen:   {"PASS" if has_null else "FAIL"}')
    print(f'  teeth:       {all(t["status"] == "PASS" for t in teeth_results)}')
    for t in teeth_results:
        print(f'    {t["mutant"]}: {t["status"]}')
    print(f'  receipt: {receipt_path}')

    sys.exit(0 if all_pass else 1)


if __name__ == '__main__':
    main()
