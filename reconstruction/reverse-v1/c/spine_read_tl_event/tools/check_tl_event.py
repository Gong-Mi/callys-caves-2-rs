#!/usr/bin/env python3
"""Original is read-only. Execute only rebuilt ARM32 C plus synthetic
heap/libc/JSON/timeline providers. PASS is a scoped reconstructed-consumer
verdict, never an original-equivalence claim.

Subject: the event-timeline family of spSkeletonJson_readSkeletonData @0x28b84c
  B16  0x28e614..0x28e7a4 (100 insns)
       "events" node test -> spEventTimeline_create(declared) -> per frame:
       Json_getString "name" -> spSkeletonData_findEvent -> Json_getFloat
       "time" -> spEvent_create -> "int"/"float"/"string" (defaults from the
       EventData) -> the SECOND string copy at _malloc line 494 into event+0x10
       -> spEventTimeline_setFrame -> frame advance; then the timeline
       publish/duration tail AND the animationsCount/array publish pair.
  E5   0x28e7b4..0x28e7f4 (16 insns)
       "Event not found: ", reached only from 0x28e6a0 beq 0x28e7b4 with
       r8 == 0, so the setError json argument is NULL.
  B18  0x28e7a4..0x28e7b4 (4 insns)
       Json_dispose(the ROOT tree at [sp+0x24]) then return data.

Census open #7 (event name second copy) and open #10 (animationsCount publish
order) are the two pins this module exists to close; the .c/.h carry the
instruction-level argument and the fixture drives its consequences (fresh
block, field, length, contents, disposal pair; count stored before the element
and the element at the OLD cursor).

BOUNDARY: nothing outside 0x28e614..0x28e7f4 is translated.  0x28e7a4's two
other predecessors (0x28d2a4/0x28d2d0, the B2 "no animations" edges) belong to
c/spine_read_animations; B18 is translated here because it is in this window.
0x28e774..0x28e79c (the animation publish) IS in this window and is translated;
the outer loop cursor advance 0x28e790..0x28e79c is not.

Real recovered chain under test (all bodies recovered, no stubs):
  Json_getItem/getString/getInt/getFloat   c/json_interface
  Json_dispose / ReportSpineError          c/spine_json_support
  _spSkeletonJson_setError                 c/spine_json_error
  spAnimation_dispose / spSkeletonData_dispose / spEventData_dispose
                                           c/spine_skeleton_data
  _malloc / _free / _calloc                c/spine_alloc

Declared synthetic boundaries (NOT recovered bodies):
  spSkeletonData_findEvent 0x28b180, spEvent_create 0x285b44,
  spEvent_dispose 0x285b78, spEventTimeline_create 0x282c8c,
  spEventTimeline_setFrame 0x282d14, fixture heap + allocator roster,
  libc providers, hand-built Json nodes.

Nothing here executes original libyoyo bytes.  Static anchors (SHA, dynsym,
instruction words, branch targets, pc-relative literals) are checked before any
run.
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
MOD = C / 'spine_read_tl_event'
FIX = MOD / 'fixture/check.c'
BODY = MOD / 'src/spine_read_tl_event.c'
HEADER = MOD / 'src/spine_read_tl_event.h'
PIN = '3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a'
TAG = 'jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c'
EVENT_TAG = 'jni/../jni/yoyo/../../../spine-c/src/spine/Event.c'
EVENTDATA_TAG = 'jni/../jni/yoyo/../../../spine-c/src/spine/EventData.c'
ANIM_TAG = 'jni/../jni/yoyo/../../../spine-c/src/spine/Animation.c'
JSON_SRC = C / 'json_interface/src/json_interface.c'
ERR_SRC = C / 'spine_json_error/src/spine_json_error.c'
SUPPORT_SRC = C / 'spine_json_support/src/spine_json_support.c'
SKEL_SRC = C / 'spine_skeleton_data/src/spine_skeleton_data.c'
SOURCES = [C / p for p in (
    'spine_alloc/src/spine_alloc.c',
    'json_interface/src/json_interface.c',
    'spine_skeleton_data/src/spine_skeleton_data.c',
    'spine_json_support/src/spine_json_support.c',
    'spine_json_error/src/spine_json_error.c',
    'spine_read_tl_event/src/spine_read_tl_event.c',
    'csprite_resources/fixture/arm32_support.c',
    'spine_linked_postpass/fixture/reporter_adapter.c',
    'spine_read_tl_event/fixture/check.c',
)]
INCLUDES = [C / p / 'src' for p in (
    'spine_alloc', 'spine_attachment', 'spine_skeleton_data', 'json_interface',
    'spine_color', 'spine_read_mesh', 'spine_mesh', 'spine_read_vertices',
    'spine_atlas_attachment', 'spine_read_slots', 'spine_json_error',
    'spine_json_support', 'spine_read_tl_event',
)]
FLAGS = ['--target=armv7a-none-eabi', '-march=armv7-a', '-marm', '-mfpu=vfpv3',
         '-mfloat-abi=softfp', '-std=c11', '-ffreestanding', '-fno-builtin',
         '-ffp-contract=off', '-fstack-protector-strong',
         '-mstack-protector-guard=global', '-ffunction-sections',
         '-fdata-sections', '-Wall', '-Wextra', '-Werror', '-nostdlib',
         '-static', '-fuse-ld=lld', '-Wl,--gc-sections', '-Wl,-e,_start']
# Contract names emitted by the fixture, in execution order.
TESTS = ['event_absent', 'event_without_frames', 'frame_defaults_from_eventdata',
         'frame_all_keys', 'event_lookup_scan', 'event_not_found_e5',
         'open7_string_copy_ownership', 'open7_null_string_no_copy',
         'declared_vs_child_count', 'two_frames_cursor',
         'publish_animation_order', 'finish_disposes_root',
         'e5_empty_event_table']
SUMMARY = 'SUMMARY all declared event timeline family contracts passed'

# Raw original instruction words: the node test, the create call, the lookup,
# the four key reads, BOTH string stores (+0x10 and the EventData default),
# the line-494 chain, the setFrame call, the frame back edge, the timeline
# publish/duration tail, the animationsCount pair, B18 and the E5 staging.
WORD_PINS = {
    0x28e614: 0xe59d204c,  # ldr r2,[sp,#0x4c]       — the events node
    0x28e618: 0xe3520000,  # cmp r2,#0
    0x28e61c: 0x0a000054,  # beq 0x28e774            — absent -> animation publish
    0x28e620: 0xe592000c,  # ldr r0,[r2,#0xc]        — DECLARED frame count
    0x28e624: 0xebffd198,  # bl spEventTimeline_create
    0x28e638: 0x0a00003e,  # beq 0x28e738            — no frames -> publish
    0x28e680: 0xebffe368,  # bl Json_getString       — "name"
    0x28e68c: 0xebfff2bb,  # bl spSkeletonData_findEvent
    0x28e698: 0xe2508000,  # subs r8,r0,#0           — the lookup result
    0x28e6a0: 0x0a000043,  # beq 0x28e7b4            — the ONLY edge into E5
    0x28e6ac: 0xebffdd24,  # bl spEvent_create
    0x28e6b0: 0xe5982004,  # ldr r2,[r8,#0x4]        — int default from EventData
    0x28e6c4: 0xe5982008,  # ldr r2,[r8,#0x8]        — float default
    0x28e6cc: 0xe5840008,  # str r0,[r4,#0x8]        — event->intValue
    0x28e6e0: 0xe584000c,  # str r0,[r4,#0xc]        — event->floatValue
    0x28e6f0: 0x0a000008,  # beq 0x28e718            — NULL string -> no copy
    0x28e6f4: 0xebf89f8f,  # bl strlen
    0x28e6fc: 0xe30021ee,  # movw r2,#0x1ee          — line 494
    0x28e704: 0xe2800001,  # add r0,r0,#1            — strlen + 1
    0x28e708: 0xebffdd40,  # bl _malloc              — the line-494 block
    0x28e710: 0xe5840010,  # str r0,[r4,#0x10]       — event->stringValue (open #7)
    0x28e714: 0xebf89fa2,  # bl strcpy
    0x28e724: 0xe2855001,  # add r5,r5,#1            — frameIndex++
    0x28e728: 0xebffd179,  # bl spEventTimeline_setFrame
    0x28e734: 0x1affffce,  # bne 0x28e674           — frame loop back edge
    0x28e73c: 0xed9b7a01,  # vldr s14,[r11,#4]       — animation->duration
    0x28e750: 0xe58b0008,  # str r0,[r11,#0x8]       — timelineCount stored FIRST
    0x28e754: 0xe7816103,  # str r6,[r1,r3,lsl#2]    — timelines[OLD count]
    0x28e75c: 0xe0833102,  # add r3,r3,r2,lsl#2      — FOUR-byte stride
    0x28e760: 0xed537a01,  # vldr s15,[r3,#-4]       — times[declared-1]
    0x28e770: 0xedcb7a01,  # vstr s15,[r11,#4]       — duration store
    0x28e778: 0xe5903034,  # ldr r3,[r0,#0x34]       — animationsCount
    0x28e77c: 0xe5902038,  # ldr r2,[r0,#0x38]       — animations array
    0x28e784: 0xe5801034,  # str r1,[r0,#0x34]       — count := old+1 (open #10)
    0x28e78c: 0xe782b103,  # str r11,[r2,r3,lsl#2]   — animations[OLD count]
    0x28e7a0: 0xe1a09000,  # mov r9,r0               — data survives to B18
    0x28e7a4: 0xe59d0024,  # ldr r0,[sp,#0x24]       — the ROOT tree
    0x28e7a8: 0xebffe2c6,  # bl Json_dispose         — B18
    0x28e7b0: 0xeafff585,  # b 0x28bdcc              — shared return
    0x28e7b4: 0xe1a04008,  # mov r4,r8               — r8 == 0 -> NULL json arg
    0x28e7c4: 0xebffcb2c,  # bl spAnimation_dispose
    0x28e7dc: 0xe1a01004,  # mov r1,r4               — E5's json argument
    0x28e7ec: 0xebfff3e4,  # bl _spSkeletonJson_setError
    0x28e7f0: 0xeafffc93,  # b 0x28da44              — common error tail
    # dependency bodies whose semantics open #7 rests on
    0x285b5c: 0xe3a01014,  # mov r1,#20              — spEvent is 20 bytes
    0x285b68: 0xe5805000,  # str r5,[r0]             — +0x00 = data
    0x285b6c: 0xe5804004,  # str r4,[r0,#0x4]        — +0x04 = time
    0x285b80: 0xe5900010,  # ldr r0,[r0,#0x10]       — dispose frees +0x10
    0x285b90: 0xea00003a,  # b _free                 — dispose frees self
    0x282c90: 0xe3a01014,  # mov r1,#20              — spEventTimeline 20 bytes
    0x282cb8: 0xe3a01006,  # mov r1,#6               — timeline type
    0x282cd0: 0xe5845008,  # str r5,[r4,#0x8]        — +0x08 frameCount
    0x282cf0: 0xe584000c,  # str r0,[r4,#0xc]        — +0x0c times
    0x282cfc: 0xe5840010,  # str r0,[r4,#0x10]       — +0x10 events
    0x282d28: 0xe5922004,  # ldr r2,[r2,#0x4]        — setFrame reads event->time
    0x282d38: 0xe5832000,  # str r2,[r3]             — times[i] = time
    0x282d3c: 0xeb000bcf,  # bl _free                — frees the previous event
    0x282d44: 0xe7836105,  # str r6,[r3,r5,lsl#2]    — events[i] = event
    0x28b188: 0xe590702c,  # ldr r7,[r0,#0x2c]       — findEvent count
    0x28b194: 0xe5906030,  # ldr r6,[r0,#0x30]       — findEvent array
    0x28b1b8: 0xe5950000,  # ldr r0,[r5]             — eventData->name
    0x28b1bc: 0xebf8acec,  # bl strcmp
    0x28da48: 0xebfff4ea,  # bl spSkeletonData_dispose
    # _spEventTimeline_dispose 0x2813c0: the ONE runtime consumer of the events
    # array — it walks frameCount and calls spEvent_dispose per event.
    0x2813e0: 0xe7930104,  # ldr r0,[r3,r4,lsl#2]   — events[i]
    0x2813e8: 0xeb0011e2,  # bl spEvent_dispose     — open #7's disposal site
    0x2813f8: 0xe5950010,  # ldr r0,[r5,#0x10]      — then _free(events)
    0x281400: 0xe595000c,  # ldr r0,[r5,#0x0c]      — then _free(times)
}
SYMBOL_PINS = {
    'spSkeletonJson_readSkeletonData': (0x28b84c, 13044),
    'spEventTimeline_create': (0x282c8c, 136),
    'spEventTimeline_setFrame': (0x282d14, 56),
    'spEvent_create': (0x285b44, 52),
    'spEvent_dispose': (0x285b78, 28),
    'spEventData_create': (0x285b94, 88),
    'spEventData_dispose': (0x285bec, 36),
    'spSkeletonData_findEvent': (0x28b180, 92),
    'spAnimation_dispose': (0x28147c, 80),
    'spSkeletonData_dispose': (0x28adf8, 452),
    '_spSkeletonJson_setError': (0x28b784, 200),
    'Json_getItem': (0x2873c4, 100),
    'Json_getString': (0x287428, 28),
    'Json_getInt': (0x287460, 28),
    'Json_getFloat': (0x287444, 28),
    'Json_dispose': (0x2872c8, 88),
    '_malloc': (0x285c10, 60),
    '_calloc': (0x285c4c, 52),
    '_free': (0x285c80, 28),
    '_spTimeline_init': (0x281328, 60),
    '_spEventTimeline_dispose': (0x2813c0, 84),
}
# (literal pool word address, the ADD site whose +8 PC base resolves it,
#  expected text).  va = add_site + 8 + pool_word.
KEY_PINS = (
    (0x28eae8, 0x28e648, 'time'),                 # [sp+0x28]
    (0x28eaec, 0x28e654, 'name'),                 # r7
    (0x28eaf0, 0x28e65c, 'int'),                  # r9
    (0x28eaf4, 0x28e660, 'float'),                # [sp+0x2c]
    (0x28eaf8, 0x28e66c, 'string'),               # [sp+0x30]
    (0x28eafc, 0x28e700, TAG),                    # line-494 malloc tag
    (0x28eb00, 0x28e7e0, 'Event not found: '),    # E5 message
)
# BL call sites that must resolve to the named dynsym entry.
CALL_PINS = (
    (0x28e624, 'spEventTimeline_create'),
    (0x28e680, 'Json_getString'),
    (0x28e68c, 'spSkeletonData_findEvent'),
    (0x28e6ac, 'spEvent_create'),
    (0x28e6c0, 'Json_getInt'),
    (0x28e6d4, 'Json_getFloat'),
    (0x28e6e8, 'Json_getString'),
    (0x28e708, '_malloc'),
    (0x28e728, 'spEventTimeline_setFrame'),
    (0x28e7a8, 'Json_dispose'),
    (0x28e7c4, 'spAnimation_dispose'),
    (0x28e7ec, '_spSkeletonJson_setError'),
    (0x28b1bc, '__plt_strcmp'),
    (0x282d3c, '_free'),
    (0x28da48, 'spSkeletonData_dispose'),
    (0x2813e8, 'spEvent_dispose'),
    (0x2813fc, '_free'),
    (0x281404, '_free'),
)
# Branch edges that define the boundaries this module claims.
EDGE_PINS = (
    (0x28e61c, 0x28e774),   # beq: events absent -> animation publish
    (0x28e638, 0x28e738),   # beq: no frames -> publish tail
    (0x28e6a0, 0x28e7b4),   # beq: findEvent miss -> E5
    (0x28e6f0, 0x28e718),   # beq: NULL string -> skip the copy
    (0x28e734, 0x28e674),   # bne: frame loop back edge
    (0x28e7b0, 0x28bdcc),   # b:   B18 -> shared return
    (0x28e7f0, 0x28da44),   # b:   E5 -> common error tail
)
PLT_STRCMP = 0xb6574


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


def branch_target(word, addr):
    """ARM32 B/BL (cond): bits 27..25 == 0b101, imm24<<2 signed."""
    if ((word >> 25) & 7) != 5:
        raise ValueError(f'not a B/BL at {addr:#x}: {word:#x}')
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
        sec = e.get_section_by_name('.dynsym')
        if sec is None:
            raise ValueError('.dynsym missing')
        found = {}
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

        def u32(a):
            return struct.unpack('<I', raw(a, 4))[0]

        words = {hex(a): u32(a) for a in WORD_PINS}
        for a, want in WORD_PINS.items():
            if words[hex(a)] != want:
                raise ValueError(f'word pin drifted at {a:#x}: '
                                 f'{words[hex(a)]:#x} != {want:#x}')
        # The line-494 malloc's movw immediate must be 494, not just any word.
        w = u32(0x28e6fc)
        imm16 = ((w >> 16) & 0xF) << 12 | (w & 0xfff)
        if imm16 != 494:
            raise ValueError(f'line immediate at 0x28e6fc is {imm16}')
        # Every BL in CALL_PINS must land on its named entry (or on the two
        # imported libc PLT slots, which .dynsym does not carry as code).
        calls = []
        for site, want in CALL_PINS:
            got = bl_target(u32(site), site)
            target = PLT_STRCMP if want == '__plt_strcmp' else found[want][0]
            if got != target:
                raise ValueError(f'call target {site:#x} -> {got:#x} is not '
                                 f'{want} {target:#x}')
            calls.append([hex(site), hex(got), want])
        for site, want in EDGE_PINS:
            got = branch_target(u32(site), site)
            if got != want:
                raise ValueError(f'branch edge {site:#x} -> {got:#x} != {want:#x}')
        # Census §2.9: the event family has NO readCurve call site.  Scan every
        # aligned word of the three translated windows.
        windows = ((0x28e614, 0x28e7a4), (0x28e7a4, 0x28e7b4),
                   (0x28e7b4, 0x28e7f4))
        bls = []
        curve_hits = []
        for lo, hi in windows:
            for a in range(lo, hi, 4):
                w = u32(a)
                if (w >> 24) == 0xeb:
                    t = bl_target(w, a)
                    bls.append([hex(a), hex(t)])
                    if t == 0x28b34c:
                        curve_hits.append(hex(a))
        if curve_hits:
            raise ValueError('a readCurve call site exists in the event windows: '
                             f'{curve_hits}')
        keys = []
        for pool, add_site, want in KEY_PINS:
            w = u32(pool)
            va = (add_site + 8 + w) & 0xffffffff
            value = raw(va, 96).split(b'\0', 1)[0].decode('ascii')
            if value != want:
                raise ValueError(f'pc-relative key mismatch {add_site:#x}: '
                                 f'{value!r} != {want!r}')
            keys.append({'pool': hex(pool), 'add_site': hex(add_site),
                         'va': hex(va), 'value': value})
    return {'original_sha256': PIN,
            'symbol_pins': {k: [hex(v[0]), v[1]] for k, v in SYMBOL_PINS.items()},
            'word_pins': words, 'call_pins': calls,
            'edge_pins': [[hex(a), hex(t)] for a, t in EDGE_PINS],
            'segment_key_literals': keys,
            'translated_window_bls': bls,
            'readcurve_call_sites': curve_hits,
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
    print('BINDING v1 entry=tl-event run=' + name
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
    """Named mutants of the BODY text only; each must be refused by a NAMED
    runtime assertion.  Every mutant still compiles cleanly."""
    return [
        # --- open #7: the second string copy ------------------------------
        ('string_copy_dropped', BODY, [
            ('        char* copy = (char*)_malloc(length + 1u, SPINE_JSON_SOURCE_TAG,\n'
             '                                    EVENT_LINE_STRING);\n'
             '        event->stringValue = copy;                     /* 0x28e710 */\n'
             '        strcpy(copy, value);                           /* 0x28e70c/0x28e714 */',
             '        (void)length;\n'
             '        event->stringValue = (char*)value;   /* mutated: alias, no copy */')],
         'an absent "string" still produces a fresh copy of the EventData +0x0c value'),
        ('line494_size_no_plus_one', BODY, [
            ('        char* copy = (char*)_malloc(length + 1u, SPINE_JSON_SOURCE_TAG,',
             '        char* copy = (char*)_malloc(length, SPINE_JSON_SOURCE_TAG,')],
         'the line-494 request is strlen(default)+1 = 5'),
        ('string_copy_wrong_bytes', BODY, [
            ('        strcpy(copy, value);                           /* 0x28e70c/0x28e714 */',
             '        strcpy(copy, "x");                     /* mutated: wrong bytes */')],
         'the copy holds the EventData string bytes, not a pointer'),
        ('int_key_literal', BODY, [
            ('Json_getInt(frame, "int", event_data->intValue)',
             'Json_getInt(frame, "integer", event_data->intValue)')],
         'event+0x08 = Json_getInt "int" (0x28e6cc)'),
        ('int_default_zero', BODY, [
            ('    event->intValue = Json_getInt(frame, "int", event_data->intValue);',
             '    event->intValue = Json_getInt(frame, "int", 0);   /* mutated */')],
         'an absent "int" takes the EventData +0x04 default (0x28e6b0)'),
        # --- E5 -----------------------------------------------------------
        ('e5_json_argument', BODY, [
            ('                             0,                        /* 0x28e7dc */',
             '                             (Json*)frame,              /* mutated */')],
         'E5 passes NULL as the setError json argument: NO Json node is disposed'),
        ('e5_message_literal', BODY, [
            ('#define ERR_EVENT_NOT_FOUND "Event not found: "',
             '#define ERR_EVENT_NOT_FOUND "Event not found:"')],
         "E5 message is the exact literal plus the frame's \"name\""),
        ('e5_dispose_order', BODY, [
            ('    spAnimation_dispose((spAnimation*)animation_raw);  /* 0x28e7c4 */',
             '    spSkeletonData_dispose((spSkeletonData*)data_raw); /* mutated order */\n'
             '    spAnimation_dispose((spAnimation*)animation_raw);  /* 0x28e7c4 */'),
            ('    spSkeletonData_dispose((spSkeletonData*)data_raw); /* 0x28da48 */',
             '    /* mutated: data already disposed above */')],
         'E5 disposes the animation BEFORE the skeleton data (0x28e7c4 then 0x28da48)'),
        # --- publish tails ------------------------------------------------
        ('timeline_count_not_bumped', BODY, [
            ('        animation->timelineCount = count + 1;          /* 0x28e74c/0x28e750 */',
             '        animation->timelineCount = count;              /* mutated */')],
         'the zero-frame timeline is still published at the old cursor (0x28e750/0x28e754)'),
        ('duration_index_zero', BODY, [
            ('        last = timeline->times[declared - 1u];',
             '        last = timeline->times[declared * 0u];         /* mutated */')],
         'duration reads times[declared-1] = times[2] (zero), not times[0] (0x28e75c/0x28e760)'),
        ('publish_count_not_bumped', BODY, [
            ('    data->animationsCount = count + 1;                 /* 0x28e780/0x28e784 */',
             '    data->animationsCount = count;                     /* mutated */')],
         'animationsCount becomes old+1 (0x28e780/0x28e784)'),
        ('publish_index_off_by_one', BODY, [
            ('    table[count] = animation_raw;                      /* 0x28e78c */',
             '    table[count + 1] = animation_raw;                  /* mutated */')],
         'the animation lands at the OLD cursor (0x28e78c uses r3 before the bump)'),
        # --- B18 ----------------------------------------------------------
        ('b18_dispose_dropped', BODY, [
            ('    Json_dispose(root);                                /* 0x28e7a4/0x28e7a8 */',
             '    (void)root;                                        /* mutated */')],
         'B18 disposes the ROOT Json tree from [sp+0x24] (0x28e7a4/0x28e7a8)'),
        ('b18_returns_null', BODY, [
            ('    return data_raw;                                   /* 0x28e7ac/0x28e7b0 */',
             '    (void)data_raw; return 0;                          /* mutated */')],
         'B18 returns the skeleton data (0x28e7ac mov r0,r9)'),
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
    report = {'schema': 'cally-tl-event-check/1', 'tier': 'test_anchored',
              'original_executed': False,
              'entry': ('event timeline family (readSkeletonData caller block '
                        'B16 0x28e614-0x28e7a4, E5 0x28e7b4-0x28e7f4, B18 '
                        '0x28e7a4-0x28e7b4)'),
              'scope': ('Reconstructed event C only: real Json_getString/'
                        'getInt/getFloat, real Json_dispose, real '
                        'spAnimation_dispose/spSkeletonData_dispose and '
                        '_spSkeletonJson_setError, the name lookup driver, the '
                        'four per-frame keys with EventData defaults, the '
                        'line-494 event-stringValue copy, setFrame storage, the '
                        'timeline publish/duration tail, the animationsCount/'
                        'array publish pair and B18. Synthetic boundaries: '
                        'spSkeletonData_findEvent 0x28b180, spEvent_create '
                        '0x285b44, spEvent_dispose 0x285b78, spEventTimeline_'
                        'create 0x282c8c and setFrame 0x282d14 (argument '
                        'recorders whose bodies follow the disassembly), fixture '
                        'heap + allocator roster, libc providers, hand-built '
                        'Json nodes. Not an original-equivalence claim.'),
              'boundary': {
                  'b16_translated': '0x28e614-0x28e7a4 (100 insns)',
                  'e5_translated': '0x28e7b4-0x28e7f0 (15 insns) + shared tail '
                                   '0x28da44-0x28da50',
                  'b18_translated': '0x28e7a4-0x28e7b4 (4 insns)',
                  'e5_entry_edge': '0x28e698 subs r8,r0,#0 ; 0x28e6a0 beq 0x28e7b4 '
                                   '(the ONLY predecessor; r8 == 0 -> NULL json arg)',
                  'b18_predecessors': ['0x28e7a0 fall-through (outer animation loop '
                                       'exhausted)',
                                       '0x28d2a4 beq 0x28e7a4 (no "animations" member, '
                                       'B2)',
                                       '0x28d2d0 beq 0x28e7a4 (no animation children, '
                                       'B2)'],
                  'not_translated': ['0x28e7f4-0x28e820 (attachment "Unknown attachment '
                                     'type: " island, not reachable from this segment)',
                                     '0x28e790-0x28e79c (outer animation loop cursor; '
                                     'owned by c/spine_read_animations)']},
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
            missing = build(ns.out, 'missing-tl-event-body', omit=(BODY,))
            if (not missing['compile_rc']
                    or 'undefined symbol: readSkeletonData_eventTimelines'
                    not in missing['diagnostic']):
                raise RuntimeError('missing event body not refused')
            report['compile_guards'].append({'name': 'missing-tl-event-body',
                                             'refused': True, **missing})
            print('GUARD missing-tl-event-body refused', flush=True)
            nojson = build(ns.out, 'unlinked-json-interface', omit=(JSON_SRC,))
            if (not nojson['compile_rc']
                    or 'undefined symbol: Json_getString' not in nojson['diagnostic']):
                raise RuntimeError('Json accessor source removal not refused')
            report['compile_guards'].append({'name': 'unlinked-json-interface',
                                             'refused': True, **nojson})
            print('GUARD unlinked-json-interface refused', flush=True)
            noerr = build(ns.out, 'unlinked-json-error', omit=(ERR_SRC,))
            if (not noerr['compile_rc']
                    or 'undefined symbol: _spSkeletonJson_setError'
                    not in noerr['diagnostic']):
                raise RuntimeError('setError source removal not refused')
            report['compile_guards'].append({'name': 'unlinked-json-error',
                                             'refused': True, **noerr})
            print('GUARD unlinked-json-error refused', flush=True)
            nosup = build(ns.out, 'unlinked-json-support', omit=(SUPPORT_SRC,))
            if (not nosup['compile_rc']
                    or 'undefined symbol: Json_dispose' not in nosup['diagnostic']):
                raise RuntimeError('Json_dispose source removal not refused')
            report['compile_guards'].append({'name': 'unlinked-json-support',
                                             'refused': True, **nosup})
            print('GUARD unlinked-json-support refused', flush=True)
            noskel = build(ns.out, 'unlinked-skeleton-data', omit=(SKEL_SRC,))
            if (not noskel['compile_rc']
                    or 'undefined symbol: spAnimation_dispose'
                    not in noskel['diagnostic']):
                raise RuntimeError('skeleton-data disposal removal not refused')
            report['compile_guards'].append({'name': 'unlinked-skeleton-data',
                                             'refused': True, **noskel})
            print('GUARD unlinked-skeleton-data refused', flush=True)
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
