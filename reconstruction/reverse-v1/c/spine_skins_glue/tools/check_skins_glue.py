#!/usr/bin/env python3
"""Original is read-only.  Execute only rebuilt ARM32 C plus synthetic
heap/libc/JSON/loader providers.  PASS is a scoped reconstructed-consumer
verdict, never an original-equivalence claim.

Subject: the EIGHT physical glue blocks the segment-chain census (asm/
segment_chain_map.md §5.1) assigns to no recovered module — 368 B / 92 insns of
spSkeletonJson_readSkeletonData @0x28b84c

  #1 0x28c7a0..0x28c7e4  68 B 17 insn  path stub (mov r2,#4) + the five-argument
                                      spAttachmentLoader_createAttachment call +
                                      the NULL split + `addls pc,pc,r3,lsl#2`
                                      with its five table entries
  #2 0x28cc68..0x28ccb8  80 B 20 insn  spSkin_addAttachment + the attachment ->
                                      slot -> skin advance and its back edges
  #3 0x28cf24..0x28cf3c  24 B  6 insn  mesh=2 / region=0 / linkedmesh=3 stubs
  #4 0x28cf3c..0x28cf68  44 B 11 insn  ik        "Target bone not found: "
  #5 0x28cf68..0x28cf78  16 B  4 insn  createAttachment NULL split on
                                      loader->error1 (silent skip)
  #6 0x28cf78..0x28cfa8  48 B 12 insn  loader error pair report + bbox=1 stub
  #7 0x28d144..0x28d170  44 B 11 insn  transform "Target bone not found: "
  #8 0x28d170..0x28d19c  44 B 11 insn  path      "Target slot not found: "

BOUNDARY (census §5.2/§5.3): the six semantic gaps that live INSIDE other
modules' declared windows (0x28bf00, 0x28bf28, 0x28bf58, 0x28c104, 0x28c384,
0x28c3b4), the common epilogue 0x28bdcc..0x28bdd4, the chain-level restores
0x28bdd8 / 0x28ccb4 and the four field parsers the jump table lands in
(region 0x28cdac, boundingbox 0x28cd6c, mesh/linkedmesh 0x28cb20, path
0x28ca5c) are NOT translated here.

Real recovered chain under test (all bodies recovered, no stubs):
  spAttachmentLoader_createAttachment  0x284d58  c/spine_atlas_attachment
  spSkin_addAttachment/_Entry_create   0x28ecd8  c/spine_skin
  spSkeletonData_create/dispose        0x28adf8  c/spine_skeleton_data
  _spSkeletonJson_setError             0x28b784  c/spine_json_error
  Json_dispose / ReportSpineError      0x2872c8  c/spine_json_support
  Json_getItem / Json_getString        0x2873c4  c/json_interface
  _malloc / _calloc / _free            0x285c10  c/spine_alloc

Declared synthetic boundaries (NOT recovered bodies): the attachment loader
record + its vtable slot +0x00 (the Atlas loader body 0x284a08 belongs to
another module; the recorder can answer NULL, answer with an object of ANY
stored type and publish error1/error2 the way 0x284df0 does), the four field
parsers, fixture heap + allocator roster, libc providers, hand-built Json
nodes, and the two "Target ..." argument records.

Nothing here executes original libyoyo bytes.  Static anchors (SHA, dynsym,
instruction words, jump table, pc-relative literals) are checked before a run.
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
MOD = C / 'spine_skins_glue'
FIX = MOD / 'fixture/check.c'
BODY = MOD / 'src/spine_skins_glue.c'
HEADER = MOD / 'src/spine_skins_glue.h'
PIN = '3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a'
SKIN_SRC = C / 'spine_skin/src/spine_skin.c'
JSON_SRC = C / 'json_interface/src/json_interface.c'
ATLAS_SRC = C / 'spine_atlas_attachment/src/spine_atlas_attachment.c'
ERR_SRC = C / 'spine_json_error/src/spine_json_error.c'
SOURCES = [C / p for p in (
    'spine_alloc/src/spine_alloc.c',
    'json_interface/src/json_interface.c',
    'spine_skeleton_data/src/spine_skeleton_data.c',
    'spine_json_support/src/spine_json_support.c',
    'spine_json_error/src/spine_json_error.c',
    'spine_atlas_attachment/src/spine_atlas_attachment.c',
    'spine_mesh/src/spine_mesh.c',
    'spine_region_geometry/src/spine_region_geometry.c',
    'spine_skin/src/spine_skin.c',
    'spine_skins_glue/src/spine_skins_glue.c',
    'csprite_resources/fixture/arm32_support.c',
    'spine_linked_postpass/fixture/reporter_adapter.c',
    'spine_skins_glue/fixture/check.c',
)]
INCLUDES = [C / p / 'src' for p in (
    'spine_alloc', 'spine_attachment', 'spine_skeleton_data', 'json_interface',
    'spine_color', 'spine_read_mesh', 'spine_mesh', 'spine_read_vertices',
    'spine_atlas_attachment', 'spine_read_slots', 'skeleton_find',
    'spine_json_error', 'spine_json_support', 'spine_skin',
    'spine_region_geometry', 'spine_read_region', 'spine_read_bbox_path',
    'spine_skins_glue',
)]
FLAGS = ['--target=armv7a-none-eabi', '-march=armv7-a', '-marm', '-mfpu=vfpv3',
         '-mfloat-abi=softfp', '-std=c11', '-ffreestanding', '-fno-builtin',
         '-ffp-contract=off', '-fstack-protector-strong',
         '-mstack-protector-guard=global', '-ffunction-sections',
         '-fdata-sections', '-Wall', '-Wextra', '-Werror', '-nostdlib',
         '-static', '-fuse-ld=lld', '-Wl,--gc-sections', '-Wl,-e,_start']
# Contract names emitted by the fixture, in execution order.
TESTS = ['create_args_five_pointer', 'type_stub_five_landings',
         'stored_type_table', 'stored_type_out_of_range',
         'null_loader_silent_skip', 'loader_error_pair_report',
         'loader_error_pair_null_arg', 'add_attachment_real_queue',
         'add_precedes_advance', 'advance_three_levels',
         'attachment_level_loop', 'ik_target_not_found_tail',
         'transform_target_not_found_tail', 'path_target_slot_not_found_tail',
         'tail_argument_through_r4']
SUMMARY = 'SUMMARY all declared skins glue contracts passed'

# The eight windows, in address order, with their census instruction counts.
WINDS = [
    ('#1 create+table', 0x28c7a0, 0x28c7e4, 17),
    ('#2 add+advance', 0x28cc68, 0x28ccb8, 20),
    ('#3 type stubs', 0x28cf24, 0x28cf3c, 6),
    ('#4 ik tail', 0x28cf3c, 0x28cf68, 11),
    ('#5 null split', 0x28cf68, 0x28cf78, 4),
    ('#6 loader tail', 0x28cf78, 0x28cfa8, 12),
    ('#7 transform tail', 0x28d144, 0x28d170, 11),
    ('#8 path tail', 0x28d170, 0x28d19c, 11),
]

# Raw original instruction words.  Every instruction of every window is pinned;
# the load-bearing ones are named.
WORD_PINS = {
    # --- #1: path stub, five-argument call, NULL split, jump table --------
    0x28c7a0: 0xe3a02004,  # mov r2,#4            path stub (block #1 head)
    0x28c7a4: 0xe5980004,  # ldr r0,[r8,#4]       loader = json->loader
    0x28c7a8: 0xe1a03006,  # mov r3,r6            name
    0x28c7ac: 0xe58d5000,  # str r5,[sp]          path = 5th, ON THE STACK
    0x28c7b0: 0xe1a01009,  # mov r1,r9            skin
    0x28c7b4: 0xebffe167,  # bl spAttachmentLoader_createAttachment
    0x28c7b8: 0xe2506000,  # subs r6,r0,#0
    0x28c7bc: 0x0a0001e9,  # beq 0x28cf68         NULL split
    0x28c7c0: 0xe5963004,  # ldr r3,[r6,#4]       type STORED IN THE OBJECT
    0x28c7c4: 0xe3530004,  # cmp r3,#4
    0x28c7c8: 0x908ff103,  # addls pc,pc,r3,lsl#2 jump table (base 0x28c7d0)
    0x28c7cc: 0xea000125,  # b 0x28cc68           r3 > 4: add only
    0x28c7d0: 0xea000175,  # b 0x28cdac           entry 0 region
    0x28c7d4: 0xea000164,  # b 0x28cd6c           entry 1 boundingbox
    0x28c7d8: 0xea0000d0,  # b 0x28cb20           entry 2 mesh
    0x28c7dc: 0xea0000cf,  # b 0x28cb20           entry 3 linkedmesh -> mesh
    0x28c7e0: 0xea00009d,  # b 0x28ca5c           entry 4 path
    # --- #2: add + three-level advance ------------------------------------
    0x28cc68: 0xe1a02007,  # mov r2,r7            name (the map key)
    0x28cc6c: 0xe1a03006,  # mov r3,r6            attachment
    0x28cc70: 0xe1a00009,  # mov r0,r9            skin
    0x28cc74: 0xe59d1028,  # ldr r1,[sp,#0x28]    slotIndex
    0x28cc78: 0xeb000816,  # bl spSkin_addAttachment
    0x28cc7c: 0xe5944000,  # ldr r4,[r4]          attachment -> next
    0x28cc80: 0xe3540000,  # cmp r4,#0
    0x28cc84: 0x1afffe97,  # bne 0x28c6e8         attachment back edge
    0x28cc88: 0xe59d001c,  # ldr r0,[sp,#0x1c]    slot cell
    0x28cc8c: 0xe5900000,  # ldr r0,[r0]          slot -> next
    0x28cc90: 0xe3500000,  # cmp r0,#0
    0x28cc94: 0xe58d001c,  # str r0,[sp,#0x1c]
    0x28cc98: 0x1afffe89,  # bne 0x28c6c4         slot back edge
    0x28cc9c: 0xe59db034,  # ldr r11,[sp,#0x34]   data restore (chain level)
    0x28cca0: 0xe59d0018,  # ldr r0,[sp,#0x18]    skin cell
    0x28cca4: 0xe5900000,  # ldr r0,[r0]          skin -> next
    0x28cca8: 0xe3500000,  # cmp r0,#0
    0x28ccac: 0xe58d0018,  # str r0,[sp,#0x18]
    0x28ccb0: 0x1afffe6b,  # bne 0x28c664         skin back edge
    0x28ccb4: 0xe1a0900b,  # mov r9,r11           chain level
    # --- #3: the three type load stubs ------------------------------------
    0x28cf24: 0xe3a02002,  # mov r2,#2            mesh
    0x28cf28: 0xeafffe1d,  # b 0x28c7a4
    0x28cf2c: 0xe1a02000,  # mov r2,r0            region (r0 == 0 after strcmp)
    0x28cf30: 0xeafffe1b,  # b 0x28c7a4
    0x28cf34: 0xe3a02003,  # mov r2,#3            linkedmesh
    0x28cf38: 0xeafffe19,  # b 0x28c7a4
    0x28cfa0: 0xe3a02001,  # mov r2,#1            boundingbox (block #6 tail)
    0x28cfa4: 0xeafffdfe,  # b 0x28c7a4
    # --- #4: ik "Target bone not found: " ---------------------------------
    0x28cf3c: 0xe1a04000,  # mov r4,r0            r4 = the failed lookup result
    0x28cf40: 0xe1a00009,  # mov r0,r9            data
    0x28cf44: 0xebfff7ab,  # bl spSkeletonData_dispose
    0x28cf48: 0xe51f25a4,  # ldr r2,[pc,#-0x5a4]  pool 0x28c9ac
    0x28cf4c: 0xe1a00008,  # mov r0,r8            json
    0x28cf50: 0xe59d1024,  # ldr r1,[sp,#0x24]    root
    0x28cf54: 0xe08f2002,  # add r2,pc,r2         -> 0x357c70
    0x28cf58: 0xe594301c,  # ldr r3,[r4,#0x1c]    argument THROUGH r4
    0x28cf5c: 0xebfffa08,  # bl _spSkeletonJson_setError
    0x28cf60: 0xe1a00004,  # mov r0,r4
    0x28cf64: 0xeafffb98,  # b 0x28bdcc           shared epilogue
    # --- #5: the loader->error1 NULL split --------------------------------
    0x28cf68: 0xe5983004,  # ldr r3,[r8,#4]       loader
    0x28cf6c: 0xe5933000,  # ldr r3,[r3]          loader->error1 (+0x00)
    0x28cf70: 0xe3530000,  # cmp r3,#0
    0x28cf74: 0x0affff40,  # beq 0x28cc7c         silent skip -> advance
    # --- #6: the loader error pair report ---------------------------------
    0x28cf78: 0xe59d9034,  # ldr r9,[sp,#0x34]    data
    0x28cf7c: 0xe1a00009,  # mov r0,r9
    0x28cf80: 0xebfff79c,  # bl spSkeletonData_dispose  (BEFORE the report)
    0x28cf84: 0xe5983004,  # ldr r3,[r8,#4]       loader
    0x28cf88: 0xe1a00008,  # mov r0,r8            json
    0x28cf8c: 0xe59d1024,  # ldr r1,[sp,#0x24]    root
    0x28cf90: 0xe893000c,  # ldm r3,{r2,r3}       error1, error2 (not static text)
    0x28cf94: 0xebfff9fa,  # bl _spSkeletonJson_setError
    0x28cf98: 0xe1a00006,  # mov r0,r6            the failed attachment
    0x28cf9c: 0xeafffb8a,  # b 0x28bdcc           shared epilogue
    # --- #7: transform "Target bone not found: " --------------------------
    0x28d144: 0xe1a04000,  # mov r4,r0
    0x28d148: 0xe1a00009,  # mov r0,r9
    0x28d14c: 0xebfff729,  # bl spSkeletonData_dispose
    0x28d150: 0xe51f2788,  # ldr r2,[pc,#-0x788]  pool 0x28c9d0
    0x28d154: 0xe1a00008,  # mov r0,r8
    0x28d158: 0xe59d1024,  # ldr r1,[sp,#0x24]
    0x28d15c: 0xe08f2002,  # add r2,pc,r2         -> 0x357c70 (same literal)
    0x28d160: 0xe594301c,  # ldr r3,[r4,#0x1c]
    0x28d164: 0xebfff986,  # bl _spSkeletonJson_setError
    0x28d168: 0xe1a00004,  # mov r0,r4
    0x28d16c: 0xeafffb16,  # b 0x28bdcc
    # --- #8: path "Target slot not found: " -------------------------------
    0x28d170: 0xe1a04000,  # mov r4,r0
    0x28d174: 0xe1a00009,  # mov r0,r9
    0x28d178: 0xebfff71e,  # bl spSkeletonData_dispose
    0x28d17c: 0xe51f27b0,  # ldr r2,[pc,#-0x7b0]  pool 0x28c9d4
    0x28d180: 0xe1a00008,  # mov r0,r8
    0x28d184: 0xe59d1024,  # ldr r1,[sp,#0x24]
    0x28d188: 0xe08f2002,  # add r2,pc,r2         -> 0x357d14
    0x28d18c: 0xe594301c,  # ldr r3,[r4,#0x1c]
    0x28d190: 0xebfff97b,  # bl _spSkeletonJson_setError
    0x28d194: 0xe1a00004,  # mov r0,r4
    0x28d198: 0xeafffb0b,  # b 0x28bdcc
    # --- the three entry edges into the tails (r0 == 0 on every one) ------
    0x28bfa0: 0xe3500000,  # cmp r0,#0            ik: spSkeletonData_findBone
    0x28bfa8: 0x0a0003e3,  # beq 0x28cf3c
    0x28c14c: 0xe3500000,  # cmp r0,#0            transform: findBone
    0x28c154: 0x0a0003fa,  # beq 0x28d144
    0x28c3f4: 0xe3500000,  # cmp r0,#0            path: findSlot
    0x28c3fc: 0x0a00035b,  # beq 0x28d170
}
TAIL_EDGES = ((0x28bfa8, 0x28cf3c), (0x28c154, 0x28d144), (0x28c3fc, 0x28d170))
SYMBOL_PINS = {
    'spSkeletonJson_readSkeletonData': (0x28b84c, 13044),
    'spAttachmentLoader_createAttachment': (0x284d58, 96),
    'spSkin_addAttachment': (0x28ecd8, 40),
    'spSkin_create': (0x28ec44, 88),
    'spSkeletonData_dispose': (0x28adf8, 452),
    'spSkeletonData_findBone': (0x28afbc, 92),
    'spSkeletonData_findSlot': (0x28b070, 92),
    '_spSkeletonJson_setError': (0x28b784, 200),
    'Json_dispose': (0x2872c8, 88),
    'Json_getItem': (0x2873c4, 100),
    'Json_getString': (0x287428, 28),
    'ReportSpineError': (0xc4404, 52),
    '_malloc': (0x285c10, 60),
    '_calloc': (0x285c4c, 52),
    '_free': (0x285c80, 28),
}
# (literal pool word address, the ADD site whose +8 PC base resolves it,
#  expected text).  va = add_site + 8 + pool_word.
KEY_PINS = (
    (0x28c9ac, 0x28cf54, 'Target bone not found: '),   # #4 ik
    (0x28c9d0, 0x28d15c, 'Target bone not found: '),   # #7 transform, same va
    (0x28c9d4, 0x28d188, 'Target slot not found: '),   # #8 path
)
# bl site -> the dynsym entry it must reach.
CALL_PINS = (
    (0x28c7b4, 'spAttachmentLoader_createAttachment'),
    (0x28cc78, 'spSkin_addAttachment'),
    (0x28cf44, 'spSkeletonData_dispose'),
    (0x28cf80, 'spSkeletonData_dispose'),
    (0x28d14c, 'spSkeletonData_dispose'),
    (0x28d178, 'spSkeletonData_dispose'),
    (0x28cf5c, '_spSkeletonJson_setError'),
    (0x28cf94, '_spSkeletonJson_setError'),
    (0x28d164, '_spSkeletonJson_setError'),
    (0x28d190, '_spSkeletonJson_setError'),
)
# entry | the five table entries | the fall-through add | entry 3 == entry 2
JUMP_TABLE = {0x28cdac: 'region', 0x28cd6c: 'boundingbox', 0x28cb20: 'mesh',
              0x28ca5c: 'path'}


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
    """ARM32 B/BL: 0x?? ??????, imm24<<2 signed, pc = addr+8."""
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

        words = {hex(a): struct.unpack('<I', raw(a, 4))[0] for a in WORD_PINS}
        for a, want in WORD_PINS.items():
            if words[hex(a)] != want:
                raise ValueError(f'word pin drifted at {a:#x}: '
                                 f'{words[hex(a)]:#x} != {want:#x}')

        # Every instruction of the eight windows must be pinned: 92 of them.
        pinned = 0
        for name, lo, hi, insns in WINDS:
            if (hi - lo) // 4 != insns:
                raise ValueError(f'{name}: window size != census count')
            for a in range(lo, hi, 4):
                if a not in WORD_PINS:
                    raise ValueError(f'{name}: instruction {a:#x} is not pinned')
                pinned += 1
        if pinned != 92:
            raise ValueError(f'pinned {pinned} instructions, census says 92')

        # The jump table: base = addls + 8, five entries, and the entries must
        # land on the four field parsers (3 shares 2's target).
        table = []
        for i in range(5):
            a = 0x28c7d0 + 4 * i
            w = struct.unpack('<I', raw(a, 4))[0]
            if (w >> 24) != 0xea:
                raise ValueError(f'table entry {i} is not a b: {w:#x}')
            tgt = bl_target(w, a)
            if tgt not in JUMP_TABLE:
                raise ValueError(f'table entry {i} -> {tgt:#x} is not a parser')
            table.append([hex(a), hex(tgt), JUMP_TABLE[tgt]])
        if table[2][1] != table[3][1]:
            raise ValueError('entries 2 and 3 must share the mesh parser')
        if bl_target(struct.unpack('<I', raw(0x28c7cc, 4))[0], 0x28c7cc) \
                != 0x28cc68:
            raise ValueError('the r3 > 4 fall-through is not b 0x28cc68')

        calls = []
        for site, want in CALL_PINS:
            got = bl_target(struct.unpack('<I', raw(site, 4))[0], site)
            if got != found[want][0]:
                raise ValueError(f'call {site:#x} -> {got:#x} is not '
                                 f'{want} {found[want][0]:#x}')
            calls.append([hex(site), want, hex(got)])
        edges = []
        for site, want in TAIL_EDGES:
            got = bl_target(struct.unpack('<I', raw(site, 4))[0], site)
            if got != want:
                raise ValueError(f'tail edge {site:#x} -> {got:#x} != {want:#x}')
            edges.append([hex(site), hex(got)])
        keys = []
        for pool, add_site, want in KEY_PINS:
            w = struct.unpack('<I', raw(pool, 4))[0]
            va = (add_site + 8 + w) & 0xffffffff
            value = raw(va, 64).split(b'\0', 1)[0].decode('ascii')
            if value != want:
                raise ValueError(f'pc-relative literal mismatch {add_site:#x}: '
                                 f'{value!r} != {want!r}')
            keys.append({'pool': hex(pool), 'add_site': hex(add_site),
                         'va': hex(va), 'value': value})
        if keys[0]['va'] != keys[1]['va']:
            raise ValueError('ik and transform no longer share 0x357c70')
    return {'original_sha256': PIN,
            'symbol_pins': {k: [hex(v[0]), v[1]] for k, v in SYMBOL_PINS.items()},
            'word_pins': words, 'pinned_instructions': pinned,
            'windows': [[n, hex(lo), hex(hi), c] for n, lo, hi, c in WINDS],
            'jump_table': table, 'call_pins': calls, 'tail_edges': edges,
            'message_literals': keys,
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
    print('BINDING v1 entry=skins-glue run=' + name
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
    """Named mutants of the BODY text only; each one must be refused by a NAMED
    runtime assertion.  Every mutant still compiles cleanly."""
    return [
        # --- the five type load stubs (block #3 + the path/bbox siblings) --
        ('type_stub_mesh_as_linkedmesh', [
            ('json, skin, SKINS_GLUE_TYPE_MESH, name, path,',
             'json, skin, SKINS_GLUE_TYPE_LINKEDMESH, name, path,')],
         'the stub loads exactly the r2 constant of its branch'),
        ('type_stub_region_as_bbox', [
            ('json, skin, SKINS_GLUE_TYPE_REGION, name, path,',
             'json, skin, SKINS_GLUE_TYPE_BOUNDINGBOX, name, path,')],
         'the stub loads exactly the r2 constant of its branch'),
        # --- the jump table ------------------------------------------------
        ('jump_table_entry3_removed', [
            ('case SKINS_GLUE_TYPE_LINKEDMESH:   /* 0x28c7dc b 0x28cb20 */',
             'case 99:   /* mutated: table entry 3 lost */')],
         'the jump table lands in the parser of the STORED type'),
        ('jump_table_unsigned_guard', [
            ('if ((uint32_t)stored_type <= (uint32_t)SKINS_GLUE_TYPE_PATH) {',
             'if ((uint32_t)stored_type < (uint32_t)SKINS_GLUE_TYPE_PATH) {')],
         'the jump table lands in the parser of the STORED type'),
        ('dispatch_on_requested_type', [
            ('stored_type = ((const skins_glue_attachment_head*)attachment)->type;',
             'stored_type = type;   /* mutated: requested instead of stored */')],
         'dispatches on the STORED type (2 -> mesh), not the request'),
        ('mesh_slot_index_zero', [
            ('attachmentMap, attachment, path, json, slotIndex);',
             'attachmentMap, attachment, path, json, 0u);')],
         'mesh/linkedmesh parser also gets path (r5) and slotIndex'),
        # --- the loader NULL split (blocks #5/#6) --------------------------
        ('null_split_returns_published', [
            ('            return SKINS_GLUE_SKIPPED;', '            return SKINS_GLUE_PUBLISHED;')],
         'createAttachment NULL + loader->error1 == 0 returns the skip code'),
        ('loader_pair_swapped', [
            ('_spSkeletonJson_setError(json, root, loader->error1, loader->error2);',
             '_spSkeletonJson_setError(json, root, loader->error2, loader->error1);')],
         'message = loader->error1 and argument = loader->error2'),
        ('loader_tail_without_dispose', [
            ('/* 0x28cf7c mov r0,r9 ; 0x28cf80 bl 0x28adf8 */\n'
             '    spSkeletonData_dispose((spSkeletonData*)data_raw);',
             '/* mutated: the loader error tail never disposes the data */\n'
             '    (void)data_raw;')],
         'spSkeletonData_dispose(data) ran exactly once (0x28cf80)'),
        # --- the add (block #2) -------------------------------------------
        ('add_dropped', [
            ('readSkeletonData_skinsAttachmentAdd(skin, slotIndex, name, attachment);\n'
             '    return SKINS_GLUE_PUBLISHED;',
             'return SKINS_GLUE_PUBLISHED;')],
         'the object is published through the real spSkin_addAttachment'),
        # --- the three-level advance --------------------------------------
        ('advance_first_level_wrong_code', [
            ('if (next != 0)\n        return SKINS_GLUE_NEXT_ATTACHMENT;',
             'if (next != 0)\n        return SKINS_GLUE_NEXT_SLOT;')],
         'att1 -> att2 keeps the attachment loop'),
        ('advance_skin_level_dropped', [
            ('next = cursor->skin->next;', 'next = 0;   /* mutated: no skin level */')],
         'slotB has no sibling, the SKIN advances'),
        # --- the three "Target ..." tails ---------------------------------
        ('tail_slot_literal', [
            ('#define SKINS_GLUE_ERR_TARGET_SLOT "Target slot not found: "',
             '#define SKINS_GLUE_ERR_TARGET_SLOT "Target slot not found:"')],
         'the message is the exact literal plus the [r4+0x1c] argument'),
        ('tail_ik_json_argument_null', [
            ('/* 0x28cf48 ldr r2,[pc,#-0x5a4] -> pool 0x28c9ac = 0x000cad14\n'
             '     * 0x28cf54 add r2,pc,r2 -> 0x28cf5c + 0xcad14 = 0x357c70 */\n'
             '    _spSkeletonJson_setError(json, root, SKINS_GLUE_ERR_TARGET_BONE,',
             '/* mutated: the ik tail passes a NULL json argument */\n'
             '    (void)root;\n'
             '    _spSkeletonJson_setError(json, 0, SKINS_GLUE_ERR_TARGET_BONE,')],
         'the setError json argument is [sp,#0x24]: the whole root tree is disposed'),
        ('tail_return_zero', [
            ('return (int)(intptr_t)r4;                           /* 0x28cf60 mov r0,r4 */',
             'return 0;   /* mutated: r4 is not returned */')],
         'the tail returns r4'),
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
    report = {'schema': 'cally-skins-glue-check/1', 'tier': 'test_anchored',
              'original_executed': False,
              'entry': ('skins/attachments glue: createAttachment five-argument call + '
                        'type jump table (0x28c7a0-0x28c7e4), spSkin_addAttachment + '
                        'three-level advance (0x28cc68-0x28ccb8), type load stubs '
                        '(0x28cf24-0x28cf3c), loader->error1 NULL split '
                        '(0x28cf68-0x28cf78), loader error pair report '
                        '(0x28cf78-0x28cfa8), ik/transform/path "Target ..." tails '
                        '(0x28cf3c, 0x28d144, 0x28d170)'),
              'scope': ('Reconstructed glue C only: real spAttachmentLoader_createAttachment '
                        'wrapper, real spSkin_addAttachment, real spSkeletonData_dispose, '
                        'real _spSkeletonJson_setError, real Json accessors and allocator. '
                        'The five jump-table landings call real module entry points that are '
                        'REPLACED here by argument recorders (region/boundingbox/mesh/path '
                        'field parsers belong to their own modules); the attachment loader '
                        'record + vtable slot +0x00 are a recorder that can answer NULL, answer '
                        'with any stored type, and publish error1/error2. 0x28bdcc, 0x28bdd8, '
                        '0x28ccb4 and the six §5.2 semantic gaps are NOT modelled. '
                        'Not an original-equivalence claim.'),
              'boundary': {
                  'translated': [f'{n} {lo:#x}-{hi:#x} ({c} insns)'
                                 for n, lo, hi, c in WINDS],
                  'total_bytes': 368, 'total_instructions': 92,
                  'not_translated': [
                      'census §5.2 semantic gaps 0x28bf00/0x28bf28/0x28bf58/'
                      '0x28c104/0x28c384/0x28c3b4 (inside other modules windows)',
                      'census §5.3 common epilogue 0x28bdcc..0x28bdd4 and the '
                      'chain restores 0x28bdd8 / 0x28ccb4 / 0x28cc9c',
                      'the four field parsers the jump table lands in: region '
                      '0x28cdac (c/spine_read_region), boundingbox 0x28cd6c and '
                      'path 0x28ca5c (c/spine_read_bbox_path), mesh/linkedmesh '
                      '0x28cb20 (c/spine_read_mesh)',
                      'the Atlas loader body 0x284a08 (synthetic vtable recorder here)'],
                  'tail_entry_edges': ('0x28bfa8 beq 0x28cf3c, 0x28c154 beq 0x28d144, '
                                       '0x28c3fc beq 0x28d170 — all three are reached only '
                                       'with r0 == 0, so `ldr r3,[r4,#0x1c]` reads VA 0x1c '
                                       'in the original (latent NULL-page read); the fixture '
                                       'injects an argument record to observe offset and '
                                       'register source instead of faulting'),
              },
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
            for name, edits, expect in mutations():
                text = BODY.read_text()
                for old, new in edits:
                    text = replace_once(text, old, new)
                candidate = ns.out / (name + '.c')
                candidate.write_text(text)
                r = build(ns.out, name, overrides={BODY: candidate})
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
            guards = [
                ('missing-skins-glue-body', (BODY,),
                 'undefined symbol: readSkeletonData_skinsCreatePathAttachment'),
                ('unlinked-spine-skin', (SKIN_SRC,),
                 'undefined symbol: spSkin_addAttachment'),
                ('unlinked-json-interface', (JSON_SRC,),
                 'undefined symbol: Json_getString'),
                ('unlinked-atlas-attachment', (ATLAS_SRC,),
                 'undefined symbol: spAttachmentLoader_createAttachment'),
                ('unlinked-json-error', (ERR_SRC,),
                 'undefined symbol: _spSkeletonJson_setError'),
            ]
            for name, omit, want in guards:
                r = build(ns.out, name, omit=omit)
                if not r['compile_rc'] or want not in r['diagnostic']:
                    raise RuntimeError(f'{name}: not refused with {want!r}')
                report['compile_guards'].append({'name': name, 'refused': True,
                                                 'expected': want, **r})
                print('GUARD', name, 'refused', flush=True)
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
