"""Whole-source startup and transitive direct Create provenance."""
import copy,hashlib,json,unittest
from package_startup import ROOT,ROOT_CODES,spawn_names
from reverse_code import Reader,SHA256
from generate_player_startup import StrictGrammarTests  # included by unittest discovery


def verify(contract,raw):
    assert contract['asset_sha256']==hashlib.sha256(raw).hexdigest()==SHA256
    assert contract['root_code_ids']==ROOT_CODES
    reader=Reader(raw);codes=reader.codes();objects=reader.objects(codes)
    bindings={b['code_id']:b for b in contract['bindings']}
    assert len(bindings)==len(contract['bindings'])
    for cid,b in bindings.items():
        assert codes[cid]['name']==b['code_name']
        assert codes[cid]['sha256']==b['bytecode_sha256']
        assert codes[cid]['owners']==b['owners']
        assert hashlib.sha256(b['gml'].encode()).hexdigest()==b['gml_sha256']
    deps={o['object_name']:o for o in contract['spawn_objects']}
    assert len(deps)==len(contract['spawn_objects'])
    queue=set();visited=set();used=set(ROOT_CODES)
    for cid in ROOT_CODES:queue.update(spawn_names(bindings[cid]['gml']))
    while queue:
        name=queue.pop()
        if name in visited:continue
        visited.add(name);dep=deps[name];obj=objects[dep['object_id']]
        assert obj['name']==name and obj['parent_id']==dep['parent_id']
        ids=[a['code_id'] for e in obj['events'] if e['type']==0 and e['subtype']==0 for a in e['actions']]
        assert ids==dep['direct_create_code_ids']
        used.update(ids)
        for cid in ids:queue.update(spawn_names(bindings[cid]['gml'])-visited)
    assert visited==deps.keys() and used==bindings.keys()
    assert contract['runtime_verified'] is False


class StartupBindingTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.raw=(ROOT/'assets/game.droid').read_bytes()
        cls.contract=json.loads((ROOT/'reconstruction/contracts/startup.json').read_text())
    def test_exact_complete_original_closure(self):
        verify(self.contract,self.raw)
        self.assertEqual([b['code_id'] for b in self.contract['bindings']],[17,365,528,531,537,548])
        self.assertEqual(len(self.contract['spawn_objects']),9)
        self.assertEqual([o['object_name'] for o in self.contract['spawn_objects'] if not o['direct_create_code_ids']],
                         ['obj_jumpbutton','obj_pausebutton','obj_phone','obj_shootbutton','obj_swordbutton'])
        self.assertTrue(all(o['parent_id']==-100 for o in self.contract['spawn_objects']))
        from generate_player_startup import translate
        source = next(b['gml'] for b in self.contract['bindings'] if b['code_id']==17)
        self.assertEqual(translate(source.encode()), (ROOT/'crates/core/src/original_player_startup.rs').read_text())
    def test_missing_transitive_phone_rejected(self):
        c=copy.deepcopy(self.contract);c['spawn_objects']=[o for o in c['spawn_objects'] if o['object_name']!='obj_phone']
        with self.assertRaises(KeyError):verify(c,self.raw)
    def test_wrong_parent_rejected(self):
        c=copy.deepcopy(self.contract);c['spawn_objects'][0]['parent_id']=0
        with self.assertRaises(AssertionError):verify(c,self.raw)
    def test_no_create_object_cannot_invent_method(self):
        c=copy.deepcopy(self.contract)
        next(o for o in c['spawn_objects'] if o['object_name']=='obj_phone')['direct_create_code_ids']=[547]
        with self.assertRaises(AssertionError):verify(c,self.raw)
    def test_changed_gml_rejected(self):
        c=copy.deepcopy(self.contract);c['bindings'][0]['gml']+='\nglobal.maxhp=999;'
        with self.assertRaises(AssertionError):verify(c,self.raw)
    def test_duplicate_code_rejected(self):
        c=copy.deepcopy(self.contract);c['bindings'].append(c['bindings'][0])
        with self.assertRaises(AssertionError):verify(c,self.raw)
    def test_dynamic_target_not_silently_omitted(self):
        with self.assertRaises(AssertionError):spawn_names('instance_create(x,y,computed_target);')

if __name__=='__main__':unittest.main()
