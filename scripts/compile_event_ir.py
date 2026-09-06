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
        if op in ('pushi', 'push', 'pushbltn', 'pushglb'):
            if 'value' in i:
                require(i['type1'] in (0, 2, 15) and isinstance(i['value'], (int, float)),
                        where + ': unsupported numeric type')
                row.update(op='constant', value=i['value'])
            else:
                require(i['type1'] == 5, where + ': unsupported push (including strings)')
                row.update(op='load', name=i['reference']['name'], selector=i['instance_raw'],
                           array=i['reference_type'] == 0)
                require(i['reference_type'] in (0, 160), where + ': unsupported reference mode')
        elif op == 'pop':
            require(i['type1'] == 5 and i['type2'] in (0, 2, 5), where + ': unsupported store type')
            require(i['reference_type'] in (0, 160), where + ': unsupported reference mode')
            row.update(op='store', name=i['reference']['name'], selector=i['instance_raw'],
                       array=i['reference_type'] == 0)
        elif op == 'conv':
            require(i['type1'] in (0, 2, 4, 5) and i['type2'] in (0, 2, 4, 5),
                    where + ': unsupported conversion')
            row.update(op='cast', to=i['type2'])
        elif op in ('add', 'sub', 'cmp'):
            require(i['type1'] in (0, 2, 5) and i['type2'] in (0, 2, 5),
                    where + ': unsupported arithmetic type')
            # Numeric f64 subset; no integer overflow/wrapping contract yet.
            row.update(op=op)
            if op == 'cmp':
                require(i['comparison'] in range(1, 7), where + ': unsupported comparison')
                row['comparison'] = i['comparison']
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
    for o in selected:
        require(o['parent_id'] < 0, 'inherited events not yet supported: ' + o['name'])
        events = []
        for e in o['events']:
            require(all(a['code_id'] >= 0 for a in e['actions']), 'non-CODE action unsupported')
            events.append(dict(event_type=e['type'], subtype=e['subtype'],
                               codes=[a['code_id'] for a in e['actions']]))
        result.append(dict(id=o['id'], name=o['name'], sprite=o['sprite_id'],
                           depth=reader.i32(o['record_offset'] + 20), events=events))
    return dict(schema=1, source_sha256=SHA256, numeric_model='finite-f64-subset',
                objects=result, codes=[lower(codes[c], disassemble(reader, codes[c])) for c in ids])


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
