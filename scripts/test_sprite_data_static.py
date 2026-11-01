#!/usr/bin/env python3
"""Static-contract checks for Sprite_Data; never executes original ELF.

Host test uses synthetic globals. ARMv7 check only compiles and checks symbols.
Mutation cases are compiled in an invocation-owned temporary directory.
"""
from pathlib import Path
import hashlib
import os
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[1]
C = ROOT / 'reconstruction/reverse-v1/c'
SRC = C / 'sprite_data.c'
TEST = C / 'sprite_data_test.c'
HEADER = C / 'sprite_data.h'

def run(cmd, **kw):
    p = subprocess.run(cmd, text=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, **kw)
    return p

def must(p, label):
    if p.returncode:
        raise SystemExit(f'{label}: exit={p.returncode}\n{p.stdout}{p.stderr}')
    return p

def main():
    for f in (SRC, TEST, HEADER):
        print('BINDING', f.name, hashlib.sha256(f.read_bytes()).hexdigest())
    with tempfile.TemporaryDirectory(prefix='sprite-data-') as tmp:
        tmp = Path(tmp)
        env = os.environ.copy()
        env['LLVM_PROFILE_FILE'] = str(tmp / 'p-%p.profraw')
        base = ['clang', '-std=c11', '-Wall', '-Wextra', '-Werror', '-O1', '-I', str(C)]
        exe = tmp / 'test'
        must(run(base + [str(SRC), str(TEST), '-o', str(exe)], env=env), 'host compile')
        p = must(run([str(exe)], env=env), 'host synthetic fixture')
        print(p.stdout.strip())
        # Each false implementation must be rejected by the same real consumer.
        source = SRC.read_text(encoding='utf-8')
        variants = {
            'inclusive_upper_bound': ('index >= g_NumberOfSprites', 'index > g_NumberOfSprites', 'count boundary'),
            'extra_indirection': ('g_SpriteItems.items[index]',
                '((SpriteItems *)(uintptr_t)g_SpriteItems.unknown0)->items[index]', 'first from real +4'),
        }
        for name, (old, new, failure) in variants.items():
            if source.count(old) != 1:
                raise SystemExit(f'{name}: mutation target missing or nonunique')
            mut = tmp / (name + '.c')
            mut.write_text(source.replace(old, new), encoding='utf-8')
            must(run(base + [str(mut), str(TEST), '-o', str(exe)], env=env), name + ' compile')
            p = run([str(exe)], env=env)
            if p.returncode != 1 or f'FAIL {failure}' not in p.stderr:
                raise SystemExit(f'{name}: mutant not rejected by named assertion: rc={p.returncode} {p.stderr}')
            print(f'negative control {name}: rejected by {failure}')
        obj = tmp / 'sprite_data_arm.o'
        must(run(['clang', '--target=armv7a-unknown-linux-android30', '-std=c11',
                  '-Wall', '-Wextra', '-Werror', '-O1', '-c', str(SRC), '-o', str(obj)], env=env), 'armv7 compile')
        nm = must(run(['llvm-nm', str(obj)], env=env), 'armv7 symbols').stdout
        for needed in (' T _Z11Sprite_Datai', ' U g_SpriteItems', ' U g_NumberOfSprites'):
            if needed not in nm:
                raise SystemExit('missing armv7 symbol: '+needed+'\n'+nm)
        print('ARMv7 compilation, layout assertions and exported/required symbols: PASS')
    print('BOUNDARY: self-consistency and static structure only; original ELF not executed')

if __name__ == '__main__':
    main()
