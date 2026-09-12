#!/usr/bin/env python3
"""Strict, CODE17-only source-to-Rust translation; never a runtime GML VM.

Usage: python scripts/generate_player_startup.py SOURCE.gml [--check]
The original GML is external recovery evidence, not a runtime input. Every line
is consumed by the grammar below, including braces. Unknown syntax is fatal.
Use --self-test to exercise rejection and consumption without source artifacts.
"""
import argparse
import hashlib
from pathlib import Path
import re
import unittest

GML_SHA256 = 'dc640893db3b07c6fe5ce278157d039c7223acea70e4d40133aaf8b83569a23b'
CODE_SHA256 = '4b1f25be1bf7916fd002ea1747e5d5a92e545da6625ad9a290ce0d0f2384da75'
OUTPUT = Path(__file__).resolve().parents[1] / 'crates/core/src/original_player_startup.rs'
NUM = r'[0-9]+(?:\.[0-9]+)?'
NAME = r'[A-Za-z_][A-Za-z_0-9]*'
STR = r'"[A-Za-z_0-9.]*"'
FIELD = rf'(?:global\.{NAME}|score)'


def number(value):
    if not re.fullmatch(NUM, value):
        raise ValueError(f'unsupported numeric literal: {value!r}')
    return value if '.' in value else value + '.0'


def read(field):
    if not re.fullmatch(FIELD, field):
        raise ValueError(f'unsupported field: {field!r}')
    if field.startswith('global.'):
        return f'rt.read_global("{field[7:]}")'
    return 'rt.read_self("score")'


class Translator:
    def __init__(self, text):
        self.lines = text.splitlines()
        self.pos = 0
        self.output = []
        self.counts = dict(read=0, write=0, exists=0, open=0, close=0, if_=0, else_=0)

    def emit(self, text, depth):
        self.output.append('    ' * depth + text)

    def consume(self, depth):
        line = self.lines[self.pos].strip()
        self.pos += 1
        self.emit(f'// GML {self.pos}: {line}', depth)
        return line

    def block(self, depth, nested=False):
        previous_if = False
        while self.pos < len(self.lines):
            s = self.consume(depth)
            if s == '}':
                if not nested:
                    raise ValueError(f'line {self.pos}: unmatched closing brace')
                self.emit('}', depth - 1)
                return
            m = re.fullmatch(r'(else )?if \((.*)\)', s)
            if m:
                is_else, condition = m.groups()
                if is_else and not previous_if:
                    raise ValueError(f'line {self.pos}: else without preceding if')
                self.counts['if_'] += 1
                self.counts['else_'] += bool(is_else)
                f = re.fullmatch(rf'(!?)file_exists\(({STR})\)', condition)
                g = re.fullmatch(rf'global\.({NAME}) (==|>) ({NUM})', condition)
                if f:
                    self.counts['exists'] += 1
                    expr = f'{f[1]}rt.file_exists({f[2]})'
                elif g:
                    expr = f'rt.read_global("{g[1]}") {g[2]} {number(g[3])}'
                else:
                    raise ValueError(f'line {self.pos}: unknown condition {condition!r}')
                self.emit(('else ' if is_else else '') + f'if {expr} {{', depth)
                if self.pos == len(self.lines) or self.consume(depth + 1) != '{':
                    raise ValueError(f'line {self.pos}: expected opening brace')
                self.block(depth + 1, True)
                previous_if = True
                continue
            previous_if = False
            if s == 'AdColony_Init("app73023f81ce5d4f508a", "vz1aca9f7894b44cec93", "");':
                self.emit('rt.adcolony_init("app73023f81ce5d4f508a", "vz1aca9f7894b44cec93", "");', depth)
                continue
            if s == 'instance_create(x, y, obj_introduction);':
                self.emit('// Original CODE17 offsets 39224/39232: push self.y, then self.x.', depth)
                self.emit('let y = rt.read_self("y");', depth)
                self.emit('let x = rt.read_self("x");', depth)
                self.emit('rt.spawn_named(x, y, "obj_introduction");', depth)
                continue
            m = re.fullmatch(rf'ini_open\(({STR})\);', s)
            if m:
                self.counts['open'] += 1
                self.emit(f'rt.ini_open({m[1]});', depth)
                continue
            if s == 'ini_close();':
                self.counts['close'] += 1
                self.emit('rt.ini_close();', depth)
                continue
            m = re.fullmatch(rf'ini_write_real\(({STR}), ({STR}), ({FIELD})\);', s)
            if m:
                self.counts['write'] += 1
                self.emit(f'let value = {read(m[3])};', depth)
                self.emit(f'rt.ini_write_real({m[1]}, {m[2]}, value);', depth)
                continue
            m = re.fullmatch(rf'({FIELD}) = (.*);', s)
            if m:
                target, rhs = m.groups()
                ini = re.fullmatch(rf'ini_read_real\(({STR}), ({STR}), ({NUM})\)', rhs)
                if ini:
                    self.counts['read'] += 1
                    self.emit(f'let value = rt.ini_read_real({ini[1]}, {ini[2]}, {number(ini[3])});', depth)
                    value = 'value'
                elif re.fullmatch(NUM, rhs):
                    value = number(rhs)
                else:
                    raise ValueError(f'line {self.pos}: unsupported assignment {rhs!r}')
                scope, name = ('global', target[7:]) if target.startswith('global.') else ('self', target)
                self.emit(f'rt.write_{scope}("{name}", {value});', depth)
                continue
            raise ValueError(f'line {self.pos}: unrecognized syntax {s!r}')
        if nested:
            raise ValueError('unterminated block')


def translate(raw):
    if hashlib.sha256(raw).hexdigest() != GML_SHA256:
        raise ValueError('CODE17 GML SHA-256 mismatch')
    t = Translator(raw.decode('utf-8'))
    t.block(1)
    expected = dict(read=324, write=324, exists=6, open=4, close=4, if_=138, else_=3)
    if t.counts != expected or t.pos != 1540:
        raise ValueError(f'coverage mismatch: {t.pos} lines; {t.counts}')
    header = f'''//! Complete CODE17 obj_player Other_2, translated from all 1540 GML lines.
//! GML SHA-256: {GML_SHA256}
//! Original bytecode SHA-256: {CODE_SHA256}
//! Regenerate with scripts/generate_player_startup.py; unsupported syntax is fatal.
//! Explicit immediate calls preserve live host side effects and original ordering.
//! This is not original-file INI compatibility or a production startup host.
use crate::original_startup::StartupRuntime;

/// Run the recovered body. Host owns initialized fields, INI and ad policy.
/// Deliberately separate `if`s: >10 clamps AFTER damage branches; fractional
/// levels do not acquire an invented damage default. Never snapshot globals.
pub fn player_other2<R: StartupRuntime>(rt: &mut R) {{
'''
    return header + '\n'.join(t.output) + '\n}\n'


class StrictGrammarTests(unittest.TestCase):
    def test_unknown_syntax_is_fatal(self):
        for text in ('while (1) {}', 'global.x = foo();', 'global.x = 1; trailing',
                     'if (global.x != 1)\n{\n}', '{', '}', '', 'else if (global.x == 1)\n{\n}'):
            with self.subTest(text=text), self.assertRaises(ValueError):
                Translator(text + '\n').block(1)

    def test_unterminated_block_is_fatal(self):
        with self.assertRaises(ValueError):
            Translator('if (global.x == 1)\n{\nglobal.x = 2;').block(1)

    def test_hash_mismatch_is_fatal(self):
        with self.assertRaisesRegex(ValueError, 'SHA-256'):
            translate(b'global.x = 0;')

    def test_every_line_consumed_and_commented(self):
        t = Translator('if (global.x == 1)\n{\nglobal.x = 2;\n}')
        t.block(1)
        self.assertEqual(t.pos, 4)
        for i in range(1, 5):
            self.assertTrue(any(f'// GML {i}:' in s for s in t.output))


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('source', type=Path, nargs='?')
    p.add_argument('--check', action='store_true')
    p.add_argument('--output', type=Path, default=OUTPUT)
    p.add_argument('--self-test', action='store_true')
    args = p.parse_args()
    if args.self_test:
        result = unittest.TextTestRunner(verbosity=2).run(unittest.defaultTestLoader.loadTestsFromTestCase(StrictGrammarTests))
        raise SystemExit(not result.wasSuccessful())
    if args.source is None:
        p.error('source required unless --self-test')
    output = translate(args.source.read_bytes())
    if args.check:
        if args.output.read_text() != output:
            raise SystemExit('generated Rust differs')
    else:
        args.output.write_text(output)
    print('CODE17: consumed 1540 lines; 324 read/324 write; 6 exists; 4 open/close; 138 if/3 else')


if __name__ == '__main__':
    main()
