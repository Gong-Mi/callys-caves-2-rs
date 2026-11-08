#!/usr/bin/env python3
"""Level A function-level differential: original readSkeletonData vs the
reconstructed chain on one synthetic Json tree.

  original arm : Unicorn memory oracle, original bytes @0x28b84c
  rebuild arm  : c/spine_read_skeleton/ assembled chain under qemu-arm

Contract: reconstruction/contracts/native-equivalence-gate.md, Level A.
Evidence layer: synthetic memory oracle.  The input domain is exactly the
frozen tree set of this contract; this is neither full-input-domain nor device
equivalence.

Usage:
  python3 level_a_diff.py --run [--out DIR]
  python3 level_a_diff.py --oracle-dump --variant main --scale 2.0
"""
import argparse
import hashlib
import json
import os
import pathlib
import re
import struct
import subprocess
import sys
import time

HERE = pathlib.Path(__file__).resolve().parent
MOD = HERE.parent                      # c/spine_level_a
C = MOD.parent                         # c
RV1 = C.parent                         # reconstruction/reverse-v1
sys.path.insert(0, str(HERE))
sys.path.insert(0, str(C / 'spine_read_skeleton' / 'tools'))

import level_a_model as model          # noqa: E402
import level_a_dump as dump            # noqa: E402
import check_skeleton as chain_check   # noqa: E402  (build recipe + FLAGS)

PIN = '3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a'
SO = pathlib.Path('/data/data/com.termux/files/home/callys-caves-2-rs/'
                  'reconstruction/live-mem/libyoyo_armv7.so')
RECEIPTS = RV1 / 'harness' / 'receipts'
BUILD = MOD / 'build'


def sha_file(path):
    return hashlib.sha256(pathlib.Path(path).read_bytes()).hexdigest()


# ----------------------------------------------------------------------
# field flattening + attribution
# ----------------------------------------------------------------------
FLOAT_KEYS = {'width', 'height', 'length', 'x', 'y', 'rotation', 'scaleX',
              'scaleY', 'shearX', 'shearY', 'mix', 'rotateMix',
              'translateMix', 'scaleMix', 'shearMix', 'r', 'g', 'b', 'a',
              'u', 'v', 'u2', 'v2', 'duration', 'position', 'spacing',
              'floatValue', 'time'}

META_POINTER_WORDS = {5: 'bones', 7: 'slots', 9: 'skins', 10: 'defaultSkin',
                      12: 'events', 14: 'animations', 16: 'ik',
                      18: 'transform', 20: 'path'}

SHARED_DURATION = ['spine_read_tl_slots', 'spine_read_tl_bones',
                   'spine_read_tl_ik', 'spine_read_tl_transform',
                   'spine_read_tl_path', 'spine_read_tl_path_mix',
                   'spine_read_tl_deform', 'spine_read_tl_draworder',
                   'spine_read_tl_event']

ATTRIBUTION = [
    ('meta.spine', ['spine_read_meta']),
    ('meta.hash', ['spine_read_meta']),
    ('meta.width', ['spine_read_meta']),
    ('meta.height', ['spine_read_meta']),
    ('meta.bonesCount', ['spine_read_bones']),
    ('meta.slotsCount', ['spine_read_slots']),
    ('meta.skinsCount', ['spine_read_skins']),
    ('meta.eventsCount', ['spine_read_animations']),
    ('meta.animationsCount', ['spine_animations_loop']),
    ('meta.ikCount', ['spine_read_ik']),
    ('meta.transformCount', ['spine_read_transform']),
    ('meta.pathCount', ['spine_read_path']),
    ('meta.defaultSkinIndex', ['spine_read_skins']),
    ('meta.word05_', ['spine_read_meta']),
    ('meta.word07_', ['spine_read_slots']),
    ('meta.word09_', ['spine_read_skins']),
    ('meta.word10_', ['spine_read_skins']),
    ('meta.word12_', ['spine_read_animations']),
    ('meta.word14_', ['spine_animations_loop']),
    ('meta.word16_', ['spine_read_ik']),
    ('meta.word18_', ['spine_read_transform']),
    ('meta.word20_', ['spine_read_path']),
    ('bones[', ['spine_read_bones']),
    ('slots[', ['spine_read_slots']),
    ('ik[', ['spine_read_ik']),
    ('transform[', ['spine_read_transform']),
    ('path[', ['spine_read_path']),
    ('skins[', ['spine_read_skins', 'spine_read_attach_dispatch',
                'spine_skins_glue', 'spine_read_region', 'spine_read_mesh',
                'spine_read_bbox_path', 'spine_read_vertices']),
    ('events[', ['spine_read_animations']),
    ('animations[].name', ['spine_animations_loop']),
    ('animations[].duration', SHARED_DURATION),
    ('animations[].timelineCount', ['spine_read_animations',
                                    'spine_animations_loop']),
    ('animations[].timelines[].curves', ['spine_read_curve']),
    ('animations[].timelines[].frames', ['spine_read_tl_bones',
                                         'spine_read_tl_event']),
    ('animations[].timelines[].names', ['spine_read_tl_slots']),
    ('animations[].timelines[].type', ['spine_animations_loop']),
    ('animations[].timelines[].frameCount', ['spine_read_tl_bones']),
    ('animations[].timelines[].frameFloatCount', ['spine_read_tl_bones']),
    ('animations[].timelines[].index', ['spine_read_tl_bones']),
    ('error.', ['spine_read_entry', 'spine_read_skeleton',
                'spine_json_error']),
]


def attribution(field):
    norm = re.sub(r'\[\d+\]', '[]', field)
    for prefix, segs in ATTRIBUTION:
        if norm.startswith(prefix) or field.startswith(prefix):
            if norm.startswith('animations[].timelines[].frames'):
                if re.search(r'\.(time|intValue|floatValue|stringValue)$', field):
                    return ['spine_read_tl_event']
                return ['spine_read_tl_bones']
            return list(segs)
    return ['unattributed']


def _float_keys_in(prefix):
    return any(prefix.endswith(k) for k in FLOAT_KEYS) or \
        re.search(r'\.(x|y|rotation|scaleX|scaleY|shearX|shearY|mix|'
                  r'rotateMix|translateMix|scaleMix|shearMix|r|g|b|a|u|v|u2|v2)'
                  r'(_bits)?$', prefix) is not None


def flatten(d):
    """Return {field: value}. Floats stay binary32 bit words (ints)."""
    out = {}

    def put(key, val):
        out[key] = val

    if d.get('meta'):
        m = d['meta']
        put('meta.spine', m['spine'])
        put('meta.hash', m['hash'])
        put('meta.width', m['words'][2])
        put('meta.height', m['words'][3])
        names = {4: 'bonesCount', 6: 'slotsCount', 8: 'skinsCount',
                 11: 'eventsCount', 13: 'animationsCount', 15: 'ikCount',
                 17: 'transformCount', 19: 'pathCount'}
        for idx, name in names.items():
            put('meta.' + name, m['words'][idx])
        for idx, name in META_POINTER_WORDS.items():
            put('meta.word%02d_%s_nonnull' % (idx, name),
                1 if m['words'][idx] else 0)
        put('meta.defaultSkinIndex', d.get('defaultSkinIndex', -1))
    for i, b in enumerate(d.get('bones', [])):
        p = 'bones[%d].' % i
        put(p + 'name', b['name'])
        put(p + 'parent', b['parent'])
        put(p + 'index', b['index'])
        for k in ('length', 'x', 'y', 'rotation', 'scaleX', 'scaleY',
                  'shearX', 'shearY'):
            put(p + k, b[k])
        put(p + 'inheritRotation', b['inheritRotation'])
        put(p + 'inheritScale', b['inheritScale'])
    for i, s in enumerate(d.get('slots', [])):
        p = 'slots[%d].' % i
        put(p + 'name', s['name'])
        put(p + 'bone', s['bone'])
        put(p + 'attachment', s['attachment'])
        for k in ('r', 'g', 'b', 'a'):
            put(p + k, s[k])
        put(p + 'blend', s['blend'])
    for i, c in enumerate(d.get('ik', [])):
        p = 'ik[%d].' % i
        put(p + 'name', c['name'])
        put(p + 'boneCount', c['boneCount'])
        for j, v in enumerate(c['bones']):
            put(p + 'bones[%d]' % j, v)
        put(p + 'target', c['target'])
        put(p + 'bendDirection', c['bendDirection'])
        put(p + 'mix', c['mix'])
    for i, c in enumerate(d.get('transform', [])):
        p = 'transform[%d].' % i
        put(p + 'name', c['name'])
        put(p + 'boneCount', c['boneCount'])
        for j, v in enumerate(c['bones']):
            put(p + 'bones[%d]' % j, v)
        put(p + 'target', c['target'])
        for k in ('rotateMix', 'translateMix', 'scaleMix', 'shearMix',
                  'rotation', 'x', 'y', 'scaleX', 'scaleY', 'shearY'):
            put(p + k, c[k])
    for i, c in enumerate(d.get('path', [])):
        p = 'path[%d].' % i
        put(p + 'name', c['name'])
        put(p + 'boneCount', c['boneCount'])
        for j, v in enumerate(c['bones']):
            put(p + 'bones[%d]' % j, v)
        put(p + 'target', c['target'])
        for k in ('positionMode', 'spacingMode', 'rotateMode', 'rotation',
                  'position', 'spacing', 'rotateMix', 'translateMix'):
            put(p + k, c[k])
    for i, sk in enumerate(d.get('skins', [])):
        p = 'skins[%d].' % i
        put(p + 'name', sk['name'])
        put(p + 'entryCount', len(sk['entries']))
        for j, e in enumerate(sk['entries']):
            q = p + 'entries[%d].' % j
            put(q + 'slot', e['slot'])
            put(q + 'name', e['name'])
            a = e['attachment']
            put(q + 'attachment.type', a['type'])
            put(q + 'attachment.name', a['name'])
            put(q + 'attachment.path', a['path'])
            if a['type'] == 0:
                for k in ('x', 'y', 'scaleX', 'scaleY', 'rotation', 'width',
                          'height', 'r', 'g', 'b', 'a'):
                    put(q + 'attachment.' + k, a[k])
                for k, v in enumerate(a['region']):
                    put(q + 'attachment.region[%d]' % k, v)
                for k, v in enumerate(a['offset']):
                    put(q + 'attachment.offset[%d]' % k, v)
                for k, v in enumerate(a['uvs']):
                    put(q + 'attachment.uvs[%d]' % k, v)
            elif a['type'] in (2, 3):
                for k in ('boneCount', 'vertexFloatCount',
                          'worldVerticesLength', 'triangleCount', 'hull',
                          'u', 'v', 'u2', 'v2', 'r', 'g', 'b', 'a'):
                    put(q + 'attachment.' + k, a[k])
                for k, v in enumerate(a['vertices']):
                    put(q + 'attachment.vertices[%d]' % k, v)
                for k, v in enumerate(a['region']):
                    put(q + 'attachment.region[%d]' % k, v)
                for k, v in enumerate(a['triangles']):
                    put(q + 'attachment.triangles[%d]' % k, v)
            else:
                for k in ('boneCount', 'vertexFloatCount',
                          'worldVerticesLength'):
                    put(q + 'attachment.' + k, a[k])
                for k, v in enumerate(a['vertices']):
                    put(q + 'attachment.vertices[%d]' % k, v)
                for k, v in enumerate(a.get('flags', [])):
                    put(q + 'attachment.flags[%d]' % k, v)
    for i, e in enumerate(d.get('events', [])):
        p = 'events[%d].' % i
        put(p + 'name', e['name'])
        put(p + 'intValue', e['intValue'])
        put(p + 'floatValue', e['floatValue'])
        put(p + 'stringValue', e['stringValue'])
    for i, a in enumerate(d.get('animations', [])):
        p = 'animations[%d].' % i
        put(p + 'name', a['name'])
        put(p + 'duration', a['duration'])
        put(p + 'timelineCount', a['timelineCount'])
        for j, t in enumerate(a['timelines']):
            q = p + 'timelines[%d].' % j
            put(q + 'type', t['type'])
            put(q + 'frameCount', t['frameCount'])
            put(q + 'frameFloatCount', t['frameFloatCount'])
            put(q + 'index', t['index'])
            if t['type'] == 6:
                for k, fr in enumerate(t['frames']):
                    put(q + 'frames[%d].time' % k, fr['time'])
                    put(q + 'frames[%d].intValue' % k, fr['intValue'])
                    put(q + 'frames[%d].floatValue' % k, fr['floatValue'])
                    put(q + 'frames[%d].stringValue' % k, fr['stringValue'])
            elif t['type'] == 5:
                for k, v in enumerate(t.get('frames', [])):
                    put(q + 'frames[%d]' % k, v)
                for k, v in enumerate(t.get('names', [])):
                    put(q + 'names[%d]' % k, v)
            else:
                for k, v in enumerate(t.get('frames', [])):
                    put(q + 'frames[%d]' % k, v)
                for k, v in enumerate(t.get('curves', [])):
                    put(q + 'curves[%d]' % k, v)
    if d.get('error'):
        put('error.is_null', d['error']['is_null'])
        put('error.error', d['error']['error'])
    return out


def field_float(field):
    return bool(re.search(r'\.(width|height|length|rotation|scaleX|scaleY|'
                          r'shearX|shearY|mix|rotateMix|translateMix|scaleMix|'
                          r'shearMix|r|g|b|a|u|v|u2|v2|duration|position|'
                          r'spacing|floatValue|time)$', field)) or \
        'attachment.x' in field or 'attachment.y' in field


def describe(field, value):
    if isinstance(value, str):
        return value
    if field_float(field) and isinstance(value, int):
        return {'bits': '0x%08x' % value,
                'f32': struct.unpack('<f', struct.pack('<I', value))[0]}
    return value


def diff_dicts(a, b):
    fields = sorted(set(a) | set(b))
    diffs = []
    for f in fields:
        va, vb = a.get(f, '<absent>'), b.get(f, '<absent>')
        if va != vb:
            diffs.append({
                'field': f,
                'original': describe(f, va) if va != '<absent>' else '<absent>',
                'rebuild': describe(f, vb) if vb != '<absent>' else '<absent>',
                'original_raw': va, 'rebuild_raw': vb,
                'attribution': attribution(f),
            })
    return diffs


# ----------------------------------------------------------------------
# C arm build/run
# ----------------------------------------------------------------------
def build_c(variant, scale_bits, name, overrides=None):
    BUILD.mkdir(parents=True, exist_ok=True)
    tmp = BUILD / 'tmp'
    tmp.mkdir(exist_ok=True)
    os.environ['TMPDIR'] = str(tmp)
    (BUILD / 'level_a_tree.inc').write_text(model.emit_all())
    sources = [p for p in chain_check.SOURCES if p.name != 'check.c']
    sources.append(MOD / 'fixture' / 'level_a_dump.c')
    if overrides:
        sources = [overrides.get(p, p) for p in sources]
    includes = list(chain_check.INCLUDES) + [MOD / 'fixture', BUILD]
    flags = [f if f != '-Wl,-e,chain_start' else '-Wl,-e,level_a_start'
             for f in chain_check.FLAGS]
    variant_id = list(model.VARIANTS).index(variant) + 1
    binary = BUILD / (name + '.arm')
    argv = ['clang', *flags, '-O2',
            '-DLEVEL_A_VARIANT=%d' % variant_id,
            '-DLEVEL_A_SCALE_BITS=%du' % scale_bits,
            *['-I' + str(i) for i in includes],
            *[str(s) for s in sources], '-o', str(binary)]
    p = subprocess.run(argv, capture_output=True, text=True)
    (BUILD / (name + '.build.log')).write_text(p.stdout + p.stderr)
    if p.returncode:
        raise RuntimeError('build failed (%s):\n%s' % (name, p.stderr[-6000:]))
    return binary


def run_c(binary):
    p = subprocess.run(['qemu-arm', str(binary)], capture_output=True,
                       timeout=120)
    if p.returncode != 0:
        raise RuntimeError('qemu-arm exit %d: %s' % (
            p.returncode, p.stderr.decode('latin1')[-2000:]))
    return p.stdout


# ----------------------------------------------------------------------
# original arm
# ----------------------------------------------------------------------
def run_oracle(tree, scale):
    import level_a_oracle as oracle_mod
    o = oracle_mod.Oracle()
    ret, error = o.run(model.flatten(tree), scale=scale)
    d = dump.read_oracle(o, ret)
    if not ret:
        d['error']['error'] = error
        d['error']['reported'] = ''
    return d, o


def oracle_dump_bytes(variant, scale):
    tree = model.VARIANTS[variant]()
    d, _ = run_oracle(tree, scale)
    d['tree'] = d['tree'].hex()
    payload = json.dumps(d, sort_keys=True, ensure_ascii=False).encode()
    return payload


# ----------------------------------------------------------------------
# one variant run
# ----------------------------------------------------------------------
def run_variant(variant, scale, tag):
    tree = model.VARIANTS[variant]()
    orig, oracle = run_oracle(tree, scale)
    sfx = '%s_s%s' % (variant, str(scale).replace('.', 'p'))
    binary = build_c(variant, struct.unpack('<I', struct.pack('<f', scale))[0],
                     sfx)
    cblob = run_c(binary)
    reb = dump.parse_binary(cblob)

    py_blob = model.canonical(tree)
    py_hashes = dump.tree_node_hashes(py_blob)
    c_hashes = dump.tree_node_hashes(reb['tree'])
    py_tree_sha = hashlib.sha256(py_blob).hexdigest()
    c_tree_sha = hashlib.sha256(reb['tree']).hexdigest()
    node_join = hashlib.sha256('\n'.join(py_hashes).encode()).hexdigest()
    fo, fr = flatten(orig), flatten(reb)
    diffs = diff_dicts(fo, fr)
    return {
        'variant': variant, 'scale': scale, 'tag': tag,
        'binary_sha256': sha_file(binary),
        'original': {'returned_null': orig.get('meta') is None,
                     'error': orig.get('error', {}).get('error', ''),
                     'fields': len(fo)},
        'rebuild': {'returned_null': reb.get('meta') is None,
                    'error': reb.get('error', {}).get('error', ''),
                    'fields': len(fr)},
        'tree': {'node_count': len(py_hashes),
                 'python_sha256': py_tree_sha,
                 'c_arm_sha256': c_tree_sha,
                 'match': py_tree_sha == c_tree_sha,
                 'node_hashes_match': py_hashes == c_hashes,
                 'node_hashes_sha256': node_join,
                 'node_sha256': py_hashes},
        'diff': diffs,
        'diff_count': len(diffs),
        'diff_groups': sorted({d['field'].split('.')[0].split('[')[0]
                               for d in diffs}),
        '_fields_original': fo,
        '_fields_rebuild': fr,
    }


# ----------------------------------------------------------------------
# negative controls
# ----------------------------------------------------------------------
def mutation_source(relpath, old, new):
    src = C / relpath
    text = src.read_text()
    if text.count(old) != 1:
        raise RuntimeError('mutation site not unique in %s: %r' % (relpath, old))
    out = BUILD / ('mut_' + src.name)
    out.write_text(text.replace(old, new, 1))
    return src, out


def negative_broken_segment(scale):
    base = run_variant('main', scale, 'baseline')
    if base['diff_count']:
        return {'passed': False, 'reason': 'baseline not clean; fix that first',
                'baseline_diff': base['diff_count']}
    results = []
    specs = [
        ('slots_blend_additive_1_to_3', 'spine_read_slots/src/spine_read_slots.c',
         '*(int*)((char*)slotData + 0x20) = 1;',
         '*(int*)((char*)slotData + 0x20) = 3;', 'spine_read_slots'),
        ('bones_scaleX_offset_0x1c_to_0x20', 'spine_read_bones/src/spine_read_bones.c',
         '#define BD_SCALEX_OFF        0x1c',
         '#define BD_SCALEX_OFF        0x20', 'spine_read_bones'),
        ('tl_bones_rotate_angle_key', 'spine_read_tl_bones/src/spine_read_tl_bones.c',
         'Json_getFloat(frame, "angle", 0.0f)',
         'Json_getFloat(frame, "angel", 0.0f)', 'spine_read_tl_bones'),
    ]
    for name, rel, old, new, segment in specs:
        src, mutated = mutation_source(rel, old, new)
        try:
            variant = model.VARIANTS['main']()
            orig, _ = run_oracle(variant, scale)
            binary = build_c('main', struct.unpack('<I', struct.pack('<f', scale))[0],
                             name, overrides={src: mutated})
            reb = dump.parse_binary(run_c(binary))
            diffs = diff_dicts(flatten(orig), flatten(reb))
            hit = [d for d in diffs if segment in d['attribution']]
            ok = bool(diffs) and bool(hit)
            results.append({'name': name, 'segment': segment,
                            'diff_count': len(diffs),
                            'fields': [d['field'] for d in diffs][:12],
                            'attributed_hit': bool(hit),
                            'passed': ok})
        finally:
            pass
    return {'passed': all(r['passed'] for r in results), 'mutants': results}


def negative_input_perturbation(scale):
    base_o, _ = run_oracle(model.VARIANTS['main'](), scale)
    base_r = dump.parse_binary(run_c(build_c(
        'main', struct.unpack('<I', struct.pack('<f', scale))[0], 'pert_base')))
    pert_o, _ = run_oracle(model.VARIANTS['perturb'](), scale)
    pert_r = dump.parse_binary(run_c(build_c(
        'perturb', struct.unpack('<I', struct.pack('<f', scale))[0], 'pert_new')))
    fo, fr = flatten(base_o), flatten(base_r)
    po, pr = flatten(pert_o), flatten(pert_r)
    changed_o = sorted(set(fo) | set(po))
    changed_o = [f for f in changed_o if fo.get(f, '<absent>') != po.get(f, '<absent>')]
    changed_r = sorted(set(fr) | set(pr))
    changed_r = [f for f in changed_r if fr.get(f, '<absent>') != pr.get(f, '<absent>')]
    same = changed_o == changed_r
    return {'passed': bool(changed_o) and same,
            'original_changed_fields': changed_o,
            'rebuild_changed_fields': changed_r,
            'sets_equal': same}


def negative_oracle_archive():
    out1 = BUILD / 'oracle_archive_a.json'
    out2 = BUILD / 'oracle_archive_b.json'
    env = dict(os.environ)
    for path in (out1, out2):
        p = subprocess.run([sys.executable, str(pathlib.Path(__file__)),
                            '--oracle-archive', str(path),
                            '--variant', 'main', '--scale', '2.0'],
                           capture_output=True, text=True, timeout=300, env=env)
        if p.returncode != 0:
            return {'passed': False, 'error': p.stderr[-2000:]}
    a = out1.read_bytes(); b = out2.read_bytes()
    return {'passed': a == b, 'sha_a': hashlib.sha256(a).hexdigest(),
            'sha_b': hashlib.sha256(b).hexdigest(), 'bytes': len(a)}


# ----------------------------------------------------------------------
def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--run', action='store_true')
    ap.add_argument('--oracle-dump', action='store_true')
    ap.add_argument('--oracle-archive')
    ap.add_argument('--variant', default='main', choices=list(model.VARIANTS))
    ap.add_argument('--scale', type=float, default=2.0)
    ap.add_argument('--out', type=pathlib.Path)
    ns = ap.parse_args()

    if ns.oracle_archive:
        pathlib.Path(ns.oracle_archive).write_bytes(
            oracle_dump_bytes(ns.variant, ns.scale))
        return
    if ns.oracle_dump:
        sys.stdout.buffer.write(oracle_dump_bytes(ns.variant, ns.scale))
        return
    if not ns.run:
        ap.error('choose --run or --oracle-archive')

    BUILD.mkdir(parents=True, exist_ok=True)
    stamp = time.strftime('%Y%m%dT%H%M%S')
    out_dir = ns.out or BUILD
    out_dir.mkdir(parents=True, exist_ok=True)
    results = {}
    for scale in (2.0, 1.0):
        results['main_s%s' % str(scale).replace('.', 'p')] = run_variant(
            'main', scale, 'main')
    results['err_parent_s2p0'] = run_variant('err_parent', 2.0, 'err_parent')
    results['perturb_s2p0'] = run_variant('perturb', 2.0, 'perturb')

    nc1 = negative_broken_segment(2.0)
    nc2 = negative_input_perturbation(2.0)
    nc3 = negative_oracle_archive()

    # Per-field report: every compared field with both values, equality and
    # segment attribution.  Kept beside the receipt so the receipt stays
    # readable while the contract's "every field" table still exists.
    field_report = {}
    group_summary = {}
    for key, res in results.items():
        fo = res['_fields_original']
        fr = res['_fields_rebuild']
        rows = []
        groups = {}
        for f in sorted(set(fo) | set(fr)):
            va = fo.get(f, '<absent>')
            vb = fr.get(f, '<absent>')
            g = f.split('.')[0].split('[')[0]
            gs = groups.setdefault(g, {'fields': 0, 'diff': 0})
            gs['fields'] += 1
            if va != vb:
                gs['diff'] += 1
            rows.append({'field': f,
                         'original': describe(f, va) if va != '<absent>' else '<absent>',
                         'rebuild': describe(f, vb) if vb != '<absent>' else '<absent>',
                         'original_raw': va, 'rebuild_raw': vb,
                         'equal': va == vb,
                         'attribution': attribution(f)})
        field_report[key] = rows
        group_summary[key] = groups

    main_ok = (results['main_s2p0']['diff_count'] == 0 and
               results['main_s1p0']['diff_count'] == 0)
    err = results['err_parent_s2p0']
    err_ok = (err['original']['returned_null'] and err['rebuild']['returned_null']
              and err['diff_count'] == 0)
    bind_ok = all(r['tree']['match'] and r['tree']['node_hashes_match']
                  for r in results.values())
    all_controls = nc1['passed'] and nc2['passed'] and nc3['passed']
    status = 'PASS' if (main_ok and err_ok and bind_ok and all_controls) else 'FAIL'

    protocol = [{'tag': 'T_TREE', 'id': 1,
                 'payload': 'canonical tree (level_a_model.canonical grammar)'},
                {'tag': 'T_META', 'id': 2, 'payload': '21 u32 words, spine str, hash str'},
                {'tag': 'T_BONES', 'id': 3}, {'tag': 'T_SLOTS', 'id': 4},
                {'tag': 'T_IK', 'id': 5}, {'tag': 'T_TRANSFORM', 'id': 6},
                {'tag': 'T_PATH', 'id': 7}, {'tag': 'T_SKINS', 'id': 8},
                {'tag': 'T_EVENTS', 'id': 9}, {'tag': 'T_ANIMS', 'id': 10},
                {'tag': 'T_ERROR', 'id': 11}, {'tag': 'T_END', 'id': 255}]

    field_path = out_dir / ('level_a_field_report_%s.json' % stamp)
    field_path.write_text(json.dumps(
        {'schema': 'cally-level-a-field-report/1',
         'note': ('every compared field on both arms: original/rebuild values, '
                  'equality, segment attribution; main_s2p0 is the contract run'),
         'runs': field_report}, ensure_ascii=False, indent=1) + '\n')

    report = {
        'schema': 'cally-level-a-diff/1',
        'generated_utc': time.strftime('%Y-%m-%dT%H:%M:%SZ', time.gmtime()),
        'tier': 'oracle_anchored',
        'original_executed': True,
        'evidence_layer': ('synthetic memory oracle: original ARM bytes executed in '
                           'Unicorn over a staged 32-byte-node Json tree and a '
                           'bump heap; NOT device execution'),
        'contract': 'reconstruction/contracts/native-equivalence-gate.md Level A',
        'BINDING': {
            'version': 'BINDING v1',
            'original_sha256': PIN,
            'original_path': str(SO),
            'fixture_sha256': sha_file(MOD / 'fixture' / 'level_a_dump.c'),
            'model_sha256': sha_file(HERE / 'level_a_model.py'),
            'oracle_sha256': sha_file(HERE / 'level_a_oracle.py'),
            'dump_sha256': sha_file(HERE / 'level_a_dump.py'),
            'driver_sha256': sha_file(HERE / 'level_a_diff.py'),
            'trees': {k: {'node_count': v['tree']['node_count'],
                          'python_sha256': v['tree']['python_sha256'],
                          'c_arm_sha256': v['tree']['c_arm_sha256'],
                          'match': v['tree']['match'],
                          'node_hashes_match': v['tree']['node_hashes_match'],
                          'node_hashes_sha256': v['tree']['node_hashes_sha256'],
                          'first_node_sha256': v['tree']['node_sha256'][0],
                          'node_sha256': v['tree']['node_sha256']}
                      for k, v in results.items()},
            'rebuild_binaries': {k: v['binary_sha256'] for k, v in results.items()},
            'chain_check_build_recipe': str(C / 'spine_read_skeleton' / 'tools' /
                                            'check_skeleton.py'),
        },
        'input_domain': {
            'trees': {
                'main': 'skeleton(meta) + 3 bones + slot(blend/color/attachment) '
                        '+ ik + transform + path + skin(region+mesh) + event + '
                        'animation(rotate 3 frames curve+stepped, translate 2 frames, '
                        'event frame)',
                'err_parent': 'main with bone arm parent=forearm (Parent bone not found)',
                'perturb': 'main with the last translate frame removed and the '
                           'animation renamed walk2',
            },
            'scales': [2.0, 1.0],
            'note': ('This is the contract input set only; it is not the full input '
                     'domain and not device equivalence.'),
        },
        'comparable_fields': {
            'spSkeletonData': '21 words: strings/counts/floats exact; pointer words '
                              'compared as non-null presence plus their per-element '
                              'records (heap addresses differ by construction)',
            'per_element': ['bone name/parent/index/scalars/inherit flags',
                            'slot name/bone/attachment/blend/color bits',
                            'ik/transform/path names, bone lists, targets, scalars',
                            'skin name/entries; attachment type/name/path plus region '
                            'or mesh payload',
                            'event name/int/float/string',
                            'animation name/duration/timelineCount; per timeline '
                            'type/frameCount/ffc/index/frame bits/curve bits/event '
                            'frames'],
            'not_comparable': ['intermediate malloc/free sequence',
                               'creator internal layout beyond the fields above',
                               'console output text (parser->error is compared)',
                               'pointer values'],
        },
        'field_to_segment': {prefix: segs for prefix, segs in ATTRIBUTION},
        'dump_protocol': protocol,
        'results': results,
        'field_table': {
            'schema': 'cally-level-a-field-report/1',
            'path': str(field_path),
            'groups': group_summary,
            'note': ('Every field row carries original/rebuild values, equal flag '
                     'and segment attribution; main_s2p0 is the contract run.'),
        },
        'negative_controls': {
            'broken_segment': nc1,
            'input_perturbation': nc2,
            'oracle_archive_replay': nc3,
        },
        'equivalence_axis_4': {
            'status': ('合成内存 oracle 层已测，差异 0（输入域：本合同输入集）'
                       if status == 'PASS' else '合成内存 oracle 层已测，存在差异'),
            'diff_zero': main_ok,
            'diff_fields': sorted({d['field'] for k, v in results.items()
                                   for d in v['diff']}),
            'diff_count': sum(v['diff_count'] for v in results.values()),
            'caveat': ('不是全输入域等价，不是设备等价。The original arm is a '
                       'synthetic-memory Unicorn oracle; the rebuild arm is the '
                       'reconstructed C chain under qemu-arm.'),
        },
        'status': status,
    }
    out_dir.mkdir(parents=True, exist_ok=True)
    (out_dir / ('level_a_report_%s.json' % stamp)).write_text(
        json.dumps(report, ensure_ascii=False, indent=2) + '\n')
    RECEIPTS.mkdir(parents=True, exist_ok=True)
    receipt = RECEIPTS / ('level_a_diff-%s.json' % stamp)
    receipt.write_text(json.dumps(report, ensure_ascii=False, indent=2) + '\n')
    print('RESULT %s' % status)
    for k, v in results.items():
        print('  %-16s diff=%d tree_match=%s orig_null=%s reb_null=%s' % (
            k, v['diff_count'], v['tree']['match'],
            v['original']['returned_null'], v['rebuild']['returned_null']))
        for d in v['diff'][:10]:
            print('    DIFF', d['field'], 'orig=', d['original'],
                  'reb=', d['rebuild'], 'seg=', d['attribution'])
    print('  NC1 broken_segment passed=%s' % nc1['passed'])
    print('  NC2 input_perturbation passed=%s (sets_equal=%s, fields=%d)' % (
        nc2['passed'], nc2.get('sets_equal'), len(nc2.get('original_changed_fields', []))))
    print('  NC3 oracle_archive passed=%s' % nc3['passed'])
    print('  receipt=%s' % receipt)


if __name__ == '__main__':
    main()
