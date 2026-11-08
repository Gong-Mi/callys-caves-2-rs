#!/usr/bin/env python3
"""Level A tree set: one superset skeleton plus the error/perturbation deltas.

The single source of node construction stays level_a_model.py; this module only
composes trees out of it.  Every tree here is emitted twice (Unicorn memory on
the original arm, generated C on the rebuild arm) and both arms serialise it
with the same canonical grammar, so "same input" is literally the same tree.

Section coverage of `main` (one node family per chain module):
  skeleton meta, bones(parent chain), slots(blend+color+attachment),
  ik, transform, path, skins(default): region, mesh, boundingbox, path,
  linkedmesh(parent present), events, animation(walk) with bones rotate/
  translate/scale/shear, slots attachment+color, ik, transform, paths
  position/spacing/mix, deform, drawOrder, events.
"""
import level_a_model as M

N = M.N
obj = M.obj
arr = M.arr
s = M.s
i = M.i
f = M.f
frame = M.frame
jcurve = M.jcurve
jstepped = M.jstepped


def child(node, key):
    """First direct child with this JSON key (case-sensitive)."""
    for k in node.kids:
        if k.key == key:
            return k
    return None


def sub(node, key):
    n = child(node, key)
    if n is None:
        raise KeyError(key)
    return n


def set_str(node, key, value):
    n = sub(node, key)
    n.s = value
    n.kind = 4
    return n


def set_key(node, old, new):
    n = sub(node, old)
    n.key = new
    return n


def skeleton_meta():
    return obj('skeleton', s('hash', 'abc123'), s('spine', '3.8.99'),
               f('width', 100.0), f('height', 200.0))


def bones_section(parent='root'):
    b0 = obj('b0', s('name', 'root'), f('length', 10.0), f('x', 1.0),
             f('y', 2.0), f('rotation', 30.0), f('scaleX', 2.0),
             f('scaleY', 3.0), f('shearX', 4.0), f('shearY', 5.0),
             i('inheritRotation', 0), i('inheritScale', 0))
    b1 = obj('b1', s('name', 'arm'), s('parent', parent), f('length', 5.0))
    b2 = obj('b2', s('name', 'hand'), s('parent', 'arm'))
    return arr('bones', [b0, b1, b2])


def slots_section(bone0='root'):
    slot = obj('slotA', s('bone', bone0), s('name', 'slotA'),
               s('color', 'ff000080'), s('attachment', 'reg'),
               s('blend', 'additive'))
    slot2 = obj('slotB', s('bone', 'arm'), s('name', 'slotB'),
                s('color', '00ff0080'), s('attachment', 'meshA'),
                s('blend', 'multiply'))
    return arr('slots', [slot, slot2])


def ik_section(bone0='root', target='arm'):
    return arr('ik', [obj('ik0', s('name', 'ikCon'),
                          arr('bones', [s(None, bone0), s(None, 'arm')]),
                          s('target', target), i('bendPositive', 0),
                          f('mix', 0.5))])


def transform_section(bone0='hand', target='arm'):
    return arr('transform', [obj('t0', s('name', 'tCon'),
                                 arr('bones', [s(None, bone0)]),
                                 s('target', target), f('rotation', 5.0),
                                 f('x', 1.0), f('y', 2.0), f('scaleX', 2.0),
                                 f('scaleY', 3.0), f('shearY', 4.0),
                                 f('rotateMix', 0.25), f('translateMix', 0.5),
                                 f('scaleMix', 0.75), f('shearMix', 0.125))])


def path_section(bone0='root', target='slotA'):
    return arr('path', [obj('p0', s('name', 'pCon'),
                            arr('bones', [s(None, bone0)]),
                            s('target', target), s('positionMode', 'fixed'),
                            s('spacingMode', 'fixed'), s('rotateMode', 'chain'),
                            f('rotation', 0.0), f('position', 3.0),
                            f('spacing', 4.0), f('rotateMix', 0.5),
                            f('translateMix', 0.25))])


def region_attachment():
    return obj('reg', s('name', 'reg'), s('path', 'asset'), s('type', 'region'),
               f('x', 1.0), f('y', 2.0), f('scaleX', 1.0), f('scaleY', 1.0),
               f('rotation', 0.0), f('width', 10.0), f('height', 20.0),
               s('color', 'ffffffff'))


def mesh_attachment():
    return obj('meshA', s('name', 'meshA'), s('type', 'mesh'),
               s('color', '80ff00ff'), f('width', 8.0), f('height', 8.0),
               arr('triangles', [N(None, i=0, kind=3), N(None, i=1, kind=3),
                                 N(None, i=2, kind=3)], 3),
               arr('uvs', [N(None, f=M.f32bits(v), kind=2)
                           for v in (0.0, 0.0, 1.0, 0.0, 0.0, 1.0)], 6),
               arr('vertices', [N(None, f=M.f32bits(v), kind=2)
                                for v in (0.0, 0.0, 1.0, 1.0, 2.0, 2.0)], 6),
               i('hull', 3))


def bbox_attachment():
    return obj('bboxA', s('name', 'bboxA'), s('type', 'boundingbox'),
               arr('vertices', [N(None, f=M.f32bits(v), kind=2)
                                for v in (1.0, 2.0, 3.0, 4.0, 5.0, 6.0)], 6),
               i('vertexCount', 3))


def path_attachment():
    return obj('pathA', s('name', 'pathA'), s('type', 'path'),
               i('closed', 1), i('constantSpeed', 0), i('vertexCount', 3),
               arr('vertices', [N(None, f=M.f32bits(v), kind=2)
                                for v in (0.0, 1.0, 2.0, 3.0, 4.0, 5.0)], 6),
               arr('lengths', [N(None, f=M.f32bits(v), kind=2)
                               for v in (1.0, 2.0, 3.0)], 3))


def linked_attachment(skin=None, parent='meshA'):
    kids = [s('name', 'linkA'), s('type', 'linkedmesh'), s('parent', parent),
            f('width', 8.0), f('height', 8.0), i('deform', 0)]
    if skin is not None:
        kids.insert(3, s('skin', skin))
    return obj('linkA', *kids)


def skins_section(att_type='region', link_skin=None, link_parent='meshA',
                  with_link=True):
    reg = region_attachment()
    if att_type != 'region':
        set_str(reg, 'type', att_type)
    slot_a = obj('slotA', reg, mesh_attachment())
    if with_link:
        slot_a.add(linked_attachment(link_skin, link_parent))
    slot_b = obj('slotB', bbox_attachment(), path_attachment())
    skins = arr('skins', [obj('default', slot_a, slot_b)])
    return skins


def events_section():
    return arr('events', [obj('step', i('int', 3), f('float', 1.5),
                              s('string', 'snd'))])
def anim_bones(bone='arm'):
    rot = arr('rotate', [
        frame(f('time', 0.25), f('angle', 30.0), jcurve()),
        frame(f('time', 0.5), f('angle', 60.0), jstepped()),
        frame(f('time', 0.75), f('angle', 90.0))])
    trn = arr('translate', [frame(f('time', 0.375), f('x', 1.0), f('y', 2.0)),
                           frame(f('time', 0.625), f('x', 3.0), f('y', 4.0))])
    scl = arr('scale', [frame(f('time', 0.125), f('x', 2.0), f('y', 3.0)),
                        frame(f('time', 0.5), f('x', 4.0), f('y', 5.0))])
    shr = arr('shear', [frame(f('time', 0.25), f('x', 1.5), f('y', 2.5)),
                        frame(f('time', 0.75), f('x', 3.5), f('y', 4.5))])
    return arr('bones', [arr(bone, [rot, trn, scl, shr])])


def anim_slots(slot='slotA'):
    att = arr('attachment', [
        frame(f('time', 0.1), s('name', 'reg')),
        frame(f('time', 0.9), s('name', 'meshA'))])
    col = arr('color', [
        frame(f('time', 0.2), s('color', 'ff0000ff'), i('x', 0)),
        frame(f('time', 0.4), s('color', '00ff00ff'), i('x', 0))])
    return arr('slots', [obj(slot, att, col)])


def anim_ik(name='ikCon'):
    return arr('ik', [arr(name, [
        frame(f('time', 0.1), f('mix', 0.5), i('bendPositive', 0)),
        frame(f('time', 0.9), f('mix', 0.8), i('bendPositive', 1))])])


def anim_transform(name='tCon'):
    return arr('transform', [arr(name, [
        frame(f('time', 0.15), f('rotateMix', 0.1), f('translateMix', 0.2),
              f('scaleMix', 0.3), f('shearMix', 0.4)),
        frame(f('time', 0.85), f('rotateMix', 0.6), f('translateMix', 0.7),
              f('scaleMix', 0.8), f('shearMix', 0.9))])])


def anim_paths(name='pCon'):
    pos = arr('position', [frame(f('time', 0.2), f('position', 1.5)),
                           frame(f('time', 0.6), f('position', 2.5))])
    spa = arr('spacing', [frame(f('time', 0.3), f('spacing', 3.5)),
                          frame(f('time', 0.7), f('spacing', 4.5))])
    mix = arr('mix', [frame(f('time', 0.4), f('rotateMix', 0.5),
                            f('translateMix', 0.25)),
                      frame(f('time', 0.8), f('rotateMix', 0.75),
                            f('translateMix', 0.125))])
    return arr('paths', [obj(name, pos, spa, mix)])


def anim_deform(skin='default', slot='slotA', att='meshA'):
    frames = [
        frame(f('time', 0.3), i('offset', 0),
              arr('vertices', [N(None, f=M.f32bits(v), kind=2)
                               for v in (0.5, 0.5, 1.5, 1.5, 2.5, 2.5)], 6)),
        frame(f('time', 0.7), i('offset', 1),
              arr('vertices', [N(None, f=M.f32bits(v), kind=2)
                               for v in (3.0, 3.5, 4.0, 4.5)], 4))]
    return arr('deform', [obj(skin, obj(slot, arr(att, frames)))])


def anim_draworder(slot='slotB'):
    f0 = frame(f('time', 0.35),
               arr('offsets', [obj(None, s('slot', slot), i('offset', 0))]))
    f1 = frame(f('time', 0.65))
    return arr('drawOrder', [f0, f1])


def anim_events(name='step'):
    return arr('events', [frame(s('name', name), f('time', 0.8))])


def build_main(anim_name='walk', drop_last_translate=False, **kw):
    root = N(None)
    anim = obj(anim_name, anim_bones(kw.get('bone_tl', 'arm')),
               anim_slots(kw.get('slot_tl', 'slotA')),
               anim_ik(), anim_transform(), anim_paths(), anim_deform(),
               anim_draworder(kw.get('draworder_slot', 'slotB')),
               anim_events(kw.get('event_name', 'step')))
    root.kids = [skeleton_meta(), bones_section(kw.get('parent', 'root')),
                 slots_section(kw.get('slot_bone', 'root')),
                 ik_section(kw.get('ik_bone0', 'root'), kw.get('ik_target', 'arm')),
                 transform_section(kw.get('tr_bone0', 'hand'),
                                   kw.get('tr_target', 'arm')),
                 path_section(kw.get('path_bone0', 'root'),
                              kw.get('path_target', 'slotA')),
                 skins_section(kw.get('att_type', 'region'),
                               kw.get('link_skin'), kw.get('link_parent', 'meshA'),
                               kw.get('with_link', True)),
                 events_section(), arr('animations', [anim])]
    if drop_last_translate:
        arm = child(sub(anim, 'bones'), kw.get('bone_tl', 'arm'))
        trn = child(arm, 'translate')
        trn.kids = trn.kids[:1]
        trn.declared = len(trn.kids)
    return root
def d_slot_bone():
    return build_main(slot_bone='ghost')


def d_ik_bone():
    return build_main(ik_bone0='ghost')


def d_parent():
    return build_main(parent='forearm')


def d_tr_bone():
    return build_main(tr_bone0='ghost')


def d_path_constraint():
    return _with(anim_paths('nope'))


def _with(new_paths):
    root = build_main()
    anim = sub(root, 'animations').kids[0]
    anim.kids = [new_paths if k.key == 'paths' else k for k in anim.kids]
    return root


def d_path_bone():
    return build_main(path_bone0='ghost')


def d_ik_target():
    return build_main(ik_target='ghost')


def d_tr_target():
    return build_main(tr_target='ghost')


def d_path_target():
    return build_main(path_target='ghost')


def d_draworder_slot():
    return build_main(draworder_slot='ghost')


def d_bone_tl():
    return build_main(bone_tl='ghost')


def d_event():
    return build_main(event_name='nope')


def d_deform_att():
    return _deform('nope')


def _deform(att):
    root = build_main()
    anim = sub(root, 'animations').kids[0]
    anim.kids = [anim_deform(att=att) if k.key == 'deform' else k for k in anim.kids]
    return root


def _bad_timeline(root, where, node_key):
    """Append an unknown member to a bone/slot timeline map (E1 / E3)."""
    anim = sub(root, 'animations').kids[0]
    if where == 'slot':
        target = child(sub(anim, 'slots'), 'slotA')
    else:
        target = child(sub(anim, 'bones'), 'arm')
    target.add(obj(node_key, arr('x', [frame(f('time', 0.5))])))
    target.declared = len(target.kids)
    return root


def d_tl_slot_invalid():
    return _bad_timeline(build_main(), 'slot', 'bogus')


def d_tl_bone_invalid():
    return _bad_timeline(build_main(), 'bone', 'bogus')


def d_link_skin():
    return build_main(link_skin='ghost')


def d_link_parent():
    return build_main(link_parent='P')


def d_att_unknown():
    return build_main(att_type='point')


def d_json_fail():
    return build_main()


def d_perturb():
    return build_main(anim_name='walk2', drop_last_translate=True)


def d_perturb_slot():
    """Delete slotB: the slots array, the skin's slotB node and the
    drawOrder offset all shrink; both arms must follow the same input."""
    root = build_main()
    slots = sub(root, 'slots')
    slots.kids = [k for k in slots.kids if not (k.key == 'slotB')]
    slots.declared = len(slots.kids)
    skin = sub(sub(root, 'skins'), 'default')
    skin.kids = [k for k in skin.kids if not (k.key == 'slotB')]
    anim = sub(root, 'animations').kids[0]
    anim.kids = [anim_draworder(slot='slotA') if k.key == 'drawOrder' else k
                 for k in anim.kids]
    return root


def d_perturb_curve():
    """Change the four curve array values of the first rotate frame."""
    root = build_main()
    arm = child(sub(sub(root, 'animations').kids[0], 'bones'), 'arm')
    rot = child(arm, 'rotate')
    curve = child(rot.kids[0], 'curve')
    curve.kids = [N(None, f=M.f32bits(v), kind=2)
                  for v in (0.1, 0.2, 0.3, 0.4)]
    return root


VARIANTS = {
    'main': build_main,
    'perturb': d_perturb,
    'perturb_slot': d_perturb_slot,
    'perturb_curve': d_perturb_curve,
    'err_slot_bone': d_slot_bone,
    'err_ik_bone': d_ik_bone,
    'err_parent': d_parent,
    'err_tr_bone': d_tr_bone,
    'err_path_constraint': d_path_constraint,
    'err_path_bone': d_path_bone,
    'err_ik_target': d_ik_target,
    'err_tr_target': d_tr_target,
    'err_path_target': d_path_target,
    'err_draworder_slot': d_draworder_slot,
    'err_bone_tl': d_bone_tl,
    'err_tl_slot_invalid': d_tl_slot_invalid,
    'err_tl_bone_invalid': d_tl_bone_invalid,
    'err_event': d_event,
    'err_deform_att': d_deform_att,
    'err_link_skin': d_link_skin,
    'err_link_parent': d_link_parent,
    'err_att_unknown': d_att_unknown,
    'err_json': d_json_fail,
}


def emit_all():
    """One #if/#elif chain emitting every variant's C builder (the driver
    selects with -DLEVEL_A_VARIANT=N, N = 1-based index into VARIANTS)."""
    lines = []
    for n, (name, fn) in enumerate(VARIANTS.items(), start=1):
        guard = '#if' if n == 1 else '#elif'
        lines.append('%s LEVEL_A_VARIANT == %d' % (guard, n))
        lines.append(M.emit_c(fn()))
    lines.append('#endif')
    return '\n'.join(lines) + '\n'


# Variants whose Json_create must fail: the fixture returns NULL and answers
# Json_getError with the same text the oracle's hook returns.
JSON_FAIL = {'err_json'}
JSON_ERROR = 'expected value at 1'
