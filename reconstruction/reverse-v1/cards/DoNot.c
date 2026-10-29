/* cally 逆向卡：DoNot（原版 libyoyo.so，armv7）
 * @func 0xd7908 0xd7c34  size 812  203 条指令（含尾部 7 个 literal 字）
 * 级别: 正文（203 条全部解码；三档 mode + 14 路 tag 表已定，mode 0 的"载荷是裸类型还是 RValue"未闭合）
 * 符号: _Z5DoNotjPhPKhP6VMExec → uchar* DoNot(uint32 arg, uchar* sp, const uchar* base, VMExec* exec)
 *
 * 已证（指令级）：
 *   mode = (arg >> 8) & 0xF；cls = (arg >> 16) & 0xF           ; d7908 / d791c / d7924
 *   mode 0（以及 3..15，比较落空即回落）→ 强类型快路：就地改载荷、sp 不动、返回 r6    ; d7934..d793c
 *       cls 0 double(8B)  ：ldrd → __fixdfdi → mvn pair → __floatdidf → strd              ; d7944 → d7a24
 *       cls 1 float (4B)  ：vldr s15 / vcvt.s32.f32 / mvn / vcvt.f32.s32 / vstr            ; d7948 → d7a4c
 *       cls 2 int32 (4B)  ：ldr / mvn / str                                                ; d794c → d7960
 *       cls 3 int64 (8B)  ：ldrd / mvn/mvn / strd                                          ; d7950 → d797c
 *       cls 4 bool  (4B)  ：ldr / rsbs r3,r3,#1 / movlo r3,#0 / str（1-x，负归 0）          ; d7954 → d799c
 *       cls 5 RValue(16B) ：读 +0xc 的 tag 走 14 路跳表                                     ; d7958 → d79bc
 *       cls 6 string(4B)  ：VMError "DoNot :: Execution Engine - Cannot operate on string type" ; d795c → d7a04
 *       cls >6            ：原样返回 r6                                                    ; d7940 → d7c10
 *   cls 5 的 tag 跳表（cmp r2,#13；表基 d79cc）：
 *       0 → double 取反（__fixdfdi/mvn/mvn/__floatdidf）d7b84 ；13 → 同上
 *       7 → int32 mvn d7960 ；10 → int64 mvn pair d7b50
 *       1 → "Cannot operate on string type" d7b6c ；2 → "DoNot :: illegal array use" d7ba4
 *       3/4/5/6/8/9/11/12 → "DoNot :: Malformed variable" d7be4 ；>13 → malformed（落空到 d79c8）
 *   mode 1（逻辑非 !）：boxType(sp+16, cls, sp) → [sp+0x1c] 若 == 0x00FFFFFF → JSThrowReferenceError
 *       ("could not find lhs variable in logical not") ；JS_ToBoolean(sp+16) → r0^1 → uxtb →
 *       写 1 B 到 boxed_sp-4，返回 boxed_sp-4（4 B 结果）                        ; d7a78..d7abc
 *   mode 2（按位取反 ~）：boxType(sp, cls, sp) → 同一未解析检查（"could not find lhs variable in binary not"）
 *       ；F_JS_ToInt32(sp+16, sp) → 返回 1 → JSThrowTypeError("Unary ~ could not convert expr to a number")
 *       ；返回非 0 → 直接返回 boxed_sp；返回 0 → vcvt.s32.f64 → mvn → vcvt.f64.s32 → tag 0 压 16 B，返回 boxed_sp-16
 *                                                  ; d7ac0..d7b4c
 *   RValue 释放闸：(tag-1)&0x00FFFFFC==0（tag ∈ 1..4）才 FREE_RValue__Pre   ; d7a90..d7aa8 等
 *
 * 结论：
 *   1. 同一个 DoNot 承载 ! / ~ / 强类型位取反 三种 opcode（mode 0/1/2），与 DoNeg 的 mode 分档完全同构
 *      （同一套编译器后端：mode=(arg>>8)&0xF，cls=(arg>>16)&0xF，cls>6 无操作，cls 6 报字符串错）。
 *   2. 两种通用 mode 的栈效应不同：! 只写 1 B（uxtb）并返回 boxed_sp-4；~ 写 16 B 的 Real 并返回 boxed_sp-16。
 *      所以 `!` 的字节码后续读的是 4 B 布尔，`~` 读的是完整 RValue，二者不可互换。
 *   3. 动态路径（cls 5）只有 tag 0/13（double）、7（int32）、10（int64）可算；数组/字符串/指针/未定义/其它
 *      各走专属消息，说明 `~` 在原版里是"数值运算"而不是"逐位操作任意布局"。
 * open：mode 0 的载荷是否就是 RValue 的 +0.. 裸类型数据（DoAdd 卡已证 mode 0 的槽是裸类型数据，此处只做了
 *       "就地改载荷、不写 tag"的观察，未做跨函数闭合）；tag 13 与 tag 0 的区别；mode 2 走 int32 中转而非 int64 的理由。
 *
 * ── 本批补证：逻辑非（逐条锚在下方）──
 *   __fixdfdi ×2（double→int64）+ __floatdidf ×2（回 double）+ boxType ×2 + JSThrowReferenceError ×2 + VMError ×4
 *   open 1 是否按 JS 语义（!x → 0/1）而非按位取反
 *   open 2 4 处 VMError 文案
 */

/* ── 段 1 · 序言 / mode·cls 位域（0xd7908..d7930） ── */
/* @0xd7908 ubfx r2, r0, #0x8, #0x4 */
/* @0xd790c cmp r2, #0 */
/* @0xd7910 push {r4, r5, r6, lr} */
/* @0xd7914 mov r6, r1 */
/* @0xd7918 sub sp, sp, #32 */
/* @0xd791c lsr r1, r0, #16 */
/* @0xd7920 beq 0xd7934 <_Z5DoNotjPhPKhP6VMExec+0x2c> */
/* @0xd7924 cmp r2, #1 */
/* @0xd7928 beq 0xd7a78 <_Z5DoNotjPhPKhP6VMExec+0x170> */
/* @0xd792c cmp r2, #2 */
/* @0xd7930 beq 0xd7ac0 <_Z5DoNotjPhPKhP6VMExec+0x1b8> */

/* ── 段 2 · 强类型快路分派（cls 0..6）与 int32/int64/float/double 体（0xd7934..d79b8） ── */
/* @0xd7934 and r2, r1, #15 */
/* @0xd7938 cmp r2, #6 */
/* @0xd793c addls pc, pc, r2, lsl #2 */
/* @0xd7940 b 0xd7c10 <_Z5DoNotjPhPKhP6VMExec+0x308> */
/* @0xd7944 b 0xd7a24 <_Z5DoNotjPhPKhP6VMExec+0x11c> */
/* @0xd7948 b 0xd7a4c <_Z5DoNotjPhPKhP6VMExec+0x144> */
/* @0xd794c b 0xd7960 <_Z5DoNotjPhPKhP6VMExec+0x58> */
/* @0xd7950 b 0xd797c <_Z5DoNotjPhPKhP6VMExec+0x74> */
/* @0xd7954 b 0xd799c <_Z5DoNotjPhPKhP6VMExec+0x94> */
/* @0xd7958 b 0xd79bc <_Z5DoNotjPhPKhP6VMExec+0xb4> */
/* @0xd795c b 0xd7a04 <_Z5DoNotjPhPKhP6VMExec+0xfc> */
/* @0xd7960 ldr r3, [r6] */
/* @0xd7964 mov r12, r6 */
/* @0xd7968 mvn r3, r3 */
/* @0xd796c str r3, [r6] */
/* @0xd7970 mov r0, r12 */
/* @0xd7974 add sp, sp, #32 */
/* @0xd7978 pop {r4, r5, r6, pc} */
/* @0xd797c ldrd r4, r5, [r6] */
/* @0xd7980 mov r12, r6 */
/* @0xd7984 mov r0, r12 */
/* @0xd7988 mvn r4, r4 */
/* @0xd798c mvn r5, r5 */
/* @0xd7990 strd r4, r5, [r6] */
/* @0xd7994 add sp, sp, #32 */
/* @0xd7998 pop {r4, r5, r6, pc} */
/* @0xd799c ldr r3, [r6] */
/* @0xd79a0 mov r12, r6 */
/* @0xd79a4 mov r0, r12 */
/* @0xd79a8 rsbs r3, r3, #1 */
/* @0xd79ac movlo r3, #0 */
/* @0xd79b0 str r3, [r6] */
/* @0xd79b4 add sp, sp, #32 */
/* @0xd79b8 pop {r4, r5, r6, pc} */

/* ── 段 3 · cls 5：RValue tag 跳表（0xd79bc..d7a00） ── */
/* @0xd79bc ldr r2, [r6, #0xc] */
/* @0xd79c0 cmp r2, #13 */
/* @0xd79c4 addls pc, pc, r2, lsl #2 */
/* @0xd79c8 b 0xd7be4 <_Z5DoNotjPhPKhP6VMExec+0x2dc> */
/* @0xd79cc b 0xd7b84 <_Z5DoNotjPhPKhP6VMExec+0x27c> */
/* @0xd79d0 b 0xd7b6c <_Z5DoNotjPhPKhP6VMExec+0x264> */
/* @0xd79d4 b 0xd7ba4 <_Z5DoNotjPhPKhP6VMExec+0x29c> */
/* @0xd79d8 b 0xd7be4 <_Z5DoNotjPhPKhP6VMExec+0x2dc> */
/* @0xd79dc b 0xd7be4 <_Z5DoNotjPhPKhP6VMExec+0x2dc> */
/* @0xd79e0 b 0xd7be4 <_Z5DoNotjPhPKhP6VMExec+0x2dc> */
/* @0xd79e4 b 0xd7be4 <_Z5DoNotjPhPKhP6VMExec+0x2dc> */
/* @0xd79e8 b 0xd7960 <_Z5DoNotjPhPKhP6VMExec+0x58> */
/* @0xd79ec b 0xd7be4 <_Z5DoNotjPhPKhP6VMExec+0x2dc> */
/* @0xd79f0 b 0xd7be4 <_Z5DoNotjPhPKhP6VMExec+0x2dc> */
/* @0xd79f4 b 0xd7b50 <_Z5DoNotjPhPKhP6VMExec+0x248> */
/* @0xd79f8 b 0xd7be4 <_Z5DoNotjPhPKhP6VMExec+0x2dc> */
/* @0xd79fc b 0xd7be4 <_Z5DoNotjPhPKhP6VMExec+0x2dc> */
/* @0xd7a00 b 0xd7b84 <_Z5DoNotjPhPKhP6VMExec+0x27c> */

/* ── 段 4 · cls 6 与 tag 错误分支（0xd7a04..d7a74） ── */
/* @0xd7a04 ldr r1, [pc, #0x20c] */
/* @0xd7a08 mov r0, r3 */
/* @0xd7a0c add r1, pc, r1 */
/* @0xd7a10 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd7a14 mov r12, r6 */
/* @0xd7a18 mov r0, r12 */
/* @0xd7a1c add sp, sp, #32 */
/* @0xd7a20 pop {r4, r5, r6, pc} */
/* @0xd7a24 ldrd r0, r1, [r6] */
/* @0xd7a28 bl 0x3194a0 <__fixdfdi> */
/* @0xd7a2c mvn r0, r0 */
/* @0xd7a30 mvn r1, r1 */
/* @0xd7a34 bl 0x319164 <__floatdidf> */
/* @0xd7a38 mov r12, r6 */
/* @0xd7a3c strd r0, r1, [r6] */
/* @0xd7a40 mov r0, r12 */
/* @0xd7a44 add sp, sp, #32 */
/* @0xd7a48 pop {r4, r5, r6, pc} */
/* @0xd7a4c vldr s15, [r6] */
/* @0xd7a50 vcvt.s32.f32 s15, s15 */
/* @0xd7a54 mov r12, r6 */
/* @0xd7a58 mov r0, r12 */
/* @0xd7a5c vmov r3, s15 */
/* @0xd7a60 mvn r3, r3 */
/* @0xd7a64 vmov s15, r3 */
/* @0xd7a68 vcvt.f32.s32 s15, s15 */
/* @0xd7a6c vstr s15, [r6] */
/* @0xd7a70 add sp, sp, #32 */
/* @0xd7a74 pop {r4, r5, r6, pc} */

/* ── 段 5 · mode 1：逻辑非（boxType + JS_ToBoolean）（0xd7a78..d7abc） ── */
/* @0xd7a78 add r4, sp, #16 */
/* @0xd7a7c mov r2, r6 */
/* @0xd7a80 and r1, r1, #15 */
/* @0xd7a84 mov r0, r4 */
/* @0xd7a88 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xd7a8c ldr r2, [sp, #0x1c] */
/* @0xd7a90 mvn r3, #-16777216 */
/* @0xd7a94 and r2, r2, r3 */
/* @0xd7a98 cmp r2, r3 */
/* @0xd7a9c mov r5, r0 */
/* @0xd7aa0 beq 0xd7bbc <_Z5DoNotjPhPKhP6VMExec+0x2b4> */
/* @0xd7aa4 mov r0, r4 */
/* @0xd7aa8 bl 0x2404bc <_Z12JS_ToBooleanR6RValue> */
/* @0xd7aac sub r12, r5, #4 */
/* @0xd7ab0 eor r0, r0, #1 */
/* @0xd7ab4 uxtb r3, r0 */
/* @0xd7ab8 str r3, [r5, #-0x4] */
/* @0xd7abc b 0xd7970 <_Z5DoNotjPhPKhP6VMExec+0x68> */

/* ── 段 6 · mode 2：按位取反（boxType + F_JS_ToInt32）（0xd7ac0..d7b4c） ── */
/* @0xd7ac0 mov r2, r6 */
/* @0xd7ac4 and r1, r1, #15 */
/* @0xd7ac8 mov r0, sp */
/* @0xd7acc bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xd7ad0 ldr r2, [sp, #0xc] */
/* @0xd7ad4 mvn r3, #-16777216 */
/* @0xd7ad8 and r2, r2, r3 */
/* @0xd7adc cmp r2, r3 */
/* @0xd7ae0 mov r4, r0 */
/* @0xd7ae4 beq 0xd7bd0 <_Z5DoNotjPhPKhP6VMExec+0x2c8> */
/* @0xd7ae8 mov r1, sp */
/* @0xd7aec add r0, sp, #16 */
/* @0xd7af0 str r3, [sp, #0x1c] */
/* @0xd7af4 mov r2, #0 */
/* @0xd7af8 mov r3, #0 */
/* @0xd7afc mov r12, #0 */
/* @0xd7b00 strd r2, r3, [sp, #16] */
/* @0xd7b04 str r12, [sp, #0x18] */
/* @0xd7b08 bl 0x24d5c8 <_Z12F_JS_ToInt32R6RValueS0_> */
/* @0xd7b0c cmp r0, #1 */
/* @0xd7b10 beq 0xd7bfc <_Z5DoNotjPhPKhP6VMExec+0x2f4> */
/* @0xd7b14 cmp r0, #0 */
/* @0xd7b18 movne r12, r4 */
/* @0xd7b1c bne 0xd7970 <_Z5DoNotjPhPKhP6VMExec+0x68> */
/* @0xd7b20 vldr d7, [sp, #16] */
/* @0xd7b24 vcvt.s32.f64 s13, d7 */
/* @0xd7b28 sub r12, r4, #16 */
/* @0xd7b2c str r0, [r4, #-0x4] */
/* @0xd7b30 vmov r2, s13 */
/* @0xd7b34 mvn r2, r2 */
/* @0xd7b38 vmov s15, r2 */
/* @0xd7b3c vcvt.f64.s32 d7, s15 */
/* @0xd7b40 vmov r2, r3, d7 */
/* @0xd7b44 vstr s14, [r4, #-16] */
/* @0xd7b48 str r3, [r4, #-0xc] */
/* @0xd7b4c b 0xd7970 <_Z5DoNotjPhPKhP6VMExec+0x68> */

/* ── 段 7 · tag 0/7/10 处理体与错误返回（0xd7b50..d7c14） ── */
/* @0xd7b50 ldr r4, [r6] */
/* @0xd7b54 mov r12, r6 */
/* @0xd7b58 ldr r5, [r6, #0x4] */
/* @0xd7b5c mvn r4, r4 */
/* @0xd7b60 mvn r5, r5 */
/* @0xd7b64 stm r6, {r4, r5} */
/* @0xd7b68 b 0xd7970 <_Z5DoNotjPhPKhP6VMExec+0x68> */
/* @0xd7b6c ldr r1, [pc, #0xa8] */
/* @0xd7b70 mov r0, r3 */
/* @0xd7b74 add r1, pc, r1 */
/* @0xd7b78 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd7b7c mov r12, r6 */
/* @0xd7b80 b 0xd7970 <_Z5DoNotjPhPKhP6VMExec+0x68> */
/* @0xd7b84 ldm r6, {r0, r1} */
/* @0xd7b88 bl 0x3194a0 <__fixdfdi> */
/* @0xd7b8c mvn r0, r0 */
/* @0xd7b90 mvn r1, r1 */
/* @0xd7b94 bl 0x319164 <__floatdidf> */
/* @0xd7b98 mov r12, r6 */
/* @0xd7b9c stm r6, {r0, r1} */
/* @0xd7ba0 b 0xd7970 <_Z5DoNotjPhPKhP6VMExec+0x68> */
/* @0xd7ba4 ldr r1, [pc, #0x74] */
/* @0xd7ba8 mov r0, r3 */
/* @0xd7bac add r1, pc, r1 */
/* @0xd7bb0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd7bb4 mov r12, r6 */
/* @0xd7bb8 b 0xd7970 <_Z5DoNotjPhPKhP6VMExec+0x68> */
/* @0xd7bbc ldr r0, [pc, #0x60] */
/* @0xd7bc0 add r0, pc, r0 */
/* @0xd7bc4 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xd7bc8 mov r12, r5 */
/* @0xd7bcc b 0xd7970 <_Z5DoNotjPhPKhP6VMExec+0x68> */
/* @0xd7bd0 ldr r0, [pc, #0x50] */
/* @0xd7bd4 add r0, pc, r0 */
/* @0xd7bd8 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xd7bdc mov r12, r4 */
/* @0xd7be0 b 0xd7970 <_Z5DoNotjPhPKhP6VMExec+0x68> */
/* @0xd7be4 ldr r1, [pc, #0x40] */
/* @0xd7be8 mov r0, r3 */
/* @0xd7bec add r1, pc, r1 */
/* @0xd7bf0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd7bf4 mov r12, r6 */
/* @0xd7bf8 b 0xd7970 <_Z5DoNotjPhPKhP6VMExec+0x68> */
/* @0xd7bfc ldr r0, [pc, #0x2c] */
/* @0xd7c00 add r0, pc, r0 */
/* @0xd7c04 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xd7c08 mov r12, r4 */
/* @0xd7c0c b 0xd7970 <_Z5DoNotjPhPKhP6VMExec+0x68> */
/* @0xd7c10 mov r12, r6 */
/* @0xd7c14 b 0xd7970 <_Z5DoNotjPhPKhP6VMExec+0x68> */

/* ── 段 8 · literal pool（非指令） ── */
/* @0xd7c18 eoreq r11, r5, r0, lsl #3 —— 非指令（literal pool 数据字，objdump 误译） */
/* @0xd7c1c eoreq r11, r5, r8, lsl r0 —— 非指令（literal pool 数据字，objdump 误译） */
/* @0xd7c20 eoreq r11, r5, r12, lsl r0 —— 非指令（literal pool 数据字，objdump 误译） */
/* @0xd7c24 eoreq r10, r5, r8, asr #30 —— 非指令（literal pool 数据字，objdump 误译） */
/* @0xd7c28 eoreq r10, r5, r0, ror #30 —— 非指令（literal pool 数据字，objdump 误译） */
/* @0xd7c2c .word 0x0025aff8 —— 非指令（literal pool 数据字，objdump 误译） */
/* @0xd7c30 eoreq r10, r5, r0, ror #30 */
