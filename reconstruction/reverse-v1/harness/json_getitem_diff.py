#!/usr/bin/env python3
"""Json_getItem — original-binary differential (L5 oracle arm #8).

Walks a linked list of Json nodes matching by name.
This exercises the core JSON tree navigation that readSkeletonData calls 31 times.

Input: a chain of Json nodes (32B each) in guest memory.
Output: pointer to matching node, or NULL.

The C translation and the original both walk forward through the child
linked list starting at json->child (+0x04).

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

JSON_GET_ITEM = 0x2873c4
SEED = 0x37A5
N_NODES = 15
N_EXTRA_QUERIES = 15

# Json layout (32 B, from json_interface.h)
JSON_SIZE = 32
OFF_NEXT = 0x00
OFF_CHILD = 0x04
OFF_UNK_08 = 0x08
OFF_UNK_0C = 0x0C
OFF_STRING = 0x10
OFF_INT = 0x14
OFF_FLOAT = 0x18
OFF_NAME = 0x1C

C_DRIVER = r'''
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <strings.h>
#include "json_interface.h"

#define MAX_NODES 15

int main(void) {
    char line[256];
    Json nodes[MAX_NODES];
    char names[MAX_NODES][64];
    Json root = {0};

    for (int i = 0; i < MAX_NODES; i++) {
        snprintf(names[i], 64, "key_%d", i);
        memset(&nodes[i], 0, sizeof(Json));
        nodes[i].name = names[i];
        nodes[i].int_value = i * 100;
        if (i > 0) nodes[i - 1].next = &nodes[i];
    }
    root.child = &nodes[0];

    Json empty_root = {0};
    empty_root.child = NULL;

    while (fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\n")] = 0;
        if (strcmp(line, "END") == 0) break;
        if (strncmp(line, "EMPTY:", 6) == 0) {
            Json* r = Json_getItem(&empty_root, line + 6);
            printf("%d\n", r ? 100 : -1);
        } else {
            Json* r = Json_getItem(&root, line);
            if (r == NULL) printf("-1\n");
            else {
                int found = -1;
                for (int i = 0; i < MAX_NODES; i++) {
                    if (r == &nodes[i]) { found = i; break; }
                }
                printf("%d\n", found);
            }
        }
    }
    return 0;
}
'''


def build_c_driver():
    BUILD.mkdir(exist_ok=True)
    src = BUILD / 'json_getitem_driver.c'
    src.write_text(C_DRIVER)
    json_c = RV1 / 'c' / 'json_interface' / 'src' / 'json_interface.c'
    json_h_dir = RV1 / 'c' / 'json_interface' / 'src'
    exe = BUILD / 'json_getitem_driver'
    cmd = ['clang', '-std=c11', '-O0', '-g',
           '-I', str(json_h_dir),
           str(src), str(json_c), '-o', str(exe)]
    r = subprocess.run(cmd, capture_output=True, text=True, timeout=60)
    if r.returncode != 0:
        raise RuntimeError(f'C driver build failed:\n{r.stderr}')
    return exe


def build_mutant(n, orig_src):
    mutant_src = BUILD / f'json_getitem_mutant{n}.c'
    patched = orig_src
    if n == 1:
        # Skip the first child (miss key_0)
        patched = orig_src.replace(
            'Json* item = json->child;',
            'Json* item = json->child ? json->child->next : NULL; /* MUTANT1: skip first */',
            1)
    elif n == 2:
        # Never return a match (always NULL)
        patched = orig_src.replace(
            'if (strcasecmp(item_name, name) == 0) {\n                /* 0x287420 implicit: return r4 (item) */\n                return item;\n            }',
            '/* MUTANT2: never match */',
            1)
    elif n == 3:
        # Use wrong name offset: +0x10 (string_value) instead of +0x1C (name)
        patched = orig_src.replace(
            'const char* item_name = item->name;',
            'const char* item_name = item->string_value; /* MUTANT3: wrong field */',
            1)
    mutant_src.write_text(patched)
    return mutant_src


def setup_guest(oracle, node_names):
    """Build a linked list of Json nodes in guest memory."""
    n = len(node_names)

    # Allocate name strings
    name_addrs = []
    for name in node_names:
        blob = name.encode() + b'\0'
        addr = oracle.alloc(len(blob), align=4)
        oracle.write(addr, blob)
        name_addrs.append(addr)

    # Allocate Json nodes (32 B each)
    node_addrs = []
    for i in range(n):
        addr = oracle.alloc(JSON_SIZE, align=4)
        # Zero everything
        oracle.write(addr, b'\0' * JSON_SIZE)
        # +0x00: next (link to previous node)
        if i > 0:
            oracle.write(node_addrs[i-1] + OFF_NEXT, struct.pack('<I', addr))
        # +0x14: int value (i * 100)
        oracle.write(addr + OFF_INT, struct.pack('<I', i * 100))
        # +0x1C: name
        oracle.write(addr + OFF_NAME, struct.pack('<I', name_addrs[i]))
        node_addrs.append(addr)

    # Allocate root node (32 B, only child matters)
    root_addr = oracle.alloc(JSON_SIZE, align=4)
    oracle.write(root_addr, b'\0' * JSON_SIZE)
    # +0x04: child → first node
    oracle.write(root_addr + OFF_CHILD, struct.pack('<I', node_addrs[0]))

    return root_addr, node_addrs


def run_oracle(oracle, queries, node_names):
    root_addr, node_addrs = setup_guest(oracle, node_names)
    results = []
    for query in queries:
        blob = query.encode() + b'\0'
        q_addr = oracle.alloc(len(blob), align=4)
        oracle.write(q_addr, blob)
        ret = oracle.call(JSON_GET_ITEM, r0=root_addr, r1=q_addr)
        if ret == 0:
            results.append(-1)
        else:
            found = False
            for i, addr in enumerate(node_addrs):
                if ret == addr:
                    results.append(i)
                    found = True
                    break
            if not found:
                results.append(-2)
    return results


def run_c(exe, queries):
    input_text = '\n'.join(queries) + '\nEND\n'
    r = subprocess.run([str(exe)], input=input_text, capture_output=True, text=True, timeout=30)
    if r.returncode != 0:
        raise RuntimeError(f'C driver failed: rc={r.returncode}\n{r.stderr}')
    return [int(x) for x in r.stdout.strip().split('\n')]


def main():
    random.seed(SEED)
    node_names = [f'key_{i}' for i in range(N_NODES)]

    queries = list(node_names)
    queries.extend(['key_99', 'nonexistent', 'key', '', 'key_0_extra',
                    'KEY_0', 'key_00', 'x' * 30])
    # Case-insensitive test cases (strcasecmp, not strcmp!)
    queries.extend(['Key_0', 'KEY_1', 'kEy_2', 'key_3', 'KEY_14'])
    for _ in range(N_EXTRA_QUERIES):
        if random.random() < 0.5:
            queries.append(f'key_{random.randint(0, N_NODES - 1)}')
        else:
            queries.append(f'random_{random.randint(0, 999)}')

    exe = build_c_driver()

    oracle = Oracle(libc=True, guard_plt=True)
    a_results = run_oracle(oracle, queries, node_names)

    # Empty root (child = NULL)
    empty_queries = [f'EMPTY:{q}' for q in ['key_0', 'nonexistent', '']]
    oracle2 = Oracle(libc=True, guard_plt=True)
    empty_root = oracle2.alloc(JSON_SIZE, align=4)
    oracle2.write(empty_root, b'\0' * JSON_SIZE)
    # child = 0 (NULL)
    a_empty = []
    for eq in empty_queries:
        q = eq[6:]
        blob = q.encode() + b'\0'
        q_addr = oracle2.alloc(len(blob), align=4)
        oracle2.write(q_addr, blob)
        ret = oracle2.call(JSON_GET_ITEM, r0=empty_root, r1=q_addr)
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
    found_all = all(a_results[i] == i for i in range(N_NODES))

    # === Gate: non-degenerate ===
    has_null = any(a == -1 for a in a_all)

    # === Gate: TEETH ===
    teeth_results = []
    json_c = RV1 / 'c' / 'json_interface' / 'src' / 'json_interface.c'
    orig_src = json_c.read_text()

    for mutant_id in (1, 2, 3):
        mutant_src = build_mutant(mutant_id, orig_src)
        json_h_dir = RV1 / 'c' / 'json_interface' / 'src'
        driver_src = BUILD / 'json_getitem_driver.c'
        mutant_exe = BUILD / f'json_getitem_mutant{mutant_id}'
        cmd = ['clang', '-std=c11', '-O0', '-g',
               '-I', str(json_h_dir),
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
        'schema': 'cally-jsongetitem-diff/1',
        'function': 'Json_getItem',
        'entry': hex(JSON_GET_ITEM),
        'original_sha256': hashlib.sha256(open(oracle.so, 'rb').read()).hexdigest(),
        'c_source': 'c/json_interface/src/json_interface.c',
        'c_source_sha256': hashlib.sha256(json_c.read_bytes()).hexdigest(),
        'seed': SEED,
        'n_nodes': N_NODES,
        'n_queries': len(all_queries),
        'queries': all_queries,
        'arm_a': a_all,
        'arm_b': c_all,
        'gates': {
            'identity': {'pass': not mismatches, 'mismatches': mismatches[:5]},
            'coverage': {'pass': found_all, 'detail': 'all N nodes found by name'},
            'non_degenerate': {'pass': has_null, 'detail': 'at least one NULL return'},
            'teeth': teeth_results,
        },
        'status': 'PASS' if all_pass else 'FAIL',
        'stubbed_imports': 'strcmp (from libc hook)',
        'scope': 'pure leaf; linked list walk; name at +0x1C; 32B Json layout; NULL name edge case',
        'timestamp': time.strftime('%Y%m%dT%H%M%S'),
    }

    RECEIPTS.mkdir(exist_ok=True)
    receipt_path = RECEIPTS / f'json_getitem_diff-{time.strftime("%Y%m%dT%H%M%S")}.json'
    receipt_path.write_text(json.dumps(receipt, ensure_ascii=False, indent=2) + '\n')

    print(f'Json_getItem differential: {receipt["status"]}')
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
