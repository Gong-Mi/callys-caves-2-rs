"""Whole-body provenance and exhaustive direct spawn dependency contracts.

These checks are static evidence, not an execution of the GameMaker runner.
"""
import copy
import hashlib
import json
from pathlib import Path
import re
import unittest
from reverse_code import Reader, SHA256

ROOT = Path(__file__).resolve().parents[1]


def verify_contract(contract, raw):
    assert contract['asset_sha256'] == SHA256 == hashlib.sha256(raw).hexdigest()
    reader = Reader(raw)
    codes = reader.codes()
    objects = reader.objects(codes)
    player = objects[contract['object_id']]
    assert player['name'] == contract['object_name'] == 'obj_player'
    events = {e['subtype']: [a['code_id'] for a in e['actions']]
              for e in player['events'] if e['type'] == 2}

    def verify_body(binding):
        code = codes[binding['code_id']]
        assert code['name'] == binding['code_name']
        assert code['sha256'] == binding['bytecode_sha256']
        assert hashlib.sha256(binding['gml'].encode()).hexdigest() == binding['gml_sha256']

    assert sorted(b['alarm'] for b in contract['bindings']) == [0, 1]
    spawn_names = set()
    for binding in contract['bindings']:
        assert events[binding['alarm']] == [binding['code_id']]
        verify_body(binding)
        calls = re.findall(r'instance_create\([^;]*?,\s*(obj_\w+)\)', binding['gml'])
        assert len(calls) == binding['gml'].count('instance_create(')
        spawn_names.update(calls)
    deps = contract['direct_spawn_dependencies']
    assert len(deps) == len(spawn_names) == 12
    assert {d['object_name'] for d in deps} == spawn_names
    for dep in deps:
        obj = objects[dep['object_id']]
        assert obj['name'] == dep['object_name']
        assert obj['parent_id'] == dep['parent_id']
        create_ids = [a['code_id'] for e in obj['events']
                      if e['type'] == 0 and e['subtype'] == 0 for a in e['actions']]
        assert [b['code_id'] for b in dep['direct_create']] == create_ids
        for binding in dep['direct_create']:
            verify_body(binding)
        # Provenance export does not infer Rust implementation status.
        assert 'rust_create_implemented' not in dep
        assert dep['runtime_verified'] is False


class CombatBindingTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.raw = (ROOT / 'assets/game.droid').read_bytes()
        cls.contract = json.loads((ROOT / 'reconstruction/contracts/player-combat.json').read_text())

    def test_complete_methods_and_all_direct_create_bodies(self):
        verify_contract(self.contract, self.raw)

    def test_missing_spawn_dependency_rejected(self):
        contract = copy.deepcopy(self.contract)
        contract['direct_spawn_dependencies'].pop()
        with self.assertRaises(AssertionError):
            verify_contract(contract, self.raw)

    def test_changed_create_body_rejected(self):
        contract = copy.deepcopy(self.contract)
        contract['direct_spawn_dependencies'][0]['direct_create'][0]['gml'] += '\nx = 123;\n'
        with self.assertRaises(AssertionError):
            verify_contract(contract, self.raw)

    def test_wrong_parent_rejected(self):
        contract = copy.deepcopy(self.contract)
        contract['direct_spawn_dependencies'][0]['parent_id'] = 123456
        with self.assertRaises(AssertionError):
            verify_contract(contract, self.raw)

    def test_wrong_alarm_binding_rejected(self):
        contract = copy.deepcopy(self.contract)
        contract['bindings'][0]['code_id'] = 10
        with self.assertRaises(AssertionError):
            verify_contract(contract, self.raw)

    def test_duplicate_dependency_rejected(self):
        contract = copy.deepcopy(self.contract)
        contract['direct_spawn_dependencies'][-1] = copy.deepcopy(contract['direct_spawn_dependencies'][0])
        with self.assertRaises(AssertionError):
            verify_contract(contract, self.raw)


if __name__ == '__main__':
    unittest.main()
