#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""negctl.py — 负控：证明这套测试**确实能区分**原文语义写错，而不是只会跑绿。

判定规则（REVIEW-r2 的 Loader 负控要求）：
  · 每个变异体都写死「期望退出码」与「期望失败的用例名集合」，**两者同时相等**才算被抓住；
    只对上一个不算。
  · 退出码 < 0（被信号杀掉）一律判 INVALID：崩溃不是语义证据，说明变异体把程序搞崩了
    而不是被断言抓住。本表里没有任何一条依赖信号。
  · no-op 对照必须**输出逐字节相同**（比「rc==0」强：证明不是碰巧全绿）。
  · 变异体只允许改 candidate 源文件的少数行（purity：改动行数 ≤ 12），锚点必须唯一，
    否则直接判 ANCHOR-ERR。
  · 所有变异都保持**边界内**：没有一条依赖越界读/写来产生差异。

用法：python3 scripts/negctl.py [-v] [--host-only]
退出码：0 = 全部符合期望；1 = 有不符合；2 = 缺工具（qemu-arm 等，不冒充全绿）。
"""
import difflib
import os
import shutil
import subprocess
import sys
import tempfile

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
C = os.path.join(ROOT, "src")
SRC = os.path.join(C, "csprite_loadfromchunk.c")
SRCS = [SRC, os.path.join(C, "test_doubles.c"), os.path.join(C, "driver.c")]

HOST_FLAGS = ["-std=c11", "-O1", "-g", "-Wall", "-Wextra", "-Werror",
              "-fmath-errno", "-ffp-contract=off", "-I" + C]
ARM_FLAGS = ["--target=armv7a-none-eabi", "-march=armv7-a", "-mfpu=vfpv3-d16",
             "-mfloat-abi=softfp", "-marm", "-std=c11", "-O2",
             "-Wall", "-Wextra", "-Werror", "-ffreestanding", "-fno-builtin",
             "-fmath-errno", "-ffp-contract=off", "-DHARNESS_FREESTANDING",
             "-nostdlib", "-static", "-fuse-ld=lld", "-Wl,-e,_start", "-I" + C]

# ── 变异体表 ─────────────────────────────────────────────────────────────
# (名字, 锚点, 替换, 期望 rc, 期望失败用例集合, 说明)
MUTANTS = [
    ("M0_noop",
     "/* ── ARM `lsl #2`：32 位模 2^32 左移",
     "/* ── (no-op) ARM `lsl #2`：32 位模 2^32 左移",
     0, set(), "阳性对照：只改注释，必须输出完全相同"),

    ("M1_vcvt_satmax",
     "        return INT32_MIN;                    /* 死分支：合同值 */",
     "        return INT32_MAX;                    /* OLD: 旧写法『饱和到 MAX』*/",
     1, {"T21"}, "VCVT 越界死分支写成 INT32_MAX"),

    ("M2_unsigned_sq",
     "        float ox2 = (float)yy_mul32(ox, ox);      /* vcvt.f32.s32 s18 */\n"
     "        float oy2 = (float)yy_mul32(oy, oy);      /* vcvt.f32.s32 s19 */\n"
     "        float dw2 = (float)yy_mul32(dw, dw);      /* vcvt.f32.s32 s17 */\n"
     "        float dh2 = (float)yy_mul32(dh, dh);      /* vcvt.f32.s32 s16 */",
     "        float ox2 = (float)((uint32_t)ox * (uint32_t)ox);   /* OLD: 无符号平方 */\n"
     "        float oy2 = (float)((uint32_t)oy * (uint32_t)oy);\n"
     "        float dw2 = (float)((uint32_t)dw * (uint32_t)dw);\n"
     "        float dh2 = (float)((uint32_t)dh * (uint32_t)dh);",
     1, {"T18"}, "平方按无符号解释（vcvt.f32.s32 → 应是 vcvt.f32.u32 的误读）"),

    ("M3_no_int32_wrap",
     "        float ox2 = (float)yy_mul32(ox, ox);      /* vcvt.f32.s32 s18 */",
     "        float ox2 = (float)ox * (float)ox;        /* OLD: 不截 int32，回绕消失 */",
     1, {"T18"}, "先转 float 再乘：丢掉 mul 的低 32 位回绕"),

    ("M4_no_gate",
     "    uint32_t bytes = ((uint32_t)count > 0x1FC00000u) ? 0xFFFFFFFFu : ((uint32_t)count << 2);",
     "    uint32_t bytes = (uint32_t)count << 2;    /* OLD: 没有 0x1FC00000 闸 */",
     4, {"T08", "T09", "T23", "T24"}, "删掉 0x1FC00000 长度闸"),

    ("M5_signed_gate",
     "    uint32_t bytes = ((uint32_t)count > 0x1FC00000u) ? 0xFFFFFFFFu : ((uint32_t)count << 2);",
     "    uint32_t bytes = (count > 0x1FC00000) ? 0xFFFFFFFFu : ((uint32_t)count << 2); /* OLD: 有符号比较 */",
     2, {"T08", "T23"}, "闸用有符号比较（原版是 mvnhi ⇒ 无符号）"),

    ("M6_flag35_uncond",
     "        if (mask_count > 0) {\n"
     "            cur += 4;                                        /* add r6,r6,#4 */\n"
     "            yy_slot_set((uint32_t *)&self->field_68, cur);   /* str r6,[r4,#0x68] */\n"
     "            self->flag_35 = (uint8_t)(mask_count == count);  /* strb r5,[r4,#0x35] */\n"
     "        } else {",
     "        self->flag_35 = (uint8_t)(mask_count == count);      /* OLD: 无条件写 +0x35 */\n"
     "        if (mask_count > 0) {\n"
     "            cur += 4;\n"
     "            yy_slot_set((uint32_t *)&self->field_68, cur);\n"
     "        } else {",
     3, {"T03", "T04", "T25"}, "maskCount<=0 时也写 +0x35（原版一个字节都不写）"),

    ("M7_nan_abs",
     "        float c0 = ceilf(sqrtf(ox2 + oy2));       /* s14 → s15 → ceilf ⇒ s20 */",
     "        float c0 = ceilf(sqrtf(__builtin_fabsf(ox2 + oy2))); /* OLD: 假设和不会为负 */",
     1, {"T18"}, "按『平方和不会为负』写成 fabs"),

    ("M8_no_reread_18",
     "    count = self->frame_count;                              /* ldr r5,[r4,#0x18] */",
     "    /* OLD: 不重读 this+0x18，直接用分配前寄存器里的 count */",
     1, {"T22"}, "分配后不重读 +0x18（原版 0x1e9828 `ldr r5,[r4,#0x18]`）"),

    ("M9_field6c_float_assign",
     "                memcpy(&self->field_6c, &v44, 4);\n"
     "                memcpy(&self->field_70, &v48, 4);",
     "                self->field_6c = (float)v44;    /* OLD: 浮点赋值，位型被改 */\n"
     "                self->field_70 = (int32_t)v48;",
     2, {"T14", "T26"}, "0x6c/0x70 写成数值转换（原版是裸 32 位 ldr/str）"),

    ("M10_mask_ge0",
     "        if (mask_count > 0) {",
     "        if (mask_count >= 0) {   /* OLD: ble 与 blt 的误读 */",
     2, {"T03", "T25"}, "掩码分支用 >= 0（原版 0x1e9850 是 ble ⇒ > 0）"),
]


def run(cmd):
    p = subprocess.run(cmd, capture_output=True, text=True)
    return p.returncode, p.stdout + p.stderr


def parse(out):
    """只取用例 ID（T01…）——失败行的名字后面还带描述，不参与集合比较。"""
    pas, fai = [], []
    for ln in out.splitlines():
        if ln.startswith("PASS  "):
            pas.append(ln[6:].split()[0])
        elif ln.startswith("FAIL  "):
            fai.append(ln[6:].split()[0])
    return pas, fai


def build_run(flags, srcs, outdir, tag, runner=None):
    exe = os.path.join(outdir, "drv_" + tag)
    rc, out = run(["clang"] + flags + ["-o", exe] + srcs)
    if rc != 0:
        return dict(ok=False, stage="compile", out=out, rc=rc)
    rc, out = run(([runner] if runner else []) + [exe])
    return dict(ok=True, stage="run", rc=rc, out=out)


def changed_lines(a, b):
    sm = difflib.SequenceMatcher(None, a, b)
    return sum(max(i2 - i1, j2 - j1) for op, i1, i2, j1, j2 in sm.get_opcodes()
               if op != "equal")


def main():
    verbose = "-v" in sys.argv
    host_only = "--host-only" in sys.argv
    have_qemu = shutil.which("qemu-arm") is not None
    if shutil.which("clang") is None:
        print("缺 clang")
        return 2
    if not have_qemu and not host_only:
        print("缺 qemu-arm；用 --host-only 只跑 host（不冒充 ARM 矩阵）")
        return 2

    outdir = tempfile.mkdtemp(prefix="cally-loader-negctl-")
    base = open(SRC, encoding="utf-8").read()
    base_lines = base.splitlines()

    print("== 基线（固定实现，必须 0 失败）==")
    hb = build_run(HOST_FLAGS + ["-lm"], SRCS, outdir, "host_base")
    if not hb["ok"] or hb["rc"] != 0:
        print("host 基线失败：\n" + hb.get("out", "")[:1500])
        return 2
    bases = {"host": hb}
    if have_qemu and not host_only:
        ab = build_run(ARM_FLAGS, SRCS, outdir, "arm_base", runner="qemu-arm")
        if not ab["ok"] or ab["rc"] != 0:
            print("arm32 基线失败：\n" + ab.get("out", "")[:1500])
            return 2
        bases["arm32"] = ab
    for k, v in bases.items():
        _, fai = parse(v["out"])
        print("PASS  基线 %-5s rc=0 fail=%d" % (k, len(fai)))

    bad = []
    print("\n== 变异体（每个都必须按**具名断言 + 精确退出码**被抓住）==")
    print("%-24s %-8s %-9s %s" % ("mutant", "target", "verdict", "evidence"))
    for name, anchor, repl, exp_rc, exp_fail, note in MUTANTS:
        n = base.count(anchor)
        if n != 1:
            print("%-24s %-8s %-9s 锚点出现 %d 次（要求 1 次）" % (name, "-", "ANCHOR-ERR", n))
            bad.append(name)
            continue
        mutated = base.replace(anchor, repl, 1)
        pure = changed_lines(base_lines, mutated.splitlines())
        if pure > 12:
            raise SystemExit("mutation purity exceeded: " + name)
        path = os.path.join(outdir, name + ".c")
        open(path, "w", encoding="utf-8").write(mutated)
        srcs = [path] + SRCS[1:]

        for target, flags, runner in (("host", HOST_FLAGS + ["-lm"], None),
                                      ("arm32", ARM_FLAGS, "qemu-arm")):
            if target == "arm32" and (host_only or not have_qemu):
                continue
            res = build_run(flags, srcs, outdir, target + "_" + name, runner=runner)
            if not res["ok"]:
                print("%-24s %-8s %-9s 编译失败：%s"
                      % (name, target, "COMPILE-FAIL", res["out"].strip().splitlines()[-1][:80]))
                bad.append(name)
                continue
            _, fai = parse(res["out"])
            rc = res["rc"]
            if name == "M0_noop":
                same = res["out"] == bases[target]["out"] and rc == 0
                verdict = "PASS-EXPECTED" if same else "FALSE-RED!!"
                ev = "输出与基线 %s（rc=%d）" % ("完全相同" if same else "**不同**", rc)
                if not same:
                    bad.append(name)
            elif rc < 0:
                verdict, ev = "INVALID(signal)", "被信号 %d 杀掉 —— 崩溃不是语义证据" % (-rc)
                bad.append(name)
            elif rc == exp_rc and set(fai) == exp_fail:
                verdict, ev = "CAUGHT", "rc=%d, 具名失败=%s" % (rc, ",".join(sorted(fai)))
            else:
                verdict = "MISMATCH!!"
                ev = "rc=%d(期望%d), 失败={%s}(期望{%s})" % (
                    rc, exp_rc, ",".join(sorted(fai)), ",".join(sorted(exp_fail)))
                bad.append(name)
            print("%-24s %-8s %-9s %s" % (name, target, verdict, ev))
            if verbose and fai:
                for f in fai[:4]:
                    print("      - " + f)
        print("%-24s %-8s %-9s purity: 改动 %d 行；%s" % (name, "-", "-", pure, note))

    shutil.rmtree(outdir, ignore_errors=True)
    print()
    if bad:
        print("负控失败：%s" % ", ".join(sorted(set(bad))))
        return 1
    print("负控通过：基线 0 失败；%d 个语义变异全部按具名断言+精确退出码被抓住；"
          "no-op 输出与基线逐字节相同。" % (len(MUTANTS) - 1))
    return 0


if __name__ == "__main__":
    sys.exit(main())
