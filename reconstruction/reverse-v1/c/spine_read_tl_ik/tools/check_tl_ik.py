#!/usr/bin/env python3
"""Original is read-only. Execute only rebuilt ARM32 C plus synthetic
heap/libc/JSON/lookup/timeline providers. PASS is a scoped
reconstructed-consumer verdict, never an original-equivalence claim.

Subject: the ik-constraint timeline family of spSkeletonJson_readSkeletonData
@0x28b84c
  B7   0x28d840..0x28d8dc (156 B / 39 insns)
       ik child loop head -> real findIkConstraint is a declared synthetic
       boundary; spIkConstraintTimeline_create; the pointer linear scan over
       data->ikConstraints (+0x3c count / +0x40 array) that writes
       timeline+0x14 (hit island 0x28dbc8/0x28dbcc).
  B7b  0x28dbd0..0x28dca8 (216 B / 54 insns)
       frame loop head 0x28dbe0: getFloat "time" (0), getFloat "mix" (1.0f),
       getInt "bendPositive" (1) -> enum -1/+1 -> setFrame (0x28dc38) ->
       readCurve (0x28dc48) -> next frame, frameIndex++ -> publish/duration
       tail with a THREE-float frame stride -> back edge 0x28dca4.

Real recovered chain under test (all bodies recovered, no stubs):
  Json_getFloat / Json_getInt      c/json_interface
  readCurve                        c/spine_read_curve

Declared synthetic boundaries (NOT recovered bodies):
  spSkeletonData_findIkConstraint 0x28b238, spIkConstraintTimeline_create
  0x282f74, spIkConstraintTimeline_setFrame 0x282f8c,
  spCurveTimeline_setStepped/setCurve 0x2817c0/0x2817d8,
  fixture heap + allocator roster, libc providers, hand-built Json nodes.

Nothing here executes original libyoyo bytes. Static anchors (SHA, dynsym,
instruction words, pc-relative literals, anonymous-callee call sites) are
checked before any run.
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
MOD = C / 'spine_read_tl_ik'
FIX = MOD / 'fixture/check.c'
BODY = MOD / 'src/spine_read_tl_ik.c'
HEADER = MOD / 'src/spine_read_tl_ik.h'
PIN = '3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a'
CURVE_SRC = C / 'spine_read_curve/src/spine_read_curve.c'
JSON_SRC = C / 'json_interface/src/json_interface.c'
SOURCES = [C / p for p in (
    'spine_alloc/src/spine_alloc.c',
    'json_interface/src/json_interface.c',
    'spine_read_curve/src/spine_read_curve.c',
    'spine_read_tl_ik/src/spine_read_tl_ik.c',
    'csprite_resources/fixture/arm32_support.c',
    'spine_read_tl_ik/fixture/check.c',
)]
INCLUDES = [C / p / 'src' for p in (
    'spine_alloc', 'spine_attachment', 'spine_skeleton_data', 'json_interface',
    'spine_color', 'spine_read_mesh', 'spine_mesh', 'spine_read_vertices',
    'spine_atlas_attachment', 'spine_read_slots', 'skeleton_find',
    'spine_json_error', 'spine_json_support', 'spine_read_curve',
    'spine_read_tl_ik',
)]
FLAGS = ['--target=armv7a-none-eabi', '-march=armv7-a', '-marm', '-mfpu=vfpv3',
         '-mfloat-abi=softfp', '-std=c11', '-ffreestanding', '-fno-builtin',
         '-ffp-contract=off', '-fstack-protector-strong',
         '-mstack-protector-guard=global', '-ffunction-sections',
         '-fdata-sections', '-Wall', '-Wextra', '-Werror', '-nostdlib',
         '-static', '-fuse-ld=lld', '-Wl,--gc-sections', '-Wl,-e,_start']
# Contract names emitted by the fixture, in execution order.
TESTS = ['map_absent', 'map_without_constraints', 'scan_element_zero',
         'scan_element_middle', 'scan_element_last', 'scan_miss',
         'scan_nonpositive_count', 'lookup_null_matches_null_slot',
         'frame_values_and_bend', 'frame_defaults', 'read_curve_paths',
         'two_constraints', 'declared_vs_child_count']
SUMMARY = 'SUMMARY all declared ik timeline family contracts passed'
# Raw original instruction words: forks, field loads/stores, stack arguments,
# call sites.  Every word below was re-read from the image, not transcribed.
WORD_PINS = {
    0x28d840: 0xe59d3034,  # ldr r3,[sp,#0x34]      — the "ik" JSON child
    0x28d848: 0x0a000116,  # beq 0x28dca8           — no "ik" -> transform block
    0x28d850: 0xe5914004,  # ldr r4,[r1,#0x4]       — ik->child
    0x28d858: 0x0a000112,  # beq 0x28dca8           — no constraints -> transform
    0x28d85c: 0xe51fae1c,  # ldr r10,[pc,#-0xe1c]   — pool 0x28ca48 "time"
    0x28d870: 0xe58d202c,  # str r2,[sp,#0x2c]      — "mix" spill for the loop
    0x28d874: 0xe08f3003,  # add r3,pc,r3           — pool 0x28ca50 "bendPositive"
    0x28d884: 0xebfff66b,  # bl spSkeletonData_findIkConstraint
    0x28d888: 0xe1a05000,  # mov r5,r0              — result kept, NO null test
    0x28d890: 0xebffd5b7,  # bl spIkConstraintTimeline_create
    0x28d89c: 0xe590103c,  # ldr r1,[r0,#0x3c]      — ikConstraintsCount snapshot
    0x28d8a4: 0xda0000c9,  # ble 0x28dbd0           — SIGNED count <= 0 skip
    0x28d8a8: 0xe5902040,  # ldr r2,[r0,#0x40]      — ikConstraints array
    0x28d8ac: 0xe5923000,  # ldr r3,[r2]            — element 0
    0x28d8b0: 0xe1550003,  # cmp r5,r3              — pointer compare
    0x28d8b4: 0x13a03000,  # movne r3,#0            — index = 0
    0x28d8b8: 0x1a000003,  # bne 0x28d8cc           — -> increment path
    0x28d8bc: 0xea0000c1,  # b 0x28dbc8             — [0] hit -> out-of-line store
    0x28d8c0: 0xe5b20004,  # ldr r0,[r2,#0x4]!      — pre-increment element walk
    0x28d8c8: 0x0a0000bf,  # beq 0x28dbcc           — hit -> store index
    0x28d8cc: 0xe2833001,  # add r3,r3,#1           — index++
    0x28d8d0: 0xe1530001,  # cmp r3,r1              — index vs count snapshot
    0x28d8d4: 0x1afffff9,  # bne 0x28d8c0           — equality only, not blt
    0x28d8d8: 0xea0000bc,  # b 0x28dbd0             — miss -> frame loop
    0x28dbc8: 0xe3a03000,  # mov r3,#0              — [0] hit clears the index reg
    0x28dbcc: 0xe5863014,  # str r3,[r6,#0x14]      — the only ik-timeline +0x14 writer
    0x28dbd0: 0xe5945004,  # ldr r5,[r4,#0x4]       — constraintNode->child (frames)
    0x28dbd8: 0x13a07000,  # movne r7,#0            — frameIndex = 0
    0x28dbdc: 0x0a00001e,  # beq 0x28dc5c           — no frames -> tail
    0x28dbf4: 0xe3a025fe,  # mov r2,#1065353216     — "mix" default 1.0f
    0x28dc08: 0xe3a02001,  # mov r2,#1              — "bendPositive" default 1
    0x28dc2c: 0x03e0c000,  # mvneq r12,#0           — bend 0 -> -1
    0x28dc30: 0x13a0c001,  # movne r12,#1           — otherwise -> +1
    0x28dc34: 0xe58dc000,  # str r12,[sp]           — 5th arg on the stack
    0x28dc38: 0xebffd4d3,  # bl spIkConstraintTimeline_setFrame
    0x28dc48: 0xebfff5bf,  # bl readCurve            — anonymous 0x28b34c
    0x28dc4c: 0xe5955000,  # ldr r5,[r5]            — frame = frame->next
    0x28dc50: 0xe2877001,  # add r7,r7,#1           — frameIndex++
    0x28dc6c: 0xe2422001,  # sub r2,r2,#1           — frameCount-1
    0x28dc78: 0xe0822082,  # add r2,r2,r2,lsl#1     — *3 threefold frame stride
    0x28dc7c: 0xe7816103,  # str r6,[r1,r3,lsl#2]   — timelines[count] = timeline
    0x28dc84: 0xe5944000,  # ldr r4,[r4]            — ikMap = ikMap->next
    0x28dca0: 0xedcb7a01,  # vstr s15,[r11,#4]      — duration store
    0x28dca4: 0x1afffef4,  # bne 0x28d87c           — constraint loop back edge
}
SYMBOL_PINS = {
    'spSkeletonJson_readSkeletonData': (0x28b84c, 13044),
    'Json_getItem': (0x2873c4, 100),
    'Json_getFloat': (0x287444, 28),
    'Json_getInt': (0x287460, 28),
    'spSkeletonData_findIkConstraint': (0x28b238, 92),
    'spIkConstraintTimeline_create': (0x282f74, 24),
    'spIkConstraintTimeline_setFrame': (0x282f8c, 44),
    '_spBaseTimeline_create': (0x282a10, 128),
    '_spCurveTimeline_init': (0x2816d8, 68),
    '_spTimeline_init': (0x281328, 60),
}
# Anonymous callee: no .dynsym/.symtab entry, so the ONLY proof is the call
# site plus the claim that no symbol range covers the address.
ANON_CALLEES = {
    'readCurve': {'target': 0x28b34c, 'first_word': 0xe92d4030,
                  'sites': [0x28dc48]},
}
# (literal pool word address, the ADD site whose +8 PC base resolves it,
#  expected text).  va = add_site + 8 + pool_word — pass the ADD address.
KEY_PINS = (
    (0x28ca48, 0x28d868, 'time'),
    (0x28ca4c, 0x28d86c, 'mix'),
    (0x28ca50, 0x28d874, 'bendPositive'),
)


def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def run(argv, timeout=60):
    return subprocess.run([str(x) for x in argv], text=True, capture_output=True,
                          timeout=timeout)


def replace_once(text, old, new):
    if text.count(old) != 1:
        raise ValueError('mutation site not unique: ' + old)
    return text.replace(old, new, 1)


def bl_target(word, addr):
    """ARM32 BL: 0xeb??????, imm24<<2 signed, pc = addr+8."""
    if (word >> 24) != 0xeb:
        raise ValueError(f'not a BL at {addr:#x}: {word:#x}')
    imm = word & 0xffffff
    if imm & 0x800000:
        imm -= 0x1000000
    return (addr + 8 + (imm << 2)) & 0xffffffff


def static(so):
    if sha(so) != PIN:
        raise ValueError('original SHA mismatch')
    with so.open('rb') as f:
        e = ELFFile(f)
        segs = [(s['p_vaddr'], s.data()) for s in e.iter_segments()
                if s['p_type'] == 'PT_LOAD']
        # This library has no .symtab; .dynsym is the authoritative table.
        sec = e.get_section_by_name('.dynsym')
        if sec is None:
            raise ValueError('.dynsym missing')
        syms = []
        found = {}
        for sym in sec.iter_symbols():
            if sym.name:
                syms.append((sym.name, sym['st_value'], sym['st_size']))
                if sym.name not in found:
                    found[sym.name] = (sym['st_value'], sym['st_size'])
        for name, (va, size) in SYMBOL_PINS.items():
            if found.get(name) != (va, size):
                raise ValueError(f'symbol pin drifted: {name}: {found.get(name)}')

        def raw(a, n):
            for va, data in segs:
                if va <= a and a + n <= va + len(data):
                    return data[a - va:a - va + n]
            raise ValueError('unmapped original ' + hex(a))

        def covered_by_symbol(addr):
            hits = []
            for name, value, size in syms:
                if size and value <= addr < value + size:
                    hits.append((name, hex(value), size))
            return hits

        words = {hex(a): struct.unpack('<I', raw(a, 4))[0] for a in WORD_PINS}
        for a, want in WORD_PINS.items():
            if words[hex(a)] != want:
                raise ValueError(f'word pin drifted at {a:#x}: '
                                 f'{words[hex(a)]:#x} != {want:#x}')
        keys = []
        for pool, add_site, want in KEY_PINS:
            w = struct.unpack('<I', raw(pool, 4))[0]
            va = (add_site + 8 + w) & 0xffffffff
            value = raw(va, 96).split(b'\0', 1)[0].decode('ascii')
            if value != want:
                raise ValueError(f'pc-relative key mismatch {add_site:#x}: '
                                 f'{value!r} != {want!r}')
            keys.append({'pool': hex(pool), 'add_site': hex(add_site),
                         'va': hex(va), 'value': value})
        anon = {}
        for name, spec in ANON_CALLEES.items():
            target = spec['target']
            if name in found:
                raise ValueError(f'{name} unexpectedly present in .dynsym')
            if covered_by_symbol(target):
                raise ValueError(f'{target:#x} is covered by a symbol: '
                                 f'{covered_by_symbol(target)}')
            if struct.unpack('<I', raw(target, 4))[0] != spec['first_word']:
                raise ValueError(f'{name} first instruction drifted at {target:#x}')
            sites = []
            for site in spec['sites']:
                w = struct.unpack('<I', raw(site, 4))[0]
                got = bl_target(w, site)
                if got != target:
                    raise ValueError(f'{name} call site {site:#x} targets '
                                     f'{got:#x}, not {target:#x}')
                sites.append({'site': hex(site), 'word': hex(w), 'target': hex(got)})
            anon[name] = {'address': hex(target), 'sites': sites,
                          'proof': 'no .dynsym entry and no symbol range covers the address'}
    return {'original_sha256': PIN,
            'symbol_pins': {k: [hex(v[0]), v[1]] for k, v in SYMBOL_PINS.items()},
            'anonymous_callees': anon,
            'word_pins': words, 'segment_key_literals': keys,
            'note': 'Static anchors, not original execution/equivalence'}


def dependency_binding():
    flags = [f for f in FLAGS if not f.startswith(('-Wl,', '-fuse-ld='))
             and f not in ('-nostdlib', '-static')]
    deps = set(SOURCES) | {Path(__file__).resolve()}
    for src in SOURCES:
        p = run(['clang', *flags, *['-I' + str(i) for i in INCLUDES], '-MM', src])
        if p.returncode:
            raise RuntimeError(p.stderr)
        text = p.stdout.replace('\\\n', ' ')
        deps.update(Path(x).resolve() for x in text.split(':', 1)[1].split())
    return {str(p): sha(p) for p in sorted(deps)}


def build(out, name, opt='-O2', overrides=None, extra=(), omit=()):
    used = [(overrides or {}).get(p, p) for p in SOURCES if p not in omit]
    binary = out / (name + '.arm')
    argv = ['clang', *FLAGS, opt, *extra,
            *['-I' + str(i) for i in INCLUDES], *used, '-o', binary]
    p = run(argv)
    (out / (name + '.build.log')).write_text(p.stdout + p.stderr)
    result = {'compile_rc': p.returncode,
              'compile_command': [str(x) for x in argv]}
    if p.returncode:
        return {**result, 'diagnostic': p.stderr}
    before = sha(binary)
    result['binary_sha256'] = before
    result['translation_units'] = {str(s): sha(s) for s in used}
    print('BINDING v1 entry=tl-ik run=' + name
          + ' original_sha256=' + PIN + ' fixture_sha256=' + sha(FIX)
          + ' binary_sha256=' + before, flush=True)
    p = run(['qemu-arm', binary], 15)
    (out / (name + '.log')).write_text(p.stdout + p.stderr)
    if sha(binary) != before:
        raise RuntimeError('executed binary drift')
    return {**result, 'exit_code': p.returncode, 'stdout': p.stdout,
            'stderr': p.stderr,
            'passes': re.findall(r'^PASS (.+)$', p.stdout, re.M),
            'failures': re.findall(r'^FAIL (.+)$', p.stdout, re.M)}


def mutations():
    """Ten mutants of the BODY text only; each must be refused by a NAMED
    runtime assertion.  Every mutant still compiles cleanly."""
    return [
        # --- the pointer scan (census open #6) --------------------------
        ('scan_off_by_one', BODY, [
            ('            timeline->ikConstraintIndex = index;        /* 0x28d8c8 beq 0x28dbcc ; 0x28dbcc str */',
             '            timeline->ikConstraintIndex = index + 1;    /* mutated: index 1-based */')],
         'scan_element_middle: a hit on ikConstraints[2] stores index 2'),
        ('scan_first_stores_pointer', BODY, [
            ('        timeline->ikConstraintIndex = 0;                /* 0x28dbc8 mov r3,#0 ; 0x28dbcc str */',
             '        timeline->ikConstraintIndex = (int32_t)(uintptr_t)ik; /* mutated: no clear of r3 */')],
         'scan_element_zero: a hit on ikConstraints[0] stores index 0 (0x28dbc8 clears r3)'),
        ('scan_miss_writes', BODY, [
            ('        if (index == count)                             /* 0x28d8d0 cmp r3,r1 */\n'
             '            return 0;                                   /* 0x28d8d4 bne fall-through -> 0x28d8d8 */',
             '        if (index == count) {                           /* 0x28d8d0 cmp r3,r1 */\n'
             '            timeline->ikConstraintIndex = -1;           /* mutated: writes on a miss */\n'
             '            return 0;                                   /* 0x28d8d4 bne fall-through -> 0x28d8d8 */\n'
             '        }')],
         'scan_miss: a miss stores nothing and +0x14 keeps the create-time value'),
        ('scan_count_signedness', BODY, [
            ('    if (count <= 0)                                     /* 0x28d8a0 cmp / 0x28d8a4 ble */',
             '    if (count == 0)                                     /* mutated: ble -> beq */')],
         'scan_nonpositive_count: a negative count skips the scan (ble, not bne)'),
        ('scan_wrong_end', BODY, [
            ('    element = array[0];                                 /* 0x28d8ac */',
             '    element = array[count - 1];                         /* mutated: first probe at the far end */')],
         'scan_element_zero: a hit on ikConstraints[0] stores index 0 (0x28dbc8 clears r3)'),
        # --- the frame loop ---------------------------------------------
        ('setframe_time_mix_swap', BODY, [
            ('                                            time, mix, bend_enum);       /* 0x28dc1c/0x28dc20/0x28dc34 */',
             '                                            mix, time, bend_enum);       /* mutated: args 3/4 swapped */')],
         'frame_values_and_bend: setFrame receives the frame "time" bits'),
        ('bend_polarity', BODY, [
            ('            int bend_enum = (bend == 0) ? -1 : 1;                   /* 0x28dc24..0x28dc30 */',
             '            int bend_enum = (bend == 0) ? 1 : -1;                   /* mutated */')],
         'frame_values_and_bend: bendPositive 0 -> -1, any non-zero -> +1 (0x28dc24..0x28dc30)'),
        ('readcurve_dropped', BODY, [
            ('            readCurve(frame, (void*)timeline, frameIndex);         /* 0x28dc3c..0x28dc48 */',
             '            (void)frameIndex;   /* mutated: the readCurve call is gone */')],
         'read_curve_paths: readCurve runs once per frame after setFrame'),
        ('mix_key_literal', BODY, [
            ('            float mix = Json_getFloat(frame, "mix", 1.0f);          /* 0x28dbf0..0x28dc00 */',
             '            float mix = Json_getFloat(frame, "mux", 1.0f);          /* mutated: key literal */')],
         'frame_values_and_bend: setFrame receives the frame "mix" bits'),
        ('frame_index_stuck', BODY, [
            ('            ++frameIndex;                                          /* 0x28dc50 add r7,r7,#1 */',
             '            /* mutated: the frameIndex increment is gone */')],
         'frame_values_and_bend: the frame index starts at 0 and increments per frame'),
        ('tail_stride', BODY, [
            ('        word_index = (declared - 1u) * 3u;              /* 0x28dc6c sub / 0x28dc78 add r2,r2,r2,lsl#1 */',
             '        word_index = (declared - 1u);                   /* mutated: stride 1 */')],
         'two_constraints: duration keeps the larger last frame time (1.7 over 0.4)'),
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
    report = {'schema': 'cally-tl-ik-check/1', 'tier': 'test_anchored',
              'original_executed': False,
              'entry': ('ik constraint timeline family (readSkeletonData caller blocks '
                        'B7 0x28d840-0x28d8dc, B7b 0x28dbd0-0x28dca8)'),
              'scope': ('Reconstructed ik-timeline C only: real Json_getFloat/Json_getInt, '
                        'real readCurve, the count-snapshot / array-reload / pointer-equality '
                        'index scan and the three-float frame tail. Synthetic boundaries: '
                        'spSkeletonData_findIkConstraint (scripted pointer, NULL allowed), '
                        'spIkConstraintTimeline_create/setFrame (argument recorders whose store '
                        'shape follows the disassembled bodies), spCurveTimeline_setStepped/'
                        'setCurve recorders, fixture heap + allocator roster, libc providers, '
                        'hand-built Json nodes. Not an original-equivalence claim.'),
              'subject': {'body': str(BODY), 'header': str(HEADER), 'fixture': str(FIX)},
              'runs': [], 'teeth': [], 'compile_guards': [],
              'declared_tests': TESTS, 'declared_summary': SUMMARY,
              'status': 'INCOMPLETE'}
    try:
        report['static'] = static(ns.so)
        report['source_binding'] = dependency_binding()
        report['toolchain'] = {n: run([n, '--version']).stdout.splitlines()[0]
                               for n in ('clang', 'qemu-arm')}
        configs = [('O2', '-O2', ())] if ns.smoke else [
            ('O0', '-O0', ()), ('O2', '-O2', ()), ('O3', '-O3', ()),
            ('ubsan', '-O2', ('-fsanitize=undefined,float-cast-overflow',
                              '-fsanitize-trap=all'))]
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
                    raise RuntimeError('mutant not rejected by named runtime '
                                       f'assertion: {name}: {r}')
                print('TEETH', name, r['failures'], flush=True)
            missing = build(ns.out, 'missing-tl-ik-body', omit=(BODY,))
            if (not missing['compile_rc']
                    or 'undefined symbol: readSkeletonData_ikTimelines'
                    not in missing['diagnostic']):
                raise RuntimeError('missing ik-timeline body not refused')
            report['compile_guards'].append({'name': 'missing-tl-ik-body',
                                             'refused': True, **missing})
            print('GUARD missing-tl-ik-body refused', flush=True)
            # Second door: the real readCurve translation unit must be linked,
            # otherwise the call at 0x28dc48 has no definition.  A stub would
            # satisfy the link, so this proves the source, not a placeholder.
            nostub = build(ns.out, 'unlinked-read-curve', omit=(CURVE_SRC,))
            if (not nostub['compile_rc']
                    or 'undefined symbol: readCurve' not in nostub['diagnostic']):
                raise RuntimeError('readCurve source removal not refused')
            report['compile_guards'].append({'name': 'unlinked-read-curve',
                                             'refused': True, **nostub})
            print('GUARD unlinked-read-curve refused', flush=True)
            # Third door: the Json accessors must come from c/json_interface.
            nojson = build(ns.out, 'unlinked-json-interface', omit=(JSON_SRC,))
            if (not nojson['compile_rc']
                    or 'undefined symbol: Json_getFloat' not in nojson['diagnostic']):
                raise RuntimeError('Json accessor source removal not refused')
            report['compile_guards'].append({'name': 'unlinked-json-interface',
                                             'refused': True, **nojson})
            print('GUARD unlinked-json-interface refused', flush=True)
        if any(sha(p) != v for p, v in report['source_binding'].items()):
            raise RuntimeError('bound source/header/checker drift')
        report['status'] = 'SMOKE_PASS' if ns.smoke else 'PASS'
    except Exception as ex:
        report['error'] = str(ex)
        raise
    finally:
        (ns.out / 'receipt.json').write_text(
            json.dumps(report, ensure_ascii=False, indent=2) + '\n')
    print('RESULT ' + report['status'] + '; ORIGINAL NOT EXECUTED; receipt='
          + str(ns.out / 'receipt.json'), flush=True)


if __name__ == '__main__':
    main()
