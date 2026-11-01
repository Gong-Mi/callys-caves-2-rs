#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""run_fixtures.py — 构建并运行 CSprite::Clear 译文 fixture，验证变异体被杀。

用例矩阵（期望值写死在这里，跑不过就是 FAIL，不伪装 PASS）：

  fixed_host   9 passed / 4 skipped / 0 failed
  m1/m1a/m1b  TPE 计数和表基址变异，分别由 T3/T4/T5 杀死
  m2_host      不能观察位图 vtable 路径（4 个 host skip）
  m3_host      提前读取纹理指针，被 T13 杀死
  fixed_arm    ARM32/qemu-arm，13 passed / 0 skipped
  m1/m1a/m1b/m2/m3_arm  分别在指定场景被杀死

host 上代码地址在 0x6... （> 4 GiB），而 CSprite 的槽是 32 位，位图路径的
`blx` 无法建模，所以 T8/T9/T10/T11 在 host 上显式 SKIP；ARM32 构建（qemu-arm）
覆盖全部 12 项。M2 的杀伤只在 ARM32 上成立——这一点被写成断言，不能用 host 的
“0 failed”冒充。

退出码：0 = 全部期望满足；1 = 有期望不满足；2 = 缺 qemu-arm（ARM 部分 SKIP）。
"""
import difflib
import atexit
import tempfile
import os
import re
import shutil
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
OUT = os.environ.get("CALLY_CLEAR_OUT")
if OUT:
    OUT = os.path.abspath(OUT)
else:
    OUT = tempfile.mkdtemp(prefix="cally-clear-fixtures-")
    atexit.register(shutil.rmtree, OUT, ignore_errors=True)
SRC = os.path.join(ROOT, "src", "csprite_clear.c")
FIX = os.path.join(ROOT, "tools", "fixture", "fixture_clear.c")
MUT = {
    "m1": os.path.join(ROOT, "tools", "mutants", "csprite_clear_cached_tpe.c"),
    "m1a": os.path.join(ROOT, "tools", "mutants", "csprite_clear_cached_tpe_base.c"),
    "m1b": os.path.join(ROOT, "tools", "mutants", "csprite_clear_cached_tpe_count.c"),
    "m2": os.path.join(ROOT, "tools", "mutants", "csprite_clear_cached_bmp.c"),
    "m3": os.path.join(ROOT, "tools", "mutants", "csprite_clear_cached_texture.c"),
}
IMPL = {"fixed": SRC, **MUT}

CFLAGS_HOST = ["-std=c11", "-O2", "-Wall", "-Wextra", "-Werror", "-I" + os.path.join(ROOT, "src")]
CFLAGS_ARM = ["--target=armv7a-none-eabi", "-march=armv7-a", "-mfloat-abi=soft",
              "-marm", "-std=c11", "-O2", "-Wall", "-Wextra", "-Werror",
              "-ffreestanding", "-I" + os.path.join(ROOT, "src"),
              "-DHARNESS_FREESTANDING", "-nostdlib", "-static", "-fuse-ld=lld",
              "-Wl,-e,_start"]
CFLAGS_ARM_OBJ = ["--target=armv7a-none-eabi", "-march=armv7-a", "-mfloat-abi=soft",
                  "-marm", "-std=c11", "-O2", "-Wall", "-Wextra", "-Werror",
                  "-ffreestanding", "-I" + os.path.join(ROOT, "src")]

EXPECT = {
    "fixed_host": {"rc": 0, "fail": set()},
    "m1_host": {"rc": 3, "fail": {"T3_tpe_base_reread", "T4_tpe_count_grow",
                                  "T5_tpe_count_shrink"}},
    "m1a_host": {"rc": 1, "fail": {"T3_tpe_base_reread"}},
    "m1b_host": {"rc": 2, "fail": {"T4_tpe_count_grow", "T5_tpe_count_shrink"}},
    "m2_host": {"rc": 0, "fail": set()},
    "m3_host": {"rc": 1, "fail": {"T13_texture_ids_reread"}},
    "fixed_arm": {"rc": 0, "fail": set()},
    "m1_arm": {"rc": 3, "fail": {"T3_tpe_base_reread", "T4_tpe_count_grow",
                                 "T5_tpe_count_shrink"}},
    "m1a_arm": {"rc": 1, "fail": {"T3_tpe_base_reread"}},
    "m1b_arm": {"rc": 2, "fail": {"T4_tpe_count_grow", "T5_tpe_count_shrink"}},
    "m2_arm": {"rc": 1, "fail": {"T8_bmp_base_reread"}},
    "m3_arm": {"rc": 1, "fail": {"T13_texture_ids_reread"}},
}

results = []
skips = []


def run(cmd, **kw):
    p = subprocess.run(cmd, capture_output=True, text=True, **kw)
    return p.returncode, p.stdout + p.stderr


def record(name, ok, detail=""):
    results.append((name, ok, detail))
    print(("PASS  " if ok else "FAIL  ") + name + (("   " + detail) if detail else ""))


def record_skip(name, detail=""):
    skips.append((name, detail))
    print("SKIP  " + name + (("   " + detail) if detail else ""))


def code_part(path):
    """取 `#include` 起的代码部分（跳过文件头注释），用于变异体纯度检查。"""
    s = open(path).read()
    return s[s.index('#include "csprite_clear.h"'):].splitlines()


def changed_lines(a, b):
    sm = difflib.SequenceMatcher(None, a, b)
    return sum(max(i2 - i1, j2 - j1) for op, i1, i2, j1, j2 in sm.get_opcodes()
               if op != "equal")


def parse(report):
    pas, skp, fai = [], [], []
    for ln in report.splitlines():
        m = re.match(r"^(PASS|SKIP|FAIL)\s+(\S+)", ln)
        if m:
            {"PASS": pas, "SKIP": skp, "FAIL": fai}[m.group(1)].append(m.group(2))
    return pas, skp, fai


def build_host(tag, src, exe):
    rc, out = run(["clang"] + CFLAGS_HOST + ["-o", exe, src, FIX])
    record("build host " + tag, rc == 0, "" if rc == 0 else out[:400])
    return rc == 0


def build_arm(tag, src, exe):
    rc, out = run(["clang"] + CFLAGS_ARM + ["-o", exe, src, FIX])
    record("build armv7 %s (link static, -Werror)" % tag, rc == 0, "" if rc == 0 else out[:400])
    return rc == 0


def compile_arm_obj(tag, src):
    obj = os.path.join(OUT, tag + ".o")
    rc, out = run(["clang"] + CFLAGS_ARM_OBJ + ["-c", src, "-o", obj])
    record("compile armv7 %s -c -Werror" % tag, rc == 0, "" if rc == 0 else out[:400])
    return rc == 0


def main():
    os.makedirs(OUT, exist_ok=True)
    have_qemu = shutil.which("qemu-arm") is not None
    have_clang = shutil.which("clang") is not None
    if not have_clang:
        record("clang available", False, "clang not found")
        return 1

    for tag in IMPL:
        build_host(tag, IMPL[tag], os.path.join(OUT, "fx_host_" + tag))
        compile_arm_obj(tag, IMPL[tag])

    if have_qemu:
        for tag in IMPL:
            build_arm(tag, IMPL[tag], os.path.join(OUT, "fx_arm_" + tag))
    else:
        record_skip("ARM32 cases", "qemu-arm not found; M2 kill matrix cannot be exercised")

    base = code_part(SRC)
    for tag in MUT:
        n = changed_lines(base, code_part(IMPL[tag]))
        record("mutant %s purity: code-part diff <= 20 lines" % tag, n <= 20, "changed=%d" % n)

    cases = []
    for tag in IMPL:
        cases.append((tag + "_host", os.path.join(OUT, "fx_host_" + tag), False))
    if have_qemu:
        for tag in IMPL:
            cases.append((tag + "_arm", os.path.join(OUT, "fx_arm_" + tag), True))

    for name, exe, is_arm in cases:
        if not os.path.exists(exe):
            record("run " + name, False, "binary missing (build failed)")
            continue
        rc, report = run([exe] if not is_arm else ["qemu-arm", exe])
        open(os.path.join(OUT, name + ".txt"), "w").write(report)
        pas, skp, fai = parse(report)
        exp = EXPECT[name]
        ok = (rc == exp["rc"]) and (set(fai) == exp["fail"])
        detail = "rc=%d fail={%s} pass=%d skip=%d" % (rc, ",".join(fai), len(pas), len(skp))
        record("run " + name, ok, detail)
        if name == "fixed_host":
            ok2 = (len(pas) == 9 and set(skp) == {"T8_bmp_base_reread", "T9_bmp_count_grow",
                                                  "T10_full_order_post", "T11_idempotent"})
            record("fixed_host: skipped set is the low-code subset", ok2, ",".join(skp))
        if name == "fixed_arm":
            record("fixed_arm: all 13 tests executed (no skip)", len(pas) == 13 and not skp,
                   "pass=%d skip=%d" % (len(pas), len(skp)))
        if name == "m2_host":
            record("m2_host: M2 is NOT observable on host (documented boundary)",
                   set(fai) == set(), "host cannot model the 32-bit vtable call")

    fails = [r for r in results if not r[1]]
    print("\n%d 项 fixture 期望，%d PASS，%d FAIL，%d SKIP"
          % (len(results), len(results) - len(fails), len(fails), len(skips)))
    summary = "\n".join(["%s %s %s" % ("PASS" if r[1] else "FAIL", r[0], r[2]) for r in results]
                        + ["SKIP %s %s" % s for s in skips])
    open(os.path.join(OUT, "fixtures-report.txt"), "w").write(summary + "\n")
    if fails:
        return 1
    return 0 if have_qemu else 2


if __name__ == "__main__":
    sys.exit(main())
