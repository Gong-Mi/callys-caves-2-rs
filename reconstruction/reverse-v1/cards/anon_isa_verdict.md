# 14 段匿名区的 ISA 判定：用调用点编码反推（不靠被调方长相）

对象：`~/cally-oracle/libyoyo.so`（ELF32 ARM，armeabi-v7a，stripped，4,689,844 B，
`.text` 0xb6fd0..0x31bb7c，sha256 `3bbedd09…6bc0fbe3a`）。
输入清单：`cards/anon_batch5.c` 的「排除 A（Thumb-2，14 段）」。

## 0. 结论

**14 段全部是 Thumb-2。** 没有任何一段有 ARM 侧的直接调用证据（全 `.text` 内 0 条 ARM `bl`/`blx` 指向它们），
而每一段都有 2~51 条 Thumb-2 `bl` 指向它，且条数与 `anon_batch5.c` 记的 in-degree 逐字相同。

| # | 段起始 | 段长 | 锚点 | in-deg = Thumb `bl` 数 | ARM `bl`/`blx` | 反向证据（调用者） | 正向（段内 bl 到具名 Thumb） | 结论 | 置信度 |
|---|--------|------|------|------------------------|----------------|--------------------|------------------------------|------|--------|
| 1 | `0x2f8e0a` | 1,170 B | 455 | **51** | **0** | TT_RunIns×9 / anon_2fec70 区×22 / anon_2f1de8 区×13 / anon_300274 区×6 / anon_b6fd0 区×1 | 0 | Thumb-2 | 证明级 |
| 2 | `0x317798` | 684 B | 281 | **7** | **0** | __cxa_call_unexpected×5 / anon_317210 区×1 / anon_3180e8 区×1 | 2 | Thumb-2 | 证明级 |
| 3 | `0x2e8c38` | 1,180 B | 483 | **4** | **0** | FT_New_Face×1 / FT_New_Memory_Face×1 / FT_Open_Face×1 / anon_2e90fc 区×1 | 16 | Thumb-2 | 证明级 |
| 4 | `0x2fa06c` | 708 B | 271 | **3** | **0** | TT_New_Context×1 / anon_2f1de8 区×1 / anon_300274 区×1 | 32 | Thumb-2 | 证明级 |
| 5 | `0x2fb894` | 3,156 B | 1211 | **3** | **0** | TT_RunIns×3 | 51 | Thumb-2 | 证明级 |
| 6 | `0x2e90fc` | 666 B | 280 | **3** | **0** | anon_2e90fc 父区×3（0x2e9322 在窗口内、落在第 2 个 bl 入口 0x2e91a4 体内；0x2e958a / 0x2e96ac 在窗口外） | 20 | Thumb-2 | 证明级 |
| 7 | `0x2fb68c` | 518 B | 182 | **3** | **0** | TT_RunIns×3 | 1 | Thumb-2 | 证明级 |
| 8 | `0x317ba8` | 692 B | 279 | **3** | **0** | __gxx_personality_v0×3 | 0 | Thumb-2 | 证明级 |
| 9 | `0x2fec70` | 5,012 B | 1832 | **2** | **0** | anon_2fec70 自递归×2（本段内 0x2ffaac / 0x3001d0） | 43 | Thumb-2 | 证明级 |
| 10 | `0x309b08` | 2,996 B | 1143 | **2** | **0** | anon_309b08 自递归×2（本段内 0x309e50 / 0x30a3e4） | 27 | Thumb-2 | 证明级 |
| 11 | `0x2f0444` | 1,154 B | 445 | **2** | **0** | ps_hints_apply×2 | 3 | Thumb-2 | 证明级 |
| 12 | `0x2f9ab6` | 1,112 B | 424 | **2** | **0** | TT_RunIns×2 | 11 | Thumb-2 | 证明级 |
| 13 | `0x2f08c6` | 1,110 B | 410 | **2** | **0** | ps_hints_apply×2 | 8 | Thumb-2 | 证明级 |
| 14 | `0x2f1142` | 700 B | 275 | **2** | **0** | ps_hints_apply×1 / anon_2e9c78 区×1 | 0 | Thumb-2 | 证明级 |

「置信度」只分两档：`证明级` = 有 ≥1 条已复核到指令边界的同族 `bl`（单向即可，双向更硬）；
`推断` = 只有解码旁证。本表 14 行全是前者。

## 1. 为什么旧结论停在 open

`claims.jsonl` 里两条负结果的口径都是**看被调方长相**：

- ISA-004：拿「ARM 解码里 svc/undefined/.word 的比例」当信号，只在 37 个区间成立；这 14 段在 ARM 视图下
  解出 `andlo` / `rscvc` / `andmi` 之类，看起来不算离谱，于是判不了。
- ISA-005：`0x2f8e0a` 的 ARM 视图是乱跳、Thumb 视图是 `smull/asr.w/add.w/adds+adc`，两种都自洽，于是判不了。

这两条在各自口径下都没错。问题是**解码外观本来就不是 ISA 的判定依据** —— 同一串字节在两种解码下都
可能「像话」。ISA 是**调用约定**的一部分，证据应该来自调用点。

## 2. 判据：编码域 + 状态保持

| 指令 | 编码 | 目标 |
|------|------|------|
| ARM `bl` | `cond=1110,1011,imm24` → 首字节 `0xEB` | `pc+8+(imm24<<2)`，**必为 4 的倍数** |
| ARM `blx` imm | `1111 101H imm24` → `0xFA`/`0xFB` | `pc+8+SignExtend(imm24:H:00)`，H 在 bit24，可落 2 的倍数 |
| Thumb `bl` | 32 位 `11110 S imm10` + `11 J1 1 J2 imm11` | 首半字 `0xF000..0xF7FF`，次半字 `0xD800..0xDFFF`/`0xF800..0xFFFF` |
| Thumb `blx` imm | 次半字 `11 J1 0 J2 imm11` | `0xC800..0xCFFF`/`0xE800..0xEFFF` |

三条推论：

1. **状态保持**：Thumb 的 `bl` 只能进 Thumb 代码；ARM 的 `bl` 只能进 ARM 代码。跨态必须用 `blx`。
2. 所以「一条位于指令边界上的 Thumb `bl T`」⇒ **T 是 Thumb**，与被调方字节长什么样无关。
3. 反向也成立：段内有一条 `bl` 打到具名 Thumb 函数 ⇒ **本段是 Thumb 代码**（调用者状态已知）。

## 3. 扫描与计数

对 14 个起始地址各扫一遍全 `.text`（2,509,740 B）：

- 4 B 栅格匹配 `0xEB`/`0xFA`/`0xFB` 三种 ARM 形态（`blx` 的 H 位在 bit24，按 `imm24:H:00` 正确还原）→ 14 段**全 0**。
- 2 B 栅格匹配 Thumb `bl` 形态（`F0xx` 首半字 + `0xD8..0xDF`/`0xF8..0xFF` 次半字，按 `S:I1:I2:imm10:imm11:0` 还原，
  `I1=!(J1^S)`、`I2=!(J2^S)`）→ 命中数正好 51/7/4/3/3/3/3/3/2/2/2/2/2/2。

这组数字与 `anon_batch5.c`「排除 A」记的 in-degree **逐字相同**，而那份 in-degree 出自另一套流程 ——
两条独立路径给出同一组计数，说明扫描既没漏也没多。

## 4. 逐点复核：89/89 落在指令边界上

光有半字匹配还不够：`F0xx F8xx` 也可能只是两个恰好相邻的半字。所以对 89 个命中点逐个解**调用者所在函数**
（`llvm-objdump --triple=thumbv7`，范围取该函数的 census 边界），确认命中地址上确实是一条 `bl T`：

**89 处命中，89 处成立**（0 处「地址不在指令边界上」）。

## 5. 校准：同一套扫描器跑已知答案

拿符号表当答案（奇数 `st_value` = Thumb，偶数 = ARM），各取 60 个 ≥24 B 的函数：

| 样本 | Thumb `bl` 命中 | ARM `bl` 命中 | 无直接调用 |
|------|-----------------|---------------|------------|
| 60 个 ARM 符号（偶数 `st_value`） | 0 | 19 | 41（叶函数或纯间接） |
| 60 个 Thumb 符号（奇数 `st_value`） | 37 | 4 | 19 |

全库统计：4,452 个 Thumb 目标里 85 个同时出现在 ARM 目标集 —— 跨族碰撞率 **1.9%**。

这解释了 ISA-004 为什么会被骗：**单条**命中确实有 2~7% 的假阳率。但本批的形态不是单条：每段 2..51 条命中
**全是同族**、异族 0 条。按 1.9% 的独立碰撞率，2 条的那几段全错概率约 3.6e-4，51 条那段约 1e-87。

## 6. 逐段证据

> 口径：这里的「正向」只数 `bl` 目标**正好等于**某个具名符号起始地址的条数；目标落在具名符号内部的情况
> （例如 `0x317ba8` 打到 `__cxa_call_unexpected+0x108`）不计入，所以「正向 0 条」不等于「没有具名被调」，
> 只说明正向量在符号表上取不到值 —— 那种段的判决完全靠反向。

### §1 `0x2f8e0a` — 1,170 B，in-degree 51 → **Thumb-2**（证明级）

| 调用点 | 4 字节编码 | 解出 | 所在函数（ISA） |
|--------|-----------|------|-----------------|
| `0xb8888` | `40f2bffa` | `bl 0x2f8e0a` | anon_b6fd0（匿名区·Thumb 带） |
| `0x2f982e` | `fff7ecfa` | `bl 0x2f8e0a` | anon_2f1de8（匿名区·Thumb 带） |
| `0x2f9836` | `fff7e8fa` | `bl 0x2f8e0a` | anon_2f1de8（匿名区·Thumb 带） |

- 反向：**51 条** Thumb `bl`，ARM `bl`/`blx` **0 条**。分布：TT_RunIns×9 / anon_2fec70 区×22 / anon_2f1de8 区×13 / anon_300274 区×6 / anon_b6fd0 区×1
- 正向：段内 **0 条** `bl` 指向具名 Thumb 符号的**入口**（无 —— 入口是纯叶，体内没有 bl），指向具名 ARM 符号 0 条。
- 入口：`smull r3, r2, r1, r0`；窗口内出口 45 个。归属判断：FreeType 定点算术叶例程（(a*b+0x8000)>>16 形态）+ 3 个邻接函数 + 107 B 可打印串

### §2 `0x317798` — 684 B，in-degree 7 → **Thumb-2**（证明级）

| 调用点 | 4 字节编码 | 解出 | 所在函数（ISA） |
|--------|-----------|------|-----------------|
| `0x317680` | `00f08af8` | `bl 0x317798` | anon_317210（匿名区·Thumb 带） |
| `0x3181e6` | `fff7d7fa` | `bl 0x317798` | anon_3180e8（匿名区·Thumb 带） |
| `0x318764` | `fff718f8` | `bl 0x317798` | __cxa_call_unexpected（Thumb） |

- 反向：**7 条** Thumb `bl`，ARM `bl`/`blx` **0 条**。分布：__cxa_call_unexpected×5 / anon_317210 区×1 / anon_3180e8 区×1
- 正向：段内 **2 条** `bl` 指向具名 Thumb 符号的**入口**（__cxa_call_unexpected、__cxa_end_cleanup），指向具名 ARM 符号 0 条。
- 入口：`push {r3, r4, r5, lr}`；窗口内出口 15 个。归属判断：C++ 展开/cleanup 运行时（libsupc++），夹在 libpng LZW 与 __gxx_personality_v0 之间

### §3 `0x2e8c38` — 1,180 B，in-degree 4 → **Thumb-2**（证明级）

| 调用点 | 4 字节编码 | 解出 | 所在函数（ISA） |
|--------|-----------|------|-----------------|
| `0x2e90ee` | `fff7a3fd` | `bl 0x2e8c38` | FT_New_Face（Thumb） |
| `0x2e9170` | `fff762fd` | `bl 0x2e8c38` | anon_2e90fc（匿名区·Thumb 带） |
| `0x2e970a` | `fff795fa` | `bl 0x2e8c38` | FT_New_Memory_Face（Thumb） |

- 反向：**4 条** Thumb `bl`，ARM `bl`/`blx` **0 条**。分布：FT_New_Face×1 / FT_New_Memory_Face×1 / FT_Open_Face×1 / anon_2e90fc 区×1
- 正向：段内 **16 条** `bl` 指向具名 Thumb 符号的**入口**（FT_Done_Face、FT_List_Add、FT_New_GlyphSlot、FT_New_Size、FT_Raccess_Guess、FT_Stream_Free 等 11 个符号），指向具名 ARM 符号 0 条。
- 入口：`push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}`；窗口内出口 1 个。归属判断：FreeType ftobjs.c 的 open_face（narrowed）—— 本批唯一 100% 单函数段

### §4 `0x2fa06c` — 708 B，in-degree 3 → **Thumb-2**（证明级）

| 调用点 | 4 字节编码 | 解出 | 所在函数（ISA） |
|--------|-----------|------|-----------------|
| `0x2fa116` | `fff7a9ff` | `bl 0x2fa06c` | anon_2f1de8（匿名区·Thumb 带） |
| `0x300262` | `f9f703ff` | `bl 0x2fa06c` | TT_New_Context（Thumb） |
| `0x3002d2` | `f9f7cbfe` | `bl 0x2fa06c` | anon_300274（匿名区·Thumb 带） |

- 反向：**3 条** Thumb `bl`，ARM `bl`/`blx` **0 条**。分布：TT_New_Context×1 / anon_2f1de8 区×1 / anon_300274 区×1
- 正向：段内 **32 条** `bl` 指向具名 Thumb 符号的**入口**（ft_mem_free），指向具名 ARM 符号 0 条。
- 入口：`push {r4, r5, r6, lr}`；窗口内出口 4 个。归属判断：TrueType 解释器带的 6 个小函数（708 B / 6 个 bl 入口）

### §5 `0x2fb894` — 3,156 B，in-degree 3 → **Thumb-2**（证明级）

| 调用点 | 4 字节编码 | 解出 | 所在函数（ISA） |
|--------|-----------|------|-----------------|
| `0x2fd9ac` | `fdf772ff` | `bl 0x2fb894` | TT_RunIns（Thumb） |
| `0x2fda06` | `fdf745ff` | `bl 0x2fb894` | TT_RunIns（Thumb） |
| `0x2fda1e` | `fdf739ff` | `bl 0x2fb894` | TT_RunIns（Thumb） |

- 反向：**3 条** Thumb `bl`，ARM `bl`/`blx` **0 条**。分布：TT_RunIns×3
- 正向：段内 **51 条** `bl` 指向具名 Thumb 符号的**入口**（FT_DivFix、FT_MulDiv、FT_Stream_EnterFrame、FT_Stream_ExitFrame、FT_Stream_GetULong、FT_Stream_GetUShort 等 14 个符号），指向具名 ARM 符号 0 条。
- 入口：`push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}`；窗口内出口 3 个。归属判断：TrueType 解释器带的大块（3,156 B / 5 个 bl 入口 / 1,211 条）

### §6 `0x2e90fc` — 666 B，in-degree 3 → **Thumb-2**（证明级）

| 调用点 | 4 字节编码 | 解出 | 所在函数（ISA） |
|--------|-----------|------|-----------------|
| `0x2e9322` | `fff7ebfe` | `bl 0x2e90fc` | anon_2e90fc（匿名区·Thumb 带） |
| `0x2e958a` | `fff7b7fd` | `bl 0x2e90fc` | anon_2e90fc（匿名区·Thumb 带） |
| `0x2e96ac` | `fff726fd` | `bl 0x2e90fc` | anon_2e90fc（匿名区·Thumb 带） |

- 反向：**3 条** Thumb `bl`，ARM `bl`/`blx` **0 条**。分布：anon_2e90fc 父区×3（0x2e9322 在窗口内、落在第 2 个 bl 入口 0x2e91a4 体内；0x2e958a / 0x2e96ac 在窗口外）
- 正向：段内 **20 条** `bl` 指向具名 Thumb 符号的**入口**（FT_Get_Module、FT_Raccess_Get_HeaderInfo、FT_Stream_Close、FT_Stream_OpenMemory、FT_Stream_Pos、FT_Stream_Read 等 12 个符号），指向具名 ARM 符号 0 条。
- 入口：`push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}`；窗口内出口 2 个。归属判断：FreeType ftobjs.c 的 open_face 下家（666 B / 3 个 bl 入口）
- 特殊：本段没有具名调用者（反向命中全落在父区内部，属自递归），靠**正向**立住 —— 段内 `bl` 打在
  已知具名 Thumb 函数上，调用者状态已知，故本段必为 Thumb。

### §7 `0x2fb68c` — 518 B，in-degree 3 → **Thumb-2**（证明级）

| 调用点 | 4 字节编码 | 解出 | 所在函数（ISA） |
|--------|-----------|------|-----------------|
| `0x2fd616` | `fef739f8` | `bl 0x2fb68c` | TT_RunIns（Thumb） |
| `0x2fe536` | `fdf7a9f8` | `bl 0x2fb68c` | TT_RunIns（Thumb） |
| `0x2fe548` | `fdf7a0f8` | `bl 0x2fb68c` | TT_RunIns（Thumb） |

- 反向：**3 条** Thumb `bl`，ARM `bl`/`blx` **0 条**。分布：TT_RunIns×3
- 正向：段内 **1 条** `bl` 指向具名 Thumb 符号的**入口**（FT_DivFix），指向具名 ARM 符号 0 条。
- 入口：`ldr r3, [r1]`；窗口内出口 3 个。归属判断：TrueType 解释器带的小件（518 B 窗口 / 3 个 bl 入口）

### §8 `0x317ba8` — 692 B，in-degree 3 → **Thumb-2**（证明级）

| 调用点 | 4 字节编码 | 解出 | 所在函数（ISA） |
|--------|-----------|------|-----------------|
| `0x31802c` | `fff7bcfd` | `bl 0x317ba8` | __gxx_personality_v0（Thumb） |
| `0x31809e` | `fff783fd` | `bl 0x317ba8` | __gxx_personality_v0（Thumb） |
| `0x3180ca` | `fff76dfd` | `bl 0x317ba8` | __gxx_personality_v0（Thumb） |

- 反向：**3 条** Thumb `bl`，ARM `bl`/`blx` **0 条**。分布：__gxx_personality_v0×3
- 正向：段内 **0 条** `bl` 指向具名 Thumb 符号的**入口**（无 —— 入口是纯叶，体内没有 bl），指向具名 ARM 符号 0 条。
- 入口：`push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}`；窗口内出口 1 个。归属判断：C++ 展开运行时的 662 B 单函数（按 CFI 恢复寄存器/跳转）

### §9 `0x2fec70` — 5,012 B，in-degree 2 → **Thumb-2**（证明级）

| 调用点 | 4 字节编码 | 解出 | 所在函数（ISA） |
|--------|-----------|------|-----------------|
| `0x2ffaac` | `fff7e0f8` | `bl 0x2fec70` | anon_2fec70（匿名区·Thumb 带） |
| `0x3001d0` | `fef74efd` | `bl 0x2fec70` | anon_2fec70（匿名区·Thumb 带） |

- 反向：**2 条** Thumb `bl`，ARM `bl`/`blx` **0 条**。分布：anon_2fec70 自递归×2（本段内 0x2ffaac / 0x3001d0）
- 正向：段内 **43 条** `bl` 指向具名 Thumb 符号的**入口**（FT_GlyphLoader_Add、FT_Hypot、FT_List_Add、FT_List_Find、FT_Outline_Transform、FT_Outline_Translate 等 14 个符号），指向具名 ARM 符号 0 条。
- 入口：`push.w {r3, r4, r5, r6, r7, r8, r9, lr}`；窗口内出口 6 个。归属判断：ttgload.c 带（5,012 B / 5 个 bl 入口 / 1,832 条）
- 特殊：本段没有具名调用者（反向命中全落在父区内部，属自递归），靠**正向**立住 —— 段内 `bl` 打在
  已知具名 Thumb 函数上，调用者状态已知，故本段必为 Thumb。

### §10 `0x309b08` — 2,996 B，in-degree 2 → **Thumb-2**（证明级）

| 调用点 | 4 字节编码 | 解出 | 所在函数（ISA） |
|--------|-----------|------|-----------------|
| `0x309e50` | `fff75afe` | `bl 0x309b08` | anon_309b08（匿名区·Thumb 带） |
| `0x30a3e4` | `fff790fb` | `bl 0x309b08` | anon_309b08（匿名区·Thumb 带） |

- 反向：**2 条** Thumb `bl`，ARM `bl`/`blx` **0 条**。分布：anon_309b08 自递归×2（本段内 0x309e50 / 0x30a3e4）
- 正向：段内 **27 条** `bl` 指向具名 Thumb 符号的**入口**（FT_DivFix、FT_Get_Char_Index、FT_Get_Next_Char、FT_Load_Glyph、FT_Matrix_Invert、FT_Outline_EmboldenXY 等 15 个符号），指向具名 ARM 符号 0 条。
- 入口：`push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}`；窗口内出口 5 个。归属判断：autofit afshaper.c 带（2,996 B / 2 个 bl 入口 / 1,143 条）
- 特殊：本段没有具名调用者（反向命中全落在父区内部，属自递归），靠**正向**立住 —— 段内 `bl` 打在
  已知具名 Thumb 函数上，调用者状态已知，故本段必为 Thumb。

### §11 `0x2f0444` — 1,154 B，in-degree 2 → **Thumb-2**（证明级）

| 调用点 | 4 字节编码 | 解出 | 所在函数（ISA） |
|--------|-----------|------|-----------------|
| `0x2f1784` | `fef75efe` | `bl 0x2f0444` | ps_hints_apply（Thumb） |
| `0x2f1dbe` | `fef741fb` | `bl 0x2f0444` | ps_hints_apply（Thumb） |

- 反向：**2 条** Thumb `bl`，ARM `bl`/`blx` **0 条**。分布：ps_hints_apply×2
- 正向：段内 **3 条** `bl` 指向具名 Thumb 符号的**入口**（ft_mem_realloc），指向具名 ARM 符号 0 条。
- 入口：`push.w {r0, r1, r2, r4, r5, r6, r7, r8, r9, r10, r11, lr}`；窗口内出口 11 个。归属判断：psaux/pshints.c 带（1,154 B / 7 个 bl 入口 / 445 条）

### §12 `0x2f9ab6` — 1,112 B，in-degree 2 → **Thumb-2**（证明级）

| 调用点 | 4 字节编码 | 解出 | 所在函数（ISA） |
|--------|-----------|------|-----------------|
| `0x2fe33c` | `fbf7bbfb` | `bl 0x2f9ab6` | TT_RunIns（Thumb） |
| `0x2fe446` | `fbf736fb` | `bl 0x2f9ab6` | TT_RunIns（Thumb） |

- 反向：**2 条** Thumb `bl`，ARM `bl`/`blx` **0 条**。分布：TT_RunIns×2
- 正向：段内 **11 条** `bl` 指向具名 Thumb 符号的**入口**（FT_DivFix、FT_MulDiv、FT_Request_Metrics、FT_Select_Metrics），指向具名 ARM 符号 0 条。
- 入口：`push.w {r4, r5, r6, r7, r8, r9, r10, lr}`；窗口内出口 13 个。归属判断：TrueType 字节码解释器带（1,112 B / 4 个 bl 入口 / 424 条）

### §13 `0x2f08c6` — 1,110 B，in-degree 2 → **Thumb-2**（证明级）

| 调用点 | 4 字节编码 | 解出 | 所在函数（ISA） |
|--------|-----------|------|-----------------|
| `0x2f170e` | `fff7daf8` | `bl 0x2f08c6` | ps_hints_apply（Thumb） |
| `0x2f1716` | `fff7d6f8` | `bl 0x2f08c6` | ps_hints_apply（Thumb） |

- 反向：**2 条** Thumb `bl`，ARM `bl`/`blx` **0 条**。分布：ps_hints_apply×2
- 正向：段内 **8 条** `bl` 指向具名 Thumb 符号的**入口**（FT_DivFix、ft_mem_alloc、ft_mem_free），指向具名 ARM 符号 0 条。
- 入口：`push {r4, r5, r6, lr}`；窗口内出口 9 个。归属判断：psaux/pshints.c 带（1,110 B / 6 个 bl 入口 / 410 条）

### §14 `0x2f1142` — 700 B，in-degree 2 → **Thumb-2**（证明级）

| 调用点 | 4 字节编码 | 解出 | 所在函数（ISA） |
|--------|-----------|------|-----------------|
| `0x2f12aa` | `fff74aff` | `bl 0x2f1142` | anon_2e9c78（匿名区·Thumb 带） |
| `0x2f18b2` | `fff746fc` | `bl 0x2f1142` | ps_hints_apply（Thumb） |

- 反向：**2 条** Thumb `bl`，ARM `bl`/`blx` **0 条**。分布：ps_hints_apply×1 / anon_2e9c78 区×1
- 正向：段内 **0 条** `bl` 指向具名 Thumb 符号的**入口**（无 —— 入口是纯叶，体内没有 bl），指向具名 ARM 符号 0 条。
- 入口：`push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}`；窗口内出口 1 个。归属判断：psaux 带 700 B 单函数（本批唯一与 split 尺寸差 2 B 的段）

## 7. 与 ISA-004 / ISA-005 的关系

- **ISA-004**「无名 Thumb-2 的自动识别不可靠」在它的口径下仍成立（解码外观确实不可靠），但不再是这 14 段的
  阻塞项 —— 调用点编码给的是证明级结论。建议把它的范围收窄为「不能用解码外观识别」，并指向本报告。
- **ISA-005**「0x2f8e0a 的 ISA 无法只靠解码判定」→ **已推翻为 Thumb-2**：51 条 Thumb `bl`（TT_RunIns 9 条、
  匿名区 41 条），ARM 侧 0 条；入口 8 条是 (a\*b+0x8000)>>16 的 64 位写法，纯叶算术算子。它落在
  ps_hints_apply(0x2f1400, 2534 B) 之后 0x11000 处，objdump 借名不代表归属 —— 这一点 ISA-005 说对了，
  但「判不出 ISA」这半句现在可以关掉。

## 8. 出卡情况

14 段全部 ≥512 B（最小 518 B）且全部判为 Thumb-2，因此 **14 段全部出卡**：

- 锚表：`asm/index-anonT_{2f8e0a`,`317798`,`2e8c38`,`2fa06c`,`2fb894`,`2e90fc`,`2fb68c`,`317ba8`,`2fec70`,`309b08`,`2f0444`,`2f9ab6`,`2f08c6`,`2f1142}.tsv`（`asm_index.py --thumb`，thumbv7 triple）
- 卡：`cards/anon_thumb_batch.c`，7,971 条锚点 / 14 节；逐节 `check_card_anchors.py` → **14/14 RESULT EXACT**

两处窗口修正（只动边界，不动锚文本）：

- `0x2fb68c`：split 记 520 B，但 `0x2fb892` 起 2 B 是链接器 `0xffff` 填充 → 收到 518 B。
- `0x2f1142`：split 记 698 B，切在最后一条 `pop.w {r4-r11, pc}` 中间 → 放到 700 B。

## 9. open

1. 只有静态证据：89 个 `bl` 命中 + 89 处边界复核 + 符号表对照。没有 oracle/device 锚，没跑差分，没碰设备。
2. in-degree 只数直接 `bl`；`blx rN`、函数指针槽、跳转表的间接调用不在分母里（3 段零具名调用者即是证据）。
3. 段长是 `anon_splits.tsv` 的「到下一个 Thumb bl 目标的距离」，**不是函数长度**：14 段里只有 3 段
   （`0x2e8c38` / `0x317ba8` / `0x2f1142`）是「一段一函数」（入口可达占比 99% / 96% / 100%），其余是「入口函数 + 只经指针进入的邻接函数 + 池字/表」。
   卡里给了每段的「入口可达」下界与「段内 bl 入口」表，但没有逐函数切卡。
4. 库级归属（FreeType / libpng 邻接 / libsupc++）proven；函数级名字一律 narrowed，未与上游源码逐行对照。

