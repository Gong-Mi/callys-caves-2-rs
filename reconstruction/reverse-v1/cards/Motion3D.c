/* cally 逆向卡：Motion3D（原版 libyoyo.so，armv7）
 * §1 Motion_Grid_Path(int, CPath*, int, int, int, int, bool)          0x19a8f8 size 6324 1581 条
 * §2 GR_3D_Draw_Block(float×6, int, float, float)                    0x17763c size 5896 1474 条
 * 总账: 3055 锚点 = 1581 + 1474，与 asm/index-Motion_Grid_Path.tsv / asm/index-GR_3D_Draw_Block.tsv 逐字一致
 *       （scripts/check_card_anchors.py：missing=0 extra=0 mismatch=0 ⇒ RESULT EXACT）。
 *       其中 §1 有 18 个池字、§2 有 9 个池字是 literal pool（objdump 会把它们解成「像指令」的样子），锚点保留原写法。
 * 级别: 骨架（两节都到「结构 + 关键写点」）。未钉项按节列在各自的 open 里，不在正文里含糊。
 * 签名来源: .dynsym（_Z16Motion_Grid_PathiP5CPathiiiib / _Z16GR_3D_Draw_Blockffffffiff）
 * 锚点来源: 全部由 scripts/asm_index.py 从 ~/cally-oracle/libyoyo.so 生成，本卡未手写转录任何一条
 * 读法: 注释里的地址一律是**裸地址**（不带 @）；被调函数入口在注释里另写
 *
 * ── 这张卡回答的两个问题（任务书指定）────────────────────────────────────────
 *   1. 网格寻路对 path 字段写了什么？—— §1 全函数**零条固定偏移 store**（只有 124 条写 [sp+…] 与 19 条 base+index
 *      写数组），42 条固定偏移 load 全打在网格对象 r9 上（+4/+8/+0xc/+0x10/+0x14/+0x18/+0x1c）。
 *      ⇒ 它既没碰 CInstance 的 +0x128/+0x12c/+0x134/+0x144/+0x148，也没有直接写 CPath 的字段；
 *      对 path 的全部作用经 5 个方法：Clear 0x1a6f98、SetKind(0) 0x1a6e64、SetClosed(0) 0x1a6e78、
 *      AddPoint 0x1a72c0（2+N 次）、Reverse 0x1a76b4。把 CPath 的点搬进 CInstance+0x128… 是调用侧的事：
 *      唯一调用者 F_MpGridPath 0x10a03c 只把 int 返回值变成 1.0/0.0（0x10a0f8..0x10a114）。
 *   2. 3D 块的顶点/矩阵从哪来？—— §2 里没有任何矩阵：全函数只从内存读 2 个浮点全局
 *      （GOT 0x3F019C = 纹理宽、0x3F01A0 = 纹理高，只用于 UV 归一化）。顶点 x/y/z 直接来自实参
 *      （x∈{arg0,arg3}、y∈{arg1,arg4}、z∈{arg2,arg5} ⇒ 6 个浮点实参是两个对角点），
 *      法线的 ±1 来自 vmov 立即数与池字 0x00000000。36 个 36 字节顶点被追加进全局顶点缓冲
 *      （GOT 0x3F02C8/0x3F02D8/0x3F02DC），计数按顶点数 +36。变换不在本函数（D3D 固定管线/别处的矩阵状态）。
 *
 * ── 两节的关系 ─────────────────────────────────────────────────────────────
 *   没有任何调用/数据关系：一个是 GML 寻路（纯整数、写 CPath），一个是 D3D 方块顶点提交（纯浮点、写顶点缓冲）。
 *   放在一张卡里只因为它们同属「Motion/3D」这一批（任务书指定），互不作旁证。
 */



/* ══ §1 Motion_Grid_Path(int gridId, CPath* path, int x1, int y1, int x2, int y2, bool allowDiag) 0x19a8f8 ══
 * @func 0x19a8f8 0x19c1ac  size 6324  1581 条（末条 0x19c1a8；0x19b734..0x19b778 的 18 个字是 literal pool，
 *       objdump 把它们解成「像指令」的样子，锚点保留原写法）
 * 级别: 骨架（入口闸门、坐标→格子换算、环形队列 BFS 主循环、八邻域派发、路径写出五段逐条钉住；
 *       八方向各自的展开体只做结构核对；坑位编码与对角兜底分支未钉，见本节 open）
 * 符号: _Z16Motion_Grid_PathiP5CPathiiiib → int Motion_Grid_Path(int gridId, CPath* path, int x1, int y1, int x2, int y2, bool allowDiag)
 * 调用点: 全 .text 只有 0x10a0f8 一处，落在 F_MpGridPath 0x10a03c（GML 内建 mp_grid_path 的实现）体内：
 *       0x10a0d8 YYGetBool(arg,6) → 0x10a0f0 存进第 7 个实参槽 → 0x10a0f8 调用；
 *       0x10a0fc..0x10a114 把 int 返回值变成 1.0/0.0 双精度（movtne r3,#0x3ff0）⇒ 本函数的 1/0 就是 GML 的 true/false
 * 实参落位: r0=gridId  r1=path  r2=x1  r3=y1  [sp+0xa0]=x2  [sp+0xa4]=y2  [sp+0xa8]=allowDiag（帧 36+124=0xa0）
 * 返回值: 1 = 已把路径写进 CPath；0 = 参数/边界/障碍不满足，path 一个字节都没被改写
 *         （早退路径跳过格子复位，因为那时一个戳都还没打）
 *
 * ── 一句话 ──
 *   网格表按 id 取网格 → 起终点像素坐标各自换算成格子并查障碍哨兵 → 起点格打戳 1 入环形队列 →
 *   BFS 每弹一格就把「本格戳+1」写进 8 个邻居并压队 → 弹到终点格即转路径写出：
 *   CPath 清空 → 先写终点 → 沿戳递减逐格写格中心 → 最后写起点 → Reverse
 *   ⇒ 点序是起点→终点，所有点速度字段 100.0f。
 *
 * ── 网格对象布局（r9；本函数 42 条固定偏移 load 全部打在它身上）──
 *   +0x04 int hx（像素原点 x）    +0x08 int hy（像素原点 y）
 *   +0x0c int cellW               +0x10 int cellH
 *   +0x14 int cols                +0x18 int rows
 *   +0x1c int* cells（cols*rows 个 int；索引 = col*rows + row，列优先）
 *   互证：换算走 (px-hx)/cellW；越界闸用 hx+cellW*cols；复位循环外层 cols 内层 rows；所有索引都是 mla rows,col,row
 */
/* @0x19a8f8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x19a8fc sub sp, sp, #124 */
/* @0x19a900 mov r11, r1 */
/* @0x19a904 ldr r4, [pc, #0xe28] */
/* @0x19a908 ldrb r1, [sp, #0xa8] */
/* @0x19a90c cmp r0, #0 */
/* @0x19a910 add r4, pc, r4 */
/* @0x19a914 mov r10, r2 */
/* @0x19a918 mov r8, r3 */
/* @0x19a91c str r1, [sp, #0x1c] */

/* ── 帧、实参落位、网格表闸 ──
 *   9 个核寄存器 + 124 字节局部区；r4 = pc + 池字 0x00257340 = GOT 基址 0x3F1C58（与 DoSlowDrawRoom / CInstance 卡同一基址）
 *   arg7(bool) 用 ldrb 从 [sp+0xa8] 取出后立刻存 [sp+0x1c]：后面所有 allowDiag 判断都读这个栈槽
 *   三道闸全部返回 0：gridId < 0 → 0x19ae28；gridId >= *(GOT 0x3F06B4 双层解引用) → 0x19ae28
 *   （GOT 槽 → 对象 → [0] = 条数）；grids[gridId] == 0 → 0x19ae2c（mov r0,r9 把 0 直接当返回值）
 *   grids 基址 = *(GOT 0x3F06B8 双层解引用)
 */
/* @0x19a920 blt 0x19ae28 <_Z16Motion_Grid_PathiP5CPathiiiib+0x530> */
/* @0x19a924 ldr r3, [pc, #0xe0c] */
/* @0x19a928 ldr r3, [r4, r3] */
/* @0x19a92c ldr r3, [r3] */
/* @0x19a930 cmp r0, r3 */
/* @0x19a934 bge 0x19ae28 <_Z16Motion_Grid_PathiP5CPathiiiib+0x530> */
/* @0x19a938 ldr r3, [pc, #0xdfc] */
/* @0x19a93c ldr r3, [r4, r3] */
/* @0x19a940 ldr r3, [r3] */
/* @0x19a944 ldr r9, [r3, r0, lsl #2] */
/* @0x19a948 cmp r9, #0 */
/* @0x19a94c moveq r0, r9 */
/* @0x19a950 beq 0x19ae2c <_Z16Motion_Grid_PathiP5CPathiiiib+0x534> */

/* ── path 闸、队列对象、起点 x 闸 ──
 *   path == 0 → 0；r9 = 网格对象；r6 = *(GOT 0x3F06BC)（队列元素计数对象）非 0 才继续
 *   起点 x：x1 >= hx(+4) 且 x1 < hx + cellW*cols（0x19a9b4 的 mla）——任一不满足都回 0
 *   同时把 GOT 0x3F06C0 / 0x3F06C4 / 0x3F06C8 / 0x3F06CC 四个对象指针读出来，并先把三处计数清 0（0x19a998/0x19a99c/0x19a9a4）
 */
/* @0x19a954 cmp r11, #0 */
/* @0x19a958 beq 0x19ae28 <_Z16Motion_Grid_PathiP5CPathiiiib+0x530> */
/* @0x19a95c ldr r3, [pc, #0xddc] */
/* @0x19a960 ldr r3, [r4, r3] */
/* @0x19a964 ldr r6, [r3] */
/* @0x19a968 str r3, [sp, #0x20] */
/* @0x19a96c cmp r6, #0 */
/* @0x19a970 beq 0x19ae34 <_Z16Motion_Grid_PathiP5CPathiiiib+0x53c> */
/* @0x19a974 ldr r2, [pc, #0xdc8] */
/* @0x19a978 ldr r3, [pc, #0xdc8] */
/* @0x19a97c ldr r12, [r4, r2] */
/* @0x19a980 ldr r7, [r4, r3] */
/* @0x19a984 ldr r2, [pc, #0xdc0] */
/* @0x19a988 mov r3, #0 */
/* @0x19a98c ldr r5, [r9, #0x4] */
/* @0x19a990 ldr r2, [r4, r2] */
/* @0x19a994 cmp r10, r5 */
/* @0x19a998 str r3, [r7] */
/* @0x19a99c str r3, [r12] */
/* @0x19a9a0 str r2, [sp, #0x14] */
/* @0x19a9a4 str r3, [r2] */
/* @0x19a9a8 blt 0x19ae28 <_Z16Motion_Grid_PathiP5CPathiiiib+0x530> */
/* @0x19a9ac ldr r6, [r9, #0xc] */
/* @0x19a9b0 ldr r3, [r9, #0x14] */
/* @0x19a9b4 mla r3, r3, r6, r5 */
/* @0x19a9b8 cmp r10, r3 */
/* @0x19a9bc bge 0x19ae28 <_Z16Motion_Grid_PathiP5CPathiiiib+0x530> */

/* ── 起点 y 闸 ──
 *   y1 >= hy(+8) 且 y1 < hy + cellH*rows（0x19a9e8 的 mla，rows=[r9+0x18]）
 *   四个中间量各存一份栈槽供后文复用：+0x10=hy、+0x28=cellH、+0x24=rows、+0x30=y 上界
 */
/* @0x19a9c0 ldr r2, [r9, #0x8] */
/* @0x19a9c4 cmp r8, r2 */
/* @0x19a9c8 str r2, [sp, #0x10] */
/* @0x19a9cc blt 0x19ae28 <_Z16Motion_Grid_PathiP5CPathiiiib+0x530> */
/* @0x19a9d0 ldr r2, [r9, #0x18] */
/* @0x19a9d4 ldr r1, [sp, #0x10] */
/* @0x19a9d8 str r2, [sp, #0x24] */
/* @0x19a9dc ldr r0, [sp, #0x24] */
/* @0x19a9e0 ldr r2, [r9, #0x10] */
/* @0x19a9e4 str r2, [sp, #0x28] */
/* @0x19a9e8 mla r2, r2, r0, r1 */
/* @0x19a9ec cmp r8, r2 */
/* @0x19a9f0 str r2, [sp, #0x30] */
/* @0x19a9f4 bge 0x19ae28 <_Z16Motion_Grid_PathiP5CPathiiiib+0x530> */

/* ── 起点 → 格子 + 障碍哨兵 ──
 *   cx1 = (x1-hx)/cellW（0x19aa08 __divsi3）、cy1 = (y1-hy)/cellH（0x19aa1c）
 *   起点格 = cx1*rows + cy1（0x19aa2c）→ [sp+0x2c]（后面打戳与入队都用它）
 *   cells[起点格] < 0 → 0（0x19aa48/0x19aa4c：只把「小于 0」当失败，见 open 第 1 条）
 */
/* @0x19a9f8 mov r1, r6 */
/* @0x19a9fc rsb r0, r5, r10 */
/* @0x19aa00 str r3, [sp, #0xc] */
/* @0x19aa04 str r12, [sp, #0x8] */
/* @0x19aa08 bl 0x318d10 <__divsi3> */
/* @0x19aa0c ldr r2, [sp, #0x10] */
/* @0x19aa10 ldr r1, [sp, #0x28] */
/* @0x19aa14 str r0, [sp, #0x38] */
/* @0x19aa18 rsb r0, r2, r8 */
/* @0x19aa1c bl 0x318d10 <__divsi3> */
/* @0x19aa20 ldr r1, [sp, #0x38] */
/* @0x19aa24 ldr r2, [sp, #0x24] */
/* @0x19aa28 ldr r3, [sp, #0xc] */
/* @0x19aa2c mla r2, r1, r2, r0 */
/* @0x19aa30 str r0, [sp, #0x3c] */
/* @0x19aa34 str r2, [sp, #0x2c] */
/* @0x19aa38 ldr r0, [sp, #0x2c] */
/* @0x19aa3c ldr r2, [r9, #0x1c] */
/* @0x19aa40 ldr r1, [r2, r0, lsl #2] */
/* @0x19aa44 str r2, [sp, #0x34] */
/* @0x19aa48 cmp r1, #0 */
/* @0x19aa4c blt 0x19ae28 <_Z16Motion_Grid_PathiP5CPathiiiib+0x530> */

/* ── 终点闸（与起点同构，实参取 [sp+0xa0]/[sp+0xa4]）──
 *   四道范围闸 → cx2=[sp+0x40]、cy2=[sp+0x44] → 终点格 → cells[终点格] < 0 → 0
 */
/* @0x19aa50 ldr r1, [sp, #0xa0] */
/* @0x19aa54 cmp r1, r5 */
/* @0x19aa58 blt 0x19ae28 <_Z16Motion_Grid_PathiP5CPathiiiib+0x530> */
/* @0x19aa5c cmp r1, r3 */
/* @0x19aa60 bge 0x19ae28 <_Z16Motion_Grid_PathiP5CPathiiiib+0x530> */
/* @0x19aa64 ldr r2, [sp, #0xa4] */
/* @0x19aa68 ldr r3, [sp, #0x10] */
/* @0x19aa6c cmp r2, r3 */
/* @0x19aa70 blt 0x19ae28 <_Z16Motion_Grid_PathiP5CPathiiiib+0x530> */
/* @0x19aa74 ldr r3, [sp, #0x30] */
/* @0x19aa78 cmp r2, r3 */
/* @0x19aa7c bge 0x19ae28 <_Z16Motion_Grid_PathiP5CPathiiiib+0x530> */
/* @0x19aa80 rsb r0, r5, r1 */
/* @0x19aa84 mov r1, r6 */
/* @0x19aa88 bl 0x318d10 <__divsi3> */
/* @0x19aa8c ldr r2, [sp, #0x10] */
/* @0x19aa90 ldr lr, [sp, #0xa4] */
/* @0x19aa94 ldr r1, [sp, #0x28] */
/* @0x19aa98 str r0, [sp, #0x40] */
/* @0x19aa9c rsb r0, r2, lr */
/* @0x19aaa0 bl 0x318d10 <__divsi3> */
/* @0x19aaa4 ldr r2, [sp, #0x24] */
/* @0x19aaa8 ldr r1, [sp, #0x40] */
/* @0x19aaac ldr r12, [sp, #0x8] */
/* @0x19aab0 mla r3, r1, r2, r0 */
/* @0x19aab4 ldr r2, [sp, #0x34] */
/* @0x19aab8 str r0, [sp, #0x44] */
/* @0x19aabc ldr r1, [r2, r3, lsl #2] */
/* @0x19aac0 cmp r1, #0 */
/* @0x19aac4 blt 0x19ae28 <_Z16Motion_Grid_PathiP5CPathiiiib+0x530> */

/* ── 起点打戳 + 首次入队 ──
 *   cells[起点格] = 1（0x19aad4）——BFS 的距离原点；后面每层 +1
 *   环形队列：base=[GOT 0x3F06CC 对象]、head=[GOT 0x3F06C4 对象]、cap=[GOT 0x3F06C8 对象]
 *   新 head = (head+1) & (cap-1)（0x19aae4..0x19aaec），与 tail 相等 ⇒ 队满 ⇒ 0x19bec4 扩容
 *   0x19ab08 判定命中时不写队；否则 0x19ab34 把起点格号写进 queue[head]
 */
/* @0x19aac8 ldr r3, [sp, #0x2c] */
/* @0x19aacc mov r1, #1 */
/* @0x19aad0 ldr r0, [sp, #0x20] */
/* @0x19aad4 str r1, [r2, r3, lsl #2] */
/* @0x19aad8 ldr r6, [r0] */
/* @0x19aadc ldr r3, [r12] */
/* @0x19aae0 ldr r0, [r7] */
/* @0x19aae4 add r2, r3, r1 */
/* @0x19aae8 sub r1, r6, #1 */
/* @0x19aaec and r2, r1, r2 */
/* @0x19aaf0 ldr r5, [r9, #0x18] */
/* @0x19aaf4 cmp r2, r0 */
/* @0x19aaf8 ldr r1, [sp, #0x38] */
/* @0x19aafc ldr r2, [sp, #0x3c] */
/* @0x19ab00 mla r5, r5, r1, r2 */
/* @0x19ab04 str r5, [sp, #0x24] */
/* @0x19ab08 beq 0x19bec4 <_Z16Motion_Grid_PathiP5CPathiiiib+0x15cc> */

/* ── 队列对象与实参搬进栈槽（给主循环腾寄存器）──
 *   [sp+0x5c]/[sp+0x60]/[sp+0x64]/[sp+0x68] = 四个 pc 相对字符串地址
 *     （池字 0x001b2234 / 0x001b2218 / 0x001b21d4 / 0x001b21cc），只作 Alloc 的 __FILE__ 实参（内容未取证）
 *   [sp+0x6c]=path、[sp+0x70]=x1、[sp+0x74]=y1；[sp+0x14]=元素计数对象、[sp+0x20]=队列计数对象地址；
 *   r10 改成 head 对象、r12 = tail 对象、r5 = 队列 base
 */
/* @0x19ab0c ldr r2, [pc, #0xc64] */
/* @0x19ab10 ldr r5, [r4, r2] */
/* @0x19ab14 ldr r1, [pc, #0xc34] */
/* @0x19ab18 ldr r2, [r5] */
/* @0x19ab1c add r1, pc, r1 */
/* @0x19ab20 str r1, [sp, #0x5c] */
/* @0x19ab24 ldr r1, [sp, #0x24] */
/* @0x19ab28 ldr r0, [pc, #0xc24] */
/* @0x19ab2c str r10, [sp, #0x70] */
/* @0x19ab30 mov r10, r12 */
/* @0x19ab34 str r1, [r2, r3, lsl #2] */
/* @0x19ab38 add r0, pc, r0 */
/* @0x19ab3c ldr r2, [sp, #0x14] */
/* @0x19ab40 ldr r3, [sp, #0x20] */
/* @0x19ab44 str r0, [sp, #0x60] */
/* @0x19ab48 ldr r0, [r2] */
/* @0x19ab4c ldr r2, [r3] */
/* @0x19ab50 ldr r3, [r12] */
/* @0x19ab54 add r0, r0, #1 */
/* @0x19ab58 sub r2, r2, #1 */
/* @0x19ab5c ldr r1, [sp, #0x14] */
/* @0x19ab60 add r3, r3, #1 */
/* @0x19ab64 str r11, [sp, #0x6c] */
/* @0x19ab68 and r3, r2, r3 */
/* @0x19ab6c str r3, [r12] */
/* @0x19ab70 ldr r12, [sp, #0x20] */
/* @0x19ab74 ldr r2, [pc, #0xbdc] */
/* @0x19ab78 ldr r3, [pc, #0xbdc] */
/* @0x19ab7c add r2, pc, r2 */
/* @0x19ab80 str r0, [r1] */
/* @0x19ab84 add r3, pc, r3 */
/* @0x19ab88 str r2, [sp, #0x64] */
/* @0x19ab8c str r3, [sp, #0x68] */
/* @0x19ab90 str r8, [sp, #0x74] */

/* ── 出队 + 格号还原 + 命中终点 ──
 *   r0 = 当前元素数；为 0 → 0x19adcc（队列空 = 搜索失败，但仍走格子复位再返回 0）
 *   cell = queue[head]；head=(head+1)&(cap-1) 写回；元素数 -1（0x19abd4）
 *   cx = cell / rows（0x19abe0）、cy = cell % rows（0x19abf0 __aeabi_idivmod 取余）——与入队时的 mla 互逆
 *   0x19ac04/0x19ac08：cx == cx2 且 cy == cy2 ⇒ [sp+0x34]=1 且 b 0x19b77c（路径写出）
 */
/* @0x19ab94 cmp r0, #0 */
/* @0x19ab98 beq 0x19adcc <_Z16Motion_Grid_PathiP5CPathiiiib+0x4d4> */
/* @0x19ab9c ldr r8, [r5] */
/* @0x19aba0 sub r2, r0, #1 */
/* @0x19aba4 ldr r3, [r7] */
/* @0x19aba8 ldr r0, [r12] */
/* @0x19abac str r8, [sp, #0x2c] */
/* @0x19abb0 add r1, r3, #1 */
/* @0x19abb4 ldr lr, [sp, #0x2c] */
/* @0x19abb8 sub r0, r0, #1 */
/* @0x19abbc ldr r8, [r9, #0x18] */
/* @0x19abc0 and r1, r0, r1 */
/* @0x19abc4 ldr r0, [sp, #0x14] */
/* @0x19abc8 ldr r11, [lr, r3, lsl #2] */
/* @0x19abcc str r1, [r7] */
/* @0x19abd0 mov r1, r8 */
/* @0x19abd4 str r2, [r0] */
/* @0x19abd8 mov r0, r11 */
/* @0x19abdc str r12, [sp, #0x8] */
/* @0x19abe0 bl 0x318d10 <__divsi3> */
/* @0x19abe4 mov r1, r8 */
/* @0x19abe8 mov r4, r0 */
/* @0x19abec mov r0, r11 */
/* @0x19abf0 bl 0x318dec <__aeabi_idivmod> */
/* @0x19abf4 ldr r2, [sp, #0x44] */
/* @0x19abf8 ldr r12, [sp, #0x8] */
/* @0x19abfc mov r6, r1 */
/* @0x19ac00 ldr r1, [sp, #0x40] */
/* @0x19ac04 cmp r1, r4 */
/* @0x19ac08 cmpeq r2, r6 */
/* @0x19ac0c movne r1, #0 */
/* @0x19ac10 moveq r1, #1 */
/* @0x19ac14 str r1, [sp, #0x34] */
/* @0x19ac18 beq 0x19b77c <_Z16Motion_Grid_PathiP5CPathiiiib+0xe84> */

/* ── 下一层戳 ──
 *   cells[cell] + 1 → [sp+0x30]：本轮 8 个邻居要写的值（每弹一格重算 ⇒ 戳 = 离起点的步数 + 1）
 */
/* @0x19ac1c ldr r3, [r9, #0x1c] */
/* @0x19ac20 cmp r4, #0 */
/* @0x19ac24 sub r1, r8, #1 */
/* @0x19ac28 ldr r2, [r3, r11, lsl #2] */
/* @0x19ac2c add r2, r2, #1 */
/* @0x19ac30 str r2, [sp, #0x30] */
/* @0x19ac34 ble 0x19afe4 <_Z16Motion_Grid_PathiP5CPathiiiib+0x6ec> */
/* @0x19ac38 cmp r6, r1 */
/* @0x19ac3c blt 0x19af5c <_Z16Motion_Grid_PathiP5CPathiiiib+0x664> */

/* ── 8 邻域闸门（先算四个正邻与四个角，再统一派发）──
 *   闸门口：v = cells[邻居]；r = 1 - v；r 小于 0 归 0（0x19ac70 的 rsbs + movlo）
 *   ⇒ 通过条件等价于 v <= 0：未访问(0) 放行，戳 1（起点）与戳 >=2（已访问）都挡住（见 open 第 1 条）
 *   正邻：左 (cx-1,cy)→[sp+0x24]、右 (cx+1,cy)→[sp+0x28]、上 (cx,cy-1)→[sp+0x20]、下 (cx,cy+1)→[sp+0x50]
 *         （越界项先置 0：0x19ac74/0x19ac9c/0x19acb8/0x19af40 几处）
 *   对角：0x19acbc..0x19ad24 先查对角格与两个相邻正格（防切角），allowDiag（[sp+0x1c]）在 0x19acd4 参与取值
 */
/* @0x19ac40 ldr r2, [r9, #0x14] */
/* @0x19ac44 mov r11, #0 */
/* @0x19ac48 str r11, [sp, #0x50] */
/* @0x19ac4c sub r2, r2, #1 */
/* @0x19ac50 str r11, [sp, #0x20] */
/* @0x19ac54 mov r11, #0 */
/* @0x19ac58 str r11, [sp, #0x48] */
/* @0x19ac5c cmp r4, #0 */
/* @0x19ac60 ble 0x19b1cc <_Z16Motion_Grid_PathiP5CPathiiiib+0x8d4> */
/* @0x19ac64 sub r1, r4, #1 */
/* @0x19ac68 mla r1, r1, r8, r6 */
/* @0x19ac6c ldr r1, [r3, r1, lsl #2] */
/* @0x19ac70 rsbs r1, r1, #1 */
/* @0x19ac74 movlo r1, #0 */
/* @0x19ac78 str r1, [sp, #0x24] */
/* @0x19ac7c cmp r4, r2 */
/* @0x19ac80 movge r11, #0 */
/* @0x19ac84 strge r11, [sp, #0x28] */
/* @0x19ac88 bge 0x19aca4 <_Z16Motion_Grid_PathiP5CPathiiiib+0x3ac> */
/* @0x19ac8c mla r1, r4, r8, r8 */
/* @0x19ac90 add r1, r6, r1 */
/* @0x19ac94 ldr r1, [r3, r1, lsl #2] */
/* @0x19ac98 rsbs r1, r1, #1 */
/* @0x19ac9c movlo r1, #0 */
/* @0x19aca0 str r1, [sp, #0x28] */
/* @0x19aca4 cmp r6, #0 */
/* @0x19aca8 movle r1, #0 */
/* @0x19acac movgt r1, #1 */
/* @0x19acb0 cmp r4, #0 */
/* @0x19acb4 cmpgt r6, #0 */
/* @0x19acb8 ble 0x19af40 <_Z16Motion_Grid_PathiP5CPathiiiib+0x648> */
/* @0x19acbc sub r0, r6, #1 */
/* @0x19acc0 sub r11, r4, #1 */
/* @0x19acc4 mla r11, r11, r8, r0 */
/* @0x19acc8 ldr r11, [r3, r11, lsl #2] */
/* @0x19accc cmp r11, #0 */
/* @0x19acd0 bne 0x19af50 <_Z16Motion_Grid_PathiP5CPathiiiib+0x658> */
/* @0x19acd4 ldr r11, [sp, #0x1c] */
/* @0x19acd8 str r11, [sp, #0x4c] */
/* @0x19acdc mla r0, r4, r8, r0 */
/* @0x19ace0 ldr r0, [r3, r0, lsl #2] */
/* @0x19ace4 cmp r0, #0 */
/* @0x19ace8 moveq r11, #1 */
/* @0x19acec beq 0x19acf4 <_Z16Motion_Grid_PathiP5CPathiiiib+0x3fc> */
/* @0x19acf0 mov r11, #0 */
/* @0x19acf4 cmp r4, r2 */
/* @0x19acf8 bge 0x19ad28 <_Z16Motion_Grid_PathiP5CPathiiiib+0x430> */
/* @0x19acfc cmp r1, #0 */
/* @0x19ad00 streq r1, [sp, #0x34] */
/* @0x19ad04 beq 0x19ad28 <_Z16Motion_Grid_PathiP5CPathiiiib+0x430> */
/* @0x19ad08 mla r2, r4, r8, r8 */
/* @0x19ad0c ldr r0, [sp, #0x1c] */
/* @0x19ad10 add r2, r6, r2 */
/* @0x19ad14 sub r2, r2, #1 */
/* @0x19ad18 ldr r2, [r3, r2, lsl #2] */
/* @0x19ad1c cmp r2, #0 */
/* @0x19ad20 movne r0, #0 */
/* @0x19ad24 str r0, [sp, #0x34] */

/* ── 八方向派发（顺序固定：先正后斜，斜向要额外过角闸）──
 *   [sp+0x24] → 0x19affc（左）              [sp+0x28] → 0x19b158（右）
 *   r11（对角标志）→ 0x19b068               [sp+0x20] → 0x19b0e0（上）
 *   [sp+0x50]&[sp+0x24]&[sp+0x20] → 0x19b2e0（左上）
 *   [sp+0x4c]&[sp+0x24]&r11 → 0x19b36c（左下）
 *   [sp+0x48]&[sp+0x28]&[sp+0x20] → 0x19b1d8（右上）
 *   [sp+0x34]&[sp+0x28]&r11 → 0x19b264（右下）
 *   每个 push 体都做同样四件事：算邻居索引 → cells[邻居]=戳 → 队满则跳 out-of-line 扩容 → 压队并 ++计数
 */
/* @0x19ad28 ldr r1, [sp, #0x24] */
/* @0x19ad2c cmp r1, #0 */
/* @0x19ad30 bne 0x19affc <_Z16Motion_Grid_PathiP5CPathiiiib+0x704> */
/* @0x19ad34 ldr r8, [sp, #0x28] */
/* @0x19ad38 cmp r8, #0 */
/* @0x19ad3c bne 0x19b158 <_Z16Motion_Grid_PathiP5CPathiiiib+0x860> */
/* @0x19ad40 cmp r11, #0 */
/* @0x19ad44 bne 0x19b068 <_Z16Motion_Grid_PathiP5CPathiiiib+0x770> */
/* @0x19ad48 ldr r8, [sp, #0x20] */
/* @0x19ad4c cmp r8, #0 */
/* @0x19ad50 bne 0x19b0e0 <_Z16Motion_Grid_PathiP5CPathiiiib+0x7e8> */
/* @0x19ad54 ldr r8, [sp, #0x50] */
/* @0x19ad58 cmp r8, #0 */
/* @0x19ad5c beq 0x19ad70 <_Z16Motion_Grid_PathiP5CPathiiiib+0x478> */
/* @0x19ad60 ldr r8, [sp, #0x24] */
/* @0x19ad64 ldr r0, [sp, #0x20] */
/* @0x19ad68 tst r8, r0 */
/* @0x19ad6c bne 0x19b2e0 <_Z16Motion_Grid_PathiP5CPathiiiib+0x9e8> */
/* @0x19ad70 ldr r8, [sp, #0x4c] */
/* @0x19ad74 cmp r8, #0 */
/* @0x19ad78 beq 0x19ad88 <_Z16Motion_Grid_PathiP5CPathiiiib+0x490> */
/* @0x19ad7c ldr r8, [sp, #0x24] */
/* @0x19ad80 tst r8, r11 */
/* @0x19ad84 bne 0x19b36c <_Z16Motion_Grid_PathiP5CPathiiiib+0xa74> */
/* @0x19ad88 ldr r8, [sp, #0x48] */
/* @0x19ad8c cmp r8, #0 */
/* @0x19ad90 beq 0x19ada4 <_Z16Motion_Grid_PathiP5CPathiiiib+0x4ac> */
/* @0x19ad94 ldr r8, [sp, #0x28] */
/* @0x19ad98 ldr r0, [sp, #0x20] */
/* @0x19ad9c tst r8, r0 */
/* @0x19ada0 bne 0x19b1d8 <_Z16Motion_Grid_PathiP5CPathiiiib+0x8e0> */
/* @0x19ada4 ldr r8, [sp, #0x34] */
/* @0x19ada8 cmp r8, #0 */
/* @0x19adac beq 0x19adbc <_Z16Motion_Grid_PathiP5CPathiiiib+0x4c4> */
/* @0x19adb0 ldr r8, [sp, #0x28] */
/* @0x19adb4 tst r8, r11 */
/* @0x19adb8 bne 0x19b264 <_Z16Motion_Grid_PathiP5CPathiiiib+0x96c> */
/* @0x19adbc ldr r11, [sp, #0x14] */
/* @0x19adc0 ldr r0, [r11] */
/* @0x19adc4 cmp r0, #0 */
/* @0x19adc8 bne 0x19ab9c <_Z16Motion_Grid_PathiP5CPathiiiib+0x2a4> */

/* ── 唯一的出口序列：把这一轮打上去的戳全部擦掉 ──
 *   外层 col 0..cols-1、内层 row 0..rows-1：cells[col*rows+row] > 0 ⇒ 写 0（0x19ae04 的 strgt）
 *   ⇒ 网格数组被当「可重入的临时距离场」：>0 是本次搜索的戳，<=0 的既有值原样留着
 *   0x19adcc 是成功（0x19bb30 b 过来）与「队列耗尽」共用的入口；早退（0x19ae28）跳过复位，因为那时还没打戳
 *   0x19ae28 mov r0,#0 + 0x19ae2c add sp/pop = 返回 0；0x19ae2c 同时是 0x19a94c「grids[id]==0」的落点
 */
/* @0x19adcc ldr r3, [r9, #0x14] */
/* @0x19add0 cmp r3, #0 */
/* @0x19add4 ble 0x19ae2c <_Z16Motion_Grid_PathiP5CPathiiiib+0x534> */
/* @0x19add8 ldr r2, [r9, #0x18] */
/* @0x19addc mov r5, #0 */
/* @0x19ade0 mov r6, r5 */
/* @0x19ade4 cmp r2, #0 */
/* @0x19ade8 ble 0x19ae18 <_Z16Motion_Grid_PathiP5CPathiiiib+0x520> */
/* @0x19adec ldr r4, [r9, #0x1c] */
/* @0x19adf0 mov r3, #0 */
/* @0x19adf4 mla r1, r2, r5, r3 */
/* @0x19adf8 add r3, r3, #1 */
/* @0x19adfc ldr r12, [r4, r1, lsl #2] */
/* @0x19ae00 cmp r12, #0 */
/* @0x19ae04 strgt r6, [r4, r1, lsl #2] */
/* @0x19ae08 ldrgt r2, [r9, #0x18] */
/* @0x19ae0c cmp r2, r3 */
/* @0x19ae10 bgt 0x19adf4 <_Z16Motion_Grid_PathiP5CPathiiiib+0x4fc> */
/* @0x19ae14 ldr r3, [r9, #0x14] */
/* @0x19ae18 add r5, r5, #1 */
/* @0x19ae1c cmp r5, r3 */
/* @0x19ae20 blt 0x19ade4 <_Z16Motion_Grid_PathiP5CPathiiiib+0x4ec> */
/* @0x19ae24 b 0x19ae2c <_Z16Motion_Grid_PathiP5CPathiiiib+0x534> */
/* @0x19ae28 mov r0, #0 */
/* @0x19ae2c add sp, sp, #124 */
/* @0x19ae30 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── 环形队列扩容（队满时跳进来；这里是最短的一份）──
 *   Alloc(新容量*4, __FILE__(池字 0x001b1f0c 加 pc), 212, true)：212 是源码行号
 *   两段 memcpy：先搬 [head,cap)，再从 0 搬 head 个元素 —— 与「head 处断开」的环形布局一一对应
 *   Free(旧 base)；head=0、元素数=cnt+cnt2、base 换新、容量换新（0x19aec4..0x19aed8）→ b 0x19a984 回主循环
 */
/* @0x19ae34 ldr r1, [pc, #0x924] */
/* @0x19ae38 mov r2, #212 */
/* @0x19ae3c mov r3, #1 */
/* @0x19ae40 mov r0, r6 */
/* @0x19ae44 add r1, pc, r1 */
/* @0x19ae48 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x19ae4c ldr r3, [sp, #0x20] */
/* @0x19ae50 ldr r1, [pc, #0x8ec] */
/* @0x19ae54 ldr r2, [r3] */
/* @0x19ae58 cmp r2, #0 */
/* @0x19ae5c str r0, [sp, #0x14] */
/* @0x19ae60 ble 0x19af28 <_Z16Motion_Grid_PathiP5CPathiiiib+0x630> */
/* @0x19ae64 ldr r3, [pc, #0x8dc] */
/* @0x19ae68 ldr r12, [r4, r1] */
/* @0x19ae6c ldr r7, [r4, r3] */
/* @0x19ae70 ldr r1, [r12] */
/* @0x19ae74 ldr r3, [r7] */
/* @0x19ae78 cmp r1, r3 */
/* @0x19ae7c bgt 0x19aedc <_Z16Motion_Grid_PathiP5CPathiiiib+0x5e4> */
/* @0x19ae80 ldr r1, [pc, #0x8f0] */
/* @0x19ae84 rsb r2, r3, r2 */
/* @0x19ae88 lsl r6, r2, #2 */
/* @0x19ae8c ldr r5, [r4, r1] */
/* @0x19ae90 mov r2, r6 */
/* @0x19ae94 ldr r1, [r5] */
/* @0x19ae98 str r12, [sp, #0x8] */
/* @0x19ae9c add r1, r1, r3, lsl #2 */
/* @0x19aea0 bl 0xb65bc <memcpy@plt> */
/* @0x19aea4 ldr r12, [sp, #0x8] */
/* @0x19aea8 ldr r3, [sp, #0x14] */
/* @0x19aeac ldr r1, [r5] */
/* @0x19aeb0 ldr r2, [r12] */
/* @0x19aeb4 add r0, r3, r6 */
/* @0x19aeb8 lsl r2, r2, #2 */
/* @0x19aebc bl 0xb65bc <memcpy@plt> */
/* @0x19aec0 ldr r12, [sp, #0x8] */
/* @0x19aec4 ldr r3, [sp, #0x14] */
/* @0x19aec8 ldr r0, [sp, #0x20] */
/* @0x19aecc str r3, [r5] */
/* @0x19aed0 mov r3, #0 */
/* @0x19aed4 str r3, [r0] */
/* @0x19aed8 b 0x19a984 <_Z16Motion_Grid_PathiP5CPathiiiib+0x8c> */
/* @0x19aedc ldr lr, [pc, #0x894] */
/* @0x19aee0 rsb r2, r3, r1 */
/* @0x19aee4 lsl r2, r2, #2 */
/* @0x19aee8 ldr r5, [r4, lr] */
/* @0x19aeec ldr r1, [r5] */
/* @0x19aef0 str r12, [sp, #0x8] */
/* @0x19aef4 add r1, r1, r3, lsl #2 */
/* @0x19aef8 bl 0xb65bc <memcpy@plt> */
/* @0x19aefc ldr r12, [sp, #0x8] */
/* @0x19af00 ldr r3, [r7] */
/* @0x19af04 ldr r0, [r5] */
/* @0x19af08 ldr r2, [r12] */
/* @0x19af0c str r6, [r7] */
/* @0x19af10 rsb r3, r3, r2 */
/* @0x19af14 str r3, [r12] */
/* @0x19af18 str r12, [sp, #0x8] */
/* @0x19af1c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19af20 ldr r12, [sp, #0x8] */
/* @0x19af24 b 0x19aec4 <_Z16Motion_Grid_PathiP5CPathiiiib+0x5cc> */
/* @0x19af28 ldr r2, [pc, #0x818] */
/* @0x19af2c ldr r3, [pc, #0x844] */
/* @0x19af30 ldr r12, [r4, r1] */
/* @0x19af34 ldr r7, [r4, r2] */
/* @0x19af38 ldr r5, [r4, r3] */
/* @0x19af3c b 0x19aec4 <_Z16Motion_Grid_PathiP5CPathiiiib+0x5cc> */

/* ── 角闸尾巴 + 八方向 push 体（每条都内联展开，互不共享）──
 *   已核对的同构点（以左边的 0x19affc 段为例）：
 *     sub r2,r4,#1 → mla r8,r2,r8,r6（index=(cx-1)*rows+cy）→ str 戳
 *     → 队满判 (head+1)&(cap-1)==tail → str 邻居格号 queue[head] → head 写回 → 元素数 +1
 *   右/上/下与四个斜向代码形状相同，只差 mla 的 (dcx,dcy) 与各自的队满落点；
 *   本块不逐条给每个展开体起名，只保证锚点全覆盖（未钉项见 open 第 4 条）
 */
/* @0x19af40 cmp r1, #0 */
/* @0x19af44 streq r1, [sp, #0x4c] */
/* @0x19af48 beq 0x19acf0 <_Z16Motion_Grid_PathiP5CPathiiiib+0x3f8> */
/* @0x19af4c sub r0, r6, #1 */
/* @0x19af50 mov r11, #0 */
/* @0x19af54 str r11, [sp, #0x4c] */
/* @0x19af58 b 0x19acdc <_Z16Motion_Grid_PathiP5CPathiiiib+0x3e4> */
/* @0x19af5c add r2, r6, #1 */
/* @0x19af60 sub r0, r4, #1 */
/* @0x19af64 mla r0, r0, r8, r2 */
/* @0x19af68 ldr r0, [r3, r0, lsl #2] */
/* @0x19af6c cmp r0, #0 */
/* @0x19af70 bne 0x19aff0 <_Z16Motion_Grid_PathiP5CPathiiiib+0x6f8> */
/* @0x19af74 ldr r11, [sp, #0x1c] */
/* @0x19af78 str r11, [sp, #0x50] */
/* @0x19af7c mla r2, r4, r8, r2 */
/* @0x19af80 ldr r2, [r3, r2, lsl #2] */
/* @0x19af84 cmp r2, #0 */
/* @0x19af88 ldr r2, [r9, #0x14] */
/* @0x19af8c sub r2, r2, #1 */
/* @0x19af90 bne 0x19afc8 <_Z16Motion_Grid_PathiP5CPathiiiib+0x6d0> */
/* @0x19af94 cmp r4, r2 */
/* @0x19af98 mov r11, #1 */
/* @0x19af9c str r11, [sp, #0x20] */
/* @0x19afa0 bge 0x19ac54 <_Z16Motion_Grid_PathiP5CPathiiiib+0x35c> */
/* @0x19afa4 mla r1, r4, r8, r8 */
/* @0x19afa8 add r1, r6, r1 */
/* @0x19afac add r1, r1, #1 */
/* @0x19afb0 ldr r1, [r3, r1, lsl #2] */
/* @0x19afb4 cmp r1, #0 */
/* @0x19afb8 bne 0x19ac54 <_Z16Motion_Grid_PathiP5CPathiiiib+0x35c> */
/* @0x19afbc ldr r11, [sp, #0x1c] */
/* @0x19afc0 str r11, [sp, #0x48] */
/* @0x19afc4 b 0x19ac5c <_Z16Motion_Grid_PathiP5CPathiiiib+0x364> */
/* @0x19afc8 cmp r4, r2 */
/* @0x19afcc mov r11, #0 */
/* @0x19afd0 str r11, [sp, #0x20] */
/* @0x19afd4 bge 0x19ac54 <_Z16Motion_Grid_PathiP5CPathiiiib+0x35c> */
/* @0x19afd8 cmp r6, r1 */
/* @0x19afdc bge 0x19ac54 <_Z16Motion_Grid_PathiP5CPathiiiib+0x35c> */
/* @0x19afe0 b 0x19afa4 <_Z16Motion_Grid_PathiP5CPathiiiib+0x6ac> */
/* @0x19afe4 cmp r6, r1 */
/* @0x19afe8 addlt r2, r6, #1 */
/* @0x19afec bge 0x19ac40 <_Z16Motion_Grid_PathiP5CPathiiiib+0x348> */
/* @0x19aff0 mov r11, #0 */
/* @0x19aff4 str r11, [sp, #0x50] */
/* @0x19aff8 b 0x19af7c <_Z16Motion_Grid_PathiP5CPathiiiib+0x684> */
/* @0x19affc sub r2, r4, #1 */
/* @0x19b000 ldr r0, [sp, #0x30] */
/* @0x19b004 mla r8, r2, r8, r6 */
/* @0x19b008 str r0, [r3, r8, lsl #2] */
/* @0x19b00c ldr r3, [r10] */
/* @0x19b010 ldr r1, [r12] */
/* @0x19b014 add r0, r3, #1 */
/* @0x19b018 sub r8, r1, #1 */
/* @0x19b01c and r0, r8, r0 */
/* @0x19b020 ldr r8, [r7] */
/* @0x19b024 cmp r0, r8 */
/* @0x19b028 ldr r0, [r9, #0x18] */
/* @0x19b02c mla r8, r0, r2, r6 */
/* @0x19b030 ldrne r2, [sp, #0x2c] */
/* @0x19b034 beq 0x19b4c4 <_Z16Motion_Grid_PathiP5CPathiiiib+0xbcc> */
/* @0x19b038 str r8, [r2, r3, lsl #2] */
/* @0x19b03c ldr r8, [sp, #0x14] */
/* @0x19b040 ldr r2, [r10] */
/* @0x19b044 ldr r1, [r12] */
/* @0x19b048 ldr r3, [r8] */
/* @0x19b04c add r2, r2, #1 */
/* @0x19b050 sub r1, r1, #1 */
/* @0x19b054 and r2, r1, r2 */
/* @0x19b058 add r3, r3, #1 */
/* @0x19b05c str r2, [r10] */
/* @0x19b060 str r3, [r8] */
/* @0x19b064 b 0x19ad34 <_Z16Motion_Grid_PathiP5CPathiiiib+0x43c> */
/* @0x19b068 ldr r2, [r9, #0x18] */
/* @0x19b06c ldr r3, [r9, #0x1c] */
/* @0x19b070 ldr r8, [sp, #0x30] */
/* @0x19b074 mla r2, r2, r4, r6 */
/* @0x19b078 sub r2, r2, #-1073741823 */
/* @0x19b07c str r8, [r3, r2, lsl #2] */
/* @0x19b080 ldr r8, [r9, #0x18] */
/* @0x19b084 ldr r3, [r10] */
/* @0x19b088 ldr r2, [r12] */
/* @0x19b08c add r1, r3, #1 */
/* @0x19b090 sub r0, r2, #1 */
/* @0x19b094 and r1, r0, r1 */
/* @0x19b098 ldr r0, [r7] */
/* @0x19b09c mla r8, r8, r4, r6 */
/* @0x19b0a0 cmp r1, r0 */
/* @0x19b0a4 sub r8, r8, #1 */
/* @0x19b0a8 beq 0x19b664 <_Z16Motion_Grid_PathiP5CPathiiiib+0xd6c> */
/* @0x19b0ac ldr r2, [r5] */
/* @0x19b0b0 str r8, [r2, r3, lsl #2] */
/* @0x19b0b4 ldr r8, [sp, #0x14] */
/* @0x19b0b8 ldr r2, [r10] */
/* @0x19b0bc ldr r1, [r12] */
/* @0x19b0c0 ldr r3, [r8] */
/* @0x19b0c4 add r2, r2, #1 */
/* @0x19b0c8 sub r1, r1, #1 */
/* @0x19b0cc and r2, r1, r2 */
/* @0x19b0d0 add r3, r3, #1 */
/* @0x19b0d4 str r2, [r10] */
/* @0x19b0d8 str r3, [r8] */
/* @0x19b0dc b 0x19ad48 <_Z16Motion_Grid_PathiP5CPathiiiib+0x450> */
/* @0x19b0e0 ldr r2, [r9, #0x18] */
/* @0x19b0e4 ldr r3, [r9, #0x1c] */
/* @0x19b0e8 ldr r8, [sp, #0x30] */
/* @0x19b0ec mla r2, r2, r4, r6 */
/* @0x19b0f0 add r2, r2, #1 */
/* @0x19b0f4 str r8, [r3, r2, lsl #2] */
/* @0x19b0f8 ldr r8, [r9, #0x18] */
/* @0x19b0fc ldr r3, [r10] */
/* @0x19b100 ldr r2, [r12] */
/* @0x19b104 add r1, r3, #1 */
/* @0x19b108 sub r0, r2, #1 */
/* @0x19b10c and r1, r0, r1 */
/* @0x19b110 ldr r0, [r7] */
/* @0x19b114 mla r8, r8, r4, r6 */
/* @0x19b118 cmp r1, r0 */
/* @0x19b11c add r8, r8, #1 */
/* @0x19b120 beq 0x19b594 <_Z16Motion_Grid_PathiP5CPathiiiib+0xc9c> */
/* @0x19b124 ldr r2, [r5] */
/* @0x19b128 str r8, [r2, r3, lsl #2] */
/* @0x19b12c ldr r8, [sp, #0x14] */
/* @0x19b130 ldr r2, [r10] */
/* @0x19b134 ldr r1, [r12] */
/* @0x19b138 ldr r3, [r8] */
/* @0x19b13c add r2, r2, #1 */
/* @0x19b140 sub r1, r1, #1 */
/* @0x19b144 and r2, r1, r2 */
/* @0x19b148 add r3, r3, #1 */
/* @0x19b14c str r2, [r10] */
/* @0x19b150 str r3, [r8] */
/* @0x19b154 b 0x19ad54 <_Z16Motion_Grid_PathiP5CPathiiiib+0x45c> */
/* @0x19b158 ldr r2, [r9, #0x18] */
/* @0x19b15c add r8, r4, #1 */
/* @0x19b160 ldr r3, [r9, #0x1c] */
/* @0x19b164 ldr r0, [sp, #0x30] */
/* @0x19b168 mla r2, r2, r8, r6 */
/* @0x19b16c str r0, [r3, r2, lsl #2] */
/* @0x19b170 ldr r3, [r10] */
/* @0x19b174 ldr r2, [r12] */
/* @0x19b178 add r1, r3, #1 */
/* @0x19b17c sub r0, r2, #1 */
/* @0x19b180 and r1, r0, r1 */
/* @0x19b184 ldr r0, [r7] */
/* @0x19b188 cmp r1, r0 */
/* @0x19b18c ldr r1, [r9, #0x18] */
/* @0x19b190 mla r8, r1, r8, r6 */
/* @0x19b194 beq 0x19b3f8 <_Z16Motion_Grid_PathiP5CPathiiiib+0xb00> */
/* @0x19b198 ldr r2, [r5] */
/* @0x19b19c str r8, [r2, r3, lsl #2] */
/* @0x19b1a0 ldr r8, [sp, #0x14] */
/* @0x19b1a4 ldr r2, [r10] */
/* @0x19b1a8 ldr r1, [r12] */
/* @0x19b1ac ldr r3, [r8] */
/* @0x19b1b0 add r2, r2, #1 */
/* @0x19b1b4 sub r1, r1, #1 */
/* @0x19b1b8 and r2, r1, r2 */
/* @0x19b1bc add r3, r3, #1 */
/* @0x19b1c0 str r2, [r10] */
/* @0x19b1c4 str r3, [r8] */
/* @0x19b1c8 b 0x19ad40 <_Z16Motion_Grid_PathiP5CPathiiiib+0x448> */
/* @0x19b1cc mov r11, #0 */
/* @0x19b1d0 str r11, [sp, #0x24] */
/* @0x19b1d4 b 0x19ac7c <_Z16Motion_Grid_PathiP5CPathiiiib+0x384> */
/* @0x19b1d8 ldr r2, [r9, #0x18] */
/* @0x19b1dc add r1, r4, #1 */
/* @0x19b1e0 ldr r3, [r9, #0x1c] */
/* @0x19b1e4 ldr r8, [sp, #0x30] */
/* @0x19b1e8 mla r2, r2, r1, r6 */
/* @0x19b1ec add r2, r2, #1 */
/* @0x19b1f0 str r8, [r3, r2, lsl #2] */
/* @0x19b1f4 ldr r0, [r9, #0x18] */
/* @0x19b1f8 ldr r3, [r10] */
/* @0x19b1fc ldr r2, [r12] */
/* @0x19b200 mla r0, r0, r1, r6 */
/* @0x19b204 sub r8, r2, #1 */
/* @0x19b208 ldr r1, [r7] */
/* @0x19b20c str r0, [sp, #0x10] */
/* @0x19b210 add r0, r3, #1 */
/* @0x19b214 and r0, r8, r0 */
/* @0x19b218 ldr r8, [sp, #0x10] */
/* @0x19b21c cmp r0, r1 */
/* @0x19b220 add r8, r8, #1 */
/* @0x19b224 str r8, [sp, #0x20] */
/* @0x19b228 beq 0x19bd54 <_Z16Motion_Grid_PathiP5CPathiiiib+0x145c> */
/* @0x19b22c ldr r2, [r5] */
/* @0x19b230 ldr r8, [sp, #0x20] */
/* @0x19b234 str r8, [r2, r3, lsl #2] */
/* @0x19b238 ldr r8, [sp, #0x14] */
/* @0x19b23c ldr r2, [r10] */
/* @0x19b240 ldr r1, [r12] */
/* @0x19b244 ldr r3, [r8] */
/* @0x19b248 add r2, r2, #1 */
/* @0x19b24c sub r1, r1, #1 */
/* @0x19b250 and r2, r1, r2 */
/* @0x19b254 add r3, r3, #1 */
/* @0x19b258 str r2, [r10] */
/* @0x19b25c str r3, [r8] */
/* @0x19b260 b 0x19ada4 <_Z16Motion_Grid_PathiP5CPathiiiib+0x4ac> */
/* @0x19b264 ldr r2, [r9, #0x18] */
/* @0x19b268 add r4, r4, #1 */
/* @0x19b26c ldr r3, [r9, #0x1c] */
/* @0x19b270 ldr r11, [sp, #0x30] */
/* @0x19b274 mla r2, r2, r4, r6 */
/* @0x19b278 sub r2, r2, #-1073741823 */
/* @0x19b27c str r11, [r3, r2, lsl #2] */
/* @0x19b280 ldr r1, [r9, #0x18] */
/* @0x19b284 ldr r3, [r10] */
/* @0x19b288 ldr r2, [r12] */
/* @0x19b28c mla r6, r1, r4, r6 */
/* @0x19b290 sub r0, r2, #1 */
/* @0x19b294 add r1, r3, #1 */
/* @0x19b298 ldr r4, [r7] */
/* @0x19b29c and r1, r0, r1 */
/* @0x19b2a0 cmp r1, r4 */
/* @0x19b2a4 sub r8, r6, #1 */
/* @0x19b2a8 beq 0x19bb34 <_Z16Motion_Grid_PathiP5CPathiiiib+0x123c> */
/* @0x19b2ac ldr r2, [r5] */
/* @0x19b2b0 str r8, [r2, r3, lsl #2] */
/* @0x19b2b4 ldr r8, [sp, #0x14] */
/* @0x19b2b8 ldr r3, [r10] */
/* @0x19b2bc ldr r2, [r12] */
/* @0x19b2c0 ldr r0, [r8] */
/* @0x19b2c4 add r3, r3, #1 */
/* @0x19b2c8 sub r2, r2, #1 */
/* @0x19b2cc add r0, r0, #1 */
/* @0x19b2d0 and r3, r2, r3 */
/* @0x19b2d4 str r0, [r8] */
/* @0x19b2d8 str r3, [r10] */
/* @0x19b2dc b 0x19ab94 <_Z16Motion_Grid_PathiP5CPathiiiib+0x29c> */
/* @0x19b2e0 ldr r2, [r9, #0x18] */
/* @0x19b2e4 sub r1, r4, #1 */
/* @0x19b2e8 ldr r3, [r9, #0x1c] */
/* @0x19b2ec ldr r8, [sp, #0x30] */
/* @0x19b2f0 mla r2, r2, r1, r6 */
/* @0x19b2f4 add r2, r2, #1 */
/* @0x19b2f8 str r8, [r3, r2, lsl #2] */
/* @0x19b2fc ldr r0, [r9, #0x18] */
/* @0x19b300 ldr r3, [r10] */
/* @0x19b304 ldr r2, [r12] */
/* @0x19b308 mla r0, r0, r1, r6 */
/* @0x19b30c sub r8, r2, #1 */
/* @0x19b310 ldr r1, [r7] */
/* @0x19b314 str r0, [sp, #0x10] */
/* @0x19b318 add r0, r3, #1 */
/* @0x19b31c and r0, r8, r0 */
/* @0x19b320 ldr r8, [sp, #0x10] */
/* @0x19b324 cmp r0, r1 */
/* @0x19b328 add r8, r8, #1 */
/* @0x19b32c str r8, [sp, #0x2c] */
/* @0x19b330 beq 0x19bbdc <_Z16Motion_Grid_PathiP5CPathiiiib+0x12e4> */
/* @0x19b334 ldr r2, [r5] */
/* @0x19b338 ldr r8, [sp, #0x2c] */
/* @0x19b33c str r8, [r2, r3, lsl #2] */
/* @0x19b340 ldr r8, [sp, #0x14] */
/* @0x19b344 ldr r2, [r10] */
/* @0x19b348 ldr r1, [r12] */
/* @0x19b34c ldr r3, [r8] */
/* @0x19b350 add r2, r2, #1 */
/* @0x19b354 sub r1, r1, #1 */
/* @0x19b358 and r2, r1, r2 */
/* @0x19b35c add r3, r3, #1 */
/* @0x19b360 str r2, [r10] */
/* @0x19b364 str r3, [r8] */
/* @0x19b368 b 0x19ad70 <_Z16Motion_Grid_PathiP5CPathiiiib+0x478> */
/* @0x19b36c ldr r2, [r9, #0x18] */
/* @0x19b370 sub r1, r4, #1 */
/* @0x19b374 ldr r3, [r9, #0x1c] */
/* @0x19b378 ldr r8, [sp, #0x30] */
/* @0x19b37c mla r2, r2, r1, r6 */
/* @0x19b380 sub r2, r2, #-1073741823 */
/* @0x19b384 str r8, [r3, r2, lsl #2] */
/* @0x19b388 ldr r0, [r9, #0x18] */
/* @0x19b38c ldr r3, [r10] */
/* @0x19b390 ldr r2, [r12] */
/* @0x19b394 mla r0, r0, r1, r6 */
/* @0x19b398 sub r8, r2, #1 */
/* @0x19b39c ldr r1, [r7] */
/* @0x19b3a0 str r0, [sp, #0x10] */
/* @0x19b3a4 add r0, r3, #1 */
/* @0x19b3a8 and r0, r8, r0 */
/* @0x19b3ac ldr r8, [sp, #0x10] */
/* @0x19b3b0 cmp r0, r1 */
/* @0x19b3b4 sub r8, r8, #1 */
/* @0x19b3b8 str r8, [sp, #0x24] */
/* @0x19b3bc beq 0x19bc98 <_Z16Motion_Grid_PathiP5CPathiiiib+0x13a0> */
/* @0x19b3c0 ldr r2, [r5] */
/* @0x19b3c4 ldr r8, [sp, #0x24] */
/* @0x19b3c8 str r8, [r2, r3, lsl #2] */
/* @0x19b3cc ldr r8, [sp, #0x14] */
/* @0x19b3d0 ldr r2, [r10] */
/* @0x19b3d4 ldr r1, [r12] */
/* @0x19b3d8 ldr r3, [r8] */
/* @0x19b3dc add r2, r2, #1 */
/* @0x19b3e0 sub r1, r1, #1 */
/* @0x19b3e4 and r2, r1, r2 */
/* @0x19b3e8 add r3, r3, #1 */
/* @0x19b3ec str r2, [r10] */
/* @0x19b3f0 str r3, [r8] */
/* @0x19b3f4 b 0x19ad88 <_Z16Motion_Grid_PathiP5CPathiiiib+0x490> */
/* @0x19b3f8 cmp r2, #0 */
/* @0x19b3fc ldr r1, [pc, #0x360] */
/* @0x19b400 lslge r2, r2, #1 */
/* @0x19b404 str r12, [sp, #0x8] */
/* @0x19b408 movlt r2, #4096 */
/* @0x19b40c str r2, [sp, #0x2c] */
/* @0x19b410 ldr r3, [sp, #0x2c] */
/* @0x19b414 mov r2, #212 */
/* @0x19b418 add r1, pc, r1 */
/* @0x19b41c lsl r0, r3, #2 */
/* @0x19b420 mov r3, #1 */
/* @0x19b424 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x19b428 ldr r12, [sp, #0x8] */
/* @0x19b42c ldr r2, [r12] */
/* @0x19b430 cmp r2, #0 */
/* @0x19b434 str r0, [sp, #0x54] */
/* @0x19b438 ble 0x19b4ac <_Z16Motion_Grid_PathiP5CPathiiiib+0xbb4> */
/* @0x19b43c ldr r3, [r10] */
/* @0x19b440 ldr r1, [r7] */
/* @0x19b444 cmp r3, r1 */
/* @0x19b448 bgt 0x19be10 <_Z16Motion_Grid_PathiP5CPathiiiib+0x1518> */
/* @0x19b44c rsb r2, r1, r2 */
/* @0x19b450 str r2, [sp, #0x58] */
/* @0x19b454 ldr lr, [sp, #0x58] */
/* @0x19b458 ldr r2, [r5] */
/* @0x19b45c str r12, [sp, #0x8] */
/* @0x19b460 lsl r3, lr, #2 */
/* @0x19b464 add r1, r2, r1, lsl #2 */
/* @0x19b468 str r3, [sp, #0xc] */
/* @0x19b46c mov r2, r3 */
/* @0x19b470 bl 0xb65bc <memcpy@plt> */
/* @0x19b474 ldr r2, [r10] */
/* @0x19b478 ldr r3, [sp, #0xc] */
/* @0x19b47c ldr r1, [sp, #0x54] */
/* @0x19b480 lsl r2, r2, #2 */
/* @0x19b484 add r0, r1, r3 */
/* @0x19b488 ldr r1, [r5] */
/* @0x19b48c bl 0xb65bc <memcpy@plt> */
/* @0x19b490 ldr r12, [sp, #0x8] */
/* @0x19b494 ldr r3, [r10] */
/* @0x19b498 mov r2, #0 */
/* @0x19b49c ldr r0, [sp, #0x58] */
/* @0x19b4a0 str r2, [r7] */
/* @0x19b4a4 add r3, r0, r3 */
/* @0x19b4a8 str r3, [r10] */
/* @0x19b4ac ldr r2, [sp, #0x54] */
/* @0x19b4b0 ldr r1, [sp, #0x2c] */
/* @0x19b4b4 ldr r3, [r10] */
/* @0x19b4b8 str r2, [r5] */
/* @0x19b4bc str r1, [r12] */
/* @0x19b4c0 b 0x19b19c <_Z16Motion_Grid_PathiP5CPathiiiib+0x8a4> */
/* @0x19b4c4 cmp r1, #0 */
/* @0x19b4c8 mov r3, #1 */
/* @0x19b4cc lslge r1, r1, #1 */
/* @0x19b4d0 str r12, [sp, #0x8] */
/* @0x19b4d4 movlt r1, #4096 */
/* @0x19b4d8 str r1, [sp, #0x2c] */
/* @0x19b4dc ldr r2, [sp, #0x2c] */
/* @0x19b4e0 ldr r1, [pc, #0x280] */
/* @0x19b4e4 lsl r0, r2, #2 */
/* @0x19b4e8 add r1, pc, r1 */
/* @0x19b4ec mov r2, #212 */
/* @0x19b4f0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x19b4f4 ldr r12, [sp, #0x8] */
/* @0x19b4f8 ldr r2, [r12] */
/* @0x19b4fc cmp r2, #0 */
/* @0x19b500 str r0, [sp, #0x54] */
/* @0x19b504 ble 0x19b578 <_Z16Motion_Grid_PathiP5CPathiiiib+0xc80> */
/* @0x19b508 ldr r3, [r10] */
/* @0x19b50c ldr r1, [r7] */
/* @0x19b510 cmp r3, r1 */
/* @0x19b514 bgt 0x19be4c <_Z16Motion_Grid_PathiP5CPathiiiib+0x1554> */
/* @0x19b518 rsb r2, r1, r2 */
/* @0x19b51c str r2, [sp, #0x58] */
/* @0x19b520 ldr lr, [sp, #0x58] */
/* @0x19b524 ldr r2, [r5] */
/* @0x19b528 str r12, [sp, #0x8] */
/* @0x19b52c lsl r3, lr, #2 */
/* @0x19b530 add r1, r2, r1, lsl #2 */
/* @0x19b534 str r3, [sp, #0xc] */
/* @0x19b538 mov r2, r3 */
/* @0x19b53c bl 0xb65bc <memcpy@plt> */
/* @0x19b540 ldr r2, [r10] */
/* @0x19b544 ldr r3, [sp, #0xc] */
/* @0x19b548 ldr r1, [sp, #0x54] */
/* @0x19b54c lsl r2, r2, #2 */
/* @0x19b550 add r0, r1, r3 */
/* @0x19b554 ldr r1, [r5] */
/* @0x19b558 bl 0xb65bc <memcpy@plt> */
/* @0x19b55c ldr r12, [sp, #0x8] */
/* @0x19b560 ldr r3, [r10] */
/* @0x19b564 mov r2, #0 */
/* @0x19b568 ldr r0, [sp, #0x58] */
/* @0x19b56c str r2, [r7] */
/* @0x19b570 add r3, r0, r3 */
/* @0x19b574 str r3, [r10] */
/* @0x19b578 ldr r3, [sp, #0x54] */
/* @0x19b57c ldr r0, [sp, #0x2c] */
/* @0x19b580 str r3, [r5] */
/* @0x19b584 mov r2, r3 */
/* @0x19b588 str r0, [r12] */
/* @0x19b58c ldr r3, [r10] */
/* @0x19b590 b 0x19b038 <_Z16Motion_Grid_PathiP5CPathiiiib+0x740> */
/* @0x19b594 cmp r2, #0 */
/* @0x19b598 mov r3, #1 */
/* @0x19b59c lslge r2, r2, #1 */
/* @0x19b5a0 strge r2, [sp, #0x2c] */
/* @0x19b5a4 movlt r1, #4096 */
/* @0x19b5a8 strlt r1, [sp, #0x2c] */
/* @0x19b5ac ldr r2, [sp, #0x2c] */
/* @0x19b5b0 ldr r1, [pc, #0x1b4] */
/* @0x19b5b4 str r12, [sp, #0x8] */
/* @0x19b5b8 lsl r0, r2, #2 */
/* @0x19b5bc add r1, pc, r1 */
/* @0x19b5c0 mov r2, #212 */
/* @0x19b5c4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x19b5c8 ldr r12, [sp, #0x8] */
/* @0x19b5cc ldr r2, [r12] */
/* @0x19b5d0 cmp r2, #0 */
/* @0x19b5d4 str r0, [sp, #0x54] */
/* @0x19b5d8 ble 0x19b64c <_Z16Motion_Grid_PathiP5CPathiiiib+0xd54> */
/* @0x19b5dc ldr r3, [r10] */
/* @0x19b5e0 ldr r1, [r7] */
/* @0x19b5e4 cmp r3, r1 */
/* @0x19b5e8 bgt 0x19be88 <_Z16Motion_Grid_PathiP5CPathiiiib+0x1590> */
/* @0x19b5ec rsb r2, r1, r2 */
/* @0x19b5f0 str r2, [sp, #0x58] */
/* @0x19b5f4 ldr lr, [sp, #0x58] */
/* @0x19b5f8 ldr r2, [r5] */
/* @0x19b5fc str r12, [sp, #0x8] */
/* @0x19b600 lsl r3, lr, #2 */
/* @0x19b604 add r1, r2, r1, lsl #2 */
/* @0x19b608 str r3, [sp, #0xc] */
/* @0x19b60c mov r2, r3 */
/* @0x19b610 bl 0xb65bc <memcpy@plt> */
/* @0x19b614 ldr r2, [r10] */
/* @0x19b618 ldr r3, [sp, #0xc] */
/* @0x19b61c ldr r1, [sp, #0x54] */
/* @0x19b620 lsl r2, r2, #2 */
/* @0x19b624 add r0, r1, r3 */
/* @0x19b628 ldr r1, [r5] */
/* @0x19b62c bl 0xb65bc <memcpy@plt> */
/* @0x19b630 ldr r12, [sp, #0x8] */
/* @0x19b634 ldr r3, [r10] */
/* @0x19b638 mov r2, #0 */
/* @0x19b63c ldr r0, [sp, #0x58] */
/* @0x19b640 str r2, [r7] */
/* @0x19b644 add r3, r0, r3 */
/* @0x19b648 str r3, [r10] */
/* @0x19b64c ldr r2, [sp, #0x54] */
/* @0x19b650 ldr r1, [sp, #0x2c] */
/* @0x19b654 ldr r3, [r10] */
/* @0x19b658 str r2, [r5] */
/* @0x19b65c str r1, [r12] */
/* @0x19b660 b 0x19b128 <_Z16Motion_Grid_PathiP5CPathiiiib+0x830> */
/* @0x19b664 cmp r2, #0 */
/* @0x19b668 mov r3, #1 */
/* @0x19b66c lslge r2, r2, #1 */
/* @0x19b670 strge r2, [sp, #0x2c] */
/* @0x19b674 movlt r1, #4096 */
/* @0x19b678 strlt r1, [sp, #0x2c] */
/* @0x19b67c ldr r2, [sp, #0x2c] */
/* @0x19b680 ldr r1, [pc, #0xe8] */
/* @0x19b684 str r12, [sp, #0x8] */
/* @0x19b688 lsl r0, r2, #2 */
/* @0x19b68c add r1, pc, r1 */
/* @0x19b690 mov r2, #212 */
/* @0x19b694 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x19b698 ldr r12, [sp, #0x8] */
/* @0x19b69c ldr r2, [r12] */
/* @0x19b6a0 cmp r2, #0 */
/* @0x19b6a4 str r0, [sp, #0x54] */
/* @0x19b6a8 ble 0x19b71c <_Z16Motion_Grid_PathiP5CPathiiiib+0xe24> */
/* @0x19b6ac ldr r3, [r10] */
/* @0x19b6b0 ldr r1, [r7] */
/* @0x19b6b4 cmp r3, r1 */
/* @0x19b6b8 bgt 0x19bf94 <_Z16Motion_Grid_PathiP5CPathiiiib+0x169c> */
/* @0x19b6bc rsb r2, r1, r2 */
/* @0x19b6c0 str r2, [sp, #0x58] */
/* @0x19b6c4 ldr lr, [sp, #0x58] */
/* @0x19b6c8 ldr r2, [r5] */
/* @0x19b6cc str r12, [sp, #0x8] */
/* @0x19b6d0 lsl r3, lr, #2 */
/* @0x19b6d4 add r1, r2, r1, lsl #2 */
/* @0x19b6d8 str r3, [sp, #0xc] */
/* @0x19b6dc mov r2, r3 */
/* @0x19b6e0 bl 0xb65bc <memcpy@plt> */
/* @0x19b6e4 ldr r2, [r10] */
/* @0x19b6e8 ldr r3, [sp, #0xc] */
/* @0x19b6ec ldr r1, [sp, #0x54] */
/* @0x19b6f0 lsl r2, r2, #2 */
/* @0x19b6f4 add r0, r1, r3 */
/* @0x19b6f8 ldr r1, [r5] */
/* @0x19b6fc bl 0xb65bc <memcpy@plt> */
/* @0x19b700 ldr r12, [sp, #0x8] */
/* @0x19b704 ldr r3, [r10] */
/* @0x19b708 mov r2, #0 */
/* @0x19b70c ldr r0, [sp, #0x58] */
/* @0x19b710 str r2, [r7] */
/* @0x19b714 add r3, r0, r3 */
/* @0x19b718 str r3, [r10] */
/* @0x19b71c ldr r2, [sp, #0x54] */
/* @0x19b720 ldr r1, [sp, #0x2c] */
/* @0x19b724 ldr r3, [r10] */
/* @0x19b728 str r2, [r5] */
/* @0x19b72c str r1, [r12] */
/* @0x19b730 b 0x19b0b0 <_Z16Motion_Grid_PathiP5CPathiiiib+0x7b8> */

/* ── literal pool（0x19b734..0x19b778，18 字；objdump 把前三个字解成了指令，非指令）──
 *   0x19b734 = 0x00257340 → 加到 pc 得 GOT 基址 0x3F1C58
 *   0x19b738 = 0xffffea5c → GOT 槽 0x3F06B4（网格条数）
 *   0x19b73c = 0xffffea60 → GOT 槽 0x3F06B8（网格基址）
 *   0x19b740 = 0xffffea64 → GOT 槽 0x3F06BC（队列元素计数对象）
 *   0x19b744 = 0xffffea68 → GOT 槽 0x3F06C0（环形 base）
 *   0x19b748 = 0xffffea6c → GOT 槽 0x3F06C4（head）
 *   0x19b74c = 0xffffea70 → GOT 槽 0x3F06C8（容量）
 *   0x19b750/19b754/19b758/19b75c/19b760/19b764/19b768/19b76c/19b770/19b774 = 10 个 pc 相对地址
 *     （__FILE__ 字符串，例：0x19b750+0x19ab24=0x34CD58）
 *   0x19b778 = 0xffffea74 → GOT 槽 0x3F06CC（第二个队列的 base）
 */
/* @0x19b734 eoreq r7, r5, r0, asr #6 */
/* @0x19b738 .word 0xffffea5c */
/* @0x19b73c .word 0xffffea60 */
/* @0x19b740 .word 0xffffea64 */
/* @0x19b744 .word 0xffffea68 */
/* @0x19b748 .word 0xffffea6c */
/* @0x19b74c .word 0xffffea70 */
/* @0x19b750 andseq r2, r11, r4, lsr r2 */
/* @0x19b754 andseq r2, r11, r8, lsl r2 */
/* @0x19b758 ldrsbeq r2, [r11], -r4 */
/* @0x19b75c andseq r2, r11, r12, asr #3 */
/* @0x19b760 andseq r1, r11, r12, lsl #30 */
/* @0x19b764 andseq r1, r11, r8, lsr r9 */
/* @0x19b768 andseq r1, r11, r8, ror #16 */
/* @0x19b76c mulseq r11, r4, r7 */
/* @0x19b770 andseq r1, r11, r4, asr #13 */
/* @0x19b774 andseq r0, r11, r8, ror lr */
/* @0x19b778 .word 0xffffea74 */

/* ── 路径写出（本卡重点：path 到底被写了什么）──
 *   0x19b77c 先把三个东西从栈槽搬回：r11=path、r10=x1、r8=y1
 *   1) CPath::Clear()                                0x1a6f98（0x19b78c）
 *   2) CPath::SetKind(0)                             0x1a6e64（0x19b794 mov r1,#0）
 *   3) CPath::SetClosed(0)                           0x1a6e78（0x19b7a0 mov r1,#0）
 *   4) CPath::AddPoint((float)x2,(float)y2,100.0f)   0x19b7cc：前两个实参由 [sp+0xa0]/[sp+0xa4] 经 vcvt.f32.s32 来，
 *      r3 = 0x42c80000（0x19b7b8 mov #0 / 0x19b7bc movt #0x42c8）⇒ 先落的是**终点**
 *   5) 回溯循环（0x19b7e4 起）：current=(r4,r5)、start=([sp+0x38],[sp+0x3c])；两轴都相等 ⇒ 0x19baf0 收尾
 *      否则 dir=cells[current]，按 dir-1 与两轴组合选出 8 方向之一，走一格后
 *      AddPoint(格中心,100.0f)：中心 = hx + cx*cellW + cellW/2、hy + cy*cellH + cellH/2
 *      （0x19b960 起：lr=cellW*cx；r2=(cellW + cellW>>31)>>1 = 半格截断；y 侧同构用 [r9+0x10]）
 *   6) 0x19baf0：AddPoint((float)x1,(float)y1,100.0f) —— 起点
 *   7) CPath::Reverse()                              0x1a76b4（0x19bb28）
 *   ⇒ 写进 CPath 的点序 = 起点、各格中心（起点侧→终点侧）、终点；所有点速度 = 100.0f
 *   ⇒ 点数 = 2 + 回溯步数；起点 == 终点时是 2 个点（首弹即命中，回溯循环一次都不进）
 *   0x19bb2c mov r0,#1 → 0x19adcc（复位戳）→ 返回 1
 *   ★ 全程没有一条 store 落在 path 上：除上面 5 个调用外，path 只当 r0 传参；CPath 字段布局不在本卡
 */
/* @0x19b77c ldr r11, [sp, #0x6c] */
/* @0x19b780 ldr r10, [sp, #0x70] */
/* @0x19b784 ldr r8, [sp, #0x74] */
/* @0x19b788 mov r0, r11 */
/* @0x19b78c bl 0x1a6f98 <_ZN5CPath5ClearEv> */
/* @0x19b790 mov r0, r11 */
/* @0x19b794 mov r1, #0 */
/* @0x19b798 bl 0x1a6e64 <_ZN5CPath7SetKindEi> */
/* @0x19b79c mov r0, r11 */
/* @0x19b7a0 mov r1, #0 */
/* @0x19b7a4 bl 0x1a6e78 <_ZN5CPath9SetClosedEb> */
/* @0x19b7a8 vldr s15, [sp, #160] */
/* @0x19b7ac vldr s11, [sp, #164] */
/* @0x19b7b0 vcvt.f32.s32 s15, s15 */
/* @0x19b7b4 mov r0, r11 */
/* @0x19b7b8 mov r3, #0 */
/* @0x19b7bc movt r3, #0x42c8 */
/* @0x19b7c0 vcvt.f32.s32 s11, s11 */
/* @0x19b7c4 vmov r1, s15 */
/* @0x19b7c8 vmov r2, s11 */
/* @0x19b7cc bl 0x1a72c0 <_ZN5CPath8AddPointEfff> */
/* @0x19b7d0 ldr r4, [sp, #0x40] */
/* @0x19b7d4 ldr r5, [sp, #0x44] */
/* @0x19b7d8 str r11, [sp, #0x28] */
/* @0x19b7dc str r10, [sp, #0x30] */
/* @0x19b7e0 str r8, [sp, #0x34] */
/* @0x19b7e4 ldr r8, [sp, #0x38] */
/* @0x19b7e8 ldr r10, [sp, #0x3c] */
/* @0x19b7ec subs r12, r8, r4 */
/* @0x19b7f0 movne r12, #1 */
/* @0x19b7f4 subs r6, r10, r5 */
/* @0x19b7f8 movne r6, #1 */
/* @0x19b7fc orrs r11, r6, r12 */
/* @0x19b800 beq 0x19baf0 <_Z16Motion_Grid_PathiP5CPathiiiib+0x11f8> */
/* @0x19b804 ldr r1, [r9, #0x18] */
/* @0x19b808 cmp r4, #0 */
/* @0x19b80c ldr r2, [r9, #0x1c] */
/* @0x19b810 sub r8, r1, #1 */
/* @0x19b814 mul r0, r4, r1 */
/* @0x19b818 add lr, r0, r5 */
/* @0x19b81c ldr r7, [r2, lr, lsl #2] */
/* @0x19b820 ble 0x19ba80 <_Z16Motion_Grid_PathiP5CPathiiiib+0x1188> */
/* @0x19b824 cmp r5, r8 */
/* @0x19b828 blt 0x19b9fc <_Z16Motion_Grid_PathiP5CPathiiiib+0x1104> */
/* @0x19b82c ldr lr, [r9, #0x14] */
/* @0x19b830 mov r3, #0 */
/* @0x19b834 str r3, [sp, #0x24] */
/* @0x19b838 sub lr, lr, #1 */
/* @0x19b83c str r3, [sp, #0x20] */
/* @0x19b840 mov r3, #0 */
/* @0x19b844 str r3, [sp, #0x14] */
/* @0x19b848 cmp r4, #0 */
/* @0x19b84c ble 0x19ba98 <_Z16Motion_Grid_PathiP5CPathiiiib+0x11a0> */
/* @0x19b850 rsb r8, r1, r0 */
/* @0x19b854 sub r3, r7, #1 */
/* @0x19b858 add r8, r5, r8 */
/* @0x19b85c ldr r8, [r2, r8, lsl #2] */
/* @0x19b860 subs r11, r8, r3 */
/* @0x19b864 rsbs r3, r11, #0 */
/* @0x19b868 adcs r3, r3, r11 */
/* @0x19b86c str r3, [sp, #0x10] */
/* @0x19b870 cmp r4, lr */
/* @0x19b874 movge r11, #0 */
/* @0x19b878 strge r11, [sp, #0x18] */
/* @0x19b87c bge 0x19b8a0 <_Z16Motion_Grid_PathiP5CPathiiiib+0xfa8> */
/* @0x19b880 add r8, r1, r0 */
/* @0x19b884 sub r3, r7, #1 */
/* @0x19b888 add r8, r8, r5 */
/* @0x19b88c ldr r8, [r2, r8, lsl #2] */
/* @0x19b890 subs r10, r8, r3 */
/* @0x19b894 rsbs r3, r10, #0 */
/* @0x19b898 adcs r3, r3, r10 */
/* @0x19b89c str r3, [sp, #0x18] */
/* @0x19b8a0 cmp r5, #0 */
/* @0x19b8a4 movle r8, #0 */
/* @0x19b8a8 movgt r8, #1 */
/* @0x19b8ac cmp r4, #0 */
/* @0x19b8b0 cmpgt r5, #0 */
/* @0x19b8b4 ble 0x19b9e4 <_Z16Motion_Grid_PathiP5CPathiiiib+0x10ec> */
/* @0x19b8b8 sub r10, r5, #1 */
/* @0x19b8bc rsb r11, r1, r0 */
/* @0x19b8c0 add r11, r11, r10 */
/* @0x19b8c4 sub r3, r7, #1 */
/* @0x19b8c8 ldr r11, [r2, r11, lsl #2] */
/* @0x19b8cc cmp r11, r3 */
/* @0x19b8d0 beq 0x19bac8 <_Z16Motion_Grid_PathiP5CPathiiiib+0x11d0> */
/* @0x19b8d4 mov r11, #0 */
/* @0x19b8d8 add r10, r0, r10 */
/* @0x19b8dc ldr r10, [r2, r10, lsl #2] */
/* @0x19b8e0 cmp r10, r3 */
/* @0x19b8e4 beq 0x19bac0 <_Z16Motion_Grid_PathiP5CPathiiiib+0x11c8> */
/* @0x19b8e8 mov r3, #0 */
/* @0x19b8ec cmp r4, lr */
/* @0x19b8f0 movge r2, #0 */
/* @0x19b8f4 bge 0x19b924 <_Z16Motion_Grid_PathiP5CPathiiiib+0x102c> */
/* @0x19b8f8 cmp r8, #0 */
/* @0x19b8fc moveq r2, r8 */
/* @0x19b900 beq 0x19b924 <_Z16Motion_Grid_PathiP5CPathiiiib+0x102c> */
/* @0x19b904 add r1, r1, r0 */
/* @0x19b908 sub r7, r7, #1 */
/* @0x19b90c add r1, r1, r5 */
/* @0x19b910 sub r1, r1, #1 */
/* @0x19b914 ldr r2, [r2, r1, lsl #2] */
/* @0x19b918 subs r1, r2, r7 */
/* @0x19b91c rsbs r2, r1, #0 */
/* @0x19b920 adcs r2, r2, r1 */
/* @0x19b924 ldr lr, [sp, #0x10] */
/* @0x19b928 cmp lr, #0 */
/* @0x19b92c beq 0x19b9c4 <_Z16Motion_Grid_PathiP5CPathiiiib+0x10cc> */
/* @0x19b930 ldr r8, [sp, #0x38] */
/* @0x19b934 sub r4, r4, #1 */
/* @0x19b938 subs r12, r8, r4 */
/* @0x19b93c movne r12, #1 */
/* @0x19b940 orrs r12, r6, r12 */
/* @0x19b944 beq 0x19b7e4 <_Z16Motion_Grid_PathiP5CPathiiiib+0xeec> */
/* @0x19b948 ldr r2, [r9, #0xc] */
/* @0x19b94c vldr s11, [r9, #4] */
/* @0x19b950 ldr r3, [r9, #0x10] */
/* @0x19b954 vcvt.f32.s32 s10, s11 */
/* @0x19b958 vldr s13, [r9, #8] */
/* @0x19b95c ldr r0, [sp, #0x28] */
/* @0x19b960 mul lr, r2, r4 */
/* @0x19b964 add r2, r2, r2, lsr #31 */
/* @0x19b968 mul r1, r3, r5 */
/* @0x19b96c add r3, r3, r3, lsr #31 */
/* @0x19b970 asr r2, r2, #1 */
/* @0x19b974 vcvt.f32.s32 s11, s13 */
/* @0x19b978 asr r3, r3, #1 */
/* @0x19b97c vmov s12, lr */
/* @0x19b980 vmov s15, r3 */
/* @0x19b984 mov r3, #0 */
/* @0x19b988 vmov s14, r1 */
/* @0x19b98c movt r3, #0x42c8 */
/* @0x19b990 vcvt.f32.s32 s12, s12 */
/* @0x19b994 vcvt.f32.s32 s14, s14 */
/* @0x19b998 vadd.f32 s12, s10, s12 */
/* @0x19b99c vadd.f32 s14, s11, s14 */
/* @0x19b9a0 vmov s11, r2 */
/* @0x19b9a4 vcvt.f32.s32 s15, s15 */
/* @0x19b9a8 vcvt.f32.s32 s13, s11 */
/* @0x19b9ac vadd.f32 s15, s14, s15 */
/* @0x19b9b0 vadd.f32 s13, s12, s13 */
/* @0x19b9b4 vmov r2, s15 */
/* @0x19b9b8 vmov r1, s13 */
/* @0x19b9bc bl 0x1a72c0 <_ZN5CPath8AddPointEfff> */
/* @0x19b9c0 b 0x19b7e4 <_Z16Motion_Grid_PathiP5CPathiiiib+0xeec> */
/* @0x19b9c4 ldr r10, [sp, #0x18] */
/* @0x19b9c8 cmp r10, #0 */
/* @0x19b9cc beq 0x19baa4 <_Z16Motion_Grid_PathiP5CPathiiiib+0x11ac> */
/* @0x19b9d0 ldr r11, [sp, #0x38] */
/* @0x19b9d4 add r4, r4, #1 */
/* @0x19b9d8 subs r12, r11, r4 */
/* @0x19b9dc movne r12, #1 */
/* @0x19b9e0 b 0x19b940 <_Z16Motion_Grid_PathiP5CPathiiiib+0x1048> */
/* @0x19b9e4 cmp r8, #0 */
/* @0x19b9e8 moveq r11, r8 */
/* @0x19b9ec beq 0x19b8e8 <_Z16Motion_Grid_PathiP5CPathiiiib+0xff0> */
/* @0x19b9f0 sub r3, r7, #1 */
/* @0x19b9f4 sub r10, r5, #1 */
/* @0x19b9f8 b 0x19b8d4 <_Z16Motion_Grid_PathiP5CPathiiiib+0xfdc> */
/* @0x19b9fc rsb r10, r1, r0 */
/* @0x19ba00 sub r3, r7, #1 */
/* @0x19ba04 add r10, r5, r10 */
/* @0x19ba08 add r10, r10, #1 */
/* @0x19ba0c ldr r10, [r2, r10, lsl #2] */
/* @0x19ba10 subs r11, r10, r3 */
/* @0x19ba14 rsbs r10, r11, #0 */
/* @0x19ba18 adcs r10, r10, r11 */
/* @0x19ba1c str r10, [sp, #0x24] */
/* @0x19ba20 add lr, lr, #1 */
/* @0x19ba24 ldr lr, [r2, lr, lsl #2] */
/* @0x19ba28 cmp lr, r3 */
/* @0x19ba2c ldr lr, [r9, #0x14] */
/* @0x19ba30 sub lr, lr, #1 */
/* @0x19ba34 beq 0x19c190 <_Z16Motion_Grid_PathiP5CPathiiiib+0x1898> */
/* @0x19ba38 cmp r4, lr */
/* @0x19ba3c bge 0x19ba74 <_Z16Motion_Grid_PathiP5CPathiiiib+0x117c> */
/* @0x19ba40 cmp r5, r8 */
/* @0x19ba44 mov r11, #0 */
/* @0x19ba48 str r11, [sp, #0x20] */
/* @0x19ba4c bge 0x19b840 <_Z16Motion_Grid_PathiP5CPathiiiib+0xf48> */
/* @0x19ba50 add r8, r1, r0 */
/* @0x19ba54 add r8, r8, r5 */
/* @0x19ba58 add r8, r8, #1 */
/* @0x19ba5c ldr r8, [r2, r8, lsl #2] */
/* @0x19ba60 cmp r8, r3 */
/* @0x19ba64 bne 0x19b840 <_Z16Motion_Grid_PathiP5CPathiiiib+0xf48> */
/* @0x19ba68 mov r8, #1 */
/* @0x19ba6c str r8, [sp, #0x14] */
/* @0x19ba70 b 0x19b848 <_Z16Motion_Grid_PathiP5CPathiiiib+0xf50> */
/* @0x19ba74 mov r10, #0 */
/* @0x19ba78 str r10, [sp, #0x20] */
/* @0x19ba7c b 0x19b840 <_Z16Motion_Grid_PathiP5CPathiiiib+0xf48> */
/* @0x19ba80 cmp r5, r8 */
/* @0x19ba84 bge 0x19b82c <_Z16Motion_Grid_PathiP5CPathiiiib+0xf34> */
/* @0x19ba88 mov r10, #0 */
/* @0x19ba8c sub r3, r7, #1 */
/* @0x19ba90 str r10, [sp, #0x24] */
/* @0x19ba94 b 0x19ba20 <_Z16Motion_Grid_PathiP5CPathiiiib+0x1128> */
/* @0x19ba98 mov r10, #0 */
/* @0x19ba9c str r10, [sp, #0x10] */
/* @0x19baa0 b 0x19b870 <_Z16Motion_Grid_PathiP5CPathiiiib+0xf78> */
/* @0x19baa4 cmp r3, #0 */
/* @0x19baa8 beq 0x19bad0 <_Z16Motion_Grid_PathiP5CPathiiiib+0x11d8> */
/* @0x19baac ldr r8, [sp, #0x3c] */
/* @0x19bab0 sub r5, r5, #1 */
/* @0x19bab4 subs r6, r8, r5 */
/* @0x19bab8 movne r6, #1 */
/* @0x19babc b 0x19b940 <_Z16Motion_Grid_PathiP5CPathiiiib+0x1048> */
/* @0x19bac0 mov r3, #1 */
/* @0x19bac4 b 0x19b8ec <_Z16Motion_Grid_PathiP5CPathiiiib+0xff4> */
/* @0x19bac8 mov r11, #1 */
/* @0x19bacc b 0x19b8d8 <_Z16Motion_Grid_PathiP5CPathiiiib+0xfe0> */
/* @0x19bad0 ldr r10, [sp, #0x20] */
/* @0x19bad4 cmp r10, #0 */
/* @0x19bad8 beq 0x19bfd0 <_Z16Motion_Grid_PathiP5CPathiiiib+0x16d8> */
/* @0x19badc ldr r11, [sp, #0x3c] */
/* @0x19bae0 add r5, r5, #1 */
/* @0x19bae4 subs r6, r11, r5 */
/* @0x19bae8 movne r6, #1 */
/* @0x19baec b 0x19b940 <_Z16Motion_Grid_PathiP5CPathiiiib+0x1048> */
/* @0x19baf0 ldr r10, [sp, #0x30] */
/* @0x19baf4 mov r3, #0 */
/* @0x19baf8 ldr r8, [sp, #0x34] */
/* @0x19bafc movt r3, #0x42c8 */
/* @0x19bb00 ldr r11, [sp, #0x28] */
/* @0x19bb04 vmov s11, r10 */
/* @0x19bb08 vmov s13, r8 */
/* @0x19bb0c vcvt.f32.s32 s11, s11 */
/* @0x19bb10 mov r0, r11 */
/* @0x19bb14 vcvt.f32.s32 s13, s13 */
/* @0x19bb18 vmov r1, s11 */
/* @0x19bb1c vmov r2, s13 */
/* @0x19bb20 bl 0x1a72c0 <_ZN5CPath8AddPointEfff> */
/* @0x19bb24 mov r0, r11 */
/* @0x19bb28 bl 0x1a76b4 <_ZN5CPath7ReverseEv> */
/* @0x19bb2c mov r0, #1 */
/* @0x19bb30 b 0x19adcc <_Z16Motion_Grid_PathiP5CPathiiiib+0x4d4> */

/* ── out-of-line 扩容助手群（八个方向体各自的队满落点，本块主体）──
 *   入口：0x19bb34（0x19b2a8）、0x19bbdc（0x19b330）、0x19b3f8（0x19b194）、0x19b4c4（0x19b034）、
 *         0x19b594（0x19b120）、0x19b664（0x19b0a8）、0x19bd54（0x19b228）、0x19bec4（0x19ab08）
 *   每份同模板：容量 = max(cnt*2, 4096)（cmp/lslge/movlt 4096）→ Alloc(...,212,...) →
 *   两段 memcpy（环形断开）→ Free 旧 base → 换 base/cap → b 回各自 push 体续跑
 *   0x19bfd0 / 0x19c07c 是回溯循环的「没有下降邻居」兜底：按 allowDiag 再试另一组方向，
 *   仍未命中就转 0x19b948 继续写点（兜底语义未钉全，见 open 第 3 条）
 *
 * ── §1 open ──
 *   1. 坑位（障碍）编码未定：入口只把 cells[idx] < 0 当失败（0x19aa48/0x19aac4），而扩展闸门等价于
 *      「v <= 0 才可入」（0x19ac70 的 rsbs/movlo）⇒ 若要表达「障碍」，cells 里必须存一个 >= 1 的非戳值。
 *      两者并存说明障碍不是 -1；实际取值要 mp_grid_add_* / mp_grid_set 侧开卡才能定，本节不猜。
 *   2. GOT 0x3F06B4..0x3F06CC 七个槽的宿主对象只有结构证据（{元素数, base, head, cap} 的环形数组），
 *      没有符号名；谁创建/释放它们（是否 GML 全局容器）未证。
 *   3. 回溯兜底 0x19bfd0..0x19c0b8 的方向修正表未逐条钉；正常路径（有下降邻居）不受影响。
 *   4. 八方向 push 体的 8 份展开代码只核对了同构点，没有逐支命名（每份 30..60 条，形状一致）。
 *   5. [sp+0x1c] 的 bool 语义按调用侧（YYGetBool(arg,6) → mp_grid_path 的 allowdiag）定为「允许对角」，
 *      本函数内部只证它参与四角闸（0x19acd4/0x19ad6c/0x19ad84/0x19ad9c/0x19adb4）与回溯兜底。
 *   6. cells 的被写面：本函数只写 cells[邻居]=戳 与复位时的 0，不改障碍格；谁填初始障碍不在本卡。
 */
/* @0x19bb34 cmp r2, #0 */
/* @0x19bb38 ldr r1, [sp, #0x68] */
/* @0x19bb3c lslge r11, r2, #1 */
/* @0x19bb40 mov r3, #1 */
/* @0x19bb44 movlt r11, #4096 */
/* @0x19bb48 mov r2, #212 */
/* @0x19bb4c lsl r0, r11, #2 */
/* @0x19bb50 str r12, [sp, #0x8] */
/* @0x19bb54 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x19bb58 ldr r12, [sp, #0x8] */
/* @0x19bb5c ldr r4, [r12] */
/* @0x19bb60 cmp r4, #0 */
/* @0x19bb64 str r0, [sp, #0x20] */
/* @0x19bb68 ble 0x19bbc8 <_Z16Motion_Grid_PathiP5CPathiiiib+0x12d0> */
/* @0x19bb6c ldr r2, [r10] */
/* @0x19bb70 ldr r3, [r7] */
/* @0x19bb74 cmp r2, r3 */
/* @0x19bb78 bgt 0x19c0f8 <_Z16Motion_Grid_PathiP5CPathiiiib+0x1800> */
/* @0x19bb7c rsb r4, r3, r4 */
/* @0x19bb80 ldr r1, [r5] */
/* @0x19bb84 str r12, [sp, #0x8] */
/* @0x19bb88 lsl r6, r4, #2 */
/* @0x19bb8c add r1, r1, r3, lsl #2 */
/* @0x19bb90 mov r2, r6 */
/* @0x19bb94 bl 0xb65bc <memcpy@plt> */
/* @0x19bb98 ldr r2, [r10] */
/* @0x19bb9c ldr r3, [sp, #0x20] */
/* @0x19bba0 ldr r1, [r5] */
/* @0x19bba4 add r0, r3, r6 */
/* @0x19bba8 lsl r2, r2, #2 */
/* @0x19bbac bl 0xb65bc <memcpy@plt> */
/* @0x19bbb0 ldr r12, [sp, #0x8] */
/* @0x19bbb4 ldr r3, [r10] */
/* @0x19bbb8 mov r0, #0 */
/* @0x19bbbc str r0, [r7] */
/* @0x19bbc0 add r4, r4, r3 */
/* @0x19bbc4 str r4, [r10] */
/* @0x19bbc8 ldr r3, [sp, #0x20] */
/* @0x19bbcc str r11, [r12] */
/* @0x19bbd0 str r3, [r5] */
/* @0x19bbd4 ldr r3, [r10] */
/* @0x19bbd8 b 0x19b2ac <_Z16Motion_Grid_PathiP5CPathiiiib+0x9b4> */
/* @0x19bbdc cmp r2, #0 */
/* @0x19bbe0 ldr r1, [sp, #0x5c] */
/* @0x19bbe4 lslge r2, r2, #1 */
/* @0x19bbe8 strge r2, [sp, #0x50] */
/* @0x19bbec movlt r8, #4096 */
/* @0x19bbf0 strlt r8, [sp, #0x50] */
/* @0x19bbf4 ldr r8, [sp, #0x50] */
/* @0x19bbf8 mov r2, #212 */
/* @0x19bbfc mov r3, #1 */
/* @0x19bc00 str r12, [sp, #0x8] */
/* @0x19bc04 lsl r0, r8, #2 */
/* @0x19bc08 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x19bc0c ldr r12, [sp, #0x8] */
/* @0x19bc10 ldr r8, [r12] */
/* @0x19bc14 cmp r8, #0 */
/* @0x19bc18 str r0, [sp, #0x54] */
/* @0x19bc1c ble 0x19bc80 <_Z16Motion_Grid_PathiP5CPathiiiib+0x1388> */
/* @0x19bc20 ldr r2, [r10] */
/* @0x19bc24 ldr r3, [r7] */
/* @0x19bc28 cmp r2, r3 */
/* @0x19bc2c bgt 0x19c0bc <_Z16Motion_Grid_PathiP5CPathiiiib+0x17c4> */
/* @0x19bc30 rsb r8, r3, r8 */
/* @0x19bc34 ldr r1, [r5] */
/* @0x19bc38 str r12, [sp, #0x8] */
/* @0x19bc3c lsl r2, r8, #2 */
/* @0x19bc40 add r1, r1, r3, lsl #2 */
/* @0x19bc44 str r2, [sp, #0x58] */
/* @0x19bc48 bl 0xb65bc <memcpy@plt> */
/* @0x19bc4c ldr r2, [r10] */
/* @0x19bc50 ldr r3, [sp, #0x54] */
/* @0x19bc54 ldr lr, [sp, #0x58] */
/* @0x19bc58 ldr r1, [r5] */
/* @0x19bc5c lsl r2, r2, #2 */
/* @0x19bc60 add r0, r3, lr */
/* @0x19bc64 bl 0xb65bc <memcpy@plt> */
/* @0x19bc68 ldr r12, [sp, #0x8] */
/* @0x19bc6c ldr r3, [r10] */
/* @0x19bc70 mov r0, #0 */
/* @0x19bc74 str r0, [r7] */
/* @0x19bc78 add r8, r8, r3 */
/* @0x19bc7c str r8, [r10] */
/* @0x19bc80 ldr r3, [sp, #0x54] */
/* @0x19bc84 ldr r8, [sp, #0x50] */
/* @0x19bc88 str r3, [r5] */
/* @0x19bc8c str r8, [r12] */
/* @0x19bc90 ldr r3, [r10] */
/* @0x19bc94 b 0x19b334 <_Z16Motion_Grid_PathiP5CPathiiiib+0xa3c> */
/* @0x19bc98 cmp r2, #0 */
/* @0x19bc9c ldr r1, [sp, #0x60] */
/* @0x19bca0 lslge r2, r2, #1 */
/* @0x19bca4 strge r2, [sp, #0x2c] */
/* @0x19bca8 movlt r8, #4096 */
/* @0x19bcac strlt r8, [sp, #0x2c] */
/* @0x19bcb0 ldr r8, [sp, #0x2c] */
/* @0x19bcb4 mov r2, #212 */
/* @0x19bcb8 mov r3, #1 */
/* @0x19bcbc str r12, [sp, #0x8] */
/* @0x19bcc0 lsl r0, r8, #2 */
/* @0x19bcc4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x19bcc8 ldr r12, [sp, #0x8] */
/* @0x19bccc ldr r8, [r12] */
/* @0x19bcd0 cmp r8, #0 */
/* @0x19bcd4 str r0, [sp, #0x4c] */
/* @0x19bcd8 ble 0x19bd3c <_Z16Motion_Grid_PathiP5CPathiiiib+0x1444> */
/* @0x19bcdc ldr r2, [r10] */
/* @0x19bce0 ldr r3, [r7] */
/* @0x19bce4 cmp r2, r3 */
/* @0x19bce8 bgt 0x19c040 <_Z16Motion_Grid_PathiP5CPathiiiib+0x1748> */
/* @0x19bcec rsb r8, r3, r8 */
/* @0x19bcf0 ldr r1, [r5] */
/* @0x19bcf4 str r12, [sp, #0x8] */
/* @0x19bcf8 lsl r2, r8, #2 */
/* @0x19bcfc add r1, r1, r3, lsl #2 */
/* @0x19bd00 str r2, [sp, #0x50] */
/* @0x19bd04 bl 0xb65bc <memcpy@plt> */
/* @0x19bd08 ldr r2, [r10] */
/* @0x19bd0c ldr r3, [sp, #0x4c] */
/* @0x19bd10 ldr lr, [sp, #0x50] */
/* @0x19bd14 ldr r1, [r5] */
/* @0x19bd18 lsl r2, r2, #2 */
/* @0x19bd1c add r0, r3, lr */
/* @0x19bd20 bl 0xb65bc <memcpy@plt> */
/* @0x19bd24 ldr r12, [sp, #0x8] */
/* @0x19bd28 ldr r3, [r10] */
/* @0x19bd2c mov r0, #0 */
/* @0x19bd30 str r0, [r7] */
/* @0x19bd34 add r8, r8, r3 */
/* @0x19bd38 str r8, [r10] */
/* @0x19bd3c ldr r3, [sp, #0x4c] */
/* @0x19bd40 ldr r8, [sp, #0x2c] */
/* @0x19bd44 str r3, [r5] */
/* @0x19bd48 str r8, [r12] */
/* @0x19bd4c ldr r3, [r10] */
/* @0x19bd50 b 0x19b3c0 <_Z16Motion_Grid_PathiP5CPathiiiib+0xac8> */
/* @0x19bd54 cmp r2, #0 */
/* @0x19bd58 ldr r1, [sp, #0x64] */
/* @0x19bd5c lslge r2, r2, #1 */
/* @0x19bd60 strge r2, [sp, #0x24] */
/* @0x19bd64 movlt r8, #4096 */
/* @0x19bd68 strlt r8, [sp, #0x24] */
/* @0x19bd6c ldr r8, [sp, #0x24] */
/* @0x19bd70 mov r2, #212 */
/* @0x19bd74 mov r3, #1 */
/* @0x19bd78 str r12, [sp, #0x8] */
/* @0x19bd7c lsl r0, r8, #2 */
/* @0x19bd80 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x19bd84 ldr r12, [sp, #0x8] */
/* @0x19bd88 ldr r8, [r12] */
/* @0x19bd8c cmp r8, #0 */
/* @0x19bd90 str r0, [sp, #0x2c] */
/* @0x19bd94 ble 0x19bdf8 <_Z16Motion_Grid_PathiP5CPathiiiib+0x1500> */
/* @0x19bd98 ldr r2, [r10] */
/* @0x19bd9c ldr r3, [r7] */
/* @0x19bda0 cmp r2, r3 */
/* @0x19bda4 bgt 0x19c004 <_Z16Motion_Grid_PathiP5CPathiiiib+0x170c> */
/* @0x19bda8 rsb r8, r3, r8 */
/* @0x19bdac ldr r1, [r5] */
/* @0x19bdb0 str r12, [sp, #0x8] */
/* @0x19bdb4 lsl r2, r8, #2 */
/* @0x19bdb8 add r1, r1, r3, lsl #2 */
/* @0x19bdbc str r2, [sp, #0x48] */
/* @0x19bdc0 bl 0xb65bc <memcpy@plt> */
/* @0x19bdc4 ldr r2, [r10] */
/* @0x19bdc8 ldr r3, [sp, #0x2c] */
/* @0x19bdcc ldr lr, [sp, #0x48] */
/* @0x19bdd0 ldr r1, [r5] */
/* @0x19bdd4 lsl r2, r2, #2 */
/* @0x19bdd8 add r0, r3, lr */
/* @0x19bddc bl 0xb65bc <memcpy@plt> */
/* @0x19bde0 ldr r12, [sp, #0x8] */
/* @0x19bde4 ldr r3, [r10] */
/* @0x19bde8 mov r0, #0 */
/* @0x19bdec str r0, [r7] */
/* @0x19bdf0 add r8, r8, r3 */
/* @0x19bdf4 str r8, [r10] */
/* @0x19bdf8 ldr r3, [sp, #0x2c] */
/* @0x19bdfc ldr r8, [sp, #0x24] */
/* @0x19be00 str r3, [r5] */
/* @0x19be04 str r8, [r12] */
/* @0x19be08 ldr r3, [r10] */
/* @0x19be0c b 0x19b22c <_Z16Motion_Grid_PathiP5CPathiiiib+0x934> */
/* @0x19be10 rsb r2, r1, r3 */
/* @0x19be14 ldr r3, [r5] */
/* @0x19be18 lsl r2, r2, #2 */
/* @0x19be1c add r1, r3, r1, lsl #2 */
/* @0x19be20 bl 0xb65bc <memcpy@plt> */
/* @0x19be24 ldr r2, [r10] */
/* @0x19be28 ldr r3, [r7] */
/* @0x19be2c mov lr, #0 */
/* @0x19be30 ldr r0, [r5] */
/* @0x19be34 rsb r3, r3, r2 */
/* @0x19be38 str lr, [r7] */
/* @0x19be3c str r3, [r10] */
/* @0x19be40 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19be44 ldr r12, [sp, #0x8] */
/* @0x19be48 b 0x19b4ac <_Z16Motion_Grid_PathiP5CPathiiiib+0xbb4> */
/* @0x19be4c rsb r2, r1, r3 */
/* @0x19be50 ldr r3, [r5] */
/* @0x19be54 lsl r2, r2, #2 */
/* @0x19be58 add r1, r3, r1, lsl #2 */
/* @0x19be5c bl 0xb65bc <memcpy@plt> */
/* @0x19be60 ldr r2, [r10] */
/* @0x19be64 ldr r3, [r7] */
/* @0x19be68 mov lr, #0 */
/* @0x19be6c ldr r0, [r5] */
/* @0x19be70 rsb r3, r3, r2 */
/* @0x19be74 str lr, [r7] */
/* @0x19be78 str r3, [r10] */
/* @0x19be7c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19be80 ldr r12, [sp, #0x8] */
/* @0x19be84 b 0x19b578 <_Z16Motion_Grid_PathiP5CPathiiiib+0xc80> */
/* @0x19be88 rsb r2, r1, r3 */
/* @0x19be8c ldr r3, [r5] */
/* @0x19be90 lsl r2, r2, #2 */
/* @0x19be94 add r1, r3, r1, lsl #2 */
/* @0x19be98 bl 0xb65bc <memcpy@plt> */
/* @0x19be9c ldr r2, [r10] */
/* @0x19bea0 ldr r3, [r7] */
/* @0x19bea4 mov lr, #0 */
/* @0x19bea8 ldr r0, [r5] */
/* @0x19beac rsb r3, r3, r2 */
/* @0x19beb0 str lr, [r7] */
/* @0x19beb4 str r3, [r10] */
/* @0x19beb8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19bebc ldr r12, [sp, #0x8] */
/* @0x19bec0 b 0x19b64c <_Z16Motion_Grid_PathiP5CPathiiiib+0xd54> */
/* @0x19bec4 cmp r6, #0 */
/* @0x19bec8 ldr r1, [pc, #-0x75c] */
/* @0x19becc lslge r6, r6, #1 */
/* @0x19bed0 mov r3, #1 */
/* @0x19bed4 movlt r6, #4096 */
/* @0x19bed8 add r1, pc, r1 */
/* @0x19bedc lsl r0, r6, #2 */
/* @0x19bee0 mov r2, #212 */
/* @0x19bee4 str r12, [sp, #0x8] */
/* @0x19bee8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x19beec ldr r3, [sp, #0x20] */
/* @0x19bef0 ldr r12, [sp, #0x8] */
/* @0x19bef4 ldr r1, [r3] */
/* @0x19bef8 cmp r1, #0 */
/* @0x19befc str r0, [sp, #0x28] */
/* @0x19bf00 ble 0x19c184 <_Z16Motion_Grid_PathiP5CPathiiiib+0x188c> */
/* @0x19bf04 ldr r2, [r12] */
/* @0x19bf08 ldr r3, [r7] */
/* @0x19bf0c cmp r2, r3 */
/* @0x19bf10 bgt 0x19c134 <_Z16Motion_Grid_PathiP5CPathiiiib+0x183c> */
/* @0x19bf14 ldr r2, [pc, #-0x7a4] */
/* @0x19bf18 rsb r1, r3, r1 */
/* @0x19bf1c str r1, [sp, #0x30] */
/* @0x19bf20 lsl lr, r1, #2 */
/* @0x19bf24 str lr, [sp, #0x34] */
/* @0x19bf28 ldr r5, [r4, r2] */
/* @0x19bf2c mov r2, lr */
/* @0x19bf30 ldr r1, [r5] */
/* @0x19bf34 str r12, [sp, #0x8] */
/* @0x19bf38 add r1, r1, r3, lsl #2 */
/* @0x19bf3c bl 0xb65bc <memcpy@plt> */
/* @0x19bf40 ldr r12, [sp, #0x8] */
/* @0x19bf44 ldr r3, [sp, #0x28] */
/* @0x19bf48 ldr lr, [sp, #0x34] */
/* @0x19bf4c ldr r2, [r12] */
/* @0x19bf50 add r0, r3, lr */
/* @0x19bf54 ldr r1, [r5] */
/* @0x19bf58 lsl r2, r2, #2 */
/* @0x19bf5c bl 0xb65bc <memcpy@plt> */
/* @0x19bf60 ldr r12, [sp, #0x8] */
/* @0x19bf64 ldr r0, [sp, #0x30] */
/* @0x19bf68 mov r2, #0 */
/* @0x19bf6c str r2, [r7] */
/* @0x19bf70 ldr r3, [r12] */
/* @0x19bf74 add r3, r0, r3 */
/* @0x19bf78 str r3, [r12] */
/* @0x19bf7c ldr r3, [sp, #0x28] */
/* @0x19bf80 ldr r0, [sp, #0x20] */
/* @0x19bf84 str r3, [r5] */
/* @0x19bf88 str r6, [r0] */
/* @0x19bf8c ldr r3, [r12] */
/* @0x19bf90 b 0x19ab14 <_Z16Motion_Grid_PathiP5CPathiiiib+0x21c> */
/* @0x19bf94 rsb r2, r1, r3 */
/* @0x19bf98 ldr r3, [r5] */
/* @0x19bf9c lsl r2, r2, #2 */
/* @0x19bfa0 add r1, r3, r1, lsl #2 */
/* @0x19bfa4 bl 0xb65bc <memcpy@plt> */
/* @0x19bfa8 ldr r2, [r10] */
/* @0x19bfac ldr r3, [r7] */
/* @0x19bfb0 mov lr, #0 */
/* @0x19bfb4 ldr r0, [r5] */
/* @0x19bfb8 rsb r3, r3, r2 */
/* @0x19bfbc str lr, [r7] */
/* @0x19bfc0 str r3, [r10] */
/* @0x19bfc4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19bfc8 ldr r12, [sp, #0x8] */
/* @0x19bfcc b 0x19b71c <_Z16Motion_Grid_PathiP5CPathiiiib+0xe24> */
/* @0x19bfd0 ldr lr, [sp, #0x24] */
/* @0x19bfd4 ldr r8, [sp, #0x1c] */
/* @0x19bfd8 tst lr, r8 */
/* @0x19bfdc beq 0x19c07c <_Z16Motion_Grid_PathiP5CPathiiiib+0x1784> */
/* @0x19bfe0 sub r4, r4, #1 */
/* @0x19bfe4 add r5, r5, #1 */
/* @0x19bfe8 ldr r10, [sp, #0x38] */
/* @0x19bfec ldr r11, [sp, #0x3c] */
/* @0x19bff0 subs r12, r10, r4 */
/* @0x19bff4 movne r12, #1 */
/* @0x19bff8 subs r6, r11, r5 */
/* @0x19bffc movne r6, #1 */
/* @0x19c000 b 0x19b940 <_Z16Motion_Grid_PathiP5CPathiiiib+0x1048> */
/* @0x19c004 rsb r2, r3, r2 */
/* @0x19c008 ldr r1, [r5] */
/* @0x19c00c lsl r2, r2, #2 */
/* @0x19c010 add r1, r1, r3, lsl #2 */
/* @0x19c014 bl 0xb65bc <memcpy@plt> */
/* @0x19c018 ldr r2, [r10] */
/* @0x19c01c ldr r3, [r7] */
/* @0x19c020 mov lr, #0 */
/* @0x19c024 ldr r0, [r5] */
/* @0x19c028 rsb r3, r3, r2 */
/* @0x19c02c str lr, [r7] */
/* @0x19c030 str r3, [r10] */
/* @0x19c034 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19c038 ldr r12, [sp, #0x8] */
/* @0x19c03c b 0x19bdf8 <_Z16Motion_Grid_PathiP5CPathiiiib+0x1500> */
/* @0x19c040 rsb r2, r3, r2 */
/* @0x19c044 ldr r1, [r5] */
/* @0x19c048 lsl r2, r2, #2 */
/* @0x19c04c add r1, r1, r3, lsl #2 */
/* @0x19c050 bl 0xb65bc <memcpy@plt> */
/* @0x19c054 ldr r2, [r10] */
/* @0x19c058 ldr r3, [r7] */
/* @0x19c05c mov lr, #0 */
/* @0x19c060 ldr r0, [r5] */
/* @0x19c064 rsb r3, r3, r2 */
/* @0x19c068 str lr, [r7] */
/* @0x19c06c str r3, [r10] */
/* @0x19c070 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19c074 ldr r12, [sp, #0x8] */
/* @0x19c078 b 0x19bd3c <_Z16Motion_Grid_PathiP5CPathiiiib+0x1444> */
/* @0x19c07c ldr lr, [sp, #0x14] */
/* @0x19c080 ldr r8, [sp, #0x1c] */
/* @0x19c084 tst lr, r8 */
/* @0x19c088 addne r4, r4, #1 */
/* @0x19c08c addne r5, r5, #1 */
/* @0x19c090 bne 0x19bfe8 <_Z16Motion_Grid_PathiP5CPathiiiib+0x16f0> */
/* @0x19c094 ldr r8, [sp, #0x1c] */
/* @0x19c098 tst r11, r8 */
/* @0x19c09c subne r4, r4, #1 */
/* @0x19c0a0 bne 0x19c0b4 <_Z16Motion_Grid_PathiP5CPathiiiib+0x17bc> */
/* @0x19c0a4 ldr r8, [sp, #0x1c] */
/* @0x19c0a8 tst r2, r8 */
/* @0x19c0ac beq 0x19b948 <_Z16Motion_Grid_PathiP5CPathiiiib+0x1050> */
/* @0x19c0b0 add r4, r4, #1 */
/* @0x19c0b4 sub r5, r5, #1 */
/* @0x19c0b8 b 0x19bfe8 <_Z16Motion_Grid_PathiP5CPathiiiib+0x16f0> */
/* @0x19c0bc rsb r2, r3, r2 */
/* @0x19c0c0 ldr r1, [r5] */
/* @0x19c0c4 lsl r2, r2, #2 */
/* @0x19c0c8 add r1, r1, r3, lsl #2 */
/* @0x19c0cc bl 0xb65bc <memcpy@plt> */
/* @0x19c0d0 ldr r2, [r10] */
/* @0x19c0d4 ldr r3, [r7] */
/* @0x19c0d8 mov lr, #0 */
/* @0x19c0dc ldr r0, [r5] */
/* @0x19c0e0 rsb r3, r3, r2 */
/* @0x19c0e4 str lr, [r7] */
/* @0x19c0e8 str r3, [r10] */
/* @0x19c0ec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19c0f0 ldr r12, [sp, #0x8] */
/* @0x19c0f4 b 0x19bc80 <_Z16Motion_Grid_PathiP5CPathiiiib+0x1388> */
/* @0x19c0f8 rsb r2, r3, r2 */
/* @0x19c0fc ldr r1, [r5] */
/* @0x19c100 lsl r2, r2, #2 */
/* @0x19c104 add r1, r1, r3, lsl #2 */
/* @0x19c108 bl 0xb65bc <memcpy@plt> */
/* @0x19c10c ldr r2, [r10] */
/* @0x19c110 ldr r3, [r7] */
/* @0x19c114 mov lr, #0 */
/* @0x19c118 ldr r0, [r5] */
/* @0x19c11c rsb r3, r3, r2 */
/* @0x19c120 str lr, [r7] */
/* @0x19c124 str r3, [r10] */
/* @0x19c128 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19c12c ldr r12, [sp, #0x8] */
/* @0x19c130 b 0x19bbc8 <_Z16Motion_Grid_PathiP5CPathiiiib+0x12d0> */
/* @0x19c134 ldr r1, [pc, #-0x9c4] */
/* @0x19c138 rsb r2, r3, r2 */
/* @0x19c13c lsl r2, r2, #2 */
/* @0x19c140 ldr r5, [r4, r1] */
/* @0x19c144 ldr r1, [r5] */
/* @0x19c148 str r12, [sp, #0x8] */
/* @0x19c14c add r1, r1, r3, lsl #2 */
/* @0x19c150 bl 0xb65bc <memcpy@plt> */
/* @0x19c154 ldr r12, [sp, #0x8] */
/* @0x19c158 ldr r3, [r7] */
/* @0x19c15c mov r2, #0 */
/* @0x19c160 ldr r0, [r5] */
/* @0x19c164 ldr r1, [r12] */
/* @0x19c168 str r2, [r7] */
/* @0x19c16c rsb r3, r3, r1 */
/* @0x19c170 str r3, [r12] */
/* @0x19c174 str r12, [sp, #0x8] */
/* @0x19c178 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19c17c ldr r12, [sp, #0x8] */
/* @0x19c180 b 0x19bf7c <_Z16Motion_Grid_PathiP5CPathiiiib+0x1684> */
/* @0x19c184 ldr r3, [pc, #-0xa14] */
/* @0x19c188 ldr r5, [r4, r3] */
/* @0x19c18c b 0x19bf7c <_Z16Motion_Grid_PathiP5CPathiiiib+0x1684> */
/* @0x19c190 cmp r4, lr */
/* @0x19c194 movge r3, #1 */
/* @0x19c198 strge r3, [sp, #0x20] */
/* @0x19c19c bge 0x19b840 <_Z16Motion_Grid_PathiP5CPathiiiib+0xf48> */
/* @0x19c1a0 mov r8, #1 */
/* @0x19c1a4 str r8, [sp, #0x20] */
/* @0x19c1a8 b 0x19ba50 <_Z16Motion_Grid_PathiP5CPathiiiib+0x1158> */


/* ══ §2 GR_3D_Draw_Block(float, float, float, float, float, float, int, float, float) 0x17763c ══
 * @func 0x17763c 0x178d44  size 5896  1474 条（0x177aa0..0x177ac0 的 9 个字是 literal pool，中间用 b 跳过）
 * 级别: 骨架（实参落位、顶点缓冲协议、首顶点 9 字段、36 顶点计数、Primitive 起止、纹理重复存档/恢复逐条钉住；
 *       36 个顶点各自的 UV 系数表与「无精灵」分支的退化 UV 只给结构，未逐顶点列名）
 * 符号: _Z16GR_3D_Draw_Blockffffffiff → void GR_3D_Draw_Block(float, float, float, float, float, float, int, float, float)
 * 调用点: 0x1441f8、0x164dfc 两处 bl；另有 0xb7d44 的尾跳落到 0x177d6c（同函数内的共享尾段，不是另一个函数）
 *       下一个符号是 GR_3D_Draw_Cylinder 0x178d44
 * 实参落位: r0=x1  r1=y1  r2=z1  r3=arg3  [sp+0xd0]=arg4  [sp+0xd4]=arg5  [sp+0xd8]=arg6(int)
 *           [sp+0xdc]=arg7  [sp+0xe0]=arg8（帧 = 36 + 24 + 148 = 0xd0）
 *           s18=[sp+0xd0] s19=[sp+0xd4] s16=[sp+0xdc] s17=[sp+0xe0] r6=[sp+0xd8]
 * 返回值: 没有自己的 return —— 尾部是 b GR_D3D_Set_Texture_Repeat(存档旧值)，返回值即该调用的返回值
 *
 * ── 一句话 ──
 *   Graphics::Flush() → 纹理重复模式存档并置 1 → GR_3D_Primitive_Begin(4, arg6) → **无循环**地展开写出
 *   36 个 36 字节顶点（6 个面 × 每面 6 顶点 = 12 个三角形）→ Primitive_End() → 再 Flush() → 尾调恢复纹理重复。
 *
 * ── 顶点缓冲协议（GOT 0x3F02C8 / 0x3F02D8 / 0x3F02DC）──
 *   r1 = *(GOT 0x3F02C8) → 缓冲对象；[r1] = 当前顶点数（以**顶点**为单位）
 *   r12 = *(GOT 0x3F02D8) → 顶点数组首址；r2 = r12 + count*36（0x1776c8 的 add r3,r3,r3,lsl#3 再 0x1776cc 的 lsl #2
 *   = count*9*4 = count*36）
 *   *(GOT 0x3F02DC) ← r2（把这个新顶点地址记成「当前指针」）
 *   收尾：count += 36（0x17877c）、当前指针 = 首顶点 + 36（0x17876c / 0x178778）
 *
 * ── 顶点记录：36 字节 = 9 个 32 位字（首顶点 0x1776d4..0x1776f8 逐字段钉住）──
 *   +0x00 float x      = arg0（r10）
 *   +0x04 float y      = arg1（r11）
 *   +0x08 float z      = arg2（r9）
 *   +0x0c float nx     = 0.0f（s15；池字 0x177aa0 = 0x00000000，已用 libyoyo.so 原始字节核过）
 *   +0x10 float ny     = 0.0f（同上）
 *   +0x14 float nz     = -1.0f（s12 = vmov.f32 #-1.0）
 *   +0x18 uint32 color = *(*(GOT 0x3EDD04)) & ~1（0x1776f0..0x1776fc，bit0 被清；全函数只算这一次，36 槽共用）
 *   +0x1c float u      = 见 UV 公式
 *   +0x20 float v      = 见 UV 公式
 *   color 覆盖全部 36 槽：0x18 落在每个 36 字节槽的 +0x18，35 槽各 2 条 + 首槽 1 条 = 71 条 store
 *
 * ── 位置从哪来（本卡重点 2 的一半答案）──
 *   全函数只有 6 条「从内存读浮点」的 vldr：s14（GOT 0x3F019C → 纹理宽）、s13（GOT 0x3F01A0 → 纹理高），
 *   加 s18/s19/s16/s17（都是栈上实参）。没有矩阵、没有四元数、没有坐标变换调用。
 *   顶点的 x/y/z 只从 r10/r4（arg0/arg3）、r11/s18（arg1/arg4）、r9/s19（arg2/arg5）取。
 *   ⇒ 6 个浮点实参是**两个对角点** (x1,y1,z1)/(x2,y2,z2)，36 个顶点是这 8 个角的重复（每面 6 个）。
 *   写点互证：槽 0 用 r10/r11/r9；槽 2 的 x 用 r4；槽 1 的 y 用 s18；槽 6..11 的 z 用 s19；槽 12..17 的 y 用 s18。
 */
/* @0x17763c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x177640 vpush {d8, d9, d10} */
/* @0x177644 sub sp, sp, #148 */
/* @0x177648 vldr s18, [sp, #208] */
/* @0x17764c mov r9, r2 */
/* @0x177650 mov r11, r1 */
/* @0x177654 mov r4, r3 */
/* @0x177658 mov r10, r0 */
/* @0x17765c ldr r6, [sp, #0xd8] */
/* @0x177660 vldr s19, [sp, #212] */
/* @0x177664 vldr s16, [sp, #220] */
/* @0x177668 vldr s17, [sp, #224] */
/* @0x17766c bl 0x1852ec <_ZN8Graphics5FlushEv> */

/* ── GOT 基址、Flush、纹理重复存档 ──
 *   r5 = pc + 池字 0x0027a5d8 = GOT 基址 0x3F1C58（同一基址）
 *   0x17766c Graphics::Flush()（收尾 0x178788 再来一次，成对）
 *   0x177674 GR_D3D_Get_Texture_Repeat() → [sp+0x68]（存档）；0x177684 GR_D3D_Set_Texture_Repeat(1)（强制重复）
 *   ⇒ 本函数假定 UV 允许越界环绕，所以先把 repeat 打开
 */
/* @0x177670 ldr r5, [pc, #0x42c] */
/* @0x177674 bl 0x1689e0 <_Z25GR_D3D_Get_Texture_Repeatv> */
/* @0x177678 add r5, pc, r5 */
/* @0x17767c str r0, [sp, #0x68] */
/* @0x177680 mov r0, #1 */
/* @0x177684 bl 0x168870 <_Z25GR_D3D_Set_Texture_Repeatb> */
/* @0x177688 mov r1, r6 */
/* @0x17768c mov r0, #4 */
/* @0x177690 bl 0x1769dc <_Z21GR_3D_Primitive_Beginii> */

/* ── 定位新顶点 + 写首个顶点的 8 个字段 + color 闸 ──
 *   0x177694..0x1776b8 取 5 个 GOT 槽：0x3F02C8（缓冲对象）、0x3F02DC（当前指针槽）、0x3F02D8（数组首址）、
 *     0x3EDD04（颜色字）、0x3F0198（当前精灵槽）
 *   0x1776bc..0x1776cc：count = [缓冲对象]；offset = count*36；r2 = 数组首址 + offset
 *   0x1776d4..0x1776f8：x=arg0、y=arg1、z=arg2、+0x0c/+0x10=0.0f、+0x14=-1.0f、color=(*(GOT 0x3EDD04))&~1
 *   0x1776f0..0x1776f8 同时把 *(GOT 0x3F02DC) = r2（当前指针）
 *   0x177700..0x17770c：精灵指针 = *(*(GOT 0x3F0198))；为 0 → 0x1787a0（无精灵分支）
 */
/* @0x177694 ldr r1, [pc, #0x40c] */
/* @0x177698 ldr r3, [pc, #0x40c] */
/* @0x17769c vmov.f32 s12, #-1.000000e+00 */
/* @0x1776a0 ldr r2, [pc, #0x408] */
/* @0x1776a4 vldr s15, [pc, #1012] */
/* @0x1776a8 ldr r1, [r5, r1] */
/* @0x1776ac ldr r0, [pc, #0x400] */
/* @0x1776b0 str r1, [sp, #0x3c] */
/* @0x1776b4 ldr r3, [r5, r3] */
/* @0x1776b8 str r3, [sp, #0x40] */
/* @0x1776bc ldr r3, [r1] */
/* @0x1776c0 ldr r12, [r5, r2] */
/* @0x1776c4 ldr r1, [pc, #0x3ec] */
/* @0x1776c8 add r3, r3, r3, lsl #3 */
/* @0x1776cc add r2, r12, r3, lsl #2 */
/* @0x1776d0 ldr r3, [sp, #0x40] */
/* @0x1776d4 vstr s15, [r2, #12] */
/* @0x1776d8 vstr s15, [r2, #16] */
/* @0x1776dc str r10, [r2] */
/* @0x1776e0 vstr s12, [r2, #20] */
/* @0x1776e4 str r2, [r3] */
/* @0x1776e8 str r11, [r2, #0x4] */
/* @0x1776ec str r9, [r2, #0x8] */
/* @0x1776f0 ldr r3, [r5, r0] */
/* @0x1776f4 ldr r0, [r3] */
/* @0x1776f8 bic r0, r0, #1 */
/* @0x1776fc str r0, [r2, #0x18] */
/* @0x177700 ldr r3, [r5, r1] */
/* @0x177704 ldr r1, [r3] */
/* @0x177708 cmp r1, #0 */

/* ── 唯一的条件分支：精灵为空就跳去无精灵分支 ──
 *   全函数只有这一条条件跳转（0x17770c beq 0x1787a0）；其余代码是直线，说明 36 个顶点是编译期完全展开的
 */
/* @0x17770c beq 0x1787a0 <_Z16GR_3D_Draw_Blockffffffiff+0x1164> */

/* ── 纹理路径前半：顶点 0..11 的 UV 与法线 ──
 *   精灵对象上四个 int16 子矩形边：+0x00 / +0x02 / +0x0c / +0x0e（ldrsh；按用法是 left / top / 宽 / 高）
 *   纹理尺寸：s14 = *(*(GOT 0x3F019C))（0x177730..0x177748）、s13 = *(*(GOT 0x3F01A0))（0x177760..0x177798）
 *   UV 模板：u = (left + 系数*[+0x0c]) / 纹理宽；v = (top + 系数*[+0x0e]) / 纹理高
 *     例顶点 0：u = left/宽（0x177778 的 vmla 系数是 s15=0.0，0x177788 vdiv），v = top/高（0x177830 vdiv）
 *     例顶点 1：v 用 0x177814 的 vmla（系数 s17=arg8）⇒ 同一面两个角的 v 差一个 arg8 倍子矩形高
 *   系数只有四个来源：s15=0.0f（池字 0x177aa0）、s11=1.0f（0x177714 vmov.f32 #1.0）、s16=arg7、s17=arg8
 *   法线：+0x0c/+0x10/+0x14 三格由 s15(0.0)/s11(+1.0)/s12(-1.0) 组合 ⇒ 轴对齐单位向量
 *     顶点 0..5 = (0,0,-1)（0x1776d4/0x1776d8/0x1776e0 与 0x1777d8/0x1777dc 同型写入）
 *     顶点 6..11 = (0,0,+1)（0x177a74 一带把 0x14 写成 s11）
 */
/* @0x177710 ldrsh r12, [r1] */
/* @0x177714 vmov.f32 s11, #1.000000e+00 */
/* @0x177718 ldrsh r3, [r1, #12] */
/* @0x17771c add r6, r2, #1120 */
/* @0x177720 add lr, r2, #1088 */
/* @0x177724 vmov s13, r12 */
/* @0x177728 add r12, r2, #900 */
/* @0x17772c vmov s10, r3 */
/* @0x177730 ldr r3, [pc, #0x384] */
/* @0x177734 str r12, [sp, #0x38] */
/* @0x177738 mov r7, r6 */
/* @0x17773c ldrsh r12, [r1, #2] */
/* @0x177740 mov r8, r6 */
/* @0x177744 ldr r3, [r5, r3] */
/* @0x177748 vldr s14, [r3] */
/* @0x17774c ldrsh r3, [r1, #14] */
/* @0x177750 vmov s6, r12 */
/* @0x177754 ldrsh r12, [r1] */
/* @0x177758 vcvt.f32.s32 s10, s10 */
/* @0x17775c vmov s1, r3 */
/* @0x177760 ldr r3, [pc, #0x358] */
/* @0x177764 vmov s9, r12 */
/* @0x177768 ldrsh r12, [r1, #12] */
/* @0x17776c vmov s4, r12 */
/* @0x177770 ldrsh r12, [r1] */
/* @0x177774 vcvt.f32.s32 s13, s13 */
/* @0x177778 vmla.f32 s13, s10, s15 */
/* @0x17777c vmov s10, r12 */
/* @0x177780 add r12, r2, #1024 */
/* @0x177784 add r12, r12, #12 */
/* @0x177788 vdiv.f32 s13, s13, s14 */
/* @0x17778c vcvt.f32.s32 s6, s6 */
/* @0x177790 vstr s13, [r2, #28] */
/* @0x177794 ldr r3, [r5, r3] */
/* @0x177798 vldr s13, [r3] */
/* @0x17779c ldrsh r3, [r1, #2] */
/* @0x1777a0 ldrsh r5, [r1, #14] */
/* @0x1777a4 vstr s12, [r2, #56] */
/* @0x1777a8 str r4, [r2, #0x48] */
/* @0x1777ac vstr s12, [r2, #92] */
/* @0x1777b0 vmov s8, r3 */
/* @0x1777b4 ldrsh r3, [r1, #12] */
/* @0x1777b8 vmov s3, r5 */
/* @0x1777bc add r5, r2, #1024 */
/* @0x1777c0 vcvt.f32.s32 s1, s1 */
/* @0x1777c4 add r5, r5, #4 */
/* @0x1777c8 vmov s5, r3 */
/* @0x1777cc str r10, [r2, #0x24] */
/* @0x1777d0 vstr s18, [r2, #40] */
/* @0x1777d4 str r9, [r2, #0x2c] */
/* @0x1777d8 vstr s15, [r2, #48] */
/* @0x1777dc vstr s15, [r2, #52] */
/* @0x1777e0 str r0, [r2, #0x3c] */
/* @0x1777e4 vstr s18, [r2, #76] */
/* @0x1777e8 str r9, [r2, #0x50] */
/* @0x1777ec vstr s15, [r2, #84] */
/* @0x1777f0 vstr s15, [r2, #88] */
/* @0x1777f4 str r0, [r2, #0x60] */
/* @0x1777f8 vcvt.f32.s32 s4, s4 */
/* @0x1777fc add r3, r2, #1040 */
/* @0x177800 add r3, r3, #4 */
/* @0x177804 vcvt.f32.s32 s9, s9 */
/* @0x177808 vmov.f32 s7, s6 */
/* @0x17780c vmla.f32 s9, s4, s15 */
/* @0x177810 vmla.f32 s6, s1, s15 */
/* @0x177814 vmla.f32 s7, s17, s1 */
/* @0x177818 vcvt.f32.s32 s3, s3 */
/* @0x17781c vcvt.f32.s32 s5, s5 */
/* @0x177820 vcvt.f32.s32 s8, s8 */
/* @0x177824 vcvt.f32.s32 s10, s10 */
/* @0x177828 vmla.f32 s8, s17, s3 */
/* @0x17782c vmla.f32 s10, s16, s5 */
/* @0x177830 vdiv.f32 s6, s6, s13 */
/* @0x177834 vdiv.f32 s7, s7, s13 */
/* @0x177838 vstr s6, [r2, #32] */
/* @0x17783c vdiv.f32 s9, s9, s14 */
/* @0x177840 vstr s7, [r2, #68] */
/* @0x177844 vdiv.f32 s8, s8, s13 */
/* @0x177848 vstr s9, [r2, #64] */
/* @0x17784c str r5, [sp, #0x8] */
/* @0x177850 add r5, r2, #1040 */
/* @0x177854 add r5, r5, #8 */
/* @0x177858 str r5, [sp, #0x14] */
/* @0x17785c add r5, r2, #1056 */
/* @0x177860 str r3, [sp, #0x10] */
/* @0x177864 add r5, r5, #8 */
/* @0x177868 str r5, [sp, #0x20] */
/* @0x17786c add r5, r2, #1056 */
/* @0x177870 add r3, r2, #1056 */
/* @0x177874 str r5, [sp, #0x74] */
/* @0x177878 add r5, r5, #24 */
/* @0x17787c str r5, [sp, #0x28] */
/* @0x177880 add r5, r2, #1088 */
/* @0x177884 str r12, [sp, #0xc] */
/* @0x177888 add r3, r3, #4 */
/* @0x17788c add r5, r5, #8 */
/* @0x177890 str r3, [sp, #0x1c] */
/* @0x177894 str r5, [sp, #0x34] */
/* @0x177898 add r3, r2, #1040 */
/* @0x17789c ldrsh r5, [r1, #2] */
/* @0x1778a0 add r12, r2, #1040 */
/* @0x1778a4 add r12, r12, #12 */
/* @0x1778a8 str r3, [sp, #0x70] */
/* @0x1778ac str r12, [sp, #0x18] */
/* @0x1778b0 add r3, r3, #36 */
/* @0x1778b4 add r12, r2, #1024 */
/* @0x1778b8 str r3, [sp, #0x24] */
/* @0x1778bc str r12, [sp, #0x6c] */
/* @0x1778c0 add r3, r2, #1088 */
/* @0x1778c4 add r12, r2, #1072 */
/* @0x1778c8 add r3, r3, #4 */
/* @0x1778cc str r12, [sp, #0x78] */
/* @0x1778d0 add r12, r12, #12 */
/* @0x1778d4 str r3, [sp, #0x30] */
/* @0x1778d8 add r3, r2, #1104 */
/* @0x1778dc str r12, [sp, #0x2c] */
/* @0x1778e0 add r12, r2, #1104 */
/* @0x1778e4 add r12, r12, #4 */
/* @0x1778e8 add r3, r3, #8 */
/* @0x1778ec str r12, [sp, #0x4] */
/* @0x1778f0 vmov s6, r5 */
/* @0x1778f4 ldrsh r12, [r1, #14] */
/* @0x1778f8 vstr s18, [r2, #112] */
/* @0x1778fc ldrsh r5, [r1, #12] */
/* @0x177900 str r3, [sp] */
/* @0x177904 ldrsh r3, [r1] */
/* @0x177908 vmov s1, r12 */
/* @0x17790c str r4, [r2, #0x6c] */
/* @0x177910 vmov s3, r5 */
/* @0x177914 ldrsh r12, [r1, #2] */
/* @0x177918 vstr s15, [r2, #120] */
/* @0x17791c str r9, [r2, #0x74] */
/* @0x177920 vmov s7, r12 */
/* @0x177924 vdiv.f32 s10, s10, s14 */
/* @0x177928 vstr s8, [r2, #104] */
/* @0x17792c vmov s8, r3 */
/* @0x177930 ldrsh r3, [r1, #14] */
/* @0x177934 vstr s12, [r2, #128] */
/* @0x177938 str r4, [r2, #0x90] */
/* @0x17793c vstr s15, [r2, #124] */
/* @0x177940 str r0, [r2, #0x84] */
/* @0x177944 vmov s2, r3 */
/* @0x177948 vstr s10, [r2, #100] */
/* @0x17794c str r11, [r2, #0x94] */
/* @0x177950 ldrsh r5, [r1] */
/* @0x177954 vcvt.f32.s32 s1, s1 */
/* @0x177958 ldrsh r12, [r1, #12] */
/* @0x17795c vstr s12, [r2, #164] */
/* @0x177960 ldrsh r3, [r1] */
/* @0x177964 vstr s12, [r2, #200] */
/* @0x177968 vmov s9, r5 */
/* @0x17796c ldrsh r5, [r1, #12] */
/* @0x177970 vmov s4, r12 */
/* @0x177974 add r12, r2, #1136 */
/* @0x177978 vmov s10, r3 */
/* @0x17797c add r3, r2, #1136 */
/* @0x177980 vmov s5, r5 */
/* @0x177984 add r12, r12, #8 */
/* @0x177988 vcvt.f32.s32 s6, s6 */
/* @0x17798c str r12, [sp, #0x44] */
/* @0x177990 add r3, r3, #12 */
/* @0x177994 add r12, r2, #1152 */
/* @0x177998 str r3, [sp, #0x48] */
/* @0x17799c add r3, r2, #1152 */
/* @0x1779a0 add r12, r12, #4 */
/* @0x1779a4 add r3, r3, #8 */
/* @0x1779a8 str r12, [sp, #0x4c] */
/* @0x1779ac vstr s15, [r2, #156] */
/* @0x1779b0 ldrsh r12, [r1, #2] */
/* @0x1779b4 vstr s15, [r2, #160] */
/* @0x1779b8 str r3, [sp, #0x50] */
/* @0x1779bc vstr s15, [r2, #192] */
/* @0x1779c0 vcvt.f32.s32 s2, s2 */
/* @0x1779c4 ldrsh r3, [r1, #14] */
/* @0x1779c8 str r9, [r2, #0x98] */
/* @0x1779cc vstr s15, [r2, #196] */
/* @0x1779d0 str r0, [r2, #0xa8] */
/* @0x1779d4 add r5, r2, #1104 */
/* @0x1779d8 str r10, [r2, #0xb4] */
/* @0x1779dc str r11, [r2, #0xb8] */
/* @0x1779e0 str r9, [r2, #0xbc] */
/* @0x1779e4 str r0, [r2, #0xcc] */
/* @0x1779e8 vcvt.f32.s32 s7, s7 */
/* @0x1779ec str r10, [r2, #0xd8] */
/* @0x1779f0 vcvt.f32.s32 s3, s3 */
/* @0x1779f4 vcvt.f32.s32 s4, s4 */
/* @0x1779f8 vcvt.f32.s32 s5, s5 */
/* @0x1779fc vcvt.f32.s32 s8, s8 */
/* @0x177a00 vcvt.f32.s32 s9, s9 */
/* @0x177a04 vcvt.f32.s32 s10, s10 */
/* @0x177a08 vmla.f32 s6, s17, s1 */
/* @0x177a0c vmov s1, r3 */
/* @0x177a10 ldrsh r3, [r1, #14] */
/* @0x177a14 vmla.f32 s7, s2, s15 */
/* @0x177a18 vmov s2, r3 */
/* @0x177a1c ldrsh r3, [r1, #12] */
/* @0x177a20 vmla.f32 s8, s16, s3 */
/* @0x177a24 vmla.f32 s9, s16, s4 */
/* @0x177a28 vmov s4, r3 */
/* @0x177a2c vmla.f32 s10, s5, s15 */
/* @0x177a30 vdiv.f32 s6, s6, s13 */
/* @0x177a34 vdiv.f32 s7, s7, s13 */
/* @0x177a38 vstr s6, [r2, #140] */
/* @0x177a3c vmov s6, r12 */
/* @0x177a40 ldrsh r12, [r1, #2] */
/* @0x177a44 str r11, [r2, #0xdc] */
/* @0x177a48 vdiv.f32 s8, s8, s14 */
/* @0x177a4c vstr s7, [r2, #176] */
/* @0x177a50 vmov s7, r12 */
/* @0x177a54 ldrsh r12, [r1] */
/* @0x177a58 vstr s19, [r2, #224] */
/* @0x177a5c vdiv.f32 s9, s9, s14 */
/* @0x177a60 vstr s8, [r2, #136] */
/* @0x177a64 vdiv.f32 s10, s10, s14 */
/* @0x177a68 vstr s9, [r2, #172] */
/* @0x177a6c vmov s9, r12 */
/* @0x177a70 vstr s10, [r2, #208] */
/* @0x177a74 vstr s15, [r2, #228] */
/* @0x177a78 ldrsh r12, [r1, #2] */
/* @0x177a7c vcvt.f32.s32 s1, s1 */
/* @0x177a80 ldrsh r3, [r1, #14] */
/* @0x177a84 vstr s11, [r2, #236] */
/* @0x177a88 str r4, [r2, #0xfc] */
/* @0x177a8c vstr s11, [r2, #272] */
/* @0x177a90 vmov s8, r12 */
/* @0x177a94 ldrsh r12, [r1] */
/* @0x177a98 vmov s3, r3 */

/* ── 跳过 literal pool 的 b + 池（0x177aa0..0x177ac0，9 字）──
 *   0x177aa0 = 0x00000000 → s15 = 0.0f（UV 系数 0 / 法线分量 0）
 *   0x177aa4 = 0x0027a5d8 → 加到 pc 得 GOT 基址 0x3F1C58
 *   0x177aa8 = 0xffffe670 → GOT 槽 0x3F02C8（顶点缓冲对象）
 *   0x177aac = 0xffffe684 → GOT 槽 0x3F02DC（当前顶点指针槽）
 *   0x177ab0 = 0xffffe680 → GOT 槽 0x3F02D8（顶点数组首址）
 *   0x177ab4 = 0xffffc0ac → GOT 槽 0x3EDD04（颜色字）
 *   0x177ab8 = 0xffffe540 → GOT 槽 0x3F0198（当前精灵槽）
 *   0x177abc = 0xffffe544 → GOT 槽 0x3F019C（纹理宽）
 *   0x177ac0 = 0xffffe548 → GOT 槽 0x3F01A0（纹理高）
 */
/* @0x177a9c b 0x177ac4 <_Z16GR_3D_Draw_Blockffffffiff+0x488> */
/* @0x177aa0 andeq r0, r0, r0 */
/* @0x177aa4 .word 0x0027a5d8 */
/* @0x177aa8 .word 0xffffe670 */
/* @0x177aac .word 0xffffe684 */
/* @0x177ab0 .word 0xffffe680 */
/* @0x177ab4 .word 0xffffc0ac */
/* @0x177ab8 .word 0xffffe540 */
/* @0x177abc .word 0xffffe544 */
/* @0x177ac0 .word 0xffffe548 */

/* ── 纹理路径续：顶点 12..27 前半 ──
 *   与前面同构：每顶点 9 字，x ∈ {r10,r4}、y ∈ {r11,s18}、z ∈ {r9,s19}，法线按面切换分量
 *   从写入模式看，36 个顶点是按「6 个面 × 6 个顶点」排的：
 *     0..5 法线 (0,0,-1)、6..11 (0,0,+1)、12..17 (0,+1,0)、18..23 (+1,0,0)、24..29 (0,-1,0)、30..35 (-1,0,0)
 *   （前五组的实测见 0x1777d8..0x177acc 与 0x178b04..0x178b18 两处同型写入；第六组见 open 第 1 条）
 */
/* @0x177ac4 ldrsh r3, [r1, #12] */
/* @0x177ac8 str lr, [sp, #0x7c] */
/* @0x177acc vstr s15, [r2, #232] */
/* @0x177ad0 vmov s10, r12 */
/* @0x177ad4 add r12, r2, #1152 */
/* @0x177ad8 vmov s5, r3 */
/* @0x177adc add r12, r12, #12 */
/* @0x177ae0 vcvt.f32.s32 s2, s2 */
/* @0x177ae4 str r12, [sp, #0x54] */
/* @0x177ae8 add r3, r2, #1136 */
/* @0x177aec add r12, r2, #1152 */
/* @0x177af0 str r3, [sp, #0x84] */
/* @0x177af4 vstr s19, [r2, #260] */
/* @0x177af8 ldrsh r3, [r1, #2] */
/* @0x177afc vstr s15, [r2, #264] */
/* @0x177b00 str r12, [sp, #0x88] */
/* @0x177b04 vstr s11, [r2, #308] */
/* @0x177b08 ldrsh r12, [r1, #14] */
/* @0x177b0c vstr s15, [r2, #268] */
/* @0x177b10 str r4, [r2, #0x120] */
/* @0x177b14 vstr s18, [r2, #292] */
/* @0x177b18 vcvt.f32.s32 s3, s3 */
/* @0x177b1c str r6, [sp, #0x80] */
/* @0x177b20 vmov s20, r12 */
/* @0x177b24 ldrsh r12, [r1, #12] */
/* @0x177b28 str r0, [r2, #0xf0] */
/* @0x177b2c vstr s19, [r2, #296] */
/* @0x177b30 str r11, [r2, #0x100] */
/* @0x177b34 vstr s15, [r2, #300] */
/* @0x177b38 str r0, [r2, #0x114] */
/* @0x177b3c vstr s15, [r2, #304] */
/* @0x177b40 vcvt.f32.s32 s4, s4 */
/* @0x177b44 vcvt.f32.s32 s5, s5 */
/* @0x177b48 vcvt.f32.s32 s6, s6 */
/* @0x177b4c vcvt.f32.s32 s7, s7 */
/* @0x177b50 vcvt.f32.s32 s8, s8 */
/* @0x177b54 vcvt.f32.s32 s9, s9 */
/* @0x177b58 vcvt.f32.s32 s10, s10 */
/* @0x177b5c vmla.f32 s6, s1, s15 */
/* @0x177b60 vmla.f32 s7, s2, s15 */
/* @0x177b64 vmov s2, r12 */
/* @0x177b68 vmla.f32 s8, s3, s15 */
/* @0x177b6c vmla.f32 s9, s4, s15 */
/* @0x177b70 vmla.f32 s10, s16, s5 */
/* @0x177b74 vmov s5, r3 */
/* @0x177b78 ldrsh r3, [r1] */
/* @0x177b7c vdiv.f32 s6, s6, s13 */
/* @0x177b80 vdiv.f32 s7, s7, s13 */
/* @0x177b84 vstr s6, [r2, #212] */
/* @0x177b88 vdiv.f32 s8, s8, s13 */
/* @0x177b8c vstr s7, [r2, #248] */
/* @0x177b90 vdiv.f32 s9, s9, s14 */
/* @0x177b94 vstr s8, [r2, #284] */
/* @0x177b98 vmov s8, r3 */
/* @0x177b9c ldrsh r3, [r1, #2] */
/* @0x177ba0 vmov s6, r3 */
/* @0x177ba4 vdiv.f32 s10, s10, s14 */
/* @0x177ba8 vstr s9, [r2, #244] */
/* @0x177bac vstr s10, [r2, #280] */
/* @0x177bb0 vstr s11, [r2, #344] */
/* @0x177bb4 ldrsh r12, [r1, #14] */
/* @0x177bb8 vcvt.f32.s32 s20, s20 */
/* @0x177bbc ldrsh r3, [r1] */
/* @0x177bc0 vstr s18, [r2, #328] */
/* @0x177bc4 str r4, [r2, #0x144] */
/* @0x177bc8 vstr s19, [r2, #332] */
/* @0x177bcc vmov s0, r12 */
/* @0x177bd0 ldrsh r12, [r1, #12] */
/* @0x177bd4 vmov s9, r3 */
/* @0x177bd8 ldrsh r3, [r1, #2] */
/* @0x177bdc vstr s11, [r2, #380] */
/* @0x177be0 str r0, [r2, #0x138] */
/* @0x177be4 vmov s3, r12 */
/* @0x177be8 ldrsh r12, [r1, #14] */
/* @0x177bec vmov s7, r3 */
/* @0x177bf0 ldrsh r3, [r1] */
/* @0x177bf4 vcvt.f32.s32 s0, s0 */
/* @0x177bf8 vstr s15, [r2, #336] */
/* @0x177bfc vmov s1, r12 */
/* @0x177c00 ldrsh r12, [r1, #12] */
/* @0x177c04 vmov s10, r3 */
/* @0x177c08 add r3, r2, #1168 */
/* @0x177c0c str r3, [sp, #0x8c] */
/* @0x177c10 vstr s15, [r2, #340] */
/* @0x177c14 vmov s4, r12 */
/* @0x177c18 add r12, r3, #4 */
/* @0x177c1c ldrsh r3, [r1, #2] */
/* @0x177c20 vstr s18, [r2, #364] */
/* @0x177c24 str r12, [sp, #0x58] */
/* @0x177c28 vstr s11, [r2, #416] */
/* @0x177c2c vcvt.f32.s32 s1, s1 */
/* @0x177c30 ldrsh r12, [r1, #14] */
/* @0x177c34 str r0, [r2, #0x15c] */
/* @0x177c38 vstr s19, [r2, #368] */
/* @0x177c3c str r10, [r2, #0x168] */
/* @0x177c40 vstr s15, [r2, #372] */
/* @0x177c44 vstr s15, [r2, #376] */
/* @0x177c48 str r0, [r2, #0x180] */
/* @0x177c4c str r10, [r2, #0x18c] */
/* @0x177c50 vcvt.f32.s32 s2, s2 */
/* @0x177c54 vcvt.f32.s32 s3, s3 */
/* @0x177c58 vcvt.f32.s32 s4, s4 */
/* @0x177c5c vcvt.f32.s32 s5, s5 */
/* @0x177c60 vcvt.f32.s32 s6, s6 */
/* @0x177c64 vcvt.f32.s32 s8, s8 */
/* @0x177c68 vcvt.f32.s32 s7, s7 */
/* @0x177c6c vcvt.f32.s32 s9, s9 */
/* @0x177c70 vcvt.f32.s32 s10, s10 */
/* @0x177c74 vmla.f32 s5, s17, s20 */
/* @0x177c78 vmla.f32 s6, s17, s0 */
/* @0x177c7c vmla.f32 s7, s17, s1 */
/* @0x177c80 vmov s1, r12 */
/* @0x177c84 vmla.f32 s8, s16, s2 */
/* @0x177c88 vmla.f32 s9, s16, s3 */
/* @0x177c8c vmla.f32 s10, s4, s15 */
/* @0x177c90 vdiv.f32 s5, s5, s13 */
/* @0x177c94 vdiv.f32 s6, s6, s13 */
/* @0x177c98 vstr s5, [r2, #320] */
/* @0x177c9c vdiv.f32 s7, s7, s13 */
/* @0x177ca0 vstr s6, [r2, #356] */
/* @0x177ca4 vmov s6, r3 */
/* @0x177ca8 ldrsh r3, [r1] */
/* @0x177cac vdiv.f32 s8, s8, s14 */
/* @0x177cb0 vstr s7, [r2, #392] */
/* @0x177cb4 vdiv.f32 s9, s9, s14 */
/* @0x177cb8 vstr s8, [r2, #316] */
/* @0x177cbc vmov s8, r3 */
/* @0x177cc0 vdiv.f32 s10, s10, s14 */
/* @0x177cc4 vstr s9, [r2, #352] */
/* @0x177cc8 vstr s10, [r2, #388] */
/* @0x177ccc str r11, [r2, #0x190] */
/* @0x177cd0 ldrsh r12, [r1, #12] */
/* @0x177cd4 vcvt.f32.s32 s1, s1 */
/* @0x177cd8 ldrsh r3, [r1, #2] */
/* @0x177cdc vstr s19, [r2, #404] */
/* @0x177ce0 vmov s3, r12 */
/* @0x177ce4 ldrsh r12, [r1, #14] */
/* @0x177ce8 vmov s7, r3 */
/* @0x177cec ldrsh r3, [r1] */
/* @0x177cf0 vstr s11, [r2, #448] */
/* @0x177cf4 vstr s15, [r2, #408] */
/* @0x177cf8 vmov s2, r12 */
/* @0x177cfc ldrsh r12, [r1, #12] */
/* @0x177d00 vmov s9, r3 */
/* @0x177d04 ldrsh r3, [r1] */
/* @0x177d08 vcvt.f32.s32 s2, s2 */
/* @0x177d0c vstr s11, [r2, #484] */
/* @0x177d10 vmov s4, r12 */
/* @0x177d14 ldrsh r12, [r1, #12] */
/* @0x177d18 vmov s10, r3 */
/* @0x177d1c add r3, r2, #1168 */
/* @0x177d20 add r3, r3, #12 */
/* @0x177d24 str r3, [sp, #0x5c] */
/* @0x177d28 vmov s5, r12 */
/* @0x177d2c ldrsh r3, [r1, #14] */
/* @0x177d30 ldrsh r12, [r1, #2] */
/* @0x177d34 vstr s15, [r2, #412] */
/* @0x177d38 str r0, [r2, #0x1a4] */
/* @0x177d3c vstr s18, [r2, #436] */

/* ── 纹理路径续：顶点 12..27 后半 ──
 *   这一段把「按面换轴」写全：同一批 s 寄存器被反复重装（ldrsh 子矩形 + vcvt.f32.s32 + vmla/vdiv），
 *   每个顶点的 u/v 都由 (left|top, 子矩形宽|高, 系数) 三步得出，写进该槽的 +0x1c/+0x20
 *   0x178304/0x178320 这类 vstr s6/s9 是槽 24 的 u/v；0x17830c/0x178328 是槽 25 的
 *   ⇒ 顶点 24..29 的面（法线 (0,-1,0)）u/v 也走同一模板
 */
/* @0x177d40 vcvt.f32.s32 s3, s3 */
/* @0x177d44 str r10, [r2, #0x1b0] */
/* @0x177d48 str r9, [r2, #0x1b8] */
/* @0x177d4c vstr s15, [r2, #444] */
/* @0x177d50 vstr s15, [r2, #452] */
/* @0x177d54 str r0, [r2, #0x1c8] */
/* @0x177d58 str r10, [r2, #0x1d4] */
/* @0x177d5c vstr s18, [r2, #472] */
/* @0x177d60 vstr s19, [r2, #476] */
/* @0x177d64 vstr s15, [r2, #480] */
/* @0x177d68 vstr s15, [r2, #488] */
/* @0x177d6c str r0, [r2, #0x1ec] */
/* @0x177d70 vcvt.f32.s32 s4, s4 */
/* @0x177d74 vcvt.f32.s32 s5, s5 */
/* @0x177d78 vcvt.f32.s32 s6, s6 */
/* @0x177d7c vcvt.f32.s32 s7, s7 */
/* @0x177d80 vcvt.f32.s32 s8, s8 */
/* @0x177d84 vcvt.f32.s32 s9, s9 */
/* @0x177d88 vcvt.f32.s32 s10, s10 */
/* @0x177d8c vmla.f32 s6, s1, s15 */
/* @0x177d90 vmov s1, r3 */
/* @0x177d94 vmla.f32 s7, s2, s15 */
/* @0x177d98 vmla.f32 s8, s3, s15 */
/* @0x177d9c vmla.f32 s9, s4, s15 */
/* @0x177da0 vmla.f32 s10, s5, s15 */
/* @0x177da4 vdiv.f32 s6, s6, s13 */
/* @0x177da8 vdiv.f32 s7, s7, s13 */
/* @0x177dac vstr s6, [r2, #428] */
/* @0x177db0 vmov s6, r12 */
/* @0x177db4 vdiv.f32 s8, s8, s14 */
/* @0x177db8 vstr s7, [r2, #464] */
/* @0x177dbc vdiv.f32 s9, s9, s14 */
/* @0x177dc0 vstr s8, [r2, #424] */
/* @0x177dc4 vdiv.f32 s10, s10, s14 */
/* @0x177dc8 vstr s9, [r2, #460] */
/* @0x177dcc vstr s10, [r2, #496] */
/* @0x177dd0 vstr s11, [r2, #520] */
/* @0x177dd4 ldrsh r12, [r1, #2] */
/* @0x177dd8 vcvt.f32.s32 s1, s1 */
/* @0x177ddc ldrsh r3, [r1, #14] */
/* @0x177de0 str r4, [r2, #0x1f8] */
/* @0x177de4 vmov s7, r12 */
/* @0x177de8 ldrsh r12, [r1] */
/* @0x177dec vmov s2, r3 */
/* @0x177df0 ldrsh r3, [r1, #12] */
/* @0x177df4 vstr s18, [r2, #508] */
/* @0x177df8 vstr s11, [r2, #556] */
/* @0x177dfc vmov s9, r12 */
/* @0x177e00 ldrsh r12, [r1, #2] */
/* @0x177e04 vmov s4, r3 */
/* @0x177e08 ldrsh r3, [r1, #14] */
/* @0x177e0c vcvt.f32.s32 s2, s2 */
/* @0x177e10 str r4, [r2, #0x21c] */
/* @0x177e14 vmov s8, r12 */
/* @0x177e18 ldrsh r12, [r1] */
/* @0x177e1c vmov s3, r3 */
/* @0x177e20 ldrsh r3, [r1, #12] */
/* @0x177e24 vstr s19, [r2, #512] */
/* @0x177e28 str r4, [r2, #0x240] */
/* @0x177e2c vmov s10, r12 */
/* @0x177e30 ldrsh r12, [r1, #2] */
/* @0x177e34 vmov s5, r3 */
/* @0x177e38 ldrsh r3, [r1, #14] */
/* @0x177e3c vstr s11, [r2, #592] */
/* @0x177e40 vstr s15, [r2, #516] */
/* @0x177e44 vcvt.f32.s32 s3, s3 */
/* @0x177e48 vstr s15, [r2, #524] */
/* @0x177e4c vmov s20, r3 */
/* @0x177e50 ldrsh r3, [r1, #12] */
/* @0x177e54 str r0, [r2, #0x210] */
/* @0x177e58 vstr s18, [r2, #544] */
/* @0x177e5c vstr s19, [r2, #548] */
/* @0x177e60 vstr s15, [r2, #552] */
/* @0x177e64 vstr s15, [r2, #560] */
/* @0x177e68 str r0, [r2, #0x234] */
/* @0x177e6c vstr s18, [r2, #580] */
/* @0x177e70 str r9, [r2, #0x248] */
/* @0x177e74 vstr s15, [r2, #588] */
/* @0x177e78 vstr s15, [r2, #596] */
/* @0x177e7c vcvt.f32.s32 s4, s4 */
/* @0x177e80 vcvt.f32.s32 s5, s5 */
/* @0x177e84 vcvt.f32.s32 s6, s6 */
/* @0x177e88 vcvt.f32.s32 s7, s7 */
/* @0x177e8c vcvt.f32.s32 s8, s8 */
/* @0x177e90 vcvt.f32.s32 s9, s9 */
/* @0x177e94 vcvt.f32.s32 s10, s10 */
/* @0x177e98 vmla.f32 s6, s17, s1 */
/* @0x177e9c vmla.f32 s7, s17, s2 */
/* @0x177ea0 vmov s2, r3 */
/* @0x177ea4 vmla.f32 s8, s17, s3 */
/* @0x177ea8 vmla.f32 s9, s16, s4 */
/* @0x177eac vmla.f32 s10, s16, s5 */
/* @0x177eb0 vmov s5, r12 */
/* @0x177eb4 ldrsh r12, [r1] */
/* @0x177eb8 vdiv.f32 s6, s6, s13 */
/* @0x177ebc vdiv.f32 s7, s7, s13 */
/* @0x177ec0 vstr s6, [r2, #500] */
/* @0x177ec4 vdiv.f32 s8, s8, s13 */
/* @0x177ec8 vstr s7, [r2, #536] */
/* @0x177ecc vdiv.f32 s9, s9, s14 */
/* @0x177ed0 vstr s8, [r2, #572] */
/* @0x177ed4 vmov s8, r12 */
/* @0x177ed8 ldrsh r12, [r1, #2] */
/* @0x177edc vmov s6, r12 */
/* @0x177ee0 vdiv.f32 s10, s10, s14 */
/* @0x177ee4 vstr s9, [r2, #532] */
/* @0x177ee8 vstr s10, [r2, #568] */
/* @0x177eec vstr s11, [r2, #628] */
/* @0x177ef0 ldrsh r3, [r1, #14] */
/* @0x177ef4 vcvt.f32.s32 s2, s2 */
/* @0x177ef8 ldrsh r12, [r1] */
/* @0x177efc vstr s18, [r2, #616] */
/* @0x177f00 str r10, [r2, #0x264] */
/* @0x177f04 vstr s15, [r2, #624] */
/* @0x177f08 vmov s0, r3 */
/* @0x177f0c ldrsh r3, [r1, #12] */
/* @0x177f10 vmov s9, r12 */
/* @0x177f14 ldrsh r12, [r1, #2] */
/* @0x177f18 vstr s11, [r2, #660] */
/* @0x177f1c str r4, [r2, #0x288] */
/* @0x177f20 vmov s3, r3 */
/* @0x177f24 ldrsh r3, [r1, #14] */
/* @0x177f28 vmov s7, r12 */
/* @0x177f2c ldrsh r12, [r1] */
/* @0x177f30 vcvt.f32.s32 s0, s0 */
/* @0x177f34 str r0, [r2, #0x258] */
/* @0x177f38 vmov s1, r3 */
/* @0x177f3c ldrsh r3, [r1, #12] */
/* @0x177f40 vmov s10, r12 */
/* @0x177f44 add r12, r2, #1184 */
/* @0x177f48 add r12, r12, #4 */
/* @0x177f4c str r12, [sp, #0x60] */
/* @0x177f50 vmov s4, r3 */
/* @0x177f54 ldrsh r12, [r1, #14] */
/* @0x177f58 ldrsh r3, [r1, #2] */
/* @0x177f5c vstr s15, [r2, #632] */
/* @0x177f60 vstr s11, [r2, #696] */
/* @0x177f64 str r4, [r2, #0x2ac] */
/* @0x177f68 vcvt.f32.s32 s1, s1 */
/* @0x177f6c str r9, [r2, #0x26c] */
/* @0x177f70 str r0, [r2, #0x27c] */
/* @0x177f74 vstr s18, [r2, #652] */
/* @0x177f78 str r9, [r2, #0x290] */
/* @0x177f7c vstr s15, [r2, #664] */
/* @0x177f80 vstr s15, [r2, #668] */
/* @0x177f84 str r0, [r2, #0x2a0] */
/* @0x177f88 vcvt.f32.s32 s3, s3 */
/* @0x177f8c vcvt.f32.s32 s4, s4 */
/* @0x177f90 vcvt.f32.s32 s5, s5 */
/* @0x177f94 vcvt.f32.s32 s20, s20 */
/* @0x177f98 vcvt.f32.s32 s6, s6 */
/* @0x177f9c vcvt.f32.s32 s8, s8 */
/* @0x177fa0 vcvt.f32.s32 s7, s7 */
/* @0x177fa4 vcvt.f32.s32 s9, s9 */
/* @0x177fa8 vcvt.f32.s32 s10, s10 */
/* @0x177fac vmla.f32 s6, s0, s15 */
/* @0x177fb0 vmla.f32 s7, s1, s15 */
/* @0x177fb4 vmov s1, r12 */
/* @0x177fb8 vmla.f32 s8, s16, s2 */
/* @0x177fbc vmla.f32 s9, s3, s15 */
/* @0x177fc0 vmla.f32 s10, s4, s15 */
/* @0x177fc4 vmla.f32 s5, s20, s15 */
/* @0x177fc8 vdiv.f32 s6, s6, s13 */
/* @0x177fcc vdiv.f32 s5, s5, s13 */
/* @0x177fd0 vstr s6, [r2, #644] */
/* @0x177fd4 vmov s6, r3 */
/* @0x177fd8 ldrsh r3, [r1] */
/* @0x177fdc vdiv.f32 s7, s7, s13 */
/* @0x177fe0 vstr s5, [r2, #608] */
/* @0x177fe4 vdiv.f32 s8, s8, s14 */
/* @0x177fe8 vstr s7, [r2, #680] */
/* @0x177fec vdiv.f32 s9, s9, s14 */
/* @0x177ff0 vstr s8, [r2, #604] */
/* @0x177ff4 vmov s8, r3 */
/* @0x177ff8 vdiv.f32 s10, s10, s14 */
/* @0x177ffc vstr s9, [r2, #640] */
/* @0x178000 vstr s10, [r2, #676] */
/* @0x178004 vstr s18, [r2, #688] */
/* @0x178008 ldrsh r12, [r1, #12] */
/* @0x17800c vcvt.f32.s32 s1, s1 */
/* @0x178010 ldrsh r3, [r1, #2] */
/* @0x178014 vstr s11, [r2, #732] */
/* @0x178018 str r4, [r2, #0x2d0] */
/* @0x17801c vstr s19, [r2, #692] */
/* @0x178020 vmov s3, r12 */
/* @0x178024 ldrsh r12, [r1, #14] */
/* @0x178028 vmov s7, r3 */
/* @0x17802c ldrsh r3, [r1] */
/* @0x178030 vstr s15, [r2, #700] */
/* @0x178034 vstr s15, [r2, #704] */
/* @0x178038 vmov s2, r12 */
/* @0x17803c ldrsh r12, [r1, #12] */
/* @0x178040 vmov s9, r3 */
/* @0x178044 ldrsh r3, [r1] */
/* @0x178048 vcvt.f32.s32 s2, s2 */
/* @0x17804c vstr s11, [r2, #768] */
/* @0x178050 vmov s4, r12 */
/* @0x178054 ldrsh r12, [r1, #12] */
/* @0x178058 vmov s10, r3 */
/* @0x17805c ldrsh r3, [r1, #2] */
/* @0x178060 str r4, [r2, #0x2f4] */
/* @0x178064 vstr s19, [r2, #728] */
/* @0x178068 vmov s5, r12 */
/* @0x17806c ldrsh r12, [r1, #14] */
/* @0x178070 str r0, [r2, #0x2c4] */
/* @0x178074 vstr s11, [r2, #804] */
/* @0x178078 str r11, [r2, #0x2d4] */
/* @0x17807c vstr s15, [r2, #736] */
/* @0x178080 vcvt.f32.s32 s3, s3 */
/* @0x178084 vstr s15, [r2, #740] */
/* @0x178088 str r0, [r2, #0x2e8] */
/* @0x17808c vstr s19, [r2, #764] */
/* @0x178090 str r11, [r2, #0x2f8] */
/* @0x178094 vstr s15, [r2, #772] */
/* @0x178098 vstr s15, [r2, #776] */
/* @0x17809c str r0, [r2, #0x30c] */
/* @0x1780a0 vcvt.f32.s32 s4, s4 */
/* @0x1780a4 vcvt.f32.s32 s5, s5 */
/* @0x1780a8 vcvt.f32.s32 s6, s6 */
/* @0x1780ac vcvt.f32.s32 s7, s7 */
/* @0x1780b0 vcvt.f32.s32 s8, s8 */
/* @0x1780b4 vcvt.f32.s32 s9, s9 */
/* @0x1780b8 vcvt.f32.s32 s10, s10 */
/* @0x1780bc vmla.f32 s6, s17, s1 */
/* @0x1780c0 vmla.f32 s7, s17, s2 */
/* @0x1780c4 vmov s2, r12 */
/* @0x1780c8 vmla.f32 s8, s3, s15 */
/* @0x1780cc vmla.f32 s9, s16, s4 */
/* @0x1780d0 vmla.f32 s10, s16, s5 */
/* @0x1780d4 vdiv.f32 s6, s6, s13 */
/* @0x1780d8 vdiv.f32 s7, s7, s13 */
/* @0x1780dc vstr s6, [r2, #716] */
/* @0x1780e0 vdiv.f32 s8, s8, s14 */
/* @0x1780e4 vstr s7, [r2, #752] */
/* @0x1780e8 vmov s7, r3 */
/* @0x1780ec ldrsh r3, [r1] */
/* @0x1780f0 vdiv.f32 s9, s9, s14 */
/* @0x1780f4 vstr s8, [r2, #712] */
/* @0x1780f8 vdiv.f32 s10, s10, s14 */
/* @0x1780fc vstr s9, [r2, #748] */
/* @0x178100 vstr s10, [r2, #784] */
/* @0x178104 str r4, [r2, #0x318] */
/* @0x178108 ldrsh r12, [r1, #12] */
/* @0x17810c vmov s10, r3 */
/* @0x178110 ldrsh r3, [r1, #2] */
/* @0x178114 vcvt.f32.s32 s2, s2 */
/* @0x178118 str r11, [r2, #0x31c] */
/* @0x17811c vstr s15, [r2, #808] */
/* @0x178120 vmov s5, r12 */
/* @0x178124 ldrsh r12, [r1, #14] */
/* @0x178128 vmov s8, r3 */
/* @0x17812c ldrsh r3, [r1, #2] */
/* @0x178130 vstr s11, [r2, #840] */
/* @0x178134 str r4, [r2, #0x33c] */
/* @0x178138 vmov s3, r12 */
/* @0x17813c ldrsh r12, [r1, #14] */
/* @0x178140 vmov s9, r3 */
/* @0x178144 ldrsh r3, [r1] */
/* @0x178148 vcvt.f32.s32 s3, s3 */
/* @0x17814c str r9, [r2, #0x320] */
/* @0x178150 vmov s4, r12 */
/* @0x178154 ldrsh r12, [r1, #12] */
/* @0x178158 vmov s11, r3 */
/* @0x17815c ldrsh r3, [r1, #2] */
/* @0x178160 str r4, [r2, #0x360] */
/* @0x178164 vstr s12, [r2, #880] */
/* @0x178168 vmov s6, r12 */
/* @0x17816c ldrsh r12, [r1, #14] */
/* @0x178170 vstr s15, [r2, #812] */
/* @0x178174 str r0, [r2, #0x330] */
/* @0x178178 vstr s18, [r2, #832] */
/* @0x17817c str r9, [r2, #0x344] */
/* @0x178180 vcvt.f32.s32 s4, s4 */
/* @0x178184 vstr s15, [r2, #844] */
/* @0x178188 vmov s0, r12 */
/* @0x17818c ldrsh r12, [r1, #12] */
/* @0x178190 vstr s15, [r2, #848] */
/* @0x178194 str r0, [r2, #0x354] */
/* @0x178198 str r11, [r2, #0x364] */
/* @0x17819c vstr s15, [r2, #876] */
/* @0x1781a0 str r9, [r2, #0x368] */
/* @0x1781a4 vstr s15, [r2, #884] */
/* @0x1781a8 vcvt.f32.s32 s5, s5 */
/* @0x1781ac vcvt.f32.s32 s6, s6 */
/* @0x1781b0 vcvt.f32.s32 s7, s7 */
/* @0x1781b4 vcvt.f32.s32 s8, s8 */
/* @0x1781b8 vcvt.f32.s32 s9, s9 */
/* @0x1781bc vcvt.f32.s32 s10, s10 */
/* @0x1781c0 vcvt.f32.s32 s11, s11 */
/* @0x1781c4 vmla.f32 s7, s17, s2 */
/* @0x1781c8 vmla.f32 s8, s3, s15 */
/* @0x1781cc vmov s3, r12 */
/* @0x1781d0 vmla.f32 s9, s4, s15 */
/* @0x1781d4 vmla.f32 s10, s16, s5 */
/* @0x1781d8 vmla.f32 s11, s6, s15 */
/* @0x1781dc vmov s6, r3 */
/* @0x1781e0 ldrsh r3, [r1] */
/* @0x1781e4 vdiv.f32 s7, s7, s13 */
/* @0x1781e8 vdiv.f32 s8, s8, s13 */
/* @0x1781ec vstr s7, [r2, #788] */
/* @0x1781f0 vdiv.f32 s9, s9, s13 */
/* @0x1781f4 vstr s8, [r2, #824] */
/* @0x1781f8 vdiv.f32 s10, s10, s14 */
/* @0x1781fc vstr s9, [r2, #860] */
/* @0x178200 vmov s9, r3 */
/* @0x178204 ldrsh r3, [r1, #2] */
/* @0x178208 vmov s7, r3 */
/* @0x17820c vdiv.f32 s11, s11, s14 */
/* @0x178210 vstr s10, [r2, #820] */
/* @0x178214 vstr s11, [r2, #856] */
/* @0x178218 str r4, [r2, #0x384] */
/* @0x17821c ldrsh r12, [r1, #14] */
/* @0x178220 vcvt.f32.s32 s6, s6 */
/* @0x178224 ldr r3, [sp, #0x38] */
/* @0x178228 vstr s12, [r2, #916] */
/* @0x17822c str r11, [r2, #0x388] */
/* @0x178230 vstr s19, [r2, #908] */
/* @0x178234 vmov s1, r12 */
/* @0x178238 ldr r12, [sp, #0x40] */
/* @0x17823c str r0, [r2, #0x378] */
/* @0x178240 vstr s15, [r2, #912] */
/* @0x178244 vstr s15, [r2, #920] */
/* @0x178248 str r0, [r2, #0x39c] */
/* @0x17824c str r3, [r12] */
/* @0x178250 ldrsh r3, [r1] */
/* @0x178254 vcvt.f32.s32 s0, s0 */
/* @0x178258 ldrsh r12, [r1, #12] */
/* @0x17825c vstr s12, [r2, #952] */
/* @0x178260 str r10, [r2, #0x3a8] */
/* @0x178264 vstr s19, [r2, #944] */
/* @0x178268 vmov s10, r3 */
/* @0x17826c ldrsh r3, [r1, #2] */
/* @0x178270 vmov s4, r12 */
/* @0x178274 ldrsh r12, [r1, #14] */
/* @0x178278 str r11, [r2, #0x3ac] */
/* @0x17827c vstr s15, [r2, #948] */
/* @0x178280 vmov s8, r3 */
/* @0x178284 ldrsh r3, [r1] */
/* @0x178288 vmov s2, r12 */
/* @0x17828c ldrsh r12, [r1, #12] */
/* @0x178290 vcvt.f32.s32 s4, s4 */
/* @0x178294 vstr s15, [r2, #956] */
/* @0x178298 vmov s11, r3 */
/* @0x17829c add r3, r2, #1184 */
/* @0x1782a0 vmov s5, r12 */
/* @0x1782a4 add r12, r2, #1184 */
/* @0x1782a8 add r3, r3, #8 */
/* @0x1782ac add r12, r12, #12 */
/* @0x1782b0 str r3, [sp, #0x38] */
/* @0x1782b4 str r12, [sp, #0x64] */
/* @0x1782b8 ldrsh r3, [r1, #2] */
/* @0x1782bc vcvt.f32.s32 s5, s5 */
/* @0x1782c0 str r0, [r2, #0x3c0] */
/* @0x1782c4 vcvt.f32.s32 s7, s7 */
/* @0x1782c8 vcvt.f32.s32 s1, s1 */
/* @0x1782cc vcvt.f32.s32 s9, s9 */
/* @0x1782d0 vcvt.f32.s32 s8, s8 */
/* @0x1782d4 vcvt.f32.s32 s3, s3 */
/* @0x1782d8 vcvt.f32.s32 s2, s2 */
/* @0x1782dc vcvt.f32.s32 s10, s10 */
/* @0x1782e0 vcvt.f32.s32 s11, s11 */
/* @0x1782e4 vmla.f32 s10, s4, s15 */
/* @0x1782e8 vmla.f32 s11, s16, s5 */
/* @0x1782ec vmla.f32 s6, s0, s15 */
/* @0x1782f0 vmla.f32 s7, s17, s1 */
/* @0x1782f4 vmla.f32 s8, s17, s2 */
/* @0x1782f8 vmla.f32 s9, s3, s15 */
/* @0x1782fc vdiv.f32 s6, s6, s13 */
/* @0x178300 vdiv.f32 s7, s7, s13 */
/* @0x178304 vstr s6, [r2, #896] */
/* @0x178308 vdiv.f32 s8, s8, s13 */
/* @0x17830c vstr s7, [r2, #932] */
/* @0x178310 vmov s7, r3 */
/* @0x178314 vdiv.f32 s9, s9, s14 */
/* @0x178318 vstr s8, [r2, #968] */
/* @0x17831c vdiv.f32 s10, s10, s14 */
/* @0x178320 vstr s9, [r2, #892] */
/* @0x178324 vdiv.f32 s11, s11, s14 */
/* @0x178328 vstr s10, [r2, #928] */
/* @0x17832c vstr s11, [r2, #964] */
/* @0x178330 str r10, [r2, #0x3cc] */
/* @0x178334 ldrsh r12, [r1, #14] */
/* @0x178338 vcvt.f32.s32 s7, s7 */
/* @0x17833c ldrsh r3, [r1] */
/* @0x178340 vstr s19, [r2, #980] */
/* @0x178344 vstr s12, [r2, #988] */
/* @0x178348 str r11, [r2, #0x3d0] */
/* @0x17834c vmov s4, r12 */
/* @0x178350 ldrsh r12, [r1, #12] */
/* @0x178354 vmov s8, r3 */
/* @0x178358 ldrsh r3, [r1, #2] */
/* @0x17835c vstr s15, [r2, #984] */
/* @0x178360 vstr s15, [r2, #992] */
/* @0x178364 vmov s5, r12 */
/* @0x178368 ldrsh r12, [r1, #14] */
/* @0x17836c vmov s9, r3 */
/* @0x178370 ldrsh r3, [r1] */
/* @0x178374 vcvt.f32.s32 s5, s5 */
/* @0x178378 str r0, [r2, #0x3e4] */
/* @0x17837c vmov s6, r12 */
/* @0x178380 ldrsh r12, [r1, #12] */
/* @0x178384 vmov s10, r3 */
/* @0x178388 str r10, [r2, #0x3f0] */
/* @0x17838c str r11, [r2, #0x3f4] */
/* @0x178390 vstr s15, [r2, #1020] */
/* @0x178394 vmov s11, r12 */
/* @0x178398 str r9, [r2, #0x3f8] */
/* @0x17839c vcvt.f32.s32 s11, s11 */

/* ── 顶点 28..35：改用暂存指针写 + 计数 ──
 *   0x178448 起把 r2+1184/1200/1216/1232/1248/1264/1280 存进 [sp+0x04..0x8c]，后续用 vstr sX,[rN,#小偏移]
 *   写同一批槽 —— 所以「偏移不整齐」只是编译器换了寻址方式，记录布局没变（每 36 B 一槽）
 *   0x178400/0x178490/0x17852c/0x178578/0x17860c/0x1786b0/0x1786f0/0x178744 八条 str r0 是本组 8 个顶点的 color
 *     （落在 0x408/0x42c/0x450/0x474/0x498/0x4bc/0x4e0/0x504 = 槽 28..35 的 +0x18）
 *   0x17876c add r2,r8,#36 + 0x178778 str：当前指针推进一个顶点
 *   0x17877c add r3,r3,#36 + 0x178780 str：**顶点数 += 36** ⇒ 一次调用提交 36 个顶点
 */
/* @0x1783a0 vcvt.f32.s32 s4, s4 */
/* @0x1783a4 vcvt.f32.s32 s8, s8 */
/* @0x1783a8 vcvt.f32.s32 s10, s10 */
/* @0x1783ac vcvt.f32.s32 s6, s6 */
/* @0x1783b0 vcvt.f32.s32 s9, s9 */
/* @0x1783b4 vmla.f32 s8, s16, s5 */
/* @0x1783b8 vmla.f32 s10, s16, s11 */
/* @0x1783bc vmov s11, r3 */
/* @0x1783c0 ldr r3, [sp, #0x6c] */
/* @0x1783c4 vmla.f32 s7, s17, s4 */
/* @0x1783c8 vmla.f32 s9, s6, s15 */
/* @0x1783cc vmov s6, r12 */
/* @0x1783d0 ldr r12, [sp, #0x8] */
/* @0x1783d4 vcvt.f32.s32 s6, s6 */
/* @0x1783d8 vcvt.f32.s32 s11, s11 */
/* @0x1783dc vmla.f32 s11, s6, s15 */
/* @0x1783e0 vdiv.f32 s7, s7, s13 */
/* @0x1783e4 vdiv.f32 s8, s8, s14 */
/* @0x1783e8 vstr s7, [r2, #1004] */
/* @0x1783ec vdiv.f32 s10, s10, s14 */
/* @0x1783f0 vstr s8, [r2, #1000] */
/* @0x1783f4 vstr s12, [r3] */
/* @0x1783f8 vstr s15, [r12] */
/* @0x1783fc ldr r3, [sp, #0xc] */
/* @0x178400 str r0, [r2, #0x408] */
/* @0x178404 ldr r12, [sp, #0x70] */
/* @0x178408 vdiv.f32 s9, s9, s13 */
/* @0x17840c vstr s10, [r3] */
/* @0x178410 ldr r3, [sp, #0x10] */
/* @0x178414 vdiv.f32 s11, s11, s14 */
/* @0x178418 vstr s9, [r12] */
/* @0x17841c str r4, [r3] */
/* @0x178420 ldr r12, [sp, #0x18] */
/* @0x178424 ldr r4, [sp, #0x14] */
/* @0x178428 str r11, [r4] */
/* @0x17842c str r9, [r12] */
/* @0x178430 ldr r4, [sp, #0x1c] */
/* @0x178434 ldr r3, [sp, #0x74] */
/* @0x178438 vstr s15, [r3] */
/* @0x17843c ldr r12, [sp, #0x20] */
/* @0x178440 vstr s12, [r4] */
/* @0x178444 vstr s15, [r12] */
/* @0x178448 add r4, r2, #1200 */
/* @0x17844c add r12, r2, #1216 */
/* @0x178450 add r4, r4, #8 */
/* @0x178454 add r12, r12, #4 */
/* @0x178458 str r4, [sp, #0xc] */
/* @0x17845c str r12, [sp, #0x10] */
/* @0x178460 add r4, r2, #1216 */
/* @0x178464 add r12, r2, #1232 */
/* @0x178468 add r4, r4, #12 */
/* @0x17846c add r12, r12, #4 */
/* @0x178470 str r4, [sp, #0x18] */
/* @0x178474 str r12, [sp, #0x1c] */
/* @0x178478 add r3, r2, #1200 */
/* @0x17847c ldrsh r4, [r1, #2] */
/* @0x178480 add r3, r3, #4 */
/* @0x178484 ldrsh r12, [r1, #14] */
/* @0x178488 str r3, [sp, #0x8] */
/* @0x17848c add r3, r2, #1216 */
/* @0x178490 str r0, [r2, #0x42c] */
/* @0x178494 add r3, r3, #8 */
/* @0x178498 vmov s7, r4 */
/* @0x17849c str r3, [sp, #0x14] */
/* @0x1784a0 ldr r3, [sp, #0x78] */
/* @0x1784a4 ldrsh r4, [r1, #2] */
/* @0x1784a8 vmov s10, r4 */
/* @0x1784ac ldr r4, [sp, #0x2c] */
/* @0x1784b0 vstr s11, [r3] */
/* @0x1784b4 vmov s11, r12 */
/* @0x1784b8 vcvt.f32.s32 s7, s7 */
/* @0x1784bc ldrsh r12, [r1] */
/* @0x1784c0 ldrsh r3, [r1, #12] */
/* @0x1784c4 vmov s9, r12 */
/* @0x1784c8 ldrsh r12, [r1, #14] */
/* @0x1784cc vcvt.f32.s32 s11, s11 */
/* @0x1784d0 vmla.f32 s7, s11, s15 */
/* @0x1784d4 vmov s11, r3 */
/* @0x1784d8 ldr r3, [sp, #0x28] */
/* @0x1784dc vcvt.f32.s32 s11, s11 */
/* @0x1784e0 vcvt.f32.s32 s9, s9 */
/* @0x1784e4 vmla.f32 s9, s11, s15 */
/* @0x1784e8 vmov s11, r12 */
/* @0x1784ec ldr r12, [sp, #0x24] */
/* @0x1784f0 vcvt.f32.s32 s11, s11 */
/* @0x1784f4 vcvt.f32.s32 s10, s10 */
/* @0x1784f8 vmla.f32 s10, s17, s11 */
/* @0x1784fc vdiv.f32 s7, s7, s13 */
/* @0x178500 vdiv.f32 s9, s9, s14 */
/* @0x178504 vstr s7, [r12] */
/* @0x178508 str r10, [r3] */
/* @0x17850c str r11, [r4] */
/* @0x178510 ldr r3, [sp, #0x30] */
/* @0x178514 str r9, [lr] */
/* @0x178518 vstr s12, [r3] */
/* @0x17851c ldr r4, [sp, #0x34] */
/* @0x178520 vstr s15, [r4] */
/* @0x178524 vstr s15, [lr, #12] */
/* @0x178528 add r4, r2, #1200 */
/* @0x17852c str r0, [r2, #0x450] */
/* @0x178530 add lr, r2, #1264 */
/* @0x178534 str r4, [sp, #0x2c] */
/* @0x178538 add r4, r2, #1264 */
/* @0x17853c ldr r12, [sp, #0x4] */
/* @0x178540 add r4, r4, #4 */
/* @0x178544 ldr r3, [sp] */
/* @0x178548 str r4, [sp, #0x24] */
/* @0x17854c ldr r4, [sp, #0x44] */
/* @0x178550 vdiv.f32 s10, s10, s13 */
/* @0x178554 vstr s9, [r12] */
/* @0x178558 vstr s7, [r3] */
/* @0x17855c str r10, [r5, #0xc] */
/* @0x178560 str r11, [r6] */
/* @0x178564 vstr s19, [r6, #4] */
/* @0x178568 ldr r5, [sp, #0x84] */
/* @0x17856c vstr s12, [r7, #8] */
/* @0x178570 vstr s15, [r8, #12] */
/* @0x178574 vstr s15, [r5] */
/* @0x178578 str r0, [r2, #0x474] */
/* @0x17857c vstr s9, [r4] */
/* @0x178580 ldr r4, [sp, #0x48] */
/* @0x178584 add r12, r2, #1248 */
/* @0x178588 add r12, r12, #4 */
/* @0x17858c str r12, [sp, #0x20] */
/* @0x178590 add r12, r2, #1216 */
/* @0x178594 str r12, [sp, #0x30] */
/* @0x178598 add r12, r2, #1264 */
/* @0x17859c add r7, r2, #1232 */
/* @0x1785a0 add r3, r2, #1184 */
/* @0x1785a4 add r12, r12, #8 */
/* @0x1785a8 str r3, [sp, #0x28] */
/* @0x1785ac add r5, r2, #1248 */
/* @0x1785b0 str r12, [sp, #0x6c] */
/* @0x1785b4 mov r6, r7 */
/* @0x1785b8 str r7, [sp, #0x34] */
/* @0x1785bc mov r8, r5 */
/* @0x1785c0 add r12, r2, #1280 */
/* @0x1785c4 mov r3, r12 */
/* @0x1785c8 vstr s10, [r4] */
/* @0x1785cc ldr r4, [sp, #0x88] */
/* @0x1785d0 str r10, [r4] */
/* @0x1785d4 ldr r4, [sp, #0x4c] */
/* @0x1785d8 vstr s18, [r4] */
/* @0x1785dc ldr r4, [sp, #0x50] */
/* @0x1785e0 vstr s19, [r4] */
/* @0x1785e4 ldr r4, [sp, #0x54] */
/* @0x1785e8 vstr s12, [r4] */
/* @0x1785ec ldr r4, [sp, #0x8c] */
/* @0x1785f0 vstr s15, [r4] */
/* @0x1785f4 ldrsh r4, [r1, #2] */
/* @0x1785f8 vmov s6, r4 */
/* @0x1785fc ldr r4, [sp, #0x58] */
/* @0x178600 vstr s15, [r4] */
/* @0x178604 ldrsh r4, [r1, #14] */
/* @0x178608 vcvt.f32.s32 s6, s6 */
/* @0x17860c str r0, [r2, #0x498] */
/* @0x178610 vmov s10, r4 */
/* @0x178614 ldrsh r4, [r1] */
/* @0x178618 vmov s7, r4 */
/* @0x17861c ldrsh r4, [r1, #12] */
/* @0x178620 vcvt.f32.s32 s10, s10 */
/* @0x178624 vmov s11, r4 */
/* @0x178628 ldrsh r4, [r1, #2] */
/* @0x17862c vmov s8, r4 */
/* @0x178630 ldrsh r4, [r1, #2] */
/* @0x178634 vcvt.f32.s32 s8, s8 */
/* @0x178638 vcvt.f32.s32 s11, s11 */
/* @0x17863c vcvt.f32.s32 s7, s7 */
/* @0x178640 vmla.f32 s6, s17, s10 */
/* @0x178644 vmla.f32 s8, s17, s10 */
/* @0x178648 vmov s10, r4 */
/* @0x17864c ldrsh r4, [r1, #14] */
/* @0x178650 vmov s5, r4 */
/* @0x178654 ldr r4, [sp, #0x5c] */
/* @0x178658 vcvt.f32.s32 s10, s10 */
/* @0x17865c vcvt.f32.s32 s5, s5 */
/* @0x178660 vmla.f32 s7, s16, s11 */
/* @0x178664 vmla.f32 s10, s5, s15 */
/* @0x178668 vdiv.f32 s7, s7, s14 */
/* @0x17866c vdiv.f32 s6, s6, s13 */
/* @0x178670 vstr s7, [r4] */
/* @0x178674 ldr r4, [sp, #0x28] */
/* @0x178678 vdiv.f32 s8, s8, s13 */
/* @0x17867c vstr s6, [r4] */
/* @0x178680 ldr r4, [sp, #0x60] */
/* @0x178684 str r10, [r4] */
/* @0x178688 ldr r4, [sp, #0x38] */
/* @0x17868c vstr s18, [r4] */
/* @0x178690 ldr r4, [sp, #0x64] */
/* @0x178694 vstr s19, [r4] */
/* @0x178698 ldr r4, [sp, #0x2c] */
/* @0x17869c vstr s12, [r4] */
/* @0x1786a0 ldr r4, [sp, #0x8] */
/* @0x1786a4 vstr s15, [r4] */
/* @0x1786a8 ldr r4, [sp, #0xc] */
/* @0x1786ac vstr s15, [r4] */
/* @0x1786b0 str r0, [r2, #0x4bc] */
/* @0x1786b4 ldr r4, [sp, #0x30] */
/* @0x1786b8 vstr s7, [r4] */
/* @0x1786bc ldr r4, [sp, #0x10] */
/* @0x1786c0 vdiv.f32 s10, s10, s13 */
/* @0x1786c4 vstr s8, [r4] */
/* @0x1786c8 ldr r4, [sp, #0x14] */
/* @0x1786cc str r10, [r4] */
/* @0x1786d0 ldr r4, [sp, #0x18] */
/* @0x1786d4 vstr s18, [r4] */
/* @0x1786d8 ldr r4, [sp, #0x1c] */
/* @0x1786dc str r9, [r7] */
/* @0x1786e0 vstr s12, [r4] */
/* @0x1786e4 vstr s15, [r7, #8] */
/* @0x1786e8 ldr r4, [sp, #0x20] */
/* @0x1786ec vstr s15, [r6, #12] */
/* @0x1786f0 str r0, [r2, #0x4e0] */
/* @0x1786f4 vstr s7, [r4] */
/* @0x1786f8 ldrsh r4, [r1, #14] */
/* @0x1786fc vmov s9, r4 */
/* @0x178700 ldr r4, [sp, #0x6c] */
/* @0x178704 vstr s10, [r5, #8] */
/* @0x178708 ldrsh r5, [r1, #2] */
/* @0x17870c vcvt.f32.s32 s9, s9 */
/* @0x178710 vmov s11, r5 */
/* @0x178714 ldrsh r5, [r1] */
/* @0x178718 ldrsh r1, [r1, #12] */
/* @0x17871c str r10, [r8, #0xc]! */
/* @0x178720 vmov s8, r5 */
/* @0x178724 str r11, [lr] */
/* @0x178728 vmov s10, r1 */
/* @0x17872c ldr r1, [sp, #0x24] */
/* @0x178730 vcvt.f32.s32 s11, s11 */
/* @0x178734 str r9, [r1] */
/* @0x178738 vstr s12, [r4] */
/* @0x17873c vstr s15, [lr, #12] */
/* @0x178740 vstr s15, [r12] */
/* @0x178744 str r0, [r2, #0x504] */
/* @0x178748 vcvt.f32.s32 s12, s8 */
/* @0x17874c vcvt.f32.s32 s10, s10 */
/* @0x178750 vmla.f32 s11, s9, s15 */
/* @0x178754 vmla.f32 s12, s10, s15 */
/* @0x178758 vdiv.f32 s13, s11, s13 */
/* @0x17875c vdiv.f32 s14, s12, s14 */
/* @0x178760 vstr s14, [r12, #8] */
/* @0x178764 vstr s13, [r3, #12] */

/* ── 公共收尾 ──
 *   0x178784 GR_3D_Primitive_End()；0x178788 Graphics::Flush()（与开头成对）
 *   0x17878c 取回存档的纹理重复值 → 撤帧 → 0x17879c b GR_D3D_Set_Texture_Repeat(旧值)
 *   ⇒ 尾调用：本函数自己不 return，返回值 = 恢复纹理重复那次调用的返回值
 */
/* @0x178768 ldr r1, [sp, #0x3c] */
/* @0x17876c add r2, r8, #36 */
/* @0x178770 ldr r4, [sp, #0x40] */
/* @0x178774 ldr r3, [r1] */
/* @0x178778 str r2, [r4] */
/* @0x17877c add r3, r3, #36 */
/* @0x178780 str r3, [r1] */
/* @0x178784 bl 0x176ad0 <_Z19GR_3D_Primitive_Endv> */
/* @0x178788 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x17878c ldr r0, [sp, #0x68] */
/* @0x178790 add sp, sp, #148 */
/* @0x178794 vpop {d8, d9, d10} */
/* @0x178798 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x17879c b 0x168870 <_Z25GR_D3D_Set_Texture_Repeatb> */

/* ── 无精灵分支（0x17770c 的 beq 落点）：同 36 个顶点，UV 退化 ──
 *   几何、法线、color 的写法与纹理路径完全相同（同一批 36 槽、同样的 0x18 位置、同样 36 的计数）
 *   差别只在 +0x1c/+0x20：大量 vstr s15,[r2,#28]/[r2,#32] 把 UV 直接置 0，少数槽写 s16/s17（= arg7/arg8）
 *   例：0x178b58/0x178b5c 把 s16/s17 直接写进槽 26 的 +0x1c/+0x20
 *   本分支不读精灵对象、不做 vdiv ⇒ 无精灵时不存在「÷纹理尺寸」这一步
 */
/* @0x1787a0 add r3, r2, #1024 */
/* @0x1787a4 mov r1, #1065353216 */
/* @0x1787a8 str r4, [r2, #0x48] */
/* @0x1787ac vstr s15, [r2, #28] */
/* @0x1787b0 str r4, [r2, #0x6c] */
/* @0x1787b4 vstr s15, [r2, #32] */
/* @0x1787b8 str r4, [r2, #0x90] */
/* @0x1787bc vstr s18, [r2, #40] */
/* @0x1787c0 str r10, [r2, #0x24] */
/* @0x1787c4 vstr s15, [r2, #48] */
/* @0x1787c8 str r9, [r2, #0x2c] */
/* @0x1787cc vstr s15, [r2, #52] */
/* @0x1787d0 vstr s12, [r2, #56] */
/* @0x1787d4 str r0, [r2, #0x3c] */
/* @0x1787d8 vstr s15, [r2, #64] */
/* @0x1787dc vstr s17, [r2, #68] */
/* @0x1787e0 vstr s18, [r2, #76] */
/* @0x1787e4 str r9, [r2, #0x50] */
/* @0x1787e8 vstr s15, [r2, #84] */
/* @0x1787ec vstr s15, [r2, #88] */
/* @0x1787f0 vstr s12, [r2, #92] */
/* @0x1787f4 str r0, [r2, #0x60] */
/* @0x1787f8 vstr s16, [r2, #100] */
/* @0x1787fc vstr s17, [r2, #104] */
/* @0x178800 vstr s18, [r2, #112] */
/* @0x178804 str r9, [r2, #0x74] */
/* @0x178808 vstr s15, [r2, #120] */
/* @0x17880c vstr s15, [r2, #124] */
/* @0x178810 vstr s12, [r2, #128] */
/* @0x178814 str r0, [r2, #0x84] */
/* @0x178818 vstr s16, [r2, #136] */
/* @0x17881c vstr s17, [r2, #140] */
/* @0x178820 str r11, [r2, #0x94] */
/* @0x178824 vstr s15, [r2, #156] */
/* @0x178828 str r9, [r2, #0x98] */
/* @0x17882c vstr s15, [r2, #160] */
/* @0x178830 str r4, [r2, #0xfc] */
/* @0x178834 vstr s12, [r2, #164] */
/* @0x178838 str r4, [r2, #0x120] */
/* @0x17883c vstr s16, [r2, #172] */
/* @0x178840 str r1, [r2, #0xec] */
/* @0x178844 vstr s15, [r2, #176] */
/* @0x178848 str r1, [r2, #0x110] */
/* @0x17884c vstr s15, [r2, #192] */
/* @0x178850 str r0, [r2, #0xa8] */
/* @0x178854 vstr s15, [r2, #196] */
/* @0x178858 str r10, [r2, #0xb4] */
/* @0x17885c vstr s12, [r2, #200] */
/* @0x178860 str r11, [r2, #0xb8] */
/* @0x178864 vstr s15, [r2, #208] */
/* @0x178868 str r9, [r2, #0xbc] */
/* @0x17886c vstr s15, [r2, #212] */
/* @0x178870 str r0, [r2, #0xcc] */
/* @0x178874 vstr s19, [r2, #224] */
/* @0x178878 str r10, [r2, #0xd8] */
/* @0x17887c vstr s15, [r2, #228] */
/* @0x178880 str r11, [r2, #0xdc] */
/* @0x178884 vstr s15, [r2, #232] */
/* @0x178888 str r0, [r2, #0xf0] */
/* @0x17888c vstr s15, [r2, #244] */
/* @0x178890 vstr s15, [r2, #248] */
/* @0x178894 str r11, [r2, #0x100] */
/* @0x178898 vstr s19, [r2, #260] */
/* @0x17889c vstr s15, [r2, #264] */
/* @0x1788a0 vstr s15, [r2, #268] */
/* @0x1788a4 str r0, [r2, #0x114] */
/* @0x1788a8 vstr s16, [r2, #280] */
/* @0x1788ac vstr s15, [r2, #284] */
/* @0x1788b0 vstr s18, [r2, #292] */
/* @0x1788b4 vstr s19, [r2, #296] */
/* @0x1788b8 str r1, [r2, #0x134] */
/* @0x1788bc vstr s15, [r2, #300] */
/* @0x1788c0 str r1, [r2, #0x158] */
/* @0x1788c4 vstr s15, [r2, #304] */
/* @0x1788c8 str r1, [r2, #0x17c] */
/* @0x1788cc vstr s16, [r2, #316] */
/* @0x1788d0 str r1, [r2, #0x1a0] */
/* @0x1788d4 vstr s17, [r2, #320] */
/* @0x1788d8 str r4, [r2, #0x144] */
/* @0x1788dc vstr s18, [r2, #328] */
/* @0x1788e0 str r0, [r2, #0x138] */
/* @0x1788e4 vstr s19, [r2, #332] */
/* @0x1788e8 vstr s15, [r2, #336] */
/* @0x1788ec vstr s15, [r2, #340] */
/* @0x1788f0 str r0, [r2, #0x15c] */
/* @0x1788f4 vstr s16, [r2, #352] */
/* @0x1788f8 vstr s17, [r2, #356] */
/* @0x1788fc str r10, [r2, #0x168] */
/* @0x178900 vstr s18, [r2, #364] */
/* @0x178904 vstr s19, [r2, #368] */
/* @0x178908 vstr s15, [r2, #372] */
/* @0x17890c vstr s15, [r2, #376] */
/* @0x178910 str r0, [r2, #0x180] */
/* @0x178914 vstr s15, [r2, #388] */
/* @0x178918 vstr s17, [r2, #392] */
/* @0x17891c str r10, [r2, #0x18c] */
/* @0x178920 str r11, [r2, #0x190] */
/* @0x178924 vstr s19, [r2, #404] */
/* @0x178928 vstr s15, [r2, #408] */
/* @0x17892c vstr s15, [r2, #412] */
/* @0x178930 str r0, [r2, #0x1a4] */
/* @0x178934 vstr s15, [r2, #424] */
/* @0x178938 vstr s15, [r2, #428] */
/* @0x17893c str r10, [r2, #0x1b0] */
/* @0x178940 str r1, [r2, #0x1c0] */
/* @0x178944 vstr s18, [r2, #436] */
/* @0x178948 str r1, [r2, #0x1e4] */
/* @0x17894c vstr s15, [r2, #444] */
/* @0x178950 str r1, [r2, #0x208] */
/* @0x178954 vstr s15, [r2, #452] */
/* @0x178958 str r1, [r2, #0x22c] */
/* @0x17895c vstr s15, [r2, #460] */
/* @0x178960 str r4, [r2, #0x1f8] */
/* @0x178964 vstr s15, [r2, #464] */
/* @0x178968 str r4, [r2, #0x21c] */
/* @0x17896c vstr s18, [r2, #472] */
/* @0x178970 str r9, [r2, #0x1b8] */
/* @0x178974 vstr s19, [r2, #476] */
/* @0x178978 str r0, [r2, #0x1c8] */
/* @0x17897c vstr s15, [r2, #480] */
/* @0x178980 str r10, [r2, #0x1d4] */
/* @0x178984 vstr s15, [r2, #488] */
/* @0x178988 str r0, [r2, #0x1ec] */
/* @0x17898c vstr s15, [r2, #496] */
/* @0x178990 vstr s17, [r2, #500] */
/* @0x178994 vstr s18, [r2, #508] */
/* @0x178998 vstr s19, [r2, #512] */
/* @0x17899c vstr s15, [r2, #516] */
/* @0x1789a0 vstr s15, [r2, #524] */
/* @0x1789a4 str r0, [r2, #0x210] */
/* @0x1789a8 vstr s16, [r2, #532] */
/* @0x1789ac vstr s17, [r2, #536] */
/* @0x1789b0 vstr s18, [r2, #544] */
/* @0x1789b4 vstr s19, [r2, #548] */
/* @0x1789b8 vstr s15, [r2, #552] */
/* @0x1789bc vstr s15, [r2, #560] */
/* @0x1789c0 str r0, [r2, #0x234] */
/* @0x1789c4 vstr s16, [r2, #568] */
/* @0x1789c8 str r1, [r2, #0x250] */
/* @0x1789cc vstr s17, [r2, #572] */
/* @0x1789d0 str r1, [r2, #0x274] */
/* @0x1789d4 vstr s18, [r2, #580] */
/* @0x1789d8 str r1, [r2, #0x294] */
/* @0x1789dc vstr s15, [r2, #588] */
/* @0x1789e0 str r1, [r2, #0x2b8] */
/* @0x1789e4 vstr s15, [r2, #596] */
/* @0x1789e8 str r4, [r2, #0x240] */
/* @0x1789ec vstr s16, [r2, #604] */
/* @0x1789f0 str r4, [r2, #0x288] */
/* @0x1789f4 vstr s15, [r2, #608] */
/* @0x1789f8 str r4, [r2, #0x2ac] */
/* @0x1789fc vstr s18, [r2, #616] */
/* @0x178a00 str r9, [r2, #0x248] */
/* @0x178a04 vstr s15, [r2, #624] */
/* @0x178a08 str r0, [r2, #0x258] */
/* @0x178a0c vstr s15, [r2, #632] */
/* @0x178a10 str r10, [r2, #0x264] */
/* @0x178a14 vstr s15, [r2, #640] */
/* @0x178a18 str r9, [r2, #0x26c] */
/* @0x178a1c vstr s15, [r2, #644] */
/* @0x178a20 str r0, [r2, #0x27c] */
/* @0x178a24 vstr s18, [r2, #652] */
/* @0x178a28 str r9, [r2, #0x290] */
/* @0x178a2c vstr s15, [r2, #664] */
/* @0x178a30 vstr s15, [r2, #668] */
/* @0x178a34 str r0, [r2, #0x2a0] */
/* @0x178a38 vstr s15, [r2, #676] */
/* @0x178a3c vstr s15, [r2, #680] */
/* @0x178a40 vstr s18, [r2, #688] */
/* @0x178a44 vstr s19, [r2, #692] */
/* @0x178a48 vstr s15, [r2, #700] */
/* @0x178a4c vstr s15, [r2, #704] */
/* @0x178a50 str r1, [r2, #0x2dc] */
/* @0x178a54 vstr s15, [r2, #712] */
/* @0x178a58 str r1, [r2, #0x300] */
/* @0x178a5c vstr s17, [r2, #716] */
/* @0x178a60 str r1, [r2, #0x324] */
/* @0x178a64 vstr s19, [r2, #728] */
/* @0x178a68 str r4, [r2, #0x2d0] */
/* @0x178a6c vstr s15, [r2, #736] */
/* @0x178a70 str r4, [r2, #0x2f4] */
/* @0x178a74 vstr s15, [r2, #740] */
/* @0x178a78 str r4, [r2, #0x318] */
/* @0x178a7c vstr s16, [r2, #748] */
/* @0x178a80 str r4, [r2, #0x33c] */
/* @0x178a84 vstr s17, [r2, #752] */
/* @0x178a88 str r0, [r2, #0x2c4] */
/* @0x178a8c vstr s19, [r2, #764] */
/* @0x178a90 str r11, [r2, #0x2d4] */
/* @0x178a94 vstr s15, [r2, #772] */
/* @0x178a98 str r0, [r2, #0x2e8] */
/* @0x178a9c vstr s15, [r2, #776] */
/* @0x178aa0 str r11, [r2, #0x2f8] */
/* @0x178aa4 vstr s16, [r2, #784] */
/* @0x178aa8 str r0, [r2, #0x30c] */
/* @0x178aac vstr s17, [r2, #788] */
/* @0x178ab0 str r11, [r2, #0x31c] */
/* @0x178ab4 vstr s15, [r2, #808] */
/* @0x178ab8 str r9, [r2, #0x320] */
/* @0x178abc vstr s15, [r2, #812] */
/* @0x178ac0 str r0, [r2, #0x330] */
/* @0x178ac4 vstr s16, [r2, #820] */
/* @0x178ac8 vstr s15, [r2, #824] */
/* @0x178acc vstr s18, [r2, #832] */
/* @0x178ad0 str r9, [r2, #0x344] */
/* @0x178ad4 add r8, r2, #1248 */
/* @0x178ad8 str r1, [r2, #0x348] */
/* @0x178adc mov r1, r3 */
/* @0x178ae0 str r4, [r2, #0x360] */
/* @0x178ae4 vstr s15, [r2, #844] */
/* @0x178ae8 str r4, [r2, #0x384] */
/* @0x178aec vstr s15, [r2, #848] */
/* @0x178af0 str r0, [r2, #0x354] */
/* @0x178af4 vstr s15, [r2, #856] */
/* @0x178af8 vstr s15, [r2, #860] */
/* @0x178afc str r11, [r2, #0x364] */
/* @0x178b00 str r9, [r2, #0x368] */
/* @0x178b04 vstr s15, [r2, #876] */
/* @0x178b08 vstr s12, [r2, #880] */
/* @0x178b0c vstr s15, [r2, #884] */
/* @0x178b10 str r0, [r2, #0x378] */
/* @0x178b14 vstr s15, [r2, #892] */
/* @0x178b18 vstr s15, [r2, #896] */
/* @0x178b1c str r11, [r2, #0x388] */
/* @0x178b20 vstr s19, [r2, #908] */
/* @0x178b24 vstr s15, [r2, #912] */
/* @0x178b28 vstr s12, [r2, #916] */
/* @0x178b2c vstr s15, [r2, #920] */
/* @0x178b30 str r0, [r2, #0x39c] */
/* @0x178b34 vstr s15, [r2, #928] */
/* @0x178b38 vstr s17, [r2, #932] */
/* @0x178b3c str r10, [r2, #0x3a8] */
/* @0x178b40 str r11, [r2, #0x3ac] */
/* @0x178b44 vstr s19, [r2, #944] */
/* @0x178b48 vstr s15, [r2, #948] */
/* @0x178b4c vstr s12, [r2, #952] */
/* @0x178b50 vstr s15, [r2, #956] */
/* @0x178b54 str r0, [r2, #0x3c0] */
/* @0x178b58 vstr s16, [r2, #964] */
/* @0x178b5c vstr s17, [r2, #968] */
/* @0x178b60 str r10, [r2, #0x3cc] */
/* @0x178b64 str r11, [r2, #0x3d0] */
/* @0x178b68 vstr s19, [r2, #980] */
/* @0x178b6c vstr s15, [r2, #984] */
/* @0x178b70 vstr s12, [r2, #988] */
/* @0x178b74 vstr s15, [r2, #992] */
/* @0x178b78 str r0, [r2, #0x3e4] */
/* @0x178b7c vstr s16, [r2, #1000] */
/* @0x178b80 vstr s17, [r2, #1004] */
/* @0x178b84 str r10, [r2, #0x3f0] */
/* @0x178b88 vstr s15, [r2, #1020] */
/* @0x178b8c str r11, [r2, #0x3f4] */
/* @0x178b90 str r9, [r2, #0x3f8] */

/* ── 无精灵分支尾部 ──
 *   0x178b94 起继续用暂存指针写槽 28..35（color 落在 0x408/0x42c/0x450/0x474/0x498/0x4bc/0x4e0/0x504）
 *   0x178d40 b 0x178768 —— 汇入公共收尾（Primitive_End + Flush + 恢复纹理重复）
 *   ★ 两条路径的顶点数、字段顺序、color 完全一致 ⇒ 缓冲里的 36 条记录只差 UV 两组值
 *
 * ── §2 open ──
 *   1. 36 个顶点各自的 UV 系数（0 / 1 / arg7 / arg8）没有逐顶点建表：本卡只证系数取值域与「按面/取角不同」，
 *      逐槽 (u,v) 表达式要把 0x177710..0x178760 的 s 寄存器数据流整段解一遍（约 1400 条）。
 *      同理，第六个面的法线 (-1,0,0) 是按前五组的模板推定，未在写点处逐字核到。
 *   2. arg3(r4)、arg4(s18)、arg5(s19) 的语义按「两个对角点」推定：x∈{arg0,arg3}、y∈{arg1,arg4}、z∈{arg2,arg5}
 *      三条都在写点处见到（槽 0/1/2/6/12 等），但 6 个实参的形参名（x1,y1,z1,x2,y2,z2 还是 x,y,z,w,h,d）未定。
 *   3. int 实参（arg6）只证它是 Primitive_Begin 的第二个实参（0x17768c/0x177690 的 r0=4, r1=r6）；
 *      语义（图元类型/混合模式）未证。
 *   4. Primitive_Begin 的第一个实参 4 的枚举含义没有枚举表证据；从 36 = 6 面 × 6 顶点（每面两个三角形）看
 *      像三角列表，但这是几何推断，不是指令证据。
 *   5. s15 同时当「UV 系数 0」与「法线分量 0」用，是编译器的寄存器复用，不要据此推断语义。
 */
/* @0x178b94 vstr s12, [r3] */
/* @0x178b98 vstr s15, [r3, #4] */
/* @0x178b9c add r3, r2, #1040 */
/* @0x178ba0 str r0, [r2, #0x408] */
/* @0x178ba4 vstr s16, [r1, #12] */
/* @0x178ba8 mov r1, r3 */
/* @0x178bac str r4, [r3, #0x4] */
/* @0x178bb0 vstr s15, [r3] */
/* @0x178bb4 str r11, [r1, #0x8] */
/* @0x178bb8 str r9, [r1, #0xc] */
/* @0x178bbc add r3, r2, #1056 */
/* @0x178bc0 add r1, r2, #1072 */
/* @0x178bc4 vstr s15, [r3] */
/* @0x178bc8 vstr s12, [r3, #4] */
/* @0x178bcc mov r12, r3 */
/* @0x178bd0 mov r3, r1 */
/* @0x178bd4 vstr s15, [r12, #8] */
/* @0x178bd8 str r0, [r2, #0x42c] */
/* @0x178bdc mov r12, r1 */
/* @0x178be0 vstr s15, [r1, #4] */
/* @0x178be4 vstr s15, [r1] */
/* @0x178be8 add r1, r2, #1088 */
/* @0x178bec str r10, [r3, #0x8] */
/* @0x178bf0 str r11, [r12, #0xc] */
/* @0x178bf4 vstr s12, [r1, #4] */
/* @0x178bf8 str r9, [r1] */
/* @0x178bfc mov r3, r1 */
/* @0x178c00 mov r12, r1 */
/* @0x178c04 add r1, r2, #1104 */
/* @0x178c08 vstr s15, [r3, #8] */
/* @0x178c0c vstr s15, [r12, #12] */
/* @0x178c10 mov r3, r1 */
/* @0x178c14 mov r12, r1 */
/* @0x178c18 str r0, [r2, #0x450] */
/* @0x178c1c vstr s15, [r1, #4] */
/* @0x178c20 add r1, r2, #1120 */
/* @0x178c24 vstr s15, [r3, #8] */
/* @0x178c28 str r10, [r12, #0xc] */
/* @0x178c2c vstr s19, [r1, #4] */
/* @0x178c30 str r11, [r1] */
/* @0x178c34 mov r3, r1 */
/* @0x178c38 mov r12, r1 */
/* @0x178c3c vstr s12, [r3, #8] */
/* @0x178c40 add r1, r2, #1136 */
/* @0x178c44 vstr s15, [r12, #12] */
/* @0x178c48 add r12, r2, #1152 */
/* @0x178c4c vstr s15, [r1] */
/* @0x178c50 mov r3, r1 */
/* @0x178c54 str r0, [r2, #0x474] */
/* @0x178c58 vstr s15, [r1, #8] */
/* @0x178c5c vstr s17, [r3, #12] */
/* @0x178c60 mov r1, r12 */
/* @0x178c64 str r10, [r12] */
/* @0x178c68 vstr s18, [r12, #4] */
/* @0x178c6c mov r3, r12 */
/* @0x178c70 vstr s19, [r1, #8] */
/* @0x178c74 add r12, r2, #1168 */
/* @0x178c78 vstr s12, [r3, #12] */
/* @0x178c7c add r3, r2, #1184 */
/* @0x178c80 vstr s15, [r12] */
/* @0x178c84 vstr s15, [r12, #4] */
/* @0x178c88 mov r1, r12 */
/* @0x178c8c str r0, [r2, #0x498] */
/* @0x178c90 mov r12, r3 */
/* @0x178c94 vstr s16, [r1, #12] */
/* @0x178c98 vstr s17, [r3] */
/* @0x178c9c str r10, [r3, #0x4] */
/* @0x178ca0 vstr s18, [r12, #8] */
/* @0x178ca4 add r12, r2, #1216 */
/* @0x178ca8 add r4, r2, #1232 */
/* @0x178cac mov r1, r3 */
/* @0x178cb0 add r3, r2, #1200 */
/* @0x178cb4 vstr s19, [r1, #12] */
/* @0x178cb8 mov r1, r12 */
/* @0x178cbc vstr s12, [r3] */
/* @0x178cc0 vstr s15, [r3, #4] */
/* @0x178cc4 mov lr, r3 */
/* @0x178cc8 mov r3, r12 */
/* @0x178ccc vstr s15, [lr, #8] */
/* @0x178cd0 str r0, [r2, #0x4bc] */
/* @0x178cd4 mov lr, r4 */
/* @0x178cd8 vstr s16, [r12] */
/* @0x178cdc vstr s17, [r12, #4] */
/* @0x178ce0 str r10, [r1, #0x8] */
/* @0x178ce4 mov r12, r4 */
/* @0x178ce8 vstr s18, [r3, #12] */
/* @0x178cec add r1, r2, #1280 */
/* @0x178cf0 str r9, [r4] */
/* @0x178cf4 vstr s12, [r4, #4] */
/* @0x178cf8 add r4, r2, #1264 */
/* @0x178cfc vstr s15, [lr, #8] */
/* @0x178d00 mov r3, r1 */
/* @0x178d04 vstr s15, [r12, #12] */
/* @0x178d08 mov lr, r4 */
/* @0x178d0c str r0, [r2, #0x4e0] */
/* @0x178d10 mov r12, r4 */
/* @0x178d14 vstr s16, [r8, #4] */
/* @0x178d18 vstr s15, [r8, #8] */
/* @0x178d1c str r10, [r8, #0xc]! */
/* @0x178d20 str r11, [r4] */
/* @0x178d24 str r9, [r4, #0x4] */
/* @0x178d28 vstr s12, [lr, #8] */
/* @0x178d2c vstr s15, [r12, #12] */
/* @0x178d30 vstr s15, [r1] */
/* @0x178d34 str r0, [r2, #0x504] */
/* @0x178d38 vstr s15, [r1, #8] */
/* @0x178d3c vstr s15, [r3, #12] */
/* @0x178d40 b 0x178768 <_Z16GR_3D_Draw_Blockffffffiff+0x112c> */

