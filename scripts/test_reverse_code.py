import hashlib
from pathlib import Path
import struct
import unittest

from reverse_code import analyze, FormatError, Reader

ASSET = Path(__file__).resolve().parents[1] / 'assets/game.droid'


class LedgerTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.data = ASSET.read_bytes()
        cls.reader = Reader(cls.data)
        cls.ledger = analyze(cls.data)

    def mutated(self, pos, value):
        data = bytearray(self.data)
        struct.pack_into('<I', data, pos, value & 0xffffffff)
        return bytes(data)

    def parse_mutation(self, pos, value):
        data = self.mutated(pos, value)
        return analyze(data, hashlib.sha256(data).hexdigest())

    def test_real_asset_complete_counts(self):
        s = self.ledger['summary']
        for key, value in dict(code_count=1354, variable_records=2088,
                               function_records=99, object_count=191, room_count=114,
                               variable_occurrences=52459, function_occurrences=14731).items():
            self.assertEqual(s[key], value, key)
        self.assertEqual(s['code_without_direct_owner'], [])
        self.assertEqual(s['semantics_recovered'], 0)
        self.assertEqual(self.ledger['bytecode_version'], 16)

    def test_vari_header_is_not_record_count(self):
        v = self.ledger['variables']
        self.assertEqual(v['header_raw'], [691, 691, 7])
        self.assertEqual(len(v['records']), 2088)
        self.assertEqual(sum(r['occurrence_count'] for r in v['records'][691:]), 13196)
        self.assertEqual(v['trailing_bytes'], 0)

    def test_reference_counts_and_ranges(self):
        refs = [r for c in self.ledger['codes'] for r in c['references']]
        self.assertEqual(len(refs), 52459 + 14731)
        self.assertEqual(len({r['offset'] for r in refs}), len(refs))
        for c in self.ledger['codes']:
            for r in c['references']:
                self.assertGreaterEqual(r['offset'], c['start'])
                self.assertLessEqual(r['offset'] + 8, c['start'] + c['length'])

    def test_owner_is_stored_action_id_not_name_guess(self):
        player = self.ledger['codes'][0]
        self.assertEqual(player['name'], 'gml_Object_obj_player_Create_0')
        self.assertEqual(len(player['owners']), 1)
        owner = player['owners'][0]
        self.assertEqual((owner['object_id'], owner['event_type'], owner['subtype']), (0, 0, 0))
        self.assertEqual(self.reader.i32(owner['action_offset'] + 32), 0)

    def test_hash_gate(self):
        with self.assertRaisesRegex(FormatError, 'SHA-256'):
            analyze(self.data + b'x')

    def test_form_size(self):
        with self.assertRaisesRegex(FormatError, 'FORM size'):
            Reader(self.mutated(4, 0))

    def test_truncated_chunk(self):
        with self.assertRaises(FormatError):
            Reader(self.mutated(12, len(self.data)))

    def test_bad_code_pointer(self):
        with self.assertRaises(FormatError):
            self.parse_mutation(self.reader.chunks['CODE'][0] + 4, 0)

    def test_bad_code_relative_pointer(self):
        with self.assertRaises(FormatError):
            self.parse_mutation(self.ledger['codes'][0]['record_offset'] + 12, 0x7fffffff)

    def test_variable_occurrence_outside_code(self):
        rec = next(r for r in self.ledger['variables']['records'] if r['occurrence_count'] > 0)
        pos = rec['record_offset'] + 16
        with self.assertRaises(FormatError):
            self.parse_mutation(pos, 0)

    def test_zero_reference_delta(self):
        rec = next(r for r in self.ledger['variables']['records'] if r['occurrence_count'] > 1)
        with self.assertRaisesRegex(FormatError, 'zero occurrence delta'):
            self.parse_mutation(rec['first_occurrence_raw'] + 4, 0)

    def test_bad_event_code_id(self):
        pos = self.ledger['codes'][0]['owners'][0]['action_offset'] + 32
        with self.assertRaisesRegex(FormatError, 'bad action CODE'):
            self.parse_mutation(pos, len(self.ledger['codes']))

    def test_wrong_version(self):
        pos = self.reader.chunks['GEN8'][0]
        with self.assertRaisesRegex(FormatError, 'unsupported bytecode version'):
            self.parse_mutation(pos, 0x0e01)

    def test_player_alarm8_exact_constant_body(self):
        body = self.ledger['codes'][3]['constant_prefix']
        self.assertTrue(body['whole_body'])
        self.assertEqual([(s['scope'], s['name'], s['value']) for s in body['assignments']],
                         [('self', 'invulnerable', 0), ('self', 'invulnerable2', 0)])

    def test_player_create_stops_before_nonconstant_code(self):
        body = self.ledger['codes'][0]['constant_prefix']
        self.assertFalse(body['whole_body'])
        self.assertEqual(len(body['assignments']), 9)
        self.assertEqual(body['stop_offset'], self.ledger['codes'][0]['start'] + 108)
        self.assertEqual(body['assignments'][-1]['scope'], 'global')

    def test_constant_decoder_does_not_guess_array_assignment(self):
        c = self.ledger['codes'][3]
        data = self.mutated(c['start'] + 8, 0x000017e4)
        result = analyze(data, hashlib.sha256(data).hexdigest())
        self.assertEqual(result['codes'][3]['constant_prefix']['assignments'], [])
        self.assertFalse(result['codes'][3]['constant_prefix']['whole_body'])

    def test_deterministic(self):
        self.assertEqual(analyze(self.data), self.ledger)


if __name__ == '__main__':
    unittest.main()
