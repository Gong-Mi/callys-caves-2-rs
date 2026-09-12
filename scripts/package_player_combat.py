#!/usr/bin/env python3
"""Bind combat methods and every literal direct spawn Create to original input.

This records dependencies, NOT implemented/behavior-verified Create callbacks.
Run with a verified restored-source directory from Recover original GML.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
from reverse_code import Reader, SHA256

ROOT = Path(__file__).resolve().parents[1]


def package(source):
    raw = (ROOT / 'assets/game.droid').read_bytes()
    assert hashlib.sha256(raw).hexdigest() == SHA256
    reader = Reader(raw)
    codes = reader.codes()
    objects = reader.objects(codes)
    index = {e['id']: e for e in json.loads((source / 'index.json').read_text())}

    def binding(code_id):
        entry = index[code_id]
        text = (source / entry['file']).read_text()
        assert hashlib.sha256(text.encode()).hexdigest() == entry['gml_sha256']
        assert entry['roundtrip']['assembly_equal']
        assert entry['roundtrip']['redecompiled_text_equal']
        return dict(code_id=code_id, code_name=codes[code_id]['name'],
                    bytecode_sha256=codes[code_id]['sha256'],
                    gml_sha256=entry['gml_sha256'], gml=text)

    methods = [dict(alarm=alarm, **binding(code_id)) for alarm, code_id in [(0, 11), (1, 10)]]
    names = set()
    for method in methods:
        calls = re.findall(r'instance_create\([^;]*?,\s*(obj_\w+)\)', method['gml'])
        assert len(calls) == method['gml'].count('instance_create('), 'unresolved spawn target'
        names.update(calls)
    dependencies = []
    for name in sorted(names):
        obj, = [obj for obj in objects if obj['name'] == name]
        create_ids = [action['code_id'] for event in obj['events']
                      if event['type'] == 0 and event['subtype'] == 0
                      for action in event['actions']]
        dependencies.append(dict(object_id=obj['id'], object_name=name,
                                 parent_id=obj['parent_id'],
                                 direct_create=[binding(code_id) for code_id in create_ids],
                                 runtime_verified=False))
    return dict(asset_sha256=SHA256, object_id=0, object_name='obj_player',
                execution_boundary='host-backed methods; synchronous Create required; no legacy-loop integration',
                bindings=methods, direct_spawn_dependencies=dependencies)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('restored_source', type=Path)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    result = package(args.restored_source)
    args.output.write_text(json.dumps(result, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps(dict(methods=len(result['bindings']),
                          direct_spawn_objects=len(result['direct_spawn_dependencies']),
                          direct_create_bodies=sum(len(d['direct_create']) for d in result['direct_spawn_dependencies']))))
