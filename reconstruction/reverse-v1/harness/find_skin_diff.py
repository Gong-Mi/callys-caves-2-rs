#!/usr/bin/env python3
"""spSkeletonData_findSkin — original-binary differential (L5 oracle arm #7).

Same pattern as findBone/findSlotIndex but:
  - searches skins (+0x20/+0x24) not bones/slots
  - name field is at +0x00 (not +0x04)
  - returns skin* or NULL

Gates: identity, coverage, non-degenerate, TEETH.
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

FIND_SKIN = 0x28b124
SEED = 0x5C1D
N_SKINS = 8
N_EXTRA_QUERIES = 12

OFF_SKIN_COUNT = 0x20
OFF_SKINS = 0x24
SKIN_SIZE = 4  # name at +0x00 only (minimum)

C_DRIVER = r'''
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "skeleton_find.h"

#define MAX_SKINS 8
#define N_SKINS 8

int main(void) {
    char line[256];
    spSkeletonData data = {0};
    spSkin* skin_ptrs[MAX_SKINS];
    spSkin skins[MAX_SKINS];
    char names[MAX_SKINS][64];

    spSkin empty_skins[1];
    spSkin* empty_ptrs[1] = {&empty_skins[0]};
    spSkeletonData empty_data = {0};

    data.skin_count = N_SKINS;
    data.skins = skin_ptrs;

    for (int i = 0; i < N_SKINS; i++) {
        snprintf(names[i], 64, "skin_%d", i);
        skins[i].name = names[i];
        skin_ptrs[i] = &skins[i];
    }
    empty_data.skin_count = 0;
    empty_data.skins = NULL;

    while (fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\n")] = 0;
        if (strcmp(line, "END") == 0) break;
        if (strncmp(line, "EMPTY:", 6) == 0) {
            spSkin* r = spSkeletonData_findSkin(&empty_data, line + 6);
            printf("%d\n", r ? 100 : -1);
        } else {
            spSkin* r = spSkeletonData_findSkin(&data, line);
            if (r == NULL) printf("-1\n");
            else {
                for (int i = 0; i < N_SKINS; i++) {
                    if (r == &skins[i]) { printf("%d\n", i); break; }
                }
            }
        }
    }
    return 0;
}
'''


def build_c_driver():
    BUILD.mkdir(exist_ok=True)
    src = BUILD / 'find_skin_driver.c'
    src.write_text(C_DRIVER)
    skel_c = RV1 / 'c' / 'skeleton_find' / 'src' / 'skeleton_find.c'
    skel_h_dir = RV1 / 'c' / 'skeleton_find' / 'src'
    exe = BUILD / 'find_skin_driver'
    cmd = ['clang', '-std=c11', '-O0', '-g',
           '-I', str(skel_h_dir),
           str(src), str(skel_c), '-o', str(exe)]
    r = subprocess.run(cmd, capture_output=True, text=True, timeout=60)
    if r.returncode != 0:
        raise RuntimeError(f'C driver build failed:\n{r.stderr}')
    return exe


def build_mutant(n, orig_src):
    mutant_src = BUILD / f'skeleton_find_skin_mutant{n}.c'
    patched = orig_src
    if n == 1:
        # Off-by-one: miss the last skin
        patched = orig_src.replace(
            'int count = self->skin_count;\n\n    /* 0x28b130',
            'int count = self->skin_count - 1; /* MUTANT1 */\n\n    /* 0x28b130',
            1)
    elif n == 2:
        # Return non-NULL for not-found (return first skin instead)
        patched = orig_src.replace(
            '/* 0x28b174 mov r5, #0; 0x28b178 mov r0, r5 */\n    return NULL;\n}',
            '/* MUTANT2 */ return self->skins ? self->skins[0] : NULL;\n}',
            1)
    elif n == 3:
        # Use wrong name offset: +0x04 instead of +0x00
        patched = orig_src.replace(
            'if (strcmp(skin->name, name) == 0) {',
            'if (strcmp((char*)skin + 4, name) == 0) { /* MUTANT3: wrong offset */',
            1)
    mutant_src.write_text(patched)
    return mutant_src


def setup_guest(oracle, skin_names):
    n = len(skin_names)
    name_addrs = []
    for name in skin_names:
        blob = name.encode() + b'\0'
        addr = oracle.alloc(len(blob), align=4)
        oracle.write(addr, blob)
        name_addrs.append(addr)

    # spSkin: name at +0x00 (NOT +0x04)
    skin_addrs = []
    for i in range(n):
        addr = oracle.alloc(SKIN_SIZE, align=4)
        # +0x00: name pointer (only field)
        oracle.write(addr, struct.pack('<I', name_addrs[i]))
        skin_addrs.append(addr)

    arr_addr = oracle.alloc(n * 4, align=4)
    for i in range(n):
        oracle.write(arr_addr + i * 4, struct.pack('<I', skin_addrs[i]))

    data_addr = oracle.alloc(0x28, align=4)
    oracle.write(data_addr, b'\0' * 0x28)
    oracle.write(data_addr + OFF_SKIN_COUNT, struct.pack('<I', n))
    oracle.write(data_addr + OFF_SKINS, struct.pack('<I', arr_addr))
    return data_addr, skin_addrs


def run_oracle(oracle, queries, skin_names):
    data_addr, skin_addrs = setup_guest(oracle, skin_names)
    results = []
    for query in queries:
        blob = query.encode() + b'\0'
        q_addr = oracle.alloc(len(blob), align=4)
        oracle.write(q_addr, blob)
        ret = oracle.call(FIND_SKIN, r0=data_addr, r1=q_addr)
        # Normalize: pointer → index, NULL → -1
        if ret == 0:
            results.append(-1)
        else:
            found = False
            for i, addr in enumerate(skin_addrs):
                if ret == addr:
                    results.append(i)
                    found = True
                    break
            if not found:
                results.append(-2)  # unexpected
    return results


def run_c(exe, queries):
    input_text = '\n'.join(queries) + '\nEND\n'
    r = subprocess.run([str(exe)], input=input_text, capture_output=True, text=True, timeout=30)
    if r.returncode != 0:
        raise RuntimeError(f'C driver failed: rc={r.returncode}\n{r.stderr}')
    return [int(x) for x in r.stdout.strip().split('\n')]


def main():
    random.seed(SEED)
    skin_names = [f'skin_{i}' for i in range(N_SKINS)]

    queries = list(skin_names)
    queries.extend(['skin_99', 'nonexistent', 'skin', '', 'skin_0_extra',
                    'SKIN_0', 'skin_00', 'x' * 40])
    for _ in range(N_EXTRA_QUERIES):
        if random.random() < 0.5:
            queries.append(f'skin_{random.randint(0, N_SKINS - 1)}')
        else:
            queries.append(f'random_{random.randint(0, 999)}')

    exe = build_c_driver()

    oracle = Oracle(libc=True, guard_plt=True)
    a_results = run_oracle(oracle, queries, skin_names)

    # Empty skeleton
    empty_queries = [f'EMPTY:{q}' for q in ['skin_0', 'nonexistent', '']]
    oracle2 = Oracle(libc=True, guard_plt=True)
    empty_data = oracle2.alloc(0x28, align=4)
    oracle2.write(empty_data, b'\0' * 0x28)
    oracle2.write(empty_data + OFF_SKIN_COUNT, struct.pack('<I', 0))
    oracle2.write(empty_data + OFF_SKINS, struct.pack('<I', 0))
    a_empty = []
    for eq in empty_queries:
        q = eq[6:]  # strip EMPTY:
        blob = q.encode() + b'\0'
        q_addr = oracle2.alloc(len(blob), align=4)
        oracle2.write(q_addr, blob)
        ret = oracle2.call(FIND_SKIN, r0=empty_data, r1=q_addr)
        a_empty.append(-1 if ret == 0 else -2)

    all_queries = queries + empty_queries
    a_all = a_results + a_empty

    c_all = run_c(exe, all_queries)

    # === Gate: identity ===
    mismatches = []
    for i, (q, a, c) in enumerate(zip(all_queries, a_all, c_all)):
        if a != c:
            mismatches.append({'case': i, 'query': q, 'orig': a, 'c': c})

    # === Gate: coverage ===
    found_all = all(a_results[i] == i for i in range(N_SKINS))

    # === Gate: non-degenerate ===
    has_null = any(a == -1 for a in a_all)

    # === Gate: TEETH ===
    teeth_results = []
    skel_c = RV1 / 'c' / 'skeleton_find' / 'src' / 'skeleton_find.c'
    orig_src = skel_c.read_text()

    for mutant_id in (1, 2, 3):
        mutant_src = build_mutant(mutant_id, orig_src)
        skel_h_dir = RV1 / 'c' / 'skeleton_find' / 'src'
        driver_src = BUILD / 'find_skin_driver.c'
        mutant_exe = BUILD / f'find_skin_mutant{mutant_id}'
        cmd = ['clang', '-std=c11', '-O0', '-g',
               '-I', str(skel_h_dir),
               str(driver_src), str(mutant_src), '-o', str(mutant_exe)]
        r = subprocess.run(cmd, capture_output=True, text=True, timeout=60)
        if r.returncode != 0:
            teeth_results.append({'mutant': mutant_id, 'status': 'BUILD_FAIL',
                                 'detail': r.stderr[:200]})
            continue

        m_results = run_c(mutant_exe, all_queries)
        caught = sum(1 for a, m in zip(a_all, m_results) if a != m)
        teeth_results.append({'mutant': mutant_id, 'caught': caught,
                              'status': 'PASS' if caught > 0 else 'FAIL'})

    all_pass = (not mismatches and found_all and has_null
                and all(t['status'] == 'PASS' for t in teeth_results))

    receipt = {
        'schema': 'cally-findskin-diff/1',
        'function': 'spSkeletonData_findSkin',
        'entry': hex(FIND_SKIN),
        'original_sha256': hashlib.sha256(open(oracle.so, 'rb').read()).hexdigest(),
        'c_source': 'c/skeleton_find/src/skeleton_find.c',
        'c_source_sha256': hashlib.sha256(skel_c.read_bytes()).hexdigest(),
        'seed': SEED,
        'n_skins': N_SKINS,
        'n_queries': len(all_queries),
        'queries': all_queries,
        'arm_a': a_all,
        'arm_b': c_all,
        'gates': {
            'identity': {'pass': not mismatches, 'mismatches': mismatches[:5]},
            'coverage': {'pass': found_all, 'detail': 'all N skins found by name'},
            'non_degenerate': {'pass': has_null, 'detail': 'at least one NULL return'},
            'teeth': teeth_results,
        },
        'status': 'PASS' if all_pass else 'FAIL',
        'stubbed_imports': 'strcmp (from libc hook)',
        'scope': 'pure leaf; unique names; name at +0x00 (differs from bone +0x04 and slot +0x04); returns pointer',
        'timestamp': time.strftime('%Y%m%dT%H%M%S'),
    }

    RECEIPTS.mkdir(exist_ok=True)
    receipt_path = RECEIPTS / f'find_skin_diff-{time.strftime("%Y%m%dT%H%M%S")}.json'
    receipt_path.write_text(json.dumps(receipt, ensure_ascii=False, indent=2) + '\n')

    print(f'findSkin differential: {receipt["status"]}')
    print(f'  identity:    {"PASS" if not mismatches else f"FAIL ({len(mismatches)} mismatches)"}')
    print(f'  coverage:    {"PASS" if found_all else "FAIL"}')
    print(f'  non-degen:   {"PASS" if has_null else "FAIL"}')
    print(f'  teeth:       {all(t["status"] == "PASS" for t in teeth_results)}')
    for t in teeth_results:
        print(f'    MUTANT{t["mutant"]}: {t["status"]} (caught={t.get("caught", "?")})')
    print(f'  receipt: {receipt_path}')

    sys.exit(0 if all_pass else 1)


if __name__ == '__main__':
    main()
