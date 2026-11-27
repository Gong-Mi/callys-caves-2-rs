#!/usr/bin/env python3
"""Decode the Level A dump on both arms into one canonical record shape.

C arm  : binary stream produced by fixture/level_a_dump.c (record tags below).
Orig arm: direct reads of the Unicorn memory image, emitted into the same dict.
"""
import struct

T_TREE = 1
T_META = 2
T_BONES = 3
T_SLOTS = 4
T_IK = 5
T_TRANSFORM = 6
T_PATH = 7
T_SKINS = 8
T_EVENTS = 9
T_ANIMS = 10
T_ERROR = 11
T_END = 0xff


class Reader:
    def __init__(self, blob):
        self.b = blob
        self.p = 0

    def u8(self):
        v = self.b[self.p]; self.p += 1; return v

    def u16(self):
        v = struct.unpack_from('<H', self.b, self.p)[0]; self.p += 2; return v

    def u32(self):
        v = struct.unpack_from('<I', self.b, self.p)[0]; self.p += 4; return v

    def i32(self):
        v = struct.unpack_from('<i', self.b, self.p)[0]; self.p += 4; return v

    def s(self):
        n = self.u16()
        v = self.b[self.p:self.p + n].decode('utf-8', 'replace')
        self.p += n
        return v


def _tree_len(buf, p):
    assert buf[p] == 0x7b
    p += 1
    if buf[p]:
        p += 1
        p += 2 + struct.unpack_from('<H', buf, p)[0]
    else:
        p += 1
    if buf[p]:
        p += 1
        p += 2 + struct.unpack_from('<H', buf, p)[0]
    else:
        p += 1
    p += 4 + 4 + 4 + 4
    kids = struct.unpack_from('<I', buf, p)[0]; p += 4
    for _ in range(kids):
        p = _tree_len(buf, p)
    assert buf[p] == 0x7d
    return p + 1


def tree_node_hashes(buf):
    """Per-node sha256 over the node's own canonical record (no children).

    Both arms emit the same canonical tree bytes, so this list is the
    'per-node sha' BINDING witness.  The local slice is node[0]..child_count,
    children excluded.
    """
    import hashlib
    out = []

    def rec(p):
        start = p
        assert buf[p] == 0x7b
        p += 1
        if buf[p]:
            p += 1
            p += 2 + struct.unpack_from('<H', buf, p)[0]
        else:
            p += 1
        if buf[p]:
            p += 1
            p += 2 + struct.unpack_from('<H', buf, p)[0]
        else:
            p += 1
        p += 16
        kids = struct.unpack_from('<I', buf, p)[0]
        p += 4
        out.append(hashlib.sha256(buf[start:p]).hexdigest())
        for _ in range(kids):
            p = rec(p)
        assert buf[p] == 0x7d
        return p + 1
    end = rec(0)
    assert end == len(buf), 'canonical tree trailing bytes'
    return out


def parse_binary(blob, trace=None):
    r = Reader(blob)
    out = {'tree': b'', 'meta': None, 'bones': [], 'slots': [], 'ik': [],
           'transform': [], 'path': [], 'skins': [], 'events': [],
           'animations': [], 'error': None}
    while True:
        off = r.p
        tag = r.u8()
        if trace:
            trace(tag, off)
        if tag == T_END:
            break
        if tag == T_TREE:
            start = r.p
            end = _tree_len(blob, start)
            out['tree'] = blob[start:end]
            r.p = end
        elif tag == T_META:
            words = [r.u32() for _ in range(21)]
            out['meta'] = {'words': words, 'spine': r.s(), 'hash': r.s()}
        elif tag == T_BONES:
            n = r.u32()
            for _ in range(n):
                b = {'index': r.i32(), 'name': r.s(), 'parent': r.i32()}
                vals = [r.u32() for _ in range(8)]
                b.update(length=vals[0], x=vals[1], y=vals[2], rotation=vals[3],
                         scaleX=vals[4], scaleY=vals[5], shearX=vals[6],
                         shearY=vals[7])
                b['inheritRotation'] = r.i32()
                b['inheritScale'] = r.i32()
                out['bones'].append(b)
        elif tag == T_SLOTS:
            n = r.u32()
            for _ in range(n):
                s = {'index': r.i32(), 'name': r.s(), 'bone': r.i32(),
                     'attachment': r.s(), 'r': r.u32(), 'g': r.u32(),
                     'b': r.u32(), 'a': r.u32(), 'blend': r.i32()}
                out['slots'].append(s)
        elif tag == T_IK:
            n = r.u32()
            for _ in range(n):
                c = {'index': r.i32(), 'name': r.s()}
                bc = r.i32(); c['boneCount'] = bc
                c['bones'] = [r.i32() for _ in range(bc)]
                c['target'] = r.i32()
                c['bendDirection'] = r.i32()
                c['mix'] = r.u32()
                out['ik'].append(c)
        elif tag == T_TRANSFORM:
            n = r.u32()
            for _ in range(n):
                c = {'index': r.i32(), 'name': r.s()}
                bc = r.i32(); c['boneCount'] = bc
                c['bones'] = [r.i32() for _ in range(bc)]
                c['target'] = r.i32()
                vals = [r.u32() for _ in range(10)]
                c.update(rotateMix=vals[0], translateMix=vals[1],
                         scaleMix=vals[2], shearMix=vals[3], rotation=vals[4],
                         x=vals[5], y=vals[6], scaleX=vals[7], scaleY=vals[8],
                         shearY=vals[9])
                out['transform'].append(c)
        elif tag == T_PATH:
            n = r.u32()
            for _ in range(n):
                c = {'index': r.i32(), 'name': r.s()}
                bc = r.i32(); c['boneCount'] = bc
                c['bones'] = [r.i32() for _ in range(bc)]
                c['target'] = r.i32()
                vals = [r.u32() for _ in range(8)]
                c.update(positionMode=vals[0], spacingMode=vals[1],
                         rotateMode=vals[2], rotation=vals[3], position=vals[4],
                         spacing=vals[5], rotateMix=vals[6], translateMix=vals[7])
                out['path'].append(c)
        elif tag == T_SKINS:
            n = r.u32()
            out['defaultSkinIndex'] = r.i32()
            for _ in range(n):
                skin = {'index': r.i32(), 'name': r.s(), 'entries': []}
                ec = r.u32()
                for _ in range(ec):
                    e = {'slot': r.i32(), 'name': r.s()}
                    e['attachment'] = _read_attachment(r)
                    skin['entries'].append(e)
                out['skins'].append(skin)
        elif tag == T_EVENTS:
            n = r.u32()
            for _ in range(n):
                out['events'].append({'index': r.i32(), 'name': r.s(),
                                      'intValue': r.i32(),
                                      'floatValue': r.u32(),
                                      'stringValue': r.s()})
        elif tag == T_ANIMS:
            n = r.u32()
            for _ in range(n):
                a = {'index': r.i32(), 'name': r.s(), 'duration': r.u32(),
                     'timelineCount': r.i32(), 'timelines': []}
                for _ in range(a['timelineCount']):
                    t = {'type': r.u32(), 'frameCount': r.u32(),
                         'frameFloatCount': r.u32(), 'index': r.i32()}
                    if t['type'] == 5:
                        # fixture emits per frame: time(u32) + name(str),
                        # interleaved (la_dump_animations type-5 branch)
                        t['slotIndex'] = r.i32()
                        t['frames'] = []
                        t['names'] = []
                        for _ in range(t['frameCount']):
                            t['frames'].append(r.u32())
                            t['names'].append(r.s())
                    elif t['type'] == 7:
                        t['slotsCount'] = r.i32()
                        t['frames'] = []
                        for _ in range(t['frameCount']):
                            t['frames'].append({
                                'time': r.u32(),
                                'order': [r.i32() for _ in range(t['slotsCount'])]})
                    elif t['type'] == 8:
                        t['vertexFloatCount'] = r.i32()
                        t['frames'] = []
                        for _ in range(t['frameCount']):
                            t['frames'].append({
                                'time': r.u32(),
                                'vertices': [r.u32() for _ in
                                             range(t['vertexFloatCount'])]})
                    elif t['type'] == 6:
                        t['frames'] = []
                        for _ in range(t['frameCount']):
                            t['frames'].append({
                                'time': r.u32(), 'intValue': r.i32(),
                                'floatValue': r.u32(), 'stringValue': r.s()})
                    else:
                        t['frames'] = [r.u32() for _ in range(t['frameFloatCount'])]
                        cn = max(0, (t['frameCount'] - 1) * 19)
                        t['curves'] = [r.u32() for _ in range(cn)]
                    a['timelines'].append(t)
                out['animations'].append(a)
        elif tag == T_ERROR:
            out['error'] = {'is_null': r.u32(), 'error': r.s(), 'reported': r.s(),
                            'json_create_calls': r.u32(), 'report_calls': r.u32(),
                            'root_dispose': r.u32()}
        else:
            raise ValueError('unknown tag %#x at %d' % (tag, r.p))
    return out


def _read_attachment(r):
    a = {'type': r.i32(), 'name': r.s(), 'path': r.s()}
    if a['type'] == 0:
        vals = [r.u32() for _ in range(11)]
        a.update(x=vals[0], y=vals[1], scaleX=vals[2], scaleY=vals[3],
                 rotation=vals[4], width=vals[5], height=vals[6],
                 r=vals[7], g=vals[8], b=vals[9], a=vals[10])
        a['region'] = [r.i32() for _ in range(6)]
        a['offset'] = [r.u32() for _ in range(8)]
        a['uvs'] = [r.u32() for _ in range(8)]
    elif a['type'] in (2, 3):
        a['boneCount'] = r.u32()
        a['vertexFloatCount'] = r.u32()
        a['worldVerticesLength'] = r.u32()
        a['vertices'] = [r.u32() for _ in range(min(a['vertexFloatCount'], 16))]
        vals = [r.u32() for _ in range(4)]
        a.update(u=vals[0], v=vals[1], u2=vals[2], v2=vals[3])
        rgba = [r.u32() for _ in range(4)]
        a.update(r=rgba[0], g=rgba[1], b=rgba[2], a=rgba[3])
        a['region'] = [r.i32() for _ in range(4)]
        a['triangleCount'] = r.u32()
        a['triangles'] = [r.u16() for _ in range(min(a['triangleCount'], 12))]
        a['hull'] = r.u32()
        a['parentMesh'] = r.s()
    else:
        a['boneCount'] = r.u32()
        a['vertexFloatCount'] = r.u32()
        a['worldVerticesLength'] = r.u32()
        a['vertices'] = [r.u32() for _ in range(min(a['vertexFloatCount'], 16))]
        if a['type'] == 4:
            a['flags'] = [r.i32() for _ in range(3)]
    return a


# ----------------------------------------------------------------------
# Unicorn arm reader
# ----------------------------------------------------------------------
def read_oracle(oracle, ret):
    uc = oracle.uc

    def u32(addr):
        return struct.unpack('<I', bytes(uc.mem_read(addr, 4)))[0]

    def i32(addr):
        return struct.unpack('<i', bytes(uc.mem_read(addr, 4)))[0]

    def ptr(addr):
        return u32(addr)

    def cstr(addr):
        return oracle.read_cstr(addr) if addr else ''

    out = {'tree': b'', 'meta': None, 'bones': [], 'slots': [], 'ik': [],
           'transform': [], 'path': [], 'skins': [], 'events': [],
           'animations': [], 'error': None}
    if not ret:
        errp = u32(oracle.selfptr + 8)
        out['error'] = {'is_null': 1, 'error': cstr(errp), 'reported': '',
                        'json_create_calls': 0, 'report_calls': 0,
                        'root_dispose': oracle.root_disposes}
        return out
    words = [u32(ret + 4 * k) for k in range(21)]
    out['meta'] = {'words': words, 'spine': cstr(words[0]),
                   'hash': cstr(words[1])}
    bcount, btable = words[4], words[5]
    for k in range(bcount):
        b = ptr(btable + 4 * k)
        out['bones'].append({
            'index': i32(b), 'name': cstr(u32(b + 4)),
            'parent': _index_of(uc, btable, bcount, ptr(b + 8)),
            'length': u32(b + 0xc), 'x': u32(b + 0x10), 'y': u32(b + 0x14),
            'rotation': u32(b + 0x18), 'scaleX': u32(b + 0x1c),
            'scaleY': u32(b + 0x20), 'shearX': u32(b + 0x24),
            'shearY': u32(b + 0x28), 'inheritRotation': i32(b + 0x2c),
            'inheritScale': i32(b + 0x30)})
    scount, stable = words[6], words[7]
    for k in range(scount):
        s = ptr(stable + 4 * k)
        out['slots'].append({
            'index': i32(s), 'name': cstr(u32(s + 4)),
            'bone': _index_of(uc, btable, bcount, ptr(s + 8)),
            'attachment': cstr(u32(s + 0xc)),
            'r': u32(s + 0x10), 'g': u32(s + 0x14),
            'b': u32(s + 0x18), 'a': u32(s + 0x1c),
            'blend': i32(s + 0x20)})
    icount, itable = words[15], words[16]
    for k in range(icount):
        c = ptr(itable + 4 * k)
        bc = i32(c + 4)
        bones = ptr(c + 8)
        out['ik'].append({
            'index': k, 'name': cstr(u32(c)),
            'boneCount': bc,
            'bones': [_index_of(uc, btable, bcount, ptr(bones + 4 * j))
                      for j in range(bc)],
            'target': _index_of(uc, btable, bcount, ptr(c + 0xc)),
            'bendDirection': i32(c + 0x10), 'mix': u32(c + 0x14)})
    tcount, ttable = words[17], words[18]
    for k in range(tcount):
        c = ptr(ttable + 4 * k)
        bc = i32(c + 4)
        bones = ptr(c + 8)
        out['transform'].append({
            'index': k, 'name': cstr(u32(c)), 'boneCount': bc,
            'bones': [_index_of(uc, btable, bcount, ptr(bones + 4 * j))
                      for j in range(bc)],
            'target': _index_of(uc, btable, bcount, ptr(c + 0xc)),
            'rotateMix': u32(c + 0x10), 'translateMix': u32(c + 0x14),
            'scaleMix': u32(c + 0x18), 'shearMix': u32(c + 0x1c),
            'rotation': u32(c + 0x20), 'x': u32(c + 0x24),
            'y': u32(c + 0x28), 'scaleX': u32(c + 0x2c),
            'scaleY': u32(c + 0x30), 'shearY': u32(c + 0x34)})
    pcount, ptable = words[19], words[20]
    for k in range(pcount):
        c = ptr(ptable + 4 * k)
        bc = i32(c + 4)
        bones = ptr(c + 8)
        out['path'].append({
            'index': k, 'name': cstr(u32(c)), 'boneCount': bc,
            'bones': [_index_of(uc, btable, bcount, ptr(bones + 4 * j))
                      for j in range(bc)],
            'target': _index_of(uc, stable, scount, ptr(c + 0xc)),
            'positionMode': i32(c + 0x10), 'spacingMode': i32(c + 0x14),
            'rotateMode': i32(c + 0x18), 'rotation': u32(c + 0x1c),
            'position': u32(c + 0x20), 'spacing': u32(c + 0x24),
            'rotateMix': u32(c + 0x28), 'translateMix': u32(c + 0x2c)})
    skcount, sktable = words[8], words[9]
    out['defaultSkinIndex'] = _index_of(uc, sktable, skcount, ptr(ret + 0x28))
    for k in range(skcount):
        skin = ptr(sktable + 4 * k)
        sk = {'index': k, 'name': cstr(u32(skin)), 'entries': []}
        e = ptr(skin + 4)
        while e:
            att = ptr(e + 8)
            sk['entries'].append({
                'slot': i32(e), 'name': cstr(u32(e + 4)),
                'attachment': _read_attachment_mem(
                    uc, att, lambda a: u32(a), lambda a: i32(a), cstr)})
            e = ptr(e + 0xc)
        out['skins'].append(sk)
    ecount, etable = words[11], words[12]
    for k in range(ecount):
        e = ptr(etable + 4 * k)
        out['events'].append({
            'index': k, 'name': cstr(u32(e)), 'intValue': i32(e + 4),
            'floatValue': u32(e + 8), 'stringValue': cstr(u32(e + 0xc))})
    acount, atable = words[13], words[14]
    for k in range(acount):
        a = ptr(atable + 4 * k)
        anim = {'index': k, 'name': cstr(u32(a)), 'duration': u32(a + 4),
                'timelineCount': i32(a + 8), 'timelines': []}
        tl = ptr(a + 0xc)
        for j in range(anim['timelineCount']):
            t = ptr(tl + 4 * j)
            typ = u32(t)
            step = _STEP.get(typ, 0)
            ffc = 0 if 5 <= typ <= 8 else i32(t + 0xc)
            if typ == 5 or typ == 6 or typ == 7:
                fc = i32(t + 8)
            elif typ == 8:
                fc = i32(t + 0xc)          # deform: +0x0c frameCount, not ffc
            else:
                fc = ffc // step if step else 0
            item = {'type': typ, 'frameCount': fc, 'frameFloatCount': ffc,
                    'index': 0 if 5 <= typ <= 8 else i32(t + 0x14)}
            if step:
                frames = ptr(t + 0x10)
                item['frames'] = [u32(frames + 4 * q) for q in range(ffc)]
                curves = ptr(t + 8)
                cn = max(0, (fc - 1) * 19)
                item['curves'] = [u32(curves + 4 * q) for q in range(cn)]
            elif typ == 5:
                times = ptr(t + 0xc)
                names = ptr(t + 0x14)
                item['slotIndex'] = i32(t + 0x10)
                item['frames'] = [u32(times + 4 * q) for q in range(fc)]
                item['names'] = [cstr(u32(names + 4 * q)) for q in range(fc)]
            elif typ == 7:
                slots = i32(t + 0x14)
                dtimes = ptr(t + 0xc)
                orders = ptr(t + 0x10)
                item['slotsCount'] = slots
                item['frames'] = []
                for q in range(fc):
                    o = ptr(orders + 4 * q) if orders else 0
                    item['frames'].append({
                        'time': u32(dtimes + 4 * q),
                        'order': [i32(o + 4 * k) if o else 0x7fffffff
                                  for k in range(slots)]})
            elif typ == 8:
                vcount = i32(t + 0x14)
                vtimes = ptr(t + 0x10)
                table = ptr(t + 0x18)
                item['vertexFloatCount'] = vcount
                item['frames'] = []
                for q in range(fc):
                    vp = ptr(table + 4 * q) if table else 0
                    item['frames'].append({
                        'time': u32(vtimes + 4 * q),
                        'vertices': [u32(vp + 4 * k) if vp else 0x7fffffff
                                     for k in range(vcount)]})
            elif typ == 6:
                times = ptr(t + 0xc)
                events = ptr(t + 0x10)
                item['frames'] = []
                for q in range(fc):
                    e = ptr(events + 4 * q)
                    if e:
                        item['frames'].append({
                            'time': u32(times + 4 * q), 'intValue': i32(e + 8),
                            'floatValue': u32(e + 0xc),
                            'stringValue': cstr(u32(e + 0x10))})
                    else:
                        item['frames'].append({'time': u32(times + 4 * q),
                                               'intValue': 0, 'floatValue': 0,
                                               'stringValue': ''})
            else:
                item['frames'] = []
            anim['timelines'].append(item)
        out['animations'].append(anim)
    errp = u32(oracle.selfptr + 8)
    out['error'] = {'is_null': 0, 'error': cstr(errp), 'reported': '',
                    'json_create_calls': 0, 'report_calls': 0,
                    'root_dispose': oracle.root_disposes}
    return out


_STEP = {1: 2, 2: 3, 0: 3, 3: 3, 4: 5, 9: 3, 10: 5, 11: 2, 12: 2, 13: 3}


def _index_of(uc, table, count, p):
    for k in range(count):
        if struct.unpack('<I', bytes(uc.mem_read(table + 4 * k, 4)))[0] == p:
            return k
    return -1


def _read_attachment_mem(uc, a, u32, i32, cstr):
    typ = i32(a + 4)
    out = {'type': typ, 'name': cstr(u32(a)), 'path': ''}
    if typ == 0:
        out['path'] = cstr(u32(a + 0x10))
        out.update(x=u32(a + 0x14), y=u32(a + 0x18),
                   scaleX=u32(a + 0x1c), scaleY=u32(a + 0x20),
                   rotation=u32(a + 0x24), width=u32(a + 0x28),
                   height=u32(a + 0x2c), r=u32(a + 0x30), g=u32(a + 0x34),
                   b=u32(a + 0x38), a=u32(a + 0x3c))
        out['region'] = [i32(a + 0x44 + 4 * k) for k in range(6)]
        out['offset'] = [u32(a + 0x5c + 4 * k) for k in range(8)]
        out['uvs'] = [u32(a + 0x7c + 4 * k) for k in range(8)]
    elif typ in (2, 3):
        out['path'] = cstr(u32(a + 0x54))
        out['boneCount'] = u32(a + 0x10)
        out['vertexFloatCount'] = u32(a + 0x18)
        out['worldVerticesLength'] = u32(a + 0x20)
        vp = u32(a + 0x1c)
        n = min(out['vertexFloatCount'], 16)
        out['vertices'] = [u32(vp + 4 * k) for k in range(n)]
        out.update(u=u32(a + 0x40), v=u32(a + 0x44), u2=u32(a + 0x48),
                   v2=u32(a + 0x4c), r=u32(a + 0x68), g=u32(a + 0x6c),
                   b=u32(a + 0x70), a=u32(a + 0x74))
        out['region'] = [i32(a + 0x30 + 4 * k) for k in range(4)]
        out['triangleCount'] = u32(a + 0x60)
        tp = u32(a + 0x64)
        out['triangles'] = [struct.unpack('<H', bytes(uc.mem_read(tp + 2 * k, 2)))[0]
                            for k in range(min(out['triangleCount'], 12))]
        out['hull'] = u32(a + 0x78)
        pm = u32(a + 0x7c)
        out['parentMesh'] = cstr(u32(pm)) if pm else ''
    else:
        out['boneCount'] = u32(a + 0x10)
        out['vertexFloatCount'] = u32(a + 0x18)
        out['worldVerticesLength'] = u32(a + 0x20)
        vp = u32(a + 0x1c)
        n = min(out['vertexFloatCount'], 16)
        out['vertices'] = [u32(vp + 4 * k) for k in range(n)]
        if typ == 4:
            out['flags'] = [i32(a + 0x24), i32(a + 0x2c), i32(a + 0x30)]
    return out
