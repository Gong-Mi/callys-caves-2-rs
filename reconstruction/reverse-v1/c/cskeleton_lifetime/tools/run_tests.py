#!/usr/bin/env python3
"""Static identity + lifecycle/decoder/five-layer synthetic integration.

No original execution. Freestanding ARM32 requires no ARM libc/sysroot.
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

ROOT=Path(__file__).resolve().parents[1]
C=ROOT.parent
SRC=ROOT/'src'
LOADER=C/'csprite_loadfromchunk'
CLEAR=C/'csprite_clear/src'
RES=C/'csprite_resources'
IMAGE_SHA='3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a'


def run(cmd,env):
    return subprocess.run([str(x) for x in cmd],text=True,capture_output=True,env=env,timeout=90)


def require(p,label):
    if p.returncode:
        raise SystemExit(f'FAIL {label} rc={p.returncode}\n{p.stdout}{p.stderr}')
    return p.stdout


def static_gate():
    p=Path(os.environ.get('CALLY_ORIGINAL_SO','~/callys-caves-2-rs/reconstruction/live-mem/libyoyo_armv7.so')).expanduser()
    data=p.read_bytes()
    if hashlib.sha256(data).hexdigest()!=IMAGE_SHA: raise SystemExit('original identity mismatch')
    elf=ELFFile(io.BytesIO(data))
    def raw(a,n):
        for s in elf.iter_segments():
            if s['p_type']=='PT_LOAD' and s['p_vaddr']<=a and a+n<=s['p_vaddr']+s['p_filesz']:
                o=s['p_offset']+a-s['p_vaddr'];return data[o:o+n]
        raise SystemExit(f'unmapped original address {a:#x}')
    def u32(a):return int.from_bytes(raw(a,4),'little')
    syms={s.name:s for s in elf.get_section_by_name('.dynsym').iter_symbols()}
    md=Cs(CS_ARCH_ARM,CS_MODE_ARM|CS_MODE_LITTLE_ENDIAN)
    all_ins={}
    for name,a,size,body,expected in (
        ('_ZN15CSkeletonSprite12SimpleDecodeEPhi',0xbd840,44,44,11),
        ('_ZN15CSkeletonSpriteC2EPcjjjjj',0xbd86c,164,156,39),
        ('_ZN15CSkeletonSpriteD2Ev',0xbd910,92,88,22)):
        s=syms[name];assert s['st_value']==a and s['st_size']==size,name
        ins=list(md.disasm(raw(a,body),a));assert len(ins)==expected and sum(x.size for x in ins)==body,name
        all_ins.update({x.address:x for x in ins})
        print('static decode',name,'instructions='+str(len(ins)),'literal_bytes='+str(size-body))
    for a,m,ops in ((0xbd844,'bxle','lr'),(0xbd900,'mov','r0, r4'),(0xbd95c,'mov','r0, r5'),
                    (0xbd94c,'strb','r3, [r4]'),(0xbd960,'strb','r3, [r4]')):
        x=all_ins[a];assert (x.mnemonic,x.op_str)==(m,ops),(hex(a),x.mnemonic,x.op_str)
    for alias,target in (('_ZN15CSkeletonSpriteC1EPcjjjjj','_ZN15CSkeletonSpriteC2EPcjjjjj'),
                         ('_ZN15CSkeletonSpriteD1Ev','_ZN15CSkeletonSpriteD2Ev')):
        assert syms[alias]['st_value']==syms[target]['st_value'] and syms[alias]['st_size']==syms[target]['st_size']
    assert 0xbd888+8+u32(0xbd908)==0x479c98
    empty=0xbd8dc+8+u32(0xbd90c);assert empty==0x32eb3e and raw(empty,1)==b'\0'
    assert 0xbd944+8+u32(0xbd968)==0x3ed920 and u32(0x3ed920)==0x479ca8
    f=syms['g_bFreeingSpineSprite'];assert f['st_value']==0x479ca8 and f['st_size']==1
    rel=[x for x in elf.get_section_by_name('.rel.dyn').iter_relocations() if x['r_offset']==0x3ed920]
    assert len(rel)==1 and rel[0]['r_info_type']==23 and rel[0]['r_info_sym']==0
    print('static predicates, this returns, aliases, anonymous context/flag GOT and empty string: PASS')


def main():
    static_gate()
    if not shutil.which('qemu-arm'):
        print('SKIP ARM32 runtime: qemu-arm missing');return 2
    files=[SRC/'skeleton_lifetime.c',SRC/'yy_skel_deps.h',SRC/'simple_decode.c',
           ROOT/'fixture/lifetime.c',ROOT/'fixture/decode.c',ROOT/'fixture/full_chain.c',
           CLEAR/'csprite_clear.h',CLEAR/'csprite_clear.c',RES/'fixture/arm32_support.c',RES/'fixture/fx.h',
           RES/'src/free_resources.c',RES/'src/clear_swf.c',LOADER/'src/csprite_loadfromchunk.h',
           LOADER/'src/csprite_loadfromchunk.c',LOADER/'src/test_doubles.c',Path(__file__).resolve()]
    for p in files:print('BINDING',p,hashlib.sha256(p.read_bytes()).hexdigest())
    with tempfile.TemporaryDirectory(prefix='cally-skeleton-') as tmp:
        d=Path(tmp);env=dict(os.environ,TMPDIR=tmp,LLVM_PROFILE_FILE=str(d/'p-%p.profraw'))
        base=['-std=c11','-O2','-Wall','-Wextra','-Werror','-fno-builtin','-I'+str(SRC)]
        arms=['--target=armv7a-none-eabi','-march=armv7-a','-mfloat-abi=soft','-marm','-ffreestanding',
              '-nostdlib','-static','-fuse-ld=lld','-Wl,-e,_start','-DYY_FIXTURE_ARM']
        for tag,flags,runner in (('host',base,[]),('arm32',base+arms,['qemu-arm'])):
            support=[RES/'fixture/arm32_support.c'] if tag=='arm32' else []
            baseline=None
            for mut,failed in ((0,None),(1,'ctor_read_data_uses_base_pointer'),(2,'dtor_clears_flag_when_atlas_is_null'),(3,None)):
                exe=d/f'life-{tag}-{mut}'
                require(run(['clang',*flags,f'-DYY_MUTANT={mut}',SRC/'skeleton_lifetime.c',ROOT/'fixture/lifetime.c',*support,'-o',exe],env),'lifetime build')
                p=run([*runner,exe],env)
                failures=re.findall(r'^\[FAIL\] (.+)$',p.stdout,re.M)
                passes=re.findall(r'^\[PASS\] (.+)$',p.stdout,re.M)
                want=[] if failed is None else [failed]
                if p.returncode!=(0 if failed is None else 1) or failures!=want or len(passes)+len(failures)!=17:
                    raise SystemExit(f'lifetime {tag}/{mut} unexpected rc={p.returncode}\n{p.stdout}{p.stderr}')
                if mut==0:baseline=p.stdout
                if mut==3 and baseline!=p.stdout:raise SystemExit('lifetime no-op changed output')
                print('lifetime',tag,'mutant='+str(mut),'rc='+str(p.returncode),'failures='+str(failures))
            for mut,old,new,marker in ((0,None,None,None),(1,'uint32_t key = 42;','uint32_t key = 43;','all_byte_one_step'),
                    (2,'key = key * key + key;','key = 42;','recurrence_vector')):
                source=SRC/'simple_decode.c'
                if old:
                    t=source.read_text();assert t.count(old)==1
                    source=d/f'decode-{tag}-{mut}.c';source.write_text(t.replace(old,new,1))
                exe=d/f'decode-{tag}-{mut}'
                require(run(['clang',*flags,source,ROOT/'fixture/decode.c','-o',exe],env),'decode build')
                p=run([*runner,exe],env)
                if marker is None:
                    assert p.returncode==0 and p.stdout.count('PASS ')==4,(p.returncode,p.stdout,p.stderr)
                elif p.returncode!=1 or f'FAIL {marker}' not in p.stdout:
                    raise SystemExit(f'decode mutation invalid {tag}/{mut}\n{p.stdout}{p.stderr}')
                print('decode',tag,'mutant='+str(mut),'rc='+str(p.returncode))
        obj=d/'life.o'
        require(run(['clang',*base,'--target=armv7a-none-eabi','-ffreestanding','-c',SRC/'skeleton_lifetime.c','-o',obj],env),'alias object')
        nm=require(run(['llvm-nm','--defined-only',obj],env),'alias nm')
        defs={m.group(2):m.group(1) for m in re.finditer(r'^([0-9a-f]+)\s+T\s+(\S+)$',nm,re.M)}
        for a,b in (('_ZN15CSkeletonSpriteC1EPcjjjjj','_ZN15CSkeletonSpriteC2EPcjjjjj'),('_ZN15CSkeletonSpriteD1Ev','_ZN15CSkeletonSpriteD2Ev')):
            assert a in defs and b in defs and defs[a]==defs[b]
        print('ARM32 C1/C2 and D1/D2 same-address aliases: PASS')
        # Anonymous native storage is a required host binding, never a raw VA fallback.
        t=(ROOT/'fixture/lifetime.c').read_text();old='yy_glob_479c98 g_yy_479c98;';assert t.count(old)==1
        missing=d/'missing-storage.c';missing.write_text(t.replace(old,'',1))
        p=run(['clang',*base,SRC/'skeleton_lifetime.c',missing,'-o',d/'unbound'],env)
        if p.returncode==0 or 'g_yy_479c98' not in p.stderr:raise SystemExit('missing storage provider was not refused')
        print('missing anonymous-context provider: link refused as required')
        spec=importlib.util.spec_from_file_location('loader_flags',LOADER/'tools/run_tests.py')
        lf=importlib.util.module_from_spec(spec);spec.loader.exec_module(lf)
        sources=[ROOT/'fixture/full_chain.c',SRC/'skeleton_lifetime.c',SRC/'simple_decode.c',
                 CLEAR/'csprite_clear.c',RES/'src/free_resources.c',RES/'src/clear_swf.c',
                 LOADER/'src/csprite_loadfromchunk.c',LOADER/'src/test_doubles.c']
        for tag,flags,runner,extra in (('host',lf.HOST_FLAGS,[],['-lm']),('arm32',lf.ARM_FLAGS,['qemu-arm'],['-DFX_FREESTANDING'])):
            exe=d/f'chain-{tag}'
            require(run(['clang',*flags,'-I'+str(SRC),'-I'+str(CLEAR),'-I'+str(RES/'fixture'),
                         '-DCSPRITE_CHAIN_WITH_REAL_CLEAR','-DCSPRITE_CHAIN_WITH_REAL_SKELETON',
                         *sources,*extra,'-o',exe],env),'eight-translation chain build')
            out=require(run([*runner,exe],env),'eight-translation chain run')
            if len(re.findall(r'^PASS chain C[1234] ',out,re.M))!=4 or 'ALL CHAIN OK' not in out:
                raise SystemExit('full chain roster mismatch\n'+out)
            print('full chain',tag,'4/4 scenarios, includes actual ctor/decode/D2 via Loader/Clear: PASS')
    print('BOUNDARY: static proof plus synthetic dependencies; no original, ART or Unicorn execution')
    return 0


if __name__=='__main__':raise SystemExit(main())
