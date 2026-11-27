/* libyoyo.so 覆盖卡组 0249
 * 函数 0x29fb30..0x2a297c，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x29fb30 · Debug_SendGameStructure(DbgSocket*, Buffer_Standard*) · size=796 · insn=199 */
/* @0x29fb30 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x29fb34 mov r6, r1 */
/* @0x29fb38 add r8, r1, #44 */
/* @0x29fb3c ldr r1, [r1] */
/* @0x29fb40 mov r7, #0 */
/* @0x29fb44 mov r10, r0 */
/* @0x29fb48 mov r2, #465567744 */
/* @0x29fb4c mov r0, r6 */
/* @0x29fb50 str r2, [r6, #0x2c] */
/* @0x29fb54 movw r3, #0xc238 */
/* @0x29fb58 mov r2, r8 */
/* @0x29fb5c movt r3, #0x41e7 */
/* @0x29fb60 str r3, [r6, #0x30] */
/* @0x29fb64 mov r9, r7 */
/* @0x29fb68 ldr r3, [r1, #0x8] */
/* @0x29fb6c mov r1, #5 */
/* @0x29fb70 str r7, [r6, #0x38] */
/* @0x29fb74 movt r9, #0x97c0 */
/* @0x29fb78 blx r3 */
/* @0x29fb7c ldr r3, [r6] */
/* @0x29fb80 str r7, [r6, #0x2c] */
/* @0x29fb84 mov r2, r8 */
/* @0x29fb88 str r7, [r6, #0x30] */
/* @0x29fb8c mov r0, r6 */
/* @0x29fb90 str r7, [r6, #0x38] */
/* @0x29fb94 mov r1, #5 */
/* @0x29fb98 ldr r3, [r3, #0x8] */
/* @0x29fb9c blx r3 */
/* @0x29fba0 ldr r3, [r6] */
/* @0x29fba4 str r7, [r6, #0x2c] */
/* @0x29fba8 mov r2, r8 */
/* @0x29fbac mov r1, #1073741824 */
/* @0x29fbb0 str r7, [r6, #0x38] */
/* @0x29fbb4 str r1, [r6, #0x30] */
/* @0x29fbb8 mov r0, r6 */
/* @0x29fbbc ldr r3, [r3, #0x8] */
/* @0x29fbc0 mov r1, #5 */
/* @0x29fbc4 blx r3 */
/* @0x29fbc8 ldr r1, [r6] */
/* @0x29fbcc str r9, [r6, #0x2c] */
/* @0x29fbd0 mov r2, r8 */
/* @0x29fbd4 str r7, [r6, #0x38] */
/* @0x29fbd8 mov r0, r6 */
/* @0x29fbdc movw r3, #0x9154 */
/* @0x29fbe0 movt r3, #0x41d5 */
/* @0x29fbe4 str r3, [r6, #0x30] */
/* @0x29fbe8 ldr r3, [r1, #0x8] */
/* @0x29fbec mov r1, #5 */
/* @0x29fbf0 blx r3 */
/* @0x29fbf4 ldr r1, [r6] */
/* @0x29fbf8 mov r2, r8 */
/* @0x29fbfc str r7, [r6, #0x2c] */
/* @0x29fc00 mov r3, r7 */
/* @0x29fc04 str r7, [r6, #0x38] */
/* @0x29fc08 movt r3, #0x4020 */
/* @0x29fc0c mov r0, r6 */
/* @0x29fc10 str r3, [r6, #0x30] */
/* @0x29fc14 ldr r3, [r1, #0x8] */
/* @0x29fc18 mov r1, #5 */
/* @0x29fc1c blx r3 */
/* @0x29fc20 bl 0x159cf4 <_Z23YoYo_GetPlatform_DoWorkv> */
/* @0x29fc24 ldr r3, [r6] */
/* @0x29fc28 mov r2, r8 */
/* @0x29fc2c str r7, [r6, #0x38] */
/* @0x29fc30 vmov d6, r0, r1 */
/* @0x29fc34 mov r0, r6 */
/* @0x29fc38 mov r1, #5 */
/* @0x29fc3c vcvt.u32.f64 s15, d6 */
/* @0x29fc40 vcvt.f64.u32 d6, s15 */
/* @0x29fc44 vmov r4, r5, d6 */
/* @0x29fc48 vstr s12, [r6, #44] */
/* @0x29fc4c str r5, [r6, #0x30] */
/* @0x29fc50 ldr r3, [r3, #0x8] */
/* @0x29fc54 blx r3 */
/* @0x29fc58 ldr r1, [r6] */
/* @0x29fc5c str r7, [r6, #0x38] */
/* @0x29fc60 mov r2, #289406976 */
/* @0x29fc64 mov r0, r6 */
/* @0x29fc68 str r2, [r6, #0x2c] */
/* @0x29fc6c movw r3, #0xd3d1 */
/* @0x29fc70 mov r2, r8 */
/* @0x29fc74 movt r3, #0x41d0 */
/* @0x29fc78 str r3, [r6, #0x30] */
/* @0x29fc7c ldr r3, [r1, #0x8] */
/* @0x29fc80 mov r1, #5 */
/* @0x29fc84 blx r3 */
/* @0x29fc88 mov r0, r6 */
/* @0x29fc8c bl 0x29f380 <_Z16AddVMCodeBuffersP15Buffer_Standard> */
/* @0x29fc90 ldr r1, [r6] */
/* @0x29fc94 str r9, [r6, #0x2c] */
/* @0x29fc98 mov r2, r8 */
/* @0x29fc9c str r7, [r6, #0x38] */
/* @0x29fca0 mov r0, r6 */
/* @0x29fca4 movw r3, #0xd092 */
/* @0x29fca8 movt r3, #0x41d3 */
/* @0x29fcac str r3, [r6, #0x30] */
/* @0x29fcb0 ldr r3, [r1, #0x8] */
/* @0x29fcb4 mov r1, #5 */
/* @0x29fcb8 blx r3 */
/* @0x29fcbc mov r0, r6 */
/* @0x29fcc0 bl 0x29e80c <_Z15TraverseObjectsP15Buffer_Standard> */
/* @0x29fcc4 ldr r1, [r6] */
/* @0x29fcc8 str r7, [r6, #0x38] */
/* @0x29fccc mov r2, #-1795162112 */
/* @0x29fcd0 mov r0, r6 */
/* @0x29fcd4 str r2, [r6, #0x2c] */
/* @0x29fcd8 movw r3, #0xd0d4 */
/* @0x29fcdc mov r2, r8 */
/* @0x29fce0 movt r3, #0x41d4 */
/* @0x29fce4 str r3, [r6, #0x30] */
/* @0x29fce8 ldr r3, [r1, #0x8] */
/* @0x29fcec mov r1, #5 */
/* @0x29fcf0 blx r3 */
/* @0x29fcf4 mov r0, r6 */
/* @0x29fcf8 bl 0x29ec54 <_Z10AddScriptsP15Buffer_Standard> */
/* @0x29fcfc ldr r1, [r6] */
/* @0x29fd00 str r7, [r6, #0x38] */
/* @0x29fd04 mov r2, r7 */
/* @0x29fd08 mov r0, r6 */
/* @0x29fd0c movt r2, #0x90c0 */
/* @0x29fd10 movw r3, #0x9553 */
/* @0x29fd14 str r2, [r6, #0x2c] */
/* @0x29fd18 movt r3, #0x41d1 */
/* @0x29fd1c mov r2, r8 */
/* @0x29fd20 str r3, [r6, #0x30] */
/* @0x29fd24 ldr r3, [r1, #0x8] */
/* @0x29fd28 mov r1, #5 */
/* @0x29fd2c blx r3 */
/* @0x29fd30 mov r0, r6 */
/* @0x29fd34 bl 0x29f4e4 <_Z16AddFunctionNamesP15Buffer_Standard> */
/* @0x29fd38 ldr r1, [r6] */
/* @0x29fd3c str r7, [r6, #0x38] */
/* @0x29fd40 mov r2, #-788529152 */
/* @0x29fd44 mov r0, r6 */
/* @0x29fd48 str r2, [r6, #0x2c] */
/* @0x29fd4c movw r3, #0xd0d3 */
/* @0x29fd50 mov r2, r8 */
/* @0x29fd54 movt r3, #0x41d0 */
/* @0x29fd58 str r3, [r6, #0x30] */
/* @0x29fd5c ldr r3, [r1, #0x8] */
/* @0x29fd60 mov r1, #5 */
/* @0x29fd64 blx r3 */
/* @0x29fd68 mov r0, r6 */
/* @0x29fd6c bl 0x29edf0 <_Z15AddCreationCodeP15Buffer_Standard> */
/* @0x29fd70 ldr r1, [r6] */
/* @0x29fd74 str r7, [r6, #0x38] */
/* @0x29fd78 mov r2, #327155712 */
/* @0x29fd7c mov r0, r6 */
/* @0x29fd80 str r2, [r6, #0x2c] */
/* @0x29fd84 movw r3, #0x1353 */
/* @0x29fd88 mov r2, r8 */
/* @0x29fd8c movt r3, #0x41d5 */
/* @0x29fd90 str r3, [r6, #0x30] */
/* @0x29fd94 ldr r3, [r1, #0x8] */
/* @0x29fd98 mov r1, #5 */
/* @0x29fd9c blx r3 */
/* @0x29fda0 mov r0, r6 */
/* @0x29fda4 bl 0x29f1b8 <_Z15AddTimelineCodeP15Buffer_Standard> */
/* @0x29fda8 ldr r3, [r6] */
/* @0x29fdac ldr r9, [r6, #0x1c] */
/* @0x29fdb0 mov r1, r7 */
/* @0x29fdb4 mov r0, r6 */
/* @0x29fdb8 mov r2, #4 */
/* @0x29fdbc ldr r3, [r3, #0x10] */
/* @0x29fdc0 blx r3 */
/* @0x29fdc4 vmov s15, r9 */
/* @0x29fdc8 ldr r3, [r6] */
/* @0x29fdcc mov r2, r8 */
/* @0x29fdd0 vcvt.f64.u32 d7, s15 */
/* @0x29fdd4 str r7, [r6, #0x38] */
/* @0x29fdd8 mov r0, r6 */
/* @0x29fddc mov r1, #5 */
/* @0x29fde0 vmov r4, r5, d7 */
/* @0x29fde4 vstr s14, [r6, #44] */
/* @0x29fde8 str r5, [r6, #0x30] */
/* @0x29fdec ldr r3, [r3, #0x8] */
/* @0x29fdf0 blx r3 */
/* @0x29fdf4 ldr r3, [r6] */
/* @0x29fdf8 mov r1, r7 */
/* @0x29fdfc mov r2, r9 */
/* @0x29fe00 mov r0, r6 */
/* @0x29fe04 ldr r3, [r3, #0x10] */
/* @0x29fe08 blx r3 */
/* @0x29fe0c ldr r3, [pc, #0x30] */
/* @0x29fe10 ldr r1, [pc, #0x30] */
/* @0x29fe14 mov r2, r9 */
/* @0x29fe18 ldr r3, [pc, r3] */
/* @0x29fe1c add r1, pc, r1 */
/* @0x29fe20 ldr r0, [r3] */
/* @0x29fe24 ldr r3, [r0] */
/* @0x29fe28 ldr r3, [r3, #0xc] */
/* @0x29fe2c blx r3 */
/* @0x29fe30 mov r0, r10 */
/* @0x29fe34 mov r2, r9 */
/* @0x29fe38 ldr r1, [r6, #0xc] */
/* @0x29fe3c pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x29fe40 b 0x29d9a8 <_ZN9DbgSocket5WriteEPvj> */
/* @0x29fe44 ldrsheq sp, [r4], -r12 */
/* @0x29fe48 andeq r9, r11, r8, lsl #28 */

/* ── FUNC 0x29fe4c · Debug_SendYYDebug(DbgSocket*, Buffer_Standard*) · size=376 · insn=94 */
/* @0x29fe4c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x29fe50 mov r6, r1 */
/* @0x29fe54 add r8, r1, #44 */
/* @0x29fe58 ldr r1, [r1] */
/* @0x29fe5c mov r4, #0 */
/* @0x29fe60 mov r2, #465567744 */
/* @0x29fe64 mov r9, r0 */
/* @0x29fe68 str r2, [r6, #0x2c] */
/* @0x29fe6c movw r3, #0xc238 */
/* @0x29fe70 mov r2, r8 */
/* @0x29fe74 movt r3, #0x41e7 */
/* @0x29fe78 mov r0, r6 */
/* @0x29fe7c str r3, [r6, #0x30] */
/* @0x29fe80 ldr r3, [r1, #0x8] */
/* @0x29fe84 mov r1, #5 */
/* @0x29fe88 str r4, [r6, #0x38] */
/* @0x29fe8c blx r3 */
/* @0x29fe90 ldr r3, [r6] */
/* @0x29fe94 str r4, [r6, #0x2c] */
/* @0x29fe98 mov r1, #5 */
/* @0x29fe9c str r4, [r6, #0x30] */
/* @0x29fea0 mov r2, r8 */
/* @0x29fea4 ldr r3, [r3, #0x8] */
/* @0x29fea8 mov r0, r6 */
/* @0x29feac str r4, [r6, #0x38] */
/* @0x29feb0 blx r3 */
/* @0x29feb4 ldr r3, [pc, #0xf8] */
/* @0x29feb8 ldr r3, [pc, r3] */
/* @0x29febc ldr r1, [r3] */
/* @0x29fec0 cmp r1, r4 */
/* @0x29fec4 beq 0x29fedc <_Z17Debug_SendYYDebugP9DbgSocketP15Buffer_Standard+0x90> */
/* @0x29fec8 ldr r3, [pc, #0xe8] */
/* @0x29fecc ldr r3, [pc, r3] */
/* @0x29fed0 ldr r3, [r3] */
/* @0x29fed4 cmp r3, r4 */
/* @0x29fed8 bgt 0x29ffa4 <_Z17Debug_SendYYDebugP9DbgSocketP15Buffer_Standard+0x158> */
/* @0x29fedc ldr r12, [r6] */
/* @0x29fee0 mov r3, #0 */
/* @0x29fee4 mov r0, r6 */
/* @0x29fee8 str r3, [r6, #0x2c] */
/* @0x29feec str r3, [r6, #0x30] */
/* @0x29fef0 mov r1, #5 */
/* @0x29fef4 str r3, [r6, #0x38] */
/* @0x29fef8 mov r2, r8 */
/* @0x29fefc ldr r3, [r12, #0x8] */
/* @0x29ff00 blx r3 */
/* @0x29ff04 ldr r3, [r6] */
/* @0x29ff08 mov r1, #0 */
/* @0x29ff0c ldr r7, [r6, #0x1c] */
/* @0x29ff10 mov r0, r6 */
/* @0x29ff14 mov r2, #4 */
/* @0x29ff18 mov r10, r1 */
/* @0x29ff1c ldr r3, [r3, #0x10] */
/* @0x29ff20 blx r3 */
/* @0x29ff24 vmov s15, r7 */
/* @0x29ff28 ldr r3, [r6] */
/* @0x29ff2c mov r2, r8 */
/* @0x29ff30 vcvt.f64.u32 d7, s15 */
/* @0x29ff34 str r10, [r6, #0x38] */
/* @0x29ff38 mov r0, r6 */
/* @0x29ff3c mov r1, #5 */
/* @0x29ff40 vmov r4, r5, d7 */
/* @0x29ff44 vstr s14, [r6, #44] */
/* @0x29ff48 str r5, [r6, #0x30] */
/* @0x29ff4c ldr r3, [r3, #0x8] */
/* @0x29ff50 blx r3 */
/* @0x29ff54 ldr r3, [r6] */
/* @0x29ff58 mov r1, r10 */
/* @0x29ff5c mov r2, r7 */
/* @0x29ff60 mov r0, r6 */
/* @0x29ff64 ldr r3, [r3, #0x10] */
/* @0x29ff68 blx r3 */
/* @0x29ff6c ldr r3, [pc, #0x48] */
/* @0x29ff70 ldr r1, [pc, #0x48] */
/* @0x29ff74 mov r2, r7 */
/* @0x29ff78 ldr r3, [pc, r3] */
/* @0x29ff7c add r1, pc, r1 */
/* @0x29ff80 ldr r0, [r3] */
/* @0x29ff84 ldr r3, [r0] */
/* @0x29ff88 ldr r3, [r3, #0xc] */
/* @0x29ff8c blx r3 */
/* @0x29ff90 mov r0, r9 */
/* @0x29ff94 mov r2, r7 */
/* @0x29ff98 ldr r1, [r6, #0xc] */
/* @0x29ff9c pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x29ffa0 b 0x29d9a8 <_ZN9DbgSocket5WriteEPvj> */
/* @0x29ffa4 mov r0, r6 */
/* @0x29ffa8 mov r2, #1 */
/* @0x29ffac bl 0xcdabc <_ZN7IBuffer5WriteEPKvjj> */
/* @0x29ffb0 b 0x29ff04 <_Z17Debug_SendYYDebugP9DbgSocketP15Buffer_Standard+0xb8> */
/* @0x29ffb4 andseq r0, r5, r8, asr lr */
/* @0x29ffb8 andseq r0, r5, r8, asr #28 */
/* @0x29ffbc mulseq r4, r12, r7 */
/* @0x29ffc0 ldrdeq r9, r10, [r11], -r4 */

/* ── FUNC 0x29ffc4 · cmpDumpNode(void const*, void const*) · size=40 · insn=10 */
/* @0x29ffc4 ldrd r2, r3, [r0, #16] */
/* @0x29ffc8 ldrd r0, r1, [r1, #16] */
/* @0x29ffcc cmp r3, r1 */
/* @0x29ffd0 cmpeq r2, r0 */
/* @0x29ffd4 blo 0x29ffe4 <_Z11cmpDumpNodePKvS0_+0x20> */
/* @0x29ffd8 movls r0, #0 */
/* @0x29ffdc mvnhi r0, #0 */
/* @0x29ffe0 bx lr */
/* @0x29ffe4 mov r0, #1 */
/* @0x29ffe8 bx lr */

/* ── FUNC 0x29ffec · anon_29ffec · size=180 · insn=46 */
/* @0x29ffec push {r0, r1, r2, r3} */
/* @0x29fff0 movw r1, #0x3fe */
/* @0x29fff4 push {r4, r5, lr} */
/* @0x29fff8 sub sp, sp, #1024 */
/* @0x29fffc ldr r4, [pc, #0x98] */
/* @0x2a0000 sub sp, sp, #12 */
/* @0x2a0004 add r12, sp, #1040 */
/* @0x2a0008 add r5, sp, #4 */
/* @0x2a000c ldr r4, [pc, r4] */
/* @0x2a0010 add r12, r12, #12 */
/* @0x2a0014 ldr r2, [sp, #0x418] */
/* @0x2a0018 mov r0, r5 */
/* @0x2a001c ldr lr, [r4] */
/* @0x2a0020 mov r3, r12 */
/* @0x2a0024 str r12, [sp] */
/* @0x2a0028 str lr, [sp, #0x404] */
/* @0x2a002c bl 0xb6610 <vsnprintf@plt> */
/* @0x2a0030 mov r0, r5 */
/* @0x2a0034 bl 0xb6538 <strlen@plt> */
/* @0x2a0038 ldr r3, [pc, #0x60] */
/* @0x2a003c add r12, sp, #1024 */
/* @0x2a0040 mov lr, #10 */
/* @0x2a0044 add r12, r12, #8 */
/* @0x2a0048 add r3, pc, r3 */
/* @0x2a004c ldr r3, [r3] */
/* @0x2a0050 add r1, r12, r0 */
/* @0x2a0054 add r2, r5, r0 */
/* @0x2a0058 mov r12, #0 */
/* @0x2a005c mov r0, r5 */
/* @0x2a0060 strb lr, [r1, #-0x404] */
/* @0x2a0064 mov r1, #1 */
/* @0x2a0068 strb r12, [r2, #0x1]! */
/* @0x2a006c rsb r2, r5, r2 */
/* @0x2a0070 bl 0xb68bc <fwrite@plt> */
/* @0x2a0074 ldr r2, [sp, #0x404] */
/* @0x2a0078 ldr r3, [r4] */
/* @0x2a007c cmp r2, r3 */
/* @0x2a0080 bne 0x2a0098 <_Z11cmpDumpNodePKvS0_+0xd4> */
/* @0x2a0084 add sp, sp, #1024 */
/* @0x2a0088 add sp, sp, #12 */
/* @0x2a008c pop {r4, r5, lr} */
/* @0x2a0090 add sp, sp, #16 */
/* @0x2a0094 bx lr */
/* @0x2a0098 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2a009c andseq sp, r4, r4, asr #18 */
/* @0x2a00a0 subeq r7, r11, r8, lsr #28 */

/* ── FUNC 0x2a00a4 · CProfiler::CProfiler() · size=12 · insn=3 */
/* @0x2a00a4 mov r2, #0 */
/* @0x2a00a8 strb r2, [r0, #0x10] */
/* @0x2a00ac bx lr */

/* ── FUNC 0x2a00a4 · CProfiler::CProfiler() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2a00b0 · CProfiler::Init(char const*, int) · size=692 · insn=173 */
/* @0x2a00b0 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2a00b4 mov r9, r1 */
/* @0x2a00b8 ldr r10, [pc, #0x280] */
/* @0x2a00bc adds r1, r1, #0 */
/* @0x2a00c0 ldr r3, [pc, #0x27c] */
/* @0x2a00c4 mov r7, r0 */
/* @0x2a00c8 add r10, pc, r10 */
/* @0x2a00cc mov lr, #1 */
/* @0x2a00d0 movne r1, #1 */
/* @0x2a00d4 ldr r0, [pc, #0x26c] */
/* @0x2a00d8 ldr r8, [r10, r3] */
/* @0x2a00dc eor r12, r1, lr */
/* @0x2a00e0 strb r1, [r7, #0x15] */
/* @0x2a00e4 sub sp, sp, #1024 */
/* @0x2a00e8 sub sp, sp, #8 */
/* @0x2a00ec mov r3, #0 */
/* @0x2a00f0 ldr r1, [r8] */
/* @0x2a00f4 mov r6, #0 */
/* @0x2a00f8 strb r12, [r7, #0x14] */
/* @0x2a00fc mov r4, #0 */
/* @0x2a0100 strb lr, [r7, #0x10] */
/* @0x2a0104 mov r5, #0 */
/* @0x2a0108 strb r3, [r7, #0x11] */
/* @0x2a010c strb r3, [r7, #0x12] */
/* @0x2a0110 strb r3, [r7, #0x13] */
/* @0x2a0114 str r1, [sp, #0x404] */
/* @0x2a0118 ldr r1, [r10, r0] */
/* @0x2a011c mov r0, #12 */
/* @0x2a0120 str r2, [r7, #0x2c] */
/* @0x2a0124 strd r4, r5, [r7, #32] */
/* @0x2a0128 ldrb r1, [r1] */
/* @0x2a012c strd r4, r5, [r7, #72] */
/* @0x2a0130 cmp r1, r3 */
/* @0x2a0134 strd r4, r5, [r7, #64] */
/* @0x2a0138 strbne r3, [r7, #0x14] */
/* @0x2a013c strd r4, r5, [r7, #88] */
/* @0x2a0140 strd r4, r5, [r7, #96] */
/* @0x2a0144 str r6, [r7, #0x28] */
/* @0x2a0148 str r6, [r7, #0x18] */
/* @0x2a014c str r6, [r7, #0x30] */
/* @0x2a0150 bl 0x27c524 <_Znwj> */
/* @0x2a0154 ldr r1, [pc, #0x1f0] */
/* @0x2a0158 mov r3, #10 */
/* @0x2a015c mov r2, #55 */
/* @0x2a0160 add r1, pc, r1 */
/* @0x2a0164 mov r4, r0 */
/* @0x2a0168 str r6, [r0, #0x4] */
/* @0x2a016c str r3, [r4, #0x8] */
/* @0x2a0170 mov r0, #240 */
/* @0x2a0174 mov r3, #1 */
/* @0x2a0178 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x2a017c ldr r2, [pc, #0x1cc] */
/* @0x2a0180 ldr r3, [pc, #0x1cc] */
/* @0x2a0184 str r0, [r4] */
/* @0x2a0188 mov r0, #12 */
/* @0x2a018c str r4, [r7, #0x8] */
/* @0x2a0190 ldr r2, [r10, r2] */
/* @0x2a0194 ldr r2, [r2] */
/* @0x2a0198 str r2, [r7, #0x34] */
/* @0x2a019c ldr r3, [r10, r3] */
/* @0x2a01a0 ldr r3, [r3] */
/* @0x2a01a4 str r3, [r7, #0x38] */
/* @0x2a01a8 bl 0x27c524 <_Znwj> */
/* @0x2a01ac ldr r1, [pc, #0x1a4] */
/* @0x2a01b0 mov r2, #80 */
/* @0x2a01b4 mov r3, #1 */
/* @0x2a01b8 add r1, pc, r1 */
/* @0x2a01bc mov r4, r0 */
/* @0x2a01c0 mov r0, #5120 */
/* @0x2a01c4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x2a01c8 ldr r1, [pc, #0x18c] */
/* @0x2a01cc mov r3, #128 */
/* @0x2a01d0 str r3, [r4] */
/* @0x2a01d4 mvn r3, #0 */
/* @0x2a01d8 mov r12, r0 */
/* @0x2a01dc str r0, [r4, #0x8] */
/* @0x2a01e0 ldrb r2, [r12, #0x3] */
/* @0x2a01e4 mov r0, #1 */
/* @0x2a01e8 str r4, [r7, #0xc] */
/* @0x2a01ec ldr r1, [r10, r1] */
/* @0x2a01f0 and r2, r2, #240 */
/* @0x2a01f4 str r0, [r4, #0x4] */
/* @0x2a01f8 bfi r2, r6, #4, #4 */
/* @0x2a01fc strb r6, [r12, #0x1] */
/* @0x2a0200 strb r6, [r1] */
/* @0x2a0204 strb r2, [r12, #0x3] */
/* @0x2a0208 strb r6, [r12, #0x2] */
/* @0x2a020c strb r6, [r12] */
/* @0x2a0210 strb r6, [r12, #0x8] */
/* @0x2a0214 strb r6, [r12, #0x9] */
/* @0x2a0218 strb r6, [r12, #0xa] */
/* @0x2a021c strb r6, [r12, #0xb] */
/* @0x2a0220 strb r6, [r12, #0xc] */
/* @0x2a0224 strb r6, [r12, #0xd] */
/* @0x2a0228 strb r6, [r12, #0xe] */
/* @0x2a022c strb r6, [r12, #0xf] */
/* @0x2a0230 strb r6, [r12, #0x10] */
/* @0x2a0234 strb r6, [r12, #0x11] */
/* @0x2a0238 strb r6, [r12, #0x12] */
/* @0x2a023c strb r6, [r12, #0x13] */
/* @0x2a0240 strb r6, [r12, #0x14] */
/* @0x2a0244 strb r6, [r12, #0x15] */
/* @0x2a0248 strb r6, [r12, #0x16] */
/* @0x2a024c strb r6, [r12, #0x17] */
/* @0x2a0250 strb r3, [r12, #0x18] */
/* @0x2a0254 strb r3, [r12, #0x19] */
/* @0x2a0258 strb r3, [r12, #0x1a] */
/* @0x2a025c strb r3, [r12, #0x1b] */
/* @0x2a0260 strb r3, [r12, #0x1c] */
/* @0x2a0264 strb r3, [r12, #0x1d] */
/* @0x2a0268 strb r3, [r12, #0x1e] */
/* @0x2a026c ldrb r2, [r7, #0x14] */
/* @0x2a0270 strb r3, [r12, #0x1f] */
/* @0x2a0274 cmp r2, r6 */
/* @0x2a0278 strb r6, [r12, #0x20] */
/* @0x2a027c strb r6, [r12, #0x21] */
/* @0x2a0280 strb r6, [r12, #0x22] */
/* @0x2a0284 strb r6, [r12, #0x23] */
/* @0x2a0288 str r6, [r7, #0x70] */
/* @0x2a028c streq r2, [r7, #0x74] */
/* @0x2a0290 streq r2, [r7, #0x78] */
/* @0x2a0294 bne 0x2a02ec <_ZN9CProfiler4InitEPKci+0x23c> */
/* @0x2a0298 ldrb r3, [r7, #0x15] */
/* @0x2a029c cmp r3, #0 */
/* @0x2a02a0 bne 0x2a02c0 <_ZN9CProfiler4InitEPKci+0x210> */
/* @0x2a02a4 ldr r2, [sp, #0x404] */
/* @0x2a02a8 ldr r3, [r8] */
/* @0x2a02ac cmp r2, r3 */
/* @0x2a02b0 bne 0x2a033c <_ZN9CProfiler4InitEPKci+0x28c> */
/* @0x2a02b4 add sp, sp, #1024 */
/* @0x2a02b8 add sp, sp, #8 */
/* @0x2a02bc pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2a02c0 mov r3, #1 */
/* @0x2a02c4 mov r0, r9 */
/* @0x2a02c8 strb r3, [r7, #0x11] */
/* @0x2a02cc bl 0x214f5c <_Z15ExtractFilePathPKc> */
/* @0x2a02d0 ldrb r3, [r0] */
/* @0x2a02d4 cmp r3, #0 */
/* @0x2a02d8 beq 0x2a0318 <_ZN9CProfiler4InitEPKci+0x268> */
/* @0x2a02dc mov r0, r9 */
/* @0x2a02e0 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x2a02e4 str r0, [r7, #0x18] */
/* @0x2a02e8 b 0x2a02a4 <_ZN9CProfiler4InitEPKci+0x1f4> */
/* @0x2a02ec ldr r1, [pc, #0x6c] */
/* @0x2a02f0 mov r2, #32768 */
/* @0x2a02f4 str r6, [r7, #0x7c] */
/* @0x2a02f8 mov r3, r6 */
/* @0x2a02fc str r2, [r7, #0x78] */
/* @0x2a0300 mov r0, #131072 */
/* @0x2a0304 mov r2, #76 */
/* @0x2a0308 add r1, pc, r1 */
/* @0x2a030c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x2a0310 str r0, [r7, #0x74] */
/* @0x2a0314 b 0x2a0298 <_ZN9CProfiler4InitEPKci+0x1e8> */
/* @0x2a0318 add r4, sp, #4 */
/* @0x2a031c mov r2, r9 */
/* @0x2a0320 mov r1, #1024 */
/* @0x2a0324 mov r0, r4 */
/* @0x2a0328 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x2a032c mov r0, r4 */
/* @0x2a0330 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x2a0334 str r0, [r7, #0x18] */
/* @0x2a0338 b 0x2a02a4 <_ZN9CProfiler4InitEPKci+0x1f4> */
/* @0x2a033c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2a0340 andseq r1, r5, r8, lsl #23 */
/* @0x2a0344 .word 0xffffbd00 */
/* @0x2a0348 .word 0xffffbcd4 */
/* @0x2a034c andeq r5, r11, r4, lsr #1 */
/* @0x2a0350 .word 0xffffbec4 */
/* @0x2a0354 .word 0xffffbed8 */
/* @0x2a0358 strheq r9, [r11], -r12 */
/* @0x2a035c .word 0xffffbf18 */
/* @0x2a0360 muleq r11, r12, r9 */

/* ── FUNC 0x2a0364 · CProfiler::Clean() · size=148 · insn=37 */
/* @0x2a0364 ldrb r3, [r0, #0x10] */
/* @0x2a0368 push {r4, r5, r6, lr} */
/* @0x2a036c cmp r3, #0 */
/* @0x2a0370 mov r4, r0 */
/* @0x2a0374 popeq {r4, r5, r6, pc} */
/* @0x2a0378 ldr r5, [r0, #0x8] */
/* @0x2a037c mov r3, #0 */
/* @0x2a0380 strb r3, [r0, #0x10] */
/* @0x2a0384 cmp r5, r3 */
/* @0x2a0388 strb r3, [r0, #0x11] */
/* @0x2a038c beq 0x2a03a0 <_ZN9CProfiler5CleanEv+0x3c> */
/* @0x2a0390 ldr r0, [r5] */
/* @0x2a0394 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2a0398 mov r0, r5 */
/* @0x2a039c bl 0x27d1d0 <_ZdlPv> */
/* @0x2a03a0 ldr r5, [r4, #0xc] */
/* @0x2a03a4 mov r6, #0 */
/* @0x2a03a8 str r6, [r4, #0x8] */
/* @0x2a03ac cmp r5, r6 */
/* @0x2a03b0 beq 0x2a03c8 <_ZN9CProfiler5CleanEv+0x64> */
/* @0x2a03b4 ldr r0, [r5, #0x8] */
/* @0x2a03b8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2a03bc str r6, [r5, #0x8] */
/* @0x2a03c0 mov r0, r5 */
/* @0x2a03c4 bl 0x27d1d0 <_ZdlPv> */
/* @0x2a03c8 mov r5, #0 */
/* @0x2a03cc ldr r0, [r4, #0x74] */
/* @0x2a03d0 str r5, [r4, #0xc] */
/* @0x2a03d4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2a03d8 ldr r0, [r4, #0x28] */
/* @0x2a03dc str r5, [r4, #0x74] */
/* @0x2a03e0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2a03e4 str r5, [r4, #0x28] */
/* @0x2a03e8 ldr r0, [r4, #0x18] */
/* @0x2a03ec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2a03f0 str r5, [r4, #0x18] */
/* @0x2a03f4 pop {r4, r5, r6, pc} */

/* ── FUNC 0x2a03f8 · CProfiler::BeginFrame() · size=192 · insn=48 */
/* @0x2a03f8 ldrb r3, [r0, #0x11] */
/* @0x2a03fc ldr r12, [pc, #0xa8] */
/* @0x2a0400 cmp r3, #0 */
/* @0x2a0404 push {r4, r5, r6, r7, r8, lr} */
/* @0x2a0408 add r12, pc, r12 */
/* @0x2a040c mov r8, r0 */
/* @0x2a0410 beq 0x2a048c <_ZN9CProfiler10BeginFrameEv+0x94> */
/* @0x2a0414 ldrb r4, [r0, #0x12] */
/* @0x2a0418 cmp r4, #0 */
/* @0x2a041c bne 0x2a048c <_ZN9CProfiler10BeginFrameEv+0x94> */
/* @0x2a0420 ldr r5, [pc, #0x88] */
/* @0x2a0424 mov lr, #1 */
/* @0x2a0428 ldr r6, [pc, #0x84] */
/* @0x2a042c mov r3, #0 */
/* @0x2a0430 ldrd r0, r1, [r0] */
/* @0x2a0434 mov r2, #0 */
/* @0x2a0438 ldr r7, [r12, r5] */
/* @0x2a043c strb lr, [r8, #0x13] */
/* @0x2a0440 ldr r5, [r8, #0x8] */
/* @0x2a0444 strb lr, [r7] */
/* @0x2a0448 ldr r12, [r12, r6] */
/* @0x2a044c strd r0, r1, [r12] */
/* @0x2a0450 strd r2, r3, [r8] */
/* @0x2a0454 str r4, [r5, #0x4] */
/* @0x2a0458 str r4, [r8, #0x70] */
/* @0x2a045c bl 0x215148 <Timing_Time> */
/* @0x2a0460 ldrd r6, r7, [r8, #64] */
/* @0x2a0464 orrs r3, r6, r7 */
/* @0x2a0468 beq 0x2a0484 <_ZN9CProfiler10BeginFrameEv+0x8c> */
/* @0x2a046c ldrd r4, r5, [r8, #80] */
/* @0x2a0470 subs r4, r4, r6 */
/* @0x2a0474 sbc r5, r5, r7 */
/* @0x2a0478 adds r4, r4, r0 */
/* @0x2a047c adc r5, r5, r1 */
/* @0x2a0480 strd r4, r5, [r8, #80] */
/* @0x2a0484 strd r0, r1, [r8, #64] */
/* @0x2a0488 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2a048c ldr r1, [pc, #0x1c] */
/* @0x2a0490 mov r0, #0 */
/* @0x2a0494 mov r2, #0 */
/* @0x2a0498 mov r3, #0 */
/* @0x2a049c ldr r1, [r12, r1] */
/* @0x2a04a0 strd r2, r3, [r8, #64] */
/* @0x2a04a4 strb r0, [r1] */
/* @0x2a04a8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2a04ac andseq r1, r5, r8, asr #16 */
/* @0x2a04b0 .word 0xffffbf18 */
/* @0x2a04b4 .word 0xffffef4c */

/* ── FUNC 0x2a04b8 · CProfiler::Pause(bool) · size=32 · insn=8 */
/* @0x2a04b8 cmp r1, #0 */
/* @0x2a04bc strb r1, [r0, #0x12] */
/* @0x2a04c0 ldrne r3, [pc, #0xc] */
/* @0x2a04c4 movne r2, #0 */
/* @0x2a04c8 ldrne r3, [pc, r3] */
/* @0x2a04cc strbne r2, [r3] */
/* @0x2a04d0 bx lr */
/* @0x2a04d4 andseq sp, r4, r0, lsr #13 */

/* ── FUNC 0x2a04d8 · CProfiler::Enable(bool) · size=28 · insn=7 */
/* @0x2a04d8 cmp r1, #0 */
/* @0x2a04dc strb r1, [r0, #0x11] */
/* @0x2a04e0 ldreq r3, [pc, #0x8] */
/* @0x2a04e4 ldreq r3, [pc, r3] */
/* @0x2a04e8 strbeq r1, [r3] */
/* @0x2a04ec bx lr */
/* @0x2a04f0 andseq sp, r4, r4, lsl #13 */

/* ── FUNC 0x2a04f4 · CProfiler::FindOrCreateNode(int, int) · size=476 · insn=119 */
/* @0x2a04f4 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2a04f8 mov r6, r0 */
/* @0x2a04fc ldr r8, [r0, #0x70] */
/* @0x2a0500 sub sp, sp, #8 */
/* @0x2a0504 ldr r7, [r0, #0xc] */
/* @0x2a0508 add r8, r8, r8, lsl #2 */
/* @0x2a050c ldr r12, [r7, #0x8] */
/* @0x2a0510 lsl r8, r8, #3 */
/* @0x2a0514 add r3, r12, r8 */
/* @0x2a0518 ldr r4, [r3, #0x18] */
/* @0x2a051c cmn r4, #1 */
/* @0x2a0520 beq 0x2a057c <_ZN9CProfiler16FindOrCreateNodeEii+0x88> */
/* @0x2a0524 mov r0, r4 */
/* @0x2a0528 b 0x2a0540 <_ZN9CProfiler16FindOrCreateNodeEii+0x4c> */
/* @0x2a052c ldr r3, [r3, #0x1c] */
/* @0x2a0530 mov r0, r4 */
/* @0x2a0534 cmn r3, #1 */
/* @0x2a0538 beq 0x2a057c <_ZN9CProfiler16FindOrCreateNodeEii+0x88> */
/* @0x2a053c mov r4, r3 */
/* @0x2a0540 add r3, r4, r4, lsl #2 */
/* @0x2a0544 ldr r5, [r12, r3, lsl #3] */
/* @0x2a0548 add r3, r12, r3, lsl #3 */
/* @0x2a054c ubfx r5, r5, #0x0, #0x1c */
/* @0x2a0550 cmp r5, r2 */
/* @0x2a0554 bne 0x2a052c <_ZN9CProfiler16FindOrCreateNodeEii+0x38> */
/* @0x2a0558 ldrb r5, [r3, #0x3] */
/* @0x2a055c cmp r1, r5, lsr #4 */
/* @0x2a0560 bne 0x2a052c <_ZN9CProfiler16FindOrCreateNodeEii+0x38> */
/* @0x2a0564 cmp r4, #0 */
/* @0x2a0568 blt 0x2a0578 <_ZN9CProfiler16FindOrCreateNodeEii+0x84> */
/* @0x2a056c mov r0, r4 */
/* @0x2a0570 add sp, sp, #8 */
/* @0x2a0574 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2a0578 mov r4, r0 */
/* @0x2a057c ldr r3, [r7] */
/* @0x2a0580 bic r5, r2, #-268435456 */
/* @0x2a0584 ldr r2, [r7, #0x4] */
/* @0x2a0588 and r9, r1, #15 */
/* @0x2a058c sub r1, r3, #1 */
/* @0x2a0590 cmp r2, r1 */
/* @0x2a0594 movlt r1, r2 */
/* @0x2a0598 movlt r6, r7 */
/* @0x2a059c blt 0x2a05e8 <_ZN9CProfiler16FindOrCreateNodeEii+0xf4> */
/* @0x2a05a0 lsl r2, r3, #1 */
/* @0x2a05a4 str r2, [r7] */
/* @0x2a05a8 add r1, r2, r3, lsl #3 */
/* @0x2a05ac ldr r2, [pc, #0x118] */
/* @0x2a05b0 mov r0, r12 */
/* @0x2a05b4 mov r3, #104 */
/* @0x2a05b8 mov r12, #0 */
/* @0x2a05bc lsl r1, r1, #3 */
/* @0x2a05c0 str r12, [sp] */
/* @0x2a05c4 add r2, pc, r2 */
/* @0x2a05c8 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x2a05cc ldr r8, [r6, #0x70] */
/* @0x2a05d0 ldr r1, [r7, #0x4] */
/* @0x2a05d4 ldr r6, [r6, #0xc] */
/* @0x2a05d8 add r8, r8, r8, lsl #2 */
/* @0x2a05dc lsl r8, r8, #3 */
/* @0x2a05e0 mov r12, r0 */
/* @0x2a05e4 str r0, [r7, #0x8] */
/* @0x2a05e8 add r2, r1, r1, lsl #2 */
/* @0x2a05ec add r3, r1, #1 */
/* @0x2a05f0 str r3, [r7, #0x4] */
/* @0x2a05f4 ubfx r10, r5, #0x8, #0x8 */
/* @0x2a05f8 lsl r2, r2, #3 */
/* @0x2a05fc ubfx r7, r5, #0x10, #0x8 */
/* @0x2a0600 add r3, r12, r2 */
/* @0x2a0604 mov r0, #0 */
/* @0x2a0608 strb r5, [r12, r2] */
/* @0x2a060c mvn r2, #0 */
/* @0x2a0610 ldrb r12, [r3, #0x3] */
/* @0x2a0614 strb r10, [r3, #0x1] */
/* @0x2a0618 bic r12, r12, #15 */
/* @0x2a061c strb r7, [r3, #0x2] */
/* @0x2a0620 orr r5, r12, r5, lsr #24 */
/* @0x2a0624 strb r0, [r3, #0x8] */
/* @0x2a0628 strb r0, [r3, #0x9] */
/* @0x2a062c bfi r5, r9, #4, #4 */
/* @0x2a0630 strb r0, [r3, #0xa] */
/* @0x2a0634 strb r5, [r3, #0x3] */
/* @0x2a0638 strb r0, [r3, #0xb] */
/* @0x2a063c strb r0, [r3, #0xc] */
/* @0x2a0640 strb r0, [r3, #0xd] */
/* @0x2a0644 strb r0, [r3, #0xe] */
/* @0x2a0648 strb r0, [r3, #0xf] */
/* @0x2a064c strb r0, [r3, #0x10] */
/* @0x2a0650 strb r0, [r3, #0x11] */
/* @0x2a0654 strb r0, [r3, #0x12] */
/* @0x2a0658 strb r0, [r3, #0x13] */
/* @0x2a065c strb r0, [r3, #0x14] */
/* @0x2a0660 strb r0, [r3, #0x15] */
/* @0x2a0664 strb r0, [r3, #0x16] */
/* @0x2a0668 strb r0, [r3, #0x17] */
/* @0x2a066c strb r0, [r3, #0x20] */
/* @0x2a0670 strb r0, [r3, #0x21] */
/* @0x2a0674 strb r0, [r3, #0x22] */
/* @0x2a0678 strb r2, [r3, #0x18] */
/* @0x2a067c strb r2, [r3, #0x19] */
/* @0x2a0680 strb r2, [r3, #0x1a] */
/* @0x2a0684 strb r2, [r3, #0x1b] */
/* @0x2a0688 strb r2, [r3, #0x1c] */
/* @0x2a068c strb r2, [r3, #0x1d] */
/* @0x2a0690 strb r2, [r3, #0x1e] */
/* @0x2a0694 strb r2, [r3, #0x1f] */
/* @0x2a0698 strb r0, [r3, #0x23] */
/* @0x2a069c ldr r3, [r6, #0x8] */
/* @0x2a06a0 add r8, r3, r8 */
/* @0x2a06a4 ldr r2, [r8, #0x18] */
/* @0x2a06a8 cmp r2, r0 */
/* @0x2a06ac strlt r1, [r8, #0x18] */
/* @0x2a06b0 addge r4, r4, r4, lsl #2 */
/* @0x2a06b4 addge r3, r3, r4, lsl #3 */
/* @0x2a06b8 mov r4, r1 */
/* @0x2a06bc mov r0, r4 */
/* @0x2a06c0 strge r1, [r3, #0x1c] */
/* @0x2a06c4 add sp, sp, #8 */
/* @0x2a06c8 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2a06cc strheq r9, [r11], -r0 */

/* ── FUNC 0x2a06d0 · CProfiler::AddNodeDirect(int, int, unsigned int) · size=104 · insn=26 */
/* @0x2a06d0 ldr r12, [pc, #0x5c] */
/* @0x2a06d4 push {r4, r5, r6, lr} */
/* @0x2a06d8 ldr r12, [pc, r12] */
/* @0x2a06dc mov r6, r3 */
/* @0x2a06e0 mov r4, r0 */
/* @0x2a06e4 ldrb r3, [r12] */
/* @0x2a06e8 cmp r3, #0 */
/* @0x2a06ec popeq {r4, r5, r6, pc} */
/* @0x2a06f0 bl 0x2a04f4 <_ZN9CProfiler16FindOrCreateNodeEii> */
/* @0x2a06f4 ldr r3, [r4, #0xc] */
/* @0x2a06f8 ldr r3, [r3, #0x8] */
/* @0x2a06fc add r0, r0, r0, lsl #2 */
/* @0x2a0700 add r0, r3, r0, lsl #3 */
/* @0x2a0704 ldrd r4, r5, [r0, #8] */
/* @0x2a0708 ldrd r2, r3, [r0, #16] */
/* @0x2a070c adds r4, r4, #1 */
/* @0x2a0710 ldr r1, [r0, #0x20] */
/* @0x2a0714 adc r5, r5, #0 */
/* @0x2a0718 adds r2, r2, r6 */
/* @0x2a071c adc r3, r3, #0 */
/* @0x2a0720 add r6, r1, r6 */
/* @0x2a0724 strd r4, r5, [r0, #8] */
/* @0x2a0728 strd r2, r3, [r0, #16] */
/* @0x2a072c str r6, [r0, #0x20] */
/* @0x2a0730 pop {r4, r5, r6, pc} */
/* @0x2a0734 mulseq r4, r0, r4 */

/* ── FUNC 0x2a0738 · CProfiler::Push(int, int) · size=312 · insn=78 */
/* @0x2a0738 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2a073c sub sp, sp, #24 */
/* @0x2a0740 mov r6, r0 */
/* @0x2a0744 mov r9, r1 */
/* @0x2a0748 mov r8, r2 */
/* @0x2a074c bl 0x215148 <Timing_Time> */
/* @0x2a0750 mov r2, r8 */
/* @0x2a0754 mov r4, r0 */
/* @0x2a0758 mov r5, r1 */
/* @0x2a075c mov r0, r6 */
/* @0x2a0760 mov r1, r9 */
/* @0x2a0764 bl 0x2a04f4 <_ZN9CProfiler16FindOrCreateNodeEii> */
/* @0x2a0768 ldr r7, [r6, #0x8] */
/* @0x2a076c str r9, [sp] */
/* @0x2a0770 str r8, [sp, #0x4] */
/* @0x2a0774 ldr r3, [r7, #0x4] */
/* @0x2a0778 ldr r2, [r7, #0x8] */
/* @0x2a077c cmp r3, r2 */
/* @0x2a0780 str r0, [r6, #0x70] */
/* @0x2a0784 str r0, [sp, #0x8] */
/* @0x2a0788 beq 0x2a0818 <_ZN9CProfiler4PushEii+0xe0> */
/* @0x2a078c ldr r9, [r7] */
/* @0x2a0790 mov r12, sp */
/* @0x2a0794 add r8, r3, r3, lsl #1 */
/* @0x2a0798 ldm r12!, {r0, r1, r2, r3} */
/* @0x2a079c lsl r8, r8, #3 */
/* @0x2a07a0 add lr, r9, r8 */
/* @0x2a07a4 str r0, [r9, r8] */
/* @0x2a07a8 str r1, [lr, #0x4] */
/* @0x2a07ac ldm r12!, {r0, r1} */
/* @0x2a07b0 str r2, [lr, #0x8] */
/* @0x2a07b4 str r3, [lr, #0xc] */
/* @0x2a07b8 str r0, [lr, #0x10] */
/* @0x2a07bc str r1, [lr, #0x14] */
/* @0x2a07c0 ldr r2, [r6, #0x8] */
/* @0x2a07c4 ldr r3, [r7, #0x4] */
/* @0x2a07c8 add r3, r3, #1 */
/* @0x2a07cc str r3, [r7, #0x4] */
/* @0x2a07d0 ldm r2, {r2, r3} */
/* @0x2a07d4 cmp r3, #0 */
/* @0x2a07d8 addgt r3, r3, r3, lsl #1 */
/* @0x2a07dc movle r7, #0 */
/* @0x2a07e0 addgt r7, r2, r3, lsl #3 */
/* @0x2a07e4 subgt r7, r7, #24 */
/* @0x2a07e8 bl 0x215148 <Timing_Time> */
/* @0x2a07ec ldrd r2, r3, [r6] */
/* @0x2a07f0 subs r2, r2, r4 */
/* @0x2a07f4 sbc r3, r3, r5 */
/* @0x2a07f8 rsbs r4, r2, #0 */
/* @0x2a07fc rsc r5, r3, #0 */
/* @0x2a0800 adds r0, r0, r2 */
/* @0x2a0804 adc r1, r1, r3 */
/* @0x2a0808 strd r0, r1, [r6] */
/* @0x2a080c strd r4, r5, [r7, #16] */
/* @0x2a0810 add sp, sp, #24 */
/* @0x2a0814 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2a0818 add r8, r3, #10 */
/* @0x2a081c ldr r1, [pc, #0x48] */
/* @0x2a0820 mov r3, #1 */
/* @0x2a0824 mov r2, #40 */
/* @0x2a0828 add r0, r8, r8, lsl #1 */
/* @0x2a082c add r1, pc, r1 */
/* @0x2a0830 lsl r0, r0, #3 */
/* @0x2a0834 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x2a0838 ldr r2, [r7, #0x8] */
/* @0x2a083c ldr r1, [r7] */
/* @0x2a0840 add r2, r2, r2, lsl #1 */
/* @0x2a0844 lsl r2, r2, #3 */
/* @0x2a0848 mov r10, r0 */
/* @0x2a084c bl 0xb65bc <memcpy@plt> */
/* @0x2a0850 ldr r0, [r7] */
/* @0x2a0854 mov r9, r10 */
/* @0x2a0858 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2a085c ldr r3, [r7, #0x4] */
/* @0x2a0860 str r8, [r7, #0x8] */
/* @0x2a0864 str r10, [r7] */
/* @0x2a0868 b 0x2a0790 <_ZN9CProfiler4PushEii+0x58> */
/* @0x2a086c ldrdeq r4, r5, [r11], -r8 */

/* ── FUNC 0x2a0870 · CProfiler::BeginStep() · size=60 · insn=15 */
/* @0x2a0870 push {r4, r5, r6, r7, r8, lr} */
/* @0x2a0874 mov r8, r0 */
/* @0x2a0878 bl 0x215148 <Timing_Time> */
/* @0x2a087c ldrd r4, r5, [r8] */
/* @0x2a0880 mov r6, #0 */
/* @0x2a0884 mov r7, #0 */
/* @0x2a0888 mov r2, #21 */
/* @0x2a088c strd r6, r7, [r8, #104] */
/* @0x2a0890 subs r4, r0, r4 */
/* @0x2a0894 sbc r5, r1, r5 */
/* @0x2a0898 mov r0, r8 */
/* @0x2a089c strd r4, r5, [r8, #88] */
/* @0x2a08a0 mov r1, #6 */
/* @0x2a08a4 pop {r4, r5, r6, r7, r8, lr} */
/* @0x2a08a8 b 0x2a0738 <_ZN9CProfiler4PushEii> */

/* ── FUNC 0x2a08ac · CProfiler::Pop() · size=180 · insn=45 */
/* @0x2a08ac push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x2a08b0 mov r8, r0 */
/* @0x2a08b4 bl 0x215148 <Timing_Time> */
/* @0x2a08b8 ldr r4, [r8, #0x8] */
/* @0x2a08bc ldrd r2, r3, [r8] */
/* @0x2a08c0 ldr r6, [r8, #0xc] */
/* @0x2a08c4 ldm r4, {r9, r12} */
/* @0x2a08c8 subs r2, r0, r2 */
/* @0x2a08cc sbc r3, r1, r3 */
/* @0x2a08d0 cmp r12, #0 */
/* @0x2a08d4 subgt r12, r12, #1 */
/* @0x2a08d8 strgt r12, [r4, #0x4] */
/* @0x2a08dc movle r0, #0 */
/* @0x2a08e0 addgt r0, r12, r12, lsl #1 */
/* @0x2a08e4 addgt r0, r9, r0, lsl #3 */
/* @0x2a08e8 ldr r1, [r0, #0x8] */
/* @0x2a08ec ldrd r4, r5, [r0, #16] */
/* @0x2a08f0 ldr r0, [r6, #0x8] */
/* @0x2a08f4 add r1, r1, r1, lsl #2 */
/* @0x2a08f8 subs r2, r2, r4 */
/* @0x2a08fc sbc r3, r3, r5 */
/* @0x2a0900 add r3, r0, r1, lsl #3 */
/* @0x2a0904 ldrd r6, r7, [r3, #8] */
/* @0x2a0908 ldrd r4, r5, [r3, #16] */
/* @0x2a090c adds r6, r6, #1 */
/* @0x2a0910 ldr r1, [r3, #0x20] */
/* @0x2a0914 adc r7, r7, #0 */
/* @0x2a0918 adds r4, r4, r2 */
/* @0x2a091c adc r5, r5, #0 */
/* @0x2a0920 cmp r12, #0 */
/* @0x2a0924 add r2, r1, r2 */
/* @0x2a0928 strd r6, r7, [r3, #8] */
/* @0x2a092c strd r4, r5, [r3, #16] */
/* @0x2a0930 str r2, [r3, #0x20] */
/* @0x2a0934 ble 0x2a0954 <_ZN9CProfiler3PopEv+0xa8> */
/* @0x2a0938 add r12, r12, r12, lsl #1 */
/* @0x2a093c add r9, r9, r12, lsl #3 */
/* @0x2a0940 subs r9, r9, #24 */
/* @0x2a0944 beq 0x2a0954 <_ZN9CProfiler3PopEv+0xa8> */
/* @0x2a0948 ldr r3, [r9, #0x8] */
/* @0x2a094c str r3, [r8, #0x70] */
/* @0x2a0950 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2a0954 mov r3, #0 */
/* @0x2a0958 str r3, [r8, #0x70] */
/* @0x2a095c pop {r3, r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x2a0960 · CProfiler::EndStep() · size=64 · insn=16 */
/* @0x2a0960 push {r4, r5, r6, r7, r8, lr} */
/* @0x2a0964 mov r8, r0 */
/* @0x2a0968 bl 0x2a08ac <_ZN9CProfiler3PopEv> */
/* @0x2a096c bl 0x215148 <Timing_Time> */
/* @0x2a0970 ldrd r4, r5, [r8] */
/* @0x2a0974 ldrd r2, r3, [r8, #88] */
/* @0x2a0978 ldrd r6, r7, [r8, #96] */
/* @0x2a097c subs r0, r0, r4 */
/* @0x2a0980 sbc r1, r1, r5 */
/* @0x2a0984 subs r0, r0, r2 */
/* @0x2a0988 sbc r1, r1, r3 */
/* @0x2a098c strd r0, r1, [r8, #104] */
/* @0x2a0990 adds r4, r6, r0 */
/* @0x2a0994 adc r5, r7, r1 */
/* @0x2a0998 strd r4, r5, [r8, #96] */
/* @0x2a099c pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x2a09a0 · CProfiler::ResetData() · size=320 · insn=80 */
/* @0x2a09a0 push {r4, r5, r6, lr} */
/* @0x2a09a4 mov r12, #0 */
/* @0x2a09a8 ldr r1, [r0, #0x8] */
/* @0x2a09ac mov r2, #0 */
/* @0x2a09b0 ldr r5, [r0, #0xc] */
/* @0x2a09b4 mov r3, #0 */
/* @0x2a09b8 str r12, [r0, #0x30] */
/* @0x2a09bc sub sp, sp, #8 */
/* @0x2a09c0 strd r2, r3, [r0, #72] */
/* @0x2a09c4 mov r4, r0 */
/* @0x2a09c8 strd r2, r3, [r0, #96] */
/* @0x2a09cc strd r2, r3, [r0, #80] */
/* @0x2a09d0 str r12, [r1, #0x4] */
/* @0x2a09d4 ldr r1, [r5] */
/* @0x2a09d8 str r12, [r5, #0x4] */
/* @0x2a09dc cmp r1, #1 */
/* @0x2a09e0 ble 0x2a0a98 <_ZN9CProfiler9ResetDataEv+0xf8> */
/* @0x2a09e4 ldr r1, [r5, #0x8] */
/* @0x2a09e8 mov r6, r12 */
/* @0x2a09ec mov r2, #1 */
/* @0x2a09f0 add r3, r1, r12 */
/* @0x2a09f4 str r2, [r5, #0x4] */
/* @0x2a09f8 mov r2, #0 */
/* @0x2a09fc strb r2, [r1, r12] */
/* @0x2a0a00 ldrb r0, [r3, #0x3] */
/* @0x2a0a04 mvn r1, #0 */
/* @0x2a0a08 strb r2, [r3, #0x1] */
/* @0x2a0a0c and r0, r0, #240 */
/* @0x2a0a10 strb r2, [r3, #0x2] */
/* @0x2a0a14 strb r2, [r3, #0x8] */
/* @0x2a0a18 bfi r0, r2, #4, #4 */
/* @0x2a0a1c strb r2, [r3, #0x9] */
/* @0x2a0a20 strb r2, [r3, #0xa] */
/* @0x2a0a24 strb r2, [r3, #0xb] */
/* @0x2a0a28 strb r2, [r3, #0xc] */
/* @0x2a0a2c strb r2, [r3, #0xd] */
/* @0x2a0a30 strb r2, [r3, #0xe] */
/* @0x2a0a34 strb r2, [r3, #0xf] */
/* @0x2a0a38 strb r2, [r3, #0x10] */
/* @0x2a0a3c strb r2, [r3, #0x11] */
/* @0x2a0a40 strb r2, [r3, #0x12] */
/* @0x2a0a44 strb r2, [r3, #0x13] */
/* @0x2a0a48 strb r2, [r3, #0x14] */
/* @0x2a0a4c strb r2, [r3, #0x15] */
/* @0x2a0a50 strb r2, [r3, #0x16] */
/* @0x2a0a54 strb r2, [r3, #0x17] */
/* @0x2a0a58 strb r2, [r3, #0x20] */
/* @0x2a0a5c strb r2, [r3, #0x21] */
/* @0x2a0a60 strb r2, [r3, #0x22] */
/* @0x2a0a64 strb r0, [r3, #0x3] */
/* @0x2a0a68 strb r1, [r3, #0x18] */
/* @0x2a0a6c strb r1, [r3, #0x19] */
/* @0x2a0a70 strb r1, [r3, #0x1a] */
/* @0x2a0a74 strb r1, [r3, #0x1b] */
/* @0x2a0a78 strb r1, [r3, #0x1c] */
/* @0x2a0a7c strb r1, [r3, #0x1d] */
/* @0x2a0a80 strb r1, [r3, #0x1e] */
/* @0x2a0a84 strb r1, [r3, #0x1f] */
/* @0x2a0a88 strb r2, [r3, #0x23] */
/* @0x2a0a8c str r6, [r4, #0x70] */
/* @0x2a0a90 add sp, sp, #8 */
/* @0x2a0a94 pop {r4, r5, r6, pc} */
/* @0x2a0a98 lsl r3, r1, #1 */
/* @0x2a0a9c ldr r2, [pc, #0x38] */
/* @0x2a0aa0 add r1, r3, r1, lsl #3 */
/* @0x2a0aa4 str r3, [r5] */
/* @0x2a0aa8 ldr r0, [r5, #0x8] */
/* @0x2a0aac add r2, pc, r2 */
/* @0x2a0ab0 lsl r1, r1, #3 */
/* @0x2a0ab4 str r12, [sp] */
/* @0x2a0ab8 mov r3, #104 */
/* @0x2a0abc bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x2a0ac0 ldr r6, [r5, #0x4] */
/* @0x2a0ac4 add r2, r6, #1 */
/* @0x2a0ac8 add r12, r6, r6, lsl #2 */
/* @0x2a0acc lsl r12, r12, #3 */
/* @0x2a0ad0 mov r1, r0 */
/* @0x2a0ad4 str r0, [r5, #0x8] */
/* @0x2a0ad8 b 0x2a09f0 <_ZN9CProfiler9ResetDataEv+0x50> */
/* @0x2a0adc andeq r9, r11, r8, asr #3 */

/* ── FUNC 0x2a0ae0 · CProfiler::WriteProfileData(Buffer_Standard*) · size=960 · insn=240 */
/* @0x2a0ae0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2a0ae4 vpush {d8} */
/* @0x2a0ae8 mov r9, r0 */
/* @0x2a0aec ldrb r8, [r0, #0x13] */
/* @0x2a0af0 sub sp, sp, #36 */
/* @0x2a0af4 mov r4, r1 */
/* @0x2a0af8 cmp r8, #0 */
/* @0x2a0afc bne 0x2a0b0c <_ZN9CProfiler16WriteProfileDataEP15Buffer_Standard+0x2c> */
/* @0x2a0b00 ldr r10, [r0, #0x30] */
/* @0x2a0b04 cmp r10, #0 */
/* @0x2a0b08 bne 0x2a0b40 <_ZN9CProfiler16WriteProfileDataEP15Buffer_Standard+0x60> */
/* @0x2a0b0c mov r2, r4 */
/* @0x2a0b10 mov r3, #0 */
/* @0x2a0b14 ldr r12, [r2], #44 */
/* @0x2a0b18 mov r0, r4 */
/* @0x2a0b1c str r3, [r4, #0x2c] */
/* @0x2a0b20 mov r1, #6 */
/* @0x2a0b24 str r3, [r4, #0x30] */
/* @0x2a0b28 ldr r12, [r12, #0x8] */
/* @0x2a0b2c str r3, [r4, #0x38] */
/* @0x2a0b30 blx r12 */
/* @0x2a0b34 add sp, sp, #36 */
/* @0x2a0b38 vpop {d8} */
/* @0x2a0b3c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2a0b40 vmov s13, r10 */
/* @0x2a0b44 ldr r3, [r1] */
/* @0x2a0b48 add r6, r1, #44 */
/* @0x2a0b4c str r8, [r1, #0x38] */
/* @0x2a0b50 vcvt.f64.s32 d6, s13 */
/* @0x2a0b54 mov r0, r1 */
/* @0x2a0b58 mov r2, r6 */
/* @0x2a0b5c mov r1, #6 */
/* @0x2a0b60 vldr d8, [pc, #816] */
/* @0x2a0b64 vmov r10, r11, d6 */
/* @0x2a0b68 vstr s12, [r4, #44] */
/* @0x2a0b6c str r11, [r4, #0x30] */
/* @0x2a0b70 ldr r3, [r3, #0x8] */
/* @0x2a0b74 blx r3 */
/* @0x2a0b78 ldrd r0, r1, [r9, #72] */
/* @0x2a0b7c bl 0x319150 <__floatundidf> */
/* @0x2a0b80 ldr r3, [r4] */
/* @0x2a0b84 mov r2, r6 */
/* @0x2a0b88 str r8, [r4, #0x38] */
/* @0x2a0b8c vmov d6, r0, r1 */
/* @0x2a0b90 mov r1, #8 */
/* @0x2a0b94 mov r0, r4 */
/* @0x2a0b98 vdiv.f64 d7, d6, d8 */
/* @0x2a0b9c vcvt.f32.f64 s14, d7 */
/* @0x2a0ba0 vcvt.f64.f32 d6, s14 */
/* @0x2a0ba4 vmov r10, r11, d6 */
/* @0x2a0ba8 vstr s12, [r4, #44] */
/* @0x2a0bac str r11, [r4, #0x30] */
/* @0x2a0bb0 ldr r3, [r3, #0x8] */
/* @0x2a0bb4 blx r3 */
/* @0x2a0bb8 ldrd r0, r1, [r9, #96] */
/* @0x2a0bbc bl 0x319150 <__floatundidf> */
/* @0x2a0bc0 ldr r3, [r4] */
/* @0x2a0bc4 mov r2, r6 */
/* @0x2a0bc8 str r8, [r4, #0x38] */
/* @0x2a0bcc vmov d6, r0, r1 */
/* @0x2a0bd0 mov r1, #8 */
/* @0x2a0bd4 mov r0, r4 */
/* @0x2a0bd8 vdiv.f64 d7, d6, d8 */
/* @0x2a0bdc vcvt.f32.f64 s14, d7 */
/* @0x2a0be0 vcvt.f64.f32 d6, s14 */
/* @0x2a0be4 vmov r10, r11, d6 */
/* @0x2a0be8 vstr s12, [r4, #44] */
/* @0x2a0bec str r11, [r4, #0x30] */
/* @0x2a0bf0 ldr r3, [r3, #0x8] */
/* @0x2a0bf4 blx r3 */
/* @0x2a0bf8 ldrd r0, r1, [r9, #80] */
/* @0x2a0bfc bl 0x319150 <__floatundidf> */
/* @0x2a0c00 ldr r3, [r4] */
/* @0x2a0c04 mov r2, r6 */
/* @0x2a0c08 str r8, [r4, #0x38] */
/* @0x2a0c0c vmov d7, r0, r1 */
/* @0x2a0c10 mov r1, #8 */
/* @0x2a0c14 mov r0, r4 */
/* @0x2a0c18 vdiv.f64 d8, d7, d8 */
/* @0x2a0c1c vcvt.f32.f64 s16, d8 */
/* @0x2a0c20 vcvt.f64.f32 d6, s16 */
/* @0x2a0c24 vmov r10, r11, d6 */
/* @0x2a0c28 vstr s12, [r4, #44] */
/* @0x2a0c2c str r11, [r4, #0x30] */
/* @0x2a0c30 ldr r3, [r3, #0x8] */
/* @0x2a0c34 blx r3 */
/* @0x2a0c38 ldr r12, [r9, #0xc] */
/* @0x2a0c3c ldr r3, [r4] */
/* @0x2a0c40 mov r2, r6 */
/* @0x2a0c44 mov r0, r4 */
/* @0x2a0c48 mov r1, #6 */
/* @0x2a0c4c ldr r12, [r12, #0x4] */
/* @0x2a0c50 str r8, [r4, #0x38] */
/* @0x2a0c54 vmov s15, r12 */
/* @0x2a0c58 str r12, [sp, #0x1c] */
/* @0x2a0c5c vcvt.f64.s32 d7, s15 */
/* @0x2a0c60 vmov r10, r11, d7 */
/* @0x2a0c64 vstr s14, [r4, #44] */
/* @0x2a0c68 str r11, [r4, #0x30] */
/* @0x2a0c6c ldr r3, [r3, #0x8] */
/* @0x2a0c70 blx r3 */
/* @0x2a0c74 ldr r3, [sp, #0x1c] */
/* @0x2a0c78 cmp r3, #1 */
/* @0x2a0c7c ble 0x2a0db0 <_ZN9CProfiler16WriteProfileDataEP15Buffer_Standard+0x2d0> */
/* @0x2a0c80 movw r11, #0x86a0 */
/* @0x2a0c84 movt r11, #0x1 */
/* @0x2a0c88 mov r10, r8 */
/* @0x2a0c8c mov r7, r8 */
/* @0x2a0c90 mov r3, r11 */
/* @0x2a0c94 mov r11, r9 */
/* @0x2a0c98 mov r9, r3 */
/* @0x2a0c9c ldr r3, [r11, #0xc] */
/* @0x2a0ca0 mov r1, #5 */
/* @0x2a0ca4 ldr r12, [r4] */
/* @0x2a0ca8 mov r0, r4 */
/* @0x2a0cac add r10, r10, #1 */
/* @0x2a0cb0 ldr r3, [r3, #0x8] */
/* @0x2a0cb4 add r5, r3, r8 */
/* @0x2a0cb8 ldr r3, [r3, r8] */
/* @0x2a0cbc add r8, r8, #40 */
/* @0x2a0cc0 ldrb r2, [r5, #0x3] */
/* @0x2a0cc4 ubfx r3, r3, #0x0, #0x1c */
/* @0x2a0cc8 str r7, [r4, #0x38] */
/* @0x2a0ccc lsr r2, r2, #4 */
/* @0x2a0cd0 mla r3, r9, r2, r3 */
/* @0x2a0cd4 mov r2, r6 */
/* @0x2a0cd8 vmov s12, r3 */
/* @0x2a0cdc vcvt.f64.s32 d7, s12 */
/* @0x2a0ce0 vstr s14, [r4, #44] */
/* @0x2a0ce4 vstr s15, [r4, #48] */
/* @0x2a0ce8 ldr r3, [r12, #0x8] */
/* @0x2a0cec blx r3 */
/* @0x2a0cf0 vldr s14, [r5, #8] */
/* @0x2a0cf4 vcvt.f64.u32 d7, s14 */
/* @0x2a0cf8 ldr r12, [r4] */
/* @0x2a0cfc mov r1, #5 */
/* @0x2a0d00 mov r2, r6 */
/* @0x2a0d04 mov r0, r4 */
/* @0x2a0d08 str r7, [r4, #0x38] */
/* @0x2a0d0c vstr s14, [r4, #44] */
/* @0x2a0d10 vstr s15, [r4, #48] */
/* @0x2a0d14 ldr r3, [r12, #0x8] */
/* @0x2a0d18 blx r3 */
/* @0x2a0d1c vldr s14, [r5, #16] */
/* @0x2a0d20 vcvt.f64.u32 d7, s14 */
/* @0x2a0d24 ldr r12, [r4] */
/* @0x2a0d28 mov r1, #5 */
/* @0x2a0d2c mov r2, r6 */
/* @0x2a0d30 mov r0, r4 */
/* @0x2a0d34 str r7, [r4, #0x38] */
/* @0x2a0d38 vstr s14, [r4, #44] */
/* @0x2a0d3c vstr s15, [r4, #48] */
/* @0x2a0d40 ldr r3, [r12, #0x8] */
/* @0x2a0d44 blx r3 */
/* @0x2a0d48 vldr s14, [r5, #24] */
/* @0x2a0d4c vcvt.f64.s32 d7, s14 */
/* @0x2a0d50 ldr r12, [r4] */
/* @0x2a0d54 mov r1, #6 */
/* @0x2a0d58 mov r2, r6 */
/* @0x2a0d5c mov r0, r4 */
/* @0x2a0d60 str r7, [r4, #0x38] */
/* @0x2a0d64 vstr s14, [r4, #44] */
/* @0x2a0d68 vstr s15, [r4, #48] */
/* @0x2a0d6c ldr r3, [r12, #0x8] */
/* @0x2a0d70 blx r3 */
/* @0x2a0d74 vldr s14, [r5, #28] */
/* @0x2a0d78 vcvt.f64.s32 d7, s14 */
/* @0x2a0d7c ldr r3, [r4] */
/* @0x2a0d80 mov r0, r4 */
/* @0x2a0d84 str r7, [r4, #0x38] */
/* @0x2a0d88 mov r1, #6 */
/* @0x2a0d8c mov r2, r6 */
/* @0x2a0d90 vstr s14, [r4, #44] */
/* @0x2a0d94 vstr s15, [r4, #48] */
/* @0x2a0d98 ldr r3, [r3, #0x8] */
/* @0x2a0d9c blx r3 */
/* @0x2a0da0 ldr r3, [sp, #0x1c] */
/* @0x2a0da4 cmp r10, r3 */
/* @0x2a0da8 bne 0x2a0c9c <_ZN9CProfiler16WriteProfileDataEP15Buffer_Standard+0x1bc> */
/* @0x2a0dac mov r9, r11 */
/* @0x2a0db0 ldrb r3, [r9, #0x14] */
/* @0x2a0db4 cmp r3, #0 */
/* @0x2a0db8 bne 0x2a0e0c <_ZN9CProfiler16WriteProfileDataEP15Buffer_Standard+0x32c> */
/* @0x2a0dbc ldr r12, [r4] */
/* @0x2a0dc0 mov r2, r6 */
/* @0x2a0dc4 str r3, [r4, #0x2c] */
/* @0x2a0dc8 mov r0, r4 */
/* @0x2a0dcc str r3, [r4, #0x30] */
/* @0x2a0dd0 mov r1, #5 */
/* @0x2a0dd4 str r3, [r4, #0x38] */
/* @0x2a0dd8 ldr r3, [r12, #0x8] */
/* @0x2a0ddc blx r3 */
/* @0x2a0de0 ldr r3, [r4] */
/* @0x2a0de4 mov r0, r4 */
/* @0x2a0de8 ldr r2, [r4, #0x1c] */
/* @0x2a0dec mov r1, #0 */
/* @0x2a0df0 ldr r3, [r3, #0x10] */
/* @0x2a0df4 blx r3 */
/* @0x2a0df8 mov r0, r9 */
/* @0x2a0dfc add sp, sp, #36 */
/* @0x2a0e00 vpop {d8} */
/* @0x2a0e04 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2a0e08 b 0x2a09a0 <_ZN9CProfiler9ResetDataEv> */
/* @0x2a0e0c ldr r12, [r4] */
/* @0x2a0e10 mov r3, #0 */
/* @0x2a0e14 mov r5, r3 */
/* @0x2a0e18 mov r2, r6 */
/* @0x2a0e1c movt r3, #0x3ff0 */
/* @0x2a0e20 str r5, [r4, #0x2c] */
/* @0x2a0e24 str r3, [r4, #0x30] */
/* @0x2a0e28 mov r1, #5 */
/* @0x2a0e2c ldr r3, [r12, #0x8] */
/* @0x2a0e30 mov r0, r4 */
/* @0x2a0e34 str r5, [r4, #0x38] */
/* @0x2a0e38 blx r3 */
/* @0x2a0e3c ldr r6, [r4, #0x1c] */
/* @0x2a0e40 ldr r2, [r9, #0x7c] */
/* @0x2a0e44 mov r12, #1 */
/* @0x2a0e48 ldr r1, [r9, #0x74] */
/* @0x2a0e4c mov r3, r5 */
/* @0x2a0e50 mvn r0, #0 */
/* @0x2a0e54 str r12, [sp, #0x8] */
/* @0x2a0e58 lsl r2, r2, #2 */
/* @0x2a0e5c str r0, [sp] */
/* @0x2a0e60 str r5, [sp, #0xc] */
/* @0x2a0e64 mov r0, r4 */
/* @0x2a0e68 str r5, [sp, #0x10] */
/* @0x2a0e6c str r6, [sp, #0x4] */
/* @0x2a0e70 bl 0xccabc <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb> */
/* @0x2a0e74 ldr r3, [r4] */
/* @0x2a0e78 mov r1, r5 */
/* @0x2a0e7c ldr r3, [r3, #0x10] */
/* @0x2a0e80 add r2, r6, r0 */
/* @0x2a0e84 mov r0, r4 */
/* @0x2a0e88 blx r3 */
/* @0x2a0e8c str r5, [r9, #0x7c] */
/* @0x2a0e90 b 0x2a0de0 <_ZN9CProfiler16WriteProfileDataEP15Buffer_Standard+0x300> */
/* @0x2a0e94 nop */
/* @0x2a0e98 andeq r0, r0, r0 */
/* @0x2a0e9c addmi r4, pc, r0 */

/* ── FUNC 0x2a0ea0 · CProfiler::DumpProfileData() · size=1488 · insn=372 */
/* @0x2a0ea0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2a0ea4 vpush {d8, d9, d10} */
/* @0x2a0ea8 sub sp, sp, #308 */
/* @0x2a0eac ldr r9, [pc, #0x45c] */
/* @0x2a0eb0 mov r11, r0 */
/* @0x2a0eb4 ldr r3, [pc, #0x458] */
/* @0x2a0eb8 add r9, pc, r9 */
/* @0x2a0ebc ldr r1, [pc, #0x454] */
/* @0x2a0ec0 ldr r0, [r0, #0x18] */
/* @0x2a0ec4 ldr r3, [r9, r3] */
/* @0x2a0ec8 add r1, pc, r1 */
/* @0x2a0ecc str r3, [sp, #0x14] */
/* @0x2a0ed0 ldr r3, [r3] */
/* @0x2a0ed4 str r3, [sp, #0x12c] */
/* @0x2a0ed8 bl 0xb6844 <fopen@plt> */
/* @0x2a0edc ldr r3, [pc, #0x438] */
/* @0x2a0ee0 ldr r1, [pc, #0x438] */
/* @0x2a0ee4 ldr r2, [r11, #0x18] */
/* @0x2a0ee8 add r1, pc, r1 */
/* @0x2a0eec str r0, [sp, #0x10] */
/* @0x2a0ef0 ldr r3, [r9, r3] */
/* @0x2a0ef4 ldr r4, [r3] */
/* @0x2a0ef8 ldr r3, [r4] */
/* @0x2a0efc mov r0, r4 */
/* @0x2a0f00 ldr r3, [r3, #0xc] */
/* @0x2a0f04 blx r3 */
/* @0x2a0f08 ldr r1, [sp, #0x10] */
/* @0x2a0f0c cmp r1, #0 */
/* @0x2a0f10 beq 0x2a1450 <_ZN9CProfiler15DumpProfileDataEv+0x5b0> */
/* @0x2a0f14 ldr r2, [r11, #0x28] */
/* @0x2a0f18 ldr r3, [pc, #0x404] */
/* @0x2a0f1c cmp r2, #0 */
/* @0x2a0f20 ldr r2, [sp, #0x10] */
/* @0x2a0f24 add r3, pc, r3 */
/* @0x2a0f28 str r2, [r3] */
/* @0x2a0f2c beq 0x2a13e4 <_ZN9CProfiler15DumpProfileDataEv+0x544> */
/* @0x2a0f30 ldrd r0, r1, [r11, #72] */
/* @0x2a0f34 vldr d8, [pc, #964] */
/* @0x2a0f38 bl 0x319150 <__floatundidf> */
/* @0x2a0f3c ldr r7, [r11, #0x30] */
/* @0x2a0f40 vmov s12, r7 */
/* @0x2a0f44 vcvt.f32.s32 s19, s12 */
/* @0x2a0f48 vmov d6, r0, r1 */
/* @0x2a0f4c ldrd r0, r1, [r11, #96] */
/* @0x2a0f50 vdiv.f64 d7, d6, d8 */
/* @0x2a0f54 vcvt.f32.f64 s18, d7 */
/* @0x2a0f58 bl 0x319150 <__floatundidf> */
/* @0x2a0f5c ldr r12, [r11, #0xc] */
/* @0x2a0f60 mov r2, #656 */
/* @0x2a0f64 mov r3, #1 */
/* @0x2a0f68 ldr r4, [r12, #0x4] */
/* @0x2a0f6c add r12, r4, r4, lsl #1 */
/* @0x2a0f70 vdiv.f32 s21, s18, s19 */
/* @0x2a0f74 vmov d7, r0, r1 */
/* @0x2a0f78 ldr r1, [pc, #0x3a8] */
/* @0x2a0f7c lsl r0, r12, #3 */
/* @0x2a0f80 add r1, pc, r1 */
/* @0x2a0f84 vdiv.f64 d8, d7, d8 */
/* @0x2a0f88 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x2a0f8c cmp r4, #1 */
/* @0x2a0f90 movle r1, #0 */
/* @0x2a0f94 mov r10, r0 */
/* @0x2a0f98 movle r8, r1 */
/* @0x2a0f9c vcvt.f32.f64 s16, d8 */
/* @0x2a0fa0 vdiv.f32 s19, s16, s19 */
/* @0x2a0fa4 ble 0x2a1058 <_ZN9CProfiler15DumpProfileDataEv+0x1b8> */
/* @0x2a0fa8 ldr r3, [r11, #0xc] */
/* @0x2a0fac add r4, r4, r4, lsl #2 */
/* @0x2a0fb0 vmov s15, r7 */
/* @0x2a0fb4 mov r8, #0 */
/* @0x2a0fb8 ldr r1, [r3, #0x8] */
/* @0x2a0fbc add r0, r1, r4, lsl #3 */
/* @0x2a0fc0 add r1, r1, #40 */
/* @0x2a0fc4 cmp r8, #0 */
/* @0x2a0fc8 ldr r4, [r1] */
/* @0x2a0fcc beq 0x2a1008 <_ZN9CProfiler15DumpProfileDataEv+0x168> */
/* @0x2a0fd0 ldr r3, [r10] */
/* @0x2a0fd4 cmp r3, r4 */
/* @0x2a0fd8 addne r2, r10, #24 */
/* @0x2a0fdc movne r3, #0 */
/* @0x2a0fe0 bne 0x2a0ffc <_ZN9CProfiler15DumpProfileDataEv+0x15c> */
/* @0x2a0fe4 b 0x2a1294 <_ZN9CProfiler15DumpProfileDataEv+0x3f4> */
/* @0x2a0fe8 mov r12, r2 */
/* @0x2a0fec add r2, r2, #24 */
/* @0x2a0ff0 ldr lr, [r12] */
/* @0x2a0ff4 cmp lr, r4 */
/* @0x2a0ff8 beq 0x2a1298 <_ZN9CProfiler15DumpProfileDataEv+0x3f8> */
/* @0x2a0ffc add r3, r3, #1 */
/* @0x2a1000 cmp r3, r8 */
/* @0x2a1004 bne 0x2a0fe8 <_ZN9CProfiler15DumpProfileDataEv+0x148> */
/* @0x2a1008 add r5, r8, r8, lsl #1 */
/* @0x2a100c ldrb r6, [r1, #0x3] */
/* @0x2a1010 ldrd r2, r3, [r1, #8] */
/* @0x2a1014 add r8, r8, #1 */
/* @0x2a1018 ldr lr, [r10, r5, lsl #3] */
/* @0x2a101c add r12, r10, r5, lsl #3 */
/* @0x2a1020 lsr r6, r6, #4 */
/* @0x2a1024 bfi lr, r4, #0, #28 */
/* @0x2a1028 str lr, [r10, r5, lsl #3] */
/* @0x2a102c ldrd r4, r5, [r1, #16] */
/* @0x2a1030 lsr lr, lr, #24 */
/* @0x2a1034 strd r2, r3, [r12, #8] */
/* @0x2a1038 bfi lr, r6, #4, #4 */
/* @0x2a103c strb lr, [r12, #0x3] */
/* @0x2a1040 strd r4, r5, [r12, #16] */
/* @0x2a1044 add r1, r1, #40 */
/* @0x2a1048 cmp r1, r0 */
/* @0x2a104c bne 0x2a0fc4 <_ZN9CProfiler15DumpProfileDataEv+0x124> */
/* @0x2a1050 vmov r7, s15 */
/* @0x2a1054 mov r1, r8 */
/* @0x2a1058 ldr r3, [pc, #0x2cc] */
/* @0x2a105c mov r2, #24 */
/* @0x2a1060 mov r0, r10 */
/* @0x2a1064 ldr r3, [r9, r3] */
/* @0x2a1068 bl 0xb66dc <qsort@plt> */
/* @0x2a106c bl 0x159cf4 <_Z23YoYo_GetPlatform_DoWorkv> */
/* @0x2a1070 ldr r2, [pc, #0x2b8] */
/* @0x2a1074 add r2, pc, r2 */
/* @0x2a1078 vmov d6, r0, r1 */
/* @0x2a107c vcvt.u32.f64 s13, d6 */
/* @0x2a1080 vmov r0, s13 */
/* @0x2a1084 cmp r0, #18 */
/* @0x2a1088 bls 0x2a13d4 <_ZN9CProfiler15DumpProfileDataEv+0x534> */
/* @0x2a108c ldr r3, [pc, #0x2a0] */
/* @0x2a1090 ldr r0, [pc, #0x2a0] */
/* @0x2a1094 ldr r5, [pc, #0x2a0] */
/* @0x2a1098 ldr r3, [r9, r3] */
/* @0x2a109c add r0, pc, r0 */
/* @0x2a10a0 add r5, pc, r5 */
/* @0x2a10a4 ldr r4, [pc, #0x294] */
/* @0x2a10a8 ldr r1, [r3] */
/* @0x2a10ac add r4, pc, r4 */
/* @0x2a10b0 bl 0x29ffec <_Z11cmpDumpNodePKvS0_+0x28> */
/* @0x2a10b4 ldr r1, [pc, #0x288] */
/* @0x2a10b8 mov r0, r5 */
/* @0x2a10bc mov r2, r7 */
/* @0x2a10c0 add r1, pc, r1 */
/* @0x2a10c4 bl 0x29ffec <_Z11cmpDumpNodePKvS0_+0x28> */
/* @0x2a10c8 vcvt.s32.f32 s18, s18 */
/* @0x2a10cc ldr r1, [pc, #0x274] */
/* @0x2a10d0 mov r0, r5 */
/* @0x2a10d4 add r1, pc, r1 */
/* @0x2a10d8 vmov r2, s18 */
/* @0x2a10dc bl 0x29ffec <_Z11cmpDumpNodePKvS0_+0x28> */
/* @0x2a10e0 vcvt.f64.f32 d7, s21 */
/* @0x2a10e4 ldr r1, [pc, #0x260] */
/* @0x2a10e8 mov r0, r4 */
/* @0x2a10ec add r1, pc, r1 */
/* @0x2a10f0 vmov r2, r3, d7 */
/* @0x2a10f4 bl 0x29ffec <_Z11cmpDumpNodePKvS0_+0x28> */
/* @0x2a10f8 ldr r1, [pc, #0x250] */
/* @0x2a10fc vcvt.f64.f32 d6, s19 */
/* @0x2a1100 mov r0, r4 */
/* @0x2a1104 add r1, pc, r1 */
/* @0x2a1108 vmov r2, r3, d6 */
/* @0x2a110c bl 0x29ffec <_Z11cmpDumpNodePKvS0_+0x28> */
/* @0x2a1110 ldr r0, [pc, #0x23c] */
/* @0x2a1114 add r0, pc, r0 */
/* @0x2a1118 bl 0x29ffec <_Z11cmpDumpNodePKvS0_+0x28> */
/* @0x2a111c ldr r3, [pc, #0x234] */
/* @0x2a1120 ldr r0, [pc, #0x234] */
/* @0x2a1124 add r3, pc, r3 */
/* @0x2a1128 ldr r1, [pc, #0x230] */
/* @0x2a112c str r3, [sp] */
/* @0x2a1130 add r0, pc, r0 */
/* @0x2a1134 ldr r2, [pc, #0x228] */
/* @0x2a1138 add r1, pc, r1 */
/* @0x2a113c ldr r3, [pc, #0x224] */
/* @0x2a1140 add r2, pc, r2 */
/* @0x2a1144 add r3, pc, r3 */
/* @0x2a1148 bl 0x29ffec <_Z11cmpDumpNodePKvS0_+0x28> */
/* @0x2a114c cmp r8, #0 */
/* @0x2a1150 beq 0x2a13a4 <_ZN9CProfiler15DumpProfileDataEv+0x504> */
/* @0x2a1154 ldr r1, [pc, #0x210] */
/* @0x2a1158 vmov s13, r7 */
/* @0x2a115c ldr r6, [pc, #0x20c] */
/* @0x2a1160 mov r4, r10 */
/* @0x2a1164 add r1, pc, r1 */
/* @0x2a1168 ldr r2, [pc, #0x204] */
/* @0x2a116c str r1, [sp, #0x18] */
/* @0x2a1170 vcvt.f64.s32 d10, s13 */
/* @0x2a1174 ldr r3, [pc, #0x1fc] */
/* @0x2a1178 add r2, pc, r2 */
/* @0x2a117c ldr r1, [pc, #0x1f8] */
/* @0x2a1180 add r6, pc, r6 */
/* @0x2a1184 add r3, pc, r3 */
/* @0x2a1188 str r2, [sp, #0x20] */
/* @0x2a118c add r1, pc, r1 */
/* @0x2a1190 mov r5, #0 */
/* @0x2a1194 str r3, [sp, #0x24] */
/* @0x2a1198 vldr d9, [pc, #360] */
/* @0x2a119c str r1, [sp, #0x1c] */
/* @0x2a11a0 b 0x2a1248 <_ZN9CProfiler15DumpProfileDataEv+0x3a8> */
/* @0x2a11a4 cmp r3, #0 */
/* @0x2a11a8 movne r7, r6 */
/* @0x2a11ac bne 0x2a11d8 <_ZN9CProfiler15DumpProfileDataEv+0x338> */
/* @0x2a11b0 ldr r3, [pc, #0x1c8] */
/* @0x2a11b4 ldr r3, [r9, r3] */
/* @0x2a11b8 ldr r3, [r3] */
/* @0x2a11bc cmp r12, r3 */
/* @0x2a11c0 bge 0x2a12c4 <_ZN9CProfiler15DumpProfileDataEv+0x424> */
/* @0x2a11c4 ldr r3, [pc, #0x1b8] */
/* @0x2a11c8 add r12, r12, r12, lsl #2 */
/* @0x2a11cc ldr r3, [r9, r3] */
/* @0x2a11d0 ldr r3, [r3] */
/* @0x2a11d4 add r7, r3, r12, lsl #4 */
/* @0x2a11d8 ldrd r0, r1, [r4, #16] */
/* @0x2a11dc add r5, r5, #1 */
/* @0x2a11e0 bl 0x319150 <__floatundidf> */
/* @0x2a11e4 add r4, r4, #24 */
/* @0x2a11e8 vmov d8, r0, r1 */
/* @0x2a11ec ldrd r0, r1, [r4, #-16] */
/* @0x2a11f0 bl 0x319150 <__floatundidf> */
/* @0x2a11f4 vmov d7, r0, r1 */
/* @0x2a11f8 ldr r0, [pc, #0x188] */
/* @0x2a11fc mov r1, r7 */
/* @0x2a1200 vdiv.f64 d6, d8, d7 */
/* @0x2a1204 add r0, pc, r0 */
/* @0x2a1208 vdiv.f64 d8, d8, d10 */
/* @0x2a120c vdiv.f64 d7, d7, d10 */
/* @0x2a1210 vmul.f64 d6, d6, d9 */
/* @0x2a1214 vmul.f64 d8, d8, d9 */
/* @0x2a1218 vcvt.f32.f64 s12, d6 */
/* @0x2a121c vcvt.f32.f64 s14, d7 */
/* @0x2a1220 vcvt.f64.f32 d6, s12 */
/* @0x2a1224 vcvt.f32.f64 s16, d8 */
/* @0x2a1228 vstr d6, [sp] */
/* @0x2a122c vcvt.f64.f32 d7, s14 */
/* @0x2a1230 vcvt.f64.f32 d6, s16 */
/* @0x2a1234 vstr d7, [sp, #8] */
/* @0x2a1238 vmov r2, r3, d6 */
/* @0x2a123c bl 0x29ffec <_Z11cmpDumpNodePKvS0_+0x28> */
/* @0x2a1240 cmp r5, r8 */
/* @0x2a1244 beq 0x2a13a4 <_ZN9CProfiler15DumpProfileDataEv+0x504> */
/* @0x2a1248 ldrb r3, [r4, #0x3] */
/* @0x2a124c ldr r12, [r4] */
/* @0x2a1250 lsr r3, r3, #4 */
/* @0x2a1254 ubfx r12, r12, #0x0, #0x1c */
/* @0x2a1258 cmp r3, #6 */
/* @0x2a125c beq 0x2a12cc <_ZN9CProfiler15DumpProfileDataEv+0x42c> */
/* @0x2a1260 cmp r3, #1 */
/* @0x2a1264 bne 0x2a11a4 <_ZN9CProfiler15DumpProfileDataEv+0x304> */
/* @0x2a1268 ldr r3, [pc, #0x124] */
/* @0x2a126c ldr r3, [r9, r3] */
/* @0x2a1270 ldr r3, [r3] */
/* @0x2a1274 cmp r12, r3 */
/* @0x2a1278 bge 0x2a12f8 <_ZN9CProfiler15DumpProfileDataEv+0x458> */
/* @0x2a127c ldr r3, [r11, #0x28] */
/* @0x2a1280 ldr r2, [sp, #0x24] */
/* @0x2a1284 ldr r7, [r3, r12, lsl #2] */
/* @0x2a1288 cmp r7, #0 */
/* @0x2a128c moveq r7, r2 */
/* @0x2a1290 b 0x2a11d8 <_ZN9CProfiler15DumpProfileDataEv+0x338> */
/* @0x2a1294 mov r12, r10 */
/* @0x2a1298 ldrd r2, r3, [r1, #8] */
/* @0x2a129c ldrd r4, r5, [r12, #8] */
/* @0x2a12a0 ldrd r6, r7, [r12, #16] */
/* @0x2a12a4 adds r2, r2, r4 */
/* @0x2a12a8 adc r3, r3, r5 */
/* @0x2a12ac strd r2, r3, [r12, #8] */
/* @0x2a12b0 ldrd r2, r3, [r1, #16] */
/* @0x2a12b4 adds r2, r2, r6 */
/* @0x2a12b8 adc r3, r3, r7 */
/* @0x2a12bc strd r2, r3, [r12, #16] */
/* @0x2a12c0 b 0x2a1044 <_ZN9CProfiler15DumpProfileDataEv+0x1a4> */
/* @0x2a12c4 ldr r7, [sp, #0x18] */
/* @0x2a12c8 b 0x2a11d8 <_ZN9CProfiler15DumpProfileDataEv+0x338> */
/* @0x2a12cc ldr r3, [pc, #0xb8] */
/* @0x2a12d0 mov r1, #256 */
/* @0x2a12d4 ldr r2, [sp, #0x1c] */
/* @0x2a12d8 add r3, pc, r3 */
/* @0x2a12dc add r3, r3, r12, lsl #2 */
/* @0x2a12e0 add r12, sp, #44 */
/* @0x2a12e4 ldr r3, [r3, #0x4c] */
/* @0x2a12e8 mov r0, r12 */
/* @0x2a12ec mov r7, r12 */
/* @0x2a12f0 bl 0xb65c8 <snprintf@plt> */
/* @0x2a12f4 b 0x2a11d8 <_ZN9CProfiler15DumpProfileDataEv+0x338> */
/* @0x2a12f8 ldr r7, [sp, #0x20] */
/* @0x2a12fc b 0x2a11d8 <_ZN9CProfiler15DumpProfileDataEv+0x338> */
/* @0x2a1300 andeq r0, r0, r0 */
/* @0x2a1304 addmi r4, pc, r0 */
/* @0x2a1308 and r0, r0, r0 */
/* @0x2a130c svclo #0x50624d */
/* @0x2a1310 mulseq r5, r8, sp */
/* @0x2a1314 .word 0xffffbd00 */
/* @0x2a1318 andeq pc, r9, r4, lsr #9 */
/* @0x2a131c .word 0xffffbac4 */
/* @0x2a1320 strdeq r8, r9, [r11], -r8 */
/* @0x2a1324 subeq r6, r11, r12, asr #30 */
/* @0x2a1328 andeq r8, r11, r4, lsr #26 */
/* @0x2a132c .word 0xfffffdc8 */
/* @0x2a1330 andeq r8, r11, r4, ror #24 */
/* @0x2a1334 .word 0xffffeed0 */
/* @0x2a1338 andeq r8, r11, r8, ror r12 */
/* @0x2a133c andeq r8, r11, r0, lsl #25 */
/* @0x2a1340 andeq r8, r11, r0, lsr #25 */
/* @0x2a1344 andeq r8, r11, r12, ror #24 */
/* @0x2a1348 andeq r8, r11, r8, ror #24 */
/* @0x2a134c andeq r8, r11, r12, ror #24 */
/* @0x2a1350 andeq r8, r11, r12, ror #24 */
/* @0x2a1354 andeq sp, r8, r2, lsr #20 */
/* @0x2a1358 muleq r11, r8, r12 */
/* @0x2a135c andeq r8, r11, r8, asr r12 */
/* @0x2a1360 andeq r8, r11, r8, ror #24 */
/* @0x2a1364 andeq r8, r11, r8, ror #24 */
/* @0x2a1368 andeq r8, r11, r0, ror r12 */
/* @0x2a136c andeq r8, r11, r8, ror r11 */
/* @0x2a1370 andeq r8, r11, r12, asr r11 */
/* @0x2a1374 andeq r8, r11, r4, ror #22 */
/* @0x2a1378 andeq r8, r11, r8, asr r11 */
/* @0x2a137c andeq r8, r11, r12, lsr r12 */
/* @0x2a1380 .word 0xffffbec4 */
/* @0x2a1384 .word 0xffffbec8 */
/* @0x2a1388 andeq r8, r11, r12, asr #23 */
/* @0x2a138c andseq r7, r4, r0, ror #6 */
/* @0x2a1390 andseq r7, r4, r0, ror #4 */
/* @0x2a1394 .word 0xffffbed8 */
/* @0x2a1398 andeq r8, r11, r12, lsr #17 */
/* @0x2a139c .word 0xffffbed0 */
/* @0x2a13a0 muleq r11, r12, r8 */
/* @0x2a13a4 ldr r0, [sp, #0x10] */
/* @0x2a13a8 bl 0xb6850 <fclose@plt> */
/* @0x2a13ac mov r0, r10 */
/* @0x2a13b0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2a13b4 ldr r1, [sp, #0x14] */
/* @0x2a13b8 ldr r2, [sp, #0x12c] */
/* @0x2a13bc ldr r3, [r1] */
/* @0x2a13c0 cmp r2, r3 */
/* @0x2a13c4 bne 0x2a146c <_ZN9CProfiler15DumpProfileDataEv+0x5cc> */
/* @0x2a13c8 add sp, sp, #308 */
/* @0x2a13cc vpop {d8, d9, d10} */
/* @0x2a13d0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2a13d4 ldr r3, [pc, #-0x4c] */
/* @0x2a13d8 add r3, pc, r3 */
/* @0x2a13dc ldr r2, [r3, r0, lsl #2] */
/* @0x2a13e0 b 0x2a108c <_ZN9CProfiler15DumpProfileDataEv+0x1ec> */
/* @0x2a13e4 ldr r0, [pc, #-0x58] */
/* @0x2a13e8 mov r3, #1 */
/* @0x2a13ec ldr r1, [pc, #-0x5c] */
/* @0x2a13f0 movw r2, #0x27b */
/* @0x2a13f4 ldr r4, [r9, r0] */
/* @0x2a13f8 add r1, pc, r1 */
/* @0x2a13fc ldr r0, [r4] */
/* @0x2a1400 lsl r0, r0, #2 */
/* @0x2a1404 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x2a1408 ldr r3, [pc, #-0x74] */
/* @0x2a140c str r0, [r11, #0x28] */
/* @0x2a1410 ldr r3, [r9, r3] */
/* @0x2a1414 ldr r3, [r3] */
/* @0x2a1418 cmp r3, #0 */
/* @0x2a141c beq 0x2a0f30 <_ZN9CProfiler15DumpProfileDataEv+0x90> */
/* @0x2a1420 ldr r1, [r4] */
/* @0x2a1424 ldr r2, [r3, #0x60] */
/* @0x2a1428 cmp r2, #0 */
/* @0x2a142c blt 0x2a1440 <_ZN9CProfiler15DumpProfileDataEv+0x5a0> */
/* @0x2a1430 cmp r2, r1 */
/* @0x2a1434 ldrlt r12, [r3, #0x5c] */
/* @0x2a1438 ldrlt r0, [r11, #0x28] */
/* @0x2a143c strlt r12, [r0, r2, lsl #2] */
/* @0x2a1440 ldr r3, [r3, #0x4] */
/* @0x2a1444 cmp r3, #0 */
/* @0x2a1448 bne 0x2a1424 <_ZN9CProfiler15DumpProfileDataEv+0x584> */
/* @0x2a144c b 0x2a0f30 <_ZN9CProfiler15DumpProfileDataEv+0x90> */
/* @0x2a1450 ldr r3, [r4] */
/* @0x2a1454 mov r0, r4 */
/* @0x2a1458 ldr r1, [pc, #-0xc0] */
/* @0x2a145c ldr r3, [r3, #0xc] */
/* @0x2a1460 add r1, pc, r1 */
/* @0x2a1464 blx r3 */
/* @0x2a1468 b 0x2a13b4 <_ZN9CProfiler15DumpProfileDataEv+0x514> */
/* @0x2a146c bl 0xb65d4 <__stack_chk_fail@plt> */

/* ── FUNC 0x2a1470 · CProfiler::ProfileDump() · size=40 · insn=10 */
/* @0x2a1470 ldrb r2, [r0, #0x10] */
/* @0x2a1474 cmp r2, #0 */
/* @0x2a1478 bxeq lr */
/* @0x2a147c ldrb r2, [r0, #0x15] */
/* @0x2a1480 cmp r2, #0 */
/* @0x2a1484 bxeq lr */
/* @0x2a1488 ldr r3, [r0, #0x18] */
/* @0x2a148c cmp r3, #0 */
/* @0x2a1490 bxeq lr */
/* @0x2a1494 b 0x2a0ea0 <_ZN9CProfiler15DumpProfileDataEv> */

/* ── FUNC 0x2a1498 · CProfiler::EndFrame() · size=548 · insn=137 */
/* @0x2a1498 ldr r3, [pc, #0x214] */
/* @0x2a149c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2a14a0 ldr r3, [pc, r3] */
/* @0x2a14a4 mov r10, #0 */
/* @0x2a14a8 sub sp, sp, #28 */
/* @0x2a14ac ldrb r3, [r3] */
/* @0x2a14b0 mov r4, r0 */
/* @0x2a14b4 strb r10, [r0, #0x13] */
/* @0x2a14b8 cmp r3, r10 */
/* @0x2a14bc bne 0x2a14c8 <_ZN9CProfiler8EndFrameEv+0x30> */
/* @0x2a14c0 add sp, sp, #28 */
/* @0x2a14c4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2a14c8 ldr r3, [r0, #0x30] */
/* @0x2a14cc add r3, r3, #1 */
/* @0x2a14d0 str r3, [r0, #0x30] */
/* @0x2a14d4 bl 0x215148 <Timing_Time> */
/* @0x2a14d8 ldrd r6, r7, [r4] */
/* @0x2a14dc ldrd r8, r9, [r4, #64] */
/* @0x2a14e0 ldrd r2, r3, [r4, #72] */
/* @0x2a14e4 strd r6, r7, [sp, #16] */
/* @0x2a14e8 adds r6, r6, r8 */
/* @0x2a14ec adc r7, r7, r9 */
/* @0x2a14f0 subs r2, r2, r6 */
/* @0x2a14f4 sbc r3, r3, r7 */
/* @0x2a14f8 str r0, [sp, #0x8] */
/* @0x2a14fc mov r5, r0 */
/* @0x2a1500 str r1, [sp, #0xc] */
/* @0x2a1504 ldrd r6, r7, [sp, #8] */
/* @0x2a1508 ldrb r0, [r4, #0x14] */
/* @0x2a150c adds r2, r2, r6 */
/* @0x2a1510 adc r3, r3, r7 */
/* @0x2a1514 cmp r0, r10 */
/* @0x2a1518 strd r2, r3, [r4, #72] */
/* @0x2a151c beq 0x2a161c <_ZN9CProfiler8EndFrameEv+0x184> */
/* @0x2a1520 ldr r2, [r4, #0xc] */
/* @0x2a1524 ldr r3, [r4, #0x7c] */
/* @0x2a1528 ldr r1, [r4, #0x78] */
/* @0x2a152c ldr r7, [r2, #0x4] */
/* @0x2a1530 add r2, r7, #1 */
/* @0x2a1534 add r2, r2, r2, lsl #1 */
/* @0x2a1538 add r2, r3, r2 */
/* @0x2a153c cmp r2, r1 */
/* @0x2a1540 bgt 0x2a1680 <_ZN9CProfiler8EndFrameEv+0x1e8> */
/* @0x2a1544 ldr r1, [r4, #0x74] */
/* @0x2a1548 ldr r0, [sp, #0x10] */
/* @0x2a154c rsb r5, r8, r5 */
/* @0x2a1550 add r2, r3, #1 */
/* @0x2a1554 str r2, [r4, #0x7c] */
/* @0x2a1558 rsb r5, r0, r5 */
/* @0x2a155c ldr r2, [r4, #0x68] */
/* @0x2a1560 str r5, [r1, r3, lsl #2] */
/* @0x2a1564 cmp r7, #1 */
/* @0x2a1568 ldr r3, [r4, #0x7c] */
/* @0x2a156c add r0, r3, #1 */
/* @0x2a1570 str r0, [r4, #0x7c] */
/* @0x2a1574 str r2, [r1, r3, lsl #2] */
/* @0x2a1578 ldr r3, [r4, #0x7c] */
/* @0x2a157c add r2, r3, #1 */
/* @0x2a1580 str r2, [r4, #0x7c] */
/* @0x2a1584 str r7, [r1, r3, lsl #2] */
/* @0x2a1588 ble 0x2a161c <_ZN9CProfiler8EndFrameEv+0x184> */
/* @0x2a158c ldr r11, [r4, #0xc] */
/* @0x2a1590 mov r2, #0 */
/* @0x2a1594 movw r10, #0x86a0 */
/* @0x2a1598 movt r10, #0x1 */
/* @0x2a159c mov r0, r2 */
/* @0x2a15a0 str r7, [sp, #0x10] */
/* @0x2a15a4 ldr r5, [r11, #0x8] */
/* @0x2a15a8 add r0, r0, #1 */
/* @0x2a15ac ldr r3, [sp, #0x10] */
/* @0x2a15b0 mov r7, #0 */
/* @0x2a15b4 ldr r12, [r4, #0x7c] */
/* @0x2a15b8 cmp r0, r3 */
/* @0x2a15bc add r3, r5, r2 */
/* @0x2a15c0 ldr r8, [r5, r2] */
/* @0x2a15c4 add r9, r12, #1 */
/* @0x2a15c8 ldrb r6, [r3, #0x3] */
/* @0x2a15cc add r2, r2, #40 */
/* @0x2a15d0 ubfx r8, r8, #0x0, #0x1c */
/* @0x2a15d4 ldr r5, [r3, #0x20] */
/* @0x2a15d8 str r7, [r3, #0x20] */
/* @0x2a15dc lsr r6, r6, #4 */
/* @0x2a15e0 str r9, [r4, #0x7c] */
/* @0x2a15e4 mla r6, r10, r6, r8 */
/* @0x2a15e8 str r6, [r1, r12, lsl #2] */
/* @0x2a15ec ldr r12, [r4, #0x7c] */
/* @0x2a15f0 add r6, r12, #1 */
/* @0x2a15f4 str r6, [r4, #0x7c] */
/* @0x2a15f8 str r5, [r1, r12, lsl #2] */
/* @0x2a15fc ldrh r5, [r3, #28] */
/* @0x2a1600 ldr r12, [r4, #0x7c] */
/* @0x2a1604 ldrh r3, [r3, #24] */
/* @0x2a1608 add r6, r12, #1 */
/* @0x2a160c str r6, [r4, #0x7c] */
/* @0x2a1610 orr r3, r3, r5, lsl #16 */
/* @0x2a1614 str r3, [r1, r12, lsl #2] */
/* @0x2a1618 bne 0x2a15a4 <_ZN9CProfiler8EndFrameEv+0x10c> */
/* @0x2a161c ldrb r3, [r4, #0x15] */
/* @0x2a1620 cmp r3, #0 */
/* @0x2a1624 beq 0x2a14c0 <_ZN9CProfiler8EndFrameEv+0x28> */
/* @0x2a1628 ldr r1, [r4, #0x2c] */
/* @0x2a162c cmp r1, #0 */
/* @0x2a1630 ble 0x2a14c0 <_ZN9CProfiler8EndFrameEv+0x28> */
/* @0x2a1634 ldrd r2, r3, [r4, #32] */
/* @0x2a1638 orrs r0, r2, r3 */
/* @0x2a163c ldrdeq r6, r7, [sp, #8] */
/* @0x2a1640 strdeq r6, r7, [r4, #32] */
/* @0x2a1644 beq 0x2a14c0 <_ZN9CProfiler8EndFrameEv+0x28> */
/* @0x2a1648 movw r0, #0x4240 */
/* @0x2a164c movt r0, #0xf */
/* @0x2a1650 ldrd r6, r7, [sp, #8] */
/* @0x2a1654 mul r0, r0, r1 */
/* @0x2a1658 subs r2, r6, r2 */
/* @0x2a165c sbc r3, r7, r3 */
/* @0x2a1660 asr r1, r0, #31 */
/* @0x2a1664 cmp r3, r1 */
/* @0x2a1668 cmpeq r2, r0 */
/* @0x2a166c bls 0x2a14c0 <_ZN9CProfiler8EndFrameEv+0x28> */
/* @0x2a1670 mov r0, r4 */
/* @0x2a1674 bl 0x2a0ea0 <_ZN9CProfiler15DumpProfileDataEv> */
/* @0x2a1678 strd r6, r7, [r4, #32] */
/* @0x2a167c b 0x2a14c0 <_ZN9CProfiler8EndFrameEv+0x28> */
/* @0x2a1680 ldr r2, [pc, #0x30] */
/* @0x2a1684 lsl r3, r1, #1 */
/* @0x2a1688 ldr r0, [r4, #0x74] */
/* @0x2a168c lsl r1, r1, #3 */
/* @0x2a1690 str r10, [sp] */
/* @0x2a1694 add r2, pc, r2 */
/* @0x2a1698 str r3, [r4, #0x78] */
/* @0x2a169c mov r3, #237 */
/* @0x2a16a0 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x2a16a4 ldr r3, [r4, #0x7c] */
/* @0x2a16a8 mov r1, r0 */
/* @0x2a16ac str r0, [r4, #0x74] */
/* @0x2a16b0 b 0x2a1548 <_ZN9CProfiler8EndFrameEv+0xb0> */
/* @0x2a16b4 andseq r12, r4, r8, asr #13 */
/* @0x2a16b8 andeq r8, r11, r0, lsl r6 */

/* ── FUNC 0x2a16bc · EndOfGame() · size=32 · insn=8 */
/* @0x2a16bc push {r3, lr} */
/* @0x2a16c0 bl 0x18b8a0 <_Z7IO_Quitv> */
/* @0x2a16c4 bl 0x21e9d0 <_Z7SND_Endv> */
/* @0x2a16c8 ldr r0, [pc, #0x8] */
/* @0x2a16cc pop {r3, lr} */
/* @0x2a16d0 ldr r0, [pc, r0] */
/* @0x2a16d4 b 0x2a1470 <_ZN9CProfiler11ProfileDumpEv> */
/* @0x2a16d8 mulseq r4, r12, r4 */

/* ── FUNC 0x2a16dc · DoTheWork() · size=184 · insn=46 */
/* @0x2a16dc push {r3, r4, r5, lr} */
/* @0x2a16e0 movw r0, #0x12e4 */
/* @0x2a16e4 movt r0, #0x20 */
/* @0x2a16e8 bl 0xb69c4 <srand48@plt> */
/* @0x2a16ec bl 0x1df59c <_Z13RunnerLoadWadv> */
/* @0x2a16f0 subs r4, r0, #0 */
/* @0x2a16f4 beq 0x2a1758 <_Z9DoTheWorkv+0x7c> */
/* @0x2a16f8 bl 0x1f3354 <_Z20Variable_Global_Initv> */
/* @0x2a16fc ldr r3, [pc, #0x7c] */
/* @0x2a1700 ldr r1, [pc, #0x7c] */
/* @0x2a1704 ldr r3, [pc, r3] */
/* @0x2a1708 add r1, pc, r1 */
/* @0x2a170c ldr r5, [r3] */
/* @0x2a1710 ldr r3, [r5] */
/* @0x2a1714 mov r0, r5 */
/* @0x2a1718 ldr r3, [r3, #0xc] */
/* @0x2a171c blx r3 */
/* @0x2a1720 bl 0x1df714 <_Z11PrepareGamev> */
/* @0x2a1724 subs r4, r0, #0 */
/* @0x2a1728 bne 0x2a1734 <_Z9DoTheWorkv+0x58> */
/* @0x2a172c mov r0, r4 */
/* @0x2a1730 pop {r3, r4, r5, pc} */
/* @0x2a1734 ldr r3, [r5] */
/* @0x2a1738 mov r0, r5 */
/* @0x2a173c ldr r1, [pc, #0x44] */
/* @0x2a1740 ldr r3, [r3, #0xc] */
/* @0x2a1744 add r1, pc, r1 */
/* @0x2a1748 blx r3 */
/* @0x2a174c bl 0x1d4ed8 <_Z9Run_Startv> */
/* @0x2a1750 mov r0, r4 */
/* @0x2a1754 pop {r3, r4, r5, pc} */
/* @0x2a1758 ldr r3, [pc, #0x2c] */
/* @0x2a175c ldr r1, [pc, #0x2c] */
/* @0x2a1760 ldr r3, [pc, r3] */
/* @0x2a1764 add r1, pc, r1 */
/* @0x2a1768 ldr r0, [r3] */
/* @0x2a176c ldr r3, [r0] */
/* @0x2a1770 ldr r3, [r3, #0xc] */
/* @0x2a1774 blx r3 */
/* @0x2a1778 mov r0, r4 */
/* @0x2a177c pop {r3, r4, r5, pc} */
/* @0x2a1780 andseq lr, r4, r8, lsl r4 */
/* @0x2a1784 andeq r8, r11, r8, lsr r9 */
/* @0x2a1788 andeq r8, r11, r12, lsl #18 */
/* @0x2a178c ldrheq r11, [r4], -r4 */
/* @0x2a1790 andeq r8, r11, r0, asr #17 */

/* ── FUNC 0x2a1794 · DrawSplash() · size=120 · insn=30 */
/* @0x2a1794 push {r3, r4, r5, lr} */
/* @0x2a1798 ldr r3, [pc, #0x68] */
/* @0x2a179c ldr r3, [pc, r3] */
/* @0x2a17a0 ldrb r4, [r3] */
/* @0x2a17a4 cmp r4, #0 */
/* @0x2a17a8 popne {r3, r4, r5, pc} */
/* @0x2a17ac bl 0x28fe44 <_Z19ShouldDisplaySplashv> */
/* @0x2a17b0 cmp r0, #0 */
/* @0x2a17b4 popeq {r3, r4, r5, pc} */
/* @0x2a17b8 bl 0x1689f4 <_Z32GR_D3D_Get_Texture_Interpolationv> */
/* @0x2a17bc mov r5, r0 */
/* @0x2a17c0 mov r0, #1 */
/* @0x2a17c4 bl 0x168710 <_Z32GR_D3D_Set_Texture_Interpolationb> */
/* @0x2a17c8 bl 0x1699c0 <_Z18GR_D3D_Start_Framev> */
/* @0x2a17cc mov r0, #-16777216 */
/* @0x2a17d0 bl 0x169f58 <_Z13GR_Draw_Clearj> */
/* @0x2a17d4 mov r0, r4 */
/* @0x2a17d8 bl 0x28fe40 <_Z8DrawLogoi> */
/* @0x2a17dc add r4, r4, #1 */
/* @0x2a17e0 mov r0, #1 */
/* @0x2a17e4 bl 0x169a58 <_Z19GR_D3D_Finish_Frameb> */
/* @0x2a17e8 bl 0x28fe64 <_Z15ProcessMessagesv> */
/* @0x2a17ec cmp r4, #5 */
/* @0x2a17f0 bne 0x2a17c8 <_Z10DrawSplashv+0x34> */
/* @0x2a17f4 mov r0, r5 */
/* @0x2a17f8 bl 0x168710 <_Z32GR_D3D_Set_Texture_Interpolationb> */
/* @0x2a17fc mvn r0, #0 */
/* @0x2a1800 pop {r3, r4, r5, lr} */
/* @0x2a1804 b 0x28fe40 <_Z8DrawLogoi> */
/* @0x2a1808 andseq r0, r5, r0, lsl #5 */

/* ── FUNC 0x2a180c · BeginToEnd() · size=1024 · insn=256 */
/* @0x2a180c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2a1810 sub sp, sp, #8 */
/* @0x2a1814 ldr r7, [pc, #0x364] */
/* @0x2a1818 mov r8, #1 */
/* @0x2a181c ldr r3, [pc, #0x360] */
/* @0x2a1820 movw r4, #0x70c */
/* @0x2a1824 add r7, pc, r7 */
/* @0x2a1828 ldr r1, [pc, #0x358] */
/* @0x2a182c ldr r3, [r7, r3] */
/* @0x2a1830 add r1, pc, r1 */
/* @0x2a1834 ldr r6, [r3] */
/* @0x2a1838 ldr r3, [r6] */
/* @0x2a183c mov r0, r6 */
/* @0x2a1840 ldr r3, [r3, #0xc] */
/* @0x2a1844 blx r3 */
/* @0x2a1848 mov r0, #8 */
/* @0x2a184c bl 0x27c524 <_Znwj> */
/* @0x2a1850 ldr r3, [pc, #0x334] */
/* @0x2a1854 ldr r3, [r7, r3] */
/* @0x2a1858 str r0, [r3] */
/* @0x2a185c bl 0xf1c90 <_ZN10Code_Error6CreateEv> */
/* @0x2a1860 ldr r3, [pc, #0x328] */
/* @0x2a1864 movw lr, #0x808c */
/* @0x2a1868 ldr r1, [r6] */
/* @0x2a186c mov r2, r8 */
/* @0x2a1870 mov r0, r6 */
/* @0x2a1874 ldr r12, [r7, r3] */
/* @0x2a1878 mov r3, #0 */
/* @0x2a187c stm sp, {r4, lr} */
/* @0x2a1880 strb r8, [r12] */
/* @0x2a1884 ldr r12, [r1, #0xc] */
/* @0x2a1888 ldr r1, [pc, #0x304] */
/* @0x2a188c add r1, pc, r1 */
/* @0x2a1890 blx r12 */
/* @0x2a1894 bl 0x1def08 <_Z14RunnerLoadGamev> */
/* @0x2a1898 mov r0, #0 */
/* @0x2a189c bl 0xb67fc <time@plt> */
/* @0x2a18a0 ldr r2, [pc, #0x2f0] */
/* @0x2a18a4 ldr r3, [r6] */
/* @0x2a18a8 ldr r1, [pc, #0x2ec] */
/* @0x2a18ac ldr r2, [r7, r2] */
/* @0x2a18b0 add r1, pc, r1 */
/* @0x2a18b4 ldr r3, [r3, #0xc] */
/* @0x2a18b8 mov r4, r0 */
/* @0x2a18bc asr r5, r0, #31 */
/* @0x2a18c0 mov r0, r6 */
/* @0x2a18c4 strd r4, r5, [r2] */
/* @0x2a18c8 blx r3 */
/* @0x2a18cc ldr r2, [pc, #0x2cc] */
/* @0x2a18d0 ldr r3, [pc, #0x2cc] */
/* @0x2a18d4 ldr r2, [r7, r2] */
/* @0x2a18d8 ldr r3, [r7, r3] */
/* @0x2a18dc ldr r0, [r2] */
/* @0x2a18e0 ldr r1, [r3] */
/* @0x2a18e4 bl 0x1dd46c <_Z13GetResolutionPhi> */
/* @0x2a18e8 ldr r3, [r6] */
/* @0x2a18ec ldr r1, [pc, #0x2b4] */
/* @0x2a18f0 mov r0, r6 */
/* @0x2a18f4 add r1, pc, r1 */
/* @0x2a18f8 ldr r3, [r3, #0xc] */
/* @0x2a18fc blx r3 */
/* @0x2a1900 ldr r2, [pc, #0x2a4] */
/* @0x2a1904 ldr r3, [pc, #0x2a4] */
/* @0x2a1908 ldr r2, [r7, r2] */
/* @0x2a190c ldr r3, [r7, r3] */
/* @0x2a1910 ldr r0, [r2] */
/* @0x2a1914 ldr r1, [r3] */
/* @0x2a1918 bl 0x1a8854 <_Z19CreateDesktopWindowii> */
/* @0x2a191c ldr r3, [r6] */
/* @0x2a1920 ldr r1, [pc, #0x28c] */
/* @0x2a1924 mov r0, r6 */
/* @0x2a1928 add r1, pc, r1 */
/* @0x2a192c ldr r3, [r3, #0xc] */
/* @0x2a1930 blx r3 */
/* @0x2a1934 bl 0x1df5f0 <_Z12InitGraphicsv> */
/* @0x2a1938 cmp r0, #0 */
/* @0x2a193c bne 0x2a1948 <_Z10BeginToEndv+0x13c> */
/* @0x2a1940 add sp, sp, #8 */
/* @0x2a1944 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2a1948 ldr r3, [r6] */
/* @0x2a194c mov r0, r6 */
/* @0x2a1950 ldr r1, [pc, #0x260] */
/* @0x2a1954 ldr r3, [r3, #0xc] */
/* @0x2a1958 add r1, pc, r1 */
/* @0x2a195c blx r3 */
/* @0x2a1960 bl 0x18c33c <_Z7IO_Initv> */
/* @0x2a1964 ldr r3, [r6] */
/* @0x2a1968 ldr r1, [pc, #0x24c] */
/* @0x2a196c mov r0, r6 */
/* @0x2a1970 add r1, pc, r1 */
/* @0x2a1974 ldr r3, [r3, #0xc] */
/* @0x2a1978 blx r3 */
/* @0x2a197c bl 0x28fe64 <_Z15ProcessMessagesv> */
/* @0x2a1980 ldr r3, [r6] */
/* @0x2a1984 ldr r1, [pc, #0x234] */
/* @0x2a1988 mov r0, r6 */
/* @0x2a198c add r1, pc, r1 */
/* @0x2a1990 ldr r3, [r3, #0xc] */
/* @0x2a1994 blx r3 */
/* @0x2a1998 bl 0x2a1794 <_Z10DrawSplashv> */
/* @0x2a199c ldr r3, [r6] */
/* @0x2a19a0 ldr r1, [pc, #0x21c] */
/* @0x2a19a4 mov r0, r6 */
/* @0x2a19a8 add r1, pc, r1 */
/* @0x2a19ac ldr r3, [r3, #0xc] */
/* @0x2a19b0 blx r3 */
/* @0x2a19b4 bl 0x1699c0 <_Z18GR_D3D_Start_Framev> */
/* @0x2a19b8 ldr r3, [r6] */
/* @0x2a19bc ldr r1, [pc, #0x204] */
/* @0x2a19c0 mov r0, r6 */
/* @0x2a19c4 add r1, pc, r1 */
/* @0x2a19c8 ldr r3, [r3, #0xc] */
/* @0x2a19cc blx r3 */
/* @0x2a19d0 bl 0x1a5a3c <_Z19Part_CreateTexturesv> */
/* @0x2a19d4 ldr r3, [r6] */
/* @0x2a19d8 ldr r1, [pc, #0x1ec] */
/* @0x2a19dc mov r0, r6 */
/* @0x2a19e0 add r1, pc, r1 */
/* @0x2a19e4 ldr r3, [r3, #0xc] */
/* @0x2a19e8 blx r3 */
/* @0x2a19ec bl 0x29bfc8 <_Z25Debug_InitRemoteInterfacev> */
/* @0x2a19f0 ldr r3, [r6] */
/* @0x2a19f4 ldr r1, [pc, #0x1d4] */
/* @0x2a19f8 mov r0, r6 */
/* @0x2a19fc ldr r3, [r3, #0xc] */
/* @0x2a1a00 add r1, pc, r1 */
/* @0x2a1a04 blx r3 */
/* @0x2a1a08 bl 0xd83a8 <_ZN2VM4InitEv> */
/* @0x2a1a0c ldr r3, [pc, #0x1c0] */
/* @0x2a1a10 ldr r3, [r7, r3] */
/* @0x2a1a14 ldr r3, [r3] */
/* @0x2a1a18 cmp r3, #0 */
/* @0x2a1a1c bne 0x2a1a48 <_Z10BeginToEndv+0x23c> */
/* @0x2a1a20 ldr r3, [pc, #0x1b0] */
/* @0x2a1a24 ldr r3, [r7, r3] */
/* @0x2a1a28 ldrb r3, [r3] */
/* @0x2a1a2c cmp r3, #0 */
/* @0x2a1a30 beq 0x2a1a48 <_Z10BeginToEndv+0x23c> */
/* @0x2a1a34 ldr r3, [pc, #0x1a0] */
/* @0x2a1a38 ldr r4, [r7, r3] */
/* @0x2a1a3c ldr r5, [r4] */
/* @0x2a1a40 cmp r5, #0 */
/* @0x2a1a44 beq 0x2a1ab4 <_Z10BeginToEndv+0x2a8> */
/* @0x2a1a48 ldr r3, [r6] */
/* @0x2a1a4c mov r0, r6 */
/* @0x2a1a50 ldr r1, [pc, #0x188] */
/* @0x2a1a54 ldr r3, [r3, #0xc] */
/* @0x2a1a58 add r1, pc, r1 */
/* @0x2a1a5c blx r3 */
/* @0x2a1a60 mov r0, #1 */
/* @0x2a1a64 bl 0x27c524 <_Znwj> */
/* @0x2a1a68 ldr r3, [pc, #0x174] */
/* @0x2a1a6c ldr r3, [r7, r3] */
/* @0x2a1a70 str r0, [r3] */
/* @0x2a1a74 bl 0x1dbe94 <_ZN9Run_Score6CreateEv> */
/* @0x2a1a78 ldr r3, [r6] */
/* @0x2a1a7c mov r0, r6 */
/* @0x2a1a80 ldr r1, [pc, #0x160] */
/* @0x2a1a84 ldr r3, [r3, #0xc] */
/* @0x2a1a88 add r1, pc, r1 */
/* @0x2a1a8c blx r3 */
/* @0x2a1a90 ldr r3, [r6] */
/* @0x2a1a94 ldr r1, [pc, #0x150] */
/* @0x2a1a98 mov r0, r6 */
/* @0x2a1a9c add r1, pc, r1 */
/* @0x2a1aa0 ldr r3, [r3, #0xc] */
/* @0x2a1aa4 blx r3 */
/* @0x2a1aa8 add sp, sp, #8 */
/* @0x2a1aac pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2a1ab0 b 0x2a16dc <_Z9DoTheWorkv> */
/* @0x2a1ab4 ldr r3, [pc, #0x134] */
/* @0x2a1ab8 ldr r1, [pc, #0x134] */
/* @0x2a1abc ldr r3, [r7, r3] */
/* @0x2a1ac0 add r1, pc, r1 */
/* @0x2a1ac4 ldr r9, [r3] */
/* @0x2a1ac8 ldr r3, [r9] */
/* @0x2a1acc mov r0, r9 */
/* @0x2a1ad0 ldr r3, [r3, #0xc] */
/* @0x2a1ad4 blx r3 */
/* @0x2a1ad8 mov r0, #8 */
/* @0x2a1adc bl 0x27c524 <_Znwj> */
/* @0x2a1ae0 ldr r3, [pc, #0x110] */
/* @0x2a1ae4 ldr r3, [r7, r3] */
/* @0x2a1ae8 ldrb r1, [r3] */
/* @0x2a1aec mov r10, r0 */
/* @0x2a1af0 bl 0x29cf24 <_ZN9DbgServerC2Eb> */
/* @0x2a1af4 mov r0, r10 */
/* @0x2a1af8 str r10, [r4] */
/* @0x2a1afc bl 0x29cf64 <_ZN9DbgServer4InitEv> */
/* @0x2a1b00 cmp r0, #0 */
/* @0x2a1b04 beq 0x2a1b40 <_Z10BeginToEndv+0x334> */
/* @0x2a1b08 ldr r2, [pc, #0xec] */
/* @0x2a1b0c ldr r3, [pc, #0xec] */
/* @0x2a1b10 ldr r2, [r7, r2] */
/* @0x2a1b14 ldr r3, [r7, r3] */
/* @0x2a1b18 ldrb r2, [r2] */
/* @0x2a1b1c eor r2, r2, r8 */
/* @0x2a1b20 strb r2, [r3] */
/* @0x2a1b24 bl 0x29ccc8 <_Z22DebuggerCreateIPSocketv> */
/* @0x2a1b28 ldr r3, [pc, #0xd4] */
/* @0x2a1b2c mov r0, r5 */
/* @0x2a1b30 ldr r3, [r7, r3] */
/* @0x2a1b34 strb r8, [r3] */
/* @0x2a1b38 bl 0x15f2a4 <_Z17YYPowersaveEnableb> */
/* @0x2a1b3c b 0x2a1a48 <_Z10BeginToEndv+0x23c> */
/* @0x2a1b40 ldr r3, [r9] */
/* @0x2a1b44 mov r0, r9 */
/* @0x2a1b48 ldr r1, [pc, #0xb8] */
/* @0x2a1b4c ldr r3, [r3, #0xc] */
/* @0x2a1b50 add r1, pc, r1 */
/* @0x2a1b54 blx r3 */
/* @0x2a1b58 ldr r5, [r4] */
/* @0x2a1b5c cmp r5, #0 */
/* @0x2a1b60 beq 0x2a1b74 <_Z10BeginToEndv+0x368> */
/* @0x2a1b64 mov r0, r5 */
/* @0x2a1b68 bl 0x29d038 <_ZN9DbgServerD2Ev> */
/* @0x2a1b6c mov r0, r5 */
/* @0x2a1b70 bl 0x27d1d0 <_ZdlPv> */
/* @0x2a1b74 mov r3, #0 */
/* @0x2a1b78 str r3, [r4] */
/* @0x2a1b7c b 0x2a1a48 <_Z10BeginToEndv+0x23c> */
/* @0x2a1b80 andseq r0, r5, r12, lsr #8 */
/* @0x2a1b84 .word 0xffffdecc */
/* @0x2a1b88 andeq r8, r11, r12, lsr #16 */
/* @0x2a1b8c .word 0xffffc138 */
/* @0x2a1b90 .word 0xfffffc00 */
/* @0x2a1b94 andeq r8, r11, r4, ror #15 */
/* @0x2a1b98 .word 0xfffffdd0 */
/* @0x2a1b9c andeq r8, r11, r4, asr #16 */
/* @0x2a1ba0 .word 0xfffff0bc */
/* @0x2a1ba4 .word 0xfffff0b8 */
/* @0x2a1ba8 andeq r8, r11, r0, lsl r8 */
/* @0x2a1bac .word 0xfffff05c */
/* @0x2a1bb0 .word 0xfffff060 */
/* @0x2a1bb4 andeq r8, r11, r12, ror #15 */
/* @0x2a1bb8 andeq r8, r11, r12, asr #15 */
/* @0x2a1bbc andeq r8, r11, r0, asr #15 */
/* @0x2a1bc0 strheq r8, [r11], -r8 */
/* @0x2a1bc4 andeq r8, r11, r8, lsr #15 */
/* @0x2a1bc8 muleq r11, r12, r7 */
/* @0x2a1bcc muleq r11, r8, r7 */
/* @0x2a1bd0 muleq r11, r8, r7 */
/* @0x2a1bd4 .word 0xffffc7d0 */
/* @0x2a1bd8 .word 0xfffff0a0 */
/* @0x2a1bdc .word 0xffffc0a4 */
/* @0x2a1be0 andeq r8, r11, r4, ror r7 */
/* @0x2a1be4 .word 0xfffffdd4 */
/* @0x2a1be8 andeq r8, r11, r8, asr r7 */
/* @0x2a1bec andeq r8, r11, r8, asr r7 */
/* @0x2a1bf0 .word 0xffffbcf0 */
/* @0x2a1bf4 andeq r8, r11, r4, ror #13 */
/* @0x2a1bf8 .word 0xfffffdd8 */
/* @0x2a1bfc .word 0xffffbcd4 */
/* @0x2a1c00 .word 0xffffbd2c */
/* @0x2a1c04 .word 0xffffdf9c */
/* @0x2a1c08 andeq r8, r11, r8, ror #12 */

/* ── FUNC 0x2a1c0c · GetNextCmd(int, char*) · size=228 · insn=57 */
/* @0x2a1c0c push {r4, r5, r6, lr} */
/* @0x2a1c10 cmp r1, #0 */
/* @0x2a1c14 ldr r5, [pc, #0xc8] */
/* @0x2a1c18 mov r3, #0 */
/* @0x2a1c1c mov r4, r0 */
/* @0x2a1c20 ldr r5, [pc, r5] */
/* @0x2a1c24 strb r3, [r5] */
/* @0x2a1c28 beq 0x2a1cdc <_Z10GetNextCmdiPc+0xd0> */
/* @0x2a1c2c ldrb r3, [r1, r0] */
/* @0x2a1c30 add r2, r1, r0 */
/* @0x2a1c34 cmp r3, #0 */
/* @0x2a1c38 beq 0x2a1cdc <_Z10GetNextCmdiPc+0xd0> */
/* @0x2a1c3c cmp r3, #32 */
/* @0x2a1c40 bls 0x2a1c50 <_Z10GetNextCmdiPc+0x44> */
/* @0x2a1c44 b 0x2a1c64 <_Z10GetNextCmdiPc+0x58> */
/* @0x2a1c48 cmp r3, #0 */
/* @0x2a1c4c beq 0x2a1cdc <_Z10GetNextCmdiPc+0xd0> */
/* @0x2a1c50 ldrb r3, [r2, #0x1]! */
/* @0x2a1c54 add r4, r4, #1 */
/* @0x2a1c58 cmp r3, #32 */
/* @0x2a1c5c bls 0x2a1c48 <_Z10GetNextCmdiPc+0x3c> */
/* @0x2a1c60 add r2, r1, r4 */
/* @0x2a1c64 mov r0, #0 */
/* @0x2a1c68 mov r12, r0 */
/* @0x2a1c6c b 0x2a1c84 <_Z10GetNextCmdiPc+0x78> */
/* @0x2a1c70 cmp r0, #0 */
/* @0x2a1c74 beq 0x2a1ca8 <_Z10GetNextCmdiPc+0x9c> */
/* @0x2a1c78 strb r3, [r5, r12] */
/* @0x2a1c7c add r12, r12, #1 */
/* @0x2a1c80 ldrb r3, [r2, #0x1]! */
/* @0x2a1c84 cmp r3, #0 */
/* @0x2a1c88 rsb r4, r1, r2 */
/* @0x2a1c8c beq 0x2a1ca8 <_Z10GetNextCmdiPc+0x9c> */
/* @0x2a1c90 cmp r3, #32 */
/* @0x2a1c94 bls 0x2a1c70 <_Z10GetNextCmdiPc+0x64> */
/* @0x2a1c98 cmp r3, #34 */
/* @0x2a1c9c eoreq r0, r0, #1 */
/* @0x2a1ca0 beq 0x2a1c80 <_Z10GetNextCmdiPc+0x74> */
/* @0x2a1ca4 b 0x2a1c78 <_Z10GetNextCmdiPc+0x6c> */
/* @0x2a1ca8 ldr r6, [pc, #0x38] */
/* @0x2a1cac mov r0, r5 */
/* @0x2a1cb0 mov r3, #0 */
/* @0x2a1cb4 strb r3, [r5, r12] */
/* @0x2a1cb8 ldr r6, [pc, r6] */
/* @0x2a1cbc ldr r5, [r6] */
/* @0x2a1cc0 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x2a1cc4 ldr r3, [pc, #0x20] */
/* @0x2a1cc8 ldr r2, [r6] */
/* @0x2a1ccc ldr r3, [pc, r3] */
/* @0x2a1cd0 add r2, r2, #1 */
/* @0x2a1cd4 str r2, [r6] */
/* @0x2a1cd8 str r0, [r3, r5, lsl #2] */
/* @0x2a1cdc mov r0, r4 */
/* @0x2a1ce0 pop {r4, r5, r6, pc} */
/* @0x2a1ce4 andseq pc, r4, r12, lsl #28 */
/* @0x2a1ce8 andseq sp, r4, r8, ror #11 */
/* @0x2a1cec ldrsbeq sp, [r4], -r8 */

/* ── FUNC 0x2a1cf0 · ProcessCommandLine(char*) · size=2828 · insn=707 */
/* @0x2a1cf0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2a1cf4 sub sp, sp, #60 */
/* @0x2a1cf8 ldr r5, [pc, #0x99c] */
/* @0x2a1cfc mov r3, #0 */
/* @0x2a1d00 ldr r12, [pc, #0x998] */
/* @0x2a1d04 mov r2, #1 */
/* @0x2a1d08 add r5, pc, r5 */
/* @0x2a1d0c ldr r1, [pc, #0x990] */
/* @0x2a1d10 ldr r8, [pc, #0x990] */
/* @0x2a1d14 subs r7, r0, #0 */
/* @0x2a1d18 ldr r12, [r5, r12] */
/* @0x2a1d1c ldr r6, [pc, #0x988] */
/* @0x2a1d20 ldr r4, [pc, #0x988] */
/* @0x2a1d24 str r12, [sp, #0x10] */
/* @0x2a1d28 strb r3, [r12] */
/* @0x2a1d2c ldr r1, [r5, r1] */
/* @0x2a1d30 ldr r12, [pc, #0x97c] */
/* @0x2a1d34 ldr r0, [pc, #0x97c] */
/* @0x2a1d38 str r1, [sp, #0x8] */
/* @0x2a1d3c strb r3, [r1] */
/* @0x2a1d40 ldr r1, [r5, r8] */
/* @0x2a1d44 str r1, [sp, #0x20] */
/* @0x2a1d48 ldr r8, [sp, #0x20] */
/* @0x2a1d4c ldr r1, [pc, #0x968] */
/* @0x2a1d50 strb r3, [r8] */
/* @0x2a1d54 ldr r6, [r5, r6] */
/* @0x2a1d58 str r6, [sp, #0x24] */
/* @0x2a1d5c strb r3, [r6] */
/* @0x2a1d60 ldr r4, [r5, r4] */
/* @0x2a1d64 str r4, [sp, #0x14] */
/* @0x2a1d68 strb r2, [r4] */
/* @0x2a1d6c ldr r2, [r5, r12] */
/* @0x2a1d70 strb r3, [r2] */
/* @0x2a1d74 str r2, [sp, #0x18] */
/* @0x2a1d78 ldr r2, [r5, r0] */
/* @0x2a1d7c strb r3, [r2] */
/* @0x2a1d80 str r2, [sp, #0x1c] */
/* @0x2a1d84 ldr r2, [r5, r1] */
/* @0x2a1d88 str r2, [sp, #0xc] */
/* @0x2a1d8c str r3, [r2] */
/* @0x2a1d90 beq 0x2a1e54 <_Z18ProcessCommandLinePc+0x164> */
/* @0x2a1d94 ldr r2, [pc, #0x924] */
/* @0x2a1d98 mov r4, r3 */
/* @0x2a1d9c ldr r9, [pc, #0x920] */
/* @0x2a1da0 ldr r8, [pc, #0x920] */
/* @0x2a1da4 ldr r6, [pc, #0x920] */
/* @0x2a1da8 add r9, pc, r9 */
/* @0x2a1dac ldr r10, [pc, #0x91c] */
/* @0x2a1db0 add r8, pc, r8 */
/* @0x2a1db4 ldr r11, [pc, #0x918] */
/* @0x2a1db8 add r6, pc, r6 */
/* @0x2a1dbc ldr r2, [r5, r2] */
/* @0x2a1dc0 add r10, pc, r10 */
/* @0x2a1dc4 str r6, [sp, #0x28] */
/* @0x2a1dc8 add r11, pc, r11 */
/* @0x2a1dcc ldr r6, [pc, #0x904] */
/* @0x2a1dd0 str r3, [r2] */
/* @0x2a1dd4 add r6, pc, r6 */
/* @0x2a1dd8 str r6, [sp, #0x2c] */
/* @0x2a1ddc ldrb r3, [r7, r4] */
/* @0x2a1de0 cmp r3, #0 */
/* @0x2a1de4 beq 0x2a1e54 <_Z18ProcessCommandLinePc+0x164> */
/* @0x2a1de8 mov r0, r4 */
/* @0x2a1dec mov r1, r7 */
/* @0x2a1df0 bl 0x2a1c0c <_Z10GetNextCmdiPc> */
/* @0x2a1df4 ldr r3, [pc, #0x8e0] */
/* @0x2a1df8 ldr r1, [pc, #0x8e0] */
/* @0x2a1dfc ldr r6, [r5, r3] */
/* @0x2a1e00 add r1, pc, r1 */
/* @0x2a1e04 mov r4, r0 */
/* @0x2a1e08 mov r0, r6 */
/* @0x2a1e0c bl 0xb6574 <strcmp@plt> */
/* @0x2a1e10 cmp r0, #0 */
/* @0x2a1e14 bne 0x2a1e5c <_Z18ProcessCommandLinePc+0x16c> */
/* @0x2a1e18 ldr r3, [pc, #0x8c4] */
/* @0x2a1e1c ldr r3, [r5, r3] */
/* @0x2a1e20 ldr r3, [r3] */
/* @0x2a1e24 cmp r3, #0 */
/* @0x2a1e28 bne 0x2a1ddc <_Z18ProcessCommandLinePc+0xec> */
/* @0x2a1e2c ldr r6, [sp, #0x10] */
/* @0x2a1e30 mov r3, #1 */
/* @0x2a1e34 strb r3, [r6] */
/* @0x2a1e38 mov r3, #2 */
/* @0x2a1e3c ldr r6, [sp, #0xc] */
/* @0x2a1e40 str r3, [r6] */
/* @0x2a1e44 bl 0x237b88 <_ZN13CPhysicsWorld12SetDebugModeEv> */
/* @0x2a1e48 ldrb r3, [r7, r4] */
/* @0x2a1e4c cmp r3, #0 */
/* @0x2a1e50 bne 0x2a1de8 <_Z18ProcessCommandLinePc+0xf8> */
/* @0x2a1e54 add sp, sp, #60 */
/* @0x2a1e58 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2a1e5c ldr r1, [pc, #0x884] */
/* @0x2a1e60 mov r0, r6 */
/* @0x2a1e64 add r1, pc, r1 */
/* @0x2a1e68 bl 0xb6574 <strcmp@plt> */
/* @0x2a1e6c cmp r0, #0 */
/* @0x2a1e70 bne 0x2a1e88 <_Z18ProcessCommandLinePc+0x198> */
/* @0x2a1e74 ldr r3, [pc, #0x870] */
/* @0x2a1e78 mov r2, #1 */
/* @0x2a1e7c ldr r3, [r5, r3] */
/* @0x2a1e80 strb r2, [r3] */
/* @0x2a1e84 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec> */
/* @0x2a1e88 ldr r1, [pc, #0x860] */
/* @0x2a1e8c mov r0, r6 */
/* @0x2a1e90 add r1, pc, r1 */
/* @0x2a1e94 bl 0xb6574 <strcmp@plt> */
/* @0x2a1e98 cmp r0, #0 */
/* @0x2a1e9c bne 0x2a1eb4 <_Z18ProcessCommandLinePc+0x1c4> */
/* @0x2a1ea0 ldr r3, [pc, #0x84c] */
/* @0x2a1ea4 mov r2, #1 */
/* @0x2a1ea8 ldr r3, [r5, r3] */
/* @0x2a1eac strb r2, [r3] */
/* @0x2a1eb0 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec> */
/* @0x2a1eb4 ldr r1, [pc, #0x83c] */
/* @0x2a1eb8 mov r0, r6 */
/* @0x2a1ebc add r1, pc, r1 */
/* @0x2a1ec0 bl 0xb6574 <strcmp@plt> */
/* @0x2a1ec4 cmp r0, #0 */
/* @0x2a1ec8 ldreq r6, [sp, #0x8] */
/* @0x2a1ecc moveq r3, #1 */
/* @0x2a1ed0 strbeq r3, [r6] */
/* @0x2a1ed4 beq 0x2a1ddc <_Z18ProcessCommandLinePc+0xec> */
/* @0x2a1ed8 ldr r1, [pc, #0x81c] */
/* @0x2a1edc mov r0, r6 */
/* @0x2a1ee0 add r1, pc, r1 */
/* @0x2a1ee4 bl 0xb6574 <strcmp@plt> */
/* @0x2a1ee8 cmp r0, #0 */
/* @0x2a1eec ldreq r3, [pc, #0x80c] */
/* @0x2a1ef0 ldreq r3, [r5, r3] */
/* @0x2a1ef4 strbeq r0, [r3] */
/* @0x2a1ef8 beq 0x2a1ddc <_Z18ProcessCommandLinePc+0xec> */
/* @0x2a1efc ldr r1, [pc, #0x800] */
/* @0x2a1f00 mov r0, r6 */
/* @0x2a1f04 add r1, pc, r1 */
/* @0x2a1f08 bl 0xb6574 <strcmp@plt> */
/* @0x2a1f0c cmp r0, #0 */
/* @0x2a1f10 beq 0x2a1f3c <_Z18ProcessCommandLinePc+0x24c> */
/* @0x2a1f14 ldr r1, [pc, #0x7ec] */
/* @0x2a1f18 mov r0, r6 */
/* @0x2a1f1c add r1, pc, r1 */
/* @0x2a1f20 bl 0xb6574 <strcmp@plt> */
/* @0x2a1f24 cmp r0, #0 */
/* @0x2a1f28 bne 0x2a1f48 <_Z18ProcessCommandLinePc+0x258> */
/* @0x2a1f2c ldr r6, [sp, #0x18] */
/* @0x2a1f30 mov r3, #1 */
/* @0x2a1f34 strb r3, [r6] */
/* @0x2a1f38 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec> */
/* @0x2a1f3c ldr r6, [sp, #0x14] */
/* @0x2a1f40 strb r0, [r6] */
/* @0x2a1f44 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec> */
/* @0x2a1f48 ldr r1, [pc, #0x7bc] */
/* @0x2a1f4c mov r0, r6 */
/* @0x2a1f50 add r1, pc, r1 */
/* @0x2a1f54 bl 0xb6574 <strcmp@plt> */
/* @0x2a1f58 cmp r0, #0 */
/* @0x2a1f5c beq 0x2a1ff4 <_Z18ProcessCommandLinePc+0x304> */
/* @0x2a1f60 ldr r1, [pc, #0x7a8] */
/* @0x2a1f64 mov r0, r6 */
/* @0x2a1f68 add r1, pc, r1 */
/* @0x2a1f6c bl 0xb6574 <strcmp@plt> */
/* @0x2a1f70 cmp r0, #0 */
/* @0x2a1f74 beq 0x2a2004 <_Z18ProcessCommandLinePc+0x314> */
/* @0x2a1f78 ldr r1, [pc, #0x794] */
/* @0x2a1f7c mov r0, r6 */
/* @0x2a1f80 add r1, pc, r1 */
/* @0x2a1f84 bl 0xb6574 <strcmp@plt> */
/* @0x2a1f88 cmp r0, #0 */
/* @0x2a1f8c str r0, [sp, #0x34] */
/* @0x2a1f90 beq 0x2a2070 <_Z18ProcessCommandLinePc+0x380> */
/* @0x2a1f94 ldr r1, [pc, #0x77c] */
/* @0x2a1f98 mov r0, r6 */
/* @0x2a1f9c add r1, pc, r1 */
/* @0x2a1fa0 bl 0xb6574 <strcmp@plt> */
/* @0x2a1fa4 cmp r0, #0 */
/* @0x2a1fa8 str r0, [sp, #0x34] */
/* @0x2a1fac beq 0x2a20ec <_Z18ProcessCommandLinePc+0x3fc> */
/* @0x2a1fb0 ldr r1, [pc, #0x764] */
/* @0x2a1fb4 mov r0, r6 */
/* @0x2a1fb8 add r1, pc, r1 */
/* @0x2a1fbc bl 0xb6574 <strcmp@plt> */
/* @0x2a1fc0 cmp r0, #0 */
/* @0x2a1fc4 beq 0x2a213c <_Z18ProcessCommandLinePc+0x44c> */
/* @0x2a1fc8 ldr r1, [pc, #0x750] */
/* @0x2a1fcc mov r0, r6 */
/* @0x2a1fd0 add r1, pc, r1 */
/* @0x2a1fd4 bl 0xb6574 <strcmp@plt> */
/* @0x2a1fd8 cmp r0, #0 */
/* @0x2a1fdc bne 0x2a20c0 <_Z18ProcessCommandLinePc+0x3d0> */
/* @0x2a1fe0 ldr r3, [pc, #0x73c] */
/* @0x2a1fe4 mov r2, #1 */
/* @0x2a1fe8 ldr r3, [r5, r3] */
/* @0x2a1fec strb r2, [r3] */
/* @0x2a1ff0 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec> */
/* @0x2a1ff4 ldr r6, [sp, #0x1c] */
/* @0x2a1ff8 mov r3, #1 */
/* @0x2a1ffc strb r3, [r6] */
/* @0x2a2000 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec> */
/* @0x2a2004 mov r0, r4 */
/* @0x2a2008 mov r1, r7 */
/* @0x2a200c bl 0x2a1c0c <_Z10GetNextCmdiPc> */
/* @0x2a2010 ldr r3, [pc, #0x6cc] */
/* @0x2a2014 ldr r3, [r5, r3] */
/* @0x2a2018 str r3, [sp, #0x30] */
/* @0x2a201c mov r4, r0 */
/* @0x2a2020 ldr r0, [r3] */
/* @0x2a2024 cmp r0, #0 */
/* @0x2a2028 beq 0x2a203c <_Z18ProcessCommandLinePc+0x34c> */
/* @0x2a202c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2a2030 ldr r0, [sp, #0x30] */
/* @0x2a2034 mov r3, #0 */
/* @0x2a2038 str r3, [r0] */
/* @0x2a203c mov r0, r6 */
/* @0x2a2040 bl 0xb6538 <strlen@plt> */
/* @0x2a2044 ldr r1, [pc, #0x6dc] */
/* @0x2a2048 movw r2, #0x26d */
/* @0x2a204c add r1, pc, r1 */
/* @0x2a2050 mov r3, #1 */
/* @0x2a2054 add r0, r0, r3 */
/* @0x2a2058 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x2a205c mov r1, r6 */
/* @0x2a2060 ldr r6, [sp, #0x30] */
/* @0x2a2064 str r0, [r6] */
/* @0x2a2068 bl 0xb65a4 <strcpy@plt> */
/* @0x2a206c b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec> */
/* @0x2a2070 mov r0, r4 */
/* @0x2a2074 mov r1, r7 */
/* @0x2a2078 bl 0x2a1c0c <_Z10GetNextCmdiPc> */
/* @0x2a207c ldr r3, [pc, #0x6a8] */
/* @0x2a2080 ldr r3, [r5, r3] */
/* @0x2a2084 str r3, [sp, #0x30] */
/* @0x2a2088 mov r4, r0 */
/* @0x2a208c ldr r0, [r3] */
/* @0x2a2090 cmp r0, #0 */
/* @0x2a2094 beq 0x2a20a8 <_Z18ProcessCommandLinePc+0x3b8> */
/* @0x2a2098 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2a209c ldr r2, [sp, #0x34] */
/* @0x2a20a0 ldr r3, [sp, #0x30] */
/* @0x2a20a4 str r2, [r3] */
/* @0x2a20a8 mov r0, r6 */
/* @0x2a20ac bl 0xb6538 <strlen@plt> */
/* @0x2a20b0 ldr r1, [pc, #0x678] */
/* @0x2a20b4 movw r2, #0x276 */
/* @0x2a20b8 add r1, pc, r1 */
/* @0x2a20bc b 0x2a2050 <_Z18ProcessCommandLinePc+0x360> */
/* @0x2a20c0 ldr r1, [pc, #0x66c] */
/* @0x2a20c4 mov r0, r6 */
/* @0x2a20c8 add r1, pc, r1 */
/* @0x2a20cc bl 0xb6574 <strcmp@plt> */
/* @0x2a20d0 cmp r0, #0 */
/* @0x2a20d4 bne 0x2a2194 <_Z18ProcessCommandLinePc+0x4a4> */
/* @0x2a20d8 ldr r3, [pc, #0x658] */
/* @0x2a20dc mov r2, #1 */
/* @0x2a20e0 ldr r3, [r5, r3] */
/* @0x2a20e4 strb r2, [r3] */
/* @0x2a20e8 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec> */
/* @0x2a20ec mov r0, r4 */
/* @0x2a20f0 mov r1, r7 */
/* @0x2a20f4 bl 0x2a1c0c <_Z10GetNextCmdiPc> */
/* @0x2a20f8 ldr r3, [pc, #0x63c] */
/* @0x2a20fc ldr r3, [r5, r3] */
/* @0x2a2100 str r3, [sp, #0x30] */
/* @0x2a2104 mov r4, r0 */
/* @0x2a2108 ldr r0, [r3] */
/* @0x2a210c cmp r0, #0 */
/* @0x2a2110 beq 0x2a2124 <_Z18ProcessCommandLinePc+0x434> */
/* @0x2a2114 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2a2118 ldr r2, [sp, #0x34] */
/* @0x2a211c ldr r3, [sp, #0x30] */
/* @0x2a2120 str r2, [r3] */
/* @0x2a2124 mov r0, r6 */
/* @0x2a2128 bl 0xb6538 <strlen@plt> */
/* @0x2a212c ldr r1, [pc, #0x60c] */
/* @0x2a2130 movw r2, #0x27f */
/* @0x2a2134 add r1, pc, r1 */
/* @0x2a2138 b 0x2a2050 <_Z18ProcessCommandLinePc+0x360> */
/* @0x2a213c mov r0, r4 */
/* @0x2a2140 ldr r4, [sp, #0x20] */
/* @0x2a2144 mov r1, r7 */
/* @0x2a2148 mov r3, #1 */
/* @0x2a214c strb r3, [r4] */
/* @0x2a2150 str r3, [sp, #0x4] */
/* @0x2a2154 bl 0x2a1c0c <_Z10GetNextCmdiPc> */
/* @0x2a2158 mov r4, r0 */
/* @0x2a215c mov r0, r6 */
/* @0x2a2160 bl 0xb6538 <strlen@plt> */
/* @0x2a2164 ldr r1, [pc, #0x5d8] */
/* @0x2a2168 ldr r3, [sp, #0x4] */
/* @0x2a216c movw r2, #0x285 */
/* @0x2a2170 add r1, pc, r1 */
/* @0x2a2174 add r0, r0, #1 */
/* @0x2a2178 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x2a217c ldr r3, [pc, #0x5c4] */
/* @0x2a2180 mov r1, r6 */
/* @0x2a2184 ldr r3, [r5, r3] */
/* @0x2a2188 str r0, [r3] */
/* @0x2a218c bl 0xb65a4 <strcpy@plt> */
/* @0x2a2190 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec> */
/* @0x2a2194 ldr r1, [pc, #0x5b0] */
/* @0x2a2198 mov r0, r6 */
/* @0x2a219c add r1, pc, r1 */
/* @0x2a21a0 bl 0xb6574 <strcmp@plt> */
/* @0x2a21a4 cmp r0, #0 */
/* @0x2a21a8 bne 0x2a21cc <_Z18ProcessCommandLinePc+0x4dc> */
/* @0x2a21ac ldr r1, [pc, #0x59c] */
/* @0x2a21b0 mov r3, #1 */
/* @0x2a21b4 ldr r2, [pc, #0x598] */
/* @0x2a21b8 ldr r1, [r5, r1] */
/* @0x2a21bc strb r3, [r1] */
/* @0x2a21c0 ldr r2, [r5, r2] */
/* @0x2a21c4 strb r3, [r2] */
/* @0x2a21c8 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec> */
/* @0x2a21cc ldr r1, [pc, #0x584] */
/* @0x2a21d0 mov r0, r6 */
/* @0x2a21d4 add r1, pc, r1 */
/* @0x2a21d8 bl 0xb6574 <strcmp@plt> */
/* @0x2a21dc cmp r0, #0 */
/* @0x2a21e0 bne 0x2a21f8 <_Z18ProcessCommandLinePc+0x508> */
/* @0x2a21e4 ldr r6, [sp, #0xc] */
/* @0x2a21e8 ldr r3, [r6] */
/* @0x2a21ec orr r3, r3, #16 */
/* @0x2a21f0 str r3, [r6] */
/* @0x2a21f4 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec> */
/* @0x2a21f8 ldr r1, [pc, #0x55c] */
/* @0x2a21fc mov r0, r6 */
/* @0x2a2200 add r1, pc, r1 */
/* @0x2a2204 bl 0xb6574 <strcmp@plt> */
/* @0x2a2208 cmp r0, #0 */
/* @0x2a220c bne 0x2a2224 <_Z18ProcessCommandLinePc+0x534> */
/* @0x2a2210 ldr r3, [pc, #0x548] */
/* @0x2a2214 mov r2, #1 */
/* @0x2a2218 ldr r3, [r5, r3] */
/* @0x2a221c strb r2, [r3] */
/* @0x2a2220 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec> */
/* @0x2a2224 mov r0, r6 */
/* @0x2a2228 mov r1, r9 */
/* @0x2a222c bl 0xb6574 <strcmp@plt> */
/* @0x2a2230 cmp r0, #0 */
/* @0x2a2234 bne 0x2a224c <_Z18ProcessCommandLinePc+0x55c> */
/* @0x2a2238 ldr r3, [pc, #0x524] */
/* @0x2a223c mov r2, #1 */
/* @0x2a2240 ldr r3, [r5, r3] */
/* @0x2a2244 strb r2, [r3] */
/* @0x2a2248 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec> */
/* @0x2a224c mov r0, r6 */
/* @0x2a2250 mov r1, r8 */
/* @0x2a2254 bl 0xb6574 <strcmp@plt> */
/* @0x2a2258 cmp r0, #0 */
/* @0x2a225c beq 0x2a22e0 <_Z18ProcessCommandLinePc+0x5f0> */
/* @0x2a2260 mov r0, r6 */
/* @0x2a2264 ldr r1, [sp, #0x28] */
/* @0x2a2268 bl 0xb6574 <strcmp@plt> */
/* @0x2a226c cmp r0, #0 */
/* @0x2a2270 beq 0x2a25c4 <_Z18ProcessCommandLinePc+0x8d4> */
/* @0x2a2274 mov r0, r6 */
/* @0x2a2278 ldr r1, [sp, #0x2c] */
/* @0x2a227c bl 0xb6574 <strcmp@plt> */
/* @0x2a2280 cmp r0, #0 */
/* @0x2a2284 beq 0x2a2548 <_Z18ProcessCommandLinePc+0x858> */
/* @0x2a2288 mov r0, r6 */
/* @0x2a228c mov r1, r10 */
/* @0x2a2290 bl 0xb6574 <strcmp@plt> */
/* @0x2a2294 cmp r0, #0 */
/* @0x2a2298 bne 0x2a231c <_Z18ProcessCommandLinePc+0x62c> */
/* @0x2a229c ldr r2, [pc, #0x4c4] */
/* @0x2a22a0 mov r3, #1 */
/* @0x2a22a4 ldr r1, [pc, #0x4c0] */
/* @0x2a22a8 ldr r0, [r5, r2] */
/* @0x2a22ac ldr r2, [pc, #0x4bc] */
/* @0x2a22b0 strb r3, [r0] */
/* @0x2a22b4 ldr r0, [r5, r1] */
/* @0x2a22b8 ldr r1, [pc, #0x4b4] */
/* @0x2a22bc strb r3, [r0] */
/* @0x2a22c0 ldr r0, [r5, r2] */
/* @0x2a22c4 ldr r2, [pc, #0x4ac] */
/* @0x2a22c8 strb r3, [r0] */
/* @0x2a22cc ldr r1, [r5, r1] */
/* @0x2a22d0 strb r3, [r1] */
/* @0x2a22d4 ldr r2, [r5, r2] */
/* @0x2a22d8 strb r3, [r2] */
/* @0x2a22dc b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec> */
/* @0x2a22e0 mov r0, r4 */
/* @0x2a22e4 ldr r4, [sp, #0x24] */
/* @0x2a22e8 mov r1, r7 */
/* @0x2a22ec mov r3, #1 */
/* @0x2a22f0 strb r3, [r4] */
/* @0x2a22f4 str r3, [sp, #0x4] */
/* @0x2a22f8 bl 0x2a1c0c <_Z10GetNextCmdiPc> */
/* @0x2a22fc mov r4, r0 */
/* @0x2a2300 mov r0, r6 */
/* @0x2a2304 bl 0xb6538 <strlen@plt> */
/* @0x2a2308 ldr r1, [pc, #0x46c] */
/* @0x2a230c ldr r3, [sp, #0x4] */
/* @0x2a2310 movw r2, #0x29f */
/* @0x2a2314 add r1, pc, r1 */
/* @0x2a2318 b 0x2a2174 <_Z18ProcessCommandLinePc+0x484> */
/* @0x2a231c mov r0, r6 */
/* @0x2a2320 mov r1, r11 */
/* @0x2a2324 bl 0xb6574 <strcmp@plt> */
/* @0x2a2328 cmp r0, #0 */
/* @0x2a232c beq 0x2a2440 <_Z18ProcessCommandLinePc+0x750> */
/* @0x2a2330 ldr r1, [pc, #0x448] */
/* @0x2a2334 mov r0, r6 */
/* @0x2a2338 mov r2, #9 */
/* @0x2a233c add r1, pc, r1 */
/* @0x2a2340 bl 0xb65e0 <strncmp@plt> */
/* @0x2a2344 subs r3, r0, #0 */
/* @0x2a2348 bne 0x2a23f0 <_Z18ProcessCommandLinePc+0x700> */
/* @0x2a234c ldr r2, [pc, #0x430] */
/* @0x2a2350 ldr r2, [r5, r2] */
/* @0x2a2354 ldr r0, [r2] */
/* @0x2a2358 str r2, [sp, #0x30] */
/* @0x2a235c cmp r0, #0 */
/* @0x2a2360 beq 0x2a2378 <_Z18ProcessCommandLinePc+0x688> */
/* @0x2a2364 str r3, [sp, #0x4] */
/* @0x2a2368 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2a236c ldr r3, [sp, #0x4] */
/* @0x2a2370 ldr r0, [sp, #0x30] */
/* @0x2a2374 str r3, [r0] */
/* @0x2a2378 ldr r1, [pc, #0x408] */
/* @0x2a237c mov r2, #11 */
/* @0x2a2380 mov r0, r6 */
/* @0x2a2384 add r1, pc, r1 */
/* @0x2a2388 bl 0xb65e0 <strncmp@plt> */
/* @0x2a238c cmp r0, #0 */
/* @0x2a2390 moveq r0, #11 */
/* @0x2a2394 movne r0, #9 */
/* @0x2a2398 str r0, [sp, #0x34] */
/* @0x2a239c mov r0, r6 */
/* @0x2a23a0 bl 0xb6538 <strlen@plt> */
/* @0x2a23a4 sub r0, r0, #1 */
/* @0x2a23a8 ldrb r3, [r6, r0] */
/* @0x2a23ac cmp r3, #47 */
/* @0x2a23b0 moveq r3, #0 */
/* @0x2a23b4 strbeq r3, [r6, r0] */
/* @0x2a23b8 mov r0, r6 */
/* @0x2a23bc bl 0xb6538 <strlen@plt> */
/* @0x2a23c0 ldr r1, [pc, #0x3c4] */
/* @0x2a23c4 mov r3, #1 */
/* @0x2a23c8 mov r2, #720 */
/* @0x2a23cc add r1, pc, r1 */
/* @0x2a23d0 add r0, r0, r3 */
/* @0x2a23d4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x2a23d8 ldr r2, [sp, #0x34] */
/* @0x2a23dc add r1, r6, r2 */
/* @0x2a23e0 ldr r6, [sp, #0x30] */
/* @0x2a23e4 str r0, [r6] */
/* @0x2a23e8 bl 0xb65a4 <strcpy@plt> */
/* @0x2a23ec b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec> */
/* @0x2a23f0 ldr r1, [pc, #0x398] */
/* @0x2a23f4 mov r0, r6 */
/* @0x2a23f8 add r1, pc, r1 */
/* @0x2a23fc bl 0xb6574 <strcmp@plt> */
/* @0x2a2400 cmp r0, #0 */
/* @0x2a2404 beq 0x2a24e4 <_Z18ProcessCommandLinePc+0x7f4> */
/* @0x2a2408 ldr r1, [pc, #0x384] */
/* @0x2a240c mov r0, r6 */
/* @0x2a2410 add r1, pc, r1 */
/* @0x2a2414 bl 0xb6574 <strcmp@plt> */
/* @0x2a2418 cmp r0, #0 */
/* @0x2a241c bne 0x2a24ac <_Z18ProcessCommandLinePc+0x7bc> */
/* @0x2a2420 ldr r2, [pc, #0x370] */
/* @0x2a2424 mov r1, #1 */
/* @0x2a2428 ldr r3, [pc, #0x36c] */
/* @0x2a242c ldr r2, [r5, r2] */
/* @0x2a2430 strb r1, [r2] */
/* @0x2a2434 ldr r3, [r5, r3] */
/* @0x2a2438 strb r0, [r3] */
/* @0x2a243c b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec> */
/* @0x2a2440 mov r1, r7 */
/* @0x2a2444 mov r0, r4 */
/* @0x2a2448 bl 0x2a1c0c <_Z10GetNextCmdiPc> */
/* @0x2a244c mov r4, r0 */
/* @0x2a2450 mov r0, r6 */
/* @0x2a2454 bl 0xb6538 <strlen@plt> */
/* @0x2a2458 ldr r1, [pc, #0x340] */
/* @0x2a245c movw r2, #0x2bb */
/* @0x2a2460 mov r3, #1 */
/* @0x2a2464 add r1, pc, r1 */
/* @0x2a2468 add r0, r0, r3 */
/* @0x2a246c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x2a2470 ldr r3, [pc, #0x32c] */
/* @0x2a2474 mov r1, r6 */
/* @0x2a2478 ldr r3, [r5, r3] */
/* @0x2a247c str r0, [r3] */
/* @0x2a2480 bl 0xb65a4 <strcpy@plt> */
/* @0x2a2484 mov r0, r4 */
/* @0x2a2488 mov r1, r7 */
/* @0x2a248c bl 0x2a1c0c <_Z10GetNextCmdiPc> */
/* @0x2a2490 mov r4, r0 */
/* @0x2a2494 mov r0, r6 */
/* @0x2a2498 bl 0xb66b8 <atoi@plt> */
/* @0x2a249c ldr r3, [pc, #0x304] */
/* @0x2a24a0 ldr r3, [r5, r3] */
/* @0x2a24a4 str r0, [r3] */
/* @0x2a24a8 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec> */
/* @0x2a24ac ldr r1, [pc, #0x2f8] */
/* @0x2a24b0 mov r0, r6 */
/* @0x2a24b4 add r1, pc, r1 */
/* @0x2a24b8 bl 0xb6574 <strcmp@plt> */
/* @0x2a24bc cmp r0, #0 */
/* @0x2a24c0 bne 0x2a251c <_Z18ProcessCommandLinePc+0x82c> */
/* @0x2a24c4 ldr r1, [pc, #0x2cc] */
/* @0x2a24c8 mov r3, #1 */
/* @0x2a24cc ldr r2, [pc, #0x2dc] */
/* @0x2a24d0 ldr r1, [r5, r1] */
/* @0x2a24d4 strb r3, [r1] */
/* @0x2a24d8 ldr r2, [r5, r2] */
/* @0x2a24dc strb r3, [r2] */
/* @0x2a24e0 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec> */
/* @0x2a24e4 mov r1, r7 */
/* @0x2a24e8 mov r0, r4 */
/* @0x2a24ec bl 0x2a1c0c <_Z10GetNextCmdiPc> */
/* @0x2a24f0 mov r4, r0 */
/* @0x2a24f4 mov r0, r6 */
/* @0x2a24f8 bl 0xb66b8 <atoi@plt> */
/* @0x2a24fc ldr r1, [pc, #0x2b0] */
/* @0x2a2500 ldr r2, [pc, #0x2b0] */
/* @0x2a2504 mov r3, #1 */
/* @0x2a2508 ldr r1, [r5, r1] */
/* @0x2a250c str r0, [r1] */
/* @0x2a2510 ldr r2, [r5, r2] */
/* @0x2a2514 strb r3, [r2] */
/* @0x2a2518 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec> */
/* @0x2a251c ldr r1, [pc, #0x298] */
/* @0x2a2520 mov r0, r6 */
/* @0x2a2524 add r1, pc, r1 */
/* @0x2a2528 bl 0xb6574 <strcmp@plt> */
/* @0x2a252c cmp r0, #0 */
/* @0x2a2530 bne 0x2a2620 <_Z18ProcessCommandLinePc+0x930> */
/* @0x2a2534 ldr r3, [pc, #0x284] */
/* @0x2a2538 mov r2, #1 */
/* @0x2a253c ldr r3, [r5, r3] */
/* @0x2a2540 strb r2, [r3] */
/* @0x2a2544 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec> */
/* @0x2a2548 ldr lr, [pc, #0x274] */
/* @0x2a254c mov r1, r7 */
/* @0x2a2550 ldr r12, [pc, #0x270] */
/* @0x2a2554 mov r0, r4 */
/* @0x2a2558 ldr r2, [pc, #0x26c] */
/* @0x2a255c mov r3, #1 */
/* @0x2a2560 ldr lr, [r5, lr] */
/* @0x2a2564 ldr r12, [r5, r12] */
/* @0x2a2568 ldr lr, [lr] */
/* @0x2a256c ldr r12, [r12] */
/* @0x2a2570 ldr lr, [lr] */
/* @0x2a2574 str lr, [r12] */
/* @0x2a2578 ldr r2, [r5, r2] */
/* @0x2a257c strb r3, [r2] */
/* @0x2a2580 str r3, [sp, #0x4] */
/* @0x2a2584 bl 0x2a1c0c <_Z10GetNextCmdiPc> */
/* @0x2a2588 mov r4, r0 */
/* @0x2a258c mov r0, r6 */
/* @0x2a2590 bl 0xb6538 <strlen@plt> */
/* @0x2a2594 ldr r1, [pc, #0x234] */
/* @0x2a2598 ldr r3, [sp, #0x4] */
/* @0x2a259c mov r2, #684 */
/* @0x2a25a0 add r1, pc, r1 */
/* @0x2a25a4 add r0, r0, #1 */
/* @0x2a25a8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x2a25ac ldr r3, [pc, #0x220] */
/* @0x2a25b0 mov r1, r6 */
/* @0x2a25b4 ldr r3, [r5, r3] */
/* @0x2a25b8 str r0, [r3] */
/* @0x2a25bc bl 0xb65a4 <strcpy@plt> */
/* @0x2a25c0 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec> */
/* @0x2a25c4 ldr r2, [pc, #0x20c] */
/* @0x2a25c8 mov r1, r7 */
/* @0x2a25cc mov r0, r4 */
/* @0x2a25d0 mov r3, #1 */
/* @0x2a25d4 ldr r2, [r5, r2] */
/* @0x2a25d8 strb r3, [r2] */
/* @0x2a25dc str r3, [sp, #0x4] */
/* @0x2a25e0 bl 0x2a1c0c <_Z10GetNextCmdiPc> */
/* @0x2a25e4 mov r4, r0 */
/* @0x2a25e8 mov r0, r6 */
/* @0x2a25ec bl 0xb6538 <strlen@plt> */
/* @0x2a25f0 ldr r1, [pc, #0x1e4] */
/* @0x2a25f4 ldr r3, [sp, #0x4] */
/* @0x2a25f8 movw r2, #0x2a5 */
/* @0x2a25fc add r1, pc, r1 */
/* @0x2a2600 add r0, r0, #1 */
/* @0x2a2604 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x2a2608 ldr r3, [pc, #0x1d0] */
/* @0x2a260c mov r1, r6 */
/* @0x2a2610 ldr r3, [r5, r3] */
/* @0x2a2614 str r0, [r3] */
/* @0x2a2618 bl 0xb65a4 <strcpy@plt> */
/* @0x2a261c b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec> */
/* @0x2a2620 ldr r1, [pc, #0x1bc] */
/* @0x2a2624 mov r0, r6 */
/* @0x2a2628 add r1, pc, r1 */
/* @0x2a262c bl 0xb6574 <strcmp@plt> */
/* @0x2a2630 cmp r0, #0 */
/* @0x2a2634 bne 0x2a264c <_Z18ProcessCommandLinePc+0x95c> */
/* @0x2a2638 ldr r3, [pc, #0x1a8] */
/* @0x2a263c mov r2, #1 */
/* @0x2a2640 ldr r3, [r5, r3] */
/* @0x2a2644 strb r2, [r3] */
/* @0x2a2648 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec> */
/* @0x2a264c ldr r1, [pc, #0x198] */
/* @0x2a2650 mov r0, r6 */
/* @0x2a2654 add r1, pc, r1 */
/* @0x2a2658 bl 0xb6574 <strcmp@plt> */
/* @0x2a265c cmp r0, #0 */
/* @0x2a2660 bne 0x2a2678 <_Z18ProcessCommandLinePc+0x988> */
/* @0x2a2664 ldr r3, [pc, #0x184] */
/* @0x2a2668 mov r2, #1 */
/* @0x2a266c ldr r3, [r5, r3] */
/* @0x2a2670 strb r2, [r3] */
/* @0x2a2674 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec> */
/* @0x2a2678 ldr r1, [pc, #0x174] */
/* @0x2a267c mov r0, r6 */
/* @0x2a2680 add r1, pc, r1 */
/* @0x2a2684 bl 0xb6574 <strcmp@plt> */
/* @0x2a2688 cmp r0, #0 */
/* @0x2a268c ldreq r3, [pc, #0x164] */
/* @0x2a2690 ldreq r3, [r5, r3] */
/* @0x2a2694 strbeq r0, [r3] */
/* @0x2a2698 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec> */
/* @0x2a269c andseq pc, r4, r8, asr #30 */
/* @0x2a26a0 .word 0xffffef34 */
/* @0x2a26a4 .word 0xfffff75c */
/* @0x2a26a8 .word 0xffffe9c8 */
/* @0x2a26ac .word 0xffffe9cc */
/* @0x2a26b0 .word 0xffffe9f8 */
/* @0x2a26b4 .word 0xffffd3fc */
/* @0x2a26b8 .word 0xffffeb04 */
/* @0x2a26bc .word 0xffffc7dc */
/* @0x2a26c0 .word 0xffffd650 */
/* @0x2a26c4 andeq r8, r11, r0, lsr r5 */
/* @0x2a26c8 andeq r8, r11, r4, lsr r5 */
/* @0x2a26cc andeq r8, r11, r8, lsr r5 */
/* @0x2a26d0 andeq r8, r11, r8, asr #10 */
/* @0x2a26d4 andeq r8, r11, r12, asr #10 */
/* @0x2a26d8 andeq r8, r11, r4, lsr #10 */
/* @0x2a26dc .word 0xfffffddc */
/* @0x2a26e0 andeq r8, r11, r4, lsl #8 */
/* @0x2a26e4 .word 0xffffeed0 */
/* @0x2a26e8 andeq r8, r11, r8, lsr #7 */
/* @0x2a26ec .word 0xffffc100 */
/* @0x2a26f0 andeq r8, r11, r4, lsl #7 */
/* @0x2a26f4 .word 0xffffc7cc */
/* @0x2a26f8 andeq r8, r11, r4, ror #6 */
/* @0x2a26fc andeq r8, r11, r8, asr #6 */
/* @0x2a2700 .word 0xffffc158 */
/* @0x2a2704 andeq r8, r11, r0, lsr r3 */
/* @0x2a2708 andeq r8, r11, r4, lsr #6 */
/* @0x2a270c strdeq r8, r9, [r11], -r12 */
/* @0x2a2710 strdeq r8, r9, [r11], -r0 */
/* @0x2a2714 andeq r8, r11, r8, lsl #6 */
/* @0x2a2718 strdeq r8, r9, [r11], -r4 */
/* @0x2a271c andeq r8, r11, r0, ror #5 */
/* @0x2a2720 ldrdeq r8, r9, [r11], -r0 */
/* @0x2a2724 .word 0xffffc180 */
/* @0x2a2728 andeq r8, r11, r4, lsl r2 */
/* @0x2a272c .word 0xfffffde0 */
/* @0x2a2730 andeq r8, r11, r8, lsr #3 */
/* @0x2a2734 andeq r8, r11, r0, ror #3 */
/* @0x2a2738 .word 0xfffffde4 */
/* @0x2a273c .word 0xfffffde8 */
/* @0x2a2740 andeq r8, r11, r12, lsr #2 */
/* @0x2a2744 strdeq r8, r9, [r11], -r0 */
/* @0x2a2748 .word 0xffffe9d0 */
/* @0x2a274c andeq r8, r11, r8, lsl r1 */
/* @0x2a2750 .word 0xffffe830 */
/* @0x2a2754 .word 0xfffffdec */
/* @0x2a2758 andeq r8, r11, r8, ror #1 */
/* @0x2a275c andeq r8, r11, r8, asr #1 */
/* @0x2a2760 .word 0xfffffd48 */
/* @0x2a2764 .word 0xfffffdf0 */
/* @0x2a2768 .word 0xfffff0cc */
/* @0x2a276c .word 0xffffef38 */
/* @0x2a2770 .word 0xfffffdf4 */
/* @0x2a2774 .word 0xffffc148 */
/* @0x2a2778 .word 0xfffffdcc */
/* @0x2a277c andeq r7, r11, r12, asr #30 */
/* @0x2a2780 andeq r7, r11, r8, ror #31 */
/* @0x2a2784 .word 0xffffdf10 */
/* @0x2a2788 andeq r7, r11, r12, lsr #31 */
/* @0x2a278c muleq r11, r4, lr */
/* @0x2a2790 andeq r7, r11, r4, asr #30 */
/* @0x2a2794 andeq r7, r11, r12, lsr pc */
/* @0x2a2798 .word 0xfffffdf8 */
/* @0x2a279c .word 0xfffffdfc */
/* @0x2a27a0 strdeq r7, r8, [r11], -r12 */
/* @0x2a27a4 .word 0xffffef64 */
/* @0x2a27a8 .word 0xffffef68 */
/* @0x2a27ac andeq r7, r11, r4, lsr #29 */
/* @0x2a27b0 .word 0xfffffe00 */
/* @0x2a27b4 .word 0xffffc964 */
/* @0x2a27b8 .word 0xfffffe04 */
/* @0x2a27bc andeq r7, r11, r12, lsr lr */
/* @0x2a27c0 .word 0xfffffe08 */
/* @0x2a27c4 .word 0xffffbac4 */
/* @0x2a27c8 .word 0xffffdecc */
/* @0x2a27cc .word 0xfffffe0c */
/* @0x2a27d0 andeq r7, r11, r0, asr #25 */
/* @0x2a27d4 .word 0xfffffe10 */
/* @0x2a27d8 .word 0xfffffe14 */
/* @0x2a27dc andeq r7, r11, r4, ror #24 */
/* @0x2a27e0 .word 0xfffffe18 */
/* @0x2a27e4 andeq r7, r11, r12, asr #26 */
/* @0x2a27e8 .word 0xfffffe1c */
/* @0x2a27ec andeq r7, r11, r0, lsr sp */
/* @0x2a27f0 .word 0xfffffe20 */
/* @0x2a27f4 andeq r7, r11, r4, lsl sp */
/* @0x2a27f8 .word 0xfffffe24 */

/* ── FUNC 0x2a27fc · Quit() · size=240 · insn=60 */
/* @0x2a27fc push {r4, lr} */
/* @0x2a2800 bl 0x1dba70 <_Z13CleanGesturesv> */
/* @0x2a2804 bl 0xd675c <_Z14FreeAllObjectsv> */
/* @0x2a2808 ldr r4, [pc, #0xd0] */
/* @0x2a280c bl 0x20b27c <_Z21FreeAllDataStructuresv> */
/* @0x2a2810 bl 0xd66e0 <_Z7ResetGCv> */
/* @0x2a2814 bl 0x15a0c0 <_Z17QuitYoYoFunctionsv> */
/* @0x2a2818 bl 0x2998b8 <_Z23QuitNetworkingFunctionsv> */
/* @0x2a281c bl 0x1dc3bc <_Z14FINALIZE_Scorev> */
/* @0x2a2820 bl 0xf1bb0 <_Z22FINALIZE_Code_Constantv> */
/* @0x2a2824 bl 0xce274 <_Z22FINALIZE_Code_Functionv> */
/* @0x2a2828 bl 0xcf478 <_Z18FINALIZE_Code_Mainv> */
/* @0x2a282c bl 0xd2618 <_Z22FINALIZE_Code_Variablev> */
/* @0x2a2830 bl 0x19c2cc <_Z20FINALIZE_Motion_Gridv> */
/* @0x2a2834 bl 0x1b5e54 <_Z18FINALIZE_Room_Mainv> */
/* @0x2a2838 bl 0x1959f4 <_Z23FINALIZE_Instance_Classv> */
/* @0x2a283c bl 0x1d37cc <_Z17FINALIZE_Run_Mainv> */
/* @0x2a2840 bl 0x19e884 <_Z21FINALIZE_Object_Listsv> */
/* @0x2a2844 bl 0x19f0c0 <_Z20FINALIZE_Object_Mainv> */
/* @0x2a2848 bl 0x19e1c8 <_Z21FINALIZE_Object_Classv> */
/* @0x2a284c bl 0x1a5de8 <_Z22FINALIZE_Particle_Mainv> */
/* @0x2a2850 bl 0x1ee76c <_Z21FINALIZE_Sprite_Classv> */
/* @0x2a2854 bl 0x1ef514 <_Z20FINALIZE_Sprite_Mainv> */
/* @0x2a2858 bl 0x214e14 <_Z21FINALIZE_Support_Filev> */
/* @0x2a285c bl 0x1e3180 <_Z22FINALIZE_VertexFormatsv> */
/* @0x2a2860 bl 0x17dbb8 <_Z25FINALIZE_Graphics_Displayv> */
/* @0x2a2864 bl 0xc42f4 <_Z19FINALIZE_Backgroundv> */
/* @0x2a2868 bl 0x1767cc <_Z25FINALIZE_Graphics_Texturev> */
/* @0x2a286c bl 0x1e0770 <_Z20FINALIZE_Script_Mainv> */
/* @0x2a2870 bl 0x1f4d10 <_Z22FINALIZE_Variable_Mainv> */
/* @0x2a2874 bl 0xface8 <_Z18FINALIZE_Font_Mainv> */
/* @0x2a2878 bl 0x1738fc <_Z22FINALIZE_Graphics_Textv> */
/* @0x2a287c bl 0xf2c9c <_Z21FINALIZE_Event_Actionv> */
/* @0x2a2880 bl 0x13cf04 <_Z22FINALIZE_Function_Filev> */
/* @0x2a2884 bl 0x1f3174 <_Z22FINALIZE_Timeline_Mainv> */
/* @0x2a2888 bl 0x1df90c <_Z20FINALIZE_Runner_Formv> */
/* @0x2a288c bl 0x21f49c <_Z14FINALIZE_Soundv> */
/* @0x2a2890 bl 0xc47f8 <_Z12FINALIZE_Allv> */
/* @0x2a2894 ldr r0, [pc, #0x48] */
/* @0x2a2898 ldr r0, [pc, r0] */
/* @0x2a289c bl 0x2a0364 <_ZN9CProfiler5CleanEv> */
/* @0x2a28a0 bl 0x168c90 <_Z10GR_D3D_Endv> */
/* @0x2a28a4 ldr r4, [pc, r4] */
/* @0x2a28a8 ldr r0, [r4] */
/* @0x2a28ac cmp r0, #0 */
/* @0x2a28b0 beq 0x2a28d0 <_Z4Quitv+0xd4> */
/* @0x2a28b4 bl 0x1a88c0 <_Z15yyDestroyWindowPv> */
/* @0x2a28b8 ldr r3, [pc, #0x28] */
/* @0x2a28bc mov r2, #1 */
/* @0x2a28c0 mov r1, #0 */
/* @0x2a28c4 ldr r3, [pc, r3] */
/* @0x2a28c8 str r1, [r4] */
/* @0x2a28cc strb r2, [r3] */
/* @0x2a28d0 bl 0x28fe68 <_Z25FINALIZE_PlatformSpecificv> */
/* @0x2a28d4 bl 0xd826c <_ZN2VM4QuitEv> */
/* @0x2a28d8 pop {r4, lr} */
/* @0x2a28dc b 0xc7b44 <_Z14FreeAllBuffersv> */
/* @0x2a28e0 andseq sp, r4, r0, asr pc */
/* @0x2a28e4 ldrsbeq r11, [r4], -r4 */
/* @0x2a28e8 ldrheq pc, [r4], -r4 */

/* ── FUNC 0x2a28ec · SetDebugMode(bool) · size=40 · insn=10 */
/* @0x2a28ec ldr r3, [pc, #0x1c] */
/* @0x2a28f0 push {r4, lr} */
/* @0x2a28f4 ldr r3, [pc, r3] */
/* @0x2a28f8 mov r4, r0 */
/* @0x2a28fc strb r0, [r3] */
/* @0x2a2900 bl 0x1004ec <_Z33Setup_SetupDataStructureFunctionsb> */
/* @0x2a2904 mov r0, r4 */
/* @0x2a2908 pop {r4, lr} */
/* @0x2a290c b 0xca678 <_Z27Setup_VertexBufferFunctionsb> */
/* @0x2a2910 mulseq r4, r12, r5 */

/* ── FUNC 0x2a2914 · Init() · size=104 · insn=26 */
/* @0x2a2914 ldr r0, [pc, #0x58] */
/* @0x2a2918 push {r3, lr} */
/* @0x2a291c ldr r0, [pc, r0] */
/* @0x2a2920 bl 0x1a86ac <_ZN7RomDisk4InitEPh> */
/* @0x2a2924 bl 0x2151b8 <Timing_Init> */
/* @0x2a2928 bl 0x27de00 <_Z11InitFastCRCv> */
/* @0x2a292c bl 0x28fe6c <_Z27INITIALIZE_PlatformSpecificv> */
/* @0x2a2930 bl 0x214e10 <_Z23INITIALIZE_Support_Filev> */
/* @0x2a2934 bl 0x16c2c0 <_Z24INITIALIZE_Graphics_Drawv> */
/* @0x2a2938 bl 0xee01c <_Z24INITIALIZE_Code_Constantv> */
/* @0x2a293c bl 0x179d3c <_Z26INITIALIZE_Graphics_Windowv> */
/* @0x2a2940 bl 0x1a5dd8 <_Z24INITIALIZE_Particle_Mainv> */
/* @0x2a2944 bl 0x1cb778 <_Z21INITIALIZE_Run_Globalv> */
/* @0x2a2948 bl 0x21f210 <_Z24INITIALIZE_Sound_DirectXv> */
/* @0x2a294c bl 0x1ffbd0 <_Z27INITIALIZE_Variable_BuiltInv> */
/* @0x2a2950 bl 0x1a8518 <_Z15INITIALIZE_Pathv> */
/* @0x2a2954 bl 0x1dc3b8 <_Z16INITIALIZE_Scorev> */
/* @0x2a2958 bl 0x1d37a4 <_Z15INITIALIZE_Mainv> */
/* @0x2a295c ldr r0, [pc, #0x14] */
/* @0x2a2960 ldr r0, [pc, r0] */
/* @0x2a2964 bl 0x16ddac <_ZN14CCameraManager17SetupGMLFunctionsEv> */
/* @0x2a2968 bl 0x28fe64 <_Z15ProcessMessagesv> */
/* @0x2a296c mov r0, #1 */
/* @0x2a2970 pop {r3, pc} */
/* @0x2a2974 andseq pc, r4, r0, ror #2 */
/* @0x2a2978 andseq r11, r4, r4, lsl r3 */

/* ── FUNC 0x2a297c · InitGMLFunctions() · size=684 · insn=171 */
/* @0x2a297c ldr r3, [pc, #0x250] */
/* @0x2a2980 push {r4, lr} */
/* @0x2a2984 ldr r3, [pc, r3] */
/* @0x2a2988 ldr r1, [pc, #0x248] */
/* @0x2a298c ldr r4, [r3] */
/* @0x2a2990 add r1, pc, r1 */
/* @0x2a2994 ldr r3, [r4] */
/* @0x2a2998 mov r0, r4 */
/* @0x2a299c ldr r3, [r3, #0xc] */
/* @0x2a29a0 blx r3 */
/* @0x2a29a4 bl 0x1dc600 <_Z18HighScore_InitLoadv> */
/* @0x2a29a8 ldr r3, [r4] */
/* @0x2a29ac ldr r1, [pc, #0x228] */
/* @0x2a29b0 mov r0, r4 */
/* @0x2a29b4 add r1, pc, r1 */
/* @0x2a29b8 ldr r3, [r3, #0xc] */
/* @0x2a29bc blx r3 */
/* @0x2a29c0 bl 0x10c7d8 <_Z17InitGameFunctionsv> */
/* @0x2a29c4 ldr r3, [r4] */
/* @0x2a29c8 ldr r1, [pc, #0x210] */
/* @0x2a29cc mov r0, r4 */
/* @0x2a29d0 add r1, pc, r1 */
/* @0x2a29d4 ldr r3, [r3, #0xc] */
/* @0x2a29d8 blx r3 */
/* @0x2a29dc bl 0x111c5c <_Z17InitMathFunctionsv> */
/* @0x2a29e0 ldr r3, [r4] */
/* @0x2a29e4 ldr r1, [pc, #0x1f8] */
/* @0x2a29e8 mov r0, r4 */
/* @0x2a29ec add r1, pc, r1 */
/* @0x2a29f0 ldr r3, [r3, #0xc] */
/* @0x2a29f4 blx r3 */
/* @0x2a29f8 bl 0x12326c <_Z20InitGraphicFunctionsv> */
/* @0x2a29fc ldr r3, [r4] */
/* @0x2a2a00 ldr r1, [pc, #0x1e0] */
/* @0x2a2a04 mov r0, r4 */
/* @0x2a2a08 add r1, pc, r1 */
/* @0x2a2a0c ldr r3, [r3, #0xc] */
/* @0x2a2a10 blx r3 */
/* @0x2a2a14 bl 0x141e60 <_Z19InitActionFunctionsv> */
/* @0x2a2a18 ldr r3, [r4] */
/* @0x2a2a1c ldr r1, [pc, #0x1c8] */
/* @0x2a2a20 mov r0, r4 */
/* @0x2a2a24 add r1, pc, r1 */
/* @0x2a2a28 ldr r3, [r3, #0xc] */
/* @0x2a2a2c blx r3 */
/* @0x2a2a30 bl 0x13c4a0 <_Z17InitFileFunctionsv> */
/* @0x2a2a34 ldr r3, [r4] */
/* @0x2a2a38 ldr r1, [pc, #0x1b0] */
/* @0x2a2a3c mov r0, r4 */
/* @0x2a2a40 add r1, pc, r1 */
/* @0x2a2a44 ldr r3, [r3, #0xc] */
/* @0x2a2a48 blx r3 */
/* @0x2a2a4c bl 0x130ffc <_Z21InitResourceFunctionsv> */
/* @0x2a2a50 ldr r3, [r4] */
/* @0x2a2a54 ldr r1, [pc, #0x198] */
/* @0x2a2a58 mov r0, r4 */
/* @0x2a2a5c add r1, pc, r1 */
/* @0x2a2a60 ldr r3, [r3, #0xc] */
/* @0x2a2a64 blx r3 */
/* @0x2a2a68 bl 0x1278c4 <_Z24InitInteractionFunctionsv> */
/* @0x2a2a6c ldr r3, [r4] */
/* @0x2a2a70 ldr r1, [pc, #0x180] */
/* @0x2a2a74 mov r0, r4 */
/* @0x2a2a78 add r1, pc, r1 */
/* @0x2a2a7c ldr r3, [r3, #0xc] */
/* @0x2a2a80 blx r3 */
/* @0x2a2a84 bl 0x149f4c <_Z15Init3DFunctionsv> */
/* @0x2a2a88 ldr r3, [r4] */
/* @0x2a2a8c ldr r1, [pc, #0x168] */
/* @0x2a2a90 mov r0, r4 */
/* @0x2a2a94 add r1, pc, r1 */
/* @0x2a2a98 ldr r3, [r3, #0xc] */
/* @0x2a2a9c blx r3 */
/* @0x2a2aa0 bl 0x129f74 <_Z22InitParticlesFunctionsv> */
/* @0x2a2aa4 ldr r3, [r4] */
/* @0x2a2aa8 ldr r1, [pc, #0x150] */
/* @0x2a2aac mov r0, r4 */
/* @0x2a2ab0 add r1, pc, r1 */
/* @0x2a2ab4 ldr r3, [r3, #0xc] */
/* @0x2a2ab8 blx r3 */
/* @0x2a2abc bl 0x118720 <_Z17InitMiscFunctionsv> */
/* @0x2a2ac0 ldr r3, [r4] */
/* @0x2a2ac4 ldr r1, [pc, #0x138] */
/* @0x2a2ac8 mov r0, r4 */
/* @0x2a2acc add r1, pc, r1 */
/* @0x2a2ad0 ldr r3, [r3, #0xc] */
/* @0x2a2ad4 blx r3 */
/* @0x2a2ad8 bl 0x10057c <_Z27InitDataStructuresFunctionsv> */
/* @0x2a2adc ldr r3, [r4] */
/* @0x2a2ae0 ldr r1, [pc, #0x120] */
/* @0x2a2ae4 mov r0, r4 */
/* @0x2a2ae8 add r1, pc, r1 */
/* @0x2a2aec ldr r3, [r3, #0xc] */
/* @0x2a2af0 blx r3 */
/* @0x2a2af4 bl 0x13672c <_Z18InitSoundFunctionsv> */
/* @0x2a2af8 ldr r3, [r4] */
/* @0x2a2afc ldr r1, [pc, #0x108] */
/* @0x2a2b00 mov r0, r4 */
/* @0x2a2b04 add r1, pc, r1 */
/* @0x2a2b08 ldr r3, [r3, #0xc] */
/* @0x2a2b0c blx r3 */
/* @0x2a2b10 bl 0x150434 <InitPhysicsFunctions> */
/* @0x2a2b14 ldr r3, [r4] */
/* @0x2a2b18 ldr r1, [pc, #0xf0] */
/* @0x2a2b1c mov r0, r4 */
/* @0x2a2b20 add r1, pc, r1 */
/* @0x2a2b24 ldr r3, [r3, #0xc] */
/* @0x2a2b28 blx r3 */
/* @0x2a2b2c bl 0x152c9c <_Z20InitGamepadFunctionsv> */
/* @0x2a2b30 ldr r3, [r4] */
/* @0x2a2b34 ldr r1, [pc, #0xd8] */
/* @0x2a2b38 mov r0, r4 */
/* @0x2a2b3c add r1, pc, r1 */
/* @0x2a2b40 ldr r3, [r3, #0xc] */
/* @0x2a2b44 blx r3 */
/* @0x2a2b48 bl 0xc75fc <_Z19InitBufferFunctionsv> */
/* @0x2a2b4c bl 0xca9a0 <_Z25InitBufferVertexFunctionsv> */
/* @0x2a2b50 ldr r3, [r4] */
/* @0x2a2b54 ldr r1, [pc, #0xbc] */
/* @0x2a2b58 mov r0, r4 */
/* @0x2a2b5c add r1, pc, r1 */
/* @0x2a2b60 ldr r3, [r3, #0xc] */
/* @0x2a2b64 blx r3 */
/* @0x2a2b68 bl 0x299684 <_Z23InitNetworkingFunctionsv> */
/* @0x2a2b6c ldr r3, [r4] */
/* @0x2a2b70 ldr r1, [pc, #0xa4] */
/* @0x2a2b74 mov r0, r4 */
/* @0x2a2b78 add r1, pc, r1 */
/* @0x2a2b7c ldr r3, [r3, #0xc] */
/* @0x2a2b80 blx r3 */
/* @0x2a2b84 bl 0x1e2184 <_Z19InitShaderFunctionsv> */
/* @0x2a2b88 bl 0x1e2fe8 <_Z17InitVertexFormatsv> */
/* @0x2a2b8c bl 0x16258c <_Z18InitSteamFunctionsv> */
/* @0x2a2b90 bl 0x155ea0 <_Z17InitPushFunctionsv> */
/* @0x2a2b94 ldr r3, [r4] */
/* @0x2a2b98 ldr r1, [pc, #0x80] */
/* @0x2a2b9c mov r0, r4 */
/* @0x2a2ba0 add r1, pc, r1 */
/* @0x2a2ba4 ldr r3, [r3, #0xc] */
/* @0x2a2ba8 blx r3 */
/* @0x2a2bac bl 0x15a0d0 <_Z17InitYoYoFunctionsv> */
/* @0x2a2bb0 bl 0x128b58 <_Z18InitMetroFunctionsv> */
/* @0x2a2bb4 bl 0x1c1540 <_ZN13CLayerManager18InitLayerFunctionsEv> */
/* @0x2a2bb8 ldr r3, [r4] */
/* @0x2a2bbc ldr r1, [pc, #0x60] */
/* @0x2a2bc0 mov r0, r4 */
/* @0x2a2bc4 add r1, pc, r1 */
/* @0x2a2bc8 ldr r3, [r3, #0xc] */
/* @0x2a2bcc blx r3 */
/* @0x2a2bd0 pop {r4, pc} */
/* @0x2a2bd4 mulseq r4, r8, r1 */
/* @0x2a2bd8 andeq r7, r11, r4, lsl r10 */
/* @0x2a2bdc strdeq r7, r8, [r11], -r12 */
/* @0x2a2be0 andeq r7, r11, r8, ror #19 */
/* @0x2a2be4 ldrdeq r7, r8, [r11], -r4 */
/* @0x2a2be8 andeq r7, r11, r4, asr #19 */
/* @0x2a2bec strheq r7, [r11], -r4 */
/* @0x2a2bf0 andeq r7, r11, r0, lsr #19 */
/* @0x2a2bf4 muleq r11, r0, r9 */
/* @0x2a2bf8 andeq r7, r11, r4, lsl #19 */
/* @0x2a2bfc andeq r7, r11, r0, ror r9 */
/* @0x2a2c00 andeq r7, r11, r0, ror #18 */
/* @0x2a2c04 andeq r7, r11, r12, asr #18 */
/* @0x2a2c08 andeq r7, r11, r8, lsr r9 */
/* @0x2a2c0c andeq r7, r11, r4, lsr #18 */
/* @0x2a2c10 andeq r7, r11, r4, lsl r9 */
/* @0x2a2c14 andeq r7, r11, r4, lsl #18 */
/* @0x2a2c18 strdeq r7, r8, [r11], -r0 */
/* @0x2a2c1c andeq r7, r11, r4, ror #17 */
/* @0x2a2c20 andeq r7, r11, r8, asr #17 */
/* @0x2a2c24 andeq r7, r11, r12, lsr #17 */
