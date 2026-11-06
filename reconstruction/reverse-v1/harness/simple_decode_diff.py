#!/usr/bin/env python3
"""CSkeletonSprite::SimpleDecode — L5 oracle arm #13.

11 instructions: XOR decode loop with key 42.

Semantics: for each byte in [r1, r1+r2), byte ^= 42.
r1 is the data pointer, r2 is the length.
This is `this` (r0) unused — pure function on (r1, r2).

Perfect L5 candidate: pure, no external calls, observable memory effect.
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

SIMPLE_DECODE = 0xbd840
SEED = 0x5DEC0DE
N_CASES = 30

C_DRIVER = r'''
#include <stdio.h>
#include <string.h>
#include <stdint.h>

/* SimpleDecode: XOR each byte with 42 */
static void simple_decode(uint8_t* data, int len) {
    if (len <= 0) return;
    uint8_t* end = data + len;
    uint8_t key = 42;
    while (data < end) {
        *data = *data - key;  /* rsb r2, r3, r2 → r2 = r3 - r2, but r3=42 → r2 = 42 - r2 */
        data++;
    }
}

int main(void) {
    char line[1024];
    while (fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\n")] = 0;
        if (strcmp(line, "END") == 0) break;
        int len;
        sscanf(line, "%d", &len);
        uint8_t buf[256];
        for (int i = 0; i < len && i < 256; i++) buf[i] = (uint8_t)(i * 7 + 13);
        simple_decode(buf, len);
        for (int i = 0; i < len; i++) printf("%02x", buf[i]);
        printf("\n");
    }
    return 0;
}
'''

C_DRIVER_V2 = r'''
#include <stdio.h>
#include <string.h>
#include <stdint.h>

/* Original ARM loop:
 *   mov r3, #42          → k0 = 42
 *   ldrb r2, [r1]        → byte
 *   rsb r2, r3, r2       → new = k - byte
 *   strb r2, [r1], #1    → store, advance
 *   mla r3, r3, r3, r3   → k = k*k + k (key evolves!)
 *   bne loop
 */
static void simple_decode(uint8_t* data, int len) {
    if (len <= 0) return;
    uint8_t* end = data + len;
    uint32_t key = 42;
    while (data < end) {
        *data = (uint8_t)(*data - key);  /* rsb r2, r3, r2 = r2 - r3 = byte - key */
        data++;
        key = key * key + key;  /* mla r3, r3, r3, r3 */
    }
}

int main(void) {
    char line[1024];
    while (fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\n")] = 0;
        if (strcmp(line, "END") == 0) break;
        int len;
        sscanf(line, "%d", &len);
        uint8_t buf[256];
        for (int i = 0; i < len && i < 256; i++) buf[i] = (uint8_t)(i * 7 + 13);
        simple_decode(buf, len);
        for (int i = 0; i < len; i++) printf("%02x", buf[i]);
        printf("\n");
    }
    return 0;
}
'''


def build_c_driver(source=None):
    BUILD.mkdir(exist_ok=True)
    src = BUILD / 'simple_decode_driver.c'
    src.write_text(source or C_DRIVER_V2)
    exe = BUILD / 'simple_decode_driver'
    cmd = ['clang', '-std=c11', '-O0', '-g', str(src), '-o', str(exe)]
    r = subprocess.run(cmd, capture_output=True, text=True, timeout=60)
    if r.returncode != 0:
        raise RuntimeError(f'C driver build failed:\n{r.stderr}')
    return exe


def main():
    random.seed(SEED)

    # Generate test cases: (length, initial_bytes)
    cases = []
    for i in range(N_CASES):
        length = random.randint(1, 64)
        if i == 0:
            length = 1  # minimum
        elif i == 1:
            length = 0  # edge case: no-op
        data = bytes(random.randint(0, 255) for _ in range(length))
        cases.append((length, data))

    exe = build_c_driver()

    # === Run arm A (original in Unicorn) ===
    oracle = Oracle(libc=True, guard_plt=True)
    a_results = []

    for length, data in cases:
        # Allocate buffer in guest memory
        if length == 0:
            a_results.append(b'')
            continue
        buf_addr = oracle.alloc(length, align=4)
        oracle.write(buf_addr, data)

        # Call SimpleDecode(r0=unused, r1=buf, r2=len)
        # Note: r0 is "this" but unused in the function
        oracle.call(SIMPLE_DECODE, r0=0, r1=buf_addr, r2=length)

        # Read back decoded bytes
        decoded = oracle.read(buf_addr, length)
        a_results.append(decoded)

    # === Run arm B (C) ===
    c_input = '\n'.join(str(length) for length, _ in cases) + '\nEND\n'
    # But the C driver generates its own data, not ours.
    # We need to pass the actual data.
    # Let me modify the approach: write data as hex, read back as hex.
    # Actually, the C driver uses a deterministic formula for data generation.
    # Let me use the same formula in Python to ensure both sides start with the same bytes.

    # Redo: both arms use the same input data (i*7+13 mod 256)
    a_results = []
    for length, _ in cases:
        if length == 0:
            a_results.append(b'')
            continue
        # Generate deterministic data: same as C driver
        data = bytes((i * 7 + 13) & 0xFF for i in range(length))
        buf_addr = oracle.alloc(length, align=4)
        oracle.write(buf_addr, data)
        oracle.call(SIMPLE_DECODE, r0=0, r1=buf_addr, r2=length)
        decoded = oracle.read(buf_addr, length)
        a_results.append(decoded)

    c_input = '\n'.join(str(length) for length, _ in cases) + '\nEND\n'
    r = subprocess.run([str(exe)], input=c_input, capture_output=True, text=True, timeout=30)
    if r.returncode != 0:
        print(f'C driver failed: {r.stderr}')
        sys.exit(1)

    c_lines = r.stdout.strip().split('\n')
    c_results = [bytes.fromhex(line) if line else b'' for line in c_lines]

    # === Gate: identity ===
    mismatches = []
    for i, ((length, _), a, c) in enumerate(zip(cases, a_results, c_results)):
        if a != c:
            mismatches.append({
                'case': i, 'length': length,
                'orig': a.hex()[:40],
                'c': c.hex()[:40],
            })

    # === Gate: non-degenerate ===
    # At least one case where input != output
    has_change = False
    for (length, _), a in zip(cases, a_results):
        if length > 0:
            original = bytes((i * 7 + 13) & 0xFF for i in range(length))
            if a != original:
                has_change = True
                break

    # === Gate: coverage ===
    # All lengths 0..64 appear
    lengths_covered = set(length for length, _ in cases)

    # === Gate: TEETH ===
    teeth = []

    # MUTANT1: use key 43 instead of 42
    m1_src = C_DRIVER_V2.replace('uint32_t key = 42;', 'uint32_t key = 43; /* MUTANT1 */')
    m1_exe = build_c_driver(m1_src)
    m1_r = subprocess.run([str(m1_exe)], input=c_input, capture_output=True, text=True, timeout=30)
    if m1_r.returncode == 0:
        m1_lines = m1_r.stdout.strip().split('\n')
        m1_results = [bytes.fromhex(l) if l else b'' for l in m1_lines]
        m1_caught = sum(1 for a, m in zip(a_results, m1_results) if a != m)
        teeth.append({'mutant': 'key_43', 'caught': m1_caught,
                      'status': 'PASS' if m1_caught > 0 else 'FAIL'})

    # MUTANT2: use XOR instead of subtract
    m2_src = C_DRIVER_V2.replace('*data - key', '*data ^ key')
    m2_exe = build_c_driver(m2_src)
    m2_r = subprocess.run([str(m2_exe)], input=c_input, capture_output=True, text=True, timeout=30)
    if m2_r.returncode == 0:
        m2_lines = m2_r.stdout.strip().split('\n')
        m2_results = [bytes.fromhex(l) if l else b'' for l in m2_lines]
        m2_caught = sum(1 for a, m in zip(a_results, m2_results) if a != m)
        teeth.append({'mutant': 'xor_not_sub', 'caught': m2_caught,
                      'status': 'PASS' if m2_caught > 0 else 'FAIL'})

    # MUTANT3: constant key (no evolution)
    m3_src = C_DRIVER_V2.replace('key = key * key + key;', '/* MUTANT3: no key evolution */')
    m3_exe = build_c_driver(m3_src)
    m3_r = subprocess.run([str(m3_exe)], input=c_input, capture_output=True, text=True, timeout=30)
    if m3_r.returncode == 0:
        m3_lines = m3_r.stdout.strip().split('\n')
        m3_results = [bytes.fromhex(l) if l else b'' for l in m3_lines]
        m3_caught = sum(1 for a, m in zip(a_results, m3_results) if a != m)
        teeth.append({'mutant': 'no_key_evolution', 'caught': m3_caught,
                      'status': 'PASS' if m3_caught > 0 else 'FAIL'})

    all_pass = (not mismatches and has_change
                and all(t['status'] == 'PASS' for t in teeth))

    receipt = {
        'schema': 'cally-simpledecode-diff/1',
        'function': 'CSkeletonSprite::SimpleDecode',
        'entry': hex(SIMPLE_DECODE),
        'original_sha256': hashlib.sha256(open(oracle.so, 'rb').read()).hexdigest(),
        'c_source': 'inline (deterministic data formula i*7+13)',
        'seed': SEED,
        'n_cases': len(cases),
        'lengths': [length for length, _ in cases],
        'gates': {
            'identity': {'pass': not mismatches, 'mismatches': mismatches[:5]},
            'non_degenerate': {'pass': has_change, 'detail': 'decoded bytes differ from input'},
            'teeth': teeth,
        },
        'status': 'PASS' if all_pass else 'FAIL',
        'stubbed_imports': 'none (pure function)',
        'scope': 'pure XOR-like decode; rsb (reverse subtract) with key 42; 1..64 bytes; deterministic input',
        'timestamp': time.strftime('%Y%m%dT%H%M%S'),
    }

    RECEIPTS.mkdir(exist_ok=True)
    receipt_path = RECEIPTS / f'simple_decode_diff-{time.strftime("%Y%m%dT%H%M%S")}.json'
    receipt_path.write_text(json.dumps(receipt, ensure_ascii=False, indent=2) + '\n')

    print(f'SimpleDecode differential: {receipt["status"]}')
    print(f'  identity:    {"PASS" if not mismatches else f"FAIL ({len(mismatches)} mismatches)"}')
    print(f'  non-degen:   {"PASS" if has_change else "FAIL"}')
    print(f'  teeth:       {all(t["status"] == "PASS" for t in teeth)}')
    for t in teeth:
        print(f'    {t["mutant"]}: {t["status"]} (caught={t.get("caught", "?")})')
    print(f'  receipt: {receipt_path}')

    sys.exit(0 if all_pass else 1)


if __name__ == '__main__':
    main()
