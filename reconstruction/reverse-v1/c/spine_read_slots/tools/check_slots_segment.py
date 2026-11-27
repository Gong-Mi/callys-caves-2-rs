#!/usr/bin/env python3
"""Original is read-only. Execute only rebuilt ARM32 slots-segment C + synthetic
creator/heap/libc providers. PASS is a scoped reconstructed-consumer verdict,
never an original-equivalence claim.

Subject: readSkeletonData_slotsSegment — the slots segment OUTER LOOP of
readSkeletonData, caller BLOCK 0x28bbe4-0x28bdd8.

Real recovered chain under test (all bodies recovered, no stubs):
    readSkeletonData_slotsArray  -> Json_getItem(tree,"slots"),
                                    data->slotsCount, _malloc(size*4,tag,651)
    loop condition (0x28bd7c)    -> Json_getString(slotMap,"bone",0)
                                    spSkeletonData_findBone(data,boneName)
    body (0x28bc5c)              -> readSkeletonData_oneSlot
    error path (0x28bda4)        -> spSkeletonData_dispose(data)
                                    _spSkeletonJson_setError(parser,tree,
                                        "Slot bone not found: ",boneName)
                                    -> ReportSpineError console vcall
                                    -> Json_dispose(root tree)
    return 0 @0x28bdc8 (mov r0,r7; r7 == findBone == NULL)

Declared synthetic boundaries (NOT recovered bodies):
  * spSlotData_create / spSlotData_setAttachmentName (SlotData.c) — the fixture
    probe table stands in; it is a declared boundary, not a recovered creator.
  * the fixture heap + allocator roster, the libc string providers, and the
    console object installed into dbg_csol via spine_linked_postpass/fixture/
    reporter_adapter.c (the vcall itself is the real ReportSpineError).
  * the line-651 slots array is pre-filled with a pointer to a zeroed 16-byte
    record so the REAL dispose can walk the never-published tail without
    faulting; the original's behaviour on malloc garbage there is undefined and
    is NOT asserted.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import subprocess
from elftools.elf.elffile import ELFFile

C = Path(__file__).resolve().parents[2]
MOD = C / 'spine_read_slots'
FIX = MOD / 'fixture/segment_check.c'
BODY = MOD / 'src/spine_read_slots.c'
PIN = '3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a'
SOURCES = [C / p for p in (
    'spine_alloc/src/spine_alloc.c', 'json_interface/src/json_interface.c',
    'spine_color/src/spine_color.c', 'spine_skeleton_data/src/spine_skeleton_data.c',
    'skeleton_find/src/skeleton_find.c', 'spine_json_support/src/spine_json_support.c',
    'spine_json_error/src/spine_json_error.c', 'spine_read_slots/src/spine_read_slots.c',
    'csprite_resources/fixture/arm32_support.c',
    'spine_linked_postpass/fixture/reporter_adapter.c',
    'spine_read_slots/fixture/segment_check.c',
)]
INCLUDES = [C / p / 'src' for p in (
    'spine_alloc', 'spine_attachment', 'spine_skeleton_data', 'json_interface',
    'spine_color', 'spine_read_mesh', 'spine_mesh', 'spine_read_vertices',
    'spine_atlas_attachment', 'spine_read_slots', 'skeleton_find',
    'spine_json_error', 'spine_json_support',
)]
FLAGS = ['--target=armv7a-none-eabi', '-march=armv7-a', '-marm', '-mfpu=vfpv3',
         '-mfloat-abi=softfp', '-std=c11', '-ffreestanding', '-fno-builtin',
         '-ffp-contract=off', '-fstack-protector-strong',
         '-mstack-protector-guard=global', '-ffunction-sections',
         '-fdata-sections', '-Wall', '-Wextra', '-Werror', '-nostdlib',
         '-static', '-fuse-ld=lld', '-Wl,--gc-sections', '-Wl,-e,_start']
# Contract names emitted by the fixture, in execution order.
TESTS = ['segment_absent', 'segment_empty_children', 'segment_success', 'segment_error']
SUMMARY = 'SUMMARY all declared slots segment contracts passed'
# Raw original words that constitute the segment's structural pins.
WORD_PINS = {
    0x28bbe8: 0xe300228b,  # movw r2,#651        — malloc line for the slots array
    0x28bbe0: 0x0a00007d,  # beq 0x28bddc        — "slots" key absent skips segment
    0x28bc0c: 0x0a000072,  # beq 0x28bddc        — child==0 skips loop
    0x28bc58: 0xea000047,  # b   0x28bd7c        — condition evaluated BEFORE body
    0x28bd70: 0xe5944000,  # ldr r4,[r4]         — slotMap = slotMap->next
    0x28bd74: 0xe3540000,  # cmp r4,#0
    0x28bd78: 0x0a000016,  # beq exit
    0x28bd88: 0xebffeda6,  # bl  Json_getString(slotMap,"bone",0)
    0x28bd98: 0xebfffc87,  # bl  spSkeletonData_findBone(data,boneName)
    0x28bda0: 0x1affffad,  # bne body            — condition-first polarity
    0x28bdac: 0xebfffc11,  # bl  spSkeletonData_dispose(data)
    0x28bdb4: 0xe59d1024,  # ldr r1,[sp,#0x24]   — ROOT tree into setError's json arg
    0x28bdb8: 0xe1a03005,  # mov r3,r5           — boneName extra
    0x28bdbc: 0xe1a00008,  # mov r0,r8           — parser
    0x28bdc4: 0xebfffe6e,  # bl  _spSkeletonJson_setError
    0x28bdc8: 0xe1a00007,  # mov r0,r7           — return findBone result (NULL => 0)
}
SYMBOL_PINS = {
    'spSlotData_create': (0x28ef2c, 124),
    'spSlotData_setAttachmentName': (0x28efcc, 80),
    'Json_getItem': (0x2873c4, 100),
    'Json_getString': (0x287428, 28),
    'spSkeletonData_findBone': (0x28afbc, 92),
    'spSkeletonData_dispose': (0x28adf8, 452),
    '_spSkeletonJson_setError': (0x28b784, 200),
    'spSkeletonJson_readSkeletonData': (0x28b84c, 13044),
    '_malloc': (0x285c10, 60),
}
# (literal pool word address, the ADD site whose +8 PC base resolves it, expected text)
# va = add_site + 8 + pool_word  — pass the ADD instruction address, not its base.
KEY_PINS = (
    (0x28c844, 0x28bc28, 'bone'),
    (0x28c860, 0x28bdc0, 'Slot bone not found: '),
)


def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def run(argv, timeout=60):
    return subprocess.run([str(x) for x in argv], text=True, capture_output=True, timeout=timeout)


def replace_once(text, old, new):
    if text.count(old) != 1:
        raise ValueError('mutation site not unique: ' + old)
    return text.replace(old, new, 1)


def static(so):
    if sha(so) != PIN:
        raise ValueError('original SHA mismatch')
    with so.open('rb') as f:
        e = ELFFile(f)
        segs = [(s['p_vaddr'], s.data()) for s in e.iter_segments() if s['p_type'] == 'PT_LOAD']
        # .dynsym first, then .symtab; first definition seen wins.
        found = {}
        for secname in ('.dynsym', '.symtab'):
            sec = e.get_section_by_name(secname)
            if sec is None:
                continue
            for sym in sec.iter_symbols():
                if sym.name and sym.name not in found:
                    found[sym.name] = (sym['st_value'], sym['st_size'])
        for name, (va, size) in SYMBOL_PINS.items():
            if found.get(name) != (va, size):
                raise ValueError(f'symbol pin drifted: {name}: {found.get(name)}')

        def raw(a, n):
            for va, data in segs:
                if va <= a and a + n <= va + len(data):
                    return data[a - va:a - va + n]
            raise ValueError('unmapped original ' + hex(a))

        words = {hex(a): struct.unpack('<I', raw(a, 4))[0] for a in WORD_PINS}
        for a, want in WORD_PINS.items():
            if words[hex(a)] != want:
                raise ValueError(f'word pin drifted at {a:#x}: {words[hex(a)]:#x} != {want:#x}')
        keys = []
        for pool, add_site, want in KEY_PINS:
            w = struct.unpack('<I', raw(pool, 4))[0]
            va = (add_site + 8 + w) & 0xffffffff
            value = raw(va, 64).split(b'\0', 1)[0].decode('ascii')
            if value != want:
                raise ValueError(f'pc-relative key mismatch {add_site:#x}: {value!r} != {want!r}')
            keys.append({'pool': hex(pool), 'add_site': hex(add_site), 'va': hex(va), 'value': value})
    return {'original_sha256': PIN,
            'symbol_pins': {k: [hex(v[0]), v[1]] for k, v in SYMBOL_PINS.items()},
            'word_pins': words, 'segment_key_literals': keys,
            'note': 'Static anchors, not original execution/equivalence'}


def dependency_binding():
    flags = [f for f in FLAGS if not f.startswith(('-Wl,', '-fuse-ld=')) and f not in ('-nostdlib', '-static')]
    deps = set(SOURCES) | {Path(__file__).resolve()}
    for src in SOURCES:
        p = run(['clang', *flags, *['-I' + str(i) for i in INCLUDES], '-MM', src])
        if p.returncode:
            raise RuntimeError(p.stderr)
        deps.update(Path(x).resolve() for x in p.stdout.replace('\\\n', '').split(':', 1)[1].split())
    return {str(p): sha(p) for p in sorted(deps)}


def build(out, name, opt='-O2', overrides=None, extra=(), omit=()):
    used = [(overrides or {}).get(p, p) for p in SOURCES if p not in omit]
    binary = out / (name + '.arm')
    argv = ['clang', *FLAGS, opt, *extra, *['-I' + str(i) for i in INCLUDES], *used, '-o', binary]
    p = run(argv)
    (out / (name + '.build.log')).write_text(p.stdout + p.stderr)
    result = {'compile_rc': p.returncode, 'compile_command': [str(x) for x in argv]}
    if p.returncode:
        return {**result, 'diagnostic': p.stderr}
    before = sha(binary)
    result['binary_sha256'] = before
    result['translation_units'] = {str(s): sha(s) for s in used}
    print('BINDING v1 entry=slots-segment run=' + name
          + ' original_sha256=' + PIN + ' fixture_sha256=' + sha(FIX)
          + ' binary_sha256=' + before, flush=True)
    p = run(['qemu-arm', binary], 15)
    (out / (name + '.log')).write_text(p.stdout + p.stderr)
    if sha(binary) != before:
        raise RuntimeError('executed binary drift')
    return {**result, 'exit_code': p.returncode, 'stdout': p.stdout, 'stderr': p.stderr,
            'passes': re.findall(r'^PASS (.+)$', p.stdout, re.M),
            'failures': re.findall(r'^FAIL (.+)$', p.stdout, re.M)}


def mutations():
    """Six mutants of the BODY text only; each must be refused by a NAMED assertion."""
    seterror_call = ('_spSkeletonJson_setError((spSkeletonJson*)parser_raw, tree,\n'
                     '                                     "Slot bone not found: ", bone_name);')
    return [
        ('seg_dispose_skipped', BODY, [
            ('spSkeletonData_dispose((spSkeletonData*)data_raw);',
             '(void)data_raw;')],
         'segment_error: SEG dispose frees the published slot and bones'),
        ('seg_error_returns_1', BODY, [
            ('return 0;           /* 0x28bdc8: mov r0,r7 (r7 = findBone = 0) */',
             'return 1;           /* mutated: error swallowed */')],
         'segment_error: SEG returns 0 when a slot bone is missing'),
        ('seg_wrong_message', BODY, [
            (seterror_call,
             '_spSkeletonJson_setError((spSkeletonJson*)parser_raw, tree,\n'
             '                                     "Slot bone not found", bone_name);')],
         'segment_error: SEG error message exact'),
        ('seg_json_arg_dropped', BODY, [
            (seterror_call,
             '_spSkeletonJson_setError((spSkeletonJson*)parser_raw, 0,\n'
             '                                     "Slot bone not found: ", bone_name);')],
         'segment_error: SEG root tree disposed via setError'),
        ('seg_condition_polarity', BODY, [
            ('if (bone == 0) {', 'if (bone != 0) {')],
         'segment_success: SEG success returns 1'),
        ('seg_index_base', BODY, [
            ('int index = 0;              /* 0x28bc14: mov r6,#0 before first check */',
             'int index = 1;              /* mutated */')],
         'segment_success: SEG success publishes both slots in order'),
    ]


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--so', type=Path, required=True)
    ap.add_argument('--out', type=Path, required=True)
    ap.add_argument('--smoke', action='store_true')
    ns = ap.parse_args()
    ns.out.mkdir(parents=True, exist_ok=False)
    tmp = ns.out / 'compiler-tmp'
    tmp.mkdir()
    os.environ['TMPDIR'] = str(tmp)
    report = {'schema': 'cally-slots-segment-check/1', 'tier': 'test_anchored',
              'original_executed': False,
              'entry': 'slots-segment (readSkeletonData caller BLOCK 0x28bbe4-0x28bdd8)',
              'scope': ('Reconstructed slots segment C only: slotsArray -> Json_getString/'
                        'findBone condition-first -> oneSlot body -> real '
                        'spSkeletonData_dispose -> real _spSkeletonJson_setError -> console '
                        'vcall -> Json_dispose(root). Synthetic boundaries: spSlotData_create/'
                        'setAttachmentName (SlotData.c), fixture heap + allocator roster, libc '
                        'string providers, console object in dbg_csol (reporter_adapter.c), and '
                        'the line-651 zeroed-record heap fill. Not an original-equivalence claim.'),
              'subject': {'body': str(BODY), 'fixture': str(FIX)},
              'runs': [], 'teeth': [], 'compile_guards': [],
              'declared_tests': TESTS, 'declared_summary': SUMMARY, 'status': 'INCOMPLETE'}
    try:
        report['static'] = static(ns.so)
        report['source_binding'] = dependency_binding()
        report['toolchain'] = {n: run([n, '--version']).stdout.splitlines()[0]
                               for n in ('clang', 'qemu-arm')}
        configs = [('O2', '-O2', ())] if ns.smoke else [
            ('O0', '-O0', ()), ('O2', '-O2', ()), ('O3', '-O3', ()),
            ('ubsan', '-O2', ('-fsanitize=undefined,float-cast-overflow', '-fsanitize-trap=all'))]
        for name, opt, extra in configs:
            r = build(ns.out, name, opt, extra=extra)
            report['runs'].append({'name': name, **r})
            if (r.get('compile_rc') or r['exit_code'] or r['passes'] != TESTS
                    or r['failures'] or SUMMARY not in r['stdout']):
                raise RuntimeError(f'{name}: acceptance failed {r}')
            print('PASS', name, 'declared_tests=' + str(len(TESTS)), flush=True)
        if not ns.smoke:
            for name, subject, edits, expect in mutations():
                text = subject.read_text()
                for old, new in edits:
                    text = replace_once(text, old, new)
                candidate = ns.out / (name + '.c')
                candidate.write_text(text)
                r = build(ns.out, name, overrides={subject: candidate})
                caught = (r.get('compile_rc') == 0 and r.get('exit_code') == 1
                          and expect in r.get('failures', []))
                report['teeth'].append({'name': name, 'expected_failure': expect,
                                        'caught_by_named_assertion': caught, **r})
                if not caught:
                    raise RuntimeError(f'mutant not rejected by named runtime assertion: {name}: {r}')
                print('TEETH', name, r['failures'], flush=True)
            missing = build(ns.out, 'missing-slots-segment-body', omit=(BODY,))
            if (not missing['compile_rc']
                    or 'undefined symbol: readSkeletonData_slotsSegment' not in missing['diagnostic']):
                raise RuntimeError('missing slots segment body not refused')
            report['compile_guards'].append({'name': 'missing-slots-segment-body',
                                             'refused': True, **missing})
            print('GUARD missing-slots-segment-body refused', flush=True)
        if any(sha(p) != v for p, v in report['source_binding'].items()):
            raise RuntimeError('bound source/header/checker drift')
        report['status'] = 'SMOKE_PASS' if ns.smoke else 'PASS'
    except Exception as ex:
        report['error'] = str(ex)
        raise
    finally:
        (ns.out / 'receipt.json').write_text(json.dumps(report, ensure_ascii=False, indent=2) + '\n')
    print('RESULT ' + report['status'] + '; ORIGINAL NOT EXECUTED; receipt='
          + str(ns.out / 'receipt.json'), flush=True)


if __name__ == '__main__':
    main()
