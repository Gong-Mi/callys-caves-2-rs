"""Basic blocks and conservative, intraprocedural GMS16 control-flow graphs.

This graph preserves both encoded environment successors. It does NOT resolve
with-receivers, environment iteration, expression feasibility, event dispatch,
exceptions or interprocedural effects. Reachability is graph topology only.
"""
from collections import deque
import json

BRANCHES = {0xb6, 0xb7, 0xb8, 0xba, 0xbb}
TERMINATORS = BRANCHES | {0x9c, 0x9d}


def require(condition, message):
    if not condition:
        raise ValueError(message)


def build_cfg(code):
    instructions = code['instructions']
    start, end = code['start'], code['start'] + code['length']
    expected = start
    for instruction in instructions:
        require(instruction['offset'] == expected, 'instruction gap/overlap/order')
        require(instruction['size'] > 0 and instruction['size'] % 4 == 0, 'invalid instruction size')
        expected += instruction['size']
    require(expected == end, 'instructions do not cover entire CODE')
    positions = {i['offset']: n for n, i in enumerate(instructions)}
    leaders = {start} if instructions else set()
    environments = []
    for instruction in instructions:
        op, pos = instruction['opcode'], instruction['offset']
        after = pos + instruction['size']
        if op in BRANCHES:
            # Not present in the pinned asset. Refuse rather than invent a
            # successor for environment-stack unwind variants.
            require(not instruction.get('popenv_exit_magic'), 'popenv-exit magic CFG not modeled')
            require('target' in instruction, 'missing branch target')
            target = instruction['target']
            require(target == end or target in positions, 'target outside CODE or inside payload')
            if target != end:
                leaders.add(target)
        if op in TERMINATORS and after != end:
            leaders.add(after)  # Includes dead code: never silently drop bytes.
        if op in (0xba, 0xbb):
            environments.append(dict(offset=pos, opcode=op,
                pending='receiver and environment-stack runtime semantics',
                encoded_target=instruction['target'], fallthrough=after))
    cuts = sorted(leaders)
    blocks = []
    for n, block_start in enumerate(cuts):
        block_end = cuts[n + 1] if n + 1 < len(cuts) else end
        a = positions[block_start]
        b = positions[block_end] if block_end != end else len(instructions)
        body = instructions[a:b]
        require(bool(body), 'empty basic block')
        last = body[-1]
        op = last['opcode']
        after = last['offset'] + last['size']
        require(after == block_end, 'block does not end at instruction boundary')
        edges = []
        if op == 0xb6:
            edges.append(dict(target=last['target'], kind='jump'))
        elif op in (0xb7, 0xb8):
            taken = 'true' if op == 0xb7 else 'false'
            edges.extend([dict(target=last['target'], kind=taken),
                          dict(target=after, kind='false' if taken == 'true' else 'true')])
        elif op in (0xba, 0xbb):
            edges.extend([dict(target=last['target'], kind='environment_encoded_target'),
                          dict(target=after, kind='environment_fallthrough')])
        elif op in (0x9c, 0x9d):
            edges.append(dict(target=end, kind='return' if op == 0x9c else 'exit'))
        else:
            edges.append(dict(target=after, kind='end' if after == end else 'fallthrough'))
        blocks.append(dict(start=block_start, end=block_end,
                           instruction_offsets=[i['offset'] for i in body], edges=edges))
    by_start = {b['start']: b for b in blocks}
    for block in blocks:
        for edge in block['edges']:
            require(edge['target'] == end or edge['target'] in by_start, 'edge not at block boundary')
    visited = set()
    queue = deque([start] if instructions else [])
    while queue:
        pos = queue.popleft()
        if pos == end or pos in visited:
            continue
        visited.add(pos)
        queue.extend(edge['target'] for edge in by_start[pos]['edges'])
    return dict(code_id=code['id'], code_name=code['name'], entry=start, exit=end,
                blocks=blocks, environment_ops=environments, environment_runtime_verified=False,
                reachability_kind='intraprocedural topology with conservative environment edges',
                unreachable_blocks=[b['start'] for b in blocks if b['start'] not in visited])


def export_cfg(ledger, output):
    graphs = [build_cfg(c) for c in ledger['codes']]
    summary = dict(code_count=len(graphs),
        basic_blocks=sum(len(g['blocks']) for g in graphs),
        edges=sum(len(b['edges']) for g in graphs for b in g['blocks']),
        instruction_memberships=sum(len(b['instruction_offsets']) for g in graphs for b in g['blocks']),
        environment_codes=sum(bool(g['environment_ops']) for g in graphs),
        environment_ops=sum(len(g['environment_ops']) for g in graphs),
        unreachable_blocks=sum(len(g['unreachable_blocks']) for g in graphs),
        full_stack_semantics_verified=0, full_event_behaviors_verified=0)
    result = dict(schema_version=1, input_sha256=ledger['input_sha256'], summary=summary, graphs=graphs)
    (output / 'cfg.json').write_text(json.dumps(result, indent=2) + '\n')
    (output / 'cfg-summary.json').write_text(json.dumps(summary, indent=2) + '\n')
    # A complete per-CODE stage matrix, rather than a mixed completion percentage.
    with (output / 'progress.tsv').open('w') as out:
        out.write('code_id\tname\tindexed\tdisassembled\tstructural_cfg\tconstant_only_body\tenvironment_ops_pending\tstack_semantics\tbehavior_verified\n')
        for code, graph in zip(ledger['codes'], graphs):
            pure = bool(code['constant_prefix']['assignments']) and code['constant_prefix']['whole_body']
            out.write(f"{code['id']}\t{code['name']}\tyes\tyes\tyes\t{str(pure).lower()}\t{len(graph['environment_ops'])}\tunknown\tno\n")
    for graph in graphs:
        if graph['code_name'] in ('gml_Object_obj_player_Step_0', 'gml_Object_obj_player_Alarm_8'):
            (output / f"cfg-{graph['code_id']}.dot").write_text(to_dot(graph))
    return summary


def to_dot(graph):
    lines = ['digraph cfg {', '  rankdir=TB;',
             f"  label={json.dumps(graph['code_name'] + ' - structural CFG, not runtime behavior')};",
             f"  n{graph['exit']} [shape=doublecircle,label=\"EXIT\"];"]
    env_positions = {e['offset'] for e in graph['environment_ops']}
    unreachable = set(graph['unreachable_blocks'])
    for block in graph['blocks']:
        label = f"{block['start']:08x}..{block['end']:08x}\n{len(block['instruction_offsets'])} instructions"
        if any(p in env_positions for p in block['instruction_offsets']):
            label += '\nENV SEMANTICS PENDING'
        color = 'gray' if block['start'] in unreachable else 'black'
        lines.append(f"  n{block['start']} [shape=box,color={color},label={json.dumps(label)}];")
        for edge in block['edges']:
            lines.append(f"  n{block['start']} -> n{edge['target']} [label={json.dumps(edge['kind'])}];")
    lines.append('}')
    return '\n'.join(lines) + '\n'
