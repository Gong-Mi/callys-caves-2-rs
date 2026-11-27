/* cally 逆向卡：All_61 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 251 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/251 F_ObjectSetMask(RValue&, CInstance*, CInstance*, int, RValue*)  0x12b180  size 124  31 条（0x12b180..0x12b1fc）
 * @func 0x12b180 0x12b1fc  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0x10×2 / 0x4×2 / 0x5c×1 / 0x3×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12b180 push {r3, r4, r5, lr}
 *   @0x12b184 mov r1, #0
 *   @0x12b188 ldr r4, [sp, #0x10]
 *   @0x12b18c mov r0, r4
 *   @0x12b190 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b194 ldr r3, [pc, #0x5c]
 *   @0x12b198 ldr r3, [pc, r3]
 *   @0x12b19c ldr r3, [r3]
 *   @0x12b1a0 ldr r2, [r3, #0x4]
 *   @0x12b1a4 ldr r3, [r3]
 *   @0x12b1a8 and r2, r0, r2
 *   @0x12b1ac ldr r3, [r3, r2, lsl #3]
 *   @0x12b1b0 cmp r3, #0
 *   @0x12b1b4 bne 0x12b1c8 <_Z15F_ObjectSetMaskR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x12b1b8 pop {r3, r4, r5, pc}
 *   @0x12b1bc ldr r3, [r3, #0x4]
 *   @0x12b1c0 cmp r3, #0
 *   @0x12b1c4 beq 0x12b1f4 <_Z15F_ObjectSetMaskR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x12b1c8 ldr r2, [r3, #0x8]
 *   @0x12b1cc cmp r0, r2
 *   @0x12b1d0 bne 0x12b1bc <_Z15F_ObjectSetMaskR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x12b1d4 ldr r5, [r3, #0xc]
 *   @0x12b1d8 cmp r5, #0
 *   @0x12b1dc popeq {r3, r4, r5, pc}
 *   @0x12b1e0 mov r0, r4
 *   @0x12b1e4 mov r1, #1
 *   @0x12b1e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12b1ec str r0, [r5, #0x10]
 *   @0x12b1f0 pop {r3, r4, r5, pc}
 *   @0x12b1f4 pop {r3, r4, r5, pc}
 *   @0x12b1f8 eoreq r2, r12, r4, lsr #21
 *
 * ══ §2/251 F_SoundAdd(RValue&, CInstance*, CInstance*, int, RValue*)  0x12f72c  size 124  31 条（0x12f72c..0x12f7a8）
 * @func 0x12f72c 0x12f7a8  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / YYGetInt32(RValue const*, int) / YYGetBool(RValue const*, int) / Sound_Add(char const*, int, bool)
 * 字段偏移 top8: 0x68×1 / 0x18×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12f72c push {r3, r4, r5, r6, r7, lr}
 *   @0x12f730 mov r5, r0
 *   @0x12f734 ldr r3, [pc, #0x68]
 *   @0x12f738 ldr r4, [sp, #0x18]
 *   @0x12f73c ldr r3, [pc, r3]
 *   @0x12f740 ldrb r1, [r3]
 *   @0x12f744 cmp r1, #0
 *   @0x12f748 popne {r3, r4, r5, r6, r7, pc}
 *   @0x12f74c str r1, [r0, #0xc]
 *   @0x12f750 mov r0, r4
 *   @0x12f754 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x12f758 mov r1, #1
 *   @0x12f75c mov r7, r0
 *   @0x12f760 mov r0, r4
 *   @0x12f764 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f768 mov r1, #2
 *   @0x12f76c mov r6, r0
 *   @0x12f770 mov r0, r4
 *   @0x12f774 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12f778 mov r1, r6
 *   @0x12f77c mov r2, r0
 *   @0x12f780 mov r0, r7
 *   @0x12f784 bl 0x21fd14 <_Z9Sound_AddPKcib>
 *   @0x12f788 vmov s15, r0
 *   @0x12f78c vcvt.f64.s32 d7, s15
 *   @0x12f790 vmov r0, r1, d7
 *   @0x12f794 vmov r2, s14
 *   @0x12f798 mov r3, r1
 *   @0x12f79c stm r5, {r2, r3}
 *   @0x12f7a0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x12f7a4 .word 0x002bf5f4
 *
 * ══ §3/251 F_Audio_CreatePlayQueue(RValue&, CInstance*, CInstance*, int, RValue*)  0x135b9c  size 124  31 条（0x135b9c..0x135c18）
 * @func 0x135b9c 0x135c18  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / Audio_CreatePlayQueue(int, int, int)
 * 字段偏移 top8: 0x68×1 / 0x18×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x135b9c push {r3, r4, r5, r6, r7, lr}
 *   @0x135ba0 mov r5, r0
 *   @0x135ba4 ldr r3, [pc, #0x68]
 *   @0x135ba8 ldr r4, [sp, #0x18]
 *   @0x135bac ldr r3, [pc, r3]
 *   @0x135bb0 ldrb r1, [r3]
 *   @0x135bb4 cmp r1, #0
 *   @0x135bb8 popne {r3, r4, r5, r6, r7, pc}
 *   @0x135bbc str r1, [r0, #0xc]
 *   @0x135bc0 mov r0, r4
 *   @0x135bc4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135bc8 mov r1, #1
 *   @0x135bcc mov r7, r0
 *   @0x135bd0 mov r0, r4
 *   @0x135bd4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135bd8 mov r1, #2
 *   @0x135bdc mov r6, r0
 *   @0x135be0 mov r0, r4
 *   @0x135be4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135be8 mov r1, r6
 *   @0x135bec mov r2, r0
 *   @0x135bf0 mov r0, r7
 *   @0x135bf4 bl 0x21cb8c <_Z21Audio_CreatePlayQueueiii>
 *   @0x135bf8 vmov s15, r0
 *   @0x135bfc vcvt.f64.s32 d7, s15
 *   @0x135c00 vmov r0, r1, d7
 *   @0x135c04 vmov r2, s14
 *   @0x135c08 mov r3, r1
 *   @0x135c0c stm r5, {r2, r3}
 *   @0x135c10 pop {r3, r4, r5, r6, r7, pc}
 *   @0x135c14 eoreq r9, r11, r0, lsr #9
 *
 * ══ §4/251 F_FileTextReadReal(RValue&, CInstance*, CInstance*, int, RValue*)  0x137ff8  size 124  31 条（0x137ff8..0x138074）
 * @func 0x137ff8 0x138074  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×2 / 0x48×1 / 0x2×1 / 0x38×1 / 0x28×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x137ff8 push {r4, lr}
 *   @0x137ffc mov r1, #0
 *   @0x138000 mov r4, r0
 *   @0x138004 ldr r0, [sp, #0x8]
 *   @0x138008 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13800c sub r3, r0, #1
 *   @0x138010 cmp r3, #30
 *   @0x138014 bhi 0x13802c <_Z18F_FileTextReadRealR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x138018 ldr r3, [pc, #0x48]
 *   @0x13801c ldr r3, [pc, r3]
 *   @0x138020 ldr r3, [r3, r0, lsl #2]
 *   @0x138024 cmp r3, #1
 *   @0x138028 beq 0x138040 <_Z18F_FileTextReadRealR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x13802c ldr r0, [pc, #0x38]
 *   @0x138030 mov r1, #0
 *   @0x138034 pop {r4, lr}
 *   @0x138038 add r0, pc, r0
 *   @0x13803c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x138040 ldr r3, [pc, #0x28]
 *   @0x138044 add r0, r0, r0, lsl #1
 *   @0x138048 mov r2, #0
 *   @0x13804c mov r1, r4
 *   @0x138050 ldr r3, [pc, r3]
 *   @0x138054 str r2, [r4, #0xc]
 *   @0x138058 add r3, r3, r0, lsl #2
 *   @0x13805c pop {r4, lr}
 *   @0x138060 ldr r0, [r3, #0x8]
 *   @0x138064 b 0x18df88 <_ZN8LoadSave9freadrealEP7_YYFILEPd>
 *   @0x138068 eoreq r7, r11, r4, asr r2
 *   @0x13806c .word 0x00207ff8
 *   @0x138070 eoreq r7, r11, r4, lsr #4
 *
 * ══ §5/251 F_ActionMessage(RValue&, CInstance*, CInstance*, int, RValue*)  0x13eb4c  size 124  31 条（0x13eb4c..0x13ebc8）
 * @func 0x13eb4c 0x13ebc8  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool) / STRING_RValue(char**, char**, int*, RValue const*) / String_Replace_Hash(char*) / ShowMessage(char const*) / IO_Clear() / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x8×4 / 0x70×1 / 0x4×1 / 0x18×1 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13eb4c ldr r1, [pc, #0x70]
 *   @0x13eb50 mov r12, #16
 *   @0x13eb54 push {r4, lr}
 *   @0x13eb58 sub sp, sp, #16
 *   @0x13eb5c mov r0, r12
 *   @0x13eb60 add r1, pc, r1
 *   @0x13eb64 movw r2, #0x39e
 *   @0x13eb68 mov r3, #1
 *   @0x13eb6c str r12, [sp, #0x4]
 *   @0x13eb70 ldr r4, [sp, #0x18]
 *   @0x13eb74 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x13eb78 mov r1, #0
 *   @0x13eb7c mov r3, r4
 *   @0x13eb80 mov r2, r0
 *   @0x13eb84 str r0, [sp, #0x8]
 *   @0x13eb88 add r0, sp, #16
 *   @0x13eb8c str r2, [r0, #-0x4]!
 *   @0x13eb90 strb r1, [r2]
 *   @0x13eb94 add r1, sp, #8
 *   @0x13eb98 add r2, sp, #4
 *   @0x13eb9c bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue>
 *   @0x13eba0 ldr r0, [sp, #0x8]
 *   @0x13eba4 bl 0x212da8 <_Z19String_Replace_HashPc>
 *   @0x13eba8 ldr r0, [sp, #0x8]
 *   @0x13ebac bl 0xc4b0c <_Z11ShowMessagePKc>
 *   @0x13ebb0 bl 0x18c2c8 <_Z8IO_Clearv>
 *   @0x13ebb4 ldr r0, [sp, #0x8]
 *   @0x13ebb8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x13ebbc add sp, sp, #16
 *   @0x13ebc0 pop {r4, pc}
 *   @0x13ebc4 eoreq r1, r0, r12, lsl #27
 *
 * ══ §6/251 F_GPUSetTexMipFilter(RValue&, CInstance*, CInstance*, int, RValue*)  0x147744  size 124  31 条（0x147744..0x1477c0）
 * @func 0x147744 0x1477d4  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / RenderStateManager::SetSamplerState(int, eSamplerState, unsigned int)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x10×1 / 0x44×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x147744 cmp r3, #1
 *   @0x147748 mov r3, #0
 *   @0x14774c push {r4, r5, r6, lr}
 *   @0x147750 mov r4, r3
 *   @0x147754 movt r3, #0xbff0
 *   @0x147758 str r4, [r0, #0xc]
 *   @0x14775c str r3, [r0, #0x4]
 *   @0x147760 str r4, [r0]
 *   @0x147764 ldr r0, [sp, #0x10]
 *   @0x147768 beq 0x147780 <_Z20F_GPUSetTexMipFilterR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x14776c ldr r0, [pc, #0x44]
 *   @0x147770 mov r1, r4
 *   @0x147774 pop {r4, r5, r6, lr}
 *   @0x147778 add r0, pc, r0
 *   @0x14777c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x147780 mov r1, r4
 *   @0x147784 ldr r5, [pc, #0x30]
 *   @0x147788 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14778c ldr r5, [pc, r5]
 *   @0x147790 mov r6, r0
 *   @0x147794 mov r1, r4
 *   @0x147798 mov r0, r5
 *   @0x14779c mov r2, #4
 *   @0x1477a0 add r4, r4, #1
 *   @0x1477a4 mov r3, r6
 *   @0x1477a8 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x1477ac cmp r4, #8
 *   @0x1477b0 bne 0x147794 <_Z20F_GPUSetTexMipFilterR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x1477b4 pop {r4, r5, r6, pc}
 *   @0x1477b8 andseq r10, pc, r8, ror #7
 *   @0x1477bc eoreq r6, r10, r12, ror #10
 *
 * ══ §7/251 F_GPUSetTexMipBias(RValue&, CInstance*, CInstance*, int, RValue*)  0x147838  size 124  31 条（0x147838..0x1478b4）
 * @func 0x147838 0x1478c8  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int) / RenderStateManager::SetSamplerState(int, eSamplerState, unsigned int)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x10×1 / 0x44×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x147838 cmp r3, #1
 *   @0x14783c mov r3, #0
 *   @0x147840 push {r4, r5, r6, lr}
 *   @0x147844 mov r4, r3
 *   @0x147848 movt r3, #0xbff0
 *   @0x14784c str r4, [r0, #0xc]
 *   @0x147850 str r3, [r0, #0x4]
 *   @0x147854 str r4, [r0]
 *   @0x147858 ldr r0, [sp, #0x10]
 *   @0x14785c beq 0x147874 <_Z18F_GPUSetTexMipBiasR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x147860 ldr r0, [pc, #0x44]
 *   @0x147864 mov r1, r4
 *   @0x147868 pop {r4, r5, r6, lr}
 *   @0x14786c add r0, pc, r0
 *   @0x147870 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x147874 mov r1, r4
 *   @0x147878 ldr r5, [pc, #0x30]
 *   @0x14787c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x147880 ldr r5, [pc, r5]
 *   @0x147884 mov r6, r0
 *   @0x147888 mov r1, r4
 *   @0x14788c mov r0, r5
 *   @0x147890 mov r2, #7
 *   @0x147894 add r4, r4, #1
 *   @0x147898 mov r3, r6
 *   @0x14789c bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x1478a0 cmp r4, #8
 *   @0x1478a4 bne 0x147888 <_Z18F_GPUSetTexMipBiasR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x1478a8 pop {r4, r5, r6, pc}
 *   @0x1478ac andseq r10, pc, r12, lsl #7
 *   @0x1478b0 eoreq r6, r10, r8, ror r4
 *
 * ══ §8/251 F_GPUSetTexMinMip(RValue&, CInstance*, CInstance*, int, RValue*)  0x14792c  size 124  31 条（0x14792c..0x1479a8）
 * @func 0x14792c 0x1479bc  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int) / RenderStateManager::SetSamplerState(int, eSamplerState, unsigned int)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x10×1 / 0x44×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14792c cmp r3, #1
 *   @0x147930 mov r3, #0
 *   @0x147934 push {r4, r5, r6, lr}
 *   @0x147938 mov r4, r3
 *   @0x14793c movt r3, #0xbff0
 *   @0x147940 str r4, [r0, #0xc]
 *   @0x147944 str r3, [r0, #0x4]
 *   @0x147948 str r4, [r0]
 *   @0x14794c ldr r0, [sp, #0x10]
 *   @0x147950 beq 0x147968 <_Z17F_GPUSetTexMinMipR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x147954 ldr r0, [pc, #0x44]
 *   @0x147958 mov r1, r4
 *   @0x14795c pop {r4, r5, r6, lr}
 *   @0x147960 add r0, pc, r0
 *   @0x147964 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x147968 mov r1, r4
 *   @0x14796c ldr r5, [pc, #0x30]
 *   @0x147970 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x147974 ldr r5, [pc, r5]
 *   @0x147978 mov r6, r0
 *   @0x14797c mov r1, r4
 *   @0x147980 mov r0, r5
 *   @0x147984 mov r2, #5
 *   @0x147988 add r4, r4, #1
 *   @0x14798c mov r3, r6
 *   @0x147990 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x147994 cmp r4, #8
 *   @0x147998 bne 0x14797c <_Z17F_GPUSetTexMinMipR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x14799c pop {r4, r5, r6, pc}
 *   @0x1479a0 andseq r10, pc, r8, lsr #6
 *   @0x1479a4 eoreq r6, r10, r4, lsl #7
 *
 * ══ §9/251 F_GPUSetTexMaxMip(RValue&, CInstance*, CInstance*, int, RValue*)  0x147a20  size 124  31 条（0x147a20..0x147a9c）
 * @func 0x147a20 0x147ab0  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int) / RenderStateManager::SetSamplerState(int, eSamplerState, unsigned int)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x10×1 / 0x44×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x147a20 cmp r3, #1
 *   @0x147a24 mov r3, #0
 *   @0x147a28 push {r4, r5, r6, lr}
 *   @0x147a2c mov r4, r3
 *   @0x147a30 movt r3, #0xbff0
 *   @0x147a34 str r4, [r0, #0xc]
 *   @0x147a38 str r3, [r0, #0x4]
 *   @0x147a3c str r4, [r0]
 *   @0x147a40 ldr r0, [sp, #0x10]
 *   @0x147a44 beq 0x147a5c <_Z17F_GPUSetTexMaxMipR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x147a48 ldr r0, [pc, #0x44]
 *   @0x147a4c mov r1, r4
 *   @0x147a50 pop {r4, r5, r6, lr}
 *   @0x147a54 add r0, pc, r0
 *   @0x147a58 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x147a5c mov r1, r4
 *   @0x147a60 ldr r5, [pc, #0x30]
 *   @0x147a64 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x147a68 ldr r5, [pc, r5]
 *   @0x147a6c mov r6, r0
 *   @0x147a70 mov r1, r4
 *   @0x147a74 mov r0, r5
 *   @0x147a78 mov r2, #6
 *   @0x147a7c add r4, r4, #1
 *   @0x147a80 mov r3, r6
 *   @0x147a84 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x147a88 cmp r4, #8
 *   @0x147a8c bne 0x147a70 <_Z17F_GPUSetTexMaxMipR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x147a90 pop {r4, r5, r6, pc}
 *   @0x147a94 andseq r10, pc, r4, asr #5
 *   @0x147a98 mlaeq r10, r0, r2, r6
 *
 * ══ §10/251 F_GPUSetTexMipEnable(RValue&, CInstance*, CInstance*, int, RValue*)  0x147c74  size 124  31 条（0x147c74..0x147cf0）
 * @func 0x147c74 0x147cf0  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / RenderStateManager::SetSamplerState(int, eSamplerState, unsigned int)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x10×1 / 0x44×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x147c74 cmp r3, #1
 *   @0x147c78 mov r3, #0
 *   @0x147c7c push {r4, r5, r6, lr}
 *   @0x147c80 mov r4, r3
 *   @0x147c84 movt r3, #0xbff0
 *   @0x147c88 str r4, [r0, #0xc]
 *   @0x147c8c str r3, [r0, #0x4]
 *   @0x147c90 str r4, [r0]
 *   @0x147c94 ldr r0, [sp, #0x10]
 *   @0x147c98 beq 0x147cb0 <_Z20F_GPUSetTexMipEnableR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x147c9c ldr r0, [pc, #0x44]
 *   @0x147ca0 mov r1, r4
 *   @0x147ca4 pop {r4, r5, r6, lr}
 *   @0x147ca8 add r0, pc, r0
 *   @0x147cac b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x147cb0 mov r1, r4
 *   @0x147cb4 ldr r5, [pc, #0x30]
 *   @0x147cb8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x147cbc ldr r5, [pc, r5]
 *   @0x147cc0 mov r6, r0
 *   @0x147cc4 mov r1, r4
 *   @0x147cc8 mov r0, r5
 *   @0x147ccc mov r2, #9
 *   @0x147cd0 add r4, r4, #1
 *   @0x147cd4 mov r3, r6
 *   @0x147cd8 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x147cdc cmp r4, #8
 *   @0x147ce0 bne 0x147cc4 <_Z20F_GPUSetTexMipEnableR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x147ce4 pop {r4, r5, r6, pc}
 *   @0x147ce8 ldrsbeq r10, [pc], -r0
 *   @0x147cec eoreq r6, r10, r12, lsr r0
 *
 * ══ §11/251 F_GPUGetTexFilterExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x14855c  size 124  31 条（0x14855c..0x1485d8）
 * @func 0x14855c 0x1485d8  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / RenderStateManager::GetSamplerState(int, eSamplerState)
 * 字段偏移 top8: 0x4×2 / 0x10×1 / 0xc×1 / 0x44×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14855c cmp r3, #1
 *   @0x148560 push {r3, r4, r5, lr}
 *   @0x148564 mov r5, r0
 *   @0x148568 mov r4, #0
 *   @0x14856c ldr r0, [sp, #0x10]
 *   @0x148570 str r4, [r5, #0xc]
 *   @0x148574 mov r1, r4
 *   @0x148578 str r4, [r5]
 *   @0x14857c str r4, [r5, #0x4]
 *   @0x148580 beq 0x148594 <_Z20F_GPUGetTexFilterExtR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x148584 ldr r0, [pc, #0x44]
 *   @0x148588 pop {r3, r4, r5, lr}
 *   @0x14858c add r0, pc, r0
 *   @0x148590 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x148594 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x148598 cmp r0, #7
 *   @0x14859c pophi {r3, r4, r5, pc}
 *   @0x1485a0 ldr r3, [pc, #0x2c]
 *   @0x1485a4 mov r1, r0
 *   @0x1485a8 mov r2, r4
 *   @0x1485ac ldr r0, [pc, r3]
 *   @0x1485b0 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState>
 *   @0x1485b4 str r4, [r5]
 *   @0x1485b8 cmp r0, #1
 *   @0x1485bc moveq r3, #0
 *   @0x1485c0 movne r3, r4
 *   @0x1485c4 movteq r3, #0x3ff0
 *   @0x1485c8 str r3, [r5, #0x4]
 *   @0x1485cc pop {r3, r4, r5, pc}
 *   @0x1485d0 andseq r9, pc, r12, ror #25
 *   @0x1485d4 eoreq r5, r10, r12, asr #14
 *
 * ══ §12/251 F_GPUGetTexMipFilterExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x148734  size 124  31 条（0x148734..0x1487b0）
 * @func 0x148734 0x1487b0  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / RenderStateManager::GetSamplerState(int, eSamplerState)
 * 字段偏移 top8: 0xc×1 / 0x8×1 / 0x44×1 / 0x2c×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x148734 cmp r3, #1
 *   @0x148738 mov r3, #0
 *   @0x14873c push {r4, lr}
 *   @0x148740 mov r1, r3
 *   @0x148744 mov r4, r0
 *   @0x148748 movt r3, #0xbff0
 *   @0x14874c str r1, [r0, #0xc]
 *   @0x148750 stm r0, {r1, r3}
 *   @0x148754 ldr r0, [sp, #0x8]
 *   @0x148758 beq 0x14876c <_Z23F_GPUGetTexMipFilterExtR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x14875c ldr r0, [pc, #0x44]
 *   @0x148760 pop {r4, lr}
 *   @0x148764 add r0, pc, r0
 *   @0x148768 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14876c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x148770 cmp r0, #7
 *   @0x148774 pophi {r4, pc}
 *   @0x148778 ldr r3, [pc, #0x2c]
 *   @0x14877c mov r1, r0
 *   @0x148780 mov r2, #4
 *   @0x148784 ldr r0, [pc, r3]
 *   @0x148788 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState>
 *   @0x14878c vmov s15, r0
 *   @0x148790 vcvt.f64.u32 d7, s15
 *   @0x148794 vmov r0, r1, d7
 *   @0x148798 vmov r2, s14
 *   @0x14879c mov r3, r1
 *   @0x1487a0 stm r4, {r2, r3}
 *   @0x1487a4 pop {r4, pc}
 *   @0x1487a8 andseq r9, pc, r0, lsr #24
 *   @0x1487ac eoreq r5, r10, r4, ror r5
 *
 * ══ §13/251 F_GPUGetTexMipBiasExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x148820  size 124  31 条（0x148820..0x14889c）
 * @func 0x148820 0x14889c  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / RenderStateManager::GetSamplerState(int, eSamplerState)
 * 字段偏移 top8: 0xc×1 / 0x8×1 / 0x44×1 / 0x2c×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x148820 cmp r3, #1
 *   @0x148824 mov r3, #0
 *   @0x148828 push {r4, lr}
 *   @0x14882c mov r1, r3
 *   @0x148830 mov r4, r0
 *   @0x148834 movt r3, #0xbff0
 *   @0x148838 str r1, [r0, #0xc]
 *   @0x14883c stm r0, {r1, r3}
 *   @0x148840 ldr r0, [sp, #0x8]
 *   @0x148844 beq 0x148858 <_Z21F_GPUGetTexMipBiasExtR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x148848 ldr r0, [pc, #0x44]
 *   @0x14884c pop {r4, lr}
 *   @0x148850 add r0, pc, r0
 *   @0x148854 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x148858 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14885c cmp r0, #7
 *   @0x148860 pophi {r4, pc}
 *   @0x148864 ldr r3, [pc, #0x2c]
 *   @0x148868 mov r1, r0
 *   @0x14886c mov r2, #7
 *   @0x148870 ldr r0, [pc, r3]
 *   @0x148874 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState>
 *   @0x148878 vmov s15, r0
 *   @0x14887c vcvt.f64.f32 d7, s15
 *   @0x148880 vmov r0, r1, d7
 *   @0x148884 vmov r2, s14
 *   @0x148888 mov r3, r1
 *   @0x14888c stm r4, {r2, r3}
 *   @0x148890 pop {r4, pc}
 *   @0x148894 andseq r9, pc, r4, asr #23
 *   @0x148898 eoreq r5, r10, r8, lsl #9
 *
 * ══ §14/251 F_GPUGetTexMinMipExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x14890c  size 124  31 条（0x14890c..0x148988）
 * @func 0x14890c 0x148988  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / RenderStateManager::GetSamplerState(int, eSamplerState)
 * 字段偏移 top8: 0xc×1 / 0x8×1 / 0x44×1 / 0x2c×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14890c cmp r3, #1
 *   @0x148910 mov r3, #0
 *   @0x148914 push {r4, lr}
 *   @0x148918 mov r1, r3
 *   @0x14891c mov r4, r0
 *   @0x148920 movt r3, #0xbff0
 *   @0x148924 str r1, [r0, #0xc]
 *   @0x148928 stm r0, {r1, r3}
 *   @0x14892c ldr r0, [sp, #0x8]
 *   @0x148930 beq 0x148944 <_Z20F_GPUGetTexMinMipExtR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x148934 ldr r0, [pc, #0x44]
 *   @0x148938 pop {r4, lr}
 *   @0x14893c add r0, pc, r0
 *   @0x148940 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x148944 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x148948 cmp r0, #7
 *   @0x14894c pophi {r4, pc}
 *   @0x148950 ldr r3, [pc, #0x2c]
 *   @0x148954 mov r1, r0
 *   @0x148958 mov r2, #5
 *   @0x14895c ldr r0, [pc, r3]
 *   @0x148960 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState>
 *   @0x148964 vmov s15, r0
 *   @0x148968 vcvt.f64.f32 d7, s15
 *   @0x14896c vmov r0, r1, d7
 *   @0x148970 vmov r2, s14
 *   @0x148974 mov r3, r1
 *   @0x148978 stm r4, {r2, r3}
 *   @0x14897c pop {r4, pc}
 *   @0x148980 andseq r9, pc, r0, ror #22
 *   @0x148984 mlaeq r10, r12, r3, r5
 *
 * ══ §15/251 F_GPUGetTexMaxMipExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x1489f8  size 124  31 条（0x1489f8..0x148a74）
 * @func 0x1489f8 0x148a74  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / RenderStateManager::GetSamplerState(int, eSamplerState)
 * 字段偏移 top8: 0xc×1 / 0x8×1 / 0x44×1 / 0x2c×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1489f8 cmp r3, #1
 *   @0x1489fc mov r3, #0
 *   @0x148a00 push {r4, lr}
 *   @0x148a04 mov r1, r3
 *   @0x148a08 mov r4, r0
 *   @0x148a0c movt r3, #0xbff0
 *   @0x148a10 str r1, [r0, #0xc]
 *   @0x148a14 stm r0, {r1, r3}
 *   @0x148a18 ldr r0, [sp, #0x8]
 *   @0x148a1c beq 0x148a30 <_Z20F_GPUGetTexMaxMipExtR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x148a20 ldr r0, [pc, #0x44]
 *   @0x148a24 pop {r4, lr}
 *   @0x148a28 add r0, pc, r0
 *   @0x148a2c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x148a30 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x148a34 cmp r0, #7
 *   @0x148a38 pophi {r4, pc}
 *   @0x148a3c ldr r3, [pc, #0x2c]
 *   @0x148a40 mov r1, r0
 *   @0x148a44 mov r2, #6
 *   @0x148a48 ldr r0, [pc, r3]
 *   @0x148a4c bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState>
 *   @0x148a50 vmov s15, r0
 *   @0x148a54 vcvt.f64.f32 d7, s15
 *   @0x148a58 vmov r0, r1, d7
 *   @0x148a5c vmov r2, s14
 *   @0x148a60 mov r3, r1
 *   @0x148a64 stm r4, {r2, r3}
 *   @0x148a68 pop {r4, pc}
 *   @0x148a6c ldrsheq r9, [pc], -r12
 *   @0x148a70 .word 0x002a52b0
 *
 * ══ §16/251 F_GPUGetTexMaxAnisoExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x148ae4  size 124  31 条（0x148ae4..0x148b60）
 * @func 0x148ae4 0x148b60  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / RenderStateManager::GetSamplerState(int, eSamplerState)
 * 字段偏移 top8: 0xc×1 / 0x8×1 / 0x44×1 / 0x2c×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x148ae4 cmp r3, #1
 *   @0x148ae8 mov r3, #0
 *   @0x148aec push {r4, lr}
 *   @0x148af0 mov r1, r3
 *   @0x148af4 mov r4, r0
 *   @0x148af8 movt r3, #0xbff0
 *   @0x148afc str r1, [r0, #0xc]
 *   @0x148b00 stm r0, {r1, r3}
 *   @0x148b04 ldr r0, [sp, #0x8]
 *   @0x148b08 beq 0x148b1c <_Z22F_GPUGetTexMaxAnisoExtR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x148b0c ldr r0, [pc, #0x44]
 *   @0x148b10 pop {r4, lr}
 *   @0x148b14 add r0, pc, r0
 *   @0x148b18 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x148b1c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x148b20 cmp r0, #7
 *   @0x148b24 pophi {r4, pc}
 *   @0x148b28 ldr r3, [pc, #0x2c]
 *   @0x148b2c mov r1, r0
 *   @0x148b30 mov r2, #8
 *   @0x148b34 ldr r0, [pc, r3]
 *   @0x148b38 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState>
 *   @0x148b3c vmov s15, r0
 *   @0x148b40 vcvt.f64.u32 d7, s15
 *   @0x148b44 vmov r0, r1, d7
 *   @0x148b48 vmov r2, s14
 *   @0x148b4c mov r3, r1
 *   @0x148b50 stm r4, {r2, r3}
 *   @0x148b54 pop {r4, pc}
 *   @0x148b58 andseq r9, pc, r12, ror r10
 *   @0x148b5c eoreq r5, r10, r4, asr #3
 *
 * ══ §17/251 F_GPUGetTexMipEnableExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x148bd0  size 124  31 条（0x148bd0..0x148c4c）
 * @func 0x148bd0 0x148c4c  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / RenderStateManager::GetSamplerState(int, eSamplerState)
 * 字段偏移 top8: 0xc×1 / 0x8×1 / 0x44×1 / 0x2c×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x148bd0 cmp r3, #1
 *   @0x148bd4 mov r3, #0
 *   @0x148bd8 push {r4, lr}
 *   @0x148bdc mov r1, r3
 *   @0x148be0 mov r4, r0
 *   @0x148be4 movt r3, #0xbff0
 *   @0x148be8 str r1, [r0, #0xc]
 *   @0x148bec stm r0, {r1, r3}
 *   @0x148bf0 ldr r0, [sp, #0x8]
 *   @0x148bf4 beq 0x148c08 <_Z23F_GPUGetTexMipEnableExtR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x148bf8 ldr r0, [pc, #0x44]
 *   @0x148bfc pop {r4, lr}
 *   @0x148c00 add r0, pc, r0
 *   @0x148c04 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x148c08 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x148c0c cmp r0, #7
 *   @0x148c10 pophi {r4, pc}
 *   @0x148c14 ldr r3, [pc, #0x2c]
 *   @0x148c18 mov r1, r0
 *   @0x148c1c mov r2, #9
 *   @0x148c20 ldr r0, [pc, r3]
 *   @0x148c24 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState>
 *   @0x148c28 vmov s15, r0
 *   @0x148c2c vcvt.f64.u32 d7, s15
 *   @0x148c30 vmov r0, r1, d7
 *   @0x148c34 vmov r2, s14
 *   @0x148c38 mov r3, r1
 *   @0x148c3c stm r4, {r2, r3}
 *   @0x148c40 pop {r4, pc}
 *   @0x148c44 ldrsheq r9, [pc], -r12
 *   @0x148c48 .word 0x002a50d8
 *
 * ══ §18/251 F_PhysicsEndParticleGroup(RValue&, CInstance*, CInstance*, int, RValue*)  0x14db1c  size 124  31 条（0x14db1c..0x14db98）
 * @func 0x14db1c 0x14dbac  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsWorld::EndParticleGroup()
 * 字段偏移 top8: 0x6c×1 / 0xc×1 / 0x4×1 / 0xb4×1 / 0x10×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14db1c ldr r3, [pc, #0x6c]
 *   @0x14db20 mov r1, #0
 *   @0x14db24 push {r4, lr}
 *   @0x14db28 ldr r3, [pc, r3]
 *   @0x14db2c str r1, [r0]
 *   @0x14db30 mov r2, r1
 *   @0x14db34 ldr r3, [r3]
 *   @0x14db38 movt r2, #0xbff0
 *   @0x14db3c mov r4, r0
 *   @0x14db40 str r1, [r0, #0xc]
 *   @0x14db44 cmp r3, r1
 *   @0x14db48 str r2, [r0, #0x4]
 *   @0x14db4c beq 0x14db7c <_Z25F_PhysicsEndParticleGroupR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x14db50 ldr r0, [r3, #0xb4]
 *   @0x14db54 cmp r0, r1
 *   @0x14db58 beq 0x14db7c <_Z25F_PhysicsEndParticleGroupR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x14db5c bl 0x239d30 <_ZN13CPhysicsWorld16EndParticleGroupEv>
 *   @0x14db60 vmov s15, r0
 *   @0x14db64 vcvt.f64.s32 d7, s15
 *   @0x14db68 vmov r0, r1, d7
 *   @0x14db6c vmov r2, s14
 *   @0x14db70 mov r3, r1
 *   @0x14db74 stm r4, {r2, r3}
 *   @0x14db78 pop {r4, pc}
 *   @0x14db7c ldr r0, [pc, #0x10]
 *   @0x14db80 mov r1, #0
 *   @0x14db84 pop {r4, lr}
 *   @0x14db88 add r0, pc, r0
 *   @0x14db8c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14db90 eoreq pc, r9, r0, lsl #28
 *   @0x14db94 andseq r6, pc, r0, ror r8
 *
 * ══ §19/251 SGamepadMapping::CreateFromFile(char const*)  0x152b14  size 124  31 条（0x152b14..0x152b90）
 * @func 0x152b14 0x152b90  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LoadSave::SaveFileExists(char const*) / LoadSave::BundleFileExists(char const*) / SGamepadMapping::CreateFromFileAsString(unsigned char*, int) / MemoryManager::Free(void const*) / LoadSave::ReadBundleFile(char const*, int*) / LoadSave::ReadSaveFile(char const*, int*)
 * 字段偏移 top8: 0x4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x152b14 push {r4, r5, lr}
 *   @0x152b18 sub sp, sp, #12
 *   @0x152b1c mov r3, #0
 *   @0x152b20 mov r5, r0
 *   @0x152b24 str r3, [sp, #0x4]
 *   @0x152b28 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0x152b2c cmp r0, #0
 *   @0x152b30 mov r0, r5
 *   @0x152b34 bne 0x152b80 <_ZN15SGamepadMapping14CreateFromFileEPKc+0x6c>
 *   @0x152b38 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0x152b3c cmp r0, #0
 *   @0x152b40 moveq r4, r0
 *   @0x152b44 bne 0x152b6c <_ZN15SGamepadMapping14CreateFromFileEPKc+0x58>
 *   @0x152b48 ldr r1, [sp, #0x4]
 *   @0x152b4c mov r0, r4
 *   @0x152b50 bl 0x1529e0 <_ZN15SGamepadMapping22CreateFromFileAsStringEPhi>
 *   @0x152b54 mov r5, r0
 *   @0x152b58 mov r0, r4
 *   @0x152b5c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x152b60 mov r0, r5
 *   @0x152b64 add sp, sp, #12
 *   @0x152b68 pop {r4, r5, pc}
 *   @0x152b6c mov r0, r5
 *   @0x152b70 add r1, sp, #4
 *   @0x152b74 bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi>
 *   @0x152b78 mov r4, r0
 *   @0x152b7c b 0x152b48 <_ZN15SGamepadMapping14CreateFromFileEPKc+0x34>
 *   @0x152b80 add r1, sp, #4
 *   @0x152b84 bl 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi>
 *   @0x152b88 mov r4, r0
 *   @0x152b8c b 0x152b48 <_ZN15SGamepadMapping14CreateFromFileEPKc+0x34>
 *
 * ══ §20/251 YYIAPRestoreEvent(int)  0x1556a8  size 124  31 条（0x1556a8..0x155724）
 * @func 0x1556a8 0x155724  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Mutex::Lock() / anon_154a70 / anon_153020+0x1ac
 * 字段偏移 top8: 0x60×1 / 0x4c×1 / 0x44×1 / 0x10×1 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1556a8 push {r4, r5, lr}
 *   @0x1556ac mov r5, r0
 *   @0x1556b0 ldr r4, [pc, #0x60]
 *   @0x1556b4 sub sp, sp, #28
 *   @0x1556b8 add r4, pc, r4
 *   @0x1556bc ldr r0, [r4]
 *   @0x1556c0 bl 0x27e084 <_ZN5Mutex4LockEv>
 *   @0x1556c4 vmov s13, r5
 *   @0x1556c8 ldr r2, [pc, #0x4c]
 *   @0x1556cc mov r3, #0
 *   @0x1556d0 vcvt.f64.s32 d7, s13
 *   @0x1556d4 ldr r1, [pc, #0x44]
 *   @0x1556d8 str r3, [sp]
 *   @0x1556dc add r2, pc, r2
 *   @0x1556e0 str r3, [sp, #0x10]
 *   @0x1556e4 add r1, pc, r1
 *   @0x1556e8 str r2, [sp, #0x4]
 *   @0x1556ec mov r0, #2
 *   @0x1556f0 mov r2, #0
 *   @0x1556f4 mov r3, #0
 *   @0x1556f8 movt r3, #0x4010
 *   @0x1556fc vstr d7, [sp, #8]
 *   @0x155700 bl 0x154a70 <_Z19YYIAPEventsDispatchv+0xe88>
 *   @0x155704 bl 0x1531cc <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x1d8>
 *   @0x155708 ldr r0, [r4]
 *   @0x15570c add sp, sp, #28
 *   @0x155710 pop {r4, r5, lr}
 *   @0x155714 b 0x27e09c <_ZN5Mutex6UnlockEv>
 *   @0x155718 eorseq pc, r2, r8, lsl #7
 *   @0x15571c andseq r1, lr, r12, ror r8
 *   @0x155720 andseq r0, pc, r4, asr #20
 *
 * ══ §21/251 F_YoYo_FacebookGraphRequest(RValue&, CInstance*, CInstance*, int, RValue*)  0x1572ac  size 124  31 条（0x1572ac..0x157328）
 * @func 0x1572ac 0x157328  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)×2 / YYGetInt32(RValue const*, int)×2 / FacebookGraphRequestM(char*, char*, int, int)
 * 字段偏移 top8: 0x18×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1572ac push {r4, r5, r6, r7, r8, lr}
 *   @0x1572b0 mov r1, #0
 *   @0x1572b4 ldr r4, [sp, #0x18]
 *   @0x1572b8 mov r5, r0
 *   @0x1572bc str r1, [r0, #0xc]
 *   @0x1572c0 mov r0, r4
 *   @0x1572c4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1572c8 mov r1, #1
 *   @0x1572cc mov r8, r0
 *   @0x1572d0 mov r0, r4
 *   @0x1572d4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1572d8 mov r1, #2
 *   @0x1572dc mov r7, r0
 *   @0x1572e0 mov r0, r4
 *   @0x1572e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1572e8 mov r1, #3
 *   @0x1572ec mov r6, r0
 *   @0x1572f0 mov r0, r4
 *   @0x1572f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1572f8 mov r1, r7
 *   @0x1572fc mov r2, r6
 *   @0x157300 mov r3, r0
 *   @0x157304 mov r0, r8
 *   @0x157308 bl 0x15fe9c <_Z21FacebookGraphRequestMPcS_ii>
 *   @0x15730c vmov s15, r0
 *   @0x157310 vcvt.f64.s32 d7, s15
 *   @0x157314 vmov r0, r1, d7
 *   @0x157318 vmov r2, s14
 *   @0x15731c mov r3, r1
 *   @0x157320 stm r5, {r2, r3}
 *   @0x157324 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §22/251 GR_3DM_Primitive_End(int)  0x1658d0  size 124  31 条（0x1658d0..0x16594c）
 * @func 0x1658d0 0x16594c  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3DM_Primitive_End(int)+0x6c / C3D_Model::AddEntry(int, float, float, float, float, float, float, float, float, float, float)
 * 字段偏移 top8: 0x4×3 / 0x-4×1 / 0x5c×1 / 0x4c×1 / 0x2×1 / 0x8×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1658d0 cmp r0, #0
 *   @0x1658d4 str lr, [sp, #-0x4]!
 *   @0x1658d8 sub sp, sp, #36
 *   @0x1658dc blt 0x16593c <_Z20GR_3DM_Primitive_Endi+0x6c>
 *   @0x1658e0 ldr r3, [pc, #0x5c]
 *   @0x1658e4 ldr r3, [pc, r3]
 *   @0x1658e8 ldr r3, [r3]
 *   @0x1658ec cmp r0, r3
 *   @0x1658f0 bge 0x16593c <_Z20GR_3DM_Primitive_Endi+0x6c>
 *   @0x1658f4 ldr r3, [pc, #0x4c]
 *   @0x1658f8 ldr r3, [pc, r3]
 *   @0x1658fc ldr r3, [r3, #0x4]
 *   @0x165900 ldr r0, [r3, r0, lsl #2]
 *   @0x165904 cmp r0, #0
 *   @0x165908 beq 0x16593c <_Z20GR_3DM_Primitive_Endi+0x6c>
 *   @0x16590c mov r3, #0
 *   @0x165910 mov r1, #1
 *   @0x165914 mov r2, r3
 *   @0x165918 str r3, [sp]
 *   @0x16591c str r3, [sp, #0x4]
 *   @0x165920 str r3, [sp, #0x8]
 *   @0x165924 str r3, [sp, #0xc]
 *   @0x165928 str r3, [sp, #0x10]
 *   @0x16592c str r3, [sp, #0x14]
 *   @0x165930 str r3, [sp, #0x18]
 *   @0x165934 str r3, [sp, #0x1c]
 *   @0x165938 bl 0x1648d4 <_ZN9C3D_Model8AddEntryEiffffffffff>
 *   @0x16593c add sp, sp, #36
 *   @0x165940 ldr pc, [sp], #4
 *   @0x165944 eoreq r10, r8, r12, lsl #16
 *   @0x165948 .word 0x0028a7fc
 *
 * ══ §23/251 _CreateBlankTexture()  0x168b64  size 124  31 条（0x168b64..0x168be0）
 * @func 0x168b64 0x168be0  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Texture_Create_And_Fill(int, int, unsigned char*, unsigned int) / GR_Texture_Exists(int)
 * 字段偏移 top8: 0x60×1 / 0x-4×1 / 0x20×1 / 0x18×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x168b64 push {r4, lr}
 *   @0x168b68 sub sp, sp, #8
 *   @0x168b6c ldr r4, [pc, #0x60]
 *   @0x168b70 ldr r4, [pc, r4]
 *   @0x168b74 ldr r3, [r4]
 *   @0x168b78 cmn r3, #1
 *   @0x168b7c beq 0x168b88 <_Z19_CreateBlankTexturev+0x24>
 *   @0x168b80 add sp, sp, #8
 *   @0x168b84 pop {r4, pc}
 *   @0x168b88 add r2, sp, #8
 *   @0x168b8c mov r0, #1
 *   @0x168b90 mov r1, r0
 *   @0x168b94 str r3, [r2, #-0x4]!
 *   @0x168b98 mov r3, #4
 *   @0x168b9c bl 0x173c18 <_Z26GR_Texture_Create_And_FilliiPhj>
 *   @0x168ba0 str r0, [r4]
 *   @0x168ba4 bl 0x173e2c <_Z17GR_Texture_Existsi>
 *   @0x168ba8 cmp r0, #0
 *   @0x168bac beq 0x168b80 <_Z19_CreateBlankTexturev+0x1c>
 *   @0x168bb0 ldr r2, [pc, #0x20]
 *   @0x168bb4 ldr r1, [r4]
 *   @0x168bb8 ldr r2, [pc, r2]
 *   @0x168bbc ldr r3, [pc, #0x18]
 *   @0x168bc0 ldr r2, [r2, #0x4]
 *   @0x168bc4 ldr r3, [pc, r3]
 *   @0x168bc8 ldr r2, [r2, r1, lsl #2]
 *   @0x168bcc str r2, [r3]
 *   @0x168bd0 b 0x168b80 <_Z19_CreateBlankTexturev+0x1c>
 *   @0x168bd4 .word 0x002875bc
 *   @0x168bd8 eoreq r4, r8, r4, ror #26
 *   @0x168bdc eoreq r7, r8, r12, ror #10
 *
 * ══ §24/251 F_CameraGetViewTarget(RValue&, CInstance*, CInstance*, int, RValue*)  0x17000c  size 124  31 条（0x17000c..0x170088）
 * @func 0x17000c 0x17009c  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CCameraManager::GetCamera(int) / CCamera::GetTargetInstance()
 * 字段偏移 top8: 0xc×1 / 0x8×1 / 0x44×1 / 0x34×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17000c cmp r3, #1
 *   @0x170010 mov r3, #0
 *   @0x170014 push {r4, lr}
 *   @0x170018 mov r1, r3
 *   @0x17001c mov r4, r0
 *   @0x170020 movt r3, #0xbff0
 *   @0x170024 str r1, [r0, #0xc]
 *   @0x170028 stm r0, {r1, r3}
 *   @0x17002c ldr r0, [sp, #0x8]
 *   @0x170030 beq 0x170044 <_Z21F_CameraGetViewTargetR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x170034 ldr r0, [pc, #0x44]
 *   @0x170038 pop {r4, lr}
 *   @0x17003c add r0, pc, r0
 *   @0x170040 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x170044 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x170048 ldr r3, [pc, #0x34]
 *   @0x17004c mov r1, r0
 *   @0x170050 ldr r0, [pc, r3]
 *   @0x170054 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi>
 *   @0x170058 cmp r0, #0
 *   @0x17005c popeq {r4, pc}
 *   @0x170060 bl 0x16d334 <_ZN7CCamera17GetTargetInstanceEv>
 *   @0x170064 vmov s15, r0
 *   @0x170068 vcvt.f64.s32 d7, s15
 *   @0x17006c vmov r0, r1, d7
 *   @0x170070 vmov r2, s14
 *   @0x170074 mov r3, r1
 *   @0x170078 stm r4, {r2, r3}
 *   @0x17007c pop {r4, pc}
 *   @0x170080 andseq r11, sp, r12, ror r0
 *   @0x170084 eoreq sp, r7, r4, lsr #24
 *
 * ══ §25/251 F_CameraGetUpdateScript(RValue&, CInstance*, CInstance*, int, RValue*)  0x170088  size 124  31 条（0x170088..0x170104）
 * @func 0x170088 0x170118  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CCameraManager::GetCamera(int) / CCamera::GetUpdateScript()
 * 字段偏移 top8: 0xc×1 / 0x8×1 / 0x44×1 / 0x34×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x170088 cmp r3, #1
 *   @0x17008c mov r3, #0
 *   @0x170090 push {r4, lr}
 *   @0x170094 mov r1, r3
 *   @0x170098 mov r4, r0
 *   @0x17009c movt r3, #0xbff0
 *   @0x1700a0 str r1, [r0, #0xc]
 *   @0x1700a4 stm r0, {r1, r3}
 *   @0x1700a8 ldr r0, [sp, #0x8]
 *   @0x1700ac beq 0x1700c0 <_Z23F_CameraGetUpdateScriptR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x1700b0 ldr r0, [pc, #0x44]
 *   @0x1700b4 pop {r4, lr}
 *   @0x1700b8 add r0, pc, r0
 *   @0x1700bc b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1700c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1700c4 ldr r3, [pc, #0x34]
 *   @0x1700c8 mov r1, r0
 *   @0x1700cc ldr r0, [pc, r3]
 *   @0x1700d0 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi>
 *   @0x1700d4 cmp r0, #0
 *   @0x1700d8 popeq {r4, pc}
 *   @0x1700dc bl 0x16d364 <_ZN7CCamera15GetUpdateScriptEv>
 *   @0x1700e0 vmov s15, r0
 *   @0x1700e4 vcvt.f64.s32 d7, s15
 *   @0x1700e8 vmov r0, r1, d7
 *   @0x1700ec vmov r2, s14
 *   @0x1700f0 mov r3, r1
 *   @0x1700f4 stm r4, {r2, r3}
 *   @0x1700f8 pop {r4, pc}
 *   @0x1700fc andseq r11, sp, r8, lsr r0
 *   @0x170100 eoreq sp, r7, r8, lsr #23
 *
 * ══ §26/251 F_CameraGetBeginScript(RValue&, CInstance*, CInstance*, int, RValue*)  0x170104  size 124  31 条（0x170104..0x170180）
 * @func 0x170104 0x170194  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CCameraManager::GetCamera(int) / CCamera::GetBeginScript()
 * 字段偏移 top8: 0xc×1 / 0x8×1 / 0x44×1 / 0x34×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x170104 cmp r3, #1
 *   @0x170108 mov r3, #0
 *   @0x17010c push {r4, lr}
 *   @0x170110 mov r1, r3
 *   @0x170114 mov r4, r0
 *   @0x170118 movt r3, #0xbff0
 *   @0x17011c str r1, [r0, #0xc]
 *   @0x170120 stm r0, {r1, r3}
 *   @0x170124 ldr r0, [sp, #0x8]
 *   @0x170128 beq 0x17013c <_Z22F_CameraGetBeginScriptR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x17012c ldr r0, [pc, #0x44]
 *   @0x170130 pop {r4, lr}
 *   @0x170134 add r0, pc, r0
 *   @0x170138 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x17013c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x170140 ldr r3, [pc, #0x34]
 *   @0x170144 mov r1, r0
 *   @0x170148 ldr r0, [pc, r3]
 *   @0x17014c bl 0x16f45c <_ZN14CCameraManager9GetCameraEi>
 *   @0x170150 cmp r0, #0
 *   @0x170154 popeq {r4, pc}
 *   @0x170158 bl 0x16d344 <_ZN7CCamera14GetBeginScriptEv>
 *   @0x17015c vmov s15, r0
 *   @0x170160 vcvt.f64.s32 d7, s15
 *   @0x170164 vmov r0, r1, d7
 *   @0x170168 vmov r2, s14
 *   @0x17016c mov r3, r1
 *   @0x170170 stm r4, {r2, r3}
 *   @0x170174 pop {r4, pc}
 *   @0x170178 ldrsheq r10, [sp], -r4
 *   @0x17017c eoreq sp, r7, r12, lsr #22
 *
 * ══ §27/251 F_CameraGetEndScript(RValue&, CInstance*, CInstance*, int, RValue*)  0x170180  size 124  31 条（0x170180..0x1701fc）
 * @func 0x170180 0x170210  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CCameraManager::GetCamera(int) / CCamera::GetEndScript()
 * 字段偏移 top8: 0xc×1 / 0x8×1 / 0x44×1 / 0x34×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x170180 cmp r3, #1
 *   @0x170184 mov r3, #0
 *   @0x170188 push {r4, lr}
 *   @0x17018c mov r1, r3
 *   @0x170190 mov r4, r0
 *   @0x170194 movt r3, #0xbff0
 *   @0x170198 str r1, [r0, #0xc]
 *   @0x17019c stm r0, {r1, r3}
 *   @0x1701a0 ldr r0, [sp, #0x8]
 *   @0x1701a4 beq 0x1701b8 <_Z20F_CameraGetEndScriptR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x1701a8 ldr r0, [pc, #0x44]
 *   @0x1701ac pop {r4, lr}
 *   @0x1701b0 add r0, pc, r0
 *   @0x1701b4 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1701b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1701bc ldr r3, [pc, #0x34]
 *   @0x1701c0 mov r1, r0
 *   @0x1701c4 ldr r0, [pc, r3]
 *   @0x1701c8 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi>
 *   @0x1701cc cmp r0, #0
 *   @0x1701d0 popeq {r4, pc}
 *   @0x1701d4 bl 0x16d354 <_ZN7CCamera12GetEndScriptEv>
 *   @0x1701d8 vmov s15, r0
 *   @0x1701dc vcvt.f64.s32 d7, s15
 *   @0x1701e0 vmov r0, r1, d7
 *   @0x1701e4 vmov r2, s14
 *   @0x1701e8 mov r3, r1
 *   @0x1701ec stm r4, {r2, r3}
 *   @0x1701f0 pop {r4, pc}
 *   @0x1701f4 ldrheq r10, [sp], -r0
 *   @0x1701f8 .word 0x0027dab0
 *
 * ══ §28/251 F_CameraGetViewX(RValue&, CInstance*, CInstance*, int, RValue*)  0x1701fc  size 124  31 条（0x1701fc..0x170278）
 * @func 0x1701fc 0x17028c  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CCameraManager::GetCamera(int) / CCamera::GetViewX()
 * 字段偏移 top8: 0xc×1 / 0x8×1 / 0x44×1 / 0x34×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1701fc cmp r3, #1
 *   @0x170200 mov r3, #0
 *   @0x170204 push {r4, lr}
 *   @0x170208 mov r1, r3
 *   @0x17020c mov r4, r0
 *   @0x170210 movt r3, #0xbff0
 *   @0x170214 str r1, [r0, #0xc]
 *   @0x170218 stm r0, {r1, r3}
 *   @0x17021c ldr r0, [sp, #0x8]
 *   @0x170220 beq 0x170234 <_Z16F_CameraGetViewXR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x170224 ldr r0, [pc, #0x44]
 *   @0x170228 pop {r4, lr}
 *   @0x17022c add r0, pc, r0
 *   @0x170230 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x170234 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x170238 ldr r3, [pc, #0x34]
 *   @0x17023c mov r1, r0
 *   @0x170240 ldr r0, [pc, r3]
 *   @0x170244 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi>
 *   @0x170248 cmp r0, #0
 *   @0x17024c popeq {r4, pc}
 *   @0x170250 bl 0x16d2a4 <_ZN7CCamera8GetViewXEv>
 *   @0x170254 vmov s15, r0
 *   @0x170258 vcvt.f64.f32 d7, s15
 *   @0x17025c vmov r0, r1, d7
 *   @0x170260 vmov r2, s14
 *   @0x170264 mov r3, r1
 *   @0x170268 stm r4, {r2, r3}
 *   @0x17026c pop {r4, pc}
 *   @0x170270 andseq r10, sp, r8, ror #30
 *   @0x170274 eoreq sp, r7, r4, lsr r10
 *
 * ══ §29/251 F_CameraGetViewY(RValue&, CInstance*, CInstance*, int, RValue*)  0x170278  size 124  31 条（0x170278..0x1702f4）
 * @func 0x170278 0x170308  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CCameraManager::GetCamera(int) / CCamera::GetViewY()
 * 字段偏移 top8: 0xc×1 / 0x8×1 / 0x44×1 / 0x34×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x170278 cmp r3, #1
 *   @0x17027c mov r3, #0
 *   @0x170280 push {r4, lr}
 *   @0x170284 mov r1, r3
 *   @0x170288 mov r4, r0
 *   @0x17028c movt r3, #0xbff0
 *   @0x170290 str r1, [r0, #0xc]
 *   @0x170294 stm r0, {r1, r3}
 *   @0x170298 ldr r0, [sp, #0x8]
 *   @0x17029c beq 0x1702b0 <_Z16F_CameraGetViewYR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x1702a0 ldr r0, [pc, #0x44]
 *   @0x1702a4 pop {r4, lr}
 *   @0x1702a8 add r0, pc, r0
 *   @0x1702ac b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1702b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1702b4 ldr r3, [pc, #0x34]
 *   @0x1702b8 mov r1, r0
 *   @0x1702bc ldr r0, [pc, r3]
 *   @0x1702c0 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi>
 *   @0x1702c4 cmp r0, #0
 *   @0x1702c8 popeq {r4, pc}
 *   @0x1702cc bl 0x16d2b4 <_ZN7CCamera8GetViewYEv>
 *   @0x1702d0 vmov s15, r0
 *   @0x1702d4 vcvt.f64.f32 d7, s15
 *   @0x1702d8 vmov r0, r1, d7
 *   @0x1702dc vmov r2, s14
 *   @0x1702e0 mov r3, r1
 *   @0x1702e4 stm r4, {r2, r3}
 *   @0x1702e8 pop {r4, pc}
 *   @0x1702ec andseq r10, sp, r12, lsl pc
 *   @0x1702f0 .word 0x0027d9b8
 *
 * ══ §30/251 F_CameraGetViewWidth(RValue&, CInstance*, CInstance*, int, RValue*)  0x1702f4  size 124  31 条（0x1702f4..0x170370）
 * @func 0x1702f4 0x170384  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CCameraManager::GetCamera(int) / CCamera::GetViewWidth()
 * 字段偏移 top8: 0xc×1 / 0x8×1 / 0x44×1 / 0x34×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1702f4 cmp r3, #1
 *   @0x1702f8 mov r3, #0
 *   @0x1702fc push {r4, lr}
 *   @0x170300 mov r1, r3
 *   @0x170304 mov r4, r0
 *   @0x170308 movt r3, #0xbff0
 *   @0x17030c str r1, [r0, #0xc]
 *   @0x170310 stm r0, {r1, r3}
 *   @0x170314 ldr r0, [sp, #0x8]
 *   @0x170318 beq 0x17032c <_Z20F_CameraGetViewWidthR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x17031c ldr r0, [pc, #0x44]
 *   @0x170320 pop {r4, lr}
 *   @0x170324 add r0, pc, r0
 *   @0x170328 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x17032c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x170330 ldr r3, [pc, #0x34]
 *   @0x170334 mov r1, r0
 *   @0x170338 ldr r0, [pc, r3]
 *   @0x17033c bl 0x16f45c <_ZN14CCameraManager9GetCameraEi>
 *   @0x170340 cmp r0, #0
 *   @0x170344 popeq {r4, pc}
 *   @0x170348 bl 0x16d2c4 <_ZN7CCamera12GetViewWidthEv>
 *   @0x17034c vmov s15, r0
 *   @0x170350 vcvt.f64.f32 d7, s15
 *   @0x170354 vmov r0, r1, d7
 *   @0x170358 vmov r2, s14
 *   @0x17035c mov r3, r1
 *   @0x170360 stm r4, {r2, r3}
 *   @0x170364 pop {r4, pc}
 *   @0x170368 ldrsbeq r10, [sp], -r0
 *   @0x17036c eoreq sp, r7, r12, lsr r9
 *
 * ══ §31/251 F_CameraGetViewHeight(RValue&, CInstance*, CInstance*, int, RValue*)  0x170370  size 124  31 条（0x170370..0x1703ec）
 * @func 0x170370 0x170400  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CCameraManager::GetCamera(int) / CCamera::GetViewHeight()
 * 字段偏移 top8: 0xc×1 / 0x8×1 / 0x44×1 / 0x34×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x170370 cmp r3, #1
 *   @0x170374 mov r3, #0
 *   @0x170378 push {r4, lr}
 *   @0x17037c mov r1, r3
 *   @0x170380 mov r4, r0
 *   @0x170384 movt r3, #0xbff0
 *   @0x170388 str r1, [r0, #0xc]
 *   @0x17038c stm r0, {r1, r3}
 *   @0x170390 ldr r0, [sp, #0x8]
 *   @0x170394 beq 0x1703a8 <_Z21F_CameraGetViewHeightR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x170398 ldr r0, [pc, #0x44]
 *   @0x17039c pop {r4, lr}
 *   @0x1703a0 add r0, pc, r0
 *   @0x1703a4 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1703a8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1703ac ldr r3, [pc, #0x34]
 *   @0x1703b0 mov r1, r0
 *   @0x1703b4 ldr r0, [pc, r3]
 *   @0x1703b8 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi>
 *   @0x1703bc cmp r0, #0
 *   @0x1703c0 popeq {r4, pc}
 *   @0x1703c4 bl 0x16d2d4 <_ZN7CCamera13GetViewHeightEv>
 *   @0x1703c8 vmov s15, r0
 *   @0x1703cc vcvt.f64.f32 d7, s15
 *   @0x1703d0 vmov r0, r1, d7
 *   @0x1703d4 vmov r2, s14
 *   @0x1703d8 mov r3, r1
 *   @0x1703dc stm r4, {r2, r3}
 *   @0x1703e0 pop {r4, pc}
 *   @0x1703e4 andseq r10, sp, r8, lsl #29
 *   @0x1703e8 eoreq sp, r7, r0, asr #17
 *
 * ══ §32/251 F_CameraGetViewSpeedX(RValue&, CInstance*, CInstance*, int, RValue*)  0x1703ec  size 124  31 条（0x1703ec..0x170468）
 * @func 0x1703ec 0x17047c  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CCameraManager::GetCamera(int) / CCamera::GetViewSpeedX()
 * 字段偏移 top8: 0xc×1 / 0x8×1 / 0x44×1 / 0x34×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1703ec cmp r3, #1
 *   @0x1703f0 mov r3, #0
 *   @0x1703f4 push {r4, lr}
 *   @0x1703f8 mov r1, r3
 *   @0x1703fc mov r4, r0
 *   @0x170400 movt r3, #0xbff0
 *   @0x170404 str r1, [r0, #0xc]
 *   @0x170408 stm r0, {r1, r3}
 *   @0x17040c ldr r0, [sp, #0x8]
 *   @0x170410 beq 0x170424 <_Z21F_CameraGetViewSpeedXR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x170414 ldr r0, [pc, #0x44]
 *   @0x170418 pop {r4, lr}
 *   @0x17041c add r0, pc, r0
 *   @0x170420 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x170424 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x170428 ldr r3, [pc, #0x34]
 *   @0x17042c mov r1, r0
 *   @0x170430 ldr r0, [pc, r3]
 *   @0x170434 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi>
 *   @0x170438 cmp r0, #0
 *   @0x17043c popeq {r4, pc}
 *   @0x170440 bl 0x16d2e4 <_ZN7CCamera13GetViewSpeedXEv>
 *   @0x170444 vmov s15, r0
 *   @0x170448 vcvt.f64.f32 d7, s15
 *   @0x17044c vmov r0, r1, d7
 *   @0x170450 vmov r2, s14
 *   @0x170454 mov r3, r1
 *   @0x170458 stm r4, {r2, r3}
 *   @0x17045c pop {r4, pc}
 *   @0x170460 andseq r10, sp, r4, asr #28
 *   @0x170464 eoreq sp, r7, r4, asr #16
 *
 * ══ §33/251 F_CameraGetViewSpeedY(RValue&, CInstance*, CInstance*, int, RValue*)  0x170468  size 124  31 条（0x170468..0x1704e4）
 * @func 0x170468 0x1704f8  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CCameraManager::GetCamera(int) / CCamera::GetViewSpeedY()
 * 字段偏移 top8: 0xc×1 / 0x8×1 / 0x44×1 / 0x34×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x170468 cmp r3, #1
 *   @0x17046c mov r3, #0
 *   @0x170470 push {r4, lr}
 *   @0x170474 mov r1, r3
 *   @0x170478 mov r4, r0
 *   @0x17047c movt r3, #0xbff0
 *   @0x170480 str r1, [r0, #0xc]
 *   @0x170484 stm r0, {r1, r3}
 *   @0x170488 ldr r0, [sp, #0x8]
 *   @0x17048c beq 0x1704a0 <_Z21F_CameraGetViewSpeedYR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x170490 ldr r0, [pc, #0x44]
 *   @0x170494 pop {r4, lr}
 *   @0x170498 add r0, pc, r0
 *   @0x17049c b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1704a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1704a4 ldr r3, [pc, #0x34]
 *   @0x1704a8 mov r1, r0
 *   @0x1704ac ldr r0, [pc, r3]
 *   @0x1704b0 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi>
 *   @0x1704b4 cmp r0, #0
 *   @0x1704b8 popeq {r4, pc}
 *   @0x1704bc bl 0x16d2f4 <_ZN7CCamera13GetViewSpeedYEv>
 *   @0x1704c0 vmov s15, r0
 *   @0x1704c4 vcvt.f64.f32 d7, s15
 *   @0x1704c8 vmov r0, r1, d7
 *   @0x1704cc vmov r2, s14
 *   @0x1704d0 mov r3, r1
 *   @0x1704d4 stm r4, {r2, r3}
 *   @0x1704d8 pop {r4, pc}
 *   @0x1704dc andseq r10, sp, r0, lsl #28
 *   @0x1704e0 eoreq sp, r7, r8, asr #15
 *
 * ══ §34/251 F_CameraGetViewBorderX(RValue&, CInstance*, CInstance*, int, RValue*)  0x1704e4  size 124  31 条（0x1704e4..0x170560）
 * @func 0x1704e4 0x170574  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CCameraManager::GetCamera(int) / CCamera::GetViewBorderX()
 * 字段偏移 top8: 0xc×1 / 0x8×1 / 0x44×1 / 0x34×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1704e4 cmp r3, #1
 *   @0x1704e8 mov r3, #0
 *   @0x1704ec push {r4, lr}
 *   @0x1704f0 mov r1, r3
 *   @0x1704f4 mov r4, r0
 *   @0x1704f8 movt r3, #0xbff0
 *   @0x1704fc str r1, [r0, #0xc]
 *   @0x170500 stm r0, {r1, r3}
 *   @0x170504 ldr r0, [sp, #0x8]
 *   @0x170508 beq 0x17051c <_Z22F_CameraGetViewBorderXR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x17050c ldr r0, [pc, #0x44]
 *   @0x170510 pop {r4, lr}
 *   @0x170514 add r0, pc, r0
 *   @0x170518 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x17051c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x170520 ldr r3, [pc, #0x34]
 *   @0x170524 mov r1, r0
 *   @0x170528 ldr r0, [pc, r3]
 *   @0x17052c bl 0x16f45c <_ZN14CCameraManager9GetCameraEi>
 *   @0x170530 cmp r0, #0
 *   @0x170534 popeq {r4, pc}
 *   @0x170538 bl 0x16d304 <_ZN7CCamera14GetViewBorderXEv>
 *   @0x17053c vmov s15, r0
 *   @0x170540 vcvt.f64.f32 d7, s15
 *   @0x170544 vmov r0, r1, d7
 *   @0x170548 vmov r2, s14
 *   @0x17054c mov r3, r1
 *   @0x170550 stm r4, {r2, r3}
 *   @0x170554 pop {r4, pc}
 *   @0x170558 ldrheq r10, [sp], -r12
 *   @0x17055c eoreq sp, r7, r12, asr #14
 *
 * ══ §35/251 F_CameraGetViewBorderY(RValue&, CInstance*, CInstance*, int, RValue*)  0x170560  size 124  31 条（0x170560..0x1705dc）
 * @func 0x170560 0x1705f0  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CCameraManager::GetCamera(int) / CCamera::GetViewBorderY()
 * 字段偏移 top8: 0xc×1 / 0x8×1 / 0x44×1 / 0x34×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x170560 cmp r3, #1
 *   @0x170564 mov r3, #0
 *   @0x170568 push {r4, lr}
 *   @0x17056c mov r1, r3
 *   @0x170570 mov r4, r0
 *   @0x170574 movt r3, #0xbff0
 *   @0x170578 str r1, [r0, #0xc]
 *   @0x17057c stm r0, {r1, r3}
 *   @0x170580 ldr r0, [sp, #0x8]
 *   @0x170584 beq 0x170598 <_Z22F_CameraGetViewBorderYR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x170588 ldr r0, [pc, #0x44]
 *   @0x17058c pop {r4, lr}
 *   @0x170590 add r0, pc, r0
 *   @0x170594 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x170598 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x17059c ldr r3, [pc, #0x34]
 *   @0x1705a0 mov r1, r0
 *   @0x1705a4 ldr r0, [pc, r3]
 *   @0x1705a8 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi>
 *   @0x1705ac cmp r0, #0
 *   @0x1705b0 popeq {r4, pc}
 *   @0x1705b4 bl 0x16d314 <_ZN7CCamera14GetViewBorderYEv>
 *   @0x1705b8 vmov s15, r0
 *   @0x1705bc vcvt.f64.f32 d7, s15
 *   @0x1705c0 vmov r0, r1, d7
 *   @0x1705c4 vmov r2, s14
 *   @0x1705c8 mov r3, r1
 *   @0x1705cc stm r4, {r2, r3}
 *   @0x1705d0 pop {r4, pc}
 *   @0x1705d4 andseq r10, sp, r8, ror sp
 *   @0x1705d8 .word 0x0027d6d0
 *
 * ══ §36/251 F_CameraGetViewAngle(RValue&, CInstance*, CInstance*, int, RValue*)  0x1705dc  size 124  31 条（0x1705dc..0x170658）
 * @func 0x1705dc 0x170658  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CCameraManager::GetCamera(int) / CCamera::GetViewAngle()
 * 字段偏移 top8: 0xc×1 / 0x8×1 / 0x44×1 / 0x34×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1705dc cmp r3, #1
 *   @0x1705e0 mov r3, #0
 *   @0x1705e4 push {r4, lr}
 *   @0x1705e8 mov r1, r3
 *   @0x1705ec mov r4, r0
 *   @0x1705f0 movt r3, #0xbff0
 *   @0x1705f4 str r1, [r0, #0xc]
 *   @0x1705f8 stm r0, {r1, r3}
 *   @0x1705fc ldr r0, [sp, #0x8]
 *   @0x170600 beq 0x170614 <_Z20F_CameraGetViewAngleR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x170604 ldr r0, [pc, #0x44]
 *   @0x170608 pop {r4, lr}
 *   @0x17060c add r0, pc, r0
 *   @0x170610 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x170614 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x170618 ldr r3, [pc, #0x34]
 *   @0x17061c mov r1, r0
 *   @0x170620 ldr r0, [pc, r3]
 *   @0x170624 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi>
 *   @0x170628 cmp r0, #0
 *   @0x17062c popeq {r4, pc}
 *   @0x170630 bl 0x16d324 <_ZN7CCamera12GetViewAngleEv>
 *   @0x170634 vmov s15, r0
 *   @0x170638 vcvt.f64.f32 d7, s15
 *   @0x17063c vmov r0, r1, d7
 *   @0x170640 vmov r2, s14
 *   @0x170644 mov r3, r1
 *   @0x170648 stm r4, {r2, r3}
 *   @0x17064c pop {r4, pc}
 *   @0x170650 andseq r10, sp, r4, lsr sp
 *   @0x170654 eoreq sp, r7, r4, asr r6
 *
 * ══ §37/251 MakeDefaultFont()  0x172468  size 124  31 条（0x172468..0x1724e4）
 * @func 0x172468 0x1724f8  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Texture_Add(void*, int, int) / operator new(unsigned int) / CFontGM::CFontGM(unsigned char*, int, int, int)
 * 字段偏移 top8: 0x60×1 / 0x48×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x172468 push {r4, r5, r6, lr}
 *   @0x17246c sub sp, sp, #8
 *   @0x172470 ldr r4, [pc, #0x60]
 *   @0x172474 ldr r4, [pc, r4]
 *   @0x172478 ldr r3, [r4]
 *   @0x17247c cmp r3, #0
 *   @0x172480 beq 0x17248c <_Z15MakeDefaultFontv+0x24>
 *   @0x172484 add sp, sp, #8
 *   @0x172488 pop {r4, r5, r6, pc}
 *   @0x17248c ldr r3, [pc, #0x48]
 *   @0x172490 mov r1, #256
 *   @0x172494 mov r2, #128
 *   @0x172498 ldr r3, [pc, r3]
 *   @0x17249c ldr r0, [r3]
 *   @0x1724a0 bl 0x173bb4 <_Z14GR_Texture_AddPvii>
 *   @0x1724a4 mov r6, r0
 *   @0x1724a8 mov r0, #144
 *   @0x1724ac bl 0x27c524 <_Znwj>
 *   @0x1724b0 ldr r1, [pc, #0x28]
 *   @0x1724b4 mov r2, #32
 *   @0x1724b8 str r6, [sp]
 *   @0x1724bc mov r3, #136
 *   @0x1724c0 ldr r1, [pc, r1]
 *   @0x1724c4 mov r5, r0
 *   @0x1724c8 bl 0xf6e8c <_ZN7CFontGMC2EPhiii>
 *   @0x1724cc str r5, [r4]
 *   @0x1724d0 add sp, sp, #8
 *   @0x1724d4 pop {r4, r5, r6, pc}
 *   @0x1724d8 eoreq sp, r7, r0, lsr #28
 *   @0x1724dc eoreq sp, r7, r0, lsl #28
 *   @0x1724e0 .word 0x0027dddc
 *
 * ══ §38/251 SetFont()  0x1724e4  size 124  31 条（0x1724e4..0x172560）
 * @func 0x1724e4 0x172560  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1724ec→0x3f2410, 0x172508→0x48ffd8, 0x17251c→0x48ffd4, 0x172534→0x48ffd4
 * 调用序列: Font_Exists(int) / Font_Data(int) / MakeDefaultFont()
 * 字段偏移 top8: 0x60×2 / 0x48×1 / 0x38×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1724e4 push {r3, r4, r5, lr}
 *   @0x1724e8 ldr r4, [pc, #0x60]
 *   @0x1724ec ldr r3, [pc, #0x60]
 *   @0x1724f0 add r4, pc, r4
 *   @0x1724f4 ldr r5, [r4, r3]
 *   @0x1724f8 ldr r0, [r5]
 *   @0x1724fc bl 0xfa2a8 <_Z11Font_Existsi>
 *   @0x172500 cmp r0, #0
 *   @0x172504 bne 0x17252c <_Z7SetFontv+0x48>
 *   @0x172508 ldr r3, [pc, #0x48]
 *   @0x17250c ldr r5, [r4, r3]
 *   @0x172510 ldr r3, [r5]
 *   @0x172514 cmp r3, #0
 *   @0x172518 beq 0x172544 <_Z7SetFontv+0x60>
 *   @0x17251c ldr r2, [pc, #0x38]
 *   @0x172520 ldr r2, [r4, r2]
 *   @0x172524 str r3, [r2]
 *   @0x172528 pop {r3, r4, r5, pc}
 *   @0x17252c ldr r0, [r5]
 *   @0x172530 bl 0xfa3fc <_Z9Font_Datai>
 *   @0x172534 ldr r3, [pc, #0x20]
 *   @0x172538 ldr r3, [r4, r3]
 *   @0x17253c str r0, [r3]
 *   @0x172540 pop {r3, r4, r5, pc}
 *   @0x172544 bl 0x172468 <_Z15MakeDefaultFontv>
 *   @0x172548 ldr r3, [r5]
 *   @0x17254c b 0x17251c <_Z7SetFontv+0x38>
 *   @0x172550 eoreq pc, r7, r0, ror #14
 *   @0x172554 .word 0xffffe650
 *   @0x172558 .word 0xffffe644
 *   @0x17255c .word 0xffffe654
 *
 * ══ §39/251 GR_Texture_Init()  0x173db0  size 124  31 条（0x173db0..0x173e2c）
 * @func 0x173db0 0x173e2c  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / GR_Texture_Init()+0x50
 * 字段偏移 top8: 0x4×4 / 0x2×2 / 0x68×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x173db0 push {r4, r5, r6, lr}
 *   @0x173db4 ldr r5, [pc, #0x68]
 *   @0x173db8 ldr r5, [pc, r5]
 *   @0x173dbc ldr r0, [r5, #0x4]
 *   @0x173dc0 cmp r0, #0
 *   @0x173dc4 beq 0x173e0c <_Z15GR_Texture_Initv+0x5c>
 *   @0x173dc8 ldr r3, [r5]
 *   @0x173dcc cmp r3, #0
 *   @0x173dd0 ble 0x173e00 <_Z15GR_Texture_Initv+0x50>
 *   @0x173dd4 mov r4, #0
 *   @0x173dd8 mov r6, r4
 *   @0x173ddc ldr r0, [r0, r4, lsl #2]
 *   @0x173de0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x173de4 ldr r2, [r5, #0x4]
 *   @0x173de8 ldr r3, [r5]
 *   @0x173dec str r6, [r2, r4, lsl #2]
 *   @0x173df0 add r4, r4, #1
 *   @0x173df4 cmp r3, r4
 *   @0x173df8 ldr r0, [r5, #0x4]
 *   @0x173dfc bgt 0x173ddc <_Z15GR_Texture_Initv+0x2c>
 *   @0x173e00 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x173e04 mov r3, #0
 *   @0x173e08 str r3, [r5, #0x4]
 *   @0x173e0c ldr r3, [pc, #0x14]
 *   @0x173e10 mov r2, #0
 *   @0x173e14 str r2, [r5]
 *   @0x173e18 ldr r3, [pc, r3]
 *   @0x173e1c str r2, [r3]
 *   @0x173e20 pop {r4, r5, r6, pc}
 *   @0x173e24 eoreq r9, r7, r4, ror #22
 *   @0x173e28 mlaeq r7, r8, r4, r12
 *
 * ══ §40/251 pushRenderBufferStack()  0x18072c  size 124  31 条（0x18072c..0x1807a8）
 * @func 0x18072c 0x1807a8  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: initRenderBufferStack()
 * 字段偏移 top8: 0x68×1 / 0x58×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18072c push {r3, r4, r5, lr}
 *   @0x180730 ldr r3, [pc, #0x68]
 *   @0x180734 ldr r3, [pc, r3]
 *   @0x180738 ldrb r3, [r3]
 *   @0x18073c cmp r3, #0
 *   @0x180740 beq 0x180798 <_Z21pushRenderBufferStackv+0x6c>
 *   @0x180744 ldr r3, [pc, #0x58]
 *   @0x180748 add r3, pc, r3
 *   @0x18074c ldr r12, [r3]
 *   @0x180750 cmp r12, #99
 *   @0x180754 movgt r5, #0
 *   @0x180758 bgt 0x180790 <_Z21pushRenderBufferStackv+0x64>
 *   @0x18075c rsb r4, r12, r12, lsl #3
 *   @0x180760 add r12, r12, #1
 *   @0x180764 str r12, [r3]
 *   @0x180768 mov r5, #1
 *   @0x18076c add r4, r3, r4, lsl #2
 *   @0x180770 rsb r12, r12, r12, lsl #3
 *   @0x180774 add r4, r4, #4
 *   @0x180778 add r12, r3, r12, lsl #2
 *   @0x18077c ldm r4!, {r0, r1, r2, r3}
 *   @0x180780 add r12, r12, #4
 *   @0x180784 stm r12!, {r0, r1, r2, r3}
 *   @0x180788 ldm r4, {r0, r1, r2}
 *   @0x18078c stm r12, {r0, r1, r2}
 *   @0x180790 mov r0, r5
 *   @0x180794 pop {r3, r4, r5, pc}
 *   @0x180798 bl 0x180650 <_Z21initRenderBufferStackv>
 *   @0x18079c b 0x180744 <_Z21pushRenderBufferStackv+0x18>
 *   @0x1807a0 eoreq pc, r6, r0, lsl #28
 *   @0x1807a4 ldrhteq r1, [r2], -r4
 *
 * ══ §41/251 Shader_Add(char*, char*, char**, bool*, int, char**)  0x187b7c  size 124  31 条（0x187b7c..0x187bf8）
 * @func 0x187b7c 0x187bf8  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Shader_Setup(char*, char*, char**, bool*, int, char**) / MemoryManager::SetLength(void**, unsigned int, char const*, int)
 * 字段偏移 top8: 0x4×3 / 0x18×1 / 0x1c×1 / 0x48×1 / 0x44×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x187b7c push {r4, r5, lr}
 *   @0x187b80 sub sp, sp, #12
 *   @0x187b84 ldr lr, [sp, #0x18]
 *   @0x187b88 ldr r12, [sp, #0x1c]
 *   @0x187b8c str lr, [sp]
 *   @0x187b90 str r12, [sp, #0x4]
 *   @0x187b94 bl 0x1878d8 <_Z12Shader_SetupPcS_PS_PbiS0_>
 *   @0x187b98 subs r5, r0, #0
 *   @0x187b9c beq 0x187be8 <_Z10Shader_AddPcS_PS_PbiS0_+0x6c>
 *   @0x187ba0 ldr r4, [pc, #0x48]
 *   @0x187ba4 movw r3, #0x2a9
 *   @0x187ba8 ldr r2, [pc, #0x44]
 *   @0x187bac ldr r4, [pc, r4]
 *   @0x187bb0 add r2, pc, r2
 *   @0x187bb4 ldr r1, [r4]
 *   @0x187bb8 mov r0, r4
 *   @0x187bbc add r1, r1, #1
 *   @0x187bc0 str r1, [r0], #4
 *   @0x187bc4 lsl r1, r1, #2
 *   @0x187bc8 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x187bcc ldr r3, [r4]
 *   @0x187bd0 ldr r2, [r4, #0x4]
 *   @0x187bd4 sub r1, r3, #-1073741823
 *   @0x187bd8 sub r0, r3, #1
 *   @0x187bdc str r5, [r2, r1, lsl #2]
 *   @0x187be0 add sp, sp, #12
 *   @0x187be4 pop {r4, r5, pc}
 *   @0x187be8 mvn r0, #0
 *   @0x187bec b 0x187be0 <_Z10Shader_AddPcS_PS_PbiS0_+0x64>
 *   @0x187bf0 eoreq r8, r6, r12, lsl #20
 *   @0x187bf4 ldrsheq r4, [r12], -r8
 *
 * ══ §42/251 CreateAsynEventWithDSMap(int, int)  0x18da04  size 124  31 条（0x18da04..0x18da80）
 * @func 0x18da04 0x18da94  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int)×2 / HTTP_REQ_CONTEXT::HTTP_REQ_CONTEXT(char const*, int, int (*)(HTTP_REQ_CONTEXT*, void*, int*), void (*)(HTTP_REQ_CONTEXT*), void*, bool)
 * 字段偏移 top8: 0x8×2 / 0x4×2 / 0x38×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18da04 push {r4, r5, r6, lr}
 *   @0x18da08 mov r5, r0
 *   @0x18da0c sub sp, sp, #16
 *   @0x18da10 mov r0, #12
 *   @0x18da14 mov r6, r1
 *   @0x18da18 bl 0x27c524 <_Znwj>
 *   @0x18da1c mvn r3, #0
 *   @0x18da20 mov r4, r0
 *   @0x18da24 mov r0, #68
 *   @0x18da28 str r5, [r4]
 *   @0x18da2c str r3, [r4, #0x8]
 *   @0x18da30 str r6, [r4, #0x4]
 *   @0x18da34 bl 0x27c524 <_Znwj>
 *   @0x18da38 ldr r3, [pc, #0x38]
 *   @0x18da3c ldr r12, [pc, #0x38]
 *   @0x18da40 mov r1, #0
 *   @0x18da44 mov lr, #1
 *   @0x18da48 mov r2, r1
 *   @0x18da4c ldr r12, [pc, r12]
 *   @0x18da50 ldr r3, [pc, r3]
 *   @0x18da54 str r4, [sp, #0x4]
 *   @0x18da58 str r12, [sp]
 *   @0x18da5c str lr, [sp, #0x8]
 *   @0x18da60 mov r5, r0
 *   @0x18da64 bl 0x18d834 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b>
 *   @0x18da68 mov r3, #7
 *   @0x18da6c str r3, [r5, #0xc]
 *   @0x18da70 add sp, sp, #16
 *   @0x18da74 pop {r4, r5, r6, pc}
 *   @0x18da78 eoreq r2, r6, r12, ror #23
 *   @0x18da7c .word 0x00262bf4
 *
 * ══ §43/251 CreateAsynEventWithDSMapAndBuffer(int, int, int)  0x18da80  size 124  31 条（0x18da80..0x18dafc）
 * @func 0x18da80 0x18dafc  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int)×2 / HTTP_REQ_CONTEXT::HTTP_REQ_CONTEXT(char const*, int, int (*)(HTTP_REQ_CONTEXT*, void*, int*), void (*)(HTTP_REQ_CONTEXT*), void*, bool)
 * 字段偏移 top8: 0x8×2 / 0x4×2 / 0x38×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18da80 push {r4, r5, r6, r7, lr}
 *   @0x18da84 mov r5, r0
 *   @0x18da88 sub sp, sp, #20
 *   @0x18da8c mov r0, #12
 *   @0x18da90 mov r6, r1
 *   @0x18da94 mov r7, r2
 *   @0x18da98 bl 0x27c524 <_Znwj>
 *   @0x18da9c mov r4, r0
 *   @0x18daa0 str r5, [r0]
 *   @0x18daa4 str r6, [r4, #0x8]
 *   @0x18daa8 mov r0, #68
 *   @0x18daac str r7, [r4, #0x4]
 *   @0x18dab0 bl 0x27c524 <_Znwj>
 *   @0x18dab4 ldr r3, [pc, #0x38]
 *   @0x18dab8 ldr r12, [pc, #0x38]
 *   @0x18dabc mov r1, #0
 *   @0x18dac0 mov lr, #1
 *   @0x18dac4 mov r2, r1
 *   @0x18dac8 ldr r12, [pc, r12]
 *   @0x18dacc ldr r3, [pc, r3]
 *   @0x18dad0 str r4, [sp, #0x4]
 *   @0x18dad4 str r12, [sp]
 *   @0x18dad8 str lr, [sp, #0x8]
 *   @0x18dadc mov r5, r0
 *   @0x18dae0 bl 0x18d834 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b>
 *   @0x18dae4 mov r3, #7
 *   @0x18dae8 str r3, [r5, #0xc]
 *   @0x18daec add sp, sp, #20
 *   @0x18daf0 pop {r4, r5, r6, r7, pc}
 *   @0x18daf4 eoreq r2, r6, r0, ror r11
 *   @0x18daf8 eoreq r2, r6, r8, ror r11
 *
 * ══ §44/251 GMGamePad::Clear()  0x18e778  size 124  31 条（0x18e778..0x18e7f4）
 * @func 0x18e778 0x18e7f4  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65b0×3
 * 字段偏移 top8: 0x4×2 / 0x8×2 / 0xc×1 / 0x10×1 / 0x14×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18e778 push {r4, lr}
 *   @0x18e77c mov r4, r0
 *   @0x18e780 ldr r0, [r0, #0xc]
 *   @0x18e784 cmp r0, #0
 *   @0x18e788 beq 0x18e79c <_ZN9GMGamePad5ClearEv+0x24>
 *   @0x18e78c ldr r2, [r4, #0x4]
 *   @0x18e790 mov r1, #0
 *   @0x18e794 lsl r2, r2, #2
 *   @0x18e798 bl 0xb65b0 <memset@plt>
 *   @0x18e79c ldr r0, [r4, #0x10]
 *   @0x18e7a0 cmp r0, #0
 *   @0x18e7a4 beq 0x18e7b8 <_ZN9GMGamePad5ClearEv+0x40>
 *   @0x18e7a8 ldr r2, [r4, #0x4]
 *   @0x18e7ac mov r1, #0
 *   @0x18e7b0 lsl r2, r2, #2
 *   @0x18e7b4 bl 0xb65b0 <memset@plt>
 *   @0x18e7b8 ldr r0, [r4, #0x14]
 *   @0x18e7bc cmp r0, #0
 *   @0x18e7c0 beq 0x18e7d4 <_ZN9GMGamePad5ClearEv+0x5c>
 *   @0x18e7c4 ldr r2, [r4, #0x8]
 *   @0x18e7c8 mov r1, #0
 *   @0x18e7cc lsl r2, r2, #2
 *   @0x18e7d0 bl 0xb65b0 <memset@plt>
 *   @0x18e7d4 ldr r0, [r4, #0x18]
 *   @0x18e7d8 cmp r0, #0
 *   @0x18e7dc popeq {r4, pc}
 *   @0x18e7e0 ldr r2, [r4, #0x8]
 *   @0x18e7e4 mov r1, #0
 *   @0x18e7e8 pop {r4, lr}
 *   @0x18e7ec lsl r2, r2, #2
 *   @0x18e7f0 b 0xb65b0 <memset@plt>
 *
 * ══ §45/251 GMGamePad::ButtonDown(int) const  0x18eb5c  size 124  31 条（0x18eb5c..0x18ebd8）
 * @func 0x18eb5c 0x18ebd8  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GMGamePad::ButtonDown(int) const+0x50 / GMGamePad::GetButtonValueFromAxis(int, float*) const
 * 字段偏移 top8: 0x4×1 / 0x10×1 / 0x14×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18eb5c subs r3, r1, #0
 *   @0x18eb60 push {r4, lr}
 *   @0x18eb64 mov r4, r0
 *   @0x18eb68 blt 0x18ebac <_ZNK9GMGamePad10ButtonDownEi+0x50>
 *   @0x18eb6c ands r12, r3, #4096
 *   @0x18eb70 bne 0x18ebb4 <_ZNK9GMGamePad10ButtonDownEi+0x58>
 *   @0x18eb74 ldr r2, [r0, #0x4]
 *   @0x18eb78 cmp r3, r2
 *   @0x18eb7c bge 0x18eba4 <_ZNK9GMGamePad10ButtonDownEi+0x48>
 *   @0x18eb80 ldr r2, [r0, #0x10]
 *   @0x18eb84 vldr s15, [r0, #28]
 *   @0x18eb88 add r3, r2, r3, lsl #2
 *   @0x18eb8c vldr s14, [r3]
 *   @0x18eb90 vcmpe.f32 s14, s15
 *   @0x18eb94 vmrs APSR_nzcv, fpscr
 *   @0x18eb98 movlt r0, #0
 *   @0x18eb9c movge r0, #1
 *   @0x18eba0 pop {r4, pc}
 *   @0x18eba4 mov r0, r12
 *   @0x18eba8 pop {r4, pc}
 *   @0x18ebac mov r0, #0
 *   @0x18ebb0 pop {r4, pc}
 *   @0x18ebb4 ldr r2, [r0, #0x14]
 *   @0x18ebb8 bl 0x18eae4 <_ZNK9GMGamePad22GetButtonValueFromAxisEiPf>
 *   @0x18ebbc vldr s15, [r4, #28]
 *   @0x18ebc0 vmov s14, r0
 *   @0x18ebc4 vcmpe.f32 s14, s15
 *   @0x18ebc8 vmrs APSR_nzcv, fpscr
 *   @0x18ebcc movlt r0, #0
 *   @0x18ebd0 movge r0, #1
 *   @0x18ebd4 pop {r4, pc}
 *
 * ══ §46/251 LoadSave::SaveFileExists(char const*)  0x18fb6c  size 124  31 条（0x18fb6c..0x18fbe8）
 * @func 0x18fb6c 0x18fbe8  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LoadSave::_GetSaveFileName(char*, int, char const*) / 0xb6844 / 0xb6850 / 0xb65d4
 * 字段偏移 top8: 0x804×2 / 0x64×1 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18fb6c push {r4, r5, lr}
 *   @0x18fb70 sub sp, sp, #2048
 *   @0x18fb74 ldr r4, [pc, #0x64]
 *   @0x18fb78 sub sp, sp, #12
 *   @0x18fb7c add r5, sp, #4
 *   @0x18fb80 mov r2, r0
 *   @0x18fb84 ldr r4, [pc, r4]
 *   @0x18fb88 mov r1, #2048
 *   @0x18fb8c mov r0, r5
 *   @0x18fb90 ldr r3, [r4]
 *   @0x18fb94 str r3, [sp, #0x804]
 *   @0x18fb98 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x18fb9c ldr r1, [pc, #0x40]
 *   @0x18fba0 mov r0, r5
 *   @0x18fba4 add r1, pc, r1
 *   @0x18fba8 bl 0xb6844 <fopen@plt>
 *   @0x18fbac subs r5, r0, #0
 *   @0x18fbb0 beq 0x18fbb8 <_ZN8LoadSave14SaveFileExistsEPKc+0x4c>
 *   @0x18fbb4 bl 0xb6850 <fclose@plt>
 *   @0x18fbb8 ldr r2, [sp, #0x804]
 *   @0x18fbbc adds r0, r5, #0
 *   @0x18fbc0 ldr r3, [r4]
 *   @0x18fbc4 movne r0, #1
 *   @0x18fbc8 cmp r2, r3
 *   @0x18fbcc bne 0x18fbdc <_ZN8LoadSave14SaveFileExistsEPKc+0x70>
 *   @0x18fbd0 add sp, sp, #2048
 *   @0x18fbd4 add sp, sp, #12
 *   @0x18fbd8 pop {r4, r5, pc}
 *   @0x18fbdc bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x18fbe0 eoreq sp, r5, r12, asr #27
 *   @0x18fbe4 andseq r8, r10, r4, asr r0
 *
 * ══ §47/251 RegisterAndroidGamepadConnected(int, int, int)  0x190874  size 124  31 条（0x190874..0x1908f0）
 * @func 0x190874 0x1908f0  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GamepadInitM() / GMGamePad::SetGamePadCount(int) / operator new(unsigned int) / GMGamePad::GMGamePad(int, int)
 * 字段偏移 top8: 0x2×2 / 0x58×1 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x190874 push {r4, r5, r6, r7, r8, lr}
 *   @0x190878 mov r4, r0
 *   @0x19087c mov r6, r1
 *   @0x190880 mov r5, r2
 *   @0x190884 bl 0x190014 <_Z12GamepadInitMv>
 *   @0x190888 ldr r3, [pc, #0x58]
 *   @0x19088c ldr r3, [pc, r3]
 *   @0x190890 ldr r3, [r3]
 *   @0x190894 cmp r4, r3
 *   @0x190898 bge 0x1908bc <_Z31RegisterAndroidGamepadConnectediii+0x48>
 *   @0x19089c ldr r3, [pc, #0x48]
 *   @0x1908a0 mov r1, r6
 *   @0x1908a4 mov r2, r5
 *   @0x1908a8 ldr r3, [pc, r3]
 *   @0x1908ac ldr r3, [r3]
 *   @0x1908b0 ldr r0, [r3, r4, lsl #2]
 *   @0x1908b4 pop {r4, r5, r6, r7, r8, lr}
 *   @0x1908b8 b 0x18e69c <_ZN9GMGamePad12UpdateCountsEii>
 *   @0x1908bc add r0, r4, #1
 *   @0x1908c0 bl 0x18e4a4 <_ZN9GMGamePad15SetGamePadCountEi>
 *   @0x1908c4 mov r7, r0
 *   @0x1908c8 mov r0, #556
 *   @0x1908cc bl 0x27c524 <_Znwj>
 *   @0x1908d0 mov r1, r6
 *   @0x1908d4 mov r2, r5
 *   @0x1908d8 mov r8, r0
 *   @0x1908dc bl 0x18e9d4 <_ZN9GMGamePadC2Eii>
 *   @0x1908e0 str r8, [r7, r4, lsl #2]
 *   @0x1908e4 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1908e8 .word 0x0025f1d4
 *   @0x1908ec .word 0x0025f1bc
 *
 * ══ §48/251 CBucket<16u, 1048576u, false>::Check()  0x190c54  size 124  31 条（0x190c54..0x190cd0）
 * @func 0x190c54 0x190cd0  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBucket<16u, 1048576u, false>::Check()+0x48
 * 字段偏移 top8: 0x8×1 / 0x60×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x190c54 ldr r12, [r0, #0x8]
 *   @0x190c58 push {r4, r5, r6}
 *   @0x190c5c cmp r12, #0
 *   @0x190c60 beq 0x190cc4 <_ZN7CBucketILj16ELj1048576ELb0EE5CheckEv+0x70>
 *   @0x190c64 ldr r4, [pc, #0x60]
 *   @0x190c68 mov r6, #0
 *   @0x190c6c mov r5, #42
 *   @0x190c70 ldr r4, [pc, r4]
 *   @0x190c74 ldr r3, [r0, #0x4]
 *   @0x190c78 cmp r3, #0
 *   @0x190c7c beq 0x190ca8 <_ZN7CBucketILj16ELj1048576ELb0EE5CheckEv+0x54>
 *   @0x190c80 add r1, r3, #8
 *   @0x190c84 add r2, r3, #1048576
 *   @0x190c88 cmp r12, r1
 *   @0x190c8c add r2, r2, #8
 *   @0x190c90 blo 0x190c9c <_ZN7CBucketILj16ELj1048576ELb0EE5CheckEv+0x48>
 *   @0x190c94 cmp r2, r12
 *   @0x190c98 bhi 0x190cac <_ZN7CBucketILj16ELj1048576ELb0EE5CheckEv+0x58>
 *   @0x190c9c ldr r3, [r3]
 *   @0x190ca0 cmp r3, #0
 *   @0x190ca4 bne 0x190c80 <_ZN7CBucketILj16ELj1048576ELb0EE5CheckEv+0x2c>
 *   @0x190ca8 str r5, [r6]
 *   @0x190cac ldr r12, [r12]
 *   @0x190cb0 ldr r3, [r4]
 *   @0x190cb4 cmp r12, #0
 *   @0x190cb8 add r3, r3, #1
 *   @0x190cbc str r3, [r4]
 *   @0x190cc0 bne 0x190c74 <_ZN7CBucketILj16ELj1048576ELb0EE5CheckEv+0x20>
 *   @0x190cc4 pop {r4, r5, r6}
 *   @0x190cc8 bx lr
 *   @0x190ccc eoreq r12, r5, r4, asr pc
 *
 * ══ §49/251 Motion_Grid_GetCell(int, int, int)  0x19a478  size 124  31 条（0x19a478..0x19a4f4）
 * @func 0x19a478 0x19a4f4  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Motion_Grid_GetCell(int, int, int)+0x5c×3 / Motion_Grid_GetCell(int, int, int)+0x64
 * 字段偏移 top8: 0x2×2 / 0x64×1 / 0x54×1 / 0x14×1 / 0x18×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19a478 cmp r0, #0
 *   @0x19a47c blt 0x19a4d4 <_Z19Motion_Grid_GetCelliii+0x5c>
 *   @0x19a480 ldr r3, [pc, #0x64]
 *   @0x19a484 ldr r3, [pc, r3]
 *   @0x19a488 ldr r3, [r3]
 *   @0x19a48c cmp r0, r3
 *   @0x19a490 bge 0x19a4d4 <_Z19Motion_Grid_GetCelliii+0x5c>
 *   @0x19a494 ldr r3, [pc, #0x54]
 *   @0x19a498 ldr r3, [pc, r3]
 *   @0x19a49c ldr r3, [r3]
 *   @0x19a4a0 ldr r3, [r3, r0, lsl #2]
 *   @0x19a4a4 cmp r3, #0
 *   @0x19a4a8 beq 0x19a4d4 <_Z19Motion_Grid_GetCelliii+0x5c>
 *   @0x19a4ac cmp r1, #0
 *   @0x19a4b0 blt 0x19a4d4 <_Z19Motion_Grid_GetCelliii+0x5c>
 *   @0x19a4b4 ldr r0, [r3, #0x14]
 *   @0x19a4b8 cmp r1, r0
 *   @0x19a4bc bge 0x19a4d4 <_Z19Motion_Grid_GetCelliii+0x5c>
 *   @0x19a4c0 cmp r2, #0
 *   @0x19a4c4 blt 0x19a4d4 <_Z19Motion_Grid_GetCelliii+0x5c>
 *   @0x19a4c8 ldr r0, [r3, #0x18]
 *   @0x19a4cc cmp r2, r0
 *   @0x19a4d0 blt 0x19a4dc <_Z19Motion_Grid_GetCelliii+0x64>
 *   @0x19a4d4 mvn r0, #0
 *   @0x19a4d8 bx lr
 *   @0x19a4dc mla r1, r0, r1, r2
 *   @0x19a4e0 ldr r3, [r3, #0x1c]
 *   @0x19a4e4 ldr r0, [r3, r1, lsl #2]
 *   @0x19a4e8 bx lr
 *   @0x19a4ec eoreq r6, r5, r8, lsr #4
 *   @0x19a4f0 eoreq r6, r5, r8, lsl r2
 *
 * ══ §50/251 CObjectGM::YYCreateEvent(int, int)  0x19d60c  size 124  31 条（0x19d60c..0x19d688）
 * @func 0x19d60c 0x19d688  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CObjectGM::YYCreateEvent(int, int)+0x24 / MemoryManager::SetLength(void**, unsigned int, char const*, int) / operator new(unsigned int) / CEvent::CEvent()
 * 字段偏移 top8: 0x4c×2 / 0x50×2 / 0x2×1 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19d60c push {r4, r5, r6, r7, r8, lr}
 *   @0x19d610 add r8, r0, r1, lsl #3
 *   @0x19d614 mov r7, r2
 *   @0x19d618 ldr r4, [r8, #0x4c]
 *   @0x19d61c cmp r4, r2
 *   @0x19d620 ble 0x19d630 <_ZN9CObjectGM13YYCreateEventEii+0x24>
 *   @0x19d624 ldr r3, [r8, #0x50]
 *   @0x19d628 ldr r0, [r3, r7, lsl #2]
 *   @0x19d62c pop {r4, r5, r6, r7, r8, pc}
 *   @0x19d630 add r6, r2, #1
 *   @0x19d634 ldr r2, [pc, #0x48]
 *   @0x19d638 add r0, r0, r1, lsl #3
 *   @0x19d63c lsl r5, r4, #2
 *   @0x19d640 add r0, r0, #80
 *   @0x19d644 lsl r1, r6, #2
 *   @0x19d648 add r2, pc, r2
 *   @0x19d64c movw r3, #0x152
 *   @0x19d650 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x19d654 str r6, [r8, #0x4c]
 *   @0x19d658 mov r0, #12
 *   @0x19d65c add r4, r4, #1
 *   @0x19d660 bl 0x27c524 <_Znwj>
 *   @0x19d664 mov r6, r0
 *   @0x19d668 bl 0xf2d0c <_ZN6CEventC2Ev>
 *   @0x19d66c ldr r3, [r8, #0x50]
 *   @0x19d670 cmp r7, r4
 *   @0x19d674 str r6, [r3, r5]
 *   @0x19d678 add r5, r5, #4
 *   @0x19d67c bge 0x19d658 <_ZN9CObjectGM13YYCreateEventEii+0x4c>
 *   @0x19d680 b 0x19d624 <_ZN9CObjectGM13YYCreateEventEii+0x18>
 *   @0x19d684 mulseq r10, r8, r7
 *
 * ══ §51/251 F_VertexFormat_End(RValue&, CInstance*, CInstance*, int, RValue*)  0x1e2e1c  size 124  31 条（0x1e2e1c..0x1e2e98）
 * @func 0x1e2e1c 0x1e2e98  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: AddVertexFormat(VertexFormat*) / CreateNativeVertexFormat(VertexFormat*)
 * 字段偏移 top8: 0x60×1 / 0x3c×1 / 0xc×1 / 0x10×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e2e1c push {r3, r4, r5, lr}
 *   @0x1e2e20 mov r5, r0
 *   @0x1e2e24 ldr r4, [pc, #0x60]
 *   @0x1e2e28 ldr r4, [pc, r4]
 *   @0x1e2e2c ldr r0, [r4]
 *   @0x1e2e30 cmp r0, #0
 *   @0x1e2e34 beq 0x1e2e78 <_Z18F_VertexFormat_EndR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x1e2e38 bl 0x1e2d68 <_Z15AddVertexFormatP12VertexFormat>
 *   @0x1e2e3c str r0, [r4]
 *   @0x1e2e40 bl 0x18565c <_Z24CreateNativeVertexFormatP12VertexFormat>
 *   @0x1e2e44 ldr r3, [r4]
 *   @0x1e2e48 mov r1, #0
 *   @0x1e2e4c ldr r0, [pc, #0x3c]
 *   @0x1e2e50 str r1, [r5, #0xc]
 *   @0x1e2e54 ldr r2, [r3]
 *   @0x1e2e58 ldr r0, [pc, r0]
 *   @0x1e2e5c vmov s15, r2
 *   @0x1e2e60 vcvt.f64.s32 d7, s15
 *   @0x1e2e64 vmov r2, r3, d7
 *   @0x1e2e68 stm r5, {r2, r3}
 *   @0x1e2e6c str r1, [r0]
 *   @0x1e2e70 str r1, [r4]
 *   @0x1e2e74 pop {r3, r4, r5, pc}
 *   @0x1e2e78 mov r1, r0
 *   @0x1e2e7c ldr r0, [pc, #0x10]
 *   @0x1e2e80 pop {r3, r4, r5, lr}
 *   @0x1e2e84 add r0, pc, r0
 *   @0x1e2e88 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1e2e8c eoreq sp, r0, r8, ror #30
 *   @0x1e2e90 eoreq sp, r0, r12, lsr pc
 *   @0x1e2e94 andseq pc, r6, r12, lsr r4
 *
 * ══ §52/251 F_VertexFormat_Delete(RValue&, CInstance*, CInstance*, int, RValue*)  0x1e2f58  size 124  31 条（0x1e2f58..0x1e2fd4）
 * @func 0x1e2f58 0x1e2fd4  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::Flush() / YYGetUint32(RValue const*, int) / FreeVertexFormat(VertexFormat*)
 * 字段偏移 top8: 0x8×2 / 0x4×2 / 0x58×1 / 0x3×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e2f58 push {r4, lr}
 *   @0x1e2f5c ldr r4, [sp, #0x8]
 *   @0x1e2f60 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x1e2f64 mov r1, #0
 *   @0x1e2f68 mov r0, r4
 *   @0x1e2f6c bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x1e2f70 ldr r3, [pc, #0x58]
 *   @0x1e2f74 ldr r3, [pc, r3]
 *   @0x1e2f78 ldr r2, [r3, #0x4]
 *   @0x1e2f7c ldr r3, [r3]
 *   @0x1e2f80 and r2, r0, r2
 *   @0x1e2f84 ldr r3, [r3, r2, lsl #3]
 *   @0x1e2f88 cmp r3, #0
 *   @0x1e2f8c bne 0x1e2fa0 <_Z21F_VertexFormat_DeleteR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x1e2f90 pop {r4, pc}
 *   @0x1e2f94 ldr r3, [r3, #0x4]
 *   @0x1e2f98 cmp r3, #0
 *   @0x1e2f9c beq 0x1e2fcc <_Z21F_VertexFormat_DeleteR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x1e2fa0 ldr r2, [r3, #0x8]
 *   @0x1e2fa4 cmp r0, r2
 *   @0x1e2fa8 bne 0x1e2f94 <_Z21F_VertexFormat_DeleteR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1e2fac ldr r4, [r3, #0xc]
 *   @0x1e2fb0 cmp r4, #0
 *   @0x1e2fb4 popeq {r4, pc}
 *   @0x1e2fb8 mov r0, r4
 *   @0x1e2fbc bl 0x185640 <_Z16FreeVertexFormatP12VertexFormat>
 *   @0x1e2fc0 mov r0, r4
 *   @0x1e2fc4 pop {r4, lr}
 *   @0x1e2fc8 b 0x1e2e98 <_Z18DeleteVertexFormatP12VertexFormat>
 *   @0x1e2fcc pop {r4, pc}
 *   @0x1e2fd0 eoreq sp, r0, r8, lsr #28
 *
 * ══ §53/251 CTimeLine::MakeMomentScript(int, int)  0x1f1f9c  size 124  31 条（0x1f1f9c..0x1f2018）
 * @func 0x1f1f9c 0x1f2018  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CTimeLine::FindSmaller(double) / CTimeLine::MakeMomentScript(int, int)+0x58
 * 字段偏移 top8: 0x4×2 / 0x10×1 / 0xc×1 / 0x14×1 / 0x2×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f1f9c vmov s15, r1
 *   @0x1f1fa0 push {r4, r5, lr}
 *   @0x1f1fa4 vcvt.f64.s32 d7, s15
 *   @0x1f1fa8 sub sp, sp, #12
 *   @0x1f1fac mov r5, r2
 *   @0x1f1fb0 mov r4, r0
 *   @0x1f1fb4 str r1, [sp, #0x4]
 *   @0x1f1fb8 vmov r2, r3, d7
 *   @0x1f1fbc bl 0x1f1d04 <_ZN9CTimeLine11FindSmallerEd>
 *   @0x1f1fc0 ldr r1, [sp, #0x4]
 *   @0x1f1fc4 cmn r0, #1
 *   @0x1f1fc8 beq 0x1f2010 <_ZN9CTimeLine16MakeMomentScriptEii+0x74>
 *   @0x1f1fcc ldr r3, [r4, #0x10]
 *   @0x1f1fd0 cmp r0, r3
 *   @0x1f1fd4 lslge r3, r0, #2
 *   @0x1f1fd8 blt 0x1f1ff4 <_ZN9CTimeLine16MakeMomentScriptEii+0x58>
 *   @0x1f1fdc ldr r2, [r4, #0xc]
 *   @0x1f1fe0 lsl r5, r5, #1
 *   @0x1f1fe4 orr r5, r5, #1
 *   @0x1f1fe8 str r5, [r2, r3]
 *   @0x1f1fec add sp, sp, #12
 *   @0x1f1ff0 pop {r4, r5, pc}
 *   @0x1f1ff4 ldr r2, [r4, #0x14]
 *   @0x1f1ff8 lsl r3, r0, #2
 *   @0x1f1ffc ldr r2, [r2, r0, lsl #2]
 *   @0x1f2000 cmp r2, r1
 *   @0x1f2004 bne 0x1f1fdc <_ZN9CTimeLine16MakeMomentScriptEii+0x40>
 *   @0x1f2008 add sp, sp, #12
 *   @0x1f200c pop {r4, r5, pc}
 *   @0x1f2010 mov r3, #0
 *   @0x1f2014 b 0x1f1fdc <_ZN9CTimeLine16MakeMomentScriptEii+0x40>
 *
 * ══ §54/251 TimeLine_Find(char const*)  0x1f2bcc  size 124  31 条（0x1f2bcc..0x1f2c48）
 * @func 0x1f2bcc 0x1f2c48  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: TimeLine_Find(char const*)+0x68 / 0xb6574
 * 字段偏移 top8: 0x4×3 / 0x2×2 / 0x68×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f2bcc push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x1f2bd0 mov r6, r0
 *   @0x1f2bd4 ldr r3, [pc, #0x68]
 *   @0x1f2bd8 add r3, pc, r3
 *   @0x1f2bdc ldr r8, [r3, #0x4]
 *   @0x1f2be0 ldr r5, [r8]
 *   @0x1f2be4 cmp r5, #0
 *   @0x1f2be8 ble 0x1f2c34 <_Z13TimeLine_FindPKc+0x68>
 *   @0x1f2bec ldr r9, [r3]
 *   @0x1f2bf0 mov r4, #0
 *   @0x1f2bf4 ldr r7, [r9]
 *   @0x1f2bf8 cmp r4, r7
 *   @0x1f2bfc mov r1, r6
 *   @0x1f2c00 bge 0x1f2c28 <_Z13TimeLine_FindPKc+0x5c>
 *   @0x1f2c04 ldr r3, [r9, #0x4]
 *   @0x1f2c08 ldr r3, [r3, r4, lsl #2]
 *   @0x1f2c0c cmp r3, #0
 *   @0x1f2c10 beq 0x1f2c28 <_Z13TimeLine_FindPKc+0x5c>
 *   @0x1f2c14 ldr r3, [r8, #0x4]
 *   @0x1f2c18 ldr r0, [r3, r4, lsl #2]
 *   @0x1f2c1c bl 0xb6574 <strcmp@plt>
 *   @0x1f2c20 cmp r0, #0
 *   @0x1f2c24 beq 0x1f2c3c <_Z13TimeLine_FindPKc+0x70>
 *   @0x1f2c28 add r4, r4, #1
 *   @0x1f2c2c cmp r4, r5
 *   @0x1f2c30 bne 0x1f2bf8 <_Z13TimeLine_FindPKc+0x2c>
 *   @0x1f2c34 mvn r0, #0
 *   @0x1f2c38 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1f2c3c mov r0, r4
 *   @0x1f2c40 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1f2c44 subseq r0, r6, r4, lsl r5
 *
 * ══ §55/251 SV_Lives(CInstance*, int, RValue*)  0x1fb2c0  size 124  31 条（0x1fb2c0..0x1fb33c）
 * @func 0x1fb2c0 0x1fb350  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / SV_Lives(CInstance*, int, RValue*)+0x48 / SV_Lives(CInstance*, int, RValue*)+0x64 / REAL_RValue_Ex(RValue const*) / Perform_Event_All(int, int)
 * 字段偏移 top8: 0xc×1 / 0x68×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fb2c0 push {r3, r4, r5, lr}
 *   @0x1fb2c4 ldr r3, [r2, #0xc]
 *   @0x1fb2c8 ldr r4, [pc, #0x68]
 *   @0x1fb2cc bic r3, r3, #-16777216
 *   @0x1fb2d0 ldr r4, [pc, r4]
 *   @0x1fb2d4 cmp r3, #0
 *   @0x1fb2d8 ldr r5, [r4]
 *   @0x1fb2dc bne 0x1fb310 <_Z8SV_LivesP9CInstanceiP6RValue+0x50>
 *   @0x1fb2e0 ldr r12, [r2]
 *   @0x1fb2e4 ldr r3, [r2, #0x4]
 *   @0x1fb2e8 mov r0, r12
 *   @0x1fb2ec mov r1, r3
 *   @0x1fb2f0 bl 0xb66e8 <lrint@plt>
 *   @0x1fb2f4 cmp r5, #0
 *   @0x1fb2f8 str r0, [r4]
 *   @0x1fb2fc ble 0x1fb308 <_Z8SV_LivesP9CInstanceiP6RValue+0x48>
 *   @0x1fb300 cmp r0, #0
 *   @0x1fb304 ble 0x1fb324 <_Z8SV_LivesP9CInstanceiP6RValue+0x64>
 *   @0x1fb308 mov r0, #1
 *   @0x1fb30c pop {r3, r4, r5, pc}
 *   @0x1fb310 mov r0, r2
 *   @0x1fb314 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fb318 mov r12, r0
 *   @0x1fb31c mov r3, r1
 *   @0x1fb320 b 0x1fb2e8 <_Z8SV_LivesP9CInstanceiP6RValue+0x28>
 *   @0x1fb324 mov r0, #7
 *   @0x1fb328 mov r1, #6
 *   @0x1fb32c bl 0xf33b0 <_Z17Perform_Event_Allii>
 *   @0x1fb330 mov r0, #1
 *   @0x1fb334 pop {r3, r4, r5, pc}
 *   @0x1fb338 andseq r4, pc, r0, lsl #2
 *
 * ══ §56/251 SV_Health(CInstance*, int, RValue*)  0x1fb33c  size 124  31 条（0x1fb33c..0x1fb3b8）
 * @func 0x1fb33c 0x1fb3b8  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SV_Health(CInstance*, int, RValue*)+0x48 / SV_Health(CInstance*, int, RValue*)+0x60 / REAL_RValue_Ex(RValue const*) / Perform_Event_All(int, int)
 * 字段偏移 top8: 0xc×1 / 0x60×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fb33c ldr r3, [r2, #0xc]
 *   @0x1fb340 push {r4, lr}
 *   @0x1fb344 vpush {d8}
 *   @0x1fb348 bic r3, r3, #-16777216
 *   @0x1fb34c ldr r4, [pc, #0x60]
 *   @0x1fb350 cmp r3, #0
 *   @0x1fb354 ldr r4, [pc, r4]
 *   @0x1fb358 vldr d8, [r4]
 *   @0x1fb35c bne 0x1fb390 <_Z9SV_HealthP9CInstanceiP6RValue+0x54>
 *   @0x1fb360 ldm r2, {r0, r1}
 *   @0x1fb364 vcmpe.f64 d8, #0
 *   @0x1fb368 strd r0, r1, [r4]
 *   @0x1fb36c vmrs APSR_nzcv, fpscr
 *   @0x1fb370 ble 0x1fb384 <_Z9SV_HealthP9CInstanceiP6RValue+0x48>
 *   @0x1fb374 vmov d7, r0, r1
 *   @0x1fb378 vcmpe.f64 d7, #0
 *   @0x1fb37c vmrs APSR_nzcv, fpscr
 *   @0x1fb380 bls 0x1fb39c <_Z9SV_HealthP9CInstanceiP6RValue+0x60>
 *   @0x1fb384 vpop {d8}
 *   @0x1fb388 mov r0, #1
 *   @0x1fb38c pop {r4, pc}
 *   @0x1fb390 mov r0, r2
 *   @0x1fb394 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fb398 b 0x1fb364 <_Z9SV_HealthP9CInstanceiP6RValue+0x28>
 *   @0x1fb39c mov r0, #7
 *   @0x1fb3a0 mov r1, #9
 *   @0x1fb3a4 bl 0xf33b0 <_Z17Perform_Event_Allii>
 *   @0x1fb3a8 vpop {d8}
 *   @0x1fb3ac mov r0, #1
 *   @0x1fb3b0 pop {r4, pc}
 *   @0x1fb3b4 andseq r4, pc, r4, lsl #1
 *
 * ══ §57/251 SV_ImageAngle(CInstance*, int, RValue*)  0x1fb8c0  size 124  31 条（0x1fb8c0..0x1fb93c）
 * @func 0x1fb8c0 0x1fb93c  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CInstance::SetImageAngle(float) / REAL_RValue_Ex(RValue const*) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x6c×1 / 0xc×1 / 0x10×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fb8c0 ldr r3, [pc, #0x6c]
 *   @0x1fb8c4 push {r4, r5, r6, lr}
 *   @0x1fb8c8 ldr r3, [pc, r3]
 *   @0x1fb8cc mov r6, r0
 *   @0x1fb8d0 ldrb r1, [r3]
 *   @0x1fb8d4 cmp r1, #0
 *   @0x1fb8d8 beq 0x1fb920 <_Z13SV_ImageAngleP9CInstanceiP6RValue+0x60>
 *   @0x1fb8dc ldr r3, [r2, #0xc]
 *   @0x1fb8e0 bic r3, r3, #-16777216
 *   @0x1fb8e4 cmp r3, #0
 *   @0x1fb8e8 bne 0x1fb90c <_Z13SV_ImageAngleP9CInstanceiP6RValue+0x4c>
 *   @0x1fb8ec ldm r2, {r4, r5}
 *   @0x1fb8f0 vmov d7, r4, r5
 *   @0x1fb8f4 mov r0, r6
 *   @0x1fb8f8 vcvt.f32.f64 s15, d7
 *   @0x1fb8fc vmov r1, s15
 *   @0x1fb900 bl 0x19303c <_ZN9CInstance13SetImageAngleEf>
 *   @0x1fb904 mov r0, #1
 *   @0x1fb908 pop {r4, r5, r6, pc}
 *   @0x1fb90c mov r0, r2
 *   @0x1fb910 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fb914 mov r4, r0
 *   @0x1fb918 mov r5, r1
 *   @0x1fb91c b 0x1fb8f0 <_Z13SV_ImageAngleP9CInstanceiP6RValue+0x30>
 *   @0x1fb920 ldr r0, [pc, #0x10]
 *   @0x1fb924 add r0, pc, r0
 *   @0x1fb928 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1fb92c mov r0, #1
 *   @0x1fb930 pop {r4, r5, r6, pc}
 *   @0x1fb934 ldrsheq r5, [pc], -r4
 *   @0x1fb938 andseq r7, r5, r4, asr r0
 *
 * ══ §58/251 CDS_Priority::MarkOnlyChildren4GC(unsigned int*, int)  0x203f14  size 124  31 条（0x203f14..0x203f90）
 * @func 0x203f14 0x203f90  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RVALUE_GC_THISONLY(RValue const*, unsigned int*, int)×2 / CDS_Priority::MarkOnlyChildren4GC(unsigned int*, int)+0x44
 * 字段偏移 top8: 0x8×2 / 0x10×2 / 0xc×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x203f14 push {r3, r4, r5, r6, r7, lr}
 *   @0x203f18 mov r4, r0
 *   @0x203f1c ldr r3, [r0, #0x8]
 *   @0x203f20 mov r6, r1
 *   @0x203f24 mov r7, r2
 *   @0x203f28 cmp r3, #0
 *   @0x203f2c movgt r5, #0
 *   @0x203f30 ble 0x203f58 <_ZN12CDS_Priority19MarkOnlyChildren4GCEPji+0x44>
 *   @0x203f34 ldr r0, [r4, #0xc]
 *   @0x203f38 mov r1, r6
 *   @0x203f3c mov r2, r7
 *   @0x203f40 add r0, r0, r5, lsl #4
 *   @0x203f44 add r5, r5, #1
 *   @0x203f48 bl 0x191f5c <_Z18RVALUE_GC_THISONLYPK6RValuePji>
 *   @0x203f4c ldr r3, [r4, #0x8]
 *   @0x203f50 cmp r3, r5
 *   @0x203f54 bgt 0x203f34 <_ZN12CDS_Priority19MarkOnlyChildren4GCEPji+0x20>
 *   @0x203f58 ldr r3, [r4, #0x10]
 *   @0x203f5c cmp r3, #0
 *   @0x203f60 pople {r3, r4, r5, r6, r7, pc}
 *   @0x203f64 mov r5, #0
 *   @0x203f68 ldr r0, [r4, #0x14]
 *   @0x203f6c mov r1, r6
 *   @0x203f70 mov r2, r7
 *   @0x203f74 add r0, r0, r5, lsl #4
 *   @0x203f78 add r5, r5, #1
 *   @0x203f7c bl 0x191f5c <_Z18RVALUE_GC_THISONLYPK6RValuePji>
 *   @0x203f80 ldr r3, [r4, #0x10]
 *   @0x203f84 cmp r3, r5
 *   @0x203f88 bgt 0x203f68 <_ZN12CDS_Priority19MarkOnlyChildren4GCEPji+0x54>
 *   @0x203f8c pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §59/251 CDS_Priority::FindMin()  0x204000  size 124  31 条（0x204000..0x20407c）
 * @func 0x204000 0x204090  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CDS_Priority::FindMin()+0x70 / YYCompareVal(RValue const&, RValue const&, double)
 * 字段偏移 top8: 0x4×2 / 0x54×1 / 0x14×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x204000 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x204004 mov r8, r0
 *   @0x204008 ldr r0, [r0, #0x4]
 *   @0x20400c cmp r0, #0
 *   @0x204010 popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x204014 cmp r0, #1
 *   @0x204018 ble 0x204070 <_ZN12CDS_Priority7FindMinEv+0x70>
 *   @0x20401c ldr r9, [pc, #0x54]
 *   @0x204020 mov r4, #1
 *   @0x204024 mov r6, #0
 *   @0x204028 ldr r9, [pc, r9]
 *   @0x20402c ldr r1, [r8, #0x14]
 *   @0x204030 lsl r7, r4, #4
 *   @0x204034 lsl r5, r6, #4
 *   @0x204038 ldrd r2, r3, [r9]
 *   @0x20403c add r0, r1, r7
 *   @0x204040 add r1, r1, r5
 *   @0x204044 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d>
 *   @0x204048 ldr r3, [r8, #0x4]
 *   @0x20404c cmp r0, #0
 *   @0x204050 movlt r6, r4
 *   @0x204054 add r4, r4, #1
 *   @0x204058 movlt r5, r7
 *   @0x20405c cmp r3, r4
 *   @0x204060 bgt 0x20402c <_ZN12CDS_Priority7FindMinEv+0x2c>
 *   @0x204064 ldr r0, [r8, #0xc]
 *   @0x204068 add r0, r0, r5
 *   @0x20406c pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x204070 mov r5, #0
 *   @0x204074 b 0x204064 <_ZN12CDS_Priority7FindMinEv+0x64>
 *   @0x204078 andseq sp, lr, r12, asr r3
 *
 * ══ §60/251 CDS_Priority::FindMax()  0x20407c  size 124  31 条（0x20407c..0x2040f8）
 * @func 0x20407c 0x2040f8  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CDS_Priority::FindMax()+0x70 / YYCompareVal(RValue const&, RValue const&, double)
 * 字段偏移 top8: 0x4×2 / 0x54×1 / 0x14×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20407c push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x204080 mov r8, r0
 *   @0x204084 ldr r0, [r0, #0x4]
 *   @0x204088 cmp r0, #0
 *   @0x20408c popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x204090 cmp r0, #1
 *   @0x204094 ble 0x2040ec <_ZN12CDS_Priority7FindMaxEv+0x70>
 *   @0x204098 ldr r9, [pc, #0x54]
 *   @0x20409c mov r4, #1
 *   @0x2040a0 mov r6, #0
 *   @0x2040a4 ldr r9, [pc, r9]
 *   @0x2040a8 ldr r1, [r8, #0x14]
 *   @0x2040ac lsl r5, r4, #4
 *   @0x2040b0 lsl r7, r6, #4
 *   @0x2040b4 ldrd r2, r3, [r9]
 *   @0x2040b8 add r0, r1, r5
 *   @0x2040bc add r1, r1, r7
 *   @0x2040c0 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d>
 *   @0x2040c4 ldr r3, [r8, #0x4]
 *   @0x2040c8 cmp r0, #0
 *   @0x2040cc movgt r6, r4
 *   @0x2040d0 add r4, r4, #1
 *   @0x2040d4 movle r5, r7
 *   @0x2040d8 cmp r3, r4
 *   @0x2040dc bgt 0x2040a8 <_ZN12CDS_Priority7FindMaxEv+0x2c>
 *   @0x2040e0 ldr r0, [r8, #0xc]
 *   @0x2040e4 add r0, r0, r5
 *   @0x2040e8 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2040ec mov r5, #0
 *   @0x2040f0 b 0x2040e0 <_ZN12CDS_Priority7FindMaxEv+0x64>
 *   @0x2040f4 andseq sp, lr, r0, ror #5
 *
 * ══ §61/251 SND_AddFromMemory(CStream*, int)  0x21ea60  size 124  31 条（0x21ea60..0x21eadc）
 * @func 0x21ea60 0x21eadc  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SND_AddEmpty(int) / CStream::GetMemory() / CStream::GetSize() / SoundHardware::Load(void*, int, int)
 * 字段偏移 top8: 0x4×2 / 0x5c×1 / 0x3c×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21ea60 push {r4, r5, r6, r7, r8, lr}
 *   @0x21ea64 mov r6, r0
 *   @0x21ea68 mov r0, r1
 *   @0x21ea6c bl 0x21e7f4 <_Z12SND_AddEmptyi>
 *   @0x21ea70 ldr r3, [pc, #0x5c]
 *   @0x21ea74 ldr r3, [pc, r3]
 *   @0x21ea78 ldr r3, [r3, #0x4]
 *   @0x21ea7c add r5, r0, r0, lsl #2
 *   @0x21ea80 mov r4, r0
 *   @0x21ea84 add r5, r3, r5, lsl #2
 *   @0x21ea88 ldr r3, [r5, #0x4]
 *   @0x21ea8c cmp r3, #3
 *   @0x21ea90 beq 0x21eacc <_Z17SND_AddFromMemoryP7CStreami+0x6c>
 *   @0x21ea94 ldr r3, [pc, #0x3c]
 *   @0x21ea98 mov r0, r6
 *   @0x21ea9c add r3, pc, r3
 *   @0x21eaa0 ldr r8, [r3]
 *   @0x21eaa4 bl 0x201158 <_ZN7CStream9GetMemoryEv>
 *   @0x21eaa8 mov r7, r0
 *   @0x21eaac mov r0, r6
 *   @0x21eab0 bl 0x201168 <_ZN7CStream7GetSizeEv>
 *   @0x21eab4 mov r1, r7
 *   @0x21eab8 mov r3, r4
 *   @0x21eabc mov r2, r0
 *   @0x21eac0 mov r0, r8
 *   @0x21eac4 bl 0x22054c <_ZN13SoundHardware4LoadEPvii>
 *   @0x21eac8 str r0, [r5, #0x8]
 *   @0x21eacc mov r0, r4
 *   @0x21ead0 pop {r4, r5, r6, r7, r8, pc}
 *   @0x21ead4 andseq r2, sp, r4, lsr #19
 *   @0x21ead8 subseq r6, r3, r8, lsl #17
 *
 * ══ §62/251 SoundHardware::GetDataChunkSize(void*, int)  0x2204d0  size 124  31 条（0x2204d0..0x22054c）
 * @func 0x2204d0 0x22054c  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SoundHardware::FindDataChunk(void*, int)
 * 字段偏移 top8: 0x44×2 / 0x64×1 / 0x40×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2204d0 ldr r3, [pc, #0x64]
 *   @0x2204d4 push {r4, r5, r6, lr}
 *   @0x2204d8 ldr r3, [pc, r3]
 *   @0x2204dc mov r6, r0
 *   @0x2204e0 mov r5, r1
 *   @0x2204e4 ldrb r3, [r3]
 *   @0x2204e8 mov r4, r2
 *   @0x2204ec cmp r3, #0
 *   @0x2204f0 beq 0x220520 <_ZN13SoundHardware16GetDataChunkSizeEPvi+0x50>
 *   @0x2204f4 ldr r3, [pc, #0x44]
 *   @0x2204f8 ldr r2, [pc, #0x44]
 *   @0x2204fc ldr r3, [pc, r3]
 *   @0x220500 ldr r1, [pc, #0x40]
 *   @0x220504 add r2, pc, r2
 *   @0x220508 ldr r0, [r3]
 *   @0x22050c add r1, pc, r1
 *   @0x220510 add r2, r2, #48
 *   @0x220514 ldr r3, [r0]
 *   @0x220518 ldr r3, [r3, #0xc]
 *   @0x22051c blx r3
 *   @0x220520 mov r0, r6
 *   @0x220524 mov r1, r5
 *   @0x220528 mov r2, r4
 *   @0x22052c bl 0x2203fc <_ZN13SoundHardware13FindDataChunkEPvi>
 *   @0x220530 pop {r4, r5, r6, lr}
 *   @0x220534 add r0, r0, #4
 *   @0x220538 b 0x220164 <_Z7ReadU32Pv>
 *   @0x22053c andseq r0, sp, r0, asr pc
 *   @0x220540 andseq sp, r12, r8, lsl r2
 *   @0x220544 andseq sp, r3, r4, asr #21
 *   @0x220548 andseq r4, r3, r0, lsr r3
 *
 * ══ §63/251 COggSyncThread::Tick()  0x22510c  size 124  31 条（0x22510c..0x225188）
 * @func 0x22510c 0x225188  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: COggSyncThread::Lock() / COggSyncThread::Unlock()
 * 字段偏移 top8: 0x800×2 / 0x54×2 / 0xc×2 / 0x810×1 / 0x801×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22510c push {r3, r4, r5, lr}
 *   @0x225110 mov r4, r0
 *   @0x225114 bl 0x224c24 <_ZN14COggSyncThread4LockEv>
 *   @0x225118 ldrb r3, [r4, #0x800]
 *   @0x22511c cmp r3, #0
 *   @0x225120 beq 0x22516c <_ZN14COggSyncThread4TickEv+0x60>
 *   @0x225124 ldr r3, [pc, #0x54]
 *   @0x225128 ldr r1, [pc, #0x54]
 *   @0x22512c ldr r3, [pc, r3]
 *   @0x225130 ldr r2, [r4, #0x810]
 *   @0x225134 add r1, pc, r1
 *   @0x225138 ldr r5, [r3]
 *   @0x22513c ldr r3, [r5]
 *   @0x225140 mov r0, r5
 *   @0x225144 ldr r3, [r3, #0xc]
 *   @0x225148 blx r3
 *   @0x22514c ldr r3, [r5]
 *   @0x225150 mov r0, r5
 *   @0x225154 mov r1, r4
 *   @0x225158 ldr r3, [r3, #0xc]
 *   @0x22515c blx r3
 *   @0x225160 mov r3, #0
 *   @0x225164 strb r3, [r4]
 *   @0x225168 strb r3, [r4, #0x800]
 *   @0x22516c ldrb r5, [r4, #0x801]
 *   @0x225170 mov r0, r4
 *   @0x225174 bl 0x224c2c <_ZN14COggSyncThread6UnlockEv>
 *   @0x225178 mov r0, r5
 *   @0x22517c pop {r3, r4, r5, pc}
 *   @0x225180 andseq r8, r12, r8, ror #11
 *   @0x225184 andseq pc, r2, r8, lsl sp
 *
 * ══ §64/251 IniFile::CalcFileSize()  0x235cb0  size 124  31 条（0x235cb0..0x235d2c）
 * @func 0x235cb0 0x235d2c  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538×3
 * 字段偏移 top8: 0x8×3 / 0x4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x235cb0 push {r3, r4, r5, r6, r7, lr}
 *   @0x235cb4 ldr r7, [r0, #0x8]
 *   @0x235cb8 cmp r7, #0
 *   @0x235cbc beq 0x235d20 <_ZN7IniFile12CalcFileSizeEv+0x70>
 *   @0x235cc0 mov r5, #0
 *   @0x235cc4 ldr r0, [r7, #0x8]
 *   @0x235cc8 add r5, r5, #4
 *   @0x235ccc bl 0xb6538 <strlen@plt>
 *   @0x235cd0 ldr r4, [r7, #0x4]
 *   @0x235cd4 cmp r4, #0
 *   @0x235cd8 add r5, r5, r0
 *   @0x235cdc beq 0x235d0c <_ZN7IniFile12CalcFileSizeEv+0x5c>
 *   @0x235ce0 ldr r0, [r4, #0x4]
 *   @0x235ce4 bl 0xb6538 <strlen@plt>
 *   @0x235ce8 mov r6, r0
 *   @0x235cec ldr r0, [r4, #0x8]
 *   @0x235cf0 bl 0xb6538 <strlen@plt>
 *   @0x235cf4 ldr r4, [r4]
 *   @0x235cf8 cmp r4, #0
 *   @0x235cfc add r0, r6, r0
 *   @0x235d00 add r5, r0, r5
 *   @0x235d04 add r5, r5, #5
 *   @0x235d08 bne 0x235ce0 <_ZN7IniFile12CalcFileSizeEv+0x30>
 *   @0x235d0c ldr r7, [r7]
 *   @0x235d10 cmp r7, #0
 *   @0x235d14 bne 0x235cc4 <_ZN7IniFile12CalcFileSizeEv+0x14>
 *   @0x235d18 mov r0, r5
 *   @0x235d1c pop {r3, r4, r5, r6, r7, pc}
 *   @0x235d20 mov r5, r7
 *   @0x235d24 mov r0, r5
 *   @0x235d28 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §65/251 CPhysicsWorld::SetParticleCategoryFlags(int, unsigned int)  0x23a194  size 124  31 条（0x23a194..0x23a210）
 * @func 0x23a194 0x23a210  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2World::GetParticleFlagsBuffer() / b2World::GetParticleUserDataBuffer()
 * 字段偏移 top8: 0x10×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23a194 push {r4, r5, r6, r7, r8, lr}
 *   @0x23a198 mov r7, r0
 *   @0x23a19c ldr r0, [r0, #0x10]
 *   @0x23a1a0 movw r3, #0x9298
 *   @0x23a1a4 movt r3, #0x1
 *   @0x23a1a8 mov r5, r1
 *   @0x23a1ac mov r4, r2
 *   @0x23a1b0 ldr r8, [r0, r3]
 *   @0x23a1b4 bl 0x2cb568 <_ZN7b2World22GetParticleFlagsBufferEv>
 *   @0x23a1b8 mov r6, r0
 *   @0x23a1bc ldr r0, [r7, #0x10]
 *   @0x23a1c0 bl 0x2cb598 <_ZN7b2World25GetParticleUserDataBufferEv>
 *   @0x23a1c4 cmp r8, #0
 *   @0x23a1c8 pople {r4, r5, r6, r7, r8, pc}
 *   @0x23a1cc cmp r5, #0
 *   @0x23a1d0 beq 0x23a1f8 <_ZN13CPhysicsWorld24SetParticleCategoryFlagsEij+0x64>
 *   @0x23a1d4 lsl r1, r8, #2
 *   @0x23a1d8 mov r3, #0
 *   @0x23a1dc ldr r12, [r0, r3]
 *   @0x23a1e0 cmp r12, r5
 *   @0x23a1e4 streq r4, [r6, r3]
 *   @0x23a1e8 add r3, r3, #4
 *   @0x23a1ec cmp r3, r1
 *   @0x23a1f0 bne 0x23a1dc <_ZN13CPhysicsWorld24SetParticleCategoryFlagsEij+0x48>
 *   @0x23a1f4 pop {r4, r5, r6, r7, r8, pc}
 *   @0x23a1f8 add r3, r6, r8, lsl #2
 *   @0x23a1fc mov r0, r6
 *   @0x23a200 str r4, [r0], #4
 *   @0x23a204 cmp r0, r3
 *   @0x23a208 bne 0x23a200 <_ZN13CPhysicsWorld24SetParticleCategoryFlagsEij+0x6c>
 *   @0x23a20c pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §66/251 CPhysicsDebugRender::DrawSolidCircle(b2Vec2 const&, float, b2Vec2 const&, b2Color const&)  0x23c554  size 124  31 条（0x23c554..0x23c5d0）
 * @func 0x23c554 0x23c5d0  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsDebugRender::TranslateColour(b2Color const&) / YYGML_draw_set_colour(unsigned int)
 * 字段偏移 top8: 0x18×2 / 0x8×1
 * VFP 指令 20 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23c554 push {r4, r5, r6, lr}
 *   @0x23c558 vpush {d8}
 *   @0x23c55c mov r4, r1
 *   @0x23c560 ldr r1, [sp, #0x18]
 *   @0x23c564 vmov s16, r2
 *   @0x23c568 mov r5, r0
 *   @0x23c56c bl 0x23c338 <_ZN19CPhysicsDebugRender15TranslateColourERK7b2Color>
 *   @0x23c570 bl 0x169d98 <_Z21YYGML_draw_set_colourj>
 *   @0x23c574 vmov.f32 s12, #1.000000e+00
 *   @0x23c578 ldr r3, [r5, #0x8]
 *   @0x23c57c vldr s15, [r3, #96]
 *   @0x23c580 vldr s13, [r4]
 *   @0x23c584 vldr s14, [r4, #4]
 *   @0x23c588 mov r3, #0
 *   @0x23c58c str r3, [sp, #0x18]
 *   @0x23c590 vdiv.f32 s15, s12, s15
 *   @0x23c594 vsub.f32 s11, s13, s16
 *   @0x23c598 vsub.f32 s12, s14, s16
 *   @0x23c59c vadd.f32 s13, s13, s16
 *   @0x23c5a0 vadd.f32 s16, s16, s14
 *   @0x23c5a4 vmul.f32 s16, s16, s15
 *   @0x23c5a8 vmul.f32 s11, s11, s15
 *   @0x23c5ac vmov r3, s16
 *   @0x23c5b0 vpop {d8}
 *   @0x23c5b4 pop {r4, r5, r6, lr}
 *   @0x23c5b8 vmul.f32 s12, s12, s15
 *   @0x23c5bc vmov r0, s11
 *   @0x23c5c0 vmul.f32 s13, s13, s15
 *   @0x23c5c4 vmov r1, s12
 *   @0x23c5c8 vmov r2, s13
 *   @0x23c5cc b 0x16b278 <_Z15GR_Draw_Ellipseffffb>
 *
 * ══ §67/251 F_JS_Object_prototype_toLocaleString(RValue&, CInstance*, CInstance*, int, RValue*)  0x251220  size 124  31 条（0x251220..0x25129c）
 * @func 0x251220 0x25129c  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_GetProperty(YYObjectBase*, RValue*, char const*) / JS_IsCallable(RValue&) / Call_RValue(YYObjectBase*, RValue*, RValue*, int, RValue*) / JSThrowTypeError(char const*)
 * 字段偏移 top8: 0x60×1 / 0x14×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x251220 push {r4, r5, r6, lr}
 *   @0x251224 sub sp, sp, #24
 *   @0x251228 add r4, sp, #8
 *   @0x25122c ldr r2, [pc, #0x60]
 *   @0x251230 mov r5, r1
 *   @0x251234 mov r6, r0
 *   @0x251238 add r2, pc, r2
 *   @0x25123c mov r0, r1
 *   @0x251240 mov r1, r4
 *   @0x251244 mov r3, #5
 *   @0x251248 str r3, [sp, #0x14]
 *   @0x25124c bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc>
 *   @0x251250 mov r0, r4
 *   @0x251254 bl 0x24076c <_Z13JS_IsCallableR6RValue>
 *   @0x251258 cmp r0, #0
 *   @0x25125c beq 0x251280 <_Z36F_JS_Object_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x251260 mov r3, #0
 *   @0x251264 mov r0, r5
 *   @0x251268 mov r1, r6
 *   @0x25126c mov r2, r4
 *   @0x251270 str r3, [sp]
 *   @0x251274 bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_>
 *   @0x251278 add sp, sp, #24
 *   @0x25127c pop {r4, r5, r6, pc}
 *   @0x251280 ldr r0, [pc, #0x10]
 *   @0x251284 add r0, pc, r0
 *   @0x251288 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x25128c add sp, sp, #24
 *   @0x251290 pop {r4, r5, r6, pc}
 *   @0x251294 ldrdeq r1, r2, [lr], -r8
 *   @0x251298 andseq r4, r0, r4, asr #25
 *
 * ══ §68/251 CBucket<8u, 131072u, true>::Check()  0x27b368  size 124  31 条（0x27b368..0x27b3e4）
 * @func 0x27b368 0x27b3f8  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBucket<8u, 131072u, true>::Check()+0x48
 * 字段偏移 top8: 0x8×1 / 0x60×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27b368 ldr r12, [r0, #0x8]
 *   @0x27b36c push {r4, r5, r6}
 *   @0x27b370 cmp r12, #0
 *   @0x27b374 beq 0x27b3d8 <_ZN7CBucketILj8ELj131072ELb1EE5CheckEv+0x70>
 *   @0x27b378 ldr r4, [pc, #0x60]
 *   @0x27b37c mov r6, #0
 *   @0x27b380 mov r5, #42
 *   @0x27b384 ldr r4, [pc, r4]
 *   @0x27b388 ldr r3, [r0, #0x4]
 *   @0x27b38c cmp r3, #0
 *   @0x27b390 beq 0x27b3bc <_ZN7CBucketILj8ELj131072ELb1EE5CheckEv+0x54>
 *   @0x27b394 add r1, r3, #8
 *   @0x27b398 add r2, r3, #131072
 *   @0x27b39c cmp r12, r1
 *   @0x27b3a0 add r2, r2, #8
 *   @0x27b3a4 blo 0x27b3b0 <_ZN7CBucketILj8ELj131072ELb1EE5CheckEv+0x48>
 *   @0x27b3a8 cmp r2, r12
 *   @0x27b3ac bhi 0x27b3c0 <_ZN7CBucketILj8ELj131072ELb1EE5CheckEv+0x58>
 *   @0x27b3b0 ldr r3, [r3]
 *   @0x27b3b4 cmp r3, #0
 *   @0x27b3b8 bne 0x27b394 <_ZN7CBucketILj8ELj131072ELb1EE5CheckEv+0x2c>
 *   @0x27b3bc str r5, [r6]
 *   @0x27b3c0 ldr r12, [r12]
 *   @0x27b3c4 ldr r3, [r4]
 *   @0x27b3c8 cmp r12, #0
 *   @0x27b3cc add r3, r3, #1
 *   @0x27b3d0 str r3, [r4]
 *   @0x27b3d4 bne 0x27b388 <_ZN7CBucketILj8ELj131072ELb1EE5CheckEv+0x20>
 *   @0x27b3d8 pop {r4, r5, r6}
 *   @0x27b3dc bx lr
 *   @0x27b3e0 andseq r2, r7, r0, asr #16
 *
 * ══ §69/251 CBucket<16u, 262144u, true>::Check()  0x27b3e4  size 124  31 条（0x27b3e4..0x27b460）
 * @func 0x27b3e4 0x27b474  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBucket<16u, 262144u, true>::Check()+0x48
 * 字段偏移 top8: 0x8×1 / 0x60×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27b3e4 ldr r12, [r0, #0x8]
 *   @0x27b3e8 push {r4, r5, r6}
 *   @0x27b3ec cmp r12, #0
 *   @0x27b3f0 beq 0x27b454 <_ZN7CBucketILj16ELj262144ELb1EE5CheckEv+0x70>
 *   @0x27b3f4 ldr r4, [pc, #0x60]
 *   @0x27b3f8 mov r6, #0
 *   @0x27b3fc mov r5, #42
 *   @0x27b400 ldr r4, [pc, r4]
 *   @0x27b404 ldr r3, [r0, #0x4]
 *   @0x27b408 cmp r3, #0
 *   @0x27b40c beq 0x27b438 <_ZN7CBucketILj16ELj262144ELb1EE5CheckEv+0x54>
 *   @0x27b410 add r1, r3, #8
 *   @0x27b414 add r2, r3, #262144
 *   @0x27b418 cmp r12, r1
 *   @0x27b41c add r2, r2, #8
 *   @0x27b420 blo 0x27b42c <_ZN7CBucketILj16ELj262144ELb1EE5CheckEv+0x48>
 *   @0x27b424 cmp r2, r12
 *   @0x27b428 bhi 0x27b43c <_ZN7CBucketILj16ELj262144ELb1EE5CheckEv+0x58>
 *   @0x27b42c ldr r3, [r3]
 *   @0x27b430 cmp r3, #0
 *   @0x27b434 bne 0x27b410 <_ZN7CBucketILj16ELj262144ELb1EE5CheckEv+0x2c>
 *   @0x27b438 str r5, [r6]
 *   @0x27b43c ldr r12, [r12]
 *   @0x27b440 ldr r3, [r4]
 *   @0x27b444 cmp r12, #0
 *   @0x27b448 add r3, r3, #1
 *   @0x27b44c str r3, [r4]
 *   @0x27b450 bne 0x27b404 <_ZN7CBucketILj16ELj262144ELb1EE5CheckEv+0x20>
 *   @0x27b454 pop {r4, r5, r6}
 *   @0x27b458 bx lr
 *   @0x27b45c andseq r2, r7, r4, asr #15
 *
 * ══ §70/251 CBucket<32u, 262144u, true>::Check()  0x27b460  size 124  31 条（0x27b460..0x27b4dc）
 * @func 0x27b460 0x27b4f0  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBucket<32u, 262144u, true>::Check()+0x48
 * 字段偏移 top8: 0x8×1 / 0x60×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27b460 ldr r12, [r0, #0x8]
 *   @0x27b464 push {r4, r5, r6}
 *   @0x27b468 cmp r12, #0
 *   @0x27b46c beq 0x27b4d0 <_ZN7CBucketILj32ELj262144ELb1EE5CheckEv+0x70>
 *   @0x27b470 ldr r4, [pc, #0x60]
 *   @0x27b474 mov r6, #0
 *   @0x27b478 mov r5, #42
 *   @0x27b47c ldr r4, [pc, r4]
 *   @0x27b480 ldr r3, [r0, #0x4]
 *   @0x27b484 cmp r3, #0
 *   @0x27b488 beq 0x27b4b4 <_ZN7CBucketILj32ELj262144ELb1EE5CheckEv+0x54>
 *   @0x27b48c add r1, r3, #8
 *   @0x27b490 add r2, r3, #262144
 *   @0x27b494 cmp r12, r1
 *   @0x27b498 add r2, r2, #8
 *   @0x27b49c blo 0x27b4a8 <_ZN7CBucketILj32ELj262144ELb1EE5CheckEv+0x48>
 *   @0x27b4a0 cmp r2, r12
 *   @0x27b4a4 bhi 0x27b4b8 <_ZN7CBucketILj32ELj262144ELb1EE5CheckEv+0x58>
 *   @0x27b4a8 ldr r3, [r3]
 *   @0x27b4ac cmp r3, #0
 *   @0x27b4b0 bne 0x27b48c <_ZN7CBucketILj32ELj262144ELb1EE5CheckEv+0x2c>
 *   @0x27b4b4 str r5, [r6]
 *   @0x27b4b8 ldr r12, [r12]
 *   @0x27b4bc ldr r3, [r4]
 *   @0x27b4c0 cmp r12, #0
 *   @0x27b4c4 add r3, r3, #1
 *   @0x27b4c8 str r3, [r4]
 *   @0x27b4cc bne 0x27b480 <_ZN7CBucketILj32ELj262144ELb1EE5CheckEv+0x20>
 *   @0x27b4d0 pop {r4, r5, r6}
 *   @0x27b4d4 bx lr
 *   @0x27b4d8 andseq r2, r7, r8, asr #14
 *
 * ══ §71/251 CBucket<64u, 524288u, true>::Check()  0x27b4dc  size 124  31 条（0x27b4dc..0x27b558）
 * @func 0x27b4dc 0x27b56c  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBucket<64u, 524288u, true>::Check()+0x48
 * 字段偏移 top8: 0x8×1 / 0x60×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27b4dc ldr r12, [r0, #0x8]
 *   @0x27b4e0 push {r4, r5, r6}
 *   @0x27b4e4 cmp r12, #0
 *   @0x27b4e8 beq 0x27b54c <_ZN7CBucketILj64ELj524288ELb1EE5CheckEv+0x70>
 *   @0x27b4ec ldr r4, [pc, #0x60]
 *   @0x27b4f0 mov r6, #0
 *   @0x27b4f4 mov r5, #42
 *   @0x27b4f8 ldr r4, [pc, r4]
 *   @0x27b4fc ldr r3, [r0, #0x4]
 *   @0x27b500 cmp r3, #0
 *   @0x27b504 beq 0x27b530 <_ZN7CBucketILj64ELj524288ELb1EE5CheckEv+0x54>
 *   @0x27b508 add r1, r3, #8
 *   @0x27b50c add r2, r3, #524288
 *   @0x27b510 cmp r12, r1
 *   @0x27b514 add r2, r2, #8
 *   @0x27b518 blo 0x27b524 <_ZN7CBucketILj64ELj524288ELb1EE5CheckEv+0x48>
 *   @0x27b51c cmp r2, r12
 *   @0x27b520 bhi 0x27b534 <_ZN7CBucketILj64ELj524288ELb1EE5CheckEv+0x58>
 *   @0x27b524 ldr r3, [r3]
 *   @0x27b528 cmp r3, #0
 *   @0x27b52c bne 0x27b508 <_ZN7CBucketILj64ELj524288ELb1EE5CheckEv+0x2c>
 *   @0x27b530 str r5, [r6]
 *   @0x27b534 ldr r12, [r12]
 *   @0x27b538 ldr r3, [r4]
 *   @0x27b53c cmp r12, #0
 *   @0x27b540 add r3, r3, #1
 *   @0x27b544 str r3, [r4]
 *   @0x27b548 bne 0x27b4fc <_ZN7CBucketILj64ELj524288ELb1EE5CheckEv+0x20>
 *   @0x27b54c pop {r4, r5, r6}
 *   @0x27b550 bx lr
 *   @0x27b554 andseq r2, r7, r12, asr #13
 *
 * ══ §72/251 CBucket<128u, 524288u, true>::Check()  0x27b558  size 124  31 条（0x27b558..0x27b5d4）
 * @func 0x27b558 0x27b5e8  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBucket<128u, 524288u, true>::Check()+0x48
 * 字段偏移 top8: 0x8×1 / 0x60×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27b558 ldr r12, [r0, #0x8]
 *   @0x27b55c push {r4, r5, r6}
 *   @0x27b560 cmp r12, #0
 *   @0x27b564 beq 0x27b5c8 <_ZN7CBucketILj128ELj524288ELb1EE5CheckEv+0x70>
 *   @0x27b568 ldr r4, [pc, #0x60]
 *   @0x27b56c mov r6, #0
 *   @0x27b570 mov r5, #42
 *   @0x27b574 ldr r4, [pc, r4]
 *   @0x27b578 ldr r3, [r0, #0x4]
 *   @0x27b57c cmp r3, #0
 *   @0x27b580 beq 0x27b5ac <_ZN7CBucketILj128ELj524288ELb1EE5CheckEv+0x54>
 *   @0x27b584 add r1, r3, #8
 *   @0x27b588 add r2, r3, #524288
 *   @0x27b58c cmp r12, r1
 *   @0x27b590 add r2, r2, #8
 *   @0x27b594 blo 0x27b5a0 <_ZN7CBucketILj128ELj524288ELb1EE5CheckEv+0x48>
 *   @0x27b598 cmp r2, r12
 *   @0x27b59c bhi 0x27b5b0 <_ZN7CBucketILj128ELj524288ELb1EE5CheckEv+0x58>
 *   @0x27b5a0 ldr r3, [r3]
 *   @0x27b5a4 cmp r3, #0
 *   @0x27b5a8 bne 0x27b584 <_ZN7CBucketILj128ELj524288ELb1EE5CheckEv+0x2c>
 *   @0x27b5ac str r5, [r6]
 *   @0x27b5b0 ldr r12, [r12]
 *   @0x27b5b4 ldr r3, [r4]
 *   @0x27b5b8 cmp r12, #0
 *   @0x27b5bc add r3, r3, #1
 *   @0x27b5c0 str r3, [r4]
 *   @0x27b5c4 bne 0x27b578 <_ZN7CBucketILj128ELj524288ELb1EE5CheckEv+0x20>
 *   @0x27b5c8 pop {r4, r5, r6}
 *   @0x27b5cc bx lr
 *   @0x27b5d0 andseq r2, r7, r0, asr r6
 *
 * ══ §73/251 CBucket<256u, 1048576u, true>::Check()  0x27b5d4  size 124  31 条（0x27b5d4..0x27b650）
 * @func 0x27b5d4 0x27b650  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBucket<256u, 1048576u, true>::Check()+0x48
 * 字段偏移 top8: 0x8×1 / 0x60×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27b5d4 ldr r12, [r0, #0x8]
 *   @0x27b5d8 push {r4, r5, r6}
 *   @0x27b5dc cmp r12, #0
 *   @0x27b5e0 beq 0x27b644 <_ZN7CBucketILj256ELj1048576ELb1EE5CheckEv+0x70>
 *   @0x27b5e4 ldr r4, [pc, #0x60]
 *   @0x27b5e8 mov r6, #0
 *   @0x27b5ec mov r5, #42
 *   @0x27b5f0 ldr r4, [pc, r4]
 *   @0x27b5f4 ldr r3, [r0, #0x4]
 *   @0x27b5f8 cmp r3, #0
 *   @0x27b5fc beq 0x27b628 <_ZN7CBucketILj256ELj1048576ELb1EE5CheckEv+0x54>
 *   @0x27b600 add r1, r3, #8
 *   @0x27b604 add r2, r3, #1048576
 *   @0x27b608 cmp r12, r1
 *   @0x27b60c add r2, r2, #8
 *   @0x27b610 blo 0x27b61c <_ZN7CBucketILj256ELj1048576ELb1EE5CheckEv+0x48>
 *   @0x27b614 cmp r2, r12
 *   @0x27b618 bhi 0x27b62c <_ZN7CBucketILj256ELj1048576ELb1EE5CheckEv+0x58>
 *   @0x27b61c ldr r3, [r3]
 *   @0x27b620 cmp r3, #0
 *   @0x27b624 bne 0x27b600 <_ZN7CBucketILj256ELj1048576ELb1EE5CheckEv+0x2c>
 *   @0x27b628 str r5, [r6]
 *   @0x27b62c ldr r12, [r12]
 *   @0x27b630 ldr r3, [r4]
 *   @0x27b634 cmp r12, #0
 *   @0x27b638 add r3, r3, #1
 *   @0x27b63c str r3, [r4]
 *   @0x27b640 bne 0x27b5f4 <_ZN7CBucketILj256ELj1048576ELb1EE5CheckEv+0x20>
 *   @0x27b644 pop {r4, r5, r6}
 *   @0x27b648 bx lr
 *   @0x27b64c ldrsbeq r2, [r7], -r4
 *
 * ══ §74/251 CBucket<16384u, 262144u, true>::Check()  0x27b6dc  size 124  31 条（0x27b6dc..0x27b758）
 * @func 0x27b6dc 0x27b758  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBucket<16384u, 262144u, true>::Check()+0x48
 * 字段偏移 top8: 0x8×1 / 0x60×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27b6dc ldr r12, [r0, #0x8]
 *   @0x27b6e0 push {r4, r5, r6}
 *   @0x27b6e4 cmp r12, #0
 *   @0x27b6e8 beq 0x27b74c <_ZN7CBucketILj16384ELj262144ELb1EE5CheckEv+0x70>
 *   @0x27b6ec ldr r4, [pc, #0x60]
 *   @0x27b6f0 mov r6, #0
 *   @0x27b6f4 mov r5, #42
 *   @0x27b6f8 ldr r4, [pc, r4]
 *   @0x27b6fc ldr r3, [r0, #0x4]
 *   @0x27b700 cmp r3, #0
 *   @0x27b704 beq 0x27b730 <_ZN7CBucketILj16384ELj262144ELb1EE5CheckEv+0x54>
 *   @0x27b708 add r1, r3, #8
 *   @0x27b70c add r2, r3, #262144
 *   @0x27b710 cmp r12, r1
 *   @0x27b714 add r2, r2, #8
 *   @0x27b718 blo 0x27b724 <_ZN7CBucketILj16384ELj262144ELb1EE5CheckEv+0x48>
 *   @0x27b71c cmp r2, r12
 *   @0x27b720 bhi 0x27b734 <_ZN7CBucketILj16384ELj262144ELb1EE5CheckEv+0x58>
 *   @0x27b724 ldr r3, [r3]
 *   @0x27b728 cmp r3, #0
 *   @0x27b72c bne 0x27b708 <_ZN7CBucketILj16384ELj262144ELb1EE5CheckEv+0x2c>
 *   @0x27b730 str r5, [r6]
 *   @0x27b734 ldr r12, [r12]
 *   @0x27b738 ldr r3, [r4]
 *   @0x27b73c cmp r12, #0
 *   @0x27b740 add r3, r3, #1
 *   @0x27b744 str r3, [r4]
 *   @0x27b748 bne 0x27b6fc <_ZN7CBucketILj16384ELj262144ELb1EE5CheckEv+0x20>
 *   @0x27b74c pop {r4, r5, r6}
 *   @0x27b750 bx lr
 *   @0x27b754 andseq r2, r7, r12, asr #9
 *
 * ══ §75/251 spDrawOrderTimeline_setFrame  0x282ddc  size 124  31 条（0x282ddc..0x282e58）
 * @func 0x282ddc 0x282e58  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _free / _malloc
 * 字段偏移 top8: 0x10×4 / 0x2×4 / 0x14×2 / 0xc×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x282ddc push {r3, r4, r5, r6, r7, lr}
 *   @0x282de0 mov r5, r1
 *   @0x282de4 ldr r1, [r0, #0xc]
 *   @0x282de8 mov r4, r0
 *   @0x282dec ldr r0, [r0, #0x10]
 *   @0x282df0 mov r6, r3
 *   @0x282df4 add r3, r1, r5, lsl #2
 *   @0x282df8 ldr r0, [r0, r5, lsl #2]
 *   @0x282dfc str r2, [r3]
 *   @0x282e00 bl 0x285c80 <_free>
 *   @0x282e04 cmp r6, #0
 *   @0x282e08 beq 0x282e48 <spDrawOrderTimeline_setFrame+0x6c>
 *   @0x282e0c ldr r0, [r4, #0x14]
 *   @0x282e10 movw r2, #0x2b2
 *   @0x282e14 ldr r1, [pc, #0x38]
 *   @0x282e18 ldr r7, [r4, #0x10]
 *   @0x282e1c add r1, pc, r1
 *   @0x282e20 lsl r0, r0, #2
 *   @0x282e24 bl 0x285c10 <_malloc>
 *   @0x282e28 ldr r2, [r4, #0x14]
 *   @0x282e2c mov r1, r6
 *   @0x282e30 lsl r2, r2, #2
 *   @0x282e34 str r0, [r7, r5, lsl #2]
 *   @0x282e38 ldr r3, [r4, #0x10]
 *   @0x282e3c ldr r0, [r3, r5, lsl #2]
 *   @0x282e40 pop {r3, r4, r5, r6, r7, lr}
 *   @0x282e44 b 0xb65bc <memcpy@plt>
 *   @0x282e48 ldr r3, [r4, #0x10]
 *   @0x282e4c str r6, [r3, r5, lsl #2]
 *   @0x282e50 pop {r3, r4, r5, r6, r7, pc}
 *   @0x282e54 andeq r4, sp, r4, lsr r6
 *
 * ══ §76/251 spDeformTimeline_setFrame  0x282ef8  size 124  31 条（0x282ef8..0x282f74）
 * @func 0x282ef8 0x282f74  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _free / _malloc
 * 字段偏移 top8: 0x18×4 / 0x2×4 / 0x14×2 / 0x10×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x282ef8 push {r3, r4, r5, r6, r7, lr}
 *   @0x282efc mov r5, r1
 *   @0x282f00 ldr r1, [r0, #0x10]
 *   @0x282f04 mov r4, r0
 *   @0x282f08 ldr r0, [r0, #0x18]
 *   @0x282f0c mov r6, r3
 *   @0x282f10 add r3, r1, r5, lsl #2
 *   @0x282f14 ldr r0, [r0, r5, lsl #2]
 *   @0x282f18 str r2, [r3]
 *   @0x282f1c bl 0x285c80 <_free>
 *   @0x282f20 cmp r6, #0
 *   @0x282f24 beq 0x282f64 <spDeformTimeline_setFrame+0x6c>
 *   @0x282f28 ldr r0, [r4, #0x14]
 *   @0x282f2c movw r2, #0x31f
 *   @0x282f30 ldr r1, [pc, #0x38]
 *   @0x282f34 ldr r7, [r4, #0x18]
 *   @0x282f38 add r1, pc, r1
 *   @0x282f3c lsl r0, r0, #2
 *   @0x282f40 bl 0x285c10 <_malloc>
 *   @0x282f44 ldr r2, [r4, #0x14]
 *   @0x282f48 mov r1, r6
 *   @0x282f4c lsl r2, r2, #2
 *   @0x282f50 str r0, [r7, r5, lsl #2]
 *   @0x282f54 ldr r3, [r4, #0x18]
 *   @0x282f58 ldr r0, [r3, r5, lsl #2]
 *   @0x282f5c pop {r3, r4, r5, r6, r7, lr}
 *   @0x282f60 b 0xb65bc <memcpy@plt>
 *   @0x282f64 ldr r3, [r4, #0x18]
 *   @0x282f68 str r6, [r3, r5, lsl #2]
 *   @0x282f6c pop {r3, r4, r5, r6, r7, pc}
 *   @0x282f70 andeq r4, sp, r8, lsl r5
 *
 * ══ §77/251 spSlotData_create  0x28ef2c  size 124  31 条（0x28ef2c..0x28efa8）
 * @func 0x28ef2c 0x28efa8  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _calloc / 0xb6538 / _malloc / 0xb65a4
 * 字段偏移 top8: 0x68×1 / 0x4×1 / 0x8×1 / 0x10×1 / 0x14×1 / 0x18×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28ef2c push {r4, r5, r6, r7, r8, lr}
 *   @0x28ef30 mov r5, r1
 *   @0x28ef34 ldr r6, [pc, #0x68]
 *   @0x28ef38 mov r1, #36
 *   @0x28ef3c mov r3, r1
 *   @0x28ef40 mov r8, r0
 *   @0x28ef44 add r6, pc, r6
 *   @0x28ef48 mov r7, r2
 *   @0x28ef4c mov r0, #1
 *   @0x28ef50 mov r2, r6
 *   @0x28ef54 bl 0x285c4c <_calloc>
 *   @0x28ef58 mov r4, r0
 *   @0x28ef5c str r8, [r0]
 *   @0x28ef60 mov r0, r5
 *   @0x28ef64 bl 0xb6538 <strlen@plt>
 *   @0x28ef68 mov r1, r6
 *   @0x28ef6c mov r2, #38
 *   @0x28ef70 add r0, r0, #1
 *   @0x28ef74 bl 0x285c10 <_malloc>
 *   @0x28ef78 mov r1, r5
 *   @0x28ef7c str r0, [r4, #0x4]
 *   @0x28ef80 bl 0xb65a4 <strcpy@plt>
 *   @0x28ef84 mov r3, #1065353216
 *   @0x28ef88 str r7, [r4, #0x8]
 *   @0x28ef8c mov r0, r4
 *   @0x28ef90 str r3, [r4, #0x10]
 *   @0x28ef94 str r3, [r4, #0x14]
 *   @0x28ef98 str r3, [r4, #0x18]
 *   @0x28ef9c str r3, [r4, #0x1c]
 *   @0x28efa0 pop {r4, r5, r6, r7, r8, pc}
 *   @0x28efa4 andeq r9, r12, r12, lsr #1
 *
 * ══ §78/251 yySocket::Bind(sockaddr const*, int)  0x2951c4  size 124  31 条（0x2951c4..0x295240）
 * @func 0x2951c4 0x295240  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6dcc / yySocket::Bind(sockaddr const*, int)+0x28 / 0xb6bf8
 * 字段偏移 top8: 0x44×1 / 0xc×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2951c4 push {r4, r5, r6, r7, lr}
 *   @0x2951c8 mov r5, r0
 *   @0x2951cc sub sp, sp, #12
 *   @0x2951d0 ldr r0, [r0]
 *   @0x2951d4 bl 0xb6dcc <bind@plt>
 *   @0x2951d8 subs r4, r0, #0
 *   @0x2951dc blt 0x2951ec <_ZN8yySocket4BindEPK8sockaddri+0x28>
 *   @0x2951e0 mov r0, r4
 *   @0x2951e4 add sp, sp, #12
 *   @0x2951e8 pop {r4, r5, r6, r7, pc}
 *   @0x2951ec ldr r3, [pc, #0x44]
 *   @0x2951f0 ldr r7, [r5]
 *   @0x2951f4 ldr r3, [pc, r3]
 *   @0x2951f8 ldr r5, [r3]
 *   @0x2951fc ldr r3, [r5]
 *   @0x295200 ldr r6, [r3, #0xc]
 *   @0x295204 bl 0xb6bf8 <__errno@plt>
 *   @0x295208 ldr r1, [pc, #0x2c]
 *   @0x29520c mov r2, r7
 *   @0x295210 add r1, pc, r1
 *   @0x295214 mov r3, r0
 *   @0x295218 mov r0, r5
 *   @0x29521c ldr r12, [r3]
 *   @0x295220 mov r3, r4
 *   @0x295224 str r12, [sp]
 *   @0x295228 blx r6
 *   @0x29522c mov r0, r4
 *   @0x295230 add sp, sp, #12
 *   @0x295234 pop {r4, r5, r6, r7, pc}
 *   @0x295238 andseq r8, r5, r0, lsr #10
 *   @0x29523c andeq r4, r12, r4, lsl r0
 *
 * ══ §79/251 png_set_gAMA_fixed  0x2ae988  size 124  31 条（0x2ae988..0x2aea04）
 * @func 0x2ae988 0x2aea04  size 124  31 条
 * 部分覆盖: 本节 31/50 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_warning×2
 * 字段偏移 top8: 0x58×1 / 0x8×1 / 0x20×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ae988 push {r4, r5, r6, lr}
 *   @0x2ae98c mov r4, r2
 *   @0x2ae990 cbz r0, 0x2ae9e8 <png_set_gAMA_fixed+0x60>
 *   @0x2ae994 mvn r3, #0x80000000
 *   @0x2ae998 cmp r2, r3
 *   @0x2ae99c ldr r1, [pc, #0x58]
 *   @0x2ae9a0 bl 0x2a6474 <png_warning>
 *   @0x2ae9a4 b 0x2ae9b4 <png_set_gAMA_fixed+0x2c>
 *   @0x2ae9a8 bge 0x2ae9b4 <png_set_gAMA_fixed+0x2c>
 *   @0x2ae9ac movs r4, #0x0
 *   @0x2ae9b0 bl 0x2a6474 <png_warning>
 *   @0x2ae9b4 vmov s15, r4
 *   @0x2ae9b8 ldr r3, [r5, #0x8]
 *   @0x2ae9bc mrc p0, #0x5, r4, c8, c12, #0x7
 *   @0x2ae9c0 vldr d6, [pc, #924]
 *   @0x2ae9c4 .word 0xf0437b0b
 *   @0x2ae9c8 adcvs r0, r11, r1, lsl #6
 *   @0x2ae9cc vdiv.f64 d7, d6, d7
 *   @0x2ae9d0 vcvt.f32.f64 s14, d7
 *   @0x2ae9d4 vstr s14, [r5, #40]
 *   @0x2ae9d8 cbnz r4, 0x2ae9e8 <png_set_gAMA_fixed+0x60>
 *   @0x2ae9dc mov r0, r6
 *   @0x2ae9e0 ldrbtmi r4, [r9], #-112
 *   @0x2ae9e4 b.w 0x2a6474 <png_warning>
 *   @0x2ae9e8 pop {r4, r5, r6, pc}
 *   @0x2ae9ec nop.w
 *   @0x2ae9f0 movs r0, r0
 *   @0x2ae9f4 ldr r0, [r0, #0x20]
 *   @0x2ae9f8 .word 0xf0d8 000d
 *   @0x2ae9fc .word 0xf0f3 000d
 *   @0x2aea00 .word 0xf0af 000d
 *
 * ══ §80/251 png_set_hIST  0x2aea08  size 124  31 条（0x2aea08..0x2aea84）
 * @func 0x2aea08 0x2aea84  size 124  31 条
 * 部分覆盖: 本节 31/55 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_set_hIST+0x1c / png_free_data
 * 字段偏移 top8: 0x8×2 / 0x14×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2aea08 push {r4, r5, r6, lr}
 *   @0x2aea0c mov r6, r2
 *   @0x2aea10 cbz r0, 0x2aea7a <png_set_hIST+0x72>
 *   @0x2aea14 ldrh r3, [r1, #0x14]
 *   @0x2aea18 uxth r3, r3
 *   @0x2aea1c bls 0x2aea24 <png_set_hIST+0x1c>
 *   @0x2aea20 add r1, pc
 *   @0x2aea24 movs r2, #0x8
 *   @0x2aea28 bl 0x2a5bc0 <png_free_data>
 *   @0x2aea2c mov r0, r5
 *   @0x2aea30 .word 0xf7f87100
 *   @0x2aea34 .word 0xf8c5f970
 *   @0x2aea38 strhlt r0, [r8, -r8]
 *   @0x2aea3c movs r3, #0x0
 *   @0x2aea40 ldr r1, [pc, #0x3c]
 *   @0x2aea44 add r1, pc
 *   @0x2aea48 .word 0xf7f74070
 *   @0x2aea4c bhi 0xfeb5dea0 <b2_toiTime+0xfffffffffe4049fc>
 *   @0x2aea50 ldr.w r1, [r5, #0x2b8]
 *   @0x2aea54 cmp r3, r2
 *   @0x2aea58 ldrh.w r2, [r6, r3, lsl #1]
 *   @0x2aea5c strh.w r2, [r1, r3, lsl #1]
 *   @0x2aea60 adds r3, #0x1
 *   @0x2aea64 ldr r3, [r4, #0x8]
 *   @0x2aea68 orr r3, r3, #0x40
 *   @0x2aea6c str r3, [r4, #0x8]
 *   @0x2aea70 .word 0xf04330b8
 *   @0x2aea74 .word 0xf8c40308
 *   @0x2aea78 ldcllt p0, c3, [r0, #-736]!
 *   @0x2aea7c .word 0xf0a0 000d
 *   @0x2aea80 .word 0xf0aa 000d
 *
 * ══ §81/251 b2FrictionJointDef::Initialize(b2Body*, b2Body*, b2Vec2 const&)  0x2cd998  size 124  31 条（0x2cd998..0x2cda14）
 * @func 0x2cd998 0x2cda14  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 28 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cd998 vldr s15, [r1, #16]
 *   @0x2cd99c vldr s14, [r3, #4]
 *   @0x2cd9a0 vsub.f32 s14, s14, s15
 *   @0x2cd9a4 vldr s9, [r1, #20]
 *   @0x2cd9a8 vldr s8, [r1, #24]
 *   @0x2cd9ac vldr s6, [r3]
 *   @0x2cd9b0 vldr s10, [r1, #12]
 *   @0x2cd9b4 vldr s12, [r2, #20]
 *   @0x2cd9b8 vldr s11, [r2, #24]
 *   @0x2cd9bc vldr s15, [r2, #16]
 *   @0x2cd9c0 vldr s7, [r2, #12]
 *   @0x2cd9c4 str r1, [r0, #0x8]
 *   @0x2cd9c8 str r2, [r0, #0xc]
 *   @0x2cd9cc vmul.f32 s13, s14, s9
 *   @0x2cd9d0 vmul.f32 s14, s14, s8
 *   @0x2cd9d4 vsub.f32 s10, s6, s10
 *   @0x2cd9d8 vmla.f32 s13, s10, s8
 *   @0x2cd9dc vmls.f32 s14, s9, s10
 *   @0x2cd9e0 vstr s13, [r0, #20]
 *   @0x2cd9e4 vstr s14, [r0, #24]
 *   @0x2cd9e8 vldr s14, [r3, #4]
 *   @0x2cd9ec vsub.f32 s15, s14, s15
 *   @0x2cd9f0 vldr s13, [r3]
 *   @0x2cd9f4 vmul.f32 s14, s15, s12
 *   @0x2cd9f8 vmul.f32 s15, s15, s11
 *   @0x2cd9fc vsub.f32 s13, s13, s7
 *   @0x2cda00 vmla.f32 s14, s13, s11
 *   @0x2cda04 vmls.f32 s15, s12, s13
 *   @0x2cda08 vstr s14, [r0, #28]
 *   @0x2cda0c vstr s15, [r0, #32]
 *   @0x2cda10 bx lr
 *
 * ══ §82/251 anon_2e8b5c  0x2e8b5c  size 124  31 条（0x2e8b5c..0x2e8bd8）
 * @func 0x2e8b5c 0x2e8bd8  size 124  31 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xbe8ac0
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e8b5c mvnsmi lr, sp, lsr #18
 *   @0x2e8b60 svcvs #0x8b4605
 *   @0x2e8b64 ldrmi r4, [r7], -r12, lsl #12
 *   @0x2e8b68 .word 0x800cf8d2
 *   @0x2e8b6c svcvs #0x48b10b
 *   @0x2e8b70 stclvs p7, c4, [r6, #-608]!
 *   @0x2e8b74 shadd16mi r11, r0, lr
 *   @0x2e8b78 .word 0xffcff7fe
 *   @0x2e8b7c ldmdbmi r6, {r0, r3, r4, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x2e8b80 .word 0xf104463b
 *   @0x2e8b84 strtmi r0, [r10], -r12, rrx
 *   @0x2e8b88 .word 0xf7ff4479
 *   @0x2e8b8c blvs 0xbe8ac0 <b2_toiTime+0x48f61c>
 *   @0x2e8b90 smlatblt r11, r6, r5, r6
 *   @0x2e8b94 ldrmi r4, [r8, r0, lsr #12]
 *   @0x2e8b98 strtmi r4, [r9], -r0, lsr #12
 *   @0x2e8b9c .word 0xffecf7fe
 *   @0x2e8ba0 ldrsbtlo pc, [r4], -r8
 *   @0x2e8ba4 strtmi r11, [r0], -r11, lsl #2
 *   @0x2e8ba8 stmvs r1!, {r3, r4, r7, r8, r9, r10, lr}
 *   @0x2e8bac cdpvs p6, #0xa, c2, c0, c0, #0x0
 *   @0x2e8bb0 orrhs pc, r0, r1, asr #7
 *   @0x2e8bb4 mrrc2 p7, #0xf, pc, r3, c14
 *   @0x2e8bb8 .word 0x1080f8d4
 *   @0x2e8bbc smulwblt r1, r6, r6
 *   @0x2e8bc0 .word 0xf7fe4628
 *   @0x2e8bc4 .word 0xf8c4fbb8
 *   @0x2e8bc8 strtmi r6, [r8], -r0, lsl #1
 *   @0x2e8bcc pop {r0, r5, r9, r10, lr}
 *   @0x2e8bd0 .word 0xf7fe41f0
 *   @0x2e8bd4 svclt #0xbbb0
 *
 * ══ §83/251 png_get_cHRM_fixed  0x2a67de  size 122  31 条（0x2a67de..0x2a6858）
 * @func 0x2a67de 0x2a685a  size 124  31 条
 * 部分覆盖: 本节 31/57 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x49684e
 * 字段偏移 top8: 0x20×1 / 0x28×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a67de push.w {r4, r5, r6, r7, r8, lr}
 *   @0x2a67e2 mov r8, r3
 *   @0x2a67e6 blls 0x49684e <g_prim_v+0x6842>
 *   @0x2a67ea ldr r7, [sp, #0x20]
 *   @0x2a67ee ldr r5, [sp, #0x28]
 *   @0x2a67f2 cbz r0, 0x2a6854 <png_get_cHRM_fixed+0x76>
 *   @0x2a67f6 ldr r0, [r1, #0x8]
 *   @0x2a67fa eorle r0, r10, r4
 *   @0x2a67fe cbz r2, 0x2a6806 <png_get_cHRM_fixed+0x28>
 *   @0x2a6802 andsvs r0, r0, r0, lsl #2
 *   @0x2a6806 cmp.w r8, #0x0
 *   @0x2a680a beq 0x2a6814 <png_get_cHRM_fixed+0x36>
 *   @0x2a680e .word 0xf8c82104
 *   @0x2a6812 .word 0xf1bc2000
 *   @0x2a6816 andle r0, r3, r0, lsl #30
 *   @0x2a681a ldr.w r2, [r1, #0x108]
 *   @0x2a681e str.w r2, [r12]
 *   @0x2a6822 cbz r3, 0x2a682a <png_get_cHRM_fixed+0x4c>
 *   @0x2a6826 andsvs r2, r10, r12, lsl #2
 *   @0x2a682a cbz r7, 0x2a6832 <png_get_cHRM_fixed+0x54>
 *   @0x2a682e eorsvs r3, r11, r0, lsl r1
 *   @0x2a6832 cbz r6, 0x2a683a <png_get_cHRM_fixed+0x5c>
 *   @0x2a6836 eorsvs r3, r3, r4, lsl r1
 *   @0x2a683a cbz r5, 0x2a6842 <png_get_cHRM_fixed+0x64>
 *   @0x2a683e eorvs r3, r11, r8, lsl r1
 *   @0x2a6842 cbz r4, 0x2a6852 <png_get_cHRM_fixed+0x74>
 *   @0x2a6846 eorvs r3, r3, r12, lsl r1
 *   @0x2a684a b 0x2a6852 <png_get_cHRM_fixed+0x74>
 *   @0x2a684e pop.w {r4, r5, r6, r7, r8, pc}
 *   @0x2a6852 movs r0, #0x4
 *   @0x2a6856 strdlt r8, r9, [r0, r0]
 *
 * ══ §84/251 FT_Get_Advance  0x2e7950  size 122  31 条（0x2e7950..0x2e79ca）
 * @func 0x2e7950 0x2e79cc  size 124  31 条
 * 部分覆盖: 本节 31/56 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FT_Get_Advances / 0x3385a0
 * 字段偏移 top8: 0x60×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e7950 push {r0, r1, r2, r4, r5, r6, r7, lr}
 *   @0x2e7954 mov r5, r2
 *   @0x2e7958 mov r4, r0
 *   @0x2e795c beq 0x2e79bc <FT_Get_Advance+0x6c>
 *   @0x2e7960 beq 0x2e79c0 <FT_Get_Advance+0x70>
 *   @0x2e7964 cmp r1, r3
 *   @0x2e7968 ldr r3, [r0, #0x60]
 *   @0x2e796c ldr.w r12, [r3, #0x54]
 *   @0x2e7970 cmp.w r12, #0x0
 *   @0x2e7974 bne 0x2e7986 <FT_Get_Advance+0x36>
 *   @0x2e7978 mov r0, r4
 *   @0x2e797c movs r2, #0x1
 *   @0x2e7980 bl 0x2e788c <FT_Get_Advances>
 *   @0x2e7984 b 0x2e79c6 <FT_Get_Advance+0x76>
 *   @0x2e7988 bne 0x2e7992 <FT_Get_Advance+0x42>
 *   @0x2e798c blhs 0x3385a0
 *   @0x2e7990 bne 0x2e7976 <FT_Get_Advance+0x26>
 *   @0x2e7994 mov r0, r4
 *   @0x2e7998 movs r2, #0x1
 *   @0x2e799c blx r12
 *   @0x2e79a0 add.w r0, r4, #0x58
 *   @0x2e79a4 mov r1, r6
 *   @0x2e79a8 mov r3, r5
 *   @0x2e79ac pop.w {r4, r5, r6, r7, lr}
 *   @0x2e79b0 b.w 0x2e4db2 <FT_MulDiv+0x76>
 *   @0x2e79b4 uxtb r3, r0
 *   @0x2e79b8 bne 0x2e79c6 <FT_Get_Advance+0x76>
 *   @0x2e79bc movs r0, #0x23
 *   @0x2e79c0 movs r0, #0x6
 *   @0x2e79c4 movs r0, #0x10
 *   @0x2e79c8 pop {r4, r5, r6, r7, pc}
 *
 * ══ §85/251 AllocateIBuffer(void*, int, bool)  0xc6a10  size 120  30 条（0xc6a10..0xc6a88）
 * @func 0xc6a10 0xc6a88  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: AllocBuffer() / operator new(unsigned int) / IBuffer::IBuffer(void*, int, eBuffer_Format, int, bool)
 * 字段偏移 top8: 0x4×2 / 0x24×1 / 0x20×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc6a10 push {r4, r5, r6, r7, r8, lr}
 *   @0xc6a14 sub sp, sp, #8
 *   @0xc6a18 mov r6, r1
 *   @0xc6a1c mov r8, r2
 *   @0xc6a20 mov r7, r0
 *   @0xc6a24 bl 0xc67b0 <_Z11AllocBufferv>
 *   @0xc6a28 mov r4, r0
 *   @0xc6a2c mov r0, #64
 *   @0xc6a30 bl 0x27c524 <_Znwj>
 *   @0xc6a34 mov r2, r6
 *   @0xc6a38 mov r12, #1
 *   @0xc6a3c str r8, [sp, #0x4]
 *   @0xc6a40 mov r1, r7
 *   @0xc6a44 mov r3, #0
 *   @0xc6a48 str r12, [sp]
 *   @0xc6a4c mov r5, r0
 *   @0xc6a50 bl 0xcca38 <_ZN7IBufferC2EPvi14eBuffer_Formatib>
 *   @0xc6a54 ldr r2, [pc, #0x24]
 *   @0xc6a58 mov r0, r4
 *   @0xc6a5c ldr r3, [pc, #0x20]
 *   @0xc6a60 add r2, pc, r2
 *   @0xc6a64 ldr r3, [pc, r3]
 *   @0xc6a68 ldr r2, [r2, #0x4]
 *   @0xc6a6c add r3, r3, #8
 *   @0xc6a70 str r3, [r5]
 *   @0xc6a74 str r5, [r2, r4, lsl #2]
 *   @0xc6a78 add sp, sp, #8
 *   @0xc6a7c pop {r4, r5, r6, r7, r8, pc}
 *   @0xc6a80 ldrhteq r3, [r11], -r4
 *   @0xc6a84 eorseq r6, r2, r12, asr #30
 *
 * ══ §86/251 CBucket<32768u, 1048576u, false>::Free(void const*)  0xd3314  size 120  30 条（0xd3314..0xd338c）
 * @func 0xd3314 0xd338c  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBucket<32768u, 1048576u, false>::Free(void const*)+0x30
 * 字段偏移 top8: 0x4×3 / 0x8×2 / 0x10×2 / 0xc×2 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd3314 ldr r3, [r0, #0x4]
 *   @0xd3318 str r4, [sp, #-0x4]!
 *   @0xd331c cmp r3, #0
 *   @0xd3320 mov r4, r0
 *   @0xd3324 beq 0xd3350 <_ZN7CBucketILj32768ELj1048576ELb0EE4FreeEPKv+0x3c>
 *   @0xd3328 add r12, r3, #8
 *   @0xd332c add r2, r3, #1048576
 *   @0xd3330 cmp r1, r12
 *   @0xd3334 add r2, r2, #8
 *   @0xd3338 blo 0xd3344 <_ZN7CBucketILj32768ELj1048576ELb0EE4FreeEPKv+0x30>
 *   @0xd333c cmp r2, r1
 *   @0xd3340 bhi 0xd335c <_ZN7CBucketILj32768ELj1048576ELb0EE4FreeEPKv+0x48>
 *   @0xd3344 ldr r3, [r3]
 *   @0xd3348 cmp r3, #0
 *   @0xd334c bne 0xd3328 <_ZN7CBucketILj32768ELj1048576ELb0EE4FreeEPKv+0x14>
 *   @0xd3350 mov r0, r3
 *   @0xd3354 ldr r4, [sp], #4
 *   @0xd3358 bx lr
 *   @0xd335c ldr r12, [r4, #0x8]
 *   @0xd3360 mov r0, #1
 *   @0xd3364 ldr r2, [r4, #0x10]
 *   @0xd3368 ldr r3, [r4, #0xc]
 *   @0xd336c add r2, r2, r0
 *   @0xd3370 str r12, [r1]
 *   @0xd3374 sub r3, r3, #1
 *   @0xd3378 str r1, [r4, #0x8]
 *   @0xd337c str r2, [r4, #0x10]
 *   @0xd3380 str r3, [r4, #0xc]
 *   @0xd3384 ldr r4, [sp], #4
 *   @0xd3388 bx lr
 *
 * ══ §87/251 EndGCThread()  0xd3e1c  size 120  30 条（0xd3e1c..0xd3e94）
 * @func 0xd3e1c 0xd3e94  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)×2 / Mutex::Lock() / Mutex::Unlock() / CThread::WaitForExit() / Mutex::~Mutex()
 * 字段偏移 top8: 0x14×3 / 0x68×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd3e1c push {r4, r5, r6, lr}
 *   @0xd3e20 ldr r4, [pc, #0x68]
 *   @0xd3e24 ldr r4, [pc, r4]
 *   @0xd3e28 ldr r5, [r4]
 *   @0xd3e2c cmp r5, #0
 *   @0xd3e30 popeq {r4, r5, r6, pc}
 *   @0xd3e34 ldr r0, [r5, #0x14]
 *   @0xd3e38 bl 0x27e084 <_ZN5Mutex4LockEv>
 *   @0xd3e3c mov r3, #1
 *   @0xd3e40 ldr r0, [r5, #0x14]
 *   @0xd3e44 strb r3, [r5, #0x8]
 *   @0xd3e48 bl 0x27e09c <_ZN5Mutex6UnlockEv>
 *   @0xd3e4c ldr r0, [r4]
 *   @0xd3e50 bl 0x27e108 <_ZN7CThread11WaitForExitEv>
 *   @0xd3e54 ldr r5, [r4]
 *   @0xd3e58 cmp r5, #0
 *   @0xd3e5c beq 0xd3e84 <_Z11EndGCThreadv+0x68>
 *   @0xd3e60 ldr r6, [r5, #0x14]
 *   @0xd3e64 cmp r6, #0
 *   @0xd3e68 beq 0xd3e7c <_Z11EndGCThreadv+0x60>
 *   @0xd3e6c mov r0, r6
 *   @0xd3e70 bl 0x27e020 <_ZN5MutexD2Ev>
 *   @0xd3e74 mov r0, r6
 *   @0xd3e78 bl 0x27d1d0 <_ZdlPv>
 *   @0xd3e7c mov r0, r5
 *   @0xd3e80 bl 0x27d1d0 <_ZdlPv>
 *   @0xd3e84 mov r3, #0
 *   @0xd3e88 str r3, [r4]
 *   @0xd3e8c pop {r4, r5, r6, pc}
 *   @0xd3e90 eorseq r9, r1, r0, lsl #28
 *
 * ══ §88/251 CExtensionConstant::LoadFromExeStream(CStream*)  0xf4878  size 120  30 条（0xf4878..0xf48f0）
 * @func 0xf4878 0xf48f0  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / CStream::ReadString(char const*&)×2 / CExtensionConstant::Clear() / CStream::ReadInteger()
 * 字段偏移 top8: 0x4×2 / 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4878 push {r3, r4, r5, lr}
 *   @0xf487c mov r5, r1
 *   @0xf4880 mov r4, r0
 *   @0xf4884 bl 0xf47f4 <_ZN18CExtensionConstant5ClearEv>
 *   @0xf4888 mov r0, r5
 *   @0xf488c bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0xf4890 cmp r0, #700
 *   @0xf4894 beq 0xf48a0 <_ZN18CExtensionConstant17LoadFromExeStreamEP7CStream+0x28>
 *   @0xf4898 mov r0, #0
 *   @0xf489c pop {r3, r4, r5, pc}
 *   @0xf48a0 ldr r0, [r4, #0x4]
 *   @0xf48a4 cmp r0, #0
 *   @0xf48a8 beq 0xf48b8 <_ZN18CExtensionConstant17LoadFromExeStreamEP7CStream+0x40>
 *   @0xf48ac bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xf48b0 mov r3, #0
 *   @0xf48b4 str r3, [r4, #0x4]
 *   @0xf48b8 mov r0, r5
 *   @0xf48bc add r1, r4, #4
 *   @0xf48c0 bl 0x2018e8 <_ZN7CStream10ReadStringERPKc>
 *   @0xf48c4 ldr r0, [r4, #0x8]
 *   @0xf48c8 cmp r0, #0
 *   @0xf48cc beq 0xf48dc <_ZN18CExtensionConstant17LoadFromExeStreamEP7CStream+0x64>
 *   @0xf48d0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xf48d4 mov r3, #0
 *   @0xf48d8 str r3, [r4, #0x8]
 *   @0xf48dc mov r0, r5
 *   @0xf48e0 add r1, r4, #8
 *   @0xf48e4 bl 0x2018e8 <_ZN7CStream10ReadStringERPKc>
 *   @0xf48e8 mov r0, #1
 *   @0xf48ec pop {r3, r4, r5, pc}
 *
 * ══ §89/251 F_DsPriorityAdd(RValue&, CInstance*, CInstance*, int, RValue*)  0xfcce4  size 120  30 条（0xfcce4..0xfcd5c）
 * @func 0xfcce4 0xfcd70  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_DsPriorityAdd(RValue&, CInstance*, CInstance*, int, RValue*)+0x58
 * 字段偏移 top8: 0x8×1 / 0x48×1 / 0x38×1 / 0x4×1 / 0x2×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfcce4 push {r4, lr}
 *   @0xfcce8 mov r1, #0
 *   @0xfccec ldr r4, [sp, #0x8]
 *   @0xfccf0 mov r0, r4
 *   @0xfccf4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfccf8 cmp r0, #0
 *   @0xfccfc blt 0xfcd3c <_Z15F_DsPriorityAddR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0xfcd00 ldr r3, [pc, #0x48]
 *   @0xfcd04 ldr r3, [pc, r3]
 *   @0xfcd08 ldr r3, [r3]
 *   @0xfcd0c cmp r0, r3
 *   @0xfcd10 bge 0xfcd3c <_Z15F_DsPriorityAddR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0xfcd14 ldr r3, [pc, #0x38]
 *   @0xfcd18 ldr r3, [pc, r3]
 *   @0xfcd1c ldr r3, [r3, #0x4]
 *   @0xfcd20 ldr r0, [r3, r0, lsl #2]
 *   @0xfcd24 cmp r0, #0
 *   @0xfcd28 beq 0xfcd3c <_Z15F_DsPriorityAddR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0xfcd2c add r1, r4, #16
 *   @0xfcd30 add r2, r4, #32
 *   @0xfcd34 pop {r4, lr}
 *   @0xfcd38 b 0x206510 <_ZN12CDS_Priority3AddEP6RValueS1_>
 *   @0xfcd3c ldr r0, [pc, #0x14]
 *   @0xfcd40 mov r1, #0
 *   @0xfcd44 pop {r4, lr}
 *   @0xfcd48 add r0, pc, r0
 *   @0xfcd4c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfcd50 eoreq r1, pc, r0, ror r1
 *   @0xfcd54 eoreq r1, pc, r0, ror #2
 *   @0xfcd58 .word 0x0023aeb4
 *
 * ══ §90/251 F_DsPriorityChangePriority(RValue&, CInstance*, CInstance*, int, RValue*)  0xfcd5c  size 120  30 条（0xfcd5c..0xfcdd4）
 * @func 0xfcd5c 0xfcde8  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_DsPriorityChangePriority(RValue&, CInstance*, CInstance*, int, RValue*)+0x58
 * 字段偏移 top8: 0x8×1 / 0x48×1 / 0x38×1 / 0x4×1 / 0x2×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfcd5c push {r4, lr}
 *   @0xfcd60 mov r1, #0
 *   @0xfcd64 ldr r4, [sp, #0x8]
 *   @0xfcd68 mov r0, r4
 *   @0xfcd6c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfcd70 cmp r0, #0
 *   @0xfcd74 blt 0xfcdb4 <_Z26F_DsPriorityChangePriorityR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0xfcd78 ldr r3, [pc, #0x48]
 *   @0xfcd7c ldr r3, [pc, r3]
 *   @0xfcd80 ldr r3, [r3]
 *   @0xfcd84 cmp r0, r3
 *   @0xfcd88 bge 0xfcdb4 <_Z26F_DsPriorityChangePriorityR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0xfcd8c ldr r3, [pc, #0x38]
 *   @0xfcd90 ldr r3, [pc, r3]
 *   @0xfcd94 ldr r3, [r3, #0x4]
 *   @0xfcd98 ldr r0, [r3, r0, lsl #2]
 *   @0xfcd9c cmp r0, #0
 *   @0xfcda0 beq 0xfcdb4 <_Z26F_DsPriorityChangePriorityR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0xfcda4 add r1, r4, #16
 *   @0xfcda8 add r2, r4, #32
 *   @0xfcdac pop {r4, lr}
 *   @0xfcdb0 b 0x20a148 <_ZN12CDS_Priority6ChangeEP6RValueS1_>
 *   @0xfcdb4 ldr r0, [pc, #0x14]
 *   @0xfcdb8 mov r1, #0
 *   @0xfcdbc pop {r4, lr}
 *   @0xfcdc0 add r0, pc, r0
 *   @0xfcdc4 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfcdc8 .word 0x002f10f8
 *   @0xfcdcc eoreq r1, pc, r8, ror #1
 *   @0xfcdd0 eoreq r10, r3, r12, lsr lr
 *
 * ══ §91/251 F_InstancePosition(RValue&, CInstance*, CInstance*, int, RValue*)  0x1093b0  size 120  30 条（0x1093b0..0x109428）
 * @func 0x1093b0 0x10943c  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / YYGetInt32(RValue const*, int) / Command_InstancePosition(float, float, int)
 * 字段偏移 top8: 0x18×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1093b0 push {r3, r4, r5, r6, r7, lr}
 *   @0x1093b4 mov r1, #0
 *   @0x1093b8 ldr r4, [sp, #0x18]
 *   @0x1093bc mov r5, r0
 *   @0x1093c0 mov r0, r4
 *   @0x1093c4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1093c8 mov r1, #1
 *   @0x1093cc mov r7, r0
 *   @0x1093d0 mov r0, r4
 *   @0x1093d4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1093d8 mov r1, #2
 *   @0x1093dc mov r6, r0
 *   @0x1093e0 mov r0, r4
 *   @0x1093e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1093e8 mov r1, r6
 *   @0x1093ec mov r2, r0
 *   @0x1093f0 mov r0, r7
 *   @0x1093f4 bl 0x1c90cc <_Z24Command_InstancePositionffi>
 *   @0x1093f8 mov r3, #0
 *   @0x1093fc str r3, [r5, #0xc]
 *   @0x109400 cmp r0, #0
 *   @0x109404 ldrne r2, [r0, #0x78]
 *   @0x109408 moveq r3, #0
 *   @0x10940c moveq r2, #0
 *   @0x109410 movteq r3, #0xc010
 *   @0x109414 vmovne s15, r2
 *   @0x109418 vcvtne.f64.s32 d7, s15
 *   @0x10941c vmovne r2, r3, d7
 *   @0x109420 stm r5, {r2, r3}
 *   @0x109424 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §92/251 F_InstanceNearest(RValue&, CInstance*, CInstance*, int, RValue*)  0x109428  size 120  30 条（0x109428..0x1094a0）
 * @func 0x109428 0x1094b4  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / YYGetInt32(RValue const*, int) / Command_InstanceNearest(float, float, int)
 * 字段偏移 top8: 0x18×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x109428 push {r3, r4, r5, r6, r7, lr}
 *   @0x10942c mov r1, #0
 *   @0x109430 ldr r4, [sp, #0x18]
 *   @0x109434 mov r5, r0
 *   @0x109438 mov r0, r4
 *   @0x10943c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x109440 mov r1, #1
 *   @0x109444 mov r7, r0
 *   @0x109448 mov r0, r4
 *   @0x10944c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x109450 mov r1, #2
 *   @0x109454 mov r6, r0
 *   @0x109458 mov r0, r4
 *   @0x10945c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x109460 mov r1, r6
 *   @0x109464 mov r2, r0
 *   @0x109468 mov r0, r7
 *   @0x10946c bl 0x1c9290 <_Z23Command_InstanceNearestffi>
 *   @0x109470 mov r3, #0
 *   @0x109474 str r3, [r5, #0xc]
 *   @0x109478 cmp r0, #0
 *   @0x10947c ldrne r2, [r0, #0x78]
 *   @0x109480 moveq r3, #0
 *   @0x109484 moveq r2, #0
 *   @0x109488 movteq r3, #0xc010
 *   @0x10948c vmovne s15, r2
 *   @0x109490 vcvtne.f64.s32 d7, s15
 *   @0x109494 vmovne r2, r3, d7
 *   @0x109498 stm r5, {r2, r3}
 *   @0x10949c pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §93/251 F_InstanceFurthest(RValue&, CInstance*, CInstance*, int, RValue*)  0x1094a0  size 120  30 条（0x1094a0..0x109518）
 * @func 0x1094a0 0x109518  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / YYGetInt32(RValue const*, int) / Command_InstanceFurthest(float, float, int)
 * 字段偏移 top8: 0x18×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1094a0 push {r3, r4, r5, r6, r7, lr}
 *   @0x1094a4 mov r1, #0
 *   @0x1094a8 ldr r4, [sp, #0x18]
 *   @0x1094ac mov r5, r0
 *   @0x1094b0 mov r0, r4
 *   @0x1094b4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1094b8 mov r1, #1
 *   @0x1094bc mov r7, r0
 *   @0x1094c0 mov r0, r4
 *   @0x1094c4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1094c8 mov r1, #2
 *   @0x1094cc mov r6, r0
 *   @0x1094d0 mov r0, r4
 *   @0x1094d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1094d8 mov r1, r6
 *   @0x1094dc mov r2, r0
 *   @0x1094e0 mov r0, r7
 *   @0x1094e4 bl 0x1c9414 <_Z24Command_InstanceFurthestffi>
 *   @0x1094e8 mov r3, #0
 *   @0x1094ec str r3, [r5, #0xc]
 *   @0x1094f0 cmp r0, #0
 *   @0x1094f4 ldrne r2, [r0, #0x78]
 *   @0x1094f8 moveq r3, #0
 *   @0x1094fc moveq r2, #0
 *   @0x109500 movteq r3, #0xc010
 *   @0x109504 vmovne s15, r2
 *   @0x109508 vcvtne.f64.s32 d7, s15
 *   @0x10950c vmovne r2, r3, d7
 *   @0x109510 stm r5, {r2, r3}
 *   @0x109514 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §94/251 F_ArraySet(RValue&, CInstance*, CInstance*, int, RValue*)  0x10f53c  size 120  30 条（0x10f53c..0x10f5b4）
 * @func 0x10f53c 0x10f5b4  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1 / 0xc×1 / 0x4c×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10f53c push {r4, lr}
 *   @0x10f540 cmp r3, #3
 *   @0x10f544 ldr r4, [sp, #0x8]
 *   @0x10f548 ldr r3, [r4, #0xc]
 *   @0x10f54c beq 0x10f568 <_Z10F_ArraySetR6RValueP9CInstanceS2_iPS_+0x2c>
 *   @0x10f550 cmp r3, #2
 *   @0x10f554 beq 0x10f57c <_Z10F_ArraySetR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x10f558 ldr r0, [pc, #0x4c]
 *   @0x10f55c pop {r4, lr}
 *   @0x10f560 add r0, pc, r0
 *   @0x10f564 b 0xd547c <_Z7YYErrorPKcz>
 *   @0x10f568 cmp r3, #2
 *   @0x10f56c bne 0x10f558 <_Z10F_ArraySetR6RValueP9CInstanceS2_iPS_+0x1c>
 *   @0x10f570 ldr r3, [r4]
 *   @0x10f574 cmp r3, #0
 *   @0x10f578 bne 0x10f58c <_Z10F_ArraySetR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x10f57c ldr r0, [pc, #0x2c]
 *   @0x10f580 pop {r4, lr}
 *   @0x10f584 add r0, pc, r0
 *   @0x10f588 b 0xd547c <_Z7YYErrorPKcz>
 *   @0x10f58c mov r0, r4
 *   @0x10f590 mov r1, #1
 *   @0x10f594 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x10f598 add r1, r4, #32
 *   @0x10f59c mov r2, r0
 *   @0x10f5a0 mov r0, r4
 *   @0x10f5a4 pop {r4, lr}
 *   @0x10f5a8 b 0xcfcb4 <_Z16SET_RValue_ArrayP6RValueS0_i>
 *   @0x10f5ac eoreq r9, r2, r0, lsl #19
 *   @0x10f5b0 eoreq r9, r2, r4, lsl #19
 *
 * ══ §95/251 F_TileGetID(RValue&, CInstance*, CInstance*, int, RValue*)  0x119e60  size 120  30 条（0x119e60..0x119ed8）
 * @func 0x119e60 0x119ed8  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_TileGetID(RValue&, CInstance*, CInstance*, int, RValue*)+0x60
 * 字段偏移 top8: 0x64×1 / 0x10×1 / 0xc×1 / 0xb8×1 / 0xc0×1 / 0x20×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x119e60 push {r3, r4, r5, lr}
 *   @0x119e64 mov r4, r0
 *   @0x119e68 ldr r3, [pc, #0x64]
 *   @0x119e6c mov r1, #0
 *   @0x119e70 ldr r0, [sp, #0x10]
 *   @0x119e74 ldr r3, [pc, r3]
 *   @0x119e78 str r1, [r4, #0xc]
 *   @0x119e7c ldr r5, [r3]
 *   @0x119e80 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x119e84 cmp r0, #0
 *   @0x119e88 blt 0x119ec0 <_Z11F_TileGetIDR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x119e8c ldr r3, [r5, #0xb8]
 *   @0x119e90 cmp r0, r3
 *   @0x119e94 bge 0x119ec0 <_Z11F_TileGetIDR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x119e98 ldr r3, [r5, #0xc0]
 *   @0x119e9c rsb r0, r0, r0, lsl #3
 *   @0x119ea0 adds r0, r3, r0, lsl #3
 *   @0x119ea4 beq 0x119ec0 <_Z11F_TileGetIDR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x119ea8 ldr r2, [r0, #0x20]
 *   @0x119eac vmov s15, r2
 *   @0x119eb0 vcvt.f64.s32 d7, s15
 *   @0x119eb4 vmov r2, r3, d7
 *   @0x119eb8 stm r4, {r2, r3}
 *   @0x119ebc pop {r3, r4, r5, pc}
 *   @0x119ec0 mov r3, #0
 *   @0x119ec4 mov r2, r3
 *   @0x119ec8 movt r3, #0xbff0
 *   @0x119ecc stm r4, {r2, r3}
 *   @0x119ed0 pop {r3, r4, r5, pc}
 *   @0x119ed4 .word 0x002d3ab4
 *
 * ══ §96/251 F_SurfaceFree(RValue&, CInstance*, CInstance*, int, RValue*)  0x11c8c8  size 120  30 条（0x11c8c8..0x11c940）
 * @func 0x11c8c8 0x11c940  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / GR_Surface_Free(int, bool)
 * 字段偏移 top8: 0x10×1 / 0x38×1 / 0x28×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11c8c8 push {r3, r4, r5, lr}
 *   @0x11c8cc mov r1, #0
 *   @0x11c8d0 ldr r4, [sp, #0x10]
 *   @0x11c8d4 mov r0, r4
 *   @0x11c8d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11c8dc mov r1, #0
 *   @0x11c8e0 mov r5, r0
 *   @0x11c8e4 mov r0, r4
 *   @0x11c8e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11c8ec mov r1, #0
 *   @0x11c8f0 bl 0x171ba0 <_Z15GR_Surface_Freeib>
 *   @0x11c8f4 ldr r3, [pc, #0x38]
 *   @0x11c8f8 ldr r3, [pc, r3]
 *   @0x11c8fc ldrb r3, [r3]
 *   @0x11c900 cmp r3, #0
 *   @0x11c904 popeq {r3, r4, r5, pc}
 *   @0x11c908 ldr r3, [pc, #0x28]
 *   @0x11c90c ldr r3, [pc, r3]
 *   @0x11c910 ldr r3, [r3]
 *   @0x11c914 cmp r3, #0
 *   @0x11c918 popne {r3, r4, r5, pc}
 *   @0x11c91c ldr r1, [pc, #0x18]
 *   @0x11c920 mov r2, r5
 *   @0x11c924 mov r0, #4
 *   @0x11c928 add r1, pc, r1
 *   @0x11c92c pop {r3, r4, r5, lr}
 *   @0x11c930 b 0x29c3ec <_Z12Debug_AddTag12eTagNameTypePKcz>
 *   @0x11c934 eoreq r1, sp, r12, lsr #32
 *   @0x11c938 eoreq r1, sp, r4, lsl r11
 *   @0x11c93c eoreq sp, r1, r0, lsl #15
 *
 * ══ §97/251 F_ShowError(RValue&, CInstance*, CInstance*, int, RValue*)  0x1273f4  size 120  30 条（0x1273f4..0x12746c）
 * @func 0x1273f4 0x12746c  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / YYGetBool(RValue const*, int) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x10×1 / 0x34×1 / 0x24×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1273f4 push {r3, r4, r5, lr}
 *   @0x1273f8 mov r1, #0
 *   @0x1273fc ldr r4, [sp, #0x10]
 *   @0x127400 mov r0, r4
 *   @0x127404 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x127408 mov r1, #1
 *   @0x12740c mov r5, r0
 *   @0x127410 mov r0, r4
 *   @0x127414 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x127418 mov r1, r0
 *   @0x12741c mov r0, r5
 *   @0x127420 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x127424 ldr r3, [pc, #0x34]
 *   @0x127428 ldr r3, [pc, r3]
 *   @0x12742c ldrb r3, [r3]
 *   @0x127430 cmp r3, #0
 *   @0x127434 popeq {r3, r4, r5, pc}
 *   @0x127438 ldr r3, [pc, #0x24]
 *   @0x12743c ldr r3, [pc, r3]
 *   @0x127440 ldr r3, [r3]
 *   @0x127444 cmp r3, #0
 *   @0x127448 popne {r3, r4, r5, pc}
 *   @0x12744c ldr r1, [pc, #0x14]
 *   @0x127450 mov r0, #1
 *   @0x127454 pop {r3, r4, r5, lr}
 *   @0x127458 add r1, pc, r1
 *   @0x12745c b 0x29c3ec <_Z12Debug_AddTag12eTagNameTypePKcz>
 *   @0x127460 .word 0x002c64fc
 *   @0x127464 eoreq r6, r12, r4, ror #31
 *   @0x127468 mlaeq r1, r4, lr, r4
 *
 * ══ §98/251 F_PathInsertPoint(RValue&, CInstance*, CInstance*, int, RValue*)  0x12db14  size 120  30 条（0x12db14..0x12db8c）
 * @func 0x12db14 0x12dba0  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×3 / YYGetInt32(RValue const*, int)×2 / Path_Data(int)
 * 字段偏移 top8: 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12db14 push {r4, r5, r6, r7, r8, lr}
 *   @0x12db18 mov r1, #0
 *   @0x12db1c ldr r4, [sp, #0x18]
 *   @0x12db20 mov r0, r4
 *   @0x12db24 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12db28 bl 0x1a815c <_Z9Path_Datai>
 *   @0x12db2c subs r5, r0, #0
 *   @0x12db30 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x12db34 mov r0, r4
 *   @0x12db38 mov r1, #1
 *   @0x12db3c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12db40 mov r1, #2
 *   @0x12db44 mov r8, r0
 *   @0x12db48 mov r0, r4
 *   @0x12db4c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x12db50 mov r1, #3
 *   @0x12db54 mov r7, r0
 *   @0x12db58 mov r0, r4
 *   @0x12db5c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x12db60 mov r1, #4
 *   @0x12db64 mov r6, r0
 *   @0x12db68 mov r0, r4
 *   @0x12db6c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x12db70 mov r1, r8
 *   @0x12db74 mov r2, r7
 *   @0x12db78 mov r3, r6
 *   @0x12db7c str r0, [sp, #0x18]
 *   @0x12db80 mov r0, r5
 *   @0x12db84 pop {r4, r5, r6, r7, r8, lr}
 *   @0x12db88 b 0x1a71d0 <_ZN5CPath11InsertPointEifff>
 *
 * ══ §99/251 F_PathChangePoint(RValue&, CInstance*, CInstance*, int, RValue*)  0x12db8c  size 120  30 条（0x12db8c..0x12dc04）
 * @func 0x12db8c 0x12dc04  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×3 / YYGetInt32(RValue const*, int)×2 / Path_Data(int)
 * 字段偏移 top8: 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12db8c push {r4, r5, r6, r7, r8, lr}
 *   @0x12db90 mov r1, #0
 *   @0x12db94 ldr r4, [sp, #0x18]
 *   @0x12db98 mov r0, r4
 *   @0x12db9c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12dba0 bl 0x1a815c <_Z9Path_Datai>
 *   @0x12dba4 subs r5, r0, #0
 *   @0x12dba8 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x12dbac mov r0, r4
 *   @0x12dbb0 mov r1, #1
 *   @0x12dbb4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12dbb8 mov r1, #2
 *   @0x12dbbc mov r8, r0
 *   @0x12dbc0 mov r0, r4
 *   @0x12dbc4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x12dbc8 mov r1, #3
 *   @0x12dbcc mov r7, r0
 *   @0x12dbd0 mov r0, r4
 *   @0x12dbd4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x12dbd8 mov r1, #4
 *   @0x12dbdc mov r6, r0
 *   @0x12dbe0 mov r0, r4
 *   @0x12dbe4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x12dbe8 mov r1, r8
 *   @0x12dbec mov r2, r7
 *   @0x12dbf0 mov r3, r6
 *   @0x12dbf4 str r0, [sp, #0x18]
 *   @0x12dbf8 mov r0, r5
 *   @0x12dbfc pop {r4, r5, r6, r7, r8, lr}
 *   @0x12dc00 b 0x1a72f8 <_ZN5CPath11ChangePointEifff>
 *
 * ══ §100/251 F_AudioSetListenerPosition(RValue&, CInstance*, CInstance*, int, RValue*)  0x13460c  size 120  30 条（0x13460c..0x134684）
 * @func 0x13460c 0x134684  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×3 / Audio_SetListenerPosition(int, double, double, double)
 * 字段偏移 top8: 0x6c×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13460c ldr r3, [pc, #0x6c]
 *   @0x134610 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x134614 ldr r3, [pc, r3]
 *   @0x134618 sub sp, sp, #20
 *   @0x13461c ldrb r8, [r3]
 *   @0x134620 ldr r9, [sp, #0x30]
 *   @0x134624 cmp r8, #0
 *   @0x134628 bne 0x134678 <_Z26F_AudioSetListenerPositionR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x13462c mov r0, r9
 *   @0x134630 mov r1, r8
 *   @0x134634 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134638 mov r4, r0
 *   @0x13463c mov r5, r1
 *   @0x134640 mov r0, r9
 *   @0x134644 mov r1, #1
 *   @0x134648 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x13464c mov r6, r0
 *   @0x134650 mov r7, r1
 *   @0x134654 mov r0, r9
 *   @0x134658 mov r1, #2
 *   @0x13465c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134660 strd r6, r7, [sp]
 *   @0x134664 mov r2, r4
 *   @0x134668 mov r3, r5
 *   @0x13466c strd r0, r1, [sp, #8]
 *   @0x134670 mov r0, r8
 *   @0x134674 bl 0x2165c0 <_Z25Audio_SetListenerPositioniddd>
 *   @0x134678 add sp, sp, #20
 *   @0x13467c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x134680 eoreq r10, r11, r8, lsr r10
 *
 * ══ §101/251 F_AudioSetListenerVelocity(RValue&, CInstance*, CInstance*, int, RValue*)  0x134708  size 120  30 条（0x134708..0x134780）
 * @func 0x134708 0x134780  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×3 / Audio_SetListenerVelocity(int, double, double, double)
 * 字段偏移 top8: 0x6c×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x134708 ldr r3, [pc, #0x6c]
 *   @0x13470c push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x134710 ldr r3, [pc, r3]
 *   @0x134714 sub sp, sp, #20
 *   @0x134718 ldrb r8, [r3]
 *   @0x13471c ldr r9, [sp, #0x30]
 *   @0x134720 cmp r8, #0
 *   @0x134724 bne 0x134774 <_Z26F_AudioSetListenerVelocityR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x134728 mov r0, r9
 *   @0x13472c mov r1, r8
 *   @0x134730 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134734 mov r4, r0
 *   @0x134738 mov r5, r1
 *   @0x13473c mov r0, r9
 *   @0x134740 mov r1, #1
 *   @0x134744 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134748 mov r6, r0
 *   @0x13474c mov r7, r1
 *   @0x134750 mov r0, r9
 *   @0x134754 mov r1, #2
 *   @0x134758 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x13475c strd r6, r7, [sp]
 *   @0x134760 mov r2, r4
 *   @0x134764 mov r3, r5
 *   @0x134768 strd r0, r1, [sp, #8]
 *   @0x13476c mov r0, r8
 *   @0x134770 bl 0x216608 <_Z25Audio_SetListenerVelocityiddd>
 *   @0x134774 add sp, sp, #20
 *   @0x134778 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x13477c eoreq r10, r11, r12, lsr r9
 *
 * ══ §102/251 F_FileTextWriteLn(RValue&, CInstance*, CInstance*, int, RValue*)  0x13824c  size 120  30 条（0x13824c..0x1382c4）
 * @func 0x13824c 0x1382c4  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×2 / 0x44×1 / 0x2×1 / 0x34×1 / 0x24×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13824c push {r3, lr}
 *   @0x138250 mov r1, #0
 *   @0x138254 ldr r0, [sp, #0x8]
 *   @0x138258 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13825c sub r3, r0, #1
 *   @0x138260 cmp r3, #30
 *   @0x138264 bhi 0x13827c <_Z17F_FileTextWriteLnR6RValueP9CInstanceS2_iPS_+0x30>
 *   @0x138268 ldr r3, [pc, #0x44]
 *   @0x13826c ldr r3, [pc, r3]
 *   @0x138270 ldr r3, [r3, r0, lsl #2]
 *   @0x138274 cmp r3, #2
 *   @0x138278 beq 0x138290 <_Z17F_FileTextWriteLnR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x13827c ldr r0, [pc, #0x34]
 *   @0x138280 mov r1, #0
 *   @0x138284 pop {r3, lr}
 *   @0x138288 add r0, pc, r0
 *   @0x13828c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x138290 ldr r3, [pc, #0x24]
 *   @0x138294 add r0, r0, r0, lsl #1
 *   @0x138298 ldr r1, [pc, #0x20]
 *   @0x13829c ldr r3, [pc, r3]
 *   @0x1382a0 add r3, r3, r0, lsl #2
 *   @0x1382a4 add r1, pc, r1
 *   @0x1382a8 ldr r0, [r3, #0x8]
 *   @0x1382ac pop {r3, lr}
 *   @0x1382b0 b 0x18e114 <_ZN8LoadSave5fputsEP7_YYFILEPKc>
 *   @0x1382b4 eoreq r7, r11, r4
 *   @0x1382b8 eoreq r7, r0, r4, lsl #28
 *   @0x1382bc .word 0x002b6fd8
 *   @0x1382c0 ldrsheq r10, [pc], -r4
 *
 * ══ §103/251 F_IniWriteString(RValue&, CInstance*, CInstance*, int, RValue*)  0x13a1d0  size 120  30 条（0x13a1d0..0x13a248）
 * @func 0x13a1d0 0x13a25c  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)×3
 * 字段偏移 top8: 0x10×1 / 0x34×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13a1d0 push {r4, r5, r6, lr}
 *   @0x13a1d4 mov r1, #0
 *   @0x13a1d8 ldr r4, [sp, #0x10]
 *   @0x13a1dc mov r0, r4
 *   @0x13a1e0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x13a1e4 mov r1, #1
 *   @0x13a1e8 mov r5, r0
 *   @0x13a1ec mov r0, r4
 *   @0x13a1f0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x13a1f4 mov r1, #2
 *   @0x13a1f8 mov r6, r0
 *   @0x13a1fc mov r0, r4
 *   @0x13a200 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x13a204 ldr r12, [pc, #0x34]
 *   @0x13a208 ldr r12, [pc, r12]
 *   @0x13a20c mov r3, r0
 *   @0x13a210 ldr r0, [r12]
 *   @0x13a214 cmp r0, #0
 *   @0x13a218 beq 0x13a22c <_Z16F_IniWriteStringR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x13a21c mov r1, r5
 *   @0x13a220 mov r2, r6
 *   @0x13a224 pop {r4, r5, r6, lr}
 *   @0x13a228 b 0x235edc <_ZN7IniFile6SetKeyEPKcS1_S1_>
 *   @0x13a22c mov r1, r0
 *   @0x13a230 ldr r0, [pc, #0xc]
 *   @0x13a234 pop {r4, r5, r6, lr}
 *   @0x13a238 add r0, pc, r0
 *   @0x13a23c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x13a240 eoreq r5, r11, r12, lsl #1
 *   @0x13a244 eoreq r6, r0, r0, lsr r0
 *
 * ══ §104/251 F_GPUSetTexMipFilterExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x1477c0  size 120  30 条（0x1477c0..0x147838）
 * @func 0x1477c0 0x14784c  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x44×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1477c0 cmp r3, #2
 *   @0x1477c4 mov r3, #0
 *   @0x1477c8 push {r4, r5, r6, lr}
 *   @0x1477cc mov r1, r3
 *   @0x1477d0 ldr r4, [sp, #0x10]
 *   @0x1477d4 movt r3, #0xbff0
 *   @0x1477d8 str r1, [r0, #0xc]
 *   @0x1477dc stm r0, {r1, r3}
 *   @0x1477e0 beq 0x1477f4 <_Z23F_GPUSetTexMipFilterExtR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x1477e4 ldr r0, [pc, #0x44]
 *   @0x1477e8 pop {r4, r5, r6, lr}
 *   @0x1477ec add r0, pc, r0
 *   @0x1477f0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1477f4 mov r0, r4
 *   @0x1477f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1477fc mov r1, #1
 *   @0x147800 mov r5, r0
 *   @0x147804 mov r0, r4
 *   @0x147808 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14780c cmp r5, #7
 *   @0x147810 pophi {r4, r5, r6, pc}
 *   @0x147814 ldr r12, [pc, #0x18]
 *   @0x147818 mov r1, r5
 *   @0x14781c mov r3, r0
 *   @0x147820 mov r2, #4
 *   @0x147824 ldr r0, [pc, r12]
 *   @0x147828 pop {r4, r5, r6, lr}
 *   @0x14782c b 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x147830 ldrheq r10, [pc], -r4
 *   @0x147834 .word 0x002a64d4
 *
 * ══ §105/251 F_GPUSetTexMipBiasExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x1478b4  size 120  30 条（0x1478b4..0x14792c）
 * @func 0x1478b4 0x147940  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x44×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1478b4 cmp r3, #2
 *   @0x1478b8 mov r3, #0
 *   @0x1478bc push {r4, r5, r6, lr}
 *   @0x1478c0 mov r1, r3
 *   @0x1478c4 ldr r4, [sp, #0x10]
 *   @0x1478c8 movt r3, #0xbff0
 *   @0x1478cc str r1, [r0, #0xc]
 *   @0x1478d0 stm r0, {r1, r3}
 *   @0x1478d4 beq 0x1478e8 <_Z21F_GPUSetTexMipBiasExtR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x1478d8 ldr r0, [pc, #0x44]
 *   @0x1478dc pop {r4, r5, r6, lr}
 *   @0x1478e0 add r0, pc, r0
 *   @0x1478e4 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1478e8 mov r0, r4
 *   @0x1478ec bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1478f0 mov r1, #1
 *   @0x1478f4 mov r5, r0
 *   @0x1478f8 mov r0, r4
 *   @0x1478fc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x147900 cmp r5, #7
 *   @0x147904 pophi {r4, r5, r6, pc}
 *   @0x147908 ldr r12, [pc, #0x18]
 *   @0x14790c mov r1, r5
 *   @0x147910 mov r3, r0
 *   @0x147914 mov r2, #7
 *   @0x147918 ldr r0, [pc, r12]
 *   @0x14791c pop {r4, r5, r6, lr}
 *   @0x147920 b 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x147924 andseq r10, pc, r4, asr r3
 *   @0x147928 eoreq r6, r10, r0, ror #7
 *
 * ══ §106/251 F_GPUSetTexMinMipExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x1479a8  size 120  30 条（0x1479a8..0x147a20）
 * @func 0x1479a8 0x147a34  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x44×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1479a8 cmp r3, #2
 *   @0x1479ac mov r3, #0
 *   @0x1479b0 push {r4, r5, r6, lr}
 *   @0x1479b4 mov r1, r3
 *   @0x1479b8 ldr r4, [sp, #0x10]
 *   @0x1479bc movt r3, #0xbff0
 *   @0x1479c0 str r1, [r0, #0xc]
 *   @0x1479c4 stm r0, {r1, r3}
 *   @0x1479c8 beq 0x1479dc <_Z20F_GPUSetTexMinMipExtR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x1479cc ldr r0, [pc, #0x44]
 *   @0x1479d0 pop {r4, r5, r6, lr}
 *   @0x1479d4 add r0, pc, r0
 *   @0x1479d8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1479dc mov r0, r4
 *   @0x1479e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1479e4 mov r1, #1
 *   @0x1479e8 mov r5, r0
 *   @0x1479ec mov r0, r4
 *   @0x1479f0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1479f4 cmp r5, #7
 *   @0x1479f8 pophi {r4, r5, r6, pc}
 *   @0x1479fc ldr r12, [pc, #0x18]
 *   @0x147a00 mov r1, r5
 *   @0x147a04 mov r3, r0
 *   @0x147a08 mov r2, #5
 *   @0x147a0c ldr r0, [pc, r12]
 *   @0x147a10 pop {r4, r5, r6, lr}
 *   @0x147a14 b 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x147a18 ldrsheq r10, [pc], -r0
 *   @0x147a1c eoreq r6, r10, r12, ror #5
 *
 * ══ §107/251 F_GPUSetTexMaxMipExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x147a9c  size 120  30 条（0x147a9c..0x147b14）
 * @func 0x147a9c 0x147b14  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x44×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x147a9c cmp r3, #2
 *   @0x147aa0 mov r3, #0
 *   @0x147aa4 push {r4, r5, r6, lr}
 *   @0x147aa8 mov r1, r3
 *   @0x147aac ldr r4, [sp, #0x10]
 *   @0x147ab0 movt r3, #0xbff0
 *   @0x147ab4 str r1, [r0, #0xc]
 *   @0x147ab8 stm r0, {r1, r3}
 *   @0x147abc beq 0x147ad0 <_Z20F_GPUSetTexMaxMipExtR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x147ac0 ldr r0, [pc, #0x44]
 *   @0x147ac4 pop {r4, r5, r6, lr}
 *   @0x147ac8 add r0, pc, r0
 *   @0x147acc b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x147ad0 mov r0, r4
 *   @0x147ad4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x147ad8 mov r1, #1
 *   @0x147adc mov r5, r0
 *   @0x147ae0 mov r0, r4
 *   @0x147ae4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x147ae8 cmp r5, #7
 *   @0x147aec pophi {r4, r5, r6, pc}
 *   @0x147af0 ldr r12, [pc, #0x18]
 *   @0x147af4 mov r1, r5
 *   @0x147af8 mov r3, r0
 *   @0x147afc mov r2, #6
 *   @0x147b00 ldr r0, [pc, r12]
 *   @0x147b04 pop {r4, r5, r6, lr}
 *   @0x147b08 b 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x147b0c andseq r10, pc, r12, lsl #5
 *   @0x147b10 .word 0x002a61f8
 *
 * ══ §108/251 F_GPUSetTexMipEnableExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x149e68  size 120  30 条（0x149e68..0x149ee0）
 * @func 0x149e68 0x149ee0  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x44×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x149e68 cmp r3, #2
 *   @0x149e6c mov r3, #0
 *   @0x149e70 push {r4, r5, r6, lr}
 *   @0x149e74 mov r1, r3
 *   @0x149e78 ldr r4, [sp, #0x10]
 *   @0x149e7c movt r3, #0xbff0
 *   @0x149e80 str r1, [r0, #0xc]
 *   @0x149e84 stm r0, {r1, r3}
 *   @0x149e88 beq 0x149e9c <_Z23F_GPUSetTexMipEnableExtR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x149e8c ldr r0, [pc, #0x44]
 *   @0x149e90 pop {r4, r5, r6, lr}
 *   @0x149e94 add r0, pc, r0
 *   @0x149e98 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x149e9c mov r0, r4
 *   @0x149ea0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x149ea4 mov r1, #1
 *   @0x149ea8 mov r5, r0
 *   @0x149eac mov r0, r4
 *   @0x149eb0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x149eb4 cmp r5, #7
 *   @0x149eb8 pophi {r4, r5, r6, pc}
 *   @0x149ebc ldr r12, [pc, #0x18]
 *   @0x149ec0 mov r1, r5
 *   @0x149ec4 mov r3, r0
 *   @0x149ec8 mov r2, #9
 *   @0x149ecc ldr r0, [pc, r12]
 *   @0x149ed0 pop {r4, r5, r6, lr}
 *   @0x149ed4 b 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x149ed8 mulseq pc, r12, r11
 *   @0x149edc eoreq r3, r10, r12, lsr #28
 *
 * ══ §109/251 F_PhysicsGetFriction(RValue&, CInstance*, CInstance*, int, RValue*)  0x14bfa4  size 120  30 条（0x14bfa4..0x14c01c）
 * @func 0x14bfa4 0x14c030  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CPhysicsObject::GetFriction(int)
 * 字段偏移 top8: 0xc×2 / 0x4×1 / 0x84×1 / 0x10×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14bfa4 mov r2, #0
 *   @0x14bfa8 push {r3, r4, r5, lr}
 *   @0x14bfac mov r3, r2
 *   @0x14bfb0 movt r2, #0xbff0
 *   @0x14bfb4 str r3, [r0]
 *   @0x14bfb8 str r2, [r0, #0x4]
 *   @0x14bfbc mov r4, r0
 *   @0x14bfc0 ldr r5, [r1, #0x84]
 *   @0x14bfc4 str r3, [r0, #0xc]
 *   @0x14bfc8 cmp r5, r3
 *   @0x14bfcc ldr r0, [sp, #0x10]
 *   @0x14bfd0 beq 0x14c004 <_Z20F_PhysicsGetFrictionR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x14bfd4 mov r1, r3
 *   @0x14bfd8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14bfdc mov r1, r0
 *   @0x14bfe0 mov r0, r5
 *   @0x14bfe4 bl 0x2378d0 <_ZN14CPhysicsObject11GetFrictionEi>
 *   @0x14bfe8 vmov s15, r0
 *   @0x14bfec vcvt.f64.f32 d7, s15
 *   @0x14bff0 vmov r0, r1, d7
 *   @0x14bff4 vmov r2, s14
 *   @0x14bff8 mov r3, r1
 *   @0x14bffc stm r4, {r2, r3}
 *   @0x14c000 pop {r3, r4, r5, pc}
 *   @0x14c004 ldr r0, [pc, #0xc]
 *   @0x14c008 mov r1, r5
 *   @0x14c00c pop {r3, r4, r5, lr}
 *   @0x14c010 add r0, pc, r0
 *   @0x14c014 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14c018 ldrsbeq r7, [pc], -r4
 *
 * ══ §110/251 F_PhysicsGetDensity(RValue&, CInstance*, CInstance*, int, RValue*)  0x14c01c  size 120  30 条（0x14c01c..0x14c094）
 * @func 0x14c01c 0x14c0a8  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CPhysicsObject::GetDensity(int)
 * 字段偏移 top8: 0xc×2 / 0x4×1 / 0x84×1 / 0x10×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14c01c mov r2, #0
 *   @0x14c020 push {r3, r4, r5, lr}
 *   @0x14c024 mov r3, r2
 *   @0x14c028 movt r2, #0xbff0
 *   @0x14c02c str r3, [r0]
 *   @0x14c030 str r2, [r0, #0x4]
 *   @0x14c034 mov r4, r0
 *   @0x14c038 ldr r5, [r1, #0x84]
 *   @0x14c03c str r3, [r0, #0xc]
 *   @0x14c040 cmp r5, r3
 *   @0x14c044 ldr r0, [sp, #0x10]
 *   @0x14c048 beq 0x14c07c <_Z19F_PhysicsGetDensityR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x14c04c mov r1, r3
 *   @0x14c050 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14c054 mov r1, r0
 *   @0x14c058 mov r0, r5
 *   @0x14c05c bl 0x237924 <_ZN14CPhysicsObject10GetDensityEi>
 *   @0x14c060 vmov s15, r0
 *   @0x14c064 vcvt.f64.f32 d7, s15
 *   @0x14c068 vmov r0, r1, d7
 *   @0x14c06c vmov r2, s14
 *   @0x14c070 mov r3, r1
 *   @0x14c074 stm r4, {r2, r3}
 *   @0x14c078 pop {r3, r4, r5, pc}
 *   @0x14c07c ldr r0, [pc, #0xc]
 *   @0x14c080 mov r1, r5
 *   @0x14c084 pop {r3, r4, r5, lr}
 *   @0x14c088 add r0, pc, r0
 *   @0x14c08c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14c090 andseq r7, pc, r12, asr sp
 *
 * ══ §111/251 F_PhysicsGetRestitution(RValue&, CInstance*, CInstance*, int, RValue*)  0x14c094  size 120  30 条（0x14c094..0x14c10c）
 * @func 0x14c094 0x14c10c  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CPhysicsObject::GetRestitution(int)
 * 字段偏移 top8: 0xc×2 / 0x4×1 / 0x84×1 / 0x10×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14c094 mov r2, #0
 *   @0x14c098 push {r3, r4, r5, lr}
 *   @0x14c09c mov r3, r2
 *   @0x14c0a0 movt r2, #0xbff0
 *   @0x14c0a4 str r3, [r0]
 *   @0x14c0a8 str r2, [r0, #0x4]
 *   @0x14c0ac mov r4, r0
 *   @0x14c0b0 ldr r5, [r1, #0x84]
 *   @0x14c0b4 str r3, [r0, #0xc]
 *   @0x14c0b8 cmp r5, r3
 *   @0x14c0bc ldr r0, [sp, #0x10]
 *   @0x14c0c0 beq 0x14c0f4 <_Z23F_PhysicsGetRestitutionR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x14c0c4 mov r1, r3
 *   @0x14c0c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14c0cc mov r1, r0
 *   @0x14c0d0 mov r0, r5
 *   @0x14c0d4 bl 0x237978 <_ZN14CPhysicsObject14GetRestitutionEi>
 *   @0x14c0d8 vmov s15, r0
 *   @0x14c0dc vcvt.f64.f32 d7, s15
 *   @0x14c0e0 vmov r0, r1, d7
 *   @0x14c0e4 vmov r2, s14
 *   @0x14c0e8 mov r3, r1
 *   @0x14c0ec stm r4, {r2, r3}
 *   @0x14c0f0 pop {r3, r4, r5, pc}
 *   @0x14c0f4 ldr r0, [pc, #0xc]
 *   @0x14c0f8 mov r1, r5
 *   @0x14c0fc pop {r3, r4, r5, lr}
 *   @0x14c100 add r0, pc, r0
 *   @0x14c104 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14c108 andseq r7, pc, r4, ror #25
 *
 * ══ §112/251 F_PhysicsPause(RValue&, CInstance*, CInstance*, int, RValue*)  0x14d1a8  size 120  30 条（0x14d1a8..0x14d220）
 * @func 0x14d1a8 0x14d220  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x64×3 / 0xb4×3 / 0x8×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14d1a8 push {r4, lr}
 *   @0x14d1ac ldr r4, [pc, #0x64]
 *   @0x14d1b0 ldr r0, [sp, #0x8]
 *   @0x14d1b4 ldr r4, [pc, r4]
 *   @0x14d1b8 ldr r3, [r4]
 *   @0x14d1bc cmp r3, #0
 *   @0x14d1c0 beq 0x14d204 <_Z14F_PhysicsPauseR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x14d1c4 ldr r3, [r3, #0xb4]
 *   @0x14d1c8 cmp r3, #0
 *   @0x14d1cc beq 0x14d204 <_Z14F_PhysicsPauseR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x14d1d0 mov r1, #0
 *   @0x14d1d4 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x14d1d8 cmp r0, #0
 *   @0x14d1dc beq 0x14d1f4 <_Z14F_PhysicsPauseR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x14d1e0 ldr r3, [r4]
 *   @0x14d1e4 mov r2, #1
 *   @0x14d1e8 ldr r3, [r3, #0xb4]
 *   @0x14d1ec strb r2, [r3, #0x64]
 *   @0x14d1f0 pop {r4, pc}
 *   @0x14d1f4 ldr r3, [r4]
 *   @0x14d1f8 ldr r3, [r3, #0xb4]
 *   @0x14d1fc strb r0, [r3, #0x64]
 *   @0x14d200 pop {r4, pc}
 *   @0x14d204 ldr r0, [pc, #0x10]
 *   @0x14d208 mov r1, #0
 *   @0x14d20c pop {r4, lr}
 *   @0x14d210 add r0, pc, r0
 *   @0x14d214 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14d218 eoreq r0, r10, r4, ror r7
 *   @0x14d21c andseq r6, pc, r0, lsr sp
 *
 * ══ §113/251 F_GamepadConnected(RValue&, CInstance*, CInstance*, int, RValue*)  0x15126c  size 120  30 条（0x15126c..0x1512e4）
 * @func 0x15126c 0x1512e4  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x4×2 / 0xc×1 / 0x10×1 / 0x3c×1 / 0x2c×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15126c push {r3, r4, r5, lr}
 *   @0x151270 mov r5, #0
 *   @0x151274 mov r4, r0
 *   @0x151278 str r5, [r0, #0xc]
 *   @0x15127c str r5, [r0]
 *   @0x151280 mov r1, r5
 *   @0x151284 str r5, [r0, #0x4]
 *   @0x151288 ldr r0, [sp, #0x10]
 *   @0x15128c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x151290 cmp r0, #0
 *   @0x151294 poplt {r3, r4, r5, pc}
 *   @0x151298 ldr r3, [pc, #0x3c]
 *   @0x15129c ldr r3, [pc, r3]
 *   @0x1512a0 ldr r3, [r3]
 *   @0x1512a4 cmp r0, r3
 *   @0x1512a8 popge {r3, r4, r5, pc}
 *   @0x1512ac ldr r3, [pc, #0x2c]
 *   @0x1512b0 ldr r3, [pc, r3]
 *   @0x1512b4 ldr r3, [r3]
 *   @0x1512b8 ldr r3, [r3, r0, lsl #2]
 *   @0x1512bc ldrb r3, [r3]
 *   @0x1512c0 cmp r3, #0
 *   @0x1512c4 movne r3, #0
 *   @0x1512c8 movtne r3, #0x3ff0
 *   @0x1512cc moveq r5, r3
 *   @0x1512d0 str r5, [r4]
 *   @0x1512d4 str r3, [r4, #0x4]
 *   @0x1512d8 pop {r3, r4, r5, pc}
 *   @0x1512dc eoreq lr, r9, r4, asr #15
 *   @0x1512e0 .word 0x0029e7b4
 *
 * ══ §114/251 F_GamepadButtonCount(RValue&, CInstance*, CInstance*, int, RValue*)  0x151424  size 120  30 条（0x151424..0x15149c）
 * @func 0x151424 0x15149c  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / GMGamePad::ButtonCount() const
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x8×1 / 0x3c×1 / 0x2c×1 / 0x2×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x151424 push {r4, lr}
 *   @0x151428 mov r3, #0
 *   @0x15142c mov r4, r0
 *   @0x151430 str r3, [r0, #0xc]
 *   @0x151434 str r3, [r0]
 *   @0x151438 mov r1, r3
 *   @0x15143c str r3, [r0, #0x4]
 *   @0x151440 ldr r0, [sp, #0x8]
 *   @0x151444 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x151448 cmp r0, #0
 *   @0x15144c poplt {r4, pc}
 *   @0x151450 ldr r3, [pc, #0x3c]
 *   @0x151454 ldr r3, [pc, r3]
 *   @0x151458 ldr r3, [r3]
 *   @0x15145c cmp r0, r3
 *   @0x151460 popge {r4, pc}
 *   @0x151464 ldr r3, [pc, #0x2c]
 *   @0x151468 ldr r3, [pc, r3]
 *   @0x15146c ldr r3, [r3]
 *   @0x151470 ldr r0, [r3, r0, lsl #2]
 *   @0x151474 bl 0x18ead0 <_ZNK9GMGamePad11ButtonCountEv>
 *   @0x151478 vmov s15, r0
 *   @0x15147c vcvt.f64.s32 d7, s15
 *   @0x151480 vmov r0, r1, d7
 *   @0x151484 vmov r2, s14
 *   @0x151488 mov r3, r1
 *   @0x15148c stm r4, {r2, r3}
 *   @0x151490 pop {r4, pc}
 *   @0x151494 eoreq lr, r9, r12, lsl #12
 *   @0x151498 .word 0x0029e5fc
 *
 * ══ §115/251 F_GamepadAxisCount(RValue&, CInstance*, CInstance*, int, RValue*)  0x151724  size 120  30 条（0x151724..0x15179c）
 * @func 0x151724 0x15179c  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / GMGamePad::AxisCount() const
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x8×1 / 0x3c×1 / 0x2c×1 / 0x2×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x151724 push {r4, lr}
 *   @0x151728 mov r3, #0
 *   @0x15172c mov r4, r0
 *   @0x151730 str r3, [r0, #0xc]
 *   @0x151734 str r3, [r0]
 *   @0x151738 mov r1, r3
 *   @0x15173c str r3, [r0, #0x4]
 *   @0x151740 ldr r0, [sp, #0x8]
 *   @0x151744 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x151748 cmp r0, #0
 *   @0x15174c poplt {r4, pc}
 *   @0x151750 ldr r3, [pc, #0x3c]
 *   @0x151754 ldr r3, [pc, r3]
 *   @0x151758 ldr r3, [r3]
 *   @0x15175c cmp r0, r3
 *   @0x151760 popge {r4, pc}
 *   @0x151764 ldr r3, [pc, #0x2c]
 *   @0x151768 ldr r3, [pc, r3]
 *   @0x15176c ldr r3, [r3]
 *   @0x151770 ldr r0, [r3, r0, lsl #2]
 *   @0x151774 bl 0x18ed88 <_ZNK9GMGamePad9AxisCountEv>
 *   @0x151778 vmov s15, r0
 *   @0x15177c vcvt.f64.s32 d7, s15
 *   @0x151780 vmov r0, r1, d7
 *   @0x151784 vmov r2, s14
 *   @0x151788 mov r3, r1
 *   @0x15178c stm r4, {r2, r3}
 *   @0x151790 pop {r4, pc}
 *   @0x151794 eoreq lr, r9, r12, lsl #6
 *   @0x151798 .word 0x0029e2fc
 *
 * ══ §116/251 YYIAPStoreLoadEvent(int)  0x155630  size 120  30 条（0x155630..0x1556a8）
 * @func 0x155630 0x1556bc  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Mutex::Lock() / anon_154a70 / anon_153020+0x1ac
 * 字段偏移 top8: 0x5c×1 / 0x48×1 / 0x40×1 / 0x10×1 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x155630 push {r4, r5, lr}
 *   @0x155634 mov r5, r0
 *   @0x155638 ldr r4, [pc, #0x5c]
 *   @0x15563c sub sp, sp, #28
 *   @0x155640 add r4, pc, r4
 *   @0x155644 ldr r0, [r4]
 *   @0x155648 bl 0x27e084 <_ZN5Mutex4LockEv>
 *   @0x15564c vmov s13, r5
 *   @0x155650 ldr r2, [pc, #0x48]
 *   @0x155654 mov r3, #0
 *   @0x155658 vcvt.f64.s32 d7, s13
 *   @0x15565c ldr r1, [pc, #0x40]
 *   @0x155660 str r3, [sp]
 *   @0x155664 add r2, pc, r2
 *   @0x155668 str r3, [sp, #0x10]
 *   @0x15566c add r1, pc, r1
 *   @0x155670 str r2, [sp, #0x4]
 *   @0x155674 mov r3, #0
 *   @0x155678 mov r2, #0
 *   @0x15567c mov r0, #2
 *   @0x155680 vstr d7, [sp, #8]
 *   @0x155684 bl 0x154a70 <_Z19YYIAPEventsDispatchv+0xe88>
 *   @0x155688 bl 0x1531cc <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x1d8>
 *   @0x15568c ldr r0, [r4]
 *   @0x155690 add sp, sp, #28
 *   @0x155694 pop {r4, r5, lr}
 *   @0x155698 b 0x27e09c <_ZN5Mutex6UnlockEv>
 *   @0x15569c eorseq pc, r2, r0, lsl #8
 *   @0x1556a0 andseq r11, sp, r12, ror #7
 *   @0x1556a4 ldrheq r0, [pc], -r12
 *
 * ══ §117/251 F_YoYo_OF_AddLeaderboard(RValue&, CInstance*, CInstance*, int, RValue*)  0x159464  size 120  30 条（0x159464..0x1594dc）
 * @func 0x159464 0x1594dc  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)×4 / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x159464 push {r4, r5, r6, lr}
 *   @0x159468 cmp r3, #3
 *   @0x15946c ldr r4, [sp, #0x10]
 *   @0x159470 mov r1, #0
 *   @0x159474 mov r0, r4
 *   @0x159478 beq 0x1594a4 <_Z24F_YoYo_OF_AddLeaderboardR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x15947c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x159480 mov r1, #1
 *   @0x159484 mov r5, r0
 *   @0x159488 mov r0, r4
 *   @0x15948c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x159490 mov r2, #1
 *   @0x159494 mov r1, r0
 *   @0x159498 mov r0, r5
 *   @0x15949c pop {r4, r5, r6, lr}
 *   @0x1594a0 b 0x1616dc <_Z22YoYo_OF_AddLeaderboardPKcS0_16eLeaderboardType>
 *   @0x1594a4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1594a8 mov r1, #1
 *   @0x1594ac mov r6, r0
 *   @0x1594b0 mov r0, r4
 *   @0x1594b4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1594b8 mov r1, #2
 *   @0x1594bc mov r5, r0
 *   @0x1594c0 mov r0, r4
 *   @0x1594c4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1594c8 mov r1, r5
 *   @0x1594cc mov r2, r0
 *   @0x1594d0 mov r0, r6
 *   @0x1594d4 pop {r4, r5, r6, lr}
 *   @0x1594d8 b 0x1616dc <_Z22YoYo_OF_AddLeaderboardPKcS0_16eLeaderboardType>
 *
 * ══ §118/251 CCamera::GetCamRight()  0x16d8c4  size 120  30 条（0x16d8c4..0x16d93c）
 * @func 0x16d8c4 0x16d93c  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6700
 * 字段偏移 top8: 无
 * VFP 指令 23 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d8c4 vldr s15, [r1, #100]
 *   @0x16d8c8 vmul.f32 s14, s15, s15
 *   @0x16d8cc push {r4, lr}
 *   @0x16d8d0 vstr s15, [r0]
 *   @0x16d8d4 vstr s15, [r0, #4]
 *   @0x16d8d8 vstr s15, [r0, #8]
 *   @0x16d8dc mov r4, r0
 *   @0x16d8e0 vadd.f32 s15, s14, s14
 *   @0x16d8e4 vadd.f32 s14, s14, s15
 *   @0x16d8e8 vsqrt.f32 s15, s14
 *   @0x16d8ec vcmp.f32 s15, s15
 *   @0x16d8f0 vmrs APSR_nzcv, fpscr
 *   @0x16d8f4 bne 0x16d92c <_ZN7CCamera11GetCamRightEv+0x68>
 *   @0x16d8f8 vmov.f32 s11, #1.000000e+00
 *   @0x16d8fc vldr s12, [r4]
 *   @0x16d900 vldr s14, [r4, #4]
 *   @0x16d904 vldr s13, [r4, #8]
 *   @0x16d908 mov r0, r4
 *   @0x16d90c vdiv.f32 s15, s11, s15
 *   @0x16d910 vmul.f32 s12, s12, s15
 *   @0x16d914 vmul.f32 s14, s14, s15
 *   @0x16d918 vstr s12, [r4]
 *   @0x16d91c vmul.f32 s15, s13, s15
 *   @0x16d920 vstr s14, [r4, #4]
 *   @0x16d924 vstr s15, [r4, #8]
 *   @0x16d928 pop {r4, pc}
 *   @0x16d92c vmov r0, s14
 *   @0x16d930 bl 0xb6700 <sqrtf@plt>
 *   @0x16d934 vmov s15, r0
 *   @0x16d938 b 0x16d8f8 <_ZN7CCamera11GetCamRightEv+0x34>
 *
 * ══ §119/251 F_CameraSetViewTarget(RValue&, CInstance*, CInstance*, int, RValue*)  0x16f77c  size 120  30 条（0x16f77c..0x16f7f4）
 * @func 0x16f77c 0x16f808  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / CCameraManager::GetCamera(int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x44×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16f77c cmp r3, #2
 *   @0x16f780 push {r3, r4, r5, lr}
 *   @0x16f784 mov r3, #0
 *   @0x16f788 mov r1, r3
 *   @0x16f78c ldr r4, [sp, #0x10]
 *   @0x16f790 movt r3, #0xbff0
 *   @0x16f794 str r1, [r0, #0xc]
 *   @0x16f798 stm r0, {r1, r3}
 *   @0x16f79c beq 0x16f7b0 <_Z21F_CameraSetViewTargetR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x16f7a0 ldr r0, [pc, #0x44]
 *   @0x16f7a4 pop {r3, r4, r5, lr}
 *   @0x16f7a8 add r0, pc, r0
 *   @0x16f7ac b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x16f7b0 mov r0, r4
 *   @0x16f7b4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16f7b8 ldr r3, [pc, #0x30]
 *   @0x16f7bc mov r1, r0
 *   @0x16f7c0 ldr r0, [pc, r3]
 *   @0x16f7c4 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi>
 *   @0x16f7c8 subs r5, r0, #0
 *   @0x16f7cc popeq {r3, r4, r5, pc}
 *   @0x16f7d0 mov r0, r4
 *   @0x16f7d4 mov r1, #1
 *   @0x16f7d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16f7dc mov r1, r0
 *   @0x16f7e0 mov r0, r5
 *   @0x16f7e4 pop {r3, r4, r5, lr}
 *   @0x16f7e8 b 0x16d32c <_ZN7CCamera17SetTargetInstanceEi>
 *   @0x16f7ec mulseq sp, r4, r6
 *   @0x16f7f0 .word 0x0027e4b4
 *
 * ══ §120/251 F_CameraSetUpdateScript(RValue&, CInstance*, CInstance*, int, RValue*)  0x16f7f4  size 120  30 条（0x16f7f4..0x16f86c）
 * @func 0x16f7f4 0x16f880  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / CCameraManager::GetCamera(int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x44×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16f7f4 cmp r3, #2
 *   @0x16f7f8 push {r3, r4, r5, lr}
 *   @0x16f7fc mov r3, #0
 *   @0x16f800 mov r1, r3
 *   @0x16f804 ldr r4, [sp, #0x10]
 *   @0x16f808 movt r3, #0xbff0
 *   @0x16f80c str r1, [r0, #0xc]
 *   @0x16f810 stm r0, {r1, r3}
 *   @0x16f814 beq 0x16f828 <_Z23F_CameraSetUpdateScriptR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x16f818 ldr r0, [pc, #0x44]
 *   @0x16f81c pop {r3, r4, r5, lr}
 *   @0x16f820 add r0, pc, r0
 *   @0x16f824 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x16f828 mov r0, r4
 *   @0x16f82c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16f830 ldr r3, [pc, #0x30]
 *   @0x16f834 mov r1, r0
 *   @0x16f838 ldr r0, [pc, r3]
 *   @0x16f83c bl 0x16f45c <_ZN14CCameraManager9GetCameraEi>
 *   @0x16f840 subs r5, r0, #0
 *   @0x16f844 popeq {r3, r4, r5, pc}
 *   @0x16f848 mov r0, r4
 *   @0x16f84c mov r1, #1
 *   @0x16f850 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16f854 mov r1, r0
 *   @0x16f858 mov r0, r5
 *   @0x16f85c pop {r3, r4, r5, lr}
 *   @0x16f860 b 0x16d35c <_ZN7CCamera15SetUpdateScriptEi>
 *   @0x16f864 andseq r11, sp, r4, asr r6
 *   @0x16f868 eoreq lr, r7, r12, lsr r4
 *
 * ══ §121/251 F_CameraSetBeginScript(RValue&, CInstance*, CInstance*, int, RValue*)  0x16f86c  size 120  30 条（0x16f86c..0x16f8e4）
 * @func 0x16f86c 0x16f8f8  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / CCameraManager::GetCamera(int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x44×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16f86c cmp r3, #2
 *   @0x16f870 push {r3, r4, r5, lr}
 *   @0x16f874 mov r3, #0
 *   @0x16f878 mov r1, r3
 *   @0x16f87c ldr r4, [sp, #0x10]
 *   @0x16f880 movt r3, #0xbff0
 *   @0x16f884 str r1, [r0, #0xc]
 *   @0x16f888 stm r0, {r1, r3}
 *   @0x16f88c beq 0x16f8a0 <_Z22F_CameraSetBeginScriptR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x16f890 ldr r0, [pc, #0x44]
 *   @0x16f894 pop {r3, r4, r5, lr}
 *   @0x16f898 add r0, pc, r0
 *   @0x16f89c b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x16f8a0 mov r0, r4
 *   @0x16f8a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16f8a8 ldr r3, [pc, #0x30]
 *   @0x16f8ac mov r1, r0
 *   @0x16f8b0 ldr r0, [pc, r3]
 *   @0x16f8b4 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi>
 *   @0x16f8b8 subs r5, r0, #0
 *   @0x16f8bc popeq {r3, r4, r5, pc}
 *   @0x16f8c0 mov r0, r4
 *   @0x16f8c4 mov r1, #1
 *   @0x16f8c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16f8cc mov r1, r0
 *   @0x16f8d0 mov r0, r5
 *   @0x16f8d4 pop {r3, r4, r5, lr}
 *   @0x16f8d8 b 0x16d33c <_ZN7CCamera14SetBeginScriptEi>
 *   @0x16f8dc andseq r11, sp, r4, lsl r6
 *   @0x16f8e0 eoreq lr, r7, r4, asr #7
 *
 * ══ §122/251 F_CameraSetEndScript(RValue&, CInstance*, CInstance*, int, RValue*)  0x16f8e4  size 120  30 条（0x16f8e4..0x16f95c）
 * @func 0x16f8e4 0x16f95c  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / CCameraManager::GetCamera(int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x44×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16f8e4 cmp r3, #2
 *   @0x16f8e8 push {r3, r4, r5, lr}
 *   @0x16f8ec mov r3, #0
 *   @0x16f8f0 mov r1, r3
 *   @0x16f8f4 ldr r4, [sp, #0x10]
 *   @0x16f8f8 movt r3, #0xbff0
 *   @0x16f8fc str r1, [r0, #0xc]
 *   @0x16f900 stm r0, {r1, r3}
 *   @0x16f904 beq 0x16f918 <_Z20F_CameraSetEndScriptR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x16f908 ldr r0, [pc, #0x44]
 *   @0x16f90c pop {r3, r4, r5, lr}
 *   @0x16f910 add r0, pc, r0
 *   @0x16f914 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x16f918 mov r0, r4
 *   @0x16f91c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16f920 ldr r3, [pc, #0x30]
 *   @0x16f924 mov r1, r0
 *   @0x16f928 ldr r0, [pc, r3]
 *   @0x16f92c bl 0x16f45c <_ZN14CCameraManager9GetCameraEi>
 *   @0x16f930 subs r5, r0, #0
 *   @0x16f934 popeq {r3, r4, r5, pc}
 *   @0x16f938 mov r0, r4
 *   @0x16f93c mov r1, #1
 *   @0x16f940 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16f944 mov r1, r0
 *   @0x16f948 mov r0, r5
 *   @0x16f94c pop {r3, r4, r5, lr}
 *   @0x16f950 b 0x16d34c <_ZN7CCamera12SetEndScriptEi>
 *   @0x16f954 ldrsbeq r11, [sp], -r4
 *   @0x16f958 eoreq lr, r7, r12, asr #6
 *
 * ══ §123/251 GR_Text_ResetToDefault()  0x173884  size 120  30 条（0x173884..0x1738fc）
 * @func 0x173884 0x1738fc  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x17388c→0x3f2410, 0x1738a8→0x48ffd0, 0x1738ac→0x48ffcc, 0x1738b8→0x3f23d0, 0x1738bc→0x3f23cc
 * 调用序列: 无
 * 字段偏移 top8: 0x3c×2 / 0x34×2 / 0x58×1 / 0x54×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x173884 ldr r3, [pc, #0x58]
 *   @0x173888 mov r2, #0
 *   @0x17388c ldr r0, [pc, #0x54]
 *   @0x173890 mov r12, #-16777216
 *   @0x173894 add r3, pc, r3
 *   @0x173898 mov r1, #255
 *   @0x17389c push {r4, r5, r6, r7, r8}
 *   @0x1738a0 mvn r8, #0
 *   @0x1738a4 ldr r7, [r3, r0]
 *   @0x1738a8 ldr r6, [pc, #0x3c]
 *   @0x1738ac ldr r5, [pc, #0x3c]
 *   @0x1738b0 str r8, [r7]
 *   @0x1738b4 ldr r6, [r3, r6]
 *   @0x1738b8 ldr r4, [pc, #0x34]
 *   @0x1738bc ldr r0, [pc, #0x34]
 *   @0x1738c0 str r2, [r6]
 *   @0x1738c4 ldr r5, [r3, r5]
 *   @0x1738c8 str r2, [r5]
 *   @0x1738cc ldr r2, [r3, r4]
 *   @0x1738d0 pop {r4, r5, r6, r7, r8}
 *   @0x1738d4 str r12, [r2]
 *   @0x1738d8 ldr r3, [r3, r0]
 *   @0x1738dc str r1, [r3]
 *   @0x1738e0 bx lr
 *   @0x1738e4 .word 0x0027e3bc
 *   @0x1738e8 .word 0xffffe650
 *   @0x1738ec .word 0xffffe658
 *   @0x1738f0 .word 0xffffe65c
 *   @0x1738f4 .word 0xffffc0ac
 *   @0x1738f8 .word 0xffffc0b0
 *
 * ══ §124/251 GraphicsPerf::coprintf(float, unsigned int, unsigned int, char const*, ...)  0x17c9b8  size 120  30 条（0x17c9b8..0x17ca30）
 * @func 0x17c9b8 0x17ca30  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GraphicsPerf::strwidth(char const*, int) / GraphicsPerf::oprintf(float, float, unsigned int, unsigned int, char const*, ...)
 * 字段偏移 top8: 0x-4×1 / 0x1c×1 / 0x44×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17c9b8 str r3, [sp, #-0x4]!
 *   @0x17c9bc push {r4, r5, r6, r7, lr}
 *   @0x17c9c0 sub sp, sp, #8
 *   @0x17c9c4 mov r7, r0
 *   @0x17c9c8 mov r6, r1
 *   @0x17c9cc ldr r4, [sp, #0x1c]
 *   @0x17c9d0 mvn r1, #-2147483648
 *   @0x17c9d4 mov r5, r2
 *   @0x17c9d8 mov r0, r4
 *   @0x17c9dc bl 0x17c49c <_ZN12GraphicsPerf8strwidthEPKci>
 *   @0x17c9e0 ldr r12, [pc, #0x44]
 *   @0x17c9e4 mov r1, r7
 *   @0x17c9e8 mov r2, r6
 *   @0x17c9ec ldr r12, [pc, r12]
 *   @0x17c9f0 mov r3, r5
 *   @0x17c9f4 ldr r12, [r12]
 *   @0x17c9f8 str r4, [sp]
 *   @0x17c9fc add r12, r12, #1
 *   @0x17ca00 rsb r0, r0, r12
 *   @0x17ca04 add r0, r0, r0, lsr #31
 *   @0x17ca08 asr r0, r0, #1
 *   @0x17ca0c vmov s15, r0
 *   @0x17ca10 vcvt.f32.s32 s15, s15
 *   @0x17ca14 vmov r0, s15
 *   @0x17ca18 bl 0x17c2f8 <_ZN12GraphicsPerf7oprintfEffjjPKcz>
 *   @0x17ca1c add sp, sp, #8
 *   @0x17ca20 pop {r4, r5, r6, r7, lr}
 *   @0x17ca24 add sp, sp, #4
 *   @0x17ca28 bx lr
 *   @0x17ca2c .word 0x002734b0
 *
 * ══ §125/251 SetupErrorString(char**, char*)  0x186544  size 120  30 条（0x186544..0x1865bc）
 * @func 0x186544 0x1865bc  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538 / MemoryManager::Alloc(unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x4c×1 / 0x48×1 / 0xc×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x186544 cmp r1, #0
 *   @0x186548 cmpne r0, #0
 *   @0x18654c push {r3, r4, r5, lr}
 *   @0x186550 mov r5, r0
 *   @0x186554 mov r4, r1
 *   @0x186558 popeq {r3, r4, r5, pc}
 *   @0x18655c ldr r3, [pc, #0x4c]
 *   @0x186560 mov r2, r1
 *   @0x186564 ldr r1, [pc, #0x48]
 *   @0x186568 ldr r3, [pc, r3]
 *   @0x18656c add r1, pc, r1
 *   @0x186570 ldr r0, [r3]
 *   @0x186574 ldr r3, [r0]
 *   @0x186578 ldr r3, [r3, #0xc]
 *   @0x18657c blx r3
 *   @0x186580 mov r0, r4
 *   @0x186584 bl 0xb6538 <strlen@plt>
 *   @0x186588 ldr r1, [pc, #0x28]
 *   @0x18658c mov r3, #1
 *   @0x186590 mov r2, #70
 *   @0x186594 add r1, pc, r1
 *   @0x186598 add r0, r0, r3
 *   @0x18659c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1865a0 mov r1, r4
 *   @0x1865a4 str r0, [r5]
 *   @0x1865a8 pop {r3, r4, r5, lr}
 *   @0x1865ac b 0xb65a4 <strcpy@plt>
 *   @0x1865b0 eoreq r7, r6, r12, lsr #3
 *   @0x1865b4 andseq r5, r12, r12, ror r6
 *   @0x1865b8 mulseq r10, r12, r10
 *
 * ══ §126/251 GMGamePad::GetButtonValueFromAxis(int, float*) const  0x18eae4  size 120  30 条（0x18eae4..0x18eb5c）
 * @func 0x18eae4 0x18eb70  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 17 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18eae4 tst r1, #16384
 *   @0x18eae8 biceq r1, r1, #4096
 *   @0x18eaec bicne r1, r1, #20480
 *   @0x18eaf0 tst r1, #8192
 *   @0x18eaf4 beq 0x18eb24 <_ZNK9GMGamePad22GetButtonValueFromAxisEiPf+0x40>
 *   @0x18eaf8 vldr s14, [r0, #32]
 *   @0x18eafc vneg.f32 s14, s14
 *   @0x18eb00 bic r1, r1, #8192
 *   @0x18eb04 add r2, r2, r1, lsl #2
 *   @0x18eb08 vldr s15, [r2]
 *   @0x18eb0c vcmpe.f32 s15, s14
 *   @0x18eb10 vmrs APSR_nzcv, fpscr
 *   @0x18eb14 vabsmi.f32 s15, s15
 *   @0x18eb18 bpl 0x18eb4c <_ZNK9GMGamePad22GetButtonValueFromAxisEiPf+0x68>
 *   @0x18eb1c vmov r0, s15
 *   @0x18eb20 bx lr
 *   @0x18eb24 vldr s13, [r0, #32]
 *   @0x18eb28 vneg.f32 s13, s13
 *   @0x18eb2c add r1, r2, r1, lsl #2
 *   @0x18eb30 vldr s15, [r1]
 *   @0x18eb34 vldr s14, [pc, #28]
 *   @0x18eb38 vcmpe.f32 s15, s13
 *   @0x18eb3c vmrs APSR_nzcv, fpscr
 *   @0x18eb40 vmovle.f32 s15, s14
 *   @0x18eb44 vmov r0, s15
 *   @0x18eb48 bx lr
 *   @0x18eb4c vldr s15, [pc, #4]
 *   @0x18eb50 vmov r0, s15
 *   @0x18eb54 bx lr
 *   @0x18eb58 andeq r0, r0, r0
 *
 * ══ §127/251 TranslateGamepadButtonM(int, int)  0x190acc  size 120  30 条（0x190acc..0x190b44）
 * @func 0x190acc 0x190b44  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: TranslateGamepadButtonM(int, int)+0x38 / TranslateGamepadButtonM(int, int)+0x5c
 * 字段偏移 top8: 0x48×1 / 0x1c×1 / 0x10×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x190acc cmp r1, #32768
 *   @0x190ad0 blt 0x190b04 <_Z23TranslateGamepadButtonMii+0x38>
 *   @0x190ad4 cmp r0, #0
 *   @0x190ad8 beq 0x190b0c <_Z23TranslateGamepadButtonMii+0x40>
 *   @0x190adc cmp r0, #63
 *   @0x190ae0 bgt 0x190b1c <_Z23TranslateGamepadButtonMii+0x50>
 *   @0x190ae4 add r0, r0, r0, lsl #1
 *   @0x190ae8 sub r1, r1, #32768
 *   @0x190aec ldr r3, [pc, #0x48]
 *   @0x190af0 rsb r0, r0, r0, lsl #3
 *   @0x190af4 add r1, r0, r1
 *   @0x190af8 add r3, pc, r3
 *   @0x190afc add r0, r3, r1, lsl #2
 *   @0x190b00 ldr r1, [r0, #0x1c]
 *   @0x190b04 mov r0, r1
 *   @0x190b08 bx lr
 *   @0x190b0c sub r1, r1, #32768
 *   @0x190b10 sub r1, r1, #1
 *   @0x190b14 cmp r1, #7
 *   @0x190b18 bls 0x190b28 <_Z23TranslateGamepadButtonMii+0x5c>
 *   @0x190b1c mvn r1, #0
 *   @0x190b20 mov r0, r1
 *   @0x190b24 bx lr
 *   @0x190b28 ldr r3, [pc, #0x10]
 *   @0x190b2c add r3, pc, r3
 *   @0x190b30 ldr r1, [r3, r1, lsl #2]
 *   @0x190b34 mov r0, r1
 *   @0x190b38 bx lr
 *   @0x190b3c eorseq r4, r10, r0, lsr sp
 *   @0x190b40 andseq sp, r12, r0, asr r1
 *
 * ══ §128/251 CBucket<16u, 1048576u, false>::Free(void const*)  0x190bc8  size 120  30 条（0x190bc8..0x190c40）
 * @func 0x190bc8 0x190c40  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBucket<16u, 1048576u, false>::Free(void const*)+0x30
 * 字段偏移 top8: 0x4×3 / 0x8×2 / 0x10×2 / 0xc×2 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x190bc8 ldr r3, [r0, #0x4]
 *   @0x190bcc str r4, [sp, #-0x4]!
 *   @0x190bd0 cmp r3, #0
 *   @0x190bd4 mov r4, r0
 *   @0x190bd8 beq 0x190c04 <_ZN7CBucketILj16ELj1048576ELb0EE4FreeEPKv+0x3c>
 *   @0x190bdc add r12, r3, #8
 *   @0x190be0 add r2, r3, #1048576
 *   @0x190be4 cmp r1, r12
 *   @0x190be8 add r2, r2, #8
 *   @0x190bec blo 0x190bf8 <_ZN7CBucketILj16ELj1048576ELb0EE4FreeEPKv+0x30>
 *   @0x190bf0 cmp r2, r1
 *   @0x190bf4 bhi 0x190c10 <_ZN7CBucketILj16ELj1048576ELb0EE4FreeEPKv+0x48>
 *   @0x190bf8 ldr r3, [r3]
 *   @0x190bfc cmp r3, #0
 *   @0x190c00 bne 0x190bdc <_ZN7CBucketILj16ELj1048576ELb0EE4FreeEPKv+0x14>
 *   @0x190c04 mov r0, r3
 *   @0x190c08 ldr r4, [sp], #4
 *   @0x190c0c bx lr
 *   @0x190c10 ldr r12, [r4, #0x8]
 *   @0x190c14 mov r0, #1
 *   @0x190c18 ldr r2, [r4, #0x10]
 *   @0x190c1c ldr r3, [r4, #0xc]
 *   @0x190c20 add r2, r2, r0
 *   @0x190c24 str r12, [r1]
 *   @0x190c28 sub r3, r3, #1
 *   @0x190c2c str r1, [r4, #0x8]
 *   @0x190c30 str r2, [r4, #0x10]
 *   @0x190c34 str r3, [r4, #0xc]
 *   @0x190c38 ldr r4, [sp], #4
 *   @0x190c3c bx lr
 *
 * ══ §129/251 CPath::ComputeLinear()  0x1a60dc  size 120  30 条（0x1a60dc..0x1a6154）
 * @func 0x1a60dc 0x1a6154  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPath::AddInternalPoint(float, float, float)
 * 字段偏移 top8: 0x4×4 / 0x10×2 / 0x8×2 / 0x20×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a60dc ldr r3, [r0, #0x10]
 *   @0x1a60e0 push {r4, r5, r6, lr}
 *   @0x1a60e4 mov r5, #0
 *   @0x1a60e8 cmp r3, r5
 *   @0x1a60ec mov r4, r0
 *   @0x1a60f0 str r5, [r0, #0x20]
 *   @0x1a60f4 pople {r4, r5, r6, pc}
 *   @0x1a60f8 mov r6, r5
 *   @0x1a60fc ldr r3, [r4, #0x4]
 *   @0x1a6100 mov r0, r4
 *   @0x1a6104 add r6, r6, #1
 *   @0x1a6108 add r3, r3, r5
 *   @0x1a610c add r5, r5, #12
 *   @0x1a6110 ldr r1, [r3]
 *   @0x1a6114 ldr r2, [r3, #0x4]
 *   @0x1a6118 ldr r3, [r3, #0x8]
 *   @0x1a611c bl 0x1a6068 <_ZN5CPath16AddInternalPointEfff>
 *   @0x1a6120 ldr r3, [r4, #0x10]
 *   @0x1a6124 cmp r3, r6
 *   @0x1a6128 bgt 0x1a60fc <_ZN5CPath13ComputeLinearEv+0x20>
 *   @0x1a612c ldrb r3, [r4, #0x18]
 *   @0x1a6130 cmp r3, #0
 *   @0x1a6134 popeq {r4, r5, r6, pc}
 *   @0x1a6138 ldr r3, [r4, #0x4]
 *   @0x1a613c mov r0, r4
 *   @0x1a6140 pop {r4, r5, r6, lr}
 *   @0x1a6144 ldr r1, [r3]
 *   @0x1a6148 ldr r2, [r3, #0x4]
 *   @0x1a614c ldr r3, [r3, #0x8]
 *   @0x1a6150 b 0x1a6068 <_ZN5CPath16AddInternalPointEfff>
 *
 * ══ §130/251 Room_Find(char const*)  0x1b524c  size 120  30 条（0x1b524c..0x1b52c4）
 * @func 0x1b524c 0x1b52c4  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Room_Find(char const*)+0x64 / 0xb6574
 * 字段偏移 top8: 0x64×1 / 0x4×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b524c push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x1b5250 mov r8, r0
 *   @0x1b5254 ldr r3, [pc, #0x64]
 *   @0x1b5258 add r3, pc, r3
 *   @0x1b525c ldr r6, [r3]
 *   @0x1b5260 cmp r6, #0
 *   @0x1b5264 ble 0x1b52b0 <_Z9Room_FindPKc+0x64>
 *   @0x1b5268 ldr r9, [r3, #0x4]
 *   @0x1b526c mov r4, #0
 *   @0x1b5270 ldr r7, [r3, #0xc]
 *   @0x1b5274 mov r5, r4
 *   @0x1b5278 ldr r3, [r9, r4]
 *   @0x1b527c mov r1, r8
 *   @0x1b5280 cmp r3, #0
 *   @0x1b5284 beq 0x1b52a0 <_Z9Room_FindPKc+0x54>
 *   @0x1b5288 ldr r0, [r7, r4]
 *   @0x1b528c cmp r0, #0
 *   @0x1b5290 beq 0x1b52a0 <_Z9Room_FindPKc+0x54>
 *   @0x1b5294 bl 0xb6574 <strcmp@plt>
 *   @0x1b5298 cmp r0, #0
 *   @0x1b529c beq 0x1b52b8 <_Z9Room_FindPKc+0x6c>
 *   @0x1b52a0 add r5, r5, #1
 *   @0x1b52a4 add r4, r4, #4
 *   @0x1b52a8 cmp r5, r6
 *   @0x1b52ac bne 0x1b5278 <_Z9Room_FindPKc+0x2c>
 *   @0x1b52b0 mvn r0, #0
 *   @0x1b52b4 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1b52b8 mov r0, r5
 *   @0x1b52bc pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1b52c0 eorseq sp, r8, r0, ror r3
 *
 * ══ §131/251 F_TilemapTileGetEmpty(RValue&, CInstance*, CInstance*, int, RValue*)  0x1b65e0  size 120  30 条（0x1b65e0..0x1b6658）
 * @func 0x1b65e0 0x1b6658  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x4×3 / 0xc×1 / 0x10×1 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b65e0 cmp r3, #1
 *   @0x1b65e4 push {r3, r4, r5, lr}
 *   @0x1b65e8 mov r3, #0
 *   @0x1b65ec mov r5, r3
 *   @0x1b65f0 mov r4, r0
 *   @0x1b65f4 movt r3, #0xbff0
 *   @0x1b65f8 str r5, [r0, #0xc]
 *   @0x1b65fc str r3, [r0, #0x4]
 *   @0x1b6600 str r5, [r0]
 *   @0x1b6604 ldr r0, [sp, #0x10]
 *   @0x1b6608 beq 0x1b6620 <_Z21F_TilemapTileGetEmptyR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1b660c ldr r0, [pc, #0x40]
 *   @0x1b6610 mov r1, r5
 *   @0x1b6614 pop {r3, r4, r5, lr}
 *   @0x1b6618 add r0, pc, r0
 *   @0x1b661c b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1b6620 str r5, [r4]
 *   @0x1b6624 mov r1, r5
 *   @0x1b6628 str r5, [r4, #0x4]
 *   @0x1b662c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1b6630 ubfx r0, r0, #0x0, #0x13
 *   @0x1b6634 cmp r0, #0
 *   @0x1b6638 moveq r3, #0
 *   @0x1b663c movne r3, r5
 *   @0x1b6640 movteq r3, #0x3ff0
 *   @0x1b6644 moveq r5, r0
 *   @0x1b6648 str r3, [r4, #0x4]
 *   @0x1b664c str r5, [r4]
 *   @0x1b6650 pop {r3, r4, r5, pc}
 *   @0x1b6654 andseq r6, r9, r4, ror lr
 *
 * ══ §132/251 GV_BackgroundWidth(CInstance*, int, RValue*)  0x1f9f20  size 120  30 条（0x1f9f20..0x1f9f98）
 * @func 0x1f9f20 0x1f9fac  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Background_Exists(int) / Background_Data(int) / CBackground::GetWidth()
 * 字段偏移 top8: 0x4×2 / 0x64×1 / 0xc×1 / 0x24×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f9f20 push {r3, r4, r5, lr}
 *   @0x1f9f24 cmp r1, #7
 *   @0x1f9f28 ldr r3, [pc, #0x64]
 *   @0x1f9f2c mov r4, r2
 *   @0x1f9f30 mov r2, #0
 *   @0x1f9f34 str r2, [r4]
 *   @0x1f9f38 ldr r3, [pc, r3]
 *   @0x1f9f3c movhi r1, #0
 *   @0x1f9f40 str r2, [r4, #0x4]
 *   @0x1f9f44 ldr r3, [r3]
 *   @0x1f9f48 str r2, [r4, #0xc]
 *   @0x1f9f4c add r1, r3, r1, lsl #2
 *   @0x1f9f50 ldr r3, [r1, #0x24]
 *   @0x1f9f54 ldr r5, [r3, #0x4]
 *   @0x1f9f58 mov r0, r5
 *   @0x1f9f5c bl 0xc3640 <_Z17Background_Existsi>
 *   @0x1f9f60 cmp r0, #0
 *   @0x1f9f64 beq 0x1f9f8c <_Z18GV_BackgroundWidthP9CInstanceiP6RValue+0x6c>
 *   @0x1f9f68 mov r0, r5
 *   @0x1f9f6c bl 0xc3794 <_Z15Background_Datai>
 *   @0x1f9f70 bl 0xc2d78 <_ZN11CBackground8GetWidthEv>
 *   @0x1f9f74 vmov s15, r0
 *   @0x1f9f78 vcvt.f64.s32 d7, s15
 *   @0x1f9f7c vmov r0, r1, d7
 *   @0x1f9f80 vmov r2, s14
 *   @0x1f9f84 mov r3, r1
 *   @0x1f9f88 stm r4, {r2, r3}
 *   @0x1f9f8c mov r0, #1
 *   @0x1f9f90 pop {r3, r4, r5, pc}
 *   @0x1f9f94 ldrsheq r3, [pc], -r0
 *
 * ══ §133/251 GV_BackgroundHeight(CInstance*, int, RValue*)  0x1f9f98  size 120  30 条（0x1f9f98..0x1fa010）
 * @func 0x1f9f98 0x1fa010  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Background_Exists(int) / Background_Data(int) / CBackground::GetHeight()
 * 字段偏移 top8: 0x4×2 / 0x64×1 / 0xc×1 / 0x24×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f9f98 push {r3, r4, r5, lr}
 *   @0x1f9f9c cmp r1, #7
 *   @0x1f9fa0 ldr r3, [pc, #0x64]
 *   @0x1f9fa4 mov r4, r2
 *   @0x1f9fa8 mov r2, #0
 *   @0x1f9fac str r2, [r4]
 *   @0x1f9fb0 ldr r3, [pc, r3]
 *   @0x1f9fb4 movhi r1, #0
 *   @0x1f9fb8 str r2, [r4, #0x4]
 *   @0x1f9fbc ldr r3, [r3]
 *   @0x1f9fc0 str r2, [r4, #0xc]
 *   @0x1f9fc4 add r1, r3, r1, lsl #2
 *   @0x1f9fc8 ldr r3, [r1, #0x24]
 *   @0x1f9fcc ldr r5, [r3, #0x4]
 *   @0x1f9fd0 mov r0, r5
 *   @0x1f9fd4 bl 0xc3640 <_Z17Background_Existsi>
 *   @0x1f9fd8 cmp r0, #0
 *   @0x1f9fdc beq 0x1fa004 <_Z19GV_BackgroundHeightP9CInstanceiP6RValue+0x6c>
 *   @0x1f9fe0 mov r0, r5
 *   @0x1f9fe4 bl 0xc3794 <_Z15Background_Datai>
 *   @0x1f9fe8 bl 0xc2d80 <_ZN11CBackground9GetHeightEv>
 *   @0x1f9fec vmov s15, r0
 *   @0x1f9ff0 vcvt.f64.s32 d7, s15
 *   @0x1f9ff4 vmov r0, r1, d7
 *   @0x1f9ff8 vmov r2, s14
 *   @0x1f9ffc mov r3, r1
 *   @0x1fa000 stm r4, {r2, r3}
 *   @0x1fa004 mov r0, #1
 *   @0x1fa008 pop {r3, r4, r5, pc}
 *   @0x1fa00c andseq r3, pc, r8, ror r9
 *
 * ══ §134/251 GV_RoomSpeed(CInstance*, int, RValue*)  0x1faeb0  size 120  30 条（0x1faeb0..0x1faf28）
 * @func 0x1faeb0 0x1faf28  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CTimingSource::GetFPS()
 * 字段偏移 top8: 0xc×2 / 0x64×1 / 0x44×1 / 0x18×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1faeb0 ldr r3, [pc, #0x64]
 *   @0x1faeb4 push {r4, lr}
 *   @0x1faeb8 ldr r3, [pc, r3]
 *   @0x1faebc mov r4, r2
 *   @0x1faec0 mov r2, #0
 *   @0x1faec4 ldrb r3, [r3]
 *   @0x1faec8 str r2, [r4, #0xc]
 *   @0x1faecc cmp r3, r2
 *   @0x1faed0 bne 0x1faf04 <_Z12GV_RoomSpeedP9CInstanceiP6RValue+0x54>
 *   @0x1faed4 ldr r3, [pc, #0x44]
 *   @0x1faed8 ldr r3, [pc, r3]
 *   @0x1faedc ldr r3, [r3]
 *   @0x1faee0 ldr r0, [r3, #0xc]
 *   @0x1faee4 vmov s15, r0
 *   @0x1faee8 vcvt.f64.s32 d7, s15
 *   @0x1faeec vmov r0, r1, d7
 *   @0x1faef0 mov r0, #1
 *   @0x1faef4 vmov r2, s14
 *   @0x1faef8 mov r3, r1
 *   @0x1faefc stm r4, {r2, r3}
 *   @0x1faf00 pop {r4, pc}
 *   @0x1faf04 ldr r0, [pc, #0x18]
 *   @0x1faf08 ldr r0, [pc, r0]
 *   @0x1faf0c bl 0x214808 <_ZN13CTimingSource6GetFPSEv>
 *   @0x1faf10 stm r4, {r0, r1}
 *   @0x1faf14 mov r0, #1
 *   @0x1faf18 pop {r4, pc}
 *   @0x1faf1c andseq r2, pc, r12, ror #20
 *   @0x1faf20 andseq r2, pc, r0, asr r10
 *   @0x1faf24 andseq r2, pc, r4, lsr #20
 *
 * ══ §135/251 SV_ImageBlend(CInstance*, int, RValue*)  0x1fc104  size 120  30 条（0x1fc104..0x1fc17c）
 * @func 0x1fc104 0x1fc190  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / REAL_RValue_Ex(RValue const*) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x68×1 / 0xc×1 / 0xa8×1 / 0x10×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fc104 ldr r3, [pc, #0x68]
 *   @0x1fc108 push {r4, lr}
 *   @0x1fc10c ldr r3, [pc, r3]
 *   @0x1fc110 mov r4, r0
 *   @0x1fc114 ldrb r1, [r3]
 *   @0x1fc118 cmp r1, #0
 *   @0x1fc11c beq 0x1fc160 <_Z13SV_ImageBlendP9CInstanceiP6RValue+0x5c>
 *   @0x1fc120 ldr r3, [r2, #0xc]
 *   @0x1fc124 bic r3, r3, #-16777216
 *   @0x1fc128 cmp r3, #0
 *   @0x1fc12c bne 0x1fc154 <_Z13SV_ImageBlendP9CInstanceiP6RValue+0x50>
 *   @0x1fc130 ldm r2, {r0, r1}
 *   @0x1fc134 vmov d6, r0, r1
 *   @0x1fc138 vcvt.f32.f64 s15, d6
 *   @0x1fc13c vcvt.f64.f32 d6, s15
 *   @0x1fc140 vmov r0, r1, d6
 *   @0x1fc144 bl 0xb66e8 <lrint@plt>
 *   @0x1fc148 str r0, [r4, #0xa8]
 *   @0x1fc14c mov r0, #1
 *   @0x1fc150 pop {r4, pc}
 *   @0x1fc154 mov r0, r2
 *   @0x1fc158 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fc15c b 0x1fc134 <_Z13SV_ImageBlendP9CInstanceiP6RValue+0x30>
 *   @0x1fc160 ldr r0, [pc, #0x10]
 *   @0x1fc164 add r0, pc, r0
 *   @0x1fc168 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1fc16c mov r0, #1
 *   @0x1fc170 pop {r4, pc}
 *   @0x1fc174 ldrheq r4, [pc], -r0
 *   @0x1fc178 andseq r6, r5, r8, asr r8
 *
 * ══ §136/251 SV_Layer(CInstance*, int, RValue*)  0x1fc17c  size 120  30 条（0x1fc17c..0x1fc1f4）
 * @func 0x1fc17c 0x1fc1f4  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::RemoveInstance(CRoom*, CInstance*) / CLayerManager::GetLayerFromID(CRoom*, int) / CLayerManager::AddInstanceToLayer(CRoom*, CLayer*, CInstance*) / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x64×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fc17c push {r4, r5, r6, lr}
 *   @0x1fc180 mov r1, r0
 *   @0x1fc184 ldr r4, [pc, #0x64]
 *   @0x1fc188 mov r6, r2
 *   @0x1fc18c mov r5, r0
 *   @0x1fc190 ldr r4, [pc, r4]
 *   @0x1fc194 ldr r0, [r4]
 *   @0x1fc198 bl 0x1b9e5c <_ZN13CLayerManager14RemoveInstanceEP5CRoomP9CInstance>
 *   @0x1fc19c ldr r3, [r6, #0xc]
 *   @0x1fc1a0 bic r3, r3, #-16777216
 *   @0x1fc1a4 cmp r3, #0
 *   @0x1fc1a8 bne 0x1fc1e4 <_Z8SV_LayerP9CInstanceiP6RValue+0x68>
 *   @0x1fc1ac ldm r6, {r0, r1}
 *   @0x1fc1b0 vmov d7, r0, r1
 *   @0x1fc1b4 ldr r0, [r4]
 *   @0x1fc1b8 vcvt.s32.f64 s15, d7
 *   @0x1fc1bc vmov r1, s15
 *   @0x1fc1c0 vstr s15, [r5, #368]
 *   @0x1fc1c4 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1fc1c8 subs r1, r0, #0
 *   @0x1fc1cc beq 0x1fc1dc <_Z8SV_LayerP9CInstanceiP6RValue+0x60>
 *   @0x1fc1d0 ldr r0, [r4]
 *   @0x1fc1d4 mov r2, r5
 *   @0x1fc1d8 bl 0x1c5a38 <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance>
 *   @0x1fc1dc mov r0, #1
 *   @0x1fc1e0 pop {r4, r5, r6, pc}
 *   @0x1fc1e4 mov r0, r6
 *   @0x1fc1e8 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fc1ec b 0x1fc1b0 <_Z8SV_LayerP9CInstanceiP6RValue+0x34>
 *   @0x1fc1f0 mulseq pc, r8, r7
 *
 * ══ §137/251 SV_PhysicsAngularVelocity(CInstance*, int, RValue*)  0x1fe584  size 120  30 条（0x1fe584..0x1fe5fc）
 * @func 0x1fe584 0x1fe610  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CheckPhysicsError(CInstance*, bool, bool) / CPhysicsObject::SetAngularVelocity(float) / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x84×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fe584 push {r4, r5, r6, r7, r8, lr}
 *   @0x1fe588 mov r1, #1
 *   @0x1fe58c mov r6, r2
 *   @0x1fe590 mov r2, #0
 *   @0x1fe594 mov r4, r0
 *   @0x1fe598 bl 0x1fe500 <_Z17CheckPhysicsErrorP9CInstancebb>
 *   @0x1fe59c subs r7, r0, #0
 *   @0x1fe5a0 beq 0x1fe5d8 <_Z25SV_PhysicsAngularVelocityP9CInstanceiP6RValue+0x54>
 *   @0x1fe5a4 ldr r8, [r4, #0x84]
 *   @0x1fe5a8 cmp r8, #0
 *   @0x1fe5ac beq 0x1fe5f4 <_Z25SV_PhysicsAngularVelocityP9CInstanceiP6RValue+0x70>
 *   @0x1fe5b0 ldr r3, [r6, #0xc]
 *   @0x1fe5b4 bic r3, r3, #-16777216
 *   @0x1fe5b8 cmp r3, #0
 *   @0x1fe5bc bne 0x1fe5e0 <_Z25SV_PhysicsAngularVelocityP9CInstanceiP6RValue+0x5c>
 *   @0x1fe5c0 ldm r6, {r4, r5}
 *   @0x1fe5c4 vmov d7, r4, r5
 *   @0x1fe5c8 mov r0, r8
 *   @0x1fe5cc vcvt.f32.f64 s15, d7
 *   @0x1fe5d0 vmov r1, s15
 *   @0x1fe5d4 bl 0x236f44 <_ZN14CPhysicsObject18SetAngularVelocityEf>
 *   @0x1fe5d8 mov r0, r7
 *   @0x1fe5dc pop {r4, r5, r6, r7, r8, pc}
 *   @0x1fe5e0 mov r0, r6
 *   @0x1fe5e4 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fe5e8 mov r4, r0
 *   @0x1fe5ec mov r5, r1
 *   @0x1fe5f0 b 0x1fe5c4 <_Z25SV_PhysicsAngularVelocityP9CInstanceiP6RValue+0x40>
 *   @0x1fe5f4 mov r7, r8
 *   @0x1fe5f8 b 0x1fe5d8 <_Z25SV_PhysicsAngularVelocityP9CInstanceiP6RValue+0x54>
 *
 * ══ §138/251 SV_PhysicsAngle(CInstance*, int, RValue*)  0x1fe5fc  size 120  30 条（0x1fe5fc..0x1fe674）
 * @func 0x1fe5fc 0x1fe674  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CheckPhysicsError(CInstance*, bool, bool) / CPhysicsObject::SetRotation(float) / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0x84×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fe5fc push {r4, r5, r6, r7, r8, lr}
 *   @0x1fe600 mov r1, #1
 *   @0x1fe604 mov r6, r2
 *   @0x1fe608 mov r2, #0
 *   @0x1fe60c mov r4, r0
 *   @0x1fe610 bl 0x1fe500 <_Z17CheckPhysicsErrorP9CInstancebb>
 *   @0x1fe614 subs r7, r0, #0
 *   @0x1fe618 beq 0x1fe650 <_Z15SV_PhysicsAngleP9CInstanceiP6RValue+0x54>
 *   @0x1fe61c ldr r8, [r4, #0x84]
 *   @0x1fe620 cmp r8, #0
 *   @0x1fe624 beq 0x1fe66c <_Z15SV_PhysicsAngleP9CInstanceiP6RValue+0x70>
 *   @0x1fe628 ldr r3, [r6, #0xc]
 *   @0x1fe62c bic r3, r3, #-16777216
 *   @0x1fe630 cmp r3, #0
 *   @0x1fe634 bne 0x1fe658 <_Z15SV_PhysicsAngleP9CInstanceiP6RValue+0x5c>
 *   @0x1fe638 ldm r6, {r4, r5}
 *   @0x1fe63c vmov d7, r4, r5
 *   @0x1fe640 mov r0, r8
 *   @0x1fe644 vcvt.f32.f64 s15, d7
 *   @0x1fe648 vmov r1, s15
 *   @0x1fe64c bl 0x236e48 <_ZN14CPhysicsObject11SetRotationEf>
 *   @0x1fe650 mov r0, r7
 *   @0x1fe654 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1fe658 mov r0, r6
 *   @0x1fe65c bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fe660 mov r4, r0
 *   @0x1fe664 mov r5, r1
 *   @0x1fe668 b 0x1fe63c <_Z15SV_PhysicsAngleP9CInstanceiP6RValue+0x40>
 *   @0x1fe66c mov r7, r8
 *   @0x1fe670 b 0x1fe650 <_Z15SV_PhysicsAngleP9CInstanceiP6RValue+0x54>
 *
 * ══ §139/251 CStream::WriteInteger64(long long)  0x201a68  size 120  30 条（0x201a68..0x201ae0）
 * @func 0x201a68 0x201af4  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::_AllocExtraSpace(int)
 * 字段偏移 top8: 0x10×1 / 0x8×1 / 0x18×1 / 0x4×1 / 0x1×1 / 0x2×1 / 0x3×1 / 0x5×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x201a68 push {r4, r5, r6, lr}
 *   @0x201a6c mov r1, #8
 *   @0x201a70 mov r4, r0
 *   @0x201a74 mov r5, r2
 *   @0x201a78 mov r6, r3
 *   @0x201a7c bl 0x201414 <_ZN7CStream16_AllocExtraSpaceEi>
 *   @0x201a80 ldr r3, [r4, #0x10]
 *   @0x201a84 ldr r2, [r4, #0x8]
 *   @0x201a88 ldr r1, [r4, #0x18]
 *   @0x201a8c cmp r2, r3
 *   @0x201a90 pople {r4, r5, r6, pc}
 *   @0x201a94 strb r5, [r1, r3]!
 *   @0x201a98 lsr r2, r5, #8
 *   @0x201a9c lsr r3, r5, #16
 *   @0x201aa0 strb r6, [r1, #0x4]
 *   @0x201aa4 strb r2, [r1, #0x1]
 *   @0x201aa8 lsr r5, r5, #24
 *   @0x201aac asr r2, r6, #8
 *   @0x201ab0 strb r3, [r1, #0x2]
 *   @0x201ab4 strb r5, [r1, #0x3]
 *   @0x201ab8 asr r3, r6, #16
 *   @0x201abc strb r2, [r1, #0x5]
 *   @0x201ac0 lsr r6, r6, #24
 *   @0x201ac4 strb r3, [r1, #0x6]
 *   @0x201ac8 strb r6, [r1, #0x7]
 *   @0x201acc ldrd r2, r3, [r4, #16]
 *   @0x201ad0 adds r2, r2, #8
 *   @0x201ad4 adc r3, r3, #0
 *   @0x201ad8 strd r2, r3, [r4, #16]
 *   @0x201adc pop {r4, r5, r6, pc}
 *
 * ══ §140/251 CStream::WriteReal(double)  0x201ae0  size 120  30 条（0x201ae0..0x201b58）
 * @func 0x201ae0 0x201b58  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::_AllocExtraSpace(int)
 * 字段偏移 top8: 0x10×1 / 0x8×1 / 0x18×1 / 0x1×1 / 0x2×1 / 0x4×1 / 0x3×1 / 0x7×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x201ae0 push {r4, r5, r6, lr}
 *   @0x201ae4 mov r1, #8
 *   @0x201ae8 mov r4, r0
 *   @0x201aec mov r6, r2
 *   @0x201af0 mov r5, r3
 *   @0x201af4 bl 0x201414 <_ZN7CStream16_AllocExtraSpaceEi>
 *   @0x201af8 ldr r0, [r4, #0x10]
 *   @0x201afc ldr r12, [r4, #0x8]
 *   @0x201b00 ldr r1, [r4, #0x18]
 *   @0x201b04 cmp r12, r0
 *   @0x201b08 pople {r4, r5, r6, pc}
 *   @0x201b0c strb r6, [r1, r0]!
 *   @0x201b10 lsr r12, r6, #8
 *   @0x201b14 lsr r0, r6, #16
 *   @0x201b18 strb r12, [r1, #0x1]
 *   @0x201b1c strb r0, [r1, #0x2]
 *   @0x201b20 lsr r2, r6, #24
 *   @0x201b24 strb r5, [r1, #0x4]
 *   @0x201b28 lsr r3, r5, #24
 *   @0x201b2c strb r2, [r1, #0x3]
 *   @0x201b30 lsr r12, r5, #8
 *   @0x201b34 strb r3, [r1, #0x7]
 *   @0x201b38 lsr r0, r5, #16
 *   @0x201b3c strb r12, [r1, #0x5]
 *   @0x201b40 strb r0, [r1, #0x6]
 *   @0x201b44 ldrd r2, r3, [r4, #16]
 *   @0x201b48 adds r2, r2, #8
 *   @0x201b4c adc r3, r3, #0
 *   @0x201b50 strd r2, r3, [r4, #16]
 *   @0x201b54 pop {r4, r5, r6, pc}
 *
 * ══ §141/251 setGainForNoiseImmediate(CNoise*, float)  0x217610  size 120  30 条（0x217610..0x217688）
 * @func 0x217610 0x217688  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_GetGainFromSoundID(int)
 * 字段偏移 top8: 0x10×2 / 0x5×1 / 0x8×1 / 0x18×1 / 0x38×1 / 0x14×1 / 0x2×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x217610 ldrb r3, [r0, #0x5]
 *   @0x217614 push {r4, lr}
 *   @0x217618 cmp r3, #0
 *   @0x21761c mov r4, r0
 *   @0x217620 popeq {r4, pc}
 *   @0x217624 ldr r3, [r0, #0x8]
 *   @0x217628 cmp r3, #0
 *   @0x21762c popne {r4, pc}
 *   @0x217630 ldr r3, [r0, #0x10]
 *   @0x217634 cmp r3, #0
 *   @0x217638 poplt {r4, pc}
 *   @0x21763c ldr r0, [r0, #0x18]
 *   @0x217640 bl 0x217060 <_Z24Audio_GetGainFromSoundIDi>
 *   @0x217644 vldr s15, [r4, #36]
 *   @0x217648 ldr r3, [r4, #0x38]
 *   @0x21764c movw r1, #0x100a
 *   @0x217650 cmp r3, #0
 *   @0x217654 vmov s14, r0
 *   @0x217658 ldr r0, [r4, #0x10]
 *   @0x21765c pop {r4, lr}
 *   @0x217660 vmul.f32 s15, s14, s15
 *   @0x217664 vldrne s14, [r3, #40]
 *   @0x217668 ldr r3, [pc, #0x14]
 *   @0x21766c ldr r3, [pc, r3]
 *   @0x217670 ldr r3, [r3]
 *   @0x217674 ldr r0, [r3, r0, lsl #2]
 *   @0x217678 vmulne.f32 s15, s15, s14
 *   @0x21767c vmov r2, s15
 *   @0x217680 b 0xb6a78 <alSourcef@plt>
 *   @0x217684 andseq r9, sp, r0, ror #26
 *
 * ══ §142/251 Audio_SetGainGroup(int, float, int)  0x218b84  size 120  30 条（0x218b84..0x218bfc）
 * @func 0x218b84 0x218bfc  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_GetSound(int) / Audio_SoundGain(int, float, int)
 * 字段偏移 top8: 0x6c×1 / 0x20×1 / 0x4c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x218b84 ldr r3, [pc, #0x6c]
 *   @0x218b88 push {r4, r5, r6, r7, r8, lr}
 *   @0x218b8c add r3, pc, r3
 *   @0x218b90 mov r6, r0
 *   @0x218b94 mov r7, r1
 *   @0x218b98 ldr r5, [r3, #0x20]
 *   @0x218b9c mov r8, r2
 *   @0x218ba0 cmp r5, #0
 *   @0x218ba4 pople {r4, r5, r6, r7, r8, pc}
 *   @0x218ba8 mov r4, #0
 *   @0x218bac b 0x218bbc <_Z18Audio_SetGainGroupifi+0x38>
 *   @0x218bb0 add r4, r4, #1
 *   @0x218bb4 cmp r4, r5
 *   @0x218bb8 beq 0x218bf4 <_Z18Audio_SetGainGroupifi+0x70>
 *   @0x218bbc mov r0, r4
 *   @0x218bc0 bl 0x21632c <_Z14Audio_GetSoundi>
 *   @0x218bc4 cmp r0, #0
 *   @0x218bc8 beq 0x218bb0 <_Z18Audio_SetGainGroupifi+0x2c>
 *   @0x218bcc ldr r3, [r0, #0x4c]
 *   @0x218bd0 cmp r3, r6
 *   @0x218bd4 bne 0x218bb0 <_Z18Audio_SetGainGroupifi+0x2c>
 *   @0x218bd8 mov r0, r4
 *   @0x218bdc mov r1, r7
 *   @0x218be0 mov r2, r8
 *   @0x218be4 add r4, r4, #1
 *   @0x218be8 bl 0x2178f0 <_Z15Audio_SoundGainifi>
 *   @0x218bec cmp r4, r5
 *   @0x218bf0 bne 0x218bbc <_Z18Audio_SetGainGroupifi+0x38>
 *   @0x218bf4 pop {r4, r5, r6, r7, r8, pc}
 *   @0x218bf8 subseq r12, r3, r8, lsl #14
 *
 * ══ §143/251 SoundHardware::FindSampleStart(void*, int)  0x220458  size 120  30 条（0x220458..0x2204d0）
 * @func 0x220458 0x2204e4  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SoundHardware::FindDataChunk(void*, int)
 * 字段偏移 top8: 0x40×2 / 0x60×1 / 0x3c×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x220458 ldr r3, [pc, #0x60]
 *   @0x22045c push {r4, r5, r6, lr}
 *   @0x220460 ldr r3, [pc, r3]
 *   @0x220464 mov r6, r0
 *   @0x220468 mov r5, r1
 *   @0x22046c ldrb r3, [r3]
 *   @0x220470 mov r4, r2
 *   @0x220474 cmp r3, #0
 *   @0x220478 beq 0x2204a8 <_ZN13SoundHardware15FindSampleStartEPvi+0x50>
 *   @0x22047c ldr r3, [pc, #0x40]
 *   @0x220480 ldr r2, [pc, #0x40]
 *   @0x220484 ldr r3, [pc, r3]
 *   @0x220488 ldr r1, [pc, #0x3c]
 *   @0x22048c add r2, pc, r2
 *   @0x220490 ldr r0, [r3]
 *   @0x220494 add r1, pc, r1
 *   @0x220498 add r2, r2, #32
 *   @0x22049c ldr r3, [r0]
 *   @0x2204a0 ldr r3, [r3, #0xc]
 *   @0x2204a4 blx r3
 *   @0x2204a8 mov r0, r6
 *   @0x2204ac mov r1, r5
 *   @0x2204b0 mov r2, r4
 *   @0x2204b4 bl 0x2203fc <_ZN13SoundHardware13FindDataChunkEPvi>
 *   @0x2204b8 add r0, r0, #8
 *   @0x2204bc pop {r4, r5, r6, pc}
 *   @0x2204c0 andseq r0, sp, r8, asr #31
 *   @0x2204c4 mulseq r12, r0, r2
 *   @0x2204c8 andseq sp, r3, r12, lsr r11
 *   @0x2204cc andseq r4, r3, r8, lsr #7
 *
 * ══ §144/251 SoundHardware::Resume(void*)  0x220e68  size 120  30 条（0x220e68..0x220ee0）
 * @func 0x220e68 0x220ee0  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6a84 / CheckALError()
 * 字段偏移 top8: 0x5c×1 / 0x4c×1 / 0x3c×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x220e68 push {r3, r4, r5, lr}
 *   @0x220e6c mov r5, r1
 *   @0x220e70 ldr r3, [pc, #0x5c]
 *   @0x220e74 ldr r3, [pc, r3]
 *   @0x220e78 ldrb r3, [r3]
 *   @0x220e7c cmp r3, #0
 *   @0x220e80 popne {r3, r4, r5, pc}
 *   @0x220e84 ldr r3, [pc, #0x4c]
 *   @0x220e88 ldr r3, [pc, r3]
 *   @0x220e8c ldrb r3, [r3]
 *   @0x220e90 cmp r3, #0
 *   @0x220e94 popne {r3, r4, r5, pc}
 *   @0x220e98 ldr r3, [pc, #0x3c]
 *   @0x220e9c ldr r3, [pc, r3]
 *   @0x220ea0 ldrb r4, [r3]
 *   @0x220ea4 cmp r4, #0
 *   @0x220ea8 popne {r3, r4, r5, pc}
 *   @0x220eac cmp r1, #0
 *   @0x220eb0 popeq {r3, r4, r5, pc}
 *   @0x220eb4 add r3, r5, r4
 *   @0x220eb8 add r4, r4, #4
 *   @0x220ebc ldr r0, [r3, #0x4]
 *   @0x220ec0 bl 0xb6a84 <alSourcePlay@plt>
 *   @0x220ec4 bl 0x220198 <_Z12CheckALErrorv>
 *   @0x220ec8 cmp r4, #16
 *   @0x220ecc bne 0x220eb4 <_ZN13SoundHardware6ResumeEPv+0x4c>
 *   @0x220ed0 pop {r3, r4, r5, pc}
 *   @0x220ed4 ldrsbeq lr, [r12], -r8
 *   @0x220ed8 andseq r0, sp, r8, lsr #11
 *   @0x220edc mulseq sp, r8, r5
 *
 * ══ §145/251 anon_2236d4  0x2236d4  size 120  30 条（0x2236d4..0x22374c）
 * @func 0x2236d4 0x22374c  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6b14 / 0xb6a9c / 0xb6b08 / ov_clear
 * 字段偏移 top8: 0x2b4×3 / 0x2c4×1 / 0x2e0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2236d4 push {r4, r5, lr}
 *   @0x2236d8 sub sp, sp, #12
 *   @0x2236dc mov r4, r0
 *   @0x2236e0 ldr r0, [r0, #0x2b4]
 *   @0x2236e4 bl 0xb6b14 <alSourceStop@plt>
 *   @0x2236e8 ldr r0, [r4, #0x2b4]
 *   @0x2236ec movw r1, #0x1015
 *   @0x2236f0 mov r2, sp
 *   @0x2236f4 bl 0xb6a9c <alGetSourcei@plt>
 *   @0x2236f8 ldr r3, [sp]
 *   @0x2236fc cmp r3, #0
 *   @0x223700 sub r3, r3, #1
 *   @0x223704 addne r5, sp, #4
 *   @0x223708 str r3, [sp]
 *   @0x22370c beq 0x223734 <_Z8ogg_readPvjjS_+0xa8>
 *   @0x223710 ldr r0, [r4, #0x2b4]
 *   @0x223714 mov r1, #1
 *   @0x223718 mov r2, r5
 *   @0x22371c bl 0xb6b08 <alSourceUnqueueBuffers@plt>
 *   @0x223720 ldr r3, [sp]
 *   @0x223724 cmp r3, #0
 *   @0x223728 sub r3, r3, #1
 *   @0x22372c str r3, [sp]
 *   @0x223730 bne 0x223710 <_Z8ogg_readPvjjS_+0x84>
 *   @0x223734 mov r0, r4
 *   @0x223738 bl 0x230ec4 <ov_clear>
 *   @0x22373c mov r3, #0
 *   @0x223740 str r3, [r4, #0x2c4]
 *   @0x223744 str r3, [r4, #0x2e0]
 *   @0x223748 add sp, sp, #12
 *
 * ══ §146/251 COggAudio::Delete_SyncThread(int)  0x225f2c  size 120  30 条（0x225f2c..0x225fa4）
 * @func 0x225f2c 0x225fa4  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)×2 / COggSyncThread::Quit() / Mutex::~Mutex()
 * 字段偏移 top8: 0x10×2 / 0x2×2 / 0x8×2 / 0x4×1 / 0x848×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x225f2c push {r3, r4, r5, r6, r7, lr}
 *   @0x225f30 mov r4, r0
 *   @0x225f34 ldr r3, [r0, #0x4]
 *   @0x225f38 mov r5, r1
 *   @0x225f3c cmp r3, r1
 *   @0x225f40 pople {r3, r4, r5, r6, r7, pc}
 *   @0x225f44 ldr r3, [r0, #0x10]
 *   @0x225f48 ldr r6, [r3, r1, lsl #2]
 *   @0x225f4c cmp r6, #0
 *   @0x225f50 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x225f54 mov r0, r6
 *   @0x225f58 bl 0x2250c8 <_ZN14COggSyncThread4QuitEv>
 *   @0x225f5c ldr r7, [r6, #0x848]
 *   @0x225f60 cmp r7, #0
 *   @0x225f64 beq 0x225f78 <_ZN9COggAudio17Delete_SyncThreadEi+0x4c>
 *   @0x225f68 mov r0, r7
 *   @0x225f6c bl 0x27e020 <_ZN5MutexD2Ev>
 *   @0x225f70 mov r0, r7
 *   @0x225f74 bl 0x27d1d0 <_ZdlPv>
 *   @0x225f78 mov r0, r6
 *   @0x225f7c bl 0x27d1d0 <_ZdlPv>
 *   @0x225f80 ldr r3, [r4, #0x8]
 *   @0x225f84 ldr r2, [r4, #0x10]
 *   @0x225f88 mov r1, #0
 *   @0x225f8c cmp r5, r3
 *   @0x225f90 str r1, [r2, r5, lsl #2]
 *   @0x225f94 addge r5, r5, #1
 *   @0x225f98 movlt r5, r3
 *   @0x225f9c str r5, [r4, #0x8]
 *   @0x225fa0 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §147/251 oggpackB_read1  0x233db0  size 120  30 条（0x233db0..0x233e28）
 * @func 0x233db0 0x233e28  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×3 / 0xc×2 / 0x10×1 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x233db0 ldr r1, [r0]
 *   @0x233db4 mov r3, r0
 *   @0x233db8 ldr r12, [r0, #0x10]
 *   @0x233dbc str r4, [sp, #-0x4]!
 *   @0x233dc0 cmp r1, r12
 *   @0x233dc4 bge 0x233e0c <oggpackB_read1+0x5c>
 *   @0x233dc8 ldr r12, [r0, #0xc]
 *   @0x233dcc ldr r2, [r0, #0x4]
 *   @0x233dd0 ldrb r0, [r12]
 *   @0x233dd4 add r4, r2, #1
 *   @0x233dd8 rsb r2, r2, #7
 *   @0x233ddc cmp r4, #7
 *   @0x233de0 addgt r12, r12, #1
 *   @0x233de4 addgt r1, r1, #1
 *   @0x233de8 asr r0, r0, r2
 *   @0x233dec strle r4, [r3, #0x4]
 *   @0x233df0 and r0, r0, #1
 *   @0x233df4 movgt r2, #0
 *   @0x233df8 strgt r12, [r3, #0xc]
 *   @0x233dfc strgt r1, [r3]
 *   @0x233e00 strgt r2, [r3, #0x4]
 *   @0x233e04 ldr r4, [sp], #4
 *   @0x233e08 bx lr
 *   @0x233e0c mov r1, #0
 *   @0x233e10 mov r2, #1
 *   @0x233e14 mvn r0, #0
 *   @0x233e18 str r12, [r3]
 *   @0x233e1c str r1, [r3, #0xc]
 *   @0x233e20 str r2, [r3, #0x4]
 *   @0x233e24 b 0x233e04 <oggpackB_read1+0x54>
 *
 * ══ §148/251 CPhysicsFixture::SetChainShape(bool)  0x236964  size 120  30 条（0x236964..0x2369dc）
 * @func 0x236964 0x2369dc  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsFixture::DeleteShape() / operator new(unsigned int)
 * 字段偏移 top8: 0xc×2 / 0x19×1 / 0x20×1 / 0x4c×1 / 0x4×1 / 0x8×1 / 0x10×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x236964 push {r3, r4, r5, lr}
 *   @0x236968 mov r4, r0
 *   @0x23696c mov r5, r1
 *   @0x236970 bl 0x2365d0 <_ZN15CPhysicsFixture11DeleteShapeEv>
 *   @0x236974 strb r5, [r4, #0x19]
 *   @0x236978 mov r0, #40
 *   @0x23697c bl 0x27c524 <_Znwj>
 *   @0x236980 ldr r12, [r4, #0x20]
 *   @0x236984 ldr r2, [pc, #0x4c]
 *   @0x236988 mov r1, #3
 *   @0x23698c ldr r2, [pc, r2]
 *   @0x236990 add r2, r2, #8
 *   @0x236994 mov r3, r0
 *   @0x236998 movw r0, #0xd70a
 *   @0x23699c str r1, [r3, #0x4]
 *   @0x2369a0 movt r0, #0x3c23
 *   @0x2369a4 str r2, [r3]
 *   @0x2369a8 mov r1, #8
 *   @0x2369ac mov r2, #0
 *   @0x2369b0 str r0, [r3, #0x8]
 *   @0x2369b4 str r2, [r3, #0xc]
 *   @0x2369b8 mov r0, r4
 *   @0x2369bc str r2, [r3, #0x10]
 *   @0x2369c0 strb r2, [r3, #0x24]
 *   @0x2369c4 strb r2, [r3, #0x25]
 *   @0x2369c8 str r3, [r12]
 *   @0x2369cc str r2, [r4, #0xc]
 *   @0x2369d0 pop {r3, r4, r5, lr}
 *   @0x2369d4 b 0x23658c <_ZN15CPhysicsFixture13AllocVerticesEi>
 *   @0x2369d8 andseq r10, r11, r12, lsr #22
 *
 * ══ §149/251 CPhysicsWorld::ParticleGroupCircle(float)  0x239a6c  size 120  30 条（0x239a6c..0x239ae4）
 * @func 0x239a6c 0x239ae4  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int)
 * 字段偏移 top8: 0x3c×2 / 0x4×2 / 0x34×1 / 0xc×1 / 0x10×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x239a6c push {r4, lr}
 *   @0x239a70 vpush {d8}
 *   @0x239a74 mov r4, r0
 *   @0x239a78 ldr r0, [r0, #0x3c]
 *   @0x239a7c vmov s16, r1
 *   @0x239a80 cmp r0, #0
 *   @0x239a84 beq 0x239a94 <_ZN13CPhysicsWorld19ParticleGroupCircleEf+0x28>
 *   @0x239a88 ldr r3, [r0]
 *   @0x239a8c ldr r3, [r3, #0x4]
 *   @0x239a90 blx r3
 *   @0x239a94 mov r0, #20
 *   @0x239a98 bl 0x27c524 <_Znwj>
 *   @0x239a9c vldr s15, [r4, #96]
 *   @0x239aa0 vmul.f32 s16, s16, s15
 *   @0x239aa4 ldr r2, [pc, #0x34]
 *   @0x239aa8 mov r1, #0
 *   @0x239aac ldr r2, [pc, r2]
 *   @0x239ab0 add r2, r2, #8
 *   @0x239ab4 vabs.f32 s16, s16
 *   @0x239ab8 mov r3, r0
 *   @0x239abc vstr s16, [r3, #8]
 *   @0x239ac0 vpop {d8}
 *   @0x239ac4 mov r0, #0
 *   @0x239ac8 str r1, [r3, #0xc]
 *   @0x239acc str r0, [r3, #0x4]
 *   @0x239ad0 str r1, [r3, #0x10]
 *   @0x239ad4 str r2, [r3]
 *   @0x239ad8 str r3, [r4, #0x3c]
 *   @0x239adc pop {r4, pc}
 *   @0x239ae0 andseq r7, r11, r0, lsl #20
 *
 * ══ §150/251 F_JS_Object_prototype_isPrototypeOf(RValue&, CInstance*, CInstance*, int, RValue*)  0x23cc9c  size 120  30 条（0x23cc9c..0x23cd14）
 * @func 0x23cc9c 0x23cd14  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×4 / 0x4×3 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23cc9c ldr r3, [sp]
 *   @0x23cca0 ldr r2, [r3, #0xc]
 *   @0x23cca4 cmp r2, #6
 *   @0x23cca8 beq 0x23ccc0 <_Z35F_JS_Object_prototype_isPrototypeOfR6RValueP9CInstanceS2_iPS_+0x24>
 *   @0x23ccac mov r3, #0
 *   @0x23ccb0 str r3, [r0, #0xc]
 *   @0x23ccb4 str r3, [r0]
 *   @0x23ccb8 str r3, [r0, #0x4]
 *   @0x23ccbc bx lr
 *   @0x23ccc0 ldr r3, [r3]
 *   @0x23ccc4 b 0x23ccd0 <_Z35F_JS_Object_prototype_isPrototypeOfR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x23ccc8 cmp r1, r3
 *   @0x23cccc beq 0x23ccf4 <_Z35F_JS_Object_prototype_isPrototypeOfR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x23ccd0 ldr r3, [r3, #0x18]
 *   @0x23ccd4 cmp r3, #0
 *   @0x23ccd8 bne 0x23ccc8 <_Z35F_JS_Object_prototype_isPrototypeOfR6RValueP9CInstanceS2_iPS_+0x2c>
 *   @0x23ccdc mov r3, #0
 *   @0x23cce0 mov r2, #13
 *   @0x23cce4 str r3, [r0]
 *   @0x23cce8 str r2, [r0, #0xc]
 *   @0x23ccec str r3, [r0, #0x4]
 *   @0x23ccf0 bx lr
 *   @0x23ccf4 mov r3, #0
 *   @0x23ccf8 mov r2, #13
 *   @0x23ccfc movt r3, #0x3ff0
 *   @0x23cd00 str r2, [r0, #0xc]
 *   @0x23cd04 str r3, [r0, #0x4]
 *   @0x23cd08 mov r3, #0
 *   @0x23cd0c str r3, [r0]
 *   @0x23cd10 bx lr
 *
 * ══ §151/251 myswap(RValue*, int, int)  0x242edc  size 120  30 条（0x242edc..0x242f54）
 * @func 0x242edc 0x242f54  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×6 / 0xc×4 / 0x8×4
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x242edc push {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x242ee0 add r4, r0, r1, lsl #4
 *   @0x242ee4 add r12, r0, r2, lsl #4
 *   @0x242ee8 mov r7, r0
 *   @0x242eec ldr r3, [r4, #0xc]
 *   @0x242ef0 sub sp, sp, #16
 *   @0x242ef4 ldr r0, [r4]
 *   @0x242ef8 mov r9, r1
 *   @0x242efc mov r8, r2
 *   @0x242f00 ldr r1, [r4, #0x4]
 *   @0x242f04 ldr r2, [r4, #0x8]
 *   @0x242f08 mov r5, sp
 *   @0x242f0c mov r6, sp
 *   @0x242f10 ldr r10, [r12, #0x4]
 *   @0x242f14 ldr r11, [r12]
 *   @0x242f18 stm r6!, {r0, r1, r2, r3}
 *   @0x242f1c ldm r5!, {r0, r1, r2, r3}
 *   @0x242f20 ldr r6, [r12, #0x8]
 *   @0x242f24 ldr r5, [r12, #0xc]
 *   @0x242f28 str r11, [r7, r9, lsl #4]
 *   @0x242f2c str r10, [r4, #0x4]
 *   @0x242f30 str r6, [r4, #0x8]
 *   @0x242f34 str r5, [r4, #0xc]
 *   @0x242f38 str r0, [r7, r8, lsl #4]
 *   @0x242f3c str r1, [r12, #0x4]
 *   @0x242f40 str r2, [r12, #0x8]
 *   @0x242f44 str r3, [r12, #0xc]
 *   @0x242f48 add sp, sp, #16
 *   @0x242f4c pop {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x242f50 bx lr
 *
 * ══ §152/251 F_JS_IsFinite(RValue&, CInstance*, CInstance*, int, RValue*)  0x24d874  size 120  30 条（0x24d874..0x24d8ec）
 * @func 0x24d874 0x24d8ec  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_JS_ToNumber(RValue&, RValue&)
 * 字段偏移 top8: 0xc×2 / 0x28×1 / 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24d874 push {r4, r5, r6, r7, lr}
 *   @0x24d878 sub sp, sp, #20
 *   @0x24d87c mov r6, r0
 *   @0x24d880 mov r7, #0
 *   @0x24d884 ldr r1, [sp, #0x28]
 *   @0x24d888 mov r0, sp
 *   @0x24d88c mov r2, #0
 *   @0x24d890 mov r3, #0
 *   @0x24d894 str r7, [sp, #0x8]
 *   @0x24d898 strd r2, r3, [sp]
 *   @0x24d89c mvn r3, #-16777216
 *   @0x24d8a0 str r3, [sp, #0xc]
 *   @0x24d8a4 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_>
 *   @0x24d8a8 ldrd r4, r5, [sp]
 *   @0x24d8ac mov r3, #0
 *   @0x24d8b0 movt r3, #0x7ff0
 *   @0x24d8b4 mov r2, #0
 *   @0x24d8b8 and r5, r5, r3
 *   @0x24d8bc and r4, r4, r2
 *   @0x24d8c0 cmp r5, r3
 *   @0x24d8c4 cmpeq r4, r2
 *   @0x24d8c8 mov r1, #13
 *   @0x24d8cc mov r3, r7
 *   @0x24d8d0 str r7, [r6]
 *   @0x24d8d4 movt r3, #0x3ff0
 *   @0x24d8d8 str r1, [r6, #0xc]
 *   @0x24d8dc str r3, [r6, #0x4]
 *   @0x24d8e0 streq r7, [r6, #0x4]
 *   @0x24d8e4 add sp, sp, #20
 *   @0x24d8e8 pop {r4, r5, r6, r7, pc}
 *
 * ══ §153/251 JS_Math_round(RValue&, CInstance*, CInstance*, int, RValue*)  0x252a20  size 120  30 条（0x252a20..0x252a98）
 * @func 0x252a20 0x252a98  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_Math_round(RValue&, CInstance*, CInstance*, int, RValue*)+0x54 / F_JS_ToNumber(RValue&, RValue&) / YYGetReal(RValue const*, int) / 0xb66e8
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x252a20 cmp r3, #0
 *   @0x252a24 push {r3, r4, r5, lr}
 *   @0x252a28 mov r5, #0
 *   @0x252a2c mov r4, r0
 *   @0x252a30 ldr r1, [sp, #0x10]
 *   @0x252a34 str r5, [r0, #0xc]
 *   @0x252a38 ble 0x252a74 <_Z13JS_Math_roundR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x252a3c bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_>
 *   @0x252a40 cmp r0, #1
 *   @0x252a44 beq 0x252a84 <_Z13JS_Math_roundR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x252a48 mov r1, r5
 *   @0x252a4c mov r0, r4
 *   @0x252a50 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x252a54 bl 0xb66e8 <lrint@plt>
 *   @0x252a58 vmov s15, r0
 *   @0x252a5c vcvt.f64.s32 d7, s15
 *   @0x252a60 vmov r0, r1, d7
 *   @0x252a64 vmov r2, s14
 *   @0x252a68 mov r3, r1
 *   @0x252a6c stm r4, {r2, r3}
 *   @0x252a70 pop {r3, r4, r5, pc}
 *   @0x252a74 mvn r2, #0
 *   @0x252a78 mvn r3, #-2147483648
 *   @0x252a7c stm r0, {r2, r3}
 *   @0x252a80 pop {r3, r4, r5, pc}
 *   @0x252a84 ldr r0, [pc, #0x8]
 *   @0x252a88 pop {r3, r4, r5, lr}
 *   @0x252a8c add r0, pc, r0
 *   @0x252a90 b 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x252a94 ldrheq r3, [r0], -r12
 *
 * ══ §154/251 pcre_refcount  0x266568  size 120  30 条（0x266568..0x2665e0）
 * @func 0x266568 0x2665e0  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x28×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x266568 subs r3, r0, #0
 *   @0x26656c beq 0x2665d8 <pcre_refcount+0x70>
 *   @0x266570 ldr r0, [r3]
 *   @0x266574 movw r2, #0x5245
 *   @0x266578 movt r2, #0x5043
 *   @0x26657c cmp r0, r2
 *   @0x266580 bne 0x2665c8 <pcre_refcount+0x60>
 *   @0x266584 ldr r2, [r3, #0xc]
 *   @0x266588 tst r2, #1
 *   @0x26658c beq 0x2665d0 <pcre_refcount+0x68>
 *   @0x266590 ldrh r2, [r3, #40]
 *   @0x266594 rsb r0, r1, #0
 *   @0x266598 cmp r0, r2
 *   @0x26659c movgt r0, #0
 *   @0x2665a0 movgt r1, r0
 *   @0x2665a4 bgt 0x2665c0 <pcre_refcount+0x58>
 *   @0x2665a8 add r1, r1, r2
 *   @0x2665ac movw r2, #0xffff
 *   @0x2665b0 cmp r1, r2
 *   @0x2665b4 movge r1, r2
 *   @0x2665b8 uxth r1, r1
 *   @0x2665bc mov r0, r1
 *   @0x2665c0 strh r1, [r3, #40]
 *   @0x2665c4 bx lr
 *   @0x2665c8 mvn r0, #3
 *   @0x2665cc bx lr
 *   @0x2665d0 mvn r0, #27
 *   @0x2665d4 bx lr
 *   @0x2665d8 mvn r0, #1
 *   @0x2665dc bx lr
 *
 * ══ §155/251 _spAttachmentLoader_setError  0x284df0  size 120  30 条（0x284df0..0x284e68）
 * @func 0x284df0 0x284e68  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _free×2 / 0xb6538×2 / _malloc×2 / 0xb65a4
 * 字段偏移 top8: 0x4×2 / 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x284df0 push {r3, r4, r5, r6, r7, lr}
 *   @0x284df4 mov r4, r0
 *   @0x284df8 ldr r0, [r0]
 *   @0x284dfc mov r6, r1
 *   @0x284e00 mov r5, r2
 *   @0x284e04 bl 0x285c80 <_free>
 *   @0x284e08 ldr r0, [r4, #0x4]
 *   @0x284e0c bl 0x285c80 <_free>
 *   @0x284e10 mov r0, r6
 *   @0x284e14 bl 0xb6538 <strlen@plt>
 *   @0x284e18 ldr r7, [pc, #0x44]
 *   @0x284e1c mov r2, #91
 *   @0x284e20 add r7, pc, r7
 *   @0x284e24 mov r1, r7
 *   @0x284e28 add r0, r0, #1
 *   @0x284e2c bl 0x285c10 <_malloc>
 *   @0x284e30 mov r1, r6
 *   @0x284e34 str r0, [r4]
 *   @0x284e38 bl 0xb65a4 <strcpy@plt>
 *   @0x284e3c mov r0, r5
 *   @0x284e40 bl 0xb6538 <strlen@plt>
 *   @0x284e44 mov r1, r7
 *   @0x284e48 mov r2, #92
 *   @0x284e4c add r0, r0, #1
 *   @0x284e50 bl 0x285c10 <_malloc>
 *   @0x284e54 mov r1, r5
 *   @0x284e58 str r0, [r4, #0x4]
 *   @0x284e5c pop {r3, r4, r5, r6, r7, lr}
 *   @0x284e60 b 0xb65a4 <strcpy@plt>
 *   @0x284e64 andeq r2, sp, r12, ror #16
 *
 * ══ §156/251 spSkeletonJson_readSkeletonDataFile  0x28eb40  size 120  30 条（0x28eb40..0x28ebb8）
 * @func 0x28eb40 0x28ebb8  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _spUtil_readFile / spSkeletonJson_readSkeletonData / _free / _spSkeletonJson_setError
 * 字段偏移 top8: 0x4×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28eb40 push {r4, r5, r6, lr}
 *   @0x28eb44 mov r5, r1
 *   @0x28eb48 sub sp, sp, #8
 *   @0x28eb4c mov r6, r0
 *   @0x28eb50 add r1, sp, #4
 *   @0x28eb54 mov r0, r5
 *   @0x28eb58 bl 0xbd83c <_spUtil_readFile>
 *   @0x28eb5c ldr r3, [sp, #0x4]
 *   @0x28eb60 cmp r3, #0
 *   @0x28eb64 mov r4, r0
 *   @0x28eb68 mov r0, r6
 *   @0x28eb6c beq 0x28eb98 <spSkeletonJson_readSkeletonDataFile+0x58>
 *   @0x28eb70 cmp r4, #0
 *   @0x28eb74 beq 0x28eb98 <spSkeletonJson_readSkeletonDataFile+0x58>
 *   @0x28eb78 mov r1, r4
 *   @0x28eb7c bl 0x28b84c <spSkeletonJson_readSkeletonData>
 *   @0x28eb80 mov r5, r0
 *   @0x28eb84 mov r0, r4
 *   @0x28eb88 bl 0x285c80 <_free>
 *   @0x28eb8c mov r0, r5
 *   @0x28eb90 add sp, sp, #8
 *   @0x28eb94 pop {r4, r5, r6, pc}
 *   @0x28eb98 ldr r2, [pc, #0x14]
 *   @0x28eb9c mov r3, r5
 *   @0x28eba0 mov r1, #0
 *   @0x28eba4 add r2, pc, r2
 *   @0x28eba8 bl 0x28b784 <_spSkeletonJson_setError>
 *   @0x28ebac mov r0, #0
 *   @0x28ebb0 b 0x28eb90 <spSkeletonJson_readSkeletonDataFile+0x50>
 *   @0x28ebb4 andeq r9, r12, r4, asr #7
 *
 * ══ §157/251 WriteString(Buffer_Standard*, char const*)  0x29e624  size 120  30 条（0x29e624..0x29e69c）
 * @func 0x29e624 0x29e69c  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538
 * 字段偏移 top8: 0x2c×1 / 0x38×1 / 0x30×1 / 0x8×1 / 0xc×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29e624 push {r3, r4, r5, r6, r7, lr}
 *   @0x29e628 subs r7, r1, #0
 *   @0x29e62c mov r6, r0
 *   @0x29e630 beq 0x29e684 <_Z11WriteStringP15Buffer_StandardPKc+0x60>
 *   @0x29e634 mov r0, r7
 *   @0x29e638 bl 0xb6538 <strlen@plt>
 *   @0x29e63c add r0, r0, #1
 *   @0x29e640 vmov s15, r0
 *   @0x29e644 vcvt.f64.u32 d6, s15
 *   @0x29e648 mov r2, r6
 *   @0x29e64c ldr r3, [r2], #44
 *   @0x29e650 mov r1, #0
 *   @0x29e654 mov r0, r6
 *   @0x29e658 str r1, [r6, #0x38]
 *   @0x29e65c mov r1, #5
 *   @0x29e660 vmov r4, r5, d6
 *   @0x29e664 vstr s12, [r6, #44]
 *   @0x29e668 str r5, [r6, #0x30]
 *   @0x29e66c ldr r3, [r3, #0x8]
 *   @0x29e670 blx r3
 *   @0x29e674 mov r0, r6
 *   @0x29e678 mov r1, r7
 *   @0x29e67c pop {r3, r4, r5, r6, r7, lr}
 *   @0x29e680 b 0xcddb8 <_ZN7IBuffer5WriteEPKc>
 *   @0x29e684 ldr r7, [pc, #0xc]
 *   @0x29e688 vldr s15, [pc, #4]
 *   @0x29e68c add r7, pc, r7
 *   @0x29e690 b 0x29e644 <_Z11WriteStringP15Buffer_StandardPKc+0x20>
 *   @0x29e694 andeq r0, r0, r7
 *   @0x29e698 andeq r11, r11, r12, lsr r5
 *
 * ══ §158/251 DrawSplash()  0x2a1794  size 120  30 条（0x2a1794..0x2a180c）
 * @func 0x2a1794 0x2a180c  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_D3D_Set_Texture_Interpolation(bool)×2 / ShouldDisplaySplash() / GR_D3D_Get_Texture_Interpolation() / GR_D3D_Start_Frame() / GR_Draw_Clear(unsigned int) / DrawLogo(int) / GR_D3D_Finish_Frame(bool) / ProcessMessages()
 * 字段偏移 top8: 0x68×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a1794 push {r3, r4, r5, lr}
 *   @0x2a1798 ldr r3, [pc, #0x68]
 *   @0x2a179c ldr r3, [pc, r3]
 *   @0x2a17a0 ldrb r4, [r3]
 *   @0x2a17a4 cmp r4, #0
 *   @0x2a17a8 popne {r3, r4, r5, pc}
 *   @0x2a17ac bl 0x28fe44 <_Z19ShouldDisplaySplashv>
 *   @0x2a17b0 cmp r0, #0
 *   @0x2a17b4 popeq {r3, r4, r5, pc}
 *   @0x2a17b8 bl 0x1689f4 <_Z32GR_D3D_Get_Texture_Interpolationv>
 *   @0x2a17bc mov r5, r0
 *   @0x2a17c0 mov r0, #1
 *   @0x2a17c4 bl 0x168710 <_Z32GR_D3D_Set_Texture_Interpolationb>
 *   @0x2a17c8 bl 0x1699c0 <_Z18GR_D3D_Start_Framev>
 *   @0x2a17cc mov r0, #-16777216
 *   @0x2a17d0 bl 0x169f58 <_Z13GR_Draw_Clearj>
 *   @0x2a17d4 mov r0, r4
 *   @0x2a17d8 bl 0x28fe40 <_Z8DrawLogoi>
 *   @0x2a17dc add r4, r4, #1
 *   @0x2a17e0 mov r0, #1
 *   @0x2a17e4 bl 0x169a58 <_Z19GR_D3D_Finish_Frameb>
 *   @0x2a17e8 bl 0x28fe64 <_Z15ProcessMessagesv>
 *   @0x2a17ec cmp r4, #5
 *   @0x2a17f0 bne 0x2a17c8 <_Z10DrawSplashv+0x34>
 *   @0x2a17f4 mov r0, r5
 *   @0x2a17f8 bl 0x168710 <_Z32GR_D3D_Set_Texture_Interpolationb>
 *   @0x2a17fc mvn r0, #0
 *   @0x2a1800 pop {r3, r4, r5, lr}
 *   @0x2a1804 b 0x28fe40 <_Z8DrawLogoi>
 *   @0x2a1808 andseq r0, r5, r0, lsl #5
 *
 * ══ §159/251 _zip_free(zip*)  0x2a4884  size 120  30 条（0x2a4884..0x2a48fc）
 * @func 0x2a4884 0x2a48fc  size 120  30 条
 * 部分覆盖: 本节 30/55 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb655c×2 / 0xb6850 / 0x1ba2f50
 * 字段偏移 top8: 0x4×2 / 0x20×1 / 0x34×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a4884 push {r4, r5, r6, lr}
 *   @0x2a4888 cmp r0, #0x0
 *   @0x2a488c ldr r0, [r0]
 *   @0x2a4890 blx 0xb655c <free@plt>
 *   @0x2a4894 ldr r0, [r4, #0x4]
 *   @0x2a4898 blx 0xb6850 <fclose@plt>
 *   @0x2a489c ldr r0, [r4, #0x20]
 *   @0x2a48a0 blvs 0x1ba2f50 <b2_toiTime+0x1449aac>
 *   @0x2a48a4 cbz r3, 0x2a48c2 <_Z9_zip_freeP3zip+0x3e>
 *   @0x2a48a8 movs r6, #0x14
 *   @0x2a48ac ldr r0, [r4, #0x34]
 *   @0x2a48b0 bge 0x2a48be <_Z9_zip_freeP3zip+0x3a>
 *   @0x2a48b4 .word 0xf0000005
 *   @0x2a48b8 strlo pc, [r1, #-0xf58]
 *   @0x2a48bc b 0x2a48aa <_Z9_zip_freeP3zip+0x26>
 *   @0x2a48c0 strhs lr, [r0, #-0xe4e]
 *   @0x2a48c4 ldr r3, [r4, #0x38]
 *   @0x2a48c8 bge 0x2a48ea <_Z9_zip_freeP3zip+0x66>
 *   @0x2a48cc ldr.w r0, [r3, r5, lsl #2]
 *   @0x2a48d0 ldr r6, [r0, #0x4]
 *   @0x2a48d4 adds r0, #0x4
 *   @0x2a48d8 mov r2, r6
 *   @0x2a48dc stcvs p13, c15, [r3], #-244
 *   @0x2a48e0 ldr.w r3, [r3, r5, lsl #2]
 *   @0x2a48e4 str r6, [r3]
 *   @0x2a48e8 b 0x2a48c4 <_Z9_zip_freeP3zip+0x40>
 *   @0x2a48ec blx 0xb655c <free@plt>
 *   @0x2a48f0 mov r0, r4
 *   @0x2a48f4 .word 0xf0774070
 *   @0x2a48f8 ldcllt p8, c11, [r0, #-900]!
 *
 * ══ §160/251 png_read_sig  0x2abb94  size 120  30 条（0x2abb94..0x2abc0c）
 * @func 0x2abb94 0x2abc0c  size 120  30 条
 * 部分覆盖: 本节 30/53 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_sig_cmp / png_error
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2abb94 push {r3, r4, r5, r6, r7, lr}
 *   @0x2abb98 ldrb.w r4, [r0, #0x1f0]
 *   @0x2abb9c mov r6, r1
 *   @0x2abba0 bhi 0x2abc00 <png_read_sig+0x6c>
 *   @0x2abba4 .word 0xf1040708
 *   @0x2abba8 ldrtmi r0, [r1], #-288
 *   @0x2abbac adds r6, #0x20
 *   @0x2abbb0 mov r2, r7
 *   @0x2abbb4 .word 0xf7fc3334
 *   @0x2abbb8 movwhs pc, #0x8a3b
 *   @0x2abbbc mov r0, r6
 *   @0x2abbc0 qsub8mi r3, r1, r0
 *   @0x2abbc4 mov r2, r7
 *   @0x2abbc8 orrlt pc, r8, r1, asr #30
 *   @0x2abbcc cmp r4, #0x3
 *   @0x2abbd0 mov r0, r6
 *   @0x2abbd4 rsb.w r2, r4, #0x4
 *   @0x2abbd8 bl 0x2a5a4c <png_sig_cmp>
 *   @0x2abbdc cbz r0, 0x2abbe6 <png_read_sig+0x52>
 *   @0x2abbe0 mov r0, r5
 *   @0x2abbe4 b 0x2abbec <png_read_sig+0x58>
 *   @0x2abbe8 mov r0, r5
 *   @0x2abbec bl 0x2a642c <png_error>
 *   @0x2abbf0 cmp r4, #0x2
 *   @0x2abbf4 ldr.w r3, [r5, #0x12c]
 *   @0x2abbf8 orr r3, r3, #0x1000
 *   @0x2abbfc str.w r3, [r5, #0x12c]
 *   @0x2abc00 pop {r3, r4, r5, r6, r7, pc}
 *   @0x2abc04 lsrs r1, r0, #0x1f
 *   @0x2abc08 lsrs r0, r1, #0x1f
 *
 * ══ §161/251 png_write_oFFs  0x2b21d8  size 120  30 条（0x2b21d8..0x2b2250）
 * @func 0x2b21d8 0x2b2250  size 120  30 条
 * 部分覆盖: 本节 30/53 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_save_int_32×2 / png_write_chunk / 0xb65d4 / png_write_pCAL+0xe4
 * 字段偏移 top8: 0x14×2 / 0x58×1 / 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b21d8 push.w {r4, r5, r6, r7, r8, r9, lr}
 *   @0x2b21dc mov r7, r3
 *   @0x2b21e0 mov r6, r0
 *   @0x2b21e4 sub sp, #0x1c
 *   @0x2b21e8 ldr r4, [r4]
 *   @0x2b21ec add r5, pc
 *   @0x2b21f0 ldr r3, [r4]
 *   @0x2b21f4 ldr r0, [r5, #88]!
 *   @0x2b21f8 str r3, [sp, #0x14]
 *   @0x2b21fc str r0, [sp]
 *   @0x2b2200 stcle p0, c3, [r4, #-16]
 *   @0x2b2204 ldr r1, [pc, #0x44]
 *   @0x2b2208 add r1, pc
 *   @0x2b220c stcge p9, c15, [r2, #-204]
 *   @0x2b2210 mov r1, r9
 *   @0x2b2214 bl 0x2b1134 <png_save_int_32>
 *   @0x2b2218 adds r0, r5, #0x4
 *   @0x2b221c bl 0x2b1134 <png_save_int_32>
 *   @0x2b2220 mov r2, r5
 *   @0x2b2224 mov r0, r6
 *   @0x2b2228 strb.w r7, [sp, #0x10]
 *   @0x2b222c bl 0x2b12bc <png_write_chunk>
 *   @0x2b2230 ldr r2, [sp, #0x14]
 *   @0x2b2234 cmp r2, r3
 *   @0x2b2238 blx 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2b223c add sp, #0x1c
 *   @0x2b2240 svclt #0x83f0
 *   @0x2b2244 .word 0xb76e
 *   @0x2b2248 blt 0x2b2334 <png_write_pCAL+0xe4>
 *   @0x2b224c stm r4!, {r0, r1, r2, r4, r6}
 *
 * ══ §162/251 png_write_pHYs  0x2b2418  size 120  30 条（0x2b2418..0x2b2490）
 * @func 0x2b2418 0x2b2490  size 120  30 条
 * 部分覆盖: 本节 30/53 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_save_uint_32×2 / png_write_chunk / 0xb65d4 / png_write_tIME+0x64
 * 字段偏移 top8: 0x14×2 / 0x67×1 / 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b2418 push.w {r4, r5, r6, r7, r8, r9, lr}
 *   @0x2b241c mov r7, r3
 *   @0x2b2420 mov r6, r0
 *   @0x2b2424 sub sp, #0x1c
 *   @0x2b2428 ldr r4, [r4]
 *   @0x2b242c add r5, pc
 *   @0x2b2430 ldr r3, [r4]
 *   @0x2b2434 ldr r0, [r5, #103]!
 *   @0x2b2438 str r3, [sp, #0x14]
 *   @0x2b243c str r0, [sp]
 *   @0x2b2440 stcle p0, c3, [r4, #-16]
 *   @0x2b2444 ldr r1, [pc, #0x44]
 *   @0x2b2448 add r1, pc
 *   @0x2b244c stcge p8, c15, [r2, #-76]
 *   @0x2b2450 mov r1, r9
 *   @0x2b2454 bl 0x2b1124 <png_save_uint_32>
 *   @0x2b2458 adds r0, r5, #0x4
 *   @0x2b245c bl 0x2b1124 <png_save_uint_32>
 *   @0x2b2460 mov r2, r5
 *   @0x2b2464 mov r0, r6
 *   @0x2b2468 strb.w r7, [sp, #0x10]
 *   @0x2b246c bl 0x2b12bc <png_write_chunk>
 *   @0x2b2470 ldr r2, [sp, #0x14]
 *   @0x2b2474 cmp r2, r3
 *   @0x2b2478 blx 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2b247c add sp, #0x1c
 *   @0x2b2480 svclt #0x83f0
 *   @0x2b2484 push {r1, r2, r3, r5, lr}
 *   @0x2b2488 bls 0x2b24f4 <png_write_tIME+0x64>
 *   @0x2b248c stm r2!, {r0, r2, r6}
 *
 * ══ §163/251 jinit_input_controller  0x2b3ee0  size 120  30 条（0x2b3ee0..0x2b3f58）
 * @func 0x2b3ee0 0x2b3f58  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x44×2 / 0x3c×2 / 0x4×1 / 0x190×1 / 0xc×1 / 0x14×1 / 0x10×1 / 0x11×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b3ee0 ldr r3, [r0, #0x4]
 *   @0x2b3ee4 mov r1, #0
 *   @0x2b3ee8 push {r4, r5, r6, lr}
 *   @0x2b3eec mov r2, #24
 *   @0x2b3ef0 ldr r3, [r3]
 *   @0x2b3ef4 mov r4, r0
 *   @0x2b3ef8 blx r3
 *   @0x2b3efc ldr r5, [pc, #0x44]
 *   @0x2b3f00 ldr r6, [pc, #0x44]
 *   @0x2b3f04 mov r3, #0
 *   @0x2b3f08 add r5, pc, r5
 *   @0x2b3f0c ldr r12, [pc, #0x3c]
 *   @0x2b3f10 ldr r1, [pc, #0x3c]
 *   @0x2b3f14 add r6, pc, r6
 *   @0x2b3f18 mov r2, #1
 *   @0x2b3f1c add r12, pc, r12
 *   @0x2b3f20 add r1, pc, r1
 *   @0x2b3f24 str r0, [r4, #0x190]
 *   @0x2b3f28 mov r4, r5
 *   @0x2b3f2c str r6, [r0]
 *   @0x2b3f30 stmib r0, {r4, r12}
 *   @0x2b3f34 str r1, [r0, #0xc]
 *   @0x2b3f38 strb r2, [r0, #0x14]
 *   @0x2b3f3c strb r3, [r0, #0x10]
 *   @0x2b3f40 strb r3, [r0, #0x11]
 *   @0x2b3f44 pop {r4, r5, r6, pc}
 *   @0x2b3f48 .word 0xfffff9a4
 *   @0x2b3f4c .word 0xfffffc90
 *   @0x2b3f50 .word 0xfffff9e4
 *   @0x2b3f54 .word 0xfffff974
 *
 * ══ §164/251 b2PulleyJoint::GetCurrentLengthA() const  0x2d119c  size 120  30 条（0x2d119c..0x2d1214）
 * @func 0x2d119c 0x2d1228  size 140  35 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6700
 * 字段偏移 top8: 0x30×1
 * VFP 指令 24 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d119c vldr s9, [r0, #96]
 *   @0x2d11a0 push {r3, lr}
 *   @0x2d11a4 vldr s12, [r0, #92]
 *   @0x2d11a8 vldr s6, [r0, #72]
 *   @0x2d11ac ldr r3, [r0, #0x30]
 *   @0x2d11b0 vldr s11, [r3, #24]
 *   @0x2d11b4 vmul.f32 s13, s11, s9
 *   @0x2d11b8 vldr s10, [r3, #20]
 *   @0x2d11bc vldr s14, [r3, #16]
 *   @0x2d11c0 vldr s7, [r3, #12]
 *   @0x2d11c4 vldr s8, [r0, #68]
 *   @0x2d11c8 vmul.f32 s15, s10, s9
 *   @0x2d11cc vmla.f32 s13, s12, s10
 *   @0x2d11d0 vnmls.f32 s15, s11, s12
 *   @0x2d11d4 vadd.f32 s14, s13, s14
 *   @0x2d11d8 vsub.f32 s14, s14, s6
 *   @0x2d11dc vadd.f32 s15, s15, s7
 *   @0x2d11e0 vmul.f32 s14, s14, s14
 *   @0x2d11e4 vsub.f32 s15, s15, s8
 *   @0x2d11e8 vmla.f32 s14, s15, s15
 *   @0x2d11ec vsqrt.f32 s15, s14
 *   @0x2d11f0 vcmp.f32 s15, s15
 *   @0x2d11f4 vmrs APSR_nzcv, fpscr
 *   @0x2d11f8 bne 0x2d1204 <_ZNK13b2PulleyJoint17GetCurrentLengthAEv+0x68>
 *   @0x2d11fc vmov r0, s15
 *   @0x2d1200 pop {r3, pc}
 *   @0x2d1204 vmov r0, s14
 *   @0x2d1208 bl 0xb6700 <sqrtf@plt>
 *   @0x2d120c vmov s15, r0
 *   @0x2d1210 b 0x2d11fc <_ZNK13b2PulleyJoint17GetCurrentLengthAEv+0x60>
 *
 * ══ §165/251 b2PulleyJoint::GetCurrentLengthB() const  0x2d1214  size 120  30 条（0x2d1214..0x2d128c）
 * @func 0x2d1214 0x2d128c  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6700
 * 字段偏移 top8: 0x34×1
 * VFP 指令 24 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d1214 vldr s9, [r0, #104]
 *   @0x2d1218 push {r3, lr}
 *   @0x2d121c vldr s12, [r0, #100]
 *   @0x2d1220 vldr s6, [r0, #80]
 *   @0x2d1224 ldr r3, [r0, #0x34]
 *   @0x2d1228 vldr s11, [r3, #24]
 *   @0x2d122c vmul.f32 s13, s11, s9
 *   @0x2d1230 vldr s10, [r3, #20]
 *   @0x2d1234 vldr s14, [r3, #16]
 *   @0x2d1238 vldr s7, [r3, #12]
 *   @0x2d123c vldr s8, [r0, #76]
 *   @0x2d1240 vmul.f32 s15, s10, s9
 *   @0x2d1244 vmla.f32 s13, s12, s10
 *   @0x2d1248 vnmls.f32 s15, s11, s12
 *   @0x2d124c vadd.f32 s14, s13, s14
 *   @0x2d1250 vsub.f32 s14, s14, s6
 *   @0x2d1254 vadd.f32 s15, s15, s7
 *   @0x2d1258 vmul.f32 s14, s14, s14
 *   @0x2d125c vsub.f32 s15, s15, s8
 *   @0x2d1260 vmla.f32 s14, s15, s15
 *   @0x2d1264 vsqrt.f32 s15, s14
 *   @0x2d1268 vcmp.f32 s15, s15
 *   @0x2d126c vmrs APSR_nzcv, fpscr
 *   @0x2d1270 bne 0x2d127c <_ZNK13b2PulleyJoint17GetCurrentLengthBEv+0x68>
 *   @0x2d1274 vmov r0, s15
 *   @0x2d1278 pop {r3, pc}
 *   @0x2d127c vmov r0, s14
 *   @0x2d1280 bl 0xb6700 <sqrtf@plt>
 *   @0x2d1284 vmov s15, r0
 *   @0x2d1288 b 0x2d1274 <_ZNK13b2PulleyJoint17GetCurrentLengthBEv+0x60>
 *
 * ══ §166/251 b2Vec2* b2ParticleSystem::ReallocateBuffer<b2Vec2>(b2ParticleSystem::ParticleBuffer<b2Vec2>*, int, int, bool)  0x2da090  size 120  30 条（0x2da090..0x2da108）
 * @func 0x2da090 0x2da108  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2BlockAllocator::Allocate(int) / 0xb65bc / b2BlockAllocator::Free(void*, int)
 * 字段偏移 top8: 0xd4×2 / 0x18×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2da090 push {r3, r4, r5, r6, r7, lr}
 *   @0x2da094 mov r6, r0
 *   @0x2da098 ldrb r12, [sp, #0x18]
 *   @0x2da09c ldr r4, [r1]
 *   @0x2da0a0 eor r12, r12, #1
 *   @0x2da0a4 ldr r5, [r1, #0x4]
 *   @0x2da0a8 cmp r4, #0
 *   @0x2da0ac orrne r12, r12, #1
 *   @0x2da0b0 cmp r12, #0
 *   @0x2da0b4 moveq r4, r12
 *   @0x2da0b8 bne 0x2da0c4 <_ZN16b2ParticleSystem16ReallocateBufferI6b2Vec2EEPT_PNS_14ParticleBufferIS2_EEiib+0x34>
 *   @0x2da0bc mov r0, r4
 *   @0x2da0c0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x2da0c4 cmp r5, #0
 *   @0x2da0c8 bne 0x2da0bc <_ZN16b2ParticleSystem16ReallocateBufferI6b2Vec2EEPT_PNS_14ParticleBufferIS2_EEiib+0x2c>
 *   @0x2da0cc lsl r1, r3, #3
 *   @0x2da0d0 ldr r0, [r0, #0xd4]
 *   @0x2da0d4 lsl r5, r2, #3
 *   @0x2da0d8 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2da0dc mov r1, r4
 *   @0x2da0e0 mov r2, r5
 *   @0x2da0e4 mov r7, r0
 *   @0x2da0e8 bl 0xb65bc <memcpy@plt>
 *   @0x2da0ec ldr r0, [r6, #0xd4]
 *   @0x2da0f0 mov r1, r4
 *   @0x2da0f4 mov r2, r5
 *   @0x2da0f8 mov r4, r7
 *   @0x2da0fc bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2da100 mov r0, r4
 *   @0x2da104 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §167/251 FT_MulDiv  0x2e4d3c  size 118  30 条（0x2e4d3c..0x2e4db2）
 * @func 0x2e4d3c 0x2e4db4  size 120  30 条
 * 部分覆盖: 本节 30/56 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FT_MulDiv+0x3c
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e4d3c push {r0, r1, r4, r5, r6, lr}
 *   @0x2e4d40 it lt
 *   @0x2e4d44 mov r4, r2
 *   @0x2e4d48 movlt.w r5, #0xffffffff
 *   @0x2e4d4c movge r5, #0x1
 *   @0x2e4d50 itt lt
 *   @0x2e4d54 rsblt r1, r1, #0
 *   @0x2e4d58 itt lt
 *   @0x2e4d5c rsblt r5, r5, #0
 *   @0x2e4d60 lsrs r3, r4, #0x11
 *   @0x2e4d64 rsb.w r3, r3, #0x1fa00
 *   @0x2e4d68 lsrs r6, r4, #0x1
 *   @0x2e4d6c addsmi r7, r3, #-872415230
 *   @0x2e4d70 blo 0x2e4d78 <FT_MulDiv+0x3c>
 *   @0x2e4d74 and r6, r11, r1
 *   @0x2e4d78 mov r2, sp
 *   @0x2e4d7c stmdbls r0, {r0, r1, r2, r6, r7, r8, r10, r11, r12, sp, lr, pc}
 *   @0x2e4d80 ldr r3, [sp, #0x4]
 *   @0x2e4d84 ite lo
 *   @0x2e4d88 movhs r0, #0x1
 *   @0x2e4d8c bne 0x2e4d98 <FT_MulDiv+0x5c>
 *   @0x2e4d90 mov r1, r4
 *   @0x2e4d94 and lr, r7, r10, asr pc
 *   @0x2e4d98 cmp r0, r4
 *   @0x2e4d9c mov r2, r4
 *   @0x2e4da0 and pc, r1, lr, asr #30
 *   @0x2e4da4 mvn r0, #0x80000000
 *   @0x2e4da8 adds r5, #0x1
 *   @0x2e4dac rsbeq r0, r0, #0
 *   @0x2e4db0 pop {r4, r5, r6, pc}
 *
 * ══ §168/251 FT_GlyphLoader_CopyPoints  0x2e81fe  size 118  30 条（0x2e81fe..0x2e8274）
 * @func 0x2e81fe 0x2e8276  size 120  30 条
 * 部分覆盖: 本节 30/51 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65bc×2 / FT_GlyphLoader_CheckPoints / anon_2e490c+0x38
 * 字段偏移 top8: 0x1c×2 / 0x18×1 / 0x20×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e81fe push.w {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2e8202 mov r5, r1
 *   @0x2e8206 .word 0x4604a016
 *   @0x2e820a ldrh.w r9, [r1, #0x14]
 *   @0x2e820e sxth.w r7, r10
 *   @0x2e8212 sxth.w r11, r9
 *   @0x2e8216 mov r1, r7
 *   @0x2e821a bl 0x2e8106 <FT_GlyphLoader_CheckPoints>
 *   @0x2e821e mov r8, r0
 *   @0x2e8222 lsls r6, r7, #0x3
 *   @0x2e8226 ldr r0, [r4, #0x18]
 *   @0x2e822a blx 0xb65bc <memcpy@plt>
 *   @0x2e822e ldr r1, [r5, #0x1c]
 *   @0x2e8232 ldr r0, [r4, #0x1c]
 *   @0x2e8236 bvs 0xb22946 <b2_toiTime+0x3c94a2>
 *   @0x2e823a ldr r1, [r5, #0x20]
 *   @0x2e823e .word 0xf5ce024b
 *   @0x2e8242 stcvc p9, c14, [r3], #-752
 *   @0x2e8246 cbz r3, 0x2e8260 <FT_GlyphLoader_CopyPoints+0x62>
 *   @0x2e824a cbz r3, 0x2e8260 <FT_GlyphLoader_CopyPoints+0x62>
 *   @0x2e824e mov r2, r6
 *   @0x2e8252 blx 0xb65bc <memcpy@plt>
 *   @0x2e8256 ldr r0, [r4, #0x2c]
 *   @0x2e825a mov r2, r6
 *   @0x2e825e .word 0xf8a4e9ae
 *   @0x2e8262 qadd16mi r10, r0, r6
 *   @0x2e8266 strh.w r9, [r4, #0x14]
 *   @0x2e826a bl 0x2e4944 <_ZNK11b2GearJoint8GetRatioEv+0x40>
 *   @0x2e826e mov r0, r8
 *   @0x2e8272 ldrlt r8, [r0, #-0xff8]!
 *
 * ══ §169/251 ASYNC_SAVE_LOAD_REQ_CONTEXT::~ASYNC_SAVE_LOAD_REQ_CONTEXT()  0xc66ac  size 116  29 条（0xc66ac..0xc6720）
 * @func 0xc66ac 0xc6720  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×3 / HTTP_REQ_CONTEXT::~HTTP_REQ_CONTEXT() / operator delete(void*)
 * 字段偏移 top8: 0x44×2 / 0x48×2 / 0x5c×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc66ac push {r4, r5, r6, lr}
 *   @0xc66b0 mov r6, r0
 *   @0xc66b4 ldr r4, [r0, #0x44]
 *   @0xc66b8 ldr r3, [pc, #0x5c]
 *   @0xc66bc cmp r4, #0
 *   @0xc66c0 ldr r3, [pc, r3]
 *   @0xc66c4 add r3, r3, #8
 *   @0xc66c8 str r3, [r0]
 *   @0xc66cc beq 0xc66f0 <_ZN27ASYNC_SAVE_LOAD_REQ_CONTEXTD0Ev+0x44>
 *   @0xc66d0 ldr r5, [r4]
 *   @0xc66d4 ldr r0, [r4, #0x8]
 *   @0xc66d8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xc66dc ldr r0, [r4, #0xc]
 *   @0xc66e0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xc66e4 cmp r5, #0
 *   @0xc66e8 mov r4, r5
 *   @0xc66ec bne 0xc66d0 <_ZN27ASYNC_SAVE_LOAD_REQ_CONTEXTD0Ev+0x24>
 *   @0xc66f0 ldr r0, [r6, #0x48]
 *   @0xc66f4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xc66f8 mov r3, #0
 *   @0xc66fc mov r0, r6
 *   @0xc6700 str r3, [r6, #0x44]
 *   @0xc6704 str r3, [r6, #0x48]
 *   @0xc6708 bl 0x18d724 <_ZN16HTTP_REQ_CONTEXTD2Ev>
 *   @0xc670c mov r0, r6
 *   @0xc6710 bl 0x27d1d0 <_ZdlPv>
 *   @0xc6714 mov r0, r6
 *   @0xc6718 pop {r4, r5, r6, pc}
 *   @0xc671c ldrshteq r7, [r2], -r4
 *
 * ══ §170/251 F_Vertex_Float4_debug(RValue&, CInstance*, CInstance*, int, RValue*)  0xc9610  size 116  29 条（0xc9610..0xc9684）
 * @func 0xc9610 0xc9698  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4 / Init_Vertex_Write(RValue&, int, RValue*, int) / Buffer_Vertex::FindNextType(yyVertexType)
 * 字段偏移 top8: 0x10×1 / 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc9610 push {r3, r4, r5, lr}
 *   @0xc9614 mov r1, r3
 *   @0xc9618 ldr r4, [sp, #0x10]
 *   @0xc961c mov r3, #5
 *   @0xc9620 mov r2, r4
 *   @0xc9624 bl 0xc9188 <_Z17Init_Vertex_WriteR6RValueiPS_i>
 *   @0xc9628 cmp r0, #0
 *   @0xc962c popeq {r3, r4, r5, pc}
 *   @0xc9630 mov r1, #4
 *   @0xc9634 bl 0xc875c <_ZN13Buffer_Vertex12FindNextTypeE12yyVertexType>
 *   @0xc9638 subs r5, r0, #0
 *   @0xc963c popeq {r3, r4, r5, pc}
 *   @0xc9640 mov r1, #1
 *   @0xc9644 mov r0, r4
 *   @0xc9648 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc964c mov r1, #2
 *   @0xc9650 str r0, [r5]
 *   @0xc9654 mov r0, r4
 *   @0xc9658 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc965c mov r1, #3
 *   @0xc9660 str r0, [r5, #0x4]
 *   @0xc9664 mov r0, r4
 *   @0xc9668 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc966c mov r1, #4
 *   @0xc9670 str r0, [r5, #0x8]
 *   @0xc9674 mov r0, r4
 *   @0xc9678 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0xc967c str r0, [r5, #0xc]
 *   @0xc9680 pop {r3, r4, r5, pc}
 *
 * ══ §171/251 F_Vertex_ubyte4_debug(RValue&, CInstance*, CInstance*, int, RValue*)  0xc9684  size 116  29 条（0xc9684..0xc96f8）
 * @func 0xc9684 0xc96f8  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetUint32(RValue const*, int)×4 / Init_Vertex_Write(RValue&, int, RValue*, int) / Buffer_Vertex::FindNextType(yyVertexType)
 * 字段偏移 top8: 0x10×1 / 0x1×1 / 0x2×1 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc9684 push {r3, r4, r5, lr}
 *   @0xc9688 mov r1, r3
 *   @0xc968c ldr r4, [sp, #0x10]
 *   @0xc9690 mov r3, #5
 *   @0xc9694 mov r2, r4
 *   @0xc9698 bl 0xc9188 <_Z17Init_Vertex_WriteR6RValueiPS_i>
 *   @0xc969c cmp r0, #0
 *   @0xc96a0 popeq {r3, r4, r5, pc}
 *   @0xc96a4 mov r1, #6
 *   @0xc96a8 bl 0xc875c <_ZN13Buffer_Vertex12FindNextTypeE12yyVertexType>
 *   @0xc96ac subs r5, r0, #0
 *   @0xc96b0 popeq {r3, r4, r5, pc}
 *   @0xc96b4 mov r1, #1
 *   @0xc96b8 mov r0, r4
 *   @0xc96bc bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0xc96c0 mov r1, #2
 *   @0xc96c4 strb r0, [r5]
 *   @0xc96c8 mov r0, r4
 *   @0xc96cc bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0xc96d0 mov r1, #3
 *   @0xc96d4 strb r0, [r5, #0x1]
 *   @0xc96d8 mov r0, r4
 *   @0xc96dc bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0xc96e0 mov r1, #4
 *   @0xc96e4 strb r0, [r5, #0x2]
 *   @0xc96e8 mov r0, r4
 *   @0xc96ec bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0xc96f0 strb r0, [r5, #0x3]
 *   @0xc96f4 pop {r3, r4, r5, pc}
 *
 * ══ §172/251 Code_Constant_Find_IgnoreCase(char const*)  0xedc8c  size 116  29 条（0xedc8c..0xedd00）
 * @func 0xedc8c 0xedd00  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Code_Constant_Find_IgnoreCase(char const*)+0x60 / 0xb66d0
 * 字段偏移 top8: 0x60×1 / 0x48×1 / 0x-4×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xedc8c ldr r3, [pc, #0x60]
 *   @0xedc90 push {r4, r5, r6, lr}
 *   @0xedc94 ldr r3, [pc, r3]
 *   @0xedc98 mov r6, r0
 *   @0xedc9c ldr r3, [r3]
 *   @0xedca0 subs r4, r3, #1
 *   @0xedca4 bmi 0xedcec <_Z29Code_Constant_Find_IgnoreCasePKc+0x60>
 *   @0xedca8 ldr r2, [pc, #0x48]
 *   @0xedcac ldr r2, [pc, r2]
 *   @0xedcb0 ldr r5, [r2]
 *   @0xedcb4 add r5, r5, r3, lsl #2
 *   @0xedcb8 b 0xedcc4 <_Z29Code_Constant_Find_IgnoreCasePKc+0x38>
 *   @0xedcbc subs r4, r4, #1
 *   @0xedcc0 blo 0xedcec <_Z29Code_Constant_Find_IgnoreCasePKc+0x60>
 *   @0xedcc4 ldr r0, [r5, #-0x4]!
 *   @0xedcc8 mov r1, r6
 *   @0xedccc bl 0xb66d0 <strcasecmp@plt>
 *   @0xedcd0 cmp r0, #0
 *   @0xedcd4 bne 0xedcbc <_Z29Code_Constant_Find_IgnoreCasePKc+0x30>
 *   @0xedcd8 ldr r3, [pc, #0x1c]
 *   @0xedcdc ldr r3, [pc, r3]
 *   @0xedce0 ldr r0, [r3]
 *   @0xedce4 add r0, r0, r4, lsl #4
 *   @0xedce8 pop {r4, r5, r6, pc}
 *   @0xedcec mov r0, #0
 *   @0xedcf0 pop {r4, r5, r6, pc}
 *   @0xedcf4 eorseq r0, r0, r0, lsr r1
 *   @0xedcf8 eorseq r0, r0, r12, lsl r1
 *   @0xedcfc ldrshteq r0, [r0], -r0
 *
 * ══ §173/251 DIALOG_REQ_CONTEXT::~DIALOG_REQ_CONTEXT()  0xf1ca8  size 116  29 条（0xf1ca8..0xf1d1c）
 * @func 0xf1ca8 0xf1d1c  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb655c×3 / HTTP_REQ_CONTEXT::~HTTP_REQ_CONTEXT()
 * 字段偏移 top8: 0x48×2 / 0x4c×2 / 0x50×2 / 0x5c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf1ca8 push {r4, lr}
 *   @0xf1cac mov r4, r0
 *   @0xf1cb0 ldr r0, [r0, #0x48]
 *   @0xf1cb4 ldr r3, [pc, #0x5c]
 *   @0xf1cb8 cmp r0, #0
 *   @0xf1cbc ldr r3, [pc, r3]
 *   @0xf1cc0 add r3, r3, #8
 *   @0xf1cc4 str r3, [r4]
 *   @0xf1cc8 beq 0xf1cd8 <_ZN18DIALOG_REQ_CONTEXTD2Ev+0x30>
 *   @0xf1ccc bl 0xb655c <free@plt>
 *   @0xf1cd0 mov r3, #0
 *   @0xf1cd4 str r3, [r4, #0x48]
 *   @0xf1cd8 ldr r0, [r4, #0x4c]
 *   @0xf1cdc cmp r0, #0
 *   @0xf1ce0 beq 0xf1cf0 <_ZN18DIALOG_REQ_CONTEXTD2Ev+0x48>
 *   @0xf1ce4 bl 0xb655c <free@plt>
 *   @0xf1ce8 mov r3, #0
 *   @0xf1cec str r3, [r4, #0x4c]
 *   @0xf1cf0 ldr r0, [r4, #0x50]
 *   @0xf1cf4 cmp r0, #0
 *   @0xf1cf8 beq 0xf1d08 <_ZN18DIALOG_REQ_CONTEXTD2Ev+0x60>
 *   @0xf1cfc bl 0xb655c <free@plt>
 *   @0xf1d00 mov r3, #0
 *   @0xf1d04 str r3, [r4, #0x50]
 *   @0xf1d08 mov r0, r4
 *   @0xf1d0c bl 0x18d724 <_ZN16HTTP_REQ_CONTEXTD2Ev>
 *   @0xf1d10 mov r0, r4
 *   @0xf1d14 pop {r4, pc}
 *   @0xf1d18 eoreq r12, pc, r4, lsr #2
 *
 * ══ §174/251 MessageDialogASync(HTTP_REQ_CONTEXT*, void*, int*)  0xf21a0  size 116  29 条（0xf21a0..0xf2214）
 * @func 0xf21a0 0xf2214  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CreateDsMap(int, ...) / RemoveDialogAndKick(HTTP_REQ_CONTEXT*)
 * 字段偏移 top8: 0x24×1 / 0x4c×1 / 0x4×1 / 0x30×1 / 0x10×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf21a0 vldr s14, [r0, #40]
 *   @0xf21a4 vcvt.f64.s32 d7, s14
 *   @0xf21a8 push {r4, r5, lr}
 *   @0xf21ac mov r5, r2
 *   @0xf21b0 ldr r2, [r0, #0x24]
 *   @0xf21b4 sub sp, sp, #28
 *   @0xf21b8 ldr r1, [pc, #0x4c]
 *   @0xf21bc mov r4, r0
 *   @0xf21c0 mov r3, #0
 *   @0xf21c4 mov r0, #2
 *   @0xf21c8 add r1, pc, r1
 *   @0xf21cc str r1, [sp, #0x4]
 *   @0xf21d0 vstr d7, [sp, #8]
 *   @0xf21d4 vmov s15, r2
 *   @0xf21d8 ldr r1, [pc, #0x30]
 *   @0xf21dc vcvt.f64.s32 d7, s15
 *   @0xf21e0 str r3, [sp]
 *   @0xf21e4 str r3, [sp, #0x10]
 *   @0xf21e8 add r1, pc, r1
 *   @0xf21ec vmov r2, r3, d7
 *   @0xf21f0 bl 0x20bdc0 <_Z11CreateDsMapiz>
 *   @0xf21f4 str r0, [r5]
 *   @0xf21f8 mov r0, r4
 *   @0xf21fc bl 0xf1d98 <_Z19RemoveDialogAndKickP16HTTP_REQ_CONTEXT>
 *   @0xf2200 mov r0, #63
 *   @0xf2204 add sp, sp, #28
 *   @0xf2208 pop {r4, r5, pc}
 *   @0xf220c eoreq lr, r3, r8, lsl #17
 *   @0xf2210 eoreq lr, r3, r8, asr r8
 *
 * ══ §175/251 F_DsPriorityDeleteValue(RValue&, CInstance*, CInstance*, int, RValue*)  0xfcdd4  size 116  29 条（0xfcdd4..0xfce48）
 * @func 0xfcdd4 0xfce5c  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_DsPriorityDeleteValue(RValue&, CInstance*, CInstance*, int, RValue*)+0x54
 * 字段偏移 top8: 0x8×1 / 0x44×1 / 0x34×1 / 0x4×1 / 0x2×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfcdd4 push {r4, lr}
 *   @0xfcdd8 mov r1, #0
 *   @0xfcddc ldr r4, [sp, #0x8]
 *   @0xfcde0 mov r0, r4
 *   @0xfcde4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfcde8 cmp r0, #0
 *   @0xfcdec blt 0xfce28 <_Z23F_DsPriorityDeleteValueR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0xfcdf0 ldr r3, [pc, #0x44]
 *   @0xfcdf4 ldr r3, [pc, r3]
 *   @0xfcdf8 ldr r3, [r3]
 *   @0xfcdfc cmp r0, r3
 *   @0xfce00 bge 0xfce28 <_Z23F_DsPriorityDeleteValueR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0xfce04 ldr r3, [pc, #0x34]
 *   @0xfce08 ldr r3, [pc, r3]
 *   @0xfce0c ldr r3, [r3, #0x4]
 *   @0xfce10 ldr r0, [r3, r0, lsl #2]
 *   @0xfce14 cmp r0, #0
 *   @0xfce18 beq 0xfce28 <_Z23F_DsPriorityDeleteValueR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0xfce1c add r1, r4, #16
 *   @0xfce20 pop {r4, lr}
 *   @0xfce24 b 0x20a424 <_ZN12CDS_Priority6DeleteEP6RValue>
 *   @0xfce28 ldr r0, [pc, #0x14]
 *   @0xfce2c mov r1, #0
 *   @0xfce30 pop {r4, lr}
 *   @0xfce34 add r0, pc, r0
 *   @0xfce38 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfce3c eoreq r1, pc, r0, lsl #1
 *   @0xfce40 eoreq r1, pc, r0, ror r0
 *   @0xfce44 eoreq r10, r3, r8, asr #27
 *
 * ══ §176/251 F_DsPriorityDeleteMin(RValue&, CInstance*, CInstance*, int, RValue*)  0xfce48  size 116  29 条（0xfce48..0xfcebc）
 * @func 0xfce48 0xfced0  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_DsPriorityDeleteMin(RValue&, CInstance*, CInstance*, int, RValue*)+0x54
 * 字段偏移 top8: 0x8×1 / 0x44×1 / 0x34×1 / 0x4×1 / 0x2×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfce48 push {r4, lr}
 *   @0xfce4c mov r1, #0
 *   @0xfce50 mov r4, r0
 *   @0xfce54 ldr r0, [sp, #0x8]
 *   @0xfce58 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfce5c cmp r0, #0
 *   @0xfce60 blt 0xfce9c <_Z21F_DsPriorityDeleteMinR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0xfce64 ldr r3, [pc, #0x44]
 *   @0xfce68 ldr r3, [pc, r3]
 *   @0xfce6c ldr r3, [r3]
 *   @0xfce70 cmp r0, r3
 *   @0xfce74 bge 0xfce9c <_Z21F_DsPriorityDeleteMinR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0xfce78 ldr r3, [pc, #0x34]
 *   @0xfce7c ldr r3, [pc, r3]
 *   @0xfce80 ldr r3, [r3, #0x4]
 *   @0xfce84 ldr r0, [r3, r0, lsl #2]
 *   @0xfce88 cmp r0, #0
 *   @0xfce8c beq 0xfce9c <_Z21F_DsPriorityDeleteMinR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0xfce90 mov r1, r4
 *   @0xfce94 pop {r4, lr}
 *   @0xfce98 b 0x20a99c <_ZN12CDS_Priority9DeleteMinEP6RValue>
 *   @0xfce9c ldr r0, [pc, #0x14]
 *   @0xfcea0 mov r1, #0
 *   @0xfcea4 pop {r4, lr}
 *   @0xfcea8 add r0, pc, r0
 *   @0xfceac b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfceb0 eoreq r1, pc, r12
 *   @0xfceb4 .word 0x002f0ffc
 *   @0xfceb8 eoreq r10, r3, r4, asr sp
 *
 * ══ §177/251 F_DsPriorityDeleteMax(RValue&, CInstance*, CInstance*, int, RValue*)  0xfcebc  size 116  29 条（0xfcebc..0xfcf30）
 * @func 0xfcebc 0xfcf30  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_DsPriorityDeleteMax(RValue&, CInstance*, CInstance*, int, RValue*)+0x54
 * 字段偏移 top8: 0x8×1 / 0x44×1 / 0x34×1 / 0x4×1 / 0x2×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfcebc push {r4, lr}
 *   @0xfcec0 mov r1, #0
 *   @0xfcec4 mov r4, r0
 *   @0xfcec8 ldr r0, [sp, #0x8]
 *   @0xfcecc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfced0 cmp r0, #0
 *   @0xfced4 blt 0xfcf10 <_Z21F_DsPriorityDeleteMaxR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0xfced8 ldr r3, [pc, #0x44]
 *   @0xfcedc ldr r3, [pc, r3]
 *   @0xfcee0 ldr r3, [r3]
 *   @0xfcee4 cmp r0, r3
 *   @0xfcee8 bge 0xfcf10 <_Z21F_DsPriorityDeleteMaxR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0xfceec ldr r3, [pc, #0x34]
 *   @0xfcef0 ldr r3, [pc, r3]
 *   @0xfcef4 ldr r3, [r3, #0x4]
 *   @0xfcef8 ldr r0, [r3, r0, lsl #2]
 *   @0xfcefc cmp r0, #0
 *   @0xfcf00 beq 0xfcf10 <_Z21F_DsPriorityDeleteMaxR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0xfcf04 mov r1, r4
 *   @0xfcf08 pop {r4, lr}
 *   @0xfcf0c b 0x20accc <_ZN12CDS_Priority9DeleteMaxEP6RValue>
 *   @0xfcf10 ldr r0, [pc, #0x14]
 *   @0xfcf14 mov r1, #0
 *   @0xfcf18 pop {r4, lr}
 *   @0xfcf1c add r0, pc, r0
 *   @0xfcf20 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfcf24 mlaeq pc, r8, pc, r0
 *   @0xfcf28 eoreq r0, pc, r8, lsl #31
 *   @0xfcf2c eoreq r10, r3, r0, ror #25
 *
 * ══ §178/251 F_DsGridClear(RValue&, CInstance*, CInstance*, int, RValue*)  0xfd25c  size 116  29 条（0xfd25c..0xfd2d0）
 * @func 0xfd25c 0xfd2d0  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_DsGridClear(RValue&, CInstance*, CInstance*, int, RValue*)+0x54
 * 字段偏移 top8: 0x8×1 / 0x44×1 / 0x34×1 / 0x4×1 / 0x2×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfd25c push {r4, lr}
 *   @0xfd260 mov r1, #0
 *   @0xfd264 ldr r4, [sp, #0x8]
 *   @0xfd268 mov r0, r4
 *   @0xfd26c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfd270 cmp r0, #0
 *   @0xfd274 blt 0xfd2b0 <_Z13F_DsGridClearR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0xfd278 ldr r3, [pc, #0x44]
 *   @0xfd27c ldr r3, [pc, r3]
 *   @0xfd280 ldr r3, [r3]
 *   @0xfd284 cmp r0, r3
 *   @0xfd288 bge 0xfd2b0 <_Z13F_DsGridClearR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0xfd28c ldr r3, [pc, #0x34]
 *   @0xfd290 ldr r3, [pc, r3]
 *   @0xfd294 ldr r3, [r3, #0x4]
 *   @0xfd298 ldr r0, [r3, r0, lsl #2]
 *   @0xfd29c cmp r0, #0
 *   @0xfd2a0 beq 0xfd2b0 <_Z13F_DsGridClearR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0xfd2a4 add r1, r4, #16
 *   @0xfd2a8 pop {r4, lr}
 *   @0xfd2ac b 0x20c120 <_ZN8CDS_Grid5ClearEP6RValue>
 *   @0xfd2b0 ldr r0, [pc, #0x14]
 *   @0xfd2b4 mov r1, #0
 *   @0xfd2b8 pop {r4, lr}
 *   @0xfd2bc add r0, pc, r0
 *   @0xfd2c0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfd2c4 eoreq r0, pc, r8, lsl #24
 *   @0xfd2c8 .word 0x002f0bf8
 *   @0xfd2cc eoreq r10, r3, r0, asr #18
 *
 * ══ §179/251 F_Sqrt(RValue&, CInstance*, CInstance*, int, RValue*)  0x10f770  size 116  29 条（0x10f770..0x10f7e4）
 * @func 0x10f770 0x10f7e4  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / F_Sqrt(RValue&, CInstance*, CInstance*, int, RValue*)+0x50 / 0xb66f4
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x18×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10f770 push {r3, r4, r5, lr}
 *   @0x10f774 mov r4, #0
 *   @0x10f778 ldr r3, [sp, #0x10]
 *   @0x10f77c mov r5, r0
 *   @0x10f780 str r4, [r0, #0xc]
 *   @0x10f784 mov r1, r4
 *   @0x10f788 mov r0, r3
 *   @0x10f78c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x10f790 vmov d7, r0, r1
 *   @0x10f794 vcmpe.f64 d7, #0
 *   @0x10f798 vmrs APSR_nzcv, fpscr
 *   @0x10f79c blt 0x10f7c0 <_Z6F_SqrtR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x10f7a0 vsqrt.f64 d7, d7
 *   @0x10f7a4 vcmp.f64 d7, d7
 *   @0x10f7a8 vmrs APSR_nzcv, fpscr
 *   @0x10f7ac bne 0x10f7d4 <_Z6F_SqrtR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x10f7b0 vmov r2, s14
 *   @0x10f7b4 vmov r3, s15
 *   @0x10f7b8 stm r5, {r2, r3}
 *   @0x10f7bc pop {r3, r4, r5, pc}
 *   @0x10f7c0 ldr r0, [pc, #0x18]
 *   @0x10f7c4 mov r1, r4
 *   @0x10f7c8 pop {r3, r4, r5, lr}
 *   @0x10f7cc add r0, pc, r0
 *   @0x10f7d0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x10f7d4 bl 0xb66f4 <sqrt@plt>
 *   @0x10f7d8 vmov d7, r0, r1
 *   @0x10f7dc b 0x10f7b0 <_Z6F_SqrtR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x10f7e0 eoreq r9, r2, r12, lsr #15
 *
 * ══ §180/251 F_Ord(RValue&, CInstance*, CInstance*, int, RValue*)  0x10fc4c  size 116  29 条（0x10fc4c..0x10fcc0）
 * @func 0x10fc4c 0x10fcc0  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / utf8_extract_char
 * 字段偏移 top8: 0x4×2 / 0x10×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10fc4c push {r4, lr}
 *   @0x10fc50 sub sp, sp, #8
 *   @0x10fc54 mov r4, r0
 *   @0x10fc58 mov r1, #0
 *   @0x10fc5c ldr r0, [sp, #0x10]
 *   @0x10fc60 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x10fc64 mov r3, #0
 *   @0x10fc68 str r3, [r4, #0xc]
 *   @0x10fc6c cmp r0, #0
 *   @0x10fc70 str r0, [sp, #0x4]
 *   @0x10fc74 beq 0x10fc84 <_Z5F_OrdR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x10fc78 ldrb r3, [r0]
 *   @0x10fc7c cmp r3, #0
 *   @0x10fc80 bne 0x10fc98 <_Z5F_OrdR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x10fc84 mov r3, #0
 *   @0x10fc88 str r3, [r4]
 *   @0x10fc8c str r3, [r4, #0x4]
 *   @0x10fc90 add sp, sp, #8
 *   @0x10fc94 pop {r4, pc}
 *   @0x10fc98 add r0, sp, #4
 *   @0x10fc9c bl 0x10fb38 <utf8_extract_char>
 *   @0x10fca0 vmov s15, r0
 *   @0x10fca4 vcvt.f64.u32 d7, s15
 *   @0x10fca8 vmov r0, r1, d7
 *   @0x10fcac vmov r2, s14
 *   @0x10fcb0 mov r3, r1
 *   @0x10fcb4 stm r4, {r2, r3}
 *   @0x10fcb8 add sp, sp, #8
 *   @0x10fcbc pop {r4, pc}
 *
 * ══ §181/251 YYGML_lengthdir_x(float, float)  0x111acc  size 116  29 条（0x111acc..0x111b40）
 * @func 0x111acc 0x111b40  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb658c / 0xb67f0
 * 字段偏移 top8: 0x-4×1 / 0x4×1
 * VFP 指令 19 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x111acc vmov s13, r1
 *   @0x111ad0 vldr s14, [pc, #92]
 *   @0x111ad4 vldr s15, [pc, #92]
 *   @0x111ad8 str lr, [sp, #-0x4]!
 *   @0x111adc vmul.f32 s14, s13, s14
 *   @0x111ae0 vpush {d8}
 *   @0x111ae4 vmov s16, r0
 *   @0x111ae8 sub sp, sp, #12
 *   @0x111aec vdiv.f32 s15, s14, s15
 *   @0x111af0 vmov r0, s15
 *   @0x111af4 bl 0xb658c <cosf@plt>
 *   @0x111af8 add r1, sp, #4
 *   @0x111afc vmov s15, r0
 *   @0x111b00 vmul.f32 s16, s15, s16
 *   @0x111b04 vmov r0, s16
 *   @0x111b08 bl 0xb67f0 <modff@plt>
 *   @0x111b0c vldr s15, [pc, #40]
 *   @0x111b10 vmov s13, r0
 *   @0x111b14 vabs.f32 s14, s13
 *   @0x111b18 vcmpe.f32 s14, s15
 *   @0x111b1c vmrs APSR_nzcv, fpscr
 *   @0x111b20 vldrmi s16, [sp, #4]
 *   @0x111b24 vmov r0, s16
 *   @0x111b28 add sp, sp, #12
 *   @0x111b2c vpop {d8}
 *   @0x111b30 ldr pc, [sp], #4
 *   @0x111b34 ldrdmi r0, r1, [r9], #-251
 *   @0x111b38 teqmi r4, #0
 *   @0x111b3c ldmlo r1, {r0, r1, r2, r4, r8, r9, r10, r12, sp, pc} ^
 *
 * ══ §182/251 YYGML_lengthdir_y(float, float)  0x111b94  size 116  29 条（0x111b94..0x111c08）
 * @func 0x111b94 0x111c08  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6580 / 0xb67f0
 * 字段偏移 top8: 0x-4×1 / 0x4×1
 * VFP 指令 19 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x111b94 vmov s13, r1
 *   @0x111b98 vldr s14, [pc, #92]
 *   @0x111b9c vldr s15, [pc, #92]
 *   @0x111ba0 str lr, [sp, #-0x4]!
 *   @0x111ba4 vmul.f32 s14, s13, s14
 *   @0x111ba8 vpush {d8}
 *   @0x111bac vmov s16, r0
 *   @0x111bb0 sub sp, sp, #12
 *   @0x111bb4 vdiv.f32 s15, s14, s15
 *   @0x111bb8 vmov r0, s15
 *   @0x111bbc bl 0xb6580 <sinf@plt>
 *   @0x111bc0 add r1, sp, #4
 *   @0x111bc4 vmov s15, r0
 *   @0x111bc8 vnmul.f32 s16, s16, s15
 *   @0x111bcc vmov r0, s16
 *   @0x111bd0 bl 0xb67f0 <modff@plt>
 *   @0x111bd4 vldr s15, [pc, #40]
 *   @0x111bd8 vmov s13, r0
 *   @0x111bdc vabs.f32 s14, s13
 *   @0x111be0 vcmpe.f32 s14, s15
 *   @0x111be4 vmrs APSR_nzcv, fpscr
 *   @0x111be8 vldrmi s16, [sp, #4]
 *   @0x111bec vmov r0, s16
 *   @0x111bf0 add sp, sp, #12
 *   @0x111bf4 vpop {d8}
 *   @0x111bf8 ldr pc, [sp], #4
 *   @0x111bfc ldrdmi r0, r1, [r9], #-251
 *   @0x111c00 teqmi r4, #0
 *   @0x111c04 ldmlo r1, {r0, r1, r2, r4, r8, r9, r10, r12, sp, pc} ^
 *
 * ══ §183/251 F_DateCompareDateTime(RValue&, CInstance*, CInstance*, int, RValue*)  0x115638  size 116  29 条（0x115638..0x1156ac）
 * @func 0x115638 0x1156ac  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×2
 * 字段偏移 top8: 0x18×1 / 0xc×1 / 0x4×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x115638 push {r3, r4, r5, lr}
 *   @0x11563c vpush {d8}
 *   @0x115640 mov r4, r0
 *   @0x115644 ldr r5, [sp, #0x18]
 *   @0x115648 mov r1, #0
 *   @0x11564c mov r0, r5
 *   @0x115650 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x115654 vmov d8, r0, r1
 *   @0x115658 mov r0, r5
 *   @0x11565c mov r1, #1
 *   @0x115660 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x115664 mov r3, #0
 *   @0x115668 str r3, [r4, #0xc]
 *   @0x11566c vmov d7, r0, r1
 *   @0x115670 vcmp.f64 d8, d7
 *   @0x115674 vmrs APSR_nzcv, fpscr
 *   @0x115678 moveq r2, r3
 *   @0x11567c beq 0x11569c <_Z21F_DateCompareDateTimeR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x115680 vcmpe.f64 d8, d7
 *   @0x115684 mov r1, r3
 *   @0x115688 mov r2, r3
 *   @0x11568c movt r1, #0x3ff0
 *   @0x115690 movt r2, #0xbff0
 *   @0x115694 vmrs APSR_nzcv, fpscr
 *   @0x115698 movgt r2, r1
 *   @0x11569c str r3, [r4]
 *   @0x1156a0 str r2, [r4, #0x4]
 *   @0x1156a4 vpop {d8}
 *   @0x1156a8 pop {r3, r4, r5, pc}
 *
 * ══ §184/251 F_BackgroundDelete(RValue&, CInstance*, CInstance*, int, RValue*)  0x12cac8  size 116  29 条（0x12cac8..0x12cb3c）
 * @func 0x12cac8 0x12cb3c  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Background_Exists(int) / Error_Show_Action(char const*, bool) / Background_Delete(int)
 * 字段偏移 top8: 0xc×2 / 0x10×1 / 0x44×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12cac8 push {r4, r5, r6, lr}
 *   @0x12cacc mov r1, #0
 *   @0x12cad0 mov r4, r0
 *   @0x12cad4 ldr r0, [sp, #0x10]
 *   @0x12cad8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12cadc mov r6, r0
 *   @0x12cae0 bl 0xc3640 <_Z17Background_Existsi>
 *   @0x12cae4 subs r5, r0, #0
 *   @0x12cae8 bne 0x12cb14 <_Z18F_BackgroundDeleteR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x12caec ldr r0, [pc, #0x44]
 *   @0x12caf0 mov r1, r5
 *   @0x12caf4 add r0, pc, r0
 *   @0x12caf8 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x12cafc str r5, [r4, #0xc]
 *   @0x12cb00 mov r3, #0
 *   @0x12cb04 mov r2, r3
 *   @0x12cb08 str r3, [r4]
 *   @0x12cb0c str r2, [r4, #0x4]
 *   @0x12cb10 pop {r4, r5, r6, pc}
 *   @0x12cb14 mov r0, r6
 *   @0x12cb18 bl 0xc3f74 <_Z17Background_Deletei>
 *   @0x12cb1c mov r3, #0
 *   @0x12cb20 str r3, [r4, #0xc]
 *   @0x12cb24 cmp r0, r3
 *   @0x12cb28 movne r2, #0
 *   @0x12cb2c movtne r2, #0x3ff0
 *   @0x12cb30 bne 0x12cb08 <_Z18F_BackgroundDeleteR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x12cb34 b 0x12cb00 <_Z18F_BackgroundDeleteR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x12cb38 .word 0x002109f0
 *
 * ══ §185/251 F_FontDelete(RValue&, CInstance*, CInstance*, int, RValue*)  0x12d31c  size 116  29 条（0x12d31c..0x12d390）
 * @func 0x12d31c 0x12d390  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Font_Exists(int) / Error_Show_Action(char const*, bool) / Font_Delete(int)
 * 字段偏移 top8: 0xc×2 / 0x10×1 / 0x44×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12d31c push {r4, r5, r6, lr}
 *   @0x12d320 mov r1, #0
 *   @0x12d324 mov r4, r0
 *   @0x12d328 ldr r0, [sp, #0x10]
 *   @0x12d32c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12d330 mov r6, r0
 *   @0x12d334 bl 0xfa2a8 <_Z11Font_Existsi>
 *   @0x12d338 subs r5, r0, #0
 *   @0x12d33c bne 0x12d368 <_Z12F_FontDeleteR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x12d340 ldr r0, [pc, #0x44]
 *   @0x12d344 mov r1, r5
 *   @0x12d348 add r0, pc, r0
 *   @0x12d34c bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x12d350 str r5, [r4, #0xc]
 *   @0x12d354 mov r3, #0
 *   @0x12d358 mov r2, r3
 *   @0x12d35c str r3, [r4]
 *   @0x12d360 str r2, [r4, #0x4]
 *   @0x12d364 pop {r4, r5, r6, pc}
 *   @0x12d368 mov r0, r6
 *   @0x12d36c bl 0xfabb8 <_Z11Font_Deletei>
 *   @0x12d370 mov r3, #0
 *   @0x12d374 str r3, [r4, #0xc]
 *   @0x12d378 cmp r0, r3
 *   @0x12d37c movne r2, #0
 *   @0x12d380 movtne r2, #0x3ff0
 *   @0x12d384 bne 0x12d35c <_Z12F_FontDeleteR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x12d388 b 0x12d354 <_Z12F_FontDeleteR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x12d38c eoreq r0, r1, r4, lsl #5
 *
 * ══ §186/251 F_PathDelete(RValue&, CInstance*, CInstance*, int, RValue*)  0x12da3c  size 116  29 条（0x12da3c..0x12dab0）
 * @func 0x12da3c 0x12dab0  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Path_Data(int) / Path_Delete(int) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x10×2 / 0xc×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12da3c push {r4, r5, r6, lr}
 *   @0x12da40 mov r1, #0
 *   @0x12da44 mov r4, r0
 *   @0x12da48 ldr r0, [sp, #0x10]
 *   @0x12da4c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12da50 mov r5, r0
 *   @0x12da54 bl 0x1a815c <_Z9Path_Datai>
 *   @0x12da58 subs r6, r0, #0
 *   @0x12da5c beq 0x12da94 <_Z12F_PathDeleteR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x12da60 mov r0, r5
 *   @0x12da64 bl 0x1a82a0 <_Z11Path_Deletei>
 *   @0x12da68 mov r3, #0
 *   @0x12da6c str r3, [r4, #0xc]
 *   @0x12da70 cmp r0, r3
 *   @0x12da74 movne r2, #0
 *   @0x12da78 movtne r2, #0x3ff0
 *   @0x12da7c bne 0x12da88 <_Z12F_PathDeleteR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x12da80 mov r3, #0
 *   @0x12da84 mov r2, r3
 *   @0x12da88 str r3, [r4]
 *   @0x12da8c str r2, [r4, #0x4]
 *   @0x12da90 pop {r4, r5, r6, pc}
 *   @0x12da94 ldr r0, [pc, #0x10]
 *   @0x12da98 mov r1, r6
 *   @0x12da9c add r0, pc, r0
 *   @0x12daa0 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x12daa4 str r6, [r4, #0xc]
 *   @0x12daa8 b 0x12da80 <_Z12F_PathDeleteR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x12daac eoreq pc, r0, r12, ror r11
 *
 * ══ §187/251 F_TimeLineDelete(RValue&, CInstance*, CInstance*, int, RValue*)  0x12dedc  size 116  29 条（0x12dedc..0x12df50）
 * @func 0x12dedc 0x12df50  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / TimeLine_Exists(int) / Error_Show_Action(char const*, bool) / TimeLine_Delete(int)
 * 字段偏移 top8: 0xc×2 / 0x10×1 / 0x44×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12dedc push {r4, r5, r6, lr}
 *   @0x12dee0 mov r1, #0
 *   @0x12dee4 mov r4, r0
 *   @0x12dee8 ldr r0, [sp, #0x10]
 *   @0x12deec bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12def0 mov r6, r0
 *   @0x12def4 bl 0x1f2b18 <_Z15TimeLine_Existsi>
 *   @0x12def8 subs r5, r0, #0
 *   @0x12defc bne 0x12df28 <_Z16F_TimeLineDeleteR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x12df00 ldr r0, [pc, #0x44]
 *   @0x12df04 mov r1, r5
 *   @0x12df08 add r0, pc, r0
 *   @0x12df0c bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x12df10 str r5, [r4, #0xc]
 *   @0x12df14 mov r3, #0
 *   @0x12df18 mov r2, r3
 *   @0x12df1c str r3, [r4]
 *   @0x12df20 str r2, [r4, #0x4]
 *   @0x12df24 pop {r4, r5, r6, pc}
 *   @0x12df28 mov r0, r6
 *   @0x12df2c bl 0x1f2fb4 <_Z15TimeLine_Deletei>
 *   @0x12df30 mov r3, #0
 *   @0x12df34 str r3, [r4, #0xc]
 *   @0x12df38 cmp r0, r3
 *   @0x12df3c movne r2, #0
 *   @0x12df40 movtne r2, #0x3ff0
 *   @0x12df44 bne 0x12df1c <_Z16F_TimeLineDeleteR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x12df48 b 0x12df14 <_Z16F_TimeLineDeleteR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x12df4c eoreq pc, r0, r4, lsr r7
 *
 * ══ §188/251 F_ObjectDelete(RValue&, CInstance*, CInstance*, int, RValue*)  0x12e164  size 116  29 条（0x12e164..0x12e1d8）
 * @func 0x12e164 0x12e1d8  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / Object_Exists(int) / Object_Delete(int) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0xc×2 / 0x10×1 / 0x4×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12e164 push {r4, r5, r6, lr}
 *   @0x12e168 mov r1, #0
 *   @0x12e16c mov r4, r0
 *   @0x12e170 ldr r0, [sp, #0x10]
 *   @0x12e174 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12e178 mov r6, r0
 *   @0x12e17c bl 0x19ecf8 <_Z13Object_Existsi>
 *   @0x12e180 subs r5, r0, #0
 *   @0x12e184 beq 0x12e1b4 <_Z14F_ObjectDeleteR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x12e188 mov r0, r6
 *   @0x12e18c bl 0x19f014 <_Z13Object_Deletei>
 *   @0x12e190 mov r3, #0
 *   @0x12e194 str r3, [r4, #0xc]
 *   @0x12e198 cmp r0, r3
 *   @0x12e19c movne r2, #0
 *   @0x12e1a0 movtne r2, #0x3ff0
 *   @0x12e1a4 beq 0x12e1c8 <_Z14F_ObjectDeleteR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x12e1a8 str r3, [r4]
 *   @0x12e1ac str r2, [r4, #0x4]
 *   @0x12e1b0 pop {r4, r5, r6, pc}
 *   @0x12e1b4 ldr r0, [pc, #0x18]
 *   @0x12e1b8 mov r1, r5
 *   @0x12e1bc add r0, pc, r0
 *   @0x12e1c0 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x12e1c4 str r5, [r4, #0xc]
 *   @0x12e1c8 mov r3, #0
 *   @0x12e1cc mov r2, r3
 *   @0x12e1d0 b 0x12e1a8 <_Z14F_ObjectDeleteR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x12e1d4 eoreq pc, r0, r8, lsr #9
 *
 * ══ §189/251 F_FileEof(RValue&, CInstance*, CInstance*, int, RValue*)  0x139a2c  size 116  29 条（0x139a2c..0x139aa0）
 * @func 0x139a2c 0x139aa0  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6874
 * 字段偏移 top8: 0x58×1 / 0x48×1 / 0x38×1 / 0xc×1 / 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x139a2c push {r3, r4, r5, lr}
 *   @0x139a30 mov r4, r0
 *   @0x139a34 ldr r3, [pc, #0x58]
 *   @0x139a38 ldr r3, [pc, r3]
 *   @0x139a3c ldr r3, [r3]
 *   @0x139a40 cmp r3, #1
 *   @0x139a44 beq 0x139a5c <_Z9F_FileEofR6RValueP9CInstanceS2_iPS_+0x30>
 *   @0x139a48 ldr r0, [pc, #0x48]
 *   @0x139a4c mov r1, #0
 *   @0x139a50 pop {r3, r4, r5, lr}
 *   @0x139a54 add r0, pc, r0
 *   @0x139a58 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x139a5c ldr r3, [pc, #0x38]
 *   @0x139a60 mov r5, #0
 *   @0x139a64 str r5, [r0, #0xc]
 *   @0x139a68 ldr r3, [pc, r3]
 *   @0x139a6c ldr r0, [r3, #0x8]
 *   @0x139a70 bl 0xb6874 <feof@plt>
 *   @0x139a74 cmp r0, #0
 *   @0x139a78 moveq r5, r0
 *   @0x139a7c movne r3, r5
 *   @0x139a80 moveq r3, r5
 *   @0x139a84 movtne r3, #0x3ff0
 *   @0x139a88 str r5, [r4]
 *   @0x139a8c str r3, [r4, #0x4]
 *   @0x139a90 pop {r3, r4, r5, pc}
 *   @0x139a94 eoreq r5, r11, r8, lsr r8
 *   @0x139a98 .word 0x002065dc
 *   @0x139a9c eoreq r5, r11, r12, lsl #16
 *
 * ══ §190/251 F_IniSectionExists(RValue&, CInstance*, CInstance*, int, RValue*)  0x13a248  size 116  29 条（0x13a248..0x13a2bc）
 * @func 0x13a248 0x13a2bc  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int) / IniFile::GetSection(char const*)
 * 字段偏移 top8: 0xc×2 / 0x8×1 / 0x50×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13a248 push {r4, lr}
 *   @0x13a24c mov r1, #0
 *   @0x13a250 mov r4, r0
 *   @0x13a254 ldr r0, [sp, #0x8]
 *   @0x13a258 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x13a25c ldr r3, [pc, #0x50]
 *   @0x13a260 ldr r3, [pc, r3]
 *   @0x13a264 mov r1, r0
 *   @0x13a268 ldr r0, [r3]
 *   @0x13a26c cmp r0, #0
 *   @0x13a270 beq 0x13a2a0 <_Z18F_IniSectionExistsR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x13a274 bl 0x235a90 <_ZN7IniFile10GetSectionEPKc>
 *   @0x13a278 mov r3, #0
 *   @0x13a27c str r3, [r4, #0xc]
 *   @0x13a280 cmp r0, #0
 *   @0x13a284 moveq r3, r0
 *   @0x13a288 movne r2, r3
 *   @0x13a28c moveq r2, r3
 *   @0x13a290 movtne r2, #0x3ff0
 *   @0x13a294 str r3, [r4]
 *   @0x13a298 str r2, [r4, #0x4]
 *   @0x13a29c pop {r4, pc}
 *   @0x13a2a0 mov r1, r0
 *   @0x13a2a4 ldr r0, [pc, #0xc]
 *   @0x13a2a8 pop {r4, lr}
 *   @0x13a2ac add r0, pc, r0
 *   @0x13a2b0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x13a2b4 eoreq r5, r11, r4, lsr r0
 *   @0x13a2b8 .word 0x00205fbc
 *
 * ══ §191/251 F_ActionSetMotion(RValue&, CInstance*, CInstance*, int, RValue*)  0x13d9b4  size 116  29 条（0x13d9b4..0x13da28）
 * @func 0x13d9b4 0x13da28  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / CInstance::SetDirection(float)
 * 字段偏移 top8: 0x10×1 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13d9b4 push {r4, r5, r6, lr}
 *   @0x13d9b8 mov r5, r1
 *   @0x13d9bc ldr r4, [sp, #0x10]
 *   @0x13d9c0 mov r1, #0
 *   @0x13d9c4 mov r0, r4
 *   @0x13d9c8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13d9cc mov r1, #1
 *   @0x13d9d0 mov r6, r0
 *   @0x13d9d4 mov r0, r4
 *   @0x13d9d8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13d9dc ldr r3, [pc, #0x40]
 *   @0x13d9e0 ldr r3, [pc, r3]
 *   @0x13d9e4 ldrb r3, [r3]
 *   @0x13d9e8 cmp r3, #0
 *   @0x13d9ec mov r4, r0
 *   @0x13d9f0 bne 0x13da10 <_Z17F_ActionSetMotionR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x13d9f4 mov r1, r6
 *   @0x13d9f8 mov r0, r5
 *   @0x13d9fc bl 0x193064 <_ZN9CInstance12SetDirectionEf>
 *   @0x13da00 mov r0, r5
 *   @0x13da04 mov r1, r4
 *   @0x13da08 pop {r4, r5, r6, lr}
 *   @0x13da0c b 0x1930d4 <_ZN9CInstance8SetSpeedEf>
 *   @0x13da10 mov r0, r5
 *   @0x13da14 mov r1, r6
 *   @0x13da18 mov r2, r4
 *   @0x13da1c pop {r4, r5, r6, lr}
 *   @0x13da20 b 0x193ec0 <_ZN9CInstance11AddTo_SpeedEff>
 *   @0x13da24 eoreq r0, r11, r12, asr r1
 *
 * ══ §192/251 YYGML_action_if_number(int, double, int)  0x141ca8  size 116  29 条（0x141ca8..0x141d1c）
 * @func 0x141ca8 0x141d30  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Command_InstanceNumber(int)
 * 字段偏移 top8: 0x10×1
 * VFP 指令 13 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x141ca8 push {r4, lr}
 *   @0x141cac vpush {d8}
 *   @0x141cb0 vmov d8, r2, r3
 *   @0x141cb4 ldr r4, [sp, #0x10]
 *   @0x141cb8 bl 0x1c8ed0 <_Z22Command_InstanceNumberi>
 *   @0x141cbc cmp r4, #1
 *   @0x141cc0 vmov s13, r0
 *   @0x141cc4 vcvt.f64.s32 d7, s13
 *   @0x141cc8 beq 0x141cec <_Z22YYGML_action_if_numberidi+0x44>
 *   @0x141ccc cmp r4, #2
 *   @0x141cd0 beq 0x141d04 <_Z22YYGML_action_if_numberidi+0x5c>
 *   @0x141cd4 vcmp.f64 d7, d8
 *   @0x141cd8 vpop {d8}
 *   @0x141cdc vmrs APSR_nzcv, fpscr
 *   @0x141ce0 movne r0, #0
 *   @0x141ce4 moveq r0, #1
 *   @0x141ce8 pop {r4, pc}
 *   @0x141cec vcmpe.f64 d7, d8
 *   @0x141cf0 vpop {d8}
 *   @0x141cf4 vmrs APSR_nzcv, fpscr
 *   @0x141cf8 movpl r0, #0
 *   @0x141cfc movmi r0, #1
 *   @0x141d00 pop {r4, pc}
 *   @0x141d04 vcmpe.f64 d7, d8
 *   @0x141d08 vpop {d8}
 *   @0x141d0c vmrs APSR_nzcv, fpscr
 *   @0x141d10 movle r0, #0
 *   @0x141d14 movgt r0, #1
 *   @0x141d18 pop {r4, pc}
 *
 * ══ §193/251 YYGML_action_if_variable(RValue const&, RValue const&, int)  0x141d1c  size 116  29 条（0x141d1c..0x141d90）
 * @func 0x141d1c 0x141d90  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYCompareVal(RValue const&, RValue const&, double)
 * 字段偏移 top8: 0x68×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x141d1c ldr r3, [pc, #0x68]
 *   @0x141d20 push {r4, lr}
 *   @0x141d24 ldr r3, [pc, r3]
 *   @0x141d28 mov r4, r2
 *   @0x141d2c ldrd r2, r3, [r3]
 *   @0x141d30 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d>
 *   @0x141d34 cmp r4, #1
 *   @0x141d38 beq 0x141d64 <_Z24YYGML_action_if_variableRK6RValueS1_i+0x48>
 *   @0x141d3c cmp r4, #2
 *   @0x141d40 beq 0x141d6c <_Z24YYGML_action_if_variableRK6RValueS1_i+0x50>
 *   @0x141d44 cmp r4, #3
 *   @0x141d48 beq 0x141d7c <_Z24YYGML_action_if_variableRK6RValueS1_i+0x60>
 *   @0x141d4c cmp r4, #4
 *   @0x141d50 beq 0x141d60 <_Z24YYGML_action_if_variableRK6RValueS1_i+0x44>
 *   @0x141d54 rsbs r0, r0, #1
 *   @0x141d58 movlo r0, #0
 *   @0x141d5c pop {r4, pc}
 *   @0x141d60 mvn r0, r0
 *   @0x141d64 lsr r0, r0, #31
 *   @0x141d68 pop {r4, pc}
 *   @0x141d6c cmp r0, #0
 *   @0x141d70 movle r0, #0
 *   @0x141d74 movgt r0, #1
 *   @0x141d78 pop {r4, pc}
 *   @0x141d7c cmp r0, #0
 *   @0x141d80 movgt r0, #0
 *   @0x141d84 movle r0, #1
 *   @0x141d88 pop {r4, pc}
 *   @0x141d8c .word 0x002abff4
 *
 * ══ §194/251 F_PhysicsJointGetValue(RValue&, CInstance*, CInstance*, int, RValue*)  0x14bbd4  size 116  29 条（0x14bbd4..0x14bc48）
 * @func 0x14bbd4 0x14bc48  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / CPhysicsJointFactory::FindJoint(unsigned int) / CPhysicsJoint::GetValue(int)
 * 字段偏移 top8: 0xc×2 / 0x10×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14bbd4 push {r4, r5, r6, lr}
 *   @0x14bbd8 mov r1, #0
 *   @0x14bbdc ldr r5, [sp, #0x10]
 *   @0x14bbe0 mov r4, r0
 *   @0x14bbe4 str r1, [r0, #0xc]
 *   @0x14bbe8 mov r0, r5
 *   @0x14bbec bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14bbf0 bl 0x23b374 <_ZN20CPhysicsJointFactory9FindJointEj>
 *   @0x14bbf4 subs r6, r0, #0
 *   @0x14bbf8 beq 0x14bc30 <_Z22F_PhysicsJointGetValueR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x14bbfc mov r1, #1
 *   @0x14bc00 mov r0, r5
 *   @0x14bc04 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14bc08 mov r1, r0
 *   @0x14bc0c mov r0, r6
 *   @0x14bc10 bl 0x23b610 <_ZN13CPhysicsJoint8GetValueEi>
 *   @0x14bc14 vmov s15, r0
 *   @0x14bc18 vcvt.f64.f32 d7, s15
 *   @0x14bc1c vmov r0, r1, d7
 *   @0x14bc20 vmov r2, s14
 *   @0x14bc24 mov r3, r1
 *   @0x14bc28 stm r4, {r2, r3}
 *   @0x14bc2c pop {r4, r5, r6, pc}
 *   @0x14bc30 ldr r0, [pc, #0xc]
 *   @0x14bc34 mov r1, r6
 *   @0x14bc38 pop {r4, r5, r6, lr}
 *   @0x14bc3c add r0, pc, r0
 *   @0x14bc40 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14bc44 mulseq pc, r0, r1
 *
 * ══ §195/251 F_PhysicsSetParticleFlags(RValue&, CInstance*, CInstance*, int, RValue*)  0x14d654  size 116  29 条（0x14d654..0x14d6c8）
 * @func 0x14d654 0x14d6dc  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetUint32(RValue const*, int)
 * 字段偏移 top8: 0x10×2 / 0x64×1 / 0xb4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14d654 ldr r3, [pc, #0x64]
 *   @0x14d658 push {r4, r5, r6, lr}
 *   @0x14d65c ldr r3, [pc, r3]
 *   @0x14d660 ldr r4, [sp, #0x10]
 *   @0x14d664 ldr r3, [r3]
 *   @0x14d668 cmp r3, #0
 *   @0x14d66c beq 0x14d6ac <_Z25F_PhysicsSetParticleFlagsR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x14d670 ldr r5, [r3, #0xb4]
 *   @0x14d674 cmp r5, #0
 *   @0x14d678 beq 0x14d6ac <_Z25F_PhysicsSetParticleFlagsR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x14d67c mov r0, r4
 *   @0x14d680 mov r1, #0
 *   @0x14d684 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14d688 mov r1, #1
 *   @0x14d68c mov r6, r0
 *   @0x14d690 mov r0, r4
 *   @0x14d694 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x14d698 mov r1, r6
 *   @0x14d69c mov r2, r0
 *   @0x14d6a0 mov r0, r5
 *   @0x14d6a4 pop {r4, r5, r6, lr}
 *   @0x14d6a8 b 0x23a160 <_ZN13CPhysicsWorld16SetParticleFlagsEij>
 *   @0x14d6ac ldr r0, [pc, #0x10]
 *   @0x14d6b0 mov r1, #0
 *   @0x14d6b4 pop {r4, r5, r6, lr}
 *   @0x14d6b8 add r0, pc, r0
 *   @0x14d6bc b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14d6c0 eoreq r0, r10, r12, asr #5
 *   @0x14d6c4 andseq r6, pc, r0, lsl #22
 *
 * ══ §196/251 F_PhysicsSetParticleCategoryFlags(RValue&, CInstance*, CInstance*, int, RValue*)  0x14d6c8  size 116  29 条（0x14d6c8..0x14d73c）
 * @func 0x14d6c8 0x14d750  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetUint32(RValue const*, int)
 * 字段偏移 top8: 0x10×2 / 0x64×1 / 0xb4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14d6c8 ldr r3, [pc, #0x64]
 *   @0x14d6cc push {r4, r5, r6, lr}
 *   @0x14d6d0 ldr r3, [pc, r3]
 *   @0x14d6d4 ldr r4, [sp, #0x10]
 *   @0x14d6d8 ldr r3, [r3]
 *   @0x14d6dc cmp r3, #0
 *   @0x14d6e0 beq 0x14d720 <_Z33F_PhysicsSetParticleCategoryFlagsR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x14d6e4 ldr r5, [r3, #0xb4]
 *   @0x14d6e8 cmp r5, #0
 *   @0x14d6ec beq 0x14d720 <_Z33F_PhysicsSetParticleCategoryFlagsR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x14d6f0 mov r0, r4
 *   @0x14d6f4 mov r1, #0
 *   @0x14d6f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14d6fc mov r1, #1
 *   @0x14d700 mov r6, r0
 *   @0x14d704 mov r0, r4
 *   @0x14d708 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x14d70c mov r1, r6
 *   @0x14d710 mov r2, r0
 *   @0x14d714 mov r0, r5
 *   @0x14d718 pop {r4, r5, r6, lr}
 *   @0x14d71c b 0x23a194 <_ZN13CPhysicsWorld24SetParticleCategoryFlagsEij>
 *   @0x14d720 ldr r0, [pc, #0x10]
 *   @0x14d724 mov r1, #0
 *   @0x14d728 pop {r4, r5, r6, lr}
 *   @0x14d72c add r0, pc, r0
 *   @0x14d730 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14d734 eoreq r0, r10, r8, asr r2
 *   @0x14d738 andseq r6, pc, r12, lsl #21
 *
 * ══ §197/251 F_PhysicsSetParticleGroupFlags(RValue&, CInstance*, CInstance*, int, RValue*)  0x14d73c  size 116  29 条（0x14d73c..0x14d7b0）
 * @func 0x14d73c 0x14d7b0  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetUint32(RValue const*, int)
 * 字段偏移 top8: 0x10×2 / 0x64×1 / 0xb4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14d73c ldr r3, [pc, #0x64]
 *   @0x14d740 push {r4, r5, r6, lr}
 *   @0x14d744 ldr r3, [pc, r3]
 *   @0x14d748 ldr r4, [sp, #0x10]
 *   @0x14d74c ldr r3, [r3]
 *   @0x14d750 cmp r3, #0
 *   @0x14d754 beq 0x14d794 <_Z30F_PhysicsSetParticleGroupFlagsR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x14d758 ldr r5, [r3, #0xb4]
 *   @0x14d75c cmp r5, #0
 *   @0x14d760 beq 0x14d794 <_Z30F_PhysicsSetParticleGroupFlagsR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x14d764 mov r0, r4
 *   @0x14d768 mov r1, #0
 *   @0x14d76c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14d770 mov r1, #1
 *   @0x14d774 mov r6, r0
 *   @0x14d778 mov r0, r4
 *   @0x14d77c bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x14d780 mov r1, r6
 *   @0x14d784 mov r2, r0
 *   @0x14d788 mov r0, r5
 *   @0x14d78c pop {r4, r5, r6, lr}
 *   @0x14d790 b 0x23a210 <_ZN13CPhysicsWorld21SetParticleGroupFlagsEij>
 *   @0x14d794 ldr r0, [pc, #0x10]
 *   @0x14d798 mov r1, #0
 *   @0x14d79c pop {r4, r5, r6, lr}
 *   @0x14d7a0 add r0, pc, r0
 *   @0x14d7a4 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14d7a8 eoreq r0, r10, r4, ror #3
 *   @0x14d7ac andseq r6, pc, r8, lsl r10
 *
 * ══ §198/251 F_PhysicsParticleGroupSetBox(RValue&, CInstance*, CInstance*, int, RValue*)  0x14d9f8  size 116  29 条（0x14d9f8..0x14da6c）
 * @func 0x14d9f8 0x14da6c  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2
 * 字段偏移 top8: 0x10×2 / 0x64×1 / 0xb4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14d9f8 ldr r3, [pc, #0x64]
 *   @0x14d9fc push {r4, r5, r6, lr}
 *   @0x14da00 ldr r3, [pc, r3]
 *   @0x14da04 ldr r4, [sp, #0x10]
 *   @0x14da08 ldr r3, [r3]
 *   @0x14da0c cmp r3, #0
 *   @0x14da10 beq 0x14da50 <_Z28F_PhysicsParticleGroupSetBoxR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x14da14 ldr r5, [r3, #0xb4]
 *   @0x14da18 cmp r5, #0
 *   @0x14da1c beq 0x14da50 <_Z28F_PhysicsParticleGroupSetBoxR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x14da20 mov r0, r4
 *   @0x14da24 mov r1, #0
 *   @0x14da28 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14da2c mov r1, #1
 *   @0x14da30 mov r6, r0
 *   @0x14da34 mov r0, r4
 *   @0x14da38 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14da3c mov r1, r6
 *   @0x14da40 mov r2, r0
 *   @0x14da44 mov r0, r5
 *   @0x14da48 pop {r4, r5, r6, lr}
 *   @0x14da4c b 0x239ae4 <_ZN13CPhysicsWorld16ParticleGroupBoxEff>
 *   @0x14da50 ldr r0, [pc, #0x10]
 *   @0x14da54 mov r1, #0
 *   @0x14da58 pop {r4, r5, r6, lr}
 *   @0x14da5c add r0, pc, r0
 *   @0x14da60 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14da64 eoreq pc, r9, r8, lsr #30
 *   @0x14da68 andseq r6, pc, r12, ror r8
 *
 * ══ §199/251 F_PhysicsParticleGroupAddPoint(RValue&, CInstance*, CInstance*, int, RValue*)  0x14daa8  size 116  29 条（0x14daa8..0x14db1c）
 * @func 0x14daa8 0x14db30  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2
 * 字段偏移 top8: 0x10×2 / 0x64×1 / 0xb4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14daa8 ldr r3, [pc, #0x64]
 *   @0x14daac push {r4, r5, r6, lr}
 *   @0x14dab0 ldr r3, [pc, r3]
 *   @0x14dab4 ldr r4, [sp, #0x10]
 *   @0x14dab8 ldr r3, [r3]
 *   @0x14dabc cmp r3, #0
 *   @0x14dac0 beq 0x14db00 <_Z30F_PhysicsParticleGroupAddPointR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x14dac4 ldr r5, [r3, #0xb4]
 *   @0x14dac8 cmp r5, #0
 *   @0x14dacc beq 0x14db00 <_Z30F_PhysicsParticleGroupAddPointR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x14dad0 mov r0, r4
 *   @0x14dad4 mov r1, #0
 *   @0x14dad8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14dadc mov r1, #1
 *   @0x14dae0 mov r6, r0
 *   @0x14dae4 mov r0, r4
 *   @0x14dae8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14daec mov r1, r6
 *   @0x14daf0 mov r2, r0
 *   @0x14daf4 mov r0, r5
 *   @0x14daf8 pop {r4, r5, r6, lr}
 *   @0x14dafc b 0x239c08 <_ZN13CPhysicsWorld21ParticleGroupAddPointEff>
 *   @0x14db00 ldr r0, [pc, #0x10]
 *   @0x14db04 mov r1, #0
 *   @0x14db08 pop {r4, r5, r6, lr}
 *   @0x14db0c add r0, pc, r0
 *   @0x14db10 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14db14 eoreq pc, r9, r8, ror lr
 *   @0x14db18 andseq r6, pc, r8, lsl #17
 *
 * ══ §200/251 F_PhysicsJoinParticleGroups(RValue&, CInstance*, CInstance*, int, RValue*)  0x14db98  size 116  29 条（0x14db98..0x14dc0c）
 * @func 0x14db98 0x14dc0c  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0x10×2 / 0x64×1 / 0xb4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14db98 ldr r3, [pc, #0x64]
 *   @0x14db9c push {r4, r5, r6, lr}
 *   @0x14dba0 ldr r3, [pc, r3]
 *   @0x14dba4 ldr r4, [sp, #0x10]
 *   @0x14dba8 ldr r3, [r3]
 *   @0x14dbac cmp r3, #0
 *   @0x14dbb0 beq 0x14dbf0 <_Z27F_PhysicsJoinParticleGroupsR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x14dbb4 ldr r5, [r3, #0xb4]
 *   @0x14dbb8 cmp r5, #0
 *   @0x14dbbc beq 0x14dbf0 <_Z27F_PhysicsJoinParticleGroupsR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x14dbc0 mov r0, r4
 *   @0x14dbc4 mov r1, #0
 *   @0x14dbc8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14dbcc mov r1, #1
 *   @0x14dbd0 mov r6, r0
 *   @0x14dbd4 mov r0, r4
 *   @0x14dbd8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14dbdc mov r1, r6
 *   @0x14dbe0 mov r2, r0
 *   @0x14dbe4 mov r0, r5
 *   @0x14dbe8 pop {r4, r5, r6, lr}
 *   @0x14dbec b 0x239de8 <_ZN13CPhysicsWorld18JoinParticleGroupsEii>
 *   @0x14dbf0 ldr r0, [pc, #0x10]
 *   @0x14dbf4 mov r1, #0
 *   @0x14dbf8 pop {r4, r5, r6, lr}
 *   @0x14dbfc add r0, pc, r0
 *   @0x14dc00 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14dc04 eoreq pc, r9, r8, lsl #27
 *   @0x14dc08 andseq r6, pc, r8, asr r8
 *
 * ══ §201/251 F_PhysicsParticleCount(RValue&, CInstance*, CInstance*, int, RValue*)  0x14de60  size 116  29 条（0x14de60..0x14ded4）
 * @func 0x14de60 0x14ded4  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x64×1 / 0x4×1 / 0xb4×1 / 0x10×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14de60 ldr r3, [pc, #0x64]
 *   @0x14de64 mov r1, #0
 *   @0x14de68 str r1, [r0]
 *   @0x14de6c mov r2, r1
 *   @0x14de70 ldr r3, [pc, r3]
 *   @0x14de74 movt r2, #0xbff0
 *   @0x14de78 str r1, [r0, #0xc]
 *   @0x14de7c ldr r3, [r3]
 *   @0x14de80 str r2, [r0, #0x4]
 *   @0x14de84 cmp r3, r1
 *   @0x14de88 beq 0x14debc <_Z22F_PhysicsParticleCountR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x14de8c ldr r3, [r3, #0xb4]
 *   @0x14de90 cmp r3, r1
 *   @0x14de94 beq 0x14debc <_Z22F_PhysicsParticleCountR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x14de98 ldr r2, [r3, #0x10]
 *   @0x14de9c movw r3, #0x9298
 *   @0x14dea0 movt r3, #0x1
 *   @0x14dea4 ldr r2, [r2, r3]
 *   @0x14dea8 vmov s15, r2
 *   @0x14deac vcvt.f64.s32 d7, s15
 *   @0x14deb0 vmov r2, r3, d7
 *   @0x14deb4 stm r0, {r2, r3}
 *   @0x14deb8 bx lr
 *   @0x14debc ldr r0, [pc, #0xc]
 *   @0x14dec0 mov r1, #0
 *   @0x14dec4 add r0, pc, r0
 *   @0x14dec8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14decc .word 0x0029fab8
 *   @0x14ded0 andseq r6, pc, r4, asr #12
 *
 * ══ §202/251 GraphicsPerf::DisplayFPS(float)  0x17c428  size 116  29 条（0x17c428..0x17c49c）
 * @func 0x17c428 0x17c49c  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GraphicsPerf::BuildPerfDisplay() / GraphicsPerf::oprintf(float, float, unsigned int, unsigned int, char const*, ...)
 * 字段偏移 top8: 0x-4×1 / 0x48×1 / 0x44×1 / 0x3c×1 / 0x8×1 / 0xc×1 / 0x4×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17c428 str lr, [sp, #-0x4]!
 *   @0x17c42c vpush {d8}
 *   @0x17c430 vmov s16, r0
 *   @0x17c434 sub sp, sp, #20
 *   @0x17c438 bl 0x17bbfc <_ZN12GraphicsPerf16BuildPerfDisplayEv>
 *   @0x17c43c vcvt.s32.f32 s16, s16
 *   @0x17c440 ldr r12, [pc, #0x48]
 *   @0x17c444 mov r0, #0
 *   @0x17c448 ldr lr, [pc, #0x44]
 *   @0x17c44c mov r2, #-16777216
 *   @0x17c450 ldr r12, [pc, r12]
 *   @0x17c454 ldr r1, [pc, #0x3c]
 *   @0x17c458 add lr, pc, lr
 *   @0x17c45c str lr, [sp]
 *   @0x17c460 ldr r1, [pc, r1]
 *   @0x17c464 mvn r3, #0
 *   @0x17c468 vstr s16, [sp, #4]
 *   @0x17c46c ldr r12, [r12]
 *   @0x17c470 str r12, [sp, #0x8]
 *   @0x17c474 ldr r1, [r1]
 *   @0x17c478 str r1, [sp, #0xc]
 *   @0x17c47c mov r1, r0
 *   @0x17c480 bl 0x17c2f8 <_ZN12GraphicsPerf7oprintfEffjjPKcz>
 *   @0x17c484 add sp, sp, #20
 *   @0x17c488 vpop {d8}
 *   @0x17c48c ldr pc, [sp], #4
 *   @0x17c490 eoreq r3, r7, r0, asr #30
 *   @0x17c494 andseq pc, r12, r8, lsr #3
 *   @0x17c498 eoreq r3, r7, r4, lsr pc
 *
 * ══ §203/251 GMGamePad::Update(float*, float*)  0x18ee74  size 116  29 条（0x18ee74..0x18eee8）
 * @func 0x18ee74 0x18eee8  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65bc×3 / GMGamePad::Update(float*, float*)+0x40
 * 字段偏移 top8: 0x4×2 / 0x10×2 / 0x8×2 / 0x14×2 / 0xc×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18ee74 ldr r3, [r0, #0x4]
 *   @0x18ee78 push {r4, r5, r6, lr}
 *   @0x18ee7c mov r4, r0
 *   @0x18ee80 mov r5, r1
 *   @0x18ee84 mov r6, r2
 *   @0x18ee88 ldr r0, [r0, #0xc]
 *   @0x18ee8c lsl r2, r3, #2
 *   @0x18ee90 ldr r1, [r4, #0x10]
 *   @0x18ee94 bl 0xb65bc <memcpy@plt>
 *   @0x18ee98 ldr r2, [r4, #0x8]
 *   @0x18ee9c cmp r2, #0
 *   @0x18eea0 ble 0x18eeb4 <_ZN9GMGamePad6UpdateEPfS0_+0x40>
 *   @0x18eea4 lsl r2, r2, #2
 *   @0x18eea8 ldr r0, [r4, #0x18]
 *   @0x18eeac ldr r1, [r4, #0x14]
 *   @0x18eeb0 bl 0xb65bc <memcpy@plt>
 *   @0x18eeb4 ldr r2, [r4, #0x4]
 *   @0x18eeb8 mov r1, r5
 *   @0x18eebc ldr r0, [r4, #0x10]
 *   @0x18eec0 lsl r2, r2, #2
 *   @0x18eec4 bl 0xb65bc <memcpy@plt>
 *   @0x18eec8 ldr r2, [r4, #0x8]
 *   @0x18eecc cmp r2, #0
 *   @0x18eed0 pople {r4, r5, r6, pc}
 *   @0x18eed4 ldr r0, [r4, #0x14]
 *   @0x18eed8 mov r1, r6
 *   @0x18eedc lsl r2, r2, #2
 *   @0x18eee0 pop {r4, r5, r6, lr}
 *   @0x18eee4 b 0xb65bc <memcpy@plt>
 *
 * ══ §204/251 LoadSave::_FileExists(char*)  0x18f6c0  size 116  29 条（0x18f6c0..0x18f734）
 * @func 0x18f6c0 0x18f734  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: zip_fopen / zip_fclose
 * 字段偏移 top8: 0x58×1 / 0x34×1 / 0x30×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18f6c0 push {r3, r4, r5, lr}
 *   @0x18f6c4 mov r1, r0
 *   @0x18f6c8 ldr r3, [pc, #0x58]
 *   @0x18f6cc mov r5, r0
 *   @0x18f6d0 mov r2, #1
 *   @0x18f6d4 ldr r3, [pc, r3]
 *   @0x18f6d8 ldr r0, [r3]
 *   @0x18f6dc blx 0x2a44b8 <zip_fopen>
 *   @0x18f6e0 adds r4, r0, #0
 *   @0x18f6e4 movne r4, #1
 *   @0x18f6e8 cmp r4, #0
 *   @0x18f6ec bne 0x18f71c <_ZN8LoadSave11_FileExistsEPc+0x5c>
 *   @0x18f6f0 ldr r3, [pc, #0x34]
 *   @0x18f6f4 mov r2, r5
 *   @0x18f6f8 ldr r1, [pc, #0x30]
 *   @0x18f6fc ldr r3, [pc, r3]
 *   @0x18f700 add r1, pc, r1
 *   @0x18f704 ldr r0, [r3]
 *   @0x18f708 ldr r3, [r0]
 *   @0x18f70c ldr r3, [r3, #0xc]
 *   @0x18f710 blx r3
 *   @0x18f714 mov r0, r4
 *   @0x18f718 pop {r3, r4, r5, pc}
 *   @0x18f71c blx 0x2a4388 <zip_fclose>
 *   @0x18f720 mov r0, r4
 *   @0x18f724 pop {r3, r4, r5, pc}
 *   @0x18f728 eoreq r0, r6, r0, asr #16
 *   @0x18f72c eoreq lr, r5, r8, lsl r0
 *   @0x18f730 andseq r12, r11, r8, asr #27
 *
 * ══ §205/251 Motion_Grid_ClearCell(int, int, int)  0x19a26c  size 116  29 条（0x19a26c..0x19a2e0）
 * @func 0x19a26c 0x19a2e0  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x5c×1 / 0x4c×1 / 0x2×1 / 0x14×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19a26c cmp r0, #0
 *   @0x19a270 bxlt lr
 *   @0x19a274 ldr r3, [pc, #0x5c]
 *   @0x19a278 ldr r3, [pc, r3]
 *   @0x19a27c ldr r3, [r3]
 *   @0x19a280 cmp r0, r3
 *   @0x19a284 bxge lr
 *   @0x19a288 ldr r3, [pc, #0x4c]
 *   @0x19a28c ldr r3, [pc, r3]
 *   @0x19a290 ldr r3, [r3]
 *   @0x19a294 ldr r3, [r3, r0, lsl #2]
 *   @0x19a298 cmp r3, #0
 *   @0x19a29c bxeq lr
 *   @0x19a2a0 cmp r1, #0
 *   @0x19a2a4 bxlt lr
 *   @0x19a2a8 ldr r0, [r3, #0x14]
 *   @0x19a2ac cmp r1, r0
 *   @0x19a2b0 bxge lr
 *   @0x19a2b4 cmp r2, #0
 *   @0x19a2b8 bxlt lr
 *   @0x19a2bc ldr r0, [r3, #0x18]
 *   @0x19a2c0 cmp r2, r0
 *   @0x19a2c4 mlalt r1, r0, r1, r2
 *   @0x19a2c8 ldrlt r3, [r3, #0x1c]
 *   @0x19a2cc movlt r2, #0
 *   @0x19a2d0 strlt r2, [r3, r1, lsl #2]
 *   @0x19a2d4 bx lr
 *   @0x19a2d8 eoreq r6, r5, r4, lsr r4
 *   @0x19a2dc eoreq r6, r5, r4, lsr #8
 *
 * ══ §206/251 Motion_Grid_AddCell(int, int, int)  0x19a404  size 116  29 条（0x19a404..0x19a478）
 * @func 0x19a404 0x19a48c  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x5c×1 / 0x4c×1 / 0x2×1 / 0x14×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19a404 cmp r0, #0
 *   @0x19a408 bxlt lr
 *   @0x19a40c ldr r3, [pc, #0x5c]
 *   @0x19a410 ldr r3, [pc, r3]
 *   @0x19a414 ldr r3, [r3]
 *   @0x19a418 cmp r0, r3
 *   @0x19a41c bxge lr
 *   @0x19a420 ldr r3, [pc, #0x4c]
 *   @0x19a424 ldr r3, [pc, r3]
 *   @0x19a428 ldr r3, [r3]
 *   @0x19a42c ldr r3, [r3, r0, lsl #2]
 *   @0x19a430 cmp r3, #0
 *   @0x19a434 bxeq lr
 *   @0x19a438 cmp r1, #0
 *   @0x19a43c bxlt lr
 *   @0x19a440 ldr r0, [r3, #0x14]
 *   @0x19a444 cmp r1, r0
 *   @0x19a448 bxge lr
 *   @0x19a44c cmp r2, #0
 *   @0x19a450 bxlt lr
 *   @0x19a454 ldr r0, [r3, #0x18]
 *   @0x19a458 cmp r2, r0
 *   @0x19a45c mlalt r1, r0, r1, r2
 *   @0x19a460 ldrlt r3, [r3, #0x1c]
 *   @0x19a464 mvnlt r2, #0
 *   @0x19a468 strlt r2, [r3, r1, lsl #2]
 *   @0x19a46c bx lr
 *   @0x19a470 mlaeq r5, r12, r2, r6
 *   @0x19a474 eoreq r6, r5, r12, lsl #5
 *
 * ══ §207/251 CObjectGM::SetName(char*)  0x19d2d4  size 116  29 条（0x19d2d4..0x19d348）
 * @func 0x19d2d4 0x19d348  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*) / 0xb6538 / MemoryManager::Alloc(unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x14×3 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19d2d4 push {r4, r5, r6, lr}
 *   @0x19d2d8 mov r5, r0
 *   @0x19d2dc ldr r0, [r0, #0x14]
 *   @0x19d2e0 mov r4, r1
 *   @0x19d2e4 cmp r0, #0
 *   @0x19d2e8 beq 0x19d2f8 <_ZN9CObjectGM7SetNameEPc+0x24>
 *   @0x19d2ec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x19d2f0 mov r3, #0
 *   @0x19d2f4 str r3, [r5, #0x14]
 *   @0x19d2f8 cmp r4, #0
 *   @0x19d2fc popeq {r4, r5, r6, pc}
 *   @0x19d300 ldrb r3, [r4]
 *   @0x19d304 cmp r3, #0
 *   @0x19d308 popeq {r4, r5, r6, pc}
 *   @0x19d30c mov r0, r4
 *   @0x19d310 bl 0xb6538 <strlen@plt>
 *   @0x19d314 mov r3, #1
 *   @0x19d318 ldr r1, [pc, #0x24]
 *   @0x19d31c mov r2, #248
 *   @0x19d320 add r1, pc, r1
 *   @0x19d324 add r6, r0, r3
 *   @0x19d328 mov r0, r6
 *   @0x19d32c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x19d330 mov r2, r6
 *   @0x19d334 mov r1, r4
 *   @0x19d338 str r0, [r5, #0x14]
 *   @0x19d33c pop {r4, r5, r6, lr}
 *   @0x19d340 b 0xb65bc <memcpy@plt>
 *   @0x19d344 andseq pc, r10, r0, asr #21
 *
 * ══ §208/251 CPath::AddInternalPoint(float, float, float)  0x1a6068  size 116  29 条（0x1a6068..0x1a60dc）
 * @func 0x1a6068 0x1a60f0  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPath::AddInternalPoint(float, float, float)+0x54 / MemoryManager::SetLength(void**, unsigned int, char const*, int)
 * 字段偏移 top8: 0x20×3 / 0x8×3 / 0x38×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a6068 ldr r12, [r0, #0x20]
 *   @0x1a606c push {r3, r4, r5, r6, r7, lr}
 *   @0x1a6070 mov r6, r2
 *   @0x1a6074 ldr r2, [r0, #0x8]
 *   @0x1a6078 mov r4, r0
 *   @0x1a607c add r0, r12, #1
 *   @0x1a6080 mov r7, r1
 *   @0x1a6084 cmp r0, r2
 *   @0x1a6088 mov r5, r3
 *   @0x1a608c str r0, [r4, #0x20]
 *   @0x1a6090 ble 0x1a60bc <_ZN5CPath16AddInternalPointEfff+0x54>
 *   @0x1a6094 add r1, r12, #11
 *   @0x1a6098 ldr r2, [pc, #0x38]
 *   @0x1a609c add r0, r4, #12
 *   @0x1a60a0 mov r3, #158
 *   @0x1a60a4 add r2, pc, r2
 *   @0x1a60a8 lsl r1, r1, #4
 *   @0x1a60ac bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1a60b0 ldr r0, [r4, #0x20]
 *   @0x1a60b4 add r3, r0, #10
 *   @0x1a60b8 str r3, [r4, #0x8]
 *   @0x1a60bc ldr r3, [r4, #0xc]
 *   @0x1a60c0 sub r0, r0, #-268435455
 *   @0x1a60c4 add r0, r3, r0, lsl #4
 *   @0x1a60c8 str r7, [r0]
 *   @0x1a60cc str r6, [r0, #0x4]
 *   @0x1a60d0 str r5, [r0, #0x8]
 *   @0x1a60d4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1a60d8 andseq r7, r10, r4, lsr r0
 *
 * ══ §209/251 TBitmap::LoadFromStream(CStream*)  0x1a900c  size 116  29 条（0x1a900c..0x1a9080）
 * @func 0x1a900c 0x1a9080  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::GetSize() / CStream::GetPosition() / CStream::ReadBuffer(void*, int) / TBitmap::ReadDIB(CStream*, int)
 * 字段偏移 top8: 0x30×1 / 0x6×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a900c ldr r3, [r0]
 *   @0x1a9010 push {r4, r5, r6, lr}
 *   @0x1a9014 mov r4, r1
 *   @0x1a9018 sub sp, sp, #8
 *   @0x1a901c ldr r3, [r3, #0x30]
 *   @0x1a9020 mov r5, r0
 *   @0x1a9024 blx r3
 *   @0x1a9028 mov r0, r4
 *   @0x1a902c bl 0x201168 <_ZN7CStream7GetSizeEv>
 *   @0x1a9030 mov r6, r0
 *   @0x1a9034 mov r0, r4
 *   @0x1a9038 bl 0x201160 <_ZN7CStream11GetPositionEv>
 *   @0x1a903c cmp r6, r0
 *   @0x1a9040 beq 0x1a9064 <_ZN7TBitmap14LoadFromStreamEP7CStream+0x58>
 *   @0x1a9044 mov r2, #2
 *   @0x1a9048 mov r0, r4
 *   @0x1a904c add r1, sp, #6
 *   @0x1a9050 bl 0x2011e4 <_ZN7CStream10ReadBufferEPvi>
 *   @0x1a9054 ldrh r2, [sp, #6]
 *   @0x1a9058 movw r3, #0x4d42
 *   @0x1a905c cmp r2, r3
 *   @0x1a9060 beq 0x1a906c <_ZN7TBitmap14LoadFromStreamEP7CStream+0x60>
 *   @0x1a9064 add sp, sp, #8
 *   @0x1a9068 pop {r4, r5, r6, pc}
 *   @0x1a906c mov r0, r5
 *   @0x1a9070 mov r1, r4
 *   @0x1a9074 mov r2, #0
 *   @0x1a9078 bl 0x1a8de4 <_ZN7TBitmap7ReadDIBEP7CStreami>
 *   @0x1a907c b 0x1a9064 <_ZN7TBitmap14LoadFromStreamEP7CStream+0x58>
 *
 * ══ §210/251 F_TilemapTileGetFlip(RValue&, CInstance*, CInstance*, int, RValue*)  0x1b66b8  size 116  29 条（0x1b66b8..0x1b672c）
 * @func 0x1b66b8 0x1b6740  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x4×3 / 0xc×1 / 0x10×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b66b8 cmp r3, #1
 *   @0x1b66bc push {r3, r4, r5, lr}
 *   @0x1b66c0 mov r3, #0
 *   @0x1b66c4 mov r5, r3
 *   @0x1b66c8 mov r4, r0
 *   @0x1b66cc movt r3, #0xbff0
 *   @0x1b66d0 str r5, [r0, #0xc]
 *   @0x1b66d4 str r3, [r0, #0x4]
 *   @0x1b66d8 str r5, [r0]
 *   @0x1b66dc ldr r0, [sp, #0x10]
 *   @0x1b66e0 beq 0x1b66f8 <_Z20F_TilemapTileGetFlipR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1b66e4 ldr r0, [pc, #0x3c]
 *   @0x1b66e8 mov r1, r5
 *   @0x1b66ec pop {r3, r4, r5, lr}
 *   @0x1b66f0 add r0, pc, r0
 *   @0x1b66f4 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1b66f8 str r5, [r4]
 *   @0x1b66fc mov r1, r5
 *   @0x1b6700 str r5, [r4, #0x4]
 *   @0x1b6704 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1b6708 ands r0, r0, #536870912
 *   @0x1b670c moveq r5, r0
 *   @0x1b6710 movne r3, #0
 *   @0x1b6714 moveq r3, r5
 *   @0x1b6718 movtne r3, #0x3ff0
 *   @0x1b671c str r5, [r4]
 *   @0x1b6720 str r3, [r4, #0x4]
 *   @0x1b6724 pop {r3, r4, r5, pc}
 *   @0x1b6728 andseq r6, r9, r12, lsl #28
 *
 * ══ §211/251 F_TilemapTileGetMirror(RValue&, CInstance*, CInstance*, int, RValue*)  0x1b672c  size 116  29 条（0x1b672c..0x1b67a0）
 * @func 0x1b672c 0x1b67b4  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x4×3 / 0xc×1 / 0x10×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b672c cmp r3, #1
 *   @0x1b6730 push {r3, r4, r5, lr}
 *   @0x1b6734 mov r3, #0
 *   @0x1b6738 mov r5, r3
 *   @0x1b673c mov r4, r0
 *   @0x1b6740 movt r3, #0xbff0
 *   @0x1b6744 str r5, [r0, #0xc]
 *   @0x1b6748 str r3, [r0, #0x4]
 *   @0x1b674c str r5, [r0]
 *   @0x1b6750 ldr r0, [sp, #0x10]
 *   @0x1b6754 beq 0x1b676c <_Z22F_TilemapTileGetMirrorR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1b6758 ldr r0, [pc, #0x3c]
 *   @0x1b675c mov r1, r5
 *   @0x1b6760 pop {r3, r4, r5, lr}
 *   @0x1b6764 add r0, pc, r0
 *   @0x1b6768 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1b676c str r5, [r4]
 *   @0x1b6770 mov r1, r5
 *   @0x1b6774 str r5, [r4, #0x4]
 *   @0x1b6778 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1b677c ands r0, r0, #268435456
 *   @0x1b6780 moveq r5, r0
 *   @0x1b6784 movne r3, #0
 *   @0x1b6788 moveq r3, r5
 *   @0x1b678c movtne r3, #0x3ff0
 *   @0x1b6790 str r5, [r4]
 *   @0x1b6794 str r3, [r4, #0x4]
 *   @0x1b6798 pop {r3, r4, r5, pc}
 *   @0x1b679c andseq r6, r9, r12, asr #27
 *
 * ══ §212/251 F_TilemapTileGetRotate(RValue&, CInstance*, CInstance*, int, RValue*)  0x1b67a0  size 116  29 条（0x1b67a0..0x1b6814）
 * @func 0x1b67a0 0x1b6814  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x4×3 / 0xc×1 / 0x10×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b67a0 cmp r3, #1
 *   @0x1b67a4 push {r3, r4, r5, lr}
 *   @0x1b67a8 mov r3, #0
 *   @0x1b67ac mov r5, r3
 *   @0x1b67b0 mov r4, r0
 *   @0x1b67b4 movt r3, #0xbff0
 *   @0x1b67b8 str r5, [r0, #0xc]
 *   @0x1b67bc str r3, [r0, #0x4]
 *   @0x1b67c0 str r5, [r0]
 *   @0x1b67c4 ldr r0, [sp, #0x10]
 *   @0x1b67c8 beq 0x1b67e0 <_Z22F_TilemapTileGetRotateR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1b67cc ldr r0, [pc, #0x3c]
 *   @0x1b67d0 mov r1, r5
 *   @0x1b67d4 pop {r3, r4, r5, lr}
 *   @0x1b67d8 add r0, pc, r0
 *   @0x1b67dc b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1b67e0 str r5, [r4]
 *   @0x1b67e4 mov r1, r5
 *   @0x1b67e8 str r5, [r4, #0x4]
 *   @0x1b67ec bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1b67f0 ands r0, r0, #1073741824
 *   @0x1b67f4 moveq r5, r0
 *   @0x1b67f8 movne r3, #0
 *   @0x1b67fc moveq r3, r5
 *   @0x1b6800 movtne r3, #0x3ff0
 *   @0x1b6804 str r5, [r4]
 *   @0x1b6808 str r3, [r4, #0x4]
 *   @0x1b680c pop {r3, r4, r5, pc}
 *   @0x1b6810 mulseq r9, r0, sp
 *
 * ══ §213/251 ElementsHaveLoop(LinkedList<CLayerElementBase>*)  0x1b6e4c  size 116  29 条（0x1b6e4c..0x1b6ec0）
 * @func 0x1b6e4c 0x1b6ec0  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b6e4c cmp r0, #0
 *   @0x1b6e50 bxeq lr
 *   @0x1b6e54 ldr r3, [r0]
 *   @0x1b6e58 cmp r3, #0
 *   @0x1b6e5c beq 0x1b6ea8 <_Z16ElementsHaveLoopP10LinkedListI17CLayerElementBaseE+0x5c>
 *   @0x1b6e60 ldr r0, [r3, #0x14]
 *   @0x1b6e64 cmp r0, #0
 *   @0x1b6e68 bxeq lr
 *   @0x1b6e6c cmp r3, r0
 *   @0x1b6e70 beq 0x1b6eb0 <_Z16ElementsHaveLoopP10LinkedListI17CLayerElementBaseE+0x64>
 *   @0x1b6e74 cmp r3, #0
 *   @0x1b6e78 ldrne r3, [r3, #0x14]
 *   @0x1b6e7c cmp r0, #0
 *   @0x1b6e80 bxeq lr
 *   @0x1b6e84 ldr r2, [r0, #0x14]
 *   @0x1b6e88 cmp r2, #0
 *   @0x1b6e8c beq 0x1b6eb8 <_Z16ElementsHaveLoopP10LinkedListI17CLayerElementBaseE+0x6c>
 *   @0x1b6e90 cmp r3, #0
 *   @0x1b6e94 ldr r0, [r2, #0x14]
 *   @0x1b6e98 beq 0x1b6ea8 <_Z16ElementsHaveLoopP10LinkedListI17CLayerElementBaseE+0x5c>
 *   @0x1b6e9c cmp r0, #0
 *   @0x1b6ea0 bne 0x1b6e6c <_Z16ElementsHaveLoopP10LinkedListI17CLayerElementBaseE+0x20>
 *   @0x1b6ea4 bx lr
 *   @0x1b6ea8 mov r0, r3
 *   @0x1b6eac bx lr
 *   @0x1b6eb0 mov r0, #1
 *   @0x1b6eb4 bx lr
 *   @0x1b6eb8 mov r0, r2
 *   @0x1b6ebc bx lr
 *
 * ══ §214/251 CalcDistInches(int, int)  0x1d6708  size 116  29 条（0x1d6708..0x1d677c）
 * @func 0x1d6708 0x1d677c  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ConvertXDPI(float) / ConvertYDPI(float) / 0xb6700
 * 字段偏移 top8: 0x4×3 / 0x-4×1
 * VFP 指令 18 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d6708 vmov s13, r0
 *   @0x1d670c str lr, [sp, #-0x4]!
 *   @0x1d6710 vpush {d8}
 *   @0x1d6714 vcvt.f32.s32 s13, s13
 *   @0x1d6718 sub sp, sp, #12
 *   @0x1d671c str r1, [sp, #0x4]
 *   @0x1d6720 vmov r0, s13
 *   @0x1d6724 bl 0x1d66c0 <_Z11ConvertXDPIf>
 *   @0x1d6728 ldr r1, [sp, #0x4]
 *   @0x1d672c vmov s15, r1
 *   @0x1d6730 vcvt.f32.s32 s15, s15
 *   @0x1d6734 vmov s16, r0
 *   @0x1d6738 vmov r0, s15
 *   @0x1d673c bl 0x1d66e4 <_Z11ConvertYDPIf>
 *   @0x1d6740 vmov s13, r0
 *   @0x1d6744 vmul.f32 s14, s13, s13
 *   @0x1d6748 vmla.f32 s14, s16, s16
 *   @0x1d674c vsqrt.f32 s15, s14
 *   @0x1d6750 vcmp.f32 s15, s15
 *   @0x1d6754 vmrs APSR_nzcv, fpscr
 *   @0x1d6758 bne 0x1d676c <_Z14CalcDistInchesii+0x64>
 *   @0x1d675c vmov r0, s15
 *   @0x1d6760 add sp, sp, #12
 *   @0x1d6764 vpop {d8}
 *   @0x1d6768 ldr pc, [sp], #4
 *   @0x1d676c vmov r0, s14
 *   @0x1d6770 bl 0xb6700 <sqrtf@plt>
 *   @0x1d6774 vmov s15, r0
 *   @0x1d6778 b 0x1d675c <_Z14CalcDistInchesii+0x54>
 *
 * ══ §215/251 Shader_Find(char const*)  0x1e12dc  size 116  29 条（0x1e12dc..0x1e1350）
 * @func 0x1e12dc 0x1e1350  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Shader_Find(char const*)+0x5c / 0xb6574
 * 字段偏移 top8: 0x4×2 / 0x5c×1 / 0x4c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e12dc push {r3, r4, r5, r6, r7, lr}
 *   @0x1e12e0 mov r7, r0
 *   @0x1e12e4 ldr r3, [pc, #0x5c]
 *   @0x1e12e8 ldr r3, [pc, r3]
 *   @0x1e12ec ldr r6, [r3]
 *   @0x1e12f0 cmp r6, #0
 *   @0x1e12f4 ble 0x1e1338 <_Z11Shader_FindPKc+0x5c>
 *   @0x1e12f8 ldr r3, [pc, #0x4c]
 *   @0x1e12fc mov r4, #0
 *   @0x1e1300 ldr r3, [pc, r3]
 *   @0x1e1304 ldr r5, [r3]
 *   @0x1e1308 sub r5, r5, #4
 *   @0x1e130c ldr r3, [r5, #0x4]!
 *   @0x1e1310 mov r1, r7
 *   @0x1e1314 cmp r3, #0
 *   @0x1e1318 beq 0x1e132c <_Z11Shader_FindPKc+0x50>
 *   @0x1e131c ldr r0, [r3, #0x4]
 *   @0x1e1320 bl 0xb6574 <strcmp@plt>
 *   @0x1e1324 cmp r0, #0
 *   @0x1e1328 beq 0x1e1340 <_Z11Shader_FindPKc+0x64>
 *   @0x1e132c add r4, r4, #1
 *   @0x1e1330 cmp r4, r6
 *   @0x1e1334 bne 0x1e130c <_Z11Shader_FindPKc+0x30>
 *   @0x1e1338 mvn r0, #0
 *   @0x1e133c pop {r3, r4, r5, r6, r7, pc}
 *   @0x1e1340 mov r0, r4
 *   @0x1e1344 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1e1348 eoreq pc, r0, r12, asr r10
 *   @0x1e134c eoreq pc, r0, r8, asr #20
 *
 * ══ §216/251 CSprite::FreeMask()  0x1e3b58  size 116  29 条（0x1e3b58..0x1e3bcc）
 * @func 0x1e3b58 0x1e3bcc  size 116  29 条
 * 级别: 骨架（静态语义/C译文已补；真实依赖与原版等价未验收）
 * 静态译文: c/csprite_resources/src/free_resources.c；has_mask==0 原样返回；count>0 才逐行 Free，外调后重读表/计数并清行两字，最后 Free 表并清 +0x40/+0x3c/+0x31。
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / CSprite::FreeMask()+0x5c / CSprite::FreeMask()+0x2c
 * 字段偏移 top8: 0x3c×3 / 0x40×3 / 0x31×2 / 0x4×2 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e3b58 push {r3, r4, r5, r6, r7, lr}
 *   @0x1e3b5c mov r6, r0
 *   @0x1e3b60 ldrb r3, [r0, #0x31]
 *   @0x1e3b64 cmp r3, #0
 *   @0x1e3b68 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1e3b6c ldr r3, [r0, #0x3c]
 *   @0x1e3b70 ldr r0, [r0, #0x40]
 *   @0x1e3b74 cmp r3, #0
 *   @0x1e3b78 movgt r4, #0
 *   @0x1e3b7c movgt r7, r4
 *   @0x1e3b80 ble 0x1e3bb4 <_ZN7CSprite8FreeMaskEv+0x5c>
 *   @0x1e3b84 lsl r5, r4, #3
 *   @0x1e3b88 add r3, r0, r5
 *   @0x1e3b8c ldr r0, [r3, #0x4]
 *   @0x1e3b90 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e3b94 ldr r0, [r6, #0x40]
 *   @0x1e3b98 ldr r2, [r6, #0x3c]
 *   @0x1e3b9c add r5, r0, r5
 *   @0x1e3ba0 str r7, [r5, #0x4]
 *   @0x1e3ba4 str r7, [r0, r4, lsl #3]
 *   @0x1e3ba8 add r4, r4, #1
 *   @0x1e3bac cmp r4, r2
 *   @0x1e3bb0 blt 0x1e3b84 <_ZN7CSprite8FreeMaskEv+0x2c>
 *   @0x1e3bb4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e3bb8 mov r3, #0
 *   @0x1e3bbc str r3, [r6, #0x40]
 *   @0x1e3bc0 str r3, [r6, #0x3c]
 *   @0x1e3bc4 strb r3, [r6, #0x31]
 *   @0x1e3bc8 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §217/251 CVariableList::Alloc(RVariable const*)  0x1f7890  size 116  29 条（0x1f7890..0x1f7904）
 * @func 0x1f7890 0x1f7904  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RVariable::RVariable(RVariable const*)×2 / RVariable::Assign(RVariable const&) / operator new(unsigned int)
 * 字段偏移 top8: 0x28×2 / 0x68×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f7890 ldr r3, [pc, #0x68]
 *   @0x1f7894 push {r4, r5, r6, lr}
 *   @0x1f7898 ldr r3, [pc, r3]
 *   @0x1f789c sub sp, sp, #48
 *   @0x1f78a0 mov r5, r0
 *   @0x1f78a4 ldr r4, [r3]
 *   @0x1f78a8 cmp r4, #0
 *   @0x1f78ac beq 0x1f78e8 <_ZN13CVariableList5AllocEPK9RVariable+0x58>
 *   @0x1f78b0 ldr r2, [r4, #0x4]
 *   @0x1f78b4 add r6, sp, #4
 *   @0x1f78b8 mov r1, r0
 *   @0x1f78bc mov r0, r6
 *   @0x1f78c0 str r2, [r3]
 *   @0x1f78c4 bl 0x1f7404 <_ZN9RVariableC2EPKS_>
 *   @0x1f78c8 mov r0, r4
 *   @0x1f78cc mov r1, r6
 *   @0x1f78d0 bl 0x1f6f80 <_ZN9RVariable6AssignERKS_>
 *   @0x1f78d4 ldr r3, [r5, #0x28]
 *   @0x1f78d8 mov r0, r4
 *   @0x1f78dc str r3, [r4, #0x28]
 *   @0x1f78e0 add sp, sp, #48
 *   @0x1f78e4 pop {r4, r5, r6, pc}
 *   @0x1f78e8 mov r0, #44
 *   @0x1f78ec bl 0x27c524 <_Znwj>
 *   @0x1f78f0 mov r1, r5
 *   @0x1f78f4 mov r4, r0
 *   @0x1f78f8 bl 0x1f7404 <_ZN9RVariableC2EPKS_>
 *   @0x1f78fc b 0x1f78d4 <_ZN13CVariableList5AllocEPK9RVariable+0x44>
 *   @0x1f7900 mulseq pc, r12, r5
 *
 * ══ §218/251 SV_RoomPersistent(CInstance*, int, RValue*)  0x1fcf9c  size 116  29 条（0x1fcf9c..0x1fd010）
 * @func 0x1fcf9c 0x1fd010  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1 / 0x64×1 / 0x4×1 / 0x18×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fcf9c ldr r1, [r2, #0xc]
 *   @0x1fcfa0 ldr r3, [pc, #0x64]
 *   @0x1fcfa4 bic r1, r1, #-16777216
 *   @0x1fcfa8 ldr r3, [pc, r3]
 *   @0x1fcfac cmp r1, #0
 *   @0x1fcfb0 push {r4, lr}
 *   @0x1fcfb4 ldr r4, [r3]
 *   @0x1fcfb8 bne 0x1fcff8 <_Z17SV_RoomPersistentP9CInstanceiP6RValue+0x5c>
 *   @0x1fcfbc ldr r12, [r2]
 *   @0x1fcfc0 ldr r3, [r2, #0x4]
 *   @0x1fcfc4 mov r1, r3
 *   @0x1fcfc8 mov r0, r12
 *   @0x1fcfcc bl 0xb66e8 <lrint@plt>
 *   @0x1fcfd0 vmov.f64 d7, #5.000000e-01
 *   @0x1fcfd4 vmov s11, r0
 *   @0x1fcfd8 mov r0, #1
 *   @0x1fcfdc vcvt.f64.s32 d6, s11
 *   @0x1fcfe0 vcmpe.f64 d6, d7
 *   @0x1fcfe4 vmrs APSR_nzcv, fpscr
 *   @0x1fcfe8 movle r3, #0
 *   @0x1fcfec movgt r3, #1
 *   @0x1fcff0 strb r3, [r4, #0x18]
 *   @0x1fcff4 pop {r4, pc}
 *   @0x1fcff8 mov r0, r2
 *   @0x1fcffc bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fd000 mov r12, r0
 *   @0x1fd004 mov r3, r1
 *   @0x1fd008 b 0x1fcfc4 <_Z17SV_RoomPersistentP9CInstanceiP6RValue+0x28>
 *   @0x1fd00c andseq r0, pc, r0, lsl #19
 *
 * ══ §219/251 SV_BackgroundShowColor(CInstance*, int, RValue*)  0x1fd068  size 116  29 条（0x1fd068..0x1fd0dc）
 * @func 0x1fd068 0x1fd0f0  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1 / 0x64×1 / 0x4×1 / 0x20×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fd068 ldr r1, [r2, #0xc]
 *   @0x1fd06c ldr r3, [pc, #0x64]
 *   @0x1fd070 bic r1, r1, #-16777216
 *   @0x1fd074 ldr r3, [pc, r3]
 *   @0x1fd078 cmp r1, #0
 *   @0x1fd07c push {r4, lr}
 *   @0x1fd080 ldr r4, [r3]
 *   @0x1fd084 bne 0x1fd0c4 <_Z22SV_BackgroundShowColorP9CInstanceiP6RValue+0x5c>
 *   @0x1fd088 ldr r12, [r2]
 *   @0x1fd08c ldr r3, [r2, #0x4]
 *   @0x1fd090 mov r1, r3
 *   @0x1fd094 mov r0, r12
 *   @0x1fd098 bl 0xb66e8 <lrint@plt>
 *   @0x1fd09c vmov.f64 d7, #5.000000e-01
 *   @0x1fd0a0 vmov s11, r0
 *   @0x1fd0a4 mov r0, #1
 *   @0x1fd0a8 vcvt.f64.s32 d6, s11
 *   @0x1fd0ac vcmpe.f64 d6, d7
 *   @0x1fd0b0 vmrs APSR_nzcv, fpscr
 *   @0x1fd0b4 movle r3, #0
 *   @0x1fd0b8 movgt r3, #1
 *   @0x1fd0bc strb r3, [r4, #0x20]
 *   @0x1fd0c0 pop {r4, pc}
 *   @0x1fd0c4 mov r0, r2
 *   @0x1fd0c8 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fd0cc mov r12, r0
 *   @0x1fd0d0 mov r3, r1
 *   @0x1fd0d4 b 0x1fd090 <_Z22SV_BackgroundShowColorP9CInstanceiP6RValue+0x28>
 *   @0x1fd0d8 ldrheq r0, [pc], -r4
 *
 * ══ §220/251 SV_ViewEnabled(CInstance*, int, RValue*)  0x1fd0dc  size 116  29 条（0x1fd0dc..0x1fd150）
 * @func 0x1fd0dc 0x1fd150  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / REAL_RValue_Ex(RValue const*)
 * 字段偏移 top8: 0xc×1 / 0x64×1 / 0x4×1 / 0x44×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fd0dc ldr r1, [r2, #0xc]
 *   @0x1fd0e0 ldr r3, [pc, #0x64]
 *   @0x1fd0e4 bic r1, r1, #-16777216
 *   @0x1fd0e8 ldr r3, [pc, r3]
 *   @0x1fd0ec cmp r1, #0
 *   @0x1fd0f0 push {r4, lr}
 *   @0x1fd0f4 ldr r4, [r3]
 *   @0x1fd0f8 bne 0x1fd138 <_Z14SV_ViewEnabledP9CInstanceiP6RValue+0x5c>
 *   @0x1fd0fc ldr r12, [r2]
 *   @0x1fd100 ldr r3, [r2, #0x4]
 *   @0x1fd104 mov r1, r3
 *   @0x1fd108 mov r0, r12
 *   @0x1fd10c bl 0xb66e8 <lrint@plt>
 *   @0x1fd110 vmov.f64 d7, #5.000000e-01
 *   @0x1fd114 vmov s11, r0
 *   @0x1fd118 mov r0, #1
 *   @0x1fd11c vcvt.f64.s32 d6, s11
 *   @0x1fd120 vcmpe.f64 d6, d7
 *   @0x1fd124 vmrs APSR_nzcv, fpscr
 *   @0x1fd128 movle r3, #0
 *   @0x1fd12c movgt r3, #1
 *   @0x1fd130 strb r3, [r4, #0x44]
 *   @0x1fd134 pop {r4, pc}
 *   @0x1fd138 mov r0, r2
 *   @0x1fd13c bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fd140 mov r12, r0
 *   @0x1fd144 mov r3, r1
 *   @0x1fd148 b 0x1fd104 <_Z14SV_ViewEnabledP9CInstanceiP6RValue+0x28>
 *   @0x1fd14c andseq r0, pc, r0, asr #16
 *
 * ══ §221/251 Audio_SetEmitterPosition(int, double, double, double)  0x216df8  size 116  29 条（0x216df8..0x216e6c）
 * @func 0x216df8 0x216e6c  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x64×1 / 0x50×1 / 0x40×1 / 0x44×1 / 0x2×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x216df8 ldr r1, [pc, #0x64]
 *   @0x216dfc vmov d7, r2, r3
 *   @0x216e00 ldr r1, [pc, r1]
 *   @0x216e04 ldrb r3, [r1]
 *   @0x216e08 cmp r3, #0
 *   @0x216e0c bxeq lr
 *   @0x216e10 ldr r3, [pc, #0x50]
 *   @0x216e14 add r3, pc, r3
 *   @0x216e18 ldr r2, [r3, #0x40]
 *   @0x216e1c cmp r2, r0
 *   @0x216e20 movgt r2, #0
 *   @0x216e24 movle r2, #1
 *   @0x216e28 orrs r2, r2, r0, lsr #31
 *   @0x216e2c bxne lr
 *   @0x216e30 ldr r3, [r3, #0x44]
 *   @0x216e34 ldr r3, [r3, r0, lsl #2]
 *   @0x216e38 cmp r3, #0
 *   @0x216e3c bxeq lr
 *   @0x216e40 vcvt.f32.f64 s14, d7
 *   @0x216e44 vldr d5, [sp]
 *   @0x216e48 vcvt.f32.f64 s13, d5
 *   @0x216e4c vldr d5, [sp, #8]
 *   @0x216e50 vstr s14, [r3]
 *   @0x216e54 vcvt.f32.f64 s15, d5
 *   @0x216e58 vstr s13, [r3, #4]
 *   @0x216e5c vstr s15, [r3, #8]
 *   @0x216e60 bx lr
 *   @0x216e64 andseq r7, sp, r0, lsr pc
 *   @0x216e68 subseq lr, r3, r0, lsl #9
 *
 * ══ §222/251 Audio_SetEmitterVelocity(int, double, double, double)  0x216ed8  size 116  29 条（0x216ed8..0x216f4c）
 * @func 0x216ed8 0x216f4c  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x64×1 / 0x50×1 / 0x40×1 / 0x44×1 / 0x2×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x216ed8 ldr r1, [pc, #0x64]
 *   @0x216edc vmov d7, r2, r3
 *   @0x216ee0 ldr r1, [pc, r1]
 *   @0x216ee4 ldrb r3, [r1]
 *   @0x216ee8 cmp r3, #0
 *   @0x216eec bxeq lr
 *   @0x216ef0 ldr r3, [pc, #0x50]
 *   @0x216ef4 add r3, pc, r3
 *   @0x216ef8 ldr r2, [r3, #0x40]
 *   @0x216efc cmp r2, r0
 *   @0x216f00 movgt r2, #0
 *   @0x216f04 movle r2, #1
 *   @0x216f08 orrs r2, r2, r0, lsr #31
 *   @0x216f0c bxne lr
 *   @0x216f10 ldr r3, [r3, #0x44]
 *   @0x216f14 ldr r3, [r3, r0, lsl #2]
 *   @0x216f18 cmp r3, #0
 *   @0x216f1c bxeq lr
 *   @0x216f20 vcvt.f32.f64 s14, d7
 *   @0x216f24 vldr d5, [sp]
 *   @0x216f28 vcvt.f32.f64 s13, d5
 *   @0x216f2c vldr d5, [sp, #8]
 *   @0x216f30 vstr s14, [r3, #12]
 *   @0x216f34 vcvt.f32.f64 s15, d5
 *   @0x216f38 vstr s13, [r3, #16]
 *   @0x216f3c vstr s15, [r3, #20]
 *   @0x216f40 bx lr
 *   @0x216f44 andseq r7, sp, r0, asr lr
 *   @0x216f48 subseq lr, r3, r0, lsr #7
 *
 * ══ §223/251 Audio_SetMasterGain(int, double)  0x218118  size 116  27 条（0x218118..0x21818c）
 * @func 0x218118 0x21818c  size 116  27 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x60×1 / 0x4c×1 / 0x20×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x218118 ldr r1, [pc, #0x60]
 *   @0x21811c vmov d7, r2, r3
 *   @0x218120 ldr r1, [pc, r1]
 *   @0x218124 ldrb r3, [r1]
 *   @0x218128 cmp r3, #0
 *   @0x21812c bxne lr
 *   @0x218130 ldr r3, [pc, #0x4c]
 *   @0x218134 ldr r3, [pc, r3]
 *   @0x218138 ldrb r3, [r3]
 *   @0x21813c cmp r3, #0
 *   @0x218140 bxeq lr
 *   @0x218144 vcmp.f64 d7, #0
 *   @0x218148 vldr d6, [pc, #40]
 *   @0x21814c vmrs APSR_nzcv, fpscr
 *   @0x218150 vmovmi.f64 d7, d6
 *   @0x218154 cmp r0, #0
 *   @0x218158 bxne lr
 *   @0x21815c vcvt.f32.f64 s13, d7
 *   @0x218160 ldr r3, [pc, #0x20]
 *   @0x218164 ldr r3, [pc, r3]
 *   @0x218168 ldr r0, [r3]
 *   @0x21816c vmov r1, s13
 *   @0x218170 b 0x215b34 <_ZN9CListener7SetGainEf>
 *   @0x218174 nop
 *   @0x218180 andseq r6, sp, r12, lsr #30
 *   @0x218184 ldrsheq r6, [sp], -r12
 *   @0x218188 andseq r9, sp, r8, ror r2
 *
 * ══ §224/251 Audio_SoundSetListenerMask(int, unsigned int)  0x218444  size 116  29 条（0x218444..0x2184b8）
 * @func 0x218444 0x2184b8  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_SoundSetListenerMask(int, unsigned int)+0x4c / Audio_GetNoiseFromID(int)
 * 字段偏移 top8: 0x4×4 / 0x60×1 / 0x-4×1 / 0x48×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x218444 ldr r3, [pc, #0x60]
 *   @0x218448 str lr, [sp, #-0x4]!
 *   @0x21844c ldr r3, [pc, r3]
 *   @0x218450 sub sp, sp, #12
 *   @0x218454 ldrb r3, [r3]
 *   @0x218458 cmp r3, #0
 *   @0x21845c bne 0x218488 <_Z26Audio_SoundSetListenerMaskij+0x44>
 *   @0x218460 ldr r3, [pc, #0x48]
 *   @0x218464 ldr r3, [pc, r3]
 *   @0x218468 ldrb r3, [r3]
 *   @0x21846c cmp r3, #0
 *   @0x218470 beq 0x218488 <_Z26Audio_SoundSetListenerMaskij+0x44>
 *   @0x218474 ldr r3, [pc, #0x38]
 *   @0x218478 ldr r3, [pc, r3]
 *   @0x21847c ldr r3, [r3]
 *   @0x218480 cmp r3, r0
 *   @0x218484 ble 0x218490 <_Z26Audio_SoundSetListenerMaskij+0x4c>
 *   @0x218488 add sp, sp, #12
 *   @0x21848c ldr pc, [sp], #4
 *   @0x218490 str r1, [sp, #0x4]
 *   @0x218494 bl 0x216fbc <_Z20Audio_GetNoiseFromIDi>
 *   @0x218498 ldr r1, [sp, #0x4]
 *   @0x21849c cmp r0, #0
 *   @0x2184a0 strne r1, [r0, #0x34]
 *   @0x2184a4 add sp, sp, #12
 *   @0x2184a8 ldr pc, [sp], #4
 *   @0x2184ac andseq r6, sp, r0, lsl #24
 *   @0x2184b0 andseq r6, sp, r12, asr #17
 *   @0x2184b4 andseq r8, sp, r12, ror #30
 *
 * ══ §225/251 Audio_Suspend()  0x2197fc  size 116  29 条（0x2197fc..0x219870）
 * @func 0x2197fc 0x219870  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: COggAudio::Suspend()
 * 字段偏移 top8: 0xc×2 / 0x38×2 / 0x58×1 / 0x50×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2197fc ldr r3, [pc, #0x58]
 *   @0x219800 push {r4, lr}
 *   @0x219804 ldr r3, [pc, r3]
 *   @0x219808 ldr r1, [pc, #0x50]
 *   @0x21980c ldr r4, [r3]
 *   @0x219810 add r1, pc, r1
 *   @0x219814 ldr r3, [r4]
 *   @0x219818 mov r0, r4
 *   @0x21981c ldr r3, [r3, #0xc]
 *   @0x219820 blx r3
 *   @0x219824 ldr r3, [pc, #0x38]
 *   @0x219828 ldr r0, [pc, #0x38]
 *   @0x21982c mov r2, #1
 *   @0x219830 ldr r3, [pc, r3]
 *   @0x219834 add r0, pc, r0
 *   @0x219838 strb r2, [r3]
 *   @0x21983c bl 0x22609c <_ZN9COggAudio7SuspendEv>
 *   @0x219840 ldr r3, [r4]
 *   @0x219844 mov r0, r4
 *   @0x219848 ldr r1, [pc, #0x1c]
 *   @0x21984c ldr r3, [r3, #0xc]
 *   @0x219850 add r1, pc, r1
 *   @0x219854 blx r3
 *   @0x219858 pop {r4, pc}
 *   @0x21985c andseq r3, sp, r0, lsl pc
 *   @0x219860 andseq r10, r3, r12, asr #11
 *   @0x219864 ldrheq r7, [sp], -r12
 *   @0x219868 subseq r11, r3, r0, ror #20
 *   @0x21986c andseq r10, r3, r4, lsr #11
 *
 * ══ §226/251 CAudioGroup::~CAudioGroup()  0x21db80  size 116  29 条（0x21db80..0x21dbf4）
 * @func 0x21db80 0x21dbf4  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×3 / operator delete(void*)×2 / Mutex::~Mutex()
 * 字段偏移 top8: 0x20×2 / 0x24×2 / 0x18×2 / 0x1c×2 / 0x14×1 / 0xc×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21db80 push {r4, r5, r6, lr}
 *   @0x21db84 mov r4, r0
 *   @0x21db88 ldr r5, [r0, #0x20]
 *   @0x21db8c cmp r5, #0
 *   @0x21db90 beq 0x21dbb8 <_ZN11CAudioGroupD2Ev+0x38>
 *   @0x21db94 ldr r6, [r5, #0x14]
 *   @0x21db98 cmp r6, #0
 *   @0x21db9c beq 0x21dbb0 <_ZN11CAudioGroupD2Ev+0x30>
 *   @0x21dba0 mov r0, r6
 *   @0x21dba4 bl 0x27e020 <_ZN5MutexD2Ev>
 *   @0x21dba8 mov r0, r6
 *   @0x21dbac bl 0x27d1d0 <_ZdlPv>
 *   @0x21dbb0 mov r0, r5
 *   @0x21dbb4 bl 0x27d1d0 <_ZdlPv>
 *   @0x21dbb8 mov r5, #0
 *   @0x21dbbc ldr r0, [r4, #0x24]
 *   @0x21dbc0 str r5, [r4, #0x20]
 *   @0x21dbc4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21dbc8 ldr r0, [r4, #0x18]
 *   @0x21dbcc str r5, [r4, #0x24]
 *   @0x21dbd0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21dbd4 ldr r0, [r4, #0x1c]
 *   @0x21dbd8 str r5, [r4, #0x18]
 *   @0x21dbdc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21dbe0 str r5, [r4, #0x1c]
 *   @0x21dbe4 str r5, [r4, #0xc]
 *   @0x21dbe8 mov r0, r4
 *   @0x21dbec str r5, [r4, #0x8]
 *   @0x21dbf0 pop {r4, r5, r6, pc}
 *
 * ══ §227/251 COggThread::Tick()  0x2247c0  size 116  29 条（0x2247c0..0x224834）
 * @func 0x2247c0 0x224834  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: COggThread::Lock()
 * 字段偏移 top8: 0x800×2 / 0x4c×2 / 0xc×2 / 0x80c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2247c0 push {r3, r4, r5, lr}
 *   @0x2247c4 mov r4, r0
 *   @0x2247c8 bl 0x223a9c <_ZN10COggThread4LockEv>
 *   @0x2247cc ldrb r3, [r4, #0x800]
 *   @0x2247d0 cmp r3, #0
 *   @0x2247d4 beq 0x224820 <_ZN10COggThread4TickEv+0x60>
 *   @0x2247d8 ldr r3, [pc, #0x4c]
 *   @0x2247dc ldr r1, [pc, #0x4c]
 *   @0x2247e0 ldr r3, [pc, r3]
 *   @0x2247e4 ldr r2, [r4, #0x80c]
 *   @0x2247e8 add r1, pc, r1
 *   @0x2247ec ldr r5, [r3]
 *   @0x2247f0 ldr r3, [r5]
 *   @0x2247f4 mov r0, r5
 *   @0x2247f8 ldr r3, [r3, #0xc]
 *   @0x2247fc blx r3
 *   @0x224800 ldr r3, [r5]
 *   @0x224804 mov r0, r5
 *   @0x224808 mov r1, r4
 *   @0x22480c ldr r3, [r3, #0xc]
 *   @0x224810 blx r3
 *   @0x224814 mov r3, #0
 *   @0x224818 strb r3, [r4]
 *   @0x22481c strb r3, [r4, #0x800]
 *   @0x224820 mov r0, r4
 *   @0x224824 pop {r3, r4, r5, lr}
 *   @0x224828 b 0x223aa4 <_ZN10COggThread6UnlockEv>
 *   @0x22482c andseq r8, r12, r4, lsr pc
 *   @0x224830 andseq r0, r3, r4, ror #12
 *
 * ══ §228/251 oggpack_read1  0x233d3c  size 116  29 条（0x233d3c..0x233db0）
 * @func 0x233d3c 0x233dc4  size 136  34 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×3 / 0xc×2 / 0x10×1 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x233d3c ldr r1, [r0]
 *   @0x233d40 mov r3, r0
 *   @0x233d44 ldr r12, [r0, #0x10]
 *   @0x233d48 str r4, [sp, #-0x4]!
 *   @0x233d4c cmp r1, r12
 *   @0x233d50 bge 0x233d94 <oggpack_read1+0x58>
 *   @0x233d54 ldr r12, [r0, #0xc]
 *   @0x233d58 ldr r2, [r0, #0x4]
 *   @0x233d5c ldrb r0, [r12]
 *   @0x233d60 add r4, r2, #1
 *   @0x233d64 cmp r4, #7
 *   @0x233d68 strle r4, [r3, #0x4]
 *   @0x233d6c addgt r12, r12, #1
 *   @0x233d70 addgt r1, r1, #1
 *   @0x233d74 asr r2, r0, r2
 *   @0x233d78 strgt r12, [r3, #0xc]
 *   @0x233d7c and r0, r2, #1
 *   @0x233d80 strgt r1, [r3]
 *   @0x233d84 movgt r2, #0
 *   @0x233d88 strgt r2, [r3, #0x4]
 *   @0x233d8c ldr r4, [sp], #4
 *   @0x233d90 bx lr
 *   @0x233d94 mov r1, #0
 *   @0x233d98 mov r2, #1
 *   @0x233d9c mvn r0, #0
 *   @0x233da0 str r12, [r3]
 *   @0x233da4 str r1, [r3, #0xc]
 *   @0x233da8 str r2, [r3, #0x4]
 *   @0x233dac b 0x233d8c <oggpack_read1+0x50>
 *
 * ══ §229/251 JS_Object_Delete(YYObjectBase*, char const*, bool)  0x24f0a4  size 116  29 条（0x24f0a4..0x24f118）
 * @func 0x24f0a4 0x24f118  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_GetOwnProperty(YYObjectBase*, RValue*, char const*) / JSThrowTypeError(char const*)
 * 字段偏移 top8: 0xc×2 / 0x8×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24f0a4 push {r4, r5, lr}
 *   @0x24f0a8 sub sp, sp, #20
 *   @0x24f0ac mov r12, r1
 *   @0x24f0b0 mov r4, r2
 *   @0x24f0b4 mov r1, sp
 *   @0x24f0b8 mov r2, r12
 *   @0x24f0bc mov r12, #5
 *   @0x24f0c0 str r12, [sp, #0xc]
 *   @0x24f0c4 bl 0x241890 <_Z17JS_GetOwnPropertyP12YYObjectBaseP6RValuePKc>
 *   @0x24f0c8 ldr r1, [sp, #0xc]
 *   @0x24f0cc bic r1, r1, #-16777216
 *   @0x24f0d0 cmp r1, #5
 *   @0x24f0d4 beq 0x24f108 <_Z16JS_Object_DeleteP12YYObjectBasePKcb+0x64>
 *   @0x24f0d8 ldr r3, [sp, #0x8]
 *   @0x24f0dc ands r5, r3, #2
 *   @0x24f0e0 bne 0x24f108 <_Z16JS_Object_DeleteP12YYObjectBasePKcb+0x64>
 *   @0x24f0e4 cmp r4, #0
 *   @0x24f0e8 moveq r0, r4
 *   @0x24f0ec beq 0x24f10c <_Z16JS_Object_DeleteP12YYObjectBasePKcb+0x68>
 *   @0x24f0f0 ldr r0, [pc, #0x1c]
 *   @0x24f0f4 add r0, pc, r0
 *   @0x24f0f8 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x24f0fc mov r0, r5
 *   @0x24f100 add sp, sp, #20
 *   @0x24f104 pop {r4, r5, pc}
 *   @0x24f108 mov r0, #1
 *   @0x24f10c add sp, sp, #20
 *   @0x24f110 pop {r4, r5, pc}
 *   @0x24f114 andseq r6, r0, r4, asr lr
 *
 * ══ §230/251 JS_Math_abs(RValue&, CInstance*, CInstance*, int, RValue*)  0x252168  size 116  29 条（0x252168..0x2521dc）
 * @func 0x252168 0x2521dc  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_Math_abs(RValue&, CInstance*, CInstance*, int, RValue*)+0x50 / F_JS_ToNumber(RValue&, RValue&) / YYGetReal(RValue const*, int)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x252168 cmp r3, #0
 *   @0x25216c push {r3, r4, r5, lr}
 *   @0x252170 mov r5, #0
 *   @0x252174 mov r4, r0
 *   @0x252178 ldr r1, [sp, #0x10]
 *   @0x25217c str r5, [r0, #0xc]
 *   @0x252180 ble 0x2521b8 <_Z11JS_Math_absR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x252184 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_>
 *   @0x252188 cmp r0, #1
 *   @0x25218c beq 0x2521c8 <_Z11JS_Math_absR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x252190 mov r1, r5
 *   @0x252194 mov r0, r4
 *   @0x252198 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x25219c vmov d7, r0, r1
 *   @0x2521a0 vabs.f64 d7, d7
 *   @0x2521a4 vmov r0, r1, d7
 *   @0x2521a8 vmov r2, s14
 *   @0x2521ac mov r3, r1
 *   @0x2521b0 stm r4, {r2, r3}
 *   @0x2521b4 pop {r3, r4, r5, pc}
 *   @0x2521b8 mvn r2, #0
 *   @0x2521bc mvn r3, #-2147483648
 *   @0x2521c0 stm r0, {r2, r3}
 *   @0x2521c4 pop {r3, r4, r5, pc}
 *   @0x2521c8 ldr r0, [pc, #0x8]
 *   @0x2521cc pop {r3, r4, r5, lr}
 *   @0x2521d0 add r0, pc, r0
 *   @0x2521d4 b 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x2521d8 andseq r3, r0, r8, ror sp
 *
 * ══ §231/251 spAnimation_create  0x2812b4  size 116  29 条（0x2812b4..0x281328）
 * @func 0x2812b4 0x281328  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _malloc×2 / _calloc / 0xb6538 / 0xb65a4
 * 字段偏移 top8: 0x60×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2812b4 push {r3, r4, r5, r6, r7, lr}
 *   @0x2812b8 mov r3, #38
 *   @0x2812bc ldr r5, [pc, #0x60]
 *   @0x2812c0 mov r6, r0
 *   @0x2812c4 mov r7, r1
 *   @0x2812c8 mov r0, #1
 *   @0x2812cc add r5, pc, r5
 *   @0x2812d0 mov r1, #16
 *   @0x2812d4 mov r2, r5
 *   @0x2812d8 bl 0x285c4c <_calloc>
 *   @0x2812dc mov r4, r0
 *   @0x2812e0 mov r0, r6
 *   @0x2812e4 bl 0xb6538 <strlen@plt>
 *   @0x2812e8 mov r1, r5
 *   @0x2812ec mov r2, #39
 *   @0x2812f0 add r0, r0, #1
 *   @0x2812f4 bl 0x285c10 <_malloc>
 *   @0x2812f8 mov r1, r6
 *   @0x2812fc str r0, [r4]
 *   @0x281300 bl 0xb65a4 <strcpy@plt>
 *   @0x281304 str r7, [r4, #0x8]
 *   @0x281308 lsl r0, r7, #2
 *   @0x28130c mov r1, r5
 *   @0x281310 mov r2, #41
 *   @0x281314 bl 0x285c10 <_malloc>
 *   @0x281318 str r0, [r4, #0xc]
 *   @0x28131c mov r0, r4
 *   @0x281320 pop {r3, r4, r5, r6, r7, pc}
 *   @0x281324 andeq r6, sp, r4, lsl #3
 *
 * ══ §232/251 Debug_StartStopTarget(bool)  0x29c648  size 116  29 条（0x29c648..0x29c6bc）
 * @func 0x29c648 0x29c6bc  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x29c658→0x757e80, 0x29c668→0x542979, 0x29c66c→0x3f2098, 0x29c674→0x47f290, 0x29c680→0x47f296
 * 调用序列: CProfiler::Pause(bool)
 * 字段偏移 top8: 0x3c×2 / 0x4c×1 / 0x48×1 / 0x38×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29c648 push {r4, r5, r6, lr}
 *   @0x29c64c mov r1, r0
 *   @0x29c650 ldr r4, [pc, #0x4c]
 *   @0x29c654 mov r5, r0
 *   @0x29c658 ldr r3, [pc, #0x48]
 *   @0x29c65c add r4, pc, r4
 *   @0x29c660 ldr r0, [r4, r3]
 *   @0x29c664 bl 0x2a04b8 <_ZN9CProfiler5PauseEb>
 *   @0x29c668 ldr r2, [pc, #0x3c]
 *   @0x29c66c ldr r0, [pc, #0x3c]
 *   @0x29c670 mvn r12, #0
 *   @0x29c674 ldr r1, [pc, #0x38]
 *   @0x29c678 mov r3, #0
 *   @0x29c67c ldr r6, [r4, r2]
 *   @0x29c680 ldr r2, [pc, #0x30]
 *   @0x29c684 strb r5, [r6]
 *   @0x29c688 ldr r0, [r4, r0]
 *   @0x29c68c str r12, [r0]
 *   @0x29c690 ldr r1, [r4, r1]
 *   @0x29c694 str r3, [r1]
 *   @0x29c698 ldr r2, [r4, r2]
 *   @0x29c69c strb r3, [r2]
 *   @0x29c6a0 pop {r4, r5, r6, pc}
 *   @0x29c6a4 ldrsheq r5, [r5], -r4
 *   @0x29c6a8 .word 0xffffbf1c
 *   @0x29c6ac .word 0xffffdfa0
 *   @0x29c6b0 .word 0xffffc0f8
 *   @0x29c6b4 .word 0xffffc0f0
 *   @0x29c6b8 .word 0xfffffdbc
 *
 * ══ §233/251 png_crc_finish  0x2abc94  size 116  29 条（0x2abc94..0x2abd08）
 * @func 0x2abc94 0x2abd08  size 116  29 条
 * 部分覆盖: 本节 29/52 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_crc_finish+0x20 / png_crc_error / png_chunk_warning
 * 字段偏移 top8: 0x1f×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2abc94 push {r4, r5, r6, lr}
 *   @0x2abc98 ldr.w r6, [r0, #0x174]
 *   @0x2abc9c mov r5, r1
 *   @0x2abca0 bls 0x2abcb4 <png_crc_finish+0x20>
 *   @0x2abca4 ldr.w r1, [r4, #0x170]
 *   @0x2abca8 ldr.w r2, [r4, #0x174]
 *   @0x2abcac subs r5, r5, r6
 *   @0x2abcb0 ldrb pc, [r4, sp, lsr #31]!
 *   @0x2abcb4 cbz r5, 0x2abcc2 <png_crc_finish+0x2e>
 *   @0x2abcb8 ldr.w r1, [r4, #0x170]
 *   @0x2abcbc mov r2, r5
 *   @0x2abcc0 strtmi pc, [r0], -r5, lsr #31
 *   @0x2abcc4 bl 0x2abc2a <png_crc_error>
 *   @0x2abcc8 cbz r0, 0x2abcfc <png_crc_finish+0x68>
 *   @0x2abccc .word 0xf01331e0
 *   @0x2abcd0 .word 0xf8d40f20
 *   @0x2abcd4 andle r3, r2, r0, lsr r1
 *   @0x2abcd8 lsls r2, r3, #0x16
 *   @0x2abcdc b 0x2abce2 <png_crc_finish+0x4e>
 *   @0x2abce0 bpl 0x2abcf0 <png_crc_finish+0x5c>
 *   @0x2abce4 mov r0, r4
 *   @0x2abce8 bl 0x2a6504 <png_chunk_warning>
 *   @0x2abcec movs r0, #0x1
 *   @0x2abcf0 ldr r1, [pc, #0x10]
 *   @0x2abcf4 add r1, pc
 *   @0x2abcf8 andhs pc, r0, r9, ror #23
 *   @0x2abcfc pop {r4, r5, r6, pc}
 *   @0x2abd00 lsls r6, r0, #0xf
 *   @0x2abd04 lsls r0, r7, #0xe
 *
 * ══ §234/251 GifFreeExtensions(int*, ExtensionBlock**)  0x2c2ff8  size 116  29 条（0x2c2ff8..0x2c306c）
 * @func 0x2c2ff8 0x2c306c  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb655c×2 / GifFreeExtensions(int*, ExtensionBlock**)+0x30
 * 字段偏移 top8: 0x-8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c2ff8 push {r3, r4, r5, r6, r7, lr}
 *   @0x2c2ffc mov r6, r1
 *   @0x2c3000 ldr r4, [r1]
 *   @0x2c3004 mov r7, r0
 *   @0x2c3008 cmp r4, #0
 *   @0x2c300c popeq {r3, r4, r5, r6, r7, pc}
 *   @0x2c3010 ldr r3, [r0]
 *   @0x2c3014 add r3, r3, r3, lsl #1
 *   @0x2c3018 add r3, r4, r3, lsl #2
 *   @0x2c301c cmp r4, r3
 *   @0x2c3020 bhs 0x2c3064 <_Z17GifFreeExtensionsPiPP14ExtensionBlock+0x6c>
 *   @0x2c3024 add r4, r4, #12
 *   @0x2c3028 ldr r0, [r4, #-0x8]
 *   @0x2c302c mov r5, r4
 *   @0x2c3030 bl 0xb655c <free@plt>
 *   @0x2c3034 ldr r3, [r7]
 *   @0x2c3038 ldr r0, [r6]
 *   @0x2c303c add r3, r3, r3, lsl #1
 *   @0x2c3040 add r3, r0, r3, lsl #2
 *   @0x2c3044 cmp r4, r3
 *   @0x2c3048 add r4, r4, #12
 *   @0x2c304c blo 0x2c3028 <_Z17GifFreeExtensionsPiPP14ExtensionBlock+0x30>
 *   @0x2c3050 bl 0xb655c <free@plt>
 *   @0x2c3054 mov r3, #0
 *   @0x2c3058 str r3, [r6]
 *   @0x2c305c str r3, [r7]
 *   @0x2c3060 pop {r3, r4, r5, r6, r7, pc}
 *   @0x2c3064 mov r0, r4
 *   @0x2c3068 b 0x2c3050 <_Z17GifFreeExtensionsPiPP14ExtensionBlock+0x58>
 *
 * ══ §235/251 b2PolygonShape::SetAsBox(float, float)  0x2c5e9c  size 116  29 条（0x2c5e9c..0x2c5f10）
 * @func 0x2c5e9c 0x2c5f10  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x94×1 / 0x1c×1 / 0x54×1 / 0x60×1 / 0x64×1 / 0x70×1 / 0xc×1 / 0x10×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c5e9c vmov s14, r1
 *   @0x2c5ea0 mov r3, #4
 *   @0x2c5ea4 vmov s15, r2
 *   @0x2c5ea8 mov r12, #0
 *   @0x2c5eac vneg.f32 s14, s14
 *   @0x2c5eb0 movt r12, #0xbf80
 *   @0x2c5eb4 str r3, [r0, #0x94]
 *   @0x2c5eb8 mov r3, #0
 *   @0x2c5ebc str r1, [r0, #0x1c]
 *   @0x2c5ec0 str r3, [r0, #0x54]
 *   @0x2c5ec4 vneg.f32 s15, s15
 *   @0x2c5ec8 str r3, [r0, #0x60]
 *   @0x2c5ecc str r3, [r0, #0x64]
 *   @0x2c5ed0 vstr s14, [r0, #20]
 *   @0x2c5ed4 str r3, [r0, #0x70]
 *   @0x2c5ed8 vstr s14, [r0, #44]
 *   @0x2c5edc str r3, [r0, #0xc]
 *   @0x2c5ee0 str r3, [r0, #0x10]
 *   @0x2c5ee4 vstr s15, [r0, #24]
 *   @0x2c5ee8 mov r3, #1065353216
 *   @0x2c5eec str r1, [r0, #0x24]
 *   @0x2c5ef0 str r2, [r0, #0x28]
 *   @0x2c5ef4 vstr s15, [r0, #32]
 *   @0x2c5ef8 str r2, [r0, #0x30]
 *   @0x2c5efc str r12, [r0, #0x58]
 *   @0x2c5f00 str r12, [r0, #0x6c]
 *   @0x2c5f04 str r3, [r0, #0x5c]
 *   @0x2c5f08 str r3, [r0, #0x68]
 *   @0x2c5f0c bx lr
 *
 * ══ §236/251 b2DistanceJoint::b2DistanceJoint(b2DistanceJointDef const*)  0x2cd2ac  size 116  29 条（0x2cd2ac..0x2cd320）
 * @func 0x2cd2ac 0x2cd320  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Joint::b2Joint(b2JointDef const*)
 * 字段偏移 top8: 0x54×1 / 0x24×1 / 0x50×1 / 0x2c×1 / 0x28×1 / 0x68×1 / 0x44×1 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cd2ac push {r3, r4, r5, r6, r7, lr}
 *   @0x2cd2b0 mov r4, r0
 *   @0x2cd2b4 mov r5, r1
 *   @0x2cd2b8 bl 0x2cdee0 <_ZN7b2JointC2EPK10b2JointDef>
 *   @0x2cd2bc add r3, r5, #20
 *   @0x2cd2c0 ldr r2, [pc, #0x54]
 *   @0x2cd2c4 add r6, r5, #28
 *   @0x2cd2c8 ldr r7, [r5, #0x24]
 *   @0x2cd2cc ldm r3, {r0, r1}
 *   @0x2cd2d0 ldr r2, [pc, r2]
 *   @0x2cd2d4 mov r3, r4
 *   @0x2cd2d8 add r2, r2, #8
 *   @0x2cd2dc str r2, [r3], #80
 *   @0x2cd2e0 add r12, r4, #88
 *   @0x2cd2e4 stm r3, {r0, r1}
 *   @0x2cd2e8 mov r3, #0
 *   @0x2cd2ec ldm r6, {r0, r1}
 *   @0x2cd2f0 ldr r2, [r5, #0x2c]
 *   @0x2cd2f4 ldr r6, [r5, #0x28]
 *   @0x2cd2f8 stm r12, {r0, r1}
 *   @0x2cd2fc mov r0, r4
 *   @0x2cd300 str r7, [r4, #0x68]
 *   @0x2cd304 str r6, [r4, #0x44]
 *   @0x2cd308 str r2, [r4, #0x48]
 *   @0x2cd30c str r3, [r4, #0x64]
 *   @0x2cd310 str r3, [r4, #0x60]
 *   @0x2cd314 str r3, [r4, #0x4c]
 *   @0x2cd318 pop {r3, r4, r5, r6, r7, pc}
 *   @0x2cd31c andseq r4, r2, r8, lsl #17
 *
 * ══ §237/251 b2MotorJoint::SetLinearOffset(b2Vec2 const&)  0x2ce870  size 116  29 条（0x2ce870..0x2ce8e4）
 * @func 0x2ce870 0x2ce8e4  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x30×1 / 0x-10×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ce870 vldr s15, [r0, #68]
 *   @0x2ce874 vldr s14, [r1]
 *   @0x2ce878 vcmp.f32 s14, s15
 *   @0x2ce87c mov r3, r0
 *   @0x2ce880 vmrs APSR_nzcv, fpscr
 *   @0x2ce884 bne 0x2ce89c <_ZN12b2MotorJoint15SetLinearOffsetERK6b2Vec2+0x2c>
 *   @0x2ce888 vldr s14, [r1, #4]
 *   @0x2ce88c vldr s15, [r0, #72]
 *   @0x2ce890 vcmp.f32 s14, s15
 *   @0x2ce894 vmrs APSR_nzcv, fpscr
 *   @0x2ce898 bxeq lr
 *   @0x2ce89c ldr r2, [r3, #0x30]
 *   @0x2ce8a0 add r3, r3, #68
 *   @0x2ce8a4 ldrh r0, [r2, #4]
 *   @0x2ce8a8 tst r0, #2
 *   @0x2ce8ac orreq r0, r0, #2
 *   @0x2ce8b0 strheq r0, [r2, #4]
 *   @0x2ce8b4 moveq r12, #0
 *   @0x2ce8b8 streq r12, [r2, #0xa0]
 *   @0x2ce8bc ldr r2, [r3, #-0x10]
 *   @0x2ce8c0 ldrh r0, [r2, #4]
 *   @0x2ce8c4 tst r0, #2
 *   @0x2ce8c8 orreq r0, r0, #2
 *   @0x2ce8cc strheq r0, [r2, #4]
 *   @0x2ce8d0 ldm r1, {r0, r1}
 *   @0x2ce8d4 moveq r12, #0
 *   @0x2ce8d8 streq r12, [r2, #0xa0]
 *   @0x2ce8dc stm r3, {r0, r1}
 *   @0x2ce8e0 bx lr
 *
 * ══ §238/251 b2WeldJoint::b2WeldJoint(b2WeldJointDef const*)  0x2d3724  size 116  29 条（0x2d3724..0x2d3798）
 * @func 0x2d3724 0x2d3798  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Joint::b2Joint(b2JointDef const*)
 * 字段偏移 top8: 0x54×1 / 0x24×1 / 0x50×1 / 0x2c×1 / 0x28×1 / 0x60×1 / 0x44×1 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d3724 push {r3, r4, r5, r6, r7, lr}
 *   @0x2d3728 mov r4, r0
 *   @0x2d372c mov r5, r1
 *   @0x2d3730 bl 0x2cdee0 <_ZN7b2JointC2EPK10b2JointDef>
 *   @0x2d3734 add r3, r5, #20
 *   @0x2d3738 ldr r2, [pc, #0x54]
 *   @0x2d373c add r6, r5, #28
 *   @0x2d3740 ldr r7, [r5, #0x24]
 *   @0x2d3744 ldm r3, {r0, r1}
 *   @0x2d3748 ldr r2, [pc, r2]
 *   @0x2d374c mov r3, r4
 *   @0x2d3750 add r2, r2, #8
 *   @0x2d3754 str r2, [r3], #80
 *   @0x2d3758 add r12, r4, #88
 *   @0x2d375c stm r3, {r0, r1}
 *   @0x2d3760 mov r3, #0
 *   @0x2d3764 ldm r6, {r0, r1}
 *   @0x2d3768 ldr r2, [r5, #0x2c]
 *   @0x2d376c ldr r6, [r5, #0x28]
 *   @0x2d3770 stm r12, {r0, r1}
 *   @0x2d3774 mov r0, r4
 *   @0x2d3778 str r7, [r4, #0x60]
 *   @0x2d377c str r6, [r4, #0x44]
 *   @0x2d3780 str r2, [r4, #0x48]
 *   @0x2d3784 str r3, [r4, #0x68]
 *   @0x2d3788 str r3, [r4, #0x6c]
 *   @0x2d378c str r3, [r4, #0x70]
 *   @0x2d3790 pop {r3, r4, r5, r6, r7, pc}
 *   @0x2d3794 andseq lr, r1, r0, lsr r4
 *
 * ══ §239/251 ft_corner_is_flat  0x2e5248  size 116  29 条（0x2e5248..0x2e52bc）
 * @func 0x2e5248 0x2e52bc  size 116  29 条
 * 部分覆盖: 本节 29/54 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x3259f8 / 0x426640 / 0x9a6644
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5248 push {r4, r5, r6, lr}
 *   @0x2e524c adds r5, r1, r3
 *   @0x2e5250 it lt
 *   @0x2e5254 cmp r1, #0x0
 *   @0x2e5258 rsblt r1, r1, #0
 *   @0x2e525c cmp r0, r1
 *   @0x2e5260 mulgt r1, r4, r1
 *   @0x2e5264 mov.w r4, #0x3
 *   @0x2e5268 ite gt
 *   @0x2e526c bl 0x3259f8
 *   @0x2e5270 bhs 0x2e59f8 <FT_Face_Properties>
 *   @0x2e5274 it lt
 *   @0x2e5278 cmp r3, #0x0
 *   @0x2e527c rsblt r3, r3, #0
 *   @0x2e5280 cmp r2, r3
 *   @0x2e5284 mulgt r3, r0, r3
 *   @0x2e5288 addgt.w r3, r2, r3, asr #3
 *   @0x2e528c addle.w r3, r3, r2, asr #3
 *   @0x2e5290 cmp r6, #0x0
 *   @0x2e5294 rsblt r6, r6, #0
 *   @0x2e5298 it lt
 *   @0x2e529c add r3, r1
 *   @0x2e52a0 itete gt
 *   @0x2e52a4 mulle r4, r6, r4
 *   @0x2e52a8 bl 0x426640 <g_RomDisk+0x2ee20>
 *   @0x2e52ac blne 0x9a6644 <b2_toiTime+0x24d1a0>
 *   @0x2e52b0 cmp.w r3, r4, asr #4
 *   @0x2e52b4 ite ge
 *   @0x2e52b8 movlt r0, #0x1
 *
 * ══ §240/251 FT_Outline_Reverse  0x2e6452  size 116  29 条（0x2e6452..0x2e64c6）
 * @func 0x2e6452 0x2e64c6  size 116  29 条
 * 部分覆盖: 本节 29/50 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x8×1 / 0x12×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e6452 push.w {r4, r5, r6, r7, r8, lr}
 *   @0x2e6456 mov r3, r0
 *   @0x2e645a movs r6, #0x0
 *   @0x2e645e ldrsh.w r2, [r3]
 *   @0x2e6462 cmp r5, r2
 *   @0x2e6466 ldr r2, [r3, #0xc]
 *   @0x2e646a ldrsh.w r7, [r2, r5, lsl #1]
 *   @0x2e646e add.w r2, r4, r6, lsl #3
 *   @0x2e6472 add.w r4, r4, r7, lsl #3
 *   @0x2e6476 cmp r2, r4
 *   @0x2e647a .word 0xf1020408
 *   @0x2e647e andle r0, r11, #8, #4
 *   @0x2e6482 add.w r1, r4, #0x8
 *   @0x2e6486 ldmdb r2, {r8, r12}
 *   @0x2e648a ldm r1, {r0, r1}
 *   @0x2e648e .word 0xf8c40003
 *   @0x2e6492 .word 0xf8c48008
 *   @0x2e6496 strb r12, [sp, r12]!
 *   @0x2e649a ldr r2, [r3, #0x8]
 *   @0x2e649e add r2, r7
 *   @0x2e64a2 bhs 0x2e64b2 <FT_Outline_Reverse+0x60>
 *   @0x2e64a6 ldrb r0, [r2]
 *   @0x2e64aa .word 0xf8020b01
 *   @0x2e64ae ldrb r1, [r6, r1, lsl #18]!
 *   @0x2e64b2 adds r5, #0x1
 *   @0x2e64b6 uxth r5, r5
 *   @0x2e64ba ldr r2, [r3, #0x10]
 *   @0x2e64be tstvs r10, r4, lsl #4
 *   @0x2e64c2 pop.w {r4, r5, r6, r7, r8, pc}
 *
 * ══ §241/251 __cxa_type_match  0x3185b4  size 116  29 条（0x3185b4..0x318628）
 * @func 0x3185b4 0x318628  size 116  29 条
 * 部分覆盖: 本节 29/53 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c10
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_317a44
 * 字段偏移 top8: 0x50×2 / 0x-34×1 / 0x4×1 / 0x110×1 / 0xd0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x3185b4 push {r4, r5, r6, r7, lr}
 *   @0x3185b8 ldr r4, [r0, #-52]
 *   @0x3185bc add.w r2, r0, #0x58
 *   @0x3185c0 mov r5, r0
 *   @0x3185c4 mov r7, r3
 *   @0x3185c8 cmp r4, #0x0
 *   @0x3185cc ldr r1, [pc, #0x50]
 *   @0x3185d0 ldr r2, [pc, #0x50]
 *   @0x3185d4 add r1, pc
 *   @0x3185d8 add r2, pc
 *   @0x3185dc bl 0x317a44 <ft_lzwstate_io+0xa90>
 *   @0x3185e0 cbz r0, 0x318616 <__cxa_type_match+0x62>
 *   @0x3185e4 movs r5, #0x2
 *   @0x3185e8 rsbs.w r3, r4, #0x1
 *   @0x3185ec it lo
 *   @0x3185f0 cmp r6, #0x0
 *   @0x3185f4 orreq r3, r3, #0x1
 *   @0x3185f8 cbz r3, 0x318602 <__cxa_type_match+0x4e>
 *   @0x3185fc mov r0, r5
 *   @0x318600 pop {r4, r5, r6, r7, pc}
 *   @0x318604 mov r0, r6
 *   @0x318608 add r2, sp, #0x4
 *   @0x31860c blx r3
 *   @0x318610 ldr r3, [sp, #0x4]
 *   @0x318614 b 0x3185fc <__cxa_type_match+0x48>
 *   @0x318618 b 0x3185e8 <__cxa_type_match+0x34>
 *   @0x31861c b 0x3185fc <__cxa_type_match+0x48>
 *   @0x318620 str r6, [sp, #0x110]
 *   @0x318624 str r6, [sp, #0xd0]
 *
 * ══ §242/251 __gnu_Unwind_Resume  0x319b2c  size 116  29 条（0x319b2c..0x319ba0）
 * @func 0x319b2c 0x319ba0  size 116  29 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_319630+0x310 / anon_319630+0x2ac / anon_319630+0x2a8 / restore_core_regs / 0xb6c88
 * 字段偏移 top8: 0x40×2 / 0xc×1 / 0x14×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x319b2c push {r4, r5, r6, lr}
 *   @0x319b30 mov r5, r0
 *   @0x319b34 ldr r6, [r0, #0xc]
 *   @0x319b38 mov r4, r1
 *   @0x319b3c ldr r3, [r0, #0x14]
 *   @0x319b40 cmp r6, #0
 *   @0x319b44 str r3, [r1, #0x40]
 *   @0x319b48 beq 0x319b58 <__gnu_Unwind_Resume+0x2c>
 *   @0x319b4c mov r2, #1
 *   @0x319b50 bl 0x319940 <__gnu_uldivmod_helper+0x34c>
 *   @0x319b54 b 0x319b9c <__gnu_Unwind_Resume+0x70>
 *   @0x319b58 ldr r3, [r0, #0x10]
 *   @0x319b5c mov r1, r5
 *   @0x319b60 mov r0, #2
 *   @0x319b64 mov r2, r4
 *   @0x319b68 blx r3
 *   @0x319b6c cmp r0, #7
 *   @0x319b70 beq 0x319b88 <__gnu_Unwind_Resume+0x5c>
 *   @0x319b74 cmp r0, #8
 *   @0x319b78 bne 0x319b9c <__gnu_Unwind_Resume+0x70>
 *   @0x319b7c mov r0, r5
 *   @0x319b80 mov r1, r4
 *   @0x319b84 bl 0x3198dc <__gnu_uldivmod_helper+0x2e8>
 *   @0x319b88 mov r0, r6
 *   @0x319b8c ldr r1, [r4, #0x40]
 *   @0x319b90 bl 0x3198d8 <__gnu_uldivmod_helper+0x2e4>
 *   @0x319b94 add r0, r4, #4
 *   @0x319b98 bl 0x31a508 <restore_core_regs>
 *   @0x319b9c bl 0xb6c88 <abort@plt>
 *
 * ══ §243/251 FT_Set_Transform  0x2e539e  size 114  29 条（0x2e539e..0x2e5410）
 * @func 0x2e539e 0x2e5412  size 116  29 条
 * 部分覆盖: 本节 29/52 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×3 / 0x4×2 / 0x8×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e539e push {r4, r5, r6, lr}
 *   @0x2e53a2 mov r6, r2
 *   @0x2e53a6 beq 0x2e540e <FT_Set_Transform+0x70>
 *   @0x2e53aa movwhs r4, #0x80
 *   @0x2e53ae str r3, [r4, #0x18]
 *   @0x2e53b2 mov.w r3, #0x10000
 *   @0x2e53b6 str r1, [r4, #0x8]
 *   @0x2e53ba strtmi r0, [r5], -r8, lsr #32
 *   @0x2e53be str r3, [r4, #0xc]
 *   @0x2e53c2 ldm r1, {r0, r1, r2, r3}
 *   @0x2e53c6 stmvs r10!, {r0, r1, r2, r3}
 *   @0x2e53ca ldr r3, [r5, #0x4]
 *   @0x2e53ce bne 0x2e53e0 <FT_Set_Transform+0x42>
 *   @0x2e53d2 cmp.w r3, #0x10000
 *   @0x2e53d6 bne 0x2e53e0 <FT_Set_Transform+0x42>
 *   @0x2e53da cmp.w r3, #0x10000
 *   @0x2e53de beq 0x2e53e8 <FT_Set_Transform+0x4a>
 *   @0x2e53e2 orr r3, r3, #0x1
 *   @0x2e53e6 str r3, [r4, #0x18]
 *   @0x2e53ea ldmdblt lr, {r4, r8, r9}
 *   @0x2e53ee str r6, [r4, #0x10]
 *   @0x2e53f2 mov r6, r3
 *   @0x2e53f6 ldm.w r6, {r0, r1}
 *   @0x2e53fa stm.w r3, {r0, r1}
 *   @0x2e53fe ldr r2, [r6, #0x4]
 *   @0x2e5402 orrs r3, r2
 *   @0x2e5406 ldr r3, [r4, #0x18]
 *   @0x2e540a .word 0x61a30302
 *   @0x2e540e pop {r4, r5, r6, pc}
 *
 * ══ §244/251 CBackground::LoadFromPNGData(void*, int, bool, bool, bool, bool)  0xc26ac  size 112  28 条（0xc26ac..0xc271c）
 * @func 0xc26ac 0xc271c  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ReadPNGFile(void*, int, int*, int*, bool) / CBackground::LoadFromData(void*, int, int, bool, bool, bool, bool) / FreePNGFile()
 * 字段偏移 top8: 0x38×1 / 0x30×1 / 0x34×1 / 0x10×1 / 0x14×1 / 0xc×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc26ac push {r4, r5, r6, r7, r8, lr}
 *   @0xc26b0 sub sp, sp, #24
 *   @0xc26b4 mov r8, r0
 *   @0xc26b8 mov r7, r3
 *   @0xc26bc mov r0, r1
 *   @0xc26c0 mov r3, #0
 *   @0xc26c4 mov r1, r2
 *   @0xc26c8 str r3, [sp]
 *   @0xc26cc add r2, sp, #16
 *   @0xc26d0 add r3, sp, #20
 *   @0xc26d4 ldrb r4, [sp, #0x38]
 *   @0xc26d8 ldrb r6, [sp, #0x30]
 *   @0xc26dc ldrb r5, [sp, #0x34]
 *   @0xc26e0 bl 0x18a24c <_Z11ReadPNGFilePviPiS0_b>
 *   @0xc26e4 ldr r2, [sp, #0x10]
 *   @0xc26e8 ldr r3, [sp, #0x14]
 *   @0xc26ec str r4, [sp, #0xc]
 *   @0xc26f0 str r7, [sp]
 *   @0xc26f4 str r6, [sp, #0x4]
 *   @0xc26f8 str r5, [sp, #0x8]
 *   @0xc26fc mov r1, r0
 *   @0xc2700 mov r0, r8
 *   @0xc2704 bl 0xc2618 <_ZN11CBackground12LoadFromDataEPviibbbb>
 *   @0xc2708 mov r4, r0
 *   @0xc270c bl 0x18a518 <_Z11FreePNGFilev>
 *   @0xc2710 mov r0, r4
 *   @0xc2714 add sp, sp, #24
 *   @0xc2718 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §245/251 Buffer_Fast::Read(eBuffer_Type, RValue*)  0xc4b5c  size 112  28 条（0xc4b5c..0xc4bcc）
 * @func 0xc4b5c 0xc4bcc  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x1c×2 / 0x4×1 / 0x10×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc4b5c cmp r1, #1
 *   @0xc4b60 mov r3, #0
 *   @0xc4b64 push {r4, r5}
 *   @0xc4b68 str r3, [r2, #0xc]
 *   @0xc4b6c str r3, [r2]
 *   @0xc4b70 str r3, [r2, #0x4]
 *   @0xc4b74 bne 0xc4bbc <_ZN11Buffer_Fast4ReadE12eBuffer_TypeP6RValue+0x60>
 *   @0xc4b78 ldr r1, [r0, #0x1c]
 *   @0xc4b7c ldr r12, [r0, #0x10]
 *   @0xc4b80 cmp r1, r12
 *   @0xc4b84 bge 0xc4bc4 <_ZN11Buffer_Fast4ReadE12eBuffer_TypeP6RValue+0x68>
 *   @0xc4b88 ldr r12, [r0, #0xc]
 *   @0xc4b8c add r4, r1, #1
 *   @0xc4b90 str r4, [r0, #0x1c]
 *   @0xc4b94 mov r0, r3
 *   @0xc4b98 ldrb r4, [r12, r1]
 *   @0xc4b9c vmov s15, r4
 *   @0xc4ba0 vcvt.f64.u32 d7, s15
 *   @0xc4ba4 vmov r4, r5, d7
 *   @0xc4ba8 vmov r1, s14
 *   @0xc4bac mov r3, r5
 *   @0xc4bb0 stm r2, {r1, r3}
 *   @0xc4bb4 pop {r4, r5}
 *   @0xc4bb8 bx lr
 *   @0xc4bbc mvn r0, #3
 *   @0xc4bc0 b 0xc4bb4 <_ZN11Buffer_Fast4ReadE12eBuffer_TypeP6RValue+0x58>
 *   @0xc4bc4 mvn r0, #1
 *   @0xc4bc8 b 0xc4bb4 <_ZN11Buffer_Fast4ReadE12eBuffer_TypeP6RValue+0x58>
 *
 * ══ §246/251 F_BUFFER_GetAddress(RValue&, CInstance*, CInstance*, int, RValue*)  0xc6318  size 112  28 条（0xc6318..0xc6388）
 * @func 0xc6318 0xc6388  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / F_BUFFER_GetAddress(RValue&, CInstance*, CInstance*, int, RValue*)+0x54
 * 字段偏移 top8: 0x8×1 / 0xc×1 / 0x38×1 / 0x4×1 / 0x2×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc6318 push {r4, lr}
 *   @0xc631c mov r2, #3
 *   @0xc6320 ldr r3, [sp, #0x8]
 *   @0xc6324 mov r4, r0
 *   @0xc6328 str r2, [r0, #0xc]
 *   @0xc632c mov r1, #0
 *   @0xc6330 mov r0, r3
 *   @0xc6334 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc6338 cmp r0, #0
 *   @0xc633c blt 0xc636c <_Z19F_BUFFER_GetAddressR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0xc6340 ldr r3, [pc, #0x38]
 *   @0xc6344 add r3, pc, r3
 *   @0xc6348 ldr r2, [r3]
 *   @0xc634c cmp r0, r2
 *   @0xc6350 bge 0xc636c <_Z19F_BUFFER_GetAddressR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0xc6354 ldr r3, [r3, #0x4]
 *   @0xc6358 ldr r3, [r3, r0, lsl #2]
 *   @0xc635c cmp r3, #0
 *   @0xc6360 ldrne r3, [r3, #0xc]
 *   @0xc6364 strne r3, [r4]
 *   @0xc6368 popne {r4, pc}
 *   @0xc636c ldr r0, [pc, #0x10]
 *   @0xc6370 mov r1, #0
 *   @0xc6374 pop {r4, lr}
 *   @0xc6378 add r0, pc, r0
 *   @0xc637c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc6380 ldrsbteq r3, [r11], -r0
 *   @0xc6384 .word 0x0026aab4
 *
 * ══ §247/251 Variable_FindNameNoAlloc(char const*)  0xd1c94  size 112  28 条（0xd1c94..0xd1d04）
 * @func 0xd1c94 0xd1d04  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Variable_FindNameNoAlloc(char const*)+0x60 / 0xb6574
 * 字段偏移 top8: 0x58×1 / 0x48×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd1c94 push {r3, r4, r5, r6, r7, lr}
 *   @0xd1c98 mov r7, r0
 *   @0xd1c9c ldr r3, [pc, #0x58]
 *   @0xd1ca0 ldr r3, [pc, r3]
 *   @0xd1ca4 ldr r6, [r3]
 *   @0xd1ca8 cmp r6, #0
 *   @0xd1cac ble 0xd1cf4 <_Z24Variable_FindNameNoAllocPKc+0x60>
 *   @0xd1cb0 ldr r3, [pc, #0x48]
 *   @0xd1cb4 mov r4, #0
 *   @0xd1cb8 ldr r3, [pc, r3]
 *   @0xd1cbc ldr r5, [r3]
 *   @0xd1cc0 sub r5, r5, #4
 *   @0xd1cc4 b 0xd1cd4 <_Z24Variable_FindNameNoAllocPKc+0x40>
 *   @0xd1cc8 add r4, r4, #1
 *   @0xd1ccc cmp r4, r6
 *   @0xd1cd0 beq 0xd1cf4 <_Z24Variable_FindNameNoAllocPKc+0x60>
 *   @0xd1cd4 ldr r0, [r5, #0x4]!
 *   @0xd1cd8 mov r1, r7
 *   @0xd1cdc bl 0xb6574 <strcmp@plt>
 *   @0xd1ce0 cmp r0, #0
 *   @0xd1ce4 bne 0xd1cc8 <_Z24Variable_FindNameNoAllocPKc+0x34>
 *   @0xd1ce8 add r0, r4, #99328
 *   @0xd1cec add r0, r0, #672
 *   @0xd1cf0 pop {r3, r4, r5, r6, r7, pc}
 *   @0xd1cf4 mvn r0, #0
 *   @0xd1cf8 pop {r3, r4, r5, r6, r7, pc}
 *   @0xd1cfc ldrshteq r11, [r1], -r4
 *   @0xd1d00 eorseq r11, r1, r0, ror #29
 *
 * ══ §248/251 VMWriteBuffer::Reserve(int)  0xec604  size 112  28 条（0xec604..0xec674）
 * @func 0xec604 0xec674  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new[](unsigned int) / 0xb65bc
 * 字段偏移 top8: 0x10×3 / 0x4×3 / 0x1c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xec604 push {r4, r5, r6, lr}
 *   @0xec608 mov r4, r0
 *   @0xec60c ldr r2, [r4, #0x1c]
 *   @0xec610 mov r6, r1
 *   @0xec614 ldr r0, [r0, #0x10]
 *   @0xec618 ldr r3, [r4, #0x4]
 *   @0xec61c rsb r1, r2, r0
 *   @0xec620 add r1, r3, r1
 *   @0xec624 cmp r6, r1
 *   @0xec628 pople {r4, r5, r6, pc}
 *   @0xec62c rsb r5, r0, r2
 *   @0xec630 lsl r0, r3, #1
 *   @0xec634 bl 0x27d14c <_Znaj>
 *   @0xec638 ldr r1, [r4, #0x10]
 *   @0xec63c mov r2, r5
 *   @0xec640 bl 0xb65bc <memcpy@plt>
 *   @0xec644 ldr r3, [r4, #0x4]
 *   @0xec648 lsl r3, r3, #1
 *   @0xec64c str r3, [r4, #0x4]
 *   @0xec650 add r2, r0, r5
 *   @0xec654 mov r12, r0
 *   @0xec658 rsb r1, r2, r0
 *   @0xec65c str r2, [r4, #0x1c]
 *   @0xec660 add r1, r3, r1
 *   @0xec664 str r12, [r4, #0x10]
 *   @0xec668 cmp r6, r1
 *   @0xec66c bgt 0xec62c <_ZN13VMWriteBuffer7ReserveEi+0x28>
 *   @0xec670 pop {r4, r5, r6, pc}
 *
 * ══ §249/251 anon_fb34c  0xfb34c  size 112  28 条（0xfb34c..0xfb3bc）
 * @func 0xfb34c 0xfb3bc  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65e0×2 / anon_fae18 / MemoryManager::Free(void const*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfb34c push {r4, r5, r6, r7, r8, lr}
 *   @0xfb350 mov r4, r0
 *   @0xfb354 bl 0xfae18 <_Z15F_DsQueueCreateR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0xfb358 add r6, r4, #80
 *   @0xfb35c mov r8, r0
 *   @0xfb360 mov r5, r0
 *   @0xfb364 mov r1, r4
 *   @0xfb368 mov r0, r5
 *   @0xfb36c mov r2, #8
 *   @0xfb370 bl 0xb65e0 <strncmp@plt>
 *   @0xfb374 add r1, r4, #8
 *   @0xfb378 mov r2, #8
 *   @0xfb37c add r4, r4, #16
 *   @0xfb380 subs r7, r0, #0
 *   @0xfb384 add r0, r5, r2
 *   @0xfb388 add r5, r5, #16
 *   @0xfb38c bne 0xfb3b8 <_Z17F_DsMapSecureSaveR6RValueP9CInstanceS2_iPS_+0x1f8>
 *   @0xfb390 bl 0xb65e0 <strncmp@plt>
 *   @0xfb394 cmp r0, #0
 *   @0xfb398 bne 0xfb3a8 <_Z17F_DsMapSecureSaveR6RValueP9CInstanceS2_iPS_+0x1e8>
 *   @0xfb39c cmp r4, r6
 *   @0xfb3a0 bne 0xfb364 <_Z17F_DsMapSecureSaveR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0xfb3a4 mov r7, #1
 *   @0xfb3a8 mov r0, r8
 *   @0xfb3ac bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xfb3b0 mov r0, r7
 *   @0xfb3b4 pop {r4, r5, r6, r7, r8, pc}
 *   @0xfb3b8 mov r7, #0
 *
 * ══ §250/251 F_MpGridClearRectangle(RValue&, CInstance*, CInstance*, int, RValue*)  0x108ce8  size 112  28 条（0x108ce8..0x108d58）
 * @func 0x108ce8 0x108d58  size 112  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×5
 * 字段偏移 top8: 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x108ce8 push {r4, r5, r6, r7, r8, lr}
 *   @0x108cec mov r1, #0
 *   @0x108cf0 ldr r4, [sp, #0x18]
 *   @0x108cf4 mov r0, r4
 *   @0x108cf8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x108cfc mov r1, #1
 *   @0x108d00 mov r5, r0
 *   @0x108d04 mov r0, r4
 *   @0x108d08 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x108d0c mov r1, #2
 *   @0x108d10 mov r8, r0
 *   @0x108d14 mov r0, r4
 *   @0x108d18 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x108d1c mov r1, #3
 *   @0x108d20 mov r7, r0
 *   @0x108d24 mov r0, r4
 *   @0x108d28 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x108d2c mov r1, #4
 *   @0x108d30 mov r6, r0
 *   @0x108d34 mov r0, r4
 *   @0x108d38 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x108d3c mov r1, r8
 *   @0x108d40 mov r2, r7
 *   @0x108d44 mov r3, r6
 *   @0x108d48 str r0, [sp, #0x18]
 *   @0x108d4c mov r0, r5
 *   @0x108d50 pop {r4, r5, r6, r7, r8, lr}
 *   @0x108d54 b 0x19a2e0 <_Z26Motion_Grid_ClearRectangleiiiii>
 *
 * ══ §251/251 CBackground::DrawSimple(float, float)  0xc1fb4  size 28  7 条（0xc1fb4..0xc1fd0）
 * @func 0xc1fb4 0xc1fd0  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc1fb4 ldr r3, [r0, #0x14]
 *   @0xc1fb8 cmp r3, #0
 *   @0xc1fbc beq 0xc1fc8 <_ZN11CBackground10DrawSimpleEff+0x14>
 *   @0xc1fc0 mov r0, r3
 *   @0xc1fc4 b 0x174868 <_Z22GR_Texture_Draw_SimpleP12YYTPageEntryff>
 *   @0xc1fc8 ldr r0, [r0, #0xc]
 *   @0xc1fcc b 0x174498 <_Z22GR_Texture_Draw_Simpleiff>
 */
