/* cally 逆向卡：CSprite 的 SWF 数据装载口与时间线子项绘制口（原版 libyoyo.so，armv7）—— 一卡两节
 * @func §1 0x1e838c 0x1e9728  size 5024  1256 条（1230 指令 + 26 个字面量池字，池在函数体内两处：
 *                                    0x1e882c..0x1e8888 共 24 字、0x1e94a0..0x1e94a4 共 2 字）
 * @func §2 0x1eba90 0x1ebf08  size 1144   286 条（278 指令 + 8 个字面量池字 0x1ebee8..0x1ebf04）
 * 总账: 1542 锚点 = 1508 条指令 + 34 个池字，与 asm/index-CSprite_SWF_all.tsv 的对应两段逐字一致。
 *       该索引第 3 段（0x1e9c10..0x1eba8c，1952 条 = DrawDictionaryItem）**不在本卡范围**，已由别的卡覆盖，
 *       本卡不重复、也不对那 1952 条发锚点 ⇒ 用整份索引跑 check_card_anchors 会报 1952 missing（预期）。
 *       本卡自检用「只含本卡两段」的裁切索引，结果见文末。
 * 级别: §1 骨架（深）—— 1256/1256 锚点全覆盖；容器/记录的一级 schema、全部 28 个分配点（26 次
 *       MemoryManager::Alloc + 2 次 Free）、版本号编码、9 组数组复制驱动的元素步长、三条尾路
 *       （尺寸/半径、碰撞掩码、纹理装载）都逐条证到指令；**未钉**的是 84 B 记录里那 9 个数组与
 *       92 B/80 B/8 B 三种子项的逐字段语义（字段名与单位），故不写「正文」。
 *       §2 正文 —— 286/286 逐条解码：形参落位、矩阵拷贝与三次乘法、纹理查表、UV 比例、
 *       12 个栈字 + r2/r3 的 AAPCS 拆分实参、纹理缺失旁路、flag≠0 的 3D 合流与缩放的完整算式。
 *       唯一未钉：0x1ebd54 的投影循环读 sp+176..191 六个字，其中 4 个字在本函数内没有写点。
 * 符号: _ZN7CSprite12BuildSWFDataEPcii  → int CSprite::BuildSWFData(char* data, int w, int h)
 *       _ZN7CSprite13DrawSWFObjectEP18SWF_TimelineObjectP8yyMatrixS3_PjS4_S4_S4_b
 *                                        → void CSprite::DrawSWFObject(SWF_TimelineObject* obj,
 *                                             yyMatrix* a, yyMatrix* b, uint32* c1, uint32* c2,
 *                                             uint32* c3, uint32* c4, bool flag)
 * 同层: CSprite::DrawSWF 0x1ebf08（紧邻的下一个函数；它的三个调用点就是 §2 的三处调用者，
 *       见 cards/CSprite_DrawShape.c 段 A 的 1ec370/1ec4d4/1ec654）、
 *       CSprite::DrawDictionaryItem 0x1e9c10（§2 的绘制收口，另卡）、
 *       CSprite::SetupGradientTexture 0x1e7c8c、SetupBitmapTexture 0x1e7e1c、
 *       SetupSWFCollisionMasks 0x1e8264（§1 的三个子装配点，全在本函数上方同一 TU）
 *
 * ── 一句话 ─────────────────────────────────────────────────────
 *   §1 是「一次性反序列化」：把一段自带长度头/版本号的二进制 SWF 描述，展开成
 *      CSprite 的三层容器 —— this+0x7c 字典项数组（+0x80 是项数）、每项 24 B 子记录数组、
 *      每个子记录再挂 84 B 记录数组与两个 16 位/8 位数组；尾段再装 this+0x84 的影片
 *      （24 B 帧 → 144 B 显示项），最后算包围尺寸/半径并（可选）建碰撞掩码。
 *   §2 是「一次子项绘制」：把时间线子项自带的 64 B 矩阵与上层矩阵相乘，取 this+0x54 指向的
 *      页记录里的纹理号与两个 int16 画 UV 原点，把三组 16 B 颜色/坐标块透传下去，
 *      再以 AAPCS「r2/r3 + 14 字栈」拆分方式把 64 B 矩阵按值交给 DrawDictionaryItem。
 *      flag≠0 时先把 Graphics 的三层矩阵并进来，用投影后的两条基向量长度算一个缩放当第 5 形参。
 *
 * ── §1 的容器 schema（本卡重点 1；偏移全部来自 §1 的写点，不来自猜测）────────────
 *   头（0x1e83ac..0x1e8404）:
 *     w0 = *(int32*)data
 *     w0 >= 0  → version = 4，跳过 align4(w0) 字节，字典起点 = data+4
 *     w0 <  0  → version = *(int32*)(data+4)，跳过 align4(w0 & 0x7FFFFFFF)，字典起点 = data+8
 *     （0x1e83c0..0x1e83e0 的 b 条件块；0x1e83ec `addne r3,r5,#3` + 0x1e83f4 `bicne r3,r3,#3`
 *       是 align4，0x1e83fc `addne r1,r1,r3` 是跳过）
 *     接着 [字典起点] = 字典项数 n（0x1e840c `ldr r0,[r9],#4`），写 this+0x80，
 *     Alloc(4n) → this+0x7c 并 memset 0（0x1e8418..0x1e8434）。
 *   CSprite 侧: +0x7c 项指针数组 / +0x80 项数 / +0x84 影片指针（Alloc(28)）/ +0x78 字节开关 /
 *     +0x24 = 形参 w、+0x28 = 形参 h / +0x08,+0x0c,+0x10,+0x14,+0x18,+0x1c,+0x20 = 尺寸整数
 *     / +0x2c = 半径（vcvt.s32）/ +0x30,+0x32,+0x34 = 三个字节标志 / +0x1c,+0x20 另有一次覆写。
 *   项（本卡只证到尺寸与写点）:
 *     type 1 → Alloc(32)：[+0x00]=1 [+0x04]=id [+0x08]=子记录数组 [+0x0c..+0x1c]=记录 5 字
 *     type 2 → Alloc(28)：[+0x00]=2 [+0x04]=id [+0x08]=-1 [+0x0c]=0 [+0x10]=版本相关字
 *     其它   → Alloc(8) ：[+0x00]=type [+0x04]=id
 *   子记录（24 B，0x1e8620 起，索引 ×24 见 0x1e8628/0x1e8630）:
 *     [+0x00]=Alloc(84×n3) [+0x04]=Alloc(4×n1) [+0x08]=Alloc(4×n2)
 *     [+0x0c]=n3 [+0x10]=n1 [+0x14]=n2
 *   84 B 记录（0x1e8a7c 起，步长 84 见 0x1e8d24 `add r5,r5,#84`）:
 *     [+0x00..+0x20]=9 个数组指针 [+0x24..+0x2c]=3 个透传字 [+0x30..+0x50]=9 个计数
 *     ⇒ 记录本身是「9 对 (指针,计数) + 3 个字」的容器；计数随 version 变长（见块 §1-K）。
 *   帧（24 B，0x1e9328 `add r12,r12,#24`）: [+0x00]=显示项数组 [+0x04..+0x10]=4 个 float×g
 *     [+0x14]=显示项数 ⇒ 与 cards/CSprite_DrawShape.c 段 A 的 1ec408/1ec410 读法一致。
 *   显示项（144 B，0x1e92cc/0x1e92d0 `add #144`）: [+0x00..+0x0f] 4 字、[+0x10..+0x4f] 由
 *     4 组 4 字/16 B 拼成、[+0x50..+0x8f] 是 64 B 单位矩阵（16 个 0.0f + 4 个 1.0f，见
 *     0x1e9284..0x1e92c0）——「子项 144 B」这条与 DrawSWF 卡互证，且矩阵就在 +0x50。
 *
 * ── §1 的编码要点（本卡重点 2）──────────────────────────────────
 *   ① 大端：流里的 32 位值按「b0<<24 | b1<<16 | b2<<8 | b3」从 4 个字节拼出，同构三处
 *      （0x1e87e8..0x1e87f4、0x1e88b0..0x1e88c4、0x1e8a08..0x1e8a1c），都在 `ldrb` 之后。
 *   ② 数组元素宽度被压窄：多个目的地按 4 B/项申请，却用 `strh` 以 2 B 步长写入
 *      （0x1e8bd0、0x1e8bfc、0x1e8c58、0x1e8c84、0x1e8ce0），即「源 4 B/项 → 目标 16 位/项」。
 *   ③ 版本闸：`cmp version,#7`（0x1e851c 与 0x1e86f0）决定子项头是 16 B 还是 24 B、
 *      92 B 项是否多读一个 +0x08 字；`cmp version,#4`（0x1e8a80）与 `cmp #5`（0x1e8ad0）
 *      决定 84 B 记录头是 32/40/48 B —— 三个版本档位的记录形状都由这几条 cmp 定死。
 *
 * ── §2 的实参落位（本卡重点 3，AAPCS 拆分实证）────────────────────
 *   帧 = 708 + push 36 + vpush 8 = 752 ⇒ 栈形参从 [sp+0x2f0] 起：
 *     c1=[0x2f0] c2=[0x2f4] c3=[0x2f8] c4=[0x2fc] flag=[0x300]（ldrb，0x1ebabc）
 *   交给 DrawDictionaryItem 的 64 B 矩阵**不是整块压栈**，而是 r2/r3 = 矩阵第 0/1 字 +
 *   sp+0x00..0x37 = 第 2..15 字（0x1ebbd0..0x1ebc48 的 4 组 ldm/stm：源 sp+264..319 全部，
 *   再补 sp+256..263 两字进 r2/r3）。⇒ 形参表里 yyMatrix 按值传，落在「寄存器+栈」两处，
 *   核对此调用的第 5.. 个形参必须从 sp+0x38 起算，否则会整体错 8 字节。
/* ══ 段 A · CSprite::BuildSWFData 0x1e838c ═══════════════════════════════════════════════════
 *   5024 B / 1256 字 = 1230 指令 + 26 池字。28 个分配点：MemoryManager::Alloc ×26、Free ×2；
 *   子调用 3 个（SetupGradientTexture / SetupBitmapTexture / SetupSWFCollisionMasks）、sqrtf@plt ×4。
 *   控制流骨架（按地址）：
 *     0x1e838c 序言/守卫            0x1e83ac 头解码（version + 跳过长度）
 *     0x1e8408 字典项数组 Alloc     0x1e8444 项循环前导
 *     0x1e84e8 项类型分派（1/2/其它）
 *     0x1e8560 type1（32 B，挂 24 B 子记录）   0x1e84fc type2（28 B）   0x1e8498 其它（8 B）
 *     0x1e8620 子记录循环（24 B）   0x1e866c 子项分派（2/3/1）
 *     0x1e86c4 子项 92 B           0x1e888c 子项 8 B        0x1e88d0 子项 80 B
 *     0x1e8a7c 84 B 记录头 + 9 组数组复制    0x1e8d54 九组数组分配
 *     0x1e8f4c type2 的位图装载（SetupBitmapTexture）
 *     0x1e8ff4 影片 Alloc(28) → 帧数组 → 逐帧 144 B 显示项
 *     0x1e9334 碰撞掩码闸 → 0x1e9370 尺寸/半径 → 收尾返回 1
 */

/* ── 序言：帧 256、形参落位、data==0 直接返回 0 ──────────────────────────────
 *   push 36 + vpush {d8,d9} 16 = 52；sub 204 ⇒ 帧 256；无 r11 帧指针（r11 后面当游标用）。
 *   r0(this) → [sp+0x2c]、r2 → [sp+0x64]、r3 → [sp+0x68]、r1(data) 留在 r1。
 *   ★ 0x1e8394 的 cmp 在 sub 之前：`cmp r1,#0; sub sp,#204` 是调度槽，返回路径 0x1e96b0 只是
 *     把 r1(0) 搬到 r0（返回值 0 表示 data 为空、什么都没建）。
 */
/* @0x001e838c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x001e8390 vpush {d8, d9} */
/* @0x001e8394 cmp r1, #0——守卫：cmp 在 sub 之前，data==0 时返回 0 */
/* @0x001e8398 sub sp, sp, #204 */
/* @0x001e839c str r0, [sp, #0x2c] */
/* @0x001e83a0 str r2, [sp, #0x64] */
/* @0x001e83a4 str r3, [sp, #0x68] */
/* @0x001e83a8 beq 0x1e96b0 <_ZN7CSprite12BuildSWFDataEPcii+0x1324> */

/* ── 头解码：w0 的 bit31 = 「有显式 version」，跳过长度按 align4 ───────────────────
 *   r4 = *(int32*)data（0x1e83ac），落 [sp+0x58]。
 *   w0 >= 0：version=4（movge r5,#4 → [sp+0x44]）、数据起点 data+4（addge r1,r1,#4）
 *   w0 <  0：version=*(int32*)(data+4)（0x1e83c8 ldrlt r12,[r1,#4] → [sp+0x44]）、
 *            w0 &= 0x7FFFFFFF（0x1e83d4 biclt r4,r4,#0x80000000）、起点 data+8
 *   然后 0x1e83dc..0x1e83fc：若跳过长度 ≠ 0，起点 += align4(跳过长度)（+3 再 bic #3）；
 *   否则 [sp+0x60] = 0，即「无跳过块」。
 *   ★ [sp+0x44] 后面被当版本号比较（0x1e851c / 0x1e86f0 的 cmp #7、0x1e8a80 的 cmp #4、
 *     0x1e8ad0 的 cmp #5），是本函数唯一的格式开关。
 */
/* @0x001e83ac ldr r4, [r1] */
/* @0x001e83b0 movw r2, #0x101e */
/* @0x001e83b4 cmp r4, #0 */
/* @0x001e83b8 str r4, [sp, #0x58] */
/* @0x001e83bc addge r1, r1, #4 */
/* @0x001e83c0 ldrlt r4, [sp, #0x58] */
/* @0x001e83c4 movge r5, #4 */
/* @0x001e83c8 ldrlt r12, [r1, #0x4] */
/* @0x001e83cc addlt r1, r1, #8 */
/* @0x001e83d0 strge r5, [sp, #0x44] */
/* @0x001e83d4 biclt r4, r4, #-2147483648——bit31 = 有显式 version（清掉后作跳过长度） */
/* @0x001e83d8 strlt r4, [sp, #0x58] */
/* @0x001e83dc ldr r5, [sp, #0x58] */
/* @0x001e83e0 strlt r12, [sp, #0x44] */
/* @0x001e83e4 cmp r5, #0 */
/* @0x001e83e8 strne r1, [sp, #0x60] */
/* @0x001e83ec addne r3, r5, #3 */
/* @0x001e83f0 ldr r4, [sp, #0x2c] */
/* @0x001e83f4 bicne r3, r3, #3 */
/* @0x001e83f8 ldreq r12, [sp, #0x58] */
/* @0x001e83fc addne r1, r1, r3 */
/* @0x001e8400 mov r3, #1 */
/* @0x001e8404 mov r9, r1 */

/* ── 字典项数组：项数 → this+0x80，指针数组 → this+0x7c（4 B/项，memset 0）────────
 *   0x1e8408 先算出一个 .rodata 串地址（池字 0x0016a014 + pc=0x1e8418 ⇒ 0x34e42c）当 Alloc 的
 *   file 实参，0x1e840c `ldr r0,[r9],#4` 读项数并推进 r9。
 *   0x1e8418 str [this+0x80]；0x1e841c lsl #2 → Alloc(4n)；0x1e8430 str [this+0x7c]；
 *   0x1e8434 memset(ptr, 0, 4n)。
 *   ★ 0x1e8440 `ble 0x1e8ff4`：项数 ≤ 0 时**跳过整个字典循环直接进影片段** —— 空字典是合法输入。
 */
/* @0x001e8408 ldr r1, [pc, #0x420] */
/* @0x001e840c ldr r0, [r9], #4 */
/* @0x001e8410 add r1, pc, r1 */
/* @0x001e8414 streq r12, [sp, #0x60] */
/* @0x001e8418 str r0, [r4, #0x80] */
/* @0x001e841c lsl r0, r0, #2——Alloc(4n)：字典项指针数组 */
/* @0x001e8420 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x001e8424 ldr r2, [r4, #0x80] */
/* @0x001e8428 mov r1, #0 */
/* @0x001e842c lsl r2, r2, #2 */
/* @0x001e8430 str r0, [r4, #0x7c] */
/* @0x001e8434 bl 0xb65b0 <memset@plt>——memset(数组,0,4n) */
/* @0x001e8438 ldr r3, [r4, #0x80] */
/* @0x001e843c cmp r3, #0 */
/* @0x001e8440 ble 0x1e8ff4 <_ZN7CSprite12BuildSWFDataEPcii+0xc68> */

/* ── 项循环前导：一次性把 6 个 pc 相对量（.rodata 文件串/池基址）与 0.0f 装进栈槽 ────────
 *   s16 = 0.0f（池字 0x1e882c），后面所有「清零」都用它（vstr s16 共 50 条 vstr 里的大半）。
 *   [sp+0x5c]/[sp+0x70]/[sp+0x74]/[sp+0x78]/[sp+0x7c] = 五个 `add rX,pc,rX` 得到的 .rodata 地址，
 *   全部是 Alloc 的第 2 实参（file）。[sp+0x28]=项下标 i、[sp+0x54]=i*4、r7=数据游标。
 *   ★ 这些串地址的一个已算实例：0x1e8478 的字面量 0x00169f9c → 0x35241c；0x1e8a48 的
 *     0x001485d4 → 0x331024。本仓库无 libyoyo.so 副本，串内容未读（见 open）。
 */
/* @0x001e8444 ldr r5, [pc, #0x3e8] */
/* @0x001e8448 mov r12, #0 */
/* @0x001e844c ldr r4, [pc, #0x3e4] */
/* @0x001e8450 vldr s16, [pc, #980]——s16 = 0.0f（池字 0x1e882c） */
/* @0x001e8454 add r5, pc, r5 */
/* @0x001e8458 str r12, [sp, #0x54] */
/* @0x001e845c add r4, pc, r4 */
/* @0x001e8460 str r5, [sp, #0x5c] */
/* @0x001e8464 str r4, [sp, #0x7c] */
/* @0x001e8468 mov r7, r9 */
/* @0x001e846c str r12, [sp, #0x28] */
/* @0x001e8470 ldr r5, [pc, #0x3c4] */
/* @0x001e8474 ldr r12, [pc, #0x3c4] */
/* @0x001e8478 ldr r4, [pc, #0x3c4] */
/* @0x001e847c add r5, pc, r5 */
/* @0x001e8480 add r12, pc, r12 */
/* @0x001e8484 str r5, [sp, #0x70] */
/* @0x001e8488 add r4, pc, r4 */
/* @0x001e848c str r12, [sp, #0x74] */
/* @0x001e8490 str r4, [sp, #0x78] */
/* @0x001e8494 b 0x1e84e8 <_ZN7CSprite12BuildSWFDataEPcii+0x15c> */

/* ── 项类型「其它」：Alloc(8)，只写 {type, id} ────────────────────────────────
 *   [item+0x00] = r4(type)、[item+0x04] = r5(id)（0x1e852c `stm r0,{r4,r5}` 同构见上一定义），
 *   游标 r7 += 8（0x1e84b4），[this+0x7c][i] = item（0x1e84bc），i++ 与 i<n 判定在 0x1e84c0..e4。
 *   ★ 这条是「未知类型也要占位」的兜底：后面 DrawSWFObject 用 [item+4] 当字典索引，
 *     数组必须与项数等长，所以这里宁可分配 8 B 也不留空洞。
 */
/* @0x001e8498 mov r3, #1 */
/* @0x001e849c mov r0, #8 */
/* @0x001e84a0 ldr r1, [sp, #0x5c] */
/* @0x001e84a4 mov r2, #70 */
/* @0x001e84a8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x001e84ac ldr r4, [sp, #0x2c] */
/* @0x001e84b0 ldr r5, [sp, #0x54] */
/* @0x001e84b4 add r7, r7, #8 */
/* @0x001e84b8 ldr r3, [r4, #0x7c] */
/* @0x001e84bc str r0, [r3, r5] */
/* @0x001e84c0 ldr r12, [sp, #0x2c] */
/* @0x001e84c4 ldr r4, [sp, #0x28] */
/* @0x001e84c8 ldr r5, [sp, #0x54] */
/* @0x001e84cc ldr r3, [r12, #0x80] */
/* @0x001e84d0 add r4, r4, #1 */
/* @0x001e84d4 add r5, r5, #4 */
/* @0x001e84d8 str r4, [sp, #0x28] */
/* @0x001e84dc cmp r3, r4 */
/* @0x001e84e0 str r5, [sp, #0x54] */
/* @0x001e84e4 ble 0x1e8ff0 <_ZN7CSprite12BuildSWFDataEPcii+0xc64> */

/* ── 项头：`ldm r7,{r4,r5}` = {type, id}，type==1 → 0x1e8560，type==2 → 0x1e84fc ──
 *   ★ 项头就是两个字；type 之后的分支各自决定记录总长（28/24/16/8），见下三块。
 */
/* @0x001e84e8 ldm r7, {r4, r5} */
/* @0x001e84ec cmp r4, #1 */
/* @0x001e84f0 beq 0x1e8560 <_ZN7CSprite12BuildSWFDataEPcii+0x1d4> */
/* @0x001e84f4 cmp r4, #2 */
/* @0x001e84f8 bne 0x1e8498 <_ZN7CSprite12BuildSWFDataEPcii+0x10c> */

/* ── type 2（28 B）：位图/纹理项，两档头长 ───────────────────────────────────
 *   Alloc(28)（0x1e8504 mov r0,#28）→ [this+0x7c][i]；[item]=2、[item+4]=id（0x1e852c stm）。
 *   若 version > 7（0x1e851c cmp #7 + 0x1e853c bls）：再读 [r7+0x14] 入 [item+0x10] 且 r7 += 24，
 *   同时 [item+8] = -1（mvn r2,#0）、[item+0xc] = 0。
 *   version ≤ 7：跳 0x1e8f4c，那里 [item+8]=[item+0x10]=-1、[item+0xc]=0，游标只推进到 r7+32 起。
 *   ★ 这条记录最终被 0x1e8f4c 段的 SetupBitmapTexture 消费：三个计数 [r7+0x14]/[r7+0x18]/[r7+0x1c]
 *     与紧随其后的三块像素数据（起点 r7+32，块间 align4）就是 SWF_Bitmap 的 4 个平面。
 */
/* @0x001e84fc ldr r1, [sp, #0x7c] */
/* @0x001e8500 mov r3, #1 */
/* @0x001e8504 mov r0, #28 */
/* @0x001e8508 mov r2, #70 */
/* @0x001e850c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x001e8510 ldr r12, [sp, #0x2c] */
/* @0x001e8514 ldr r3, [r12, #0x7c] */
/* @0x001e8518 ldr r12, [sp, #0x44] */
/* @0x001e851c cmp r12, #7 */
/* @0x001e8520 ldr r12, [sp, #0x54] */
/* @0x001e8524 mov r1, r0 */
/* @0x001e8528 str r0, [r3, r12] */
/* @0x001e852c stm r0, {r4, r5} */
/* @0x001e8530 ldr r8, [r7, #0x8] */
/* @0x001e8534 ldr r3, [r7, #0xc] */
/* @0x001e8538 ldr r9, [r7, #0x10] */
/* @0x001e853c bls 0x1e8f4c <_ZN7CSprite12BuildSWFDataEPcii+0xbc0> */
/* @0x001e8540 ldr r3, [r7, #0x14] */
/* @0x001e8544 mvn r2, #0 */
/* @0x001e8548 add r7, r7, #24 */
/* @0x001e854c str r2, [r0, #0x8] */
/* @0x001e8550 mov r2, #0 */
/* @0x001e8554 str r2, [r0, #0xc] */
/* @0x001e8558 str r3, [r0, #0x10] */
/* @0x001e855c b 0x1e84c0 <_ZN7CSprite12BuildSWFDataEPcii+0x134> */

/* ── type 1（32 B）：形状/时间线项，挂 24 B 子记录数组 ─────────────────────────
 *   记录是 28 B（0x1e8580 `add r7,r7,#28` 之后再回读 [r7-0x14..-0x4]）：
 *     [item+0x0c]=记录[2]  [item+0x10]=记录[3]  [item+0x14]=记录[4]
 *     [item+0x18]=记录[5]  [item+0x1c]=记录[6]（=子记录个数 n）
 *   0x1e85cc `add r0,r12,r12,lsl #1` + `lsl r0,r0,#3` ⇒ Alloc(24n) → [item+8]；
 *   [item+0]=1、[item+4]=id（0x1e85a4/a8）。
 *   ★ n==0 直接回 0x1e84c0 推进（0x1e85e8 beq）——形状项可以没有子记录。
 */
/* @0x001e8560 mov r3, r4 */
/* @0x001e8564 ldr r1, [sp, #0x70] */
/* @0x001e8568 movw r2, #0x102c */
/* @0x001e856c mov r0, #32 */
/* @0x001e8570 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x001e8574 ldr r12, [sp, #0x2c] */
/* @0x001e8578 mov r3, r4 */
/* @0x001e857c ldr r1, [sp, #0x70] */
/* @0x001e8580 add r7, r7, #28 */
/* @0x001e8584 ldr r2, [r12, #0x7c] */
/* @0x001e8588 ldr r12, [sp, #0x54] */
/* @0x001e858c str r0, [sp, #0x48] */
/* @0x001e8590 ldr lr, [sp, #0x48]——lr = 新分配的 32 B 项 */
/* @0x001e8594 ldr r0, [r7, #-0x14] */
/* @0x001e8598 str lr, [r2, r12] */
/* @0x001e859c str r0, [lr, #0xc] */
/* @0x001e85a0 ldr r2, [r7, #-0x10] */
/* @0x001e85a4 str r4, [lr] */
/* @0x001e85a8 str r5, [lr, #0x4] */
/* @0x001e85ac str r2, [lr, #0x10] */
/* @0x001e85b0 movw r2, #0x103f */
/* @0x001e85b4 ldr r0, [r7, #-0xc] */
/* @0x001e85b8 ldr r12, [r7, #-0x4] */
/* @0x001e85bc str r0, [lr, #0x14] */
/* @0x001e85c0 ldr r0, [r7, #-0x8] */
/* @0x001e85c4 str r12, [lr, #0x1c] */
/* @0x001e85c8 str r0, [lr, #0x18] */
/* @0x001e85cc add r0, r12, r12, lsl #1 */
/* @0x001e85d0 lsl r0, r0, #3 */
/* @0x001e85d4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>——Alloc(24n) → 子记录数组 */
/* @0x001e85d8 ldr r4, [sp, #0x48] */
/* @0x001e85dc ldr r3, [r4, #0x1c] */
/* @0x001e85e0 cmp r3, #0 */
/* @0x001e85e4 str r0, [r4, #0x8] */
/* @0x001e85e8 beq 0x1e84c0 <_ZN7CSprite12BuildSWFDataEPcii+0x134> */

/* ── 子记录循环入口：24 B/条，[+0x0c]/[+0x10]/[+0x14] 三个计数先落位再看是否分配 ────────
 *   r6 = [item+8] + 24*i（0x1e8628 `add r6,r12,r12,lsl #1`、0x1e8630 `add r6,r3,r6,lsl #3`）。
 *   [+0x10] ← 记录[0]（n1）、[+0x14] ← 记录[1]（n2）、[+0x0c] ← 记录[2]（n3）。
 *   ★ 三个「为 0 就不分配」的分支（0x1e8644/0x1e8654/0x1e8664 的 streq + 各自 bne 到分配块）
 *     是本函数的统一风格：**计数 0 ⇒ 指针严格置 0**，不做 Alloc(0)。
 */
/* @0x001e85ec ldr r5, [pc, #0x254] */
/* @0x001e85f0 mov r3, r0 */
/* @0x001e85f4 ldr r12, [pc, #0x250] */
/* @0x001e85f8 mov r4, #0 */
/* @0x001e85fc add r5, pc, r5 */
/* @0x001e8600 str r5, [sp, #0x6c] */
/* @0x001e8604 ldr r5, [pc, #0x244] */
/* @0x001e8608 add r12, pc, r12 */
/* @0x001e860c str r4, [sp, #0x38] */
/* @0x001e8610 add r5, pc, r5 */
/* @0x001e8614 str r12, [sp, #0x4c] */
/* @0x001e8618 str r5, [sp, #0x50] */
/* @0x001e861c ldr r12, [sp, #0x38] */
/* @0x001e8620 add r5, r7, #12 */
/* @0x001e8624 ldr r0, [r7] */
/* @0x001e8628 add r6, r12, r12, lsl #1——24 B 步长：3i 再 lsl#3 */
/* @0x001e862c cmp r0, #0 */
/* @0x001e8630 add r6, r3, r6, lsl #3 */
/* @0x001e8634 str r0, [r6, #0x10] */
/* @0x001e8638 ldr r3, [r7, #0x4] */
/* @0x001e863c str r3, [r6, #0x14] */
/* @0x001e8640 ldr r2, [r7, #0x8] */
/* @0x001e8644 streq r0, [r6, #0x4] */
/* @0x001e8648 str r2, [r6, #0xc] */
/* @0x001e864c bne 0x1e8f2c <_ZN7CSprite12BuildSWFDataEPcii+0xba0> */
/* @0x001e8650 cmp r3, #0 */
/* @0x001e8654 streq r3, [r6, #0x8] */
/* @0x001e8658 bne 0x1e8f10 <_ZN7CSprite12BuildSWFDataEPcii+0xb84> */
/* @0x001e865c ldr r3, [r6, #0xc] */
/* @0x001e8660 cmp r3, #0 */
/* @0x001e8664 streq r3, [r6] */
/* @0x001e8668 bne 0x1e8ef0 <_ZN7CSprite12BuildSWFDataEPcii+0xb64> */

/* ── 子项循环：n1 次，每次读 1 个子类型字，按 2/3/1 三路建对象，其它存 0 ───────────────
 *   r2 = [+0x10] = n1；r5 = 子项数据游标（r7+12 起）；r8 = 下标；
 *   [r6+0x04][r8] ← 子项指针（0x1e86b4 `str r4,[r3,r8,lsl #2]`），未知类型写 0（r4=0）。
 */
/* @0x001e866c ldr r2, [r6, #0x10] */
/* @0x001e8670 cmp r2, #0 */
/* @0x001e8674 beq 0x1e89dc <_ZN7CSprite12BuildSWFDataEPcii+0x650> */
/* @0x001e8678 ldr r4, [pc, #0x1d4] */
/* @0x001e867c mov r8, #0 */
/* @0x001e8680 ldr r12, [pc, #0x1d0] */
/* @0x001e8684 add r4, pc, r4 */
/* @0x001e8688 str r4, [sp, #0x30] */
/* @0x001e868c add r12, pc, r12 */
/* @0x001e8690 str r12, [sp, #0x34] */
/* @0x001e8694 b 0x1e86c4 <_ZN7CSprite12BuildSWFDataEPcii+0x338> */
/* @0x001e8698 cmp r7, #3 */
/* @0x001e869c beq 0x1e88d0 <_ZN7CSprite12BuildSWFDataEPcii+0x544> */
/* @0x001e86a0 cmp r7, #1 */
/* @0x001e86a4 addne r5, r5, #4 */
/* @0x001e86a8 movne r4, #0 */
/* @0x001e86ac beq 0x1e888c <_ZN7CSprite12BuildSWFDataEPcii+0x500> */
/* @0x001e86b0 ldr r3, [r6, #0x4] */
/* @0x001e86b4 str r4, [r3, r8, lsl #2] */
/* @0x001e86b8 add r8, r8, #1 */
/* @0x001e86bc cmp r2, r8 */
/* @0x001e86c0 bls 0x1e89dc <_ZN7CSprite12BuildSWFDataEPcii+0x650> */

/* ── 子项 subtype 2（92 B）：渐变填充样式（尾部调 SetupGradientTexture）───────────────
 *   Alloc(92)（0x1e86d8 mov r0,#0x5c）；[+0x04] = 子项头[1]；version>7 时再读 [+0x08] = 头[2]
 *   且头长 12，否则 [+0x08] = -1、头长 8（0x1e86f0 cmp #7 / 0x1e86f4 addls / 0x1e8700 ldrhi）。
 *   0x1e8718..0x1e8724 把 36 B（9 字）源块搬到 sp+164（ldr/str 流水，`cmp r3,r0` 判尾）。
 *   随后是一串常量填充：1.0f（`mov r3,#0x3f800000`）写 [+0x34]/[+0x48]（0x1e8738/0x1e8760），
 *   0.0f 写 8 处 [+0x14]/[+0x18]/[+0x24]/[+0x28]/[+0x2c]/[+0x30]/[+0x38]/[+0x44]
 *   （0x1e8734..0x1e876c 的 8 条 vstr），再把 36 B 源块的头几字回填到
 *   [+0x0c]/[+0x10]/[+0x1c]/[+0x20]/[+0x3c]/[+0x40] 与 [+0x4c]（= 档数，0x1e8798），
 *   0x1e8728..0x1e8788 共 6 条 ldr/str 配对。
 *   0x1e879c `lsl r0,r0,#3` ⇒ Alloc(8 × 渐变档数) → [+0x50]；[+0x4c] = 档数；
 *   0x1e87c0..0x1e87fc 每档 8 B：第一个字直接拷，第二个字由随后 4 个字节按大端拼（见 ①）。
 *   收尾 [+0x54]=-1、[+0x58]=0、[+0]=subtype、[+0x04] 已是样式值，然后
 *   `bl SetupGradientTexture(this, item)`（0x1e881c），返回后再 `str r7,[r4]` 固定 subtype=2。
 *   ★ 「92 B 项 + 8 B/档 + 档数为 0 就不进循环（0x1e87b0 ble）」是本块三条可证事实。
 */
/* @0x001e86c4 ldr r7, [r5] */
/* @0x001e86c8 cmp r7, #2 */
/* @0x001e86cc bne 0x1e8698 <_ZN7CSprite12BuildSWFDataEPcii+0x30c> */
/* @0x001e86d0 movw r2, #0x1079 */
/* @0x001e86d4 mov r3, #1 */
/* @0x001e86d8 mov r0, #92 */
/* @0x001e86dc ldr r1, [sp, #0x4c] */
/* @0x001e86e0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x001e86e4 ldr r12, [sp, #0x44] */
/* @0x001e86e8 ldr r3, [r5, #0x4] */
/* @0x001e86ec add r2, sp, #164 */
/* @0x001e86f0 cmp r12, #7 */
/* @0x001e86f4 addls r5, r5, #8 */
/* @0x001e86f8 str r3, [r0, #0x4] */
/* @0x001e86fc mov r4, r0 */
/* @0x001e8700 ldrhi r3, [r5, #0x8] */
/* @0x001e8704 addhi r5, r5, #12 */
/* @0x001e8708 mvnls r3, #0 */
/* @0x001e870c str r3, [r0, #0x8] */
/* @0x001e8710 add r0, r5, #36 */
/* @0x001e8714 mov r3, r5 */
/* @0x001e8718 ldr r1, [r3], #4 */
/* @0x001e871c cmp r3, r0 */
/* @0x001e8720 str r1, [r2], #4 */
/* @0x001e8724 bne 0x1e8718 <_ZN7CSprite12BuildSWFDataEPcii+0x38c> */
/* @0x001e8728 ldr r1, [sp, #0xa4] */
/* @0x001e872c mov r3, #1065353216 */
/* @0x001e8730 ldr r2, [sp, #0xa8] */
/* @0x001e8734 vstr s16, [r4, #68] */
/* @0x001e8738 str r3, [r4, #0x48] */
/* @0x001e873c vstr s16, [r4, #56] */
/* @0x001e8740 str r1, [r4, #0xc] */
/* @0x001e8744 vstr s16, [r4, #48] */
/* @0x001e8748 str r2, [r4, #0x1c] */
/* @0x001e874c vstr s16, [r4, #44] */
/* @0x001e8750 ldr r1, [sp, #0xac] */
/* @0x001e8754 vstr s16, [r4, #40] */
/* @0x001e8758 ldr r2, [sp, #0xb0] */
/* @0x001e875c vstr s16, [r4, #36] */
/* @0x001e8760 str r3, [r4, #0x34] */
/* @0x001e8764 vstr s16, [r4, #24] */
/* @0x001e8768 str r1, [r4, #0x3c] */
/* @0x001e876c vstr s16, [r4, #20] */
/* @0x001e8770 str r2, [r4, #0x10] */
/* @0x001e8774 mov r3, #1 */
/* @0x001e8778 ldr r1, [sp, #0xb4] */
/* @0x001e877c add r5, r5, #40 */
/* @0x001e8780 ldr r2, [sp, #0xb8] */
/* @0x001e8784 str r1, [r4, #0x20] */
/* @0x001e8788 str r2, [r4, #0x40] */
/* @0x001e878c movw r2, #0x10a4——行号 0x10a4（Alloc 的 line 实参） */
/* @0x001e8790 ldr r0, [r5, #-0x4] */
/* @0x001e8794 ldr r1, [sp, #0x50] */
/* @0x001e8798 str r0, [r4, #0x4c] */
/* @0x001e879c lsl r0, r0, #3 */
/* @0x001e87a0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>——Alloc(8×档数) → [+0x50] */
/* @0x001e87a4 ldr r11, [r4, #0x4c] */
/* @0x001e87a8 cmp r11, #0 */
/* @0x001e87ac str r0, [r4, #0x50] */
/* @0x001e87b0 ble 0x1e8804 <_ZN7CSprite12BuildSWFDataEPcii+0x478> */
/* @0x001e87b4 lsl r11, r11, #3 */
/* @0x001e87b8 mov r2, r5 */
/* @0x001e87bc mov r12, #0 */
/* @0x001e87c0 ldr r1, [r2] */
/* @0x001e87c4 mov r3, r0 */
/* @0x001e87c8 add r2, r2, #8 */
/* @0x001e87cc str r1, [r3, r12]! */
/* @0x001e87d0 add r12, r12, #8 */
/* @0x001e87d4 ldrb r1, [r2, #-0x2] */
/* @0x001e87d8 cmp r12, r11 */
/* @0x001e87dc ldrb r10, [r2, #-0x3] */
/* @0x001e87e0 ldrb r9, [r2, #-0x4] */
/* @0x001e87e4 ldrb lr, [r2, #-0x1] */
/* @0x001e87e8 lsl r1, r1, #16 */
/* @0x001e87ec orr r1, r1, r10, lsl #8 */
/* @0x001e87f0 orr r1, r1, r9 */
/* @0x001e87f4 orr r1, r1, lr, lsl #24 */
/* @0x001e87f8 str r1, [r3, #0x4] */
/* @0x001e87fc bne 0x1e87c0 <_ZN7CSprite12BuildSWFDataEPcii+0x434> */
/* @0x001e8800 add r5, r5, r12 */
/* @0x001e8804 mvn r2, #0 */
/* @0x001e8808 mov r3, #0 */
/* @0x001e880c str r2, [r4, #0x54] */
/* @0x001e8810 mov r1, r4 */
/* @0x001e8814 ldr r0, [sp, #0x2c] */
/* @0x001e8818 str r3, [r4, #0x58] */
/* @0x001e881c bl 0x1e7c8c <_ZN7CSprite20SetupGradientTextureEP25SWF_GradientFillStyleData>——type 1 形状项的半成品先交给梯度装配 */
/* @0x001e8820 str r7, [r4] */
/* @0x001e8824 ldr r2, [r6, #0x10] */
/* @0x001e8828 b 0x1e86b0 <_ZN7CSprite12BuildSWFDataEPcii+0x324> */

/* ── 内联字面量池（24 字，0x1e882c..0x1e8888）：本函数最大的一处数据混在代码里 ─────────
 *   objdump 把它逐条译成了指令（andeq/andseq/ldrsbeq/mulseq/eoreq），**全部不是指令**：
 *     0x1e882c = 0x00000000（= 0.0f，s16 的来源，0x1e8450 的 vldr 目标）
 *     0x1e8830..0x1e8888 = 23 个 pc 相对 .rodata 偏移（Alloc 的 file 实参；已算实例 0x331024/
 *       0x33102c/0x331038/0x34E42C/0x352418/0x35241C/0x352420）
 *     ⇒ 24 字全部被引用（末字 0x1e8888 由 0x1e90cc `ldr r12,[pc,#-0x84c]` 取，落 0x331038，
 *       与 0x1e8a60 所指同一个串）。
 *   引用点分布：0x1e8408/444/44c/470/474/478/5ec/5f4/604/678/680 走正向，0x1e8a30..0x1e8a68、
 *   0x1e8e74/ea0/ecc、0x1e8ff4/ffc 走 `ldr rX,[pc,#-imm]` 反向。
 */
/* @0x001e882c andeq r0, r0, r0 */
/* @0x001e8830 andseq r10, r6, r4, lsl r0 */
/* @0x001e8834 ldrsbeq r8, [r4], -r12 */
/* @0x001e8838 ldrsbeq r8, [r4], -r4 */
/* @0x001e883c andseq r9, r6, r8, lsr #31 */
/* @0x001e8840 andseq r9, r6, r4, lsr #31 */
/* @0x001e8844 mulseq r6, r12, pc */
/* @0x001e8848 andseq r9, r6, r8, lsr #28 */
/* @0x001e884c andseq r9, r6, r12, lsl lr */
/* @0x001e8850 andseq r9, r6, r4, lsl lr */
/* @0x001e8854 andseq r9, r6, r0, lsr #27 */
/* @0x001e8858 mulseq r6, r8, sp */
/* @0x001e885c andseq r9, r6, r0, ror #19 */
/* @0x001e8860 ldrsbeq r9, [r6], -r8 */
/* @0x001e8864 ldrsbeq r9, [r6], -r0 */
/* @0x001e8868 ldrsbeq r8, [r4], -r4 */
/* @0x001e886c andseq r8, r4, r4, asr #11 */
/* @0x001e8870 ldrheq r8, [r4], -r12 */
/* @0x001e8874 andseq r8, r4, r12, lsr #3 */
/* @0x001e8878 andseq r8, r4, r0, lsl #3 */
/* @0x001e887c andseq r8, r4, r4, asr r1 */
/* @0x001e8880 andseq r8, r4, r12, lsr #32 */
/* @0x001e8884 eoreq r7, r0, r12, lsr #27 */
/* @0x001e8888 andseq r7, r4, r4, asr pc */

/* ── 子项 subtype 3（8 B）：Alloc(8)，只填 [+0x04] = 大端四字节 ───────────────────────
 *   0x1e8898 mov r0,#8；0x1e88a0..0x1e88c4 的 4 个 ldrb + 3 个 orr（左移 8/16/24）拼出一个
 *   32 位值（大端），写 [+0x04]；游标 r5 += 8；[+0x00] = 3 由公共尾 0x1e8820 `str r7,[r4]` 写。
 */
/* @0x001e888c ldr r1, [sp, #0x34] */
/* @0x001e8890 movw r2, #0x1066 */
/* @0x001e8894 mov r3, r7 */
/* @0x001e8898 mov r0, #8 */
/* @0x001e889c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x001e88a0 ldrb r3, [r5, #0x6] */
/* @0x001e88a4 ldrb r1, [r5, #0x4] */
/* @0x001e88a8 add r5, r5, #8 */
/* @0x001e88ac ldrb r2, [r5, #-0x1] */
/* @0x001e88b0 lsl r3, r3, #16 */
/* @0x001e88b4 mov r4, r0 */
/* @0x001e88b8 ldrb r0, [r5, #-0x3] */
/* @0x001e88bc orr r3, r3, r0, lsl #8 */
/* @0x001e88c0 orr r3, r3, r1 */
/* @0x001e88c4 orr r3, r3, r2, lsl #24 */
/* @0x001e88c8 str r3, [r4, #0x4] */
/* @0x001e88cc b 0x1e8820 <_ZN7CSprite12BuildSWFDataEPcii+0x494> */

/* ── 子项 subtype 1（80 B）：Alloc(0x50)，含一次「按 id 反查字典」的线性搜索 ────────────
 *   [+0x04]=头[1]、[+0x08]=头[2]，[+0x0c]=-1（0x1e88ec mvn r3,#0 → 0x1e8904）。
 *   若 i>0（[sp+0x28] ≠ 0）：拿 [+0x08] 与 [this+0x7c][0]->[+0x04] 比，不等就沿数组
 *   `ldr r1,[r2,#0x4]!`（0x1e8934）逐项比，命中把下标写 [+0x0c]、未命中保持 -1
 *   （0x1e8924 movne / 0x1e89d0 mov r3,#0 两条出口）。★ 这就是「引用前项」的 id→下标解析。
 *   然后 36 B（9 字）从 r5 搬到 sp+164，再回填到 [+0x10]/[+0x14]/[+0x20]/[+0x24]/[+0x40]/[+0x44]
 *   （0x1e896c..0x1e89c8 六条 ldr/str）；同时 1.0f 写 [+0x38]/[+0x4c]、0.0f 写
 *   [+0x18]/[+0x1c]/[+0x28]/[+0x2c]/[+0x30]/[+0x34]/[+0x3c]/[+0x48] 八处。
 *   ★ 0x1e89d4 的 `str r3,[r4,#0xc]` 是命中的落点（r3 = 下标），0x1e89d0 的 mov r3,#0 是
 *     「第 0 项恒命中」的短路。
 */
/* @0x001e88d0 movw r2, #0x10c3 */
/* @0x001e88d4 mov r3, #1 */
/* @0x001e88d8 mov r0, #80 */
/* @0x001e88dc ldr r1, [sp, #0x30] */
/* @0x001e88e0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x001e88e4 ldr r2, [r5, #0x4] */
/* @0x001e88e8 ldr r12, [sp, #0x28] */
/* @0x001e88ec mvn r3, #0 */
/* @0x001e88f0 cmp r12, #0 */
/* @0x001e88f4 add r12, r5, #12 */
/* @0x001e88f8 mov r4, r0 */
/* @0x001e88fc str r2, [r0, #0x4] */
/* @0x001e8900 ldr r0, [r5, #0x8] */
/* @0x001e8904 str r3, [r4, #0xc] */
/* @0x001e8908 str r0, [r4, #0x8] */
/* @0x001e890c beq 0x1e8950 <_ZN7CSprite12BuildSWFDataEPcii+0x5c4> */
/* @0x001e8910 ldr lr, [sp, #0x2c] */
/* @0x001e8914 ldr r2, [lr, #0x7c] */
/* @0x001e8918 ldr r3, [r2] */
/* @0x001e891c ldr r3, [r3, #0x4] */
/* @0x001e8920 cmp r0, r3 */
/* @0x001e8924 movne r3, #0 */
/* @0x001e8928 ldrne lr, [sp, #0x28] */
/* @0x001e892c bne 0x1e8944 <_ZN7CSprite12BuildSWFDataEPcii+0x5b8> */
/* @0x001e8930 b 0x1e89d0 <_ZN7CSprite12BuildSWFDataEPcii+0x644> */
/* @0x001e8934 ldr r1, [r2, #0x4]! */
/* @0x001e8938 ldr r1, [r1, #0x4] */
/* @0x001e893c cmp r0, r1 */
/* @0x001e8940 beq 0x1e89d4 <_ZN7CSprite12BuildSWFDataEPcii+0x648> */
/* @0x001e8944 add r3, r3, #1 */
/* @0x001e8948 cmp r3, lr */
/* @0x001e894c bne 0x1e8934 <_ZN7CSprite12BuildSWFDataEPcii+0x5a8> */
/* @0x001e8950 add r2, sp, #164 */
/* @0x001e8954 add r0, r12, #36 */
/* @0x001e8958 mov r3, r12 */
/* @0x001e895c ldr r1, [r3], #4 */
/* @0x001e8960 cmp r3, r0 */
/* @0x001e8964 str r1, [r2], #4 */
/* @0x001e8968 bne 0x1e895c <_ZN7CSprite12BuildSWFDataEPcii+0x5d0> */
/* @0x001e896c ldr r2, [sp, #0xa4] */
/* @0x001e8970 mov r3, #1065353216 */
/* @0x001e8974 str r3, [r4, #0x4c] */
/* @0x001e8978 add r5, r5, #48 */
/* @0x001e897c str r3, [r4, #0x38] */
/* @0x001e8980 vstr s16, [r4, #72] */
/* @0x001e8984 str r2, [r4, #0x10] */
/* @0x001e8988 vstr s16, [r4, #60] */
/* @0x001e898c ldr r2, [sp, #0xa8] */
/* @0x001e8990 vstr s16, [r4, #52] */
/* @0x001e8994 ldr r3, [sp, #0xb8] */
/* @0x001e8998 vstr s16, [r4, #48] */
/* @0x001e899c vstr s16, [r4, #44] */
/* @0x001e89a0 vstr s16, [r4, #40] */
/* @0x001e89a4 str r2, [r4, #0x20] */
/* @0x001e89a8 vstr s16, [r4, #28] */
/* @0x001e89ac ldr r2, [sp, #0xac] */
/* @0x001e89b0 vstr s16, [r4, #24] */
/* @0x001e89b4 str r3, [r4, #0x44] */
/* @0x001e89b8 str r2, [r4, #0x40] */
/* @0x001e89bc ldr r2, [sp, #0xb0] */
/* @0x001e89c0 str r2, [r4, #0x14] */
/* @0x001e89c4 ldr r2, [sp, #0xb4] */
/* @0x001e89c8 str r2, [r4, #0x24] */
/* @0x001e89cc b 0x1e8820 <_ZN7CSprite12BuildSWFDataEPcii+0x494> */
/* @0x001e89d0 mov r3, #0 */
/* @0x001e89d4 str r3, [r4, #0xc] */
/* @0x001e89d8 b 0x1e8950 <_ZN7CSprite12BuildSWFDataEPcii+0x5c4> */

/* ── 子记录尾：n2 个 4 B 元素，从流里按大端读进 [+0x08] 数组 ───────────────────────
 *   r3 = [r6+8] - 4（0x1e89f0 `sub r3,r3,#4`，配合 `str r2,[r3,#4]!` 的预减寻址），
 *   循环终点 r7 = r5 + 4·n2（0x1e89ec `add r7,r5,r7,lsl #2`）。
 *   ★ n2==0 走 0x1e8fe8（`mov r7,r5` 把游标复位）——这是唯一一处「游标不动」的出口。
 */
/* @0x001e89dc ldr r7, [r6, #0x14] */
/* @0x001e89e0 cmp r7, #0 */
/* @0x001e89e4 beq 0x1e8fe8 <_ZN7CSprite12BuildSWFDataEPcii+0xc5c> */
/* @0x001e89e8 ldr r3, [r6, #0x8] */
/* @0x001e89ec add r7, r5, r7, lsl #2 */
/* @0x001e89f0 sub r3, r3, #4 */
/* @0x001e89f4 ldrb r2, [r5, #0x2] */
/* @0x001e89f8 add r5, r5, #4 */
/* @0x001e89fc ldrb r12, [r5, #-0x3] */
/* @0x001e8a00 ldrb r0, [r5, #-0x4] */
/* @0x001e8a04 ldrb r1, [r5, #-0x1] */
/* @0x001e8a08 lsl r2, r2, #16 */
/* @0x001e8a0c orr r2, r2, r12, lsl #8 */
/* @0x001e8a10 cmp r5, r7 */
/* @0x001e8a14 orr r2, r2, r0 */
/* @0x001e8a18 orr r2, r2, r1, lsl #24 */
/* @0x001e8a1c str r2, [r3, #0x4]! */
/* @0x001e8a20 bne 0x1e89f4 <_ZN7CSprite12BuildSWFDataEPcii+0x668> */

/* ── 84 B 记录段的闸：n3==0 就跳过整段（0x1e8a2c beq 0x1e8d30）────────────────────
 *   ★ 到 0x1e8d30 后直接做子记录 i++ 与下一项判定，说明 84 B 记录是**可选**层。
 */
/* @0x001e8a24 ldr r3, [r6, #0xc] */
/* @0x001e8a28 cmp r3, #0 */
/* @0x001e8a2c beq 0x1e8d30 <_ZN7CSprite12BuildSWFDataEPcii+0x9a4> */

/* ── 84 B 记录循环前导：装载 6 个池字/串地址，r5 是「记录内偏移累加器」 ────────────────
 *   r5 = 0（0x1e8a34），r8 = 0（子记录下标），r9 = [sp+0x44]（version）。
 *   ★ 0x1e8a58 `ldr r9,[sp+0x44]` 之后 0x1e8a80 `cmp r9,#4` / 0x1e8ad0 `cmp r9,#5` ——
 *     版本号在这三个档位上直接决定读多少字（见下块）。
 */
/* @0x001e8a30 ldr r9, [pc, #-0x1dc] */
/* @0x001e8a34 mov r5, #0 */
/* @0x001e8a38 ldr r10, [pc, #-0x1e0] */
/* @0x001e8a3c mov r8, r5 */
/* @0x001e8a40 ldr r11, [pc, #-0x1e4] */
/* @0x001e8a44 add r9, pc, r9 */
/* @0x001e8a48 ldr r4, [pc, #-0x1e8] */
/* @0x001e8a4c add r10, pc, r10 */
/* @0x001e8a50 str r9, [sp, #0x40] */
/* @0x001e8a54 add r11, pc, r11 */
/* @0x001e8a58 ldr r9, [sp, #0x44] */
/* @0x001e8a5c add r4, pc, r4 */
/* @0x001e8a60 ldr r12, [pc, #-0x1fc] */
/* @0x001e8a64 str r4, [sp, #0x30] */
/* @0x001e8a68 ldr r4, [pc, #-0x200] */
/* @0x001e8a6c add r12, pc, r12 */
/* @0x001e8a70 str r12, [sp, #0x34] */
/* @0x001e8a74 add r4, pc, r4 */
/* @0x001e8a78 str r4, [sp, #0x3c] */

/* ── 84 B 记录头：3 个透传字 + 9 个计数，计数个数随 version 变长 ────────────────────────
 *   r4 = [r6+0x00] + r5（0x1e8a7c/0x1e8a88），即第 i 条 84 B 记录的基址。
 *   [+0x24..+0x2c] ← 记录[0..2]；计数落 [+0x30..+0x50]：
 *     version ≤ 4 → 5 个（+0x30..+0x40），然后 0x1e8d54 把 +0x44/+0x48/+0x4c/+0x50 清 0、游标 +32
 *     version = 5 → 8 个（+0x30..+0x4c），0x1e9724 只把 +0x50 补读、游标 +40
 *     version ≥ 6 → 9 个（+0x30..+0x50），游标 +48
 *   ★ 9 个计数的读点：0x1e8a84(+0x30) 0x1e8a90(+0x34) 0x1e8a98(+0x38) 0x1e8aa0(+0x3c)
 *     0x1e8aa8(+0x40) 0x1e8ad4(+0x44) 0x1e8ad8(+0x48) 0x1e8af0(+0x4c) 0x1e8afc(+0x50)。
 *   ★ 0x1e8aec `add r7,r7,#48` 与 0x1e8af4 `ldr r3,[r7,#-4]` 的方向说明：先推进再回读最后一字。
 */
/* @0x001e8a7c ldr r4, [r6] */
/* @0x001e8a80 cmp r9, #4——version ≤ 4：记录头只 5 个计数 */
/* @0x001e8a84 ldr r3, [r7] */
/* @0x001e8a88 add r4, r4, r5 */
/* @0x001e8a8c str r3, [r4, #0x24] */
/* @0x001e8a90 ldr r3, [r7, #0x4] */
/* @0x001e8a94 str r3, [r4, #0x28] */
/* @0x001e8a98 ldr r3, [r7, #0x8] */
/* @0x001e8a9c str r3, [r4, #0x2c] */
/* @0x001e8aa0 ldr r0, [r7, #0xc] */
/* @0x001e8aa4 str r0, [r4, #0x30] */
/* @0x001e8aa8 ldr r3, [r7, #0x10] */
/* @0x001e8aac str r3, [r4, #0x34] */
/* @0x001e8ab0 ldr r3, [r7, #0x14] */
/* @0x001e8ab4 str r3, [r4, #0x38] */
/* @0x001e8ab8 ldr r3, [r7, #0x18] */
/* @0x001e8abc str r3, [r4, #0x3c] */
/* @0x001e8ac0 ldr r3, [r7, #0x1c] */
/* @0x001e8ac4 str r3, [r4, #0x40] */
/* @0x001e8ac8 bls 0x1e8d54 <_ZN7CSprite12BuildSWFDataEPcii+0x9c8> */
/* @0x001e8acc ldr r3, [r7, #0x20] */
/* @0x001e8ad0 cmp r9, #5——version == 5：8 个计数 */
/* @0x001e8ad4 str r3, [r4, #0x44] */
/* @0x001e8ad8 ldr r3, [r7, #0x24] */
/* @0x001e8adc str r3, [r4, #0x48] */
/* @0x001e8ae0 beq 0x1e9724 <_ZN7CSprite12BuildSWFDataEPcii+0x1398> */
/* @0x001e8ae4 ldr r3, [r7, #0x28] */
/* @0x001e8ae8 cmp r0, #0 */
/* @0x001e8aec add r7, r7, #48 */
/* @0x001e8af0 str r3, [r4, #0x4c] */
/* @0x001e8af4 ldr r3, [r7, #-0x4] */
/* @0x001e8af8 streq r0, [r4] */
/* @0x001e8afc str r3, [r4, #0x50] */
/* @0x001e8b00 bne 0x1e8d7c <_ZN7CSprite12BuildSWFDataEPcii+0x9f0> */
/* @0x001e8b04 ldr r0, [r4, #0x34] */
/* @0x001e8b08 cmp r0, #0 */
/* @0x001e8b0c streq r0, [r4, #0x4] */
/* @0x001e8b10 bne 0x1e8da4 <_ZN7CSprite12BuildSWFDataEPcii+0xa18> */
/* @0x001e8b14 ldr r3, [r4, #0x38] */
/* @0x001e8b18 cmp r3, #0 */
/* @0x001e8b1c streq r3, [r4, #0x8] */
/* @0x001e8b20 bne 0x1e8dcc <_ZN7CSprite12BuildSWFDataEPcii+0xa40> */
/* @0x001e8b24 ldr r0, [r4, #0x3c] */
/* @0x001e8b28 cmp r0, #0 */
/* @0x001e8b2c streq r0, [r4, #0xc] */
/* @0x001e8b30 bne 0x1e8df8 <_ZN7CSprite12BuildSWFDataEPcii+0xa6c> */
/* @0x001e8b34 ldr r3, [r4, #0x40] */
/* @0x001e8b38 cmp r3, #0 */
/* @0x001e8b3c streq r3, [r4, #0x10] */
/* @0x001e8b40 bne 0x1e8e20 <_ZN7CSprite12BuildSWFDataEPcii+0xa94> */
/* @0x001e8b44 ldr r0, [r4, #0x44] */
/* @0x001e8b48 cmp r0, #0 */
/* @0x001e8b4c streq r0, [r4, #0x14] */
/* @0x001e8b50 bne 0x1e8e4c <_ZN7CSprite12BuildSWFDataEPcii+0xac0> */
/* @0x001e8b54 ldr r0, [r4, #0x48] */
/* @0x001e8b58 cmp r0, #0 */
/* @0x001e8b5c streq r0, [r4, #0x18] */
/* @0x001e8b60 bne 0x1e8e74 <_ZN7CSprite12BuildSWFDataEPcii+0xae8> */
/* @0x001e8b64 ldr r0, [r4, #0x4c] */
/* @0x001e8b68 cmp r0, #0 */
/* @0x001e8b6c streq r0, [r4, #0x1c] */
/* @0x001e8b70 bne 0x1e8ea0 <_ZN7CSprite12BuildSWFDataEPcii+0xb14> */
/* @0x001e8b74 ldr r2, [r4, #0x50] */
/* @0x001e8b78 cmp r2, #0 */
/* @0x001e8b7c streq r2, [r4, #0x20] */
/* @0x001e8b80 bne 0x1e8ecc <_ZN7CSprite12BuildSWFDataEPcii+0xb40> */

/* ── 九组数组复制驱动：每次 (count, dst, 元素宽度) 三段式，同构九遍 ─────────────────────
 *   模式：`ldr count,[r4,#0x3N]` → 若 0 跳过（lsls 置零标志）→ `ldr dst,[r4,#0xM]` → 逐元素拷 →
 *   游标 r7 前进。**count 不是元素个数**，而是「一份记录」的个数；每份在源里占 2 个或 3 个字：
 *     +0x30 → [+0x00]  目标 8c B / 步 4 B ⇒ 2c 个 int32，源 8c B（0x1e8b94 `lsl #3`、0x1e8bb0）
 *     +0x34 → [+0x04]  目标 4c B / 步 2 B ⇒ 2c 个 int16（strh），源 8c B（0x1e8bd0、0x1e8bdc）
 *     +0x38 → [+0x08]  目标 6c B / 步 2 B ⇒ 3c 个 int16，源 12c B（0x1e8be4 的 3c、0x1e8c08）
 *     +0x3c → [+0x0c]  2c 个 int32，源 8c B（0x1e8c18/0x1e8c38）
 *     +0x40 → [+0x10]  3c 个 int16，源 12c B（0x1e8c40/0x1e8c64）
 *     +0x44 → [+0x14]  2c 个 int16，源 8c B（0x1e8c7c/0x1e8c90）
 *     +0x48 → [+0x18]  2c 个 int32，源 8c B（0x1e8ca4/0x1e8cc0）
 *     +0x4c → [+0x1c]  2c 个 int16，源 8c B（0x1e8cd8/0x1e8cec）
 *     (+0x10) → [+0x20] 4 B → 8 B（最后一组用子记录的 n1 = r2，见 0x1e8cf0 `lsls r3,r2,#1`）
 *   ★ 九组的「跳过」出口都 `beq` 到下一组头部，游标不动 ⇒ 空数组不占流字节。
 *   ★ 第九组的计数不是来自 84 B 记录，而是 0x1e8824 `ldr r2,[r6+0x10]`（子记录的 n1），
 *     这是本驱动里唯一的例外，也是「+0x20 数组与 [+0x04] 数组同长」的证据。
 */
/* @0x001e8b84 ldr r12, [r4, #0x30] */
/* @0x001e8b88 lsls lr, r12, #1——lsls lr,r12,#1：count==0 的零标志 */
/* @0x001e8b8c beq 0x1e8bb4 <_ZN7CSprite12BuildSWFDataEPcii+0x828> */
/* @0x001e8b90 ldr r3, [r4] */
/* @0x001e8b94 lsl r12, r12, #3 */
/* @0x001e8b98 mov r1, r7 */
/* @0x001e8b9c add r0, r3, r12 */
/* @0x001e8ba0 ldr lr, [r1], #4 */
/* @0x001e8ba4 str lr, [r3], #4 */
/* @0x001e8ba8 cmp r3, r0 */
/* @0x001e8bac bne 0x1e8ba0 <_ZN7CSprite12BuildSWFDataEPcii+0x814> */
/* @0x001e8bb0 add r7, r7, r12 */
/* @0x001e8bb4 ldr r12, [r4, #0x34] */
/* @0x001e8bb8 lsls lr, r12, #1 */
/* @0x001e8bbc beq 0x1e8be0 <_ZN7CSprite12BuildSWFDataEPcii+0x854> */
/* @0x001e8bc0 ldr r3, [r4, #0x4] */
/* @0x001e8bc4 sub r1, r7, #4 */
/* @0x001e8bc8 add r12, r3, r12, lsl #2 */
/* @0x001e8bcc ldr r0, [r1, #0x4]! */
/* @0x001e8bd0 strh r0, [r3], #2——strh：源 4 B/项 → 目标 16 位/项 */
/* @0x001e8bd4 cmp r3, r12 */
/* @0x001e8bd8 bne 0x1e8bcc <_ZN7CSprite12BuildSWFDataEPcii+0x840> */
/* @0x001e8bdc add r7, r7, lr, lsl #2 */
/* @0x001e8be0 ldr lr, [r4, #0x38] */
/* @0x001e8be4 adds lr, lr, lr, lsl #1 */
/* @0x001e8be8 beq 0x1e8c0c <_ZN7CSprite12BuildSWFDataEPcii+0x880> */
/* @0x001e8bec ldr r3, [r4, #0x8] */
/* @0x001e8bf0 sub r1, r7, #4 */
/* @0x001e8bf4 add r12, r3, lr, lsl #1——目标 6 B/项（3 个 short） */
/* @0x001e8bf8 ldr r0, [r1, #0x4]! */
/* @0x001e8bfc strh r0, [r3], #2 */
/* @0x001e8c00 cmp r3, r12 */
/* @0x001e8c04 bne 0x1e8bf8 <_ZN7CSprite12BuildSWFDataEPcii+0x86c> */
/* @0x001e8c08 add r7, r7, lr, lsl #2 */
/* @0x001e8c0c ldr r12, [r4, #0x3c] */
/* @0x001e8c10 lsls r0, r12, #1 */
/* @0x001e8c14 beq 0x1e8c3c <_ZN7CSprite12BuildSWFDataEPcii+0x8b0> */
/* @0x001e8c18 ldr r3, [r4, #0xc] */
/* @0x001e8c1c lsl r12, r12, #3 */
/* @0x001e8c20 mov r1, r7 */
/* @0x001e8c24 add r0, r3, r12 */
/* @0x001e8c28 ldr lr, [r1], #4 */
/* @0x001e8c2c str lr, [r3], #4 */
/* @0x001e8c30 cmp r3, r0 */
/* @0x001e8c34 bne 0x1e8c28 <_ZN7CSprite12BuildSWFDataEPcii+0x89c> */
/* @0x001e8c38 add r7, r7, r12 */
/* @0x001e8c3c ldr lr, [r4, #0x40] */
/* @0x001e8c40 adds lr, lr, lr, lsl #1 */
/* @0x001e8c44 beq 0x1e8c68 <_ZN7CSprite12BuildSWFDataEPcii+0x8dc> */
/* @0x001e8c48 ldr r3, [r4, #0x10] */
/* @0x001e8c4c sub r1, r7, #4 */
/* @0x001e8c50 add r12, r3, lr, lsl #1 */
/* @0x001e8c54 ldr r0, [r1, #0x4]! */
/* @0x001e8c58 strh r0, [r3], #2 */
/* @0x001e8c5c cmp r3, r12 */
/* @0x001e8c60 bne 0x1e8c54 <_ZN7CSprite12BuildSWFDataEPcii+0x8c8> */
/* @0x001e8c64 add r7, r7, lr, lsl #2 */
/* @0x001e8c68 ldr r12, [r4, #0x44] */
/* @0x001e8c6c lsls lr, r12, #1 */
/* @0x001e8c70 beq 0x1e8c94 <_ZN7CSprite12BuildSWFDataEPcii+0x908> */
/* @0x001e8c74 ldr r3, [r4, #0x14] */
/* @0x001e8c78 sub r1, r7, #4 */
/* @0x001e8c7c add r12, r3, r12, lsl #2 */
/* @0x001e8c80 ldr r0, [r1, #0x4]! */
/* @0x001e8c84 strh r0, [r3], #2 */
/* @0x001e8c88 cmp r3, r12 */
/* @0x001e8c8c bne 0x1e8c80 <_ZN7CSprite12BuildSWFDataEPcii+0x8f4> */
/* @0x001e8c90 add r7, r7, lr, lsl #2 */
/* @0x001e8c94 ldr r12, [r4, #0x48] */
/* @0x001e8c98 lsls r1, r12, #1 */
/* @0x001e8c9c beq 0x1e8cc4 <_ZN7CSprite12BuildSWFDataEPcii+0x938> */
/* @0x001e8ca0 ldr r3, [r4, #0x18] */
/* @0x001e8ca4 lsl r12, r12, #3 */
/* @0x001e8ca8 mov r1, r7 */
/* @0x001e8cac add r0, r12, r3 */
/* @0x001e8cb0 ldr lr, [r1], #4 */
/* @0x001e8cb4 str lr, [r3], #4 */
/* @0x001e8cb8 cmp r3, r0 */
/* @0x001e8cbc bne 0x1e8cb0 <_ZN7CSprite12BuildSWFDataEPcii+0x924> */
/* @0x001e8cc0 add r7, r7, r12 */
/* @0x001e8cc4 ldr r12, [r4, #0x4c] */
/* @0x001e8cc8 lsls lr, r12, #1 */
/* @0x001e8ccc beq 0x1e8cf0 <_ZN7CSprite12BuildSWFDataEPcii+0x964> */
/* @0x001e8cd0 ldr r3, [r4, #0x1c] */
/* @0x001e8cd4 sub r1, r7, #4 */
/* @0x001e8cd8 add r12, r3, r12, lsl #2 */
/* @0x001e8cdc ldr r0, [r1, #0x4]! */
/* @0x001e8ce0 strh r0, [r3], #2 */
/* @0x001e8ce4 cmp r3, r12 */
/* @0x001e8ce8 bne 0x1e8cdc <_ZN7CSprite12BuildSWFDataEPcii+0x950> */
/* @0x001e8cec add r7, r7, lr, lsl #2 */
/* @0x001e8cf0 lsls r3, r2, #1——第九组用子记录的 n1（r2），不是 84 B 记录的计数 */
/* @0x001e8cf4 beq 0x1e8d1c <_ZN7CSprite12BuildSWFDataEPcii+0x990> */
/* @0x001e8cf8 ldr r3, [r4, #0x20] */
/* @0x001e8cfc lsl r2, r2, #3 */
/* @0x001e8d00 mov r1, r7 */
/* @0x001e8d04 add r12, r2, r3 */
/* @0x001e8d08 ldr r0, [r1], #4 */
/* @0x001e8d0c str r0, [r3], #4 */
/* @0x001e8d10 cmp r3, r12 */
/* @0x001e8d14 bne 0x1e8d08 <_ZN7CSprite12BuildSWFDataEPcii+0x97c> */
/* @0x001e8d18 add r7, r7, r2 */
/* @0x001e8d1c ldr r3, [r6, #0xc] */
/* @0x001e8d20 add r8, r8, #1 */
/* @0x001e8d24 add r5, r5, #84——84 B 步长 */
/* @0x001e8d28 cmp r3, r8 */
/* @0x001e8d2c bhi 0x1e8a7c <_ZN7CSprite12BuildSWFDataEPcii+0x6f0> */

/* ── 子记录收尾：i++ 与 i<n3 判定；回边 0x1e8d50 → 0x1e861c ─────────────────────────
 *   [sp+0x38]++，与 [item+0x1c] 比（0x1e8d44 `cmp r3,r5` + `bls 0x1e84c0`）。
 *   ★ 0x1e8d4c 回填 r3 = [item+8] 后跳回 0x1e861c，是唯一的循环回边。
 */
/* @0x001e8d30 ldr r4, [sp, #0x48] */
/* @0x001e8d34 ldr r5, [sp, #0x38] */
/* @0x001e8d38 ldr r3, [r4, #0x1c] */
/* @0x001e8d3c add r5, r5, #1 */
/* @0x001e8d40 str r5, [sp, #0x38] */
/* @0x001e8d44 cmp r3, r5 */
/* @0x001e8d48 bls 0x1e84c0 <_ZN7CSprite12BuildSWFDataEPcii+0x134> */
/* @0x001e8d4c ldr r3, [r4, #0x8] */
/* @0x001e8d50 b 0x1e861c <_ZN7CSprite12BuildSWFDataEPcii+0x290> */

/* ── 九组数组分配（version ≤ 4 的五组补零也在本块）─────────────────────────────────
 *   每组的形状都是 `ldr count,[r4,#0x3N]` → `cmp #0` → `streq 0,[r4,#0xM]` 或 Alloc(count×宽度)。
 *   Alloc 尺寸算式（逐条可核）：
 *     [+0x00] ← [+0x30]×8     0x1e8d7c `lsl r0,r0,#3`
 *     [+0x04] ← [+0x34]×4     0x1e8da8 `lsl r0,r0,#2`
 *     [+0x08] ← [+0x38]×6     0x1e8dcc `add r0,r3,r3,lsl#1` + 0x1e8ddc `lsl r0,r0,r3`（r3=1）
 *     [+0x0c] ← [+0x3c]×8     0x1e8dfc `lsl r0,r0,#3`
 *     [+0x10] ← [+0x40]×6     0x1e8e20 同 [+0x08] 的算式
 *     [+0x14] ← [+0x44]×4     0x1e8e4c `lsl r0,r0,#2`
 *     [+0x18] ← [+0x48]×8     0x1e8e78 `lsl r0,r0,#3`
 *     [+0x1c] ← [+0x4c]×4     0x1e8ea8 `lsl r0,r0,#2`
 *     [+0x20] ← [+0x50]×8     0x1e8ed0 `lsl r0,r2,#3`
 *   ★ 0x1e8d54..0x1e8d78 是 version ≤ 4 的补齐：+0x44/+0x48/+0x4c/+0x50 全 0，游标 +32。
 *   ★ 全块只有一个入口值被复用：r0 在 0x1e8ef0 前既是 count 又是 Alloc 返回值，注意 0x1e8f40
 *     在 Alloc 之后重读 [r6+0x14]（调用破坏现场）。
 */
/* @0x001e8d54 add r7, r7, #32 */
/* @0x001e8d58 mov r3, #0 */
/* @0x001e8d5c str r3, [r4, #0x44] */
/* @0x001e8d60 str r3, [r4, #0x48] */
/* @0x001e8d64 cmp r0, #0 */
/* @0x001e8d68 mov r3, #0 */
/* @0x001e8d6c streq r0, [r4] */
/* @0x001e8d70 str r3, [r4, #0x4c] */
/* @0x001e8d74 str r3, [r4, #0x50] */
/* @0x001e8d78 beq 0x1e8b04 <_ZN7CSprite12BuildSWFDataEPcii+0x778> */
/* @0x001e8d7c lsl r0, r0, #3——Alloc(8×count) */
/* @0x001e8d80 ldr r1, [sp, #0x40] */
/* @0x001e8d84 movw r2, #0x1137 */
/* @0x001e8d88 mov r3, #1 */
/* @0x001e8d8c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x001e8d90 str r0, [r4] */
/* @0x001e8d94 ldr r0, [r4, #0x34] */
/* @0x001e8d98 cmp r0, #0 */
/* @0x001e8d9c streq r0, [r4, #0x4] */
/* @0x001e8da0 beq 0x1e8b14 <_ZN7CSprite12BuildSWFDataEPcii+0x788> */
/* @0x001e8da4 mov r3, #1 */
/* @0x001e8da8 lsl r0, r0, #2 */
/* @0x001e8dac mov r1, r10 */
/* @0x001e8db0 movw r2, #0x113c */
/* @0x001e8db4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x001e8db8 ldr r3, [r4, #0x38] */
/* @0x001e8dbc cmp r3, #0 */
/* @0x001e8dc0 streq r3, [r4, #0x8] */
/* @0x001e8dc4 str r0, [r4, #0x4] */
/* @0x001e8dc8 beq 0x1e8b24 <_ZN7CSprite12BuildSWFDataEPcii+0x798> */
/* @0x001e8dcc add r0, r3, r3, lsl #1 */
/* @0x001e8dd0 mov r1, r11 */
/* @0x001e8dd4 mov r3, #1 */
/* @0x001e8dd8 movw r2, #0x1141 */
/* @0x001e8ddc lsl r0, r0, r3——Alloc(6×count)：3 个 short */
/* @0x001e8de0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x001e8de4 str r0, [r4, #0x8] */
/* @0x001e8de8 ldr r0, [r4, #0x3c] */
/* @0x001e8dec cmp r0, #0 */
/* @0x001e8df0 streq r0, [r4, #0xc] */
/* @0x001e8df4 beq 0x1e8b34 <_ZN7CSprite12BuildSWFDataEPcii+0x7a8> */
/* @0x001e8df8 mov r3, #1 */
/* @0x001e8dfc lsl r0, r0, #3 */
/* @0x001e8e00 ldr r1, [sp, #0x30] */
/* @0x001e8e04 mov r2, #70 */
/* @0x001e8e08 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x001e8e0c ldr r3, [r4, #0x40] */
/* @0x001e8e10 cmp r3, #0 */
/* @0x001e8e14 streq r3, [r4, #0x10] */
/* @0x001e8e18 str r0, [r4, #0xc] */
/* @0x001e8e1c beq 0x1e8b44 <_ZN7CSprite12BuildSWFDataEPcii+0x7b8> */
/* @0x001e8e20 add r0, r3, r3, lsl #1 */
/* @0x001e8e24 ldr r1, [sp, #0x34] */
/* @0x001e8e28 mov r3, #1 */
/* @0x001e8e2c mov r2, #70 */
/* @0x001e8e30 lsl r0, r0, r3 */
/* @0x001e8e34 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x001e8e38 str r0, [r4, #0x10] */
/* @0x001e8e3c ldr r0, [r4, #0x44] */
/* @0x001e8e40 cmp r0, #0 */
/* @0x001e8e44 streq r0, [r4, #0x14] */
/* @0x001e8e48 beq 0x1e8b54 <_ZN7CSprite12BuildSWFDataEPcii+0x7c8> */
/* @0x001e8e4c lsl r0, r0, #2 */
/* @0x001e8e50 ldr r1, [sp, #0x3c] */
/* @0x001e8e54 mov r2, #70 */
/* @0x001e8e58 mov r3, #1 */
/* @0x001e8e5c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x001e8e60 str r0, [r4, #0x14] */
/* @0x001e8e64 ldr r0, [r4, #0x48] */
/* @0x001e8e68 cmp r0, #0 */
/* @0x001e8e6c streq r0, [r4, #0x18] */
/* @0x001e8e70 beq 0x1e8b64 <_ZN7CSprite12BuildSWFDataEPcii+0x7d8> */
/* @0x001e8e74 ldr r1, [pc, #-0x608] */
/* @0x001e8e78 lsl r0, r0, #3 */
/* @0x001e8e7c mov r2, #70 */
/* @0x001e8e80 mov r3, #1 */
/* @0x001e8e84 add r1, pc, r1 */
/* @0x001e8e88 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x001e8e8c str r0, [r4, #0x18] */
/* @0x001e8e90 ldr r0, [r4, #0x4c] */
/* @0x001e8e94 cmp r0, #0 */
/* @0x001e8e98 streq r0, [r4, #0x1c] */
/* @0x001e8e9c beq 0x1e8b74 <_ZN7CSprite12BuildSWFDataEPcii+0x7e8> */
/* @0x001e8ea0 ldr r1, [pc, #-0x630] */
/* @0x001e8ea4 mov r2, #70 */
/* @0x001e8ea8 lsl r0, r0, #2 */
/* @0x001e8eac mov r3, #1 */
/* @0x001e8eb0 add r1, pc, r1 */
/* @0x001e8eb4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x001e8eb8 ldr r2, [r4, #0x50] */
/* @0x001e8ebc cmp r2, #0 */
/* @0x001e8ec0 streq r2, [r4, #0x20] */
/* @0x001e8ec4 str r0, [r4, #0x1c] */
/* @0x001e8ec8 beq 0x1e8b84 <_ZN7CSprite12BuildSWFDataEPcii+0x7f8> */
/* @0x001e8ecc ldr r1, [pc, #-0x658] */
/* @0x001e8ed0 lsl r0, r2, #3 */
/* @0x001e8ed4 mov r3, #1 */
/* @0x001e8ed8 mov r2, #70 */
/* @0x001e8edc add r1, pc, r1 */
/* @0x001e8ee0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x001e8ee4 ldr r2, [r4, #0x50] */
/* @0x001e8ee8 str r0, [r4, #0x20] */
/* @0x001e8eec b 0x1e8b84 <_ZN7CSprite12BuildSWFDataEPcii+0x7f8> */

/* ── 子记录三指针的分配（n3/n1/n2 三条，按 84/4/4 B）───────────────────────────────
 *   0x1e8ef0 `mov r0,#84` + `mul r0,r0,r3`（r3 = [r6+0xc] = n3）→ [+0x00]；
 *   0x1e8f10 `lsl r0,r3,#2`（r3 = [r6+0x14] = n2）→ [+0x08]；
 *   0x1e8f2c `lsl r0,r0,#2`（r0 = [r6+0x10] 由 0x1e8624 带来 = n1）→ [+0x04]。
 *   ★ 三条 Alloc 的 file/line 分别是 [sp+0x6c]:0x1057、[sp+0x78]:0x1052、[sp+0x74]:0x104d ——
 *     行号随语句递增，说明源码里这三行挨着（可作源码还原的排序线索）。
 */
/* @0x001e8ef0 mov r0, #84——Alloc(84×n3) → 子记录 [+0x00] */
/* @0x001e8ef4 ldr r1, [sp, #0x6c] */
/* @0x001e8ef8 mul r0, r0, r3 */
/* @0x001e8efc movw r2, #0x1057 */
/* @0x001e8f00 mov r3, #1 */
/* @0x001e8f04 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x001e8f08 str r0, [r6] */
/* @0x001e8f0c b 0x1e866c <_ZN7CSprite12BuildSWFDataEPcii+0x2e0> */
/* @0x001e8f10 lsl r0, r3, #2 */
/* @0x001e8f14 ldr r1, [sp, #0x78] */
/* @0x001e8f18 movw r2, #0x1052 */
/* @0x001e8f1c mov r3, #1 */
/* @0x001e8f20 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x001e8f24 str r0, [r6, #0x8] */
/* @0x001e8f28 b 0x1e865c <_ZN7CSprite12BuildSWFDataEPcii+0x2d0> */
/* @0x001e8f2c mov r3, #1 */
/* @0x001e8f30 lsl r0, r0, #2 */
/* @0x001e8f34 ldr r1, [sp, #0x74] */
/* @0x001e8f38 movw r2, #0x104d */
/* @0x001e8f3c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x001e8f40 ldr r3, [r6, #0x14] */
/* @0x001e8f44 str r0, [r6, #0x4] */
/* @0x001e8f48 b 0x1e8650 <_ZN7CSprite12BuildSWFDataEPcii+0x2c4> */

/* ── type 2 的位图装载：三个计数 + 三块像素 → SetupBitmapTexture（12 形参）─────────────
 *   r2=[r7+0x14]、lr=[r7+0x18]、r6=[r7+0x1c] 三个计数；r12 = r7+32 = 数据起点。
 *   四个平面指针按「长度是否为 0」三态求出（0x1e8f74/78/7c 与 84/88/90/94/98/a4）：
 *     p0 = n0 ? 起点 : 0；p1 = 起点+n0；p2 = p1+n1；p3 = p2+n2；块间 align4（0x1e8fac/0x1e8fb4）。
 *   栈实参 8 字：sp+0x00=r9、+0x04=版本、+0x08=lr、+0x0c=r6、+0x10=r5(平面0 或 0)、+0x14=r0、
 *     +0x18=r4、+0x1c=[sp+0x60](data 基址)、+0x20=[sp+0x58]；r0=this、r1=&SWF_Bitmap（0x1e8524
 *     的 `mov r1,r0` 已经把 Alloc 返回值搬过来）、r2=r8、r3=1。
 *   ★ 12 个形参 = 6 个 int（r2,r3 + 栈 4 个）+ 4 个 uchar* + 1 个 uint，与符号
 *     ...EP10SWF_BitmapiiiiiiPhS2_S2_S2_j 的 6 个 i / 4 个 Ph / 1 个 j 一一对上。
 *   ★ 9 个栈字里 sp+0x10 由 0x1e8f9c 写（`str r5,[sp,#0x10]`，r5 = 平面0 或 0），
 *     不是空洞；漏看这一条会以为实参表错位。
 */
/* @0x001e8f4c mvn r2, #0 */
/* @0x001e8f50 str r2, [r0, #0x10] */
/* @0x001e8f54 str r2, [r0, #0x8] */
/* @0x001e8f58 mov r5, #0 */
/* @0x001e8f5c ldr r2, [r7, #0x14] */
/* @0x001e8f60 add r12, r7, #32 */
/* @0x001e8f64 ldr lr, [r7, #0x18] */
/* @0x001e8f68 cmp r2, r5 */
/* @0x001e8f6c ldr r6, [r7, #0x1c] */
/* @0x001e8f70 str r5, [r0, #0xc] */
/* @0x001e8f74 movle r0, r12 */
/* @0x001e8f78 addgt r0, r12, r2 */
/* @0x001e8f7c movgt r5, r12 */
/* @0x001e8f80 cmp lr, #0 */
/* @0x001e8f84 add r7, r2, lr */
/* @0x001e8f88 addgt r4, r0, lr */
/* @0x001e8f8c add r7, r7, r6 */
/* @0x001e8f90 movle r4, r0 */
/* @0x001e8f94 movle r0, #0 */
/* @0x001e8f98 cmp r6, #0 */
/* @0x001e8f9c str r5, [sp, #0x10] */
/* @0x001e8fa0 ldr r5, [sp, #0x60] */
/* @0x001e8fa4 movle r4, #0 */
/* @0x001e8fa8 str r4, [sp, #0x18] */
/* @0x001e8fac add r4, r7, #3 */
/* @0x001e8fb0 str r2, [sp, #0x4] */
/* @0x001e8fb4 bic r4, r4, #3 */
/* @0x001e8fb8 str r0, [sp, #0x14] */
/* @0x001e8fbc add r7, r12, r4 */
/* @0x001e8fc0 ldr r12, [sp, #0x58] */
/* @0x001e8fc4 str r9, [sp] */
/* @0x001e8fc8 mov r2, r8 */
/* @0x001e8fcc str lr, [sp, #0x8] */
/* @0x001e8fd0 str r6, [sp, #0xc] */
/* @0x001e8fd4 ldr r0, [sp, #0x2c] */
/* @0x001e8fd8 str r5, [sp, #0x1c] */
/* @0x001e8fdc str r12, [sp, #0x20] */
/* @0x001e8fe0 bl 0x1e7e1c <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j>——SetupBitmapTexture：12 形参，4 平面 */
/* @0x001e8fe4 b 0x1e84c0 <_ZN7CSprite12BuildSWFDataEPcii+0x134> */

/* ── 子记录尾的「n2==0」出口：游标复位到 r5 后直入影片段判定（0x1e8fec b 0x1e8a24）──
 *   ★ 注意 0x1e8fec 跳的是 **0x1e8a24**（84 B 记录闸），不是回 0x1e89dc —— 说明这条出口
 *     属于「n2==0 且 n3 可能非 0」的路径，仍要走 84 B 记录段。
 */
/* @0x001e8fe8 mov r7, r5 */
/* @0x001e8fec b 0x1e8a24 <_ZN7CSprite12BuildSWFDataEPcii+0x698> */

/* ── 影片段入口：r9 = 帧数据起点，Alloc(28) → this+0x84 ──────────────────────────────
 *   0x1e8ff0 `mov r9,r7`（项循环结束时 r7 已越过最后一项）；0x1e9018 Alloc(28)。
 *   写入顺序（0x1e903c..0x1e9090）：
 *     [+0x04] ← [r9+0]      [+0x18] ← [r9+4]（= 帧数）
 *     [+0x08..+0x14] ← [r9+8..+0x14] 四个 float × g（s15 = *GOT 0x3f0ddc，见 0x1e9028）
 *   ★ 0x1e9028 `ldr r12,[pc,r12]` + [sp+0x34] 保存的 0x00207dac 是本函数访问 GOT 的唯一方式：
 *     地址 = pc + 0x207dac，落到 0x3f0ddc（全局 float g，与 DrawShape 卡同槽）。
 *   ★ 四个 float 都乘 g 后才落 [+0x08..+0x14] —— 即影片矩形以「1/g 单位」存档。
 */
/* @0x001e8ff0 mov r9, r7 */
/* @0x001e8ff4 ldr r5, [pc, #-0x77c] */
/* @0x001e8ff8 mov r3, #1 */
/* @0x001e8ffc ldr r12, [pc, #-0x780] */
/* @0x001e9000 mov r0, #28 */
/* @0x001e9004 add r5, pc, r5 */
/* @0x001e9008 mov r2, #70 */
/* @0x001e900c add r10, r9, #36 */
/* @0x001e9010 mov r1, r5 */
/* @0x001e9014 str r12, [sp, #0x34] */
/* @0x001e9018 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>——Alloc(28) → this+0x84（影片） */
/* @0x001e901c ldr r12, [sp, #0x34] */
/* @0x001e9020 vldr s14, [r9, #8] */
/* @0x001e9024 ldr r3, [r9] */
/* @0x001e9028 ldr r12, [pc, r12]——ldr [pc,r12]：GOT 0x3f0ddc（全局 float g） */
/* @0x001e902c vldr s15, [r12] */
/* @0x001e9030 str r12, [sp, #0x34] */
/* @0x001e9034 vmul.f32 s14, s14, s15 */
/* @0x001e9038 ldr r12, [sp, #0x2c] */
/* @0x001e903c str r0, [r12, #0x84] */
/* @0x001e9040 mov r4, r0 */
/* @0x001e9044 str r3, [r0, #0x4] */
/* @0x001e9048 ldr r3, [r9, #0x4] */
/* @0x001e904c cmp r3, #0 */
/* @0x001e9050 str r3, [r0, #0x18] */
/* @0x001e9054 ldr r12, [r9, #0x18] */
/* @0x001e9058 str r12, [sp, #0x3c] */
/* @0x001e905c ldr r12, [r9, #0x1c] */
/* @0x001e9060 str r12, [sp, #0x44] */
/* @0x001e9064 ldr r12, [r9, #0x20] */
/* @0x001e9068 vstr s14, [r0, #8] */
/* @0x001e906c vldr s14, [r9, #12] */
/* @0x001e9070 vmul.f32 s14, s15, s14 */
/* @0x001e9074 str r12, [sp, #0x48] */
/* @0x001e9078 vstr s14, [r0, #12] */
/* @0x001e907c vldr s14, [r9, #16] */
/* @0x001e9080 vmul.f32 s14, s15, s14 */
/* @0x001e9084 vstr s14, [r0, #16] */
/* @0x001e9088 vldr s14, [r9, #20] */
/* @0x001e908c vmul.f32 s15, s15, s14 */
/* @0x001e9090 vstr s15, [r0, #20] */
/* @0x001e9094 ble 0x1e9698 <_ZN7CSprite12BuildSWFDataEPcii+0x130c> */

/* ── 帧数组：Alloc(24×帧数) → [this+0x84][+0x00]；帧数 ≤ 0 则清 0 ───────────────────
 *   0x1e9098 `add r0,r3,r3,lsl #1` + 0x1e90a8 `lsl r0,r0,#3` = 24×n；0x1e90c4 `str r0,[r4]`。
 *   ★ 0x1e9094 `ble 0x1e9698`：帧数 ≤ 0 时 [r0] = 0 并跳到 0x1e9334（尺寸段）——
 *     「没有帧」不是错误，后面照样算包围尺寸。
 */
/* @0x001e9098 add r0, r3, r3, lsl #1 */
/* @0x001e909c mov r1, r5 */
/* @0x001e90a0 mov r2, #70 */
/* @0x001e90a4 mov r3, #1 */
/* @0x001e90a8 lsl r0, r0, #3 */
/* @0x001e90ac bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>——Alloc(24×帧数) → 帧数组 */
/* @0x001e90b0 ldr r5, [sp, #0x2c] */
/* @0x001e90b4 ldr r3, [r5, #0x84] */
/* @0x001e90b8 ldr r1, [r3, #0x18] */
/* @0x001e90bc mov r2, r3 */
/* @0x001e90c0 cmp r1, #0 */
/* @0x001e90c4 str r0, [r4] */
/* @0x001e90c8 ble 0x1e9334 <_ZN7CSprite12BuildSWFDataEPcii+0xfa8> */
/* @0x001e90cc ldr r12, [pc, #-0x84c] */
/* @0x001e90d0 mov r4, #0 */
/* @0x001e90d4 vldr s16, [pc, #964] */
/* @0x001e90d8 str r4, [sp, #0x38] */
/* @0x001e90dc add r12, pc, r12 */
/* @0x001e90e0 str r4, [sp, #0x30] */
/* @0x001e90e4 str r12, [sp, #0x40] */

/* ── 逐帧：24 B 帧头 + 144 B 显示项数组（本函数最内层的大循环）────────────────────────
 *   帧基址 r5 = [r6] + 帧偏移（[sp+0x38] 每帧 +24，0x1e9328）。
 *   帧头写入：+0x14 ← 项数（0x1e9110 `str r2,[r5,#0x14]`，r2=[r10]）；
 *     +0x04..+0x10 ← 四个 float × g（0x1e90e8..0x1e9138）。
 *   显示项：Alloc(144×n)（0x1e9140 `add r0,r2,r2,lsl #3` + 0x1e9150 `lsl r0,r0,#4`）→ [帧+0]；
 *     源记录 100 B/项（0x1e9180 `mov r1,#100` + 0x1e918c `mla r10,r1,r10,r4`）。
 *   每项填充：+0x00..+0x0f 四字直拷（0x1e91a0..0x1e91c4）；+0x10..+0x1f 与 +0x30..+0x3f 是两次
 *     4 字拷贝（0x1e91c8 的 16 B 循环 + 0x1e9200 的 4 字循环，同一块数据写两处）；
 *     +0x20..+0x2f 由 sp+144 的 4 字块拷入；+0x40..+0x4c 四个 float × g；
 *     +0x50..+0x8f 单位矩阵：16 个 0.0f（0x1e9294..0x1e92c0）+ 4 个 1.0f（0x1e9284..0x1e9290）。
 *   ★ 0x1e9278 `rsb r2,r0,r8` + 0x1e9280 `add r2,r2,r9` 是「当前项末地址」的构造式，
 *     所有 0.0f/1.0f 都以它为负偏移写入 —— 单位矩阵是按项尾定位的，不是按项首。
 *   ★ 144 = 0x90，正好把 [0x50,0x90) 留给 64 B 矩阵 ⇒ 与 §2 的 obj+0x50 读法闭环。
 */
/* @0x001e90e8 vldr s14, [r10, #4] */
/* @0x001e90ec ldr r5, [sp, #0x34] */
/* @0x001e90f0 vldr s15, [r5] */
/* @0x001e90f4 vmul.f32 s14, s14, s15 */
/* @0x001e90f8 ldr r6, [r3] */
/* @0x001e90fc add r4, r10, #20 */
/* @0x001e9100 ldr r12, [sp, #0x38] */
/* @0x001e9104 ldr r2, [r10] */
/* @0x001e9108 add r5, r6, r12 */
/* @0x001e910c cmp r2, #0 */
/* @0x001e9110 str r2, [r5, #0x14] */
/* @0x001e9114 vstr s14, [r5, #4] */
/* @0x001e9118 vldr s14, [r10, #8] */
/* @0x001e911c vmul.f32 s14, s15, s14 */
/* @0x001e9120 vstr s14, [r5, #8] */
/* @0x001e9124 vldr s14, [r10, #12] */
/* @0x001e9128 vmul.f32 s14, s15, s14 */
/* @0x001e912c vstr s14, [r5, #12] */
/* @0x001e9130 vldr s14, [r10, #16] */
/* @0x001e9134 vmul.f32 s15, s15, s14 */
/* @0x001e9138 vstr s15, [r5, #16] */
/* @0x001e913c ble 0x1e9524 <_ZN7CSprite12BuildSWFDataEPcii+0x1198> */
/* @0x001e9140 add r0, r2, r2, lsl #3 */
/* @0x001e9144 ldr r1, [sp, #0x40] */
/* @0x001e9148 mov r2, #70 */
/* @0x001e914c mov r3, #1 */
/* @0x001e9150 lsl r0, r0, #4——Alloc(144×项数) → 显示项 */
/* @0x001e9154 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x001e9158 ldr r10, [r5, #0x14] */
/* @0x001e915c ldr r5, [sp, #0x38] */
/* @0x001e9160 cmp r10, #0 */
/* @0x001e9164 str r0, [r6, r5] */
/* @0x001e9168 ble 0x1e9704 <_ZN7CSprite12BuildSWFDataEPcii+0x1378> */
/* @0x001e916c vmov.f32 s14, #1.000000e+00 */
/* @0x001e9170 add r9, r0, #80 */
/* @0x001e9174 add r11, sp, #164 */
/* @0x001e9178 add r12, sp, #132 */
/* @0x001e917c add r7, sp, #148 */
/* @0x001e9180 mov r1, #100 */
/* @0x001e9184 mov r8, r9 */
/* @0x001e9188 mov r3, r0 */
/* @0x001e918c mla r10, r1, r10, r4——源记录 100 B/项 */
/* @0x001e9190 ldr r5, [sp, #0x34] */
/* @0x001e9194 vldr s15, [r5] */
/* @0x001e9198 add r1, sp, #144 */
/* @0x001e919c str r1, [sp, #0x28] */
/* @0x001e91a0 ldr r1, [r4] */
/* @0x001e91a4 add r5, r4, #16 */
/* @0x001e91a8 mov r2, #0 */
/* @0x001e91ac str r1, [r3] */
/* @0x001e91b0 ldr r1, [r4, #0x4] */
/* @0x001e91b4 str r1, [r3, #0x4] */
/* @0x001e91b8 ldr r1, [r4, #0x8] */
/* @0x001e91bc str r1, [r3, #0x8] */
/* @0x001e91c0 ldr r1, [r4, #0xc] */
/* @0x001e91c4 str r1, [r3, #0xc] */
/* @0x001e91c8 ldr r1, [r5, r2] */
/* @0x001e91cc str r1, [r12, r2] */
/* @0x001e91d0 add r2, r2, #4 */
/* @0x001e91d4 cmp r2, #16 */
/* @0x001e91d8 bne 0x1e91c8 <_ZN7CSprite12BuildSWFDataEPcii+0xe3c> */
/* @0x001e91dc add r6, r4, #44 */
/* @0x001e91e0 add r2, r4, #28 */
/* @0x001e91e4 add r1, sp, #144 */
/* @0x001e91e8 ldr r5, [r2, #0x4]! */
/* @0x001e91ec cmp r6, r2 */
/* @0x001e91f0 str r5, [r1, #0x4]! */
/* @0x001e91f4 bne 0x1e91e8 <_ZN7CSprite12BuildSWFDataEPcii+0xe5c> */
/* @0x001e91f8 mov r1, r3 */
/* @0x001e91fc mov r2, #0 */
/* @0x001e9200 ldr r5, [r7, r2] */
/* @0x001e9204 add r1, r1, #4 */
/* @0x001e9208 ldr r6, [r12, r2] */
/* @0x001e920c add r2, r2, #4 */
/* @0x001e9210 cmp r2, #16 */
/* @0x001e9214 str r5, [r1, #0x1c] */
/* @0x001e9218 str r6, [r1, #0xc] */
/* @0x001e921c str r5, [r1, #0x2c] */
/* @0x001e9220 bne 0x1e9200 <_ZN7CSprite12BuildSWFDataEPcii+0xe74> */
/* @0x001e9224 mov r2, #0 */
/* @0x001e9228 str r2, [r3, #0x30] */
/* @0x001e922c vldr s13, [r4, #48] */
/* @0x001e9230 vmul.f32 s13, s13, s15 */
/* @0x001e9234 add r5, r4, #100 */
/* @0x001e9238 add r2, r4, #64 */
/* @0x001e923c mov r1, r11 */
/* @0x001e9240 vstr s13, [r3, #64] */
/* @0x001e9244 vldr s13, [r4, #52] */
/* @0x001e9248 vmul.f32 s13, s13, s15 */
/* @0x001e924c vstr s13, [r3, #68] */
/* @0x001e9250 vldr s13, [r4, #56] */
/* @0x001e9254 vmul.f32 s13, s13, s15 */
/* @0x001e9258 vstr s13, [r3, #72] */
/* @0x001e925c vldr s13, [r4, #60] */
/* @0x001e9260 vmul.f32 s13, s13, s15 */
/* @0x001e9264 vstr s13, [r3, #76] */
/* @0x001e9268 ldr r4, [r2], #4 */
/* @0x001e926c cmp r5, r2 */
/* @0x001e9270 str r4, [r1], #4 */
/* @0x001e9274 bne 0x1e9268 <_ZN7CSprite12BuildSWFDataEPcii+0xedc> */
/* @0x001e9278 rsb r2, r0, r8 */
/* @0x001e927c cmp r5, r10 */
/* @0x001e9280 add r2, r2, r9 */
/* @0x001e9284 vstr s14, [r2, #-20] */
/* @0x001e9288 vstr s14, [r2, #-40] */
/* @0x001e928c vstr s14, [r2, #-60] */
/* @0x001e9290 vstr s14, [r2, #-80] */
/* @0x001e9294 vstr s16, [r2, #-24] */
/* @0x001e9298 vstr s16, [r2, #-28] */
/* @0x001e929c vstr s16, [r2, #-32] */
/* @0x001e92a0 vstr s16, [r2, #-36] */
/* @0x001e92a4 vstr s16, [r2, #-44] */
/* @0x001e92a8 vstr s16, [r2, #-48] */
/* @0x001e92ac vstr s16, [r2, #-52] */
/* @0x001e92b0 vstr s16, [r2, #-56] */
/* @0x001e92b4 vstr s16, [r2, #-64] */
/* @0x001e92b8 vstr s16, [r2, #-68] */
/* @0x001e92bc vstr s16, [r2, #-72] */
/* @0x001e92c0 vstr s16, [r2, #-76] */
/* @0x001e92c4 ldr r2, [sp, #0xa4] */
/* @0x001e92c8 mov r4, r5 */
/* @0x001e92cc add r8, r8, #144——144 B/显示项 */
/* @0x001e92d0 add r3, r3, #144——同上（项首推进） */
/* @0x001e92d4 str r2, [r3, #-0x40] */
/* @0x001e92d8 ldr r2, [sp, #0xa8] */
/* @0x001e92dc str r2, [r3, #-0x30] */
/* @0x001e92e0 ldr r2, [sp, #0xac] */
/* @0x001e92e4 str r2, [r3, #-0x10] */
/* @0x001e92e8 ldr r2, [sp, #0xb0] */
/* @0x001e92ec str r2, [r3, #-0x3c] */
/* @0x001e92f0 ldr r2, [sp, #0xb4] */
/* @0x001e92f4 str r2, [r3, #-0x2c] */
/* @0x001e92f8 ldr r2, [sp, #0xb8] */
/* @0x001e92fc str r2, [r3, #-0xc] */
/* @0x001e9300 bne 0x1e91a0 <_ZN7CSprite12BuildSWFDataEPcii+0xe14> */
/* @0x001e9304 ldr r4, [sp, #0x2c] */
/* @0x001e9308 ldr r3, [r4, #0x84] */
/* @0x001e930c ldr r5, [sp, #0x30] */
/* @0x001e9310 mov r2, r3 */
/* @0x001e9314 ldr r1, [r3, #0x18] */
/* @0x001e9318 add r5, r5, #1 */
/* @0x001e931c ldr r12, [sp, #0x38] */
/* @0x001e9320 cmp r1, r5 */
/* @0x001e9324 str r5, [sp, #0x30] */
/* @0x001e9328 add r12, r12, #24 */
/* @0x001e932c str r12, [sp, #0x38] */
/* @0x001e9330 bgt 0x1e90e8 <_ZN7CSprite12BuildSWFDataEPcii+0xd5c> */

/* ── 碰撞掩码闸：+0x18 字非 0 → 0x1e95a0；否则写尺寸四字节并进半径段 ─────────────────
 *   0x1e9334 `ldr r4,[sp+0x3c]`（= 掩码个数，来自 [r9+0x18] 存进 [sp+0x3c]）→ `cmp #0`。
 *   0x1e9340/0x1e9348：s14 = (int)[影片+0xc]、s15 = (int)[影片+0x14] → this+0x1c / this+0x20
 *     （两条 vcvt.s32.f32 + vstr，0x1e934c..0x1e9360）。
 *   0x1e9350 `ldrb r3,[this+0x78]`：已初始化过就跳到 0x1e9670，否则 this+0x30 = 0、this+0x04 = 0、
 *     this+0x34 = 1（0x1e936c..0x1e9380）。
 *   ★ 0x1e9670 那条支路用 this+0x30 反查是否已建过掩码，未建则从 this+0x08/0x0c/0x24/0x28 重算 ——
 *     即「重复调用 BuildSWFData 时保留首次的尺寸」，这是本块唯一的重入保护。
 */
/* @0x001e9334 ldr r4, [sp, #0x3c] */
/* @0x001e9338 cmp r4, #0 */
/* @0x001e933c bne 0x1e95a0 <_ZN7CSprite12BuildSWFDataEPcii+0x1214> */
/* @0x001e9340 vldr s14, [r2, #12] */
/* @0x001e9344 vldr s15, [r2, #20] */
/* @0x001e9348 ldr r5, [sp, #0x2c] */
/* @0x001e934c vcvt.s32.f32 s14, s14 */
/* @0x001e9350 ldrb r3, [r5, #0x78] */
/* @0x001e9354 cmp r3, #0 */
/* @0x001e9358 vcvt.s32.f32 s15, s15 */
/* @0x001e935c vstr s14, [r5, #28] */
/* @0x001e9360 vstr s15, [r5, #32] */
/* @0x001e9364 bne 0x1e9670 <_ZN7CSprite12BuildSWFDataEPcii+0x12e4> */
/* @0x001e9368 ldr r12, [sp, #0x3c] */
/* @0x001e936c strb r12, [r5, #0x30] */

/* ── 尺寸/半径：矩形四角两两求距，取最大 → this+0x2c ────────────────────────────────
 *   输入：this+0x08/0x0c（影片矩形左/下，int）、this+0x10/0x14（右/上）、this+0x24/0x28（w/h）。
 *   0x1e939c..0x1e93c4：把 [影片+8/+0xc/+0x10/+0x14] 四个 float 经 vcvt.s32 落 this+0x08..+0x14
 *     （顺序是 +0x08←[+8]、+0x10←[+0xc]、+0x0c←[+0x10]... 四条 vstr 的落点见 0x1e93bc/c4/cc/d4）。
 *   0x1e93d8/0x1e93dc：dx = this+0x28 - this+0x08、dy = this+0x24 - this+0x0c（rsb 两条）。
 *   0x1e9400..0x1e940c：s15 = dx² + dy²，vsqrt → s18（第一对角的平方根）。
 *   0x1e941c..0x1e9434：第二对；0x1e9460..0x1e948c：第三对；0x1e94a8..0x1e94d0：第四对。
 *   ★ 四条 vsqrt 后面都紧跟 `vcmp sN,sN` + `vmrs` + `bne sqrtf@plt`：NaN 时回退 libm sqrtf
 *     （0x1e9418/0x1e945c/0x1e9498/0x1e94dc 四个 bne）——这是 -ffast-math 或缺 vsqrt 的兜底。
 *   ★ 0x1e940c/0x1e9450/0x1e948c/0x1e94d0 的四个结果进 s18/s17/s16/s15，随后 0x1e94e0..0x1e959c
 *     是一棵**四选一的最大值树**（vcmpe + 条件 vmov + 六个分支），不是简单 max：它把「最大者」
 *     选出来后 0x1e9508/0x1e956c/0x1e9598 三条 vcvt.s32 出口落 this+0x2c。
 */
/* @0x001e9370 ldr r4, [sp, #0x2c] */
/* @0x001e9374 mov r2, #0 */
/* @0x001e9378 mov r3, #1 */
/* @0x001e937c str r2, [r4, #0x4] */
/* @0x001e9380 strb r3, [r4, #0x34] */
/* @0x001e9384 ldr r5, [sp, #0x2c] */
/* @0x001e9388 ldr r12, [sp, #0x64] */
/* @0x001e938c ldr r1, [sp, #0x68] */
/* @0x001e9390 ldr r3, [r5, #0x84] */
/* @0x001e9394 vldr s15, [r3, #8] */
/* @0x001e9398 vcvt.s32.f32 s15, s15 */
/* @0x001e939c vldr s13, [r3, #16] */
/* @0x001e93a0 vldr s14, [r3, #12] */
/* @0x001e93a4 vmov r2, s15 */
/* @0x001e93a8 vldr s15, [r3, #20] */
/* @0x001e93ac vcvt.s32.f32 s13, s13 */
/* @0x001e93b0 str r12, [r5, #0x24]——this+0x24 = 形参 w */
/* @0x001e93b4 str r1, [r5, #0x28]——this+0x28 = 形参 h */
/* @0x001e93b8 vcvt.s32.f32 s14, s14 */
/* @0x001e93bc vstr s13, [r5, #12] */
/* @0x001e93c0 vcvt.s32.f32 s15, s15 */
/* @0x001e93c4 vstr s14, [r5, #16] */
/* @0x001e93c8 mov r0, r2 */
/* @0x001e93cc str r2, [r5, #0x8] */
/* @0x001e93d0 vmov r2, s13 */
/* @0x001e93d4 vstr s15, [r5, #20] */
/* @0x001e93d8 rsb r2, r2, r1 */
/* @0x001e93dc rsb r0, r0, r12 */
/* @0x001e93e0 ldr r3, [r3, #0x18] */
/* @0x001e93e4 mov r4, #1 */
/* @0x001e93e8 vmov s15, r2 */
/* @0x001e93ec ldr r5, [sp, #0x2c] */
/* @0x001e93f0 vmov s13, r0 */
/* @0x001e93f4 vcvt.f32.s32 s15, s15 */
/* @0x001e93f8 strb r4, [r5, #0x32] */
/* @0x001e93fc str r3, [r5, #0x18] */
/* @0x001e9400 vmul.f32 s15, s15, s15 */
/* @0x001e9404 vcvt.f32.s32 s14, s13 */
/* @0x001e9408 vmla.f32 s15, s14, s14 */
/* @0x001e940c vsqrt.f32 s18, s15 */
/* @0x001e9410 vcmp.f32 s18, s18 */
/* @0x001e9414 vmrs APSR_nzcv, fpscr */
/* @0x001e9418 bne 0x1e96f4 <_ZN7CSprite12BuildSWFDataEPcii+0x1368>——vsqrt 后 NaN 自检 */

/* ── 第二/第三/第四条对角线（含两条 sqrtf 回退）────────────────────────────────────
 *   每条都是「dx = a-b、dy = c-d、s = dx²+dy²、sqrt、NaN 检查」的同构四步；
 *   0x1e96c0/0x1e96d8/0x1e96f4/0x1e9714 是四个 libm 回退桩（vmov r0,sN; bl sqrtf@plt; vmov sN,r0）。
 *   ★ 四个回退桩里三个在函数尾部、一个（0x1e96f4）与 0x1e96c0 相邻 —— 说明编译器把冷块统一
 *     挪到函数末尾，热路径只剩 6 条指令。
 */
/* @0x001e941c ldr r4, [sp, #0x2c] */
/* @0x001e9420 ldr r2, [r4, #0x28] */
/* @0x001e9424 ldr r3, [r4, #0xc] */
/* @0x001e9428 ldr r1, [r4, #0x10] */
/* @0x001e942c rsb r3, r3, r2 */
/* @0x001e9430 vmov s15, r3 */
/* @0x001e9434 ldr r3, [r4, #0x24] */
/* @0x001e9438 vcvt.f32.s32 s15, s15 */
/* @0x001e943c rsb r1, r3, r1 */
/* @0x001e9440 vmov s13, r1 */
/* @0x001e9444 vmul.f32 s15, s15, s15 */
/* @0x001e9448 vcvt.f32.s32 s14, s13 */
/* @0x001e944c vmla.f32 s15, s14, s14 */
/* @0x001e9450 vsqrt.f32 s17, s15 */
/* @0x001e9454 vcmp.f32 s17, s17 */
/* @0x001e9458 vmrs APSR_nzcv, fpscr */
/* @0x001e945c bne 0x1e96c0 <_ZN7CSprite12BuildSWFDataEPcii+0x1334> */
/* @0x001e9460 ldr r4, [sp, #0x2c] */
/* @0x001e9464 ldr r1, [r4, #0x14] */
/* @0x001e9468 ldr r0, [r4, #0x8] */
/* @0x001e946c rsb r5, r2, r1 */
/* @0x001e9470 rsb r0, r0, r3 */
/* @0x001e9474 vmov s15, r5 */
/* @0x001e9478 vmov s13, r0 */
/* @0x001e947c vcvt.f32.s32 s15, s15 */
/* @0x001e9480 vmul.f32 s15, s15, s15 */
/* @0x001e9484 vcvt.f32.s32 s14, s13 */
/* @0x001e9488 vmla.f32 s15, s14, s14 */
/* @0x001e948c vsqrt.f32 s16, s15 */
/* @0x001e9490 vcmp.f32 s16, s16 */
/* @0x001e9494 vmrs APSR_nzcv, fpscr */
/* @0x001e9498 bne 0x1e96d8 <_ZN7CSprite12BuildSWFDataEPcii+0x134c> */
/* @0x001e949c b 0x1e94a8 <_ZN7CSprite12BuildSWFDataEPcii+0x111c> */

/* ── 第二处内联字面量池（2 字）──────────────────────────────────────────────────
 *   0x1e94a0 = 0x00000000（= 0.0f，0x1e90d4 的 `vldr s16,[pc,#964]` 目标，用作「清 0 常量」）
 *   0x1e94a4 = 0x00168e74（pc 相对 .rodata 偏移，0x1e95a0 的 `ldr r5,[pc,#-0x104]` 取它当
 *     Alloc 的 file 实参；objdump 译作 andseq，非指令）
 *   ★ 两处池共 26 字，全部混在 .text 里，没有任何 .word 标记 —— 这是本函数锚点里最容易
 *     被误当指令的两段（另一段是 0x1e882c..0x1e8888 的 24 字）。
 */
/* @0x001e94a0 andeq r0, r0, r0 */
/* @0x001e94a4 andseq r8, r6, r4, ror lr */

/* ── 最大值树与出口：四条对角线选最大 → vcvt.s32 → this+0x2c，返回 1 ──────────────────
 *   0x1e94e0 `vcmpe s16,s15` 起是一串「两两比较 + 条件搬移」，出口三条 vcvt.s32：
 *     0x1e9508（s18）、0x1e956c（s17）、0x1e9598（s16）、0x1e96a8（s15）—— 四条对应四个候选，
 *     谁在树里胜出就走谁。落点统一 0x1e9514 `vstr s15,[r4,#44]`（this+0x2c）。
 *   0x1e9510 `mov r0,#1` 是**成功返回 1** 的唯一出口（与 0x1e96b0 的返回 0 相对）。
 *   ★ 这一段的四个候选值不是「四边」而是「四个角到对角」：由 0x1e93d8/0x1e93dc、0x1e942c/0x1e943c、
 *     0x1e946c/0x1e9470、0x1e94a8/0x1e94bc 的四组 rsb 各自配对而定，取最大即外接圆半径。
 */
/* @0x001e94a8 rsb r2, r2, r1 */
/* @0x001e94ac ldr r4, [sp, #0x2c] */
/* @0x001e94b0 vmov s14, r2 */
/* @0x001e94b4 ldr r0, [r4, #0x10] */
/* @0x001e94b8 vcvt.f32.s32 s14, s14 */
/* @0x001e94bc rsb r3, r3, r0 */
/* @0x001e94c0 vmov s13, r3 */
/* @0x001e94c4 vmul.f32 s14, s14, s14 */
/* @0x001e94c8 vcvt.f32.s32 s15, s13 */
/* @0x001e94cc vmla.f32 s14, s15, s15 */
/* @0x001e94d0 vsqrt.f32 s15, s14 */
/* @0x001e94d4 vcmp.f32 s15, s15 */
/* @0x001e94d8 vmrs APSR_nzcv, fpscr */
/* @0x001e94dc bne 0x1e9714 <_ZN7CSprite12BuildSWFDataEPcii+0x1388> */
/* @0x001e94e0 vcmpe.f32 s16, s15 */
/* @0x001e94e4 vmrs APSR_nzcv, fpscr */
/* @0x001e94e8 ble 0x1e9538 <_ZN7CSprite12BuildSWFDataEPcii+0x11ac> */
/* @0x001e94ec vcmpe.f32 s17, s16 */
/* @0x001e94f0 vmrs APSR_nzcv, fpscr */
/* @0x001e94f4 ble 0x1e9554 <_ZN7CSprite12BuildSWFDataEPcii+0x11c8> */
/* @0x001e94f8 vmov.f32 s14, s17 */
/* @0x001e94fc vcmpe.f32 s14, s18 */
/* @0x001e9500 vmrs APSR_nzcv, fpscr */
/* @0x001e9504 bpl 0x1e9574 <_ZN7CSprite12BuildSWFDataEPcii+0x11e8> */
/* @0x001e9508 vcvt.s32.f32 s15, s18 */
/* @0x001e950c ldr r4, [sp, #0x2c] */
/* @0x001e9510 mov r0, #1——成功返回 1 */
/* @0x001e9514 vstr s15, [r4, #44] */
/* @0x001e9518 add sp, sp, #204 */
/* @0x001e951c vpop {d8, d9} */
/* @0x001e9520 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x001e9524 ldr r5, [sp, #0x38] */
/* @0x001e9528 mov r12, #0 */
/* @0x001e952c mov r10, r4 */
/* @0x001e9530 str r12, [r6, r5] */
/* @0x001e9534 b 0x1e930c <_ZN7CSprite12BuildSWFDataEPcii+0xf80> */
/* @0x001e9538 vcmpe.f32 s17, s15 */
/* @0x001e953c vmrs APSR_nzcv, fpscr */
/* @0x001e9540 bgt 0x1e94f8 <_ZN7CSprite12BuildSWFDataEPcii+0x116c> */
/* @0x001e9544 vcmpe.f32 s16, s15 */
/* @0x001e9548 vmrs APSR_nzcv, fpscr */
/* @0x001e954c vmovle.f32 s14, s15 */
/* @0x001e9550 ble 0x1e94fc <_ZN7CSprite12BuildSWFDataEPcii+0x1170> */
/* @0x001e9554 vcmpe.f32 s18, s16 */
/* @0x001e9558 vmrs APSR_nzcv, fpscr */
/* @0x001e955c bgt 0x1e9508 <_ZN7CSprite12BuildSWFDataEPcii+0x117c> */
/* @0x001e9560 vcmpe.f32 s17, s16 */
/* @0x001e9564 vmrs APSR_nzcv, fpscr */
/* @0x001e9568 ble 0x1e9598 <_ZN7CSprite12BuildSWFDataEPcii+0x120c> */
/* @0x001e956c vcvt.s32.f32 s15, s17 */
/* @0x001e9570 b 0x1e950c <_ZN7CSprite12BuildSWFDataEPcii+0x1180> */
/* @0x001e9574 vcmpe.f32 s16, s15 */
/* @0x001e9578 vmrs APSR_nzcv, fpscr */
/* @0x001e957c bgt 0x1e9560 <_ZN7CSprite12BuildSWFDataEPcii+0x11d4> */
/* @0x001e9580 vcmpe.f32 s17, s15 */
/* @0x001e9584 vmrs APSR_nzcv, fpscr */
/* @0x001e9588 bgt 0x1e956c <_ZN7CSprite12BuildSWFDataEPcii+0x11e0> */
/* @0x001e958c vcmpe.f32 s16, s15 */
/* @0x001e9590 vmrs APSR_nzcv, fpscr */
/* @0x001e9594 ble 0x1e96a8 <_ZN7CSprite12BuildSWFDataEPcii+0x131c> */
/* @0x001e9598 vcvt.s32.f32 s15, s16 */
/* @0x001e959c b 0x1e950c <_ZN7CSprite12BuildSWFDataEPcii+0x1180> */

/* ── 碰撞掩码：两个临时指针数组 + SetupSWFCollisionMasks + 双双 Free ──────────────────
 *   n = [sp+0x3c]；0x1e95a4 `lsl r6,r4,#2` = 4n，两次 Alloc(4n)（0x1e95bc/0x1e95d4，行号 0x1286/0x1287）。
 *   0x1e95f0..0x1e9610 逐项：r1 = *p++（每块长度）、`add r0,r1,#3; bic r1,r0,#3` = align4 步进，
 *     第一数组存长度、第二数组存块指针（0x1e95f8 / 0x1e9600）。
 *   0x1e9614..0x1e9628：this+0x1c/0x20 ← [sp+0x44]/[sp+0x48]；this+0x30 = 1（若 this+0x78 == 0）。
 *   0x1e964c `bl SetupSWFCollisionMasks(this, sizes, ptrs, n)` —— 注意 r1/r2 的次序是
 *     (unsigned char**, int*, int)：r1 = 指针数组、r2 = 长度数组。
 *   0x1e9654/0x1e965c 两次 Free，随后 0x1e9664 判 this+0x78 → 回 0x1e9370 或 0x1e9384。
 *   ★ 这是本函数唯一一处「先 Alloc 再立刻 Free」的用法：两个数组只为传参存在，不长期持有。
 */
/* @0x001e95a0 ldr r5, [pc, #-0x104] */
/* @0x001e95a4 lsl r6, r4, #2 */
/* @0x001e95a8 movw r2, #0x1286 */
/* @0x001e95ac mov r3, #1 */
/* @0x001e95b0 add r5, pc, r5 */
/* @0x001e95b4 mov r0, r6 */
/* @0x001e95b8 mov r1, r5 */
/* @0x001e95bc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>——Alloc(4n)：长度数组 */
/* @0x001e95c0 mov r1, r5 */
/* @0x001e95c4 movw r2, #0x1287 */
/* @0x001e95c8 mov r3, #1 */
/* @0x001e95cc mov r4, r0 */
/* @0x001e95d0 mov r0, r6 */
/* @0x001e95d4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>——Alloc(4n)：块指针数组 */
/* @0x001e95d8 ldr r12, [sp, #0x3c] */
/* @0x001e95dc cmp r12, #0 */
/* @0x001e95e0 movgt r3, #0 */
/* @0x001e95e4 movgt r2, r10 */
/* @0x001e95e8 mov r5, r0 */
/* @0x001e95ec ble 0x1e9614 <_ZN7CSprite12BuildSWFDataEPcii+0x1288> */
/* @0x001e95f0 ldr r1, [r2], #4 */
/* @0x001e95f4 add r0, r1, #3 */
/* @0x001e95f8 str r1, [r4, r3] */
/* @0x001e95fc bic r1, r0, #3 */
/* @0x001e9600 str r2, [r5, r3] */
/* @0x001e9604 add r3, r3, #4 */
/* @0x001e9608 cmp r3, r6 */
/* @0x001e960c add r2, r2, r1 */
/* @0x001e9610 bne 0x1e95f0 <_ZN7CSprite12BuildSWFDataEPcii+0x1264> */
/* @0x001e9614 ldr r12, [sp, #0x2c] */
/* @0x001e9618 ldr lr, [sp, #0x44] */
/* @0x001e961c ldr r0, [sp, #0x48] */
/* @0x001e9620 ldrb r3, [r12, #0x78] */
/* @0x001e9624 str lr, [r12, #0x1c] */
/* @0x001e9628 cmp r3, #0 */
/* @0x001e962c str r0, [r12, #0x20] */
/* @0x001e9630 ldreq r12, [sp, #0x2c] */
/* @0x001e9634 moveq r3, #1 */
/* @0x001e9638 strbeq r3, [r12, #0x30] */
/* @0x001e963c ldr r3, [sp, #0x3c] */
/* @0x001e9640 mov r2, r4 */
/* @0x001e9644 mov r1, r5 */
/* @0x001e9648 ldr r0, [sp, #0x2c] */
/* @0x001e964c bl 0x1e8264 <_ZN7CSprite22SetupSWFCollisionMasksEPPhPii>——SetupSWFCollisionMasks(this, ptrs, sizes, n) */
/* @0x001e9650 mov r0, r5 */
/* @0x001e9654 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>——Free(指针数组) */
/* @0x001e9658 mov r0, r4 */
/* @0x001e965c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>——Free(长度数组) */
/* @0x001e9660 ldr r4, [sp, #0x2c] */

/* ── 分支汇合：this+0x78 决定回半径段还是直接用现成尺寸 ────────────────────────────────
 *   0x1e966c `beq 0x1e9370`（未初始化 → 走完整尺寸计算）；否则 0x1e9670 起读 this+0x30/0x08/
 *   0x0c/0x24/0x28 做同样的四条对角线 —— 即「已有尺寸时只补算半径，不重写字段」。
 */
/* @0x001e9664 ldrb r3, [r4, #0x78] */
/* @0x001e9668 cmp r3, #0 */
/* @0x001e966c beq 0x1e9370 <_ZN7CSprite12BuildSWFDataEPcii+0xfe4> */
/* @0x001e9670 ldr r5, [sp, #0x2c] */
/* @0x001e9674 ldrb r3, [r5, #0x30] */
/* @0x001e9678 cmp r3, #0 */
/* @0x001e967c bne 0x1e9384 <_ZN7CSprite12BuildSWFDataEPcii+0xff8> */
/* @0x001e9680 ldr r3, [r5, #0x84] */
/* @0x001e9684 ldr r12, [r5, #0x24] */
/* @0x001e9688 ldr r0, [r5, #0x8] */
/* @0x001e968c ldr r1, [r5, #0x28] */
/* @0x001e9690 ldr r2, [r5, #0xc] */
/* @0x001e9694 b 0x1e93d8 <_ZN7CSprite12BuildSWFDataEPcii+0x104c> */
/* @0x001e9698 mov r3, #0 */
/* @0x001e969c mov r2, r0 */
/* @0x001e96a0 str r3, [r0] */
/* @0x001e96a4 b 0x1e9334 <_ZN7CSprite12BuildSWFDataEPcii+0xfa8> */
/* @0x001e96a8 vcvt.s32.f32 s15, s15 */
/* @0x001e96ac b 0x1e950c <_ZN7CSprite12BuildSWFDataEPcii+0x1180> */

/* ── 早退：data == 0 → 返回 0（唯一不清任何字段的出口）──────────────────────────────
 *   0x1e83a8 的 beq 目标；`mov r0,r1` 时 r1 恒为 0。
 */
/* @0x001e96b0 mov r0, r1——返回 0（data 为空） */
/* @0x001e96b4 add sp, sp, #204 */
/* @0x001e96b8 vpop {d8, d9} */
/* @0x001e96bc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── 四个 sqrtf@plt 回退桩（0x1e96c0/0x1e96d8/0x1e96f4/0x1e9714）+ version==5 的补读 ──
 *   桩体：vmov r0,sN → bl 0xb6700 <sqrtf@plt> → vmov sN,r0 → 跳回对应热路径。
 *   0x1e9724 是 version==5 的 84 B 记录尾：`add r7,r7,#40`（只读 8 个计数）。
 *   ★ 四个桩都只破坏 r0，不碰 r2..r11 —— 与调用点前后仍在用的活值相容。
 */
/* @0x001e96c0 vmov r0, s15 */
/* @0x001e96c4 bl 0xb6700 <sqrtf@plt> */
/* @0x001e96c8 ldr r3, [r4, #0x24] */
/* @0x001e96cc ldr r2, [r4, #0x28] */
/* @0x001e96d0 vmov s17, r0 */
/* @0x001e96d4 b 0x1e9460 <_ZN7CSprite12BuildSWFDataEPcii+0x10d4> */
/* @0x001e96d8 vmov r0, s15 */
/* @0x001e96dc bl 0xb6700 <sqrtf@plt> */
/* @0x001e96e0 ldr r3, [r4, #0x24] */
/* @0x001e96e4 ldr r2, [r4, #0x28] */
/* @0x001e96e8 ldr r1, [r4, #0x14] */
/* @0x001e96ec vmov s16, r0 */
/* @0x001e96f0 b 0x1e94a8 <_ZN7CSprite12BuildSWFDataEPcii+0x111c> */
/* @0x001e96f4 vmov r0, s15 */
/* @0x001e96f8 bl 0xb6700 <sqrtf@plt> */
/* @0x001e96fc vmov s18, r0 */
/* @0x001e9700 b 0x1e941c <_ZN7CSprite12BuildSWFDataEPcii+0x1090> */
/* @0x001e9704 ldr r12, [sp, #0x2c] */
/* @0x001e9708 mov r10, r4 */
/* @0x001e970c ldr r3, [r12, #0x84] */
/* @0x001e9710 b 0x1e930c <_ZN7CSprite12BuildSWFDataEPcii+0xf80> */
/* @0x001e9714 vmov r0, s14 */
/* @0x001e9718 bl 0xb6700 <sqrtf@plt> */
/* @0x001e971c vmov s15, r0 */
/* @0x001e9720 b 0x1e94e0 <_ZN7CSprite12BuildSWFDataEPcii+0x1154> */

/* ── 末块（两个字）：version==5 的记录尾 + 跳回分配块 ──────────────────────────────
 *   0x1e9724 `add r7,r7,#40`（5 档只读 8 个计数）；0x1e9728 `b 0x1e8d64` 直接跳进分配块的
 *   `cmp r0,#0`（0x1e8d64），**跳过 0x1e8d54..0x1e8d60 的「version ≤ 4 补零」**。
 *   ★ 0x1e9728 是本函数最后一个字（0x1e838c+0x13a0 = 0x1e972c 才是下一个函数），
 *     它是一条尾跳而不是返回 —— 全函数没有 r11 帧指针、返回只在 0x1e9518/0x1e96b4 两处。
 */
/* @0x001e9724 add r7, r7, #40 */
/* @0x001e9728 b 0x1e8d64 <_ZN7CSprite12BuildSWFDataEPcii+0x9d8> */

/* ══ 段 B · CSprite::DrawSWFObject 0x1eba90 ═══════════════════════════════════════════════
 *   1144 B / 286 字 = 278 指令 + 8 池字。11 条 bl 里：yyMatrix::Multiply ×4、
 *   Graphics::GetMatrix ×3、GR_Texture_Exists ×1、DrawDictionaryItem ×1、sqrtf@plt ×2。
 *   没有 GR_Texture_Draw/Drawi、没有 GR_3D_*、没有 CProfiler、没有状态存取 —— 与 DrawSWF 段
 *   （自己存/还原 8 个状态）和纹理档（自己算 π/180）都不同，本函数是**纯几何 + 委派**。
 *
 *   流程（一句话版）：
 *     M = obj[+0x50] 的 64 B 矩阵 × 上层矩阵 a
 *     flag≠0 → 取 Graphics 的 2/0/1 三层矩阵并成 ((M2·M0)·M1)，M 左乘之，再用投影后的两条基向量
 *              求缩放 s16 = g2 / (0.5·max(d1,d2))；flag==0 → s16 = 1.0f
 *     uv 原点 = (int16)page[+0x00]/纹理宽、(int16)page[+0x02]/纹理高
 *     obj[+0x00] == 0 → 整条不画（返回 0）；否则 item = this[+0x7c][ obj[+4] ]
 *     DrawDictionaryItem(this, item, M(按值拆分 r2/r3+14 字), s16, flag, (texExists!=0),
 *                        [sp+0x44], [sp+0x48], [sp+0x4c], sp+512, sp+576, sp+640, tex,
 *                        uv.x, uv.y)  —— 12 个字，比 mangled 名要求少 1 个（见 open 第 9 条）
 */
/* @0x001eba90 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x001eba94 vpush {d8} */
/* @0x001eba98 add lr, r1, #80 */
/* @0x001eba9c sub sp, sp, #708 */
/* @0x001ebaa0 mov r4, r2 */
/* @0x001ebaa4 mov r10, r1 */
/* @0x001ebaa8 mov r8, r0 */
/* @0x001ebaac str r3, [sp, #0x7c] */

/* ── 从 obj+0x50 拷 64 B 到 sp+192（4 组 ldm/stm，每组 4 字）──────────────────────────
 *   lr = obj+0x50（0x1eba98 `add lr,r1,#80`），r12 = sp+192，r9 = sp+256。
 *   ★ 这 4 组是 **load/store 交替**（0x1ebab4..0x1ebae4），不是 memcpy 调用 ——
 *     「时间线子项自带矩阵在 +0x50」由此成立，与 §1 显示项 144 B 的 [0x50,0x90) 矩阵块闭环。
 */
/* @0x001ebab0 add r12, sp, #192 */
/* @0x001ebab4 ldm lr!, {r0, r1, r2, r3} */
/* @0x001ebab8 add r9, sp, #256 */
/* @0x001ebabc ldrb r5, [sp, #0x300]——第 8 形参 bool */
/* @0x001ebac0 ldr r7, [pc, #0x424] */
/* @0x001ebac4 stm r12!, {r0, r1, r2, r3} */
/* @0x001ebac8 add r7, pc, r7——GOT 基址 0x3f1c58 */
/* @0x001ebacc ldm lr!, {r0, r1, r2, r3} */
/* @0x001ebad0 str r5, [sp, #0x78] */
/* @0x001ebad4 stm r12!, {r0, r1, r2, r3} */
/* @0x001ebad8 ldm lr!, {r0, r1, r2, r3} */
/* @0x001ebadc stm r12!, {r0, r1, r2, r3} */
/* @0x001ebae0 ldm lr, {r0, r1, r2, r3} */
/* @0x001ebae4 stm r12, {r0, r1, r2, r3} */

/* ── 本地矩阵 = obj 矩阵 × 形参矩阵 a（dst = sp+256）──────────────────────────────────
 *   r0 = r9 = sp+256、r1 = sp+192（刚拷来的）、r2 = r4 = 形参 a。
 *   flag = [sp+0x300]（0x1ebabc ldrb）；非 0 → 0x1ebc7c 的 3D 合流分支。
 */
/* @0x001ebae8 mov r2, r4 */
/* @0x001ebaec mov r0, r9 */
/* @0x001ebaf0 add r1, sp, #192 */
/* @0x001ebaf4 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_>——Multiply(dst=sp+256, obj 矩阵, 形参 a) */
/* @0x001ebaf8 cmp r5, #0 */
/* @0x001ebafc bne 0x1ebc7c <_ZN7CSprite13DrawSWFObjectEP18SWF_TimelineObjectP8yyMatrixS3_PjS4_S4_S4_b+0x1ec>——flag≠0 → 3D 合流 */

/* ── flag==0：缩放 s16 = 1.0f，三个 16 B 缓冲基址落位（sp+512/576/640）──────────────
 *   ★ s16 是最后那个 float 形参的唯一来源：2D 路恒 1.0，3D 路是算出来的比例（0x1ebeb0..0x1ebec4）。
 */
/* @0x001ebb00 vmov.f32 s16, #1.000000e+00 */
/* @0x001ebb04 add r5, sp, #512 */
/* @0x001ebb08 add r4, sp, #576 */
/* @0x001ebb0c add r6, sp, #640 */

/* ── 三组 4 字：obj+0x10/+0x20/+0x30 → sp+512 / sp+576 / sp+640 ─────────────────────
 *   循环 4 次（r3 = 0,4,8,0xc），每次读 [obj+0x10+k]/[obj+0x20+k]/[obj+0x30+k]（r2 每轮 +4，
 *   用 [r2+0x1c]/[r2+0x2c] 的偏移找齐），写三个缓冲的第 k 字。
 *   ★ 三个缓冲随后作为第 9/10/11 个实参（sp+512/576/640）交给 DrawDictionaryItem；
 *     它们的内容语义（4 个 ARGB？4 对 UV？）未钉 —— 见 open。
 */
/* @0x001ebb10 mov r2, r10 */
/* @0x001ebb14 mov r3, #0 */
/* @0x001ebb18 ldr r12, [r2, #0x10] */
/* @0x001ebb1c add r2, r2, #4 */
/* @0x001ebb20 ldr r0, [r2, #0x1c] */
/* @0x001ebb24 ldr r1, [r2, #0x2c] */
/* @0x001ebb28 str r12, [r5, r3] */
/* @0x001ebb2c str r0, [r4, r3] */
/* @0x001ebb30 str r1, [r6, r3] */
/* @0x001ebb34 add r3, r3, #4 */
/* @0x001ebb38 cmp r3, #16 */
/* @0x001ebb3c bne 0x1ebb18 <_ZN7CSprite13DrawSWFObjectEP18SWF_TimelineObjectP8yyMatrixS3_PjS4_S4_S4_b+0x88> */

/* ── 纹理号：this+0x54 → *(+0) → ldrsh [+0x14]，再 GR_Texture_Exists ──────────────────
 *   r3 = [this+0x54]（0x1ebb40）、r3 = [r3]（0x1ebb48）、r0 = ldrsh [r3,+0x14]（0x1ebb50）。
 *   ★ 二级解引用：+0x54 是「页/子图表」，其首字才是当前记录；这与 DrawShape 卡里 +0x54 记作
 *     「tpe 表」一致，本卡把它收窄为「首字解引用后 +0x14 是纹理号」。
 *   ★ 纹理不存在（r0==0）→ 0x1ebc68：s14=s15=0.0f、[sp+0x68]=0、r7=0，仍继续走绘制流程
 *     （不是早退），即「缺纹理只影响 UV 与 flag，不影响几何」。
 */
/* @0x001ebb40 ldr r3, [r8, #0x54] */
/* @0x001ebb44 ldr r2, [pc, #0x3a4] */
/* @0x001ebb48 ldr r3, [r3] */
/* @0x001ebb4c ldr r2, [r7, r2] */
/* @0x001ebb50 ldrsh r0, [r3, #20]——纹理号 = int16[page+0x14] */
/* @0x001ebb54 ldr r11, [r2] */
/* @0x001ebb58 str r3, [sp, #0x70] */
/* @0x001ebb5c bl 0x173e2c <_Z17GR_Texture_Existsi>——GR_Texture_Exists(纹理号) */
/* @0x001ebb60 ldr r3, [sp, #0x70] */
/* @0x001ebb64 cmp r0, #0 */
/* @0x001ebb68 beq 0x1ebc68 <_ZN7CSprite13DrawSWFObjectEP18SWF_TimelineObjectP8yyMatrixS3_PjS4_S4_S4_b+0x1d8>——纹理不存在 → 0x1ebc68 */

/* ── 全局开关 + 纹理表定位 ──────────────────────────────────────────────────────
 *   r11 = *GOT 0x3f1b80（0x1ebb44 的字面量 -216 与 r7 基址相加）→ `adds r11,r11,#0` +
 *     `movne r11,#1` ⇒ r11 = (全局 != 0)，落 [sp+0x68]（作为第 7 实参 bool 传出）。
 *   r1 = *GOT 0x3ed924（纹理表，池字 -0x4334）；r3 = [r1+4]（数据基址）；
 *     r3 = [r3 + id*4]（表项）；r7 = [r3]（Texture*，0x1ebba0）。
 *   ★ GOT 基址 0x3f1c58 由 0x1ebac0 的 0x00206188 + pc 算出（0x1ebac8 `add r7,pc,r7`），
 *     与 DrawShape 卡同一基址；本函数的 7 个字面量全部是「基址相对偏移」。
 */
/* @0x001ebb6c ldr r1, [pc, #0x380] */
/* @0x001ebb70 adds r11, r11, #0 */
/* @0x001ebb74 ldrsh r2, [r3, #20] */
/* @0x001ebb78 movne r11, #1 */
/* @0x001ebb7c str r11, [sp, #0x68] */
/* @0x001ebb80 ldrsh r11, [r3] */
/* @0x001ebb84 ldr r1, [r7, r1] */
/* @0x001ebb88 ldrsh r3, [r3, #2] */
/* @0x001ebb8c vmov s14, r11 */
/* @0x001ebb90 vmov s15, r3 */
/* @0x001ebb94 ldr r3, [r1, #0x4] */
/* @0x001ebb98 vcvt.f32.s32 s14, s14 */
/* @0x001ebb9c ldr r3, [r3, r2, lsl #2] */
/* @0x001ebba0 ldr r7, [r3]——Texture* */
/* @0x001ebba4 vldr s11, [r7, #4] */
/* @0x001ebba8 vcvt.f32.s32 s15, s15 */

/* ── UV 比例：s14 = (float)int16[page+0x00] / (float)tex[+4]，s15 同 / tex[+8] ────────
 *   0x1ebb88 ldrsh r3,[r3,#2] → s15；0x1ebb8c/0x1ebb90 vmov + 0x1ebb98/0x1ebba8 vcvt.f32.s32；
 *   0x1ebbb8/0x1ebbbc vdiv.f32。tex[+4]/tex[+8] 两个 int 先 vcvt.f32.s32 再当除数
 *   （按用法推定为纹理宽/高 —— 名字是读法，不是证据）。
 *   ★ 两个 int16 与宽高相除 ⇒ 归一化到 [0,1]，即**子图 UV 原点**；它们与 §1 里
 *     0x1e90e8 段给显示项写的 +0x40..+0x4c 四个 float 不是同一组量（后者是 ×g 的颜色/矩阵量）。
 */
/* @0x001ebbac vcvt.f32.s32 s12, s11 */
/* @0x001ebbb0 vldr s11, [r7, #8] */
/* @0x001ebbb4 vcvt.f32.s32 s13, s11 */
/* @0x001ebbb8 vdiv.f32 s14, s14, s12——s14 = uv0.x / 纹理宽 */
/* @0x001ebbbc vdiv.f32 s15, s15, s13——s15 = uv0.y / 纹理高 */

/* ── 绘制闸 + 12 字实参装配（矩阵按值拆成 r2/r3 + 14 字栈）──────────────────────────
 *   obj[+0x00] == 0 → 0x1ebc58 直接返回 0（0x1ebbc4/0x1ebbc8）。
 *   item = [this+0x7c][ obj[+4] ]（0x1ebbcc..0x1ebbe0，步长 4 的指针数组）。
 *   栈字落位（与 AAPCS「复合类型拆分」对应）：
 *     sp+0x00..0x37 ← sp+264..319（矩阵第 2..15 字，4 组 ldm/stm，0x1ebbd0..0x1ebc48）
 *     sp+0x38 = s16（float）        sp+0x3c = flag(第 8 形参)
 *     sp+0x40 = [sp+0x68]（纹理存在标志，bool）
 *     sp+0x44 = 形参 b（yyMatrix*）  sp+0x48 = c2    sp+0x4c = c4
 *     sp+0x50 = sp+512             sp+0x54 = sp+576  sp+0x58 = sp+640
 *     sp+0x5c = Texture*           sp+0x60 = uv.x   sp+0x64 = uv.y
 *   ★ **实名对不齐**：mangled 名 ...PjS4_S4_S4_PiS5_S5_P7Textureff 在 by-value 矩阵之后要求
 *     13 个字（1 float + 2 bool + 8 指针 + 2 float），实测只落了 12 个字（sp+0x38..0x64）。
 *     也就是说「4 个 uint32* + 3 个 int* + Texture*」这 8 个指针里只有 7 个能在这个调用点找到
 *     出处；本卡只钉住**字面落位**，不把 12 个字硬套到 13 个形参名上（见 open 第 9 条）。
 *   ★ 0x1ebc44 `ldm r9,{r2,r3}` 把矩阵第 0/1 字装进寄存器实参 —— 这是 AAPCS 允许的
 *     "split between registers and stack"，也是最容易算错 8 字节的地方。
 */
/* @0x001ebbc0 ldr r3, [r10] */
/* @0x001ebbc4 cmp r3, #0 */
/* @0x001ebbc8 beq 0x1ebc58 <_ZN7CSprite13DrawSWFObjectEP18SWF_TimelineObjectP8yyMatrixS3_PjS4_S4_S4_b+0x1c8> */
/* @0x001ebbcc ldr r11, [r8, #0x7c] */
/* @0x001ebbd0 add lr, sp, #264 */
/* @0x001ebbd4 ldr r10, [r10, #0x4] */
/* @0x001ebbd8 mov r12, sp */
/* @0x001ebbdc ldm lr!, {r0, r1, r2, r3} */
/* @0x001ebbe0 ldr r10, [r11, r10, lsl #2]——item = this[+0x7c][ obj[+4] ] */
/* @0x001ebbe4 vstr s16, [sp, #56] */
/* @0x001ebbe8 ldr r11, [sp, #0x68] */
/* @0x001ebbec vstr s14, [sp, #96] */
/* @0x001ebbf0 vstr s15, [sp, #100] */
/* @0x001ebbf4 str r5, [sp, #0x50] */
/* @0x001ebbf8 str r10, [sp, #0x6c] */
/* @0x001ebbfc ldr r10, [sp, #0x78] */
/* @0x001ebc00 str r11, [sp, #0x40] */
/* @0x001ebc04 ldr r11, [sp, #0x2f4] */
/* @0x001ebc08 str r10, [sp, #0x3c] */
/* @0x001ebc0c ldr r10, [sp, #0x7c] */
/* @0x001ebc10 str r11, [sp, #0x48] */
/* @0x001ebc14 str r4, [sp, #0x54] */
/* @0x001ebc18 str r10, [sp, #0x44] */
/* @0x001ebc1c ldr r10, [sp, #0x2fc] */
/* @0x001ebc20 str r6, [sp, #0x58] */
/* @0x001ebc24 str r7, [sp, #0x5c] */
/* @0x001ebc28 str r10, [sp, #0x4c] */
/* @0x001ebc2c stm r12!, {r0, r1, r2, r3} */
/* @0x001ebc30 ldm lr!, {r0, r1, r2, r3} */
/* @0x001ebc34 stm r12!, {r0, r1, r2, r3} */
/* @0x001ebc38 ldm lr!, {r0, r1, r2, r3} */
/* @0x001ebc3c stm r12!, {r0, r1, r2, r3} */
/* @0x001ebc40 ldm lr, {r0, r1} */
/* @0x001ebc44 ldm r9, {r2, r3} */
/* @0x001ebc48 stm r12, {r0, r1} */
/* @0x001ebc4c mov r0, r8——DrawDictionaryItem：r2/r3 = 矩阵前 2 字 */
/* @0x001ebc50 ldr r1, [sp, #0x6c] */

/* ── 调用 DrawDictionaryItem 并返回 0 ──────────────────────────────────────────────
 *   r0 = this、r1 = item（[sp+0x6c] 的溢出槽，0x1ebbf8 存、0x1ebc50 取）。
 *   返回值恒 0（0x1ebc58 `mov r0,#0`）—— 本函数没有失败返回。
 */
/* @0x001ebc54 bl 0x1e9c10 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff> */
/* @0x001ebc58 mov r0, #0 */
/* @0x001ebc5c add sp, sp, #708 */
/* @0x001ebc60 vpop {d8} */
/* @0x001ebc64 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── 纹理缺失旁路：s15/s14 = 0.0f（池字 0x1ebee8）、[sp+0x68] = 0、r7 = 0 ─────────────
 *   ★ r7（Texture*）置 0 后仍作为第 12 实参传下去 —— 下游必须容忍空纹理（DrawDictionaryItem
 *     的第 12 形参是 Texture*）。这解释了为什么 §2 从不检查 r7 再用。
 */
/* @0x001ebc68 vldr s15, [pc, #632] */
/* @0x001ebc6c mov r7, r0 */
/* @0x001ebc70 vmov.f32 s14, s15 */
/* @0x001ebc74 str r0, [sp, #0x68] */
/* @0x001ebc78 b 0x1ebbc0 <_ZN7CSprite13DrawSWFObjectEP18SWF_TimelineObjectP8yyMatrixS3_PjS4_S4_S4_b+0x130> */

/* ── 3D 合流：Graphics 三层矩阵 → 三次 Multiply → 与本地矩阵左乘 ─────────────────────
 *   GetMatrix(2, sp+320) / GetMatrix(0, sp+384) / GetMatrix(1, sp+448)（0x1ebc94/cac/cbc）。
 *   Multiply(sp+512, sp+320, sp+384) = M2·M0（0x1ebcd0）
 *   Multiply(sp+576, sp+512, sp+448) = (M2·M0)·M1（0x1ebce0）
 *   Multiply(sp+640, sp+256, sp+576) = M_local ·(M2·M0·M1)（0x1ebcf0）—— 注意左乘次序：
 *     r1 = r9 = sp+256（本地矩阵）在前，chain 在后 ⇒ 结果是「先在屏幕空间、再进本地空间」。
 *   ★ 三个目标缓冲 sp+512/576/640 正是 2D 路里放三个颜色块的地方 ⇒ 3D 路做完投影后它们被覆盖，
 *     两者**互斥**（flag 就是这个闸）。
 */
/* @0x001ebc7c add r3, sp, #320 */
/* @0x001ebc80 mov r0, #2 */
/* @0x001ebc84 str r3, [sp, #0x70] */
/* @0x001ebc88 add r11, sp, #448 */
/* @0x001ebc8c mov r1, r3 */
/* @0x001ebc90 add r5, sp, #512 */
/* @0x001ebc94 bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf>——GetMatrix(2, sp+320) */
/* @0x001ebc98 add r2, sp, #384 */
/* @0x001ebc9c mov r0, #0 */
/* @0x001ebca0 str r2, [sp, #0x74] */
/* @0x001ebca4 mov r1, r2 */
/* @0x001ebca8 add r4, sp, #576 */
/* @0x001ebcac bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf>——GetMatrix(0, sp+384) */
/* @0x001ebcb0 mov r1, r11 */
/* @0x001ebcb4 mov r0, #1 */
/* @0x001ebcb8 add r6, sp, #640 */
/* @0x001ebcbc bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf>——GetMatrix(1, sp+448) */
/* @0x001ebcc0 ldr r3, [sp, #0x70] */
/* @0x001ebcc4 ldr r2, [sp, #0x74] */
/* @0x001ebcc8 mov r0, r5 */
/* @0x001ebccc mov r1, r3 */
/* @0x001ebcd0 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_>——sp+512 = M2·M0 */
/* @0x001ebcd4 mov r2, r11 */
/* @0x001ebcd8 mov r1, r5 */
/* @0x001ebcdc mov r0, r4 */
/* @0x001ebce0 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_>——sp+576 = (M2·M0)·M1 */
/* @0x001ebce4 mov r2, r4 */
/* @0x001ebce8 mov r0, r6 */
/* @0x001ebcec mov r1, r9 */
/* @0x001ebcf0 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_>——sp+640 = M_local·chain（左乘本地矩阵） */

/* ── 常量与全局：0.0f 初始化 + 两个 int 标量 + 全局 float z ────────────────────────
 *   s12/s15/s11 = 0.0f；sp+0x98 与 sp+0xa4 = 1.0f（0x1ebd04 `mov r1,#1065353216`）；
 *   s2 = (float)*GOT 0x3f014c（池字 -0x1b0c，0x1ebd08）、s3 = (float)*GOT 0x3f0150（-0x1b08）；
 *   s10 = *(float*)GOT 0x3ed928（+z，池字 -0x4330，0x1ebd28/0x1ebd48）。
 *   ★ 0x1ebd1c/0x1ebd2c/0x1ebd30 三个输出指针：sp+152（输入游标）、sp+168（输出游标）、
 *     sp+184（循环终点）—— 循环恰好两轮（168→176→184，见 0x1ebd7c 的 cmp）。
 */
/* @0x001ebcf4 ldr r2, [pc, #0x1fc] */
/* @0x001ebcf8 ldr r3, [pc, #0x1fc] */
/* @0x001ebcfc vldr s15, [pc, #484] */
/* @0x001ebd00 vmov.f32 s12, s15 */
/* @0x001ebd04 mov r1, #1065353216 */
/* @0x001ebd08 ldr r12, [r7, r2] */
/* @0x001ebd0c vldr s2, [r12] */
/* @0x001ebd10 ldr r0, [r7, r3] */
/* @0x001ebd14 vldr s3, [r0] */
/* @0x001ebd18 str r1, [sp, #0x98] */
/* @0x001ebd1c add r2, sp, #152 */
/* @0x001ebd20 vcvt.f32.s32 s2, s2 */
/* @0x001ebd24 str r1, [sp, #0xa4] */
/* @0x001ebd28 ldr r1, [pc, #0x1d0] */
/* @0x001ebd2c add r3, sp, #168 */
/* @0x001ebd30 add r0, sp, #184 */
/* @0x001ebd34 vstr s15, [sp, #144] */
/* @0x001ebd38 vstr s15, [sp, #148] */
/* @0x001ebd3c vstr s15, [sp, #156] */
/* @0x001ebd40 vstr s15, [sp, #160] */
/* @0x001ebd44 ldr r1, [r7, r1] */
/* @0x001ebd48 vldr s10, [r1] */
/* @0x001ebd4c vcvt.f32.s32 s3, s3 */
/* @0x001ebd50 vmov.f32 s11, s15 */

/* ── 两点投影循环（两轮）：(0,0) 与 (1,0) 过 4×4 矩阵 + 透视除法，再乘两个全局标量 ───────
 *   每轮用 s11/s12 当输入 x/y（首轮 0/0 由 0x1ebd00/0x1ebd50 置，次轮 1/0 来自 sp+152/156），
 *   分子 = s12·m[k] + s11·m[k+1] + z·m[k+2] + m[k+3]（三条 vmul/vmla + 一条 vadd），
 *   分母 = 同一组合的另一行（s13，含 s8/s15 两个平移项），`vdiv` 得 w 后乘 s2/s3 落 [r3-8]/[r3-4]。
 *   ★ 结果落 sp+160..175：两轮共 4 个 float；随后 0x1ebdec 段读 sp+168..188 六个字求边长，
 *     其中 sp+176..191 **本函数内无写点**（见 open 第 3 条）。
 *   ★ 分母里 s8/s15 是矩阵的 e14/e15 平移项、s10 是全局 z ⇒ 这是一次「齐次坐标 + 透视」而不是
 *     普通 2×3 仿射 —— 与 2D 路（yyMatrix::Multiply）不是同一套数学。
 */
/* @0x001ebd54 vldr s13, [sp, #668] */
/* @0x001ebd58 vldr s14, [sp, #656] */
/* @0x001ebd5c vldr s4, [sp, #652] */
/* @0x001ebd60 vldr s5, [sp, #640] */
/* @0x001ebd64 vmul.f32 s13, s12, s13 */
/* @0x001ebd68 vldr s7, [sp, #672] */
/* @0x001ebd6c vldr s6, [sp, #684] */
/* @0x001ebd70 vldr s8, [sp, #700] */
/* @0x001ebd74 vldr s15, [sp, #688] */
/* @0x001ebd78 vldr s9, [r1] */
/* @0x001ebd7c cmp r3, r0 */
/* @0x001ebd80 add r2, r2, #8 */
/* @0x001ebd84 add r3, r3, #8 */
/* @0x001ebd88 vmul.f32 s14, s12, s14 */
/* @0x001ebd8c vmla.f32 s13, s11, s4 */
/* @0x001ebd90 vmla.f32 s14, s11, s5 */
/* @0x001ebd94 vmla.f32 s13, s10, s6 */
/* @0x001ebd98 vmla.f32 s14, s10, s7 */
/* @0x001ebd9c vadd.f32 s13, s13, s8 */
/* @0x001ebda0 vadd.f32 s14, s14, s15 */
/* @0x001ebda4 vdiv.f32 s14, s14, s13——透视除法 */
/* @0x001ebda8 vmul.f32 s14, s2, s14 */
/* @0x001ebdac vstr s14, [r3, #-8]——落 sp+160/164（第一点） */
/* @0x001ebdb0 vmov.f32 s10, s9 */
/* @0x001ebdb4 vldr s15, [sp, #660] */
/* @0x001ebdb8 vldr s7, [sp, #644] */
/* @0x001ebdbc vldr s8, [sp, #676] */
/* @0x001ebdc0 vldr s14, [sp, #692] */
/* @0x001ebdc4 vmul.f32 s15, s12, s15 */
/* @0x001ebdc8 vmla.f32 s15, s11, s7 */
/* @0x001ebdcc vmla.f32 s15, s9, s8 */
/* @0x001ebdd0 vadd.f32 s15, s15, s14 */
/* @0x001ebdd4 vdiv.f32 s13, s15, s13 */
/* @0x001ebdd8 vmul.f32 s13, s3, s13 */
/* @0x001ebddc vstr s13, [r3, #-4] */
/* @0x001ebde0 vldrne s11, [r2, #-8] */
/* @0x001ebde4 vldrne s12, [r2, #-4] */
/* @0x001ebde8 bne 0x1ebd54 <_ZN7CSprite13DrawSWFObjectEP18SWF_TimelineObjectP8yyMatrixS3_PjS4_S4_S4_b+0x2c4>——两轮：r3 = 168 → 176 → 184 */

/* ── 第一条边长：d1² = (Δx)² + (Δy)²，s16 = sqrt(d1²) ────────────────────────────────
 *   s12=[sp+168] s14=[sp+176] s13=[sp+172] s15=[sp+180] s10=[sp+184] s11=[sp+188]；
 *   s14 -= s12、s15 -= s13、s12 = s10-s12、s13 = s11-s13（四条 vsub），s16 = s14²+s15²（vmul+vmla）。
 *   0x1ebe28 `vcmpe s16,#0` + ble → 跳过 sqrt；否则 vsqrt + NaN 检查（真则 0x1ebed8 走 sqrtf@plt）。
 *   ★ 「≤0 就跳过」是编译器为 sqrt(-0)/0 做的合法化，不是业务分支。
 */
/* @0x001ebdec vldr s12, [sp, #168] */
/* @0x001ebdf0 vldr s14, [sp, #176] */
/* @0x001ebdf4 vsub.f32 s14, s14, s12 */
/* @0x001ebdf8 vldr s13, [sp, #172] */
/* @0x001ebdfc vldr s15, [sp, #180] */
/* @0x001ebe00 vldr s10, [sp, #184] */
/* @0x001ebe04 vldr s11, [sp, #188] */
/* @0x001ebe08 vmul.f32 s16, s14, s14 */
/* @0x001ebe0c vstr s14, [sp, #128] */
/* @0x001ebe10 vsub.f32 s15, s15, s13 */
/* @0x001ebe14 vmla.f32 s16, s15, s15 */
/* @0x001ebe18 vstr s15, [sp, #132] */
/* @0x001ebe1c vsub.f32 s12, s10, s12 */
/* @0x001ebe20 vsub.f32 s13, s11, s13 */
/* @0x001ebe24 vstr s12, [sp, #136] */
/* @0x001ebe28 vcmpe.f32 s16, #0——d1² ≤ 0 跳过 sqrt */
/* @0x001ebe2c vstr s13, [sp, #140] */
/* @0x001ebe30 vmrs APSR_nzcv, fpscr */
/* @0x001ebe34 ble 0x1ebe4c <_ZN7CSprite13DrawSWFObjectEP18SWF_TimelineObjectP8yyMatrixS3_PjS4_S4_S4_b+0x3bc> */
/* @0x001ebe38 vsqrt.f32 s15, s16 */
/* @0x001ebe3c vcmp.f32 s15, s15 */
/* @0x001ebe40 vmrs APSR_nzcv, fpscr */
/* @0x001ebe44 bne 0x1ebed8 <_ZN7CSprite13DrawSWFObjectEP18SWF_TimelineObjectP8yyMatrixS3_PjS4_S4_S4_b+0x448> */
/* @0x001ebe48 vmov.f32 s16, s15 */

/* ── 第二条边长 + 两个 sqrtf@plt 回退 ──────────────────────────────────────────────
 *   s15 = s12²+s13²（sp+136/140 的两个分量）；s13 = 0.0f 作比较阈值；
 *   `vcmpe s16,#0` + `vmovle.f32 s16,s13` ⇒ s16 若 ≤0 就钳成 0；s15 ≤0 直接跳过 sqrt。
 *   ★ 0x1ebe7c/0x1ebe80 的 `vcmp s14,s14` + bne 是 NaN 自检的固定写法（与 §1 的 vsqrt 同构）。
 */
/* @0x001ebe4c vldr s15, [sp, #136] */
/* @0x001ebe50 vldr s14, [sp, #140] */
/* @0x001ebe54 vldr s13, [pc, #140] */
/* @0x001ebe58 vmul.f32 s15, s15, s15 */
/* @0x001ebe5c vmla.f32 s15, s14, s14 */
/* @0x001ebe60 vcmpe.f32 s16, #0 */
/* @0x001ebe64 vmrs APSR_nzcv, fpscr */
/* @0x001ebe68 vcmpe.f32 s15, s13 */
/* @0x001ebe6c vmovle.f32 s16, s13 */
/* @0x001ebe70 vmrs APSR_nzcv, fpscr */
/* @0x001ebe74 ble 0x1ebe8c <_ZN7CSprite13DrawSWFObjectEP18SWF_TimelineObjectP8yyMatrixS3_PjS4_S4_S4_b+0x3fc> */
/* @0x001ebe78 vsqrt.f32 s14, s15 */
/* @0x001ebe7c vcmp.f32 s14, s14 */
/* @0x001ebe80 vmrs APSR_nzcv, fpscr */
/* @0x001ebe84 bne 0x1ebec8 <_ZN7CSprite13DrawSWFObjectEP18SWF_TimelineObjectP8yyMatrixS3_PjS4_S4_S4_b+0x438> */
/* @0x001ebe88 vmov.f32 s15, s14 */

/* ── 缩放合成：s16 = g2 × (1 / (0.5·max(s15,s16)))，≤0 时退化为 1.0 ─────────────────────
 *   r3 = *GOT 0x3ee5c0（float g2，池字 -0x3698）；s14 = 0.5f（0x1ebe90 `vmov.f32 s14,#5e-1`）。
 *   `vcmp s15,s16` + `vmovgt s16,s15` ⇒ max；`vmul s16,s16,s14` ⇒ ×0.5；
 *   `vcmpe s16,#0` + `vmovgt s15,#1.0` + `vdivgt s16,s15,s16` ⇒ 正数取倒数，否则 1.0；
 *   最后 `vmul s16,s16,s15(=g2)` ⇒ s16 = g2 / (0.5·max)。
 *   ★ 与 DrawShape 卡的 f3 = g2/(0.5·max(|e1|,|e2|)) 是**同一个公式、同一个全局 0x3ee5c0** ——
 *     两条独立路径互证了这条缩放律。
 *   ★ 0x1ebec4 `b 0x1ebb10` 回到三组 4 字拷贝：3D 路的投影结果只在 s16 上留痕。
 */
/* @0x001ebe8c ldr r3, [pc, #0x70]——g2 = *GOT 0x3ee5c0 */
/* @0x001ebe90 vmov.f32 s14, #5.000000e-01 */
/* @0x001ebe94 ldr r3, [r7, r3] */
/* @0x001ebe98 vcmp.f32 s15, s16 */
/* @0x001ebe9c vmrs APSR_nzcv, fpscr */
/* @0x001ebea0 vmovgt.f32 s16, s15 */
/* @0x001ebea4 vmul.f32 s16, s16, s14 */
/* @0x001ebea8 vcmpe.f32 s16, #0 */
/* @0x001ebeac vmrs APSR_nzcv, fpscr */
/* @0x001ebeb0 vmovgt.f32 s15, #1.000000e+00 */
/* @0x001ebeb4 vdivgt.f32 s16, s15, s16——1/(0.5·max) */
/* @0x001ebeb8 vldr s15, [r3] */
/* @0x001ebebc vmovle.f32 s16, #1.000000e+00 */
/* @0x001ebec0 vmul.f32 s16, s16, s15 */
/* @0x001ebec4 b 0x1ebb10 <_ZN7CSprite13DrawSWFObjectEP18SWF_TimelineObjectP8yyMatrixS3_PjS4_S4_S4_b+0x80>——回主路（s16 已就位） */

/* ── 两条 sqrtf@plt 回退桩（0x1ebec8 / 0x1ebed8）────────────────────────────────────
 *   vmov r0,sN → bl 0xb6700 → vmov sN,r0 → 跳回热路径（0x1ebe88 / 0x1ebe48）。
 */
/* @0x001ebec8 vmov r0, s15 */
/* @0x001ebecc bl 0xb6700 <sqrtf@plt> */
/* @0x001ebed0 vmov s14, r0 */
/* @0x001ebed4 b 0x1ebe88 <_ZN7CSprite13DrawSWFObjectEP18SWF_TimelineObjectP8yyMatrixS3_PjS4_S4_S4_b+0x3f8> */
/* @0x001ebed8 vmov r0, s16 */
/* @0x001ebedc bl 0xb6700 <sqrtf@plt>——sqrtf@plt 回退 */
/* @0x001ebee0 vmov s15, r0 */
/* @0x001ebee4 b 0x1ebe48 <_ZN7CSprite13DrawSWFObjectEP18SWF_TimelineObjectP8yyMatrixS3_PjS4_S4_S4_b+0x3b8> */

/* ── 字面量池（8 字，0x1ebee8..0x1ebf04）：1 个 float + 7 个 GOT 相对偏移 ─────────────
 *   0x1ebee8 = 0x00000000（0.0f，0x1ebc68/0x1ebcfc/0x1ebe54 三处 vldr 的目标）
 *   0x1ebeec = 0x00206188 → GOT 基址 0x3f1c58（0x1ebac8 `add r7,pc,r7`）
 *   0x1ebef0 = 0xffffe828（-216）   → 0x3f1b80（全局 int，第 7 实参 bool 的来源）
 *   0x1ebef4 = 0xffffbccc（-17204） → 0x3ed924（纹理表）
 *   0x1ebef8 = 0xffffe4f4（-6924）  → 0x3f014c（int 标量 → s2）
 *   0x1ebefc = 0xffffe4f8（-6920）  → 0x3f0150（int 标量 → s3）
 *   0x1ebf00 = 0xffffbcd0（-17200） → 0x3ed928（float z）
 *   0x1ebf04 = 0xffffc968（-13976） → 0x3ee5c0（float g2）
 *   ★ objdump 把前两字译成 andeq/eoreq，其余译成 .word，**八个都不是指令**。
 */
/* @0x001ebee8 andeq r0, r0, r0 */
/* @0x001ebeec eoreq r6, r0, r8, lsl #3 */
/* @0x001ebef0 .word 0xffffe828 */
/* @0x001ebef4 .word 0xffffbccc */
/* @0x001ebef8 .word 0xffffe4f4 */
/* @0x001ebefc .word 0xffffe4f8 */
/* @0x001ebf00 .word 0xffffbcd0 */
/* @0x001ebf04 .word 0xffffc968 */

/* ── 收束：两节合起来说明的一件事（也是本卡最值得留的六条）───────────────────────────────
 *   1. 数据形状是「容器套容器、每层自带计数」：header(version+跳过长度) → 字典项数 n →
 *      n 个项(type 1/2/其它) → 每项 n3 条 24 B 子记录 → 每条子记录 9 组数组 + 一个 84 B 记录
 *      数组；再往上是影片段：帧数 → 24 B 帧 → 144 B 显示项。**每一层的计数都为 0 有明确出口**，
 *      且计数为 0 时指针严格写 0、不调用 Alloc（§1 九组数组的九个「跳过」出口 + 0x1e9094/0x1e8a2c）。
 *   2. 显示项 144 B 与绘制口 obj+0x50 是同一套结构：§1 把 [0x50,0x90) 写成单位 4×4，
 *      §2 第一件事就是把这 64 B 拷出来乘上层矩阵。两段在**没有任何共享符号**的前提下互证了
 *      「子项 144 B、矩阵在 +0x50」这条已知事实。
 *   3. 版本号是唯一的格式开关：[sp+0x44] 一处存、四处比（≤7 定子项头长、≥8 多读一字、
 *      ≤4/==5/≥6 定 84 B 记录头 32/40/48 B）。⇒ 这套二进制格式至少有 3 个不兼容小版本。
 *   4. §1 只写 this 与两个 new 出来的容器（+0x7c/+0x80/+0x84），**不碰任何全局**；
 *      §2 反过来**只读全局、不写 this**（0 条 str [r8…]）。⇒ 装载与绘制在副作用上完全分离。
 *   5. 同一个全局 float 在两个不同函数里承担同一种角色：§1 用它把影片矩阵的四个 float 缩放后存档
 *      （0x1e9028 的 0x3f0ddc），§2（3D 路）用 0x3ee5c0 把一个「1/(0.5·最大边长)」的比例乘回去，
 *      而 DrawShape 卡在另一条独立路径上也用 0x3ee5c0 做同一个除法 ⇒ 这套坐标里存在「单位换算」
 *      与「屏幕缩放」两个不同的全局常量，不能混用。
 *   6. §2 的 flag 是一个**后端选择**而不是开关：flag==0 走 yyMatrix::Multiply 的 2D 仿射链；
 *      flag≠0 走 Graphics::GetMatrix(2/0/1) 的三层合成 + 透视除法 + 比例缩放。两条路的产物
 *      只是 s16 不同（1.0 vs g2/(0.5·max)），矩阵本身都还是 §1 存的本地矩阵 —— 所以同一份数据
 *      在 2D/3D 两种渲染路径下画出的**几何相同、缩放不同**。
 *
 * ── open ─────────────────────────────────────────────────────────────────────
 *   1. 92 B / 80 B / 8 B 三种子项的字段语义：尺寸与写点全钉（92 B 的 +0x4c/+0x50 是渐变档数/指针、
 *      80 B 的 +0x0c 是「引用前项的下标」），但 +0x10/+0x14/+0x20/… 这些位置对应的 SWF 标签字段名
 *      没有符号或字符串证据（本仓库无 libyoyo.so 副本，.rodata 串无法读）。
 *   2. 84 B 记录里 9 个数组的单位与含义：只证到「每份记录在源里占 2 个或 3 个字、目标按 8/4/6 字节
 *      一份分配」与「计数 0 不分配」，没有证到每一组是顶点/边/UV/索引中的哪一种。
 *   3. §2 的 0x1ebd54 投影循环：结果只落 sp+160..175 四个 float，但 0x1ebdec 段读 sp+168..188
 *      六个字，其中 sp+176/180/184/188 在本函数内**没有写点**。要么这两轮循环本该有四轮
 *      （终点 sp+184 的常量可能是别处被改写的），要么这段读的是调用者预留的栈槽 —— 两种都无证据。
 *   4. §2 第 6 形参 yyMatrix*（sp+0x44，来自形参 b）的用途：DrawDictionaryItem 侧才知道它是
 *      「父矩阵」还是「输出矩阵」；本卡只证到「原样透传」。
 *   5. 三组 16 B 块（obj+0x10/+0x20/+0x30 → sp+512/576/640）的语义：按「4 字」透传，既可能是
 *      4 个 ARGB，也可能是 8 个 16 位（UV/索引）。§1 的对应写点（0x1e9200 的 4 字循环把同一块
 *      数据同时写进显示项 +0x10 与 +0x30）只支持「两组来自同源」，不支持任何具体类型。
 *   6. this+0x54 的二级解引用：`[this+0x54] → 首字 → +0x14 纹理号 / +0x00,+0x02 两个 int16`，
 *      但「首字」是谁写的，§1 里没有对应写点（§1 只写 +0x7c/+0x80/+0x84 与尺寸字段）⇒
 *      这一层要么由别的函数（DrawDictionaryItem 卡范围）建立，要么由构造期写入。未钉。
 *   7. §1 池里的 23 个串偏移落点（0x331024/0x33102c/0x331038/0x34e42c/0x352418/0x35241c/
 *      0x352420 …）对应的源码文件串内容未读：本仓库只有 asm/ 与 cards/，没有 libyoyo.so 副本，
 *      也没有 .rodata dump ⇒ 「哪个 Alloc 属于哪个源文件」这条线索到此为止。
 *   8. 返回值语义：§1 只返回 0/1（0 = data 空，1 = 建完），没有部分成功/失败码；§2 恒返回 0。
 *      「Alloc 失败」在本函数里没有任何检查（26 次 Alloc 全部直接解引用返回值）。
 *   9. §2 的实参个数与 mangled 名差一个：名里 matrix 之后要 13 个字，实测 12 个
 *      （sp+0x38/0x3c/0x40/0x44/0x48/0x4c/0x50/0x54/0x58/0x5c/0x60/0x64）。可能是
 *      (a) 3 个 int* 里有一个在这个调用点被省掉（例如传了同一个指针两次而被合并），或
 *      (b) 该地址上还有第二个更短签名的入口（别名）。本卡不猜，只记落位。
 *
 * ── 自检 ─────────────────────────────────────────────────────────────────────
 *   裁切索引（只含本卡两段 0x1e838c..0x1e9728 与 0x1eba90..0x1ebf08）跑
 *   scripts/check_card_anchors.py：
 *     index=1542 card=1542 missing=0 extra=0 mismatch=0 RESULT EXACT
 *   用整份 asm/index-CSprite_SWF_all.tsv（3494 条，含 DrawDictionaryItem 段）会报
 *   1952 missing —— 那 1952 条属别的卡，本卡按约定不重复、不发锚点。
 *
 * ── 引用面（本轮只读，未改任何其它文件）──────────────────────────────────────────
 *   asm/index-CSprite_SWF_all.tsv（3494 行，本卡用 §1 段 0x1e838c 起 1256 行 + §2 段 286 行）
 *   asm/functions.tsv（0x1e838c/0x1eba90/0x1e9c10/0x1e7c8c/0x1e7e1c/0x1e8264 六条符号与尺寸）
 *   asm/instructions.jsonl.xz（f 字段用于确认两段边界内无外函数指令）
 *   cards/CSprite_DrawShape.c（段 A 的 1ec408/1ec410：帧/子项读法与 §1 的 24/144 B 互证；
 *     其 open 第 3 条「帧表 ×8 步长不自洽」在本卡得到解释：帧=24 B、显示项=144 B、项数组=4 B）
 *   scripts/check_card_anchors.py（RESULT EXACT 的判定器）
 */
