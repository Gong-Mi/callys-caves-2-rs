/* libyoyo.so 覆盖卡组 0119
 * 函数 0x17fd24..0x18269c，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x17fd24 · Graphics::SetRenderState(eRenderState, unsigned int) · size=1924 · insn=481 */
/* @0x17fd24 push {r3, r4, r5, r6, r7, lr} */
/* @0x17fd28 sub r0, r0, #1 */
/* @0x17fd2c ldr r4, [pc, #0x4fc] */
/* @0x17fd30 mov r5, r1 */
/* @0x17fd34 add r4, pc, r4 */
/* @0x17fd38 cmp r0, #31 */
/* @0x17fd3c addls pc, pc, r0, lsl #2 */
/* @0x17fd40 b 0x17fdc4 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0xa0> */
/* @0x17fd44 b 0x1802c4 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x5a0> */
/* @0x17fd48 b 0x17fdc4 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0xa0> */
/* @0x17fd4c b 0x1801f4 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x4d0> */
/* @0x17fd50 b 0x1801d4 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x4b0> */
/* @0x17fd54 b 0x1801a4 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x480> */
/* @0x17fd58 b 0x180168 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x444> */
/* @0x17fd5c b 0x180128 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x404> */
/* @0x17fd60 b 0x1800e0 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x3bc> */
/* @0x17fd64 b 0x1800c4 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x3a0> */
/* @0x17fd68 b 0x180078 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x354> */
/* @0x17fd6c b 0x18002c <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x308> */
/* @0x17fd70 b 0x180024 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x300> */
/* @0x17fd74 b 0x17ffc4 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x2a0> */
/* @0x17fd78 b 0x17fdc4 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0xa0> */
/* @0x17fd7c b 0x17fec0 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x19c> */
/* @0x17fd80 b 0x17fe88 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x164> */
/* @0x17fd84 b 0x17fe50 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x12c> */
/* @0x17fd88 b 0x17fe18 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0xf4> */
/* @0x17fd8c b 0x17fdc4 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0xa0> */
/* @0x17fd90 b 0x17fdc4 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0xa0> */
/* @0x17fd94 b 0x17ff3c <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x218> */
/* @0x17fd98 b 0x17fdc4 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0xa0> */
/* @0x17fd9c b 0x17fdc4 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0xa0> */
/* @0x17fda0 b 0x17fde8 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0xc4> */
/* @0x17fda4 b 0x17fdc8 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0xa4> */
/* @0x17fda8 b 0x180394 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x670> */
/* @0x17fdac b 0x180338 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x614> */
/* @0x17fdb0 b 0x1803c8 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x6a4> */
/* @0x17fdb4 b 0x1802f8 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x5d4> */
/* @0x17fdb8 b 0x180424 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x700> */
/* @0x17fdbc b 0x17ff6c <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x248> */
/* @0x17fdc0 b 0x17ffac <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x288> */
/* @0x17fdc4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x17fdc8 mov r0, #2960 */
/* @0x17fdcc cmp r5, #0 */
/* @0x17fdd0 bne 0x180464 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x740> */
/* @0x17fdd4 ldr r3, [pc, #0x4e4] */
/* @0x17fdd8 ldr r3, [r4, r3] */
/* @0x17fddc ldr r3, [r3] */
/* @0x17fde0 blx r3 */
/* @0x17fde4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x17fde8 ldr lr, [pc, #0x444] */
/* @0x17fdec and r0, r1, #1 */
/* @0x17fdf0 ldr r12, [pc, #0x440] */
/* @0x17fdf4 ubfx r1, r1, #0x1, #0x1 */
/* @0x17fdf8 ubfx r2, r5, #0x2, #0x1 */
/* @0x17fdfc ubfx r3, r5, #0x3, #0x1 */
/* @0x17fe00 ldr lr, [r4, lr] */
/* @0x17fe04 str r5, [lr] */
/* @0x17fe08 ldr r12, [r4, r12] */
/* @0x17fe0c ldr r12, [r12] */
/* @0x17fe10 blx r12 */
/* @0x17fe14 pop {r3, r4, r5, r6, r7, pc} */
/* @0x17fe18 ldr r2, [pc, #0x41c] */
/* @0x17fe1c ldr r3, [pc, #0x41c] */
/* @0x17fe20 ldr r2, [r4, r2] */
/* @0x17fe24 str r1, [r2] */
/* @0x17fe28 ldr r3, [r4, r3] */
/* @0x17fe2c ldr r3, [r3] */
/* @0x17fe30 cmp r3, #0 */
/* @0x17fe34 popne {r3, r4, r5, r6, r7, pc} */
/* @0x17fe38 ldr r3, [pc, #0x404] */
/* @0x17fe3c movw r0, #0xb64 */
/* @0x17fe40 ldr r3, [r4, r3] */
/* @0x17fe44 ldr r3, [r3] */
/* @0x17fe48 blx r3 */
/* @0x17fe4c pop {r3, r4, r5, r6, r7, pc} */
/* @0x17fe50 ldr r2, [pc, #0x3f0] */
/* @0x17fe54 ldr r3, [pc, #0x3e4] */
/* @0x17fe58 ldr r2, [r4, r2] */
/* @0x17fe5c str r1, [r2] */
/* @0x17fe60 ldr r3, [r4, r3] */
/* @0x17fe64 ldr r3, [r3] */
/* @0x17fe68 cmp r3, #0 */
/* @0x17fe6c popne {r3, r4, r5, r6, r7, pc} */
/* @0x17fe70 ldr r3, [pc, #0x3cc] */
/* @0x17fe74 movw r0, #0xb63 */
/* @0x17fe78 ldr r3, [r4, r3] */
/* @0x17fe7c ldr r3, [r3] */
/* @0x17fe80 blx r3 */
/* @0x17fe84 pop {r3, r4, r5, r6, r7, pc} */
/* @0x17fe88 ldr r3, [pc, #0x3b0] */
/* @0x17fe8c ldr r3, [r4, r3] */
/* @0x17fe90 ldr r3, [r3] */
/* @0x17fe94 cmp r3, #0 */
/* @0x17fe98 popne {r3, r4, r5, r6, r7, pc} */
/* @0x17fe9c ldr r3, [pc, #0x3a0] */
/* @0x17fea0 mov r0, r1 */
/* @0x17fea4 ldr r3, [r4, r3] */
/* @0x17fea8 ldr r4, [r3] */
/* @0x17feac bl 0x17fcc8 <_Z14ConvertFogMode4eFog> */
/* @0x17feb0 mov r1, r0 */
/* @0x17feb4 movw r0, #0xb65 */
/* @0x17feb8 blx r4 */
/* @0x17febc pop {r3, r4, r5, r6, r7, pc} */
/* @0x17fec0 uxtb r3, r1 */
/* @0x17fec4 ubfx r5, r1, #0x10, #0x8 */
/* @0x17fec8 vldr s15, [pc, #856] */
/* @0x17fecc ldr r2, [pc, #0x378] */
/* @0x17fed0 vmov s12, r3 */
/* @0x17fed4 ubfx r3, r1, #0x8, #0x8 */
/* @0x17fed8 vmov s11, r5 */
/* @0x17fedc vmov s14, r3 */
/* @0x17fee0 ldr r1, [r4, r2] */
/* @0x17fee4 vcvt.f32.s32 s12, s12 */
/* @0x17fee8 ldr r3, [pc, #0x350] */
/* @0x17feec mov r2, #1065353216 */
/* @0x17fef0 str r2, [r1, #0xc] */
/* @0x17fef4 vcvt.f32.s32 s14, s14 */
/* @0x17fef8 vcvt.f32.s32 s13, s11 */
/* @0x17fefc vmul.f32 s12, s12, s15 */
/* @0x17ff00 vmul.f32 s14, s14, s15 */
/* @0x17ff04 vstr s12, [r1] */
/* @0x17ff08 vmul.f32 s15, s13, s15 */
/* @0x17ff0c vstr s14, [r1, #4] */
/* @0x17ff10 vstr s15, [r1, #8] */
/* @0x17ff14 ldr r3, [r4, r3] */
/* @0x17ff18 ldr r3, [r3] */
/* @0x17ff1c cmp r3, #0 */
/* @0x17ff20 popne {r3, r4, r5, r6, r7, pc} */
/* @0x17ff24 ldr r3, [pc, #0x324] */
/* @0x17ff28 movw r0, #0xb66 */
/* @0x17ff2c ldr r3, [r4, r3] */
/* @0x17ff30 ldr r3, [r3] */
/* @0x17ff34 blx r3 */
/* @0x17ff38 pop {r3, r4, r5, r6, r7, pc} */
/* @0x17ff3c ldr r2, [pc, #0x310] */
/* @0x17ff40 adds r1, r1, #0 */
/* @0x17ff44 ldr r3, [pc, #0x2f4] */
/* @0x17ff48 movne r1, #1 */
/* @0x17ff4c ldr r2, [r4, r2] */
/* @0x17ff50 strb r1, [r2] */
/* @0x17ff54 ldr r3, [r4, r3] */
/* @0x17ff58 ldr r3, [r3] */
/* @0x17ff5c cmp r3, #0 */
/* @0x17ff60 popne {r3, r4, r5, r6, r7, pc} */
/* @0x17ff64 mov r0, #2896 */
/* @0x17ff68 b 0x17fdcc <_ZN8Graphics14SetRenderStateE12eRenderStatej+0xa8> */
/* @0x17ff6c ldr r1, [pc, #0x344] */
/* @0x17ff70 ldr r2, [pc, #0x338] */
/* @0x17ff74 ldr r3, [pc, #0x338] */
/* @0x17ff78 ldr r6, [r4, r1] */
/* @0x17ff7c str r5, [r6] */
/* @0x17ff80 ldr r2, [r4, r2] */
/* @0x17ff84 ldr r3, [r4, r3] */
/* @0x17ff88 ldr r0, [r2] */
/* @0x17ff8c ldr r5, [r3] */
/* @0x17ff90 bl 0x17fc3c <_Z17ConvertComparison8eCmpFunc> */
/* @0x17ff94 ldr r3, [pc, #0x310] */
/* @0x17ff98 ldr r2, [r6] */
/* @0x17ff9c ldr r3, [r4, r3] */
/* @0x17ffa0 ldr r1, [r3] */
/* @0x17ffa4 blx r5 */
/* @0x17ffa8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x17ffac ldr r3, [pc, #0x2a4] */
/* @0x17ffb0 mov r0, r1 */
/* @0x17ffb4 ldr r3, [r4, r3] */
/* @0x17ffb8 ldr r3, [r3] */
/* @0x17ffbc blx r3 */
/* @0x17ffc0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x17ffc4 ldr r2, [pc, #0x290] */
/* @0x17ffc8 adds r1, r1, #0 */
/* @0x17ffcc ldr r3, [pc, #0x26c] */
/* @0x17ffd0 movne r1, #1 */
/* @0x17ffd4 ldr r2, [r4, r2] */
/* @0x17ffd8 strb r1, [r2] */
/* @0x17ffdc ldr r3, [r4, r3] */
/* @0x17ffe0 ldr r3, [r3] */
/* @0x17ffe4 cmp r3, #0 */
/* @0x17ffe8 popne {r3, r4, r5, r6, r7, pc} */
/* @0x17ffec ldr r3, [pc, #0x26c] */
/* @0x17fff0 movw r0, #0xc54 */
/* @0x17fff4 mov r1, #4352 */
/* @0x17fff8 ldr r3, [r4, r3] */
/* @0x17fffc ldr r3, [r3] */
/* @0x180000 blx r3 */
/* @0x180004 ldr r3, [pc, #0x238] */
/* @0x180008 movw r0, #0xb62 */
/* @0x18000c mov r1, #1065353216 */
/* @0x180010 ldr r3, [r4, r3] */
/* @0x180014 ldr r3, [r3] */
/* @0x180018 blx r3 */
/* @0x18001c mov r0, #2912 */
/* @0x180020 b 0x17fdcc <_ZN8Graphics14SetRenderStateE12eRenderStatej+0xa8> */
/* @0x180024 movw r0, #0xbe2 */
/* @0x180028 b 0x17fdcc <_ZN8Graphics14SetRenderStateE12eRenderStatej+0xa8> */
/* @0x18002c ldr r3, [pc, #0x20c] */
/* @0x180030 ldr r3, [r4, r3] */
/* @0x180034 ldr r3, [r3] */
/* @0x180038 cmp r3, #0 */
/* @0x18003c popne {r3, r4, r5, r6, r7, pc} */
/* @0x180040 ldr r3, [pc, #0x21c] */
/* @0x180044 mov r0, r1 */
/* @0x180048 ldr r3, [r4, r3] */
/* @0x18004c ldr r5, [r3] */
/* @0x180050 bl 0x17fc3c <_Z17ConvertComparison8eCmpFunc> */
/* @0x180054 ldr r3, [pc, #0x20c] */
/* @0x180058 vldr s15, [pc, #460] */
/* @0x18005c ldr r3, [r4, r3] */
/* @0x180060 vldr s14, [r3] */
/* @0x180064 vcvt.f32.s32 s14, s14 */
/* @0x180068 vdiv.f32 s15, s14, s15 */
/* @0x18006c vmov r1, s15 */
/* @0x180070 blx r5 */
/* @0x180074 pop {r3, r4, r5, r6, r7, pc} */
/* @0x180078 ldr r2, [pc, #0x1e8] */
/* @0x18007c ldr r3, [pc, #0x1bc] */
/* @0x180080 ldr r2, [r4, r2] */
/* @0x180084 str r1, [r2] */
/* @0x180088 ldr r3, [r4, r3] */
/* @0x18008c ldr r3, [r3] */
/* @0x180090 cmp r3, #0 */
/* @0x180094 popne {r3, r4, r5, r6, r7, pc} */
/* @0x180098 vmov s11, r1 */
/* @0x18009c vldr s15, [pc, #392] */
/* @0x1800a0 ldr r3, [pc, #0x1bc] */
/* @0x1800a4 mov r0, #516 */
/* @0x1800a8 vcvt.f32.u32 s14, s11 */
/* @0x1800ac ldr r3, [r4, r3] */
/* @0x1800b0 ldr r3, [r3] */
/* @0x1800b4 vdiv.f32 s15, s14, s15 */
/* @0x1800b8 vmov r1, s15 */
/* @0x1800bc blx r3 */
/* @0x1800c0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1800c4 ldr r3, [pc, #0x1a0] */
/* @0x1800c8 mov r0, r1 */
/* @0x1800cc ldr r3, [r4, r3] */
/* @0x1800d0 ldr r4, [r3] */
/* @0x1800d4 bl 0x17fc3c <_Z17ConvertComparison8eCmpFunc> */
/* @0x1800d8 blx r4 */
/* @0x1800dc pop {r3, r4, r5, r6, r7, pc} */
/* @0x1800e0 ldr r3, [pc, #0x188] */
/* @0x1800e4 mov r0, r1 */
/* @0x1800e8 ldr r3, [r4, r3] */
/* @0x1800ec str r1, [r3] */
/* @0x1800f0 bl 0x17fc68 <_Z11ConvertCull5eCull> */
/* @0x1800f4 subs r5, r0, #0 */
/* @0x1800f8 blt 0x180490 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x76c> */
/* @0x1800fc ldr r3, [pc, #0x1b8] */
/* @0x180100 movw r0, #0xb44 */
/* @0x180104 ldr r3, [r4, r3] */
/* @0x180108 ldr r3, [r3] */
/* @0x18010c blx r3 */
/* @0x180110 ldr r3, [pc, #0x15c] */
/* @0x180114 mov r0, r5 */
/* @0x180118 ldr r3, [r4, r3] */
/* @0x18011c ldr r3, [r3] */
/* @0x180120 blx r3 */
/* @0x180124 pop {r3, r4, r5, r6, r7, pc} */
/* @0x180128 ldr r3, [pc, #0x148] */
/* @0x18012c mov r0, r1 */
/* @0x180130 ldr r1, [r4, r3] */
/* @0x180134 bl 0x17fc0c <_Z12ConvertBlend6eBlendPi> */
/* @0x180138 ldr r12, [pc, #0x13c] */
/* @0x18013c ldr r3, [pc, #0x13c] */
/* @0x180140 ldr r2, [pc, #0x13c] */
/* @0x180144 ldr r12, [r4, r12] */
/* @0x180148 str r0, [r12] */
/* @0x18014c mov r1, r0 */
/* @0x180150 ldr r3, [r4, r3] */
/* @0x180154 ldr r2, [r4, r2] */
/* @0x180158 ldr r3, [r3] */
/* @0x18015c ldr r0, [r2] */
/* @0x180160 blx r3 */
/* @0x180164 pop {r3, r4, r5, r6, r7, pc} */
/* @0x180168 ldr r3, [pc, #0x118] */
/* @0x18016c mov r0, r1 */
/* @0x180170 ldr r1, [r4, r3] */
/* @0x180174 bl 0x17fc0c <_Z12ConvertBlend6eBlendPi> */
/* @0x180178 ldr r1, [pc, #0x104] */
/* @0x18017c ldr r3, [pc, #0xfc] */
/* @0x180180 ldr r2, [pc, #0xf4] */
/* @0x180184 ldr r1, [r4, r1] */
/* @0x180188 str r0, [r1] */
/* @0x18018c ldr r3, [r4, r3] */
/* @0x180190 ldr r2, [r4, r2] */
/* @0x180194 ldr r3, [r3] */
/* @0x180198 ldr r1, [r2] */
/* @0x18019c blx r3 */
/* @0x1801a0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1801a4 ldr r2, [pc, #0xe0] */
/* @0x1801a8 adds r1, r1, #0 */
/* @0x1801ac ldr r3, [pc, #0x8c] */
/* @0x1801b0 movne r1, #1 */
/* @0x1801b4 ldr r2, [r4, r2] */
/* @0x1801b8 strb r1, [r2] */
/* @0x1801bc ldr r3, [r4, r3] */
/* @0x1801c0 ldr r3, [r3] */
/* @0x1801c4 cmp r3, #0 */
/* @0x1801c8 popne {r3, r4, r5, r6, r7, pc} */
/* @0x1801cc mov r0, #3008 */
/* @0x1801d0 b 0x17fdcc <_ZN8Graphics14SetRenderStateE12eRenderStatej+0xa8> */
/* @0x1801d4 ldr r3, [pc, #0xb4] */
/* @0x1801d8 cmp r1, #0 */
/* @0x1801dc movne r0, #1 */
/* @0x1801e0 moveq r0, r1 */
/* @0x1801e4 ldr r3, [r4, r3] */
/* @0x1801e8 ldr r3, [r3] */
/* @0x1801ec blx r3 */
/* @0x1801f0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1801f4 ldr r3, [pc, #0x44] */
/* @0x1801f8 ldr r3, [r4, r3] */
/* @0x1801fc ldr r3, [r3] */
/* @0x180200 cmp r3, #0 */
/* @0x180204 popne {r3, r4, r5, r6, r7, pc} */
/* @0x180208 ldr r3, [pc, #0x84] */
/* @0x18020c cmp r1, #1 */
/* @0x180210 moveq r0, #7424 */
/* @0x180214 movwne r0, #0x1d01 */
/* @0x180218 ldr r3, [r4, r3] */
/* @0x18021c ldr r3, [r3] */
/* @0x180220 blx r3 */
/* @0x180224 pop {r3, r4, r5, r6, r7, pc} */
/* @0x180228 bllo 0xfe1a0434 <b2_toiTime+0xfffffffffda46f90> */
/* @0x18022c cmnmi pc, #0 */
/* @0x180230 eoreq r1, r7, r12, lsl pc */
/* @0x180234 .word 0xffffe870 */
/* @0x180238 .word 0xffffbb18 */
/* @0x18023c .word 0xffffe874 */
/* @0x180240 .word 0xffffe7b8 */
/* @0x180244 .word 0xffffbc98 */
/* @0x180248 .word 0xffffe878 */
/* @0x18024c .word 0xffffe87c */
/* @0x180250 .word 0xffffbc9c */
/* @0x180254 .word 0xffffe880 */
/* @0x180258 .word 0xffffbb58 */
/* @0x18025c .word 0xffffe884 */
/* @0x180260 .word 0xffffbb14 */
/* @0x180264 .word 0xffffbc1c */
/* @0x180268 .word 0xffffe888 */
/* @0x18026c .word 0xffffbaec */
/* @0x180270 .word 0xffffe82c */
/* @0x180274 .word 0xffffbb10 */
/* @0x180278 .word 0xffffe88c */
/* @0x18027c .word 0xffffe890 */
/* @0x180280 .word 0xffffbac8 */
/* @0x180284 .word 0xffffe894 */
/* @0x180288 .word 0xffffe898 */
/* @0x18028c .word 0xffffe89c */
/* @0x180290 .word 0xffffbb0c */
/* @0x180294 .word 0xffffbc64 */
/* @0x180298 .word 0xffffe8a0 */
/* @0x18029c .word 0xffffe8a4 */
/* @0x1802a0 .word 0xffffe8a8 */
/* @0x1802a4 .word 0xffffbb5c */
/* @0x1802a8 .word 0xffffe8ac */
/* @0x1802ac .word 0xffffe8b0 */
/* @0x1802b0 .word 0xffffe8b4 */
/* @0x1802b4 .word 0xffffbb54 */
/* @0x1802b8 .word 0xffffe8b8 */
/* @0x1802bc .word 0xffffbad8 */
/* @0x1802c0 .word 0xffffbad0 */
/* @0x1802c4 ldr r3, [pc, #-0x34] */
/* @0x1802c8 adds r5, r1, #0 */
/* @0x1802cc movne r5, #1 */
/* @0x1802d0 cmp r5, #0 */
/* @0x1802d4 ldr r3, [r4, r3] */
/* @0x1802d8 strb r5, [r3] */
/* @0x1802dc beq 0x180478 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x754> */
/* @0x1802e0 ldr r3, [pc, #-0x2c] */
/* @0x1802e4 movw r0, #0xb71 */
/* @0x1802e8 ldr r3, [r4, r3] */
/* @0x1802ec ldr r3, [r3] */
/* @0x1802f0 blx r3 */
/* @0x1802f4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1802f8 ldr r2, [pc, #-0x50] */
/* @0x1802fc mov r0, r1 */
/* @0x180300 ldr r3, [pc, #-0x54] */
/* @0x180304 ldr r2, [r4, r2] */
/* @0x180308 str r1, [r2] */
/* @0x18030c ldr r3, [r4, r3] */
/* @0x180310 ldr r5, [r3] */
/* @0x180314 bl 0x17fc3c <_Z17ConvertComparison8eCmpFunc> */
/* @0x180318 ldr r2, [pc, #-0x74] */
/* @0x18031c ldr r3, [pc, #-0x6c] */
/* @0x180320 ldr r2, [r4, r2] */
/* @0x180324 ldr r3, [r4, r3] */
/* @0x180328 ldr r1, [r2] */
/* @0x18032c ldr r2, [r3] */
/* @0x180330 blx r5 */
/* @0x180334 pop {r3, r4, r5, r6, r7, pc} */
/* @0x180338 ldr r1, [pc, #-0x98] */
/* @0x18033c ldr r2, [pc, #-0xa4] */
/* @0x180340 ldr r3, [pc, #-0xa4] */
/* @0x180344 ldr r6, [r4, r1] */
/* @0x180348 str r5, [r6] */
/* @0x18034c ldr r2, [r4, r2] */
/* @0x180350 ldr r3, [r4, r3] */
/* @0x180354 ldr r0, [r2] */
/* @0x180358 ldr r5, [r3] */
/* @0x18035c bl 0x17fcf8 <_Z16ConvertStencilOp10eStencilOp> */
/* @0x180360 mov r7, r0 */
/* @0x180364 ldr r0, [r6] */
/* @0x180368 bl 0x17fcf8 <_Z16ConvertStencilOp10eStencilOp> */
/* @0x18036c ldr r3, [pc, #-0xd8] */
/* @0x180370 ldr r3, [r4, r3] */
/* @0x180374 mov r6, r0 */
/* @0x180378 ldr r0, [r3] */
/* @0x18037c bl 0x17fcf8 <_Z16ConvertStencilOp10eStencilOp> */
/* @0x180380 mov r1, r6 */
/* @0x180384 mov r2, r0 */
/* @0x180388 mov r0, r7 */
/* @0x18038c blx r5 */
/* @0x180390 pop {r3, r4, r5, r6, r7, pc} */
/* @0x180394 ldr r2, [pc, #-0xfc] */
/* @0x180398 mov r0, r1 */
/* @0x18039c ldr r3, [pc, #-0x100] */
/* @0x1803a0 ldr r2, [r4, r2] */
/* @0x1803a4 str r1, [r2] */
/* @0x1803a8 ldr r3, [r4, r3] */
/* @0x1803ac ldr r5, [r3] */
/* @0x1803b0 bl 0x17fcf8 <_Z16ConvertStencilOp10eStencilOp> */
/* @0x1803b4 ldr r3, [pc, #-0x114] */
/* @0x1803b8 ldr r3, [r4, r3] */
/* @0x1803bc mov r7, r0 */
/* @0x1803c0 ldr r0, [r3] */
/* @0x1803c4 b 0x180368 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x644> */
/* @0x1803c8 ldr r1, [pc, #-0x134] */
/* @0x1803cc ldr r2, [pc, #-0x134] */
/* @0x1803d0 ldr r3, [pc, #-0x134] */
/* @0x1803d4 ldr r6, [r4, r1] */
/* @0x1803d8 str r5, [r6] */
/* @0x1803dc ldr r2, [r4, r2] */
/* @0x1803e0 ldr r3, [r4, r3] */
/* @0x1803e4 ldr r0, [r2] */
/* @0x1803e8 ldr r5, [r3] */
/* @0x1803ec bl 0x17fcf8 <_Z16ConvertStencilOp10eStencilOp> */
/* @0x1803f0 ldr r3, [pc, #-0x150] */
/* @0x1803f4 ldr r3, [r4, r3] */
/* @0x1803f8 mov r7, r0 */
/* @0x1803fc ldr r0, [r3] */
/* @0x180400 bl 0x17fcf8 <_Z16ConvertStencilOp10eStencilOp> */
/* @0x180404 mov r4, r0 */
/* @0x180408 ldr r0, [r6] */
/* @0x18040c bl 0x17fcf8 <_Z16ConvertStencilOp10eStencilOp> */
/* @0x180410 mov r1, r4 */
/* @0x180414 mov r2, r0 */
/* @0x180418 mov r0, r7 */
/* @0x18041c blx r5 */
/* @0x180420 pop {r3, r4, r5, r6, r7, pc} */
/* @0x180424 ldr r1, [pc, #-0x180] */
/* @0x180428 ldr r2, [pc, #-0x180] */
/* @0x18042c ldr r3, [pc, #-0x180] */
/* @0x180430 ldr r6, [r4, r1] */
/* @0x180434 str r5, [r6] */
/* @0x180438 ldr r2, [r4, r2] */
/* @0x18043c ldr r3, [r4, r3] */
/* @0x180440 ldr r0, [r2] */
/* @0x180444 ldr r5, [r3] */
/* @0x180448 bl 0x17fc3c <_Z17ConvertComparison8eCmpFunc> */
/* @0x18044c ldr r3, [pc, #-0x19c] */
/* @0x180450 ldr r1, [r6] */
/* @0x180454 ldr r3, [r4, r3] */
/* @0x180458 ldr r2, [r3] */
/* @0x18045c blx r5 */
/* @0x180460 pop {r3, r4, r5, r6, r7, pc} */
/* @0x180464 ldr r3, [pc, #-0x1b0] */
/* @0x180468 ldr r3, [r4, r3] */
/* @0x18046c ldr r3, [r3] */
/* @0x180470 blx r3 */
/* @0x180474 pop {r3, r4, r5, r6, r7, pc} */
/* @0x180478 ldr r3, [pc, #-0x1c0] */
/* @0x18047c movw r0, #0xb71 */
/* @0x180480 ldr r3, [r4, r3] */
/* @0x180484 ldr r3, [r3] */
/* @0x180488 blx r3 */
/* @0x18048c pop {r3, r4, r5, r6, r7, pc} */
/* @0x180490 ldr r3, [pc, #-0x1d8] */
/* @0x180494 movw r0, #0xb44 */
/* @0x180498 ldr r3, [r4, r3] */
/* @0x18049c ldr r3, [r3] */
/* @0x1804a0 blx r3 */
/* @0x1804a4 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x1804a8 · Graphics::SetRenderStateEx(int, unsigned int) · size=4 · insn=1 */
/* @0x1804a8 b 0x17fd24 <_ZN8Graphics14SetRenderStateE12eRenderStatej> */

/* ── FUNC 0x1804ac · Graphics::ResetBlends() · size=4 · insn=1 */
/* @0x1804ac bx lr */

/* ── FUNC 0x1804b0 · Graphics::SetSamplerState(int, eSamplerState, unsigned int) · size=260 · insn=65 */
/* @0x1804b0 cmp r0, #8 */
/* @0x1804b4 ldr r3, [pc, #0xd0] */
/* @0x1804b8 add r3, pc, r3 */
/* @0x1804bc bxhi lr */
/* @0x1804c0 cmp r1, #8 */
/* @0x1804c4 addls pc, pc, r1, lsl #2 */
/* @0x1804c8 b 0x1804fc <_ZN8Graphics15SetSamplerStateEi13eSamplerStatej+0x4c> */
/* @0x1804cc b 0x1804f0 <_ZN8Graphics15SetSamplerStateEi13eSamplerStatej+0x40> */
/* @0x1804d0 b 0x180510 <_ZN8Graphics15SetSamplerStateEi13eSamplerStatej+0x60> */
/* @0x1804d4 b 0x180520 <_ZN8Graphics15SetSamplerStateEi13eSamplerStatej+0x70> */
/* @0x1804d8 b 0x180530 <_ZN8Graphics15SetSamplerStateEi13eSamplerStatej+0x80> */
/* @0x1804dc b 0x180540 <_ZN8Graphics15SetSamplerStateEi13eSamplerStatej+0x90> */
/* @0x1804e0 b 0x180550 <_ZN8Graphics15SetSamplerStateEi13eSamplerStatej+0xa0> */
/* @0x1804e4 b 0x180564 <_ZN8Graphics15SetSamplerStateEi13eSamplerStatej+0xb4> */
/* @0x1804e8 b 0x180578 <_ZN8Graphics15SetSamplerStateEi13eSamplerStatej+0xc8> */
/* @0x1804ec b 0x180500 <_ZN8Graphics15SetSamplerStateEi13eSamplerStatej+0x50> */
/* @0x1804f0 ldr r1, [pc, #0x98] */
/* @0x1804f4 ldr r3, [r3, r1] */
/* @0x1804f8 str r2, [r3, r0, lsl #2] */
/* @0x1804fc b 0x180ed4 <_Z28UpdateCurrentTextureSettingsi> */
/* @0x180500 ldr r1, [pc, #0x8c] */
/* @0x180504 ldr r3, [r3, r1] */
/* @0x180508 str r2, [r3, r0, lsl #2] */
/* @0x18050c b 0x1804fc <_ZN8Graphics15SetSamplerStateEi13eSamplerStatej+0x4c> */
/* @0x180510 ldr r1, [pc, #0x80] */
/* @0x180514 ldr r3, [r3, r1] */
/* @0x180518 str r2, [r3, r0, lsl #2] */
/* @0x18051c b 0x1804fc <_ZN8Graphics15SetSamplerStateEi13eSamplerStatej+0x4c> */
/* @0x180520 ldr r1, [pc, #0x74] */
/* @0x180524 ldr r3, [r3, r1] */
/* @0x180528 str r2, [r3, r0, lsl #2] */
/* @0x18052c b 0x1804fc <_ZN8Graphics15SetSamplerStateEi13eSamplerStatej+0x4c> */
/* @0x180530 ldr r1, [pc, #0x68] */
/* @0x180534 ldr r3, [r3, r1] */
/* @0x180538 str r2, [r3, r0, lsl #2] */
/* @0x18053c b 0x1804fc <_ZN8Graphics15SetSamplerStateEi13eSamplerStatej+0x4c> */
/* @0x180540 ldr r1, [pc, #0x5c] */
/* @0x180544 ldr r3, [r3, r1] */
/* @0x180548 str r2, [r3, r0, lsl #2] */
/* @0x18054c b 0x1804fc <_ZN8Graphics15SetSamplerStateEi13eSamplerStatej+0x4c> */
/* @0x180550 ldr r1, [pc, #0x50] */
/* @0x180554 ldr r3, [r3, r1] */
/* @0x180558 add r3, r3, r0, lsl #2 */
/* @0x18055c str r2, [r3] */
/* @0x180560 b 0x1804fc <_ZN8Graphics15SetSamplerStateEi13eSamplerStatej+0x4c> */
/* @0x180564 ldr r1, [pc, #0x40] */
/* @0x180568 ldr r3, [r3, r1] */
/* @0x18056c add r3, r3, r0, lsl #2 */
/* @0x180570 str r2, [r3] */
/* @0x180574 b 0x1804fc <_ZN8Graphics15SetSamplerStateEi13eSamplerStatej+0x4c> */
/* @0x180578 ldr r1, [pc, #0x30] */
/* @0x18057c ldr r3, [r3, r1] */
/* @0x180580 add r3, r3, r0, lsl #2 */
/* @0x180584 str r2, [r3] */
/* @0x180588 b 0x1804fc <_ZN8Graphics15SetSamplerStateEi13eSamplerStatej+0x4c> */
/* @0x18058c mlaeq r7, r8, r7, r1 */
/* @0x180590 .word 0xffffe8bc */
/* @0x180594 .word 0xffffe8c0 */
/* @0x180598 .word 0xffffe8c4 */
/* @0x18059c .word 0xffffe8c8 */
/* @0x1805a0 .word 0xffffe8cc */
/* @0x1805a4 .word 0xffffe8d0 */
/* @0x1805a8 .word 0xffffe8d4 */
/* @0x1805ac .word 0xffffe8d8 */
/* @0x1805b0 .word 0xffffe8dc */

/* ── FUNC 0x1805b4 · DBG_BIND_FRAMEBUFFER(int) · size=156 · insn=39 */
/* @0x1805b4 push {r3, r4, r5, lr} */
/* @0x1805b8 cmn r0, #1 */
/* @0x1805bc ldr r4, [pc, #0x70] */
/* @0x1805c0 mov r5, r0 */
/* @0x1805c4 add r4, pc, r4 */
/* @0x1805c8 beq 0x180604 <_Z20DBG_BIND_FRAMEBUFFERi+0x50> */
/* @0x1805cc ldr r3, [pc, #0x64] */
/* @0x1805d0 ldr r3, [r4, r3] */
/* @0x1805d4 ldr r3, [r3] */
/* @0x1805d8 cmp r3, #1 */
/* @0x1805dc beq 0x1805fc <_Z20DBG_BIND_FRAMEBUFFERi+0x48> */
/* @0x1805e0 ldr r3, [pc, #0x54] */
/* @0x1805e4 ldr r3, [r4, r3] */
/* @0x1805e8 mov r1, r5 */
/* @0x1805ec movw r0, #0x8d40 */
/* @0x1805f0 ldr r3, [r3] */
/* @0x1805f4 blx r3 */
/* @0x1805f8 pop {r3, r4, r5, pc} */
/* @0x1805fc ldr r3, [pc, #0x3c] */
/* @0x180600 b 0x1805e4 <_Z20DBG_BIND_FRAMEBUFFERi+0x30> */
/* @0x180604 ldr r2, [pc, #0x38] */
/* @0x180608 ldr r3, [pc, #0x38] */
/* @0x18060c ldr r1, [pc, #0x38] */
/* @0x180610 ldr r2, [r4, r2] */
/* @0x180614 ldr r3, [r4, r3] */
/* @0x180618 add r1, pc, r1 */
/* @0x18061c ldr r0, [r2] */
/* @0x180620 ldm r3, {r2, r3} */
/* @0x180624 ldr r12, [r0] */
/* @0x180628 ldr r12, [r12, #0xc] */
/* @0x18062c blx r12 */
/* @0x180630 b 0x1805cc <_Z20DBG_BIND_FRAMEBUFFERi+0x18> */
/* @0x180634 eoreq r1, r7, r12, lsl #13 */
/* @0x180638 .word 0xffffe7b8 */
/* @0x18063c .word 0xffffbc78 */
/* @0x180640 .word 0xffffbb74 */
/* @0x180644 .word 0xffffbac4 */
/* @0x180648 .word 0xffffe81c */
/* @0x18064c andseq r11, r12, r12, lsl #7 */

/* ── FUNC 0x180650 · initRenderBufferStack() · size=172 · insn=43 */
/* @0x180650 ldr r3, [pc, #0x84] */
/* @0x180654 mov r1, #0 */
/* @0x180658 ldr r2, [pc, #0x80] */
/* @0x18065c mov r0, #1 */
/* @0x180660 push {r4, r5, r6} */
/* @0x180664 add r3, pc, r3 */
/* @0x180668 ldr r4, [pc, #0x74] */
/* @0x18066c add r2, pc, r2 */
/* @0x180670 ldr r12, [pc, #0x70] */
/* @0x180674 str r1, [r3] */
/* @0x180678 ldr r4, [r2, r4] */
/* @0x18067c ldr r12, [r2, r12] */
/* @0x180680 ldr r6, [pc, #0x64] */
/* @0x180684 ldr r4, [r4] */
/* @0x180688 ldr r12, [r12] */
/* @0x18068c str r1, [r3, #0x4] */
/* @0x180690 str r1, [r3, #0x8] */
/* @0x180694 str r1, [r3, #0xc] */
/* @0x180698 str r1, [r3, #0x10] */
/* @0x18069c str r1, [r3, #0x14] */
/* @0x1806a0 str r4, [r3, #0x18] */
/* @0x1806a4 str r12, [r3, #0x1c] */
/* @0x1806a8 ldr r5, [pc, #0x40] */
/* @0x1806ac ldr r6, [r2, r6] */
/* @0x1806b0 ldr r1, [pc, #0x3c] */
/* @0x1806b4 ldr r3, [pc, #0x3c] */
/* @0x1806b8 str r4, [r6] */
/* @0x1806bc ldr r4, [r2, r5] */
/* @0x1806c0 str r12, [r4] */
/* @0x1806c4 ldr r1, [r2, r1] */
/* @0x1806c8 pop {r4, r5, r6} */
/* @0x1806cc str r0, [r1] */
/* @0x1806d0 ldr r3, [r2, r3] */
/* @0x1806d4 strb r0, [r3] */
/* @0x1806d8 bx lr */
/* @0x1806dc mlaseq r2, r8, sp, r1 */
/* @0x1806e0 eoreq r1, r7, r4, ror #11 */
/* @0x1806e4 .word 0xffffe24c */
/* @0x1806e8 .word 0xffffe250 */
/* @0x1806ec .word 0xffffe834 */
/* @0x1806f0 .word 0xffffe838 */
/* @0x1806f4 .word 0xffffe8e0 */
/* @0x1806f8 .word 0xffffe8e4 */

/* ── FUNC 0x1806fc · countRenderBufferStack() · size=48 · insn=12 */
/* @0x1806fc push {r3, lr} */
/* @0x180700 ldr r3, [pc, #0x1c] */
/* @0x180704 ldr r3, [pc, r3] */
/* @0x180708 ldrb r3, [r3] */
/* @0x18070c cmp r3, #0 */
/* @0x180710 bne 0x180718 <_Z22countRenderBufferStackv+0x1c> */
/* @0x180714 bl 0x180650 <_Z21initRenderBufferStackv> */
/* @0x180718 ldr r3, [pc, #0x8] */
/* @0x18071c ldr r0, [pc, r3] */
/* @0x180720 pop {r3, pc} */
/* @0x180724 eoreq pc, r6, r0, lsr lr */
/* @0x180728 eorseq r1, r2, r0, ror #25 */

/* ── FUNC 0x18072c · pushRenderBufferStack() · size=124 · insn=31 */
/* @0x18072c push {r3, r4, r5, lr} */
/* @0x180730 ldr r3, [pc, #0x68] */
/* @0x180734 ldr r3, [pc, r3] */
/* @0x180738 ldrb r3, [r3] */
/* @0x18073c cmp r3, #0 */
/* @0x180740 beq 0x180798 <_Z21pushRenderBufferStackv+0x6c> */
/* @0x180744 ldr r3, [pc, #0x58] */
/* @0x180748 add r3, pc, r3 */
/* @0x18074c ldr r12, [r3] */
/* @0x180750 cmp r12, #99 */
/* @0x180754 movgt r5, #0 */
/* @0x180758 bgt 0x180790 <_Z21pushRenderBufferStackv+0x64> */
/* @0x18075c rsb r4, r12, r12, lsl #3 */
/* @0x180760 add r12, r12, #1 */
/* @0x180764 str r12, [r3] */
/* @0x180768 mov r5, #1 */
/* @0x18076c add r4, r3, r4, lsl #2 */
/* @0x180770 rsb r12, r12, r12, lsl #3 */
/* @0x180774 add r4, r4, #4 */
/* @0x180778 add r12, r3, r12, lsl #2 */
/* @0x18077c ldm r4!, {r0, r1, r2, r3} */
/* @0x180780 add r12, r12, #4 */
/* @0x180784 stm r12!, {r0, r1, r2, r3} */
/* @0x180788 ldm r4, {r0, r1, r2} */
/* @0x18078c stm r12, {r0, r1, r2} */
/* @0x180790 mov r0, r5 */
/* @0x180794 pop {r3, r4, r5, pc} */
/* @0x180798 bl 0x180650 <_Z21initRenderBufferStackv> */
/* @0x18079c b 0x180744 <_Z21pushRenderBufferStackv+0x18> */
/* @0x1807a0 eoreq pc, r6, r0, lsl #28 */
/* @0x1807a4 ldrhteq r1, [r2], -r4 */

/* ── FUNC 0x1807a8 · popRenderBufferStack() · size=68 · insn=17 */
/* @0x1807a8 push {r3, lr} */
/* @0x1807ac ldr r3, [pc, #0x30] */
/* @0x1807b0 ldr r3, [pc, r3] */
/* @0x1807b4 ldrb r3, [r3] */
/* @0x1807b8 cmp r3, #0 */
/* @0x1807bc beq 0x1807dc <_Z20popRenderBufferStackv+0x34> */
/* @0x1807c0 ldr r2, [pc, #0x20] */
/* @0x1807c4 add r2, pc, r2 */
/* @0x1807c8 ldr r3, [r2] */
/* @0x1807cc subs r3, r3, #1 */
/* @0x1807d0 movmi r3, #0 */
/* @0x1807d4 str r3, [r2] */
/* @0x1807d8 pop {r3, pc} */
/* @0x1807dc bl 0x180650 <_Z21initRenderBufferStackv> */
/* @0x1807e0 b 0x1807c0 <_Z20popRenderBufferStackv+0x18> */
/* @0x1807e4 eoreq pc, r6, r4, lsl #27 */
/* @0x1807e8 eorseq r1, r2, r8, lsr r12 */

/* ── FUNC 0x1807ec · topRenderBufferStack() · size=152 · insn=38 */
/* @0x1807ec push {r3, r4, r5, lr} */
/* @0x1807f0 mov r5, r0 */
/* @0x1807f4 ldr r3, [pc, #0x80] */
/* @0x1807f8 ldr r3, [pc, r3] */
/* @0x1807fc ldrb r3, [r3] */
/* @0x180800 cmp r3, #0 */
/* @0x180804 beq 0x180848 <_Z20topRenderBufferStackv+0x5c> */
/* @0x180808 ldr r3, [pc, #0x70] */
/* @0x18080c add r3, pc, r3 */
/* @0x180810 ldr r4, [r3] */
/* @0x180814 cmp r4, #0 */
/* @0x180818 ble 0x180850 <_Z20topRenderBufferStackv+0x64> */
/* @0x18081c sub r4, r4, #1 */
/* @0x180820 mov r12, r5 */
/* @0x180824 rsb r4, r4, r4, lsl #3 */
/* @0x180828 add r4, r3, r4, lsl #2 */
/* @0x18082c add r4, r4, #4 */
/* @0x180830 ldm r4!, {r0, r1, r2, r3} */
/* @0x180834 stm r12!, {r0, r1, r2, r3} */
/* @0x180838 ldm r4, {r0, r1, r2} */
/* @0x18083c stm r12, {r0, r1, r2} */
/* @0x180840 mov r0, r5 */
/* @0x180844 pop {r3, r4, r5, pc} */
/* @0x180848 bl 0x180650 <_Z21initRenderBufferStackv> */
/* @0x18084c b 0x180808 <_Z20topRenderBufferStackv+0x1c> */
/* @0x180850 mov r3, #0 */
/* @0x180854 mvn r2, #0 */
/* @0x180858 str r3, [r5] */
/* @0x18085c mov r0, r5 */
/* @0x180860 str r3, [r5, #0x4] */
/* @0x180864 str r3, [r5, #0x8] */
/* @0x180868 str r3, [r5, #0xc] */
/* @0x18086c str r3, [r5, #0x10] */
/* @0x180870 str r2, [r5, #0x14] */
/* @0x180874 str r2, [r5, #0x18] */
/* @0x180878 pop {r3, r4, r5, pc} */
/* @0x18087c eoreq pc, r6, r12, lsr sp */
/* @0x180880 ldrshteq r1, [r2], -r0 */

/* ── FUNC 0x180884 · isTextureBoundAsRenderTarget(Texture*) · size=128 · insn=32 */
/* @0x180884 cmp r0, #0 */
/* @0x180888 bxeq lr */
/* @0x18088c ldr r0, [r0, #0x18] */
/* @0x180890 cmp r0, #0 */
/* @0x180894 bxeq lr */
/* @0x180898 ldr r3, [pc, #0x5c] */
/* @0x18089c ldr r3, [pc, r3] */
/* @0x1808a0 ldrb r3, [r3] */
/* @0x1808a4 cmp r3, #0 */
/* @0x1808a8 beq 0x1808ec <_Z28isTextureBoundAsRenderTargetP7Texture+0x68> */
/* @0x1808ac ldr r2, [pc, #0x4c] */
/* @0x1808b0 add r2, pc, r2 */
/* @0x1808b4 ldr r3, [r2] */
/* @0x1808b8 cmp r3, #0 */
/* @0x1808bc blt 0x1808ec <_Z28isTextureBoundAsRenderTargetP7Texture+0x68> */
/* @0x1808c0 rsb r1, r3, r3, lsl #3 */
/* @0x1808c4 add r2, r2, #4 */
/* @0x1808c8 mov r3, #0 */
/* @0x1808cc add r1, r2, r1, lsl #2 */
/* @0x1808d0 add r2, r1, r3 */
/* @0x1808d4 add r3, r3, #4 */
/* @0x1808d8 ldr r2, [r2, #0x4] */
/* @0x1808dc cmp r0, r2 */
/* @0x1808e0 beq 0x1808f4 <_Z28isTextureBoundAsRenderTargetP7Texture+0x70> */
/* @0x1808e4 cmp r3, #16 */
/* @0x1808e8 bne 0x1808d0 <_Z28isTextureBoundAsRenderTargetP7Texture+0x4c> */
/* @0x1808ec mov r0, #0 */
/* @0x1808f0 bx lr */
/* @0x1808f4 mov r0, #1 */
/* @0x1808f8 bx lr */
/* @0x1808fc mlaeq r6, r8, r12, pc */
/* @0x180900 eorseq r1, r2, r12, asr #22 */

/* ── FUNC 0x180904 · _UpdateActiveDrawBuffers() · size=4 · insn=1 */
/* @0x180904 bx lr */

/* ── FUNC 0x180908 · bindFBO(int, int, int) · size=380 · insn=95 */
/* @0x180908 ldr r3, [pc, #0x148] */
/* @0x18090c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x180910 add r3, pc, r3 */
/* @0x180914 add r8, r3, #4 */
/* @0x180918 sub sp, sp, #20 */
/* @0x18091c ldr r9, [r3] */
/* @0x180920 mov r7, r0 */
/* @0x180924 ldr r4, [pc, #0x130] */
/* @0x180928 str r1, [sp, #0x8] */
/* @0x18092c rsb r9, r9, r9, lsl #3 */
/* @0x180930 add r4, pc, r4 */
/* @0x180934 str r2, [sp, #0xc] */
/* @0x180938 lsl r9, r9, #2 */
/* @0x18093c add r10, r8, r9 */
/* @0x180940 ldr r3, [r8, r9] */
/* @0x180944 cmp r3, #0 */
/* @0x180948 beq 0x1809d4 <_Z7bindFBOiii+0xcc> */
/* @0x18094c ldr r3, [pc, #0x10c] */
/* @0x180950 ldr r11, [r4, r3] */
/* @0x180954 ldr r3, [r11] */
/* @0x180958 cmp r3, #1 */
/* @0x18095c ble 0x1809d4 <_Z7bindFBOiii+0xcc> */
/* @0x180960 mov r6, r10 */
/* @0x180964 movw r5, #0x8ce1 */
/* @0x180968 ldr r3, [r6, #0x8] */
/* @0x18096c add r6, r6, #4 */
/* @0x180970 ldr r12, [pc, #0xec] */
/* @0x180974 cmp r3, #0 */
/* @0x180978 beq 0x1809bc <_Z7bindFBOiii+0xb4> */
/* @0x18097c ldr r12, [r4, r12] */
/* @0x180980 mov r1, r5 */
/* @0x180984 ldr lr, [pc, #0xdc] */
/* @0x180988 movw r0, #0x8d40 */
/* @0x18098c movw r2, #0xde1 */
/* @0x180990 mov r3, #0 */
/* @0x180994 ldr r12, [r12] */
/* @0x180998 cmp r12, #1 */
/* @0x18099c beq 0x180a40 <_Z7bindFBOiii+0x138> */
/* @0x1809a0 ldr r12, [r4, lr] */
/* @0x1809a4 mov lr, #0 */
/* @0x1809a8 str lr, [sp] */
/* @0x1809ac ldr r12, [r12] */
/* @0x1809b0 blx r12 */
/* @0x1809b4 mov r1, #0 */
/* @0x1809b8 str r1, [r6, #0x4] */
/* @0x1809bc sub r3, r5, #35840 */
/* @0x1809c0 ldr r2, [r11] */
/* @0x1809c4 sub r3, r3, #223 */
/* @0x1809c8 add r5, r5, #1 */
/* @0x1809cc cmp r2, r3 */
/* @0x1809d0 bgt 0x180968 <_Z7bindFBOiii+0x60> */
/* @0x1809d4 ldr r3, [pc, #0x90] */
/* @0x1809d8 mov r0, r7 */
/* @0x1809dc ldr r1, [pc, #0x8c] */
/* @0x1809e0 movw r2, #0x172 */
/* @0x1809e4 ldr r3, [r4, r3] */
/* @0x1809e8 add r1, pc, r1 */
/* @0x1809ec stm r3, {r1, r2} */
/* @0x1809f0 bl 0x1805b4 <_Z20DBG_BIND_FRAMEBUFFERi> */
/* @0x1809f4 ldr r1, [sp, #0x8] */
/* @0x1809f8 str r7, [r8, r9] */
/* @0x1809fc ldr r3, [pc, #0x70] */
/* @0x180a00 str r1, [r10, #0x14] */
/* @0x180a04 ldr r1, [sp, #0xc] */
/* @0x180a08 ldr r2, [pc, #0x68] */
/* @0x180a0c str r1, [r10, #0x18] */
/* @0x180a10 ldr r1, [r4, r3] */
/* @0x180a14 ldr r3, [pc, #0x60] */
/* @0x180a18 str r7, [r1] */
/* @0x180a1c ldr r1, [sp, #0x8] */
/* @0x180a20 ldr r2, [r4, r2] */
/* @0x180a24 str r1, [r2] */
/* @0x180a28 ldr r2, [sp, #0xc] */
/* @0x180a2c ldr r3, [r4, r3] */
/* @0x180a30 str r2, [r3] */
/* @0x180a34 add sp, sp, #20 */
/* @0x180a38 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x180a3c b 0x180904 <_Z24_UpdateActiveDrawBuffersv> */
/* @0x180a40 ldr r12, [pc, #0x38] */
/* @0x180a44 ldr r12, [r4, r12] */
/* @0x180a48 str r3, [sp] */
/* @0x180a4c ldr r12, [r12] */
/* @0x180a50 blx r12 */
/* @0x180a54 b 0x1809b4 <_Z7bindFBOiii+0xac> */
/* @0x180a58 eorseq r1, r2, r12, ror #21 */
/* @0x180a5c eoreq r1, r7, r0, lsr #6 */
/* @0x180a60 .word 0xffffe8e0 */
/* @0x180a64 .word 0xffffe7b8 */
/* @0x180a68 .word 0xffffbc7c */
/* @0x180a6c .word 0xffffe81c */
/* @0x180a70 ldrsbeq r10, [r12], -r4 */
/* @0x180a74 .word 0xffffe820 */
/* @0x180a78 .word 0xffffe834 */
/* @0x180a7c .word 0xffffe838 */
/* @0x180a80 .word 0xffffbb6c */

/* ── FUNC 0x180a84 · isSurfaceBoundAsTexture(int) · size=76 · insn=19 */
/* @0x180a84 ldr r1, [pc, #0x40] */
/* @0x180a88 ldr r1, [pc, r1] */
/* @0x180a8c sub r3, r1, #4 */
/* @0x180a90 add r1, r1, #28 */
/* @0x180a94 ldr r2, [r3, #0x4]! */
/* @0x180a98 cmp r2, #0 */
/* @0x180a9c beq 0x180ab4 <_Z23isSurfaceBoundAsTexturei+0x30> */
/* @0x180aa0 ldr r2, [r2, #0x18] */
/* @0x180aa4 cmp r2, #0 */
/* @0x180aa8 beq 0x180ab4 <_Z23isSurfaceBoundAsTexturei+0x30> */
/* @0x180aac cmp r2, r0 */
/* @0x180ab0 beq 0x180ac4 <_Z23isSurfaceBoundAsTexturei+0x40> */
/* @0x180ab4 cmp r3, r1 */
/* @0x180ab8 bne 0x180a94 <_Z23isSurfaceBoundAsTexturei+0x10> */
/* @0x180abc mov r0, #0 */
/* @0x180ac0 bx lr */
/* @0x180ac4 mov r0, #1 */
/* @0x180ac8 bx lr */
/* @0x180acc .word 0x0026fab0 */

/* ── FUNC 0x180ad0 · _IsPowerOfTwo(int) · size=28 · insn=7 */
/* @0x180ad0 cmp r0, #0 */
/* @0x180ad4 bxeq lr */
/* @0x180ad8 sub r3, r0, #1 */
/* @0x180adc tst r3, r0 */
/* @0x180ae0 movne r0, #0 */
/* @0x180ae4 moveq r0, #1 */
/* @0x180ae8 bx lr */

/* ── FUNC 0x180aec · _SetTextureNPOTFlags(Texture*) · size=60 · insn=15 */
/* @0x180aec push {r4, lr} */
/* @0x180af0 mov r4, r0 */
/* @0x180af4 ldr r0, [r0, #0x4] */
/* @0x180af8 bl 0x180ad0 <_Z13_IsPowerOfTwoi> */
/* @0x180afc cmp r0, #0 */
/* @0x180b00 bne 0x180b14 <_Z20_SetTextureNPOTFlagsP7Texture+0x28> */
/* @0x180b04 ldr r3, [r4, #0x10] */
/* @0x180b08 orr r3, r3, #4 */
/* @0x180b0c str r3, [r4, #0x10] */
/* @0x180b10 pop {r4, pc} */
/* @0x180b14 ldr r0, [r4, #0x8] */
/* @0x180b18 bl 0x180ad0 <_Z13_IsPowerOfTwoi> */
/* @0x180b1c cmp r0, #0 */
/* @0x180b20 popne {r4, pc} */
/* @0x180b24 b 0x180b04 <_Z20_SetTextureNPOTFlagsP7Texture+0x18> */

/* ── FUNC 0x180b28 · _SetCurrentTextureSettings() · size=940 · insn=235 */
/* @0x180b28 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x180b2c vpush {d8} */
/* @0x180b30 sub sp, sp, #52 */
/* @0x180b34 ldr r4, [pc, #0x344] */
/* @0x180b38 ldr r2, [pc, #0x344] */
/* @0x180b3c add r4, pc, r4 */
/* @0x180b40 ldr r3, [pc, #0x340] */
/* @0x180b44 ldr r0, [pc, #0x340] */
/* @0x180b48 ldr r6, [r4, r2] */
/* @0x180b4c ldr r2, [r4, r3] */
/* @0x180b50 ldr r1, [pc, #0x338] */
/* @0x180b54 ldr r3, [r6] */
/* @0x180b58 ldr r0, [r4, r0] */
/* @0x180b5c ldr r1, [r4, r1] */
/* @0x180b60 ldr r2, [r2, r3, lsl #2] */
/* @0x180b64 ldr r8, [r0, r3, lsl #2] */
/* @0x180b68 cmp r2, #0 */
/* @0x180b6c ldr r7, [r1, r3, lsl #2] */
/* @0x180b70 moveq r9, r2 */
/* @0x180b74 beq 0x180b8c <_Z26_SetCurrentTextureSettingsv+0x64> */
/* @0x180b78 ldr r2, [r2, #0x10] */
/* @0x180b7c tst r2, #4 */
/* @0x180b80 ubfx r9, r2, #0x5, #0x1 */
/* @0x180b84 movne r7, #1 */
/* @0x180b88 movne r8, r7 */
/* @0x180b8c ldr r2, [pc, #0x300] */
/* @0x180b90 vldr s17, [pc, #728] */
/* @0x180b94 ldr r12, [pc, #0x2fc] */
/* @0x180b98 vldr s16, [pc, #724] */
/* @0x180b9c movw r0, #0xde1 */
/* @0x180ba0 mov r1, #10240 */
/* @0x180ba4 ldr r2, [r4, r2] */
/* @0x180ba8 ldr r5, [r4, r12] */
/* @0x180bac ldr r2, [r2, r3, lsl #2] */
/* @0x180bb0 ldr r3, [r5] */
/* @0x180bb4 cmp r2, #1 */
/* @0x180bb8 vmoveq r2, s16 */
/* @0x180bbc vmovne r2, s17 */
/* @0x180bc0 blx r3 */
/* @0x180bc4 cmp r9, #0 */
/* @0x180bc8 bne 0x180c44 <_Z26_SetCurrentTextureSettingsv+0x11c> */
/* @0x180bcc ldr r2, [pc, #0x2c8] */
/* @0x180bd0 movw r0, #0xde1 */
/* @0x180bd4 ldr r12, [r6] */
/* @0x180bd8 movw r1, #0x2801 */
/* @0x180bdc ldr r3, [r5] */
/* @0x180be0 ldr r2, [r4, r2] */
/* @0x180be4 ldr r2, [r2, r12, lsl #2] */
/* @0x180be8 cmp r2, #1 */
/* @0x180bec vmoveq r2, s16 */
/* @0x180bf0 vmovne r2, s17 */
/* @0x180bf4 blx r3 */
/* @0x180bf8 cmp r8, #1 */
/* @0x180bfc vldr s17, [pc, #628] */
/* @0x180c00 vldr s16, [pc, #628] */
/* @0x180c04 ldr r3, [r5] */
/* @0x180c08 vmoveq r2, s16 */
/* @0x180c0c vmovne r2, s17 */
/* @0x180c10 movw r0, #0xde1 */
/* @0x180c14 movw r1, #0x2802 */
/* @0x180c18 blx r3 */
/* @0x180c1c cmp r7, #1 */
/* @0x180c20 ldr r3, [r5] */
/* @0x180c24 movw r0, #0xde1 */
/* @0x180c28 vmoveq r2, s16 */
/* @0x180c2c vmovne r2, s17 */
/* @0x180c30 movw r1, #0x2803 */
/* @0x180c34 blx r3 */
/* @0x180c38 add sp, sp, #52 */
/* @0x180c3c vpop {d8} */
/* @0x180c40 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x180c44 ldr r10, [pc, #0x254] */
/* @0x180c48 add r12, sp, #12 */
/* @0x180c4c ldr lr, [pc, #0x250] */
/* @0x180c50 ldr r9, [pc, #0x244] */
/* @0x180c54 ldr r10, [r4, r10] */
/* @0x180c58 add lr, pc, lr */
/* @0x180c5c ldm lr!, {r0, r1, r2, r3} */
/* @0x180c60 str r10, [sp] */
/* @0x180c64 ldr r9, [r4, r9] */
/* @0x180c68 ldr r10, [r6] */
/* @0x180c6c ldr r11, [sp] */
/* @0x180c70 str r9, [sp, #0x4] */
/* @0x180c74 stm r12!, {r0, r1, r2, r3} */
/* @0x180c78 ldr r9, [r11, r10, lsl #2] */
/* @0x180c7c ldr r11, [sp, #0x4] */
/* @0x180c80 ldm lr!, {r0, r1, r2, r3} */
/* @0x180c84 add r9, r9, r9, lsl #1 */
/* @0x180c88 ldr r10, [r11, r10, lsl #2] */
/* @0x180c8c add r9, r9, r10 */
/* @0x180c90 ldr r10, [r5] */
/* @0x180c94 stm r12!, {r0, r1, r2, r3} */
/* @0x180c98 add r1, sp, #48 */
/* @0x180c9c ldr lr, [lr] */
/* @0x180ca0 add r9, r1, r9, lsl #2 */
/* @0x180ca4 movw r0, #0xde1 */
/* @0x180ca8 movw r1, #0x2801 */
/* @0x180cac str lr, [r12] */
/* @0x180cb0 ldr r2, [r9, #-0x24] */
/* @0x180cb4 vmov s15, r2 */
/* @0x180cb8 vcvt.f32.s32 s15, s15 */
/* @0x180cbc vmov r2, s15 */
/* @0x180cc0 blx r10 */
/* @0x180cc4 ldr r3, [pc, #0x1dc] */
/* @0x180cc8 ldr r3, [r4, r3] */
/* @0x180ccc ldrb r3, [r3] */
/* @0x180cd0 cmp r3, #0 */
/* @0x180cd4 bne 0x180db0 <_Z26_SetCurrentTextureSettingsv+0x288> */
/* @0x180cd8 ldr r3, [pc, #0x1cc] */
/* @0x180cdc ldr r3, [r4, r3] */
/* @0x180ce0 ldrb r3, [r3] */
/* @0x180ce4 cmp r3, #0 */
/* @0x180ce8 bne 0x180e48 <_Z26_SetCurrentTextureSettingsv+0x320> */
/* @0x180cec ldr r3, [pc, #0x1bc] */
/* @0x180cf0 ldr r3, [r4, r3] */
/* @0x180cf4 ldrb r3, [r3] */
/* @0x180cf8 cmp r3, #0 */
/* @0x180cfc beq 0x180d50 <_Z26_SetCurrentTextureSettingsv+0x228> */
/* @0x180d00 ldr r3, [r6] */
/* @0x180d04 ldr r11, [sp] */
/* @0x180d08 ldr r2, [r11, r3, lsl #2] */
/* @0x180d0c cmp r2, #2 */
/* @0x180d10 bne 0x180e30 <_Z26_SetCurrentTextureSettingsv+0x308> */
/* @0x180d14 ldr r2, [pc, #0x198] */
/* @0x180d18 movw r0, #0xde1 */
/* @0x180d1c ldr lr, [pc, #0x194] */
/* @0x180d20 movw r1, #0x84fe */
/* @0x180d24 ldr r12, [r5] */
/* @0x180d28 ldr r2, [r4, r2] */
/* @0x180d2c ldr lr, [r4, lr] */
/* @0x180d30 ldr r2, [r2, r3, lsl #2] */
/* @0x180d34 ldr r3, [lr] */
/* @0x180d38 cmp r2, r3 */
/* @0x180d3c movge r2, r3 */
/* @0x180d40 vmov s15, r2 */
/* @0x180d44 vcvt.f32.s32 s15, s15 */
/* @0x180d48 vmov r2, s15 */
/* @0x180d4c blx r12 */
/* @0x180d50 ldr r3, [pc, #0x164] */
/* @0x180d54 ldr r3, [r4, r3] */
/* @0x180d58 ldrb r3, [r3] */
/* @0x180d5c cmp r3, #0 */
/* @0x180d60 beq 0x180bf8 <_Z26_SetCurrentTextureSettingsv+0xd0> */
/* @0x180d64 ldr r2, [pc, #0x154] */
/* @0x180d68 movw r0, #0xde1 */
/* @0x180d6c ldr r12, [r6] */
/* @0x180d70 movw r1, #0x813a */
/* @0x180d74 ldr r3, [r5] */
/* @0x180d78 ldr r2, [r4, r2] */
/* @0x180d7c add r2, r2, r12, lsl #2 */
/* @0x180d80 ldr r2, [r2] */
/* @0x180d84 blx r3 */
/* @0x180d88 ldr r2, [pc, #0x134] */
/* @0x180d8c ldr r12, [r6] */
/* @0x180d90 movw r0, #0xde1 */
/* @0x180d94 ldr r3, [r5] */
/* @0x180d98 movw r1, #0x813b */
/* @0x180d9c ldr r2, [r4, r2] */
/* @0x180da0 add r2, r2, r12, lsl #2 */
/* @0x180da4 ldr r2, [r2] */
/* @0x180da8 blx r3 */
/* @0x180dac b 0x180bf8 <_Z26_SetCurrentTextureSettingsv+0xd0> */
/* @0x180db0 ldr r1, [pc, #0x110] */
/* @0x180db4 ldr r3, [pc, #0x110] */
/* @0x180db8 ldr r2, [r6] */
/* @0x180dbc ldr r1, [r4, r1] */
/* @0x180dc0 vldr s15, [r1] */
/* @0x180dc4 vneg.f32 s14, s15 */
/* @0x180dc8 ldr r3, [r4, r3] */
/* @0x180dcc add r3, r3, r2, lsl #2 */
/* @0x180dd0 vldr s13, [r3] */
/* @0x180dd4 vcmpe.f32 s13, s14 */
/* @0x180dd8 vmrs APSR_nzcv, fpscr */
/* @0x180ddc ble 0x180e10 <_Z26_SetCurrentTextureSettingsv+0x2e8> */
/* @0x180de0 vcmpe.f32 s13, s15 */
/* @0x180de4 vmrs APSR_nzcv, fpscr */
/* @0x180de8 bpl 0x180df0 <_Z26_SetCurrentTextureSettingsv+0x2c8> */
/* @0x180dec vmov.f32 s15, s13 */
/* @0x180df0 ldr r3, [pc, #0xd8] */
/* @0x180df4 mov r0, #34048 */
/* @0x180df8 movw r1, #0x8501 */
/* @0x180dfc vmov r2, s15 */
/* @0x180e00 ldr r3, [r4, r3] */
/* @0x180e04 ldr r3, [r3] */
/* @0x180e08 blx r3 */
/* @0x180e0c b 0x180cec <_Z26_SetCurrentTextureSettingsv+0x1c4> */
/* @0x180e10 vcmpe.f32 s15, s14 */
/* @0x180e14 vmrs APSR_nzcv, fpscr */
/* @0x180e18 ble 0x180df0 <_Z26_SetCurrentTextureSettingsv+0x2c8> */
/* @0x180e1c vcmpe.f32 s13, s14 */
/* @0x180e20 vmrs APSR_nzcv, fpscr */
/* @0x180e24 vmovle.f32 s15, s14 */
/* @0x180e28 ble 0x180df0 <_Z26_SetCurrentTextureSettingsv+0x2c8> */
/* @0x180e2c b 0x180dec <_Z26_SetCurrentTextureSettingsv+0x2c4> */
/* @0x180e30 ldr r3, [r5] */
/* @0x180e34 movw r0, #0xde1 */
/* @0x180e38 movw r1, #0x84fe */
/* @0x180e3c mov r2, #1065353216 */
/* @0x180e40 blx r3 */
/* @0x180e44 b 0x180d50 <_Z26_SetCurrentTextureSettingsv+0x228> */
/* @0x180e48 ldr r2, [pc, #0x7c] */
/* @0x180e4c movw r0, #0xde1 */
/* @0x180e50 ldr r12, [r6] */
/* @0x180e54 movw r1, #0x8501 */
/* @0x180e58 ldr r3, [r5] */
/* @0x180e5c ldr r2, [r4, r2] */
/* @0x180e60 add r2, r2, r12, lsl #2 */
/* @0x180e64 ldr r2, [r2] */
/* @0x180e68 blx r3 */
/* @0x180e6c b 0x180cec <_Z26_SetCurrentTextureSettingsv+0x1c4> */
/* @0x180e70 ldrmi r0, [r8], -r0 */
/* @0x180e74 ldrmi r0, [r8], -r0, lsl #8 */
/* @0x180e78 strtmi r0, [r4], -r0, lsl #8 */
/* @0x180e7c strmi r2, [r1, -r0, lsl #30] */
/* @0x180e80 eoreq r1, r7, r4, lsl r1 */
/* @0x180e84 .word 0xffffe808 */
/* @0x180e88 .word 0xffffe8e8 */
/* @0x180e8c .word 0xffffe8c8 */
/* @0x180e90 .word 0xffffe8cc */
/* @0x180e94 .word 0xffffe8bc */
/* @0x180e98 .word 0xffffbb1c */
/* @0x180e9c .word 0xffffe8c4 */
/* @0x180ea0 .word 0xffffe8d0 */
/* @0x180ea4 andseq r12, sp, r0, ror #30 */
/* @0x180ea8 .word 0xffffe7e8 */
/* @0x180eac .word 0xffffe8ec */
/* @0x180eb0 .word 0xffffe7d0 */
/* @0x180eb4 .word 0xffffe8c0 */
/* @0x180eb8 .word 0xffffe7d4 */
/* @0x180ebc .word 0xffffe8f0 */
/* @0x180ec0 .word 0xffffe8d4 */
/* @0x180ec4 .word 0xffffe8d8 */
/* @0x180ec8 .word 0xffffe7e4 */
/* @0x180ecc .word 0xffffe8dc */
/* @0x180ed0 .word 0xffffbca4 */

/* ── FUNC 0x180ed4 · UpdateCurrentTextureSettings(int) · size=196 · insn=49 */
/* @0x180ed4 push {r4, r5, r6, lr} */
/* @0x180ed8 mov r6, r0 */
/* @0x180edc ldr r4, [pc, #0x9c] */
/* @0x180ee0 ldr r3, [pc, #0x9c] */
/* @0x180ee4 add r4, pc, r4 */
/* @0x180ee8 ldr r5, [r4, r3] */
/* @0x180eec ldr r3, [r5] */
/* @0x180ef0 cmp r3, #0 */
/* @0x180ef4 bne 0x180f28 <_Z28UpdateCurrentTextureSettingsi+0x54> */
/* @0x180ef8 ldr r3, [pc, #0x88] */
/* @0x180efc ldr r3, [r4, r3] */
/* @0x180f00 ldr r3, [r3] */
/* @0x180f04 cmp r3, #0 */
/* @0x180f08 popeq {r4, r5, r6, pc} */
/* @0x180f0c ldr r3, [pc, #0x78] */
/* @0x180f10 ldr r3, [r4, r3] */
/* @0x180f14 ldr r3, [r3] */
/* @0x180f18 cmp r3, #0 */
/* @0x180f1c popeq {r4, r5, r6, pc} */
/* @0x180f20 bl 0x180b28 <_Z26_SetCurrentTextureSettingsv> */
/* @0x180f24 ldr r3, [r5] */
/* @0x180f28 cmp r3, #1 */
/* @0x180f2c popne {r4, r5, r6, pc} */
/* @0x180f30 ldr r3, [pc, #0x58] */
/* @0x180f34 ldr r5, [r4, r3] */
/* @0x180f38 ldr r3, [r5] */
/* @0x180f3c cmp r3, r6 */
/* @0x180f40 beq 0x180f64 <_Z28UpdateCurrentTextureSettingsi+0x90> */
/* @0x180f44 ldr r3, [pc, #0x48] */
/* @0x180f48 add r0, r6, #33792 */
/* @0x180f4c str r6, [r5] */
/* @0x180f50 add r0, r0, #192 */
/* @0x180f54 ldr r3, [r4, r3] */
/* @0x180f58 ldr r3, [r3] */
/* @0x180f5c blx r3 */
/* @0x180f60 ldr r6, [r5] */
/* @0x180f64 ldr r3, [pc, #0x1c] */
/* @0x180f68 ldr r3, [r4, r3] */
/* @0x180f6c ldr r3, [r3, r6, lsl #2] */
/* @0x180f70 cmp r3, #0 */
/* @0x180f74 popeq {r4, r5, r6, pc} */
/* @0x180f78 pop {r4, r5, r6, lr} */
/* @0x180f7c b 0x180b28 <_Z26_SetCurrentTextureSettingsv> */
/* @0x180f80 eoreq r0, r7, r12, ror #26 */
/* @0x180f84 .word 0xffffe7b8 */
/* @0x180f88 .word 0xffffe8e8 */
/* @0x180f8c .word 0xffffe8f4 */
/* @0x180f90 .word 0xffffe808 */
/* @0x180f94 .word 0xffffbbf0 */

/* ── FUNC 0x180f98 · Graphics::FreeTexture(void*) · size=504 · insn=126 */
/* @0x180f98 push {r3, r4, r5, lr} */
/* @0x180f9c mov r4, r0 */
/* @0x180fa0 ldr r5, [pc, #0x1c4] */
/* @0x180fa4 ldr r3, [pc, #0x1c4] */
/* @0x180fa8 add r5, pc, r5 */
/* @0x180fac ldr r3, [r5, r3] */
/* @0x180fb0 ldr r2, [r3] */
/* @0x180fb4 cmp r0, r2 */
/* @0x180fb8 moveq r2, #0 */
/* @0x180fbc streq r2, [r3] */
/* @0x180fc0 ldr r3, [r0, #0x14] */
/* @0x180fc4 cmn r3, #1 */
/* @0x180fc8 beq 0x180fec <_ZN8Graphics11FreeTextureEPv+0x54> */
/* @0x180fcc ldr r3, [pc, #0x1a0] */
/* @0x180fd0 mov r0, #1 */
/* @0x180fd4 add r1, r4, #20 */
/* @0x180fd8 ldr r3, [r5, r3] */
/* @0x180fdc ldr r3, [r3] */
/* @0x180fe0 blx r3 */
/* @0x180fe4 mvn r3, #0 */
/* @0x180fe8 str r3, [r4, #0x14] */
/* @0x180fec ldr r3, [r4, #0x18] */
/* @0x180ff0 cmn r3, #1 */
/* @0x180ff4 beq 0x18102c <_ZN8Graphics11FreeTextureEPv+0x94> */
/* @0x180ff8 ldr r3, [pc, #0x178] */
/* @0x180ffc ldr r3, [r5, r3] */
/* @0x181000 ldr r0, [r3] */
/* @0x181004 cmp r0, #1 */
/* @0x181008 beq 0x181154 <_ZN8Graphics11FreeTextureEPv+0x1bc> */
/* @0x18100c ldr r3, [pc, #0x168] */
/* @0x181010 mov r0, #1 */
/* @0x181014 add r1, r4, #24 */
/* @0x181018 ldr r3, [r5, r3] */
/* @0x18101c ldr r3, [r3] */
/* @0x181020 blx r3 */
/* @0x181024 mvn r3, #0 */
/* @0x181028 str r3, [r4, #0x18] */
/* @0x18102c ldr r3, [r4, #0x1c] */
/* @0x181030 cmn r3, #1 */
/* @0x181034 beq 0x18106c <_ZN8Graphics11FreeTextureEPv+0xd4> */
/* @0x181038 ldr r3, [pc, #0x138] */
/* @0x18103c ldr r3, [r5, r3] */
/* @0x181040 ldr r0, [r3] */
/* @0x181044 cmp r0, #1 */
/* @0x181048 beq 0x18113c <_ZN8Graphics11FreeTextureEPv+0x1a4> */
/* @0x18104c ldr r3, [pc, #0x12c] */
/* @0x181050 mov r0, #1 */
/* @0x181054 add r1, r4, #28 */
/* @0x181058 ldr r3, [r5, r3] */
/* @0x18105c ldr r3, [r3] */
/* @0x181060 blx r3 */
/* @0x181064 mvn r3, #0 */
/* @0x181068 str r3, [r4, #0x1c] */
/* @0x18106c ldr r3, [r4, #0x20] */
/* @0x181070 cmn r3, #1 */
/* @0x181074 beq 0x1810ac <_ZN8Graphics11FreeTextureEPv+0x114> */
/* @0x181078 ldr r3, [pc, #0xf8] */
/* @0x18107c ldr r3, [r5, r3] */
/* @0x181080 ldr r0, [r3] */
/* @0x181084 cmp r0, #1 */
/* @0x181088 beq 0x181124 <_ZN8Graphics11FreeTextureEPv+0x18c> */
/* @0x18108c ldr r3, [pc, #0xec] */
/* @0x181090 mov r0, #1 */
/* @0x181094 add r1, r4, #32 */
/* @0x181098 ldr r3, [r5, r3] */
/* @0x18109c ldr r3, [r3] */
/* @0x1810a0 blx r3 */
/* @0x1810a4 mvn r3, #0 */
/* @0x1810a8 str r3, [r4, #0x20] */
/* @0x1810ac ldr r0, [r4, #0x24] */
/* @0x1810b0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1810b4 ldr r2, [pc, #0xc8] */
/* @0x1810b8 mov r3, #0 */
/* @0x1810bc str r3, [r4, #0x2c] */
/* @0x1810c0 str r3, [r4, #0x24] */
/* @0x1810c4 ldr r0, [r5, r2] */
/* @0x1810c8 ldr r1, [r0] */
/* @0x1810cc cmp r1, #0 */
/* @0x1810d0 beq 0x181100 <_ZN8Graphics11FreeTextureEPv+0x168> */
/* @0x1810d4 cmp r4, r1 */
/* @0x1810d8 ldr r3, [r1, #0x34] */
/* @0x1810dc bne 0x1810f8 <_ZN8Graphics11FreeTextureEPv+0x160> */
/* @0x1810e0 b 0x18111c <_ZN8Graphics11FreeTextureEPv+0x184> */
/* @0x1810e4 cmp r4, r3 */
/* @0x1810e8 ldr r2, [r3, #0x34] */
/* @0x1810ec beq 0x18110c <_ZN8Graphics11FreeTextureEPv+0x174> */
/* @0x1810f0 mov r1, r3 */
/* @0x1810f4 mov r3, r2 */
/* @0x1810f8 cmp r3, #0 */
/* @0x1810fc bne 0x1810e4 <_ZN8Graphics11FreeTextureEPv+0x14c> */
/* @0x181100 mov r0, r4 */
/* @0x181104 pop {r3, r4, r5, lr} */
/* @0x181108 b 0x27d1d0 <_ZdlPv> */
/* @0x18110c cmp r1, #0 */
/* @0x181110 strne r2, [r1, #0x34] */
/* @0x181114 bne 0x181100 <_ZN8Graphics11FreeTextureEPv+0x168> */
/* @0x181118 mov r3, r2 */
/* @0x18111c str r3, [r0] */
/* @0x181120 b 0x181100 <_ZN8Graphics11FreeTextureEPv+0x168> */
/* @0x181124 ldr r3, [pc, #0x5c] */
/* @0x181128 add r1, r4, #32 */
/* @0x18112c ldr r3, [r5, r3] */
/* @0x181130 ldr r3, [r3] */
/* @0x181134 blx r3 */
/* @0x181138 b 0x1810a4 <_ZN8Graphics11FreeTextureEPv+0x10c> */
/* @0x18113c ldr r3, [pc, #0x44] */
/* @0x181140 add r1, r4, #28 */
/* @0x181144 ldr r3, [r5, r3] */
/* @0x181148 ldr r3, [r3] */
/* @0x18114c blx r3 */
/* @0x181150 b 0x181064 <_ZN8Graphics11FreeTextureEPv+0xcc> */
/* @0x181154 ldr r3, [pc, #0x30] */
/* @0x181158 add r1, r4, #24 */
/* @0x18115c ldr r3, [r5, r3] */
/* @0x181160 ldr r3, [r3] */
/* @0x181164 blx r3 */
/* @0x181168 b 0x181024 <_ZN8Graphics11FreeTextureEPv+0x8c> */
/* @0x18116c eoreq r0, r7, r8, lsr #25 */
/* @0x181170 .word 0xffffe8f8 */
/* @0x181174 .word 0xffffbb24 */
/* @0x181178 .word 0xffffe7b8 */
/* @0x18117c .word 0xffffbc80 */
/* @0x181180 .word 0xffffbcbc */
/* @0x181184 .word 0xffffe664 */
/* @0x181188 .word 0xffffbc0c */
/* @0x18118c .word 0xffffbb70 */

/* ── FUNC 0x181190 · FreeTextureResources() · size=44 · insn=11 */
/* @0x181190 push {r4, lr} */
/* @0x181194 ldr r4, [pc, #0x1c] */
/* @0x181198 ldr r4, [pc, r4] */
/* @0x18119c ldr r0, [r4] */
/* @0x1811a0 cmp r0, #0 */
/* @0x1811a4 popeq {r4, pc} */
/* @0x1811a8 bl 0x180f98 <_ZN8Graphics11FreeTextureEPv> */
/* @0x1811ac mov r3, #0 */
/* @0x1811b0 str r3, [r4] */
/* @0x1811b4 pop {r4, pc} */
/* @0x1811b8 .word 0x0026f3b4 */

/* ── FUNC 0x1811bc · Graphics::FlushTexture(void*) · size=356 · insn=89 */
/* @0x1811bc push {r3, r4, r5, lr} */
/* @0x1811c0 mov r4, r0 */
/* @0x1811c4 ldr r3, [r0, #0x14] */
/* @0x1811c8 ldr r5, [pc, #0x134] */
/* @0x1811cc cmn r3, #1 */
/* @0x1811d0 add r5, pc, r5 */
/* @0x1811d4 beq 0x1811f8 <_ZN8Graphics12FlushTextureEPv+0x3c> */
/* @0x1811d8 ldr r3, [pc, #0x128] */
/* @0x1811dc mov r0, #1 */
/* @0x1811e0 add r1, r4, #20 */
/* @0x1811e4 ldr r3, [r5, r3] */
/* @0x1811e8 ldr r3, [r3] */
/* @0x1811ec blx r3 */
/* @0x1811f0 mvn r3, #0 */
/* @0x1811f4 str r3, [r4, #0x14] */
/* @0x1811f8 ldr r3, [r4, #0x18] */
/* @0x1811fc cmn r3, #1 */
/* @0x181200 beq 0x181238 <_ZN8Graphics12FlushTextureEPv+0x7c> */
/* @0x181204 ldr r3, [pc, #0x100] */
/* @0x181208 ldr r3, [r5, r3] */
/* @0x18120c ldr r0, [r3] */
/* @0x181210 cmp r0, #1 */
/* @0x181214 beq 0x1812ec <_ZN8Graphics12FlushTextureEPv+0x130> */
/* @0x181218 ldr r3, [pc, #0xf0] */
/* @0x18121c mov r0, #1 */
/* @0x181220 add r1, r4, #24 */
/* @0x181224 ldr r3, [r5, r3] */
/* @0x181228 ldr r3, [r3] */
/* @0x18122c blx r3 */
/* @0x181230 mvn r3, #0 */
/* @0x181234 str r3, [r4, #0x18] */
/* @0x181238 ldr r3, [r4, #0x1c] */
/* @0x18123c cmn r3, #1 */
/* @0x181240 beq 0x181278 <_ZN8Graphics12FlushTextureEPv+0xbc> */
/* @0x181244 ldr r3, [pc, #0xc0] */
/* @0x181248 ldr r3, [r5, r3] */
/* @0x18124c ldr r0, [r3] */
/* @0x181250 cmp r0, #1 */
/* @0x181254 beq 0x1812d4 <_ZN8Graphics12FlushTextureEPv+0x118> */
/* @0x181258 ldr r3, [pc, #0xb4] */
/* @0x18125c mov r0, #1 */
/* @0x181260 add r1, r4, #28 */
/* @0x181264 ldr r3, [r5, r3] */
/* @0x181268 ldr r3, [r3] */
/* @0x18126c blx r3 */
/* @0x181270 mvn r3, #0 */
/* @0x181274 str r3, [r4, #0x1c] */
/* @0x181278 ldr r3, [r4, #0x20] */
/* @0x18127c cmn r3, #1 */
/* @0x181280 popeq {r3, r4, r5, pc} */
/* @0x181284 ldr r3, [pc, #0x80] */
/* @0x181288 ldr r3, [r5, r3] */
/* @0x18128c ldr r0, [r3] */
/* @0x181290 cmp r0, #1 */
/* @0x181294 beq 0x1812bc <_ZN8Graphics12FlushTextureEPv+0x100> */
/* @0x181298 ldr r3, [pc, #0x74] */
/* @0x18129c mov r0, #1 */
/* @0x1812a0 add r1, r4, #32 */
/* @0x1812a4 ldr r3, [r5, r3] */
/* @0x1812a8 ldr r3, [r3] */
/* @0x1812ac blx r3 */
/* @0x1812b0 mvn r3, #0 */
/* @0x1812b4 str r3, [r4, #0x20] */
/* @0x1812b8 pop {r3, r4, r5, pc} */
/* @0x1812bc ldr r3, [pc, #0x54] */
/* @0x1812c0 add r1, r4, #32 */
/* @0x1812c4 ldr r3, [r5, r3] */
/* @0x1812c8 ldr r3, [r3] */
/* @0x1812cc blx r3 */
/* @0x1812d0 b 0x1812b0 <_ZN8Graphics12FlushTextureEPv+0xf4> */
/* @0x1812d4 ldr r3, [pc, #0x3c] */
/* @0x1812d8 add r1, r4, #28 */
/* @0x1812dc ldr r3, [r5, r3] */
/* @0x1812e0 ldr r3, [r3] */
/* @0x1812e4 blx r3 */
/* @0x1812e8 b 0x181270 <_ZN8Graphics12FlushTextureEPv+0xb4> */
/* @0x1812ec ldr r3, [pc, #0x28] */
/* @0x1812f0 add r1, r4, #24 */
/* @0x1812f4 ldr r3, [r5, r3] */
/* @0x1812f8 ldr r3, [r3] */
/* @0x1812fc blx r3 */
/* @0x181300 b 0x181230 <_ZN8Graphics12FlushTextureEPv+0x74> */
/* @0x181304 eoreq r0, r7, r0, lsl #21 */
/* @0x181308 .word 0xffffbb24 */
/* @0x18130c .word 0xffffe7b8 */
/* @0x181310 .word 0xffffbc80 */
/* @0x181314 .word 0xffffbcbc */
/* @0x181318 .word 0xffffbc0c */
/* @0x18131c .word 0xffffbb70 */

/* ── FUNC 0x181320 · GetPOW2Size(int) · size=84 · insn=21 */
/* @0x181320 ldr r3, [pc, #0x48] */
/* @0x181324 ldr r3, [pc, r3] */
/* @0x181328 ldr r2, [r3] */
/* @0x18132c cmp r2, #0 */
/* @0x181330 ble 0x181358 <_Z11GetPOW2Sizei+0x38> */
/* @0x181334 cmp r0, #1 */
/* @0x181338 ble 0x181368 <_Z11GetPOW2Sizei+0x48> */
/* @0x18133c mov r3, #1 */
/* @0x181340 b 0x18134c <_Z11GetPOW2Sizei+0x2c> */
/* @0x181344 cmp r0, r3 */
/* @0x181348 ble 0x181360 <_Z11GetPOW2Sizei+0x40> */
/* @0x18134c lsl r3, r3, #1 */
/* @0x181350 cmp r3, r2 */
/* @0x181354 ble 0x181344 <_Z11GetPOW2Sizei+0x24> */
/* @0x181358 mov r0, r2 */
/* @0x18135c bx lr */
/* @0x181360 mov r0, r3 */
/* @0x181364 bx lr */
/* @0x181368 mov r0, #1 */
/* @0x18136c bx lr */
/* @0x181370 eoreq pc, r6, r12, ror #1 */

/* ── FUNC 0x181374 · Graphics::GetMaxTextureSize() · size=20 · insn=5 */
/* @0x181374 ldr r3, [pc, #0x8] */
/* @0x181378 ldr r3, [pc, r3] */
/* @0x18137c ldr r0, [r3] */
/* @0x181380 bx lr */
/* @0x181384 mlaeq r6, r8, r0, pc */

/* ── FUNC 0x181388 · ScaleTexture(int, int, unsigned int*, int, int, unsigned int*) · size=280 · insn=70 */
/* @0x181388 ldr r12, [pc, #0x108] */
/* @0x18138c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x181390 ldr r12, [pc, r12] */
/* @0x181394 mov r9, r0 */
/* @0x181398 sub sp, sp, #36 */
/* @0x18139c ldr r0, [r12] */
/* @0x1813a0 mov r10, r3 */
/* @0x1813a4 ldr r5, [sp, #0x48] */
/* @0x1813a8 mov r3, r1 */
/* @0x1813ac ldr lr, [sp, #0x4c] */
/* @0x1813b0 mov r4, r2 */
/* @0x1813b4 ldr r12, [r0] */
/* @0x1813b8 mov r2, r9 */
/* @0x1813bc str r1, [sp, #0x1c] */
/* @0x1813c0 ldr r1, [pc, #0xd4] */
/* @0x1813c4 str lr, [sp, #0xc] */
/* @0x1813c8 add r1, pc, r1 */
/* @0x1813cc stm sp, {r4, r10} */
/* @0x1813d0 str r5, [sp, #0x8] */
/* @0x1813d4 ldr r12, [r12, #0xc] */
/* @0x1813d8 blx r12 */
/* @0x1813dc lsl r0, r5, #16 */
/* @0x1813e0 ldr r1, [sp, #0x1c] */
/* @0x1813e4 bl 0x318d10 <__divsi3> */
/* @0x1813e8 ldr r12, [sp, #0x1c] */
/* @0x1813ec cmp r12, #0 */
/* @0x1813f0 str r0, [sp, #0x14] */
/* @0x1813f4 ble 0x18147c <_Z12ScaleTextureiiPjiiS_+0xf4> */
/* @0x1813f8 mov r1, r9 */
/* @0x1813fc lsl r0, r10, #16 */
/* @0x181400 bl 0x318d10 <__divsi3> */
/* @0x181404 ldr r1, [sp, #0x1c] */
/* @0x181408 mov r3, #0 */
/* @0x18140c lsl r11, r9, #2 */
/* @0x181410 mov r2, r4 */
/* @0x181414 mov r8, r3 */
/* @0x181418 mul r1, r1, r9 */
/* @0x18141c str r1, [sp, #0x18] */
/* @0x181420 mov r1, r3 */
/* @0x181424 asr r6, r8, #16 */
/* @0x181428 ldr r12, [sp, #0x4c] */
/* @0x18142c cmp r9, #0 */
/* @0x181430 mul r6, r10, r6 */
/* @0x181434 add r6, r12, r6, lsl #2 */
/* @0x181438 ble 0x181464 <_Z12ScaleTextureiiPjiiS_+0xdc> */
/* @0x18143c add r7, r11, r2 */
/* @0x181440 mov r4, r2 */
/* @0x181444 mov r12, #0 */
/* @0x181448 asr r5, r12, #16 */
/* @0x18144c add r12, r12, r0 */
/* @0x181450 ldr r5, [r6, r5, lsl #2] */
/* @0x181454 str r5, [r4], #4 */
/* @0x181458 cmp r7, r4 */
/* @0x18145c bne 0x181448 <_Z12ScaleTextureiiPjiiS_+0xc0> */
/* @0x181460 add r3, r3, r9 */
/* @0x181464 ldr r12, [sp, #0x18] */
/* @0x181468 add r1, r1, #1 */
/* @0x18146c cmp r12, r3 */
/* @0x181470 ldr r12, [sp, #0x14] */
/* @0x181474 add r8, r8, r12 */
/* @0x181478 bge 0x181484 <_Z12ScaleTextureiiPjiiS_+0xfc> */
/* @0x18147c add sp, sp, #36 */
/* @0x181480 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x181484 ldr r12, [sp, #0x1c] */
/* @0x181488 add r2, r2, r11 */
/* @0x18148c cmp r12, r1 */
/* @0x181490 bgt 0x181424 <_Z12ScaleTextureiiPjiiS_+0x9c> */
/* @0x181494 b 0x18147c <_Z12ScaleTextureiiPjiiS_+0xf4> */
/* @0x181498 eoreq r12, r6, r4, lsl #7 */
/* @0x18149c andseq r10, r12, r12, lsr r6 */

/* ── FUNC 0x1814a0 · _SetupRenderTargetFBO(Texture*, int, int) · size=1720 · insn=430 */
/* @0x1814a0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1814a4 subs r5, r0, #0 */
/* @0x1814a8 ldr r4, [pc, #0x608] */
/* @0x1814ac sub sp, sp, #20 */
/* @0x1814b0 mov r8, r1 */
/* @0x1814b4 mov r7, r2 */
/* @0x1814b8 add r4, pc, r4 */
/* @0x1814bc beq 0x181868 <_Z21_SetupRenderTargetFBOP7Textureii+0x3c8> */
/* @0x1814c0 ldr r1, [r5, #0x14] */
/* @0x1814c4 cmn r1, #1 */
/* @0x1814c8 beq 0x181868 <_Z21_SetupRenderTargetFBOP7Textureii+0x3c8> */
/* @0x1814cc ldr r3, [pc, #0x5e8] */
/* @0x1814d0 movw r0, #0xde1 */
/* @0x1814d4 ldr r3, [r4, r3] */
/* @0x1814d8 ldr r3, [r3] */
/* @0x1814dc blx r3 */
/* @0x1814e0 ldr r3, [pc, #0x5d8] */
/* @0x1814e4 movw r0, #0xde1 */
/* @0x1814e8 movw r1, #0x2801 */
/* @0x1814ec mov r2, #1024 */
/* @0x1814f0 movt r2, #0x4618 */
/* @0x1814f4 ldr r6, [r4, r3] */
/* @0x1814f8 ldr r3, [r6] */
/* @0x1814fc blx r3 */
/* @0x181500 ldr r3, [r6] */
/* @0x181504 movw r0, #0xde1 */
/* @0x181508 mov r1, #10240 */
/* @0x18150c mov r2, #1024 */
/* @0x181510 movt r2, #0x4618 */
/* @0x181514 blx r3 */
/* @0x181518 ldr r3, [r6] */
/* @0x18151c movw r0, #0xde1 */
/* @0x181520 movw r1, #0x2802 */
/* @0x181524 mov r2, #12032 */
/* @0x181528 movt r2, #0x4701 */
/* @0x18152c blx r3 */
/* @0x181530 ldr r3, [r6] */
/* @0x181534 movw r0, #0xde1 */
/* @0x181538 movw r1, #0x2803 */
/* @0x18153c mov r2, #12032 */
/* @0x181540 movt r2, #0x4701 */
/* @0x181544 blx r3 */
/* @0x181548 ldr r3, [pc, #0x574] */
/* @0x18154c ldr r6, [r4, r3] */
/* @0x181550 ldr r0, [r6] */
/* @0x181554 cmp r0, #1 */
/* @0x181558 beq 0x1819ec <_Z21_SetupRenderTargetFBOP7Textureii+0x54c> */
/* @0x18155c ldr r3, [pc, #0x564] */
/* @0x181560 mov r0, #1 */
/* @0x181564 add r1, r5, #24 */
/* @0x181568 ldr r3, [r4, r3] */
/* @0x18156c ldr r3, [r3] */
/* @0x181570 blx r3 */
/* @0x181574 ldr r1, [pc, #0x550] */
/* @0x181578 movw r3, #0x443 */
/* @0x18157c ldr r2, [pc, #0x54c] */
/* @0x181580 ldr r0, [r5, #0x18] */
/* @0x181584 ldr r9, [r4, r1] */
/* @0x181588 add r2, pc, r2 */
/* @0x18158c stm r9, {r2, r3} */
/* @0x181590 bl 0x1805b4 <_Z20DBG_BIND_FRAMEBUFFERi> */
/* @0x181594 ldr r3, [r6] */
/* @0x181598 ldr r12, [pc, #0x534] */
/* @0x18159c cmp r3, #1 */
/* @0x1815a0 ldrne r12, [pc, #0x530] */
/* @0x1815a4 ldr r12, [r4, r12] */
/* @0x1815a8 mov lr, #0 */
/* @0x1815ac ldr r3, [r5, #0x14] */
/* @0x1815b0 movw r0, #0x8d40 */
/* @0x1815b4 str lr, [sp] */
/* @0x1815b8 movw r1, #0x8ce0 */
/* @0x1815bc movw r2, #0xde1 */
/* @0x1815c0 ldr r12, [r12] */
/* @0x1815c4 blx r12 */
/* @0x1815c8 ldr r0, [r6] */
/* @0x1815cc cmp r0, #1 */
/* @0x1815d0 beq 0x181a38 <_Z21_SetupRenderTargetFBOP7Textureii+0x598> */
/* @0x1815d4 ldr r3, [pc, #0x500] */
/* @0x1815d8 mov r0, #1 */
/* @0x1815dc add r1, r5, #28 */
/* @0x1815e0 ldr r3, [r4, r3] */
/* @0x1815e4 ldr r3, [r3] */
/* @0x1815e8 blx r3 */
/* @0x1815ec ldr r3, [r6] */
/* @0x1815f0 cmp r3, #1 */
/* @0x1815f4 beq 0x181a30 <_Z21_SetupRenderTargetFBOP7Textureii+0x590> */
/* @0x1815f8 ldr r3, [pc, #0x4e0] */
/* @0x1815fc ldr r3, [r4, r3] */
/* @0x181600 movw r0, #0x8d41 */
/* @0x181604 ldr r1, [r5, #0x1c] */
/* @0x181608 ldr r3, [r3] */
/* @0x18160c blx r3 */
/* @0x181610 ldr r3, [pc, #0x4cc] */
/* @0x181614 ldr r3, [r4, r3] */
/* @0x181618 ldrb r3, [r3] */
/* @0x18161c cmp r3, #0 */
/* @0x181620 ldr r3, [r6] */
/* @0x181624 beq 0x181870 <_Z21_SetupRenderTargetFBOP7Textureii+0x3d0> */
/* @0x181628 cmp r3, #1 */
/* @0x18162c ldr r12, [pc, #0x4b4] */
/* @0x181630 ldrne r12, [pc, #0x4b4] */
/* @0x181634 ldr r12, [r4, r12] */
/* @0x181638 mov r3, r7 */
/* @0x18163c movw r0, #0x8d41 */
/* @0x181640 movw r1, #0x88f0 */
/* @0x181644 mov r2, r8 */
/* @0x181648 ldr r12, [r12] */
/* @0x18164c blx r12 */
/* @0x181650 ldr r3, [r6] */
/* @0x181654 cmp r3, #1 */
/* @0x181658 beq 0x181a68 <_Z21_SetupRenderTargetFBOP7Textureii+0x5c8> */
/* @0x18165c ldr r3, [pc, #0x47c] */
/* @0x181660 ldr r3, [r4, r3] */
/* @0x181664 movw r0, #0x8d41 */
/* @0x181668 mov r1, #0 */
/* @0x18166c ldr r3, [r3] */
/* @0x181670 blx r3 */
/* @0x181674 ldr r3, [pc, #0x474] */
/* @0x181678 ldr r3, [r4, r3] */
/* @0x18167c ldrb r3, [r3] */
/* @0x181680 cmp r3, #0 */
/* @0x181684 ldr r3, [r6] */
/* @0x181688 bne 0x181a04 <_Z21_SetupRenderTargetFBOP7Textureii+0x564> */
/* @0x18168c cmp r3, #1 */
/* @0x181690 ldr r12, [pc, #0x45c] */
/* @0x181694 ldrne r12, [pc, #0x45c] */
/* @0x181698 ldr r12, [r4, r12] */
/* @0x18169c movw r0, #0x8d40 */
/* @0x1816a0 ldr r3, [r5, #0x1c] */
/* @0x1816a4 mov r1, #36096 */
/* @0x1816a8 movw r2, #0x8d41 */
/* @0x1816ac ldr r12, [r12] */
/* @0x1816b0 blx r12 */
/* @0x1816b4 ldr r3, [r6] */
/* @0x1816b8 cmp r3, #1 */
/* @0x1816bc beq 0x181a80 <_Z21_SetupRenderTargetFBOP7Textureii+0x5e0> */
/* @0x1816c0 ldr r12, [pc, #0x430] */
/* @0x1816c4 movw r0, #0x8d40 */
/* @0x1816c8 ldr r3, [r5, #0x1c] */
/* @0x1816cc ldr r12, [r4, r12] */
/* @0x1816d0 movw r1, #0x8d20 */
/* @0x1816d4 movw r2, #0x8d41 */
/* @0x1816d8 ldr r12, [r12] */
/* @0x1816dc blx r12 */
/* @0x1816e0 ldr r12, [pc, #0x414] */
/* @0x1816e4 mov r0, #0 */
/* @0x1816e8 mov r1, r0 */
/* @0x1816ec mov r2, r8 */
/* @0x1816f0 mov r3, r7 */
/* @0x1816f4 ldr r10, [r4, r12] */
/* @0x1816f8 ldr r12, [r10] */
/* @0x1816fc blx r12 */
/* @0x181700 ldr r12, [pc, #0x3f8] */
/* @0x181704 mov r3, r7 */
/* @0x181708 mov r0, #0 */
/* @0x18170c mov r2, r8 */
/* @0x181710 mov r1, r0 */
/* @0x181714 ldr r7, [r4, r12] */
/* @0x181718 ldr r5, [r7] */
/* @0x18171c blx r5 */
/* @0x181720 ldr r3, [pc, #0x3dc] */
/* @0x181724 mov r0, #0 */
/* @0x181728 mov r1, r0 */
/* @0x18172c mov r2, r0 */
/* @0x181730 ldr lr, [r4, r3] */
/* @0x181734 mov r3, r0 */
/* @0x181738 ldr r5, [lr] */
/* @0x18173c blx r5 */
/* @0x181740 ldr r3, [pc, #0x3c0] */
/* @0x181744 mov r0, #1065353216 */
/* @0x181748 ldr r3, [r4, r3] */
/* @0x18174c ldr r3, [r3] */
/* @0x181750 blx r3 */
/* @0x181754 ldr r3, [pc, #0x3b0] */
/* @0x181758 movw r0, #0xc11 */
/* @0x18175c ldr r3, [r4, r3] */
/* @0x181760 ldr r3, [r3] */
/* @0x181764 blx r3 */
/* @0x181768 ldr r3, [pc, #0x3a0] */
/* @0x18176c mov r0, #17664 */
/* @0x181770 ldr r3, [r4, r3] */
/* @0x181774 ldr r3, [r3] */
/* @0x181778 blx r3 */
/* @0x18177c ldr r3, [pc, #0x390] */
/* @0x181780 movw r0, #0xc11 */
/* @0x181784 ldr r3, [r4, r3] */
/* @0x181788 ldr r3, [r3] */
/* @0x18178c blx r3 */
/* @0x181790 ldr r2, [pc, #0x380] */
/* @0x181794 ldr r0, [pc, #0x380] */
/* @0x181798 ldr r1, [pc, #0x380] */
/* @0x18179c ldr r2, [r4, r2] */
/* @0x1817a0 ldr r3, [pc, #0x37c] */
/* @0x1817a4 ldr r11, [r4, r0] */
/* @0x1817a8 ldr r8, [r4, r1] */
/* @0x1817ac str r2, [sp, #0xc] */
/* @0x1817b0 ldr r5, [r4, r3] */
/* @0x1817b4 ldr r0, [r11] */
/* @0x1817b8 ldr r1, [r8] */
/* @0x1817bc ldr r2, [r2] */
/* @0x1817c0 ldr r3, [r5] */
/* @0x1817c4 ldr r10, [r10] */
/* @0x1817c8 blx r10 */
/* @0x1817cc ldr r3, [sp, #0xc] */
/* @0x1817d0 ldr r12, [r7] */
/* @0x1817d4 ldr r0, [r11] */
/* @0x1817d8 ldr r2, [r3] */
/* @0x1817dc ldr r1, [r8] */
/* @0x1817e0 ldr r3, [r5] */
/* @0x1817e4 blx r12 */
/* @0x1817e8 ldr r3, [r6] */
/* @0x1817ec cmp r3, #1 */
/* @0x1817f0 beq 0x181a50 <_Z21_SetupRenderTargetFBOP7Textureii+0x5b0> */
/* @0x1817f4 ldr r3, [pc, #0x32c] */
/* @0x1817f8 movw r0, #0x8d40 */
/* @0x1817fc ldr r3, [r4, r3] */
/* @0x181800 ldr r3, [r3] */
/* @0x181804 blx r3 */
/* @0x181808 movw r3, #0x8cd5 */
/* @0x18180c cmp r0, r3 */
/* @0x181810 beq 0x18183c <_Z21_SetupRenderTargetFBOP7Textureii+0x39c> */
/* @0x181814 ldr r12, [pc, #0x310] */
/* @0x181818 mov r2, r0 */
/* @0x18181c mov r3, r0 */
/* @0x181820 ldr r1, [pc, #0x308] */
/* @0x181824 ldr r0, [r4, r12] */
/* @0x181828 add r1, pc, r1 */
/* @0x18182c ldr r0, [r0] */
/* @0x181830 ldr r12, [r0] */
/* @0x181834 ldr r12, [r12, #0xc] */
/* @0x181838 blx r12 */
/* @0x18183c ldr r3, [pc, #0x2f0] */
/* @0x181840 movw r1, #0x48b */
/* @0x181844 ldr r2, [pc, #0x2ec] */
/* @0x181848 str r1, [r9, #0x4] */
/* @0x18184c add r2, pc, r2 */
/* @0x181850 str r2, [r9] */
/* @0x181854 ldr r3, [r4, r3] */
/* @0x181858 ldr r0, [r3] */
/* @0x18185c add sp, sp, #20 */
/* @0x181860 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x181864 b 0x1805b4 <_Z20DBG_BIND_FRAMEBUFFERi> */
/* @0x181868 add sp, sp, #20 */
/* @0x18186c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x181870 cmp r3, #1 */
/* @0x181874 movw r1, #0x81a5 */
/* @0x181878 ldr r3, [pc, #0x2bc] */
/* @0x18187c beq 0x181a78 <_Z21_SetupRenderTargetFBOP7Textureii+0x5d8> */
/* @0x181880 ldr r12, [pc, #0x264] */
/* @0x181884 ldr r10, [r4, r3] */
/* @0x181888 movw lr, #0x81a6 */
/* @0x18188c ldr r12, [r4, r12] */
/* @0x181890 mov r3, r7 */
/* @0x181894 movw r0, #0x8d41 */
/* @0x181898 mov r2, r8 */
/* @0x18189c ldrb r10, [r10] */
/* @0x1818a0 ldr r12, [r12] */
/* @0x1818a4 cmp r10, #0 */
/* @0x1818a8 movne r1, lr */
/* @0x1818ac blx r12 */
/* @0x1818b0 ldr r3, [r6] */
/* @0x1818b4 cmp r3, #1 */
/* @0x1818b8 beq 0x181a70 <_Z21_SetupRenderTargetFBOP7Textureii+0x5d0> */
/* @0x1818bc ldr r3, [pc, #0x21c] */
/* @0x1818c0 ldr r3, [r4, r3] */
/* @0x1818c4 movw r0, #0x8d41 */
/* @0x1818c8 mov r1, #0 */
/* @0x1818cc ldr r3, [r3] */
/* @0x1818d0 blx r3 */
/* @0x1818d4 ldr r3, [r6] */
/* @0x1818d8 ldr r12, [pc, #0x214] */
/* @0x1818dc cmp r3, #1 */
/* @0x1818e0 ldrne r12, [pc, #0x210] */
/* @0x1818e4 ldr r12, [r4, r12] */
/* @0x1818e8 movw r0, #0x8d40 */
/* @0x1818ec ldr r3, [r5, #0x1c] */
/* @0x1818f0 mov r1, #36096 */
/* @0x1818f4 movw r2, #0x8d41 */
/* @0x1818f8 ldr r12, [r12] */
/* @0x1818fc blx r12 */
/* @0x181900 ldr r3, [pc, #0x238] */
/* @0x181904 ldr r3, [r4, r3] */
/* @0x181908 ldrb r3, [r3] */
/* @0x18190c cmp r3, #0 */
/* @0x181910 beq 0x1816e0 <_Z21_SetupRenderTargetFBOP7Textureii+0x240> */
/* @0x181914 ldr r0, [r6] */
/* @0x181918 cmp r0, #1 */
/* @0x18191c beq 0x181aa0 <_Z21_SetupRenderTargetFBOP7Textureii+0x600> */
/* @0x181920 ldr r3, [pc, #0x1b4] */
/* @0x181924 mov r0, #1 */
/* @0x181928 add r1, r5, #32 */
/* @0x18192c ldr r3, [r4, r3] */
/* @0x181930 ldr r3, [r3] */
/* @0x181934 blx r3 */
/* @0x181938 ldr r3, [pc, #0x1ec] */
/* @0x18193c ldr r1, [pc, #0x200] */
/* @0x181940 ldr r2, [r5, #0x20] */
/* @0x181944 ldr r3, [r4, r3] */
/* @0x181948 add r1, pc, r1 */
/* @0x18194c ldr r0, [r3] */
/* @0x181950 ldr r3, [r0] */
/* @0x181954 ldr r3, [r3, #0xc] */
/* @0x181958 blx r3 */
/* @0x18195c ldr r3, [r6] */
/* @0x181960 cmp r3, #1 */
/* @0x181964 beq 0x181a98 <_Z21_SetupRenderTargetFBOP7Textureii+0x5f8> */
/* @0x181968 ldr r3, [pc, #0x170] */
/* @0x18196c ldr r3, [r4, r3] */
/* @0x181970 movw r0, #0x8d41 */
/* @0x181974 ldr r1, [r5, #0x20] */
/* @0x181978 ldr r3, [r3] */
/* @0x18197c blx r3 */
/* @0x181980 ldr r3, [r6] */
/* @0x181984 ldr r12, [pc, #0x15c] */
/* @0x181988 cmp r3, #1 */
/* @0x18198c ldrne r12, [pc, #0x158] */
/* @0x181990 ldr r12, [r4, r12] */
/* @0x181994 mov r3, r7 */
/* @0x181998 movw r0, #0x8d41 */
/* @0x18199c movw r1, #0x8d48 */
/* @0x1819a0 mov r2, r8 */
/* @0x1819a4 ldr r12, [r12] */
/* @0x1819a8 blx r12 */
/* @0x1819ac ldr r3, [r6] */
/* @0x1819b0 cmp r3, #1 */
/* @0x1819b4 beq 0x181a90 <_Z21_SetupRenderTargetFBOP7Textureii+0x5f0> */
/* @0x1819b8 ldr r3, [pc, #0x120] */
/* @0x1819bc ldr r3, [r4, r3] */
/* @0x1819c0 movw r0, #0x8d41 */
/* @0x1819c4 mov r1, #0 */
/* @0x1819c8 ldr r3, [r3] */
/* @0x1819cc blx r3 */
/* @0x1819d0 ldr r3, [r6] */
/* @0x1819d4 ldr r12, [pc, #0x118] */
/* @0x1819d8 cmp r3, #1 */
/* @0x1819dc ldrne r12, [pc, #0x114] */
/* @0x1819e0 movw r0, #0x8d40 */
/* @0x1819e4 ldr r3, [r5, #0x20] */
/* @0x1819e8 b 0x1816cc <_Z21_SetupRenderTargetFBOP7Textureii+0x22c> */
/* @0x1819ec ldr r3, [pc, #0x154] */
/* @0x1819f0 add r1, r5, #24 */
/* @0x1819f4 ldr r3, [r4, r3] */
/* @0x1819f8 ldr r3, [r3] */
/* @0x1819fc blx r3 */
/* @0x181a00 b 0x181574 <_Z21_SetupRenderTargetFBOP7Textureii+0xd4> */
/* @0x181a04 cmp r3, #1 */
/* @0x181a08 ldr r12, [pc, #0xe4] */
/* @0x181a0c ldrne r12, [pc, #0xe4] */
/* @0x181a10 ldr r12, [r4, r12] */
/* @0x181a14 movw r0, #0x8d40 */
/* @0x181a18 ldr r3, [r5, #0x1c] */
/* @0x181a1c movw r1, #0x821a */
/* @0x181a20 movw r2, #0x8d41 */
/* @0x181a24 ldr r12, [r12] */
/* @0x181a28 blx r12 */
/* @0x181a2c b 0x1816e0 <_Z21_SetupRenderTargetFBOP7Textureii+0x240> */
/* @0x181a30 ldr r3, [pc, #0x114] */
/* @0x181a34 b 0x1815fc <_Z21_SetupRenderTargetFBOP7Textureii+0x15c> */
/* @0x181a38 ldr r3, [pc, #0x110] */
/* @0x181a3c add r1, r5, #28 */
/* @0x181a40 ldr r3, [r4, r3] */
/* @0x181a44 ldr r3, [r3] */
/* @0x181a48 blx r3 */
/* @0x181a4c b 0x1815ec <_Z21_SetupRenderTargetFBOP7Textureii+0x14c> */
/* @0x181a50 ldr r3, [pc, #0xfc] */
/* @0x181a54 movw r0, #0x8d40 */
/* @0x181a58 ldr r3, [r4, r3] */
/* @0x181a5c ldr r3, [r3] */
/* @0x181a60 blx r3 */
/* @0x181a64 b 0x181808 <_Z21_SetupRenderTargetFBOP7Textureii+0x368> */
/* @0x181a68 ldr r3, [pc, #0xdc] */
/* @0x181a6c b 0x181660 <_Z21_SetupRenderTargetFBOP7Textureii+0x1c0> */
/* @0x181a70 ldr r3, [pc, #0xd4] */
/* @0x181a74 b 0x1818c0 <_Z21_SetupRenderTargetFBOP7Textureii+0x420> */
/* @0x181a78 ldr r12, [pc, #0x68] */
/* @0x181a7c b 0x181884 <_Z21_SetupRenderTargetFBOP7Textureii+0x3e4> */
/* @0x181a80 ldr r12, [pc, #0x6c] */
/* @0x181a84 movw r0, #0x8d40 */
/* @0x181a88 ldr r3, [r5, #0x1c] */
/* @0x181a8c b 0x1816cc <_Z21_SetupRenderTargetFBOP7Textureii+0x22c> */
/* @0x181a90 ldr r3, [pc, #0xb4] */
/* @0x181a94 b 0x1819bc <_Z21_SetupRenderTargetFBOP7Textureii+0x51c> */
/* @0x181a98 ldr r3, [pc, #0xac] */
/* @0x181a9c b 0x18196c <_Z21_SetupRenderTargetFBOP7Textureii+0x4cc> */
/* @0x181aa0 ldr r3, [pc, #0xa8] */
/* @0x181aa4 add r1, r5, #32 */
/* @0x181aa8 ldr r3, [r4, r3] */
/* @0x181aac ldr r3, [r3] */
/* @0x181ab0 blx r3 */
/* @0x181ab4 b 0x181938 <_Z21_SetupRenderTargetFBOP7Textureii+0x498> */
/* @0x181ab8 mlaeq r7, r8, r7, r0 */
/* @0x181abc .word 0xffffbb20 */
/* @0x181ac0 .word 0xffffbb1c */
/* @0x181ac4 .word 0xffffe7b8 */
/* @0x181ac8 .word 0xffffbc74 */
/* @0x181acc .word 0xffffe81c */
/* @0x181ad0 andseq r10, r12, r4, lsr r4 */
/* @0x181ad4 .word 0xffffbb6c */
/* @0x181ad8 .word 0xffffbc7c */
/* @0x181adc .word 0xffffbcb0 */
/* @0x181ae0 .word 0xffffbcb4 */
/* @0x181ae4 .word 0xffffe7d8 */
/* @0x181ae8 .word 0xffffbc08 */
/* @0x181aec .word 0xffffbcb8 */
/* @0x181af0 .word 0xffffe900 */
/* @0x181af4 .word 0xffffbc10 */
/* @0x181af8 .word 0xffffbcc0 */
/* @0x181afc .word 0xffffbae4 */
/* @0x181b00 .word 0xffffbaf0 */
/* @0x181b04 .word 0xffffbb00 */
/* @0x181b08 .word 0xffffbb04 */
/* @0x181b0c .word 0xffffbad0 */
/* @0x181b10 .word 0xffffbacc */
/* @0x181b14 .word 0xffffbad8 */
/* @0x181b18 .word 0xffffe814 */
/* @0x181b1c .word 0xffffe80c */
/* @0x181b20 .word 0xffffe810 */
/* @0x181b24 .word 0xffffe818 */
/* @0x181b28 .word 0xffffbc84 */
/* @0x181b2c .word 0xffffbac4 */
/* @0x181b30 andseq r10, r12, r8, lsl r2 */
/* @0x181b34 .word 0xffffe820 */
/* @0x181b38 andseq r10, r12, r0, ror r1 */
/* @0x181b3c .word 0xffffe7dc */
/* @0x181b40 .word 0xffffe7c4 */
/* @0x181b44 andseq r10, r12, r8, ror #1 */
/* @0x181b48 .word 0xffffbb68 */
/* @0x181b4c .word 0xffffbc04 */
/* @0x181b50 .word 0xffffbc00 */
/* @0x181b54 .word 0xffffbbf4 */

/* ── FUNC 0x181b58 · gluBuild2DMipmaps(unsigned int, int, int, int, unsigned int, unsigned int, void const*) · size=388 · insn=97 */
/* @0x181b58 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x181b5c sub sp, sp, #36 */
/* @0x181b60 ldr r9, [pc, #0x170] */
/* @0x181b64 mov r7, r2 */
/* @0x181b68 str r1, [sp, #0x18] */
/* @0x181b6c mov r11, #0 */
/* @0x181b70 ldr r1, [sp, #0x48] */
/* @0x181b74 ldr r9, [pc, r9] */
/* @0x181b78 ldr r2, [sp, #0x4c] */
/* @0x181b7c mov r10, r3 */
/* @0x181b80 ldr r6, [sp, #0x50] */
/* @0x181b84 add r5, r7, r7, lsr #31 */
/* @0x181b88 str r1, [sp, #0x8] */
/* @0x181b8c mov r1, r11 */
/* @0x181b90 str r3, [sp] */
/* @0x181b94 mov r3, r7 */
/* @0x181b98 str r2, [sp, #0xc] */
/* @0x181b9c asr r5, r5, #1 */
/* @0x181ba0 str r6, [sp, #0x10] */
/* @0x181ba4 str r11, [sp, #0x4] */
/* @0x181ba8 ldr r2, [sp, #0x18] */
/* @0x181bac ldr r4, [r9] */
/* @0x181bb0 str r0, [sp, #0x1c] */
/* @0x181bb4 blx r4 */
/* @0x181bb8 add r4, r10, r10, lsr #31 */
/* @0x181bbc asr r4, r4, #1 */
/* @0x181bc0 cmp r5, #1 */
/* @0x181bc4 cmpgt r4, #1 */
/* @0x181bc8 ble 0x181c50 <_Z17gluBuild2DMipmapsjiiijjPKv+0xf8> */
/* @0x181bcc ldr r1, [sp, #0x48] */
/* @0x181bd0 movw r3, #0x1908 */
/* @0x181bd4 mov r8, #1 */
/* @0x181bd8 cmp r1, r3 */
/* @0x181bdc beq 0x181c58 <_Z17gluBuild2DMipmapsjiiijjPKv+0x100> */
/* @0x181be0 mov r3, r7 */
/* @0x181be4 ldr r7, [sp, #0x4c] */
/* @0x181be8 mov r0, r5 */
/* @0x181bec mov r1, r4 */
/* @0x181bf0 str r10, [sp] */
/* @0x181bf4 mov r2, r6 */
/* @0x181bf8 str r6, [sp, #0x4] */
/* @0x181bfc mov r10, r4 */
/* @0x181c00 bl 0x18941c <_Z14HalfTextureRGBiiPhiiS_> */
/* @0x181c04 ldr r2, [sp, #0x48] */
/* @0x181c08 stm sp, {r4, r11} */
/* @0x181c0c mov r3, r5 */
/* @0x181c10 mov r1, r8 */
/* @0x181c14 str r7, [sp, #0xc] */
/* @0x181c18 str r2, [sp, #0x8] */
/* @0x181c1c asr r4, r4, #1 */
/* @0x181c20 ldr r2, [sp, #0x18] */
/* @0x181c24 add r8, r8, #1 */
/* @0x181c28 str r6, [sp, #0x10] */
/* @0x181c2c ldr r0, [sp, #0x1c] */
/* @0x181c30 ldr r12, [r9] */
/* @0x181c34 blx r12 */
/* @0x181c38 asr r2, r5, #1 */
/* @0x181c3c cmp r4, #1 */
/* @0x181c40 cmpgt r2, #1 */
/* @0x181c44 mov r3, r5 */
/* @0x181c48 mov r5, r2 */
/* @0x181c4c bgt 0x181be8 <_Z17gluBuild2DMipmapsjiiijjPKv+0x90> */
/* @0x181c50 add sp, sp, #36 */
/* @0x181c54 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x181c58 mov r2, r10 */
/* @0x181c5c mov r10, r9 */
/* @0x181c60 ldr r9, [sp, #0x4c] */
/* @0x181c64 mov r3, r7 */
/* @0x181c68 mov r0, r5 */
/* @0x181c6c mov r1, r4 */
/* @0x181c70 str r2, [sp] */
/* @0x181c74 str r6, [sp, #0x4] */
/* @0x181c78 mov r2, r6 */
/* @0x181c7c bl 0x18923c <_Z15HalfTextureRGBAiiPjiiS_> */
/* @0x181c80 stm sp, {r4, r11} */
/* @0x181c84 movw r3, #0x1908 */
/* @0x181c88 mov r1, r8 */
/* @0x181c8c str r3, [sp, #0x8] */
/* @0x181c90 mov r3, r5 */
/* @0x181c94 str r9, [sp, #0xc] */
/* @0x181c98 mov r7, r5 */
/* @0x181c9c ldr r2, [sp, #0x18] */
/* @0x181ca0 asr r5, r5, #1 */
/* @0x181ca4 str r6, [sp, #0x10] */
/* @0x181ca8 add r8, r8, #1 */
/* @0x181cac ldr r0, [sp, #0x1c] */
/* @0x181cb0 ldr r12, [r10] */
/* @0x181cb4 blx r12 */
/* @0x181cb8 asr r3, r4, #1 */
/* @0x181cbc cmp r3, #1 */
/* @0x181cc0 cmpgt r5, #1 */
/* @0x181cc4 mov r2, r4 */
/* @0x181cc8 mov r4, r3 */
/* @0x181ccc bgt 0x181c64 <_Z17gluBuild2DMipmapsjiiijjPKv+0x10c> */
/* @0x181cd0 add sp, sp, #36 */
/* @0x181cd4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x181cd8 eoreq r11, r6, r8, lsl #24 */

/* ── FUNC 0x181cdc · _PNG_setTexture(Texture*, int, int, int, int, int, unsigned char*) · size=212 · insn=53 */
/* @0x181cdc ldr r12, [pc, #0xbc] */
/* @0x181ce0 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x181ce4 ldr r12, [pc, r12] */
/* @0x181ce8 sub sp, sp, #24 */
/* @0x181cec mov r6, r1 */
/* @0x181cf0 mov r4, r3 */
/* @0x181cf4 mov r7, r0 */
/* @0x181cf8 ldr r3, [r12] */
/* @0x181cfc add r1, sp, #20 */
/* @0x181d00 mov r0, #1 */
/* @0x181d04 mov r5, r2 */
/* @0x181d08 ldr r10, [sp, #0x38] */
/* @0x181d0c ldr r9, [sp, #0x3c] */
/* @0x181d10 ldr r8, [sp, #0x40] */
/* @0x181d14 blx r3 */
/* @0x181d18 ldr r3, [pc, #0x84] */
/* @0x181d1c movw r0, #0xde1 */
/* @0x181d20 ldr r1, [sp, #0x14] */
/* @0x181d24 ldr r3, [pc, r3] */
/* @0x181d28 ldr r3, [r3] */
/* @0x181d2c blx r3 */
/* @0x181d30 ldr r12, [pc, #0x70] */
/* @0x181d34 ldr r1, [pc, #0x70] */
/* @0x181d38 mov r2, r5 */
/* @0x181d3c ldr r12, [pc, r12] */
/* @0x181d40 mov r3, r4 */
/* @0x181d44 add r1, pc, r1 */
/* @0x181d48 ldr r0, [r12] */
/* @0x181d4c ldr r12, [r0] */
/* @0x181d50 str r10, [sp] */
/* @0x181d54 str r9, [sp, #0x4] */
/* @0x181d58 str r6, [sp, #0x8] */
/* @0x181d5c ldr r12, [r12, #0xc] */
/* @0x181d60 blx r12 */
/* @0x181d64 cmp r6, #2 */
/* @0x181d68 mov r3, r4 */
/* @0x181d6c movw r12, #0x1401 */
/* @0x181d70 movwne r1, #0x1908 */
/* @0x181d74 movweq r1, #0x1907 */
/* @0x181d78 str r8, [sp, #0x8] */
/* @0x181d7c mov r2, r5 */
/* @0x181d80 movw r0, #0xde1 */
/* @0x181d84 str r12, [sp, #0x4] */
/* @0x181d88 str r1, [sp] */
/* @0x181d8c bl 0x181b58 <_Z17gluBuild2DMipmapsjiiijjPKv> */
/* @0x181d90 ldr r3, [sp, #0x14] */
/* @0x181d94 str r3, [r7, #0x14] */
/* @0x181d98 add sp, sp, #24 */
/* @0x181d9c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x181da0 mlaeq r6, r4, r10, r11 */
/* @0x181da4 eoreq r11, r6, r12, asr #20 */
/* @0x181da8 .word 0x0026b9d8 */
/* @0x181dac andseq r9, r12, r8, lsr sp */

/* ── FUNC 0x181db0 · GenerateMips(Texture*, int, int, int, char*) · size=852 · insn=213 */
/* @0x181db0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x181db4 mov r4, r2 */
/* @0x181db8 add r2, r1, r1, lsr #31 */
/* @0x181dbc sub sp, sp, #76 */
/* @0x181dc0 mov r6, r1 */
/* @0x181dc4 add r1, r4, r4, lsr #31 */
/* @0x181dc8 asrs r7, r2, #1 */
/* @0x181dcc str r0, [sp, #0x3c] */
/* @0x181dd0 ldr r8, [pc, #0x324] */
/* @0x181dd4 mov r2, #70 */
/* @0x181dd8 moveq r7, #1 */
/* @0x181ddc asrs r1, r1, #1 */
/* @0x181de0 mul r0, r3, r7 */
/* @0x181de4 moveq r1, #1 */
/* @0x181de8 str r1, [sp, #0x18] */
/* @0x181dec add r8, pc, r8 */
/* @0x181df0 ldr r12, [sp, #0x18] */
/* @0x181df4 mov r3, #1 */
/* @0x181df8 mov r1, r8 */
/* @0x181dfc ldr r5, [sp, #0x70] */
/* @0x181e00 mul r9, r12, r0 */
/* @0x181e04 mov r0, r9 */
/* @0x181e08 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x181e0c mov r1, r8 */
/* @0x181e10 mov r2, #70 */
/* @0x181e14 mov r3, #1 */
/* @0x181e18 str r0, [sp, #0x34] */
/* @0x181e1c mov r0, r9 */
/* @0x181e20 ldr r12, [sp, #0x34] */
/* @0x181e24 str r12, [sp, #0x40] */
/* @0x181e28 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x181e2c cmp r4, #1 */
/* @0x181e30 cmpeq r6, #1 */
/* @0x181e34 str r0, [sp, #0x38] */
/* @0x181e38 str r0, [sp, #0x44] */
/* @0x181e3c beq 0x1820d4 <_Z12GenerateMipsP7TextureiiiPc+0x324> */
/* @0x181e40 ldr r12, [pc, #0x2b8] */
/* @0x181e44 str r12, [sp, #0x30] */
/* @0x181e48 mov r12, #0 */
/* @0x181e4c str r12, [sp, #0x28] */
/* @0x181e50 ldr r12, [sp, #0x38] */
/* @0x181e54 str r12, [sp, #0x2c] */
/* @0x181e58 ldr r12, [sp, #0x30] */
/* @0x181e5c ldr r12, [pc, r12] */
/* @0x181e60 str r12, [sp, #0x30] */
/* @0x181e64 ldr r12, [sp, #0x34] */
/* @0x181e68 str r12, [sp, #0x20] */
/* @0x181e6c mov r12, #1 */
/* @0x181e70 str r12, [sp, #0x24] */
/* @0x181e74 cmp r6, #1 */
/* @0x181e78 cmpne r4, #1 */
/* @0x181e7c movne r4, #0 */
/* @0x181e80 moveq r4, #1 */
/* @0x181e84 bne 0x181fc8 <_Z12GenerateMipsP7TextureiiiPc+0x218> */
/* @0x181e88 ldr r12, [sp, #0x18] */
/* @0x181e8c cmp r12, #0 */
/* @0x181e90 ble 0x181f14 <_Z12GenerateMipsP7TextureiiiPc+0x164> */
/* @0x181e94 ldr r12, [sp, #0x20] */
/* @0x181e98 sub r1, r12, #4 */
/* @0x181e9c ldr r12, [sp, #0x18] */
/* @0x181ea0 add r6, r5, r12, lsl #3 */
/* @0x181ea4 ldr r3, [r5] */
/* @0x181ea8 add r5, r5, #8 */
/* @0x181eac ldr r2, [r5, #-0x4] */
/* @0x181eb0 cmp r5, r6 */
/* @0x181eb4 and r4, r3, #65280 */
/* @0x181eb8 and r12, r3, #16711680 */
/* @0x181ebc and r0, r2, #16711680 */
/* @0x181ec0 and lr, r2, #65280 */
/* @0x181ec4 add lr, r4, lr */
/* @0x181ec8 add r12, r12, r0 */
/* @0x181ecc asr r4, r3, #8 */
/* @0x181ed0 asr r0, r2, #8 */
/* @0x181ed4 and r4, r4, #16711680 */
/* @0x181ed8 and r0, r0, #16711680 */
/* @0x181edc asr lr, lr, #1 */
/* @0x181ee0 asr r12, r12, #1 */
/* @0x181ee4 uxtb r2, r2 */
/* @0x181ee8 add r0, r4, r0 */
/* @0x181eec and lr, lr, #65280 */
/* @0x181ef0 and r12, r12, #16711680 */
/* @0x181ef4 uxtab r3, r2, r3 */
/* @0x181ef8 orr r12, lr, r12 */
/* @0x181efc lsl r0, r0, #7 */
/* @0x181f00 orr r3, r12, r3, lsr #1 */
/* @0x181f04 and r0, r0, #-16777216 */
/* @0x181f08 orr r3, r3, r0 */
/* @0x181f0c str r3, [r1, #0x4]! */
/* @0x181f10 bne 0x181ea4 <_Z12GenerateMipsP7TextureiiiPc+0xf4> */
/* @0x181f14 ldr r12, [sp, #0x18] */
/* @0x181f18 mov lr, #0 */
/* @0x181f1c str lr, [sp, #0x4] */
/* @0x181f20 movw r2, #0x1908 */
/* @0x181f24 ldr lr, [sp, #0x30] */
/* @0x181f28 movw r3, #0x1401 */
/* @0x181f2c str r12, [sp] */
/* @0x181f30 movw r0, #0xde1 */
/* @0x181f34 ldr r12, [sp, #0x20] */
/* @0x181f38 ldr r1, [sp, #0x24] */
/* @0x181f3c str r2, [sp, #0x8] */
/* @0x181f40 str r3, [sp, #0xc] */
/* @0x181f44 mov r3, r7 */
/* @0x181f48 str r12, [sp, #0x10] */
/* @0x181f4c add r12, r1, #1 */
/* @0x181f50 str r12, [sp, #0x24] */
/* @0x181f54 ldr r12, [lr] */
/* @0x181f58 blx r12 */
/* @0x181f5c ldr r12, [sp, #0x18] */
/* @0x181f60 add r3, r7, r7, lsr #31 */
/* @0x181f64 add r2, r12, r12, lsr #31 */
/* @0x181f68 asrs r3, r3, #1 */
/* @0x181f6c ldr r12, [sp, #0x28] */
/* @0x181f70 moveq r3, #1 */
/* @0x181f74 asrs r2, r2, #1 */
/* @0x181f78 eor r1, r12, #1 */
/* @0x181f7c ldr r12, [sp, #0x18] */
/* @0x181f80 moveq r2, #1 */
/* @0x181f84 cmp r7, #1 */
/* @0x181f88 cmpeq r12, #1 */
/* @0x181f8c beq 0x1820d4 <_Z12GenerateMipsP7TextureiiiPc+0x324> */
/* @0x181f90 ldr r12, [sp, #0x28] */
/* @0x181f94 add lr, sp, #72 */
/* @0x181f98 ldr r5, [sp, #0x20] */
/* @0x181f9c mov r6, r7 */
/* @0x181fa0 ldr r4, [sp, #0x18] */
/* @0x181fa4 mov r7, r3 */
/* @0x181fa8 add r0, lr, r12, lsl #2 */
/* @0x181fac ldr r12, [sp, #0x2c] */
/* @0x181fb0 str r1, [sp, #0x28] */
/* @0x181fb4 ldr r0, [r0, #-0x8] */
/* @0x181fb8 str r12, [sp, #0x20] */
/* @0x181fbc str r2, [sp, #0x18] */
/* @0x181fc0 str r0, [sp, #0x2c] */
/* @0x181fc4 b 0x181e74 <_Z12GenerateMipsP7TextureiiiPc+0xc4> */
/* @0x181fc8 ldr r2, [sp, #0x18] */
/* @0x181fcc mul r2, r2, r7 */
/* @0x181fd0 cmp r2, #0 */
/* @0x181fd4 str r2, [sp, #0x1c] */
/* @0x181fd8 ble 0x181f14 <_Z12GenerateMipsP7TextureiiiPc+0x164> */
/* @0x181fdc ldr r12, [sp, #0x20] */
/* @0x181fe0 sub r8, r12, #4 */
/* @0x181fe4 mov r0, r4 */
/* @0x181fe8 mov r1, r7 */
/* @0x181fec bl 0x318d10 <__divsi3> */
/* @0x181ff0 mov r1, r7 */
/* @0x181ff4 mul r9, r6, r0 */
/* @0x181ff8 mov r0, r4 */
/* @0x181ffc bl 0x318dec <__aeabi_idivmod> */
/* @0x182000 ldr r2, [sp, #0x1c] */
/* @0x182004 add r4, r4, #1 */
/* @0x182008 cmp r4, r2 */
/* @0x18200c add r1, r9, r1 */
/* @0x182010 lsl r1, r1, #1 */
/* @0x182014 add r3, r1, r6 */
/* @0x182018 add r2, r1, #1 */
/* @0x18201c ldr r0, [r5, r1, lsl #2] */
/* @0x182020 ldr r12, [r5, r2, lsl #2] */
/* @0x182024 add lr, r5, r3, lsl #2 */
/* @0x182028 ldr r2, [r5, r3, lsl #2] */
/* @0x18202c and r9, r0, #65280 */
/* @0x182030 ldr r3, [lr, #0x4] */
/* @0x182034 and r1, r12, #65280 */
/* @0x182038 and lr, r12, #16711680 */
/* @0x18203c and r11, r0, #16711680 */
/* @0x182040 add r1, r9, r1 */
/* @0x182044 and r9, r2, #65280 */
/* @0x182048 add r11, r11, lr */
/* @0x18204c add r1, r1, r9 */
/* @0x182050 and lr, r2, #16711680 */
/* @0x182054 and r9, r3, #65280 */
/* @0x182058 add r11, r11, lr */
/* @0x18205c add r1, r1, r9 */
/* @0x182060 asr lr, r12, #8 */
/* @0x182064 asr r9, r0, #8 */
/* @0x182068 and r9, r9, #16711680 */
/* @0x18206c and lr, lr, #16711680 */
/* @0x182070 and r10, r3, #16711680 */
/* @0x182074 add lr, r9, lr */
/* @0x182078 asr r9, r2, #8 */
/* @0x18207c add r10, r11, r10 */
/* @0x182080 uxtb r12, r12 */
/* @0x182084 asr r11, r3, #8 */
/* @0x182088 and r9, r9, #16711680 */
/* @0x18208c uxtab r0, r12, r0 */
/* @0x182090 and r11, r11, #16711680 */
/* @0x182094 add lr, lr, r9 */
/* @0x182098 asr r1, r1, #2 */
/* @0x18209c asr r10, r10, #2 */
/* @0x1820a0 uxtab r0, r0, r2 */
/* @0x1820a4 add r12, lr, r11 */
/* @0x1820a8 and r1, r1, #65280 */
/* @0x1820ac and r10, r10, #16711680 */
/* @0x1820b0 uxtab r3, r0, r3 */
/* @0x1820b4 orr r1, r1, r10 */
/* @0x1820b8 lsl r12, r12, #6 */
/* @0x1820bc orr r3, r1, r3, lsr #2 */
/* @0x1820c0 and r12, r12, #-16777216 */
/* @0x1820c4 orr r3, r3, r12 */
/* @0x1820c8 str r3, [r8, #0x4]! */
/* @0x1820cc bne 0x181fe4 <_Z12GenerateMipsP7TextureiiiPc+0x234> */
/* @0x1820d0 b 0x181f14 <_Z12GenerateMipsP7TextureiiiPc+0x164> */
/* @0x1820d4 ldr r12, [sp, #0x3c] */
/* @0x1820d8 ldr r0, [sp, #0x34] */
/* @0x1820dc ldr r3, [r12, #0x10] */
/* @0x1820e0 orr r3, r3, #32 */
/* @0x1820e4 str r3, [r12, #0x10] */
/* @0x1820e8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1820ec ldr r0, [sp, #0x38] */
/* @0x1820f0 add sp, sp, #76 */
/* @0x1820f4 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1820f8 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1820fc andseq pc, r10, r4, asr #4 */
/* @0x182100 eoreq r11, r6, r0, lsr #18 */

/* ── FUNC 0x182104 · _CreateTexture(Texture*, bool, eMipEnable) · size=1020 · insn=255 */
/* @0x182104 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x182108 cmp r1, #0 */
/* @0x18210c ldr r6, [pc, #0x3c8] */
/* @0x182110 sub sp, sp, #24 */
/* @0x182114 mov r4, r0 */
/* @0x182118 mov r7, r2 */
/* @0x18211c add r6, pc, r6 */
/* @0x182120 bne 0x182198 <_Z14_CreateTextureP7Textureb10eMipEnable+0x94> */
/* @0x182124 ldr r5, [r4, #0x2c] */
/* @0x182128 cmp r5, #0 */
/* @0x18212c beq 0x182304 <_Z14_CreateTextureP7Textureb10eMipEnable+0x200> */
/* @0x182130 ldr r0, [r5] */
/* @0x182134 movw r3, #0x4152 */
/* @0x182138 movt r3, #0x2057 */
/* @0x18213c cmp r0, r3 */
/* @0x182140 beq 0x1821f4 <_Z14_CreateTextureP7Textureb10eMipEnable+0xf0> */
/* @0x182144 movw r3, #0x5089 */
/* @0x182148 movt r3, #0x474e */
/* @0x18214c cmp r0, r3 */
/* @0x182150 beq 0x1822cc <_Z14_CreateTextureP7Textureb10eMipEnable+0x1c8> */
/* @0x182154 ldr r2, [r5, #0x2c] */
/* @0x182158 movw r3, #0x5650 */
/* @0x18215c movt r3, #0x2152 */
/* @0x182160 cmp r2, r3 */
/* @0x182164 beq 0x1821a0 <_Z14_CreateTextureP7Textureb10eMipEnable+0x9c> */
/* @0x182168 ldr r3, [pc, #0x370] */
/* @0x18216c ldr r1, [pc, #0x370] */
/* @0x182170 ldr r3, [r6, r3] */
/* @0x182174 add r1, pc, r1 */
/* @0x182178 ldr r0, [r3] */
/* @0x18217c ldr r3, [r0] */
/* @0x182180 ldr r3, [r3, #0xc] */
/* @0x182184 blx r3 */
/* @0x182188 mov r0, r4 */
/* @0x18218c add sp, sp, #24 */
/* @0x182190 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x182194 b 0x180aec <_Z20_SetTextureNPOTFlagsP7Texture> */
/* @0x182198 bl 0x182598 <_Z23_InvalidateTextureStatev> */
/* @0x18219c b 0x182124 <_Z14_CreateTextureP7Textureb10eMipEnable+0x20> */
/* @0x1821a0 ldr lr, [r5, #0x4] */
/* @0x1821a4 mov r1, r4 */
/* @0x1821a8 ldr r12, [r5, #0x8] */
/* @0x1821ac mov r2, #6 */
/* @0x1821b0 ldr r3, [pc, #0x330] */
/* @0x1821b4 mov r0, #1 */
/* @0x1821b8 stmib r4, {r12, lr} */
/* @0x1821bc str r2, [r1], #20 */
/* @0x1821c0 ldr r3, [r6, r3] */
/* @0x1821c4 ldr r3, [r3] */
/* @0x1821c8 blx r3 */
/* @0x1821cc ldr r3, [pc, #0x318] */
/* @0x1821d0 movw r0, #0xde1 */
/* @0x1821d4 ldr r1, [r4, #0x14] */
/* @0x1821d8 ldr r3, [r6, r3] */
/* @0x1821dc ldr r3, [r3] */
/* @0x1821e0 blx r3 */
/* @0x1821e4 mov r0, r4 */
/* @0x1821e8 add sp, sp, #24 */
/* @0x1821ec pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1821f0 b 0x180aec <_Z20_SetTextureNPOTFlagsP7Texture> */
/* @0x1821f4 ldr r9, [r5, #0x4] */
/* @0x1821f8 mov r0, #1 */
/* @0x1821fc ldr r8, [r5, #0x8] */
/* @0x182200 add r1, r4, #20 */
/* @0x182204 ldr r3, [pc, #0x2dc] */
/* @0x182208 ldr r10, [r5, #0xc] */
/* @0x18220c str r9, [r4, #0x4] */
/* @0x182210 str r8, [r4, #0x8] */
/* @0x182214 ldr r3, [r6, r3] */
/* @0x182218 ldr r3, [r3] */
/* @0x18221c blx r3 */
/* @0x182220 ldr r3, [pc, #0x2c4] */
/* @0x182224 movw r0, #0xde1 */
/* @0x182228 ldr r1, [r4, #0x14] */
/* @0x18222c ldr r3, [r6, r3] */
/* @0x182230 ldr r3, [r3] */
/* @0x182234 blx r3 */
/* @0x182238 cmp r10, #1 */
/* @0x18223c ldr r3, [pc, #0x2ac] */
/* @0x182240 beq 0x182410 <_Z14_CreateTextureP7Textureb10eMipEnable+0x30c> */
/* @0x182244 mov r2, #6 */
/* @0x182248 str r2, [r4] */
/* @0x18224c ldr lr, [r6, r3] */
/* @0x182250 mov r0, #0 */
/* @0x182254 movw r12, #0x1908 */
/* @0x182258 mov r3, r9 */
/* @0x18225c mov r1, r0 */
/* @0x182260 str r8, [sp] */
/* @0x182264 mov r2, r12 */
/* @0x182268 add r5, r5, #16 */
/* @0x18226c str r5, [sp, #0x10] */
/* @0x182270 ldr r6, [lr] */
/* @0x182274 movw lr, #0x1401 */
/* @0x182278 str r0, [sp, #0x4] */
/* @0x18227c movw r0, #0xde1 */
/* @0x182280 str r12, [sp, #0x8] */
/* @0x182284 str lr, [sp, #0xc] */
/* @0x182288 blx r6 */
/* @0x18228c ldr r3, [r4, #0x10] */
/* @0x182290 cmp r7, #1 */
/* @0x182294 orr r2, r3, #64 */
/* @0x182298 str r2, [r4, #0x10] */
/* @0x18229c beq 0x1822b0 <_Z14_CreateTextureP7Textureb10eMipEnable+0x1ac> */
/* @0x1822a0 cmp r7, #2 */
/* @0x1822a4 bne 0x182188 <_Z14_CreateTextureP7Textureb10eMipEnable+0x84> */
/* @0x1822a8 tst r3, #16 */
/* @0x1822ac beq 0x182188 <_Z14_CreateTextureP7Textureb10eMipEnable+0x84> */
/* @0x1822b0 ldr r1, [r4, #0x4] */
/* @0x1822b4 mov r0, r4 */
/* @0x1822b8 ldr r2, [r4, #0x8] */
/* @0x1822bc mov r3, #4 */
/* @0x1822c0 str r5, [sp] */
/* @0x1822c4 bl 0x181db0 <_Z12GenerateMipsP7TextureiiiPc> */
/* @0x1822c8 b 0x182188 <_Z14_CreateTextureP7Textureb10eMipEnable+0x84> */
/* @0x1822cc ldr r3, [pc, #0x20c] */
/* @0x1822d0 ldr r1, [pc, #0x21c] */
/* @0x1822d4 ldr r2, [r4, #0x4] */
/* @0x1822d8 ldr r0, [r6, r3] */
/* @0x1822dc add r1, pc, r1 */
/* @0x1822e0 ldr r3, [r4, #0x8] */
/* @0x1822e4 ldr r0, [r0] */
/* @0x1822e8 ldr r12, [r0] */
/* @0x1822ec ldr r12, [r12, #0xc] */
/* @0x1822f0 blx r12 */
/* @0x1822f4 mov r0, r4 */
/* @0x1822f8 mov r1, r7 */
/* @0x1822fc bl 0x1828a4 <_Z18LoadTextureFromPNGP7Texture10eMipEnable> */
/* @0x182300 b 0x182188 <_Z14_CreateTextureP7Textureb10eMipEnable+0x84> */
/* @0x182304 ldr r3, [pc, #0x1d4] */
/* @0x182308 ldr r1, [pc, #0x1e8] */
/* @0x18230c ldr r2, [r4, #0x4] */
/* @0x182310 ldr r0, [r6, r3] */
/* @0x182314 add r1, pc, r1 */
/* @0x182318 ldr r3, [r4, #0x8] */
/* @0x18231c ldr r8, [r0] */
/* @0x182320 ldr r12, [r8] */
/* @0x182324 mov r0, r8 */
/* @0x182328 ldr r12, [r12, #0xc] */
/* @0x18232c blx r12 */
/* @0x182330 ldr r9, [r4, #0x28] */
/* @0x182334 cmp r9, #0 */
/* @0x182338 beq 0x18245c <_Z14_CreateTextureP7Textureb10eMipEnable+0x358> */
/* @0x18233c ldr r3, [r8] */
/* @0x182340 mov r0, r8 */
/* @0x182344 ldr r1, [pc, #0x1b0] */
/* @0x182348 ldr r2, [r4, #0x4] */
/* @0x18234c ldr r12, [r3, #0xc] */
/* @0x182350 add r1, pc, r1 */
/* @0x182354 ldr r3, [r4, #0x8] */
/* @0x182358 blx r12 */
/* @0x18235c ldr r3, [pc, #0x184] */
/* @0x182360 mov r0, #1 */
/* @0x182364 add r1, r4, #20 */
/* @0x182368 ldr r8, [r4, #0x28] */
/* @0x18236c ldr r3, [r6, r3] */
/* @0x182370 ldr r3, [r3] */
/* @0x182374 blx r3 */
/* @0x182378 ldr r3, [pc, #0x16c] */
/* @0x18237c movw r0, #0xde1 */
/* @0x182380 ldr r1, [r4, #0x14] */
/* @0x182384 ldr r3, [r6, r3] */
/* @0x182388 ldr r3, [r3] */
/* @0x18238c blx r3 */
/* @0x182390 ldr r2, [pc, #0x158] */
/* @0x182394 ldr r9, [r4, #0x8] */
/* @0x182398 movw r12, #0x1908 */
/* @0x18239c ldr r3, [r4, #0x4] */
/* @0x1823a0 mov r1, r5 */
/* @0x1823a4 ldr r0, [r6, r2] */
/* @0x1823a8 movw lr, #0x1401 */
/* @0x1823ac mov r2, r12 */
/* @0x1823b0 str r8, [sp, #0x10] */
/* @0x1823b4 str r5, [sp, #0x4] */
/* @0x1823b8 ldr r5, [r0] */
/* @0x1823bc movw r0, #0xde1 */
/* @0x1823c0 str r9, [sp] */
/* @0x1823c4 str r12, [sp, #0x8] */
/* @0x1823c8 str lr, [sp, #0xc] */
/* @0x1823cc blx r5 */
/* @0x1823d0 ldr r3, [r4, #0x10] */
/* @0x1823d4 cmp r7, #1 */
/* @0x1823d8 orr r2, r3, #64 */
/* @0x1823dc str r2, [r4, #0x10] */
/* @0x1823e0 beq 0x1823f4 <_Z14_CreateTextureP7Textureb10eMipEnable+0x2f0> */
/* @0x1823e4 cmp r7, #2 */
/* @0x1823e8 bne 0x182188 <_Z14_CreateTextureP7Textureb10eMipEnable+0x84> */
/* @0x1823ec tst r3, #16 */
/* @0x1823f0 beq 0x182188 <_Z14_CreateTextureP7Textureb10eMipEnable+0x84> */
/* @0x1823f4 ldr r1, [r4, #0x4] */
/* @0x1823f8 mov r0, r4 */
/* @0x1823fc ldr r2, [r4, #0x8] */
/* @0x182400 mov r3, #4 */
/* @0x182404 str r8, [sp] */
/* @0x182408 bl 0x181db0 <_Z12GenerateMipsP7TextureiiiPc> */
/* @0x18240c b 0x182188 <_Z14_CreateTextureP7Textureb10eMipEnable+0x84> */
/* @0x182410 mov r2, #11 */
/* @0x182414 str r2, [r4] */
/* @0x182418 ldr lr, [r6, r3] */
/* @0x18241c mov r0, #0 */
/* @0x182420 movw r12, #0x1908 */
/* @0x182424 add r5, r5, #16 */
/* @0x182428 mov r1, r0 */
/* @0x18242c str r5, [sp, #0x10] */
/* @0x182430 str r8, [sp] */
/* @0x182434 mov r3, r9 */
/* @0x182438 ldr r5, [lr] */
/* @0x18243c mov r2, r12 */
/* @0x182440 movw lr, #0x8033 */
/* @0x182444 str r0, [sp, #0x4] */
/* @0x182448 str r12, [sp, #0x8] */
/* @0x18244c movw r0, #0xde1 */
/* @0x182450 str lr, [sp, #0xc] */
/* @0x182454 blx r5 */
/* @0x182458 b 0x182188 <_Z14_CreateTextureP7Textureb10eMipEnable+0x84> */
/* @0x18245c ldr r3, [pc, #0x84] */
/* @0x182460 add r1, r4, #20 */
/* @0x182464 mov r0, #1 */
/* @0x182468 ldr r3, [r6, r3] */
/* @0x18246c ldr r3, [r3] */
/* @0x182470 blx r3 */
/* @0x182474 ldr r3, [pc, #0x70] */
/* @0x182478 ldr r1, [r4, #0x14] */
/* @0x18247c movw r0, #0xde1 */
/* @0x182480 ldr r3, [r6, r3] */
/* @0x182484 ldr r3, [r3] */
/* @0x182488 blx r3 */
/* @0x18248c ldr r2, [pc, #0x5c] */
/* @0x182490 ldr r7, [r4, #0x8] */
/* @0x182494 movw r12, #0x1908 */
/* @0x182498 ldr r3, [r4, #0x4] */
/* @0x18249c mov r1, r9 */
/* @0x1824a0 ldr r0, [r6, r2] */
/* @0x1824a4 movw lr, #0x1401 */
/* @0x1824a8 mov r2, r12 */
/* @0x1824ac str r9, [sp, #0x4] */
/* @0x1824b0 str r9, [sp, #0x10] */
/* @0x1824b4 ldr r5, [r0] */
/* @0x1824b8 movw r0, #0xde1 */
/* @0x1824bc str r7, [sp] */
/* @0x1824c0 str r12, [sp, #0x8] */
/* @0x1824c4 str lr, [sp, #0xc] */
/* @0x1824c8 blx r5 */
/* @0x1824cc mov r0, r4 */
/* @0x1824d0 ldmib r4, {r1, r2} */
/* @0x1824d4 bl 0x1814a0 <_Z21_SetupRenderTargetFBOP7Textureii> */
/* @0x1824d8 b 0x182188 <_Z14_CreateTextureP7Textureb10eMipEnable+0x84> */
/* @0x1824dc eoreq pc, r6, r4, lsr r11 */
/* @0x1824e0 .word 0xffffbac4 */
/* @0x1824e4 andseq r9, r12, r0, lsl #19 */
/* @0x1824e8 .word 0xffffbb28 */
/* @0x1824ec .word 0xffffbb20 */
/* @0x1824f0 .word 0xffffbb2c */
/* @0x1824f4 andseq r9, r12, r4, lsl #16 */
/* @0x1824f8 andseq r9, r12, r4, lsr #15 */
/* @0x1824fc andseq r9, r12, r12, ror r7 */

/* ── FUNC 0x182500 · _CreateTextureIfInvalid(Texture*, bool, eMipEnable) · size=152 · insn=38 */
/* @0x182500 push {r4, r5, r6, lr} */
/* @0x182504 subs r5, r0, #0 */
/* @0x182508 mov r6, r1 */
/* @0x18250c mov r4, r2 */
/* @0x182510 popeq {r4, r5, r6, pc} */
/* @0x182514 cmn r2, #1 */
/* @0x182518 ldr r3, [r5, #0x14] */
/* @0x18251c beq 0x182570 <_Z23_CreateTextureIfInvalidP7Textureb10eMipEnable+0x70> */
/* @0x182520 cmp r2, #1 */
/* @0x182524 beq 0x18257c <_Z23_CreateTextureIfInvalidP7Textureb10eMipEnable+0x7c> */
/* @0x182528 cmp r2, #0 */
/* @0x18252c bne 0x182558 <_Z23_CreateTextureIfInvalidP7Textureb10eMipEnable+0x58> */
/* @0x182530 ldr r2, [r5, #0x10] */
/* @0x182534 tst r2, #32 */
/* @0x182538 beq 0x182570 <_Z23_CreateTextureIfInvalidP7Textureb10eMipEnable+0x70> */
/* @0x18253c mov r0, r5 */
/* @0x182540 bl 0x1811bc <_ZN8Graphics12FlushTextureEPv> */
/* @0x182544 mov r0, r5 */
/* @0x182548 mov r1, r6 */
/* @0x18254c mov r2, r4 */
/* @0x182550 pop {r4, r5, r6, lr} */
/* @0x182554 b 0x182104 <_Z14_CreateTextureP7Textureb10eMipEnable> */
/* @0x182558 cmp r2, #2 */
/* @0x18255c bne 0x182570 <_Z23_CreateTextureIfInvalidP7Textureb10eMipEnable+0x70> */
/* @0x182560 ldr r2, [r5, #0x10] */
/* @0x182564 and r2, r2, #48 */
/* @0x182568 cmp r2, #16 */
/* @0x18256c beq 0x18253c <_Z23_CreateTextureIfInvalidP7Textureb10eMipEnable+0x3c> */
/* @0x182570 cmn r3, #1 */
/* @0x182574 popne {r4, r5, r6, pc} */
/* @0x182578 b 0x18253c <_Z23_CreateTextureIfInvalidP7Textureb10eMipEnable+0x3c> */
/* @0x18257c ldr r2, [r5, #0x10] */
/* @0x182580 and r2, r2, #96 */
/* @0x182584 cmp r2, #64 */
/* @0x182588 beq 0x18253c <_Z23_CreateTextureIfInvalidP7Textureb10eMipEnable+0x3c> */
/* @0x18258c cmn r3, #1 */
/* @0x182590 popne {r4, r5, r6, pc} */
/* @0x182594 b 0x18253c <_Z23_CreateTextureIfInvalidP7Textureb10eMipEnable+0x3c> */

/* ── FUNC 0x182598 · _InvalidateTextureState() · size=260 · insn=65 */
/* @0x182598 push {r3, r4, r5, lr} */
/* @0x18259c ldr r4, [pc, #0xd4] */
/* @0x1825a0 ldr r3, [pc, #0xd4] */
/* @0x1825a4 add r4, pc, r4 */
/* @0x1825a8 ldr r5, [r4, r3] */
/* @0x1825ac ldr r3, [r5] */
/* @0x1825b0 cmp r3, #0 */
/* @0x1825b4 beq 0x18263c <_Z23_InvalidateTextureStatev+0xa4> */
/* @0x1825b8 cmp r3, #1 */
/* @0x1825bc popne {r3, r4, r5, pc} */
/* @0x1825c0 ldr r2, [pc, #0xb8] */
/* @0x1825c4 ldr r1, [pc, #0xb8] */
/* @0x1825c8 ldr r3, [pc, #0xb8] */
/* @0x1825cc ldr r2, [r4, r2] */
/* @0x1825d0 ldr r5, [r4, r1] */
/* @0x1825d4 ldr r3, [r4, r3] */
/* @0x1825d8 ldr r2, [r2] */
/* @0x1825dc ldr r0, [r5] */
/* @0x1825e0 ldr r1, [r3, r2, lsl #2] */
/* @0x1825e4 cmp r1, r0 */
/* @0x1825e8 beq 0x182600 <_Z23_InvalidateTextureStatev+0x68> */
/* @0x1825ec ldr r1, [pc, #0x98] */
/* @0x1825f0 ldr r1, [r4, r1] */
/* @0x1825f4 ldr r12, [r1] */
/* @0x1825f8 add r12, r12, #1 */
/* @0x1825fc str r12, [r1] */
/* @0x182600 cmp r0, #0 */
/* @0x182604 mov r1, #0 */
/* @0x182608 str r1, [r3, r2, lsl #2] */
/* @0x18260c popeq {r3, r4, r5, pc} */
/* @0x182610 mvn r2, #0 */
/* @0x182614 bl 0x182500 <_Z23_CreateTextureIfInvalidP7Textureb10eMipEnable> */
/* @0x182618 ldr r3, [pc, #0x70] */
/* @0x18261c ldr r2, [r5] */
/* @0x182620 movw r0, #0xde1 */
/* @0x182624 ldr r3, [r4, r3] */
/* @0x182628 ldr r1, [r2, #0x14] */
/* @0x18262c ldr r3, [r3] */
/* @0x182630 blx r3 */
/* @0x182634 pop {r3, r4, r5, lr} */
/* @0x182638 b 0x180b28 <_Z26_SetCurrentTextureSettingsv> */
/* @0x18263c ldr r12, [pc, #0x44] */
/* @0x182640 movw r0, #0xde1 */
/* @0x182644 ldr r1, [pc, #0x48] */
/* @0x182648 ldr r2, [pc, #0x48] */
/* @0x18264c ldr r12, [r4, r12] */
/* @0x182650 str r3, [r12] */
/* @0x182654 ldr r1, [r4, r1] */
/* @0x182658 str r3, [r1] */
/* @0x18265c ldr r3, [r4, r2] */
/* @0x182660 ldr r3, [r3] */
/* @0x182664 blx r3 */
/* @0x182668 ldr r3, [r5] */
/* @0x18266c cmp r3, #1 */
/* @0x182670 popne {r3, r4, r5, pc} */
/* @0x182674 b 0x1825c0 <_Z23_InvalidateTextureStatev+0x28> */
/* @0x182678 eoreq pc, r6, r12, lsr #13 */
/* @0x18267c .word 0xffffe7b8 */
/* @0x182680 .word 0xffffe808 */
/* @0x182684 .word 0xffffe8fc */
/* @0x182688 .word 0xffffe8e8 */
/* @0x18268c .word 0xffffe740 */
/* @0x182690 .word 0xffffbb20 */
/* @0x182694 .word 0xffffe8f4 */
/* @0x182698 .word 0xffffbad0 */

/* ── FUNC 0x18269c · Graphics::CreateTexture(int, int, int, eTextureFlags, eTextureFormat) · size=520 · insn=130 */
/* @0x18269c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1826a0 cmp r1, #0 */
/* @0x1826a4 cmpne r0, #0 */
/* @0x1826a8 sub sp, sp, #28 */
/* @0x1826ac ldr r7, [pc, #0x1d4] */
/* @0x1826b0 mov r5, r1 */
/* @0x1826b4 movne r6, #0 */
/* @0x1826b8 moveq r6, #1 */
/* @0x1826bc add r7, pc, r7 */
/* @0x1826c0 mov r11, r2 */
/* @0x1826c4 mov r10, r3 */
/* @0x1826c8 mov r8, r0 */
/* @0x1826cc ldr r9, [sp, #0x40] */
/* @0x1826d0 beq 0x18282c <_ZN8Graphics13CreateTextureEiii13eTextureFlags14eTextureFormat+0x190> */
/* @0x1826d4 bl 0x181320 <_Z11GetPOW2Sizei> */
/* @0x1826d8 mov r4, r0 */
/* @0x1826dc mov r0, r5 */
/* @0x1826e0 bl 0x181320 <_Z11GetPOW2Sizei> */
/* @0x1826e4 ldr r3, [pc, #0x1a0] */
/* @0x1826e8 ldr r3, [r7, r3] */
/* @0x1826ec ldrb r3, [r3] */
/* @0x1826f0 cmp r3, #0 */
/* @0x1826f4 moveq r8, r4 */
/* @0x1826f8 moveq r5, r0 */
/* @0x1826fc mov r0, #56 */
/* @0x182700 bl 0x27c524 <_Znwj> */
/* @0x182704 ldr r3, [pc, #0x184] */
/* @0x182708 mvn r1, #0 */
/* @0x18270c str r6, [r0, #0x24] */
/* @0x182710 mov r4, r0 */
/* @0x182714 str r6, [r0, #0x28] */
/* @0x182718 str r6, [r0, #0x2c] */
/* @0x18271c str r6, [r0, #0x30] */
/* @0x182720 str r6, [r0, #0x10] */
/* @0x182724 ldr r3, [r7, r3] */
/* @0x182728 str r8, [r0, #0x4] */
/* @0x18272c str r5, [r0, #0x8] */
/* @0x182730 ldr r2, [r3] */
/* @0x182734 str r11, [r0, #0xc] */
/* @0x182738 str r0, [r3] */
/* @0x18273c str r2, [r0, #0x34] */
/* @0x182740 str r9, [r0] */
/* @0x182744 str r1, [r0, #0x14] */
/* @0x182748 str r1, [r0, #0x18] */
/* @0x18274c str r1, [r0, #0x1c] */
/* @0x182750 str r1, [r0, #0x20] */
/* @0x182754 bl 0x182598 <_Z23_InvalidateTextureStatev> */
/* @0x182758 ands r3, r10, #2 */
/* @0x18275c bne 0x182794 <_ZN8Graphics13CreateTextureEiii13eTextureFlags14eTextureFormat+0xf8> */
/* @0x182760 mul r5, r5, r8 */
/* @0x182764 ldr r1, [pc, #0x128] */
/* @0x182768 movw r2, #0x506 */
/* @0x18276c add r1, pc, r1 */
/* @0x182770 add r0, r5, #4 */
/* @0x182774 lsl r0, r0, #2 */
/* @0x182778 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x18277c mov r3, r0 */
/* @0x182780 mov r0, r4 */
/* @0x182784 str r3, [r4, #0x24] */
/* @0x182788 str r3, [r4, #0x28] */
/* @0x18278c add sp, sp, #28 */
/* @0x182790 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x182794 ldr r3, [pc, #0xfc] */
/* @0x182798 add r1, r4, #20 */
/* @0x18279c str r6, [r4, #0x24] */
/* @0x1827a0 mov r0, #1 */
/* @0x1827a4 str r6, [r4, #0x28] */
/* @0x1827a8 ldr r3, [r7, r3] */
/* @0x1827ac ldr r3, [r3] */
/* @0x1827b0 blx r3 */
/* @0x1827b4 ldr r3, [pc, #0xe0] */
/* @0x1827b8 ldr r1, [r4, #0x14] */
/* @0x1827bc movw r0, #0xde1 */
/* @0x1827c0 ldr r3, [r7, r3] */
/* @0x1827c4 ldr r3, [r3] */
/* @0x1827c8 blx r3 */
/* @0x1827cc ldr r3, [pc, #0xcc] */
/* @0x1827d0 movw r12, #0x1908 */
/* @0x1827d4 movw lr, #0x1401 */
/* @0x1827d8 mov r2, r12 */
/* @0x1827dc mov r1, r6 */
/* @0x1827e0 ldr r7, [r7, r3] */
/* @0x1827e4 movw r0, #0xde1 */
/* @0x1827e8 mov r3, r8 */
/* @0x1827ec str r5, [sp] */
/* @0x1827f0 str r6, [sp, #0x4] */
/* @0x1827f4 ldr r7, [r7] */
/* @0x1827f8 str r12, [sp, #0x8] */
/* @0x1827fc str lr, [sp, #0xc] */
/* @0x182800 str r6, [sp, #0x10] */
/* @0x182804 blx r7 */
/* @0x182808 mov r0, r4 */
/* @0x18280c bl 0x180aec <_Z20_SetTextureNPOTFlagsP7Texture> */
/* @0x182810 mov r0, r4 */
/* @0x182814 mov r1, r8 */
/* @0x182818 mov r2, r5 */
/* @0x18281c bl 0x1814a0 <_Z21_SetupRenderTargetFBOP7Textureii> */
/* @0x182820 mov r0, r4 */
/* @0x182824 add sp, sp, #28 */
/* @0x182828 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x18282c mov r0, #56 */
/* @0x182830 bl 0x27c524 <_Znwj> */
/* @0x182834 ldr r1, [pc, #0x54] */
/* @0x182838 mov r2, #0 */
/* @0x18283c mov r3, r0 */
/* @0x182840 str r2, [r0, #0x4] */
/* @0x182844 str r2, [r3, #0x8] */
/* @0x182848 str r2, [r3, #0xc] */
/* @0x18284c str r2, [r3, #0x24] */
/* @0x182850 str r2, [r3, #0x28] */
/* @0x182854 str r2, [r3, #0x1c] */
/* @0x182858 str r2, [r3, #0x18] */
/* @0x18285c str r2, [r3, #0x14] */
/* @0x182860 str r2, [r3, #0x2c] */
/* @0x182864 str r2, [r3, #0x30] */
/* @0x182868 str r2, [r3, #0x10] */
/* @0x18286c ldr r2, [r7, r1] */
/* @0x182870 ldr r1, [r2] */
/* @0x182874 str r3, [r2] */
/* @0x182878 str r9, [r3] */
/* @0x18287c str r1, [r3, #0x34] */
/* @0x182880 add sp, sp, #28 */
/* @0x182884 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x182888 mlaeq r6, r4, r5, pc */
/* @0x18288c .word 0xffffe7cc */
/* @0x182890 .word 0xffffe664 */
/* @0x182894 andseq r9, r12, r0, asr r2 */
/* @0x182898 .word 0xffffbb28 */
/* @0x18289c .word 0xffffbb20 */
/* @0x1828a0 .word 0xffffbb2c */
