#!/usr/bin/env python3
"""Json_getFloat/getInt/getString — three-way differential (L5 oracle arms #9-11).

All three are 7-instruction wrappers: getItem then read +0x18/+0x14/+0x10.
Each returns the field value or a caller-provided default.

Tests both the found path (returns field) and the not-found path (returns default).
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

JSON_GET_FLOAT = 0x287444
JSON_GET_INT = 0x287460
JSON_GET_STRING = 0x287428
SEED = 0x47E3
N_NODES = 10

JSON_SIZE = 32
OFF_NEXT = 0x00
OFF_CHILD = 0x04
OFF_STRING = 0x10
OFF_INT = 0x14
OFF_FLOAT = 0x18
OFF_NAME = 0x1C

C_DRIVER = r'''
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "json_interface.h"

#define MAX_NODES 10

int main(void) {
    char line[256];
    Json nodes[MAX_NODES];
    char names[MAX_NODES][64];
    char str_vals[MAX_NODES][64];
    Json root = {0};

    for (int i = 0; i < MAX_NODES; i++) {
        snprintf(names[i], 64, "key_%d", i);
        snprintf(str_vals[i], 64, "val_%d", i);
        memset(&nodes[i], 0, sizeof(Json));
        nodes[i].name = names[i];
        nodes[i].int_value = i * 10;
        nodes[i].float_value = (float)(i * 0.5);
        nodes[i].string_value = str_vals[i];
        if (i > 0) nodes[i - 1].next = &nodes[i];
    }
    root.child = &nodes[0];
    Json empty_root = {0};

    while (fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\n")] = 0;
        if (strcmp(line, "END") == 0) break;
        char cmd[16], key[128];
        sscanf(line, "%15s %127s", cmd, key);
        if (strcmp(cmd, "F") == 0) {
            float r = Json_getFloat(&root, key, -99.0f);
            printf("%.4f\n", r);
        } else if (strcmp(cmd, "I") == 0) {
            int r = Json_getInt(&root, key, -99);
            printf("%d\n", r);
        } else if (strcmp(cmd, "S") == 0) {
            const char* r = Json_getString(&root, key, "DEFAULT");
            printf("%s\n", r);
        } else if (strcmp(cmd, "EF") == 0) {
            float r = Json_getFloat(&empty_root, key, -99.0f);
            printf("%.4f\n", r);
        } else if (strcmp(cmd, "EI") == 0) {
            int r = Json_getInt(&empty_root, key, -99);
            printf("%d\n", r);
        } else if (strcmp(cmd, "ES") == 0) {
            const char* r = Json_getString(&empty_root, key, "DEFAULT");
            printf("%s\n", r);
        }
    }
    return 0;
}
'''


def build_c_driver():
    BUILD.mkdir(exist_ok=True)
    src = BUILD / 'json_get3_driver.c'
    src.write_text(C_DRIVER)
    json_c = RV1 / 'c' / 'json_interface' / 'src' / 'json_interface.c'
    json_h_dir = RV1 / 'c' / 'json_interface' / 'src'
    exe = BUILD / 'json_get3_driver'
    cmd = ['clang', '-std=c11', '-O0', '-g',
           '-I', str(json_h_dir),
           str(src), str(json_c), '-o', str(exe)]
    r = subprocess.run(cmd, capture_output=True, text=True, timeout=60)
    if r.returncode != 0:
        raise RuntimeError(f'C driver build failed:\n{r.stderr}')
    return exe


def setup_guest(oracle, node_data):
    """node_data: list of (name, int_val, float_bits, str_addr)."""
    n = len(node_data)
    node_addrs = []
    for i, (name, int_val, float_bits, str_addr) in enumerate(node_data):
        # Name string
        blob = name.encode() + b'\0'
        na = oracle.alloc(len(blob), align=4)
        oracle.write(na, blob)

        # Node
        addr = oracle.alloc(JSON_SIZE, align=4)
        oracle.write(addr, b'\0' * JSON_SIZE)
        if i > 0:
            oracle.write(node_addrs[i-1] + OFF_NEXT, struct.pack('<I', addr))
        oracle.write(addr + OFF_INT, struct.pack('<I', int_val & 0xFFFFFFFF))
        oracle.write(addr + OFF_FLOAT, struct.pack('<I', float_bits))
        if str_addr:
            oracle.write(addr + OFF_STRING, struct.pack('<I', str_addr))
        oracle.write(addr + OFF_NAME, struct.pack('<I', na))
        node_addrs.append(addr)

    root = oracle.alloc(JSON_SIZE, align=4)
    oracle.write(root, b'\0' * JSON_SIZE)
    oracle.write(root + OFF_CHILD, struct.pack('<I', node_addrs[0]))
    return root, node_addrs


def run_oracle_arm(oracle, entry, root, q_addr, default):
    """Call one of the three get* functions and return the raw r0."""
    return oracle.call(entry, r0=root, r1=q_addr, r2=default)


def main():
    random.seed(SEED)

    # Build test data
    node_data = []
    for i in range(N_NODES):
        name = f'key_{i}'
        int_val = i * 10
        float_bits = struct.unpack('<I', struct.pack('<f', i * 0.5))[0]
        node_data.append((name, int_val, float_bits, 0))  # str_addr filled later

    oracle = Oracle(libc=True, guard_plt=True)

    # Write string values
    str_addrs = {}
    for i in range(N_NODES):
        sv = f'val_{i}'
        blob = sv.encode() + b'\0'
        sa = oracle.alloc(len(blob), align=4)
        oracle.write(sa, blob)
        str_addrs[i] = sa
        node_data[i] = (node_data[i][0], node_data[i][1], node_data[i][2], sa)

    root, node_addrs = setup_guest(oracle, node_data)

    # Build queries: (cmd, key) pairs
    commands = []
    for i in range(N_NODES):
        commands.append(('F', f'key_{i}'))
        commands.append(('I', f'key_{i}'))
        commands.append(('S', f'key_{i}'))
    # Not-found queries
    for _ in range(8):
        commands.append(('F', 'nonexistent'))
        commands.append(('I', 'nonexistent'))
        commands.append(('S', 'nonexistent'))
    # Empty root
    empty_root = oracle.alloc(JSON_SIZE, align=4)
    oracle.write(empty_root, b'\0' * JSON_SIZE)
    commands.extend([('EF', 'key_0'), ('EI', 'key_0'), ('ES', 'key_0')])

    exe = build_c_driver()

    # Run arm A (original) for all three functions
    a_results = {'F': [], 'I': [], 'S': []}
    DEFAULT_FLOAT = struct.unpack('<I', struct.pack('<f', -99.0))[0]
    DEFAULT_INT = 0xFFFFFF9D  # -99
    DEFAULT_STR_ADDR = 0

    for cmd, key in commands:
        blob = key.encode() + b'\0'
        qa = oracle.alloc(len(blob), align=4)
        oracle.write(qa, blob)

        if cmd in ('F', 'EF'):
            entry = JSON_GET_FLOAT
            default = DEFAULT_FLOAT
            r = oracle.call(entry, r0=(empty_root if cmd == 'EF' else root), r1=qa, r2=default)
            a_results['F'].append(r)
        elif cmd in ('I', 'EI'):
            entry = JSON_GET_INT
            default = DEFAULT_INT
            r = oracle.call(entry, r0=(empty_root if cmd == 'EI' else root), r1=qa, r2=default)
            a_results['I'].append(r)
        elif cmd in ('S', 'ES'):
            entry = JSON_GET_STRING
            # Write "DEFAULT" string to a known guest address
            if DEFAULT_STR_ADDR == 0:
                pass  # will allocate below
            commands_key = (cmd, key)

    # For string default, allocate a guest string
    default_str = b'DEFAULT\0'
    DEFAULT_STR_ADDR = oracle.alloc(len(default_str), align=4)
    oracle.write(DEFAULT_STR_ADDR, default_str)

    # Re-run string arm with proper default
    a_results['S'] = []
    for cmd, key in commands:
        if cmd not in ('S', 'ES'):
            continue
        blob = key.encode() + b'\0'
        qa = oracle.alloc(len(blob), align=4)
        oracle.write(qa, blob)
        root_to_use = empty_root if cmd == 'ES' else root
        r = oracle.call(JSON_GET_STRING, r0=root_to_use, r1=qa, r2=DEFAULT_STR_ADDR)
        a_results['S'].append(r)

    # Run arm B (C)
    c_input = '\n'.join(f'{cmd} {key}' for cmd, key in commands) + '\nEND\n'
    r = subprocess.run([str(exe)], input=c_input, capture_output=True, text=True, timeout=30)
    if r.returncode != 0:
        print(f'C driver failed: {r.stderr}')
        sys.exit(1)
    c_lines = r.stdout.strip().split('\n')

    # Compare: we need to align the results
    # The C driver outputs in order: F/I/S interleaved based on commands
    # Parse back into groups
    c_results = {'F': [], 'I': [], 'S': []}
    idx = 0
    for cmd, key in commands:
        if cmd in ('F', 'EF'):
            c_results['F'].append(c_lines[idx]); idx += 1
        elif cmd in ('I', 'EI'):
            c_results['I'].append(c_lines[idx]); idx += 1
        elif cmd in ('S', 'ES'):
            c_results['S'].append(c_lines[idx]); idx += 1

    # === Compare float ===
    f_queries = [(c, k) for c, k in commands if c in ('F', 'EF')]
    f_mismatches = []
    for i, ((cmd, key), a_raw) in enumerate(zip(f_queries, a_results['F'])):
        # Original returns raw float bits in r0
        a_float = struct.unpack('<f', struct.pack('<I', a_raw))[0]
        c_val = float(c_results['F'][i])
        if abs(a_float - c_val) > 0.0001:
            f_mismatches.append({'query': key, 'orig': a_float, 'c': c_val})

    # === Compare int ===
    i_queries = [(c, k) for c, k in commands if c in ('I', 'EI')]
    i_mismatches = []
    for i, ((cmd, key), a_raw) in enumerate(zip(i_queries, a_results['I'])):
        a_int = a_raw if a_raw < 2**31 else a_raw - 2**32
        c_val = int(c_results['I'][i])
        if a_int != c_val:
            i_mismatches.append({'query': key, 'orig': a_int, 'c': c_val})

    # === Compare string ===
    s_queries = [(c, k) for c, k in commands if c in ('S', 'ES')]
    s_mismatches = []
    for i, ((cmd, key), a_raw) in enumerate(zip(s_queries, a_results['S'])):
        if a_raw == DEFAULT_STR_ADDR:
            a_str = 'DEFAULT'
        elif a_raw == 0:
            a_str = 'NULL'
        else:
            a_str = oracle.read_cstr(a_raw)
        c_val = c_results['S'][i]
        if a_str != c_val:
            s_mismatches.append({'query': key, 'orig': a_str, 'c': c_val})

    # === TEETH: mutate getInt to read +0x18 (float offset) instead of +0x14 ===
    teeth = []
    json_c = RV1 / 'c' / 'json_interface' / 'src' / 'json_interface.c'
    orig_src = json_c.read_text()

    mutant_src = BUILD / 'json_getint_mutant.c'
    patched = orig_src.replace(
        'return item->int_value;',
        'return item->float_value; /* MUTANT: wrong offset */',
        1)
    mutant_src.write_text(patched)
    mutant_exe = BUILD / 'json_getint_mutant'
    cmd = ['clang', '-std=c11', '-O0', '-g',
           '-I', str(RV1 / 'c' / 'json_interface' / 'src'),
           str(BUILD / 'json_get3_driver.c'), str(mutant_src),
           '-o', str(mutant_exe)]
    mr = subprocess.run(cmd, capture_output=True, text=True, timeout=60)
    if mr.returncode == 0:
        mi_input = '\n'.join(f'{c} {k}' for c, k in commands if c in ('I', 'EI')) + '\nEND\n'
        mr2 = subprocess.run([str(mutant_exe)], input=mi_input, capture_output=True, text=True, timeout=30)
        if mr2.returncode == 0:
            mi_lines = mr2.stdout.strip().split('\n')
            caught = 0
            for i, ((cmd, key), a_raw) in enumerate(zip(i_queries, a_results['I'])):
                a_int = a_raw if a_raw < 2**31 else a_raw - 2**32
                m_val = int(mi_lines[i])
                if a_int != m_val:
                    caught += 1
            teeth.append({'mutant': 'int_reads_float', 'caught': caught,
                          'status': 'PASS' if caught > 0 else 'FAIL'})
    else:
        teeth.append({'mutant': 'int_reads_float', 'status': 'BUILD_FAIL'})

    all_pass = (not f_mismatches and not i_mismatches and not s_mismatches
                and all(t['status'] == 'PASS' for t in teeth))

    receipt = {
        'schema': 'cally-json3-diff/1',
        'function': 'Json_getFloat/getInt/getString',
        'entries': [hex(JSON_GET_FLOAT), hex(JSON_GET_INT), hex(JSON_GET_STRING)],
        'original_sha256': hashlib.sha256(open(oracle.so, 'rb').read()).hexdigest(),
        'c_source': 'c/json_interface/src/json_interface.c',
        'c_source_sha256': hashlib.sha256(json_c.read_bytes()).hexdigest(),
        'seed': SEED,
        'n_nodes': N_NODES,
        'n_float_queries': len(f_queries),
        'n_int_queries': len(i_queries),
        'n_string_queries': len(s_queries),
        'gates': {
            'float_identity': {'pass': not f_mismatches, 'mismatches': f_mismatches[:5]},
            'int_identity': {'pass': not i_mismatches, 'mismatches': i_mismatches[:5]},
            'string_identity': {'pass': not s_mismatches, 'mismatches': s_mismatches[:5]},
            'teeth': teeth,
        },
        'status': 'PASS' if all_pass else 'FAIL',
        'stubbed_imports': 'strcasecmp (from libc hook)',
        'scope': 'three 7-insn wrappers; float +0x18, int +0x14, string +0x10; found and default paths',
        'timestamp': time.strftime('%Y%m%dT%H%M%S'),
    }

    RECEIPTS.mkdir(exist_ok=True)
    receipt_path = RECEIPTS / f'json_get3_diff-{time.strftime("%Y%m%dT%H%M%S")}.json'
    receipt_path.write_text(json.dumps(receipt, ensure_ascii=False, indent=2) + '\n')

    print(f'Json_getFloat/getInt/getString differential: {receipt["status"]}')
    print(f'  float identity:  {"PASS" if not f_mismatches else f"FAIL ({len(f_mismatches)})"}')
    print(f'  int identity:    {"PASS" if not i_mismatches else f"FAIL ({len(i_mismatches)})"}')
    print(f'  string identity: {"PASS" if not s_mismatches else f"FAIL ({len(s_mismatches)})"}')
    for t in teeth:
        print(f'    TEETH {t["mutant"]}: {t["status"]} (caught={t.get("caught", "?")})')
    print(f'  receipt: {receipt_path}')

    sys.exit(0 if all_pass else 1)


if __name__ == '__main__':
    main()
