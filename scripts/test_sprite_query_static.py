#!/usr/bin/env python3
"""Exercise statically recovered Sprite_Number/Exists without original execution.

Host synthetic fixtures are NOT original-vs-translation differential evidence.
ARM32: compile and inspect symbols/layout, not an execution of either body.
"""
from pathlib import Path
import hashlib
import os
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[1]
C = ROOT / 'reconstruction/reverse-v1/c'
SRC, TEST, HEADER = (C / n for n in ('sprite_query.c', 'sprite_query_test.c', 'sprite_data.h'))
DATA = C / 'sprite_data.c'


def run(cmd, env):
    return subprocess.run(cmd, text=True, capture_output=True, env=env)


def require(p, label):
    if p.returncode:
        raise SystemExit(f'{label}: rc={p.returncode}\n{p.stdout}{p.stderr}')
    return p


def main():
    for f in (SRC, TEST, HEADER, DATA):
        print('BINDING', f.name, hashlib.sha256(f.read_bytes()).hexdigest())
    with tempfile.TemporaryDirectory(prefix='sprite-query-') as tmp:
        d = Path(tmp)
        env = dict(os.environ, TMPDIR=tmp, LLVM_PROFILE_FILE=str(d / 'profile-%p.profraw'))
        base = ['clang', '-std=c11', '-Wall', '-Wextra', '-Werror', '-O1', '-I', str(C)]
        exe = d / 'test'
        text = SRC.read_text(encoding='utf-8')
        variants = {
            'noop': (None, None, None),
            'wrong_count': ('return g_NumberOfSprites;', 'return 0;', 'number-three'),
            'reject_zero': ('index < 0', 'index <= 0', 'first-real-table'),
            'inclusive_upper': ('index >= g_NumberOfSprites', 'index > g_NumberOfSprites', 'upper-bound'),
            'wrong_table_indirection': ('g_SpriteItems.items[index]',
                '((SpriteItems *)(uintptr_t)g_SpriteItems.unknown0)->items[index]', 'first-real-table'),
            'inverted_presence': ('!= NULL', '== NULL', 'first-real-table'),
        }
        for name, (old, new, failure) in variants.items():
            if old is None:
                altered = text
            else:
                if text.count(old) != 1:
                    raise SystemExit(f'{name}: mutation target missing/nonunique')
                altered = text.replace(old, new, 1)
            mut = d / (name + '.c')
            mut.write_text(altered, encoding='utf-8')
            require(run(base + [str(mut), str(DATA), str(TEST), '-o', str(exe)], env), name + ' compile')
            p = run([str(exe)], env)
            if failure is None:
                require(p, 'unmodified synthetic fixture')
                if p.stdout.strip() != 'sprite-query synthetic fixture: 14/14 PASS':
                    raise SystemExit(f'fixture case count mismatch: {p.stdout!r}')
                print('host/no-op:', p.stdout.strip())
            elif p.returncode != 1 or f'FAIL {failure}:' not in p.stderr:
                raise SystemExit(f'{name}: expected named assertion {failure}, rc={p.returncode}\n{p.stdout}{p.stderr}')
            else:
                print('negative control', name, 'rejected by', failure)
        obj = d / 'query_arm.o'
        require(run(['clang', '--target=armv7a-unknown-linux-android30', '-std=c11',
                     '-Wall', '-Wextra', '-Werror', '-O1', '-c', str(SRC), '-o', str(obj)], env), 'armv7 compile')
        nm = require(run(['llvm-nm', str(obj)], env), 'armv7 nm').stdout
        for symbol in (' T _Z13Sprite_Numberv', ' T _Z13Sprite_Existsi',
                       ' U g_SpriteItems', ' U g_NumberOfSprites'):
            if symbol not in nm:
                raise SystemExit(f'missing ARMv7 symbol {symbol}\n{nm}')
        print('ARMv7 compile, structure assertions and symbols: PASS')
    print('BOUNDARY: synthetic contract only; original ELF not executed')


if __name__ == '__main__':
    main()
