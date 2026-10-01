#!/usr/bin/env python3
"""Bind complete startup roots and transitive literal Create dependencies."""
import argparse
import hashlib
import json
from pathlib import Path
import re
from reverse_code import Reader, SHA256

ROOT=Path(__file__).resolve().parents[1]
ROOT_CODES=[17,365]


def spawn_names(text):
    names=re.findall(r'instance_create\([^;]*?,\s*(obj_\w+)\)',text)
    assert len(names)==text.count('instance_create('),'unresolved dynamic spawn target'
    return set(names)


def package(source):
    raw=(ROOT/'assets/game.droid').read_bytes()
    assert hashlib.sha256(raw).hexdigest()==SHA256
    reader=Reader(raw);codes=reader.codes();objects=reader.objects(codes)
    by_name={o['name']:o for o in objects}
    entries=json.loads((source/'index.json').read_text());index={r['id']:r for r in entries}
    assert len(index)==len(entries)==len(codes)
    bodies={}
    def bind(cid):
        if cid in bodies:return bodies[cid]
        entry=index[cid];text=(source/entry['file']).read_text()
        assert hashlib.sha256(text.encode()).hexdigest()==entry['gml_sha256']
        assert entry['roundtrip']['assembly_equal'] and entry['roundtrip']['redecompiled_text_equal']
        b=dict(code_id=cid,code_name=codes[cid]['name'],bytecode_sha256=codes[cid]['sha256'],
               gml_sha256=entry['gml_sha256'],gml=text,owners=codes[cid]['owners'])
        bodies[cid]=b;return b
    pending=set()
    for cid in ROOT_CODES:pending.update(spawn_names(bind(cid)['gml']))
    deps={}
    while pending:
        name=min(pending);pending.remove(name)
        if name in deps:continue
        obj=by_name[name]
        ids=[a['code_id'] for e in obj['events'] if e['type']==0 and e['subtype']==0 for a in e['actions']]
        deps[name]=dict(object_id=obj['id'],object_name=name,parent_id=obj['parent_id'],direct_create_code_ids=ids)
        for cid in ids:pending.update(spawn_names(bind(cid)['gml'])-deps.keys())
    return dict(asset_sha256=SHA256,root_code_ids=ROOT_CODES,
                bindings=[bodies[cid] for cid in sorted(bodies)],
                spawn_objects=[deps[name] for name in sorted(deps)],
                runtime_verified=False,
                boundary='complete literal Create dependency closure; no inferred inherited events, dynamic targets, startup scheduling or production platform implementation')


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('restored_source',type=Path);p.add_argument('--output',type=Path,required=True)
    args=p.parse_args();result=package(args.restored_source)
    args.output.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n')
    print(json.dumps(dict(code_ids=[b['code_id'] for b in result['bindings']],spawn_objects=len(result['spawn_objects']),no_direct_create=[o['object_name'] for o in result['spawn_objects'] if not o['direct_create_code_ids']])))
