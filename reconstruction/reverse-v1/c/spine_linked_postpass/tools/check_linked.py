#!/usr/bin/env python3
"""Linked postpass acceptance: only our reconstructed ARM32 C is executed."""
import argparse
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import re
import struct
import subprocess
from capstone import Cs, CS_ARCH_ARM, CS_MODE_ARM
from elftools.elf.elffile import ELFFile
C=Path(__file__).resolve().parents[2]
MOD=C/"spine_linked_postpass"
FIX=MOD/"fixture/check.c"
ADAPTER=MOD/"fixture/reporter_adapter.c"
SKIN=C/"spine_skin/src/spine_skin.c"
FIND=C/"skeleton_find/src/skeleton_find.c"
POST=MOD/"src/spine_linked_postpass.c"
PIN="3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a"
spec=importlib.util.spec_from_file_location("previous_mesh_checker",C/"spine_read_mesh/tools/check_mesh.py")
mesh=importlib.util.module_from_spec(spec);spec.loader.exec_module(mesh)
FLAGS=mesh.FLAGS
INCLUDES=mesh.INCLUDES+[C/p/"src" for p in ("spine_skin","skeleton_find","spine_linked_postpass","spine_json_error","spine_json_support")]
TESTS=["skin_constructors_duplicates_newest_first","skin_get_comparator_mutates_attachment_and_next",
       "skin_entry_publication_and_latest_head","data_find_uses_full_record_and_name_offsets",
       "find_skin_count_and_table_snapshot","postpass_zero_and_negative_count_no_effects",
       "postpass_default_skin_lookup_and_real_cleanup","postpass_named_skin_lookup",
       "missing_skin_disposes_then_rereads_error_extra","missing_parent_disposes_then_rereads_error_extra",
       "postpass_mesh_pointer_reread_after_uv_allocator","postpass_parent_and_slot_read_after_skin_lookup",
       "postpass_callback_grows_count_and_replaces_queue","postpass_callback_shrinks_count",
       "error_unconditional_strlen_and_end_pointer_strncat"]

def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def command(a,timeout=50):return subprocess.run([str(x) for x in a],capture_output=True,text=True,timeout=timeout)
def sources():
    support=sorted((C/"spine_json_support/src").glob("*.c"))
    if not support:raise ValueError("restored Json_dispose/ReportSpineError bodies are required")
    return [p for p in mesh.SOURCES if p!=mesh.FIX]+[SKIN,FIND,POST,C/"spine_json_error/src/spine_json_error.c",*support,FIX,ADAPTER]
def static(so):
    if sha(so)!=PIN:raise ValueError("original SHA mismatch")
    with so.open("rb") as f:
        e=ELFFile(f);segments=[(s["p_vaddr"],s.data()) for s in e.iter_segments() if s["p_type"]=="PT_LOAD"]
        syms={s.name:(s["st_value"],s["st_size"]) for s in e.get_section_by_name(".dynsym").iter_symbols()}
    def read(a,n):
        for va,data in segments:
            if va<=a and a+n<=va+len(data):return data[a-va:a-va+n]
        raise ValueError(f"unmapped VA {a:#x}+{n}")
    md=Cs(CS_ARCH_ARM,CS_MODE_ARM);out=[]
    for name,a,end,pool in (("_Entry_create",0x28ebb8,0x28ec20,4),("spSkin_create",0x28ec44,0x28ec9c,4),
                           ("spSkin_addAttachment",0x28ecd8,0x28ed00,0),("spSkin_getAttachment",0x28ed00,0x28ed58,0),
                           ("spSkeletonData_findBone",0x28afbc,0x28b018,0),("spSkeletonData_findSlotIndex",0x28b0cc,0x28b124,0),
                           ("spSkeletonData_findSkin",0x28b124,0x28b180,0)):
        if syms.get(name)!=(a,end-a):raise ValueError("symbol boundary "+name)
        data=read(a,end-a);ins=[{"va":hex(i.address),"mnemonic":i.mnemonic,"operands":i.op_str} for i in md.disasm(data[:len(data)-pool],a)]
        if len(ins)*4!=len(data)-pool:raise ValueError("decode lost body "+name)
        out.append({"name":name,"address":hex(a),"isa":"ARM","range_end_exclusive":hex(end),"code_end_exclusive":hex(end-pool),
                    "body_sha256":hashlib.sha256(data).hexdigest(),"literal_bytes":pool,"instructions":ins})
    literals=[]
    for pool,pc,want in ((0x28ec1c,0x28ebd0,"jni/../jni/yoyo/../../../spine-c/src/spine/Skin.c"),
                          (0x28ec98,0x28ec5c,"jni/../jni/yoyo/../../../spine-c/src/spine/Skin.c"),
                          (0x28c980,0x28cd5c,"Skin not found: "),(0x28eb08,0x28e89c,"Parent mesh not found: ")):
        a=(pc+8+struct.unpack("<I",read(pool,4))[0])&0xffffffff
        s=read(a,90).split(b"\0",1)[0].decode("ascii")
        if s!=want:raise ValueError("literal mapping "+hex(pc)+":"+repr(s))
        literals.append({"pool":hex(pool),"add":hex(pc),"va":hex(a),"value":s})
    return {"original_sha256":PIN,"functions":out,"literals":literals,
            "caller_blocks":[{"range":[hex(a),hex(b)],"sha256":hashlib.sha256(read(a,b-a)).hexdigest()} for a,b in ((0x28ccb8,0x28cd6c),(0x28e880,0x28e8ac))]}
def replace_once(s,a,b):
    if s.count(a)!=1:raise ValueError("mutation selector must be unique: "+a)
    return s.replace(a,b,1)
def build(out,name,opt="-O2",extra=(),overrides=None,omit=()):
    binary=out/(name+".arm");src=[(overrides or {}).get(p,p) for p in sources() if p not in omit]
    argv=["clang",*FLAGS,opt,*extra,*["-I"+str(x) for x in INCLUDES],*src,"-o",binary]
    p=command(argv);(out/(name+".build.log")).write_text(p.stdout+p.stderr)
    if p.returncode:return {"compile_rc":p.returncode,"stderr":p.stderr,"argv":[str(x) for x in argv]}
    binary_sha=sha(binary)
    print("BINDING v1 entry=linked-postpass run="+name+" original_sha256="+PIN+" fixture_sha256="+sha(FIX)+" binary_sha256="+binary_sha,flush=True)
    p=command(["qemu-arm",binary],12);(out/(name+".log")).write_text(p.stdout+p.stderr)
    if sha(binary)!=binary_sha:raise RuntimeError("binary changed")
    return {"compile_rc":0,"binary_sha256":binary_sha,"argv":[str(x) for x in argv],"exit_code":p.returncode,
            "stdout":p.stdout,"stderr":p.stderr,"passes":re.findall(r"^PASS (.+)$",p.stdout,re.M),"failures":re.findall(r"^FAIL (.+)$",p.stdout,re.M)}
def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument("--so",type=Path,required=True);ap.add_argument("--out",type=Path,required=True);ns=ap.parse_args()
    ns.out.mkdir(parents=True,exist_ok=False);tmp=ns.out/"compiler-tmp";tmp.mkdir();os.environ["TMPDIR"]=str(tmp)
    report={"schema":"cally-linked-postpass-check/1","scope":"reconstructed ARM32 C plus synthetic libc/allocator/reporter providers; original not executed",
            "original_executed":False,"tier":"test_anchored","static":static(ns.so),"declared_tests":TESTS,"runs":[],"teeth":[],"compile_guards":[]}
    compile_flags=[x for x in FLAGS if not x.startswith(("-Wl,","-fuse-ld=")) and x not in ("-nostdlib","-static")]
    deps=set(sources()+[Path(__file__).resolve(),C/"spine_read_mesh/tools/check_mesh.py"])
    for src in sources():
        p=command(["clang",*compile_flags,*["-I"+str(x) for x in INCLUDES],"-MM",src])
        if p.returncode:raise RuntimeError(p.stderr)
        deps.update(Path(x).resolve() for x in p.stdout.replace("\\\n","").split(":",1)[1].split())
    binding={str(p):sha(p) for p in sorted(deps)};report["source_binding"]=binding
    report["toolchain"]={n:command([n,"--version"]).stdout.splitlines()[0] for n in ("clang","qemu-arm")}
    for name,opt,extra in (("O0","-O0",()),("O2","-O2",()),("O3","-O3",()),("ubsan","-O2",("-fsanitize=undefined,float-cast-overflow","-fsanitize-trap=all"))):
        r=build(ns.out,name,opt,extra);report["runs"].append({"name":name,**r})
        if r.get("compile_rc") or r["exit_code"] or r["passes"]!=TESTS or r["failures"]:raise RuntimeError(f"{name}: {r}")
        print("PASS",name,"declared_contracts="+str(len(TESTS)),flush=True)
    error_src=C/"spine_json_error/src/spine_json_error.c"
    for name,opt in (("guard-O0","-O0"),("guard-O2","-O2"),("guard-O3","-O3")):
        r=build(ns.out,name,opt,extra=("-DTEST_CANARY=1",))
        if r.get("compile_rc") or r.get("exit_code")!=1 or r.get("failures")!=["set_error_canary_after_dispose: stack guard"]:
            raise RuntimeError(f"canary did not fail after disposer in {name}: {r}")
        report["compile_guards"].append({"name":name,"kind":"actual generated guard runtime rejection",**r})
        print("GUARD",name,r["failures"],flush=True)
    unprotected=ns.out/"canary-disabled.c"
    unprotected.write_text(replace_once(error_src.read_text(),"void\n_spSkeletonJson_setError", "__attribute__((no_stack_protector))\nvoid\n_spSkeletonJson_setError"))
    r=build(ns.out,"guard-disabled",extra=("-DTEST_CANARY=1",),overrides={error_src:unprotected})
    if r.get("compile_rc") or r.get("exit_code")!=1 or r.get("failures")!=["set_error_canary_after_dispose: canary was not checked after Json_dispose"]:
        raise RuntimeError(f"canary negative control not discriminatory: {r}")
    report["compile_guards"].append({"name":"guard-disabled","kind":"guard rejection absent, distinguished by named assertion",**r})
    mutants=[
        ("error_strlen_conditional",error_src,[("uint32_t message_length = (uint32_t)strlen(message);", "uint32_t message_length = extra ? (uint32_t)strlen(message) : 0u;")]),
        ("error_wrong_append_base",error_src,[("strncat(append_at, extra,", "strncat(append_at - message_length, extra,")]),
        ("get_wrong_slot",SKIN,[("e->slotIndex==slotIndex &&", "(e->slotIndex==slotIndex || e->slotIndex==17u) &&")]),
        ("get_attachment_cached",SKIN,[("while(e) {", "while(e) { spAttachment *cached=e->attachment;"),("return e->attachment;", "return cached;")]),
        ("get_next_cached",SKIN,[("while(e) {", "while(e) { spSkinEntry *cached=e->next;"),("e=e->next;", "e=cached;")]),
        ("add_head_cached",SKIN,[("spSkinEntry *e=_Entry_create(slotIndex,name,a);", "spSkinEntry *cached=s->entries; spSkinEntry *e=_Entry_create(slotIndex,name,a);"),("e->next=s->entries;", "e->next=cached;")]),
        ("bone_wrong_name_offset",FIND,[("rd(bone,4)", "rd(bone,0)")]),
        ("slot_wrong_name_offset",FIND,[("rd(slot,4)", "rd(slot,0)")]),
        ("post_default_is_first_skin",POST,[("(spSkin *)(uintptr_t)data->words[10]", "((spSkin **)(uintptr_t)data->words[9])[0]")]),
        ("post_count_cached",POST,[("uint32_t i=0;", "uint32_t i=0,limit=j->unk_10;"),("while(signed32(j->unk_10)>signed32(i))", "while(signed32(limit)>signed32(i))")]),
        ("post_queue_cached",POST,[("uint32_t i=0;", "uint32_t i=0,cached=j->unk_18;"),("uint32_t base=j->unk_18,offset=i<<4;", "uint32_t base=cached,offset=i<<4;")]),
        ("post_skin_extra_cached",POST,[("spSkeletonData_dispose(data); /*0x28cd48", "const char *extra=entry->skin; spSkeletonData_dispose(data); /*0x28cd48"),("\"Skin not found: \",entry->skin", "\"Skin not found: \",extra")]),
        ("post_parent_extra_cached",POST,[("spSkeletonData_dispose(data); /*0x28e888", "const char *extra=entry->parent; spSkeletonData_dispose(data); /*0x28e888"),("\"Parent mesh not found: \",entry->parent", "\"Parent mesh not found: \",extra")]),
        ("post_skin_dispose_missing",POST,[("spSkeletonData_dispose(data); /*0x28cd48", "(void)data; /*0x28cd48")]),
        ("post_uv_missing",POST,[("spMeshAttachment_updateUVs(entry->mesh);", "(void)entry->mesh;")]),
        ("post_configure_mesh_cached",POST,[("spMeshAttachment_updateUVs(entry->mesh);", "spMeshAttachment *cached=entry->mesh; spMeshAttachment_updateUVs(entry->mesh);"),("spAttachment *attachment=(spAttachment *)entry->mesh;", "spAttachment *attachment=(spAttachment *)cached;")]),
        ("post_parent_before_find_cached",POST,[("const char *skin_name=entry->skin;", "const char *skin_name=entry->skin,*cached_name=entry->parent; uint32_t cached_slot=entry->slotIndex;"),("spSkin_getAttachment(skin,entry->slotIndex,entry->parent)", "spSkin_getAttachment(skin,cached_slot,cached_name)")]),
    ]
    for name,subject,edits in mutants:
        text=subject.read_text()
        for a,b in edits:text=replace_once(text,a,b)
        p=ns.out/(name+".c");p.write_text(text);r=build(ns.out,name,overrides={subject:p})
        caught=r.get("compile_rc")==0 and r.get("exit_code")==1 and bool(r.get("failures"))
        report["teeth"].append({"name":name,"caught_by_named_assertion":caught,**r})
        if not caught:raise RuntimeError(f"mutant did not fail a named runtime assertion: {name}: {r}")
        print("TEETH",name,r["failures"],flush=True)
    missing=build(ns.out,"missing-skin-body",omit=(SKIN,))
    if not missing["compile_rc"] or "undefined symbol: spSkin_getAttachment" not in missing["stderr"]:raise RuntimeError("missing skin provider was not refused")
    report["compile_guards"].append({"name":"missing-skin-body","refused":True,**missing})
    if binding!={str(p):sha(p) for p in sorted(deps)}:raise RuntimeError("source/header/checker changed during acceptance")
    report["status"]="PASS";(ns.out/"receipt.json").write_text(json.dumps(report,ensure_ascii=False,indent=2)+"\n")
    print("RESULT PASS; ORIGINAL NOT EXECUTED; receipt="+str(ns.out/"receipt.json"),flush=True)
if __name__=="__main__":main()
