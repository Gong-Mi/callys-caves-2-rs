#!/usr/bin/env python3
"""Original is read-only. Execute only rebuilt ARM32 C plus synthetic
heap/libc/JSON/lookup/timeline providers. PASS is a scoped
reconstructed-consumer verdict, never an original-equivalence claim.

Subject: the path-constraint timeline family of spSkeletonJson_readSkeletonData
@0x28b84c
  B13  0x28de74..0x28e060 (492 B / 123 insns)
       paths child loop head -> real findPathConstraint is a declared synthetic
       boundary; the result IS null-tested (0x28dee0) -> E7; the pointer linear
       scan over data->pathConstraints (+0x4c count / +0x50 array) whose hit
       writes the SHARED STACK CELL [sp+0x2c] (0x28df2c); the
       "position"/"spacing" strcmp dispatch; the shared frame loop (head
       0x28dfa4, readCurve at 0x28dff4); the two-float publish/duration tail.
  islands 0x28e52c..0x28e558 (spacing strcmp + create + mode select),
          0x28e554 (1.0f arm), 0x28ea74 (spacing scale), 0x28ea48..0x28ea70 (E7).

BOUNDARY: 0x28e538 `bne 0x28e8ec` hands every sub-key that is neither
"position" nor "spacing" to the path-MIX block B17 (0x28e8ec..0x28ea88), which
has its own loop head (0x28e948), its own readCurve call site (0x28e9b0) and a
THREE-float frame stride (0x28e9e8). B17 is NOT part of this module; the driver
reports PATH_TL_HANDOFF_MIX and the fixture pins that no mix timeline is
created here.

Real recovered chain under test (all bodies recovered, no stubs):
  Json_getFloat                    c/json_interface
  readCurve                        c/spine_read_curve
  _spSkeletonJson_setError         c/spine_json_error
  spAnimation_dispose / spSkeletonData_dispose / spTimeline_dispose
                                   c/spine_skeleton_data
  Json_dispose / ReportSpineError  c/spine_json_support
  _malloc / _free / _calloc        c/spine_alloc

Declared synthetic boundaries (NOT recovered bodies):
  spSkeletonData_findPathConstraint 0x28b2f0, spPathConstraintPositionTimeline_
  create 0x283010, ...SpacingTimeline_create 0x28303c,
  spPathConstraintPositionTimeline_setFrame 0x283028,
  spCurveTimeline_setStepped/setCurve 0x2817c0/0x2817d8, fixture heap +
  allocator roster, libc providers, hand-built Json nodes.

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
MOD = C / 'spine_read_tl_path'
FIX = MOD / 'fixture/check.c'
BODY = MOD / 'src/spine_read_tl_path.c'
HEADER = MOD / 'src/spine_read_tl_path.h'
PIN = '3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a'
CURVE_SRC = C / 'spine_read_curve/src/spine_read_curve.c'
JSON_SRC = C / 'json_interface/src/json_interface.c'
SOURCES = [C / p for p in (
    'spine_alloc/src/spine_alloc.c',
    'json_interface/src/json_interface.c',
    'spine_skeleton_data/src/spine_skeleton_data.c',
    'spine_json_support/src/spine_json_support.c',
    'spine_json_error/src/spine_json_error.c',
    'spine_read_curve/src/spine_read_curve.c',
    'spine_read_tl_path/src/spine_read_tl_path.c',
    'csprite_resources/fixture/arm32_support.c',
    'spine_linked_postpass/fixture/reporter_adapter.c',
    'spine_read_tl_path/fixture/check.c',
)]
INCLUDES = [C / p / 'src' for p in (
    'spine_alloc', 'spine_attachment', 'spine_skeleton_data', 'json_interface',
    'spine_color', 'spine_read_mesh', 'spine_mesh', 'spine_read_vertices',
    'spine_atlas_attachment', 'spine_read_slots', 'spine_json_error',
    'spine_json_support', 'spine_read_curve', 'spine_read_tl_path',
)]
FLAGS = ['--target=armv7a-none-eabi', '-march=armv7-a', '-marm', '-mfpu=vfpv3',
         '-mfloat-abi=softfp', '-std=c11', '-ffreestanding', '-fno-builtin',
         '-ffp-contract=off', '-fstack-protector-strong',
         '-mstack-protector-guard=global', '-ffunction-sections',
         '-fdata-sections', '-Wall', '-Wextra', '-Werror', '-nostdlib',
         '-static', '-fuse-ld=lld', '-Wl,--gc-sections', '-Wl,-e,_start']
# Contract names emitted by the fixture, in execution order.
TESTS = ['paths_absent', 'paths_without_children', 'constraint_not_found',
         'scan_element_zero', 'scan_element_middle', 'scan_element_last',
         'scan_miss_leaves_cell', 'scan_index_carries',
         'scan_nonpositive_count', 'position_frames_scaled',
         'position_percent_unscaled', 'value_key_is_timeline_name',
         'spacing_mode_matrix', 'frame_defaults', 'read_curve_paths',
         'mix_subkey_hands_off', 'two_paths_cursor_duration',
         'declared_vs_child_count']
SUMMARY = 'SUMMARY all declared path timeline family contracts passed'
# Raw original instruction words: forks, field loads/stores, call sites.
# Every word below was re-read from the image, not transcribed.
WORD_PINS = {
    0x28de74: 0xe59d1044,  # ldr r1,[sp,#0x44]      — the "paths" JSON child
    0x28de7c: 0x0a000077,  # beq 0x28e060           — absent -> deform block
    0x28de84: 0xe592a004,  # ldr r10,[r2,#0x4]      — paths->child
    0x28de8c: 0x0a000073,  # beq 0x28e060           — no children -> deform
    0x28de9c: 0xe08f3003,  # add r3,pc,r3           — pool 0x28eaac "position"
    0x28dea0: 0xe58d002c,  # str r0,[sp,#0x2c]      — the index cell, ONCE
    0x28ded0: 0xe58d0048,  # str r0,[sp,#0x48]      — "mix" (B17's key)
    0x28dedc: 0xebfff503,  # bl spSkeletonData_findPathConstraint
    0x28dee0: 0xe2509000,  # subs r9,r0,#0          — the NULL test ik lacks
    0x28dee4: 0x0a0002d7,  # beq 0x28ea48           — E7 error path
    0x28deec: 0xe592104c,  # ldr r1,[r2,#0x4c]      — pathConstraintsCount snapshot
    0x28def4: 0xda00000d,  # ble 0x28df30           — SIGNED count <= 0 skip
    0x28def8: 0xe5922050,  # ldr r2,[r2,#0x50]      — pathConstraints array
    0x28df00: 0xe1590003,  # cmp r9,r3              — pointer compare
    0x28df08: 0x1a000003,  # bne 0x28df1c           — -> increment path
    0x28df10: 0xe5b20004,  # ldr r0,[r2,#0x4]!      — pre-increment element walk
    0x28df18: 0x0a000003,  # beq 0x28df2c           — hit -> store the cell
    0x28df24: 0x1afffff9,  # bne 0x28df10           — equality only, not blt
    0x28df2c: 0xe58d302c,  # str r3,[sp,#0x2c]      — the CELL, not the timeline
    0x28df54: 0x1a000174,  # bne 0x28e52c           — not "position"
    0x28df64: 0x0a000174,  # beq 0x28e53c           — is "spacing"
    0x28df6c: 0xebffd427,  # bl spPathConstraintPositionTimeline_create
    0x28df70: 0xe5993010,  # ldr r3,[r9,#0x10]      — positionMode
    0x28df7c: 0x1a000174,  # bne 0x28e554           — non-zero -> 1.0f
    0x28df88: 0xe5945004,  # ldr r5,[r4,#0x4]       — timelineNode->child (frames)
    0x28df94: 0xe5882014,  # str r2,[r8,#0x14]      — UNCONDITIONAL index store
    0x28dfa0: 0x0a00001a,  # beq 0x28e010           — no frames -> tail
    0x28dfb8: 0xe1a01006,  # mov r1,r6              — VALUE KEY = the node name
    0x28dfdc: 0xee677a08,  # vmul.f32 s15,s14,s16   — value * scale, always
    0x28dfe4: 0xebffd40f,  # bl spPathConstraintPositionTimeline_setFrame
    0x28dff4: 0xebfff4d4,  # bl readCurve           — anonymous 0x28b34c (B13)
    0x28dff8: 0xe5955000,  # ldr r5,[r5]            — frame = frame->next
    0x28e008: 0x1affffe5,  # bne 0x28dfa4           — frame loop back edge
    0x28e028: 0xe7818103,  # str r8,[r1,r3,lsl#2]   — timelines[count] = timeline
    0x28e030: 0xe0833182,  # add r3,r3,r2,lsl#3     — *8 = TWO-float stride
    0x28e034: 0xed537a02,  # vldr s15,[r3,#-8]      — frames[(declared-1)*2]
    0x28e044: 0xedcb7a01,  # vstr s15,[r11,#4]      — duration store
    0x28e050: 0x1affffb9,  # bne 0x28df3c           — timeline-node loop
    0x28e05c: 0x1affff9c,  # bne 0x28ded4           — path-node loop
    0x28e538: 0x1a0000eb,  # bne 0x28e8ec           — the B17 handoff
    0x28e540: 0xebffd2bd,  # bl spPathConstraintSpacingTimeline_create
    0x28e544: 0xe5993014,  # ldr r3,[r9,#0x14]      — spacingMode
    0x28e550: 0x9a000147,  # bls 0x28ea74           — UNSIGNED mode <= 1
    0x28e558: 0xeafffe8a,  # b 0x28df88             — back to the shared prologue
    0x28e9b0: 0xebfff265,  # bl readCurve           — B17's OWN site (not B13's)
    0x28ea5c: 0xe1a00008,  # mov r0,r8              — E7 argument staging
}
SYMBOL_PINS = {
    'spSkeletonJson_readSkeletonData': (0x28b84c, 13044),
    'Json_getFloat': (0x287444, 28),
    'Json_getItem': (0x2873c4, 100),
    'spSkeletonData_findPathConstraint': (0x28b2f0, 92),
    'spPathConstraintPositionTimeline_create': (0x283010, 24),
    'spPathConstraintPositionTimeline_setFrame': (0x283028, 20),
    'spPathConstraintSpacingTimeline_create': (0x28303c, 24),
    'spPathConstraintSpacingTimeline_setFrame': (0x283054, 20),
    'spPathConstraintMixTimeline_create': (0x283068, 24),
    '_spBaseTimeline_create': (0x282a10, 128),
    '_spCurveTimeline_init': (0x2816d8, 68),
    '_spTimeline_init': (0x281328, 60),
    'spAnimation_dispose': (0x28147c, 80),
    'spSkeletonData_dispose': (0x28adf8, 452),
    '_spSkeletonJson_setError': (0x28b784, 200),
}
# Anonymous callee: no .dynsym/.symtab entry, so the ONLY proof is the call
# sites plus the claim that no symbol range covers the address.  Two sites are
# pinned on purpose: 0x28dff4 is B13's and 0x28e9b0 is B17's, which is the
# byte-level proof that the two blocks own separate frame loops.
ANON_CALLEES = {
    'readCurve': {'target': 0x28b34c, 'first_word': 0xe92d4030,
                  'sites': [0x28dff4, 0x28e9b0]},
}
# (literal pool word address, the ADD site whose +8 PC base resolves it,
#  expected text).  va = add_site + 8 + pool_word — pass the ADD address.
KEY_PINS = (
    (0x28eaac, 0x28de9c, 'position'),      # [sp+0x38]
    (0x28eab0, 0x28dea8, 'time'),          # [sp+0x3c]
    (0x28eab4, 0x28deb8, 'spacing'),       # [sp+0x40]
    (0x28eab8, 0x28debc, 'spacing'),       # [sp+0x44]
    (0x28eabc, 0x28dec4, 'mix'),           # [sp+0x48] — B17's key
    # B17 boundary material: its own three keys, read at its own loop head.
    (0x28eb10, 0x28e934, 'time'),
    (0x28eb14, 0x28e93c, 'teMix'),         # +4 into the "rotateMix" literal
    (0x28eb18, 0x28e940, 'translateMix'),
    # E7 message literal (0x28ea58 ldr r2,[pc,#0xc0] -> pool 0x28eb20).
    (0x28eb20, 0x28ea68, 'Path constraint not found: '),
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
    print('BINDING v1 entry=tl-path run=' + name
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
        # --- the pointer scan (the shared [sp+0x2c] cell) -----------------
        ('scan_off_by_one', BODY, [
            ('            *index_cell = index;                       /* 0x28df18 beq 0x28df2c ; 0x28df2c str */',
             '            *index_cell = index + 1;                   /* mutated: 1-based index */')],
         'the scan stores the matching element index'),
        ('scan_miss_writes_zero', BODY, [
            ('        if (index == count)                            /* 0x28df20 */\n'
             '            return 0;                                  /* 0x28df28 b 0x28df30 */',
             '        if (index == count) {                          /* 0x28df20 */\n'
             '            *index_cell = 0;                           /* mutated: clears the carry */\n'
             '            return 0;                                  /* 0x28df28 b 0x28df30 */\n'
             '        }')],
         'the second constraint MISSES and stores the stale cell 2, not 0 and not a sentinel'),
        ('scan_count_signedness', BODY, [
            ('    if (count <= 0)                                    /* 0x28def0 cmp / 0x28def4 ble */',
             '    if (count == 0)                                    /* mutated: ble -> beq */')],
         'a negative count skips the scan (ble, not bne)'),
        ('scan_first_probe_at_end', BODY, [
            ('    element = array[0];                                /* 0x28defc */',
             '    element = array[count - 1];                        /* mutated: probe the far end first */')],
         'the scan stores the matching element index'),
        ('index_store_dropped', BODY, [
            ('            timeline->pathConstraintIndex = index_cell; /* 0x28df8c ldr r2,[sp,#0x2c] ;',
             '            timeline->pathConstraintIndex = 0;         /* mutated: no cell read ;')],
         'the scan stores the matching element index'),
        # --- the scale selects ------------------------------------------
        ('position_mode_polarity', BODY, [
            ('    if (pc->positionMode != 0)                         /* 0x28df70 / 0x28df74 / 0x28df7c bne */',
             '    if (pc->positionMode == 0)                         /* mutated: polarity flipped */')],
         'positionMode 0 multiplies the "position" value by parser->scale (1.5*2)'),
        ('spacing_signed_compare', BODY, [
            ('    if ((uint32_t)pc->spacingMode <= 1u)               /* 0x28e544 / 0x28e548 / 0x28e550 bls */',
             '    if (pc->spacingMode <= 1)                          /* mutated: bls -> signed <= */')],
         'spacingMode 0/1 scale, 2/3/negative do not (0x28e550 bls is unsigned)'),
        # --- the frame loop ---------------------------------------------
        ('value_key_literal', BODY, [
            ('            float value = Json_getFloat(frame, timelineNode->name, 0.0f); /* 0x28dfb8..0x28dfc8 */',
             '            float value = Json_getFloat(frame, "position", 0.0f); /* mutated: hardcoded key */')],
         'the value key is timelineNode->name (0x28dfb8 mov r1,r6), not a literal'),
        ('time_key_literal', BODY, [
            ('            float time = Json_getFloat(frame, "time", 0.0f);            /* 0x28dfa4..0x28dfb4 */',
             '            float time = Json_getFloat(frame, "tome", 0.0f);            /* mutated: key literal */')],
         'setFrame receives the frame "time" bits'),
        ('readcurve_dropped', BODY, [
            ('            readCurve(frame, (void*)timeline, frameIndex);              /* 0x28dff4 */',
             '            (void)frameIndex;   /* mutated: the readCurve call is gone */')],
         'readCurve runs once per frame after setFrame'),
        ('frame_index_stuck', BODY, [
            ('            ++frameIndex;                                               /* 0x28dffc */',
             '            /* mutated: the frameIndex increment is gone */')],
         'the frame index starts at 0 and increments per frame'),
        # --- the tail ----------------------------------------------------
        ('tail_stride_three', BODY, [
            ('                last = timeline->frames[declared * 2u - 2u];   /* 0x28e02c..0x28e034 */',
             '                last = timeline->frames[declared * 3u - 3u];   /* mutated: stride 3 */')],
         'duration reads frames[(declared-1)*2] = the last TIME, not a value'),
        # --- the dispatch and the boundary -------------------------------
        ('spacing_key_literal', BODY, [
            ('            } else if (strcmp(timelineNode->name, "spacing") == 0) {',
             '            } else if (strcmp(timelineNode->name, "spacingx") == 0) {')],
         'both sub-key names reach the deform block'),
        ('handoff_silently_continues', BODY, [
            ('                return PATH_TL_HANDOFF_MIX;            /* 0x28e538 bne 0x28e8ec (B17) */',
             '                return PATH_TL_REACHED_DEFORM;         /* mutated: swallows the mix key */')],
         'a "mix" sub-key is handed to B17 at 0x28e538 (bne 0x28e8ec)'),
        # --- the error path ----------------------------------------------
        ('e7_json_argument', BODY, [
            ('    spAnimation_dispose((spAnimation*)animation_raw);               /* 0x28ea54 */',
             '    (void)animationJson;   /* mutated: keeps the parameter "used" */\n'
             '    spAnimation_dispose((spAnimation*)animation_raw);               /* 0x28ea54 */'),
            ('                             animationJson,                         /* 0x28ea60 ldr r1,[sp,#0x1c] */',
             '                             (Json*)pathNode,                       /* mutated: wrong json arg */')],
         'E7 passes the CURRENT ANIMATION NODE as the setError json argument'),
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
    report = {'schema': 'cally-tl-path-check/1', 'tier': 'test_anchored',
              'original_executed': False,
              'entry': ('path constraint timeline family (readSkeletonData caller block '
                        'B13 0x28de74-0x28e060 plus the 0x28e52c/0x28ea74 islands)'),
              'scope': ('Reconstructed path-timeline C only: real Json_getFloat, real readCurve, '
                        'real _spSkeletonJson_setError/spAnimation_dispose/spSkeletonData_dispose, '
                        'the count-snapshot / array-reload / pointer-equality index scan into the '
                        'shared [sp+0x2c] cell, the position/spacing dispatch with both scale '
                        'selects, the shared frame loop and the two-float publish tail. Synthetic '
                        'boundaries: spSkeletonData_findPathConstraint (scripted pointer, NULL '
                        'allowed), spPathConstraintPosition/SpacingTimeline_create and the single '
                        'Position setFrame (argument recorders whose store shape follows the '
                        'disassembled bodies), spCurveTimeline_setStepped/setCurve recorders, '
                        'fixture heap + allocator roster, libc providers, hand-built Json nodes. '
                        'B17 (path mix, 0x28e8ec-0x28ea88) is NOT modelled; the driver reports '
                        'the handoff. Not an original-equivalence claim.'),
              'boundary': {
                  'b13_range': '0x28de74-0x28e060 (492 B / 123 insns, census §6)',
                  'b13_islands': ['0x28e52c-0x28e558 (spacing dispatch + create + mode select; '
                                  'address-wise inside census B15)',
                                  '0x28e554 + 0x28ea74-0x28ea7c (the 1.0f arm and the spacing '
                                  'scale; 0x28ea74 is inside census B17)',
                                  '0x28ea48-0x28ea70 (E7, shared tail 0x28da44)'],
                  'b17_range': '0x28e8ec-0x28ea88 (NOT in this module)',
                  'handoff_site': '0x28e538 bne 0x28e8ec',
                  'b17_evidence': ('own loop head 0x28e948, own readCurve call site 0x28e9b0, '
                                   'three-float frame stride 0x28e9e8 add r2,r2,r2,lsl#1, own '
                                   'keys "time"/"rotateMix"(as the +4 suffix "teMix")/'
                                   '"translateMix" at pools 0x28eb10/0x28eb14/0x28eb18, and its '
                                   'own publish tail 0x28e9cc..0x28ea0c')},
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
                # The fixture prints "FAIL <test>: <message>"; `expect` is the
                # message of one specific runtime assertion, so a substring hit
                # names both the failing test and the assertion.
                hit = [f for f in r.get('failures', []) if expect in f]
                caught = (r.get('compile_rc') == 0 and r.get('exit_code') == 1
                          and len(hit) == 1)
                report['teeth'].append({'name': name,
                                        'expected_failure_substring': expect,
                                        'failed_by': hit,
                                        'caught_by_named_assertion': caught, **r})
                if not caught:
                    raise RuntimeError('mutant not rejected by named runtime '
                                       f'assertion: {name}: {r}')
                print('TEETH', name, hit, flush=True)
            missing = build(ns.out, 'missing-tl-path-body', omit=(BODY,))
            if (not missing['compile_rc']
                    or 'undefined symbol: readSkeletonData_pathTimelines'
                    not in missing['diagnostic']):
                raise RuntimeError('missing path-timeline body not refused')
            report['compile_guards'].append({'name': 'missing-tl-path-body',
                                             'refused': True, **missing})
            print('GUARD missing-tl-path-body refused', flush=True)
            # Second door: the real readCurve translation unit must be linked,
            # otherwise the call at 0x28dff4 has no definition.  A stub would
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
            # Fourth door: the only setFrame the family links is the POSITION
            # symbol at 0x283028.  A body that calls the spacing twin must not
            # link, which is what proves the recovered call target.
            twin_text = BODY.read_text()
            twin_text = replace_once(
                twin_text,
                'spPathConstraintPositionTimeline_setFrame((void*)timeline, frameIndex,',
                'spPathConstraintSpacingTimeline_setFrame((void*)timeline, frameIndex,')
            twin_text = replace_once(
                twin_text,
                '#define ERR_PATH_NOT_FOUND "Path constraint not found: "',
                'extern void spPathConstraintSpacingTimeline_setFrame(void*, int, float, float);\n'
                '#define ERR_PATH_NOT_FOUND "Path constraint not found: "')
            twin = ns.out / 'spacing-setframe.c'
            twin.write_text(twin_text)
            twinbuilt = build(ns.out, 'spacing-setframe', overrides={BODY: twin})
            if (not twinbuilt['compile_rc']
                    or 'undefined symbol: spPathConstraintSpacingTimeline_setFrame'
                    not in twinbuilt['diagnostic']):
                raise RuntimeError('spacing setFrame twin (0x283054) was linkable; '
                                   'the 0x28dfe4 call target is not pinned')
            report['compile_guards'].append(
                {'name': 'spacing-setframe-not-a-callsite', 'refused': True, **twinbuilt})
            print('GUARD spacing-setframe-not-a-callsite refused', flush=True)
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
