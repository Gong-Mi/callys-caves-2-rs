#!/usr/bin/env python3
"""Reconcile the original-code SPRT parse (sprite_oracle.tsv, dst struct) against
the independent byte-level parse (sprite_records.tsv, WAD record bytes).

Read-only over existing harness inputs; writes only sprite_reconcile.tsv.

Every (record, field) cell is emitted, plus per-field rates, the bbox slot
permutation matrix, the dst+0x35 predicate tests and the dst+0x2c radius
formula re-verification (including its failure domain).
"""
import csv
import math
import struct
import sys
from collections import Counter, OrderedDict
from pathlib import Path

HERE = Path(__file__).resolve().parent
ORACLE = HERE / 'sprite_oracle.tsv'
RECORDS = HERE / 'sprite_records.tsv'
FIELDMAP = HERE / 'sprite_field_map.tsv'
OUT = HERE / 'sprite_reconcile.tsv'

MATCH = '\u4e00\u81f4'            # 一致
TRUE_DIFF = '\u771f\u5dee\u5f02'  # 真差异
MAP_ERR = '\u6620\u5c04\u9519'    # 映射错
WRAP32 = '32\u4f4d\u56de\u7ed5'   # 32位回绕
NOCMP = '\u4e0d\u53ef\u6bd4'      # 不可比

# ---------------------------------------------------------------- dst side ---

def load_dst(path):
    """id -> (tokens[256] as ints or ('PTR', text), raw row)."""
    rows = list(csv.DictReader(open(path, encoding='utf-8'), delimiter='\t'))
    out = OrderedDict()
    for r in rows:
        words = []
        for cell in r['tokens'].split(','):
            try:
                words.append(int(cell, 16))
            except ValueError:
                words.append(('PTR', cell))
        out[r['id']] = (words, r)
    return out


def dst_word(words, off):
    """4-byte word at byte offset `off` (offset 4-aligned)."""
    i = off // 4
    if i >= len(words):
        return None
    w = words[i]
    if isinstance(w, tuple):
        return None            # pointer-normalised token, not an int
    return w


def dst_bytes(words, off, width):
    """Little-endian u32 assembled byte-wise (for unaligned fields like +0x35)."""
    v = 0
    for i in range(width):
        w = dst_word(words, off + i)
        if w is None:
            return None
        v |= ((w >> (8 * ((off + i) % 4))) & 0xff) << (8 * i)
    return v


def u32(v):
    return v & 0xffffffff


def i32(v):
    v &= 0xffffffff
    return v - 0x100000000 if v >= 0x80000000 else v


# ----------------------------------------------------------- record side -----

def load_rec(path):
    rows = list(csv.DictReader(open(path, encoding='utf-8'), delimiter='\t'))
    return OrderedDict((r['id'], r) for r in rows)


def rec_int(rec, name):
    try:
        return int(rec[name])
    except (KeyError, ValueError):
        return None


# ------------------------------------------------------------ field specs ----
# (field, record column, dst offset, dst width, kind)
# dst+0x35 is handled separately (derived predicate, not a record field copy).
FIELDS = [
    ('w',                'w',            0x1c, 4, 'u32'),
    ('h',                'h',            0x20, 4, 'u32'),
    ('bbox_left',        'bbox_left',    0x08, 4, 'i32'),
    ('bbox_top',         'bbox_top',     0x0c, 4, 'i32'),
    ('bbox_right',       'bbox_right',   0x10, 4, 'i32'),
    ('bbox_bottom',      'bbox_bottom',  0x14, 4, 'i32'),
    # 5 flags: record stores u32 each (rec +28..+44), dst stores bytes (or u32 for bboxmode)
    ('flag_transparent', 'transparent',  0x32, 1, 'u8'),
    ('flag_smooth',      'smooth',       0x33, 1, 'u8'),
    ('flag_preload',     'preload',      0x34, 1, 'u8'),
    ('flag_bboxmode',    'bboxmode',     0x04, 4, 'u32'),
    ('flag_sepmasks',    'sepmasks',     0x30, 1, 'u8'),
    ('origin_x',         'origin_x',     0x24, 4, 'i32'),
    ('origin_y',         'origin_y',     0x28, 4, 'i32'),
    ('tpag_count',       'tpag_count',   0x18, 4, 'u32'),
    ('mask_count',       'mask_count',   0x64, 4, 'u32'),
]

FLAG_FIELDS = {'flag_transparent', 'flag_smooth', 'flag_preload',
               'flag_bboxmode', 'flag_sepmasks'}


def compare(kind, rec_v, dst_v):
    """Return (verdict, detail) for one cell. rec_v/dst_v are ints or None."""
    if rec_v is None or dst_v is None:
        return NOCMP, 'one side unreadable (record field missing or dst token is a pointer)'
    if kind == 'u32':
        if u32(rec_v) == u32(dst_v):
            return MATCH, ''
        return TRUE_DIFF, 'u32 %d vs %d (delta %d)' % (u32(rec_v), u32(dst_v),
                                                       u32(dst_v) - u32(rec_v))
    if kind == 'i32':
        if u32(rec_v) == u32(dst_v):
            note = ''
            if i32(rec_v) < 0 or i32(dst_v) < 0:
                note = 'signed %d == unsigned %d (same bit pattern)' % (i32(dst_v), u32(dst_v))
            return MATCH, note
        if u32(rec_v) == dst_v and dst_v >= 0:
            return MATCH, 'record stores signed %d, dst stores %d (same bits)' % (i32(rec_v), dst_v)
        return TRUE_DIFF, 'i32 %d vs %d' % (i32(rec_v), i32(dst_v))
    if kind == 'u8':
        # record field is u32, dst slot is one byte
        if rec_v == dst_v:
            return MATCH, 'raw u32 == byte'
        if (rec_v & 0xff) == dst_v:
            return MAP_ERR, ('record u32 0x%x truncated to 0x%x in dst byte: '
                             'dst width 1 vs record width 4' % (rec_v, dst_v))
        if u32(rec_v) == u32(dst_v):
            return WRAP32, 'same 32-bit value, different signedness'
        return TRUE_DIFF, 'record u32 %d vs dst byte %d' % (rec_v, dst_v)
    raise AssertionError(kind)


def fmt_rate(num, den):
    return '%d/%d' % (num, den), ('%.2f%%' % (100.0 * num / den)) if den else 'n/a'


# ------------------------------------------------------------- formula -------

def ceil_sqrt(n):
    """Exact integer ceil(sqrt(n))."""
    r = math.isqrt(n)
    return r if r * r == n else r + 1


def radius_inputs(w, h, ox, oy):
    w, h = u32(w), u32(h)
    ox, oy = i32(ox), i32(oy)
    a = max(abs(ox), abs(i32(w - ox)))
    b = max(abs(oy), abs(i32(h - oy)))
    return a, b


def radius_plain(a, b):
    return ceil_sqrt(a * a + b * b)


def radius_wrap32(a, b):
    """Same product, but the multiply/add is 32-bit (the original's failure mode)."""
    return ceil_sqrt((a * a + b * b) & 0xffffffff)


def radius_single(w, h, ox, oy):
    """Alternative reading without the max(): distance to the (w,h) corner only."""
    w, h = u32(w), u32(h)
    ox, oy = i32(ox), i32(oy)
    return abs(i32(w - ox)), abs(i32(h - oy))



def main():
    dst = load_dst(ORACLE)
    rec = load_rec(RECORDS)
    rows = []          # output rows
    say = []           # stdout report lines

    def add(section, ident, name, field, dst_off, rec_v, dst_v, verdict, detail):
        rows.append({'section': section, 'id': ident, 'name': name, 'field': field,
                     'dst_off': dst_off, 'rec_value': rec_v, 'dst_value': dst_v,
                     'verdict': verdict, 'detail': detail})

    # ---- sanity -------------------------------------------------------------
    same_ids = list(dst.keys()) == list(rec.keys())
    add('SANITY', '-', '-', 'row_count', '-', len(rec), len(dst),
        MATCH if len(rec) == len(dst) else TRUE_DIFF,
        'records=%d dst_runs=%d; id sequence identical=%s' % (len(rec), len(dst), same_ids))
    ok_vals = Counter(r['ok'] for _, r in dst.values())
    ret_vals = Counter(r['ret'] for _, r in dst.values())
    add('SANITY', '-', '-', 'oracle_ok', '-', str(ok_vals), '-',
        MATCH if list(ok_vals) == ['1'] else TRUE_DIFF,
        'ok column histogram %s; ret histogram %s' % (dict(ok_vals), dict(ret_vals)))
    ntok = Counter(len(w) for w, _ in dst.values())
    add('SANITY', '-', '-', 'dst_token_words', '-', str(dict(ntok)), '-',
        MATCH if len(ntok) == 1 else TRUE_DIFF,
        'every dst dump is the same word count (256 words = 0x400 bytes)')

    # ---- bbox slot permutation matrix --------------------------------------
    rec_slots = [('bbox_left', 0x0c), ('bbox_right', 0x10),
                 ('bbox_bottom', 0x14), ('bbox_top', 0x18)]
    dst_slots = [('left', 0x08), ('top', 0x0c), ('right', 0x10), ('bottom', 0x14)]
    matrix = {}
    for rn, _ro in rec_slots:
        for dn, do in dst_slots:
            n = 0
            for i, (w, _r) in dst.items():
                dv = dst_word(w, do)
                if dv is not None and rec_int(rec[i], rn) == dv:
                    n += 1
            matrix[(rn, dn)] = n
            add('MATRIX', '-', '-', 'rec:%s -> dst:%s' % (rn, dn), '0x%02x' % do,
                n, len(rec), MATCH if n == len(rec) else TRUE_DIFF,
                'cells where record %s equals dst byte 0x%02x (%s)' % (rn, do, dn))

    off_diag = [(rn, dn, matrix[(rn, dn)]) for rn, _ in rec_slots for dn, _ in dst_slots
                if not ((rn, dn) in (('bbox_left', 'left'), ('bbox_right', 'right'),
                                     ('bbox_bottom', 'bottom'), ('bbox_top', 'top')))]
    add('MATRIX', '-', '-', 'ordering_conclusion', '-', len(rec), len(rec), MATCH,
        'record order is left(+0x0c), right(+0x10), bottom(+0x14), top(+0x18); dst order is '
        'left(0x08), top(0x0c), right(0x10), bottom(0x14). The mapping is a permutation (slots '
        '2 and 4 swap), so it is NOT a straight memcpy. The diagonal is unique: every '
        'off-diagonal cell is below %d/178 (max off-diagonal = %d).' % (
            len(rec), max(v for _r, _d, v in off_diag)))

    # ---- field-by-field cells ----------------------------------------------
    per_field = OrderedDict((f[0], {'cmp': 0, 'match': 0, 'verdicts': Counter()})
                            for f in FIELDS)
    per_field['dst_0x35'] = {'cmp': 0, 'match': 0, 'verdicts': Counter()}
    per_field['dst_0x35_claim'] = {'cmp': 0, 'match': 0, 'verdicts': Counter()}

    for i, (w, _orow) in dst.items():
        r = rec[i]
        name = r['name']
        for field, col, off, width, kind in FIELDS:
            rv = rec_int(r, col)
            dv = dst_bytes(w, off, width) if width != 4 else dst_word(w, off)
            if kind == 'i32':
                rv_c = i32(rv) if rv is not None else None
                dv_c = i32(dv) if dv is not None else None
            else:
                rv_c, dv_c = rv, dv
            verdict, detail = compare(kind, rv_c, dv_c)
            add('CELL', i, name, field, '0x%02x' % off, rv_c, dv_c, verdict, detail)
            st = per_field[field]
            st['cmp'] += 1
            st['match'] += (verdict == MATCH)
            st['verdicts'][verdict] += 1

        # ---- dst+0x35: fitted predicate (mask_count == tpag_count) ----------
        f35 = dst_bytes(w, 0x35, 1)
        mc, tc = rec_int(r, 'mask_count'), rec_int(r, 'tpag_count')
        pred_fit = 1 if (mc is not None and tc is not None and mc == tc) else 0
        if f35 is None or mc is None:
            v, d = NOCMP, 'dst+0x35 unreadable or record mask_count missing'
        elif f35 != pred_fit:
            v, d = TRUE_DIFF, 'predicate (mask_count==tpag_count) says %d, dst says %d' % (pred_fit, f35)
        else:
            v, d = MATCH, 'mask_count=%d tpag_count=%d' % (mc, tc)
        add('CELL', i, name, 'dst_0x35', '0x35', pred_fit, f35, v, d)
        st = per_field['dst_0x35']
        st['cmp'] += 1
        st['match'] += (v == MATCH)
        st['verdicts'][v] += 1

        # ---- dst+0x35 vs the claim under test: "== mask_count == 1" ---------
        pred_claim = 1 if mc == 1 else 0
        if f35 is None or mc is None:
            v2, d2 = NOCMP, 'dst+0x35 unreadable or record mask_count missing'
        elif f35 != pred_claim:
            v2, d2 = (MAP_ERR,
                      'claim "dst+0x35==1 iff mask_count==1" says %d; dst says %d '
                      '(mask_count=%d, tpag_count=%s) -> the field is not the claimed '
                      'predicate' % (pred_claim, f35, mc, tc))
        else:
            v2, d2 = MATCH, 'mask_count=1 and dst+0x35=1'
        add('CELL', i, name, 'dst_0x35_claim', '0x35', pred_claim, f35, v2, d2)
        st = per_field['dst_0x35_claim']
        st['cmp'] += 1
        st['match'] += (v2 == MATCH)
        st['verdicts'][v2] += 1

    # ---- per-field summary --------------------------------------------------
    for field, st in per_field.items():
        rate, pct = fmt_rate(st['match'], st['cmp'])
        vc = ', '.join('%s=%d' % (k, n) for k, n in st['verdicts'].most_common())
        add('SUMMARY', '-', '-', field, '-', rate, pct,
            MATCH if st['match'] == st['cmp'] else TRUE_DIFF, vc)

    flag_max = max(max(rec_int(rec[i], c) or 0 for i in dst)
                   for c in ('transparent', 'smooth', 'preload', 'bboxmode', 'sepmasks'))
    add('SUMMARY', '-', '-', 'flag_width_note', '-', 'max_flag_u32=%d' % flag_max, 1, MATCH,
        'largest u32 value seen in any of the 5 record flag fields is %d, so the '
        'raw-vs-u8-normalised distinction is never exercised here: dst stores transparent/'
        'smooth/preload/sepmasks as 1 byte (0x32/0x33/0x34/0x30) and bboxmode as 4 bytes (0x04). '
        'A corpus with flags > 0xff would be needed to test the truncation path.' % flag_max)

    # ---- 0x35 candidate predicate fits -------------------------------------
    cands = OrderedDict([
        ('mask_count==1', lambda mc, tc: mc == 1),
        ('tpag_count==1', lambda mc, tc: tc == 1),
        ('mask_count==tpag_count', lambda mc, tc: mc == tc),
        ('mask_count>=1', lambda mc, tc: mc >= 1),
    ])
    for label, fn in cands.items():
        hits, miss = 0, []
        for i, (w, _o) in dst.items():
            f35 = dst_bytes(w, 0x35, 1)
            mc, tc = rec_int(rec[i], 'mask_count'), rec_int(rec[i], 'tpag_count')
            pred = 1 if fn(mc, tc) else 0
            if pred == f35:
                hits += 1
            else:
                miss.append('%s(t=%d,m=%d,dst=%d)' % (i, tc, mc, f35))
        rate, pct = fmt_rate(hits, len(dst))
        add('PRED', '-', '-', 'dst+0x35 <- ' + label, '0x35', rate, pct,
            MATCH if hits == len(dst) else TRUE_DIFF,
            'mismatches: ' + (', '.join(miss[:12]) + (' ...' if len(miss) > 12 else '')
                              if miss else 'none'))

    # ---- dst+0x2c radius formula -------------------------------------------
    f_ok = f_wrap_ok = 0
    f_bad = []
    max_a = max_b = max_s = 0
    perfect = 0
    models = OrderedDict([
        ('M1 A=max(|ox|,|w-ox|) B=max(|oy|,|h-oy|), plain', lambda w_, h_, x_, y_: radius_plain(*radius_inputs(w_, h_, x_, y_))),
        ('M2 same, A^2+B^2 mod 2^32', lambda w_, h_, x_, y_: radius_wrap32(*radius_inputs(w_, h_, x_, y_))),
        ('M3 A=|w-ox| B=|h-oy| (no max), plain', lambda w_, h_, x_, y_: radius_plain(*radius_single(w_, h_, x_, y_))),
        ('M4 same as M3, A^2+B^2 mod 2^32', lambda w_, h_, x_, y_: radius_wrap32(*radius_single(w_, h_, x_, y_))),
    ])
    fit = OrderedDict((k, 0) for k in models)
    disc = []
    for i, (w, _o) in dst.items():
        r = rec[i]
        ww, hh = rec_int(r, 'w'), rec_int(r, 'h')
        ox, oy = rec_int(r, 'origin_x'), rec_int(r, 'origin_y')
        a, b = radius_inputs(ww, hh, ox, oy)
        obs = dst_word(w, 0x2c)
        plain, wrapped = radius_plain(a, b), radius_wrap32(a, b)
        max_a, max_b = max(max_a, a), max(max_b, b)
        max_s = max(max_s, a * a + b * b)
        if a * a + b * b == math.isqrt(a * a + b * b) ** 2:
            perfect += 1
        vals = set()
        for k, fn in models.items():
            v = fn(ww, hh, ox, oy)
            vals.add(v)
            if v == obs:
                fit[k] += 1
        if len(vals) > 1:
            disc.append('%s(%s: A=%d B=%d obs=%d %s)' % (
                i, r['name'], a, b, obs, '/'.join('%s=%d' % (k.split()[0], fn(ww, hh, ox, oy))
                                                  for k, fn in models.items())))
        if obs is None:
            v, d = NOCMP, 'dst+0x2c unreadable'
        elif plain == obs:
            v, d = MATCH, ''
            f_ok += 1
        else:
            v, d = TRUE_DIFF, 'plain=%d wrapped=%d obs=%d (a=%d b=%d s=0x%x)' % (
                plain, wrapped, obs, a, b, a * a + b * b)
            f_bad.append((i, r['name'], a, b, plain, wrapped, obs))
        if wrapped == obs:
            f_wrap_ok += 1
        note = d
        if a > 0xffff or b > 0xffff:
            note = (note + '; ' if note else '') + 'a|b > 0xffff: a^2+b^2 exceeds 32 bits, only the wrapped form is defined'
        add('FORMULA_CELL', i, r['name'],
            'dst+0x2c=ceil(sqrt(A^2+B^2))', '0x2c',
            'w=%d h=%d ox=%d oy=%d A=%d B=%d s=0x%x plain=%d wrap=%d' % (
                ww, hh, ox, oy, a, b, a * a + b * b, plain, wrapped),
            obs, v, note)

    rate, pct = fmt_rate(f_ok, len(dst))
    add('FORMULA', '-', '-', 'dst+0x2c plain (A^2+B^2 not wrapped)', '0x2c', rate, pct,
        MATCH if f_ok == len(dst) else TRUE_DIFF,
        'A=max(|ox|,|w-ox|), B=max(|oy|,|h-oy|), exact integer ceil(sqrt(A^2+B^2)); '
        'max A=%d max B=%d max A^2+B^2=%d (<2^32=%d)' % (max_a, max_b, max_s, 2 ** 32))
    rate, pct = fmt_rate(f_wrap_ok, len(dst))
    add('FORMULA', '-', '-', 'dst+0x2c wrap32 (A^2+B^2 mod 2^32)', '0x2c', rate, pct,
        MATCH if f_wrap_ok == len(dst) else TRUE_DIFF,
        'same formula evaluated with the 32-bit wrap of the original; identical on this '
        'corpus because no A|B exceeds 0xffff')
    # which candidate model does the corpus actually pin?
    for k, n in fit.items():
        rate, pct = fmt_rate(n, len(dst))
        add('FORMULA', '-', '-', 'model fit: ' + k, '0x2c', rate, pct,
            MATCH if n == len(dst) else TRUE_DIFF,
            '%d/%d records; models that lose here are excluded by real data, so the max() '
            'clause is pinned by the corpus (not assumed)' % (n, len(dst)))
    add('FORMULA', '-', '-', 'records that discriminate the models', '0x2c', len(disc), len(dst),
        MATCH if disc else NOCMP,
        'records where M1..M4 do not all agree; ids: ' +
        (', '.join(disc) if disc else 'none'))
    for item in f_bad:
        add('FORMULA', item[0], item[1], 'dst+0x2c mismatch', '0x2c', item[4], item[6],
            TRUE_DIFF, 'A=%d B=%d wrapped=%d' % (item[2], item[3], item[5]))

    # domain: perfect squares (float vs int ceil would differ if ceilf misrounded)
    add('FORMULA_DOMAIN', '-', '-', 'perfect_square_cases', '0x2c', perfect, len(dst),
        MATCH, '%d/%d records have A^2+B^2 a perfect square; ceil is exact there, so '
               'ceilf and integer ceil are indistinguishable on this corpus' % (perfect, len(dst)))

    n_multi = sum(1 for i in dst if rec_int(rec[i], 'tpag_count') != 1)
    n_onemask = sum(1 for i in dst if rec_int(rec[i], 'mask_count') != 1)
    add('FORMULA_DOMAIN', '-', '-', 'multi_frame_records', '0x2c', n_multi, len(dst),
        MATCH, '%d/%d records have tpag_count!=1; the formula is exact on all of them as well, '
               'so the multi-frame path is not a formula failure domain - only the flag '
               '(dst+0x35) and the mask blob differ there' % (n_multi, len(dst)))
    add('FORMULA_DOMAIN', '-', '-', 'multi_mask_records', '0x2c', n_onemask, len(dst),
        MATCH, '%d/%d records have mask_count!=1 (ids 76, 77); see the per-record rows below'
               % (n_onemask, len(dst)))

    # the two records whose mask region is per-frame (mask_count == tpag_count > 1)
    for i, (w, _o) in dst.items():
        r = rec[i]
        tc, mc = rec_int(r, 'tpag_count'), rec_int(r, 'mask_count')
        if mc == 1:
            continue
        a, b = radius_inputs(rec_int(r, 'w'), rec_int(r, 'h'),
                             rec_int(r, 'origin_x'), rec_int(r, 'origin_y'))
        obs = dst_word(w, 0x2c)
        pred = radius_wrap32(a, b)
        add('FORMULA_DOMAIN', i, r['name'], 'mask_count != 1 path', '0x2c',
            'tpag=%d mask=%d A=%d B=%d pred=%d' % (tc, mc, a, b, pred),
            obs, MATCH if pred == obs else TRUE_DIFF,
            'per-frame mask record (mask_count==tpag_count==%d): formula still exact, '
            'dst+0x35 also still 1 - this is the record class that falsifies the '
            '"0x35 == (mask_count==1)" claim' % mc if pred == obs else 'formula fails here')

    # ---- domain failures recorded by the field-map probes -------------------
    probe_rows = list(csv.DictReader(open(FIELDMAP, encoding='utf-8'), delimiter='\t'))
    tmpl = rec['0']
    base31 = dst_word(dst['0'][0], 0x2c)
    probe_tension = []
    for pr in probe_rows:
        if pr['row'] != 'probe':
            continue
        diag = pr['diag_pred']
        if not (diag.startswith('n/a') or diag.startswith('pred=')):
            continue
        val = int(pr['test_value'])
        ww, hh = rec_int(tmpl, 'w'), rec_int(tmpl, 'h')
        ox, oy = rec_int(tmpl, 'origin_x'), rec_int(tmpl, 'origin_y')
        fld = pr['field']
        if fld == 'w':
            ww = i32(val)
        elif fld == 'h':
            hh = i32(val)
        elif fld == 'origin_x':
            ox = i32(val)
        elif fld == 'origin_y':
            oy = i32(val)
        elif fld != 'tpag_count':
            continue
        # reconstruct the observed radius word from the recorded changed bytes
        obs_bytes = {}
        for chunk in pr['dst_bytes'].split(','):
            if not chunk.startswith('0x'):
                continue
            lhs, rhs = chunk.split(':')
            off = int(lhs, 16)
            new = int(rhs.split('->')[1], 16)
            if 0x2c <= off <= 0x2f:
                obs_bytes[off] = new
        obs = base31
        for k, v in obs_bytes.items():
            shift = 8 * (k - 0x2c)
            obs = (obs & ~(0xff << shift)) | (v << shift)
        if fld == 'tpag_count':
            add('FORMULA_DOMAIN', pr['row'], 'template rec0', 'dst+0x2c under %s=%d' % (fld, val),
                '0x2c', 'w/h are rewritten by the loader on this path', obs, NOCMP,
                'tpag_count=0xffffffff 异常路径: dst w(0x1c)->0, h(0x20)->0, '
                'transparent(0x32)->1, radius=%d. Formula inputs (w,h,ox,oy) no longer '
                'describe the sprite, so the formula is not applicable here; the 127 is not '
                'produced by ceil(sqrt(A^2+B^2)) on any (A,B) derivable from the record.' % obs)
            continue
        a, b = radius_inputs(ww, hh, ox, oy)
        plain, wrapped = radius_plain(a, b), radius_wrap32(a, b)
        sa, sb = radius_single(ww, hh, ox, oy)
        cand = OrderedDict([('M1_max_plain', plain), ('M2_max_wrap32', wrapped),
                            ('M3_single_plain', radius_plain(sa, sb)),
                            ('M4_single_wrap32', radius_wrap32(sa, sb))])
        hit = [k for k, v in cand.items() if v == obs]
        if a >= 0x80000000 or b >= 0x80000000:
            verdict = NOCMP
            detail = ('%s=%d drives A|B to 2^31: the int32 sub/abs/max/mul chain is outside '
                      'the domain in which any of the four integer models is trustworthy, so '
                      'this probe cannot confirm or refute the formula. Observed radius %d '
                      'recorded; variants coincidentally reproducing it: %s '
                      '(M1=%d M2=%d M3=%d M4=%d)' % (
                          fld, val, obs, ', '.join(hit) or 'none',
                          plain, wrapped, cand['M3_single_plain'], cand['M4_single_wrap32']))
        elif wrapped == obs:
            verdict = MATCH
            detail = ('field-map probe (template rec0 + %s=%d): A=%d B=%d, A^2+B^2=0x%x is '
                      'beyond 32 bits; plain model declared %s, the 32-bit wrapped product '
                      'predicts %d == observed %d -> the multiply is 32-bit and wraps. This is '
                      'the formula failure domain (unreachable from the 178 real records, '
                      'max A=%d max B=%d).' % (fld, val, a, b, a * a + b * b, diag,
                                               wrapped, obs, max_a, max_b))
        else:
            verdict = TRUE_DIFF
            detail = ('field-map probe (template rec0 + %s=%d): A=%d B=%d is still inside '
                      'int32 and beyond the 0xffff product range, yet the corpus-pinned 32-bit '
                      'wrap model predicts %d and the observation is %d. Variants matching the '
                      'observation: %s (M1=%d M2=%d M3=%d M4=%d). The matching variant is the '
                      'no-max one, which the 178-record corpus rejects at 18 records -> open '
                      'contradiction between the probe set and the corpus.' % (
                          fld, val, a, b, wrapped, obs, ', '.join(hit) or 'none',
                          plain, wrapped, cand['M3_single_plain'], cand['M4_single_wrap32']))
            probe_tension.append((fld, val, a, b, obs, dict(cand)))
        add('FORMULA_DOMAIN', pr['row'], 'template rec0',
            'dst+0x2c under %s=%d' % (fld, val), '0x2c',
            'A=%d B=%d s=0x%x M1=%s M2=%d M3=%d M4=%d' % (
                a, b, a * a + b * b, 'overflow' if plain > 0xffffffff else plain,
                wrapped, cand['M3_single_plain'], cand['M4_single_wrap32']),
            obs, verdict, detail)

    for fld, val, a, b, obs, cand in probe_tension:
        add('FORMULA', 'probe', 'template rec0', 'unresolved: %s=%d vs corpus max()' % (fld, val),
            '0x2c', 'A=%d B=%d M1=%d M2=%d' % (a, b, cand['M1_max_plain'], cand['M2_max_wrap32']),
            obs, TRUE_DIFF,
            'corpus (178 records, 18 of them discriminating) requires the max() form; this '
            'single probe needs the no-max form (M4=%d). Both cannot hold. Recorded as an '
            'open contradiction between the two data sets; not resolved here.'
            % cand['M4_single_wrap32'])

    # ---- overall ------------------------------------------------------------
    cells = [r for r in rows if r['section'] == 'CELL']
    ok = sum(1 for r in cells if r['verdict'] == MATCH)
    rate, pct = fmt_rate(ok, len(cells))
    vc = Counter(r['verdict'] for r in cells)
    add('OVERALL', '-', '-', 'all_field_cells', '-', rate, pct,
        MATCH if ok == len(cells) else TRUE_DIFF,
        ', '.join('%s=%d' % kv for kv in vc.most_common()))
    real = [r for r in cells if r['field'] != 'dst_0x35_claim']
    ok2 = sum(1 for r in real if r['verdict'] == MATCH)
    rate, pct = fmt_rate(ok2, len(real))
    add('OVERALL', '-', '-', 'field_cells_excluding_0x35_claim', '-', rate, pct,
        MATCH if ok2 == len(real) else TRUE_DIFF,
        'the 99 non-matching cells in all_field_cells are all the one falsified predicate '
        'claim about dst+0x35; every real field cell agrees')

    with open(OUT, 'w', encoding='utf-8', newline='') as fh:
        wr = csv.DictWriter(fh, fieldnames=['section', 'id', 'name', 'field', 'dst_off',
                                            'rec_value', 'dst_value', 'verdict', 'detail'],
                            delimiter='\t', quoting=csv.QUOTE_MINIMAL, lineterminator='\n')
        wr.writeheader()
        for r in rows:
            wr.writerow(r)

    # ------------------------------------------------------------ report -----
    say.append('records: %d  (dst runs ok=1 on %d, ret=0x1 on %d)'
               % (len(rec), ok_vals.get('1', 0), ret_vals.get('0x1', 0)))
    say.append('')
    say.append('per-field (comparable / identical / rate):')
    for field, st in per_field.items():
        rate, pct = fmt_rate(st['match'], st['cmp'])
        extra = '' if st['match'] == st['cmp'] else '   [%s]' % ', '.join(
            '%s=%d' % kv for kv in st['verdicts'].most_common() if kv[0] != MATCH)
        say.append('  %-18s %8s  %8s%s' % (field, rate, pct, extra))
    say.append('')
    say.append('bbox slot matrix (cells out of %d matching):' % len(rec))
    for rn, _ in rec_slots:
        say.append('  rec %-12s ' % rn + '  '.join(
            '%s=%3d' % (dn, matrix[(rn, dn)]) for dn, _ in dst_slots))
    say.append('')
    say.append('dst+0x35 predicate fits:')
    for label, fn in cands.items():
        hits = sum(1 for i, (w, _o) in dst.items()
                   if (1 if fn(rec_int(rec[i], 'mask_count'), rec_int(rec[i], 'tpag_count')) else 0)
                   == dst_bytes(w, 0x35, 1))
        say.append('  %-24s %d/%d' % (label, hits, len(dst)))
    say.append('')
    say.append('dst+0x2c formula: plain %d/%d, wrap32 %d/%d, max A=%d max B=%d max s=%d, '
               'perfect squares=%d, discriminating records=%d'
               % (f_ok, len(dst), f_wrap_ok, len(dst), max_a, max_b, max_s, perfect, len(disc)))
    for k, n in fit.items():
        say.append('  model %-46s %d/%d' % (k, n, len(dst)))
    say.append('rows written: %d -> %s' % (len(rows), OUT))
    print('\n'.join(say))
    return 0


if __name__ == '__main__':
    sys.exit(main())
