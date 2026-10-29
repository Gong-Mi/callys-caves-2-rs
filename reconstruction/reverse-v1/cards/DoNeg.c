/* cally 逆向卡：DoNeg（原版 libyoyo.so，armv7）
 * @func 0xe096c 0xe0cec  size 896  224 条指令（含尾部 10 个 literal 字）
 * 级别: 正文（224 条全部解码；三档 mode 与 14 路 tag 表已定，mode 2 的编译器用途与 cls 4 的类型名未定）
 * 符号: _Z5DoNegjPhPKhP6VMExec → uchar* DoNeg(uint32 arg, uchar* sp, const uchar* base, VMExec* exec)
 *
 * 已证（指令级）：
 *   mode = (arg >> 8) & 0xF；cls = (arg >> 16) & 0xF          ; e096c / e0980 / e0998
 *       与 DoAdd 的 arg 位域同源（DoAdd: mode=(arg>>8)&0xF、type=(arg>>16)&0xFF），这里只用右操作数存储类 cls = type&0xF
 *   mode 0（以及 3..15，比较落空即回落到这里）→ 强类型快路：就地改载荷、sp 不动、返回 r6   ; e0998..e09c0
 *       cls 0 double(8B) ：vldr d7 / vneg.f64 / vstr                            ; e09a8 → e0a5c
 *       cls 1 float (4B) ：vldr s15 / vneg.f32 / vstr                           ; e09ac → e0a74
 *       cls 2 int32 (4B) ：ldr / rsb r3,r3,#0 / str                             ; e09b0 → e09c4
 *       cls 3 int64 (8B) ：ldrd / rsbs r4,r4,#0 / rsc r5,r5,#0 / strd           ; e09b4 → e09dc
 *       cls 4 bool  (4B) ：与 int32 同一条 rsb 路径                            ; e09b8 → e09c4
 *       cls 5 RValue(16B)：读 +0xc 的 tag 走 14 路跳表                          ; e09bc → e09f8
 *       cls 6 string(4B) ：VMError "DoNeg :1: Execution Engine - Cannot operate on string type" ; e09c0 → e0a40
 *       cls >6           ：原样返回 r6（不动栈）                                ; e09a4 → e0cbc
 *   cls 5 的 tag 跳表（cmp r2,#13；表基 e0a08）：
 *       0 → 翻符号位（ldr r4/r5 / eor r5,#0x80000000 / stm）e0c28 ；13 → 同上
 *       10 → int64 取负 e0bac ；7 → int32 rsb e09c4
 *       1 → "Cannot operate on string type" e0c10 ；2 → "illegal array use" e0bf8
 *       3 → "illegal pointer use" e0be0 ；5 → "undefined value" e0bc8
 *       4/6/8/9/11/12 → "Malformed variable" e0c5c ；>13 → "Malformed variable"（落空到 e0a04）
 *   mode 1（通用取负）：boxType(sp, cls, sp) → [sp+0xc] 的 tag 若 == 0x00FFFFFF 则 JSThrowReferenceError
 *       ；F_JS_ToNumber(sp+16, sp) → 返回 1 则 JSThrowTypeError("Unary - could not convert expr to a number")
 *       ；结果 tag 0（Real）压在 boxType 返回值 -16；NaN（vcmp 无序）显式落 0x7FFFFFFF_FFFFFFFF      ; e0a8c..e0b18
 *   mode 2（纯数值化）：与 mode 1 逐指令同构，唯一差别是不做 vneg，直接把转好的 double 原样压回       ; e0b1c..e0b94
 *   失败清理：读 [sp+0x1c] 的 out-tag，(tag-1)&0x00FFFFFC != 0 → 直接返回；== 0 → FREE_RValue__Pre 后返回 ; e0c80..e0ca8
 *
 * 结论：
 *   1. 一个 DoNeg 承载三种 opcode 形态：强类型取负（mode 0）、通用取负（mode 1）、纯数值化（mode 2，等价 JS 一元 +）。
 *   2. double 取负有两套实现：强类型路用 vneg.f64；通用路走 "double → int64 → 取负 → double"，并且把 NaN 规范成
 *      0x7FFFFFFF_FFFFFFFF —— 这条 NaN 规范化是 VFP 之外的显式分支（e0af8..e0b08），不是硬件行为。
 *   3. tag 13 与 tag 0 走同一条 double 路径、tag 7/10 走 32/64 位整数路径，与 SET_RValue 的载荷宽度表
 *      （0/10/13 → 8B；3/7/14 → 4B；4/5/8/9/11/12 → 无载荷）逐条对齐。
 * open：mode 2 的编译器用途（是否专给一元 + / 隐式数值化）；tag 13 的类型名（与 tag 0 同为 8B，但在 DoPop 里被当成实例标签用）；
 *       cls 4 在强类型路按 32 位整数取负，而 boxType 的 cls 4 分支（0xd788c）产出 tag 13 + double —— 两处的类型名需统一。
 *
 * ── 本批补证：取负（逐条锚在下方）──
 *   F_JS_ToNumber ×2（操作数转数）+ boxType ×2（装箱）+ JSThrowReferenceError ×2 / JSThrowTypeError ×2 + VMError ×6
 *   open 1 负数/零的符号处理
 *   open 2 6 处 VMError 文案
 */

/* ── 段 1 · 序言 / mode·cls 位域（0xe096c..0xe0994） ── */
/* @0xe096c ubfx r2, r0, #0x8, #0x4 */
/* @0xe0970 cmp r2, #0 */
/* @0xe0974 push {r4, r5, r6, r7, lr} */
/* @0xe0978 mov r6, r1 */
/* @0xe097c sub sp, sp, #36 */
/* @0xe0980 lsr r1, r0, #16 */
/* @0xe0984 beq 0xe0998 <_Z5DoNegjPhPKhP6VMExec+0x2c> */
/* @0xe0988 cmp r2, #1 */
/* @0xe098c beq 0xe0a8c <_Z5DoNegjPhPKhP6VMExec+0x120> */
/* @0xe0990 cmp r2, #2 */
/* @0xe0994 beq 0xe0b1c <_Z5DoNegjPhPKhP6VMExec+0x1b0> */

/* ── 段 2 · 强类型快路分派（cls 0..6）（0xe0998..e09c0） ── */
/* @0xe0998 and r2, r1, #15 */
/* @0xe099c cmp r2, #6 */
/* @0xe09a0 addls pc, pc, r2, lsl #2 */
/* @0xe09a4 b 0xe0cbc <_Z5DoNegjPhPKhP6VMExec+0x350> */
/* @0xe09a8 b 0xe0a5c <_Z5DoNegjPhPKhP6VMExec+0xf0> */
/* @0xe09ac b 0xe0a74 <_Z5DoNegjPhPKhP6VMExec+0x108> */
/* @0xe09b0 b 0xe09c4 <_Z5DoNegjPhPKhP6VMExec+0x58> */
/* @0xe09b4 b 0xe09dc <_Z5DoNegjPhPKhP6VMExec+0x70> */
/* @0xe09b8 b 0xe09c4 <_Z5DoNegjPhPKhP6VMExec+0x58> */
/* @0xe09bc b 0xe09f8 <_Z5DoNegjPhPKhP6VMExec+0x8c> */
/* @0xe09c0 b 0xe0a40 <_Z5DoNegjPhPKhP6VMExec+0xd4> */

/* ── 段 3 · 强类型体：int32/int64/float/double（0xe09c4..e09f4） ── */
/* @0xe09c4 ldr r3, [r6] */
/* @0xe09c8 mov r0, r6 */
/* @0xe09cc rsb r3, r3, #0 */
/* @0xe09d0 str r3, [r6] */
/* @0xe09d4 add sp, sp, #36 */
/* @0xe09d8 pop {r4, r5, r6, r7, pc} */
/* @0xe09dc ldrd r4, r5, [r6] */
/* @0xe09e0 mov r0, r6 */
/* @0xe09e4 rsbs r4, r4, #0 */
/* @0xe09e8 rsc r5, r5, #0 */
/* @0xe09ec strd r4, r5, [r6] */
/* @0xe09f0 add sp, sp, #36 */
/* @0xe09f4 pop {r4, r5, r6, r7, pc} */

/* ── 段 4 · cls 5：RValue tag 跳表 + 各 tag 处理（0xe09f8..e0a3c） ── */
/* @0xe09f8 ldr r2, [r6, #0xc] */
/* @0xe09fc cmp r2, #13 */
/* @0xe0a00 addls pc, pc, r2, lsl #2 */
/* @0xe0a04 b 0xe0c5c <_Z5DoNegjPhPKhP6VMExec+0x2f0> */
/* @0xe0a08 b 0xe0c28 <_Z5DoNegjPhPKhP6VMExec+0x2bc> */
/* @0xe0a0c b 0xe0c10 <_Z5DoNegjPhPKhP6VMExec+0x2a4> */
/* @0xe0a10 b 0xe0bf8 <_Z5DoNegjPhPKhP6VMExec+0x28c> */
/* @0xe0a14 b 0xe0be0 <_Z5DoNegjPhPKhP6VMExec+0x274> */
/* @0xe0a18 b 0xe0c5c <_Z5DoNegjPhPKhP6VMExec+0x2f0> */
/* @0xe0a1c b 0xe0bc8 <_Z5DoNegjPhPKhP6VMExec+0x25c> */
/* @0xe0a20 b 0xe0c5c <_Z5DoNegjPhPKhP6VMExec+0x2f0> */
/* @0xe0a24 b 0xe09c4 <_Z5DoNegjPhPKhP6VMExec+0x58> */
/* @0xe0a28 b 0xe0c5c <_Z5DoNegjPhPKhP6VMExec+0x2f0> */
/* @0xe0a2c b 0xe0c5c <_Z5DoNegjPhPKhP6VMExec+0x2f0> */
/* @0xe0a30 b 0xe0bac <_Z5DoNegjPhPKhP6VMExec+0x240> */
/* @0xe0a34 b 0xe0c5c <_Z5DoNegjPhPKhP6VMExec+0x2f0> */
/* @0xe0a38 b 0xe0c5c <_Z5DoNegjPhPKhP6VMExec+0x2f0> */
/* @0xe0a3c b 0xe0c28 <_Z5DoNegjPhPKhP6VMExec+0x2bc> */

/* ── 段 5 · cls 6 与 tag 错误分支（0xe0a40..e0a58） ── */
/* @0xe0a40 ldr r1, [pc, #0x27c] */
/* @0xe0a44 mov r0, r3 */
/* @0xe0a48 add r1, pc, r1 */
/* @0xe0a4c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe0a50 mov r0, r6 */
/* @0xe0a54 add sp, sp, #36 */
/* @0xe0a58 pop {r4, r5, r6, r7, pc} */

/* ── 段 6 · 强类型 float/double 体（0xe0a5c..e0a88） ── */
/* @0xe0a5c vldr d7, [r6] */
/* @0xe0a60 vneg.f64 d7, d7 */
/* @0xe0a64 mov r0, r6 */
/* @0xe0a68 vstr d7, [r6] */
/* @0xe0a6c add sp, sp, #36 */
/* @0xe0a70 pop {r4, r5, r6, r7, pc} */
/* @0xe0a74 vldr s15, [r6] */
/* @0xe0a78 vneg.f32 s15, s15 */
/* @0xe0a7c mov r0, r6 */
/* @0xe0a80 vstr s15, [r6] */
/* @0xe0a84 add sp, sp, #36 */
/* @0xe0a88 pop {r4, r5, r6, r7, pc} */

/* ── 段 7 · mode 1：boxType + F_JS_ToNumber + 取负（0xe0a8c..e0b18） ── */
/* @0xe0a8c mov r2, r6 */
/* @0xe0a90 and r1, r1, #15 */
/* @0xe0a94 mov r0, sp */
/* @0xe0a98 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xe0a9c ldr r2, [sp, #0xc] */
/* @0xe0aa0 mvn r3, #-16777216 */
/* @0xe0aa4 and r2, r2, r3 */
/* @0xe0aa8 cmp r2, r3 */
/* @0xe0aac mov r4, r0 */
/* @0xe0ab0 beq 0xe0b98 <_Z5DoNegjPhPKhP6VMExec+0x22c> */
/* @0xe0ab4 add r5, sp, #16 */
/* @0xe0ab8 mov r1, sp */
/* @0xe0abc str r3, [sp, #0x1c] */
/* @0xe0ac0 mov r2, #0 */
/* @0xe0ac4 mov r0, r5 */
/* @0xe0ac8 mov r3, #0 */
/* @0xe0acc strd r2, r3, [sp, #16] */
/* @0xe0ad0 mov r3, #0 */
/* @0xe0ad4 str r3, [sp, #0x18] */
/* @0xe0ad8 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0xe0adc cmp r0, #1 */
/* @0xe0ae0 beq 0xe0cac <_Z5DoNegjPhPKhP6VMExec+0x340> */
/* @0xe0ae4 cmp r0, #0 */
/* @0xe0ae8 bne 0xe0c80 <_Z5DoNegjPhPKhP6VMExec+0x314> */
/* @0xe0aec str r0, [r4, #-0x4] */
/* @0xe0af0 sub r0, r4, #16 */
/* @0xe0af4 vldr d7, [sp, #16] */
/* @0xe0af8 vcmp.f64 d7, d7 */
/* @0xe0afc vmrs APSR_nzcv, fpscr */
/* @0xe0b00 vnegvc.f64 d6, d7 */
/* @0xe0b04 mvnvs r2, #0 */
/* @0xe0b08 mvnvs r3, #-2147483648 */
/* @0xe0b0c vmovvc r2, r3, d6 */
/* @0xe0b10 str r2, [r4, #-0x10] */
/* @0xe0b14 str r3, [r4, #-0xc] */
/* @0xe0b18 b 0xe09d4 <_Z5DoNegjPhPKhP6VMExec+0x68> */

/* ── 段 8 · mode 2：同构但不取负（0xe0b1c..e0b94） ── */
/* @0xe0b1c mov r2, r6 */
/* @0xe0b20 and r1, r1, #15 */
/* @0xe0b24 mov r0, sp */
/* @0xe0b28 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xe0b2c ldr r2, [sp, #0xc] */
/* @0xe0b30 mvn r3, #-16777216 */
/* @0xe0b34 and r2, r2, r3 */
/* @0xe0b38 cmp r2, r3 */
/* @0xe0b3c mov r4, r0 */
/* @0xe0b40 beq 0xe0c48 <_Z5DoNegjPhPKhP6VMExec+0x2dc> */
/* @0xe0b44 add r5, sp, #16 */
/* @0xe0b48 mov r1, sp */
/* @0xe0b4c str r3, [sp, #0x1c] */
/* @0xe0b50 mov r2, #0 */
/* @0xe0b54 mov r0, r5 */
/* @0xe0b58 mov r3, #0 */
/* @0xe0b5c strd r2, r3, [sp, #16] */
/* @0xe0b60 mov r3, #0 */
/* @0xe0b64 str r3, [sp, #0x18] */
/* @0xe0b68 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0xe0b6c cmp r0, #1 */
/* @0xe0b70 beq 0xe0c74 <_Z5DoNegjPhPKhP6VMExec+0x308> */
/* @0xe0b74 cmp r0, #0 */
/* @0xe0b78 bne 0xe0c80 <_Z5DoNegjPhPKhP6VMExec+0x314> */
/* @0xe0b7c str r0, [r4, #-0x4] */
/* @0xe0b80 sub r0, r4, #16 */
/* @0xe0b84 ldr r2, [sp, #0x10] */
/* @0xe0b88 ldr r3, [sp, #0x14] */
/* @0xe0b8c str r2, [r4, #-0x10] */
/* @0xe0b90 str r3, [r4, #-0xc] */
/* @0xe0b94 b 0xe09d4 <_Z5DoNegjPhPKhP6VMExec+0x68> */

/* ── 段 9 · 错误路径 + 两处返回（0xe0b98..e0cc0） ── */
/* @0xe0b98 ldr r0, [pc, #0x128] */
/* @0xe0b9c add r0, pc, r0 */
/* @0xe0ba0 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe0ba4 mov r0, r4 */
/* @0xe0ba8 b 0xe09d4 <_Z5DoNegjPhPKhP6VMExec+0x68> */
/* @0xe0bac ldr r4, [r6] */
/* @0xe0bb0 mov r0, r6 */
/* @0xe0bb4 ldr r5, [r6, #0x4] */
/* @0xe0bb8 rsbs r4, r4, #0 */
/* @0xe0bbc rsc r5, r5, #0 */
/* @0xe0bc0 stm r6, {r4, r5} */
/* @0xe0bc4 b 0xe09d4 <_Z5DoNegjPhPKhP6VMExec+0x68> */
/* @0xe0bc8 ldr r1, [pc, #0xfc] */
/* @0xe0bcc mov r0, r3 */
/* @0xe0bd0 add r1, pc, r1 */
/* @0xe0bd4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe0bd8 mov r0, r6 */
/* @0xe0bdc b 0xe09d4 <_Z5DoNegjPhPKhP6VMExec+0x68> */
/* @0xe0be0 ldr r1, [pc, #0xe8] */
/* @0xe0be4 mov r0, r3 */
/* @0xe0be8 add r1, pc, r1 */
/* @0xe0bec bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe0bf0 mov r0, r6 */
/* @0xe0bf4 b 0xe09d4 <_Z5DoNegjPhPKhP6VMExec+0x68> */
/* @0xe0bf8 ldr r1, [pc, #0xd4] */
/* @0xe0bfc mov r0, r3 */
/* @0xe0c00 add r1, pc, r1 */
/* @0xe0c04 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe0c08 mov r0, r6 */
/* @0xe0c0c b 0xe09d4 <_Z5DoNegjPhPKhP6VMExec+0x68> */
/* @0xe0c10 ldr r1, [pc, #0xc0] */
/* @0xe0c14 mov r0, r3 */
/* @0xe0c18 add r1, pc, r1 */
/* @0xe0c1c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe0c20 mov r0, r6 */
/* @0xe0c24 b 0xe09d4 <_Z5DoNegjPhPKhP6VMExec+0x68> */
/* @0xe0c28 ldr r5, [r6, #0x4] */
/* @0xe0c2c mov r0, r6 */
/* @0xe0c30 ldr r4, [r6] */
/* @0xe0c34 eor r5, r5, #-2147483648 */
/* @0xe0c38 mov r2, r4 */
/* @0xe0c3c mov r3, r5 */
/* @0xe0c40 stm r6, {r2, r3} */
/* @0xe0c44 b 0xe09d4 <_Z5DoNegjPhPKhP6VMExec+0x68> */
/* @0xe0c48 ldr r0, [pc, #0x8c] */
/* @0xe0c4c add r0, pc, r0 */
/* @0xe0c50 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xe0c54 mov r0, r4 */
/* @0xe0c58 b 0xe09d4 <_Z5DoNegjPhPKhP6VMExec+0x68> */
/* @0xe0c5c ldr r1, [pc, #0x7c] */
/* @0xe0c60 mov r0, r3 */
/* @0xe0c64 add r1, pc, r1 */
/* @0xe0c68 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xe0c6c mov r0, r6 */
/* @0xe0c70 b 0xe09d4 <_Z5DoNegjPhPKhP6VMExec+0x68> */
/* @0xe0c74 ldr r0, [pc, #0x68] */
/* @0xe0c78 add r0, pc, r0 */
/* @0xe0c7c bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xe0c80 ldr r3, [sp, #0x1c] */
/* @0xe0c84 sub r3, r3, #1 */
/* @0xe0c88 bic r3, r3, #-16777216 */
/* @0xe0c8c bic r3, r3, #3 */
/* @0xe0c90 cmp r3, #0 */
/* @0xe0c94 movne r0, r4 */
/* @0xe0c98 bne 0xe09d4 <_Z5DoNegjPhPKhP6VMExec+0x68> */
/* @0xe0c9c mov r0, r5 */
/* @0xe0ca0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xe0ca4 mov r0, r4 */
/* @0xe0ca8 b 0xe09d4 <_Z5DoNegjPhPKhP6VMExec+0x68> */
/* @0xe0cac ldr r0, [pc, #0x34] */
/* @0xe0cb0 add r0, pc, r0 */
/* @0xe0cb4 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xe0cb8 b 0xe0c80 <_Z5DoNegjPhPKhP6VMExec+0x314> */
/* @0xe0cbc mov r0, r6 */
/* @0xe0cc0 b 0xe09d4 <_Z5DoNegjPhPKhP6VMExec+0x68> */

/* ── 段 10 · literal pool（非指令） ── */
/* @0xe0cc4 mlaeq r5, r8, r3, r3 —— 非指令（literal pool 数据字，objdump 误译） */
/* @0xe0cc8 eoreq r3, r5, r4, asr #3 —— 非指令（literal pool 数据字，objdump 误译） */
/* @0xe0ccc eoreq r3, r5, r12, ror #4 —— 非指令（literal pool 数据字，objdump 误译） */
/* @0xe0cd0 eoreq r3, r5, r4, lsr r2 —— 非指令（literal pool 数据字，objdump 误译） */
/* @0xe0cd4 mlaeq r5, r4, r2, r3 —— 非指令（literal pool 数据字，objdump 误译） */
/* @0xe0cd8 eoreq r3, r5, r0, asr #4 —— 非指令（literal pool 数据字，objdump 误译） */
/* @0xe0cdc eoreq r3, r5, r8, ror #2 —— 非指令（literal pool 数据字，objdump 误译） */
/* @0xe0ce0 eoreq r3, r5, r12, asr #4 —— 非指令（literal pool 数据字，objdump 误译） */
/* @0xe0ce4 eoreq r3, r5, r0, lsl r1 —— 非指令（literal pool 数据字，objdump 误译） */
/* @0xe0ce8 .word 0x002530d8 */
