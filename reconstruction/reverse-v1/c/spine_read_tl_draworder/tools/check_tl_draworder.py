#!/usr/bin/env python3
"""Original is read-only. Execute only rebuilt ARM32 C plus synthetic
heap/libc/JSON/timeline providers. PASS is a scoped reconstructed-consumer
verdict, never an original-equivalence claim.

Subject: the drawOrder timeline family of spSkeletonJson_readSkeletonData
@0x28b84c
  B15   0x28e338..0x28e528 (125 insns of census B15's 137)
        "drawOrder" node test -> spDrawOrderTimeline_create(declared, slotsCount)
        -> per frame: Json_getItem "offsets", TWO _malloc calls (line 442
        (slotsCount-jsonOffsetsSize)*4 and line 445 slotsCount*4 filled -1),
        the "slot"/"offset" entry loop feeding spSkeletonData_findSlotIndex, the
        leftover merge and _free(line 442).
  B15b  0x28e594..0x28e614 (32 insns)
        "time" -> spDrawOrderTimeline_setFrame(t, i, time, order) -> _free(order)
        -> frame advance; then the publish/duration tail.
  E4    0x28e55c..0x28e58c (13 insns of the 14 in 0x28e55c..0x28e594)
        "Attachment not found: ", reached from the DEFORM block (0x28e110
        beq 0x28e55c) with a NULL setError json argument.

BOUNDARY: 0x28e52c..0x28e558 is the path family's spacing island
(strcmp "spacing" + spPathConstraintSpacingTimeline_create + the mode select),
already recovered by c/spine_read_tl_path.  0x28e528 `b 0x28e594` is the
unconditional branch that steps over it, so the 12 instructions are NOT
translated here and no instruction is double-counted.  0x28e464 `beq 0x28e8ac`
leaves for the out-of-range "Slot not found: " block; the driver only reports
that handoff.  0x28e590 `mov r6,r4` sits in E4's address window but is the
drawOrder frame loop's "no offsets" join, translated with B15.

Real recovered chain under test (all bodies recovered, no stubs):
  Json_getItem/getString/getInt/getFloat   c/json_interface
  spSkeletonData_findSlotIndex             c/skeleton_find
  _spSkeletonJson_setError                 c/spine_json_error
  spAnimation_dispose / spSkeletonData_dispose  c/spine_skeleton_data
  Json_dispose / ReportSpineError          c/spine_json_support
  _malloc / _free / _calloc                c/spine_alloc

Declared synthetic boundaries (NOT recovered bodies):
  spDrawOrderTimeline_create 0x282d4c, spDrawOrderTimeline_setFrame 0x282ddc,
  fixture heap + allocator roster, libc providers, hand-built Json nodes.

Nothing here executes original libyoyo bytes.  Static anchors (SHA, dynsym,
instruction words, pc-relative literals) are checked before any run.
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
MOD = C / 'spine_read_tl_draworder'
FIX = MOD / 'fixture/check.c'
BODY = MOD / 'src/spine_read_tl_draworder.c'
HEADER = MOD / 'src/spine_read_tl_draworder.h'
PIN = '3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a'
TAG = 'jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c'
FIND_SRC = C / 'skeleton_find/src/skeleton_find.c'
JSON_SRC = C / 'json_interface/src/json_interface.c'
ERR_SRC = C / 'spine_json_error/src/spine_json_error.c'
SOURCES = [C / p for p in (
    'spine_alloc/src/spine_alloc.c',
    'json_interface/src/json_interface.c',
    'skeleton_find/src/skeleton_find.c',
    'spine_skeleton_data/src/spine_skeleton_data.c',
    'spine_json_support/src/spine_json_support.c',
    'spine_json_error/src/spine_json_error.c',
    'spine_read_tl_draworder/src/spine_read_tl_draworder.c',
    'csprite_resources/fixture/arm32_support.c',
    'spine_linked_postpass/fixture/reporter_adapter.c',
    'spine_read_tl_draworder/fixture/check.c',
)]
INCLUDES = [C / p / 'src' for p in (
    'spine_alloc', 'spine_attachment', 'spine_skeleton_data', 'json_interface',
    'spine_color', 'spine_read_mesh', 'spine_mesh', 'spine_read_vertices',
    'spine_atlas_attachment', 'spine_read_slots', 'skeleton_find',
    'spine_json_error', 'spine_json_support', 'spine_read_tl_draworder',
)]
FLAGS = ['--target=armv7a-none-eabi', '-march=armv7-a', '-marm', '-mfpu=vfpv3',
         '-mfloat-abi=softfp', '-std=c11', '-ffreestanding', '-fno-builtin',
         '-ffp-contract=off', '-fstack-protector-strong',
         '-mstack-protector-guard=global', '-ffunction-sections',
         '-fdata-sections', '-Wall', '-Wextra', '-Werror', '-nostdlib',
         '-static', '-fuse-ld=lld', '-Wl,--gc-sections', '-Wl,-e,_start']
# Contract names emitted by the fixture, in execution order.
TESTS = ['draworder_absent', 'draworder_without_frames', 'frame_without_offsets',
         'single_entry_identity', 'offset_moves_slot_up', 'offset_moves_slot_down',
         'two_frames_cursor', 'leftover_merge_order', 'offsets_size_underflow',
         'slots_count_reload', 'slot_not_found_handoff', 'frame_time_default',
         'attachment_not_found',
         'publish_cursor_duration', 'declared_vs_child_count']
SUMMARY = 'SUMMARY all declared drawOrder timeline family contracts passed'
# Raw original instruction words: forks, both malloc size chains, the -1 fill,
# the merge, both _free sites, the setFrame call and the E4 argument staging.
WORD_PINS = {
    0x28e338: 0xe59d3028,  # ldr r3,[sp,#0x28]      — the "drawOrder" node
    0x28e340: 0x0a0000b3,  # beq 0x28e614           — absent -> event block
    0x28e354: 0xebffd27c,  # bl spDrawOrderTimeline_create
    0x28e358: 0xe58d002c,  # str r0,[sp,#0x2c]      — the timeline handle
    0x28e360: 0xe5909004,  # ldr r9,[r0,#0x4]       — first frame
    0x28e368: 0x0a000099,  # beq 0x28e5d4           — no frames -> publish
    0x28e3c8: 0xe594300c,  # ldr r3,[r4,#0xc]       — jsonOffsetsSize
    0x28e3cc: 0xe30021ba,  # movw r2,#0x1ba         — line 442
    0x28e3d8: 0xe0630000,  # rsb r0,r3,r0           — slotsCount - jsonOffsetsSize
    0x28e3dc: 0xe1a00100,  # lsl r0,r0,#2           — * 4 (32-bit wrap)
    0x28e3e0: 0xebffde0a,  # bl _malloc             — A, the leftovers
    0x28e3e8: 0xe30021bd,  # movw r2,#0x1bd         — line 445
    0x28e3f4: 0xe1a00100,  # lsl r0,r0,#2           — slotsCount * 4
    0x28e3f8: 0xebffde04,  # bl _malloc             — B, the order array
    0x28e40c: 0x53e00000,  # mvnpl r0,#0            — the -1 fill value
    0x28e418: 0xe5220004,  # str r0,[r2,#-0x4]!     — fill store
    0x28e420: 0x1afffffb,  # bne 0x28e414           — fill loop back edge
    0x28e464: 0x0a000110,  # beq 0x28e8ac           — slot miss -> OUT OF RANGE
    0x28e4b8: 0xe7864100,  # str r4,[r6,r0,lsl#2]   — B[slotIndex+offset]
    0x28e4f4: 0xe2521001,  # subs r1,r2,#1          — merge from the tail
    0x28e50c: 0x02455001,  # subeq r5,r5,#1         — unmoved--
    0x28e510: 0x079b3105,  # ldreq r3,[r11,r5,lsl#2]— A[unmoved]
    0x28e514: 0x05823000,  # streq r3,[r2]          — B[i] = A[unmoved]
    0x28e524: 0xebffddd5,  # bl _free               — A freed INSIDE the builder
    0x28e528: 0xea000019,  # b 0x28e594             — steps over the B13 island
    0x28e52c: 0xe59d1044,  # ldr r1,[sp,#0x44]      — the island's first insn (B13)
    0x28e538: 0x1a0000eb,  # bne 0x28e8ec           — B13 hands off to B17 here
    0x28e590: 0xe1a06004,  # mov r6,r4              — "no offsets" join (r4 == 0)
    0x28e5b8: 0xebffd207,  # bl spDrawOrderTimeline_setFrame
    0x28e5c0: 0xebffddae,  # bl _free               — B freed after setFrame
    0x28e5cc: 0x1affff78,  # bne 0x28e3b4           — frame loop back edge
    0x28e5f4: 0xe7810103,  # str r0,[r1,r3,lsl#2]   — timelines[count]
    0x28e5fc: 0xe0833102,  # add r3,r3,r2,lsl#2     — FOUR-byte stride
    0x28e600: 0xed537a01,  # vldr s15,[r3,#-4]      — times[declared-1]
    0x28e610: 0xedcb7a01,  # vstr s15,[r11,#4]      — duration store
    0x28e55c: 0xe1a05008,  # mov r5,r8              — r8 == 0 at the only entry
    0x28e578: 0xe1a01005,  # mov r1,r5              — setError json argument
    0x28e588: 0xebfff47d,  # bl _spSkeletonJson_setError
    0x28e58c: 0xeafffd2c,  # b 0x28da44             — common tail
    0x28e10c: 0xe2508000,  # subs r8,r0,#0          — the attachment lookup result
    0x28e110: 0x0a000111,  # beq 0x28e55c           — the ONLY edge into E4
    0x282d7c: 0xe3a01007,  # mov r1,#7              — drawOrder timeline type word
    0x282dc0: 0xe5847014,  # str r7,[r4,#0x14]      — +0x14 slotsCount
    0x282e00: 0xeb000b9e,  # bl _free               — setFrame frees the old slot
    0x282e24: 0xeb000b79,  # bl _malloc             — setFrame's own copy
    0x282e44: 0xeaf8cddc,  # b memcpy@plt           — ... of slotsCount*4 bytes
    0x282e48: 0xe5943010,  # ldr r3,[r4,#0x10]      — NULL order -> store 0
}
SYMBOL_PINS = {
    'spSkeletonJson_readSkeletonData': (0x28b84c, 13044),
    'spDrawOrderTimeline_create': (0x282d4c, 144),
    'spDrawOrderTimeline_setFrame': (0x282ddc, 124),
    'spDeformTimeline_create': (0x282e58, 160),
    'spSkeletonData_findSlotIndex': (0x28b0cc, 88),
    'spSkin_getAttachment': (0x28ed00, 88),
    'spAnimation_dispose': (0x28147c, 80),
    'spSkeletonData_dispose': (0x28adf8, 452),
    '_spSkeletonJson_setError': (0x28b784, 200),
    'Json_getItem': (0x2873c4, 100),
    'Json_getString': (0x287428, 28),
    'Json_getInt': (0x287460, 28),
    'Json_getFloat': (0x287444, 28),
    '_malloc': (0x285c10, 60),
    '_free': (0x285c80, 28),
    '_calloc': (0x285c4c, 52),
    '_spTimeline_init': (0x281328, 60),
}
# (literal pool word address, the ADD site whose +8 PC base resolves it,
#  expected text).  va = add_site + 8 + pool_word.
KEY_PINS = (
    (0x28ead0, 0x28e378, 'offsets'),                 # [sp+0x3c]
    (0x28ead4, 0x28e388, TAG),                       # [sp+0x30] malloc tag
    (0x28ead8, 0x28e394, 'slot'),                    # [sp+0x34]
    (0x28eadc, 0x28e398, 'offset'),                  # [sp+0x40]
    (0x28eae0, 0x28e3a0, 'time'),                    # [sp+0x44]
    (0x28eae4, 0x28e584, 'Attachment not found: '),  # E4 message
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

        words = {hex(a): struct.unpack('<I', raw(a, 4))[0] for a in WORD_PINS}
        for a, want in WORD_PINS.items():
            if words[hex(a)] != want:
                raise ValueError(f'word pin drifted at {a:#x}: '
                                 f'{words[hex(a)]:#x} != {want:#x}')
        # The two malloc sizes must be the sizes the two call sites request:
        # line 442 = (slotsCount - jsonOffsetsSize)*4, line 445 = slotsCount*4.
        for site, line_site, want_target in ((0x28e3e0, 0x28e3cc, '_malloc'),
                                             (0x28e3f8, 0x28e3e8, '_malloc'),
                                             (0x28e524, None, '_free'),
                                             (0x28e5c0, None, '_free'),
                                             (0x28e5b8, None,
                                              'spDrawOrderTimeline_setFrame'),
                                             (0x28e588, None,
                                              '_spSkeletonJson_setError')):
            got = bl_target(struct.unpack('<I', raw(site, 4))[0], site)
            if got != found[want_target][0]:
                raise ValueError(f'call target {site:#x} -> {got:#x} is not '
                                 f'{want_target} {found[want_target][0]:#x}')
            if line_site is not None:
                w = struct.unpack('<I', raw(line_site, 4))[0]
                imm16 = ((w >> 16) & 0xF) << 12 | (w & 0xfff)
                if imm16 not in (442, 445):
                    raise ValueError(f'line immediate at {line_site:#x} is {imm16}')
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
        # census §2.9: the drawOrder family has NO readCurve call site.  Scan
        # every aligned word of the three translated windows and prove that no
        # BL targets the anonymous readCurve entry 0x28b34c (c/spine_read_curve).
        windows = ((0x28e338, 0x28e528), (0x28e594, 0x28e614),
                   (0x28e55c, 0x28e58c))
        bls = []
        curve_hits = []
        for lo, hi in windows:
            for a in range(lo, hi, 4):
                w = struct.unpack('<I', raw(a, 4))[0]
                if (w >> 24) == 0xeb:
                    t = bl_target(w, a)
                    bls.append([hex(a), hex(t)])
                    if t == 0x28b34c:
                        curve_hits.append(hex(a))
        if curve_hits:
            raise ValueError('a readCurve call site exists in the drawOrder '
                             f'windows: {curve_hits}')
    return {'original_sha256': PIN,
            'symbol_pins': {k: [hex(v[0]), v[1]] for k, v in SYMBOL_PINS.items()},
            'word_pins': words, 'segment_key_literals': keys,
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
    print('BINDING v1 entry=tl-draworder run=' + name
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
        # --- the two malloc size formulas (census §3.1, open #4) ---------
        ('line442_size_sum', BODY, [
            ('        ((uint32_t)data->slotsCount - (uint32_t)json_offsets_size) * 4u,',
             '        ((uint32_t)data->slotsCount + (uint32_t)json_offsets_size) * 4u,')],
         '(slotsCount - jsonOffsetsSize) * 4 = 8 for the leftovers (0x28e3d8/0x28e3dc)'),
        ('line445_size_halved', BODY, [
            ('    order = (int32_t*)_malloc((uint32_t)data->slotsCount * 4u,',
             '    order = (int32_t*)_malloc((uint32_t)data->slotsCount * 2u,')],
         'slotsCount * 4 = 12 for the order array (0x28e3f4)'),
        # --- the -1 fill -------------------------------------------------
        ('fill_value_zero', BODY, [
            ('            order[k] = -1;                             /* 0x28e40c mvn r0,#0 ; 0x28e418 */',
             '            order[k] = 0;                              /* mutated: 0 instead of -1 */')],
         "the timeline's private copy holds the final order [0,1,2]"),
        # --- ownership ---------------------------------------------------
        ('free_a_dropped', BODY, [
            ('    _free(leftovers);                                   /* 0x28e520 / 0x28e524 */',
             '    /* mutated: the line-442 array is never released */')],
         'the line-442 array is freed FIRST, inside the frame builder (0x28e524)'),
        ('free_b_dropped', BODY, [
            ('        _free(order);                                   /* 0x28e5bc / 0x28e5c0 */',
             '        /* mutated: the line-445 array is never released */')],
         "two unconditional _free(NULL) calls: setFrame's old slot (0x282e00) then "
         "the reader's line-445 pointer (0x28e5c0)"),
        ('free_b_before_setframe', BODY, [
            ('        time = Json_getFloat(frame, "time", 0.0f);      /* 0x28e594..0x28e5a0 */',
             '        _free(order);   /* mutated: released before the call */\n'
             '        time = Json_getFloat(frame, "time", 0.0f);      /* 0x28e594..0x28e5a0 */'),
            ('        spDrawOrderTimeline_setFrame(timeline_raw, frame_index, time, order);\n'
             '                                                       /* 0x28e5a4..0x28e5b8 */\n'
             '        _free(order);                                   /* 0x28e5bc / 0x28e5c0 */',
             '        spDrawOrderTimeline_setFrame(timeline_raw, frame_index, time, order);\n'
             '                                                       /* 0x28e5a4..0x28e5b8 */')],
         'then setFrame frees the slot\'s previous (NULL) array (0x282e00)'),
        # --- setFrame arguments -----------------------------------------
        ('setframe_order_arg_null', BODY, [
            ('        spDrawOrderTimeline_setFrame(timeline_raw, frame_index, time, order);',
             '        spDrawOrderTimeline_setFrame(timeline_raw, frame_index, time, 0);')],
         'the pointer handed to setFrame is the line-445 array, not the line-442 one'),
        ('setframe_index_off_by_one', BODY, [
            ('        spDrawOrderTimeline_setFrame(timeline_raw, frame_index, time, order);',
             '        spDrawOrderTimeline_setFrame(timeline_raw, frame_index + 1, time, order);')],
         'the frame still reaches setFrame at index 0'),
        # --- key literal -------------------------------------------------
        ('time_key_literal', BODY, [
            ('        time = Json_getFloat(frame, "time", 0.0f);      /* 0x28e594..0x28e5a0 */',
             '        time = Json_getFloat(frame, "tome", 0.0f);      /* mutated: key literal */')],
         'setFrame receives the frame "time" bits'),
        # --- loop condition ---------------------------------------------
        ('loop_condition_reversed', BODY, [
            ('    } while (frame != 0);                               /* 0x28e5c8 / 0x28e5cc */',
             '    } while (frame != 0 && frame->next != 0);           /* mutated: stops one frame early */')],
         'frameIndex starts at 0 and increments once per frame (0x28e5ac)'),
        # --- publish tail -------------------------------------------------
        ('publish_count_not_bumped', BODY, [
            ('        animation->timelineCount = count + 1;          /* 0x28e5e8 / 0x28e5ec */',
             '        animation->timelineCount = count;              /* mutated: cursor not advanced */')],
         'the zero-frame timeline is still published at the animation cursor'),
        ('publish_index_off_by_one', BODY, [
            ('        timelines[count] = (void*)timeline;            /* 0x28e5f4 */',
             '        timelines[count + 1] = (void*)timeline;        /* mutated: wrong slot */')],
         'the zero-frame timeline is still published at the animation cursor'),
        ('duration_index_zero', BODY, [
            ('        last = timeline->times[declared - 1u];',
             '        last = timeline->times[declared * 0u];         /* mutated: always times[0] */')],
         'duration = the larger last-frame time (0.75)'),
        # --- E4 -----------------------------------------------------------
        ('e4_json_argument', BODY, [
            ('                             0,                                    /* 0x28e578 */',
             '                             (Json*)attachmentNode,                /* mutated: wrong json arg */')],
         'E4 passes NULL as the setError json argument: NO Json node is disposed'),
        ('e4_message_literal', BODY, [
            ('#define ERR_ATTACHMENT_NOT_FOUND "Attachment not found: "',
             '#define ERR_ATTACHMENT_NOT_FOUND "Attachment not found:"')],
         'E4 message is the exact literal plus the attachment timeline\'s name'),
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
    report = {'schema': 'cally-tl-draworder-check/1', 'tier': 'test_anchored',
              'original_executed': False,
              'entry': ('drawOrder timeline family (readSkeletonData caller block '
                        'B15 0x28e338-0x28e528, B15b 0x28e594-0x28e614, E4 '
                        '0x28e55c-0x28e58c)'),
              'scope': ('Reconstructed drawOrder C only: real Json_getItem/String/Int/Float, '
                        'real spSkeletonData_findSlotIndex, real spAnimation_dispose/'
                        'spSkeletonData_dispose and _spSkeletonJson_setError, the two per-frame '
                        'mallocs with their size formulas and the -1 fill, the offsets entry '
                        'loop, the leftover merge, the two _free sites, the frame loop with '
                        'spDrawOrderTimeline_setFrame and the publish/duration tail. Synthetic '
                        'boundaries: spDrawOrderTimeline_create/setFrame (argument recorders '
                        'whose bodies follow the disassembly, including the deep copy at line '
                        '690), fixture heap + allocator roster, libc providers, hand-built Json '
                        'nodes. 0x28e52c-0x28e558 (path spacing island) and 0x28e8ac (slot-miss '
                        'error block) are NOT modelled. Not an original-equivalence claim.'),
              'boundary': {
                  'b15_translated': '0x28e338-0x28e528 (125 insns) + 0x28e590 join',
                  'b15b_translated': '0x28e594-0x28e614 (32 insns)',
                  'e4_translated': '0x28e55c-0x28e58c (13 insns) + shared tail 0x28da44',
                  'not_translated': ['0x28e52c-0x28e558 (path spacing island, '
                                     'c/spine_read_tl_path owns it; 0x28e528 b 0x28e594 '
                                     'steps over it)',
                                     '0x28e8ac-0x28e8ec ("Slot not found: " for a drawOrder '
                                     'entry; 0x28e464 beq 0x28e8ac is reported as a handoff)'],
                  'e4_entry_edge': '0x28e10c subs r8,r0,#0 ; 0x28e110 beq 0x28e55c (the DEFORM '
                                   'block is the only predecessor, r8 == 0 -> NULL json arg)'},
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
            missing = build(ns.out, 'missing-tl-draworder-body', omit=(BODY,))
            if (not missing['compile_rc']
                    or 'undefined symbol: readSkeletonData_drawOrderTimelines'
                    not in missing['diagnostic']):
                raise RuntimeError('missing drawOrder body not refused')
            report['compile_guards'].append({'name': 'missing-tl-draworder-body',
                                             'refused': True, **missing})
            print('GUARD missing-tl-draworder-body refused', flush=True)
            # Second door: the Json accessors must come from c/json_interface.
            nojson = build(ns.out, 'unlinked-json-interface', omit=(JSON_SRC,))
            if (not nojson['compile_rc']
                    or 'undefined symbol: Json_getItem' not in nojson['diagnostic']):
                raise RuntimeError('Json accessor source removal not refused')
            report['compile_guards'].append({'name': 'unlinked-json-interface',
                                             'refused': True, **nojson})
            print('GUARD unlinked-json-interface refused', flush=True)
            # Third door: the slot lookup is the REAL c/skeleton_find body.
            nofind = build(ns.out, 'unlinked-skeleton-find', omit=(FIND_SRC,))
            if (not nofind['compile_rc']
                    or 'undefined symbol: spSkeletonData_findSlotIndex'
                    not in nofind['diagnostic']):
                raise RuntimeError('findSlotIndex source removal not refused')
            report['compile_guards'].append({'name': 'unlinked-skeleton-find',
                                             'refused': True, **nofind})
            print('GUARD unlinked-skeleton-find refused', flush=True)
            # Fourth door: E4 reports through the real setError body.
            noerr = build(ns.out, 'unlinked-json-error', omit=(ERR_SRC,))
            if (not noerr['compile_rc']
                    or 'undefined symbol: _spSkeletonJson_setError'
                    not in noerr['diagnostic']):
                raise RuntimeError('setError source removal not refused')
            report['compile_guards'].append({'name': 'unlinked-json-error',
                                             'refused': True, **noerr})
            print('GUARD unlinked-json-error refused', flush=True)
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
