/* libyoyo.so 覆盖卡组 0020
 * 函数 0xf2c60..0xf44f4，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0xf2c60 · DPlay_Message_Receive_Name(char const*) · size=8 · insn=2 */
/* @0xf2c60 mov r0, #0 */
/* @0xf2c64 bx lr */

/* ── FUNC 0xf2c68 · DPlay_Message_Id() · size=8 · insn=2 */
/* @0xf2c68 mov r0, #0 */
/* @0xf2c6c bx lr */

/* ── FUNC 0xf2c70 · DPlay_Message_Value(RValue*) · size=4 · insn=1 */
/* @0xf2c70 bx lr */

/* ── FUNC 0xf2c74 · DPlay_Message_Player() · size=8 · insn=2 */
/* @0xf2c74 mov r0, #0 */
/* @0xf2c78 bx lr */

/* ── FUNC 0xf2c7c · DPlay_Message_Name() · size=16 · insn=4 */
/* @0xf2c7c ldr r0, [pc, #0x4] */
/* @0xf2c80 add r0, pc, r0 */
/* @0xf2c84 bx lr */
/* @0xf2c88 eoreq r4, r4, r0, lsl #6 */

/* ── FUNC 0xf2c8c · DPlay_Message_Count(int) · size=8 · insn=2 */
/* @0xf2c8c mov r0, #0 */
/* @0xf2c90 bx lr */

/* ── FUNC 0xf2c94 · DPlay_Message_Clear(int) · size=4 · insn=1 */
/* @0xf2c94 bx lr */

/* ── FUNC 0xf2c98 · DPlay_IPaddress(char const*&) · size=4 · insn=1 */
/* @0xf2c98 bx lr */

/* ── FUNC 0xf2c9c · FINALIZE_Event_Action() · size=108 · insn=27 */
/* @0xf2c9c push {r3, r4, r5, r6, r7, lr} */
/* @0xf2ca0 ldr r5, [pc, #0x58] */
/* @0xf2ca4 ldr r5, [pc, r5] */
/* @0xf2ca8 ldr r3, [r5] */
/* @0xf2cac cmp r3, #0 */
/* @0xf2cb0 popeq {r3, r4, r5, r6, r7, pc} */
/* @0xf2cb4 ldr r6, [pc, #0x48] */
/* @0xf2cb8 ldr r6, [pc, r6] */
/* @0xf2cbc ldr r2, [r6] */
/* @0xf2cc0 cmp r2, #0 */
/* @0xf2cc4 pople {r3, r4, r5, r6, r7, pc} */
/* @0xf2cc8 mov r4, #0 */
/* @0xf2ccc mov r7, r4 */
/* @0xf2cd0 ldr r0, [r3, r4, lsl #2] */
/* @0xf2cd4 cmp r0, #0 */
/* @0xf2cd8 beq 0xf2ce8 <_Z21FINALIZE_Event_Actionv+0x4c> */
/* @0xf2cdc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xf2ce0 ldr r3, [r5] */
/* @0xf2ce4 str r7, [r3, r4, lsl #2] */
/* @0xf2ce8 ldr r3, [r6] */
/* @0xf2cec add r4, r4, #1 */
/* @0xf2cf0 cmp r3, r4 */
/* @0xf2cf4 pople {r3, r4, r5, r6, r7, pc} */
/* @0xf2cf8 ldr r3, [r5] */
/* @0xf2cfc b 0xf2cd0 <_Z21FINALIZE_Event_Actionv+0x34> */
/* @0xf2d00 eoreq r11, pc, r4, ror r1 */
/* @0xf2d04 eoreq r11, pc, r4, ror #2 */

/* ── FUNC 0xf2d08 · CEvent::Clear() · size=4 · insn=1 */
/* @0xf2d08 bx lr */

/* ── FUNC 0xf2d0c · CEvent::CEvent() · size=52 · insn=13 */
/* @0xf2d0c ldr r3, [pc, #0x28] */
/* @0xf2d10 mov r2, #0 */
/* @0xf2d14 push {r4, lr} */
/* @0xf2d18 ldr r3, [pc, r3] */
/* @0xf2d1c mov r4, r0 */
/* @0xf2d20 str r2, [r0, #0x4] */
/* @0xf2d24 str r2, [r0, #0x8] */
/* @0xf2d28 add r3, r3, #8 */
/* @0xf2d2c str r3, [r0] */
/* @0xf2d30 bl 0xf2d08 <_ZN6CEvent5ClearEv> */
/* @0xf2d34 mov r0, r4 */
/* @0xf2d38 pop {r4, pc} */
/* @0xf2d3c eoreq r11, pc, r8, lsl #2 */

/* ── FUNC 0xf2d0c · CEvent::CEvent() · alias of the symbol above · insn=0 */

/* ── FUNC 0xf2d40 · CEvent::~CEvent() · size=40 · insn=10 */
/* @0xf2d40 ldr r3, [pc, #0x1c] */
/* @0xf2d44 push {r4, lr} */
/* @0xf2d48 ldr r3, [pc, r3] */
/* @0xf2d4c mov r4, r0 */
/* @0xf2d50 add r3, r3, #8 */
/* @0xf2d54 str r3, [r0] */
/* @0xf2d58 bl 0xf2d08 <_ZN6CEvent5ClearEv> */
/* @0xf2d5c mov r0, r4 */
/* @0xf2d60 pop {r4, pc} */
/* @0xf2d64 .word 0x002fb0d8 */

/* ── FUNC 0xf2d40 · CEvent::~CEvent() · alias of the symbol above · insn=0 */

/* ── FUNC 0xf2d68 · CEvent::~CEvent() · size=28 · insn=7 */
/* @0xf2d68 push {r4, lr} */
/* @0xf2d6c mov r4, r0 */
/* @0xf2d70 bl 0xf2d40 <_ZN6CEventD2Ev> */
/* @0xf2d74 mov r0, r4 */
/* @0xf2d78 bl 0x27d1d0 <_ZdlPv> */
/* @0xf2d7c mov r0, r4 */
/* @0xf2d80 pop {r4, pc} */

/* ── FUNC 0xf2d84 · CEvent::LoadFromChunk(YYEvent*, unsigned char*) · size=140 · insn=35 */
/* @0xf2d84 ldr r3, [r1, #0x4] */
/* @0xf2d88 push {r4, r5, r6, lr} */
/* @0xf2d8c cmp r3, #0 */
/* @0xf2d90 mov r4, r0 */
/* @0xf2d94 moveq r5, r3 */
/* @0xf2d98 ldrne r2, [pc, #0x60] */
/* @0xf2d9c ldrne r2, [pc, r2] */
/* @0xf2da0 ldrne r5, [r2] */
/* @0xf2da4 addne r5, r5, r3 */
/* @0xf2da8 ldr r3, [pc, #0x54] */
/* @0xf2dac ldr r3, [pc, r3] */
/* @0xf2db0 ldrb r2, [r3] */
/* @0xf2db4 cmp r2, #0 */
/* @0xf2db8 bne 0xf2dd0 <_ZN6CEvent13LoadFromChunkEP7YYEventPh+0x4c> */
/* @0xf2dbc ldr r2, [pc, #0x44] */
/* @0xf2dc0 ldr r2, [pc, r2] */
/* @0xf2dc4 ldrb r3, [r2] */
/* @0xf2dc8 cmp r3, #0 */
/* @0xf2dcc beq 0xf2df8 <_ZN6CEvent13LoadFromChunkEP7YYEventPh+0x74> */
/* @0xf2dd0 ldr r3, [pc, #0x34] */
/* @0xf2dd4 mov r0, #124 */
/* @0xf2dd8 add r3, pc, r3 */
/* @0xf2ddc str r3, [r4, #0x8] */
/* @0xf2de0 bl 0x27c524 <_Znwj> */
/* @0xf2de4 ldr r1, [r5, #0x20] */
/* @0xf2de8 mov r2, #0 */
/* @0xf2dec mov r6, r0 */
/* @0xf2df0 bl 0xcefc8 <_ZN5CCodeC2Eib> */
/* @0xf2df4 str r6, [r4, #0x4] */
/* @0xf2df8 mov r0, #1 */
/* @0xf2dfc pop {r4, r5, r6, pc} */
/* @0xf2e00 eoreq r10, pc, r8, lsr #23 */
/* @0xf2e04 .word 0x002fadb4 */
/* @0xf2e08 eoreq r10, pc, r12, asr sp */
/* @0xf2e0c eoreq r11, r3, lr, asr sp */

/* ── FUNC 0xf2e10 · CEvent::Compile() · size=8 · insn=2 */
/* @0xf2e10 mov r0, #1 */
/* @0xf2e14 bx lr */

/* ── FUNC 0xf2e18 · CEvent::Free() · size=28 · insn=7 */
/* @0xf2e18 push {r3, lr} */
/* @0xf2e1c subs r3, r0, #0 */
/* @0xf2e20 popeq {r3, pc} */
/* @0xf2e24 ldr r3, [r3] */
/* @0xf2e28 ldr r3, [r3, #0x4] */
/* @0xf2e2c blx r3 */
/* @0xf2e30 pop {r3, pc} */

/* ── FUNC 0xf2e34 · CEvent::Execute(CInstance*, CInstance*) · size=76 · insn=19 */
/* @0xf2e34 push {r4, r5, r6, lr} */
/* @0xf2e38 sub sp, sp, #24 */
/* @0xf2e3c ldr r4, [pc, #0x38] */
/* @0xf2e40 mov lr, #0 */
/* @0xf2e44 ldr r6, [r0, #0x4] */
/* @0xf2e48 mov r12, #1 */
/* @0xf2e4c ldr r4, [pc, r4] */
/* @0xf2e50 mov r0, r1 */
/* @0xf2e54 add r3, sp, #8 */
/* @0xf2e58 mov r1, r2 */
/* @0xf2e5c ldrb r5, [r4] */
/* @0xf2e60 mov r2, r6 */
/* @0xf2e64 strb lr, [r4] */
/* @0xf2e68 str r12, [sp] */
/* @0xf2e6c bl 0xcfc60 <_Z12Code_ExecuteP9CInstanceS0_P5CCodeP6RValuei> */
/* @0xf2e70 strb r5, [r4] */
/* @0xf2e74 add sp, sp, #24 */
/* @0xf2e78 pop {r4, r5, r6, pc} */
/* @0xf2e7c .word 0x002facf0 */

/* ── FUNC 0xf2e80 · Find_Event(int, int, int, int&) · size=620 · insn=155 */
/* @0xf2e80 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0xf2e84 mov r7, r3 */
/* @0xf2e88 ldr r6, [pc, #0x258] */
/* @0xf2e8c mov r8, r2 */
/* @0xf2e90 str r0, [r7] */
/* @0xf2e94 mov r5, r0 */
/* @0xf2e98 ldr r6, [pc, r6] */
/* @0xf2e9c mov r9, r1 */
/* @0xf2ea0 ldr r3, [r6] */
/* @0xf2ea4 ldr r2, [r3, #0x4] */
/* @0xf2ea8 ldr r3, [r3] */
/* @0xf2eac and r2, r0, r2 */
/* @0xf2eb0 ldr r3, [r3, r2, lsl #3] */
/* @0xf2eb4 cmp r3, #0 */
/* @0xf2eb8 bne 0xf2ecc <_Z10Find_EventiiiRi+0x4c> */
/* @0xf2ebc b 0xf2f6c <_Z10Find_EventiiiRi+0xec> */
/* @0xf2ec0 ldr r3, [r3, #0x4] */
/* @0xf2ec4 cmp r3, #0 */
/* @0xf2ec8 beq 0xf2f6c <_Z10Find_EventiiiRi+0xec> */
/* @0xf2ecc ldr r2, [r3, #0x8] */
/* @0xf2ed0 cmp r5, r2 */
/* @0xf2ed4 bne 0xf2ec0 <_Z10Find_EventiiiRi+0x40> */
/* @0xf2ed8 ldr r4, [r3, #0xc] */
/* @0xf2edc cmp r4, #0 */
/* @0xf2ee0 beq 0xf2f6c <_Z10Find_EventiiiRi+0xec> */
/* @0xf2ee4 mov r0, r4 */
/* @0xf2ee8 mov r1, r9 */
/* @0xf2eec mov r2, r8 */
/* @0xf2ef0 bl 0x19da74 <_ZN9CObjectGM14GetEventDirectEii> */
/* @0xf2ef4 cmp r0, #0 */
/* @0xf2ef8 popne {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xf2efc ldr r0, [r4, #0xc] */
/* @0xf2f00 cmp r0, #0 */
/* @0xf2f04 blt 0xf2f6c <_Z10Find_EventiiiRi+0xec> */
/* @0xf2f08 bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0xf2f0c cmp r0, #0 */
/* @0xf2f10 beq 0xf2f6c <_Z10Find_EventiiiRi+0xec> */
/* @0xf2f14 ldr r2, [r6] */
/* @0xf2f18 ldr r3, [r4, #0xc] */
/* @0xf2f1c str r3, [r7] */
/* @0xf2f20 ldr r1, [r2, #0x4] */
/* @0xf2f24 ldr r3, [r4, #0xc] */
/* @0xf2f28 ldr r2, [r2] */
/* @0xf2f2c and r1, r3, r1 */
/* @0xf2f30 ldr r12, [r2, r1, lsl #3] */
/* @0xf2f34 cmp r12, #0 */
/* @0xf2f38 beq 0xf2f6c <_Z10Find_EventiiiRi+0xec> */
/* @0xf2f3c ldr r2, [r12, #0x8] */
/* @0xf2f40 cmp r3, r2 */
/* @0xf2f44 beq 0xf2f60 <_Z10Find_EventiiiRi+0xe0> */
/* @0xf2f48 ldr r12, [r12, #0x4] */
/* @0xf2f4c cmp r12, #0 */
/* @0xf2f50 beq 0xf2f6c <_Z10Find_EventiiiRi+0xec> */
/* @0xf2f54 ldr r4, [r12, #0x8] */
/* @0xf2f58 cmp r3, r4 */
/* @0xf2f5c bne 0xf2f48 <_Z10Find_EventiiiRi+0xc8> */
/* @0xf2f60 ldr r4, [r12, #0xc] */
/* @0xf2f64 cmp r4, #0 */
/* @0xf2f68 bne 0xf2ee4 <_Z10Find_EventiiiRi+0x64> */
/* @0xf2f6c cmp r9, #4 */
/* @0xf2f70 beq 0xf2f7c <_Z10Find_EventiiiRi+0xfc> */
/* @0xf2f74 mov r0, #0 */
/* @0xf2f78 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xf2f7c mov r0, r8 */
/* @0xf2f80 bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0xf2f84 cmp r0, #0 */
/* @0xf2f88 beq 0xf2f74 <_Z10Find_EventiiiRi+0xf4> */
/* @0xf2f8c ldr r3, [r6] */
/* @0xf2f90 ldr r2, [r3, #0x4] */
/* @0xf2f94 ldr r3, [r3] */
/* @0xf2f98 and r2, r8, r2 */
/* @0xf2f9c ldr r3, [r3, r2, lsl #3] */
/* @0xf2fa0 cmp r3, #0 */
/* @0xf2fa4 bne 0xf2fb8 <_Z10Find_EventiiiRi+0x138> */
/* @0xf2fa8 b 0xf2fc8 <_Z10Find_EventiiiRi+0x148> */
/* @0xf2fac ldr r3, [r3, #0x4] */
/* @0xf2fb0 cmp r3, #0 */
/* @0xf2fb4 beq 0xf2fc8 <_Z10Find_EventiiiRi+0x148> */
/* @0xf2fb8 ldr r2, [r3, #0x8] */
/* @0xf2fbc cmp r8, r2 */
/* @0xf2fc0 bne 0xf2fac <_Z10Find_EventiiiRi+0x12c> */
/* @0xf2fc4 ldr r3, [r3, #0xc] */
/* @0xf2fc8 ldr r8, [r3, #0xc] */
/* @0xf2fcc cmp r8, #0 */
/* @0xf2fd0 blt 0xf2f74 <_Z10Find_EventiiiRi+0xf4> */
/* @0xf2fd4 mov r0, r8 */
/* @0xf2fd8 bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0xf2fdc cmp r0, #0 */
/* @0xf2fe0 beq 0xf2f74 <_Z10Find_EventiiiRi+0xf4> */
/* @0xf2fe4 ldr r3, [r6] */
/* @0xf2fe8 str r5, [r7] */
/* @0xf2fec ldm r3, {r0, r9} */
/* @0xf2ff0 and r3, r5, r9 */
/* @0xf2ff4 ldr r3, [r0, r3, lsl #3] */
/* @0xf2ff8 cmp r3, #0 */
/* @0xf2ffc bne 0xf3010 <_Z10Find_EventiiiRi+0x190> */
/* @0xf3000 b 0xf30b8 <_Z10Find_EventiiiRi+0x238> */
/* @0xf3004 ldr r3, [r3, #0x4] */
/* @0xf3008 cmp r3, #0 */
/* @0xf300c beq 0xf30b8 <_Z10Find_EventiiiRi+0x238> */
/* @0xf3010 ldr r2, [r3, #0x8] */
/* @0xf3014 cmp r5, r2 */
/* @0xf3018 bne 0xf3004 <_Z10Find_EventiiiRi+0x184> */
/* @0xf301c ldr r4, [r3, #0xc] */
/* @0xf3020 cmp r4, #0 */
/* @0xf3024 beq 0xf30b8 <_Z10Find_EventiiiRi+0x238> */
/* @0xf3028 mov r0, r4 */
/* @0xf302c mov r1, #4 */
/* @0xf3030 mov r2, r8 */
/* @0xf3034 bl 0x19da74 <_ZN9CObjectGM14GetEventDirectEii> */
/* @0xf3038 cmp r0, #0 */
/* @0xf303c popne {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xf3040 ldr r0, [r4, #0xc] */
/* @0xf3044 cmp r0, #0 */
/* @0xf3048 blt 0xf30b0 <_Z10Find_EventiiiRi+0x230> */
/* @0xf304c bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0xf3050 cmp r0, #0 */
/* @0xf3054 beq 0xf30b0 <_Z10Find_EventiiiRi+0x230> */
/* @0xf3058 ldr r3, [r6] */
/* @0xf305c ldr r2, [r4, #0xc] */
/* @0xf3060 str r2, [r7] */
/* @0xf3064 ldm r3, {r0, r9} */
/* @0xf3068 ldr r4, [r4, #0xc] */
/* @0xf306c and r3, r4, r9 */
/* @0xf3070 ldr r1, [r0, r3, lsl #3] */
/* @0xf3074 cmp r1, #0 */
/* @0xf3078 beq 0xf30b8 <_Z10Find_EventiiiRi+0x238> */
/* @0xf307c ldr r3, [r1, #0x8] */
/* @0xf3080 cmp r4, r3 */
/* @0xf3084 beq 0xf30a0 <_Z10Find_EventiiiRi+0x220> */
/* @0xf3088 ldr r1, [r1, #0x4] */
/* @0xf308c cmp r1, #0 */
/* @0xf3090 beq 0xf30b8 <_Z10Find_EventiiiRi+0x238> */
/* @0xf3094 ldr r12, [r1, #0x8] */
/* @0xf3098 cmp r4, r12 */
/* @0xf309c bne 0xf3088 <_Z10Find_EventiiiRi+0x208> */
/* @0xf30a0 ldr r4, [r1, #0xc] */
/* @0xf30a4 cmp r4, #0 */
/* @0xf30a8 bne 0xf3028 <_Z10Find_EventiiiRi+0x1a8> */
/* @0xf30ac b 0xf30b8 <_Z10Find_EventiiiRi+0x238> */
/* @0xf30b0 ldr r3, [r6] */
/* @0xf30b4 ldm r3, {r0, r9} */
/* @0xf30b8 and r9, r9, r8 */
/* @0xf30bc ldr r3, [r0, r9, lsl #3] */
/* @0xf30c0 cmp r3, #0 */
/* @0xf30c4 bne 0xf30d8 <_Z10Find_EventiiiRi+0x258> */
/* @0xf30c8 b 0xf2fc8 <_Z10Find_EventiiiRi+0x148> */
/* @0xf30cc ldr r3, [r3, #0x4] */
/* @0xf30d0 cmp r3, #0 */
/* @0xf30d4 beq 0xf2fc8 <_Z10Find_EventiiiRi+0x148> */
/* @0xf30d8 ldr r2, [r3, #0x8] */
/* @0xf30dc cmp r8, r2 */
/* @0xf30e0 bne 0xf30cc <_Z10Find_EventiiiRi+0x24c> */
/* @0xf30e4 b 0xf2fc4 <_Z10Find_EventiiiRi+0x144> */
/* @0xf30e8 eoreq r10, pc, r4, lsr #27 */

/* ── FUNC 0xf30ec · Perform_Event_TimeLine(CInstance*, CInstance*, int, int) · size=268 · insn=67 */
/* @0xf30ec push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xf30f0 mov r7, r0 */
/* @0xf30f4 ldr r4, [pc, #0xe8] */
/* @0xf30f8 sub sp, sp, #36 */
/* @0xf30fc ldr r12, [pc, #0xe4] */
/* @0xf3100 mov r6, r1 */
/* @0xf3104 add r4, pc, r4 */
/* @0xf3108 mov r5, r2 */
/* @0xf310c mov r8, r3 */
/* @0xf3110 ldr r12, [r4, r12] */
/* @0xf3114 ldr r12, [r12] */
/* @0xf3118 cmn r12, #1 */
/* @0xf311c beq 0xf3128 <_Z22Perform_Event_TimeLineP9CInstanceS0_ii+0x3c> */
/* @0xf3120 add sp, sp, #36 */
/* @0xf3124 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xf3128 mov r0, r2 */
/* @0xf312c bl 0x1f2c48 <_Z13TimeLine_Datai> */
/* @0xf3130 subs r9, r0, #0 */
/* @0xf3134 beq 0xf3120 <_Z22Perform_Event_TimeLineP9CInstanceS0_ii+0x34> */
/* @0xf3138 mov r1, r8 */
/* @0xf313c bl 0x1f1710 <_ZN9CTimeLine8GetEventEi> */
/* @0xf3140 subs r2, r0, #0 */
/* @0xf3144 beq 0xf3120 <_Z22Perform_Event_TimeLineP9CInstanceS0_ii+0x34> */
/* @0xf3148 ldr r10, [pc, #0x9c] */
/* @0xf314c mov r0, r9 */
/* @0xf3150 ldr lr, [pc, #0x98] */
/* @0xf3154 mov r1, r8 */
/* @0xf3158 ldr r12, [pc, #0x94] */
/* @0xf315c movw r3, #0x86a0 */
/* @0xf3160 ldr r9, [r4, r10] */
/* @0xf3164 movt r3, #0x1 */
/* @0xf3168 ldr r8, [r4, lr] */
/* @0xf316c ldr r4, [r4, r12] */
/* @0xf3170 ldr r11, [r9] */
/* @0xf3174 ldr r10, [r8] */
/* @0xf3178 str r5, [r9] */
/* @0xf317c str r3, [r8] */
/* @0xf3180 ldr r5, [r4] */
/* @0xf3184 str r2, [sp, #0xc] */
/* @0xf3188 bl 0x1f1738 <_ZN9CTimeLine7GetStepEi> */
/* @0xf318c ldr r2, [sp, #0xc] */
/* @0xf3190 tst r2, #1 */
/* @0xf3194 str r0, [r4] */
/* @0xf3198 beq 0xf31d0 <_Z22Perform_Event_TimeLineP9CInstanceS0_ii+0xe4> */
/* @0xf319c mov r3, #0 */
/* @0xf31a0 asr r0, r2, #1 */
/* @0xf31a4 add r12, sp, #16 */
/* @0xf31a8 mov r1, r7 */
/* @0xf31ac mov r2, r6 */
/* @0xf31b0 str r3, [sp, #0x4] */
/* @0xf31b4 str r12, [sp] */
/* @0xf31b8 bl 0x1e0774 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue> */
/* @0xf31bc str r11, [r9] */
/* @0xf31c0 str r10, [r8] */
/* @0xf31c4 str r5, [r4] */
/* @0xf31c8 add sp, sp, #36 */
/* @0xf31cc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xf31d0 mov r0, r2 */
/* @0xf31d4 mov r1, r7 */
/* @0xf31d8 mov r2, r6 */
/* @0xf31dc bl 0xf2e34 <_ZN6CEvent7ExecuteEP9CInstanceS1_> */
/* @0xf31e0 b 0xf31bc <_Z22Perform_Event_TimeLineP9CInstanceS0_ii+0xd0> */
/* @0xf31e4 eoreq lr, pc, r12, asr #22 */
/* @0xf31e8 .word 0xffffc154 */
/* @0xf31ec .word 0xffffc168 */
/* @0xf31f0 .word 0xffffc160 */
/* @0xf31f4 .word 0xffffc164 */

/* ── FUNC 0xf31f8 · Perform_Event_Object_ASync(CInstance*, CInstance*, int, int, int) · size=236 · insn=59 */
/* @0xf31f8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xf31fc sub sp, sp, #12 */
/* @0xf3200 mov r8, r3 */
/* @0xf3204 add r3, sp, #8 */
/* @0xf3208 ldr r7, [sp, #0x30] */
/* @0xf320c mov r5, r0 */
/* @0xf3210 mov r4, r1 */
/* @0xf3214 mov r0, r2 */
/* @0xf3218 mov r1, r8 */
/* @0xf321c mov r2, #0 */
/* @0xf3220 str r2, [r3, #-0x4]! */
/* @0xf3224 mov r2, r7 */
/* @0xf3228 bl 0xf2e80 <_Z10Find_EventiiiRi> */
/* @0xf322c cmp r0, #0 */
/* @0xf3230 beq 0xf32b0 <_Z26Perform_Event_Object_ASyncP9CInstanceS0_iii+0xb8> */
/* @0xf3234 ldr lr, [pc, #0x90] */
/* @0xf3238 add lr, pc, lr */
/* @0xf323c ldr r12, [lr] */
/* @0xf3240 add r12, r12, #1 */
/* @0xf3244 str r12, [lr] */
/* @0xf3248 cmp r12, #32 */
/* @0xf324c bgt 0xf32b8 <_Z26Perform_Event_Object_ASyncP9CInstanceS0_iii+0xc0> */
/* @0xf3250 mov r1, r5 */
/* @0xf3254 mov r2, r4 */
/* @0xf3258 ldr r6, [pc, #0x70] */
/* @0xf325c ldr r5, [pc, #0x70] */
/* @0xf3260 ldr r4, [pc, #0x70] */
/* @0xf3264 ldr r6, [pc, r6] */
/* @0xf3268 ldr r5, [pc, r5] */
/* @0xf326c ldr r3, [sp, #0x4] */
/* @0xf3270 ldr r4, [pc, r4] */
/* @0xf3274 ldr r11, [r6] */
/* @0xf3278 ldr r10, [r5] */
/* @0xf327c ldr r9, [r4] */
/* @0xf3280 str r3, [r6] */
/* @0xf3284 str r8, [r5] */
/* @0xf3288 str r7, [r4] */
/* @0xf328c bl 0xf2e34 <_ZN6CEvent7ExecuteEP9CInstanceS1_> */
/* @0xf3290 str r11, [r6] */
/* @0xf3294 str r10, [r5] */
/* @0xf3298 str r9, [r4] */
/* @0xf329c ldr r3, [pc, #0x38] */
/* @0xf32a0 add r3, pc, r3 */
/* @0xf32a4 ldr r2, [r3] */
/* @0xf32a8 sub r2, r2, #1 */
/* @0xf32ac str r2, [r3] */
/* @0xf32b0 add sp, sp, #12 */
/* @0xf32b4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xf32b8 ldr r0, [pc, #0x20] */
/* @0xf32bc mov r1, #1 */
/* @0xf32c0 add r0, pc, r0 */
/* @0xf32c4 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xf32c8 b 0xf329c <_Z26Perform_Event_Object_ASyncP9CInstanceS0_iii+0xa4> */
/* @0xf32cc eorseq r0, r9, r12, asr #3 */
/* @0xf32d0 eoreq r10, pc, r4, asr r11 */
/* @0xf32d4 eoreq r10, pc, r8, asr #22 */
/* @0xf32d8 eoreq r10, pc, r4, asr #22 */
/* @0xf32dc eorseq r0, r9, r4, ror #2 */
/* @0xf32e0 eoreq r3, r4, r8, asr #25 */

/* ── FUNC 0xf32e4 · Perform_Event_Object(CInstance*, CInstance*, int, int, int) · size=156 · insn=39 */
/* @0xf32e4 cmp r3, #12 */
/* @0xf32e8 str r4, [sp, #-0x4]! */
/* @0xf32ec ldr r4, [sp, #0x4] */
/* @0xf32f0 beq 0xf3354 <_Z20Perform_Event_ObjectP9CInstanceS0_iii+0x70> */
/* @0xf32f4 ldr r12, [pc, #0x78] */
/* @0xf32f8 ldr r12, [pc, r12] */
/* @0xf32fc ldr r12, [r12] */
/* @0xf3300 cmn r12, #1 */
/* @0xf3304 beq 0xf3348 <_Z20Perform_Event_ObjectP9CInstanceS0_iii+0x64> */
/* @0xf3308 ldrb r12, [r0, #0x67] */
/* @0xf330c cmp r12, #0 */
/* @0xf3310 bne 0xf3334 <_Z20Perform_Event_ObjectP9CInstanceS0_iii+0x50> */
/* @0xf3314 ldr r12, [pc, #0x5c] */
/* @0xf3318 ldr r12, [pc, r12] */
/* @0xf331c ldr r12, [r12] */
/* @0xf3320 ldrb r12, [r12, #0x18] */
/* @0xf3324 cmp r12, #0 */
/* @0xf3328 bne 0xf3334 <_Z20Perform_Event_ObjectP9CInstanceS0_iii+0x50> */
/* @0xf332c ldr r4, [sp], #4 */
/* @0xf3330 bx lr */
/* @0xf3334 cmp r3, #14 */
/* @0xf3338 cmpne r3, #2 */
/* @0xf333c bls 0xf3348 <_Z20Perform_Event_ObjectP9CInstanceS0_iii+0x64> */
/* @0xf3340 cmp r3, #7 */
/* @0xf3344 bne 0xf332c <_Z20Perform_Event_ObjectP9CInstanceS0_iii+0x48> */
/* @0xf3348 str r4, [sp, #0x4] */
/* @0xf334c ldr r4, [sp], #4 */
/* @0xf3350 b 0xf31f8 <_Z26Perform_Event_Object_ASyncP9CInstanceS0_iii> */
/* @0xf3354 ldr r12, [pc, #0x20] */
/* @0xf3358 ldr r12, [pc, r12] */
/* @0xf335c ldrb r12, [r12] */
/* @0xf3360 cmp r12, #0 */
/* @0xf3364 bne 0xf332c <_Z20Perform_Event_ObjectP9CInstanceS0_iii+0x48> */
/* @0xf3368 str r4, [sp, #0x4] */
/* @0xf336c ldr r4, [sp], #4 */
/* @0xf3370 b 0xf31f8 <_Z26Perform_Event_Object_ASyncP9CInstanceS0_iii> */
/* @0xf3374 eoreq r10, pc, r12, lsr #21 */
/* @0xf3378 eoreq r10, pc, r0, lsl r6 */
/* @0xf337c eoreq r10, pc, r12, lsl #16 */

/* ── FUNC 0xf3380 · Perform_Event(CInstance*, CInstance*, int, int) · size=48 · insn=12 */
/* @0xf3380 subs r12, r0, #0 */
/* @0xf3384 push {r4, lr} */
/* @0xf3388 mov r4, r3 */
/* @0xf338c sub sp, sp, #8 */
/* @0xf3390 beq 0xf33a8 <_Z13Perform_EventP9CInstanceS0_ii+0x28> */
/* @0xf3394 ldr r12, [r12, #0x7c] */
/* @0xf3398 mov r3, r2 */
/* @0xf339c str r4, [sp] */
/* @0xf33a0 mov r2, r12 */
/* @0xf33a4 bl 0xf32e4 <_Z20Perform_Event_ObjectP9CInstanceS0_iii> */
/* @0xf33a8 add sp, sp, #8 */
/* @0xf33ac pop {r4, pc} */

/* ── FUNC 0xf33b0 · Perform_Event_All(int, int) · size=156 · insn=39 */
/* @0xf33b0 ldr r2, [pc, #0x8c] */
/* @0xf33b4 push {r4, r5, r6, lr} */
/* @0xf33b8 ldr r2, [pc, r2] */
/* @0xf33bc sub sp, sp, #8 */
/* @0xf33c0 mov r5, r0 */
/* @0xf33c4 ldr r3, [r2] */
/* @0xf33c8 mov r6, r1 */
/* @0xf33cc cmn r3, #1 */
/* @0xf33d0 beq 0xf33dc <_Z17Perform_Event_Allii+0x2c> */
/* @0xf33d4 add sp, sp, #8 */
/* @0xf33d8 pop {r4, r5, r6, pc} */
/* @0xf33dc ldr r3, [pc, #0x64] */
/* @0xf33e0 ldr r3, [pc, r3] */
/* @0xf33e4 ldr r3, [r3] */
/* @0xf33e8 cmp r3, #0 */
/* @0xf33ec beq 0xf33d4 <_Z17Perform_Event_Allii+0x24> */
/* @0xf33f0 ldr r2, [r3, #0x80] */
/* @0xf33f4 cmp r2, #0 */
/* @0xf33f8 beq 0xf33d4 <_Z17Perform_Event_Allii+0x24> */
/* @0xf33fc ldrb r12, [r2, #0x68] */
/* @0xf3400 ldr r4, [r2, #0x178] */
/* @0xf3404 cmp r12, #0 */
/* @0xf3408 bne 0xf3430 <_Z17Perform_Event_Allii+0x80> */
/* @0xf340c ldrb r12, [r2, #0x69] */
/* @0xf3410 mov r0, r2 */
/* @0xf3414 mov r1, r2 */
/* @0xf3418 mov r3, r5 */
/* @0xf341c cmp r12, #0 */
/* @0xf3420 bne 0xf3430 <_Z17Perform_Event_Allii+0x80> */
/* @0xf3424 ldr r2, [r2, #0x7c] */
/* @0xf3428 str r6, [sp] */
/* @0xf342c bl 0xf32e4 <_Z20Perform_Event_ObjectP9CInstanceS0_iii> */
/* @0xf3430 cmp r4, #0 */
/* @0xf3434 mov r2, r4 */
/* @0xf3438 bne 0xf33fc <_Z17Perform_Event_Allii+0x4c> */
/* @0xf343c add sp, sp, #8 */
/* @0xf3440 pop {r4, r5, r6, pc} */
/* @0xf3444 eoreq r10, pc, r12, ror #19 */
/* @0xf3448 eoreq r10, pc, r8, asr #10 */

/* ── FUNC 0xf344c · StepToStr(int) · size=64 · insn=16 */
/* @0xf344c cmp r0, #1 */
/* @0xf3450 beq 0xf3474 <_Z9StepToStri+0x28> */
/* @0xf3454 cmp r0, #2 */
/* @0xf3458 bne 0xf3468 <_Z9StepToStri+0x1c> */
/* @0xf345c ldr r0, [pc, #0x1c] */
/* @0xf3460 add r0, pc, r0 */
/* @0xf3464 bx lr */
/* @0xf3468 ldr r0, [pc, #0x14] */
/* @0xf346c add r0, pc, r0 */
/* @0xf3470 bx lr */
/* @0xf3474 ldr r0, [pc, #0xc] */
/* @0xf3478 add r0, pc, r0 */
/* @0xf347c bx lr */
/* @0xf3480 mlaeq r4, r0, r11, r3 */
/* @0xf3484 eoreq r11, r3, r10, asr #13 */
/* @0xf3488 eoreq r3, r4, r0, ror r11 */

/* ── FUNC 0xf348c · KeyToStr(int) · size=1124 · insn=281 */
/* @0xf348c push {r3, r4, r5, lr} */
/* @0xf3490 mov r4, r0 */
/* @0xf3494 cmp r0, #111 */
/* @0xf3498 addls pc, pc, r0, lsl #2 */
/* @0xf349c b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf34a0 b 0xf36c0 <_Z8KeyToStri+0x234> */
/* @0xf34a4 b 0xf36b4 <_Z8KeyToStri+0x228> */
/* @0xf34a8 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf34ac b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf34b0 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf34b4 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf34b8 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf34bc b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf34c0 b 0xf3660 <_Z8KeyToStri+0x1d4> */
/* @0xf34c4 b 0xf37c8 <_Z8KeyToStri+0x33c> */
/* @0xf34c8 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf34cc b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf34d0 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf34d4 b 0xf37bc <_Z8KeyToStri+0x330> */
/* @0xf34d8 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf34dc b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf34e0 b 0xf37b0 <_Z8KeyToStri+0x324> */
/* @0xf34e4 b 0xf37a4 <_Z8KeyToStri+0x318> */
/* @0xf34e8 b 0xf3798 <_Z8KeyToStri+0x30c> */
/* @0xf34ec b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf34f0 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf34f4 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf34f8 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf34fc b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf3500 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf3504 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf3508 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf350c b 0xf378c <_Z8KeyToStri+0x300> */
/* @0xf3510 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf3514 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf3518 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf351c b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf3520 b 0xf3780 <_Z8KeyToStri+0x2f4> */
/* @0xf3524 b 0xf3774 <_Z8KeyToStri+0x2e8> */
/* @0xf3528 b 0xf3768 <_Z8KeyToStri+0x2dc> */
/* @0xf352c b 0xf375c <_Z8KeyToStri+0x2d0> */
/* @0xf3530 b 0xf3750 <_Z8KeyToStri+0x2c4> */
/* @0xf3534 b 0xf3744 <_Z8KeyToStri+0x2b8> */
/* @0xf3538 b 0xf3738 <_Z8KeyToStri+0x2ac> */
/* @0xf353c b 0xf372c <_Z8KeyToStri+0x2a0> */
/* @0xf3540 b 0xf3720 <_Z8KeyToStri+0x294> */
/* @0xf3544 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf3548 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf354c b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf3550 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf3554 b 0xf3714 <_Z8KeyToStri+0x288> */
/* @0xf3558 b 0xf36f0 <_Z8KeyToStri+0x264> */
/* @0xf355c b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf3560 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf3564 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf3568 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf356c b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf3570 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf3574 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf3578 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf357c b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf3580 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf3584 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf3588 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf358c b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf3590 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf3594 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf3598 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf359c b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf35a0 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf35a4 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf35a8 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf35ac b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf35b0 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf35b4 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf35b8 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf35bc b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf35c0 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf35c4 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf35c8 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf35cc b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf35d0 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf35d4 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf35d8 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf35dc b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf35e0 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf35e4 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf35e8 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf35ec b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf35f0 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf35f4 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf35f8 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf35fc b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf3600 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf3604 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf3608 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf360c b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf3610 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf3614 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf3618 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf361c b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf3620 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf3624 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf3628 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf362c b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf3630 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf3634 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf3638 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf363c b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf3640 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf3644 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf3648 b 0xf36e4 <_Z8KeyToStri+0x258> */
/* @0xf364c b 0xf36d8 <_Z8KeyToStri+0x24c> */
/* @0xf3650 b 0xf37d4 <_Z8KeyToStri+0x348> */
/* @0xf3654 b 0xf36cc <_Z8KeyToStri+0x240> */
/* @0xf3658 b 0xf3708 <_Z8KeyToStri+0x27c> */
/* @0xf365c b 0xf36fc <_Z8KeyToStri+0x270> */
/* @0xf3660 ldr r0, [pc, #0x200] */
/* @0xf3664 add r0, pc, r0 */
/* @0xf3668 sub r3, r4, #65 */
/* @0xf366c cmp r3, #25 */
/* @0xf3670 bls 0xf3810 <_Z8KeyToStri+0x384> */
/* @0xf3674 sub r3, r4, #96 */
/* @0xf3678 cmp r3, #9 */
/* @0xf367c bls 0xf3838 <_Z8KeyToStri+0x3ac> */
/* @0xf3680 sub r3, r4, #112 */
/* @0xf3684 cmp r3, #11 */
/* @0xf3688 pophi {r3, r4, r5, pc} */
/* @0xf368c ldr r0, [pc, #0x1d8] */
/* @0xf3690 sub r3, r4, #111 */
/* @0xf3694 ldr r2, [pc, #0x1d4] */
/* @0xf3698 mov r1, #64 */
/* @0xf369c add r0, pc, r0 */
/* @0xf36a0 add r2, pc, r2 */
/* @0xf36a4 mov r4, r0 */
/* @0xf36a8 bl 0xb65c8 <snprintf@plt> */
/* @0xf36ac mov r0, r4 */
/* @0xf36b0 pop {r3, r4, r5, pc} */
/* @0xf36b4 ldr r0, [pc, #0x1b8] */
/* @0xf36b8 add r0, pc, r0 */
/* @0xf36bc b 0xf3668 <_Z8KeyToStri+0x1dc> */
/* @0xf36c0 ldr r0, [pc, #0x1b0] */
/* @0xf36c4 add r0, pc, r0 */
/* @0xf36c8 b 0xf3668 <_Z8KeyToStri+0x1dc> */
/* @0xf36cc ldr r0, [pc, #0x1a8] */
/* @0xf36d0 add r0, pc, r0 */
/* @0xf36d4 b 0xf3668 <_Z8KeyToStri+0x1dc> */
/* @0xf36d8 ldr r0, [pc, #0x1a0] */
/* @0xf36dc add r0, pc, r0 */
/* @0xf36e0 b 0xf3668 <_Z8KeyToStri+0x1dc> */
/* @0xf36e4 ldr r0, [pc, #0x198] */
/* @0xf36e8 add r0, pc, r0 */
/* @0xf36ec b 0xf3668 <_Z8KeyToStri+0x1dc> */
/* @0xf36f0 ldr r0, [pc, #0x190] */
/* @0xf36f4 add r0, pc, r0 */
/* @0xf36f8 b 0xf3668 <_Z8KeyToStri+0x1dc> */
/* @0xf36fc ldr r0, [pc, #0x188] */
/* @0xf3700 add r0, pc, r0 */
/* @0xf3704 b 0xf3668 <_Z8KeyToStri+0x1dc> */
/* @0xf3708 ldr r0, [pc, #0x180] */
/* @0xf370c add r0, pc, r0 */
/* @0xf3710 b 0xf3668 <_Z8KeyToStri+0x1dc> */
/* @0xf3714 ldr r0, [pc, #0x178] */
/* @0xf3718 add r0, pc, r0 */
/* @0xf371c b 0xf3668 <_Z8KeyToStri+0x1dc> */
/* @0xf3720 ldr r0, [pc, #0x170] */
/* @0xf3724 add r0, pc, r0 */
/* @0xf3728 b 0xf3668 <_Z8KeyToStri+0x1dc> */
/* @0xf372c ldr r0, [pc, #0x168] */
/* @0xf3730 add r0, pc, r0 */
/* @0xf3734 b 0xf3668 <_Z8KeyToStri+0x1dc> */
/* @0xf3738 ldr r0, [pc, #0x160] */
/* @0xf373c add r0, pc, r0 */
/* @0xf3740 b 0xf3668 <_Z8KeyToStri+0x1dc> */
/* @0xf3744 ldr r0, [pc, #0x158] */
/* @0xf3748 add r0, pc, r0 */
/* @0xf374c b 0xf3668 <_Z8KeyToStri+0x1dc> */
/* @0xf3750 ldr r0, [pc, #0x150] */
/* @0xf3754 add r0, pc, r0 */
/* @0xf3758 b 0xf3668 <_Z8KeyToStri+0x1dc> */
/* @0xf375c ldr r0, [pc, #0x148] */
/* @0xf3760 add r0, pc, r0 */
/* @0xf3764 b 0xf3668 <_Z8KeyToStri+0x1dc> */
/* @0xf3768 ldr r0, [pc, #0x140] */
/* @0xf376c add r0, pc, r0 */
/* @0xf3770 b 0xf3668 <_Z8KeyToStri+0x1dc> */
/* @0xf3774 ldr r0, [pc, #0x138] */
/* @0xf3778 add r0, pc, r0 */
/* @0xf377c b 0xf3668 <_Z8KeyToStri+0x1dc> */
/* @0xf3780 ldr r0, [pc, #0x130] */
/* @0xf3784 add r0, pc, r0 */
/* @0xf3788 b 0xf3668 <_Z8KeyToStri+0x1dc> */
/* @0xf378c ldr r0, [pc, #0x128] */
/* @0xf3790 add r0, pc, r0 */
/* @0xf3794 b 0xf3668 <_Z8KeyToStri+0x1dc> */
/* @0xf3798 ldr r0, [pc, #0x120] */
/* @0xf379c add r0, pc, r0 */
/* @0xf37a0 b 0xf3668 <_Z8KeyToStri+0x1dc> */
/* @0xf37a4 ldr r0, [pc, #0x118] */
/* @0xf37a8 add r0, pc, r0 */
/* @0xf37ac b 0xf3668 <_Z8KeyToStri+0x1dc> */
/* @0xf37b0 ldr r0, [pc, #0x110] */
/* @0xf37b4 add r0, pc, r0 */
/* @0xf37b8 b 0xf3668 <_Z8KeyToStri+0x1dc> */
/* @0xf37bc ldr r0, [pc, #0x108] */
/* @0xf37c0 add r0, pc, r0 */
/* @0xf37c4 b 0xf3668 <_Z8KeyToStri+0x1dc> */
/* @0xf37c8 ldr r0, [pc, #0x100] */
/* @0xf37cc add r0, pc, r0 */
/* @0xf37d0 b 0xf3668 <_Z8KeyToStri+0x1dc> */
/* @0xf37d4 sub r3, r0, #48 */
/* @0xf37d8 cmp r3, #9 */
/* @0xf37dc bhi 0xf385c <_Z8KeyToStri+0x3d0> */
/* @0xf37e0 ldr r5, [pc, #0xec] */
/* @0xf37e4 mov r3, r0 */
/* @0xf37e8 ldr r2, [pc, #0xe8] */
/* @0xf37ec mov r1, #64 */
/* @0xf37f0 add r5, pc, r5 */
/* @0xf37f4 add r2, pc, r2 */
/* @0xf37f8 mov r0, r5 */
/* @0xf37fc bl 0xb65c8 <snprintf@plt> */
/* @0xf3800 sub r3, r4, #65 */
/* @0xf3804 cmp r3, #25 */
/* @0xf3808 mov r0, r5 */
/* @0xf380c bhi 0xf3674 <_Z8KeyToStri+0x1e8> */
/* @0xf3810 ldr r0, [pc, #0xc4] */
/* @0xf3814 mov r3, r4 */
/* @0xf3818 ldr r2, [pc, #0xc0] */
/* @0xf381c mov r1, #64 */
/* @0xf3820 add r0, pc, r0 */
/* @0xf3824 add r2, pc, r2 */
/* @0xf3828 mov r4, r0 */
/* @0xf382c bl 0xb65c8 <snprintf@plt> */
/* @0xf3830 mov r0, r4 */
/* @0xf3834 pop {r3, r4, r5, pc} */
/* @0xf3838 ldr r4, [pc, #0xa4] */
/* @0xf383c mov r1, #64 */
/* @0xf3840 ldr r2, [pc, #0xa0] */
/* @0xf3844 add r4, pc, r4 */
/* @0xf3848 add r2, pc, r2 */
/* @0xf384c mov r0, r4 */
/* @0xf3850 bl 0xb65c8 <snprintf@plt> */
/* @0xf3854 mov r0, r4 */
/* @0xf3858 pop {r3, r4, r5, pc} */
/* @0xf385c ldr r0, [pc, #0x88] */
/* @0xf3860 add r0, pc, r0 */
/* @0xf3864 b 0xf3668 <_Z8KeyToStri+0x1dc> */
/* @0xf3868 eoreq r3, r4, r4, ror r10 */
/* @0xf386c eorseq pc, r8, r12, ror #26 */
/* @0xf3870 eoreq r3, r4, r0, ror r10 */
/* @0xf3874 eoreq r3, r4, r12, lsr #20 */
/* @0xf3878 eoreq r3, r4, r12, lsr #20 */
/* @0xf387c eoreq r3, r4, r8, asr #18 */
/* @0xf3880 eoreq r3, r4, r8, asr #18 */
/* @0xf3884 eoreq r3, r4, r8, asr #18 */
/* @0xf3888 eoreq r3, r4, r8, asr #18 */
/* @0xf388c eoreq r3, r4, r0, lsl #18 */
/* @0xf3890 eoreq r3, r4, r0, lsl #18 */
/* @0xf3894 eoreq r3, r4, r0, lsr r9 */
/* @0xf3898 eoreq r3, r4, r0, lsr r9 */
/* @0xf389c eoreq r3, r4, r12, lsr #18 */
/* @0xf38a0 eoreq r3, r4, r8, lsr #18 */
/* @0xf38a4 eoreq r3, r4, r4, lsr #18 */
/* @0xf38a8 eoreq r3, r4, r0, lsr #18 */
/* @0xf38ac eoreq r3, r4, r12, lsl r9 */
/* @0xf38b0 eoreq r3, r4, r8, lsl r9 */
/* @0xf38b4 eoreq r3, r4, r8, lsl r9 */
/* @0xf38b8 eoreq r3, r4, r8, lsl r9 */
/* @0xf38bc eoreq r3, r4, r4, lsl r9 */
/* @0xf38c0 eoreq r3, r4, r4, lsl r9 */
/* @0xf38c4 eoreq r3, r4, r0, lsl r9 */
/* @0xf38c8 eoreq r3, r4, r12, lsl #18 */
/* @0xf38cc eoreq r3, r4, r8, lsl #18 */
/* @0xf38d0 eoreq r3, r4, r4, lsl #18 */
/* @0xf38d4 eorseq pc, r8, r8, lsl r12 */
/* @0xf38d8 eoreq r3, r4, r8, lsl #18 */
/* @0xf38dc eorseq pc, r8, r8, ror #23 */
/* @0xf38e0 .word 0x002438d8 */
/* @0xf38e4 eorseq pc, r8, r4, asr #23 */
/* @0xf38e8 .word 0x002438bc */
/* @0xf38ec mlaeq r4, r4, r7, r3 */

/* ── FUNC 0xf38f0 · MouseToStr(int) · size=1028 · insn=257 */
/* @0xf38f0 cmp r0, #61 */
/* @0xf38f4 addls pc, pc, r0, lsl #2 */
/* @0xf38f8 b 0xf3c28 <_Z10MouseToStri+0x338> */
/* @0xf38fc b 0xf39f4 <_Z10MouseToStri+0x104> */
/* @0xf3900 b 0xf3c1c <_Z10MouseToStri+0x32c> */
/* @0xf3904 b 0xf3c10 <_Z10MouseToStri+0x320> */
/* @0xf3908 b 0xf3c04 <_Z10MouseToStri+0x314> */
/* @0xf390c b 0xf3bf8 <_Z10MouseToStri+0x308> */
/* @0xf3910 b 0xf3bec <_Z10MouseToStri+0x2fc> */
/* @0xf3914 b 0xf3be0 <_Z10MouseToStri+0x2f0> */
/* @0xf3918 b 0xf3bd4 <_Z10MouseToStri+0x2e4> */
/* @0xf391c b 0xf3bc8 <_Z10MouseToStri+0x2d8> */
/* @0xf3920 b 0xf3bbc <_Z10MouseToStri+0x2cc> */
/* @0xf3924 b 0xf3bb0 <_Z10MouseToStri+0x2c0> */
/* @0xf3928 b 0xf3ba4 <_Z10MouseToStri+0x2b4> */
/* @0xf392c b 0xf3c28 <_Z10MouseToStri+0x338> */
/* @0xf3930 b 0xf3c28 <_Z10MouseToStri+0x338> */
/* @0xf3934 b 0xf3c28 <_Z10MouseToStri+0x338> */
/* @0xf3938 b 0xf3c28 <_Z10MouseToStri+0x338> */
/* @0xf393c b 0xf3b98 <_Z10MouseToStri+0x2a8> */
/* @0xf3940 b 0xf3b8c <_Z10MouseToStri+0x29c> */
/* @0xf3944 b 0xf3b80 <_Z10MouseToStri+0x290> */
/* @0xf3948 b 0xf3b74 <_Z10MouseToStri+0x284> */
/* @0xf394c b 0xf3c28 <_Z10MouseToStri+0x338> */
/* @0xf3950 b 0xf3b68 <_Z10MouseToStri+0x278> */
/* @0xf3954 b 0xf3b5c <_Z10MouseToStri+0x26c> */
/* @0xf3958 b 0xf3b50 <_Z10MouseToStri+0x260> */
/* @0xf395c b 0xf3b44 <_Z10MouseToStri+0x254> */
/* @0xf3960 b 0xf3b38 <_Z10MouseToStri+0x248> */
/* @0xf3964 b 0xf3b2c <_Z10MouseToStri+0x23c> */
/* @0xf3968 b 0xf3b20 <_Z10MouseToStri+0x230> */
/* @0xf396c b 0xf3b14 <_Z10MouseToStri+0x224> */
/* @0xf3970 b 0xf3c28 <_Z10MouseToStri+0x338> */
/* @0xf3974 b 0xf3c28 <_Z10MouseToStri+0x338> */
/* @0xf3978 b 0xf3b08 <_Z10MouseToStri+0x218> */
/* @0xf397c b 0xf3afc <_Z10MouseToStri+0x20c> */
/* @0xf3980 b 0xf3af0 <_Z10MouseToStri+0x200> */
/* @0xf3984 b 0xf3ae4 <_Z10MouseToStri+0x1f4> */
/* @0xf3988 b 0xf3c28 <_Z10MouseToStri+0x338> */
/* @0xf398c b 0xf3ad8 <_Z10MouseToStri+0x1e8> */
/* @0xf3990 b 0xf3acc <_Z10MouseToStri+0x1dc> */
/* @0xf3994 b 0xf3ac0 <_Z10MouseToStri+0x1d0> */
/* @0xf3998 b 0xf3ab4 <_Z10MouseToStri+0x1c4> */
/* @0xf399c b 0xf3aa8 <_Z10MouseToStri+0x1b8> */
/* @0xf39a0 b 0xf3a9c <_Z10MouseToStri+0x1ac> */
/* @0xf39a4 b 0xf3a90 <_Z10MouseToStri+0x1a0> */
/* @0xf39a8 b 0xf3a84 <_Z10MouseToStri+0x194> */
/* @0xf39ac b 0xf3c28 <_Z10MouseToStri+0x338> */
/* @0xf39b0 b 0xf3c28 <_Z10MouseToStri+0x338> */
/* @0xf39b4 b 0xf3c28 <_Z10MouseToStri+0x338> */
/* @0xf39b8 b 0xf3c28 <_Z10MouseToStri+0x338> */
/* @0xf39bc b 0xf3c28 <_Z10MouseToStri+0x338> */
/* @0xf39c0 b 0xf3c28 <_Z10MouseToStri+0x338> */
/* @0xf39c4 b 0xf3a78 <_Z10MouseToStri+0x188> */
/* @0xf39c8 b 0xf3a6c <_Z10MouseToStri+0x17c> */
/* @0xf39cc b 0xf3a60 <_Z10MouseToStri+0x170> */
/* @0xf39d0 b 0xf3a54 <_Z10MouseToStri+0x164> */
/* @0xf39d4 b 0xf3a48 <_Z10MouseToStri+0x158> */
/* @0xf39d8 b 0xf3a3c <_Z10MouseToStri+0x14c> */
/* @0xf39dc b 0xf3a30 <_Z10MouseToStri+0x140> */
/* @0xf39e0 b 0xf3a24 <_Z10MouseToStri+0x134> */
/* @0xf39e4 b 0xf3a18 <_Z10MouseToStri+0x128> */
/* @0xf39e8 b 0xf3c28 <_Z10MouseToStri+0x338> */
/* @0xf39ec b 0xf3a0c <_Z10MouseToStri+0x11c> */
/* @0xf39f0 b 0xf3a00 <_Z10MouseToStri+0x110> */
/* @0xf39f4 ldr r0, [pc, #0x238] */
/* @0xf39f8 add r0, pc, r0 */
/* @0xf39fc bx lr */
/* @0xf3a00 ldr r0, [pc, #0x230] */
/* @0xf3a04 add r0, pc, r0 */
/* @0xf3a08 bx lr */
/* @0xf3a0c ldr r0, [pc, #0x228] */
/* @0xf3a10 add r0, pc, r0 */
/* @0xf3a14 bx lr */
/* @0xf3a18 ldr r0, [pc, #0x220] */
/* @0xf3a1c add r0, pc, r0 */
/* @0xf3a20 bx lr */
/* @0xf3a24 ldr r0, [pc, #0x218] */
/* @0xf3a28 add r0, pc, r0 */
/* @0xf3a2c bx lr */
/* @0xf3a30 ldr r0, [pc, #0x210] */
/* @0xf3a34 add r0, pc, r0 */
/* @0xf3a38 bx lr */
/* @0xf3a3c ldr r0, [pc, #0x208] */
/* @0xf3a40 add r0, pc, r0 */
/* @0xf3a44 bx lr */
/* @0xf3a48 ldr r0, [pc, #0x200] */
/* @0xf3a4c add r0, pc, r0 */
/* @0xf3a50 bx lr */
/* @0xf3a54 ldr r0, [pc, #0x1f8] */
/* @0xf3a58 add r0, pc, r0 */
/* @0xf3a5c bx lr */
/* @0xf3a60 ldr r0, [pc, #0x1f0] */
/* @0xf3a64 add r0, pc, r0 */
/* @0xf3a68 bx lr */
/* @0xf3a6c ldr r0, [pc, #0x1e8] */
/* @0xf3a70 add r0, pc, r0 */
/* @0xf3a74 bx lr */
/* @0xf3a78 ldr r0, [pc, #0x1e0] */
/* @0xf3a7c add r0, pc, r0 */
/* @0xf3a80 bx lr */
/* @0xf3a84 ldr r0, [pc, #0x1d8] */
/* @0xf3a88 add r0, pc, r0 */
/* @0xf3a8c bx lr */
/* @0xf3a90 ldr r0, [pc, #0x1d0] */
/* @0xf3a94 add r0, pc, r0 */
/* @0xf3a98 bx lr */
/* @0xf3a9c ldr r0, [pc, #0x1c8] */
/* @0xf3aa0 add r0, pc, r0 */
/* @0xf3aa4 bx lr */
/* @0xf3aa8 ldr r0, [pc, #0x1c0] */
/* @0xf3aac add r0, pc, r0 */
/* @0xf3ab0 bx lr */
/* @0xf3ab4 ldr r0, [pc, #0x1b8] */
/* @0xf3ab8 add r0, pc, r0 */
/* @0xf3abc bx lr */
/* @0xf3ac0 ldr r0, [pc, #0x1b0] */
/* @0xf3ac4 add r0, pc, r0 */
/* @0xf3ac8 bx lr */
/* @0xf3acc ldr r0, [pc, #0x1a8] */
/* @0xf3ad0 add r0, pc, r0 */
/* @0xf3ad4 bx lr */
/* @0xf3ad8 ldr r0, [pc, #0x1a0] */
/* @0xf3adc add r0, pc, r0 */
/* @0xf3ae0 bx lr */
/* @0xf3ae4 ldr r0, [pc, #0x198] */
/* @0xf3ae8 add r0, pc, r0 */
/* @0xf3aec bx lr */
/* @0xf3af0 ldr r0, [pc, #0x190] */
/* @0xf3af4 add r0, pc, r0 */
/* @0xf3af8 bx lr */
/* @0xf3afc ldr r0, [pc, #0x188] */
/* @0xf3b00 add r0, pc, r0 */
/* @0xf3b04 bx lr */
/* @0xf3b08 ldr r0, [pc, #0x180] */
/* @0xf3b0c add r0, pc, r0 */
/* @0xf3b10 bx lr */
/* @0xf3b14 ldr r0, [pc, #0x178] */
/* @0xf3b18 add r0, pc, r0 */
/* @0xf3b1c bx lr */
/* @0xf3b20 ldr r0, [pc, #0x170] */
/* @0xf3b24 add r0, pc, r0 */
/* @0xf3b28 bx lr */
/* @0xf3b2c ldr r0, [pc, #0x168] */
/* @0xf3b30 add r0, pc, r0 */
/* @0xf3b34 bx lr */
/* @0xf3b38 ldr r0, [pc, #0x160] */
/* @0xf3b3c add r0, pc, r0 */
/* @0xf3b40 bx lr */
/* @0xf3b44 ldr r0, [pc, #0x158] */
/* @0xf3b48 add r0, pc, r0 */
/* @0xf3b4c bx lr */
/* @0xf3b50 ldr r0, [pc, #0x150] */
/* @0xf3b54 add r0, pc, r0 */
/* @0xf3b58 bx lr */
/* @0xf3b5c ldr r0, [pc, #0x148] */
/* @0xf3b60 add r0, pc, r0 */
/* @0xf3b64 bx lr */
/* @0xf3b68 ldr r0, [pc, #0x140] */
/* @0xf3b6c add r0, pc, r0 */
/* @0xf3b70 bx lr */
/* @0xf3b74 ldr r0, [pc, #0x138] */
/* @0xf3b78 add r0, pc, r0 */
/* @0xf3b7c bx lr */
/* @0xf3b80 ldr r0, [pc, #0x130] */
/* @0xf3b84 add r0, pc, r0 */
/* @0xf3b88 bx lr */
/* @0xf3b8c ldr r0, [pc, #0x128] */
/* @0xf3b90 add r0, pc, r0 */
/* @0xf3b94 bx lr */
/* @0xf3b98 ldr r0, [pc, #0x120] */
/* @0xf3b9c add r0, pc, r0 */
/* @0xf3ba0 bx lr */
/* @0xf3ba4 ldr r0, [pc, #0x118] */
/* @0xf3ba8 add r0, pc, r0 */
/* @0xf3bac bx lr */
/* @0xf3bb0 ldr r0, [pc, #0x110] */
/* @0xf3bb4 add r0, pc, r0 */
/* @0xf3bb8 bx lr */
/* @0xf3bbc ldr r0, [pc, #0x108] */
/* @0xf3bc0 add r0, pc, r0 */
/* @0xf3bc4 bx lr */
/* @0xf3bc8 ldr r0, [pc, #0x100] */
/* @0xf3bcc add r0, pc, r0 */
/* @0xf3bd0 bx lr */
/* @0xf3bd4 ldr r0, [pc, #0xf8] */
/* @0xf3bd8 add r0, pc, r0 */
/* @0xf3bdc bx lr */
/* @0xf3be0 ldr r0, [pc, #0xf0] */
/* @0xf3be4 add r0, pc, r0 */
/* @0xf3be8 bx lr */
/* @0xf3bec ldr r0, [pc, #0xe8] */
/* @0xf3bf0 add r0, pc, r0 */
/* @0xf3bf4 bx lr */
/* @0xf3bf8 ldr r0, [pc, #0xe0] */
/* @0xf3bfc add r0, pc, r0 */
/* @0xf3c00 bx lr */
/* @0xf3c04 ldr r0, [pc, #0xd8] */
/* @0xf3c08 add r0, pc, r0 */
/* @0xf3c0c bx lr */
/* @0xf3c10 ldr r0, [pc, #0xd0] */
/* @0xf3c14 add r0, pc, r0 */
/* @0xf3c18 bx lr */
/* @0xf3c1c ldr r0, [pc, #0xc8] */
/* @0xf3c20 add r0, pc, r0 */
/* @0xf3c24 bx lr */
/* @0xf3c28 ldr r0, [pc, #0xc0] */
/* @0xf3c2c add r0, pc, r0 */
/* @0xf3c30 bx lr */
/* @0xf3c34 eoreq r3, r4, r12, lsl r7 */
/* @0xf3c38 eoreq r3, r4, r0, asr r10 */
/* @0xf3c3c eoreq r3, r4, r4, lsr r10 */
/* @0xf3c40 eoreq r3, r4, r0, lsl r10 */
/* @0xf3c44 .word 0x002439f0 */
/* @0xf3c48 .word 0x002439d0 */
/* @0xf3c4c .word 0x002439b0 */
/* @0xf3c50 mlaeq r4, r0, r9, r3 */
/* @0xf3c54 eoreq r3, r4, r0, ror r9 */
/* @0xf3c58 eoreq r3, r4, r0, asr r9 */
/* @0xf3c5c eoreq r3, r4, r0, lsr r9 */
/* @0xf3c60 eoreq r3, r4, r0, lsl r9 */
/* @0xf3c64 .word 0x002438f0 */
/* @0xf3c68 .word 0x002438d0 */
/* @0xf3c6c .word 0x002438b0 */
/* @0xf3c70 mlaeq r4, r0, r8, r3 */
/* @0xf3c74 eoreq r3, r4, r0, ror r8 */
/* @0xf3c78 eoreq r3, r4, r0, asr r8 */
/* @0xf3c7c eoreq r3, r4, r0, lsr r8 */
/* @0xf3c80 eoreq r3, r4, r0, lsl r8 */
/* @0xf3c84 .word 0x002437f4 */
/* @0xf3c88 .word 0x002437d8 */
/* @0xf3c8c .word 0x002437b8 */
/* @0xf3c90 mlaeq r4, r12, r7, r3 */
/* @0xf3c94 eoreq r3, r4, r12, ror r7 */
/* @0xf3c98 eoreq r3, r4, r12, asr r7 */
/* @0xf3c9c eoreq r3, r4, r12, lsr r7 */
/* @0xf3ca0 eoreq r3, r4, r12, lsl r7 */
/* @0xf3ca4 .word 0x002436fc */
/* @0xf3ca8 .word 0x002436dc */
/* @0xf3cac .word 0x002436bc */
/* @0xf3cb0 mlaeq r4, r12, r6, r3 */
/* @0xf3cb4 eoreq r3, r4, r0, lsl #13 */
/* @0xf3cb8 eoreq r3, r4, r4, ror #12 */
/* @0xf3cbc eoreq r3, r4, r4, asr #12 */
/* @0xf3cc0 eoreq r3, r4, r8, lsr #12 */
/* @0xf3cc4 eoreq r3, r4, r0, lsl r6 */
/* @0xf3cc8 .word 0x002435f8 */
/* @0xf3ccc .word 0x002435dc */
/* @0xf3cd0 eoreq r3, r4, r0, asr #11 */
/* @0xf3cd4 eoreq r3, r4, r4, lsr #11 */
/* @0xf3cd8 eoreq r3, r4, r8, lsl #11 */
/* @0xf3cdc eoreq r3, r4, r12, ror #10 */
/* @0xf3ce0 eoreq r3, r4, r0, asr r5 */
/* @0xf3ce4 eoreq r3, r4, r8, lsr r5 */
/* @0xf3ce8 eoreq r3, r4, r12, lsl r5 */
/* @0xf3cec eoreq r3, r4, r0, lsl #10 */
/* @0xf3cf0 eoreq r3, r4, r8, asr #7 */

/* ── FUNC 0xf3cf4 · OtherToStr(int) · size=968 · insn=242 */
/* @0xf3cf4 cmp r0, #58 */
/* @0xf3cf8 addls pc, pc, r0, lsl #2 */
/* @0xf3cfc b 0xf3ffc <_Z10OtherToStri+0x308> */
/* @0xf3d00 b 0xf3dec <_Z10OtherToStri+0xf8> */
/* @0xf3d04 b 0xf3ff0 <_Z10OtherToStri+0x2fc> */
/* @0xf3d08 b 0xf3fe4 <_Z10OtherToStri+0x2f0> */
/* @0xf3d0c b 0xf3fd8 <_Z10OtherToStri+0x2e4> */
/* @0xf3d10 b 0xf3fcc <_Z10OtherToStri+0x2d8> */
/* @0xf3d14 b 0xf3fc0 <_Z10OtherToStri+0x2cc> */
/* @0xf3d18 b 0xf3fb4 <_Z10OtherToStri+0x2c0> */
/* @0xf3d1c b 0xf3fa8 <_Z10OtherToStri+0x2b4> */
/* @0xf3d20 b 0xf3f9c <_Z10OtherToStri+0x2a8> */
/* @0xf3d24 b 0xf3f90 <_Z10OtherToStri+0x29c> */
/* @0xf3d28 b 0xf3f84 <_Z10OtherToStri+0x290> */
/* @0xf3d2c b 0xf3f78 <_Z10OtherToStri+0x284> */
/* @0xf3d30 b 0xf3f6c <_Z10OtherToStri+0x278> */
/* @0xf3d34 b 0xf3f60 <_Z10OtherToStri+0x26c> */
/* @0xf3d38 b 0xf3f54 <_Z10OtherToStri+0x260> */
/* @0xf3d3c b 0xf3f48 <_Z10OtherToStri+0x254> */
/* @0xf3d40 b 0xf3f3c <_Z10OtherToStri+0x248> */
/* @0xf3d44 b 0xf3f30 <_Z10OtherToStri+0x23c> */
/* @0xf3d48 b 0xf3f24 <_Z10OtherToStri+0x230> */
/* @0xf3d4c b 0xf3f18 <_Z10OtherToStri+0x224> */
/* @0xf3d50 b 0xf3f0c <_Z10OtherToStri+0x218> */
/* @0xf3d54 b 0xf3f00 <_Z10OtherToStri+0x20c> */
/* @0xf3d58 b 0xf3ef4 <_Z10OtherToStri+0x200> */
/* @0xf3d5c b 0xf3ee8 <_Z10OtherToStri+0x1f4> */
/* @0xf3d60 b 0xf3edc <_Z10OtherToStri+0x1e8> */
/* @0xf3d64 b 0xf3ed0 <_Z10OtherToStri+0x1dc> */
/* @0xf3d68 b 0xf3ffc <_Z10OtherToStri+0x308> */
/* @0xf3d6c b 0xf3ffc <_Z10OtherToStri+0x308> */
/* @0xf3d70 b 0xf3ffc <_Z10OtherToStri+0x308> */
/* @0xf3d74 b 0xf3ffc <_Z10OtherToStri+0x308> */
/* @0xf3d78 b 0xf3ec4 <_Z10OtherToStri+0x1d0> */
/* @0xf3d7c b 0xf3ffc <_Z10OtherToStri+0x308> */
/* @0xf3d80 b 0xf3ffc <_Z10OtherToStri+0x308> */
/* @0xf3d84 b 0xf3ffc <_Z10OtherToStri+0x308> */
/* @0xf3d88 b 0xf3ffc <_Z10OtherToStri+0x308> */
/* @0xf3d8c b 0xf3ffc <_Z10OtherToStri+0x308> */
/* @0xf3d90 b 0xf3ffc <_Z10OtherToStri+0x308> */
/* @0xf3d94 b 0xf3ffc <_Z10OtherToStri+0x308> */
/* @0xf3d98 b 0xf3ffc <_Z10OtherToStri+0x308> */
/* @0xf3d9c b 0xf3ffc <_Z10OtherToStri+0x308> */
/* @0xf3da0 b 0xf3eb8 <_Z10OtherToStri+0x1c4> */
/* @0xf3da4 b 0xf3eac <_Z10OtherToStri+0x1b8> */
/* @0xf3da8 b 0xf3ea0 <_Z10OtherToStri+0x1ac> */
/* @0xf3dac b 0xf3e94 <_Z10OtherToStri+0x1a0> */
/* @0xf3db0 b 0xf3e88 <_Z10OtherToStri+0x194> */
/* @0xf3db4 b 0xf3e7c <_Z10OtherToStri+0x188> */
/* @0xf3db8 b 0xf3e70 <_Z10OtherToStri+0x17c> */
/* @0xf3dbc b 0xf3e64 <_Z10OtherToStri+0x170> */
/* @0xf3dc0 b 0xf3ffc <_Z10OtherToStri+0x308> */
/* @0xf3dc4 b 0xf3ffc <_Z10OtherToStri+0x308> */
/* @0xf3dc8 b 0xf3e58 <_Z10OtherToStri+0x164> */
/* @0xf3dcc b 0xf3e4c <_Z10OtherToStri+0x158> */
/* @0xf3dd0 b 0xf3e40 <_Z10OtherToStri+0x14c> */
/* @0xf3dd4 b 0xf3e34 <_Z10OtherToStri+0x140> */
/* @0xf3dd8 b 0xf3e28 <_Z10OtherToStri+0x134> */
/* @0xf3ddc b 0xf3e1c <_Z10OtherToStri+0x128> */
/* @0xf3de0 b 0xf3e10 <_Z10OtherToStri+0x11c> */
/* @0xf3de4 b 0xf3e04 <_Z10OtherToStri+0x110> */
/* @0xf3de8 b 0xf3df8 <_Z10OtherToStri+0x104> */
/* @0xf3dec ldr r0, [pc, #0x214] */
/* @0xf3df0 add r0, pc, r0 */
/* @0xf3df4 bx lr */
/* @0xf3df8 ldr r0, [pc, #0x20c] */
/* @0xf3dfc add r0, pc, r0 */
/* @0xf3e00 bx lr */
/* @0xf3e04 ldr r0, [pc, #0x204] */
/* @0xf3e08 add r0, pc, r0 */
/* @0xf3e0c bx lr */
/* @0xf3e10 ldr r0, [pc, #0x1fc] */
/* @0xf3e14 add r0, pc, r0 */
/* @0xf3e18 bx lr */
/* @0xf3e1c ldr r0, [pc, #0x1f4] */
/* @0xf3e20 add r0, pc, r0 */
/* @0xf3e24 bx lr */
/* @0xf3e28 ldr r0, [pc, #0x1ec] */
/* @0xf3e2c add r0, pc, r0 */
/* @0xf3e30 bx lr */
/* @0xf3e34 ldr r0, [pc, #0x1e4] */
/* @0xf3e38 add r0, pc, r0 */
/* @0xf3e3c bx lr */
/* @0xf3e40 ldr r0, [pc, #0x1dc] */
/* @0xf3e44 add r0, pc, r0 */
/* @0xf3e48 bx lr */
/* @0xf3e4c ldr r0, [pc, #0x1d4] */
/* @0xf3e50 add r0, pc, r0 */
/* @0xf3e54 bx lr */
/* @0xf3e58 ldr r0, [pc, #0x1cc] */
/* @0xf3e5c add r0, pc, r0 */
/* @0xf3e60 bx lr */
/* @0xf3e64 ldr r0, [pc, #0x1c4] */
/* @0xf3e68 add r0, pc, r0 */
/* @0xf3e6c bx lr */
/* @0xf3e70 ldr r0, [pc, #0x1bc] */
/* @0xf3e74 add r0, pc, r0 */
/* @0xf3e78 bx lr */
/* @0xf3e7c ldr r0, [pc, #0x1b4] */
/* @0xf3e80 add r0, pc, r0 */
/* @0xf3e84 bx lr */
/* @0xf3e88 ldr r0, [pc, #0x1ac] */
/* @0xf3e8c add r0, pc, r0 */
/* @0xf3e90 bx lr */
/* @0xf3e94 ldr r0, [pc, #0x1a4] */
/* @0xf3e98 add r0, pc, r0 */
/* @0xf3e9c bx lr */
/* @0xf3ea0 ldr r0, [pc, #0x19c] */
/* @0xf3ea4 add r0, pc, r0 */
/* @0xf3ea8 bx lr */
/* @0xf3eac ldr r0, [pc, #0x194] */
/* @0xf3eb0 add r0, pc, r0 */
/* @0xf3eb4 bx lr */
/* @0xf3eb8 ldr r0, [pc, #0x18c] */
/* @0xf3ebc add r0, pc, r0 */
/* @0xf3ec0 bx lr */
/* @0xf3ec4 ldr r0, [pc, #0x184] */
/* @0xf3ec8 add r0, pc, r0 */
/* @0xf3ecc bx lr */
/* @0xf3ed0 ldr r0, [pc, #0x17c] */
/* @0xf3ed4 add r0, pc, r0 */
/* @0xf3ed8 bx lr */
/* @0xf3edc ldr r0, [pc, #0x174] */
/* @0xf3ee0 add r0, pc, r0 */
/* @0xf3ee4 bx lr */
/* @0xf3ee8 ldr r0, [pc, #0x16c] */
/* @0xf3eec add r0, pc, r0 */
/* @0xf3ef0 bx lr */
/* @0xf3ef4 ldr r0, [pc, #0x164] */
/* @0xf3ef8 add r0, pc, r0 */
/* @0xf3efc bx lr */
/* @0xf3f00 ldr r0, [pc, #0x15c] */
/* @0xf3f04 add r0, pc, r0 */
/* @0xf3f08 bx lr */
/* @0xf3f0c ldr r0, [pc, #0x154] */
/* @0xf3f10 add r0, pc, r0 */
/* @0xf3f14 bx lr */
/* @0xf3f18 ldr r0, [pc, #0x14c] */
/* @0xf3f1c add r0, pc, r0 */
/* @0xf3f20 bx lr */
/* @0xf3f24 ldr r0, [pc, #0x144] */
/* @0xf3f28 add r0, pc, r0 */
/* @0xf3f2c bx lr */
/* @0xf3f30 ldr r0, [pc, #0x13c] */
/* @0xf3f34 add r0, pc, r0 */
/* @0xf3f38 bx lr */
/* @0xf3f3c ldr r0, [pc, #0x134] */
/* @0xf3f40 add r0, pc, r0 */
/* @0xf3f44 bx lr */
/* @0xf3f48 ldr r0, [pc, #0x12c] */
/* @0xf3f4c add r0, pc, r0 */
/* @0xf3f50 bx lr */
/* @0xf3f54 ldr r0, [pc, #0x124] */
/* @0xf3f58 add r0, pc, r0 */
/* @0xf3f5c bx lr */
/* @0xf3f60 ldr r0, [pc, #0x11c] */
/* @0xf3f64 add r0, pc, r0 */
/* @0xf3f68 bx lr */
/* @0xf3f6c ldr r0, [pc, #0x114] */
/* @0xf3f70 add r0, pc, r0 */
/* @0xf3f74 bx lr */
/* @0xf3f78 ldr r0, [pc, #0x10c] */
/* @0xf3f7c add r0, pc, r0 */
/* @0xf3f80 bx lr */
/* @0xf3f84 ldr r0, [pc, #0x104] */
/* @0xf3f88 add r0, pc, r0 */
/* @0xf3f8c bx lr */
/* @0xf3f90 ldr r0, [pc, #0xfc] */
/* @0xf3f94 add r0, pc, r0 */
/* @0xf3f98 bx lr */
/* @0xf3f9c ldr r0, [pc, #0xf4] */
/* @0xf3fa0 add r0, pc, r0 */
/* @0xf3fa4 bx lr */
/* @0xf3fa8 ldr r0, [pc, #0xec] */
/* @0xf3fac add r0, pc, r0 */
/* @0xf3fb0 bx lr */
/* @0xf3fb4 ldr r0, [pc, #0xe4] */
/* @0xf3fb8 add r0, pc, r0 */
/* @0xf3fbc bx lr */
/* @0xf3fc0 ldr r0, [pc, #0xdc] */
/* @0xf3fc4 add r0, pc, r0 */
/* @0xf3fc8 bx lr */
/* @0xf3fcc ldr r0, [pc, #0xd4] */
/* @0xf3fd0 add r0, pc, r0 */
/* @0xf3fd4 bx lr */
/* @0xf3fd8 ldr r0, [pc, #0xcc] */
/* @0xf3fdc add r0, pc, r0 */
/* @0xf3fe0 bx lr */
/* @0xf3fe4 ldr r0, [pc, #0xc4] */
/* @0xf3fe8 add r0, pc, r0 */
/* @0xf3fec bx lr */
/* @0xf3ff0 ldr r0, [pc, #0xbc] */
/* @0xf3ff4 add r0, pc, r0 */
/* @0xf3ff8 bx lr */
/* @0xf3ffc ldr r0, [pc, #0xb4] */
/* @0xf4000 add r0, pc, r0 */
/* @0xf4004 bx lr */
/* @0xf4008 eoreq r3, r4, r8, ror r6 */
/* @0xf400c eoreq r3, r4, r12, lsl #18 */
/* @0xf4010 .word 0x002438f0 */
/* @0xf4014 .word 0x002438d4 */
/* @0xf4018 .word 0x002438b8 */
/* @0xf401c mlaeq r4, r12, r8, r3 */
/* @0xf4020 eoreq r3, r4, r0, lsl #17 */
/* @0xf4024 eoreq r3, r4, r4, ror #16 */
/* @0xf4028 eoreq r3, r4, r8, asr #16 */
/* @0xf402c eoreq r3, r4, r12, lsr #16 */
/* @0xf4030 eoreq r3, r4, r0, lsl r8 */
/* @0xf4034 .word 0x002437f4 */
/* @0xf4038 .word 0x002437d8 */
/* @0xf403c .word 0x002437bc */
/* @0xf4040 eoreq r3, r4, r0, lsr #15 */
/* @0xf4044 eoreq r3, r4, r4, lsl #15 */
/* @0xf4048 eoreq r3, r4, r8, ror #14 */
/* @0xf404c eoreq r3, r4, r12, asr #14 */
/* @0xf4050 eoreq r3, r4, r0, lsr r7 */
/* @0xf4054 eoreq r3, r4, r4, lsl r7 */
/* @0xf4058 .word 0x002436f8 */
/* @0xf405c .word 0x002436dc */
/* @0xf4060 eoreq r3, r4, r0, asr #13 */
/* @0xf4064 eoreq r3, r4, r4, lsr #13 */
/* @0xf4068 eoreq r3, r4, r8, lsl #13 */
/* @0xf406c eoreq r3, r4, r12, ror #12 */
/* @0xf4070 eoreq r3, r4, r0, asr r6 */
/* @0xf4074 eoreq r3, r4, r4, lsr r6 */
/* @0xf4078 eoreq r3, r4, r8, lsl r6 */
/* @0xf407c .word 0x002435fc */
/* @0xf4080 eoreq r3, r4, r0, ror #11 */
/* @0xf4084 eoreq r3, r4, r4, asr #11 */
/* @0xf4088 eoreq r3, r4, r8, lsr #11 */
/* @0xf408c eoreq r3, r4, r12, lsl #11 */
/* @0xf4090 eoreq r3, r4, r0, ror r5 */
/* @0xf4094 eoreq r3, r4, r4, asr r5 */
/* @0xf4098 eoreq r3, r4, r12, lsr r5 */
/* @0xf409c eoreq r3, r4, r0, lsr #10 */
/* @0xf40a0 eoreq r3, r4, r4, lsl #10 */
/* @0xf40a4 eoreq r3, r4, r12, ror #9 */
/* @0xf40a8 .word 0x002434d4 */
/* @0xf40ac .word 0x002434bc */
/* @0xf40b0 eoreq r3, r4, r4, lsr #9 */
/* @0xf40b4 eoreq r3, r4, r4, lsl #9 */
/* @0xf40b8 .word 0x00242ff4 */

/* ── FUNC 0xf40bc · WebToStr(int) · size=320 · insn=80 */
/* @0xf40bc sub r0, r0, #60 */
/* @0xf40c0 cmp r0, #15 */
/* @0xf40c4 addls pc, pc, r0, lsl #2 */
/* @0xf40c8 b 0xf41b4 <_Z8WebToStri+0xf8> */
/* @0xf40cc b 0xf410c <_Z8WebToStri+0x50> */
/* @0xf40d0 b 0xf4118 <_Z8WebToStri+0x5c> */
/* @0xf40d4 b 0xf4124 <_Z8WebToStri+0x68> */
/* @0xf40d8 b 0xf4130 <_Z8WebToStri+0x74> */
/* @0xf40dc b 0xf41b4 <_Z8WebToStri+0xf8> */
/* @0xf40e0 b 0xf41b4 <_Z8WebToStri+0xf8> */
/* @0xf40e4 b 0xf413c <_Z8WebToStri+0x80> */
/* @0xf40e8 b 0xf4148 <_Z8WebToStri+0x8c> */
/* @0xf40ec b 0xf4154 <_Z8WebToStri+0x98> */
/* @0xf40f0 b 0xf4160 <_Z8WebToStri+0xa4> */
/* @0xf40f4 b 0xf416c <_Z8WebToStri+0xb0> */
/* @0xf40f8 b 0xf4178 <_Z8WebToStri+0xbc> */
/* @0xf40fc b 0xf4184 <_Z8WebToStri+0xc8> */
/* @0xf4100 b 0xf4190 <_Z8WebToStri+0xd4> */
/* @0xf4104 b 0xf419c <_Z8WebToStri+0xe0> */
/* @0xf4108 b 0xf41a8 <_Z8WebToStri+0xec> */
/* @0xf410c ldr r0, [pc, #0xac] */
/* @0xf4110 add r0, pc, r0 */
/* @0xf4114 bx lr */
/* @0xf4118 ldr r0, [pc, #0xa4] */
/* @0xf411c add r0, pc, r0 */
/* @0xf4120 bx lr */
/* @0xf4124 ldr r0, [pc, #0x9c] */
/* @0xf4128 add r0, pc, r0 */
/* @0xf412c bx lr */
/* @0xf4130 ldr r0, [pc, #0x94] */
/* @0xf4134 add r0, pc, r0 */
/* @0xf4138 bx lr */
/* @0xf413c ldr r0, [pc, #0x8c] */
/* @0xf4140 add r0, pc, r0 */
/* @0xf4144 bx lr */
/* @0xf4148 ldr r0, [pc, #0x84] */
/* @0xf414c add r0, pc, r0 */
/* @0xf4150 bx lr */
/* @0xf4154 ldr r0, [pc, #0x7c] */
/* @0xf4158 add r0, pc, r0 */
/* @0xf415c bx lr */
/* @0xf4160 ldr r0, [pc, #0x74] */
/* @0xf4164 add r0, pc, r0 */
/* @0xf4168 bx lr */
/* @0xf416c ldr r0, [pc, #0x6c] */
/* @0xf4170 add r0, pc, r0 */
/* @0xf4174 bx lr */
/* @0xf4178 ldr r0, [pc, #0x64] */
/* @0xf417c add r0, pc, r0 */
/* @0xf4180 bx lr */
/* @0xf4184 ldr r0, [pc, #0x5c] */
/* @0xf4188 add r0, pc, r0 */
/* @0xf418c bx lr */
/* @0xf4190 ldr r0, [pc, #0x54] */
/* @0xf4194 add r0, pc, r0 */
/* @0xf4198 bx lr */
/* @0xf419c ldr r0, [pc, #0x4c] */
/* @0xf41a0 add r0, pc, r0 */
/* @0xf41a4 bx lr */
/* @0xf41a8 ldr r0, [pc, #0x44] */
/* @0xf41ac add r0, pc, r0 */
/* @0xf41b0 bx lr */
/* @0xf41b4 ldr r0, [pc, #0x3c] */
/* @0xf41b8 add r0, pc, r0 */
/* @0xf41bc bx lr */
/* @0xf41c0 eoreq r3, r4, r12, lsl #12 */
/* @0xf41c4 eoreq r3, r4, r0, lsl r6 */
/* @0xf41c8 eoreq r3, r4, r4, lsl r6 */
/* @0xf41cc eoreq r3, r4, r0, lsl r6 */
/* @0xf41d0 eoreq r3, r4, r12, lsl #12 */
/* @0xf41d4 eoreq r3, r4, r4, lsl #12 */
/* @0xf41d8 eoreq r3, r4, r0, lsl #12 */
/* @0xf41dc eoreq r3, r4, r0, lsl #12 */
/* @0xf41e0 .word 0x002435fc */
/* @0xf41e4 .word 0x002435f8 */
/* @0xf41e8 .word 0x002435f4 */
/* @0xf41ec .word 0x002435f4 */
/* @0xf41f0 .word 0x002435f8 */
/* @0xf41f4 .word 0x002435fc */
/* @0xf41f8 eoreq r2, r4, r12, lsr lr */

/* ── FUNC 0xf41fc · Get_Event_Name(int, int) · size=760 · insn=190 */
/* @0xf41fc push {r4, lr} */
/* @0xf4200 sub sp, sp, #8 */
/* @0xf4204 cmp r0, #14 */
/* @0xf4208 addls pc, pc, r0, lsl #2 */
/* @0xf420c b 0xf443c <_Z14Get_Event_Nameii+0x240> */
/* @0xf4210 b 0xf425c <_Z14Get_Event_Nameii+0x60> */
/* @0xf4214 b 0xf4268 <_Z14Get_Event_Nameii+0x6c> */
/* @0xf4218 b 0xf4274 <_Z14Get_Event_Nameii+0x78> */
/* @0xf421c b 0xf42a0 <_Z14Get_Event_Nameii+0xa4> */
/* @0xf4220 b 0xf42cc <_Z14Get_Event_Nameii+0xd0> */
/* @0xf4224 b 0xf4300 <_Z14Get_Event_Nameii+0x104> */
/* @0xf4228 b 0xf4348 <_Z14Get_Event_Nameii+0x14c> */
/* @0xf422c b 0xf4384 <_Z14Get_Event_Nameii+0x188> */
/* @0xf4230 b 0xf43c8 <_Z14Get_Event_Nameii+0x1cc> */
/* @0xf4234 b 0xf43d4 <_Z14Get_Event_Nameii+0x1d8> */
/* @0xf4238 b 0xf4408 <_Z14Get_Event_Nameii+0x20c> */
/* @0xf423c b 0xf443c <_Z14Get_Event_Nameii+0x240> */
/* @0xf4240 b 0xf443c <_Z14Get_Event_Nameii+0x240> */
/* @0xf4244 b 0xf443c <_Z14Get_Event_Nameii+0x240> */
/* @0xf4248 b 0xf424c <_Z14Get_Event_Nameii+0x50> */
/* @0xf424c ldr r0, [pc, #0x224] */
/* @0xf4250 add r0, pc, r0 */
/* @0xf4254 add sp, sp, #8 */
/* @0xf4258 pop {r4, pc} */
/* @0xf425c ldr r0, [pc, #0x218] */
/* @0xf4260 add r0, pc, r0 */
/* @0xf4264 b 0xf4254 <_Z14Get_Event_Nameii+0x58> */
/* @0xf4268 ldr r0, [pc, #0x210] */
/* @0xf426c add r0, pc, r0 */
/* @0xf4270 b 0xf4254 <_Z14Get_Event_Nameii+0x58> */
/* @0xf4274 ldr r4, [pc, #0x208] */
/* @0xf4278 mov r3, r1 */
/* @0xf427c ldr r2, [pc, #0x204] */
/* @0xf4280 mov r1, #512 */
/* @0xf4284 add r4, pc, r4 */
/* @0xf4288 add r4, r4, #64 */
/* @0xf428c add r2, pc, r2 */
/* @0xf4290 mov r0, r4 */
/* @0xf4294 bl 0xb65c8 <snprintf@plt> */
/* @0xf4298 mov r0, r4 */
/* @0xf429c b 0xf4254 <_Z14Get_Event_Nameii+0x58> */
/* @0xf42a0 ldr r4, [pc, #0x1e4] */
/* @0xf42a4 mov r3, r1 */
/* @0xf42a8 ldr r2, [pc, #0x1e0] */
/* @0xf42ac mov r1, #512 */
/* @0xf42b0 add r4, pc, r4 */
/* @0xf42b4 add r4, r4, #64 */
/* @0xf42b8 add r2, pc, r2 */
/* @0xf42bc mov r0, r4 */
/* @0xf42c0 bl 0xb65c8 <snprintf@plt> */
/* @0xf42c4 mov r0, r4 */
/* @0xf42c8 b 0xf4254 <_Z14Get_Event_Nameii+0x58> */
/* @0xf42cc mov r0, r1 */
/* @0xf42d0 ldr r4, [pc, #0x1bc] */
/* @0xf42d4 bl 0x19ed54 <_Z11Object_Namei> */
/* @0xf42d8 ldr r2, [pc, #0x1b8] */
/* @0xf42dc add r4, pc, r4 */
/* @0xf42e0 mov r1, #512 */
/* @0xf42e4 add r4, r4, #64 */
/* @0xf42e8 add r2, pc, r2 */
/* @0xf42ec mov r3, r0 */
/* @0xf42f0 mov r0, r4 */
/* @0xf42f4 bl 0xb65c8 <snprintf@plt> */
/* @0xf42f8 mov r0, r4 */
/* @0xf42fc b 0xf4254 <_Z14Get_Event_Nameii+0x58> */
/* @0xf4300 mov r0, r1 */
/* @0xf4304 ldr r4, [pc, #0x190] */
/* @0xf4308 bl 0xf348c <_Z8KeyToStri> */
/* @0xf430c ldr r12, [pc, #0x18c] */
/* @0xf4310 ldr r2, [pc, #0x18c] */
/* @0xf4314 add r4, pc, r4 */
/* @0xf4318 ldr r3, [pc, #0x188] */
/* @0xf431c add r12, pc, r12 */
/* @0xf4320 add r4, r4, #64 */
/* @0xf4324 add r2, pc, r2 */
/* @0xf4328 add r3, pc, r3 */
/* @0xf432c mov r1, #512 */
/* @0xf4330 stm sp, {r0, r12} */
/* @0xf4334 mov r0, r4 */
/* @0xf4338 bl 0xb65c8 <snprintf@plt> */
/* @0xf433c mov r0, r4 */
/* @0xf4340 add sp, sp, #8 */
/* @0xf4344 pop {r4, pc} */
/* @0xf4348 mov r0, r1 */
/* @0xf434c ldr r4, [pc, #0x158] */
/* @0xf4350 bl 0xf38f0 <_Z10MouseToStri> */
/* @0xf4354 ldr r2, [pc, #0x154] */
/* @0xf4358 add r4, pc, r4 */
/* @0xf435c ldr r3, [pc, #0x150] */
/* @0xf4360 add r4, r4, #64 */
/* @0xf4364 mov r1, #512 */
/* @0xf4368 add r2, pc, r2 */
/* @0xf436c add r3, pc, r3 */
/* @0xf4370 str r0, [sp] */
/* @0xf4374 mov r0, r4 */
/* @0xf4378 bl 0xb65c8 <snprintf@plt> */
/* @0xf437c mov r0, r4 */
/* @0xf4380 b 0xf4254 <_Z14Get_Event_Nameii+0x58> */
/* @0xf4384 cmp r1, #59 */
/* @0xf4388 mov r0, r1 */
/* @0xf438c bgt 0xf4448 <_Z14Get_Event_Nameii+0x24c> */
/* @0xf4390 bl 0xf3cf4 <_Z10OtherToStri> */
/* @0xf4394 ldr r4, [pc, #0x11c] */
/* @0xf4398 ldr r2, [pc, #0x11c] */
/* @0xf439c mov r1, #512 */
/* @0xf43a0 add r4, pc, r4 */
/* @0xf43a4 ldr r3, [pc, #0x114] */
/* @0xf43a8 add r4, r4, #64 */
/* @0xf43ac add r2, pc, r2 */
/* @0xf43b0 add r3, pc, r3 */
/* @0xf43b4 str r0, [sp] */
/* @0xf43b8 mov r0, r4 */
/* @0xf43bc bl 0xb65c8 <snprintf@plt> */
/* @0xf43c0 mov r0, r4 */
/* @0xf43c4 b 0xf4254 <_Z14Get_Event_Nameii+0x58> */
/* @0xf43c8 ldr r0, [pc, #0xf4] */
/* @0xf43cc add r0, pc, r0 */
/* @0xf43d0 b 0xf4254 <_Z14Get_Event_Nameii+0x58> */
/* @0xf43d4 mov r0, r1 */
/* @0xf43d8 ldr r4, [pc, #0xe8] */
/* @0xf43dc bl 0xf348c <_Z8KeyToStri> */
/* @0xf43e0 ldr r12, [pc, #0xe4] */
/* @0xf43e4 ldr r2, [pc, #0xe4] */
/* @0xf43e8 add r4, pc, r4 */
/* @0xf43ec ldr r3, [pc, #0xe0] */
/* @0xf43f0 add r12, pc, r12 */
/* @0xf43f4 mov r1, #512 */
/* @0xf43f8 add r4, r4, #64 */
/* @0xf43fc add r2, pc, r2 */
/* @0xf4400 add r3, pc, r3 */
/* @0xf4404 b 0xf4330 <_Z14Get_Event_Nameii+0x134> */
/* @0xf4408 mov r0, r1 */
/* @0xf440c ldr r4, [pc, #0xc4] */
/* @0xf4410 bl 0xf348c <_Z8KeyToStri> */
/* @0xf4414 ldr r12, [pc, #0xc0] */
/* @0xf4418 ldr r2, [pc, #0xc0] */
/* @0xf441c add r4, pc, r4 */
/* @0xf4420 ldr r3, [pc, #0xbc] */
/* @0xf4424 add r12, pc, r12 */
/* @0xf4428 mov r1, #512 */
/* @0xf442c add r4, r4, #64 */
/* @0xf4430 add r2, pc, r2 */
/* @0xf4434 add r3, pc, r3 */
/* @0xf4438 b 0xf4330 <_Z14Get_Event_Nameii+0x134> */
/* @0xf443c ldr r0, [pc, #0xa4] */
/* @0xf4440 add r0, pc, r0 */
/* @0xf4444 b 0xf4254 <_Z14Get_Event_Nameii+0x58> */
/* @0xf4448 bl 0xf40bc <_Z8WebToStri> */
/* @0xf444c ldr r4, [pc, #0x98] */
/* @0xf4450 ldr r2, [pc, #0x98] */
/* @0xf4454 mov r1, #512 */
/* @0xf4458 add r4, pc, r4 */
/* @0xf445c add r4, r4, #64 */
/* @0xf4460 add r2, pc, r2 */
/* @0xf4464 mov r3, r0 */
/* @0xf4468 mov r0, r4 */
/* @0xf446c bl 0xb65c8 <snprintf@plt> */
/* @0xf4470 mov r0, r4 */
/* @0xf4474 b 0xf4254 <_Z14Get_Event_Nameii+0x58> */
/* @0xf4478 eoreq r3, r4, r8, ror r5 */
/* @0xf447c eoreq r3, r4, r8, ror r5 */
/* @0xf4480 eoreq r3, r4, r12, ror r5 */
/* @0xf4484 eorseq pc, r8, r4, lsl #3 */
/* @0xf4488 eoreq r3, r4, r8, ror r5 */
/* @0xf448c eorseq pc, r8, r8, asr r1 */
/* @0xf4490 eoreq r3, r4, r8, ror #10 */
/* @0xf4494 eorseq pc, r8, r12, lsr #2 */
/* @0xf4498 eoreq r3, r4, r8, asr #10 */
/* @0xf449c ldrshteq pc, [r8], -r4 */
/* @0xf44a0 eoreq r3, r4, r0, asr #10 */
/* @0xf44a4 eoreq r3, r4, r12, lsl r5 */
/* @0xf44a8 eoreq r3, r4, r0, lsr #10 */
/* @0xf44ac ldrhteq pc, [r8], -r0 */
/* @0xf44b0 eoreq r0, r4, r12, ror #16 */
/* @0xf44b4 .word 0x002434f8 */
/* @0xf44b8 eorseq pc, r8, r8, rrx */
/* @0xf44bc eoreq r0, r4, r8, lsr #16 */
/* @0xf44c0 eoreq r3, r4, r8, asr #9 */
/* @0xf44c4 eoreq r3, r4, r12, lsr #8 */
/* @0xf44c8 eorseq pc, r8, r0, lsr #32 */
/* @0xf44cc eoreq r3, r4, r12, ror #8 */
/* @0xf44d0 eoreq r3, r4, r4, asr #8 */
/* @0xf44d4 mlaeq r4, r8, r4, r3 */
/* @0xf44d8 eorseq lr, r8, r12, ror #31 */
/* @0xf44dc eoreq r3, r4, r8, lsr r4 */
/* @0xf44e0 eoreq r3, r4, r0, lsl r4 */
/* @0xf44e4 eoreq r3, r4, r12, ror r4 */
/* @0xf44e8 eoreq r3, r4, r8, ror r3 */
/* @0xf44ec ldrhteq lr, [r8], -r0 */
/* @0xf44f0 eoreq r3, r4, r8, lsr #8 */

/* ── FUNC 0xf44f4 · Get_Event_Name_Short(int, int) · size=520 · insn=130 */
/* @0xf44f4 push {r4, lr} */
/* @0xf44f8 sub sp, sp, #8 */
/* @0xf44fc cmp r0, #14 */
/* @0xf4500 addls pc, pc, r0, lsl #2 */
/* @0xf4504 b 0xf46a4 <_Z20Get_Event_Name_Shortii+0x1b0> */
/* @0xf4508 b 0xf4554 <_Z20Get_Event_Name_Shortii+0x60> */
/* @0xf450c b 0xf4560 <_Z20Get_Event_Name_Shortii+0x6c> */
/* @0xf4510 b 0xf456c <_Z20Get_Event_Name_Shortii+0x78> */
/* @0xf4514 b 0xf4598 <_Z20Get_Event_Name_Shortii+0xa4> */
/* @0xf4518 b 0xf45d8 <_Z20Get_Event_Name_Shortii+0xe4> */
/* @0xf451c b 0xf45e8 <_Z20Get_Event_Name_Shortii+0xf4> */
/* @0xf4520 b 0xf45f8 <_Z20Get_Event_Name_Shortii+0x104> */
/* @0xf4524 b 0xf4608 <_Z20Get_Event_Name_Shortii+0x114> */
/* @0xf4528 b 0xf4620 <_Z20Get_Event_Name_Shortii+0x12c> */
/* @0xf452c b 0xf462c <_Z20Get_Event_Name_Shortii+0x138> */
/* @0xf4530 b 0xf4668 <_Z20Get_Event_Name_Shortii+0x174> */
/* @0xf4534 b 0xf46a4 <_Z20Get_Event_Name_Shortii+0x1b0> */
/* @0xf4538 b 0xf46a4 <_Z20Get_Event_Name_Shortii+0x1b0> */
/* @0xf453c b 0xf46a4 <_Z20Get_Event_Name_Shortii+0x1b0> */
/* @0xf4540 b 0xf4544 <_Z20Get_Event_Name_Shortii+0x50> */
/* @0xf4544 ldr r0, [pc, #0x170] */
/* @0xf4548 add r0, pc, r0 */
/* @0xf454c add sp, sp, #8 */
/* @0xf4550 pop {r4, pc} */
/* @0xf4554 ldr r0, [pc, #0x164] */
/* @0xf4558 add r0, pc, r0 */
/* @0xf455c b 0xf454c <_Z20Get_Event_Name_Shortii+0x58> */
/* @0xf4560 ldr r0, [pc, #0x15c] */
/* @0xf4564 add r0, pc, r0 */
/* @0xf4568 b 0xf454c <_Z20Get_Event_Name_Shortii+0x58> */
/* @0xf456c ldr r4, [pc, #0x154] */
/* @0xf4570 mov r3, r1 */
/* @0xf4574 ldr r2, [pc, #0x150] */
/* @0xf4578 mov r1, #512 */
/* @0xf457c add r4, pc, r4 */
/* @0xf4580 add r4, r4, #64 */
/* @0xf4584 add r2, pc, r2 */
/* @0xf4588 mov r0, r4 */
/* @0xf458c bl 0xb65c8 <snprintf@plt> */
/* @0xf4590 mov r0, r4 */
/* @0xf4594 b 0xf454c <_Z20Get_Event_Name_Shortii+0x58> */
/* @0xf4598 mov r0, r1 */
/* @0xf459c ldr r4, [pc, #0x12c] */
/* @0xf45a0 bl 0xf344c <_Z9StepToStri> */
/* @0xf45a4 ldr r12, [pc, #0x128] */
/* @0xf45a8 add r4, pc, r4 */
/* @0xf45ac ldr r2, [pc, #0x124] */
/* @0xf45b0 add r4, r4, #64 */
/* @0xf45b4 add r12, pc, r12 */
/* @0xf45b8 mov r1, #512 */
/* @0xf45bc add r2, pc, r2 */
/* @0xf45c0 str r12, [sp] */
/* @0xf45c4 mov r3, r0 */
/* @0xf45c8 mov r0, r4 */
/* @0xf45cc bl 0xb65c8 <snprintf@plt> */
/* @0xf45d0 mov r0, r4 */
/* @0xf45d4 b 0xf454c <_Z20Get_Event_Name_Shortii+0x58> */
/* @0xf45d8 mov r0, r1 */
/* @0xf45dc add sp, sp, #8 */
/* @0xf45e0 pop {r4, lr} */
/* @0xf45e4 b 0x19ed54 <_Z11Object_Namei> */
/* @0xf45e8 mov r0, r1 */
/* @0xf45ec add sp, sp, #8 */
/* @0xf45f0 pop {r4, lr} */
/* @0xf45f4 b 0xf348c <_Z8KeyToStri> */
/* @0xf45f8 mov r0, r1 */
/* @0xf45fc add sp, sp, #8 */
/* @0xf4600 pop {r4, lr} */
/* @0xf4604 b 0xf38f0 <_Z10MouseToStri> */
/* @0xf4608 cmp r1, #59 */
/* @0xf460c mov r0, r1 */
/* @0xf4610 bgt 0xf46b0 <_Z20Get_Event_Name_Shortii+0x1bc> */
/* @0xf4614 add sp, sp, #8 */
/* @0xf4618 pop {r4, lr} */
/* @0xf461c b 0xf3cf4 <_Z10OtherToStri> */
/* @0xf4620 ldr r0, [pc, #0xb4] */
/* @0xf4624 add r0, pc, r0 */
/* @0xf4628 b 0xf454c <_Z20Get_Event_Name_Shortii+0x58> */
/* @0xf462c mov r0, r1 */
/* @0xf4630 ldr r4, [pc, #0xa8] */
/* @0xf4634 bl 0xf348c <_Z8KeyToStri> */
/* @0xf4638 ldr r2, [pc, #0xa4] */
/* @0xf463c add r4, pc, r4 */
/* @0xf4640 ldr r3, [pc, #0xa0] */
/* @0xf4644 add r4, r4, #64 */
/* @0xf4648 mov r1, #512 */
/* @0xf464c add r2, pc, r2 */
/* @0xf4650 add r3, pc, r3 */
/* @0xf4654 str r0, [sp] */
/* @0xf4658 mov r0, r4 */
/* @0xf465c bl 0xb65c8 <snprintf@plt> */
/* @0xf4660 mov r0, r4 */
/* @0xf4664 b 0xf454c <_Z20Get_Event_Name_Shortii+0x58> */
/* @0xf4668 mov r0, r1 */
/* @0xf466c ldr r4, [pc, #0x78] */
/* @0xf4670 bl 0xf348c <_Z8KeyToStri> */
/* @0xf4674 ldr r2, [pc, #0x74] */
/* @0xf4678 add r4, pc, r4 */
/* @0xf467c ldr r3, [pc, #0x70] */
/* @0xf4680 add r4, r4, #64 */
/* @0xf4684 mov r1, #512 */
/* @0xf4688 add r2, pc, r2 */
/* @0xf468c add r3, pc, r3 */
/* @0xf4690 str r0, [sp] */
/* @0xf4694 mov r0, r4 */
/* @0xf4698 bl 0xb65c8 <snprintf@plt> */
/* @0xf469c mov r0, r4 */
/* @0xf46a0 b 0xf454c <_Z20Get_Event_Name_Shortii+0x58> */
/* @0xf46a4 ldr r0, [pc, #0x4c] */
/* @0xf46a8 add r0, pc, r0 */
/* @0xf46ac b 0xf454c <_Z20Get_Event_Name_Shortii+0x58> */
/* @0xf46b0 add sp, sp, #8 */
/* @0xf46b4 pop {r4, lr} */
/* @0xf46b8 b 0xf40bc <_Z8WebToStri> */
/* @0xf46bc eoreq r3, r4, r0, lsl #7 */
/* @0xf46c0 eoreq r3, r4, r12, ror r3 */
/* @0xf46c4 eoreq r3, r4, r8, ror r3 */
/* @0xf46c8 eorseq lr, r8, r12, lsl #29 */
/* @0xf46cc eoreq r3, r4, r8, ror #6 */
/* @0xf46d0 eorseq lr, r8, r0, ror #28 */
/* @0xf46d4 eoreq r3, r4, r4, asr #6 */
/* @0xf46d8 eoreq r0, r4, r8, lsl r6 */
/* @0xf46dc eoreq r3, r4, r0, asr #5 */
/* @0xf46e0 eorseq lr, r8, r12, asr #27 */
/* @0xf46e4 eoreq r0, r4, r8, lsl #11 */
/* @0xf46e8 .word 0x002432b0 */
/* @0xf46ec mlaseq r8, r0, sp, lr */
/* @0xf46f0 eoreq r0, r4, r12, asr #10 */
/* @0xf46f4 eoreq r3, r4, r12, ror r2 */
/* @0xf46f8 eoreq r3, r4, r0, lsl r1 */
