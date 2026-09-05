#!/usr/bin/env python3
"""Hash-pinned GMS bytecode-16 evidence ledger, not a VM or decompiler."""
import argparse
import bisect
import hashlib
import json
from pathlib import Path
import struct

SHA256 = '9eee3f3aa6718375f2cd24fbfa33e075879a291ba9d43214441d4408994347a6'


class FormatError(ValueError):
    pass


def require(condition, message):
    if not condition:
        raise FormatError(message)


class Reader:
    def __init__(self, data):
        self.data = data
        self.chunks = {}
        require(data[:4] == b'FORM', 'missing FORM')
        require(self.u32(4) + 8 == len(data), 'FORM size mismatch')
        pos = 8
        while pos < len(data):
            self.bounds(pos, 8)
            tag = data[pos:pos + 4].decode('ascii')
            size = self.u32(pos + 4)
            self.bounds(pos + 8, size)
            require(tag not in self.chunks, 'duplicate chunk ' + tag)
            self.chunks[tag] = (pos + 8, pos + 8 + size)
            pos += 8 + size

    def bounds(self, pos, size, lower=0, upper=None):
        upper = len(self.data) if upper is None else upper
        require(lower <= pos and size >= 0 and pos + size <= upper,
                f'range {pos:#x}+{size:#x} outside {lower:#x}..{upper:#x}')

    def u32(self, pos):
        self.bounds(pos, 4)
        return struct.unpack_from('<I', self.data, pos)[0]

    def i32(self, pos):
        self.bounds(pos, 4)
        return struct.unpack_from('<i', self.data, pos)[0]

    def string(self, pos):
        lo, hi = self.chunks['STRG']
        self.bounds(pos, 1, lo, hi)
        end = self.data.find(b'\0', pos, hi)
        require(end >= pos, 'unterminated STRG string')
        return self.data[pos:end].decode('utf-8')

    def table(self, pos, lo, hi):
        self.bounds(pos, 4, lo, hi)
        count = self.u32(pos)
        self.bounds(pos + 4, count * 4, lo, hi)
        return [self.u32(pos + 4 + i * 4) for i in range(count)]

    def codes(self):
        lo, hi = self.chunks['CODE']
        offsets = self.table(lo, lo, hi)
        result = []
        for idx, pos in enumerate(offsets):
            self.bounds(pos, 20, lo + 4 + len(offsets) * 4, hi)
            length = self.u32(pos + 4)
            start = pos + 12 + self.i32(pos + 12)
            self.bounds(start, length, lo, hi)
            require(length % 4 == 0, 'unaligned CODE length')
            result.append(dict(id=idx, name=self.string(self.u32(pos)), record_offset=pos,
                               start=start, length=length,
                               metadata_raw=[self.u32(pos + 8), self.u32(pos + 16)],
                               sha256=hashlib.sha256(self.data[start:start + length]).hexdigest(),
                               references=[], owners=[], stage='indexed'))
        spans = sorted((c['start'], c['start'] + c['length'], c['id']) for c in result)
        require(all(a[1] <= b[0] for a, b in zip(spans, spans[1:])), 'overlapping CODE bodies')
        return result

    def references(self, codes, tag):
        lo, hi = self.chunks[tag]
        if tag == 'VARI':
            self.bounds(lo, 12, lo, hi)
            require((hi - lo - 12) % 20 == 0, 'partial VARI record')
            count, start, stride = (hi - lo - 12) // 20, lo + 12, 20
        else:
            count, start, stride = self.u32(lo), lo + 4, 12
        self.bounds(start, count * stride, lo, hi)
        spans = sorted((c['start'], c['start'] + c['length'], c['id']) for c in codes)
        starts = [s[0] for s in spans]
        records, seen = [], set()
        for idx in range(count):
            pos = start + idx * stride
            npos = pos + (12 if tag == 'VARI' else 4)
            occurrences, first = self.u32(npos), self.u32(npos + 4)
            name = self.string(self.u32(pos))
            rec = dict(id=idx, name=name, record_offset=pos, occurrence_count=occurrences,
                       first_occurrence_raw=first, occurrences=[])
            if tag == 'VARI':
                rec.update(instance_raw=self.i32(pos + 4), variable_id_raw=self.i32(pos + 8))
            require(occurrences <= (self.chunks['CODE'][1] - self.chunks['CODE'][0]) // 4,
                    'impossible occurrence count')
            cur = first
            for ordinal in range(occurrences):
                si = bisect.bisect_right(starts, cur) - 1
                require(si >= 0, 'occurrence before CODE bodies')
                a, b, code_id = spans[si]
                self.bounds(cur, 8, a, b)
                require((cur - a) % 4 == 0, 'unaligned reference')
                require(cur not in seen, f'duplicate/cyclic {tag} occurrence at {cur:#x}')
                seen.add(cur)
                raw = self.u32(cur + 4)
                ref = dict(kind=tag, symbol_id=idx, name=name, offset=cur,
                           code_offset=cur - a, instruction_word_raw=self.u32(cur),
                           reference_word_raw=raw)
                codes[code_id]['references'].append(ref)
                rec['occurrences'].append(dict(offset=cur, code_id=code_id))
                if ordinal + 1 < occurrences:
                    delta = raw & 0xffffff
                    delta = delta - 0x1000000 if delta & 0x800000 else delta
                    require(delta != 0, 'zero occurrence delta')
                    cur += delta
            records.append(rec)
        return dict(header_raw=[self.u32(lo + i * 4) for i in range(3 if tag == 'VARI' else 1)],
                    records=records, trailing_offset=start + count * stride,
                    trailing_bytes=hi - (start + count * stride))

    def objects(self, codes):
        lo, hi = self.chunks['OBJT']
        offsets = self.table(lo, lo, hi)
        require(offsets == sorted(set(offsets)), 'OBJT pointers not increasing')
        result = []
        for idx, pos in enumerate(offsets):
            end = offsets[idx + 1] if idx + 1 < len(offsets) else hi
            self.bounds(pos, 68, lo + 4 + len(offsets) * 4, end)
            obj = dict(id=idx, name=self.string(self.u32(pos)), record_offset=pos,
                       sprite_id=self.i32(pos + 4), parent_id=self.i32(pos + 24), events=[])
            evpos = pos + 80 + self.u32(pos + 64) * 8
            for event_type, listpos in enumerate(self.table(evpos, pos, end)):
                for ep in self.table(listpos, pos, end):
                    self.bounds(ep, 8, pos, end)
                    subtype = self.i32(ep)
                    event = dict(type=event_type, subtype=subtype, offset=ep, actions=[])
                    for order, ap in enumerate(self.table(ep + 4, pos, end)):
                        self.bounds(ap, 56, pos, end)
                        cid = self.i32(ap + 32)
                        require(cid == -1 or 0 <= cid < len(codes), 'bad action CODE id')
                        event['actions'].append(dict(order=order, offset=ap, code_id=cid,
                                                     words_raw=[self.u32(ap + i * 4) for i in range(14)]))
                        if cid >= 0:
                            codes[cid]['owners'].append(dict(kind='OBJT', object_id=idx,
                                object_name=obj['name'], event_type=event_type,
                                subtype=subtype, action_order=order, action_offset=ap))
                    obj['events'].append(event)
            result.append(obj)
        return result

    def rooms(self, codes):
        lo, hi = self.chunks['ROOM']
        offsets = self.table(lo, lo, hi)
        rooms = []
        for idx, pos in enumerate(offsets):
            self.bounds(pos, 88, lo, hi)
            room = dict(id=idx, name=self.string(self.u32(pos)), record_offset=pos,
                        instances=[])
            # GMS16 ROOM fixed header: creation code +32, objects pointer +48.
            cid = self.i32(pos + 32)
            require(cid == -1 or 0 <= cid < len(codes), 'bad room creation CODE')
            if cid >= 0:
                codes[cid]['owners'].append(dict(kind='ROOM', room_id=idx, room_name=room['name']))
            ipos = self.u32(pos + 48)
            for ip in self.table(ipos, lo, hi):
                self.bounds(ip, 36, lo, hi)
                cid = self.i32(ip + 16)
                require(cid == -1 or 0 <= cid < len(codes), 'bad instance creation CODE')
                instance = dict(offset=ip, object_id=self.i32(ip + 8),
                                instance_id=self.i32(ip + 12), code_id=cid)
                room['instances'].append(instance)
                if cid >= 0:
                    codes[cid]['owners'].append(dict(kind='ROOM_INSTANCE', room_id=idx,
                        room_name=room['name'], **instance))
            rooms.append(room)
        return rooms


def analyze(data, expected_sha=SHA256):
    digest = hashlib.sha256(data).hexdigest()
    require(digest == expected_sha, 'input SHA-256 mismatch')
    r = Reader(data)
    version = data[r.chunks['GEN8'][0] + 1]
    require(version == 16, 'unsupported bytecode version')
    codes = r.codes()
    variables = r.references(codes, 'VARI')
    functions = r.references(codes, 'FUNC')
    objects = r.objects(codes)
    rooms = r.rooms(codes)
    for c in codes:
        c['references'].sort(key=lambda v: v['offset'])
        if c['references']:
            c['stage'] = 'references-resolved'
    summary = dict(code_count=len(codes), variable_records=len(variables['records']),
        function_records=len(functions['records']), object_count=len(objects), room_count=len(rooms),
        variable_occurrences=sum(v['occurrence_count'] for v in variables['records']),
        function_occurrences=sum(v['occurrence_count'] for v in functions['records']),
        code_without_direct_owner=[c['id'] for c in codes if not c['owners']],
        semantics_recovered=0, behavior_verified=0)
    return dict(schema_version=1, input_sha256=digest, bytecode_version=version,
                summary=summary, codes=codes, variables=variables, functions=functions,
                objects=objects, rooms=rooms)


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('input', type=Path)
    p.add_argument('--output', type=Path, required=True)
    args = p.parse_args()
    result = analyze(args.input.read_bytes())
    args.output.mkdir(parents=True, exist_ok=True)
    (args.output / 'ledger.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps(result['summary'], indent=2))


if __name__ == '__main__':
    main()
