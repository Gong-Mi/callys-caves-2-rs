#!/usr/bin/env python3
"""Static contract + rebuilt-ARM32 acceptance for spine_json_error/support.

The original libyoyo.so is opened read-only for byte/symbol/relocation facts.
It is never loaded, mapped for execution, or passed to qemu.  qemu only runs
binaries linked from the reconstructed C in this module.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys
import tempfile

from elftools.elf.elffile import ELFFile

PIN = "3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a"
C = Path(__file__).resolve().parents[2]
ERR = C / "spine_json_error"
SUP = C / "spine_json_support"
FIX = SUP / "fixture/check.c"
SOURCES = [C / "spine_alloc/src/spine_alloc.c",
           SUP / "src/spine_json_support.c",
           ERR / "src/spine_json_error.c",
           FIX]
INCLUDES = [C / "spine_alloc/src", SUP / "src", ERR / "src"]
BASE = ["--target=armv7a-none-eabi", "-march=armv7-a", "-marm",
        "-mfpu=vfpv3", "-mfloat-abi=softfp", "-ffp-contract=off",
        "-std=c11", "-ffreestanding", "-fno-builtin",
        "-fstack-protector-strong", "-mstack-protector-guard=global",
        "-Wall", "-Wextra", "-Werror", "-nostdlib", "-static",
        "-fuse-ld=lld", "-Wl,-e,_start"]
TESTS = [
    "report_exact_vcall_slot_0xc",
    "neg_report_vtable_slot_0x0_0x4_0x8_not_called",
    "neg_report_global_reloaded_each_call",
    "json_dispose_null_is_noop",
    "json_dispose_order_depth_first_next_cached",
    "json_dispose_skips_null_string_and_name",
    "neg_json_dispose_rereads_string_name_after_child",
    "neg_json_dispose_caches_next_before_child",
    "neg_json_dispose_rereads_name_after_string_free",
    "set_error_tag_line_message_and_order",
    "neg_set_error_skips_old_error_free",
    "neg_set_error_short_malloc_tag",
    "neg_set_error_wrong_alloc_line",
    "neg_set_error_reports_before_malloc",
    "neg_set_error_json_dispose_before_report",
    "set_error_extra_append_exact",
    "neg_set_error_extra_ignored",
    "neg_set_error_extra_bound_255",
    "set_error_extra_null",
    "file_wrapper_success_loader_then_free",
    "neg_file_wrapper_frees_before_loader",
    "neg_file_wrapper_size_zero_is_error",
    "neg_file_wrapper_size_zero_no_free",
    "neg_file_wrapper_null_data_is_error",
    "neg_file_wrapper_exact_prefix",
]
TAG = b"jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c"
PREFIX = b"Unable to read skeleton file: "
FMT = b"Spine Error:%s\n"


BINDINGS = {}
RUNS = []
HEADER_BINDING = {}

class Failed(Exception):
    pass


def need(cond, why):
    if not cond:
        raise Failed(why)


def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def check_original(path):
    need(sha(path) == PIN, "original SHA-256 mismatch")
    raw = Path(path).read_bytes()
    with open(path, "rb") as fh:
        elf = ELFFile(fh)
        segs = [s for s in elf.iter_segments() if s["p_type"] == "PT_LOAD"]
        syms = {s.name: (s["st_value"], s["st_size"])
                for s in elf.get_section_by_name(".dynsym").iter_symbols()}

        def rd(v, n):
            for s in segs:
                if s["p_vaddr"] <= v and v + n <= s["p_vaddr"] + s["p_filesz"]:
                    o = s["p_offset"] + (v - s["p_vaddr"])
                    return raw[o:o + n]
            raise Failed(f"unmapped original range {v:#x}+{n}")

        def w(v):
            return int.from_bytes(rd(v, 4), "little")

        need(rd(0x357b08, len(TAG)) == TAG, "0x357b08 tag literal")
        need(rd(0x357f70, len(PREFIX)) == PREFIX, "0x357f70 file prefix")
        need(rd(0x330afc, len(FMT)) == FMT, "0x330afc report format")
        need(w(0x28b848) == 0x000cc308, "setError tag pool word")
        need(w(0x28ebb4) == 0x000c93c4, "file prefix pool word")
        need(w(0xc4430) == 0x00329300, "report GOT pool word")
        need(w(0xc4434) == 0x0026c6dc, "report format pool word")
        for name, entry, size in (
                ("_spSkeletonJson_setError", 0x28b784, 200),
                ("spSkeletonJson_readSkeletonDataFile", 0x28eb40, 120),
                ("Json_dispose", 0x2872c8, 88),
                ("ReportSpineError", 0xc4404, 52),
                ("spSkeletonJson_readSkeletonData", 0x28b84c, 13044)):
            need(name in syms, f"missing dynsym {name}")
            need(syms[name] == (entry, size),
                 f"{name} expected ({entry:#x},{size}) got {syms[name]}")
        need(syms["dbg_csol"] == (0x3eb70c, 4), "dbg_csol storage")
        need(syms["_dbg_csol"] == (0x47a118, 4), "_dbg_csol storage")
        need(w(0x3ed71c) == 0x3eb70c, "GOT 0x3ed71c -> &dbg_csol")
        need(w(0x3eb70c) == 0x47a118, "dbg_csol value -> &_dbg_csol")
        need(w(0x3eb6a0 + 0x14) == 0xc4390,
             "_ZTV12DummyConsole address-point +0xc = DummyConsole::Output")
        need(w(0xbd83c) == 0xea072125, "_spUtil_readFile is b 0x285cd8")
        rel = {r["r_offset"]: r["r_info_type"]
               for r in elf.get_section_by_name(".rel.dyn").iter_relocations()}
        need(rel.get(0x3ed71c) == 23, "GOT slot R_ARM_RELATIVE")
        need(rel.get(0x3eb70c) == 23, "dbg_csol R_ARM_RELATIVE")
    return dict(rd=rd, syms=syms)


def check_functions(orig):
    for mod, fname, expected in ((ERR, "functions.json", 2),
                                 (SUP, "functions.json", 2)):
        doc = json.loads((mod / fname).read_text())
        need(doc["source_sha256"] == PIN, f"{mod.name} image pin")
        need(doc["tier"] == "bytecode_anchored", f"{mod.name} tier")
        need(len(doc["functions"]) == expected, f"{mod.name} function count")
        for fn in doc["functions"]:
            start, end = (int(x, 16) for x in fn["original_body_range"])
            body = orig["rd"](start, end - start)
            need(hashlib.sha256(body).hexdigest() == fn["original_body_sha256"],
                 f"{fn['name']} original body hash")
            src = mod / fn["translation_source"]
            need(sha(src) == fn["translation_source_sha256"],
                 f"{fn['name']} translation source hash")
        text = (mod / fname).read_text()
        need("_readFile" not in [f["name"] for f in doc["functions"]],
             f"{mod.name} must not claim _readFile recovery")


def flags(opt, ubsan):
    cmd = ["clang"] + BASE[:BASE.index("-std=c11")] + [f"-O{opt}"] + \
          BASE[BASE.index("-std=c11"):]
    for inc in INCLUDES:
        cmd += ["-I", str(inc)]
    if ubsan:
        rt = Path(subprocess.check_output(["clang", "-print-resource-dir"],
                                          text=True).strip()) / "lib/linux"
        cmd += ["-fsanitize=undefined", "-fsanitize-minimal-runtime"]
        return cmd, rt / "libclang_rt.ubsan_minimal-arm-android.a"
    return cmd, None


def build(out, opt, ubsan=False, sources=None):
    cmd, rt = flags(opt, ubsan)
    cmd += [str(p) for p in (sources or SOURCES)]
    if rt is not None:
        cmd.append(str(rt))
    cmd += ["-o", str(out)]
    p = subprocess.run(cmd, text=True, capture_output=True)
    need(p.returncode == 0, "compile/link failed: " + (p.stderr or "")[-800:])
    selected = sources or SOURCES
    bound = {str(x): sha(x) for x in selected}
    binary_sha = sha(out)
    BINDINGS[str(out)] = {"argv": [str(x) for x in cmd], "sources": bound,
                          "binary_sha256": binary_sha}
    print("BINDING v1 entry=spine-error binary_sha256=" + binary_sha +
          " fixture_sha256=" + sha(FIX) + " original_sha256=" + PIN +
          " source_set_sha256=" + hashlib.sha256(json.dumps(bound,sort_keys=True).encode()).hexdigest(), flush=True)
    return out


def run(exe):
    before = BINDINGS[str(exe)]["binary_sha256"]
    need(sha(exe) == before, "binary changed before execution")
    p = subprocess.run(["qemu-arm", str(exe)], text=True,
                       capture_output=True, timeout=60)
    need(sha(exe) == before, "binary changed during execution")
    output = (p.stdout or "") + (p.stderr or "")
    RUNS.append({"binary":str(exe), "binary_sha256":before,
                 "exit_code":p.returncode, "output":output})
    return p.returncode, output


def run_variant(tmp, name, opt, ubsan=False):
    exe = build(tmp / f"{name}.arm", opt, ubsan)
    rc, out = run(exe)
    need(rc == 0, f"{name} exited {rc}: " + out[-800:])
    passed = [line.split(" ", 1)[1] for line in out.splitlines()
              if line.startswith("PASS ")]
    need(passed == TESTS, f"{name} test roster/order mismatch")
    need("ALL PASS spine_json_error/support" in out, f"{name} missing ALL PASS")
    if ubsan:
        dis = subprocess.run(["llvm-objdump", "-d", str(exe)],
                             text=True, capture_output=True).stdout
        for fn in ("<Json_dispose>:", "<ReportSpineError>:"):
            part = dis.split(fn, 1)[1].split("\n\n", 1)[0]
            need("__ubsan_handle_" in part, f"{name} {fn} not UBSan-instrumented")
    print(f"PASS variant {name}: {len(passed)} tests")


def mutate(tmp, name, err_text, sup_text):
    d = tmp / ("mut_" + name)
    d.mkdir()
    ep, sp = d / "error.c", d / "support.c"
    ep.write_text(err_text)
    sp.write_text(sup_text)
    sources = [C / "spine_alloc/src/spine_alloc.c", sp, ep, FIX]
    exe = build(d / "check.arm", 1, sources=sources)
    rc, out = run(exe)
    need(rc != 0, f"mutation {name} was accepted (exit 0)")
    need("FAIL " in out, f"mutation {name} failed without a named FAIL")
    first = next(line for line in out.splitlines() if line.startswith("FAIL "))
    print(f"PASS mutation rejected {name}: {first}")


def mutations(tmp):
    nl = "\n"
    err = (ERR / "src/spine_json_error.c").read_text()
    sup = (SUP / "src/spine_json_support.c").read_text()
    cases = []
    cases.append(("tag_short", err.replace(str(TAG.decode()), "spine_json_err"), sup))
    cases.append(("prefix_wrong", err.replace(
        '"Unable to read skeleton file: ", path);',
        '"Error reading skeleton file: ", path);'), sup))
    cases.append(("line_91", err.replace("        90u);", "        91u);"), sup))
    cases.append(("extra_ignored", err.replace("    if (extra != NULL) {",
                                               "    if (0) {"), sup))
    cached = sup.replace(
        "        if (child != NULL) {" + nl + "            Json_dispose(child);",
        "        const char *cached_s = json->string_value;" + nl +
        "        const char *cached_n = json->name;" + nl +
        "        if (child != NULL) {" + nl + "            Json_dispose(child);")
    cached = cached.replace("        const char *string_value = json->string_value;",
                            "        const char *string_value = cached_s;")
    cached = cached.replace("        const char *name = json->name;",
                            "        const char *name = cached_n;")
    cases.append(("json_fields_cached", err, cached))
    cases.append(("json_next_reread", err, sup.replace(
        "        json = next;",
        "        json = (next != NULL) ? json->next : json->next;")))
    cases.append(("report_slot_08", err, sup.replace(
        '    console->vptr->output(console, "Spine Error:%s\\n", message);',
        '    ((SpineErrorOutputFn *)(const void *)console->vptr)[2](console, "Spine Error:%s\\n", message);')))
    cases.append(("reporter_cached", err, sup.replace(
        "    struct SpineErrorConsole *console = dbg_csol;",
        "    static struct SpineErrorConsole *console;" + nl +
        "    if (console == NULL) console = dbg_csol;")))
    cases.append(("no_free_data", err.replace(
        "    _free(data);" + nl + nl + "    /* 0x28eb8c",
        "    /* removed */" + nl + nl + "    /* 0x28eb8c"), sup))
    cases.append(("size_check_dropped", err.replace(
        "    if (size == 0 || data == NULL) {", "    if (data == NULL) {"), sup))
    for name, e, s in cases:
        mutate(tmp, name, e, s)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--original", default="/data/data/com.termux/files/home/cally-oracle/libyoyo.so")
    ap.add_argument("--no-mutations", action="store_true")
    ap.add_argument("--keep", action="store_true")
    ap.add_argument("--out", type=Path, help="new exclusive persistent output directory")
    args = ap.parse_args()
    if args.out:
        args.out.mkdir(parents=True,exist_ok=False);tmp=args.out
    else:
        tmp = Path(tempfile.mkdtemp(prefix="spine-json-error-", dir=os.environ.get("TMPDIR")))
    compiler_tmp=tmp/"compiler-tmp";compiler_tmp.mkdir();os.environ["TMPDIR"]=str(compiler_tmp)
    try:
        dep_flags=[x for x in BASE if not x.startswith(("-Wl,","-fuse-ld=")) and x not in ("-nostdlib","-static")]
        deps=set(SOURCES+[Path(__file__).resolve()])
        for src in SOURCES:
            p=subprocess.run(["clang",*dep_flags,*["-I"+str(x) for x in INCLUDES],"-MM",str(src)],capture_output=True,text=True)
            need(p.returncode==0,"dependency scan failed: "+p.stderr)
            deps.update(Path(x).resolve() for x in p.stdout.replace("\\\n","").split(":",1)[1].split())
        before={str(x):sha(x) for x in sorted(deps)}
        orig = check_original(Path(args.original))
        check_functions(orig)
        print("PASS static original bytes/symbols/relocations/contract")
        for name, opt in (("O0", 0), ("O2", 2), ("O3", 3)):
            run_variant(tmp, name, opt)
        run_variant(tmp, "UBSan", 1, ubsan=True)
        if not args.no_mutations:
            mutations(tmp)
        need(before=={str(x):sha(x) for x in sorted(deps)},"source/header/checker drift during acceptance")
        report={"schema":"cally-error-parent-check/1","status":"PASS","original_executed":False,
                "scope":"reconstructed ARM32 plus synthetic file/loader/platform providers",
                "source_binding":before,"builds":BINDINGS,"runs":RUNS,"declared_tests":TESTS}
        (tmp/"receipt.json").write_text(json.dumps(report,ensure_ascii=False,indent=2)+"\n")
        print("SUMMARY PASS: static + O0/O2/O3/UBSan + mutations; original not executed")
        print("RECEIPT",tmp/"receipt.json")
    except Failed as exc:
        print("FAIL:", exc)
        return 1
    finally:
        if args.keep or args.out:
            print("kept", tmp)
        else:
            shutil.rmtree(tmp, ignore_errors=True)
    return 0


if __name__ == "__main__":
    sys.exit(main())
