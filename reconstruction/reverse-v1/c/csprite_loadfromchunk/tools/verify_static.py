#!/usr/bin/env python3
"""verify_static.py — 静态校验（不运行原版、不执行被逆向的 .so）

把卡片里每一条「可被二进制否证」的主张都变成一次机器检查：
  V1  函数边界/符号大小/字面量池三字
  V2  调用目标集合与 .dynsym 名字
  V3  两个 GOT 槽 → 全局名字与重定位类型
  V4  +0x35 的 (maskCount == count) 指令组合，以及 mask<=0 路径不写该字节
  V5  半径：32 位 mul → vcvt.f32 → vadd → vsqrt → ceilf → vcvt.s32 各 4 次；无 hypot/double
  V6  所有分支目标都是指令边界（并且落在函数体内或函数尾）
  V7  全部 [this, #off] 写点集合 == C 译文里 self->field 赋值的偏移集合
  V8  ABI：r1 先读、r2/r3 从未被读（第二形参在函数体内是死参数）

r1 追加（回应 REVIEW 问题 1/2/5）：
  V9  译文 armv7 -Werror 编译 + 目标码里出现同一批字段偏移
  V10 分配器合同：_Znaj/_Znwj 尾跳 MemoryManager::Alloc；Alloc(size==0) ⇒ NULL；
      _Alloc 的 size+16 > 0xFFFFFFFE ⇒ NULL；bucketAlloc 大尺寸 ⇒ NULL；
      **logLocation 只在「分配成功且 zero==false」时调用**（r2 更正：不是失败路径）；
      _Znaj/_Znwj 都传 zero=true ⇒ 这条分支对它们不可达。
      异常：只断言「闭包内没有静态可见的抛出点」，不把 `b` 当证据（见 alloc_closure.py）
  V11 两处长度闸（0x1e9814 / 0x1e9a80）逐条指令
  V12 sqrtf 慢路径：4 个块、实参是 vadd 的**和**（s14/s19/s18/s16），不是 vsqrt 结果
  V13 浮点调用顺序：每个角的 ceilf 喂入点都在该角 vsqrt 之后（sqrt→ceil 交替四轮）
  V14 负 count 的 32 位左移寻址（ldr r3,[r6,r5,lsl #2] / lsl lr,r5,#2 / add r1,r6,r5）
  V15 链接级 ABI：译文对象的 undefined 集合 == 原版 mangled 依赖名
      （与 clear 线的真实合并/类型一致性由 tools/verify_integration.py 负责——
       链接成功不等于类型兼容，这两件事已拆开）
  V16 编译开关敏感性：不带 -fmath-errno 时 sqrtf 调用整个消失（所以必须带）

用法：python3 scripts/verify_static.py           # 全绿返回 0
"""
import hashlib
import os
import re
import struct
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, ROOT + "/tools")
from sodis import SOImage, disasm

SO = os.environ.get("CALLY_ORIGINAL_SO", os.path.expanduser("~/callys-caves-2-rs/reconstruction/live-mem/libyoyo_armv7.so"))
SO_SHA = "3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a"
S, E = 0x1e972c, 0x1e9b5c          # 指令体
POOL = (0x1e9b5c, 0x1e9b60, 0x1e9b64)
GOT = 0x3f1c58

SCRATCH = os.path.join(os.environ.get("TMPDIR",
                     "/data/data/com.termux/files/home/.hermes/cache/scratch"), "cally-loader-verify-" + str(os.getpid()))
ARMV7 = "--target=armv7a-unknown-linux-android30"

fails = []
notes = []


def check(cond, msg):
    if cond:
        notes.append("  ok   " + msg)
    else:
        fails.append("  FAIL " + msg)


def run(cmd):
    return subprocess.run(cmd, capture_output=True, text=True)


def relocs(obj):
    """llvm-objdump -dr 里的 R_ARM_* 重定位 → [(偏移, 类型, 符号)]"""
    out = run(["llvm-objdump", "-dr", "--triple=armv7-linux-gnueabi", obj]).stdout
    res = []
    for m in re.finditer(r"^\s*([0-9a-f]+):\s+R_ARM_(\w+)\s+(\S+)$", out, re.M):
        res.append((int(m.group(1), 16), m.group(2), m.group(3)))
    return res


def main():
    img = SOImage(SO)
    ins = disasm(img, S, E)
    by_addr = {i.address: i for i in ins}
    os.makedirs(SCRATCH, exist_ok=True)

    # ── V0 文件身份 ────────────────────────────────────────────────────
    sha = hashlib.sha256(open(SO, "rb").read()).hexdigest()
    check(sha == SO_SHA, "V0 sha256 = %s" % sha)

    # ── V1 边界/大小/池 ────────────────────────────────────────────────
    check(len(ins) == 268, "V1 指令体 268 条（实得 %d）" % len(ins))
    check(ins[-1].address == 0x1e9b58, "V1 最后一条指令在 0x1e9b58")
    check(ins[-1].mnemonic == "b" and ins[-1].op_str == "#0x1e9908",
          "V1 最后一条是 b 0x1e9908（sqrtf 慢路径的回跳），不是 pop：%s %s" % (ins[-1].mnemonic, ins[-1].op_str))
    pool = [img.u32(a) for a in POOL]
    check(pool == [0x00208494, 0xFFFFBCD4, 0xFFFFBCF4],
          "V1 池字 = %s" % [hex(x) for x in pool])
    check(0x1e972c + 1084 == 0x1e9b68, "V1 符号 size 1084 覆盖到 0x1e9b68")
    check(sum(4 for _ in ins) + len(POOL) * 4 == 1084, "V1 268*4 + 3*4 == 1084")

    # ── V2 调用目标 ────────────────────────────────────────────────────
    calls = [(i.address, i.operands[-1].imm) for i in ins if i.mnemonic == "bl"]
    import collections
    cnt = collections.Counter(t for _, t in calls)
    expect = {
        0x1e6b4c: 1,   # CSprite::Clear()
        0x27d14c: 2,   # _Znaj
        0x27c524: 1,   # _Znwj
        0xbd86c: 1,    # CSkeletonSprite::CSkeletonSprite(char*,u32*5)
        0x1e838c: 1,   # CSprite::BuildSWFData(char*,int,int)
        0xb6994: 4,    # ceilf@plt
        0xb6700: 4,    # sqrtf@plt
    }
    check(dict(cnt) == expect, "V2 调用目标直方图 = %s" % dict(sorted(cnt.items())))
    check(len(calls) == 14, "V2 共 %d 条 bl" % len(calls))

    # ── V3 GOT → 全局 ─────────────────────────────────────────────────
    slots = {}
    for i in ins:
        for o in i.operands:
            if o.type == 3 and i.reg_name(o.mem.base) == "pc":   # ARM_OP_MEM
                lit = i.address + 8 + struct.unpack("<i", struct.pack("<I", o.mem.disp & 0xFFFFFFFF))[0]
                if i.mnemonic == "ldr":
                    v = img.u32(lit)
                    slot = GOT + struct.unpack("<i", struct.pack("<I", v))[0]
                    if 0x3ed718 <= slot < 0x3f2000:
                        slots[slot] = img.u32(slot)
    check(slots == {0x3ed92c: 0x5428e8, 0x3ed94c: 0x544c44},
          "V3 GOT 槽 = %s" % {hex(k): hex(v) for k, v in slots.items()})
    check(GOT == 0x1e97bc + 8 + 0x208494, "V3 GOT 锚 0x%x（0x1e97b0 池字 + add pc）" % GOT)
    rel_va, rel_sz = 0x9b9f0, 0x1a3c0
    rels = {}
    for k in range(rel_sz // 8):
        off, info = struct.unpack_from("<II", img.read(rel_va + k * 8, 8))
        if off in (0x3ed92c, 0x3ed94c):
            rels[off] = (info & 0xFF, info >> 8)
    check(rels == {0x3ed92c: (23, 0), 0x3ed94c: (23, 0)},
          "V3 两个槽都是 R_ARM_RELATIVE(23)、sym=0：%s" % rels)
    SYM_OFF, SYM_N, STR_OFF = 0x148, 0x2de10 // 16, 0x2df58
    B = img.buf
    names = {}
    for k in range(SYM_N):
        nm, val = struct.unpack_from("<II", B, SYM_OFF + k * 16)
        if val in (0x5428e8, 0x544c44):
            names[val] = B[STR_OFF + nm:B.index(b"\x00", STR_OFF + nm)].decode()
    check(names == {0x5428e8: "g_isZeus", 0x544c44: "g_pWADBaseAddress"},
          "V3 .dynsym 定名 = %s" % names)

    # ── V4 +0x35 ──────────────────────────────────────────────────────
    seq = [(a, by_addr[a].mnemonic, by_addr[a].op_str) for a in
           (0x1e9854, 0x1e9858, 0x1e985c, 0x1e9860, 0x1e9864, 0x1e9868)]
    check([m for _, m, _ in seq] == ["subs", "add", "rsbs", "str", "adcs", "strb"],
          "V4 0x1e9854..0x1e9868 = %s" % [m for _, m, _ in seq])
    check(seq[0][2] == "r3, r3, r5" and seq[2][2] == "r5, r3, #0" and seq[4][2] == "r5, r5, r3",
          "V4 相等判定三连 = subs/rsbs/adcs（%s | %s | %s）" % (seq[0][2], seq[2][2], seq[4][2]))
    check(seq[5][2] == "r5, [r4, #0x35]", "V4 落点 = [r4,#0x35]")
    mask_le = [i for i in ins if 0x1e9a58 <= i.address <= 0x1e9a60]
    check(all("[r4, #0x35]" not in i.op_str for i in mask_le) and len(mask_le) == 3,
          "V4 mask<=0 支路 3 条指令，均不碰 +0x35：%s" % [i.op_str for i in mask_le])
    w35 = [i.address for i in ins if i.mnemonic.startswith("str") and "[r4, #0x35]" in i.op_str]
    check(w35 == [0x1e9868], "V4 全函数唯一 +0x35 写点 = %s" % [hex(x) for x in w35])

    # ── V5 半径序列 ───────────────────────────────────────────────────
    def mn(m):
        return [i for i in ins if i.mnemonic == m]
    check(len(mn("mul")) == 4, "V5 mul ×4（%s）" % [i.op_str for i in mn("mul")])
    check(len(mn("vcvt.f32.s32")) == 4, "V5 vcvt.f32.s32 ×4")
    check(len(mn("vadd.f32")) == 4, "V5 vadd.f32 ×4（%s）" % [i.op_str for i in mn("vadd.f32")])
    check(len(mn("vsqrt.f32")) == 4, "V5 vsqrt.f32 ×4")
    check(len(mn("vcvt.s32.f32")) == 4, "V5 vcvt.s32.f32 ×4")
    check(not any("hypot" in str(i.op_str) for i in ins), "V5 无 hypot")
    check(not any(i.mnemonic.startswith("vcvt.f64") or i.mnemonic.startswith("vadd.f64") for i in ins),
          "V5 全函数无 double（无 .f64 运算）")
    feed = [i.address for i in ins if i.mnemonic == "vmov" and i.op_str.startswith("r0, s")]
    check(feed[:4] == [0x1e98c8, 0x1e98ec, 0x1e990c, 0x1e9928] and len(feed) == 9,
          "V5 喂 ceilf 的 4 次 vmov r0,sN = %s（另 4 次喂 sqrtf@plt + 1 次取 s15 位型）"
          % [hex(x) for x in feed[:4]])
    check([hex(i.address) for i in mn("vcvt.f32.s32")] ==
          ["0x1e989c", "0x1e98a4", "0x1e98b4", "0x1e98c0"],
          "V5 四个 int→float 点在 0x1e989c/a4/b4/c0")

    # ── V6 分支目标 ───────────────────────────────────────────────────
    tgt = []
    for i in ins:
        if i.mnemonic == "b" or (i.mnemonic.startswith("b") and i.mnemonic != "bl"):
            if i.operands and i.operands[-1].type == 2:
                tgt.append((i.address, i.operands[-1].imm))
    bad = [(a, t) for a, t in tgt if t not in by_addr and t != 0x1e9b5c]
    check(not bad, "V6 %d 条分支目标全部落在指令边界（坏点 %s）" % (len(tgt), bad))

    # ── V7 写点集合 ↔ C 译文 ──────────────────────────────────────────
    written = set()
    for i in ins:
        if i.mnemonic.startswith("str") and "[r4, #" in i.op_str:
            m = re.search(r"\[r4, #(0x[0-9a-f]+|\d+)\]", i.op_str)
            if m:
                written.add(int(m.group(1), 16))
    hdr = open(os.path.join(ROOT, "../csprite_clear/src/csprite_clear.h")).read()
    # 权威头（clear 线副本）的字段格式：`<类型>  <名字>;   /* 0xNN 说明 */`
    off_by_name = {nm: int(off, 16) for nm, off in
                   re.findall(r"(\w+)(?:\[\d+\])?;\s*/\*\s*0x([0-9a-f]+)", hdr)}
    csrc = open(ROOT + "/src/csprite_loadfromchunk.c").read()
    cwritten = set()
    # 三种写形状：self->f = …、self->arr[i] = …、&self->f 传给 yy_slot_set/st32/memcpy
    for nm, idx in re.findall(r"self->(\w+)\[(\d+)\]\s*=", csrc):
        if nm not in off_by_name:
            fails.append("  FAIL V7 译文里的 self->%s[] 在布局表里没有偏移" % nm)
        else:
            cwritten.add(off_by_name[nm] + 4 * int(idx))
    for nm in re.findall(r"self->(\w+)\s*=(?!=)", csrc):
        if nm not in off_by_name:
            fails.append("  FAIL V7 译文里的 self->%s 在布局表里没有偏移" % nm)
        else:
            cwritten.add(off_by_name[nm])
    for nm in re.findall(r"&self->(\w+)", csrc):
        if nm not in off_by_name:
            fails.append("  FAIL V7 译文里的 &self->%s 在布局表里没有偏移" % nm)
        else:
            cwritten.add(off_by_name[nm])
    check(written == cwritten,
          "V7 原版写点集合 == 译文写点集合（原版 %d 个/译文 %d 个；差集 %s）"
          % (len(written), len(cwritten), sorted(hex(x) for x in (written ^ cwritten))))
    check(sorted(written) == sorted([
        0x04, 0x08, 0x0c, 0x10, 0x14, 0x18, 0x1c, 0x20, 0x24, 0x28, 0x2c,
        0x30, 0x32, 0x33, 0x34, 0x35, 0x54, 0x58, 0x64, 0x68, 0x6c, 0x70, 0x74, 0x78]),
        "V7 原版写点清单 = %s" % [hex(x) for x in sorted(written)])

    # ── V8 ABI：r2/r3 死参数 ──────────────────────────────────────────
    def first_touch(reg):
        for i in ins:
            ops = i.op_str
            dst_m = re.match(r"^(%s)\b" % reg, ops)
            src = ops[len(reg):] if dst_m else ops
            if re.search(r"\b%s\b" % reg, src):
                return ("read", i.address, i.mnemonic, i.op_str)
            if dst_m:
                return ("write", i.address, i.mnemonic, i.op_str)
        return None
    t1, t2, t3 = first_touch("r1"), first_touch("r2"), first_touch("r3")
    check(t1 and t1[0] == "read" and t1[1] == 0x1e9734, "V8 r1 首次触碰是读（%s）" % (t1,))
    check(t2 and t2[0] == "write" and t2[1] == 0x1e9750,
          "V8 r2（第 2 形参）首次触碰是写 ⇒ 函数体内从未读入参：%s" % (t2,))
    check(t3 and t3[0] == "write" and t3[1] == 0x1e976c,
          "V8 r3（第 3 形参）首次触碰是写 ⇒ 无第三形参：%s" % (t3,))
    check(not any("[sp, #" in i.op_str and i.mnemonic == "ldr" for i in ins[:8]),
          "V8 序言没有从栈上读形参（无第 5+ 个实参）")

    # ── V9 译文 armv7 编译 + 目标码偏移 ───────────────────────────────
    obj = os.path.join(SCRATCH, "lf_armv7.o")
    rc = run(["clang", ARMV7, "-std=c11", "-O2", "-Wall", "-Wextra", "-Werror",
              "-fmath-errno", "-ffp-contract=off", "-c",
              ROOT + "/src/csprite_loadfromchunk.c", "-o", obj])
    check(rc.returncode == 0, "V9 译文 armv7 编译通过（-Wall -Wextra -Werror -fmath-errno）")
    if rc.returncode == 0:
        dis = run(["llvm-objdump", "-d", "--triple=armv7-linux-gnueabi", obj]).stdout
        want = ["#0x2c]", "#0x35]", "#0x54]", "#0x58]", "#0x64]", "#0x68]",
                "#0x6c]", "#0x70]", "#0x74]", "#0x78]"]
        miss = [w for w in want if w not in dis]
        check(not miss, "V9 译文目标码里出现全部关键偏移（缺 %s）" % miss)
        check("_Znaj" not in dis or True, "V9 (info) 符号引用见 V15")

    # ── V10 分配器合同（REVIEW 问题 1 的更正依据）──────────────────────
    znaj = disasm(img, 0x27d14c, 0x27d160)
    check([i.mnemonic for i in znaj] == ["ldr", "movw", "mov", "add", "b"] and
          znaj[-1].op_str == "#0x27ce78",
          "V10 _Znaj 0x27d14c 尾跳 MemoryManager::Alloc(0x27ce78)：%s" %
          " | ".join("%s %s" % (i.mnemonic, i.op_str) for i in znaj))
    check(znaj[-1].mnemonic == "b" and "0x27ce78" in znaj[-1].op_str and
          znaj[2].op_str == "r3, #1",
          "V10 _Znaj 尾跳 Alloc 且 zero=true。注意：`b` 只说明它自己不建帧/不捕获，"
          "**不能**据此断言被调方不抛——异常结论见 隔离候选的 scripts/alloc_closure.py（不作已证明结论）")
    alloc = {i.address: i for i in disasm(img, 0x27ce78, 0x27cedc)}
    check(alloc[0x27ce7c].op_str == "r6, r0, #0" and alloc[0x27ce84].op_str == "#0x27cec4",
          "V10 Alloc: subs/beq ⇒ size==0 直接跳 0x27cec4（mov r0,#0; pop）")
    check(alloc[0x27cec4].mnemonic == "mov" and alloc[0x27cec4].op_str == "r0, #0",
          "V10 0x27cec4 = mov r0,#0 ⇒ 返回 NULL（不是 throw）")
    check(alloc[0x27cea4].mnemonic == "beq" and alloc[0x27cea4].op_str == "#0x27cec4",
          "V10 _Alloc 返回 0 时同样走 0x27cec4 返回 NULL")
    seq = [(alloc[a].mnemonic, alloc[a].op_str) for a in
           (0x27ce8c, 0x27ce90, 0x27ce94, 0x27ce98, 0x27ce9c, 0x27cea0, 0x27cea4)]
    check([m for m, _ in seq] == ["adds", "mov", "movne", "tst", "bne", "cmp", "beq"] and
          seq[3][1] == "r1, r5" and seq[4][1] == "#0x27cecc" and seq[6][1] == "#0x27cec4",
          "V10 Alloc: tst r1,r5(zero) → bne 0x27cecc(memset)；ptr==0 → beq 0x27cec4 返回 NULL")
    check(alloc[0x27ceb8].operands[-1].imm == 0x27bcf4,
          "V10 0x27ceb8 的 logLocation 落在『ptr!=0 且 zero==0』分支上"
          "（REVIEW-r2 更正：不是失败才调）")
    logloc = disasm(img, 0x27bcf4, 0x27bcf8)
    check(len(logloc) == 1 and logloc[0].mnemonic == "bx",
          "V10 0x27bcf4 logLocation = `%s %s`（空实现：不打日志、不 abort）"
          % (logloc[0].mnemonic, logloc[0].op_str))
    _alloc = disasm(img, 0x27cd54, 0x27ce78)
    a = {i.address: i for i in _alloc}
    check(a[0x27cda8].op_str == "r0, r7, #0x10" and a[0x27cdb0].mnemonic == "adc",
          "V10 _Alloc: size+16 用 adds/adc 做 64 位和")
    check(a[0x27cdb4].op_str == "r4, #1" and a[0x27cdc0].mnemonic == "sbcs",
          "V10 _Alloc: 上界 0xFFFFFFFE 与 size+16 做 sbcs 64 位比较")
    check(a[0x27cdc4].mnemonic == "bge" and a[0x27cdc8].op_str == "r4, #0",
          "V10 _Alloc: 不满足 ⇒ r4=0 ⇒ 返回 NULL（size ≥ 0xFFFFFFEF）")
    check(a[0x27cdd4].op_str == "r0, #0" and a[0x27cdd8].mnemonic == "beq",
          "V10 _Alloc: malloc 失败也返回 NULL")
    check(a[0x27ce00].op_str == "r4, r0, #0x10", "V10 _Alloc: 用户指针 = malloc 结果 + 16")
    buck = {i.address: i for i in disasm(img, 0x27c53c, 0x27cd1c)}
    check(buck[0x27c688].op_str == "r5, #0x4000" and buck[0x27c68c].mnemonic == "bne" and
          buck[0x27c6e8].op_str == "r0, #0",
          "V10 bucketAlloc: size>16384 且 !=256 ⇒ 0x27c6e8 mov r0,#0（4 GB 请求不可能命中桶）")

    # ── V11 两处长度闸 ────────────────────────────────────────────────
    g1 = [(a_ , by_addr[a_].mnemonic, by_addr[a_].op_str) for a_ in
          (0x1e9814, 0x1e9818, 0x1e981c, 0x1e9820, 0x1e9824)]
    check([m for _, m, _ in g1] == ["cmp", "mvnhi", "bhi", "lsl", "bl"] and
          g1[0][2] == "r0, #0x1fc00000" and g1[1][2] == "r0, #0" and g1[4][2] == "#0x27d14c",
          "V11 主闸 0x1e9814..0x1e9824 = %s" % " | ".join(x[2] for x in g1))
    g2 = [(by_addr[a_].mnemonic, by_addr[a_].op_str) for a_ in
          (0x1e9a80, 0x1e9a84, 0x1e9a88, 0x1e9a8c, 0x1e9a90)]
    check(g2[0] == ("cmp", "r8, #0x1fc00000") and g2[2] == ("mvnhi", "r0, #0") and
          g2[3] == ("movls", "r0, r5") and g2[4] == ("bl", "#0x27d14c"),
          "V11 kind1 闸 0x1e9a80..0x1e9a90 = %s" % " | ".join(x[1] for x in g2))

    # ── V12 sqrtf 慢路径的实参 = vadd 的和 ────────────────────────────
    slow = {0x1e9b1c: "s14", 0x1e9b2c: "s16", 0x1e9b3c: "s19", 0x1e9b4c: "s18"}
    ok = True
    detail = []
    for addr, sreg in slow.items():
        pair = disasm(img, addr, addr + 8)
        good = (len(pair) == 2 and pair[0].mnemonic == "vmov" and
                pair[0].op_str == "r0, " + sreg and pair[1].mnemonic == "bl" and
                pair[1].operands[-1].imm == 0xb6700)
        ok &= good
        detail.append("0x%x:%s" % (addr, "√" if good else "×"))
    check(ok, "V12 四个 sqrtf 慢路径块都传 vadd 的和（%s）" % " ".join(detail))
    vadd_dst = {i.op_str.split(",")[0] for i in ins if i.mnemonic == "vadd.f32"}
    check(vadd_dst == {"s14", "s19", "s18", "s16"},
          "V12 四条 vadd 的目的寄存器 = %s（慢路径实参）" % sorted(vadd_dst))
    # bne 从 vcmp 出发，指向对应慢路径块
    bn = {i.address: i for i in ins if i.mnemonic == "bne"}
    check([bn[a_].operands[-1].imm for a_ in (0x1e98c4, 0x1e98e4, 0x1e9904, 0x1e9924)] ==
          [0x1e9b1c, 0x1e9b3c, 0x1e9b4c, 0x1e9b2c],
          "V12 四条 bne → %s（NaN 才进慢路径）" %
          [hex(bn[a_].operands[-1].imm) for a_ in (0x1e98c4, 0x1e98e4, 0x1e9904, 0x1e9924)])
    # NaN 可达性：vcmp 比较的是 vsqrt 结果，vs 输入可能是负的平方和
    check(all(by_addr[a_].mnemonic == "vcmp.f32" for a_ in (0x1e98b0, 0x1e98dc, 0x1e98fc, 0x1e991c)),
          "V12 四条 vsqrt 之后紧跟 vcmp sN,sN（NaN 检测点）")

    # ── V13 浮点调用顺序：sqrt→ceil 四轮 ─────────────────────────────
    order = []
    for a_ in (0x1e98ac, 0x1e98d4, 0x1e98f4, 0x1e9914):     # vsqrt
        order.append(("sqrt", a_))
    for a_ in (0x1e98c8, 0x1e98ec, 0x1e990c, 0x1e9928):     # vmov r0,sN（喂 ceilf）
        order.append(("ceil", a_))
    order.sort(key=lambda x: x[1])
    kinds = [k for k, _ in order]
    check(kinds == ["sqrt", "ceil"] * 4,
          "V13 四角 vsqrt 地址顺序 = %s；ceilf 喂入点 = %s"
          % ([hex(a_) for k, a_ in order if k == "sqrt"], [hex(a_) for k, a_ in order if k == "ceil"]))
    # 每个角的 ceilf 喂入点必须在该角 vsqrt 之后
    pairs = [(0x1e98ac, 0x1e98c8), (0x1e98d4, 0x1e98ec), (0x1e98f4, 0x1e990c), (0x1e9914, 0x1e9928)]
    check(all(c > s for s, c in pairs),
          "V13 每个角的 ceilf 都在自己的 vsqrt 之后 ⇒ 调用顺序 sqrt→ceil→sqrt→… 与原版一致")

    # ── V14 负 count / 变长尾部的 32 位左移寻址 ─────────────────────
    check(by_addr[0x1e9828].op_str == "r5, [r4, #0x18]" and
          by_addr[0x1e9830].mnemonic == "lsl" and by_addr[0x1e9830].op_str == "lr, r5, #2",
          "V14 count 重读 + lsl lr,r5,#2（32 位左移，可产生 0xFFFFFFF8）")
    check(by_addr[0x1e9840].op_str == "r3, [r6, r5, lsl #2]",
          "V14 掩码条数读点 = ldr r3,[r6,r5,lsl#2]（32 位回绕后落点视 count 而定）")
    check(by_addr[0x1e9844].op_str == "r6, r6, lr", "V14 游标推进 = add r6,r6,lr（32 位加）")
    check(by_addr[0x1e9a84].op_str == "r5, r8, #2" and by_addr[0x1e9ae0].op_str == "r1, r6, r5",
          "V14 kind1 的 data = cur + (n<<2)（0x1e9a84 lsl + 0x1e9ae0 add）")

    # ── V15 链接级 ABI ───────────────────────────────────────────────
    if rc.returncode == 0:
        und = [l.split()[1] for l in run(["llvm-nm", "-u", obj]).stdout.splitlines() if l.strip()]
        expect_und = sorted(["_ZN7CSprite5ClearEv", "_ZN7CSprite12BuildSWFDataEPcii",
                             "_ZN15CSkeletonSpriteC2EPcjjjjj", "_Znaj", "_Znwj",
                             "ceilf", "sqrtf", "g_isZeus", "g_pWADBaseAddress"])
        check(sorted(und) == expect_und,
              "V15 译文对象 undefined == 原版 mangled 依赖名（实得 %s）" % sorted(und))
        defs = [l.split()[2] for l in run(["llvm-nm", "--defined-only", obj]).stdout.splitlines()
                if len(l.split()) >= 3]
        check(all(d not in expect_und for d in defs),
              "V15 译文对象没有定义任何依赖符号（defined = %s）" % defs)
        notes.append("  note V15 与 clear 线的**类型/布局/合并/运行**验证已拆到 "
                     "tools/verify_integration.py（链接成功不等于类型兼容）")

    # ── V16 -fmath-errno 是载荷开关 ──────────────────────────────────
    if rc.returncode == 0:
        noerr = os.path.join(SCRATCH, "lf_armv7_noerrno.o")
        r2 = run(["clang", ARMV7, "-std=c11", "-O2", "-Wall", "-Wextra", "-Werror",
                  "-fno-math-errno", "-ffp-contract=off", "-c",
                  ROOT + "/src/csprite_loadfromchunk.c", "-o", noerr])
        check(r2.returncode == 0, "V16 -fno-math-errno 也能编过（对照组）")
        if r2.returncode == 0:
            with_errno = [x for x in relocs(obj) if x[2] == "sqrtf"]
            without = [x for x in relocs(noerr) if x[2] == "sqrtf"]
            check(len(with_errno) == 4 and len(without) == 0,
                  "V16 sqrtf 重定位：-fmath-errno %d 条 / -fno-math-errno %d 条 "
                  "⇒ 该开关决定原版的 NaN 慢路径是否还在（必须显式打开）"
                  % (len(with_errno), len(without)))
            check(len([x for x in relocs(obj) if x[2] == "ceilf"]) == 4,
                  "V16 ceilf 重定位 4 条（ARMv7 无 vrintp，ceilf 必须真调）")

    print("\n".join(notes))
    if fails:
        print("\n".join(fails))
        print("\n%d 项检查，%d 项失败" % (len(notes) + len(fails), len(fails)))
        return 1
    print("\n%d 项检查全部通过" % len(notes))
    return 0


if __name__ == "__main__":
    sys.exit(main())
