#!/usr/bin/env python3
"""Level A function-level differential: original readSkeletonData vs the
reconstructed chain on one synthetic Json tree.

  original arm : Unicorn memory oracle, original bytes @0x28b84c
  rebuild arm  : c/spine_read_skeleton/ assembled chain under qemu-arm

Contract: reconstruction/contracts/native-equivalence-gate.md, Level A.
Evidence layer: synthetic memory oracle.  The input domain is exactly the
frozen tree set of this contract; this is neither full-input-domain nor device
equivalence.

Usage:
  python3 level_a_diff.py --run [--out DIR]
  python3 level_a_diff.py --oracle-dump --variant main --scale 2.0
"""
import argparse
import hashlib
import json
import os
import pathlib
import re
import struct
import subprocess
import sys
import time

HERE = pathlib.Path(__file__).resolve().parent
MOD = HERE.parent                      # c/spine_level_a
C = MOD.parent                         # c
RV1 = C.parent                         # reconstruction/reverse-v1
sys.path.insert(0, str(HERE))
sys.path.insert(0, str(C / 'spine_read_skeleton' / 'tools'))

import level_a_model as model          # noqa: E402
import level_a_trees as trees          # noqa: E402
import level_a_dump as dump            # noqa: E402
import check_skeleton as chain_check   # noqa: E402  (build recipe + FLAGS)

PIN = '3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a'
SO = pathlib.Path('/data/data/com.termux/files/home/callys-caves-2-rs/'
                  'reconstruction/live-mem/libyoyo_armv7.so')
RECEIPTS = RV1 / 'harness' / 'receipts'
BUILD = MOD / 'build'


def sha_file(path):
    return hashlib.sha256(pathlib.Path(path).read_bytes()).hexdigest()


# ----------------------------------------------------------------------
# field flattening + attribution
# ----------------------------------------------------------------------
FLOAT_KEYS = {'width', 'height', 'length', 'x', 'y', 'rotation', 'scaleX',
              'scaleY', 'shearX', 'shearY', 'mix', 'rotateMix',
              'translateMix', 'scaleMix', 'shearMix', 'r', 'g', 'b', 'a',
              'u', 'v', 'u2', 'v2', 'duration', 'position', 'spacing',
              'floatValue', 'time'}

META_POINTER_WORDS = {5: 'bones', 7: 'slots', 9: 'skins', 10: 'defaultSkin',
                      12: 'events', 14: 'animations', 16: 'ik',
                      18: 'transform', 20: 'path'}

SHARED_DURATION = ['spine_read_tl_slots', 'spine_read_tl_bones',
                   'spine_read_tl_ik', 'spine_read_tl_transform',
                   'spine_read_tl_path', 'spine_read_tl_path_mix',
                   'spine_read_tl_deform', 'spine_read_tl_draworder',
                   'spine_read_tl_event']

# Timeline type word -> the family module that builds it (see
# c/spine_read_*_tl_*/src for the type constants each creator writes).
TL_SEG = {0: 'spine_read_tl_bones', 1: 'spine_read_tl_bones',
          2: 'spine_read_tl_bones', 3: 'spine_read_tl_bones',
          4: 'spine_read_tl_slots', 5: 'spine_read_tl_slots',
          6: 'spine_read_tl_event', 7: 'spine_read_tl_draworder',
          8: 'spine_read_tl_deform', 9: 'spine_read_tl_ik',
          10: 'spine_read_tl_transform', 11: 'spine_read_tl_path',
          12: 'spine_read_tl_path', 13: 'spine_read_tl_path_mix'}

# ----------------------------------------------------------------------
# Gate matrix definitions
# ----------------------------------------------------------------------
# B class: every error tree in level_a_trees.VARIANTS.  Each gate requires the
# two arms to return NULL, to report the same parser->error text, to agree on
# every compared field (which includes error.root_dispose) and to stage the
# same tree on both arms.
B_ERROR_TREES = [
    'err_slot_bone', 'err_ik_bone', 'err_parent', 'err_tr_bone',
    'err_path_constraint', 'err_path_bone', 'err_ik_target', 'err_tr_target',
    'err_path_target', 'err_draworder_slot', 'err_bone_tl',
    'err_tl_slot_invalid', 'err_tl_bone_invalid', 'err_event',
    'err_deform_att', 'err_link_skin', 'err_link_parent', 'err_att_unknown',
    'err_json',
]
# The two linked-mesh tails dispose spSkeletonData but not the Json root: the
# original leaks the root, so both arms must report root_dispose == 0.
B_LEAK_TREES = {'err_link_skin', 'err_link_parent'}

# A class: one breakage site per chain module (16 segment/glue modules, the 9
# timeline families, curve and color).  Each mutation is a source-copy
# override, never an edit of the module source.  The first three are the
# contract's original broken-segment control and keep their names.
# Mutants whose module body is only reachable through a tree other than `main`.
# tl_path_mix lives behind B17, and B17 skips the sub-key named exactly "mix";
# the contract therefore needs the `path_mix_alt` tree for it to be testable.
A_MUTANT_VARIANT = {'tl_path_mix_rotate_key': 'path_mix_alt'}

A_MODULE_MUTANTS = [
    # --- NC1 continuity: the three contract mutants -------------------
    ('spine_read_slots', 'spine_read_slots/src/spine_read_slots.c',
     '*(int*)((char*)slotData + 0x20) = 1;',
     '*(int*)((char*)slotData + 0x20) = 3;',
     'slots_blend_additive_1_to_3'),
    ('spine_read_bones', 'spine_read_bones/src/spine_read_bones.c',
     '#define BD_SCALEX_OFF        0x1c',
     '#define BD_SCALEX_OFF        0x20',
     'bones_scaleX_offset_0x1c_to_0x20'),
    ('spine_read_tl_bones', 'spine_read_tl_bones/src/spine_read_tl_bones.c',
     'Json_getFloat(frame, "angle", 0.0f)',
     'Json_getFloat(frame, "angel", 0.0f)',
     'tl_bones_rotate_angle_key'),
    # --- the other 24 modules ---------------------------------------
    ('spine_read_meta', 'spine_read_meta/src/spine_read_meta.c',
     '#define SD_WIDTH_OFF   0x08', '#define SD_WIDTH_OFF   0x0c',
     'meta_sd_width_off_0x08_to_0x0c'),
    ('spine_read_ik', 'spine_read_ik/src/spine_read_ik.c',
     'Json_getInt(map, "bendPositive", 1)',
     'Json_getInt(map, "bendPositiveZ", 1)',
     'ik_bend_positive_key'),
    ('spine_read_transform', 'spine_read_transform/src/spine_read_transform.c',
     'Json_getFloat(map, "rotateMix", 1.0f)',
     'Json_getFloat(map, "rotateMixX", 1.0f)',
     'transform_rotate_mix_key'),
    ('spine_read_path', 'spine_read_path/src/spine_read_path.c',
     'Json_getString(map, "positionMode", "percent")',
     'Json_getString(map, "positionModeZ", "percent")',
     'path_position_mode_key'),
    ('spine_read_skins', 'spine_read_skins/src/spine_read_skins.c',
     '_strcmp(name, "default")', '_strcmp(name, "defaultX")',
     'skins_default_skin_compare'),
    ('spine_read_attach_dispatch',
     'spine_read_attach_dispatch/src/spine_read_attach_dispatch.c',
     'Json_getString(attachmentMap, "path", name)',
     'Json_getString(attachmentMap, "pathX", name)',
     'attach_dispatch_path_key'),
    ('spine_read_region', 'spine_read_region/src/spine_read_region.c',
     'Json_getFloat(map,"width",32.0f)',
     'Json_getFloat(map,"widht",32.0f)',
     'region_width_key'),
    ('spine_read_bbox_path', 'spine_read_bbox_path/src/spine_read_bbox_path.c',
     'Json_getInt(map, "closed", 0)',
     'Json_getInt(map, "closedX", 0)',
     'bbox_path_closed_key'),
    ('spine_read_mesh', 'spine_read_mesh/src/spine_read_mesh.c',
     'Json_getInt(map,"hull",0)', 'Json_getInt(map,"hul",0)',
     'mesh_hull_key'),
    ('spine_read_vertices', 'spine_read_vertices/src/spine_read_vertices.c',
     'a->worldVerticesLength = verticesCount;',
     'a->worldVerticesLength = verticesCount >> 1;',
     'vertices_world_length_halved'),
    ('spine_skins_glue', 'spine_skins_glue/src/spine_skins_glue.c',
     'case SKINS_GLUE_TYPE_REGION:',
     'case SKINS_GLUE_TYPE_REGION + 100:',
     'skins_glue_region_type_stub'),
    ('spine_linked_postpass', 'spine_linked_postpass/src/spine_linked_postpass.c',
     'if(signed32(j->unk_10)<=0)return 1;',
     'if(1)return 1;',
     'linked_postpass_early_out'),
    ('spine_read_animations', 'spine_read_animations/src/spine_read_animations.c',
     'Json_getInt(eventMap, "int", 0)',
     'Json_getInt(eventMap, "intValue", 0)',
     'animations_event_int_key'),
    ('spine_animations_loop',
     'spine_animations_loop/src/spine_animations_loop.c',
     '    if (readSkeletonData_boneTimelines(frame->bones, frame->animation, data_raw,\n'
     '                                       animation, parser_raw) == 0)\n'
     '        return 0;\n'
     '\n'
     '    /* B7 ik, 0x28d840..0x28dca8 (no error path in the family). */\n'
     '    if (readSkeletonData_ikTimelines(frame->ik, data_raw, animation) == 0)\n'
     '        return 0;',
     '    /* B7 ik, 0x28d840..0x28dca8 (no error path in the family). */\n'
     '    if (readSkeletonData_ikTimelines(frame->ik, data_raw, animation) == 0)\n'
     '        return 0;\n'
     '\n'
     '    if (readSkeletonData_boneTimelines(frame->bones, frame->animation, data_raw,\n'
     '                                       animation, parser_raw) == 0)\n'
     '        return 0;',
     'animations_loop_stage_order_ik_before_bones'),
    ('spine_read_tl_slots', 'spine_read_tl_slots/src/spine_read_tl_slots.c',
     'uint32_t word_index = (declared - 1u) * 5u;',
     'uint32_t word_index = (declared - 1u) * 4u;',
     'tl_slots_color_word_stride'),
    ('spine_read_tl_ik', 'spine_read_tl_ik/src/spine_read_tl_ik.c',
     'int bend_enum = (bend == 0) ? -1 : 1;',
     'int bend_enum = (bend == 0) ? 1 : -1;',
     'tl_ik_bend_enum_flip'),
    ('spine_read_tl_transform',
     'spine_read_tl_transform/src/spine_read_tl_transform.c',
     '                                                   time, rotateMix,\n'
     '                                                   translateMix, scaleMix,',
     '                                                   time, translateMix,\n'
     '                                                   rotateMix, scaleMix,',
     'tl_transform_mix_argument_order'),
    ('spine_read_tl_path', 'spine_read_tl_path/src/spine_read_tl_path.c',
     'float value = Json_getFloat(frame, timelineNode->name, 0.0f);',
     'float value = Json_getFloat(frame, "spacing", 0.0f);',
     'tl_path_value_key_fixed_spacing'),
    ('spine_read_tl_path_mix', 'spine_read_tl_path_mix/src/spine_read_tl_path_mix.c',
     'float rotateMix = Json_getFloat(frame, "rotateMix", 1.0f);',
     'float rotateMix = Json_getFloat(frame, "rotateMixX", 1.0f);',
     'tl_path_mix_rotate_key'),
    ('spine_read_tl_deform', 'spine_read_tl_deform/src/spine_read_tl_deform.c',
     'float time = Json_getFloat(frame, "time", 0.0f);',
     'float time = Json_getFloat(frame, "tim", 0.0f);',
     'tl_deform_frame_time_key'),
    ('spine_read_tl_draworder', 'spine_read_tl_draworder/src/spine_read_tl_draworder.c',
     'order[k] = -1;', 'order[k] = -2;',
     'tl_draworder_fill_value'),
    ('spine_read_tl_event', 'spine_read_tl_event/src/spine_read_tl_event.c',
     'event->intValue = Json_getInt(frame, "int", event_data->intValue);',
     'event->intValue = Json_getInt(frame, "int", 0);',
     'tl_event_int_default'),
    ('spine_read_curve', 'spine_read_curve/src/spine_read_curve.c',
     'Json* curve = Json_getItem(frame, "curve");',
     'Json* curve = Json_getItem(frame, "curves");',
     'curve_key'),
    ('spine_color', 'spine_color/src/spine_color.c',
     '"t"(converted), "t"(255.0f)',
     '"t"(converted), "t"(256.0f)',
     'color_hex_divisor_255_to_256'),
]

# C class: perturbation trees compared against the main baseline.
C_PERTURBATIONS = ['perturb', 'perturb_slot', 'perturb_curve']


ATTRIBUTION = [
    ('meta.spine', ['spine_read_meta']),
    ('meta.hash', ['spine_read_meta']),
    ('meta.width', ['spine_read_meta']),
    ('meta.height', ['spine_read_meta']),
    ('meta.bonesCount', ['spine_read_bones']),
    ('meta.slotsCount', ['spine_read_slots']),
    ('meta.skinsCount', ['spine_read_skins']),
    ('meta.eventsCount', ['spine_read_animations']),
    ('meta.animationsCount', ['spine_animations_loop']),
    ('meta.ikCount', ['spine_read_ik']),
    ('meta.transformCount', ['spine_read_transform']),
    ('meta.pathCount', ['spine_read_path']),
    ('meta.defaultSkinIndex', ['spine_read_skins']),
    ('meta.word05_', ['spine_read_meta']),
    ('meta.word07_', ['spine_read_slots']),
    ('meta.word09_', ['spine_read_skins']),
    ('meta.word10_', ['spine_read_skins']),
    ('meta.word12_', ['spine_read_animations']),
    ('meta.word14_', ['spine_animations_loop']),
    ('meta.word16_', ['spine_read_ik']),
    ('meta.word18_', ['spine_read_transform']),
    ('meta.word20_', ['spine_read_path']),
    ('bones[', ['spine_read_bones']),
    ('slots[', ['spine_read_slots']),
    ('ik[', ['spine_read_ik']),
    ('transform[', ['spine_read_transform']),
    ('path[', ['spine_read_path']),
    ('skins[', ['spine_read_skins', 'spine_read_attach_dispatch',
                'spine_skins_glue', 'spine_read_region', 'spine_read_mesh',
                'spine_read_bbox_path', 'spine_read_vertices']),
    ('events[', ['spine_read_animations']),
    ('animations[].name', ['spine_animations_loop']),
    ('animations[].duration', SHARED_DURATION),
    ('animations[].timelineCount', ['spine_read_animations',
                                    'spine_animations_loop']),
    ('animations[].timelines[].curves', ['spine_read_curve']),
    ('animations[].timelines[].frames', ['spine_read_tl_bones',
                                         'spine_read_tl_event']),
    ('animations[].timelines[].names', ['spine_read_tl_slots']),
    ('animations[].timelines[].type', ['spine_animations_loop']),
    ('animations[].timelines[].frameCount', ['spine_read_tl_bones']),
    ('animations[].timelines[].frameFloatCount', ['spine_read_tl_bones']),
    ('animations[].timelines[].index', ['spine_read_tl_bones']),
    ('error.', ['spine_read_entry', 'spine_read_skeleton',
                'spine_json_error']),
]


def attribution(field):
    norm = re.sub(r'\[\d+\]', '[]', field)
    for prefix, segs in ATTRIBUTION:
        if norm.startswith(prefix) or field.startswith(prefix):
            if norm.startswith('animations[].timelines[].frames'):
                if re.search(r'\.(time|intValue|floatValue|stringValue)$', field):
                    return ['spine_read_tl_event']
                return ['spine_read_tl_bones']
            return list(segs)
    return ['unattributed']


def _float_keys_in(prefix):
    return any(prefix.endswith(k) for k in FLOAT_KEYS) or \
        re.search(r'\.(x|y|rotation|scaleX|scaleY|shearX|shearY|mix|'
                  r'rotateMix|translateMix|scaleMix|shearMix|r|g|b|a|u|v|u2|v2)'
                  r'(_bits)?$', prefix) is not None


def flatten(d):
    """Flatten one arm's dump into {field: value}; ATTR[field] gets segments.

    Attribution is assigned where the field is emitted, so a timeline's frames
    are attributed to the family that OWNS that timeline type instead of to the
    generic "frames" prefix.  Module-scoped lists are the ones the field name
    alone cannot disambiguate (multi-segment co-write, contract §负控 1).
    """
    out = {}
    attrs = {}

    def put(key, val, segs):
        out[key] = val
        attrs[key] = list(segs)

    meta_segs = ['spine_read_meta', 'spine_read_entry']
    skin_segs = ['spine_read_skins', 'spine_read_attach_dispatch',
                 'spine_skins_glue', 'spine_read_region', 'spine_read_mesh',
                 'spine_read_bbox_path', 'spine_read_vertices',
                 'spine_linked_postpass']
    color_segs = skin_segs + ['spine_color']

    if d.get('meta'):
        m = d['meta']
        put('meta.spine', m['spine'], meta_segs)
        put('meta.hash', m['hash'], meta_segs)
        put('meta.width', m['words'][2], meta_segs)
        put('meta.height', m['words'][3], meta_segs)
        names = {4: ('bonesCount', 'spine_read_bones'),
                 6: ('slotsCount', 'spine_read_slots'),
                 8: ('skinsCount', 'spine_read_skins'),
                 11: ('eventsCount', 'spine_read_animations'),
                 13: ('animationsCount', 'spine_animations_loop'),
                 15: ('ikCount', 'spine_read_ik'),
                 17: ('transformCount', 'spine_read_transform'),
                 19: ('pathCount', 'spine_read_path')}
        for idx, (name, seg) in names.items():
            put('meta.' + name, m['words'][idx], [seg, 'spine_read_entry'])
        for idx, name in META_POINTER_WORDS.items():
            seg = {5: 'spine_read_bones', 7: 'spine_read_slots',
                   9: 'spine_read_skins', 10: 'spine_read_skins',
                   12: 'spine_read_animations', 14: 'spine_animations_loop',
                   16: 'spine_read_ik', 18: 'spine_read_transform',
                   20: 'spine_read_path'}[idx]
            put('meta.word%02d_%s_nonnull' % (idx, name),
                1 if m['words'][idx] else 0, [seg, 'spine_read_entry'])
        put('meta.defaultSkinIndex', d.get('defaultSkinIndex', -1),
            ['spine_read_skins', 'spine_read_entry'])
    for n, b in enumerate(d.get('bones', [])):
        p = 'bones[%d].' % n
        seg = ['spine_read_bones']
        put(p + 'name', b['name'], seg)
        put(p + 'parent', b['parent'], seg)
        put(p + 'index', b['index'], seg)
        for k in ('length', 'x', 'y', 'rotation', 'scaleX', 'scaleY',
                  'shearX', 'shearY'):
            put(p + k, b[k], seg)
        put(p + 'inheritRotation', b['inheritRotation'], seg)
        put(p + 'inheritScale', b['inheritScale'], seg)
    for n, sl in enumerate(d.get('slots', [])):
        p = 'slots[%d].' % n
        put(p + 'name', sl['name'], ['spine_read_slots'])
        put(p + 'bone', sl['bone'], ['spine_read_slots'])
        put(p + 'attachment', sl['attachment'], ['spine_read_slots'])
        for k in ('r', 'g', 'b', 'a'):
            put(p + k, sl[k], ['spine_read_slots', 'spine_color'])
        put(p + 'blend', sl['blend'], ['spine_read_slots'])
    for n, c in enumerate(d.get('ik', [])):
        p = 'ik[%d].' % n
        seg = ['spine_read_ik']
        put(p + 'name', c['name'], seg)
        put(p + 'boneCount', c['boneCount'], seg)
        for j, v in enumerate(c['bones']):
            put(p + 'bones[%d]' % j, v, seg)
        put(p + 'target', c['target'], seg)
        put(p + 'bendDirection', c['bendDirection'], seg)
        put(p + 'mix', c['mix'], seg)
    for n, c in enumerate(d.get('transform', [])):
        p = 'transform[%d].' % n
        seg = ['spine_read_transform']
        put(p + 'name', c['name'], seg)
        put(p + 'boneCount', c['boneCount'], seg)
        for j, v in enumerate(c['bones']):
            put(p + 'bones[%d]' % j, v, seg)
        put(p + 'target', c['target'], seg)
        for k in ('rotateMix', 'translateMix', 'scaleMix', 'shearMix',
                  'rotation', 'x', 'y', 'scaleX', 'scaleY', 'shearY'):
            put(p + k, c[k], seg)
    for n, c in enumerate(d.get('path', [])):
        p = 'path[%d].' % n
        seg = ['spine_read_path']
        put(p + 'name', c['name'], seg)
        put(p + 'boneCount', c['boneCount'], seg)
        for j, v in enumerate(c['bones']):
            put(p + 'bones[%d]' % j, v, seg)
        put(p + 'target', c['target'], seg)
        for k in ('positionMode', 'spacingMode', 'rotateMode', 'rotation',
                  'position', 'spacing', 'rotateMix', 'translateMix'):
            put(p + k, c[k], seg)
    for n, sk in enumerate(d.get('skins', [])):
        p = 'skins[%d].' % n
        put(p + 'name', sk['name'], ['spine_read_skins'])
        put(p + 'entryCount', len(sk['entries']),
            ['spine_read_skins', 'spine_skins_glue'])
        for j, e in enumerate(sk['entries']):
            q = p + 'entries[%d].' % j
            put(q + 'slot', e['slot'],
                ['spine_read_skins', 'spine_skins_glue'])
            put(q + 'name', e['name'],
                ['spine_read_skins', 'spine_read_attach_dispatch',
                 'spine_skins_glue'])
            a = e['attachment']
            put(q + 'attachment.type', a['type'],
                ['spine_read_attach_dispatch', 'spine_skins_glue'])
            put(q + 'attachment.name', a['name'],
                ['spine_read_attach_dispatch', 'spine_skins_glue'])
            put(q + 'attachment.path', a['path'],
                ['spine_read_attach_dispatch', 'spine_skins_glue'])
            if a['type'] == 0:
                for k in ('x', 'y', 'scaleX', 'scaleY', 'rotation', 'width',
                          'height'):
                    put(q + 'attachment.' + k, a[k],
                        ['spine_read_region', 'spine_skins_glue'])
                for k in ('r', 'g', 'b', 'a'):
                    put(q + 'attachment.' + k, a[k],
                        ['spine_read_region', 'spine_color'])
                for k, v in enumerate(a['region']):
                    put(q + 'attachment.region[%d]' % k, v, skin_segs)
                for k, v in enumerate(a['offset']):
                    put(q + 'attachment.offset[%d]' % k, v,
                        ['spine_read_region'])
                for k, v in enumerate(a['uvs']):
                    put(q + 'attachment.uvs[%d]' % k, v,
                        ['spine_read_region'])
            elif a['type'] in (2, 3):
                for k in ('boneCount', 'vertexFloatCount',
                          'worldVerticesLength', 'triangleCount', 'hull'):
                    put(q + 'attachment.' + k, a[k],
                        ['spine_read_mesh', 'spine_read_vertices',
                         'spine_skins_glue'])
                for k in ('u', 'v', 'u2', 'v2'):
                    put(q + 'attachment.' + k, a[k], ['spine_read_mesh'])
                for k in ('r', 'g', 'b', 'a'):
                    put(q + 'attachment.' + k, a[k],
                        ['spine_read_mesh', 'spine_color'])
                for k, v in enumerate(a['vertices']):
                    put(q + 'attachment.vertices[%d]' % k, v,
                        ['spine_read_vertices', 'spine_read_mesh'])
                for k, v in enumerate(a['region']):
                    put(q + 'attachment.region[%d]' % k, v, skin_segs)
                for k, v in enumerate(a['triangles']):
                    put(q + 'attachment.triangles[%d]' % k, v,
                        ['spine_read_mesh'])
                put(q + 'attachment.parentMesh', a.get('parentMesh', ''),
                    ['spine_linked_postpass'])
            else:
                for k in ('boneCount', 'vertexFloatCount',
                          'worldVerticesLength'):
                    put(q + 'attachment.' + k, a[k],
                        ['spine_read_vertices', 'spine_read_bbox_path',
                         'spine_skins_glue'])
                for k, v in enumerate(a['vertices']):
                    put(q + 'attachment.vertices[%d]' % k, v,
                        ['spine_read_vertices', 'spine_read_bbox_path'])
                for k, v in enumerate(a.get('flags', [])):
                    put(q + 'attachment.flags[%d]' % k, v, skin_segs)
    for n, e in enumerate(d.get('events', [])):
        p = 'events[%d].' % n
        seg = ['spine_read_animations']
        put(p + 'name', e['name'], seg)
        put(p + 'intValue', e['intValue'], seg)
        put(p + 'floatValue', e['floatValue'], seg)
        put(p + 'stringValue', e['stringValue'], seg)
    for n, an in enumerate(d.get('animations', [])):
        p = 'animations[%d].' % n
        put(p + 'name', an['name'], ['spine_animations_loop',
                                     'spine_read_animations'])
        put(p + 'duration', an['duration'], SHARED_DURATION)
        put(p + 'timelineCount', an['timelineCount'],
            ['spine_read_animations', 'spine_animations_loop'])
        for j, t in enumerate(an['timelines']):
            q = p + 'timelines[%d].' % j
            fam = TL_SEG.get(t['type'], 'spine_animations_loop')
            put(q + 'type', t['type'],
                ['spine_animations_loop', 'spine_read_tl_slots'])
            put(q + 'frameCount', t['frameCount'], [fam, 'spine_animations_loop'])
            put(q + 'frameFloatCount', t['frameFloatCount'], [fam])
            put(q + 'index', t['index'], [fam])
            if t['type'] == 5:
                put(q + 'slotIndex', t.get('slotIndex', 0),
                    ['spine_read_tl_slots'])
                for k, v in enumerate(t.get('frames', [])):
                    put(q + 'frames[%d]' % k, v, ['spine_read_tl_slots'])
                for k, v in enumerate(t.get('names', [])):
                    put(q + 'names[%d]' % k, v, ['spine_read_tl_slots'])
            elif t['type'] == 6:
                for k, fr in enumerate(t['frames']):
                    put(q + 'frames[%d].time' % k, fr['time'],
                        ['spine_read_tl_event'])
                    put(q + 'frames[%d].intValue' % k, fr['intValue'],
                        ['spine_read_tl_event'])
                    put(q + 'frames[%d].floatValue' % k, fr['floatValue'],
                        ['spine_read_tl_event'])
                    put(q + 'frames[%d].stringValue' % k, fr['stringValue'],
                        ['spine_read_tl_event'])
            elif t['type'] == 7:
                put(q + 'slotsCount', t.get('slotsCount', 0),
                    ['spine_read_tl_draworder'])
                for k, fr in enumerate(t['frames']):
                    put(q + 'frames[%d].time' % k, fr['time'],
                        ['spine_read_tl_draworder'])
                    for m, v in enumerate(fr['order']):
                        put(q + 'frames[%d].order[%d]' % (k, m), v,
                            ['spine_read_tl_draworder'])
            elif t['type'] == 8:
                put(q + 'vertexFloatCount', t.get('vertexFloatCount', 0),
                    ['spine_read_tl_deform'])
                for k, fr in enumerate(t['frames']):
                    put(q + 'frames[%d].time' % k, fr['time'],
                        ['spine_read_tl_deform'])
                    for m, v in enumerate(fr['vertices']):
                        put(q + 'frames[%d].vertices[%d]' % (k, m), v,
                            ['spine_read_tl_deform'])
            else:
                for k, v in enumerate(t.get('frames', [])):
                    put(q + 'frames[%d]' % k, v, [fam])
                for k, v in enumerate(t.get('curves', [])):
                    put(q + 'curves[%d]' % k, v,
                        ['spine_read_curve', fam])
    if d.get('error'):
        put('error.is_null', d['error']['is_null'],
            ['spine_read_entry', 'spine_read_skeleton'])
        put('error.error', d['error']['error'],
            ['spine_read_entry', 'spine_read_skeleton', 'spine_json_error'])
        put('error.root_dispose', d['error'].get('root_dispose', 0),
            ['spine_read_entry', 'spine_read_skeleton'])
    return out, attrs


def field_float(field):
    return bool(re.search(r'\.(width|height|length|rotation|scaleX|scaleY|'
                          r'shearX|shearY|mix|rotateMix|translateMix|scaleMix|'
                          r'shearMix|r|g|b|a|u|v|u2|v2|duration|position|'
                          r'spacing|floatValue|time)$', field)) or \
        'attachment.x' in field or 'attachment.y' in field


def describe(field, value):
    if isinstance(value, str):
        return value
    if field_float(field) and isinstance(value, int):
        return {'bits': '0x%08x' % value,
                'f32': struct.unpack('<f', struct.pack('<I', value))[0]}
    return value


def diff_dicts(fa, a, fb, b):
    """Diff two flattened arms; attribution comes from the emitting side."""
    fields = sorted(set(a) | set(b))
    diffs = []
    for f in fields:
        va, vb = a.get(f, '<absent>'), b.get(f, '<absent>')
        if va != vb:
            diffs.append({
                'field': f,
                'original': describe(f, va) if va != '<absent>' else '<absent>',
                'rebuild': describe(f, vb) if vb != '<absent>' else '<absent>',
                'original_raw': va, 'rebuild_raw': vb,
                'attribution': fb.get(f) or fa.get(f) or attribution(f),
            })
    return diffs


# ----------------------------------------------------------------------
# C arm build/run
# ----------------------------------------------------------------------
def build_c(variant, scale_bits, name, overrides=None):
    BUILD.mkdir(parents=True, exist_ok=True)
    tmp = BUILD / 'tmp'
    tmp.mkdir(exist_ok=True)
    os.environ['TMPDIR'] = str(tmp)
    (BUILD / 'level_a_tree.inc').write_text(trees.emit_all())
    sources = [p for p in chain_check.SOURCES if p.name != 'check.c']
    sources.append(MOD / 'fixture' / 'level_a_dump.c')
    if overrides:
        sources = [overrides.get(p, p) for p in sources]
    includes = list(chain_check.INCLUDES) + [MOD / 'fixture', BUILD]
    flags = [f if f != '-Wl,-e,chain_start' else '-Wl,-e,level_a_start'
             for f in chain_check.FLAGS]
    variant_id = list(trees.VARIANTS).index(variant) + 1
    binary = BUILD / (name + '.arm')
    defines = ['-DLEVEL_A_VARIANT=%d' % variant_id,
               '-DLEVEL_A_SCALE_BITS=%du' % scale_bits]
    if variant in trees.JSON_FAIL:
        defines.append('-DLEVEL_A_JSON_FAIL=1')
        defines.append('-DLEVEL_A_JSON_ERROR=%s' % json.dumps(trees.JSON_ERROR))
    argv = ['clang', *flags, '-O2', *defines,
            *['-I' + str(i) for i in includes],
            *[str(s) for s in sources], '-o', str(binary)]
    p = subprocess.run(argv, capture_output=True, text=True)
    (BUILD / (name + '.build.log')).write_text(p.stdout + p.stderr)
    if p.returncode:
        raise RuntimeError('build failed (%s):\n%s' % (name, p.stderr[-6000:]))
    return binary


def run_c(binary):
    p = subprocess.run(['qemu-arm', str(binary)], capture_output=True,
                       timeout=120)
    if p.returncode != 0:
        raise RuntimeError('qemu-arm exit %d: %s' % (
            p.returncode, p.stderr.decode('latin1')[-2000:]))
    return p.stdout


# ----------------------------------------------------------------------
# original arm
# ----------------------------------------------------------------------
def run_oracle(tree, scale, json_fail=False, json_error=None):
    import level_a_oracle as oracle_mod
    o = oracle_mod.Oracle()
    ret, error = o.run(model.flatten(tree), scale=scale,
                       json_fail=json_fail, json_error=json_error)
    d = dump.read_oracle(o, ret)
    if not ret:
        d['error']['error'] = error
        d['error']['reported'] = ''
    return d, o


def oracle_dump_bytes(variant, scale):
    tree = trees.VARIANTS[variant]()
    d, _ = run_oracle(tree, scale)
    d['tree'] = d['tree'].hex()
    payload = json.dumps(d, sort_keys=True, ensure_ascii=False).encode()
    return payload


# ----------------------------------------------------------------------
# one variant run
# ----------------------------------------------------------------------
def run_variant(variant, scale, tag):
    tree = trees.VARIANTS[variant]()
    jf = variant in trees.JSON_FAIL
    orig, oracle = run_oracle(tree, scale, json_fail=jf,
                              json_error=trees.JSON_ERROR if jf else None)
    sfx = '%s_s%s' % (variant, str(scale).replace('.', 'p'))
    binary = build_c(variant, struct.unpack('<I', struct.pack('<f', scale))[0],
                     sfx)
    cblob = run_c(binary)
    reb = dump.parse_binary(cblob)

    py_blob = model.canonical(tree)
    py_hashes = dump.tree_node_hashes(py_blob)
    c_hashes = dump.tree_node_hashes(reb['tree'])
    py_tree_sha = hashlib.sha256(py_blob).hexdigest()
    c_tree_sha = hashlib.sha256(reb['tree']).hexdigest()
    node_join = hashlib.sha256('\n'.join(py_hashes).encode()).hexdigest()
    fo, fo_attr = flatten(orig)
    fr, fr_attr = flatten(reb)
    diffs = diff_dicts(fo_attr, fo, fr_attr, fr)
    return {
        'variant': variant, 'scale': scale, 'tag': tag,
        'binary_sha256': sha_file(binary),
        'original': {'returned_null': orig.get('meta') is None,
                     'error': orig.get('error', {}).get('error', ''),
                     'fields': len(fo)},
        'rebuild': {'returned_null': reb.get('meta') is None,
                    'error': reb.get('error', {}).get('error', ''),
                    'fields': len(fr)},
        'tree': {'node_count': len(py_hashes),
                 'python_sha256': py_tree_sha,
                 'c_arm_sha256': c_tree_sha,
                 'match': py_tree_sha == c_tree_sha,
                 'node_hashes_match': py_hashes == c_hashes,
                 'node_hashes_sha256': node_join,
                 'node_sha256': py_hashes},
        'diff': diffs,
        'diff_count': len(diffs),
        'diff_groups': sorted({d['field'].split('.')[0].split('[')[0]
                               for d in diffs}),
        '_fields_original': fo,
        '_fields_rebuild': fr,
    }


# ----------------------------------------------------------------------
# negative controls
# ----------------------------------------------------------------------
def mutation_source(relpath, old, new):
    src = C / relpath
    text = src.read_text()
    if text.count(old) != 1:
        raise RuntimeError('mutation site not unique in %s: %r' % (relpath, old))
    out = BUILD / ('mut_' + src.name)
    out.write_text(text.replace(old, new, 1))
    return src, out


def gate_a_modules(scale, subset=None):
    """Break one module at a time (source-copy override) and require the diff
    to be non-zero with at least one difference attributed to that module.

    A mutant may pin its own tree (A_MUTANT_VARIANT): a module whose arm is
    unreachable from `main` would otherwise produce a vacuous diff=0 - the
    mutant is only discriminating if the entry actually executes that module.
    Baselines are taken per tree, so the comparison stays same-input."""
    scale_bits = struct.unpack('<I', struct.pack('<f', scale))[0]
    base = {}

    def baseline(variant):
        if variant not in base:
            inst = trees.VARIANTS[variant]()
            orig, _ = run_oracle(inst, scale)
            base[variant] = flatten(orig)
        return base[variant]

    gates = []
    for module, rel, old, new, name in A_MODULE_MUTANTS:
        if subset is not None and name not in subset:
            continue
        variant = A_MUTANT_VARIANT.get(name, 'main')
        of_, oa = baseline(variant)
        src, mutated = mutation_source(rel, old, new)
        binary = build_c(variant, scale_bits, 'gateA_' + name,
                         overrides={src: mutated})
        reb = dump.parse_binary(run_c(binary))
        rf, ra = flatten(reb)
        diffs = diff_dicts(oa, of_, ra, rf)
        hits = [d['field'] for d in diffs if module in d['attribution']]
        passed = bool(diffs) and bool(hits)
        gates.append({
            'name': name, 'class': 'A_module', 'module': module,
            'variant': A_MUTANT_VARIANT.get(name, 'main'),
            'PASS': passed,
            'diff_count': len(diffs),
            'unique_to_module': len(hits) == len(diffs) and bool(hits),
            'attribution_hit': bool(hits),
            'diff_fields': [d['field'] for d in diffs][:12],
            'attributed_fields': hits[:12],
            'mutation': {'file': rel, 'old': old, 'new': new},
        })
    return gates


def legacy_broken_segment(gate_a):
    """Contract NC1 view over the first three A gates (same names/shape)."""
    muts = [{'name': g['name'], 'segment': g['module'],
             'diff_count': g['diff_count'],
             'fields': g['diff_fields'],
             'attributed_hit': g['attribution_hit'],
             'passed': g['PASS']} for g in gate_a]
    return {'passed': bool(muts) and all(m['passed'] for m in muts),
            'mutants': muts,
            'source': 'gate_matrix.A_module (first three entries)'}


def gate_b_error_trees(scale):
    """Every error tree: both arms NULL, same parser->error text, identical
    compared fields (error.root_dispose included), identical staged tree."""
    gates = []
    for variant in B_ERROR_TREES:
        res = run_variant(variant, scale, variant)
        fo = res['_fields_original']
        fr = res['_fields_rebuild']
        rd_o = fo.get('error.root_dispose')
        rd_r = fr.get('error.root_dispose')
        leak = variant in B_LEAK_TREES
        both_null = bool(res['original']['returned_null'] and
                         res['rebuild']['returned_null'])
        same_text = (res['original']['error'] == res['rebuild']['error'] and
                     bool(res['original']['error']))
        if leak:
            dispose_ok = (rd_o == 0 and rd_r == 0)
        else:
            dispose_ok = (isinstance(rd_o, int) and rd_o == rd_r and rd_o >= 1)
        trees_ok = bool(res['tree']['match'] and res['tree']['node_hashes_match'])
        passed = bool(both_null and same_text and res['diff_count'] == 0 and
                      dispose_ok and trees_ok)
        gates.append({
            'name': variant, 'class': 'B_error_tree', 'PASS': passed,
            'original_null': res['original']['returned_null'],
            'rebuild_null': res['rebuild']['returned_null'],
            'error_text_original': res['original']['error'],
            'error_text_rebuild': res['rebuild']['error'],
            'error_text_equal': same_text,
            'root_dispose_original': rd_o, 'root_dispose_rebuild': rd_r,
            'leak_expected': leak, 'root_dispose_ok': dispose_ok,
            'diff_count': res['diff_count'],
            'diff_fields': [d['field'] for d in res['diff']][:12],
            'tree_match': trees_ok,
            'tree_sha256': res['tree']['node_hashes_sha256'],
            'fields_compared': min(len(fo), len(fr)),
            'binary_sha256': res['binary_sha256'],
        })
    return gates


def gate_c_perturbations(scale, base_o, base_r):
    """Perturbation trees: both arms must change on the same field set."""
    scale_bits = struct.unpack('<I', struct.pack('<f', scale))[0]
    gates = []
    for variant in C_PERTURBATIONS:
        po_raw, _ = run_oracle(trees.VARIANTS[variant](), scale)
        pr_raw = dump.parse_binary(run_c(build_c(
            variant, scale_bits, 'gateC_' + variant)))
        po, _ = flatten(po_raw)
        pr, _ = flatten(pr_raw)

        def changed(a, b):
            return [f for f in sorted(set(a) | set(b))
                    if a.get(f, '<absent>') != b.get(f, '<absent>')]

        co = changed(base_o, po)
        cr = changed(base_r, pr)
        same = co == cr
        gates.append({
            'name': variant, 'class': 'C_input_perturbation', 'PASS':
                bool(co) and same,
            'sets_equal': same,
            'changed_count_original': len(co),
            'changed_count_rebuild': len(cr),
            'changed_fields_original': co,
            'changed_fields_rebuild': cr,
        })
    return gates


def negative_input_perturbation(scale, base_o=None, base_r=None):
    """NC2 view: the 'perturb' C gate in its original shape."""
    if base_o is None:
        base_o, _ = run_oracle(trees.VARIANTS['main'](), scale)
    if base_r is None:
        base_r = dump.parse_binary(run_c(build_c(
            'main', struct.unpack('<I', struct.pack('<f', scale))[0],
            'pert_base')))
    gate = gate_c_perturbations(scale, flatten(base_o)[0],
                                flatten(base_r)[0])[0]
    return {'passed': gate['PASS'],
            'original_changed_fields': gate['changed_fields_original'],
            'rebuild_changed_fields': gate['changed_fields_rebuild'],
            'sets_equal': gate['sets_equal']}


def negative_oracle_archive():
    out1 = BUILD / 'oracle_archive_a.json'
    out2 = BUILD / 'oracle_archive_b.json'
    env = dict(os.environ)
    for path in (out1, out2):
        p = subprocess.run([sys.executable, str(pathlib.Path(__file__)),
                            '--oracle-archive', str(path),
                            '--variant', 'main', '--scale', '2.0'],
                           capture_output=True, text=True, timeout=300, env=env)
        if p.returncode != 0:
            return {'passed': False, 'error': p.stderr[-2000:]}
    a = out1.read_bytes(); b = out2.read_bytes()
    return {'passed': a == b, 'sha_a': hashlib.sha256(a).hexdigest(),
            'sha_b': hashlib.sha256(b).hexdigest(), 'bytes': len(a)}


# ----------------------------------------------------------------------
def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--run', action='store_true')
    ap.add_argument('--oracle-dump', action='store_true')
    ap.add_argument('--oracle-archive')
    ap.add_argument('--variant', default='main', choices=list(trees.VARIANTS))
    ap.add_argument('--scale', type=float, default=2.0)
    ap.add_argument('--out', type=pathlib.Path)
    ap.add_argument('--stage', default='all',
                    choices=['all', 'base', 'b', 'a', 'c'],
                    help='all = 4 contract rounds + B/A/C gate matrix; '
                         'base = the 4 rounds + NC1/NC2/NC3 only; '
                         'b/a/c = one gate class only (writes under build/)')
    ns = ap.parse_args()

    if ns.oracle_archive:
        pathlib.Path(ns.oracle_archive).write_bytes(
            oracle_dump_bytes(ns.variant, ns.scale))
        return
    if ns.oracle_dump:
        sys.stdout.buffer.write(oracle_dump_bytes(ns.variant, ns.scale))
        return
    if not ns.run:
        ap.error('choose --run or --oracle-archive')

    BUILD.mkdir(parents=True, exist_ok=True)
    stamp = time.strftime('%Y%m%dT%H%M%S')
    out_dir = ns.out or BUILD
    out_dir.mkdir(parents=True, exist_ok=True)
    stage = ns.stage
    results = {}
    if stage in ('all', 'base'):
        for scale in (2.0, 1.0):
            results['main_s%s' % str(scale).replace('.', 'p')] = run_variant(
                'main', scale, 'main')
        results['err_parent_s2p0'] = run_variant('err_parent', 2.0, 'err_parent')
        results['perturb_s2p0'] = run_variant('perturb', 2.0, 'perturb')

    gates_b = gate_b_error_trees(2.0) if stage in ('all', 'b') else []
    gates_a = gate_a_modules(2.0) if stage in ('all', 'a') else []
    if stage in ('all', 'c'):
        if 'main_s2p0' not in results:
            results['main_s2p0'] = run_variant('main', 2.0, 'main')
        gates_c = gate_c_perturbations(
            2.0, results['main_s2p0']['_fields_original'],
            results['main_s2p0']['_fields_rebuild'])
    else:
        gates_c = []

    # Contract NC1/NC2/NC3 stay in their original shape; in a full run they are
    # derived from the matrix entries instead of re-running the same builds.
    if gates_a:
        nc1 = legacy_broken_segment(gates_a[:3])
    else:
        nc1 = legacy_broken_segment(gate_a_modules(
            2.0, subset={m[4] for m in A_MODULE_MUTANTS[:3]}))
    if gates_c:
        _g = next(g for g in gates_c if g['name'] == 'perturb')
        nc2 = {'passed': _g['PASS'],
               'original_changed_fields': _g['changed_fields_original'],
               'rebuild_changed_fields': _g['changed_fields_rebuild'],
               'sets_equal': _g['sets_equal']}
    else:
        nc2 = negative_input_perturbation(2.0)
    nc3 = (negative_oracle_archive() if stage in ('all', 'base')
           else {'passed': None, 'skipped': 'stage %s' % stage})

    # Per-field report: every compared field with both values, equality and
    # segment attribution.  Kept beside the receipt so the receipt stays
    # readable while the contract's "every field" table still exists.
    field_report = {}
    group_summary = {}
    for key, res in results.items():
        fo = res['_fields_original']
        fr = res['_fields_rebuild']
        rows = []
        groups = {}
        for f in sorted(set(fo) | set(fr)):
            va = fo.get(f, '<absent>')
            vb = fr.get(f, '<absent>')
            g = f.split('.')[0].split('[')[0]
            gs = groups.setdefault(g, {'fields': 0, 'diff': 0})
            gs['fields'] += 1
            if va != vb:
                gs['diff'] += 1
            rows.append({'field': f,
                         'original': describe(f, va) if va != '<absent>' else '<absent>',
                         'rebuild': describe(f, vb) if vb != '<absent>' else '<absent>',
                         'original_raw': va, 'rebuild_raw': vb,
                         'equal': va == vb,
                         'attribution': attribution(f)})
        field_report[key] = rows
        group_summary[key] = groups

    main_ok = (('main_s2p0' not in results or
                results['main_s2p0']['diff_count'] == 0) and
               ('main_s1p0' not in results or
                results['main_s1p0']['diff_count'] == 0))
    err = results.get('err_parent_s2p0')
    err_ok = True if err is None else bool(
        err['original']['returned_null'] and err['rebuild']['returned_null']
        and err['diff_count'] == 0)
    bind_ok = all(r['tree']['match'] and r['tree']['node_hashes_match']
                  for r in results.values())
    controls_ok = bool(nc1['passed'] and nc2['passed'] and
                       nc3['passed'] is not False)

    all_gates = gates_b + gates_a + gates_c
    if stage == 'all':
        gates_ok = (bool(gates_b) and bool(gates_a) and bool(gates_c) and
                    all(g['PASS'] for g in all_gates))
    elif stage == 'base':
        gates_ok = True
    else:
        gates_ok = bool(all_gates) and all(g['PASS'] for g in all_gates)

    gate_counts = {
        'total': len(all_gates),
        'passed': sum(1 for g in all_gates if g['PASS']),
        'failed': sum(1 for g in all_gates if not g['PASS']),
        'B_error_trees': {'total': len(gates_b),
                          'passed': sum(1 for g in gates_b if g['PASS'])},
        'A_module_break': {'total': len(gates_a),
                           'passed': sum(1 for g in gates_a if g['PASS'])},
        'C_input_perturbation': {'total': len(gates_c),
                                 'passed': sum(1 for g in gates_c if g['PASS'])},
    }
    gate_matrix = {
        'schema': 'cally-level-a-gate-matrix/1',
        'note': ('B: every error tree must return NULL on both arms with the '
                 'same parser->error text and the same error.root_dispose. '
                 'A: breaking one chain module in a source copy must move a '
                 'compared field attributed to that module. C: a perturbed tree '
                 'must change the same field set on both arms.'),
        'counts': gate_counts,
        'B_error_trees': gates_b,
        'A_module_break': gates_a,
        'C_input_perturbation': gates_c,
    }
    if stage == 'all':
        status = 'PASS' if (main_ok and err_ok and bind_ok and controls_ok
                            and gates_ok) else 'FAIL'
    else:
        status = 'PASS' if (main_ok and err_ok and controls_ok and gates_ok) \
            else 'FAIL'

    protocol = [{'tag': 'T_TREE', 'id': 1,
                 'payload': 'canonical tree (level_a_model.canonical grammar)'},
                {'tag': 'T_META', 'id': 2, 'payload': '21 u32 words, spine str, hash str'},
                {'tag': 'T_BONES', 'id': 3}, {'tag': 'T_SLOTS', 'id': 4},
                {'tag': 'T_IK', 'id': 5}, {'tag': 'T_TRANSFORM', 'id': 6},
                {'tag': 'T_PATH', 'id': 7}, {'tag': 'T_SKINS', 'id': 8},
                {'tag': 'T_EVENTS', 'id': 9}, {'tag': 'T_ANIMS', 'id': 10},
                {'tag': 'T_ERROR', 'id': 11}, {'tag': 'T_END', 'id': 255}]

    field_path = None
    if field_report:
        field_path = out_dir / ('level_a_field_report_%s.json' % stamp)
        field_path.write_text(json.dumps(
            {'schema': 'cally-level-a-field-report/1',
             'note': ('every compared field on both arms: original/rebuild values, '
                      'equality, segment attribution; main_s2p0 is the contract run'),
             'runs': field_report}, ensure_ascii=False, indent=1) + '\n')

    report = {
        'schema': 'cally-level-a-diff/2',
        'generated_utc': time.strftime('%Y-%m-%dT%H:%M:%SZ', time.gmtime()),
        'stage': stage,
        'tier': 'oracle_anchored',
        'original_executed': True,
        'evidence_layer': ('synthetic memory oracle: original ARM bytes executed in '
                           'Unicorn over a staged 32-byte-node Json tree and a '
                           'bump heap; NOT device execution'),
        'contract': 'reconstruction/contracts/native-equivalence-gate.md Level A',
        'BINDING': {
            'version': 'BINDING v1',
            'original_sha256': PIN,
            'original_path': str(SO),
            'fixture_sha256': sha_file(MOD / 'fixture' / 'level_a_dump.c'),
            'model_sha256': sha_file(HERE / 'level_a_model.py'),
            'oracle_sha256': sha_file(HERE / 'level_a_oracle.py'),
            'dump_sha256': sha_file(HERE / 'level_a_dump.py'),
            'driver_sha256': sha_file(HERE / 'level_a_diff.py'),
            'trees': {k: {'node_count': v['tree']['node_count'],
                          'python_sha256': v['tree']['python_sha256'],
                          'c_arm_sha256': v['tree']['c_arm_sha256'],
                          'match': v['tree']['match'],
                          'node_hashes_match': v['tree']['node_hashes_match'],
                          'node_hashes_sha256': v['tree']['node_hashes_sha256'],
                          'first_node_sha256': v['tree']['node_sha256'][0],
                          'node_sha256': v['tree']['node_sha256']}
                      for k, v in results.items()},
            'rebuild_binaries': {k: v['binary_sha256'] for k, v in results.items()},
            'chain_check_build_recipe': str(C / 'spine_read_skeleton' / 'tools' /
                                            'check_skeleton.py'),
        },
        'input_domain': {
            'trees': {
                'main': 'skeleton(meta) + 3 bones + slot(blend/color/attachment) '
                        '+ ik + transform + path + skin(region+mesh) + event + '
                        'animation(rotate 3 frames curve+stepped, translate 2 frames, '
                        'event frame)',
                'err_parent': 'main with bone arm parent=forearm (Parent bone not found)',
                'perturb': 'main with the last translate frame removed and the '
                           'animation renamed walk2',
                'err_trees': ('all 19 error trees of level_a_trees.VARIANTS '
                              '(gate matrix class B)'),
                'perturbations': C_PERTURBATIONS,
            },
            'scales': [2.0, 1.0] if 'main_s1p0' in results else [2.0],
            'note': ('This is the contract input set only; it is not the full input '
                     'domain and not device equivalence.'),
        },
        'comparable_fields': {
            'spSkeletonData': '21 words: strings/counts/floats exact; pointer words '
                              'compared as non-null presence plus their per-element '
                              'records (heap addresses differ by construction)',
            'per_element': ['bone name/parent/index/scalars/inherit flags',
                            'slot name/bone/attachment/blend/color bits',
                            'ik/transform/path names, bone lists, targets, scalars',
                            'skin name/entries; attachment type/name/path plus region '
                            'or mesh payload',
                            'event name/int/float/string',
                            'animation name/duration/timelineCount; per timeline '
                            'type/frameCount/ffc/index/frame bits/curve bits/event '
                            'frames'],
            'not_comparable': ['intermediate malloc/free sequence',
                               'creator internal layout beyond the fields above',
                               'console output text (parser->error is compared)',
                               'pointer values'],
        },
        'field_to_segment': {prefix: segs for prefix, segs in ATTRIBUTION},
        'dump_protocol': protocol,
        'gate_matrix': gate_matrix,
        'results': results,
        'field_table': {
            'schema': 'cally-level-a-field-report/1',
            'path': str(field_path) if field_path else None,
            'groups': group_summary,
            'note': ('Every field row carries original/rebuild values, equal flag '
                     'and segment attribution; main_s2p0 is the contract run.'),
        },
        'negative_controls': {
            'broken_segment': nc1,
            'input_perturbation': nc2,
            'oracle_archive_replay': nc3,
            'perturbations': gates_c,
        },
        'equivalence_axis_4': {
            'status': ('合成内存 oracle 层已测，差异 0（输入域：本合同输入集）'
                       if status == 'PASS' else '合成内存 oracle 层已测，存在差异'),
            'diff_zero': main_ok,
            'diff_fields': sorted({d['field'] for k, v in results.items()
                                   for d in v['diff']}),
            'diff_count': sum(v['diff_count'] for v in results.values()),
            'caveat': ('不是全输入域等价，不是设备等价。The original arm is a '
                       'synthetic-memory Unicorn oracle; the rebuild arm is the '
                       'reconstructed C chain under qemu-arm.'),
        },
        'status': status,
    }
    out_dir.mkdir(parents=True, exist_ok=True)
    (out_dir / ('level_a_report_%s.json' % stamp)).write_text(
        json.dumps(report, ensure_ascii=False, indent=2) + '\n')
    if stage == 'all':
        RECEIPTS.mkdir(parents=True, exist_ok=True)
        receipt = RECEIPTS / ('level_a_diff-%s.json' % stamp)
    else:
        receipt = out_dir / ('level_a_stage_%s_%s.json' % (stage, stamp))
    receipt.write_text(json.dumps(report, ensure_ascii=False, indent=2) + '\n')

    print('RESULT %s (stage=%s)' % (status, stage))
    for k, v in results.items():
        print('  %-16s diff=%d tree_match=%s orig_null=%s reb_null=%s' % (
            k, v['diff_count'], v['tree']['match'],
            v['original']['returned_null'], v['rebuild']['returned_null']))
        for d in v['diff'][:10]:
            print('    DIFF', d['field'], 'orig=', d['original'],
                  'reb=', d['rebuild'], 'seg=', d['attribution'])
    for g in gates_b:
        print('  GATE-B %-22s %s null=%s/%s text=%r dispose=%s/%s diff=%d' % (
            g['name'], 'PASS' if g['PASS'] else 'FAIL',
            g['original_null'], g['rebuild_null'], g['error_text_original'],
            g['root_dispose_original'], g['root_dispose_rebuild'],
            g['diff_count']))
    for g in gates_a:
        print('  GATE-A %-38s %s module=%-26s diff=%d hit=%d %s' % (
            g['name'], 'PASS' if g['PASS'] else 'FAIL', g['module'],
            g['diff_count'], len(g['attributed_fields']),
            g['attributed_fields'][:3]))
    for g in gates_c:
        print('  GATE-C %-22s %s changed=%d/%d sets_equal=%s' % (
            g['name'], 'PASS' if g['PASS'] else 'FAIL',
            g['changed_count_original'], g['changed_count_rebuild'],
            g['sets_equal']))
    print('  NC1 broken_segment passed=%s' % nc1['passed'])
    print('  NC2 input_perturbation passed=%s (sets_equal=%s, fields=%d)' % (
        nc2['passed'], nc2.get('sets_equal'), len(nc2.get('original_changed_fields', []))))
    print('  NC3 oracle_archive passed=%s' % nc3['passed'])
    print('  GATE-MATRIX total=%d passed=%d failed=%d (B=%d/%d A=%d/%d C=%d/%d)' % (
        gate_counts['total'], gate_counts['passed'], gate_counts['failed'],
        gate_counts['B_error_trees']['passed'], gate_counts['B_error_trees']['total'],
        gate_counts['A_module_break']['passed'], gate_counts['A_module_break']['total'],
        gate_counts['C_input_perturbation']['passed'],
        gate_counts['C_input_perturbation']['total']))
    print('  receipt=%s' % receipt)


if __name__ == '__main__':
    main()
