#!/usr/bin/env python3
"""Compile pinned CODE words to numeric stack IR; never consumes/re-writes GML.

This is a deliberately bounded bytecode16 backend, not an all-GML translator.
One unsupported instruction rejects the entire selected object export.
"""
import argparse
import hashlib
import json
from pathlib import Path
from reverse_code import Reader, SHA256, require
from reverse_instructions import disassemble

DEFAULT_OBJECTS = ('obj_introduction', 'obj_phone', 'obj_logo')


def lower(code, instructions):
    out = []
    for i in instructions:
        where = f"CODE {code['id']} @{i['offset']:#x}"
        op = i['mnemonic']
        row = dict(offset=i['offset'], code_offset=i['offset'] - code['start'],
                   words_raw=i['words_raw'])
        if op in ('pushi', 'push', 'pushbltn', 'pushglb', 'pushloc'):
            if 'value' in i:
                require(i['type1'] in (0, 2, 15) and isinstance(i['value'], (int, float)),
                        where + ': unsupported numeric type')
                row.update(op='constant', value=i['value'])
            elif i['type1'] == 6:
                # String literal: STRG id preserved; host resolves the text.
                row.update(op='string', string_id=i['string_id'])
            else:
                require(i['type1'] == 5, where + ': unsupported push (including strings)')
                # pushloc is a per-call local; the VM hosts locals separately.
                if op == 'pushloc':
                    row.update(op='load_local', name=i['reference']['name'])
                else:
                    row.update(op='load', name=i['reference']['name'], selector=i['instance_raw'],
                               array=i['reference_type'] == 0, other=i['reference_type'] == 128)
                    require(i['reference_type'] in (0, 128, 160), where + ': unsupported reference mode')
        elif op == 'pop':
            # Local-variable pop: type1=5 with array-scope marker and instance -7.
            if i['type1'] == 5 and i.get('reference_type') == 160 and i.get('instance_raw') == -7:
                row.update(op='store_local', name=i['reference']['name'])
            else:
                # type1/type2 record the value type pushed for the store.
                require(i['type1'] in (2, 5) and i['type2'] in (0, 2, 5, 6), where + ': unsupported store type')
                require(i['reference_type'] in (0, 128, 160), where + ': unsupported reference mode')
                row.update(op='store', name=i['reference']['name'], selector=i['instance_raw'],
                           array=i['reference_type'] == 0, other=i['reference_type'] == 128)
        elif op == 'conv':
            # (6,5) string->value handled by host at Cast time via string_id stack.
            require(i['type1'] in (0, 2, 4, 5, 6) and i['type2'] in (0, 2, 4, 5),
                    where + ': unsupported conversion')
            row.update(op='cast', to=i['type2'])
        elif op in ('add', 'sub', 'mul', 'div', 'cmp'):
            # type1/type2 are operand type hints; the VM is uniformly f64.
            # (5,6)/(6,5) pairs compare against strings the host resolves.
            require(i['type1'] in (0, 2, 5, 6) and i['type2'] in (0, 2, 5, 6),
                    where + ': unsupported arithmetic type')
            # Numeric f64 subset; no integer overflow/wrapping contract yet.
            row.update(op=op)
            if op == 'cmp':
                require(i['comparison'] in range(1, 7), where + ': unsupported comparison')
                row['comparison'] = i['comparison']
        elif op == 'dup':
            # Duplicates the top stack slot (variable reference chains).
            require(i['type1'] in (0, 2, 5), where + ': unsupported dup type')
            row.update(op='dup')
        elif op == 'and':
            # Short-circuit-free bitwise/boolean and on i32 pair.
            require(i['type1'] == 2 and i['type2'] == 2, where + ': unsupported and type')
            row.update(op='and')
        elif op == 'not':
            require(i['type1'] == 4 and i['type2'] in (0, 2, 4), where + ': unsupported not type')
            row.update(op='not')
        elif op in ('b', 'bt', 'bf', 'pushenv', 'popenv'):
            require(not i.get('popenv_exit_magic'), where + ': magic environment cleanup unsupported')
            row.update(op=op, target=i['target'])
        elif op == 'call':
            row.update(op='call', name=i['reference']['name'], argc=i['argc'])
        elif op in ('popz', 'exit'):
            row['op'] = op
        else:
            raise ValueError(where + ': unsupported instruction ' + op)
        out.append(row)
    return dict(id=code['id'], name=code['name'], start=code['start'],
                end=code['start'] + code['length'], sha256=code['sha256'], instructions=out)


def compile_asset(data, names=DEFAULT_OBJECTS):
    require(hashlib.sha256(data).hexdigest() == SHA256, 'game.droid SHA256 mismatch')
    reader = Reader(data)
    codes = reader.codes()
    reader.references(codes, 'VARI')
    reader.references(codes, 'FUNC')
    objects = reader.objects(codes)
    selected = [o for o in objects if o['name'] in names]
    require(set(names) == {o['name'] for o in selected}, 'unknown object selection')
    ids = sorted({a['code_id'] for o in selected for e in o['events'] for a in e['actions']
                  if a['code_id'] >= 0})
    result = []
    # ROOM creation-code bindings: instance code ids resolve to their room and
    # object so the host can run the exact original creation body per instance.
    rooms = reader.rooms(codes)
    room_bindings = []
    for room in rooms:
        cid = None
        for inst in room['instances']:
            if inst['code_id'] >= 0:
                room_bindings.append(dict(room_id=room['id'], room_name=room['name'],
                    object_id=inst['object_id'], instance_id=inst['instance_id'],
                    code_id=inst['code_id']))
    by_id = {o['id']: o for o in objects}
    for o in selected:
        # Inheritance chain is exported verbatim; the host resolves inherited
        # events at load time. Compiler does not silently flatten.
        chain = []
        cur = o
        while cur['parent_id'] >= 0:
            chain.append(cur['parent_id'])
            cur = by_id.get(cur['parent_id'])
            require(cur is not None, 'unknown parent in chain for ' + o['name'])
        events = []
        for e in o['events']:
            require(all(a['code_id'] >= 0 for a in e['actions']), 'non-CODE action unsupported')
            events.append(dict(event_type=e['type'], subtype=e['subtype'],
                               codes=[a['code_id'] for a in e['actions']]))
        result.append(dict(id=o['id'], name=o['name'], sprite=o['sprite_id'],
                           depth=reader.i32(o['record_offset'] + 20),
                           parent=o['parent_id'], parent_chain=chain, events=events))
    # Room creation-code bodies are part of the same executable surface.
    ids = set(ids) | {b['code_id'] for b in room_bindings}
    # Export STRG string table so strings referenced by string_id resolve directly.
    lo, hi = reader.chunks['STRG']
    ptrs = reader.table(lo, lo, hi)
    strings = []
    for pos in ptrs:
        slen = reader.u32(pos)
        strings.append(reader.data[pos + 4 : pos + 4 + slen].decode('utf-8', errors='replace'))
    return dict(schema=1, source_sha256=SHA256, numeric_model='finite-f64-subset',
                string_table=strings, objects=result, room_bindings=room_bindings,
                codes=[lower(codes[c], disassemble(reader, codes[c])) for c in sorted(ids)])


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('asset', type=Path)
    p.add_argument('output', type=Path)
    p.add_argument('--objects', nargs='+', default=DEFAULT_OBJECTS)
    a = p.parse_args()
    bundle = compile_asset(a.asset.read_bytes(), a.objects)
    a.output.parent.mkdir(parents=True, exist_ok=True)
    a.output.write_text(json.dumps(bundle, ensure_ascii=False, indent=2) + '\n')
    print(f"compiled {len(bundle['codes'])} CODE bodies; {sum(len(c['instructions']) for c in bundle['codes'])} instructions")


if __name__ == '__main__':
    main()
