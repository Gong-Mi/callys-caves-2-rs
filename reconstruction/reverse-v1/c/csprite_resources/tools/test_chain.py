#!/usr/bin/env python3
"""Static branch calibration + five-translation integration; never runs original."""
from pathlib import Path
import hashlib
import importlib.util
import io
import os
import re
import shutil
import subprocess
import tempfile
from elftools.elf.elffile import ELFFile
from capstone import Cs, CS_ARCH_ARM, CS_MODE_ARM, CS_MODE_LITTLE_ENDIAN

ROOT = Path(__file__).resolve().parents[1]
CLEAR = ROOT.parent / 'csprite_clear/src'
LOADER = ROOT.parent / 'csprite_loadfromchunk'
SO_SHA = '3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a'


def require(cmd, env):
    p = subprocess.run([str(x) for x in cmd], text=True, capture_output=True, env=env, timeout=90)
    if p.returncode:
        raise SystemExit(f'FAIL {cmd}: rc={p.returncode}\n{p.stdout}{p.stderr}')
    return p.stdout


def static_gate():
    so = Path(os.environ.get('CALLY_ORIGINAL_SO', '~/callys-caves-2-rs/reconstruction/live-mem/libyoyo_armv7.so')).expanduser()
    data = so.read_bytes()
    if hashlib.sha256(data).hexdigest() != SO_SHA:
        raise SystemExit('FAIL original identity')
    elf = ELFFile(io.BytesIO(data))
    syms = {s.name:s for s in elf.get_section_by_name('.dynsym').iter_symbols()}
    md = Cs(CS_ARCH_ARM, CS_MODE_ARM | CS_MODE_LITTLE_ENDIAN)
    decoded = {}
    for name, start, size in (
            ('_ZN7CSprite8FreeMaskEv',0x1e3b58,116),
            ('_ZN7CSprite11FreeTextureEv',0x1e56fc,76),
            ('_ZN7CSprite12ClearSWFDataEv',0x1e68b0,668)):
        s = syms[name]
        if int(s['st_value']) != start or int(s['st_size']) != size:
            raise SystemExit('FAIL symbol boundary '+name)
        for seg in elf.iter_segments():
            if seg['p_type']=='PT_LOAD' and seg['p_vaddr']<=start and start+size<=seg['p_vaddr']+seg['p_filesz']:
                off = seg['p_offset']+start-seg['p_vaddr']
                ins = list(md.disasm(data[off:off+size],start))
                break
        else:
            raise SystemExit('FAIL unmapped function')
        if sum(x.size for x in ins)!=size or len(ins)!=size//4:
            raise SystemExit('FAIL incomplete static decode '+name)
        decoded.update({i.address:i for i in ins})
        print('static symbol/decode', name, 'bytes='+str(size), 'items='+str(len(ins)))
    for addr, mnem in ((0x1e570c,'pople'),(0x1e693c,'beq'),(0x1e6958,'beq'),
                       (0x1e69f4,'bl'),(0x1e69ec,'bhi'),(0x1e6a94,'bhi')):
        i = decoded[addr]
        if i.mnemonic!=mnem:
            raise SystemExit(f'FAIL branch @ {addr:#x}: {i.mnemonic}, expected {mnem}')
        print(f'static predicate {addr:#x} {i.mnemonic} {i.op_str}')
    print('BOUNDARY: static decode and symbol verification, not original execution')


def main():
    static_gate()
    if not shutil.which('qemu-arm'):
        print('SKIP ARM32 chain; qemu-arm missing')
        return 2
    spec = importlib.util.spec_from_file_location('loader_flags', LOADER/'tools/run_tests.py')
    flags = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(flags)
    sources = [ROOT/'fixture/chain_resources.c', CLEAR/'csprite_clear.c',
               ROOT/'src/free_resources.c', ROOT/'src/clear_swf.c',
               LOADER/'src/csprite_loadfromchunk.c', LOADER/'src/test_doubles.c']
    for p in [*sources,CLEAR/'csprite_clear.h',LOADER/'src/csprite_loadfromchunk.h',
              LOADER/'src/test_doubles.h',ROOT/'fixture/fx.h',Path(__file__).resolve()]:
        print('BINDING', p, hashlib.sha256(p.read_bytes()).hexdigest())
    with tempfile.TemporaryDirectory(prefix='cally-full-resource-chain-') as tmp:
        d = Path(tmp)
        env = dict(os.environ,TMPDIR=tmp,LLVM_PROFILE_FILE=str(d/'profile-%p.profraw'))
        for tag, cf, runner in (('host',flags.HOST_FLAGS,[]),('arm32',flags.ARM_FLAGS,['qemu-arm'])):
            exe=d/tag
            extra=['-DFX_FREESTANDING'] if tag=='arm32' else ['-lm']
            require(['clang',*cf,'-DCSPRITE_CHAIN_WITH_REAL_CLEAR','-I'+str(CLEAR),
                     '-I'+str(LOADER/'src'),'-I'+str(ROOT/'fixture'),*sources,*extra,'-o',exe],env)
            out=require([*runner,exe],env)
            if len(re.findall(r'^PASS chain C[123] ',out,re.M))!=3 or 'ALL CHAIN OK' not in out:
                raise SystemExit('FAIL integrated chain roster\n'+out)
            nm=require(['llvm-nm','--defined-only',exe],env)
            for symbol in ('_ZN7CSprite13LoadFromChunkEP8YYSpritePh','_ZN7CSprite5ClearEv',
                           '_ZN7CSprite8FreeMaskEv','_ZN7CSprite11FreeTextureEv','_ZN7CSprite12ClearSWFDataEv'):
                if len(re.findall(r'\bT '+re.escape(symbol)+r'$',nm,re.M))!=1:
                    raise SystemExit('FAIL expected exactly one real definition '+symbol)
            print(tag+': 3/3 integration scenarios; 5 translated entry symbols: PASS')
    print('BOUNDARY: five recovered translations, synthetic allocator/graphics/builders; original not executed')
    return 0


if __name__=='__main__':
    raise SystemExit(main())
