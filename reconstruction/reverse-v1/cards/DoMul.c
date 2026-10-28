/* cally 逆向卡：DoMul（原版 libyoyo.so，armv7）
 * @func 0xe5810 0xe61b0  size 2468  617 条指令（含尾部 literal 池）
 * 级别: 骨架（入口/两级 kind 分派/103 路消费表/52 路算术表/10 条算术核/字符串重复路径已证；
 *        kind 1、kind 4 的语义未证）
 * 符号: _Z5DoMuljPhPKhP6VMExec → uchar* DoMul(uint32 arg, uchar* sp, const uchar* base, VMExec* exec)
 *
 * 已证（指令级）：
 *   mode  = (arg >> 8) & 0xF          ; @0xe5810（ubfx r2,r0,#8,#4；cmp r2,#1 → beq 0xe5dd0）
 *   kindA = (arg >> 16) & 0xF         ; @0xe5830（and r2,r5,#15；r5 = uxtb(arg>>16)）
 *   kindB = (arg >> 20) & 0xF         ; @0xe5864（asr r2,r7,#4）
 *   pair  = kindA | (kindB << 4)      ; @0xe5898（cmp r5,#102 的 103 路表索引）
 *
 * 寄存器角色：r8 = base、r9 = opB 槽（= base+sizeA）、r4 = 新 sp（= opB 槽 + sizeB）、
 *             r5 = 结果槽、r6 = 待释放槽。
 * 操作数布局与 DoShr 同构：opA（kindA，位[19:16]）在 base+0，opB（kindB，位[23:20]）在
 * base+sizeA。乘法交换律下分不出左右，但字符串重复核（@0xe5cf4）证明 **opA 是串、opB 是次数**，
 * 即源码形如 `次数 * 串`：pair 6 = (串, real 次数)、pair 38 = (串, int32 次数)。
 *
 * 结论（新增五条硬事实）：
 *   1. **mode 只有 1 走常量装箱**（cmp r2,#1）；mode 2..15 与 0 同路。这与 DoShr 的
 *      "mode≠0 即装箱" 不同 —— 同一套模板在两个算子上取值不同。
 *   2. **kindA 表**（@0xe5838）：kindA∈{0,3} → opA 占 8 字节、opB 槽 = base+8；
 *      kindA∈{1,2,4,6} → opA 占 4 字节、opB 槽 = base+4；kindA=5 → 间接（按 tag 反推）；
 *      **没有 kindA=6 的报错分支** —— 字符串在本算子里是被支持的类型。
 *      **kindB 表**（@0xe586c）同构：kindB∈{0,3} → 新 sp = opA+8，其余 → opA+4，kindB=5 → 间接。
 *   3. **间接操作数按 tag 反推 kind**（14 路表，tag 在 +12）：tag 0/13 → real、tag 7 → int32、
 *      tag 10 → int64、tag 1 → **string（kind 6）**；tag 2 → "illegal array use"（opA 侧）/
 *      "Variable is malformed"（opB 侧，块合并所致）、tag 3 → "illegal pointer use"、
 *      tag 5 → "undefined value"、tag 4/6/8/9/11/12 → "Variable is malformed"。
 *   4. **pair 6 与 pair 38 是字符串重复**（@0xe5cf4）：pair 6 = (kindA=6 串, kindB=0 real)、
 *      pair 38 = (kindA=6 串, kindB=2 int32)，即 **字符串只能做 opA**，次数来自 opB；
 *      kindB=0 时用 vcvt.s32.f64 取整（@0xe60c0），kindB=2 时直接取 int32（@0xe5ef4）。
 *      实现：MemoryManager::Alloc(len*count+1, "…/VM_Exec.cpp", 0xb54=2900, 1) → strcat 循环
 *      count 次 → operator new(12) 造 {data, refcount=1, len} → 结果 tag = **1（string）**；
 *      原串引用计数减 1（LOCK_RVALUE_MUTEX / [obj+4]-- ），归零则 YYFree + _RefThing::dec + delete。
 *   5. **52 路算术表**（@0xe5a4c cmp #51）10 条合法 pair（pair = kA|kB<<4），real 一律经 vmul.f64：
 *        pair 0   kA=0 kB=0  real × real         @0xe5ca8
 *        pair 2   kA=2 kB=0  int32 × real        @0xe5c8c（opA vcvt.f64.s32）
 *        pair 3   kA=3 kB=0  int64 × real        @0xe5d98（__floatdidf）
 *        pair 32  kA=0 kB=2  real × int32        @0xe5cd8
 *        pair 34  kA=2 kB=2  int32 × int32       @0xe5cc0（mul，结果 tag 7）
 *        pair 35  kA=3 kB=2  int64 × int32       @0xe5c64（umull+mla，tag 10）
 *        pair 48  kA=0 kB=3  real × int64        @0xe5c44
 *        pair 50  kA=2 kB=3  int32 × int64       @0xe5c30
 *        pair 51  kA=3 kB=3  int64 × int64       @0xe5bf4（umull+mla 全 64 位，tag 10）
 *        pair 6   kA=6 kB=0  串 × real 次数       @0xe5cf4
 *        pair 38  kA=6 kB=2  串 × int32 次数      @0xe5cf4
 *      其余（含 pair 96 = 字符串当 opB）→ VMError("DoMul :: Execution Error")。
 *      pair>102 越界直接落到 pair 34/102 的块（编译器 default 落点）。
 * open：kind 1 / kind 4 的语义；opA=string 时"次数"到底取 opB 的哪 4 字节（k1∈{1,4} 的 4 字节
 *       槽在字符串路径里被当次数用时符号性如何）；字符串长度上限/溢出（len*count+1 无检查）。
 */
/* ---- 入口：mode=(arg>>8)&0xF，只有 mode==1 走常量装箱 ---- */
/* @0x00e5810 ubfx r2, r0, #0x8, #0x4 */
/* @0x00e5814 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x00e5818 cmp r2, #1 */
/* @0x00e581c lsr r7, r0, #16 */
/* @0x00e5820 sub sp, sp, #72 */
/* @0x00e5824 mov r8, r1 */
/* @0x00e5828 uxtb r5, r7 */
/* @0x00e582c beq 0xe5dd0 <_Z5DoMuljPhPKhP6VMExec+0x5c0> */
/* ---- kindA=(arg>>16)&0xF 表：{0,3}→8 字节槽，{1,2,4,6}→4 字节槽，{5}→间接 ---- */
/* @0x00e5830 and r2, r5, #15 */
/* @0x00e5834 cmp r2, #6 */
/* @0x00e5838 addls pc, pc, r2, lsl #2 */
/* @0x00e583c b 0xe6168 <_Z5DoMuljPhPKhP6VMExec+0x958> */
/* @0x00e5840 b 0xe5bdc <_Z5DoMuljPhPKhP6VMExec+0x3cc> */
/* @0x00e5844 b 0xe585c <_Z5DoMuljPhPKhP6VMExec+0x4c> */
/* @0x00e5848 b 0xe585c <_Z5DoMuljPhPKhP6VMExec+0x4c> */
/* @0x00e584c b 0xe5bdc <_Z5DoMuljPhPKhP6VMExec+0x3cc> */
/* @0x00e5850 b 0xe585c <_Z5DoMuljPhPKhP6VMExec+0x4c> */
/* @0x00e5854 b 0xe5b94 <_Z5DoMuljPhPKhP6VMExec+0x384> */
/* @0x00e5858 b 0xe585c <_Z5DoMuljPhPKhP6VMExec+0x4c> */
/* @0x00e585c add r9, r1, #4 */
/* @0x00e5860 mov r7, r5 */
/* ---- kindB=(pair>>4)&0xF 表：{0,3}→新 sp=opA+8，其余→opA+4，{5}→间接 ---- */
/* @0x00e5864 asr r2, r7, #4 */
/* @0x00e5868 cmp r2, #6 */
/* @0x00e586c addls pc, pc, r2, lsl #2 */
/* @0x00e5870 b 0xe6174 <_Z5DoMuljPhPKhP6VMExec+0x964> */
/* @0x00e5874 b 0xe5b8c <_Z5DoMuljPhPKhP6VMExec+0x37c> */
/* @0x00e5878 b 0xe5890 <_Z5DoMuljPhPKhP6VMExec+0x80> */
/* @0x00e587c b 0xe5890 <_Z5DoMuljPhPKhP6VMExec+0x80> */
/* @0x00e5880 b 0xe5b8c <_Z5DoMuljPhPKhP6VMExec+0x37c> */
/* @0x00e5884 b 0xe5890 <_Z5DoMuljPhPKhP6VMExec+0x80> */
/* @0x00e5888 b 0xe5b44 <_Z5DoMuljPhPKhP6VMExec+0x334> */
/* @0x00e588c b 0xe5890 <_Z5DoMuljPhPKhP6VMExec+0x80> */
/* 新 sp 初值 r4 = opA 槽 + sizeB */
/* @0x00e5890 add r4, r9, #4 */
/* ---- 103 路消费表（cmp #102）：结果槽 r5 / 释放槽 r6 / 新 sp ---- */
/* @0x00e5894 cmp r5, #102 */
/* @0x00e5898 addls pc, pc, r5, lsl #2 */
/* @0x00e589c b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e58a0 b 0xe5b34 <_Z5DoMuljPhPKhP6VMExec+0x324> */
/* @0x00e58a4 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e58a8 b 0xe5b34 <_Z5DoMuljPhPKhP6VMExec+0x324> */
/* @0x00e58ac b 0xe5b34 <_Z5DoMuljPhPKhP6VMExec+0x324> */
/* @0x00e58b0 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e58b4 b 0xe5b24 <_Z5DoMuljPhPKhP6VMExec+0x314> */
/* @0x00e58b8 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e58bc b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e58c0 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e58c4 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e58c8 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e58cc b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e58d0 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e58d4 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e58d8 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e58dc b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e58e0 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e58e4 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e58e8 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e58ec b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e58f0 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e58f4 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e58f8 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e58fc b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e5900 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e5904 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e5908 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e590c b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e5910 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e5914 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e5918 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e591c b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e5920 b 0xe5b34 <_Z5DoMuljPhPKhP6VMExec+0x324> */
/* @0x00e5924 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e5928 b 0xe5a3c <_Z5DoMuljPhPKhP6VMExec+0x22c> */
/* @0x00e592c b 0xe5b34 <_Z5DoMuljPhPKhP6VMExec+0x324> */
/* @0x00e5930 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e5934 b 0xe5b24 <_Z5DoMuljPhPKhP6VMExec+0x314> */
/* @0x00e5938 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e593c b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e5940 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e5944 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e5948 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e594c b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e5950 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e5954 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e5958 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e595c b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e5960 b 0xe5b34 <_Z5DoMuljPhPKhP6VMExec+0x324> */
/* @0x00e5964 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e5968 b 0xe5b34 <_Z5DoMuljPhPKhP6VMExec+0x324> */
/* @0x00e596c b 0xe5b34 <_Z5DoMuljPhPKhP6VMExec+0x324> */
/* @0x00e5970 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e5974 b 0xe5b24 <_Z5DoMuljPhPKhP6VMExec+0x314> */
/* @0x00e5978 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e597c b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e5980 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e5984 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e5988 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e598c b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e5990 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e5994 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e5998 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e599c b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e59a0 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e59a4 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e59a8 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e59ac b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e59b0 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e59b4 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e59b8 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e59bc b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e59c0 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e59c4 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e59c8 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e59cc b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e59d0 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e59d4 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e59d8 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e59dc b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e59e0 b 0xe5b24 <_Z5DoMuljPhPKhP6VMExec+0x314> */
/* @0x00e59e4 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e59e8 b 0xe5b24 <_Z5DoMuljPhPKhP6VMExec+0x314> */
/* @0x00e59ec b 0xe5b24 <_Z5DoMuljPhPKhP6VMExec+0x314> */
/* @0x00e59f0 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e59f4 b 0xe5b24 <_Z5DoMuljPhPKhP6VMExec+0x314> */
/* @0x00e59f8 b 0xe5b24 <_Z5DoMuljPhPKhP6VMExec+0x314> */
/* @0x00e59fc b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e5a00 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e5a04 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e5a08 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e5a0c b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e5a10 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e5a14 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e5a18 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e5a1c b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e5a20 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e5a24 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e5a28 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e5a2c b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e5a30 b 0xe5be8 <_Z5DoMuljPhPKhP6VMExec+0x3d8> */
/* @0x00e5a34 b 0xe5b24 <_Z5DoMuljPhPKhP6VMExec+0x314> */
/* @0x00e5a38 b 0xe5a3c <_Z5DoMuljPhPKhP6VMExec+0x22c> */
/* pair=34 或 102：结果 4 字节，回退 4 ---- */
/* @0x00e5a3c sub r4, r4, #4 */
/* @0x00e5a40 mov r6, #0 */
/* @0x00e5a44 mov r5, r4 */
/* ---- 52 路算术表（cmp #51）---- */
/* @0x00e5a48 cmp r7, #51 */
/* @0x00e5a4c addls pc, pc, r7, lsl #2 */
/* @0x00e5a50 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5a54 b 0xe5ca8 <_Z5DoMuljPhPKhP6VMExec+0x498> */
/* @0x00e5a58 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5a5c b 0xe5c8c <_Z5DoMuljPhPKhP6VMExec+0x47c> */
/* @0x00e5a60 b 0xe5d98 <_Z5DoMuljPhPKhP6VMExec+0x588> */
/* @0x00e5a64 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5a68 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5a6c b 0xe5cf4 <_Z5DoMuljPhPKhP6VMExec+0x4e4> */
/* @0x00e5a70 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5a74 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5a78 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5a7c b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5a80 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5a84 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5a88 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5a8c b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5a90 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5a94 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5a98 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5a9c b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5aa0 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5aa4 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5aa8 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5aac b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5ab0 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5ab4 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5ab8 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5abc b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5ac0 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5ac4 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5ac8 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5acc b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5ad0 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5ad4 b 0xe5cd8 <_Z5DoMuljPhPKhP6VMExec+0x4c8> */
/* @0x00e5ad8 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5adc b 0xe5cc0 <_Z5DoMuljPhPKhP6VMExec+0x4b0> */
/* @0x00e5ae0 b 0xe5c64 <_Z5DoMuljPhPKhP6VMExec+0x454> */
/* @0x00e5ae4 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5ae8 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5aec b 0xe5cf4 <_Z5DoMuljPhPKhP6VMExec+0x4e4> */
/* @0x00e5af0 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5af4 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5af8 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5afc b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5b00 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5b04 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5b08 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5b0c b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5b10 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5b14 b 0xe5c44 <_Z5DoMuljPhPKhP6VMExec+0x434> */
/* @0x00e5b18 b 0xe5db8 <_Z5DoMuljPhPKhP6VMExec+0x5a8> */
/* @0x00e5b1c b 0xe5c30 <_Z5DoMuljPhPKhP6VMExec+0x420> */
/* @0x00e5b20 b 0xe5bf4 <_Z5DoMuljPhPKhP6VMExec+0x3e4> */
/* pair∈{5,37,53,80,82,83,85,86,101}：间接路径，回退 16 并释放 RValue ---- */
/* @0x00e5b24 sub r6, r4, #16 */
/* @0x00e5b28 mov r5, r6 */
/* @0x00e5b2c mov r4, r6 */
/* @0x00e5b30 b 0xe5a48 <_Z5DoMuljPhPKhP6VMExec+0x238> */
/* 8 字节结果：回退 8 ---- */
/* @0x00e5b34 sub r4, r4, #8 */
/* @0x00e5b38 mov r6, #0 */
/* @0x00e5b3c mov r5, r4 */
/* @0x00e5b40 b 0xe5a48 <_Z5DoMuljPhPKhP6VMExec+0x238> */
/* kindB=5：按 [opB+0xc] 的 tag 反推 kindB（改写高半字节） */
/* @0x00e5b44 ldr r2, [r9, #0xc] */
/* @0x00e5b48 cmp r2, #13 */
/* @0x00e5b4c addls pc, pc, r2, lsl #2 */
/* @0x00e5b50 b 0xe6070 <_Z5DoMuljPhPKhP6VMExec+0x860> */
/* @0x00e5b54 b 0xe5eec <_Z5DoMuljPhPKhP6VMExec+0x6dc> */
/* @0x00e5b58 b 0xe5ee0 <_Z5DoMuljPhPKhP6VMExec+0x6d0> */
/* @0x00e5b5c b 0xe6070 <_Z5DoMuljPhPKhP6VMExec+0x860> */
/* @0x00e5b60 b 0xe5ec4 <_Z5DoMuljPhPKhP6VMExec+0x6b4> */
/* @0x00e5b64 b 0xe6070 <_Z5DoMuljPhPKhP6VMExec+0x860> */
/* @0x00e5b68 b 0xe5ea8 <_Z5DoMuljPhPKhP6VMExec+0x698> */
/* @0x00e5b6c b 0xe6070 <_Z5DoMuljPhPKhP6VMExec+0x860> */
/* @0x00e5b70 b 0xe5e9c <_Z5DoMuljPhPKhP6VMExec+0x68c> */
/* @0x00e5b74 b 0xe6070 <_Z5DoMuljPhPKhP6VMExec+0x860> */
/* @0x00e5b78 b 0xe6070 <_Z5DoMuljPhPKhP6VMExec+0x860> */
/* @0x00e5b7c b 0xe5e8c <_Z5DoMuljPhPKhP6VMExec+0x67c> */
/* @0x00e5b80 b 0xe6070 <_Z5DoMuljPhPKhP6VMExec+0x860> */
/* @0x00e5b84 b 0xe6070 <_Z5DoMuljPhPKhP6VMExec+0x860> */
/* @0x00e5b88 b 0xe5eec <_Z5DoMuljPhPKhP6VMExec+0x6dc> */
/* kindB∈{0,3}：新 sp r4 = opB 槽 + 8 ---- */
/* @0x00e5b8c add r4, r9, #8 */
/* @0x00e5b90 b 0xe5894 <_Z5DoMuljPhPKhP6VMExec+0x84> */
/* kindA=5：按 [base+0xc] 的 tag 反推 kindA（改写低半字节） */
/* @0x00e5b94 ldr r2, [r1, #0xc] */
/* @0x00e5b98 cmp r2, #13 */
/* @0x00e5b9c addls pc, pc, r2, lsl #2 */
/* @0x00e5ba0 b 0xe608c <_Z5DoMuljPhPKhP6VMExec+0x87c> */
/* @0x00e5ba4 b 0xe6028 <_Z5DoMuljPhPKhP6VMExec+0x818> */
/* @0x00e5ba8 b 0xe601c <_Z5DoMuljPhPKhP6VMExec+0x80c> */
/* @0x00e5bac b 0xe5ffc <_Z5DoMuljPhPKhP6VMExec+0x7ec> */
/* @0x00e5bb0 b 0xe6050 <_Z5DoMuljPhPKhP6VMExec+0x840> */
/* @0x00e5bb4 b 0xe608c <_Z5DoMuljPhPKhP6VMExec+0x87c> */
/* @0x00e5bb8 b 0xe6030 <_Z5DoMuljPhPKhP6VMExec+0x820> */
/* @0x00e5bbc b 0xe608c <_Z5DoMuljPhPKhP6VMExec+0x87c> */
/* @0x00e5bc0 b 0xe5ff0 <_Z5DoMuljPhPKhP6VMExec+0x7e0> */
/* @0x00e5bc4 b 0xe608c <_Z5DoMuljPhPKhP6VMExec+0x87c> */
/* @0x00e5bc8 b 0xe608c <_Z5DoMuljPhPKhP6VMExec+0x87c> */
/* @0x00e5bcc b 0xe5fe0 <_Z5DoMuljPhPKhP6VMExec+0x7d0> */
/* @0x00e5bd0 b 0xe608c <_Z5DoMuljPhPKhP6VMExec+0x87c> */
/* @0x00e5bd4 b 0xe608c <_Z5DoMuljPhPKhP6VMExec+0x87c> */
/* @0x00e5bd8 b 0xe6028 <_Z5DoMuljPhPKhP6VMExec+0x818> */
/* kindA∈{0,3}：opB 槽 = base+8（opA 占 8 字节） */
/* @0x00e5bdc add r9, r1, #8 */
/* @0x00e5be0 mov r7, r5 */
/* @0x00e5be4 b 0xe5864 <_Z5DoMuljPhPKhP6VMExec+0x54> */
/* 非法 pair：结果槽/释放槽清零，随后由算术表报错 ---- */
/* @0x00e5be8 mov r5, #0 */
/* @0x00e5bec mov r6, r5 */
/* @0x00e5bf0 b 0xe5a48 <_Z5DoMuljPhPKhP6VMExec+0x238> */
/* pair 51 (int64,int64)：umull + mla 全 64 位乘，结果 tag 10 ---- */
/* @0x00e5bf4 ldr r1, [r8, #0x4] */
/* @0x00e5bf8 mov r12, #10 */
/* @0x00e5bfc ldr r2, [r9] */
/* @0x00e5c00 ldr r3, [r8] */
/* @0x00e5c04 ldr r0, [r9, #0x4] */
/* @0x00e5c08 mul r1, r2, r1 */
/* @0x00e5c0c mla r1, r3, r0, r1 */
/* @0x00e5c10 umull r2, r3, r2, r3 */
/* @0x00e5c14 add r3, r1, r3 */
/* @0x00e5c18 strd r2, r3, [r5] */
/* 收尾：写结果 tag（r12）→ 返回 r4 ---- */
/* @0x00e5c1c cmp r6, #0 */
/* @0x00e5c20 strne r12, [r6, #0xc] */
/* @0x00e5c24 mov r0, r4 */
/* @0x00e5c28 add sp, sp, #72 */
/* @0x00e5c2c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* pair 50 (int64,int32)：int64*int32 ---- */
/* @0x00e5c30 ldr r3, [r8] */
/* @0x00e5c34 mov r12, #10 */
/* @0x00e5c38 ldr r2, [r9] */
/* @0x00e5c3c asr r1, r3, #31 */
/* @0x00e5c40 b 0xe5c04 <_Z5DoMuljPhPKhP6VMExec+0x3f4> */
/* pair 48 (int64,real)：__floatdidf 后 vmul.f64 ---- */
/* @0x00e5c44 ldrd r0, r1, [r9] */
/* @0x00e5c48 bl 0x319164 <__floatdidf> */
/* @0x00e5c4c vldr d7, [r8] */
/* @0x00e5c50 mov r12, #0 */
/* @0x00e5c54 vmov d6, r0, r1 */
/* @0x00e5c58 vmul.f64 d7, d6, d7 */
/* @0x00e5c5c vstr d7, [r5] */
/* @0x00e5c60 b 0xe5c1c <_Z5DoMuljPhPKhP6VMExec+0x40c> */
/* pair 35 (int32,int64)：umull+mla ---- */
/* @0x00e5c64 ldr r3, [r9] */
/* @0x00e5c68 mov r12, #10 */
/* @0x00e5c6c ldm r8, {r2, r7} */
/* @0x00e5c70 asr r1, r3, #31 */
/* @0x00e5c74 mul r0, r3, r7 */
/* @0x00e5c78 mla r1, r2, r1, r0 */
/* @0x00e5c7c umull r2, r3, r2, r3 */
/* @0x00e5c80 add r3, r1, r3 */
/* @0x00e5c84 strd r2, r3, [r5] */
/* @0x00e5c88 b 0xe5c1c <_Z5DoMuljPhPKhP6VMExec+0x40c> */
/* pair 2 (real,int32)：opA vcvt.f64.s32 后 vmul ---- */
/* @0x00e5c8c vldr s14, [r8] */
/* @0x00e5c90 vcvt.f64.s32 d7, s14 */
/* @0x00e5c94 vldr d6, [r9] */
/* @0x00e5c98 mov r12, #0 */
/* @0x00e5c9c vmul.f64 d7, d6, d7 */
/* @0x00e5ca0 vstr d7, [r5] */
/* @0x00e5ca4 b 0xe5c1c <_Z5DoMuljPhPKhP6VMExec+0x40c> */
/* pair 0 (real,real)：vmul.f64 ---- */
/* @0x00e5ca8 vldr d6, [r9] */
/* @0x00e5cac vldr d7, [r8] */
/* @0x00e5cb0 vmul.f64 d7, d6, d7 */
/* @0x00e5cb4 mov r12, #0 */
/* @0x00e5cb8 vstr d7, [r5] */
/* @0x00e5cbc b 0xe5c1c <_Z5DoMuljPhPKhP6VMExec+0x40c> */
/* pair 34 (int32,int32)：mul，结果 tag 7 ---- */
/* @0x00e5cc0 ldr r3, [r9] */
/* @0x00e5cc4 mov r12, #7 */
/* @0x00e5cc8 ldr r2, [r8] */
/* @0x00e5ccc mul r3, r2, r3 */
/* @0x00e5cd0 str r3, [r5] */
/* @0x00e5cd4 b 0xe5c1c <_Z5DoMuljPhPKhP6VMExec+0x40c> */
/* pair 32 (int32,real)：opB vcvt 后 vmul ---- */
/* @0x00e5cd8 vldr s14, [r9] */
/* @0x00e5cdc vcvt.f64.s32 d7, s14 */
/* @0x00e5ce0 vldr d6, [r8] */
/* @0x00e5ce4 mov r12, #0 */
/* @0x00e5ce8 vmul.f64 d7, d7, d6 */
/* @0x00e5cec vstr d7, [r5] */
/* @0x00e5cf0 b 0xe5c1c <_Z5DoMuljPhPKhP6VMExec+0x40c> */
/* pair 6/38 字符串重复：取 opA 的 YYStr 数据指针，按 opB 的次数复制 ---- */
/* @0x00e5cf4 ldr r10, [r8] */
/* @0x00e5cf8 cmp r10, #0 */
/* @0x00e5cfc ldrne r8, [r10] */
/* @0x00e5d00 moveq r8, r10 */
/* @0x00e5d04 asrs r7, r7, #4 */
/* @0x00e5d08 beq 0xe60c0 <_Z5DoMuljPhPKhP6VMExec+0x8b0> */
/* @0x00e5d0c cmp r7, #2 */
/* @0x00e5d10 beq 0xe5ef4 <_Z5DoMuljPhPKhP6VMExec+0x6e4> */
/* 次数 kind 既非 real 也非 int32：Alloc(1) 走「空串」兜底 ---- */
/* @0x00e5d14 ldr r1, [pc, #0x460] */
/* @0x00e5d18 mov r0, #1 */
/* @0x00e5d1c mov r3, r0 */
/* @0x00e5d20 movw r2, #0xb54 */
/* @0x00e5d24 add r1, pc, r1 */
/* @0x00e5d28 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x00e5d2c mov r3, #0 */
/* @0x00e5d30 mov r9, r0 */
/* @0x00e5d34 strb r3, [r0] */
/* operator new(12) 造 {data, refcount=1, len=8}，结果 tag=1(string) ---- */
/* @0x00e5d38 mov r0, #12 */
/* @0x00e5d3c mov r8, #1 */
/* @0x00e5d40 bl 0x27c524 <_Znwj> */
/* @0x00e5d44 mov r7, r0 */
/* @0x00e5d48 mov r0, r9 */
/* @0x00e5d4c bl 0xb6538 <strlen@plt> */
/* @0x00e5d50 str r0, [r7, #0x8] */
/* @0x00e5d54 mov r0, r9 */
/* @0x00e5d58 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x00e5d5c stm r7, {r0, r8} */
/* @0x00e5d60 mov r0, r9 */
/* 结果写 [r5]（回退后的新 sp），随后释放临时串 ---- */
/* @0x00e5d64 str r7, [r5] */
/* @0x00e5d68 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x00e5d6c cmp r10, #0 */
/* @0x00e5d70 beq 0xe5d90 <_Z5DoMuljPhPKhP6VMExec+0x580> */
/* 原串引用计数减 1（LOCK_RVALUE_MUTEX） */
/* @0x00e5d74 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x00e5d78 ldr r5, [r10, #0x4] */
/* @0x00e5d7c sub r5, r5, #1 */
/* @0x00e5d80 str r5, [r10, #0x4] */
/* @0x00e5d84 cmp r5, #0 */
/* @0x00e5d88 beq 0xe60d0 <_Z5DoMuljPhPKhP6VMExec+0x8c0> */
/* @0x00e5d8c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x00e5d90 mov r12, #1 */
/* @0x00e5d94 b 0xe5c1c <_Z5DoMuljPhPKhP6VMExec+0x40c> */
/* pair 3 (real,int64)：__floatdidf 后 vmul ---- */
/* @0x00e5d98 ldrd r0, r1, [r8] */
/* @0x00e5d9c bl 0x319164 <__floatdidf> */
/* @0x00e5da0 vldr d7, [r9] */
/* @0x00e5da4 mov r12, #0 */
/* @0x00e5da8 vmov d5, r0, r1 */
/* @0x00e5dac vmul.f64 d7, d7, d5 */
/* @0x00e5db0 vstr d7, [r5] */
/* @0x00e5db4 b 0xe5c1c <_Z5DoMuljPhPKhP6VMExec+0x40c> */
/* 算术表默认项：VMError("DoMul :: Execution Error") ---- */
/* @0x00e5db8 ldr r1, [pc, #0x3c0] */
/* @0x00e5dbc mov r0, r3 */
/* @0x00e5dc0 add r1, pc, r1 */
/* @0x00e5dc4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00e5dc8 mov r12, #0 */
/* @0x00e5dcc b 0xe5c1c <_Z5DoMuljPhPKhP6VMExec+0x40c> */
/* ---- 常量路径：boxType(帧+0x18,kindA,base) / boxType(帧+8,kindB,前次返回) ---- */
/* @0x00e5dd0 add r6, sp, #24 */
/* @0x00e5dd4 mov r2, r1 */
/* @0x00e5dd8 and r1, r5, #15 */
/* @0x00e5ddc add r7, sp, #8 */
/* @0x00e5de0 mov r0, r6 */
/* @0x00e5de4 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0x00e5de8 lsr r1, r5, #4 */
/* @0x00e5dec mov r2, r0 */
/* @0x00e5df0 mov r0, r7 */
/* @0x00e5df4 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* 校验两枚 RValue 的 +12 字低 24 位是否全 1（0x00FFFFFF = 未解析引用标记） ---- */
/* @0x00e5df8 ldr r3, [sp, #0x14] */
/* @0x00e5dfc mvn r12, #-16777216 */
/* @0x00e5e00 and r3, r3, r12 */
/* @0x00e5e04 cmp r3, r12 */
/* @0x00e5e08 mov r4, r0 */
/* @0x00e5e0c beq 0xe6128 <_Z5DoMuljPhPKhP6VMExec+0x918> */
/* @0x00e5e10 ldr r3, [sp, #0x24] */
/* @0x00e5e14 bic r3, r3, #-16777216 */
/* @0x00e5e18 cmp r3, r12 */
/* @0x00e5e1c beq 0xe60ac <_Z5DoMuljPhPKhP6VMExec+0x89c> */
/* F_JS_ToNumber(帧+0x28, 帧+8) 与 F_JS_ToNumber(帧+0x38, 帧+0x18) ---- */
/* @0x00e5e20 add r5, sp, #40 */
/* @0x00e5e24 mov r1, r7 */
/* @0x00e5e28 mov r2, #0 */
/* @0x00e5e2c mov r3, #0 */
/* @0x00e5e30 mov r0, r5 */
/* @0x00e5e34 str r12, [sp, #0x34] */
/* @0x00e5e38 str r12, [sp, #0x44] */
/* @0x00e5e3c mov r12, #0 */
/* @0x00e5e40 strd r2, r3, [sp, #40] */
/* @0x00e5e44 strd r2, r3, [sp, #56] */
/* @0x00e5e48 str r12, [sp, #0x30] */
/* @0x00e5e4c str r12, [sp, #0x40] */
/* F_JS_ToNumber(RValue&, RValue&)：0=ok 1=TypeError */
/* @0x00e5e50 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x00e5e54 cmp r0, #1 */
/* @0x00e5e58 beq 0xe613c <_Z5DoMuljPhPKhP6VMExec+0x92c> */
/* @0x00e5e5c cmp r0, #0 */
/* @0x00e5e60 beq 0xe5f48 <_Z5DoMuljPhPKhP6VMExec+0x738> */
/* @0x00e5e64 ldr r3, [sp, #0x34] */
/* 释放中间 RValue（refcount 检查 bic #3） */
/* @0x00e5e68 sub r3, r3, #1 */
/* @0x00e5e6c bic r3, r3, #-16777216 */
/* @0x00e5e70 bic r3, r3, #3 */
/* @0x00e5e74 cmp r3, #0 */
/* @0x00e5e78 bne 0xe5c24 <_Z5DoMuljPhPKhP6VMExec+0x414> */
/* @0x00e5e7c mov r0, r5 */
/* @0x00e5e80 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x00e5e84 mov r0, r4 */
/* @0x00e5e88 b 0xe5c28 <_Z5DoMuljPhPKhP6VMExec+0x418> */
/* 间接 kindB：tag 10 → kindB=3（0x30） */
/* @0x00e5e8c and r7, r7, #15 */
/* @0x00e5e90 orr r7, r7, #48 */
/* @0x00e5e94 add r4, r9, #16 */
/* @0x00e5e98 b 0xe5894 <_Z5DoMuljPhPKhP6VMExec+0x84> */
/* 间接 kindB：tag 7 → kindB=2（0x20） */
/* @0x00e5e9c and r7, r7, #15 */
/* @0x00e5ea0 orr r7, r7, #32 */
/* @0x00e5ea4 b 0xe5e94 <_Z5DoMuljPhPKhP6VMExec+0x684> */
/* 间接 kindB：tag 5 → "undefined value" ---- */
/* @0x00e5ea8 ldr r1, [pc, #0x2d4] */
/* @0x00e5eac mov r0, r3 */
/* @0x00e5eb0 str r3, [sp, #0x4] */
/* @0x00e5eb4 add r1, pc, r1 */
/* @0x00e5eb8 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00e5ebc ldr r3, [sp, #0x4] */
/* @0x00e5ec0 b 0xe5e94 <_Z5DoMuljPhPKhP6VMExec+0x684> */
/* 间接 kindB：tag 3 → "illegal pointer use" ---- */
/* @0x00e5ec4 ldr r1, [pc, #0x2bc] */
/* @0x00e5ec8 mov r0, r3 */
/* @0x00e5ecc str r3, [sp, #0x4] */
/* @0x00e5ed0 add r1, pc, r1 */
/* @0x00e5ed4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00e5ed8 ldr r3, [sp, #0x4] */
/* @0x00e5edc b 0xe5e94 <_Z5DoMuljPhPKhP6VMExec+0x684> */
/* 间接 kindB：tag 1 → kindB=6（0x60，字符串） */
/* @0x00e5ee0 and r7, r7, #15 */
/* @0x00e5ee4 orr r7, r7, #96 */
/* @0x00e5ee8 b 0xe5e94 <_Z5DoMuljPhPKhP6VMExec+0x684> */
/* 间接 kindB：tag 0/13 → kindB=0（real） */
/* @0x00e5eec and r7, r7, #15 */
/* @0x00e5ef0 b 0xe5e94 <_Z5DoMuljPhPKhP6VMExec+0x684> */
/* 重复 count 次：Alloc(len*count+1) + strcat 循环 ---- */
/* @0x00e5ef4 ldr r7, [r9] */
/* @0x00e5ef8 mov r0, r8 */
/* @0x00e5efc bl 0xb6538 <strlen@plt> */
/* @0x00e5f00 ldr r1, [pc, #0x284] */
/* @0x00e5f04 mov r3, #1 */
/* @0x00e5f08 movw r2, #0xb54 */
/* @0x00e5f0c add r1, pc, r1 */
/* @0x00e5f10 mul r0, r7, r0 */
/* @0x00e5f14 add r0, r0, r3 */
/* @0x00e5f18 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x00e5f1c cmp r7, #0 */
/* @0x00e5f20 mov r3, #0 */
/* @0x00e5f24 mov r9, r0 */
/* @0x00e5f28 strb r3, [r0] */
/* @0x00e5f2c ble 0xe5d38 <_Z5DoMuljPhPKhP6VMExec+0x528> */
/* @0x00e5f30 mov r0, r9 */
/* @0x00e5f34 mov r1, r8 */
/* @0x00e5f38 bl 0xb6628 <strcat@plt> */
/* @0x00e5f3c subs r7, r7, #1 */
/* @0x00e5f40 bne 0xe5f30 <_Z5DoMuljPhPKhP6VMExec+0x720> */
/* @0x00e5f44 b 0xe5d38 <_Z5DoMuljPhPKhP6VMExec+0x528> */
/* @0x00e5f48 add r7, sp, #56 */
/* @0x00e5f4c mov r1, r6 */
/* @0x00e5f50 mov r0, r7 */
/* @0x00e5f54 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x00e5f58 cmp r0, #1 */
/* @0x00e5f5c beq 0xe6158 <_Z5DoMuljPhPKhP6VMExec+0x948> */
/* @0x00e5f60 cmp r0, #0 */
/* @0x00e5f64 bne 0xe5e64 <_Z5DoMuljPhPKhP6VMExec+0x654> */
/* @0x00e5f68 str r0, [r4, #-0x4] */
/* @0x00e5f6c sub r6, r4, #16 */
/* @0x00e5f70 vldr d6, [sp, #40] */
/* @0x00e5f74 vldr d7, [sp, #56] */
/* @0x00e5f78 vmul.f64 d5, d6, d7 */
/* @0x00e5f7c ldr r1, [sp, #0x34] */
/* @0x00e5f80 sub r1, r1, #1 */
/* @0x00e5f84 bic r1, r1, #-16777216 */
/* @0x00e5f88 bic r1, r1, #3 */
/* @0x00e5f8c cmp r1, #0 */
/* @0x00e5f90 vmov r2, r3, d5 */
/* @0x00e5f94 vstr s10, [r4, #-16] */
/* @0x00e5f98 str r3, [r4, #-0xc] */
/* @0x00e5f9c beq 0xe614c <_Z5DoMuljPhPKhP6VMExec+0x93c> */
/* @0x00e5fa0 ldr r1, [sp, #0x44] */
/* @0x00e5fa4 mov r3, #0 */
/* @0x00e5fa8 str r3, [sp, #0x30] */
/* @0x00e5fac mov r2, #5 */
/* @0x00e5fb0 sub r1, r1, #1 */
/* @0x00e5fb4 str r3, [sp, #0x28] */
/* @0x00e5fb8 bic r3, r1, #-16777216 */
/* @0x00e5fbc str r2, [sp, #0x34] */
/* @0x00e5fc0 bic r3, r3, #3 */
/* @0x00e5fc4 cmp r3, #0 */
/* @0x00e5fc8 movne r0, r6 */
/* @0x00e5fcc bne 0xe5c28 <_Z5DoMuljPhPKhP6VMExec+0x418> */
/* @0x00e5fd0 mov r0, r7 */
/* @0x00e5fd4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x00e5fd8 mov r0, r6 */
/* @0x00e5fdc b 0xe5c28 <_Z5DoMuljPhPKhP6VMExec+0x418> */
/* 间接 kindA：tag 10 → kindA=3，opB 槽回 base+16 ---- */
/* @0x00e5fe0 and r7, r7, #240 */
/* @0x00e5fe4 orr r7, r7, #3 */
/* @0x00e5fe8 add r9, r8, #16 */
/* @0x00e5fec b 0xe5864 <_Z5DoMuljPhPKhP6VMExec+0x54> */
/* 间接 kindA：tag 7 → kindA=2 ---- */
/* @0x00e5ff0 and r7, r7, #240 */
/* @0x00e5ff4 orr r7, r7, #2 */
/* @0x00e5ff8 b 0xe5fe8 <_Z5DoMuljPhPKhP6VMExec+0x7d8> */
/* 间接 kindA：tag 2 → "illegal array use" ---- */
/* @0x00e5ffc ldr r1, [pc, #0x18c] */
/* @0x00e6000 mov r0, r3 */
/* @0x00e6004 str r3, [sp, #0x4] */
/* @0x00e6008 mov r7, r5 */
/* @0x00e600c add r1, pc, r1 */
/* @0x00e6010 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00e6014 ldr r3, [sp, #0x4] */
/* @0x00e6018 b 0xe5fe8 <_Z5DoMuljPhPKhP6VMExec+0x7d8> */
/* 间接 kindA：tag 1 → kindA=6（字符串） ---- */
/* @0x00e601c and r7, r7, #240 */
/* @0x00e6020 orr r7, r7, #6 */
/* @0x00e6024 b 0xe5fe8 <_Z5DoMuljPhPKhP6VMExec+0x7d8> */
/* 间接 kindA：tag 0/13 → kindA=0 ---- */
/* @0x00e6028 and r7, r5, #240 */
/* @0x00e602c b 0xe5fe8 <_Z5DoMuljPhPKhP6VMExec+0x7d8> */
/* 间接 kindA：tag 5 → "undefined value" ---- */
/* @0x00e6030 ldr r1, [pc, #0x15c] */
/* @0x00e6034 mov r0, r3 */
/* @0x00e6038 str r3, [sp, #0x4] */
/* @0x00e603c mov r7, r5 */
/* @0x00e6040 add r1, pc, r1 */
/* @0x00e6044 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00e6048 ldr r3, [sp, #0x4] */
/* @0x00e604c b 0xe5fe8 <_Z5DoMuljPhPKhP6VMExec+0x7d8> */
/* 间接 kindA：tag 3 → "illegal pointer use" ---- */
/* @0x00e6050 ldr r1, [pc, #0x140] */
/* @0x00e6054 mov r0, r3 */
/* @0x00e6058 str r3, [sp, #0x4] */
/* @0x00e605c mov r7, r5 */
/* @0x00e6060 add r1, pc, r1 */
/* @0x00e6064 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00e6068 ldr r3, [sp, #0x4] */
/* @0x00e606c b 0xe5fe8 <_Z5DoMuljPhPKhP6VMExec+0x7d8> */
/* 间接公用："Variable is malformed" ---- */
/* @0x00e6070 ldr r1, [pc, #0x124] */
/* @0x00e6074 mov r0, r3 */
/* @0x00e6078 str r3, [sp, #0x4] */
/* @0x00e607c add r1, pc, r1 */
/* @0x00e6080 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00e6084 ldr r3, [sp, #0x4] */
/* @0x00e6088 b 0xe5e94 <_Z5DoMuljPhPKhP6VMExec+0x684> */
/* @0x00e608c ldr r1, [pc, #0x10c] */
/* @0x00e6090 mov r0, r3 */
/* @0x00e6094 str r3, [sp, #0x4] */
/* @0x00e6098 mov r7, r5 */
/* @0x00e609c add r1, pc, r1 */
/* @0x00e60a0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0x00e60a4 ldr r3, [sp, #0x4] */
/* @0x00e60a8 b 0xe5fe8 <_Z5DoMuljPhPKhP6VMExec+0x7d8> */
/* opA 未解析引用 → JSThrowReferenceError("could not find lhs variable on multiply") ---- */
/* @0x00e60ac ldr r0, [pc, #0xf0] */
/* @0x00e60b0 add r0, pc, r0 */
/* @0x00e60b4 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0x00e60b8 mov r0, r4 */
/* @0x00e60bc b 0xe5c28 <_Z5DoMuljPhPKhP6VMExec+0x418> */
/* 次数来自 opB 的 double：vcvt.s32.f64 取整 ---- */
/* @0x00e60c0 vldr d7, [r9] */
/* @0x00e60c4 vcvt.s32.f64 s11, d7 */
/* @0x00e60c8 vmov r7, s11 */
/* @0x00e60cc b 0xe5ef8 <_Z5DoMuljPhPKhP6VMExec+0x6e8> */
/* 引用计数归零：YYFree(data) + _RefThing::dec + operator delete ---- */
/* @0x00e60d0 ldr r0, [r10] */
/* @0x00e60d4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x00e60d8 str r5, [r10] */
/* @0x00e60dc str r5, [r10, #0x8] */
/* @0x00e60e0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x00e60e4 ldr r5, [r10, #0x4] */
/* @0x00e60e8 sub r5, r5, #1 */
/* @0x00e60ec str r5, [r10, #0x4] */
/* @0x00e60f0 cmp r5, #0 */
/* @0x00e60f4 bne 0xe6118 <_Z5DoMuljPhPKhP6VMExec+0x908> */
/* @0x00e60f8 ldr r0, [r10] */
/* @0x00e60fc bl 0xcef90 <_Z6YYFreePKv> */
/* @0x00e6100 mov r0, r10 */
/* @0x00e6104 str r5, [r10] */
/* @0x00e6108 str r5, [r10, #0x8] */
/* @0x00e610c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x00e6110 mov r0, r10 */
/* @0x00e6114 bl 0x27d1d0 <_ZdlPv> */
/* @0x00e6118 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x00e611c mov r0, r10 */
/* @0x00e6120 bl 0x27d1d0 <_ZdlPv> */
/* @0x00e6124 b 0xe5d8c <_Z5DoMuljPhPKhP6VMExec+0x57c> */
/* opB 未解析引用 → 同一句 ReferenceError（字符串只有 lhs 版本） ---- */
/* @0x00e6128 ldr r0, [pc, #0x78] */
/* @0x00e612c add r0, pc, r0 */
/* @0x00e6130 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0x00e6134 mov r0, r4 */
/* @0x00e6138 b 0xe5c28 <_Z5DoMuljPhPKhP6VMExec+0x418> */
/* F_JS_ToNumber 失败 → JSThrowTypeError("Could not convert left-hand-side of '*' operator to a number") ---- */
/* @0x00e613c ldr r0, [pc, #0x68] */
/* @0x00e6140 add r0, pc, r0 */
/* @0x00e6144 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x00e6148 b 0xe5e64 <_Z5DoMuljPhPKhP6VMExec+0x654> */
/* @0x00e614c mov r0, r5 */
/* @0x00e6150 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x00e6154 b 0xe5fa0 <_Z5DoMuljPhPKhP6VMExec+0x790> */
/* 右侧失败 → "Could not convert right-hand-side of '*' operator to a number" ---- */
/* @0x00e6158 ldr r0, [pc, #0x50] */
/* @0x00e615c add r0, pc, r0 */
/* @0x00e6160 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x00e6164 b 0xe5e64 <_Z5DoMuljPhPKhP6VMExec+0x654> */
/* @0x00e6168 mov r7, r5 */
/* @0x00e616c mov r9, r1 */
/* @0x00e6170 b 0xe5864 <_Z5DoMuljPhPKhP6VMExec+0x54> */
/* @0x00e6174 mov r4, r9 */
/* @0x00e6178 b 0xe5894 <_Z5DoMuljPhPKhP6VMExec+0x84> */
/* @0x00e617c eoreq r12, r4, r8, asr r10 */
/* @0x00e6180 eoreq lr, r4, r0, asr #15 */
/* @0x00e6184 mlaeq r4, r0, r6, lr */
/* @0x00e6188 eoreq lr, r4, r0, ror #12 */
/* @0x00e618c eoreq r12, r4, r0, ror r8 */
/* @0x00e6190 eoreq lr, r4, r8, asr #10 */
/* @0x00e6194 eoreq lr, r4, r4, lsl #10 */
/* @0x00e6198 .word 0x0024e4d0 */
/* @0x00e619c eoreq lr, r4, r12, ror #9 */
/* @0x00e61a0 eoreq lr, r4, r12, asr #9 */
/* @0x00e61a4 eoreq lr, r4, r8, asr r4 */
/* @0x00e61a8 .word 0x0024e3dc */
/* @0x00e61ac .word 0x0024d0d4 */
/* @0x00e61b0 .word 0x0024d0f8 */
