#!/usr/bin/env python3
"""spSkeletonJson_create 0x28b734 / spSkeletonJson_dispose 0x28b74c 的验收。

三步，全部只读原件（不执行、不 mmap、不 Unicorn）：
  1) 身份 + .dynsym（size 24 / 56，helper 52）+ capstone 逐条指令（地址/助记符/操作数/
     分支目标/字面量算术），译文结构与静态事实对不上就直接失败。
  2) host 与 ARM32(qemu-arm) 各编译 5 个变体（0 基线、1..3 语义变异、4 no-op），
     断言精确退出码 + 精确具名失败集合 + PASS 条数；崩溃（rc<0 或 rc 不在 {0,1}）不算杀死。
  3) 目标文件导出集合必须恰好是三个 spSkeletonJson_*（防止隐式多导出/名字写错）。

ARM32 走 -nostdlib -static + 主树 fx.h / arm32_support.c，不需要 ARM libc 或 sysroot。
默认 tempfile.TemporaryDirectory 独占并在退出时清理；--keep 保留现场。
"""
from __future__ import annotations

import argparse
import hashlib
import io
import json
import os
import re
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM, CS_MODE_ARM, CS_MODE_LITTLE_ENDIAN
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[1]
SRC = ROOT / "src"
FIX = ROOT / "fixture"

IMAGE_SHA = "3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a"
HOME = Path(os.path.expanduser("~"))
DEFAULT_SO = HOME / "callys-caves-2-rs/reconstruction/live-mem/libyoyo_armv7.so"
DEFAULT_MAIN = ROOT.parent

# (name, vaddr, size, 参与解码的字节数, 期望指令表)
# create/dispose 整段都是指令；createWithLoader 末尾 4 字节是字面量池。
EXPECT = [
    ("spSkeletonJson_create", 0x28B734, 24, 24, [
        ("push", "{r3, lr}"),
        ("bl", "#0x284bb4"),
        ("bl", "#0x28b700"),
        ("mov", "r3, #1"),
        ("str", "r3, [r0, #0xc]"),
        ("pop", "{r3, pc}"),
    ]),
    ("spSkeletonJson_dispose", 0x28B74C, 56, 56, [
        ("ldr", "r3, [r0, #0xc]"),
        ("push", "{r4, lr}"),
        ("cmp", "r3, #0"),
        ("mov", "r4, r0"),
        ("beq", "#0x28b768"),
        ("ldr", "r0, [r0, #4]"),
        ("bl", "#0x284d38"),
        ("ldr", "r0, [r4, #0x18]"),
        ("bl", "#0x285c80"),
        ("ldr", "r0, [r4, #8]"),
        ("bl", "#0x285c80"),
        ("mov", "r0, r4"),
        ("pop", "{r4, lr}"),
        ("b", "#0x285c80"),
    ]),
    ("spSkeletonJson_createWithLoader", 0x28B700, 52, 48, [
        ("ldr", "r2, [pc, #0x28]"),
        ("mov", "r1, #28"),
        ("push", "{r4, lr}"),
        ("add", "r2, pc, r2"),
        ("mov", "r4, r0"),
        ("mov", "r3, #62"),
        ("mov", "r0, #1"),
        ("bl", "#0x285c4c"),
        ("mov", "r2, #1065353216"),
        ("str", "r4, [r0, #4]"),
        ("str", "r2, [r0]"),
        ("pop", "{r4, pc}"),
    ]),
]

TESTS = [
    "create_returns_calloc_block_at_28_bytes",
    "calloc_uses_original_metadata",
    "create_forwards_atlas_to_attachment_loader",
    "create_stores_loader_at_0x04",
    "create_sets_scale_to_1f_at_0x00",
    "create_sets_owns_loader_at_0x0c",
    "create_leaves_other_words_untouched",
    "create_then_dispose_disposes_created_loader",
    "create_with_null_atlas_forwards_null",
    "dispose_with_flag_set_disposes_loader",
    "dispose_with_flag_clear_skips_loader",
    "dispose_free_order_is_18_then_08_then_self",
    "dispose_does_not_rewrite_fields",
]

FREE18 = "    _free((void *)(uintptr_t)j->unk_18);   /* 28b768 ldr r0,[r4,#0x18]; 28b76c bl _free */"
FREE08 = "    _free((void *)(uintptr_t)j->unk_08);   /* 28b770 ldr r0,[r4,#8];    28b774 bl _free */"
ST_LOADER = "    j->loader = (uint32_t)(uintptr_t)loader;   /* 28b724 str r4,[r0,#4] */"
ST_SCALE = "    j->scale  = 0x3f800000u;                   /* 28b728 str r2,[r0]  = 1.0f */"

# (id, [(old, new)], ok_rc, 期望失败集合, 是否要求与基线输出逐字节相同)
MUTANTS = [
    (0, [], 0, set(), False),
    (1, [("    j->owns_loader = 1u;", "    j->owns_loader = 0u;")], 1,
     {"create_sets_owns_loader_at_0x0c", "create_then_dispose_disposes_created_loader"}, False),
    (2, [("    if (j->owns_loader) {", "    if (1) {")], 1,
     {"dispose_with_flag_clear_skips_loader"}, False),
    (3, [(FREE18 + "\n" + FREE08, FREE08 + "\n" + FREE18)], 1,
     {"dispose_free_order_is_18_then_08_then_self"}, False),
    (4, [(ST_LOADER + "\n" + ST_SCALE, ST_SCALE + "\n" + ST_LOADER)], 0, set(), True),
    (5, [("_calloc(1u, 28u, yy_alloc_tag_357b08, 62u)",
          "_calloc(1u, 28u, (const char *)((uintptr_t)yy_alloc_tag_357b08 & 0u), 62u)")], 1,
     {"calloc_uses_original_metadata"}, False),
]


def normalize_ops(op_str: str) -> str:
    return re.sub(r"#(0x[0-9a-fA-F]+|\d+)", lambda m: "#%d" % int(m.group(1), 0), op_str)


def branch_target(ins) -> int:
    m = re.search(r"#(0x[0-9a-fA-F]+)", ins.op_str)
    if not m:
        raise AssertionError("no branch target in %s %s" % (ins.mnemonic, ins.op_str))
    return int(m.group(1), 16)


def static_gate(so: Path) -> None:
    data = so.read_bytes()
    got = hashlib.sha256(data).hexdigest()
    if got != IMAGE_SHA:
        raise SystemExit("original identity mismatch: %s" % got)
    elf = ELFFile(io.BytesIO(data))

    def raw(addr: int, n: int) -> bytes:
        for seg in elf.iter_segments():
            if seg["p_type"] == "PT_LOAD" and seg["p_vaddr"] <= addr and addr + n <= seg["p_vaddr"] + seg["p_filesz"]:
                off = seg["p_offset"] + addr - seg["p_vaddr"]
                return data[off:off + n]
        raise SystemExit("unmapped original address %#x" % addr)

    def u32(addr: int) -> int:
        return int.from_bytes(raw(addr, 4), "little")

    syms = {s.name: s for s in elf.get_section_by_name(".dynsym").iter_symbols()}
    md = Cs(CS_ARCH_ARM, CS_MODE_ARM | CS_MODE_LITTLE_ENDIAN)

    decoded = {}
    for name, addr, size, body, expected in EXPECT:
        sym = syms[name]
        assert sym["st_value"] == addr, (name, hex(sym["st_value"]))
        assert sym["st_size"] == size, (name, sym["st_size"])
        assert sym["st_info"]["type"] == "STT_FUNC", (name, sym["st_info"])
        ins = list(md.disasm(raw(addr, body), addr))
        got_tab = [(i.mnemonic, normalize_ops(i.op_str)) for i in ins]
        expected = [(m, normalize_ops(o)) for m, o in expected]
        if got_tab != expected:
            for a, b in zip(got_tab, expected):
                if a != b:
                    raise SystemExit("%s decode mismatch:\n  got  %s\n  want %s\nfull=%s"
                                     % (name, a, b, got_tab))
            raise SystemExit("%s instruction count %d != %d" % (name, len(got_tab), len(expected)))
        assert sum(i.size for i in ins) == body, name
        decoded[name] = {i.address: i for i in ins}
        print("decode %-32s %#x size=%-3d insns=%d literal=%dB"
              % (name, addr, size, len(ins), size - body))

    # 分支目标：create 的两个 callee、dispose 的门/尾、helper 的 _calloc
    c, d, h = decoded["spSkeletonJson_create"], decoded["spSkeletonJson_dispose"], decoded["spSkeletonJson_createWithLoader"]
    assert branch_target(c[0x28B738]) == 0x284BB4
    assert branch_target(c[0x28B73C]) == 0x28B700
    assert branch_target(d[0x28B75C]) == 0x28B768
    assert branch_target(d[0x28B764]) == 0x284D38
    assert branch_target(d[0x28B76C]) == 0x285C80
    assert branch_target(d[0x28B774]) == 0x285C80
    assert branch_target(d[0x28B780]) == 0x285C80
    assert branch_target(h[0x28B71C]) == 0x285C4C

    # 字面量池算术：ldr r2,[pc,#0x28] @28b700 -> 28b730；add r2,pc,r2 @28b70c -> 0x357b08
    assert 0x28B700 + 8 + 0x28 == 0x28B730
    assert 0x28B70C + 8 + u32(0x28B730) == 0x357B08
    metadata = b"jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c\0"
    assert raw(0x357B08, len(metadata)) == metadata
    # dispose 的唯一条件分支：跳过 loader 释放时正好落在 28b768（第一个 _free）
    assert 0x28B75C + 8 + 4 == 0x28B768
    # 两个入口都没有 C1/D1 别名（纯 C 名，非 mangled）
    assert "spSkeletonJson_create" in syms and "spSkeletonJson_dispose" in syms
    # dispose 早于 push 读 [r0+0xc]：dynsym size 56 覆盖到 b _free
    print("static predicates: sizes, decode, branch targets, literal math -> PASS")


def run(cmd, env):
    return subprocess.run([str(x) for x in cmd], text=True, capture_output=True, env=env, timeout=180)


def require(p, label):
    if p.returncode:
        raise SystemExit("FAIL build %s rc=%d\n%s%s" % (label, p.returncode, p.stdout, p.stderr))
    return p.stdout


def main() -> int:
    if not __debug__:
        raise SystemExit('refuse optimized Python: assertions are required')
    ap = argparse.ArgumentParser()
    ap.add_argument("--original-so", default=str(DEFAULT_SO))
    ap.add_argument("--main-tree", default=str(DEFAULT_MAIN),
                    help="主树 c/ 目录（提供 cskeleton_lifetime/src/yy_skel_deps.h 与 csprite_resources/fixture）")
    ap.add_argument("--deps-header", default=None, help="yy_skel_deps.h 路径（默认 <main-tree>/cskeleton_lifetime/src/）")
    ap.add_argument("--keep", action="store_true", help="保留临时目录（默认清空）")
    args = ap.parse_args()

    so = Path(args.original_so).expanduser()
    main_tree = Path(args.main_tree).expanduser()
    deps = Path(args.deps_header).expanduser() if args.deps_header else main_tree / "cskeleton_lifetime/src/yy_skel_deps.h"
    loader_h = main_tree / "csprite_loadfromchunk/src/csprite_loadfromchunk.h"
    clear_h = main_tree / "csprite_clear/src/csprite_clear.h"
    fix_dir = main_tree / "csprite_resources/fixture"
    for p in (so, deps, loader_h, clear_h, fix_dir / "fx.h", fix_dir / "arm32_support.c"):
        if not p.exists():
            raise SystemExit("missing required path: %s" % p)

    static_gate(so)
    for p in (SRC / "spine_json_lifetime.c", FIX / "spine_json_fixture.c", deps, loader_h, clear_h,
              fix_dir / "fx.h", fix_dir / "arm32_support.c", Path(__file__)):
        print("BINDING %s %s" % (p, hashlib.sha256(Path(p).read_bytes()).hexdigest()))

    if not shutil.which("qemu-arm"):
        raise SystemExit("qemu-arm missing: ARM32 runtime evidence is required (no ARM libc/sysroot needed)")

    tmp_ctx = tempfile.TemporaryDirectory(prefix="cally-skeljson-")
    d = Path(tmp_ctx.name)
    env = dict(os.environ, TMPDIR=str(d))
    try:
        base = ["-std=c11", "-O2", "-Wall", "-Wextra", "-Werror", "-fno-builtin",
                "-I", str(SRC), "-I", str(FIX), "-I", str(fix_dir),
                '-DYY_SKEL_DEPS_HDR="%s"' % deps,
                '-DYY_LOADER_H="%s"' % loader_h,
                '-DYY_CLEAR_H="%s"' % clear_h]
        arms = ["--target=armv7a-none-eabi", "-march=armv7-a", "-mfloat-abi=soft", "-marm",
                "-ffreestanding", "-nostdlib", "-static", "-fuse-ld=lld", "-Wl,-e,_start",
                "-DFX_FREESTANDING"]

        src_text = (SRC / "spine_json_lifetime.c").read_text()
        baseline = {}
        total = 0
        for tag, flags, runner in (("host", base, []), ("arm32", base + arms, ["qemu-arm"])):
            support = [fix_dir / "arm32_support.c"] if tag == "arm32" else []
            for mut, edits, ok_rc, want_fail, same_output in MUTANTS:
                text = src_text
                for old, new in edits:
                    n = text.count(old)
                    if n != 1:
                        raise SystemExit("mutant %d anchor count=%d for %r" % (mut, n, old[:60]))
                    text = text.replace(old, new, 1)
                variant = SRC / "spine_json_lifetime.c" if mut == 0 else d / ("tu-m%d.c" % mut)
                if mut:
                    variant.write_text(text)
                exe = d / ("fx-%s-m%d" % (tag, mut))
                require(run(["clang", *flags, variant, FIX / "spine_json_fixture.c", *support, "-o", exe], env),
                        "%s/m%d" % (tag, mut))
                p = run([*runner, exe], env)
                fails = re.findall(r"^\[FAIL\] (.+)$", p.stdout, re.M)
                passes = re.findall(r"^\[PASS\] (.+)$", p.stdout, re.M)
                total += 1
                if p.returncode < 0:
                    raise SystemExit("%s/m%d crashed by signal %d (a crash is not a kill)\n%s%s"
                                     % (tag, mut, -p.returncode, p.stdout, p.stderr))
                if p.returncode != ok_rc:
                    raise SystemExit("%s/m%d rc=%d want %d\n%s%s" % (tag, mut, p.returncode, ok_rc, p.stdout, p.stderr))
                if set(fails) != want_fail or len(fails) != len(want_fail):
                    raise SystemExit("%s/m%d failures=%s want %s\n%s%s"
                                     % (tag, mut, sorted(fails), sorted(want_fail), p.stdout, p.stderr))
                if (len(passes) + len(fails) != len(TESTS)
                        or set(passes) & set(fails)
                        or set(passes) | set(fails) != set(TESTS)):
                    raise SystemExit("%s/m%d pass/fail accounting %d+%d\n%s"
                                     % (tag, mut, len(passes), len(fails), p.stdout))
                if same_output:
                    if baseline[tag] != p.stdout:
                        raise SystemExit("%s/m%d no-op changed output" % (tag, mut))
                else:
                    if mut == 0:
                        baseline[tag] = p.stdout
                print("%-5s mutant=%d rc=%d pass=%2d fail=%d %s"
                      % (tag, mut, p.returncode, len(passes), len(fails), sorted(fails)))

        # 导出集合：只允许这三条，名字和 mangling 都不能漂
        obj = d / "tu.o"
        require(run(["clang", *base, "-c", SRC / "spine_json_lifetime.c", "-o", obj], env), "tu object")
        nm = require(run(["llvm-nm", "--defined-only", obj], env), "tu nm")
        defs = {m.group(2) for m in re.finditer(r"^([0-9a-fA-F]+)\s+[TtWw]\s+(\S+)$", nm, re.M)}
        want = {"spSkeletonJson_create", "spSkeletonJson_dispose", "spSkeletonJson_createWithLoader"}
        if defs != want:
            raise SystemExit("exported set %s != %s" % (sorted(defs), sorted(want)))
        print("exports:", " ".join(sorted(defs)))

        # Allocator and loader are real required interfaces. Literal bytes are
        # supplied by this translation, never an undefined weak-to-NULL fallback.
        und = require(run(["llvm-nm", "-u", obj], env), "tu undefined")
        undef = {ln.split()[-1] for ln in und.splitlines() if ln.strip()}
        want_undef = {"_calloc", "_free", "spAtlasAttachmentLoader_create",
                      "spAttachmentLoader_dispose"}
        if undef != want_undef:
            raise SystemExit("undefined set %s != %s" % (sorted(undef), sorted(want_undef)))
        print("deps unresolved by design:", " ".join(sorted(undef)))
        return 0
    finally:
        if args.keep:
            print("kept:", d)
            tmp_ctx.cleanup = lambda: None
        else:
            tmp_ctx.cleanup()


if __name__ == "__main__":
    sys.exit(main())
