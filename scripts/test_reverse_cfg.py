"""Structural CFG contracts. They do not execute GameMaker events."""
import unittest
from pathlib import Path

from reverse_code import analyze


def instruction(offset, opcode, **kwargs):
    return dict(offset=offset, size=4, opcode=opcode, words_raw=[opcode << 24], **kwargs)


def code(instructions, length=None):
    return dict(id=0, name='fixture', start=100,
                length=length if length is not None else len(instructions) * 4,
                instructions=instructions)


def cfg(c):
    from reverse_cfg import build_cfg
    return build_cfg(c)


class CFGTests(unittest.TestCase):
    def test_straight_line_one_block(self):
        result = cfg(code([instruction(100, 0x84), instruction(104, 0x45)]))
        self.assertEqual(len(result['blocks']), 1)
        block = result['blocks'][0]
        self.assertEqual(block['instruction_offsets'], [100, 104])
        self.assertEqual(block['edges'], [dict(target=108, kind='end')])

    def test_conditional_has_two_labeled_edges(self):
        result = cfg(code([instruction(100, 0xb8, target=108),
                           instruction(104, 0x84), instruction(108, 0x9d)]))
        self.assertEqual(result['blocks'][0]['edges'],
                         [dict(target=108, kind='false'), dict(target=104, kind='true')])

    def test_unconditional_jump_retains_unreachable_block(self):
        result = cfg(code([instruction(100, 0xb6, target=108),
                           instruction(104, 0x84), instruction(108, 0x9d)]))
        self.assertEqual(result['blocks'][0]['edges'], [dict(target=108, kind='jump')])
        self.assertEqual(result['unreachable_blocks'], [104])
        self.assertEqual([b['start'] for b in result['blocks']], [100, 104, 108])

    def test_backedge_not_confused_with_exit(self):
        result = cfg(code([instruction(100, 0x84), instruction(104, 0xb7, target=100)]))
        self.assertEqual(result['blocks'][0]['edges'],
                         [dict(target=100, kind='true'), dict(target=108, kind='false')])
        self.assertEqual(result['unreachable_blocks'], [])

    def test_environment_semantics_stay_explicit(self):
        result = cfg(code([instruction(100, 0xba, target=112), instruction(104, 0x84),
                           instruction(108, 0xbb, target=104), instruction(112, 0x9d)]))
        self.assertEqual([x['offset'] for x in result['environment_ops']], [100, 108])
        self.assertFalse(result['environment_runtime_verified'])
        self.assertNotEqual(result['blocks'][0]['edges'], [dict(target=104, kind='fallthrough')])

    def test_exit_terminates_block_without_fallthrough(self):
        result = cfg(code([instruction(100, 0x9d), instruction(104, 0x84)]))
        self.assertEqual(result['blocks'][0]['edges'], [dict(target=108, kind='exit')])
        self.assertEqual(result['unreachable_blocks'], [104])

    def test_empty_code_explicit(self):
        result = cfg(code([], 0))
        self.assertEqual(result['blocks'], [])
        self.assertEqual(result['entry'], result['exit'])

    def test_invalid_target_rejected(self):
        with self.assertRaises(ValueError):
            cfg(code([instruction(100, 0xb6, target=102)]))

    def test_gap_in_instruction_coverage_rejected(self):
        with self.assertRaises(ValueError):
            cfg(code([instruction(100, 0x84), instruction(108, 0x84)], 12))


class RealCFGTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        data = Path(__file__).resolve().parents[1] / 'assets/game.droid'
        cls.ledger = analyze(data.read_bytes())

    def test_every_instruction_belongs_to_exactly_one_block(self):
        for c in self.ledger['codes']:
            result = cfg(c)
            flattened = [o for b in result['blocks'] for o in b['instruction_offsets']]
            self.assertEqual(flattened, [i['offset'] for i in c['instructions']], c['name'])
            self.assertEqual(len(flattened), len(set(flattened)), c['name'])
            starts = {b['start'] for b in result['blocks']} | {result['exit']}
            self.assertTrue(all(e['target'] in starts for b in result['blocks'] for e in b['edges']))

    def test_all_encoded_destinations_are_represented(self):
        for c in self.ledger['codes']:
            result = cfg(c)
            by_offset = {o: b for b in result['blocks'] for o in b['instruction_offsets']}
            for ins in c['instructions']:
                if 'target' in ins:
                    self.assertIn(ins['target'], [e['target'] for e in by_offset[ins['offset']]['edges']], c['name'])

    def test_player_alarm8_remains_one_straight_line_block(self):
        result = cfg(self.ledger['codes'][3])
        self.assertEqual(len(result['blocks']), 1)
        self.assertEqual(result['environment_ops'], [])
        self.assertEqual(result['unreachable_blocks'], [])


if __name__ == '__main__':
    unittest.main()
