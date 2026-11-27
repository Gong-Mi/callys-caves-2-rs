#!/usr/bin/env python3
"""Verify new mesh C consumers; original ELF is READ ONLY, never executed.

Only target/rebuilt ARM32 binaries are passed to qemu-arm. Records exact linked
artifacts, compiler-discovered header closure, declared assertions and mutations.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import subprocess
from capstone import Cs, CS_ARCH_ARM, CS_MODE_ARM
from elftools.elf.elffile import ELFFile

C = Path(__file__).resolve().parents[2]
MOD = C / "spine_read_mesh"
FIX = MOD / "fixture/check.c"
MESH = C / "spine_mesh/src/spine_mesh.c"
COLOR = C / "spine_color/src/spine_color.c"
CALLER = MOD / "src/spine_read_mesh.c"
PIN = "3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a"
SOURCES = [C / p for p in (
    "spine_alloc/src/spine_alloc.c", "spine_atlas_attachment/src/spine_atlas_attachment.c",
    "spine_attachment/src/spine_attachment.c", "spine_skeleton_data/src/spine_skeleton_data.c",
    "spine_lifetime/src/spine_json_lifetime.c", "json_interface/src/json_interface.c",
    "csprite_resources/fixture/arm32_support.c", "spine_read_vertices/src/spine_read_vertices.c",
)] + [MESH, COLOR, CALLER, FIX]
INCLUDES = [C / p / "src" for p in (
    "spine_alloc", "spine_attachment", "spine_skeleton_data", "spine_atlas_attachment",
    "json_interface", "spine_read_vertices", "spine_mesh", "spine_color", "spine_read_mesh",
)]
FLAGS = ["--target=armv7a-none-eabi", "-march=armv7-a", "-marm", "-mfpu=vfpv3",
         "-mfloat-abi=softfp", "-std=c11", "-ffreestanding", "-fno-builtin", "-ffp-contract=off",
         "-fstack-protector-strong", "-mstack-protector-guard=global", "-ffunction-sections",
         "-fdata-sections", "-Wall", "-Wextra", "-Werror", "-nostdlib", "-static", "-fuse-ld=lld",
         "-Wl,--gc-sections", "-Wl,-e,_start"]
TESTS = [
    "color_strtoul_signed_and_s0", "uv_rotated_and_unrotated",
    "uv_callback_snapshot_and_live_reloads", "uv_overlap_preserves_instruction_read_write_order",
    "uv_zero_negative_and_odd_pair_footprint", "uv_vmla_vmls_nonfused_rounding",
    "uv_empty_snan_span_computation", "parent_mesh_shares_geometry_null_keeps_fields",
    "mesh_full_consumer_and_real_cleanup", "mesh_absent_optional_edges",
    "mesh_triangle_allocator_rereads_child", "mesh_uv_allocator_rereads_child_caches_count",
    "linked_queue_first_and_capacity_growth", "linked_geometry_ownership_real_destructors",
    "linked_queue_callback_rereads_count_and_source", "linked_parent_json_presence_even_null_string",
]

def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()

def run(argv, timeout=40):
    return subprocess.run([str(x) for x in argv], text=True, capture_output=True, timeout=timeout)

def static(so):
    if sha(so) != PIN:
        raise ValueError("original SHA mismatch")
    with so.open("rb") as f:
        elf = ELFFile(f)
        segments = [(s["p_vaddr"], s.data()) for s in elf.iter_segments() if s["p_type"] == "PT_LOAD"]
        syms = {s.name: (s["st_value"], s["st_size"]) for s in elf.get_section_by_name(".dynsym").iter_symbols()}
        ex = elf.get_section_by_name(".ARM.exidx")
        exdata, exaddr = ex.data(), ex["sh_addr"]
    def read(a, n):
        for va, data in segments:
            if va <= a and a+n <= va+len(data):
                return data[a-va:a-va+n]
        raise ValueError(f"unmapped original range {a:#x}+{n}")
    exrows = []
    for off in range(0, len(exdata), 8):
        w, unwind = struct.unpack_from("<II", exdata, off)
        x = w & 0x7fffffff
        if x & (1 << 30): x -= 1 << 31
        exrows.append(((exaddr+off+x)&0xffffffff, unwind))
    md = Cs(CS_ARCH_ARM, CS_MODE_ARM)
    functions = []
    for name, start, code_end, end in (
        ("spMeshAttachment_updateUVs",0x287538,0x28764c,0x287650),
        ("spMeshAttachment_setParentMesh",0x287654,0x2876d4,0x2876d4),
        ("toColor",0x28b680,0x28b6fc,0x28b700),
    ):
        if name != "toColor" and syms.get(name) != (start,end-start):
            raise ValueError("symbol boundary changed: "+name)
        if not any(a == start for a,_ in exrows) or not any(a == end for a,_ in exrows):
            raise ValueError("exidx boundary missing: "+name)
        code = read(start,code_end-start)
        instructions = [{"va":hex(i.address),"mnemonic":i.mnemonic,"operands":i.op_str} for i in md.disasm(code,start)]
        if len(instructions)*4 != len(code):
            raise ValueError("incomplete ARM decode: "+name)
        functions.append({"name":name,"entry":hex(start),"code_end_exclusive":hex(code_end),
                          "range_end_exclusive":hex(end),"original_body_sha256":hashlib.sha256(read(start,end-start)).hexdigest(),
                          "instructions":instructions,"literal_bytes":end-code_end})
    literals = []
    for pool,add,want in (
        (0x28c964,0x28cb30,"jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c"),
        (0x28c968,0x28cb54,"color"),(0x28c96c,0x28cbac,"width"),
        (0x28c970,0x28cbc0,"height"),(0x28c974,0x28cbe0,"parent"),
        (0x28c978,0x28cc0c,"deform"),(0x28c97c,0x28cc1c,"skin"),
        (0x28c9b4,0x28d00c,"triangles"),(0x28c9bc,0x28d064,"uvs"),
        (0x28c9c4,0x28d0d8,"hull"),(0x28c9c8,0x28d0e4,"edges"),
    ):
        delta = struct.unpack("<I",read(pool,4))[0]
        addr=(add+8+delta)&0xffffffff
        value=read(addr,90).split(b"\0",1)[0].decode("ascii")
        if value != want:
            raise ValueError(f"PC-relative key mismatch {add:#x}: {value!r} != {want!r}")
        literals.append({"add":hex(add),"pool":hex(pool),"va":hex(addr),"value":value})
    return {"original_sha256":PIN,"functions":functions,"caller_keys":literals,
            "note":"Static identity/anchors only, not an equivalence verdict"}

def replace_once(text, old, new):
    if text.count(old) != 1:
        raise ValueError("nonunique mutation site: "+old)
    return text.replace(old,new,1)

def build(out,name,opt="-O2",overrides=None,extra=(),omit=()):
    used=[(overrides or {}).get(p,p) for p in SOURCES if p not in omit]
    binary=out/(name+".arm")
    argv=["clang",*FLAGS,opt,*extra,*["-I"+str(p) for p in INCLUDES],*used,"-o",binary]
    p=run(argv)
    (out/(name+".build.log")).write_text(p.stdout+p.stderr)
    if p.returncode:
        return {"compile_rc":p.returncode,"diagnostic":p.stderr,"compile_command":[str(x) for x in argv]}
    before=sha(binary)
    print("BINDING v1 entry=mesh-consumer run="+name+" original_sha256="+PIN+
          " fixture_sha256="+sha(FIX)+" binary_sha256="+before,flush=True)
    p=run(["qemu-arm",binary],10)
    (out/(name+".log")).write_text(p.stdout+p.stderr)
    if sha(binary) != before:
        raise RuntimeError("binary drift during execution")
    return {"compile_rc":0,"binary_sha256":before,"compile_command":[str(x) for x in argv],
            "exit_code":p.returncode,"stdout":p.stdout,"stderr":p.stderr,
            "passes":re.findall(r"^PASS (.+)$",p.stdout,re.M),
            "failures":re.findall(r"^FAIL (.+)$",p.stdout,re.M)}

def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--so",type=Path,required=True)
    ap.add_argument("--out",type=Path,required=True)
    ns=ap.parse_args();ns.out.mkdir(parents=True,exist_ok=False)
    compiler_tmp=ns.out/"compiler-tmp";compiler_tmp.mkdir();os.environ["TMPDIR"]=str(compiler_tmp)
    report={"schema":"cally-mesh-static-check/1","tier":"test_anchored","original_executed":False,
            "scope":"Reconstructed ARM32 C + synthetic import/allocator providers; caller blocks not whole loader",
            "static":static(ns.so),"runs":[],"teeth":[],"compile_guards":[],"declared_tests":TESTS}
    compile_flags=[f for f in FLAGS if not f.startswith(("-Wl,","-fuse-ld=")) and f not in ("-nostdlib","-static")]
    deps=set(SOURCES)
    for src in SOURCES:
        p=run(["clang",*compile_flags,*["-I"+str(i) for i in INCLUDES],"-MM",src])
        if p.returncode: raise RuntimeError(p.stderr)
        deps.update(Path(x).resolve() for x in p.stdout.replace("\\\n","").split(":",1)[1].split())
    deps.add(Path(__file__).resolve())
    binding={str(p):sha(p) for p in sorted(deps)}
    report["source_binding"]=binding
    report["toolchain"]={n:run([n,"--version"]).stdout.splitlines()[0] for n in ("clang","qemu-arm")}
    for name,opt,extra in (("O0","-O0",()),("O2","-O2",()),("O3","-O3",()),
                           ("ubsan","-O2",("-fsanitize=undefined,float-cast-overflow","-fsanitize-trap=all"))):
        r=build(ns.out,name,opt,extra=extra);report["runs"].append({"name":name,**r})
        if r.get("compile_rc") or r["exit_code"] or r["passes"] != TESTS or r["failures"]:
            raise RuntimeError(f"{name}: acceptance failed {r}")
        print("PASS",name,"declared_contracts="+str(len(TESTS)),flush=True)
    # Copy only mutated source. Include paths continue to bind canonical headers.
    mutants=[
        ("signed_color",COLOR,[("vcvt.f32.s32", "vcvt.f32.u32")]),
        ("stock_color_length",COLOR,[("if (strlen(value) != 8u)","if ((uint32_t)index >= strlen(value)/2u)")]),
        ("width_default_zero",CALLER,[("Json_getFloat(map,\"width\",32.0f)","Json_getFloat(map,\"width\",0.0f)")]),
        ("hull_doubled",CALLER,[("a->opaque_78 = (uint32_t)Json_getInt(map,\"hull\",0);","a->opaque_78 = (uint32_t)Json_getInt(map,\"hull\",0) << 1;")]),
        ("parent_string_truth",CALLER,[("if (parent) {", "if (parent && parent->string_value) {")]),
        ("queue_free_count_cached",CALLER,[("count = j->unk_10; /* 0x28cff4 */", "count = copy_count; /* 0x28cff4 */")]),
        ("queue_malloc_count_cached",CALLER,[("uint32_t copy_count = j->unk_10;", "uint32_t copy_count = count;")]),
        ("queue_capacity_wrong",CALLER,[("j->unk_14 = 8; bytes = 128;", "j->unk_14 = 7; bytes = 128;")]),
        ("uv_count_not_cached",CALLER,[("_readVertices(j,map,&a->super,uv_count);", "_readVertices(j,map,&a->super,array->unk_0c);")]),
        ("triangle_child_cached",CALLER,[("uint16_t *triangles = _malloc(count << 1,tag,935u);", "Json *cached_child = array->child; uint16_t *triangles = _malloc(count << 1,tag,935u);"),
                                          ("Json *child = array->child;", "Json *child = cached_child;")]),
        ("uv_rotate_reversed",MESH,[("if (rotate == 0)", "if (rotate != 0)")]),
        ("uv_count_after_free",MESH,[("_free (old_uvs);", "_free (old_uvs); word_count = self->super.worldVerticesLength; count = sp_s32(word_count);")]),
        ("uv_pair_cached",MESH,[("float x = sp_vldr (sp_src_at (src, i << 3));", "float x = sp_vldr (sp_src_at (src, i << 3)); float cached_y = sp_vldr(sp_src_at(src, (i << 3) + 4u));"),
                               ("float y = sp_vldr (sp_src_at (src, (i << 3) + 4u));", "float y = cached_y;")]),
        ("parent_null_keeps_old_pointer",MESH,[("self->parentMesh = parentMesh;", "if (parentMesh) self->parentMesh = parentMesh;")]),
        ("parent_wrong_count",MESH,[("self->super.worldVerticesLength = p_20;", "self->super.worldVerticesLength = p_20 + 1u;")]),
        ("mesh_owned_uv_leak",C/"spine_atlas_attachment/src/spine_atlas_attachment.c",
         [("_free (mesh->owned_58);", "(void)mesh->owned_58;")]),
    ]
    for name,subject,edits in mutants:
        text=subject.read_text()
        for old,new in edits: text=replace_once(text,old,new)
        candidate=ns.out/(name+".c");candidate.write_text(text)
        r=build(ns.out,name,overrides={subject:candidate})
        caught=(r.get("compile_rc")==0 and r.get("exit_code")==1 and bool(r.get("failures")))
        report["teeth"].append({"name":name,"caught_by_named_assertion":caught,**r})
        if not caught: raise RuntimeError(f"mutant not killed by named runtime assertion: {name}: {r}")
        print("TEETH",name,r["failures"],flush=True)
    missing=build(ns.out,"missing-mesh-provider",omit=(MESH,))
    if not missing["compile_rc"] or "undefined symbol: spMeshAttachment_updateUVs" not in missing["diagnostic"]:
        raise RuntimeError("missing internal mesh body did not fail link")
    report["compile_guards"].append({"name":"missing-mesh-provider","refused":True,**missing})
    if binding != {str(p):sha(p) for p in sorted(deps)}:
        raise RuntimeError("bound source/header/checker changed during acceptance")
    report["status"]="PASS"
    receipt=ns.out/"receipt.json";receipt.write_text(json.dumps(report,ensure_ascii=False,indent=2)+"\n")
    print("RESULT PASS; ORIGINAL NOT EXECUTED; receipt="+str(receipt),flush=True)

if __name__=="__main__":
    main()
