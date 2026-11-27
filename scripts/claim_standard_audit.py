#!/usr/bin/env python3
"""Audit the reverse-v1 claims ledger against the CURRENT evidence standard.

The standard (reverse-toolkit `db/SCHEMA.md` §1, tightened 2026-10-31):
a status word is a gate, the body is the evidence.
    proven    body carries a reproducible judgement - device/command/input
              domain/receipt - the input domain is non-degenerate, and a rerun
              gives the same result
    narrowed  has a judgement but the body says which face it proved and which
              it did not
    refuted   body carries a counter-example and points at the entry it refutes
    open      placeholder, no judgement

Anything whose body does not meet its status word must be read as `open`; it may
not be cited downstream as a gate.

This tool does not rewrite anything. It classifies every claim, prints the
distribution, and writes a report so the ledger owner can decide. Classification
is deliberately mechanical and conservative, and every bucket keeps a sample so
the reading can be challenged:

    device     body names a runnable device (script/oracle/harness/seed/命令/回执)
    static     body cites instruction addresses or byte-level reads only -
               reproducible by re-reading the binary, but NOT a runtime result
    behavior   the claim TEXT asserts runtime behaviour while the body is static
               (this is the bucket the standard is aimed at)
    naked      neither addresses nor a device

Usage:
  python3 scripts/claim_standard_audit.py [--md OUT.md] [--tsv OUT.tsv]
"""
import argparse
import collections
import glob
import json
import os
import re
import pathlib

ROOT = pathlib.Path(__file__).resolve().parents[1]
RV1 = ROOT / 'reconstruction/reverse-v1'

DEVICE = ('oracle', 'unicorn', 'harness', 'seed', '种子', 'receipt', '回执',
          '.py', 'clang', 'cargo', 'pytest', 'c-recon', 'gate_sha', '夹具')
ADDR = re.compile(r'(0x[0-9a-f]{3,}|\b[0-9a-f]{5,8}\b|@func|逐条|指令)')
BEHAVIOR = ('运行', '实际执行', '会', '调用', '返回', '写回', '读出', '走这', '触发',
            '行为', '等价')


def load():
    """All claims rows, deduped by id.

    `claims.jsonl` at the tree root is a partial aggregate that repeats some
    batch rows verbatim, so the raw file count overstates the ledger: the
    authoritative total is the unique-id count, and `verify_reverse_v1.py`
    agrees with it. Duplicates are reported, not silently dropped.
    """
    raw = []
    for f in sorted(glob.glob(str(RV1 / 'claims*.jsonl'))):
        for ln, line in enumerate(open(f, encoding='utf-8'), 1):
            line = line.strip()
            if not line:
                continue
            d = json.loads(line)
            d['_file'] = os.path.basename(f)
            d['_line'] = ln
            raw.append(d)
    # Prefer a batch file over the aggregate when the same id appears twice.
    best = {}
    for d in raw:
        i = d.get('id')
        cur = best.get(i)
        if cur is None or (cur['_file'] == 'claims.jsonl' and d['_file'] != 'claims.jsonl'):
            best[i] = d
    dups = [(d.get('id'), d.get('_file'), d.get('_line')) for d in raw
            if best.get(d.get('id')) is not d]
    return [best[k] for k in best], dups, len(raw)


def classify(d):
    body = (d.get('evidence') or '') + ' ' + (d.get('claim_note') or '')
    low = body.lower()
    text = d.get('claim') or ''
    has_device = any(k in low for k in DEVICE)
    has_addr = bool(ADDR.search(body))
    asserts_behavior = any(k in text for k in BEHAVIOR)
    if has_device:
        return 'device'
    if has_addr and asserts_behavior:
        return 'behavior'
    if has_addr:
        return 'static'
    return 'naked'


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--md')
    ap.add_argument('--tsv')
    args = ap.parse_args()

    rows, dups, raw_n = load()
    dist = collections.Counter()
    per_status = collections.defaultdict(collections.Counter)
    samples = collections.defaultdict(list)
    ids = collections.Counter()
    for d in rows:
        k = classify(d)
        dist[k] += 1
        st = d.get('status', '?')
        per_status[st][k] += 1
        ids[d.get('id')] += 1
        if len(samples[(st, k)]) < 3:
            samples[(st, k)].append((d.get('id'), d.get('card'), (d.get('claim') or '')[:90]))

    verdict = collections.Counter()
    for st, c in per_status.items():
        if st == 'proven':
            verdict['proven 合格（有装置）'] = c['device']
            verdict['proven 待降 narrowed（正文断言行为、证据只有地址）'] = c['behavior']
            verdict['proven 属静态事实（可复查地址，非运行结果）'] = c['static']
            verdict['proven 无判据 → 按 open'] = c['naked']
        elif st == 'narrowed':
            verdict['narrowed 有装置'] = c['device']
            verdict['narrowed 仅地址/无装置（标准要求写明证到哪面）'] = c['behavior'] + c['static'] + c['naked']
        elif st == 'refuted':
            verdict['refuted 有反例装置'] = c['device']
            verdict['refuted 仅地址（缺反例判据）'] = c['behavior'] + c['static'] + c['naked']
        elif st == 'open':
            verdict['open 占位（符合）'] = sum(c.values())

    lines = []
    lines.append('# Claims 对新标准的合规审计（只读，不改账）\n')
    lines.append('标准来源：reverse-toolkit `db/SCHEMA.md` §1「状态词是门，body 才是证文」，'
                 '2026-10-31 收紧后的四态判定条件。\n')
    lines.append('生成：`python3 scripts/claim_standard_audit.py`。本文件不改任何 claim 的 status，'
                 '只给出机器分类与样本，供决定降级/补证据。\n')
    lines.append('## 总量\n')
    lines.append('| 项 | 数 |\n| --- | --- |')
    lines.append('| 原始行（全部 claims*.jsonl，含根部的聚合文件） | %d |' % raw_n)
    lines.append('| **去重后 claims（权威总数）** | **%d** |' % len(rows))
    lines.append('| 文件数 | %d |' % len(glob.glob(str(RV1 / 'claims*.jsonl'))))
    lines.append('| 重复 id（一条在多文件里出现） | %d |' % len(dups))
    lines.append('| 正文分类：device / behavior / static / naked | %d / %d / %d / %d |'
                 % (dist['device'], dist['behavior'], dist['static'], dist['naked']))
    lines.append('\n## 按 status × 正文分类\n')
    lines.append('| status | device | behavior | static | naked |')
    lines.append('| --- | --- | --- | --- | --- |')
    for st in ('proven', 'narrowed', 'refuted', 'inferred', 'open'):
        if st in per_status:
            c = per_status[st]
            lines.append('| `%s` | %d | %d | %d | %d |' % (st, c['device'], c['behavior'], c['static'], c['naked']))
    lines.append('\n## 判定（按标准读）\n')
    for k, v in sorted(verdict.items(), key=lambda kv: -kv[1]):
        lines.append('- %s：**%d**' % (k, v))
    lines.append('\n## 样本（每桶最多 3 条，用来挑战分类）\n')
    for (st, k), items in sorted(samples.items()):
        lines.append('\n### %s × %s\n' % (st, k))
        for i, card, txt in items:
            lines.append('- `%s`（%s）%s' % (i, card, txt.replace('\n', ' ')))
    lines.append('\n## 怎么用这份审计\n')
    lines.append('1. `proven × behavior` 是唯一需要立刻动的桶：正文断言运行期行为，证据只有指令地址。'
                 '要么补一个装置（oracle/harness/seed/回执），要么把 status 降到 `narrowed` 并在正文写明'
                 '「只证到静态字节，未证运行」。')
    lines.append('2. `proven × static` 不是错，但只能当 `bytecode_anchored` 层引用，'
                 '不得被下游当作行为门。')
    lines.append('3. `refuted × 仅地址` 要补反例判据或指向被推翻条目，否则按 `open`。')
    lines.append('4. 本工具不改账：降级是账本所有者的动作，改完须重跑 `verify_reverse_v1.py`。\n')

    text = '\n'.join(lines) + '\n'
    if args.md:
        pathlib.Path(args.md).write_text(text)
    if args.tsv:
        with open(args.tsv, 'w') as fh:
            fh.write('id\tstatus\tcard\tclass\tfile\tline\n')
            for d in rows:
                fh.write('%s\t%s\t%s\t%s\t%s\t%s\n' % (
                    d.get('id'), d.get('status'), d.get('card'), classify(d),
                    d.get('_file'), d.get('_line')))
    if dups:
        lines.append('\n## 重复 id（同一结论在多份文件里各写一次）\n')
        for i, f, ln in dups[:30]:
            lines.append('- `%s` @ %s:%d' % (i, f, ln))
        text += '\n'.join(lines[-len(dups) - 2:]) + '\n'
    print(text[:2400])
    print('...\nclaims=%d %s' % (len(rows), dict(dist)))


if __name__ == '__main__':
    main()
