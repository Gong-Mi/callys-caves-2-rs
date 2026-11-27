#!/usr/bin/env python3
"""Original is read-only.  Execute only the rebuilt ARM32 C (the assembled chain
plus every recovered segment module and their real dependencies) under qemu-arm;
the original libyoyo bytes are never loaded or executed.  PASS is a scoped
reconstructed-assembly verdict, never an original-equivalence claim.

Subject: the complete spSkeletonJson_readSkeletonData @0x28b84c (13044 B) of
libyoyo_armv7.so, assembled by c/spine_read_skeleton:

  entry  0x28b84c..0x28b8f0   locale guard + Json_create + data + "skeleton"
  meta   0x28b8f4..0x28ba40   skeleton fields + bones array
  bones  0x28ba40..0x28bbcc   bone loop
  slots  0x28bbcc..0x28bdd8   slots segment (owns its own error tail)
  ik     0x28bdd8..0x28bff8   ik constraints
  xform  0x28bff8..0x28c274   transform constraints
  path   0x28c274..0x28c5ec   path constraints
  skins  0x28c5ec..0x28ccb8   skins -> slots -> attachments (dispatch + glue)
  link   0x28ccb8..0x28d19c   linkedmesh postpass
  anim   0x28d19c..0x28e7a0   events + animations (B1/B2 + per-animation loop)
  B18    0x28e7a4..0x28e7b0   Json_dispose(root); return data
  tail   0x28bdcc..0x28bdd4   the single shared epilogue

What this checker proves, in its own words:

  * WIRING — every segment entry point is called once per loader call with the
    arguments the chain hands it (roots, data, parser, scale instant), and the
    segment ORDER is the original single chain: an exchange, a dropped stage or
    a mis-routed root is refused by a named assertion.
  * END TO END — one synthetic skeleton JSON tree with parented bones, a slot
    with blend/color, one ik/transform/path constraint, a skin with region and
    mesh attachments and one animation (rotate + translate frames, one array
    curve, one stepped curve, one event) walks the whole chain; the produced
    spSkeletonData counts/arrays/values/duration/event strings are asserted.
  * ERROR PATHS — every segment code that the module reports instead of
    emitting (census §5.2) is closed by this layer with
    dispose(data) -> setError(self, root, literal, arg) -> NULL, in that order;
    the loader-error pair and the out-of-window "Unknown attachment type" tail
    are exercised too.
  * LIFETIMES — the root is released exactly once on success (B18) and exactly
    once on the ten dispose-bearing error tails (inside setError), and it LEAKS
    on the two linkedmesh tails that pass root = 0 (the original's behaviour,
    asserted as a leak, not repaired).
  * ONLY ONCE — no segment is emitted twice (meta allocations counted), the
    shared epilogue exists as one C return, and json->scale is re-read at every
    scaling site instead of being cached across calls.

Family/module evidence for the segments themselves lives in their own checkers;
this receipt is about the assembly.
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
MOD = C / 'spine_read_skeleton'
FIX = MOD / 'fixture/check.c'
BODY = MOD / 'src/spine_read_skeleton.c'
HEADER = MOD / 'src/spine_read_skeleton.h'
PIN = '3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a'

SEGMENTS = [
    'spine_read_entry/src/spine_read_entry.c',
    'spine_read_meta/src/spine_read_meta.c',
    'spine_read_bones/src/spine_read_bones.c',
    'spine_read_slots/src/spine_read_slots.c',
    'spine_read_ik/src/spine_read_ik.c',
    'spine_read_transform/src/spine_read_transform.c',
    'spine_read_path/src/spine_read_path.c',
    'spine_read_skins/src/spine_read_skins.c',
    'spine_read_attach_dispatch/src/spine_read_attach_dispatch.c',
    'spine_read_region/src/spine_read_region.c',
    'spine_read_bbox_path/src/spine_read_bbox_path.c',
    'spine_read_mesh/src/spine_read_mesh.c',
    'spine_skins_glue/src/spine_skins_glue.c',
    'spine_linked_postpass/src/spine_linked_postpass.c',
    'spine_read_animations/src/spine_read_animations.c',
    'spine_animations_loop/src/spine_animations_loop.c',
]
FAMILIES = [
    'spine_read_tl_slots/src/spine_read_tl_slots.c',
    'spine_read_tl_bones/src/spine_read_tl_bones.c',
    'spine_read_tl_ik/src/spine_read_tl_ik.c',
    'spine_read_tl_transform/src/spine_read_tl_transform.c',
    'spine_read_tl_path/src/spine_read_tl_path.c',
    'spine_read_tl_deform/src/spine_read_tl_deform.c',
    'spine_read_tl_draworder/src/spine_read_tl_draworder.c',
    'spine_read_tl_event/src/spine_read_tl_event.c',
    'spine_read_tl_path_mix/src/spine_read_tl_path_mix.c',
]
SUPPORT = [
    'spine_alloc/src/spine_alloc.c',
    'json_interface/src/json_interface.c',
    'spine_color/src/spine_color.c',
    'spine_skeleton_data/src/spine_skeleton_data.c',
    'spine_json_support/src/spine_json_support.c',
    'spine_json_error/src/spine_json_error.c',
    'spine_read_curve/src/spine_read_curve.c',
    'skeleton_find/src/skeleton_find.c',
    'spine_skin/src/spine_skin.c',
    'spine_mesh/src/spine_mesh.c',
    'spine_region_geometry/src/spine_region_geometry.c',
    'spine_atlas_attachment/src/spine_atlas_attachment.c',
    'spine_read_vertices/src/spine_read_vertices.c',
]
RUNTIME = [
    'csprite_resources/fixture/arm32_support.c',
    'spine_linked_postpass/fixture/reporter_adapter.c',
]
SOURCES = [C / p for p in (SEGMENTS + FAMILIES + SUPPORT +
                           ['spine_read_skeleton/src/spine_read_skeleton.c'] +
                           RUNTIME + ['spine_read_skeleton/fixture/check.c'])]
INCLUDES = [C / p / 'src' for p in (
    'spine_alloc', 'spine_attachment', 'spine_skeleton_data', 'json_interface',
    'spine_color', 'spine_read_mesh', 'spine_mesh', 'spine_read_vertices',
    'spine_atlas_attachment', 'spine_read_slots', 'skeleton_find',
    'spine_json_error', 'spine_json_support', 'spine_read_animations',
    'spine_read_curve', 'spine_read_tl_slots', 'spine_read_tl_bones',
    'spine_read_tl_ik', 'spine_read_tl_transform', 'spine_read_tl_path',
    'spine_read_tl_deform', 'spine_read_tl_draworder', 'spine_read_tl_event',
    'spine_read_tl_path_mix', 'spine_skin', 'spine_animations_loop',
    'spine_read_skeleton', 'spine_read_entry', 'spine_read_meta',
    'spine_read_bones', 'spine_read_ik', 'spine_read_transform',
    'spine_read_path', 'spine_read_skins', 'spine_read_attach_dispatch',
    'spine_skins_glue', 'spine_linked_postpass', 'spine_region_geometry',
    'spine_read_region', 'spine_read_bbox_path',
)]
FLAGS = ['--target=armv7a-none-eabi', '-march=armv7-a', '-marm', '-mfpu=vfpv3',
         '-mfloat-abi=softfp', '-std=c11', '-ffreestanding', '-fno-builtin',
         '-ffp-contract=off', '-fstack-protector-strong',
         '-mstack-protector-guard=global', '-ffunction-sections',
         '-fdata-sections', '-Wall', '-Wextra', '-Werror', '-nostdlib',
         '-static', '-fuse-ld=lld', '-Wl,--gc-sections', '-Wl,--error-limit=0',
         # the fixture's entry point is chain_start: the reused animations-loop
         # fixture keeps its own (unreferenced, GC'd) _start.
         '-Wl,-e,chain_start']

TESTS = [
    'chain_segment_attribution',
    'chain_full_end_to_end',
    'chain_error_parent_bone',
    'chain_error_ik_bone',
    'chain_error_ik_target',
    'chain_error_transform_bone',
    'chain_error_transform_target',
    'chain_error_path_bone',
    'chain_error_path_target',
    'chain_error_slot_bone',
    'chain_error_unknown_attachment',
    'chain_attachment_create_null_silent',
    'chain_error_loader_report',
    'chain_error_linked_skin_leak',
    'chain_error_linked_parent_leak',
    'chain_json_create_failure',
    'chain_locale_fallback',
    'chain_optional_sections_absent',
    'chain_scale_read_per_call',
    'chain_file_wrapper',
]
SUMMARY = 'SUMMARY all declared skeleton chain contracts passed'

BLOCKS = [
    {'name': 'entry', 'range': '0x28b84c..0x28b8f0',
     'role': 'error free + unk_10 clear, locale guard, Json_create, data, "skeleton"'},
    {'name': 'meta', 'range': '0x28b8f4..0x28ba40',
     'role': 'hash 607 / spine 608 / width / height, bones array 615'},
    {'name': 'bones', 'range': '0x28ba40..0x28bbcc', 'role': 'bone loop'},
    {'name': 'slots', 'range': '0x28bbcc..0x28bdd8',
     'role': 'slots array 651 + loop + its own dispose/setError tail'},
    {'name': 'ik', 'range': '0x28bdd8..0x28bff8', 'role': 'ik array 697 + loop'},
    {'name': 'transform', 'range': '0x28bff8..0x28c274',
     'role': 'transform array 735 + loop'},
    {'name': 'path', 'range': '0x28c274..0x28c5ec', 'role': 'path array 782 + loop'},
    {'name': 'skins', 'range': '0x28c5ec..0x28ccb8',
     'role': 'skin -> slot -> attachment three-level window (glue cursor)'},
    {'name': 'link', 'range': '0x28ccb8..0x28d19c', 'role': 'linkedmesh postpass'},
    {'name': 'anim', 'range': '0x28d19c..0x28e7a0',
     'role': 'B1 events + B2 animations + per-animation loop'},
    {'name': 'B18', 'range': '0x28e7a4..0x28e7b0',
     'role': 'Json_dispose(root) then return data'},
    {'name': 'tail', 'range': '0x28bdcc..0x28bdd4',
     'role': 'the single shared epilogue this assembly emits once'},
    {'name': 'GAP-UNKNOWN-ATT', 'range': '0x28e7f4..0x28e81c',
     'role': 'out-of-window "Unknown attachment type" tail closed by this layer'},
]

# Raw original instruction words.  Every entry is a chain transition the
# assembly depends on: the top-level dispatch (getItem + its branch), the B18
# tail, the single epilogue, the chain-level restores, and the six §5.2 gap
# blocks plus the out-of-window unknown-attachment tail.
WORD_PINS = {
    0x28b84c: 0xe92d4ff0,  # push {r4-r11,lr}          function head
    # --- the eight top-level Json_getItem calls and their branches ---------
    0x28b8e8: 0xebffeeb5,  # bl Json_getItem           1 "skeleton"
    0x28b8f0: 0x0a000035,  # beq 0x28b9cc              absent -> skip meta
    0x28b9d8: 0xebffee79,  # bl Json_getItem           2 "bones" (NO null test)
    0x28bbd8: 0xebffedf9,  # bl Json_getItem           3 "slots"
    0x28bbe0: 0x0a00007d,  # beq 0x28bddc
    0x28bde8: 0xebffed75,  # bl Json_getItem           4 "ik"
    0x28bdf0: 0x0a000080,  # beq 0x28bff8
    0x28c004: 0xebffecee,  # bl Json_getItem           5 "transform"
    0x28c00c: 0x0a000098,  # beq 0x28c274
    0x28c280: 0xebffec4f,  # bl Json_getItem           6 "path"
    0x28c288: 0x0a0000d7,  # beq 0x28c5ec
    0x28c5f8: 0xebffeb71,  # bl Json_getItem           7 "skins"
    0x28c600: 0x0a0001ac,  # beq 0x28ccb8
    0x28d1a8: 0xebffe885,  # bl Json_getItem           8 "events"   (B1)
    0x28d1b0: 0x0a000036,  # beq 0x28d290
    0x28d29c: 0xebffe848,  # bl Json_getItem           9 "animations" (B2)
    0x28d2a4: 0x0a00053e,  # beq 0x28e7a4              absent -> B18
    # --- chain-level restores (census §5.3, emitted as C locals) -----------
    0x28bdd8: 0xe59d8028,  # ldr r8,[sp,#0x28]         json restore at the ik head
    0x28ccb4: 0xe1a0900b,  # mov r9,r11                data restore at the skins exit
    # --- the one shared epilogue ------------------------------------------
    0x28bdcc: 0xe28dd07c,  # add sp,sp,#124
    0x28bdd4: 0xe8bd8ff0,  # pop {r4-r11,pc}
    # --- B18 ---------------------------------------------------------------
    0x28e7a4: 0xe59d0024,  # ldr r0,[sp,#0x24]         root
    0x28e7a8: 0xebffe2c6,  # bl Json_dispose
    0x28e7ac: 0xe1a00009,  # mov r0,r9                 data
    0x28e7b0: 0xeafff585,  # b 0x28bdcc
    # --- §5.2 gap 1: ik "IK bone not found" tail ---------------------------
    0x28bf14: 0xebfffe1a,  # bl _spSkeletonJson_setError
    0x28bf18: 0xe1a0000a,  # mov r0,r10                r10 was zeroed at 0x28bef8
    # --- §5.2 gap 2: bones "Parent bone not found" tail --------------------
    0x28bf2c: 0xebfffbb1,  # bl spSkeletonData_dispose
    0x28bf44: 0xebfffe0e,  # bl _spSkeletonJson_setError
    # --- §5.2 gap 3: setlocale(NULL) fallback ------------------------------
    0x28bf58: 0xe59f1928,  # ldr r1,[pc,#0x928]        "C"
    0x28bf64: 0xebf8aa0c,  # bl setlocale
    0x28bf6c: 0xebffeceb,  # bl Json_create
    0x28bf7c: 0xebf8aa06,  # bl setlocale              NULL, no restore
    # --- §5.2 gap 4: transform "Transform bone not found" tail -------------
    0x28c10c: 0xebfffb39,  # bl spSkeletonData_dispose
    0x28c124: 0xebfffd96,  # bl _spSkeletonJson_setError
    # --- §5.2 gap 5: path "Path bone not found" tail -----------------------
    0x28c38c: 0xebfffa99,  # bl spSkeletonData_dispose
    0x28c3a4: 0xebfffcf6,  # bl _spSkeletonJson_setError
    # --- §5.2 gap 6: Json_create failure tail ------------------------------
    0x28c3b4: 0xebffebbf,  # bl Json_getError
    0x28c3cc: 0xebfffcec,  # bl _spSkeletonJson_setError
    # --- out-of-window unknown-attachment tail -----------------------------
    0x28c79c: 0x1a000814,  # bne 0x28e7f4              dispatch fall-through
    0x28e7fc: 0xebfff17d,  # bl spSkeletonData_dispose
    0x28e814: 0xebfff3da,  # bl _spSkeletonJson_setError
    # --- §5.1 #4/#7/#8: the three glue target tails this layer routes ------
    0x28bfa8: 0x0a0003e3,  # beq 0x28cf3c              ik target
    0x28c154: 0x0a0003fa,  # beq 0x28d144              transform target
    0x28c3fc: 0x0a00035b,  # beq 0x28d170              path target slot
}
SYMBOL_PINS = {
    'spSkeletonJson_readSkeletonData': (0x28b84c, 13044),
    'spSkeletonJson_readSkeletonDataFile': (0x28eb40, 120),
    'Json_getItem': (0x2873c4, 100),
    'Json_getString': (0x287428, 28),
    'Json_getFloat': (0x287444, 28),
    'Json_getInt': (0x287460, 28),
    'Json_create': (0x287320, 164),
    'Json_getError': (0x2872b8, 16),
    'Json_dispose': (0x2872c8, 88),
    'ReportSpineError': (0xc4404, 52),
    '_malloc': (0x285c10, 60),
    '_calloc': (0x285c4c, 52),
    '_free': (0x285c80, 28),
    '_spSkeletonJson_setError': (0x28b784, 200),
    'spSkeletonData_create': (0x28addc, 28),
    'spSkeletonData_dispose': (0x28adf8, 452),
    'spBoneData_dispose': (0x285ac4, 28),
    'spSlotData_dispose': (0x28efa8, 36),
    'spSkin_dispose': (0x28ec9c, 60),
    'spEventData_dispose': (0x285bec, 36),
    'spAnimation_dispose': (0x28147c, 80),
    'spIkConstraintData_dispose': (0x286758, 36),
    'spTransformConstraintData_dispose': (0x28f608, 36),
    'spPathConstraintData_dispose': (0x288f34, 36),
    'spTimeline_dispose': (0x281468, 20),
    'spAttachment_dispose': (0x284cb4, 20),
    '_Entry_dispose': (0x28ec20, 36),
    '_Entry_create': (0x28ebb8, 104),
    'spSkeletonData_findBone': (0x28afbc, 92),
    'spSkeletonData_findSlotIndex': (0x28b0cc, 88),
    'spSkeletonData_findSkin': (0x28b124, 92),
    'spSkeletonData_findSlot': (0x28b070, 92),
    'spSkin_create': (0x28ec44, 88),
    'spSkin_addAttachment': (0x28ecd8, 40),
    'spSkin_getAttachment': (0x28ed00, 88),
    'spAttachmentLoader_createAttachment': (0x284d58, 96),
    'spAttachmentLoader_configureAttachment': (0x284db8, 28),
    '_spAttachmentLoader_setError': (0x284df0, 120),
    '_spAttachmentLoader_setUnknownTypeError': (0x284e68, 112),
    'spRegionAttachment_create': (0x288f78, 100),
    'spBoundingBoxAttachment_create': (0x285af8, 72),
    'spMeshAttachment_create': (0x2874dc, 92),
    'spPathAttachment_create': (0x2876f4, 72),
    'spRegionAttachment_updateOffset': (0x289040, 308),
    'spMeshAttachment_updateUVs': (0x287538, 280),
    'spMeshAttachment_setParentMesh': (0x287654, 128),
    'spSkeletonData_findBoneIndex': (0x28b018, 88),
    'spRotateTimeline_create': (0x282a90, 24),
    'spIkConstraintTimeline_create': (0x282f74, 24),
}
# (literal pool word address, ADD site, expected text) — every key the top level
# looks up and every literal this layer's tails emit.
KEY_PINS = (
    (0x28c7e8, 0x28b8dc, 'skeleton'),
    (0x28c800, 0x28b9d4, 'bones'),
    (0x28c838, 0x28bbd4, 'slots'),
    (0x28c864, 0x28bde4, 'ik'),
    (0x28c88c, 0x28c000, 'transform'),
    (0x28c8cc, 0x28c27c, 'path'),
    (0x28c928, 0x28c5f4, 'skins'),
    (0x28c9d8, 0x28d1a4, 'events'),
    (0x28c9f0, 0x28d298, 'animations'),
    (0x28c880, 0x28bf10, 'IK bone not found: '),
    (0x28c884, 0x28bf40, 'Parent bone not found: '),
    (0x28c8a4, 0x28c120, 'Transform bone not found: '),
    (0x28c8e4, 0x28c3a0, 'Path bone not found: '),
    (0x28c8e8, 0x28c3c0, 'Invalid skeleton JSON: '),
    (0x28eb04, 0x28e810, 'Unknown attachment type: '),
)


def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def run(argv, timeout=300):
    return subprocess.run([str(x) for x in argv], text=True, capture_output=True,
                          timeout=timeout)


def replace_once(text, old, new):
    if text.count(old) != 1:
        raise ValueError('mutation site not unique: ' + old[:90])
    return text.replace(old, new, 1)


def swap_ik_and_transform(text):
    """Exchange the two adjacent, mutually independent stages 0x28bdd8 (ik)
    and 0x28bff8 (transform) in the assembled loader.  Both stages would still
    succeed on their own, so only an observable ORDER assertion can refuse the
    mutant."""
    ik_head = '    /* 0x28bdd8..0x28bff8'
    path_head = '    /* 0x28c274..0x28c5ec'
    tr_head = '    /* 0x28bff8..0x28c274'
    a = text.index(ik_head)
    b = text.index(path_head)
    mid = text[a:b]
    cut = mid.index(tr_head)
    return text[:a] + mid[cut:] + mid[:cut] + text[b:]


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
    print('BINDING v1 entry=skeleton-chain run=' + name
          + ' original_sha256=' + PIN + ' fixture_sha256=' + sha(FIX)
          + ' binary_sha256=' + before, flush=True)
    p = run(['qemu-arm', binary], 60)
    (out / (name + '.log')).write_text(p.stdout + p.stderr)
    if sha(binary) != before:
        raise RuntimeError('executed binary drift')
    return {**result, 'exit_code': p.returncode, 'stdout': p.stdout,
            'stderr': p.stderr,
            'passes': re.findall(r'^PASS (.+)$', p.stdout, re.M),
            'failures': re.findall(r'^FAIL (.+)$', p.stdout, re.M)}


def mutations():
    """Injected defects, by class.  Each mutant must be refused by the exact
    named runtime assertion quoted last; every edit stays compilable under
    -Werror, so a refusal is always a RUNTIME verdict, never a build error.

      segment_order      an exchanged stage pair, refused by the observable
                         side-effect order (per-stage array allocation line and
                         the synthetic creator call sequence)
      handoff_mismatch   a wrong inter-stage handoff argument (off-by-one slot
                         index, name/path exchanged), refused by a named value
      broken_segment     one semantic constant changed INSIDE a segment module;
                         the failure line names that segment
      assembly_*         defects of the assembly layer itself (error tail, root
                         lifetime, dropped stage, literal, cached state,
                         double emission)
    """
    return [
        # ---------------- segment_order ----------------
        ('order_ik_transform_exchanged', BODY, swap_ik_and_transform,
         'chain_full_end_to_end: stage order: ik must precede transform',
         'segment_order'),
        ('order_postpass_before_skins', BODY, [
            ('    /* 0x28c5ec..0x28ccb8 — skins -> slots -> attachments. */\n'
             '    if (chain_skins_stage(self, tree, sd) == 0)\n'
             '        return 0;                              /* tail already disposed + reported */\n'
             '\n'
             '    /* 0x28ccb8..0x28d19c — linkedmesh postpass (owns both of its tails). */\n'
             '    if (readSkeletonData_resolveLinkedMeshes(self, sd) == 0)\n'
             '        return 0;',
             '    /* MUTATED: postpass exchanged with the skins window */\n'
             '    if (readSkeletonData_resolveLinkedMeshes(self, sd) == 0)\n'
             '        return 0;\n'
             '    if (chain_skins_stage(self, tree, sd) == 0)\n'
             '        return 0;'),
        ], 'chain_error_linked_skin_leak: linked-skin: the postpass returns NULL',
           'segment_order'),
        # ---------------- handoff_mismatch ----------------
        ('handoff_slot_index_off_by_one', BODY, [
            ('            ctx.slotIndex = (uint32_t)spSkeletonData_findSlotIndex(\n'
             '                (spSkeletonData*)data_raw, slotMap->name);',
             '            ctx.slotIndex = (uint32_t)(spSkeletonData_findSlotIndex(\n'
             '                (spSkeletonData*)data_raw, slotMap->name) + 1);  /* MUTATED */'),
        ], 'chain_full_end_to_end: skins: the mesh attachment is the newest entry',
           'handoff_mismatch'),
        ('handoff_name_path_exchanged', BODY, [
            ('        return readSkeletonData_skinsCreateRegionAttachment(\n'
             '            ctx->json, ctx->skin, name, path, attachmentMap, ctx->slotIndex,\n'
             '            ctx->root, ctx->data_raw);',
             '        return readSkeletonData_skinsCreateRegionAttachment(\n'
             '            ctx->json, ctx->skin, path, name, attachmentMap, ctx->slotIndex,\n'
             '            ctx->root, ctx->data_raw);          /* MUTATED: name/path swapped */'),
        ], 'chain_full_end_to_end: skins: the region attachment is the older entry',
           'handoff_mismatch'),
        # ---------------- broken_segment (one constant per module) ----------------
        ('broken_segment_bones_scaleX_slot',
         C / 'spine_read_bones/src/spine_read_bones.c', [
            ('#define BD_SCALEX_OFF        0x1c',
             '#define BD_SCALEX_OFF        0x20     /* MUTATED: +0x1c -> +0x20 */'),
        ], 'chain_segment_attribution: segment spine_read_bones: scaled length '
           'and the +0x1c scaleX slot', 'broken_segment'),
        ('broken_segment_slots_blend_word',
         C / 'spine_read_slots/src/spine_read_slots.c', [
            ('            *(int*)((char*)slotData + 0x20) = 1;   /* 0x28bd1c/20 */',
             '            *(int*)((char*)slotData + 0x20) = 2;   /* MUTATED */'),
        ], 'chain_segment_attribution: segment spine_read_slots: additive stores '
           'blend 1 and color r', 'broken_segment'),
        ('broken_segment_ik_bend_offset',
         C / 'spine_read_ik/src/spine_read_ik.c', [
            ('#define IKC_BENDDIR_OFF    0x10',
             '#define IKC_BENDDIR_OFF    0x14     /* MUTATED */'),
        ], 'chain_segment_attribution: segment spine_read_ik: bendPositive 0 '
           'stores -1 at +0x10', 'broken_segment'),
        # ---------------- assembly_error_tail ----------------
        ('ik_tail_without_report', BODY, [
            ('                return chain_fail(self, tree, sd, "IK bone not found: ", name);',
             '                spSkeletonData_dispose(sd);\n'
             '                return 0;                      /* MUTATED: no setError */'),
        ], 'chain_error_ik_bone: ik-bone: one report with the exact literal',
           'assembly_error_tail'),
        ('unknown_attachment_skipped', BODY, [
            ('        spSkeletonData_dispose((spSkeletonData*)ctx->data_raw);\n'
             '        _spSkeletonJson_setError(ctx->json, ctx->root,\n'
             '                                 "Unknown attachment type: ", type);\n'
             '        return SKINS_GLUE_ERROR;',
             '        return SKINS_GLUE_SKIPPED;             /* MUTATED */'),
        ], 'chain_error_unknown_attachment: unknown-att: the loader returns NULL',
           'assembly_error_tail'),
        # ---------------- assembly_root_lifetime ----------------
        ('root_double_dispose', BODY, [
            ('    if (chain_skins_stage(self, tree, sd) == 0)\n'
             '        return 0;                              /* tail already disposed + reported */',
             '    if (chain_skins_stage(self, tree, sd) == 0) {\n'
             '        Json_dispose(tree);                    /* MUTATED: second release */\n'
             '        return 0;\n'
             '    }'),
        ], 'chain_error_unknown_attachment: unknown-att: setError disposes the root once',
           'assembly_root_lifetime'),
        ('root_release_dropped', BODY, [
            ('    Json_dispose(tree);\n'
             '    return sd;',
             '    return sd;                                 /* MUTATED: B18 dispose dropped */'),
        ], 'chain_full_end_to_end: B18: the root tree is disposed exactly once',
           'assembly_root_lifetime'),
        ('b18_returns_null', BODY, [
            ('    Json_dispose(tree);\n'
             '    return sd;',
             '    Json_dispose(tree);\n'
             '    return 0;                                  /* MUTATED: B18 result dropped */'),
        ], 'chain_segment_attribution: segment attribution: the assembled chain '
           'returns data', 'assembly_root_lifetime'),
        # ---------------- assembly_stage_drop ----------------
        ('transform_stage_dropped', BODY, [
            ('        if (readSkeletonData_transformSection(tree, sd, chain_scale(self),\n'
             '                                              &which, &name) == 0) {',
             '        if (0) {                               /* MUTATED: transform stage gone */'),
        ], 'chain_segment_attribution: segment spine_read_transform: scaleMix at +0x18',
           'assembly_stage_drop'),
        # ---------------- assembly_literal ----------------
        ('adapter_message_typo', BODY, [
            ('"IK bone not found: "', '"IK bone not found"                  /* MUTATED */'),
        ], 'chain_error_ik_bone: ik-bone: one report with the exact literal',
           'assembly_literal'),
        # ---------------- assembly_state ----------------
        ('scale_cached_across_calls', BODY, [
            ('static float chain_scale(const spSkeletonJson* json)\n{',
             'static float chain_scale_once;                /* MUTATED */\n'
             'static float chain_scale(const spSkeletonJson* json)\n{'),
            ('    return value;\n}',
             '    if (chain_scale_once == 0.0f) chain_scale_once = value;\n'
             '    return chain_scale_once;                   /* MUTATED: cached */\n}'),
        ], 'chain_scale_read_per_call: scale: the second run re-reads json->scale '
           '(no cached scale)', 'assembly_state'),
        # ---------------- assembly_only_once ----------------
        ('meta_double_emit', BODY, [
            ('    readSkeletonData_metadata(tree, sd);',
             '    readSkeletonData_metadata(tree, sd);\n'
             '    readSkeletonData_metadata(tree, sd);   /* MUTATED: twice */'),
        ], 'chain_full_end_to_end: meta: each MALLOC_STR runs once (lines 607/608)',
           'assembly_only_once'),
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
    report = {'schema': 'cally-skeleton-chain-check/1',
              'tier': 'test_anchored', 'original_executed': False,
              # Axis 4 (equivalence with the original) is NOT measured here and
              # must not be inferred from any fixture-green result.
              'equivalence_axis_4': {
                  'status': 'not_measured',
                  'note': ('No equivalence measurement against the original. Green fixture '
                           'runs are composition-level evidence about the reconstructed C '
                           'only; the original libyoyo bytes were never executed.')},
              'entry': ('spSkeletonJson_readSkeletonData 0x28b84c..0x28e7b0: entry, meta, '
                        'bones, slots, ik, transform, path, skins(+dispatch/glue/parsers), '
                        'linkedmesh postpass, events+animations, B18, shared epilogue'),
              'scope': ('Reconstructed C only. Real links to all sixteen segment/glue modules, '
                        'the nine timeline families and their real dependencies (Json_*, '
                        'toColor, readCurve, setError/ReportSpineError/Json_dispose, '
                        'spSkeletonData_create/dispose and every record disposer, '
                        'findBone/findSlotIndex/findSkin, spSkin_*, spAttachmentLoader_*, '
                        'the five attachment constructors, region offset / mesh UV bodies, '
                        '_readVertices, _malloc/_calloc/_free). Errors the segment modules '
                        'report as codes are closed here with dispose->setError->NULL; the '
                        'out-of-window 0x28e7f4 unknown-attachment tail is closed here too. '
                        'Synthetic boundaries: Json_create/Json_getError, the four local '
                        'record creators, spSkeletonData_findSlot (0x28b070), the animation '
                        'and timeline creators/setters, the four synthetic find* scans, the '
                        'attachment loader record, the fixture heap and libc. The root slot '
                        '[sp,#0x24] is carried by readSkeletonData_rootSlot because the entry '
                        'module cannot return it. Not an original-equivalence claim.'),
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
            for name, subject, edits, expect, klass in mutations():
                text = subject.read_text()
                if callable(edits):
                    text = edits(text)
                else:
                    for old, new in edits:
                        text = replace_once(text, old, new)
                candidate = ns.out / (name + '.c')
                candidate.write_text(text)
                r = build(ns.out, name, overrides={subject: candidate})
                caught = (r.get('compile_rc') == 0 and r.get('exit_code') == 1
                          and expect in r.get('failures', []))
                report['teeth'].append({'name': name, 'class': klass,
                                        'expected_failure': expect,
                                        'caught_by_named_assertion': caught, **r})
                if not caught:
                    raise RuntimeError(
                        f'mutant not rejected by its named assertion: {name}: '
                        f'failures={r.get("failures")} diag={r.get("diagnostic", "")[:2000]}')
                print('TEETH', klass, name, r['failures'], flush=True)
            report['negative_controls'] = {
                'segment_order': [t['name'] for t in report['teeth']
                                  if t['class'] == 'segment_order'],
                'handoff_mismatch': [t['name'] for t in report['teeth']
                                     if t['class'] == 'handoff_mismatch'],
                'broken_segment': [t['name'] for t in report['teeth']
                                   if t['class'] == 'broken_segment'],
                'assembly_layer': [t['name'] for t in report['teeth']
                                   if t['class'].startswith('assembly_')],
                'all_caught_by_named_assertion': all(
                    t['caught_by_named_assertion'] for t in report['teeth'])}
            guards = [
                ('missing-chain-body', BODY,
                 ['spSkeletonJson_readSkeletonData']),
                ('missing-bones', C / 'spine_read_bones/src/spine_read_bones.c',
                 ['readSkeletonData_boneLoop']),
                ('missing-slots', C / 'spine_read_slots/src/spine_read_slots.c',
                 ['readSkeletonData_slotsSegment']),
                ('missing-skins-glue', C / 'spine_skins_glue/src/spine_skins_glue.c',
                 ['readSkeletonData_skinsCreateRegionAttachment',
                  'readSkeletonData_skinsAttachmentLevel']),
                ('missing-linked-postpass',
                 C / 'spine_linked_postpass/src/spine_linked_postpass.c',
                 ['readSkeletonData_resolveLinkedMeshes']),
                ('missing-animations-loop',
                 C / 'spine_animations_loop/src/spine_animations_loop.c',
                 ['readSkeletonData_animationsLoop']),
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
