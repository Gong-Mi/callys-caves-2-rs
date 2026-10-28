/* cally 逆向卡：DoAnd（原版 libyoyo.so，armv7）
 * @func 0xdef70 0xdf800 size 2196  549 条指令（含 literal 词）
 * 级别: 骨架（arg 位域 / 双格式码分派 / 10 条内核（含 bool）/ 全部错误分支已证；返回值口径未定，不升正文）
 * 符号: _Z5DoAndjPhPKhP6VMExec → uchar* DoAnd(uint32 arg, uchar* sp, const uchar* base, VMExec* exec)
 *
 * 已证（指令级）：
 *   慢路径开关 = bits[11:8] 任一非零：@0xdef70 tst r0, #3840 —— tst 0xF00；@0xdef88 bne 0xdefbc <_Z5DoAndjPhPKhP6VMExec+0x4c> —— bne 0xdefbc
 *   byte=(arg>>16)&0xFF=(Afmt<<4)|Bfmt（高 nibble=A）：@0xdef78 lsr r5, r0, #16 —— arg>>16；@0xdef8c uxtb r4, r5 —— uxtb；@0xdef90 and r2, r4, #15 —— 取低 nibble（B）
 *   表1 按 B 的格式码定 A 的地址：@0xdef98 addls pc, pc, r2, lsl #2 —— 7 项表；@0xdf05c add r10, r1, #8 —— B 8 字节 → A=arg2+8；@0xdf3ac add r10, r1, #4 —— B 4 字节 → A=arg2+4
 *   表2 按 A 的格式码算 r6=A+4 / A+8：@0xdf064 asr r2, r5, #4 —— asr #4；@0xdf06c addls pc, pc, r2, lsl #2 —— 第二级表；@0xdf3a4 add r6, r10, #8 —— r6=A+8
 *   B 从 [arg2] 读、A 从 arg2+4/arg2+8 读：@0xdf420 ldrd r0, r1, [r9] —— ldrd r0,r1,[r9] 取 B（实数内核）
 *   表3 按整字节（0..85）→ dest：@0xdf0a4 cmp r4, #85 —— 上界 85；@0xdf0a8 addls pc, pc, r4, lsl #2 —— 86 项表；逐项等价于 dest=A+size(A)−max(size(A),size(B))
 *   表4 按同一字节（0..68）→ 10 条内核（含 bool）：@0xdf214 cmp r5, #68 —— 上界 68；@0xdf218 addls pc, pc, r5, lsl #2 —— 69 项表
 *   结果 tag：0=double、7=int32、10=int64、13=bool，只在 r7≠0 时写 [r7+0xc]：@0xdf44c str r12, [r7, #0xc] —— 条件写
 *   bool×bool 走逻辑与并写 tag 13：@0xdf52c ldr r3, [r10] —— 入口；@0xdf534 beq 0xdf544 <_Z5DoAndjPhPKhP6VMExec+0x5d4> —— A==0 短路；@0xdf548 mov r12, #13 —— tag=13
 *   real×bool 与 real×int32 共用内核（4 与 2 同表项）：@0xdf458 ldrd r0, r1, [r10] —— (real,4字节) 内核；@0xdf41c ldr r4, [r10] —— (4字节,real) 内核
 *   int64×int64 双字 and（tag 10）：@0xdf4a8 and r2, r2, r0 —— 低字；@0xdf4ac and r3, r3, r1 —— 高字；@0xdf4a0 mov r12, #10 —— tag=10
 *   int32×int32 单字 and（tag 7）：@0xdf4e0 and r3, r2, r3 —— and；@0xdf4d8 mov r12, #7 —— tag=7
 *   慢路径 = boxType×2 + F_JS_ToInt32×2 + 32 位 and：@0xdf03c bl 0x24d5c8 <_Z12F_JS_ToInt32R6RValueS0_> —— F_JS_ToInt32
 *
 * 结论（新增 4 条硬事实）：
 *   1. DoAnd 与 DoXor 是同一模板的两个实例（位域、表结构、dest 规则、慢路径全同），差别只在 4 条内核里的
 *      eor→and、以及 bool 的组合面：DoAnd 允许 bool 与 real 混算（4 与 2 在 (real,·) 内核里同项、64 与 32 在 (·,real) 里同项），
 *      但 bool 与 int32 直接组合（36/66）不发射 → VMError；DoXor 则只有 (4,4)。
 *   2. 实数参与按位与时同样先 __fixdfdi 截断成 int64 再与（不按浮点位），结果 tag 仍是 0（double）。
 *   3. bool×bool 是**短路语义**的逻辑与：A==0 时直接把 A 写回，否则写 (B!=0)，tag 13；写回顺序保证
 *      A、B 都只读一次。
 *   4. 错误分支（含字符串组合）只写 tag 0 不写值，然后统一返回 r6。
 * open：
 *   · 0xdf778/0xdf798 两条 JS 文案写的是 "DoAdd - could not convert …"（复制粘贴自加法），与本函数名不符。
 *   · DoAnd 的 dest 表在 (4,·)/(·,4) 的少数组合上仍给 dest（如 69、84），而 DoShl 对同类组合直接没有 dest，
 *     说明发射规则不是一条公式，只能逐表核对；本卡已复算全部已列出项。
 *   · 返回值是"新 sp"还是"新 ip"未定；尾部 0xdf7c0..0xdf804 是 literal pool（objdump 译成 eoreq/mla），逐字保留。
 */
/* @0xdef70 tst r0, #3840 */
/* @0xdef74 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xdef78 lsr r5, r0, #16 */
/* @0xdef7c sub sp, sp, #68 */
/* @0xdef80 mov r9, r1 */
/* @0xdef84 mov r11, r3 */
/* @0xdef88 bne 0xdefbc <_Z5DoAndjPhPKhP6VMExec+0x4c> */
/* @0xdef8c uxtb r4, r5 */
/* @0xdef90 and r2, r4, #15 */
/* @0xdef94 cmp r2, #6 */
/* @0xdef98 addls pc, pc, r2, lsl #2   ——表：按 r2 0→0xdf05c, 1-2→0xdf3ac, 3→0xdf05c, 4→0xdf3ac, 5→0xdf3b8, 6→0xdf400 */
/* @0xdef9c b 0xdf7ac <_Z5DoAndjPhPKhP6VMExec+0x83c> */
/* @0xdefa0 b 0xdf05c <_Z5DoAndjPhPKhP6VMExec+0xec> */
/* @0xdefa4 b 0xdf3ac <_Z5DoAndjPhPKhP6VMExec+0x43c> */
/* @0xdefa8 b 0xdf3ac <_Z5DoAndjPhPKhP6VMExec+0x43c> */
/* @0xdefac b 0xdf05c <_Z5DoAndjPhPKhP6VMExec+0xec> */
/* @0xdefb0 b 0xdf3ac <_Z5DoAndjPhPKhP6VMExec+0x43c> */
/* @0xdefb4 b 0xdf3b8 <_Z5DoAndjPhPKhP6VMExec+0x448> */
/* @0xdefb8 b 0xdf400 <_Z5DoAndjPhPKhP6VMExec+0x490> */
/* @0xdefbc add r4, sp, #16 */
/* @0xdefc0 uxtb r5, r5 */
/* @0xdefc4 mov r2, r1 */
/* @0xdefc8 and r1, r5, #15 */
/* @0xdefcc mov r0, r4 */
/* @0xdefd0 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xdefd4 lsr r1, r5, #4 */
/* @0xdefd8 mov r2, r0 */
/* @0xdefdc mov r0, sp */
/* @0xdefe0 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xdefe4 ldr r3, [sp, #0xc] */
/* @0xdefe8 mvn r12, #-16777216 */
/* @0xdefec and r3, r3, r12 */
/* @0xdeff0 cmp r3, r12 */
/* @0xdeff4 mov r6, r0 */
/* @0xdeff8 beq 0xdf764 <_Z5DoAndjPhPKhP6VMExec+0x7f4> */
/* @0xdeffc ldr r3, [sp, #0x1c] */
/* @0xdf000 bic r3, r3, #-16777216 */
/* @0xdf004 cmp r3, r12 */
/* @0xdf008 beq 0xdf488 <_Z5DoAndjPhPKhP6VMExec+0x518> */
/* @0xdf00c add r5, sp, #32 */
/* @0xdf010 mov r1, sp */
/* @0xdf014 mov r2, #0 */
/* @0xdf018 mov r3, #0 */
/* @0xdf01c mov r0, r5 */
/* @0xdf020 str r12, [sp, #0x2c] */
/* @0xdf024 str r12, [sp, #0x3c] */
/* @0xdf028 mov r12, #0 */
/* @0xdf02c strd r2, r3, [sp, #32] */
/* @0xdf030 strd r2, r3, [sp, #48] */
/* @0xdf034 str r12, [sp, #0x28] */
/* @0xdf038 str r12, [sp, #0x38] */
/* @0xdf03c bl 0x24d5c8 <_Z12F_JS_ToInt32R6RValueS0_> */
/* @0xdf040 cmp r0, #1 */
/* @0xdf044 beq 0xdf778 <_Z5DoAndjPhPKhP6VMExec+0x808> */
/* @0xdf048 cmp r0, #0 */
/* @0xdf04c beq 0xdf590 <_Z5DoAndjPhPKhP6VMExec+0x620> */
/* @0xdf050 mov r0, r6 */
/* @0xdf054 add sp, sp, #68 */
/* @0xdf058 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xdf05c add r10, r1, #8   ——Bfmt 0/3 → A=arg2+8 */
/* @0xdf060 mov r5, r4 */
/* @0xdf064 asr r2, r5, #4   ——取 A 的 nibble */
/* @0xdf068 cmp r2, #6 */
/* @0xdf06c addls pc, pc, r2, lsl #2   ——表：按 r2 0→0xdf3a4, 1-2→0xdf39c, 3→0xdf3a4, 4→0xdf39c, 5→0xdf354, 6→0xdf090 */
/* @0xdf070 b 0xdf7b8 <_Z5DoAndjPhPKhP6VMExec+0x848> */
/* @0xdf074 b 0xdf3a4 <_Z5DoAndjPhPKhP6VMExec+0x434> */
/* @0xdf078 b 0xdf39c <_Z5DoAndjPhPKhP6VMExec+0x42c> */
/* @0xdf07c b 0xdf39c <_Z5DoAndjPhPKhP6VMExec+0x42c> */
/* @0xdf080 b 0xdf3a4 <_Z5DoAndjPhPKhP6VMExec+0x434> */
/* @0xdf084 b 0xdf39c <_Z5DoAndjPhPKhP6VMExec+0x42c> */
/* @0xdf088 b 0xdf354 <_Z5DoAndjPhPKhP6VMExec+0x3e4> */
/* @0xdf08c b 0xdf090 <_Z5DoAndjPhPKhP6VMExec+0x120> */
/* @0xdf090 ldr r1, [pc, #0x728]   ——Afmt=6 → VMError */
/* @0xdf094 mov r0, r11 */
/* @0xdf098 mov r6, r10 */
/* @0xdf09c add r1, pc, r1 */
/* @0xdf0a0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdf0a4 cmp r4, #85 */
/* @0xdf0a8 addls pc, pc, r4, lsl #2   ——表：按 r4 0→0xdf344, 1→0xdf47c, 2-3→0xdf344, 4→0xdf47c, 5→0xdf334, 6-31→0xdf47c, 32→0xdf344, 33→0xdf47c, 34→0xdf208, 35→0xdf344, 36→0xdf47c, 37→0xdf334, 38-47→0xdf47c, 48→0xdf344, 49→0xdf47c, 50-51→0xdf344, 52→0xdf47c, 53→0xdf334, 54-67→0xdf47c, 68→0xdf208, 69→0xdf334, 70-79→0xdf47c, 80→0xdf334, 81→0xdf47c, 82-85→0xdf334 */
/* @0xdf0ac b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf0b0 b 0xdf344 <_Z5DoAndjPhPKhP6VMExec+0x3d4> */
/* @0xdf0b4 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf0b8 b 0xdf344 <_Z5DoAndjPhPKhP6VMExec+0x3d4> */
/* @0xdf0bc b 0xdf344 <_Z5DoAndjPhPKhP6VMExec+0x3d4> */
/* @0xdf0c0 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf0c4 b 0xdf334 <_Z5DoAndjPhPKhP6VMExec+0x3c4> */
/* @0xdf0c8 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf0cc b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf0d0 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf0d4 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf0d8 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf0dc b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf0e0 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf0e4 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf0e8 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf0ec b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf0f0 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf0f4 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf0f8 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf0fc b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf100 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf104 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf108 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf10c b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf110 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf114 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf118 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf11c b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf120 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf124 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf128 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf12c b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf130 b 0xdf344 <_Z5DoAndjPhPKhP6VMExec+0x3d4> */
/* @0xdf134 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf138 b 0xdf208 <_Z5DoAndjPhPKhP6VMExec+0x298> */
/* @0xdf13c b 0xdf344 <_Z5DoAndjPhPKhP6VMExec+0x3d4> */
/* @0xdf140 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf144 b 0xdf334 <_Z5DoAndjPhPKhP6VMExec+0x3c4> */
/* @0xdf148 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf14c b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf150 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf154 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf158 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf15c b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf160 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf164 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf168 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf16c b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf170 b 0xdf344 <_Z5DoAndjPhPKhP6VMExec+0x3d4> */
/* @0xdf174 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf178 b 0xdf344 <_Z5DoAndjPhPKhP6VMExec+0x3d4> */
/* @0xdf17c b 0xdf344 <_Z5DoAndjPhPKhP6VMExec+0x3d4> */
/* @0xdf180 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf184 b 0xdf334 <_Z5DoAndjPhPKhP6VMExec+0x3c4> */
/* @0xdf188 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf18c b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf190 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf194 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf198 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf19c b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1a0 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1a4 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1a8 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1ac b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1b0 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1b4 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1b8 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1bc b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1c0 b 0xdf208 <_Z5DoAndjPhPKhP6VMExec+0x298> */
/* @0xdf1c4 b 0xdf334 <_Z5DoAndjPhPKhP6VMExec+0x3c4> */
/* @0xdf1c8 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1cc b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1d0 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1d4 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1d8 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1dc b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1e0 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1e4 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1e8 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1ec b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1f0 b 0xdf334 <_Z5DoAndjPhPKhP6VMExec+0x3c4> */
/* @0xdf1f4 b 0xdf47c <_Z5DoAndjPhPKhP6VMExec+0x50c> */
/* @0xdf1f8 b 0xdf334 <_Z5DoAndjPhPKhP6VMExec+0x3c4> */
/* @0xdf1fc b 0xdf334 <_Z5DoAndjPhPKhP6VMExec+0x3c4> */
/* @0xdf200 b 0xdf334 <_Z5DoAndjPhPKhP6VMExec+0x3c4> */
/* @0xdf204 b 0xdf334 <_Z5DoAndjPhPKhP6VMExec+0x3c4> */
/* @0xdf208 sub r6, r6, #4   ——dest=r6-4 */
/* @0xdf20c mov r7, #0 */
/* @0xdf210 mov r8, r6 */
/* @0xdf214 cmp r5, #68 */
/* @0xdf218 addls pc, pc, r5, lsl #2   ——表：按 r5 0→0xdf560, 1→0xdf578, 2→0xdf458, 3→0xdf550, 4→0xdf458, 5-31→0xdf578, 32→0xdf41c, 33→0xdf578, 34→0xdf4d4, 35→0xdf4b8, 36-47→0xdf578, 48→0xdf508, 49→0xdf578, 50→0xdf4ec, 51→0xdf49c, 52-63→0xdf578, 64→0xdf41c, 65-67→0xdf578, 68→0xdf52c */
/* @0xdf21c b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf220 b 0xdf560 <_Z5DoAndjPhPKhP6VMExec+0x5f0> */
/* @0xdf224 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf228 b 0xdf458 <_Z5DoAndjPhPKhP6VMExec+0x4e8> */
/* @0xdf22c b 0xdf550 <_Z5DoAndjPhPKhP6VMExec+0x5e0> */
/* @0xdf230 b 0xdf458 <_Z5DoAndjPhPKhP6VMExec+0x4e8> */
/* @0xdf234 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf238 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf23c b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf240 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf244 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf248 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf24c b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf250 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf254 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf258 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf25c b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf260 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf264 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf268 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf26c b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf270 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf274 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf278 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf27c b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf280 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf284 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf288 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf28c b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf290 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf294 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf298 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf29c b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf2a0 b 0xdf41c <_Z5DoAndjPhPKhP6VMExec+0x4ac> */
/* @0xdf2a4 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf2a8 b 0xdf4d4 <_Z5DoAndjPhPKhP6VMExec+0x564> */
/* @0xdf2ac b 0xdf4b8 <_Z5DoAndjPhPKhP6VMExec+0x548> */
/* @0xdf2b0 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf2b4 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf2b8 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf2bc b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf2c0 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf2c4 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf2c8 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf2cc b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf2d0 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf2d4 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf2d8 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf2dc b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf2e0 b 0xdf508 <_Z5DoAndjPhPKhP6VMExec+0x598> */
/* @0xdf2e4 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf2e8 b 0xdf4ec <_Z5DoAndjPhPKhP6VMExec+0x57c> */
/* @0xdf2ec b 0xdf49c <_Z5DoAndjPhPKhP6VMExec+0x52c> */
/* @0xdf2f0 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf2f4 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf2f8 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf2fc b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf300 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf304 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf308 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf30c b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf310 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf314 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf318 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf31c b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf320 b 0xdf41c <_Z5DoAndjPhPKhP6VMExec+0x4ac> */
/* @0xdf324 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf328 b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf32c b 0xdf578 <_Z5DoAndjPhPKhP6VMExec+0x608> */
/* @0xdf330 b 0xdf52c <_Z5DoAndjPhPKhP6VMExec+0x5bc> */
/* @0xdf334 sub r7, r6, #16   ——dest=r6-16（r7 写 tag） */
/* @0xdf338 mov r8, r7 */
/* @0xdf33c mov r6, r7 */
/* @0xdf340 b 0xdf214 <_Z5DoAndjPhPKhP6VMExec+0x2a4> */
/* @0xdf344 sub r6, r6, #8   ——dest=r6-8（r7=0） */
/* @0xdf348 mov r7, #0 */
/* @0xdf34c mov r8, r6 */
/* @0xdf350 b 0xdf214 <_Z5DoAndjPhPKhP6VMExec+0x2a4> */
/* @0xdf354 ldr r3, [r10, #0xc]   ——Afmt 5：读 [A+0xc] 的 tag */
/* @0xdf358 cmp r3, #13 */
/* @0xdf35c addls pc, pc, r3, lsl #2   ——表：按 r3 0→0xdf6ac, 1→0xdf698, 2→0xdf684, 3→0xdf670, 4→0xdf738, 5→0xdf65c, 6→0xdf738, 7→0xdf650, 8-9→0xdf738, 10→0xdf640, 11-12→0xdf738, 13→0xdf6ac */
/* @0xdf360 b 0xdf738 <_Z5DoAndjPhPKhP6VMExec+0x7c8> */
/* @0xdf364 b 0xdf6ac <_Z5DoAndjPhPKhP6VMExec+0x73c> */
/* @0xdf368 b 0xdf698 <_Z5DoAndjPhPKhP6VMExec+0x728> */
/* @0xdf36c b 0xdf684 <_Z5DoAndjPhPKhP6VMExec+0x714> */
/* @0xdf370 b 0xdf670 <_Z5DoAndjPhPKhP6VMExec+0x700> */
/* @0xdf374 b 0xdf738 <_Z5DoAndjPhPKhP6VMExec+0x7c8> */
/* @0xdf378 b 0xdf65c <_Z5DoAndjPhPKhP6VMExec+0x6ec> */
/* @0xdf37c b 0xdf738 <_Z5DoAndjPhPKhP6VMExec+0x7c8> */
/* @0xdf380 b 0xdf650 <_Z5DoAndjPhPKhP6VMExec+0x6e0> */
/* @0xdf384 b 0xdf738 <_Z5DoAndjPhPKhP6VMExec+0x7c8> */
/* @0xdf388 b 0xdf738 <_Z5DoAndjPhPKhP6VMExec+0x7c8> */
/* @0xdf38c b 0xdf640 <_Z5DoAndjPhPKhP6VMExec+0x6d0> */
/* @0xdf390 b 0xdf738 <_Z5DoAndjPhPKhP6VMExec+0x7c8> */
/* @0xdf394 b 0xdf738 <_Z5DoAndjPhPKhP6VMExec+0x7c8> */
/* @0xdf398 b 0xdf6ac <_Z5DoAndjPhPKhP6VMExec+0x73c> */
/* @0xdf39c add r6, r10, #4   ——Afmt 1/2/4 → r6=A+4 */
/* @0xdf3a0 b 0xdf0a4 <_Z5DoAndjPhPKhP6VMExec+0x134> */
/* @0xdf3a4 add r6, r10, #8   ——Afmt 0/3 → r6=A+8 */
/* @0xdf3a8 b 0xdf0a4 <_Z5DoAndjPhPKhP6VMExec+0x134> */
/* @0xdf3ac add r10, r1, #4   ——Bfmt 1/2/4 → A=arg2+4 */
/* @0xdf3b0 mov r5, r4 */
/* @0xdf3b4 b 0xdf064 <_Z5DoAndjPhPKhP6VMExec+0xf4> */
/* @0xdf3b8 ldr r3, [r1, #0xc]   ——Bfmt 5：读 [arg2+0xc] 的 tag */
/* @0xdf3bc cmp r3, #13 */
/* @0xdf3c0 addls pc, pc, r3, lsl #2   ——表：按 r3 0→0xdf730, 1→0xdf718, 2→0xdf700, 3→0xdf6e8, 4→0xdf74c, 5→0xdf6d0, 6→0xdf74c, 7→0xdf6c4, 8-9→0xdf74c, 10→0xdf6b4, 11-12→0xdf74c, 13→0xdf730 */
/* @0xdf3c4 b 0xdf74c <_Z5DoAndjPhPKhP6VMExec+0x7dc> */
/* @0xdf3c8 b 0xdf730 <_Z5DoAndjPhPKhP6VMExec+0x7c0> */
/* @0xdf3cc b 0xdf718 <_Z5DoAndjPhPKhP6VMExec+0x7a8> */
/* @0xdf3d0 b 0xdf700 <_Z5DoAndjPhPKhP6VMExec+0x790> */
/* @0xdf3d4 b 0xdf6e8 <_Z5DoAndjPhPKhP6VMExec+0x778> */
/* @0xdf3d8 b 0xdf74c <_Z5DoAndjPhPKhP6VMExec+0x7dc> */
/* @0xdf3dc b 0xdf6d0 <_Z5DoAndjPhPKhP6VMExec+0x760> */
/* @0xdf3e0 b 0xdf74c <_Z5DoAndjPhPKhP6VMExec+0x7dc> */
/* @0xdf3e4 b 0xdf6c4 <_Z5DoAndjPhPKhP6VMExec+0x754> */
/* @0xdf3e8 b 0xdf74c <_Z5DoAndjPhPKhP6VMExec+0x7dc> */
/* @0xdf3ec b 0xdf74c <_Z5DoAndjPhPKhP6VMExec+0x7dc> */
/* @0xdf3f0 b 0xdf6b4 <_Z5DoAndjPhPKhP6VMExec+0x744> */
/* @0xdf3f4 b 0xdf74c <_Z5DoAndjPhPKhP6VMExec+0x7dc> */
/* @0xdf3f8 b 0xdf74c <_Z5DoAndjPhPKhP6VMExec+0x7dc> */
/* @0xdf3fc b 0xdf730 <_Z5DoAndjPhPKhP6VMExec+0x7c0> */
/* @0xdf400 ldr r1, [pc, #0x3bc]   ——Bfmt=6（内联字符串常量）→ VMError */
/* @0xdf404 mov r0, r3 */
/* @0xdf408 mov r5, r4 */
/* @0xdf40c mov r10, r9 */
/* @0xdf410 add r1, pc, r1 */
/* @0xdf414 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdf418 b 0xdf064 <_Z5DoAndjPhPKhP6VMExec+0xf4> */
/* @0xdf41c ldr r4, [r10]   ——内核 (int32|bool, real)：A 四字节符号扩展后 & B(截断)，回 double，tag 0 */
/* @0xdf420 ldrd r0, r1, [r9] */
/* @0xdf424 asr r5, r4, #31 */
/* @0xdf428 bl 0x3194a0 <__fixdfdi> */
/* @0xdf42c and r0, r0, r4 */
/* @0xdf430 and r1, r1, r5 */
/* @0xdf434 bl 0x319164 <__floatdidf> */
/* @0xdf438 mov r12, #0 */
/* @0xdf43c strd r0, r1, [r8] */
/* @0xdf440 cmp r7, #0   ——共享尾：r7≠0 才写 tag */
/* @0xdf444 beq 0xdf050 <_Z5DoAndjPhPKhP6VMExec+0xe0> */
/* @0xdf448 mov r0, r6   ——返回 r6 */
/* @0xdf44c str r12, [r7, #0xc] */
/* @0xdf450 add sp, sp, #68 */
/* @0xdf454 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xdf458 ldrd r0, r1, [r10]   ——内核 (real, int32|bool)：A 截断后 & B 符号扩展，回 double，tag 0 */
/* @0xdf45c bl 0x3194a0 <__fixdfdi> */
/* @0xdf460 ldr r3, [r9] */
/* @0xdf464 and r0, r0, r3 */
/* @0xdf468 and r1, r1, r3, asr #31 */
/* @0xdf46c bl 0x319164 <__floatdidf> */
/* @0xdf470 mov r12, #0 */
/* @0xdf474 strd r0, r1, [r8] */
/* @0xdf478 b 0xdf440 <_Z5DoAndjPhPKhP6VMExec+0x4d0> */
/* @0xdf47c mov r8, #0   ——无 dest 出口（r8=r7=0） */
/* @0xdf480 mov r7, r8 */
/* @0xdf484 b 0xdf214 <_Z5DoAndjPhPKhP6VMExec+0x2a4> */
/* @0xdf488 ldr r0, [pc, #0x338]   ——VMError/JSThrow 文案："could not find variable after '&'" */
/* @0xdf48c add r0, pc, r0 */
/* @0xdf490 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xdf494 mov r0, r6 */
/* @0xdf498 b 0xdf054 <_Z5DoAndjPhPKhP6VMExec+0xe4> */
/* @0xdf49c ldrd r0, r1, [r10]   ——内核 (int64,int64) */
/* @0xdf4a0 mov r12, #10 */
/* @0xdf4a4 ldrd r2, r3, [r9] */
/* @0xdf4a8 and r2, r2, r0 */
/* @0xdf4ac and r3, r3, r1 */
/* @0xdf4b0 strd r2, r3, [r8] */
/* @0xdf4b4 b 0xdf440 <_Z5DoAndjPhPKhP6VMExec+0x4d0> */
/* @0xdf4b8 ldr r1, [r10]   ——内核 (int32,int64) */
/* @0xdf4bc mov r12, #10 */
/* @0xdf4c0 ldrd r2, r3, [r9] */
/* @0xdf4c4 and r2, r2, r1 */
/* @0xdf4c8 and r3, r3, r1, asr #31 */
/* @0xdf4cc strd r2, r3, [r8] */
/* @0xdf4d0 b 0xdf440 <_Z5DoAndjPhPKhP6VMExec+0x4d0> */
/* @0xdf4d4 ldr r2, [r10]   ——内核 (int32,int32) */
/* @0xdf4d8 mov r12, #7 */
/* @0xdf4dc ldr r3, [r9] */
/* @0xdf4e0 and r3, r2, r3 */
/* @0xdf4e4 str r3, [r8] */
/* @0xdf4e8 b 0xdf440 <_Z5DoAndjPhPKhP6VMExec+0x4d0> */
/* @0xdf4ec ldr r1, [r9]   ——内核 (int64,int32) */
/* @0xdf4f0 mov r12, #10 */
/* @0xdf4f4 ldrd r2, r3, [r10] */
/* @0xdf4f8 and r2, r2, r1 */
/* @0xdf4fc and r3, r3, r1, asr #31 */
/* @0xdf500 strd r2, r3, [r8] */
/* @0xdf504 b 0xdf440 <_Z5DoAndjPhPKhP6VMExec+0x4d0> */
/* @0xdf508 ldrd r0, r1, [r9]   ——内核 (int64,real) */
/* @0xdf50c bl 0x3194a0 <__fixdfdi> */
/* @0xdf510 ldrd r2, r3, [r10] */
/* @0xdf514 and r0, r0, r2 */
/* @0xdf518 and r1, r1, r3 */
/* @0xdf51c bl 0x319164 <__floatdidf> */
/* @0xdf520 mov r12, #0 */
/* @0xdf524 strd r0, r1, [r8] */
/* @0xdf528 b 0xdf440 <_Z5DoAndjPhPKhP6VMExec+0x4d0> */
/* @0xdf52c ldr r3, [r10]   ——内核 (bool,bool)：逻辑与，tag 13 */
/* @0xdf530 cmp r3, #0 */
/* @0xdf534 beq 0xdf544 <_Z5DoAndjPhPKhP6VMExec+0x5d4> */
/* @0xdf538 ldr r3, [r9] */
/* @0xdf53c adds r3, r3, #0 */
/* @0xdf540 movne r3, #1 */
/* @0xdf544 str r3, [r8] */
/* @0xdf548 mov r12, #13 */
/* @0xdf54c b 0xdf440 <_Z5DoAndjPhPKhP6VMExec+0x4d0> */
/* @0xdf550 ldrd r0, r1, [r10]   ——内核 (real,int64) */
/* @0xdf554 bl 0x3194a0 <__fixdfdi> */
/* @0xdf558 ldrd r2, r3, [r9] */
/* @0xdf55c b 0xdf514 <_Z5DoAndjPhPKhP6VMExec+0x5a4> */
/* @0xdf560 ldrd r0, r1, [r10]   ——内核 (real,real) */
/* @0xdf564 bl 0x3194a0 <__fixdfdi> */
/* @0xdf568 mov r4, r0 */
/* @0xdf56c mov r5, r1 */
/* @0xdf570 ldrd r0, r1, [r9] */
/* @0xdf574 b 0xdf428 <_Z5DoAndjPhPKhP6VMExec+0x4b8> */
/* @0xdf578 ldr r1, [pc, #0x24c]   ——非法组合 → VMError('DoAnd :: Execution Error')，tag 0 */
/* @0xdf57c mov r0, r11 */
/* @0xdf580 add r1, pc, r1 */
/* @0xdf584 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdf588 mov r12, #0 */
/* @0xdf58c b 0xdf440 <_Z5DoAndjPhPKhP6VMExec+0x4d0> */
/* @0xdf590 add r7, sp, #48 */
/* @0xdf594 mov r1, r4 */
/* @0xdf598 mov r0, r7 */
/* @0xdf59c bl 0x24d5c8 <_Z12F_JS_ToInt32R6RValueS0_> */
/* @0xdf5a0 cmp r0, #1 */
/* @0xdf5a4 beq 0xdf798 <_Z5DoAndjPhPKhP6VMExec+0x828> */
/* @0xdf5a8 cmp r0, #0 */
/* @0xdf5ac bne 0xdf050 <_Z5DoAndjPhPKhP6VMExec+0xe0> */
/* @0xdf5b0 str r0, [r6, #-0x4] */
/* @0xdf5b4 sub r4, r6, #16 */
/* @0xdf5b8 vldr d7, [sp, #32] */
/* @0xdf5bc vldr d6, [sp, #48] */
/* @0xdf5c0 vcvt.s32.f64 s14, d7 */
/* @0xdf5c4 ldr r3, [sp, #0x2c] */
/* @0xdf5c8 sub r3, r3, #1 */
/* @0xdf5cc bic r3, r3, #-16777216 */
/* @0xdf5d0 bic r3, r3, #3 */
/* @0xdf5d4 cmp r3, #0 */
/* @0xdf5d8 vcvt.s32.f64 s11, d6 */
/* @0xdf5dc vmov r3, s14 */
/* @0xdf5e0 vmov r2, s11 */
/* @0xdf5e4 and r2, r2, r3 */
/* @0xdf5e8 vmov s15, r2 */
/* @0xdf5ec vcvt.f64.s32 d7, s15 */
/* @0xdf5f0 vmov r2, r3, d7 */
/* @0xdf5f4 vstr s14, [r6, #-16] */
/* @0xdf5f8 str r3, [r6, #-0xc] */
/* @0xdf5fc beq 0xdf78c <_Z5DoAndjPhPKhP6VMExec+0x81c> */
/* @0xdf600 ldr r1, [sp, #0x3c] */
/* @0xdf604 mov r3, #0 */
/* @0xdf608 str r3, [sp, #0x28] */
/* @0xdf60c mov r2, #5 */
/* @0xdf610 sub r1, r1, #1 */
/* @0xdf614 str r3, [sp, #0x20] */
/* @0xdf618 bic r3, r1, #-16777216 */
/* @0xdf61c str r2, [sp, #0x2c] */
/* @0xdf620 bic r3, r3, #3 */
/* @0xdf624 cmp r3, #0 */
/* @0xdf628 movne r0, r4 */
/* @0xdf62c bne 0xdf054 <_Z5DoAndjPhPKhP6VMExec+0xe4> */
/* @0xdf630 mov r0, r7 */
/* @0xdf634 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdf638 mov r0, r4 */
/* @0xdf63c b 0xdf054 <_Z5DoAndjPhPKhP6VMExec+0xe4> */
/* @0xdf640 and r5, r5, #15 */
/* @0xdf644 orr r5, r5, #48 */
/* @0xdf648 add r6, r10, #16 */
/* @0xdf64c b 0xdf0a4 <_Z5DoAndjPhPKhP6VMExec+0x134> */
/* @0xdf650 and r5, r5, #15 */
/* @0xdf654 orr r5, r5, #32 */
/* @0xdf658 b 0xdf648 <_Z5DoAndjPhPKhP6VMExec+0x6d8> */
/* @0xdf65c ldr r1, [pc, #0x16c]   ——VMError/JSThrow 文案：'DoAnd :2: undefined value' */
/* @0xdf660 mov r0, r11 */
/* @0xdf664 add r1, pc, r1 */
/* @0xdf668 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdf66c b 0xdf648 <_Z5DoAndjPhPKhP6VMExec+0x6d8> */
/* @0xdf670 ldr r1, [pc, #0x15c]   ——VMError/JSThrow 文案：'DoAnd :2: illegal pointer use' */
/* @0xdf674 mov r0, r11 */
/* @0xdf678 add r1, pc, r1 */
/* @0xdf67c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdf680 b 0xdf648 <_Z5DoAndjPhPKhP6VMExec+0x6d8> */
/* @0xdf684 ldr r1, [pc, #0x14c]   ——VMError/JSThrow 文案：'DoAnd :2: illegal array use' */
/* @0xdf688 mov r0, r11 */
/* @0xdf68c add r1, pc, r1 */
/* @0xdf690 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdf694 b 0xdf648 <_Z5DoAndjPhPKhP6VMExec+0x6d8> */
/* @0xdf698 ldr r1, [pc, #0x13c]   ——VMError/JSThrow 文案：'DoAnd :2: Execution Engine - Cannot operate on string type' */
/* @0xdf69c mov r0, r11 */
/* @0xdf6a0 add r1, pc, r1 */
/* @0xdf6a4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdf6a8 b 0xdf648 <_Z5DoAndjPhPKhP6VMExec+0x6d8> */
/* @0xdf6ac and r5, r5, #15 */
/* @0xdf6b0 b 0xdf648 <_Z5DoAndjPhPKhP6VMExec+0x6d8> */
/* @0xdf6b4 and r5, r5, #240 */
/* @0xdf6b8 orr r5, r5, #3 */
/* @0xdf6bc add r10, r9, #16 */
/* @0xdf6c0 b 0xdf064 <_Z5DoAndjPhPKhP6VMExec+0xf4> */
/* @0xdf6c4 and r5, r5, #240 */
/* @0xdf6c8 orr r5, r5, #2 */
/* @0xdf6cc b 0xdf6bc <_Z5DoAndjPhPKhP6VMExec+0x74c> */
/* @0xdf6d0 ldr r1, [pc, #0x108]   ——VMError/JSThrow 文案：'DoAnd :1: undefined value' */
/* @0xdf6d4 mov r0, r11 */
/* @0xdf6d8 mov r5, r4 */
/* @0xdf6dc add r1, pc, r1 */
/* @0xdf6e0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdf6e4 b 0xdf6bc <_Z5DoAndjPhPKhP6VMExec+0x74c> */
/* @0xdf6e8 ldr r1, [pc, #0xf4]   ——VMError/JSThrow 文案：'DoAnd :1: illegal pointer use' */
/* @0xdf6ec mov r0, r11 */
/* @0xdf6f0 mov r5, r4 */
/* @0xdf6f4 add r1, pc, r1 */
/* @0xdf6f8 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdf6fc b 0xdf6bc <_Z5DoAndjPhPKhP6VMExec+0x74c> */
/* @0xdf700 ldr r1, [pc, #0xe0]   ——VMError/JSThrow 文案：'DoAnd :1: illegal array use' */
/* @0xdf704 mov r0, r11 */
/* @0xdf708 mov r5, r4 */
/* @0xdf70c add r1, pc, r1 */
/* @0xdf710 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdf714 b 0xdf6bc <_Z5DoAndjPhPKhP6VMExec+0x74c> */
/* @0xdf718 ldr r1, [pc, #0xcc]   ——VMError/JSThrow 文案：'DoAnd :1: Execution Engine - Cannot operate on string type' */
/* @0xdf71c mov r0, r11 */
/* @0xdf720 mov r5, r4 */
/* @0xdf724 add r1, pc, r1 */
/* @0xdf728 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdf72c b 0xdf6bc <_Z5DoAndjPhPKhP6VMExec+0x74c> */
/* @0xdf730 and r5, r4, #240 */
/* @0xdf734 b 0xdf6bc <_Z5DoAndjPhPKhP6VMExec+0x74c> */
/* @0xdf738 ldr r1, [pc, #0xb0]   ——VMError/JSThrow 文案：'DoAnd :2: Malformed variable' */
/* @0xdf73c mov r0, r11 */
/* @0xdf740 add r1, pc, r1 */
/* @0xdf744 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdf748 b 0xdf648 <_Z5DoAndjPhPKhP6VMExec+0x6d8> */
/* @0xdf74c ldr r1, [pc, #0xa0]   ——VMError/JSThrow 文案：'DoAnd :1: Malformed variable' */
/* @0xdf750 mov r0, r11 */
/* @0xdf754 mov r5, r4 */
/* @0xdf758 add r1, pc, r1 */
/* @0xdf75c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xdf760 b 0xdf6bc <_Z5DoAndjPhPKhP6VMExec+0x74c> */
/* @0xdf764 ldr r0, [pc, #0x8c]   ——VMError/JSThrow 文案："could not find variable before '&'" */
/* @0xdf768 add r0, pc, r0 */
/* @0xdf76c bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xdf770 mov r0, r6 */
/* @0xdf774 b 0xdf054 <_Z5DoAndjPhPKhP6VMExec+0xe4> */
/* @0xdf778 ldr r0, [pc, #0x7c]   ——VMError/JSThrow 文案：'DoAdd - could not convert lhs expr to a number' */
/* @0xdf77c add r0, pc, r0 */
/* @0xdf780 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xdf784 mov r0, r6 */
/* @0xdf788 b 0xdf054 <_Z5DoAndjPhPKhP6VMExec+0xe4> */
/* @0xdf78c mov r0, r5 */
/* @0xdf790 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xdf794 b 0xdf600 <_Z5DoAndjPhPKhP6VMExec+0x690> */
/* @0xdf798 ldr r0, [pc, #0x60]   ——VMError/JSThrow 文案：'DoAdd - could not convert rhs expr to a number' */
/* @0xdf79c add r0, pc, r0 */
/* @0xdf7a0 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xdf7a4 mov r0, r6 */
/* @0xdf7a8 b 0xdf054 <_Z5DoAndjPhPKhP6VMExec+0xe4> */
/* @0xdf7ac mov r5, r4 */
/* @0xdf7b0 mov r10, r1 */
/* @0xdf7b4 b 0xdf064 <_Z5DoAndjPhPKhP6VMExec+0xf4> */
/* @0xdf7b8 mov r6, r10 */
/* @0xdf7bc b 0xdf0a4 <_Z5DoAndjPhPKhP6VMExec+0x134> */
/* @0xdf7c0 eoreq r4, r5, r12, ror r6   ——literal pool：+0x25467c → 0x333720 (非指令) 'DoAnd :: Execution Engine - Cannot operate on string type' */
/* @0xdf7c4 eoreq r4, r5, r8, lsl #6   ——literal pool：+0x254308 → 0x333720 (非指令) 'DoAnd :: Execution Engine - Cannot operate on string type' */
/* @0xdf7c8 eoreq r4, r5, r8, lsl #4   ——literal pool：+0x254208 → 0x33369c (非指令) "could not find variable after '&'" */
/* @0xdf7cc eoreq r4, r5, r12, lsr r3   ——literal pool：+0x25433c → 0x3338c4 (非指令) 'DoAnd :: Execution Error' */
/* @0xdf7d0 eoreq r4, r5, r0, lsl #4   ——literal pool：+0x254200 → 0x33386c (非指令) 'DoAnd :2: undefined value' */
/* @0xdf7d4 eoreq r4, r5, r12, asr #3   ——literal pool：+0x2541cc → 0x33384c (非指令) 'DoAnd :2: illegal pointer use' */
/* @0xdf7d8 .word 0x002541f4   ——literal pool：+0x2541f4 → 0x333888 (非指令) 'DoAnd :2: illegal array use' */
/* @0xdf7dc eoreq r4, r5, r8, ror #2   ——literal pool：+0x254168 → 0x333810 (非指令) 'DoAnd :2: Execution Engine - Cannot operate on string type' */
/* @0xdf7e0 mlaeq r5, r8, r0, r4   ——literal pool：+0x254098 → 0x33377c (非指令) 'DoAnd :1: undefined value' */
/* @0xdf7e4 eoreq r4, r5, r0, rrx   ——literal pool：+0x254060 → 0x33375c (非指令) 'DoAnd :1: illegal pointer use' */
/* @0xdf7e8 eoreq r4, r5, r0, asr #1   ——literal pool：+0x2540c0 → 0x3337d4 (非指令) 'DoAnd :1: illegal array use' */
/* @0xdf7ec eoreq r4, r5, r12, rrx   ——literal pool：+0x25406c → 0x333798 (非指令) 'DoAnd :1: Execution Engine - Cannot operate on string type' */
/* @0xdf7f0 eoreq r4, r5, r12, asr r1   ——literal pool：+0x25415c → 0x3338a4 (非指令) 'DoAnd :2: Malformed variable' */
/* @0xdf7f4 mlaeq r5, r0, r0, r4   ——literal pool：+0x254090 → 0x3337f0 (非指令) 'DoAnd :1: Malformed variable' */
/* @0xdf7f8 eoreq r3, r5, r8, lsl #30   ——literal pool：+0x253f08 → 0x333678 (非指令) "could not find variable before '&'" */
/* @0xdf7fc eoreq r3, r5, r12, lsr pc   ——literal pool：+0x253f3c → 0x3336c0 (非指令) 'DoAdd - could not convert lhs expr to a number' */
/* @0xdf800 eoreq r3, r5, r12, asr #30   ——literal pool：+0x253f4c → 0x3336f0 (非指令) 'DoAdd - could not convert rhs expr to a number' */
