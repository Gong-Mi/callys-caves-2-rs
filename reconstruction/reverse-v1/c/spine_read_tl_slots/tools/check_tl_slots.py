#!/usr/bin/env python3
"""Original is read-only. Execute only rebuilt ARM32 C plus synthetic
heap/libc/JSON/timeline providers. PASS is a scoped reconstructed-consumer
verdict, never an original-equivalence claim.

Subject: the slots timeline family of spSkeletonJson_readSkeletonData @0x28b84c
  B5   0x28d4ec..0x28d640 (340 B / 85 insns)
       slots child loop -> real findSlotIndex -> strcmp type dispatch ->
       attachment frames (getItem "name" + getFloat "time") -> publish tail
  B8   0x28d8dc..0x28d9d4 (248 B / 62 insns)
       color frames: getString("color") hex channel -> four real toColor calls
       -> spColorTimeline_setFrame -> real readCurve
  B8b  0x28d9d4..0x28da18 (68 B / 17 insns)
       color publish tail, frames at +0x10 with a five-float stride
  E1   0x28da18..0x28da54 (60 B / 15 insns)
       "Invalid timeline type for a slot: " -> real spAnimation_dispose ->
       real _spSkeletonJson_setError(parser, NULL, ...) -> real
       spSkeletonData_dispose -> NULL

Real recovered chain under test (all bodies recovered, no stubs):
  Json_getItem/getString/getFloat   c/json_interface
  spSkeletonData_findSlotIndex      c/skeleton_find
  toColor                           c/spine_color
  readCurve                         c/spine_read_curve
  _spSkeletonJson_setError          c/spine_json_error
  Json_dispose / ReportSpineError   c/spine_json_support
  spAnimation_dispose / spSkeletonData_dispose / spSlotData_dispose
                                    c/spine_skeleton_data
  _malloc / _free                   c/spine_alloc

Declared synthetic boundaries (NOT recovered bodies):
  spAttachmentTimeline_create/setFrame (0x282b94 / 0x282c1c) and
  spColorTimeline_create/setFrame      (0x282b3c / 0x282b54): the fixture
  doubles model the disassembled store shapes and record every argument.
  spCurveTimeline_setStepped/setCurve (0x2817c0 / 0x2817d8) recorders.
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
MOD = C / 'spine_read_tl_slots'
FIX = MOD / 'fixture/check.c'
BODY = MOD / 'src/spine_read_tl_slots.c'
HEADER = MOD / 'src/spine_read_tl_slots.h'
PIN = '3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a'
SOURCES = [C / p for p in (
    'spine_alloc/src/spine_alloc.c', 'json_interface/src/json_interface.c',
    'spine_color/src/spine_color.c', 'spine_skeleton_data/src/spine_skeleton_data.c',
    'skeleton_find/src/skeleton_find.c', 'spine_json_support/src/spine_json_support.c',
    'spine_json_error/src/spine_json_error.c',
    'spine_read_curve/src/spine_read_curve.c',
    'spine_read_tl_slots/src/spine_read_tl_slots.c',
    'csprite_resources/fixture/arm32_support.c',
    'spine_linked_postpass/fixture/reporter_adapter.c',
    'spine_read_tl_slots/fixture/check.c',
)]
# The readCurve translation unit is the one the "real link, not a stub" guard
# removes; keep its path addressable by name.
CURVE_SRC = C / 'spine_read_curve/src/spine_read_curve.c'
INCLUDES = [C / p / 'src' for p in (
    'spine_alloc', 'spine_attachment', 'spine_skeleton_data', 'json_interface',
    'spine_color', 'spine_read_mesh', 'spine_mesh', 'spine_read_vertices',
    'spine_atlas_attachment', 'spine_read_slots', 'skeleton_find',
    'spine_json_error', 'spine_json_support', 'spine_read_curve',
    'spine_read_tl_slots',
)]
FLAGS = ['--target=armv7a-none-eabi', '-march=armv7-a', '-marm', '-mfpu=vfpv3',
         '-mfloat-abi=softfp', '-std=c11', '-ffreestanding', '-fno-builtin',
         '-ffp-contract=off', '-fstack-protector-strong',
         '-mstack-protector-guard=global', '-ffunction-sections',
         '-fdata-sections', '-Wall', '-Wextra', '-Werror', '-nostdlib',
         '-static', '-fuse-ld=lld', '-Wl,--gc-sections', '-Wl,-e,_start']
# Contract names emitted by the fixture, in execution order.
TESTS = ['dispatch_no_timelines', 'slot_not_found', 'attachment_frames',
         'attachment_name_kind', 'color_frames_hex', 'color_hex_malformed',
         'read_curve_both_paths', 'duration_and_cursor', 'invalid_type_e1',
         'two_slots', 'declared_vs_child_count']
SUMMARY = 'SUMMARY all declared slots timeline family contracts passed'
# Raw original instruction words: control-flow forks, field stores, call sites.
WORD_PINS = {
    0x28d4ec: 0xe51f7adc,  # ldr r7,[pc,#-0xadc]     — "name" key pointer cache
    0x28d52c: 0xebfff6e6,  # bl spSkeletonData_findSlotIndex
    0x28d530: 0xe3700001,  # cmn r0,#1               — slot index == -1 test
    0x28d538: 0x0a000534,  # beq 0x28ea10            — miss -> out-of-block error
    0x28d554: 0xe1a00004,  # mov r0,r4               — strcmp(timeline name, key)
    0x28d558: 0xebf8a405,  # bl strcmp@plt           — "color"
    0x28d560: 0x0a0000dd,  # beq 0x28d8dc            — color branch
    0x28d56c: 0xebf8a400,  # bl strcmp@plt           — "attachment"
    0x28d574: 0x1a000127,  # bne 0x28da18            — neither -> E1
    0x28d57c: 0xebffd584,  # bl spAttachmentTimeline_create
    0x28d590: 0xe5802010,  # str r2,[r0,#0x10]       — attachment slotIndex +0x10
    0x28d5b8: 0xe59a3008,  # ldr r3,[r10,#0x8]       — name node kind word
    0x28d5c4: 0xe3530002,  # cmp r3,#2               — the "false" discriminator
    0x28d5c8: 0x159a3010,  # ldrne r3,[r10,#0x10]    — string_value
    0x28d5d8: 0xebffd58f,  # bl spAttachmentTimeline_setFrame
    0x28d5e4: 0x1affffeb,  # bne 0x28d598            — frame loop back edge
    0x28d5e8: 0xe59b3008,  # ldr r3,[r11,#0x8]       — animation timelineCount
    0x28d604: 0xe598300c,  # ldr r3,[r8,#0xc]        — attachment frames array
    0x28d60c: 0xed537a01,  # vldr s15,[r3,#-4]       — frames[count-1]
    0x28d61c: 0xedcb7a01,  # vstr s15,[r11,#4]       — duration store
    0x28d620: 0xe5999000,  # ldr r9,[r9]             — next timeline
    0x28d628: 0x1affffc7,  # bne 0x28d54c            — timeline loop back edge
    0x28d63c: 0x1affffb7,  # bne 0x28d520            — slot loop back edge
    0x28d8e0: 0xebffd495,  # bl spColorTimeline_create
    0x28d8f4: 0xe5801014,  # str r1,[r0,#0x14]       — color slotIndex +0x14
    0x28d8f8: 0x0a000035,  # beq 0x28d9d4            — no frames -> tail
    0x28d92c: 0xebffe6bd,  # bl Json_getString        — hex "color" channel
    0x28d940: 0xebffe6bf,  # bl Json_getFloat         — "time"
    0x28d950: 0xebfff74a,  # bl toColor(color,0)      — anonymous 0x28b680
    0x28d960: 0xebfff746,  # bl toColor(color,1)
    0x28d970: 0xebfff742,  # bl toColor(color,2)
    0x28d980: 0xebfff73e,  # bl toColor(color,3)
    0x28d9a0: 0xebffd46b,  # bl spColorTimeline_setFrame
    0x28d9b0: 0xebfff665,  # bl readCurve             — anonymous 0x28b34c
    0x28d9b8: 0xe2855001,  # add r5,r5,#1             — frameIndex++
    0x28d9d4: 0xe599200c,  # ldr r2,[r9,#0xc]         — declared frame count
    0x28d9e4: 0xe2422001,  # sub r2,r2,#1             — frameCount-1
    0x28d9f0: 0xe0822102,  # add r2,r2,r2,lsl#2       — *5 (five-float stride)
    0x28d9f8: 0xe5983010,  # ldr r3,[r8,#0x10]        — color frames array
    0x28da0c: 0xcef07a47,  # vmovgt.f32 s15,s14       — duration = max(...)
    0x28da14: 0xeaffff01,  # b 0x28d620              — back edge to the slot loop
    0x28da28: 0xebffce93,  # bl spAnimation_dispose
    0x28da34: 0xe594301c,  # ldr r3,[r4,#0x1c]        — the offending type text
    0x28da38: 0xe3a01000,  # mov r1,#0                — setError json arg is NULL
    0x28da40: 0xebfff74f,  # bl _spSkeletonJson_setError
    0x28da48: 0xebfff4ea,  # bl spSkeletonData_dispose
    0x28da4c: 0xe3a00000,  # mov r0,#0                — return NULL
    0x28da50: 0xeafff8dd,  # b 0x28bdcc               — parent loader tail
}
SYMBOL_PINS = {
    'spSkeletonJson_readSkeletonData': (0x28b84c, 13044),
    'Json_getItem': (0x2873c4, 100),
    'Json_getString': (0x287428, 28),
    'Json_getFloat': (0x287444, 28),
    '_malloc': (0x285c10, 60),
    'spSkeletonData_findSlotIndex': (0x28b0cc, 88),
    'spAttachmentTimeline_create': (0x282b94, 136),
    'spAttachmentTimeline_setFrame': (0x282c1c, 112),
    'spColorTimeline_create': (0x282b3c, 24),
    'spColorTimeline_setFrame': (0x282b54, 64),
    'spAnimation_dispose': (0x28147c, 80),
    'spSkeletonData_dispose': (0x28adf8, 452),
    '_spSkeletonJson_setError': (0x28b784, 200),
}
# Anonymous callees: no .dynsym/.symtab entry exists, so the ONLY proof is the
# call site + the claim that no symbol range covers the address.
ANON_CALLEES = {
    'toColor': {'target': 0x28b680, 'first_word': 0xe92d4030,
                'sites': [0x28d950, 0x28d960, 0x28d970, 0x28d980]},
    'readCurve': {'target': 0x28b34c, 'first_word': 0xe92d4030,
                  'sites': [0x28d9b0]},
}
# (literal pool word address, the ADD site whose +8 PC base resolves it,
#  expected text).  va = add_site + 8 + pool_word — pass the ADD address.
KEY_PINS = (
    (0x28ca18, 0x28d4f8, 'name'),
    (0x28ca1c, 0x28d500, 'time'),
    (0x28ca20, 0x28d508, 'color'),
    (0x28ca24, 0x28d50c, 'attachment'),
    (0x28ca28, 0x28d514, 'color'),
    (0x28ca54, 0x28d908, 'time'),
    (0x28ca58, 0x28da3c, 'Invalid timeline type for a slot: '),
)


def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def run(argv, timeout=60):
    return subprocess.run([str(x) for x in argv], text=True, capture_output=True, timeout=timeout)


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
        segs = [(s['p_vaddr'], s.data()) for s in e.iter_segments() if s['p_type'] == 'PT_LOAD']
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
                raise ValueError(f'word pin drifted at {a:#x}: {words[hex(a)]:#x} != {want:#x}')
        keys = []
        for pool, add_site, want in KEY_PINS:
            w = struct.unpack('<I', raw(pool, 4))[0]
            va = (add_site + 8 + w) & 0xffffffff
            value = raw(va, 96).split(b'\0', 1)[0].decode('ascii')
            if value != want:
                raise ValueError(f'pc-relative key mismatch {add_site:#x}: {value!r} != {want!r}')
            keys.append({'pool': hex(pool), 'add_site': hex(add_site), 'va': hex(va), 'value': value})
        # Anonymous callees: call-site proof + no covering symbol.
        anon = {}
        for name, spec in ANON_CALLEES.items():
            target = spec['target']
            if name in found:
                raise ValueError(f'{name} unexpectedly present in .dynsym')
            if covered_by_symbol(target):
                raise ValueError(f'{target:#x} is covered by a symbol: {covered_by_symbol(target)}')
            if struct.unpack('<I', raw(target, 4))[0] != spec['first_word']:
                raise ValueError(f'{name} first instruction drifted at {target:#x}')
            sites = []
            for site in spec['sites']:
                w = struct.unpack('<I', raw(site, 4))[0]
                got = bl_target(w, site)
                if got != target:
                    raise ValueError(f'{name} call site {site:#x} targets {got:#x}, not {target:#x}')
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
    argv = ['clang', *FLAGS, opt, *extra, *['-I' + str(i) for i in INCLUDES], *used, '-o', binary]
    p = run(argv)
    (out / (name + '.build.log')).write_text(p.stdout + p.stderr)
    result = {'compile_rc': p.returncode, 'compile_command': [str(x) for x in argv]}
    if p.returncode:
        return {**result, 'diagnostic': p.stderr}
    before = sha(binary)
    result['binary_sha256'] = before
    result['translation_units'] = {str(s): sha(s) for s in used}
    print('BINDING v1 entry=tl-slots run=' + name
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
    """Ten mutants of the BODY text only; each must be refused by a NAMED
    runtime assertion.  Every mutant still compiles cleanly."""
    seterror = ('    _spSkeletonJson_setError((spSkeletonJson*)parser_raw, 0,      /* 0x28da30..0x28da40 */')
    return [
        # +0x18 sits past the six-word record but inside the fixture block, so
        # the mutant cannot fault before the named assertion sees the field.
        ('attach_slot_offset', BODY, [
            ('    timeline->slotIndex = slotIndex;                 /* 0x28d590 */',
             '    ((int32_t*)(void*)timeline)[6] = slotIndex;      /* mutated: +0x18 */')],
         'attachment_frames: attachment timeline stores the slot index at +0x10'),
        ('color_slot_offset', BODY, [
            ('    timeline->slotIndex = slotIndex;                 /* 0x28d8f4 */',
             '    ((int32_t*)(void*)timeline)[6] = slotIndex;      /* mutated: +0x18 */')],
         'color_frames_hex: color timeline stores the slot index at +0x14'),
        ('color_tail_stride', BODY, [
            ('        uint32_t word_index = (declared - 1u) * 5u;      /* 0x28d9e4 / 0x28d9f0 */',
             '        uint32_t word_index = (declared - 1u);           /* mutated: stride 1 */')],
         'color_frames_hex: B8b tail reads frames[(count-1)*5] for the last frame time'),
        ('attach_tail_stride', BODY, [
            ('        uint32_t last_index = declared - 1u;             /* wraps like the original */',
             '        uint32_t last_index = (declared - 1u) * 5u;      /* mutated: stride 5 */')],
         'attachment_frames: B5 tail extends the animation duration to the last frame time'),
        ('error_message', BODY, [
            ('    "Invalid timeline type for a slot: ";',
             '    "Invalid timeline type for a slot";')],
         'invalid_type_e1: E1 message is the exact original literal plus the timeline key'),
        ('error_json_arg', BODY, [
            (seterror,
             '    _spSkeletonJson_setError((spSkeletonJson*)parser_raw, data_raw, /* mutated */')],
         'invalid_type_e1: E1 passes a NULL json argument to setError (data disposed exactly once)'),
        ('attach_index_stuck', BODY, [
            ('            frameIndex = index + 1;                               /* 0x28d5c0 */',
             '            frameIndex = index;                                   /* mutated */')],
         'attachment_frames: attachment frame index starts at 0 and increments per frame'),
        ('attach_name_kind_dropped', BODY, [
            ('            attachment_name = (kind == 2u) ? 0 : name_node->string_value; /* 0x28d5c4..0x28d5cc */',
             '            attachment_name = (kind == 0xffffffffu) ? 0 : name_node->string_value; /* mutated */')],
         'attachment_name_kind: a name node whose +0x08 word is 2 suppresses the attachment name'),
        ('color_component_swap', BODY, [
            ('            float g = toColor(color, 1);',
             '            float g = toColor(color, 2);   /* mutated */'),
            ('            float b = toColor(color, 2);',
             '            float b = toColor(color, 1);   /* mutated */')],
         'color_frames_hex: color frame 0 hex ff800000 -> r=1, g=0x80/255, b=0, a=0 through real toColor'),
        ('duration_polarity', BODY, [
            ('        animation->duration = (duration > last) ? duration : last; /* 0x28d610..0x28d61c */',
             '        animation->duration = (duration <= last) ? duration : last; /* mutated */')],
         'attachment_frames: B5 tail extends the animation duration to the last frame time'),
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
    report = {'schema': 'cally-tl-slots-check/1', 'tier': 'test_anchored',
              'original_executed': False,
              'entry': ('slots timeline family (readSkeletonData caller blocks '
                        'B5 0x28d4ec-0x28d640, B8 0x28d8dc-0x28d9d4, '
                        'B8b 0x28d9d4-0x28da18, E1 0x28da18-0x28da54)'),
              'scope': ('Reconstructed slots-timeline C only: real findSlotIndex, Json accessors, '
                        'hex-channel toColor x4, real readCurve, real setError with the console '
                        'vcall, real spAnimation_dispose/spSkeletonData_dispose, real _malloc/_free. '
                        'Synthetic boundaries: spAttachmentTimeline_create/setFrame and '
                        'spColorTimeline_create/setFrame (argument recorders whose store shape '
                        'follows the disassembled bodies), spCurveTimeline_setStepped/setCurve '
                        'recorders, fixture heap + allocator roster, libc providers, hand-built Json '
                        'nodes. Not an original-equivalence claim.'),
              'subject': {'body': str(BODY), 'header': str(HEADER), 'fixture': str(FIX)},
              'runs': [], 'teeth': [], 'compile_guards': [],
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
            missing = build(ns.out, 'missing-tl-slots-body', omit=(BODY,))
            if (not missing['compile_rc']
                    or 'undefined symbol: readSkeletonData_slotTimelines' not in missing['diagnostic']):
                raise RuntimeError('missing slots-timeline body not refused')
            report['compile_guards'].append({'name': 'missing-tl-slots-body',
                                             'refused': True, **missing})
            print('GUARD missing-tl-slots-body refused', flush=True)
            # Second door: the real readCurve translation unit must be linked,
            # otherwise the call at 0x28d9b0 has no definition.  A stub would
            # satisfy the link, so this proves the source, not a placeholder.
            nostub = build(ns.out, 'unlinked-read-curve', omit=(CURVE_SRC,))
            if (not nostub['compile_rc']
                    or 'undefined symbol: readCurve' not in nostub['diagnostic']):
                raise RuntimeError('readCurve source removal not refused')
            report['compile_guards'].append({'name': 'unlinked-read-curve',
                                             'refused': True, **nostub})
            print('GUARD unlinked-read-curve refused', flush=True)
            # Third door: the hex channel's real toColor must come from
            # c/spine_color, not from a fixture stub.
            nocolor = build(ns.out, 'unlinked-to-color',
                            omit=(C / 'spine_color/src/spine_color.c',))
            if (not nocolor['compile_rc']
                    or 'undefined symbol: toColor' not in nocolor['diagnostic']):
                raise RuntimeError('toColor source removal not refused')
            report['compile_guards'].append({'name': 'unlinked-to-color',
                                             'refused': True, **nocolor})
            print('GUARD unlinked-to-color refused', flush=True)
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
