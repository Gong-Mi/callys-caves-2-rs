#!/usr/bin/env python3
"""Original is read-only. Execute only rebuilt ARM32 C plus synthetic
heap/libc/JSON/timeline providers. PASS is a scoped reconstructed-consumer
verdict, never an original-equivalence claim.

Subject: the deform timeline family of spSkeletonJson_readSkeletonData @0x28b84c
  B14   0x28e060..0x28e338 (728 B / 182 insns)
        deform map loop (skin -> slot -> attachment-name node -> frames), the
        weighted gate from attachment+0x14, 2*(vertexCount/3) through the
        0x55555556 stack magic, the line-388 _malloc, spDeformTimeline_create,
        the +0x1c/+0x20 stores, the frame loop (head 0x28e19c, readCurve at
        0x28e2a8) and the ONE-float frame-stride publish/duration tail.
  B14b  0x28e820..0x28e880 (96 B / 24 insns)
        out-of-line island: "vertices" absent (weighted memset / non-weighted
        attachment+0x1c) and the scale != 1.0f copy loop.
  E6    0x28e8ac..0x28e8ec (64 B / 16 insns)
        "Slot not found: ".  MEASURED CALLER: 0x28e464 `beq 0x28e8ac` inside the
        drawOrder offsets loop, not the deform path (B14 never tests the
        findSlotIndex result).  Recovered here because the bytes are ours.

BOUNDARY: 0x28e110 `beq 0x28e55c` leaves for E4 ("Attachment not found: ",
0x28e55c..0x28e590), which is NOT part of this module; the driver reports
DEFORM_TL_HANDOFF_ATTACHMENT.

Real recovered chain under test (all bodies recovered, no stubs):
  Json_getItem/getInt/getFloat/getString   c/json_interface
  readCurve                                c/spine_read_curve
  spSkeletonData_findSkin/findSlotIndex    c/skeleton_find
  spSkin_getAttachment/create/addAttachment c/spine_skin
  _spSkeletonJson_setError                 c/spine_json_error
  spAnimation_dispose/spSkeletonData_dispose/spTimeline_dispose
                                           c/spine_skeleton_data
  Json_dispose/ReportSpineError            c/spine_json_support
  _malloc/_free/_calloc                    c/spine_alloc

Declared synthetic boundaries (NOT recovered bodies):
  spDeformTimeline_create 0x282e58, spDeformTimeline_setFrame 0x282ef8,
  spCurveTimeline_setStepped/setCurve 0x2817c0/0x2817d8, fixture heap +
  allocator roster, libc providers, hand-built Json nodes.

Nothing here executes original libyoyo bytes.  Static anchors (SHA, dynsym,
instruction words, pc-relative literals, anonymous-callee call sites, the
absence of any BL to _readVertices) are checked before any run.
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
MOD = C / 'spine_read_tl_deform'
FIX = MOD / 'fixture/check.c'
BODY = MOD / 'src/spine_read_tl_deform.c'
HEADER = MOD / 'src/spine_read_tl_deform.h'
PIN = '3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a'
CURVE_SRC = C / 'spine_read_curve/src/spine_read_curve.c'
JSON_SRC = C / 'json_interface/src/json_interface.c'
FINDSRC = C / 'skeleton_find/src/skeleton_find.c'
SKINSRC = C / 'spine_skin/src/spine_skin.c'
SOURCES = [C / p for p in (
    'spine_alloc/src/spine_alloc.c',
    'json_interface/src/json_interface.c',
    'spine_skeleton_data/src/spine_skeleton_data.c',
    'spine_json_support/src/spine_json_support.c',
    'spine_json_error/src/spine_json_error.c',
    'spine_read_curve/src/spine_read_curve.c',
    'skeleton_find/src/skeleton_find.c',
    'spine_skin/src/spine_skin.c',
    'spine_read_tl_deform/src/spine_read_tl_deform.c',
    'csprite_resources/fixture/arm32_support.c',
    'spine_linked_postpass/fixture/reporter_adapter.c',
    'spine_read_tl_deform/fixture/check.c',
)]
INCLUDES = [C / p / 'src' for p in (
    'spine_alloc', 'spine_attachment', 'spine_skeleton_data', 'json_interface',
    'spine_color', 'spine_read_mesh', 'spine_mesh', 'spine_read_vertices',
    'spine_atlas_attachment', 'spine_read_slots', 'spine_json_error',
    'spine_json_support', 'spine_read_curve', 'skeleton_find', 'spine_skin',
    'spine_read_tl_deform',
)]
FLAGS = ['--target=armv7a-none-eabi', '-march=armv7-a', '-marm', '-mfpu=vfpv3',
         '-mfloat-abi=softfp', '-std=c11', '-ffreestanding', '-fno-builtin',
         '-ffp-contract=off', '-fstack-protector-strong',
         '-mstack-protector-guard=global', '-ffunction-sections',
         '-fdata-sections', '-Wall', '-Wextra', '-Werror', '-nostdlib',
         '-static', '-fuse-ld=lld', '-Wl,--gc-sections', '-Wl,-e,_start']
# Contract names emitted by the fixture, in execution order.
TESTS = ['deform_absent', 'deform_without_skins', 'skin_without_slots',
         'slot_without_attachments', 'attachment_not_found_handoff',
         'weighted_count_and_malloc', 'weighted_nonmultiples',
         'unweighted_count_verbatim', 'magic_identity_25',
         'frame_scaled_copy', 'frame_unscaled_copy', 'frame_offset_gap',
         'frame_base_add', 'frame_no_vertices_weighted',
         'frame_no_vertices_unweighted', 'frame_time_and_curve',
         'publish_tail_duration', 'declared_vs_child_count',
         'two_skins_slot_indices', 'e6_slot_not_found', 'e6_missing_slot_key']
SUMMARY = 'SUMMARY all declared deform timeline family contracts passed'
# Raw original instruction words: forks, field loads/stores, call sites and the
# 0x55555556 magic read.  Every word below was re-read from the image.
WORD_PINS = {
    0x28e060: 0xe59d1050,  # ldr r1,[sp,#0x50]      — the "deform" JSON child
    0x28e064: 0xe3510000,  # cmp r1,#0
    0x28e068: 0x0a0000b2,  # beq 0x28e338           — absent -> drawOrder
    0x28e070: 0xe5900004,  # ldr r0,[r0,#0x4]       — deform->child (skin node)
    0x28e078: 0xe58d002c,  # str r0,[sp,#0x2c]
    0x28e07c: 0x0a0000ad,  # beq 0x28e338           — no children -> drawOrder
    0x28e080: 0xe59f1a38,  # ldr r1,[pc,#0xa38]     — pool 0x28eac0 malloc tag
    0x28e088: 0xe59f2a34,  # ldr r2,[pc,#0xa34]     — pool 0x28eac4 "vertices"
    0x28e08c: 0xe59f3a34,  # ldr r3,[pc,#0xa34]     — pool 0x28eac8 "offset"
    0x28e094: 0xe59f0a30,  # ldr r0,[pc,#0xa30]     — pool 0x28eacc "time"
    0x28e0c0: 0xebfff417,  # bl spSkeletonData_findSkin
    0x28e0e4: 0xebfff3f8,  # bl spSkeletonData_findSlotIndex
    0x28e108: 0xeb0002fc,  # bl spSkin_getAttachment
    0x28e110: 0x0a000111,  # beq 0x28e55c           — E4, OUT OF SCOPE
    0x28e114: 0xe5983014,  # ldr r3,[r8,#0x14]      — attachment->bones
    0x28e11c: 0x13a03001,  # movne r3,#1            — weighted flag
    0x28e124: 0xe58d3034,  # str r3,[sp,#0x34]      — shared weighted word
    0x28e128: 0x159d1060,  # ldrne r1,[sp,#0x60]    — THE 0x55555556 magic read
    0x28e12c: 0x15983018,  # ldrne r3,[r8,#0x18]    — verticesCount
    0x28e130: 0x0598b018,  # ldreq r11,[r8,#0x18]   — non-weighted count verbatim
    0x28e134: 0x10c21391,  # smullne r1,r2,r1,r3
    0x28e13c: 0x10423fc3,  # subne r3,r2,r3,asr #31 — signed /3 correction
    0x28e140: 0x11a0b083,  # lslne r11,r3,#1        — x2
    0x28e144: 0xe1a0210b,  # lsl r2,r11,#2          — bytes = floatCount*4
    0x28e150: 0xe3a02f61,  # mov r2,#388            — the malloc line
    0x28e154: 0xebffdead,  # bl _malloc
    0x28e164: 0xebffd33b,  # bl spDeformTimeline_create
    0x28e178: 0xe580301c,  # str r3,[r0,#0x1c]      — timeline+0x1c slotIndex
    0x28e17c: 0xe5808020,  # str r8,[r0,#0x20]      — timeline+0x20 attachment
    0x28e1a4: 0xebffe486,  # bl Json_getItem        — "vertices"
    0x28e1c0: 0xebffe4a6,  # bl Json_getInt         — "offset"
    0x28e1dc: 0xebf8a0f3,  # bl memset              — the offset zero fill
    0x28e1fc: 0x1a000191,  # bne 0x28e848           — scale != 1.0f island
    0x28e244: 0x1a00000a,  # bne 0x28e274           — weighted skips the base add
    0x28e250: 0xda000007,  # ble 0x28e274           — floatCount <= 0 skips
    0x28e284: 0xebffe46e,  # bl Json_getFloat       — "time"
    0x28e298: 0xebffd316,  # bl spDeformTimeline_setFrame
    0x28e2a8: 0xebfff427,  # bl readCurve           — anonymous 0x28b34c
    0x28e2c8: 0xebffde6c,  # bl _free               — the frame buffer
    0x28e2e0: 0xe599200c,  # ldr r2,[r9,#0xc]       — declared frame count
    0x28e2f0: 0xe0833102,  # add r3,r3,r2,lsl #2    — ONE-float stride
    0x28e2f4: 0xed537a01,  # vldr s15,[r3,#-4]      — frames[declared-1]
    0x28e308: 0xedca7a01,  # vstr s15,[r10,#4]      — duration store
    0x28e330: 0x1affff5f,  # bne 0x28e0b4           — skin-node loop
    0x28e338: 0xe59d3028,  # ldr r3,[sp,#0x28]      — drawOrder first word
    0x28e820: 0xe59d2034,  # ldr r2,[sp,#0x34]      — B14b: weighted
    0x28e828: 0x0598601c,  # ldreq r6,[r8,#0x1c]    — non-weighted source
    0x28e82c: 0x0afffe91,  # beq 0x28e278
    0x28e840: 0xebf89f5a,  # bl memset              — weighted whole-buffer clear
    0x28e848: 0xe3520000,  # cmp r2,#0              — B14b scale path
    0x28e860: 0xed927a06,  # vldr s14,[r2,#24]      — element->float_value
    0x28e864: 0xee677a87,  # vmul.f32 s15,s15,s14   — scale * value
    0x28e874: 0xece37a01,  # vstmia r3!,{s15}
    0x28e8ac: 0xe59db038,  # ldr r11,[sp,#0x38]     — E6: animation
    0x28e8bc: 0xebffcaee,  # bl spAnimation_dispose
    0x28e8cc: 0xebffe2d5,  # bl Json_getString      — "slot"
    0x28e8d4: 0xe3a01000,  # mov r1,#0              — NULL setError json argument
    0x28e8e4: 0xebfff3a6,  # bl _spSkeletonJson_setError
    0x28e8e8: 0xeafffc55,  # b 0x28da44             — data dispose, return NULL
    0x28d2d8: 0xe3051556,  # movw r1,#0x5556        — B3 magic low half
    0x28d2e0: 0xe3451555,  # movt r1,#0x5555        — B3 magic high half
    0x28d304: 0xe58d1060,  # str r1,[sp,#0x60]      — THE ONLY writer of the magic
    0x28b34c: 0xe92d4030,  # push {r4,r5,lr}        — anonymous readCurve
}
SYMBOL_PINS = {
    'spSkeletonJson_readSkeletonData': (0x28b84c, 13044),
    'Json_getItem': (0x2873c4, 100),
    'Json_getInt': (0x287460, 28),
    'Json_getFloat': (0x287444, 28),
    'Json_getString': (0x287428, 28),
    'spSkeletonData_findSkin': (0x28b124, 92),
    'spSkeletonData_findSlotIndex': (0x28b0cc, 88),
    'spSkin_getAttachment': (0x28ed00, 88),
    'spDeformTimeline_create': (0x282e58, 160),
    'spDeformTimeline_setFrame': (0x282ef8, 124),
    'spAnimation_dispose': (0x28147c, 80),
    'spSkeletonData_dispose': (0x28adf8, 452),
    '_spSkeletonJson_setError': (0x28b784, 200),
    '_malloc': (0x285c10, 60),
    '_free': (0x285c80, 28),
}
# Anonymous callee: no .dynsym entry.  Two sites are pinned on purpose:
# 0x28dff4 belongs to B13 (path) and 0x28e2a8 to B14 (deform).
ANON_CALLEES = {
    'readCurve': {'target': 0x28b34c, 'first_word': 0xe92d4030,
                  'sites': [0x28dff4, 0x28e2a8]},
}
# (literal pool word address, the ADD site whose +8 PC base resolves it,
#  expected text).  va = add_site + 8 + pool_word — pass the ADD address.
KEY_PINS = (
    (0x28eac0, 0x28e090, 'jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c'),
    (0x28eac4, 0x28e098, 'vertices'),      # [sp+0x48]
    (0x28eac8, 0x28e09c, 'offset'),        # [sp+0x54]
    (0x28eacc, 0x28e0a4, 'time'),          # [sp+0x58]
    (0x28eb0c, 0x28e8d8, 'Slot not found: '),  # E6 message
    (0x28ead8, 0x28e394, 'slot'),          # E6 Json_getString key (B15 caller)
    (0x28ead0, 0x28e378, 'offsets'),       # B15's array key, recorded for context
)
# Every BL inside B14/B14b, in address order.  The absence of 0x28b3fc proves
# the deform frame reader is INLINE (Json child walk), not a _readVertices call.
B14_BL_EXPECT = [
    (0x28e0c0, 0x28b124),  # findSkin
    (0x28e0e4, 0x28b0cc),  # findSlotIndex
    (0x28e108, 0x28ed00),  # spSkin_getAttachment
    (0x28e154, 0x285c10),  # _malloc (line 388)
    (0x28e164, 0x282e58),  # spDeformTimeline_create
    (0x28e1a4, 0x2873c4),  # Json_getItem
    (0x28e1c0, 0x287460),  # Json_getInt
    (0x28e1dc, 0xb65b0),   # memset (offset zero fill)
    (0x28e238, 0xb65b0),   # memset (tail zero fill after the copy)
    (0x28e284, 0x287444),  # Json_getFloat
    (0x28e298, 0x282ef8),  # spDeformTimeline_setFrame
    (0x28e2a8, 0x28b34c),  # readCurve
    (0x28e2c8, 0x285c80),  # _free
]
B14B_BL_EXPECT = [
    (0x28e840, 0xb65b0),   # memset (B14b weighted whole-buffer clear)
]
E6_BL_EXPECT = [
    (0x28e8bc, 0x28147c),  # spAnimation_dispose
    (0x28e8cc, 0x287428),  # Json_getString
    (0x28e8e4, 0x28b784),  # _spSkeletonJson_setError
]
READ_VERTICES = 0x28b3fc


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

        # Every BL in the two recovered ranges, in order, with targets.
        def bl_sites(start, end):
            out = []
            for a in range(start, end, 4):
                w = struct.unpack('<I', raw(a, 4))[0]
                if (w >> 24) == 0xeb:
                    out.append((a, bl_target(w, a)))
            return out

        b14_bl = bl_sites(0x28e060, 0x28e338)
        b14b_bl = bl_sites(0x28e820, 0x28e880)
        e6_bl = bl_sites(0x28e8ac, 0x28e8ec)
        if b14_bl != B14_BL_EXPECT:
            raise ValueError(f'B14 BL list drifted: {[(hex(a), hex(t)) for a, t in b14_bl]}')
        if b14b_bl != B14B_BL_EXPECT:
            raise ValueError(f'B14b BL list drifted: {[(hex(a), hex(t)) for a, t in b14b_bl]}')
        if e6_bl != E6_BL_EXPECT:
            raise ValueError(f'E6 BL list drifted: {[(hex(a), hex(t)) for a, t in e6_bl]}')
        if any(t == READ_VERTICES for _, t in b14_bl + b14b_bl):
            raise ValueError('B14/B14b must not call _readVertices 0x28b3fc')

    return {'original_sha256': PIN,
            'symbol_pins': {k: [hex(v[0]), v[1]] for k, v in SYMBOL_PINS.items()},
            'anonymous_callees': anon,
            'word_pins': words, 'segment_key_literals': keys,
            'b14_bl_sites': [{'site': hex(a), 'target': hex(t)} for a, t in b14_bl],
            'b14b_bl_sites': [{'site': hex(a), 'target': hex(t)} for a, t in b14b_bl],
            'e6_bl_sites': [{'site': hex(a), 'target': hex(t)} for a, t in e6_bl],
            'read_vertices_not_linked': hex(READ_VERTICES),
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
    print('BINDING v1 entry=tl-deform run=' + name
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
    """Named mutants of the BODY text only; each must be refused by a NAMED
    runtime assertion.  Every mutant still compiles cleanly."""
    return [
        # --- the 0x55555556 magic chain (open #8 / open #5) --------------
        ('magic_divisor', BODY, [
            ('    return 2 * (vertexCount / 3);',
             '    return 2 * (vertexCount / 4);   /* mutated divisor */')],
         'weighted vertexCount 6 reaches create as 2*(6/3) = 4 floats'),
        ('magic_multiplier', BODY, [
            ('    return 2 * (vertexCount / 3);',
             '    return 3 * (vertexCount / 3);   /* mutated multiplier */')],
         'weighted vertexCount 6 reaches create as 2*(6/3) = 4 floats'),
        ('magic_unsigned_divide', BODY, [
            ('    return 2 * (vertexCount / 3);',
             '    return (int32_t)(2u * ((uint32_t)vertexCount / 3u));  /* mutated: unsigned */')],
         '2*(v/3) equals the 0x55555556 smull/asr#31 sequence over 25 values'),
        # --- the weighted gate and the size formula ----------------------
        ('weighted_gate_flip', BODY, [
            ('    if (a->bones != 0)                                     /* 0x28e114..0x28e124 */',
             '    if (a->bones == 0)                                     /* mutated: polarity */')],
         'weighted vertexCount 6 reaches create as 2*(6/3) = 4 floats'),
        ('size_formula', BODY, [
            ('                        buffer = (float*)_malloc((uint32_t)floatCount * 4u,',
             '                        buffer = (float*)_malloc((uint32_t)floatCount * 2u,')],
         'the line-388 malloc asks for floatCount*4 = 16 bytes'),
        # --- the frame keys and the frame loop ---------------------------
        ('vertices_key_literal', BODY, [
            ('        Json* verticesJson = Json_getItem(frame, "vertices");   /* 0x28e19c..0x28e1a4 */',
             '        Json* verticesJson = Json_getItem(frame, "verticez");   /* mutated key */')],
         'scale 2.0 multiplies both frame values (1.5*2, -0.75*2) at 0x28e864'),
        ('offset_key_literal', BODY, [
            ('        int32_t offset = Json_getInt(frame, "offset", 0);       /* 0x28e1b0..0x28e1c0 */',
             '        int32_t offset = Json_getInt(frame, "offsett", 0);       /* mutated key */')],
         'the offset slot before the copied data stays zero'),
        ('time_key_literal', BODY, [
            ('            float time = Json_getFloat(frame, "time", 0.0f);  /* 0x28e278..0x28e284 */',
             '            float time = Json_getFloat(frame, "tome", 0.0f);  /* mutated key */')],
         'setFrame receives the frame "time" bits (0.25f)'),
        ('frame_index_stuck', BODY, [
            ('        ++frameIndex;                                  /* 0x28e2b0..0x28e2bc */',
             '        /* mutated: the frameIndex increment is gone */')],
         'the frame index starts at 0 and increments per frame child'),
        ('readcurve_dropped', BODY, [
            ('        readCurve(frame, timeline_raw, frameIndex);    /* 0x28e29c..0x28e2a8 */',
             '        (void)frameIndex;   /* mutated: the readCurve call is gone */')],
         'a "stepped" curve string reaches spCurveTimeline_setStepped at frame 0'),
        ('scale_ignored', BODY, [
            ('                    float scaled = scale * element->float_value;  /* 0x28e864 */',
             '                    float scaled = element->float_value;  /* mutated: scale dropped */')],
         'scale 2.0 multiplies both frame values (1.5*2, -0.75*2) at 0x28e864'),
        ('weighted_add_flip', BODY, [
            ('        if (weighted == 0 && floatCount > 0) {         /* 0x28e23c..0x28e250 */',
             '        if (weighted != 0 && floatCount > 0) {         /* mutated: polarity */')],
         'the weighted absent-key branch memsets the whole buffer at 0x28e840'),
        ('b14b_unweighted_source', BODY, [
            ('                src = attachment->vertices;            /* 0x28e828 ldreq r6,[r8,#0x1c] */',
             '                src = buffer;                          /* mutated: wrong source */')],
         'with no vertices key the non-weighted path publishes attachment+0x1c (0x28e828)'),
        ('weighted_buffer_clear', BODY, [
            ('                memset(buffer, 0, (uint32_t)floatCount * 4u);  /* 0x28e830..0x28e840 */',
             '                memset(buffer, 0, 0u);                  /* mutated: no clear */')],
         'the weighted absent-key branch memsets the whole buffer at 0x28e840'),
        # --- timeline fields and the tail -------------------------------
        ('slot_store_dropped', BODY, [
            ('                        timeline->slotIndex = slotIndex;   /* 0x28e178 */',
             '                        timeline->slotIndex = (int32_t)0x5a5a5a5a;  /* mutated */')],
         'B14 stores slotIndex at +0x1c and the attachment at +0x20'),
        ('tail_stride_two', BODY, [
            ('                            last = timeline->frames[declared - 1u];',
             '                            last = timeline->frames[declared * 2u - 2u];  /* mutated */')],
         'duration reads frames[declared-1] with a ONE-float stride (1.7 over 0.5)'),
        ('duration_compare_flip', BODY, [
            ('                                (duration > last) ? duration : last;',
             '                                (duration > last) ? last : duration;  /* mutated */')],
         'duration reads frames[declared-1] with a ONE-float stride (1.7 over 0.5)'),
        # --- E6 ----------------------------------------------------------
        ('e6_json_argument', BODY, [
            ('                             0,                            /* 0x28e8d4 mov r1,#0 */',
             '                             (Json*)offsetsNode,            /* mutated json arg */')],
         'E6 passes NULL (not the offsets node, not the root) as the setError json argument'),
        ('e6_message_literal', BODY, [
            ('#define ERR_SLOT_NOT_FOUND "Slot not found: "',
             '#define ERR_SLOT_NOT_FOUND "Slots not found: "')],
         'E6 message is the exact original literal plus Json_getString("slot")'),
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
    report = {'schema': 'cally-tl-deform-check/1', 'tier': 'test_anchored',
              'original_executed': False,
              'entry': ('deform timeline family (readSkeletonData caller block '
                        'B14 0x28e060-0x28e338 plus the B14b 0x28e820-0x28e880 '
                        'island and E6 0x28e8ac-0x28e8ec)'),
              'scope': ('Reconstructed deform-timeline C only: real Json accessors, real readCurve, '
                        'real findSkin/findSlotIndex, real spSkin_getAttachment, real setError and '
                        'dispose pair, the weighted 2*(vertexCount/3) computed through the '
                        '0x55555556 stack magic, the line-388 malloc, the inline frame "vertices" '
                        'child walk (NOT _readVertices), the offset zero fill, the non-weighted base '
                        'addend, the scale copy and the one-float publish tail. Synthetic '
                        'boundaries: spDeformTimeline_create/setFrame (argument recorders whose '
                        'layout follows the disassembled bodies), spCurveTimeline_setStepped/'
                        'setCurve recorders, fixture heap + allocator roster, libc providers, '
                        'hand-built Json nodes. E4 (0x28e55c) is NOT modelled; the driver reports '
                        'the handoff. Not an original-equivalence claim.'),
              'boundary': {
                  'b14_range': '0x28e060-0x28e338 (728 B / 182 insns, census §6)',
                  'b14b_range': '0x28e820-0x28e880 (96 B / 24 insns, out-of-line island)',
                  'e6_range': '0x28e8ac-0x28e8ec (64 B / 16 insns)',
                  'e6_caller_correction': ('E6 is reached only from 0x28e464 `beq 0x28e8ac` in the '
                                           'drawOrder offsets loop; the deform slot loop stores the '
                                           'findSlotIndex result at [sp+0x3c] without a -1 test '
                                           '(0x28e0e4/0x28e0f4), so this is not a deform error'),
                  'e4_out_of_scope': {'range': '0x28e55c-0x28e590',
                                      'branch': '0x28e110 beq 0x28e55c',
                                      'driver_code': 'DEFORM_TL_HANDOFF_ATTACHMENT'},
                  'neighbours_not_translated': ['0x28e7f4-0x28e820 attachment error block',
                                                '0x28e880-0x28e8ac Parent mesh error block']},
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
                    raise RuntimeError('mutant not rejected by a named runtime '
                                       f'assertion: {name}: {r}')
                print('TEETH', name, hit, flush=True)
            missing = build(ns.out, 'missing-tl-deform-body', omit=(BODY,))
            if (not missing['compile_rc']
                    or 'undefined symbol: readSkeletonData_deformTimelines'
                    not in missing['diagnostic']):
                raise RuntimeError('missing deform-timeline body not refused')
            report['compile_guards'].append({'name': 'missing-tl-deform-body',
                                             'refused': True, **missing})
            print('GUARD missing-tl-deform-body refused', flush=True)
            # Second door: the real readCurve translation unit must be linked,
            # otherwise the call at 0x28e2a8 has no definition.
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
                    or 'undefined symbol: Json_getItem' not in nojson['diagnostic']):
                raise RuntimeError('Json accessor source removal not refused')
            report['compile_guards'].append({'name': 'unlinked-json-interface',
                                             'refused': True, **nojson})
            print('GUARD unlinked-json-interface refused', flush=True)
            # Fourth door: the real findSlotIndex/findSkin bodies.
            nofind = build(ns.out, 'unlinked-skeleton-find', omit=(FINDSRC,))
            if (not nofind['compile_rc']
                    or 'undefined symbol: spSkeletonData_findSlotIndex'
                    not in nofind['diagnostic']):
                raise RuntimeError('skeleton_find source removal not refused')
            report['compile_guards'].append({'name': 'unlinked-skeleton-find',
                                             'refused': True, **nofind})
            print('GUARD unlinked-skeleton-find refused', flush=True)
            # Fifth door: the real spSkin_getAttachment body.
            noskin = build(ns.out, 'unlinked-spine-skin', omit=(SKINSRC,))
            if (not noskin['compile_rc']
                    or 'undefined symbol: spSkin_getAttachment'
                    not in noskin['diagnostic']):
                raise RuntimeError('spine_skin source removal not refused')
            report['compile_guards'].append({'name': 'unlinked-spine-skin',
                                             'refused': True, **noskin})
            print('GUARD unlinked-spine-skin refused', flush=True)
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
