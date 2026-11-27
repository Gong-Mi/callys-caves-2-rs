#!/usr/bin/env python3
"""Original is read-only. Execute only rebuilt ARM32 slots C + synthetic creator.
PASS is a scoped reconstructed-consumer verdict, never an original equivalence claim.

Pins the 2026-11-08 correction of the two legacy slot-reader deviations:
  F1 blend mapping — original stores additive→1, multiply→2, screen→3,
     each CONDITIONALLY (moveq/streq at 0x28bd1c/20, 0x28bd3c/40, 0x28bd5c/60);
     no default write on unrecognized or absent blend.
  F4 creator result — spSlotData_create's return is never tested; a NULL flows
     through the field consumers and is published into data->slots[index]
     (unconditional str r5,[r3,r6,lsl #2] at 0x28bd68).
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
FIX = MOD / 'fixture/legacy_red.c'
BODY = MOD / 'src/spine_read_slots.c'
PIN = '3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a'
SOURCES = [C / p for p in (
    'spine_alloc/src/spine_alloc.c', 'json_interface/src/json_interface.c',
    'spine_color/src/spine_color.c', 'spine_read_slots/src/spine_read_slots.c',
    'csprite_resources/fixture/arm32_support.c', FIX,
)]
INCLUDES = [C / p / 'src' for p in (
    'spine_alloc', 'spine_attachment', 'spine_skeleton_data', 'json_interface',
    'spine_color', 'spine_read_mesh', 'spine_mesh', 'spine_read_vertices',
    'spine_atlas_attachment', 'spine_read_slots',
)]
FLAGS = ['--target=armv7a-none-eabi', '-march=armv7-a', '-marm', '-mfpu=vfpv3',
         '-mfloat-abi=softfp', '-std=c11', '-ffreestanding', '-fno-builtin',
         '-ffp-contract=off', '-fstack-protector-strong',
         '-mstack-protector-guard=global', '-ffunction-sections',
         '-fdata-sections', '-Wall', '-Wextra', '-Werror', '-nostdlib',
         '-static', '-fuse-ld=lld', '-Wl,--gc-sections', '-Wl,-e,_start']
# Named runtime assertions in the fixture (per RED_CASE).
CASES = {
    1: 'F1 additive is1, not3',
    2: 'F4 forced NULL return still publishes slot and consumes remaining fields',
    3: 'F1 unrecognized blend does not overwrite comparator-updated value',
    4: 'F1 multiply is2, not1',
    5: 'F1 screen is3, not2',
}
# Raw original words that constitute the deviation pins.
WORD_PINS = {
    0x28bc78: 0xeb000cab,  # bl spSlotData_create
    0x28bc7c: 0xe59d1018,  # ldr r1,[sp,#0x18]  — color feed, NO test in between
    0x28bd1c: 0x03a03001,  # moveq r3,#1        — additive -> 1
    0x28bd20: 0x05853020,  # streq r3,[r5,#0x20]
    0x28bd3c: 0x03a03002,  # moveq r3,#2        — multiply -> 2
    0x28bd40: 0x05853020,  # streq r3,[r5,#0x20]
    0x28bd5c: 0x03a03003,  # moveq r3,#3        — screen -> 3
    0x28bd60: 0x05853020,  # streq r3,[r5,#0x20]
    0x28bd64: 0xe599301c,  # ldr r3,[r9,#0x1c]  — unconditional publish
    0x28bd68: 0xe7835106,  # str r5,[r3,r6,lsl #2]
    0x28bbe8: 0xe300228b,  # movw r2,#651       — malloc line anchor
    0x28bbfc: 0xebffe803,  # bl _malloc
    0x28bc08: 0xe589001c,  # str r0,[r9,#0x1c]  — slots array publish
}
SYMBOL_PINS = {
    'spSlotData_create': (0x28ef2c, 124),
    'spSlotData_setAttachmentName': (0x28efcc, 80),
    'Json_getItem': (0x2873c4, 100),
    'Json_getString': (0x287428, 28),
    'spSkeletonData_findBone': (0x28afbc, 92),
    'spSkeletonJson_readSkeletonData': (0x28b84c, 13044),
    '_malloc': (0x285c10, 60),
}
# (literal pool, add-site whose pc base resolves it, expected string)
KEY_PINS = (
    (0x28c850, 0x28bc44, 'blend'),
    (0x28c854, 0x28bc4c, 'additive'),
    (0x28c858, 0x28bd30, 'multiply'),
    (0x28c85c, 0x28bd50, 'screen'),
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
            value = raw(va, 40).split(b'\0', 1)[0].decode('ascii')
            if value != want:
                raise ValueError(f'pc-relative key mismatch {add_site:#x}: {value!r} != {want!r}')
            keys.append({'pool': hex(pool), 'add_site': hex(add_site), 'va': hex(va), 'value': value})
        # The no-NULL-check pin: instruction flow right after the create call is
        # ldr r1,[sp,#0x18]; mov r2,#0; mov r5,r0; mov r0,r4; bl Json_getString —
        # no cmp/tst on the creator result anywhere before the color lookup.
        flow = [struct.unpack('<I', raw(a, 4))[0] for a in range(0x28bc7c, 0x28bc90, 4)]
        if flow != [0xe59d1018, 0xe3a02000, 0xe1a05000, 0xe1a00004, 0xebffede5]:
            raise ValueError('post-create flow changed (NULL check appeared or reordered)')
    return {'original_sha256': PIN, 'symbol_pins': {k: [hex(v[0]), v[1]] for k, v in SYMBOL_PINS.items()},
            'word_pins': words, 'blend_key_literals': keys,
            'note': 'Static anchors, not original execution/equivalence'}


def dependency_binding():
    flags = [f for f in FLAGS if not f.startswith(('-Wl,', '-fuse-ld=')) and f not in ('-nostdlib', '-static')]
    deps = set(SOURCES) | {Path(__file__).resolve()}
    for src in SOURCES:
        p = run(['clang', *flags, *['-I' + str(i) for i in INCLUDES], '-DRED_CASE=1', '-MM', src])
        if p.returncode:
            raise RuntimeError(p.stderr)
        deps.update(Path(x).resolve() for x in p.stdout.replace('\\\n', '').split(':', 1)[1].split())
    return {str(p): sha(p) for p in sorted(deps)}


def build(out, name, opt='-O2', overrides=None, extra=(), red_case=1, omit=()):
    used = [(overrides or {}).get(p, p) for p in SOURCES if p not in omit]
    binary = out / (name + '.arm')
    argv = ['clang', *FLAGS, opt, *extra, *['-I' + str(i) for i in INCLUDES],
            f'-DRED_CASE={red_case}', *used, '-o', binary]
    p = run(argv)
    (out / (name + '.build.log')).write_text(p.stdout + p.stderr)
    result = {'compile_rc': p.returncode, 'compile_command': [str(x) for x in argv], 'red_case': red_case}
    if p.returncode:
        return {**result, 'diagnostic': p.stderr}
    before = sha(binary)
    result['binary_sha256'] = before
    result['translation_units'] = {str(s): sha(s) for s in used}
    print('BINDING v1 entry=slots-legacy-red case=' + str(red_case) + ' run=' + name
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
    return [
        ('blend_additive_swapped', BODY, [
            ('*(int*)((char*)slotData + 0x20) = 1;   /* 0x28bd1c/20 */',
             '*(int*)((char*)slotData + 0x20) = 3;   /* 0x28bd1c/20 */')], 1),
        ('blend_multiply_swapped', BODY, [
            ('*(int*)((char*)slotData + 0x20) = 2;   /* 0x28bd3c/40 */',
             '*(int*)((char*)slotData + 0x20) = 1;   /* 0x28bd3c/40 */')], 4),
        ('blend_screen_swapped', BODY, [
            ('*(int*)((char*)slotData + 0x20) = 3;   /* 0x28bd5c/60 */',
             '*(int*)((char*)slotData + 0x20) = 2;   /* 0x28bd5c/60 */')], 5),
        ('blend_default_write_restored', BODY, [
            ('*(int*)((char*)slotData + 0x20) = 3;   /* 0x28bd5c/60 */\n    }',
             '*(int*)((char*)slotData + 0x20) = 3;   /* 0x28bd5c/60 */\n'
             '        else *(int*)((char*)slotData + 0x20) = 0;\n    }')], 3),
        ('creator_null_early_return_restored', BODY, [
            ('slotData = spSlotData_create(index, name, bone);\n\n    /* 0x28bc8c: color = getString(slotMap, "color", 0) */',
             'slotData = spSlotData_create(index, name, bone);\n    if (slotData == 0) return 0;\n\n    /* 0x28bc8c: color = getString(slotMap, "color", 0) */')], 2),
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
    report = {'schema': 'cally-slots-legacy-check/1', 'tier': 'test_anchored',
              'original_executed': False,
              'scope': 'Reconstructed slots reader C only; spSlotData creator is a declared synthetic boundary, not a recovered creator',
              'runs': [], 'teeth': [], 'compile_guards': [],
              'declared_cases': {str(k): v for k, v in CASES.items()}, 'status': 'INCOMPLETE'}
    try:
        report['static'] = static(ns.so)
        report['source_binding'] = dependency_binding()
        report['toolchain'] = {n: run([n, '--version']).stdout.splitlines()[0] for n in ('clang', 'qemu-arm')}
        configs = [('O2', '-O2', ())] if ns.smoke else [
            ('O0', '-O0', ()), ('O2', '-O2', ()), ('O3', '-O3', ()),
            ('ubsan', '-O2', ('-fsanitize=undefined,float-cast-overflow', '-fsanitize-trap=all'))]
        for name, opt, extra in configs:
            for case in sorted(CASES):
                r = build(ns.out, f'{name}-case{case}', opt, extra=extra, red_case=case)
                report['runs'].append({'name': name, **r})
                want = 'legacy_bug_probe'
                if r.get('compile_rc') or r['exit_code'] or r['passes'] != [want] or r['failures']:
                    raise RuntimeError(f'{name} case{case}: acceptance failed {r}')
            print('PASS', name, 'cases=' + str(len(CASES)), flush=True)
        if not ns.smoke:
            for name, subject, edits, case in mutations():
                text = subject.read_text()
                for old, new in edits:
                    text = replace_once(text, old, new)
                candidate = ns.out / (name + '.c')
                candidate.write_text(text)
                r = build(ns.out, name, overrides={subject: candidate}, red_case=case)
                named = 'legacy_slots_red: ' + CASES[case]
                caught = r.get('compile_rc') == 0 and r.get('exit_code') == 1 and named in r.get('failures', [])
                report['teeth'].append({'name': name, 'caught_by_named_assertion': caught, **r})
                if not caught:
                    raise RuntimeError(f'mutant not rejected by named runtime assertion: {name}: {r}')
                print('TEETH', name, r['failures'], flush=True)
            missing = build(ns.out, 'missing-slots-body', omit=(BODY,))
            if not missing['compile_rc'] or 'undefined symbol: readSkeletonData_oneSlot' not in missing['diagnostic']:
                raise RuntimeError('missing internal slots body not refused')
            report['compile_guards'].append({'name': 'missing-slots-body', 'refused': True, **missing})
        if any(sha(p) != v for p, v in report['source_binding'].items()):
            raise RuntimeError('bound source/header/checker drift')
        report['status'] = 'SMOKE_PASS' if ns.smoke else 'PASS'
    except Exception as ex:
        report['error'] = str(ex)
        raise
    finally:
        (ns.out / 'receipt.json').write_text(json.dumps(report, ensure_ascii=False, indent=2) + '\n')
    print('RESULT ' + report['status'] + '; ORIGINAL NOT EXECUTED; receipt=' + str(ns.out / 'receipt.json'), flush=True)


if __name__ == '__main__':
    main()
