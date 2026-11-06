#!/usr/bin/env python3
"""spSkeletonData_findSlotIndex — original-binary differential (L5 oracle arm #6).

Two arms, same inputs:
  arm A (judge)     libyoyo's findSlotIndex @0x28b0cc, executed in Unicorn
  arm B (claim)     reconstruction/reverse-v1/c/skeleton_find/src/skeleton_find.c

Input: spSkeletonData with N slots (name at +0x04), queried by name.
Output: slot index (int) or -1 for not-found.

Gates: identity, coverage, non-degenerate, TEETH.
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

FIND_SLOT_INDEX = 0x28b0cc
SEED = 0x5107
N_SLOTS = 10
N_EXTRA_QUERIES = 15

OFF_SLOT_COUNT = 0x18
OFF_SLOTS = 0x1c
SLOT_SIZE = 8

C_DRIVER = r'''
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "skeleton_find.h"

#define MAX_SLOTS 10
#define N_SLOTS 10

int main(void) {
    char line[256];
    spSkeletonData data = {0};
    spSlotData* slot_ptrs[MAX_SLOTS];
    spSlotData slots[MAX_SLOTS];
    char names[MAX_SLOTS][64];

    /* Empty skeleton for the EMPTY: prefixed queries */
    spSkeletonData empty_data = {0};
    empty_data.slot_count = 0;
    empty_data.slots = NULL;

    data.slot_count = N_SLOTS;
    data.slots = slot_ptrs;

    for (int i = 0; i < N_SLOTS; i++) {
        snprintf(names[i], 64, "slot_%d", i);
        slots[i].name = names[i];
        slot_ptrs[i] = &slots[i];
    }

    while (fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\n")] = 0;
        if (strcmp(line, "END") == 0) break;
        if (strncmp(line, "EMPTY:", 6) == 0) {
            /* Query against the empty skeleton */
            int idx = spSkeletonData_findSlotIndex(&empty_data, line + 6);
            printf("%d\n", idx);
        } else {
            int idx = spSkeletonData_findSlotIndex(&data, line);
            printf("%d\n", idx);
        }
    }
    return 0;
}
'''


def build_c_driver():
    BUILD.mkdir(exist_ok=True)
    src = BUILD / 'find_slot_driver.c'
    src.write_text(C_DRIVER)
    skel_c = RV1 / 'c' / 'skeleton_find' / 'src' / 'skeleton_find.c'
    skel_h_dir = RV1 / 'c' / 'skeleton_find' / 'src'
    exe = BUILD / 'find_slot_driver'
    cmd = ['clang', '-std=c11', '-O0', '-g',
           '-I', str(skel_h_dir),
           str(src), str(skel_c), '-o', str(exe)]
    r = subprocess.run(cmd, capture_output=True, text=True, timeout=60)
    if r.returncode != 0:
        raise RuntimeError(f'C driver build failed:\n{r.stderr}')
    return exe


def build_mutant(n, orig_src):
    mutant_src = BUILD / f'skeleton_find_slot_mutant{n}.c'
    patched = orig_src
    # Target only the findSlotIndex function
    if n == 1:
        # Off-by-one: search one fewer slot than present (misses the last)
        patched = orig_src.replace(
            'int count = self->slot_count;\n\n    /* 0x28b0d8',
            'int count = self->slot_count - 1; /* MUTANT1: off-by-one */\n\n    /* 0x28b0d8',
            1)
    elif n == 2:
        # Change return -1 to return -2 (breaks not-found)
        patched = orig_src.replace(
            '/* 0x28b11c mvn r0, #0 — return -1 */\n    return -1;\n}',
            '/* MUTANT2 */ return -2;\n}',
            1)
    elif n == 3:
        # Use bone_count instead of slot_count (wrong field)
        patched = orig_src.replace(
            'int count = self->slot_count;',
            'int count = self->bone_count; /* MUTANT3: wrong field */',
            1)
    mutant_src.write_text(patched)
    return mutant_src


def setup_guest(oracle, slot_names):
    n = len(slot_names)
    name_addrs = []
    for name in slot_names:
        blob = name.encode() + b'\0'
        addr = oracle.alloc(len(blob), align=4)
        oracle.write(addr, blob)
        name_addrs.append(addr)

    slot_addrs = []
    for i in range(n):
        addr = oracle.alloc(SLOT_SIZE, align=4)
        oracle.write(addr, struct.pack('<I', 0))
        oracle.write(addr + 4, struct.pack('<I', name_addrs[i]))
        slot_addrs.append(addr)

    arr_addr = oracle.alloc(n * 4, align=4)
    for i in range(n):
        oracle.write(arr_addr + i * 4, struct.pack('<I', slot_addrs[i]))

    data_addr = oracle.alloc(0x20, align=4)
    oracle.write(data_addr, b'\0' * 0x20)
    oracle.write(data_addr + OFF_SLOT_COUNT, struct.pack('<I', n))
    oracle.write(data_addr + OFF_SLOTS, struct.pack('<I', arr_addr))
    return data_addr, slot_addrs


def run_oracle(oracle, queries, slot_names):
    data_addr, slot_addrs = setup_guest(oracle, slot_names)
    results = []
    for query in queries:
        blob = query.encode() + b'\0'
        q_addr = oracle.alloc(len(blob), align=4)
        oracle.write(q_addr, blob)
        ret = oracle.call(FIND_SLOT_INDEX, r0=data_addr, r1=q_addr)
        # findSlotIndex returns the index directly (int in r0)
        # -1 = 0xFFFFFFFF when not found
        if ret == 0xFFFFFFFF:
            results.append(-1)
        else:
            results.append(ret)
    return results


def run_c(exe, queries):
    input_text = '\n'.join(queries) + '\nEND\n'
    r = subprocess.run([str(exe)], input=input_text, capture_output=True, text=True, timeout=30)
    if r.returncode != 0:
        raise RuntimeError(f'C driver failed: rc={r.returncode}\n{r.stderr}')
    return [int(x) for x in r.stdout.strip().split('\n')]


def main():
    random.seed(SEED)
    slot_names = [f'slot_{i}' for i in range(N_SLOTS)]

    queries = list(slot_names)
    queries.extend(['slot_99', 'nonexistent', 'slot', '', 'slot_0_extra',
                    'SLOT_0', 'slot_00', 'x' * 50])
    for _ in range(N_EXTRA_QUERIES):
        if random.random() < 0.5:
            queries.append(f'slot_{random.randint(0, N_SLOTS - 1)}')
        else:
            queries.append(f'random_{random.randint(0, 999)}')

    exe = build_c_driver()

    oracle = Oracle(libc=True, guard_plt=True)
    a_results = run_oracle(oracle, queries, slot_names)

    # Empty skeleton (slot_count=0) — catches MUTANT1
    empty_queries = ['slot_0', 'nonexistent', '']
    oracle2 = Oracle(libc=True, guard_plt=True)
    empty_data = oracle2.alloc(0x20, align=4)
    oracle2.write(empty_data, b'\0' * 0x20)
    oracle2.write(empty_data + OFF_SLOT_COUNT, struct.pack('<I', 0))
    oracle2.write(empty_data + OFF_SLOTS, struct.pack('<I', 0))
    a_empty = []
    for q in empty_queries:
        blob = q.encode() + b'\0'
        q_addr = oracle2.alloc(len(blob), align=4)
        oracle2.write(q_addr, blob)
        ret = oracle2.call(FIND_SLOT_INDEX, r0=empty_data, r1=q_addr)
        a_empty.append(-1 if ret == 0xFFFFFFFF else ret)

    queries.extend(empty_queries)
    a_results.extend(a_empty)

    c_results = run_c(exe, queries[:len(queries) - len(empty_queries)])
    # C side for empty queries: run them through the EMPTY: prefix in the driver
    c_empty_input = '\n'.join(f'EMPTY:{q}' for q in empty_queries) + '\nEND\n'
    r = subprocess.run([str(exe)], input=c_empty_input, capture_output=True, text=True, timeout=30)
    if r.returncode != 0:
        raise RuntimeError(f'C empty driver failed: rc={r.returncode}\n{r.stderr}')
    c_results.extend(int(x) for x in r.stdout.strip().split('\n'))

    # === Gate: identity ===
    mismatches = []
    for i, (q, a, c) in enumerate(zip(queries, a_results, c_results)):
        if a != c:
            mismatches.append({'case': i, 'query': q, 'orig': a, 'c': c})

    # === Gate: coverage ===
    found_all = all(a_results[i] == i for i in range(N_SLOTS))

    # === Gate: non-degenerate ===
    has_not_found = any(a == -1 for a in a_results)

    # === Gate: TEETH ===
    teeth_results = []
    skel_c = RV1 / 'c' / 'skeleton_find' / 'src' / 'skeleton_find.c'
    orig_src = skel_c.read_text()

    for mutant_id in (1, 2, 3):
        mutant_src = build_mutant(mutant_id, orig_src)
        skel_h_dir = RV1 / 'c' / 'skeleton_find' / 'src'
        driver_src = BUILD / 'find_slot_driver.c'
        mutant_exe = BUILD / f'find_slot_mutant{mutant_id}'
        cmd = ['clang', '-std=c11', '-O0', '-g',
               '-I', str(skel_h_dir),
               str(driver_src), str(mutant_src), '-o', str(mutant_exe)]
        r = subprocess.run(cmd, capture_output=True, text=True, timeout=60)
        if r.returncode != 0:
            teeth_results.append({'mutant': mutant_id, 'status': 'BUILD_FAIL',
                                 'detail': r.stderr[:200]})
            continue

        m_results = run_c(mutant_exe, queries[:len(queries) - len(empty_queries)])
        # Run empty queries through the mutant too
        m_empty_input = '\n'.join(f'EMPTY:{q}' for q in empty_queries) + '\nEND\n'
        mr = subprocess.run([str(mutant_exe)], input=m_empty_input, capture_output=True, text=True, timeout=30)
        if mr.returncode == 0:
            m_results.extend(int(x) for x in mr.stdout.strip().split('\n'))
        else:
            m_results.extend([999] * len(empty_queries))  # signal build/run failure
        caught = sum(1 for a, m in zip(a_results, m_results) if a != m)
        teeth_results.append({'mutant': mutant_id, 'caught': caught,
                              'status': 'PASS' if caught > 0 else 'FAIL'})

    all_pass = (not mismatches and found_all and has_not_found
                and all(t['status'] == 'PASS' for t in teeth_results))

    receipt = {
        'schema': 'cally-findslotindex-diff/1',
        'function': 'spSkeletonData_findSlotIndex',
        'entry': hex(FIND_SLOT_INDEX),
        'original_sha256': hashlib.sha256(open(oracle.so, 'rb').read()).hexdigest(),
        'c_source': 'c/skeleton_find/src/skeleton_find.c',
        'c_source_sha256': hashlib.sha256(skel_c.read_bytes()).hexdigest(),
        'seed': SEED,
        'n_slots': N_SLOTS,
        'n_queries': len(queries),
        'queries': queries,
        'arm_a': a_results,
        'arm_b': c_results,
        'gates': {
            'identity': {'pass': not mismatches, 'mismatches': mismatches[:5]},
            'coverage': {'pass': found_all, 'detail': 'all N slots found by name'},
            'non_degenerate': {'pass': has_not_found, 'detail': 'at least one -1 return'},
            'teeth': teeth_results,
        },
        'status': 'PASS' if all_pass else 'FAIL',
        'stubbed_imports': 'strcmp (from libc hook)',
        'scope': 'pure leaf; unique names; returns int index not pointer; -1 for not-found',
        'timestamp': time.strftime('%Y%m%dT%H%M%S'),
    }

    RECEIPTS.mkdir(exist_ok=True)
    receipt_path = RECEIPTS / f'find_slot_diff-{time.strftime("%Y%m%dT%H%M%S")}.json'
    receipt_path.write_text(json.dumps(receipt, ensure_ascii=False, indent=2) + '\n')

    print(f'findSlotIndex differential: {receipt["status"]}')
    print(f'  identity:    {"PASS" if not mismatches else f"FAIL ({len(mismatches)} mismatches)"}')
    print(f'  coverage:    {"PASS" if found_all else "FAIL"}')
    print(f'  non-degen:   {"PASS" if has_not_found else "FAIL"}')
    print(f'  teeth:       {all(t["status"] == "PASS" for t in teeth_results)}')
    for t in teeth_results:
        print(f'    MUTANT{t["mutant"]}: {t["status"]} (caught={t.get("caught", "?")})')
    print(f'  receipt: {receipt_path}')

    sys.exit(0 if all_pass else 1)


if __name__ == '__main__':
    main()
