#!/usr/bin/env python3
"""Original is read-only. Execute only rebuilt ARM32 C plus synthetic
heap/libc/JSON/timeline providers. PASS is a scoped reconstructed-consumer
verdict, never an original-equivalence claim.

Subject: the bones timeline family of spSkeletonJson_readSkeletonData @0x28b84c
  B6    0x28d640..0x28d740 (256 B / 64 insns)
        bones child loop -> REAL spSkeletonData_findBoneIndex -> cmp -1 ->
        strcmp(type, rotate/scale/translate/shear) dispatch
  B6b   0x28d740..0x28d840 (256 B / 64 insns)
        shared translate/scale/shear frame loop ("time","x","y"), the s16
        multiplier, spTranslateTimeline_setFrame, readCurve, publish tail with
        a three-float stride, and the timeline->next / bone->next back edges
  B9    0x28da54..0x28da74 (32 B / 8 insns)
        translate select: s16 = parser->scale (vldr s16,[parser])
  B10   0x28da74..0x28db48 (212 B / 53 insns)
        rotate frames ("time","angle"), readCurve, publish tail, two-float stride
  B11   0x28db48..0x28db5c (20 B / 5 insns)  scale select, s16 = 1.0
  B11b  0x28dbb4..0x28dbc4 (shear select, s16 = 1.0; the census' 7-insn range
        also contains 0x28dbc8/0x28dbcc, which are the IK index-scan store)
  E2    0x28db5c..0x28db88 (44 B / 11 insns)
        "Bone not found: " -> real spAnimation_dispose -> real setError with
        the CURRENT ANIMATION NODE as the json argument -> shared tail
        0x28da44 (real spSkeletonData_dispose; return 0)
  E3    0x28db88..0x28dbb4 (44 B / 11 insns)
        "Invalid timeline type for a bone: " -> real spAnimation_dispose ->
        real setError with json == NULL (r1 = r4 = 0) -> same tail

Real recovered chain under test (all bodies recovered, no stubs):
  Json_getItem/getFloat             c/json_interface
  readCurve                         c/spine_read_curve
  _spSkeletonJson_setError          c/spine_json_error
  Json_dispose / ReportSpineError   c/spine_json_support
  spAnimation_dispose / spSkeletonData_dispose / spBoneData_dispose
                                    c/spine_skeleton_data
  _malloc / _free / _calloc         c/spine_alloc
  spSkeletonData_findBoneIndex      this module (0x28b018, 88 B / 21 insns)

Declared synthetic boundaries (NOT recovered bodies):
  spTranslateTimeline_create / spRotateTimeline_create / spScaleTimeline_create
  / spShearTimeline_create and spTranslateTimeline_setFrame /
  spRotateTimeline_setFrame: the fixture doubles model the disassembled store
  shapes and record every argument word.
  spScaleTimeline_setFrame (0x282b1c) and spShearTimeline_setFrame (0x282b38)
  are 4-byte `b spTranslateTimeline_setFrame` thunks in the original and are
  deliberately NOT defined by the fixture, so any call to them fails the link.
  spCurveTimeline_setStepped/setCurve recorders, fixture heap + allocator
  roster, libc providers, hand-built Json nodes.

Nothing here executes original libyoyo bytes. Static anchors (SHA, dynsym,
instruction words, pc-relative literals, BL/branch targets) are checked before
any run.
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
MOD = C / 'spine_read_tl_bones'
FIX = MOD / 'fixture/check.c'
BODY = MOD / 'src/spine_read_tl_bones.c'
HEADER = MOD / 'src/spine_read_tl_bones.h'
PIN = '3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a'
SOURCES = [C / p for p in (
    'spine_alloc/src/spine_alloc.c', 'json_interface/src/json_interface.c',
    'spine_skeleton_data/src/spine_skeleton_data.c',
    'spine_json_support/src/spine_json_support.c',
    'spine_json_error/src/spine_json_error.c',
    'spine_read_curve/src/spine_read_curve.c',
    'spine_read_tl_bones/src/spine_read_tl_bones.c',
    'csprite_resources/fixture/arm32_support.c',
    'spine_linked_postpass/fixture/reporter_adapter.c',
    'spine_read_tl_bones/fixture/check.c',
)]
# The readCurve translation unit is the one the "real link, not a stub" guard
# removes; keep its path addressable by name.
CURVE_SRC = C / 'spine_read_curve/src/spine_read_curve.c'
JSON_SRC = C / 'json_interface/src/json_interface.c'
INCLUDES = [C / p / 'src' for p in (
    'spine_alloc', 'spine_attachment', 'spine_skeleton_data', 'json_interface',
    'spine_color', 'spine_read_mesh', 'spine_mesh', 'spine_read_vertices',
    'spine_atlas_attachment', 'spine_read_slots', 'spine_json_error',
    'spine_json_support', 'spine_read_curve', 'spine_read_tl_bones',
)]
FLAGS = ['--target=armv7a-none-eabi', '-march=armv7-a', '-marm', '-mfpu=vfpv3',
         '-mfloat-abi=softfp', '-std=c11', '-ffreestanding', '-fno-builtin',
         '-ffp-contract=off', '-fstack-protector-strong',
         '-mstack-protector-guard=global', '-ffunction-sections',
         '-fdata-sections', '-Wall', '-Wextra', '-Werror', '-nostdlib',
         '-static', '-fuse-ld=lld', '-Wl,--gc-sections', '-Wl,-e,_start']
# Contract names emitted by the fixture, in execution order.
TESTS = ['bones_key_absent', 'bones_without_children',
         'bone_without_timelines_then_next', 'bone_index_first_of_duplicates',
         'bone_index_second', 'bone_index_empty_data', 'translate_frames_scaled',
         'scale_frames_not_scaled', 'shear_frames_not_scaled',
         'rotate_frames_angle', 'curve_wiring', 'declared_vs_child_xy',
         'declared_vs_child_rotate', 'dispatch_all_four', 'invalid_type_e3',
         'bone_not_found_e2', 'duration_keeps_animation', 'two_bones']
SUMMARY = 'SUMMARY all declared bones timeline family contracts passed'
# Raw original instruction words: control-flow forks, key-pointer materialisation,
# field stores, call sites.
WORD_PINS = {
    0x28d640: 0xe59d3030,  # ldr r3,[sp,#0x30]      — the "bones" Json value
    0x28d648: 0x0a00007c,  # beq 0x28d840           — absent -> ik block
    0x28d650: 0xe5906004,  # ldr r6,[r0,#0x4]       — boneNode = bones->child
    0x28d658: 0x0a000078,  # beq 0x28d840           — no children -> ik block
    0x28d694: 0xe58d1030,  # str r1,[sp,#0x30]      — "time" overwrites the bones spill
    0x28d698: 0xe59d0018,  # ldr r0,[sp,#0x18]      — data
    0x28d69c: 0xe596101c,  # ldr r1,[r6,#0x1c]      — boneNode->name
    0x28d6a0: 0xebfff65c,  # bl spSkeletonData_findBoneIndex
    0x28d6a4: 0xe3700001,  # cmn r0,#1              — index == -1 test
    0x28d6ac: 0x0a00012a,  # beq 0x28db5c           — miss -> E2
    0x28d6b8: 0x158d6058,  # strne r6,[sp,#0x58]    — spill the bone node
    0x28d6c4: 0xe59d103c,  # ldr r1,[sp,#0x3c]      — "rotate"
    0x28d6cc: 0xebf8a3a8,  # bl strcmp@plt
    0x28d6d0: 0xe2509000,  # subs r9,r0,#0          — rotate flag (and B10's 0 index)
    0x28d6d4: 0x0a0000e6,  # beq 0x28da74           — B10 rotate
    0x28d71c: 0x0a000119,  # beq 0x28db88           — no match -> E3
    0x28d724: 0x1a0000ca,  # bne 0x28da54           — B9 translate
    0x28d72c: 0x1a000105,  # bne 0x28db48           — B11 scale
    0x28d734: 0x0eb78a00,  # vmoveq.f32 s16,#1.0    — s16 = 1.0
    0x28d73c: 0x1a00011c,  # bne 0x28dbb4           — B11b shear
    0x28d740: 0xe5976004,  # ldr r6,[r7,#0x4]       — frame = timelineJson->child
    0x28d744: 0xe5848014,  # str r8,[r4,#0x14]      — timeline->boneIndex (+0x14)
    0x28d74c: 0x0a000024,  # beq 0x28d7e4           — no frames -> tail
    0x28d754: 0xe3a05000,  # mov r5,#0              — frameIndex = 0
    0x28d768: 0xe1a00006,  # mov r0,r6              — frame loop head
    0x28d774: 0xebffe732,  # bl Json_getFloat       — "time"
    0x28d788: 0xebffe72d,  # bl Json_getFloat       — "x"
    0x28d79c: 0xee678a08,  # vmul.f32 s17,s14,s16   — x * s16
    0x28d7a0: 0xebffe727,  # bl Json_getFloat       — "y"
    0x28d7c0: 0xebffd4c3,  # bl spTranslateTimeline_setFrame (r3=x*s16,[sp]=y*s16)
    0x28d7d0: 0xebfff6dd,  # bl readCurve           — anonymous 0x28b34c
    0x28d7e4: 0xe597200c,  # ldr r2,[r7,#0xc]       — declared frame count
    0x28d7f4: 0xe2422001,  # sub r2,r2,#1           — declared-1
    0x28d800: 0xe0822082,  # add r2,r2,r2,lsl#1     — *3 (three-float stride)
    0x28d808: 0xe5943010,  # ldr r3,[r4,#0x10]      — frames at +0x10
    0x28d810: 0xedd37a00,  # vldr s15,[r3]
    0x28d820: 0xedcb7a01,  # vstr s15,[r11,#4]      — duration store
    0x28d824: 0xe5977000,  # ldr r7,[r7]            — next timeline
    0x28d82c: 0x1affffa3,  # bne 0x28d6c0           — timeline loop back edge
    0x28d83c: 0x1affff95,  # bne 0x28d698           — bone loop back edge
    0x28da54: 0xe3550000,  # cmp r5,#0              — B9: scale flag
    0x28da5c: 0xed928a00,  # vldr s16,[r2]          — s16 = parser->scale
    0x28da60: 0x1a000039,  # bne 0x28db4c
    0x28da64: 0xe597000c,  # ldr r0,[r7,#0xc]       — declared count
    0x28da68: 0xebffd413,  # bl spTranslateTimeline_create
    0x28da70: 0xeaffff32,  # b 0x28d740             — into B6b
    0x28da74: 0xe597000c,  # ldr r0,[r7,#0xc]       — B10 declared count
    0x28da78: 0xebffd404,  # bl spRotateTimeline_create
    0x28da88: 0xe5808014,  # str r8,[r0,#0x14]      — rotate boneIndex
    0x28daa8: 0xe1a00004,  # mov r0,r4              — B10 frame loop head
    0x28dab8: 0xebffe661,  # bl Json_getFloat       — "time"
    0x28dacc: 0xebffe65c,  # bl Json_getFloat       — "angle"
    0x28dae0: 0xebffd3f0,  # bl spRotateTimeline_setFrame
    0x28daf0: 0xebfff615,  # bl readCurve
    0x28daf8: 0xe2899001,  # add r9,r9,#1           — frameIndex++
    0x28db0c: 0xe59b3008,  # ldr r3,[r11,#0x8]      — timelineCount
    0x28db20: 0xe597200c,  # ldr r2,[r7,#0xc]       — declared count
    0x28db2c: 0xe0833182,  # add r3,r3,r2,lsl#3     — *2 (two-float stride)
    0x28db30: 0xed537a02,  # vldr s15,[r3,#-8]      — frames[(declared-1)*2]
    0x28db44: 0xeaffff36,  # b 0x28d824             — rejoin the shared loop
    0x28db48: 0xeeb78a00,  # vmov.f32 s16,#1.0      — B11 s16 = 1.0
    0x28db50: 0xebffd3eb,  # bl spScaleTimeline_create
    0x28db58: 0xeafffef8,  # b 0x28d740
    0x28db5c: 0xe59d8020,  # ldr r8,[sp,#0x20]      — E2 parser
    0x28db68: 0xebffce43,  # bl spAnimation_dispose
    0x28db74: 0xe59d101c,  # ldr r1,[sp,#0x1c]      — setError json = animation node
    0x28db78: 0xe596301c,  # ldr r3,[r6,#0x1c]      — boneNode->name
    0x28db80: 0xebfff6ff,  # bl _spSkeletonJson_setError
    0x28db84: 0xeaffffae,  # b 0x28da44             — shared error tail
    0x28db88: 0xe59d8020,  # ldr r8,[sp,#0x20]      — E3 parser
    0x28db94: 0xebffce38,  # bl spAnimation_dispose
    0x28db9c: 0xe1a01004,  # mov r1,r4              — r4 == 0 -> json arg NULL
    0x28dba4: 0xe597301c,  # ldr r3,[r7,#0x1c]      — timelineJson->name
    0x28dbac: 0xebfff6f4,  # bl _spSkeletonJson_setError
    0x28dbb0: 0xeaffffa3,  # b 0x28da44
    0x28dbb4: 0xe597000c,  # ldr r0,[r7,#0xc]       — B11b declared count
    0x28dbb8: 0xeeb78a00,  # vmov.f32 s16,#1.0      — B11b s16 = 1.0
    0x28dbbc: 0xebffd3d7,  # bl spShearTimeline_create
    0x28dbc4: 0xeafffedd,  # b 0x28d740
    0x28da48: 0xebfff4ea,  # bl spSkeletonData_dispose (shared tail 0x28da44)
}
SYMBOL_PINS = {
    'spSkeletonJson_readSkeletonData': (0x28b84c, 13044),
    'spSkeletonData_findBone': (0x28afbc, 92),
    'spSkeletonData_findBoneIndex': (0x28b018, 88),
    'spTranslateTimeline_create': (0x282abc, 24),
    'spRotateTimeline_create': (0x282a90, 24),
    'spScaleTimeline_create': (0x282b04, 24),
    'spShearTimeline_create': (0x282b20, 24),
    'spTranslateTimeline_setFrame': (0x282ad4, 48),
    'spRotateTimeline_setFrame': (0x282aa8, 20),
    'spScaleTimeline_setFrame': (0x282b1c, 4),
    'spShearTimeline_setFrame': (0x282b38, 4),
    'spAnimation_dispose': (0x28147c, 80),
    'spSkeletonData_dispose': (0x28adf8, 452),
    '_spSkeletonJson_setError': (0x28b784, 200),
    'Json_getFloat': (0x287444, 28),
    'Json_getItem': (0x2873c4, 100),
}
# Direct BL targets inside the eight blocks (site -> target VA).
BL_PINS = {
    0x28d6a0: 0x28b018,  # spSkeletonData_findBoneIndex
    0x28d6cc: 0xb6574,   # strcmp@plt — "rotate"
    0x28d6e0: 0xb6574,   # strcmp@plt — "scale"
    0x28d6f4: 0xb6574,   # strcmp@plt — "translate"
    0x28d708: 0xb6574,   # strcmp@plt — "shear"
    0x28d774: 0x287444,  # Json_getFloat — "time"
    0x28d788: 0x287444,  # Json_getFloat — "x"
    0x28d7a0: 0x287444,  # Json_getFloat — "y"
    0x28d7c0: 0x282ad4,  # spTranslateTimeline_setFrame (also scale/shear)
    0x28d7d0: 0x28b34c,  # readCurve
    0x28da68: 0x282abc,  # spTranslateTimeline_create
    0x28da78: 0x282a90,  # spRotateTimeline_create
    0x28dab8: 0x287444,  # Json_getFloat — "time"
    0x28dacc: 0x287444,  # Json_getFloat — "angle"
    0x28dae0: 0x282aa8,  # spRotateTimeline_setFrame
    0x28daf0: 0x28b34c,  # readCurve
    0x28db50: 0x282b04,  # spScaleTimeline_create
    0x28db68: 0x28147c,  # spAnimation_dispose (E2)
    0x28db80: 0x28b784,  # _spSkeletonJson_setError (E2)
    0x28db94: 0x28147c,  # spAnimation_dispose (E3)
    0x28dbac: 0x28b784,  # _spSkeletonJson_setError (E3)
    0x28dbbc: 0x282b20,  # spShearTimeline_create
    0x28da48: 0x28adf8,  # spSkeletonData_dispose (shared error tail)
}
# Control-flow edges inside the eight blocks (site -> target VA).
BRANCH_PINS = {
    0x28d648: 0x28d840,  # bones absent -> ik
    0x28d658: 0x28d840,  # no bone children -> ik
    0x28d6ac: 0x28db5c,  # findBoneIndex == -1 -> E2
    0x28d6d4: 0x28da74,  # rotate -> B10
    0x28d71c: 0x28db88,  # no type match -> E3
    0x28d724: 0x28da54,  # translate -> B9
    0x28d72c: 0x28db48,  # scale -> B11
    0x28d73c: 0x28dbb4,  # shear -> B11b
    0x28d74c: 0x28d7e4,  # no frames -> tail
    0x28d82c: 0x28d6c0,  # timeline loop back edge
    0x28d83c: 0x28d698,  # bone loop back edge
    0x28da60: 0x28db4c,  # B9's dead scale re-test still targets B11's create
    0x28da70: 0x28d740,  # B9 -> B6b
    0x28db44: 0x28d824,  # B10 tail -> shared loop
    0x28db58: 0x28d740,  # B11 -> B6b
    0x28db84: 0x28da44,  # E2 -> shared error tail
    0x28dbb0: 0x28da44,  # E3 -> shared error tail
    0x28dbc4: 0x28d740,  # B11b -> B6b
}
# Anonymous callees: no .dynsym/.symtab entry exists, so the ONLY proof is the
# call site plus the claim that no symbol range covers the address.
ANON_CALLEES = {
    'readCurve': {'target': 0x28b34c, 'first_word': 0xe92d4030,
                  'sites': [0x28d7d0, 0x28daf0]},
}
# The scale/shear setters are 4-byte AL branches onto spTranslateTimeline_setFrame.
THUNK_PINS = {
    'spScaleTimeline_setFrame': {'site': 0x282b1c, 'word': 0xeaffffec, 'target': 0x282ad4},
    'spShearTimeline_setFrame': {'site': 0x282b38, 'word': 0xeaffffe5, 'target': 0x282ad4},
}
# (literal pool word address, the ADD site whose +8 PC base resolves it,
#  expected text).  va = add_site + 8 + pool word — pass the ADD address.
KEY_PINS = (
    (0x28ca2c, 0x28d664, 'rotate'),
    (0x28ca30, 0x28d670, 'scale'),
    (0x28ca34, 0x28d678, 'translate'),
    (0x28ca38, 0x28d680, 'shear'),
    (0x28ca3c, 0x28d688, 'time'),
    (0x28ca40, 0x28d75c, 'x'),
    (0x28ca44, 0x28d760, 'y'),
    (0x28ea88, 0x28da9c, 'time'),
    (0x28ea8c, 0x28daa0, 'angle'),
    (0x28ea90, 0x28db7c, 'Bone not found: '),
    (0x28ea94, 0x28dba8, 'Invalid timeline type for a bone: '),
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


def b_target(word, addr):
    """ARM32 B/BL class (bits 27..25 == 0b101), any condition."""
    if ((word >> 25) & 0x7) != 0x5:
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

        # findBone (pointer) and findBoneIndex (index) are adjacent symbols;
        # the blocks must call the latter, never the former.
        fb_va, fb_size = found['spSkeletonData_findBone']
        fbi_va, fbi_size = found['spSkeletonData_findBoneIndex']
        if fb_va + fb_size != fbi_va:
            raise ValueError('findBone does not end where findBoneIndex starts')
        own = covered_by_symbol(fbi_va)
        if own != [('spSkeletonData_findBoneIndex', hex(fbi_va), fbi_size)]:
            raise ValueError(f'findBoneIndex coverage drifted: {own}')

        def ow(a):
            return struct.unpack('<I', raw(a, 4))[0]

        words = {hex(a): ow(a) for a in WORD_PINS}
        for a, want in WORD_PINS.items():
            if words[hex(a)] != want:
                raise ValueError(f'word pin drifted at {a:#x}: {words[hex(a)]:#x} != {want:#x}')
        for site, want in BL_PINS.items():
            got = bl_target(ow(site), site)
            if got != want:
                raise ValueError(f'BL at {site:#x} targets {got:#x}, not {want:#x}')
        for site, want in BRANCH_PINS.items():
            got = b_target(ow(site), site)
            if got != want:
                raise ValueError(f'branch at {site:#x} targets {got:#x}, not {want:#x}')
        thunks = {}
        for name, spec in THUNK_PINS.items():
            if found.get(name) != (spec['site'], 4):
                raise ValueError(f'{name} is not the expected 4-byte thunk')
            w = struct.unpack('<I', raw(spec['site'], 4))[0]
            if w != spec['word']:
                raise ValueError(f'{name} thunk word drifted: {w:#x}')
            tgt = b_target(w, spec['site'])
            if tgt != spec['target']:
                raise ValueError(f'{name} thunk targets {tgt:#x}, not {spec["target"]:#x}')
            thunks[name] = {'site': hex(spec['site']), 'word': hex(w),
                            'target': hex(tgt),
                            'meaning': '4-byte b spTranslateTimeline_setFrame'}
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
            'adjacency': {'spSkeletonData_findBone': hex(fb_va), 'size': fb_size,
                          'spSkeletonData_findBoneIndex': hex(fbi_va),
                          'note': 'findBone ends exactly at findBoneIndex; the block calls 0x28b018'},
            'anonymous_callees': anon, 'setframe_thunks': thunks,
            'word_pins': words, 'bl_pins': {hex(k): hex(v) for k, v in BL_PINS.items()},
            'branch_pins': {hex(k): hex(v) for k, v in BRANCH_PINS.items()},
            'segment_key_literals': keys,
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
    print('BINDING v1 entry=tl-bones run=' + name
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
    """Mutants of the BODY text only; each must be refused by a NAMED runtime
    assertion.  Every mutant still compiles cleanly."""
    return [
        ('xy_bone_offset', BODY, [
            ('    timeline->boneIndex = boneIndex;                   /* 0x28d744 */',
             '    ((int32_t*)(void*)timeline)[7] = boneIndex;        /* mutated: +0x1c */')],
         'bone_without_timelines_then_next: the second bone resolves to index 1 through the real findBoneIndex'),
        ('xy_tail_stride', BODY, [
            ('        uint32_t word_index = (declared - 1u) * 3u;        /* 0x28d7f4 / 0x28d800 */',
             '        uint32_t word_index = (declared - 1u);             /* mutated: stride 1 */')],
         'translate_frames_scaled: B6b tail reads frames[3*(count-1)] for the last frame time'),
        ('rotate_tail_stride', BODY, [
            ('        last = timeline->frames[declared * 2u - 2u];       /* 0x28db28..0x28db30 */',
             '        last = timeline->frames[declared * 1u - 1u];       /* mutated: stride 1 */')],
         'rotate_frames_angle: B10 tail reads frames[2*(count-1)] for the last frame time'),
        ('scale_multiplier', BODY, [
            ('                    void* timeline = spScaleTimeline_create((int)timelineJson->unk_0c);\n'
             '                    readSkeletonData_boneXYTimeline(timelineJson, animation_raw,\n'
             '                                                    boneIndex, 1.0f, timeline);',
             '                    void* timeline = spScaleTimeline_create((int)timelineJson->unk_0c);\n'
             '                    readSkeletonData_boneXYTimeline(timelineJson, animation_raw,\n'
             '                                                    boneIndex, spSkeletonJson_scale_float(parser), timeline); /* mutated */')],
         'scale_frames_not_scaled: scale x/y reach setFrame unscaled (s16 = 1.0, not parser->scale)'),
        ('translate_scale_dropped', BODY, [
            ('                    float coord_scale = spSkeletonJson_scale_float(parser);',
             '                    float coord_scale = 1.0f;   /* mutated */')],
         'translate_frames_scaled: translate multiplies x and y by parser->scale (1*2, 3*2)'),
        ('rotate_reads_x', BODY, [
            ('            float angle = Json_getFloat(frame, "angle", 0.0f); /* 0x28dabc..0x28dacc */',
             '            float angle = Json_getFloat(frame, "x", 0.0f);     /* mutated */')],
         'rotate_frames_angle: rotate reads the \\"angle\\" key, not x (30, -45)'),
        ('e2_json_argument', BODY, [
            ('                             animationJson,                        /* 0x28db74 */',
             '                             (Json*)((uintptr_t)animationJson & 0u), /* mutated: NULL */')],
         'bone_not_found_e2: E2 passes the CURRENT ANIMATION NODE as the setError json argument'),
        ('e3_json_argument', BODY, [
            ('                             0,                                    /* 0x28db9c mov r1,r4, r4 == 0 */',
             '                             timelineJson,                         /* mutated */')],
         'invalid_type_e3: E3 passes a NULL json argument to setError (r4 == 0), tree untouched'),
        ('e2_error_text', BODY, [
            ('static const char* const ERR_BONE_NOT_FOUND = "Bone not found: ";',
             'static const char* const ERR_BONE_NOT_FOUND = "Bone not found:";  /* mutated */')],
         'bone_not_found_e2: E2 message is the exact original literal plus the bone name'),
        ('xy_frame_index_stuck', BODY, [
            ('            ++frameIndex;                              /* 0x28d7d8 */',
             '            frameIndex = 0;                             /* mutated: never advances */')],
         'translate_frames_scaled: translate frame index starts at 0 and increments'),
        ('dispatch_shear_dropped', BODY, [
            ('                } else if (strcmp(type, "shear") == 0) {     /* 0x28d700..0x28d710 */',
             '                } else if (strcmp(type, "shear ") == 0) {    /* mutated */')],
         'shear_frames_not_scaled: B6 shear timeline completes'),
        ('duration_polarity', BODY, [
            ('        animation->duration = (duration > last) ? duration : last;\n'
             '                                                           /* 0x28d814..0x28d820 */',
             '        animation->duration = (duration <= last) ? duration : last; /* mutated */')],
         'translate_frames_scaled: B6b tail reads frames[3*(count-1)] for the last frame time'),
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
    report = {'schema': 'cally-tl-bones-check/1', 'tier': 'test_anchored',
              'original_executed': False,
              'entry': ('bones timeline family (readSkeletonData caller blocks '
                        'B6 0x28d640-0x28d740, B6b 0x28d740-0x28d840, '
                        'B9 0x28da54-0x28da74, B10 0x28da74-0x28db48, '
                        'B11 0x28db48-0x28db5c, B11b 0x28dbb4-0x28dbc4, '
                        'E2 0x28db5c-0x28db88, E3 0x28db88-0x28dbb4)'),
              'scope': ('Reconstructed bones-timeline C only: real findBoneIndex (recovered here), '
                        'Json_getItem/getFloat, real readCurve on both branches, real setError with '
                        'the console vcall and its Json_dispose argument, real spAnimation_dispose / '
                        'spSkeletonData_dispose / spBoneData_dispose, real _malloc/_free. Synthetic '
                        'boundaries: spTranslate/Rotate/Scale/ShearTimeline_create and '
                        'spTranslate/RotateTimeline_setFrame recorders whose store shape follows the '
                        'disassembled bodies (scale/shear setFrame thunks deliberately undefined), '
                        'spCurveTimeline_setStepped/setCurve recorders, fixture heap, libc providers, '
                        'hand-built Json nodes. Not an original-equivalence claim.'),
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
            missing = build(ns.out, 'missing-tl-bones-body', omit=(BODY,))
            if (not missing['compile_rc']
                    or 'undefined symbol: readSkeletonData_boneTimelines' not in missing['diagnostic']):
                raise RuntimeError('missing bones-timeline body not refused')
            report['compile_guards'].append({'name': 'missing-tl-bones-body',
                                             'refused': True, **missing})
            print('GUARD missing-tl-bones-body refused', flush=True)
            # Second door: the real readCurve translation unit must be linked,
            # otherwise the call at 0x28d7d0/0x28daf0 has no definition.  A stub
            # would satisfy the link, so this proves the source, not a placeholder.
            nostub = build(ns.out, 'unlinked-read-curve', omit=(CURVE_SRC,))
            if (not nostub['compile_rc']
                    or 'undefined symbol: readCurve' not in nostub['diagnostic']):
                raise RuntimeError('readCurve source removal not refused')
            report['compile_guards'].append({'name': 'unlinked-read-curve',
                                             'refused': True, **nostub})
            print('GUARD unlinked-read-curve refused', flush=True)
            # Third door: the Json accessors must come from c/json_interface.
            nojson = build(ns.out, 'unlinked-json-accessors', omit=(JSON_SRC,))
            if (not nojson['compile_rc']
                    or 'undefined symbol: Json_getFloat' not in nojson['diagnostic']):
                raise RuntimeError('json_interface source removal not refused')
            report['compile_guards'].append({'name': 'unlinked-json-accessors',
                                             'refused': True, **nojson})
            print('GUARD unlinked-json-accessors refused', flush=True)
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
