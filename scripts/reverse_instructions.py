"""GMS16 structural disassembly. No stack evaluator or VM execution.

Encoding reference (non-official): UndertaleModTool f43e12c445c37d50dc6244caa12ccab232983f3f
UndertaleModLib/Models/UndertaleCode.cs:234-393,720-789,825-910.
Unknown opcodes/types fail closed; only this asset's version is supported.
"""
import math
import struct

OPCODES = {
    0x07: 'conv', 0x08: 'mul', 0x09: 'div', 0x0a: 'rem', 0x0b: 'mod',
    0x0c: 'add', 0x0d: 'sub', 0x0e: 'and', 0x0f: 'or', 0x10: 'xor',
    0x11: 'neg', 0x12: 'not', 0x13: 'shl', 0x14: 'shr', 0x15: 'cmp',
    0x45: 'pop', 0x84: 'pushi', 0x86: 'dup', 0x99: 'callv', 0x9c: 'ret',
    0x9d: 'exit', 0x9e: 'popz', 0xb6: 'b', 0xb7: 'bt', 0xb8: 'bf',
    0xba: 'pushenv', 0xbb: 'popenv', 0xc0: 'push', 0xc1: 'pushloc',
    0xc2: 'pushglb', 0xc3: 'pushbltn', 0xd9: 'call', 0xff: 'break',
}
PUSH = {0x84, 0xc0, 0xc1, 0xc2, 0xc3}
GOTO = {0xb6, 0xb7, 0xb8, 0xba, 0xbb}


def disassemble(reader, code):
    require = reader.require
    start, end = code['start'], code['start'] + code['length']
    pos, result = start, []
    references = {r['offset']: r for r in code['references']}
    consumed = set()
    while pos < end:
        reader.bounds(pos, 4, start, end)
        word = reader.u32(pos)
        op, typ = word >> 24, (word >> 16) & 255
        require(op in OPCODES, f'unknown opcode {op:#x} @{pos:#x}')
        size, ref_kind = 4, None
        if op in PUSH:
            require(typ in (0, 2, 3, 5, 6, 15), f'unsupported push type {typ} @{pos:#x}')
            size = {0: 12, 2: 8, 3: 12, 5: 8, 6: 8, 15: 4}[typ]
            if typ == 5:
                ref_kind = 'VARI'
        elif op == 0x45 and typ & 15 != 15:
            size, ref_kind = 8, 'VARI'
        elif op == 0xd9:
            size, ref_kind = 8, 'FUNC'
        elif op == 0xff and typ == 2:
            size = 8
        reader.bounds(pos, size, start, end)
        item = dict(offset=pos, opcode=op, mnemonic=OPCODES[op], type1=typ & 15,
                    type2=typ >> 4, size=size,
                    words_raw=[reader.u32(p) for p in range(pos, pos + size, 4)])
        if ref_kind:
            require(pos in references and references[pos]['kind'] == ref_kind,
                    f'missing/wrong {ref_kind} reference @{pos:#x}')
            item['reference'] = references[pos]
            item['reference_type'] = (reader.u32(pos + 4) >> 24) & 0xf8
            if ref_kind == 'VARI':
                item['instance_raw'] = struct.unpack_from('<h', reader.data, pos)[0]
            consumed.add(pos)
        else:
            require(pos not in references, f'reference on non-reference instruction @{pos:#x}')
        if op in PUSH and typ != 5:
            if typ == 15:
                item['value'] = struct.unpack_from('<h', reader.data, pos)[0]
            elif typ == 2:
                item['value'] = reader.i32(pos + 4)
            elif typ == 3:
                item['value'] = struct.unpack_from('<q', reader.data, pos + 4)[0]
            elif typ == 0:
                value = struct.unpack_from('<d', reader.data, pos + 4)[0]
                item['value'] = value if math.isfinite(value) else repr(value)
            elif typ == 6:
                item['string_id'] = reader.u32(pos + 4)
        if op == 0xd9:
            item['argc'] = word & 0xffff
        if op == 0x15:
            item['comparison'] = (word >> 8) & 255
        if op in GOTO:
            delta = word & 0xffffff
            if delta == 0xf00000:
                require(op == 0xbb, 'popenv exit magic on other opcode')
                item['popenv_exit_magic'] = True
            else:
                if delta & 0x400000:
                    delta |= 0x800000
                if delta & 0x800000:
                    delta -= 0x1000000
                item['target'] = pos + delta * 4
        result.append(item)
        pos += size
    require(consumed == set(references), f'references inside payload or outside instructions in CODE {code["id"]}')
    boundaries = {i['offset'] for i in result} | {end}
    for item in result:
        if 'target' in item:
            require(item['target'] in boundaries, f'branch outside CODE/in payload @{item["offset"]:#x}')
    return result


def parse_locals(reader, functions, codes):
    # UndertaleChunks.cs:1928-1934; UndertaleFunction.cs:149-165,184-210.
    require = reader.require
    pos, end = functions['trailing_offset'], reader.chunks['FUNC'][1]
    reader.bounds(pos, 4, pos, end)
    count = reader.u32(pos)
    pos += 4
    require(count <= (end - pos) // 8, 'impossible locals count')
    names = {c['name'] for c in codes}
    seen, result = set(), []
    for _ in range(count):
        reader.bounds(pos, 8, 0, end)
        n = reader.u32(pos)
        name = reader.string(reader.u32(pos + 4))
        require(name in names and name not in seen, 'unknown/duplicate locals CODE name')
        seen.add(name)
        entry = dict(offset=pos, code_name=name, variables=[])
        pos += 8
        reader.bounds(pos, n * 8, 0, end)
        for i in range(n):
            at = pos + i * 8
            entry['variables'].append(dict(index=reader.u32(at), name=reader.string(reader.u32(at + 4))))
        result.append(entry)
        pos += n * 8
    require(pos == end, 'FUNC locals do not exhaust chunk')
    require(seen == names, 'missing CODE locals entry')
    return result


def format_instruction(item):
    fields = [f"{item['offset']:08x}", ' '.join(f'{w:08x}' for w in item['words_raw']),
              f"{item['mnemonic']} t1={item['type1']} t2={item['type2']}"]
    for key in ('value', 'string_id', 'argc', 'comparison', 'instance_raw', 'reference_type'):
        if key in item:
            fields.append(f'{key}={item[key]}')
    if 'reference' in item:
        ref = item['reference']
        fields.append(f"{ref['kind']}[{ref['symbol_id']}]={ref['name']}")
    if 'target' in item:
        fields.append(f"target={item['target']:08x}")
    if item.get('popenv_exit_magic'):
        fields.append('popenv-exit-magic')
    return ' | '.join(fields)
