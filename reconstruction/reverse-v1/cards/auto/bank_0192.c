/* libyoyo.so 覆盖卡组 0192
 * 函数 0x216560..0x217a80，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x216560 · Audio_GetNoiseFromQueuedSoundID(int) · size=96 · insn=24 */
/* @0x216560 ldr r3, [pc, #0x54] */
/* @0x216564 str r4, [sp, #-0x4]! */
/* @0x216568 add r3, pc, r3 */
/* @0x21656c ldr r4, [r3, #0x38] */
/* @0x216570 cmp r4, #0 */
/* @0x216574 ble 0x2165ac <_Z31Audio_GetNoiseFromQueuedSoundIDi+0x4c> */
/* @0x216578 ldr r1, [r3, #0x3c] */
/* @0x21657c mov r3, #0 */
/* @0x216580 sub r1, r1, #4 */
/* @0x216584 ldr r2, [r1, #0x4]! */
/* @0x216588 add r3, r3, #1 */
/* @0x21658c ldr r12, [r2, #0x8] */
/* @0x216590 cmp r12, #0 */
/* @0x216594 bne 0x2165a4 <_Z31Audio_GetNoiseFromQueuedSoundIDi+0x44> */
/* @0x216598 ldr r12, [r2, #0x18] */
/* @0x21659c cmp r12, r0 */
/* @0x2165a0 beq 0x2165b0 <_Z31Audio_GetNoiseFromQueuedSoundIDi+0x50> */
/* @0x2165a4 cmp r3, r4 */
/* @0x2165a8 bne 0x216584 <_Z31Audio_GetNoiseFromQueuedSoundIDi+0x24> */
/* @0x2165ac mov r2, #0 */
/* @0x2165b0 mov r0, r2 */
/* @0x2165b4 ldr r4, [sp], #4 */
/* @0x2165b8 bx lr */
/* @0x2165bc subseq lr, r3, r12, lsr #26 */

/* ── FUNC 0x2165c0 · Audio_SetListenerPosition(int, double, double, double) · size=72 · insn=18 */
/* @0x2165c0 cmp r0, #0 */
/* @0x2165c4 vmov d7, r2, r3 */
/* @0x2165c8 bxne lr */
/* @0x2165cc ldr r3, [pc, #0x30] */
/* @0x2165d0 ldr r3, [pc, r3] */
/* @0x2165d4 ldr r3, [r3] */
/* @0x2165d8 cmp r3, #0 */
/* @0x2165dc bxeq lr */
/* @0x2165e0 vcvt.f32.f64 s14, d7 */
/* @0x2165e4 vldr d5, [sp] */
/* @0x2165e8 vcvt.f32.f64 s13, d5 */
/* @0x2165ec vldr d5, [sp, #8] */
/* @0x2165f0 vstr s14, [r3] */
/* @0x2165f4 vcvt.f32.f64 s15, d5 */
/* @0x2165f8 vstr s13, [r3, #4] */
/* @0x2165fc vstr s15, [r3, #8] */
/* @0x216600 bx lr */
/* @0x216604 andseq r10, sp, r12, lsl #28 */

/* ── FUNC 0x216608 · Audio_SetListenerVelocity(int, double, double, double) · size=72 · insn=18 */
/* @0x216608 cmp r0, #0 */
/* @0x21660c vmov d7, r2, r3 */
/* @0x216610 bxne lr */
/* @0x216614 ldr r3, [pc, #0x30] */
/* @0x216618 ldr r3, [pc, r3] */
/* @0x21661c ldr r3, [r3] */
/* @0x216620 cmp r3, #0 */
/* @0x216624 bxeq lr */
/* @0x216628 vcvt.f32.f64 s14, d7 */
/* @0x21662c vldr d5, [sp] */
/* @0x216630 vcvt.f32.f64 s13, d5 */
/* @0x216634 vldr d5, [sp, #8] */
/* @0x216638 vstr s14, [r3, #12] */
/* @0x21663c vcvt.f32.f64 s15, d5 */
/* @0x216640 vstr s13, [r3, #16] */
/* @0x216644 vstr s15, [r3, #20] */
/* @0x216648 bx lr */
/* @0x21664c andseq r10, sp, r4, asr #27 */

/* ── FUNC 0x216650 · Audio_SetListenerOrientation(int, double, double, double, double, double, double) · size=108 · insn=27 */
/* @0x216650 cmp r0, #0 */
/* @0x216654 vmov d7, r2, r3 */
/* @0x216658 bxne lr */
/* @0x21665c ldr r3, [pc, #0x54] */
/* @0x216660 ldr r3, [pc, r3] */
/* @0x216664 ldr r3, [r3] */
/* @0x216668 cmp r3, #0 */
/* @0x21666c bxeq lr */
/* @0x216670 vcvt.f32.f64 s14, d7 */
/* @0x216674 vldr d6, [sp] */
/* @0x216678 vcvt.f32.f64 s15, d6 */
/* @0x21667c vstr s14, [r3, #24] */
/* @0x216680 vldr d6, [sp, #8] */
/* @0x216684 vstr s15, [r3, #28] */
/* @0x216688 vcvt.f32.f64 s14, d6 */
/* @0x21668c vldr d6, [sp, #16] */
/* @0x216690 vcvt.f32.f64 s15, d6 */
/* @0x216694 vstr s14, [r3, #32] */
/* @0x216698 vldr d6, [sp, #24] */
/* @0x21669c vstr s15, [r3, #36] */
/* @0x2166a0 vcvt.f32.f64 s14, d6 */
/* @0x2166a4 vldr d6, [sp, #32] */
/* @0x2166a8 vcvt.f32.f64 s15, d6 */
/* @0x2166ac vstr s14, [r3, #40] */
/* @0x2166b0 vstr s15, [r3, #44] */
/* @0x2166b4 bx lr */
/* @0x2166b8 andseq r10, sp, r12, ror sp */

/* ── FUNC 0x2166bc · Audio_Init(SoundHardware*) · size=288 · insn=72 */
/* @0x2166bc push {r4, r5, r6, r7, lr} */
/* @0x2166c0 sub sp, sp, #44 */
/* @0x2166c4 ldr r6, [pc, #0xf4] */
/* @0x2166c8 ldr r2, [pc, #0xf4] */
/* @0x2166cc add r6, pc, r6 */
/* @0x2166d0 ldr r3, [pc, #0xf0] */
/* @0x2166d4 ldr r2, [r6, r2] */
/* @0x2166d8 str r0, [r2] */
/* @0x2166dc ldr r3, [r6, r3] */
/* @0x2166e0 ldrb r3, [r3] */
/* @0x2166e4 cmp r3, #0 */
/* @0x2166e8 ldr r3, [pc, #0xdc] */
/* @0x2166ec beq 0x216704 <_Z10Audio_InitP13SoundHardware+0x48> */
/* @0x2166f0 ldr r3, [r6, r3] */
/* @0x2166f4 mov r2, #0 */
/* @0x2166f8 strb r2, [r3] */
/* @0x2166fc add sp, sp, #44 */
/* @0x216700 pop {r4, r5, r6, r7, pc} */
/* @0x216704 ldr r3, [r6, r3] */
/* @0x216708 ldrb r3, [r3] */
/* @0x21670c cmp r3, #0 */
/* @0x216710 beq 0x2166fc <_Z10Audio_InitP13SoundHardware+0x40> */
/* @0x216714 ldr r3, [pc, #0xb4] */
/* @0x216718 ldr r4, [r6, r3] */
/* @0x21671c ldr r3, [r4] */
/* @0x216720 cmp r3, #0 */
/* @0x216724 beq 0x2167a8 <_Z10Audio_InitP13SoundHardware+0xec> */
/* @0x216728 ldr r3, [pc, #0xa4] */
/* @0x21672c mov r4, #0 */
/* @0x216730 mov r5, #0 */
/* @0x216734 mov r7, #0 */
/* @0x216738 movt r7, #0x3ff0 */
/* @0x21673c ldr r3, [r6, r3] */
/* @0x216740 mov r6, #0 */
/* @0x216744 ldr r0, [r3] */
/* @0x216748 add r0, r0, #1 */
/* @0x21674c bl 0x21625c <_Z19Audio_CreateSourcesi> */
/* @0x216750 movw r0, #0xd001 */
/* @0x216754 bl 0xb6aa8 <alDistanceModel@plt> */
/* @0x216758 mov r2, r4 */
/* @0x21675c mov r3, r5 */
/* @0x216760 strd r4, r5, [sp] */
/* @0x216764 strd r4, r5, [sp, #8] */
/* @0x216768 mov r0, #0 */
/* @0x21676c bl 0x2165c0 <_Z25Audio_SetListenerPositioniddd> */
/* @0x216770 strd r4, r5, [sp] */
/* @0x216774 strd r4, r5, [sp, #16] */
/* @0x216778 mov r2, r4 */
/* @0x21677c strd r4, r5, [sp, #32] */
/* @0x216780 mov r3, r5 */
/* @0x216784 mov r0, #0 */
/* @0x216788 strd r6, r7, [sp, #8] */
/* @0x21678c strd r6, r7, [sp, #24] */
/* @0x216790 bl 0x216650 <_Z28Audio_SetListenerOrientationidddddd> */
/* @0x216794 ldr r0, [pc, #0x3c] */
/* @0x216798 add r0, pc, r0 */
/* @0x21679c add sp, sp, #44 */
/* @0x2167a0 pop {r4, r5, r6, r7, lr} */
/* @0x2167a4 b 0x215fd0 <_Z7checkALPKc> */
/* @0x2167a8 mov r0, #52 */
/* @0x2167ac bl 0x27c524 <_Znwj> */
/* @0x2167b0 mov r5, r0 */
/* @0x2167b4 bl 0x215ae8 <_ZN9CListenerC2Ev> */
/* @0x2167b8 str r5, [r4] */
/* @0x2167bc b 0x216728 <_Z10Audio_InitP13SoundHardware+0x6c> */
/* @0x2167c0 andseq r11, sp, r4, lsl #11 */
/* @0x2167c4 .word 0xfffff790 */
/* @0x2167c8 .word 0xffffd3fc */
/* @0x2167cc .word 0xffffd0e0 */
/* @0x2167d0 .word 0xfffff78c */
/* @0x2167d4 .word 0xfffff784 */
/* @0x2167d8 andseq sp, r3, r4, lsr #8 */

/* ── FUNC 0x2167dc · Audio_GetListenerData(int) · size=444 · insn=111 */
/* @0x2167dc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2167e0 subs r4, r0, #0 */
/* @0x2167e4 sub sp, sp, #188 */
/* @0x2167e8 bne 0x21695c <_Z21Audio_GetListenerDatai+0x180> */
/* @0x2167ec ldr r3, [pc, #0x170] */
/* @0x2167f0 ldr r3, [pc, r3] */
/* @0x2167f4 ldr r12, [r3] */
/* @0x2167f8 cmp r12, #0 */
/* @0x2167fc beq 0x21695c <_Z21Audio_GetListenerDatai+0x180> */
/* @0x216800 ldr lr, [pc, #0x160] */
/* @0x216804 vldr s15, [r12] */
/* @0x216808 str r4, [sp] */
/* @0x21680c vcvt.f64.f32 d6, s15 */
/* @0x216810 add lr, pc, lr */
/* @0x216814 str lr, [sp, #0x4] */
/* @0x216818 vldr s14, [r12, #4] */
/* @0x21681c ldr r1, [pc, #0x148] */
/* @0x216820 str r4, [sp, #0x10] */
/* @0x216824 mov r0, #12 */
/* @0x216828 add r1, pc, r1 */
/* @0x21682c str r1, [sp, #0x14] */
/* @0x216830 ldr r1, [pc, #0x138] */
/* @0x216834 ldr r11, [pc, #0x138] */
/* @0x216838 vcvt.f64.f32 d7, s14 */
/* @0x21683c add r1, pc, r1 */
/* @0x216840 add r11, pc, r11 */
/* @0x216844 ldr r10, [pc, #0x12c] */
/* @0x216848 ldr r9, [pc, #0x12c] */
/* @0x21684c add r10, pc, r10 */
/* @0x216850 ldr r8, [pc, #0x128] */
/* @0x216854 add r9, pc, r9 */
/* @0x216858 ldr r7, [pc, #0x124] */
/* @0x21685c add r8, pc, r8 */
/* @0x216860 ldr r6, [pc, #0x120] */
/* @0x216864 add r7, pc, r7 */
/* @0x216868 ldr r5, [pc, #0x11c] */
/* @0x21686c vstr d7, [sp, #8] */
/* @0x216870 vldr s14, [r12, #8] */
/* @0x216874 vcvt.f64.f32 d7, s14 */
/* @0x216878 str r1, [sp, #0x24] */
/* @0x21687c str r4, [sp, #0x20] */
/* @0x216880 add r6, pc, r6 */
/* @0x216884 add r5, pc, r5 */
/* @0x216888 ldr lr, [pc, #0x100] */
/* @0x21688c ldr r1, [pc, #0x100] */
/* @0x216890 add lr, pc, lr */
/* @0x216894 vmov r2, r3, d6 */
/* @0x216898 add r1, pc, r1 */
/* @0x21689c vstr d7, [sp, #24] */
/* @0x2168a0 vldr s14, [r12, #12] */
/* @0x2168a4 vcvt.f64.f32 d7, s14 */
/* @0x2168a8 str r4, [sp, #0x30] */
/* @0x2168ac str r11, [sp, #0x34] */
/* @0x2168b0 vstr d7, [sp, #40] */
/* @0x2168b4 vldr s14, [r12, #16] */
/* @0x2168b8 vcvt.f64.f32 d7, s14 */
/* @0x2168bc str r4, [sp, #0x40] */
/* @0x2168c0 str r10, [sp, #0x44] */
/* @0x2168c4 vstr d7, [sp, #56] */
/* @0x2168c8 vldr s14, [r12, #20] */
/* @0x2168cc vcvt.f64.f32 d7, s14 */
/* @0x2168d0 str r4, [sp, #0x50] */
/* @0x2168d4 str r9, [sp, #0x54] */
/* @0x2168d8 vstr d7, [sp, #72] */
/* @0x2168dc vldr s14, [r12, #24] */
/* @0x2168e0 vcvt.f64.f32 d7, s14 */
/* @0x2168e4 str r4, [sp, #0x60] */
/* @0x2168e8 str r8, [sp, #0x64] */
/* @0x2168ec vstr d7, [sp, #88] */
/* @0x2168f0 vldr s14, [r12, #28] */
/* @0x2168f4 vcvt.f64.f32 d7, s14 */
/* @0x2168f8 str r4, [sp, #0x70] */
/* @0x2168fc str r7, [sp, #0x74] */
/* @0x216900 vstr d7, [sp, #104] */
/* @0x216904 vldr s14, [r12, #32] */
/* @0x216908 vcvt.f64.f32 d7, s14 */
/* @0x21690c vstr d7, [sp, #120] */
/* @0x216910 str r4, [sp, #0x80] */
/* @0x216914 str r6, [sp, #0x84] */
/* @0x216918 vldr s14, [r12, #36] */
/* @0x21691c vcvt.f64.f32 d7, s14 */
/* @0x216920 str r4, [sp, #0x90] */
/* @0x216924 str r5, [sp, #0x94] */
/* @0x216928 vstr d7, [sp, #136] */
/* @0x21692c vldr s14, [r12, #40] */
/* @0x216930 vcvt.f64.f32 d7, s14 */
/* @0x216934 str r4, [sp, #0xa0] */
/* @0x216938 str lr, [sp, #0xa4] */
/* @0x21693c vstr d7, [sp, #152] */
/* @0x216940 vldr s14, [r12, #44] */
/* @0x216944 vcvt.f64.f32 d7, s14 */
/* @0x216948 str r4, [sp, #0xb0] */
/* @0x21694c vstr d7, [sp, #168] */
/* @0x216950 bl 0x20bdc0 <_Z11CreateDsMapiz> */
/* @0x216954 add sp, sp, #188 */
/* @0x216958 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x21695c mvn r0, #0 */
/* @0x216960 b 0x216954 <_Z21Audio_GetListenerDatai+0x178> */
/* @0x216964 andseq r10, sp, r12, ror #23 */
/* @0x216968 andseq r10, r1, r8, rrx */
/* @0x21696c andseq sp, r3, r0, lsr #7 */
/* @0x216970 mulseq r3, r0, r3 */
/* @0x216974 mulseq r3, r0, r3 */
/* @0x216978 andseq sp, r3, r8, lsl #7 */
/* @0x21697c andseq sp, r3, r4, lsl #7 */
/* @0x216980 andseq sp, r3, r8, lsl #7 */
/* @0x216984 andseq sp, r3, r12, lsl #7 */
/* @0x216988 andseq sp, r3, r12, ror r3 */
/* @0x21698c andseq sp, r3, r0, lsl #7 */
/* @0x216990 andseq sp, r3, r12, ror r3 */
/* @0x216994 ldrsbeq r9, [r1], -r12 */

/* ── FUNC 0x216998 · Audio_Model() · size=20 · insn=5 */
/* @0x216998 ldr r3, [pc, #0x8] */
/* @0x21699c ldr r3, [pc, r3] */
/* @0x2169a0 ldrb r0, [r3] */
/* @0x2169a4 bx lr */
/* @0x2169a8 mulseq sp, r4, r3 */

/* ── FUNC 0x2169ac · Audio_CreateEmitter() · size=744 · insn=186 */
/* @0x2169ac ldr r3, [pc, #0x29c] */
/* @0x2169b0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2169b4 ldr r3, [pc, r3] */
/* @0x2169b8 sub sp, sp, #20 */
/* @0x2169bc ldrb r3, [r3] */
/* @0x2169c0 cmp r3, #0 */
/* @0x2169c4 beq 0x216c48 <_Z19Audio_CreateEmitterv+0x29c> */
/* @0x2169c8 ldr r3, [pc, #0x284] */
/* @0x2169cc add r3, pc, r3 */
/* @0x2169d0 ldr r7, [r3, #0x40] */
/* @0x2169d4 cmp r7, #0 */
/* @0x2169d8 ble 0x216c40 <_Z19Audio_CreateEmitterv+0x294> */
/* @0x2169dc ldr r10, [pc, #0x274] */
/* @0x2169e0 mov r5, #0 */
/* @0x2169e4 ldr r9, [pc, #0x270] */
/* @0x2169e8 mov r4, r5 */
/* @0x2169ec ldr r8, [pc, #0x26c] */
/* @0x2169f0 add r10, pc, r10 */
/* @0x2169f4 add r9, pc, r9 */
/* @0x2169f8 mov r3, r7 */
/* @0x2169fc add r8, pc, r8 */
/* @0x216a00 b 0x216a38 <_Z19Audio_CreateEmitterv+0x8c> */
/* @0x216a04 bl 0x27c524 <_Znwj> */
/* @0x216a08 mov r6, r0 */
/* @0x216a0c bl 0x2157c8 <_ZN8CEmitterC2Ev> */
/* @0x216a10 ldr r3, [r10, #0x44] */
/* @0x216a14 str r6, [r3, r5] */
/* @0x216a18 add r5, r5, #4 */
/* @0x216a1c ldrb r3, [r6, #0x18] */
/* @0x216a20 cmp r3, #0 */
/* @0x216a24 beq 0x216a64 <_Z19Audio_CreateEmitterv+0xb8> */
/* @0x216a28 add r4, r4, #1 */
/* @0x216a2c cmp r4, r7 */
/* @0x216a30 beq 0x216a7c <_Z19Audio_CreateEmitterv+0xd0> */
/* @0x216a34 ldr r3, [r8, #0x40] */
/* @0x216a38 cmp r4, r3 */
/* @0x216a3c mov r0, #60 */
/* @0x216a40 bge 0x216a04 <_Z19Audio_CreateEmitterv+0x58> */
/* @0x216a44 ldr r3, [r9, #0x44] */
/* @0x216a48 ldr r6, [r3, r5] */
/* @0x216a4c cmp r6, #0 */
/* @0x216a50 beq 0x216a04 <_Z19Audio_CreateEmitterv+0x58> */
/* @0x216a54 ldrb r3, [r6, #0x18] */
/* @0x216a58 add r5, r5, #4 */
/* @0x216a5c cmp r3, #0 */
/* @0x216a60 bne 0x216a28 <_Z19Audio_CreateEmitterv+0x7c> */
/* @0x216a64 mov r7, r4 */
/* @0x216a68 mov r3, #1 */
/* @0x216a6c strb r3, [r6, #0x18] */
/* @0x216a70 mov r0, r7 */
/* @0x216a74 add sp, sp, #20 */
/* @0x216a78 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x216a7c ldr r3, [pc, #0x1e0] */
/* @0x216a80 add r3, pc, r3 */
/* @0x216a84 ldr r2, [r3, #0x40] */
/* @0x216a88 add r8, r7, #8 */
/* @0x216a8c cmp r8, r2 */
/* @0x216a90 moveq r8, r2 */
/* @0x216a94 beq 0x216ba0 <_Z19Audio_CreateEmitterv+0x1f4> */
/* @0x216a98 cmp r8, #0 */
/* @0x216a9c bne 0x216b64 <_Z19Audio_CreateEmitterv+0x1b8> */
/* @0x216aa0 ldr r9, [pc, #0x1c0] */
/* @0x216aa4 add r9, pc, r9 */
/* @0x216aa8 ldr r3, [r9, #0x44] */
/* @0x216aac cmp r3, #0 */
/* @0x216ab0 beq 0x216c24 <_Z19Audio_CreateEmitterv+0x278> */
/* @0x216ab4 cmp r2, #0 */
/* @0x216ab8 ble 0x216b48 <_Z19Audio_CreateEmitterv+0x19c> */
/* @0x216abc ldr r11, [pc, #0x1a8] */
/* @0x216ac0 mov r4, r8 */
/* @0x216ac4 ldr r12, [pc, #0x1a4] */
/* @0x216ac8 mov r10, r8 */
/* @0x216acc add r11, pc, r11 */
/* @0x216ad0 add r12, pc, r12 */
/* @0x216ad4 ldr r0, [r3] */
/* @0x216ad8 movw r2, #0xfeee */
/* @0x216adc movt r2, #0xfeee */
/* @0x216ae0 movw r1, #0xfeee */
/* @0x216ae4 cmp r0, r2 */
/* @0x216ae8 movt r1, #0xfeee */
/* @0x216aec lsl r6, r4, #2 */
/* @0x216af0 beq 0x216b38 <_Z19Audio_CreateEmitterv+0x18c> */
/* @0x216af4 ldr r5, [r3, r4, lsl #2] */
/* @0x216af8 add r2, r3, r6 */
/* @0x216afc cmp r5, #0 */
/* @0x216b00 mov r0, r5 */
/* @0x216b04 beq 0x216b38 <_Z19Audio_CreateEmitterv+0x18c> */
/* @0x216b08 ldr r3, [r5] */
/* @0x216b0c cmp r3, r1 */
/* @0x216b10 beq 0x216b30 <_Z19Audio_CreateEmitterv+0x184> */
/* @0x216b14 str r12, [sp, #0xc] */
/* @0x216b18 bl 0x21580c <_ZN8CEmitterD2Ev> */
/* @0x216b1c mov r0, r5 */
/* @0x216b20 bl 0x27d1d0 <_ZdlPv> */
/* @0x216b24 ldr r12, [sp, #0xc] */
/* @0x216b28 ldr r2, [r12, #0x44] */
/* @0x216b2c add r2, r2, r6 */
/* @0x216b30 str r10, [r2] */
/* @0x216b34 ldr r3, [r11, #0x44] */
/* @0x216b38 ldr r2, [r9, #0x40] */
/* @0x216b3c add r4, r4, #1 */
/* @0x216b40 cmp r4, r2 */
/* @0x216b44 blt 0x216ad4 <_Z19Audio_CreateEmitterv+0x128> */
/* @0x216b48 mov r0, r3 */
/* @0x216b4c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x216b50 ldr r3, [pc, #0x11c] */
/* @0x216b54 mov r2, #0 */
/* @0x216b58 add r3, pc, r3 */
/* @0x216b5c str r2, [r3, #0x44] */
/* @0x216b60 b 0x216b94 <_Z19Audio_CreateEmitterv+0x1e8> */
/* @0x216b64 lsls r1, r8, #2 */
/* @0x216b68 beq 0x216c18 <_Z19Audio_CreateEmitterv+0x26c> */
/* @0x216b6c ldr r4, [pc, #0x104] */
/* @0x216b70 mov r3, #0 */
/* @0x216b74 ldr r2, [pc, #0x100] */
/* @0x216b78 add r4, pc, r4 */
/* @0x216b7c str r3, [sp] */
/* @0x216b80 add r2, pc, r2 */
/* @0x216b84 mov r3, #135 */
/* @0x216b88 ldr r0, [r4, #0x44] */
/* @0x216b8c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x216b90 str r0, [r4, #0x44] */
/* @0x216b94 ldr r3, [pc, #0xe4] */
/* @0x216b98 add r3, pc, r3 */
/* @0x216b9c str r8, [r3, #0x40] */
/* @0x216ba0 cmp r7, r8 */
/* @0x216ba4 lslge r5, r7, #2 */
/* @0x216ba8 blt 0x216be8 <_Z19Audio_CreateEmitterv+0x23c> */
/* @0x216bac mov r0, #60 */
/* @0x216bb0 bl 0x27c524 <_Znwj> */
/* @0x216bb4 mov r4, r0 */
/* @0x216bb8 bl 0x2157c8 <_ZN8CEmitterC2Ev> */
/* @0x216bbc ldr r3, [pc, #0xc0] */
/* @0x216bc0 mov r0, r4 */
/* @0x216bc4 add r3, pc, r3 */
/* @0x216bc8 ldr r3, [r3, #0x44] */
/* @0x216bcc str r4, [r3, r5] */
/* @0x216bd0 bl 0x215774 <_ZN8CEmitter5ResetEv> */
/* @0x216bd4 mov r3, #1 */
/* @0x216bd8 strb r3, [r4, #0x18] */
/* @0x216bdc mov r0, r7 */
/* @0x216be0 add sp, sp, #20 */
/* @0x216be4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x216be8 ldr r3, [pc, #0x98] */
/* @0x216bec lsl r5, r7, #2 */
/* @0x216bf0 add r3, pc, r3 */
/* @0x216bf4 ldr r3, [r3, #0x44] */
/* @0x216bf8 ldr r4, [r3, r7, lsl #2] */
/* @0x216bfc cmp r4, #0 */
/* @0x216c00 beq 0x216bac <_Z19Audio_CreateEmitterv+0x200> */
/* @0x216c04 mov r0, r4 */
/* @0x216c08 bl 0x215774 <_ZN8CEmitter5ResetEv> */
/* @0x216c0c mov r3, #1 */
/* @0x216c10 strb r3, [r4, #0x18] */
/* @0x216c14 b 0x216bdc <_Z19Audio_CreateEmitterv+0x230> */
/* @0x216c18 ldr r3, [pc, #0x6c] */
/* @0x216c1c add r3, pc, r3 */
/* @0x216c20 ldr r3, [r3, #0x44] */
/* @0x216c24 mov r0, r3 */
/* @0x216c28 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x216c2c ldr r3, [pc, #0x5c] */
/* @0x216c30 mov r2, #0 */
/* @0x216c34 add r3, pc, r3 */
/* @0x216c38 str r2, [r3, #0x44] */
/* @0x216c3c b 0x216b94 <_Z19Audio_CreateEmitterv+0x1e8> */
/* @0x216c40 mov r2, r7 */
/* @0x216c44 b 0x216a88 <_Z19Audio_CreateEmitterv+0xdc> */
/* @0x216c48 mvn r7, #0 */
/* @0x216c4c b 0x216a70 <_Z19Audio_CreateEmitterv+0xc4> */
/* @0x216c50 andseq r8, sp, r12, ror r3 */
/* @0x216c54 subseq lr, r3, r8, asr #17 */
/* @0x216c58 subseq lr, r3, r4, lsr #17 */
/* @0x216c5c subseq lr, r3, r0, lsr #17 */
/* @0x216c60 .word 0x0053e898 */
/* @0x216c64 subseq lr, r3, r4, lsl r8 */
/* @0x216c68 ldrsheq lr, [r3], #-112 */
/* @0x216c6c subseq lr, r3, r8, asr #15 */
/* @0x216c70 subseq lr, r3, r4, asr #15 */
/* @0x216c74 subseq lr, r3, r12, lsr r7 */
/* @0x216c78 subseq lr, r3, r12, lsl r7 */
/* @0x216c7c andseq r6, r3, r0, ror r7 */
/* @0x216c80 ldrsheq lr, [r3], #-108 */
/* @0x216c84 ldrsbeq lr, [r3], #-96 */
/* @0x216c88 subseq lr, r3, r4, lsr #13 */
/* @0x216c8c subseq lr, r3, r8, ror r6 */
/* @0x216c90 subseq lr, r3, r0, ror #12 */

/* ── FUNC 0x216c94 · Audio_SetEmitterFalloff(int, double, double, double) · size=356 · insn=89 */
/* @0x216c94 ldr r1, [pc, #0x148] */
/* @0x216c98 vmov d7, r2, r3 */
/* @0x216c9c push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x216ca0 vpush {d8, d9} */
/* @0x216ca4 ldr r1, [pc, r1] */
/* @0x216ca8 ldrb r3, [r1] */
/* @0x216cac cmp r3, #0 */
/* @0x216cb0 beq 0x216ddc <_Z23Audio_SetEmitterFalloffiddd+0x148> */
/* @0x216cb4 ldr r3, [pc, #0x12c] */
/* @0x216cb8 add r3, pc, r3 */
/* @0x216cbc ldr r4, [r3, #0x40] */
/* @0x216cc0 cmp r4, r0 */
/* @0x216cc4 movgt r4, #0 */
/* @0x216cc8 movle r4, #1 */
/* @0x216ccc orrs r4, r4, r0, lsr #31 */
/* @0x216cd0 bne 0x216ddc <_Z23Audio_SetEmitterFalloffiddd+0x148> */
/* @0x216cd4 ldr r3, [r3, #0x44] */
/* @0x216cd8 ldr r6, [r3, r0, lsl #2] */
/* @0x216cdc cmp r6, #0 */
/* @0x216ce0 beq 0x216ddc <_Z23Audio_SetEmitterFalloffiddd+0x148> */
/* @0x216ce4 vcvt.f32.f64 s16, d7 */
/* @0x216ce8 vldr d6, [sp, #48] */
/* @0x216cec vldr d7, [sp, #56] */
/* @0x216cf0 ldr r7, [r6, #0x34] */
/* @0x216cf4 cmp r7, #0 */
/* @0x216cf8 vcvt.f32.f64 s17, d6 */
/* @0x216cfc vstr s16, [r6, #28] */
/* @0x216d00 vcvt.f32.f64 s18, d7 */
/* @0x216d04 vstr s17, [r6, #32] */
/* @0x216d08 vstr s18, [r6, #36] */
/* @0x216d0c ble 0x216ddc <_Z23Audio_SetEmitterFalloffiddd+0x148> */
/* @0x216d10 ldr r9, [pc, #0xd4] */
/* @0x216d14 mov r3, r7 */
/* @0x216d18 add r9, pc, r9 */
/* @0x216d1c b 0x216d30 <_Z23Audio_SetEmitterFalloffiddd+0x9c> */
/* @0x216d20 add r4, r4, #1 */
/* @0x216d24 cmp r4, r7 */
/* @0x216d28 beq 0x216ddc <_Z23Audio_SetEmitterFalloffiddd+0x148> */
/* @0x216d2c ldr r3, [r6, #0x34] */
/* @0x216d30 cmp r3, r4 */
/* @0x216d34 ble 0x216d20 <_Z23Audio_SetEmitterFalloffiddd+0x8c> */
/* @0x216d38 ldr r3, [r6, #0x38] */
/* @0x216d3c ldr r5, [r3, r4, lsl #2] */
/* @0x216d40 cmp r5, #0 */
/* @0x216d44 mov r0, r5 */
/* @0x216d48 beq 0x216d20 <_Z23Audio_SetEmitterFalloffiddd+0x8c> */
/* @0x216d4c bl 0x2164bc <_Z20Audio_NoiseIsPlayingP6CNoise> */
/* @0x216d50 cmp r0, #0 */
/* @0x216d54 beq 0x216d20 <_Z23Audio_SetEmitterFalloffiddd+0x8c> */
/* @0x216d58 ldr r8, [pc, #0x90] */
/* @0x216d5c movw r1, #0x1023 */
/* @0x216d60 ldr r0, [r5, #0x10] */
/* @0x216d64 ldr r8, [pc, r8] */
/* @0x216d68 vmov r2, s17 */
/* @0x216d6c ldr r3, [r8] */
/* @0x216d70 ldr r0, [r3, r0, lsl #2] */
/* @0x216d74 bl 0xb6a78 <alSourcef@plt> */
/* @0x216d78 ldr r3, [r8] */
/* @0x216d7c ldr r0, [r5, #0x10] */
/* @0x216d80 movw r1, #0x1020 */
/* @0x216d84 vmov r2, s16 */
/* @0x216d88 ldr r0, [r3, r0, lsl #2] */
/* @0x216d8c bl 0xb6a78 <alSourcef@plt> */
/* @0x216d90 ldr r3, [r8] */
/* @0x216d94 ldr r0, [r5, #0x10] */
/* @0x216d98 movw r1, #0x1021 */
/* @0x216d9c vmov r2, s18 */
/* @0x216da0 ldr r0, [r3, r0, lsl #2] */
/* @0x216da4 bl 0xb6a78 <alSourcef@plt> */
/* @0x216da8 bl 0xb6a54 <alGetError@plt> */
/* @0x216dac subs r2, r0, #0 */
/* @0x216db0 beq 0x216d20 <_Z23Audio_SetEmitterFalloffiddd+0x8c> */
/* @0x216db4 ldr r3, [pc, #0x38] */
/* @0x216db8 mov r1, r9 */
/* @0x216dbc add r4, r4, #1 */
/* @0x216dc0 ldr r3, [pc, r3] */
/* @0x216dc4 ldr r0, [r3] */
/* @0x216dc8 ldr r3, [r0] */
/* @0x216dcc ldr r3, [r3, #0xc] */
/* @0x216dd0 blx r3 */
/* @0x216dd4 cmp r4, r7 */
/* @0x216dd8 bne 0x216d2c <_Z23Audio_SetEmitterFalloffiddd+0x98> */
/* @0x216ddc vpop {d8, d9} */
/* @0x216de0 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x216de4 andseq r8, sp, r12, lsl #1 */
/* @0x216de8 ldrsbeq lr, [r3], #-92 */
/* @0x216dec ldrsheq r12, [r3], -r12 */
/* @0x216df0 andseq r10, sp, r8, ror #12 */
/* @0x216df4 andseq r6, sp, r4, asr r9 */

/* ── FUNC 0x216df8 · Audio_SetEmitterPosition(int, double, double, double) · size=116 · insn=29 */
/* @0x216df8 ldr r1, [pc, #0x64] */
/* @0x216dfc vmov d7, r2, r3 */
/* @0x216e00 ldr r1, [pc, r1] */
/* @0x216e04 ldrb r3, [r1] */
/* @0x216e08 cmp r3, #0 */
/* @0x216e0c bxeq lr */
/* @0x216e10 ldr r3, [pc, #0x50] */
/* @0x216e14 add r3, pc, r3 */
/* @0x216e18 ldr r2, [r3, #0x40] */
/* @0x216e1c cmp r2, r0 */
/* @0x216e20 movgt r2, #0 */
/* @0x216e24 movle r2, #1 */
/* @0x216e28 orrs r2, r2, r0, lsr #31 */
/* @0x216e2c bxne lr */
/* @0x216e30 ldr r3, [r3, #0x44] */
/* @0x216e34 ldr r3, [r3, r0, lsl #2] */
/* @0x216e38 cmp r3, #0 */
/* @0x216e3c bxeq lr */
/* @0x216e40 vcvt.f32.f64 s14, d7 */
/* @0x216e44 vldr d5, [sp] */
/* @0x216e48 vcvt.f32.f64 s13, d5 */
/* @0x216e4c vldr d5, [sp, #8] */
/* @0x216e50 vstr s14, [r3] */
/* @0x216e54 vcvt.f32.f64 s15, d5 */
/* @0x216e58 vstr s13, [r3, #4] */
/* @0x216e5c vstr s15, [r3, #8] */
/* @0x216e60 bx lr */
/* @0x216e64 andseq r7, sp, r0, lsr pc */
/* @0x216e68 subseq lr, r3, r0, lsl #9 */

/* ── FUNC 0x216e6c · Audio_GetEmitterPosition(int) · size=108 · insn=27 */
/* @0x216e6c ldr r2, [pc, #0x5c] */
/* @0x216e70 mov r3, r0 */
/* @0x216e74 ldr r2, [pc, r2] */
/* @0x216e78 ldrb r2, [r2] */
/* @0x216e7c cmp r2, #0 */
/* @0x216e80 beq 0x216ea0 <_Z24Audio_GetEmitterPositioni+0x34> */
/* @0x216e84 cmp r1, #0 */
/* @0x216e88 blt 0x216ea0 <_Z24Audio_GetEmitterPositioni+0x34> */
/* @0x216e8c ldr r2, [pc, #0x40] */
/* @0x216e90 add r2, pc, r2 */
/* @0x216e94 ldr r0, [r2, #0x40] */
/* @0x216e98 cmp r1, r0 */
/* @0x216e9c blt 0x216eb8 <_Z24Audio_GetEmitterPositioni+0x4c> */
/* @0x216ea0 mov r2, #0 */
/* @0x216ea4 mov r0, r3 */
/* @0x216ea8 str r2, [r3] */
/* @0x216eac str r2, [r3, #0x4] */
/* @0x216eb0 str r2, [r3, #0x8] */
/* @0x216eb4 bx lr */
/* @0x216eb8 ldr r2, [r2, #0x44] */
/* @0x216ebc ldr r2, [r2, r1, lsl #2] */
/* @0x216ec0 ldm r2, {r0, r1, r2} */
/* @0x216ec4 stm r3, {r0, r1, r2} */
/* @0x216ec8 mov r0, r3 */
/* @0x216ecc bx lr */
/* @0x216ed0 ldrheq r7, [sp], -r12 */
/* @0x216ed4 subseq lr, r3, r4, lsl #8 */

/* ── FUNC 0x216ed8 · Audio_SetEmitterVelocity(int, double, double, double) · size=116 · insn=29 */
/* @0x216ed8 ldr r1, [pc, #0x64] */
/* @0x216edc vmov d7, r2, r3 */
/* @0x216ee0 ldr r1, [pc, r1] */
/* @0x216ee4 ldrb r3, [r1] */
/* @0x216ee8 cmp r3, #0 */
/* @0x216eec bxeq lr */
/* @0x216ef0 ldr r3, [pc, #0x50] */
/* @0x216ef4 add r3, pc, r3 */
/* @0x216ef8 ldr r2, [r3, #0x40] */
/* @0x216efc cmp r2, r0 */
/* @0x216f00 movgt r2, #0 */
/* @0x216f04 movle r2, #1 */
/* @0x216f08 orrs r2, r2, r0, lsr #31 */
/* @0x216f0c bxne lr */
/* @0x216f10 ldr r3, [r3, #0x44] */
/* @0x216f14 ldr r3, [r3, r0, lsl #2] */
/* @0x216f18 cmp r3, #0 */
/* @0x216f1c bxeq lr */
/* @0x216f20 vcvt.f32.f64 s14, d7 */
/* @0x216f24 vldr d5, [sp] */
/* @0x216f28 vcvt.f32.f64 s13, d5 */
/* @0x216f2c vldr d5, [sp, #8] */
/* @0x216f30 vstr s14, [r3, #12] */
/* @0x216f34 vcvt.f32.f64 s15, d5 */
/* @0x216f38 vstr s13, [r3, #16] */
/* @0x216f3c vstr s15, [r3, #20] */
/* @0x216f40 bx lr */
/* @0x216f44 andseq r7, sp, r0, asr lr */
/* @0x216f48 subseq lr, r3, r0, lsr #7 */

/* ── FUNC 0x216f4c · Audio_GetEmitterVelocity(int) · size=112 · insn=28 */
/* @0x216f4c ldr r2, [pc, #0x60] */
/* @0x216f50 mov r3, r0 */
/* @0x216f54 ldr r2, [pc, r2] */
/* @0x216f58 ldrb r2, [r2] */
/* @0x216f5c cmp r2, #0 */
/* @0x216f60 beq 0x216f80 <_Z24Audio_GetEmitterVelocityi+0x34> */
/* @0x216f64 cmp r1, #0 */
/* @0x216f68 blt 0x216f80 <_Z24Audio_GetEmitterVelocityi+0x34> */
/* @0x216f6c ldr r2, [pc, #0x44] */
/* @0x216f70 add r2, pc, r2 */
/* @0x216f74 ldr r0, [r2, #0x40] */
/* @0x216f78 cmp r1, r0 */
/* @0x216f7c blt 0x216f98 <_Z24Audio_GetEmitterVelocityi+0x4c> */
/* @0x216f80 mov r2, #0 */
/* @0x216f84 mov r0, r3 */
/* @0x216f88 str r2, [r3] */
/* @0x216f8c str r2, [r3, #0x4] */
/* @0x216f90 str r2, [r3, #0x8] */
/* @0x216f94 bx lr */
/* @0x216f98 ldr r2, [r2, #0x44] */
/* @0x216f9c ldr r2, [r2, r1, lsl #2] */
/* @0x216fa0 add r2, r2, #12 */
/* @0x216fa4 ldm r2, {r0, r1, r2} */
/* @0x216fa8 stm r3, {r0, r1, r2} */
/* @0x216fac mov r0, r3 */
/* @0x216fb0 bx lr */
/* @0x216fb4 ldrsbeq r7, [sp], -r12 */
/* @0x216fb8 subseq lr, r3, r4, lsr #6 */

/* ── FUNC 0x216fbc · Audio_GetNoiseFromID(int) · size=108 · insn=27 */
/* @0x216fbc ldr r3, [pc, #0x60] */
/* @0x216fc0 str r4, [sp, #-0x4]! */
/* @0x216fc4 add r3, pc, r3 */
/* @0x216fc8 ldr r4, [r3, #0x38] */
/* @0x216fcc cmp r4, #0 */
/* @0x216fd0 ble 0x217014 <_Z20Audio_GetNoiseFromIDi+0x58> */
/* @0x216fd4 ldr r1, [r3, #0x3c] */
/* @0x216fd8 mov r3, #0 */
/* @0x216fdc sub r1, r1, #4 */
/* @0x216fe0 ldr r2, [r1, #0x4]! */
/* @0x216fe4 add r3, r3, #1 */
/* @0x216fe8 ldrb r12, [r2, #0x5] */
/* @0x216fec cmp r12, #0 */
/* @0x216ff0 beq 0x21700c <_Z20Audio_GetNoiseFromIDi+0x50> */
/* @0x216ff4 ldr r12, [r2, #0x8] */
/* @0x216ff8 cmp r12, #0 */
/* @0x216ffc bne 0x21700c <_Z20Audio_GetNoiseFromIDi+0x50> */
/* @0x217000 ldr r12, [r2, #0x14] */
/* @0x217004 cmp r12, r0 */
/* @0x217008 beq 0x217018 <_Z20Audio_GetNoiseFromIDi+0x5c> */
/* @0x21700c cmp r3, r4 */
/* @0x217010 bne 0x216fe0 <_Z20Audio_GetNoiseFromIDi+0x24> */
/* @0x217014 mov r2, #0 */
/* @0x217018 mov r0, r2 */
/* @0x21701c ldr r4, [sp], #4 */
/* @0x217020 bx lr */
/* @0x217024 ldrsbeq lr, [r3], #-32 */

/* ── FUNC 0x217028 · Audio_GetSoundType(int) · size=56 · insn=14 */
/* @0x217028 push {r3, lr} */
/* @0x21702c ldr r3, [pc, #0x28] */
/* @0x217030 ldr r3, [pc, r3] */
/* @0x217034 ldrb r3, [r3] */
/* @0x217038 cmp r3, #0 */
/* @0x21703c bne 0x217054 <_Z18Audio_GetSoundTypei+0x2c> */
/* @0x217040 bl 0x21632c <_Z14Audio_GetSoundi> */
/* @0x217044 cmp r0, #0 */
/* @0x217048 beq 0x217054 <_Z18Audio_GetSoundTypei+0x2c> */
/* @0x21704c ldrb r0, [r0, #0x24] */
/* @0x217050 pop {r3, pc} */
/* @0x217054 mvn r0, #0 */
/* @0x217058 pop {r3, pc} */
/* @0x21705c andseq r8, sp, r12, lsl r0 */

/* ── FUNC 0x217060 · Audio_GetGainFromSoundID(int) · size=56 · insn=14 */
/* @0x217060 push {r3, lr} */
/* @0x217064 ldr r3, [pc, #0x28] */
/* @0x217068 ldr r3, [pc, r3] */
/* @0x21706c ldrb r3, [r3] */
/* @0x217070 cmp r3, #0 */
/* @0x217074 beq 0x217080 <_Z24Audio_GetGainFromSoundIDi+0x20> */
/* @0x217078 mov r0, #1065353216 */
/* @0x21707c pop {r3, pc} */
/* @0x217080 bl 0x21632c <_Z14Audio_GetSoundi> */
/* @0x217084 cmp r0, #0 */
/* @0x217088 beq 0x217078 <_Z24Audio_GetGainFromSoundIDi+0x18> */
/* @0x21708c ldr r0, [r0, #0x4] */
/* @0x217090 pop {r3, pc} */
/* @0x217094 andseq r7, sp, r4, ror #31 */

/* ── FUNC 0x217098 · Audio_SoundIsPaused(int) · size=228 · insn=57 */
/* @0x217098 ldr r3, [pc, #0xc4] */
/* @0x21709c push {r4, r5, r6, r7, r8, lr} */
/* @0x2170a0 ldr r3, [pc, r3] */
/* @0x2170a4 mov r6, r0 */
/* @0x2170a8 ldrb r4, [r3] */
/* @0x2170ac cmp r4, #0 */
/* @0x2170b0 bne 0x217150 <_Z19Audio_SoundIsPausedi+0xb8> */
/* @0x2170b4 ldr r3, [pc, #0xac] */
/* @0x2170b8 ldr r3, [pc, r3] */
/* @0x2170bc ldrb r3, [r3] */
/* @0x2170c0 cmp r3, #0 */
/* @0x2170c4 beq 0x217150 <_Z19Audio_SoundIsPausedi+0xb8> */
/* @0x2170c8 ldr r3, [pc, #0x9c] */
/* @0x2170cc ldr r3, [pc, r3] */
/* @0x2170d0 ldr r3, [r3] */
/* @0x2170d4 cmp r3, r0 */
/* @0x2170d8 ble 0x217158 <_Z19Audio_SoundIsPausedi+0xc0> */
/* @0x2170dc ldr r3, [pc, #0x8c] */
/* @0x2170e0 add r3, pc, r3 */
/* @0x2170e4 ldr r5, [r3, #0x38] */
/* @0x2170e8 cmp r5, #0 */
/* @0x2170ec ble 0x217150 <_Z19Audio_SoundIsPausedi+0xb8> */
/* @0x2170f0 ldr r8, [pc, #0x7c] */
/* @0x2170f4 mov r3, r5 */
/* @0x2170f8 ldr r7, [pc, #0x78] */
/* @0x2170fc add r8, pc, r8 */
/* @0x217100 add r7, pc, r7 */
/* @0x217104 b 0x217118 <_Z19Audio_SoundIsPausedi+0x80> */
/* @0x217108 add r4, r4, #1 */
/* @0x21710c cmp r4, r5 */
/* @0x217110 beq 0x217150 <_Z19Audio_SoundIsPausedi+0xb8> */
/* @0x217114 ldr r3, [r7, #0x38] */
/* @0x217118 cmp r4, r3 */
/* @0x21711c bge 0x217108 <_Z19Audio_SoundIsPausedi+0x70> */
/* @0x217120 ldr r3, [r8, #0x3c] */
/* @0x217124 ldr r0, [r3, r4, lsl #2] */
/* @0x217128 cmp r0, #0 */
/* @0x21712c beq 0x217108 <_Z19Audio_SoundIsPausedi+0x70> */
/* @0x217130 ldr r3, [r0, #0x18] */
/* @0x217134 cmp r3, r6 */
/* @0x217138 bne 0x217108 <_Z19Audio_SoundIsPausedi+0x70> */
/* @0x21713c bl 0x216450 <_Z19Audio_NoiseIsPausedP6CNoise> */
/* @0x217140 cmp r0, #0 */
/* @0x217144 beq 0x217108 <_Z19Audio_SoundIsPausedi+0x70> */
/* @0x217148 mov r0, #1 */
/* @0x21714c pop {r4, r5, r6, r7, r8, pc} */
/* @0x217150 mov r0, #0 */
/* @0x217154 pop {r4, r5, r6, r7, r8, pc} */
/* @0x217158 bl 0x216fbc <_Z20Audio_GetNoiseFromIDi> */
/* @0x21715c pop {r4, r5, r6, r7, r8, lr} */
/* @0x217160 b 0x216450 <_Z19Audio_NoiseIsPausedP6CNoise> */
/* @0x217164 andseq r7, sp, r12, lsr #31 */
/* @0x217168 andseq r7, sp, r8, ror r12 */
/* @0x21716c andseq r10, sp, r8, lsl r3 */
/* @0x217170 ldrheq lr, [r3], #-20 */
/* @0x217174 .word 0x0053e198 */
/* @0x217178 .word 0x0053e194 */

/* ── FUNC 0x21717c · Audio_SoundIsPlaying(int) · size=228 · insn=57 */
/* @0x21717c ldr r3, [pc, #0xc4] */
/* @0x217180 push {r4, r5, r6, r7, r8, lr} */
/* @0x217184 ldr r3, [pc, r3] */
/* @0x217188 mov r6, r0 */
/* @0x21718c ldrb r4, [r3] */
/* @0x217190 cmp r4, #0 */
/* @0x217194 bne 0x217234 <_Z20Audio_SoundIsPlayingi+0xb8> */
/* @0x217198 ldr r3, [pc, #0xac] */
/* @0x21719c ldr r3, [pc, r3] */
/* @0x2171a0 ldrb r3, [r3] */
/* @0x2171a4 cmp r3, #0 */
/* @0x2171a8 beq 0x217234 <_Z20Audio_SoundIsPlayingi+0xb8> */
/* @0x2171ac ldr r3, [pc, #0x9c] */
/* @0x2171b0 ldr r3, [pc, r3] */
/* @0x2171b4 ldr r3, [r3] */
/* @0x2171b8 cmp r3, r0 */
/* @0x2171bc ble 0x21723c <_Z20Audio_SoundIsPlayingi+0xc0> */
/* @0x2171c0 ldr r3, [pc, #0x8c] */
/* @0x2171c4 add r3, pc, r3 */
/* @0x2171c8 ldr r5, [r3, #0x38] */
/* @0x2171cc cmp r5, #0 */
/* @0x2171d0 ble 0x217234 <_Z20Audio_SoundIsPlayingi+0xb8> */
/* @0x2171d4 ldr r8, [pc, #0x7c] */
/* @0x2171d8 mov r3, r5 */
/* @0x2171dc ldr r7, [pc, #0x78] */
/* @0x2171e0 add r8, pc, r8 */
/* @0x2171e4 add r7, pc, r7 */
/* @0x2171e8 b 0x2171fc <_Z20Audio_SoundIsPlayingi+0x80> */
/* @0x2171ec add r4, r4, #1 */
/* @0x2171f0 cmp r4, r5 */
/* @0x2171f4 beq 0x217234 <_Z20Audio_SoundIsPlayingi+0xb8> */
/* @0x2171f8 ldr r3, [r7, #0x38] */
/* @0x2171fc cmp r4, r3 */
/* @0x217200 bge 0x2171ec <_Z20Audio_SoundIsPlayingi+0x70> */
/* @0x217204 ldr r3, [r8, #0x3c] */
/* @0x217208 ldr r0, [r3, r4, lsl #2] */
/* @0x21720c cmp r0, #0 */
/* @0x217210 beq 0x2171ec <_Z20Audio_SoundIsPlayingi+0x70> */
/* @0x217214 ldr r3, [r0, #0x18] */
/* @0x217218 cmp r3, r6 */
/* @0x21721c bne 0x2171ec <_Z20Audio_SoundIsPlayingi+0x70> */
/* @0x217220 bl 0x2164bc <_Z20Audio_NoiseIsPlayingP6CNoise> */
/* @0x217224 cmp r0, #0 */
/* @0x217228 beq 0x2171ec <_Z20Audio_SoundIsPlayingi+0x70> */
/* @0x21722c mov r0, #1 */
/* @0x217230 pop {r4, r5, r6, r7, r8, pc} */
/* @0x217234 mov r0, #0 */
/* @0x217238 pop {r4, r5, r6, r7, r8, pc} */
/* @0x21723c bl 0x216fbc <_Z20Audio_GetNoiseFromIDi> */
/* @0x217240 pop {r4, r5, r6, r7, r8, lr} */
/* @0x217244 b 0x2164bc <_Z20Audio_NoiseIsPlayingP6CNoise> */
/* @0x217248 andseq r7, sp, r8, asr #29 */
/* @0x21724c mulseq sp, r4, r11 */
/* @0x217250 andseq r10, sp, r4, lsr r2 */
/* @0x217254 ldrsbeq lr, [r3], #-0 */
/* @0x217258 ldrheq lr, [r3], #-4 */
/* @0x21725c ldrheq lr, [r3], #-0 */

/* ── FUNC 0x217260 · Audio_Exists(int) · size=152 · insn=38 */
/* @0x217260 ldr r3, [pc, #0x84] */
/* @0x217264 push {r4, lr} */
/* @0x217268 ldr r3, [pc, r3] */
/* @0x21726c mov r4, r0 */
/* @0x217270 ldrb r3, [r3] */
/* @0x217274 cmp r3, #0 */
/* @0x217278 bne 0x2172c4 <_Z12Audio_Existsi+0x64> */
/* @0x21727c ldr r3, [pc, #0x6c] */
/* @0x217280 ldr r3, [pc, r3] */
/* @0x217284 ldr r3, [r3] */
/* @0x217288 cmp r3, r0 */
/* @0x21728c ble 0x2172cc <_Z12Audio_Existsi+0x6c> */
/* @0x217290 cmp r4, #0 */
/* @0x217294 blt 0x2172c4 <_Z12Audio_Existsi+0x64> */
/* @0x217298 ldr r3, [pc, #0x54] */
/* @0x21729c add r3, pc, r3 */
/* @0x2172a0 ldr r2, [r3, #0x20] */
/* @0x2172a4 cmp r4, r2 */
/* @0x2172a8 bge 0x2172c4 <_Z12Audio_Existsi+0x64> */
/* @0x2172ac ldr r3, [r3, #0x24] */
/* @0x2172b0 ldr r0, [r3, r4, lsl #2] */
/* @0x2172b4 cmp r0, #0 */
/* @0x2172b8 beq 0x2172e8 <_Z12Audio_Existsi+0x88> */
/* @0x2172bc mov r0, #1 */
/* @0x2172c0 pop {r4, pc} */
/* @0x2172c4 mov r0, #0 */
/* @0x2172c8 pop {r4, pc} */
/* @0x2172cc bl 0x216fbc <_Z20Audio_GetNoiseFromIDi> */
/* @0x2172d0 bl 0x2164bc <_Z20Audio_NoiseIsPlayingP6CNoise> */
/* @0x2172d4 cmp r0, #0 */
/* @0x2172d8 bne 0x2172bc <_Z12Audio_Existsi+0x5c> */
/* @0x2172dc cmp r4, #0 */
/* @0x2172e0 bge 0x217298 <_Z12Audio_Existsi+0x38> */
/* @0x2172e4 b 0x2172c4 <_Z12Audio_Existsi+0x64> */
/* @0x2172e8 pop {r4, pc} */
/* @0x2172ec andseq r7, sp, r4, ror #27 */
/* @0x2172f0 andseq r10, sp, r4, ror #2 */
/* @0x2172f4 ldrsheq sp, [r3], #-248 */

/* ── FUNC 0x2172f8 · Audio_Number() · size=20 · insn=5 */
/* @0x2172f8 ldr r3, [pc, #0x8] */
/* @0x2172fc add r3, pc, r3 */
/* @0x217300 ldr r0, [r3, #0x48] */
/* @0x217304 bx lr */
/* @0x217308 .word 0x0053df98 */

/* ── FUNC 0x21730c · Audio_Name(int) · size=24 · insn=6 */
/* @0x21730c ldr r3, [pc, #0xc] */
/* @0x217310 add r3, pc, r3 */
/* @0x217314 ldr r3, [r3, #0x4c] */
/* @0x217318 ldr r0, [r3, r0, lsl #2] */
/* @0x21731c bx lr */
/* @0x217320 subseq sp, r3, r4, lsl #31 */

/* ── FUNC 0x217324 · Audio_EmitterExists(int) · size=100 · insn=25 */
/* @0x217324 ldr r3, [pc, #0x54] */
/* @0x217328 mov r2, r0 */
/* @0x21732c ldr r3, [pc, r3] */
/* @0x217330 ldrb r3, [r3] */
/* @0x217334 cmp r3, #0 */
/* @0x217338 bne 0x217378 <_Z19Audio_EmitterExistsi+0x54> */
/* @0x21733c ldr r1, [pc, #0x40] */
/* @0x217340 add r1, pc, r1 */
/* @0x217344 ldr r0, [r1, #0x40] */
/* @0x217348 cmp r0, r2 */
/* @0x21734c movgt r0, #0 */
/* @0x217350 movle r0, #1 */
/* @0x217354 orrs r0, r0, r2, lsr #31 */
/* @0x217358 bne 0x217370 <_Z19Audio_EmitterExistsi+0x4c> */
/* @0x21735c ldr r3, [r1, #0x44] */
/* @0x217360 ldr r3, [r3, r2, lsl #2] */
/* @0x217364 cmp r3, #0 */
/* @0x217368 ldrbne r0, [r3, #0x18] */
/* @0x21736c bx lr */
/* @0x217370 mov r0, r3 */
/* @0x217374 bx lr */
/* @0x217378 mov r0, #0 */
/* @0x21737c bx lr */
/* @0x217380 andseq r7, sp, r0, lsr #26 */
/* @0x217384 subseq sp, r3, r4, asr pc */

/* ── FUNC 0x217388 · Audio_NoiseIsPlayingOgg(CNoise*) · size=80 · insn=20 */
/* @0x217388 push {r3, lr} */
/* @0x21738c ldr r3, [pc, #0x40] */
/* @0x217390 ldr r3, [pc, r3] */
/* @0x217394 ldrb r3, [r3] */
/* @0x217398 cmp r3, #0 */
/* @0x21739c beq 0x2173a8 <_Z23Audio_NoiseIsPlayingOggP6CNoise+0x20> */
/* @0x2173a0 mov r0, #0 */
/* @0x2173a4 pop {r3, pc} */
/* @0x2173a8 ldr r0, [r0, #0x18] */
/* @0x2173ac bl 0x21632c <_Z14Audio_GetSoundi> */
/* @0x2173b0 subs r3, r0, #0 */
/* @0x2173b4 beq 0x2173a0 <_Z23Audio_NoiseIsPlayingOggP6CNoise+0x18> */
/* @0x2173b8 ldrb r0, [r3, #0x24] */
/* @0x2173bc cmp r0, #0 */
/* @0x2173c0 popne {r3, pc} */
/* @0x2173c4 ldrb r0, [r3, #0x25] */
/* @0x2173c8 cmp r0, #0 */
/* @0x2173cc beq 0x2173a0 <_Z23Audio_NoiseIsPlayingOggP6CNoise+0x18> */
/* @0x2173d0 pop {r3, pc} */
/* @0x2173d4 ldrheq r7, [sp], -r12 */

/* ── FUNC 0x2173d8 · Audio_StartSoundNoise(cAudio_Sound*, CNoise*) · size=36 · insn=9 */
/* @0x2173d8 ldr r3, [pc, #0x18] */
/* @0x2173dc ldr r3, [pc, r3] */
/* @0x2173e0 ldrb r3, [r3] */
/* @0x2173e4 cmp r3, #0 */
/* @0x2173e8 bne 0x2173f0 <_Z21Audio_StartSoundNoiseP12cAudio_SoundP6CNoise+0x18> */
/* @0x2173ec b 0x216048 <_Z7checkALPKc+0x78> */
/* @0x2173f0 mov r0, #0 */
/* @0x2173f4 bx lr */
/* @0x2173f8 andseq r7, sp, r0, ror r12 */

/* ── FUNC 0x2173fc · Audio_GetSoundPitch(int) · size=100 · insn=25 */
/* @0x2173fc push {r3, lr} */
/* @0x217400 ldr r3, [pc, #0x50] */
/* @0x217404 ldr r3, [pc, r3] */
/* @0x217408 ldrb r3, [r3] */
/* @0x21740c cmp r3, #0 */
/* @0x217410 beq 0x217450 <_Z19Audio_GetSoundPitchi+0x54> */
/* @0x217414 ldr r3, [pc, #0x40] */
/* @0x217418 ldr r3, [pc, r3] */
/* @0x21741c ldr r3, [r3] */
/* @0x217420 cmp r3, r0 */
/* @0x217424 bgt 0x21743c <_Z19Audio_GetSoundPitchi+0x40> */
/* @0x217428 bl 0x216fbc <_Z20Audio_GetNoiseFromIDi> */
/* @0x21742c cmp r0, #0 */
/* @0x217430 beq 0x217450 <_Z19Audio_GetSoundPitchi+0x54> */
/* @0x217434 ldr r0, [r0, #0x20] */
/* @0x217438 pop {r3, pc} */
/* @0x21743c bl 0x21632c <_Z14Audio_GetSoundi> */
/* @0x217440 cmp r0, #0 */
/* @0x217444 beq 0x217450 <_Z19Audio_GetSoundPitchi+0x54> */
/* @0x217448 ldr r0, [r0, #0x8] */
/* @0x21744c pop {r3, pc} */
/* @0x217450 mov r0, #1065353216 */
/* @0x217454 pop {r3, pc} */
/* @0x217458 andseq r7, sp, r12, lsr #18 */
/* @0x21745c andseq r9, sp, r12, asr #31 */

/* ── FUNC 0x217460 · Audio_SoundPitch(int, float) · size=432 · insn=108 */
/* @0x217460 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x217464 vpush {d8} */
/* @0x217468 mov r6, r0 */
/* @0x21746c ldr r5, [pc, #0x17c] */
/* @0x217470 vmov s16, r1 */
/* @0x217474 ldr r3, [pc, #0x178] */
/* @0x217478 add r5, pc, r5 */
/* @0x21747c ldr r3, [r5, r3] */
/* @0x217480 ldrb r3, [r3] */
/* @0x217484 cmp r3, #0 */
/* @0x217488 bne 0x21758c <_Z16Audio_SoundPitchif+0x12c> */
/* @0x21748c ldr r3, [pc, #0x164] */
/* @0x217490 ldr r3, [r5, r3] */
/* @0x217494 ldrb r3, [r3] */
/* @0x217498 cmp r3, #0 */
/* @0x21749c beq 0x21758c <_Z16Audio_SoundPitchif+0x12c> */
/* @0x2174a0 vldr s15, [pc, #320] */
/* @0x2174a4 vcmpe.f32 s16, s15 */
/* @0x2174a8 vmrs APSR_nzcv, fpscr */
/* @0x2174ac vmovmi.f32 s16, s15 */
/* @0x2174b0 bpl 0x2175d4 <_Z16Audio_SoundPitchif+0x174> */
/* @0x2174b4 ldr r3, [pc, #0x140] */
/* @0x2174b8 mov r0, r6 */
/* @0x2174bc ldr r3, [r5, r3] */
/* @0x2174c0 ldr r3, [r3] */
/* @0x2174c4 cmp r3, r6 */
/* @0x2174c8 ble 0x217594 <_Z16Audio_SoundPitchif+0x134> */
/* @0x2174cc bl 0x21632c <_Z14Audio_GetSoundi> */
/* @0x2174d0 ldr r3, [pc, #0x128] */
/* @0x2174d4 add r3, pc, r3 */
/* @0x2174d8 ldr r7, [r3, #0x38] */
/* @0x2174dc cmp r0, #0 */
/* @0x2174e0 vstrne s16, [r0, #8] */
/* @0x2174e4 cmp r7, #0 */
/* @0x2174e8 ble 0x21758c <_Z16Audio_SoundPitchif+0x12c> */
/* @0x2174ec ldr r9, [pc, #0x110] */
/* @0x2174f0 mov r3, r7 */
/* @0x2174f4 ldr r8, [pc, #0x10c] */
/* @0x2174f8 mov r4, #0 */
/* @0x2174fc add r9, pc, r9 */
/* @0x217500 add r8, pc, r8 */
/* @0x217504 b 0x217518 <_Z16Audio_SoundPitchif+0xb8> */
/* @0x217508 add r4, r4, #1 */
/* @0x21750c cmp r4, r7 */
/* @0x217510 beq 0x21758c <_Z16Audio_SoundPitchif+0x12c> */
/* @0x217514 ldr r3, [r8, #0x38] */
/* @0x217518 cmp r4, r3 */
/* @0x21751c ldrlt r3, [r9, #0x3c] */
/* @0x217520 movge r3, #0 */
/* @0x217524 ldrlt r3, [r3, r4, lsl #2] */
/* @0x217528 ldr r2, [r3, #0x18] */
/* @0x21752c cmp r2, r6 */
/* @0x217530 bne 0x217508 <_Z16Audio_SoundPitchif+0xa8> */
/* @0x217534 ldrb r2, [r3, #0x5] */
/* @0x217538 cmp r2, #0 */
/* @0x21753c beq 0x217508 <_Z16Audio_SoundPitchif+0xa8> */
/* @0x217540 ldr r2, [r3, #0x8] */
/* @0x217544 cmp r2, #0 */
/* @0x217548 bne 0x217508 <_Z16Audio_SoundPitchif+0xa8> */
/* @0x21754c ldr r2, [r3, #0x38] */
/* @0x217550 movw r1, #0x1003 */
/* @0x217554 ldr r12, [pc, #0xb0] */
/* @0x217558 add r4, r4, #1 */
/* @0x21755c cmp r2, #0 */
/* @0x217560 vldrne s15, [r2, #44] */
/* @0x217564 ldr r0, [r3, #0x10] */
/* @0x217568 vmulne.f32 s15, s16, s15 */
/* @0x21756c ldr r3, [r5, r12] */
/* @0x217570 ldr r3, [r3] */
/* @0x217574 ldr r0, [r3, r0, lsl #2] */
/* @0x217578 vmoveq.f32 s15, s16 */
/* @0x21757c vmov r2, s15 */
/* @0x217580 bl 0xb6a78 <alSourcef@plt> */
/* @0x217584 cmp r4, r7 */
/* @0x217588 bne 0x217514 <_Z16Audio_SoundPitchif+0xb4> */
/* @0x21758c vpop {d8} */
/* @0x217590 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x217594 bl 0x216fbc <_Z20Audio_GetNoiseFromIDi> */
/* @0x217598 cmp r0, #0 */
/* @0x21759c beq 0x21758c <_Z16Audio_SoundPitchif+0x12c> */
/* @0x2175a0 ldr r3, [r0, #0x10] */
/* @0x2175a4 vstr s16, [r0, #32] */
/* @0x2175a8 cmp r3, #0 */
/* @0x2175ac blt 0x21758c <_Z16Audio_SoundPitchif+0x12c> */
/* @0x2175b0 ldr r0, [pc, #0x54] */
/* @0x2175b4 movw r1, #0x1003 */
/* @0x2175b8 vmov r2, s16 */
/* @0x2175bc vpop {d8} */
/* @0x2175c0 ldr r0, [r5, r0] */
/* @0x2175c4 ldr r0, [r0] */
/* @0x2175c8 ldr r0, [r0, r3, lsl #2] */
/* @0x2175cc pop {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x2175d0 b 0xb6a78 <alSourcef@plt> */
/* @0x2175d4 vldr s15, [pc, #16] */
/* @0x2175d8 vcmp.f32 s16, s15 */
/* @0x2175dc vmrs APSR_nzcv, fpscr */
/* @0x2175e0 vmovgt.f32 s16, s15 */
/* @0x2175e4 b 0x2174b4 <_Z16Audio_SoundPitchif+0x54> */
/* @0x2175e8 bllo 0x21fd280 <b2_toiTime+0x1aa3ddc> */
/* @0x2175ec orrmi r0, r0, #0 */
/* @0x2175f0 ldrsbeq r10, [sp], -r8 */
/* @0x2175f4 .word 0xffffd3fc */
/* @0x2175f8 .word 0xffffd0e0 */
/* @0x2175fc .word 0xfffff794 */
/* @0x217600 subseq sp, r3, r0, asr #27 */
/* @0x217604 .word 0x0053dd98 */
/* @0x217608 .word 0x0053dd94 */
/* @0x21760c .word 0xfffff77c */

/* ── FUNC 0x217610 · setGainForNoiseImmediate(CNoise*, float) · size=120 · insn=30 */
/* @0x217610 ldrb r3, [r0, #0x5] */
/* @0x217614 push {r4, lr} */
/* @0x217618 cmp r3, #0 */
/* @0x21761c mov r4, r0 */
/* @0x217620 popeq {r4, pc} */
/* @0x217624 ldr r3, [r0, #0x8] */
/* @0x217628 cmp r3, #0 */
/* @0x21762c popne {r4, pc} */
/* @0x217630 ldr r3, [r0, #0x10] */
/* @0x217634 cmp r3, #0 */
/* @0x217638 poplt {r4, pc} */
/* @0x21763c ldr r0, [r0, #0x18] */
/* @0x217640 bl 0x217060 <_Z24Audio_GetGainFromSoundIDi> */
/* @0x217644 vldr s15, [r4, #36] */
/* @0x217648 ldr r3, [r4, #0x38] */
/* @0x21764c movw r1, #0x100a */
/* @0x217650 cmp r3, #0 */
/* @0x217654 vmov s14, r0 */
/* @0x217658 ldr r0, [r4, #0x10] */
/* @0x21765c pop {r4, lr} */
/* @0x217660 vmul.f32 s15, s14, s15 */
/* @0x217664 vldrne s14, [r3, #40] */
/* @0x217668 ldr r3, [pc, #0x14] */
/* @0x21766c ldr r3, [pc, r3] */
/* @0x217670 ldr r3, [r3] */
/* @0x217674 ldr r0, [r3, r0, lsl #2] */
/* @0x217678 vmulne.f32 s15, s15, s14 */
/* @0x21767c vmov r2, s15 */
/* @0x217680 b 0xb6a78 <alSourcef@plt> */
/* @0x217684 andseq r9, sp, r0, ror #26 */

/* ── FUNC 0x217688 · setGainForSoundImmediate(int, float) · size=208 · insn=52 */
/* @0x217688 push {r3, r4, r5, r6, r7, lr} */
/* @0x21768c vpush {d8} */
/* @0x217690 mov r7, r0 */
/* @0x217694 ldr r5, [pc, #0xb4] */
/* @0x217698 add r5, pc, r5 */
/* @0x21769c ldr r6, [r5, #0x38] */
/* @0x2176a0 bl 0x217060 <_Z24Audio_GetGainFromSoundIDi> */
/* @0x2176a4 cmp r6, #0 */
/* @0x2176a8 vmov s16, r0 */
/* @0x2176ac ble 0x217748 <_Z24setGainForSoundImmediateif+0xc0> */
/* @0x2176b0 mov r4, #0 */
/* @0x2176b4 b 0x2176c4 <_Z24setGainForSoundImmediateif+0x3c> */
/* @0x2176b8 add r4, r4, #1 */
/* @0x2176bc cmp r4, r6 */
/* @0x2176c0 beq 0x217748 <_Z24setGainForSoundImmediateif+0xc0> */
/* @0x2176c4 ldr r3, [r5, #0x38] */
/* @0x2176c8 cmp r3, r4 */
/* @0x2176cc ldrgt r3, [r5, #0x3c] */
/* @0x2176d0 movle r3, #0 */
/* @0x2176d4 ldrgt r3, [r3, r4, lsl #2] */
/* @0x2176d8 ldr r2, [r3, #0x18] */
/* @0x2176dc cmp r2, r7 */
/* @0x2176e0 bne 0x2176b8 <_Z24setGainForSoundImmediateif+0x30> */
/* @0x2176e4 ldrb r2, [r3, #0x5] */
/* @0x2176e8 cmp r2, #0 */
/* @0x2176ec beq 0x2176b8 <_Z24setGainForSoundImmediateif+0x30> */
/* @0x2176f0 ldr r2, [r3, #0x8] */
/* @0x2176f4 cmp r2, #0 */
/* @0x2176f8 bne 0x2176b8 <_Z24setGainForSoundImmediateif+0x30> */
/* @0x2176fc ldr r0, [r3, #0x10] */
/* @0x217700 cmp r0, #0 */
/* @0x217704 blt 0x2176b8 <_Z24setGainForSoundImmediateif+0x30> */
/* @0x217708 vldr s15, [r3, #36] */
/* @0x21770c vmul.f32 s15, s16, s15 */
/* @0x217710 ldr r2, [r3, #0x38] */
/* @0x217714 movw r1, #0x100a */
/* @0x217718 ldr r3, [pc, #0x34] */
/* @0x21771c add r4, r4, #1 */
/* @0x217720 cmp r2, #0 */
/* @0x217724 vldrne s14, [r2, #40] */
/* @0x217728 ldr r3, [pc, r3] */
/* @0x21772c ldr r3, [r3] */
/* @0x217730 ldr r0, [r3, r0, lsl #2] */
/* @0x217734 vmulne.f32 s15, s15, s14 */
/* @0x217738 vmov r2, s15 */
/* @0x21773c bl 0xb6a78 <alSourcef@plt> */
/* @0x217740 cmp r4, r6 */
/* @0x217744 bne 0x2176c4 <_Z24setGainForSoundImmediateif+0x3c> */
/* @0x217748 vpop {d8} */
/* @0x21774c pop {r3, r4, r5, r6, r7, pc} */
/* @0x217750 ldrsheq sp, [r3], #-188 */
/* @0x217754 andseq r9, sp, r4, lsr #25 */

/* ── FUNC 0x217758 · Audio_SetGainForNoise(CNoise*, float, int) · size=308 · insn=77 */
/* @0x217758 push {r3, r4, r5, lr} */
/* @0x21775c vpush {d8} */
/* @0x217760 vmov s16, r1 */
/* @0x217764 ldr r3, [pc, #0x10c] */
/* @0x217768 mov r4, r0 */
/* @0x21776c ldr r12, [pc, #0x108] */
/* @0x217770 mov r5, r2 */
/* @0x217774 add r3, pc, r3 */
/* @0x217778 ldr r1, [r3, r12] */
/* @0x21777c ldrb r1, [r1] */
/* @0x217780 cmp r1, #0 */
/* @0x217784 bne 0x217850 <_Z21Audio_SetGainForNoiseP6CNoisefi+0xf8> */
/* @0x217788 vcmp.f32 s16, #0 */
/* @0x21778c vldr s15, [pc, #224] */
/* @0x217790 vmrs APSR_nzcv, fpscr */
/* @0x217794 vmovmi.f32 s16, s15 */
/* @0x217798 cmp r2, #0 */
/* @0x21779c bne 0x2177dc <_Z21Audio_SetGainForNoiseP6CNoisefi+0x84> */
/* @0x2177a0 vldr s15, [r0, #36] */
/* @0x2177a4 vcmp.f32 s15, s16 */
/* @0x2177a8 vmrs APSR_nzcv, fpscr */
/* @0x2177ac bne 0x2177bc <_Z21Audio_SetGainForNoiseP6CNoisefi+0x64> */
/* @0x2177b0 ldr r3, [r0, #0x2c] */
/* @0x2177b4 cmp r3, #0 */
/* @0x2177b8 beq 0x217850 <_Z21Audio_SetGainForNoiseP6CNoisefi+0xf8> */
/* @0x2177bc vstr s16, [r4, #36] */
/* @0x2177c0 vmov r1, s16 */
/* @0x2177c4 vpop {d8} */
/* @0x2177c8 mov r3, #0 */
/* @0x2177cc mov r0, r4 */
/* @0x2177d0 str r3, [r4, #0x2c] */
/* @0x2177d4 pop {r3, r4, r5, lr} */
/* @0x2177d8 b 0x217610 <_Z24setGainForNoiseImmediateP6CNoisef> */
/* @0x2177dc ldr r2, [pc, #0x9c] */
/* @0x2177e0 ldr r2, [r3, r2] */
/* @0x2177e4 ldrb r2, [r2] */
/* @0x2177e8 cmp r2, #0 */
/* @0x2177ec bne 0x217858 <_Z21Audio_SetGainForNoiseP6CNoisefi+0x100> */
/* @0x2177f0 ldr r2, [pc, #0x8c] */
/* @0x2177f4 ldr r3, [r3, r2] */
/* @0x2177f8 ldr r3, [r3] */
/* @0x2177fc cmp r3, #0 */
/* @0x217800 moveq r1, #33 */
/* @0x217804 beq 0x217820 <_Z21Audio_SetGainForNoiseP6CNoisefi+0xc8> */
/* @0x217808 ldr r1, [r3, #0xc] */
/* @0x21780c mov r0, #1000 */
/* @0x217810 bl 0x318d10 <__divsi3> */
/* @0x217814 cmp r0, #1 */
/* @0x217818 movge r1, r0 */
/* @0x21781c movlt r1, #1 */
/* @0x217820 mov r0, r5 */
/* @0x217824 bl 0x318d10 <__divsi3> */
/* @0x217828 cmp r0, #0 */
/* @0x21782c vmovgt s15, r0 */
/* @0x217830 movle r0, #1 */
/* @0x217834 vmovle.f32 s14, #1.000000e+00 */
/* @0x217838 str r0, [r4, #0x2c] */
/* @0x21783c vcvtgt.f32.s32 s14, s15 */
/* @0x217840 vldr s15, [r4, #36] */
/* @0x217844 vsub.f32 s16, s16, s15 */
/* @0x217848 vdiv.f32 s16, s16, s14 */
/* @0x21784c vstr s16, [r4, #40] */
/* @0x217850 vpop {d8} */
/* @0x217854 pop {r3, r4, r5, pc} */
/* @0x217858 ldr r2, [pc, #0x28] */
/* @0x21785c ldr r0, [r3, r2] */
/* @0x217860 bl 0x214808 <_ZN13CTimingSource6GetFPSEv> */
/* @0x217864 vmov d7, r0, r1 */
/* @0x217868 vcvt.s32.f64 s15, d7 */
/* @0x21786c vmov r1, s15 */
/* @0x217870 b 0x21780c <_Z21Audio_SetGainForNoiseP6CNoisefi+0xb4> */
/* @0x217874 andeq r0, r0, r0 */
/* @0x217878 ldrsbeq r10, [sp], -r12 */
/* @0x21787c .word 0xffffd3fc */
/* @0x217880 .word 0xffffbcd4 */
/* @0x217884 .word 0xffffbcd8 */
/* @0x217888 .word 0xffffbcdc */

/* ── FUNC 0x21788c · Audio_GetSoundGain(int) · size=100 · insn=25 */
/* @0x21788c push {r3, lr} */
/* @0x217890 ldr r3, [pc, #0x50] */
/* @0x217894 ldr r3, [pc, r3] */
/* @0x217898 ldrb r3, [r3] */
/* @0x21789c cmp r3, #0 */
/* @0x2178a0 beq 0x2178e0 <_Z18Audio_GetSoundGaini+0x54> */
/* @0x2178a4 ldr r3, [pc, #0x40] */
/* @0x2178a8 ldr r3, [pc, r3] */
/* @0x2178ac ldr r3, [r3] */
/* @0x2178b0 cmp r3, r0 */
/* @0x2178b4 bgt 0x2178cc <_Z18Audio_GetSoundGaini+0x40> */
/* @0x2178b8 bl 0x216fbc <_Z20Audio_GetNoiseFromIDi> */
/* @0x2178bc cmp r0, #0 */
/* @0x2178c0 beq 0x2178e0 <_Z18Audio_GetSoundGaini+0x54> */
/* @0x2178c4 ldr r0, [r0, #0x24] */
/* @0x2178c8 pop {r3, pc} */
/* @0x2178cc bl 0x21632c <_Z14Audio_GetSoundi> */
/* @0x2178d0 cmp r0, #0 */
/* @0x2178d4 beq 0x2178e0 <_Z18Audio_GetSoundGaini+0x54> */
/* @0x2178d8 ldr r0, [r0, #0x4] */
/* @0x2178dc pop {r3, pc} */
/* @0x2178e0 mov r0, #0 */
/* @0x2178e4 pop {r3, pc} */
/* @0x2178e8 mulseq sp, r12, r4 */
/* @0x2178ec andseq r9, sp, r12, lsr r11 */

/* ── FUNC 0x2178f0 · Audio_SoundGain(int, float, int) · size=400 · insn=100 */
/* @0x2178f0 push {r4, r5, r6, lr} */
/* @0x2178f4 vpush {d8} */
/* @0x2178f8 mov r5, r0 */
/* @0x2178fc ldr r4, [pc, #0x160] */
/* @0x217900 mov r6, r2 */
/* @0x217904 ldr r3, [pc, #0x15c] */
/* @0x217908 vmov s16, r1 */
/* @0x21790c add r4, pc, r4 */
/* @0x217910 ldr r3, [r4, r3] */
/* @0x217914 ldrb r3, [r3] */
/* @0x217918 cmp r3, #0 */
/* @0x21791c bne 0x217a1c <_Z15Audio_SoundGainifi+0x12c> */
/* @0x217920 ldr r3, [pc, #0x144] */
/* @0x217924 ldr r3, [r4, r3] */
/* @0x217928 ldrb r3, [r3] */
/* @0x21792c cmp r3, #0 */
/* @0x217930 beq 0x217a1c <_Z15Audio_SoundGainifi+0x12c> */
/* @0x217934 ldr r3, [pc, #0x134] */
/* @0x217938 ldr r3, [r4, r3] */
/* @0x21793c ldrb r3, [r3] */
/* @0x217940 cmp r3, #0 */
/* @0x217944 bne 0x217a44 <_Z15Audio_SoundGainifi+0x154> */
/* @0x217948 ldr r3, [pc, #0x124] */
/* @0x21794c ldr r3, [r4, r3] */
/* @0x217950 ldr r3, [r3] */
/* @0x217954 cmp r3, #0 */
/* @0x217958 moveq r1, #33 */
/* @0x21795c beq 0x217978 <_Z15Audio_SoundGainifi+0x88> */
/* @0x217960 ldr r1, [r3, #0xc] */
/* @0x217964 mov r0, #1000 */
/* @0x217968 bl 0x318d10 <__divsi3> */
/* @0x21796c cmp r0, #1 */
/* @0x217970 movge r1, r0 */
/* @0x217974 movlt r1, #1 */
/* @0x217978 mov r0, r6 */
/* @0x21797c bl 0x318d10 <__divsi3> */
/* @0x217980 ldr r3, [pc, #0xf0] */
/* @0x217984 vcmp.f32 s16, #0 */
/* @0x217988 vldr s15, [pc, #208] */
/* @0x21798c ldr r3, [r4, r3] */
/* @0x217990 ldr r3, [r3] */
/* @0x217994 cmp r0, #1 */
/* @0x217998 movge r4, r0 */
/* @0x21799c movlt r4, #1 */
/* @0x2179a0 vmrs APSR_nzcv, fpscr */
/* @0x2179a4 vmovmi.f32 s16, s15 */
/* @0x2179a8 cmp r3, r5 */
/* @0x2179ac mov r0, r5 */
/* @0x2179b0 ble 0x217a24 <_Z15Audio_SoundGainifi+0x134> */
/* @0x2179b4 bl 0x21632c <_Z14Audio_GetSoundi> */
/* @0x2179b8 subs r3, r0, #0 */
/* @0x2179bc beq 0x217a1c <_Z15Audio_SoundGainifi+0x12c> */
/* @0x2179c0 cmp r6, #0 */
/* @0x2179c4 vldr s15, [r3, #4] */
/* @0x2179c8 bne 0x217a04 <_Z15Audio_SoundGainifi+0x114> */
/* @0x2179cc vcmp.f32 s15, s16 */
/* @0x2179d0 vmrs APSR_nzcv, fpscr */
/* @0x2179d4 bne 0x2179e4 <_Z15Audio_SoundGainifi+0xf4> */
/* @0x2179d8 ldr r2, [r3, #0x20] */
/* @0x2179dc cmp r2, #0 */
/* @0x2179e0 beq 0x217a1c <_Z15Audio_SoundGainifi+0x12c> */
/* @0x2179e4 vstr s16, [r3, #4] */
/* @0x2179e8 vmov r1, s16 */
/* @0x2179ec vpop {d8} */
/* @0x2179f0 mov r0, r5 */
/* @0x2179f4 mov r2, #0 */
/* @0x2179f8 str r2, [r3, #0x20] */
/* @0x2179fc pop {r4, r5, r6, lr} */
/* @0x217a00 b 0x217688 <_Z24setGainForSoundImmediateif> */
/* @0x217a04 vsub.f32 s16, s16, s15 */
/* @0x217a08 str r4, [r3, #0x20] */
/* @0x217a0c vmov s14, r4 */
/* @0x217a10 vcvt.f32.s32 s15, s14 */
/* @0x217a14 vdiv.f32 s16, s16, s15 */
/* @0x217a18 vstr s16, [r3, #28] */
/* @0x217a1c vpop {d8} */
/* @0x217a20 pop {r4, r5, r6, pc} */
/* @0x217a24 bl 0x216fbc <_Z20Audio_GetNoiseFromIDi> */
/* @0x217a28 cmp r0, #0 */
/* @0x217a2c beq 0x217a1c <_Z15Audio_SoundGainifi+0x12c> */
/* @0x217a30 vmov r1, s16 */
/* @0x217a34 mov r2, r6 */
/* @0x217a38 vpop {d8} */
/* @0x217a3c pop {r4, r5, r6, lr} */
/* @0x217a40 b 0x217758 <_Z21Audio_SetGainForNoiseP6CNoisefi> */
/* @0x217a44 ldr r3, [pc, #0x30] */
/* @0x217a48 ldr r0, [r4, r3] */
/* @0x217a4c bl 0x214808 <_ZN13CTimingSource6GetFPSEv> */
/* @0x217a50 vmov d7, r0, r1 */
/* @0x217a54 vcvt.s32.f64 s15, d7 */
/* @0x217a58 vmov r1, s15 */
/* @0x217a5c b 0x217964 <_Z15Audio_SoundGainifi+0x74> */
/* @0x217a60 andeq r0, r0, r0 */
/* @0x217a64 andseq r10, sp, r4, asr #6 */
/* @0x217a68 .word 0xffffd3fc */
/* @0x217a6c .word 0xffffd0e0 */
/* @0x217a70 .word 0xffffbcd4 */
/* @0x217a74 .word 0xffffbcd8 */
/* @0x217a78 .word 0xfffff794 */
/* @0x217a7c .word 0xffffbcdc */

/* ── FUNC 0x217a80 · Audio_FalloffSet(int) · size=196 · insn=49 */
/* @0x217a80 push {r3, lr} */
/* @0x217a84 ldr r3, [pc, #0xac] */
/* @0x217a88 ldr r3, [pc, r3] */
/* @0x217a8c ldrb r3, [r3] */
/* @0x217a90 cmp r3, #0 */
/* @0x217a94 popne {r3, pc} */
/* @0x217a98 cmp r0, #6 */
/* @0x217a9c addls pc, pc, r0, lsl #2 */
/* @0x217aa0 b 0x217b14 <_Z16Audio_FalloffSeti+0x94> */
/* @0x217aa4 b 0x217acc <_Z16Audio_FalloffSeti+0x4c> */
/* @0x217aa8 b 0x217ad8 <_Z16Audio_FalloffSeti+0x58> */
/* @0x217aac b 0x217ae4 <_Z16Audio_FalloffSeti+0x64> */
/* @0x217ab0 b 0x217af0 <_Z16Audio_FalloffSeti+0x70> */
/* @0x217ab4 b 0x217afc <_Z16Audio_FalloffSeti+0x7c> */
/* @0x217ab8 b 0x217b08 <_Z16Audio_FalloffSeti+0x88> */
/* @0x217abc b 0x217ac0 <_Z16Audio_FalloffSeti+0x40> */
/* @0x217ac0 movw r0, #0xd006 */
/* @0x217ac4 pop {r3, lr} */
/* @0x217ac8 b 0xb6aa8 <alDistanceModel@plt> */
/* @0x217acc mov r0, #0 */
/* @0x217ad0 pop {r3, lr} */
/* @0x217ad4 b 0xb6aa8 <alDistanceModel@plt> */
/* @0x217ad8 movw r0, #0xd001 */
/* @0x217adc pop {r3, lr} */
/* @0x217ae0 b 0xb6aa8 <alDistanceModel@plt> */
/* @0x217ae4 movw r0, #0xd002 */
/* @0x217ae8 pop {r3, lr} */
/* @0x217aec b 0xb6aa8 <alDistanceModel@plt> */
/* @0x217af0 movw r0, #0xd003 */
/* @0x217af4 pop {r3, lr} */
/* @0x217af8 b 0xb6aa8 <alDistanceModel@plt> */
/* @0x217afc movw r0, #0xd004 */
/* @0x217b00 pop {r3, lr} */
/* @0x217b04 b 0xb6aa8 <alDistanceModel@plt> */
/* @0x217b08 movw r0, #0xd005 */
/* @0x217b0c pop {r3, lr} */
/* @0x217b10 b 0xb6aa8 <alDistanceModel@plt> */
/* @0x217b14 ldr r3, [pc, #0x20] */
/* @0x217b18 ldr r1, [pc, #0x20] */
/* @0x217b1c ldr r3, [pc, r3] */
/* @0x217b20 add r1, pc, r1 */
/* @0x217b24 ldr r0, [r3] */
/* @0x217b28 ldr r3, [r0] */
/* @0x217b2c ldr r3, [r3, #0xc] */
/* @0x217b30 blx r3 */
/* @0x217b34 pop {r3, pc} */
/* @0x217b38 andseq r7, sp, r4, asr #11 */
/* @0x217b3c ldrsheq r5, [sp], -r8 */
/* @0x217b40 andseq r12, r3, r12, lsl #2 */
