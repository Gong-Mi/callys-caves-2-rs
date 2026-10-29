/* cally 逆向卡：All_46 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 81 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/81 Background_Load(unsigned char*, unsigned int, unsigned char*)  0xc3350  size 384  96 条（0xc3350..0xc34d0）
 * @func 0xc3350 0xc34d0  size 384  96 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::SetLength(void**, unsigned int, char const*, int)×2 / operator new(unsigned int) / CBackground::CBackground() / CBackground::LoadFromChunk(YYBackground*, unsigned char*) / 0xb6538 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65a4 / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x4×4 / 0x14c×2 / 0x8×2 / 0xc×2 / 0x2×2 / 0x150×1 / 0x13c×1 / 0x100×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc3350 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xc3354 sub sp, sp, #20
 *   @0xc3358 ldr r9, [r0]
 *   @0xc335c mov r3, #92
 *   @0xc3360 ldr r4, [pc, #0x150]
 *   @0xc3364 mov r8, r0
 *   @0xc3368 ldr r12, [pc, #0x14c]
 *   @0xc336c ldr r10, [pc, #0x14c]
 *   @0xc3370 add r4, pc, r4
 *   @0xc3374 lsl r5, r9, #2
 *   @0xc3378 ldr r12, [pc, r12]
 *   @0xc337c add r10, pc, r10
 *   @0xc3380 ldr r6, [pc, #0x13c]
 *   @0xc3384 str r2, [sp, #0x8]
 *   @0xc3388 add r0, r10, #4
 *   @0xc338c mov r2, r4
 *   @0xc3390 mov r1, r5
 *   @0xc3394 str r9, [r12]
 *   @0xc3398 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xc339c ldr r6, [pc, r6]
 *   @0xc33a0 mov r1, r5
 *   @0xc33a4 mov r2, r4
 *   @0xc33a8 mov r3, #94
 *   @0xc33ac mov r0, r6
 *   @0xc33b0 str r9, [r10]
 *   @0xc33b4 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xc33b8 cmp r9, #0
 *   @0xc33bc beq 0xc34a4 <_Z15Background_LoadPhjS_+0x154>
 *   @0xc33c0 ldr r3, [pc, #0x100]
 *   @0xc33c4 mov r4, #0
 *   @0xc33c8 str r9, [sp, #0x4]
 *   @0xc33cc add r3, pc, r3
 *   @0xc33d0 str r3, [sp, #0xc]
 *   @0xc33d4 b 0xc3490 <_Z15Background_LoadPhjS_+0x140>
 *   @0xc33d8 ldr r9, [pc, #0xec]
 *   @0xc33dc ldr r9, [pc, r9]
 *   @0xc33e0 ldr r11, [r9]
 *   @0xc33e4 adds r1, r11, r5
 *   @0xc33e8 beq 0xc34b0 <_Z15Background_LoadPhjS_+0x160>
 *   @0xc33ec mov r0, #72
 *   @0xc33f0 str r1, [sp]
 *   @0xc33f4 bl 0x27c524 <_Znwj>
 *   @0xc33f8 mov r7, r0
 *   @0xc33fc bl 0xc2b58 <_ZN11CBackgroundC2Ev>
 *   @0xc3400 ldr r1, [sp]
 *   @0xc3404 mov r0, r7
 *   @0xc3408 ldr r2, [sp, #0x8]
 *   @0xc340c bl 0xc2c44 <_ZN11CBackground13LoadFromChunkEP12YYBackgroundPh>
 *   @0xc3410 ldr r12, [r11, r5]
 *   @0xc3414 cmp r12, #0
 *   @0xc3418 ldrne r3, [r9]
 *   @0xc341c moveq r11, r12
 *   @0xc3420 addne r11, r3, r12
 *   @0xc3424 mov r0, r11
 *   @0xc3428 bl 0xb6538 <strlen@plt>
 *   @0xc342c ldr r1, [sp, #0xc]
 *   @0xc3430 mov r3, #1
 *   @0xc3434 mov r2, #105
 *   @0xc3438 add r0, r0, r3
 *   @0xc343c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xc3440 mov r1, r11
 *   @0xc3444 mov r5, r0
 *   @0xc3448 bl 0xb65a4 <strcpy@plt>
 *   @0xc344c ldr r2, [r6]
 *   @0xc3450 lsl r11, r4, #2
 *   @0xc3454 ldr r0, [r2, r4, lsl #2]
 *   @0xc3458 cmp r0, #0
 *   @0xc345c beq 0xc3470 <_Z15Background_LoadPhjS_+0x120>
 *   @0xc3460 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xc3464 ldr r2, [r6]
 *   @0xc3468 mov r3, #0
 *   @0xc346c str r3, [r2, r4, lsl #2]
 *   @0xc3470 ldr r2, [r10, #0x4]
 *   @0xc3474 add r4, r4, #1
 *   @0xc3478 ldr r3, [sp, #0x4]
 *   @0xc347c str r7, [r2, r11]
 *   @0xc3480 cmp r4, r3
 *   @0xc3484 ldr r2, [r6]
 *   @0xc3488 str r5, [r2, r11]
 *   @0xc348c beq 0xc34a4 <_Z15Background_LoadPhjS_+0x154>
 *   @0xc3490 ldr r5, [r8, #0x4]!
 *   @0xc3494 cmp r5, #0
 *   @0xc3498 bne 0xc33d8 <_Z15Background_LoadPhjS_+0x88>
 *   @0xc349c mov r7, r5
 *   @0xc34a0 b 0xc344c <_Z15Background_LoadPhjS_+0xfc>
 *   @0xc34a4 mov r0, #1
 *   @0xc34a8 add sp, sp, #20
 *   @0xc34ac pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xc34b0 mov r5, r1
 *   @0xc34b4 b 0xc349c <_Z15Background_LoadPhjS_+0x14c>
 *   @0xc34b8 eoreq sp, r6, r0, lsl r7
 *   @0xc34bc ldrsbteq r10, [r2], -r0
 *   @0xc34c0 eorseq r6, r11, r12, lsr #18
 *   @0xc34c4 ldrhteq r10, [r2], -r0
 *   @0xc34c8 .word 0x0026d6b4
 *   @0xc34cc eorseq r10, r2, r8, ror #10
 *
 * ══ §2/81 F_DrawSurfaceGeneral(RValue&, CInstance*, CInstance*, int, RValue*)  0x11ec34  size 384  96 条（0x11ec34..0x11edb4）
 * @func 0x11ec34 0x11edb4  size 384  96 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×10 / YYGetInt32(RValue const*, int)×5 / GR_Surface_Exists(int) / GR_Surface_DrawGeneral(int, float, float, float, float, float, float, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, float)
 * 字段偏移 top8: 0x40×2 / 0x34×2 / 0x38×2 / 0x3c×2 / 0x44×2 / 0x48×2 / 0x4c×2 / 0xc×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11ec34 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x11ec38 sub sp, sp, #84
 *   @0x11ec3c mov r1, #0
 *   @0x11ec40 ldr r4, [sp, #0x78]
 *   @0x11ec44 mov r0, r4
 *   @0x11ec48 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11ec4c mov r5, r0
 *   @0x11ec50 bl 0x1714c0 <_Z17GR_Surface_Existsi>
 *   @0x11ec54 subs r1, r0, #0
 *   @0x11ec58 beq 0x11ed9c <_Z20F_DrawSurfaceGeneralR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x11ec5c mov r0, r4
 *   @0x11ec60 mov r1, #1
 *   @0x11ec64 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11ec68 mov r1, #2
 *   @0x11ec6c str r0, [sp, #0x40]
 *   @0x11ec70 mov r0, r4
 *   @0x11ec74 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11ec78 mov r1, #3
 *   @0x11ec7c mov r2, r0
 *   @0x11ec80 mov r0, r4
 *   @0x11ec84 str r2, [sp, #0x34]
 *   @0x11ec88 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11ec8c mov r1, #4
 *   @0x11ec90 mov r3, r0
 *   @0x11ec94 mov r0, r4
 *   @0x11ec98 str r3, [sp, #0x38]
 *   @0x11ec9c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11eca0 mov r1, #5
 *   @0x11eca4 mov r12, r0
 *   @0x11eca8 mov r0, r4
 *   @0x11ecac str r12, [sp, #0x3c]
 *   @0x11ecb0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11ecb4 mov r1, #6
 *   @0x11ecb8 str r0, [sp, #0x44]
 *   @0x11ecbc mov r0, r4
 *   @0x11ecc0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11ecc4 mov r1, #7
 *   @0x11ecc8 str r0, [sp, #0x48]
 *   @0x11eccc mov r0, r4
 *   @0x11ecd0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11ecd4 mov r1, #8
 *   @0x11ecd8 mov r11, r0
 *   @0x11ecdc mov r0, r4
 *   @0x11ece0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11ece4 mov r1, #9
 *   @0x11ece8 mov r10, r0
 *   @0x11ecec mov r0, r4
 *   @0x11ecf0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11ecf4 mov r1, #10
 *   @0x11ecf8 mov r9, r0
 *   @0x11ecfc mov r0, r4
 *   @0x11ed00 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11ed04 mov r1, #11
 *   @0x11ed08 str r0, [sp, #0x4c]
 *   @0x11ed0c mov r0, r4
 *   @0x11ed10 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11ed14 mov r1, #12
 *   @0x11ed18 mov r8, r0
 *   @0x11ed1c mov r0, r4
 *   @0x11ed20 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11ed24 mov r1, #13
 *   @0x11ed28 mov r7, r0
 *   @0x11ed2c mov r0, r4
 *   @0x11ed30 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11ed34 mov r1, #14
 *   @0x11ed38 mov r6, r0
 *   @0x11ed3c mov r0, r4
 *   @0x11ed40 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11ed44 ldr r1, [sp, #0x44]
 *   @0x11ed48 ldr r12, [sp, #0x3c]
 *   @0x11ed4c str r11, [sp, #0xc]
 *   @0x11ed50 str r1, [sp, #0x4]
 *   @0x11ed54 ldr r1, [sp, #0x48]
 *   @0x11ed58 str r12, [sp]
 *   @0x11ed5c str r10, [sp, #0x10]
 *   @0x11ed60 str r1, [sp, #0x8]
 *   @0x11ed64 ldr r1, [sp, #0x4c]
 *   @0x11ed68 str r9, [sp, #0x14]
 *   @0x11ed6c str r8, [sp, #0x1c]
 *   @0x11ed70 str r1, [sp, #0x18]
 *   @0x11ed74 str r7, [sp, #0x20]
 *   @0x11ed78 str r6, [sp, #0x24]
 *   @0x11ed7c ldr r1, [sp, #0x40]
 *   @0x11ed80 ldr r2, [sp, #0x34]
 *   @0x11ed84 ldr r3, [sp, #0x38]
 *   @0x11ed88 str r0, [sp, #0x28]
 *   @0x11ed8c mov r0, r5
 *   @0x11ed90 bl 0x171fa4 <_Z22GR_Surface_DrawGeneralifffffffffjjjjf>
 *   @0x11ed94 add sp, sp, #84
 *   @0x11ed98 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x11ed9c ldr r0, [pc, #0xc]
 *   @0x11eda0 add r0, pc, r0
 *   @0x11eda4 add sp, sp, #84
 *   @0x11eda8 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x11edac b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11edb0 eoreq r11, r1, r8, asr #9
 *
 * ══ §3/81 F_GPUSetBlendMode(RValue&, CInstance*, CInstance*, int, RValue*)  0x146754  size 384  96 条（0x146754..0x1468d4）
 * @func 0x146754 0x1468d4  size 384  96 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RenderStateManager::SetRenderState(eRenderState, unsigned int)×13 / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x164×1 / 0xc×1 / 0x4×1 / 0x10×1 / 0x138×1 / 0x128×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x146754 push {r4, r5, r6, lr}
 *   @0x146758 mov r1, #0
 *   @0x14675c ldr r5, [pc, #0x164]
 *   @0x146760 cmp r3, #1
 *   @0x146764 mov r4, r1
 *   @0x146768 mov r6, r3
 *   @0x14676c movt r1, #0xbff0
 *   @0x146770 str r4, [r0, #0xc]
 *   @0x146774 str r1, [r0, #0x4]
 *   @0x146778 add r5, pc, r5
 *   @0x14677c str r4, [r0]
 *   @0x146780 mov r1, r4
 *   @0x146784 ldr r0, [sp, #0x10]
 *   @0x146788 beq 0x14679c <_Z17F_GPUSetBlendModeR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x14678c ldr r0, [pc, #0x138]
 *   @0x146790 pop {r4, r5, r6, lr}
 *   @0x146794 add r0, pc, r0
 *   @0x146798 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14679c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1467a0 ldr r3, [pc, #0x128]
 *   @0x1467a4 mov r1, #6
 *   @0x1467a8 cmp r0, #2
 *   @0x1467ac beq 0x146854 <_Z17F_GPUSetBlendModeR6RValueP9CInstanceS2_iPS_+0x100>
 *   @0x1467b0 cmp r0, #3
 *   @0x1467b4 beq 0x146814 <_Z17F_GPUSetBlendModeR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x1467b8 ldr r5, [r5, r3]
 *   @0x1467bc cmp r0, #1
 *   @0x1467c0 mov r2, #5
 *   @0x1467c4 mov r0, r5
 *   @0x1467c8 beq 0x146894 <_Z17F_GPUSetBlendModeR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x1467cc bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x1467d0 mov r0, r5
 *   @0x1467d4 mov r1, #7
 *   @0x1467d8 mov r2, #6
 *   @0x1467dc bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x1467e0 mov r0, r5
 *   @0x1467e4 mov r1, #34
 *   @0x1467e8 mov r2, #5
 *   @0x1467ec bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x1467f0 mov r0, r5
 *   @0x1467f4 mov r1, #35
 *   @0x1467f8 mov r2, #6
 *   @0x1467fc bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x146800 mov r0, r5
 *   @0x146804 mov r2, r4
 *   @0x146808 mov r1, #33
 *   @0x14680c pop {r4, r5, r6, lr}
 *   @0x146810 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x146814 ldr r5, [r5, r3]
 *   @0x146818 mov r2, r6
 *   @0x14681c mov r0, r5
 *   @0x146820 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x146824 mov r0, r5
 *   @0x146828 mov r1, #7
 *   @0x14682c mov r2, #4
 *   @0x146830 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x146834 mov r0, r5
 *   @0x146838 mov r2, r6
 *   @0x14683c mov r1, #34
 *   @0x146840 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x146844 mov r0, r5
 *   @0x146848 mov r1, #35
 *   @0x14684c mov r2, #4
 *   @0x146850 b 0x1467fc <_Z17F_GPUSetBlendModeR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x146854 ldr r5, [r5, r3]
 *   @0x146858 mov r2, #5
 *   @0x14685c mov r0, r5
 *   @0x146860 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x146864 mov r0, r5
 *   @0x146868 mov r1, #7
 *   @0x14686c mov r2, #4
 *   @0x146870 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x146874 mov r0, r5
 *   @0x146878 mov r1, #34
 *   @0x14687c mov r2, #5
 *   @0x146880 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x146884 mov r0, r5
 *   @0x146888 mov r1, #35
 *   @0x14688c mov r2, #4
 *   @0x146890 b 0x1467fc <_Z17F_GPUSetBlendModeR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x146894 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x146898 mov r0, r5
 *   @0x14689c mov r1, #7
 *   @0x1468a0 mov r2, #2
 *   @0x1468a4 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x1468a8 mov r0, r5
 *   @0x1468ac mov r1, #34
 *   @0x1468b0 mov r2, #5
 *   @0x1468b4 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x1468b8 mov r0, r5
 *   @0x1468bc mov r1, #35
 *   @0x1468c0 mov r2, #2
 *   @0x1468c4 b 0x1467fc <_Z17F_GPUSetBlendModeR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x1468c8 .word 0x002ab4d8
 *   @0x1468cc andseq r11, pc, r0, ror r0
 *   @0x1468d0 .word 0xffffc0a8
 *
 * ══ §4/81 Path_Load(unsigned char*, unsigned int, unsigned char*)  0x1a7e74  size 384  96 条（0x1a7e74..0x1a7ff4）
 * @func 0x1a7e74 0x1a7ff4  size 384  96 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::SetLength(void**, unsigned int, char const*, int)×2 / operator new(unsigned int) / CPath::CPath() / CPath::LoadFromChunk(YYPath*, unsigned char*) / 0xb6538 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65a4 / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x4×4 / 0x14c×2 / 0x8×2 / 0xc×2 / 0x2×2 / 0x150×1 / 0x13c×1 / 0x100×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a7e74 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1a7e78 sub sp, sp, #20
 *   @0x1a7e7c ldr r9, [r0]
 *   @0x1a7e80 mov r3, #138
 *   @0x1a7e84 ldr r4, [pc, #0x150]
 *   @0x1a7e88 mov r8, r0
 *   @0x1a7e8c ldr r12, [pc, #0x14c]
 *   @0x1a7e90 ldr r10, [pc, #0x14c]
 *   @0x1a7e94 add r4, pc, r4
 *   @0x1a7e98 lsl r5, r9, #2
 *   @0x1a7e9c ldr r12, [pc, r12]
 *   @0x1a7ea0 add r10, pc, r10
 *   @0x1a7ea4 ldr r6, [pc, #0x13c]
 *   @0x1a7ea8 str r2, [sp, #0x8]
 *   @0x1a7eac add r0, r10, #4
 *   @0x1a7eb0 mov r2, r4
 *   @0x1a7eb4 mov r1, r5
 *   @0x1a7eb8 str r9, [r12]
 *   @0x1a7ebc bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1a7ec0 ldr r6, [pc, r6]
 *   @0x1a7ec4 mov r1, r5
 *   @0x1a7ec8 mov r2, r4
 *   @0x1a7ecc mov r3, #140
 *   @0x1a7ed0 mov r0, r6
 *   @0x1a7ed4 str r9, [r10]
 *   @0x1a7ed8 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1a7edc cmp r9, #0
 *   @0x1a7ee0 beq 0x1a7fc8 <_Z9Path_LoadPhjS_+0x154>
 *   @0x1a7ee4 ldr r3, [pc, #0x100]
 *   @0x1a7ee8 mov r4, #0
 *   @0x1a7eec str r9, [sp, #0x4]
 *   @0x1a7ef0 add r3, pc, r3
 *   @0x1a7ef4 str r3, [sp, #0xc]
 *   @0x1a7ef8 b 0x1a7fb4 <_Z9Path_LoadPhjS_+0x140>
 *   @0x1a7efc ldr r9, [pc, #0xec]
 *   @0x1a7f00 ldr r9, [pc, r9]
 *   @0x1a7f04 ldr r11, [r9]
 *   @0x1a7f08 adds r1, r11, r5
 *   @0x1a7f0c beq 0x1a7fd4 <_Z9Path_LoadPhjS_+0x160>
 *   @0x1a7f10 mov r0, #44
 *   @0x1a7f14 str r1, [sp]
 *   @0x1a7f18 bl 0x27c524 <_Znwj>
 *   @0x1a7f1c mov r7, r0
 *   @0x1a7f20 bl 0x1a6e9c <_ZN5CPathC2Ev>
 *   @0x1a7f24 ldr r1, [sp]
 *   @0x1a7f28 mov r0, r7
 *   @0x1a7f2c ldr r2, [sp, #0x8]
 *   @0x1a7f30 bl 0x1a7120 <_ZN5CPath13LoadFromChunkEP6YYPathPh>
 *   @0x1a7f34 ldr r12, [r11, r5]
 *   @0x1a7f38 cmp r12, #0
 *   @0x1a7f3c ldrne r3, [r9]
 *   @0x1a7f40 moveq r11, r12
 *   @0x1a7f44 addne r11, r3, r12
 *   @0x1a7f48 mov r0, r11
 *   @0x1a7f4c bl 0xb6538 <strlen@plt>
 *   @0x1a7f50 ldr r1, [sp, #0xc]
 *   @0x1a7f54 mov r3, #1
 *   @0x1a7f58 mov r2, #151
 *   @0x1a7f5c add r0, r0, r3
 *   @0x1a7f60 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1a7f64 mov r1, r11
 *   @0x1a7f68 mov r5, r0
 *   @0x1a7f6c bl 0xb65a4 <strcpy@plt>
 *   @0x1a7f70 ldr r2, [r6]
 *   @0x1a7f74 lsl r11, r4, #2
 *   @0x1a7f78 ldr r0, [r2, r4, lsl #2]
 *   @0x1a7f7c cmp r0, #0
 *   @0x1a7f80 beq 0x1a7f94 <_Z9Path_LoadPhjS_+0x120>
 *   @0x1a7f84 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1a7f88 ldr r2, [r6]
 *   @0x1a7f8c mov r3, #0
 *   @0x1a7f90 str r3, [r2, r4, lsl #2]
 *   @0x1a7f94 ldr r2, [r10, #0x4]
 *   @0x1a7f98 add r4, r4, #1
 *   @0x1a7f9c ldr r3, [sp, #0x4]
 *   @0x1a7fa0 str r7, [r2, r11]
 *   @0x1a7fa4 cmp r4, r3
 *   @0x1a7fa8 ldr r2, [r6]
 *   @0x1a7fac str r5, [r2, r11]
 *   @0x1a7fb0 beq 0x1a7fc8 <_Z9Path_LoadPhjS_+0x154>
 *   @0x1a7fb4 ldr r5, [r8, #0x4]!
 *   @0x1a7fb8 cmp r5, #0
 *   @0x1a7fbc bne 0x1a7efc <_Z9Path_LoadPhjS_+0x88>
 *   @0x1a7fc0 mov r7, r5
 *   @0x1a7fc4 b 0x1a7f70 <_Z9Path_LoadPhjS_+0xfc>
 *   @0x1a7fc8 mov r0, #1
 *   @0x1a7fcc add sp, sp, #20
 *   @0x1a7fd0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1a7fd4 mov r5, r1
 *   @0x1a7fd8 b 0x1a7fc0 <_Z9Path_LoadPhjS_+0x14c>
 *   @0x1a7fdc andseq r5, r10, r8, ror r2
 *   @0x1a7fe0 eoreq r8, r4, r0, lsr r9
 *   @0x1a7fe4 eorseq r10, r9, r8, lsl #13
 *   @0x1a7fe8 eoreq r8, r4, r0, lsl r9
 *   @0x1a7fec andseq r5, r10, r12, lsl r2
 *   @0x1a7ff0 eoreq r5, r4, r4, asr #20
 *
 * ══ §5/81 CDS_List::Insert(int, RValue*)  0x205f40  size 384  96 条（0x205f40..0x2060c0）
 * @func 0x205f40 0x2060c0  size 384  96 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6694 / 0xb65b0 / GetContextStackTop() / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*) / MemoryManager::SetLength(void**, unsigned int, char const*, int)
 * 字段偏移 top8: 0x4×10 / 0x8×5 / 0xc×4 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x205f40 push {r4, r5, r6, r7, r8, lr}
 *   @0x205f44 subs r5, r1, #0
 *   @0x205f48 mov r4, r0
 *   @0x205f4c mov r6, r2
 *   @0x205f50 poplt {r4, r5, r6, r7, r8, pc}
 *   @0x205f54 ldr r2, [r0, #0x4]
 *   @0x205f58 cmp r5, r2
 *   @0x205f5c popgt {r4, r5, r6, r7, r8, pc}
 *   @0x205f60 ldr r3, [r0, #0x8]
 *   @0x205f64 cmp r2, r3
 *   @0x205f68 bge 0x206090 <_ZN8CDS_List6InsertEiP6RValue+0x150>
 *   @0x205f6c ldr r8, [r4, #0xc]
 *   @0x205f70 rsb r2, r5, r2
 *   @0x205f74 add r7, r8, r5, lsl #4
 *   @0x205f78 lsl r2, r2, #4
 *   @0x205f7c add r0, r7, #16
 *   @0x205f80 mov r1, r7
 *   @0x205f84 bl 0xb6694 <memmove@plt>
 *   @0x205f88 mov r1, #0
 *   @0x205f8c mov r2, #16
 *   @0x205f90 mov r0, r7
 *   @0x205f94 bl 0xb65b0 <memset@plt>
 *   @0x205f98 ldr r3, [r6, #0xc]
 *   @0x205f9c ldr r2, [r6, #0x8]
 *   @0x205fa0 mov r1, #0
 *   @0x205fa4 str r1, [r8, r5, lsl #4]
 *   @0x205fa8 str r3, [r7, #0xc]
 *   @0x205fac ldr r3, [r6, #0xc]
 *   @0x205fb0 str r2, [r7, #0x8]
 *   @0x205fb4 bic r3, r3, #-16777216
 *   @0x205fb8 cmp r3, #14
 *   @0x205fbc addls pc, pc, r3, lsl #2
 *   @0x205fc0 b 0x206008 <_ZN8CDS_List6InsertEiP6RValue+0xc8>
 *   @0x205fc4 b 0x206018 <_ZN8CDS_List6InsertEiP6RValue+0xd8>
 *   @0x205fc8 b 0x206078 <_ZN8CDS_List6InsertEiP6RValue+0x138>
 *   @0x205fcc b 0x20604c <_ZN8CDS_List6InsertEiP6RValue+0x10c>
 *   @0x205fd0 b 0x206000 <_ZN8CDS_List6InsertEiP6RValue+0xc0>
 *   @0x205fd4 b 0x206008 <_ZN8CDS_List6InsertEiP6RValue+0xc8>
 *   @0x205fd8 b 0x206008 <_ZN8CDS_List6InsertEiP6RValue+0xc8>
 *   @0x205fdc b 0x206028 <_ZN8CDS_List6InsertEiP6RValue+0xe8>
 *   @0x205fe0 b 0x206000 <_ZN8CDS_List6InsertEiP6RValue+0xc0>
 *   @0x205fe4 b 0x206008 <_ZN8CDS_List6InsertEiP6RValue+0xc8>
 *   @0x205fe8 b 0x206008 <_ZN8CDS_List6InsertEiP6RValue+0xc8>
 *   @0x205fec b 0x206018 <_ZN8CDS_List6InsertEiP6RValue+0xd8>
 *   @0x205ff0 b 0x206008 <_ZN8CDS_List6InsertEiP6RValue+0xc8>
 *   @0x205ff4 b 0x206008 <_ZN8CDS_List6InsertEiP6RValue+0xc8>
 *   @0x205ff8 b 0x206018 <_ZN8CDS_List6InsertEiP6RValue+0xd8>
 *   @0x205ffc b 0x206000 <_ZN8CDS_List6InsertEiP6RValue+0xc0>
 *   @0x206000 ldr r3, [r6]
 *   @0x206004 str r3, [r8, r5, lsl #4]
 *   @0x206008 ldr r3, [r4, #0x4]
 *   @0x20600c add r3, r3, #1
 *   @0x206010 str r3, [r4, #0x4]
 *   @0x206014 pop {r4, r5, r6, r7, r8, pc}
 *   @0x206018 ldm r6, {r2, r3}
 *   @0x20601c str r2, [r8, r5, lsl #4]
 *   @0x206020 str r3, [r7, #0x4]
 *   @0x206024 b 0x206008 <_ZN8CDS_List6InsertEiP6RValue+0xc8>
 *   @0x206028 ldr r3, [r6]
 *   @0x20602c str r3, [r8, r5, lsl #4]
 *   @0x206030 ldr r3, [r6]
 *   @0x206034 cmp r3, #0
 *   @0x206038 beq 0x206008 <_ZN8CDS_List6InsertEiP6RValue+0xc8>
 *   @0x20603c bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x206040 ldr r1, [r6]
 *   @0x206044 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x206048 b 0x206008 <_ZN8CDS_List6InsertEiP6RValue+0xc8>
 *   @0x20604c ldr r3, [r6]
 *   @0x206050 cmp r3, #0
 *   @0x206054 str r3, [r8, r5, lsl #4]
 *   @0x206058 beq 0x206008 <_ZN8CDS_List6InsertEiP6RValue+0xc8>
 *   @0x20605c ldr r1, [r3, #0x8]
 *   @0x206060 ldr r2, [r3]
 *   @0x206064 cmp r1, #0
 *   @0x206068 streq r7, [r3, #0x8]
 *   @0x20606c add r2, r2, #1
 *   @0x206070 str r2, [r3]
 *   @0x206074 b 0x206008 <_ZN8CDS_List6InsertEiP6RValue+0xc8>
 *   @0x206078 ldr r3, [r6]
 *   @0x20607c cmp r3, #0
 *   @0x206080 ldrne r2, [r3, #0x4]
 *   @0x206084 addne r2, r2, #1
 *   @0x206088 strne r2, [r3, #0x4]
 *   @0x20608c b 0x206004 <_ZN8CDS_List6InsertEiP6RValue+0xc4>
 *   @0x206090 add r1, r2, #16
 *   @0x206094 ldr r2, [pc, #0x20]
 *   @0x206098 mov r3, #1296
 *   @0x20609c add r0, r0, #12
 *   @0x2060a0 add r2, pc, r2
 *   @0x2060a4 lsl r1, r1, #4
 *   @0x2060a8 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x2060ac ldr r2, [r4, #0x4]
 *   @0x2060b0 add r3, r2, #16
 *   @0x2060b4 str r3, [r4, #0x8]
 *   @0x2060b8 b 0x205f6c <_ZN8CDS_List6InsertEiP6RValue+0x2c>
 *   @0x2060bc andseq sp, r4, r12, asr #14
 *
 * ══ §6/81 png_handle_sRGB  0x2ac694  size 384  96 条（0x2ac694..0x2ac814）
 * @func 0x2ac694 0x2ac814  size 384  96 条
 * 部分覆盖: 本节 96/169 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_warning×4 / png_error / png_crc_finish / png_handle_sRGB+0x7e / 0x14bd724 / 0x20bd544 / 0xec1524 / 0x4c163c
 * 字段偏移 top8: 0x144×1 / 0x134×1 / 0x8×1 / 0x120×1 / 0xd4×1 / 0xd0×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ac694 push {r0, r1, r4, r5, r6, lr}
 *   @0x2ac698 ldr.w r3, [r0, #0x12c]
 *   @0x2ac69c mov r5, r0
 *   @0x2ac6a0 lsls r1, r3, #0x1f
 *   @0x2ac6a4 ldr r1, [pc, #0x144]
 *   @0x2ac6a8 bl 0x2a642c <png_error>
 *   @0x2ac6ac b 0x2ac6c4 <png_handle_sRGB+0x30>
 *   @0x2ac6b0 bpl 0x2ac6b8 <png_handle_sRGB+0x24>
 *   @0x2ac6b4 add r1, pc
 *   @0x2ac6b8 lsls r3, r3, #0x1e
 *   @0x2ac6bc ldr r1, [pc, #0x134]
 *   @0x2ac6c0 bl 0x2a6474 <png_warning>
 *   @0x2ac6c4 mov r0, r5
 *   @0x2ac6c8 ldr r3, [r4, #0x8]
 *   @0x2ac6cc bpl 0x2ac6d4 <png_handle_sRGB+0x40>
 *   @0x2ac6d0 add r1, pc
 *   @0x2ac6d4 cmp r6, #0x1
 *   @0x2ac6d8 ldr r1, [pc, #0x120]
 *   @0x2ac6dc bl 0x2a6474 <png_warning>
 *   @0x2ac6e0 mov r0, r5
 *   @0x2ac6e4 bl 0x2abc94 <png_crc_finish>
 *   @0x2ac6e8 b 0x2ac7e6 <png_handle_sRGB+0x152>
 *   @0x2ac6ec mov r2, r6
 *   @0x2ac6f0 strtmi pc, [r8], -sp, lsl #21
 *   @0x2ac6f4 movs r1, #0x0
 *   @0x2ac6f8 stmdahs r0, {r0, r2, r3, r6, r7, r9, r11, r12, sp, lr, pc}
 *   @0x2ac6fc bne 0x2ac7e6 <png_handle_sRGB+0x152>
 *   @0x2ac700 cdphs p0, #0x0, c6, c3, c4, #0x0
 *   @0x2ac704 ble 0x2ac712 <png_handle_sRGB+0x7e>
 *   @0x2ac708 mov r0, r5
 *   @0x2ac70c bl 0x2a6474 <png_warning>
 *   @0x2ac710 b 0x2ac7e6 <png_handle_sRGB+0x152>
 *   @0x2ac714 beq 0x2ac7ce <png_handle_sRGB+0x13a>
 *   @0x2ac718 lsls r2, r3, #0x1f
 *   @0x2ac71c ldr.w r3, [r4, #0xfc]
 *   @0x2ac720 sub.w r3, r3, #0xaf00
 *   @0x2ac724 subs r3, #0xc8
 *   @0x2ac728 stmdble lr, {r1, r3, r4, r5, r6, r8, r9, r10, r11, r12, sp, lr}
 *   @0x2ac72c ldr r1, [pc, #0xd4]
 *   @0x2ac730 add r1, pc
 *   @0x2ac734 ldmdami r4!, {r0, r1, r2, r3, r4, r7, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2ac738 ldr r1, [pc, #0xd0]
 *   @0x2ac73c ldr r0, [r0]
 *   @0x2ac740 adclo r2, r8, r0, ror #5
 *   @0x2ac744 add r1, pc
 *   @0x2ac748 stmvs r3!, {r1, r2, r3, r5, r7, r11, sp, lr, pc}
 *   @0x2ac74c lsls r3, r3, #0x1d
 *   @0x2ac750 ldr.w r3, [r4, #0x100]
 *   @0x2ac754 sub.w r3, r3, #0x7600
 *   @0x2ac758 subs r3, #0x3e
 *   @0x2ac75c ldmdale r12!, {r1, r3, r4, r5, r6, r7, r8, r9, r10, r11, sp, lr}
 *   @0x2ac760 ldr.w r3, [r4, #0x104]
 *   @0x2ac764 sub.w r3, r3, #0x7c80
 *   @0x2ac768 subs r3, #0x1c
 *   @0x2ac76c ldmdale r4!, {r1, r3, r4, r5, r6, r7, r8, r9, r10, r11, sp, lr}
 *   @0x2ac770 ldr.w r3, [r4, #0x108]
 *   @0x2ac774 sub.w r3, r3, #0xf600
 *   @0x2ac778 subs r3, #0x18
 *   @0x2ac77c stmdale r12!, {r1, r3, r4, r5, r6, r7, r8, r9, r10, r11, sp, lr}
 *   @0x2ac780 ldr.w r3, [r4, #0x10c]
 *   @0x2ac784 sub.w r3, r3, #0x7d00
 *   @0x2ac788 cmp.w r3, #0x7d0
 *   @0x2ac78c bhi 0x2ac7da <png_handle_sRGB+0x146>
 *   @0x2ac790 .word 0xf5a33110
 *   @0x2ac794 bllo 0x14bd724 <b2_toiTime+0xd64280>
 *   @0x2ac798 cmp.w r3, #0x7d0
 *   @0x2ac79c bhi 0x2ac7da <png_handle_sRGB+0x146>
 *   @0x2ac7a0 .word 0xf5a33114
 *   @0x2ac7a4 bllo 0x20bd544 <b2_toiTime+0x19640a0>
 *   @0x2ac7a8 cmp.w r3, #0x7d0
 *   @0x2ac7ac bhi 0x2ac7da <png_handle_sRGB+0x146>
 *   @0x2ac7b0 .word 0xf5a33118
 *   @0x2ac7b4 bllo 0xec1524 <b2_toiTime+0x768080>
 *   @0x2ac7b8 cmp.w r3, #0x7d0
 *   @0x2ac7bc bhi 0x2ac7da <png_handle_sRGB+0x146>
 *   @0x2ac7c0 .word 0xf5a3311c
 *   @0x2ac7c4 bllo 0x4c163c <SrcVerts+0x1e680>
 *   @0x2ac7c8 cmp.w r3, #0x7d0
 *   @0x2ac7cc bhi 0x2ac7da <png_handle_sRGB+0x146>
 *   @0x2ac7d0 mov r1, r4
 *   @0x2ac7d4 bl 0x2aed48 <png_set_sRGB_gAMA_and_cHRM>
 *   @0x2ac7d8 b 0x2ac7e6 <png_handle_sRGB+0x152>
 *   @0x2ac7dc mov r0, r5
 *   @0x2ac7e0 bl 0x2a6474 <png_warning>
 *   @0x2ac7e4 b 0x2ac7ce <png_handle_sRGB+0x13a>
 *   @0x2ac7e8 pop {r4, r5, r6, pc}
 *   @0x2ac7ec lsrs r2, r0, #0x5
 *   @0x2ac7f0 lsrs r5, r1, #0x5
 *   @0x2ac7f4 lsrs r3, r3, #0x5
 *   @0x2ac7f8 lsrs r1, r4, #0x5
 *   @0x2ac7fc lsrs r4, r5, #0x5
 *   @0x2ac800 lsrs r0, r3, #0x5
 *   @0x2ac804 lsls r7, r0, #0x1c
 *   @0x2ac808 ldr r5, [pc, #0x38]
 *   @0x2ac80c lsrs r2, r6, #0x4
 *   @0x2ac810 lsls r2, r3, #0x1e
 *
 * ══ §7/81 png_handle_sCAL  0x2ad350  size 384  96 条（0x2ad350..0x2ad4d0）
 * @func 0x2ad350 0x2ad4d0  size 384  96 条
 * 部分覆盖: 本节 96/168 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_warning×3 / png_crc_finish×2 / png_error / png_crc_read / 0xb6658 / png_handle_sCAL+0xc6 / 0x42789c / png_set_sCAL
 * 字段偏移 top8: 0x140×1 / 0x12c×1 / 0x104×1 / 0x14×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ad350 push.w {r4, r5, r6, r7, r8, r9, lr}
 *   @0x2ad354 vpush {d8}
 *   @0x2ad358 mov r6, r1
 *   @0x2ad35c addlt r3, r7, r12, lsr #2
 *   @0x2ad360 mov r4, r0
 *   @0x2ad364 lsls r1, r3, #0x1f
 *   @0x2ad368 ldr r1, [pc, #0x140]
 *   @0x2ad36c bl 0x2a642c <png_error>
 *   @0x2ad370 b 0x2ad3a2 <png_handle_sCAL+0x52>
 *   @0x2ad374 bpl 0x2ad37c <png_handle_sCAL+0x2c>
 *   @0x2ad378 add r1, pc
 *   @0x2ad37c cbz r6, 0x2ad396 <png_handle_sCAL+0x46>
 *   @0x2ad380 lsls r3, r3, #0x11
 *   @0x2ad384 ldr r1, [pc, #0x12c]
 *   @0x2ad388 bl 0x2a6474 <png_warning>
 *   @0x2ad38c mov r0, r4
 *   @0x2ad390 bl 0x2abc94 <png_crc_finish>
 *   @0x2ad394 b 0x2ad4a2 <png_handle_sCAL+0x152>
 *   @0x2ad398 bhi 0x2ad3a2 <png_handle_sCAL+0x52>
 *   @0x2ad39c mov r0, r4
 *   @0x2ad3a0 b 0x2ad388 <png_handle_sCAL+0x38>
 *   @0x2ad3a4 mov r0, r4
 *   @0x2ad3a8 .word 0x4601fcb6
 *   @0x2ad3ac str.w r0, [r4, #0x330]
 *   @0x2ad3b0 mov r0, r4
 *   @0x2ad3b4 ldr r1, [pc, #0x104]
 *   @0x2ad3b8 b 0x2ad388 <png_handle_sCAL+0x38>
 *   @0x2ad3bc bl 0x2abc0c <png_crc_read>
 *   @0x2ad3c0 mov r0, r4
 *   @0x2ad3c4 bl 0x2abc94 <png_crc_finish>
 *   @0x2ad3c8 mov r7, r0
 *   @0x2ad3cc bne 0x2ad470 <png_handle_sCAL+0x120>
 *   @0x2ad3d0 .word 0xf10d3330
 *   @0x2ad3d4 .word 0x46490914
 *   @0x2ad3d8 strb r0, [r3, r5]
 *   @0x2ad3dc andlo r0, r1, r0, lsr r3
 *   @0x2ad3e0 blx 0xb6658 <strtod@plt>
 *   @0x2ad3e4 ldr r3, [sp, #0x14]
 *   @0x2ad3e8 vmov d8, r0, r1
 *   @0x2ad3ec cbz r3, 0x2ad3f6 <png_handle_sCAL+0xa6>
 *   @0x2ad3f0 mov r0, r4
 *   @0x2ad3f4 b 0x2ad434 <png_handle_sCAL+0xe4>
 *   @0x2ad3f8 mrrcne p3, #0x3, r2, r3, c0
 *   @0x2ad3fc mov r1, r3
 *   @0x2ad400 ldrb r7, [r1]
 *   @0x2ad404 bne 0x2ad3fc <png_handle_sCAL+0xac>
 *   @0x2ad408 mov r8, r3
 *   @0x2ad40c bls 0x2ad416 <png_handle_sCAL+0xc6>
 *   @0x2ad410 mov r0, r4
 *   @0x2ad414 b 0x2ad434 <png_handle_sCAL+0xe4>
 *   @0x2ad418 mov r1, r9
 *   @0x2ad41c blls 0x42789c <g_RomDisk+0x3007c>
 *   @0x2ad420 ldrb.w r9, [r3]
 *   @0x2ad424 vmov d7, r0, r1
 *   @0x2ad428 cmp.w r9, #0x0
 *   @0x2ad42c beq 0x2ad448 <png_handle_sCAL+0xf8>
 *   @0x2ad430 mov r0, r4
 *   @0x2ad434 bl 0x2a6474 <png_warning>
 *   @0x2ad438 mov r0, r4
 *   @0x2ad43c .word 0xf7f91330
 *   @0x2ad440 .word 0xf8c4fc5d
 *   @0x2ad444 eor r7, r12, r0, lsr r3
 *   @0x2ad448 ldr.w r3, [r4, #0x330]
 *   @0x2ad44c add r5, r3
 *   @0x2ad450 bhi 0x2ad466 <png_handle_sCAL+0x116>
 *   @0x2ad454 vsqrt.f64 d24, d0
 *   @0x2ad458 stmdble r4, {r4, r9, r11, r12, sp, lr, pc}
 *   @0x2ad45c vcmpe.f64 d7, #0
 *   @0x2ad460 vmrs APSR_nzcv, fpscr
 *   @0x2ad464 bhi 0x2ad482 <png_handle_sCAL+0x132>
 *   @0x2ad468 mov r0, r4
 *   @0x2ad46c bl 0x2a6474 <png_warning>
 *   @0x2ad470 mov r0, r4
 *   @0x2ad474 .word 0xf7f91330
 *   @0x2ad478 movwhs pc, #0xc41
 *   @0x2ad47c str.w r3, [r4, #0x330]
 *   @0x2ad480 b 0x2ad4a2 <png_handle_sCAL+0x152>
 *   @0x2ad484 vstr d8, [sp]
 *   @0x2ad488 strd r0, r1, [sp, #8]
 *   @0x2ad48c mov r0, r4
 *   @0x2ad490 bl 0x2aec48 <png_set_sCAL>
 *   @0x2ad494 mov r0, r4
 *   @0x2ad498 .word 0xf7f91330
 *   @0x2ad49c .word 0xf8c4fc2f
 *   @0x2ad4a0 andlt r9, r7, r0, lsr r3
 *   @0x2ad4a4 vpop {d8}
 *   @0x2ad4a8 pop.w {r4, r5, r6, r7, r8, r9, pc}
 *   @0x2ad4ac lsls r0, r0, #0xa
 *   @0x2ad4b0 lsls r3, r1, #0xa
 *   @0x2ad4b4 lsls r5, r2, #0xa
 *   @0x2ad4b8 lsls r2, r2, #0xa
 *   @0x2ad4bc lsls r7, r1, #0xa
 *   @0x2ad4c0 lsls r5, r7, #0x9
 *   @0x2ad4c4 lsls r2, r0, #0xa
 *   @0x2ad4c8 lsls r7, r6, #0x9
 *   @0x2ad4cc lsls r5, r4, #0x9
 *
 * ══ §8/81 b2PolygonShape::RayCast(b2RayCastOutput*, b2RayCastInput const&, b2Transform const&, int) const  0x2c5730  size 384  96 条（0x2c5730..0x2c58b0）
 * @func 0x2c5730 0x2c58b0  size 384  96 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2PolygonShape::RayCast(b2RayCastOutput*, b2RayCastInput const&, b2Transform const&, int) const+0x128 / b2PolygonShape::RayCast(b2RayCastOutput*, b2RayCastInput const&, b2Transform const&, int) const+0x90 / b2PolygonShape::RayCast(b2RayCastOutput*, b2RayCastInput const&, b2Transform const&, int) const+0xec
 * 字段偏移 top8: 0x4×2 / 0x94×1 / 0x-4×1
 * VFP 指令 62 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c5730 vldr s14, [r3, #4]
 *   @0x2c5734 vldr s8, [r2, #4]
 *   @0x2c5738 vldr s6, [r2, #12]
 *   @0x2c573c vsub.f32 s8, s8, s14
 *   @0x2c5740 vldr s4, [r3, #12]
 *   @0x2c5744 vldr s3, [r3, #8]
 *   @0x2c5748 vldr s15, [r3]
 *   @0x2c574c vldr s13, [r2]
 *   @0x2c5750 vldr s12, [r2, #8]
 *   @0x2c5754 ldr r12, [r0, #0x94]
 *   @0x2c5758 str r4, [sp, #-0x4]!
 *   @0x2c575c vldr s10, [r2, #16]
 *   @0x2c5760 cmp r12, #0
 *   @0x2c5764 vsub.f32 s6, s6, s14
 *   @0x2c5768 vmul.f32 s9, s8, s3
 *   @0x2c576c vmul.f32 s5, s4, s6
 *   @0x2c5770 vmul.f32 s8, s8, s4
 *   @0x2c5774 vmul.f32 s6, s3, s6
 *   @0x2c5778 vsub.f32 s13, s13, s15
 *   @0x2c577c vsub.f32 s15, s12, s15
 *   @0x2c5780 vneg.f32 s14, s3
 *   @0x2c5784 vmla.f32 s9, s13, s4
 *   @0x2c5788 vmla.f32 s8, s13, s14
 *   @0x2c578c vmla.f32 s5, s14, s15
 *   @0x2c5790 vmla.f32 s6, s4, s15
 *   @0x2c5794 vsub.f32 s5, s5, s8
 *   @0x2c5798 vsub.f32 s6, s6, s9
 *   @0x2c579c ble 0x2c5858 <_ZNK14b2PolygonShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0x128>
 *   @0x2c57a0 add r3, r0, #84
 *   @0x2c57a4 mov r2, #0
 *   @0x2c57a8 mvn r4, #0
 *   @0x2c57ac vldr s7, [pc, #248]
 *   @0x2c57b0 b 0x2c57dc <_ZNK14b2PolygonShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0xac>
 *   @0x2c57b4 vcmpe.f32 s14, #0
 *   @0x2c57b8 vmrs APSR_nzcv, fpscr
 *   @0x2c57bc bmi 0x2c5858 <_ZNK14b2PolygonShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0x128>
 *   @0x2c57c0 vcmpe.f32 s7, s10
 *   @0x2c57c4 add r2, r2, #1
 *   @0x2c57c8 add r3, r3, #8
 *   @0x2c57cc vmrs APSR_nzcv, fpscr
 *   @0x2c57d0 bgt 0x2c5858 <_ZNK14b2PolygonShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0x128>
 *   @0x2c57d4 cmp r2, r12
 *   @0x2c57d8 beq 0x2c5868 <_ZNK14b2PolygonShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0x138>
 *   @0x2c57dc vldr s12, [r3, #4]
 *   @0x2c57e0 vmul.f32 s15, s5, s12
 *   @0x2c57e4 vldr s13, [r3]
 *   @0x2c57e8 vldr s14, [r3, #-60]
 *   @0x2c57ec vldr s11, [r3, #-64]
 *   @0x2c57f0 vmla.f32 s15, s6, s13
 *   @0x2c57f4 vsub.f32 s14, s14, s8
 *   @0x2c57f8 vmul.f32 s14, s14, s12
 *   @0x2c57fc vsub.f32 s12, s11, s9
 *   @0x2c5800 vcmp.f32 s15, #0
 *   @0x2c5804 vmla.f32 s14, s12, s13
 *   @0x2c5808 vmrs APSR_nzcv, fpscr
 *   @0x2c580c beq 0x2c57b4 <_ZNK14b2PolygonShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0x84>
 *   @0x2c5810 vcmpe.f32 s15, #0
 *   @0x2c5814 vmrs APSR_nzcv, fpscr
 *   @0x2c5818 bmi 0x2c583c <_ZNK14b2PolygonShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0x10c>
 *   @0x2c581c vcmpe.f32 s15, #0
 *   @0x2c5820 vmrs APSR_nzcv, fpscr
 *   @0x2c5824 ble 0x2c57c0 <_ZNK14b2PolygonShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0x90>
 *   @0x2c5828 vmul.f32 s13, s10, s15
 *   @0x2c582c vcmpe.f32 s13, s14
 *   @0x2c5830 vmrs APSR_nzcv, fpscr
 *   @0x2c5834 vdivgt.f32 s10, s14, s15
 *   @0x2c5838 b 0x2c57c0 <_ZNK14b2PolygonShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0x90>
 *   @0x2c583c vmul.f32 s13, s7, s15
 *   @0x2c5840 vcmpe.f32 s13, s14
 *   @0x2c5844 vmrs APSR_nzcv, fpscr
 *   @0x2c5848 ble 0x2c581c <_ZNK14b2PolygonShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0xec>
 *   @0x2c584c mov r4, r2
 *   @0x2c5850 vdiv.f32 s7, s14, s15
 *   @0x2c5854 b 0x2c57c0 <_ZNK14b2PolygonShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0x90>
 *   @0x2c5858 mov r3, #0
 *   @0x2c585c ldr r4, [sp], #4
 *   @0x2c5860 mov r0, r3
 *   @0x2c5864 bx lr
 *   @0x2c5868 cmn r4, #1
 *   @0x2c586c beq 0x2c5858 <_ZNK14b2PolygonShape7RayCastEP15b2RayCastOutputRK14b2RayCastInputRK11b2Transformi+0x128>
 *   @0x2c5870 add r4, r4, #10
 *   @0x2c5874 mov r3, #1
 *   @0x2c5878 vstr s7, [r1, #8]
 *   @0x2c587c add r0, r0, r4, lsl #3
 *   @0x2c5880 vldr s15, [r0, #8]
 *   @0x2c5884 vmul.f32 s14, s3, s15
 *   @0x2c5888 vldr s13, [r0, #4]
 *   @0x2c588c ldr r4, [sp], #4
 *   @0x2c5890 mov r0, r3
 *   @0x2c5894 vmul.f32 s15, s4, s15
 *   @0x2c5898 vnmls.f32 s14, s4, s13
 *   @0x2c589c vmla.f32 s15, s3, s13
 *   @0x2c58a0 vstr s14, [r1]
 *   @0x2c58a4 vstr s15, [r1, #4]
 *   @0x2c58a8 bx lr
 *   @0x2c58ac andeq r0, r0, r0
 *
 * ══ §9/81 b2WheelJoint::Dump()  0x2d3a18  size 384  96 条（0x2d3a18..0x2d3b98）
 * @func 0x2d3a18 0x2d3b98  size 384  96 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Log(char const*, ...)×12
 * 字段偏移 top8: 0x8×2 / 0x30×1 / 0x34×1 / 0x130×1 / 0x120×1 / 0x114×1 / 0x108×1 / 0x3d×1
 * VFP 指令 30 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d3a18 push {r4, r5, r6, lr}
 *   @0x2d3a1c mov r4, r0
 *   @0x2d3a20 ldr r2, [r4, #0x30]
 *   @0x2d3a24 sub sp, sp, #8
 *   @0x2d3a28 ldr r3, [r4, #0x34]
 *   @0x2d3a2c ldr r0, [pc, #0x130]
 *   @0x2d3a30 ldr r6, [r2, #0x8]
 *   @0x2d3a34 add r0, pc, r0
 *   @0x2d3a38 ldr r5, [r3, #0x8]
 *   @0x2d3a3c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d3a40 ldr r0, [pc, #0x120]
 *   @0x2d3a44 mov r1, r6
 *   @0x2d3a48 add r0, pc, r0
 *   @0x2d3a4c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d3a50 ldr r0, [pc, #0x114]
 *   @0x2d3a54 mov r1, r5
 *   @0x2d3a58 add r0, pc, r0
 *   @0x2d3a5c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d3a60 ldr r0, [pc, #0x108]
 *   @0x2d3a64 ldrb r1, [r4, #0x3d]
 *   @0x2d3a68 add r0, pc, r0
 *   @0x2d3a6c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d3a70 vldr s13, [r4, #76]
 *   @0x2d3a74 vldr s14, [r4, #80]
 *   @0x2d3a78 vcvt.f64.f32 d5, s13
 *   @0x2d3a7c ldr r0, [pc, #0xf0]
 *   @0x2d3a80 add r0, pc, r0
 *   @0x2d3a84 vcvt.f64.f32 d7, s14
 *   @0x2d3a88 vmov r2, r3, d5
 *   @0x2d3a8c vstr d7, [sp]
 *   @0x2d3a90 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d3a94 vldr s13, [r4, #84]
 *   @0x2d3a98 vldr s14, [r4, #88]
 *   @0x2d3a9c vcvt.f64.f32 d5, s13
 *   @0x2d3aa0 ldr r0, [pc, #0xd0]
 *   @0x2d3aa4 add r0, pc, r0
 *   @0x2d3aa8 vcvt.f64.f32 d7, s14
 *   @0x2d3aac vmov r2, r3, d5
 *   @0x2d3ab0 vstr d7, [sp]
 *   @0x2d3ab4 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d3ab8 vldr s13, [r4, #92]
 *   @0x2d3abc vldr s14, [r4, #96]
 *   @0x2d3ac0 vcvt.f64.f32 d5, s13
 *   @0x2d3ac4 ldr r0, [pc, #0xb0]
 *   @0x2d3ac8 add r0, pc, r0
 *   @0x2d3acc vcvt.f64.f32 d7, s14
 *   @0x2d3ad0 vmov r2, r3, d5
 *   @0x2d3ad4 vstr d7, [sp]
 *   @0x2d3ad8 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d3adc ldr r0, [pc, #0x9c]
 *   @0x2d3ae0 ldrb r1, [r4, #0x80]
 *   @0x2d3ae4 add r0, pc, r0
 *   @0x2d3ae8 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d3aec vldr s15, [r4, #124]
 *   @0x2d3af0 vcvt.f64.f32 d6, s15
 *   @0x2d3af4 ldr r0, [pc, #0x88]
 *   @0x2d3af8 add r0, pc, r0
 *   @0x2d3afc vmov r2, r3, d6
 *   @0x2d3b00 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d3b04 vldr s15, [r4, #120]
 *   @0x2d3b08 vcvt.f64.f32 d5, s15
 *   @0x2d3b0c ldr r0, [pc, #0x74]
 *   @0x2d3b10 add r0, pc, r0
 *   @0x2d3b14 vmov r2, r3, d5
 *   @0x2d3b18 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d3b1c vldr s15, [r4, #68]
 *   @0x2d3b20 vcvt.f64.f32 d6, s15
 *   @0x2d3b24 ldr r0, [pc, #0x60]
 *   @0x2d3b28 add r0, pc, r0
 *   @0x2d3b2c vmov r2, r3, d6
 *   @0x2d3b30 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d3b34 vldr s15, [r4, #72]
 *   @0x2d3b38 vcvt.f64.f32 d5, s15
 *   @0x2d3b3c ldr r0, [pc, #0x4c]
 *   @0x2d3b40 add r0, pc, r0
 *   @0x2d3b44 vmov r2, r3, d5
 *   @0x2d3b48 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d3b4c ldr r0, [pc, #0x40]
 *   @0x2d3b50 ldr r1, [r4, #0x38]
 *   @0x2d3b54 add r0, pc, r0
 *   @0x2d3b58 add sp, sp, #8
 *   @0x2d3b5c pop {r4, r5, r6, lr}
 *   @0x2d3b60 b 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d3b64 andeq r8, r8, r12, asr r9
 *   @0x2d3b68 andeq r8, r8, r4, ror #8
 *   @0x2d3b6c andeq r8, r8, r0, ror r4
 *   @0x2d3b70 andeq r8, r8, r12, ror r4
 *   @0x2d3b74 andeq r8, r8, r8, lsl #9
 *   @0x2d3b78 muleq r8, r0, r4
 *   @0x2d3b7c andeq r8, r8, r12, lsr r6
 *   @0x2d3b80 ldrdeq r8, r9, [r8], -r0
 *   @0x2d3b84 ldrdeq r8, r9, [r8], -r12
 *   @0x2d3b88 andeq r8, r8, r4, lsl r8
 *   @0x2d3b8c andeq r8, r8, r0, asr r4
 *   @0x2d3b90 andeq r8, r8, r8, asr r4
 *   @0x2d3b94 andeq r8, r8, r4, ror #8
 *
 * ══ §10/81 VM::GetStructureCounts(Buffer_Standard*)  0xd890c  size 380  95 条（0xd890c..0xd8a88）
 * @func 0xd890c 0xd8a88  size 380  95 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetTheStacks(int&) / GetTheQueues(int&) / GetThePriorityQueues(int&) / GetTheGrids(int&)
 * 字段偏移 top8: 0x38×6 / 0x30×6 / 0x8×6 / 0x138×1 / 0xd0×1
 * VFP 指令 24 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd890c push {r4, r5, r6, r7, r8, lr}
 *   @0xd8910 sub sp, sp, #16
 *   @0xd8914 mov r6, r0
 *   @0xd8918 add r8, r6, #44
 *   @0xd891c mov r0, sp
 *   @0xd8920 mov r7, #0
 *   @0xd8924 bl 0xffc9c <_Z12GetTheStacksRi>
 *   @0xd8928 add r0, sp, #4
 *   @0xd892c bl 0xffee8 <_Z12GetTheQueuesRi>
 *   @0xd8930 add r0, sp, #8
 *   @0xd8934 bl 0x100244 <_Z20GetThePriorityQueuesRi>
 *   @0xd8938 add r0, sp, #12
 *   @0xd893c bl 0x10026c <_Z11GetTheGridsRi>
 *   @0xd8940 ldr r3, [pc, #0x138]
 *   @0xd8944 ldr r12, [r6]
 *   @0xd8948 mov r2, r8
 *   @0xd894c ldr r3, [pc, r3]
 *   @0xd8950 str r7, [r6, #0x38]
 *   @0xd8954 mov r0, r6
 *   @0xd8958 mov r1, #5
 *   @0xd895c ldr r4, [r3]
 *   @0xd8960 vmov s15, r4
 *   @0xd8964 vcvt.f64.u32 d7, s15
 *   @0xd8968 vmov r4, r5, d7
 *   @0xd896c vstr s14, [r6, #44]
 *   @0xd8970 str r5, [r6, #0x30]
 *   @0xd8974 ldr r3, [r12, #0x8]
 *   @0xd8978 blx r3
 *   @0xd897c vldr s15, [sp]
 *   @0xd8980 vcvt.f64.u32 d7, s15
 *   @0xd8984 ldr r3, [r6]
 *   @0xd8988 mov r2, r8
 *   @0xd898c str r7, [r6, #0x38]
 *   @0xd8990 mov r0, r6
 *   @0xd8994 mov r1, #5
 *   @0xd8998 vmov r4, r5, d7
 *   @0xd899c vstr s14, [r6, #44]
 *   @0xd89a0 str r5, [r6, #0x30]
 *   @0xd89a4 ldr r3, [r3, #0x8]
 *   @0xd89a8 blx r3
 *   @0xd89ac ldr r3, [pc, #0xd0]
 *   @0xd89b0 ldr r12, [r6]
 *   @0xd89b4 mov r2, r8
 *   @0xd89b8 ldr r3, [pc, r3]
 *   @0xd89bc str r7, [r6, #0x38]
 *   @0xd89c0 mov r0, r6
 *   @0xd89c4 mov r1, #5
 *   @0xd89c8 ldr r4, [r3]
 *   @0xd89cc vmov s15, r4
 *   @0xd89d0 vcvt.f64.u32 d7, s15
 *   @0xd89d4 vmov r4, r5, d7
 *   @0xd89d8 vstr s14, [r6, #44]
 *   @0xd89dc str r5, [r6, #0x30]
 *   @0xd89e0 ldr r3, [r12, #0x8]
 *   @0xd89e4 blx r3
 *   @0xd89e8 vldr s15, [sp, #4]
 *   @0xd89ec vcvt.f64.u32 d7, s15
 *   @0xd89f0 ldr r3, [r6]
 *   @0xd89f4 mov r2, r8
 *   @0xd89f8 str r7, [r6, #0x38]
 *   @0xd89fc mov r0, r6
 *   @0xd8a00 mov r1, #5
 *   @0xd8a04 vmov r4, r5, d7
 *   @0xd8a08 vstr s14, [r6, #44]
 *   @0xd8a0c str r5, [r6, #0x30]
 *   @0xd8a10 ldr r3, [r3, #0x8]
 *   @0xd8a14 blx r3
 *   @0xd8a18 vldr s15, [sp, #8]
 *   @0xd8a1c vcvt.f64.u32 d7, s15
 *   @0xd8a20 ldr r3, [r6]
 *   @0xd8a24 mov r2, r8
 *   @0xd8a28 str r7, [r6, #0x38]
 *   @0xd8a2c mov r0, r6
 *   @0xd8a30 mov r1, #5
 *   @0xd8a34 vmov r4, r5, d7
 *   @0xd8a38 vstr s14, [r6, #44]
 *   @0xd8a3c str r5, [r6, #0x30]
 *   @0xd8a40 ldr r3, [r3, #0x8]
 *   @0xd8a44 blx r3
 *   @0xd8a48 vldr s15, [sp, #12]
 *   @0xd8a4c vcvt.f64.u32 d7, s15
 *   @0xd8a50 ldr r3, [r6]
 *   @0xd8a54 mov r2, r8
 *   @0xd8a58 str r7, [r6, #0x38]
 *   @0xd8a5c mov r0, r6
 *   @0xd8a60 mov r1, #5
 *   @0xd8a64 vmov r4, r5, d7
 *   @0xd8a68 vstr s14, [r6, #44]
 *   @0xd8a6c str r5, [r6, #0x30]
 *   @0xd8a70 ldr r3, [r3, #0x8]
 *   @0xd8a74 blx r3
 *   @0xd8a78 add sp, sp, #16
 *   @0xd8a7c pop {r4, r5, r6, r7, r8, pc}
 *   @0xd8a80 eorseq r5, r1, r0, lsr r3
 *   @0xd8a84 eorseq r5, r1, r0, asr #5
 *
 * ══ §11/81 F_PositionMeeting(RValue&, CInstance*, CInstance*, int, RValue*)  0x10d77c  size 380  95 条（0x10d77c..0x10d8f8）
 * @func 0x10d77c 0x10d8f8  size 380  95 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / YYGetFloat(RValue const*, int)×2 / ShouldUseFastCollision(int, CObjectGM**) / Command_ObjectAt(float, float, int) / UpdateTree() / RTree<CInstance*, int, float, 6, 2>::Search(int const*, int const*, bool (*)(CInstance*, void*), void*)
 * 字段偏移 top8: 0x4×2 / 0x60×2 / 0x40×1 / 0xc×1 / 0x-14×1 / 0x10×1 / 0x18×1 / 0x44×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10d77c push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x10d780 sub sp, sp, #36
 *   @0x10d784 mov r5, r0
 *   @0x10d788 mov r6, r1
 *   @0x10d78c ldr r7, [sp, #0x40]
 *   @0x10d790 mov r1, #2
 *   @0x10d794 mov r8, r2
 *   @0x10d798 mov r0, r7
 *   @0x10d79c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x10d7a0 adds r2, r6, #0
 *   @0x10d7a4 mov r3, #13
 *   @0x10d7a8 str r3, [r5, #0xc]
 *   @0x10d7ac movne r2, #1
 *   @0x10d7b0 mov r3, #0
 *   @0x10d7b4 str r3, [r5]
 *   @0x10d7b8 add r1, sp, #32
 *   @0x10d7bc str r3, [r5, #0x4]
 *   @0x10d7c0 cmn r0, #1
 *   @0x10d7c4 mov r4, r0
 *   @0x10d7c8 movne r2, #0
 *   @0x10d7cc cmp r2, #0
 *   @0x10d7d0 ldrne r4, [r6, #0x78]
 *   @0x10d7d4 adds r3, r8, #0
 *   @0x10d7d8 movne r3, #1
 *   @0x10d7dc cmn r4, #2
 *   @0x10d7e0 movne r3, #0
 *   @0x10d7e4 cmp r3, #0
 *   @0x10d7e8 ldrne r4, [r8, #0x78]
 *   @0x10d7ec mov r8, #0
 *   @0x10d7f0 str r8, [r1, #-0x14]!
 *   @0x10d7f4 mov r0, r4
 *   @0x10d7f8 bl 0x1c8df8 <_Z22ShouldUseFastCollisioniPP9CObjectGM>
 *   @0x10d7fc cmp r0, #1
 *   @0x10d800 mov r6, r0
 *   @0x10d804 beq 0x10d864 <_Z17F_PositionMeetingR6RValueP9CInstanceS2_iPS_+0xe8>
 *   @0x10d808 cmp r0, #2
 *   @0x10d80c beq 0x10d818 <_Z17F_PositionMeetingR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x10d810 add sp, sp, #36
 *   @0x10d814 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x10d818 mov r1, r8
 *   @0x10d81c mov r0, r7
 *   @0x10d820 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10d824 mov r1, #1
 *   @0x10d828 mov r6, r0
 *   @0x10d82c mov r0, r7
 *   @0x10d830 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10d834 mov r2, r4
 *   @0x10d838 mov r1, r0
 *   @0x10d83c mov r0, r6
 *   @0x10d840 bl 0x1c9da8 <_Z16Command_ObjectAtffi>
 *   @0x10d844 vmov s15, r0
 *   @0x10d848 vcvt.f64.u32 d7, s15
 *   @0x10d84c vmov r0, r1, d7
 *   @0x10d850 vmov r2, s14
 *   @0x10d854 mov r3, r1
 *   @0x10d858 stm r5, {r2, r3}
 *   @0x10d85c add sp, sp, #36
 *   @0x10d860 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x10d864 bl 0x1cc24c <_Z10UpdateTreev>
 *   @0x10d868 mov r1, r8
 *   @0x10d86c mov r0, r7
 *   @0x10d870 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x10d874 mov r1, r6
 *   @0x10d878 mov r9, r0
 *   @0x10d87c mov r0, r7
 *   @0x10d880 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x10d884 ldr lr, [pc, #0x60]
 *   @0x10d888 ldr r3, [pc, #0x60]
 *   @0x10d88c add r2, sp, #24
 *   @0x10d890 add lr, pc, lr
 *   @0x10d894 add r1, sp, #16
 *   @0x10d898 ldr r3, [pc, r3]
 *   @0x10d89c str r9, [sp, #0x10]
 *   @0x10d8a0 str r9, [sp, #0x18]
 *   @0x10d8a4 mov r12, r0
 *   @0x10d8a8 ldr r0, [pc, #0x44]
 *   @0x10d8ac str r12, [sp, #0x14]
 *   @0x10d8b0 ldr r0, [pc, r0]
 *   @0x10d8b4 str r12, [sp, #0x1c]
 *   @0x10d8b8 ldr r0, [r0]
 *   @0x10d8bc str r4, [sp]
 *   @0x10d8c0 mov r4, lr
 *   @0x10d8c4 str r9, [lr, #0x4]
 *   @0x10d8c8 strb r8, [lr]
 *   @0x10d8cc str r12, [lr, #0x8]
 *   @0x10d8d0 bl 0x10d720 <_ZN5RTreeIP9CInstanceifLi6ELi2EE6SearchEPKiS4_PFbS1_PvES5_>
 *   @0x10d8d4 ldrb r2, [r4]
 *   @0x10d8d8 vmov s15, r2
 *   @0x10d8dc vcvt.f64.u32 d7, s15
 *   @0x10d8e0 vmov r2, r3, d7
 *   @0x10d8e4 stm r5, {r2, r3}
 *   @0x10d8e8 b 0x10d810 <_Z17F_PositionMeetingR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x10d8ec eorseq r5, r7, r8, asr #28
 *   @0x10d8f0 eoreq r0, lr, r8, lsr #19
 *   @0x10d8f4 mlaeq lr, r4, r9, r0
 *
 * ══ §12/81 F_DisplayGetVisibleRects(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a5fc  size 380  95 条（0x11a5fc..0x11a778）
 * @func 0x11a5fc 0x11a778  size 380  95 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×4 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / GR_Display_Get_Visible_Rects(double, double, double, double, double**) / ARRAY_RefAlloc(void*) / F_DisplayGetVisibleRects(RValue&, CInstance*, CInstance*, int, RValue*)+0x15c / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x4×9 / 0x1c×2 / 0x18×2 / 0x-4×2 / 0x10×2 / 0xc×2 / 0x50×1 / 0xc8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a5fc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x11a600 sub sp, sp, #44
 *   @0x11a604 mov r8, r0
 *   @0x11a608 mov r1, #0
 *   @0x11a60c ldr r9, [sp, #0x50]
 *   @0x11a610 mov r11, r1
 *   @0x11a614 mov r10, #1
 *   @0x11a618 mov r0, r9
 *   @0x11a61c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x11a620 mov r4, r0
 *   @0x11a624 mov r5, r1
 *   @0x11a628 mov r0, r9
 *   @0x11a62c mov r1, r10
 *   @0x11a630 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x11a634 mov r2, r0
 *   @0x11a638 mov r3, r1
 *   @0x11a63c mov r0, r9
 *   @0x11a640 mov r1, #2
 *   @0x11a644 str r2, [sp, #0x1c]
 *   @0x11a648 str r3, [sp, #0x18]
 *   @0x11a64c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x11a650 mov r6, r0
 *   @0x11a654 mov r7, r1
 *   @0x11a658 mov r0, r9
 *   @0x11a65c mov r1, #3
 *   @0x11a660 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x11a664 add r12, sp, #40
 *   @0x11a668 ldr r2, [sp, #0x1c]
 *   @0x11a66c strd r6, r7, [sp]
 *   @0x11a670 ldr r3, [sp, #0x18]
 *   @0x11a674 str r11, [r12, #-0x4]!
 *   @0x11a678 str r12, [sp, #0x10]
 *   @0x11a67c strd r0, r1, [sp, #8]
 *   @0x11a680 mov r1, r5
 *   @0x11a684 mov r0, r4
 *   @0x11a688 bl 0x17af78 <_Z28GR_Display_Get_Visible_RectsddddPPd>
 *   @0x11a68c mov r3, #2
 *   @0x11a690 str r3, [r8, #0xc]
 *   @0x11a694 mov r4, r0
 *   @0x11a698 mov r0, r8
 *   @0x11a69c bl 0xced9c <_Z14ARRAY_RefAllocPv>
 *   @0x11a6a0 ldr r1, [pc, #0xc8]
 *   @0x11a6a4 mov r3, r10
 *   @0x11a6a8 mov r2, #70
 *   @0x11a6ac add r1, pc, r1
 *   @0x11a6b0 lsl r6, r4, #3
 *   @0x11a6b4 mov r5, r0
 *   @0x11a6b8 str r0, [r8]
 *   @0x11a6bc str r10, [r5, #0x10]
 *   @0x11a6c0 mov r0, #8
 *   @0x11a6c4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x11a6c8 ldr r1, [pc, #0xa4]
 *   @0x11a6cc mov r3, r10
 *   @0x11a6d0 mov r2, #672
 *   @0x11a6d4 add r1, pc, r1
 *   @0x11a6d8 str r0, [r5, #0x4]
 *   @0x11a6dc lsl r0, r4, #7
 *   @0x11a6e0 ldr r12, [r8]
 *   @0x11a6e4 ldr r5, [r12, #0x4]
 *   @0x11a6e8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x11a6ec cmp r6, r11
 *   @0x11a6f0 str r0, [r5, #0x4]
 *   @0x11a6f4 ldr r3, [r8]
 *   @0x11a6f8 ldr r5, [sp, #0x24]
 *   @0x11a6fc ldr r1, [r3, #0x4]
 *   @0x11a700 str r6, [r1]
 *   @0x11a704 ble 0x11a758 <_Z24F_DisplayGetVisibleRectsR6RValueP9CInstanceS2_iPS_+0x15c>
 *   @0x11a708 ldr r2, [r8]
 *   @0x11a70c mov r0, r11
 *   @0x11a710 add r6, r5, r4, lsl #6
 *   @0x11a714 mov r3, r5
 *   @0x11a718 b 0x11a724 <_Z24F_DisplayGetVisibleRectsR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x11a71c ldr r2, [r8]
 *   @0x11a720 ldr r1, [r2, #0x4]
 *   @0x11a724 ldr r2, [r2, #0x4]
 *   @0x11a728 add r3, r3, #8
 *   @0x11a72c ldr r4, [r1, #0x4]
 *   @0x11a730 ldr r12, [r3, #-0x8]
 *   @0x11a734 ldr r1, [r3, #-0x4]
 *   @0x11a738 add r4, r4, r11
 *   @0x11a73c ldr r2, [r2, #0x4]
 *   @0x11a740 cmp r3, r6
 *   @0x11a744 str r0, [r4, #0xc]
 *   @0x11a748 str r12, [r2, r11]!
 *   @0x11a74c add r11, r11, #16
 *   @0x11a750 str r1, [r2, #0x4]
 *   @0x11a754 bne 0x11a71c <_Z24F_DisplayGetVisibleRectsR6RValueP9CInstanceS2_iPS_+0x120>
 *   @0x11a758 cmp r5, #0
 *   @0x11a75c beq 0x11a768 <_Z24F_DisplayGetVisibleRectsR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x11a760 mov r0, r5
 *   @0x11a764 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x11a768 add sp, sp, #44
 *   @0x11a76c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x11a770 eoreq r6, r1, r4, lsl #19
 *   @0x11a774 eoreq pc, r1, r12, ror r8
 *
 * ══ §13/81 F_SurfaceResize(RValue&, CInstance*, CInstance*, int, RValue*)  0x11e770  size 380  88 条（0x11e770..0x11e8ec）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x11e770 0x11e8ec  size 380  88 条
 * 部分覆盖: 本节 88/95 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x11e7d0→0x3f5110, 0x11e80c→0x5428e8, 0x11e830→0x544c38, 0x11e878→0x5428f0, 0x11e880→0x3f50f8, 0x11e888→0x3f50f4
 * 调用序列: YYGetInt32(RValue const*, int)×3 / GR_Surface_Exists(int) / GR_Surface_Resize(int, int, int)
 * 字段偏移 top8: 0x20×2 / 0x4×2 / 0x13c×1 / 0xf0×1 / 0xb8×1 / 0x98×1 / 0x88×1 / 0x6c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11e770 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x11e774 mov r1, #0
 *   @0x11e778 ldr r4, [sp, #0x20]
 *   @0x11e77c mov r9, r0
 *   @0x11e780 ldr r5, [pc, #0x13c]
 *   @0x11e784 mov r0, r4
 *   @0x11e788 add r5, pc, r5
 *   @0x11e78c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11e790 mov r1, #1
 *   @0x11e794 mov r8, r0
 *   @0x11e798 mov r0, r4
 *   @0x11e79c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11e7a0 mov r1, #2
 *   @0x11e7a4 mov r6, r0
 *   @0x11e7a8 mov r0, r4
 *   @0x11e7ac bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11e7b0 sub r12, r6, #1
 *   @0x11e7b4 sub r4, r0, #1
 *   @0x11e7b8 mov r7, r0
 *   @0x11e7bc cmp r12, #8192
 *   @0x11e7c0 cmplo r4, #8192
 *   @0x11e7c4 movlo r4, #0
 *   @0x11e7c8 movhs r4, #1
 *   @0x11e7cc bhs 0x11e864 <_Z15F_SurfaceResizeR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0x11e7d0 ldr r3, [pc, #0xf0]
 *   @0x11e7d4 ldr r3, [r5, r3]
 *   @0x11e7d8 ldr r3, [r3]
 *   @0x11e7dc cmp r8, r3
 *   @0x11e7e0 beq 0x11e878 <_Z15F_SurfaceResizeR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x11e7e4 mov r0, r8
 *   @0x11e7e8 bl 0x1714c0 <_Z17GR_Surface_Existsi>
 *   @0x11e7ec subs r1, r0, #0
 *   @0x11e7f0 beq 0x11e8b4 <_Z15F_SurfaceResizeR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x11e7f4 mov r0, r8
 *   @0x11e7f8 mov r1, r6
 *   @0x11e7fc mov r2, r7
 *   @0x11e800 bl 0x171b68 <_Z17GR_Surface_Resizeiii>
 *   @0x11e820 ldr r3, [r5, r2]
 *   @0x11e824 ldrb r3, [r3]
 *   @0x11e828 cmp r3, #0
 *   @0x11e82c popeq {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x11e830 ldr r3, [pc, #0x98]
 *   @0x11e834 ldr r3, [r5, r3]
 *   @0x11e838 ldr r3, [r3]
 *   @0x11e83c cmp r3, #0
 *   @0x11e840 popne {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x11e844 ldr r1, [pc, #0x88]
 *   @0x11e848 mov r2, r6
 *   @0x11e84c str r8, [sp, #0x20]
 *   @0x11e850 mov r3, r7
 *   @0x11e854 mov r0, #4
 *   @0x11e858 add r1, pc, r1
 *   @0x11e85c pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x11e860 b 0x29c3ec <_Z12Debug_AddTag12eTagNameTypePKcz>
 *   @0x11e864 ldr r0, [pc, #0x6c]
 *   @0x11e868 mov r1, #0
 *   @0x11e86c pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x11e870 add r0, pc, r0
 *   @0x11e874 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11e878 ldr r0, [pc, #0x5c]
 *   @0x11e87c mov r12, #1
 *   @0x11e880 ldr r1, [pc, #0x58]
 *   @0x11e884 mov r3, #0
 *   @0x11e888 ldr r2, [pc, #0x54]
 *   @0x11e88c movt r3, #0x3ff0
 *   @0x11e890 ldr r0, [r5, r0]
 *   @0x11e894 strb r12, [r0]
 *   @0x11e898 ldr r1, [r5, r1]
 *   @0x11e89c str r6, [r1]
 *   @0x11e8a0 ldr r2, [r5, r2]
 *   @0x11e8a4 str r3, [r9, #0x4]
 *   @0x11e8a8 str r7, [r2]
 *   @0x11e8ac str r4, [r9]
 *   @0x11e8b0 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x11e8b4 ldr r0, [pc, #0x2c]
 *   @0x11e8b8 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x11e8bc add r0, pc, r0
 *   @0x11e8c0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11e8c4 eoreq r3, sp, r8, asr #9
 *   @0x11e8c8 .word 0xffffc988
 *   @0x11e8cc .word 0xffffbcd4
 *   @0x11e8d0 .word 0xffffc7d0
 *   @0x11e8d4 .word 0x0021b9f0
 *   @0x11e8d8 eoreq r11, r1, r4, lsr #19
 *   @0x11e8dc .word 0xffffc98c
 *   @0x11e8e0 .word 0xffffc990
 *   @0x11e8e4 .word 0xffffc994
 *   @0x11e8e8 eoreq r11, r1, r4, ror r9
 *
 * ══ §14/81 F_DrawHighscore(RValue&, CInstance*, CInstance*, int, RValue*)  0x1269fc  size 380  95 条（0x1269fc..0x126b78）
 * @func 0x1269fc 0x126b78  size 380  95 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×4 / GR_Text_Draw(float, float, char const*, int, int)×2 / 0xb65b0 / HighScore_Name(char const*&, int) / HighScore_Value(int) / 0xb65c8 / GR_Text_Width(char const*, int, int) / 0xb65d4
 * 字段偏移 top8: 0x14×2 / 0x11c×2 / 0xc×2 / 0x10×2 / 0x18×2 / 0x16c×1 / 0x150×1 / 0x124×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1269fc ldr r12, [pc, #0x16c]
 *   @0x126a00 mov r2, #256
 *   @0x126a04 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x126a08 vpush {d8}
 *   @0x126a0c ldr r12, [pc, r12]
 *   @0x126a10 sub sp, sp, #292
 *   @0x126a14 mov r1, #0
 *   @0x126a18 ldr r3, [r12]
 *   @0x126a1c add r5, sp, #28
 *   @0x126a20 ldr r8, [sp, #0x150]
 *   @0x126a24 mov r4, #1
 *   @0x126a28 mov r0, r5
 *   @0x126a2c str r12, [sp, #0x14]
 *   @0x126a30 str r3, [sp, #0x11c]
 *   @0x126a34 bl 0xb65b0 <memset@plt>
 *   @0x126a38 mov r0, r8
 *   @0x126a3c mov r1, #0
 *   @0x126a40 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x126a44 mov r1, r4
 *   @0x126a48 ldr r11, [pc, #0x124]
 *   @0x126a4c add r10, sp, #24
 *   @0x126a50 mvn r7, #0
 *   @0x126a54 add r11, pc, r11
 *   @0x126a58 vmov s16, r0
 *   @0x126a5c mov r0, r8
 *   @0x126a60 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x126a64 mov r1, #2
 *   @0x126a68 mov r3, r0
 *   @0x126a6c mov r0, r8
 *   @0x126a70 mov r6, r3
 *   @0x126a74 str r3, [sp, #0xc]
 *   @0x126a78 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x126a7c mov r1, #3
 *   @0x126a80 mov r9, r0
 *   @0x126a84 mov r0, r8
 *   @0x126a88 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x126a8c vcvt.f32.s32 s16, s16
 *   @0x126a90 ldr r3, [sp, #0xc]
 *   @0x126a94 movw r2, #0x6667
 *   @0x126a98 movt r2, #0x6666
 *   @0x126a9c vmov r8, s16
 *   @0x126aa0 rsb r0, r3, r0
 *   @0x126aa4 smull r1, r2, r2, r0
 *   @0x126aa8 asr r3, r0, #31
 *   @0x126aac rsb r3, r3, r2, asr #2
 *   @0x126ab0 str r3, [sp, #0x10]
 *   @0x126ab4 mov r1, r4
 *   @0x126ab8 mov r0, r10
 *   @0x126abc mov r3, #0
 *   @0x126ac0 str r3, [sp, #0x18]
 *   @0x126ac4 bl 0x1dc314 <_Z14HighScore_NameRPKci>
 *   @0x126ac8 vmov s15, r6
 *   @0x126acc ldr r12, [sp, #0x10]
 *   @0x126ad0 mvn r3, #0
 *   @0x126ad4 vcvt.f32.s32 s16, s15
 *   @0x126ad8 ldr r2, [sp, #0x18]
 *   @0x126adc mov r0, r8
 *   @0x126ae0 str r7, [sp]
 *   @0x126ae4 add r6, r6, r12
 *   @0x126ae8 vmov r1, s16
 *   @0x126aec bl 0x172df8 <_Z12GR_Text_DrawffPKcii>
 *   @0x126af0 mov r0, r4
 *   @0x126af4 bl 0x1dc310 <_Z15HighScore_Valuei>
 *   @0x126af8 mov r1, #256
 *   @0x126afc mov r2, r11
 *   @0x126b00 add r4, r4, #1
 *   @0x126b04 mov r3, r0
 *   @0x126b08 mov r0, r5
 *   @0x126b0c bl 0xb65c8 <snprintf@plt>
 *   @0x126b10 mvn r1, #0
 *   @0x126b14 mov r2, r1
 *   @0x126b18 mov r0, r5
 *   @0x126b1c bl 0x172bc8 <_Z13GR_Text_WidthPKcii>
 *   @0x126b20 str r7, [sp]
 *   @0x126b24 vmov r1, s16
 *   @0x126b28 mov r2, r5
 *   @0x126b2c mvn r3, #0
 *   @0x126b30 rsb r0, r0, r9
 *   @0x126b34 vmov s15, r0
 *   @0x126b38 vcvt.f32.s32 s15, s15
 *   @0x126b3c vmov r0, s15
 *   @0x126b40 bl 0x172df8 <_Z12GR_Text_DrawffPKcii>
 *   @0x126b44 cmp r4, #11
 *   @0x126b48 bne 0x126ab4 <_Z15F_DrawHighscoreR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x126b4c ldr r12, [sp, #0x14]
 *   @0x126b50 ldr r2, [sp, #0x11c]
 *   @0x126b54 ldr r3, [r12]
 *   @0x126b58 cmp r2, r3
 *   @0x126b5c bne 0x126b6c <_Z15F_DrawHighscoreR6RValueP9CInstanceS2_iPS_+0x170>
 *   @0x126b60 add sp, sp, #292
 *   @0x126b64 vpop {d8}
 *   @0x126b68 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x126b6c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x126b70 eoreq r6, r12, r4, asr #30
 *   @0x126b74 .word 0x0020bab8
 *
 * ══ §15/81 F_PhysicsDestroyParticleRegionPoly(RValue&, CInstance*, CInstance*, int, RValue*)  0x14d4d8  size 380  95 条（0x14d4d8..0x14d654）
 * @func 0x14d4d8 0x14d654  size 380  95 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CDS_List::GetValue(int)×2 / YYGetInt32(RValue const*, int) / F_PhysicsDestroyParticleRegionPoly(RValue&, CInstance*, CInstance*, int, RValue*)+0x12c / CDS_List::Size() / F_PhysicsDestroyParticleRegionPoly(RValue&, CInstance*, CInstance*, int, RValue*)+0x144 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / CPhysicsWorld::DeleteParticlePolyRegion(float*, int)
 * 字段偏移 top8: 0x4×7 / 0xb4×2 / 0x154×1 / 0x30×1 / 0x124×1 / 0x114×1 / 0x2×1 / 0xf0×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14d4d8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x14d4dc sub sp, sp, #12
 *   @0x14d4e0 ldr r7, [pc, #0x154]
 *   @0x14d4e4 ldr r0, [sp, #0x30]
 *   @0x14d4e8 ldr r7, [pc, r7]
 *   @0x14d4ec ldr r3, [r7]
 *   @0x14d4f0 cmp r3, #0
 *   @0x14d4f4 beq 0x14d624 <_Z34F_PhysicsDestroyParticleRegionPolyR6RValueP9CInstanceS2_iPS_+0x14c>
 *   @0x14d4f8 ldr r3, [r3, #0xb4]
 *   @0x14d4fc cmp r3, #0
 *   @0x14d500 beq 0x14d624 <_Z34F_PhysicsDestroyParticleRegionPolyR6RValueP9CInstanceS2_iPS_+0x14c>
 *   @0x14d504 mov r1, #0
 *   @0x14d508 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14d50c cmp r0, #0
 *   @0x14d510 blt 0x14d604 <_Z34F_PhysicsDestroyParticleRegionPolyR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x14d514 ldr r3, [pc, #0x124]
 *   @0x14d518 ldr r3, [pc, r3]
 *   @0x14d51c ldr r3, [r3]
 *   @0x14d520 cmp r0, r3
 *   @0x14d524 bge 0x14d604 <_Z34F_PhysicsDestroyParticleRegionPolyR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x14d528 ldr r10, [pc, #0x114]
 *   @0x14d52c lsl r8, r0, #2
 *   @0x14d530 ldr r10, [pc, r10]
 *   @0x14d534 ldr r3, [r10, #0x4]
 *   @0x14d538 ldr r0, [r3, r0, lsl #2]
 *   @0x14d53c cmp r0, #0
 *   @0x14d540 beq 0x14d604 <_Z34F_PhysicsDestroyParticleRegionPolyR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x14d544 bl 0x2052b8 <_ZN8CDS_List4SizeEv>
 *   @0x14d548 subs r11, r0, #0
 *   @0x14d54c ble 0x14d61c <_Z34F_PhysicsDestroyParticleRegionPolyR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x14d550 ldr r1, [pc, #0xf0]
 *   @0x14d554 lsl r0, r11, #2
 *   @0x14d558 movw r2, #0x6ad
 *   @0x14d55c mov r3, #1
 *   @0x14d560 add r1, pc, r1
 *   @0x14d564 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x14d568 asrs r11, r11, #1
 *   @0x14d56c str r11, [sp, #0x4]
 *   @0x14d570 str r0, [sp]
 *   @0x14d574 beq 0x14d5e4 <_Z34F_PhysicsDestroyParticleRegionPolyR6RValueP9CInstanceS2_iPS_+0x10c>
 *   @0x14d578 ldr r3, [sp]
 *   @0x14d57c mov r11, #0
 *   @0x14d580 add r6, r3, #4
 *   @0x14d584 ldr r3, [sp, #0x4]
 *   @0x14d588 lsl r9, r3, #1
 *   @0x14d58c ldr r2, [r10, #0x4]
 *   @0x14d590 mov r1, r11
 *   @0x14d594 ldr r0, [r2, r8]
 *   @0x14d598 bl 0x2031f4 <_ZN8CDS_List8GetValueEi>
 *   @0x14d59c ldr r2, [r10, #0x4]
 *   @0x14d5a0 add r1, r11, #1
 *   @0x14d5a4 add r11, r11, #2
 *   @0x14d5a8 ldr r4, [r0]
 *   @0x14d5ac ldr r5, [r0, #0x4]
 *   @0x14d5b0 ldr r0, [r2, r8]
 *   @0x14d5b4 vmov d6, r4, r5
 *   @0x14d5b8 vcvt.f32.f64 s15, d6
 *   @0x14d5bc vstr s15, [r6, #-4]
 *   @0x14d5c0 bl 0x2031f4 <_ZN8CDS_List8GetValueEi>
 *   @0x14d5c4 cmp r11, r9
 *   @0x14d5c8 ldr r4, [r0]
 *   @0x14d5cc ldr r5, [r0, #0x4]
 *   @0x14d5d0 vmov d6, r4, r5
 *   @0x14d5d4 vcvt.f32.f64 s15, d6
 *   @0x14d5d8 vmov r3, s15
 *   @0x14d5dc str r3, [r6], #8
 *   @0x14d5e0 bne 0x14d58c <_Z34F_PhysicsDestroyParticleRegionPolyR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x14d5e4 ldr r3, [r7]
 *   @0x14d5e8 ldm sp, {r1, r2}
 *   @0x14d5ec ldr r0, [r3, #0xb4]
 *   @0x14d5f0 bl 0x23a08c <_ZN13CPhysicsWorld24DeleteParticlePolyRegionEPfi>
 *   @0x14d5f4 ldr r0, [sp]
 *   @0x14d5f8 add sp, sp, #12
 *   @0x14d5fc pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x14d600 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x14d604 ldr r0, [pc, #0x40]
 *   @0x14d608 mov r1, #0
 *   @0x14d60c add r0, pc, r0
 *   @0x14d610 add sp, sp, #12
 *   @0x14d614 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x14d618 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14d61c add sp, sp, #12
 *   @0x14d620 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x14d624 ldr r0, [pc, #0x24]
 *   @0x14d628 mov r1, #0
 *   @0x14d62c add r0, pc, r0
 *   @0x14d630 add sp, sp, #12
 *   @0x14d634 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x14d638 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14d63c eoreq r0, r10, r0, asr #8
 *   @0x14d640 eoreq r0, r10, r4, ror #14
 *   @0x14d644 eoreq r0, r10, r0, asr r7
 *   @0x14d648 ldrheq r6, [pc], -r4
 *   @0x14d64c ldrsheq r10, [lr], -r0
 *   @0x14d650 andseq r6, pc, r8, lsr #22
 *
 * ══ §16/81 GR_3D_Light_Enable(int, bool)  0x17f920  size 380  95 条（0x17f920..0x17fa9c）
 * @func 0x17f920 0x17fa9c  size 380  95 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x17f930→0x3f26dc, 0x17f948→0x3f2770, 0x17f960→0x4a22d0, 0x17f96c→0x479c80, 0x17f994→0x4a22d0, 0x17f9a0→0x4a22c8, 0x17f9b8→0x4a22cc, 0x17f9f0→0x4a22d4
 * 调用序列: 无
 * 字段偏移 top8: 0x2×2 / 0x140×1 / 0x13c×1 / 0x128×1 / 0x114×1 / 0x10c×1 / 0xe0×1 / 0xdc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17f920 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x17f924 mov r5, r0
 *   @0x17f928 ldr r4, [pc, #0x140]
 *   @0x17f92c mov r7, r1
 *   @0x17f930 ldr r3, [pc, #0x13c]
 *   @0x17f934 add r4, pc, r4
 *   @0x17f938 ldr r6, [r4, r3]
 *   @0x17f93c ldr r3, [r6]
 *   @0x17f940 cmp r3, #0
 *   @0x17f944 bne 0x17f98c <_Z18GR_3D_Light_Enableib+0x6c>
 *   @0x17f948 ldr r3, [pc, #0x128]
 *   @0x17f94c and r5, r0, #7
 *   @0x17f950 cmp r1, #0
 *   @0x17f954 mov r12, #1
 *   @0x17f958 ldr r3, [r4, r3]
 *   @0x17f95c ldr r0, [r3, r5, lsl #2]
 *   @0x17f960 ldr r3, [pc, #0x114]
 *   @0x17f964 bne 0x17fa5c <_Z18GR_3D_Light_Enableib+0x13c>
 *   @0x17f968 ldr r3, [r4, r3]
 *   @0x17f96c ldr r2, [pc, #0x10c]
 *   @0x17f970 ldr r1, [r3]
 *   @0x17f974 bic r1, r1, r12, lsl r5
 *   @0x17f978 str r1, [r3]
 *   @0x17f97c ldr r3, [r4, r2]
 *   @0x17f980 ldr r3, [r3]
 *   @0x17f984 blx r3
 *   @0x17f988 ldr r3, [r6]
 *   @0x17f98c cmp r3, #1
 *   @0x17f990 popne {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x17f994 ldr r2, [pc, #0xe0]
 *   @0x17f998 and r5, r5, #7
 *   @0x17f99c cmp r7, #0
 *   @0x17f9a0 ldr r9, [pc, #0xdc]
 *   @0x17f9a4 mov r0, #1
 *   @0x17f9a8 ldr r2, [r4, r2]
 *   @0x17f9ac ldr r1, [r2]
 *   @0x17f9b0 orrne r5, r1, r3, lsl r5
 *   @0x17f9b4 biceq r5, r1, r3, lsl r5
 *   @0x17f9b8 ldr r3, [pc, #0xc8]
 *   @0x17f9bc mov r1, #0
 *   @0x17f9c0 str r5, [r2]
 *   @0x17f9c4 mov r6, r1
 *   @0x17f9c8 mov r2, r1
 *   @0x17f9cc mov r8, r1
 *   @0x17f9d0 ldr r10, [r4, r3]
 *   @0x17f9d4 mov r7, r1
 *   @0x17f9d8 mov r12, r1
 *   @0x17f9dc mov r3, r1
 *   @0x17f9e0 str r1, [r10]
 *   @0x17f9e4 ldr r9, [r4, r9]
 *   @0x17f9e8 str r1, [r9]
 *   @0x17f9ec ands r11, r5, r0, lsl r3
 *   @0x17f9f0 ldr r1, [pc, #0x94]
 *   @0x17f9f4 beq 0x17fa24 <_Z18GR_3D_Light_Enableib+0x104>
 *   @0x17f9f8 ldr r1, [r4, r1]
 *   @0x17f9fc mov r2, r3
 *   @0x17fa00 ldr r1, [r1, r3, lsl #2]
 *   @0x17fa04 cmp r1, #0
 *   @0x17fa08 addeq r6, r12, #1
 *   @0x17fa0c moveq r12, r6
 *   @0x17fa10 beq 0x17fa24 <_Z18GR_3D_Light_Enableib+0x104>
 *   @0x17fa14 cmp r1, #1
 *   @0x17fa18 mov r2, r3
 *   @0x17fa1c addeq r8, r7, #1
 *   @0x17fa20 moveq r7, r8
 *   @0x17fa24 add r3, r3, #1
 *   @0x17fa28 cmp r3, #8
 *   @0x17fa2c bne 0x17f9ec <_Z18GR_3D_Light_Enableib+0xcc>
 *   @0x17fa30 ldr r1, [pc, #0x58]
 *   @0x17fa34 str r2, [r10]
 *   @0x17fa38 str r6, [r9]
 *   @0x17fa3c ldr r3, [pc, #0x50]
 *   @0x17fa40 ldr r2, [r4, r1]
 *   @0x17fa44 str r8, [r2]
 *   @0x17fa48 ldr r3, [r4, r3]
 *   @0x17fa4c cmp r7, r12
 *   @0x17fa50 strhs r7, [r3]
 *   @0x17fa54 strlo r12, [r3]
 *   @0x17fa58 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x17fa5c ldr r3, [r4, r3]
 *   @0x17fa60 ldr r2, [pc, #0x30]
 *   @0x17fa64 ldr r1, [r3]
 *   @0x17fa68 orr r1, r1, r12, lsl r5
 *   @0x17fa6c b 0x17f978 <_Z18GR_3D_Light_Enableib+0x58>
 *   @0x17fa70 eoreq r2, r7, r12, lsl r3
 *   @0x17fa74 .word 0xffffe7b8
 *   @0x17fa78 .word 0xffffe848
 *   @0x17fa7c .word 0xffffe85c
 *   @0x17fa80 .word 0xffffbad0
 *   @0x17fa84 .word 0xffffe860
 *   @0x17fa88 .word 0xffffe864
 *   @0x17fa8c .word 0xffffe858
 *   @0x17fa90 .word 0xffffe868
 *   @0x17fa94 .word 0xffffe86c
 *   @0x17fa98 .word 0xffffbad8
 *
 * ══ §17/81 Run_EndGame()  0x1d1b38  size 380  95 条（0x1d1b38..0x1d1cb4）
 * @func 0x1d1b38 0x1d1cb4  size 380  95 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CRoom::~CRoom()×2 / operator delete(void*)×2 / MemoryManager::Free(void const*)×2 / EndRoom(bool) / Run_EndGame()+0x6c / Run_EndGame()+0x100 / Run_EndGame()+0x94 / Extension_Finalize()
 * 字段偏移 top8: 0x4×7 / 0x2×2 / 0x160×1 / 0x54×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d1b38 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x1d1b3c mov r0, #1
 *   @0x1d1b40 ldr r4, [pc, #0x160]
 *   @0x1d1b44 bl 0x1d1724 <_Z7EndRoomb>
 *   @0x1d1b48 ldr r4, [pc, r4]
 *   @0x1d1b4c ldr r3, [r4]
 *   @0x1d1b50 cmp r3, #0
 *   @0x1d1b54 ble 0x1d1ba4 <_Z11Run_EndGamev+0x6c>
 *   @0x1d1b58 mov r5, #0
 *   @0x1d1b5c mov r8, r5
 *   @0x1d1b60 ldr r2, [r4, #0x4]
 *   @0x1d1b64 lsl r7, r5, #2
 *   @0x1d1b68 add r3, r2, r7
 *   @0x1d1b6c ldr r6, [r2, r5, lsl #2]
 *   @0x1d1b70 add r5, r5, #1
 *   @0x1d1b74 cmp r6, #0
 *   @0x1d1b78 mov r0, r6
 *   @0x1d1b7c beq 0x1d1b94 <_Z11Run_EndGamev+0x5c>
 *   @0x1d1b80 bl 0x1afa00 <_ZN5CRoomD2Ev>
 *   @0x1d1b84 mov r0, r6
 *   @0x1d1b88 bl 0x27d1d0 <_ZdlPv>
 *   @0x1d1b8c ldr r3, [r4, #0x4]
 *   @0x1d1b90 add r3, r3, r7
 *   @0x1d1b94 str r8, [r3]
 *   @0x1d1b98 ldr r3, [r4]
 *   @0x1d1b9c cmp r3, r5
 *   @0x1d1ba0 bgt 0x1d1b60 <_Z11Run_EndGamev+0x28>
 *   @0x1d1ba4 cmp r3, #0
 *   @0x1d1ba8 beq 0x1d1c50 <_Z11Run_EndGamev+0x118>
 *   @0x1d1bac ldr r6, [r4, #0x4]
 *   @0x1d1bb0 cmp r6, #0
 *   @0x1d1bb4 beq 0x1d1c98 <_Z11Run_EndGamev+0x160>
 *   @0x1d1bb8 ldr r3, [r4]
 *   @0x1d1bbc cmp r3, #0
 *   @0x1d1bc0 ble 0x1d1c38 <_Z11Run_EndGamev+0x100>
 *   @0x1d1bc4 mov r5, #0
 *   @0x1d1bc8 mov r9, r5
 *   @0x1d1bcc ldr r1, [r6]
 *   @0x1d1bd0 movw r3, #0xfeee
 *   @0x1d1bd4 movt r3, #0xfeee
 *   @0x1d1bd8 movw r2, #0xfeee
 *   @0x1d1bdc cmp r1, r3
 *   @0x1d1be0 movt r2, #0xfeee
 *   @0x1d1be4 lsl r8, r5, #2
 *   @0x1d1be8 beq 0x1d1c28 <_Z11Run_EndGamev+0xf0>
 *   @0x1d1bec ldr r7, [r6, r5, lsl #2]
 *   @0x1d1bf0 add r3, r6, r8
 *   @0x1d1bf4 cmp r7, #0
 *   @0x1d1bf8 mov r0, r7
 *   @0x1d1bfc beq 0x1d1c28 <_Z11Run_EndGamev+0xf0>
 *   @0x1d1c00 ldr r1, [r7]
 *   @0x1d1c04 cmp r1, r2
 *   @0x1d1c08 beq 0x1d1c20 <_Z11Run_EndGamev+0xe8>
 *   @0x1d1c0c bl 0x1afa00 <_ZN5CRoomD2Ev>
 *   @0x1d1c10 mov r0, r7
 *   @0x1d1c14 bl 0x27d1d0 <_ZdlPv>
 *   @0x1d1c18 ldr r3, [r4, #0x4]
 *   @0x1d1c1c add r3, r3, r8
 *   @0x1d1c20 str r9, [r3]
 *   @0x1d1c24 ldr r6, [r4, #0x4]
 *   @0x1d1c28 ldr r3, [r4]
 *   @0x1d1c2c add r5, r5, #1
 *   @0x1d1c30 cmp r5, r3
 *   @0x1d1c34 blt 0x1d1bcc <_Z11Run_EndGamev+0x94>
 *   @0x1d1c38 mov r0, r6
 *   @0x1d1c3c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1d1c40 mov r3, #0
 *   @0x1d1c44 str r3, [r4, #0x4]
 *   @0x1d1c48 mov r3, #0
 *   @0x1d1c4c str r3, [r4]
 *   @0x1d1c50 ldr r3, [pc, #0x54]
 *   @0x1d1c54 mov r4, #0
 *   @0x1d1c58 ldr r3, [pc, r3]
 *   @0x1d1c5c str r4, [r3]
 *   @0x1d1c60 bl 0xf6610 <_Z18Extension_Finalizev>
 *   @0x1d1c64 cmp r0, r4
 *   @0x1d1c68 popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1d1c6c mov r0, r4
 *   @0x1d1c70 bl 0x17af8c <_Z20GR_Window_Set_Cursori>
 *   @0x1d1c74 mov r0, #1
 *   @0x1d1c78 bl 0x21a3bc <_Z13Audio_StopAllb>
 *   @0x1d1c7c bl 0x173884 <_Z22GR_Text_ResetToDefaultv>
 *   @0x1d1c80 ldr r0, [pc, #0x28]
 *   @0x1d1c84 ldr r0, [pc, r0]
 *   @0x1d1c88 bl 0x167c34 <_ZN18RenderStateManager5ResetEv>
 *   @0x1d1c8c mov r0, r4
 *   @0x1d1c90 pop {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x1d1c94 b 0xd6aac <_Z12MarkAndSweepP12YYObjectBase>
 *   @0x1d1c98 mov r0, r6
 *   @0x1d1c9c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1d1ca0 str r6, [r4, #0x4]
 *   @0x1d1ca4 b 0x1d1c48 <_Z11Run_EndGamev+0x110>
 *   @0x1d1ca8 eoreq lr, r1, r0, ror #31
 *   @0x1d1cac .word 0x0021bcd0
 *   @0x1d1cb0 eoreq r12, r1, r4, ror r0
 *
 * ══ §18/81 CDS_Map::Replace(RValue*, RValue*)  0x20bc44  size 380  95 条（0x20bc44..0x20bdc0）
 * @func 0x20bc44 0x20bdc0  size 380  95 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CDS_Map::Find(RValue*) / FREE_RValue__Pre(RValue*) / CDS_Map::Add(RValue*, RValue*) / GetContextStackTop() / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)
 * 字段偏移 top8: 0x10×6 / 0x1c×3 / 0x8×3 / 0xc×2 / 0x18×2 / 0x4×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20bc44 push {r3, r4, r5, r6, r7, lr}
 *   @0x20bc48 mov r5, r2
 *   @0x20bc4c mov r7, r0
 *   @0x20bc50 mov r6, r1
 *   @0x20bc54 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue>
 *   @0x20bc58 subs r4, r0, #0
 *   @0x20bc5c beq 0x20bd0c <_ZN7CDS_Map7ReplaceEP6RValueS1_+0xc8>
 *   @0x20bc60 ldr r3, [r4, #0x1c]
 *   @0x20bc64 add r6, r4, #16
 *   @0x20bc68 sub r3, r3, #1
 *   @0x20bc6c bic r3, r3, #-16777216
 *   @0x20bc70 bic r3, r3, #3
 *   @0x20bc74 cmp r3, #0
 *   @0x20bc78 beq 0x20bd00 <_ZN7CDS_Map7ReplaceEP6RValueS1_+0xbc>
 *   @0x20bc7c mov r3, #5
 *   @0x20bc80 str r3, [r4, #0x1c]
 *   @0x20bc84 ldr r3, [r5, #0xc]
 *   @0x20bc88 mov r2, #0
 *   @0x20bc8c str r2, [r4, #0x18]
 *   @0x20bc90 ldr r1, [r5, #0x8]
 *   @0x20bc94 str r3, [r4, #0x1c]
 *   @0x20bc98 ldr r3, [r5, #0xc]
 *   @0x20bc9c str r2, [r4, #0x10]
 *   @0x20bca0 bic r3, r3, #-16777216
 *   @0x20bca4 str r1, [r4, #0x18]
 *   @0x20bca8 cmp r3, #14
 *   @0x20bcac addls pc, pc, r3, lsl #2
 *   @0x20bcb0 b 0x20bd84 <_ZN7CDS_Map7ReplaceEP6RValueS1_+0x140>
 *   @0x20bcb4 b 0x20bd24 <_ZN7CDS_Map7ReplaceEP6RValueS1_+0xe0>
 *   @0x20bcb8 b 0x20bd3c <_ZN7CDS_Map7ReplaceEP6RValueS1_+0xf8>
 *   @0x20bcbc b 0x20bd5c <_ZN7CDS_Map7ReplaceEP6RValueS1_+0x118>
 *   @0x20bcc0 b 0x20bcf0 <_ZN7CDS_Map7ReplaceEP6RValueS1_+0xac>
 *   @0x20bcc4 b 0x20bd84 <_ZN7CDS_Map7ReplaceEP6RValueS1_+0x140>
 *   @0x20bcc8 b 0x20bd84 <_ZN7CDS_Map7ReplaceEP6RValueS1_+0x140>
 *   @0x20bccc b 0x20bd8c <_ZN7CDS_Map7ReplaceEP6RValueS1_+0x148>
 *   @0x20bcd0 b 0x20bcf0 <_ZN7CDS_Map7ReplaceEP6RValueS1_+0xac>
 *   @0x20bcd4 b 0x20bd84 <_ZN7CDS_Map7ReplaceEP6RValueS1_+0x140>
 *   @0x20bcd8 b 0x20bd84 <_ZN7CDS_Map7ReplaceEP6RValueS1_+0x140>
 *   @0x20bcdc b 0x20bd24 <_ZN7CDS_Map7ReplaceEP6RValueS1_+0xe0>
 *   @0x20bce0 b 0x20bd84 <_ZN7CDS_Map7ReplaceEP6RValueS1_+0x140>
 *   @0x20bce4 b 0x20bd84 <_ZN7CDS_Map7ReplaceEP6RValueS1_+0x140>
 *   @0x20bce8 b 0x20bd24 <_ZN7CDS_Map7ReplaceEP6RValueS1_+0xe0>
 *   @0x20bcec b 0x20bcf0 <_ZN7CDS_Map7ReplaceEP6RValueS1_+0xac>
 *   @0x20bcf0 ldr r3, [r5]
 *   @0x20bcf4 mov r0, #1
 *   @0x20bcf8 str r3, [r4, #0x10]
 *   @0x20bcfc pop {r3, r4, r5, r6, r7, pc}
 *   @0x20bd00 mov r0, r6
 *   @0x20bd04 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20bd08 b 0x20bc7c <_ZN7CDS_Map7ReplaceEP6RValueS1_+0x38>
 *   @0x20bd0c mov r0, r7
 *   @0x20bd10 mov r1, r6
 *   @0x20bd14 mov r2, r5
 *   @0x20bd18 bl 0x20b884 <_ZN7CDS_Map3AddEP6RValueS1_>
 *   @0x20bd1c mov r0, r4
 *   @0x20bd20 pop {r3, r4, r5, r6, r7, pc}
 *   @0x20bd24 ldr r2, [r5]
 *   @0x20bd28 mov r0, #1
 *   @0x20bd2c ldr r3, [r5, #0x4]
 *   @0x20bd30 str r2, [r4, #0x10]
 *   @0x20bd34 str r3, [r4, #0x14]
 *   @0x20bd38 pop {r3, r4, r5, r6, r7, pc}
 *   @0x20bd3c ldr r3, [r5]
 *   @0x20bd40 mov r0, #1
 *   @0x20bd44 cmp r3, #0
 *   @0x20bd48 ldrne r2, [r3, #0x4]
 *   @0x20bd4c addne r2, r2, #1
 *   @0x20bd50 strne r2, [r3, #0x4]
 *   @0x20bd54 str r3, [r4, #0x10]
 *   @0x20bd58 pop {r3, r4, r5, r6, r7, pc}
 *   @0x20bd5c ldr r3, [r5]
 *   @0x20bd60 cmp r3, #0
 *   @0x20bd64 str r3, [r4, #0x10]
 *   @0x20bd68 beq 0x20bd84 <_ZN7CDS_Map7ReplaceEP6RValueS1_+0x140>
 *   @0x20bd6c ldr r1, [r3, #0x8]
 *   @0x20bd70 ldr r2, [r3]
 *   @0x20bd74 cmp r1, #0
 *   @0x20bd78 add r2, r2, #1
 *   @0x20bd7c str r2, [r3]
 *   @0x20bd80 beq 0x20bdb4 <_ZN7CDS_Map7ReplaceEP6RValueS1_+0x170>
 *   @0x20bd84 mov r0, #1
 *   @0x20bd88 pop {r3, r4, r5, r6, r7, pc}
 *   @0x20bd8c ldr r3, [r5]
 *   @0x20bd90 str r3, [r4, #0x10]
 *   @0x20bd94 ldr r3, [r5]
 *   @0x20bd98 cmp r3, #0
 *   @0x20bd9c beq 0x20bd84 <_ZN7CDS_Map7ReplaceEP6RValueS1_+0x140>
 *   @0x20bda0 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x20bda4 ldr r1, [r5]
 *   @0x20bda8 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x20bdac mov r0, #1
 *   @0x20bdb0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x20bdb4 str r6, [r3, #0x8]
 *   @0x20bdb8 mov r0, #1
 *   @0x20bdbc pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §19/81 CPhysicsObject::DebugRenderShapes(float)  0x2372ec  size 380  95 条（0x2372ec..0x237468）
 * @func 0x2372ec 0x237468  size 380  95 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6580 / 0xb658c / CPhysicsObject::DebugRenderShapes(float)+0x10c / __aeabi_idivmod / GR_Draw_Line(float, float, float, float) / GR_Draw_Ellipse(float, float, float, float, bool)
 * 字段偏移 top8: 0x4×3 / 0x94×2 / 0x74×1 / 0xc×1 / 0x48×1
 * VFP 指令 46 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2372ec ldr r3, [r0]
 *   @0x2372f0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2372f4 vpush {d8, d9}
 *   @0x2372f8 mov r9, r0
 *   @0x2372fc ldr r7, [r3, #0x74]
 *   @0x237300 sub sp, sp, #12
 *   @0x237304 vmov s16, r1
 *   @0x237308 cmp r7, #0
 *   @0x23730c beq 0x237404 <_ZN14CPhysicsObject17DebugRenderShapesEf+0x118>
 *   @0x237310 mov r10, #1
 *   @0x237314 ldr r6, [r7, #0xc]
 *   @0x237318 ldr r3, [r6, #0x4]
 *   @0x23731c cmp r3, #0
 *   @0x237320 beq 0x237410 <_ZN14CPhysicsObject17DebugRenderShapesEf+0x124>
 *   @0x237324 cmp r3, #2
 *   @0x237328 bne 0x2373f8 <_ZN14CPhysicsObject17DebugRenderShapesEf+0x10c>
 *   @0x23732c ldr r11, [r9]
 *   @0x237330 add r8, r6, #20
 *   @0x237334 ldr r4, [r11, #0x48]
 *   @0x237338 mov r0, r4
 *   @0x23733c bl 0xb6580 <sinf@plt>
 *   @0x237340 vmov s17, r0
 *   @0x237344 mov r0, r4
 *   @0x237348 bl 0xb658c <cosf@plt>
 *   @0x23734c ldr r1, [r6, #0x94]
 *   @0x237350 cmp r1, #0
 *   @0x237354 vmov s18, r0
 *   @0x237358 ble 0x2373f8 <_ZN14CPhysicsObject17DebugRenderShapesEf+0x10c>
 *   @0x23735c mov r5, r8
 *   @0x237360 mov r4, #0
 *   @0x237364 b 0x23736c <_ZN14CPhysicsObject17DebugRenderShapesEf+0x80>
 *   @0x237368 ldr r11, [r9]
 *   @0x23736c add r4, r4, #1
 *   @0x237370 add r5, r5, #8
 *   @0x237374 mov r0, r4
 *   @0x237378 bl 0x318dec <__aeabi_idivmod>
 *   @0x23737c vldr s15, [r5, #-4]
 *   @0x237380 vmul.f32 s13, s15, s17
 *   @0x237384 vldr s9, [r5, #-8]
 *   @0x237388 vldr s10, [r11, #12]
 *   @0x23738c vldr s11, [r11, #16]
 *   @0x237390 vmul.f32 s15, s18, s15
 *   @0x237394 vnmls.f32 s13, s9, s18
 *   @0x237398 add r1, r8, r1, lsl #3
 *   @0x23739c vldr s14, [r1, #4]
 *   @0x2373a0 vldr s8, [r1]
 *   @0x2373a4 vmul.f32 s12, s14, s17
 *   @0x2373a8 vmul.f32 s14, s18, s14
 *   @0x2373ac vnmls.f32 s12, s8, s18
 *   @0x2373b0 vmla.f32 s14, s17, s8
 *   @0x2373b4 vmla.f32 s15, s17, s9
 *   @0x2373b8 vadd.f32 s12, s10, s12
 *   @0x2373bc vadd.f32 s13, s10, s13
 *   @0x2373c0 vadd.f32 s14, s11, s14
 *   @0x2373c4 vadd.f32 s15, s11, s15
 *   @0x2373c8 vmul.f32 s12, s12, s16
 *   @0x2373cc vmul.f32 s14, s14, s16
 *   @0x2373d0 vmov r2, s12
 *   @0x2373d4 vmul.f32 s13, s13, s16
 *   @0x2373d8 vmov r3, s14
 *   @0x2373dc vmul.f32 s15, s15, s16
 *   @0x2373e0 vmov r0, s13
 *   @0x2373e4 vmov r1, s15
 *   @0x2373e8 bl 0x16a21c <_Z12GR_Draw_Lineffff>
 *   @0x2373ec ldr r1, [r6, #0x94]
 *   @0x2373f0 cmp r1, r4
 *   @0x2373f4 bgt 0x237368 <_ZN14CPhysicsObject17DebugRenderShapesEf+0x7c>
 *   @0x2373f8 ldr r7, [r7, #0x4]
 *   @0x2373fc cmp r7, #0
 *   @0x237400 bne 0x237314 <_ZN14CPhysicsObject17DebugRenderShapesEf+0x28>
 *   @0x237404 add sp, sp, #12
 *   @0x237408 vpop {d8, d9}
 *   @0x23740c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x237410 vldr s15, [r6, #8]
 *   @0x237414 ldr r3, [r9]
 *   @0x237418 vldr s13, [r3, #12]
 *   @0x23741c vldr s14, [r3, #16]
 *   @0x237420 vsub.f32 s11, s13, s15
 *   @0x237424 str r10, [sp]
 *   @0x237428 vsub.f32 s12, s14, s15
 *   @0x23742c vadd.f32 s13, s13, s15
 *   @0x237430 vadd.f32 s15, s15, s14
 *   @0x237434 vmul.f32 s11, s11, s16
 *   @0x237438 vmul.f32 s13, s13, s16
 *   @0x23743c vmov r0, s11
 *   @0x237440 vmul.f32 s12, s12, s16
 *   @0x237444 vmov r2, s13
 *   @0x237448 vmul.f32 s15, s15, s16
 *   @0x23744c vmov r1, s12
 *   @0x237450 vmov r3, s15
 *   @0x237454 bl 0x16b278 <_Z15GR_Draw_Ellipseffffb>
 *   @0x237458 ldr r7, [r7, #0x4]
 *   @0x23745c cmp r7, #0
 *   @0x237460 bne 0x237314 <_ZN14CPhysicsObject17DebugRenderShapesEf+0x28>
 *   @0x237464 b 0x237404 <_ZN14CPhysicsObject17DebugRenderShapesEf+0x118>
 *
 * ══ §20/81 JS_String_prototype_concat(RValue&, CInstance*, CInstance*, int, RValue*)  0x257968  size 380  95 条（0x257968..0x257ae4）
 * @func 0x257968 0x257ae4  size 380  95 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538×2 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / 0xb65a4×2 / JS_CheckObjectCoercible(RValue&) / F_JS_ToString(RValue&, RValue*) / JS_String_prototype_concat(RValue&, CInstance*, CInstance*, int, RValue*)+0x144 / 0xb6628 / YYCreateString(RValue*, char const*)
 * 字段偏移 top8: 0x10×4 / 0x1c×3 / 0x18×2 / 0x-20×1 / 0x40×1 / 0xc×1 / 0xd0×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x257968 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x25796c sub sp, sp, #32
 *   @0x257970 add r4, sp, #32
 *   @0x257974 mov r8, r0
 *   @0x257978 mov r0, sp
 *   @0x25797c mov r6, r3
 *   @0x257980 str r1, [r4, #-0x20]!
 *   @0x257984 mov r3, #6
 *   @0x257988 ldr r5, [sp, #0x40]
 *   @0x25798c str r3, [sp, #0xc]
 *   @0x257990 bl 0x2423a4 <_Z23JS_CheckObjectCoercibleR6RValue>
 *   @0x257994 cmp r0, #1
 *   @0x257998 beq 0x257a98 <_Z26JS_String_prototype_concatR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x25799c add r7, sp, #16
 *   @0x2579a0 mov r1, sp
 *   @0x2579a4 mov r2, #0
 *   @0x2579a8 mov r3, #0
 *   @0x2579ac mov r0, r7
 *   @0x2579b0 strd r2, r3, [sp, #16]
 *   @0x2579b4 mov r4, #0
 *   @0x2579b8 mvn r3, #-16777216
 *   @0x2579bc str r4, [sp, #0x18]
 *   @0x2579c0 str r3, [sp, #0x1c]
 *   @0x2579c4 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x2579c8 ldr r3, [sp, #0x10]
 *   @0x2579cc ldr r0, [r3]
 *   @0x2579d0 bl 0xb6538 <strlen@plt>
 *   @0x2579d4 cmp r6, r4
 *   @0x2579d8 mov r9, r0
 *   @0x2579dc ble 0x257aac <_Z26JS_String_prototype_concatR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x2579e0 lsl r10, r6, #4
 *   @0x2579e4 ldr r3, [r5, r4]
 *   @0x2579e8 add r4, r4, #16
 *   @0x2579ec ldr r0, [r3]
 *   @0x2579f0 bl 0xb6538 <strlen@plt>
 *   @0x2579f4 cmp r4, r10
 *   @0x2579f8 add r9, r9, r0
 *   @0x2579fc bne 0x2579e4 <_Z26JS_String_prototype_concatR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x257a00 ldr r1, [pc, #0xd0]
 *   @0x257a04 mov r0, r9
 *   @0x257a08 mov r3, #1
 *   @0x257a0c mov r2, #70
 *   @0x257a10 add r1, pc, r1
 *   @0x257a14 mov r4, #0
 *   @0x257a18 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x257a1c strb r4, [r0]
 *   @0x257a20 mov r9, r0
 *   @0x257a24 ldr r3, [sp, #0x10]
 *   @0x257a28 ldr r1, [r3]
 *   @0x257a2c bl 0xb65a4 <strcpy@plt>
 *   @0x257a30 ldr r3, [r5, r4, lsl #4]
 *   @0x257a34 mov r0, r9
 *   @0x257a38 add r4, r4, #1
 *   @0x257a3c ldr r1, [r3]
 *   @0x257a40 bl 0xb6628 <strcat@plt>
 *   @0x257a44 cmp r4, r6
 *   @0x257a48 bne 0x257a30 <_Z26JS_String_prototype_concatR6RValueP9CInstanceS2_iPS_+0xc8>
 *   @0x257a4c ldr r3, [sp, #0x1c]
 *   @0x257a50 sub r3, r3, #1
 *   @0x257a54 bic r3, r3, #-16777216
 *   @0x257a58 bic r3, r3, #3
 *   @0x257a5c cmp r3, #0
 *   @0x257a60 beq 0x257a8c <_Z26JS_String_prototype_concatR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x257a64 mov r0, r8
 *   @0x257a68 mov r1, r9
 *   @0x257a6c mov r3, #0
 *   @0x257a70 mov r2, #5
 *   @0x257a74 str r3, [sp, #0x18]
 *   @0x257a78 str r3, [sp, #0x10]
 *   @0x257a7c str r2, [sp, #0x1c]
 *   @0x257a80 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x257a84 add sp, sp, #32
 *   @0x257a88 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x257a8c mov r0, r7
 *   @0x257a90 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x257a94 b 0x257a64 <_Z26JS_String_prototype_concatR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x257a98 ldr r0, [pc, #0x3c]
 *   @0x257a9c add r0, pc, r0
 *   @0x257aa0 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x257aa4 add sp, sp, #32
 *   @0x257aa8 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x257aac ldr r1, [pc, #0x2c]
 *   @0x257ab0 mov r2, #70
 *   @0x257ab4 mov r3, #1
 *   @0x257ab8 add r1, pc, r1
 *   @0x257abc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x257ac0 strb r4, [r0]
 *   @0x257ac4 mov r9, r0
 *   @0x257ac8 ldr r3, [sp, #0x10]
 *   @0x257acc ldr r1, [r3]
 *   @0x257ad0 bl 0xb65a4 <strcpy@plt>
 *   @0x257ad4 b 0x257a4c <_Z26JS_String_prototype_concatR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x257ad8 andeq r9, sp, r0, lsr #12
 *   @0x257adc andeq lr, pc, r12, lsr #9
 *   @0x257ae0 andeq r9, sp, r8, ror r5
 *
 * ══ §21/81 b2PulleyJointDef::Initialize(b2Body*, b2Body*, b2Vec2 const&, b2Vec2 const&, b2Vec2 const&, b2Vec2 const&, float)  0x2d0f08  size 380  95 条（0x2d0f08..0x2d1084）
 * @func 0x2d0f08 0x2d1084  size 380  95 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6700×2
 * 字段偏移 top8: 0x20×1 / 0x8×1 / 0xc×1 / 0x24×1 / 0x28×1 / 0x54×1 / 0x50×1
 * VFP 指令 63 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d0f08 push {r3, r4, r5, r6, r7, lr}
 *   @0x2d0f0c vpush {d8}
 *   @0x2d0f10 mov r4, r0
 *   @0x2d0f14 vldr s12, [r2, #20]
 *   @0x2d0f18 mov r12, r1
 *   @0x2d0f1c ldr r5, [sp, #0x20]
 *   @0x2d0f20 ldm r3, {r0, r1}
 *   @0x2d0f24 add lr, r4, #20
 *   @0x2d0f28 str r12, [r4, #0x8]
 *   @0x2d0f2c add r7, r4, #28
 *   @0x2d0f30 str r2, [r4, #0xc]
 *   @0x2d0f34 vldr s15, [r12, #16]
 *   @0x2d0f38 stm lr, {r0, r1}
 *   @0x2d0f3c vldr s9, [r12, #20]
 *   @0x2d0f40 ldm r5, {r0, r1}
 *   @0x2d0f44 vldr s8, [r12, #24]
 *   @0x2d0f48 vldr s10, [r12, #12]
 *   @0x2d0f4c ldr lr, [sp, #0x24]
 *   @0x2d0f50 vldr s11, [r2, #24]
 *   @0x2d0f54 vldr s7, [r2, #12]
 *   @0x2d0f58 stm r7, {r0, r1}
 *   @0x2d0f5c vldr s14, [lr, #4]
 *   @0x2d0f60 vsub.f32 s14, s14, s15
 *   @0x2d0f64 vldr s6, [lr]
 *   @0x2d0f68 vldr s15, [r2, #16]
 *   @0x2d0f6c ldr r6, [sp, #0x28]
 *   @0x2d0f70 vldr s16, [sp, #44]
 *   @0x2d0f74 vmul.f32 s13, s14, s9
 *   @0x2d0f78 vmul.f32 s14, s14, s8
 *   @0x2d0f7c vsub.f32 s10, s6, s10
 *   @0x2d0f80 vmla.f32 s13, s10, s8
 *   @0x2d0f84 vmls.f32 s14, s9, s10
 *   @0x2d0f88 vstr s13, [r4, #36]
 *   @0x2d0f8c vstr s14, [r4, #40]
 *   @0x2d0f90 vldr s14, [r6, #4]
 *   @0x2d0f94 vsub.f32 s15, s14, s15
 *   @0x2d0f98 vldr s13, [r6]
 *   @0x2d0f9c vmul.f32 s14, s15, s12
 *   @0x2d0fa0 vmul.f32 s15, s15, s11
 *   @0x2d0fa4 vsub.f32 s13, s13, s7
 *   @0x2d0fa8 vmla.f32 s14, s13, s11
 *   @0x2d0fac vmls.f32 s15, s12, s13
 *   @0x2d0fb0 vstr s14, [r4, #44]
 *   @0x2d0fb4 vstr s15, [r4, #48]
 *   @0x2d0fb8 vldr s15, [r3, #4]
 *   @0x2d0fbc vldr s14, [lr, #4]
 *   @0x2d0fc0 vsub.f32 s14, s14, s15
 *   @0x2d0fc4 vldr s13, [lr]
 *   @0x2d0fc8 vldr s15, [r3]
 *   @0x2d0fcc vmul.f32 s14, s14, s14
 *   @0x2d0fd0 vsub.f32 s15, s13, s15
 *   @0x2d0fd4 vmla.f32 s14, s15, s15
 *   @0x2d0fd8 vsqrt.f32 s15, s14
 *   @0x2d0fdc vcmp.f32 s15, s15
 *   @0x2d0fe0 vmrs APSR_nzcv, fpscr
 *   @0x2d0fe4 bne 0x2d1058 <_ZN16b2PulleyJointDef10InitializeEP6b2BodyS1_RK6b2Vec2S4_S4_S4_f+0x150>
 *   @0x2d0fe8 vldr s13, [r6, #4]
 *   @0x2d0fec vldr s14, [r5, #4]
 *   @0x2d0ff0 vsub.f32 s14, s13, s14
 *   @0x2d0ff4 vldr s12, [r6]
 *   @0x2d0ff8 vldr s13, [r5]
 *   @0x2d0ffc vstr s15, [r4, #52]
 *   @0x2d1000 vmul.f32 s14, s14, s14
 *   @0x2d1004 vsub.f32 s15, s12, s13
 *   @0x2d1008 vmla.f32 s14, s15, s15
 *   @0x2d100c vsqrt.f32 s15, s14
 *   @0x2d1010 vcmp.f32 s15, s15
 *   @0x2d1014 vmrs APSR_nzcv, fpscr
 *   @0x2d1018 bne 0x2d1068 <_ZN16b2PulleyJointDef10InitializeEP6b2BodyS1_RK6b2Vec2S4_S4_S4_f+0x160>
 *   @0x2d101c vldr s14, [pc, #84]
 *   @0x2d1020 ldr r3, [pc, #0x54]
 *   @0x2d1024 vcmpe.f32 s16, s14
 *   @0x2d1028 ldr r1, [pc, #0x50]
 *   @0x2d102c ldr r3, [pc, r3]
 *   @0x2d1030 vstr s16, [r4, #60]
 *   @0x2d1034 vstr s15, [r4, #56]
 *   @0x2d1038 add r1, pc, r1
 *   @0x2d103c ldr r3, [r3]
 *   @0x2d1040 vmrs APSR_nzcv, fpscr
 *   @0x2d1044 movle r0, #0
 *   @0x2d1048 movgt r0, #1
 *   @0x2d104c blx r3
 *   @0x2d1050 vpop {d8}
 *   @0x2d1054 pop {r3, r4, r5, r6, r7, pc}
 *   @0x2d1058 vmov r0, s14
 *   @0x2d105c bl 0xb6700 <sqrtf@plt>
 *   @0x2d1060 vmov s15, r0
 *   @0x2d1064 b 0x2d0fe8 <_ZN16b2PulleyJointDef10InitializeEP6b2BodyS1_RK6b2Vec2S4_S4_S4_f+0xe0>
 *   @0x2d1068 vmov r0, s14
 *   @0x2d106c bl 0xb6700 <sqrtf@plt>
 *   @0x2d1070 vmov s15, r0
 *   @0x2d1074 b 0x2d101c <_ZN16b2PulleyJointDef10InitializeEP6b2BodyS1_RK6b2Vec2S4_S4_S4_f+0x114>
 *   @0x2d1078 strlo r0, [r0], #-0
 *   @0x2d107c mulseq r2, r12, r4
 *   @0x2d1080 andeq r12, r8, r8, lsr #16
 *
 * ══ §22/81 FT_Add_Module  0x2e9810  size 380  95 条（0x2e9810..0x2e998c）
 * @func 0x2e9810 0x2e998c  size 380  95 条
 * 部分覆盖: 本节 95/176 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6574 / 0xac9878 / FT_Add_Module+0x6c / 0x3289cc / ft_mem_alloc / FT_List_Add / 0x329b7c / 0x368d60
 * 字段偏移 top8: 0x10×4 / 0x4×3 / 0x38×3 / 0x24×2 / 0x8×1 / 0xc4×1 / 0x3c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e9810 push.w {r0, r1, r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2e9814 mov r6, r1
 *   @0x2e9818 cmp r0, #0x0
 *   @0x2e981c stmdbhs r0, {r0, r3, r5, r7, pc}
 *   @0x2e9820 beq.w 0x2e9974 <FT_Add_Module+0x164>
 *   @0x2e9824 ldr r3, [r1, #0x10]
 *   @0x2e9828 cmp r3, r2
 *   @0x2e982c .word 0xf8d080a5
 *   @0x2e9830 strhs r9, [r0], #-16
 *   @0x2e9834 cmp r4, r9
 *   @0x2e9838 add.w r3, r5, r4, lsl #2
 *   @0x2e983c ldr r1, [r6, #0x8]
 *   @0x2e9840 ldr.w r8, [r7]
 *   @0x2e9844 ldr.w r0, [r8, #0x8]
 *   @0x2e9848 blx 0xb6574 <strcmp@plt>
 *   @0x2e984c cbnz r0, 0x2e9864 <FT_Add_Module+0x54>
 *   @0x2e9850 ldr.w r2, [r8, #0xc]
 *   @0x2e9854 cmp r3, r2
 *   @0x2e9858 qadd8mi r8, r8, r1
 *   @0x2e985c mov r1, r7
 *   @0x2e9860 and pc, r1, r1, ror #30
 *   @0x2e9864 adds r4, #0x1
 *   @0x2e9868 movs r3, #0x0
 *   @0x2e986c ldr r3, [r5, #0x10]
 *   @0x2e9870 blhs 0xac9878 <b2_toiTime+0x3703d4>
 *   @0x2e9874 bls 0x2e987c <FT_Add_Module+0x6c>
 *   @0x2e9878 str r3, [sp]
 *   @0x2e987c mov r0, r8
 *   @0x2e9880 mov r2, sp
 *   @0x2e9884 blls 0x3289cc
 *   @0x2e9888 mov r4, r0
 *   @0x2e988c bne 0x2e9950 <FT_Add_Module+0x140>
 *   @0x2e9890 str.w r8, [r0, #0x8]
 *   @0x2e9894 str r6, [r0]
 *   @0x2e9898 lsls r0, r3, #0x1e
 *   @0x2e989c ldr r3, [r4]
 *   @0x2e98a0 lsls r1, r3, #0x1d
 *   @0x2e98a4 str.w r4, [r5, #0xa0]
 *   @0x2e98a8 b 0x2e991a <FT_Add_Module+0x10a>
 *   @0x2e98ac .word 0x210c9000
 *   @0x2e98b0 add r2, sp, #0x4
 *   @0x2e98b4 bl 0x2e7126 <ft_mem_alloc>
 *   @0x2e98b8 ldr r3, [sp, #0x4]
 *   @0x2e98bc cbnz r3, 0x2e9912 <FT_Add_Module+0x102>
 *   @0x2e98c0 ldr r2, [pc, #0xc4]
 *   @0x2e98c4 ldr r3, [r7, #0x24]
 *   @0x2e98c8 ldr r3, [r7, #0x24]
 *   @0x2e98cc bne 0x2e98ea <FT_Add_Module+0xda>
 *   @0x2e98d0 ldr r3, [r3, #0x4]
 *   @0x2e98d4 mov r0, r9
 *   @0x2e98d8 .word 0x47980134
 *   @0x2e98dc str r0, [sp, #0x4]
 *   @0x2e98e0 ldr r3, [r7, #0x38]
 *   @0x2e98e4 str r3, [r4, #0x38]
 *   @0x2e98e8 str r3, [r4, #0x3c]
 *   @0x2e98ec uadd8mi r0, r1, r4
 *   @0x2e98f0 str.w r4, [r10, #0x8]
 *   @0x2e98f4 bl 0x2e8920 <FT_List_Add>
 *   @0x2e98f8 mov r0, r5
 *   @0x2e98fc movs r2, #0x0
 *   @0x2e9900 .word 0xf8c5fa9a
 *   @0x2e9904 blls 0x329b7c
 *   @0x2e9908 cbz r3, 0x2e9912 <FT_Add_Module+0x102>
 *   @0x2e990c mov r1, r10
 *   @0x2e9910 blls 0x368d60 <_ZTS12CDS_Priority+0xadb8>
 *   @0x2e9914 str r3, [sp]
 *   @0x2e9918 b 0x2e989c <FT_Add_Module+0x8c>
 *   @0x2e991c ldr r2, [r3]
 *   @0x2e9920 it mi
 *   @0x2e9924 ldr r3, [r6, #0x18]
 *   @0x2e9928 ldr r3, [r5, #0x10]
 *   @0x2e992c str r2, [r5, #0x10]
 *   @0x2e9930 smulbbvs r12, r3, r5
 *   @0x2e9934 b 0x2e9950 <FT_Add_Module+0x140>
 *   @0x2e9938 blx r3
 *   @0x2e993c cmp r0, #0x0
 *   @0x2e9940 ldr r3, [r4]
 *   @0x2e9944 lsls r3, r3, #0x1e
 *   @0x2e9948 mov r0, r8
 *   @0x2e994c bl 0x2e7336 <ft_mem_free>
 *   @0x2e9950 ldr r0, [sp]
 *   @0x2e9954 ldr r3, [r4, #0xc]
 *   @0x2e9958 beq 0x2e9948 <FT_Add_Module+0x138>
 *   @0x2e995c ldr r1, [pc, #0x28]
 *   @0x2e9960 bne 0x2e9948 <FT_Add_Module+0x138>
 *   @0x2e9964 cmp r0, #0x0
 *   @0x2e9968 ldr r3, [r3, #0x38]
 *   @0x2e996c blx r3
 *   @0x2e9970 movs r0, #0x21
 *   @0x2e9974 movs r0, #0x6
 *   @0x2e9978 movs r0, #0x4
 *   @0x2e997c movs r0, #0x5
 *   @0x2e9980 pop.w {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2e9984 movs r0, r1
 *   @0x2e9988 strb r4, [r5, #0x11]
 *
 * ══ §23/81 F_Vertex_Create_Buffer_From_Buffer(RValue&, CInstance*, CInstance*, int, RValue*)  0xc8bc4  size 376  94 条（0xc8bc4..0xc8d3c）
 * @func 0xc8bc4 0xc8d3c  size 376  94 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / GetIBuffer(int) / GetVertexFormat(int) / AllocBufferVertex(int) / GetBufferVertex(int) / 0xb65bc / __udivsi3 / IsBigEndian()
 * 字段偏移 top8: 0x20×4 / 0xc×3 / 0x14×2 / 0x4×2 / 0x18×2 / 0x10×2 / 0x30×1 / 0x134×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc8bc4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xc8bc8 cmp r3, #2
 *   @0xc8bcc sub sp, sp, #12
 *   @0xc8bd0 mov r3, #0
 *   @0xc8bd4 mov r1, r3
 *   @0xc8bd8 mov r6, r0
 *   @0xc8bdc movt r3, #0xbff0
 *   @0xc8be0 str r1, [r0, #0xc]
 *   @0xc8be4 stm r0, {r1, r3}
 *   @0xc8be8 ldr r4, [sp, #0x30]
 *   @0xc8bec beq 0xc8c08 <_Z34F_Vertex_Create_Buffer_From_BufferR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0xc8bf0 ldr r0, [pc, #0x134]
 *   @0xc8bf4 add r0, pc, r0
 *   @0xc8bf8 mov r1, #1
 *   @0xc8bfc add sp, sp, #12
 *   @0xc8c00 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xc8c04 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc8c08 mov r0, r4
 *   @0xc8c0c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc8c10 bl 0xc6720 <_Z10GetIBufferi>
 *   @0xc8c14 subs r5, r0, #0
 *   @0xc8c18 beq 0xc8d20 <_Z34F_Vertex_Create_Buffer_From_BufferR6RValueP9CInstanceS2_iPS_+0x15c>
 *   @0xc8c1c mov r0, r4
 *   @0xc8c20 mov r1, #1
 *   @0xc8c24 ldr r4, [r5, #0x20]
 *   @0xc8c28 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc8c2c bl 0x1e2cd0 <_Z15GetVertexFormati>
 *   @0xc8c30 cmp r4, #255
 *   @0xc8c34 movls r4, #256
 *   @0xc8c38 subs r9, r0, #0
 *   @0xc8c3c beq 0xc8d14 <_Z34F_Vertex_Create_Buffer_From_BufferR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0xc8c40 mov r0, r4
 *   @0xc8c44 bl 0xc8978 <_Z17AllocBufferVertexi>
 *   @0xc8c48 mov r4, r0
 *   @0xc8c4c bl 0xc8860 <_Z15GetBufferVertexi>
 *   @0xc8c50 subs r7, r0, #0
 *   @0xc8c54 beq 0xc8c64 <_Z34F_Vertex_Create_Buffer_From_BufferR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0xc8c58 ldrb r8, [r7, #0x20]
 *   @0xc8c5c cmp r8, #0
 *   @0xc8c60 beq 0xc8c7c <_Z34F_Vertex_Create_Buffer_From_BufferR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0xc8c64 ldr r0, [pc, #0xc4]
 *   @0xc8c68 mov r1, #1
 *   @0xc8c6c add r0, pc, r0
 *   @0xc8c70 add sp, sp, #12
 *   @0xc8c74 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xc8c78 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc8c7c ldr r2, [r5, #0x20]
 *   @0xc8c80 mvn r10, #0
 *   @0xc8c84 ldr r1, [r5, #0xc]
 *   @0xc8c88 ldr r0, [r7]
 *   @0xc8c8c bl 0xb65bc <memcpy@plt>
 *   @0xc8c90 ldr r11, [r5, #0x20]
 *   @0xc8c94 ldr r1, [r9, #0x14]
 *   @0xc8c98 mov r0, r11
 *   @0xc8c9c bl 0x318c48 <__udivsi3>
 *   @0xc8ca0 vmov s15, r4
 *   @0xc8ca4 ldr r1, [r9]
 *   @0xc8ca8 vcvt.f64.s32 d7, s15
 *   @0xc8cac vmov r2, r3, d7
 *   @0xc8cb0 mov r5, r0
 *   @0xc8cb4 ldr r0, [r9, #0x4]
 *   @0xc8cb8 str r1, [r7, #0x28]
 *   @0xc8cbc vmov r1, s14
 *   @0xc8cc0 str r8, [r7, #0x18]
 *   @0xc8cc4 str r11, [r7, #0xc]
 *   @0xc8cc8 str r5, [r7, #0x1c]
 *   @0xc8ccc str r8, [r7, #0x8]
 *   @0xc8cd0 str r8, [r7, #0x10]
 *   @0xc8cd4 str r0, [r7, #0x14]
 *   @0xc8cd8 str r8, [r7, #0x2c]
 *   @0xc8cdc str r10, [r7, #0x24]
 *   @0xc8ce0 stm r6, {r1, r3}
 *   @0xc8ce4 bl 0x212e98 <_Z11IsBigEndianv>
 *   @0xc8ce8 cmp r0, #0
 *   @0xc8cec beq 0xc8d0c <_Z34F_Vertex_Create_Buffer_From_BufferR6RValueP9CInstanceS2_iPS_+0x148>
 *   @0xc8cf0 ldr r1, [r7]
 *   @0xc8cf4 mov r0, r9
 *   @0xc8cf8 str r10, [sp]
 *   @0xc8cfc mov r2, r5
 *   @0xc8d00 str r8, [sp, #0x4]
 *   @0xc8d04 mov r3, r8
 *   @0xc8d08 bl 0x1e251c <_ZN12VertexFormat16EndianSwapBufferEPhiiib>
 *   @0xc8d0c add sp, sp, #12
 *   @0xc8d10 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xc8d14 ldr r0, [pc, #0x18]
 *   @0xc8d18 add r0, pc, r0
 *   @0xc8d1c b 0xc8bf8 <_Z34F_Vertex_Create_Buffer_From_BufferR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0xc8d20 ldr r0, [pc, #0x10]
 *   @0xc8d24 add r0, pc, r0
 *   @0xc8d28 b 0xc8bf8 <_Z34F_Vertex_Create_Buffer_From_BufferR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0xc8d2c eoreq r8, r6, r0, asr lr
 *   @0xc8d30 eoreq r8, r6, r0, lsr #29
 *   @0xc8d34 eoreq r8, r6, r12, lsr #27
 *   @0xc8d38 eoreq r8, r6, r12, asr sp
 *
 * ══ §24/81 F_StringInsert(RValue&, CInstance*, CInstance*, int, RValue*)  0x110854  size 376  94 条（0x110854..0x1109cc）
 * @func 0x110854 0x1109cc  size 376  94 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)×2 / 0xb6538×2 / operator new[](unsigned int)×2 / 0xb65b0×2 / utf8_extract_char×2 / utf8_add_char×2 / YYGetInt32(RValue const*, int) / utf8_strlen
 * 字段偏移 top8: 0x8×5 / 0x4×2 / 0xc×2 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x110854 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x110858 sub sp, sp, #20
 *   @0x11085c mov r1, #0
 *   @0x110860 ldr r4, [sp, #0x38]
 *   @0x110864 str r0, [sp, #0x4]
 *   @0x110868 mov r0, r4
 *   @0x11086c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x110870 mov r1, #1
 *   @0x110874 mov r10, r0
 *   @0x110878 mov r0, r4
 *   @0x11087c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x110880 mov r1, #2
 *   @0x110884 mov r5, r0
 *   @0x110888 mov r0, r4
 *   @0x11088c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x110890 sub r4, r0, #1
 *   @0x110894 mov r0, r5
 *   @0x110898 bl 0x110648 <utf8_strlen>
 *   @0x11089c mov r7, r0
 *   @0x1108a0 mov r0, r10
 *   @0x1108a4 bl 0xb6538 <strlen@plt>
 *   @0x1108a8 mov r9, r0
 *   @0x1108ac mov r0, r5
 *   @0x1108b0 bl 0xb6538 <strlen@plt>
 *   @0x1108b4 cmp r4, #0
 *   @0x1108b8 blt 0x110998 <_Z14F_StringInsertR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x1108bc add r6, r0, r9
 *   @0x1108c0 cmp r4, r7
 *   @0x1108c4 movge r4, r7
 *   @0x1108c8 add r6, r6, #1
 *   @0x1108cc mov r0, r6
 *   @0x1108d0 bl 0x27d14c <_Znaj>
 *   @0x1108d4 mov r2, r6
 *   @0x1108d8 mov r1, #0
 *   @0x1108dc mov r8, r0
 *   @0x1108e0 bl 0xb65b0 <memset@plt>
 *   @0x1108e4 cmp r4, #0
 *   @0x1108e8 str r8, [sp, #0x8]
 *   @0x1108ec str r5, [sp, #0xc]
 *   @0x1108f0 movle r0, r8
 *   @0x1108f4 movle r4, #0
 *   @0x1108f8 ble 0x11092c <_Z14F_StringInsertR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x1108fc add r6, sp, #12
 *   @0x110900 add r5, sp, #8
 *   @0x110904 mov r11, #0
 *   @0x110908 mov r0, r6
 *   @0x11090c add r11, r11, #1
 *   @0x110910 bl 0x10fb38 <utf8_extract_char>
 *   @0x110914 mov r1, r0
 *   @0x110918 mov r0, r5
 *   @0x11091c bl 0x10fe28 <utf8_add_char>
 *   @0x110920 cmp r11, r4
 *   @0x110924 bne 0x110908 <_Z14F_StringInsertR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x110928 ldr r0, [sp, #0x8]
 *   @0x11092c mov r2, r9
 *   @0x110930 mov r1, r10
 *   @0x110934 bl 0xb65bc <memcpy@plt>
 *   @0x110938 cmp r7, r4
 *   @0x11093c ldr r3, [sp, #0x8]
 *   @0x110940 addgt r6, sp, #12
 *   @0x110944 addgt r5, sp, #8
 *   @0x110948 add r9, r3, r9
 *   @0x11094c str r9, [sp, #0x8]
 *   @0x110950 ble 0x110974 <_Z14F_StringInsertR6RValueP9CInstanceS2_iPS_+0x120>
 *   @0x110954 mov r0, r6
 *   @0x110958 add r4, r4, #1
 *   @0x11095c bl 0x10fb38 <utf8_extract_char>
 *   @0x110960 mov r1, r0
 *   @0x110964 mov r0, r5
 *   @0x110968 bl 0x10fe28 <utf8_add_char>
 *   @0x11096c cmp r4, r7
 *   @0x110970 bne 0x110954 <_Z14F_StringInsertR6RValueP9CInstanceS2_iPS_+0x100>
 *   @0x110974 ldr r0, [sp, #0x4]
 *   @0x110978 mov r1, r8
 *   @0x11097c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x110980 cmp r8, #0
 *   @0x110984 beq 0x110990 <_Z14F_StringInsertR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x110988 mov r0, r8
 *   @0x11098c bl 0x27d1d4 <_ZdaPv>
 *   @0x110990 add sp, sp, #20
 *   @0x110994 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x110998 add r0, r0, r9
 *   @0x11099c mov r4, #0
 *   @0x1109a0 add r6, r0, #1
 *   @0x1109a4 mov r0, r6
 *   @0x1109a8 bl 0x27d14c <_Znaj>
 *   @0x1109ac mov r2, r6
 *   @0x1109b0 mov r1, r4
 *   @0x1109b4 mov r8, r0
 *   @0x1109b8 bl 0xb65b0 <memset@plt>
 *   @0x1109bc str r8, [sp, #0x8]
 *   @0x1109c0 mov r0, r8
 *   @0x1109c4 str r5, [sp, #0xc]
 *   @0x1109c8 b 0x11092c <_Z14F_StringInsertR6RValueP9CInstanceS2_iPS_+0xd8>
 *
 * ══ §25/81 F_HttpGetFile(RValue&, CInstance*, CInstance*, int, RValue*)  0x13b6b8  size 376  94 条（0x13b6b8..0x13b830）
 * @func 0x13b6b8 0x13b830  size 376  94 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x13b6d4→0x533c54, 0x13b7cc→0x5356b4
 * 调用序列: YYGetString(RValue const*, int)×2 / 0xb65e0×2 / LoadSave::_GetSaveFileName(char*, int, char const*) / EnsureDirectoryIsCreated(char const*) / 0xb6538 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65a4 / LoadSave::HTTP_Get(char const*, int, int (*)(HTTP_REQ_CONTEXT*, void*, int*), void (*)(HTTP_REQ_CONTEXT*), void*)
 * 字段偏移 top8: 0x40c×2 / 0x54×2 / 0x148×1 / 0x144×1 / 0x13c×1 / 0x430×1 / 0xc×1 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13b6b8 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x13b6bc sub sp, sp, #1040
 *   @0x13b6c0 ldr r5, [pc, #0x148]
 *   @0x13b6c4 sub sp, sp, #4
 *   @0x13b6c8 ldr r2, [pc, #0x144]
 *   @0x13b6cc mov r4, r0
 *   @0x13b6d0 add r5, pc, r5
 *   @0x13b6d4 ldr r3, [pc, #0x13c]
 *   @0x13b6d8 ldr r9, [sp, #0x430]
 *   @0x13b6dc mov r1, #0
 *   @0x13b6e0 ldr r7, [r5, r2]
 *   @0x13b6e4 mov r8, #1
 *   @0x13b6e8 mov r0, r9
 *   @0x13b6ec ldr r2, [r7]
 *   @0x13b6f0 str r2, [sp, #0x40c]
 *   @0x13b6f4 ldr r3, [r5, r3]
 *   @0x13b6f8 strb r8, [r3]
 *   @0x13b6fc bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x13b700 mov r1, r8
 *   @0x13b704 mov r6, r0
 *   @0x13b708 mov r0, r9
 *   @0x13b70c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x13b710 cmp r6, #0
 *   @0x13b714 mov r1, #0
 *   @0x13b718 mov r3, r1
 *   @0x13b71c movt r1, #0xbff0
 *   @0x13b720 str r3, [r4, #0xc]
 *   @0x13b724 str r1, [r4, #0x4]
 *   @0x13b728 str r3, [r4]
 *   @0x13b72c mov r8, r0
 *   @0x13b730 beq 0x13b76c <_Z13F_HttpGetFileR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x13b734 ldr r0, [pc, #0xe0]
 *   @0x13b738 mov r1, r6
 *   @0x13b73c mov r2, #7
 *   @0x13b740 add r0, pc, r0
 *   @0x13b744 bl 0xb65e0 <strncmp@plt>
 *   @0x13b748 cmp r0, #0
 *   @0x13b74c beq 0x13b788 <_Z13F_HttpGetFileR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x13b750 ldr r0, [pc, #0xc8]
 *   @0x13b754 mov r1, r6
 *   @0x13b758 mov r2, #8
 *   @0x13b75c add r0, pc, r0
 *   @0x13b760 bl 0xb65e0 <strncmp@plt>
 *   @0x13b764 cmp r0, #0
 *   @0x13b768 beq 0x13b788 <_Z13F_HttpGetFileR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x13b76c ldr r2, [sp, #0x40c]
 *   @0x13b770 ldr r3, [r7]
 *   @0x13b774 cmp r2, r3
 *   @0x13b778 bne 0x13b80c <_Z13F_HttpGetFileR6RValueP9CInstanceS2_iPS_+0x154>
 *   @0x13b77c add sp, sp, #1040
 *   @0x13b780 add sp, sp, #4
 *   @0x13b784 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x13b788 mov r2, r8
 *   @0x13b78c add r8, sp, #12
 *   @0x13b790 mov r1, #1024
 *   @0x13b794 mov r0, r8
 *   @0x13b798 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x13b79c mov r0, r8
 *   @0x13b7a0 bl 0x13ad20 <_Z24EnsureDirectoryIsCreatedPKc>
 *   @0x13b7a4 mov r0, r8
 *   @0x13b7a8 bl 0xb6538 <strlen@plt>
 *   @0x13b7ac ldr r1, [pc, #0x70]
 *   @0x13b7b0 mov r3, #1
 *   @0x13b7b4 movw r2, #0x97b
 *   @0x13b7b8 add r1, pc, r1
 *   @0x13b7bc add r0, r0, r3
 *   @0x13b7c0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x13b7c4 mov r1, r8
 *   @0x13b7c8 bl 0xb65a4 <strcpy@plt>
 *   @0x13b7cc ldr lr, [pc, #0x54]
 *   @0x13b7d0 ldr r2, [pc, #0x54]
 *   @0x13b7d4 mov r3, #0
 *   @0x13b7d8 mvn r1, #0
 *   @0x13b7dc ldr lr, [r5, lr]
 *   @0x13b7e0 ldr r2, [r5, r2]
 *   @0x13b7e4 mov r12, r0
 *   @0x13b7e8 str r12, [sp]
 *   @0x13b7ec ldr r5, [lr]
 *   @0x13b7f0 mov r0, r6
 *   @0x13b7f4 bl 0x18fc68 <_ZN8LoadSave8HTTP_GetEPKciPFiP16HTTP_REQ_CONTEXTPvPiEPFvS3_ES4_>
 *   @0x13b7f8 vmov s15, r5
 *   @0x13b7fc vcvt.f64.s32 d7, s15
 *   @0x13b800 vmov r2, r3, d7
 *   @0x13b804 stm r4, {r2, r3}
 *   @0x13b808 b 0x13b76c <_Z13F_HttpGetFileR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x13b80c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x13b810 eoreq r6, r11, r0, lsl #11
 *   @0x13b814 .word 0xffffbd00
 *   @0x13b818 .word 0xffffbd04
 *   @0x13b81c andseq r5, pc, r0, lsr #7
 *   @0x13b820 andseq r5, pc, r12, lsl #7
 *   @0x13b824 mlaeq r0, r8, r8, r4
 *   @0x13b828 .word 0xffffd628
 *   @0x13b82c .word 0xffffd64c
 *
 * ══ §26/81 Graphics::OpenWindow(void*, int, int, int)  0x17dbcc  size 376  94 条（0x17dbcc..0x17dd44）
 * @func 0x17dbcc 0x17dd44  size 376  94 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x17dbdc→0x4a22b1, 0x17dbe8→0x479c24, 0x17dc04→0x479c74, 0x17dc18→0x479c80, 0x17dc50→0x3f26dc, 0x17dc64→0x479c20, 0x17dc84→0x3f243c, 0x17dc94→0x499309
 * 调用序列: GetOpenGLInfo() / InitOGLResources()
 * 字段偏移 top8: 0x144×1 / 0x140×1 / 0x138×1 / 0x120×1 / 0x110×1 / 0xdc×1 / 0xcc×1 / 0xb0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17dbcc push {r4, r5, r6, r7, r8, lr}
 *   @0x17dbd0 mov r6, r3
 *   @0x17dbd4 ldr r4, [pc, #0x144]
 *   @0x17dbd8 mov r2, #1
 *   @0x17dbdc ldr r1, [pc, #0x140]
 *   @0x17dbe0 mov r0, #0
 *   @0x17dbe4 add r4, pc, r4
 *   @0x17dbe8 ldr r3, [pc, #0x138]
 *   @0x17dbec ldr r12, [r4, r1]
 *   @0x17dbf0 mov r1, #1065353216
 *   @0x17dbf4 strb r2, [r12]
 *   @0x17dbf8 ldr r3, [r4, r3]
 *   @0x17dbfc ldr r3, [r3]
 *   @0x17dc00 blx r3
 *   @0x17dc04 ldr r3, [pc, #0x120]
 *   @0x17dc08 movw r0, #0xc11
 *   @0x17dc0c ldr r8, [r4, r3]
 *   @0x17dc10 ldr r3, [r8]
 *   @0x17dc14 blx r3
 *   @0x17dc18 ldr r3, [pc, #0x110]
 *   @0x17dc1c movw r0, #0xbe2
 *   @0x17dc20 ldr r5, [r4, r3]
 *   @0x17dc24 ldr r3, [r5]
 *   @0x17dc28 blx r3
 *   @0x17dc2c ldr r3, [r5]
 *   @0x17dc30 movw r0, #0xb44
 *   @0x17dc34 blx r3
 *   @0x17dc38 ldr r3, [r5]
 *   @0x17dc3c mov r0, #2960
 *   @0x17dc40 blx r3
 *   @0x17dc44 ldr r3, [r5]
 *   @0x17dc48 mov r0, #3024
 *   @0x17dc4c blx r3
 *   @0x17dc50 ldr r3, [pc, #0xdc]
 *   @0x17dc54 ldr r7, [r4, r3]
 *   @0x17dc58 ldr r3, [r7]
 *   @0x17dc5c cmp r3, #0
 *   @0x17dc60 beq 0x17dcd4 <_ZN8Graphics10OpenWindowEPviii+0x108>
 *   @0x17dc64 ldr r3, [pc, #0xcc]
 *   @0x17dc68 movw r0, #0x203
 *   @0x17dc6c ldr r3, [r4, r3]
 *   @0x17dc70 ldr r3, [r3]
 *   @0x17dc74 blx r3
 *   @0x17dc78 bl 0x17d450 <_Z13GetOpenGLInfov>
 *   @0x17dc7c ands r3, r6, #8
 *   @0x17dc80 beq 0x17dcc4 <_ZN8Graphics10OpenWindowEPviii+0xf8>
 *   @0x17dc84 ldr r3, [pc, #0xb0]
 *   @0x17dc88 mov r2, #1
 *   @0x17dc8c ldr r3, [r4, r3]
 *   @0x17dc90 strb r2, [r3]
 *   @0x17dc94 ldr r3, [pc, #0xa4]
 *   @0x17dc98 ands r6, r6, #16
 *   @0x17dc9c movne r2, #1
 *   @0x17dca0 ldreq r3, [r4, r3]
 *   @0x17dca4 ldrne r3, [r4, r3]
 *   @0x17dca8 strbeq r6, [r3]
 *   @0x17dcac strbne r2, [r3]
 *   @0x17dcb0 ldr r3, [r7]
 *   @0x17dcb4 cmp r3, #1
 *   @0x17dcb8 beq 0x17dd14 <_ZN8Graphics10OpenWindowEPviii+0x148>
 *   @0x17dcbc mov r0, #1
 *   @0x17dcc0 pop {r4, r5, r6, r7, r8, pc}
 *   @0x17dcc4 ldr r2, [pc, #0x70]
 *   @0x17dcc8 ldr r2, [r4, r2]
 *   @0x17dccc strb r3, [r2]
 *   @0x17dcd0 b 0x17dc94 <_ZN8Graphics10OpenWindowEPviii+0xc8>
 *   @0x17dcd4 ldr r3, [r5]
 *   @0x17dcd8 mov r0, #3008
 *   @0x17dcdc blx r3
 *   @0x17dce0 ldr r3, [r5]
 *   @0x17dce4 mov r0, #2912
 *   @0x17dce8 blx r3
 *   @0x17dcec ldr r3, [r5]
 *   @0x17dcf0 mov r0, #2896
 *   @0x17dcf4 blx r3
 *   @0x17dcf8 ldr r3, [r5]
 *   @0x17dcfc movw r0, #0xde1
 *   @0x17dd00 blx r3
 *   @0x17dd04 ldr r3, [r8]
 *   @0x17dd08 movw r0, #0xba1
 *   @0x17dd0c blx r3
 *   @0x17dd10 b 0x17dc64 <_ZN8Graphics10OpenWindowEPviii+0x98>
 *   @0x17dd14 bl 0x17da94 <_Z16InitOGLResourcesv>
 *   @0x17dd18 mov r0, #1
 *   @0x17dd1c pop {r4, r5, r6, r7, r8, pc}
 *   @0x17dd20 eoreq r4, r7, r12, rrx
 *   @0x17dd24 .word 0xffffe4d0
 *   @0x17dd28 .word 0xffffbae8
 *   @0x17dd2c .word 0xffffbad8
 *   @0x17dd30 .word 0xffffbad0
 *   @0x17dd34 .word 0xffffe7b8
 *   @0x17dd38 .word 0xffffbaec
 *   @0x17dd3c .word 0xffffe4d8
 *   @0x17dd40 .word 0xffffe6a0
 *
 * ══ §27/81 GV_Argument(CInstance*, int, RValue*)  0x1ffca4  size 376  94 条（0x1ffca4..0x1ffe1c）
 * @func 0x1ffca4 0x1ffe1c  size 376  94 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GV_Argument(CInstance*, int, RValue*)+0xc0 / Error_Show_Action(char const*, bool) / FREE_RValue__Pre(RValue*) / GetContextStackTop() / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)
 * 字段偏移 top8: 0x4×8 / 0xc×5 / 0x8×4 / 0x154×1 / 0x12c×1 / 0xac×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1ffca4 push {r4, r5, r6, lr}
 *   @0x1ffca8 subs r5, r1, #0
 *   @0x1ffcac mov r4, r2
 *   @0x1ffcb0 blt 0x1ffd64 <_Z11GV_ArgumentP9CInstanceiP6RValue+0xc0>
 *   @0x1ffcb4 ldr r3, [pc, #0x154]
 *   @0x1ffcb8 ldr r3, [pc, r3]
 *   @0x1ffcbc ldr r3, [r3]
 *   @0x1ffcc0 cmp r5, r3
 *   @0x1ffcc4 bge 0x1ffd64 <_Z11GV_ArgumentP9CInstanceiP6RValue+0xc0>
 *   @0x1ffcc8 ldr r3, [r4, #0xc]
 *   @0x1ffccc sub r3, r3, #1
 *   @0x1ffcd0 bic r3, r3, #-16777216
 *   @0x1ffcd4 bic r3, r3, #3
 *   @0x1ffcd8 cmp r3, #0
 *   @0x1ffcdc beq 0x1ffd9c <_Z11GV_ArgumentP9CInstanceiP6RValue+0xf8>
 *   @0x1ffce0 ldr r3, [pc, #0x12c]
 *   @0x1ffce4 mov r2, #0
 *   @0x1ffce8 str r2, [r4]
 *   @0x1ffcec mov r1, #5
 *   @0x1ffcf0 ldr r3, [pc, r3]
 *   @0x1ffcf4 str r1, [r4, #0xc]
 *   @0x1ffcf8 str r2, [r4, #0x8]
 *   @0x1ffcfc ldr r6, [r3]
 *   @0x1ffd00 add r3, r6, r5, lsl #4
 *   @0x1ffd04 ldr r2, [r3, #0xc]
 *   @0x1ffd08 ldr r1, [r3, #0x8]
 *   @0x1ffd0c str r2, [r4, #0xc]
 *   @0x1ffd10 ldr r2, [r3, #0xc]
 *   @0x1ffd14 str r1, [r4, #0x8]
 *   @0x1ffd18 bic r2, r2, #-16777216
 *   @0x1ffd1c cmp r2, #14
 *   @0x1ffd20 addls pc, pc, r2, lsl #2
 *   @0x1ffd24 b 0x1ffd80 <_Z11GV_ArgumentP9CInstanceiP6RValue+0xdc>
 *   @0x1ffd28 b 0x1ffd88 <_Z11GV_ArgumentP9CInstanceiP6RValue+0xe4>
 *   @0x1ffd2c b 0x1ffdcc <_Z11GV_ArgumentP9CInstanceiP6RValue+0x128>
 *   @0x1ffd30 b 0x1ffde4 <_Z11GV_ArgumentP9CInstanceiP6RValue+0x140>
 *   @0x1ffd34 b 0x1ffd78 <_Z11GV_ArgumentP9CInstanceiP6RValue+0xd4>
 *   @0x1ffd38 b 0x1ffd80 <_Z11GV_ArgumentP9CInstanceiP6RValue+0xdc>
 *   @0x1ffd3c b 0x1ffd80 <_Z11GV_ArgumentP9CInstanceiP6RValue+0xdc>
 *   @0x1ffd40 b 0x1ffda8 <_Z11GV_ArgumentP9CInstanceiP6RValue+0x104>
 *   @0x1ffd44 b 0x1ffd78 <_Z11GV_ArgumentP9CInstanceiP6RValue+0xd4>
 *   @0x1ffd48 b 0x1ffd80 <_Z11GV_ArgumentP9CInstanceiP6RValue+0xdc>
 *   @0x1ffd4c b 0x1ffd80 <_Z11GV_ArgumentP9CInstanceiP6RValue+0xdc>
 *   @0x1ffd50 b 0x1ffd88 <_Z11GV_ArgumentP9CInstanceiP6RValue+0xe4>
 *   @0x1ffd54 b 0x1ffd80 <_Z11GV_ArgumentP9CInstanceiP6RValue+0xdc>
 *   @0x1ffd58 b 0x1ffd80 <_Z11GV_ArgumentP9CInstanceiP6RValue+0xdc>
 *   @0x1ffd5c b 0x1ffd88 <_Z11GV_ArgumentP9CInstanceiP6RValue+0xe4>
 *   @0x1ffd60 b 0x1ffd78 <_Z11GV_ArgumentP9CInstanceiP6RValue+0xd4>
 *   @0x1ffd64 ldr r0, [pc, #0xac]
 *   @0x1ffd68 mov r1, #1
 *   @0x1ffd6c add r0, pc, r0
 *   @0x1ffd70 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1ffd74 b 0x1ffcc8 <_Z11GV_ArgumentP9CInstanceiP6RValue+0x24>
 *   @0x1ffd78 ldr r3, [r6, r5, lsl #4]
 *   @0x1ffd7c str r3, [r4]
 *   @0x1ffd80 mov r0, #1
 *   @0x1ffd84 pop {r4, r5, r6, pc}
 *   @0x1ffd88 ldr r2, [r6, r5, lsl #4]
 *   @0x1ffd8c mov r0, #1
 *   @0x1ffd90 ldr r3, [r3, #0x4]
 *   @0x1ffd94 stm r4, {r2, r3}
 *   @0x1ffd98 pop {r4, r5, r6, pc}
 *   @0x1ffd9c mov r0, r4
 *   @0x1ffda0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x1ffda4 b 0x1ffce0 <_Z11GV_ArgumentP9CInstanceiP6RValue+0x3c>
 *   @0x1ffda8 ldr r3, [r6, r5, lsl #4]
 *   @0x1ffdac str r3, [r4]
 *   @0x1ffdb0 ldr r3, [r6, r5, lsl #4]
 *   @0x1ffdb4 cmp r3, #0
 *   @0x1ffdb8 beq 0x1ffd80 <_Z11GV_ArgumentP9CInstanceiP6RValue+0xdc>
 *   @0x1ffdbc bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x1ffdc0 ldr r1, [r6, r5, lsl #4]
 *   @0x1ffdc4 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x1ffdc8 b 0x1ffd80 <_Z11GV_ArgumentP9CInstanceiP6RValue+0xdc>
 *   @0x1ffdcc ldr r3, [r6, r5, lsl #4]
 *   @0x1ffdd0 cmp r3, #0
 *   @0x1ffdd4 ldrne r2, [r3, #0x4]
 *   @0x1ffdd8 addne r2, r2, #1
 *   @0x1ffddc strne r2, [r3, #0x4]
 *   @0x1ffde0 b 0x1ffd7c <_Z11GV_ArgumentP9CInstanceiP6RValue+0xd8>
 *   @0x1ffde4 ldr r3, [r6, r5, lsl #4]
 *   @0x1ffde8 cmp r3, #0
 *   @0x1ffdec str r3, [r4]
 *   @0x1ffdf0 beq 0x1ffd80 <_Z11GV_ArgumentP9CInstanceiP6RValue+0xdc>
 *   @0x1ffdf4 ldr r1, [r3, #0x8]
 *   @0x1ffdf8 ldr r2, [r3]
 *   @0x1ffdfc cmp r1, #0
 *   @0x1ffe00 streq r4, [r3, #0x8]
 *   @0x1ffe04 add r2, r2, #1
 *   @0x1ffe08 str r2, [r3]
 *   @0x1ffe0c b 0x1ffd80 <_Z11GV_ArgumentP9CInstanceiP6RValue+0xdc>
 *   @0x1ffe10 andseq lr, lr, r4, asr r0
 *   @0x1ffe14 andseq lr, lr, r0, lsr #32
 *   @0x1ffe18 andseq r3, r5, r12, ror r9
 *
 * ══ §28/81 WriteValue(CStream&, RValue&)  0x202af8  size 376  94 条（0x202af8..0x202c70）
 * @func 0x202af8 0x202c70  size 376  94 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::WriteInteger(int)×3 / WriteValue(CStream&, RValue&)+0x150 / WriteValue(CStream&, RValue&) / WriteValue(CStream&, RValue&)+0x130 / WriteValue(CStream&, RValue&)+0x10c
 * 字段偏移 top8: 0xc×3 / 0x4×3 / 0x10×3 / 0x10c×2 / 0x3×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x202af8 push {r4, r5, r6, r7, r8, lr}
 *   @0x202afc mov r4, r1
 *   @0x202b00 ldr r1, [r1, #0xc]
 *   @0x202b04 mov r6, r0
 *   @0x202b08 bl 0x201a10 <_ZN7CStream12WriteIntegerEi>
 *   @0x202b0c ldr r2, [r4, #0xc]
 *   @0x202b10 cmp r2, #13
 *   @0x202b14 addls pc, pc, r2, lsl #2
 *   @0x202b18 b 0x202b54 <_Z10WriteValueR7CStreamR6RValue+0x5c>
 *   @0x202b1c b 0x202bac <_Z10WriteValueR7CStreamR6RValue+0xb4>
 *   @0x202b20 b 0x202bc0 <_Z10WriteValueR7CStreamR6RValue+0xc8>
 *   @0x202b24 b 0x202bdc <_Z10WriteValueR7CStreamR6RValue+0xe4>
 *   @0x202b28 b 0x202b78 <_Z10WriteValueR7CStreamR6RValue+0x80>
 *   @0x202b2c b 0x202b54 <_Z10WriteValueR7CStreamR6RValue+0x5c>
 *   @0x202b30 b 0x202b74 <_Z10WriteValueR7CStreamR6RValue+0x7c>
 *   @0x202b34 b 0x202b54 <_Z10WriteValueR7CStreamR6RValue+0x5c>
 *   @0x202b38 b 0x202b8c <_Z10WriteValueR7CStreamR6RValue+0x94>
 *   @0x202b3c b 0x202b54 <_Z10WriteValueR7CStreamR6RValue+0x5c>
 *   @0x202b40 b 0x202b54 <_Z10WriteValueR7CStreamR6RValue+0x5c>
 *   @0x202b44 b 0x202b9c <_Z10WriteValueR7CStreamR6RValue+0xa4>
 *   @0x202b48 b 0x202b54 <_Z10WriteValueR7CStreamR6RValue+0x5c>
 *   @0x202b4c b 0x202b54 <_Z10WriteValueR7CStreamR6RValue+0x5c>
 *   @0x202b50 b 0x202bac <_Z10WriteValueR7CStreamR6RValue+0xb4>
 *   @0x202b54 ldr r3, [pc, #0x10c]
 *   @0x202b58 ldr r1, [pc, #0x10c]
 *   @0x202b5c ldr r3, [pc, r3]
 *   @0x202b60 add r1, pc, r1
 *   @0x202b64 ldr r0, [r3]
 *   @0x202b68 ldr r3, [r0]
 *   @0x202b6c ldr r3, [r3, #0xc]
 *   @0x202b70 blx r3
 *   @0x202b74 pop {r4, r5, r6, r7, r8, pc}
 *   @0x202b78 ldr r2, [r4]
 *   @0x202b7c mov r0, r6
 *   @0x202b80 pop {r4, r5, r6, r7, r8, lr}
 *   @0x202b84 asr r3, r2, #31
 *   @0x202b88 b 0x201a68 <_ZN7CStream14WriteInteger64Ex>
 *   @0x202b8c mov r0, r6
 *   @0x202b90 ldr r1, [r4]
 *   @0x202b94 pop {r4, r5, r6, r7, r8, lr}
 *   @0x202b98 b 0x201a10 <_ZN7CStream12WriteIntegerEi>
 *   @0x202b9c mov r0, r6
 *   @0x202ba0 ldm r4, {r2, r3}
 *   @0x202ba4 pop {r4, r5, r6, r7, r8, lr}
 *   @0x202ba8 b 0x201a68 <_ZN7CStream14WriteInteger64Ex>
 *   @0x202bac ldr r2, [r4]
 *   @0x202bb0 mov r0, r6
 *   @0x202bb4 ldr r3, [r4, #0x4]
 *   @0x202bb8 pop {r4, r5, r6, r7, r8, lr}
 *   @0x202bbc b 0x201ae0 <_ZN7CStream9WriteRealEd>
 *   @0x202bc0 ldr r3, [r4]
 *   @0x202bc4 mov r0, r6
 *   @0x202bc8 pop {r4, r5, r6, r7, r8, lr}
 *   @0x202bcc cmp r3, #0
 *   @0x202bd0 ldrne r1, [r3]
 *   @0x202bd4 moveq r1, r3
 *   @0x202bd8 b 0x201b58 <_ZN7CStream11WriteStringEPKc>
 *   @0x202bdc ldr r8, [r4]
 *   @0x202be0 mov r0, r6
 *   @0x202be4 cmp r8, #0
 *   @0x202be8 beq 0x202c5c <_Z10WriteValueR7CStreamR6RValue+0x164>
 *   @0x202bec ldr r1, [r8, #0x10]
 *   @0x202bf0 bl 0x201a10 <_ZN7CStream12WriteIntegerEi>
 *   @0x202bf4 ldr r3, [r8, #0x10]
 *   @0x202bf8 cmp r3, #0
 *   @0x202bfc pople {r4, r5, r6, r7, r8, pc}
 *   @0x202c00 mov r7, #0
 *   @0x202c04 ldr r4, [r8, #0x4]
 *   @0x202c08 mov r0, r6
 *   @0x202c0c add r5, r4, r7, lsl #3
 *   @0x202c10 ldr r1, [r4, r7, lsl #3]
 *   @0x202c14 bl 0x201a10 <_ZN7CStream12WriteIntegerEi>
 *   @0x202c18 ldr r3, [r4, r7, lsl #3]
 *   @0x202c1c cmp r3, #0
 *   @0x202c20 movgt r4, #0
 *   @0x202c24 ble 0x202c48 <_Z10WriteValueR7CStreamR6RValue+0x150>
 *   @0x202c28 ldr r1, [r5, #0x4]
 *   @0x202c2c mov r0, r6
 *   @0x202c30 add r1, r1, r4, lsl #4
 *   @0x202c34 add r4, r4, #1
 *   @0x202c38 bl 0x202af8 <_Z10WriteValueR7CStreamR6RValue>
 *   @0x202c3c ldr r3, [r5]
 *   @0x202c40 cmp r4, r3
 *   @0x202c44 blt 0x202c28 <_Z10WriteValueR7CStreamR6RValue+0x130>
 *   @0x202c48 ldr r3, [r8, #0x10]
 *   @0x202c4c add r7, r7, #1
 *   @0x202c50 cmp r7, r3
 *   @0x202c54 blt 0x202c04 <_Z10WriteValueR7CStreamR6RValue+0x10c>
 *   @0x202c58 pop {r4, r5, r6, r7, r8, pc}
 *   @0x202c5c mov r1, r8
 *   @0x202c60 pop {r4, r5, r6, r7, r8, lr}
 *   @0x202c64 b 0x201a10 <_ZN7CStream12WriteIntegerEi>
 *   @0x202c68 ldrheq r10, [lr], -r8
 *   @0x202c6c andseq r0, r5, r8, asr #24
 *
 * ══ §29/81 SND_Play(char const*, int, bool)  0x21eb7c  size 376  87 条（0x21eb7c..0x21ecf4）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x21eb7c 0x21ecf4  size 376  87 条
 * 部分覆盖: 本节 87/94 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x21eb8c→0x755363, 0x21ebd8→0x755334, 0x21ebec→0x755338, 0x21ec48→0x755330, 0x21ecac→0x755330
 * 调用序列: 0xb6538
 * 字段偏移 top8: 0x-1×3 / 0x-3×2 / 0x-2×2 / 0x34×2 / 0x148×1 / 0x144×1 / 0x-4×1 / 0x-5×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21eb7c push {r3, r4, r5, r6, r7, lr}
 *   @0x21eb80 mov r5, r1
 *   @0x21eba0 cmp r3, #0
 *   @0x21eba4 popne {r3, r4, r5, r6, r7, pc}
 *   @0x21eba8 cmp r0, #0
 *   @0x21ebac beq 0x21ebd0 <_Z8SND_PlayPKcib+0x54>
 *   @0x21ebb0 bl 0xb6538 <strlen@plt>
 *   @0x21ebb4 add r0, r6, r0
 *   @0x21ebb8 ldrb r3, [r0, #-0x4]
 *   @0x21ebbc cmp r3, #46
 *   @0x21ebc0 beq 0x21ec1c <_Z8SND_PlayPKcib+0xa0>
 *   @0x21ebc4 ldrb r2, [r0, #-0x5]
 *   @0x21ebc8 cmp r2, #46
 *   @0x21ebcc beq 0x21ec70 <_Z8SND_PlayPKcib+0xf4>
 *   @0x21ebd0 cmp r5, #0
 *   @0x21ebd4 poplt {r3, r4, r5, r6, r7, pc}
 *   @0x21ebd8 ldr r3, [pc, #0xfc]
 *   @0x21ebdc ldr r3, [r4, r3]
 *   @0x21ebe0 ldr r3, [r3]
 *   @0x21ebe4 cmp r5, r3
 *   @0x21ebe8 popge {r3, r4, r5, r6, r7, pc}
 *   @0x21ebec ldr r3, [pc, #0xec]
 *   @0x21ebf0 add r5, r5, r5, lsl #2
 *   @0x21ebf4 ldr r1, [pc, #0xe8]
 *   @0x21ebf8 mov r2, r7
 *   @0x21ebfc ldr r3, [r4, r3]
 *   @0x21ec00 add r1, pc, r1
 *   @0x21ec04 ldr r0, [r1]
 *   @0x21ec08 ldr r3, [r3, #0x4]
 *   @0x21ec0c add r5, r3, r5, lsl #2
 *   @0x21ec10 ldr r1, [r5, #0x8]
 *   @0x21ec14 pop {r3, r4, r5, r6, r7, lr}
 *   @0x21ec18 b 0x220764 <_ZN13SoundHardware4PlayEPvb>
 *   @0x21ec1c ldrb r3, [r0, #-0x3]
 *   @0x21ec20 cmp r3, #109
 *   @0x21ec24 bne 0x21ebd0 <_Z8SND_PlayPKcib+0x54>
 *   @0x21ec28 ldrb r3, [r0, #-0x2]
 *   @0x21ec2c cmp r3, #112
 *   @0x21ec30 beq 0x21eca0 <_Z8SND_PlayPKcib+0x124>
 *   @0x21ec34 cmp r3, #105
 *   @0x21ec38 bne 0x21ebd0 <_Z8SND_PlayPKcib+0x54>
 *   @0x21ec3c ldrb r3, [r0, #-0x1]
 *   @0x21ec40 cmp r3, #100
 *   @0x21ec44 bne 0x21ebd0 <_Z8SND_PlayPKcib+0x54>
 *   @0x21ec48 ldr r3, [pc, #0x98]
 *   @0x21ec4c mov r2, r7
 *   @0x21ec50 ldr r0, [pc, #0x94]
 *   @0x21ec54 mov r1, r6
 *   @0x21ec58 ldr r3, [r4, r3]
 *   @0x21ec5c add r0, pc, r0
 *   @0x21ec60 ldr r0, [r0]
 *   @0x21ec64 str r6, [r3]
 *   @0x21ec68 pop {r3, r4, r5, r6, r7, lr}
 *   @0x21ec6c b 0x220adc <_ZN13SoundHardware8PlayMIDIEPKcb>
 *   @0x21ec70 cmp r3, #109
 *   @0x21ec74 bne 0x21ebd0 <_Z8SND_PlayPKcib+0x54>
 *   @0x21ec78 ldrb r3, [r0, #-0x3]
 *   @0x21ec7c cmp r3, #105
 *   @0x21ec80 bne 0x21ebd0 <_Z8SND_PlayPKcib+0x54>
 *   @0x21ec84 ldrb r3, [r0, #-0x2]
 *   @0x21ec88 cmp r3, #100
 *   @0x21ec8c bne 0x21ebd0 <_Z8SND_PlayPKcib+0x54>
 *   @0x21ec90 ldrb r3, [r0, #-0x1]
 *   @0x21ec94 cmp r3, #105
 *   @0x21ec98 bne 0x21ebd0 <_Z8SND_PlayPKcib+0x54>
 *   @0x21ec9c b 0x21ec48 <_Z8SND_PlayPKcib+0xcc>
 *   @0x21eca0 ldrb r3, [r0, #-0x1]
 *   @0x21eca4 cmp r3, #51
 *   @0x21eca8 bne 0x21ebd0 <_Z8SND_PlayPKcib+0x54>
 *   @0x21ecac ldr r3, [pc, #0x34]
 *   @0x21ecb0 mov r2, r7
 *   @0x21ecb4 ldr r0, [pc, #0x34]
 *   @0x21ecb8 mov r1, r6
 *   @0x21ecbc ldr r3, [r4, r3]
 *   @0x21ecc0 add r0, pc, r0
 *   @0x21ecc4 ldr r0, [r0]
 *   @0x21ecc8 str r6, [r3]
 *   @0x21eccc pop {r3, r4, r5, r6, r7, lr}
 *   @0x21ecd0 b 0x2209fc <_ZN13SoundHardware7PlayMP3EPKcb>
 *   @0x21ecd4 ldrheq r3, [sp], -r12
 *   @0x21ecd8 .word 0xffffd3fc
 *   @0x21ecdc .word 0xfffff7c4
 *   @0x21ece0 .word 0xfffff7c8
 *   @0x21ece4 subseq r6, r3, r4, lsr #14
 *   @0x21ece8 .word 0xfffff7cc
 *   @0x21ecec subseq r6, r3, r8, asr #13
 *   @0x21ecf0 subseq r6, r3, r4, ror #12
 *
 * ══ §30/81 COggThread::Create(int, int, int)  0x223924  size 376  94 条（0x223924..0x223a9c）
 * @func 0x223924 0x223a9c  size 376  94 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new[](unsigned int)×2 / SOggChannel::SOggChannel() / COggThread::Create(int, int, int)+0x100 / SOggChannel::Init(unsigned int) / COggThread::Create(int, int, int)+0x150 / operator new(unsigned int) / Mutex::Mutex(char const*) / COggThread::StartThread()
 * 字段偏移 top8: 0x4×3 / 0x804×2 / 0x15c×1 / 0x808×1 / 0x830×1 / 0x80c×1 / 0x800×1 / 0x801×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x223924 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x223928 mov r8, r3
 *   @0x22392c ldr r3, [pc, #0x15c]
 *   @0x223930 sub r6, r8, #1
 *   @0x223934 mov r9, r2
 *   @0x223938 mov r7, r0
 *   @0x22393c ldr r3, [pc, r3]
 *   @0x223940 sub sp, sp, #12
 *   @0x223944 mla r2, r2, r6, r1
 *   @0x223948 ldr r3, [r3]
 *   @0x22394c mov r5, r1
 *   @0x223950 cmp r2, r3
 *   @0x223954 movge r0, #0
 *   @0x223958 bge 0x223a6c <_ZN10COggThread6CreateEiii+0x148>
 *   @0x22395c cmp r8, #2785280
 *   @0x223960 str r8, [r7, #0x808]
 *   @0x223964 addls r0, r8, r8, lsl #1
 *   @0x223968 mvnhi r0, #0
 *   @0x22396c lslls r0, r0, #8
 *   @0x223970 addls r0, r0, #8
 *   @0x223974 bl 0x27d14c <_Znaj>
 *   @0x223978 cmn r6, #1
 *   @0x22397c mov r3, #768
 *   @0x223980 add r10, r0, #8
 *   @0x223984 str r8, [r0, #0x4]
 *   @0x223988 str r3, [r0]
 *   @0x22398c movne r4, r10
 *   @0x223990 beq 0x2239ac <_ZN10COggThread6CreateEiii+0x88>
 *   @0x223994 mov r0, r4
 *   @0x223998 sub r6, r6, #1
 *   @0x22399c bl 0x2233f4 <_ZN11SOggChannelC2Ev>
 *   @0x2239a0 cmn r6, #1
 *   @0x2239a4 add r4, r4, #768
 *   @0x2239a8 bne 0x223994 <_ZN10COggThread6CreateEiii+0x70>
 *   @0x2239ac cmp r8, #0
 *   @0x2239b0 mov r4, #0
 *   @0x2239b4 mov r0, r10
 *   @0x2239b8 strb r4, [r7, #0x830]
 *   @0x2239bc str r5, [r7, #0x80c]
 *   @0x2239c0 str r10, [r7, #0x804]
 *   @0x2239c4 strb r4, [r7, #0x800]
 *   @0x2239c8 strb r4, [r7, #0x801]
 *   @0x2239cc strb r4, [r7, #0x831]
 *   @0x2239d0 ble 0x223a24 <_ZN10COggThread6CreateEiii+0x100>
 *   @0x2239d4 ldr r10, [pc, #0xb8]
 *   @0x2239d8 lsl r6, r5, #2
 *   @0x2239dc lsl r3, r9, #2
 *   @0x2239e0 str r3, [sp, #0x4]
 *   @0x2239e4 ldr r10, [pc, r10]
 *   @0x2239e8 add r11, r4, r4, lsl #1
 *   @0x2239ec ldr r2, [r10]
 *   @0x2239f0 add r4, r4, #1
 *   @0x2239f4 lsl r11, r11, #8
 *   @0x2239f8 add r0, r0, r11
 *   @0x2239fc ldr r1, [r2, r6]
 *   @0x223a00 bl 0x223474 <_ZN11SOggChannel4InitEj>
 *   @0x223a04 ldr r0, [r7, #0x804]
 *   @0x223a08 ldr r3, [sp, #0x4]
 *   @0x223a0c cmp r4, r8
 *   @0x223a10 add r11, r0, r11
 *   @0x223a14 add r6, r6, r3
 *   @0x223a18 str r5, [r11, #0x2b8]
 *   @0x223a1c add r5, r5, r9
 *   @0x223a20 bne 0x2239e8 <_ZN10COggThread6CreateEiii+0xc4>
 *   @0x223a24 cmp r8, #266338304
 *   @0x223a28 mvnhi r0, #0
 *   @0x223a2c bls 0x223a74 <_ZN10COggThread6CreateEiii+0x150>
 *   @0x223a30 bl 0x27d14c <_Znaj>
 *   @0x223a34 str r0, [r7, #0x810]
 *   @0x223a38 mov r0, #8
 *   @0x223a3c bl 0x27c524 <_Znwj>
 *   @0x223a40 ldr r1, [pc, #0x50]
 *   @0x223a44 add r1, pc, r1
 *   @0x223a48 mov r4, r0
 *   @0x223a4c bl 0x27e070 <_ZN5MutexC2EPKc>
 *   @0x223a50 str r4, [r7, #0x814]
 *   @0x223a54 mov r0, r7
 *   @0x223a58 bl 0x2237d4 <_ZN10COggThread11StartThreadEv>
 *   @0x223a5c subs r4, r0, #0
 *   @0x223a60 movne r0, #1
 *   @0x223a64 strbne r0, [r7, #0x802]
 *   @0x223a68 beq 0x223a7c <_ZN10COggThread6CreateEiii+0x158>
 *   @0x223a6c add sp, sp, #12
 *   @0x223a70 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x223a74 lsl r0, r8, #3
 *   @0x223a78 b 0x223a30 <_ZN10COggThread6CreateEiii+0x10c>
 *   @0x223a7c mov r0, r7
 *   @0x223a80 bl 0x223890 <_ZN10COggThread7CleanUpEv>
 *   @0x223a84 mov r0, r4
 *   @0x223a88 add sp, sp, #12
 *   @0x223a8c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x223a90 mulseq r12, r4, r10
 *   @0x223a94 andseq sp, r12, r8, ror #19
 *   @0x223a98 andseq r1, r3, r0, lsl #6
 *
 * ══ §31/81 oggpackB_write  0x233550  size 376  94 条（0x233550..0x2336c8）
 * @func 0x233550 0x2336c8  size 376  94 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: oggpackB_write+0xd4×4 / oggpackB_write+0x138 / 0xb6c28
 * 字段偏移 top8: 0xc×9 / 0x4×8 / 0x10×3 / 0x2×2 / 0x8×2 / 0x13c×1 / 0x1×1 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x233550 cmp r2, #32
 *   @0x233554 push {r4, r5, r6, lr}
 *   @0x233558 mov r4, r0
 *   @0x23355c sub sp, sp, #8
 *   @0x233560 mov r5, r1
 *   @0x233564 bhi 0x233678 <oggpackB_write+0x128>
 *   @0x233568 ldr r3, [r0, #0x10]
 *   @0x23356c ldr r0, [r0]
 *   @0x233570 sub r1, r3, #4
 *   @0x233574 cmp r0, r1
 *   @0x233578 bge 0x23365c <oggpackB_write+0x10c>
 *   @0x23357c ldr r3, [r4, #0xc]
 *   @0x233580 ldr r6, [pc, #0x13c]
 *   @0x233584 rsb r12, r2, #32
 *   @0x233588 ldr r1, [r4, #0x4]
 *   @0x23358c add r6, pc, r6
 *   @0x233590 ldrb r0, [r3]
 *   @0x233594 ldr r6, [r6, r2, lsl #2]
 *   @0x233598 add r2, r2, r1
 *   @0x23359c cmp r2, #7
 *   @0x2335a0 add r1, r1, #24
 *   @0x2335a4 and r5, r5, r6
 *   @0x2335a8 lsl r5, r5, r12
 *   @0x2335ac orr r1, r0, r5, lsr r1
 *   @0x2335b0 strb r1, [r3]
 *   @0x2335b4 ble 0x233624 <oggpackB_write+0xd4>
 *   @0x2335b8 ldr r1, [r4, #0x4]
 *   @0x2335bc cmp r2, #15
 *   @0x2335c0 ldr r3, [r4, #0xc]
 *   @0x2335c4 add r1, r1, #16
 *   @0x2335c8 lsr r1, r5, r1
 *   @0x2335cc strb r1, [r3, #0x1]
 *   @0x2335d0 ble 0x233624 <oggpackB_write+0xd4>
 *   @0x2335d4 ldr r1, [r4, #0x4]
 *   @0x2335d8 cmp r2, #23
 *   @0x2335dc ldr r3, [r4, #0xc]
 *   @0x2335e0 add r1, r1, #8
 *   @0x2335e4 lsr r1, r5, r1
 *   @0x2335e8 strb r1, [r3, #0x2]
 *   @0x2335ec ble 0x233624 <oggpackB_write+0xd4>
 *   @0x2335f0 ldr r3, [r4, #0xc]
 *   @0x2335f4 cmp r2, #31
 *   @0x2335f8 ldr r1, [r4, #0x4]
 *   @0x2335fc lsr r1, r5, r1
 *   @0x233600 strb r1, [r3, #0x3]
 *   @0x233604 ble 0x233624 <oggpackB_write+0xd4>
 *   @0x233608 ldr r3, [r4, #0x4]
 *   @0x23360c ldr r1, [r4, #0xc]
 *   @0x233610 cmp r3, #0
 *   @0x233614 rsbne r3, r3, #8
 *   @0x233618 lslne r5, r5, r3
 *   @0x23361c strbeq r3, [r1, #0x4]
 *   @0x233620 strbne r5, [r1, #0x4]
 *   @0x233624 cmp r2, #0
 *   @0x233628 add r3, r2, #7
 *   @0x23362c ldr r0, [r4]
 *   @0x233630 movge r3, r2
 *   @0x233634 ldr r1, [r4, #0xc]
 *   @0x233638 asr r3, r3, #3
 *   @0x23363c and r2, r2, #7
 *   @0x233640 str r2, [r4, #0x4]
 *   @0x233644 add r2, r0, r3
 *   @0x233648 add r3, r1, r3
 *   @0x23364c str r2, [r4]
 *   @0x233650 str r3, [r4, #0xc]
 *   @0x233654 add sp, sp, #8
 *   @0x233658 pop {r4, r5, r6, pc}
 *   @0x23365c ldr r1, [r4, #0xc]
 *   @0x233660 cmp r1, #0
 *   @0x233664 beq 0x233654 <oggpackB_write+0x104>
 *   @0x233668 movw r1, #0xfeff
 *   @0x23366c movt r1, #0x7fff
 *   @0x233670 cmp r3, r1
 *   @0x233674 ble 0x233688 <oggpackB_write+0x138>
 *   @0x233678 mov r0, r4
 *   @0x23367c add sp, sp, #8
 *   @0x233680 pop {r4, r5, r6, lr}
 *   @0x233684 b 0x23339c <oggpack_writeclear>
 *   @0x233688 ldr r0, [r4, #0x8]
 *   @0x23368c add r1, r3, #256
 *   @0x233690 str r2, [sp, #0x4]
 *   @0x233694 bl 0xb6c28 <realloc@plt>
 *   @0x233698 ldr r2, [sp, #0x4]
 *   @0x23369c cmp r0, #0
 *   @0x2336a0 beq 0x233678 <oggpackB_write+0x128>
 *   @0x2336a4 ldr r1, [r4, #0x10]
 *   @0x2336a8 ldr r3, [r4]
 *   @0x2336ac add r1, r1, #256
 *   @0x2336b0 str r0, [r4, #0x8]
 *   @0x2336b4 add r3, r0, r3
 *   @0x2336b8 str r1, [r4, #0x10]
 *   @0x2336bc str r3, [r4, #0xc]
 *   @0x2336c0 b 0x233580 <oggpackB_write+0x30>
 *   @0x2336c4 andseq r5, r3, r12, lsr #9
 *
 * ══ §32/81 Debug_SendYYDebug(DbgSocket*, Buffer_Standard*)  0x29fe4c  size 376  94 条（0x29fe4c..0x29ffc4）
 * @func 0x29fe4c 0x29ffc4  size 376  94 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IBuffer::Write(void const*, unsigned int, unsigned int)
 * 字段偏移 top8: 0x30×4 / 0x8×4 / 0x38×4 / 0x2c×3 / 0x10×2 / 0x48×2 / 0xc×2 / 0xf8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29fe4c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x29fe50 mov r6, r1
 *   @0x29fe54 add r8, r1, #44
 *   @0x29fe58 ldr r1, [r1]
 *   @0x29fe5c mov r4, #0
 *   @0x29fe60 mov r2, #465567744
 *   @0x29fe64 mov r9, r0
 *   @0x29fe68 str r2, [r6, #0x2c]
 *   @0x29fe6c movw r3, #0xc238
 *   @0x29fe70 mov r2, r8
 *   @0x29fe74 movt r3, #0x41e7
 *   @0x29fe78 mov r0, r6
 *   @0x29fe7c str r3, [r6, #0x30]
 *   @0x29fe80 ldr r3, [r1, #0x8]
 *   @0x29fe84 mov r1, #5
 *   @0x29fe88 str r4, [r6, #0x38]
 *   @0x29fe8c blx r3
 *   @0x29fe90 ldr r3, [r6]
 *   @0x29fe94 str r4, [r6, #0x2c]
 *   @0x29fe98 mov r1, #5
 *   @0x29fe9c str r4, [r6, #0x30]
 *   @0x29fea0 mov r2, r8
 *   @0x29fea4 ldr r3, [r3, #0x8]
 *   @0x29fea8 mov r0, r6
 *   @0x29feac str r4, [r6, #0x38]
 *   @0x29feb0 blx r3
 *   @0x29feb4 ldr r3, [pc, #0xf8]
 *   @0x29feb8 ldr r3, [pc, r3]
 *   @0x29febc ldr r1, [r3]
 *   @0x29fec0 cmp r1, r4
 *   @0x29fec4 beq 0x29fedc <_Z17Debug_SendYYDebugP9DbgSocketP15Buffer_Standard+0x90>
 *   @0x29fec8 ldr r3, [pc, #0xe8]
 *   @0x29fecc ldr r3, [pc, r3]
 *   @0x29fed0 ldr r3, [r3]
 *   @0x29fed4 cmp r3, r4
 *   @0x29fed8 bgt 0x29ffa4 <_Z17Debug_SendYYDebugP9DbgSocketP15Buffer_Standard+0x158>
 *   @0x29fedc ldr r12, [r6]
 *   @0x29fee0 mov r3, #0
 *   @0x29fee4 mov r0, r6
 *   @0x29fee8 str r3, [r6, #0x2c]
 *   @0x29feec str r3, [r6, #0x30]
 *   @0x29fef0 mov r1, #5
 *   @0x29fef4 str r3, [r6, #0x38]
 *   @0x29fef8 mov r2, r8
 *   @0x29fefc ldr r3, [r12, #0x8]
 *   @0x29ff00 blx r3
 *   @0x29ff04 ldr r3, [r6]
 *   @0x29ff08 mov r1, #0
 *   @0x29ff0c ldr r7, [r6, #0x1c]
 *   @0x29ff10 mov r0, r6
 *   @0x29ff14 mov r2, #4
 *   @0x29ff18 mov r10, r1
 *   @0x29ff1c ldr r3, [r3, #0x10]
 *   @0x29ff20 blx r3
 *   @0x29ff24 vmov s15, r7
 *   @0x29ff28 ldr r3, [r6]
 *   @0x29ff2c mov r2, r8
 *   @0x29ff30 vcvt.f64.u32 d7, s15
 *   @0x29ff34 str r10, [r6, #0x38]
 *   @0x29ff38 mov r0, r6
 *   @0x29ff3c mov r1, #5
 *   @0x29ff40 vmov r4, r5, d7
 *   @0x29ff44 vstr s14, [r6, #44]
 *   @0x29ff48 str r5, [r6, #0x30]
 *   @0x29ff4c ldr r3, [r3, #0x8]
 *   @0x29ff50 blx r3
 *   @0x29ff54 ldr r3, [r6]
 *   @0x29ff58 mov r1, r10
 *   @0x29ff5c mov r2, r7
 *   @0x29ff60 mov r0, r6
 *   @0x29ff64 ldr r3, [r3, #0x10]
 *   @0x29ff68 blx r3
 *   @0x29ff6c ldr r3, [pc, #0x48]
 *   @0x29ff70 ldr r1, [pc, #0x48]
 *   @0x29ff74 mov r2, r7
 *   @0x29ff78 ldr r3, [pc, r3]
 *   @0x29ff7c add r1, pc, r1
 *   @0x29ff80 ldr r0, [r3]
 *   @0x29ff84 ldr r3, [r0]
 *   @0x29ff88 ldr r3, [r3, #0xc]
 *   @0x29ff8c blx r3
 *   @0x29ff90 mov r0, r9
 *   @0x29ff94 mov r2, r7
 *   @0x29ff98 ldr r1, [r6, #0xc]
 *   @0x29ff9c pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x29ffa0 b 0x29d9a8 <_ZN9DbgSocket5WriteEPvj>
 *   @0x29ffa4 mov r0, r6
 *   @0x29ffa8 mov r2, #1
 *   @0x29ffac bl 0xcdabc <_ZN7IBuffer5WriteEPKvjj>
 *   @0x29ffb0 b 0x29ff04 <_Z17Debug_SendYYDebugP9DbgSocketP15Buffer_Standard+0xb8>
 *   @0x29ffb4 andseq r0, r5, r8, asr lr
 *   @0x29ffb8 andseq r0, r5, r8, asr #28
 *   @0x29ffbc mulseq r4, r12, r7
 *   @0x29ffc0 ldrdeq r9, r10, [r11], -r4
 *
 * ══ §33/81 png_write_row  0x2b0378  size 376  94 条（0x2b0378..0x2b04f0）
 * @func 0x2b0378 0x2b04f0  size 376  94 条
 * 部分覆盖: 本节 94/161 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_error / anon_2bc92c+0x220 / 0x43cb60 / anon_2fc4e8+0x570 / 0xb65bc / anon_2bc92c+0x28c / 0x12bd054 / png_write_row+0xd4
 * 字段偏移 top8: 0x150×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b0378 push {r3, r4, r5, lr}
 *   @0x2b037c mov r4, r0
 *   @0x2b0380 beq.w 0x2b04e8 <png_write_row+0x170>
 *   @0x2b0384 ldr.w r3, [r0, #0x1a8]
 *   @0x2b0388 cbnz r3, 0x2b03a6 <png_write_row+0x2e>
 *   @0x2b038c ldmdblt r3, {r3, r5, r6, r7, r8, r12, sp} ^
 *   @0x2b0390 ldr.w r3, [r0, #0x12c]
 *   @0x2b0394 lsls r2, r3, #0x15
 *   @0x2b0398 ldr r1, [pc, #0x150]
 *   @0x2b039c bl 0x2a642c <png_error>
 *   @0x2b03a0 mov r0, r4
 *   @0x2b03a4 .word 0xf894f8b5
 *   @0x2b03a8 blhs 0x2bcb4c <jpeg_alloc_huff_table+0x244>
 *   @0x2b03ac beq 0x2b0430 <png_write_row+0xb8>
 *   @0x2b03b0 .word 0x079b3134
 *   @0x2b03b4 bpl 0x2b0430 <png_write_row+0xb8>
 *   @0x2b03b8 blhs 0x43cb60 <g_RomDisk+0x45340>
 *   @0x2b03bc bhi 0x2b0430 <png_write_row+0xb8>
 *   @0x2b03c0 stceq p0, c15, [r4, #-12]
 *   @0x2b03c4 subs r5, r2, r4
 *   @0x2b03c8 movs r3, r6
 *   @0x2b03cc ldrbeq r3, [r8, -r8, lsr #3]
 *   @0x2b03d0 beq 0x2b0430 <png_write_row+0xb8>
 *   @0x2b03d4 pop.w {r3, r4, r5, lr}
 *   @0x2b03d8 b.w 0x2b260c <png_write_finish_row>
 *   @0x2b03dc ldr.w r3, [r4, #0x1a8]
 *   @0x2b03e0 lsls r1, r3, #0x1d
 *   @0x2b03e4 ldr.w r3, [r4, #0x18c]
 *   @0x2b03e8 cmp r3, #0x4
 *   @0x2b03ec ldr.w r3, [r4, #0x1a8]
 *   @0x2b03f0 and r3, r3, #0x7
 *   @0x2b03f4 cmp r3, #0x4
 *   @0x2b03f8 ldr.w r3, [r4, #0x1a8]
 *   @0x2b03fc lsls r2, r3, #0x1e
 *   @0x2b0400 ldr.w r3, [r4, #0x18c]
 *   @0x2b0404 cmp r3, #0x2
 *   @0x2b0408 ldr.w r3, [r4, #0x1a8]
 *   @0x2b040c and r3, r3, #0x3
 *   @0x2b0410 cmp r3, #0x2
 *   @0x2b0414 b 0x2b03d2 <png_write_row+0x5a>
 *   @0x2b0418 ldrbeq r3, [r11, r8, lsr #3]
 *   @0x2b041c bmi 0x2b03d2 <png_write_row+0x5a>
 *   @0x2b0420 blhs 0x2fca58 <ps_hints_apply+0xb658>
 *   @0x2b0424 bhi 0x2b0430 <png_write_row+0xb8>
 *   @0x2b0428 ldr.w r3, [r4, #0x1a8]
 *   @0x2b042c lsls r0, r3, #0x1f
 *   @0x2b0430 ldrb.w r3, [r4, #0x1ea]
 *   @0x2b0434 ldrb.w r0, [r4, #0x1ef]
 *   @0x2b0438 ldr.w r2, [r4, #0x198]
 *   @0x2b043c strb.w r3, [r4, #0x1cc]
 *   @0x2b0440 ldrb.w r3, [r4, #0x1ec]
 *   @0x2b0444 str.w r2, [r4, #0x1c4]
 *   @0x2b0448 strb.w r0, [r4, #0x1ce]
 *   @0x2b044c strb.w r3, [r4, #0x1cd]
 *   @0x2b0450 muls r3, r0, r3
 *   @0x2b0454 strb.w r3, [r4, #0x1cf]
 *   @0x2b0458 cmp r3, #0x7
 *   @0x2b045c lsrs r3, r3, #0x3
 *   @0x2b0460 b 0x2b0468 <png_write_row+0xf0>
 *   @0x2b0464 adds r2, #0x7
 *   @0x2b0468 ldr.w r0, [r4, #0x1b0]
 *   @0x2b046c mov r1, r5
 *   @0x2b0470 .word 0xf50421c8
 *   @0x2b0474 andlo r7, r1, r2, ror #11
 *   @0x2b0478 blx 0xb65bc <memcpy@plt>
 *   @0x2b047c ldrb.w r3, [r4, #0x1e7]
 *   @0x2b0480 cbz r3, 0x2b04a6 <png_write_row+0x12e>
 *   @0x2b0484 bhs 0x3f8c2c <g_RomDisk+0x140c>
 *   @0x2b0488 bhi 0x2b04a6 <png_write_row+0x12e>
 *   @0x2b048c .word 0x07993134
 *   @0x2b0490 bpl 0x2b04a6 <png_write_row+0x12e>
 *   @0x2b0494 .word 0x462811b0
 *   @0x2b0498 adds r1, #0x1
 *   @0x2b049c .word 0xf8d4f97f
 *   @0x2b04a0 blhs 0x2bcbb8 <jpeg_alloc_huff_table+0x2b0>
 *   @0x2b04a4 beq 0x2b03d2 <png_write_row+0x5a>
 *   @0x2b04a8 tstlt r3, r4, lsr r1
 *   @0x2b04ac mov r0, r4
 *   @0x2b04b0 .word 0xf8d4fc85
 *   @0x2b04b4 smmlseq r11, r12, r2, r3
 *   @0x2b04b8 bpl 0x2b04ce <png_write_row+0x156>
 *   @0x2b04bc blhs 0x12bd054 <b2_toiTime+0xb63bb0>
 *   @0x2b04c0 bne 0x2b04ce <png_write_row+0x156>
 *   @0x2b04c4 .word 0x462811b0
 *   @0x2b04c8 adds r1, #0x1
 *   @0x2b04cc qsub8mi pc, r0, r4
 *   @0x2b04d0 mov r1, r5
 *   @0x2b04d4 .word 0xf8d4fa81
 *   @0x2b04d8 .word 0xb12b3260
 *   @0x2b04dc mov r0, r4
 *   @0x2b04e0 .word 0xf89411a8
 *   @0x2b04e4 ldrmi r2, [r8, r8, ror #3]
 *   @0x2b04e8 pop {r3, r4, r5, pc}
 *   @0x2b04ec blt 0x2b044c <png_write_row+0xd4>
 *
 * ══ §34/81 anon_2be8b0  0x2be8b0  size 376  94 条（0x2be8b0..0x2bea28）
 * @func 0x2be8b0 0x2bea28  size 376  94 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: jpeg_make_d_derived_tbl×2 / anon_2be8b0+0xb0 / anon_2be8b0+0x144
 * 字段偏移 top8: 0x14×3 / 0x2×3 / 0x124×2 / 0x18×2 / 0x10×2 / 0x140×2 / 0x24×2 / 0x16c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2be8b0 ldr r3, [r0, #0x16c]
 *   @0x2be8b4 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2be8b8 cmp r3, #0
 *   @0x2be8bc mov r4, r0
 *   @0x2be8c0 ldr r5, [r0, #0x198]
 *   @0x2be8c4 bne 0x2be8d4 <jpeg_make_d_derived_tbl+0x3c4>
 *   @0x2be8c8 ldr r3, [r0, #0x170]
 *   @0x2be8cc cmp r3, #63
 *   @0x2be8d0 beq 0x2bea10 <jpeg_make_d_derived_tbl+0x500>
 *   @0x2be8d4 ldr r3, [r4]
 *   @0x2be8d8 mov r2, #122
 *   @0x2be8dc mov r0, r4
 *   @0x2be8e0 mvn r1, #0
 *   @0x2be8e4 str r2, [r3, #0x14]
 *   @0x2be8e8 ldr r3, [r3, #0x4]
 *   @0x2be8ec blx r3
 *   @0x2be8f0 ldr r3, [r4, #0x124]
 *   @0x2be8f4 cmp r3, #0
 *   @0x2be8f8 ble 0x2be960 <jpeg_make_d_derived_tbl+0x450>
 *   @0x2be8fc mov r6, #0
 *   @0x2be900 mov r8, r4
 *   @0x2be904 mov r10, r6
 *   @0x2be908 mov r7, r5
 *   @0x2be90c ldr r3, [r8, #0x128]
 *   @0x2be910 mov r1, #1
 *   @0x2be914 mov r0, r4
 *   @0x2be918 add r6, r6, r1
 *   @0x2be91c add r8, r8, #4
 *   @0x2be920 add r7, r7, #4
 *   @0x2be924 ldr r2, [r3, #0x14]
 *   @0x2be928 ldr r9, [r3, #0x18]
 *   @0x2be92c add r3, r2, #10
 *   @0x2be930 add r3, r5, r3, lsl #2
 *   @0x2be934 bl 0x2be510 <jpeg_make_d_derived_tbl>
 *   @0x2be938 add r3, r9, #14
 *   @0x2be93c mov r2, r9
 *   @0x2be940 mov r0, r4
 *   @0x2be944 add r3, r5, r3, lsl #2
 *   @0x2be948 mov r1, #0
 *   @0x2be94c bl 0x2be510 <jpeg_make_d_derived_tbl>
 *   @0x2be950 str r10, [r7, #0x10]
 *   @0x2be954 ldr r3, [r4, #0x124]
 *   @0x2be958 cmp r3, r6
 *   @0x2be95c bgt 0x2be90c <jpeg_make_d_derived_tbl+0x3fc>
 *   @0x2be960 ldr r3, [r4, #0x140]
 *   @0x2be964 cmp r3, #0
 *   @0x2be968 ble 0x2be9f4 <jpeg_make_d_derived_tbl+0x4e4>
 *   @0x2be96c mov r12, r4
 *   @0x2be970 mov r2, r5
 *   @0x2be974 mov r1, r5
 *   @0x2be978 mov r0, #0
 *   @0x2be97c mov r7, #1
 *   @0x2be980 ldr r3, [r12, #0x144]
 *   @0x2be984 add r3, r3, #74
 *   @0x2be988 ldr r3, [r4, r3, lsl #2]
 *   @0x2be98c ldr r6, [r3, #0x14]
 *   @0x2be990 add r6, r6, #10
 *   @0x2be994 ldr r6, [r5, r6, lsl #2]
 *   @0x2be998 str r6, [r2, #0x48]
 *   @0x2be99c ldr r6, [r3, #0x18]
 *   @0x2be9a0 add r6, r6, #14
 *   @0x2be9a4 ldr r6, [r5, r6, lsl #2]
 *   @0x2be9a8 str r6, [r2, #0x70]
 *   @0x2be9ac ldrb r6, [r3, #0x30]
 *   @0x2be9b0 cmp r6, #0
 *   @0x2be9b4 strbeq r6, [r1, #0xa2]
 *   @0x2be9b8 strbeq r6, [r1, #0x98]
 *   @0x2be9bc beq 0x2be9d8 <jpeg_make_d_derived_tbl+0x4c8>
 *   @0x2be9c0 strb r7, [r1, #0x98]
 *   @0x2be9c4 ldr r3, [r3, #0x24]
 *   @0x2be9c8 cmp r3, #1
 *   @0x2be9cc movle r3, #0
 *   @0x2be9d0 movgt r3, #1
 *   @0x2be9d4 strb r3, [r1, #0xa2]
 *   @0x2be9d8 ldr r3, [r4, #0x140]
 *   @0x2be9dc add r0, r0, #1
 *   @0x2be9e0 add r12, r12, #4
 *   @0x2be9e4 add r2, r2, #4
 *   @0x2be9e8 cmp r3, r0
 *   @0x2be9ec add r1, r1, #1
 *   @0x2be9f0 bgt 0x2be980 <jpeg_make_d_derived_tbl+0x470>
 *   @0x2be9f4 mov r3, #0
 *   @0x2be9f8 strb r3, [r5, #0x8]
 *   @0x2be9fc ldr r2, [r4, #0xfc]
 *   @0x2bea00 str r3, [r5, #0x10]
 *   @0x2bea04 str r3, [r5, #0xc]
 *   @0x2bea08 str r2, [r5, #0x24]
 *   @0x2bea0c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2bea10 ldr r3, [r0, #0x174]
 *   @0x2bea14 cmp r3, #0
 *   @0x2bea18 bne 0x2be8d4 <jpeg_make_d_derived_tbl+0x3c4>
 *   @0x2bea1c ldr r3, [r0, #0x178]
 *   @0x2bea20 cmp r3, #0
 *   @0x2bea24 beq 0x2be8f0 <jpeg_make_d_derived_tbl+0x3e0>
 *
 * ══ §35/81 b2PulleyJoint::Dump()  0x2d0734  size 376  94 条（0x2d0734..0x2d08ac）
 * @func 0x2d0734 0x2d08ac  size 376  94 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Log(char const*, ...)×11
 * 字段偏移 top8: 0x8×2 / 0x30×1 / 0x34×1 / 0x12c×1 / 0x11c×1 / 0x110×1 / 0x104×1 / 0x3d×1
 * VFP 指令 33 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d0734 push {r4, r5, r6, lr}
 *   @0x2d0738 mov r4, r0
 *   @0x2d073c ldr r2, [r4, #0x30]
 *   @0x2d0740 sub sp, sp, #8
 *   @0x2d0744 ldr r3, [r4, #0x34]
 *   @0x2d0748 ldr r0, [pc, #0x12c]
 *   @0x2d074c ldr r6, [r2, #0x8]
 *   @0x2d0750 add r0, pc, r0
 *   @0x2d0754 ldr r5, [r3, #0x8]
 *   @0x2d0758 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d075c ldr r0, [pc, #0x11c]
 *   @0x2d0760 mov r1, r6
 *   @0x2d0764 add r0, pc, r0
 *   @0x2d0768 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d076c ldr r0, [pc, #0x110]
 *   @0x2d0770 mov r1, r5
 *   @0x2d0774 add r0, pc, r0
 *   @0x2d0778 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d077c ldr r0, [pc, #0x104]
 *   @0x2d0780 ldrb r1, [r4, #0x3d]
 *   @0x2d0784 add r0, pc, r0
 *   @0x2d0788 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d078c vldr s13, [r4, #68]
 *   @0x2d0790 vldr s14, [r4, #72]
 *   @0x2d0794 vcvt.f64.f32 d5, s13
 *   @0x2d0798 ldr r0, [pc, #0xec]
 *   @0x2d079c add r0, pc, r0
 *   @0x2d07a0 vcvt.f64.f32 d7, s14
 *   @0x2d07a4 vmov r2, r3, d5
 *   @0x2d07a8 vstr d7, [sp]
 *   @0x2d07ac bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d07b0 vldr s13, [r4, #76]
 *   @0x2d07b4 vldr s14, [r4, #80]
 *   @0x2d07b8 vcvt.f64.f32 d5, s13
 *   @0x2d07bc ldr r0, [pc, #0xcc]
 *   @0x2d07c0 add r0, pc, r0
 *   @0x2d07c4 vcvt.f64.f32 d7, s14
 *   @0x2d07c8 vmov r2, r3, d5
 *   @0x2d07cc vstr d7, [sp]
 *   @0x2d07d0 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d07d4 vldr s13, [r4, #92]
 *   @0x2d07d8 vldr s14, [r4, #96]
 *   @0x2d07dc vcvt.f64.f32 d5, s13
 *   @0x2d07e0 ldr r0, [pc, #0xac]
 *   @0x2d07e4 add r0, pc, r0
 *   @0x2d07e8 vcvt.f64.f32 d7, s14
 *   @0x2d07ec vmov r2, r3, d5
 *   @0x2d07f0 vstr d7, [sp]
 *   @0x2d07f4 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d07f8 vldr s13, [r4, #100]
 *   @0x2d07fc vldr s14, [r4, #104]
 *   @0x2d0800 vcvt.f64.f32 d5, s13
 *   @0x2d0804 ldr r0, [pc, #0x8c]
 *   @0x2d0808 add r0, pc, r0
 *   @0x2d080c vcvt.f64.f32 d7, s14
 *   @0x2d0810 vmov r2, r3, d5
 *   @0x2d0814 vstr d7, [sp]
 *   @0x2d0818 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d081c vldr s15, [r4, #84]
 *   @0x2d0820 vcvt.f64.f32 d6, s15
 *   @0x2d0824 ldr r0, [pc, #0x70]
 *   @0x2d0828 add r0, pc, r0
 *   @0x2d082c vmov r2, r3, d6
 *   @0x2d0830 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d0834 vldr s15, [r4, #88]
 *   @0x2d0838 vcvt.f64.f32 d5, s15
 *   @0x2d083c ldr r0, [pc, #0x5c]
 *   @0x2d0840 add r0, pc, r0
 *   @0x2d0844 vmov r2, r3, d5
 *   @0x2d0848 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d084c vldr s15, [r4, #112]
 *   @0x2d0850 vcvt.f64.f32 d6, s15
 *   @0x2d0854 ldr r0, [pc, #0x48]
 *   @0x2d0858 add r0, pc, r0
 *   @0x2d085c vmov r2, r3, d6
 *   @0x2d0860 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d0864 ldr r0, [pc, #0x3c]
 *   @0x2d0868 ldr r1, [r4, #0x38]
 *   @0x2d086c add r0, pc, r0
 *   @0x2d0870 add sp, sp, #8
 *   @0x2d0874 pop {r4, r5, r6, lr}
 *   @0x2d0878 b 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2d087c andeq r11, r8, r0, asr #21
 *   @0x2d0880 andeq r11, r8, r8, asr #14
 *   @0x2d0884 andeq r11, r8, r4, asr r7
 *   @0x2d0888 andeq r11, r8, r0, ror #14
 *   @0x2d088c andeq r11, r8, r12, lsl #21
 *   @0x2d0890 muleq r8, r4, r10
 *   @0x2d0894 andeq r11, r8, r4, lsr #14
 *   @0x2d0898 andeq r11, r8, r12, lsr #14
 *   @0x2d089c andeq r11, r8, r8, asr r10
 *   @0x2d08a0 andeq r11, r8, r12, asr r10
 *   @0x2d08a4 andeq r11, r8, r0, ror #20
 *   @0x2d08a8 andeq r11, r8, r12, asr #14
 *
 * ══ §36/81 F_DrawBackgroundStretchedExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x11e5a4  size 372  93 条（0x11e5a4..0x11e718）
 * @func 0x11e5a4 0x11e718  size 372  93 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×10 / YYGetInt32(RValue const*, int)×4 / Sprite_Data(int) / CSprite::DrawStretched(int, float, float, float, float, unsigned int, float) / Background_Data(int) / CBackground::DrawStretched(float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0x4×2 / 0x8×2 / 0x164×1 / 0x30×1 / 0xc×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11e5a4 ldr r3, [pc, #0x164]
 *   @0x11e5a8 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x11e5ac ldr r3, [pc, r3]
 *   @0x11e5b0 sub sp, sp, #16
 *   @0x11e5b4 ldrb r1, [r3]
 *   @0x11e5b8 ldr r4, [sp, #0x30]
 *   @0x11e5bc cmp r1, #0
 *   @0x11e5c0 mov r0, r4
 *   @0x11e5c4 beq 0x11e664 <_Z28F_DrawBackgroundStretchedExtR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x11e5c8 mov r1, #0
 *   @0x11e5cc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11e5d0 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x11e5d4 subs r5, r0, #0
 *   @0x11e5d8 beq 0x11e6f8 <_Z28F_DrawBackgroundStretchedExtR6RValueP9CInstanceS2_iPS_+0x154>
 *   @0x11e5dc mov r0, r4
 *   @0x11e5e0 mov r1, #1
 *   @0x11e5e4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e5e8 mov r1, #2
 *   @0x11e5ec mov r7, r0
 *   @0x11e5f0 mov r0, r4
 *   @0x11e5f4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e5f8 mov r1, #3
 *   @0x11e5fc mov r6, r0
 *   @0x11e600 mov r0, r4
 *   @0x11e604 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e608 mov r1, #4
 *   @0x11e60c mov r10, r0
 *   @0x11e610 mov r0, r4
 *   @0x11e614 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e618 mov r1, #5
 *   @0x11e61c mov r9, r0
 *   @0x11e620 mov r0, r4
 *   @0x11e624 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11e628 mov r1, #6
 *   @0x11e62c mov r8, r0
 *   @0x11e630 mov r0, r4
 *   @0x11e634 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e638 str r10, [sp]
 *   @0x11e63c str r9, [sp, #0x4]
 *   @0x11e640 mov r2, r7
 *   @0x11e644 str r8, [sp, #0x8]
 *   @0x11e648 mov r1, #0
 *   @0x11e64c mov r3, r6
 *   @0x11e650 str r0, [sp, #0xc]
 *   @0x11e654 mov r0, r5
 *   @0x11e658 bl 0x1ecdc4 <_ZN7CSprite13DrawStretchedEiffffjf>
 *   @0x11e65c add sp, sp, #16
 *   @0x11e660 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x11e664 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11e668 bl 0xc3794 <_Z15Background_Datai>
 *   @0x11e66c subs r5, r0, #0
 *   @0x11e670 beq 0x11e6f8 <_Z28F_DrawBackgroundStretchedExtR6RValueP9CInstanceS2_iPS_+0x154>
 *   @0x11e674 mov r0, r4
 *   @0x11e678 mov r1, #1
 *   @0x11e67c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e680 mov r1, #2
 *   @0x11e684 mov r8, r0
 *   @0x11e688 mov r0, r4
 *   @0x11e68c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e690 mov r1, #3
 *   @0x11e694 mov r7, r0
 *   @0x11e698 mov r0, r4
 *   @0x11e69c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e6a0 mov r1, #4
 *   @0x11e6a4 mov r6, r0
 *   @0x11e6a8 mov r0, r4
 *   @0x11e6ac bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e6b0 mov r1, #5
 *   @0x11e6b4 mov r10, r0
 *   @0x11e6b8 mov r0, r4
 *   @0x11e6bc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11e6c0 mov r1, #6
 *   @0x11e6c4 mov r9, r0
 *   @0x11e6c8 mov r0, r4
 *   @0x11e6cc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11e6d0 str r10, [sp]
 *   @0x11e6d4 str r9, [sp, #0x4]
 *   @0x11e6d8 mov r1, r8
 *   @0x11e6dc mov r2, r7
 *   @0x11e6e0 mov r3, r6
 *   @0x11e6e4 str r0, [sp, #0x8]
 *   @0x11e6e8 mov r0, r5
 *   @0x11e6ec bl 0xc2094 <_ZN11CBackground13DrawStretchedEffffjf>
 *   @0x11e6f0 add sp, sp, #16
 *   @0x11e6f4 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x11e6f8 ldr r0, [pc, #0x14]
 *   @0x11e6fc mov r1, #0
 *   @0x11e700 add r0, pc, r0
 *   @0x11e704 add sp, sp, #16
 *   @0x11e708 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x11e70c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11e710 eoreq pc, r12, r8, ror r3
 *   @0x11e714 .word 0x0021bad4
 *
 * ══ §37/81 F_DrawSpritePartExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x1229d0  size 372  93 条（0x1229d0..0x122b44）
 * @func 0x1229d0 0x122b44  size 372  93 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×9 / Error_Show_Action(char const*, bool)×2 / GetSpriteIndices(CInstance*, RValue*, int&, int&) / Sprite_Data(int) / YYGetInt32(RValue const*, int) / CSprite::DrawPart(int, float, float, float, float, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0x20×3 / 0x24×2 / 0x28×2 / 0x2c×2 / 0x10×2 / 0x60×1 / 0x30×1 / 0x74×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1229d0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1229d4 sub sp, sp, #60
 *   @0x1229d8 mov r0, r1
 *   @0x1229dc add r2, sp, #48
 *   @0x1229e0 ldr r4, [sp, #0x60]
 *   @0x1229e4 add r3, sp, #52
 *   @0x1229e8 mov r1, r4
 *   @0x1229ec bl 0x1226c4 <_Z16GetSpriteIndicesP9CInstanceP6RValueRiS3_>
 *   @0x1229f0 cmp r0, #0
 *   @0x1229f4 bne 0x122a00 <_Z19F_DrawSpritePartExtR6RValueP9CInstanceS2_iPS_+0x30>
 *   @0x1229f8 add sp, sp, #60
 *   @0x1229fc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x122a00 ldr r0, [sp, #0x30]
 *   @0x122a04 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x122a08 ldr r3, [r0, #0x74]
 *   @0x122a0c mov r5, r0
 *   @0x122a10 cmp r3, #1
 *   @0x122a14 beq 0x122b28 <_Z19F_DrawSpritePartExtR6RValueP9CInstanceS2_iPS_+0x158>
 *   @0x122a18 cmp r3, #2
 *   @0x122a1c beq 0x122b14 <_Z19F_DrawSpritePartExtR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x122a20 mov r0, r4
 *   @0x122a24 mov r1, #2
 *   @0x122a28 ldr r7, [sp, #0x34]
 *   @0x122a2c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122a30 mov r1, #3
 *   @0x122a34 mov r6, r0
 *   @0x122a38 mov r0, r4
 *   @0x122a3c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122a40 mov r1, #4
 *   @0x122a44 mov r3, r0
 *   @0x122a48 mov r0, r4
 *   @0x122a4c str r3, [sp, #0x20]
 *   @0x122a50 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122a54 mov r1, #5
 *   @0x122a58 mov r12, r0
 *   @0x122a5c mov r0, r4
 *   @0x122a60 str r12, [sp, #0x24]
 *   @0x122a64 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122a68 mov r1, #6
 *   @0x122a6c mov r2, r0
 *   @0x122a70 mov r0, r4
 *   @0x122a74 str r2, [sp, #0x28]
 *   @0x122a78 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122a7c mov r1, #7
 *   @0x122a80 str r0, [sp, #0x2c]
 *   @0x122a84 mov r0, r4
 *   @0x122a88 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122a8c mov r1, #8
 *   @0x122a90 mov r11, r0
 *   @0x122a94 mov r0, r4
 *   @0x122a98 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122a9c mov r1, #9
 *   @0x122aa0 mov r10, r0
 *   @0x122aa4 mov r0, r4
 *   @0x122aa8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122aac mov r1, #10
 *   @0x122ab0 mov r9, r0
 *   @0x122ab4 mov r0, r4
 *   @0x122ab8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x122abc mov r1, #11
 *   @0x122ac0 mov r8, r0
 *   @0x122ac4 mov r0, r4
 *   @0x122ac8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122acc ldr r2, [sp, #0x28]
 *   @0x122ad0 ldr r12, [sp, #0x24]
 *   @0x122ad4 mov r1, r7
 *   @0x122ad8 str r11, [sp, #0xc]
 *   @0x122adc str r2, [sp, #0x4]
 *   @0x122ae0 ldr r2, [sp, #0x2c]
 *   @0x122ae4 str r12, [sp]
 *   @0x122ae8 str r10, [sp, #0x10]
 *   @0x122aec str r2, [sp, #0x8]
 *   @0x122af0 mov r2, r6
 *   @0x122af4 str r9, [sp, #0x14]
 *   @0x122af8 str r8, [sp, #0x18]
 *   @0x122afc ldr r3, [sp, #0x20]
 *   @0x122b00 str r0, [sp, #0x1c]
 *   @0x122b04 mov r0, r5
 *   @0x122b08 bl 0x1e5e34 <_ZN7CSprite8DrawPartEiffffffffjf>
 *   @0x122b0c add sp, sp, #60
 *   @0x122b10 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x122b14 ldr r0, [pc, #0x20]
 *   @0x122b18 mov r1, #0
 *   @0x122b1c add r0, pc, r0
 *   @0x122b20 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x122b24 b 0x1229f8 <_Z19F_DrawSpritePartExtR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x122b28 ldr r0, [pc, #0x10]
 *   @0x122b2c mov r1, #0
 *   @0x122b30 add r0, pc, r0
 *   @0x122b34 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x122b38 b 0x1229f8 <_Z19F_DrawSpritePartExtR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x122b3c eoreq r7, r1, r0, lsl r10
 *   @0x122b40 eoreq r7, r1, r4, asr #19
 *
 * ══ §38/81 F_BackgroundCreateFromScreen(RValue&, CInstance*, CInstance*, int, RValue*)  0x12c3f0  size 372  93 条（0x12c3f0..0x12c564）
 * @func 0x12c3f0 0x12c564  size 372  93 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×9 / CBackground::CreateFromBitmap(IBitmap*, bool, bool, bool, bool)×2 / Background_AddEmpty() / Background_Data(int) / GR_D3D_Screenshot_Part(int, int, int, int)
 * 字段偏移 top8: 0x4×3 / 0xc×1 / 0x28×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12c3f0 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x12c3f4 sub sp, sp, #8
 *   @0x12c3f8 mov r6, #0
 *   @0x12c3fc str r6, [r0, #0xc]
 *   @0x12c400 ldr r4, [sp, #0x28]
 *   @0x12c404 mov r5, r0
 *   @0x12c408 mov r7, r3
 *   @0x12c40c bl 0xc41f0 <_Z19Background_AddEmptyv>
 *   @0x12c410 mov r9, r0
 *   @0x12c414 bl 0xc3794 <_Z15Background_Datai>
 *   @0x12c418 vmov s15, r9
 *   @0x12c41c mov r1, r6
 *   @0x12c420 vcvt.f64.s32 d7, s15
 *   @0x12c424 vmov r2, r3, d7
 *   @0x12c428 stm r5, {r2, r3}
 *   @0x12c42c mov r8, r0
 *   @0x12c430 mov r0, r4
 *   @0x12c434 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c438 mov r1, #1
 *   @0x12c43c mov r10, r0
 *   @0x12c440 mov r0, r4
 *   @0x12c444 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c448 mov r1, #2
 *   @0x12c44c mov r9, r0
 *   @0x12c450 mov r0, r4
 *   @0x12c454 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c458 mov r1, #3
 *   @0x12c45c mov r5, r0
 *   @0x12c460 mov r0, r4
 *   @0x12c464 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c468 mov r2, r5
 *   @0x12c46c mov r1, r9
 *   @0x12c470 mov r3, r0
 *   @0x12c474 mov r0, r10
 *   @0x12c478 bl 0x169b34 <_Z22GR_D3D_Screenshot_Partiiii>
 *   @0x12c47c subs r5, r0, #0
 *   @0x12c480 beq 0x12c4a4 <_Z28F_BackgroundCreateFromScreenR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x12c484 cmp r7, #6
 *   @0x12c488 beq 0x12c4ac <_Z28F_BackgroundCreateFromScreenR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x12c48c cmp r7, #7
 *   @0x12c490 beq 0x12c4fc <_Z28F_BackgroundCreateFromScreenR6RValueP9CInstanceS2_iPS_+0x10c>
 *   @0x12c494 ldr r3, [r5]
 *   @0x12c498 mov r0, r5
 *   @0x12c49c ldr r3, [r3, #0x4]
 *   @0x12c4a0 blx r3
 *   @0x12c4a4 add sp, sp, #8
 *   @0x12c4a8 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x12c4ac mov r0, r4
 *   @0x12c4b0 mov r1, #4
 *   @0x12c4b4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c4b8 mov r1, #5
 *   @0x12c4bc cmp r0, r6
 *   @0x12c4c0 mov r0, r4
 *   @0x12c4c4 movle r7, #0
 *   @0x12c4c8 movgt r7, #1
 *   @0x12c4cc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c4d0 eor r3, r7, #1
 *   @0x12c4d4 str r6, [sp]
 *   @0x12c4d8 mov r2, r7
 *   @0x12c4dc str r3, [sp, #0x4]
 *   @0x12c4e0 mov r1, r5
 *   @0x12c4e4 cmp r0, r6
 *   @0x12c4e8 mov r0, r8
 *   @0x12c4ec movle r3, #0
 *   @0x12c4f0 movgt r3, #1
 *   @0x12c4f4 bl 0xc244c <_ZN11CBackground16CreateFromBitmapEP7IBitmapbbbb>
 *   @0x12c4f8 b 0x12c494 <_Z28F_BackgroundCreateFromScreenR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x12c4fc mov r0, r4
 *   @0x12c500 mov r1, #4
 *   @0x12c504 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c508 mov r1, #5
 *   @0x12c50c mov r9, r0
 *   @0x12c510 mov r0, r4
 *   @0x12c514 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c518 mov r1, #6
 *   @0x12c51c mov r7, r0
 *   @0x12c520 mov r0, r4
 *   @0x12c524 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c528 cmp r9, #0
 *   @0x12c52c str r6, [sp, #0x4]
 *   @0x12c530 mov r1, r5
 *   @0x12c534 movle r2, #0
 *   @0x12c538 movgt r2, #1
 *   @0x12c53c cmp r7, #0
 *   @0x12c540 movle r3, #0
 *   @0x12c544 movgt r3, #1
 *   @0x12c548 cmp r0, #0
 *   @0x12c54c mov r0, r8
 *   @0x12c550 movle r12, #0
 *   @0x12c554 movgt r12, #1
 *   @0x12c558 str r12, [sp]
 *   @0x12c55c bl 0xc244c <_ZN11CBackground16CreateFromBitmapEP7IBitmapbbbb>
 *   @0x12c560 b 0x12c494 <_Z28F_BackgroundCreateFromScreenR6RValueP9CInstanceS2_iPS_+0xa4>
 *
 * ══ §39/81 json_parse_to_map(json_object*, CDS_Map*)  0x13cf68  size 372  93 条（0x13cf68..0x13d0dc）
 * @func 0x13cf68 0x13d0dc  size 372  93 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FREE_RValue__Pre(RValue*)×2 / json_object_get_object / json_object_get_type / YYSetString(RValue*, char const*) / json_parse_array(json_object*, char*) / CDS_Map::Add(RValue*, RValue*) / json_value(json_object*, RValue*) / json_object_object_get
 * 字段偏移 top8: 0x24×6 / 0x4×3 / 0x8×3 / 0x14×3 / 0x20×2 / 0x10×2 / 0xc×1 / 0x1c×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13cf68 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x13cf6c sub sp, sp, #44
 *   @0x13cf70 mov r9, r1
 *   @0x13cf74 str r0, [sp, #0x4]
 *   @0x13cf78 bl 0x27e8f4 <json_object_get_object>
 *   @0x13cf7c ldr r5, [r0, #0x20]
 *   @0x13cf80 cmp r5, #0
 *   @0x13cf84 beq 0x13d080 <_Z17json_parse_to_mapP11json_objectP7CDS_Map+0x118>
 *   @0x13cf88 add r8, sp, #24
 *   @0x13cf8c mov r4, #0
 *   @0x13cf90 ldm r5, {r7, r11}
 *   @0x13cf94 cmp r11, #0
 *   @0x13cf98 beq 0x13d074 <_Z17json_parse_to_mapP11json_objectP7CDS_Map+0x10c>
 *   @0x13cf9c mov r0, r11
 *   @0x13cfa0 add r6, sp, #8
 *   @0x13cfa4 bl 0x27e828 <json_object_get_type>
 *   @0x13cfa8 mov r1, r7
 *   @0x13cfac str r4, [sp, #0x8]
 *   @0x13cfb0 str r4, [sp, #0xc]
 *   @0x13cfb4 str r4, [sp, #0x10]
 *   @0x13cfb8 str r4, [sp, #0x14]
 *   @0x13cfbc str r4, [r8]
 *   @0x13cfc0 str r4, [sp, #0x1c]
 *   @0x13cfc4 str r4, [sp, #0x20]
 *   @0x13cfc8 str r4, [sp, #0x24]
 *   @0x13cfcc mov r10, r0
 *   @0x13cfd0 mov r0, r6
 *   @0x13cfd4 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x13cfd8 sub r0, r10, #1
 *   @0x13cfdc cmp r0, #5
 *   @0x13cfe0 addls pc, pc, r0, lsl #2
 *   @0x13cfe4 b 0x13d024 <_Z17json_parse_to_mapP11json_objectP7CDS_Map+0xbc>
 *   @0x13cfe8 b 0x13d088 <_Z17json_parse_to_mapP11json_objectP7CDS_Map+0x120>
 *   @0x13cfec b 0x13d088 <_Z17json_parse_to_mapP11json_objectP7CDS_Map+0x120>
 *   @0x13cff0 b 0x13d088 <_Z17json_parse_to_mapP11json_objectP7CDS_Map+0x120>
 *   @0x13cff4 b 0x13d098 <_Z17json_parse_to_mapP11json_objectP7CDS_Map+0x130>
 *   @0x13cff8 b 0x13d000 <_Z17json_parse_to_mapP11json_objectP7CDS_Map+0x98>
 *   @0x13cffc b 0x13d088 <_Z17json_parse_to_mapP11json_objectP7CDS_Map+0x120>
 *   @0x13d000 mov r1, r7
 *   @0x13d004 ldr r0, [sp, #0x4]
 *   @0x13d008 bl 0x13d274 <_Z16json_parse_arrayP11json_objectPc>
 *   @0x13d00c ldr r3, [sp, #0x24]
 *   @0x13d010 orr r3, r3, #1073741824
 *   @0x13d014 str r3, [sp, #0x24]
 *   @0x13d018 vmov s13, r0
 *   @0x13d01c vcvt.f64.s32 d7, s13
 *   @0x13d020 vstr d7, [sp, #24]
 *   @0x13d024 mov r0, r9
 *   @0x13d028 mov r1, r6
 *   @0x13d02c mov r2, r8
 *   @0x13d030 bl 0x20b884 <_ZN7CDS_Map3AddEP6RValueS1_>
 *   @0x13d034 ldr r3, [sp, #0x14]
 *   @0x13d038 sub r3, r3, #1
 *   @0x13d03c bic r3, r3, #-16777216
 *   @0x13d040 bic r3, r3, #3
 *   @0x13d044 cmp r3, #0
 *   @0x13d048 beq 0x13d0d0 <_Z17json_parse_to_mapP11json_objectP7CDS_Map+0x168>
 *   @0x13d04c ldr r3, [sp, #0x24]
 *   @0x13d050 mov r2, #5
 *   @0x13d054 str r4, [sp, #0x10]
 *   @0x13d058 sub r3, r3, #1
 *   @0x13d05c str r2, [sp, #0x14]
 *   @0x13d060 bic r3, r3, #-16777216
 *   @0x13d064 str r4, [sp, #0x8]
 *   @0x13d068 bic r3, r3, #3
 *   @0x13d06c cmp r3, #0
 *   @0x13d070 beq 0x13d0c4 <_Z17json_parse_to_mapP11json_objectP7CDS_Map+0x15c>
 *   @0x13d074 ldr r5, [r5, #0x8]
 *   @0x13d078 cmp r5, #0
 *   @0x13d07c bne 0x13cf90 <_Z17json_parse_to_mapP11json_objectP7CDS_Map+0x28>
 *   @0x13d080 add sp, sp, #44
 *   @0x13d084 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x13d088 mov r0, r11
 *   @0x13d08c mov r1, r8
 *   @0x13d090 bl 0x13c274 <_Z10json_valueP11json_objectP6RValue>
 *   @0x13d094 b 0x13d024 <_Z17json_parse_to_mapP11json_objectP7CDS_Map+0xbc>
 *   @0x13d098 mov r1, r7
 *   @0x13d09c ldr r0, [sp, #0x4]
 *   @0x13d0a0 bl 0x27ea38 <json_object_object_get>
 *   @0x13d0a4 bl 0x13d0dc <_Z10json_parseP11json_object>
 *   @0x13d0a8 ldr r3, [sp, #0x24]
 *   @0x13d0ac orr r3, r3, #-2147483648
 *   @0x13d0b0 str r3, [sp, #0x24]
 *   @0x13d0b4 vmov s13, r0
 *   @0x13d0b8 vcvt.f64.s32 d7, s13
 *   @0x13d0bc vstr d7, [sp, #24]
 *   @0x13d0c0 b 0x13d024 <_Z17json_parse_to_mapP11json_objectP7CDS_Map+0xbc>
 *   @0x13d0c4 mov r0, r8
 *   @0x13d0c8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x13d0cc b 0x13d074 <_Z17json_parse_to_mapP11json_objectP7CDS_Map+0x10c>
 *   @0x13d0d0 mov r0, r6
 *   @0x13d0d4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x13d0d8 b 0x13d04c <_Z17json_parse_to_mapP11json_objectP7CDS_Map+0xe4>
 *
 * ══ §40/81 F_GPUSetColourWriteEnable(RValue&, CInstance*, CInstance*, int, RValue*)  0x149440  size 372  93 条（0x149440..0x1495b4）
 * @func 0x149440 0x1495b4  size 372  93 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×8
 * 字段偏移 top8: 0x4×8 / 0xc×2 / 0x18×1 / 0x118×1 / 0x108×1 / 0x8c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x149440 cmp r3, #1
 *   @0x149444 cmpne r3, #4
 *   @0x149448 mov r2, #0
 *   @0x14944c push {r3, r4, r5, r6, r7, lr}
 *   @0x149450 mov r1, r2
 *   @0x149454 moveq r12, #0
 *   @0x149458 movne r12, #1
 *   @0x14945c movt r2, #0xbff0
 *   @0x149460 str r1, [r0, #0xc]
 *   @0x149464 stm r0, {r1, r2}
 *   @0x149468 ldr r4, [sp, #0x18]
 *   @0x14946c bne 0x14949c <_Z25F_GPUSetColourWriteEnableR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x149470 cmp r3, #4
 *   @0x149474 beq 0x149564 <_Z25F_GPUSetColourWriteEnableR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x149478 ldr r5, [r4, #0xc]
 *   @0x14947c bic r5, r5, #-16777216
 *   @0x149480 cmp r5, #2
 *   @0x149484 beq 0x1494ac <_Z25F_GPUSetColourWriteEnableR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x149488 ldr r0, [pc, #0x118]
 *   @0x14948c mov r1, #0
 *   @0x149490 pop {r3, r4, r5, r6, r7, lr}
 *   @0x149494 add r0, pc, r0
 *   @0x149498 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14949c ldr r0, [pc, #0x108]
 *   @0x1494a0 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1494a4 add r0, pc, r0
 *   @0x1494a8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1494ac ldr r3, [r4]
 *   @0x1494b0 ldr r3, [r3, #0x4]
 *   @0x1494b4 ldr r2, [r3]
 *   @0x1494b8 cmp r2, #4
 *   @0x1494bc bne 0x149488 <_Z25F_GPUSetColourWriteEnableR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x1494c0 mov r1, r12
 *   @0x1494c4 ldr r0, [r3, #0x4]
 *   @0x1494c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1494cc ldr r3, [r4]
 *   @0x1494d0 mov r1, #1
 *   @0x1494d4 ldr r3, [r3, #0x4]
 *   @0x1494d8 mov r7, r0
 *   @0x1494dc ldr r0, [r3, #0x4]
 *   @0x1494e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1494e4 ldr r3, [r4]
 *   @0x1494e8 mov r1, r5
 *   @0x1494ec ldr r3, [r3, #0x4]
 *   @0x1494f0 mov r6, r0
 *   @0x1494f4 ldr r0, [r3, #0x4]
 *   @0x1494f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1494fc ldr r3, [r4]
 *   @0x149500 mov r1, #3
 *   @0x149504 ldr r3, [r3, #0x4]
 *   @0x149508 mov r5, r0
 *   @0x14950c ldr r0, [r3, #0x4]
 *   @0x149510 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x149514 mov r3, r0
 *   @0x149518 cmp r6, #0
 *   @0x14951c ldr r0, [pc, #0x8c]
 *   @0x149520 movne r12, #2
 *   @0x149524 moveq r12, #0
 *   @0x149528 cmp r5, #0
 *   @0x14952c ldr r0, [pc, r0]
 *   @0x149530 movne r1, #4
 *   @0x149534 moveq r1, #0
 *   @0x149538 cmp r7, #0
 *   @0x14953c moveq r2, r12
 *   @0x149540 orrne r2, r12, #1
 *   @0x149544 cmp r3, #0
 *   @0x149548 orr r2, r2, r1
 *   @0x14954c mov r1, #24
 *   @0x149550 movne r3, #8
 *   @0x149554 moveq r3, #0
 *   @0x149558 orr r2, r2, r3
 *   @0x14955c pop {r3, r4, r5, r6, r7, lr}
 *   @0x149560 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x149564 mov r1, r12
 *   @0x149568 mov r0, r4
 *   @0x14956c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x149570 mov r1, #1
 *   @0x149574 mov r7, r0
 *   @0x149578 mov r0, r4
 *   @0x14957c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x149580 mov r1, #2
 *   @0x149584 mov r6, r0
 *   @0x149588 mov r0, r4
 *   @0x14958c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x149590 mov r1, #3
 *   @0x149594 mov r5, r0
 *   @0x149598 mov r0, r4
 *   @0x14959c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1495a0 mov r3, r0
 *   @0x1495a4 b 0x149518 <_Z25F_GPUSetColourWriteEnableR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x1495a8 andseq r9, pc, r12, lsl #8
 *   @0x1495ac ldrheq r9, [pc], -r12
 *   @0x1495b0 eoreq r4, r10, r12, asr #15
 *
 * ══ §41/81 FUNC_Load(unsigned char*, unsigned int, unsigned char*)  0x1dcdf0  size 372  93 条（0x1dcdf0..0x1dcf64）
 * @func 0x1dcdf0 0x1dcf64  size 372  93 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1dce0c→0x544b5c, 0x1dce64→0x544c44, 0x1dcf1c→0x7590d2
 * 调用序列: FUNC_Load(unsigned char*, unsigned int, unsigned char*)+0xe0 / Code_Function_Find(char const*, int*) / FUNC_Load(unsigned char*, unsigned int, unsigned char*)+0x10c / FUNC_Load(unsigned char*, unsigned int, unsigned char*)+0xd4 / Code_Variable_Read_Local_Names(unsigned char*) / 0xb65c8 / Error_Show(char const*, bool) / YYGML_game_end()
 * 字段偏移 top8: 0x4×4 / 0x40c×2 / 0x14c×1 / 0x148×1 / 0x140×1 / 0x110×1 / 0x8×1 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dcdf0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1dcdf4 sub sp, sp, #1040
 *   @0x1dcdf8 ldr r8, [pc, #0x14c]
 *   @0x1dcdfc sub sp, sp, #4
 *   @0x1dce00 ldr r12, [pc, #0x148]
 *   @0x1dce04 mov r5, r0
 *   @0x1dce08 add r8, pc, r8
 *   @0x1dce0c ldr r3, [pc, #0x140]
 *   @0x1dce10 mov r4, r2
 *   @0x1dce14 ldr r12, [r8, r12]
 *   @0x1dce18 str r12, [sp]
 *   @0x1dce1c ldr r12, [r12]
 *   @0x1dce20 str r12, [sp, #0x40c]
 *   @0x1dce24 ldr r3, [r8, r3]
 *   @0x1dce28 ldrb r3, [r3]
 *   @0x1dce2c cmp r3, #0
 *   @0x1dce30 beq 0x1dcf38 <_Z9FUNC_LoadPhjS_+0x148>
 *   @0x1dce34 ldr r6, [r5], #4
 *   @0x1dce38 cmp r6, #0
 *   @0x1dce3c ble 0x1dced0 <_Z9FUNC_LoadPhjS_+0xe0>
 *   @0x1dce40 ldr r1, [pc, #0x110]
 *   @0x1dce44 add r7, sp, #8
 *   @0x1dce48 add r9, sp, #12
 *   @0x1dce4c mov r11, #0
 *   @0x1dce50 add r1, pc, r1
 *   @0x1dce54 str r1, [sp, #0x4]
 *   @0x1dce58 ldr r0, [r5]
 *   @0x1dce5c cmp r0, #0
 *   @0x1dce60 moveq r10, r0
 *   @0x1dce64 ldrne r3, [pc, #0xf0]
 *   @0x1dce68 ldrne r3, [r8, r3]
 *   @0x1dce6c ldrne r3, [r3]
 *   @0x1dce70 addne r10, r3, r0
 *   @0x1dce74 mov r0, r10
 *   @0x1dce78 mov r1, r7
 *   @0x1dce7c bl 0xce158 <_Z18Code_Function_FindPKcPi>
 *   @0x1dce80 ldr r2, [sp, #0x8]
 *   @0x1dce84 cmp r2, #0
 *   @0x1dce88 blt 0x1dcefc <_Z9FUNC_LoadPhjS_+0x10c>
 *   @0x1dce8c ldr r12, [r5, #0x4]
 *   @0x1dce90 add r5, r5, #12
 *   @0x1dce94 ldr r3, [r5, #-0x4]
 *   @0x1dce98 cmp r12, #0
 *   @0x1dce9c ldrgt lr, [sp, #0x8]
 *   @0x1dcea0 movgt r2, #0
 *   @0x1dcea4 ble 0x1dcec4 <_Z9FUNC_LoadPhjS_+0xd4>
 *   @0x1dcea8 add r1, r3, #4
 *   @0x1dceac add r2, r2, #1
 *   @0x1dceb0 cmp r2, r12
 *   @0x1dceb4 ldr r0, [r4, r1]
 *   @0x1dceb8 str lr, [r4, r1]
 *   @0x1dcebc add r3, r3, r0
 *   @0x1dcec0 bne 0x1dcea8 <_Z9FUNC_LoadPhjS_+0xb8>
 *   @0x1dcec4 add r11, r11, #1
 *   @0x1dcec8 cmp r11, r6
 *   @0x1dcecc bne 0x1dce58 <_Z9FUNC_LoadPhjS_+0x68>
 *   @0x1dced0 mov r0, r5
 *   @0x1dced4 bl 0xd24d4 <_Z30Code_Variable_Read_Local_NamesPh>
 *   @0x1dced8 mov r0, #1
 *   @0x1dcedc ldr r1, [sp]
 *   @0x1dcee0 ldr r2, [sp, #0x40c]
 *   @0x1dcee4 ldr r3, [r1]
 *   @0x1dcee8 cmp r2, r3
 *   @0x1dceec bne 0x1dcf48 <_Z9FUNC_LoadPhjS_+0x158>
 *   @0x1dcef0 add sp, sp, #1040
 *   @0x1dcef4 add sp, sp, #4
 *   @0x1dcef8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1dcefc mov r3, r10
 *   @0x1dcf00 mov r1, #1024
 *   @0x1dcf04 ldr r2, [sp, #0x4]
 *   @0x1dcf08 mov r0, r9
 *   @0x1dcf0c bl 0xb65c8 <snprintf@plt>
 *   @0x1dcf10 mov r0, r9
 *   @0x1dcf14 mov r1, #1
 *   @0x1dcf18 bl 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1dcf1c ldr r3, [pc, #0x3c]
 *   @0x1dcf20 ldr r3, [r8, r3]
 *   @0x1dcf24 ldrb r3, [r3]
 *   @0x1dcf28 cmp r3, #0
 *   @0x1dcf2c beq 0x1dcf40 <_Z9FUNC_LoadPhjS_+0x150>
 *   @0x1dcf30 bl 0x10c320 <_Z14YYGML_game_endv>
 *   @0x1dcf34 b 0x1dce8c <_Z9FUNC_LoadPhjS_+0x9c>
 *   @0x1dcf38 bl 0x1dccc8 <_Z13OLD_FUNC_LoadPhjS_>
 *   @0x1dcf3c b 0x1dcedc <_Z9FUNC_LoadPhjS_+0xec>
 *   @0x1dcf40 mov r0, #1
 *   @0x1dcf44 bl 0xb6688 <exit@plt>
 *   @0x1dcf48 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x1dcf4c eoreq r4, r1, r8, asr #28
 *   @0x1dcf50 .word 0xffffbd00
 *   @0x1dcf54 .word 0xffffbf04
 *   @0x1dcf58 andseq r4, r7, r12, asr #17
 *   @0x1dcf5c .word 0xffffbcf4
 *   @0x1dcf60 .word 0xffffbfe0
 *
 * ══ §42/81 CEmitter::AddNoiseToEmitter(CNoise*)  0x215944  size 372  93 条（0x215944..0x215ab8）
 * @func 0x215944 0x215ab8  size 372  93 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CEmitter::AddNoiseToEmitter(CNoise*)+0x78 / CEmitter::AddNoiseToEmitter(CNoise*)+0x10c / CNoise::~CNoise() / operator delete(void*) / CEmitter::AddNoiseToEmitter(CNoise*)+0x98 / MemoryManager::Free(void const*) / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x38×6 / 0x34×4 / 0x5×2 / 0x2×2 / 0xc×2 / 0x30×1 / 0x4×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x215944 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x215948 mov r8, r1
 *   @0x21594c ldr r4, [r0, #0x34]
 *   @0x215950 sub sp, sp, #20
 *   @0x215954 ldr r3, [r0, #0x30]
 *   @0x215958 mov r6, r0
 *   @0x21595c cmp r4, #0
 *   @0x215960 str r0, [r8, #0x38]
 *   @0x215964 str r3, [r1, #0x34]
 *   @0x215968 ldr r7, [r0, #0x38]
 *   @0x21596c ble 0x2159bc <_ZN8CEmitter17AddNoiseToEmitterEP6CNoise+0x78>
 *   @0x215970 ldr r3, [r7]
 *   @0x215974 cmp r3, #0
 *   @0x215978 beq 0x215a68 <_ZN8CEmitter17AddNoiseToEmitterEP6CNoise+0x124>
 *   @0x21597c ldrb r3, [r3, #0x5]
 *   @0x215980 cmp r3, #0
 *   @0x215984 addne r2, r7, #4
 *   @0x215988 movne r3, #0
 *   @0x21598c bne 0x2159ac <_ZN8CEmitter17AddNoiseToEmitterEP6CNoise+0x68>
 *   @0x215990 b 0x215a68 <_ZN8CEmitter17AddNoiseToEmitterEP6CNoise+0x124>
 *   @0x215994 ldr r12, [r2], #4
 *   @0x215998 cmp r12, #0
 *   @0x21599c beq 0x215a6c <_ZN8CEmitter17AddNoiseToEmitterEP6CNoise+0x128>
 *   @0x2159a0 ldrb r12, [r12, #0x5]
 *   @0x2159a4 cmp r12, #0
 *   @0x2159a8 beq 0x215a6c <_ZN8CEmitter17AddNoiseToEmitterEP6CNoise+0x128>
 *   @0x2159ac add r3, r3, #1
 *   @0x2159b0 mov r5, r2
 *   @0x2159b4 cmp r3, r4
 *   @0x2159b8 bne 0x215994 <_ZN8CEmitter17AddNoiseToEmitterEP6CNoise+0x50>
 *   @0x2159bc adds r10, r4, #1
 *   @0x2159c0 bne 0x215a78 <_ZN8CEmitter17AddNoiseToEmitterEP6CNoise+0x134>
 *   @0x2159c4 cmp r7, #0
 *   @0x2159c8 beq 0x215a50 <_ZN8CEmitter17AddNoiseToEmitterEP6CNoise+0x10c>
 *   @0x2159cc cmp r4, #0
 *   @0x2159d0 ble 0x215a50 <_ZN8CEmitter17AddNoiseToEmitterEP6CNoise+0x10c>
 *   @0x2159d4 mov r5, r10
 *   @0x2159d8 mov r1, r10
 *   @0x2159dc ldr r0, [r7]
 *   @0x2159e0 movw r3, #0xfeee
 *   @0x2159e4 movt r3, #0xfeee
 *   @0x2159e8 movw r2, #0xfeee
 *   @0x2159ec cmp r0, r3
 *   @0x2159f0 movt r2, #0xfeee
 *   @0x2159f4 lsl r11, r5, #2
 *   @0x2159f8 beq 0x215a40 <_ZN8CEmitter17AddNoiseToEmitterEP6CNoise+0xfc>
 *   @0x2159fc ldr r9, [r7, r5, lsl #2]
 *   @0x215a00 add r3, r7, r11
 *   @0x215a04 cmp r9, #0
 *   @0x215a08 mov r0, r9
 *   @0x215a0c beq 0x215a40 <_ZN8CEmitter17AddNoiseToEmitterEP6CNoise+0xfc>
 *   @0x215a10 ldr r12, [r9]
 *   @0x215a14 cmp r12, r2
 *   @0x215a18 beq 0x215a38 <_ZN8CEmitter17AddNoiseToEmitterEP6CNoise+0xf4>
 *   @0x215a1c str r1, [sp, #0xc]
 *   @0x215a20 bl 0x21db28 <_ZN6CNoiseD2Ev>
 *   @0x215a24 mov r0, r9
 *   @0x215a28 bl 0x27d1d0 <_ZdlPv>
 *   @0x215a2c ldr r3, [r6, #0x38]
 *   @0x215a30 ldr r1, [sp, #0xc]
 *   @0x215a34 add r3, r3, r11
 *   @0x215a38 str r1, [r3]
 *   @0x215a3c ldr r7, [r6, #0x38]
 *   @0x215a40 ldr r3, [r6, #0x34]
 *   @0x215a44 add r5, r5, #1
 *   @0x215a48 cmp r5, r3
 *   @0x215a4c blt 0x2159dc <_ZN8CEmitter17AddNoiseToEmitterEP6CNoise+0x98>
 *   @0x215a50 mov r0, r7
 *   @0x215a54 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x215a58 mov r2, #0
 *   @0x215a5c mov r3, r2
 *   @0x215a60 str r2, [r6, #0x38]
 *   @0x215a64 b 0x215aa4 <_ZN8CEmitter17AddNoiseToEmitterEP6CNoise+0x160>
 *   @0x215a68 mov r5, r7
 *   @0x215a6c str r8, [r5]
 *   @0x215a70 add sp, sp, #20
 *   @0x215a74 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x215a78 lsls r1, r10, #2
 *   @0x215a7c beq 0x215a50 <_ZN8CEmitter17AddNoiseToEmitterEP6CNoise+0x10c>
 *   @0x215a80 ldr r2, [pc, #0x2c]
 *   @0x215a84 mov r3, #0
 *   @0x215a88 mov r0, r7
 *   @0x215a8c str r3, [sp]
 *   @0x215a90 add r2, pc, r2
 *   @0x215a94 mov r3, #135
 *   @0x215a98 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x215a9c mov r3, r0
 *   @0x215aa0 str r0, [r6, #0x38]
 *   @0x215aa4 str r10, [r6, #0x34]
 *   @0x215aa8 str r8, [r3, r4, lsl #2]
 *   @0x215aac add sp, sp, #20
 *   @0x215ab0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x215ab4 andseq r7, r3, r0, ror #16
 *
 * ══ §43/81 png_handle_tRNS  0x2acbec  size 372  93 条（0x2acbec..0x2acd60）
 * @func 0x2acbec 0x2acd60  size 372  93 条
 * 部分覆盖: 本节 93/171 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_crc_read / png_warning / png_crc_finish / 0x142b57c / 0xb65d4
 * 字段偏移 top8: 0x148×1 / 0x120×1 / 0x8×1 / 0x108×1 / 0x1×1 / 0x2×1 / 0x4×1 / 0x84×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2acbec ldr r3, [pc, #0x148]
 *   @0x2acbf0 ldrbtmi r4, [r11], #-496
 *   @0x2acbf4 ldr r3, [r3]
 *   @0x2acbf8 sub sp, #0x118
 *   @0x2acbfc mov r4, r0
 *   @0x2acc00 mov r8, r3
 *   @0x2acc04 ldr.w r2, [r0, #0x12c]
 *   @0x2acc08 tst.w r2, #0x1
 *   @0x2acc0c bne 0x2acc18 <png_handle_tRNS+0x2c>
 *   @0x2acc10 add r1, pc
 *   @0x2acc14 and pc, r11, r11, lsl #24
 *   @0x2acc18 lsls r1, r2, #0x1d
 *   @0x2acc1c ldr r1, [pc, #0x120]
 *   @0x2acc20 b 0x2accee <png_handle_tRNS+0x102>
 *   @0x2acc24 ldr r3, [r7, #0x8]
 *   @0x2acc28 bpl 0x2acc30 <png_handle_tRNS+0x44>
 *   @0x2acc2c add r1, pc
 *   @0x2acc30 ldrb.w r2, [r4, #0x1ea]
 *   @0x2acc34 cbnz r2, 0x2acc60 <png_handle_tRNS+0x74>
 *   @0x2acc38 mov r0, r4
 *   @0x2acc3c ldr r1, [pc, #0x108]
 *   @0x2acc40 b 0x2accee <png_handle_tRNS+0x102>
 *   @0x2acc44 mov r2, r5
 *   @0x2acc48 bl 0x2abc0c <png_crc_read>
 *   @0x2acc4c ldrb r2, [r6]
 *   @0x2acc50 strh.w r3, [r4, #0x1de]
 *   @0x2acc54 ldrb r3, [r6, #0x1]
 *   @0x2acc58 .word 0xf8a42302
 *   @0x2acc5c sub r3, sp, r8, asr r2
 *   @0x2acc60 cmp r2, #0x2
 *   @0x2acc64 cmp r5, #0x6
 *   @0x2acc68 beq 0x2acc70 <png_handle_tRNS+0x84>
 *   @0x2acc6c add r1, pc
 *   @0x2acc70 add r6, sp, #0xc
 *   @0x2acc74 mov r1, r6
 *   @0x2acc78 ldmdavc r2!, {r0, r3, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2acc7c movs r3, #0x1
 *   @0x2acc80 ldmdavc r3!, {r1, r2, r3, r4, r6, r7, r8, r12, sp} ^
 *   @0x2acc84 add.w r3, r3, r2, lsl #8
 *   @0x2acc88 ldrb r2, [r6, #0x2]
 *   @0x2acc8c ldmvc r3!, {r1, r4, r6, r9, r12, sp} ^
 *   @0x2acc90 add.w r3, r3, r2, lsl #8
 *   @0x2acc94 ldrb r2, [r6, #0x4]
 *   @0x2acc98 ldmdbvc r3!, {r2, r4, r6, r9, r12, sp} ^
 *   @0x2acc9c add.w r3, r3, r2, lsl #8
 *   @0x2acca0 strh.w r3, [r4, #0x256]
 *   @0x2acca4 b 0x2accfc <png_handle_tRNS+0x110>
 *   @0x2acca8 bne 0x2acce8 <png_handle_tRNS+0xfc>
 *   @0x2accac ldreq r3, [r11, r12, lsr #2]
 *   @0x2accb0 bmi 0x2accbc <png_handle_tRNS+0xd0>
 *   @0x2accb4 mov r0, r4
 *   @0x2accb8 bl 0x2a6474 <png_warning>
 *   @0x2accbc ldrh.w r3, [r4, #0x1dc]
 *   @0x2accc0 mov r0, r4
 *   @0x2accc4 bhi 0x2acccc <png_handle_tRNS+0xe0>
 *   @0x2accc8 stmdble r2, {r7, r8, r9, r10, r11, r12, sp, lr}
 *   @0x2acccc ldr r1, [pc, #0x84]
 *   @0x2accd0 b 0x2accee <png_handle_tRNS+0x102>
 *   @0x2accd4 ldr r1, [pc, #0x80]
 *   @0x2accd8 b 0x2accee <png_handle_tRNS+0x102>
 *   @0x2accdc mov r2, r5
 *   @0x2acce0 .word 0xf8a4ff95
 *   @0x2acce4 ldrd r5, r6, [r9], -lr
 *   @0x2acce8 ldr r1, [pc, #0x70]
 *   @0x2accec add r1, pc
 *   @0x2accf0 strtmi pc, [r0], -r1, asr #23
 *   @0x2accf4 mov r1, r5
 *   @0x2accf8 ands pc, r2, sp, asr #31
 *   @0x2accfc mov r0, r4
 *   @0x2acd00 bl 0x2abc94 <png_crc_finish>
 *   @0x2acd04 cbz r0, 0x2acd0e <png_handle_tRNS+0x122>
 *   @0x2acd08 strh.w r3, [r4, #0x1de]
 *   @0x2acd0c b 0x2acd22 <png_handle_tRNS+0x136>
 *   @0x2acd10 rfeia r4!
 *   @0x2acd14 andls r3, r0, #-2147483593
 *   @0x2acd18 mov r0, r4
 *   @0x2acd1c add r2, sp, #0x14
 *   @0x2acd20 bls 0x142b57c <b2_toiTime+0xcd20d8>
 *   @0x2acd24 ldr.w r3, [r8]
 *   @0x2acd28 cmp r2, r3
 *   @0x2acd2c blx 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2acd30 add sp, #0x118
 *   @0x2acd34 svclt #0x81f0
 *   @0x2acd38 lsrs r2, r4, #0x15
 *   @0x2acd3c lsls r2, r4, #0x19
 *   @0x2acd40 lsls r5, r5, #0x19
 *   @0x2acd44 lsls r7, r6, #0x19
 *   @0x2acd48 lsls r2, r7, #0x19
 *   @0x2acd4c lsls r4, r1, #0x19
 *   @0x2acd50 lsls r6, r3, #0x18
 *   @0x2acd54 lsls r2, r5, #0x17
 *   @0x2acd58 lsls r7, r2, #0x18
 *   @0x2acd5c lsls r0, r3, #0x18
 *
 * ══ §44/81 png_set_filter  0x2b0710  size 372  93 条（0x2b0710..0x2b0884）
 * @func 0x2b0710 0x2b0884  size 372  93 条
 * 部分覆盖: 本节 93/166 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_malloc×4 / png_warning / anon_2bc92c+0x504
 * 字段偏移 top8: 0xcc×1 / 0x90×1 / 0x54×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b0710 push {r4, lr}
 *   @0x2b0714 cmp r0, #0x0
 *   @0x2b0718 .word 0xf8d080a9
 *   @0x2b071c smmlseq r8, r12, r2, r3
 *   @0x2b0720 bpl 0x2b0726 <png_set_filter+0x16>
 *   @0x2b0724 beq 0x2b072c <png_set_filter+0x1c>
 *   @0x2b0728 bne.w 0x2b085e <png_set_filter+0x14e>
 *   @0x2b072c uxtb r3, r2
 *   @0x2b0730 bhi 0x2b0762 <png_set_filter+0x52>
 *   @0x2b0734 .word 0x0c04f003
 *   @0x2b0738 asrs r0, r2, #0x8
 *   @0x2b073c lsls r6, r0, #0x18
 *   @0x2b0740 b 0x2b0750 <png_set_filter+0x40>
 *   @0x2b0744 mov r0, r4
 *   @0x2b0748 bl 0x2a6474 <png_warning>
 *   @0x2b074c b 0x2b0766 <png_set_filter+0x56>
 *   @0x2b0750 strb.w r3, [r4, #0x1e9]
 *   @0x2b0754 b 0x2b0766 <png_set_filter+0x56>
 *   @0x2b0758 b 0x2b0750 <png_set_filter+0x40>
 *   @0x2b075c b 0x2b0750 <png_set_filter+0x40>
 *   @0x2b0760 b 0x2b0750 <png_set_filter+0x40>
 *   @0x2b0764 .word 0xf8d421e9
 *   @0x2b0768 blhs 0x2bce30 <jpeg_alloc_huff_table+0x528>
 *   @0x2b076c beq 0x2b086c <png_set_filter+0x15c>
 *   @0x2b0770 ldrbeq r3, [r9], r9, ror #3
 *   @0x2b0774 bpl 0x2b0790 <png_set_filter+0x80>
 *   @0x2b0778 stmdblt r11, {r2, r4, r5, r7, r8, r12, sp} ^
 *   @0x2b077c ldr.w r1, [r4, #0x19c]
 *   @0x2b0780 mov r0, r4
 *   @0x2b0784 bl 0x2a6ca0 <png_malloc>
 *   @0x2b0788 movs r3, #0x1
 *   @0x2b078c strhvc r0, [r3], -r4
 *   @0x2b0790 ldrb.w r3, [r4, #0x1e9]
 *   @0x2b0794 lsls r2, r3, #0x1a
 *   @0x2b0798 ldr.w r3, [r4, #0x1b8]
 *   @0x2b079c cbnz r3, 0x2b07d0 <png_set_filter+0xc0>
 *   @0x2b07a0 ldmdblt r11, {r2, r3, r5, r7, r8, r12, sp} ^
 *   @0x2b07a4 ldr r1, [pc, #0xcc]
 *   @0x2b07a8 add r1, pc
 *   @0x2b07ac .word 0xf894fe63
 *   @0x2b07b0 .word 0xf02331e9
 *   @0x2b07b4 .word 0xf8840320
 *   @0x2b07b8 and r3, r9, r9, ror #3
 *   @0x2b07bc ldr.w r1, [r4, #0x19c]
 *   @0x2b07c0 mov r0, r4
 *   @0x2b07c4 bl 0x2a6ca0 <png_malloc>
 *   @0x2b07c8 movs r3, #0x2
 *   @0x2b07cc strhvc r0, [r3], -r8
 *   @0x2b07d0 ldrb.w r3, [r4, #0x1e9]
 *   @0x2b07d4 lsls r3, r3, #0x19
 *   @0x2b07d8 ldr.w r3, [r4, #0x1bc]
 *   @0x2b07dc cbnz r3, 0x2b0810 <png_set_filter+0x100>
 *   @0x2b07e0 ldmdblt r11, {r2, r3, r5, r7, r8, r12, sp} ^
 *   @0x2b07e4 ldr r1, [pc, #0x90]
 *   @0x2b07e8 add r1, pc
 *   @0x2b07ec .word 0xf894fe43
 *   @0x2b07f0 .word 0xf02331e9
 *   @0x2b07f4 .word 0xf8840340
 *   @0x2b07f8 and r3, r9, r9, ror #3
 *   @0x2b07fc ldr.w r1, [r4, #0x19c]
 *   @0x2b0800 mov r0, r4
 *   @0x2b0804 bl 0x2a6ca0 <png_malloc>
 *   @0x2b0808 movs r3, #0x3
 *   @0x2b080c strhvc r0, [r3], -r12
 *   @0x2b0810 ldrsb.w r3, [r4, #0x1e9]
 *   @0x2b0814 cmp r3, #0x0
 *   @0x2b0818 ldr.w r3, [r4, #0x1c0]
 *   @0x2b081c cbnz r3, 0x2b0850 <png_set_filter+0x140>
 *   @0x2b0820 ldmdblt r11, {r2, r3, r5, r7, r8, r12, sp} ^
 *   @0x2b0824 ldr r1, [pc, #0x54]
 *   @0x2b0828 add r1, pc
 *   @0x2b082c .word 0xf894fe23
 *   @0x2b0830 .word 0xf00331e9
 *   @0x2b0834 .word 0xf884037f
 *   @0x2b0838 and r3, r9, r9, ror #3
 *   @0x2b083c ldr.w r1, [r4, #0x19c]
 *   @0x2b0840 mov r0, r4
 *   @0x2b0844 bl 0x2a6ca0 <png_malloc>
 *   @0x2b0848 movs r3, #0x4
 *   @0x2b084c andvc r0, r3, r0, asr #3
 *   @0x2b0850 ldrb.w r3, [r4, #0x1e9]
 *   @0x2b0854 cbnz r3, 0x2b086c <png_set_filter+0x15c>
 *   @0x2b0858 strb.w r3, [r4, #0x1e9]
 *   @0x2b085c pop {r4, pc}
 *   @0x2b0860 mov r0, r4
 *   @0x2b0864 ldrbtmi r4, [r9], #-16
 *   @0x2b0868 b.w 0x2a642c <png_error>
 *   @0x2b086c pop {r4, pc}
 *   @0x2b0870 bhi 0x2b08f8 <png_set_compression_window_bits+0x34>
 *   @0x2b0874 bhi 0x2b0878 <png_set_filter+0x168>
 *   @0x2b0878 bvc 0x2b0842 <png_set_filter+0x132>
 *   @0x2b087c bvc 0x2b0816 <png_set_filter+0x106>
 *   @0x2b0880 bvc 0x2b07ea <png_set_filter+0xda>
 *
 * ══ §45/81 jinit_d_coef_controller  0x2bd9a0  size 372  93 条（0x2bd9a0..0x2bdb14）
 * @func 0x2bd9a0 0x2bdb14  size 372  93 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: jround_up×2 / jinit_d_coef_controller+0xd4
 * 字段偏移 top8: 0x4×7 / 0xc×3 / 0x130×2 / 0x8×2 / 0x24×2 / 0x10×2 / 0x188×1 / 0x70×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2bd9a0 ldr r3, [r0, #0x4]
 *   @0x2bd9a4 mov r2, #116
 *   @0x2bd9a8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2bd9ac mov r4, r1
 *   @0x2bd9b0 ldr r3, [r3]
 *   @0x2bd9b4 sub sp, sp, #12
 *   @0x2bd9b8 mov r1, #1
 *   @0x2bd9bc mov r5, r0
 *   @0x2bd9c0 blx r3
 *   @0x2bd9c4 ldr r2, [pc, #0x130]
 *   @0x2bd9c8 ldr r3, [pc, #0x130]
 *   @0x2bd9cc cmp r4, #0
 *   @0x2bd9d0 add r2, pc, r2
 *   @0x2bd9d4 mov r8, #0
 *   @0x2bd9d8 add r3, pc, r3
 *   @0x2bd9dc str r0, [r5, #0x188]
 *   @0x2bd9e0 mov r11, r0
 *   @0x2bd9e4 str r2, [r0]
 *   @0x2bd9e8 str r3, [r0, #0x8]
 *   @0x2bd9ec str r8, [r0, #0x70]
 *   @0x2bd9f0 beq 0x2bda9c <jinit_d_coef_controller+0xfc>
 *   @0x2bd9f4 ldr r3, [r5, #0x24]
 *   @0x2bd9f8 ldr r4, [r5, #0xc4]
 *   @0x2bd9fc cmp r3, r8
 *   @0x2bda00 movgt r7, r0
 *   @0x2bda04 ble 0x2bda74 <jinit_d_coef_controller+0xd4>
 *   @0x2bda08 ldrb r3, [r5, #0xc8]
 *   @0x2bda0c add r8, r8, #1
 *   @0x2bda10 ldr r6, [r4, #0xc]
 *   @0x2bda14 add r7, r7, #4
 *   @0x2bda18 cmp r3, #0
 *   @0x2bda1c ldr r3, [r5, #0x4]
 *   @0x2bda20 ldr r1, [r4, #0x8]
 *   @0x2bda24 add r4, r4, #84
 *   @0x2bda28 ldr r0, [r4, #-0x38]
 *   @0x2bda2c addne r6, r6, r6, lsl #1
 *   @0x2bda30 ldr r9, [r3, #0x14]
 *   @0x2bda34 bl 0x2bc800 <jround_up>
 *   @0x2bda38 ldr r1, [r4, #-0x48]
 *   @0x2bda3c mov r10, r0
 *   @0x2bda40 ldr r0, [r4, #-0x34]
 *   @0x2bda44 bl 0x2bc800 <jround_up>
 *   @0x2bda48 mov r1, #1
 *   @0x2bda4c mov r3, r10
 *   @0x2bda50 str r6, [sp, #0x4]
 *   @0x2bda54 mov r2, r1
 *   @0x2bda58 str r0, [sp]
 *   @0x2bda5c mov r0, r5
 *   @0x2bda60 blx r9
 *   @0x2bda64 str r0, [r7, #0x44]
 *   @0x2bda68 ldr r3, [r5, #0x24]
 *   @0x2bda6c cmp r3, r8
 *   @0x2bda70 bgt 0x2bda08 <jinit_d_coef_controller+0x68>
 *   @0x2bda74 ldr r2, [pc, #0x88]
 *   @0x2bda78 add r1, r11, #72
 *   @0x2bda7c ldr r3, [pc, #0x84]
 *   @0x2bda80 add r2, pc, r2
 *   @0x2bda84 str r1, [r11, #0x10]
 *   @0x2bda88 add r3, pc, r3
 *   @0x2bda8c str r2, [r11, #0x4]
 *   @0x2bda90 str r3, [r11, #0xc]
 *   @0x2bda94 add sp, sp, #12
 *   @0x2bda98 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2bda9c ldr r3, [r5, #0x4]
 *   @0x2bdaa0 mov r1, #1
 *   @0x2bdaa4 mov r0, r5
 *   @0x2bdaa8 mov r2, #1280
 *   @0x2bdaac ldr r3, [r3, #0x4]
 *   @0x2bdab0 blx r3
 *   @0x2bdab4 mov r1, r4
 *   @0x2bdab8 mov r3, r11
 *   @0x2bdabc add r2, r0, r1
 *   @0x2bdac0 add r1, r1, #128
 *   @0x2bdac4 cmp r1, #1280
 *   @0x2bdac8 str r2, [r3, #0x20]
 *   @0x2bdacc add r3, r3, #4
 *   @0x2bdad0 bne 0x2bdabc <jinit_d_coef_controller+0x11c>
 *   @0x2bdad4 ldr r2, [pc, #0x30]
 *   @0x2bdad8 mov r1, #0
 *   @0x2bdadc ldr r3, [pc, #0x2c]
 *   @0x2bdae0 add r2, pc, r2
 *   @0x2bdae4 str r1, [r11, #0x10]
 *   @0x2bdae8 add r3, pc, r3
 *   @0x2bdaec str r2, [r11, #0x4]
 *   @0x2bdaf0 str r3, [r11, #0xc]
 *   @0x2bdaf4 add sp, sp, #12
 *   @0x2bdaf8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2bdafc .word 0xffffefa0
 *   @0x2bdb00 .word 0xfffff1f0
 *   @0x2bdb04 .word 0xffffef04
 *   @0x2bdb08 .word 0xfffffa48
 *   @0x2bdb0c .word 0xffffee9c
 *   @0x2bdb10 .word 0xfffffbdc
 *
 * ══ §46/81 anon_2be8b4  0x2be8b4  size 372  93 条（0x2be8b4..0x2bea28）
 * @func 0x2be8b4 0x2bea28  size 372  93 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: jpeg_make_d_derived_tbl×2 / anon_2be8b0+0xb0 / anon_2be8b0+0x144
 * 字段偏移 top8: 0x14×3 / 0x2×3 / 0x124×2 / 0x18×2 / 0x10×2 / 0x140×2 / 0x24×2 / 0x198×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2be8b4 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2be8b8 cmp r3, #0
 *   @0x2be8bc mov r4, r0
 *   @0x2be8c0 ldr r5, [r0, #0x198]
 *   @0x2be8c4 bne 0x2be8d4 <jpeg_make_d_derived_tbl+0x3c4>
 *   @0x2be8c8 ldr r3, [r0, #0x170]
 *   @0x2be8cc cmp r3, #63
 *   @0x2be8d0 beq 0x2bea10 <jpeg_make_d_derived_tbl+0x500>
 *   @0x2be8d4 ldr r3, [r4]
 *   @0x2be8d8 mov r2, #122
 *   @0x2be8dc mov r0, r4
 *   @0x2be8e0 mvn r1, #0
 *   @0x2be8e4 str r2, [r3, #0x14]
 *   @0x2be8e8 ldr r3, [r3, #0x4]
 *   @0x2be8ec blx r3
 *   @0x2be8f0 ldr r3, [r4, #0x124]
 *   @0x2be8f4 cmp r3, #0
 *   @0x2be8f8 ble 0x2be960 <jpeg_make_d_derived_tbl+0x450>
 *   @0x2be8fc mov r6, #0
 *   @0x2be900 mov r8, r4
 *   @0x2be904 mov r10, r6
 *   @0x2be908 mov r7, r5
 *   @0x2be90c ldr r3, [r8, #0x128]
 *   @0x2be910 mov r1, #1
 *   @0x2be914 mov r0, r4
 *   @0x2be918 add r6, r6, r1
 *   @0x2be91c add r8, r8, #4
 *   @0x2be920 add r7, r7, #4
 *   @0x2be924 ldr r2, [r3, #0x14]
 *   @0x2be928 ldr r9, [r3, #0x18]
 *   @0x2be92c add r3, r2, #10
 *   @0x2be930 add r3, r5, r3, lsl #2
 *   @0x2be934 bl 0x2be510 <jpeg_make_d_derived_tbl>
 *   @0x2be938 add r3, r9, #14
 *   @0x2be93c mov r2, r9
 *   @0x2be940 mov r0, r4
 *   @0x2be944 add r3, r5, r3, lsl #2
 *   @0x2be948 mov r1, #0
 *   @0x2be94c bl 0x2be510 <jpeg_make_d_derived_tbl>
 *   @0x2be950 str r10, [r7, #0x10]
 *   @0x2be954 ldr r3, [r4, #0x124]
 *   @0x2be958 cmp r3, r6
 *   @0x2be95c bgt 0x2be90c <jpeg_make_d_derived_tbl+0x3fc>
 *   @0x2be960 ldr r3, [r4, #0x140]
 *   @0x2be964 cmp r3, #0
 *   @0x2be968 ble 0x2be9f4 <jpeg_make_d_derived_tbl+0x4e4>
 *   @0x2be96c mov r12, r4
 *   @0x2be970 mov r2, r5
 *   @0x2be974 mov r1, r5
 *   @0x2be978 mov r0, #0
 *   @0x2be97c mov r7, #1
 *   @0x2be980 ldr r3, [r12, #0x144]
 *   @0x2be984 add r3, r3, #74
 *   @0x2be988 ldr r3, [r4, r3, lsl #2]
 *   @0x2be98c ldr r6, [r3, #0x14]
 *   @0x2be990 add r6, r6, #10
 *   @0x2be994 ldr r6, [r5, r6, lsl #2]
 *   @0x2be998 str r6, [r2, #0x48]
 *   @0x2be99c ldr r6, [r3, #0x18]
 *   @0x2be9a0 add r6, r6, #14
 *   @0x2be9a4 ldr r6, [r5, r6, lsl #2]
 *   @0x2be9a8 str r6, [r2, #0x70]
 *   @0x2be9ac ldrb r6, [r3, #0x30]
 *   @0x2be9b0 cmp r6, #0
 *   @0x2be9b4 strbeq r6, [r1, #0xa2]
 *   @0x2be9b8 strbeq r6, [r1, #0x98]
 *   @0x2be9bc beq 0x2be9d8 <jpeg_make_d_derived_tbl+0x4c8>
 *   @0x2be9c0 strb r7, [r1, #0x98]
 *   @0x2be9c4 ldr r3, [r3, #0x24]
 *   @0x2be9c8 cmp r3, #1
 *   @0x2be9cc movle r3, #0
 *   @0x2be9d0 movgt r3, #1
 *   @0x2be9d4 strb r3, [r1, #0xa2]
 *   @0x2be9d8 ldr r3, [r4, #0x140]
 *   @0x2be9dc add r0, r0, #1
 *   @0x2be9e0 add r12, r12, #4
 *   @0x2be9e4 add r2, r2, #4
 *   @0x2be9e8 cmp r3, r0
 *   @0x2be9ec add r1, r1, #1
 *   @0x2be9f0 bgt 0x2be980 <jpeg_make_d_derived_tbl+0x470>
 *   @0x2be9f4 mov r3, #0
 *   @0x2be9f8 strb r3, [r5, #0x8]
 *   @0x2be9fc ldr r2, [r4, #0xfc]
 *   @0x2bea00 str r3, [r5, #0x10]
 *   @0x2bea04 str r3, [r5, #0xc]
 *   @0x2bea08 str r2, [r5, #0x24]
 *   @0x2bea0c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2bea10 ldr r3, [r0, #0x174]
 *   @0x2bea14 cmp r3, #0
 *   @0x2bea18 bne 0x2be8d4 <jpeg_make_d_derived_tbl+0x3c4>
 *   @0x2bea1c ldr r3, [r0, #0x178]
 *   @0x2bea20 cmp r3, #0
 *   @0x2bea24 beq 0x2be8f0 <jpeg_make_d_derived_tbl+0x3e0>
 *
 * ══ §47/81 png_read_transform_info  0x2a89bc  size 370  93 条（0x2a89bc..0x2a8b2e）
 * @func 0x2a89bc 0x2a8b30  size 372  93 条
 * 部分覆盖: 本节 93/169 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_read_transform_info+0x168
 * 字段偏移 top8: 0x19×7 / 0x18×4 / 0x16×2 / 0x1d×2 / 0x4×1 / 0x8×1 / 0x1e×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a89bc push {r4, r5, lr}
 *   @0x2a89c0 ldr.w r0, [r0, #0x134]
 *   @0x2a89c4 mov r3, r1
 *   @0x2a89c8 bpl 0x2a89fa <png_read_transform_info+0x3e>
 *   @0x2a89cc ldrh.w r4, [r2, #0x1de]
 *   @0x2a89d0 cmp r1, #0x3
 *   @0x2a89d4 cbz r4, 0x2a89da <png_read_transform_info+0x1e>
 *   @0x2a89d8 b 0x2a89dc <png_read_transform_info+0x20>
 *   @0x2a89dc strb r1, [r3, #0x19]
 *   @0x2a89e0 cbz r4, 0x2a89ec <png_read_transform_info+0x30>
 *   @0x2a89e4 itt mi
 *   @0x2a89e8 ldrbvc r0, [r9], -r4, lsl #2
 *   @0x2a89ec ldrb r1, [r3, #0x18]
 *   @0x2a89f0 bhi 0x2a89f6 <png_read_transform_info+0x3a>
 *   @0x2a89f4 strb r1, [r3, #0x18]
 *   @0x2a89f8 strh r1, [r3, #0x16]
 *   @0x2a89fc .word 0x060d1134
 *   @0x2a8a00 bpl 0x2a8a22 <png_read_transform_info+0x66>
 *   @0x2a8a04 add.w r4, r2, #0x1fc
 *   @0x2a8a08 add.w r5, r3, #0x5a
 *   @0x2a8a0c bic r1, r1, #0x4
 *   @0x2a8a10 strb r1, [r3, #0x19]
 *   @0x2a8a14 strh r1, [r3, #0x16]
 *   @0x2a8a18 str.w r0, [r3, #0x5a]
 *   @0x2a8a1c str r1, [r5, #0x4]
 *   @0x2a8a20 strh r1, [r5, #0x8]
 *   @0x2a8a24 streq r1, [r12], #308
 *   @0x2a8a28 bpl 0x2a8a38 <png_read_transform_info+0x7c>
 *   @0x2a8a2c addsvs r1, r9, #32, #4
 *   @0x2a8a30 ldr.w r1, [r2, #0x2e0]
 *   @0x2a8a34 str.w r1, [r3, #0xfc]
 *   @0x2a8a38 ldr.w r1, [r2, #0x134]
 *   @0x2a8a3c lsls r0, r1, #0x15
 *   @0x2a8a40 ldrb r1, [r3, #0x18]
 *   @0x2a8a44 itt eq
 *   @0x2a8a48 strbeq r1, [r3, #0x18]
 *   @0x2a8a4c strbeq r1, [r9], #-308
 *   @0x2a8a50 bpl 0x2a8a5a <png_read_transform_info+0x9e>
 *   @0x2a8a54 orr r1, r1, #0x2
 *   @0x2a8a58 strb r1, [r3, #0x19]
 *   @0x2a8a5c .word 0xf4111134
 *   @0x2a8a60 andle r0, r3, r0, asr #31
 *   @0x2a8a64 ldrb r1, [r3, #0x19]
 *   @0x2a8a68 ldrbvc r0, [r9], -r2, lsl #2
 *   @0x2a8a6c ldr.w r1, [r2, #0x134]
 *   @0x2a8a70 tst.w r1, #0x40
 *   @0x2a8a74 ldrb r1, [r3, #0x18]
 *   @0x2a8a78 ldrb r0, [r3, #0x19]
 *   @0x2a8a7c stmdahs r2, {r0, r1, r3, r4, r5, r6, r7}
 *   @0x2a8a80 bne 0x2a8a90 <png_read_transform_info+0xd4>
 *   @0x2a8a84 ldrhlt r0, [r8, -r0]
 *   @0x2a8a88 cmp r1, #0x8
 *   @0x2a8a8c moveq r0, #0x3
 *   @0x2a8a90 ldr.w r0, [r2, #0x134]
 *   @0x2a8a94 lsls r5, r0, #0x1d
 *   @0x2a8a98 cmp r1, #0x7
 *   @0x2a8a9c movls r1, #0x8
 *   @0x2a8aa0 ldrb r1, [r3, #0x19]
 *   @0x2a8aa4 bne 0x2a8aaa <png_read_transform_info+0xee>
 *   @0x2a8aa8 b 0x2a8ab0 <png_read_transform_info+0xf4>
 *   @0x2a8aac bpl 0x2a8aa6 <png_read_transform_info+0xea>
 *   @0x2a8ab0 strb r0, [r3, #0x1d]
 *   @0x2a8ab4 subeq r0, r0, #48, #2
 *   @0x2a8ab8 itt mi
 *   @0x2a8abc ldrbvc r0, [r9], -r4, lsl #2
 *   @0x2a8ac0 ldrb r1, [r3, #0x19]
 *   @0x2a8ac4 bpl 0x2a8acc <png_read_transform_info+0x110>
 *   @0x2a8ac8 adds r0, #0x1
 *   @0x2a8acc ldr.w r0, [r2, #0x134]
 *   @0x2a8ad0 lsls r4, r0, #0x10
 *   @0x2a8ad4 tst.w r1, #0xfd
 *   @0x2a8ad8 bne 0x2a8aee <png_read_transform_info+0x132>
 *   @0x2a8adc adds r0, #0x1
 *   @0x2a8ae0 ldr.w r0, [r2, #0x134]
 *   @0x2a8ae4 lsls r0, r0, #0x7
 *   @0x2a8ae8 orrmi r1, r1, #0x4
 *   @0x2a8aec strbmi r1, [r3, #0x19]
 *   @0x2a8af0 sbceq r1, r9, #52, #2
 *   @0x2a8af4 bpl 0x2a8b0e <png_read_transform_info+0x152>
 *   @0x2a8af8 cdpvc p1, #0x1, c1, c8, c8, #0x1
 *   @0x2a8afc cmp r0, r1
 *   @0x2a8b00 strblo r1, [r3, #0x18]
 *   @0x2a8b04 svcvc #0x592129
 *   @0x2a8b08 cmp r1, r2
 *   @0x2a8b0c strblo r2, [r3, #0x1d]
 *   @0x2a8b10 ldrb r2, [r3, #0x1d]
 *   @0x2a8b14 ldr r1, [r3]
 *   @0x2a8b18 strb r2, [r3, #0x1e]
 *   @0x2a8b1c bls 0x2a8b24 <png_read_transform_info+0x168>
 *   @0x2a8b20 muls r2, r1, r2
 *   @0x2a8b24 muls r2, r1, r2
 *   @0x2a8b28 lsrs r2, r2, #0x3
 *   @0x2a8b2c pop {r4, r5, pc}
 *
 * ══ §48/81 FT_Request_Metrics  0x2e5588  size 370  93 条（0x2e5588..0x2e56fa）
 * @func 0x2e5588 0x2e56fc  size 372  93 条
 * 部分覆盖: 本节 93/165 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xff36d6e8 / __divsi3 / 0x3603e8 / FT_DivFix / FT_MulDiv / 0xb65b0
 * 字段偏移 top8: 0x10×5 / 0x4×2 / 0x34×1 / 0x38×1 / 0x8×1 / 0x14×1 / 0xe×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5588 push.w {r0, r1, r2, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2e558c mov r7, r1
 *   @0x2e5590 mov r5, r0
 *   @0x2e5594 ands r1, r1, #0x1
 *   @0x2e5598 add.w r11, r4, #0xc
 *   @0x2e559c beq.w 0x2e56dc <FT_Request_Metrics+0x154>
 *   @0x2e55a0 ldm.w r7, {r2, r3}
 *   @0x2e55a4 cmp r2, #0x4
 *   @0x2e55a8 ldm pc, {r2, r5, r7, pc} ^
 *   @0x2e55ac streq pc, [r3], -r2
 *   @0x2e55b0 asrs r6, r1, #0x1c
 *   @0x2e55b4 ldrh.w r9, [r5, #0x44]
 *   @0x2e55b8 b 0x2e56f6 <FT_Request_Metrics+0x16e>
 *   @0x2e55bc rfeib r5!
 *   @0x2e55c0 bl 0xff36d6e8 <b2_toiTime+0xfffffffffec14244>
 *   @0x2e55c4 strbmi r0, [r10], r9, lsl #18
 *   @0x2e55c8 b 0x2e5604 <FT_Request_Metrics+0x7c>
 *   @0x2e55cc ldr r2, [r5, #0x34]
 *   @0x2e55d0 stcvs p9, c0, [r9], #-4
 *   @0x2e55d4 ldr r2, [r5, #0x38]
 *   @0x2e55d8 ands r0, r3, r1, lsl #20
 *   @0x2e55dc ldrsh.w r10, [r5, #0x46]
 *   @0x2e55e0 ldrsh.w r2, [r5, #0x48]
 *   @0x2e55e4 ldrsh.w r9, [r5, #0x4c]
 *   @0x2e55e8 rsb r10, r2, r10
 *   @0x2e55ec b 0x2e5604 <FT_Request_Metrics+0x7c>
 *   @0x2e55f0 ldr r6, [r7, #0x8]
 *   @0x2e55f4 cbnz r3, 0x2e55fc <FT_Request_Metrics+0x74>
 *   @0x2e55f8 mov r6, r3
 *   @0x2e55fc cmp r6, #0x0
 *   @0x2e5600 str r3, [r4, #0x14]
 *   @0x2e5604 cmp.w r9, #0x0
 *   @0x2e5608 it lt
 *   @0x2e560c ldmvs r8!, {r8, r11} ^
 *   @0x2e5610 cmp.w r10, #0x0
 *   @0x2e5614 it lt
 *   @0x2e5618 .word 0xb1400a00
 *   @0x2e561c muls r0, r3, r0
 *   @0x2e5620 str r3, [sp, #0x4]
 *   @0x2e5624 blx 0x318d10 <__divsi3>
 *   @0x2e5628 ldr r3, [sp, #0x4]
 *   @0x2e562c b 0x2e5630 <FT_Request_Metrics+0xa8>
 *   @0x2e5630 ldr r0, [r7, #0x10]
 *   @0x2e5634 cbz r0, 0x2e5646 <FT_Request_Metrics+0xbe>
 *   @0x2e5638 movs r1, #0x48
 *   @0x2e563c adds r0, #0x24
 *   @0x2e5640 blls 0x3603e8 <_ZTS12CDS_Priority+0x2440>
 *   @0x2e5644 mov r6, r0
 *   @0x2e5648 mov r0, r8
 *   @0x2e564c bl 0x2e4eb6 <FT_DivFix>
 *   @0x2e5650 str r0, [r4, #0x10]
 *   @0x2e5654 cbz r3, 0x2e5672 <FT_Request_Metrics+0xea>
 *   @0x2e5658 mov r1, r10
 *   @0x2e565c .word 0x6160fc2c
 *   @0x2e5660 ldr r3, [r7]
 *   @0x2e5664 bne 0x2e56a0 <FT_Request_Metrics+0x118>
 *   @0x2e5668 cmp r0, r3
 *   @0x2e566c strle r0, [r4, #0x10]
 *   @0x2e5670 b 0x2e56a0 <FT_Request_Metrics+0x118>
 *   @0x2e5674 mov r1, r10
 *   @0x2e5678 mov r2, r9
 *   @0x2e567c .word 0x4606fb5f
 *   @0x2e5680 b 0x2e56a0 <FT_Request_Metrics+0x118>
 *   @0x2e5684 mov r0, r6
 *   @0x2e5688 .word 0x4649fc16
 *   @0x2e568c mov r2, r10
 *   @0x2e5690 str r0, [r4, #0x10]
 *   @0x2e5694 bl 0x2e4d3c <FT_MulDiv>
 *   @0x2e5698 mov r8, r0
 *   @0x2e569c movs r6, #0x0
 *   @0x2e56a0 ldr r3, [r7]
 *   @0x2e56a4 ldr r1, [r4, #0x10]
 *   @0x2e56a8 .word 0xf7ff0044
 *   @0x2e56ac stmdbvs r1!, {r0, r1, r2, r3, r6, r7, r8, r9, r11, r12, sp, lr, pc} ^
 *   @0x2e56b0 mov r8, r0
 *   @0x2e56b4 .word 0xf7ff0044
 *   @0x2e56b8 strmi pc, [r6], -r9, asr #23
 *   @0x2e56bc add.w r8, r8, #0x20
 *   @0x2e56c0 adds r6, #0x20
 *   @0x2e56c4 mov r1, r11
 *   @0x2e56c8 .word 0x11b618a8
 *   @0x2e56cc strh.w r8, [r4, #0xc]
 *   @0x2e56d0 strh r6, [r4, #0xe]
 *   @0x2e56d4 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2e56d8 b.w 0x2e4e68 <FT_MulFix+0x1c>
 *   @0x2e56dc mov r0, r11
 *   @0x2e56e0 blx 0xb65b0 <memset@plt>
 *   @0x2e56e4 mov.w r3, #0x10000
 *   @0x2e56e8 str r3, [r4, #0x10]
 *   @0x2e56ec add sp, #0xc
 *   @0x2e56f0 .word 0xf04f8ff0
 *   @0x2e56f4 strbmi r0, [r10], r0, lsl #18
 *   @0x2e56f8 b 0x2e560e <FT_Request_Metrics+0x86>
 *
 * ══ §49/81 CFontGM::LoadFromChunk(YYFont*, unsigned char*)  0xf7bc4  size 368  92 条（0xf7bc4..0xf7d34）
 * @func 0xf7bc4 0xf7d34  size 368  92 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xf7be4→0x544c44, 0xf7ca8→0x544c44, 0xf7ce0→0x544c44
 * 调用序列: CFontGM::Clear() / operator new[](unsigned int) / YYStrDup(char const*) / CFontGM::LoadFromChunk(YYFont*, unsigned char*)+0x160
 * 字段偏移 top8: 0x18×3 / 0x28×3 / 0x2c×3 / 0x44×3 / 0x1c×2 / 0xc×2 / 0x8×2 / 0x48×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf7bc4 push {r4, r5, r6, r7, r8, lr}
 *   @0xf7bc8 mov r6, r1
 *   @0xf7bcc mov r4, r0
 *   @0xf7bd0 bl 0xf70a0 <_ZN7CFontGM5ClearEv>
 *   @0xf7bd4 ldr r2, [r6, #0x1c]
 *   @0xf7bd8 ldr r7, [pc, #0x14c]
 *   @0xf7bdc cmp r2, #0
 *   @0xf7be0 add r7, pc, r7
 *   @0xf7be4 ldrne r3, [pc, #0x144]
 *   @0xf7be8 ldrne r3, [r7, r3]
 *   @0xf7bec ldrne r3, [r3]
 *   @0xf7bf0 addne r2, r3, r2
 *   @0xf7bf4 ldr lr, [r6, #0xc]
 *   @0xf7bf8 ldr r12, [r6, #0x10]
 *   @0xf7bfc adds lr, lr, #0
 *   @0xf7c00 ldr r3, [r6, #0x14]
 *   @0xf7c04 ldr r0, [r6, #0x8]
 *   @0xf7c08 movne lr, #1
 *   @0xf7c0c adds r12, r12, #0
 *   @0xf7c10 ubfx r1, r3, #0x10, #0x8
 *   @0xf7c14 str r2, [r4, #0x3c]
 *   @0xf7c18 movne r12, #1
 *   @0xf7c1c cmp r1, #0
 *   @0xf7c20 strne r1, [r4, #0x10]
 *   @0xf7c24 lsrs r1, r3, #24
 *   @0xf7c28 subne r1, r1, #1
 *   @0xf7c2c strne r1, [r4, #0x14]
 *   @0xf7c30 cmp r2, #0
 *   @0xf7c34 ldr r1, [r6, #0x18]
 *   @0xf7c38 str r3, [r4, #0x18]
 *   @0xf7c3c uxth r3, r3
 *   @0xf7c40 str r3, [r4, #0x18]
 *   @0xf7c44 ldrshne r3, [r2, #4]
 *   @0xf7c48 ldrshne r2, [r2, #6]
 *   @0xf7c4c str r0, [r4, #0x8]
 *   @0xf7c50 ldr r0, [r6, #0x28]
 *   @0xf7c54 streq r2, [r4, #0x24]
 *   @0xf7c58 strne r3, [r4, #0x24]
 *   @0xf7c5c cmp r0, #532676608
 *   @0xf7c60 ldr r3, [r6, #0x20]
 *   @0xf7c64 str r2, [r4, #0x28]
 *   @0xf7c68 ldr r2, [r6, #0x24]
 *   @0xf7c6c str r3, [r4, #0x48]
 *   @0xf7c70 mov r3, #0
 *   @0xf7c74 str r0, [r4, #0x40]
 *   @0xf7c78 lslls r0, r0, #2
 *   @0xf7c7c str r3, [r4, #0x2c]
 *   @0xf7c80 mvnhi r0, #0
 *   @0xf7c84 strb lr, [r4, #0xc]
 *   @0xf7c88 strb r12, [r4, #0xd]
 *   @0xf7c8c str r1, [r4, #0x1c]
 *   @0xf7c90 str r2, [r4, #0x4c]
 *   @0xf7c94 bl 0x27d14c <_Znaj>
 *   @0xf7c98 ldr r3, [r6, #0x4]
 *   @0xf7c9c cmp r3, #0
 *   @0xf7ca0 str r0, [r4, #0x44]
 *   @0xf7ca4 moveq r0, r3
 *   @0xf7ca8 ldrne r2, [pc, #0x80]
 *   @0xf7cac ldrne r2, [r7, r2]
 *   @0xf7cb0 ldrne r0, [r2]
 *   @0xf7cb4 addne r0, r0, r3
 *   @0xf7cb8 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xf7cbc ldr r8, [r6, #0x28]
 *   @0xf7cc0 cmp r8, #0
 *   @0xf7cc4 str r0, [r4, #0x4]
 *   @0xf7cc8 ble 0xf7d24 <_ZN7CFontGM13LoadFromChunkEP6YYFontPh+0x160>
 *   @0xf7ccc ldr r0, [r4, #0x44]
 *   @0xf7cd0 add r8, r6, r8, lsl #2
 *   @0xf7cd4 mov r3, r6
 *   @0xf7cd8 ldr r2, [r3, #0x2c]
 *   @0xf7cdc rsb r12, r6, r3
 *   @0xf7ce0 ldr r1, [pc, #0x48]
 *   @0xf7ce4 add r0, r0, r12
 *   @0xf7ce8 cmp r2, #0
 *   @0xf7cec add r3, r3, #4
 *   @0xf7cf0 mov r5, r2
 *   @0xf7cf4 ldrne r1, [r7, r1]
 *   @0xf7cf8 ldrne r5, [r1]
 *   @0xf7cfc ldr r1, [r4, #0x2c]
 *   @0xf7d00 addne r5, r5, r2
 *   @0xf7d04 str r5, [r0]
 *   @0xf7d08 ldr r0, [r4, #0x44]
 *   @0xf7d0c ldr r2, [r0, r12]
 *   @0xf7d10 ldrsh r2, [r2, #8]
 *   @0xf7d14 cmp r1, r2
 *   @0xf7d18 strlt r2, [r4, #0x2c]
 *   @0xf7d1c cmp r3, r8
 *   @0xf7d20 bne 0xf7cd8 <_ZN7CFontGM13LoadFromChunkEP6YYFontPh+0x114>
 *   @0xf7d24 mov r0, #1
 *   @0xf7d28 pop {r4, r5, r6, r7, r8, pc}
 *   @0xf7d2c eoreq r10, pc, r0, ror r0
 *   @0xf7d30 .word 0xffffbcf4
 *
 * ══ §50/81 Font_Add(char const*, int, bool, bool, int, int)  0xfa43c  size 368  92 条（0xfa43c..0xfa5ac）
 * @func 0xfa43c 0xfa5ac  size 368  92 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xfa458→0x483680, 0xfa45c→0x483688, 0xfa490→0x483684, 0xfa55c→0x483684
 * 调用序列: MemoryManager::SetLength(void**, unsigned int, char const*, int)×2 / operator new(unsigned int) / CFontGM::CFontGM(char const*, int, bool, bool, int, int) / 0xb65c8 / YYStrDup(char const*) / 0xb65d4
 * 字段偏移 top8: 0x138×2 / 0x14×2 / 0x11c×2 / 0x4×2 / 0x2×2 / 0x144×1 / 0x140×1 / 0x108×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfa43c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xfa440 mov r10, r0
 *   @0xfa444 ldr r5, [pc, #0x144]
 *   @0xfa448 mov r9, r1
 *   @0xfa44c ldr r0, [pc, #0x140]
 *   @0xfa450 mov r8, r2
 *   @0xfa454 add r5, pc, r5
 *   @0xfa458 ldr r2, [pc, #0x138]
 *   @0xfa45c ldr r1, [pc, #0x138]
 *   @0xfa460 mov r11, r3
 *   @0xfa464 ldr r0, [r5, r0]
 *   @0xfa468 sub sp, sp, #292
 *   @0xfa46c ldr r3, [r0]
 *   @0xfa470 str r0, [sp, #0x14]
 *   @0xfa474 str r3, [sp, #0x11c]
 *   @0xfa478 ldr r4, [r5, r2]
 *   @0xfa47c ldr r6, [r5, r1]
 *   @0xfa480 ldr r3, [r4]
 *   @0xfa484 ldr r2, [r6]
 *   @0xfa488 cmp r2, r3
 *   @0xfa48c beq 0xfa538 <_Z8Font_AddPKcibbii+0xfc>
 *   @0xfa490 ldr r2, [pc, #0x108]
 *   @0xfa494 ldr r5, [r5, r2]
 *   @0xfa498 mov r0, #144
 *   @0xfa49c add r3, r3, #1
 *   @0xfa4a0 str r3, [r4]
 *   @0xfa4a4 bl 0x27c524 <_Znwj>
 *   @0xfa4a8 ldr r3, [sp, #0x148]
 *   @0xfa4ac mov r1, r10
 *   @0xfa4b0 mov r2, r9
 *   @0xfa4b4 str r11, [sp]
 *   @0xfa4b8 str r3, [sp, #0x4]
 *   @0xfa4bc ldr r3, [sp, #0x14c]
 *   @0xfa4c0 str r3, [sp, #0x8]
 *   @0xfa4c4 mov r3, r8
 *   @0xfa4c8 mov r7, r0
 *   @0xfa4cc bl 0xf9e08 <_ZN7CFontGMC2EPKcibbii>
 *   @0xfa4d0 ldr r3, [r4]
 *   @0xfa4d4 mov r1, #256
 *   @0xfa4d8 ldr r2, [r6, #0x4]
 *   @0xfa4dc add r6, sp, #28
 *   @0xfa4e0 sub lr, r3, #-1073741823
 *   @0xfa4e4 sub r3, r3, #1
 *   @0xfa4e8 mov r0, r6
 *   @0xfa4ec str r7, [r2, lr, lsl #2]
 *   @0xfa4f0 ldr r2, [pc, #0xac]
 *   @0xfa4f4 add r2, pc, r2
 *   @0xfa4f8 bl 0xb65c8 <snprintf@plt>
 *   @0xfa4fc ldr r3, [r4]
 *   @0xfa500 mov r0, r6
 *   @0xfa504 ldr r5, [r5]
 *   @0xfa508 sub r6, r3, #-1073741823
 *   @0xfa50c bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xfa510 ldr r1, [sp, #0x14]
 *   @0xfa514 ldr r3, [r4]
 *   @0xfa518 ldr r2, [sp, #0x11c]
 *   @0xfa51c str r0, [r5, r6, lsl #2]
 *   @0xfa520 sub r0, r3, #1
 *   @0xfa524 ldr r3, [r1]
 *   @0xfa528 cmp r2, r3
 *   @0xfa52c bne 0xfa58c <_Z8Font_AddPKcibbii+0x150>
 *   @0xfa530 add sp, sp, #292
 *   @0xfa534 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xfa538 ldr r12, [pc, #0x68]
 *   @0xfa53c add r1, r2, #5
 *   @0xfa540 add r0, r6, #4
 *   @0xfa544 movw r3, #0x101
 *   @0xfa548 add r12, pc, r12
 *   @0xfa54c lsl r1, r1, #2
 *   @0xfa550 mov r2, r12
 *   @0xfa554 mov r7, r12
 *   @0xfa558 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xfa55c ldr r0, [pc, #0x3c]
 *   @0xfa560 ldr r1, [r4]
 *   @0xfa564 movw r3, #0x103
 *   @0xfa568 mov r2, r7
 *   @0xfa56c add r1, r1, #5
 *   @0xfa570 str r1, [r6]
 *   @0xfa574 ldr r5, [r5, r0]
 *   @0xfa578 lsl r1, r1, #2
 *   @0xfa57c mov r0, r5
 *   @0xfa580 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xfa584 ldr r3, [r4]
 *   @0xfa588 b 0xfa498 <_Z8Font_AddPKcibbii+0x5c>
 *   @0xfa58c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0xfa590 .word 0x002f77fc
 *   @0xfa594 .word 0xffffbd00
 *   @0xfa598 .word 0xffffc210
 *   @0xfa59c .word 0xffffc20c
 *   @0xfa5a0 .word 0xffffc214
 *   @0xfa5a4 mlaeq r3, r12, r6, sp
 *   @0xfa5a8 eoreq sp, r3, r4, lsl r6
 *
 * ══ §51/81 F_DateDateTimeString(RValue&, CInstance*, CInstance*, int, RValue*)  0x117258  size 368  92 条（0x117258..0x1173c8）
 * @func 0x117258 0x1173dc  size 388  97 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb679c×2 / YYGetReal(RValue const*, int) / __fixdfdi / 0xb6820 / 0xb6838 / YYCreateString(RValue*, char const*) / 0xb682c / 0xb65d4
 * 字段偏移 top8: 0x40c×2 / 0x148×1 / 0xc×1 / 0x428×1 / 0xe8×1 / 0xb4×1 / 0xa4×1 / 0x90×1
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x117258 push {r4, r5, r6, r7, lr}
 *   @0x11725c mov r5, r0
 *   @0x117260 ldr r4, [pc, #0x148]
 *   @0x117264 sub sp, sp, #1040
 *   @0x117268 sub sp, sp, #4
 *   @0x11726c mov r3, #1
 *   @0x117270 ldr r4, [pc, r4]
 *   @0x117274 str r3, [r5, #0xc]
 *   @0x117278 ldr r0, [sp, #0x428]
 *   @0x11727c mov r1, #0
 *   @0x117280 ldr r3, [r4]
 *   @0x117284 str r3, [sp, #0x40c]
 *   @0x117288 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x11728c vldr d7, [pc, #260]
 *   @0x117290 vldr d5, [pc, #264]
 *   @0x117294 vmov d6, r0, r1
 *   @0x117298 vsub.f64 d7, d6, d7
 *   @0x11729c vabs.f64 d4, d7
 *   @0x1172a0 vcmpe.f64 d4, d5
 *   @0x1172a4 vmrs APSR_nzcv, fpscr
 *   @0x1172a8 vldrls d7, [pc, #248]
 *   @0x1172ac vldrhi d6, [pc, #244]
 *   @0x1172b0 vmul.f64 d5, d7, d6
 *   @0x1172b4 vmov r0, r1, d5
 *   @0x1172b8 bl 0x3194a0 <__fixdfdi>
 *   @0x1172bc add r12, sp, #1040
 *   @0x1172c0 mov r2, r0
 *   @0x1172c4 ldr r0, [pc, #0xe8]
 *   @0x1172c8 mov r3, r1
 *   @0x1172cc movw r1, #0xfbf0
 *   @0x1172d0 add r0, pc, r0
 *   @0x1172d4 movt r1, #0xffff
 *   @0x1172d8 ldrb r0, [r0]
 *   @0x1172dc strd r2, r3, [r12, r1]
 *   @0x1172e0 cmp r0, #0
 *   @0x1172e4 mov r0, sp
 *   @0x1172e8 bne 0x117360 <_Z20F_DateDateTimeStringR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x1172ec bl 0xb6820 <gmtime64@plt>
 *   @0x1172f0 mov r7, r0
 *   @0x1172f4 cmp r7, #0
 *   @0x1172f8 beq 0x117370 <_Z20F_DateDateTimeStringR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x1172fc ldr r1, [pc, #0xb4]
 *   @0x117300 mov r0, #6
 *   @0x117304 add r6, sp, #12
 *   @0x117308 add r1, pc, r1
 *   @0x11730c bl 0xb679c <setlocale@plt>
 *   @0x117310 ldr r2, [pc, #0xa4]
 *   @0x117314 mov r1, #1024
 *   @0x117318 mov r3, r7
 *   @0x11731c add r2, pc, r2
 *   @0x117320 mov r0, r6
 *   @0x117324 bl 0xb6838 <strftime@plt>
 *   @0x117328 ldr r1, [pc, #0x90]
 *   @0x11732c mov r0, #6
 *   @0x117330 add r1, pc, r1
 *   @0x117334 bl 0xb679c <setlocale@plt>
 *   @0x117338 mov r0, r5
 *   @0x11733c mov r1, r6
 *   @0x117340 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x117344 ldr r2, [sp, #0x40c]
 *   @0x117348 ldr r3, [r4]
 *   @0x11734c cmp r2, r3
 *   @0x117350 bne 0x117390 <_Z20F_DateDateTimeStringR6RValueP9CInstanceS2_iPS_+0x138>
 *   @0x117354 add sp, sp, #1040
 *   @0x117358 add sp, sp, #4
 *   @0x11735c pop {r4, r5, r6, r7, pc}
 *   @0x117360 bl 0xb682c <localtime64@plt>
 *   @0x117364 mov r7, r0
 *   @0x117368 cmp r7, #0
 *   @0x11736c bne 0x1172fc <_Z20F_DateDateTimeStringR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x117370 ldr r3, [pc, #0x4c]
 *   @0x117374 add r6, sp, #12
 *   @0x117378 add r3, pc, r3
 *   @0x11737c mov r12, r6
 *   @0x117380 ldm r3, {r0, r1, r2, r3}
 *   @0x117384 stm r12!, {r0, r1, r2}
 *   @0x117388 strb r3, [r12]
 *   @0x11738c b 0x117338 <_Z20F_DateDateTimeStringR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x117390 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x117394 nop
 *   @0x117398 andeq r0, r0, r0
 *   @0x11739c sbcsmi pc, r8, r0, asr #16
 *   @0x1173a0 bl 0x82805c <b2_toiTime+0xcebb8>
 *   @0x1173a4 svclo #0x1a36e2
 *   @0x1173a8 andeq r0, r0, r0
 *   @0x1173ac rscsmi r1, r5, r0, lsl #16
 *   @0x1173b0 eoreq r6, sp, r0, ror #13
 *   @0x1173b4 eoreq r10, sp, r8, ror #28
 *   @0x1173b8 eoreq r7, r1, lr, lsr #16
 *   @0x1173bc eoreq r2, r2, r0, asr #9
 *   @0x1173c0 eoreq r1, r2, r0, ror sp
 *   @0x1173c4 eoreq r2, r2, r8, ror #8
 *
 * ══ §52/81 F_DateDateString(RValue&, CInstance*, CInstance*, int, RValue*)  0x1173c8  size 368  92 条（0x1173c8..0x117538）
 * @func 0x1173c8 0x11754c  size 388  97 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb679c×2 / YYGetReal(RValue const*, int) / __fixdfdi / 0xb6820 / 0xb6838 / YYCreateString(RValue*, char const*) / 0xb682c / 0xb65d4
 * 字段偏移 top8: 0x40c×2 / 0x148×1 / 0xc×1 / 0x428×1 / 0xe8×1 / 0xb4×1 / 0xa4×1 / 0x90×1
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1173c8 push {r4, r5, r6, r7, lr}
 *   @0x1173cc mov r5, r0
 *   @0x1173d0 ldr r4, [pc, #0x148]
 *   @0x1173d4 sub sp, sp, #1040
 *   @0x1173d8 sub sp, sp, #4
 *   @0x1173dc mov r3, #1
 *   @0x1173e0 ldr r4, [pc, r4]
 *   @0x1173e4 str r3, [r5, #0xc]
 *   @0x1173e8 ldr r0, [sp, #0x428]
 *   @0x1173ec mov r1, #0
 *   @0x1173f0 ldr r3, [r4]
 *   @0x1173f4 str r3, [sp, #0x40c]
 *   @0x1173f8 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1173fc vldr d7, [pc, #260]
 *   @0x117400 vldr d5, [pc, #264]
 *   @0x117404 vmov d6, r0, r1
 *   @0x117408 vsub.f64 d7, d6, d7
 *   @0x11740c vabs.f64 d4, d7
 *   @0x117410 vcmpe.f64 d4, d5
 *   @0x117414 vmrs APSR_nzcv, fpscr
 *   @0x117418 vldrls d7, [pc, #248]
 *   @0x11741c vldrhi d6, [pc, #244]
 *   @0x117420 vmul.f64 d5, d7, d6
 *   @0x117424 vmov r0, r1, d5
 *   @0x117428 bl 0x3194a0 <__fixdfdi>
 *   @0x11742c add r12, sp, #1040
 *   @0x117430 mov r2, r0
 *   @0x117434 ldr r0, [pc, #0xe8]
 *   @0x117438 mov r3, r1
 *   @0x11743c movw r1, #0xfbf0
 *   @0x117440 add r0, pc, r0
 *   @0x117444 movt r1, #0xffff
 *   @0x117448 ldrb r0, [r0]
 *   @0x11744c strd r2, r3, [r12, r1]
 *   @0x117450 cmp r0, #0
 *   @0x117454 mov r0, sp
 *   @0x117458 bne 0x1174d0 <_Z16F_DateDateStringR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x11745c bl 0xb6820 <gmtime64@plt>
 *   @0x117460 mov r7, r0
 *   @0x117464 cmp r7, #0
 *   @0x117468 beq 0x1174e0 <_Z16F_DateDateStringR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x11746c ldr r1, [pc, #0xb4]
 *   @0x117470 mov r0, #6
 *   @0x117474 add r6, sp, #12
 *   @0x117478 add r1, pc, r1
 *   @0x11747c bl 0xb679c <setlocale@plt>
 *   @0x117480 ldr r2, [pc, #0xa4]
 *   @0x117484 mov r1, #1024
 *   @0x117488 mov r3, r7
 *   @0x11748c add r2, pc, r2
 *   @0x117490 mov r0, r6
 *   @0x117494 bl 0xb6838 <strftime@plt>
 *   @0x117498 ldr r1, [pc, #0x90]
 *   @0x11749c mov r0, #6
 *   @0x1174a0 add r1, pc, r1
 *   @0x1174a4 bl 0xb679c <setlocale@plt>
 *   @0x1174a8 mov r0, r5
 *   @0x1174ac mov r1, r6
 *   @0x1174b0 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x1174b4 ldr r2, [sp, #0x40c]
 *   @0x1174b8 ldr r3, [r4]
 *   @0x1174bc cmp r2, r3
 *   @0x1174c0 bne 0x117500 <_Z16F_DateDateStringR6RValueP9CInstanceS2_iPS_+0x138>
 *   @0x1174c4 add sp, sp, #1040
 *   @0x1174c8 add sp, sp, #4
 *   @0x1174cc pop {r4, r5, r6, r7, pc}
 *   @0x1174d0 bl 0xb682c <localtime64@plt>
 *   @0x1174d4 mov r7, r0
 *   @0x1174d8 cmp r7, #0
 *   @0x1174dc bne 0x11746c <_Z16F_DateDateStringR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x1174e0 ldr r3, [pc, #0x4c]
 *   @0x1174e4 add r6, sp, #12
 *   @0x1174e8 add r3, pc, r3
 *   @0x1174ec mov r12, r6
 *   @0x1174f0 ldm r3, {r0, r1, r2, r3}
 *   @0x1174f4 stm r12!, {r0, r1, r2}
 *   @0x1174f8 strb r3, [r12]
 *   @0x1174fc b 0x1174a8 <_Z16F_DateDateStringR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x117500 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x117504 nop
 *   @0x117508 andeq r0, r0, r0
 *   @0x11750c sbcsmi pc, r8, r0, asr #16
 *   @0x117510 bl 0x8281cc <b2_toiTime+0xced28>
 *   @0x117514 svclo #0x1a36e2
 *   @0x117518 andeq r0, r0, r0
 *   @0x11751c rscsmi r1, r5, r0, lsl #16
 *   @0x117520 eoreq r6, sp, r0, ror r5
 *   @0x117524 .word 0x002dacf8
 *   @0x117528 .word 0x002176be
 *   @0x11752c eoreq r2, r2, r4, ror #6
 *   @0x117530 eoreq r1, r2, r0, lsl #24
 *   @0x117534 .word 0x002222f8
 *
 * ══ §53/81 F_DateTimeString(RValue&, CInstance*, CInstance*, int, RValue*)  0x117538  size 368  92 条（0x117538..0x1176a8）
 * @func 0x117538 0x1176a8  size 368  92 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb679c×2 / YYGetReal(RValue const*, int) / __fixdfdi / 0xb6820 / 0xb6838 / YYCreateString(RValue*, char const*) / 0xb682c / 0xb65d4
 * 字段偏移 top8: 0x40c×2 / 0x148×1 / 0xc×1 / 0x428×1 / 0xe8×1 / 0xb4×1 / 0xa4×1 / 0x90×1
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x117538 push {r4, r5, r6, r7, lr}
 *   @0x11753c mov r5, r0
 *   @0x117540 ldr r4, [pc, #0x148]
 *   @0x117544 sub sp, sp, #1040
 *   @0x117548 sub sp, sp, #4
 *   @0x11754c mov r3, #1
 *   @0x117550 ldr r4, [pc, r4]
 *   @0x117554 str r3, [r5, #0xc]
 *   @0x117558 ldr r0, [sp, #0x428]
 *   @0x11755c mov r1, #0
 *   @0x117560 ldr r3, [r4]
 *   @0x117564 str r3, [sp, #0x40c]
 *   @0x117568 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x11756c vldr d7, [pc, #260]
 *   @0x117570 vldr d5, [pc, #264]
 *   @0x117574 vmov d6, r0, r1
 *   @0x117578 vsub.f64 d7, d6, d7
 *   @0x11757c vabs.f64 d4, d7
 *   @0x117580 vcmpe.f64 d4, d5
 *   @0x117584 vmrs APSR_nzcv, fpscr
 *   @0x117588 vldrls d7, [pc, #248]
 *   @0x11758c vldrhi d6, [pc, #244]
 *   @0x117590 vmul.f64 d5, d7, d6
 *   @0x117594 vmov r0, r1, d5
 *   @0x117598 bl 0x3194a0 <__fixdfdi>
 *   @0x11759c add r12, sp, #1040
 *   @0x1175a0 mov r2, r0
 *   @0x1175a4 ldr r0, [pc, #0xe8]
 *   @0x1175a8 mov r3, r1
 *   @0x1175ac movw r1, #0xfbf0
 *   @0x1175b0 add r0, pc, r0
 *   @0x1175b4 movt r1, #0xffff
 *   @0x1175b8 ldrb r0, [r0]
 *   @0x1175bc strd r2, r3, [r12, r1]
 *   @0x1175c0 cmp r0, #0
 *   @0x1175c4 mov r0, sp
 *   @0x1175c8 bne 0x117640 <_Z16F_DateTimeStringR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x1175cc bl 0xb6820 <gmtime64@plt>
 *   @0x1175d0 mov r7, r0
 *   @0x1175d4 cmp r7, #0
 *   @0x1175d8 beq 0x117650 <_Z16F_DateTimeStringR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x1175dc ldr r1, [pc, #0xb4]
 *   @0x1175e0 mov r0, #6
 *   @0x1175e4 add r6, sp, #12
 *   @0x1175e8 add r1, pc, r1
 *   @0x1175ec bl 0xb679c <setlocale@plt>
 *   @0x1175f0 ldr r2, [pc, #0xa4]
 *   @0x1175f4 mov r1, #1024
 *   @0x1175f8 mov r3, r7
 *   @0x1175fc add r2, pc, r2
 *   @0x117600 mov r0, r6
 *   @0x117604 bl 0xb6838 <strftime@plt>
 *   @0x117608 ldr r1, [pc, #0x90]
 *   @0x11760c mov r0, #6
 *   @0x117610 add r1, pc, r1
 *   @0x117614 bl 0xb679c <setlocale@plt>
 *   @0x117618 mov r0, r5
 *   @0x11761c mov r1, r6
 *   @0x117620 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x117624 ldr r2, [sp, #0x40c]
 *   @0x117628 ldr r3, [r4]
 *   @0x11762c cmp r2, r3
 *   @0x117630 bne 0x117670 <_Z16F_DateTimeStringR6RValueP9CInstanceS2_iPS_+0x138>
 *   @0x117634 add sp, sp, #1040
 *   @0x117638 add sp, sp, #4
 *   @0x11763c pop {r4, r5, r6, r7, pc}
 *   @0x117640 bl 0xb682c <localtime64@plt>
 *   @0x117644 mov r7, r0
 *   @0x117648 cmp r7, #0
 *   @0x11764c bne 0x1175dc <_Z16F_DateTimeStringR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x117650 ldr r3, [pc, #0x4c]
 *   @0x117654 add r6, sp, #12
 *   @0x117658 add r3, pc, r3
 *   @0x11765c mov r12, r6
 *   @0x117660 ldm r3, {r0, r1, r2, r3}
 *   @0x117664 stm r12!, {r0, r1, r2}
 *   @0x117668 strb r3, [r12]
 *   @0x11766c b 0x117618 <_Z16F_DateTimeStringR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x117670 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x117674 nop
 *   @0x117678 andeq r0, r0, r0
 *   @0x11767c sbcsmi pc, r8, r0, asr #16
 *   @0x117680 bl 0x82833c <b2_toiTime+0xcee98>
 *   @0x117684 svclo #0x1a36e2
 *   @0x117688 andeq r0, r0, r0
 *   @0x11768c rscsmi r1, r5, r0, lsl #16
 *   @0x117690 eoreq r6, sp, r0, lsl #8
 *   @0x117694 eoreq r10, sp, r8, lsl #23
 *   @0x117698 eoreq r7, r1, lr, asr #10
 *   @0x11769c .word 0x002221f8
 *   @0x1176a0 mlaeq r2, r0, r10, r1
 *   @0x1176a4 eoreq r2, r2, r8, lsl #3
 *
 * ══ §54/81 GR_Draw_Line_Width(float, float, float, float, float)  0x16a2ec  size 368  92 条（0x16a2ec..0x16a45c）
 * @func 0x16a2ec 0x16a45c  size 368  92 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x16a338→0x4859c0, 0x16a358→0x3f23d8, 0x16a35c→0x3f23d4, 0x16a368→0x4859ac, 0x16a37c→0x3f23d0
 * 调用序列: Graphics::AllocVerts(ePrimType, void*, int, int) / 0xb6700
 * 字段偏移 top8: 0xec×2 / 0x140×1 / 0x108×1 / 0xe4×1 / 0xd4×1 / 0x8×1 / 0x18×1 / 0x28×1
 * VFP 指令 51 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16a2ec push {r4, lr}
 *   @0x16a2f0 vpush {d8, d9, d10}
 *   @0x16a2f4 vmov s18, r1
 *   @0x16a2f8 vmov s17, r3
 *   @0x16a2fc ldr r4, [pc, #0x140]
 *   @0x16a300 vmov s20, r0
 *   @0x16a304 vsub.f32 s15, s17, s18
 *   @0x16a308 add r4, pc, r4
 *   @0x16a30c vmov s19, r2
 *   @0x16a310 vmul.f32 s15, s15, s15
 *   @0x16a314 vsub.f32 s14, s19, s20
 *   @0x16a318 vmla.f32 s15, s14, s14
 *   @0x16a31c vsqrt.f32 s16, s15
 *   @0x16a320 vcmp.f32 s16, s16
 *   @0x16a324 vmrs APSR_nzcv, fpscr
 *   @0x16a328 bne 0x16a430 <_Z18GR_Draw_Line_Widthfffff+0x144>
 *   @0x16a32c vcmp.f32 s16, #0
 *   @0x16a330 vmrs APSR_nzcv, fpscr
 *   @0x16a334 beq 0x16a428 <_Z18GR_Draw_Line_Widthfffff+0x13c>
 *   @0x16a338 ldr r1, [pc, #0x108]
 *   @0x16a33c mov r2, #16
 *   @0x16a340 mov r3, #4
 *   @0x16a344 mov r0, #6
 *   @0x16a348 ldr r1, [r4, r1]
 *   @0x16a34c ldr r1, [r1]
 *   @0x16a350 ldr r1, [r1]
 *   @0x16a354 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x16a358 ldr r1, [pc, #0xec]
 *   @0x16a35c ldr r2, [pc, #0xec]
 *   @0x16a360 vldr s13, [pc, #216]
 *   @0x16a364 vmov.f32 s14, #5.000000e-01
 *   @0x16a368 ldr r3, [pc, #0xe4]
 *   @0x16a36c ldr r1, [r4, r1]
 *   @0x16a370 vldr s15, [r1]
 *   @0x16a374 ldr r2, [r4, r2]
 *   @0x16a378 vldr s12, [r2]
 *   @0x16a37c ldr r2, [pc, #0xd4]
 *   @0x16a380 vmul.f32 s15, s15, s13
 *   @0x16a384 vmul.f32 s13, s12, s13
 *   @0x16a388 vadd.f32 s20, s15, s20
 *   @0x16a38c vadd.f32 s19, s19, s15
 *   @0x16a390 vldr s15, [sp, #32]
 *   @0x16a394 vadd.f32 s18, s13, s18
 *   @0x16a398 vadd.f32 s17, s17, s13
 *   @0x16a39c vmul.f32 s14, s15, s14
 *   @0x16a3a0 vsub.f32 s13, s19, s20
 *   @0x16a3a4 vsub.f32 s15, s17, s18
 *   @0x16a3a8 vmul.f32 s15, s14, s15
 *   @0x16a3ac vmul.f32 s14, s14, s13
 *   @0x16a3b0 vdiv.f32 s15, s15, s16
 *   @0x16a3b4 vdiv.f32 s16, s14, s16
 *   @0x16a3b8 vadd.f32 s14, s18, s16
 *   @0x16a3bc vsub.f32 s13, s20, s15
 *   @0x16a3c0 vstr s14, [r0, #4]
 *   @0x16a3c4 vsub.f32 s14, s19, s15
 *   @0x16a3c8 vstr s13, [r0]
 *   @0x16a3cc ldr r3, [r4, r3]
 *   @0x16a3d0 ldr r3, [r3]
 *   @0x16a3d4 str r3, [r0, #0x8]
 *   @0x16a3d8 ldr r2, [r4, r2]
 *   @0x16a3dc str r3, [r0, #0x18]
 *   @0x16a3e0 vsub.f32 s18, s18, s16
 *   @0x16a3e4 vstr s14, [r0, #16]
 *   @0x16a3e8 str r3, [r0, #0x28]
 *   @0x16a3ec str r3, [r0, #0x38]
 *   @0x16a3f0 ldr r3, [r2]
 *   @0x16a3f4 str r3, [r0, #0xc]
 *   @0x16a3f8 str r3, [r0, #0x1c]
 *   @0x16a3fc str r3, [r0, #0x2c]
 *   @0x16a400 str r3, [r0, #0x3c]
 *   @0x16a404 vadd.f32 s14, s17, s16
 *   @0x16a408 vstr s18, [r0, #52]
 *   @0x16a40c vadd.f32 s20, s20, s15
 *   @0x16a410 vstr s14, [r0, #20]
 *   @0x16a414 vadd.f32 s19, s19, s15
 *   @0x16a418 vstr s20, [r0, #48]
 *   @0x16a41c vsub.f32 s16, s17, s16
 *   @0x16a420 vstr s19, [r0, #32]
 *   @0x16a424 vstr s16, [r0, #36]
 *   @0x16a428 vpop {d8, d9, d10}
 *   @0x16a42c pop {r4, pc}
 *   @0x16a430 vmov r0, s15
 *   @0x16a434 bl 0xb6700 <sqrtf@plt>
 *   @0x16a438 vmov s16, r0
 *   @0x16a43c b 0x16a32c <_Z18GR_Draw_Line_Widthfffff+0x40>
 *   @0x16a440 stclo p7, c13, [r3], #-40
 *   @0x16a444 eoreq r7, r8, r8, asr #18
 *   @0x16a448 .word 0xffffe4e0
 *   @0x16a44c .word 0xffffe524
 *   @0x16a450 .word 0xffffe520
 *   @0x16a454 .word 0xffffbcd0
 *   @0x16a458 .word 0xffffc0ac
 *
 * ══ §55/81 HandleJoy(int)  0x1d6550  size 368  92 条（0x1d6550..0x1d66c0）
 * @func 0x1d6550 0x1d66c0  size 368  92 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1d6554→0x536f20, 0x1d655c→0x536f70, 0x1d6598→0x53ab70, 0x1d65a0→0x542374
 * 调用序列: HandleJoy(int)+0x154 / HandleJoy(int)+0x134 / Perform_Event(CInstance*, CInstance*, int, int)
 * 字段偏移 top8: 0x4×5 / 0x8×4 / 0x2×3 / 0x154×2 / 0x14×2 / 0x10×2 / 0x150×1 / 0x118×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d6550 ldr r1, [pc, #0x154]
 *   @0x1d6554 ldr r3, [pc, #0x154]
 *   @0x1d6558 add r1, pc, r1
 *   @0x1d655c ldr r12, [pc, #0x150]
 *   @0x1d6560 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1d6564 add r9, r0, #1536
 *   @0x1d6568 mov r8, r0
 *   @0x1d656c ldr r0, [r1, r3]
 *   @0x1d6570 sub sp, sp, #28
 *   @0x1d6574 ldrd r10, r11, [r0]
 *   @0x1d6578 adds r2, r10, #1
 *   @0x1d657c adc r3, r11, #0
 *   @0x1d6580 strd r10, r11, [sp, #8]
 *   @0x1d6584 strd r2, r3, [r0]
 *   @0x1d6588 ldr r11, [r1, r12]
 *   @0x1d658c ldr r3, [r11, r9, lsl #2]
 *   @0x1d6590 cmp r3, #0
 *   @0x1d6594 ble 0x1d66a4 <_Z9HandleJoyi+0x154>
 *   @0x1d6598 ldr r2, [pc, #0x118]
 *   @0x1d659c mov r7, #0
 *   @0x1d65a0 ldr r3, [pc, #0x114]
 *   @0x1d65a4 ldr r10, [r1, r2]
 *   @0x1d65a8 ldr r3, [r1, r3]
 *   @0x1d65ac add r10, r10, r9, lsl #3
 *   @0x1d65b0 str r3, [sp, #0x14]
 *   @0x1d65b4 mov r3, r10
 *   @0x1d65b8 mov r10, r11
 *   @0x1d65bc mov r11, r3
 *   @0x1d65c0 ldr r12, [sp, #0x14]
 *   @0x1d65c4 ldr r1, [r11, #0x4]
 *   @0x1d65c8 ldr r3, [r12]
 *   @0x1d65cc ldr r1, [r1, r7, lsl #2]
 *   @0x1d65d0 ldr r2, [r3, #0x4]
 *   @0x1d65d4 ldr r3, [r3]
 *   @0x1d65d8 and r2, r1, r2
 *   @0x1d65dc ldr r3, [r3, r2, lsl #3]
 *   @0x1d65e0 cmp r3, #0
 *   @0x1d65e4 bne 0x1d65f8 <_Z9HandleJoyi+0xa8>
 *   @0x1d65e8 b 0x1d6694 <_Z9HandleJoyi+0x144>
 *   @0x1d65ec ldr r3, [r3, #0x4]
 *   @0x1d65f0 cmp r3, #0
 *   @0x1d65f4 beq 0x1d6694 <_Z9HandleJoyi+0x144>
 *   @0x1d65f8 ldr r2, [r3, #0x8]
 *   @0x1d65fc cmp r1, r2
 *   @0x1d6600 bne 0x1d65ec <_Z9HandleJoyi+0x9c>
 *   @0x1d6604 ldr r3, [r3, #0xc]
 *   @0x1d6608 cmp r3, #0
 *   @0x1d660c beq 0x1d6694 <_Z9HandleJoyi+0x144>
 *   @0x1d6610 ldr r6, [r3, #0xc4]
 *   @0x1d6614 cmp r6, #0
 *   @0x1d6618 beq 0x1d6694 <_Z9HandleJoyi+0x144>
 *   @0x1d661c ldr r3, [r6, #0x8]
 *   @0x1d6620 cmp r3, #0
 *   @0x1d6624 beq 0x1d6694 <_Z9HandleJoyi+0x144>
 *   @0x1d6628 str r10, [sp, #0x10]
 *   @0x1d662c str r11, [sp, #0x4]
 *   @0x1d6630 b 0x1d6640 <_Z9HandleJoyi+0xf0>
 *   @0x1d6634 ldr r3, [r6, #0x8]
 *   @0x1d6638 cmp r3, #0
 *   @0x1d663c beq 0x1d668c <_Z9HandleJoyi+0x13c>
 *   @0x1d6640 ldr r0, [r6, #0x8]
 *   @0x1d6644 ldr r6, [r6]
 *   @0x1d6648 ldrb r3, [r0, #0x68]
 *   @0x1d664c cmp r3, #0
 *   @0x1d6650 bne 0x1d6684 <_Z9HandleJoyi+0x134>
 *   @0x1d6654 ldrb r3, [r0, #0x69]
 *   @0x1d6658 cmp r3, #0
 *   @0x1d665c bne 0x1d6684 <_Z9HandleJoyi+0x134>
 *   @0x1d6660 ldrd r4, r5, [r0, #112]
 *   @0x1d6664 mov r1, r0
 *   @0x1d6668 ldrd r10, r11, [sp, #8]
 *   @0x1d666c mov r2, #6
 *   @0x1d6670 mov r3, r8
 *   @0x1d6674 cmp r10, r4
 *   @0x1d6678 sbcs r11, r11, r5
 *   @0x1d667c blt 0x1d6684 <_Z9HandleJoyi+0x134>
 *   @0x1d6680 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0x1d6684 cmp r6, #0
 *   @0x1d6688 bne 0x1d6634 <_Z9HandleJoyi+0xe4>
 *   @0x1d668c ldr r10, [sp, #0x10]
 *   @0x1d6690 ldr r11, [sp, #0x4]
 *   @0x1d6694 ldr r3, [r10, r9, lsl #2]
 *   @0x1d6698 add r7, r7, #1
 *   @0x1d669c cmp r3, r7
 *   @0x1d66a0 bgt 0x1d65c0 <_Z9HandleJoyi+0x70>
 *   @0x1d66a4 add sp, sp, #28
 *   @0x1d66a8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1d66ac .word 0x0021b6f8
 *   @0x1d66b0 .word 0xffffdeb4
 *   @0x1d66b4 .word 0xffffdeb8
 *   @0x1d66b8 .word 0xffffdebc
 *   @0x1d66bc .word 0xffffbfec
 *
 * ══ §56/81 CSprite::CreateFromBitmap(IBitmap*, bool, bool, bool, bool, int, int, bool)  0x1e74ac  size 368  92 条（0x1e74ac..0x1e761c）
 * @func 0x1e74ac 0x1e761c  size 368  92 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int)×2 / CSprite::Clear() / MemoryManager::SetLength(void**, unsigned int, char const*, int) / CBitmap32::CBitmap32(IBitmap*, bool, bool, int) / CSprite::InitTexture() / CSprite::InitLocalTPE() / CSprite::ComputeBoundingBox() / CBitmap32::CBitmap32(IBitmap*, bool, bool)
 * 字段偏移 top8: 0x48×4 / 0x10×3 / 0x33×3 / 0x4×3 / 0x32×3 / 0x5c×2 / 0x44×2 / 0xc×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e74ac push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1e74b0 sub sp, sp, #28
 *   @0x1e74b4 mov r5, r1
 *   @0x1e74b8 mov r10, r2
 *   @0x1e74bc ldr r1, [r0, #0x5c]
 *   @0x1e74c0 mov r4, r0
 *   @0x1e74c4 ldrb r2, [sp, #0x40]
 *   @0x1e74c8 mov r6, #1
 *   @0x1e74cc str r3, [sp, #0x10]
 *   @0x1e74d0 ldrb r11, [sp, #0x44]
 *   @0x1e74d4 str r2, [sp, #0xc]
 *   @0x1e74d8 ldr r9, [sp, #0x48]
 *   @0x1e74dc ldr r8, [sp, #0x4c]
 *   @0x1e74e0 ldrb r7, [sp, #0x50]
 *   @0x1e74e4 str r1, [sp, #0x14]
 *   @0x1e74e8 bl 0x1e6b4c <_ZN7CSprite5ClearEv>
 *   @0x1e74ec ldr r12, [r5]
 *   @0x1e74f0 mov r0, r5
 *   @0x1e74f4 ldr r1, [sp, #0x14]
 *   @0x1e74f8 str r6, [r4, #0x18]
 *   @0x1e74fc str r1, [r4, #0x5c]
 *   @0x1e7500 ldr r1, [r12, #0x10]
 *   @0x1e7504 blx r1
 *   @0x1e7508 ldr r1, [r5]
 *   @0x1e750c ldr r1, [r1, #0x18]
 *   @0x1e7510 str r0, [r4, #0x1c]
 *   @0x1e7514 mov r0, r5
 *   @0x1e7518 blx r1
 *   @0x1e751c ldr r2, [sp, #0xc]
 *   @0x1e7520 ldr r3, [sp, #0x10]
 *   @0x1e7524 mov r1, #4
 *   @0x1e7528 strb r11, [r4, #0x34]
 *   @0x1e752c strb r2, [r4, #0x33]
 *   @0x1e7530 mov r2, #0
 *   @0x1e7534 str r2, [r4, #0x4]
 *   @0x1e7538 ldr r2, [pc, #0xd8]
 *   @0x1e753c strb r3, [r4, #0x32]
 *   @0x1e7540 movw r3, #0x62c
 *   @0x1e7544 strb r10, [r4, #0x30]
 *   @0x1e7548 add r2, pc, r2
 *   @0x1e754c str r9, [r4, #0x24]
 *   @0x1e7550 str r8, [r4, #0x28]
 *   @0x1e7554 str r0, [r4, #0x20]
 *   @0x1e7558 add r0, r4, #72
 *   @0x1e755c bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1e7560 ldr r3, [r4, #0x48]
 *   @0x1e7564 cmp r7, #0
 *   @0x1e7568 str r6, [r4, #0x44]
 *   @0x1e756c ldr r0, [r3]
 *   @0x1e7570 beq 0x1e75dc <_ZN7CSprite16CreateFromBitmapEP7IBitmapbbbbiib+0x130>
 *   @0x1e7574 cmp r0, #0
 *   @0x1e7578 beq 0x1e7588 <_ZN7CSprite16CreateFromBitmapEP7IBitmapbbbbiib+0xdc>
 *   @0x1e757c ldr r3, [r0]
 *   @0x1e7580 ldr r3, [r3, #0x4]
 *   @0x1e7584 blx r3
 *   @0x1e7588 mov r0, #24
 *   @0x1e758c bl 0x27c524 <_Znwj>
 *   @0x1e7590 ldrb r3, [r4, #0x33]
 *   @0x1e7594 ldrb r2, [r4, #0x32]
 *   @0x1e7598 mov r12, #0
 *   @0x1e759c mov r1, r5
 *   @0x1e75a0 str r12, [sp]
 *   @0x1e75a4 mov r6, r0
 *   @0x1e75a8 bl 0x166fd0 <_ZN9CBitmap32C2EP7IBitmapbbi>
 *   @0x1e75ac ldr r3, [r4, #0x48]
 *   @0x1e75b0 str r6, [r3]
 *   @0x1e75b4 mov r0, r4
 *   @0x1e75b8 bl 0x1e5748 <_ZN7CSprite11InitTextureEv>
 *   @0x1e75bc mov r0, r4
 *   @0x1e75c0 bl 0x1e5854 <_ZN7CSprite12InitLocalTPEEv>
 *   @0x1e75c4 mov r0, r4
 *   @0x1e75c8 bl 0x1e3320 <_ZN7CSprite18ComputeBoundingBoxEv>
 *   @0x1e75cc mov r0, r4
 *   @0x1e75d0 add sp, sp, #28
 *   @0x1e75d4 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1e75d8 b 0x1e3bcc <_ZN7CSprite10CreateMaskEv>
 *   @0x1e75dc cmp r0, #0
 *   @0x1e75e0 beq 0x1e75f0 <_ZN7CSprite16CreateFromBitmapEP7IBitmapbbbbiib+0x144>
 *   @0x1e75e4 ldr r3, [r0]
 *   @0x1e75e8 ldr r3, [r3, #0x4]
 *   @0x1e75ec blx r3
 *   @0x1e75f0 mov r0, #24
 *   @0x1e75f4 bl 0x27c524 <_Znwj>
 *   @0x1e75f8 ldrb r3, [r4, #0x33]
 *   @0x1e75fc mov r1, r5
 *   @0x1e7600 ldrb r2, [r4, #0x32]
 *   @0x1e7604 mov r6, r0
 *   @0x1e7608 bl 0x166e70 <_ZN9CBitmap32C2EP7IBitmapbb>
 *   @0x1e760c ldr r3, [r4, #0x48]
 *   @0x1e7610 str r6, [r3]
 *   @0x1e7614 b 0x1e75b4 <_ZN7CSprite16CreateFromBitmapEP7IBitmapbbbbiib+0x108>
 *   @0x1e7618 ldrsbeq r10, [r6], -r12
 *
 * ══ §57/81 Sprite_Replace_Alpha(int, char const*, int, bool, bool, int, int)  0x1ef07c  size 368  92 条（0x1ef07c..0x1ef1ec）
 * @func 0x1ef07c 0x1ef1ec  size 368  92 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1ef0b8→0x7530d8, 0x1ef120→0x7530d0, 0x1ef174→0x7530dc
 * 调用序列: Sprite_Replace_Alpha(int, char const*, int, bool, bool, int, int)+0x50 / Sprite_Replace_Alpha(int, char const*, int, bool, bool, int, int)+0x70 / LoadSave::SaveFileExists(char const*) / LoadSave::BundleFileExists(char const*) / LoadSave::_GetBundleFileName(char*, int, char const*) / CSprite::LoadFromFile(char const*, int, bool, bool, bool, bool, int, int, bool) / LoadSave::_GetSaveFileName(char*, int, char const*) / operator new(unsigned int)
 * 字段偏移 top8: 0x4×5 / 0x2×5 / 0x424×2 / 0x1c×2 / 0x14c×1 / 0x148×1 / 0x450×1 / 0x120×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1ef07c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1ef080 sub sp, sp, #1056
 *   @0x1ef084 ldr r4, [pc, #0x14c]
 *   @0x1ef088 sub sp, sp, #12
 *   @0x1ef08c ldr r12, [pc, #0x148]
 *   @0x1ef090 subs r6, r0, #0
 *   @0x1ef094 add r4, pc, r4
 *   @0x1ef098 mov r7, r1
 *   @0x1ef09c mov r8, r2
 *   @0x1ef0a0 mov r9, r3
 *   @0x1ef0a4 ldr r5, [r4, r12]
 *   @0x1ef0a8 ldrb r10, [sp, #0x450]
 *   @0x1ef0ac ldr r12, [r5]
 *   @0x1ef0b0 str r12, [sp, #0x424]
 *   @0x1ef0b4 blt 0x1ef0cc <_Z20Sprite_Replace_AlphaiPKcibbii+0x50>
 *   @0x1ef0b8 ldr r3, [pc, #0x120]
 *   @0x1ef0bc ldr r3, [r4, r3]
 *   @0x1ef0c0 ldr r3, [r3]
 *   @0x1ef0c4 cmp r6, r3
 *   @0x1ef0c8 blt 0x1ef0ec <_Z20Sprite_Replace_AlphaiPKcibbii+0x70>
 *   @0x1ef0cc mov r0, #0
 *   @0x1ef0d0 ldr r2, [sp, #0x424]
 *   @0x1ef0d4 ldr r3, [r5]
 *   @0x1ef0d8 cmp r2, r3
 *   @0x1ef0dc bne 0x1ef1d4 <_Z20Sprite_Replace_AlphaiPKcibbii+0x158>
 *   @0x1ef0e0 add sp, sp, #1056
 *   @0x1ef0e4 add sp, sp, #12
 *   @0x1ef0e8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1ef0ec mov r0, r1
 *   @0x1ef0f0 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0x1ef0f4 cmp r0, #0
 *   @0x1ef0f8 bne 0x1ef194 <_Z20Sprite_Replace_AlphaiPKcibbii+0x118>
 *   @0x1ef0fc mov r0, r7
 *   @0x1ef100 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0x1ef104 cmp r0, #0
 *   @0x1ef108 beq 0x1ef0cc <_Z20Sprite_Replace_AlphaiPKcibbii+0x50>
 *   @0x1ef10c add r11, sp, #36
 *   @0x1ef110 mov r2, r7
 *   @0x1ef114 mov r1, #1024
 *   @0x1ef118 mov r0, r11
 *   @0x1ef11c bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc>
 *   @0x1ef120 ldr r3, [pc, #0xbc]
 *   @0x1ef124 ldr r7, [r4, r3]
 *   @0x1ef128 ldr r3, [r7, #0x4]
 *   @0x1ef12c ldr r0, [r3, r6, lsl #2]
 *   @0x1ef130 cmp r0, #0
 *   @0x1ef134 beq 0x1ef1ac <_Z20Sprite_Replace_AlphaiPKcibbii+0x130>
 *   @0x1ef138 ldr r3, [sp, #0x454]
 *   @0x1ef13c mov r12, #1
 *   @0x1ef140 mov r2, r8
 *   @0x1ef144 mov lr, #0
 *   @0x1ef148 str r10, [sp, #0x8]
 *   @0x1ef14c mov r1, r11
 *   @0x1ef150 str r3, [sp, #0xc]
 *   @0x1ef154 ldr r3, [sp, #0x458]
 *   @0x1ef158 str r12, [sp]
 *   @0x1ef15c str r12, [sp, #0x14]
 *   @0x1ef160 str r3, [sp, #0x10]
 *   @0x1ef164 mov r3, r9
 *   @0x1ef168 str lr, [sp, #0x4]
 *   @0x1ef16c bl 0x1e7270 <_ZN7CSprite12LoadFromFileEPKcibbbbiib>
 *   @0x1ef170 ldr r3, [r7, #0x4]
 *   @0x1ef174 ldr r2, [pc, #0x6c]
 *   @0x1ef178 ldr r3, [r3, r6, lsl #2]
 *   @0x1ef17c str r6, [r3, #0x60]
 *   @0x1ef180 ldr r2, [r4, r2]
 *   @0x1ef184 ldr r2, [r2]
 *   @0x1ef188 ldr r2, [r2, r6, lsl #2]
 *   @0x1ef18c str r2, [r3, #0x5c]
 *   @0x1ef190 b 0x1ef0d0 <_Z20Sprite_Replace_AlphaiPKcibbii+0x54>
 *   @0x1ef194 add r11, sp, #36
 *   @0x1ef198 mov r2, r7
 *   @0x1ef19c mov r1, #1024
 *   @0x1ef1a0 mov r0, r11
 *   @0x1ef1a4 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x1ef1a8 b 0x1ef120 <_Z20Sprite_Replace_AlphaiPKcibbii+0xa4>
 *   @0x1ef1ac mov r0, #136
 *   @0x1ef1b0 bl 0x27c524 <_Znwj>
 *   @0x1ef1b4 str r0, [sp, #0x1c]
 *   @0x1ef1b8 bl 0x1e761c <_ZN7CSpriteC2Ev>
 *   @0x1ef1bc ldr r3, [sp, #0x1c]
 *   @0x1ef1c0 ldr r2, [r7, #0x4]
 *   @0x1ef1c4 str r3, [r2, r6, lsl #2]
 *   @0x1ef1c8 ldr r3, [r7, #0x4]
 *   @0x1ef1cc ldr r0, [r3, r6, lsl #2]
 *   @0x1ef1d0 b 0x1ef138 <_Z20Sprite_Replace_AlphaiPKcibbii+0xbc>
 *   @0x1ef1d4 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x1ef1d8 .word 0x00202bbc
 *   @0x1ef1dc .word 0xffffbd00
 *   @0x1ef1e0 .word 0xfffff1c0
 *   @0x1ef1e4 .word 0xfffff1b8
 *   @0x1ef1e8 .word 0xfffff1bc
 *
 * ══ §58/81 ZCompressStream(CStream&, CStream&, int)  0x20208c  size 368  92 条（0x20208c..0x2021fc）
 * @func 0x20208c 0x2021fc  size 368  92 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb69b8×2 / 0xb69a0 / CStream::Read(void*, int) / CStream::GetPosition() / CStream::GetSize() / 0xb69ac / CStream::Write(void*, int) / 0xb65d4
 * 字段偏移 top8: 0x8×4 / 0xc×3 / 0x4c×2 / 0x4×2 / 0x10×2 / 0x158×1 / 0x144×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20208c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x202090 sub sp, sp, #32768
 *   @0x202094 ldr r6, [pc, #0x158]
 *   @0x202098 sub sp, sp, #84
 *   @0x20209c add r12, sp, #20
 *   @0x2020a0 mov r8, r1
 *   @0x2020a4 ldr r6, [pc, r6]
 *   @0x2020a8 mov r1, r2
 *   @0x2020ac ldr r2, [pc, #0x144]
 *   @0x2020b0 mov r3, #56
 *   @0x2020b4 ldr r5, [r6]
 *   @0x2020b8 mov lr, #0
 *   @0x2020bc str r6, [sp]
 *   @0x2020c0 add r6, sp, #32768
 *   @0x2020c4 str r0, [sp, #0x8]
 *   @0x2020c8 add r2, pc, r2
 *   @0x2020cc mov r0, r12
 *   @0x2020d0 mov r4, r12
 *   @0x2020d4 str lr, [sp, #0x34]
 *   @0x2020d8 str r5, [r6, #0x4c]
 *   @0x2020dc str lr, [sp, #0x38]
 *   @0x2020e0 str lr, [sp, #0x3c]
 *   @0x2020e4 bl 0xb69a0 <deflateInit_@plt>
 *   @0x2020e8 cmp r0, #0
 *   @0x2020ec bne 0x2021b4 <_Z15ZCompressStreamR7CStreamS0_i+0x128>
 *   @0x2020f0 add r6, sp, #76
 *   @0x2020f4 str r6, [sp, #0x4]
 *   @0x2020f8 add r6, sp, #16384
 *   @0x2020fc mov r9, #16384
 *   @0x202100 add r6, r6, #76
 *   @0x202104 mov r5, r4
 *   @0x202108 movw r3, #0x7fc4
 *   @0x20210c movt r3, #0xffff
 *   @0x202110 str r3, [sp, #0xc]
 *   @0x202114 add r1, sp, #76
 *   @0x202118 mov r2, #16384
 *   @0x20211c ldr r0, [sp, #0x8]
 *   @0x202120 bl 0x20172c <_ZN7CStream4ReadEPvi>
 *   @0x202124 str r0, [r4, #0x4]
 *   @0x202128 ldr r0, [sp, #0x8]
 *   @0x20212c bl 0x201160 <_ZN7CStream11GetPositionEv>
 *   @0x202130 mov r7, r0
 *   @0x202134 ldr r0, [sp, #0x8]
 *   @0x202138 bl 0x201168 <_ZN7CStream7GetSizeEv>
 *   @0x20213c add r1, sp, #32768
 *   @0x202140 ldr r3, [sp, #0xc]
 *   @0x202144 add r1, r1, #80
 *   @0x202148 add r2, sp, #76
 *   @0x20214c str r2, [r1, r3]
 *   @0x202150 cmp r7, r0
 *   @0x202154 movge r7, #4
 *   @0x202158 movlt r7, #0
 *   @0x20215c b 0x20216c <_Z15ZCompressStreamR7CStreamS0_i+0xe0>
 *   @0x202160 ldr r3, [r10]
 *   @0x202164 cmp r3, #0
 *   @0x202168 bne 0x2021d8 <_Z15ZCompressStreamR7CStreamS0_i+0x14c>
 *   @0x20216c mov r10, r4
 *   @0x202170 mov r1, r7
 *   @0x202174 mov r0, r5
 *   @0x202178 str r9, [r4, #0x10]
 *   @0x20217c str r6, [r4, #0xc]
 *   @0x202180 bl 0xb69ac <deflate@plt>
 *   @0x202184 ldr r11, [r10, #0x10]!
 *   @0x202188 mov r0, r8
 *   @0x20218c mov r1, r6
 *   @0x202190 mov r4, r5
 *   @0x202194 rsb r11, r11, #16384
 *   @0x202198 mov r2, r11
 *   @0x20219c bl 0x2014c8 <_ZN7CStream5WriteEPvi>
 *   @0x2021a0 cmp r11, r0
 *   @0x2021a4 beq 0x202160 <_Z15ZCompressStreamR7CStreamS0_i+0xd4>
 *   @0x2021a8 mov r0, r5
 *   @0x2021ac bl 0xb69b8 <deflateEnd@plt>
 *   @0x2021b0 mvn r0, #0
 *   @0x2021b4 ldr r6, [sp]
 *   @0x2021b8 add r3, sp, #32768
 *   @0x2021bc ldr r2, [r3, #0x4c]
 *   @0x2021c0 ldr r3, [r6]
 *   @0x2021c4 cmp r2, r3
 *   @0x2021c8 bne 0x2021f0 <_Z15ZCompressStreamR7CStreamS0_i+0x164>
 *   @0x2021cc add sp, sp, #32768
 *   @0x2021d0 add sp, sp, #84
 *   @0x2021d4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2021d8 cmp r7, #4
 *   @0x2021dc bne 0x202114 <_Z15ZCompressStreamR7CStreamS0_i+0x88>
 *   @0x2021e0 mov r0, r5
 *   @0x2021e4 bl 0xb69b8 <deflateEnd@plt>
 *   @0x2021e8 mov r0, #0
 *   @0x2021ec b 0x2021b4 <_Z15ZCompressStreamR7CStreamS0_i+0x128>
 *   @0x2021f0 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2021f4 andseq r11, lr, r12, lsr #17
 *   @0x2021f8 andseq lr, r4, r8, asr pc
 *
 * ══ §59/81 oggpack_write  0x2333c8  size 368  92 条（0x2333c8..0x233538）
 * @func 0x2333c8 0x233538  size 368  92 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: oggpack_write+0xcc×4 / oggpack_write+0x130 / 0xb6c28
 * 字段偏移 top8: 0xc×9 / 0x4×8 / 0x10×3 / 0x2×2 / 0x8×2 / 0x134×1 / 0x1×1 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2333c8 cmp r2, #32
 *   @0x2333cc push {r4, r5, lr}
 *   @0x2333d0 mov r4, r0
 *   @0x2333d4 sub sp, sp, #12
 *   @0x2333d8 mov r5, r1
 *   @0x2333dc bhi 0x2334e8 <oggpack_write+0x120>
 *   @0x2333e0 ldr r3, [r0, #0x10]
 *   @0x2333e4 ldr r0, [r0]
 *   @0x2333e8 sub r1, r3, #4
 *   @0x2333ec cmp r0, r1
 *   @0x2333f0 bge 0x2334cc <oggpack_write+0x104>
 *   @0x2333f4 ldr r3, [r4, #0xc]
 *   @0x2333f8 ldr r12, [pc, #0x134]
 *   @0x2333fc ldr r1, [r4, #0x4]
 *   @0x233400 add r12, pc, r12
 *   @0x233404 ldrb r0, [r3]
 *   @0x233408 ldr r12, [r12, r2, lsl #2]
 *   @0x23340c add r2, r2, r1
 *   @0x233410 cmp r2, #7
 *   @0x233414 and r5, r5, r12
 *   @0x233418 orr r1, r0, r5, lsl r1
 *   @0x23341c strb r1, [r3]
 *   @0x233420 ble 0x233494 <oggpack_write+0xcc>
 *   @0x233424 ldr r1, [r4, #0x4]
 *   @0x233428 cmp r2, #15
 *   @0x23342c ldr r3, [r4, #0xc]
 *   @0x233430 rsb r1, r1, #8
 *   @0x233434 lsr r1, r5, r1
 *   @0x233438 strb r1, [r3, #0x1]
 *   @0x23343c ble 0x233494 <oggpack_write+0xcc>
 *   @0x233440 ldr r1, [r4, #0x4]
 *   @0x233444 cmp r2, #23
 *   @0x233448 ldr r3, [r4, #0xc]
 *   @0x23344c rsb r1, r1, #16
 *   @0x233450 lsr r1, r5, r1
 *   @0x233454 strb r1, [r3, #0x2]
 *   @0x233458 ble 0x233494 <oggpack_write+0xcc>
 *   @0x23345c ldr r1, [r4, #0x4]
 *   @0x233460 cmp r2, #31
 *   @0x233464 ldr r3, [r4, #0xc]
 *   @0x233468 rsb r1, r1, #24
 *   @0x23346c lsr r1, r5, r1
 *   @0x233470 strb r1, [r3, #0x3]
 *   @0x233474 ble 0x233494 <oggpack_write+0xcc>
 *   @0x233478 ldr r3, [r4, #0x4]
 *   @0x23347c ldr r1, [r4, #0xc]
 *   @0x233480 cmp r3, #0
 *   @0x233484 rsbne r3, r3, #32
 *   @0x233488 lsrne r5, r5, r3
 *   @0x23348c strbeq r3, [r1, #0x4]
 *   @0x233490 strbne r5, [r1, #0x4]
 *   @0x233494 cmp r2, #0
 *   @0x233498 add r3, r2, #7
 *   @0x23349c ldr r0, [r4]
 *   @0x2334a0 movge r3, r2
 *   @0x2334a4 ldr r1, [r4, #0xc]
 *   @0x2334a8 asr r3, r3, #3
 *   @0x2334ac and r2, r2, #7
 *   @0x2334b0 str r2, [r4, #0x4]
 *   @0x2334b4 add r2, r0, r3
 *   @0x2334b8 add r3, r1, r3
 *   @0x2334bc str r2, [r4]
 *   @0x2334c0 str r3, [r4, #0xc]
 *   @0x2334c4 add sp, sp, #12
 *   @0x2334c8 pop {r4, r5, pc}
 *   @0x2334cc ldr r1, [r4, #0xc]
 *   @0x2334d0 cmp r1, #0
 *   @0x2334d4 beq 0x2334c4 <oggpack_write+0xfc>
 *   @0x2334d8 movw r1, #0xfeff
 *   @0x2334dc movt r1, #0x7fff
 *   @0x2334e0 cmp r3, r1
 *   @0x2334e4 ble 0x2334f8 <oggpack_write+0x130>
 *   @0x2334e8 mov r0, r4
 *   @0x2334ec add sp, sp, #12
 *   @0x2334f0 pop {r4, r5, lr}
 *   @0x2334f4 b 0x23339c <oggpack_writeclear>
 *   @0x2334f8 ldr r0, [r4, #0x8]
 *   @0x2334fc add r1, r3, #256
 *   @0x233500 str r2, [sp, #0x4]
 *   @0x233504 bl 0xb6c28 <realloc@plt>
 *   @0x233508 ldr r2, [sp, #0x4]
 *   @0x23350c cmp r0, #0
 *   @0x233510 beq 0x2334e8 <oggpack_write+0x120>
 *   @0x233514 ldr r1, [r4, #0x10]
 *   @0x233518 ldr r3, [r4]
 *   @0x23351c add r1, r1, #256
 *   @0x233520 str r0, [r4, #0x8]
 *   @0x233524 add r3, r0, r3
 *   @0x233528 str r1, [r4, #0x10]
 *   @0x23352c str r3, [r4, #0xc]
 *   @0x233530 b 0x2333f8 <oggpack_write+0x30>
 *   @0x233534 andseq r5, r3, r8, lsr r6
 *
 * ══ §60/81 PackageManagerHasSystemFeature(char const*)  0x290288  size 368  92 条（0x290288..0x2903f8）
 * @func 0x290288 0x2903f8  size 368  92 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv / _JNIEnv::CallObjectMethod(_jobject*, _jmethodID*, ...) / _JNIEnv::CallBooleanMethod(_jobject*, _jmethodID*, ...)
 * 字段偏移 top8: 0x18×3 / 0x120×2 / 0x84×2 / 0xec×2 / 0x8c×2 / 0x138×1 / 0x104×1 / 0x240×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x290288 push {r4, r5, r6, r7, r8, lr}
 *   @0x29028c mov r7, r0
 *   @0x290290 bl 0x290274 <getJNIEnv>
 *   @0x290294 ldr r1, [pc, #0x138]
 *   @0x290298 add r1, pc, r1
 *   @0x29029c ldr r3, [r0]
 *   @0x2902a0 mov r4, r0
 *   @0x2902a4 ldr r3, [r3, #0x18]
 *   @0x2902a8 blx r3
 *   @0x2902ac ldr r12, [r4]
 *   @0x2902b0 ldr r2, [pc, #0x120]
 *   @0x2902b4 ldr r3, [pc, #0x120]
 *   @0x2902b8 add r2, pc, r2
 *   @0x2902bc ldr r12, [r12, #0x84]
 *   @0x2902c0 add r3, pc, r3
 *   @0x2902c4 mov r1, r0
 *   @0x2902c8 mov r0, r4
 *   @0x2902cc blx r12
 *   @0x2902d0 ldr r3, [r4]
 *   @0x2902d4 ldr r1, [pc, #0x104]
 *   @0x2902d8 ldr r3, [r3, #0x18]
 *   @0x2902dc add r1, pc, r1
 *   @0x2902e0 mov r6, r0
 *   @0x2902e4 mov r0, r4
 *   @0x2902e8 blx r3
 *   @0x2902ec ldr r12, [r4]
 *   @0x2902f0 ldr r2, [pc, #0xec]
 *   @0x2902f4 ldr r3, [pc, #0xec]
 *   @0x2902f8 ldr r12, [r12, #0x240]
 *   @0x2902fc add r2, pc, r2
 *   @0x290300 add r3, pc, r3
 *   @0x290304 mov r5, r0
 *   @0x290308 mov r0, r4
 *   @0x29030c mov r1, r5
 *   @0x290310 blx r12
 *   @0x290314 ldr r3, [r4]
 *   @0x290318 mov r1, r5
 *   @0x29031c ldr r3, [r3, #0x244]
 *   @0x290320 mov r2, r0
 *   @0x290324 mov r0, r4
 *   @0x290328 blx r3
 *   @0x29032c mov r2, r6
 *   @0x290330 mov r1, r0
 *   @0x290334 mov r0, r4
 *   @0x290338 bl 0x28fc74 <_ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz>
 *   @0x29033c ldr r3, [r4]
 *   @0x290340 ldr r1, [pc, #0xa4]
 *   @0x290344 ldr r3, [r3, #0x18]
 *   @0x290348 add r1, pc, r1
 *   @0x29034c mov r6, r0
 *   @0x290350 mov r0, r4
 *   @0x290354 blx r3
 *   @0x290358 ldr r12, [r4]
 *   @0x29035c ldr r2, [pc, #0x8c]
 *   @0x290360 ldr r3, [pc, #0x8c]
 *   @0x290364 ldr r12, [r12, #0x84]
 *   @0x290368 add r2, pc, r2
 *   @0x29036c add r3, pc, r3
 *   @0x290370 mov r1, r0
 *   @0x290374 mov r0, r4
 *   @0x290378 blx r12
 *   @0x29037c ldr r3, [r4]
 *   @0x290380 mov r1, r7
 *   @0x290384 ldr r3, [r3, #0x29c]
 *   @0x290388 mov r8, r0
 *   @0x29038c mov r0, r4
 *   @0x290390 blx r3
 *   @0x290394 mov r1, r6
 *   @0x290398 mov r2, r8
 *   @0x29039c mov r5, r0
 *   @0x2903a0 mov r0, r4
 *   @0x2903a4 mov r3, r5
 *   @0x2903a8 bl 0x28fcac <_ZN7_JNIEnv17CallBooleanMethodEP8_jobjectP10_jmethodIDz>
 *   @0x2903ac ldr r3, [r4]
 *   @0x2903b0 mov r1, r5
 *   @0x2903b4 ldr r3, [r3, #0x5c]
 *   @0x2903b8 mov r6, r0
 *   @0x2903bc mov r0, r4
 *   @0x2903c0 blx r3
 *   @0x2903c4 subs r3, r6, #1
 *   @0x2903c8 rsbs r0, r3, #0
 *   @0x2903cc adcs r0, r0, r3
 *   @0x2903d0 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2903d4 andeq r7, r12, r8, lsl pc
 *   @0x2903d8 andeq r7, r12, r0, lsl pc
 *   @0x2903dc andeq r7, r12, r12, lsl pc
 *   @0x2903e0 andeq r7, r12, r8, lsr #30
 *   @0x2903e4 andeq r7, r12, r12, lsr #30
 *   @0x2903e8 andeq r7, r12, r4, lsr pc
 *   @0x2903ec andeq r7, r12, r8, lsl #30
 *   @0x2903f0 andeq r7, r12, r12, lsl #30
 *   @0x2903f4 andeq r7, r12, r12, lsl pc
 *
 * ══ §61/81 png_write_cHRM  0x2b1b50  size 368  92 条（0x2b1b50..0x2b1cc0）
 * @func 0x2b1b50 0x2b1cc0  size 368  92 条
 * 部分覆盖: 本节 92/147 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_save_uint_32×6 / png_write_chunk
 * 字段偏移 top8: 0x44×2 / 0x1c×1 / 0x20×1
 * VFP 指令 39 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b1b50 vmov.f64 d7, #5.000000e-01
 *   @0x2b1b54 vldr d6, [pc, #344]
 *   @0x2b1b58 vmov d4, r2, r3
 *   @0x2b1b5c push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2b1b60 vpush {d8, d9}
 *   @0x2b1b64 sub sp, #0x4c
 *   @0x2b1b68 pkhtbmi r8, r1, r0, asr #2
 *   @0x2b1b6c add r8, pc
 *   @0x2b1b70 .word 0xf8d88000
 *   @0x2b1b74 strbmi r1, [r3], r0
 *   @0x2b1b78 vmov.f64 d5, d7
 *   @0x2b1b7c str r1, [sp, #0x44]
 *   @0x2b1b80 vmla.f64 d5, d4, d6
 *   @0x2b1b84 add r1, pc
 *   @0x2b1b88 stmdbvc r9, {r0, r2, r4, r5, r8, r9, r10, r11}
 *   @0x2b1b8c str r0, [sp, #0x1c]
 *   @0x2b1b90 strb.w r1, [sp, #0x20]
 *   @0x2b1b94 vcvt.u32.f64 s9, d5
 *   @0x2b1b98 vldr d5, [sp, #128]
 *   @0x2b1b9c vmov r4, s9
 *   @0x2b1ba0 vmov.f64 d4, d7
 *   @0x2b1ba4 vmla.f64 d4, d5, d6
 *   @0x2b1ba8 vldr d5, [sp, #136]
 *   @0x2b1bac mov r1, r4
 *   @0x2b1bb0 vnmla.f64 d4, d20, d4
 *   @0x2b1bb4 .word 0xeeb05a90
 *   @0x2b1bb8 vmls.f64 d4, d5, d7
 *   @0x2b1bbc vldr d4, [sp, #24]
 *   @0x2b1bc0 strtmi r5, [r10], -r4, lsr #22
 *   @0x2b1bc4 vcvt.u32.f64 s9, d4
 *   @0x2b1bc8 vmov r6, s9
 *   @0x2b1bcc vmov.f64 d4, d7
 *   @0x2b1bd0 vmla.f64 d4, d5, d6
 *   @0x2b1bd4 vldr d5, [sp, #152]
 *   @0x2b1bd8 mov r3, r6
 *   @0x2b1bdc vnmla.f64 d4, d20, d4
 *   @0x2b1be0 .word 0xeeb07a90
 *   @0x2b1be4 vmls.f64 d4, d5, d7
 *   @0x2b1be8 vldr d4, [sp, #24]
 *   @0x2b1bec .word 0xeefc5b28
 *   @0x2b1bf0 vnmla.f64 d4, d20, d4
 *   @0x2b1bf4 .word 0xeeb0aa90
 *   @0x2b1bf8 vmls.f64 d4, d5, d7
 *   @0x2b1bfc vldr d4, [sp, #24]
 *   @0x2b1c00 stm sp, {r1, r3, r5, r8, r9, r11, r12, lr}
 *   @0x2b1c04 cdp p4, #0xb, c0, c12, c0, #0x4
 *   @0x2b1c08 vabs.f64 d9, d4
 *   @0x2b1c0c vstr d4, [sp, #284]
 *   @0x2b1c10 vmla.f32 s18, s10, s4
 *   @0x2b1c14 vldr d4, [sp, #24]
 *   @0x2b1c18 vmla.f64 d5, d5, d28
 *   @0x2b1c1c vmov.f64 d23, #-1.718750e-01
 *   @0x2b1c20 vcvt.u32.f64 s16, d4
 *   @0x2b1c24 vstr d24, [sp, #796]
 *   @0x2b1c28 vstr s16, [sp, #12]
 *   @0x2b1c2c .word 0xf7f48a04
 *   @0x2b1c30 orrlt pc, r8, #110592
 *   @0x2b1c34 add.w r8, sp, #0x24
 *   @0x2b1c38 mov r1, r4
 *   @0x2b1c3c bl 0x2b1124 <png_save_uint_32>
 *   @0x2b1c40 add.w r0, r8, #0x4
 *   @0x2b1c44 mov r1, r5
 *   @0x2b1c48 .word 0xf108fa6d
 *   @0x2b1c4c ldrtmi r0, [r1], -r8
 *   @0x2b1c50 bl 0x2b1124 <png_save_uint_32>
 *   @0x2b1c54 add.w r0, r8, #0xc
 *   @0x2b1c58 mov r1, r7
 *   @0x2b1c5c .word 0xf108fa63
 *   @0x2b1c60 uadd16mi r0, r1, r0
 *   @0x2b1c64 bl 0x2b1124 <png_save_uint_32>
 *   @0x2b1c68 add.w r0, r8, #0x14
 *   @0x2b1c6c vmov r1, s18
 *   @0x2b1c70 bl 0x2b1124 <png_save_uint_32>
 *   @0x2b1c74 add.w r0, r8, #0x18
 *   @0x2b1c78 vmov r1, s17
 *   @0x2b1c7c bl 0x2b1124 <png_save_uint_32>
 *   @0x2b1c80 add.w r0, r8, #0x1c
 *   @0x2b1c84 vmov r1, s16
 *   @0x2b1c88 bl 0x2b1124 <png_save_uint_32>
 *   @0x2b1c8c mov r0, r9
 *   @0x2b1c90 mov r2, r8
 *   @0x2b1c94 bl 0x2b12bc <png_write_chunk>
 *   @0x2b1c98 ldr r2, [sp, #0x44]
 *   @0x2b1c9c addsmi r3, r10, #0
 *   @0x2b1ca0 beq 0x2b1ca6 <png_write_cHRM+0x156>
 *   @0x2b1ca4 mulslt r3, r8, r12
 *   @0x2b1ca8 vpop {d8, d9}
 *   @0x2b1cac pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2b1cb0 movs r0, r0
 *   @0x2b1cb4 ldr r0, [r0, #0x20]
 *   @0x2b1cb8 pop {r3, r5, r6, r7, pc}
 *   @0x2b1cbc b 0x2b2078 <png_write_zTXt+0x74>
 *
 * ══ §62/81 CBitmap32::CBitmap32(CStream*)  0x165e2c  size 364  91 条（0x165e2c..0x165f98）
 * @func 0x165e2c 0x165f98  size 364  91 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::ReadInteger()×5 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / CStream::ReadStream() / CStream::ReadBuffer(void*, int) / CStream::~CStream() / operator delete(void*) / CStream::ReadBoolean() / CStream::ReadCompressedStream()
 * 字段偏移 top8: 0x8×8 / 0xc×6 / 0x14×4 / 0x4×3 / 0x10×3 / 0x158×1 / 0xe8×1 / 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x165e2c ldr r2, [pc, #0x158]
 *   @0x165e30 mov r3, #0
 *   @0x165e34 push {r4, r5, r6, lr}
 *   @0x165e38 ldr r2, [pc, r2]
 *   @0x165e3c mov r4, r0
 *   @0x165e40 strb r3, [r0, #0x4]
 *   @0x165e44 str r3, [r0, #0x8]
 *   @0x165e48 add r2, r2, #8
 *   @0x165e4c str r2, [r0]
 *   @0x165e50 mov r0, r1
 *   @0x165e54 str r3, [r4, #0xc]
 *   @0x165e58 mov r5, r1
 *   @0x165e5c str r3, [r4, #0x14]
 *   @0x165e60 str r3, [r4, #0x10]
 *   @0x165e64 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x165e68 cmp r0, #540
 *   @0x165e6c beq 0x165f1c <_ZN9CBitmap32C2EP7CStream+0xf0>
 *   @0x165e70 cmp r0, #800
 *   @0x165e74 beq 0x165e80 <_ZN9CBitmap32C2EP7CStream+0x54>
 *   @0x165e78 mov r0, r4
 *   @0x165e7c pop {r4, r5, r6, pc}
 *   @0x165e80 mov r6, #1
 *   @0x165e84 mov r0, r5
 *   @0x165e88 strb r6, [r4, #0x4]
 *   @0x165e8c bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x165e90 str r0, [r4, #0x8]
 *   @0x165e94 mov r0, r5
 *   @0x165e98 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x165e9c ldr r12, [r4, #0x8]
 *   @0x165ea0 ldr r1, [pc, #0xe8]
 *   @0x165ea4 mov r3, r6
 *   @0x165ea8 mov r2, #171
 *   @0x165eac add r1, pc, r1
 *   @0x165eb0 str r0, [r4, #0xc]
 *   @0x165eb4 mul r0, r12, r0
 *   @0x165eb8 lsl r0, r0, #2
 *   @0x165ebc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x165ec0 ldr r3, [r4, #0x8]
 *   @0x165ec4 ldr r2, [r4, #0xc]
 *   @0x165ec8 mul r3, r2, r3
 *   @0x165ecc lsl r3, r3, #2
 *   @0x165ed0 str r3, [r4, #0x10]
 *   @0x165ed4 str r0, [r4, #0x14]
 *   @0x165ed8 mov r0, r5
 *   @0x165edc bl 0x2019c4 <_ZN7CStream10ReadStreamEv>
 *   @0x165ee0 ldr r3, [r4, #0x8]
 *   @0x165ee4 mov r5, r0
 *   @0x165ee8 ldr r2, [r4, #0xc]
 *   @0x165eec ldr r1, [r4, #0x14]
 *   @0x165ef0 mul r2, r2, r3
 *   @0x165ef4 lsl r2, r2, #2
 *   @0x165ef8 bl 0x2011e4 <_ZN7CStream10ReadBufferEPvi>
 *   @0x165efc cmp r5, #0
 *   @0x165f00 beq 0x165e78 <_ZN9CBitmap32C2EP7CStream+0x4c>
 *   @0x165f04 mov r0, r5
 *   @0x165f08 bl 0x201328 <_ZN7CStreamD2Ev>
 *   @0x165f0c mov r0, r5
 *   @0x165f10 bl 0x27d1d0 <_ZdlPv>
 *   @0x165f14 mov r0, r4
 *   @0x165f18 pop {r4, r5, r6, pc}
 *   @0x165f1c mov r0, r5
 *   @0x165f20 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv>
 *   @0x165f24 cmp r0, #0
 *   @0x165f28 strb r0, [r4, #0x4]
 *   @0x165f2c beq 0x165e78 <_ZN9CBitmap32C2EP7CStream+0x4c>
 *   @0x165f30 mov r0, r5
 *   @0x165f34 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x165f38 str r0, [r4, #0x8]
 *   @0x165f3c mov r0, r5
 *   @0x165f40 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x165f44 ldr r12, [r4, #0x8]
 *   @0x165f48 ldr r1, [pc, #0x44]
 *   @0x165f4c mov r2, #159
 *   @0x165f50 mov r3, #1
 *   @0x165f54 add r1, pc, r1
 *   @0x165f58 str r0, [r4, #0xc]
 *   @0x165f5c mul r0, r12, r0
 *   @0x165f60 lsl r0, r0, #2
 *   @0x165f64 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x165f68 ldr r3, [r4, #0x8]
 *   @0x165f6c ldr r2, [r4, #0xc]
 *   @0x165f70 mul r3, r2, r3
 *   @0x165f74 lsl r3, r3, #2
 *   @0x165f78 str r3, [r4, #0x10]
 *   @0x165f7c str r0, [r4, #0x14]
 *   @0x165f80 mov r0, r5
 *   @0x165f84 bl 0x201db0 <_ZN7CStream20ReadCompressedStreamEv>
 *   @0x165f88 b 0x165ee0 <_ZN9CBitmap32C2EP7CStream+0xb4>
 *   @0x165f8c eoreq r10, r8, r0, asr #5
 *   @0x165f90 andseq r4, lr, r4, lsl r7
 *   @0x165f94 andseq r4, lr, r12, ror #12
 *
 * ══ §63/81 GR_Draw_Triangle(float, float, float, float, float, float, bool)  0x16a6f0  size 364  91 条（0x16a6f0..0x16a85c）
 * @func 0x16a6f0 0x16a85c  size 364  91 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x16a704→0x3f23d8, 0x16a710→0x3f23d4, 0x16a714→0x3f23d0, 0x16a758→0x4859c0, 0x16a78c→0x4859ac, 0x16a7ec→0x4859ac
 * 调用序列: Graphics::AllocVerts(ePrimType, void*, int, int)×2
 * 字段偏移 top8: 0x134×2 / 0xc×2 / 0x8×2 / 0x20×2 / 0x38×2 / 0x24×2 / 0x3c×2 / 0x140×1
 * VFP 指令 34 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16a6f0 push {r3, r4, r5, lr}
 *   @0x16a6f4 vldr s13, [pc, #324]
 *   @0x16a6f8 vpush {d8, d9, d10}
 *   @0x16a6fc ldr r4, [pc, #0x140]
 *   @0x16a700 vldr s19, [sp, #40]
 *   @0x16a704 ldr r5, [pc, #0x13c]
 *   @0x16a708 vldr s18, [sp, #44]
 *   @0x16a70c add r4, pc, r4
 *   @0x16a710 ldr lr, [pc, #0x134]
 *   @0x16a714 ldr r12, [pc, #0x134]
 *   @0x16a718 ldr r5, [r4, r5]
 *   @0x16a71c vldr s14, [r5]
 *   @0x16a720 vmul.f32 s14, s14, s13
 *   @0x16a724 ldr lr, [r4, lr]
 *   @0x16a728 vldr s15, [lr]
 *   @0x16a72c ldrb lr, [sp, #0x30]
 *   @0x16a730 ldr r12, [r4, r12]
 *   @0x16a734 cmp lr, #0
 *   @0x16a738 ldr r5, [r12]
 *   @0x16a73c vmul.f32 s15, s15, s13
 *   @0x16a740 vmov s13, r0
 *   @0x16a744 vadd.f32 s16, s14, s13
 *   @0x16a748 vmov s13, r2
 *   @0x16a74c vadd.f32 s19, s14, s19
 *   @0x16a750 vadd.f32 s21, s14, s13
 *   @0x16a754 vmov s14, r1
 *   @0x16a758 ldr r1, [pc, #0xf4]
 *   @0x16a75c vmov s13, r3
 *   @0x16a760 vadd.f32 s17, s15, s14
 *   @0x16a764 vadd.f32 s20, s15, s13
 *   @0x16a768 vadd.f32 s18, s15, s18
 *   @0x16a76c bne 0x16a7d0 <_Z16GR_Draw_Triangleffffffb+0xe0>
 *   @0x16a770 ldr r1, [r4, r1]
 *   @0x16a774 mov r3, #3
 *   @0x16a778 mov r0, #4
 *   @0x16a77c mov r2, #24
 *   @0x16a780 ldr r1, [r1]
 *   @0x16a784 ldr r1, [r1]
 *   @0x16a788 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x16a78c ldr r3, [pc, #0xc4]
 *   @0x16a790 ldr r3, [r4, r3]
 *   @0x16a794 ldr r3, [r3]
 *   @0x16a798 vstr s17, [r0, #4]
 *   @0x16a79c vstr s16, [r0]
 *   @0x16a7a0 vstr s21, [r0, #24]
 *   @0x16a7a4 vstr s20, [r0, #28]
 *   @0x16a7a8 vstr s19, [r0, #48]
 *   @0x16a7ac vstr s18, [r0, #52]
 *   @0x16a7b0 vpop {d8, d9, d10}
 *   @0x16a7b4 str r5, [r0, #0xc]
 *   @0x16a7b8 str r3, [r0, #0x8]
 *   @0x16a7bc str r3, [r0, #0x20]
 *   @0x16a7c0 str r3, [r0, #0x38]
 *   @0x16a7c4 str r5, [r0, #0x24]
 *   @0x16a7c8 str r5, [r0, #0x3c]
 *   @0x16a7cc pop {r3, r4, r5, pc}
 *   @0x16a7d0 ldr r1, [r4, r1]
 *   @0x16a7d4 mov r3, #4
 *   @0x16a7d8 mov r0, #3
 *   @0x16a7dc mov r2, #24
 *   @0x16a7e0 ldr r1, [r1]
 *   @0x16a7e4 ldr r1, [r1]
 *   @0x16a7e8 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x16a7ec ldr r3, [pc, #0x64]
 *   @0x16a7f0 ldr r3, [r4, r3]
 *   @0x16a7f4 ldr r3, [r3]
 *   @0x16a7f8 vstr s21, [r0, #24]
 *   @0x16a7fc vstr s16, [r0]
 *   @0x16a800 vstr s16, [r0, #72]
 *   @0x16a804 vstr s17, [r0, #4]
 *   @0x16a808 vstr s17, [r0, #76]
 *   @0x16a80c vstr s20, [r0, #28]
 *   @0x16a810 vstr s19, [r0, #48]
 *   @0x16a814 vstr s18, [r0, #52]
 *   @0x16a818 vpop {d8, d9, d10}
 *   @0x16a81c str r5, [r0, #0xc]
 *   @0x16a820 str r3, [r0, #0x8]
 *   @0x16a824 str r3, [r0, #0x50]
 *   @0x16a828 str r3, [r0, #0x20]
 *   @0x16a82c str r3, [r0, #0x38]
 *   @0x16a830 str r5, [r0, #0x54]
 *   @0x16a834 str r5, [r0, #0x24]
 *   @0x16a838 str r5, [r0, #0x3c]
 *   @0x16a83c pop {r3, r4, r5, pc}
 *   @0x16a840 stclo p7, c13, [r3], #-40
 *   @0x16a844 eoreq r7, r8, r4, asr #10
 *   @0x16a848 .word 0xffffe524
 *   @0x16a84c .word 0xffffe520
 *   @0x16a850 .word 0xffffc0ac
 *   @0x16a854 .word 0xffffe4e0
 *   @0x16a858 .word 0xffffbcd0
 *
 * ══ §64/81 CSprite::Assign(CSprite*)  0x1e76e8  size 364  91 条（0x1e76e8..0x1e7854）
 * @func 0x1e76e8 0x1e7854  size 364  91 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSprite::Clear() / MemoryManager::SetLength(void**, unsigned int, char const*, int) / CSprite::Assign(CSprite*)+0x130 / operator new(unsigned int) / CBitmap32::CBitmap32(CBitmap32*) / CSprite::InitTexture() / CSprite::InitLocalTPE()
 * 字段偏移 top8: 0x4×5 / 0x44×4 / 0x48×3 / 0x20×2 / 0x36×2 / 0x1c×2 / 0x30×2 / 0x32×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e76e8 ldr r3, [r1, #0x74]
 *   @0x1e76ec push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1e76f0 cmp r3, #0
 *   @0x1e76f4 sub sp, sp, #12
 *   @0x1e76f8 mov r5, r1
 *   @0x1e76fc mov r4, r0
 *   @0x1e7700 beq 0x1e770c <_ZN7CSprite6AssignEPS_+0x24>
 *   @0x1e7704 add sp, sp, #12
 *   @0x1e7708 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e770c bl 0x1e6b4c <_ZN7CSprite5ClearEv>
 *   @0x1e7710 ldr r7, [r5, #0x20]
 *   @0x1e7714 add r3, r5, #8
 *   @0x1e7718 ldrb lr, [r5, #0x36]
 *   @0x1e771c ldr r6, [r5, #0x1c]
 *   @0x1e7720 add r12, r4, #8
 *   @0x1e7724 ldm r3, {r0, r1, r2, r3}
 *   @0x1e7728 cmp lr, #0
 *   @0x1e772c str r7, [r4, #0x20]
 *   @0x1e7730 ldrb r7, [r5, #0x30]
 *   @0x1e7734 ldrb r11, [r5, #0x32]
 *   @0x1e7738 ldrb r10, [r5, #0x33]
 *   @0x1e773c str r7, [sp, #0x4]
 *   @0x1e7740 ldrb r9, [r5, #0x34]
 *   @0x1e7744 ldr r8, [r5, #0x4]
 *   @0x1e7748 ldr r7, [r5, #0x24]
 *   @0x1e774c str r6, [r4, #0x1c]
 *   @0x1e7750 ldr r6, [r5, #0x28]
 *   @0x1e7754 stm r12, {r0, r1, r2, r3}
 *   @0x1e7758 add r0, r4, #72
 *   @0x1e775c ldr r3, [r5, #0x2c]
 *   @0x1e7760 ldr r2, [r5, #0x18]
 *   @0x1e7764 ldr r1, [sp, #0x4]
 *   @0x1e7768 str r3, [r4, #0x2c]
 *   @0x1e776c str r6, [r4, #0x28]
 *   @0x1e7770 ldreq r3, [r5, #0x54]
 *   @0x1e7774 strb r1, [r4, #0x30]
 *   @0x1e7778 str r2, [r4, #0x18]
 *   @0x1e777c strb r11, [r4, #0x32]
 *   @0x1e7780 strb r10, [r4, #0x33]
 *   @0x1e7784 strb r9, [r4, #0x34]
 *   @0x1e7788 str r8, [r4, #0x4]
 *   @0x1e778c str r7, [r4, #0x24]
 *   @0x1e7790 strbeq lr, [r4, #0x36]
 *   @0x1e7794 ldr r1, [r5, #0x44]
 *   @0x1e7798 ldr r2, [pc, #0xb0]
 *   @0x1e779c streq r3, [r4, #0x54]
 *   @0x1e77a0 movw r3, #0xa77
 *   @0x1e77a4 str r1, [r4, #0x44]
 *   @0x1e77a8 add r2, pc, r2
 *   @0x1e77ac lsl r1, r1, #2
 *   @0x1e77b0 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1e77b4 ldr r3, [r4, #0x44]
 *   @0x1e77b8 cmp r3, #0
 *   @0x1e77bc movgt r6, #0
 *   @0x1e77c0 ble 0x1e7818 <_ZN7CSprite6AssignEPS_+0x130>
 *   @0x1e77c4 ldr r3, [r4, #0x48]
 *   @0x1e77c8 lsl r7, r6, #2
 *   @0x1e77cc ldr r3, [r3, r6, lsl #2]
 *   @0x1e77d0 add r6, r6, #1
 *   @0x1e77d4 cmp r3, #0
 *   @0x1e77d8 mov r0, r3
 *   @0x1e77dc beq 0x1e77ec <_ZN7CSprite6AssignEPS_+0x104>
 *   @0x1e77e0 ldr r3, [r3]
 *   @0x1e77e4 ldr r3, [r3, #0x4]
 *   @0x1e77e8 blx r3
 *   @0x1e77ec mov r0, #24
 *   @0x1e77f0 bl 0x27c524 <_Znwj>
 *   @0x1e77f4 ldr r3, [r5, #0x48]
 *   @0x1e77f8 ldr r1, [r3, r7]
 *   @0x1e77fc mov r8, r0
 *   @0x1e7800 bl 0x165f98 <_ZN9CBitmap32C2EPS_>
 *   @0x1e7804 ldr r2, [r4, #0x44]
 *   @0x1e7808 ldr r3, [r4, #0x48]
 *   @0x1e780c cmp r2, r6
 *   @0x1e7810 str r8, [r3, r7]
 *   @0x1e7814 bgt 0x1e77c4 <_ZN7CSprite6AssignEPS_+0xdc>
 *   @0x1e7818 mov r0, r4
 *   @0x1e781c bl 0x1e5748 <_ZN7CSprite11InitTextureEv>
 *   @0x1e7820 ldr r3, [r5, #0x54]
 *   @0x1e7824 cmp r3, #0
 *   @0x1e7828 beq 0x1e7838 <_ZN7CSprite6AssignEPS_+0x150>
 *   @0x1e782c ldrb r3, [r5, #0x36]
 *   @0x1e7830 cmp r3, #0
 *   @0x1e7834 beq 0x1e7840 <_ZN7CSprite6AssignEPS_+0x158>
 *   @0x1e7838 mov r0, r4
 *   @0x1e783c bl 0x1e5854 <_ZN7CSprite12InitLocalTPEEv>
 *   @0x1e7840 mov r0, r4
 *   @0x1e7844 add sp, sp, #12
 *   @0x1e7848 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1e784c b 0x1e3bcc <_ZN7CSprite10CreateMaskEv>
 *   @0x1e7850 andseq r10, r6, r12, ror r12
 *
 * ══ §65/81 Audio_SoundLength(int)  0x218640  size 364  91 条（0x218640..0x2187ac）
 * @func 0x218640 0x2187ac  size 364  91 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6ac0×4 / Audio_GetSound(int)×2 / __udivsi3×2 / Audio_SoundLength(int)+0x128 / 0xb6a54 / Audio_GetNoiseFromID(int) / COggAudio::CalcSoundInfo(cAudio_Sound*)
 * 字段偏移 top8: 0x18×2 / 0x154×1 / 0x13c×1 / 0x12c×1 / 0x24×1 / 0x25×1 / 0x8×1 / 0x4×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x218640 ldr r3, [pc, #0x154]
 *   @0x218644 push {r4, r5, lr}
 *   @0x218648 ldr r3, [pc, r3]
 *   @0x21864c sub sp, sp, #20
 *   @0x218650 ldrb r3, [r3]
 *   @0x218654 cmp r3, #0
 *   @0x218658 bne 0x218758 <_Z17Audio_SoundLengthi+0x118>
 *   @0x21865c ldr r3, [pc, #0x13c]
 *   @0x218660 ldr r3, [pc, r3]
 *   @0x218664 ldrb r3, [r3]
 *   @0x218668 cmp r3, #0
 *   @0x21866c beq 0x218758 <_Z17Audio_SoundLengthi+0x118>
 *   @0x218670 ldr r3, [pc, #0x12c]
 *   @0x218674 ldr r3, [pc, r3]
 *   @0x218678 ldr r3, [r3]
 *   @0x21867c cmp r3, r0
 *   @0x218680 ble 0x218768 <_Z17Audio_SoundLengthi+0x128>
 *   @0x218684 bl 0x21632c <_Z14Audio_GetSoundi>
 *   @0x218688 mov r4, r0
 *   @0x21868c cmp r4, #0
 *   @0x218690 beq 0x218758 <_Z17Audio_SoundLengthi+0x118>
 *   @0x218694 vldr s15, [r4, #52]
 *   @0x218698 vcmpe.f32 s15, #0
 *   @0x21869c vmrs APSR_nzcv, fpscr
 *   @0x2186a0 bge 0x21875c <_Z17Audio_SoundLengthi+0x11c>
 *   @0x2186a4 ldrb r3, [r4, #0x24]
 *   @0x2186a8 cmp r3, #0
 *   @0x2186ac bne 0x218784 <_Z17Audio_SoundLengthi+0x144>
 *   @0x2186b0 ldrb r3, [r4, #0x25]
 *   @0x2186b4 cmp r3, #0
 *   @0x2186b8 bne 0x218784 <_Z17Audio_SoundLengthi+0x144>
 *   @0x2186bc ldr r5, [r4, #0x18]
 *   @0x2186c0 cmn r5, #1
 *   @0x2186c4 beq 0x21875c <_Z17Audio_SoundLengthi+0x11c>
 *   @0x2186c8 mov r0, r5
 *   @0x2186cc movw r1, #0x2004
 *   @0x2186d0 mov r2, sp
 *   @0x2186d4 bl 0xb6ac0 <alGetBufferi@plt>
 *   @0x2186d8 mov r0, r5
 *   @0x2186dc movw r1, #0x2002
 *   @0x2186e0 add r2, sp, #4
 *   @0x2186e4 bl 0xb6ac0 <alGetBufferi@plt>
 *   @0x2186e8 mov r0, r5
 *   @0x2186ec movw r1, #0x2003
 *   @0x2186f0 add r2, sp, #8
 *   @0x2186f4 bl 0xb6ac0 <alGetBufferi@plt>
 *   @0x2186f8 mov r0, r5
 *   @0x2186fc movw r1, #0x2001
 *   @0x218700 add r2, sp, #12
 *   @0x218704 bl 0xb6ac0 <alGetBufferi@plt>
 *   @0x218708 bl 0xb6a54 <alGetError@plt>
 *   @0x21870c cmp r0, #0
 *   @0x218710 bne 0x218758 <_Z17Audio_SoundLengthi+0x118>
 *   @0x218714 ldr r1, [sp, #0x8]
 *   @0x218718 ldr r0, [sp]
 *   @0x21871c bl 0x318c48 <__udivsi3>
 *   @0x218720 ldr r3, [sp, #0x4]
 *   @0x218724 cmp r3, #0
 *   @0x218728 add r2, r3, #7
 *   @0x21872c movge r1, r3
 *   @0x218730 movlt r1, r2
 *   @0x218734 asr r1, r1, #3
 *   @0x218738 bl 0x318c48 <__udivsi3>
 *   @0x21873c vldr s13, [sp, #12]
 *   @0x218740 vcvt.f32.s32 s15, s13
 *   @0x218744 vmov s13, r0
 *   @0x218748 vcvt.f32.u32 s14, s13
 *   @0x21874c vdiv.f32 s15, s14, s15
 *   @0x218750 vstr s15, [r4, #52]
 *   @0x218754 b 0x21875c <_Z17Audio_SoundLengthi+0x11c>
 *   @0x218758 vmov.f32 s15, #-1.000000e+00
 *   @0x21875c vmov r0, s15
 *   @0x218760 add sp, sp, #20
 *   @0x218764 pop {r4, r5, pc}
 *   @0x218768 bl 0x216fbc <_Z20Audio_GetNoiseFromIDi>
 *   @0x21876c cmp r0, #0
 *   @0x218770 beq 0x218758 <_Z17Audio_SoundLengthi+0x118>
 *   @0x218774 ldr r0, [r0, #0x18]
 *   @0x218778 bl 0x21632c <_Z14Audio_GetSoundi>
 *   @0x21877c mov r4, r0
 *   @0x218780 b 0x21868c <_Z17Audio_SoundLengthi+0x4c>
 *   @0x218784 ldr r0, [pc, #0x1c]
 *   @0x218788 mov r1, r4
 *   @0x21878c add r0, pc, r0
 *   @0x218790 bl 0x22688c <_ZN9COggAudio13CalcSoundInfoEP12cAudio_Sound>
 *   @0x218794 vldr s15, [r4, #52]
 *   @0x218798 b 0x21875c <_Z17Audio_SoundLengthi+0x11c>
 *   @0x21879c andseq r6, sp, r4, lsl #20
 *   @0x2187a0 ldrsbeq r6, [sp], -r0
 *   @0x2187a4 andseq r8, sp, r0, ror sp
 *   @0x2187a8 subseq r12, r3, r8, lsl #22
 *
 * ══ §66/81 JS_Array_prototype_forEach(RValue&, CInstance*, CInstance*, int, RValue*)  0x25173c  size 364  91 条（0x25173c..0x2518a8）
 * @func 0x25173c 0x2518a8  size 364  91 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYObjectBase::InternalGetYYVar(int)×3 / JSThrowTypeError(char const*)×2 / JS_Array_prototype_forEach(RValue&, CInstance*, CInstance*, int, RValue*)+0x44 / JS_IsCallable(RValue&) / Call_RValue(YYObjectBase*, RValue*, RValue*, int, RValue*)
 * 字段偏移 top8: 0x4×3 / 0xc×3 / 0x78×2 / 0x24×1 / 0x118×1 / 0x3c×1 / 0x4c×1 / 0x40×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x25173c ldr r2, [r1, #0x4]
 *   @0x251740 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x251744 cmp r2, #0
 *   @0x251748 mov r4, r3
 *   @0x25174c sub sp, sp, #84
 *   @0x251750 mov r3, #5
 *   @0x251754 str r3, [r0, #0xc]
 *   @0x251758 beq 0x251890 <_Z26JS_Array_prototype_forEachR6RValueP9CInstanceS2_iPS_+0x154>
 *   @0x25175c add r0, r2, #16
 *   @0x251760 ldr r9, [r0]
 *   @0x251764 cmp r4, #0
 *   @0x251768 ldr r7, [r9, #0x24]
 *   @0x25176c ble 0x251780 <_Z26JS_Array_prototype_forEachR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x251770 ldr r0, [sp, #0x78]
 *   @0x251774 bl 0x24076c <_Z13JS_IsCallableR6RValue>
 *   @0x251778 cmp r0, #0
 *   @0x25177c bne 0x251794 <_Z26JS_Array_prototype_forEachR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x251780 ldr r0, [pc, #0x118]
 *   @0x251784 add r0, pc, r0
 *   @0x251788 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x25178c add sp, sp, #84
 *   @0x251790 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x251794 cmp r4, #1
 *   @0x251798 moveq r12, #0
 *   @0x25179c streq r12, [sp, #0xc]
 *   @0x2517a0 ldrne r12, [sp, #0x78]
 *   @0x2517a4 ldrne r12, [r12, #0x10]
 *   @0x2517a8 strne r12, [sp, #0xc]
 *   @0x2517ac cmp r7, #0
 *   @0x2517b0 beq 0x25178c <_Z26JS_Array_prototype_forEachR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x2517b4 mov r4, #0
 *   @0x2517b8 add r6, sp, #32
 *   @0x2517bc add r11, sp, #16
 *   @0x2517c0 mov r5, r4
 *   @0x2517c4 mov r10, r4
 *   @0x2517c8 mvn r8, #-16777216
 *   @0x2517cc b 0x25184c <_Z26JS_Array_prototype_forEachR6RValueP9CInstanceS2_iPS_+0x110>
 *   @0x2517d0 ldr r3, [r0, #0xc]
 *   @0x2517d4 bic r3, r3, #-16777216
 *   @0x2517d8 cmp r3, r8
 *   @0x2517dc beq 0x25183c <_Z26JS_Array_prototype_forEachR6RValueP9CInstanceS2_iPS_+0x100>
 *   @0x2517e0 ldr r0, [r9, #0x4]
 *   @0x2517e4 cmp r0, #0
 *   @0x2517e8 add r0, r0, r4
 *   @0x2517ec beq 0x25186c <_Z26JS_Array_prototype_forEachR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x2517f0 vmov s13, r5
 *   @0x2517f4 mov r12, #6
 *   @0x2517f8 ldm r0, {r0, r1, r2, r3}
 *   @0x2517fc vcvt.f64.u32 d7, s13
 *   @0x251800 str r6, [sp]
 *   @0x251804 str r10, [sp, #0x3c]
 *   @0x251808 str r12, [sp, #0x4c]
 *   @0x25180c stm r6, {r0, r1, r2, r3}
 *   @0x251810 mov r1, r11
 *   @0x251814 ldr r0, [sp, #0xc]
 *   @0x251818 mov r3, #3
 *   @0x25181c ldr r2, [sp, #0x78]
 *   @0x251820 vstr d7, [sp, #48]
 *   @0x251824 str r9, [sp, #0x40]
 *   @0x251828 bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_>
 *   @0x25182c cmp r0, #2
 *   @0x251830 beq 0x25178c <_Z26JS_Array_prototype_forEachR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x251834 cmp r0, #1
 *   @0x251838 beq 0x25187c <_Z26JS_Array_prototype_forEachR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x25183c add r5, r5, #1
 *   @0x251840 add r4, r4, #16
 *   @0x251844 cmp r5, r7
 *   @0x251848 beq 0x25178c <_Z26JS_Array_prototype_forEachR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x25184c ldr r0, [r9, #0x4]
 *   @0x251850 cmp r0, #0
 *   @0x251854 add r0, r0, r4
 *   @0x251858 bne 0x2517d0 <_Z26JS_Array_prototype_forEachR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x25185c mov r0, r9
 *   @0x251860 mov r1, r5
 *   @0x251864 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x251868 b 0x2517d0 <_Z26JS_Array_prototype_forEachR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x25186c mov r0, r9
 *   @0x251870 mov r1, r5
 *   @0x251874 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x251878 b 0x2517f0 <_Z26JS_Array_prototype_forEachR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x25187c ldr r0, [pc, #0x20]
 *   @0x251880 add r0, pc, r0
 *   @0x251884 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x251888 add sp, sp, #84
 *   @0x25188c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x251890 mov r0, r1
 *   @0x251894 mov r1, #1
 *   @0x251898 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x25189c b 0x251760 <_Z26JS_Array_prototype_forEachR6RValueP9CInstanceS2_iPS_+0x24>
 *   @0x2518a0 mulseq r0, r4, r11
 *   @0x2518a4 andseq r4, r0, r4, asr r10
 *
 * ══ §67/81 JS_Number_Prototype_toFixed(RValue&, CInstance*, CInstance*, int, RValue*)  0x256ed8  size 364  89 条（0x256ed8..0x257044）
 * @func 0x256ed8 0x257044  size 364  89 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYCreateString(RValue*, char const*)×2 / JS_Number_Prototype_toFixed(RValue&, CInstance*, CInstance*, int, RValue*)+0x8c / F_JS_ToInteger(RValue&) / JS_Number_Prototype_toFixed(RValue&, CInstance*, CInstance*, int, RValue*)+0x90 / JSThrowRangeError(char const*) / YYObjectBase::FindValue(char const*) / 0xb65b0 / JS_Number_Prototype_toFixed(RValue&, CInstance*, CInstance*, int, RValue*)+0x104
 * 字段偏移 top8: 0x-28×2 / 0x144×1 / 0x4×1 / 0xf0×1 / 0xc8×1 / 0x-2c×1 / 0x-38×1 / 0x-34×1
 * VFP 指令 21 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x256ed8 push {r4, r5, r6, r7, r8, r11, lr}
 *   @0x256edc vpush {d8}
 *   @0x256ee0 add r11, sp, #32
 *   @0x256ee4 ldr r6, [pc, #0x144]
 *   @0x256ee8 sub sp, sp, #36
 *   @0x256eec cmp r3, #0
 *   @0x256ef0 ldr r6, [pc, r6]
 *   @0x256ef4 mov r7, r0
 *   @0x256ef8 mov r4, r1
 *   @0x256efc ldr r0, [r11, #0x4]
 *   @0x256f00 ldr r3, [r6]
 *   @0x256f04 str r3, [r11, #-0x28]
 *   @0x256f08 ble 0x256f64 <_Z27JS_Number_Prototype_toFixedR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x256f0c bl 0x24d730 <_Z14F_JS_ToIntegerR6RValue>
 *   @0x256f10 vmov d8, r0, r1
 *   @0x256f14 vcmpe.f64 d8, #0
 *   @0x256f18 vmrs APSR_nzcv, fpscr
 *   @0x256f1c bmi 0x256f30 <_Z27JS_Number_Prototype_toFixedR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x256f20 vmov.f64 d7, #2.000000e+01
 *   @0x256f24 vcmpe.f64 d8, d7
 *   @0x256f28 vmrs APSR_nzcv, fpscr
 *   @0x256f2c ble 0x256f68 <_Z27JS_Number_Prototype_toFixedR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x256f30 vcmp.f64 d8, d8
 *   @0x256f34 vmrs APSR_nzcv, fpscr
 *   @0x256f38 bvs 0x256f68 <_Z27JS_Number_Prototype_toFixedR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x256f3c ldr r0, [pc, #0xf0]
 *   @0x256f40 add r0, pc, r0
 *   @0x256f44 bl 0x253ea4 <_Z17JSThrowRangeErrorPKc>
 *   @0x256f48 ldr r2, [r11, #-0x28]
 *   @0x256f4c ldr r3, [r6]
 *   @0x256f50 cmp r2, r3
 *   @0x256f54 bne 0x25701c <_Z27JS_Number_Prototype_toFixedR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x256f58 sub sp, r11, #32
 *   @0x256f5c vpop {d8}
 *   @0x256f60 pop {r4, r5, r6, r7, r8, r11, pc}
 *   @0x256f64 vldr d8, [pc, #180]
 *   @0x256f68 ldr r1, [pc, #0xc8]
 *   @0x256f6c mov r0, r4
 *   @0x256f70 mov r8, #0
 *   @0x256f74 str r8, [r11, #-0x2c]
 *   @0x256f78 add r1, pc, r1
 *   @0x256f7c bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc>
 *   @0x256f80 ldm r0, {r4, r5}
 *   @0x256f84 vmov d6, r4, r5
 *   @0x256f88 str r4, [r11, #-0x38]
 *   @0x256f8c str r5, [r11, #-0x34]
 *   @0x256f90 vmov d7, r4, r5
 *   @0x256f94 vcmp.f64 d6, d7
 *   @0x256f98 vmrs APSR_nzcv, fpscr
 *   @0x256f9c bvs 0x257008 <_Z27JS_Number_Prototype_toFixedR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x256fa0 sub sp, sp, #264
 *   @0x256fa4 mov r1, r8
 *   @0x256fa8 add r8, sp, #8
 *   @0x256fac mov r2, #256
 *   @0x256fb0 mov r0, r8
 *   @0x256fb4 bl 0xb65b0 <memset@plt>
 *   @0x256fb8 vmov d6, r4, r5
 *   @0x256fbc vldr d7, [pc, #100]
 *   @0x256fc0 vcmpe.f64 d6, d7
 *   @0x256fc4 vmrs APSR_nzcv, fpscr
 *   @0x256fc8 blt 0x256fdc <_Z27JS_Number_Prototype_toFixedR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0x256fcc mov r0, r7
 *   @0x256fd0 sub r1, r11, #56
 *   @0x256fd4 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x256fd8 b 0x256f48 <_Z27JS_Number_Prototype_toFixedR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x256fdc vcvt.s32.f64 s13, d8
 *   @0x256fe0 ldr r1, [pc, #0x54]
 *   @0x256fe4 strd r4, r5, [sp]
 *   @0x256fe8 mov r0, r8
 *   @0x256fec add r1, pc, r1
 *   @0x256ff0 vmov r2, s13
 *   @0x256ff4 bl 0xb6550 <sprintf@plt>
 *   @0x256ff8 mov r0, r7
 *   @0x256ffc mov r1, r8
 *   @0x257000 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x257004 b 0x256f48 <_Z27JS_Number_Prototype_toFixedR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x257008 ldr r1, [pc, #0x30]
 *   @0x25700c mov r0, r7
 *   @0x257010 add r1, pc, r1
 *   @0x257014 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x257018 b 0x256f48 <_Z27JS_Number_Prototype_toFixedR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x25701c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x257028 usatle lr, #0x2, r0, asr #30
 *   @0x25702c strbmi r1, [r11], #-2788
 *   @0x257030 andseq r6, r9, r0, ror #20
 *   @0x257034 andeq pc, pc, r8, lsr #22
 *   @0x257038 muleq pc, r8, r5
 *   @0x25703c andeq pc, pc, r0, asr #21
 *   @0x257040 andeq r11, sp, r4, ror #9
 *
 * ══ §68/81 pcre_pattern_to_host_byte_order  0x25df90  size 364  91 条（0x25df90..0x25e0fc）
 * @func 0x25df90 0x25e0fc  size 364  91 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×5 / 0x28×4 / 0xc×3 / 0x1c×2 / 0x8×2 / 0x10×2 / 0x14×2 / 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x25df90 cmp r0, #0
 *   @0x25df94 push {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x25df98 beq 0x25e0f4 <pcre_pattern_to_host_byte_order+0x164>
 *   @0x25df9c ldr r12, [r0]
 *   @0x25dfa0 movw r3, #0x5245
 *   @0x25dfa4 movt r3, #0x5043
 *   @0x25dfa8 cmp r12, r3
 *   @0x25dfac beq 0x25e0c0 <pcre_pattern_to_host_byte_order+0x130>
 *   @0x25dfb0 movw r4, #0x4350
 *   @0x25dfb4 movt r4, #0x4552
 *   @0x25dfb8 cmp r12, r4
 *   @0x25dfbc bne 0x25e0dc <pcre_pattern_to_host_byte_order+0x14c>
 *   @0x25dfc0 ldr r12, [r0, #0xc]
 *   @0x25dfc4 rev r12, r12
 *   @0x25dfc8 tst r12, #1
 *   @0x25dfcc beq 0x25e0ec <pcre_pattern_to_host_byte_order+0x15c>
 *   @0x25dfd0 ldrh r11, [r0, #28]
 *   @0x25dfd4 cmp r1, #0
 *   @0x25dfd8 ldr r9, [r0, #0x4]
 *   @0x25dfdc ldr r8, [r0, #0x8]
 *   @0x25dfe0 ldr r7, [r0, #0x10]
 *   @0x25dfe4 rev r9, r9
 *   @0x25dfe8 ldr r6, [r0, #0x14]
 *   @0x25dfec rev r8, r8
 *   @0x25dff0 ldrh r5, [r0, #24]
 *   @0x25dff4 rev r7, r7
 *   @0x25dff8 ldrh r4, [r0, #26]
 *   @0x25dffc rev r6, r6
 *   @0x25e000 ldrh r10, [r0, #30]
 *   @0x25e004 rev16 r5, r5
 *   @0x25e008 str r3, [r0]
 *   @0x25e00c rev16 r3, r11
 *   @0x25e010 str r12, [r0, #0xc]
 *   @0x25e014 rev16 r4, r4
 *   @0x25e018 ldrh r11, [r0, #32]
 *   @0x25e01c rev16 r10, r10
 *   @0x25e020 ldrh r12, [r0, #34]
 *   @0x25e024 str r2, [r0, #0x30]
 *   @0x25e028 rev16 r11, r11
 *   @0x25e02c ldrh r2, [r0, #36]
 *   @0x25e030 rev16 r12, r12
 *   @0x25e034 str r9, [r0, #0x4]
 *   @0x25e038 str r8, [r0, #0x8]
 *   @0x25e03c rev16 r2, r2
 *   @0x25e040 ldrh r9, [r0, #38]
 *   @0x25e044 ldrh r8, [r0, #40]
 *   @0x25e048 rev16 r9, r9
 *   @0x25e04c str r7, [r0, #0x10]
 *   @0x25e050 rev16 r8, r8
 *   @0x25e054 str r6, [r0, #0x14]
 *   @0x25e058 strh r5, [r0, #24]
 *   @0x25e05c strh r4, [r0, #26]
 *   @0x25e060 strh r3, [r0, #28]
 *   @0x25e064 strh r10, [r0, #30]
 *   @0x25e068 strh r11, [r0, #32]
 *   @0x25e06c strh r12, [r0, #34]
 *   @0x25e070 strh r2, [r0, #36]
 *   @0x25e074 strh r9, [r0, #38]
 *   @0x25e078 strh r8, [r0, #40]
 *   @0x25e07c beq 0x25e0e4 <pcre_pattern_to_host_byte_order+0x154>
 *   @0x25e080 ldr r0, [r1]
 *   @0x25e084 ands r0, r0, #1
 *   @0x25e088 beq 0x25e0b8 <pcre_pattern_to_host_byte_order+0x128>
 *   @0x25e08c ldr r3, [r1, #0x4]
 *   @0x25e090 mov r0, #0
 *   @0x25e094 ldr r12, [r3]
 *   @0x25e098 ldr r1, [r3, #0x4]
 *   @0x25e09c ldr r2, [r3, #0x28]
 *   @0x25e0a0 rev r12, r12
 *   @0x25e0a4 rev r1, r1
 *   @0x25e0a8 str r12, [r3]
 *   @0x25e0ac rev r2, r2
 *   @0x25e0b0 str r1, [r3, #0x4]
 *   @0x25e0b4 str r2, [r3, #0x28]
 *   @0x25e0b8 pop {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x25e0bc bx lr
 *   @0x25e0c0 ldr r3, [r0, #0xc]
 *   @0x25e0c4 tst r3, #1
 *   @0x25e0c8 beq 0x25e0ec <pcre_pattern_to_host_byte_order+0x15c>
 *   @0x25e0cc str r2, [r0, #0x30]
 *   @0x25e0d0 mov r0, #0
 *   @0x25e0d4 pop {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x25e0d8 bx lr
 *   @0x25e0dc mvn r0, #3
 *   @0x25e0e0 b 0x25e0b8 <pcre_pattern_to_host_byte_order+0x128>
 *   @0x25e0e4 mov r0, r1
 *   @0x25e0e8 b 0x25e0b8 <pcre_pattern_to_host_byte_order+0x128>
 *   @0x25e0ec mvn r0, #27
 *   @0x25e0f0 b 0x25e0b8 <pcre_pattern_to_host_byte_order+0x128>
 *   @0x25e0f4 mvn r0, #1
 *   @0x25e0f8 b 0x25e0b8 <pcre_pattern_to_host_byte_order+0x128>
 *
 * ══ §69/81 CBackground::LoadFromFileData(char const*, void*, int, bool, bool, bool, bool)  0xc281c  size 360  90 条（0xc281c..0xc2984）
 * @func 0xc281c 0xc2984  size 360  90 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBackground::LoadFromGIFData(void*, int, bool, bool, bool, bool) / CBackground::LoadFromPNGData(void*, int, bool, bool, bool, bool) / CBackground::LoadFromJPEGData(void*, int, bool, bool, bool, bool)
 * 字段偏移 top8: 0x1×3 / 0x2×3 / 0x4×3 / 0x8×3 / 0x3×2 / 0x38×1 / 0x3c×1 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc281c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xc2820 sub sp, sp, #20
 *   @0xc2824 ldrb r12, [r2]
 *   @0xc2828 mov r4, r2
 *   @0xc282c mov r5, r1
 *   @0xc2830 mov r7, r3
 *   @0xc2834 cmp r12, #255
 *   @0xc2838 mov r11, r0
 *   @0xc283c ldrb r6, [sp, #0x38]
 *   @0xc2840 ldrb r10, [sp, #0x3c]
 *   @0xc2844 ldrb r9, [sp, #0x40]
 *   @0xc2848 ldrb r8, [sp, #0x44]
 *   @0xc284c beq 0xc2900 <_ZN11CBackground16LoadFromFileDataEPKcPvibbbb+0xe4>
 *   @0xc2850 cmp r12, #71
 *   @0xc2854 bne 0xc28a8 <_ZN11CBackground16LoadFromFileDataEPKcPvibbbb+0x8c>
 *   @0xc2858 ldrb r3, [r4, #0x1]
 *   @0xc285c cmp r3, #73
 *   @0xc2860 bne 0xc290c <_ZN11CBackground16LoadFromFileDataEPKcPvibbbb+0xf0>
 *   @0xc2864 ldrb r3, [r4, #0x2]
 *   @0xc2868 cmp r3, #70
 *   @0xc286c bne 0xc290c <_ZN11CBackground16LoadFromFileDataEPKcPvibbbb+0xf0>
 *   @0xc2870 ldrb r3, [r4, #0x3]
 *   @0xc2874 cmp r3, #56
 *   @0xc2878 bne 0xc290c <_ZN11CBackground16LoadFromFileDataEPKcPvibbbb+0xf0>
 *   @0xc287c str r10, [sp]
 *   @0xc2880 mov r0, r11
 *   @0xc2884 str r9, [sp, #0x4]
 *   @0xc2888 mov r1, r4
 *   @0xc288c str r8, [sp, #0x8]
 *   @0xc2890 mov r2, r7
 *   @0xc2894 mov r3, r6
 *   @0xc2898 bl 0xc279c <_ZN11CBackground15LoadFromGIFDataEPvibbbb>
 *   @0xc289c cmp r0, #0
 *   @0xc28a0 bne 0xc296c <_ZN11CBackground16LoadFromFileDataEPKcPvibbbb+0x150>
 *   @0xc28a4 ldrb r12, [r4]
 *   @0xc28a8 cmp r12, #137
 *   @0xc28ac bne 0xc290c <_ZN11CBackground16LoadFromFileDataEPKcPvibbbb+0xf0>
 *   @0xc28b0 ldrb r3, [r4, #0x1]
 *   @0xc28b4 cmp r3, #80
 *   @0xc28b8 bne 0xc290c <_ZN11CBackground16LoadFromFileDataEPKcPvibbbb+0xf0>
 *   @0xc28bc ldrb r3, [r4, #0x2]
 *   @0xc28c0 cmp r3, #78
 *   @0xc28c4 bne 0xc290c <_ZN11CBackground16LoadFromFileDataEPKcPvibbbb+0xf0>
 *   @0xc28c8 ldrb r3, [r4, #0x3]
 *   @0xc28cc cmp r3, #71
 *   @0xc28d0 bne 0xc290c <_ZN11CBackground16LoadFromFileDataEPKcPvibbbb+0xf0>
 *   @0xc28d4 str r10, [sp]
 *   @0xc28d8 mov r0, r11
 *   @0xc28dc str r9, [sp, #0x4]
 *   @0xc28e0 mov r1, r4
 *   @0xc28e4 str r8, [sp, #0x8]
 *   @0xc28e8 mov r2, r7
 *   @0xc28ec mov r3, r6
 *   @0xc28f0 bl 0xc26ac <_ZN11CBackground15LoadFromPNGDataEPvibbbb>
 *   @0xc28f4 cmp r0, #0
 *   @0xc28f8 bne 0xc2934 <_ZN11CBackground16LoadFromFileDataEPKcPvibbbb+0x118>
 *   @0xc28fc b 0xc290c <_ZN11CBackground16LoadFromFileDataEPKcPvibbbb+0xf0>
 *   @0xc2900 ldrb r3, [r2, #0x1]
 *   @0xc2904 cmp r3, #216
 *   @0xc2908 beq 0xc293c <_ZN11CBackground16LoadFromFileDataEPKcPvibbbb+0x120>
 *   @0xc290c ldr r3, [pc, #0x68]
 *   @0xc2910 mov r2, r5
 *   @0xc2914 ldr r1, [pc, #0x64]
 *   @0xc2918 ldr r3, [pc, r3]
 *   @0xc291c add r1, pc, r1
 *   @0xc2920 ldr r0, [r3]
 *   @0xc2924 ldr r3, [r0]
 *   @0xc2928 ldr r3, [r3, #0xc]
 *   @0xc292c blx r3
 *   @0xc2930 mov r0, #0
 *   @0xc2934 add sp, sp, #20
 *   @0xc2938 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xc293c ldrb r3, [r2, #0x2]
 *   @0xc2940 cmp r3, #255
 *   @0xc2944 bne 0xc290c <_ZN11CBackground16LoadFromFileDataEPKcPvibbbb+0xf0>
 *   @0xc2948 mov r1, r2
 *   @0xc294c str r10, [sp]
 *   @0xc2950 str r9, [sp, #0x4]
 *   @0xc2954 mov r2, r7
 *   @0xc2958 str r8, [sp, #0x8]
 *   @0xc295c mov r3, r6
 *   @0xc2960 bl 0xc271c <_ZN11CBackground16LoadFromJPEGDataEPvibbbb>
 *   @0xc2964 cmp r0, #0
 *   @0xc2968 beq 0xc2974 <_ZN11CBackground16LoadFromFileDataEPKcPvibbbb+0x158>
 *   @0xc296c mov r0, #1
 *   @0xc2970 b 0xc2934 <_ZN11CBackground16LoadFromFileDataEPKcPvibbbb+0x118>
 *   @0xc2974 ldrb r12, [r4]
 *   @0xc2978 b 0xc2850 <_ZN11CBackground16LoadFromFileDataEPKcPvibbbb+0x34>
 *   @0xc297c ldrshteq r10, [r2], -r12
 *   @0xc2980 .word 0x0026e0f0
 *
 * ══ §70/81 IBuffer::SHA1(RValue*, int, int)  0xcbdb4  size 360  90 条（0xcbdb4..0xcbf1c）
 * @func 0xcbdb4 0xcbf1c  size 360  90 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SHA1Reset(SHA1Context*) / SHA1Input(SHA1Context*, unsigned char const*, unsigned int) / SHA1Result(SHA1Context*) / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb6550 / YYCreateString(RValue*, char const*) / MemoryManager::Free(void const*) / IBuffer::SHA1(RValue*, int, int)+0x60
 * 字段偏移 top8: 0x6c×2 / 0xc×2 / 0x14c×1 / 0x18×1 / 0x10×1 / 0xa4×1 / 0xa0×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcbdb4 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xcbdb8 mov r5, r3
 *   @0xcbdbc ldr r8, [pc, #0x14c]
 *   @0xcbdc0 sub sp, sp, #112
 *   @0xcbdc4 subs r9, r1, #0
 *   @0xcbdc8 mov r6, r0
 *   @0xcbdcc ldr r8, [pc, r8]
 *   @0xcbdd0 mov r4, r2
 *   @0xcbdd4 ldr r3, [r8]
 *   @0xcbdd8 str r3, [sp, #0x6c]
 *   @0xcbddc beq 0xcbecc <_ZN7IBuffer4SHA1EP6RValueii+0x118>
 *   @0xcbde0 cmp r5, #0
 *   @0xcbde4 ldr r2, [r0, #0x18]
 *   @0xcbde8 ldrlt r5, [r0, #0x10]
 *   @0xcbdec ldrge r3, [r0, #0x10]
 *   @0xcbdf0 movlt r3, r5
 *   @0xcbdf4 cmp r2, #2
 *   @0xcbdf8 beq 0xcbee4 <_ZN7IBuffer4SHA1EP6RValueii+0x130>
 *   @0xcbdfc bic r4, r4, r4, asr #31
 *   @0xcbe00 cmp r4, r3
 *   @0xcbe04 subge r4, r3, #1
 *   @0xcbe08 add r2, r4, r5
 *   @0xcbe0c cmp r2, r3
 *   @0xcbe10 rsbgt r5, r4, r3
 *   @0xcbe14 add r7, sp, #4
 *   @0xcbe18 mov r3, #1
 *   @0xcbe1c str r3, [r9, #0xc]
 *   @0xcbe20 mov r0, r7
 *   @0xcbe24 bl 0x214294 <_Z9SHA1ResetP11SHA1Context>
 *   @0xcbe28 cmp r5, #0
 *   @0xcbe2c bgt 0xcbe38 <_ZN7IBuffer4SHA1EP6RValueii+0x84>
 *   @0xcbe30 b 0xcbe64 <_ZN7IBuffer4SHA1EP6RValueii+0xb0>
 *   @0xcbe34 mov r4, #0
 *   @0xcbe38 ldr r2, [r6, #0x10]
 *   @0xcbe3c mov r0, r7
 *   @0xcbe40 ldr r1, [r6, #0xc]
 *   @0xcbe44 rsb r2, r4, r2
 *   @0xcbe48 cmp r2, r5
 *   @0xcbe4c movge r2, r5
 *   @0xcbe50 add r1, r1, r4
 *   @0xcbe54 rsb r5, r2, r5
 *   @0xcbe58 bl 0x214538 <_Z9SHA1InputP11SHA1ContextPKhj>
 *   @0xcbe5c cmp r5, #0
 *   @0xcbe60 bgt 0xcbe34 <_ZN7IBuffer4SHA1EP6RValueii+0x80>
 *   @0xcbe64 mov r0, r7
 *   @0xcbe68 ldr r6, [pc, #0xa4]
 *   @0xcbe6c bl 0x2146e4 <_Z10SHA1ResultP11SHA1Context>
 *   @0xcbe70 ldr r1, [pc, #0xa0]
 *   @0xcbe74 mov r0, #45
 *   @0xcbe78 movw r2, #0x52a
 *   @0xcbe7c add r1, pc, r1
 *   @0xcbe80 mov r3, #1
 *   @0xcbe84 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xcbe88 add r7, sp, #20
 *   @0xcbe8c add r6, pc, r6
 *   @0xcbe90 mov r4, sp
 *   @0xcbe94 mov r10, r0
 *   @0xcbe98 mov r5, r0
 *   @0xcbe9c ldr r2, [r4, #0x4]!
 *   @0xcbea0 mov r0, r5
 *   @0xcbea4 mov r1, r6
 *   @0xcbea8 add r5, r5, #8
 *   @0xcbeac bl 0xb6550 <sprintf@plt>
 *   @0xcbeb0 cmp r4, r7
 *   @0xcbeb4 bne 0xcbe9c <_ZN7IBuffer4SHA1EP6RValueii+0xe8>
 *   @0xcbeb8 mov r0, r9
 *   @0xcbebc mov r1, r10
 *   @0xcbec0 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0xcbec4 mov r0, r10
 *   @0xcbec8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xcbecc ldr r2, [sp, #0x6c]
 *   @0xcbed0 ldr r3, [r8]
 *   @0xcbed4 cmp r2, r3
 *   @0xcbed8 bne 0xcbf0c <_ZN7IBuffer4SHA1EP6RValueii+0x158>
 *   @0xcbedc add sp, sp, #112
 *   @0xcbee0 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xcbee4 cmp r4, #0
 *   @0xcbee8 bge 0xcbef4 <_ZN7IBuffer4SHA1EP6RValueii+0x140>
 *   @0xcbeec adds r4, r4, r3
 *   @0xcbef0 bmi 0xcbeec <_ZN7IBuffer4SHA1EP6RValueii+0x138>
 *   @0xcbef4 cmp r4, r3
 *   @0xcbef8 blt 0xcbe14 <_ZN7IBuffer4SHA1EP6RValueii+0x60>
 *   @0xcbefc rsb r4, r3, r4
 *   @0xcbf00 cmp r4, r3
 *   @0xcbf04 bge 0xcbefc <_ZN7IBuffer4SHA1EP6RValueii+0x148>
 *   @0xcbf08 b 0xcbe14 <_ZN7IBuffer4SHA1EP6RValueii+0x60>
 *   @0xcbf0c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0xcbf10 eorseq r1, r2, r4, lsl #23
 *   @0xcbf14 eoreq r6, r6, r0, lsr #6
 *   @0xcbf18 .word 0x002662f4
 *
 * ══ §71/81 F_Rectangle_In_Circle(RValue&, CInstance*, CInstance*, int, RValue*)  0x107de8  size 360  90 条（0x107de8..0x107f50）
 * @func 0x107de8 0x107f50  size 360  90 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×7 / F_Rectangle_In_Circle(RValue&, CInstance*, CInstance*, int, RValue*)+0x160×4
 * 字段偏移 top8: 0x28×1 / 0xc×1 / 0x4×1
 * VFP 指令 50 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x107de8 push {r4, r5, r6, lr}
 *   @0x107dec vpush {d8, d9, d10}
 *   @0x107df0 mov r5, #0
 *   @0x107df4 ldr r4, [sp, #0x28]
 *   @0x107df8 mov r6, r0
 *   @0x107dfc str r5, [r0, #0xc]
 *   @0x107e00 mov r1, r5
 *   @0x107e04 mov r0, r4
 *   @0x107e08 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x107e0c mov r1, #1
 *   @0x107e10 vmov s19, r0
 *   @0x107e14 mov r0, r4
 *   @0x107e18 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x107e1c mov r1, #2
 *   @0x107e20 vmov s18, r0
 *   @0x107e24 mov r0, r4
 *   @0x107e28 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x107e2c mov r1, #3
 *   @0x107e30 vmov s20, r0
 *   @0x107e34 mov r0, r4
 *   @0x107e38 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x107e3c mov r1, #4
 *   @0x107e40 vmov s21, r0
 *   @0x107e44 mov r0, r4
 *   @0x107e48 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x107e4c mov r1, #5
 *   @0x107e50 vmov s16, r0
 *   @0x107e54 mov r0, r4
 *   @0x107e58 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x107e5c mov r1, #6
 *   @0x107e60 vmov s17, r0
 *   @0x107e64 mov r0, r4
 *   @0x107e68 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x107e6c vcmpe.f32 s19, s16
 *   @0x107e70 vmrs APSR_nzcv, fpscr
 *   @0x107e74 vmovle.f32 s15, s16
 *   @0x107e78 vmovgt.f32 s15, s19
 *   @0x107e7c vcmp.f32 s15, s20
 *   @0x107e80 vmrs APSR_nzcv, fpscr
 *   @0x107e84 vcmpe.f32 s18, s17
 *   @0x107e88 vmovgt.f32 s15, s20
 *   @0x107e8c vmrs APSR_nzcv, fpscr
 *   @0x107e90 vmovle.f32 s14, s17
 *   @0x107e94 vmovgt.f32 s14, s18
 *   @0x107e98 vcmp.f32 s14, s21
 *   @0x107e9c vmrs APSR_nzcv, fpscr
 *   @0x107ea0 vmovgt.f32 s14, s21
 *   @0x107ea4 vsub.f32 s14, s14, s17
 *   @0x107ea8 vmov s12, r0
 *   @0x107eac vmul.f32 s14, s14, s14
 *   @0x107eb0 vsub.f32 s15, s15, s16
 *   @0x107eb4 vmla.f32 s14, s15, s15
 *   @0x107eb8 vmul.f32 s15, s12, s12
 *   @0x107ebc vcmpe.f32 s15, s14
 *   @0x107ec0 vmrs APSR_nzcv, fpscr
 *   @0x107ec4 strlt r5, [r6]
 *   @0x107ec8 strlt r5, [r6, #0x4]
 *   @0x107ecc blt 0x107f48 <_Z21F_Rectangle_In_CircleR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x107ed0 vsub.f32 s19, s19, s16
 *   @0x107ed4 mov r3, #1073741824
 *   @0x107ed8 str r5, [r6]
 *   @0x107edc str r3, [r6, #0x4]
 *   @0x107ee0 vsub.f32 s18, s18, s17
 *   @0x107ee4 vmul.f32 s19, s19, s19
 *   @0x107ee8 vmul.f32 s18, s18, s18
 *   @0x107eec vadd.f32 s14, s19, s18
 *   @0x107ef0 vcmpe.f32 s15, s14
 *   @0x107ef4 vmrs APSR_nzcv, fpscr
 *   @0x107ef8 blt 0x107f48 <_Z21F_Rectangle_In_CircleR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x107efc vsub.f32 s16, s20, s16
 *   @0x107f00 vmul.f32 s16, s16, s16
 *   @0x107f04 vadd.f32 s18, s18, s16
 *   @0x107f08 vcmpe.f32 s15, s18
 *   @0x107f0c vmrs APSR_nzcv, fpscr
 *   @0x107f10 blt 0x107f48 <_Z21F_Rectangle_In_CircleR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x107f14 vsub.f32 s17, s21, s17
 *   @0x107f18 vmul.f32 s17, s17, s17
 *   @0x107f1c vadd.f32 s16, s16, s17
 *   @0x107f20 vcmpe.f32 s15, s16
 *   @0x107f24 vmrs APSR_nzcv, fpscr
 *   @0x107f28 blt 0x107f48 <_Z21F_Rectangle_In_CircleR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x107f2c vadd.f32 s17, s19, s17
 *   @0x107f30 vcmpe.f32 s15, s17
 *   @0x107f34 vmrs APSR_nzcv, fpscr
 *   @0x107f38 movge r3, #0
 *   @0x107f3c strge r5, [r6]
 *   @0x107f40 movtge r3, #0x3ff0
 *   @0x107f44 strge r3, [r6, #0x4]
 *   @0x107f48 vpop {d8, d9, d10}
 *   @0x107f4c pop {r4, r5, r6, pc}
 *
 * ══ §72/81 F_StringCopy(RValue&, CInstance*, CInstance*, int, RValue*)  0x10fcc0  size 360  90 条（0x10fcc0..0x10fe28）
 * @func 0x10fcc0 0x10fe28  size 360  90 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / utf8_extract_char×2 / operator new(unsigned int)×2 / YYAlloc(int)×2 / YYGetString(RValue const*, int) / 0xb65bc
 * 字段偏移 top8: 0x4×6 / 0xc×2 / 0x8×2 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10fcc0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x10fcc4 sub sp, sp, #12
 *   @0x10fcc8 mov r1, #0
 *   @0x10fccc mov r8, r0
 *   @0x10fcd0 ldr r4, [sp, #0x30]
 *   @0x10fcd4 mov r0, r4
 *   @0x10fcd8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x10fcdc mov r1, #1
 *   @0x10fce0 mov r5, r0
 *   @0x10fce4 mov r0, r4
 *   @0x10fce8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x10fcec mov r1, #2
 *   @0x10fcf0 mov r7, r0
 *   @0x10fcf4 mov r0, r4
 *   @0x10fcf8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x10fcfc cmp r7, #0
 *   @0x10fd00 subgt r7, r7, #1
 *   @0x10fd04 movle r7, #0
 *   @0x10fd08 cmp r5, #0
 *   @0x10fd0c bic r6, r0, r0, asr #31
 *   @0x10fd10 beq 0x10fdec <_Z12F_StringCopyR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x10fd14 cmp r7, #0
 *   @0x10fd18 str r5, [sp, #0x4]
 *   @0x10fd1c beq 0x10fde4 <_Z12F_StringCopyR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x10fd20 add r5, sp, #4
 *   @0x10fd24 mov r4, #0
 *   @0x10fd28 add r4, r4, #1
 *   @0x10fd2c mov r0, r5
 *   @0x10fd30 bl 0x10fb38 <utf8_extract_char>
 *   @0x10fd34 cmp r4, r7
 *   @0x10fd38 bne 0x10fd28 <_Z12F_StringCopyR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x10fd3c ldr r7, [sp, #0x4]
 *   @0x10fd40 cmp r6, #0
 *   @0x10fd44 beq 0x10fe1c <_Z12F_StringCopyR6RValueP9CInstanceS2_iPS_+0x15c>
 *   @0x10fd48 add r5, sp, #4
 *   @0x10fd4c mov r4, #0
 *   @0x10fd50 b 0x10fd5c <_Z12F_StringCopyR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x10fd54 cmp r4, r6
 *   @0x10fd58 beq 0x10fdd0 <_Z12F_StringCopyR6RValueP9CInstanceS2_iPS_+0x110>
 *   @0x10fd5c mov r0, r5
 *   @0x10fd60 add r4, r4, #1
 *   @0x10fd64 bl 0x10fb38 <utf8_extract_char>
 *   @0x10fd68 cmp r0, #0
 *   @0x10fd6c bne 0x10fd54 <_Z12F_StringCopyR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x10fd70 ldr r5, [sp, #0x4]
 *   @0x10fd74 sub r5, r5, #1
 *   @0x10fd78 str r5, [sp, #0x4]
 *   @0x10fd7c rsb r5, r7, r5
 *   @0x10fd80 add r11, r5, #1
 *   @0x10fd84 mov r6, r5
 *   @0x10fd88 mov r9, #1
 *   @0x10fd8c mov r0, #12
 *   @0x10fd90 str r9, [r8, #0xc]
 *   @0x10fd94 mov r10, #0
 *   @0x10fd98 bl 0x27c524 <_Znwj>
 *   @0x10fd9c mov r4, r0
 *   @0x10fda0 mov r0, r11
 *   @0x10fda4 bl 0xcef4c <_Z7YYAlloci>
 *   @0x10fda8 str r9, [r4, #0x4]
 *   @0x10fdac str r5, [r4, #0x8]
 *   @0x10fdb0 mov r1, r7
 *   @0x10fdb4 mov r2, r6
 *   @0x10fdb8 str r0, [r4]
 *   @0x10fdbc str r4, [r8]
 *   @0x10fdc0 bl 0xb65bc <memcpy@plt>
 *   @0x10fdc4 strb r10, [r0, r6]
 *   @0x10fdc8 add sp, sp, #12
 *   @0x10fdcc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x10fdd0 ldr r5, [sp, #0x4]
 *   @0x10fdd4 rsb r5, r7, r5
 *   @0x10fdd8 add r11, r5, #1
 *   @0x10fddc mov r6, r5
 *   @0x10fde0 b 0x10fd88 <_Z12F_StringCopyR6RValueP9CInstanceS2_iPS_+0xc8>
 *   @0x10fde4 mov r7, r5
 *   @0x10fde8 b 0x10fd40 <_Z12F_StringCopyR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x10fdec mov r6, #1
 *   @0x10fdf0 mov r0, #12
 *   @0x10fdf4 str r6, [r8, #0xc]
 *   @0x10fdf8 bl 0x27c524 <_Znwj>
 *   @0x10fdfc mov r4, r0
 *   @0x10fe00 mov r0, r6
 *   @0x10fe04 bl 0xcef4c <_Z7YYAlloci>
 *   @0x10fe08 str r5, [r4, #0x8]
 *   @0x10fe0c stm r4, {r0, r6}
 *   @0x10fe10 str r4, [r8]
 *   @0x10fe14 strb r5, [r0]
 *   @0x10fe18 b 0x10fdc8 <_Z12F_StringCopyR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x10fe1c mov r11, #1
 *   @0x10fe20 mov r5, r6
 *   @0x10fe24 b 0x10fd88 <_Z12F_StringCopyR6RValueP9CInstanceS2_iPS_+0xc8>
 *
 * ══ §73/81 F_DrawSpritePos(RValue&, CInstance*, CInstance*, int, RValue*)  0x11fb2c  size 360  90 条（0x11fb2c..0x11fc94）
 * @func 0x11fb2c 0x11fc94  size 360  90 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×9 / YYGetInt32(RValue const*, int)×2 / Sprite_Data(int) / CSprite::DrawPos(int, float, float, float, float, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0x24×3 / 0x28×2 / 0x2c×2 / 0x10×2 / 0x58×1 / 0x74×1 / 0x12c×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11fb2c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x11fb30 sub sp, sp, #52
 *   @0x11fb34 mov r1, #0
 *   @0x11fb38 ldr r4, [sp, #0x58]
 *   @0x11fb3c mov r0, r4
 *   @0x11fb40 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11fb44 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x11fb48 subs r5, r0, #0
 *   @0x11fb4c beq 0x11fc78 <_Z15F_DrawSpritePosR6RValueP9CInstanceS2_iPS_+0x14c>
 *   @0x11fb50 ldr r3, [r5, #0x74]
 *   @0x11fb54 ldr r0, [pc, #0x12c]
 *   @0x11fb58 cmp r3, #1
 *   @0x11fb5c add r0, pc, r0
 *   @0x11fb60 beq 0x11fc68 <_Z15F_DrawSpritePosR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x11fb64 cmp r3, #2
 *   @0x11fb68 beq 0x11fc60 <_Z15F_DrawSpritePosR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x11fb6c mov r0, r4
 *   @0x11fb70 mov r1, #1
 *   @0x11fb74 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11fb78 mov r1, #2
 *   @0x11fb7c mov r8, r0
 *   @0x11fb80 mov r0, r4
 *   @0x11fb84 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11fb88 mov r1, #3
 *   @0x11fb8c mov r7, r0
 *   @0x11fb90 mov r0, r4
 *   @0x11fb94 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11fb98 mov r1, #4
 *   @0x11fb9c mov r6, r0
 *   @0x11fba0 mov r0, r4
 *   @0x11fba4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11fba8 mov r1, #5
 *   @0x11fbac mov r12, r0
 *   @0x11fbb0 mov r0, r4
 *   @0x11fbb4 str r12, [sp, #0x24]
 *   @0x11fbb8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11fbbc mov r1, #6
 *   @0x11fbc0 mov r2, r0
 *   @0x11fbc4 mov r0, r4
 *   @0x11fbc8 str r2, [sp, #0x28]
 *   @0x11fbcc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11fbd0 mov r1, #7
 *   @0x11fbd4 mov r3, r0
 *   @0x11fbd8 mov r0, r4
 *   @0x11fbdc str r3, [sp, #0x2c]
 *   @0x11fbe0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11fbe4 mov r1, #8
 *   @0x11fbe8 mov r11, r0
 *   @0x11fbec mov r0, r4
 *   @0x11fbf0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11fbf4 mov r1, #9
 *   @0x11fbf8 mov r10, r0
 *   @0x11fbfc mov r0, r4
 *   @0x11fc00 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11fc04 mov r1, #10
 *   @0x11fc08 mov r9, r0
 *   @0x11fc0c mov r0, r4
 *   @0x11fc10 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11fc14 ldr r12, [sp, #0x24]
 *   @0x11fc18 ldr r2, [sp, #0x28]
 *   @0x11fc1c mov r1, r8
 *   @0x11fc20 ldr r3, [sp, #0x2c]
 *   @0x11fc24 str r12, [sp]
 *   @0x11fc28 mvn r12, #0
 *   @0x11fc2c str r2, [sp, #0x4]
 *   @0x11fc30 mov r2, r7
 *   @0x11fc34 str r3, [sp, #0x8]
 *   @0x11fc38 mov r3, r6
 *   @0x11fc3c str r11, [sp, #0xc]
 *   @0x11fc40 str r10, [sp, #0x10]
 *   @0x11fc44 str r9, [sp, #0x14]
 *   @0x11fc48 str r12, [sp, #0x18]
 *   @0x11fc4c str r0, [sp, #0x1c]
 *   @0x11fc50 mov r0, r5
 *   @0x11fc54 bl 0x1e5d64 <_ZN7CSprite7DrawPosEiffffffffjf>
 *   @0x11fc58 add sp, sp, #52
 *   @0x11fc5c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x11fc60 ldr r0, [pc, #0x24]
 *   @0x11fc64 add r0, pc, r0
 *   @0x11fc68 mov r1, #0
 *   @0x11fc6c add sp, sp, #52
 *   @0x11fc70 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x11fc74 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11fc78 ldr r0, [pc, #0x10]
 *   @0x11fc7c mov r1, r5
 *   @0x11fc80 add r0, pc, r0
 *   @0x11fc84 b 0x11fc6c <_Z15F_DrawSpritePosR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x11fc88 .word 0x0021a7d8
 *   @0x11fc8c eoreq r10, r1, r4, lsl #14
 *   @0x11fc90 eoreq r10, r1, r4, lsr r3
 *
 * ══ §74/81 F_ObjectSetParent(RValue&, CInstance*, CInstance*, int, RValue*)  0x130b44  size 360  90 条（0x130b44..0x130cac）
 * @func 0x130b44 0x130cac  size 360  90 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / CObjectGM::IsDecendentOf(int)
 * 字段偏移 top8: 0x4×5 / 0xc×4 / 0x3×3 / 0x8×3 / 0x18×1 / 0x124×1 / 0x48×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x130b44 push {r3, r4, r5, r6, r7, lr}
 *   @0x130b48 mov r1, #0
 *   @0x130b4c ldr r4, [sp, #0x18]
 *   @0x130b50 mov r0, r4
 *   @0x130b54 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x130b58 mov r1, #1
 *   @0x130b5c mov r5, r0
 *   @0x130b60 mov r0, r4
 *   @0x130b64 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x130b68 cmp r5, r0
 *   @0x130b6c mov r4, r0
 *   @0x130b70 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x130b74 ldr r6, [pc, #0x124]
 *   @0x130b78 ldr r6, [pc, r6]
 *   @0x130b7c ldr r3, [r6]
 *   @0x130b80 ldr r0, [r3, #0x4]
 *   @0x130b84 ldr r1, [r3]
 *   @0x130b88 and r3, r5, r0
 *   @0x130b8c ldr r3, [r1, r3, lsl #3]
 *   @0x130b90 cmp r3, #0
 *   @0x130b94 bne 0x130ba8 <_Z17F_ObjectSetParentR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x130b98 pop {r3, r4, r5, r6, r7, pc}
 *   @0x130b9c ldr r3, [r3, #0x4]
 *   @0x130ba0 cmp r3, #0
 *   @0x130ba4 beq 0x130c74 <_Z17F_ObjectSetParentR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x130ba8 ldr r2, [r3, #0x8]
 *   @0x130bac cmp r5, r2
 *   @0x130bb0 bne 0x130b9c <_Z17F_ObjectSetParentR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x130bb4 ldr r7, [r3, #0xc]
 *   @0x130bb8 cmp r7, #0
 *   @0x130bbc popeq {r3, r4, r5, r6, r7, pc}
 *   @0x130bc0 cmp r4, #0
 *   @0x130bc4 mvnlt r3, #0
 *   @0x130bc8 strlt r3, [r7, #0xc]
 *   @0x130bcc poplt {r3, r4, r5, r6, r7, pc}
 *   @0x130bd0 and r0, r4, r0
 *   @0x130bd4 ldr r3, [r1, r0, lsl #3]
 *   @0x130bd8 cmp r3, #0
 *   @0x130bdc bne 0x130bf0 <_Z17F_ObjectSetParentR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x130be0 b 0x130c8c <_Z17F_ObjectSetParentR6RValueP9CInstanceS2_iPS_+0x148>
 *   @0x130be4 ldr r3, [r3, #0x4]
 *   @0x130be8 cmp r3, #0
 *   @0x130bec beq 0x130c8c <_Z17F_ObjectSetParentR6RValueP9CInstanceS2_iPS_+0x148>
 *   @0x130bf0 ldr r2, [r3, #0x8]
 *   @0x130bf4 cmp r4, r2
 *   @0x130bf8 bne 0x130be4 <_Z17F_ObjectSetParentR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x130bfc ldr r0, [r3, #0xc]
 *   @0x130c00 cmp r0, #0
 *   @0x130c04 beq 0x130c8c <_Z17F_ObjectSetParentR6RValueP9CInstanceS2_iPS_+0x148>
 *   @0x130c08 mov r1, r5
 *   @0x130c0c bl 0x19ddb0 <_ZN9CObjectGM13IsDecendentOfEi>
 *   @0x130c10 cmp r0, #0
 *   @0x130c14 bne 0x130c78 <_Z17F_ObjectSetParentR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x130c18 movw r3, #0x423f
 *   @0x130c1c movt r3, #0xf
 *   @0x130c20 cmp r4, r3
 *   @0x130c24 str r4, [r7, #0xc]
 *   @0x130c28 bhi 0x130c6c <_Z17F_ObjectSetParentR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x130c2c ldr r3, [r6]
 *   @0x130c30 ldr r2, [r3, #0x4]
 *   @0x130c34 ldr r3, [r3]
 *   @0x130c38 and r2, r4, r2
 *   @0x130c3c ldr r3, [r3, r2, lsl #3]
 *   @0x130c40 cmp r3, #0
 *   @0x130c44 bne 0x130c58 <_Z17F_ObjectSetParentR6RValueP9CInstanceS2_iPS_+0x114>
 *   @0x130c48 b 0x130c68 <_Z17F_ObjectSetParentR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x130c4c ldr r3, [r3, #0x4]
 *   @0x130c50 cmp r3, #0
 *   @0x130c54 beq 0x130c68 <_Z17F_ObjectSetParentR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x130c58 ldr r2, [r3, #0x8]
 *   @0x130c5c cmp r4, r2
 *   @0x130c60 bne 0x130c4c <_Z17F_ObjectSetParentR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x130c64 ldr r3, [r3, #0xc]
 *   @0x130c68 str r3, [r7, #0x48]
 *   @0x130c6c pop {r3, r4, r5, r6, r7, lr}
 *   @0x130c70 b 0x19e7dc <_Z19Create_Object_Listsv>
 *   @0x130c74 pop {r3, r4, r5, r6, r7, pc}
 *   @0x130c78 ldr r0, [pc, #0x24]
 *   @0x130c7c mov r1, #0
 *   @0x130c80 pop {r3, r4, r5, r6, r7, lr}
 *   @0x130c84 add r0, pc, r0
 *   @0x130c88 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x130c8c ldr r0, [pc, #0x14]
 *   @0x130c90 mov r1, #0
 *   @0x130c94 pop {r3, r4, r5, r6, r7, lr}
 *   @0x130c98 add r0, pc, r0
 *   @0x130c9c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x130ca0 eoreq sp, r11, r4, asr #1
 *   @0x130ca4 .word 0x0020d6bc
 *   @0x130ca8 eoreq sp, r0, r8, lsl #13
 *
 * ══ §75/81 GR_Texture_Draw_Stretched(int, float, float, float, float, unsigned int, float)  0x174ad8  size 360  90 条（0x174ad8..0x174c40）
 * @func 0x174ad8 0x174c40  size 360  90 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Texture_Exists(int) / GR_Texture_Draw_Stretched(int, float, float, float, float, unsigned int, float)+0x14c / Graphics::AllocVerts(ePrimType, void*, int, int)
 * 字段偏移 top8: 0x24×2 / 0x114×1 / 0x4×1 / 0x2×1 / 0x88×1 / 0x70×1 / 0x10×1 / 0x8c×1
 * VFP 指令 39 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x174ad8 push {r4, r5, r6, lr}
 *   @0x174adc vpush {d8, d9}
 *   @0x174ae0 mov r4, r0
 *   @0x174ae4 vmov s17, r1
 *   @0x174ae8 vmov s16, r2
 *   @0x174aec vmov s18, r3
 *   @0x174af0 bl 0x173e2c <_Z17GR_Texture_Existsi>
 *   @0x174af4 subs r6, r0, #0
 *   @0x174af8 beq 0x174c18 <_Z25GR_Texture_Draw_Stretchediffffjf+0x140>
 *   @0x174afc vldr s15, [pc, #304]
 *   @0x174b00 vldr s14, [sp, #40]
 *   @0x174b04 vmul.f32 s15, s14, s15
 *   @0x174b08 vcvt.s32.f32 s15, s15
 *   @0x174b0c vmov r5, s15
 *   @0x174b10 cmp r5, #255
 *   @0x174b14 movgt r5, #-16777216
 *   @0x174b18 ble 0x174c24 <_Z25GR_Texture_Draw_Stretchediffffjf+0x14c>
 *   @0x174b1c ldr r1, [pc, #0x114]
 *   @0x174b20 mov r2, #24
 *   @0x174b24 ldr r3, [sp, #0x24]
 *   @0x174b28 mov r0, #4
 *   @0x174b2c ldr r1, [pc, r1]
 *   @0x174b30 bic r12, r3, #-16777216
 *   @0x174b34 mov r3, #6
 *   @0x174b38 ldr r1, [r1, #0x4]
 *   @0x174b3c orr r5, r5, r12
 *   @0x174b40 ldr r4, [r1, r4, lsl #2]
 *   @0x174b44 ldr r1, [r4]
 *   @0x174b48 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x174b4c mov r2, #0
 *   @0x174b50 vadd.f32 s14, s17, s18
 *   @0x174b54 str r2, [r0, #0x88]
 *   @0x174b58 str r2, [r0, #0x70]
 *   @0x174b5c str r2, [r0, #0x10]
 *   @0x174b60 str r2, [r0, #0x8c]
 *   @0x174b64 str r2, [r0, #0x2c]
 *   @0x174b68 str r2, [r0, #0x14]
 *   @0x174b6c vldr s13, [r4, #8]
 *   @0x174b70 ldrsh r12, [r4, #4]
 *   @0x174b74 vstr s16, [r0, #124]
 *   @0x174b78 vstr s16, [r0, #28]
 *   @0x174b7c vstr s16, [r0, #4]
 *   @0x174b80 vstr s14, [r0, #72]
 *   @0x174b84 vstr s14, [r0, #48]
 *   @0x174b88 vmov s15, r12
 *   @0x174b8c vstr s14, [r0, #24]
 *   @0x174b90 vldr s14, [sp, #32]
 *   @0x174b94 vadd.f32 s16, s16, s14
 *   @0x174b98 ldr r2, [pc, #0x9c]
 *   @0x174b9c vstr s17, [r0, #120]
 *   @0x174ba0 str r5, [r0, #0x54]
 *   @0x174ba4 vstr s17, [r0, #96]
 *   @0x174ba8 ldr r2, [pc, r2]
 *   @0x174bac str r5, [r0, #0x3c]
 *   @0x174bb0 vstr s17, [r0]
 *   @0x174bb4 str r5, [r0, #0x24]
 *   @0x174bb8 ldr r2, [r2]
 *   @0x174bbc str r5, [r0, #0xc]
 *   @0x174bc0 str r2, [r0, #0x80]
 *   @0x174bc4 str r2, [r0, #0x68]
 *   @0x174bc8 vcvt.f32.s32 s15, s15
 *   @0x174bcc str r2, [r0, #0x50]
 *   @0x174bd0 str r2, [r0, #0x38]
 *   @0x174bd4 vstr s16, [r0, #100]
 *   @0x174bd8 str r2, [r0, #0x20]
 *   @0x174bdc vstr s16, [r0, #76]
 *   @0x174be0 str r2, [r0, #0x8]
 *   @0x174be4 vmul.f32 s15, s15, s13
 *   @0x174be8 vstr s15, [r0, #88]
 *   @0x174bec vstr s16, [r0, #52]
 *   @0x174bf0 vstr s15, [r0, #64]
 *   @0x174bf4 vstr s15, [r0, #40]
 *   @0x174bf8 ldrsh r3, [r4, #6]
 *   @0x174bfc vldr s14, [r4, #12]
 *   @0x174c00 vmov s15, r3
 *   @0x174c04 vcvt.f32.s32 s15, s15
 *   @0x174c08 vmul.f32 s15, s15, s14
 *   @0x174c0c vstr s15, [r0, #116]
 *   @0x174c10 vstr s15, [r0, #92]
 *   @0x174c14 vstr s15, [r0, #68]
 *   @0x174c18 vpop {d8, d9}
 *   @0x174c1c mov r0, r6
 *   @0x174c20 pop {r4, r5, r6, pc}
 *   @0x174c24 cmp r5, #0
 *   @0x174c28 lslge r5, r5, #24
 *   @0x174c2c movlt r5, #0
 *   @0x174c30 b 0x174b1c <_Z25GR_Texture_Draw_Stretchediffffjf+0x44>
 *   @0x174c34 cmnmi pc, #0
 *   @0x174c38 .word 0x00278df0
 *   @0x174c3c eoreq r8, r7, r8, ror sp
 *
 * ══ §76/81 ReadPNGFilePreallocated(void*, int, int*, int*, void*, bool)  0x18a3b0  size 360  90 条（0x18a3b0..0x18a518）
 * @func 0x18a3b0 0x18a518  size 360  90 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ReadPNGFilePreallocated(void*, int, int*, int*, void*, bool)+0x130×3 / __divsi3×2 / operator new(unsigned int) / ReadPNG(yyPNGFile*) / ReadPNGFilePreallocated(void*, int, int*, int*, void*, bool)+0x158 / HalfTextureRGBA(int, int, unsigned int*, int, int, unsigned int*) / operator delete(void*)
 * 字段偏移 top8: 0xc×6 / 0x10×4 / 0x20×3 / 0x4×2 / 0x150×1 / 0x14c×1 / 0x34×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18a3b0 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x18a3b4 sub sp, sp, #20
 *   @0x18a3b8 ldr r5, [pc, #0x150]
 *   @0x18a3bc mov r9, r0
 *   @0x18a3c0 ldr r12, [pc, #0x14c]
 *   @0x18a3c4 mov r7, r2
 *   @0x18a3c8 ldrb lr, [sp, #0x34]
 *   @0x18a3cc ldr r5, [pc, r5]
 *   @0x18a3d0 ldr r12, [pc, r12]
 *   @0x18a3d4 mov r8, r3
 *   @0x18a3d8 cmp lr, #0
 *   @0x18a3dc ldr r6, [r5]
 *   @0x18a3e0 ldr r4, [r12]
 *   @0x18a3e4 moveq r4, #1
 *   @0x18a3e8 cmp r6, #0
 *   @0x18a3ec beq 0x18a424 <_Z23ReadPNGFilePreallocatedPviPiS0_S_b+0x74>
 *   @0x18a3f0 ldr r3, [r6, #0xc]
 *   @0x18a3f4 mov r0, r3
 *   @0x18a3f8 mov r1, r4
 *   @0x18a3fc bl 0x318d10 <__divsi3>
 *   @0x18a400 mov r1, r4
 *   @0x18a404 str r0, [r7]
 *   @0x18a408 ldr r0, [r6, #0x10]
 *   @0x18a40c bl 0x318d10 <__divsi3>
 *   @0x18a410 ldr r3, [r6, #0x20]
 *   @0x18a414 str r0, [r8]
 *   @0x18a418 mov r0, r3
 *   @0x18a41c add sp, sp, #20
 *   @0x18a420 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x18a424 mov r0, #40
 *   @0x18a428 str r1, [sp, #0xc]
 *   @0x18a42c bl 0x27c524 <_Znwj>
 *   @0x18a430 ldr r1, [sp, #0xc]
 *   @0x18a434 ldr r2, [sp, #0x30]
 *   @0x18a438 strb r6, [r0]
 *   @0x18a43c str r6, [r0, #0x24]
 *   @0x18a440 str r9, [r0, #0x4]
 *   @0x18a444 str r1, [r0, #0x8]
 *   @0x18a448 str r2, [r0, #0x20]
 *   @0x18a44c str r0, [r5]
 *   @0x18a450 bl 0x189e80 <_Z7ReadPNGP9yyPNGFile>
 *   @0x18a454 subs r6, r0, #0
 *   @0x18a458 beq 0x18a4e8 <_Z23ReadPNGFilePreallocatedPviPiS0_S_b+0x138>
 *   @0x18a45c cmp r4, #1
 *   @0x18a460 ble 0x18a508 <_Z23ReadPNGFilePreallocatedPviPiS0_S_b+0x158>
 *   @0x18a464 ldr r1, [r5]
 *   @0x18a468 ldr r3, [r1, #0xc]
 *   @0x18a46c cmp r3, #1
 *   @0x18a470 ble 0x18a4e0 <_Z23ReadPNGFilePreallocatedPviPiS0_S_b+0x130>
 *   @0x18a474 ldr r0, [r1, #0x10]
 *   @0x18a478 cmp r0, #1
 *   @0x18a47c movgt r6, r4
 *   @0x18a480 bgt 0x18a498 <_Z23ReadPNGFilePreallocatedPviPiS0_S_b+0xe8>
 *   @0x18a484 b 0x18a4e0 <_Z23ReadPNGFilePreallocatedPviPiS0_S_b+0x130>
 *   @0x18a488 cmp r3, #1
 *   @0x18a48c ble 0x18a4e0 <_Z23ReadPNGFilePreallocatedPviPiS0_S_b+0x130>
 *   @0x18a490 cmp r0, #1
 *   @0x18a494 ble 0x18a4e0 <_Z23ReadPNGFilePreallocatedPviPiS0_S_b+0x130>
 *   @0x18a498 ldr r2, [r1, #0x20]
 *   @0x18a49c asr r1, r0, #1
 *   @0x18a4a0 str r0, [sp]
 *   @0x18a4a4 asr r0, r3, #1
 *   @0x18a4a8 asr r6, r6, #1
 *   @0x18a4ac str r2, [sp, #0x4]
 *   @0x18a4b0 bl 0x18923c <_Z15HalfTextureRGBAiiPjiiS_>
 *   @0x18a4b4 ldr r1, [r5]
 *   @0x18a4b8 cmp r6, #1
 *   @0x18a4bc ldr r12, [r1, #0xc]
 *   @0x18a4c0 ldr r0, [r1, #0x10]
 *   @0x18a4c4 add r12, r12, r12, lsr #31
 *   @0x18a4c8 add r0, r0, r0, lsr #31
 *   @0x18a4cc asr r3, r12, #1
 *   @0x18a4d0 str r3, [r1, #0xc]
 *   @0x18a4d4 asr r0, r0, #1
 *   @0x18a4d8 str r0, [r1, #0x10]
 *   @0x18a4dc bgt 0x18a488 <_Z23ReadPNGFilePreallocatedPviPiS0_S_b+0xd8>
 *   @0x18a4e0 mov r6, r1
 *   @0x18a4e4 b 0x18a3f4 <_Z23ReadPNGFilePreallocatedPviPiS0_S_b+0x44>
 *   @0x18a4e8 ldr r0, [r5]
 *   @0x18a4ec bl 0x27d1d0 <_ZdlPv>
 *   @0x18a4f0 str r6, [r5]
 *   @0x18a4f4 mvn r2, #0
 *   @0x18a4f8 mov r3, r6
 *   @0x18a4fc str r2, [r7]
 *   @0x18a500 str r2, [r8]
 *   @0x18a504 b 0x18a418 <_Z23ReadPNGFilePreallocatedPviPiS0_S_b+0x68>
 *   @0x18a508 ldr r6, [r5]
 *   @0x18a50c b 0x18a3f0 <_Z23ReadPNGFilePreallocatedPviPiS0_S_b+0x40>
 *   @0x18a510 .word 0x002661f4
 *   @0x18a514 eoreq r4, r6, r4, lsl #4
 *
 * ══ §77/81 YYObjectBase::Mark4GenGC(unsigned int**, int, YYObjectBase*)  0x19206c  size 360  90 条（0x19206c..0x1921d4）
 * @func 0x19206c 0x1921d4  size 360  90 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RVALUE_GEN_GC(RValue const*, unsigned int**, int, YYObjectBase*)×2 / YYObjectBase::Mark4GenGC(unsigned int**, int, YYObjectBase*)+0x74 / YYObjectBase::Mark4GenGC(unsigned int**, int, YYObjectBase*) / YYObjectBase::Mark4GenGC(unsigned int**, int, YYObjectBase*)+0x110
 * 字段偏移 top8: 0x2×3 / 0x4×3 / 0x34×2 / 0x60×2 / 0x24×2 / 0x158×1 / 0x134×1 / 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19206c ldr r3, [pc, #0x158]
 *   @0x192070 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x192074 ldr r3, [pc, r3]
 *   @0x192078 mov r7, r0
 *   @0x19207c mov r8, r2
 *   @0x192080 ldr r0, [r0, #0x34]
 *   @0x192084 mov r9, r1
 *   @0x192088 ldr r2, [r3]
 *   @0x19208c cmp r0, r2
 *   @0x192090 pophs {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x192094 ldr r3, [pc, #0x134]
 *   @0x192098 ldr r1, [r7, #0x44]
 *   @0x19209c ldr r3, [pc, r3]
 *   @0x1920a0 str r2, [r7, #0x34]
 *   @0x1920a4 cmp r1, #0
 *   @0x1920a8 ldr r2, [r3]
 *   @0x1920ac add r2, r2, #1
 *   @0x1920b0 str r2, [r3]
 *   @0x1920b4 blt 0x1920e0 <_ZN12YYObjectBase10Mark4GenGCEPPjiPS_+0x74>
 *   @0x1920b8 cmp r1, r8
 *   @0x1920bc bge 0x1920e0 <_ZN12YYObjectBase10Mark4GenGCEPPjiPS_+0x74>
 *   @0x1920c0 ldr r3, [r7, #0x38]
 *   @0x1920c4 asr r2, r1, #5
 *   @0x1920c8 mov r12, #1
 *   @0x1920cc and r1, r1, #31
 *   @0x1920d0 ldr r3, [r9, r3, lsl #2]
 *   @0x1920d4 ldr r0, [r3, r2, lsl #2]
 *   @0x1920d8 orr r1, r0, r12, lsl r1
 *   @0x1920dc str r1, [r3, r2, lsl #2]
 *   @0x1920e0 ldr r0, [r7, #0x18]
 *   @0x1920e4 cmp r0, #0
 *   @0x1920e8 beq 0x1920fc <_ZN12YYObjectBase10Mark4GenGCEPPjiPS_+0x90>
 *   @0x1920ec mov r1, r9
 *   @0x1920f0 mov r2, r8
 *   @0x1920f4 mov r3, r7
 *   @0x1920f8 bl 0x19206c <_ZN12YYObjectBase10Mark4GenGCEPPjiPS_>
 *   @0x1920fc ldr r3, [r7, #0x60]
 *   @0x192100 cmp r3, #0
 *   @0x192104 beq 0x19217c <_ZN12YYObjectBase10Mark4GenGCEPPjiPS_+0x110>
 *   @0x192108 ldr r2, [r3, #0x4]
 *   @0x19210c cmp r2, #0
 *   @0x192110 ble 0x19217c <_ZN12YYObjectBase10Mark4GenGCEPPjiPS_+0x110>
 *   @0x192114 mov r4, #0
 *   @0x192118 mov r10, r4
 *   @0x19211c add r12, r4, r4, lsl #1
 *   @0x192120 ldr r2, [r3, #0x10]
 *   @0x192124 ldr r6, [r3]
 *   @0x192128 add r12, r2, r12, lsl #2
 *   @0x19212c b 0x19213c <_ZN12YYObjectBase10Mark4GenGCEPPjiPS_+0xd0>
 *   @0x192130 ldr r5, [lr, #0x8]
 *   @0x192134 cmp r5, #0
 *   @0x192138 bgt 0x1921c4 <_ZN12YYObjectBase10Mark4GenGCEPPjiPS_+0x158>
 *   @0x19213c add r4, r4, #1
 *   @0x192140 mov lr, r12
 *   @0x192144 cmp r6, r4
 *   @0x192148 add r12, r12, #12
 *   @0x19214c bge 0x192130 <_ZN12YYObjectBase10Mark4GenGCEPPjiPS_+0xc4>
 *   @0x192150 mov lr, #0
 *   @0x192154 mov r2, r8
 *   @0x192158 mov r3, r7
 *   @0x19215c ldr r0, [lr]
 *   @0x192160 mov r1, r9
 *   @0x192164 bl 0x1921d4 <_Z13RVALUE_GEN_GCPK6RValuePPjiP12YYObjectBase>
 *   @0x192168 ldr r3, [r7, #0x60]
 *   @0x19216c add r10, r10, #1
 *   @0x192170 ldr r2, [r3, #0x4]
 *   @0x192174 cmp r2, r10
 *   @0x192178 bgt 0x19211c <_ZN12YYObjectBase10Mark4GenGCEPPjiPS_+0xb0>
 *   @0x19217c ldr r4, [r7, #0x4]
 *   @0x192180 cmp r4, #0
 *   @0x192184 popeq {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x192188 ldr r3, [r7, #0x24]
 *   @0x19218c cmp r3, #0
 *   @0x192190 popeq {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x192194 mov r5, #0
 *   @0x192198 mov r0, r4
 *   @0x19219c mov r3, r7
 *   @0x1921a0 mov r1, r9
 *   @0x1921a4 mov r2, r8
 *   @0x1921a8 bl 0x1921d4 <_Z13RVALUE_GEN_GCPK6RValuePPjiP12YYObjectBase>
 *   @0x1921ac ldr r3, [r7, #0x24]
 *   @0x1921b0 add r5, r5, #1
 *   @0x1921b4 add r4, r4, #16
 *   @0x1921b8 cmp r3, r5
 *   @0x1921bc bhi 0x192198 <_ZN12YYObjectBase10Mark4GenGCEPPjiPS_+0x12c>
 *   @0x1921c0 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1921c4 add lr, lr, #4
 *   @0x1921c8 b 0x192154 <_ZN12YYObjectBase10Mark4GenGCEPPjiPS_+0xe8>
 *   @0x1921cc .word 0x0025bbd8
 *   @0x1921d0 eoreq r11, r5, r8, ror #23
 *
 * ══ §78/81 DGifOpen(void*, int (*)(GifFileType*, unsigned char*, int), int*)  0x2c1c50  size 360  90 条（0x2c1c50..0x2c1db8）
 * @func 0x2c1c50 0x2c1db8  size 360  90 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6544×2 / 0xb655c×2 / 0xb65b0 / 0xb65e0 / DGifGetScreenDesc(GifFileType*) / 0xb68c8
 * 字段偏移 top8: 0x34×1 / 0x14×1 / 0x48×1 / 0x4×1 / 0x38×1 / 0x3c×1 / 0x44×1 / 0xd4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c1c50 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x2c1c54 mov r9, r0
 *   @0x2c1c58 sub sp, sp, #12
 *   @0x2c1c5c mov r0, #76
 *   @0x2c1c60 mov r7, r1
 *   @0x2c1c64 mov r8, r2
 *   @0x2c1c68 bl 0xb6544 <malloc@plt>
 *   @0x2c1c6c subs r4, r0, #0
 *   @0x2c1c70 beq 0x2c1d34 <_Z8DGifOpenPvPFiP11GifFileTypePhiEPi+0xe4>
 *   @0x2c1c74 mov r1, #0
 *   @0x2c1c78 mov r2, #76
 *   @0x2c1c7c bl 0xb65b0 <memset@plt>
 *   @0x2c1c80 mov r6, #0
 *   @0x2c1c84 movw r0, #0x614c
 *   @0x2c1c88 str r6, [r4, #0x34]
 *   @0x2c1c8c str r6, [r4, #0x14]
 *   @0x2c1c90 bl 0xb6544 <malloc@plt>
 *   @0x2c1c94 subs r5, r0, #0
 *   @0x2c1c98 beq 0x2c1da4 <_Z8DGifOpenPvPFiP11GifFileTypePhiEPi+0x154>
 *   @0x2c1c9c cmp r7, #0
 *   @0x2c1ca0 mov r3, #8
 *   @0x2c1ca4 str r5, [r4, #0x48]
 *   @0x2c1ca8 str r6, [r5, #0x4]
 *   @0x2c1cac str r6, [r5, #0x38]
 *   @0x2c1cb0 str r7, [r5, #0x3c]
 *   @0x2c1cb4 str r9, [r4, #0x44]
 *   @0x2c1cb8 str r3, [r5]
 *   @0x2c1cbc beq 0x2c1d8c <_Z8DGifOpenPvPFiP11GifFileTypePhiEPi+0x13c>
 *   @0x2c1cc0 mov r0, r4
 *   @0x2c1cc4 mov r2, #6
 *   @0x2c1cc8 mov r1, sp
 *   @0x2c1ccc blx r7
 *   @0x2c1cd0 cmp r0, #6
 *   @0x2c1cd4 bne 0x2c1d7c <_Z8DGifOpenPvPFiP11GifFileTypePhiEPi+0x12c>
 *   @0x2c1cd8 ldr r0, [pc, #0xd4]
 *   @0x2c1cdc mov r1, sp
 *   @0x2c1ce0 mov r2, #3
 *   @0x2c1ce4 mov r3, #0
 *   @0x2c1ce8 add r0, pc, r0
 *   @0x2c1cec strb r3, [sp, #0x6]
 *   @0x2c1cf0 bl 0xb65e0 <strncmp@plt>
 *   @0x2c1cf4 subs r6, r0, #0
 *   @0x2c1cf8 bne 0x2c1d54 <_Z8DGifOpenPvPFiP11GifFileTypePhiEPi+0x104>
 *   @0x2c1cfc mov r0, r4
 *   @0x2c1d00 bl 0x2c1a30 <_Z17DGifGetScreenDescP11GifFileType>
 *   @0x2c1d04 subs r7, r0, #0
 *   @0x2c1d08 beq 0x2c1d60 <_Z8DGifOpenPvPFiP11GifFileTypePhiEPi+0x110>
 *   @0x2c1d0c ldrb r2, [sp, #0x3]
 *   @0x2c1d10 movw r3, #0x6148
 *   @0x2c1d14 mov r0, r4
 *   @0x2c1d18 str r6, [r4, #0x40]
 *   @0x2c1d1c subs r1, r2, #57
 *   @0x2c1d20 rsbs r2, r1, #0
 *   @0x2c1d24 adcs r2, r2, r1
 *   @0x2c1d28 strb r2, [r5, r3]
 *   @0x2c1d2c add sp, sp, #12
 *   @0x2c1d30 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x2c1d34 cmp r8, #0
 *   @0x2c1d38 moveq r0, r8
 *   @0x2c1d3c beq 0x2c1d2c <_Z8DGifOpenPvPFiP11GifFileTypePhiEPi+0xdc>
 *   @0x2c1d40 mov r0, r4
 *   @0x2c1d44 mov r3, #109
 *   @0x2c1d48 str r3, [r8]
 *   @0x2c1d4c add sp, sp, #12
 *   @0x2c1d50 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x2c1d54 cmp r8, #0
 *   @0x2c1d58 movne r3, #103
 *   @0x2c1d5c strne r3, [r8]
 *   @0x2c1d60 mov r0, r5
 *   @0x2c1d64 bl 0xb655c <free@plt>
 *   @0x2c1d68 mov r0, r4
 *   @0x2c1d6c bl 0xb655c <free@plt>
 *   @0x2c1d70 mov r0, #0
 *   @0x2c1d74 add sp, sp, #12
 *   @0x2c1d78 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x2c1d7c cmp r8, #0
 *   @0x2c1d80 movne r3, #102
 *   @0x2c1d84 strne r3, [r8]
 *   @0x2c1d88 b 0x2c1d60 <_Z8DGifOpenPvPFiP11GifFileTypePhiEPi+0x110>
 *   @0x2c1d8c mov r3, r7
 *   @0x2c1d90 mov r1, #1
 *   @0x2c1d94 mov r2, #6
 *   @0x2c1d98 mov r0, sp
 *   @0x2c1d9c bl 0xb68c8 <fread@plt>
 *   @0x2c1da0 b 0x2c1cd0 <_Z8DGifOpenPvPFiP11GifFileTypePhiEPi+0x80>
 *   @0x2c1da4 cmp r8, r6
 *   @0x2c1da8 movne r3, #109
 *   @0x2c1dac strne r3, [r8]
 *   @0x2c1db0 b 0x2c1d68 <_Z8DGifOpenPvPFiP11GifFileTypePhiEPi+0x118>
 *   @0x2c1db4 andeq r9, r9, r0, asr r10
 *
 * ══ §79/81 __gxx_personality_v0  0x317f80  size 360  90 条（0x317f80..0x3180e8）
 * @func 0x317f80 0x3180e8  size 360  90 条
 * 部分覆盖: 本节 90/164 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _Unwind_VRS_Set / anon_317e5c / anonT_317ba8 / 0x41377c / 0x4e70c0 / 0x5670ac / anon_317e5c+0x6c / 0x5d76b4
 * 字段偏移 top8: 0x-14×2 / 0x20×2 / 0x-10×1 / 0x1c×1 / 0x14×1 / 0x24×1 / 0x28×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x317f80 and r0, r0, #0x3
 *   @0x317f84 cmp r0, #0x1
 *   @0x317f88 .word 0x460c43f0
 *   @0x317f8c sub sp, #0x34
 *   @0x317f90 ldrd r8, r9, [r1]
 *   @0x317f94 beq 0x318044 <__gxx_personality_v0+0xc4>
 *   @0x317f98 add r7, sp, #0xc
 *   @0x317f9c movs r1, #0x0
 *   @0x317fa0 movs r2, #0xc
 *   @0x317fa4 mov r3, r1
 *   @0x317fa8 blx 0x319c68 <_Unwind_VRS_Set>
 *   @0x317fac cmp r6, #0x0
 *   @0x317fb0 adr r3, #300 <__gxx_personality_v0+0x7f>
 *   @0x317fb4 b 0xfe3a0bbc <b2_toiTime+0xfffffffffdc47718>
 *   @0x317fb8 b 0xfe3d87e0 <b2_toiTime+0xfffffffffdc7f33c>
 *   @0x317fbc b 0x1798be8 <b2_toiTime+0x103f744>
 *   @0x317fc0 svclt #0x140103
 *   @0x317fc4 movne r7, #0x0
 *   @0x317fc8 lsls r1, r5, #0x1f
 *   @0x317fcc lsls r2, r5, #0x1e
 *   @0x317fd0 lsls r3, r5, #0x1d
 *   @0x317fd4 cmp r7, #0x0
 *   @0x317fd8 ldmdb r4, {r0, r1, r2}
 *   @0x317fdc add.w r8, sp, #0x10
 *   @0x317fe0 ldr r3, [r4, #-20]
 *   @0x317fe4 ldr r5, [r4, #-16]
 *   @0x317fe8 str r0, [sp, #0x1c]
 *   @0x317fec str r1, [sp, #0x20]
 *   @0x317ff0 asrs r7, r3, #0x1f
 *   @0x317ff4 str r7, [sp, #0x14]
 *   @0x317ff8 str r2, [sp, #0x24]
 *   @0x317ffc qsub16mi pc, r0, r11
 *   @0x318000 mov r1, r6
 *   @0x318004 bl 0x317e5c <ft_lzwstate_io+0xea8>
 *   @0x318008 mov r0, r4
 *   @0x31800c mov r2, r8
 *   @0x318010 andhs pc, r7, pc, ror pc
 *   @0x318014 b 0x31801c <__gxx_personality_v0+0x9c>
 *   @0x318018 beq 0x318036 <__gxx_personality_v0+0xb6>
 *   @0x31801c add sp, #0x34
 *   @0x318020 qsub8mi r8, r9, r0
 *   @0x318024 mov r2, r7
 *   @0x318028 add r0, sp, #0x10
 *   @0x31802c bl 0x317ba8 <ft_lzwstate_io+0xbf4>
 *   @0x318030 ldr r5, [sp, #0x28]
 *   @0x318034 beq 0x318062 <__gxx_personality_v0+0xe2>
 *   @0x318038 mov r1, r6
 *   @0x31803c .word 0xe7edff3d
 *   @0x318040 movs r0, #0x3
 *   @0x318044 movs r1, #0x0
 *   @0x318048 movs r2, #0xd
 *   @0x31804c mov r3, r1
 *   @0x318050 str r7, [sp]
 *   @0x318054 blls 0x41377c <g_RomDisk+0x1bf5c>
 *   @0x318058 cmp r5, r3
 *   @0x31805c moveq r5, #0x6
 *   @0x318060 b 0x317f9c <__gxx_personality_v0+0x1c>
 *   @0x318064 cmp r7, #0x0
 *   @0x318068 ldr r3, [sp, #0x10]
 *   @0x31806c mov r1, r6
 *   @0x318070 str r3, [r4, #-20]
 *   @0x318074 ldr r3, [sp, #0x18]
 *   @0x318078 blls 0x4e70c0 <SrcVerts+0x44104>
 *   @0x31807c str r3, [r4, #-12]
 *   @0x318080 ldr r3, [sp, #0x20]
 *   @0x318084 blls 0x5670ac <g_SWFlineaavertbuff+0x13fe4>
 *   @0x318088 str r3, [r4, #-4]
 *   @0x31808c bl 0x317ec8 <ft_lzwstate_io+0xf14>
 *   @0x318090 mov r0, r5
 *   @0x318094 mov r3, r4
 *   @0x318098 mov r2, r7
 *   @0x31809c str r6, [sp]
 *   @0x3180a0 blls 0x5d76b4 <g_SWFaavertbuff+0x45ec>
 *   @0x3180a4 cmp r3, #0x6
 *   @0x3180a8 mov r1, r6
 *   @0x3180ac mov r0, r4
 *   @0x3180b0 .word 0x4620fed5
 *   @0x3180b4 bl 0x317f0c <ft_lzwstate_io+0xf58>
 *   @0x3180b8 movs r0, #0x7
 *   @0x3180bc add.w r8, sp, #0x10
 *   @0x3180c0 mov r3, r4
 *   @0x3180c4 mov r2, r7
 *   @0x3180c8 str r6, [sp]
 *   @0x3180cc blls 0x5d7688 <g_SWFaavertbuff+0x45c0>
 *   @0x3180d0 cmp r3, #0x6
 *   @0x3180d4 mov r0, r4
 *   @0x3180d8 svclt #0xfd2f
 *   @0x3180dc nop.w
 *   @0x3180e0 cmp r3, #0x0
 *   @0x3180e4 strb r3, [r0, r5]
 *
 * ══ §80/81 IBuffer::MD5(RValue*, int, int)  0xcbc50  size 356  89 条（0xcbc50..0xcbdb4）
 * @func 0xcbc50 0xcbdc8  size 376  94 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MD5Init(MD5_CTX*) / MD5Update(MD5_CTX*, unsigned char*, unsigned int) / MD5Final(MD5_CTX*) / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb6550 / YYCreateString(RValue*, char const*) / MemoryManager::Free(void const*) / IBuffer::MD5(RValue*, int, int)+0x144
 * 字段偏移 top8: 0x6c×2 / 0x10×2 / 0x148×1 / 0x18×1 / 0xc×1 / 0xa4×1 / 0xa0×1 / 0x1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcbc50 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xcbc54 mov r5, r3
 *   @0xcbc58 ldr r7, [pc, #0x148]
 *   @0xcbc5c sub sp, sp, #112
 *   @0xcbc60 subs r8, r1, #0
 *   @0xcbc64 mov r6, r0
 *   @0xcbc68 ldr r7, [pc, r7]
 *   @0xcbc6c mov r4, r2
 *   @0xcbc70 ldr r3, [r7]
 *   @0xcbc74 str r3, [sp, #0x6c]
 *   @0xcbc78 beq 0xcbd64 <_ZN7IBuffer3MD5EP6RValueii+0x114>
 *   @0xcbc7c ldr r3, [r0, #0x10]
 *   @0xcbc80 cmp r3, #0
 *   @0xcbc84 beq 0xcbd64 <_ZN7IBuffer3MD5EP6RValueii+0x114>
 *   @0xcbc88 cmp r5, #0
 *   @0xcbc8c ldr r2, [r0, #0x18]
 *   @0xcbc90 movlt r5, r3
 *   @0xcbc94 cmp r2, #2
 *   @0xcbc98 beq 0xcbd7c <_ZN7IBuffer3MD5EP6RValueii+0x12c>
 *   @0xcbc9c bic r4, r4, r4, asr #31
 *   @0xcbca0 cmp r4, r3
 *   @0xcbca4 subge r4, r3, #1
 *   @0xcbca8 add r2, r4, r5
 *   @0xcbcac cmp r3, r2
 *   @0xcbcb0 rsblt r5, r4, r3
 *   @0xcbcb4 add r9, sp, #4
 *   @0xcbcb8 mov r0, r9
 *   @0xcbcbc bl 0x2140d8 <_Z7MD5InitP7MD5_CTX>
 *   @0xcbcc0 cmp r5, #0
 *   @0xcbcc4 bgt 0xcbcd0 <_ZN7IBuffer3MD5EP6RValueii+0x80>
 *   @0xcbcc8 b 0xcbcfc <_ZN7IBuffer3MD5EP6RValueii+0xac>
 *   @0xcbccc mov r4, #0
 *   @0xcbcd0 ldr r2, [r6, #0x10]
 *   @0xcbcd4 mov r0, r9
 *   @0xcbcd8 ldr r1, [r6, #0xc]
 *   @0xcbcdc rsb r2, r4, r2
 *   @0xcbce0 cmp r2, r5
 *   @0xcbce4 movge r2, r5
 *   @0xcbce8 add r1, r1, r4
 *   @0xcbcec rsb r5, r2, r5
 *   @0xcbcf0 bl 0x214118 <_Z9MD5UpdateP7MD5_CTXPhj>
 *   @0xcbcf4 cmp r5, #0
 *   @0xcbcf8 bgt 0xcbccc <_ZN7IBuffer3MD5EP6RValueii+0x7c>
 *   @0xcbcfc mov r0, r9
 *   @0xcbd00 ldr r6, [pc, #0xa4]
 *   @0xcbd04 bl 0x2141d0 <_Z8MD5FinalP7MD5_CTX>
 *   @0xcbd08 ldr r1, [pc, #0xa0]
 *   @0xcbd0c mov r0, #33
 *   @0xcbd10 movw r2, #0x4f5
 *   @0xcbd14 add r1, pc, r1
 *   @0xcbd18 mov r3, #1
 *   @0xcbd1c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xcbd20 add r4, sp, #91
 *   @0xcbd24 add r9, sp, #107
 *   @0xcbd28 add r6, pc, r6
 *   @0xcbd2c mov r10, r0
 *   @0xcbd30 mov r5, r0
 *   @0xcbd34 ldrb r2, [r4, #0x1]!
 *   @0xcbd38 mov r0, r5
 *   @0xcbd3c mov r1, r6
 *   @0xcbd40 add r5, r5, #2
 *   @0xcbd44 bl 0xb6550 <sprintf@plt>
 *   @0xcbd48 cmp r4, r9
 *   @0xcbd4c bne 0xcbd34 <_ZN7IBuffer3MD5EP6RValueii+0xe4>
 *   @0xcbd50 mov r0, r8
 *   @0xcbd54 mov r1, r10
 *   @0xcbd58 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0xcbd5c mov r0, r10
 *   @0xcbd60 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xcbd64 ldr r2, [sp, #0x6c]
 *   @0xcbd68 ldr r3, [r7]
 *   @0xcbd6c cmp r2, r3
 *   @0xcbd70 bne 0xcbda4 <_ZN7IBuffer3MD5EP6RValueii+0x154>
 *   @0xcbd74 add sp, sp, #112
 *   @0xcbd78 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xcbd7c cmp r4, #0
 *   @0xcbd80 bge 0xcbd8c <_ZN7IBuffer3MD5EP6RValueii+0x13c>
 *   @0xcbd84 adds r4, r4, r3
 *   @0xcbd88 bmi 0xcbd84 <_ZN7IBuffer3MD5EP6RValueii+0x134>
 *   @0xcbd8c cmp r3, r4
 *   @0xcbd90 bgt 0xcbcb4 <_ZN7IBuffer3MD5EP6RValueii+0x64>
 *   @0xcbd94 rsb r4, r3, r4
 *   @0xcbd98 cmp r3, r4
 *   @0xcbd9c ble 0xcbd94 <_ZN7IBuffer3MD5EP6RValueii+0x144>
 *   @0xcbda0 b 0xcbcb4 <_ZN7IBuffer3MD5EP6RValueii+0x64>
 *   @0xcbda4 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0xcbda8 eorseq r1, r2, r8, ror #25
 *   @0xcbdac eoreq r6, r6, r12, ror r4
 *   @0xcbdb0 eoreq r6, r6, r12, asr r4
 *
 * ══ §81/81 CSkeletonSprite::GetSlotData(CDS_List*)  0xc1350  size 304  74 条（0xc1350..0xc1480）
 * @func 0xc1350 0xc1480  size 304  74 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSkeletonSprite::GetSlotData(CDS_List*)+0x10c×2 / CreateDsMap(int, ...) / CDS_List::Add(RValue*) / FREE_RValue__Pre(RValue*)
 * 字段偏移 top8: 0x4×6 / 0x18×3 / 0x34×2 / 0xf0×1 / 0xec×1 / 0xe8×1 / 0xe4×1 / 0x1c×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc1350 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xc1354 vpush {d8}
 *   @0xc1358 subs r7, r1, #0
 *   @0xc135c sub sp, sp, #60
 *   @0xc1360 mov r6, r0
 *   @0xc1364 beq 0xc145c <_ZN15CSkeletonSprite11GetSlotDataEP8CDS_List+0x10c>
 *   @0xc1368 ldr r3, [r0, #0x4]
 *   @0xc136c ldr r2, [r3, #0x18]
 *   @0xc1370 cmp r2, #0
 *   @0xc1374 ble 0xc145c <_ZN15CSkeletonSprite11GetSlotDataEP8CDS_List+0x10c>
 *   @0xc1378 ldr r11, [pc, #0xf0]
 *   @0xc137c add r5, sp, #40
 *   @0xc1380 ldr r10, [pc, #0xec]
 *   @0xc1384 mov r4, #0
 *   @0xc1388 ldr r9, [pc, #0xe8]
 *   @0xc138c add r11, pc, r11
 *   @0xc1390 ldr r8, [pc, #0xe4]
 *   @0xc1394 add r10, pc, r10
 *   @0xc1398 add r9, pc, r9
 *   @0xc139c vldr d8, [pc, #196]
 *   @0xc13a0 add r8, pc, r8
 *   @0xc13a4 b 0xc13b8 <_ZN15CSkeletonSprite11GetSlotDataEP8CDS_List+0x68>
 *   @0xc13a8 ldr r3, [r6, #0x4]
 *   @0xc13ac ldr r2, [r3, #0x18]
 *   @0xc13b0 cmp r2, r4
 *   @0xc13b4 ble 0xc145c <_ZN15CSkeletonSprite11GetSlotDataEP8CDS_List+0x10c>
 *   @0xc13b8 ldr r3, [r3, #0x1c]
 *   @0xc13bc mov r1, r10
 *   @0xc13c0 mov r0, #3
 *   @0xc13c4 ldr r2, [r3, r4, lsl #2]
 *   @0xc13c8 add r4, r4, #1
 *   @0xc13cc ldr lr, [r2, #0x8]
 *   @0xc13d0 ldr r3, [r2, #0xc]
 *   @0xc13d4 ldr r12, [r2, #0x4]
 *   @0xc13d8 ldr r2, [lr, #0x4]
 *   @0xc13dc cmp r3, #0
 *   @0xc13e0 str r9, [sp, #0x4]
 *   @0xc13e4 vstr d8, [sp, #8]
 *   @0xc13e8 moveq r3, r11
 *   @0xc13ec str r12, [sp]
 *   @0xc13f0 str r2, [sp, #0x10]
 *   @0xc13f4 vstr d8, [sp, #24]
 *   @0xc13f8 str r3, [sp, #0x20]
 *   @0xc13fc mov r2, #0
 *   @0xc1400 mov r3, #0
 *   @0xc1404 str r8, [sp, #0x14]
 *   @0xc1408 bl 0x20bdc0 <_Z11CreateDsMapiz>
 *   @0xc140c mov r1, r5
 *   @0xc1410 mov r3, #0
 *   @0xc1414 str r3, [sp, #0x34]
 *   @0xc1418 vmov s13, r0
 *   @0xc141c mov r0, r7
 *   @0xc1420 vcvt.f64.s32 d7, s13
 *   @0xc1424 vstr d7, [sp, #40]
 *   @0xc1428 bl 0x205d18 <_ZN8CDS_List3AddEP6RValue>
 *   @0xc142c ldr r3, [sp, #0x34]
 *   @0xc1430 sub r3, r3, #1
 *   @0xc1434 bic r3, r3, #-16777216
 *   @0xc1438 bic r3, r3, #3
 *   @0xc143c cmp r3, #0
 *   @0xc1440 bne 0xc13a8 <_ZN15CSkeletonSprite11GetSlotDataEP8CDS_List+0x58>
 *   @0xc1444 mov r0, r5
 *   @0xc1448 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xc144c ldr r3, [r6, #0x4]
 *   @0xc1450 ldr r2, [r3, #0x18]
 *   @0xc1454 cmp r2, r4
 *   @0xc1458 bgt 0xc13b8 <_ZN15CSkeletonSprite11GetSlotDataEP8CDS_List+0x68>
 *   @0xc145c add sp, sp, #60
 *   @0xc1460 vpop {d8}
 *   @0xc1464 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xc1470 eoreq pc, r6, r0, lsr #11
 *   @0xc1474 eoreq pc, r6, r4, ror r4
 *   @0xc1478 mlaeq r6, r12, r5, pc
 *   @0xc147c mlaeq r6, r12, r5, pc
 */
