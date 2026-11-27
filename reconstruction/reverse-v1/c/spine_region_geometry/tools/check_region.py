#!/usr/bin/env python3
"""Original is read-only. Execute only rebuilt ARM32 region C + synthetic libm.
PASS is a scoped reconstructed-consumer verdict, never an original equivalence claim.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import subprocess
from collections import Counter
from capstone import Cs, CS_ARCH_ARM, CS_MODE_ARM
from elftools.elf.elffile import ELFFile

C=Path(__file__).resolve().parents[2]
MOD=C/'spine_region_geometry'
FIX=MOD/'fixture/check.c'
BODY=MOD/'src/spine_region_geometry.c'
CALLER=C/'spine_read_region/src/spine_read_region.c'
PIN='3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a'
NUMERIC={'vdiv.f32','vmul.f32','vnmul.f32','vmla.f32','vadd.f32','vsub.f32','vcvt.f32.s32','vcvt.f64.f32','vcvt.f32.f64','vfma.f32','vfms.f32'}
SOURCES=[C/p for p in (
 'spine_alloc/src/spine_alloc.c','spine_atlas_attachment/src/spine_atlas_attachment.c',
 'spine_attachment/src/spine_attachment.c','spine_skeleton_data/src/spine_skeleton_data.c',
 'spine_lifetime/src/spine_json_lifetime.c','json_interface/src/json_interface.c',
 'csprite_resources/fixture/arm32_support.c','spine_read_vertices/src/spine_read_vertices.c',
 'spine_mesh/src/spine_mesh.c','spine_color/src/spine_color.c','spine_read_mesh/src/spine_read_mesh.c',
)]+[BODY,CALLER,FIX]
INCLUDES=[C/p/'src' for p in (
 'spine_alloc','spine_attachment','spine_skeleton_data','spine_atlas_attachment',
 'json_interface','spine_read_vertices','spine_mesh','spine_color','spine_read_mesh',
 'spine_region_geometry','spine_read_region',
)]
FLAGS=['--target=armv7a-none-eabi','-march=armv7-a','-marm','-mfpu=vfpv3',
 '-mfloat-abi=softfp','-std=c11','-ffreestanding','-fno-builtin','-ffp-contract=off',
 '-fstack-protector-strong','-mstack-protector-guard=global','-ffunction-sections',
 '-fdata-sections','-Wall','-Wextra','-Werror','-nostdlib','-static','-fuse-ld=lld',
 '-Wl,--gc-sections','-Wl,-e,_start']
TESTS=[
 'geometry_identity_and_exact_write_scope','geometry_trim_scale_and_prescribed_math_results',
 'geometry_supplied_cos0_sin1','geometry_signed_integer_dimensions_and_trim',
 'geometry_snapshots_before_math_and_xy_after_sin','geometry_double_cos_narrowing_precedes_sin',
 'geometry_zero_dimensions_keeps_vfp_effects','geometry_retains_original_no_canary_property',
 'reader_default_fields_factory_geometry_configure_cleanup','reader_scale_reloaded_after_each_json_lookup',
 'reader_color_uses_actual_s0_return_helper','reader_invalid_color_uses_actual_color_helper',
 'reader_path_publication_and_null_path_skip','reader_loader_reloaded_after_geometry_math_callbacks',
]

def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def run(argv,timeout=60):return subprocess.run([str(x) for x in argv],text=True,capture_output=True,timeout=timeout)
def replace_once(text,old,new):
 if text.count(old)!=1:raise ValueError('mutation site not unique: '+old)
 return text.replace(old,new,1)

def static(so):
 if sha(so)!=PIN:raise ValueError('original SHA mismatch')
 with so.open('rb') as f:
  e=ELFFile(f);segs=[(s['p_vaddr'],s.data()) for s in e.iter_segments() if s['p_type']=='PT_LOAD']
  syms={s.name:(s['st_value'],s['st_size'],s['st_shndx']) for s in e.get_section_by_name('.dynsym').iter_symbols()}
  plt=e.get_section_by_name('.plt')['sh_addr'];symtab=e.get_section_by_name('.dynsym')
  rels=list(e.get_section_by_name('.rel.plt').iter_relocations())
  imports={hex(a):symtab.get_symbol(rels[(a-plt-20)//12]['r_info_sym']).name for a in (0xb67e4,0xb67d8)}
  ex=e.get_section_by_name('.ARM.exidx');ed,ea=ex.data(),ex['sh_addr']
 def raw(a,n):
  for va,data in segs:
   if va<=a and a+n<=va+len(data):return data[a-va:a-va+n]
  raise ValueError('unmapped original '+hex(a))
 exstarts=[]
 for off in range(0,len(ed),8):
  v=struct.unpack_from('<I',ed,off)[0]&0x7fffffff
  if v&(1<<30):v-=1<<31
  exstarts.append((ea+off+v)&0xffffffff)
 if syms['spRegionAttachment_updateOffset'][:2]!=(0x289040,308):raise ValueError('original symbol/ISA/size changed')
 if not all(a in exstarts for a in (0x289040,0x289174)):raise ValueError('exidx boundary mismatch')
 if imports!={'0xb67e4':'cos','0xb67d8':'sin'} or any(syms[n][2]!='SHN_UNDEF' for n in ('cos','sin')):raise ValueError('double math import mapping changed')
 if raw(0x289170,4)!=struct.pack('<I',0x3c8efa35):raise ValueError('degree multiplier changed')
 md=Cs(CS_ARCH_ARM,CS_MODE_ARM);rows=[]
 for name,start,ce,end in (('spRegionAttachment_updateOffset',0x289040,0x289170,0x289174),('region_caller_BLOCK',0x28cdac,0x28cf24,0x28cf24)):
  ins=[{'va':hex(i.address),'mnemonic':i.mnemonic,'operands':i.op_str} for i in md.disasm(raw(start,ce-start),start)]
  if len(ins)*4!=ce-start:raise ValueError('incomplete decode '+name)
  rows.append({'name':name,'entry':hex(start),'code_end_exclusive':hex(ce),'end_exclusive':hex(end),
   'body_sha256':hashlib.sha256(raw(start,end-start)).hexdigest(),'literal_bytes':end-ce,'instructions':ins})
 literals=[]
 for pool,add,want in ((0x28c988,0x28cdc4,'jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c'),
   (0x28c98c,0x28cde8,'x'),(0x28c990,0x28cdfc,'y'),(0x28c994,0x28ce20,'scaleX'),(0x28c998,0x28ce40,'scaleY'),
   (0x28c99c,0x28ce58,'rotation'),(0x28c9a0,0x28ce70,'width'),(0x28c9a4,0x28ce8c,'height'),(0x28c9a8,0x28ceb0,'color')):
  a=(add+8+struct.unpack('<I',raw(pool,4))[0])&0xffffffff;value=raw(a,90).split(b'\0',1)[0].decode('ascii')
  if value!=want:raise ValueError(f'PC-relative key mismatch {add:#x}: {value!r} != {want!r}')
  literals.append({'pool':hex(pool),'add':hex(add),'va':hex(a),'value':value})
 return {'original_sha256':PIN,'functions':rows,'imports':imports,'caller_keys':literals,'note':'Static anchors, not original execution/equivalence'}

def dependency_binding():
 flags=[f for f in FLAGS if not f.startswith(('-Wl,','-fuse-ld=')) and f not in ('-nostdlib','-static')]
 deps=set(SOURCES)|{Path(__file__).resolve()}
 for src in SOURCES:
  p=run(['clang',*flags,*['-I'+str(i) for i in INCLUDES],'-MM',src])
  if p.returncode:raise RuntimeError(p.stderr)
  deps.update(Path(x).resolve() for x in p.stdout.replace('\\\n','').split(':',1)[1].split())
 return {str(p):sha(p) for p in sorted(deps)}

def arithmetic_counts(binary):
 """Decode only ELF $a ranges inside the exact rebuilt function, not pools."""
 with binary.open('rb') as f:
  e=ELFFile(f);symtab=e.get_section_by_name('.symtab');allsyms=list(symtab.iter_symbols())
  sym=next(s for s in allsyms if s.name=='spRegionAttachment_updateOffset')
  if sym['st_value']&1:raise ValueError('rebuilt function unexpectedly Thumb')
  sec=e.get_section(sym['st_shndx']);data=sec.data();base=sec['sh_addr'];start=sym['st_value'];end=start+sym['st_size']
  maps=sorted((s['st_value'],s.name) for s in allsyms if s['st_shndx']==sym['st_shndx'] and s.name.startswith(('$a','$d')))
  kind=next((name for a,name in reversed(maps) if a<=start),'$a')
  cuts=[(start,kind)]+[(a,name) for a,name in maps if start<a<end]+[(end,'end')]
  md=Cs(CS_ARCH_ARM,CS_MODE_ARM);ins=[]
  for (a,kind),(b,_) in zip(cuts,cuts[1:]):
   if kind.startswith('$a'):
    part=list(md.disasm(data[a-base:b-base],a))
    if len(part)*4!=b-a:raise ValueError('rebuilt numeric code decode incomplete')
    ins.extend(part)
  return dict(Counter(i.mnemonic for i in ins if i.mnemonic in NUMERIC))

def build(out,name,opt='-O2',overrides=None,extra=(),omit=()):
 used=[(overrides or {}).get(p,p) for p in SOURCES if p not in omit]
 binary=out/(name+'.arm');argv=['clang',*FLAGS,opt,*extra,*['-I'+str(i) for i in INCLUDES],*used,'-o',binary]
 p=run(argv);(out/(name+'.build.log')).write_text(p.stdout+p.stderr)
 result={'compile_rc':p.returncode,'compile_command':[str(x) for x in argv]}
 if p.returncode:return {**result,'diagnostic':p.stderr}
 before=sha(binary);result['binary_sha256']=before
 result['translation_units']={str(s):sha(s) for s in used}
 print('BINDING v1 entry=region-consumer run='+name+' original_sha256='+PIN+' fixture_sha256='+sha(FIX)+' binary_sha256='+before,flush=True)
 p=run(['qemu-arm',binary],15);(out/(name+'.log')).write_text(p.stdout+p.stderr)
 if sha(binary)!=before:raise RuntimeError('executed binary drift')
 return {**result,'exit_code':p.returncode,'stdout':p.stdout,'stderr':p.stderr,
  'passes':re.findall(r'^PASS (.+)$',p.stdout,re.M),'failures':re.findall(r'^FAIL (.+)$',p.stdout,re.M)}

def mutations():
 return [
 ('geometry_unsigned_dimensions',BODY,[('vcvt.f32.s32','vcvt.f32.u32')]),
 ('geometry_wrong_degree_constant',BODY,[('degree_bits=0x3c8efa35u','degree_bits=0x3c8efa34u')]),
 ('geometry_double_multiply_before_narrow',BODY,[('double angle=widen(radians);','double angle=(double)rotation*(double)degree;(void)widen(radians);')]),
 ('geometry_xy_cached_before_math',BODY,[('double cos_result=cos(angle);','float early_x=ld(&a->x),early_y=ld(&a->y);double cos_result=cos(angle);'),('float x=ld(&a->x),y=ld(&a->y);','float x=early_x,y=early_y;')]),
 ('geometry_angle_reread_for_sin',BODY,[('double sin_result=sin(angle);','double sin_result=sin(widen(mul32(ld(&a->rotation),degree)));')]),
 ('geometry_cos_narrow_after_sin',BODY,[('float co=narrow(cos_result);','float co;'),('double sin_result=sin(angle);','double sin_result=sin(angle);co=narrow(cos_result);')]),
 ('geometry_math_calls_reversed',BODY,[('double cos_result=cos(angle);','double cos_result=sin(angle);'),('double sin_result=sin(angle);','double sin_result=cos(angle);')]),
 ('geometry_late_region_width_read',BODY,[('double cos_result=cos(angle);','double cos_result=cos(angle);x2=mla32(x1,i32f(ld(&a->regionWidth)),rx);')]),
 ('geometry_trim_ignored',BODY,[('float x1=mul32(ox,rx);','float x1=mul32(ox*0.0f,rx);')]),
 ('geometry_wrong_y_sign',BODY,[('float o1=add32(yb,x1s);','float o1=sub32(yb,x1s);')]),
 ('geometry_wrong_output_corner',BODY,[('st(&a->offset[2],o2);','st(&a->offset[2],o4);(void)o2;')]),
 ('reader_width_default_zero',CALLER,[('Json_getFloat(map,"width",32.0f)','Json_getFloat(map,"width",0.0f)')]),
 ('reader_height_default_zero',CALLER,[('Json_getFloat(map,"height",32.0f)','Json_getFloat(map,"height",0.0f)')]),
 ('reader_skip_color',CALLER,[('if(color) {','if(color&&0) {')]),
 ('reader_skip_geometry',CALLER,[('spRegionAttachment_updateOffset(a);','(void)a;')]),
 ('reader_loader_cached_before_math',CALLER,[('    if(path) {','    spAttachmentLoader *cached_loader=(spAttachmentLoader *)(uintptr_t)j->loader;\n    if(path) {'),('spAttachmentLoader *loader=(spAttachmentLoader *)(uintptr_t)j->loader;','spAttachmentLoader *loader=cached_loader;')]),
 ('reader_null_path_guard_removed',CALLER,[('if(path) {','if(1) {')]),
 ('reader_wrong_path_line',CALLER,[('tag,891u','tag,892u')]),
 ('reader_parser_scale_cached_before_getters',CALLER,[('    if(path) {','    float cached_scale=current_scale(j);\n    if(path) {'),('float scale=current_scale(j);store','float scale=cached_scale;store'),('value=Json_getFloat(map,"y",0.0f);scale=current_scale(j);','value=Json_getFloat(map,"y",0.0f);scale=cached_scale;'),('value=Json_getFloat(map,"width",32.0f);scale=current_scale(j);','value=Json_getFloat(map,"width",32.0f);scale=cached_scale;'),('value=Json_getFloat(map,"height",32.0f);scale=current_scale(j);','value=Json_getFloat(map,"height",32.0f);scale=cached_scale;')]),
 ]

def main():
 ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('--so',type=Path,required=True);ap.add_argument('--out',type=Path,required=True);ap.add_argument('--smoke',action='store_true');ns=ap.parse_args()
 ns.out.mkdir(parents=True,exist_ok=False);tmp=ns.out/'compiler-tmp';tmp.mkdir();os.environ['TMPDIR']=str(tmp)
 report={'schema':'cally-region-consumer-check/1','tier':'test_anchored','original_executed':False,
  'scope':'Reconstructed C only; libm prescribed synthetic results, not libm reconstruction or original oracle',
  'runs':[],'teeth':[],'compile_guards':[],'declared_tests':TESTS,'status':'INCOMPLETE'}
 try:
  report['static']=static(ns.so);report['source_binding']=dependency_binding()
  report['toolchain']={n:run([n,'--version']).stdout.splitlines()[0] for n in ('clang','qemu-arm')}
  configs=[('O2','-O2',())] if ns.smoke else [('O0','-O0',()),('O2','-O2',()),('O3','-O3',()),('ubsan','-O2',('-fsanitize=undefined,float-cast-overflow','-fsanitize-trap=all'))]
  for name,opt,extra in configs:
   r=build(ns.out,name,opt,extra=extra);report['runs'].append({'name':name,**r})
   if r.get('compile_rc') or r['exit_code'] or r['passes']!=TESTS or r['failures']:raise RuntimeError(f'{name}: acceptance failed {r}')
   counts=arithmetic_counts(ns.out/(name+'.arm'))
   original=Counter(i['mnemonic'] for i in report['static']['functions'][0]['instructions'] if i['mnemonic'] in NUMERIC)
   if counts!=dict(original):raise RuntimeError('numeric operation count/rounding primitive drift: '+repr((counts,dict(original))))
   report['runs'][-1]['numeric_operation_counts']=counts
   print('PASS',name,'declared_contracts='+str(len(TESTS)),flush=True)
  if not ns.smoke:
   expected_failure={
    'geometry_unsigned_dimensions':'geometry_signed_dimensions',
    'geometry_wrong_degree_constant':'geometry_math_callbacks',
    'geometry_double_multiply_before_narrow':'geometry_math_callbacks',
    'geometry_xy_cached_before_math':'geometry_math_callbacks',
    'geometry_angle_reread_for_sin':'geometry_math_callbacks',
    'geometry_cos_narrow_after_sin':'geometry_cos_narrowing',
    'geometry_math_calls_reversed':'geometry_identity',
    'geometry_late_region_width_read':'geometry_math_callbacks',
    'geometry_trim_ignored':'geometry_trim',
    'geometry_wrong_y_sign':'geometry_trim',
    'geometry_wrong_output_corner':'geometry_identity',
    'reader_width_default_zero':'region_reader_defaults',
    'reader_height_default_zero':'region_reader_defaults',
    'reader_skip_color':'reader_color',
    'reader_skip_geometry':'region_reader_defaults',
    'reader_loader_cached_before_math':'reader_loader_after_math',
    'reader_null_path_guard_removed':'reader_scale_after_each_getter',
    'reader_wrong_path_line':'region_reader_defaults',
    'reader_parser_scale_cached_before_getters':'reader_scale_after_each_getter',
   }
   assert set(expected_failure)=={m[0] for m in mutations()}
   for name,subject,edits in mutations():
    text=subject.read_text()
    for old,new in edits:text=replace_once(text,old,new)
    candidate=ns.out/(name+'.c');candidate.write_text(text);r=build(ns.out,name,overrides={subject:candidate})
    caught=r.get('compile_rc')==0 and r.get('exit_code')==1 and any(x.startswith(expected_failure[name]+': ') for x in r.get('failures',[]))
    report['teeth'].append({'name':name,'caught_by_named_assertion':caught,**r})
    if not caught:raise RuntimeError(f'mutant not rejected by named runtime assertion: {name}: {r}')
    print('TEETH',name,r['failures'],flush=True)
   missing=build(ns.out,'missing-region-body',omit=(BODY,))
   if not missing['compile_rc'] or 'undefined symbol: spRegionAttachment_updateOffset' not in missing['diagnostic']:raise RuntimeError('missing internal region body not refused')
   report['compile_guards'].append({'name':'missing-region-body','refused':True,**missing})
   text=FIX.read_text().replace('#include "../../spine_read_mesh/fixture/check.c"','#include "'+str(C/'spine_read_mesh/fixture/check.c')+'"')
   for old,new in (('double cos(double angle)','double absent_fixture_cos(double angle)'),('double sin(double angle)','double absent_fixture_sin(double angle)')):text=replace_once(text,old,new)
   no_math=ns.out/'fixture_without_math.c';no_math.write_text(text)
   missing=build(ns.out,'missing-math-imports',overrides={FIX:no_math})
   if not missing['compile_rc'] or not all('undefined symbol: '+s in missing['diagnostic'] for s in ('cos','sin')):raise RuntimeError('missing double libm imports not refused')
   report['compile_guards'].append({'name':'missing-math-imports','refused':True,**missing})
   for name,extra in (('reject-software-float',('-mfpu=none','-mfloat-abi=soft')),('reject-hardfloat-pcs',('-mfloat-abi=hard',))):
    r=build(ns.out,name,extra=extra)
    if not r['compile_rc'] or 'region geometry requires actual ARM32 VFP softfp' not in r['diagnostic']:raise RuntimeError('ABI guard not refused: '+name)
    report['compile_guards'].append({'name':name,'refused':True,**r})
  if any(sha(p)!=v for p,v in report['source_binding'].items()):raise RuntimeError('bound source/header/checker drift')
  report['status']='SMOKE_PASS' if ns.smoke else 'PASS'
 except Exception as ex:
  report['error']=str(ex);raise
 finally:(ns.out/'receipt.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
 print('RESULT '+report['status']+'; ORIGINAL NOT EXECUTED; receipt='+str(ns.out/'receipt.json'),flush=True)
if __name__=='__main__':main()
