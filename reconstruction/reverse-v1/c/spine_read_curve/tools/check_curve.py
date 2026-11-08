#!/usr/bin/env python3
"""Original is read-only. Execute only the rebuilt ARM32 readCurve C plus the
synthetic fixture runtime. PASS is a scoped reconstructed-consumer verdict,
never an original-equivalence claim.

Subject: readCurve @0x28b34c..0x28b3f8 (end-exclusive 0x28b3fc, where
_readVertices begins).  Anonymous: no .dynsym/.symtab symbol; objdump renders
the address as spSkeletonData_findPathConstraint+0x5c.

Recovered body (all recovered, no stubs):
    0x28b364  Json_getItem(frame, "curve")            @0x357aec
    0x28b36c  absent -> plain return
    0x28b370  node type at Json+0x08
    0x28b374  type 4 (string) -> strcmp(node->string_value @+0x10,
                                        "stepped" @0x357af4) @0x28b398
              equal -> tail b spCurveTimeline_setStepped(timeline, frameIndex)
    0x28b37c  type 5 (array)  -> four ->next nodes, floats at +0x18, in the
                                 order cx1,cy1,cx2,cy2 -> spCurveTimeline_setCurve
    anything else             -> no-op

Declared boundaries (NOT recovered bodies): spCurveTimeline_setStepped
(0x2817c0, modelled exactly: curves[frameIndex*19 + 0] = 1.0f) and
spCurveTimeline_setCurve (0x2817d8, 264 B of Bezier expansion — the fixture
records the six AAPCS words instead), the timeline record itself, and the
shared synthetic mesh-fixture runtime (heap, allocator roster, libc strings).

Extra guard: a second build of the same fixture (-DCURVE_NULL_PROBE) runs a
zero-element "curve" array (child == 0).  The original has no NULL check
between 0x28b3b8 and 0x28b3c8, so the rebuild must die on SIGSEGV.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import subprocess
from elftools.elf.elffile import ELFFile

C = Path(__file__).resolve().parents[2]
MOD = C / 'spine_read_curve'
FIX = MOD / 'fixture/check.c'
BODY = MOD / 'src/spine_read_curve.c'
PIN = '3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a'
SOURCES = [C / p for p in (
    'spine_alloc/src/spine_alloc.c', 'json_interface/src/json_interface.c',
    'spine_read_curve/src/spine_read_curve.c',
    'csprite_resources/fixture/arm32_support.c',
    'spine_read_curve/fixture/check.c',
)]
INCLUDES = [C / p / 'src' for p in (
    'spine_alloc', 'spine_attachment', 'json_interface', 'spine_color',
    'spine_read_mesh', 'spine_mesh', 'spine_read_vertices',
    'spine_atlas_attachment', 'spine_skeleton_data', 'spine_read_curve',
    'skeleton_find', 'spine_json_error', 'spine_json_support',
)]
FLAGS = ['--target=armv7a-none-eabi', '-march=armv7-a', '-marm', '-mfpu=vfpv3',
         '-mfloat-abi=softfp', '-std=c11', '-ffreestanding', '-fno-builtin',
         '-ffp-contract=off', '-fstack-protector-strong',
         '-mstack-protector-guard=global', '-ffunction-sections',
         '-fdata-sections', '-Wall', '-Wextra', '-Werror', '-nostdlib',
         '-static', '-fuse-ld=lld', '-Wl,--gc-sections', '-Wl,-e,_start']
# Contract names emitted by the fixture, in execution order.
TESTS = ['curve_absent', 'curve_stepped', 'curve_string_other',
         'curve_array_four', 'curve_array_chain_lengths',
         'curve_array_declared_count', 'curve_array_extra_ignored',
         'curve_type_other', 'curve_frame_index']
SUMMARY = 'SUMMARY all declared readCurve contracts passed'
# Raw original words inside 0x28b34c..0x28b3fc: control flow, argument plumbing,
# field offsets and the literal-pool words.
WORD_PINS = {
    0x28b34c: 0xe92d4030,  # push {r4,r5,lr}
    0x28b350: 0xe1a05001,  # mov  r5,r1              — timeline
    0x28b354: 0xe59f1098,  # ldr  r1,[pc,#0x98]      — "curve" pool word
    0x28b35c: 0xe1a04002,  # mov  r4,r2              — frameIndex
    0x28b364: 0xebfff016,  # bl   Json_getItem
    0x28b36c: 0x0a000004,  # beq  0x28b384            — absent key returns
    0x28b370: 0xe5903008,  # ldr  r3,[r0,#0x8]       — node type
    0x28b374: 0xe3530004,  # cmp  r3,#4              — string
    0x28b378: 0x0a000003,  # beq  0x28b38c
    0x28b37c: 0xe3530005,  # cmp  r3,#5              — array
    0x28b380: 0x0a00000c,  # beq  0x28b3b8
    0x28b390: 0xe5900010,  # ldr  r0,[r0,#0x10]      — string_value
    0x28b398: 0xebf8ac75,  # bl   strcmp
    0x28b3a0: 0x1afffff7,  # bne  0x28b384            — only exact "stepped"
    0x28b3b0: 0xe8bd4030,  # pop  {r4,r5,lr}         — tail-call epilogue
    0x28b3b4: 0xeaffd901,  # b    0x2817c0            — setStepped, no return
    0x28b3b8: 0xe5903004,  # ldr  r3,[r0,#0x4]       — curve->child
    0x28b3c4: 0xe593c000,  # ldr  r12,[r3]           — child->next
    0x28b3c8: 0xe5932018,  # ldr  r2,[r3,#0x18]      — cx1
    0x28b3cc: 0xe59c3018,  # ldr  r3,[r12,#0x18]     — cy1
    0x28b3d0: 0xe59cc000,  # ldr  r12,[r12]          — next->next
    0x28b3d4: 0xe59ce018,  # ldr  lr,[r12,#0x18]     — cx2
    0x28b3d8: 0xe58de000,  # str  lr,[sp]            — arg 5 on stack
    0x28b3dc: 0xe59cc000,  # ldr  r12,[r12]
    0x28b3e0: 0xe59cc018,  # ldr  r12,[r12,#0x18]    — cy2
    0x28b3e4: 0xe58dc004,  # str  r12,[sp,#0x4]      — arg 6 on stack
    0x28b3e8: 0xebffd8fa,  # bl   spCurveTimeline_setCurve
    0x28b3f0: 0xe8bd8030,  # pop  {r4,r5,pc}
    0x28b3fc: 0xe92d4ff0,  # push {r4-r11,lr}        — _readVertices, NOT ours
}
# Json node type constants are written by the parser at 0x28677c.  These words
# are what pins 4=string, 5=array (and the neighbours) for the dispatch above.
JSON_TYPE_PINS = {
    0x2868c0: 0xe3a03004,  # mov r3,#4   -> string
    0x2868c8: 0xe5883000,  # str r3,[r8]
    0x286f98: 0xe3a03003,  # mov r3,#3   -> number
    0x286fb4: 0xe3a03005,  # mov r3,#5   -> array
    0x286fb8: 0xe5803008,  # str r3,[r0,#0x8]
    0x286c98: 0xe3a03006,  # mov r3,#6   -> object
    0x286c9c: 0xe5803008,  # str r3,[r0,#0x8]
    0x2871a0: 0xe3a03002,  # mov r3,#2   -> false
    0x2871cc: 0xe3a03001,  # mov r3,#1   -> true
    0x287170: 0xe5850008,  # str r0,[r5,#0x8], r0 == 0 -> null
}
SYMBOL_PINS = {
    'spSkeletonJson_readSkeletonData': (0x28b84c, 13044),
    'Json_getItem': (0x2873c4, 100),
    'Json_getString': (0x287428, 28),
    '_malloc': (0x285c10, 60),
    'spCurveTimeline_setStepped': (0x2817c0, 24),
    'spCurveTimeline_setCurve': (0x2817d8, 264),
}
# (literal pool word address, the ADD site whose +8 PC base resolves it, text)
# va = add_site + 8 + pool_word — pass the ADD instruction address, not its base.
KEY_PINS = (
    (0x28b3f4, 0x28b360, 'curve'),
    (0x28b3f8, 0x28b394, 'stepped'),
)


def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def run(argv, timeout=60):
    return subprocess.run([str(x) for x in argv], text=True, capture_output=True, timeout=timeout)


def replace_once(text, old, new):
    if text.count(old) != 1:
        raise ValueError('mutation site not unique: ' + old)
    return text.replace(old, new, 1)


def static(so):
    if sha(so) != PIN:
        raise ValueError('original SHA mismatch')
    with so.open('rb') as f:
        e = ELFFile(f)
        segs = [(s['p_vaddr'], s.data()) for s in e.iter_segments() if s['p_type'] == 'PT_LOAD']
        # .dynsym first, then .symtab; first definition seen wins.
        found = {}
        for secname in ('.dynsym', '.symtab'):
            sec = e.get_section_by_name(secname)
            if sec is None:
                continue
            for sym in sec.iter_symbols():
                if sym.name and sym.name not in found:
                    found[sym.name] = (sym['st_value'], sym['st_size'])
        for name, (va, size) in SYMBOL_PINS.items():
            if found.get(name) != (va, size):
                raise ValueError(f'symbol pin drifted: {name}: {found.get(name)}')

        # The subject itself must stay anonymous: no symbol may start at 0x28b34c.
        owners = [(n, v) for n, v in found.items() if v[0] == 0x28b34c]
        if owners:
            raise ValueError(f'0x28b34c is no longer anonymous: {owners}')

        def raw(a, n):
            for va, data in segs:
                if va <= a and a + n <= va + len(data):
                    return data[a - va:a - va + n]
            raise ValueError('unmapped original ' + hex(a))

        def word(a):
            return struct.unpack('<I', raw(a, 4))[0]

        words = {hex(a): word(a) for a in WORD_PINS}
        for a, want in WORD_PINS.items():
            if words[hex(a)] != want:
                raise ValueError(f'word pin drifted at {a:#x}: {words[hex(a)]:#x} != {want:#x}')
        types = {hex(a): word(a) for a in JSON_TYPE_PINS}
        for a, want in JSON_TYPE_PINS.items():
            if types[hex(a)] != want:
                raise ValueError(f'json type pin drifted at {a:#x}: {types[hex(a)]:#x} != {want:#x}')
        if WORD_PINS[0x28b34c] >> 16 != 0xe92d or WORD_PINS[0x28b3fc] >> 16 != 0xe92d:
            raise ValueError('function boundary pins lost their push prologues')
        keys = []
        for pool, add_site, want in KEY_PINS:
            w = struct.unpack('<I', raw(pool, 4))[0]
            va = (add_site + 8 + w) & 0xffffffff
            value = raw(va, 64).split(b'\0', 1)[0].decode('ascii')
            if value != want:
                raise ValueError(f'pc-relative key mismatch {add_site:#x}: {value!r} != {want!r}')
            keys.append({'pool': hex(pool), 'add_site': hex(add_site), 'va': hex(va), 'value': value})
    return {'original_sha256': PIN,
            'symbol_pins': {k: [hex(v[0]), v[1]] for k, v in SYMBOL_PINS.items()},
            'word_pins': words, 'json_type_pins': types,
            'subject_address_range': ['0x28b34c', '0x28b3fc'],
            'subject_symbol': None,
            'curve_key_literals': keys,
            'note': 'Static anchors, not original execution/equivalence'}


def dependency_binding():
    flags = [f for f in FLAGS if not f.startswith(('-Wl,', '-fuse-ld=')) and f not in ('-nostdlib', '-static')]
    deps = set(SOURCES) | {Path(__file__).resolve()}
    for src in SOURCES:
        p = run(['clang', *flags, *['-I' + str(i) for i in INCLUDES], '-MM', src])
        if p.returncode:
            raise RuntimeError(p.stderr)
        deps.update(Path(x).resolve() for x in p.stdout.replace('\\\n', '').split(':', 1)[1].split())
    return {str(p): sha(p) for p in sorted(deps)}


def build(out, name, opt='-O2', overrides=None, extra=(), omit=()):
    used = [(overrides or {}).get(p, p) for p in SOURCES if p not in omit]
    binary = out / (name + '.arm')
    argv = ['clang', *FLAGS, opt, *extra, *['-I' + str(i) for i in INCLUDES], *used, '-o', binary]
    p = run(argv)
    (out / (name + '.build.log')).write_text(p.stdout + p.stderr)
    result = {'compile_rc': p.returncode, 'compile_command': [str(x) for x in argv]}
    if p.returncode:
        return {**result, 'diagnostic': p.stderr}
    before = sha(binary)
    result['binary_sha256'] = before
    result['translation_units'] = {str(s): sha(s) for s in used}
    print('BINDING v1 entry=spine-read-curve run=' + name
          + ' original_sha256=' + PIN + ' fixture_sha256=' + sha(FIX)
          + ' binary_sha256=' + before, flush=True)
    p = run(['qemu-arm', binary], 15)
    (out / (name + '.log')).write_text(p.stdout + p.stderr)
    if sha(binary) != before:
        raise RuntimeError('executed binary drift')
    return {**result, 'exit_code': p.returncode, 'stdout': p.stdout, 'stderr': p.stderr,
            'passes': re.findall(r'^PASS (.+)$', p.stdout, re.M),
            'failures': re.findall(r'^FAIL (.+)$', p.stdout, re.M)}


def mutations():
    """Named mutants of the BODY text only; each must be refused by a NAMED
    runtime assertion of the fixture."""
    return [
        ('curve_type_polarity', BODY, [
            ('if (curve->unk_08 == CURVE_JSON_STRING) {',
             'if (curve->unk_08 != CURVE_JSON_STRING) {')],
         'curve_stepped: CURVE stepped calls setStepped exactly once'),
        ('curve_key_literal', BODY, [
            ('Json* curve = Json_getItem(frame, "curve");',
             'Json* curve = Json_getItem(frame, "curves");')],
         'curve_stepped: CURVE stepped calls setStepped exactly once'),
        ('curve_stepped_literal', BODY, [
            ('strcmp(curve->string_value, "stepped")', 'strcmp(curve->string_value, "steped")')],
         'curve_stepped: CURVE stepped calls setStepped exactly once'),
        ('curve_frame_index_dropped', BODY, [
            ('spCurveTimeline_setStepped(curveTimeline, frameIndex);',
             'spCurveTimeline_setStepped(curveTimeline, 0);')],
         'curve_stepped: CURVE stepped passes timeline and frameIndex unchanged'),
        ('curve_array_arg1_field', BODY, [
            ('float cx1 = c0->float_value;', 'float cx1 = c0->int_value;')],
         'curve_array_four: CURVE array arg1 is cx1 from child 0'),
        ('curve_array_arg2_source', BODY, [
            ('float cy1 = c1->float_value;', 'float cy1 = c0->float_value;')],
         'curve_array_four: CURVE array arg2 is cy1 from child 1'),
        ('curve_array_fourth_dropped', BODY, [
            ('float cy2 = c3->float_value;', 'float cy2 = c3->int_value;')],
         'curve_array_four: CURVE array arg4 is cy2 from child 3'),
        ('curve_absent_default_write', BODY, [
            ('    if (curve == NULL)\n        return;',
             '    if (curve == NULL) {\n        spCurveTimeline_setStepped(curveTimeline, frameIndex);\n        return;\n    }')],
         'curve_absent: CURVE absent key performs no timeline write'),
    ]


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--so', type=Path, required=True)
    ap.add_argument('--out', type=Path, required=True)
    ap.add_argument('--smoke', action='store_true')
    ns = ap.parse_args()
    ns.out.mkdir(parents=True, exist_ok=False)
    tmp = ns.out / 'compiler-tmp'
    tmp.mkdir()
    os.environ['TMPDIR'] = str(tmp)
    report = {'schema': 'cally-curve-check/1', 'tier': 'test_anchored',
              'original_executed': False,
              'entry': 'readCurve @0x28b34c..0x28b3fc (anonymous)',
              'scope': ('Reconstructed readCurve C only: Json_getItem(frame,"curve") -> '
                        'type 4 strcmp "stepped" -> tail spCurveTimeline_setStepped | '
                        'type 5 four ->next float nodes -> spCurveTimeline_setCurve. '
                        'Declared boundaries: spCurveTimeline_setStepped/setCurve bodies, '
                        'the fixture timeline record, and the shared synthetic mesh-fixture '
                        'runtime (heap, allocator roster, libc strings). Not an '
                        'original-equivalence claim.'),
              'subject': {'body': str(BODY), 'fixture': str(FIX)},
              'abi': {
                  'signature': 'void readCurve(Json* frame, void* curveTimeline, int frameIndex)',
                  'callers': ['0x28d7d0', '0x28d9b0', '0x28daf0', '0x28dc48',
                              '0x28de0c', '0x28dff4', '0x28e2a8', '0x28e9b0'],
                  'r0': 'per-frame Json object; every caller reloads frame->next after the call',
                  'r1': 'curve timeline just passed to <Type>Timeline_setFrame',
                  'r2': '0-based frame index, whole 32-bit word',
                  'return': 'void — no caller reads r0',
                  'curve_shape': ('string "stepped" (exact, case-sensitive) OR JSON array of '
                                  'numbers; four ->next nodes are read unconditionally, the '
                                  'array count at Json+0x0c is never consulted, elements map '
                                  '1:1 to setCurve(cx1,cy1,cx2,cy2)'),
              },
              'runs': [], 'teeth': [], 'compile_guards': [], 'edge_probe': None,
              'declared_tests': TESTS, 'declared_summary': SUMMARY, 'status': 'INCOMPLETE'}
    try:
        report['static'] = static(ns.so)
        report['source_binding'] = dependency_binding()
        report['toolchain'] = {n: run([n, '--version']).stdout.splitlines()[0]
                               for n in ('clang', 'qemu-arm')}
        configs = [('O2', '-O2', ())] if ns.smoke else [
            ('O0', '-O0', ()), ('O2', '-O2', ()), ('O3', '-O3', ()),
            ('ubsan', '-O2', ('-fsanitize=undefined,float-cast-overflow', '-fsanitize-trap=all'))]
        for name, opt, extra in configs:
            r = build(ns.out, name, opt, extra=extra)
            report['runs'].append({'name': name, **r})
            if (r.get('compile_rc') or r['exit_code'] or r['passes'] != TESTS
                    or r['failures'] or SUMMARY not in r['stdout']):
                raise RuntimeError(f'{name}: acceptance failed {r}')
            print('PASS', name, 'declared_tests=' + str(len(TESTS)), flush=True)
        if not ns.smoke:
            for name, subject, edits, expect in mutations():
                text = subject.read_text()
                for old, new in edits:
                    text = replace_once(text, old, new)
                candidate = ns.out / (name + '.c')
                candidate.write_text(text)
                r = build(ns.out, name, overrides={subject: candidate})
                caught = (r.get('compile_rc') == 0 and r.get('exit_code') == 1
                          and expect in r.get('failures', []))
                report['teeth'].append({'name': name, 'expected_failure': expect,
                                        'caught_by_named_assertion': caught, **r})
                if not caught:
                    raise RuntimeError(f'mutant not rejected by named runtime assertion: {name}: {r}')
                print('TEETH', name, r['failures'], flush=True)
            missing = build(ns.out, 'missing-spine-read-curve-body', omit=(BODY,))
            if (not missing['compile_rc']
                    or 'undefined symbol: readCurve' not in missing['diagnostic']):
                raise RuntimeError('missing readCurve body not refused')
            report['compile_guards'].append({'name': 'missing-spine-read-curve-body',
                                             'refused': True, **missing})
            print('GUARD missing-spine-read-curve-body refused', flush=True)
            probe = build(ns.out, 'zero-element-probe', '-O2', extra=('-DCURVE_NULL_PROBE',))
            died = (probe.get('compile_rc') == 0 and 'PROBE armed' in probe.get('stdout', '')
                    and probe.get('exit_code') in (-11, 139)
                    and 'FAIL curve_zero_elements' not in probe.get('stdout', ''))
            report['edge_probe'] = {
                'name': 'zero-element curve array (child == 0)',
                'expectation': ('no NULL guard between 0x28b3b8 and 0x28b3c8: the rebuild '
                                'must die on SIGSEGV (qemu exit -11/139) after printing '
                                '"PROBE armed"'),
                'refused_survival': died, **probe}
            if not died:
                raise RuntimeError(f'zero-element probe did not fault as pinned: {probe}')
            print('PROBE zero-element curve array faults as pinned', flush=True)
        if any(sha(p) != v for p, v in report['source_binding'].items()):
            raise RuntimeError('bound source/header/checker drift')
        report['status'] = 'SMOKE_PASS' if ns.smoke else 'PASS'
    except Exception as ex:
        report['error'] = str(ex)
        raise
    finally:
        (ns.out / 'receipt.json').write_text(json.dumps(report, ensure_ascii=False, indent=2) + '\n')
    print('RESULT ' + report['status'] + '; ORIGINAL NOT EXECUTED; receipt='
          + str(ns.out / 'receipt.json'), flush=True)


if __name__ == '__main__':
    main()
