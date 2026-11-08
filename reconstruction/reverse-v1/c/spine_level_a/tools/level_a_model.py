#!/usr/bin/env python3
"""Level A single-source Json tree.

The tree is written ONCE here and emitted twice:
  * emit_unicorn_layout()/Oracle.build_tree lays the 32-byte nodes + strings into
    the Unicorn memory image of the original arm;
  * emit_c() writes the C fixture that builds the same nodes with node()/add().
canonical() is the BINDING witness: the C fixture serialises its own g_tree with
the same byte grammar, and the driver hashes both byte strings.

Node grammar (json_interface.h): next+0, child+4, unk_08+8 (type), unk_0c+0xc
(array declared count), string_value+0x10, int_value+0x14, float_value+0x18,
name+0x1c.  The type word matters to readCurve: 4 = string, 5 = array.
"""
import hashlib
import struct

def f32bits(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


class N:
    __slots__ = ('key', 's', 'i', 'f', 'kind', 'declared', 'kids')

    def __init__(self, key=None, s=None, i=None, f=None, kind=0, declared=None):
        self.key = key
        self.s = s
        self.i = i
        self.f = f
        self.kind = kind
        self.declared = declared
        self.kids = []

    def add(self, *kids):
        self.kids.extend(kids)
        return self


def obj(key, *nodes):
    n = N(key, kind=1)
    n.kids = list(nodes)
    return n


def arr(key, nodes, declared=None):
    n = N(key, kind=5, declared=len(nodes) if declared is None else declared)
    n.kids = list(nodes)
    return n


def s(key, v):
    return N(key, s=v, kind=4)


def i(key, v):
    return N(key, i=v, kind=3)


def f(key, v):
    return N(key, f=f32bits(v), kind=2)


def frame(*nodes):
    return obj(None, *nodes)


def jcurve(vals=(0.125, 0.25, 0.375, 0.5)):
    return arr('curve', [N(None, f=f32bits(v), kind=2) for v in vals])


def jstepped():
    return N('curve', s='stepped', kind=4)


def main_tree(parent='root', drop_last_translate=False, anim_name='walk'):
    root = N(None)
    sk = obj('skeleton', s('hash', 'abc123'), s('spine', '3.8.99'),
             f('width', 100.0), f('height', 200.0))
    b0 = obj('b0', s('name', 'root'), f('length', 10.0), f('x', 1.0), f('y', 2.0),
             f('rotation', 30.0), f('scaleX', 2.0), f('scaleY', 3.0),
             f('shearX', 4.0), f('shearY', 5.0),
             i('inheritRotation', 0), i('inheritScale', 0))
    b1 = obj('b1', s('name', 'arm'), s('parent', parent), f('length', 5.0))
    b2 = obj('b2', s('name', 'hand'), s('parent', 'arm'))
    bones = arr('bones', [b0, b1, b2])
    slot = obj('slotA', s('bone', 'root'), s('name', 'slotA'),
               s('color', 'ff000080'), s('attachment', 'reg'), s('blend', 'additive'))
    slots = arr('slots', [slot])
    ik = arr('ik', [obj('ik0', s('name', 'ikCon'),
                        arr('bones', [s(None, 'root'), s(None, 'arm')]),
                        s('target', 'arm'), i('bendPositive', 0), f('mix', 0.5))])
    tr = arr('transform', [obj('t0', s('name', 'tCon'),
                               arr('bones', [s(None, 'hand')]),
                               s('target', 'arm'), f('rotation', 5.0),
                               f('x', 1.0), f('y', 2.0), f('scaleX', 2.0),
                               f('scaleY', 3.0), f('shearY', 4.0),
                               f('rotateMix', 0.25), f('translateMix', 0.5),
                               f('scaleMix', 0.75), f('shearMix', 0.125))])
    path = arr('path', [obj('p0', s('name', 'pCon'),
                            arr('bones', [s(None, 'root')]),
                            s('target', 'slotA'), s('positionMode', 'fixed'),
                            s('spacingMode', 'fixed'), s('rotateMode', 'chain'),
                            f('rotation', 0.0), f('position', 3.0),
                            f('spacing', 4.0), f('rotateMix', 0.5),
                            f('translateMix', 0.25))])
    reg = obj('reg', s('name', 'reg'), s('path', 'asset'), s('type', 'region'),
              f('x', 1.0), f('y', 2.0), f('scaleX', 1.0), f('scaleY', 1.0),
              f('rotation', 0.0), f('width', 10.0), f('height', 20.0),
              s('color', 'ffffffff'))
    mesh = obj('meshA', s('name', 'meshA'), s('type', 'mesh'),
               s('color', '80ff00ff'), f('width', 8.0), f('height', 8.0),
               arr('triangles', [N(None, i=0, kind=3), N(None, i=1, kind=3),
                                 N(None, i=2, kind=3)], 3),
               arr('uvs', [N(None, f=f32bits(v), kind=2)
                           for v in (0.0, 0.0, 1.0, 0.0, 0.0, 1.0)], 6),
               arr('vertices', [N(None, f=f32bits(v), kind=2)
                                for v in (0.0, 0.0, 1.0, 1.0, 2.0, 2.0)], 6),
               i('hull', 3))
    skin_slot = obj('slotA', reg, mesh)
    skins = arr('skins', [obj('default', skin_slot)])
    ev = arr('events', [obj('step', i('int', 3), f('float', 1.5),
                            s('string', 'snd'))])
    # rotate: frame 0 array curve, frame 1 stepped (index 1 is inside the
    # (frameCount-1)*19 array for three frames), frame 2 plain.
    rot = arr('rotate', [
        frame(f('time', 0.25), f('angle', 30.0), jcurve()),
        frame(f('time', 0.5), f('angle', 60.0), jstepped()),
        frame(f('time', 0.75), f('angle', 90.0))])
    trn_frames = [frame(f('time', 0.375), f('x', 1.0), f('y', 2.0)),
                  frame(f('time', 0.625), f('x', 3.0), f('y', 4.0))]
    if drop_last_translate:
        trn_frames = trn_frames[:1]
    trn = arr('translate', trn_frames)
    arm = arr('arm', [rot, trn])
    anim_bones = arr('bones', [arm])
    anim_ev = arr('events', [frame(s('name', 'step'), f('time', 0.8))])
    anim = obj(anim_name, anim_bones, anim_ev)
    anims = arr('animations', [anim])
    root.kids = [sk, bones, slots, ik, tr, path, skins, ev, anims]
    return root


def error_tree():
    """Same shape, one parent key names a bone that does not exist."""
    return main_tree(parent='forearm')


def perturb_tree():
    """Input perturbation: one timeline frame removed, animation renamed."""
    return main_tree(drop_last_translate=True, anim_name='walk2')


VARIANTS = {
    'main': main_tree,
    'err_parent': error_tree,
    'perturb': perturb_tree,
}


def flatten(root):
    out = []

    def rec(n):
        out.append(n)
        for k in n.kids:
            rec(k)
    rec(root)
    return out


def canonical(root):
    """Byte grammar shared with fixture/level_a_dump.c dump_tree_node()."""
    nodes = flatten(root)
    index = {id(n): k for k, n in enumerate(nodes)}
    out = bytearray()

    def wstr(x):
        b = (x or '').encode()
        out.extend(struct.pack('<H', len(b)))
        out.extend(b)

    def rec(k):
        n = nodes[k]
        out.append(0x7b)
        out.append(1 if n.key is not None else 0)
        if n.key is not None:
            wstr(n.key)
        out.append(1 if n.s is not None else 0)
        if n.s is not None:
            wstr(n.s)
        out.extend(struct.pack('<i', n.i if n.i is not None else 0))
        out.extend(struct.pack('<I', n.f if n.f is not None else 0))
        out.extend(struct.pack('<I', n.kind if n.kind is not None else 0))
        out.extend(struct.pack('<I', n.declared if n.declared is not None else 0))
        out.extend(struct.pack('<I', len(n.kids)))
        for kid in n.kids:
            rec(index[id(kid)])
        out.append(0x7d)
    rec(0)
    return bytes(out)


def binding(root):
    blob = canonical(root)
    return {'node_count': len(flatten(root)),
            'canonical_sha256': hashlib.sha256(blob).hexdigest(),
            'canonical_bytes': len(blob)}


def _cstr(x):
    return '"' + x.replace('\\', '\\\\').replace('"', '\\"') + '"'


def emit_c(root, func='build_level_a_tree'):
    """C fixture builder using the mesh fixture's node()/add() helpers."""
    nodes = flatten(root)
    index = {id(n): k for k, n in enumerate(nodes)}
    lines = ['static Json *%s(void)' % func, '{']
    for k, n in enumerate(nodes):
        key = _cstr(n.key) if n.key is not None else '0'
        lines.append('    Json *n%d = node(%s);' % (k, key))
    for k, n in enumerate(nodes):
        if n.s is not None:
            lines.append('    n%d->string_value = %s;' % (k, _cstr(n.s)))
        if n.i is not None:
            lines.append('    n%d->int_value = %d;' % (k, n.i))
        if n.f is not None:
            lines.append('    n%d->float_value = fb(0x%08xu);' % (k, n.f))
        if n.kind:
            lines.append('    n%d->unk_08 = %du;' % (k, n.kind))
        if n.declared is not None:
            lines.append('    n%d->unk_0c = %du;' % (k, n.declared))
    for k, n in enumerate(nodes):
        for kid in n.kids:
            lines.append('    add(n%d, n%d);' % (k, index[id(kid)]))
    lines.append('    return n0;')
    lines.append('}')
    return '\n'.join(lines) + '\n'


def emit_all():
    out = []
    for name, fn in VARIANTS.items():
        out.append('#if LEVEL_A_VARIANT == %d' % (list(VARIANTS).index(name) + 1))
        out.append(emit_c(fn()))
        out.append('#endif')
    return '\n'.join(out) + '\n'
