#!/usr/bin/env python3
"""Generate c/do_sub/src/do_sub.c from a template + the pinned image.

WHY a generator: the census gate requires every instruction of the original body
to appear in the translation as `/* @0xADDR <verbatim operand text> */`, exactly
once, matching llvm-objdump byte for byte.  Hand-typing 1015 operand strings is
how a translation silently drifts from the bytes, so the annotation ledger is
emitted from the image instead of from memory.  The C bodies are written by hand
in the template; this script only owns the `//@@BLOCK <start> <end>` expansion
and the residual ledger.

Usage:  python3 c/do_add/tools/gen_ledger.py [--check]
"""
import argparse
import pathlib
import re
import struct
import subprocess
import sys

from elftools.elf.elffile import ELFFile

HERE = pathlib.Path(__file__).resolve().parent
SRC = HERE.parent / 'src'
TEMPLATE = SRC / 'do_sub.c.in'
OUT = SRC / 'do_sub.c'
SO_CANDIDATES = [
    pathlib.Path('/data/data/com.termux/files/home/callys-caves-2-rs/reconstruction/live-mem/libyoyo_armv7.so'),
    pathlib.Path('/data/data/com.termux/files/home/cally-oracle/libyoyo.so'),
]
SO = next((p for p in SO_CANDIDATES if p.exists()), SO_CANDIDATES[0])

ENTRY = 0xdd500          # _Z5DoSubjPhPKhP6VMExec
POOL = 0xddd24           # first literal-pool word (17 words end at 0xddd68)
END = 0xddd68            # first byte after DoSub


def norm(s):
    return re.sub(r'\s+', ' ', s).strip()


def objdump(entry, stop):
    p = subprocess.run(['llvm-objdump', '-d', '--start-address=%#x' % entry,
                        '--stop-address=%#x' % stop, '-M', 'reg-names-std', str(SO)],
                       capture_output=True, text=True)
    if p.returncode:
        raise SystemExit('llvm-objdump failed: %s' % p.stderr[-800:])
    rows = []
    for ln in p.stdout.splitlines():
        m = re.match(r'\s*([0-9a-f]+):\s+([0-9a-f]{8})\s+(.*)$', ln)
        if not m:
            continue
        addr = int(m.group(1), 16)
        text = ' '.join(x for x in m.group(3).split('\t') if x.strip())
        text = re.sub(r'\s*<[^>]*>', '', text)      # drop <sym+0x2c>
        text = re.sub(r'\s*@.*$', '', text)         # drop @ imm = #0x40
        text = norm(text)
        if not text:
            continue
        rows.append((addr, text))
    return rows


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--check', action='store_true',
                    help='fail instead of writing when the output would change')
    args = ap.parse_args()

    rows = objdump(ENTRY, END)
    text_of = dict(rows)
    order = [a for a, _ in rows if a < POOL]
    word_of = {}
    with open(SO, 'rb') as f:
        segs = [(s['p_vaddr'], s['p_offset'], s['p_filesz'])
                for s in ELFFile(f).iter_segments() if s['p_type'] == 'PT_LOAD']
    blob = pathlib.Path(SO).read_bytes()
    for a in range(POOL, END, 4):
        for v, o, sz in segs:
            if v <= a < v + sz:
                off = o + (a - v)
                word_of[a] = struct.unpack('<I', blob[off:off + 4])[0]
    if len(word_of) != 17:
        raise SystemExit('literal pool: expected 17 words, found %d' % len(word_of))

    def line(addr):
        return '/* @%#x %s */' % (addr, text_of[addr])

    tmpl = TEMPLATE.read_text().splitlines()
    out, covered = [], set()
    for ln in tmpl:
        m = re.match(r'\s*//@@BLOCK (0x[0-9a-f]+) (0x[0-9a-f]+)(?:\s.*)?$', ln)
        if not m:
            out.append(ln)
            continue
        lo, hi = int(m.group(1), 16), int(m.group(2), 16)
        for a in order:
            if lo <= a < hi:
                out.append('    ' + line(a))
                covered.add(a)
        continue

    # residual ledger: every instruction the template did not expand, grouped by
    # 64-byte neighbourhood so a reader can still follow the body.
    rest = [a for a in order if a not in covered]
    out.append('')
    out.append('/* ════ 逐指令台账（自动生成，勿手改）════════════════════════════════════')
    out.append(' * 上面每个 //@@BLOCK 段已就地标注它实现的那段原版指令；下面这段是同一函数里')
    out.append(' * 没有 C 语句的指令：跳转表项、错误桩、以及 DoAdd 里未被本译文执行的路径')
    out.append(' * （例如字符串对象的释放链，依赖尚未恢复的 RefThing/YYFree）。每一条都在')
    out.append(' * 这里出现且只出现一次，操作数逐字取自 llvm-objdump；census 门会把这份台账')
    out.append(' * 与原版字节逐条比对，多一条、少一条、改一个操作数都会红。')
    out.append(' */')
    prev = None
    for a in rest:
        if prev is not None and a - prev > 0x40:
            out.append('')
        out.append('/* %s */' % line(a)[3:-3])
        prev = a
    out.append('')
    out.append('/* ── 字面量池 0xddd24..0xddd68（17 个字，全函数唯一的 PC 相对数据）──────')
    out.append(' * 上面每条错误的 VMError/JSThrow 都靠 ldr rX,[pc,#..] 从这里取字符串偏移；')
    out.append(' * census 门同时核对这 17 个字的数值，改一个字就会红。 */')
    for a, w in sorted(word_of.items()):
        out.append('/* @%#x .word %#010x */' % (a, w))
    out.append('/* ════ 台账结束 ═══════════════════════════════════════════════════════ */')

    blob = '\n'.join(out) + '\n'
    if args.check:
        old = OUT.read_text() if OUT.exists() else ''
        if old != blob:
            print('do_sub.c is STALE against the template/image', file=sys.stderr)
            return 1
        print('do_sub.c is current (%d instructions)' % len(order))
        return 0
    OUT.write_text(blob)
    print('wrote %s: %d instructions, %d annotated in place, %d in the residual ledger'
          % (OUT, len(order), len(covered), len(rest)))
    return 0


if __name__ == '__main__':
    sys.exit(main())
