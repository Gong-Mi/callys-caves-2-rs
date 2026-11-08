#!/usr/bin/env python3
"""Original is read-only. Execute only rebuilt ARM32 animations-entry C plus
synthetic heap/libc/JSON/creator providers. PASS is a scoped reconstructed-
consumer verdict, never an original-equivalence claim.

Subject: two caller blocks of spSkeletonJson_readSkeletonData @0x28b84c:
  B1 0x28d19c..0x28d290 (244 B / 61 insns)
     skeleton-wide events array (malloc line 1028) + EventData loop
     (string deep copy malloc line 1034)
  B2 0x28d290..0x28d2d4 (68 B / 17 insns)
     animations array (malloc line 1043)

Real recovered chain under test:
    readSkeletonData_eventsArray -> Json_getItem(tree,"events"),
        data+0x2c = events->unk_0c, _malloc(count*4,TAG,1028) -> data+0x30,
        return events->child (array published even when child==0)
    readSkeletonData_eventsSegment -> per child: spEventData_create(child->name),
        Json_getInt("int")->+0x04, Json_getFloat("float")->+0x08,
        Json_getString("string") -> strlen + _malloc(len+1,TAG,1034) + strcpy
        -> +0x0c, publish via byte cursor, child=child->next
    readSkeletonData_animationsArray -> Json_getItem(tree,"animations"),
        _malloc(count*4,TAG,1043) -> data+0x38, return animations->child;
        data+0x34 (animationsCount) is NOT written in this block

Declared synthetic boundaries (NOT recovered bodies):
  * spEventData_create (EventData.c, 0x285b94) — the fixture probe table stands
    in and records the single name argument; the module writes +0x04/+0x08/+0x0c.
  * the fixture heap + allocator roster, the libc string providers, and the
    hand-built Json nodes.
  * the fixture reserve() oversizes zero/small allocations so request sizes and
    the child-list-driven loop are observable; no real malloc-capacity claim.

Nothing here executes original libyoyo bytes. Static anchors (SHA, dynsym,
instruction words, pc-relative key literals) are checked before any run.
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
MOD = C / 'spine_read_animations'
FIX = MOD / 'fixture/check.c'
BODY = MOD / 'src/spine_read_animations.c'
PIN = '3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a'
SOURCES = [C / p for p in (
    'spine_alloc/src/spine_alloc.c', 'json_interface/src/json_interface.c',
    'spine_read_animations/src/spine_read_animations.c',
    'csprite_resources/fixture/arm32_support.c',
    'spine_read_animations/fixture/check.c',
)]
INCLUDES = [C / p / 'src' for p in (
    'spine_alloc', 'spine_attachment', 'spine_skeleton_data', 'json_interface',
    'spine_color', 'spine_read_mesh', 'spine_mesh', 'spine_read_vertices',
    'spine_atlas_attachment', 'spine_read_slots', 'skeleton_find',
    'spine_json_error', 'spine_json_support', 'spine_read_animations',
)]
FLAGS = ['--target=armv7a-none-eabi', '-march=armv7-a', '-marm', '-mfpu=vfpv3',
         '-mfloat-abi=softfp', '-std=c11', '-ffreestanding', '-fno-builtin',
         '-ffp-contract=off', '-fstack-protector-strong',
         '-mstack-protector-guard=global', '-ffunction-sections',
         '-fdata-sections', '-Wall', '-Wextra', '-Werror', '-nostdlib',
         '-static', '-fuse-ld=lld', '-Wl,--gc-sections', '-Wl,-e,_start']
# Contract names emitted by the fixture, in execution order.
TESTS = ['events_absent', 'events_empty_children', 'events_zero_count',
         'events_multiple_fields', 'events_count_is_allocation_only',
         'animations_absent', 'animations_empty_children',
         'animations_children', 'chain_order']
SUMMARY = 'SUMMARY all declared animations entry contracts passed'
# Raw original instruction words that constitute the two blocks' structural
# pins (control-flow forks, field stores, malloc call sites).
WORD_PINS = {
    0x28d1ac: 0xe2504000,  # subs r4,r0,#0        — getItem("events") null test
    0x28d1b0: 0x0a000036,  # beq 0x28d290         — absent events skips to B2
    0x28d1b8: 0xe3002404,  # movw r2,#0x404       — malloc line 1028
    0x28d1c0: 0xe589002c,  # str r0,[r9,#0x2c]    — eventsCount BEFORE malloc
    0x28d1cc: 0xebffe28f,  # bl _malloc
    0x28d1d8: 0xe5890030,  # str r0,[r9,#0x30]    — events array publish
    0x28d1dc: 0x0a00002b,  # beq 0x28d290         — empty child list skips loop
    0x28d20c: 0xe594001c,  # ldr r0,[r4,#0x1c]    — NAME = Json member key
    0x28d210: 0xebffe25f,  # bl spEventData_create
    0x28d224: 0xebffe88d,  # bl Json_getInt
    0x28d230: 0xe5850004,  # str r0,[r5,#0x4]     — intValue +0x04
    0x28d238: 0xebffe881,  # bl Json_getFloat
    0x28d244: 0xe5850008,  # str r0,[r5,#0x8]     — floatValue +0x08
    0x28d24c: 0xebffe875,  # bl Json_getString
    0x28d260: 0xe300240a,  # movw r2,#0x40a       — malloc line 1034
    0x28d268: 0xebffe268,  # bl _malloc
    0x28d270: 0xe585000c,  # str r0,[r5,#0xc]     — stringValue +0x0c
    0x28d27c: 0xe783500a,  # str r5,[r3,r10]      — publish at byte cursor
    0x28d280: 0xe28aa004,  # add r10,r10,#4
    0x28d28c: 0x1affffde,  # bne 0x28d20c         — loop on child list
    0x28d2a4: 0x0a00053e,  # beq 0x28e7a4         — absent animations ends segment
    0x28d2ac: 0xe3002413,  # movw r2,#0x413       — malloc line 1043
    0x28d2bc: 0xebffe253,  # bl _malloc
    0x28d2c0: 0xe5944004,  # ldr r4,[r4,#0x4]     — animations->child
    0x28d2cc: 0xe5890038,  # str r0,[r9,#0x38]    — animations array, NOT +0x34
    0x28d2d0: 0x0a000533,  # beq 0x28e7a4         — empty child list ends segment
}
SYMBOL_PINS = {
    'spSkeletonJson_readSkeletonData': (0x28b84c, 13044),
    'Json_getItem': (0x2873c4, 100),
    'Json_getString': (0x287428, 28),
    'Json_getFloat': (0x287444, 28),
    'Json_getInt': (0x287460, 28),
    '_malloc': (0x285c10, 60),
    'spEventData_create': (0x285b94, 88),
}
# (literal pool word address, the ADD site whose +8 PC base resolves it,
#  expected text).  va = add_site + 8 + pool_word — pass the ADD instruction
#  address, not its already-biased base.
KEY_PINS = (
    (0x28c9d8, 0x28d1a4, 'events'),
    (0x28c9f0, 0x28d298, 'animations'),
    (0x28c9e0, 0x28d1f0, 'int'),
    (0x28c9ec, 0x28d204, 'float'),
    (0x28c9e4, 0x28d1f4, 'string'),
    (0x28c9dc, 0x28d1c4, 'jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c'),
    (0x28c9f4, 0x28d2b8, 'jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c'),
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
        # This library has no .symtab; .dynsym is the authoritative table.
        found = {}
        sec = e.get_section_by_name('.dynsym')
        if sec is None:
            raise ValueError('.dynsym missing')
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
            value = raw(va, 96).split(b'\0', 1)[0].decode('ascii')
            if value != want:
                raise ValueError(f'pc-relative key mismatch {add_site:#x}: {value!r} != {want!r}')
            keys.append({'pool': hex(pool), 'add_site': hex(add_site), 'va': hex(va), 'value': value})
    return {'original_sha256': PIN,
            'symbol_pins': {k: [hex(v[0]), v[1]] for k, v in SYMBOL_PINS.items()},
            'word_pins': words, 'segment_key_literals': keys,
            'note': 'Static anchors, not original execution/equivalence'}


def dependency_binding():
    flags = [f for f in FLAGS if not f.startswith(('-Wl,', '-fuse-ld='))
             and f not in ('-nostdlib', '-static')]
    deps = set(SOURCES) | {Path(__file__).resolve()}
    for src in SOURCES:
        p = run(['clang', *flags, *['-I' + str(i) for i in INCLUDES], '-MM', src])
        if p.returncode:
            raise RuntimeError(p.stderr)
        text = p.stdout.replace('\\\n', ' ')
        deps.update(Path(x).resolve() for x in text.split(':', 1)[1].split())
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
    print('BINDING v1 entry=animations-entry run=' + name
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
    """Nine mutants of the BODY text only; each must be refused by a NAMED
    runtime assertion. No mutant may hang: the polarity mutant turns the loop
    into a skip, not an infinite loop."""
    return [
        ('events_count_unpublished', BODY, [
            ('    *(uint32_t*)((char*)data_raw + SD_EVENTSCOUNT_OFF) = count; /* 0x28d1c0 */',
             '    /* mutated: count publish removed */')],
         'events_empty_children: B1 publishes the declared events count (+0x2c)'),
        ('events_array_wrong_offset', BODY, [
            ('        *(void***)((char*)data_raw + SD_EVENTS_OFF) = array; /* 0x28d1d8 */',
             '        *(void***)((char*)data_raw + 0x34u) = array; /* mutated: wrong slot */')],
         'events_empty_children: B1 publishes the events array (+0x30) even with no children'),
        ('event_name_not_member_key', BODY, [
            ('        eventData = spEventData_create(eventMap->name); /* 0x28d20c/0x28d210 */',
             '        eventData = spEventData_create((const char*)0); /* mutated */')],
         'events_multiple_fields: creator receives the Json member key as the event name'),
        ('event_loop_polarity', BODY, [
            ('    while (eventMap != 0) {                         /* 0x28d288/0x28d28c */',
             '    while (eventMap == 0) {                         /* mutated polarity */')],
         'events_multiple_fields: one EventData per event child in list order'),
        ('event_field_swap', BODY, [
            ('        eventData->intValue = Json_getInt(eventMap, "int", 0); /* 0x28d220..0x28d230 */\n'
             '        eventData->floatValue = Json_getFloat(eventMap, "float", 0.0f); /* 0x28d234..0x28d244 */',
             '        eventData->floatValue = (float)Json_getInt(eventMap, "int", 0); /* mutated */\n'
             '        eventData->intValue = (int32_t)Json_getFloat(eventMap, "float", 0.0f); /* mutated */')],
         'events_multiple_fields: int lands at +0x04 and float bits at +0x08'),
        ('event_string_line', BODY, [
            ('                (uint32_t)strlen(string_value) + 1u, TAG, 1034u); /* 0x28d264/0x28d268 */',
             '                (uint32_t)strlen(string_value) + 1u, TAG, 1035u); /* mutated */')],
         'events_multiple_fields: string deep copy is a line-1034 allocation of strlen+1 bytes'),
        ('animations_line', BODY, [
            ('    array = (void**)_malloc(count << 2, TAG, 1043u); /* 0x28d2ac/0x28d2b4/0x28d2bc */',
             '    array = (void**)_malloc(count << 2, TAG, 1042u); /* mutated */')],
         'animations_empty_children: B2 empty children allocates count*4 at line 1043'),
        ('animations_offset', BODY, [
            ('#define SD_ANIMATIONS_OFF        0x38u',
             '#define SD_ANIMATIONS_OFF        0x34u /* mutated */')],
         'animations_empty_children: B2 publishes the animations array (+0x38)'),
        ('animations_return_node', BODY, [
            ('        Json* child = animations->child;            /* 0x28d2c0 (after _malloc) */',
             '        Json* child = animations;                   /* mutated */')],
         'animations_empty_children: B2 empty children returns NULL'),
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
    report = {'schema': 'cally-animations-entry-check/1', 'tier': 'test_anchored',
              'original_executed': False,
              'entry': 'animations-entry (readSkeletonData caller blocks B1 0x28d19c-0x28d290, B2 0x28d290-0x28d2d4)',
              'scope': ('Reconstructed B1/B2 C only: real Json_getItem/getInt/getFloat/getString, '
                        'real _malloc with tag/line, event and animation array publication, '
                        'event string deep copy, child-list-driven EventData loop. Synthetic '
                        'boundaries: spEventData_create (EventData.c), fixture heap + allocator '
                        'roster, libc string providers, hand-built Json nodes. B2 deliberately '
                        'does not write data+0x34 (animationsCount). Not an original-equivalence claim.'),
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
            missing = build(ns.out, 'missing-animations-entry-body', omit=(BODY,))
            if (not missing['compile_rc']
                    or 'undefined symbol: readSkeletonData_eventsSegment' not in missing['diagnostic']):
                raise RuntimeError('missing animations-entry body not refused')
            report['compile_guards'].append({'name': 'missing-animations-entry-body',
                                             'refused': True, **missing})
            print('GUARD missing-animations-entry-body refused', flush=True)
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
