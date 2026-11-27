#!/usr/bin/env python3
"""Original is read-only. Execute only the rebuilt ARM32 C (this module plus
the nine recovered family modules and their real dependencies) under qemu-arm;
the original libyoyo bytes are never loaded or executed.  PASS is a scoped
reconstructed-assembly verdict, never an original-equivalence claim.

Subject: the per-animation assembly of spSkeletonJson_readSkeletonData
@0x28b84c (13044 B):
  B3  0x28d2d4..0x28d3b4  frame preamble + per-animation 8-key lookup
  B4  0x28d3b4..0x28d4ec  timelineCount sum + spAnimation_create
  B5  0x28d4ec..0x28d640  slots family                     (0x28ea10 terminal
                          is recovered by this module)
  B6  0x28d640..0x28d840  bones family
  B7  0x28d840..0x28dca8  ik family
  B12 0x28dca8..0x28de74  transform family
  B13 0x28de74..0x28e060  path family (+B17 interleaved)
  B17 0x28e8ec..0x28ea0c  path-mix family
  B14 0x28e060..0x28e338  deform family
  B15 0x28e338..0x28e614  drawOrder family
  B16 0x28e614..0x28e774  event family
  --  0x28e774..0x28e79c  animationsCount/array publish + outer back edge

Family order is derived from the control flow (the fall-through chain listed in
the module header), not from address order.  The three cross-module handoffs
(path mix, deform->E4, drawOrder->E6) and the unowned 0x28ea10 block are
completed by the module and exercised here.
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
MOD = C / 'spine_animations_loop'
FIX = MOD / 'fixture/check.c'
BODY = MOD / 'src/spine_animations_loop.c'
HEADER = MOD / 'src/spine_animations_loop.h'
PIN = '3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a'
SOURCES = [C / p for p in (
    'spine_alloc/src/spine_alloc.c',
    'json_interface/src/json_interface.c',
    'spine_color/src/spine_color.c',
    'spine_skeleton_data/src/spine_skeleton_data.c',
    'spine_json_support/src/spine_json_support.c',
    'spine_json_error/src/spine_json_error.c',
    'spine_read_curve/src/spine_read_curve.c',
    'skeleton_find/src/skeleton_find.c',
    'spine_skin/src/spine_skin.c',
    'spine_read_animations/src/spine_read_animations.c',
    'spine_read_tl_slots/src/spine_read_tl_slots.c',
    'spine_read_tl_bones/src/spine_read_tl_bones.c',
    'spine_read_tl_ik/src/spine_read_tl_ik.c',
    'spine_read_tl_transform/src/spine_read_tl_transform.c',
    'spine_read_tl_path/src/spine_read_tl_path.c',
    'spine_read_tl_deform/src/spine_read_tl_deform.c',
    'spine_read_tl_draworder/src/spine_read_tl_draworder.c',
    'spine_read_tl_event/src/spine_read_tl_event.c',
    'spine_read_tl_path_mix/src/spine_read_tl_path_mix.c',
    'spine_animations_loop/src/spine_animations_loop.c',
    'csprite_resources/fixture/arm32_support.c',
    'spine_linked_postpass/fixture/reporter_adapter.c',
    'spine_animations_loop/fixture/check.c',
)]
INCLUDES = [C / p / 'src' for p in (
    'spine_alloc', 'spine_attachment', 'spine_skeleton_data', 'json_interface',
    'spine_color', 'spine_read_mesh', 'spine_mesh', 'spine_read_vertices',
    'spine_atlas_attachment', 'spine_read_slots', 'skeleton_find',
    'spine_json_error', 'spine_json_support', 'spine_read_animations',
    'spine_read_curve', 'spine_read_tl_slots', 'spine_read_tl_bones',
    'spine_read_tl_ik', 'spine_read_tl_transform', 'spine_read_tl_path',
    'spine_read_tl_deform', 'spine_read_tl_draworder', 'spine_read_tl_event',
    'spine_read_tl_path_mix', 'spine_skin', 'spine_animations_loop',
)]
FLAGS = ['--target=armv7a-none-eabi', '-march=armv7-a', '-marm', '-mfpu=vfpv3',
         '-mfloat-abi=softfp', '-std=c11', '-ffreestanding', '-fno-builtin',
         '-ffp-contract=off', '-fstack-protector-strong',
         '-mstack-protector-guard=global', '-ffunction-sections',
         '-fdata-sections', '-Wall', '-Wextra', '-Werror', '-nostdlib',
         '-static', '-fuse-ld=lld', '-Wl,--gc-sections', '-Wl,-e,_start']
TESTS = [
    'loop_full_nine_families',
    'loop_b4_sum_asymmetry',
    'loop_two_animations',
    'loop_empty_animation',
    'loop_partial_families',
    'loop_path_mix_skip',
    'loop_path_handoff_continue',
    'loop_curve_both_kinds',
    'loop_error_invalid_slot_type',
    'loop_error_slot_not_found',
    'loop_error_bone_not_found',
    'loop_error_path_not_found',
    'loop_error_deform_attachment',
    'loop_error_draworder_slot',
    'loop_error_event_not_found',
    'loop_error_second_animation',
    'loop_legacy_draworder',
]
SUMMARY = 'SUMMARY all declared animations loop contracts passed'
BLOCKS = [
    {'name': 'B3', 'range': '0x28d2d4..0x28d3b4', 'role':
     'preamble + per-animation 8-key lookup (spAnimationFrame)'},
    {'name': 'B4', 'range': '0x28d3b4..0x28d4ec', 'role':
     'timelineCount sum (4 asymmetric shapes) + spAnimation_create'},
    {'name': 'B5', 'range': '0x28d4ec..0x28d640', 'role': 'slots family'},
    {'name': 'B6', 'range': '0x28d640..0x28d840', 'role': 'bones family'},
    {'name': 'B7', 'range': '0x28d840..0x28dca8', 'role': 'ik family'},
    {'name': 'B12', 'range': '0x28dca8..0x28de74', 'role': 'transform family'},
    {'name': 'B13', 'range': '0x28de74..0x28e060', 'role':
     'path family; stops at 0x28e538 for B17'},
    {'name': 'B17', 'range': '0x28e8ec..0x28ea0c', 'role':
     'path-mix family, re-entered from B13'},
    {'name': 'B14', 'range': '0x28e060..0x28e338', 'role': 'deform family'},
    {'name': 'B15', 'range': '0x28e338..0x28e614', 'role': 'drawOrder family'},
    {'name': 'B16', 'range': '0x28e614..0x28e774', 'role': 'event family'},
    {'name': 'B18', 'range': '0x28e774..0x28e79c', 'role':
     'publish + cursor advance (B18 Json_dispose stays top-level, not here)'},
    {'name': 'E-B5', 'range': '0x28ea10..0x28ea3c', 'role':
     'slot-index -1 terminal recovered by this module (unowned before)'},
]
# Raw original instruction words.  Every entry is a control-flow transition
# between two family stages or a boundary this assembly depends on.
WORD_PINS = {
    # B4 -> B5: slots child spill, then the bones fall-through
    0x28d4dc: 0xe5944004,  # ldr r4,[r4,#0x4]   slots->child
    0x28d4e0: 0xe3540000,  # cmp r4,#0
    0x28d4e4: 0xe58d402c,  # str r4,[sp,#0x2c]  the B5 cursor slot
    0x28d4e8: 0x0a000054,  # beq 0x28d640       -> bones
    # B5 -> B6
    0x28d638: 0xe58d002c,  # str r0,[sp,#0x2c]  slot cursor refresh
    0x28d640: 0xe59d3030,  # ldr r3,[sp,#0x30]  B6 head (bones)
    # B6 -> B7
    0x28d648: 0x0a00007c,  # beq 0x28d840
    0x28d840: 0xe59d3034,  # ldr r3,[sp,#0x34]  B7 head (ik)
    # B7 -> B12
    0x28d848: 0x0a000116,  # beq 0x28dca8
    0x28dca8: 0xe59d0038,  # ldr r0,[sp,#0x38]  B12 head (transform)
    # B12 -> B13
    0x28dcb0: 0x0a00006f,  # beq 0x28de74
    0x28de74: 0xe59d1044,  # ldr r1,[sp,#0x44]  B13 head (paths)
    # B13 -> B14
    0x28de7c: 0x0a000077,  # beq 0x28e060
    0x28e060: 0xe59d1050,  # ldr r1,[sp,#0x50]  B14 head (deform)
    # B14 -> B15
    0x28e068: 0x0a0000b2,  # beq 0x28e338
    0x28e338: 0xe59d3028,  # ldr r3,[sp,#0x28]  B15 head (drawOrder)
    # B15 -> B16
    0x28e340: 0x0a0000b3,  # beq 0x28e614
    0x28e614: 0xe59d204c,  # ldr r2,[sp,#0x4c]  B16 head (events)
    # B16 -> publish
    0x28e61c: 0x0a000054,  # beq 0x28e774       absent events
    0x28e774: 0xe59d0018,  # ldr r0,[sp,#0x18]  publish head (data)
    0x28e784: 0xe5801034,  # str r1,[r0,#0x34]  count stored FIRST
    0x28e78c: 0xe782b103,  # str r11,[r2,r3,lsl#2] animations[OLD cursor]
    0x28e798: 0xe58d101c,  # str r1,[sp,#0x1c]  next animation cursor
    0x28e79c: 0x1afffadd,  # bne 0x28d318       outer back edge
    # handoffs completed by this module
    0x28d538: 0x0a000534,  # beq 0x28ea10       B5 slot -1 -> our recovery
    0x28ea1c: 0xebffca96,  # bl spAnimation_dispose
    0x28ea20: 0xe59d202c,  # ldr r2,[sp,#0x2c]  CURRENT slot node
    0x28ea2c: 0xe592301c,  # ldr r3,[r2,#0x1c]  slot member key
    0x28ea30: 0xe59f20e4,  # ldr r2,[pc,#0xe4]  "Slot not found: "
    0x28ea38: 0xebfff351,  # bl _spSkeletonJson_setError
    0x28e110: 0x0a000111,  # beq 0x28e55c       deform -> E4
    0x28e464: 0x0a000110,  # beq 0x28e8ac       drawOrder -> E6
    0x28e538: 0x1a0000eb,  # bne 0x28e8ec       path -> B17
    0x28e8fc: 0x0afffdd1,  # beq 0x28e048       B17 skips a literal "mix"
    0x28e048: 0xe5944000,  # ldr r4,[r4]        shared timeline-node advance
    # B4 sum islands
    0x28d478: 0xe5903004,  # ldr r3,[r0,#0x4]   deform skin->slot loop
    0x28d4b4: 0x12811001,  # addne r1,r1,#1     drawOrder +1
    0x28d4bc: 0x12811001,  # addne r1,r1,#1     events +1
    # B3 division magic consumed by deform
    0x28d304: 0xe58d1060,  # str r1,[sp,#0x60]  0x55555556
    0x28e6a0: 0x0a000043,  # beq 0x28e7b4       event frame miss -> E5
}
SYMBOL_PINS = {
    'spSkeletonJson_readSkeletonData': (0x28b84c, 13044),
    'Json_getItem': (0x2873c4, 100),
    'Json_getString': (0x287428, 28),
    'Json_getFloat': (0x287444, 28),
    'Json_getInt': (0x287460, 28),
    '_malloc': (0x285c10, 60),
    '_calloc': (0x285c4c, 52),
    '_free': (0x285c80, 28),
    'spSkeletonData_findBoneIndex': (0x28b018, 88),
    'spSkeletonData_findSlotIndex': (0x28b0cc, 88),
    'spSkeletonData_findSkin': (0x28b124, 92),
    'spSkeletonData_findEvent': (0x28b180, 92),
    'spSkeletonData_findIkConstraint': (0x28b238, 92),
    'spSkeletonData_findTransformConstraint': (0x28b294, 92),
    'spSkeletonData_findPathConstraint': (0x28b2f0, 92),
    'spAttachmentTimeline_create': (0x282b94, 136),
    'spAttachmentTimeline_setFrame': (0x282c1c, 112),
    'spColorTimeline_create': (0x282b3c, 24),
    'spColorTimeline_setFrame': (0x282b54, 64),
    'spTranslateTimeline_create': (0x282abc, 24),
    'spTranslateTimeline_setFrame': (0x282ad4, 48),
    'spRotateTimeline_create': (0x282a90, 24),
    'spRotateTimeline_setFrame': (0x282aa8, 20),
    'spScaleTimeline_create': (0x282b04, 24),
    'spShearTimeline_create': (0x282b20, 24),
    'spIkConstraintTimeline_create': (0x282f74, 24),
    'spIkConstraintTimeline_setFrame': (0x282f8c, 44),
    'spTransformConstraintTimeline_create': (0x282fb8, 24),
    'spTransformConstraintTimeline_setFrame': (0x282fd0, 64),
    'spPathConstraintPositionTimeline_create': (0x283010, 24),
    'spPathConstraintSpacingTimeline_create': (0x28303c, 24),
    'spPathConstraintPositionTimeline_setFrame': (0x283028, 20),
    'spPathConstraintMixTimeline_create': (0x283068, 24),
    'spPathConstraintMixTimeline_setFrame': (0x283080, 48),
    'spDeformTimeline_create': (0x282e58, 160),
    'spDeformTimeline_setFrame': (0x282ef8, 124),
    'spDrawOrderTimeline_create': (0x282d4c, 144),
    'spDrawOrderTimeline_setFrame': (0x282ddc, 124),
    'spEventTimeline_create': (0x282c8c, 136),
    'spEventTimeline_setFrame': (0x282d14, 56),
    'spEvent_create': (0x285b44, 52),
    'spEventData_create': (0x285b94, 88),
    'spAnimation_create': (0x2812b4, 116),
    'spAnimation_dispose': (0x28147c, 80),
    'spSkeletonData_dispose': (0x28adf8, 452),
    'spSkin_getAttachment': (0x28ed00, 88),
    '_spSkeletonJson_setError': (0x28b784, 200),
}
# (literal pool word, ADD site, expected text).  These are the key strings the
# assembly's dispatch and error tails compare/read.
KEY_PINS = (
    (0x28c9f8, 0x28d2e4, 'bones'),
    (0x28c9fc, 0x28d2f0, 'slots'),
    (0x28ca00, 0x28d2f8, 'ik'),
    (0x28ca04, 0x28d300, 'transform'),
    (0x28ca08, 0x28d358, 'paths'),
    (0x28ca0c, 0x28d36c, 'deform'),
    (0x28ca10, 0x28d380, 'drawOrder'),
    (0x28ca14, 0x28d394, 'events'),
    (0x28eb24, 0x28eb30, 'draworder'),
    (0x28eaac, 0x28de9c, 'position'),
    (0x28eab4, 0x28deb8, 'spacing'),
    (0x28eabc, 0x28dec4, 'mix'),
    (0x28eb1c, 0x28ea34, 'Slot not found: '),
)


def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def run(argv, timeout=90):
    return subprocess.run([str(x) for x in argv], text=True, capture_output=True,
                          timeout=timeout)


def replace_once(text, old, new):
    if text.count(old) != 1:
        raise ValueError('mutation site not unique: ' + old[:80])
    return text.replace(old, new, 1)


def static(so):
    if sha(so) != PIN:
        raise ValueError('original SHA mismatch')
    with so.open('rb') as f:
        e = ELFFile(f)
        segs = [(s['p_vaddr'], s.data()) for s in e.iter_segments()
                if s['p_type'] == 'PT_LOAD']
        found = {}
        sec = e.get_section_by_name('.dynsym')
        if sec is None:
            raise ValueError('.dynsym missing')
        for sym in sec.iter_symbols():
            if sym.name and sym.name not in found:
                found[sym.name] = (sym['st_value'], sym['st_size'])
        for name, (va, size) in SYMBOL_PINS.items():
            if found.get(name) != (va, size):
                raise ValueError(f'symbol pin drifted: {name}: {found.get(name)}')

        def raw(a, n):
            for va, data in segs:
                if va <= a and a + n <= va + len(data):
                    return data[a - va:a - va + n]
            raise ValueError('unmapped original ' + hex(a))

        words = {hex(a): struct.unpack('<I', raw(a, 4))[0] for a in WORD_PINS}
        for a, want in WORD_PINS.items():
            if words[hex(a)] != want:
                raise ValueError(
                    f'word pin drifted at {a:#x}: {words[hex(a)]:#x} != {want:#x}')
        keys = []
        for pool, add_site, want in KEY_PINS:
            w = struct.unpack('<I', raw(pool, 4))[0]
            va = (add_site + 8 + w) & 0xffffffff
            value = raw(va, 96).split(b'\0', 1)[0].decode('ascii')
            if value != want:
                raise ValueError(
                    f'pc-relative key mismatch {add_site:#x}: {value!r} != {want!r}')
            keys.append({'pool': hex(pool), 'add_site': hex(add_site),
                         'va': hex(va), 'value': value})
    return {'original_sha256': PIN,
            'symbol_pins': {k: [hex(v[0]), v[1]] for k, v in SYMBOL_PINS.items()},
            'word_pins': words, 'segment_key_literals': keys,
            'blocks': BLOCKS,
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
    argv = ['clang', *FLAGS, opt, *extra, *['-I' + str(i) for i in INCLUDES],
            *used, '-o', binary]
    p = run(argv)
    (out / (name + '.build.log')).write_text(p.stdout + p.stderr)
    result = {'compile_rc': p.returncode, 'compile_command': [str(x) for x in argv]}
    if p.returncode:
        return {**result, 'diagnostic': p.stderr}
    before = sha(binary)
    result['binary_sha256'] = before
    result['translation_units'] = {str(s): sha(s) for s in used}
    print('BINDING v1 entry=animations-loop run=' + name
          + ' original_sha256=' + PIN + ' fixture_sha256=' + sha(FIX)
          + ' binary_sha256=' + before, flush=True)
    p = run(['qemu-arm', binary], 20)
    (out / (name + '.log')).write_text(p.stdout + p.stderr)
    if sha(binary) != before:
        raise RuntimeError('executed binary drift')
    return {**result, 'exit_code': p.returncode, 'stdout': p.stdout,
            'stderr': p.stderr,
            'passes': re.findall(r'^PASS (.+)$', p.stdout, re.M),
            'failures': re.findall(r'^FAIL (.+)$', p.stdout, re.M)}


def mutations():
    """Named defects of the assembly and of the linked family sources.  Each
    mutant must be refused by the exact named runtime assertion below; every
    edit keeps the text compilable under -Werror."""
    return [
        ('loop_family_order_swap', BODY, [
            ('    if (slotsNode != 0 && slotsNode->child != 0) {\n'
             '        int rc = readSkeletonData_slotTimelines(frame->slotsChild, data_raw,',
             '    if (readSkeletonData_boneTimelines(frame->bones, frame->animation, data_raw,\n'
             '                                       animation, parser_raw) == 0)\n'
             '        return 0;\n'
             '    if (slotsNode != 0 && slotsNode->child != 0) {\n'
             '        int rc = readSkeletonData_slotTimelines(frame->slotsChild, data_raw,'),
            ('    /* B6 bones, 0x28d640..0x28d840. */\n'
             '    if (readSkeletonData_boneTimelines(frame->bones, frame->animation, data_raw,\n'
             '                                       animation, parser_raw) == 0)\n'
             '        return 0;\n',
             '    /* B6 mutated away: moved before B5 */\n'),
        ], 'loop_full_nine_families: family call order is slots, bones, ik, '
           'transform, paths(+mix), deform, drawOrder, events'),
        ('loop_slots_key_misroute', BODY, [
            ('int rc = readSkeletonData_slotTimelines(frame->slotsChild, data_raw,',
             'int rc = readSkeletonData_slotTimelines(frame->bones, data_raw,'),
        ], 'loop_full_nine_families: loop returns the data pointer when the '
           'outer loop ends'),
        ('loop_deform_stage_dropped', BODY, [
            ('readSkeletonData_deformTimelines(frame->deform, data_raw,',
             'readSkeletonData_deformTimelines((Json*)0, data_raw,'),
        ], 'loop_full_nine_families: all nine families created 15 timelines'),
        ('loop_bones_error_swallowed', BODY, [
            ('    if (readSkeletonData_boneTimelines(frame->bones, frame->animation, data_raw,\n'
             '                                       animation, parser_raw) == 0)\n'
             '        return 0;\n',
             '    if (readSkeletonData_boneTimelines(frame->bones, frame->animation, data_raw,\n'
             '                                       animation, parser_raw) == 0)\n'
             '        ;\n'),
        ], 'loop_error_bone_not_found: bone-not-found returns NULL'),
        ('loop_iteration_cursor_stuck', BODY, [
            ('    frame->animation = frame->animation->next;     /* 0x28e790 / 0x28e798 */',
             '    frame->animation = 0;                          /* mutated */'),
        ], 'loop_two_animations: B3/B4 run once per animation'),
        ('loop_path_resume_dropped', BODY, [
            ('                sub.child = t->next;',
             '                sub.child = 0;                 /* mutated */'),
        ], 'loop_full_nine_families: all nine families created 15 timelines'),
        ('b4_ik_sum_dropped', C / 'spine_read_animations/src/spine_read_animations.c', [
            ('        if (ik != 0) count = ik->unk_0c;        /* 0x28d414/0x28d418 ldrne */',
             '        if (ik != 0) count = 0u;               /* mutated */'),
        ], 'loop_full_nine_families: B4 hands spAnimation_create the asymmetric '
           'sum (5 bones + 2 slots + 1 ik + 1 transform + 3 paths + 1 deform + '
           '1 drawOrder + 1 events = 15)'),
        ('b4_draworder_sum_dropped', C / 'spine_read_animations/src/spine_read_animations.c', [
            ('    if (frame->drawOrder != 0) total += 1u;     /* 0x28d4a4/0x28d4b0/0x28d4b4 addne r1,r1,#1 */',
             '    if (frame->drawOrder != 0) total += 0u;     /* mutated */'),
        ], 'loop_full_nine_families: B4 hands spAnimation_create the asymmetric '
           'sum (5 bones + 2 slots + 1 ik + 1 transform + 3 paths + 1 deform + '
           '1 drawOrder + 1 events = 15)'),
        ('publish_cursor_off_by_one', C / 'spine_read_tl_event/src/spine_read_tl_event.c', [
            ('    data->animationsCount = count + 1;                 /* 0x28e780/0x28e784 */\n'
             '    table[count] = animation_raw;                      /* 0x28e78c */',
             '    data->animationsCount = count + 2;                 /* mutated */\n'
             '    table[count + 1] = animation_raw;                  /* mutated */'),
        ], 'loop_full_nine_families: exactly one animation is published'),
        ('event_duration_not_max', C / 'spine_read_tl_event/src/spine_read_tl_event.c', [
            ('        animation->duration = (duration > last) ? duration : last;',
             '        animation->duration = (last > duration) ? duration : last; /* mutated */'),
        ], 'loop_full_nine_families: duration is the max of every family\'s '
           'last frame time'),
        ('path_mix_skip_removed', C / 'spine_read_tl_path_mix/src/spine_read_tl_path_mix.c', [
            ('    if (strcmp(timelineNode->name, "mix") == 0)\n'
             '        return MIX_TL_SKIPPED;',
             '    if (0)\n'
             '        return MIX_TL_SKIPPED;                     /* mutated */'),
        ], 'loop_path_mix_skip: a child named exactly mix creates nothing; '
           'position and spacing still publish'),
        ('slot_error_attribution_inverted', BODY, [
            ('            if (parser->error == 0) {',
             '            if (parser->error != 0) {              /* mutated */'),
        ], 'loop_error_slot_not_found: 0x28ea10 reads the failing slot\'s '
           'member key from [sp+0x2c]'),
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
    report = {'schema': 'cally-animations-loop-check/1',
              'tier': 'test_anchored', 'original_executed': False,
              'entry': ('animations loop: B3 0x28d2d4-0x28d3b4, B4 0x28d3b4-0x28d4ec, '
                        'families B5/B6/B7/B12/B13+B17/B14/B15/B16, publish 0x28e774-0x28e79c, '
                        'B5 slot-not-found 0x28ea10-0x28ea3c'),
              'scope': ('Reconstructed C only, real links to all nine family modules and '
                        'their real dependencies (Json_*, readCurve, toColor, setError, '
                        'dispose pair, findBoneIndex/findSlotIndex/findSkin, getAttachment, '
                        '_malloc/_calloc/_free). Family order derived from the fall-through '
                        'chain, not addresses. Handoffs completed: path->B17 with B13 '
                        'resume, deform->E4, drawOrder->E6, and the unowned 0x28ea10 block. '
                        'Synthetic boundaries: spAnimation_create, all timeline create/'
                        'setFrame bodies, findEvent/findIkConstraint/findTransformConstraint/'
                        'findPathConstraint, spEvent_create/spEventData_create, the fixture '
                        'heap/reporter/Json builders. Not an original-equivalence claim.'),
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
                    raise RuntimeError(
                        f'mutant not rejected by its named assertion: {name}: '
                        f'failures={r.get("failures")} diag={r.get("diagnostic", "")[:2000]}')
                print('TEETH', name, r['failures'], flush=True)
            guards = [
                ('missing-loop-body', BODY,
                 ['readSkeletonData_animationsLoop']),
                ('missing-tl-slots', C / 'spine_read_tl_slots/src/spine_read_tl_slots.c',
                 ['readSkeletonData_slotTimelines']),
                ('missing-tl-bones', C / 'spine_read_tl_bones/src/spine_read_tl_bones.c',
                 ['readSkeletonData_boneTimelines']),
                ('missing-tl-event', C / 'spine_read_tl_event/src/spine_read_tl_event.c',
                 ['readSkeletonData_eventTimelines',
                  'readSkeletonData_publishAnimation']),
                ('missing-read-curve', C / 'spine_read_curve/src/spine_read_curve.c',
                 ['readCurve']),
            ]
            for gname, src, wanted in guards:
                missing = build(ns.out, gname, omit=(src,))
                diag = missing.get('diagnostic', '')
                if not missing['compile_rc'] or any(
                        'undefined symbol: ' + w not in diag for w in wanted):
                    raise RuntimeError(f'{gname}: not refused by the linker: {diag}')
                report['compile_guards'].append({'name': gname, 'refused': True,
                                                 'undefined_symbols': wanted,
                                                 **missing})
                print('GUARD', gname, 'refused', flush=True)
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
