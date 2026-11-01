#!/usr/bin/env python3
"""run_tests.py — ClearSWFData 译文的合成夹具矩阵（host + ARM32 qemu）

三个构建变体编进同一份译文，只靠 -DCLEAR_SWF_MUTANT 选择：
  base    ：期望 10/10 通过
  M1      ：dictionary 数组/计数提到循环外  → 必须被 t9 具名断言拒绝（exit 9）
  M2      ：容器条目数组基址提到循环外      → 必须被 t8 具名断言拒绝（exit 8）
  M3 noop ：尾部两个零写交换顺序            → 必须全部通过（证明测试不照抄写序）

"具名断言精确退出"：断言失败打印 "FAIL <测试名> @ <断言>"，退出码 = 测试序号。
崩溃（signal）不计为 kill：任何以负返回码结束的运行都判为 harness 失败。

原件 libyoyo_armv7.so 不参与任何一步；这里跑的是自建译文 + 夹具替身。
"""
import os
import atexit
import tempfile
import hashlib
import shutil
import subprocess
import sys
import tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC  = os.path.join(ROOT, "src", "clear_swf.c")
FIX  = os.path.join(ROOT, "fixture", "fixture_clear_swf.c")
SUP  = os.path.join(ROOT, "fixture", "arm32_support.c")
HDR = os.path.join(os.path.dirname(ROOT), "csprite_clear", "src")

CFLAGS = ["-std=c11", "-O2", "-g", "-Wall", "-Wextra", "-Werror", "-fno-builtin"]
ARMFLAGS = ["--target=armv7-linux-gnueabihf", "-ffreestanding", "-DFX_FREESTANDING",
            "-nostdlib", "-static", "-marm", "-fno-pic", "-Wl,--no-pie", "-Wl,-e,_start"]

CASES = [
    ("base",    0, None),
    ("M1_dict_hoist",   1, (9, "FAIL t9 dict_reread")),
    ("M2_ent_arr_hoist", 2, (8, "FAIL t8 container_array_reread")),
    ("M3_noop_store_order", 3, None),
    ("M4_skip_zero_record_free", 4, (11, "FAIL t11 zero_records_free_base")),
    ("M5_nonpositive_container_gate", 5, (12, "FAIL t12 negative_container_count")),
]


def run(cmd, **kw):
    return subprocess.run(cmd, capture_output=True, text=True, **kw)


def build(cc, out, mutant, target):
    flags = list(CFLAGS) + (list(ARMFLAGS) if target == "arm" else [])
    source = SRC
    if mutant in (4, 5):
        text = open(SRC, encoding="utf-8").read()
        old, new = (("            mm_free(rec);", "            if (n1 != 0) mm_free(rec);")
                    if mutant == 4 else ("    if (count == 0) {", "    if (count <= 0) {"))
        if text.count(old) != 1:
            raise SystemExit("nonunique regression mutation anchor")
        source = out + ".c"
        open(source, "w", encoding="utf-8").write(text.replace(old, new, 1))
    define = mutant if mutant <= 3 else 0
    cmd = [cc] + flags + [f"-I{HDR}", f"-DCLEAR_SWF_MUTANT={define}",
                          "-o", out, FIX, source]
    if target == "arm":
        cmd.append(SUP)
    r = run(cmd)
    if r.returncode != 0:
        print(r.stdout)
        print(r.stderr)
        raise SystemExit(f"build failed: {target} mutant={mutant}")


def symbols(cc, workdir):
    obj = os.path.join(workdir, "sym.o")
    r = run([cc, "-std=c11", "-O2", "-fno-builtin", f"-I{HDR}", "-c",
             SRC, "-o", obj])
    if r.returncode != 0:
        print(r.stderr)
        raise SystemExit("symbol check build failed")
    nm = shutil.which("llvm-nm") or shutil.which("nm")
    r = run([nm, obj])
    text = r.stdout
    want = {
        "defines _ZN7CSprite12ClearSWFDataEv": " T _ZN7CSprite12ClearSWFDataEv",
        "refs _ZN13MemoryManager4FreeEPKv":    " U _ZN13MemoryManager4FreeEPKv",
        "refs _Z15GR_Texture_Freei":           " U _Z15GR_Texture_Freei",
    }
    for label, pat in want.items():
        ok = pat in text
        print(f"[sym] {label:42s} {'ok' if ok else 'MISSING'}")
        if not ok:
            raise SystemExit("symbol check failed: " + label)


def main():
    cc = shutil.which("clang")
    if not cc:
        print("clang not found", file=sys.stderr)
        return 2
    if not os.path.isdir(HDR):
        print(f"header dir missing: {HDR}", file=sys.stderr)
        return 2
    qemu = shutil.which("qemu-arm")

    outdir = os.environ.get("CALLY_SWF_OUT")
    if not outdir:
        outdir = tempfile.mkdtemp(prefix="cally-cleanswf-")
        atexit.register(shutil.rmtree, outdir, ignore_errors=True)
    os.makedirs(outdir, exist_ok=True)
    print(f"workdir: {outdir}")

    for p in (SRC, FIX, SUP, os.path.join(HDR,"csprite_clear.h"), __file__):
        print("BINDING", p, hashlib.sha256(open(p,"rb").read()).hexdigest())
    symbols(cc, outdir)

    rows = []
    failures = []
    for name, mutant, expect in CASES:
        for target in ("host", "arm"):
            if target == "arm" and not qemu:
                rows.append((target, name, "SKIP", "qemu-arm 缺失，不冒充成功"))
                failures.append("qemu-arm missing")
                continue
            exe = os.path.join(outdir, f"{target}-{name}")
            build(cc, exe, mutant, target)
            cmd = [exe] if target == "host" else [qemu, exe]
            r = run(cmd)
            out = r.stdout

            if r.returncode < 0:
                rows.append((target, name, r.returncode, "CRASH（不计 kill）"))
                failures.append(f"{target}/{name} crashed")
                continue

            if expect is None:
                ok = (r.returncode == 0 and "ALL OK" in out
                      and out.count("PASS ") == 12)
                detail = "12/12 PASS" if ok else f"unexpected stdout/exit={r.returncode}"
            else:
                code, marker = expect
                ok = (r.returncode == code and marker in out)
                detail = (f"killed by {marker[7:]}" if ok
                          else f"expected exit {code}+'{marker}', got exit {r.returncode}")
            if not ok:
                failures.append(f"{target}/{name}: {detail}")
                if os.environ.get("VERBOSE"):
                    print(out)
            rows.append((target, name, r.returncode, detail))

    width = max(len(f"{t}/{n}") for t, n, *_ in rows)
    print()
    for target, name, code, detail in rows:
        print(f"  {target + '/' + name:<{width}}  exit={code!s:<4} {detail}")

    if failures:
        print("\nFAILED:")
        for f in failures:
            print("  -", f)
        return 2 if all("qemu" in f for f in failures) else 1
    print("\nall expectations met (原件未参与)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
