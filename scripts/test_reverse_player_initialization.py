import unittest
from player_initialization import collect_sources


def instruction(offset, name, op='pushglb', scope=-5, kind=160):
    return dict(offset=offset,mnemonic=op,instance_raw=scope,reference_type=kind,
                reference=dict(kind='VARI', name=name))


def code(idx, instructions):
    return dict(id=idx, name=f'CODE{idx}', sha256=str(idx), owners=[], instructions=instructions)


class GlobalSourceTests(unittest.TestCase):
    def test_all_writer_sites_and_missing_create_are_explicit(self):
        codes=[code(0,[instruction(4,'health','pop')]),
               code(1,[instruction(100,'health'),instruction(104,'maxhp')]),
               code(2,[instruction(200,'maxhp','pop'),instruction(208,'maxhp','pop')])]
        rows=collect_sources(codes,{0,1})
        self.assertEqual([r['name'] for r in rows],['health','maxhp'])
        self.assertEqual(rows[0]['player_create_write_offsets'],[4])
        self.assertEqual(rows[1]['player_create_write_offsets'],[])
        self.assertEqual(rows[1]['direct_global_writes'][0]['offsets'],[200,208])
        self.assertFalse(rows[1]['initialization_order_verified'])

    def test_same_named_self_is_not_a_global_initializer(self):
        rows=collect_sources([code(0,[instruction(4,'x','pop',-1)]),code(1,[instruction(100,'x')])],{0,1})
        self.assertEqual(len(rows),1)
        self.assertEqual(rows[0]['direct_global_writes'],[])
        self.assertEqual(rows[0]['other_scope_or_indirect_writes'][0]['offsets'],[4])

    def test_only_cohort_reads_define_required_fields(self):
        rows=collect_sources([code(0,[]),code(1,[instruction(100,'needed')]),code(2,[instruction(200,'unrelated')])],{0,1})
        self.assertEqual([r['name'] for r in rows],['needed'])

    def test_indirect_global_is_not_silently_called_direct(self):
        rows=collect_sources([code(0,[]),code(1,[instruction(100,'x')]),code(2,[instruction(200,'x','pop',0,0)])],{0,1})
        self.assertEqual(rows[0]['direct_global_writes'],[])
        self.assertEqual(rows[0]['other_scope_or_indirect_writes'][0]['offsets'],[200])

class OriginalInputTests(unittest.TestCase):
    def test_complete_original_source_census_matches_checked_in_contract(self):
        import hashlib, json
        from player_initialization import ROOT, build
        expected = json.loads((ROOT/'reconstruction/contracts/player-initialization.json').read_text())
        binding = expected.pop('player_create')
        actual = build((ROOT/'assets/game.droid').read_bytes())
        self.assertEqual(actual, expected)
        self.assertEqual(actual['scanned_code_count'],1354)
        self.assertEqual(len(actual['cohort_code_ids']),24)
        self.assertEqual(actual['required_global_count'],22)
        self.assertEqual(actual['not_written_by_player_create'],[
            'assaultriflelevel','boomeranglevel','energywavebought',
            'healthregenbought','maxhp','swordsound','timeplayed'])
        from reverse_code import Reader
        reader = Reader((ROOT/'assets/game.droid').read_bytes())
        codes = reader.codes()
        reader.objects(codes)
        self.assertEqual(binding['code_id'],0)
        self.assertEqual(binding['code_name'],codes[0]['name'])
        self.assertEqual(binding['bytecode_sha256'],codes[0]['sha256'])
        self.assertEqual(binding['owners'],codes[0]['owners'])
        self.assertEqual(hashlib.sha256(binding['gml'].encode()).hexdigest(),binding['gml_sha256'])


if __name__ == '__main__':unittest.main()
