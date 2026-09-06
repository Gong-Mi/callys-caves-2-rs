#!/usr/bin/env python3
"""Static global read/write-site census; not initialization-order proof.

Exhaustively scans the pinned CODE universe. Normal -5 VARI references are
classified as direct globals; other same-name writes are preserved separately.
No CFG dominance, branch feasibility, dynamic selector or startup-order claim.
"""
import argparse
from collections import defaultdict
import hashlib
import json
from pathlib import Path
from reverse_code import analyze, SHA256

ROOT = Path(__file__).resolve().parents[1]


def collect_sources(codes, cohort):
    by_id = {c['id']: c for c in codes}
    assert len(by_id) == len(codes), 'duplicate CODE identity'
    assert set(cohort) <= by_id.keys() and 0 in cohort
    reads = defaultdict(lambda: defaultdict(list))
    writes = defaultdict(lambda: defaultdict(list))
    other = defaultdict(lambda: defaultdict(list))
    for c in sorted(codes, key=lambda c: c['id']):
        for i in c['instructions']:
            ref = i.get('reference', {})
            if ref.get('kind') != 'VARI':
                continue
            name = ref['name']
            direct = i.get('instance_raw') == -5 and i.get('reference_type') == 160
            if i['mnemonic'] == 'pop':
                (writes if direct else other)[name][c['id']].append(i['offset'])
            elif c['id'] in cohort and direct:
                assert i['mnemonic'].startswith('push'), 'unclassified global access'
                reads[name][c['id']].append(i['offset'])

    def sites(groups):
        return [dict(code_id=cid, code_name=by_id[cid]['name'],
                     bytecode_sha256=by_id[cid]['sha256'], owners=by_id[cid]['owners'],
                     offsets=offsets) for cid, offsets in sorted(groups.items())]

    return [dict(name=name, cohort_reads=sites(reads[name]),
                 player_create_write_offsets=writes[name].get(0, []),
                 direct_global_writes=sites(writes[name]),
                 other_scope_or_indirect_writes=sites(other[name]),
                 initialization_order_verified=False)
            for name in sorted(reads)]


def build(asset, restored_source=None):
    ledger = analyze(asset)
    codes = ledger['codes']
    contract_root = ROOT / 'reconstruction/contracts'
    simple = json.loads((contract_root / 'player-alarms.json').read_text())
    combat = json.loads((contract_root / 'player-combat.json').read_text())
    cohort = {0}
    for contract in (simple, combat):
        assert contract['asset_sha256'] == SHA256
        for b in contract['bindings']:
            assert codes[b['code_id']]['sha256'] == b['bytecode_sha256']
            cohort.add(b['code_id'])
    for d in combat['direct_spawn_dependencies']:
        for b in d['direct_create']:
            assert codes[b['code_id']]['sha256'] == b['bytecode_sha256']
            cohort.add(b['code_id'])
    assert len(cohort) == 24
    assert codes[0]['name'] == 'gml_Object_obj_player_Create_0'
    assert any(o.get('object_id') == 0 and o.get('event_type') == 0
               and o.get('subtype') == 0 for o in codes[0]['owners'])
    rows = collect_sources(codes, cohort)
    report = dict(asset_sha256=SHA256, scanned_code_count=len(codes),
                  cohort_code_ids=sorted(cohort), required_global_count=len(rows),
                  not_written_by_player_create=[r['name'] for r in rows if not r['player_create_write_offsets']],
                  boundary='direct static global accesses; writer sites are NOT guaranteed initialization; other-scope/indirect same-name writes retained',
                  globals=rows)
    if restored_source is not None:
        index_list = json.loads((restored_source / 'index.json').read_text())
        index = {r['id']: r for r in index_list}
        assert len(index_list) == len(index) == len(codes)
        assert set(index) == set(range(len(codes)))
        entry = index[0]
        text = (restored_source / entry['file']).read_text()
        assert hashlib.sha256(text.encode()).hexdigest() == entry['gml_sha256']
        assert entry['roundtrip']['assembly_equal'] and entry['roundtrip']['redecompiled_text_equal']
        report['player_create'] = dict(code_id=0, code_name=codes[0]['name'],
                                      bytecode_sha256=codes[0]['sha256'],
                                      gml_sha256=entry['gml_sha256'], gml=text,
                                      owners=codes[0]['owners'], runtime_verified=False)
    return report


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('restored_source', type=Path)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    report = build((ROOT / 'assets/game.droid').read_bytes(), args.restored_source)
    args.output.write_text(json.dumps(report, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({k: report[k] for k in ('scanned_code_count','cohort_code_ids','required_global_count','not_written_by_player_create')}))
