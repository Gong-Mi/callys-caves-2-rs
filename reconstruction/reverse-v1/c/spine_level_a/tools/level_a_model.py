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
    # The REAL Json parser sets unk_0c = member count on OBJECT nodes too
    # (the B4 timelineCount sums depend on it: they read per-bone/per-slot/
    # per-constraint OBJECT children's +0xc as the per-entry timeline count;
    # the original library would overflow its own arrays on every real
    # skeleton otherwise). Staged trees must reproduce that invariant.
    n = N(key, kind=1, declared=len(nodes))
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
