/* libyoyo.so 覆盖卡组 0080
 * 函数 0x1465f0..0x147d5c，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1465f0 · F_GPUSetZTestEnable(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x1465f0 cmp r3, #1 */
/* @0x1465f4 mov r2, #0 */
/* @0x1465f8 push {r4, lr} */
/* @0x1465fc mov r1, r2 */
/* @0x146600 mov r4, r3 */
/* @0x146604 movt r2, #0xbff0 */
/* @0x146608 str r1, [r0, #0xc] */
/* @0x14660c stm r0, {r1, r2} */
/* @0x146610 ldr r0, [sp, #0x8] */
/* @0x146614 beq 0x146628 <_Z19F_GPUSetZTestEnableR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x146618 ldr r0, [pc, #0x24] */
/* @0x14661c pop {r4, lr} */
/* @0x146620 add r0, pc, r0 */
/* @0x146624 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x146628 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14662c ldr r3, [pc, #0x14] */
/* @0x146630 mov r1, r4 */
/* @0x146634 pop {r4, lr} */
/* @0x146638 mov r2, r0 */
/* @0x14663c ldr r0, [pc, r3] */
/* @0x146640 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x146644 ldrheq r11, [pc], -r12 */
/* @0x146648 .word 0x002a76bc */

/* ── FUNC 0x14664c · F_GPUSetZFunc(RValue&, CInstance*, CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x14664c cmp r3, #1 */
/* @0x146650 push {r3, lr} */
/* @0x146654 mov r3, #0 */
/* @0x146658 mov r1, r3 */
/* @0x14665c movt r3, #0xbff0 */
/* @0x146660 str r1, [r0, #0xc] */
/* @0x146664 stm r0, {r1, r3} */
/* @0x146668 ldr r0, [sp, #0x8] */
/* @0x14666c beq 0x146680 <_Z13F_GPUSetZFuncR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x146670 ldr r0, [pc, #0x24] */
/* @0x146674 pop {r3, lr} */
/* @0x146678 add r0, pc, r0 */
/* @0x14667c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x146680 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x146684 ldr r3, [pc, #0x14] */
/* @0x146688 mov r1, #9 */
/* @0x14668c mov r2, r0 */
/* @0x146690 ldr r0, [pc, r3] */
/* @0x146694 pop {r3, lr} */
/* @0x146698 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x14669c ldrheq r11, [pc], -r12 */
/* @0x1466a0 eoreq r7, r10, r8, ror #12 */

/* ── FUNC 0x1466a4 · F_GPUSetZWriteEnable(RValue&, CInstance*, CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x1466a4 cmp r3, #1 */
/* @0x1466a8 push {r3, lr} */
/* @0x1466ac mov r3, #0 */
/* @0x1466b0 mov r1, r3 */
/* @0x1466b4 movt r3, #0xbff0 */
/* @0x1466b8 str r1, [r0, #0xc] */
/* @0x1466bc stm r0, {r1, r3} */
/* @0x1466c0 ldr r0, [sp, #0x8] */
/* @0x1466c4 beq 0x1466d8 <_Z20F_GPUSetZWriteEnableR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x1466c8 ldr r0, [pc, #0x24] */
/* @0x1466cc pop {r3, lr} */
/* @0x1466d0 add r0, pc, r0 */
/* @0x1466d4 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1466d8 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1466dc ldr r3, [pc, #0x14] */
/* @0x1466e0 mov r1, #4 */
/* @0x1466e4 mov r2, r0 */
/* @0x1466e8 ldr r0, [pc, r3] */
/* @0x1466ec pop {r3, lr} */
/* @0x1466f0 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1466f4 mulseq pc, r12, r0 */
/* @0x1466f8 eoreq r7, r10, r0, lsl r6 */

/* ── FUNC 0x1466fc · F_GPUSetCullmode(RValue&, CInstance*, CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x1466fc cmp r3, #1 */
/* @0x146700 push {r3, lr} */
/* @0x146704 mov r3, #0 */
/* @0x146708 mov r1, r3 */
/* @0x14670c movt r3, #0xbff0 */
/* @0x146710 str r1, [r0, #0xc] */
/* @0x146714 stm r0, {r1, r3} */
/* @0x146718 ldr r0, [sp, #0x8] */
/* @0x14671c beq 0x146730 <_Z16F_GPUSetCullmodeR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x146720 ldr r0, [pc, #0x24] */
/* @0x146724 pop {r3, lr} */
/* @0x146728 add r0, pc, r0 */
/* @0x14672c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x146730 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x146734 ldr r3, [pc, #0x14] */
/* @0x146738 mov r1, #8 */
/* @0x14673c mov r2, r0 */
/* @0x146740 ldr r0, [pc, r3] */
/* @0x146744 pop {r3, lr} */
/* @0x146748 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x14674c andseq r11, pc, r0, lsr #1 */
/* @0x146750 .word 0x002a75b8 */

/* ── FUNC 0x146754 · F_GPUSetBlendMode(RValue&, CInstance*, CInstance*, int, RValue*) · size=384 · insn=96 */
/* @0x146754 push {r4, r5, r6, lr} */
/* @0x146758 mov r1, #0 */
/* @0x14675c ldr r5, [pc, #0x164] */
/* @0x146760 cmp r3, #1 */
/* @0x146764 mov r4, r1 */
/* @0x146768 mov r6, r3 */
/* @0x14676c movt r1, #0xbff0 */
/* @0x146770 str r4, [r0, #0xc] */
/* @0x146774 str r1, [r0, #0x4] */
/* @0x146778 add r5, pc, r5 */
/* @0x14677c str r4, [r0] */
/* @0x146780 mov r1, r4 */
/* @0x146784 ldr r0, [sp, #0x10] */
/* @0x146788 beq 0x14679c <_Z17F_GPUSetBlendModeR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x14678c ldr r0, [pc, #0x138] */
/* @0x146790 pop {r4, r5, r6, lr} */
/* @0x146794 add r0, pc, r0 */
/* @0x146798 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x14679c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1467a0 ldr r3, [pc, #0x128] */
/* @0x1467a4 mov r1, #6 */
/* @0x1467a8 cmp r0, #2 */
/* @0x1467ac beq 0x146854 <_Z17F_GPUSetBlendModeR6RValueP9CInstanceS2_iPS_+0x100> */
/* @0x1467b0 cmp r0, #3 */
/* @0x1467b4 beq 0x146814 <_Z17F_GPUSetBlendModeR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x1467b8 ldr r5, [r5, r3] */
/* @0x1467bc cmp r0, #1 */
/* @0x1467c0 mov r2, #5 */
/* @0x1467c4 mov r0, r5 */
/* @0x1467c8 beq 0x146894 <_Z17F_GPUSetBlendModeR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x1467cc bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1467d0 mov r0, r5 */
/* @0x1467d4 mov r1, #7 */
/* @0x1467d8 mov r2, #6 */
/* @0x1467dc bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1467e0 mov r0, r5 */
/* @0x1467e4 mov r1, #34 */
/* @0x1467e8 mov r2, #5 */
/* @0x1467ec bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1467f0 mov r0, r5 */
/* @0x1467f4 mov r1, #35 */
/* @0x1467f8 mov r2, #6 */
/* @0x1467fc bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x146800 mov r0, r5 */
/* @0x146804 mov r2, r4 */
/* @0x146808 mov r1, #33 */
/* @0x14680c pop {r4, r5, r6, lr} */
/* @0x146810 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x146814 ldr r5, [r5, r3] */
/* @0x146818 mov r2, r6 */
/* @0x14681c mov r0, r5 */
/* @0x146820 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x146824 mov r0, r5 */
/* @0x146828 mov r1, #7 */
/* @0x14682c mov r2, #4 */
/* @0x146830 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x146834 mov r0, r5 */
/* @0x146838 mov r2, r6 */
/* @0x14683c mov r1, #34 */
/* @0x146840 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x146844 mov r0, r5 */
/* @0x146848 mov r1, #35 */
/* @0x14684c mov r2, #4 */
/* @0x146850 b 0x1467fc <_Z17F_GPUSetBlendModeR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x146854 ldr r5, [r5, r3] */
/* @0x146858 mov r2, #5 */
/* @0x14685c mov r0, r5 */
/* @0x146860 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x146864 mov r0, r5 */
/* @0x146868 mov r1, #7 */
/* @0x14686c mov r2, #4 */
/* @0x146870 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x146874 mov r0, r5 */
/* @0x146878 mov r1, #34 */
/* @0x14687c mov r2, #5 */
/* @0x146880 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x146884 mov r0, r5 */
/* @0x146888 mov r1, #35 */
/* @0x14688c mov r2, #4 */
/* @0x146890 b 0x1467fc <_Z17F_GPUSetBlendModeR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x146894 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x146898 mov r0, r5 */
/* @0x14689c mov r1, #7 */
/* @0x1468a0 mov r2, #2 */
/* @0x1468a4 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1468a8 mov r0, r5 */
/* @0x1468ac mov r1, #34 */
/* @0x1468b0 mov r2, #5 */
/* @0x1468b4 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1468b8 mov r0, r5 */
/* @0x1468bc mov r1, #35 */
/* @0x1468c0 mov r2, #2 */
/* @0x1468c4 b 0x1467fc <_Z17F_GPUSetBlendModeR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x1468c8 .word 0x002ab4d8 */
/* @0x1468cc andseq r11, pc, r0, ror r0 */
/* @0x1468d0 .word 0xffffc0a8 */

/* ── FUNC 0x1468d4 · F_GPUSetAlphaTestEnable(RValue&, CInstance*, CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x1468d4 cmp r3, #1 */
/* @0x1468d8 push {r3, lr} */
/* @0x1468dc mov r3, #0 */
/* @0x1468e0 mov r1, r3 */
/* @0x1468e4 movt r3, #0xbff0 */
/* @0x1468e8 str r1, [r0, #0xc] */
/* @0x1468ec stm r0, {r1, r3} */
/* @0x1468f0 ldr r0, [sp, #0x8] */
/* @0x1468f4 beq 0x146908 <_Z23F_GPUSetAlphaTestEnableR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x1468f8 ldr r0, [pc, #0x24] */
/* @0x1468fc pop {r3, lr} */
/* @0x146900 add r0, pc, r0 */
/* @0x146904 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x146908 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x14690c ldr r3, [pc, #0x14] */
/* @0x146910 mov r1, #5 */
/* @0x146914 mov r2, r0 */
/* @0x146918 ldr r0, [pc, r3] */
/* @0x14691c pop {r3, lr} */
/* @0x146920 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x146924 andseq r10, pc, r0, asr #30 */
/* @0x146928 eoreq r7, r10, r0, ror #7 */

/* ── FUNC 0x14692c · F_GPUSetAlphaTestRef(RValue&, CInstance*, CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x14692c cmp r3, #1 */
/* @0x146930 push {r3, lr} */
/* @0x146934 mov r3, #0 */
/* @0x146938 mov r1, r3 */
/* @0x14693c movt r3, #0xbff0 */
/* @0x146940 str r1, [r0, #0xc] */
/* @0x146944 stm r0, {r1, r3} */
/* @0x146948 ldr r0, [sp, #0x8] */
/* @0x14694c beq 0x146960 <_Z20F_GPUSetAlphaTestRefR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x146950 ldr r0, [pc, #0x24] */
/* @0x146954 pop {r3, lr} */
/* @0x146958 add r0, pc, r0 */
/* @0x14695c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x146960 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x146964 ldr r3, [pc, #0x14] */
/* @0x146968 mov r1, #10 */
/* @0x14696c mov r2, r0 */
/* @0x146970 ldr r0, [pc, r3] */
/* @0x146974 pop {r3, lr} */
/* @0x146978 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x14697c andseq r10, pc, r8, ror #29 */
/* @0x146980 eoreq r7, r10, r8, lsl #7 */

/* ── FUNC 0x146984 · F_GPUSetAlphaTestFunc(RValue&, CInstance*, CInstance*, int, RValue*) · size=88 · insn=22 */
/* @0x146984 cmp r3, #1 */
/* @0x146988 push {r3, lr} */
/* @0x14698c mov r3, #0 */
/* @0x146990 mov r1, r3 */
/* @0x146994 movt r3, #0xbff0 */
/* @0x146998 str r1, [r0, #0xc] */
/* @0x14699c stm r0, {r1, r3} */
/* @0x1469a0 ldr r0, [sp, #0x8] */
/* @0x1469a4 beq 0x1469b8 <_Z21F_GPUSetAlphaTestFuncR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x1469a8 ldr r0, [pc, #0x24] */
/* @0x1469ac pop {r3, lr} */
/* @0x1469b0 add r0, pc, r0 */
/* @0x1469b4 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1469b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1469bc ldr r3, [pc, #0x14] */
/* @0x1469c0 mov r1, #11 */
/* @0x1469c4 mov r2, r0 */
/* @0x1469c8 ldr r0, [pc, r3] */
/* @0x1469cc pop {r3, lr} */
/* @0x1469d0 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x1469d4 andseq r10, pc, r12, ror #29 */
/* @0x1469d8 eoreq r7, r10, r0, lsr r3 */

/* ── FUNC 0x1469dc · F_D3DGetMatrix(RValue&, CInstance*, CInstance*, int, RValue*) · size=292 · insn=73 */
/* @0x1469dc push {r4, lr} */
/* @0x1469e0 vpush {d8, d9, d10, d11, d12, d13, d14} */
/* @0x1469e4 sub sp, sp, #184 */
/* @0x1469e8 mov r4, r0 */
/* @0x1469ec mov r1, #0 */
/* @0x1469f0 ldr r0, [sp, #0xf8] */
/* @0x1469f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1469f8 cmp r0, #2 */
/* @0x1469fc bhi 0x146ae0 <_Z14F_D3DGetMatrixR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0x146a00 add r1, sp, #120 */
/* @0x146a04 bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf> */
/* @0x146a08 vldr s14, [sp, #124] */
/* @0x146a0c vcvt.f64.f32 d7, s14 */
/* @0x146a10 vldr s26, [sp, #128] */
/* @0x146a14 vldr s24, [sp, #132] */
/* @0x146a18 vldr s22, [sp, #136] */
/* @0x146a1c vldr s20, [sp, #140] */
/* @0x146a20 vldr s18, [sp, #144] */
/* @0x146a24 vldr s16, [sp, #148] */
/* @0x146a28 vldr s0, [sp, #152] */
/* @0x146a2c vldr s2, [sp, #156] */
/* @0x146a30 vldr s4, [sp, #160] */
/* @0x146a34 vldr s6, [sp, #164] */
/* @0x146a38 vldr s8, [sp, #168] */
/* @0x146a3c vldr s10, [sp, #172] */
/* @0x146a40 vldr s12, [sp, #176] */
/* @0x146a44 vstr d7, [sp] */
/* @0x146a48 vldr s14, [sp, #180] */
/* @0x146a4c vcvt.f64.f32 d7, s14 */
/* @0x146a50 vldr s28, [sp, #120] */
/* @0x146a54 mov r0, r4 */
/* @0x146a58 mov r1, #16 */
/* @0x146a5c vcvt.f64.f32 d0, s0 */
/* @0x146a60 vstr d7, [sp, #112] */
/* @0x146a64 vcvt.f64.f32 d1, s2 */
/* @0x146a68 vstr d0, [sp, #56] */
/* @0x146a6c vcvt.f64.f32 d2, s4 */
/* @0x146a70 vstr d1, [sp, #64] */
/* @0x146a74 vcvt.f64.f32 d3, s6 */
/* @0x146a78 vstr d2, [sp, #72] */
/* @0x146a7c vcvt.f64.f32 d4, s8 */
/* @0x146a80 vstr d3, [sp, #80] */
/* @0x146a84 vcvt.f64.f32 d5, s10 */
/* @0x146a88 vstr d4, [sp, #88] */
/* @0x146a8c vcvt.f64.f32 d6, s12 */
/* @0x146a90 vstr d5, [sp, #96] */
/* @0x146a94 vcvt.f64.f32 d7, s28 */
/* @0x146a98 vstr d6, [sp, #104] */
/* @0x146a9c vcvt.f64.f32 d13, s26 */
/* @0x146aa0 vmov r2, r3, d7 */
/* @0x146aa4 vcvt.f64.f32 d12, s24 */
/* @0x146aa8 vstr d13, [sp, #8] */
/* @0x146aac vcvt.f64.f32 d11, s22 */
/* @0x146ab0 vstr d12, [sp, #16] */
/* @0x146ab4 vcvt.f64.f32 d10, s20 */
/* @0x146ab8 vstr d11, [sp, #24] */
/* @0x146abc vcvt.f64.f32 d9, s18 */
/* @0x146ac0 vstr d10, [sp, #32] */
/* @0x146ac4 vcvt.f64.f32 d8, s16 */
/* @0x146ac8 vstr d9, [sp, #40] */
/* @0x146acc vstr d8, [sp, #48] */
/* @0x146ad0 bl 0x120eb4 <_Z11CreateArrayP6RValueiz> */
/* @0x146ad4 add sp, sp, #184 */
/* @0x146ad8 vpop {d8, d9, d10, d11, d12, d13, d14} */
/* @0x146adc pop {r4, pc} */
/* @0x146ae0 ldr r0, [pc, #0x14] */
/* @0x146ae4 mov r1, #1 */
/* @0x146ae8 add r0, pc, r0 */
/* @0x146aec bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x146af0 add sp, sp, #184 */
/* @0x146af4 vpop {d8, d9, d10, d11, d12, d13, d14} */
/* @0x146af8 pop {r4, pc} */
/* @0x146afc ldrsheq r10, [pc], -r4 */

/* ── FUNC 0x146b00 · F_D3DLightGet(RValue&, CInstance*, CInstance*, int, RValue*) · size=404 · insn=101 */
/* @0x146b00 push {r4, r5, lr} */
/* @0x146b04 cmp r3, #1 */
/* @0x146b08 sub sp, sp, #52 */
/* @0x146b0c ldr r4, [pc, #0x160] */
/* @0x146b10 mov r5, r0 */
/* @0x146b14 add r4, pc, r4 */
/* @0x146b18 ldr r0, [sp, #0x40] */
/* @0x146b1c beq 0x146b38 <_Z13F_D3DLightGetR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x146b20 ldr r0, [pc, #0x150] */
/* @0x146b24 add r0, pc, r0 */
/* @0x146b28 mov r1, #0 */
/* @0x146b2c add sp, sp, #52 */
/* @0x146b30 pop {r4, r5, lr} */
/* @0x146b34 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x146b38 mov r1, #0 */
/* @0x146b3c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x146b40 cmp r0, #7 */
/* @0x146b44 mov r3, r0 */
/* @0x146b48 bhi 0x146c64 <_Z13F_D3DLightGetR6RValueP9CInstanceS2_iPS_+0x164> */
/* @0x146b4c ldr r2, [pc, #0x128] */
/* @0x146b50 ldr r2, [r4, r2] */
/* @0x146b54 ldr r1, [r2, r0, lsl #2] */
/* @0x146b58 cmp r1, #0 */
/* @0x146b5c beq 0x146c50 <_Z13F_D3DLightGetR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x146b60 ldr r0, [pc, #0x118] */
/* @0x146b64 lsl r2, r3, #2 */
/* @0x146b68 ldr r0, [r4, r0] */
/* @0x146b6c add r3, r0, r3, lsl #4 */
/* @0x146b70 vmov s13, r1 */
/* @0x146b74 ldr lr, [pc, #0x108] */
/* @0x146b78 ldr r12, [pc, #0x108] */
/* @0x146b7c mov r0, r5 */
/* @0x146b80 vcvt.f64.s32 d7, s13 */
/* @0x146b84 vldr s13, [pc, #228] */
/* @0x146b88 ldr lr, [r4, lr] */
/* @0x146b8c mov r1, #7 */
/* @0x146b90 ldr r12, [r4, r12] */
/* @0x146b94 add lr, lr, r2 */
/* @0x146b98 vldr s12, [lr] */
/* @0x146b9c add r2, r12, r2, lsl #2 */
/* @0x146ba0 vstr d7, [sp] */
/* @0x146ba4 vldr s14, [r3] */
/* @0x146ba8 vcvt.f64.f32 d7, s14 */
/* @0x146bac vstr d7, [sp, #8] */
/* @0x146bb0 vldr s14, [r3, #4] */
/* @0x146bb4 vcvt.f64.f32 d7, s14 */
/* @0x146bb8 vstr d7, [sp, #16] */
/* @0x146bbc vldr s14, [r3, #8] */
/* @0x146bc0 vcvt.f64.f32 d7, s14 */
/* @0x146bc4 vstr d7, [sp, #24] */
/* @0x146bc8 vldr s14, [r3, #12] */
/* @0x146bcc vcvt.f64.f32 d7, s14 */
/* @0x146bd0 vstr d7, [sp, #32] */
/* @0x146bd4 vldr s11, [r2, #4] */
/* @0x146bd8 vmul.f32 s11, s11, s13 */
/* @0x146bdc vldr s14, [r2, #8] */
/* @0x146be0 vldr s10, [r2] */
/* @0x146be4 vldr s15, [r2, #12] */
/* @0x146be8 vmul.f32 s14, s14, s13 */
/* @0x146bec vmul.f32 s15, s15, s13 */
/* @0x146bf0 vmul.f32 s13, s10, s13 */
/* @0x146bf4 vcvt.u32.f32 s11, s11 */
/* @0x146bf8 vcvt.u32.f32 s14, s14 */
/* @0x146bfc vmov r2, s11 */
/* @0x146c00 vcvt.u32.f32 s15, s15 */
/* @0x146c04 vmov r3, s14 */
/* @0x146c08 vcvt.u32.f32 s13, s13 */
/* @0x146c0c vmov lr, s15 */
/* @0x146c10 vmov r12, s13 */
/* @0x146c14 lsl r2, r2, #8 */
/* @0x146c18 vcvt.f64.f32 d7, s12 */
/* @0x146c1c uxth r2, r2 */
/* @0x146c20 uxtb r3, r3 */
/* @0x146c24 orr r3, r2, r3, lsl #16 */
/* @0x146c28 orr lr, r3, lr, lsl #24 */
/* @0x146c2c vmov r2, r3, d7 */
/* @0x146c30 uxtb r12, r12 */
/* @0x146c34 orr r12, lr, r12 */
/* @0x146c38 vmov s13, r12 */
/* @0x146c3c vcvt.f64.u32 d7, s13 */
/* @0x146c40 vstr d7, [sp, #40] */
/* @0x146c44 bl 0x120eb4 <_Z11CreateArrayP6RValueiz> */
/* @0x146c48 add sp, sp, #52 */
/* @0x146c4c pop {r4, r5, pc} */
/* @0x146c50 ldr r0, [pc, #0x34] */
/* @0x146c54 lsl r2, r3, #2 */
/* @0x146c58 ldr r0, [r4, r0] */
/* @0x146c5c add r3, r0, r3, lsl #4 */
/* @0x146c60 b 0x146b70 <_Z13F_D3DLightGetR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x146c64 ldr r0, [pc, #0x24] */
/* @0x146c68 add r0, pc, r0 */
/* @0x146c6c b 0x146b28 <_Z13F_D3DLightGetR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x146c70 cmnmi pc, #0 */
/* @0x146c74 eoreq r11, r10, r12, lsr r1 */
/* @0x146c78 andseq r10, pc, r12, asr #27 */
/* @0x146c7c .word 0xffffd9cc */
/* @0x146c80 .word 0xffffd9d0 */
/* @0x146c84 .word 0xffffd9d4 */
/* @0x146c88 .word 0xffffd9d8 */
/* @0x146c8c .word 0xffffd9dc */
/* @0x146c90 ldrsbeq r10, [pc], -r0 */

/* ── FUNC 0x146c94 · F_D3DBuildMatrixProjPersp(RValue&, CInstance*, CInstance*, int, RValue*) · size=388 · insn=97 */
/* @0x146c94 push {r4, r5, r6, lr} */
/* @0x146c98 vpush {d8, d9, d10, d11, d12, d13, d14} */
/* @0x146c9c sub sp, sp, #184 */
/* @0x146ca0 mov r1, #0 */
/* @0x146ca4 mov r5, r0 */
/* @0x146ca8 ldr r4, [sp, #0x100] */
/* @0x146cac mov r0, r4 */
/* @0x146cb0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x146cb4 mov r1, #1 */
/* @0x146cb8 vmov s17, r0 */
/* @0x146cbc mov r0, r4 */
/* @0x146cc0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x146cc4 mov r1, #2 */
/* @0x146cc8 vmov s16, r0 */
/* @0x146ccc mov r0, r4 */
/* @0x146cd0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x146cd4 mov r1, #3 */
/* @0x146cd8 mov r6, r0 */
/* @0x146cdc mov r0, r4 */
/* @0x146ce0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x146ce4 vcmp.f32 s16, #0 */
/* @0x146ce8 vmrs APSR_nzcv, fpscr */
/* @0x146cec vcmp.f32 s17, #0 */
/* @0x146cf0 movne r2, #0 */
/* @0x146cf4 moveq r2, #1 */
/* @0x146cf8 vmrs APSR_nzcv, fpscr */
/* @0x146cfc orreq r2, r2, #1 */
/* @0x146d00 cmp r2, #0 */
/* @0x146d04 bne 0x146df8 <_Z25F_D3DBuildMatrixProjPerspR6RValueP9CInstanceS2_iPS_+0x164> */
/* @0x146d08 str r0, [sp] */
/* @0x146d0c mov r3, r6 */
/* @0x146d10 add r0, sp, #120 */
/* @0x146d14 vmov r1, s17 */
/* @0x146d18 vmov r2, s16 */
/* @0x146d1c bl 0x27b180 <_ZN8yyMatrix13PerspectiveLHEPS_ffff> */
/* @0x146d20 vldr s14, [sp, #124] */
/* @0x146d24 vcvt.f64.f32 d7, s14 */
/* @0x146d28 vldr s26, [sp, #128] */
/* @0x146d2c vldr s24, [sp, #132] */
/* @0x146d30 vldr s22, [sp, #136] */
/* @0x146d34 vldr s20, [sp, #140] */
/* @0x146d38 vldr s18, [sp, #144] */
/* @0x146d3c vldr s16, [sp, #148] */
/* @0x146d40 vldr s0, [sp, #152] */
/* @0x146d44 vldr s2, [sp, #156] */
/* @0x146d48 vldr s4, [sp, #160] */
/* @0x146d4c vldr s6, [sp, #164] */
/* @0x146d50 vldr s8, [sp, #168] */
/* @0x146d54 vldr s10, [sp, #172] */
/* @0x146d58 vldr s12, [sp, #176] */
/* @0x146d5c vstr d7, [sp] */
/* @0x146d60 vldr s14, [sp, #180] */
/* @0x146d64 vcvt.f64.f32 d7, s14 */
/* @0x146d68 vldr s28, [sp, #120] */
/* @0x146d6c mov r0, r5 */
/* @0x146d70 mov r1, #16 */
/* @0x146d74 vcvt.f64.f32 d0, s0 */
/* @0x146d78 vstr d7, [sp, #112] */
/* @0x146d7c vcvt.f64.f32 d1, s2 */
/* @0x146d80 vstr d0, [sp, #56] */
/* @0x146d84 vcvt.f64.f32 d2, s4 */
/* @0x146d88 vstr d1, [sp, #64] */
/* @0x146d8c vcvt.f64.f32 d3, s6 */
/* @0x146d90 vstr d2, [sp, #72] */
/* @0x146d94 vcvt.f64.f32 d4, s8 */
/* @0x146d98 vstr d3, [sp, #80] */
/* @0x146d9c vcvt.f64.f32 d5, s10 */
/* @0x146da0 vstr d4, [sp, #88] */
/* @0x146da4 vcvt.f64.f32 d6, s12 */
/* @0x146da8 vstr d5, [sp, #96] */
/* @0x146dac vcvt.f64.f32 d7, s28 */
/* @0x146db0 vstr d6, [sp, #104] */
/* @0x146db4 vcvt.f64.f32 d13, s26 */
/* @0x146db8 vmov r2, r3, d7 */
/* @0x146dbc vcvt.f64.f32 d12, s24 */
/* @0x146dc0 vstr d13, [sp, #8] */
/* @0x146dc4 vcvt.f64.f32 d11, s22 */
/* @0x146dc8 vstr d12, [sp, #16] */
/* @0x146dcc vcvt.f64.f32 d10, s20 */
/* @0x146dd0 vstr d11, [sp, #24] */
/* @0x146dd4 vcvt.f64.f32 d9, s18 */
/* @0x146dd8 vstr d10, [sp, #32] */
/* @0x146ddc vcvt.f64.f32 d8, s16 */
/* @0x146de0 vstr d9, [sp, #40] */
/* @0x146de4 vstr d8, [sp, #48] */
/* @0x146de8 bl 0x120eb4 <_Z11CreateArrayP6RValueiz> */
/* @0x146dec add sp, sp, #184 */
/* @0x146df0 vpop {d8, d9, d10, d11, d12, d13, d14} */
/* @0x146df4 pop {r4, r5, r6, pc} */
/* @0x146df8 ldr r0, [pc, #0x14] */
/* @0x146dfc mov r1, #1 */
/* @0x146e00 add r0, pc, r0 */
/* @0x146e04 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x146e08 add sp, sp, #184 */
/* @0x146e0c vpop {d8, d9, d10, d11, d12, d13, d14} */
/* @0x146e10 pop {r4, r5, r6, pc} */
/* @0x146e14 andseq r10, pc, r4, ror #22 */

/* ── FUNC 0x146e18 · F_D3DBuildMatrixProjPerspFov(RValue&, CInstance*, CInstance*, int, RValue*) · size=400 · insn=100 */
/* @0x146e18 push {r4, r5, r6, lr} */
/* @0x146e1c vpush {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x146e20 sub sp, sp, #184 */
/* @0x146e24 mov r1, #0 */
/* @0x146e28 mov r5, r0 */
/* @0x146e2c ldr r4, [sp, #0x108] */
/* @0x146e30 mov r0, r4 */
/* @0x146e34 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x146e38 mov r1, #1 */
/* @0x146e3c vmov s17, r0 */
/* @0x146e40 mov r0, r4 */
/* @0x146e44 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x146e48 mov r1, #2 */
/* @0x146e4c vmov s16, r0 */
/* @0x146e50 mov r0, r4 */
/* @0x146e54 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x146e58 mov r1, #3 */
/* @0x146e5c mov r6, r0 */
/* @0x146e60 mov r0, r4 */
/* @0x146e64 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x146e68 vcmp.f32 s16, #0 */
/* @0x146e6c vmrs APSR_nzcv, fpscr */
/* @0x146e70 vcmp.f32 s17, #0 */
/* @0x146e74 movne r2, #0 */
/* @0x146e78 moveq r2, #1 */
/* @0x146e7c vmrs APSR_nzcv, fpscr */
/* @0x146e80 orreq r2, r2, #1 */
/* @0x146e84 cmp r2, #0 */
/* @0x146e88 bne 0x146f84 <_Z28F_D3DBuildMatrixProjPerspFovR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x146e8c vldr s15, [pc, #268] */
/* @0x146e90 vmul.f32 s15, s17, s15 */
/* @0x146e94 str r0, [sp] */
/* @0x146e98 mov r3, r6 */
/* @0x146e9c add r0, sp, #120 */
/* @0x146ea0 vmov r2, s16 */
/* @0x146ea4 vmov r1, s15 */
/* @0x146ea8 bl 0x27b068 <_ZN8yyMatrix16PerspectiveFovLHEPS_ffff> */
/* @0x146eac vldr s14, [sp, #180] */
/* @0x146eb0 vcvt.f64.f32 d7, s14 */
/* @0x146eb4 vldr s28, [sp, #124] */
/* @0x146eb8 vldr s26, [sp, #128] */
/* @0x146ebc vldr s24, [sp, #132] */
/* @0x146ec0 vldr s22, [sp, #136] */
/* @0x146ec4 vldr s20, [sp, #140] */
/* @0x146ec8 vldr s18, [sp, #144] */
/* @0x146ecc vldr s16, [sp, #148] */
/* @0x146ed0 vldr s0, [sp, #152] */
/* @0x146ed4 vldr s2, [sp, #156] */
/* @0x146ed8 vldr s4, [sp, #160] */
/* @0x146edc vldr s6, [sp, #164] */
/* @0x146ee0 vldr s8, [sp, #168] */
/* @0x146ee4 vldr s10, [sp, #172] */
/* @0x146ee8 vldr s12, [sp, #176] */
/* @0x146eec vldr s30, [sp, #120] */
/* @0x146ef0 vcvt.f64.f32 d0, s0 */
/* @0x146ef4 vstr d7, [sp, #112] */
/* @0x146ef8 mov r0, r5 */
/* @0x146efc mov r1, #16 */
/* @0x146f00 vcvt.f64.f32 d1, s2 */
/* @0x146f04 vstr d0, [sp, #56] */
/* @0x146f08 vcvt.f64.f32 d2, s4 */
/* @0x146f0c vstr d1, [sp, #64] */
/* @0x146f10 vcvt.f64.f32 d3, s6 */
/* @0x146f14 vstr d2, [sp, #72] */
/* @0x146f18 vcvt.f64.f32 d4, s8 */
/* @0x146f1c vstr d3, [sp, #80] */
/* @0x146f20 vcvt.f64.f32 d5, s10 */
/* @0x146f24 vstr d4, [sp, #88] */
/* @0x146f28 vcvt.f64.f32 d6, s12 */
/* @0x146f2c vstr d5, [sp, #96] */
/* @0x146f30 vcvt.f64.f32 d7, s30 */
/* @0x146f34 vstr d6, [sp, #104] */
/* @0x146f38 vcvt.f64.f32 d14, s28 */
/* @0x146f3c vmov r2, r3, d7 */
/* @0x146f40 vcvt.f64.f32 d13, s26 */
/* @0x146f44 vstr d14, [sp] */
/* @0x146f48 vcvt.f64.f32 d12, s24 */
/* @0x146f4c vstr d13, [sp, #8] */
/* @0x146f50 vcvt.f64.f32 d11, s22 */
/* @0x146f54 vstr d12, [sp, #16] */
/* @0x146f58 vcvt.f64.f32 d10, s20 */
/* @0x146f5c vstr d11, [sp, #24] */
/* @0x146f60 vcvt.f64.f32 d9, s18 */
/* @0x146f64 vstr d10, [sp, #32] */
/* @0x146f68 vcvt.f64.f32 d8, s16 */
/* @0x146f6c vstr d9, [sp, #40] */
/* @0x146f70 vstr d8, [sp, #48] */
/* @0x146f74 bl 0x120eb4 <_Z11CreateArrayP6RValueiz> */
/* @0x146f78 add sp, sp, #184 */
/* @0x146f7c vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x146f80 pop {r4, r5, r6, pc} */
/* @0x146f84 ldr r0, [pc, #0x18] */
/* @0x146f88 mov r1, #1 */
/* @0x146f8c add r0, pc, r0 */
/* @0x146f90 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x146f94 add sp, sp, #184 */
/* @0x146f98 vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x146f9c pop {r4, r5, r6, pc} */
/* @0x146fa0 vstmialo lr, {s30, s31} */
/* @0x146fa4 andseq r10, pc, r4, lsr #20 */

/* ── FUNC 0x146fa8 · F_D3DLightDefineDirection(RValue&, CInstance*, CInstance*, int, RValue*) · size=508 · insn=127 */
/* @0x146fa8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x146fac vpush {d8, d9} */
/* @0x146fb0 sub sp, sp, #4 */
/* @0x146fb4 mov r1, #0 */
/* @0x146fb8 ldr r5, [pc, #0x1cc] */
/* @0x146fbc ldr r6, [sp, #0x38] */
/* @0x146fc0 add r5, pc, r5 */
/* @0x146fc4 mov r0, r6 */
/* @0x146fc8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x146fcc cmp r0, #7 */
/* @0x146fd0 mov r4, r0 */
/* @0x146fd4 bhi 0x147158 <_Z25F_D3DLightDefineDirectionR6RValueP9CInstanceS2_iPS_+0x1b0> */
/* @0x146fd8 mov r1, #1 */
/* @0x146fdc mov r0, r6 */
/* @0x146fe0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x146fe4 mov r1, #2 */
/* @0x146fe8 vmov s19, r0 */
/* @0x146fec mov r0, r6 */
/* @0x146ff0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x146ff4 mov r1, #3 */
/* @0x146ff8 vmov s18, r0 */
/* @0x146ffc mov r0, r6 */
/* @0x147000 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x147004 vmul.f32 s15, s18, s18 */
/* @0x147008 vmla.f32 s15, s19, s19 */
/* @0x14700c vmov s17, r0 */
/* @0x147010 vmla.f32 s15, s17, s17 */
/* @0x147014 vsqrt.f32 s14, s15 */
/* @0x147018 vcmp.f32 s14, s14 */
/* @0x14701c vmrs APSR_nzcv, fpscr */
/* @0x147020 bne 0x147174 <_Z25F_D3DLightDefineDirectionR6RValueP9CInstanceS2_iPS_+0x1cc> */
/* @0x147024 vmov.f32 s16, #1.000000e+00 */
/* @0x147028 mov r0, r6 */
/* @0x14702c mov r1, #4 */
/* @0x147030 ldr r7, [pc, #0x158] */
/* @0x147034 ldr r9, [pc, #0x158] */
/* @0x147038 vdiv.f32 s14, s16, s14 */
/* @0x14703c vmul.f32 s19, s19, s14 */
/* @0x147040 vmul.f32 s18, s18, s14 */
/* @0x147044 vmul.f32 s17, s17, s14 */
/* @0x147048 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14704c vldr s15, [pc, #304] */
/* @0x147050 ldr r1, [pc, #0x140] */
/* @0x147054 ldr r10, [r5, r7] */
/* @0x147058 lsl r7, r4, #4 */
/* @0x14705c add r8, r10, r7 */
/* @0x147060 vneg.f32 s10, s18 */
/* @0x147064 vneg.f32 s11, s17 */
/* @0x147068 orr r3, r0, #-16777216 */
/* @0x14706c uxtb r0, r0 */
/* @0x147070 ubfx r2, r3, #0x8, #0x8 */
/* @0x147074 vmov s12, r0 */
/* @0x147078 vmov s13, r2 */
/* @0x14707c ubfx r2, r3, #0x10, #0x8 */
/* @0x147080 vcvt.f32.s32 s12, s12 */
/* @0x147084 vmov s14, r2 */
/* @0x147088 lsl r2, r4, #2 */
/* @0x14708c add r6, r2, #1 */
/* @0x147090 add r12, r2, #2 */
/* @0x147094 add r2, r2, #3 */
/* @0x147098 lsl r6, r6, #2 */
/* @0x14709c lsl r12, r12, #2 */
/* @0x1470a0 lsl r2, r2, #2 */
/* @0x1470a4 add r0, r10, r6 */
/* @0x1470a8 add r11, r10, r12 */
/* @0x1470ac add r10, r10, r2 */
/* @0x1470b0 vcvt.f32.s32 s13, s13 */
/* @0x1470b4 vcvt.f32.s32 s14, s14 */
/* @0x1470b8 vmul.f32 s12, s12, s15 */
/* @0x1470bc vmul.f32 s13, s13, s15 */
/* @0x1470c0 vmul.f32 s14, s14, s15 */
/* @0x1470c4 vneg.f32 s15, s19 */
/* @0x1470c8 vstr s15, [r8] */
/* @0x1470cc vstr s10, [r0] */
/* @0x1470d0 vstr s11, [r11] */
/* @0x1470d4 vstr s16, [r10] */
/* @0x1470d8 ldr r1, [r5, r1] */
/* @0x1470dc vldr s15, [pc, #164] */
/* @0x1470e0 mov r8, #0 */
/* @0x1470e4 mov r0, r4 */
/* @0x1470e8 add r10, r1, r2 */
/* @0x1470ec vstr s15, [r10] */
/* @0x1470f0 add r10, r1, r12 */
/* @0x1470f4 vstr s15, [r10] */
/* @0x1470f8 add r10, r1, r6 */
/* @0x1470fc add r1, r1, r7 */
/* @0x147100 vstr s15, [r10] */
/* @0x147104 vstr s15, [r1] */
/* @0x147108 ldr r1, [pc, #0x8c] */
/* @0x14710c ldr r10, [r5, r1] */
/* @0x147110 vmov r1, s19 */
/* @0x147114 add r12, r10, r12 */
/* @0x147118 add r2, r10, r2 */
/* @0x14711c add r7, r10, r7 */
/* @0x147120 add r6, r10, r6 */
/* @0x147124 vstr s12, [r7] */
/* @0x147128 vstr s13, [r6] */
/* @0x14712c vstr s14, [r12] */
/* @0x147130 vstr s16, [r2] */
/* @0x147134 vmov r2, s18 */
/* @0x147138 ldr r12, [r5, r9] */
/* @0x14713c str r3, [sp, #0x38] */
/* @0x147140 vmov r3, s17 */
/* @0x147144 str r8, [r12, r4, lsl #2] */
/* @0x147148 add sp, sp, #4 */
/* @0x14714c vpop {d8, d9} */
/* @0x147150 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x147154 b 0x17f658 <_Z28GR_3D_Light_Define_Directionifffj> */
/* @0x147158 ldr r0, [pc, #0x40] */
/* @0x14715c mov r1, #0 */
/* @0x147160 add r0, pc, r0 */
/* @0x147164 add sp, sp, #4 */
/* @0x147168 vpop {d8, d9} */
/* @0x14716c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x147170 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x147174 vmov r0, s15 */
/* @0x147178 bl 0xb6700 <sqrtf@plt> */
/* @0x14717c vmov s14, r0 */
/* @0x147180 b 0x147024 <_Z25F_D3DLightDefineDirectionR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x147184 bllo 0xfe167390 <b2_toiTime+0xfffffffffda0deec> */
/* @0x147188 andeq r0, r0, r0 */
/* @0x14718c mlaeq r10, r0, r12, r10 */
/* @0x147190 .word 0xffffd9dc */
/* @0x147194 .word 0xffffd9cc */
/* @0x147198 .word 0xffffd9d0 */
/* @0x14719c .word 0xffffd9d8 */
/* @0x1471a0 andseq r10, pc, r0, lsr #17 */

/* ── FUNC 0x1471a4 · F_D3DLightDefinePoint(RValue&, CInstance*, CInstance*, int, RValue*) · size=448 · insn=112 */
/* @0x1471a4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1471a8 sub sp, sp, #20 */
/* @0x1471ac mov r1, #0 */
/* @0x1471b0 ldr r5, [pc, #0x194] */
/* @0x1471b4 ldr r6, [sp, #0x38] */
/* @0x1471b8 add r5, pc, r5 */
/* @0x1471bc mov r0, r6 */
/* @0x1471c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1471c4 cmp r0, #7 */
/* @0x1471c8 mov r4, r0 */
/* @0x1471cc bhi 0x147330 <_Z21F_D3DLightDefinePointR6RValueP9CInstanceS2_iPS_+0x18c> */
/* @0x1471d0 mov r0, r6 */
/* @0x1471d4 mov r1, #1 */
/* @0x1471d8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1471dc mov r1, #2 */
/* @0x1471e0 mov r10, r0 */
/* @0x1471e4 mov r0, r6 */
/* @0x1471e8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1471ec mov r1, #3 */
/* @0x1471f0 mov r11, r0 */
/* @0x1471f4 mov r0, r6 */
/* @0x1471f8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1471fc mov r1, #4 */
/* @0x147200 mov r7, r0 */
/* @0x147204 mov r0, r6 */
/* @0x147208 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x14720c mov r1, #5 */
/* @0x147210 str r0, [sp, #0xc] */
/* @0x147214 mov r0, r6 */
/* @0x147218 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14721c lsl lr, r4, #2 */
/* @0x147220 lsl r2, r4, #4 */
/* @0x147224 add r9, lr, #1 */
/* @0x147228 add r8, lr, #2 */
/* @0x14722c add lr, lr, #3 */
/* @0x147230 lsl r9, r9, #2 */
/* @0x147234 vldr s15, [pc, #268] */
/* @0x147238 lsl r8, r8, #2 */
/* @0x14723c lsl lr, lr, #2 */
/* @0x147240 orr r12, r0, #-16777216 */
/* @0x147244 uxtb r0, r0 */
/* @0x147248 ubfx r3, r12, #0x8, #0x8 */
/* @0x14724c ubfx r6, r12, #0x10, #0x8 */
/* @0x147250 vmov s12, r0 */
/* @0x147254 vmov s14, r3 */
/* @0x147258 ldr r3, [pc, #0xf0] */
/* @0x14725c vmov s13, r6 */
/* @0x147260 vcvt.f32.s32 s12, s12 */
/* @0x147264 ldr r1, [r5, r3] */
/* @0x147268 mov r3, #0 */
/* @0x14726c add r0, r1, r2 */
/* @0x147270 str r3, [r0] */
/* @0x147274 add r0, r1, r9 */
/* @0x147278 str r3, [r0] */
/* @0x14727c add r0, r1, r8 */
/* @0x147280 add r1, r1, lr */
/* @0x147284 vcvt.f32.s32 s13, s13 */
/* @0x147288 str r3, [r0] */
/* @0x14728c mov r0, r4 */
/* @0x147290 str r3, [r1] */
/* @0x147294 ldr r3, [pc, #0xb8] */
/* @0x147298 ldr r1, [r5, r3] */
/* @0x14729c vcvt.f32.s32 s14, s14 */
/* @0x1472a0 ldr r3, [pc, #0xb0] */
/* @0x1472a4 add r6, r1, r2 */
/* @0x1472a8 str r10, [r6] */
/* @0x1472ac add r6, r1, r9 */
/* @0x1472b0 str r11, [r6] */
/* @0x1472b4 add r6, r1, r8 */
/* @0x1472b8 add r1, r1, lr */
/* @0x1472bc vmul.f32 s12, s12, s15 */
/* @0x1472c0 str r7, [r6] */
/* @0x1472c4 ldr r6, [sp, #0xc] */
/* @0x1472c8 str r6, [r1] */
/* @0x1472cc mov r1, r10 */
/* @0x1472d0 ldr r3, [r5, r3] */
/* @0x1472d4 mov r6, #1 */
/* @0x1472d8 add r10, r3, r2 */
/* @0x1472dc add r9, r3, r9 */
/* @0x1472e0 add r8, r3, r8 */
/* @0x1472e4 add lr, r3, lr */
/* @0x1472e8 mov r3, r7 */
/* @0x1472ec ldr r7, [pc, #0x68] */
/* @0x1472f0 mov r2, r11 */
/* @0x1472f4 vmul.f32 s14, s14, s15 */
/* @0x1472f8 vstr s12, [r10] */
/* @0x1472fc vmul.f32 s15, s13, s15 */
/* @0x147300 vstr s14, [r9] */
/* @0x147304 mov r9, #1065353216 */
/* @0x147308 vstr s15, [r8] */
/* @0x14730c str r9, [lr] */
/* @0x147310 ldr lr, [r5, r7] */
/* @0x147314 ldr r5, [sp, #0xc] */
/* @0x147318 str r12, [sp, #0x4] */
/* @0x14731c str r5, [sp] */
/* @0x147320 str r6, [lr, r4, lsl #2] */
/* @0x147324 bl 0x17f7e8 <_Z24GR_3D_Light_Define_Pointiffffj> */
/* @0x147328 add sp, sp, #20 */
/* @0x14732c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x147330 ldr r0, [pc, #0x28] */
/* @0x147334 mov r1, #0 */
/* @0x147338 add r0, pc, r0 */
/* @0x14733c add sp, sp, #20 */
/* @0x147340 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x147344 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x147348 bllo 0xfe167554 <b2_toiTime+0xfffffffffda0e0b0> */
/* @0x14734c mlaeq r10, r8, r10, r10 */
/* @0x147350 .word 0xffffd9dc */
/* @0x147354 .word 0xffffd9d0 */
/* @0x147358 .word 0xffffd9d8 */
/* @0x14735c .word 0xffffd9cc */
/* @0x147360 andseq r10, pc, r8, asr #13 */

/* ── FUNC 0x147364 · F_D3DLightEnable(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x147364 push {r3, r4, r5, lr} */
/* @0x147368 mov r1, #0 */
/* @0x14736c ldr r5, [sp, #0x10] */
/* @0x147370 mov r0, r5 */
/* @0x147374 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x147378 cmp r0, #7 */
/* @0x14737c mov r4, r0 */
/* @0x147380 bhi 0x1473b8 <_Z16F_D3DLightEnableR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x147384 mov r0, r5 */
/* @0x147388 mov r1, #1 */
/* @0x14738c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x147390 ldr r3, [pc, #0x34] */
/* @0x147394 ldr r3, [pc, r3] */
/* @0x147398 vmov s14, r0 */
/* @0x14739c mov r1, r0 */
/* @0x1473a0 mov r0, r4 */
/* @0x1473a4 add r4, r3, r4, lsl #2 */
/* @0x1473a8 vcvt.f32.u32 s15, s14 */
/* @0x1473ac vstr s15, [r4] */
/* @0x1473b0 pop {r3, r4, r5, lr} */
/* @0x1473b4 b 0x17f920 <_Z18GR_3D_Light_Enableib> */
/* @0x1473b8 ldr r0, [pc, #0x10] */
/* @0x1473bc mov r1, #0 */
/* @0x1473c0 pop {r3, r4, r5, lr} */
/* @0x1473c4 add r0, pc, r0 */
/* @0x1473c8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1473cc mlaeq r10, r0, r2, r8 */
/* @0x1473d0 andseq r10, pc, r12, lsr r6 */

/* ── FUNC 0x1473d4 · F_GPUSetTexFilter(RValue&, CInstance*, CInstance*, int, RValue*) · size=216 · insn=54 */
/* @0x1473d4 push {r3, r4, r5, lr} */
/* @0x1473d8 cmp r3, #1 */
/* @0x1473dc mov r3, #0 */
/* @0x1473e0 mov r4, r3 */
/* @0x1473e4 movt r3, #0xbff0 */
/* @0x1473e8 str r4, [r0, #0xc] */
/* @0x1473ec mov r1, r4 */
/* @0x1473f0 str r3, [r0, #0x4] */
/* @0x1473f4 str r4, [r0] */
/* @0x1473f8 ldr r0, [sp, #0x10] */
/* @0x1473fc beq 0x147410 <_Z17F_GPUSetTexFilterR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x147400 ldr r0, [pc, #0x98] */
/* @0x147404 pop {r3, r4, r5, lr} */
/* @0x147408 add r0, pc, r0 */
/* @0x14740c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x147410 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x147414 cmp r0, #0 */
/* @0x147418 beq 0x14745c <_Z17F_GPUSetTexFilterR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x14741c ldr r5, [pc, #0x80] */
/* @0x147420 ldr r5, [pc, r5] */
/* @0x147424 mov r1, r4 */
/* @0x147428 mov r0, r5 */
/* @0x14742c mov r2, #0 */
/* @0x147430 mov r3, #1 */
/* @0x147434 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x147438 mov r2, #1 */
/* @0x14743c mov r1, r4 */
/* @0x147440 mov r0, r5 */
/* @0x147444 add r4, r4, #1 */
/* @0x147448 mov r3, r2 */
/* @0x14744c bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x147450 cmp r4, #8 */
/* @0x147454 bne 0x147424 <_Z17F_GPUSetTexFilterR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x147458 pop {r3, r4, r5, pc} */
/* @0x14745c ldr r5, [pc, #0x44] */
/* @0x147460 mov r4, r0 */
/* @0x147464 ldr r5, [pc, r5] */
/* @0x147468 mov r2, #0 */
/* @0x14746c mov r1, r4 */
/* @0x147470 mov r3, r2 */
/* @0x147474 mov r0, r5 */
/* @0x147478 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x14747c mov r1, r4 */
/* @0x147480 mov r0, r5 */
/* @0x147484 add r4, r4, #1 */
/* @0x147488 mov r2, #1 */
/* @0x14748c mov r3, #0 */
/* @0x147490 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x147494 cmp r4, #8 */
/* @0x147498 bne 0x147468 <_Z17F_GPUSetTexFilterR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x14749c pop {r3, r4, r5, pc} */
/* @0x1474a0 andseq r10, pc, r8, lsr r6 */
/* @0x1474a4 .word 0x002a68d8 */
/* @0x1474a8 mlaeq r10, r4, r8, r6 */

/* ── FUNC 0x1474ac · F_GPUSetTexFilterExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=224 · insn=56 */
/* @0x1474ac cmp r3, #2 */
/* @0x1474b0 mov r3, #0 */
/* @0x1474b4 push {r4, r5, r6, lr} */
/* @0x1474b8 mov r4, r3 */
/* @0x1474bc ldr r5, [sp, #0x10] */
/* @0x1474c0 movt r3, #0xbff0 */
/* @0x1474c4 str r4, [r0, #0xc] */
/* @0x1474c8 str r3, [r0, #0x4] */
/* @0x1474cc str r4, [r0] */
/* @0x1474d0 beq 0x1474e8 <_Z20F_GPUSetTexFilterExtR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1474d4 ldr r0, [pc, #0xa4] */
/* @0x1474d8 mov r1, r4 */
/* @0x1474dc pop {r4, r5, r6, lr} */
/* @0x1474e0 add r0, pc, r0 */
/* @0x1474e4 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1474e8 mov r0, r5 */
/* @0x1474ec mov r1, r4 */
/* @0x1474f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1474f4 mov r1, #1 */
/* @0x1474f8 mov r6, r0 */
/* @0x1474fc mov r0, r5 */
/* @0x147500 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x147504 cmp r6, #7 */
/* @0x147508 mov r5, r0 */
/* @0x14750c pophi {r4, r5, r6, pc} */
/* @0x147510 cmp r0, #0 */
/* @0x147514 bne 0x14754c <_Z20F_GPUSetTexFilterExtR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x147518 ldr r4, [pc, #0x64] */
/* @0x14751c mov r1, r6 */
/* @0x147520 mov r2, r0 */
/* @0x147524 mov r3, r0 */
/* @0x147528 ldr r4, [pc, r4] */
/* @0x14752c mov r0, r4 */
/* @0x147530 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x147534 mov r0, r4 */
/* @0x147538 mov r1, r6 */
/* @0x14753c mov r3, r5 */
/* @0x147540 mov r2, #1 */
/* @0x147544 pop {r4, r5, r6, lr} */
/* @0x147548 b 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x14754c ldr r5, [pc, #0x34] */
/* @0x147550 mov r2, r4 */
/* @0x147554 mov r1, r6 */
/* @0x147558 mov r3, #1 */
/* @0x14755c ldr r5, [pc, r5] */
/* @0x147560 mov r0, r5 */
/* @0x147564 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x147568 mov r2, #1 */
/* @0x14756c mov r0, r5 */
/* @0x147570 mov r1, r6 */
/* @0x147574 mov r3, r2 */
/* @0x147578 pop {r4, r5, r6, lr} */
/* @0x14757c b 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x147580 mulseq pc, r12, r5 */
/* @0x147584 .word 0x002a67d0 */
/* @0x147588 mlaeq r10, r12, r7, r6 */

/* ── FUNC 0x14758c · F_GPUSetTexRepeat(RValue&, CInstance*, CInstance*, int, RValue*) · size=216 · insn=54 */
/* @0x14758c push {r3, r4, r5, lr} */
/* @0x147590 cmp r3, #1 */
/* @0x147594 mov r3, #0 */
/* @0x147598 mov r4, r3 */
/* @0x14759c movt r3, #0xbff0 */
/* @0x1475a0 str r4, [r0, #0xc] */
/* @0x1475a4 mov r1, r4 */
/* @0x1475a8 str r3, [r0, #0x4] */
/* @0x1475ac str r4, [r0] */
/* @0x1475b0 ldr r0, [sp, #0x10] */
/* @0x1475b4 beq 0x1475c8 <_Z17F_GPUSetTexRepeatR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1475b8 ldr r0, [pc, #0x98] */
/* @0x1475bc pop {r3, r4, r5, lr} */
/* @0x1475c0 add r0, pc, r0 */
/* @0x1475c4 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1475c8 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1475cc cmp r0, #0 */
/* @0x1475d0 beq 0x147614 <_Z17F_GPUSetTexRepeatR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x1475d4 ldr r5, [pc, #0x80] */
/* @0x1475d8 ldr r5, [pc, r5] */
/* @0x1475dc mov r1, r4 */
/* @0x1475e0 mov r0, r5 */
/* @0x1475e4 mov r2, #2 */
/* @0x1475e8 mov r3, #0 */
/* @0x1475ec bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x1475f0 mov r1, r4 */
/* @0x1475f4 mov r0, r5 */
/* @0x1475f8 add r4, r4, #1 */
/* @0x1475fc mov r2, #3 */
/* @0x147600 mov r3, #0 */
/* @0x147604 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x147608 cmp r4, #8 */
/* @0x14760c bne 0x1475dc <_Z17F_GPUSetTexRepeatR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x147610 pop {r3, r4, r5, pc} */
/* @0x147614 ldr r5, [pc, #0x44] */
/* @0x147618 mov r4, r0 */
/* @0x14761c ldr r5, [pc, r5] */
/* @0x147620 mov r1, r4 */
/* @0x147624 mov r0, r5 */
/* @0x147628 mov r2, #2 */
/* @0x14762c mov r3, #1 */
/* @0x147630 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x147634 mov r1, r4 */
/* @0x147638 mov r0, r5 */
/* @0x14763c add r4, r4, #1 */
/* @0x147640 mov r2, #3 */
/* @0x147644 mov r3, #1 */
/* @0x147648 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x14764c cmp r4, #8 */
/* @0x147650 bne 0x147620 <_Z17F_GPUSetTexRepeatR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x147654 pop {r3, r4, r5, pc} */
/* @0x147658 andseq r10, pc, r0, lsl r5 */
/* @0x14765c eoreq r6, r10, r0, lsr #14 */
/* @0x147660 .word 0x002a66dc */

/* ── FUNC 0x147664 · F_GPUSetTexRepeatExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=224 · insn=56 */
/* @0x147664 cmp r3, #2 */
/* @0x147668 mov r1, #0 */
/* @0x14766c push {r4, r5, r6, r7, r8, lr} */
/* @0x147670 mov r4, r1 */
/* @0x147674 mov r5, r3 */
/* @0x147678 movt r1, #0xbff0 */
/* @0x14767c str r4, [r0, #0xc] */
/* @0x147680 str r1, [r0, #0x4] */
/* @0x147684 str r4, [r0] */
/* @0x147688 ldr r6, [sp, #0x18] */
/* @0x14768c beq 0x1476a4 <_Z20F_GPUSetTexRepeatExtR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x147690 ldr r0, [pc, #0xa0] */
/* @0x147694 mov r1, r4 */
/* @0x147698 pop {r4, r5, r6, r7, r8, lr} */
/* @0x14769c add r0, pc, r0 */
/* @0x1476a0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1476a4 mov r1, r4 */
/* @0x1476a8 mov r0, r6 */
/* @0x1476ac bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1476b0 mov r1, #1 */
/* @0x1476b4 mov r7, r0 */
/* @0x1476b8 mov r0, r6 */
/* @0x1476bc bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1476c0 cmp r7, #7 */
/* @0x1476c4 pophi {r4, r5, r6, r7, r8, pc} */
/* @0x1476c8 cmp r0, #0 */
/* @0x1476cc bne 0x147704 <_Z20F_GPUSetTexRepeatExtR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x1476d0 ldr r4, [pc, #0x64] */
/* @0x1476d4 mov r2, r5 */
/* @0x1476d8 mov r1, r7 */
/* @0x1476dc mov r3, #1 */
/* @0x1476e0 ldr r4, [pc, r4] */
/* @0x1476e4 mov r0, r4 */
/* @0x1476e8 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x1476ec mov r0, r4 */
/* @0x1476f0 mov r1, r7 */
/* @0x1476f4 mov r2, #3 */
/* @0x1476f8 mov r3, #1 */
/* @0x1476fc pop {r4, r5, r6, r7, r8, lr} */
/* @0x147700 b 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x147704 ldr r6, [pc, #0x34] */
/* @0x147708 mov r2, r5 */
/* @0x14770c mov r1, r7 */
/* @0x147710 mov r3, r4 */
/* @0x147714 ldr r6, [pc, r6] */
/* @0x147718 mov r0, r6 */
/* @0x14771c bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x147720 mov r0, r6 */
/* @0x147724 mov r1, r7 */
/* @0x147728 mov r3, r4 */
/* @0x14772c mov r2, #3 */
/* @0x147730 pop {r4, r5, r6, r7, r8, lr} */
/* @0x147734 b 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x147738 andseq r10, pc, r0, ror r4 */
/* @0x14773c eoreq r6, r10, r8, lsl r6 */
/* @0x147740 eoreq r6, r10, r4, ror #11 */

/* ── FUNC 0x147744 · F_GPUSetTexMipFilter(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x147744 cmp r3, #1 */
/* @0x147748 mov r3, #0 */
/* @0x14774c push {r4, r5, r6, lr} */
/* @0x147750 mov r4, r3 */
/* @0x147754 movt r3, #0xbff0 */
/* @0x147758 str r4, [r0, #0xc] */
/* @0x14775c str r3, [r0, #0x4] */
/* @0x147760 str r4, [r0] */
/* @0x147764 ldr r0, [sp, #0x10] */
/* @0x147768 beq 0x147780 <_Z20F_GPUSetTexMipFilterR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x14776c ldr r0, [pc, #0x44] */
/* @0x147770 mov r1, r4 */
/* @0x147774 pop {r4, r5, r6, lr} */
/* @0x147778 add r0, pc, r0 */
/* @0x14777c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x147780 mov r1, r4 */
/* @0x147784 ldr r5, [pc, #0x30] */
/* @0x147788 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14778c ldr r5, [pc, r5] */
/* @0x147790 mov r6, r0 */
/* @0x147794 mov r1, r4 */
/* @0x147798 mov r0, r5 */
/* @0x14779c mov r2, #4 */
/* @0x1477a0 add r4, r4, #1 */
/* @0x1477a4 mov r3, r6 */
/* @0x1477a8 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x1477ac cmp r4, #8 */
/* @0x1477b0 bne 0x147794 <_Z20F_GPUSetTexMipFilterR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x1477b4 pop {r4, r5, r6, pc} */
/* @0x1477b8 andseq r10, pc, r8, ror #7 */
/* @0x1477bc eoreq r6, r10, r12, ror #10 */

/* ── FUNC 0x1477c0 · F_GPUSetTexMipFilterExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x1477c0 cmp r3, #2 */
/* @0x1477c4 mov r3, #0 */
/* @0x1477c8 push {r4, r5, r6, lr} */
/* @0x1477cc mov r1, r3 */
/* @0x1477d0 ldr r4, [sp, #0x10] */
/* @0x1477d4 movt r3, #0xbff0 */
/* @0x1477d8 str r1, [r0, #0xc] */
/* @0x1477dc stm r0, {r1, r3} */
/* @0x1477e0 beq 0x1477f4 <_Z23F_GPUSetTexMipFilterExtR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x1477e4 ldr r0, [pc, #0x44] */
/* @0x1477e8 pop {r4, r5, r6, lr} */
/* @0x1477ec add r0, pc, r0 */
/* @0x1477f0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1477f4 mov r0, r4 */
/* @0x1477f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1477fc mov r1, #1 */
/* @0x147800 mov r5, r0 */
/* @0x147804 mov r0, r4 */
/* @0x147808 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x14780c cmp r5, #7 */
/* @0x147810 pophi {r4, r5, r6, pc} */
/* @0x147814 ldr r12, [pc, #0x18] */
/* @0x147818 mov r1, r5 */
/* @0x14781c mov r3, r0 */
/* @0x147820 mov r2, #4 */
/* @0x147824 ldr r0, [pc, r12] */
/* @0x147828 pop {r4, r5, r6, lr} */
/* @0x14782c b 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x147830 ldrheq r10, [pc], -r4 */
/* @0x147834 .word 0x002a64d4 */

/* ── FUNC 0x147838 · F_GPUSetTexMipBias(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x147838 cmp r3, #1 */
/* @0x14783c mov r3, #0 */
/* @0x147840 push {r4, r5, r6, lr} */
/* @0x147844 mov r4, r3 */
/* @0x147848 movt r3, #0xbff0 */
/* @0x14784c str r4, [r0, #0xc] */
/* @0x147850 str r3, [r0, #0x4] */
/* @0x147854 str r4, [r0] */
/* @0x147858 ldr r0, [sp, #0x10] */
/* @0x14785c beq 0x147874 <_Z18F_GPUSetTexMipBiasR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x147860 ldr r0, [pc, #0x44] */
/* @0x147864 mov r1, r4 */
/* @0x147868 pop {r4, r5, r6, lr} */
/* @0x14786c add r0, pc, r0 */
/* @0x147870 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x147874 mov r1, r4 */
/* @0x147878 ldr r5, [pc, #0x30] */
/* @0x14787c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x147880 ldr r5, [pc, r5] */
/* @0x147884 mov r6, r0 */
/* @0x147888 mov r1, r4 */
/* @0x14788c mov r0, r5 */
/* @0x147890 mov r2, #7 */
/* @0x147894 add r4, r4, #1 */
/* @0x147898 mov r3, r6 */
/* @0x14789c bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x1478a0 cmp r4, #8 */
/* @0x1478a4 bne 0x147888 <_Z18F_GPUSetTexMipBiasR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x1478a8 pop {r4, r5, r6, pc} */
/* @0x1478ac andseq r10, pc, r12, lsl #7 */
/* @0x1478b0 eoreq r6, r10, r8, ror r4 */

/* ── FUNC 0x1478b4 · F_GPUSetTexMipBiasExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x1478b4 cmp r3, #2 */
/* @0x1478b8 mov r3, #0 */
/* @0x1478bc push {r4, r5, r6, lr} */
/* @0x1478c0 mov r1, r3 */
/* @0x1478c4 ldr r4, [sp, #0x10] */
/* @0x1478c8 movt r3, #0xbff0 */
/* @0x1478cc str r1, [r0, #0xc] */
/* @0x1478d0 stm r0, {r1, r3} */
/* @0x1478d4 beq 0x1478e8 <_Z21F_GPUSetTexMipBiasExtR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x1478d8 ldr r0, [pc, #0x44] */
/* @0x1478dc pop {r4, r5, r6, lr} */
/* @0x1478e0 add r0, pc, r0 */
/* @0x1478e4 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1478e8 mov r0, r4 */
/* @0x1478ec bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1478f0 mov r1, #1 */
/* @0x1478f4 mov r5, r0 */
/* @0x1478f8 mov r0, r4 */
/* @0x1478fc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x147900 cmp r5, #7 */
/* @0x147904 pophi {r4, r5, r6, pc} */
/* @0x147908 ldr r12, [pc, #0x18] */
/* @0x14790c mov r1, r5 */
/* @0x147910 mov r3, r0 */
/* @0x147914 mov r2, #7 */
/* @0x147918 ldr r0, [pc, r12] */
/* @0x14791c pop {r4, r5, r6, lr} */
/* @0x147920 b 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x147924 andseq r10, pc, r4, asr r3 */
/* @0x147928 eoreq r6, r10, r0, ror #7 */

/* ── FUNC 0x14792c · F_GPUSetTexMinMip(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x14792c cmp r3, #1 */
/* @0x147930 mov r3, #0 */
/* @0x147934 push {r4, r5, r6, lr} */
/* @0x147938 mov r4, r3 */
/* @0x14793c movt r3, #0xbff0 */
/* @0x147940 str r4, [r0, #0xc] */
/* @0x147944 str r3, [r0, #0x4] */
/* @0x147948 str r4, [r0] */
/* @0x14794c ldr r0, [sp, #0x10] */
/* @0x147950 beq 0x147968 <_Z17F_GPUSetTexMinMipR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x147954 ldr r0, [pc, #0x44] */
/* @0x147958 mov r1, r4 */
/* @0x14795c pop {r4, r5, r6, lr} */
/* @0x147960 add r0, pc, r0 */
/* @0x147964 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x147968 mov r1, r4 */
/* @0x14796c ldr r5, [pc, #0x30] */
/* @0x147970 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x147974 ldr r5, [pc, r5] */
/* @0x147978 mov r6, r0 */
/* @0x14797c mov r1, r4 */
/* @0x147980 mov r0, r5 */
/* @0x147984 mov r2, #5 */
/* @0x147988 add r4, r4, #1 */
/* @0x14798c mov r3, r6 */
/* @0x147990 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x147994 cmp r4, #8 */
/* @0x147998 bne 0x14797c <_Z17F_GPUSetTexMinMipR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x14799c pop {r4, r5, r6, pc} */
/* @0x1479a0 andseq r10, pc, r8, lsr #6 */
/* @0x1479a4 eoreq r6, r10, r4, lsl #7 */

/* ── FUNC 0x1479a8 · F_GPUSetTexMinMipExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x1479a8 cmp r3, #2 */
/* @0x1479ac mov r3, #0 */
/* @0x1479b0 push {r4, r5, r6, lr} */
/* @0x1479b4 mov r1, r3 */
/* @0x1479b8 ldr r4, [sp, #0x10] */
/* @0x1479bc movt r3, #0xbff0 */
/* @0x1479c0 str r1, [r0, #0xc] */
/* @0x1479c4 stm r0, {r1, r3} */
/* @0x1479c8 beq 0x1479dc <_Z20F_GPUSetTexMinMipExtR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x1479cc ldr r0, [pc, #0x44] */
/* @0x1479d0 pop {r4, r5, r6, lr} */
/* @0x1479d4 add r0, pc, r0 */
/* @0x1479d8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1479dc mov r0, r4 */
/* @0x1479e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1479e4 mov r1, #1 */
/* @0x1479e8 mov r5, r0 */
/* @0x1479ec mov r0, r4 */
/* @0x1479f0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1479f4 cmp r5, #7 */
/* @0x1479f8 pophi {r4, r5, r6, pc} */
/* @0x1479fc ldr r12, [pc, #0x18] */
/* @0x147a00 mov r1, r5 */
/* @0x147a04 mov r3, r0 */
/* @0x147a08 mov r2, #5 */
/* @0x147a0c ldr r0, [pc, r12] */
/* @0x147a10 pop {r4, r5, r6, lr} */
/* @0x147a14 b 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x147a18 ldrsheq r10, [pc], -r0 */
/* @0x147a1c eoreq r6, r10, r12, ror #5 */

/* ── FUNC 0x147a20 · F_GPUSetTexMaxMip(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x147a20 cmp r3, #1 */
/* @0x147a24 mov r3, #0 */
/* @0x147a28 push {r4, r5, r6, lr} */
/* @0x147a2c mov r4, r3 */
/* @0x147a30 movt r3, #0xbff0 */
/* @0x147a34 str r4, [r0, #0xc] */
/* @0x147a38 str r3, [r0, #0x4] */
/* @0x147a3c str r4, [r0] */
/* @0x147a40 ldr r0, [sp, #0x10] */
/* @0x147a44 beq 0x147a5c <_Z17F_GPUSetTexMaxMipR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x147a48 ldr r0, [pc, #0x44] */
/* @0x147a4c mov r1, r4 */
/* @0x147a50 pop {r4, r5, r6, lr} */
/* @0x147a54 add r0, pc, r0 */
/* @0x147a58 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x147a5c mov r1, r4 */
/* @0x147a60 ldr r5, [pc, #0x30] */
/* @0x147a64 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x147a68 ldr r5, [pc, r5] */
/* @0x147a6c mov r6, r0 */
/* @0x147a70 mov r1, r4 */
/* @0x147a74 mov r0, r5 */
/* @0x147a78 mov r2, #6 */
/* @0x147a7c add r4, r4, #1 */
/* @0x147a80 mov r3, r6 */
/* @0x147a84 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x147a88 cmp r4, #8 */
/* @0x147a8c bne 0x147a70 <_Z17F_GPUSetTexMaxMipR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x147a90 pop {r4, r5, r6, pc} */
/* @0x147a94 andseq r10, pc, r4, asr #5 */
/* @0x147a98 mlaeq r10, r0, r2, r6 */

/* ── FUNC 0x147a9c · F_GPUSetTexMaxMipExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x147a9c cmp r3, #2 */
/* @0x147aa0 mov r3, #0 */
/* @0x147aa4 push {r4, r5, r6, lr} */
/* @0x147aa8 mov r1, r3 */
/* @0x147aac ldr r4, [sp, #0x10] */
/* @0x147ab0 movt r3, #0xbff0 */
/* @0x147ab4 str r1, [r0, #0xc] */
/* @0x147ab8 stm r0, {r1, r3} */
/* @0x147abc beq 0x147ad0 <_Z20F_GPUSetTexMaxMipExtR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x147ac0 ldr r0, [pc, #0x44] */
/* @0x147ac4 pop {r4, r5, r6, lr} */
/* @0x147ac8 add r0, pc, r0 */
/* @0x147acc b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x147ad0 mov r0, r4 */
/* @0x147ad4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x147ad8 mov r1, #1 */
/* @0x147adc mov r5, r0 */
/* @0x147ae0 mov r0, r4 */
/* @0x147ae4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x147ae8 cmp r5, #7 */
/* @0x147aec pophi {r4, r5, r6, pc} */
/* @0x147af0 ldr r12, [pc, #0x18] */
/* @0x147af4 mov r1, r5 */
/* @0x147af8 mov r3, r0 */
/* @0x147afc mov r2, #6 */
/* @0x147b00 ldr r0, [pc, r12] */
/* @0x147b04 pop {r4, r5, r6, lr} */
/* @0x147b08 b 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x147b0c andseq r10, pc, r12, lsl #5 */
/* @0x147b10 .word 0x002a61f8 */

/* ── FUNC 0x147b14 · F_GPUSetTexMaxAniso(RValue&, CInstance*, CInstance*, int, RValue*) · size=176 · insn=44 */
/* @0x147b14 cmp r3, #1 */
/* @0x147b18 mov r3, #0 */
/* @0x147b1c push {r4, r5, r6, lr} */
/* @0x147b20 mov r4, r3 */
/* @0x147b24 mov r1, r4 */
/* @0x147b28 movt r3, #0xbff0 */
/* @0x147b2c str r4, [r0, #0xc] */
/* @0x147b30 str r3, [r0, #0x4] */
/* @0x147b34 str r4, [r0] */
/* @0x147b38 ldr r0, [sp, #0x10] */
/* @0x147b3c beq 0x147b50 <_Z19F_GPUSetTexMaxAnisoR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x147b40 ldr r0, [pc, #0x6c] */
/* @0x147b44 pop {r4, r5, r6, lr} */
/* @0x147b48 add r0, pc, r0 */
/* @0x147b4c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x147b50 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x147b54 sub r3, r0, #1 */
/* @0x147b58 mov r6, r0 */
/* @0x147b5c cmp r3, #15 */
/* @0x147b60 bhi 0x147b90 <_Z19F_GPUSetTexMaxAnisoR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x147b64 ldr r5, [pc, #0x4c] */
/* @0x147b68 ldr r5, [pc, r5] */
/* @0x147b6c mov r1, r4 */
/* @0x147b70 mov r0, r5 */
/* @0x147b74 mov r2, #8 */
/* @0x147b78 add r4, r4, #1 */
/* @0x147b7c mov r3, r6 */
/* @0x147b80 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x147b84 cmp r4, #8 */
/* @0x147b88 bne 0x147b6c <_Z19F_GPUSetTexMaxAnisoR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x147b8c pop {r4, r5, r6, pc} */
/* @0x147b90 ldr r3, [pc, #0x24] */
/* @0x147b94 ldr r1, [pc, #0x24] */
/* @0x147b98 ldr r3, [pc, r3] */
/* @0x147b9c add r1, pc, r1 */
/* @0x147ba0 ldr r0, [r3] */
/* @0x147ba4 ldr r3, [r0] */
/* @0x147ba8 ldr r3, [r3, #0xc] */
/* @0x147bac blx r3 */
/* @0x147bb0 pop {r4, r5, r6, pc} */
/* @0x147bb4 andseq r10, pc, r0, ror #4 */
/* @0x147bb8 mlaeq r10, r0, r1, r6 */
/* @0x147bbc eoreq r5, r10, r12, ror r11 */
/* @0x147bc0 andseq r10, pc, r8, asr #4 */

/* ── FUNC 0x147bc4 · F_GPUSetTexMaxAnisoExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=176 · insn=44 */
/* @0x147bc4 cmp r3, #2 */
/* @0x147bc8 mov r3, #0 */
/* @0x147bcc push {r4, r5, r6, lr} */
/* @0x147bd0 mov r1, r3 */
/* @0x147bd4 ldr r4, [sp, #0x10] */
/* @0x147bd8 movt r3, #0xbff0 */
/* @0x147bdc str r1, [r0, #0xc] */
/* @0x147be0 stm r0, {r1, r3} */
/* @0x147be4 beq 0x147bf8 <_Z22F_GPUSetTexMaxAnisoExtR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x147be8 ldr r0, [pc, #0x74] */
/* @0x147bec pop {r4, r5, r6, lr} */
/* @0x147bf0 add r0, pc, r0 */
/* @0x147bf4 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x147bf8 mov r0, r4 */
/* @0x147bfc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x147c00 mov r1, #1 */
/* @0x147c04 mov r5, r0 */
/* @0x147c08 mov r0, r4 */
/* @0x147c0c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x147c10 sub r2, r0, #1 */
/* @0x147c14 mov r3, r0 */
/* @0x147c18 cmp r2, #15 */
/* @0x147c1c bhi 0x147c40 <_Z22F_GPUSetTexMaxAnisoExtR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x147c20 cmp r5, #7 */
/* @0x147c24 pophi {r4, r5, r6, pc} */
/* @0x147c28 ldr r0, [pc, #0x38] */
/* @0x147c2c mov r1, r5 */
/* @0x147c30 mov r2, #8 */
/* @0x147c34 ldr r0, [pc, r0] */
/* @0x147c38 pop {r4, r5, r6, lr} */
/* @0x147c3c b 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x147c40 ldr r3, [pc, #0x24] */
/* @0x147c44 ldr r1, [pc, #0x24] */
/* @0x147c48 ldr r3, [pc, r3] */
/* @0x147c4c add r1, pc, r1 */
/* @0x147c50 ldr r0, [r3] */
/* @0x147c54 ldr r3, [r0] */
/* @0x147c58 ldr r3, [r3, #0xc] */
/* @0x147c5c blx r3 */
/* @0x147c60 pop {r4, r5, r6, pc} */
/* @0x147c64 andseq r10, pc, r0, lsr r2 */
/* @0x147c68 eoreq r6, r10, r4, asr #1 */
/* @0x147c6c eoreq r5, r10, r12, asr #21 */
/* @0x147c70 mulseq pc, r8, r1 */

/* ── FUNC 0x147c74 · F_GPUSetTexMipEnable(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x147c74 cmp r3, #1 */
/* @0x147c78 mov r3, #0 */
/* @0x147c7c push {r4, r5, r6, lr} */
/* @0x147c80 mov r4, r3 */
/* @0x147c84 movt r3, #0xbff0 */
/* @0x147c88 str r4, [r0, #0xc] */
/* @0x147c8c str r3, [r0, #0x4] */
/* @0x147c90 str r4, [r0] */
/* @0x147c94 ldr r0, [sp, #0x10] */
/* @0x147c98 beq 0x147cb0 <_Z20F_GPUSetTexMipEnableR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x147c9c ldr r0, [pc, #0x44] */
/* @0x147ca0 mov r1, r4 */
/* @0x147ca4 pop {r4, r5, r6, lr} */
/* @0x147ca8 add r0, pc, r0 */
/* @0x147cac b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x147cb0 mov r1, r4 */
/* @0x147cb4 ldr r5, [pc, #0x30] */
/* @0x147cb8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x147cbc ldr r5, [pc, r5] */
/* @0x147cc0 mov r6, r0 */
/* @0x147cc4 mov r1, r4 */
/* @0x147cc8 mov r0, r5 */
/* @0x147ccc mov r2, #9 */
/* @0x147cd0 add r4, r4, #1 */
/* @0x147cd4 mov r3, r6 */
/* @0x147cd8 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x147cdc cmp r4, #8 */
/* @0x147ce0 bne 0x147cc4 <_Z20F_GPUSetTexMipEnableR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x147ce4 pop {r4, r5, r6, pc} */
/* @0x147ce8 ldrsbeq r10, [pc], -r0 */
/* @0x147cec eoreq r6, r10, r12, lsr r0 */

/* ── FUNC 0x147cf0 · F_GPUGetBlendEnable(RValue&, CInstance*, CInstance*, int, RValue*) · size=108 · insn=27 */
/* @0x147cf0 push {r3, r4, r5, lr} */
/* @0x147cf4 subs r5, r3, #0 */
/* @0x147cf8 mov r1, #0 */
/* @0x147cfc mov r4, r0 */
/* @0x147d00 str r1, [r0, #0xc] */
/* @0x147d04 str r1, [r0] */
/* @0x147d08 str r1, [r0, #0x4] */
/* @0x147d0c bne 0x147d44 <_Z19F_GPUGetBlendEnableR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x147d10 ldr r0, [pc, #0x3c] */
/* @0x147d14 mov r1, #12 */
/* @0x147d18 ldr r0, [pc, r0] */
/* @0x147d1c bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x147d20 cmp r0, #0 */
/* @0x147d24 moveq r3, r0 */
/* @0x147d28 movne r2, #0 */
/* @0x147d2c movne r3, r5 */
/* @0x147d30 movtne r2, #0x3ff0 */
/* @0x147d34 moveq r2, r3 */
/* @0x147d38 str r3, [r4] */
/* @0x147d3c str r2, [r4, #0x4] */
/* @0x147d40 pop {r3, r4, r5, pc} */
/* @0x147d44 ldr r0, [pc, #0xc] */
/* @0x147d48 pop {r3, r4, r5, lr} */
/* @0x147d4c add r0, pc, r0 */
/* @0x147d50 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x147d54 eoreq r5, r10, r0, ror #31 */
/* @0x147d58 andseq r10, pc, r12, ror #2 */

/* ── FUNC 0x147d5c · F_GPUGetZTestEnable(RValue&, CInstance*, CInstance*, int, RValue*) · size=108 · insn=27 */
/* @0x147d5c push {r3, r4, r5, lr} */
/* @0x147d60 subs r5, r3, #0 */
/* @0x147d64 mov r1, #0 */
/* @0x147d68 mov r4, r0 */
/* @0x147d6c str r1, [r0, #0xc] */
/* @0x147d70 str r1, [r0] */
/* @0x147d74 str r1, [r0, #0x4] */
/* @0x147d78 bne 0x147db0 <_Z19F_GPUGetZTestEnableR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x147d7c ldr r0, [pc, #0x3c] */
/* @0x147d80 mov r1, #1 */
/* @0x147d84 ldr r0, [pc, r0] */
/* @0x147d88 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState> */
/* @0x147d8c cmp r0, #0 */
/* @0x147d90 moveq r3, r0 */
/* @0x147d94 movne r2, #0 */
/* @0x147d98 movne r3, r5 */
/* @0x147d9c movtne r2, #0x3ff0 */
/* @0x147da0 moveq r2, r3 */
/* @0x147da4 str r3, [r4] */
/* @0x147da8 str r2, [r4, #0x4] */
/* @0x147dac pop {r3, r4, r5, pc} */
/* @0x147db0 ldr r0, [pc, #0xc] */
/* @0x147db4 pop {r3, r4, r5, lr} */
/* @0x147db8 add r0, pc, r0 */
/* @0x147dbc b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x147dc0 eoreq r5, r10, r4, ror pc */
/* @0x147dc4 andseq r10, pc, r8, lsr r1 */
