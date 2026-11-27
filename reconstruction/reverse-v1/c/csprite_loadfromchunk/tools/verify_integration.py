#!/usr/bin/env python3
"""Integration of the shipped Loader+Clear translations, not original execution.

Also falsifies the exact 64-bit-host pointer-store regression with mapped guards.
All default build outputs are invocation-owned and automatically removed.
"""
from pathlib import Path
import hashlib
import os
import re
import shutil
import subprocess
import tempfile
import run_tests as fixture

ROOT = Path(__file__).resolve().parents[1]
SRC = ROOT / 'src'
CLEAR = ROOT.parent / 'csprite_clear/src'
SYMBOL = '_ZN7CSprite13LoadFromChunkEP8YYSpritePh'


def call(cmd, env, expected=0):
    p = subprocess.run([str(x) for x in cmd], env=env, text=True, capture_output=True, timeout=60)
    if p.returncode != expected:
        raise SystemExit(f'FAIL rc={p.returncode} expected={expected}: {cmd}\n{p.stdout}{p.stderr}')
    return p


def main():
    if not shutil.which('qemu-arm'):
        print('SKIP ARM32: qemu-arm missing (not full acceptance)')
        return 2
    inputs = [SRC / 'csprite_loadfromchunk.c', SRC / 'csprite_loadfromchunk.h',
              SRC / 'test_doubles.c', SRC / 'test_doubles.h', SRC / 'driver.c',
              ROOT / 'tools/chain.c', CLEAR / 'csprite_clear.c', CLEAR / 'csprite_clear.h',
              Path(__file__).resolve(), ROOT / 'tools/run_tests.py']
    for p in inputs:
        print('BINDING', p.relative_to(ROOT.parent), hashlib.sha256(p.read_bytes()).hexdigest())
    with tempfile.TemporaryDirectory(prefix='cally-loader-chain-') as tmp:
        d = Path(tmp)
        env = dict(os.environ, TMPDIR=tmp, LLVM_PROFILE_FILE=str(d / 'profile-%p.profraw'))
        inc = ['-I'+str(SRC), '-I'+str(CLEAR)]
        for target, flags, runner, extra in (
                ('host', fixture.HOST_FLAGS, [], ['-lm']),
                ('arm32', fixture.ARM_FLAGS, ['qemu-arm'], [])):
            exe = d / ('chain_'+target)
            call(['clang', *flags, '-DCSPRITE_CHAIN_WITH_REAL_CLEAR', *inc,
                  ROOT / 'tools/chain.c', SRC / 'csprite_loadfromchunk.c',
                  CLEAR / 'csprite_clear.c', SRC / 'test_doubles.c', *extra, '-o', exe], env)
            p = call([*runner, exe], env)
            if len(re.findall(r'^PASS  C[123] ', p.stdout, re.M)) != 3 or 'chain summary: 3 passed, 0 failed' not in p.stdout:
                raise SystemExit('FAIL chain roster\n'+p.stdout)
            print(target, p.stdout.strip().splitlines()[-1])
        obj = d / 'loader.o'
        call(['clang', '--target=armv7a-unknown-linux-android30', '-std=c11', '-O1',
              '-Wall', '-Wextra', '-Werror', '-fmath-errno', '-ffp-contract=off',
              '-c', SRC/'csprite_loadfromchunk.c', '-o', obj], env)
        nm = call(['llvm-nm', '--defined-only', obj], env).stdout
        if len(re.findall(r'\bT '+re.escape(SYMBOL)+r'$', nm, re.M)) != 1:
            raise SystemExit('FAIL original public mangled symbol\n'+nm)
        print('original mangled export and ARM32 compilation: PASS')
        # Reintroduce each precise original bug independently. A uint64 store is
        # bounded by the mapped guard and is observed only on 64-bit host tests.
        text = (SRC/'csprite_loadfromchunk.c').read_text()
        for name, old, new, failed in (
                ('wide_main', '*(uint32_t *)(uintptr_t)(uint32_t)(base + off) = /* ARM32 str: always four bytes */',
                 '*(uint64_t *)(uintptr_t)(uint32_t)(base + off) = /* faulty host-width store */', 'T27'),
                ('wide_swf', '                        *(uint32_t *)(uintptr_t)(uint32_t)(base + off) =\n',
                 '                        *(uint64_t *)(uintptr_t)(uint32_t)(base + off) =\n', 'T28')):
            if text.count(old) != 1:
                raise SystemExit('FAIL mutation anchor '+name)
            source, exe = d/(name+'.c'), d/name
            source.write_text(text.replace(old, new, 1))
            call(['clang', *fixture.HOST_FLAGS, source, SRC/'driver.c', SRC/'test_doubles.c', '-lm', '-o', exe], env)
            p = call([exe], env, expected=1)
            names = re.findall(r'^FAIL  (T\d+) ', p.stdout, re.M)
            if names != [failed]:
                raise SystemExit('FAIL guard regression not rejected exactly\n'+p.stdout)
            print('negative control', name, 'rc=1 assertion='+failed)
    print('BOUNDARY: integrated translations and synthetic dependencies only; original not executed')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
