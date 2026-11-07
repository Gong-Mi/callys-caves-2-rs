#!/usr/bin/env python3
"""Build/exercise reconstructed ARM32 consumers. Never executes the original.

Input identity/static checks use the pinned original as read-only bytes. Output
receipts bind the complete source/header closure and each newly linked binary.
Mutations alter a temporary source copy; the working tree stays unchanged.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import struct
import subprocess
import tempfile

PIN = "3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a"
C = Path(__file__).resolve().parents[2]
MOD = C / "spine_read_vertices"
SOURCE = MOD / "src/spine_read_vertices.c"
WRAPPER = C / "spine_read_bbox_path/src/spine_read_bbox_path.c"
FIXTURE = MOD / "fixture/check.c"
SOURCES = [C / p for p in (
    "spine_alloc/src/spine_alloc.c",
    "spine_atlas_attachment/src/spine_atlas_attachment.c",
    "json_interface/src/json_interface.c",
    "csprite_resources/fixture/arm32_support.c",
)]
INCLUDES = [C / p / "src" for p in (
    "spine_alloc", "spine_attachment", "spine_skeleton_data",
    "spine_atlas_attachment", "json_interface", "spine_read_vertices",
    "spine_read_bbox_path",
)]
FLAGS = ["--target=armv7a-none-eabi", "-march=armv7-a", "-marm",
         "-mfpu=vfpv3", "-mfloat-abi=softfp", "-std=c11", "-ffreestanding",
         "-fno-builtin", "-ffp-contract=off", "-fstack-protector-strong",
         "-mstack-protector-guard=global", "-ffunction-sections", "-fdata-sections",
         "-Wall", "-Wextra", "-Werror", "-nostdlib", "-static", "-fuse-ld=lld",
         "-Wl,--gc-sections", "-Wl,-e,_start"]

def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()

def command(args, timeout=40):
    return subprocess.run([str(a) for a in args], text=True, capture_output=True,
                          timeout=timeout, check=False)

def elf_read(data, va, n):
    if data[:6] != b"\x7fELF\x01\x01":
        raise ValueError("expected little-endian ELF32")
    phoff = struct.unpack_from("<I", data, 28)[0]
    phsize, phnum = struct.unpack_from("<HH", data, 42)
    for i in range(phnum):
        kind, offset, start, _, size = struct.unpack_from("<IIIII", data, phoff+i*phsize)
        if kind == 1 and start <= va and va+n <= start+size:
            return data[offset+va-start:offset+va-start+n]
    raise ValueError(f"unmapped original VA {va:#x}+{n}")

def static_check(so):
    raw = so.read_bytes()
    if hashlib.sha256(raw).hexdigest() != PIN:
        raise ValueError("original SHA mismatch")
    strings = []
    for pool, add in ((0x28b670,0x28b418),(0x28b674,0x28b42c),
                      (0x28b678,0x28b4d0),(0x28b67c,0x28b644)):
        delta = struct.unpack("<I", elf_read(raw,pool,4))[0]
        addr = (add+8+delta)&0xffffffff
        value = elf_read(raw,addr,90).split(b"\0",1)[0].decode("ascii")
        strings.append({"pool":hex(pool),"va":hex(addr),"value":value})
    if [s["value"] for s in strings] != ["vertices"] + [
            "jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c"]*3:
        raise ValueError("literal/PC mapping mismatch")
    body = elf_read(raw,0x28b3fc,0x28b670-0x28b3fc)
    return {"original_sha256":PIN,"entry":"0x28b3fc","code_end_exclusive":"0x28b670",
            "range_end_exclusive":"0x28b680","arm_code_words":len(body)//4,
            "literal_words":4,"code_sha256":hashlib.sha256(body).hexdigest(),
            "literals":strings}

def build_run(out, name, opt, source=SOURCE, wrapper=WRAPPER, extra=()):
    binary = out / (name+".arm")
    args = ["clang",*FLAGS,opt,*extra]
    args += ["-I"+str(p) for p in INCLUDES]
    args += [*SOURCES,source,wrapper,FIXTURE,"-o",binary]
    built = command(args)
    (out/(name+".build.log")).write_text(built.stdout+built.stderr)
    if built.returncode:
        raise RuntimeError(f"{name}: compile failed\n{built.stderr}")
    binary_sha = sha(binary)
    print("BINDING v1 entry=_readVertices run="+name+" original_sha256="+PIN+
          " c_sha256="+sha(source)+" wrapper_sha256="+sha(wrapper)+
          " fixture_sha256="+sha(FIXTURE)+" binary_sha256="+binary_sha, flush=True)
    executed = command(["qemu-arm",binary], timeout=10)
    (out/(name+".log")).write_text(executed.stdout+executed.stderr)
    if sha(binary) != binary_sha:
        raise RuntimeError("binary changed during execution")
    return {"name":name,"binary_sha256":binary_sha,"compile_command":[str(a) for a in args],
            "exit_code":executed.returncode,
            "stdout":executed.stdout,"stderr":executed.stderr}

def replace_once(text, old, new):
    if text.count(old) != 1:
        raise ValueError("mutation must select exactly one site: "+old)
    return text.replace(old,new,1)

def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--so",type=Path,required=True)
    ap.add_argument("--out",type=Path)
    ns=ap.parse_args()
    out=ns.out or Path(tempfile.mkdtemp(prefix="cally-read-vertices-",dir=os.environ["TMPDIR"]))
    if ns.out:
        out.mkdir(parents=True,exist_ok=False)
    compiler_tmp = out / "compiler-tmp"
    compiler_tmp.mkdir()
    os.environ["TMPDIR"] = str(compiler_tmp)
    static=static_check(ns.so)
    # Compiler reports the files it actually included; do not hand-maintain a
    # partial helper-only projection while claiming a complete binary binding.
    deps=set(SOURCES+[SOURCE,WRAPPER,FIXTURE])
    dep_flags = [f for f in FLAGS if not f.startswith(("-Wl,", "-fuse-ld="))
                 and f not in ("-nostdlib", "-static")]
    for src in list(deps):
        result=command(["clang",*dep_flags,"-O2",*["-I"+str(p) for p in INCLUDES],"-MM",src])
        if result.returncode:
            raise RuntimeError(result.stderr)
        joined=result.stdout.replace("\\\n","").split(":",1)[1]
        deps.update(Path(p).resolve() for p in joined.split())
    deps.add(Path(__file__).resolve())
    before={str(p):sha(p) for p in sorted(deps)}
    report={"schema":"cally-read-vertices-check/1","tier":"test_anchored",
            "scope":"reconstructed ARM32 consumer + synthetic providers; original bytes only",
            "static":static,"flags":FLAGS,"source_binding":before,
            "toolchain":{"clang":command(["clang","--version"]).stdout.splitlines()[0],
                         "qemu":command(["qemu-arm","--version"]).stdout.splitlines()[0]},
            "runs":[],"teeth":[],"compile_guards":[]}
    # Refusals are ABI/layout checks, not runtime semantic mutant kills.
    for mode,needle in (("hard","core-register ARM32 ABI"),
                        ("soft","requires real ARM32 VFP softfp")):
        mode_flags=[f for f in dep_flags if not f.startswith("-mfloat-abi=")]
        guard=command(["clang",*mode_flags,"-mfloat-abi="+mode,
                       *["-I"+str(p) for p in INCLUDES],"-fsyntax-only",SOURCE])
        (out/("refuse-"+mode+".log")).write_text(guard.stdout+guard.stderr)
        if not guard.returncode or needle not in guard.stderr:
            raise RuntimeError("ABI refusal missing: "+mode)
        report["compile_guards"].append({"name":mode,"refused":True,"diagnostic":needle})
    overlay=out/"layout-overlay";overlay.mkdir()
    header=C/"json_interface/src/json_interface.h"
    layout=replace_once(header.read_text(),"uint32_t     unk_0c;",
                        "uint32_t injected_wrong_slot; uint32_t     unk_0c;")
    (overlay/"json_interface.h").write_text(layout)
    guard=command(["clang",*dep_flags,"-I"+str(overlay),
                   *["-I"+str(p) for p in INCLUDES],"-fsyntax-only",SOURCE])
    (out/"refuse-json-layout.log").write_text(guard.stdout+guard.stderr)
    if not guard.returncode or "Json array count" not in guard.stderr:
        raise RuntimeError("Json shifted-field layout was not refused")
    report["compile_guards"].append({"name":"shifted-json-layout","refused":True,
                                     "diagnostic":"Json array count"})
    for name,opt,extra in (("O0","-O0",()),("O2","-O2",()),("O3","-O3",()),
                           ("ubsan","-O2",("-fsanitize=undefined,float-cast-overflow","-fsanitize-trap=all"))):
        run=build_run(out,name,opt,extra=extra)
        report["runs"].append(run)
        if run["exit_code"] or "SUMMARY all declared reconstructed contracts passed" not in run["stdout"]:
            raise RuntimeError(f"{name}: run failed\n{run['stdout']}\n{run['stderr']}")
        print(f"PASS {name}: {run['stdout'].count('PASS ')} named contracts")
    source=SOURCE.read_text(); wrapper=WRAPPER.read_text()
    mutants=[
        ("weighted_gate",False,[("if (verticesCount == size)","if (verticesCount != size)")]),
        ("scale_weight",False,[("__builtin_memcpy(out + 2, at(row, 4), 4);", "out[2] = mul_f32(load_f32(at(row, 4)), load_f32(json));")]),
        ("cache_bone_count",False,[("uint32_t reloadedBoneWords = a->opaque_10;", "uint32_t reloadedBoneWords = boneWords;")]),
        ("cache_child",False,[("float *values = _malloc(size << 2, tag, 513u);", "Json *earlyChild = array->child; float *values = _malloc(size << 2, tag, 513u);"),("Json *child = array->child;","Json *child = earlyChild;")]),
        ("skip_zero_group",False,[("i = cursor;","i = cursor + 4u;")]),
        ("unit_scale_multiply",False,[("if (!scale_equal_one(scale) && s32(verticesCount) > 0)","if (!scale_equal_one(scale) || s32(verticesCount) > 0)")]),
        ("skip_empty_compare",False,[("if (!scale_equal_one(scale) && s32(verticesCount) > 0)","if (s32(verticesCount) > 0 && !scale_equal_one(scale))")]),
        ("bbox_wrong_field",True,[("a->super.opaque_18 = vlen;","a->super.worldVerticesLength = vlen;")]),
        ("length_store_late",True,[("a->opaque_24 = lengthCount;\n    a->owned_28 = _malloc(lengthCount << 2, tag, 985u);", "a->owned_28 = _malloc(lengthCount << 2, tag, 985u);\n    a->opaque_24 = lengthCount;")]),
    ]
    for name,is_wrapper,edits in mutants:
        text=wrapper if is_wrapper else source
        for old,new in edits:
            text=replace_once(text,old,new)
        mutated=out/(name+".c");mutated.write_text(text)
        run=build_run(out,name,"-O2",wrapper=mutated) if is_wrapper else build_run(out,name,"-O2",source=mutated)
        caught=bool(run["exit_code"]) and "FAIL " in run["stdout"]
        report["teeth"].append({**run,"caught_by_named_assertion":caught})
        if not caught:
            raise RuntimeError(f"mutant {name} survived/failed without a named assertion: {run}")
        print("TEETH",name,run["stdout"].strip().splitlines()[-1])
    if before != {str(p):sha(p) for p in sorted(deps)}:
        raise RuntimeError("bound source changed during acceptance")
    report["status"]="PASS"
    (out/"receipt.json").write_text(json.dumps(report,ensure_ascii=False,indent=2)+"\n")
    print("BINDING original="+PIN+" complete_binary="+report["runs"][1]["binary_sha256"])
    print("RESULT PASS; ORIGINAL NOT EXECUTED; receipt="+str(out/"receipt.json"))

if __name__=="__main__":
    main()
