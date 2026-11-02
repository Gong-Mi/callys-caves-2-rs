#!/usr/bin/env python3
"""spAtlas_dispose 0x284120（84B）静态译文验收：静态钉桩 + host/ARM32 正例与负控。

不执行原件、不用 ART/Unicorn；只用 .dynsym + 机器码做静态身份，再跑自建译文。
"""
from pathlib import Path
import hashlib, io, os, re, shutil, subprocess, tempfile
from capstone import Cs, CS_ARCH_ARM, CS_MODE_ARM, CS_MODE_LITTLE_ENDIAN
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[1]
IMAGE_SHA = '3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a'
IMAGE = Path(os.environ.get('CALLY_ORIGINAL_SO',
    '~/callys-caves-2-rs/reconstruction/live-mem/libyoyo_armv7.so')).expanduser()
TREE = Path(os.environ.get('CALLY_TREE', str(ROOT.parent)))
SKEL, RES = TREE / 'cskeleton_lifetime/src', TREE / 'csprite_resources/fixture'

SYMS = {  # 名字 -> (地址, size)：全部 .dynsym GLOBAL FUNC
    'spAtlas_dispose': (0x284120, 84), 'spAtlasPage_dispose': (0x2840b8, 32),
    'spAtlasRegion_dispose': (0x2840f4, 44), '_free': (0x285c80, 28),
    '_spAtlasPage_disposeTexture': (0xbd814, 40),
}
# 21 条指令逐条钉住；op_str 归一化（去 '#'、fp→r11、ip→r12）后精确比较
EXPECT = [
 (0x284120,'push','{r3, r4, r5, lr}'), (0x284124,'mov','r5, r0'),
 (0x284128,'ldr','r0, [r0]'),          (0x28412c,'cmp','r0, 0'),
 (0x284130,'beq','0x284148'),          (0x284134,'ldr','r4, [r0, 0x28]'),
 (0x284138,'bl','0x2840b8'),           (0x28413c,'cmp','r4, 0'),
 (0x284140,'mov','r0, r4'),            (0x284144,'bne','0x284134'),
 (0x284148,'ldr','r0, [r5, 4]'),       (0x28414c,'cmp','r0, 0'),
 (0x284150,'beq','0x284168'),          (0x284154,'ldr','r4, [r0, 0x4c]'),
 (0x284158,'bl','0x2840f4'),           (0x28415c,'cmp','r4, 0'),
 (0x284160,'mov','r0, r4'),            (0x284164,'bne','0x284154'),
 (0x284168,'mov','r0, r5'),            (0x28416c,'pop','{r3, r4, r5, lr}'),
 (0x284170,'b','0x285c80'),
]
# (地址, 期望 op_str)：结构体字节数与两条链的头/尾槽位，全部来自机器码
LAYOUT = [(0x2841d0,'r1, 0xc'), (0x28406c,'r1, 0x2c'), (0x2840e0,'r1, 0x50'),
          (0x284294,'r0, [r3, 4]'), (0x2846e4,'r11, [r3, 0x28]'), (0x2846ec,'r11, [r12]'),
          (0x2840c4,'r0, [r4, 4]'), (0x284104,'r0, [r4, 0x40]'), (0x28410c,'r0, [r4, 0x44]')]

BASE_PASS = ['next_slot_offsets_are_tail_words', 'page_list_disposed_in_list_order',
             'region_list_disposed_in_list_order', 'atlas_freed_exactly_once_and_last',
             'every_node_disposed_exactly_once', 'renderer_slot_not_freed',
             'empty_atlas_frees_only_atlas', 'no_dispose_on_null_terminator']
HELPER_PASS = ['next_slot_offsets_are_tail_words', 'page_helper_frees_name_then_page',
               'region_helper_frees_name_splits_pads_then_region',
               'full_free_log_matches_instruction_order', 'atlas_freed_exactly_once_and_last',
               'every_block_freed_exactly_once', 'renderer_slot_not_freed',
               'empty_atlas_frees_only_atlas']
# 负控/变体 -> (要求出现的 FAIL 名, 是否必须与基线逐字节同输出)
MUTANTS = [(1, {'page_list_disposed_in_list_order', 'region_list_disposed_in_list_order',
                 'atlas_freed_exactly_once_and_last', 'every_node_disposed_exactly_once'}, False),
           (2, {'empty_atlas_frees_only_atlas', 'no_dispose_on_null_terminator'}, False),
           (3, {'region_list_disposed_in_list_order', 'atlas_freed_exactly_once_and_last',
                 'every_node_disposed_exactly_once'}, False),
           (4, set(), True),
           (5, {'atlas_freed_exactly_once_and_last'}, False)]


def norm(s):
    s = s.replace('#', '')
    return re.sub(r'\b(fp|ip)\b', lambda m: {'fp': 'r11', 'ip': 'r12'}[m.group(1)], s)


def run(cmd, env=None):
    return subprocess.run([str(x) for x in cmd], text=True, capture_output=True,
                          env=env, timeout=180)


def static_gate():
    data = IMAGE.read_bytes()
    if hashlib.sha256(data).hexdigest() != IMAGE_SHA:
        raise SystemExit('original identity mismatch: ' + str(IMAGE))
    elf = ELFFile(io.BytesIO(data))

    def raw(a, n):
        for s in elf.iter_segments():
            if s['p_type'] == 'PT_LOAD' and s['p_vaddr'] <= a and a + n <= s['p_vaddr'] + s['p_filesz']:
                o = s['p_offset'] + a - s['p_vaddr']
                return data[o:o + n]
        raise SystemExit(f'unmapped original address {a:#x}')

    syms = {s.name: s for s in elf.get_section_by_name('.dynsym').iter_symbols()}
    for name, (addr, size) in SYMS.items():
        s = syms[name]
        assert s['st_value'] == addr and s['st_size'] == size, (name, hex(s['st_value']), s['st_size'])
        assert s['st_info']['type']=='STT_FUNC' and s['st_info']['bind']=='STB_GLOBAL', name
    md = Cs(CS_ARCH_ARM, CS_MODE_ARM | CS_MODE_LITTLE_ENDIAN)
    ins = list(md.disasm(raw(0x284120, 84), 0x284120))
    assert len(ins) == 21 and sum(i.size for i in ins) == 84, len(ins)
    got = [(i.address, i.mnemonic, norm(i.op_str)) for i in ins]
    assert got == EXPECT, [x for x in zip(got, EXPECT) if x[0] != x[1]]
    # next 在两次外调之前被读：284134/284154 的 ldr 必须严格在 284138/284158 的 bl 之前
    assert [i.mnemonic for i in ins[5:7]] == ['ldr', 'bl']
    assert [i.mnemonic for i in ins[13:15]] == ['ldr', 'bl']
    # 21 条里没有一条写 [r5]（atlas 自身只在尾部交给 _free，不在这儿写回）
    assert not [i for i in ins if i.mnemonic.startswith('str') and 'r5' in i.op_str]
    for addr, want in LAYOUT:
        x = list(md.disasm(raw(addr, 4), addr))[0]
        assert norm(x.op_str) == want, (hex(addr), x.mnemonic, norm(x.op_str), want)
    helpers = {
        0x2840b8: [('push','{r4, lr}'), ('mov','r4, r0'), ('bl','0xbd814'),
                   ('ldr','r0, [r4, 4]'), ('bl','0x285c80'), ('mov','r0, r4'),
                   ('pop','{r4, lr}'), ('b','0x285c80')],
        0x2840f4: [('push','{r4, lr}'), ('mov','r4, r0'), ('ldr','r0, [r0]'),
                   ('bl','0x285c80'), ('ldr','r0, [r4, 0x40]'), ('bl','0x285c80'),
                   ('ldr','r0, [r4, 0x44]'), ('bl','0x285c80'), ('mov','r0, r4'),
                   ('pop','{r4, lr}'), ('b','0x285c80')],
    }
    for addr, expected in helpers.items():
        decoded = list(md.disasm(raw(addr, 4*len(expected)), addr))
        assert [(i.mnemonic,norm(i.op_str)) for i in decoded] == expected, hex(addr)
        assert sum(i.size for i in decoded) == 4*len(expected), hex(addr)
    print('static: identity+dynsym+40 instructions (atlas/page/region)+layout PASS')


def main():
    if not __debug__:
        raise SystemExit('refuse optimized Python: assertions are required')
    if not shutil.which('qemu-arm'):
        raise SystemExit('qemu-arm missing: mandatory ARM32 lane cannot be skipped')
    static_gate()
    for p in (ROOT / 'src/atlas_dispose.c', ROOT / 'src/atlas_dispose.h',
              ROOT / 'fixture/atlas_free.c', SKEL / 'yy_skel_deps.h', RES / 'fx.h',
              RES / 'arm32_support.c'):
        print('BINDING', p, hashlib.sha256(p.read_bytes()).hexdigest())
    base = ['-std=c11', '-O2', '-Wall', '-Wextra', '-Werror', '-fno-builtin',
            '-I' + str(ROOT / 'src'), '-I' + str(SKEL), '-I' + str(RES)]
    arms = ['--target=armv7a-none-eabi', '-march=armv7-a', '-mfloat-abi=soft', '-marm',
            '-ffreestanding', '-nostdlib', '-static', '-fuse-ld=lld', '-Wl,-e,_start',
            '-DYY_FIXTURE_ARM', '-DFX_FREESTANDING=1']
    srcs = [ROOT / 'src/atlas_dispose.c', ROOT / 'fixture/atlas_free.c']
    with tempfile.TemporaryDirectory(prefix='cally-atlas-free-') as tmp:
        d = Path(tmp)
        env = dict(os.environ, TMPDIR=tmp)
        targets = [('host', [], []), ('arm32', arms, [RES / 'arm32_support.c'])]

        baseline = {}
        for tag, afl, sup in targets:
            for mode, flags, want in (('boundary', ['-DYY_ATLAS_HELPERS_EXTERN=1'], BASE_PASS),
                                      ('helper', [], HELPER_PASS)):
                exe = d / f'atlas-{tag}-{mode}'
                p = run(['clang', *base, *afl, *flags, *srcs, *sup, '-o', exe], env)
                if p.returncode:
                    raise SystemExit(f'build {tag}/{mode} failed\n{p.stdout}{p.stderr}')
                runner = ['qemu-arm'] if tag == 'arm32' else []
                p = run([*runner, exe], env)
                fails = re.findall(r'^\[FAIL\] (.+)$', p.stdout, re.M)
                passes = re.findall(r'^\[PASS\] (.+)$', p.stdout, re.M)
                if p.returncode != 0 or fails or passes != want or '[DONE] assertions=ALL PASS' not in p.stdout:
                    raise SystemExit(f'{tag}/{mode} rc={p.returncode} fails={fails} passes={passes}\n'
                                     f'{p.stdout}{p.stderr}')
                print(f'{tag}/{mode}: rc=0 assertions={len(passes)} ALL PASS')
                if mode == 'boundary':
                    baseline[tag] = p.stdout

        for tag, afl, sup in targets:
            runner = ['qemu-arm'] if tag == 'arm32' else []
            for mut, need, same in MUTANTS:
                exe = d / f'atlas-{tag}-m{mut}'
                p = run(['clang', *base, *afl, '-DYY_ATLAS_HELPERS_EXTERN=1', f'-DYY_MUTANT={mut}',
                         *srcs, *sup, '-o', exe], env)
                if p.returncode:
                    raise SystemExit(f'mutant {tag}/{mut} build failed\n{p.stdout}{p.stderr}')
                p = run([*runner, exe], env)
                fails = re.findall(r'^\[FAIL\] (.+)$', p.stdout, re.M)
                passes = re.findall(r'^\[PASS\] (.+)$', p.stdout, re.M)
                if len(passes)+len(fails)!=len(BASE_PASS) or set(passes)|set(fails)!=set(BASE_PASS):
                    raise SystemExit(f'mutant {tag}/{mut} incomplete assertion roster\n{p.stdout}')
                if same:
                    if p.returncode != 0 or p.stdout != baseline[tag]:
                        raise SystemExit(f'mutant {tag}/{mut} (no-op) changed output rc={p.returncode}\n{p.stdout}')
                    print(f'mutant {tag}/{mut} no-op: rc=0 byte-identical to baseline')
                    continue
                if p.returncode != 1:
                    raise SystemExit(f'mutant {tag}/{mut} rc={p.returncode} (crash or wrong exit)\n{p.stdout}{p.stderr}')
                if set(fails)!=need or len(fails)!=len(need):
                    raise SystemExit(f'mutant {tag}/{mut} wrong named failures {need!r}: {fails}\n{p.stdout}')
                print(f'mutant {tag}/{mut}: rc=1 named failures={fails}')
        helper_variants = [
            ('early-container', None, None, ['-DYY_MUTANT=5'],
             {'full_free_log_matches_instruction_order', 'atlas_freed_exactly_once_and_last'}),
            ('page-free-order',
             '    _free(yy_at(yy_ld32(page, SPATPAGE_NAME)));\n    _free(page);',
             '    _free(page);\n    _free(yy_at(yy_ld32(page, SPATPAGE_NAME)));', [],
             {'page_helper_frees_name_then_page', 'full_free_log_matches_instruction_order',
              'every_block_freed_exactly_once', 'empty_atlas_frees_only_atlas'}),
            ('region-free-order',
             '    _free(yy_at(yy_ld32(region, SPATREGION_SPLITS)));\n    _free(yy_at(yy_ld32(region, SPATREGION_PADS)));',
             '    _free(yy_at(yy_ld32(region, SPATREGION_PADS)));\n    _free(yy_at(yy_ld32(region, SPATREGION_SPLITS)));', [],
             {'region_helper_frees_name_splits_pads_then_region', 'full_free_log_matches_instruction_order'}),
        ]
        for tag, afl, sup in targets:
            runner = ['qemu-arm'] if tag == 'arm32' else []
            for name, old, new, extra, want_fails in helper_variants:
                source = srcs[0]
                if old is not None:
                    text = source.read_text()
                    if text.count(old)!=1: raise SystemExit('nonunique helper mutation: '+name)
                    source=d/f'helper-{tag}-{name}.c'; source.write_text(text.replace(old,new,1))
                exe=d/f'helper-{tag}-{name}'
                p=run(['clang',*base,*afl,*extra,source,srcs[1],*sup,'-o',exe],env)
                if p.returncode: raise SystemExit(f'helper {tag}/{name} build failed\n{p.stdout}{p.stderr}')
                p=run([*runner,exe],env)
                fails=re.findall(r'^\[FAIL\] (.+)$',p.stdout,re.M)
                passes=re.findall(r'^\[PASS\] (.+)$',p.stdout,re.M)
                if (p.returncode!=1 or set(fails)!=want_fails or len(fails)!=len(want_fails)
                        or len(passes)+len(fails)!=len(HELPER_PASS) or set(passes)|set(fails)!=set(HELPER_PASS)):
                    raise SystemExit(f'helper {tag}/{name} wrong failures\n{p.stdout}{p.stderr}')
                print(f'helper mutant {tag}/{name}: rc=1 named failures={fails}')
    print('ALL GREEN: static + mandatory host/ARM32; 4 boundary negatives, 3 helper negatives, no-op')


if __name__ == '__main__':
    main()
