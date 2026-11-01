#!/usr/bin/env python3
"""run_tests.py — FreeMask/FreeTexture 译文 + 合成夹具的验收脚本。

做三件事：
  1. 干净译文：host 执行 10 个具名用例；再用 armv7a-none-eabi 编译 -Werror
     （只证明布局/ABI 可编译，不执行 ARM 产物）。
  2. 语义变异体：对“外调后重读”和“写序”做定点文本变异，每个变异体必须
     在指定用例上以退出码 20 + 具名 ASSERT_FAIL 被杀，且另一个 no-op 用例
     仍通过（证明变异体本身可运行、不是崩溃）。
  3. 形式 no-op 变异：改写但不改语义，全部用例必须通过。

不加载、不执行原件 libyoyo_armv7.so；夹具只链接译文和替身。
"""
import json
import os
import atexit
import tempfile
import hashlib
import shutil
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC = os.path.join(ROOT, "src", "free_resources.c")
FIX = os.path.join(ROOT, "fixture", "free_resources_tests.c")
HDR_DIR = os.path.join(os.path.dirname(ROOT), "csprite_clear", "src")
OUT = os.environ.get("CALLY_RESOURCE_OUT")
if not OUT:
    OUT = tempfile.mkdtemp(prefix="cally-free-resources-")
    atexit.register(shutil.rmtree, OUT, ignore_errors=True)

CC = shutil.which("clang")
if not CC:
    print("FAIL clang 不在 PATH")
    sys.exit(1)

CFLAGS_HOST = ["-std=c11", "-O2", "-Wall", "-Wextra", "-Werror", "-I", HDR_DIR]
CFLAGS_ARM = ["--target=armv7a-none-eabi", "-march=armv7-a",
              "-mfloat-abi=soft", "-marm", "-std=c11", "-O2", "-Wall",
              "-Wextra", "-Werror", "-ffreestanding", "-I", HDR_DIR]

# (变体名, 用例, 期望退出码, 期望 ASSERT_FAIL 前缀, 安全冒烟用例)
MUTANTS = [
    ("fm_count_cached", "fm_count_reread_shrink", 20,
     "ASSERT_FAIL:fm_count_reread_shrink:FM_COUNT_REREAD_CALLS",
     "fm_hasmask0_noop",
     [("            count = self->mask_count;\n", "")]),
    ("fm_base_cached", "fm_base_reread", 20,
     "ASSERT_FAIL:fm_base_reread:FM_BASE_REREAD_SECOND",
     "fm_hasmask0_noop",
     [("            rows  = self->mask_rows;\n", "")]),
    ("fm_clear_early", "fm_order_null_entry", 20,
     "ASSERT_FAIL:fm_order_null_entry:FM_CLEAR_AFTER_BASE_FIELD",
     "fm_hasmask0_noop",
     [("    MemoryManager_Free((const void *)(uintptr_t)rows);\n"
       "    self->mask_rows = 0;\n",
       "    self->mask_rows = 0;\n"
       "    MemoryManager_Free((const void *)(uintptr_t)rows);\n")]),
    ("ft_count_cached", "ft_count_reread", 20,
     "ASSERT_FAIL:ft_count_reread:FT_COUNT_REREAD_CALLS",
     "ft_zero_count_noop",
     [("            count = self->texture_count;\n", "")]),
    ("ft_clear_early", "ft_order_skip", 20,
     "ASSERT_FAIL:ft_order_skip:FT_ORDER_CLEAR_AFTER_FREE",
     "ft_zero_count_noop",
     [("            GR_Texture_Free(id);           /* 0x1e5728 */\n"
       "\n"
       "            /* 0x1e572c: ldr r3,[r5,#0x50] —— 外调后重读 id 数组基址 */\n"
       "            ids = self->texture_ids;\n"
       "            ((int32_t *)(uintptr_t)ids)[i] = -1;  /* 0x1e5730: r6=-1 */\n",
       "            ((int32_t *)(uintptr_t)ids)[i] = -1;  /* MUT: 提前写，且不重读基址 */\n"
       "            GR_Texture_Free(id);           /* 0x1e5728 */\n")]),
    ("ft_guard_eq", "ft_negative_count", 20,
     "ASSERT_FAIL:ft_negative_count:FT_NEG_NO_CALL",
     "ft_zero_count_noop",
     [("    if (count <= 0) {", "    if (count == 0) {")]),
    ("ft_base_cached", "ft_base_reread", 20,
     "ASSERT_FAIL:ft_base_reread:FT_BASE_REREAD_IDS",
     "ft_zero_count_noop",
     [("            ids = self->texture_ids;\n", "")]),
]

NOOPS = [
    ("fm_zero_store_order",
     [("            row[1] = 0;                                       /* 0x1e3ba0 */\n"
       "            row[0] = 0;                                       /* 0x1e3ba4 */\n",
       "            row[0] = 0;                                       /* 0x1e3ba4 */\n"
       "            row[1] = 0;                                       /* 0x1e3ba0 */\n")]),
    ("ft_reread_before_store",
     [("            ((int32_t *)(uintptr_t)ids)[i] = -1;  /* 0x1e5730: r6=-1 */\n"
       "\n"
       "            /* 0x1e5734: ldr r2,[r5,#0x4c] —— 外调后重读计数 */\n"
       "            count = self->texture_count;\n",
       "            /* 0x1e5734: ldr r2,[r5,#0x4c] —— 外调后重读计数 */\n"
       "            count = self->texture_count;\n"
       "            ((int32_t *)(uintptr_t)ids)[i] = -1;  /* 0x1e5730: r6=-1 */\n")]),
]

TESTS = [
    "fm_hasmask0_noop", "fm_order_null_entry", "fm_count_reread_shrink",
    "fm_base_reread", "fm_negative_count", "ft_zero_count_noop",
    "ft_order_skip", "ft_count_reread", "ft_negative_count", "ft_base_reread",
]

report = {"results": [], "failures": []}


def record(name, ok, detail=""):
    report["results"].append({"name": name, "ok": bool(ok), "detail": detail})
    print(("PASS  " if ok else "FAIL  ") + name + (("   " + detail) if detail else ""))
    if not ok:
        report["failures"].append(name)


def run(cmd, **kw):
    p = subprocess.run(cmd, capture_output=True, text=True, **kw)
    return p.returncode, p.stdout, p.stderr


def build_host(tag, src):
    exe = os.path.join(OUT, "tests_" + tag)
    rc, out, err = run([CC] + CFLAGS_HOST + ["-o", exe, src, FIX])
    record("build.host." + tag, rc == 0, (out + err).strip()[:500])
    return exe if rc == 0 else None


def build_arm_obj(tag, src):
    obj = os.path.join(OUT, "free_resources_" + tag + "_armv7.o")
    rc, out, err = run([CC] + CFLAGS_ARM + ["-c", src, "-o", obj])
    record("build.armv7." + tag, rc == 0, (out + err).strip()[:500])
    return obj if rc == 0 else None


def run_one(exe, test):
    rc, out, err = run([exe, test])
    return rc, out, err


def variant_source(tag, edits):
    text = open(SRC, encoding="utf-8").read()
    for old, new in edits:
        n = text.count(old)
        if n != 1:
            record("mutation.anchor." + tag, False,
                   "anchor count=%d for %r" % (n, old[:60]))
            return None
        text = text.replace(old, new, 1)
    path = os.path.join(OUT, "mutant_" + tag + ".c")
    with open(path, "w", encoding="utf-8") as f:
        f.write(text)
    record("mutation.anchor." + tag, True)
    return path


def main():
    for p in (SRC, FIX, os.path.join(HDR_DIR, "csprite_clear.h"), __file__):
        print("BINDING", p, hashlib.sha256(open(p,"rb").read()).hexdigest())
    os.makedirs(OUT, exist_ok=True)
    if not os.path.isdir(HDR_DIR):
        print("FAIL 共享头目录不存在: " + HDR_DIR)
        return 1

    baseline = build_host("baseline", SRC)
    arm_obj = build_arm_obj("baseline", SRC)
    if baseline:
        for t in TESTS:
            rc, out, err = run_one(baseline, t)
            ok = rc == 0 and ("PASS:" + t) in out
            record("case." + t, ok, "" if ok else "rc=%d err=%s" % (rc, err.strip()[:300]))

    for name, test, want_rc, marker, smoke, edits in MUTANTS:
        src = variant_source(name, edits)
        if not src:
            continue
        exe = build_host(name, src)
        build_arm_obj(name, src)
        if not exe:
            continue
        rc, out, err = run_one(exe, test)
        ok = rc == want_rc and marker in err
        record("kill." + name, ok,
               "" if ok else "rc=%d(want %d) err=%s" % (rc, want_rc, err.strip()[:300]))
        rc2, out2, err2 = run_one(exe, smoke)
        record("safe." + name + "." + smoke, rc2 == 0,
               "" if rc2 == 0 else "rc=%d err=%s" % (rc2, err2.strip()[:300]))

    for name, edits in NOOPS:
        src = variant_source(name, edits)
        if not src:
            continue
        exe = build_host(name, src)
        if not exe:
            continue
        for t in TESTS:
            rc, out, err = run_one(exe, t)
            ok = rc == 0
            record("noop." + name + "." + t, ok,
                   "" if ok else "rc=%d err=%s" % (rc, err.strip()[:300]))

    passed = sum(1 for r in report["results"] if r["ok"])
    total = len(report["results"])
    report["passed"] = passed
    report["total"] = total
    report["arm_obj"] = arm_obj is not None
    with open(os.path.join(OUT, "run-report.json"), "w", encoding="utf-8") as f:
        json.dump(report, f, ensure_ascii=False, indent=2)
    print("\n%d/%d checks passed" % (passed, total))
    return 0 if passed == total else 1


if __name__ == "__main__":
    sys.exit(main())
