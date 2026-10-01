"""Pin manual Rust callback translations to whole original CODE bodies."""
import hashlib
import json
from pathlib import Path
import struct
import unittest
from reverse_code import Reader, SHA256

ROOT = Path(__file__).resolve().parents[1]


class PlayerAlarmContractTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.raw = (ROOT / 'assets/game.droid').read_bytes()
        cls.reader = Reader(cls.raw)
        cls.codes = cls.reader.codes()
        cls.objects = cls.reader.objects(cls.codes)
        cls.contract = json.loads((ROOT / 'reconstruction/contracts/player-alarms.json').read_text())

    def test_all_nine_bindings_match_original_direct_events_and_whole_code(self):
        contract = self.contract
        self.assertEqual(hashlib.sha256(self.raw).hexdigest(), contract['asset_sha256'])
        self.assertEqual(contract['asset_sha256'], SHA256)
        player = self.objects[contract['object_id']]
        self.assertEqual(player['name'], contract['object_name'])
        events = {e['subtype']: [a['code_id'] for a in e['actions']]
                  for e in player['events'] if e['type'] == 2}
        bindings = contract['bindings']
        self.assertEqual(len(bindings), 9)
        self.assertEqual(len({b['alarm'] for b in bindings}), 9)
        for binding in bindings:
            self.assertEqual(events[binding['alarm']], [binding['code_id']])
            code = self.codes[binding['code_id']]
            self.assertEqual(code['name'], binding['code_name'])
            self.assertEqual(code['sha256'], binding['bytecode_sha256'])
            self.assertEqual(hashlib.sha256(binding['gml'].encode()).hexdigest(), binding['gml_sha256'])
        supported = {b['alarm'] for b in bindings}
        self.assertEqual(sorted(set(events) - supported), contract['not_restored_alarms'])
        self.assertEqual(sorted(set(range(12)) - set(events)), contract['absent_direct_alarms'])

    def test_player_sprite_constant_resolves_to_original_resource(self):
        pos = self.codes[4]['start']
        sprite_id = struct.unpack_from('<h', self.raw, pos)[0]
        lo, hi = self.reader.chunks['SPRT']
        sprite = self.reader.table(lo, lo, hi)[sprite_id]
        self.assertEqual(self.reader.string(self.reader.u32(sprite)), 'spr_player')
        self.assertEqual(sprite_id, 29)


if __name__ == '__main__':
    unittest.main()
