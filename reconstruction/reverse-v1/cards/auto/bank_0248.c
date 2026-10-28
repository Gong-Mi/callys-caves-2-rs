/* libyoyo.so 覆盖卡组 0248
 * 函数 0x29ccc8..0x29f4e4，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x29ccc8 · DebuggerCreateIPSocket() · size=184 · insn=46 */
/* @0x29ccc8 ldr r3, [pc, #0x9c] */
/* @0x29cccc push {r4, r5, lr} */
/* @0x29ccd0 ldr r3, [pc, r3] */
/* @0x29ccd4 sub sp, sp, #44 */
/* @0x29ccd8 ldr r3, [r3] */
/* @0x29ccdc cmp r3, #0 */
/* @0x29cce0 beq 0x29cd64 <_Z22DebuggerCreateIPSocketv+0x9c> */
/* @0x29cce4 ldr r3, [pc, #0x84] */
/* @0x29cce8 mov r4, #0 */
/* @0x29ccec ldr r1, [pc, #0x80] */
/* @0x29ccf0 mov r5, #0 */
/* @0x29ccf4 ldr r3, [pc, r3] */
/* @0x29ccf8 movt r5, #0x3ff0 */
/* @0x29ccfc add r1, pc, r1 */
/* @0x29cd00 ldr r0, [r3] */
/* @0x29cd04 ldr r3, [r0] */
/* @0x29cd08 ldr r3, [r3, #0xc] */
/* @0x29cd0c blx r3 */
/* @0x29cd10 mov r12, #0 */
/* @0x29cd14 mov r1, r12 */
/* @0x29cd18 add r3, sp, #8 */
/* @0x29cd1c mov r2, r12 */
/* @0x29cd20 str r3, [sp] */
/* @0x29cd24 add r0, sp, #24 */
/* @0x29cd28 mov r3, #1 */
/* @0x29cd2c str r12, [sp, #0x14] */
/* @0x29cd30 strd r4, r5, [sp, #8] */
/* @0x29cd34 bl 0x298e94 <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_> */
/* @0x29cd38 vldr d7, [sp, #24] */
/* @0x29cd3c vcvt.s32.f64 s13, d7 */
/* @0x29cd40 ldr r2, [pc, #0x30] */
/* @0x29cd44 ldr r1, [pc, #0x30] */
/* @0x29cd48 add r2, pc, r2 */
/* @0x29cd4c add r1, pc, r1 */
/* @0x29cd50 vmov r3, s13 */
/* @0x29cd54 vstr s13, [r1, #4] */
/* @0x29cd58 mvn r3, r3 */
/* @0x29cd5c lsr r3, r3, #31 */
/* @0x29cd60 strb r3, [r2, #0x218] */
/* @0x29cd64 add sp, sp, #44 */
/* @0x29cd68 pop {r4, r5, pc} */
/* @0x29cd6c andseq r4, r5, r4, lsr #32 */
/* @0x29cd70 andseq r0, r5, r12, asr #24 */
/* @0x29cd74 andeq r12, r11, r0, asr #27 */
/* @0x29cd78 subeq r10, r11, r0, asr #29 */
/* @0x29cd7c andseq r10, r5, r4, asr #21 */

/* ── FUNC 0x29cd80 · DebuggerDestroyIPSocket() · size=108 · insn=27 */
/* @0x29cd80 push {r4, lr} */
/* @0x29cd84 ldr r4, [pc, #0x50] */
/* @0x29cd88 add r4, pc, r4 */
/* @0x29cd8c ldr r2, [r4, #0x4] */
/* @0x29cd90 cmp r2, #0 */
/* @0x29cd94 blt 0x29cdc8 <_Z23DebuggerDestroyIPSocketv+0x48> */
/* @0x29cd98 ldr r3, [pc, #0x40] */
/* @0x29cd9c ldr r1, [pc, #0x40] */
/* @0x29cda0 ldr r3, [pc, r3] */
/* @0x29cda4 add r1, pc, r1 */
/* @0x29cda8 ldr r0, [r3] */
/* @0x29cdac ldr r3, [r0] */
/* @0x29cdb0 ldr r3, [r3, #0xc] */
/* @0x29cdb4 blx r3 */
/* @0x29cdb8 ldr r0, [r4, #0x4] */
/* @0x29cdbc bl 0x299244 <_Z10FreeSocketi> */
/* @0x29cdc0 mvn r3, #0 */
/* @0x29cdc4 str r3, [r4, #0x4] */
/* @0x29cdc8 ldr r3, [pc, #0x18] */
/* @0x29cdcc mov r2, #0 */
/* @0x29cdd0 add r3, pc, r3 */
/* @0x29cdd4 strb r2, [r3, #0x218] */
/* @0x29cdd8 pop {r4, pc} */
/* @0x29cddc andseq r10, r5, r8, lsl #21 */
/* @0x29cde0 andseq r0, r5, r0, lsr #23 */
/* @0x29cde4 andeq r12, r11, r0, lsr sp */
/* @0x29cde8 subeq r10, r11, r8, lsr lr */

/* ── FUNC 0x29cdec · DebuggerPingIP() · size=312 · insn=78 */
/* @0x29cdec push {r4, r5, r6, r7, lr} */
/* @0x29cdf0 sub sp, sp, #12 */
/* @0x29cdf4 bl 0x215148 <Timing_Time> */
/* @0x29cdf8 ldr r7, [pc, #0xf8] */
/* @0x29cdfc mov r12, #544 */
/* @0x29ce00 movw r4, #0xa120 */
/* @0x29ce04 add r7, pc, r7 */
/* @0x29ce08 movt r4, #0x7 */
/* @0x29ce0c mov r5, #0 */
/* @0x29ce10 ldr r6, [pc, #0xe4] */
/* @0x29ce14 ldrd r2, r3, [r7, r12] */
/* @0x29ce18 add r6, pc, r6 */
/* @0x29ce1c adds r2, r2, r4 */
/* @0x29ce20 adc r3, r3, r5 */
/* @0x29ce24 cmp r2, r0 */
/* @0x29ce28 sbcs r4, r3, r1 */
/* @0x29ce2c blt 0x29ce38 <_Z14DebuggerPingIPv+0x4c> */
/* @0x29ce30 add sp, sp, #12 */
/* @0x29ce34 pop {r4, r5, r6, r7, pc} */
/* @0x29ce38 ldr r3, [pc, #0xc0] */
/* @0x29ce3c strd r0, r1, [r7, r12] */
/* @0x29ce40 ldr r1, [pc, #0xbc] */
/* @0x29ce44 ldr r2, [r6, r3] */
/* @0x29ce48 ldr r3, [pc, #0xb8] */
/* @0x29ce4c ldr r5, [r6, r1] */
/* @0x29ce50 ldr r0, [r2] */
/* @0x29ce54 ldr r4, [r6, r3] */
/* @0x29ce58 ldr r1, [pc, #0xac] */
/* @0x29ce5c ldr r12, [r0] */
/* @0x29ce60 ldr r3, [r4] */
/* @0x29ce64 add r1, pc, r1 */
/* @0x29ce68 ldr r2, [r5] */
/* @0x29ce6c ldr r12, [r12, #0xc] */
/* @0x29ce70 blx r12 */
/* @0x29ce74 ldr r3, [pc, #0x94] */
/* @0x29ce78 add r3, pc, r3 */
/* @0x29ce7c ldr r3, [r3, #0x4] */
/* @0x29ce80 cmp r3, #63 */
/* @0x29ce84 bhi 0x29ce30 <_Z14DebuggerPingIPv+0x44> */
/* @0x29ce88 ldr r2, [pc, #0x84] */
/* @0x29ce8c add r3, r3, r3, lsl #1 */
/* @0x29ce90 lsl r3, r3, #2 */
/* @0x29ce94 ldr r2, [r6, r2] */
/* @0x29ce98 ldrb r1, [r2, r3] */
/* @0x29ce9c cmp r1, #0 */
/* @0x29cea0 beq 0x29ce30 <_Z14DebuggerPingIPv+0x44> */
/* @0x29cea4 add r3, r2, r3 */
/* @0x29cea8 ldr r1, [r5] */
/* @0x29ceac ldr r2, [r4] */
/* @0x29ceb0 mov r12, #8 */
/* @0x29ceb4 ldr r0, [r3, #0x4] */
/* @0x29ceb8 mov r3, #1 */
/* @0x29cebc str r3, [sp, #0x4] */
/* @0x29cec0 ldr r3, [pc, #0x50] */
/* @0x29cec4 str r12, [sp] */
/* @0x29cec8 add r3, pc, r3 */
/* @0x29cecc bl 0x296a38 <_ZN8yySocket13SendUDPPacketEPciPhib> */
/* @0x29ced0 ldr r3, [pc, #0x44] */
/* @0x29ced4 ldr r1, [pc, #0x44] */
/* @0x29ced8 ldr r3, [r6, r3] */
/* @0x29cedc add r1, pc, r1 */
/* @0x29cee0 mov r2, r0 */
/* @0x29cee4 ldr r0, [r3] */
/* @0x29cee8 ldr r3, [r0] */
/* @0x29ceec ldr r3, [r3, #0xc] */
/* @0x29cef0 blx r3 */
/* @0x29cef4 b 0x29ce30 <_Z14DebuggerPingIPv+0x44> */
/* @0x29cef8 subeq r10, r11, r4, lsl #28 */
/* @0x29cefc andseq r4, r5, r8, lsr lr */
/* @0x29cf00 .word 0xffffbcf0 */
/* @0x29cf04 .word 0xfffff0a4 */
/* @0x29cf08 .word 0xfffff0a8 */
/* @0x29cf0c andeq r12, r11, r12, lsl #25 */
/* @0x29cf10 mulseq r5, r8, r9 */
/* @0x29cf14 .word 0xfffffd54 */
/* @0x29cf18 andeq r12, r11, r12, lsr r12 */
/* @0x29cf1c .word 0xffffbac4 */
/* @0x29cf20 andeq r12, r11, r4, lsr r12 */

/* ── FUNC 0x29cf24 · DbgServer::DbgServer(bool) · size=64 · insn=16 */
/* @0x29cf24 push {r3, r4, r5, r6, r7, lr} */
/* @0x29cf28 mov r4, r0 */
/* @0x29cf2c mov r5, #0 */
/* @0x29cf30 mov r0, #44 */
/* @0x29cf34 str r5, [r4] */
/* @0x29cf38 mov r6, r1 */
/* @0x29cf3c bl 0x27c524 <_Znwj> */
/* @0x29cf40 mov r1, r5 */
/* @0x29cf44 mov r7, r0 */
/* @0x29cf48 bl 0x2970f8 <_ZN8yyServerC2Eb> */
/* @0x29cf4c mov r3, #1 */
/* @0x29cf50 str r7, [r4] */
/* @0x29cf54 strb r6, [r4, #0x5] */
/* @0x29cf58 mov r0, r4 */
/* @0x29cf5c strb r3, [r4, #0x4] */
/* @0x29cf60 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x29cf24 · DbgServer::DbgServer(bool) · alias of the symbol above · insn=0 */

/* ── FUNC 0x29cf64 · DbgServer::Init() · size=212 · insn=53 */
/* @0x29cf64 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x29cf68 sub sp, sp, #8 */
/* @0x29cf6c ldr r7, [pc, #0xb0] */
/* @0x29cf70 mov r10, r0 */
/* @0x29cf74 ldr r3, [pc, #0xac] */
/* @0x29cf78 mov r5, #5 */
/* @0x29cf7c ldr r7, [pc, r7] */
/* @0x29cf80 ldr r9, [pc, #0xa4] */
/* @0x29cf84 ldr r3, [pc, r3] */
/* @0x29cf88 mov r8, #1 */
/* @0x29cf8c ldr r4, [r7] */
/* @0x29cf90 add r9, pc, r9 */
/* @0x29cf94 ldr r6, [r3] */
/* @0x29cf98 ldr r3, [r6] */
/* @0x29cf9c mov r0, r6 */
/* @0x29cfa0 mov r1, r9 */
/* @0x29cfa4 mov r2, r4 */
/* @0x29cfa8 ldr r3, [r3, #0xc] */
/* @0x29cfac blx r3 */
/* @0x29cfb0 ldr r0, [r10] */
/* @0x29cfb4 mov r1, #0 */
/* @0x29cfb8 str r8, [sp] */
/* @0x29cfbc mov r2, r4 */
/* @0x29cfc0 mov r3, #1 */
/* @0x29cfc4 bl 0x2971e0 <_ZN8yyServer4InitE11eSocketTypeiib> */
/* @0x29cfc8 cmp r0, #0 */
/* @0x29cfcc beq 0x29cfe8 <_ZN9DbgServer4InitEv+0x84> */
/* @0x29cfd0 subs r5, r5, #1 */
/* @0x29cfd4 beq 0x29d018 <_ZN9DbgServer4InitEv+0xb4> */
/* @0x29cfd8 ldr r4, [r7] */
/* @0x29cfdc add r4, r4, #1 */
/* @0x29cfe0 str r4, [r7] */
/* @0x29cfe4 b 0x29cf98 <_ZN9DbgServer4InitEv+0x34> */
/* @0x29cfe8 ldr r3, [pc, #0x40] */
/* @0x29cfec mov r2, r4 */
/* @0x29cff0 ldr r1, [pc, #0x3c] */
/* @0x29cff4 ldr r3, [pc, r3] */
/* @0x29cff8 add r1, pc, r1 */
/* @0x29cffc ldr r0, [r3] */
/* @0x29d000 ldr r3, [r0] */
/* @0x29d004 ldr r3, [r3, #0xc] */
/* @0x29d008 blx r3 */
/* @0x29d00c mov r0, #1 */
/* @0x29d010 add sp, sp, #8 */
/* @0x29d014 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x29d018 mov r0, r5 */
/* @0x29d01c add sp, sp, #8 */
/* @0x29d020 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x29d024 andseq r3, r5, r8, asr sp */
/* @0x29d028 mulseq r5, r0, r7 */
/* @0x29d02c muleq r11, r0, r11 */
/* @0x29d030 andseq r0, r5, r12, asr #18 */
/* @0x29d034 andeq r12, r11, r12, asr #22 */

/* ── FUNC 0x29d038 · DbgServer::~DbgServer() · size=52 · insn=13 */
/* @0x29d038 push {r3, r4, r5, lr} */
/* @0x29d03c mov r4, r0 */
/* @0x29d040 ldr r5, [r0] */
/* @0x29d044 cmp r5, #0 */
/* @0x29d048 beq 0x29d05c <_ZN9DbgServerD2Ev+0x24> */
/* @0x29d04c mov r0, r5 */
/* @0x29d050 bl 0x297184 <_ZN8yyServerD2Ev> */
/* @0x29d054 mov r0, r5 */
/* @0x29d058 bl 0x27d1d0 <_ZdlPv> */
/* @0x29d05c mov r3, #0 */
/* @0x29d060 mov r0, r4 */
/* @0x29d064 str r3, [r4] */
/* @0x29d068 pop {r3, r4, r5, pc} */

/* ── FUNC 0x29d038 · DbgServer::~DbgServer() · alias of the symbol above · insn=0 */

/* ── FUNC 0x29d06c · DbgServer::GetBufferSize() · size=12 · insn=3 */
/* @0x29d06c ldr r3, [r0] */
/* @0x29d070 ldr r0, [r3, #0x10] */
/* @0x29d074 bx lr */

/* ── FUNC 0x29d078 · Debug_GetPing(Buffer_Standard*, Buffer_Standard*) · size=1116 · insn=279 */
/* @0x29d078 ldr r3, [r0] */
/* @0x29d07c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x29d080 add r5, r0, #44 */
/* @0x29d084 sub sp, sp, #28 */
/* @0x29d088 mov r6, r1 */
/* @0x29d08c mov r10, #0 */
/* @0x29d090 mov r2, r5 */
/* @0x29d094 ldr r3, [r3, #0xc] */
/* @0x29d098 mov r1, #5 */
/* @0x29d09c mov r9, r0 */
/* @0x29d0a0 blx r3 */
/* @0x29d0a4 mov r0, r5 */
/* @0x29d0a8 mov r1, r10 */
/* @0x29d0ac bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29d0b0 ldr r3, [r9] */
/* @0x29d0b4 mov r2, r5 */
/* @0x29d0b8 mov r1, #6 */
/* @0x29d0bc ldr r8, [pc, #0x3dc] */
/* @0x29d0c0 add r7, r6, #44 */
/* @0x29d0c4 ldr r3, [r3, #0xc] */
/* @0x29d0c8 add r8, pc, r8 */
/* @0x29d0cc mov r11, r0 */
/* @0x29d0d0 mov r0, r9 */
/* @0x29d0d4 blx r3 */
/* @0x29d0d8 mov r0, r5 */
/* @0x29d0dc mov r1, r10 */
/* @0x29d0e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x29d0e4 ldr r12, [pc, #0x3b8] */
/* @0x29d0e8 ldr r3, [r6] */
/* @0x29d0ec mov r2, r7 */
/* @0x29d0f0 mov r1, #5 */
/* @0x29d0f4 str r0, [sp] */
/* @0x29d0f8 mov r0, r6 */
/* @0x29d0fc ldr r12, [r8, r12] */
/* @0x29d100 str r10, [r6, #0x38] */
/* @0x29d104 ldrb r4, [r12] */
/* @0x29d108 vmov s13, r4 */
/* @0x29d10c vcvt.f64.u32 d6, s13 */
/* @0x29d110 vmov r4, r5, d6 */
/* @0x29d114 vstr s12, [r6, #44] */
/* @0x29d118 str r5, [r6, #0x30] */
/* @0x29d11c ldr r3, [r3, #0x8] */
/* @0x29d120 blx r3 */
/* @0x29d124 vmov s15, r11 */
/* @0x29d128 ldr r3, [r6] */
/* @0x29d12c mov r2, r7 */
/* @0x29d130 vcvt.f64.u32 d7, s15 */
/* @0x29d134 mov r1, #5 */
/* @0x29d138 str r10, [r6, #0x38] */
/* @0x29d13c mov r0, r6 */
/* @0x29d140 vmov r4, r5, d7 */
/* @0x29d144 vstr s14, [r6, #44] */
/* @0x29d148 str r5, [r6, #0x30] */
/* @0x29d14c ldr r3, [r3, #0x8] */
/* @0x29d150 blx r3 */
/* @0x29d154 add r1, sp, #16 */
/* @0x29d158 add r0, sp, #12 */
/* @0x29d15c bl 0x29c3a8 <_Z18Debug_QueryHeapMemRjRy> */
/* @0x29d160 ldr r3, [pc, #0x340] */
/* @0x29d164 ldr r4, [r6, #0x10] */
/* @0x29d168 ldr r3, [r8, r3] */
/* @0x29d16c ldr r0, [r3] */
/* @0x29d170 bl 0x29d06c <_ZN9DbgServer13GetBufferSizeEv> */
/* @0x29d174 ldr r1, [pc, #0x330] */
/* @0x29d178 ldr r3, [pc, #0x330] */
/* @0x29d17c ldr r2, [sp, #0xc] */
/* @0x29d180 ldr r1, [r8, r1] */
/* @0x29d184 ldr r1, [r1] */
/* @0x29d188 add r0, r4, r0 */
/* @0x29d18c add r1, r0, r1 */
/* @0x29d190 rsb r2, r1, r2 */
/* @0x29d194 str r2, [sp, #0xc] */
/* @0x29d198 ldr r3, [r8, r3] */
/* @0x29d19c str r3, [sp, #0x4] */
/* @0x29d1a0 ldrb r3, [r3] */
/* @0x29d1a4 cmp r3, r10 */
/* @0x29d1a8 bne 0x29d2b8 <_Z13Debug_GetPingP15Buffer_StandardS0_+0x240> */
/* @0x29d1ac ldr r2, [pc, #0x300] */
/* @0x29d1b0 mov r1, #0 */
/* @0x29d1b4 ldr r12, [r6] */
/* @0x29d1b8 mov r0, r6 */
/* @0x29d1bc add r2, pc, r2 */
/* @0x29d1c0 vldr s15, [r2, #556] */
/* @0x29d1c4 vcvt.f32.s32 s15, s15 */
/* @0x29d1c8 vldr s14, [r2, #552] */
/* @0x29d1cc str r3, [r2, #0x22c] */
/* @0x29d1d0 str r1, [r2, #0x228] */
/* @0x29d1d4 mov r1, #6 */
/* @0x29d1d8 str r3, [r6, #0x38] */
/* @0x29d1dc mov r2, r7 */
/* @0x29d1e0 vdiv.f32 s15, s14, s15 */
/* @0x29d1e4 vcvt.s32.f32 s15, s15 */
/* @0x29d1e8 vcvt.f64.s32 d6, s15 */
/* @0x29d1ec vmov r4, r5, d6 */
/* @0x29d1f0 vstr s12, [r6, #44] */
/* @0x29d1f4 str r5, [r6, #0x30] */
/* @0x29d1f8 ldr r3, [r12, #0x8] */
/* @0x29d1fc blx r3 */
/* @0x29d200 vldr s15, [sp, #12] */
/* @0x29d204 vcvt.f64.u32 d7, s15 */
/* @0x29d208 ldr r3, [r6] */
/* @0x29d20c mov r10, #0 */
/* @0x29d210 mov r1, #5 */
/* @0x29d214 mov r2, r7 */
/* @0x29d218 mov r0, r6 */
/* @0x29d21c str r10, [r6, #0x38] */
/* @0x29d220 vmov r4, r5, d7 */
/* @0x29d224 vstr s14, [r6, #44] */
/* @0x29d228 str r5, [r6, #0x30] */
/* @0x29d22c ldr r3, [r3, #0x8] */
/* @0x29d230 blx r3 */
/* @0x29d234 ldr r1, [sp, #0x10] */
/* @0x29d238 ldr r2, [sp, #0x14] */
/* @0x29d23c mov r12, #10 */
/* @0x29d240 ldr r3, [r6] */
/* @0x29d244 mov r0, r6 */
/* @0x29d248 str r1, [r6, #0x2c] */
/* @0x29d24c mov r1, #12 */
/* @0x29d250 str r2, [r6, #0x30] */
/* @0x29d254 mov r2, r7 */
/* @0x29d258 ldr r3, [r3, #0x8] */
/* @0x29d25c str r12, [r6, #0x38] */
/* @0x29d260 blx r3 */
/* @0x29d264 ldr r12, [sp, #0x4] */
/* @0x29d268 ldrb r3, [r12] */
/* @0x29d26c cmp r3, r10 */
/* @0x29d270 bne 0x29d39c <_Z13Debug_GetPingP15Buffer_StandardS0_+0x324> */
/* @0x29d274 mov r0, r6 */
/* @0x29d278 bl 0x29c080 <_Z17Debug_WriteOutputP15Buffer_Standard> */
/* @0x29d27c ldr r3, [pc, #0x234] */
/* @0x29d280 ldr r12, [sp] */
/* @0x29d284 ldr r0, [r8, r3] */
/* @0x29d288 and r1, r12, #1 */
/* @0x29d28c bl 0x2a04d8 <_ZN9CProfiler6EnableEb> */
/* @0x29d290 ldr r3, [pc, #0x224] */
/* @0x29d294 ldr r12, [sp] */
/* @0x29d298 mov r0, r6 */
/* @0x29d29c ldr r3, [r8, r3] */
/* @0x29d2a0 eor r9, r12, #2 */
/* @0x29d2a4 ubfx r9, r9, #0x1, #0x1 */
/* @0x29d2a8 strb r9, [r3] */
/* @0x29d2ac bl 0x29c148 <_Z22Debug_WriteProfileDataP15Buffer_Standard> */
/* @0x29d2b0 add sp, sp, #28 */
/* @0x29d2b4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x29d2b8 ldr r11, [pc, #0x200] */
/* @0x29d2bc mov r0, r6 */
/* @0x29d2c0 ldr r3, [r6] */
/* @0x29d2c4 mov r1, #5 */
/* @0x29d2c8 add r11, pc, r11 */
/* @0x29d2cc vldr s15, [r11, #556] */
/* @0x29d2d0 vcvt.f64.u32 d7, s15 */
/* @0x29d2d4 str r10, [r6, #0x38] */
/* @0x29d2d8 mov r2, r7 */
/* @0x29d2dc vmov r4, r5, d7 */
/* @0x29d2e0 vstr s14, [r6, #44] */
/* @0x29d2e4 str r5, [r6, #0x30] */
/* @0x29d2e8 ldr r3, [r3, #0x8] */
/* @0x29d2ec blx r3 */
/* @0x29d2f0 ldr r3, [r11, #0x22c] */
/* @0x29d2f4 cmp r3, #0 */
/* @0x29d2f8 movgt r9, r10 */
/* @0x29d2fc movgt r10, r9 */
/* @0x29d300 ble 0x29d34c <_Z13Debug_GetPingP15Buffer_StandardS0_+0x2d4> */
/* @0x29d304 ldr r2, [r11, #0x230] */
/* @0x29d308 mov r0, r6 */
/* @0x29d30c ldr lr, [r6] */
/* @0x29d310 mov r1, #8 */
/* @0x29d314 add r2, r2, r9, lsl #2 */
/* @0x29d318 vldr s15, [r2] */
/* @0x29d31c vcvt.f64.f32 d6, s15 */
/* @0x29d320 mov r2, r7 */
/* @0x29d324 str r10, [r6, #0x38] */
/* @0x29d328 add r9, r9, #1 */
/* @0x29d32c vmov r4, r5, d6 */
/* @0x29d330 vstr s12, [r6, #44] */
/* @0x29d334 str r5, [r6, #0x30] */
/* @0x29d338 ldr r4, [lr, #0x8] */
/* @0x29d33c blx r4 */
/* @0x29d340 ldr r2, [r11, #0x22c] */
/* @0x29d344 cmp r2, r9 */
/* @0x29d348 bgt 0x29d304 <_Z13Debug_GetPingP15Buffer_StandardS0_+0x28c> */
/* @0x29d34c ldr r12, [pc, #0x170] */
/* @0x29d350 mov r10, #0 */
/* @0x29d354 ldr r3, [r6] */
/* @0x29d358 mov r0, r6 */
/* @0x29d35c mov r1, #6 */
/* @0x29d360 mov r2, r7 */
/* @0x29d364 ldr r12, [r8, r12] */
/* @0x29d368 str r10, [r6, #0x38] */
/* @0x29d36c ldr r4, [r12] */
/* @0x29d370 vmov s13, r4 */
/* @0x29d374 vcvt.f64.s32 d6, s13 */
/* @0x29d378 vmov r4, r5, d6 */
/* @0x29d37c vstr s12, [r6, #44] */
/* @0x29d380 str r5, [r6, #0x30] */
/* @0x29d384 ldr r3, [r3, #0x8] */
/* @0x29d388 blx r3 */
/* @0x29d38c ldr r3, [pc, #0x134] */
/* @0x29d390 add r3, pc, r3 */
/* @0x29d394 str r10, [r3, #0x22c] */
/* @0x29d398 b 0x29d200 <_Z13Debug_GetPingP15Buffer_StandardS0_+0x188> */
/* @0x29d39c ldr r11, [pc, #0x128] */
/* @0x29d3a0 mov r0, r6 */
/* @0x29d3a4 ldr r3, [r6] */
/* @0x29d3a8 mov r1, #3 */
/* @0x29d3ac add r11, pc, r11 */
/* @0x29d3b0 str r10, [r6, #0x38] */
/* @0x29d3b4 mov r2, r7 */
/* @0x29d3b8 ldrh r4, [r11, #8] */
/* @0x29d3bc vmov s13, r4 */
/* @0x29d3c0 vcvt.f64.u32 d6, s13 */
/* @0x29d3c4 vmov r4, r5, d6 */
/* @0x29d3c8 vstr s12, [r6, #44] */
/* @0x29d3cc str r5, [r6, #0x30] */
/* @0x29d3d0 ldr r3, [r3, #0x8] */
/* @0x29d3d4 blx r3 */
/* @0x29d3d8 ldrh r3, [r11, #8] */
/* @0x29d3dc cmp r3, r10 */
/* @0x29d3e0 movne r9, r11 */
/* @0x29d3e4 beq 0x29d484 <_Z13Debug_GetPingP15Buffer_StandardS0_+0x40c> */
/* @0x29d3e8 ldr r3, [r9, #0xc] */
/* @0x29d3ec mov r1, #3 */
/* @0x29d3f0 ldr lr, [r6] */
/* @0x29d3f4 mov r2, r7 */
/* @0x29d3f8 mov r0, r6 */
/* @0x29d3fc ldr r11, [r3, r10, lsl #2] */
/* @0x29d400 mov r3, #0 */
/* @0x29d404 add r10, r10, #1 */
/* @0x29d408 ldrh r4, [r11] */
/* @0x29d40c str r3, [r6, #0x38] */
/* @0x29d410 vmov s13, r4 */
/* @0x29d414 vcvt.f64.u32 d6, s13 */
/* @0x29d418 vmov r4, r5, d6 */
/* @0x29d41c vstr s12, [r6, #44] */
/* @0x29d420 str r5, [r6, #0x30] */
/* @0x29d424 ldr r4, [lr, #0x8] */
/* @0x29d428 blx r4 */
/* @0x29d42c ldr r0, [r11, #0x4] */
/* @0x29d430 bl 0xb6538 <strlen@plt> */
/* @0x29d434 ldr lr, [r6] */
/* @0x29d438 mov r2, #0 */
/* @0x29d43c mov r1, #5 */
/* @0x29d440 str r2, [r6, #0x38] */
/* @0x29d444 mov r2, r7 */
/* @0x29d448 add r4, r0, #1 */
/* @0x29d44c mov r0, r6 */
/* @0x29d450 vmov s13, r4 */
/* @0x29d454 vcvt.f64.u32 d6, s13 */
/* @0x29d458 vmov r4, r5, d6 */
/* @0x29d45c vstr s12, [r6, #44] */
/* @0x29d460 str r5, [r6, #0x30] */
/* @0x29d464 ldr r4, [lr, #0x8] */
/* @0x29d468 blx r4 */
/* @0x29d46c mov r0, r6 */
/* @0x29d470 ldr r1, [r11, #0x4] */
/* @0x29d474 bl 0xcddb8 <_ZN7IBuffer5WriteEPKc> */
/* @0x29d478 ldrh r3, [r9, #8] */
/* @0x29d47c cmp r3, r10 */
/* @0x29d480 bgt 0x29d3e8 <_Z13Debug_GetPingP15Buffer_StandardS0_+0x370> */
/* @0x29d484 bl 0x29c5c8 <_Z14Debug_FreeTagsv> */
/* @0x29d488 ldr r3, [pc, #0x40] */
/* @0x29d48c mov r2, #0 */
/* @0x29d490 add r3, pc, r3 */
/* @0x29d494 strh r2, [r3, #8] */
/* @0x29d498 strb r2, [r3, #0xa] */
/* @0x29d49c b 0x29d274 <_Z13Debug_GetPingP15Buffer_StandardS0_+0x1fc> */
/* @0x29d4a0 andseq r4, r5, r8, lsl #23 */
/* @0x29d4a4 .word 0xffffdfa0 */
/* @0x29d4a8 .word 0xffffc0a4 */
/* @0x29d4ac .word 0xfffffdb8 */
/* @0x29d4b0 .word 0xffffbcd4 */
/* @0x29d4b4 subeq r10, r11, r12, asr #20 */
/* @0x29d4b8 .word 0xffffbf1c */
/* @0x29d4bc .word 0xffffef50 */
/* @0x29d4c0 subeq r10, r11, r0, asr #18 */
/* @0x29d4c4 .word 0xffffeb1c */
/* @0x29d4c8 subeq r10, r11, r8, ror r8 */
/* @0x29d4cc subeq r10, r11, r12, asr r8 */
/* @0x29d4d0 subeq r10, r11, r8, ror r7 */

/* ── FUNC 0x29d4d4 · Debug_GetUpdate(Buffer_Standard*, Buffer_Standard*) · size=344 · insn=86 */
/* @0x29d4d4 ldr r3, [r0] */
/* @0x29d4d8 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x29d4dc add r4, r0, #44 */
/* @0x29d4e0 mov r6, r1 */
/* @0x29d4e4 sub sp, sp, #16 */
/* @0x29d4e8 mov r2, r4 */
/* @0x29d4ec ldr r3, [r3, #0xc] */
/* @0x29d4f0 mov r10, #0 */
/* @0x29d4f4 mov r1, #6 */
/* @0x29d4f8 ldr r7, [pc, #0x120] */
/* @0x29d4fc blx r3 */
/* @0x29d500 mov r0, r4 */
/* @0x29d504 mov r1, r10 */
/* @0x29d508 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x29d50c ldr r7, [pc, r7] */
/* @0x29d510 ldr r3, [r6] */
/* @0x29d514 add r8, r6, #44 */
/* @0x29d518 ldrb r4, [r7] */
/* @0x29d51c mov r1, #5 */
/* @0x29d520 mov r2, r8 */
/* @0x29d524 str r10, [r6, #0x38] */
/* @0x29d528 vmov s15, r4 */
/* @0x29d52c vcvt.f64.u32 d7, s15 */
/* @0x29d530 vmov r4, r5, d7 */
/* @0x29d534 vstr s14, [r6, #44] */
/* @0x29d538 mov r9, r0 */
/* @0x29d53c mov r0, r6 */
/* @0x29d540 str r5, [r6, #0x30] */
/* @0x29d544 ldr r3, [r3, #0x8] */
/* @0x29d548 blx r3 */
/* @0x29d54c ldrb r3, [r7] */
/* @0x29d550 cmp r3, r10 */
/* @0x29d554 bne 0x29d56c <_Z15Debug_GetUpdateP15Buffer_StandardS0_+0x98> */
/* @0x29d558 mov r0, r6 */
/* @0x29d55c mov r1, r9 */
/* @0x29d560 bl 0xd8dc8 <_ZN2VM23GetRuntimeStateRealtimeEP15Buffer_Standardi> */
/* @0x29d564 add sp, sp, #16 */
/* @0x29d568 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x29d56c add r1, sp, #8 */
/* @0x29d570 add r0, sp, #4 */
/* @0x29d574 bl 0x29c3a8 <_Z18Debug_QueryHeapMemRjRy> */
/* @0x29d578 ldr r3, [pc, #0xa4] */
/* @0x29d57c ldr r5, [r6, #0x10] */
/* @0x29d580 ldr r3, [pc, r3] */
/* @0x29d584 ldr r0, [r3] */
/* @0x29d588 bl 0x29d06c <_ZN9DbgServer13GetBufferSizeEv> */
/* @0x29d58c ldr r3, [pc, #0x94] */
/* @0x29d590 ldr r4, [sp, #0x4] */
/* @0x29d594 mov r2, r8 */
/* @0x29d598 ldr r3, [pc, r3] */
/* @0x29d59c ldr r12, [r6] */
/* @0x29d5a0 mov r1, #5 */
/* @0x29d5a4 str r10, [r6, #0x38] */
/* @0x29d5a8 ldr r3, [r3] */
/* @0x29d5ac add r5, r5, r0 */
/* @0x29d5b0 mov r0, r6 */
/* @0x29d5b4 add r5, r5, r3 */
/* @0x29d5b8 rsb r4, r5, r4 */
/* @0x29d5bc str r4, [sp, #0x4] */
/* @0x29d5c0 vmov s15, r4 */
/* @0x29d5c4 vcvt.f64.u32 d7, s15 */
/* @0x29d5c8 vmov r4, r5, d7 */
/* @0x29d5cc vstr s14, [r6, #44] */
/* @0x29d5d0 str r5, [r6, #0x30] */
/* @0x29d5d4 ldr r3, [r12, #0x8] */
/* @0x29d5d8 blx r3 */
/* @0x29d5dc ldr r0, [sp, #0x8] */
/* @0x29d5e0 ldr r1, [sp, #0xc] */
/* @0x29d5e4 mov r12, #10 */
/* @0x29d5e8 ldr r3, [r6] */
/* @0x29d5ec mov r2, r8 */
/* @0x29d5f0 str r0, [r6, #0x2c] */
/* @0x29d5f4 mov r0, r6 */
/* @0x29d5f8 str r1, [r6, #0x30] */
/* @0x29d5fc mov r1, #12 */
/* @0x29d600 ldr r3, [r3, #0x8] */
/* @0x29d604 str r12, [r6, #0x38] */
/* @0x29d608 blx r3 */
/* @0x29d60c mov r0, r6 */
/* @0x29d610 mov r1, r9 */
/* @0x29d614 bl 0xdadc8 <_ZN2VM15GetRuntimeStateEP15Buffer_Standardi> */
/* @0x29d618 add sp, sp, #16 */
/* @0x29d61c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x29d620 andseq r2, r5, r4, ror #13 */
/* @0x29d624 andseq r0, r5, r4, ror r7 */
/* @0x29d628 andseq r4, r5, r0, ror r4 */

/* ── FUNC 0x29d62c · DbgServer::Process() · size=8 · insn=2 */
/* @0x29d62c ldr r0, [r0] */
/* @0x29d630 b 0x297f98 <_ZN8yyServer7ProcessEv> */

/* ── FUNC 0x29d634 · DebuggerMessageLoop() · size=180 · insn=45 */
/* @0x29d634 push {r4, r5, r6, r7, r8, lr} */
/* @0x29d638 mov r4, #0 */
/* @0x29d63c ldr r7, [pc, #0x88] */
/* @0x29d640 mov r0, #1 */
/* @0x29d644 ldr r3, [pc, #0x84] */
/* @0x29d648 add r7, pc, r7 */
/* @0x29d64c ldr r12, [pc, #0x80] */
/* @0x29d650 ldr r1, [pc, #0x80] */
/* @0x29d654 ldr lr, [r7, r3] */
/* @0x29d658 ldr r2, [pc, #0x7c] */
/* @0x29d65c ldr r3, [pc, #0x7c] */
/* @0x29d660 strb r4, [lr] */
/* @0x29d664 ldr r4, [r7, r12] */
/* @0x29d668 strb r0, [r4] */
/* @0x29d66c ldr r6, [r7, r1] */
/* @0x29d670 ldr r5, [r7, r2] */
/* @0x29d674 ldr r8, [r7, r3] */
/* @0x29d678 b 0x29d698 <_Z19DebuggerMessageLoopv+0x64> */
/* @0x29d67c ldrb r0, [r4] */
/* @0x29d680 cmp r0, #0 */
/* @0x29d684 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x29d688 ldr r3, [r7, r2] */
/* @0x29d68c ldrb r3, [r3] */
/* @0x29d690 cmp r3, #0 */
/* @0x29d694 bne 0x29d6c4 <_Z19DebuggerMessageLoopv+0x90> */
/* @0x29d698 bl 0x215148 <Timing_Time> */
/* @0x29d69c strd r0, r1, [r6] */
/* @0x29d6a0 bl 0x28fe64 <_Z15ProcessMessagesv> */
/* @0x29d6a4 ldr r0, [r5] */
/* @0x29d6a8 bl 0x29d62c <_ZN9DbgServer7ProcessEv> */
/* @0x29d6ac ldr r3, [r8] */
/* @0x29d6b0 ldr r2, [pc, #0x2c] */
/* @0x29d6b4 cmp r3, #0 */
/* @0x29d6b8 blt 0x29d67c <_Z19DebuggerMessageLoopv+0x48> */
/* @0x29d6bc mov r0, #1 */
/* @0x29d6c0 pop {r4, r5, r6, r7, r8, pc} */
/* @0x29d6c4 mov r0, #0 */
/* @0x29d6c8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x29d6cc andseq r4, r5, r8, lsl #12 */
/* @0x29d6d0 .word 0xffffc0ec */
/* @0x29d6d4 .word 0xffffdfa0 */
/* @0x29d6d8 .word 0xfffffdc4 */
/* @0x29d6dc .word 0xffffc0a4 */
/* @0x29d6e0 .word 0xffffc0e8 */
/* @0x29d6e4 .word 0xffffeec0 */

/* ── FUNC 0x29d6e8 · DebuggerMessageLoopTick() · size=56 · insn=14 */
/* @0x29d6e8 push {r4, lr} */
/* @0x29d6ec ldr r4, [pc, #0x28] */
/* @0x29d6f0 ldr r4, [pc, r4] */
/* @0x29d6f4 ldr r3, [r4] */
/* @0x29d6f8 cmp r3, #0 */
/* @0x29d6fc popeq {r4, pc} */
/* @0x29d700 ldrb r3, [r3, #0x4] */
/* @0x29d704 cmp r3, #0 */
/* @0x29d708 popeq {r4, pc} */
/* @0x29d70c bl 0x28fe64 <_Z15ProcessMessagesv> */
/* @0x29d710 ldr r0, [r4] */
/* @0x29d714 pop {r4, lr} */
/* @0x29d718 b 0x29d62c <_ZN9DbgServer7ProcessEv> */
/* @0x29d71c andseq r0, r5, r4, lsl #12 */

/* ── FUNC 0x29d720 · anon_29d720 · size=76 · insn=20 */
/* @0x29d720 push {r4, r5, r6, lr} */
/* @0x29d724 mov r4, r0 */
/* @0x29d728 ldr r6, [pc, #0x3c] */
/* @0x29d72c ldr r6, [pc, r6] */
/* @0x29d730 b 0x29d738 <_Z23DebuggerMessageLoopTickv+0x50> */
/* @0x29d734 bl 0x27e114 <_ZN7CThread5SleepEi> */
/* @0x29d738 ldr r0, [r6] */
/* @0x29d73c bl 0x29d62c <_ZN9DbgServer7ProcessEv> */
/* @0x29d740 ldr r0, [r4, #0x14] */
/* @0x29d744 bl 0x27e084 <_ZN5Mutex4LockEv> */
/* @0x29d748 ldrb r5, [r4, #0x8] */
/* @0x29d74c ldr r0, [r4, #0x14] */
/* @0x29d750 bl 0x27e09c <_ZN5Mutex6UnlockEv> */
/* @0x29d754 mov r0, #16 */
/* @0x29d758 uxtb r5, r5 */
/* @0x29d75c cmp r5, #0 */
/* @0x29d760 beq 0x29d734 <_Z23DebuggerMessageLoopTickv+0x4c> */
/* @0x29d764 mov r0, #0 */
/* @0x29d768 pop {r4, r5, r6, pc} */
/* @0x29d76c andseq r0, r5, r8, asr #11 */

/* ── FUNC 0x29d770 · TickDebugger() · size=568 · insn=142 */
/* @0x29d770 push {r3, r4, r5, r6, r7, lr} */
/* @0x29d774 ldr r4, [pc, #0x1ec] */
/* @0x29d778 ldr r3, [pc, #0x1ec] */
/* @0x29d77c add r4, pc, r4 */
/* @0x29d780 ldr r5, [r4, r3] */
/* @0x29d784 ldr r3, [r5] */
/* @0x29d788 cmp r3, #0 */
/* @0x29d78c popeq {r3, r4, r5, r6, r7, pc} */
/* @0x29d790 bl 0x215148 <Timing_Time> */
/* @0x29d794 ldr r3, [pc, #0x1d4] */
/* @0x29d798 ldr r3, [r4, r3] */
/* @0x29d79c strd r0, r1, [r3] */
/* @0x29d7a0 bl 0xd8404 <_ZN2VM26ClearBreakpointsFromMemoryEv> */
/* @0x29d7a4 ldr r0, [r5] */
/* @0x29d7a8 bl 0x29d62c <_ZN9DbgServer7ProcessEv> */
/* @0x29d7ac bl 0xd83cc <_ZN2VM24WriteBreakpointsToMemoryEv> */
/* @0x29d7b0 ldr r3, [pc, #0x1bc] */
/* @0x29d7b4 ldr r3, [r4, r3] */
/* @0x29d7b8 ldrb r2, [r3] */
/* @0x29d7bc cmp r2, #0 */
/* @0x29d7c0 bne 0x29d8b8 <_Z12TickDebuggerv+0x148> */
/* @0x29d7c4 ldr r3, [pc, #0x1ac] */
/* @0x29d7c8 ldr r6, [r4, r3] */
/* @0x29d7cc ldr r3, [pc, #0x1a8] */
/* @0x29d7d0 add r3, pc, r3 */
/* @0x29d7d4 ldrb r3, [r3, #0x218] */
/* @0x29d7d8 cmp r3, #0 */
/* @0x29d7dc bne 0x29d8f0 <_Z12TickDebuggerv+0x180> */
/* @0x29d7e0 ldrb r3, [r6] */
/* @0x29d7e4 cmp r3, #0 */
/* @0x29d7e8 bne 0x29d84c <_Z12TickDebuggerv+0xdc> */
/* @0x29d7ec ldr r3, [pc, #0x18c] */
/* @0x29d7f0 ldr r3, [r4, r3] */
/* @0x29d7f4 ldrb r3, [r3] */
/* @0x29d7f8 cmp r3, #0 */
/* @0x29d7fc beq 0x29d8f8 <_Z12TickDebuggerv+0x188> */
/* @0x29d800 ldr r6, [pc, #0x17c] */
/* @0x29d804 add r6, pc, r6 */
/* @0x29d808 ldr r7, [r6, #0x230] */
/* @0x29d80c cmp r7, #0 */
/* @0x29d810 beq 0x29d938 <_Z12TickDebuggerv+0x1c8> */
/* @0x29d814 ldr r3, [r6, #0x22c] */
/* @0x29d818 ldr r2, [pc, #0x168] */
/* @0x29d81c add r2, pc, r2 */
/* @0x29d820 ldr r1, [r2, #0x234] */
/* @0x29d824 cmp r1, r3 */
/* @0x29d828 ble 0x29d84c <_Z12TickDebuggerv+0xdc> */
/* @0x29d82c ldr r1, [pc, #0x158] */
/* @0x29d830 add r12, r3, #1 */
/* @0x29d834 ldr r0, [r2, #0x230] */
/* @0x29d838 str r12, [r2, #0x22c] */
/* @0x29d83c ldr r2, [r4, r1] */
/* @0x29d840 add r3, r0, r3, lsl #2 */
/* @0x29d844 ldr r2, [r2] */
/* @0x29d848 str r2, [r3] */
/* @0x29d84c bl 0x29cb74 <_Z19DebuggerIsConnectedv> */
/* @0x29d850 subs r6, r0, #0 */
/* @0x29d854 popne {r3, r4, r5, r6, r7, pc} */
/* @0x29d858 ldr r3, [pc, #0x130] */
/* @0x29d85c ldr r7, [r4, r3] */
/* @0x29d860 ldrb r3, [r7] */
/* @0x29d864 cmp r3, #0 */
/* @0x29d868 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x29d86c ldr r3, [pc, #0x120] */
/* @0x29d870 ldr r1, [pc, #0x120] */
/* @0x29d874 ldr r3, [r4, r3] */
/* @0x29d878 add r1, pc, r1 */
/* @0x29d87c ldr r0, [r3] */
/* @0x29d880 ldr r3, [r0] */
/* @0x29d884 ldr r3, [r3, #0xc] */
/* @0x29d888 blx r3 */
/* @0x29d88c ldr r4, [r5] */
/* @0x29d890 strb r6, [r7] */
/* @0x29d894 cmp r4, #0 */
/* @0x29d898 beq 0x29d8ac <_Z12TickDebuggerv+0x13c> */
/* @0x29d89c mov r0, r4 */
/* @0x29d8a0 bl 0x29d038 <_ZN9DbgServerD2Ev> */
/* @0x29d8a4 mov r0, r4 */
/* @0x29d8a8 bl 0x27d1d0 <_ZdlPv> */
/* @0x29d8ac mov r3, #0 */
/* @0x29d8b0 str r3, [r5] */
/* @0x29d8b4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x29d8b8 ldr r2, [pc, #0xb8] */
/* @0x29d8bc ldr r6, [r4, r2] */
/* @0x29d8c0 ldrb r2, [r6] */
/* @0x29d8c4 cmp r2, #0 */
/* @0x29d8c8 bne 0x29d7cc <_Z12TickDebuggerv+0x5c> */
/* @0x29d8cc ldr r1, [pc, #0xc8] */
/* @0x29d8d0 strb r2, [r3] */
/* @0x29d8d4 ldr r3, [r4, r1] */
/* @0x29d8d8 ldrb r3, [r3] */
/* @0x29d8dc cmp r3, #0 */
/* @0x29d8e0 beq 0x29d928 <_Z12TickDebuggerv+0x1b8> */
/* @0x29d8e4 mov r3, #0 */
/* @0x29d8e8 strb r3, [r6] */
/* @0x29d8ec b 0x29d7cc <_Z12TickDebuggerv+0x5c> */
/* @0x29d8f0 bl 0x29cdec <_Z14DebuggerPingIPv> */
/* @0x29d8f4 b 0x29d7e0 <_Z12TickDebuggerv+0x70> */
/* @0x29d8f8 ldr r2, [pc, #0x8c] */
/* @0x29d8fc ldr r3, [pc, #0x9c] */
/* @0x29d900 ldr r2, [r4, r2] */
/* @0x29d904 add r3, pc, r3 */
/* @0x29d908 vldr s15, [r2] */
/* @0x29d90c vldr s14, [r3, #552] */
/* @0x29d910 vadd.f32 s15, s14, s15 */
/* @0x29d914 ldr r2, [r3, #0x22c] */
/* @0x29d918 add r2, r2, #1 */
/* @0x29d91c str r2, [r3, #0x22c] */
/* @0x29d920 vstr s15, [r3, #552] */
/* @0x29d924 b 0x29d84c <_Z12TickDebuggerv+0xdc> */
/* @0x29d928 bl 0x1b5d08 <_Z10Room_Firstv> */
/* @0x29d92c mov r1, #1 */
/* @0x29d930 bl 0x1d38e0 <_Z9StartRoomib> */
/* @0x29d934 b 0x29d8e4 <_Z12TickDebuggerv+0x174> */
/* @0x29d938 ldr r1, [pc, #0x64] */
/* @0x29d93c mov r3, #1 */
/* @0x29d940 mov r0, #512 */
/* @0x29d944 movw r2, #0x6c2 */
/* @0x29d948 add r1, pc, r1 */
/* @0x29d94c mov r12, #128 */
/* @0x29d950 str r12, [r6, #0x234] */
/* @0x29d954 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x29d958 mov r3, r7 */
/* @0x29d95c str r7, [r6, #0x22c] */
/* @0x29d960 str r0, [r6, #0x230] */
/* @0x29d964 b 0x29d818 <_Z12TickDebuggerv+0xa8> */
/* @0x29d968 ldrsbeq r4, [r5], -r4 */
/* @0x29d96c .word 0xffffc0a4 */
/* @0x29d970 .word 0xfffffdc4 */
/* @0x29d974 .word 0xffffdf9c */
/* @0x29d978 .word 0xffffdfa0 */
/* @0x29d97c subeq r10, r11, r8, lsr r4 */
/* @0x29d980 .word 0xffffbcd4 */
/* @0x29d984 subeq r10, r11, r4, lsl #8 */
/* @0x29d988 subeq r10, r11, r12, ror #7 */
/* @0x29d98c .word 0xffffe7a8 */
/* @0x29d990 .word 0xfffffdc0 */
/* @0x29d994 .word 0xffffbcf0 */
/* @0x29d998 ldrdeq r12, sp, [r11], -r12 */
/* @0x29d99c .word 0xffffbf68 */
/* @0x29d9a0 subeq r10, r11, r4, lsl #6 */
/* @0x29d9a4 andeq r12, r11, r12, ror r0 */

/* ── FUNC 0x29d9a8 · DbgSocket::Write(void*, unsigned int) · size=8 · insn=2 */
/* @0x29d9a8 ldr r0, [r0] */
/* @0x29d9ac b 0x295464 <_ZN8yySocket5WriteEPvj> */

/* ── FUNC 0x29d9b0 · DbgSocket::GetUserData() · size=12 · insn=3 */
/* @0x29d9b0 ldr r3, [r0] */
/* @0x29d9b4 ldr r0, [r3, #0x4c] */
/* @0x29d9b8 bx lr */

/* ── FUNC 0x29d9bc · Debug_GetSelectedInstance(DbgSocket*) · size=320 · insn=80 */
/* @0x29d9bc push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x29d9c0 mov r10, r0 */
/* @0x29d9c4 bl 0x29d9b0 <_ZN9DbgSocket11GetUserDataEv> */
/* @0x29d9c8 mov r7, #0 */
/* @0x29d9cc mov r2, #465567744 */
/* @0x29d9d0 movw r3, #0xc238 */
/* @0x29d9d4 movt r3, #0x41e7 */
/* @0x29d9d8 ldr r1, [r0] */
/* @0x29d9dc add r8, r0, #44 */
/* @0x29d9e0 mov r6, r0 */
/* @0x29d9e4 str r2, [r0, #0x2c] */
/* @0x29d9e8 str r3, [r0, #0x30] */
/* @0x29d9ec mov r2, r8 */
/* @0x29d9f0 ldr r3, [r1, #0x8] */
/* @0x29d9f4 mov r1, #5 */
/* @0x29d9f8 str r7, [r0, #0x38] */
/* @0x29d9fc blx r3 */
/* @0x29da00 ldr r3, [r6] */
/* @0x29da04 str r7, [r6, #0x2c] */
/* @0x29da08 mov r2, r8 */
/* @0x29da0c str r7, [r6, #0x30] */
/* @0x29da10 mov r0, r6 */
/* @0x29da14 str r7, [r6, #0x38] */
/* @0x29da18 mov r1, #5 */
/* @0x29da1c ldr r3, [r3, #0x8] */
/* @0x29da20 blx r3 */
/* @0x29da24 ldr r1, [r6] */
/* @0x29da28 str r7, [r6, #0x2c] */
/* @0x29da2c mov r2, r8 */
/* @0x29da30 mov r3, r7 */
/* @0x29da34 str r7, [r6, #0x38] */
/* @0x29da38 movt r3, #0x402e */
/* @0x29da3c mov r0, r6 */
/* @0x29da40 str r3, [r6, #0x30] */
/* @0x29da44 ldr r3, [r1, #0x8] */
/* @0x29da48 mov r1, #5 */
/* @0x29da4c blx r3 */
/* @0x29da50 ldr r1, [r6] */
/* @0x29da54 str r7, [r6, #0x38] */
/* @0x29da58 mov r2, r7 */
/* @0x29da5c mov r0, r6 */
/* @0x29da60 movt r2, #0xffe0 */
/* @0x29da64 movw r3, #0xffff */
/* @0x29da68 str r2, [r6, #0x2c] */
/* @0x29da6c movt r3, #0x41ef */
/* @0x29da70 mov r2, r8 */
/* @0x29da74 str r3, [r6, #0x30] */
/* @0x29da78 ldr r3, [r1, #0x8] */
/* @0x29da7c mov r1, #5 */
/* @0x29da80 blx r3 */
/* @0x29da84 ldr r3, [r6] */
/* @0x29da88 ldr r9, [r6, #0x1c] */
/* @0x29da8c mov r1, r7 */
/* @0x29da90 mov r0, r6 */
/* @0x29da94 mov r2, #4 */
/* @0x29da98 ldr r3, [r3, #0x10] */
/* @0x29da9c blx r3 */
/* @0x29daa0 vmov s15, r9 */
/* @0x29daa4 ldr r3, [r6] */
/* @0x29daa8 mov r2, r8 */
/* @0x29daac vcvt.f64.u32 d7, s15 */
/* @0x29dab0 str r7, [r6, #0x38] */
/* @0x29dab4 mov r0, r6 */
/* @0x29dab8 mov r1, #5 */
/* @0x29dabc vmov r4, r5, d7 */
/* @0x29dac0 vstr s14, [r6, #44] */
/* @0x29dac4 str r5, [r6, #0x30] */
/* @0x29dac8 ldr r3, [r3, #0x8] */
/* @0x29dacc blx r3 */
/* @0x29dad0 ldr r3, [r6] */
/* @0x29dad4 mov r1, r7 */
/* @0x29dad8 mov r2, r9 */
/* @0x29dadc mov r0, r6 */
/* @0x29dae0 ldr r3, [r3, #0x10] */
/* @0x29dae4 blx r3 */
/* @0x29dae8 mov r0, r10 */
/* @0x29daec mov r2, r9 */
/* @0x29daf0 ldr r1, [r6, #0xc] */
/* @0x29daf4 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x29daf8 b 0x29d9a8 <_ZN9DbgSocket5WriteEPvj> */

/* ── FUNC 0x29dafc · Debug_GetWatches(Buffer_Standard*, Buffer_Standard*) · size=1568 · insn=392 */
/* @0x29dafc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x29db00 vpush {d8} */
/* @0x29db04 add r11, sp, #40 */
/* @0x29db08 ldr r5, [pc, #0x5f8] */
/* @0x29db0c sub sp, sp, #132 */
/* @0x29db10 ldr r12, [pc, #0x5f4] */
/* @0x29db14 add r5, pc, r5 */
/* @0x29db18 str r1, [r11, #-0x78] */
/* @0x29db1c ldr r3, [r0] */
/* @0x29db20 add r10, r0, #44 */
/* @0x29db24 ldr r12, [r5, r12] */
/* @0x29db28 mov r1, #5 */
/* @0x29db2c ldr r4, [r11, #-0x78] */
/* @0x29db30 mov r2, r10 */
/* @0x29db34 ldr r3, [r3, #0xc] */
/* @0x29db38 mov r8, r0 */
/* @0x29db3c str r12, [r11, #-0xa8] */
/* @0x29db40 add r4, r4, #44 */
/* @0x29db44 ldr r12, [r12] */
/* @0x29db48 str r4, [r11, #-0x9c] */
/* @0x29db4c mov r4, #0 */
/* @0x29db50 str r12, [r11, #-0x30] */
/* @0x29db54 blx r3 */
/* @0x29db58 mov r1, r4 */
/* @0x29db5c mov r0, r10 */
/* @0x29db60 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29db64 ldr r3, [r11, #-0x78] */
/* @0x29db68 ldr r2, [r11, #-0x9c] */
/* @0x29db6c mov r1, #5 */
/* @0x29db70 ldr lr, [r3] */
/* @0x29db74 str r4, [r3, #0x38] */
/* @0x29db78 vmov s15, r0 */
/* @0x29db7c str r0, [r11, #-0x90] */
/* @0x29db80 mov r0, r3 */
/* @0x29db84 vcvt.f64.u32 d7, s15 */
/* @0x29db88 vmov r6, r7, d7 */
/* @0x29db8c mov r6, r0 */
/* @0x29db90 vstr s14, [r0, #44] */
/* @0x29db94 str r7, [r6, #0x30] */
/* @0x29db98 ldr r3, [lr, #0x8] */
/* @0x29db9c blx r3 */
/* @0x29dba0 ldr r3, [pc, #0x568] */
/* @0x29dba4 ldr r12, [r11, #-0x90] */
/* @0x29dba8 ldr r3, [r5, r3] */
/* @0x29dbac cmp r12, r4 */
/* @0x29dbb0 str r3, [r11, #-0x94] */
/* @0x29dbb4 ldr r3, [r3] */
/* @0x29dbb8 str r3, [r11, #-0x98] */
/* @0x29dbbc ble 0x29e0cc <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x5d0> */
/* @0x29dbc0 ldr r3, [pc, #0x54c] */
/* @0x29dbc4 sub r6, r11, #76 */
/* @0x29dbc8 ldr r2, [pc, #0x548] */
/* @0x29dbcc sub r12, r11, #92 */
/* @0x29dbd0 str r4, [r11, #-0x7c] */
/* @0x29dbd4 mov r4, #0 */
/* @0x29dbd8 str r6, [r11, #-0xa4] */
/* @0x29dbdc movt r4, #0xc007 */
/* @0x29dbe0 str r4, [r11, #-0xa0] */
/* @0x29dbe4 sub r4, r11, #96 */
/* @0x29dbe8 ldr r3, [r5, r3] */
/* @0x29dbec str r12, [r11, #-0x84] */
/* @0x29dbf0 ldr r2, [r5, r2] */
/* @0x29dbf4 add r3, r3, #8 */
/* @0x29dbf8 str r4, [r11, #-0x74] */
/* @0x29dbfc str r3, [r11, #-0x8c] */
/* @0x29dc00 str r2, [r11, #-0x88] */
/* @0x29dc04 ldr r3, [r8] */
/* @0x29dc08 mov r2, r10 */
/* @0x29dc0c mov r1, #5 */
/* @0x29dc10 mov r0, r8 */
/* @0x29dc14 ldr r3, [r3, #0xc] */
/* @0x29dc18 blx r3 */
/* @0x29dc1c mov r1, #0 */
/* @0x29dc20 mov r0, r10 */
/* @0x29dc24 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29dc28 vmov s16, r0 */
/* @0x29dc2c mov r0, r8 */
/* @0x29dc30 bl 0x29e69c <_Z10ReadStringP15Buffer_Standard> */
/* @0x29dc34 ldr r3, [r8] */
/* @0x29dc38 mov r2, r10 */
/* @0x29dc3c mov r1, #5 */
/* @0x29dc40 ldr r3, [r3, #0xc] */
/* @0x29dc44 str r0, [r11, #-0x80] */
/* @0x29dc48 mov r0, r8 */
/* @0x29dc4c blx r3 */
/* @0x29dc50 mov r1, #0 */
/* @0x29dc54 mov r0, r10 */
/* @0x29dc58 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29dc5c ldr r6, [r11, #-0x8c] */
/* @0x29dc60 mov r12, #0 */
/* @0x29dc64 str r12, [r11, #-0x3c] */
/* @0x29dc68 str r12, [r11, #-0x38] */
/* @0x29dc6c str r6, [r11, #-0x4c] */
/* @0x29dc70 str r12, [r11, #-0x34] */
/* @0x29dc74 mov r5, r0 */
/* @0x29dc78 str r0, [r11, #-0x48] */
/* @0x29dc7c bl 0x27d14c <_Znaj> */
/* @0x29dc80 cmp r5, #0 */
/* @0x29dc84 mov r4, r0 */
/* @0x29dc88 str r0, [r11, #-0x3c] */
/* @0x29dc8c addne r5, r0, r5 */
/* @0x29dc90 movne r6, r0 */
/* @0x29dc94 beq 0x29dcc8 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x1cc> */
/* @0x29dc98 ldr r3, [r8] */
/* @0x29dc9c mov r1, #1 */
/* @0x29dca0 mov r2, r10 */
/* @0x29dca4 mov r0, r8 */
/* @0x29dca8 ldr r3, [r3, #0xc] */
/* @0x29dcac blx r3 */
/* @0x29dcb0 mov r0, r10 */
/* @0x29dcb4 mov r1, #0 */
/* @0x29dcb8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x29dcbc strb r0, [r6], #1 */
/* @0x29dcc0 cmp r6, r5 */
/* @0x29dcc4 bne 0x29dc98 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x19c> */
/* @0x29dcc8 ldr r3, [r8] */
/* @0x29dccc mov r1, #5 */
/* @0x29dcd0 mov r2, r10 */
/* @0x29dcd4 mov r0, r8 */
/* @0x29dcd8 ldr r3, [r3, #0xc] */
/* @0x29dcdc blx r3 */
/* @0x29dce0 mov r0, r10 */
/* @0x29dce4 mov r1, #0 */
/* @0x29dce8 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29dcec cmp r0, #0 */
/* @0x29dcf0 str r0, [r11, #-0x70] */
/* @0x29dcf4 movne r3, #0 */
/* @0x29dcf8 strne r3, [r11, #-0x6c] */
/* @0x29dcfc beq 0x29dde4 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x2e8> */
/* @0x29dd00 mov r0, r8 */
/* @0x29dd04 bl 0x29e69c <_Z10ReadStringP15Buffer_Standard> */
/* @0x29dd08 ldr r3, [r8] */
/* @0x29dd0c mov r1, #5 */
/* @0x29dd10 mov r2, r10 */
/* @0x29dd14 ldr r3, [r3, #0xc] */
/* @0x29dd18 mov r6, r0 */
/* @0x29dd1c mov r0, r8 */
/* @0x29dd20 blx r3 */
/* @0x29dd24 mov r0, r10 */
/* @0x29dd28 mov r1, #0 */
/* @0x29dd2c bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29dd30 cmp r0, #0 */
/* @0x29dd34 str r0, [r11, #-0x68] */
/* @0x29dd38 movne r5, #0 */
/* @0x29dd3c beq 0x29ddc4 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x2c8> */
/* @0x29dd40 ldr r3, [r8] */
/* @0x29dd44 mov r2, r10 */
/* @0x29dd48 mov r1, #5 */
/* @0x29dd4c mov r0, r8 */
/* @0x29dd50 add r5, r5, #1 */
/* @0x29dd54 ldr r3, [r3, #0xc] */
/* @0x29dd58 blx r3 */
/* @0x29dd5c mov r1, #0 */
/* @0x29dd60 mov r0, r10 */
/* @0x29dd64 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29dd68 ldr r3, [r8] */
/* @0x29dd6c mov r2, r10 */
/* @0x29dd70 mov r1, #5 */
/* @0x29dd74 ldr r3, [r3, #0xc] */
/* @0x29dd78 mov r9, r0 */
/* @0x29dd7c mov r0, r8 */
/* @0x29dd80 blx r3 */
/* @0x29dd84 mov r1, #0 */
/* @0x29dd88 mov r0, r10 */
/* @0x29dd8c bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29dd90 mov r1, r9 */
/* @0x29dd94 mov r7, r0 */
/* @0x29dd98 mov r0, r6 */
/* @0x29dd9c bl 0xd20c0 <_Z22New_Code_Variable_FindPKc13EVariableType> */
/* @0x29dda0 add r3, r7, #4 */
/* @0x29dda4 ldr r12, [r11, #-0x68] */
/* @0x29dda8 ldr r2, [r4, r3] */
/* @0x29ddac cmp r5, r12 */
/* @0x29ddb0 and r2, r2, #-268435456 */
/* @0x29ddb4 bic r0, r0, #-268435456 */
/* @0x29ddb8 orr r2, r2, r0 */
/* @0x29ddbc str r2, [r4, r3] */
/* @0x29ddc0 bne 0x29dd40 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x244> */
/* @0x29ddc4 mov r0, r6 */
/* @0x29ddc8 ldr r6, [r11, #-0x6c] */
/* @0x29ddcc add r6, r6, #1 */
/* @0x29ddd0 str r6, [r11, #-0x6c] */
/* @0x29ddd4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x29ddd8 ldr r12, [r11, #-0x70] */
/* @0x29dddc cmp r6, r12 */
/* @0x29dde0 bne 0x29dd00 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x204> */
/* @0x29dde4 ldr r3, [r8] */
/* @0x29dde8 mov r1, #5 */
/* @0x29ddec mov r2, r10 */
/* @0x29ddf0 mov r0, r8 */
/* @0x29ddf4 ldr r3, [r3, #0xc] */
/* @0x29ddf8 blx r3 */
/* @0x29ddfc mov r0, r10 */
/* @0x29de00 mov r1, #0 */
/* @0x29de04 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29de08 cmp r0, #0 */
/* @0x29de0c str r0, [r11, #-0x68] */
/* @0x29de10 movne r6, #0 */
/* @0x29de14 beq 0x29deb0 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x3b4> */
/* @0x29de18 mov r0, r8 */
/* @0x29de1c bl 0x29e69c <_Z10ReadStringP15Buffer_Standard> */
/* @0x29de20 sub r1, r11, #96 */
/* @0x29de24 mov r9, r0 */
/* @0x29de28 bl 0xce158 <_Z18Code_Function_FindPKcPi> */
/* @0x29de2c ldr r12, [r8] */
/* @0x29de30 mov r1, #5 */
/* @0x29de34 mov r2, r10 */
/* @0x29de38 mov r0, r8 */
/* @0x29de3c ldr r12, [r12, #0xc] */
/* @0x29de40 blx r12 */
/* @0x29de44 mov r0, r10 */
/* @0x29de48 mov r1, #0 */
/* @0x29de4c bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29de50 subs r7, r0, #0 */
/* @0x29de54 movne r5, #0 */
/* @0x29de58 beq 0x29de98 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x39c> */
/* @0x29de5c ldr r3, [r8] */
/* @0x29de60 mov r1, #5 */
/* @0x29de64 mov r2, r10 */
/* @0x29de68 mov r0, r8 */
/* @0x29de6c add r5, r5, #1 */
/* @0x29de70 ldr r3, [r3, #0xc] */
/* @0x29de74 blx r3 */
/* @0x29de78 mov r0, r10 */
/* @0x29de7c mov r1, #0 */
/* @0x29de80 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29de84 ldr r3, [r11, #-0x60] */
/* @0x29de88 cmp r5, r7 */
/* @0x29de8c add r0, r4, r0 */
/* @0x29de90 str r3, [r0, #0x4] */
/* @0x29de94 bne 0x29de5c <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x360> */
/* @0x29de98 mov r0, r9 */
/* @0x29de9c add r6, r6, #1 */
/* @0x29dea0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x29dea4 ldr r12, [r11, #-0x68] */
/* @0x29dea8 cmp r6, r12 */
/* @0x29deac bne 0x29de18 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x31c> */
/* @0x29deb0 ldr r3, [r8] */
/* @0x29deb4 mov r1, #5 */
/* @0x29deb8 mov r2, r10 */
/* @0x29debc mov r0, r8 */
/* @0x29dec0 ldr r3, [r3, #0xc] */
/* @0x29dec4 blx r3 */
/* @0x29dec8 mov r0, r10 */
/* @0x29decc mov r1, #0 */
/* @0x29ded0 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29ded4 lsl r3, r0, #2 */
/* @0x29ded8 cmp r0, #0 */
/* @0x29dedc add r3, r3, #14 */
/* @0x29dee0 mov r5, r0 */
/* @0x29dee4 bic r3, r3, #7 */
/* @0x29dee8 movne r7, #0 */
/* @0x29deec sub sp, sp, r3 */
/* @0x29def0 ldr r3, [r11, #-0x88] */
/* @0x29def4 subne r6, sp, #4 */
/* @0x29def8 mov r9, sp */
/* @0x29defc str sp, [r3] */
/* @0x29df00 beq 0x29df1c <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x420> */
/* @0x29df04 mov r0, r8 */
/* @0x29df08 add r7, r7, #1 */
/* @0x29df0c bl 0x29e69c <_Z10ReadStringP15Buffer_Standard> */
/* @0x29df10 cmp r7, r5 */
/* @0x29df14 str r0, [r6, #0x4]! */
/* @0x29df18 bne 0x29df04 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x408> */
/* @0x29df1c ldr r3, [r8] */
/* @0x29df20 mov r1, #5 */
/* @0x29df24 mov r2, r10 */
/* @0x29df28 mov r0, r8 */
/* @0x29df2c ldr r3, [r3, #0xc] */
/* @0x29df30 blx r3 */
/* @0x29df34 mov r0, r10 */
/* @0x29df38 mov r1, #0 */
/* @0x29df3c bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29df40 subs r6, r0, #0 */
/* @0x29df44 beq 0x29df90 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x494> */
/* @0x29df48 str r5, [r11, #-0x68] */
/* @0x29df4c mov r7, #0 */
/* @0x29df50 ldr r5, [r11, #-0xa0] */
/* @0x29df54 ldr r12, [r8] */
/* @0x29df58 mov r1, #5 */
/* @0x29df5c mov r2, r10 */
/* @0x29df60 mov r0, r8 */
/* @0x29df64 add r7, r7, #1 */
/* @0x29df68 ldr r12, [r12, #0xc] */
/* @0x29df6c blx r12 */
/* @0x29df70 mov r0, r10 */
/* @0x29df74 mov r1, #0 */
/* @0x29df78 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29df7c cmp r7, r6 */
/* @0x29df80 add r0, r4, r0 */
/* @0x29df84 str r5, [r0, #-0x4] */
/* @0x29df88 bne 0x29df54 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x458> */
/* @0x29df8c ldr r5, [r11, #-0x68] */
/* @0x29df90 ldr r3, [r11, #-0x98] */
/* @0x29df94 sub r1, r11, #76 */
/* @0x29df98 ldr r4, [r11, #-0x94] */
/* @0x29df9c sub r2, r11, #92 */
/* @0x29dfa0 ldr r0, [r11, #-0x80] */
/* @0x29dfa4 str r3, [r4] */
/* @0x29dfa8 bl 0x29a83c <_Z18ExecuteDebugScriptPcP8VMBufferP6RValue> */
/* @0x29dfac vcvt.f64.u32 d7, s16 */
/* @0x29dfb0 ldr r3, [r11, #-0x78] */
/* @0x29dfb4 ldr r2, [r11, #-0x9c] */
/* @0x29dfb8 mov r4, #0 */
/* @0x29dfbc mov r1, #5 */
/* @0x29dfc0 ldr lr, [r3] */
/* @0x29dfc4 mov r0, r3 */
/* @0x29dfc8 str r4, [r3, #0x38] */
/* @0x29dfcc vmov r6, r7, d7 */
/* @0x29dfd0 mov r6, r0 */
/* @0x29dfd4 vstr s14, [r6, #44] */
/* @0x29dfd8 str r7, [r6, #0x30] */
/* @0x29dfdc ldr r3, [lr, #0x8] */
/* @0x29dfe0 blx r3 */
/* @0x29dfe4 sub r0, r11, #92 */
/* @0x29dfe8 ldr r1, [r11, #-0x78] */
/* @0x29dfec bl 0xd8a88 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard> */
/* @0x29dff0 ldr r0, [r11, #-0x80] */
/* @0x29dff4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x29dff8 ldr r3, [r11, #-0x50] */
/* @0x29dffc sub r3, r3, #1 */
/* @0x29e000 bic r3, r3, #-16777216 */
/* @0x29e004 bic r3, r3, #3 */
/* @0x29e008 cmp r3, r4 */
/* @0x29e00c beq 0x29e0f8 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x5fc> */
/* @0x29e010 cmp r5, #0 */
/* @0x29e014 mov r12, #0 */
/* @0x29e018 mov r0, #5 */
/* @0x29e01c str r12, [r11, #-0x54] */
/* @0x29e020 str r0, [r11, #-0x50] */
/* @0x29e024 subne r9, r9, #4 */
/* @0x29e028 str r12, [r11, #-0x5c] */
/* @0x29e02c movne r4, #0 */
/* @0x29e030 beq 0x29e048 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x54c> */
/* @0x29e034 add r4, r4, #1 */
/* @0x29e038 ldr r0, [r9, #0x4]! */
/* @0x29e03c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x29e040 cmp r4, r5 */
/* @0x29e044 bne 0x29e034 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x538> */
/* @0x29e048 ldr r0, [r11, #-0x38] */
/* @0x29e04c mov r4, #0 */
/* @0x29e050 ldr r3, [r11, #-0x88] */
/* @0x29e054 ldr r6, [r11, #-0x8c] */
/* @0x29e058 cmp r0, r4 */
/* @0x29e05c str r4, [r3] */
/* @0x29e060 str r6, [r11, #-0x4c] */
/* @0x29e064 beq 0x29e074 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x578> */
/* @0x29e068 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x29e06c mov r12, #0 */
/* @0x29e070 str r12, [r11, #-0x38] */
/* @0x29e074 ldr r0, [r11, #-0x34] */
/* @0x29e078 cmp r0, #0 */
/* @0x29e07c beq 0x29e08c <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x590> */
/* @0x29e080 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x29e084 mov r0, #0 */
/* @0x29e088 str r0, [r11, #-0x34] */
/* @0x29e08c ldr r0, [r11, #-0x3c] */
/* @0x29e090 cmp r0, #0 */
/* @0x29e094 beq 0x29e0b4 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x5b8> */
/* @0x29e098 bl 0x1aad50 <_Z11MemoryInWadPv> */
/* @0x29e09c cmp r0, #0 */
/* @0x29e0a0 bne 0x29e0b4 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x5b8> */
/* @0x29e0a4 ldr r0, [r11, #-0x3c] */
/* @0x29e0a8 cmp r0, #0 */
/* @0x29e0ac beq 0x29e0b4 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x5b8> */
/* @0x29e0b0 bl 0x27d1d4 <_ZdaPv> */
/* @0x29e0b4 ldr r3, [r11, #-0x7c] */
/* @0x29e0b8 ldr r4, [r11, #-0x90] */
/* @0x29e0bc add r3, r3, #1 */
/* @0x29e0c0 str r3, [r11, #-0x7c] */
/* @0x29e0c4 cmp r4, r3 */
/* @0x29e0c8 bne 0x29dc04 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x108> */
/* @0x29e0cc ldr r4, [r11, #-0xa8] */
/* @0x29e0d0 ldr r2, [r11, #-0x30] */
/* @0x29e0d4 ldr r6, [r11, #-0x98] */
/* @0x29e0d8 ldr r3, [r4] */
/* @0x29e0dc ldr r12, [r11, #-0x94] */
/* @0x29e0e0 cmp r2, r3 */
/* @0x29e0e4 str r6, [r12] */
/* @0x29e0e8 bne 0x29e104 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x608> */
/* @0x29e0ec sub sp, r11, #40 */
/* @0x29e0f0 vpop {d8} */
/* @0x29e0f4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x29e0f8 sub r0, r11, #92 */
/* @0x29e0fc bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x29e100 b 0x29e010 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x514> */
/* @0x29e104 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x29e108 andseq r4, r5, r12, lsr r1 */
/* @0x29e10c .word 0xffffbd00 */
/* @0x29e110 .word 0xffffbf58 */
/* @0x29e114 .word 0xffffbedc */
/* @0x29e118 .word 0xffffc118 */

/* ── FUNC 0x29e11c · Debug_ReadCommand(eNetworkCommand, Buffer_Standard*, Buffer_Standard*) · size=272 · insn=68 */
/* @0x29e11c push {r3, lr} */
/* @0x29e120 sub r3, r0, #1 */
/* @0x29e124 cmp r3, #17 */
/* @0x29e128 addls pc, pc, r3, lsl #2 */
/* @0x29e12c b 0x29e1fc <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_+0xe0> */
/* @0x29e130 b 0x29e184 <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_+0x68> */
/* @0x29e134 b 0x29e1fc <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_+0xe0> */
/* @0x29e138 b 0x29e1fc <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_+0xe0> */
/* @0x29e13c b 0x29e1fc <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_+0xe0> */
/* @0x29e140 b 0x29e1fc <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_+0xe0> */
/* @0x29e144 b 0x29e1fc <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_+0xe0> */
/* @0x29e148 b 0x29e190 <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_+0x74> */
/* @0x29e14c b 0x29e19c <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_+0x80> */
/* @0x29e150 b 0x29e1fc <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_+0xe0> */
/* @0x29e154 b 0x29e1a8 <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_+0x8c> */
/* @0x29e158 b 0x29e1b4 <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_+0x98> */
/* @0x29e15c b 0x29e1c0 <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_+0xa4> */
/* @0x29e160 b 0x29e1cc <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_+0xb0> */
/* @0x29e164 b 0x29e1fc <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_+0xe0> */
/* @0x29e168 b 0x29e1d8 <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_+0xbc> */
/* @0x29e16c b 0x29e1e4 <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_+0xc8> */
/* @0x29e170 b 0x29e1f0 <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_+0xd4> */
/* @0x29e174 b 0x29e178 <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_+0x5c> */
/* @0x29e178 mov r0, r2 */
/* @0x29e17c pop {r3, lr} */
/* @0x29e180 b 0x29ad38 <_Z17Debug_GetTexturesP15Buffer_StandardS0_> */
/* @0x29e184 mov r0, r2 */
/* @0x29e188 pop {r3, lr} */
/* @0x29e18c b 0x29d078 <_Z13Debug_GetPingP15Buffer_StandardS0_> */
/* @0x29e190 mov r0, r2 */
/* @0x29e194 pop {r3, lr} */
/* @0x29e198 b 0x29ab8c <_Z18Debug_GetInstancesP15Buffer_StandardS0_> */
/* @0x29e19c mov r0, r2 */
/* @0x29e1a0 pop {r3, lr} */
/* @0x29e1a4 b 0x29aa44 <_Z20Debug_GetJSInstancesP15Buffer_StandardS0_> */
/* @0x29e1a8 mov r0, r2 */
/* @0x29e1ac pop {r3, lr} */
/* @0x29e1b0 b 0x29dafc <_Z16Debug_GetWatchesP15Buffer_StandardS0_> */
/* @0x29e1b4 mov r0, r2 */
/* @0x29e1b8 pop {r3, lr} */
/* @0x29e1bc b 0x29d4d4 <_Z15Debug_GetUpdateP15Buffer_StandardS0_> */
/* @0x29e1c0 mov r0, r2 */
/* @0x29e1c4 pop {r3, lr} */
/* @0x29e1c8 b 0x29b3c0 <_Z15Debug_GetArraysP15Buffer_StandardS0_> */
/* @0x29e1cc mov r0, r2 */
/* @0x29e1d0 pop {r3, lr} */
/* @0x29e1d4 b 0x29bd84 <_Z19Debug_GetStructuresP15Buffer_StandardS0_> */
/* @0x29e1d8 mov r0, r2 */
/* @0x29e1dc pop {r3, lr} */
/* @0x29e1e0 b 0x29c608 <_Z25Debug_GetSelectedInstanceP15Buffer_StandardS0_> */
/* @0x29e1e4 mov r0, r2 */
/* @0x29e1e8 pop {r3, lr} */
/* @0x29e1ec b 0x29b098 <_Z16Debug_GetBuffersP15Buffer_StandardS0_> */
/* @0x29e1f0 mov r0, r2 */
/* @0x29e1f4 pop {r3, lr} */
/* @0x29e1f8 b 0x29bb78 <_Z19Debug_PokeStructureP15Buffer_StandardS0_> */
/* @0x29e1fc ldr r3, [pc, #0x20] */
/* @0x29e200 mov r2, r0 */
/* @0x29e204 ldr r1, [pc, #0x1c] */
/* @0x29e208 ldr r3, [pc, r3] */
/* @0x29e20c add r1, pc, r1 */
/* @0x29e210 ldr r0, [r3] */
/* @0x29e214 ldr r3, [r0] */
/* @0x29e218 ldr r3, [r3, #0xc] */
/* @0x29e21c blx r3 */
/* @0x29e220 pop {r3, pc} */
/* @0x29e224 andseq pc, r4, r12, lsl #10 */
/* @0x29e228 andeq r11, r11, r0, ror #18 */

/* ── FUNC 0x29e22c · Debug_GetData(eNetworkCommand, DbgSocket*, unsigned char*, int) · size=736 · insn=184 */
/* @0x29e22c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x29e230 sub sp, sp, #20 */
/* @0x29e234 mov r8, r0 */
/* @0x29e238 mov r0, r1 */
/* @0x29e23c mov r6, r3 */
/* @0x29e240 mov r5, r2 */
/* @0x29e244 str r1, [sp, #0x8] */
/* @0x29e248 bl 0x29d9b0 <_ZN9DbgSocket11GetUserDataEv> */
/* @0x29e24c mov r9, #0 */
/* @0x29e250 mov r1, r6 */
/* @0x29e254 mov r2, r9 */
/* @0x29e258 mov r4, r0 */
/* @0x29e25c mov r0, r5 */
/* @0x29e260 bl 0xc6a10 <_Z15AllocateIBufferPvib> */
/* @0x29e264 add r7, r4, #44 */
/* @0x29e268 str r0, [sp, #0xc] */
/* @0x29e26c bl 0xc6720 <_Z10GetIBufferi> */
/* @0x29e270 ldr r1, [r4] */
/* @0x29e274 mov r2, #465567744 */
/* @0x29e278 movw r3, #0xc238 */
/* @0x29e27c str r2, [r4, #0x2c] */
/* @0x29e280 movt r3, #0x41e7 */
/* @0x29e284 mov r2, r7 */
/* @0x29e288 str r3, [r4, #0x30] */
/* @0x29e28c ldr r3, [r1, #0x8] */
/* @0x29e290 mov r1, #5 */
/* @0x29e294 str r9, [r4, #0x38] */
/* @0x29e298 mov r5, r0 */
/* @0x29e29c mov r0, r4 */
/* @0x29e2a0 blx r3 */
/* @0x29e2a4 ldr r3, [r4] */
/* @0x29e2a8 str r9, [r4, #0x2c] */
/* @0x29e2ac mov r2, r7 */
/* @0x29e2b0 str r9, [r4, #0x30] */
/* @0x29e2b4 mov r1, #5 */
/* @0x29e2b8 ldr r3, [r3, #0x8] */
/* @0x29e2bc mov r0, r4 */
/* @0x29e2c0 str r9, [r4, #0x38] */
/* @0x29e2c4 add r6, r5, #44 */
/* @0x29e2c8 blx r3 */
/* @0x29e2cc vmov s13, r8 */
/* @0x29e2d0 ldr r3, [r4] */
/* @0x29e2d4 mov r2, r7 */
/* @0x29e2d8 vcvt.f64.u32 d7, s13 */
/* @0x29e2dc mov r1, #5 */
/* @0x29e2e0 str r9, [r4, #0x38] */
/* @0x29e2e4 mov r0, r4 */
/* @0x29e2e8 vstr s14, [r4, #44] */
/* @0x29e2ec vstr s15, [r4, #48] */
/* @0x29e2f0 ldr r3, [r3, #0x8] */
/* @0x29e2f4 blx r3 */
/* @0x29e2f8 ldr r3, [r5] */
/* @0x29e2fc mov r2, r6 */
/* @0x29e300 mov r1, #5 */
/* @0x29e304 mov r0, r5 */
/* @0x29e308 ldr r3, [r3, #0xc] */
/* @0x29e30c blx r3 */
/* @0x29e310 mov r1, r9 */
/* @0x29e314 mov r0, r6 */
/* @0x29e318 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29e31c ldr r3, [r5] */
/* @0x29e320 mov r2, r6 */
/* @0x29e324 mov r1, #5 */
/* @0x29e328 mov r0, r5 */
/* @0x29e32c ldr r3, [r3, #0xc] */
/* @0x29e330 blx r3 */
/* @0x29e334 mov r1, r9 */
/* @0x29e338 mov r0, r6 */
/* @0x29e33c bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29e340 ldr r3, [r5] */
/* @0x29e344 mov r2, r6 */
/* @0x29e348 mov r1, #5 */
/* @0x29e34c mov r0, r5 */
/* @0x29e350 ldr r3, [r3, #0xc] */
/* @0x29e354 blx r3 */
/* @0x29e358 mov r1, r9 */
/* @0x29e35c mov r0, r6 */
/* @0x29e360 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29e364 ldr r3, [r5] */
/* @0x29e368 mov r2, r6 */
/* @0x29e36c mov r1, #5 */
/* @0x29e370 mov r0, r5 */
/* @0x29e374 ldr r3, [r3, #0xc] */
/* @0x29e378 blx r3 */
/* @0x29e37c mov r0, r6 */
/* @0x29e380 mov r1, r9 */
/* @0x29e384 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29e388 cmp r8, #19 */
/* @0x29e38c beq 0x29e428 <_Z13Debug_GetData15eNetworkCommandP9DbgSocketPhi+0x1fc> */
/* @0x29e390 mov r0, r8 */
/* @0x29e394 mov r2, r5 */
/* @0x29e398 mov r1, r4 */
/* @0x29e39c bl 0x29e11c <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_> */
/* @0x29e3a0 ldr r3, [r4] */
/* @0x29e3a4 mov r1, #0 */
/* @0x29e3a8 ldr r5, [r4, #0x1c] */
/* @0x29e3ac mov r0, r4 */
/* @0x29e3b0 mov r2, #4 */
/* @0x29e3b4 mov r6, r1 */
/* @0x29e3b8 ldr r3, [r3, #0x10] */
/* @0x29e3bc blx r3 */
/* @0x29e3c0 vmov s15, r5 */
/* @0x29e3c4 ldr r3, [r4] */
/* @0x29e3c8 mov r2, r7 */
/* @0x29e3cc vcvt.f64.u32 d7, s15 */
/* @0x29e3d0 str r6, [r4, #0x38] */
/* @0x29e3d4 mov r0, r4 */
/* @0x29e3d8 mov r1, #5 */
/* @0x29e3dc vmov r8, r9, d7 */
/* @0x29e3e0 vstr s14, [r4, #44] */
/* @0x29e3e4 str r9, [r4, #0x30] */
/* @0x29e3e8 ldr r3, [r3, #0x8] */
/* @0x29e3ec blx r3 */
/* @0x29e3f0 ldr r3, [r4] */
/* @0x29e3f4 mov r1, r6 */
/* @0x29e3f8 mov r2, r5 */
/* @0x29e3fc mov r0, r4 */
/* @0x29e400 ldr r3, [r3, #0x10] */
/* @0x29e404 blx r3 */
/* @0x29e408 ldr r0, [sp, #0x8] */
/* @0x29e40c mov r2, r5 */
/* @0x29e410 ldr r1, [r4, #0xc] */
/* @0x29e414 bl 0x29d9a8 <_ZN9DbgSocket5WriteEPvj> */
/* @0x29e418 ldr r0, [sp, #0xc] */
/* @0x29e41c add sp, sp, #20 */
/* @0x29e420 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x29e424 b 0xc6a88 <_Z11FreeIBufferi> */
/* @0x29e428 ldr r3, [r5] */
/* @0x29e42c mov r2, r6 */
/* @0x29e430 mov r1, #6 */
/* @0x29e434 mov r0, r5 */
/* @0x29e438 ldr r3, [r3, #0xc] */
/* @0x29e43c blx r3 */
/* @0x29e440 mov r1, r9 */
/* @0x29e444 mov r0, r6 */
/* @0x29e448 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x29e44c ldr r3, [r4] */
/* @0x29e450 str r9, [r4, #0x38] */
/* @0x29e454 mov r1, #5 */
/* @0x29e458 mov r2, r7 */
/* @0x29e45c vmov s13, r0 */
/* @0x29e460 mov r8, r0 */
/* @0x29e464 mov r0, r4 */
/* @0x29e468 vcvt.f64.u32 d7, s13 */
/* @0x29e46c vstr s14, [r4, #44] */
/* @0x29e470 vstr s15, [r4, #48] */
/* @0x29e474 ldr r3, [r3, #0x8] */
/* @0x29e478 blx r3 */
/* @0x29e47c cmp r8, r9 */
/* @0x29e480 ble 0x29e3a0 <_Z13Debug_GetData15eNetworkCommandP9DbgSocketPhi+0x174> */
/* @0x29e484 stm sp, {r7, r8} */
/* @0x29e488 mov r8, r9 */
/* @0x29e48c ldr r12, [r5] */
/* @0x29e490 mov r2, r6 */
/* @0x29e494 mov r1, #6 */
/* @0x29e498 mov r0, r5 */
/* @0x29e49c add r8, r8, #1 */
/* @0x29e4a0 ldr r12, [r12, #0xc] */
/* @0x29e4a4 blx r12 */
/* @0x29e4a8 mov r1, #0 */
/* @0x29e4ac mov r0, r6 */
/* @0x29e4b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x29e4b4 ldr r12, [r4] */
/* @0x29e4b8 mov r1, #5 */
/* @0x29e4bc ldr r2, [sp] */
/* @0x29e4c0 str r9, [r4, #0x38] */
/* @0x29e4c4 vmov s15, r0 */
/* @0x29e4c8 mov r7, r0 */
/* @0x29e4cc mov r0, r4 */
/* @0x29e4d0 vcvt.f64.u32 d7, s15 */
/* @0x29e4d4 vmov r10, r11, d7 */
/* @0x29e4d8 vstr s14, [r4, #44] */
/* @0x29e4dc str r11, [r4, #0x30] */
/* @0x29e4e0 ldr r12, [r12, #0x8] */
/* @0x29e4e4 blx r12 */
/* @0x29e4e8 mov r0, r7 */
/* @0x29e4ec mov r1, r4 */
/* @0x29e4f0 mov r2, r5 */
/* @0x29e4f4 bl 0x29e11c <_Z17Debug_ReadCommand15eNetworkCommandP15Buffer_StandardS1_> */
/* @0x29e4f8 ldr r3, [sp, #0x4] */
/* @0x29e4fc cmp r8, r3 */
/* @0x29e500 bne 0x29e48c <_Z13Debug_GetData15eNetworkCommandP9DbgSocketPhi+0x260> */
/* @0x29e504 ldr r7, [sp] */
/* @0x29e508 b 0x29e3a0 <_Z13Debug_GetData15eNetworkCommandP9DbgSocketPhi+0x174> */

/* ── FUNC 0x29e50c · ProcessDebugPacket(DbgSocket*, Buffer_Standard*, SNetwork_Packet*, int) · size=280 · insn=70 */
/* @0x29e50c push {r4, r5, r6, lr} */
/* @0x29e510 mov r5, r0 */
/* @0x29e514 ldr r4, [r2, #0xc] */
/* @0x29e518 ldr r0, [r2, #0x10] */
/* @0x29e51c sub r12, r4, #1 */
/* @0x29e520 cmp r12, #20 */
/* @0x29e524 addls pc, pc, r12, lsl #2 */
/* @0x29e528 b 0x29e5f4 <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0xe8> */
/* @0x29e52c b 0x29e58c <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0x80> */
/* @0x29e530 b 0x29e59c <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0x90> */
/* @0x29e534 b 0x29e5a8 <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0x9c> */
/* @0x29e538 b 0x29e5b4 <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0xa8> */
/* @0x29e53c b 0x29e5f4 <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0xe8> */
/* @0x29e540 b 0x29e5c0 <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0xb4> */
/* @0x29e544 b 0x29e58c <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0x80> */
/* @0x29e548 b 0x29e58c <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0x80> */
/* @0x29e54c b 0x29e5c8 <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0xbc> */
/* @0x29e550 b 0x29e58c <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0x80> */
/* @0x29e554 b 0x29e58c <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0x80> */
/* @0x29e558 b 0x29e58c <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0x80> */
/* @0x29e55c b 0x29e58c <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0x80> */
/* @0x29e560 b 0x29e5d8 <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0xcc> */
/* @0x29e564 b 0x29e5e0 <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0xd4> */
/* @0x29e568 b 0x29e58c <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0x80> */
/* @0x29e56c b 0x29e58c <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0x80> */
/* @0x29e570 b 0x29e58c <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0x80> */
/* @0x29e574 b 0x29e58c <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0x80> */
/* @0x29e578 b 0x29e5ec <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0xe0> */
/* @0x29e57c b 0x29e580 <_Z18ProcessDebugPacketP9DbgSocketP15Buffer_StandardP15SNetwork_Packeti+0x74> */
/* @0x29e580 mov r0, r5 */
/* @0x29e584 pop {r4, r5, r6, lr} */
/* @0x29e588 b 0x29fe4c <_Z17Debug_SendYYDebugP9DbgSocketP15Buffer_Standard> */
/* @0x29e58c mov r0, r4 */
/* @0x29e590 mov r1, r5 */
/* @0x29e594 pop {r4, r5, r6, lr} */
/* @0x29e598 b 0x29e22c <_Z13Debug_GetData15eNetworkCommandP9DbgSocketPhi> */
/* @0x29e59c mov r0, r5 */
/* @0x29e5a0 pop {r4, r5, r6, lr} */
/* @0x29e5a4 b 0x29fb30 <_Z23Debug_SendGameStructureP9DbgSocketP15Buffer_Standard> */
/* @0x29e5a8 mov r0, #1 */
/* @0x29e5ac pop {r4, r5, r6, lr} */
/* @0x29e5b0 b 0x29c648 <_Z21Debug_StartStopTargetb> */
/* @0x29e5b4 mov r0, #0 */
/* @0x29e5b8 pop {r4, r5, r6, lr} */
/* @0x29e5bc b 0x29c648 <_Z21Debug_StartStopTargetb> */
/* @0x29e5c0 pop {r4, r5, r6, lr} */
/* @0x29e5c4 b 0x29c780 <_Z18Debug_DoSingleStepi> */
/* @0x29e5c8 mov r0, r2 */
/* @0x29e5cc mov r1, r3 */
/* @0x29e5d0 pop {r4, r5, r6, lr} */
/* @0x29e5d4 b 0x29c888 <_Z20Debug_SetBreakpointsPhi> */
/* @0x29e5d8 pop {r4, r5, r6, lr} */
/* @0x29e5dc b 0x29c6bc <_Z19Debug_RestartTargetv> */
/* @0x29e5e0 mov r0, r5 */
/* @0x29e5e4 pop {r4, r5, r6, lr} */
/* @0x29e5e8 b 0x29d9bc <_Z25Debug_GetSelectedInstanceP9DbgSocket> */
/* @0x29e5ec pop {r4, r5, r6, lr} */
/* @0x29e5f0 b 0x29c6dc <_Z18Debug_QuitDebuggerv> */
/* @0x29e5f4 ldr r3, [pc, #0x20] */
/* @0x29e5f8 mov r2, r4 */
/* @0x29e5fc ldr r1, [pc, #0x1c] */
/* @0x29e600 ldr r3, [pc, r3] */
/* @0x29e604 add r1, pc, r1 */
/* @0x29e608 ldr r0, [r3] */
/* @0x29e60c ldr r3, [r0] */
/* @0x29e610 ldr r3, [r3, #0xc] */
/* @0x29e614 blx r3 */
/* @0x29e618 pop {r4, r5, r6, pc} */
/* @0x29e61c andseq pc, r4, r0, asr #6 */
/* @0x29e620 muleq r11, r0, r5 */

/* ── FUNC 0x29e624 · WriteString(Buffer_Standard*, char const*) · size=120 · insn=30 */
/* @0x29e624 push {r3, r4, r5, r6, r7, lr} */
/* @0x29e628 subs r7, r1, #0 */
/* @0x29e62c mov r6, r0 */
/* @0x29e630 beq 0x29e684 <_Z11WriteStringP15Buffer_StandardPKc+0x60> */
/* @0x29e634 mov r0, r7 */
/* @0x29e638 bl 0xb6538 <strlen@plt> */
/* @0x29e63c add r0, r0, #1 */
/* @0x29e640 vmov s15, r0 */
/* @0x29e644 vcvt.f64.u32 d6, s15 */
/* @0x29e648 mov r2, r6 */
/* @0x29e64c ldr r3, [r2], #44 */
/* @0x29e650 mov r1, #0 */
/* @0x29e654 mov r0, r6 */
/* @0x29e658 str r1, [r6, #0x38] */
/* @0x29e65c mov r1, #5 */
/* @0x29e660 vmov r4, r5, d6 */
/* @0x29e664 vstr s12, [r6, #44] */
/* @0x29e668 str r5, [r6, #0x30] */
/* @0x29e66c ldr r3, [r3, #0x8] */
/* @0x29e670 blx r3 */
/* @0x29e674 mov r0, r6 */
/* @0x29e678 mov r1, r7 */
/* @0x29e67c pop {r3, r4, r5, r6, r7, lr} */
/* @0x29e680 b 0xcddb8 <_ZN7IBuffer5WriteEPKc> */
/* @0x29e684 ldr r7, [pc, #0xc] */
/* @0x29e688 vldr s15, [pc, #4] */
/* @0x29e68c add r7, pc, r7 */
/* @0x29e690 b 0x29e644 <_Z11WriteStringP15Buffer_StandardPKc+0x20> */
/* @0x29e694 andeq r0, r0, r7 */
/* @0x29e698 andeq r11, r11, r12, lsr r5 */

/* ── FUNC 0x29e69c · ReadString(Buffer_Standard*) · size=148 · insn=37 */
/* @0x29e69c ldr r3, [r0] */
/* @0x29e6a0 mov r1, #5 */
/* @0x29e6a4 push {r4, r5, r6, r7, r8, lr} */
/* @0x29e6a8 add r5, r0, #44 */
/* @0x29e6ac ldr r3, [r3, #0xc] */
/* @0x29e6b0 mov r6, r0 */
/* @0x29e6b4 mov r2, r5 */
/* @0x29e6b8 blx r3 */
/* @0x29e6bc mov r1, #0 */
/* @0x29e6c0 mov r0, r5 */
/* @0x29e6c4 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x29e6c8 ldr r1, [pc, #0x5c] */
/* @0x29e6cc mov r2, #85 */
/* @0x29e6d0 mov r3, #1 */
/* @0x29e6d4 add r1, pc, r1 */
/* @0x29e6d8 mov r8, r0 */
/* @0x29e6dc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x29e6e0 cmp r8, #0 */
/* @0x29e6e4 mov r7, r0 */
/* @0x29e6e8 ble 0x29e724 <_Z10ReadStringP15Buffer_Standard+0x88> */
/* @0x29e6ec mov r4, #0 */
/* @0x29e6f0 ldr r3, [r6] */
/* @0x29e6f4 mov r1, #1 */
/* @0x29e6f8 mov r2, r5 */
/* @0x29e6fc mov r0, r6 */
/* @0x29e700 ldr r3, [r3, #0xc] */
/* @0x29e704 blx r3 */
/* @0x29e708 mov r0, r5 */
/* @0x29e70c mov r1, #0 */
/* @0x29e710 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x29e714 strb r0, [r7, r4] */
/* @0x29e718 add r4, r4, #1 */
/* @0x29e71c cmp r8, r4 */
/* @0x29e720 bne 0x29e6f0 <_Z10ReadStringP15Buffer_Standard+0x54> */
/* @0x29e724 mov r0, r7 */
/* @0x29e728 pop {r4, r5, r6, r7, r8, pc} */
/* @0x29e72c strdeq r11, r12, [r11], -r12 */

/* ── FUNC 0x29e730 · WriteData(Buffer_Standard*, unsigned char const*, int) · size=220 · insn=55 */
/* @0x29e730 vmov s15, r2 */
/* @0x29e734 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x29e738 vcvt.f64.u32 d7, s15 */
/* @0x29e73c ldr r3, [r0] */
/* @0x29e740 add r8, r0, #44 */
/* @0x29e744 mov r6, r0 */
/* @0x29e748 mov r9, r2 */
/* @0x29e74c mov r7, r1 */
/* @0x29e750 mov r10, #0 */
/* @0x29e754 mov r1, #5 */
/* @0x29e758 str r10, [r0, #0x38] */
/* @0x29e75c mov r2, r8 */
/* @0x29e760 vmov r4, r5, d7 */
/* @0x29e764 vstr s14, [r6, #44] */
/* @0x29e768 str r5, [r6, #0x30] */
/* @0x29e76c ldr r3, [r3, #0x8] */
/* @0x29e770 blx r3 */
/* @0x29e774 cmp r9, r10 */
/* @0x29e778 addgt r11, r7, r9 */
/* @0x29e77c ble 0x29e7bc <_Z9WriteDataP15Buffer_StandardPKhi+0x8c> */
/* @0x29e780 ldrb r4, [r7], #1 */
/* @0x29e784 mov r0, r6 */
/* @0x29e788 ldr r3, [r6] */
/* @0x29e78c mov r1, #1 */
/* @0x29e790 str r10, [r6, #0x38] */
/* @0x29e794 mov r2, r8 */
/* @0x29e798 vmov s15, r4 */
/* @0x29e79c vcvt.f64.u32 d7, s15 */
/* @0x29e7a0 vmov r4, r5, d7 */
/* @0x29e7a4 vstr s14, [r6, #44] */
/* @0x29e7a8 str r5, [r6, #0x30] */
/* @0x29e7ac ldr r3, [r3, #0x8] */
/* @0x29e7b0 blx r3 */
/* @0x29e7b4 cmp r7, r11 */
/* @0x29e7b8 bne 0x29e780 <_Z9WriteDataP15Buffer_StandardPKhi+0x50> */
/* @0x29e7bc add r3, r9, #3 */
/* @0x29e7c0 bic r3, r3, #3 */
/* @0x29e7c4 rsb r9, r9, r3 */
/* @0x29e7c8 cmp r9, #0 */
/* @0x29e7cc pople {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x29e7d0 mov r4, #0 */
/* @0x29e7d4 mov r5, r4 */
/* @0x29e7d8 ldr r3, [r6] */
/* @0x29e7dc add r4, r4, #1 */
/* @0x29e7e0 str r5, [r6, #0x2c] */
/* @0x29e7e4 mov r0, r6 */
/* @0x29e7e8 str r5, [r6, #0x30] */
/* @0x29e7ec mov r1, #1 */
/* @0x29e7f0 str r5, [r6, #0x38] */
/* @0x29e7f4 mov r2, r8 */
/* @0x29e7f8 ldr r3, [r3, #0x8] */
/* @0x29e7fc blx r3 */
/* @0x29e800 cmp r4, r9 */
/* @0x29e804 bne 0x29e7d8 <_Z9WriteDataP15Buffer_StandardPKhi+0xa8> */
/* @0x29e808 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x29e80c · TraverseObjects(Buffer_Standard*) · size=1096 · insn=274 */
/* @0x29e80c ldr r12, [r0] */
/* @0x29e810 mov r3, #0 */
/* @0x29e814 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x29e818 sub sp, sp, #36 */
/* @0x29e81c str r3, [r0, #0x2c] */
/* @0x29e820 add r8, r0, #44 */
/* @0x29e824 str r3, [r0, #0x30] */
/* @0x29e828 mov r1, #5 */
/* @0x29e82c ldr r12, [r12, #0x8] */
/* @0x29e830 mov r2, r8 */
/* @0x29e834 str r3, [sp, #0x14] */
/* @0x29e838 mov r6, r0 */
/* @0x29e83c str r3, [r0, #0x38] */
/* @0x29e840 ldr r3, [r0, #0x1c] */
/* @0x29e844 str r3, [sp, #0x1c] */
/* @0x29e848 blx r12 */
/* @0x29e84c ldr r3, [pc, #0x3fc] */
/* @0x29e850 ldr r3, [pc, r3] */
/* @0x29e854 ldr r3, [r3] */
/* @0x29e858 str r3, [sp, #0x18] */
/* @0x29e85c mov r12, r3 */
/* @0x29e860 ldr r2, [r3] */
/* @0x29e864 ldr r3, [sp, #0x14] */
/* @0x29e868 b 0x29e87c <_Z15TraverseObjectsP15Buffer_Standard+0x70> */
/* @0x29e86c ldr r0, [r12, #0x4] */
/* @0x29e870 add r3, r3, #1 */
/* @0x29e874 cmp r3, r0 */
/* @0x29e878 bgt 0x29ec44 <_Z15TraverseObjectsP15Buffer_Standard+0x438> */
/* @0x29e87c ldr r1, [r2, r3, lsl #3] */
/* @0x29e880 cmp r1, #0 */
/* @0x29e884 beq 0x29e86c <_Z15TraverseObjectsP15Buffer_Standard+0x60> */
/* @0x29e888 ldr r4, [r1, #0xc] */
/* @0x29e88c str r1, [sp, #0x8] */
/* @0x29e890 cmp r4, #0 */
/* @0x29e894 str r3, [sp, #0x14] */
/* @0x29e898 streq r4, [sp, #0xc] */
/* @0x29e89c beq 0x29eb7c <_Z15TraverseObjectsP15Buffer_Standard+0x370> */
/* @0x29e8a0 mov r3, #0 */
/* @0x29e8a4 str r3, [sp, #0xc] */
/* @0x29e8a8 mov r9, r3 */
/* @0x29e8ac ldr r10, [r4, #0x18] */
/* @0x29e8b0 mov r1, #5 */
/* @0x29e8b4 ldr r5, [r6] */
/* @0x29e8b8 mov r2, r8 */
/* @0x29e8bc ldr r3, [sp, #0xc] */
/* @0x29e8c0 mov r0, r6 */
/* @0x29e8c4 vmov s13, r10 */
/* @0x29e8c8 str r9, [r6, #0x38] */
/* @0x29e8cc add r3, r3, #1 */
/* @0x29e8d0 str r3, [sp, #0xc] */
/* @0x29e8d4 vcvt.f64.u32 d7, s13 */
/* @0x29e8d8 mov r3, #15 */
/* @0x29e8dc str r3, [sp, #0x10] */
/* @0x29e8e0 mov r10, r4 */
/* @0x29e8e4 vstr s14, [r6, #44] */
/* @0x29e8e8 vstr s15, [r6, #48] */
/* @0x29e8ec ldr r12, [r5, #0x8] */
/* @0x29e8f0 blx r12 */
/* @0x29e8f4 ldr r3, [r4] */
/* @0x29e8f8 ldr r5, [r6] */
/* @0x29e8fc mov r1, #5 */
/* @0x29e900 mov r2, r8 */
/* @0x29e904 str r9, [r6, #0x38] */
/* @0x29e908 vmov s13, r3 */
/* @0x29e90c mov r0, r6 */
/* @0x29e910 vcvt.f64.u32 d7, s13 */
/* @0x29e914 vstr s14, [r6, #44] */
/* @0x29e918 vstr s15, [r6, #48] */
/* @0x29e91c ldr r12, [r5, #0x8] */
/* @0x29e920 blx r12 */
/* @0x29e924 ldr r3, [r4, #0x4] */
/* @0x29e928 ldr r5, [r6] */
/* @0x29e92c mov r1, #5 */
/* @0x29e930 mov r2, r8 */
/* @0x29e934 str r9, [r6, #0x38] */
/* @0x29e938 vmov s13, r3 */
/* @0x29e93c mov r0, r6 */
/* @0x29e940 vcvt.f64.u32 d7, s13 */
/* @0x29e944 vstr s14, [r6, #44] */
/* @0x29e948 vstr s15, [r6, #48] */
/* @0x29e94c ldr r12, [r5, #0x8] */
/* @0x29e950 blx r12 */
/* @0x29e954 ldr r3, [r4, #0x10] */
/* @0x29e958 ldr r5, [r6] */
/* @0x29e95c mov r1, #5 */
/* @0x29e960 mov r2, r8 */
/* @0x29e964 str r9, [r6, #0x38] */
/* @0x29e968 vmov s13, r3 */
/* @0x29e96c mov r0, r6 */
/* @0x29e970 vcvt.f64.u32 d7, s13 */
/* @0x29e974 vstr s14, [r6, #44] */
/* @0x29e978 vstr s15, [r6, #48] */
/* @0x29e97c ldr r12, [r5, #0x8] */
/* @0x29e980 blx r12 */
/* @0x29e984 ldr r3, [r4, #0x8] */
/* @0x29e988 ldr r5, [r6] */
/* @0x29e98c mov r1, #5 */
/* @0x29e990 mov r2, r8 */
/* @0x29e994 str r9, [r6, #0x38] */
/* @0x29e998 vmov s13, r3 */
/* @0x29e99c mov r0, r6 */
/* @0x29e9a0 vcvt.f64.u32 d7, s13 */
/* @0x29e9a4 vstr s14, [r6, #44] */
/* @0x29e9a8 vstr s15, [r6, #48] */
/* @0x29e9ac ldr r12, [r5, #0x8] */
/* @0x29e9b0 blx r12 */
/* @0x29e9b4 ldr r3, [r4, #0xc] */
/* @0x29e9b8 ldr r5, [r6] */
/* @0x29e9bc mov r1, #5 */
/* @0x29e9c0 str r9, [r6, #0x38] */
/* @0x29e9c4 mov r0, r6 */
/* @0x29e9c8 vmov s13, r3 */
/* @0x29e9cc mov r2, r8 */
/* @0x29e9d0 vcvt.f64.u32 d7, s13 */
/* @0x29e9d4 vstr s14, [r6, #44] */
/* @0x29e9d8 vstr s15, [r6, #48] */
/* @0x29e9dc ldr r12, [r5, #0x8] */
/* @0x29e9e0 blx r12 */
/* @0x29e9e4 mov r0, r6 */
/* @0x29e9e8 ldr r1, [r4, #0x14] */
/* @0x29e9ec bl 0x29e624 <_Z11WriteStringP15Buffer_StandardPKc> */
/* @0x29e9f0 ldr r3, [r10, #0x4c] */
/* @0x29e9f4 cmp r3, #0 */
/* @0x29e9f8 str r3, [sp, #0x4] */
/* @0x29e9fc ble 0x29eb24 <_Z15TraverseObjectsP15Buffer_Standard+0x318> */
/* @0x29ea00 ldr lr, [sp, #0x4] */
/* @0x29ea04 mov r4, #0 */
/* @0x29ea08 ldr r3, [r10, #0x50] */
/* @0x29ea0c add r1, r3, lr, lsl #2 */
/* @0x29ea10 ldr r2, [r3], #4 */
/* @0x29ea14 cmp r2, #0 */
/* @0x29ea18 addne r4, r4, #1 */
/* @0x29ea1c cmp r3, r1 */
/* @0x29ea20 bne 0x29ea10 <_Z15TraverseObjectsP15Buffer_Standard+0x204> */
/* @0x29ea24 vmov s15, r4 */
/* @0x29ea28 ldr r3, [r6] */
/* @0x29ea2c str r9, [r6, #0x38] */
/* @0x29ea30 mov r0, r6 */
/* @0x29ea34 vcvt.f64.u32 d7, s15 */
/* @0x29ea38 mov r1, #5 */
/* @0x29ea3c mov r2, r8 */
/* @0x29ea40 mov r11, #0 */
/* @0x29ea44 vmov r4, r5, d7 */
/* @0x29ea48 vstr s14, [r6, #44] */
/* @0x29ea4c str r5, [r6, #0x30] */
/* @0x29ea50 ldr r3, [r3, #0x8] */
/* @0x29ea54 blx r3 */
/* @0x29ea58 ldr r3, [r10, #0x50] */
/* @0x29ea5c mov r1, #5 */
/* @0x29ea60 mov r2, r8 */
/* @0x29ea64 mov r0, r6 */
/* @0x29ea68 ldr r3, [r3, r11, lsl #2] */
/* @0x29ea6c cmp r3, #0 */
/* @0x29ea70 beq 0x29eb10 <_Z15TraverseObjectsP15Buffer_Standard+0x304> */
/* @0x29ea74 vmov s15, r11 */
/* @0x29ea78 ldr r12, [r6] */
/* @0x29ea7c ldr r7, [r3, #0x4] */
/* @0x29ea80 vcvt.f64.s32 d7, s15 */
/* @0x29ea84 str r9, [r6, #0x38] */
/* @0x29ea88 vmov r4, r5, d7 */
/* @0x29ea8c vstr s14, [r6, #44] */
/* @0x29ea90 str r5, [r6, #0x30] */
/* @0x29ea94 ldr r3, [r12, #0x8] */
/* @0x29ea98 blx r3 */
/* @0x29ea9c ldr r4, [r7, #0x60] */
/* @0x29eaa0 ldr r3, [r6] */
/* @0x29eaa4 mov r1, #5 */
/* @0x29eaa8 mov r2, r8 */
/* @0x29eaac mov r0, r6 */
/* @0x29eab0 vmov s15, r4 */
/* @0x29eab4 str r9, [r6, #0x38] */
/* @0x29eab8 vcvt.f64.u32 d7, s15 */
/* @0x29eabc vmov r4, r5, d7 */
/* @0x29eac0 vstr s14, [r6, #44] */
/* @0x29eac4 str r5, [r6, #0x30] */
/* @0x29eac8 ldr r3, [r3, #0x8] */
/* @0x29eacc blx r3 */
/* @0x29ead0 ldr r3, [r7, #0x50] */
/* @0x29ead4 ldr r12, [r6] */
/* @0x29ead8 mov r1, #12 */
/* @0x29eadc mov lr, #10 */
/* @0x29eae0 mov r0, r6 */
/* @0x29eae4 ldr r3, [r3, #0x10] */
/* @0x29eae8 mov r2, r8 */
/* @0x29eaec str lr, [r6, #0x38] */
/* @0x29eaf0 asr r5, r3, #31 */
/* @0x29eaf4 str r3, [r6, #0x2c] */
/* @0x29eaf8 str r5, [r6, #0x30] */
/* @0x29eafc ldr r3, [r12, #0x8] */
/* @0x29eb00 blx r3 */
/* @0x29eb04 mov r0, r6 */
/* @0x29eb08 ldr r1, [r7, #0x5c] */
/* @0x29eb0c bl 0x29e624 <_Z11WriteStringP15Buffer_StandardPKc> */
/* @0x29eb10 ldr r3, [sp, #0x4] */
/* @0x29eb14 add r11, r11, #1 */
/* @0x29eb18 cmp r11, r3 */
/* @0x29eb1c bne 0x29ea58 <_Z15TraverseObjectsP15Buffer_Standard+0x24c> */
/* @0x29eb20 b 0x29eb48 <_Z15TraverseObjectsP15Buffer_Standard+0x33c> */
/* @0x29eb24 ldr r3, [r6] */
/* @0x29eb28 mov r0, r6 */
/* @0x29eb2c str r9, [r6, #0x2c] */
/* @0x29eb30 mov r1, #5 */
/* @0x29eb34 str r9, [r6, #0x30] */
/* @0x29eb38 mov r2, r8 */
/* @0x29eb3c str r9, [r6, #0x38] */
/* @0x29eb40 ldr r3, [r3, #0x8] */
/* @0x29eb44 blx r3 */
/* @0x29eb48 ldr r3, [sp, #0x10] */
/* @0x29eb4c add r10, r10, #8 */
/* @0x29eb50 subs r3, r3, #1 */
/* @0x29eb54 str r3, [sp, #0x10] */
/* @0x29eb58 bne 0x29e9f0 <_Z15TraverseObjectsP15Buffer_Standard+0x1e4> */
/* @0x29eb5c ldr r3, [sp, #0x8] */
/* @0x29eb60 ldr r3, [r3, #0x4] */
/* @0x29eb64 cmp r3, #0 */
/* @0x29eb68 str r3, [sp, #0x8] */
/* @0x29eb6c beq 0x29ebec <_Z15TraverseObjectsP15Buffer_Standard+0x3e0> */
/* @0x29eb70 ldr r4, [r3, #0xc] */
/* @0x29eb74 cmp r4, #0 */
/* @0x29eb78 bne 0x29e8ac <_Z15TraverseObjectsP15Buffer_Standard+0xa0> */
/* @0x29eb7c ldr r3, [r6] */
/* @0x29eb80 mov r1, #0 */
/* @0x29eb84 ldr r2, [sp, #0x1c] */
/* @0x29eb88 mov r0, r6 */
/* @0x29eb8c mov r7, r1 */
/* @0x29eb90 ldr r9, [r6, #0x1c] */
/* @0x29eb94 ldr r3, [r3, #0x10] */
/* @0x29eb98 blx r3 */
/* @0x29eb9c vldr s15, [sp, #12] */
/* @0x29eba0 vcvt.f64.u32 d7, s15 */
/* @0x29eba4 ldr r3, [r6] */
/* @0x29eba8 mov r2, r8 */
/* @0x29ebac str r7, [r6, #0x38] */
/* @0x29ebb0 mov r0, r6 */
/* @0x29ebb4 mov r1, #5 */
/* @0x29ebb8 vmov r4, r5, d7 */
/* @0x29ebbc vstr s14, [r6, #44] */
/* @0x29ebc0 str r5, [r6, #0x30] */
/* @0x29ebc4 ldr r3, [r3, #0x8] */
/* @0x29ebc8 blx r3 */
/* @0x29ebcc ldr r3, [r6] */
/* @0x29ebd0 mov r1, r7 */
/* @0x29ebd4 mov r2, r9 */
/* @0x29ebd8 mov r0, r6 */
/* @0x29ebdc ldr r3, [r3, #0x10] */
/* @0x29ebe0 blx r3 */
/* @0x29ebe4 add sp, sp, #36 */
/* @0x29ebe8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x29ebec ldr r3, [sp, #0x18] */
/* @0x29ebf0 ldr lr, [sp, #0x14] */
/* @0x29ebf4 ldr r1, [r3, #0x4] */
/* @0x29ebf8 add r3, lr, #1 */
/* @0x29ebfc cmp r3, r1 */
/* @0x29ec00 bgt 0x29eb7c <_Z15TraverseObjectsP15Buffer_Standard+0x370> */
/* @0x29ec04 ldr r0, [sp, #0x18] */
/* @0x29ec08 ldr r2, [r0] */
/* @0x29ec0c add r2, r2, lr, lsl #3 */
/* @0x29ec10 b 0x29ec1c <_Z15TraverseObjectsP15Buffer_Standard+0x410> */
/* @0x29ec14 cmp r3, r1 */
/* @0x29ec18 bgt 0x29eb7c <_Z15TraverseObjectsP15Buffer_Standard+0x370> */
/* @0x29ec1c ldr r0, [r2, #0x8] */
/* @0x29ec20 mov r12, r3 */
/* @0x29ec24 add r2, r2, #8 */
/* @0x29ec28 add r3, r3, #1 */
/* @0x29ec2c cmp r0, #0 */
/* @0x29ec30 beq 0x29ec14 <_Z15TraverseObjectsP15Buffer_Standard+0x408> */
/* @0x29ec34 str r0, [sp, #0x8] */
/* @0x29ec38 str r12, [sp, #0x14] */
/* @0x29ec3c ldr r4, [r0, #0xc] */
/* @0x29ec40 b 0x29eb74 <_Z15TraverseObjectsP15Buffer_Standard+0x368> */
/* @0x29ec44 str r1, [sp, #0x8] */
/* @0x29ec48 str r1, [sp, #0xc] */
/* @0x29ec4c b 0x29eb7c <_Z15TraverseObjectsP15Buffer_Standard+0x370> */
/* @0x29ec50 andseq pc, r4, r12, ror #7 */

/* ── FUNC 0x29ec54 · AddScripts(Buffer_Standard*) · size=412 · insn=103 */
/* @0x29ec54 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x29ec58 add r7, r0, #44 */
/* @0x29ec5c ldr r8, [pc, #0x188] */
/* @0x29ec60 sub sp, sp, #12 */
/* @0x29ec64 ldr r3, [r0] */
/* @0x29ec68 mov r6, #0 */
/* @0x29ec6c ldr r8, [pc, r8] */
/* @0x29ec70 ldr r4, [r0, #0x1c] */
/* @0x29ec74 str r6, [r0, #0x2c] */
/* @0x29ec78 mov r2, r7 */
/* @0x29ec7c ldr r9, [r8] */
/* @0x29ec80 mov r1, #5 */
/* @0x29ec84 str r6, [r0, #0x30] */
/* @0x29ec88 mov r10, r0 */
/* @0x29ec8c str r6, [r0, #0x38] */
/* @0x29ec90 ldr r3, [r3, #0x8] */
/* @0x29ec94 str r4, [sp, #0x4] */
/* @0x29ec98 blx r3 */
/* @0x29ec9c cmp r9, r6 */
/* @0x29eca0 ble 0x29ede4 <_Z10AddScriptsP15Buffer_Standard+0x190> */
/* @0x29eca4 ldr r2, [r8, #0x4] */
/* @0x29eca8 mov r12, #0 */
/* @0x29ecac ldr r3, [r10] */
/* @0x29ecb0 mov r1, #5 */
/* @0x29ecb4 mov r0, r10 */
/* @0x29ecb8 ldr r11, [r2, r6, lsl #2] */
/* @0x29ecbc mov r2, r7 */
/* @0x29ecc0 add r6, r6, #1 */
/* @0x29ecc4 ldr r4, [r11, #0x10] */
/* @0x29ecc8 str r12, [r10, #0x38] */
/* @0x29eccc vmov s15, r4 */
/* @0x29ecd0 vcvt.f64.u32 d7, s15 */
/* @0x29ecd4 vmov r4, r5, d7 */
/* @0x29ecd8 vstr s14, [r10, #44] */
/* @0x29ecdc str r5, [r10, #0x30] */
/* @0x29ece0 ldr r3, [r3, #0x8] */
/* @0x29ece4 blx r3 */
/* @0x29ece8 ldr r12, [r11, #0x10] */
/* @0x29ecec mov r1, #12 */
/* @0x29ecf0 mov r2, r7 */
/* @0x29ecf4 cmp r12, #0 */
/* @0x29ecf8 mov r0, r10 */
/* @0x29ecfc ldr r3, [r11, #0x8] */
/* @0x29ed00 blt 0x29ed60 <_Z10AddScriptsP15Buffer_Standard+0x10c> */
/* @0x29ed04 ldr lr, [r3, #0x50] */
/* @0x29ed08 mov r4, #10 */
/* @0x29ed0c ldr r3, [r3, #0x6c] */
/* @0x29ed10 ldr r12, [r10] */
/* @0x29ed14 ldr lr, [lr, #0x10] */
/* @0x29ed18 str r4, [r10, #0x38] */
/* @0x29ed1c adds r4, lr, r3 */
/* @0x29ed20 asr r5, lr, #31 */
/* @0x29ed24 str lr, [r10, #0x2c] */
/* @0x29ed28 str r5, [r10, #0x30] */
/* @0x29ed2c adc r5, r5, r3, asr #31 */
/* @0x29ed30 ldr r3, [r12, #0x8] */
/* @0x29ed34 blx r3 */
/* @0x29ed38 ldr r3, [r10] */
/* @0x29ed3c str r4, [r10, #0x2c] */
/* @0x29ed40 mov r12, #10 */
/* @0x29ed44 str r5, [r10, #0x30] */
/* @0x29ed48 mov r0, r10 */
/* @0x29ed4c mov r1, #12 */
/* @0x29ed50 str r12, [r10, #0x38] */
/* @0x29ed54 mov r2, r7 */
/* @0x29ed58 ldr r3, [r3, #0x8] */
/* @0x29ed5c blx r3 */
/* @0x29ed60 ldr r1, [r11, #0x14] */
/* @0x29ed64 mov r0, r10 */
/* @0x29ed68 bl 0x29e624 <_Z11WriteStringP15Buffer_StandardPKc> */
/* @0x29ed6c cmp r6, r9 */
/* @0x29ed70 bne 0x29eca4 <_Z10AddScriptsP15Buffer_Standard+0x50> */
/* @0x29ed74 ldr r3, [r10] */
/* @0x29ed78 mov r1, #0 */
/* @0x29ed7c ldr r2, [sp, #0x4] */
/* @0x29ed80 mov r0, r10 */
/* @0x29ed84 mov r6, r1 */
/* @0x29ed88 ldr r8, [r10, #0x1c] */
/* @0x29ed8c ldr r3, [r3, #0x10] */
/* @0x29ed90 blx r3 */
/* @0x29ed94 vmov s15, r9 */
/* @0x29ed98 ldr r3, [r10] */
/* @0x29ed9c mov r2, r7 */
/* @0x29eda0 vcvt.f64.s32 d7, s15 */
/* @0x29eda4 str r6, [r10, #0x38] */
/* @0x29eda8 mov r0, r10 */
/* @0x29edac mov r1, #5 */
/* @0x29edb0 vmov r4, r5, d7 */
/* @0x29edb4 vstr s14, [r10, #44] */
/* @0x29edb8 str r5, [r10, #0x30] */
/* @0x29edbc ldr r3, [r3, #0x8] */
/* @0x29edc0 blx r3 */
/* @0x29edc4 ldr r3, [r10] */
/* @0x29edc8 mov r1, r6 */
/* @0x29edcc mov r2, r8 */
/* @0x29edd0 mov r0, r10 */
/* @0x29edd4 ldr r3, [r3, #0x10] */
/* @0x29edd8 blx r3 */
/* @0x29eddc add sp, sp, #12 */
/* @0x29ede0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x29ede4 mov r9, r6 */
/* @0x29ede8 b 0x29ed74 <_Z10AddScriptsP15Buffer_Standard+0x120> */
/* @0x29edec ldrheq r2, [r5], -r12 */

/* ── FUNC 0x29edf0 · AddCreationCode(Buffer_Standard*) · size=968 · insn=242 */
/* @0x29edf0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x29edf4 sub sp, sp, #36 */
/* @0x29edf8 mov r4, r0 */
/* @0x29edfc bl 0x1b523c <_Z11Room_Numberv> */
/* @0x29ee00 ldr r3, [r4] */
/* @0x29ee04 add r11, r4, #44 */
/* @0x29ee08 mov r5, #0 */
/* @0x29ee0c mov r1, #5 */
/* @0x29ee10 str r5, [r4, #0x38] */
/* @0x29ee14 mov r2, r11 */
/* @0x29ee18 ldr r9, [pc, #0x384] */
/* @0x29ee1c add r9, pc, r9 */
/* @0x29ee20 str r0, [sp, #0x14] */
/* @0x29ee24 mov r0, r4 */
/* @0x29ee28 vldr s15, [sp, #20] */
/* @0x29ee2c vcvt.f64.u32 d7, s15 */
/* @0x29ee30 vmov r6, r7, d7 */
/* @0x29ee34 vstr s14, [r4, #44] */
/* @0x29ee38 str r7, [r4, #0x30] */
/* @0x29ee3c ldr r3, [r3, #0x8] */
/* @0x29ee40 blx r3 */
/* @0x29ee44 ldr r3, [sp, #0x14] */
/* @0x29ee48 cmp r3, r5 */
/* @0x29ee4c ble 0x29f164 <_Z15AddCreationCodeP15Buffer_Standard+0x374> */
/* @0x29ee50 mov r8, r5 */
/* @0x29ee54 mov r12, r5 */
/* @0x29ee58 movw r3, #0xffff */
/* @0x29ee5c movt r12, #0xffe0 */
/* @0x29ee60 movt r3, #0x41ef */
/* @0x29ee64 str r5, [sp, #0x4] */
/* @0x29ee68 str r12, [sp, #0x18] */
/* @0x29ee6c str r3, [sp, #0x1c] */
/* @0x29ee70 str r5, [sp, #0x8] */
/* @0x29ee74 ldr r0, [sp, #0x4] */
/* @0x29ee78 bl 0x1b52c4 <_Z9Room_Datai> */
/* @0x29ee7c ldr r6, [r0, #0xac] */
/* @0x29ee80 mov r5, r0 */
/* @0x29ee84 ldr r1, [r6] */
/* @0x29ee88 cmp r1, #0 */
/* @0x29ee8c ldrne r3, [pc, #0x314] */
/* @0x29ee90 ldrne r3, [r9, r3] */
/* @0x29ee94 ldrne r3, [r3] */
/* @0x29ee98 addne r1, r3, r1 */
/* @0x29ee9c mov r0, r4 */
/* @0x29eea0 bl 0x29e624 <_Z11WriteStringP15Buffer_StandardPKc> */
/* @0x29eea4 ldr r3, [r5, #0x68] */
/* @0x29eea8 cmp r3, #0 */
/* @0x29eeac beq 0x29f16c <_Z15AddCreationCodeP15Buffer_Standard+0x37c> */
/* @0x29eeb0 ldr r3, [r5, #0x6c] */
/* @0x29eeb4 cmp r3, #0 */
/* @0x29eeb8 beq 0x29f16c <_Z15AddCreationCodeP15Buffer_Standard+0x37c> */
/* @0x29eebc vldr s14, [r3, #96] */
/* @0x29eec0 vcvt.f64.u32 d7, s14 */
/* @0x29eec4 ldr r3, [r3, #0x50] */
/* @0x29eec8 mov r1, #5 */
/* @0x29eecc ldr lr, [r4] */
/* @0x29eed0 mov r2, r11 */
/* @0x29eed4 mov r0, r4 */
/* @0x29eed8 ldr r7, [r3, #0x10] */
/* @0x29eedc str r8, [r4, #0x38] */
/* @0x29eee0 vstr s14, [r4, #44] */
/* @0x29eee4 vstr s15, [r4, #48] */
/* @0x29eee8 ldr r3, [lr, #0x8] */
/* @0x29eeec blx r3 */
/* @0x29eef0 ldr r12, [r4] */
/* @0x29eef4 asr r3, r7, #31 */
/* @0x29eef8 str r7, [r4, #0x2c] */
/* @0x29eefc mov lr, #10 */
/* @0x29ef00 str r3, [r4, #0x30] */
/* @0x29ef04 str lr, [r4, #0x38] */
/* @0x29ef08 mov r0, r4 */
/* @0x29ef0c mov r1, #12 */
/* @0x29ef10 ldr r3, [r12, #0x8] */
/* @0x29ef14 mov r2, r11 */
/* @0x29ef18 blx r3 */
/* @0x29ef1c ldr r3, [r4] */
/* @0x29ef20 mov r0, r4 */
/* @0x29ef24 ldr r12, [r4, #0x1c] */
/* @0x29ef28 mov r1, #5 */
/* @0x29ef2c str r8, [r4, #0x2c] */
/* @0x29ef30 mov r2, r11 */
/* @0x29ef34 str r8, [r4, #0x30] */
/* @0x29ef38 str r8, [r4, #0x38] */
/* @0x29ef3c ldr r3, [r3, #0x8] */
/* @0x29ef40 str r12, [sp, #0x10] */
/* @0x29ef44 blx r3 */
/* @0x29ef48 ldr r7, [r6, #0x30] */
/* @0x29ef4c cmp r7, #0 */
/* @0x29ef50 beq 0x29f0e4 <_Z15AddCreationCodeP15Buffer_Standard+0x2f4> */
/* @0x29ef54 ldr r7, [r5, #0xc8] */
/* @0x29ef58 cmp r7, #0 */
/* @0x29ef5c beq 0x29f0e4 <_Z15AddCreationCodeP15Buffer_Standard+0x2f4> */
/* @0x29ef60 ldr r2, [r7] */
/* @0x29ef64 cmp r2, #0 */
/* @0x29ef68 ble 0x29f19c <_Z15AddCreationCodeP15Buffer_Standard+0x3ac> */
/* @0x29ef6c mov r5, #1 */
/* @0x29ef70 mov r3, #0 */
/* @0x29ef74 str r3, [sp, #0xc] */
/* @0x29ef78 ldr r6, [r7, r5, lsl #2] */
/* @0x29ef7c ldr r3, [r6, #0x8] */
/* @0x29ef80 cmp r3, #0 */
/* @0x29ef84 blt 0x29f0d4 <_Z15AddCreationCodeP15Buffer_Standard+0x2e4> */
/* @0x29ef88 ldr r0, [r6, #0x10] */
/* @0x29ef8c bl 0xced64 <_Z13Code_GetEntryi> */
/* @0x29ef90 cmp r0, #0 */
/* @0x29ef94 beq 0x29f0d0 <_Z15AddCreationCodeP15Buffer_Standard+0x2e0> */
/* @0x29ef98 ldr r2, [r0, #0x60] */
/* @0x29ef9c cmn r2, #1 */
/* @0x29efa0 beq 0x29f0d0 <_Z15AddCreationCodeP15Buffer_Standard+0x2e0> */
/* @0x29efa4 ldr r1, [pc, #0x200] */
/* @0x29efa8 ldr r3, [sp, #0xc] */
/* @0x29efac add r3, r3, #1 */
/* @0x29efb0 str r3, [sp, #0xc] */
/* @0x29efb4 ldr r1, [r9, r1] */
/* @0x29efb8 ldr r3, [r0, #0x50] */
/* @0x29efbc ldr r10, [r1] */
/* @0x29efc0 ldr r3, [r3, #0x10] */
/* @0x29efc4 cmp r10, #0 */
/* @0x29efc8 beq 0x29f02c <_Z15AddCreationCodeP15Buffer_Standard+0x23c> */
/* @0x29efcc ldr r1, [pc, #0x1dc] */
/* @0x29efd0 ldr r12, [sp, #0x8] */
/* @0x29efd4 ldr r1, [r9, r1] */
/* @0x29efd8 ldr r1, [r1] */
/* @0x29efdc cmp r1, r12 */
/* @0x29efe0 movle r10, #0 */
/* @0x29efe4 ble 0x29f02c <_Z15AddCreationCodeP15Buffer_Standard+0x23c> */
/* @0x29efe8 ldr r1, [r10, r12, lsl #2] */
/* @0x29efec cmp r1, #0 */
/* @0x29eff0 bne 0x29f010 <_Z15AddCreationCodeP15Buffer_Standard+0x220> */
/* @0x29eff4 ldr r10, [r1] */
/* @0x29eff8 cmp r10, #0 */
/* @0x29effc beq 0x29f02c <_Z15AddCreationCodeP15Buffer_Standard+0x23c> */
/* @0x29f000 ldr r1, [pc, #0x1ac] */
/* @0x29f004 ldr r1, [r9, r1] */
/* @0x29f008 ldr r0, [r1] */
/* @0x29f00c b 0x29f028 <_Z15AddCreationCodeP15Buffer_Standard+0x238> */
/* @0x29f010 ldr r0, [pc, #0x19c] */
/* @0x29f014 ldr r0, [r9, r0] */
/* @0x29f018 ldr r0, [r0] */
/* @0x29f01c ldr r10, [r1, r0] */
/* @0x29f020 cmp r10, #0 */
/* @0x29f024 beq 0x29f02c <_Z15AddCreationCodeP15Buffer_Standard+0x23c> */
/* @0x29f028 add r10, r10, r0 */
/* @0x29f02c vmov s13, r2 */
/* @0x29f030 ldr lr, [r4] */
/* @0x29f034 ldr r12, [sp, #0x8] */
/* @0x29f038 mov r1, #5 */
/* @0x29f03c vcvt.f64.u32 d7, s13 */
/* @0x29f040 str r8, [r4, #0x38] */
/* @0x29f044 mov r2, r11 */
/* @0x29f048 add r12, r12, #1 */
/* @0x29f04c mov r0, r4 */
/* @0x29f050 str r12, [sp, #0x8] */
/* @0x29f054 vstr s14, [r4, #44] */
/* @0x29f058 vstr s15, [r4, #48] */
/* @0x29f05c ldr r12, [lr, #0x8] */
/* @0x29f060 str r3, [sp] */
/* @0x29f064 blx r12 */
/* @0x29f068 ldr r3, [sp] */
/* @0x29f06c ldr r12, [r4] */
/* @0x29f070 mov r2, r11 */
/* @0x29f074 mov r0, #10 */
/* @0x29f078 mov r1, #12 */
/* @0x29f07c str r3, [r4, #0x2c] */
/* @0x29f080 asr r3, r3, #31 */
/* @0x29f084 str r0, [r4, #0x38] */
/* @0x29f088 mov r0, r4 */
/* @0x29f08c str r3, [r4, #0x30] */
/* @0x29f090 ldr r3, [r12, #0x8] */
/* @0x29f094 blx r3 */
/* @0x29f098 mov r0, r4 */
/* @0x29f09c mov r1, r10 */
/* @0x29f0a0 bl 0x29e624 <_Z11WriteStringP15Buffer_StandardPKc> */
/* @0x29f0a4 vldr s14, [r6, #8] */
/* @0x29f0a8 vcvt.f64.u32 d7, s14 */
/* @0x29f0ac ldr r3, [r4] */
/* @0x29f0b0 mov r0, r4 */
/* @0x29f0b4 str r8, [r4, #0x38] */
/* @0x29f0b8 mov r1, #5 */
/* @0x29f0bc mov r2, r11 */
/* @0x29f0c0 vstr s14, [r4, #44] */
/* @0x29f0c4 vstr s15, [r4, #48] */
/* @0x29f0c8 ldr r3, [r3, #0x8] */
/* @0x29f0cc blx r3 */
/* @0x29f0d0 ldr r2, [r7] */
/* @0x29f0d4 cmp r2, r5 */
/* @0x29f0d8 add r5, r5, #1 */
/* @0x29f0dc bgt 0x29ef78 <_Z15AddCreationCodeP15Buffer_Standard+0x188> */
/* @0x29f0e0 ldr r7, [sp, #0xc] */
/* @0x29f0e4 ldr r3, [r4] */
/* @0x29f0e8 mov r1, #0 */
/* @0x29f0ec ldr r12, [sp, #0x4] */
/* @0x29f0f0 mov r0, r4 */
/* @0x29f0f4 ldr r2, [sp, #0x10] */
/* @0x29f0f8 add r12, r12, #1 */
/* @0x29f0fc ldr r3, [r3, #0x10] */
/* @0x29f100 str r12, [sp, #0x4] */
/* @0x29f104 ldr r5, [r4, #0x1c] */
/* @0x29f108 blx r3 */
/* @0x29f10c vmov s15, r7 */
/* @0x29f110 ldr lr, [r4] */
/* @0x29f114 mov r1, #5 */
/* @0x29f118 mov r2, r11 */
/* @0x29f11c vcvt.f64.u32 d7, s15 */
/* @0x29f120 mov r0, r4 */
/* @0x29f124 str r8, [r4, #0x38] */
/* @0x29f128 vmov r6, r7, d7 */
/* @0x29f12c vstr s14, [r4, #44] */
/* @0x29f130 str r7, [r4, #0x30] */
/* @0x29f134 ldr r3, [lr, #0x8] */
/* @0x29f138 blx r3 */
/* @0x29f13c ldr r3, [r4] */
/* @0x29f140 mov r2, r5 */
/* @0x29f144 mov r0, r4 */
/* @0x29f148 mov r1, #0 */
/* @0x29f14c ldr r3, [r3, #0x10] */
/* @0x29f150 blx r3 */
/* @0x29f154 ldr r3, [sp, #0x4] */
/* @0x29f158 ldr r12, [sp, #0x14] */
/* @0x29f15c cmp r3, r12 */
/* @0x29f160 bne 0x29ee74 <_Z15AddCreationCodeP15Buffer_Standard+0x84> */
/* @0x29f164 add sp, sp, #36 */
/* @0x29f168 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x29f16c ldr r12, [sp, #0x18] */
/* @0x29f170 mov r0, r4 */
/* @0x29f174 ldr r3, [r4] */
/* @0x29f178 mov r1, #5 */
/* @0x29f17c mov r2, r11 */
/* @0x29f180 str r8, [r4, #0x38] */
/* @0x29f184 str r12, [r4, #0x2c] */
/* @0x29f188 ldr r12, [sp, #0x1c] */
/* @0x29f18c str r12, [r4, #0x30] */
/* @0x29f190 ldr r3, [r3, #0x8] */
/* @0x29f194 blx r3 */
/* @0x29f198 b 0x29ef1c <_Z15AddCreationCodeP15Buffer_Standard+0x12c> */
/* @0x29f19c mov r7, #0 */
/* @0x29f1a0 b 0x29f0e4 <_Z15AddCreationCodeP15Buffer_Standard+0x2f4> */
/* @0x29f1a4 andseq r2, r5, r4, lsr lr */
/* @0x29f1a8 .word 0xffffbcf4 */
/* @0x29f1ac .word 0xfffff098 */
/* @0x29f1b0 .word 0xfffff09c */
/* @0x29f1b4 .word 0xffffbf00 */

/* ── FUNC 0x29f1b8 · AddTimelineCode(Buffer_Standard*) · size=456 · insn=114 */
/* @0x29f1b8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x29f1bc sub sp, sp, #20 */
/* @0x29f1c0 mov r11, r0 */
/* @0x29f1c4 bl 0x1f2b00 <_Z15TimeLine_Numberv> */
/* @0x29f1c8 ldr r3, [r11] */
/* @0x29f1cc add r5, r11, #44 */
/* @0x29f1d0 mov r10, #0 */
/* @0x29f1d4 mov r1, #5 */
/* @0x29f1d8 str r10, [r11, #0x38] */
/* @0x29f1dc mov r2, r5 */
/* @0x29f1e0 str r0, [sp, #0xc] */
/* @0x29f1e4 mov r0, r11 */
/* @0x29f1e8 vldr s15, [sp, #12] */
/* @0x29f1ec vcvt.f64.u32 d7, s15 */
/* @0x29f1f0 vmov r6, r7, d7 */
/* @0x29f1f4 vstr s14, [r11, #44] */
/* @0x29f1f8 str r7, [r11, #0x30] */
/* @0x29f1fc ldr r3, [r3, #0x8] */
/* @0x29f200 blx r3 */
/* @0x29f204 ldr r3, [sp, #0xc] */
/* @0x29f208 cmp r3, r10 */
/* @0x29f20c ble 0x29f378 <_Z15AddTimelineCodeP15Buffer_Standard+0x1c0> */
/* @0x29f210 mov r9, #10 */
/* @0x29f214 mov r7, r10 */
/* @0x29f218 str r10, [sp, #0x8] */
/* @0x29f21c ldr r0, [sp, #0x8] */
/* @0x29f220 bl 0x1f2c48 <_Z13TimeLine_Datai> */
/* @0x29f224 mov r6, r0 */
/* @0x29f228 ldr r0, [sp, #0x8] */
/* @0x29f22c bl 0x1f2b58 <_Z13TimeLine_Namei> */
/* @0x29f230 mov r1, r0 */
/* @0x29f234 mov r0, r11 */
/* @0x29f238 bl 0x29e624 <_Z11WriteStringP15Buffer_StandardPKc> */
/* @0x29f23c mov r0, r6 */
/* @0x29f240 bl 0x1f1760 <_ZN9CTimeLine8GetCountEv> */
/* @0x29f244 ldr r3, [r11] */
/* @0x29f248 str r7, [r11, #0x38] */
/* @0x29f24c mov r1, #5 */
/* @0x29f250 mov r2, r5 */
/* @0x29f254 vmov s13, r0 */
/* @0x29f258 mov r8, r0 */
/* @0x29f25c mov r0, r11 */
/* @0x29f260 vcvt.f64.u32 d7, s13 */
/* @0x29f264 vstr s14, [r11, #44] */
/* @0x29f268 vstr s15, [r11, #48] */
/* @0x29f26c ldr r3, [r3, #0x8] */
/* @0x29f270 blx r3 */
/* @0x29f274 cmp r8, #0 */
/* @0x29f278 strgt r8, [sp, #0x4] */
/* @0x29f27c movgt r4, #0 */
/* @0x29f280 movgt r8, r11 */
/* @0x29f284 ble 0x29f360 <_Z15AddTimelineCodeP15Buffer_Standard+0x1a8> */
/* @0x29f288 mov r1, r4 */
/* @0x29f28c mov r0, r6 */
/* @0x29f290 bl 0x1f1710 <_ZN9CTimeLine8GetEventEi> */
/* @0x29f294 mov r1, r4 */
/* @0x29f298 add r4, r4, #1 */
/* @0x29f29c mov r12, r0 */
/* @0x29f2a0 mov r0, r6 */
/* @0x29f2a4 str r12, [sp] */
/* @0x29f2a8 bl 0x1f1738 <_ZN9CTimeLine7GetStepEi> */
/* @0x29f2ac ldr lr, [r8] */
/* @0x29f2b0 mov r1, #5 */
/* @0x29f2b4 mov r2, r5 */
/* @0x29f2b8 str r7, [r8, #0x38] */
/* @0x29f2bc vmov s15, r0 */
/* @0x29f2c0 mov r0, r8 */
/* @0x29f2c4 vcvt.f64.u32 d7, s15 */
/* @0x29f2c8 vmov r10, r11, d7 */
/* @0x29f2cc vstr s14, [r8, #44] */
/* @0x29f2d0 str r11, [r8, #0x30] */
/* @0x29f2d4 ldr r10, [lr, #0x8] */
/* @0x29f2d8 blx r10 */
/* @0x29f2dc ldr r12, [sp] */
/* @0x29f2e0 ldr lr, [r8] */
/* @0x29f2e4 mov r1, #5 */
/* @0x29f2e8 mov r2, r5 */
/* @0x29f2ec mov r0, r8 */
/* @0x29f2f0 ldr r12, [r12, #0x4] */
/* @0x29f2f4 ldr r10, [r12, #0x60] */
/* @0x29f2f8 str r7, [r8, #0x38] */
/* @0x29f2fc vmov s15, r10 */
/* @0x29f300 vcvt.f64.u32 d7, s15 */
/* @0x29f304 vmov r10, r11, d7 */
/* @0x29f308 vstr s14, [r8, #44] */
/* @0x29f30c str r11, [r8, #0x30] */
/* @0x29f310 ldr r10, [lr, #0x8] */
/* @0x29f314 str r12, [sp] */
/* @0x29f318 blx r10 */
/* @0x29f31c ldr r12, [sp] */
/* @0x29f320 ldr lr, [r8] */
/* @0x29f324 mov r0, r8 */
/* @0x29f328 mov r1, #12 */
/* @0x29f32c mov r2, r5 */
/* @0x29f330 ldr r12, [r12, #0x50] */
/* @0x29f334 ldr r12, [r12, #0x10] */
/* @0x29f338 str r9, [r8, #0x38] */
/* @0x29f33c asr r11, r12, #31 */
/* @0x29f340 str r12, [r8, #0x2c] */
/* @0x29f344 str r11, [r8, #0x30] */
/* @0x29f348 ldr r12, [lr, #0x8] */
/* @0x29f34c blx r12 */
/* @0x29f350 ldr r3, [sp, #0x4] */
/* @0x29f354 cmp r4, r3 */
/* @0x29f358 bne 0x29f288 <_Z15AddTimelineCodeP15Buffer_Standard+0xd0> */
/* @0x29f35c mov r11, r8 */
/* @0x29f360 ldr r3, [sp, #0x8] */
/* @0x29f364 ldr r2, [sp, #0xc] */
/* @0x29f368 add r3, r3, #1 */
/* @0x29f36c str r3, [sp, #0x8] */
/* @0x29f370 cmp r3, r2 */
/* @0x29f374 bne 0x29f21c <_Z15AddTimelineCodeP15Buffer_Standard+0x64> */
/* @0x29f378 add sp, sp, #20 */
/* @0x29f37c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x29f380 · AddVMCodeBuffers(Buffer_Standard*) · size=356 · insn=89 */
/* @0x29f380 ldr r3, [pc, #0x14c] */
/* @0x29f384 mov r1, #5 */
/* @0x29f388 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x29f38c ldr r3, [pc, r3] */
/* @0x29f390 ldr r12, [r0] */
/* @0x29f394 add r9, r0, #44 */
/* @0x29f398 ldr r4, [r3] */
/* @0x29f39c mov r6, r0 */
/* @0x29f3a0 mov r8, #0 */
/* @0x29f3a4 sub sp, sp, #12 */
/* @0x29f3a8 str r8, [r0, #0x38] */
/* @0x29f3ac mov r2, r9 */
/* @0x29f3b0 vmov s15, r4 */
/* @0x29f3b4 vcvt.f64.u32 d7, s15 */
/* @0x29f3b8 vmov r4, r5, d7 */
/* @0x29f3bc vstr s14, [r6, #44] */
/* @0x29f3c0 str r5, [r6, #0x30] */
/* @0x29f3c4 ldr r3, [r12, #0x8] */
/* @0x29f3c8 blx r3 */
/* @0x29f3cc ldr r3, [pc, #0x104] */
/* @0x29f3d0 ldr r3, [pc, r3] */
/* @0x29f3d4 ldr r10, [r3] */
/* @0x29f3d8 cmp r10, r8 */
/* @0x29f3dc beq 0x29f4cc <_Z16AddVMCodeBuffersP15Buffer_Standard+0x14c> */
/* @0x29f3e0 mov r7, r8 */
/* @0x29f3e4 b 0x29f404 <_Z16AddVMCodeBuffersP15Buffer_Standard+0x84> */
/* @0x29f3e8 mov r1, r11 */
/* @0x29f3ec ldr r2, [sp, #0x4] */
/* @0x29f3f0 bl 0x29e730 <_Z9WriteDataP15Buffer_StandardPKhi> */
/* @0x29f3f4 ldr r10, [r10, #0x4] */
/* @0x29f3f8 add r8, r8, #1 */
/* @0x29f3fc cmp r10, #0 */
/* @0x29f400 beq 0x29f49c <_Z16AddVMCodeBuffersP15Buffer_Standard+0x11c> */
/* @0x29f404 vldr s15, [r10, #96] */
/* @0x29f408 vcvt.f64.u32 d7, s15 */
/* @0x29f40c ldr r11, [r10, #0x50] */
/* @0x29f410 mov r2, r9 */
/* @0x29f414 ldr r12, [r10, #0x5c] */
/* @0x29f418 mov r1, #5 */
/* @0x29f41c ldr lr, [r6] */
/* @0x29f420 mov r0, r6 */
/* @0x29f424 ldr r3, [r11, #0x4] */
/* @0x29f428 ldr r11, [r11, #0x10] */
/* @0x29f42c str r7, [r6, #0x38] */
/* @0x29f430 vmov r4, r5, d7 */
/* @0x29f434 vstr s14, [r6, #44] */
/* @0x29f438 str r3, [sp, #0x4] */
/* @0x29f43c str r5, [r6, #0x30] */
/* @0x29f440 ldr r4, [lr, #0x8] */
/* @0x29f444 str r12, [sp] */
/* @0x29f448 blx r4 */
/* @0x29f44c ldr r12, [sp] */
/* @0x29f450 mov r0, r6 */
/* @0x29f454 mov r1, r12 */
/* @0x29f458 bl 0x29e624 <_Z11WriteStringP15Buffer_StandardPKc> */
/* @0x29f45c ldr r12, [r10, #0x6c] */
/* @0x29f460 mov r0, r6 */
/* @0x29f464 mov r1, #5 */
/* @0x29f468 cmp r12, #0 */
/* @0x29f46c mov r2, r9 */
/* @0x29f470 beq 0x29f3e8 <_Z16AddVMCodeBuffersP15Buffer_Standard+0x68> */
/* @0x29f474 ldr r12, [r6] */
/* @0x29f478 add r8, r8, #1 */
/* @0x29f47c str r7, [r6, #0x2c] */
/* @0x29f480 str r7, [r6, #0x30] */
/* @0x29f484 str r7, [r6, #0x38] */
/* @0x29f488 ldr r12, [r12, #0x8] */
/* @0x29f48c blx r12 */
/* @0x29f490 ldr r10, [r10, #0x4] */
/* @0x29f494 cmp r10, #0 */
/* @0x29f498 bne 0x29f404 <_Z16AddVMCodeBuffersP15Buffer_Standard+0x84> */
/* @0x29f49c ldr r0, [pc, #0x38] */
/* @0x29f4a0 mov r2, r8 */
/* @0x29f4a4 ldr r1, [pc, #0x34] */
/* @0x29f4a8 ldr r0, [pc, r0] */
/* @0x29f4ac ldr r3, [r6, #0x20] */
/* @0x29f4b0 add r1, pc, r1 */
/* @0x29f4b4 ldr r0, [r0] */
/* @0x29f4b8 ldr r12, [r0] */
/* @0x29f4bc ldr r12, [r12, #0xc] */
/* @0x29f4c0 blx r12 */
/* @0x29f4c4 add sp, sp, #12 */
/* @0x29f4c8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x29f4cc mov r8, r10 */
/* @0x29f4d0 b 0x29f49c <_Z16AddVMCodeBuffersP15Buffer_Standard+0x11c> */
/* @0x29f4d4 mulseq r4, r12, r7 */
/* @0x29f4d8 andseq lr, r4, r0, asr r7 */
/* @0x29f4dc andseq lr, r4, r12, ror #4 */
/* @0x29f4e0 andeq r10, r11, r8, asr r7 */

/* ── FUNC 0x29f4e4 · AddFunctionNames(Buffer_Standard*) · size=1612 · insn=403 */
/* @0x29f4e4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x29f4e8 sub sp, sp, #20 */
/* @0x29f4ec ldr r3, [pc, #0x608] */
/* @0x29f4f0 add r7, r0, #44 */
/* @0x29f4f4 ldr r12, [pc, #0x604] */
/* @0x29f4f8 mov r6, r0 */
/* @0x29f4fc add r3, pc, r3 */
/* @0x29f500 str r3, [sp, #0x4] */
/* @0x29f504 ldr r4, [sp, #0x4] */
/* @0x29f508 mov r9, #0 */
/* @0x29f50c ldr r3, [r0] */
/* @0x29f510 mov r2, r7 */
/* @0x29f514 mov r1, #5 */
/* @0x29f518 ldr r8, [r4, r12] */
/* @0x29f51c vldr s15, [r8] */
/* @0x29f520 vcvt.f64.u32 d7, s15 */
/* @0x29f524 str r9, [r0, #0x38] */
/* @0x29f528 vmov r4, r5, d7 */
/* @0x29f52c vstr s14, [r6, #44] */
/* @0x29f530 str r5, [r6, #0x30] */
/* @0x29f534 ldr r3, [r3, #0x8] */
/* @0x29f538 blx r3 */
/* @0x29f53c ldr r3, [r8] */
/* @0x29f540 cmp r3, r9 */
/* @0x29f544 ble 0x29f580 <_Z16AddFunctionNamesP15Buffer_Standard+0x9c> */
/* @0x29f548 ldr r3, [pc, #0x5b4] */
/* @0x29f54c mov r4, r9 */
/* @0x29f550 ldr r12, [sp, #0x4] */
/* @0x29f554 mov r5, r9 */
/* @0x29f558 ldr r9, [r12, r3] */
/* @0x29f55c ldr r1, [r9] */
/* @0x29f560 mov r0, r6 */
/* @0x29f564 add r5, r5, #1 */
/* @0x29f568 add r1, r1, r4 */
/* @0x29f56c add r4, r4, #80 */
/* @0x29f570 bl 0x29e624 <_Z11WriteStringP15Buffer_StandardPKc> */
/* @0x29f574 ldr r3, [r8] */
/* @0x29f578 cmp r3, r5 */
/* @0x29f57c bgt 0x29f55c <_Z16AddFunctionNamesP15Buffer_Standard+0x78> */
/* @0x29f580 ldr r3, [pc, #0x580] */
/* @0x29f584 ldr r4, [sp, #0x4] */
/* @0x29f588 ldr r3, [r4, r3] */
/* @0x29f58c str r3, [sp, #0xc] */
/* @0x29f590 ldrb r3, [r3] */
/* @0x29f594 cmp r3, #0 */
/* @0x29f598 bne 0x29f634 <_Z16AddFunctionNamesP15Buffer_Standard+0x150> */
/* @0x29f59c ldr r2, [pc, #0x568] */
/* @0x29f5a0 ldr r4, [sp, #0x4] */
/* @0x29f5a4 ldr r2, [r4, r2] */
/* @0x29f5a8 ldr r1, [r2] */
/* @0x29f5ac cmp r1, #0 */
/* @0x29f5b0 ble 0x29fad4 <_Z16AddFunctionNamesP15Buffer_Standard+0x5f0> */
/* @0x29f5b4 ldr r2, [pc, #0x554] */
/* @0x29f5b8 lsl r1, r1, #4 */
/* @0x29f5bc mov r9, r3 */
/* @0x29f5c0 ldr r8, [r4, r2] */
/* @0x29f5c4 ldr r2, [r8, r3] */
/* @0x29f5c8 add r3, r3, #16 */
/* @0x29f5cc cmp r2, #0 */
/* @0x29f5d0 addne r9, r9, #1 */
/* @0x29f5d4 cmp r3, r1 */
/* @0x29f5d8 bne 0x29f5c4 <_Z16AddFunctionNamesP15Buffer_Standard+0xe0> */
/* @0x29f5dc vmov s15, r9 */
/* @0x29f5e0 ldr r3, [r6] */
/* @0x29f5e4 mov r11, #0 */
/* @0x29f5e8 mov r0, r6 */
/* @0x29f5ec vcvt.f64.u32 d7, s15 */
/* @0x29f5f0 str r11, [r6, #0x38] */
/* @0x29f5f4 mov r1, #5 */
/* @0x29f5f8 mov r2, r7 */
/* @0x29f5fc vmov r4, r5, d7 */
/* @0x29f600 vstr s14, [r6, #44] */
/* @0x29f604 str r5, [r6, #0x30] */
/* @0x29f608 ldr r3, [r3, #0x8] */
/* @0x29f60c blx r3 */
/* @0x29f610 cmp r9, r11 */
/* @0x29f614 beq 0x29f634 <_Z16AddFunctionNamesP15Buffer_Standard+0x150> */
/* @0x29f618 mov r4, r11 */
/* @0x29f61c ldr r1, [r8, r4, lsl #4] */
/* @0x29f620 mov r0, r6 */
/* @0x29f624 add r4, r4, #1 */
/* @0x29f628 bl 0x29e624 <_Z11WriteStringP15Buffer_StandardPKc> */
/* @0x29f62c cmp r4, r9 */
/* @0x29f630 bne 0x29f61c <_Z16AddFunctionNamesP15Buffer_Standard+0x138> */
/* @0x29f634 ldr r3, [r6] */
/* @0x29f638 mov r8, #0 */
/* @0x29f63c ldr r4, [r6, #0x1c] */
/* @0x29f640 mov r0, r6 */
/* @0x29f644 str r8, [r6, #0x2c] */
/* @0x29f648 mov r1, #5 */
/* @0x29f64c str r8, [r6, #0x30] */
/* @0x29f650 mov r2, r7 */
/* @0x29f654 ldr r3, [r3, #0x8] */
/* @0x29f658 str r8, [r6, #0x38] */
/* @0x29f65c str r4, [sp, #0x8] */
/* @0x29f660 blx r3 */
/* @0x29f664 ldr r3, [pc, #0x4a8] */
/* @0x29f668 ldr r12, [sp, #0x4] */
/* @0x29f66c ldr r11, [r12, r3] */
/* @0x29f670 ldr r3, [r11, #0x4] */
/* @0x29f674 cmp r3, r8 */
/* @0x29f678 ble 0x29f704 <_Z16AddFunctionNamesP15Buffer_Standard+0x220> */
/* @0x29f67c mov r10, r8 */
/* @0x29f680 ldr r3, [r11] */
/* @0x29f684 mov r1, #6 */
/* @0x29f688 mov r2, r7 */
/* @0x29f68c mov r0, r6 */
/* @0x29f690 cmp r3, r10 */
/* @0x29f694 lsl r9, r10, #2 */
/* @0x29f698 ble 0x29f6f4 <_Z16AddFunctionNamesP15Buffer_Standard+0x210> */
/* @0x29f69c ldr r3, [r11, #0xc] */
/* @0x29f6a0 ldr r3, [r3, r10, lsl #2] */
/* @0x29f6a4 cmp r3, #0 */
/* @0x29f6a8 beq 0x29f6f4 <_Z16AddFunctionNamesP15Buffer_Standard+0x210> */
/* @0x29f6ac vmov s15, r10 */
/* @0x29f6b0 ldr r3, [r6] */
/* @0x29f6b4 mov lr, #0 */
/* @0x29f6b8 str lr, [r6, #0x38] */
/* @0x29f6bc vcvt.f64.s32 d7, s15 */
/* @0x29f6c0 add r8, r8, #1 */
/* @0x29f6c4 vmov r4, r5, d7 */
/* @0x29f6c8 vstr s14, [r6, #44] */
/* @0x29f6cc str r5, [r6, #0x30] */
/* @0x29f6d0 ldr r3, [r3, #0x8] */
/* @0x29f6d4 blx r3 */
/* @0x29f6d8 ldr r3, [r11] */
/* @0x29f6dc mov r1, #0 */
/* @0x29f6e0 mov r0, r6 */
/* @0x29f6e4 cmp r3, r10 */
/* @0x29f6e8 ldrgt r3, [r11, #0xc] */
/* @0x29f6ec ldrgt r1, [r3, r9] */
/* @0x29f6f0 bl 0x29e624 <_Z11WriteStringP15Buffer_StandardPKc> */
/* @0x29f6f4 ldr r3, [r11, #0x4] */
/* @0x29f6f8 add r10, r10, #1 */
/* @0x29f6fc cmp r3, r10 */
/* @0x29f700 bgt 0x29f680 <_Z16AddFunctionNamesP15Buffer_Standard+0x19c> */
/* @0x29f704 ldr r3, [r6] */
/* @0x29f708 mov r1, #0 */
/* @0x29f70c ldr r2, [sp, #0x8] */
/* @0x29f710 mov r0, r6 */
/* @0x29f714 mov r4, r1 */
/* @0x29f718 ldr r5, [r6, #0x1c] */
/* @0x29f71c ldr r3, [r3, #0x10] */
/* @0x29f720 blx r3 */
/* @0x29f724 vmov s15, r8 */
/* @0x29f728 ldr r3, [r6] */
/* @0x29f72c mov r1, #6 */
/* @0x29f730 vcvt.f64.s32 d7, s15 */
/* @0x29f734 mov r2, r7 */
/* @0x29f738 mov r0, r6 */
/* @0x29f73c str r4, [r6, #0x38] */
/* @0x29f740 vmov r8, r9, d7 */
/* @0x29f744 vstr s14, [r6, #44] */
/* @0x29f748 mov r8, r4 */
/* @0x29f74c str r9, [r6, #0x30] */
/* @0x29f750 ldr r3, [r3, #0x8] */
/* @0x29f754 blx r3 */
/* @0x29f758 ldr r3, [r6] */
/* @0x29f75c mov r2, r5 */
/* @0x29f760 mov r1, r4 */
/* @0x29f764 mov r0, r6 */
/* @0x29f768 ldr r3, [r3, #0x10] */
/* @0x29f76c blx r3 */
/* @0x29f770 ldr r3, [r6] */
/* @0x29f774 str r4, [r6, #0x2c] */
/* @0x29f778 mov r0, r6 */
/* @0x29f77c str r4, [r6, #0x30] */
/* @0x29f780 mov r1, #5 */
/* @0x29f784 ldr r3, [r3, #0x8] */
/* @0x29f788 mov r2, r7 */
/* @0x29f78c str r4, [r6, #0x38] */
/* @0x29f790 ldr r11, [r6, #0x1c] */
/* @0x29f794 blx r3 */
/* @0x29f798 ldr r3, [pc, #0x378] */
/* @0x29f79c ldr r12, [sp, #0x4] */
/* @0x29f7a0 ldr r5, [r12, r3] */
/* @0x29f7a4 ldr r3, [r5, #0x4] */
/* @0x29f7a8 cmp r3, r4 */
/* @0x29f7ac ble 0x29f838 <_Z16AddFunctionNamesP15Buffer_Standard+0x354> */
/* @0x29f7b0 mov r9, r4 */
/* @0x29f7b4 str r11, [sp, #0x8] */
/* @0x29f7b8 str r7, [sp] */
/* @0x29f7bc ldr r3, [r5] */
/* @0x29f7c0 add r10, r4, #99328 */
/* @0x29f7c4 ldr r2, [sp] */
/* @0x29f7c8 add r10, r10, #672 */
/* @0x29f7cc cmp r3, r4 */
/* @0x29f7d0 mov r0, r6 */
/* @0x29f7d4 mov r1, #6 */
/* @0x29f7d8 ble 0x29f820 <_Z16AddFunctionNamesP15Buffer_Standard+0x33c> */
/* @0x29f7dc ldr r3, [r5, #0xc] */
/* @0x29f7e0 ldr r7, [r3, r4, lsl #2] */
/* @0x29f7e4 cmp r7, #0 */
/* @0x29f7e8 beq 0x29f820 <_Z16AddFunctionNamesP15Buffer_Standard+0x33c> */
/* @0x29f7ec vmov s15, r10 */
/* @0x29f7f0 ldr lr, [r6] */
/* @0x29f7f4 str r9, [r6, #0x38] */
/* @0x29f7f8 add r8, r8, #1 */
/* @0x29f7fc vcvt.f64.s32 d7, s15 */
/* @0x29f800 vmov r10, r11, d7 */
/* @0x29f804 vstr s14, [r6, #44] */
/* @0x29f808 str r11, [r6, #0x30] */
/* @0x29f80c ldr r10, [lr, #0x8] */
/* @0x29f810 blx r10 */
/* @0x29f814 mov r0, r6 */
/* @0x29f818 mov r1, r7 */
/* @0x29f81c bl 0x29e624 <_Z11WriteStringP15Buffer_StandardPKc> */
/* @0x29f820 ldr r3, [r5, #0x4] */
/* @0x29f824 add r4, r4, #1 */
/* @0x29f828 cmp r3, r4 */
/* @0x29f82c bgt 0x29f7bc <_Z16AddFunctionNamesP15Buffer_Standard+0x2d8> */
/* @0x29f830 ldr r11, [sp, #0x8] */
/* @0x29f834 ldr r7, [sp] */
/* @0x29f838 ldr r3, [r6] */
/* @0x29f83c mov r2, r11 */
/* @0x29f840 mov r1, #0 */
/* @0x29f844 mov r0, r6 */
/* @0x29f848 mov r5, r1 */
/* @0x29f84c ldr r4, [r6, #0x1c] */
/* @0x29f850 ldr r3, [r3, #0x10] */
/* @0x29f854 blx r3 */
/* @0x29f858 vmov s15, r8 */
/* @0x29f85c ldr r3, [r6] */
/* @0x29f860 mov r1, #6 */
/* @0x29f864 vcvt.f64.s32 d7, s15 */
/* @0x29f868 mov r2, r7 */
/* @0x29f86c mov r0, r6 */
/* @0x29f870 str r5, [r6, #0x38] */
/* @0x29f874 vmov r8, r9, d7 */
/* @0x29f878 vstr s14, [r6, #44] */
/* @0x29f87c str r9, [r6, #0x30] */
/* @0x29f880 ldr r3, [r3, #0x8] */
/* @0x29f884 blx r3 */
/* @0x29f888 ldr r3, [r6] */
/* @0x29f88c mov r2, r4 */
/* @0x29f890 mov r1, r5 */
/* @0x29f894 mov r0, r6 */
/* @0x29f898 ldr r3, [r3, #0x10] */
/* @0x29f89c blx r3 */
/* @0x29f8a0 ldr r12, [pc, #0x274] */
/* @0x29f8a4 ldr r4, [sp, #0x4] */
/* @0x29f8a8 mov r0, r6 */
/* @0x29f8ac ldr r3, [r6] */
/* @0x29f8b0 mov r1, #5 */
/* @0x29f8b4 mov r2, r7 */
/* @0x29f8b8 ldr r11, [r4, r12] */
/* @0x29f8bc vldr s15, [r11] */
/* @0x29f8c0 vcvt.f64.u32 d7, s15 */
/* @0x29f8c4 str r5, [r6, #0x38] */
/* @0x29f8c8 vmov r8, r9, d7 */
/* @0x29f8cc vstr s14, [r6, #44] */
/* @0x29f8d0 str r9, [r6, #0x30] */
/* @0x29f8d4 ldr r3, [r3, #0x8] */
/* @0x29f8d8 blx r3 */
/* @0x29f8dc ldr r3, [r11] */
/* @0x29f8e0 cmp r3, r5 */
/* @0x29f8e4 ble 0x29f9ec <_Z16AddFunctionNamesP15Buffer_Standard+0x508> */
/* @0x29f8e8 ldr r3, [pc, #0x230] */
/* @0x29f8ec mov r9, r5 */
/* @0x29f8f0 ldr r4, [sp, #0x4] */
/* @0x29f8f4 mov r8, r5 */
/* @0x29f8f8 ldr r10, [r4, r3] */
/* @0x29f8fc str r11, [sp] */
/* @0x29f900 ldr r3, [r10] */
/* @0x29f904 mov r0, r6 */
/* @0x29f908 ldr r1, [r3, r8] */
/* @0x29f90c bl 0x29e624 <_Z11WriteStringP15Buffer_StandardPKc> */
/* @0x29f910 ldr r2, [r10] */
/* @0x29f914 ldr r3, [r6] */
/* @0x29f918 mov r12, #0 */
/* @0x29f91c add r2, r2, r8 */
/* @0x29f920 mov r0, r6 */
/* @0x29f924 mov r1, #5 */
/* @0x29f928 ldr r4, [r2, #0x4] */
/* @0x29f92c mov r2, r7 */
/* @0x29f930 str r12, [r6, #0x38] */
/* @0x29f934 vmov s15, r4 */
/* @0x29f938 vcvt.f64.u32 d7, s15 */
/* @0x29f93c vmov r4, r5, d7 */
/* @0x29f940 vstr s14, [r6, #44] */
/* @0x29f944 str r5, [r6, #0x30] */
/* @0x29f948 ldr r3, [r3, #0x8] */
/* @0x29f94c blx r3 */
/* @0x29f950 ldr r3, [r10] */
/* @0x29f954 add r3, r3, r8 */
/* @0x29f958 ldr r3, [r3, #0x4] */
/* @0x29f95c cmp r3, #0 */
/* @0x29f960 movgt r11, #0 */
/* @0x29f964 ble 0x29f9d4 <_Z16AddFunctionNamesP15Buffer_Standard+0x4f0> */
/* @0x29f968 add r4, r11, #199680 */
/* @0x29f96c ldr r3, [r6] */
/* @0x29f970 add r4, r4, #320 */
/* @0x29f974 mov r12, #0 */
/* @0x29f978 mov r1, #6 */
/* @0x29f97c str r12, [r6, #0x38] */
/* @0x29f980 vmov s15, r4 */
/* @0x29f984 mov r2, r7 */
/* @0x29f988 mov r0, r6 */
/* @0x29f98c vcvt.f64.s32 d7, s15 */
/* @0x29f990 vmov r4, r5, d7 */
/* @0x29f994 vstr s14, [r6, #44] */
/* @0x29f998 str r5, [r6, #0x30] */
/* @0x29f99c ldr r3, [r3, #0x8] */
/* @0x29f9a0 blx r3 */
/* @0x29f9a4 ldr r3, [r10] */
/* @0x29f9a8 mov r0, r6 */
/* @0x29f9ac add r3, r3, r8 */
/* @0x29f9b0 ldr r3, [r3, #0x8] */
/* @0x29f9b4 ldr r1, [r3, r11, lsl #2] */
/* @0x29f9b8 add r11, r11, #1 */
/* @0x29f9bc bl 0x29e624 <_Z11WriteStringP15Buffer_StandardPKc> */
/* @0x29f9c0 ldr r3, [r10] */
/* @0x29f9c4 add r3, r3, r8 */
/* @0x29f9c8 ldr r3, [r3, #0x4] */
/* @0x29f9cc cmp r3, r11 */
/* @0x29f9d0 bgt 0x29f968 <_Z16AddFunctionNamesP15Buffer_Standard+0x484> */
/* @0x29f9d4 ldr r4, [sp] */
/* @0x29f9d8 add r9, r9, #1 */
/* @0x29f9dc add r8, r8, #12 */
/* @0x29f9e0 ldr r3, [r4] */
/* @0x29f9e4 cmp r3, r9 */
/* @0x29f9e8 bgt 0x29f900 <_Z16AddFunctionNamesP15Buffer_Standard+0x41c> */
/* @0x29f9ec ldr r3, [sp, #0xc] */
/* @0x29f9f0 ldrb r9, [r3] */
/* @0x29f9f4 cmp r9, #0 */
/* @0x29f9f8 beq 0x29fa04 <_Z16AddFunctionNamesP15Buffer_Standard+0x520> */
/* @0x29f9fc add sp, sp, #20 */
/* @0x29fa00 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x29fa04 ldr lr, [pc, #0x118] */
/* @0x29fa08 mov r3, #10 */
/* @0x29fa0c ldr r4, [sp, #0x4] */
/* @0x29fa10 mov r2, r7 */
/* @0x29fa14 ldr r12, [r6] */
/* @0x29fa18 mov r1, #12 */
/* @0x29fa1c mov r0, r6 */
/* @0x29fa20 ldr r8, [r4, lr] */
/* @0x29fa24 str r3, [r6, #0x38] */
/* @0x29fa28 ldr r3, [r8] */
/* @0x29fa2c asr r5, r3, #31 */
/* @0x29fa30 str r3, [r6, #0x2c] */
/* @0x29fa34 str r5, [r6, #0x30] */
/* @0x29fa38 ldr r3, [r12, #0x8] */
/* @0x29fa3c blx r3 */
/* @0x29fa40 ldr r4, [sp, #0x4] */
/* @0x29fa44 ldr r12, [pc, #0xdc] */
/* @0x29fa48 mov r2, r7 */
/* @0x29fa4c ldr r3, [r6] */
/* @0x29fa50 mov r0, r6 */
/* @0x29fa54 mov r1, #5 */
/* @0x29fa58 ldr r7, [r4, r12] */
/* @0x29fa5c vldr s15, [r7] */
/* @0x29fa60 vcvt.f64.u32 d7, s15 */
/* @0x29fa64 str r9, [r6, #0x38] */
/* @0x29fa68 vmov r4, r5, d7 */
/* @0x29fa6c vstr s14, [r6, #44] */
/* @0x29fa70 str r5, [r6, #0x30] */
/* @0x29fa74 ldr r3, [r3, #0x8] */
/* @0x29fa78 blx r3 */
/* @0x29fa7c ldr r3, [r7] */
/* @0x29fa80 cmp r3, #0 */
/* @0x29fa84 ble 0x29f9fc <_Z16AddFunctionNamesP15Buffer_Standard+0x518> */
/* @0x29fa88 ldr r5, [sp, #0x4] */
/* @0x29fa8c mov r4, r9 */
/* @0x29fa90 ldr r3, [r8] */
/* @0x29fa94 mov r0, r6 */
/* @0x29fa98 ldr r2, [pc, #0x8c] */
/* @0x29fa9c ldr r3, [r3, r4, lsl #2] */
/* @0x29faa0 add r4, r4, #1 */
/* @0x29faa4 cmn r3, #4 */
/* @0x29faa8 ldrne r2, [r5, r2] */
/* @0x29faac moveq r1, #0 */
/* @0x29fab0 ldrne r1, [r2] */
/* @0x29fab4 addne r1, r1, #4 */
/* @0x29fab8 addne r1, r1, r3 */
/* @0x29fabc bl 0x29e624 <_Z11WriteStringP15Buffer_StandardPKc> */
/* @0x29fac0 ldr r3, [r7] */
/* @0x29fac4 cmp r3, r4 */
/* @0x29fac8 bgt 0x29fa90 <_Z16AddFunctionNamesP15Buffer_Standard+0x5ac> */
/* @0x29facc add sp, sp, #20 */
/* @0x29fad0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x29fad4 ldr r12, [r6] */
/* @0x29fad8 mov r0, r6 */
/* @0x29fadc str r3, [r6, #0x2c] */
/* @0x29fae0 mov r1, #5 */
/* @0x29fae4 str r3, [r6, #0x30] */
/* @0x29fae8 mov r2, r7 */
/* @0x29faec str r3, [r6, #0x38] */
/* @0x29faf0 ldr r3, [r12, #0x8] */
/* @0x29faf4 blx r3 */
/* @0x29faf8 b 0x29f634 <_Z16AddFunctionNamesP15Buffer_Standard+0x150> */
/* @0x29fafc andseq r2, r5, r4, asr r7 */
/* @0x29fb00 .word 0xffffbec4 */
/* @0x29fb04 .word 0xffffbec8 */
/* @0x29fb08 .word 0xffffbcd4 */
/* @0x29fb0c .word 0xffffbfe4 */
/* @0x29fb10 .word 0xffffbfe8 */
/* @0x29fb14 .word 0xffffbf4c */
/* @0x29fb18 .word 0xffffbf50 */
/* @0x29fb1c .word 0xffffbf5c */
/* @0x29fb20 .word 0xffffbf60 */
/* @0x29fb24 .word 0xffffc114 */
/* @0x29fb28 .word 0xfffff070 */
/* @0x29fb2c .word 0xffffbcf4 */
