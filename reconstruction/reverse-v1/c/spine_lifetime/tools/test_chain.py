#!/usr/bin/env python3
"""Static page-texture proof and reconstructed-C consumer integration.

Never loads or executes the original. Mandatory host and ARM32/qemu lanes run
only the translated C with typed, explicitly synthetic dependency providers.
"""
from pathlib import Path
import hashlib
import importlib.util
import io
import os
import re
import shutil
import subprocess
import tempfile
from capstone import Cs, CS_ARCH_ARM, CS_MODE_ARM, CS_MODE_LITTLE_ENDIAN
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[1]
C = ROOT.parent
SRC = ROOT / 'src'
SKEL = C / 'cskeleton_lifetime/src'
RES = C / 'csprite_resources'
LOADER = C / 'csprite_loadfromchunk'
CLEAR = C / 'csprite_clear/src'
IMAGE = Path(os.environ.get('CALLY_ORIGINAL_SO',
    '~/callys-caves-2-rs/reconstruction/live-mem/libyoyo_armv7.so')).expanduser()
IMAGE_SHA = '3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a'
CHAIN_CASES = ['chain_populated_spine', 'chain_unowned_json_empty_atlas',
               'chain_null_atlas_and_data', 'chain_empty_dtor']
TEXTURE_CASES = ['zero_id_gate', 'zero_flag_gate', 'positive_flag_forwards',
                 'any_nonzero_flag_forwards_bits']


def module(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    m = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(m)
    return m


def run(cmd, env):
    return subprocess.run([str(x) for x in cmd], env=env, capture_output=True,
                          text=True, timeout=120)


def require(p, label):
    if p.returncode:
        raise SystemExit(f'{label} rc={p.returncode}\n{p.stdout}{p.stderr}')
    return p.stdout


def edit(text, old, new):
    if text.count(old) != 1:
        raise SystemExit(f'nonunique mutation anchor: {old!r}')
    return text.replace(old, new, 1)


def static_gate():
    data = IMAGE.read_bytes()
    if hashlib.sha256(data).hexdigest() != IMAGE_SHA:
        raise SystemExit('original identity mismatch')
    elf = ELFFile(io.BytesIO(data))
    def raw(a, n):
        for s in elf.iter_segments():
            if s['p_type']=='PT_LOAD' and s['p_vaddr']<=a and a+n<=s['p_vaddr']+s['p_filesz']:
                o=s['p_offset']+a-s['p_vaddr']; return data[o:o+n]
        raise SystemExit(f'unmapped original address {a:#x}')
    syms={s.name:s for s in elf.get_section_by_name('.dynsym').iter_symbols()}
    symbol=syms['_spAtlasPage_disposeTexture']
    assert symbol['st_value']==0xbd814 and symbol['st_size']==40
    expected=[('ldr','r0, [r0, #0x1c]'), ('cmp','r0, #0'), ('bxeq','lr'),
              ('ldr','r3, [pc, #0x10]'), ('ldr','r3, [pc, r3]'),
              ('ldrb','r3, [r3]'), ('cmp','r3, #0'), ('bxeq','lr'),
              ('b','#0x173f84')]
    md=Cs(CS_ARCH_ARM,CS_MODE_ARM|CS_MODE_LITTLE_ENDIAN)
    ins=list(md.disasm(raw(0xbd814,36),0xbd814))
    assert [(i.mnemonic,i.op_str) for i in ins]==expected
    assert sum(i.size for i in ins)==36
    literal=int.from_bytes(raw(0xbd838,4),'little')
    slot=0xbd824+8+literal
    assert slot==0x3ed920 and int.from_bytes(raw(slot,4),'little')==0x479ca8
    rel=[r for r in elf.get_section_by_name('.rel.dyn').iter_relocations() if r['r_offset']==slot]
    assert len(rel)==1 and rel[0]['r_info_type']==23 and rel[0]['r_info_sym']==0
    flag=syms['g_bFreeingSpineSprite']
    assert flag['st_value']==0x479ca8 and flag['st_size']==1
    assert syms['_Z15GR_Texture_Freei']['st_value']==0x173f84
    print('static texture: 9 instructions + 4-byte literal, GOT, relocation and byte flag PASS')


def main():
    if not __debug__:
        raise SystemExit('refuse optimized Python: assertions are required')
    if not shutil.which('qemu-arm'):
        raise SystemExit('qemu-arm missing: mandatory ARM32 lane cannot be skipped')
    static_gate()
    files=[*sorted(SRC.glob('*.[ch]')), ROOT/'fixture/chain.c', ROOT/'fixture/atlas_texture.c',
           SKEL/'skeleton_lifetime.c', SKEL/'simple_decode.c', SKEL/'yy_skel_deps.h',
           LOADER/'src/csprite_loadfromchunk.c',LOADER/'src/csprite_loadfromchunk.h',
           LOADER/'src/test_doubles.c',LOADER/'src/test_doubles.h',LOADER/'tools/run_tests.py',
           CLEAR/'csprite_clear.c',CLEAR/'csprite_clear.h',RES/'src/free_resources.c',
           RES/'src/clear_swf.c',RES/'fixture/fx.h',RES/'fixture/arm32_support.c',Path(__file__)]
    before={p:hashlib.sha256(p.read_bytes()).hexdigest() for p in files}
    for p,digest in before.items(): print('BINDING',p,digest)
    common=['-std=c11','-O2','-Wall','-Wextra','-Werror','-fno-builtin',
            '-I'+str(SRC),'-I'+str(SKEL),'-I'+str(RES/'fixture'),
            '-DYY_SKEL_DEPS_HDR="'+str(SKEL/'yy_skel_deps.h')+'"']
    arm=['--target=armv7a-none-eabi','-march=armv7-a','-mfloat-abi=soft','-marm',
         '-ffreestanding','-nostdlib','-static','-fuse-ld=lld','-Wl,-e,_start','-DFX_FREESTANDING']
    tex=SRC/'atlas_texture.c'; text=tex.read_text()
    tex_variants=[('base',None,None,None),
        ('omit-id-gate','    if (id == 0) return;', '    (void)0;', 'zero_id_gate'),
        ('omit-flag-gate','    if (g_bFreeingSpineSprite == 0) return;', '    (void)0;', 'zero_flag_gate'),
        ('wrong-id','GR_Texture_Free(id);','GR_Texture_Free(0);','positive_flag_forwards'),
        ('narrow-flag','g_bFreeingSpineSprite == 0','g_bFreeingSpineSprite != 1','any_nonzero_flag_forwards_bits'),
        ('reject-negative','if (id == 0)','if (id <= 0)','any_nonzero_flag_forwards_bits'),
        ('noop','Static translation;','Static translation (no-op comment);',None)]
    with tempfile.TemporaryDirectory(prefix='cally-spine-chain-') as tmp:
        d=Path(tmp); env=dict(os.environ,TMPDIR=tmp,LLVM_PROFILE_FILE='/dev/null')
        for tag,flags,runner,support in (
            ('host',common,[],[]),('arm32',common+arm,['qemu-arm'],[RES/'fixture/arm32_support.c'])):
            baseline=None
            for name,old,new,failed in tex_variants:
                source=tex
                if old:
                    source=d/f'tex-{tag}-{name}.c'; source.write_text(edit(text,old,new))
                exe=d/f'tex-{tag}-{name}'
                require(run(['clang',*flags,source,ROOT/'fixture/atlas_texture.c',*support,'-o',exe],env),'texture build')
                p=run([*runner,exe],env)
                passes=re.findall(r'^PASS (.+)$',p.stdout,re.M)
                failures=re.findall(r'^FAIL (.+)$',p.stdout,re.M)
                if failed:
                    if p.returncode!=1 or failures!=[failed]:
                        raise SystemExit(f'texture {tag}/{name} invalid negative\n{p.stdout}{p.stderr}')
                elif p.returncode!=0 or passes!=TEXTURE_CASES or failures:
                    raise SystemExit(f'texture {tag}/{name} missing cases\n{p.stdout}{p.stderr}')
                if name=='base': baseline=p.stdout
                if name=='noop' and p.stdout!=baseline: raise SystemExit('texture no-op changed output')
                print('texture',tag,name,'rc='+str(p.returncode),'failures='+str(failures))
        # Missing graphics binding must fail to link, not become a no-op provider.
        fixture=(ROOT/'fixture/atlas_texture.c').read_text()
        cut=d/'unbound-texture.c'
        cut.write_text(edit(fixture,'void GR_Texture_Free(int id) { ++calls;last=id; }',''))
        obj=d/'texture-required-provider.o'
        require(run(['clang',*common,'-c',tex,'-o',obj],env),'texture provider object')
        undefined=require(run(['llvm-nm','-u',obj],env),'texture required symbols')
        if '_Z15GR_Texture_Freei' not in undefined.split():
            raise SystemExit('texture object does not require the actual graphics symbol')
        cut_obj=d/'unbound-texture.o'
        require(run(['clang',*common,'-c',cut,'-o',cut_obj],env),'unbound provider fixture')
        p=run(['clang',obj,cut_obj,'-o',d/'unbound-texture'],env)
        if p.returncode==0 or 'undefined symbol: GR_Texture_Free(int)' not in p.stderr:
            raise SystemExit(f'missing graphics provider was not refused\n{p.stdout}{p.stderr}')
        print('missing graphics provider: link refused as required')

        lf=module('spine_loader_flags',LOADER/'tools/run_tests.py')
        sources=[ROOT/'fixture/chain.c',SKEL/'skeleton_lifetime.c',SKEL/'simple_decode.c',
                 SRC/'spine_json_lifetime.c',SRC/'atlas_dispose.c',tex,
                 CLEAR/'csprite_clear.c',RES/'src/free_resources.c',RES/'src/clear_swf.c',
                 LOADER/'src/csprite_loadfromchunk.c',LOADER/'src/test_doubles.c']
        variants=[('base',None,None,None),
            ('json-misses-loader-release',SRC/'spine_json_lifetime.c',
             '        spAttachmentLoader_dispose((spAttachmentLoader *)(uintptr_t)j->loader);', '        (void)j->loader;'),
            ('texture-not-consumed',tex,'GR_Texture_Free(id);','(void)id;'),
            ('page-name-cached',SRC/'atlas_dispose.c',
             '    _spAtlasPage_disposeTexture(page);\n    _free(yy_at(yy_ld32(page, SPATPAGE_NAME)));',
             '    uint32_t cached_name = yy_ld32(page, SPATPAGE_NAME);\n    _spAtlasPage_disposeTexture(page);\n    _free(yy_at(cached_name));'),
            ('json-field-cached',SRC/'spine_json_lifetime.c',
             '    _free((void *)(uintptr_t)j->unk_18);',
             '    uint32_t cached_08 = j->unk_08;\n    _free((void *)(uintptr_t)j->unk_18);'),
            ('noop',tex,'Static translation;','Static translation (no-op comment);')]
        includes=['-I'+str(SRC),'-I'+str(SKEL),'-I'+str(CLEAR),'-I'+str(RES/'fixture'),
                  '-DCSPRITE_CHAIN_WITH_REAL_CLEAR','-DCSPRITE_CHAIN_WITH_REAL_SKELETON',
                  '-DYY_SKEL_DEPS_HDR="'+str(SKEL/'yy_skel_deps.h')+'"']
        for tag,flags,runner,extra in (
            ('host',lf.HOST_FLAGS,[],['-lm']),
            ('arm32',lf.ARM_FLAGS,['qemu-arm'],['-DFX_FREESTANDING'])):
            baseline=None
            for name,subject,old,new in variants:
                used=list(sources)
                if subject:
                    variant=d/f'chain-{tag}-{name}.c'
                    candidate=edit(subject.read_text(),old,new)
                    if name=='json-field-cached':
                        candidate=edit(candidate,'_free((void *)(uintptr_t)j->unk_08);','_free((void *)(uintptr_t)cached_08);')
                    variant.write_text(candidate); used[used.index(subject)]=variant
                exe=d/f'chain-{tag}-{name}'
                require(run(['clang',*flags,*includes,*used,*extra,'-o',exe],env),'chain build')
                p=run([*runner,exe],env)
                failures=re.findall(r'^FAIL (.+)$',p.stdout,re.M)
                passes=re.findall(r'^PASS (.+)$',p.stdout,re.M)
                if name in ('base','noop'):
                    if p.returncode!=0 or passes!=CHAIN_CASES or failures:
                        raise SystemExit(f'chain {tag}/{name} missing cases\n{p.stdout}{p.stderr}')
                    if name=='base': baseline=p.stdout
                    elif baseline!=p.stdout: raise SystemExit('chain no-op changed output')
                elif p.returncode!=1 or failures!=['chain_release_trace']:
                    raise SystemExit(f'chain {tag}/{name} invalid negative\n{p.stdout}{p.stderr}')
                print('consumer chain',tag,name,'rc='+str(p.returncode),'cases='+str(len(passes)),
                      'failures='+str(failures))
    after={p:hashlib.sha256(p.read_bytes()).hexdigest() for p in files}
    if before!=after: raise SystemExit('candidate inputs changed during acceptance')
    print('BOUNDARY: original static read only; reconstructed host+ARM32; allocation/parser/GPU providers synthetic')
    return 0


if __name__=='__main__': raise SystemExit(main())
