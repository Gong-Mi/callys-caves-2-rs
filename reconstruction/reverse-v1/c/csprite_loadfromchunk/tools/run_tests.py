#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""run_tests.py — 构建并运行 CSprite::LoadFromChunk 译文的合成测试（host + ARM32/qemu）

    python3 scripts/run_tests.py            # 两份都跑
    python3 scripts/run_tests.py --host     # 只跑 host（无需 qemu）
    python3 scripts/run_tests.py --keep     # 保留构建产物到 notes/build/

期望：两份都 `summary: N passed, 0 failed`，退出码 0。
缺 qemu-arm 时 ARM 部分记 SKIP 并返回 2——不冒充全绿。
"""
import os
import shutil
import subprocess
import sys
import tempfile

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
C = os.path.join(ROOT, "src")
SRCS = [os.path.join(C, "csprite_loadfromchunk.c"),
        os.path.join(C, "test_doubles.c"),
        os.path.join(C, "driver.c")]

# host：libc + libm；arena 用 mmap 固定映射到低 4 GiB（32 位指针槽）
HOST_FLAGS = ["-std=c11", "-O1", "-g", "-Wall", "-Wextra", "-Werror",
              "-fmath-errno", "-ffp-contract=off", "-I" + C]

# ARM32：与原件同一 AAPCS + softfp；freestanding 静态链接，qemu-arm 直接跑
ARM_FLAGS = ["--target=armv7a-none-eabi", "-march=armv7-a", "-mfpu=vfpv3-d16",
             "-mfloat-abi=softfp", "-marm", "-std=c11", "-O2",
             "-Wall", "-Wextra", "-Werror", "-ffreestanding", "-fno-builtin",
             "-fmath-errno", "-ffp-contract=off", "-DHARNESS_FREESTANDING",
             "-nostdlib", "-static", "-fuse-ld=lld", "-Wl,-e,_start", "-I" + C]


def run(cmd):
    p = subprocess.run(cmd, capture_output=True, text=True)
    return p.returncode, p.stdout + p.stderr


def parse(out):
    pas, fai = [], []
    for ln in out.splitlines():
        if ln.startswith("PASS  "):
            pas.append(ln[6:].strip())
        elif ln.startswith("FAIL  "):
            fai.append(ln[6:].strip())
    return pas, fai


def build_and_run(tag, flags, extra, outdir, runner=None):
    exe = os.path.join(outdir, "drv_" + tag)
    rc, out = run(["clang"] + flags + extra + ["-o", exe] + SRCS)
    if rc != 0:
        print("FAIL  build %s\n%s" % (tag, out[:2000]))
        return dict(ok=False, rc=rc, out=out, pas=[], fai=[], exe=exe)
    rc, out = run(([runner] if runner else []) + [exe])
    pas, fai = parse(out)
    ok = rc == 0 and not fai and len(pas) == 28
    print(("PASS  " if ok else "FAIL  ") + "run %s   rc=%d pass=%d fail=%d"
          % (tag, rc, len(pas), len(fai)))
    if not ok:
        print(out[-2000:])
    return dict(ok=ok, rc=rc, out=out, pas=pas, fai=fai, exe=exe)


def main():
    only_host = "--host" in sys.argv
    keep = "--keep" in sys.argv
    if keep:
        outdir = os.environ.get("CALLY_LOADER_OUT", os.path.join(ROOT, "out"))
        os.makedirs(outdir, exist_ok=True)
    else:
        outdir = tempfile.mkdtemp(prefix="cally-loader-build-")

    results = []
    h = build_and_run("host", HOST_FLAGS, ["-lm"], outdir)
    results.append(h)

    if only_host:
        arm = None
    elif shutil.which("qemu-arm") is None:
        print("SKIP  arm32: 找不到 qemu-arm（不冒充全绿）")
        arm = None
    else:
        arm = build_and_run("arm32", ARM_FLAGS, [], outdir, runner="qemu-arm")
    results.append(arm)

    if keep:
        for r in results:
            if r:
                open(os.path.join(outdir, os.path.basename(r["exe"]) + ".txt"),
                     "w", encoding="utf-8").write(r["out"])

    if not keep:
        shutil.rmtree(outdir, ignore_errors=True)

    bad = [r for r in results if r is not None and not r["ok"]]
    if bad:
        return 1
    if arm is None and not only_host:
        return 2
    print("\n全部通过：host 28 个用例。" if only_host else "\n全部通过：host 与 ARM32/qemu 各 28 个用例。")
    return 0


if __name__ == "__main__":
    sys.exit(main())
