#!/usr/bin/env python3
"""Original is read-only. Execute only rebuilt ARM32 animations C plus
synthetic heap/libc/JSON/creator providers. PASS is a scoped reconstructed-
consumer verdict, never an original-equivalence claim.

Subject: five caller blocks of spSkeletonJson_readSkeletonData @0x28b84c:
  B1  0x28d19c..0x28d290 (244 B / 61 insns)
      skeleton-wide events array (malloc line 1028) + EventData loop
      (string deep copy malloc line 1034)
  B2  0x28d290..0x28d2d4 (68 B / 17 insns)
      animations array (malloc line 1043)
  B3  0x28d2d4..0x28d3b4 (224 B / 56 insns)
      per-animation preamble (four cached key literals + 0x55555556 into
      [sp,#0x60]) and the eight-key Json_getItem lookup; no allocation
  B3b 0x28eb28..0x28eb40 (24 B / 6 insns)
      legacy "draworder" retry, out of line at the function tail
  B4  0x28d3b4..0x28d4ec (312 B / 78 insns)
      timelineCount sum + spAnimation_create; no allocation

Real recovered chain under test:
    readSkeletonData_eventsArray -> Json_getItem(tree,"events"),
        data+0x2c = events->unk_0c, _malloc(count*4,TAG,1028) -> data+0x30,
        return events->child (array published even when child==0)
    readSkeletonData_eventsSegment -> per child: spEventData_create(child->name),
        Json_getInt("int")->+0x04, Json_getFloat("float")->+0x08,
        Json_getString("string") -> strlen + _malloc(len+1,TAG,1034) + strcpy
        -> +0x0c, publish via byte cursor, child=child->next
    readSkeletonData_animationsArray -> Json_getItem(tree,"animations"),
        _malloc(count*4,TAG,1043) -> data+0x38, return animations->child;
        data+0x34 (animationsCount) is NOT written in this block
    readSkeletonData_animationFrameInit -> four key literals into the frame's
        +0x4c..+0x58 slots, 0x55555556 into +0x48, data/spSkeletonJson spills
        into +0x00/+0x08; runs once per animations array (the loop back edge
        0x28e79c re-enters at 0x28d318, inside B3, not here)
    readSkeletonData_animationKeys -> eight Json_getItem(animation, key) calls
        in address order (bones, slots, ik, transform, paths, deform,
        drawOrder, events) into the frame's node slots; returns the slots node
        that stays in r4; on a drawOrder miss it runs B3b and continues at B4
    readSkeletonData_animationLegacyDrawOrder -> Json_getItem(animation,
        "draworder") stored unconditionally into the drawOrder slot
    readSkeletonData_animationTimelines -> per-group sum then
        spAnimation_create(animation->name, count); zeroes animation+0x08;
        publishes slots->child into +0x14 when the slots node exists

Declared synthetic boundaries (NOT recovered bodies):
  * spEventData_create (EventData.c, 0x285b94) — fixture probe table records
    the single name argument.
  * spAnimation_create (Animation.c, 0x2812b4, 116 B) — fixture probe records
    (name, timelineCount) and returns a zeroed 16-byte record. Its layout facts
    (+0x00 name, +0x08 count, +0x0c array) are cited statically from
    0x2812fc/0x281304/0x281318, not executed.
  * the fixture heap + allocator roster, the libc string providers, the
    hand-built Json nodes, and the outer-loop tail 0x28e774..0x28e79c (the
    fixture advances the animation node slot itself, marked as such).

Evidence note carried in the tests: the real Json_getItem compares with
strcasecmp (0x287414 bl strcasecmp@plt), so "drawOrder" and "draworder" are one
query and the legacy retry can never find a node the first lookup missed.

Nothing here executes original libyoyo bytes. Static anchors (SHA, dynsym,
instruction words, pc-relative key literals) are checked before any run.
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
MOD = C / 'spine_read_animations'
FIX = MOD / 'fixture/check.c'
BODY = MOD / 'src/spine_read_animations.c'
HEADER = MOD / 'src/spine_read_animations.h'
PIN = '3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a'
SOURCES = [C / p for p in (
    'spine_alloc/src/spine_alloc.c', 'json_interface/src/json_interface.c',
    'spine_read_animations/src/spine_read_animations.c',
    'csprite_resources/fixture/arm32_support.c',
    'spine_read_animations/fixture/check.c',
)]
INCLUDES = [C / p / 'src' for p in (
    'spine_alloc', 'spine_attachment', 'spine_skeleton_data', 'json_interface',
    'spine_color', 'spine_read_mesh', 'spine_mesh', 'spine_read_vertices',
    'spine_atlas_attachment', 'spine_read_slots', 'skeleton_find',
    'spine_json_error', 'spine_json_support', 'spine_read_animations',
)]
FLAGS = ['--target=armv7a-none-eabi', '-march=armv7-a', '-marm', '-mfpu=vfpv3',
         '-mfloat-abi=softfp', '-std=c11', '-ffreestanding', '-fno-builtin',
         '-ffp-contract=off', '-fstack-protector-strong',
         '-mstack-protector-guard=global', '-ffunction-sections',
         '-fdata-sections', '-Wall', '-Wextra', '-Werror', '-nostdlib',
         '-static', '-fuse-ld=lld', '-Wl,--gc-sections', '-Wl,-e,_start']
# Contract names emitted by the fixture, in execution order.
TESTS = ['events_absent', 'events_empty_children', 'events_zero_count',
         'events_multiple_fields', 'events_count_is_allocation_only',
         'animations_absent', 'animations_empty_children',
         'animations_children', 'chain_order',
         'animation_frame_init', 'animation_keys_eight', 'animation_keys_missing',
         'animation_magic_signed_div3', 'animation_timelines_empty',
         'animation_timelines_sums', 'animation_timelines_partial',
         'animation_deform_nested', 'animation_legacy_both_keys',
         'animation_legacy_fallback', 'animation_chain_two']
SUMMARY = 'SUMMARY all declared animations entry and per-animation contracts passed'
BLOCKS = [
    {'name': 'B1', 'range': '0x28d19c..0x28d290', 'bytes': 244, 'insns': 61,
     'role': 'events array (malloc 1028) + EventData loop (malloc 1034)'},
    {'name': 'B2', 'range': '0x28d290..0x28d2d4', 'bytes': 68, 'insns': 17,
     'role': 'animations array (malloc 1043)'},
    {'name': 'B3', 'range': '0x28d2d4..0x28d3b4', 'bytes': 224, 'insns': 56,
     'role': 'per-animation 8-key lookup + cached keys + 0x55555556; no malloc'},
    {'name': 'B3b', 'range': '0x28eb28..0x28eb40', 'bytes': 24, 'insns': 6,
     'role': 'legacy "draworder" retry (out of line); no malloc'},
    {'name': 'B4', 'range': '0x28d3b4..0x28d4ec', 'bytes': 312, 'insns': 78,
     'role': 'timelineCount sum + spAnimation_create; no malloc'},
]
# Raw original instruction words that constitute the blocks' structural pins
# (control-flow forks, field stores, key-cache stores, the division magic).
WORD_PINS = {
    # --- B1 / B2 (unchanged pins; must not regress) ---
    0x28d1ac: 0xe2504000,  # subs r4,r0,#0        — getItem("events") null test
    0x28d1b0: 0x0a000036,  # beq 0x28d290         — absent events skips to B2
    0x28d1b8: 0xe3002404,  # movw r2,#0x404       — malloc line 1028
    0x28d1c0: 0xe589002c,  # str r0,[r9,#0x2c]    — eventsCount BEFORE malloc
    0x28d1cc: 0xebffe28f,  # bl _malloc
    0x28d1d8: 0xe5890030,  # str r0,[r9,#0x30]    — events array publish
    0x28d1dc: 0x0a00002b,  # beq 0x28d290         — empty child list skips loop
    0x28d20c: 0xe594001c,  # ldr r0,[r4,#0x1c]    — NAME = Json member key
    0x28d210: 0xebffe25f,  # bl spEventData_create
    0x28d224: 0xebffe88d,  # bl Json_getInt
    0x28d230: 0xe5850004,  # str r0,[r5,#0x4]     — intValue +0x04
    0x28d238: 0xebffe881,  # bl Json_getFloat
    0x28d244: 0xe5850008,  # str r0,[r5,#0x8]     — floatValue +0x08
    0x28d24c: 0xebffe875,  # bl Json_getString
    0x28d260: 0xe300240a,  # movw r2,#0x40a       — malloc line 1034
    0x28d268: 0xebffe268,  # bl _malloc
    0x28d270: 0xe585000c,  # str r0,[r5,#0xc]     — stringValue +0x0c
    0x28d27c: 0xe783500a,  # str r5,[r3,r10]      — publish at byte cursor
    0x28d280: 0xe28aa004,  # add r10,r10,#4
    0x28d28c: 0x1affffde,  # bne 0x28d20c         — loop on child list
    0x28d2a4: 0x0a00053e,  # beq 0x28e7a4         — absent animations ends segment
    0x28d2ac: 0xe3002413,  # movw r2,#0x413       — malloc line 1043
    0x28d2bc: 0xebffe253,  # bl _malloc
    0x28d2c0: 0xe5944004,  # ldr r4,[r4,#0x4]     — animations->child
    0x28d2cc: 0xe5890038,  # str r0,[r9,#0x38]    — animations array, NOT +0x34
    0x28d2d0: 0x0a000533,  # beq 0x28e7a4         — empty child list ends segment
    # --- B3 preamble: the division magic and its slot ---
    0x28d2d8: 0xe3051556,  # movw r1,#0x5556
    0x28d2e0: 0xe3451555,  # movt r1,#0x5555      — r1 = 0x55555556
    0x28d304: 0xe58d1060,  # str r1,[sp,#0x60]    — the magic's only write
    # --- B3 loop head: cached key loads ---
    0x28d318: 0xe59d1064,  # ldr r1,[sp,#0x64]    — loop head, cached "bones"
    0x28d324: 0xe59d1068,  # ldr r1,[sp,#0x68]    — cached "slots"
    0x28d334: 0xe59d106c,  # ldr r1,[sp,#0x6c]    — cached "ik"
    0x28d344: 0xe59d1070,  # ldr r1,[sp,#0x70]    — cached "transform"
    # --- B3 node-slot stores, in address order ---
    0x28d328: 0xe58d0030,  # str r0,[sp,#0x30]    — bones
    0x28d338: 0xe1a04000,  # mov r4,r0            — slots stays in r4
    0x28d348: 0xe58d0034,  # str r0,[sp,#0x34]    — ik
    0x28d35c: 0xe58d0038,  # str r0,[sp,#0x38]    — transform
    0x28d370: 0xe58d0044,  # str r0,[sp,#0x44]    — paths
    0x28d384: 0xe58d0050,  # str r0,[sp,#0x50]    — deform
    0x28d398: 0xe58d0028,  # str r0,[sp,#0x28]    — drawOrder
    0x28d3ac: 0xe58d004c,  # str r0,[sp,#0x4c]    — events
    0x28d3b0: 0x0a0005dc,  # beq 0x28eb28         — drawOrder miss -> B3b
    # --- B4 sum and create ---
    0x28d3bc: 0x0a0005af,  # beq 0x28ea80         — bones absent -> zero total
    0x28d3e0: 0x1afffffa,  # bne 0x28d3d0         — bones child loop
    0x28d408: 0x1afffffa,  # bne 0x28d3f8         — slots child loop
    0x28d418: 0x1590200c,  # ldrne r2,[r0,#0xc]   — ik field read, no child loop
    0x28d428: 0xe0833002,  # add r3,r3,r2
    0x28d438: 0xe0831002,  # add r1,r3,r2         — accumulator r3 -> r1
    0x28d45c: 0x1afffffa,  # bne 0x28d44c         — paths child loop
    0x28d494: 0x1afffffa,  # bne 0x28d484         — deform slot loop
    0x28d4a0: 0x1afffff4,  # bne 0x28d478         — deform skin loop
    0x28d4b4: 0x12811001,  # addne r1,r1,#1       — drawOrder +1
    0x28d4bc: 0x12811001,  # addne r1,r1,#1       — events +1
    0x28d4c0: 0xe592001c,  # ldr r0,[r2,#0x1c]    — name = animation member key
    0x28d4c4: 0xebffcf7a,  # bl spAnimation_create
    0x28d4d4: 0xe5803008,  # str r3,[r0,#0x8]     — animation timelineCount := 0
    0x28d4e4: 0xe58d402c,  # str r4,[sp,#0x2c]    — slots->child for the B5 loop
    # --- B3b legacy retry ---
    0x28eb28: 0xe51f100c,  # ldr r1,[pc,#-0xc]    — pool 0x28eb24
    0x28eb34: 0xebffe222,  # bl Json_getItem
    0x28eb38: 0xe58d0028,  # str r0,[sp,#0x28]    — unconditional drawOrder store
    0x28eb3c: 0xeafffa1c,  # b 0x28d3b4           — back to B4
}
SYMBOL_PINS = {
    'spSkeletonJson_readSkeletonData': (0x28b84c, 13044),
    'Json_getItem': (0x2873c4, 100),
    'Json_getString': (0x287428, 28),
    'Json_getFloat': (0x287444, 28),
    'Json_getInt': (0x287460, 28),
    '_malloc': (0x285c10, 60),
    'spEventData_create': (0x285b94, 88),
    'spAnimation_create': (0x2812b4, 116),
}
# (literal pool word address, the ADD site whose +8 PC base resolves it,
#  expected text).  va = add_site + 8 + pool_word — pass the ADD instruction
#  address, not its already-biased base.
KEY_PINS = (
    (0x28c9d8, 0x28d1a4, 'events'),
    (0x28c9f0, 0x28d298, 'animations'),
    (0x28c9e0, 0x28d1f0, 'int'),
    (0x28c9ec, 0x28d204, 'float'),
    (0x28c9e4, 0x28d1f4, 'string'),
    (0x28c9dc, 0x28d1c4, 'jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c'),
    (0x28c9f4, 0x28d2b8, 'jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c'),
    (0x28c9f8, 0x28d2e4, 'bones'),
    (0x28c9fc, 0x28d2f0, 'slots'),
    (0x28ca00, 0x28d2f8, 'ik'),
    (0x28ca04, 0x28d300, 'transform'),
    (0x28ca08, 0x28d358, 'paths'),
    (0x28ca0c, 0x28d36c, 'deform'),
    (0x28ca10, 0x28d380, 'drawOrder'),
    (0x28ca14, 0x28d394, 'events'),
    (0x28eb24, 0x28eb30, 'draworder'),
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
        # This library has no .symtab; .dynsym is the authoritative table.
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
                raise ValueError(f'word pin drifted at {a:#x}: {words[hex(a)]:#x} != {want:#x}')
        keys = []
        for pool, add_site, want in KEY_PINS:
            w = struct.unpack('<I', raw(pool, 4))[0]
            va = (add_site + 8 + w) & 0xffffffff
            value = raw(va, 96).split(b'\0', 1)[0].decode('ascii')
            if value != want:
                raise ValueError(f'pc-relative key mismatch {add_site:#x}: {value!r} != {want!r}')
            keys.append({'pool': hex(pool), 'add_site': hex(add_site), 'va': hex(va), 'value': value})
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
    argv = ['clang', *FLAGS, opt, *extra, *['-I' + str(i) for i in INCLUDES], *used, '-o', binary]
    p = run(argv)
    (out / (name + '.build.log')).write_text(p.stdout + p.stderr)
    result = {'compile_rc': p.returncode, 'compile_command': [str(x) for x in argv]}
    if p.returncode:
        return {**result, 'diagnostic': p.stderr}
    before = sha(binary)
    result['binary_sha256'] = before
    result['translation_units'] = {str(s): sha(s) for s in used}
    print('BINDING v1 entry=animations-entry+b3b4 run=' + name
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
    """Twelve mutants of the BODY text only; each must be refused by a NAMED
    runtime assertion. No mutant may hang: every one keeps the loop bounds."""
    return [
        ('animation_magic_constant', BODY, [
            ('    frame->div3_magic = 0x55555556u;            /* 0x28d2d8/0x28d2e0/0x28d304 */',
             '    frame->div3_magic = 0x55555555u;            /* mutated */')],
         'animation_frame_init: B3 writes 0x55555556 into the sp+0x60 slot'),
        ('animation_key_cache_order', BODY, [
            ('    frame->bonesKey = "bones";                  /* 0x28d2d4/0x28d2e4/0x28d2ec */\n'
             '    frame->slotsKey = "slots";                  /* 0x28d2dc/0x28d2f0/0x28d2fc */',
             '    frame->bonesKey = "slots";                  /* mutated */\n'
             '    frame->slotsKey = "bones";                  /* mutated */')],
         'animation_frame_init: cached key pointers are bones, slots, ik, transform in slot order'),
        ('animation_key_literal_paths', BODY, [
            ('    frame->paths = Json_getItem(frame->animation, "paths");',
             '    frame->paths = Json_getItem(frame->animation, "path"); /* mutated */')],
         'animation_keys_eight: B3 paths slot holds the node named paths'),
        ('animation_slot_store_swap', BODY, [
            ('    frame->deform = Json_getItem(frame->animation, "deform");',
             '    frame->paths = Json_getItem(frame->animation, "deform"); /* mutated */')],
         'animation_keys_eight: B3 paths slot holds the node named paths'),
        ('animation_sum_start_empty_path', BODY, [
            ('        total = 0;                              /* 0x28ea80 ldr r3,[sp,#0x30] (bones == 0) */',
             '        total = 1u;                             /* mutated */')],
         'animation_timelines_empty: B4 empty animation counts zero timelines'),
        ('animation_sum_start_bones_loop', BODY, [
            ('            total = 0;                          /* 0x28d3cc mov r3,#0 */',
             '            total = 1u;                         /* mutated */')],
         'animation_timelines_sums: B4 sums bones/slots/paths/deform child sizes '
         'plus ik/transform fields plus drawOrder/events'),
        ('animation_create_arg_count', BODY, [
            ('            spAnimation_create(frame->animation->name, (int32_t)total);',
             '            spAnimation_create(frame->animation->name, (int32_t)(total & 0xffff0000u)); /* mutated */')],
         'animation_timelines_sums: B4 sums bones/slots/paths/deform child sizes '
         'plus ik/transform fields plus drawOrder/events'),
        ('animation_create_arg_name', BODY, [
            ('            spAnimation_create(frame->animation->name, (int32_t)total);',
             '            spAnimation_create((const char*)0, (int32_t)total); /* mutated */')],
         'animation_timelines_empty: create receives the animation member key as its name'),
        ('animation_create_count_reset', BODY, [
            ('        animation->timelineCount = 0;           /* 0x28d4cc mov r3,#0 / 0x28d4d4 str r3,[r0,#0x8] */',
             '        /* mutated: +0x08 reset removed */')],
         'animation_timelines_sums: B4 returns the created record with +0x08 reset'),
        ('animation_slots_child_spill', BODY, [
            ('            frame->slotsChild = slotsNode->child; /* 0x28d4dc/0x28d4e4 str r4,[sp,#0x2c] */',
             '            /* mutated: sp+0x2c spill removed */')],
         'animation_timelines_sums: B4 publishes slots->child into the sp+0x2c slot'),
        ('animation_legacy_key_typo', BODY, [
            ('    frame->drawOrder = Json_getItem(frame->animation, "draworder"); /* 0x28eb28..0x28eb38 */',
             '    frame->drawOrder = Json_getItem(frame->animation, "draworderx"); /* mutated */')],
         'animation_legacy_fallback: B3b publishes the legacy node into the drawOrder slot'),
        ('animation_legacy_wrong_slot', BODY, [
            ('    frame->drawOrder = Json_getItem(frame->animation, "draworder"); /* 0x28eb28..0x28eb38 */',
             '    frame->events = Json_getItem(frame->animation, "draworder"); /* mutated */')],
         'animation_legacy_fallback: B3b publishes the legacy node into the drawOrder slot'),
        ('animation_legacy_null_guard', BODY, [
            ('    frame->drawOrder = Json_getItem(frame->animation, "draworder"); /* 0x28eb28..0x28eb38 */',
             '    { Json* v = Json_getItem(frame->animation, "draworder"); /* mutated */\n'
             '      if (v != 0) frame->drawOrder = v; }   /* 0x28eb38 is unconditional in the original */')],
         'animation_legacy_fallback: B3b miss overwrites a stale drawOrder with NULL'),
    ]


def shadow_header(out):
    """Copy the header with one frame pad removed so the layout pins must bite.
    Returns the include directory to put ahead of the module INCLUDES."""
    text = HEADER.read_text()
    lines = text.splitlines(keepends=True)
    kept = [ln for ln in lines if 'reserved_3c;' not in ln]
    if len(kept) != len(lines) - 1:
        raise RuntimeError('frame pad line not found for the shadow-header guard')
    d = out / 'shadow-include'
    d.mkdir(parents=True, exist_ok=True)
    (d / HEADER.name).write_text(''.join(kept))
    return d


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
    report = {'schema': 'cally-animations-b3b4-check/1', 'tier': 'test_anchored',
              'original_executed': False,
              'entry': ('animations entry + per-animation blocks: B1 0x28d19c-0x28d290, '
                        'B2 0x28d290-0x28d2d4, B3 0x28d2d4-0x28d3b4, '
                        'B3b 0x28eb28-0x28eb40, B4 0x28d3b4-0x28d4ec'),
              'scope': ('Reconstructed C only: real Json_getItem/getInt/getFloat/getString, '
                        'real _malloc with tag/line, event and animation array publication, '
                        'event string deep copy, the child-list-driven EventData loop, the '
                        'per-animation 8-key lookup with its cached key literals and the '
                        '0x55555556 slot, the legacy draworder retry, and the timelineCount sum '
                        'with spAnimation_create argument sequence. Synthetic boundaries: '
                        'spEventData_create, spAnimation_create, fixture heap + allocator '
                        'roster, libc string providers, hand-built Json nodes, and the outer '
                        'loop tail 0x28e774..0x28e79c (fixture advances the animation slot). '
                        'B2 deliberately does not write data+0x34 (animationsCount). '
                        'Not an original-equivalence claim.'),
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
            missing = build(ns.out, 'missing-animations-entry-body', omit=(BODY,))
            wanted = [n for n in ('readSkeletonData_eventsSegment',
                                  'readSkeletonData_animationsArray',
                                  'readSkeletonData_animationFrameInit',
                                  'readSkeletonData_animationKeys',
                                  'readSkeletonData_animationLegacyDrawOrder',
                                  'readSkeletonData_animationTimelines')]
            diag = missing.get('diagnostic', '')
            if not missing['compile_rc'] or any(
                    'undefined symbol: ' + w not in diag for w in wanted):
                raise RuntimeError('missing animations-entry body not refused')
            report['compile_guards'].append({'name': 'missing-animations-entry-body',
                                             'refused': True,
                                             'undefined_symbols': wanted, **missing})
            print('GUARD missing-animations-entry-body refused', flush=True)
            shadow = shadow_header(ns.out)
            broken = build(ns.out, 'shadowed-frame-layout', extra=('-I' + str(shadow),))
            if (not broken['compile_rc']
                    or 'static assertion failed' not in broken.get('diagnostic', '')
                    or 'spAnimationFrame' not in broken.get('diagnostic', '')):
                raise RuntimeError('frame layout pins did not refuse a shifted frame')
            report['compile_guards'].append({'name': 'shadowed-frame-layout',
                                             'refused': True, **broken})
            print('GUARD shadowed-frame-layout refused', flush=True)
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
