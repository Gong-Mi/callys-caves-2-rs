/* cally 逆向卡：All_55 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 156 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/156 F_BUFFER_Load_Partial(RValue&, CInstance*, CInstance*, int, RValue*)  0xc5cc4  size 200  50 条（0xc5cc4..0xc5d8c）
 * @func 0xc5cc4 0xc5d8c  size 200  50 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×4 / F_BUFFER_Load_Partial(RValue&, CInstance*, CInstance*, int, RValue*)+0xa8 / YYGetString(RValue const*, int)
 * 字段偏移 top8: 0x28×1 / 0x98×1 / 0x4×1 / 0x2×1 / 0x20×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc5cc4 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0xc5cc8 sub sp, sp, #12
 *   @0xc5ccc mov r1, #0
 *   @0xc5cd0 ldr r4, [sp, #0x28]
 *   @0xc5cd4 mov r0, r4
 *   @0xc5cd8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc5cdc cmp r0, #0
 *   @0xc5ce0 blt 0xc5d6c <_Z21F_BUFFER_Load_PartialR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0xc5ce4 ldr r3, [pc, #0x98]
 *   @0xc5ce8 add r3, pc, r3
 *   @0xc5cec ldr r2, [r3]
 *   @0xc5cf0 cmp r0, r2
 *   @0xc5cf4 bge 0xc5d6c <_Z21F_BUFFER_Load_PartialR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0xc5cf8 ldr r3, [r3, #0x4]
 *   @0xc5cfc ldr r5, [r3, r0, lsl #2]
 *   @0xc5d00 cmp r5, #0
 *   @0xc5d04 beq 0xc5d6c <_Z21F_BUFFER_Load_PartialR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0xc5d08 ldr r3, [r5]
 *   @0xc5d0c mov r0, r4
 *   @0xc5d10 mov r1, #1
 *   @0xc5d14 ldr r6, [r3, #0x20]
 *   @0xc5d18 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0xc5d1c mov r1, #2
 *   @0xc5d20 mov r9, r0
 *   @0xc5d24 mov r0, r4
 *   @0xc5d28 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc5d2c mov r1, #3
 *   @0xc5d30 mov r8, r0
 *   @0xc5d34 mov r0, r4
 *   @0xc5d38 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc5d3c mov r1, #4
 *   @0xc5d40 mov r7, r0
 *   @0xc5d44 mov r0, r4
 *   @0xc5d48 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc5d4c mov r1, r9
 *   @0xc5d50 mov r2, r8
 *   @0xc5d54 mov r3, r7
 *   @0xc5d58 str r0, [sp]
 *   @0xc5d5c mov r0, r5
 *   @0xc5d60 blx r6
 *   @0xc5d64 add sp, sp, #12
 *   @0xc5d68 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0xc5d6c ldr r0, [pc, #0x14]
 *   @0xc5d70 mov r1, #0
 *   @0xc5d74 add r0, pc, r0
 *   @0xc5d78 add sp, sp, #12
 *   @0xc5d7c pop {r4, r5, r6, r7, r8, r9, lr}
 *   @0xc5d80 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc5d84 eorseq r4, r11, r12, lsr #8
 *   @0xc5d88 eoreq r10, r6, r0, asr #28
 *
 * ══ §2/156 F_DsMapCopy(RValue&, CInstance*, CInstance*, int, RValue*)  0xfedd8  size 200  50 条（0xfedd8..0xfeea0）
 * @func 0xfedd8 0xfeea0  size 200  50 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / F_DsMapCopy(RValue&, CInstance*, CInstance*, int, RValue*)+0x78×2 / DS_AutoMutex::~DS_AutoMutex()×2 / DS_AutoMutex::DS_AutoMutex() / F_DsMapCopy(RValue&, CInstance*, CInstance*, int, RValue*)+0x98 / Error_Show_Action(char const*, bool) / CDS_Map::Assign(CDS_Map*)
 * 字段偏移 top8: 0x2×3 / 0x4×2 / 0x20×1 / 0x88×1 / 0x78×1 / 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfedd8 push {r4, r5, r6, r7, r8, lr}
 *   @0xfeddc sub sp, sp, #8
 *   @0xfede0 add r5, sp, #4
 *   @0xfede4 ldr r7, [sp, #0x20]
 *   @0xfede8 mov r0, r5
 *   @0xfedec bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0xfedf0 mov r1, #0
 *   @0xfedf4 mov r0, r7
 *   @0xfedf8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfedfc subs r6, r0, #0
 *   @0xfee00 blt 0xfee50 <_Z11F_DsMapCopyR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0xfee04 ldr r4, [pc, #0x88]
 *   @0xfee08 ldr r4, [pc, r4]
 *   @0xfee0c ldr r3, [r4]
 *   @0xfee10 cmp r6, r3
 *   @0xfee14 bge 0xfee50 <_Z11F_DsMapCopyR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0xfee18 ldr r8, [pc, #0x78]
 *   @0xfee1c ldr r8, [pc, r8]
 *   @0xfee20 ldr r3, [r8, #0x4]
 *   @0xfee24 ldr r3, [r3, r6, lsl #2]
 *   @0xfee28 cmp r3, #0
 *   @0xfee2c beq 0xfee50 <_Z11F_DsMapCopyR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0xfee30 mov r0, r7
 *   @0xfee34 mov r1, #1
 *   @0xfee38 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfee3c cmp r0, #0
 *   @0xfee40 blt 0xfee50 <_Z11F_DsMapCopyR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0xfee44 ldr r3, [r4]
 *   @0xfee48 cmp r0, r3
 *   @0xfee4c blt 0xfee70 <_Z11F_DsMapCopyR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0xfee50 ldr r0, [pc, #0x44]
 *   @0xfee54 mov r1, #0
 *   @0xfee58 add r0, pc, r0
 *   @0xfee5c bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfee60 mov r0, r5
 *   @0xfee64 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xfee68 add sp, sp, #8
 *   @0xfee6c pop {r4, r5, r6, r7, r8, pc}
 *   @0xfee70 ldr r3, [r8, #0x4]
 *   @0xfee74 ldr r1, [r3, r0, lsl #2]
 *   @0xfee78 cmp r1, #0
 *   @0xfee7c beq 0xfee50 <_Z11F_DsMapCopyR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0xfee80 ldr r0, [r3, r6, lsl #2]
 *   @0xfee84 bl 0x20c87c <_ZN7CDS_Map6AssignEPS_>
 *   @0xfee88 mov r0, r5
 *   @0xfee8c bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xfee90 b 0xfee68 <_Z11F_DsMapCopyR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0xfee94 eoreq lr, lr, r0, ror lr
 *   @0xfee98 eoreq lr, lr, r0, lsr #22
 *   @0xfee9c eoreq r8, r3, r4, lsr #27
 *
 * ══ §3/156 F_DsMapAdd(RValue&, CInstance*, CInstance*, int, RValue*)  0xff014  size 200  50 条（0xff014..0xff0dc）
 * @func 0xff014 0xff0dc  size 200  50 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DS_AutoMutex::~DS_AutoMutex()×2 / DS_AutoMutex::DS_AutoMutex() / YYGetInt32(RValue const*, int) / F_DsMapAdd(RValue&, CInstance*, CInstance*, int, RValue*)+0x9c / CDS_Map::Add(RValue*, RValue*) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x20×2 / 0x4×2 / 0xc×1 / 0x74×1 / 0x64×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xff014 push {r4, r5, r6, r7, lr}
 *   @0xff018 sub sp, sp, #12
 *   @0xff01c add r6, sp, #4
 *   @0xff020 mov r5, r0
 *   @0xff024 ldr r7, [sp, #0x20]
 *   @0xff028 mov r4, #0
 *   @0xff02c mov r0, r6
 *   @0xff030 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0xff034 str r4, [r5, #0xc]
 *   @0xff038 str r4, [r5]
 *   @0xff03c mov r0, r7
 *   @0xff040 str r4, [r5, #0x4]
 *   @0xff044 mov r1, r4
 *   @0xff048 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xff04c cmp r0, #0
 *   @0xff050 blt 0xff0b0 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0xff054 ldr r3, [pc, #0x74]
 *   @0xff058 ldr r3, [pc, r3]
 *   @0xff05c ldr r3, [r3]
 *   @0xff060 cmp r0, r3
 *   @0xff064 bge 0xff0b0 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0xff068 ldr r3, [pc, #0x64]
 *   @0xff06c ldr r3, [pc, r3]
 *   @0xff070 ldr r3, [r3, #0x4]
 *   @0xff074 ldr r0, [r3, r0, lsl #2]
 *   @0xff078 cmp r0, r4
 *   @0xff07c beq 0xff0b0 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0xff080 add r1, r7, #16
 *   @0xff084 add r2, r7, #32
 *   @0xff088 bl 0x20b884 <_ZN7CDS_Map3AddEP6RValueS1_>
 *   @0xff08c cmp r0, #0
 *   @0xff090 mov r0, r6
 *   @0xff094 strne r4, [r5]
 *   @0xff098 movne r3, #0
 *   @0xff09c movtne r3, #0x3ff0
 *   @0xff0a0 strne r3, [r5, #0x4]
 *   @0xff0a4 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xff0a8 add sp, sp, #12
 *   @0xff0ac pop {r4, r5, r6, r7, pc}
 *   @0xff0b0 ldr r0, [pc, #0x20]
 *   @0xff0b4 mov r1, #0
 *   @0xff0b8 add r0, pc, r0
 *   @0xff0bc bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xff0c0 mov r0, r6
 *   @0xff0c4 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xff0c8 add sp, sp, #12
 *   @0xff0cc pop {r4, r5, r6, r7, pc}
 *   @0xff0d0 eoreq lr, lr, r0, lsr #24
 *   @0xff0d4 .word 0x002ee8d0
 *   @0xff0d8 eoreq r8, r3, r4, asr #22
 *
 * ══ §4/156 F_DotProduct_Normalised(RValue&, CInstance*, CInstance*, int, RValue*)  0x10f154  size 200  50 条（0x10f154..0x10f21c）
 * @func 0x10f154 0x10f21c  size 200  50 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4 / 0xb6700×2
 * 字段偏移 top8: 0x28×1 / 0xc×1
 * VFP 指令 26 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10f154 push {r3, r4, r5, lr}
 *   @0x10f158 vpush {d8, d9, d10}
 *   @0x10f15c mov r1, #0
 *   @0x10f160 ldr r4, [sp, #0x28]
 *   @0x10f164 mov r5, r0
 *   @0x10f168 str r1, [r0, #0xc]
 *   @0x10f16c mov r0, r4
 *   @0x10f170 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10f174 mov r1, #1
 *   @0x10f178 vmov s18, r0
 *   @0x10f17c mov r0, r4
 *   @0x10f180 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10f184 mov r1, #2
 *   @0x10f188 vmov s20, r0
 *   @0x10f18c mov r0, r4
 *   @0x10f190 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10f194 mov r1, #3
 *   @0x10f198 vmov s17, r0
 *   @0x10f19c mov r0, r4
 *   @0x10f1a0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10f1a4 vmul.f32 s14, s20, s20
 *   @0x10f1a8 vmla.f32 s14, s18, s18
 *   @0x10f1ac vmov s19, r0
 *   @0x10f1b0 vsqrt.f32 s16, s14
 *   @0x10f1b4 vcmp.f32 s16, s16
 *   @0x10f1b8 vmrs APSR_nzcv, fpscr
 *   @0x10f1bc bne 0x10f1fc <_Z23F_DotProduct_NormalisedR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x10f1c0 vmul.f32 s14, s19, s19
 *   @0x10f1c4 vmla.f32 s14, s17, s17
 *   @0x10f1c8 vsqrt.f32 s15, s14
 *   @0x10f1cc vcmp.f32 s15, s15
 *   @0x10f1d0 vmrs APSR_nzcv, fpscr
 *   @0x10f1d4 bne 0x10f20c <_Z23F_DotProduct_NormalisedR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x10f1d8 vmul.f32 s19, s20, s19
 *   @0x10f1dc vmla.f32 s19, s18, s17
 *   @0x10f1e0 vmul.f32 s16, s16, s15
 *   @0x10f1e4 vdiv.f32 s19, s19, s16
 *   @0x10f1e8 vcvt.f64.f32 d7, s19
 *   @0x10f1ec vmov r2, r3, d7
 *   @0x10f1f0 stm r5, {r2, r3}
 *   @0x10f1f4 vpop {d8, d9, d10}
 *   @0x10f1f8 pop {r3, r4, r5, pc}
 *   @0x10f1fc vmov r0, s14
 *   @0x10f200 bl 0xb6700 <sqrtf@plt>
 *   @0x10f204 vmov s16, r0
 *   @0x10f208 b 0x10f1c0 <_Z23F_DotProduct_NormalisedR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x10f20c vmov r0, s14
 *   @0x10f210 bl 0xb6700 <sqrtf@plt>
 *   @0x10f214 vmov s15, r0
 *   @0x10f218 b 0x10f1d8 <_Z23F_DotProduct_NormalisedR6RValueP9CInstanceS2_iPS_+0x84>
 *
 * ══ §5/156 F_VariableInstanceSet(RValue&, CInstance*, CInstance*, int, RValue*)  0x116ab0  size 200  50 条（0x116ab0..0x116b78）
 * @func 0x116ab0 0x116b78  size 200  50 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetString(RValue const*, int) / Variable_BuiltIn_Find(char const*) / F_VariableInstanceSet(RValue&, CInstance*, CInstance*, int, RValue*)+0xa8 / Code_Variable_FindAlloc_Slot_From_Name(YYObjectBase*, char const*)
 * 字段偏移 top8: 0x8×2 / 0x10×1 / 0x8c×1 / 0x3×1 / 0x4×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x116ab0 push {r4, r5, r6, lr}
 *   @0x116ab4 mov r1, #0
 *   @0x116ab8 ldr r5, [sp, #0x10]
 *   @0x116abc mov r0, r5
 *   @0x116ac0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x116ac4 mov r1, #1
 *   @0x116ac8 mov r4, r0
 *   @0x116acc mov r0, r5
 *   @0x116ad0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x116ad4 cmp r4, #0
 *   @0x116ad8 mov r6, r0
 *   @0x116adc poplt {r4, r5, r6, pc}
 *   @0x116ae0 ldr r2, [pc, #0x8c]
 *   @0x116ae4 ldr r2, [pc, r2]
 *   @0x116ae8 ldm r2, {r3, r12}
 *   @0x116aec and r2, r4, r12
 *   @0x116af0 ldr r2, [r3, r2, lsl #3]
 *   @0x116af4 cmp r2, #0
 *   @0x116af8 popeq {r4, r5, r6, pc}
 *   @0x116afc ldr r3, [r2, #0x8]
 *   @0x116b00 cmp r4, r3
 *   @0x116b04 bne 0x116b18 <_Z21F_VariableInstanceSetR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x116b08 b 0x116b28 <_Z21F_VariableInstanceSetR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x116b0c ldr r12, [r2, #0x8]
 *   @0x116b10 cmp r4, r12
 *   @0x116b14 beq 0x116b28 <_Z21F_VariableInstanceSetR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x116b18 ldr r2, [r2, #0x4]
 *   @0x116b1c cmp r2, #0
 *   @0x116b20 bne 0x116b0c <_Z21F_VariableInstanceSetR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x116b24 pop {r4, r5, r6, pc}
 *   @0x116b28 ldr r4, [r2, #0xc]
 *   @0x116b2c cmp r4, #0
 *   @0x116b30 popeq {r4, r5, r6, pc}
 *   @0x116b34 mov r0, r6
 *   @0x116b38 bl 0x1f3a5c <_Z21Variable_BuiltIn_FindPKc>
 *   @0x116b3c subs r1, r0, #0
 *   @0x116b40 blt 0x116b58 <_Z21F_VariableInstanceSetR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x116b44 mov r0, r4
 *   @0x116b48 add r3, r5, #32
 *   @0x116b4c mov r2, #-2147483648
 *   @0x116b50 pop {r4, r5, r6, lr}
 *   @0x116b54 b 0x1f3c28 <_Z24Variable_SetValue_DirectP12YYObjectBaseiiP6RValue>
 *   @0x116b58 mov r1, r6
 *   @0x116b5c mov r0, r4
 *   @0x116b60 bl 0xd2c84 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc>
 *   @0x116b64 subs r1, r0, #0
 *   @0x116b68 addge r1, r1, #99328
 *   @0x116b6c addge r1, r1, #672
 *   @0x116b70 b 0x116b44 <_Z21F_VariableInstanceSetR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x116b74 eoreq r7, sp, r0, ror #2
 *
 * ══ §6/156 F_DrawTextExtTransformed(RValue&, CInstance*, CInstance*, int, RValue*)  0x121f10  size 200  50 条（0x121f10..0x121fd8）
 * @func 0x121f10 0x121fd8  size 200  50 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×5 / YYGetInt32(RValue const*, int)×2 / GetTextFromArg(RValue const*, int, char**) / GR_Text_Draw_Transformed(float, float, char const*, int, int, float, float, float) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x14×2 / 0x40×1 / 0x-4×1 / 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x121f10 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x121f14 sub sp, sp, #28
 *   @0x121f18 add r2, sp, #24
 *   @0x121f1c mov r5, #0
 *   @0x121f20 ldr r4, [sp, #0x40]
 *   @0x121f24 mov r1, #1024
 *   @0x121f28 str r5, [r2, #-0x4]!
 *   @0x121f2c add r0, r4, #32
 *   @0x121f30 bl 0x121ce0 <_Z14GetTextFromArgPK6RValueiPPc>
 *   @0x121f34 mov r1, r5
 *   @0x121f38 mov r0, r4
 *   @0x121f3c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x121f40 mov r1, #1
 *   @0x121f44 mov r5, r0
 *   @0x121f48 mov r0, r4
 *   @0x121f4c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x121f50 mov r1, #3
 *   @0x121f54 ldr r7, [sp, #0x14]
 *   @0x121f58 mov r8, r0
 *   @0x121f5c mov r0, r4
 *   @0x121f60 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x121f64 mov r1, #4
 *   @0x121f68 mov r6, r0
 *   @0x121f6c mov r0, r4
 *   @0x121f70 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x121f74 mov r1, #5
 *   @0x121f78 mov r11, r0
 *   @0x121f7c mov r0, r4
 *   @0x121f80 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x121f84 mov r1, #6
 *   @0x121f88 mov r10, r0
 *   @0x121f8c mov r0, r4
 *   @0x121f90 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x121f94 mov r1, #7
 *   @0x121f98 mov r9, r0
 *   @0x121f9c mov r0, r4
 *   @0x121fa0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x121fa4 mov r1, r8
 *   @0x121fa8 mov r2, r7
 *   @0x121fac mov r3, r6
 *   @0x121fb0 str r11, [sp]
 *   @0x121fb4 str r10, [sp, #0x4]
 *   @0x121fb8 str r9, [sp, #0x8]
 *   @0x121fbc str r0, [sp, #0xc]
 *   @0x121fc0 mov r0, r5
 *   @0x121fc4 bl 0x173068 <_Z24GR_Text_Draw_TransformedffPKciifff>
 *   @0x121fc8 ldr r0, [sp, #0x14]
 *   @0x121fcc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x121fd0 add sp, sp, #28
 *   @0x121fd4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §7/156 F_DrawSpriteStretchedExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x122dc8  size 200  50 条（0x122dc8..0x122e90）
 * @func 0x122dc8 0x122e90  size 200  50 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×5 / GetSpriteIndices(CInstance*, RValue*, int&, int&) / Sprite_Data(int) / YYGetInt32(RValue const*, int) / CSprite::DrawStretched(int, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0x40×1 / 0x10×1 / 0x14×1 / 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x122dc8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x122dcc sub sp, sp, #28
 *   @0x122dd0 mov r0, r1
 *   @0x122dd4 add r2, sp, #16
 *   @0x122dd8 ldr r4, [sp, #0x40]
 *   @0x122ddc add r3, sp, #20
 *   @0x122de0 mov r1, r4
 *   @0x122de4 bl 0x1226c4 <_Z16GetSpriteIndicesP9CInstanceP6RValueRiS3_>
 *   @0x122de8 cmp r0, #0
 *   @0x122dec bne 0x122df8 <_Z24F_DrawSpriteStretchedExtR6RValueP9CInstanceS2_iPS_+0x30>
 *   @0x122df0 add sp, sp, #28
 *   @0x122df4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x122df8 ldr r0, [sp, #0x10]
 *   @0x122dfc bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x122e00 mov r1, #2
 *   @0x122e04 ldr r8, [sp, #0x14]
 *   @0x122e08 mov r5, r0
 *   @0x122e0c mov r0, r4
 *   @0x122e10 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122e14 mov r1, #3
 *   @0x122e18 mov r7, r0
 *   @0x122e1c mov r0, r4
 *   @0x122e20 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122e24 mov r1, #4
 *   @0x122e28 mov r6, r0
 *   @0x122e2c mov r0, r4
 *   @0x122e30 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122e34 mov r1, #5
 *   @0x122e38 mov r11, r0
 *   @0x122e3c mov r0, r4
 *   @0x122e40 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122e44 mov r1, #6
 *   @0x122e48 mov r10, r0
 *   @0x122e4c mov r0, r4
 *   @0x122e50 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x122e54 mov r1, #7
 *   @0x122e58 mov r9, r0
 *   @0x122e5c mov r0, r4
 *   @0x122e60 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122e64 str r11, [sp]
 *   @0x122e68 str r10, [sp, #0x4]
 *   @0x122e6c mov r1, r8
 *   @0x122e70 str r9, [sp, #0x8]
 *   @0x122e74 mov r2, r7
 *   @0x122e78 mov r3, r6
 *   @0x122e7c str r0, [sp, #0xc]
 *   @0x122e80 mov r0, r5
 *   @0x122e84 bl 0x1ecdc4 <_ZN7CSprite13DrawStretchedEiffffjf>
 *   @0x122e88 add sp, sp, #28
 *   @0x122e8c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §8/156 F_BackgroundPrefetch(RValue&, CInstance*, CInstance*, int, RValue*)  0x12ef2c  size 200  50 条（0x12ef2c..0x12eff4）
 * @func 0x12ef2c 0x12eff4  size 200  50 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::PrefetchTexture(void*)×2 / YYGetInt32(RValue const*, int) / Background_Data(int) / CBackground::GetTexture()
 * 字段偏移 top8: 0x4×3 / 0xc×2 / 0x2×2 / 0x10×1 / 0x7c×1 / 0x24×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12ef2c push {r3, r4, r5, lr}
 *   @0x12ef30 mov r1, #0
 *   @0x12ef34 mov r3, r1
 *   @0x12ef38 str r1, [r0, #0xc]
 *   @0x12ef3c movt r3, #0xbff0
 *   @0x12ef40 mov r4, r0
 *   @0x12ef44 stm r0, {r1, r3}
 *   @0x12ef48 ldr r0, [sp, #0x10]
 *   @0x12ef4c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12ef50 mov r5, r0
 *   @0x12ef54 bl 0xc3794 <_Z15Background_Datai>
 *   @0x12ef58 cmp r0, #0
 *   @0x12ef5c beq 0x12efc0 <_Z20F_BackgroundPrefetchR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x12ef60 bl 0xc1e8c <_ZN11CBackground10GetTextureEv>
 *   @0x12ef64 ldr r3, [pc, #0x7c]
 *   @0x12ef68 ldr r3, [pc, r3]
 *   @0x12ef6c ldr r2, [r3]
 *   @0x12ef70 cmp r0, r2
 *   @0x12ef74 bhi 0x12efa0 <_Z20F_BackgroundPrefetchR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x12ef78 ldr r3, [r3, #0x4]
 *   @0x12ef7c ldr r3, [r3, r0, lsl #2]
 *   @0x12ef80 cmp r3, #0
 *   @0x12ef84 beq 0x12ef90 <_Z20F_BackgroundPrefetchR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x12ef88 ldr r0, [r3]
 *   @0x12ef8c bl 0x182f04 <_ZN8Graphics15PrefetchTextureEPv>
 *   @0x12ef90 mov r3, #0
 *   @0x12ef94 str r3, [r4]
 *   @0x12ef98 str r3, [r4, #0x4]
 *   @0x12ef9c pop {r3, r4, r5, pc}
 *   @0x12efa0 cmn r0, #1
 *   @0x12efa4 beq 0x12ef78 <_Z20F_BackgroundPrefetchR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x12efa8 ldrsh r2, [r0, #20]
 *   @0x12efac ldr r3, [r3, #0x4]
 *   @0x12efb0 ldr r3, [r3, r2, lsl #2]
 *   @0x12efb4 ldr r0, [r3]
 *   @0x12efb8 bl 0x182f04 <_ZN8Graphics15PrefetchTextureEPv>
 *   @0x12efbc b 0x12ef90 <_Z20F_BackgroundPrefetchR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x12efc0 ldr r3, [pc, #0x24]
 *   @0x12efc4 mov r2, r5
 *   @0x12efc8 ldr r1, [pc, #0x20]
 *   @0x12efcc ldr r3, [pc, r3]
 *   @0x12efd0 add r1, pc, r1
 *   @0x12efd4 ldr r0, [r3]
 *   @0x12efd8 ldr r3, [r0]
 *   @0x12efdc ldr r3, [r3, #0xc]
 *   @0x12efe0 blx r3
 *   @0x12efe4 b 0x12ef90 <_Z20F_BackgroundPrefetchR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x12efe8 .word 0x002be9b4
 *   @0x12efec eoreq lr, r11, r8, asr #14
 *   @0x12eff0 eoreq lr, r0, r12, lsr #14
 *
 * ══ §9/156 F_AudioSetListenerOrientation(RValue&, CInstance*, CInstance*, int, RValue*)  0x134804  size 200  50 条（0x134804..0x1348cc）
 * @func 0x134804 0x1348cc  size 200  50 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×6 / Audio_SetListenerOrientation(int, double, double, double, double, double, double)
 * 字段偏移 top8: 0x2c×2 / 0x28×2 / 0xbc×1 / 0x60×1
 * VFP 指令 2 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x134804 ldr r3, [pc, #0xbc]
 *   @0x134808 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x13480c ldr r3, [pc, r3]
 *   @0x134810 sub sp, sp, #60
 *   @0x134814 ldrb r11, [r3]
 *   @0x134818 ldr r10, [sp, #0x60]
 *   @0x13481c cmp r11, #0
 *   @0x134820 bne 0x1348c0 <_Z29F_AudioSetListenerOrientationR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x134824 mov r0, r10
 *   @0x134828 mov r1, r11
 *   @0x13482c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134830 mov r2, r0
 *   @0x134834 mov r3, r1
 *   @0x134838 mov r0, r10
 *   @0x13483c mov r1, #1
 *   @0x134840 str r2, [sp, #0x2c]
 *   @0x134844 str r3, [sp, #0x28]
 *   @0x134848 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x13484c mov r8, r0
 *   @0x134850 mov r9, r1
 *   @0x134854 mov r0, r10
 *   @0x134858 mov r1, #2
 *   @0x13485c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134860 mov r6, r0
 *   @0x134864 mov r7, r1
 *   @0x134868 mov r0, r10
 *   @0x13486c mov r1, #3
 *   @0x134870 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134874 mov r4, r0
 *   @0x134878 mov r5, r1
 *   @0x13487c mov r0, r10
 *   @0x134880 mov r1, #4
 *   @0x134884 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134888 strd r0, r1, [sp, #48]
 *   @0x13488c mov r0, r10
 *   @0x134890 mov r1, #5
 *   @0x134894 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134898 vldr d7, [sp, #48]
 *   @0x13489c strd r8, r9, [sp]
 *   @0x1348a0 vstr d7, [sp, #24]
 *   @0x1348a4 strd r6, r7, [sp, #8]
 *   @0x1348a8 strd r4, r5, [sp, #16]
 *   @0x1348ac ldr r2, [sp, #0x2c]
 *   @0x1348b0 ldr r3, [sp, #0x28]
 *   @0x1348b4 strd r0, r1, [sp, #32]
 *   @0x1348b8 mov r0, r11
 *   @0x1348bc bl 0x216650 <_Z28Audio_SetListenerOrientationidddddd>
 *   @0x1348c0 add sp, sp, #60
 *   @0x1348c4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1348c8 eoreq r10, r11, r0, asr #16
 *
 * ══ §10/156 F_ActionIfScore(RValue&, CInstance*, CInstance*, int, RValue*)  0x13e878  size 200  50 条（0x13e878..0x13e940）
 * @func 0x13e878 0x13e940  size 200  50 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x13e8b4→0x54294c
 * 调用序列: YYGetReal(RValue const*, int) / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x4×3 / 0x20×1 / 0xc×1 / 0x9c×1 / 0x80×1
 * VFP 指令 13 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13e878 push {r3, r4, r5, r6, r7, lr}
 *   @0x13e87c vpush {d8}
 *   @0x13e880 mov r5, #0
 *   @0x13e884 ldr r6, [sp, #0x20]
 *   @0x13e888 mov r4, r0
 *   @0x13e88c str r5, [r0, #0xc]
 *   @0x13e890 mov r1, r5
 *   @0x13e894 ldr r7, [pc, #0x9c]
 *   @0x13e898 mov r0, r6
 *   @0x13e89c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x13e8a0 add r7, pc, r7
 *   @0x13e8a4 vmov d8, r0, r1
 *   @0x13e8a8 mov r0, r6
 *   @0x13e8ac mov r1, #1
 *   @0x13e8b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13e8b4 ldr r3, [pc, #0x80]
 *   @0x13e8b8 ldr r3, [r7, r3]
 *   @0x13e8bc vldr s14, [r3]
 *   @0x13e8c0 vcvt.f64.s32 d7, s14
 *   @0x13e8c4 cmp r0, #1
 *   @0x13e8c8 beq 0x13e918 <_Z15F_ActionIfScoreR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x13e8cc cmp r0, #2
 *   @0x13e8d0 beq 0x13e8f8 <_Z15F_ActionIfScoreR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x13e8d4 vcmp.f64 d7, d8
 *   @0x13e8d8 vmrs APSR_nzcv, fpscr
 *   @0x13e8dc bne 0x13e904 <_Z15F_ActionIfScoreR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x13e8e0 mov r3, #0
 *   @0x13e8e4 movt r3, #0x3ff0
 *   @0x13e8e8 str r5, [r4]
 *   @0x13e8ec str r3, [r4, #0x4]
 *   @0x13e8f0 vpop {d8}
 *   @0x13e8f4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x13e8f8 vcmpe.f64 d8, d7
 *   @0x13e8fc vmrs APSR_nzcv, fpscr
 *   @0x13e900 bmi 0x13e8e0 <_Z15F_ActionIfScoreR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x13e904 mov r3, r5
 *   @0x13e908 str r5, [r4]
 *   @0x13e90c str r3, [r4, #0x4]
 *   @0x13e910 vpop {d8}
 *   @0x13e914 pop {r3, r4, r5, r6, r7, pc}
 *   @0x13e918 vcmpe.f64 d8, d7
 *   @0x13e91c mov r3, r5
 *   @0x13e920 vmrs APSR_nzcv, fpscr
 *   @0x13e924 bgt 0x13e8e4 <_Z15F_ActionIfScoreR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x13e928 str r5, [r4]
 *   @0x13e92c str r3, [r4, #0x4]
 *   @0x13e930 vpop {d8}
 *   @0x13e934 pop {r3, r4, r5, r6, r7, pc}
 *   @0x13e938 .word 0x002b33b0
 *   @0x13e93c .word 0xffffce34
 *
 * ══ §11/156 F_ActionDrawEllipse(RValue&, CInstance*, CInstance*, int, RValue*)  0x140674  size 200  50 条（0x140674..0x14073c）
 * @func 0x140674 0x14073c  size 200  50 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4 / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x20×2 / 0x60×1
 * VFP 指令 21 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x140674 push {r4, r5, r6, lr}
 *   @0x140678 vpush {d8, d9}
 *   @0x14067c mov r5, r1
 *   @0x140680 ldr r4, [sp, #0x20]
 *   @0x140684 mov r1, #0
 *   @0x140688 mov r0, r4
 *   @0x14068c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x140690 mov r1, #1
 *   @0x140694 vmov s19, r0
 *   @0x140698 mov r0, r4
 *   @0x14069c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1406a0 mov r1, #2
 *   @0x1406a4 vmov s18, r0
 *   @0x1406a8 mov r0, r4
 *   @0x1406ac bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1406b0 mov r1, #3
 *   @0x1406b4 vmov s17, r0
 *   @0x1406b8 mov r0, r4
 *   @0x1406bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1406c0 mov r1, #4
 *   @0x1406c4 vmov s16, r0
 *   @0x1406c8 mov r0, r4
 *   @0x1406cc bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x1406d0 ldr r3, [pc, #0x60]
 *   @0x1406d4 ldr r3, [pc, r3]
 *   @0x1406d8 ldrb r3, [r3]
 *   @0x1406dc cmp r3, #0
 *   @0x1406e0 str r0, [sp, #0x20]
 *   @0x1406e4 bne 0x140704 <_Z19F_ActionDrawEllipseR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x1406e8 vmov r0, s19
 *   @0x1406ec vmov r1, s18
 *   @0x1406f0 vmov r2, s17
 *   @0x1406f4 vmov r3, s16
 *   @0x1406f8 vpop {d8, d9}
 *   @0x1406fc pop {r4, r5, r6, lr}
 *   @0x140700 b 0x16b278 <_Z15GR_Draw_Ellipseffffb>
 *   @0x140704 vldr s14, [r5, #180]
 *   @0x140708 vldr s15, [r5, #184]
 *   @0x14070c vadd.f32 s19, s19, s14
 *   @0x140710 vadd.f32 s18, s18, s15
 *   @0x140714 vmov r0, s19
 *   @0x140718 vadd.f32 s14, s17, s14
 *   @0x14071c vmov r1, s18
 *   @0x140720 vadd.f32 s15, s16, s15
 *   @0x140724 vpop {d8, d9}
 *   @0x140728 vmov r2, s14
 *   @0x14072c pop {r4, r5, r6, lr}
 *   @0x140730 vmov r3, s15
 *   @0x140734 b 0x16b278 <_Z15GR_Draw_Ellipseffffb>
 *   @0x140738 eoreq sp, r10, r8, ror #8
 *
 * ══ §12/156 F_ActionDrawArrow(RValue&, CInstance*, CInstance*, int, RValue*)  0x1408e8  size 200  50 条（0x1408e8..0x1409b0）
 * @func 0x1408e8 0x1409b0  size 200  50 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×5
 * 字段偏移 top8: 0x20×2 / 0x60×1
 * VFP 指令 21 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1408e8 push {r4, r5, r6, lr}
 *   @0x1408ec vpush {d8, d9}
 *   @0x1408f0 mov r5, r1
 *   @0x1408f4 ldr r4, [sp, #0x20]
 *   @0x1408f8 mov r1, #0
 *   @0x1408fc mov r0, r4
 *   @0x140900 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x140904 mov r1, #1
 *   @0x140908 vmov s19, r0
 *   @0x14090c mov r0, r4
 *   @0x140910 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x140914 mov r1, #2
 *   @0x140918 vmov s18, r0
 *   @0x14091c mov r0, r4
 *   @0x140920 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x140924 mov r1, #3
 *   @0x140928 vmov s17, r0
 *   @0x14092c mov r0, r4
 *   @0x140930 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x140934 mov r1, #4
 *   @0x140938 vmov s16, r0
 *   @0x14093c mov r0, r4
 *   @0x140940 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x140944 ldr r3, [pc, #0x60]
 *   @0x140948 ldr r3, [pc, r3]
 *   @0x14094c ldrb r3, [r3]
 *   @0x140950 cmp r3, #0
 *   @0x140954 str r0, [sp, #0x20]
 *   @0x140958 bne 0x140978 <_Z17F_ActionDrawArrowR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x14095c vmov r0, s19
 *   @0x140960 vmov r1, s18
 *   @0x140964 vmov r2, s17
 *   @0x140968 vmov r3, s16
 *   @0x14096c vpop {d8, d9}
 *   @0x140970 pop {r4, r5, r6, lr}
 *   @0x140974 b 0x16bee4 <_Z13GR_Draw_Arrowfffff>
 *   @0x140978 vldr s14, [r5, #180]
 *   @0x14097c vldr s15, [r5, #184]
 *   @0x140980 vadd.f32 s19, s19, s14
 *   @0x140984 vadd.f32 s18, s18, s15
 *   @0x140988 vmov r0, s19
 *   @0x14098c vadd.f32 s14, s17, s14
 *   @0x140990 vmov r1, s18
 *   @0x140994 vadd.f32 s15, s16, s15
 *   @0x140998 vpop {d8, d9}
 *   @0x14099c vmov r2, s14
 *   @0x1409a0 pop {r4, r5, r6, lr}
 *   @0x1409a4 vmov r3, s15
 *   @0x1409a8 b 0x16bee4 <_Z13GR_Draw_Arrowfffff>
 *   @0x1409ac .word 0x002ad1f4
 *
 * ══ §13/156 F_PhysicsParticleDataParticle(RValue&, CInstance*, CInstance*, int, RValue*)  0x14df84  size 200  50 条（0x14df84..0x14e04c）
 * @func 0x14df84 0x14e04c  size 200  50 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / GetIBuffer(int) / YYGetUint32(RValue const*, int)
 * 字段偏移 top8: 0xb4×2 / 0xac×1 / 0xc×1 / 0x4×1 / 0x18×1 / 0x24×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14df84 push {r4, r5, r6, r7, r8, lr}
 *   @0x14df88 mov r5, #0
 *   @0x14df8c ldr r4, [pc, #0xac]
 *   @0x14df90 mov r3, r5
 *   @0x14df94 str r5, [r0]
 *   @0x14df98 movt r3, #0xbff0
 *   @0x14df9c ldr r4, [pc, r4]
 *   @0x14dfa0 str r5, [r0, #0xc]
 *   @0x14dfa4 str r3, [r0, #0x4]
 *   @0x14dfa8 ldr r2, [r4]
 *   @0x14dfac ldr r6, [sp, #0x18]
 *   @0x14dfb0 cmp r2, r5
 *   @0x14dfb4 beq 0x14e018 <_Z29F_PhysicsParticleDataParticleR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x14dfb8 ldr r3, [r2, #0xb4]
 *   @0x14dfbc cmp r3, r5
 *   @0x14dfc0 beq 0x14e018 <_Z29F_PhysicsParticleDataParticleR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x14dfc4 mov r1, #1
 *   @0x14dfc8 mov r0, r6
 *   @0x14dfcc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14dfd0 bl 0xc6720 <_Z10GetIBufferi>
 *   @0x14dfd4 subs r7, r0, #0
 *   @0x14dfd8 beq 0x14e02c <_Z29F_PhysicsParticleDataParticleR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x14dfdc ldr r3, [r4]
 *   @0x14dfe0 mov r1, r5
 *   @0x14dfe4 mov r0, r6
 *   @0x14dfe8 ldr r5, [r3, #0xb4]
 *   @0x14dfec bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14dff0 mov r1, #2
 *   @0x14dff4 mov r4, r0
 *   @0x14dff8 mov r0, r6
 *   @0x14dffc bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x14e000 mov r1, r4
 *   @0x14e004 mov r2, r7
 *   @0x14e008 mov r3, r0
 *   @0x14e00c mov r0, r5
 *   @0x14e010 pop {r4, r5, r6, r7, r8, lr}
 *   @0x14e014 b 0x23a5a8 <_ZN13CPhysicsWorld23GetParticleDataParticleEiP7IBufferj>
 *   @0x14e018 ldr r0, [pc, #0x24]
 *   @0x14e01c mov r1, #0
 *   @0x14e020 pop {r4, r5, r6, r7, r8, lr}
 *   @0x14e024 add r0, pc, r0
 *   @0x14e028 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14e02c ldr r0, [pc, #0x14]
 *   @0x14e030 mov r1, r7
 *   @0x14e034 pop {r4, r5, r6, r7, r8, lr}
 *   @0x14e038 add r0, pc, r0
 *   @0x14e03c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14e040 eoreq pc, r9, r12, lsl #19
 *   @0x14e044 mulseq pc, r4, r5
 *   @0x14e048 andseq r2, lr, r12, ror r11
 *
 * ══ §14/156 F_PhysicsParticleDataGroup(RValue&, CInstance*, CInstance*, int, RValue*)  0x14e0d8  size 200  50 条（0x14e0d8..0x14e1a0）
 * @func 0x14e0d8 0x14e1a0  size 200  50 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / GetIBuffer(int) / YYGetUint32(RValue const*, int)
 * 字段偏移 top8: 0xb4×2 / 0xac×1 / 0xc×1 / 0x4×1 / 0x18×1 / 0x24×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14e0d8 push {r4, r5, r6, r7, r8, lr}
 *   @0x14e0dc mov r5, #0
 *   @0x14e0e0 ldr r4, [pc, #0xac]
 *   @0x14e0e4 mov r3, r5
 *   @0x14e0e8 str r5, [r0]
 *   @0x14e0ec movt r3, #0xbff0
 *   @0x14e0f0 ldr r4, [pc, r4]
 *   @0x14e0f4 str r5, [r0, #0xc]
 *   @0x14e0f8 str r3, [r0, #0x4]
 *   @0x14e0fc ldr r2, [r4]
 *   @0x14e100 ldr r6, [sp, #0x18]
 *   @0x14e104 cmp r2, r5
 *   @0x14e108 beq 0x14e16c <_Z26F_PhysicsParticleDataGroupR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x14e10c ldr r3, [r2, #0xb4]
 *   @0x14e110 cmp r3, r5
 *   @0x14e114 beq 0x14e16c <_Z26F_PhysicsParticleDataGroupR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x14e118 mov r1, #1
 *   @0x14e11c mov r0, r6
 *   @0x14e120 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14e124 bl 0xc6720 <_Z10GetIBufferi>
 *   @0x14e128 subs r7, r0, #0
 *   @0x14e12c beq 0x14e180 <_Z26F_PhysicsParticleDataGroupR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x14e130 ldr r3, [r4]
 *   @0x14e134 mov r1, r5
 *   @0x14e138 mov r0, r6
 *   @0x14e13c ldr r5, [r3, #0xb4]
 *   @0x14e140 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14e144 mov r1, #2
 *   @0x14e148 mov r4, r0
 *   @0x14e14c mov r0, r6
 *   @0x14e150 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x14e154 mov r1, r4
 *   @0x14e158 mov r2, r7
 *   @0x14e15c mov r3, r0
 *   @0x14e160 mov r0, r5
 *   @0x14e164 pop {r4, r5, r6, r7, r8, lr}
 *   @0x14e168 b 0x23a5f0 <_ZN13CPhysicsWorld20GetParticleDataGroupEiP7IBufferj>
 *   @0x14e16c ldr r0, [pc, #0x24]
 *   @0x14e170 mov r1, #0
 *   @0x14e174 pop {r4, r5, r6, r7, r8, lr}
 *   @0x14e178 add r0, pc, r0
 *   @0x14e17c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14e180 ldr r0, [pc, #0x14]
 *   @0x14e184 mov r1, r7
 *   @0x14e188 pop {r4, r5, r6, r7, r8, lr}
 *   @0x14e18c add r0, pc, r0
 *   @0x14e190 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14e194 eoreq pc, r9, r8, lsr r8
 *   @0x14e198 andseq r6, pc, r4, lsl #10
 *   @0x14e19c andseq r2, lr, r8, lsr #20
 *
 * ══ §15/156 C3D_Model::~C3D_Model()  0x164ff8  size 200  50 条（0x164ff8..0x1650c0）
 * @func 0x164ff8 0x1650c0  size 200  50 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / GraphicsRecorder::~GraphicsRecorder()×2 / C3D_Model::Clear() / operator delete(void*)
 * 字段偏移 top8: 0xc×2 / 0x18×1 / 0x14×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x164ff8 push {r4, r5, r6, lr}
 *   @0x164ffc mov r6, r0
 *   @0x165000 bl 0x163ce0 <_ZN9C3D_Model5ClearEv>
 *   @0x165004 ldr r3, [r6, #0x18]
 *   @0x165008 cmp r3, #0
 *   @0x16500c beq 0x165044 <_ZN9C3D_ModelD2Ev+0x4c>
 *   @0x165010 ldr r4, [r6, #0xc]
 *   @0x165014 cmp r4, #0
 *   @0x165018 beq 0x165044 <_ZN9C3D_ModelD2Ev+0x4c>
 *   @0x16501c cmp r3, #2
 *   @0x165020 beq 0x16505c <_ZN9C3D_ModelD2Ev+0x64>
 *   @0x165024 cmp r3, #3
 *   @0x165028 beq 0x165078 <_ZN9C3D_ModelD2Ev+0x80>
 *   @0x16502c cmp r3, #1
 *   @0x165030 beq 0x16509c <_ZN9C3D_ModelD2Ev+0xa4>
 *   @0x165034 ldr r5, [r4]
 *   @0x165038 cmp r5, #0
 *   @0x16503c mov r4, r5
 *   @0x165040 bne 0x165034 <_ZN9C3D_ModelD2Ev+0x3c>
 *   @0x165044 mov r3, #0
 *   @0x165048 mov r0, r6
 *   @0x16504c str r3, [r6, #0x14]
 *   @0x165050 str r3, [r6, #0x10]
 *   @0x165054 str r3, [r6, #0xc]
 *   @0x165058 pop {r4, r5, r6, pc}
 *   @0x16505c ldr r5, [r4]
 *   @0x165060 mov r0, r4
 *   @0x165064 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x165068 cmp r5, #0
 *   @0x16506c mov r4, r5
 *   @0x165070 bne 0x16505c <_ZN9C3D_ModelD2Ev+0x64>
 *   @0x165074 b 0x165044 <_ZN9C3D_ModelD2Ev+0x4c>
 *   @0x165078 ldr r5, [r4]
 *   @0x16507c mov r0, r4
 *   @0x165080 bl 0x188ca4 <_ZN16GraphicsRecorderD2Ev>
 *   @0x165084 mov r0, r4
 *   @0x165088 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x16508c cmp r5, #0
 *   @0x165090 mov r4, r5
 *   @0x165094 bne 0x165078 <_ZN9C3D_ModelD2Ev+0x80>
 *   @0x165098 b 0x165044 <_ZN9C3D_ModelD2Ev+0x4c>
 *   @0x16509c ldr r5, [r4]
 *   @0x1650a0 mov r0, r4
 *   @0x1650a4 bl 0x188ca4 <_ZN16GraphicsRecorderD2Ev>
 *   @0x1650a8 mov r0, r4
 *   @0x1650ac bl 0x27d1d0 <_ZdlPv>
 *   @0x1650b0 cmp r5, #0
 *   @0x1650b4 mov r4, r5
 *   @0x1650b8 bne 0x16509c <_ZN9C3D_ModelD2Ev+0xa4>
 *   @0x1650bc b 0x165044 <_ZN9C3D_ModelD2Ev+0x4c>
 *
 * ══ §16/156 GamepadQuitM()  0x1909f8  size 200  50 条（0x1909f8..0x190ac0）
 * @func 0x1909f8 0x190ac0  size 200  50 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x190a00→0x5356c4, 0x190a08→0x5356c0, 0x190a80→0x756d44, 0x190a84→0x756c74
 * 调用序列: GamepadQuitM()+0x64 / GMGamePad::~GMGamePad() / operator delete(void*) / GamepadQuitM()+0x34 / 0xb65b0 / GMGamePad::SetGamePadCount(int) / getJNIEnv / _JNIEnv::CallStaticVoidMethod(_jclass*, _jmethodID*, ...)
 * 字段偏移 top8: 0xa4×2 / 0x30×2 / 0xa0×1 / 0x4×1 / 0x-4×1 / 0x50×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1909f8 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x1909fc ldr r9, [pc, #0xa4]
 *   @0x190a00 ldr r2, [pc, #0xa4]
 *   @0x190a04 add r9, pc, r9
 *   @0x190a08 ldr r3, [pc, #0xa0]
 *   @0x190a0c ldr r7, [r9, r2]
 *   @0x190a10 ldr r2, [r9, r3]
 *   @0x190a14 ldr r3, [r7]
 *   @0x190a18 ldr r6, [r2]
 *   @0x190a1c cmp r3, #0
 *   @0x190a20 movgt r5, #0
 *   @0x190a24 movgt r8, r5
 *   @0x190a28 ble 0x190a5c <_Z12GamepadQuitMv+0x64>
 *   @0x190a2c ldr r4, [r6], #4
 *   @0x190a30 add r5, r5, #1
 *   @0x190a34 cmp r4, #0
 *   @0x190a38 mov r0, r4
 *   @0x190a3c beq 0x190a50 <_Z12GamepadQuitMv+0x58>
 *   @0x190a40 bl 0x18e64c <_ZN9GMGamePadD2Ev>
 *   @0x190a44 mov r0, r4
 *   @0x190a48 bl 0x27d1d0 <_ZdlPv>
 *   @0x190a4c str r8, [r6, #-0x4]
 *   @0x190a50 ldr r3, [r7]
 *   @0x190a54 cmp r5, r3
 *   @0x190a58 blt 0x190a2c <_Z12GamepadQuitMv+0x34>
 *   @0x190a5c ldr r4, [pc, #0x50]
 *   @0x190a60 mov r1, #0
 *   @0x190a64 mov r2, #5376
 *   @0x190a68 add r4, pc, r4
 *   @0x190a6c add r0, r4, #28
 *   @0x190a70 bl 0xb65b0 <memset@plt>
 *   @0x190a74 mov r0, #0
 *   @0x190a78 bl 0x18e4a4 <_ZN9GMGamePad15SetGamePadCountEi>
 *   @0x190a7c bl 0x290274 <getJNIEnv>
 *   @0x190a80 ldr r2, [pc, #0x30]
 *   @0x190a84 ldr r3, [pc, #0x30]
 *   @0x190a88 ldr r2, [r9, r2]
 *   @0x190a8c ldr r3, [r9, r3]
 *   @0x190a90 ldr r1, [r2]
 *   @0x190a94 ldr r2, [r3]
 *   @0x190a98 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x190a9c mov r3, #0
 *   @0x190aa0 str r3, [r4]
 *   @0x190aa4 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x190aa8 eoreq r1, r6, r12, asr #4
 *   @0x190aac .word 0xffffde10
 *   @0x190ab0 .word 0xffffde14
 *   @0x190ab4 eorseq r4, r10, r0, asr #27
 *   @0x190ab8 .word 0xffffbd54
 *   @0x190abc .word 0xffffea18
 *
 * ══ §17/156 Object_Find(char const*)  0x19edf4  size 200  50 条（0x19edf4..0x19eebc）
 * @func 0x19edf4 0x19eebc  size 200  50 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6574 / Object_Find(char const*)+0xb4
 * 字段偏移 top8: 0x4×3 / 0xb4×1 / 0x3×1 / 0xc×1 / 0x14×1 / 0x8×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19edf4 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x19edf8 mov r8, r0
 *   @0x19edfc ldr r3, [pc, #0xb4]
 *   @0x19ee00 mov r5, #0
 *   @0x19ee04 ldr r3, [pc, r3]
 *   @0x19ee08 ldr r9, [r3]
 *   @0x19ee0c ldr r7, [r9]
 *   @0x19ee10 b 0x19ee24 <_Z11Object_FindPKc+0x30>
 *   @0x19ee14 ldr r3, [r9, #0x4]
 *   @0x19ee18 add r5, r5, #1
 *   @0x19ee1c cmp r5, r3
 *   @0x19ee20 bgt 0x19eea8 <_Z11Object_FindPKc+0xb4>
 *   @0x19ee24 ldr r4, [r7, r5, lsl #3]
 *   @0x19ee28 cmp r4, #0
 *   @0x19ee2c beq 0x19ee14 <_Z11Object_FindPKc+0x20>
 *   @0x19ee30 ldr r6, [r4, #0xc]
 *   @0x19ee34 cmp r6, #0
 *   @0x19ee38 beq 0x19eea8 <_Z11Object_FindPKc+0xb4>
 *   @0x19ee3c ldr r0, [r6, #0x14]
 *   @0x19ee40 cmp r0, #0
 *   @0x19ee44 beq 0x19ee58 <_Z11Object_FindPKc+0x64>
 *   @0x19ee48 mov r1, r8
 *   @0x19ee4c bl 0xb6574 <strcmp@plt>
 *   @0x19ee50 cmp r0, #0
 *   @0x19ee54 beq 0x19eeb0 <_Z11Object_FindPKc+0xbc>
 *   @0x19ee58 cmp r4, #0
 *   @0x19ee5c beq 0x19eea8 <_Z11Object_FindPKc+0xb4>
 *   @0x19ee60 ldr r4, [r4, #0x4]
 *   @0x19ee64 cmp r4, #0
 *   @0x19ee68 bne 0x19ee30 <_Z11Object_FindPKc+0x3c>
 *   @0x19ee6c ldr r1, [r9, #0x4]
 *   @0x19ee70 add r3, r5, #1
 *   @0x19ee74 cmp r3, r1
 *   @0x19ee78 bgt 0x19eea8 <_Z11Object_FindPKc+0xb4>
 *   @0x19ee7c add r2, r7, r5, lsl #3
 *   @0x19ee80 b 0x19ee8c <_Z11Object_FindPKc+0x98>
 *   @0x19ee84 cmp r1, r3
 *   @0x19ee88 blt 0x19eea8 <_Z11Object_FindPKc+0xb4>
 *   @0x19ee8c ldr r4, [r2, #0x8]
 *   @0x19ee90 mov r5, r3
 *   @0x19ee94 add r2, r2, #8
 *   @0x19ee98 add r3, r3, #1
 *   @0x19ee9c cmp r4, #0
 *   @0x19eea0 beq 0x19ee84 <_Z11Object_FindPKc+0x90>
 *   @0x19eea4 b 0x19ee30 <_Z11Object_FindPKc+0x3c>
 *   @0x19eea8 mvn r0, #0
 *   @0x19eeac pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x19eeb0 ldr r0, [r6, #0x18]
 *   @0x19eeb4 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x19eeb8 eoreq lr, r4, r8, lsr lr
 *
 * ══ §18/156 CPath::Assign(CPath*)  0x1a6ed0  size 200  50 条（0x1a6ed0..0x1a6f98）
 * @func 0x1a6ed0 0x1a6f98  size 200  50 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*) / MemoryManager::SetLength(void**, unsigned int, char const*, int) / CPath::Assign(CPath*)+0xb8
 * 字段偏移 top8: 0x4×6 / 0x10×4 / 0x14×2 / 0x18×2 / 0x1c×2 / 0x8×2 / 0x74×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a6ed0 push {r3, r4, r5, r6, r7, lr}
 *   @0x1a6ed4 mov r4, r0
 *   @0x1a6ed8 mov r6, r1
 *   @0x1a6edc ldr r0, [r0, #0x4]
 *   @0x1a6ee0 ldr r1, [r1, #0x14]
 *   @0x1a6ee4 ldrb r2, [r6, #0x18]
 *   @0x1a6ee8 cmp r0, #0
 *   @0x1a6eec ldr r3, [r6, #0x1c]
 *   @0x1a6ef0 str r1, [r4, #0x14]
 *   @0x1a6ef4 strb r2, [r4, #0x18]
 *   @0x1a6ef8 str r3, [r4, #0x1c]
 *   @0x1a6efc beq 0x1a6f10 <_ZN5CPath6AssignEPS_+0x40>
 *   @0x1a6f00 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1a6f04 mov r3, #0
 *   @0x1a6f08 str r3, [r4, #0x4]
 *   @0x1a6f0c str r3, [r4]
 *   @0x1a6f10 ldr r1, [r6, #0x10]
 *   @0x1a6f14 movw r3, #0x15e
 *   @0x1a6f18 ldr r2, [pc, #0x74]
 *   @0x1a6f1c add r0, r4, #4
 *   @0x1a6f20 add r1, r1, r1, lsl #1
 *   @0x1a6f24 add r2, pc, r2
 *   @0x1a6f28 lsl r1, r1, #2
 *   @0x1a6f2c bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1a6f30 ldr r3, [r6, #0x10]
 *   @0x1a6f34 cmp r3, #0
 *   @0x1a6f38 str r3, [r4]
 *   @0x1a6f3c str r3, [r4, #0x10]
 *   @0x1a6f40 movgt r3, #0
 *   @0x1a6f44 movgt r12, r3
 *   @0x1a6f48 ble 0x1a6f88 <_ZN5CPath6AssignEPS_+0xb8>
 *   @0x1a6f4c ldr r2, [r6, #0x4]
 *   @0x1a6f50 add r12, r12, #1
 *   @0x1a6f54 ldr r5, [r4, #0x4]
 *   @0x1a6f58 add r2, r2, r3
 *   @0x1a6f5c add r0, r5, r3
 *   @0x1a6f60 ldr r7, [r2]
 *   @0x1a6f64 ldr r1, [r2, #0x4]
 *   @0x1a6f68 ldr r2, [r2, #0x8]
 *   @0x1a6f6c str r7, [r5, r3]
 *   @0x1a6f70 add r3, r3, #12
 *   @0x1a6f74 str r1, [r0, #0x4]
 *   @0x1a6f78 str r2, [r0, #0x8]
 *   @0x1a6f7c ldr r2, [r4, #0x10]
 *   @0x1a6f80 cmp r2, r12
 *   @0x1a6f84 bgt 0x1a6f4c <_ZN5CPath6AssignEPS_+0x7c>
 *   @0x1a6f88 mov r0, r4
 *   @0x1a6f8c pop {r3, r4, r5, r6, r7, lr}
 *   @0x1a6f90 b 0x1a6e30 <_ZN5CPath15ComputeInternalEv>
 *   @0x1a6f94 ldrheq r6, [r10], -r4
 *
 * ══ §19/156 FINALIZE_Runner_Form()  0x1df90c  size 200  50 条（0x1df90c..0x1df9d4）
 * @func 0x1df90c 0x1df9d4  size 200  50 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1df91c→0x544b78, 0x1df940→0x544c64, 0x1df960→0x544c24, 0x1df978→0x544c14, 0x1df980→0x544c0c, 0x1df98c→0x544c08, 0x1df990→0x544c10
 * 调用序列: MemoryManager::Free(void const*)×3 / Path_Quit() / TimeLine_Quit()
 * 字段偏移 top8: 0x38×2 / 0x98×1 / 0x94×1 / 0x74×1 / 0x58×1 / 0x44×1 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1df90c push {r3, r4, r5, lr}
 *   @0x1df910 bl 0x1a7be8 <_Z9Path_Quitv>
 *   @0x1df914 ldr r4, [pc, #0x98]
 *   @0x1df918 bl 0x1f241c <_Z13TimeLine_Quitv>
 *   @0x1df91c ldr r3, [pc, #0x94]
 *   @0x1df920 add r4, pc, r4
 *   @0x1df924 ldr r5, [r4, r3]
 *   @0x1df928 ldr r0, [r5]
 *   @0x1df92c cmp r0, #0
 *   @0x1df930 beq 0x1df940 <_Z20FINALIZE_Runner_Formv+0x34>
 *   @0x1df934 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1df938 mov r3, #0
 *   @0x1df93c str r3, [r5]
 *   @0x1df940 ldr r3, [pc, #0x74]
 *   @0x1df944 ldr r5, [r4, r3]
 *   @0x1df948 ldr r0, [r5]
 *   @0x1df94c cmp r0, #0
 *   @0x1df950 beq 0x1df960 <_Z20FINALIZE_Runner_Formv+0x54>
 *   @0x1df954 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1df958 mov r3, #0
 *   @0x1df95c str r3, [r5]
 *   @0x1df960 ldr r3, [pc, #0x58]
 *   @0x1df964 ldr r5, [r4, r3]
 *   @0x1df968 ldr r0, [r5]
 *   @0x1df96c cmp r0, #0
 *   @0x1df970 beq 0x1df978 <_Z20FINALIZE_Runner_Formv+0x6c>
 *   @0x1df974 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1df978 ldr r2, [pc, #0x44]
 *   @0x1df97c mov r3, #0
 *   @0x1df980 ldr r0, [pc, #0x40]
 *   @0x1df984 str r3, [r5]
 *   @0x1df988 ldr r12, [r4, r2]
 *   @0x1df98c ldr r1, [pc, #0x38]
 *   @0x1df990 ldr r2, [pc, #0x38]
 *   @0x1df994 str r3, [r12]
 *   @0x1df998 ldr r0, [r4, r0]
 *   @0x1df99c str r3, [r0]
 *   @0x1df9a0 ldr r1, [r4, r1]
 *   @0x1df9a4 str r3, [r1]
 *   @0x1df9a8 ldr r2, [r4, r2]
 *   @0x1df9ac str r3, [r2]
 *   @0x1df9b0 pop {r3, r4, r5, pc}
 *   @0x1df9b4 eoreq r2, r1, r0, lsr r3
 *   @0x1df9b8 .word 0xfffff0bc
 *   @0x1df9bc .word 0xffffbef0
 *   @0x1df9c0 .word 0xfffff0c0
 *   @0x1df9c4 .word 0xffffbf08
 *   @0x1df9c8 .word 0xfffff098
 *   @0x1df9cc .word 0xfffff09c
 *   @0x1df9d0 .word 0xffffbefc
 *
 * ══ §20/156 Variable_Global_Declare(int)  0x1f33bc  size 200  50 条（0x1f33bc..0x1f3484）
 * @func 0x1f33bc 0x1f3484  size 200  50 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x4×6 / 0xa4×1 / 0x1×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f33bc sub r0, r0, #99328
 *   @0x1f33c0 push {r4, r5, r6, r7, r8, lr}
 *   @0x1f33c4 subs r5, r0, #672
 *   @0x1f33c8 sub sp, sp, #8
 *   @0x1f33cc bmi 0x1f33f0 <_Z23Variable_Global_Declarei+0x34>
 *   @0x1f33d0 ldr r4, [pc, #0xa4]
 *   @0x1f33d4 ldr r4, [pc, r4]
 *   @0x1f33d8 ldr r6, [r4]
 *   @0x1f33dc cmp r5, r6
 *   @0x1f33e0 bge 0x1f33f8 <_Z23Variable_Global_Declarei+0x3c>
 *   @0x1f33e4 ldr r7, [r4, #0x4]
 *   @0x1f33e8 mov r3, #1
 *   @0x1f33ec strb r3, [r7, r5]
 *   @0x1f33f0 add sp, sp, #8
 *   @0x1f33f4 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1f33f8 adds r8, r6, #1000
 *   @0x1f33fc bne 0x1f3444 <_Z23Variable_Global_Declarei+0x88>
 *   @0x1f3400 ldr r7, [r4, #0x4]
 *   @0x1f3404 subs r0, r7, #0
 *   @0x1f3408 beq 0x1f3470 <_Z23Variable_Global_Declarei+0xb4>
 *   @0x1f340c mov r7, r8
 *   @0x1f3410 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f3414 str r8, [r4, #0x4]
 *   @0x1f3418 add r12, r6, #996
 *   @0x1f341c sub r3, r6, #1
 *   @0x1f3420 add r12, r12, #3
 *   @0x1f3424 add r3, r7, r3
 *   @0x1f3428 add r12, r7, r12
 *   @0x1f342c mov r2, #0
 *   @0x1f3430 str r8, [r4]
 *   @0x1f3434 strb r2, [r3, #0x1]!
 *   @0x1f3438 cmp r3, r12
 *   @0x1f343c bne 0x1f3434 <_Z23Variable_Global_Declarei+0x78>
 *   @0x1f3440 b 0x1f33e8 <_Z23Variable_Global_Declarei+0x2c>
 *   @0x1f3444 ldr r2, [pc, #0x34]
 *   @0x1f3448 mov r3, #0
 *   @0x1f344c ldr r0, [r4, #0x4]
 *   @0x1f3450 mov r1, r8
 *   @0x1f3454 str r3, [sp]
 *   @0x1f3458 add r2, pc, r2
 *   @0x1f345c mov r3, #106
 *   @0x1f3460 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x1f3464 mov r7, r0
 *   @0x1f3468 str r0, [r4, #0x4]
 *   @0x1f346c b 0x1f3418 <_Z23Variable_Global_Declarei+0x5c>
 *   @0x1f3470 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f3474 str r7, [r4, #0x4]
 *   @0x1f3478 b 0x1f3418 <_Z23Variable_Global_Declarei+0x5c>
 *   @0x1f347c andseq sp, pc, r4, asr r10
 *   @0x1f3480 ldrsbeq r9, [r5], -r12
 *
 * ══ §21/156 OutputVariable(tagIConsole*, RVariable*)  0x1f5a00  size 200  50 条（0x1f5a00..0x1f5ac8）
 * @func 0x1f5a00 0x1f5ac8  size 200  50 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: OutputValue(tagIConsole*, RValue*) / Code_Variable_Find_Name(char const*, int, int)
 * 字段偏移 top8: 0xc×4 / 0x8×3 / 0x14×1 / 0x84×1 / 0x64×1 / 0x48×1 / 0x38×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f5a00 ldr r3, [r1, #0x14]
 *   @0x1f5a04 push {r4, r5, r6, lr}
 *   @0x1f5a08 cmp r3, #1
 *   @0x1f5a0c mov r5, r1
 *   @0x1f5a10 mov r4, r0
 *   @0x1f5a14 bne 0x1f5a64 <_Z14OutputVariableP11tagIConsoleP9RVariable+0x64>
 *   @0x1f5a18 ldr r3, [r1, #0x8]
 *   @0x1f5a1c cmp r3, #0
 *   @0x1f5a20 beq 0x1f5a9c <_Z14OutputVariableP11tagIConsoleP9RVariable+0x9c>
 *   @0x1f5a24 ldr r12, [r0]
 *   @0x1f5a28 ldr r1, [pc, #0x84]
 *   @0x1f5a2c ldr r2, [r3]
 *   @0x1f5a30 add r1, pc, r1
 *   @0x1f5a34 ldr r3, [r12, #0xc]
 *   @0x1f5a38 blx r3
 *   @0x1f5a3c add r1, r5, #24
 *   @0x1f5a40 mov r0, r4
 *   @0x1f5a44 bl 0x1f563c <_Z11OutputValueP11tagIConsoleP6RValue>
 *   @0x1f5a48 ldr r3, [r4]
 *   @0x1f5a4c ldr r1, [pc, #0x64]
 *   @0x1f5a50 mov r0, r4
 *   @0x1f5a54 add r1, pc, r1
 *   @0x1f5a58 ldr r3, [r3, #0xc]
 *   @0x1f5a5c blx r3
 *   @0x1f5a60 pop {r4, r5, r6, pc}
 *   @0x1f5a64 ldr r3, [r0]
 *   @0x1f5a68 mvn r1, #0
 *   @0x1f5a6c ldr r0, [pc, #0x48]
 *   @0x1f5a70 ldr r2, [r5, #0x8]
 *   @0x1f5a74 add r0, pc, r0
 *   @0x1f5a78 ldr r6, [r3, #0xc]
 *   @0x1f5a7c bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii>
 *   @0x1f5a80 ldr r1, [pc, #0x38]
 *   @0x1f5a84 ldr r3, [r5, #0x8]
 *   @0x1f5a88 add r1, pc, r1
 *   @0x1f5a8c mov r2, r0
 *   @0x1f5a90 mov r0, r4
 *   @0x1f5a94 blx r6
 *   @0x1f5a98 b 0x1f5a3c <_Z14OutputVariableP11tagIConsoleP9RVariable+0x3c>
 *   @0x1f5a9c ldr r3, [r0]
 *   @0x1f5aa0 ldr r1, [pc, #0x1c]
 *   @0x1f5aa4 ldr r3, [r3, #0xc]
 *   @0x1f5aa8 add r1, pc, r1
 *   @0x1f5aac blx r3
 *   @0x1f5ab0 b 0x1f5a3c <_Z14OutputVariableP11tagIConsoleP9RVariable+0x3c>
 *   @0x1f5ab4 andseq r7, r5, r4, ror r2
 *   @0x1f5ab8 andseq sp, r3, r4, asr #4
 *   @0x1f5abc andseq r9, r3, r2, asr #1
 *   @0x1f5ac0 andseq r12, r5, r8, lsr lr
 *   @0x1f5ac4 andseq r12, r5, r4, lsr #28
 *
 * ══ §22/156 SV_RoomSpeed(CInstance*, int, RValue*)  0x1fced4  size 200  50 条（0x1fced4..0x1fcf9c）
 * @func 0x1fced4 0x1fcf9c  size 200  50 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8 / REAL_RValue_Ex(RValue const*) / Error_Show_Action(char const*, bool) / CTimingSource::SetFrameRate(double)
 * 字段偏移 top8: 0xc×1 / 0x78×1 / 0x64×1 / 0x34×1 / 0x20×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1fced4 ldr r3, [r2, #0xc]
 *   @0x1fced8 push {r4, r5, r6, lr}
 *   @0x1fcedc bic r3, r3, #-16777216
 *   @0x1fcee0 cmp r3, #0
 *   @0x1fcee4 bne 0x1fcf44 <_Z12SV_RoomSpeedP9CInstanceiP6RValue+0x70>
 *   @0x1fcee8 ldm r2, {r4, r5}
 *   @0x1fceec mov r0, r4
 *   @0x1fcef0 mov r1, r5
 *   @0x1fcef4 bl 0xb66e8 <lrint@plt>
 *   @0x1fcef8 cmp r0, #0
 *   @0x1fcefc movle r6, #0
 *   @0x1fcf00 movgt r6, #1
 *   @0x1fcf04 cmp r6, #0
 *   @0x1fcf08 beq 0x1fcf58 <_Z12SV_RoomSpeedP9CInstanceiP6RValue+0x84>
 *   @0x1fcf0c ldr r3, [pc, #0x78]
 *   @0x1fcf10 ldr r3, [pc, r3]
 *   @0x1fcf14 ldrb r3, [r3]
 *   @0x1fcf18 cmp r3, #0
 *   @0x1fcf1c bne 0x1fcf70 <_Z12SV_RoomSpeedP9CInstanceiP6RValue+0x9c>
 *   @0x1fcf20 vmov d7, r4, r5
 *   @0x1fcf24 ldr r3, [pc, #0x64]
 *   @0x1fcf28 mov r0, r6
 *   @0x1fcf2c vcvt.s32.f64 s15, d7
 *   @0x1fcf30 ldr r3, [pc, r3]
 *   @0x1fcf34 ldr r3, [r3]
 *   @0x1fcf38 vmov r4, s15
 *   @0x1fcf3c vstr s15, [r3, #12]
 *   @0x1fcf40 pop {r4, r5, r6, pc}
 *   @0x1fcf44 mov r0, r2
 *   @0x1fcf48 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x1fcf4c mov r4, r0
 *   @0x1fcf50 mov r5, r1
 *   @0x1fcf54 b 0x1fceec <_Z12SV_RoomSpeedP9CInstanceiP6RValue+0x18>
 *   @0x1fcf58 ldr r0, [pc, #0x34]
 *   @0x1fcf5c mov r1, r6
 *   @0x1fcf60 add r0, pc, r0
 *   @0x1fcf64 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1fcf68 mov r0, r6
 *   @0x1fcf6c pop {r4, r5, r6, pc}
 *   @0x1fcf70 ldr r0, [pc, #0x20]
 *   @0x1fcf74 mov r2, r4
 *   @0x1fcf78 mov r3, r5
 *   @0x1fcf7c ldr r0, [pc, r0]
 *   @0x1fcf80 bl 0x214800 <_ZN13CTimingSource12SetFrameRateEd>
 *   @0x1fcf84 mov r0, r6
 *   @0x1fcf88 pop {r4, r5, r6, pc}
 *   @0x1fcf8c andseq r0, pc, r4, lsl r10
 *   @0x1fcf90 ldrsheq r0, [pc], -r8
 *   @0x1fcf94 andseq r5, r5, r8, ror #21
 *   @0x1fcf98 ldrheq r0, [pc], -r0
 *
 * ══ §23/156 ogg_zip_seek(void*, long long, int)  0x223518  size 200  50 条（0x223518..0x2235e0）
 * @func 0x223518 0x2235e0  size 200  50 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×5 / 0x18×4 / 0x1c×4 / 0x20×4 / 0x2d0×2 / 0x2cc×2 / 0x10×2 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x223518 str r4, [sp, #-0x4]!
 *   @0x22351c ldr r1, [sp, #0x4]
 *   @0x223520 ldr r3, [r0, #0x2c8]
 *   @0x223524 cmp r1, #1
 *   @0x223528 beq 0x2235ac <_Z12ogg_zip_seekPvxi+0x94>
 *   @0x22352c cmp r1, #2
 *   @0x223530 beq 0x223580 <_Z12ogg_zip_seekPvxi+0x68>
 *   @0x223534 cmp r1, #0
 *   @0x223538 mvnne r1, #0
 *   @0x22353c beq 0x22354c <_Z12ogg_zip_seekPvxi+0x34>
 *   @0x223540 mov r0, r1
 *   @0x223544 ldr r4, [sp], #4
 *   @0x223548 bx lr
 *   @0x22354c ldr r4, [r0, #0x2d0]
 *   @0x223550 ldr r12, [r0, #0x2cc]
 *   @0x223554 ldr r0, [r3, #0x10]
 *   @0x223558 add r12, r12, r2
 *   @0x22355c rsb r2, r2, r4
 *   @0x223560 bic r0, r0, #5
 *   @0x223564 str r12, [r3, #0x18]
 *   @0x223568 str r0, [r3, #0x10]
 *   @0x22356c mov r0, r1
 *   @0x223570 str r2, [r3, #0x1c]
 *   @0x223574 str r2, [r3, #0x20]
 *   @0x223578 ldr r4, [sp], #4
 *   @0x22357c bx lr
 *   @0x223580 ldr r4, [r0, #0x2d0]
 *   @0x223584 mov r1, #0
 *   @0x223588 ldr r12, [r0, #0x2cc]
 *   @0x22358c rsb r0, r2, r4
 *   @0x223590 str r2, [r3, #0x1c]
 *   @0x223594 add r0, r12, r0
 *   @0x223598 str r2, [r3, #0x20]
 *   @0x22359c str r0, [r3, #0x18]
 *   @0x2235a0 mov r0, r1
 *   @0x2235a4 ldr r4, [sp], #4
 *   @0x2235a8 bx lr
 *   @0x2235ac ldr r0, [r3, #0x20]
 *   @0x2235b0 mov r1, #0
 *   @0x2235b4 ldr r4, [r3, #0x18]
 *   @0x2235b8 ldr r12, [r3, #0x1c]
 *   @0x2235bc add r4, r4, r2
 *   @0x2235c0 str r4, [r3, #0x18]
 *   @0x2235c4 rsb r12, r2, r12
 *   @0x2235c8 ldr r4, [sp], #4
 *   @0x2235cc rsb r2, r2, r0
 *   @0x2235d0 str r12, [r3, #0x1c]
 *   @0x2235d4 mov r0, r1
 *   @0x2235d8 str r2, [r3, #0x20]
 *   @0x2235dc bx lr
 *
 * ══ §24/156 JS_JSONObjectSetup()  0x246ee0  size 200  50 条（0x246ee0..0x246fa8）
 * @func 0x246ee0 0x246fa8  size 200  50 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYObjectBase::Add(char const*, YYObjectBase*, int)×3 / JS_SetupFunction(void (*)(RValue&, CInstance*, CInstance*, int, RValue*), int, bool)×2 / JS_StandardBuiltInObjectConstructor(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x8×1 / 0x80×1 / 0x7c×1 / 0x40×1 / 0x68×1 / 0x54×1 / 0x44×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x246ee0 push {r4, r5, r6, lr}
 *   @0x246ee4 sub sp, sp, #24
 *   @0x246ee8 mov r4, #0
 *   @0x246eec add r0, sp, #8
 *   @0x246ef0 mov r3, r4
 *   @0x246ef4 mov r1, r4
 *   @0x246ef8 mov r2, r4
 *   @0x246efc str r4, [sp]
 *   @0x246f00 bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_>
 *   @0x246f04 ldr r5, [sp, #0x8]
 *   @0x246f08 ldr r6, [pc, #0x80]
 *   @0x246f0c mov r1, r4
 *   @0x246f10 ldr r0, [pc, #0x7c]
 *   @0x246f14 mov r2, r4
 *   @0x246f18 add r6, pc, r6
 *   @0x246f1c str r6, [r5, #0x40]
 *   @0x246f20 ldr r0, [pc, r0]
 *   @0x246f24 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x246f28 ldr r1, [pc, #0x68]
 *   @0x246f2c mov r3, #6
 *   @0x246f30 add r1, pc, r1
 *   @0x246f34 mov r2, r0
 *   @0x246f38 mov r0, r5
 *   @0x246f3c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246f40 ldr r0, [pc, #0x54]
 *   @0x246f44 mov r1, r4
 *   @0x246f48 mov r2, r4
 *   @0x246f4c ldr r0, [pc, r0]
 *   @0x246f50 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x246f54 ldr r1, [pc, #0x44]
 *   @0x246f58 mov r3, #6
 *   @0x246f5c add r1, pc, r1
 *   @0x246f60 mov r2, r0
 *   @0x246f64 mov r0, r5
 *   @0x246f68 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246f6c ldr r0, [pc, #0x30]
 *   @0x246f70 mov r1, r6
 *   @0x246f74 mov r2, r5
 *   @0x246f78 ldr r0, [pc, r0]
 *   @0x246f7c mov r3, r4
 *   @0x246f80 ldr r0, [r0]
 *   @0x246f84 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246f88 add sp, sp, #24
 *   @0x246f8c pop {r4, r5, r6, pc}
 *   @0x246f90 andseq lr, r0, r12, lsr #26
 *   @0x246f94 andseq r10, r10, r4, asr #16
 *   @0x246f98 ldrsheq lr, [r0], -r4
 *   @0x246f9c andseq r10, r10, r12, lsl r8
 *   @0x246fa0 ldrsheq lr, [r0], -r0
 *   @0x246fa4 andseq r6, r10, r12, lsr r12
 *
 * ══ §25/156 F_JSForInIterator(RValue&, CInstance*, CInstance*, int, RValue*)  0x24e6a8  size 200  50 条（0x24e6a8..0x24e770）
 * @func 0x24e6a8 0x24e770  size 200  50 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_JS_ToObject(RValue&, RValue*) / operator new(unsigned int) / YYObject_PropertyNameIterator::YYObject_PropertyNameIterator(YYObjectBase*, int) / JSThrowTypeError(char const*)
 * 字段偏移 top8: 0xc×5 / 0x20×1 / 0x8×1 / 0x10×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24e6a8 push {r4, r5, r6, lr}
 *   @0x24e6ac sub sp, sp, #16
 *   @0x24e6b0 mov r2, #0
 *   @0x24e6b4 mov r3, #0
 *   @0x24e6b8 ldr r1, [sp, #0x20]
 *   @0x24e6bc mov r4, r0
 *   @0x24e6c0 strd r2, r3, [sp]
 *   @0x24e6c4 mvn r2, #-16777216
 *   @0x24e6c8 mov r0, #0
 *   @0x24e6cc str r2, [sp, #0xc]
 *   @0x24e6d0 ldr r3, [r1, #0xc]
 *   @0x24e6d4 str r0, [sp, #0x8]
 *   @0x24e6d8 and r3, r3, r2
 *   @0x24e6dc cmp r3, #5
 *   @0x24e6e0 beq 0x24e73c <_Z17F_JSForInIteratorR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x24e6e4 cmp r3, #12
 *   @0x24e6e8 beq 0x24e73c <_Z17F_JSForInIteratorR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x24e6ec cmp r3, r2
 *   @0x24e6f0 beq 0x24e73c <_Z17F_JSForInIteratorR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x24e6f4 mov r0, sp
 *   @0x24e6f8 bl 0x247388 <_Z13F_JS_ToObjectR6RValuePS_>
 *   @0x24e6fc cmp r0, #1
 *   @0x24e700 beq 0x24e758 <_Z17F_JSForInIteratorR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x24e704 mov r0, #28
 *   @0x24e708 ldr r6, [sp]
 *   @0x24e70c bl 0x27c524 <_Znwj>
 *   @0x24e710 mov r2, #1
 *   @0x24e714 mov r1, r6
 *   @0x24e718 mov r5, r0
 *   @0x24e71c bl 0x2400ec <_ZN29YYObject_PropertyNameIteratorC2EP12YYObjectBasei>
 *   @0x24e720 mov r2, #1
 *   @0x24e724 mov r3, #14
 *   @0x24e728 strb r2, [r5, #0x10]
 *   @0x24e72c str r5, [r4]
 *   @0x24e730 str r3, [r4, #0xc]
 *   @0x24e734 add sp, sp, #16
 *   @0x24e738 pop {r4, r5, r6, pc}
 *   @0x24e73c mov r3, #0
 *   @0x24e740 mov r2, #5
 *   @0x24e744 str r3, [r4]
 *   @0x24e748 str r2, [r4, #0xc]
 *   @0x24e74c str r3, [r4, #0x4]
 *   @0x24e750 add sp, sp, #16
 *   @0x24e754 pop {r4, r5, r6, pc}
 *   @0x24e758 ldr r0, [pc, #0xc]
 *   @0x24e75c add r0, pc, r0
 *   @0x24e760 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x24e764 add sp, sp, #16
 *   @0x24e768 pop {r4, r5, r6, pc}
 *   @0x24e76c ldrheq r7, [r0], -r8
 *
 * ══ §26/156 _spSkeletonJson_setError  0x28b784  size 200  50 条（0x28b784..0x28b84c）
 * @func 0x28b784 0x28b84c  size 200  50 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65a4×2 / 0xb6538×2 / _free / 0xb6c1c / _malloc / ReportSpineError / Json_dispose / 0xb65d4
 * 字段偏移 top8: 0x8×2 / 0x104×2 / 0xb0×1 / 0x50×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28b784 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x28b788 mov r9, r3
 *   @0x28b78c ldr r5, [pc, #0xb0]
 *   @0x28b790 sub sp, sp, #268
 *   @0x28b794 add r4, sp, #4
 *   @0x28b798 mov r7, r2
 *   @0x28b79c ldr r5, [pc, r5]
 *   @0x28b7a0 mov r6, r0
 *   @0x28b7a4 ldr r0, [r0, #0x8]
 *   @0x28b7a8 mov r8, r1
 *   @0x28b7ac ldr r3, [r5]
 *   @0x28b7b0 str r3, [sp, #0x104]
 *   @0x28b7b4 bl 0x285c80 <_free>
 *   @0x28b7b8 mov r1, r7
 *   @0x28b7bc mov r0, r4
 *   @0x28b7c0 bl 0xb65a4 <strcpy@plt>
 *   @0x28b7c4 mov r0, r7
 *   @0x28b7c8 bl 0xb6538 <strlen@plt>
 *   @0x28b7cc cmp r9, #0
 *   @0x28b7d0 mov r2, r0
 *   @0x28b7d4 beq 0x28b7e8 <_spSkeletonJson_setError+0x64>
 *   @0x28b7d8 mov r1, r9
 *   @0x28b7dc add r0, r4, r0
 *   @0x28b7e0 rsb r2, r2, #255
 *   @0x28b7e4 bl 0xb6c1c <strncat@plt>
 *   @0x28b7e8 mov r0, r4
 *   @0x28b7ec bl 0xb6538 <strlen@plt>
 *   @0x28b7f0 ldr r1, [pc, #0x50]
 *   @0x28b7f4 mov r2, #90
 *   @0x28b7f8 add r1, pc, r1
 *   @0x28b7fc add r0, r0, #1
 *   @0x28b800 bl 0x285c10 <_malloc>
 *   @0x28b804 mov r1, r4
 *   @0x28b808 str r0, [r6, #0x8]
 *   @0x28b80c bl 0xb65a4 <strcpy@plt>
 *   @0x28b810 mov r0, r4
 *   @0x28b814 bl 0xc4404 <ReportSpineError>
 *   @0x28b818 cmp r8, #0
 *   @0x28b81c beq 0x28b828 <_spSkeletonJson_setError+0xa4>
 *   @0x28b820 mov r0, r8
 *   @0x28b824 bl 0x2872c8 <Json_dispose>
 *   @0x28b828 ldr r2, [sp, #0x104]
 *   @0x28b82c ldr r3, [r5]
 *   @0x28b830 cmp r2, r3
 *   @0x28b834 bne 0x28b840 <_spSkeletonJson_setError+0xbc>
 *   @0x28b838 add sp, sp, #268
 *   @0x28b83c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x28b840 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x28b844 ldrheq r2, [r6], -r4
 *   @0x28b848 andeq r12, r12, r8, lsl #6
 *
 * ══ §27/156 anon_2e6e1c  0x2e6e1c  size 200  50 条（0x2e6e1c..0x2e6ee4）
 * @func 0x2e6e1c 0x2e6ee4  size 200  50 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x366d60 / 0x878684 / 0xffc37968 / 0x366cfc / anon_2e9c78+0x5248 / anon_2e9c78+0x5260
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e6e1c .word 0x43f7e92d
 *   @0x2e6e20 strmi r10, [lr], -r1, lsl #26
 *   @0x2e6e24 strtmi r4, [r9], -r4, lsl #12
 *   @0x2e6e28 .word 0xf7ff4690
 *   @0x2e6e2c blls 0x366d60 <_ZTS12CDS_Priority+0x8db8>
 *   @0x2e6e30 teqle r12, r0, lsl #22
 *   @0x2e6e34 strhle r4, [r1], -r0
 *   @0x2e6e38 eors r2, r9, r2
 *   @0x2e6e3c strtmi r4, [r9], -r0, lsr #12
 *   @0x2e6e40 .word 0xffc0f7ff
 *   @0x2e6e44 stmdahs r0, {r0, r11, r12, pc}
 *   @0x2e6e48 qasxmi sp, r0, r2
 *   @0x2e6e4c .word 0xf7ff2110
 *   @0x2e6e50 andls pc, r1, pc, ror #26
 *   @0x2e6e54 strtmi r11, [r0], -r0, ror #22
 *   @0x2e6e58 .word 0xf7ff4629
 *   @0x2e6e5c mcrls p14, #0x0, pc, c1, c3, #0x2
 *   @0x2e6e60 bllt 0x878684 <b2_toiTime+0x11f1e0>
 *   @0x2e6e64 rscle r2, r7, r0, lsl #16
 *   @0x2e6e68 ble 0xffc37968 <b2_toiTime+0xffffffffff4de4c4>
 *   @0x2e6e6c strtmi r4, [r9], -r0, lsr #12
 *   @0x2e6e70 .word 0xffa8f7ff
 *   @0x2e6e74 ldmiblt r3, {r0, r8, r9, r11, r12, pc} ^
 *   @0x2e6e78 strtmi r2, [r0], -r2, lsl #16
 *   @0x2e6e7c strtmi sp, [r9], -lr, lsl #2
 *   @0x2e6e80 .word 0xffa0f7ff
 *   @0x2e6e84 strmi r9, [r1], r1, lsl #22
 *   @0x2e6e88 strtmi r11, [r0], -r11, ror #18
 *   @0x2e6e8c .word 0xf7ff4629
 *   @0x2e6e90 blls 0x366cfc <_ZTS12CDS_Priority+0x8d54>
 *   @0x2e6e94 .word 0xf8c8b93b
 *   @0x2e6e98 and r9, r8, r0
 *   @0x2e6e9c .word 0xf7ff2108
 *   @0x2e6ea0 andls pc, r1, r7, asr #26
 *   @0x2e6ea4 strlo r11, [r1], -r0, lsr #18
 *   @0x2e6ea8 .word 0x4630e7de
 *   @0x2e6eac ldrmi lr, [r8], -r0
 *   @0x2e6eb0 pop {r0, r1, r12, sp, pc}
 *   @0x2e6eb4 strdeq r8, r9, [r0], -r0
 *   @0x2e6eb8 bls 0x2eeec0 <FT_Done_Memory+0x524c>
 *   @0x2e6ebc tstlt r9, r8, lsl r0
 *   @0x2e6ec0 stmdbmi r2, {r3, r9, r10, lr}
 *   @0x2e6ec4 svclt #0xaaf7ff
 *   @0x2e6ec8 .word 0x47702051
 *   @0x2e6ecc andeq r1, r5, r0, lsl #12
 *   @0x2e6ed0 bls 0x2eeed8 <FT_Done_Memory+0x5264>
 *   @0x2e6ed4 tstlt r9, r8, lsl r0
 *   @0x2e6ed8 stmdbmi r2, {r3, r9, r10, lr}
 *   @0x2e6edc svclt #0x9ef7ff
 *   @0x2e6ee0 .word 0x47702051
 *
 * ══ §28/156 CBackground::Draw(float, float, float, float, float, unsigned int, float)  0xc1fd0  size 196  49 条（0xc1fd0..0xc2094）
 * @func 0xc1fd0 0xc2094  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Texture_Draw(YYTPageEntry*, float, float, float, float, float, float, float, unsigned int, float) / GR_Texture_Draw(int, float, float, float, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0x4×4 / 0x28×2 / 0x10×2 / 0x14×1 / 0x-4×1 / 0xc×1
 * VFP 指令 19 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc1fd0 ldr r12, [r0, #0x14]
 *   @0xc1fd4 vldr s15, [pc, #176]
 *   @0xc1fd8 str lr, [sp, #-0x4]!
 *   @0xc1fdc cmp r12, #0
 *   @0xc1fe0 sub sp, sp, #28
 *   @0xc1fe4 mov lr, r1
 *   @0xc1fe8 beq 0xc203c <_ZN11CBackground4DrawEfffffjf+0x6c>
 *   @0xc1fec vldr s13, [sp, #36]
 *   @0xc1ff0 vmul.f32 s15, s13, s15
 *   @0xc1ff4 vldr s14, [pc, #148]
 *   @0xc1ff8 str r3, [sp, #0x4]
 *   @0xc1ffc ldr r3, [sp, #0x28]
 *   @0xc2000 mov r1, #0
 *   @0xc2004 vldr s13, [sp, #32]
 *   @0xc2008 str r2, [sp]
 *   @0xc200c vstr s13, [sp, #8]
 *   @0xc2010 mov r0, r12
 *   @0xc2014 str r3, [sp, #0x10]
 *   @0xc2018 vldr s13, [sp, #44]
 *   @0xc201c mov r3, lr
 *   @0xc2020 vstr s13, [sp, #20]
 *   @0xc2024 mov r2, r1
 *   @0xc2028 vdiv.f32 s15, s15, s14
 *   @0xc202c vstr s15, [sp, #12]
 *   @0xc2030 bl 0x174ee0 <_Z15GR_Texture_DrawP12YYTPageEntryfffffffjf>
 *   @0xc2034 add sp, sp, #28
 *   @0xc2038 ldr pc, [sp], #4
 *   @0xc203c vldr s14, [sp, #36]
 *   @0xc2040 vmul.f32 s15, s14, s15
 *   @0xc2044 vldr s14, [pc, #68]
 *   @0xc2048 ldr r0, [r0, #0xc]
 *   @0xc204c str r3, [sp, #0x4]
 *   @0xc2050 mov r1, #0
 *   @0xc2054 ldr r3, [sp, #0x28]
 *   @0xc2058 vldr s13, [sp, #32]
 *   @0xc205c str r2, [sp]
 *   @0xc2060 vstr s13, [sp, #8]
 *   @0xc2064 mov r2, r1
 *   @0xc2068 vldr s13, [sp, #44]
 *   @0xc206c str r3, [sp, #0x10]
 *   @0xc2070 vstr s13, [sp, #20]
 *   @0xc2074 mov r3, lr
 *   @0xc2078 vdiv.f32 s15, s15, s14
 *   @0xc207c vstr s15, [sp, #12]
 *   @0xc2080 bl 0x174c40 <_Z15GR_Texture_Drawifffffffjf>
 *   @0xc2084 add sp, sp, #28
 *   @0xc2088 ldr pc, [sp], #4
 *   @0xc208c ldrdmi r0, r1, [r9], #-251
 *   @0xc2090 teqmi r4, #0
 *
 * ══ §29/156 F_BUFFER_Base64_Decode(RValue&, CInstance*, CInstance*, int, RValue*)  0xc694c  size 196  49 条（0xc694c..0xc6a10）
 * @func 0xc694c 0xc6a10  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / IBuffer::IBuffer() / YYGetString(RValue const*, int) / IBuffer::Base64decode(char const*, int, int) / AllocBuffer()
 * 字段偏移 top8: 0x4×3 / 0x18×1 / 0xc×1 / 0x7c×1 / 0x38×1 / 0x24×1 / 0x2×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc694c push {r3, r4, r5, r6, r7, lr}
 *   @0xc6950 mov r5, r0
 *   @0xc6954 mov r3, #0
 *   @0xc6958 ldr r7, [sp, #0x18]
 *   @0xc695c mov r4, r3
 *   @0xc6960 movt r3, #0xbff0
 *   @0xc6964 str r4, [r0, #0xc]
 *   @0xc6968 mov r0, #64
 *   @0xc696c str r3, [r5, #0x4]
 *   @0xc6970 str r4, [r5]
 *   @0xc6974 bl 0x27c524 <_Znwj>
 *   @0xc6978 mov r6, r0
 *   @0xc697c bl 0xcc900 <_ZN7IBufferC2Ev>
 *   @0xc6980 ldr r3, [pc, #0x7c]
 *   @0xc6984 mov r1, r4
 *   @0xc6988 mov r0, r7
 *   @0xc698c ldr r3, [pc, r3]
 *   @0xc6990 add r3, r3, #8
 *   @0xc6994 str r3, [r6]
 *   @0xc6998 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0xc699c mov r2, r4
 *   @0xc69a0 mvn r3, #0
 *   @0xc69a4 mov r1, r0
 *   @0xc69a8 mov r0, r6
 *   @0xc69ac bl 0xcda18 <_ZN7IBuffer12Base64decodeEPKcii>
 *   @0xc69b0 subs r4, r0, #0
 *   @0xc69b4 bne 0xc69dc <_Z22F_BUFFER_Base64_DecodeR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0xc69b8 ldr r3, [r6]
 *   @0xc69bc mov r0, r6
 *   @0xc69c0 ldr r3, [r3, #0x4]
 *   @0xc69c4 blx r3
 *   @0xc69c8 ldr r0, [pc, #0x38]
 *   @0xc69cc mov r1, r4
 *   @0xc69d0 add r0, pc, r0
 *   @0xc69d4 pop {r3, r4, r5, r6, r7, lr}
 *   @0xc69d8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc69dc bl 0xc67b0 <_Z11AllocBufferv>
 *   @0xc69e0 ldr r1, [pc, #0x24]
 *   @0xc69e4 add r1, pc, r1
 *   @0xc69e8 ldr r1, [r1, #0x4]
 *   @0xc69ec vmov s15, r0
 *   @0xc69f0 str r6, [r1, r0, lsl #2]
 *   @0xc69f4 vcvt.f64.s32 d7, s15
 *   @0xc69f8 vmov r2, r3, d7
 *   @0xc69fc stm r5, {r2, r3}
 *   @0xc6a00 pop {r3, r4, r5, r6, r7, pc}
 *   @0xc6a04 eorseq r7, r2, r4, lsr #32
 *   @0xc6a08 mlaeq r6, r4, r6, r10
 *   @0xc6a0c eorseq r3, r11, r0, lsr r7
 *
 * ══ §30/156 IBuffer::SetSurface(int, int, int)  0xcc83c  size 196  49 条（0xcc83c..0xcc900）
 * @func 0xcc83c 0xcc900  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Surface_Exists(int) / GR_Surface_Get_Width(int) / GR_Surface_Get_Height(int) / IBuffer::SetSurface(int, int, int)+0x24 / GR_Texture_Get_Surface(int) / Graphics::Surface_SetRect(void*, void*, int, int, int, int)
 * 字段偏移 top8: 0x4×3 / 0xc×2 / 0x10×1 / 0x60×1 / 0x3×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcc83c push {r4, r5, r6, r7, r8, lr}
 *   @0xcc840 mov r5, r0
 *   @0xcc844 sub sp, sp, #8
 *   @0xcc848 mov r0, r1
 *   @0xcc84c mov r4, r1
 *   @0xcc850 mov r6, r2
 *   @0xcc854 bl 0x1714c0 <_Z17GR_Surface_Existsi>
 *   @0xcc858 cmp r0, #0
 *   @0xcc85c bne 0xcc868 <_ZN7IBuffer10SetSurfaceEiii+0x2c>
 *   @0xcc860 add sp, sp, #8
 *   @0xcc864 pop {r4, r5, r6, r7, r8, pc}
 *   @0xcc868 mov r0, r4
 *   @0xcc86c bl 0x1714d4 <_Z20GR_Surface_Get_Widthi>
 *   @0xcc870 mov r7, r0
 *   @0xcc874 mov r0, r4
 *   @0xcc878 bl 0x171518 <_Z21GR_Surface_Get_Heighti>
 *   @0xcc87c ldr r3, [r5, #0x10]
 *   @0xcc880 mul r2, r0, r7
 *   @0xcc884 mov r8, r0
 *   @0xcc888 add r6, r6, r2, lsl #2
 *   @0xcc88c cmp r3, r6
 *   @0xcc890 blt 0xcc860 <_ZN7IBuffer10SetSurfaceEiii+0x24>
 *   @0xcc894 ldr r3, [pc, #0x60]
 *   @0xcc898 ldr r3, [pc, r3]
 *   @0xcc89c ldr r2, [r3, #0x4]
 *   @0xcc8a0 ldr r3, [r3]
 *   @0xcc8a4 and r2, r4, r2
 *   @0xcc8a8 ldr r3, [r3, r2, lsl #3]
 *   @0xcc8ac cmp r3, #0
 *   @0xcc8b0 bne 0xcc8c4 <_ZN7IBuffer10SetSurfaceEiii+0x88>
 *   @0xcc8b4 b 0xcc8d4 <_ZN7IBuffer10SetSurfaceEiii+0x98>
 *   @0xcc8b8 ldr r3, [r3, #0x4]
 *   @0xcc8bc cmp r3, #0
 *   @0xcc8c0 beq 0xcc8d4 <_ZN7IBuffer10SetSurfaceEiii+0x98>
 *   @0xcc8c4 ldr r2, [r3, #0x8]
 *   @0xcc8c8 cmp r4, r2
 *   @0xcc8cc bne 0xcc8b8 <_ZN7IBuffer10SetSurfaceEiii+0x7c>
 *   @0xcc8d0 ldr r3, [r3, #0xc]
 *   @0xcc8d4 ldr r0, [r3, #0x4]
 *   @0xcc8d8 bl 0x17435c <_Z22GR_Texture_Get_Surfacei>
 *   @0xcc8dc mov r2, #0
 *   @0xcc8e0 mov r3, r2
 *   @0xcc8e4 mov r1, r0
 *   @0xcc8e8 ldr r0, [r5, #0xc]
 *   @0xcc8ec stm sp, {r7, r8}
 *   @0xcc8f0 bl 0x17e6ac <_ZN8Graphics15Surface_SetRectEPvS0_iiii>
 *   @0xcc8f4 add sp, sp, #8
 *   @0xcc8f8 pop {r4, r5, r6, r7, r8, pc}
 *   @0xcc8fc eorseq r1, r2, r8, ror r2
 *
 * ══ §31/156 ProcessObjectDisposeList()  0xd3cd4  size 196  49 条（0xd3cd4..0xd3d98）
 * @func 0xd3cd4 0xd3d98  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_GetProperty(YYObjectBase*, RValue*, char const*) / Call_RValue(YYObjectBase*, RValue*, RValue*, int, RValue*) / ProcessObjectDisposeList()+0x40
 * 字段偏移 top8: 0xc×2 / 0x28×2 / 0xa8×1 / 0x98×1 / 0x94×1 / 0x2×1 / 0x18×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd3cd4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xd3cd8 sub sp, sp, #36
 *   @0xd3cdc ldr r8, [pc, #0xa8]
 *   @0xd3ce0 ldr r8, [pc, r8]
 *   @0xd3ce4 ldr r3, [r8]
 *   @0xd3ce8 cmp r3, #0
 *   @0xd3cec beq 0xd3d7c <_Z24ProcessObjectDisposeListv+0xa8>
 *   @0xd3cf0 ldr r9, [pc, #0x98]
 *   @0xd3cf4 mov r3, #0
 *   @0xd3cf8 ldr r11, [pc, #0x94]
 *   @0xd3cfc add r7, sp, #16
 *   @0xd3d00 ldr r9, [pc, r9]
 *   @0xd3d04 mov r5, r3
 *   @0xd3d08 mov r6, r3
 *   @0xd3d0c add r11, pc, r11
 *   @0xd3d10 str r11, [sp, #0xc]
 *   @0xd3d14 ldr r0, [r9]
 *   @0xd3d18 mov r1, r7
 *   @0xd3d1c ldr r2, [sp, #0xc]
 *   @0xd3d20 mov r11, #0
 *   @0xd3d24 mov r10, #0
 *   @0xd3d28 add r5, r5, #1
 *   @0xd3d2c ldr r4, [r0, r3, lsl #2]
 *   @0xd3d30 strd r10, r11, [sp, #16]
 *   @0xd3d34 mvn r11, #-16777216
 *   @0xd3d38 str r6, [sp, #0x18]
 *   @0xd3d3c mov r0, r4
 *   @0xd3d40 str r11, [sp, #0x1c]
 *   @0xd3d44 bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc>
 *   @0xd3d48 mov r1, #0
 *   @0xd3d4c mov r3, r1
 *   @0xd3d50 mov r2, r7
 *   @0xd3d54 str r6, [sp]
 *   @0xd3d58 mov r0, r4
 *   @0xd3d5c bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_>
 *   @0xd3d60 ldr r1, [r8]
 *   @0xd3d64 ldr r2, [r4, #0x28]
 *   @0xd3d68 mov r3, r5
 *   @0xd3d6c cmp r5, r1
 *   @0xd3d70 orr r2, r2, #2
 *   @0xd3d74 str r2, [r4, #0x28]
 *   @0xd3d78 blo 0xd3d14 <_Z24ProcessObjectDisposeListv+0x40>
 *   @0xd3d7c mov r3, #0
 *   @0xd3d80 str r3, [r8]
 *   @0xd3d84 add sp, sp, #36
 *   @0xd3d88 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xd3d8c eorseq r9, r1, r8, lsr pc
 *   @0xd3d90 eorseq r9, r1, r0, lsr #30
 *   @0xd3d94 eoreq lr, r5, r0, lsr #21
 *
 * ══ §32/156 AddToSlotTraversalMap(int)  0xd59d4  size 196  49 条（0xd59d4..0xd5a98）
 * @func 0xd59d4 0xd5a98  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xd59d8→0x47a200, 0xd59e0→0x47a20c, 0xd59f4→0x47a204, 0xd5a14→0x47a214, 0xd5a70→0x47a214
 * 调用序列: AddToSlotTraversalMap(int)+0x9c / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x2×8 / 0xa4×2 / 0xa0×1 / 0x90×1 / 0x74×1 / 0x58×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd59d4 ldr r12, [pc, #0xa4]
 *   @0xd59d8 ldr r3, [pc, #0xa4]
 *   @0xd59dc add r12, pc, r12
 *   @0xd59e0 ldr r1, [pc, #0xa0]
 *   @0xd59e4 push {r4, r5, r6, r7, lr}
 *   @0xd59e8 sub sp, sp, #12
 *   @0xd59ec ldr r3, [r12, r3]
 *   @0xd59f0 mov r6, r0
 *   @0xd59f4 ldr r2, [pc, #0x90]
 *   @0xd59f8 ldr r5, [r12, r1]
 *   @0xd59fc ldr r4, [r3]
 *   @0xd5a00 ldr r2, [r12, r2]
 *   @0xd5a04 ldr r3, [r5, r4, lsl #2]
 *   @0xd5a08 ldr r1, [r2, r4, lsl #2]
 *   @0xd5a0c cmp r3, r1
 *   @0xd5a10 blt 0xd5a70 <_Z21AddToSlotTraversalMapi+0x9c>
 *   @0xd5a14 ldr lr, [pc, #0x74]
 *   @0xd5a18 lsls r3, r1, #1
 *   @0xd5a1c strne r3, [r2, r4, lsl #2]
 *   @0xd5a20 mov r0, #0
 *   @0xd5a24 moveq r3, #1
 *   @0xd5a28 streq r3, [r2, r4, lsl #2]
 *   @0xd5a2c ldr r7, [r12, lr]
 *   @0xd5a30 mov r3, #74
 *   @0xd5a34 ldr r2, [pc, #0x58]
 *   @0xd5a38 lslne r1, r1, #3
 *   @0xd5a3c str r0, [sp]
 *   @0xd5a40 moveq r1, #4
 *   @0xd5a44 add r2, pc, r2
 *   @0xd5a48 ldr r0, [r7, r4, lsl #2]
 *   @0xd5a4c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0xd5a50 ldr r3, [r5, r4, lsl #2]
 *   @0xd5a54 mov r2, r0
 *   @0xd5a58 str r0, [r7, r4, lsl #2]
 *   @0xd5a5c add r1, r3, #1
 *   @0xd5a60 str r1, [r5, r4, lsl #2]
 *   @0xd5a64 str r6, [r2, r3, lsl #2]
 *   @0xd5a68 add sp, sp, #12
 *   @0xd5a6c pop {r4, r5, r6, r7, pc}
 *   @0xd5a70 ldr r2, [pc, #0x18]
 *   @0xd5a74 ldr r2, [r12, r2]
 *   @0xd5a78 ldr r2, [r2, r4, lsl #2]
 *   @0xd5a7c b 0xd5a5c <_Z21AddToSlotTraversalMapi+0x88>
 *   @0xd5a80 eorseq r12, r1, r4, ror r2
 *   @0xd5a84 .word 0xffffc000
 *   @0xd5a88 .word 0xffffc004
 *   @0xd5a8c .word 0xffffc008
 *   @0xd5a90 .word 0xffffc00c
 *   @0xd5a94 eoreq r11, r5, r12, ror #11
 *
 * ══ §33/156 F_DsMapExists(RValue&, CInstance*, CInstance*, int, RValue*)  0xff890  size 196  49 条（0xff890..0xff954）
 * @func 0xff890 0xff954  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DS_AutoMutex::~DS_AutoMutex()×2 / DS_AutoMutex::DS_AutoMutex() / YYGetInt32(RValue const*, int) / F_DsMapExists(RValue&, CInstance*, CInstance*, int, RValue*)+0x98 / CDS_Map::Exists(RValue*) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x4×2 / 0x18×1 / 0x80×1 / 0x70×1 / 0x2×1 / 0xc×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xff890 push {r4, r5, r6, lr}
 *   @0xff894 sub sp, sp, #8
 *   @0xff898 add r4, sp, #4
 *   @0xff89c mov r6, r0
 *   @0xff8a0 ldr r5, [sp, #0x18]
 *   @0xff8a4 mov r0, r4
 *   @0xff8a8 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0xff8ac mov r1, #0
 *   @0xff8b0 mov r0, r5
 *   @0xff8b4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xff8b8 cmp r0, #0
 *   @0xff8bc blt 0xff928 <_Z13F_DsMapExistsR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0xff8c0 ldr r3, [pc, #0x80]
 *   @0xff8c4 ldr r3, [pc, r3]
 *   @0xff8c8 ldr r3, [r3]
 *   @0xff8cc cmp r0, r3
 *   @0xff8d0 bge 0xff928 <_Z13F_DsMapExistsR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0xff8d4 ldr r3, [pc, #0x70]
 *   @0xff8d8 ldr r3, [pc, r3]
 *   @0xff8dc ldr r3, [r3, #0x4]
 *   @0xff8e0 ldr r0, [r3, r0, lsl #2]
 *   @0xff8e4 cmp r0, #0
 *   @0xff8e8 beq 0xff928 <_Z13F_DsMapExistsR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0xff8ec add r1, r5, #16
 *   @0xff8f0 mov r5, #0
 *   @0xff8f4 str r5, [r6, #0xc]
 *   @0xff8f8 bl 0x203a6c <_ZN7CDS_Map6ExistsEP6RValue>
 *   @0xff8fc cmp r0, #0
 *   @0xff900 moveq r5, r0
 *   @0xff904 movne r3, r5
 *   @0xff908 moveq r3, r5
 *   @0xff90c movtne r3, #0x3ff0
 *   @0xff910 str r5, [r6]
 *   @0xff914 mov r0, r4
 *   @0xff918 str r3, [r6, #0x4]
 *   @0xff91c bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xff920 add sp, sp, #8
 *   @0xff924 pop {r4, r5, r6, pc}
 *   @0xff928 ldr r0, [pc, #0x20]
 *   @0xff92c mov r1, #0
 *   @0xff930 add r0, pc, r0
 *   @0xff934 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xff938 mov r0, r4
 *   @0xff93c bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xff940 add sp, sp, #8
 *   @0xff944 pop {r4, r5, r6, pc}
 *   @0xff948 .word 0x002ee3b4
 *   @0xff94c eoreq lr, lr, r4, rrx
 *   @0xff950 eoreq r8, r3, r12, asr #5
 *
 * ══ §34/156 F_Point_In_Rectangle(RValue&, CInstance*, CInstance*, int, RValue*)  0x107900  size 196  49 条（0x107900..0x1079c4）
 * @func 0x107900 0x1079c4  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×6 / F_Point_In_Rectangle(RValue&, CInstance*, CInstance*, int, RValue*)+0xbc×2
 * 字段偏移 top8: 0x28×1 / 0xc×1 / 0x4×1
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x107900 push {r4, r5, r6, lr}
 *   @0x107904 vpush {d8, d9, d10}
 *   @0x107908 mov r5, #0
 *   @0x10790c ldr r4, [sp, #0x28]
 *   @0x107910 mov r1, r5
 *   @0x107914 str r5, [r0, #0xc]
 *   @0x107918 mov r6, r0
 *   @0x10791c str r5, [r0]
 *   @0x107920 str r5, [r0, #0x4]
 *   @0x107924 mov r0, r4
 *   @0x107928 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10792c mov r1, #1
 *   @0x107930 vmov s16, r0
 *   @0x107934 mov r0, r4
 *   @0x107938 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10793c mov r1, #2
 *   @0x107940 vmov s19, r0
 *   @0x107944 mov r0, r4
 *   @0x107948 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10794c mov r1, #3
 *   @0x107950 vmov s17, r0
 *   @0x107954 mov r0, r4
 *   @0x107958 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10795c mov r1, #4
 *   @0x107960 vmov s20, r0
 *   @0x107964 mov r0, r4
 *   @0x107968 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10796c mov r1, #5
 *   @0x107970 vmov s18, r0
 *   @0x107974 mov r0, r4
 *   @0x107978 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10797c vcmpe.f32 s16, s17
 *   @0x107980 vmrs APSR_nzcv, fpscr
 *   @0x107984 vmov s15, r0
 *   @0x107988 blt 0x1079bc <_Z20F_Point_In_RectangleR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x10798c vcmpe.f32 s16, s18
 *   @0x107990 vmrs APSR_nzcv, fpscr
 *   @0x107994 bhi 0x1079bc <_Z20F_Point_In_RectangleR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x107998 vcmpe.f32 s19, s20
 *   @0x10799c vmrs APSR_nzcv, fpscr
 *   @0x1079a0 blt 0x1079bc <_Z20F_Point_In_RectangleR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x1079a4 vcmpe.f32 s19, s15
 *   @0x1079a8 vmrs APSR_nzcv, fpscr
 *   @0x1079ac movls r3, r5
 *   @0x1079b0 strls r5, [r6]
 *   @0x1079b4 movtls r3, #0x3ff0
 *   @0x1079b8 strls r3, [r6, #0x4]
 *   @0x1079bc vpop {d8, d9, d10}
 *   @0x1079c0 pop {r4, r5, r6, pc}
 *
 * ══ §35/156 F_PointDistance_3D(RValue&, CInstance*, CInstance*, int, RValue*)  0x10f090  size 196  49 条（0x10f090..0x10f154）
 * @func 0x10f090 0x10f154  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×6 / 0xb6700
 * 字段偏移 top8: 0x20×1 / 0xc×1
 * VFP 指令 21 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10f090 push {r4, r5, r6, lr}
 *   @0x10f094 vpush {d8, d9}
 *   @0x10f098 mov r6, #0
 *   @0x10f09c ldr r4, [sp, #0x20]
 *   @0x10f0a0 mov r1, #3
 *   @0x10f0a4 str r6, [r0, #0xc]
 *   @0x10f0a8 mov r5, r0
 *   @0x10f0ac mov r0, r4
 *   @0x10f0b0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10f0b4 mov r1, r6
 *   @0x10f0b8 vmov s16, r0
 *   @0x10f0bc mov r0, r4
 *   @0x10f0c0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10f0c4 mov r1, #4
 *   @0x10f0c8 vmov s12, r0
 *   @0x10f0cc mov r0, r4
 *   @0x10f0d0 vsub.f32 s16, s16, s12
 *   @0x10f0d4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10f0d8 mov r1, #1
 *   @0x10f0dc vmov s17, r0
 *   @0x10f0e0 mov r0, r4
 *   @0x10f0e4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10f0e8 mov r1, #5
 *   @0x10f0ec vmov s13, r0
 *   @0x10f0f0 mov r0, r4
 *   @0x10f0f4 vsub.f32 s17, s17, s13
 *   @0x10f0f8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10f0fc mov r1, #2
 *   @0x10f100 vmov s18, r0
 *   @0x10f104 mov r0, r4
 *   @0x10f108 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10f10c vmul.f32 s15, s17, s17
 *   @0x10f110 vmla.f32 s15, s16, s16
 *   @0x10f114 vmov s12, r0
 *   @0x10f118 vsub.f32 s14, s18, s12
 *   @0x10f11c vmla.f32 s15, s14, s14
 *   @0x10f120 vsqrt.f32 s14, s15
 *   @0x10f124 vcmp.f32 s14, s14
 *   @0x10f128 vmrs APSR_nzcv, fpscr
 *   @0x10f12c bne 0x10f144 <_Z18F_PointDistance_3DR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x10f130 vcvt.f64.f32 d6, s14
 *   @0x10f134 vmov r2, r3, d6
 *   @0x10f138 stm r5, {r2, r3}
 *   @0x10f13c vpop {d8, d9}
 *   @0x10f140 pop {r4, r5, r6, pc}
 *   @0x10f144 vmov r0, s15
 *   @0x10f148 bl 0xb6700 <sqrtf@plt>
 *   @0x10f14c vmov s14, r0
 *   @0x10f150 b 0x10f130 <_Z18F_PointDistance_3DR6RValueP9CInstanceS2_iPS_+0xa0>
 *
 * ══ §36/156 F_StringLettersDigits(RValue&, CInstance*, CInstance*, int, RValue*)  0x110024  size 196  49 条（0x110024..0x1100e8）
 * @func 0x110024 0x1100e8  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: utf8_add_char×2 / YYGetString(RValue const*, int) / 0xb6538 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / utf8_extract_char / F_StringLettersDigits(RValue&, CInstance*, CInstance*, int, RValue*)+0x84 / YYCreateString(RValue*, char const*) / YYFree(void const*)
 * 字段偏移 top8: 0x20×1 / 0x94×1 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x110024 push {r4, r5, r6, r7, r8, lr}
 *   @0x110028 sub sp, sp, #8
 *   @0x11002c mov r1, #0
 *   @0x110030 mov r7, r0
 *   @0x110034 ldr r0, [sp, #0x20]
 *   @0x110038 add r4, sp, #8
 *   @0x11003c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x110040 mov r8, r0
 *   @0x110044 bl 0xb6538 <strlen@plt>
 *   @0x110048 ldr r1, [pc, #0x94]
 *   @0x11004c mov r3, #1
 *   @0x110050 movw r2, #0x881
 *   @0x110054 add r1, pc, r1
 *   @0x110058 add r0, r0, r3
 *   @0x11005c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x110060 str r8, [sp]
 *   @0x110064 mov r3, r8
 *   @0x110068 mov r6, r0
 *   @0x11006c str r0, [r4, #-0x4]!
 *   @0x110070 b 0x1100b0 <_Z21F_StringLettersDigitsR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x110074 bl 0x10fb38 <utf8_extract_char>
 *   @0x110078 mov r3, r0
 *   @0x11007c bic r2, r3, #32
 *   @0x110080 sub r2, r2, #65
 *   @0x110084 sub r3, r3, #48
 *   @0x110088 mov r1, r0
 *   @0x11008c mov r0, r4
 *   @0x110090 uxth r2, r2
 *   @0x110094 uxth r3, r3
 *   @0x110098 cmp r2, #25
 *   @0x11009c bls 0x1100a8 <_Z21F_StringLettersDigitsR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x1100a0 cmp r3, #9
 *   @0x1100a4 bhi 0x1100ac <_Z21F_StringLettersDigitsR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x1100a8 bl 0x10fe28 <utf8_add_char>
 *   @0x1100ac ldr r3, [sp]
 *   @0x1100b0 ldrb r1, [r3]
 *   @0x1100b4 mov r0, sp
 *   @0x1100b8 cmp r1, #0
 *   @0x1100bc bne 0x110074 <_Z21F_StringLettersDigitsR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x1100c0 mov r0, r4
 *   @0x1100c4 bl 0x10fe28 <utf8_add_char>
 *   @0x1100c8 mov r0, r7
 *   @0x1100cc mov r1, r6
 *   @0x1100d0 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x1100d4 mov r0, r6
 *   @0x1100d8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1100dc add sp, sp, #8
 *   @0x1100e0 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1100e4 .word 0x00228df0
 *
 * ══ §37/156 F_ExternalDefine0(RValue&, CInstance*, CInstance*, int, RValue*)  0x115e8c  size 196  49 条（0x115e8c..0x115f50）
 * @func 0x115e8c 0x115f50  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)×2 / 0xb65b0 / YYGetInt32(RValue const*, int) / DLL_Define(char const*, char const*, int, int, int*, int) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x70×1 / 0xc×1 / 0x4×1 / 0x10×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x115e8c push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x115e90 sub sp, sp, #84
 *   @0x115e94 add r5, sp, #12
 *   @0x115e98 mov r2, #68
 *   @0x115e9c ldr r4, [sp, #0x70]
 *   @0x115ea0 mov r7, r0
 *   @0x115ea4 mov r1, #0
 *   @0x115ea8 mov r0, r5
 *   @0x115eac bl 0xb65b0 <memset@plt>
 *   @0x115eb0 mov r1, #0
 *   @0x115eb4 mov r0, r4
 *   @0x115eb8 mov r6, r1
 *   @0x115ebc bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x115ec0 mov r1, #1
 *   @0x115ec4 mov r8, r0
 *   @0x115ec8 mov r0, r4
 *   @0x115ecc bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x115ed0 mov r1, #2
 *   @0x115ed4 mov r9, r0
 *   @0x115ed8 mov r0, r4
 *   @0x115edc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x115ee0 str r5, [sp]
 *   @0x115ee4 mov r1, r9
 *   @0x115ee8 str r6, [r7, #0xc]
 *   @0x115eec mov r2, r6
 *   @0x115ef0 mov r3, r6
 *   @0x115ef4 subs r0, r0, #1
 *   @0x115ef8 rsbs r12, r0, #0
 *   @0x115efc adcs r12, r12, r0
 *   @0x115f00 mov r0, r8
 *   @0x115f04 str r12, [sp, #0x4]
 *   @0x115f08 bl 0x2148fc <_Z10DLL_DefinePKcS0_iiPii>
 *   @0x115f0c vmov.f64 d7, #-1.000000e+00
 *   @0x115f10 vmov s13, r0
 *   @0x115f14 vcvt.f64.s32 d6, s13
 *   @0x115f18 vmov r0, r1, d6
 *   @0x115f1c vmov r2, s12
 *   @0x115f20 vcmp.f64 d6, d7
 *   @0x115f24 vmrs APSR_nzcv, fpscr
 *   @0x115f28 mov r3, r1
 *   @0x115f2c stm r7, {r2, r3}
 *   @0x115f30 bne 0x115f44 <_Z17F_ExternalDefine0R6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x115f34 ldr r0, [pc, #0x10]
 *   @0x115f38 mov r1, r6
 *   @0x115f3c add r0, pc, r0
 *   @0x115f40 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x115f44 add sp, sp, #84
 *   @0x115f48 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x115f4c eoreq r3, r2, r4, ror #14
 *
 * ══ §38/156 F_DateGetWeekday(RValue&, CInstance*, CInstance*, int, RValue*)  0x116b78  size 196  49 条（0x116b78..0x116c3c）
 * @func 0x116b78 0x116c3c  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / __fixdfdi / 0xb6820 / 0xb682c / 0x8278e4
 * 字段偏移 top8: 0xc×1 / 0x10×1 / 0x5c×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x116b78 push {r4, lr}
 *   @0x116b7c sub sp, sp, #8
 *   @0x116b80 mov r1, #0
 *   @0x116b84 mov r4, r0
 *   @0x116b88 mov r3, r1
 *   @0x116b8c str r1, [r0, #0xc]
 *   @0x116b90 movt r3, #0xbff0
 *   @0x116b94 stm r0, {r1, r3}
 *   @0x116b98 ldr r0, [sp, #0x10]
 *   @0x116b9c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x116ba0 vldr d7, [pc, #120]
 *   @0x116ba4 vldr d5, [pc, #124]
 *   @0x116ba8 vmov d6, r0, r1
 *   @0x116bac vsub.f64 d7, d6, d7
 *   @0x116bb0 vabs.f64 d4, d7
 *   @0x116bb4 vcmpe.f64 d4, d5
 *   @0x116bb8 vmrs APSR_nzcv, fpscr
 *   @0x116bbc vldrls d7, [pc, #108]
 *   @0x116bc0 vldrhi d6, [pc, #104]
 *   @0x116bc4 vmul.f64 d5, d7, d6
 *   @0x116bc8 vmov r0, r1, d5
 *   @0x116bcc bl 0x3194a0 <__fixdfdi>
 *   @0x116bd0 mov r3, r1
 *   @0x116bd4 ldr r1, [pc, #0x5c]
 *   @0x116bd8 mov r2, r0
 *   @0x116bdc strd r2, r3, [sp]
 *   @0x116be0 add r1, pc, r1
 *   @0x116be4 mov r0, sp
 *   @0x116be8 ldrb r3, [r1]
 *   @0x116bec cmp r3, #0
 *   @0x116bf0 bne 0x116c18 <_Z16F_DateGetWeekdayR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x116bf4 bl 0xb6820 <gmtime64@plt>
 *   @0x116bf8 cmp r0, #0
 *   @0x116bfc ldrne r2, [r0, #0x18]
 *   @0x116c00 vmovne s15, r2
 *   @0x116c04 vcvtne.f64.s32 d7, s15
 *   @0x116c08 vmovne r2, r3, d7
 *   @0x116c0c stmne r4, {r2, r3}
 *   @0x116c10 add sp, sp, #8
 *   @0x116c14 pop {r4, pc}
 *   @0x116c18 bl 0xb682c <localtime64@plt>
 *   @0x116c1c b 0x116bf8 <_Z16F_DateGetWeekdayR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x116c20 andeq r0, r0, r0
 *   @0x116c24 sbcsmi pc, r8, r0, asr #16
 *   @0x116c28 bl 0x8278e4 <b2_toiTime+0xce440>
 *   @0x116c2c svclo #0x1a36e2
 *   @0x116c30 andeq r0, r0, r0
 *   @0x116c34 rscsmi r1, r5, r0, lsl #16
 *   @0x116c38 eoreq r11, sp, r8, asr r5
 *
 * ══ §39/156 F_DateGetDay(RValue&, CInstance*, CInstance*, int, RValue*)  0x116de8  size 196  49 条（0x116de8..0x116eac）
 * @func 0x116de8 0x116eac  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / __fixdfdi / 0xb6820 / 0xb682c / 0x827b54
 * 字段偏移 top8: 0xc×1 / 0x10×1 / 0x5c×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x116de8 push {r4, lr}
 *   @0x116dec sub sp, sp, #8
 *   @0x116df0 mov r1, #0
 *   @0x116df4 mov r4, r0
 *   @0x116df8 mov r3, r1
 *   @0x116dfc str r1, [r0, #0xc]
 *   @0x116e00 movt r3, #0xbff0
 *   @0x116e04 stm r0, {r1, r3}
 *   @0x116e08 ldr r0, [sp, #0x10]
 *   @0x116e0c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x116e10 vldr d7, [pc, #120]
 *   @0x116e14 vldr d5, [pc, #124]
 *   @0x116e18 vmov d6, r0, r1
 *   @0x116e1c vsub.f64 d7, d6, d7
 *   @0x116e20 vabs.f64 d4, d7
 *   @0x116e24 vcmpe.f64 d4, d5
 *   @0x116e28 vmrs APSR_nzcv, fpscr
 *   @0x116e2c vldrls d7, [pc, #108]
 *   @0x116e30 vldrhi d6, [pc, #104]
 *   @0x116e34 vmul.f64 d5, d7, d6
 *   @0x116e38 vmov r0, r1, d5
 *   @0x116e3c bl 0x3194a0 <__fixdfdi>
 *   @0x116e40 mov r3, r1
 *   @0x116e44 ldr r1, [pc, #0x5c]
 *   @0x116e48 mov r2, r0
 *   @0x116e4c strd r2, r3, [sp]
 *   @0x116e50 add r1, pc, r1
 *   @0x116e54 mov r0, sp
 *   @0x116e58 ldrb r3, [r1]
 *   @0x116e5c cmp r3, #0
 *   @0x116e60 bne 0x116e88 <_Z12F_DateGetDayR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x116e64 bl 0xb6820 <gmtime64@plt>
 *   @0x116e68 cmp r0, #0
 *   @0x116e6c ldrne r2, [r0, #0xc]
 *   @0x116e70 vmovne s15, r2
 *   @0x116e74 vcvtne.f64.s32 d7, s15
 *   @0x116e78 vmovne r2, r3, d7
 *   @0x116e7c stmne r4, {r2, r3}
 *   @0x116e80 add sp, sp, #8
 *   @0x116e84 pop {r4, pc}
 *   @0x116e88 bl 0xb682c <localtime64@plt>
 *   @0x116e8c b 0x116e68 <_Z12F_DateGetDayR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x116e90 andeq r0, r0, r0
 *   @0x116e94 sbcsmi pc, r8, r0, asr #16
 *   @0x116e98 bl 0x827b54 <b2_toiTime+0xce6b0>
 *   @0x116e9c svclo #0x1a36e2
 *   @0x116ea0 andeq r0, r0, r0
 *   @0x116ea4 rscsmi r1, r5, r0, lsl #16
 *   @0x116ea8 eoreq r11, sp, r8, ror #5
 *
 * ══ §40/156 F_DateGetHour(RValue&, CInstance*, CInstance*, int, RValue*)  0x116eb0  size 196  49 条（0x116eb0..0x116f74）
 * @func 0x116eb0 0x116f74  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / __fixdfdi / 0xb6820 / 0xb682c / 0x827c1c
 * 字段偏移 top8: 0xc×1 / 0x10×1 / 0x5c×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x116eb0 push {r4, lr}
 *   @0x116eb4 sub sp, sp, #8
 *   @0x116eb8 mov r1, #0
 *   @0x116ebc mov r4, r0
 *   @0x116ec0 mov r3, r1
 *   @0x116ec4 str r1, [r0, #0xc]
 *   @0x116ec8 movt r3, #0xbff0
 *   @0x116ecc stm r0, {r1, r3}
 *   @0x116ed0 ldr r0, [sp, #0x10]
 *   @0x116ed4 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x116ed8 vldr d7, [pc, #120]
 *   @0x116edc vldr d5, [pc, #124]
 *   @0x116ee0 vmov d6, r0, r1
 *   @0x116ee4 vsub.f64 d7, d6, d7
 *   @0x116ee8 vabs.f64 d4, d7
 *   @0x116eec vcmpe.f64 d4, d5
 *   @0x116ef0 vmrs APSR_nzcv, fpscr
 *   @0x116ef4 vldrls d7, [pc, #108]
 *   @0x116ef8 vldrhi d6, [pc, #104]
 *   @0x116efc vmul.f64 d5, d7, d6
 *   @0x116f00 vmov r0, r1, d5
 *   @0x116f04 bl 0x3194a0 <__fixdfdi>
 *   @0x116f08 mov r3, r1
 *   @0x116f0c ldr r1, [pc, #0x5c]
 *   @0x116f10 mov r2, r0
 *   @0x116f14 strd r2, r3, [sp]
 *   @0x116f18 add r1, pc, r1
 *   @0x116f1c mov r0, sp
 *   @0x116f20 ldrb r3, [r1]
 *   @0x116f24 cmp r3, #0
 *   @0x116f28 bne 0x116f50 <_Z13F_DateGetHourR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x116f2c bl 0xb6820 <gmtime64@plt>
 *   @0x116f30 cmp r0, #0
 *   @0x116f34 ldrne r2, [r0, #0x8]
 *   @0x116f38 vmovne s15, r2
 *   @0x116f3c vcvtne.f64.s32 d7, s15
 *   @0x116f40 vmovne r2, r3, d7
 *   @0x116f44 stmne r4, {r2, r3}
 *   @0x116f48 add sp, sp, #8
 *   @0x116f4c pop {r4, pc}
 *   @0x116f50 bl 0xb682c <localtime64@plt>
 *   @0x116f54 b 0x116f30 <_Z13F_DateGetHourR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x116f58 andeq r0, r0, r0
 *   @0x116f5c sbcsmi pc, r8, r0, asr #16
 *   @0x116f60 bl 0x827c1c <b2_toiTime+0xce778>
 *   @0x116f64 svclo #0x1a36e2
 *   @0x116f68 andeq r0, r0, r0
 *   @0x116f6c rscsmi r1, r5, r0, lsl #16
 *   @0x116f70 eoreq r11, sp, r0, lsr #4
 *
 * ══ §41/156 F_DateGetMinute(RValue&, CInstance*, CInstance*, int, RValue*)  0x116f78  size 196  49 条（0x116f78..0x11703c）
 * @func 0x116f78 0x11703c  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / __fixdfdi / 0xb6820 / 0xb682c / 0x827ce4
 * 字段偏移 top8: 0xc×1 / 0x10×1 / 0x5c×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x116f78 push {r4, lr}
 *   @0x116f7c sub sp, sp, #8
 *   @0x116f80 mov r1, #0
 *   @0x116f84 mov r4, r0
 *   @0x116f88 mov r3, r1
 *   @0x116f8c str r1, [r0, #0xc]
 *   @0x116f90 movt r3, #0xbff0
 *   @0x116f94 stm r0, {r1, r3}
 *   @0x116f98 ldr r0, [sp, #0x10]
 *   @0x116f9c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x116fa0 vldr d7, [pc, #120]
 *   @0x116fa4 vldr d5, [pc, #124]
 *   @0x116fa8 vmov d6, r0, r1
 *   @0x116fac vsub.f64 d7, d6, d7
 *   @0x116fb0 vabs.f64 d4, d7
 *   @0x116fb4 vcmpe.f64 d4, d5
 *   @0x116fb8 vmrs APSR_nzcv, fpscr
 *   @0x116fbc vldrls d7, [pc, #108]
 *   @0x116fc0 vldrhi d6, [pc, #104]
 *   @0x116fc4 vmul.f64 d5, d7, d6
 *   @0x116fc8 vmov r0, r1, d5
 *   @0x116fcc bl 0x3194a0 <__fixdfdi>
 *   @0x116fd0 mov r3, r1
 *   @0x116fd4 ldr r1, [pc, #0x5c]
 *   @0x116fd8 mov r2, r0
 *   @0x116fdc strd r2, r3, [sp]
 *   @0x116fe0 add r1, pc, r1
 *   @0x116fe4 mov r0, sp
 *   @0x116fe8 ldrb r3, [r1]
 *   @0x116fec cmp r3, #0
 *   @0x116ff0 bne 0x117018 <_Z15F_DateGetMinuteR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x116ff4 bl 0xb6820 <gmtime64@plt>
 *   @0x116ff8 cmp r0, #0
 *   @0x116ffc ldrne r2, [r0, #0x4]
 *   @0x117000 vmovne s15, r2
 *   @0x117004 vcvtne.f64.s32 d7, s15
 *   @0x117008 vmovne r2, r3, d7
 *   @0x11700c stmne r4, {r2, r3}
 *   @0x117010 add sp, sp, #8
 *   @0x117014 pop {r4, pc}
 *   @0x117018 bl 0xb682c <localtime64@plt>
 *   @0x11701c b 0x116ff8 <_Z15F_DateGetMinuteR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x117020 andeq r0, r0, r0
 *   @0x117024 sbcsmi pc, r8, r0, asr #16
 *   @0x117028 bl 0x827ce4 <b2_toiTime+0xce840>
 *   @0x11702c svclo #0x1a36e2
 *   @0x117030 andeq r0, r0, r0
 *   @0x117034 rscsmi r1, r5, r0, lsl #16
 *   @0x117038 eoreq r11, sp, r8, asr r1
 *
 * ══ §42/156 F_DateGetSecond(RValue&, CInstance*, CInstance*, int, RValue*)  0x117040  size 196  49 条（0x117040..0x117104）
 * @func 0x117040 0x117104  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / __fixdfdi / 0xb6820 / 0xb682c / 0x827dac
 * 字段偏移 top8: 0xc×1 / 0x10×1 / 0x5c×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x117040 push {r4, lr}
 *   @0x117044 sub sp, sp, #8
 *   @0x117048 mov r1, #0
 *   @0x11704c mov r4, r0
 *   @0x117050 mov r3, r1
 *   @0x117054 str r1, [r0, #0xc]
 *   @0x117058 movt r3, #0xbff0
 *   @0x11705c stm r0, {r1, r3}
 *   @0x117060 ldr r0, [sp, #0x10]
 *   @0x117064 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x117068 vldr d7, [pc, #120]
 *   @0x11706c vldr d5, [pc, #124]
 *   @0x117070 vmov d6, r0, r1
 *   @0x117074 vsub.f64 d7, d6, d7
 *   @0x117078 vabs.f64 d4, d7
 *   @0x11707c vcmpe.f64 d4, d5
 *   @0x117080 vmrs APSR_nzcv, fpscr
 *   @0x117084 vldrls d7, [pc, #108]
 *   @0x117088 vldrhi d6, [pc, #104]
 *   @0x11708c vmul.f64 d5, d7, d6
 *   @0x117090 vmov r0, r1, d5
 *   @0x117094 bl 0x3194a0 <__fixdfdi>
 *   @0x117098 mov r3, r1
 *   @0x11709c ldr r1, [pc, #0x5c]
 *   @0x1170a0 mov r2, r0
 *   @0x1170a4 strd r2, r3, [sp]
 *   @0x1170a8 add r1, pc, r1
 *   @0x1170ac mov r0, sp
 *   @0x1170b0 ldrb r3, [r1]
 *   @0x1170b4 cmp r3, #0
 *   @0x1170b8 bne 0x1170e0 <_Z15F_DateGetSecondR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x1170bc bl 0xb6820 <gmtime64@plt>
 *   @0x1170c0 cmp r0, #0
 *   @0x1170c4 ldrne r2, [r0]
 *   @0x1170c8 vmovne s15, r2
 *   @0x1170cc vcvtne.f64.s32 d7, s15
 *   @0x1170d0 vmovne r2, r3, d7
 *   @0x1170d4 stmne r4, {r2, r3}
 *   @0x1170d8 add sp, sp, #8
 *   @0x1170dc pop {r4, pc}
 *   @0x1170e0 bl 0xb682c <localtime64@plt>
 *   @0x1170e4 b 0x1170c0 <_Z15F_DateGetSecondR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x1170e8 andeq r0, r0, r0
 *   @0x1170ec sbcsmi pc, r8, r0, asr #16
 *   @0x1170f0 bl 0x827dac <b2_toiTime+0xce908>
 *   @0x1170f4 svclo #0x1a36e2
 *   @0x1170f8 andeq r0, r0, r0
 *   @0x1170fc rscsmi r1, r5, r0, lsl #16
 *   @0x117100 mlaeq sp, r0, r0, r11
 *
 * ══ §43/156 F_DrawSurfaceStretchedExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x11ee64  size 196  49 条（0x11ee64..0x11ef28）
 * @func 0x11ee64 0x11ef28  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×5 / YYGetInt32(RValue const*, int)×2 / GR_Surface_Exists(int) / GR_Surface_DrawStretched(int, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0x30×1 / 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11ee64 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x11ee68 sub sp, sp, #16
 *   @0x11ee6c mov r1, #0
 *   @0x11ee70 ldr r4, [sp, #0x30]
 *   @0x11ee74 mov r0, r4
 *   @0x11ee78 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11ee7c mov r5, r0
 *   @0x11ee80 bl 0x1714c0 <_Z17GR_Surface_Existsi>
 *   @0x11ee84 subs r1, r0, #0
 *   @0x11ee88 beq 0x11ef10 <_Z25F_DrawSurfaceStretchedExtR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x11ee8c mov r0, r4
 *   @0x11ee90 mov r1, #1
 *   @0x11ee94 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11ee98 mov r1, #2
 *   @0x11ee9c mov r8, r0
 *   @0x11eea0 mov r0, r4
 *   @0x11eea4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11eea8 mov r1, #3
 *   @0x11eeac mov r7, r0
 *   @0x11eeb0 mov r0, r4
 *   @0x11eeb4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11eeb8 mov r1, #4
 *   @0x11eebc mov r6, r0
 *   @0x11eec0 mov r0, r4
 *   @0x11eec4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11eec8 mov r1, #5
 *   @0x11eecc mov r10, r0
 *   @0x11eed0 mov r0, r4
 *   @0x11eed4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11eed8 mov r1, #6
 *   @0x11eedc mov r9, r0
 *   @0x11eee0 mov r0, r4
 *   @0x11eee4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11eee8 str r10, [sp]
 *   @0x11eeec str r9, [sp, #0x4]
 *   @0x11eef0 mov r1, r8
 *   @0x11eef4 mov r2, r7
 *   @0x11eef8 mov r3, r6
 *   @0x11eefc str r0, [sp, #0x8]
 *   @0x11ef00 mov r0, r5
 *   @0x11ef04 bl 0x171e2c <_Z24GR_Surface_DrawStretchediffffjf>
 *   @0x11ef08 add sp, sp, #16
 *   @0x11ef0c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x11ef10 ldr r0, [pc, #0xc]
 *   @0x11ef14 add r0, pc, r0
 *   @0x11ef18 add sp, sp, #16
 *   @0x11ef1c pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x11ef20 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11ef24 eoreq r11, r1, r4, asr r3
 *
 * ══ §44/156 F_Audio_CreateBufferSound(RValue&, CInstance*, CInstance*, int, RValue*)  0x1359b0  size 196  49 条（0x1359b0..0x135a74）
 * @func 0x1359b0 0x135a74  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×6 / Audio_CreateBufferSound(int, int, int, int, int, int)
 * 字段偏移 top8: 0xb8×1 / 0x30×1 / 0xc×1 / 0x4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1359b0 ldr r3, [pc, #0xb8]
 *   @0x1359b4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1359b8 ldr r3, [pc, r3]
 *   @0x1359bc sub sp, sp, #12
 *   @0x1359c0 mov r6, r0
 *   @0x1359c4 ldrb r5, [r3]
 *   @0x1359c8 ldr r4, [sp, #0x30]
 *   @0x1359cc cmp r5, #0
 *   @0x1359d0 bne 0x135a68 <_Z25F_Audio_CreateBufferSoundR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x1359d4 mov r1, r5
 *   @0x1359d8 mov r0, r4
 *   @0x1359dc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1359e0 mov r1, #1
 *   @0x1359e4 mov r7, r0
 *   @0x1359e8 mov r0, r4
 *   @0x1359ec bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1359f0 mov r1, #2
 *   @0x1359f4 mov r10, r0
 *   @0x1359f8 mov r0, r4
 *   @0x1359fc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135a00 mov r1, #3
 *   @0x135a04 mov r9, r0
 *   @0x135a08 mov r0, r4
 *   @0x135a0c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135a10 mov r1, #4
 *   @0x135a14 mov r8, r0
 *   @0x135a18 mov r0, r4
 *   @0x135a1c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135a20 mov r1, #5
 *   @0x135a24 mov r11, r0
 *   @0x135a28 mov r0, r4
 *   @0x135a2c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x135a30 str r11, [sp]
 *   @0x135a34 mov r1, r10
 *   @0x135a38 mov r2, r9
 *   @0x135a3c mov r3, r8
 *   @0x135a40 str r5, [r6, #0xc]
 *   @0x135a44 str r0, [sp, #0x4]
 *   @0x135a48 mov r0, r7
 *   @0x135a4c bl 0x2198a0 <_Z23Audio_CreateBufferSoundiiiiii>
 *   @0x135a50 vmov s15, r0
 *   @0x135a54 vcvt.f64.s32 d7, s15
 *   @0x135a58 vmov r0, r1, d7
 *   @0x135a5c vmov r2, s14
 *   @0x135a60 mov r3, r1
 *   @0x135a64 stm r6, {r2, r3}
 *   @0x135a68 add sp, sp, #12
 *   @0x135a6c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x135a70 mlaeq r11, r4, r6, r9
 *
 * ══ §45/156 F_DirectoryExists(RValue&, CInstance*, CInstance*, int, RValue*)  0x1385dc  size 196  49 条（0x1385dc..0x1386a0）
 * @func 0x1385dc 0x1386a0  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DirectoryExists(char const*)×2 / YYGetString(RValue const*, int) / LoadSave::_GetSaveFileName(char*, int, char const*) / LoadSave::_GetBundleFileName(char*, int, char const*) / 0xb65d4
 * 字段偏移 top8: 0x404×2 / 0xb0×1 / 0x420×1 / 0xc×1 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1385dc push {r4, r5, r6, r7, lr}
 *   @0x1385e0 sub sp, sp, #1024
 *   @0x1385e4 ldr r4, [pc, #0xb0]
 *   @0x1385e8 sub sp, sp, #12
 *   @0x1385ec mov r5, r0
 *   @0x1385f0 mov r1, #0
 *   @0x1385f4 ldr r4, [pc, r4]
 *   @0x1385f8 ldr r0, [sp, #0x420]
 *   @0x1385fc add r6, sp, #4
 *   @0x138600 ldr r3, [r4]
 *   @0x138604 str r3, [sp, #0x404]
 *   @0x138608 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x13860c mov r3, #0
 *   @0x138610 mov r1, #1024
 *   @0x138614 str r3, [r5, #0xc]
 *   @0x138618 mov r2, r0
 *   @0x13861c mov r7, r0
 *   @0x138620 mov r0, r6
 *   @0x138624 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x138628 mov r0, r6
 *   @0x13862c bl 0x214f24 <_Z15DirectoryExistsPKc>
 *   @0x138630 cmp r0, #0
 *   @0x138634 beq 0x138670 <_Z17F_DirectoryExistsR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x138638 mov r3, #0
 *   @0x13863c movt r3, #0x3ff0
 *   @0x138640 mov r2, #0
 *   @0x138644 mov r1, r2
 *   @0x138648 ldr r2, [sp, #0x404]
 *   @0x13864c str r1, [r5]
 *   @0x138650 mov r1, r3
 *   @0x138654 ldr r3, [r4]
 *   @0x138658 str r1, [r5, #0x4]
 *   @0x13865c cmp r2, r3
 *   @0x138660 bne 0x138698 <_Z17F_DirectoryExistsR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x138664 add sp, sp, #1024
 *   @0x138668 add sp, sp, #12
 *   @0x13866c pop {r4, r5, r6, r7, pc}
 *   @0x138670 mov r2, r7
 *   @0x138674 mov r0, r6
 *   @0x138678 mov r1, #1024
 *   @0x13867c bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc>
 *   @0x138680 mov r0, r6
 *   @0x138684 bl 0x214f24 <_Z15DirectoryExistsPKc>
 *   @0x138688 vmov s15, r0
 *   @0x13868c vcvt.f64.s32 d7, s15
 *   @0x138690 vmov r2, r3, d7
 *   @0x138694 b 0x138644 <_Z17F_DirectoryExistsR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x138698 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x13869c eoreq r5, r11, r12, asr r3
 *
 * ══ §46/156 F_FileOpenWrite(RValue&, CInstance*, CInstance*, int, RValue*)  0x1398a4  size 196  49 条（0x1398a4..0x139968）
 * @func 0x1398a4 0x139968  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1398c4→0x483724, 0x1398d4→0x4837a4
 * 调用序列: MemoryManager::Free(void const*)×2 / YYGetString(RValue const*, int) / YYStrDup(char const*) / 0xb6844 / 0xb6850
 * 字段偏移 top8: 0x8×3 / 0x18×1 / 0x98×1 / 0x8c×1 / 0x80×1 / 0x5c×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1398a4 push {r3, r4, r5, r6, r7, lr}
 *   @0x1398a8 mov r1, #0
 *   @0x1398ac ldr r0, [sp, #0x18]
 *   @0x1398b0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1398b4 ldr r3, [pc, #0x98]
 *   @0x1398b8 add r3, pc, r3
 *   @0x1398bc subs r7, r0, #0
 *   @0x1398c0 beq 0x139940 <_Z15F_FileOpenWriteR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x1398c4 ldr r2, [pc, #0x8c]
 *   @0x1398c8 ldr r5, [r3, r2]
 *   @0x1398cc ldr r2, [r5]
 *   @0x1398d0 cmp r2, #0
 *   @0x1398d4 ldr r2, [pc, #0x80]
 *   @0x1398d8 bne 0x13991c <_Z15F_FileOpenWriteR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x1398dc ldr r4, [r3, r2]
 *   @0x1398e0 ldr r0, [r4]
 *   @0x1398e4 mov r6, #0
 *   @0x1398e8 str r6, [r5]
 *   @0x1398ec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1398f0 str r6, [r4]
 *   @0x1398f4 mov r0, r7
 *   @0x1398f8 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1398fc ldr r1, [pc, #0x5c]
 *   @0x139900 add r1, pc, r1
 *   @0x139904 str r0, [r4]
 *   @0x139908 bl 0xb6844 <fopen@plt>
 *   @0x13990c mov r3, #2
 *   @0x139910 str r3, [r5]
 *   @0x139914 str r0, [r4, #0x8]
 *   @0x139918 pop {r3, r4, r5, r6, r7, pc}
 *   @0x13991c ldr r4, [r3, r2]
 *   @0x139920 mov r6, #0
 *   @0x139924 ldr r0, [r4]
 *   @0x139928 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x13992c str r6, [r4]
 *   @0x139930 ldr r0, [r4, #0x8]
 *   @0x139934 bl 0xb6850 <fclose@plt>
 *   @0x139938 str r6, [r4, #0x8]
 *   @0x13993c b 0x1398e0 <_Z15F_FileOpenWriteR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x139940 ldr r0, [pc, #0x1c]
 *   @0x139944 mov r1, r7
 *   @0x139948 pop {r3, r4, r5, r6, r7, lr}
 *   @0x13994c add r0, pc, r0
 *   @0x139950 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x139954 mlaeq r11, r8, r3, r8
 *   @0x139958 .word 0xffffd620
 *   @0x13995c .word 0xffffd624
 *   @0x139960 eoreq r6, r0, r8, asr #17
 *   @0x139964 eoreq r6, r0, r12, asr r8
 *
 * ══ §47/156 F_FileOpenAppend(RValue&, CInstance*, CInstance*, int, RValue*)  0x139968  size 196  49 条（0x139968..0x139a2c）
 * @func 0x139968 0x139a2c  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x139988→0x483724, 0x139998→0x4837a4
 * 调用序列: MemoryManager::Free(void const*)×2 / YYGetString(RValue const*, int) / YYStrDup(char const*) / 0xb6844 / 0xb6850
 * 字段偏移 top8: 0x8×3 / 0x18×1 / 0x98×1 / 0x8c×1 / 0x80×1 / 0x5c×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x139968 push {r3, r4, r5, r6, r7, lr}
 *   @0x13996c mov r1, #0
 *   @0x139970 ldr r0, [sp, #0x18]
 *   @0x139974 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x139978 ldr r3, [pc, #0x98]
 *   @0x13997c add r3, pc, r3
 *   @0x139980 subs r7, r0, #0
 *   @0x139984 beq 0x139a04 <_Z16F_FileOpenAppendR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x139988 ldr r2, [pc, #0x8c]
 *   @0x13998c ldr r5, [r3, r2]
 *   @0x139990 ldr r2, [r5]
 *   @0x139994 cmp r2, #0
 *   @0x139998 ldr r2, [pc, #0x80]
 *   @0x13999c bne 0x1399e0 <_Z16F_FileOpenAppendR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x1399a0 ldr r4, [r3, r2]
 *   @0x1399a4 ldr r0, [r4]
 *   @0x1399a8 mov r6, #0
 *   @0x1399ac str r6, [r5]
 *   @0x1399b0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1399b4 str r6, [r4]
 *   @0x1399b8 mov r0, r7
 *   @0x1399bc bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1399c0 ldr r1, [pc, #0x5c]
 *   @0x1399c4 add r1, pc, r1
 *   @0x1399c8 str r0, [r4]
 *   @0x1399cc bl 0xb6844 <fopen@plt>
 *   @0x1399d0 mov r3, #2
 *   @0x1399d4 str r3, [r5]
 *   @0x1399d8 str r0, [r4, #0x8]
 *   @0x1399dc pop {r3, r4, r5, r6, r7, pc}
 *   @0x1399e0 ldr r4, [r3, r2]
 *   @0x1399e4 mov r6, #0
 *   @0x1399e8 ldr r0, [r4]
 *   @0x1399ec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1399f0 str r6, [r4]
 *   @0x1399f4 ldr r0, [r4, #0x8]
 *   @0x1399f8 bl 0xb6850 <fclose@plt>
 *   @0x1399fc str r6, [r4, #0x8]
 *   @0x139a00 b 0x1399a4 <_Z16F_FileOpenAppendR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x139a04 ldr r0, [pc, #0x1c]
 *   @0x139a08 mov r1, r7
 *   @0x139a0c pop {r3, r4, r5, r6, r7, lr}
 *   @0x139a10 add r0, pc, r0
 *   @0x139a14 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x139a18 .word 0x002b82d4
 *   @0x139a1c .word 0xffffd620
 *   @0x139a20 .word 0xffffd624
 *   @0x139a24 eoreq r6, r0, r12, lsr #16
 *   @0x139a28 .word 0x002067bc
 *
 * ══ §48/156 F_ActionPartEmitBurst(RValue&, CInstance*, CInstance*, int, RValue*)  0x140ce8  size 196  49 条（0x140ce8..0x140dac）
 * @func 0x140ce8 0x140dac  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / F_ActionPartEmitBurst(RValue&, CInstance*, CInstance*, int, RValue*)+0x98 / F_ActionPartEmitBurst(RValue&, CInstance*, CInstance*, int, RValue*)+0x80 / ParticleSystem_Create(int, bool)
 * 字段偏移 top8: 0x2×2 / 0x4×2 / 0xa0×1 / 0x20×1 / 0x60×1 / 0x50×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x140ce8 push {r4, r5, r6, r7, lr}
 *   @0x140cec sub sp, sp, #12
 *   @0x140cf0 mov r1, #0
 *   @0x140cf4 ldr r4, [pc, #0xa0]
 *   @0x140cf8 ldr r5, [sp, #0x20]
 *   @0x140cfc mov r0, r5
 *   @0x140d00 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x140d04 mov r1, #1
 *   @0x140d08 mov r6, r0
 *   @0x140d0c mov r0, r5
 *   @0x140d10 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x140d14 mov r1, #2
 *   @0x140d18 mov r7, r0
 *   @0x140d1c mov r0, r5
 *   @0x140d20 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x140d24 ldr r4, [pc, r4]
 *   @0x140d28 ldr r2, [r4]
 *   @0x140d2c cmp r2, #0
 *   @0x140d30 mov r3, r0
 *   @0x140d34 blt 0x140d80 <_Z21F_ActionPartEmitBurstR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x140d38 ldr r2, [pc, #0x60]
 *   @0x140d3c ldr r2, [pc, r2]
 *   @0x140d40 ldr r1, [r2, r6, lsl #2]
 *   @0x140d44 cmp r1, #0
 *   @0x140d48 blt 0x140d68 <_Z21F_ActionPartEmitBurstR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x140d4c ldr r2, [pc, #0x50]
 *   @0x140d50 ldr r0, [r4]
 *   @0x140d54 ldr r2, [pc, r2]
 *   @0x140d58 ldr r2, [r2, r7, lsl #2]
 *   @0x140d5c add sp, sp, #12
 *   @0x140d60 pop {r4, r5, r6, r7, lr}
 *   @0x140d64 b 0x1a3cf0 <_Z28ParticleSystem_Emitter_Burstiiii>
 *   @0x140d68 ldr r0, [pc, #0x38]
 *   @0x140d6c mov r1, #0
 *   @0x140d70 add r0, pc, r0
 *   @0x140d74 add sp, sp, #12
 *   @0x140d78 pop {r4, r5, r6, r7, lr}
 *   @0x140d7c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x140d80 mvn r0, #0
 *   @0x140d84 mov r1, #1
 *   @0x140d88 str r3, [sp, #0x4]
 *   @0x140d8c bl 0x1a42dc <_Z21ParticleSystem_Createib>
 *   @0x140d90 ldr r3, [sp, #0x4]
 *   @0x140d94 str r0, [r4]
 *   @0x140d98 b 0x140d38 <_Z21F_ActionPartEmitBurstR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x140d9c .word 0x002ae6b8
 *   @0x140da0 eoreq lr, r10, r8, lsr #13
 *   @0x140da4 eoreq lr, r10, r12, lsl #13
 *   @0x140da8 andseq pc, pc, r8, lsl r12
 *
 * ══ §49/156 F_ActionPartEmitStream(RValue&, CInstance*, CInstance*, int, RValue*)  0x140dac  size 196  49 条（0x140dac..0x140e70）
 * @func 0x140dac 0x140e70  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / F_ActionPartEmitStream(RValue&, CInstance*, CInstance*, int, RValue*)+0x98 / F_ActionPartEmitStream(RValue&, CInstance*, CInstance*, int, RValue*)+0x80 / ParticleSystem_Create(int, bool)
 * 字段偏移 top8: 0x2×2 / 0x4×2 / 0xa0×1 / 0x20×1 / 0x60×1 / 0x50×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x140dac push {r4, r5, r6, r7, lr}
 *   @0x140db0 sub sp, sp, #12
 *   @0x140db4 mov r1, #0
 *   @0x140db8 ldr r4, [pc, #0xa0]
 *   @0x140dbc ldr r5, [sp, #0x20]
 *   @0x140dc0 mov r0, r5
 *   @0x140dc4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x140dc8 mov r1, #1
 *   @0x140dcc mov r6, r0
 *   @0x140dd0 mov r0, r5
 *   @0x140dd4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x140dd8 mov r1, #2
 *   @0x140ddc mov r7, r0
 *   @0x140de0 mov r0, r5
 *   @0x140de4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x140de8 ldr r4, [pc, r4]
 *   @0x140dec ldr r2, [r4]
 *   @0x140df0 cmp r2, #0
 *   @0x140df4 mov r3, r0
 *   @0x140df8 blt 0x140e44 <_Z22F_ActionPartEmitStreamR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x140dfc ldr r2, [pc, #0x60]
 *   @0x140e00 ldr r2, [pc, r2]
 *   @0x140e04 ldr r1, [r2, r6, lsl #2]
 *   @0x140e08 cmp r1, #0
 *   @0x140e0c blt 0x140e2c <_Z22F_ActionPartEmitStreamR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x140e10 ldr r2, [pc, #0x50]
 *   @0x140e14 ldr r0, [r4]
 *   @0x140e18 ldr r2, [pc, r2]
 *   @0x140e1c ldr r2, [r2, r7, lsl #2]
 *   @0x140e20 add sp, sp, #12
 *   @0x140e24 pop {r4, r5, r6, r7, lr}
 *   @0x140e28 b 0x1a3ad4 <_Z29ParticleSystem_Emitter_Streamiiii>
 *   @0x140e2c ldr r0, [pc, #0x38]
 *   @0x140e30 mov r1, #0
 *   @0x140e34 add r0, pc, r0
 *   @0x140e38 add sp, sp, #12
 *   @0x140e3c pop {r4, r5, r6, r7, lr}
 *   @0x140e40 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x140e44 mvn r0, #0
 *   @0x140e48 mov r1, #1
 *   @0x140e4c str r3, [sp, #0x4]
 *   @0x140e50 bl 0x1a42dc <_Z21ParticleSystem_Createib>
 *   @0x140e54 ldr r3, [sp, #0x4]
 *   @0x140e58 str r0, [r4]
 *   @0x140e5c b 0x140dfc <_Z22F_ActionPartEmitStreamR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x140e60 .word 0x002ae5f4
 *   @0x140e64 eoreq lr, r10, r4, ror #11
 *   @0x140e68 eoreq lr, r10, r8, asr #11
 *   @0x140e6c andseq pc, pc, r4, asr r11
 *
 * ══ §50/156 F_IAP_Consume(RValue&, CInstance*, CInstance*, int, RValue*)  0x1551f0  size 196  49 条（0x1551f0..0x1552b4）
 * @func 0x1551f0 0x1552b4  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_15327c / F_IAP_Consume(RValue&, CInstance*, CInstance*, int, RValue*)+0x2c / F_IAP_Consume(RValue&, CInstance*, CInstance*, int, RValue*)+0x58 / anon_154a70
 * 字段偏移 top8: 0x4×2 / 0x28×1 / 0x90×1 / 0x80×1 / 0x7c×1 / 0xc×1 / 0x5c×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1551f0 push {r4, r5, lr}
 *   @0x1551f4 sub sp, sp, #28
 *   @0x1551f8 ldr r0, [sp, #0x28]
 *   @0x1551fc bl 0x15327c <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x155200 subs r12, r0, #0
 *   @0x155204 blt 0x15521c <_Z13F_IAP_ConsumeR6RValueP9CInstanceS2_iPS_+0x2c>
 *   @0x155208 ldr r3, [pc, #0x90]
 *   @0x15520c ldr r3, [pc, r3]
 *   @0x155210 ldr r2, [r3]
 *   @0x155214 cmp r12, r2
 *   @0x155218 blt 0x155248 <_Z13F_IAP_ConsumeR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x15521c ldr r3, [pc, #0x80]
 *   @0x155220 mov r2, r12
 *   @0x155224 ldr r1, [pc, #0x7c]
 *   @0x155228 ldr r3, [pc, r3]
 *   @0x15522c add r1, pc, r1
 *   @0x155230 ldr r0, [r3]
 *   @0x155234 ldr r3, [r0]
 *   @0x155238 ldr r3, [r3, #0xc]
 *   @0x15523c blx r3
 *   @0x155240 add sp, sp, #28
 *   @0x155244 pop {r4, r5, pc}
 *   @0x155248 ldr r2, [pc, #0x5c]
 *   @0x15524c mov r1, #0
 *   @0x155250 mov r4, #0
 *   @0x155254 str r1, [sp]
 *   @0x155258 add r2, pc, r2
 *   @0x15525c mov r5, #0
 *   @0x155260 str r2, [sp, #0x4]
 *   @0x155264 mov r0, #2
 *   @0x155268 strd r4, r5, [sp, #8]
 *   @0x15526c mov r2, #0
 *   @0x155270 ldr lr, [r3, #0x4]
 *   @0x155274 mov r3, #1073741824
 *   @0x155278 ldr r1, [pc, #0x30]
 *   @0x15527c ldr r12, [lr, r12, lsl #2]
 *   @0x155280 add r1, pc, r1
 *   @0x155284 ldr r12, [r12]
 *   @0x155288 str r12, [sp, #0x10]
 *   @0x15528c bl 0x154a70 <_Z19YYIAPEventsDispatchv+0xe88>
 *   @0x155290 mov r1, #2
 *   @0x155294 add sp, sp, #28
 *   @0x155298 pop {r4, r5, lr}
 *   @0x15529c b 0x153acc <_Z16InitIAPFunctionsv+0x5f8>
 *   @0x1552a0 eoreq r10, r9, r8, asr #17
 *   @0x1552a4 eoreq r8, r9, r8, lsl r7
 *   @0x1552a8 ldrheq r1, [pc], -r12
 *   @0x1552ac ldrsbeq r0, [pc], -r8
 *   @0x1552b0 andseq r0, pc, r8, lsr #29
 *
 * ══ §51/156 YYIAPProductDetailsReceived(char const*)  0x1553e8  size 196  49 条（0x1553e8..0x1554ac）
 * @func 0x1553e8 0x1554ac  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Mutex::Lock() / json_tokener_parse / YYIAPProductDetailsReceived(char const*)+0x64 / anon_154a70 / anon_153020+0x1ac
 * 字段偏移 top8: 0x4c×2 / 0xa4×1 / 0x7c×1 / 0x78×1 / 0xc×1 / 0x60×1 / 0x4×1 / 0x10×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1553e8 ldr r3, [pc, #0xa4]
 *   @0x1553ec push {r4, lr}
 *   @0x1553f0 add r3, pc, r3
 *   @0x1553f4 sub sp, sp, #24
 *   @0x1553f8 mov r4, r0
 *   @0x1553fc ldr r0, [r3]
 *   @0x155400 bl 0x27e084 <_ZN5Mutex4LockEv>
 *   @0x155404 mov r0, r4
 *   @0x155408 bl 0x28075c <json_tokener_parse>
 *   @0x15540c cmn r0, #4000
 *   @0x155410 bls 0x15544c <_Z27YYIAPProductDetailsReceivedPKc+0x64>
 *   @0x155414 ldr r3, [pc, #0x7c]
 *   @0x155418 mov r2, r4
 *   @0x15541c ldr r1, [pc, #0x78]
 *   @0x155420 ldr r3, [pc, r3]
 *   @0x155424 add r1, pc, r1
 *   @0x155428 ldr r0, [r3]
 *   @0x15542c ldr r3, [r0]
 *   @0x155430 ldr r3, [r3, #0xc]
 *   @0x155434 blx r3
 *   @0x155438 ldr r3, [pc, #0x60]
 *   @0x15543c ldr r0, [pc, r3]
 *   @0x155440 add sp, sp, #24
 *   @0x155444 pop {r4, lr}
 *   @0x155448 b 0x27e09c <_ZN5Mutex6UnlockEv>
 *   @0x15544c vmov s13, r0
 *   @0x155450 ldr r2, [pc, #0x4c]
 *   @0x155454 ldr r1, [pc, #0x4c]
 *   @0x155458 mov r3, #0
 *   @0x15545c vcvt.f64.s32 d7, s13
 *   @0x155460 add r2, pc, r2
 *   @0x155464 str r3, [sp]
 *   @0x155468 add r1, pc, r1
 *   @0x15546c str r2, [sp, #0x4]
 *   @0x155470 mov r0, #2
 *   @0x155474 str r3, [sp, #0x10]
 *   @0x155478 mov r2, #0
 *   @0x15547c mov r3, #0
 *   @0x155480 movt r3, #0x3ff0
 *   @0x155484 vstr d7, [sp, #8]
 *   @0x155488 bl 0x154a70 <_Z19YYIAPEventsDispatchv+0xe88>
 *   @0x15548c bl 0x1531cc <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x1d8>
 *   @0x155490 b 0x155438 <_Z27YYIAPProductDetailsReceivedPKc+0x50>
 *   @0x155494 eorseq pc, r2, r0, asr r6
 *   @0x155498 eoreq r8, r9, r0, lsr #10
 *   @0x15549c ldrsheq r0, [pc], -r4
 *   @0x1554a0 eorseq pc, r2, r4, lsl #12
 *   @0x1554a4 andseq r0, pc, r0, lsr #27
 *   @0x1554a8 andseq r0, pc, r0, asr #25
 *
 * ══ §52/156 Graphics_Bitmap32::Color_Merge(unsigned int, unsigned int, double)  0x165ce8  size 196  49 条（0x165ce8..0x165dac）
 * @func 0x165ce8 0x165dac  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8×3
 * 字段偏移 top8: 无
 * VFP 指令 29 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x165ce8 push {r3, r4, r5, r6, r7, lr}
 *   @0x165cec vpush {d8, d9}
 *   @0x165cf0 mov r4, r1
 *   @0x165cf4 uxtb r1, r1
 *   @0x165cf8 vmov d8, r2, r3
 *   @0x165cfc uxtb r3, r0
 *   @0x165d00 mov r5, r0
 *   @0x165d04 vmov s14, r1
 *   @0x165d08 vmov.f64 d9, #1.000000e+00
 *   @0x165d0c vmov s12, r3
 *   @0x165d10 vcvt.f64.s32 d7, s14
 *   @0x165d14 vmul.f64 d7, d7, d8
 *   @0x165d18 vsub.f64 d9, d9, d8
 *   @0x165d1c vcvt.f64.s32 d6, s12
 *   @0x165d20 vmov.f64 d5, d7
 *   @0x165d24 vmla.f64 d5, d6, d9
 *   @0x165d28 vmov r0, r1, d5
 *   @0x165d2c bl 0xb66e8 <lrint@plt>
 *   @0x165d30 ubfx r1, r4, #0x8, #0x8
 *   @0x165d34 ubfx r3, r5, #0x8, #0x8
 *   @0x165d38 ubfx r4, r4, #0x10, #0x8
 *   @0x165d3c vmov s14, r1
 *   @0x165d40 ubfx r5, r5, #0x10, #0x8
 *   @0x165d44 vmov s12, r3
 *   @0x165d48 vcvt.f64.s32 d7, s14
 *   @0x165d4c vmul.f64 d7, d7, d8
 *   @0x165d50 vcvt.f64.s32 d6, s12
 *   @0x165d54 mov r6, r0
 *   @0x165d58 vmov.f64 d5, d7
 *   @0x165d5c vmla.f64 d5, d9, d6
 *   @0x165d60 vmov r0, r1, d5
 *   @0x165d64 bl 0xb66e8 <lrint@plt>
 *   @0x165d68 vmov s11, r4
 *   @0x165d6c vcvt.f64.s32 d6, s11
 *   @0x165d70 vmul.f64 d8, d6, d8
 *   @0x165d74 vmov s12, r5
 *   @0x165d78 vcvt.f64.s32 d7, s12
 *   @0x165d7c mov r7, r0
 *   @0x165d80 lsl r7, r7, #8
 *   @0x165d84 vmov.f64 d5, d8
 *   @0x165d88 uxth r7, r7
 *   @0x165d8c uxtab r6, r7, r6
 *   @0x165d90 vmla.f64 d5, d9, d7
 *   @0x165d94 vmov r0, r1, d5
 *   @0x165d98 bl 0xb66e8 <lrint@plt>
 *   @0x165d9c vpop {d8, d9}
 *   @0x165da0 uxtb r0, r0
 *   @0x165da4 add r0, r6, r0, lsl #16
 *   @0x165da8 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §53/156 GR_D3D_Set_Texture_Repeat(bool)  0x168870  size 196  49 条（0x168870..0x168934）
 * @func 0x168870 0x168934  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x16887c→0x489794, 0x168888→0x4859c8, 0x1688d8→0x4859c8
 * 调用序列: RenderStateManager::SetSamplerState(int, eSamplerState, unsigned int)×4
 * 字段偏移 top8: 0xa8×2 / 0xa0×1 / 0x50×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x168870 push {r3, r4, r5, r6, r7, lr}
 *   @0x168874 cmp r0, #0
 *   @0x168878 ldr r3, [pc, #0xa8]
 *   @0x16887c ldr r1, [pc, #0xa8]
 *   @0x168880 add r3, pc, r3
 *   @0x168884 beq 0x1688d8 <_Z25GR_D3D_Set_Texture_Repeatb+0x68>
 *   @0x168888 ldr r2, [pc, #0xa0]
 *   @0x16888c mov r4, #0
 *   @0x168890 ldr r6, [r3, r1]
 *   @0x168894 mov r7, #1
 *   @0x168898 ldr r5, [r3, r2]
 *   @0x16889c mov r1, r4
 *   @0x1688a0 strb r7, [r6, r4]
 *   @0x1688a4 mov r0, r5
 *   @0x1688a8 mov r2, #2
 *   @0x1688ac mov r3, #0
 *   @0x1688b0 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x1688b4 mov r1, r4
 *   @0x1688b8 mov r0, r5
 *   @0x1688bc add r4, r4, #1
 *   @0x1688c0 mov r2, #3
 *   @0x1688c4 mov r3, #0
 *   @0x1688c8 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x1688cc cmp r4, #8
 *   @0x1688d0 bne 0x16889c <_Z25GR_D3D_Set_Texture_Repeatb+0x2c>
 *   @0x1688d4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1688d8 ldr r2, [pc, #0x50]
 *   @0x1688dc mov r4, r0
 *   @0x1688e0 ldr r6, [r3, r1]
 *   @0x1688e4 mov r7, r0
 *   @0x1688e8 ldr r5, [r3, r2]
 *   @0x1688ec mov r1, r4
 *   @0x1688f0 strb r7, [r6, r4]
 *   @0x1688f4 mov r0, r5
 *   @0x1688f8 mov r2, #2
 *   @0x1688fc mov r3, #1
 *   @0x168900 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x168904 mov r1, r4
 *   @0x168908 mov r0, r5
 *   @0x16890c add r4, r4, #1
 *   @0x168910 mov r2, #3
 *   @0x168914 mov r3, #1
 *   @0x168918 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x16891c cmp r4, #8
 *   @0x168920 bne 0x1688ec <_Z25GR_D3D_Set_Texture_Repeatb+0x7c>
 *   @0x168924 pop {r3, r4, r5, r6, r7, pc}
 *   @0x168928 .word 0x002893d0
 *   @0x16892c .word 0xffffe4bc
 *   @0x168930 .word 0xffffc0a8
 *
 * ══ §54/156 GR_D3D_Finish_Frame(bool)  0x169a58  size 196  49 条（0x169a58..0x169b1c）
 * @func 0x169a58 0x169b1c  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x169a64→0x4a22b1, 0x169a7c→0x757e7c, 0x169aac→0x4a2028, 0x169ad4→0x757e80, 0x169af0→0x757e80
 * 调用序列: Timing_Time×2 / Graphics::SceneEnd() / CProfiler::Pop() / Graphics::Flip() / CProfiler::Push(int, int)
 * 字段偏移 top8: 0xa0×2 / 0x8c×1 / 0x60×1 / 0x3c×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x169a58 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x169a5c mov r9, r0
 *   @0x169a60 ldr r6, [pc, #0xa0]
 *   @0x169a64 ldr r3, [pc, #0xa0]
 *   @0x169a68 add r6, pc, r6
 *   @0x169a6c ldr r3, [r6, r3]
 *   @0x169a70 ldrb r7, [r3]
 *   @0x169a74 cmp r7, #0
 *   @0x169a78 beq 0x169acc <_Z19GR_D3D_Finish_Frameb+0x74>
 *   @0x169a7c ldr r3, [pc, #0x8c]
 *   @0x169a80 ldr r8, [r6, r3]
 *   @0x169a84 ldrb r3, [r8]
 *   @0x169a88 cmp r3, #0
 *   @0x169a8c bne 0x169af0 <_Z19GR_D3D_Finish_Frameb+0x98>
 *   @0x169a90 bl 0x17de74 <_ZN8Graphics8SceneEndEv>
 *   @0x169a94 bl 0x215148 <Timing_Time>
 *   @0x169a98 cmp r9, #0
 *   @0x169a9c mov r4, r0
 *   @0x169aa0 mov r5, r1
 *   @0x169aa4 bne 0x169ae8 <_Z19GR_D3D_Finish_Frameb+0x90>
 *   @0x169aa8 bl 0x215148 <Timing_Time>
 *   @0x169aac ldr r3, [pc, #0x60]
 *   @0x169ab0 ldrb r2, [r8]
 *   @0x169ab4 ldr r3, [r6, r3]
 *   @0x169ab8 subs r0, r0, r4
 *   @0x169abc sbc r1, r1, r5
 *   @0x169ac0 cmp r2, #0
 *   @0x169ac4 strd r0, r1, [r3]
 *   @0x169ac8 bne 0x169ad4 <_Z19GR_D3D_Finish_Frameb+0x7c>
 *   @0x169acc mov r0, r7
 *   @0x169ad0 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x169ad4 ldr r3, [pc, #0x3c]
 *   @0x169ad8 ldr r0, [r6, r3]
 *   @0x169adc bl 0x2a08ac <_ZN9CProfiler3PopEv>
 *   @0x169ae0 mov r0, r7
 *   @0x169ae4 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x169ae8 bl 0x17df14 <_ZN8Graphics4FlipEv>
 *   @0x169aec b 0x169aa8 <_Z19GR_D3D_Finish_Frameb+0x50>
 *   @0x169af0 ldr r3, [pc, #0x20]
 *   @0x169af4 mov r1, #6
 *   @0x169af8 mov r2, #26
 *   @0x169afc ldr r0, [r6, r3]
 *   @0x169b00 bl 0x2a0738 <_ZN9CProfiler4PushEii>
 *   @0x169b04 b 0x169a90 <_Z19GR_D3D_Finish_Frameb+0x38>
 *   @0x169b08 eoreq r8, r8, r8, ror #3
 *   @0x169b0c .word 0xffffe4d0
 *   @0x169b10 .word 0xffffbf18
 *   @0x169b14 .word 0xffffe518
 *   @0x169b18 .word 0xffffbf1c
 *
 * ══ §55/156 GR_Color_Merge(unsigned int, unsigned int, float)  0x16caa8  size 196  49 条（0x16caa8..0x16cb6c）
 * @func 0x16caa8 0x16cb6c  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8×3
 * 字段偏移 top8: 无
 * VFP 指令 29 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16caa8 push {r3, r4, r5, r6, r7, lr}
 *   @0x16caac vpush {d8}
 *   @0x16cab0 uxtb r3, r1
 *   @0x16cab4 vmov.f32 s17, #1.000000e+00
 *   @0x16cab8 mov r4, r1
 *   @0x16cabc vmov s15, r3
 *   @0x16cac0 uxtb r3, r0
 *   @0x16cac4 vmov s16, r2
 *   @0x16cac8 mov r5, r0
 *   @0x16cacc vmov s14, r3
 *   @0x16cad0 vcvt.f32.s32 s15, s15
 *   @0x16cad4 vmul.f32 s15, s15, s16
 *   @0x16cad8 vsub.f32 s17, s17, s16
 *   @0x16cadc vcvt.f32.s32 s14, s14
 *   @0x16cae0 vmla.f32 s15, s14, s17
 *   @0x16cae4 vcvt.f64.f32 d6, s15
 *   @0x16cae8 vmov r0, r1, d6
 *   @0x16caec bl 0xb66e8 <lrint@plt>
 *   @0x16caf0 ubfx r3, r4, #0x8, #0x8
 *   @0x16caf4 ubfx r4, r4, #0x10, #0x8
 *   @0x16caf8 vmov s15, r3
 *   @0x16cafc ubfx r3, r5, #0x8, #0x8
 *   @0x16cb00 ubfx r5, r5, #0x10, #0x8
 *   @0x16cb04 vcvt.f32.s32 s15, s15
 *   @0x16cb08 vmov s14, r3
 *   @0x16cb0c vmul.f32 s15, s15, s16
 *   @0x16cb10 vcvt.f32.s32 s14, s14
 *   @0x16cb14 vmla.f32 s15, s17, s14
 *   @0x16cb18 mov r6, r0
 *   @0x16cb1c vcvt.f64.f32 d6, s15
 *   @0x16cb20 vmov r0, r1, d6
 *   @0x16cb24 bl 0xb66e8 <lrint@plt>
 *   @0x16cb28 vmov s13, r4
 *   @0x16cb2c vcvt.f32.s32 s14, s13
 *   @0x16cb30 vmul.f32 s16, s14, s16
 *   @0x16cb34 vmov s14, r5
 *   @0x16cb38 vcvt.f32.s32 s15, s14
 *   @0x16cb3c vmla.f32 s16, s17, s15
 *   @0x16cb40 mov r7, r0
 *   @0x16cb44 lsl r7, r7, #8
 *   @0x16cb48 uxth r7, r7
 *   @0x16cb4c uxtab r6, r7, r6
 *   @0x16cb50 vcvt.f64.f32 d6, s16
 *   @0x16cb54 vmov r0, r1, d6
 *   @0x16cb58 bl 0xb66e8 <lrint@plt>
 *   @0x16cb5c vpop {d8}
 *   @0x16cb60 uxtb r0, r0
 *   @0x16cb64 add r0, r6, r0, lsl #16
 *   @0x16cb68 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §56/156 YYGML_draw_surface_part_ext(int, float, float, float, float, float, float, float, float, int, float)  0x171ee0  size 196  49 条（0x171ee0..0x171fa4）
 * @func 0x171ee0 0x171fa4  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Texture_Draw_Part(int, float, float, float, float, float, float, float, float, float, unsigned int, float) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x4×4 / 0x18×2 / 0xb4×1 / 0x-4×1 / 0x3×1 / 0x8×1 / 0xc×1 / 0x3c×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x171ee0 ldr r12, [pc, #0xb4]
 *   @0x171ee4 str lr, [sp, #-0x4]!
 *   @0x171ee8 ldr r12, [pc, r12]
 *   @0x171eec sub sp, sp, #36
 *   @0x171ef0 ldm r12, {r12, lr}
 *   @0x171ef4 and lr, r0, lr
 *   @0x171ef8 ldr r12, [r12, lr, lsl #3]
 *   @0x171efc cmp r12, #0
 *   @0x171f00 bne 0x171f14 <_Z27YYGML_draw_surface_part_extiffffffffif+0x34>
 *   @0x171f04 b 0x171f80 <_Z27YYGML_draw_surface_part_extiffffffffif+0xa0>
 *   @0x171f08 ldr r12, [r12, #0x4]
 *   @0x171f0c cmp r12, #0
 *   @0x171f10 beq 0x171f80 <_Z27YYGML_draw_surface_part_extiffffffffif+0xa0>
 *   @0x171f14 ldr lr, [r12, #0x8]
 *   @0x171f18 cmp r0, lr
 *   @0x171f1c bne 0x171f08 <_Z27YYGML_draw_surface_part_extiffffffffif+0x28>
 *   @0x171f20 ldr r0, [r12, #0xc]
 *   @0x171f24 cmp r0, #0
 *   @0x171f28 beq 0x171f80 <_Z27YYGML_draw_surface_part_extiffffffffif+0xa0>
 *   @0x171f2c ldr lr, [sp, #0x3c]
 *   @0x171f30 vldr s15, [sp, #40]
 *   @0x171f34 ldr r0, [r0, #0x4]
 *   @0x171f38 mov r12, #0
 *   @0x171f3c vstr s15, [sp]
 *   @0x171f40 str r12, [sp, #0x14]
 *   @0x171f44 vldr s15, [sp, #44]
 *   @0x171f48 str lr, [sp, #0x18]
 *   @0x171f4c vstr s15, [sp, #4]
 *   @0x171f50 vldr s15, [sp, #48]
 *   @0x171f54 vstr s15, [sp, #8]
 *   @0x171f58 vldr s15, [sp, #52]
 *   @0x171f5c vstr s15, [sp, #12]
 *   @0x171f60 vldr s15, [sp, #56]
 *   @0x171f64 vstr s15, [sp, #16]
 *   @0x171f68 vldr s15, [sp, #64]
 *   @0x171f6c vstr s15, [sp, #28]
 *   @0x171f70 bl 0x175208 <_Z20GR_Texture_Draw_Partifffffffffjf>
 *   @0x171f74 mov r0, #1
 *   @0x171f78 add sp, sp, #36
 *   @0x171f7c ldr pc, [sp], #4
 *   @0x171f80 ldr r0, [pc, #0x18]
 *   @0x171f84 mov r1, #0
 *   @0x171f88 add r0, pc, r0
 *   @0x171f8c bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x171f90 mov r0, #0
 *   @0x171f94 add sp, sp, #36
 *   @0x171f98 ldr pc, [sp], #4
 *   @0x171f9c eoreq r11, r7, r8, lsr #24
 *   @0x171fa0 andseq r8, r12, r0, ror #5
 *
 * ══ §57/156 GR_Texture_Create_And_Fill(int, int, unsigned char*, unsigned int)  0x173c18  size 196  49 条（0x173c18..0x173cdc）
 * @func 0x173c18 0x173cdc  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: AllocTexture() / Graphics::CreateTextureFromFile(unsigned char*, unsigned int, ImageInfo*, eTextureFormat, bool) / Graphics::CreateTextureFromData(unsigned char*, int, int, ImageInfo*, eTextureFormat)
 * 字段偏移 top8: 0x4×2 / 0x60×1 / 0x2×1 / 0x6×1 / 0x10×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x173c18 push {r4, r5, r6, r7, r8, lr}
 *   @0x173c1c sub sp, sp, #40
 *   @0x173c20 mov r7, r3
 *   @0x173c24 mov r5, r0
 *   @0x173c28 mov r4, r1
 *   @0x173c2c mov r8, r2
 *   @0x173c30 bl 0x173944 <_Z12AllocTexturev>
 *   @0x173c34 mul r3, r4, r5
 *   @0x173c38 cmp r7, r3, lsl #2
 *   @0x173c3c mov r6, r0
 *   @0x173c40 mov r0, r8
 *   @0x173c44 beq 0x173cb8 <_Z26GR_Texture_Create_And_FilliiPhj+0xa0>
 *   @0x173c48 mov r1, r7
 *   @0x173c4c mov r3, #0
 *   @0x173c50 add r2, sp, #12
 *   @0x173c54 str r3, [sp]
 *   @0x173c58 mov r3, #6
 *   @0x173c5c bl 0x182f3c <_ZN8Graphics21CreateTextureFromFileEPhjP9ImageInfo14eTextureFormatb>
 *   @0x173c60 mov r1, r0
 *   @0x173c64 vmov.f32 s15, #1.000000e+00
 *   @0x173c68 vldr s13, [sp, #16]
 *   @0x173c6c vldr s12, [sp, #12]
 *   @0x173c70 ldr r3, [pc, #0x60]
 *   @0x173c74 mov r0, r6
 *   @0x173c78 mov r2, #1
 *   @0x173c7c ldr r3, [pc, r3]
 *   @0x173c80 ldr r3, [r3, #0x4]
 *   @0x173c84 ldr r3, [r3, r6, lsl #2]
 *   @0x173c88 vcvt.f32.u32 s14, s12
 *   @0x173c8c strh r5, [r3, #4]
 *   @0x173c90 strh r4, [r3, #6]
 *   @0x173c94 strb r2, [r3, #0x10]
 *   @0x173c98 str r1, [r3]
 *   @0x173c9c vcvt.f32.u32 s13, s13
 *   @0x173ca0 vdiv.f32 s14, s15, s14
 *   @0x173ca4 vdiv.f32 s15, s15, s13
 *   @0x173ca8 vstr s14, [r3, #8]
 *   @0x173cac vstr s15, [r3, #12]
 *   @0x173cb0 add sp, sp, #40
 *   @0x173cb4 pop {r4, r5, r6, r7, r8, pc}
 *   @0x173cb8 mov r3, #6
 *   @0x173cbc mov r1, r5
 *   @0x173cc0 str r3, [sp]
 *   @0x173cc4 mov r2, r4
 *   @0x173cc8 add r3, sp, #12
 *   @0x173ccc bl 0x183188 <_ZN8Graphics21CreateTextureFromDataEPhiiP9ImageInfo14eTextureFormat>
 *   @0x173cd0 mov r1, r0
 *   @0x173cd4 b 0x173c64 <_Z26GR_Texture_Create_And_FilliiPhj+0x4c>
 *   @0x173cd8 eoreq r9, r7, r0, lsr #25
 *
 * ══ §58/156 GR_Window_Set_Caption(char const*, bool)  0x17ae38  size 196  49 条（0x17ae38..0x17aefc）
 * @func 0x17ae38 0x17aefc  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Window_Set_Caption(char const*, bool)+0x30 / MemoryManager::Free(void const*) / 0xb6538 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65bc / GR_Window_Set_CaptionM(char const*, bool)
 * 字段偏移 top8: 0xb0×1 / 0x4×1 / 0x64×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17ae38 ldr r3, [pc, #0xb0]
 *   @0x17ae3c push {r4, r5, r6, r7, lr}
 *   @0x17ae40 ldr r3, [pc, r3]
 *   @0x17ae44 sub sp, sp, #12
 *   @0x17ae48 mov r4, r0
 *   @0x17ae4c ldr r3, [r3]
 *   @0x17ae50 mov r6, r1
 *   @0x17ae54 sub r3, r3, #2
 *   @0x17ae58 cmp r3, #1
 *   @0x17ae5c bls 0x17ae68 <_Z21GR_Window_Set_CaptionPKcb+0x30>
 *   @0x17ae60 cmp r1, #0
 *   @0x17ae64 beq 0x17aee8 <_Z21GR_Window_Set_CaptionPKcb+0xb0>
 *   @0x17ae68 cmp r4, #0
 *   @0x17ae6c mov r3, #0
 *   @0x17ae70 strh r3, [sp, #4]
 *   @0x17ae74 beq 0x17ae84 <_Z21GR_Window_Set_CaptionPKcb+0x4c>
 *   @0x17ae78 ldrb r3, [r4]
 *   @0x17ae7c cmp r3, #0
 *   @0x17ae80 bne 0x17ae88 <_Z21GR_Window_Set_CaptionPKcb+0x50>
 *   @0x17ae84 add r4, sp, #4
 *   @0x17ae88 ldr r5, [pc, #0x64]
 *   @0x17ae8c ldr r5, [pc, r5]
 *   @0x17ae90 ldr r0, [r5]
 *   @0x17ae94 cmp r0, #0
 *   @0x17ae98 beq 0x17aea0 <_Z21GR_Window_Set_CaptionPKcb+0x68>
 *   @0x17ae9c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x17aea0 mov r0, r4
 *   @0x17aea4 mov r3, #0
 *   @0x17aea8 str r3, [r5]
 *   @0x17aeac bl 0xb6538 <strlen@plt>
 *   @0x17aeb0 mov r3, #1
 *   @0x17aeb4 ldr r1, [pc, #0x3c]
 *   @0x17aeb8 movw r2, #0x3a7
 *   @0x17aebc add r1, pc, r1
 *   @0x17aec0 add r7, r0, r3
 *   @0x17aec4 mov r0, r7
 *   @0x17aec8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x17aecc mov r1, r4
 *   @0x17aed0 mov r2, r7
 *   @0x17aed4 str r0, [r5]
 *   @0x17aed8 bl 0xb65bc <memcpy@plt>
 *   @0x17aedc mov r0, r4
 *   @0x17aee0 mov r1, r6
 *   @0x17aee4 bl 0x17af2c <_Z22GR_Window_Set_CaptionMPKcb>
 *   @0x17aee8 add sp, sp, #12
 *   @0x17aeec pop {r4, r5, r6, r7, pc}
 *   @0x17aef0 eoreq r5, r7, r0, ror #9
 *   @0x17aef4 .word 0x00273bf4
 *   @0x17aef8 mulseq sp, r8, r6
 *
 * ══ §59/156 UpdateCurrentTextureSettings(int)  0x180ed4  size 196  49 条（0x180ed4..0x180f98）
 * @func 0x180ed4 0x180f98  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x180ee0→0x3f26dc, 0x180ef8→0x4a2f28, 0x180f0c→0x4a2f24, 0x180f30→0x4a2f20, 0x180f44→0x479ac0, 0x180f64→0x4a2f28
 * 调用序列: _SetCurrentTextureSettings()
 * 字段偏移 top8: 0x9c×2 / 0x88×1 / 0x78×1 / 0x58×1 / 0x48×1 / 0x1c×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x180ed4 push {r4, r5, r6, lr}
 *   @0x180ed8 mov r6, r0
 *   @0x180edc ldr r4, [pc, #0x9c]
 *   @0x180ee0 ldr r3, [pc, #0x9c]
 *   @0x180ee4 add r4, pc, r4
 *   @0x180ee8 ldr r5, [r4, r3]
 *   @0x180eec ldr r3, [r5]
 *   @0x180ef0 cmp r3, #0
 *   @0x180ef4 bne 0x180f28 <_Z28UpdateCurrentTextureSettingsi+0x54>
 *   @0x180ef8 ldr r3, [pc, #0x88]
 *   @0x180efc ldr r3, [r4, r3]
 *   @0x180f00 ldr r3, [r3]
 *   @0x180f04 cmp r3, #0
 *   @0x180f08 popeq {r4, r5, r6, pc}
 *   @0x180f0c ldr r3, [pc, #0x78]
 *   @0x180f10 ldr r3, [r4, r3]
 *   @0x180f14 ldr r3, [r3]
 *   @0x180f18 cmp r3, #0
 *   @0x180f1c popeq {r4, r5, r6, pc}
 *   @0x180f20 bl 0x180b28 <_Z26_SetCurrentTextureSettingsv>
 *   @0x180f24 ldr r3, [r5]
 *   @0x180f28 cmp r3, #1
 *   @0x180f2c popne {r4, r5, r6, pc}
 *   @0x180f30 ldr r3, [pc, #0x58]
 *   @0x180f34 ldr r5, [r4, r3]
 *   @0x180f38 ldr r3, [r5]
 *   @0x180f3c cmp r3, r6
 *   @0x180f40 beq 0x180f64 <_Z28UpdateCurrentTextureSettingsi+0x90>
 *   @0x180f44 ldr r3, [pc, #0x48]
 *   @0x180f48 add r0, r6, #33792
 *   @0x180f4c str r6, [r5]
 *   @0x180f50 add r0, r0, #192
 *   @0x180f54 ldr r3, [r4, r3]
 *   @0x180f58 ldr r3, [r3]
 *   @0x180f5c blx r3
 *   @0x180f60 ldr r6, [r5]
 *   @0x180f64 ldr r3, [pc, #0x1c]
 *   @0x180f68 ldr r3, [r4, r3]
 *   @0x180f6c ldr r3, [r3, r6, lsl #2]
 *   @0x180f70 cmp r3, #0
 *   @0x180f74 popeq {r4, r5, r6, pc}
 *   @0x180f78 pop {r4, r5, r6, lr}
 *   @0x180f7c b 0x180b28 <_Z26_SetCurrentTextureSettingsv>
 *   @0x180f80 eoreq r0, r7, r12, ror #26
 *   @0x180f84 .word 0xffffe7b8
 *   @0x180f88 .word 0xffffe8e8
 *   @0x180f8c .word 0xffffe8f4
 *   @0x180f90 .word 0xffffe808
 *   @0x180f94 .word 0xffffbbf0
 *
 * ══ §60/156 Graphics::CreateTextureFromFile(unsigned char*, unsigned int, ImageInfo*, eTextureFormat, bool)  0x182f3c  size 196  49 条（0x182f3c..0x183000）
 * @func 0x182f3c 0x183000  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / _SetTextureInfo(Texture*)
 * 字段偏移 top8: 0x4×3 / 0x8×3 / 0x20×2 / 0xc×2 / 0x18×2 / 0x98×1 / 0x2c×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x182f3c push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x182f40 mov r6, r0
 *   @0x182f44 mov r0, #56
 *   @0x182f48 mov r5, r2
 *   @0x182f4c mov r7, r1
 *   @0x182f50 mov r8, r3
 *   @0x182f54 ldrb r9, [sp, #0x20]
 *   @0x182f58 bl 0x27c524 <_Znwj>
 *   @0x182f5c ldr r12, [pc, #0x98]
 *   @0x182f60 mvn r2, #0
 *   @0x182f64 cmp r9, #0
 *   @0x182f68 ldr r12, [pc, r12]
 *   @0x182f6c ldr r3, [r12]
 *   @0x182f70 mov r4, r0
 *   @0x182f74 str r6, [r0, #0x2c]
 *   @0x182f78 str r4, [r12]
 *   @0x182f7c mov r0, #0
 *   @0x182f80 str r3, [r4, #0x34]
 *   @0x182f84 moveq r3, #2
 *   @0x182f88 str r0, [r4, #0x10]
 *   @0x182f8c str r0, [r4, #0x4]
 *   @0x182f90 streq r3, [r4, #0x10]
 *   @0x182f94 str r0, [r4, #0x8]
 *   @0x182f98 str r0, [r4, #0xc]
 *   @0x182f9c str r0, [r4, #0x24]
 *   @0x182fa0 str r0, [r4, #0x28]
 *   @0x182fa4 mov r0, r4
 *   @0x182fa8 str r2, [r4, #0x14]
 *   @0x182fac str r2, [r4, #0x18]
 *   @0x182fb0 str r2, [r4, #0x1c]
 *   @0x182fb4 str r2, [r4, #0x20]
 *   @0x182fb8 str r7, [r4, #0x30]
 *   @0x182fbc str r8, [r4]
 *   @0x182fc0 bl 0x182e7c <_Z15_SetTextureInfoP7Texture>
 *   @0x182fc4 ldr r3, [r4]
 *   @0x182fc8 ldr r12, [r4, #0x8]
 *   @0x182fcc mov r0, r4
 *   @0x182fd0 ldr r2, [r4, #0x4]
 *   @0x182fd4 cmp r3, #6
 *   @0x182fd8 str r3, [r5, #0x18]
 *   @0x182fdc mov r3, #0
 *   @0x182fe0 movne r1, #16
 *   @0x182fe4 moveq r1, #32
 *   @0x182fe8 str r12, [r5, #0x4]
 *   @0x182fec str r2, [r5]
 *   @0x182ff0 str r3, [r5, #0xc]
 *   @0x182ff4 str r1, [r5, #0x8]
 *   @0x182ff8 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x182ffc eoreq sp, r6, r12, asr #6
 *
 * ══ §61/156 _ReadSaveFile(char const*, int*)  0x18f4d0  size 196  49 条（0x18f4d0..0x18f594）
 * @func 0x18f4d0 0x18f594  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb68d4×2 / 0xb6844 / 0xb6928 / 0xb6958 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb68c8 / 0xb6850
 * 字段偏移 top8: 0xac×1 / 0x4×1 / 0x4c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18f4d0 push {r4, r5, r6, lr}
 *   @0x18f4d4 mov r5, r1
 *   @0x18f4d8 ldr r1, [pc, #0xac]
 *   @0x18f4dc sub sp, sp, #8
 *   @0x18f4e0 add r1, pc, r1
 *   @0x18f4e4 bl 0xb6844 <fopen@plt>
 *   @0x18f4e8 subs r4, r0, #0
 *   @0x18f4ec beq 0x18f584 <_Z13_ReadSaveFilePKcPi+0xb4>
 *   @0x18f4f0 mov r1, #0
 *   @0x18f4f4 mov r3, #32768
 *   @0x18f4f8 mov r2, r1
 *   @0x18f4fc bl 0xb6928 <setvbuf@plt>
 *   @0x18f500 mov r2, #2
 *   @0x18f504 mov r1, #0
 *   @0x18f508 mov r0, r4
 *   @0x18f50c bl 0xb68d4 <fseek@plt>
 *   @0x18f510 add r1, sp, #4
 *   @0x18f514 mov r0, r4
 *   @0x18f518 bl 0xb6958 <fgetpos@plt>
 *   @0x18f51c cmp r5, #0
 *   @0x18f520 mov r1, #0
 *   @0x18f524 mov r0, r4
 *   @0x18f528 ldrne r3, [sp, #0x4]
 *   @0x18f52c mov r2, r1
 *   @0x18f530 strne r3, [r5]
 *   @0x18f534 bl 0xb68d4 <fseek@plt>
 *   @0x18f538 ldr r5, [sp, #0x4]
 *   @0x18f53c ldr r1, [pc, #0x4c]
 *   @0x18f540 mov r2, #112
 *   @0x18f544 cmp r5, #0
 *   @0x18f548 mov r3, #1
 *   @0x18f54c add r1, pc, r1
 *   @0x18f550 movne r0, r5
 *   @0x18f554 moveq r0, #1
 *   @0x18f558 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x18f55c mov r2, r5
 *   @0x18f560 mov r1, #1
 *   @0x18f564 mov r3, r4
 *   @0x18f568 mov r6, r0
 *   @0x18f56c bl 0xb68c8 <fread@plt>
 *   @0x18f570 mov r0, r4
 *   @0x18f574 bl 0xb6850 <fclose@plt>
 *   @0x18f578 mov r0, r6
 *   @0x18f57c add sp, sp, #8
 *   @0x18f580 pop {r4, r5, r6, pc}
 *   @0x18f584 mov r6, r4
 *   @0x18f588 b 0x18f578 <_Z13_ReadSaveFilePKcPi+0xa8>
 *   @0x18f58c andseq r8, r10, r8, lsl r7
 *   @0x18f590 andseq r12, r11, r8, lsl #30
 *
 * ══ §62/156 Speed_Factor()  0x19ff6c  size 196  42 条（0x19ff6c..0x1a0030）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x19ff6c 0x1a0030  size 196  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x19ff74→0x5428e8, 0x19ff8c→0x54298c, 0x19ffa4→0x5428f4, 0x19fffc→0x5428c0
 * 调用序列: Speed_Factor()+0x84×2 / CTimingSource::GetFPS()
 * 字段偏移 top8: 0xa4×2 / 0x90×1 / 0xc×1 / 0x7c×1 / 0x28×1
 * VFP 指令 18 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19ff88 bne 0x19fffc <_Z12Speed_Factorv+0x90>
 *   @0x19ff8c ldr r3, [pc, #0x90]
 *   @0x19ff90 ldr r3, [r4, r3]
 *   @0x19ff94 ldr r3, [r3]
 *   @0x19ff98 ldr r0, [r3, #0xc]
 *   @0x19ff9c cmp r0, #30
 *   @0x19ffa0 ble 0x19fff0 <_Z12Speed_Factorv+0x84>
 *   @0x19ffa4 ldr r3, [pc, #0x7c]
 *   @0x19ffa8 ldr r3, [r4, r3]
 *   @0x19ffac ldr r3, [r3]
 *   @0x19ffb0 cmp r3, #30
 *   @0x19ffb4 ble 0x19fff0 <_Z12Speed_Factorv+0x84>
 *   @0x19ffb8 vmov s12, r0
 *   @0x19ffbc vldr s13, [pc, #84]
 *   @0x19ffc0 vcvt.f32.s32 s15, s12
 *   @0x19ffc4 vmov s12, r3
 *   @0x19ffc8 vcvt.f32.s32 s14, s12
 *   @0x19ffcc vdiv.f32 s12, s15, s14
 *   @0x19ffd0 vcmpe.f32 s12, s13
 *   @0x19ffd4 vmrs APSR_nzcv, fpscr
 *   @0x19ffd8 vmovpl.f32 s15, #3.000000e+01
 *   @0x19ffdc vmovmi.f32 s14, #3.000000e+01
 *   @0x19ffe0 vdivpl.f32 s15, s15, s14
 *   @0x19ffe4 vdivmi.f32 s15, s14, s15
 *   @0x19ffe8 vmov r0, s15
 *   @0x19ffec pop {r4, pc}
 *   @0x19fff0 vmov.f32 s15, #1.000000e+00
 *   @0x19fff4 vmov r0, s15
 *   @0x19fff8 pop {r4, pc}
 *   @0x19fffc ldr r3, [pc, #0x28]
 *   @0x1a0000 ldr r0, [r4, r3]
 *   @0x1a0004 bl 0x214808 <_ZN13CTimingSource6GetFPSEv>
 *   @0x1a0008 vmov d7, r0, r1
 *   @0x1a000c vcvt.s32.f64 s15, d7
 *   @0x1a0010 vmov r0, s15
 *   @0x1a0014 b 0x19ff9c <_Z12Speed_Factorv+0x30>
 *   @0x1a0018 svclo #0x99999a
 *   @0x1a001c .word 0x00251cd8
 *   @0x1a0020 .word 0xffffbcd4
 *   @0x1a0024 .word 0xffffbcd8
 *   @0x1a0028 .word 0xffffeb1c
 *   @0x1a002c .word 0xffffbcdc
 *
 * ══ §63/156 cARRAY_CLASS<SRecordingInfo*>::~cARRAY_CLASS()  0x215c8c  size 196  49 条（0x215c8c..0x215d50）
 * @func 0x215c8c 0x215d50  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / cARRAY_CLASS<SRecordingInfo*>::~cARRAY_CLASS()+0x94 / operator delete(void*) / cARRAY_CLASS<SRecordingInfo*>::~cARRAY_CLASS()+0x30
 * 字段偏移 top8: 0x4×5 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x215c8c ldr r12, [r0]
 *   @0x215c90 push {r4, r5, r6, r7, r8, lr}
 *   @0x215c94 cmp r12, #0
 *   @0x215c98 mov r6, r0
 *   @0x215c9c beq 0x215d38 <_ZN12cARRAY_CLASSIP14SRecordingInfoED2Ev+0xac>
 *   @0x215ca0 ldr r5, [r0, #0x4]
 *   @0x215ca4 cmp r5, #0
 *   @0x215ca8 beq 0x215d40 <_ZN12cARRAY_CLASSIP14SRecordingInfoED2Ev+0xb4>
 *   @0x215cac cmp r12, #0
 *   @0x215cb0 ble 0x215d20 <_ZN12cARRAY_CLASSIP14SRecordingInfoED2Ev+0x94>
 *   @0x215cb4 mov r4, #0
 *   @0x215cb8 mov r8, r4
 *   @0x215cbc ldr r1, [r5]
 *   @0x215cc0 movw r3, #0xfeee
 *   @0x215cc4 movt r3, #0xfeee
 *   @0x215cc8 movw r2, #0xfeee
 *   @0x215ccc cmp r1, r3
 *   @0x215cd0 movt r2, #0xfeee
 *   @0x215cd4 lsl r7, r4, #2
 *   @0x215cd8 beq 0x215d14 <_ZN12cARRAY_CLASSIP14SRecordingInfoED2Ev+0x88>
 *   @0x215cdc ldr r3, [r5, r4, lsl #2]
 *   @0x215ce0 add r1, r5, r7
 *   @0x215ce4 cmp r3, #0
 *   @0x215ce8 mov r0, r3
 *   @0x215cec beq 0x215d14 <_ZN12cARRAY_CLASSIP14SRecordingInfoED2Ev+0x88>
 *   @0x215cf0 ldr r3, [r3]
 *   @0x215cf4 cmp r3, r2
 *   @0x215cf8 beq 0x215d0c <_ZN12cARRAY_CLASSIP14SRecordingInfoED2Ev+0x80>
 *   @0x215cfc bl 0x27d1d0 <_ZdlPv>
 *   @0x215d00 ldr r1, [r6, #0x4]
 *   @0x215d04 ldr r12, [r6]
 *   @0x215d08 add r1, r1, r7
 *   @0x215d0c str r8, [r1]
 *   @0x215d10 ldr r5, [r6, #0x4]
 *   @0x215d14 add r4, r4, #1
 *   @0x215d18 cmp r4, r12
 *   @0x215d1c blt 0x215cbc <_ZN12cARRAY_CLASSIP14SRecordingInfoED2Ev+0x30>
 *   @0x215d20 mov r0, r5
 *   @0x215d24 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x215d28 mov r3, #0
 *   @0x215d2c str r3, [r6, #0x4]
 *   @0x215d30 mov r3, #0
 *   @0x215d34 str r3, [r6]
 *   @0x215d38 mov r0, r6
 *   @0x215d3c pop {r4, r5, r6, r7, r8, pc}
 *   @0x215d40 mov r0, r5
 *   @0x215d44 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x215d48 str r5, [r6, #0x4]
 *   @0x215d4c b 0x215d30 <_ZN12cARRAY_CLASSIP14SRecordingInfoED2Ev+0xa4>
 *
 * ══ §64/156 Audio_FalloffSet(int)  0x217a80  size 196  49 条（0x217a80..0x217b44）
 * @func 0x217a80 0x217b44  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×2 / 0xac×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x217a80 push {r3, lr}
 *   @0x217a84 ldr r3, [pc, #0xac]
 *   @0x217a88 ldr r3, [pc, r3]
 *   @0x217a8c ldrb r3, [r3]
 *   @0x217a90 cmp r3, #0
 *   @0x217a94 popne {r3, pc}
 *   @0x217a98 cmp r0, #6
 *   @0x217a9c addls pc, pc, r0, lsl #2
 *   @0x217aa0 b 0x217b14 <_Z16Audio_FalloffSeti+0x94>
 *   @0x217aa4 b 0x217acc <_Z16Audio_FalloffSeti+0x4c>
 *   @0x217aa8 b 0x217ad8 <_Z16Audio_FalloffSeti+0x58>
 *   @0x217aac b 0x217ae4 <_Z16Audio_FalloffSeti+0x64>
 *   @0x217ab0 b 0x217af0 <_Z16Audio_FalloffSeti+0x70>
 *   @0x217ab4 b 0x217afc <_Z16Audio_FalloffSeti+0x7c>
 *   @0x217ab8 b 0x217b08 <_Z16Audio_FalloffSeti+0x88>
 *   @0x217abc b 0x217ac0 <_Z16Audio_FalloffSeti+0x40>
 *   @0x217ac0 movw r0, #0xd006
 *   @0x217ac4 pop {r3, lr}
 *   @0x217ac8 b 0xb6aa8 <alDistanceModel@plt>
 *   @0x217acc mov r0, #0
 *   @0x217ad0 pop {r3, lr}
 *   @0x217ad4 b 0xb6aa8 <alDistanceModel@plt>
 *   @0x217ad8 movw r0, #0xd001
 *   @0x217adc pop {r3, lr}
 *   @0x217ae0 b 0xb6aa8 <alDistanceModel@plt>
 *   @0x217ae4 movw r0, #0xd002
 *   @0x217ae8 pop {r3, lr}
 *   @0x217aec b 0xb6aa8 <alDistanceModel@plt>
 *   @0x217af0 movw r0, #0xd003
 *   @0x217af4 pop {r3, lr}
 *   @0x217af8 b 0xb6aa8 <alDistanceModel@plt>
 *   @0x217afc movw r0, #0xd004
 *   @0x217b00 pop {r3, lr}
 *   @0x217b04 b 0xb6aa8 <alDistanceModel@plt>
 *   @0x217b08 movw r0, #0xd005
 *   @0x217b0c pop {r3, lr}
 *   @0x217b10 b 0xb6aa8 <alDistanceModel@plt>
 *   @0x217b14 ldr r3, [pc, #0x20]
 *   @0x217b18 ldr r1, [pc, #0x20]
 *   @0x217b1c ldr r3, [pc, r3]
 *   @0x217b20 add r1, pc, r1
 *   @0x217b24 ldr r0, [r3]
 *   @0x217b28 ldr r3, [r0]
 *   @0x217b2c ldr r3, [r3, #0xc]
 *   @0x217b30 blx r3
 *   @0x217b34 pop {r3, pc}
 *   @0x217b38 andseq r7, sp, r4, asr #11
 *   @0x217b3c ldrsheq r5, [sp], -r8
 *   @0x217b40 andseq r12, r3, r12, lsl #2
 *
 * ══ §65/156 Audio_ReleaseEmitter(int)  0x21a2f8  size 196  49 条（0x21a2f8..0x21a3bc）
 * @func 0x21a2f8 0x21a3bc  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_ReleaseEmitter(int)+0xa4×2 / Audio_StopSound(int)
 * 字段偏移 top8: 0x2×2 / 0x34×2 / 0xb4×1 / 0xa0×1 / 0x40×1 / 0x44×1 / 0x38×1 / 0x5×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21a2f8 ldr r3, [pc, #0xb4]
 *   @0x21a2fc push {r4, r5, r6, lr}
 *   @0x21a300 ldr r3, [pc, r3]
 *   @0x21a304 ldrb r3, [r3]
 *   @0x21a308 cmp r3, #0
 *   @0x21a30c popeq {r4, r5, r6, pc}
 *   @0x21a310 ldr r3, [pc, #0xa0]
 *   @0x21a314 add r3, pc, r3
 *   @0x21a318 ldr r4, [r3, #0x40]
 *   @0x21a31c cmp r4, r0
 *   @0x21a320 movgt r4, #0
 *   @0x21a324 movle r4, #1
 *   @0x21a328 orrs r4, r4, r0, lsr #31
 *   @0x21a32c popne {r4, r5, r6, pc}
 *   @0x21a330 ldr r3, [r3, #0x44]
 *   @0x21a334 ldr r5, [r3, r0, lsl #2]
 *   @0x21a338 cmp r5, #0
 *   @0x21a33c popeq {r4, r5, r6, pc}
 *   @0x21a340 ldr r6, [r5, #0x34]
 *   @0x21a344 cmp r6, #0
 *   @0x21a348 movgt r3, r6
 *   @0x21a34c bgt 0x21a358 <_Z20Audio_ReleaseEmitteri+0x60>
 *   @0x21a350 b 0x21a3a8 <_Z20Audio_ReleaseEmitteri+0xb0>
 *   @0x21a354 ldr r3, [r5, #0x34]
 *   @0x21a358 cmp r3, r4
 *   @0x21a35c ble 0x21a39c <_Z20Audio_ReleaseEmitteri+0xa4>
 *   @0x21a360 ldr r3, [r5, #0x38]
 *   @0x21a364 ldr r3, [r3, r4, lsl #2]
 *   @0x21a368 cmp r3, #0
 *   @0x21a36c beq 0x21a39c <_Z20Audio_ReleaseEmitteri+0xa4>
 *   @0x21a370 ldrb r2, [r3, #0x5]
 *   @0x21a374 cmp r2, #0
 *   @0x21a378 beq 0x21a39c <_Z20Audio_ReleaseEmitteri+0xa4>
 *   @0x21a37c ldr r2, [r3, #0x8]
 *   @0x21a380 cmp r2, #0
 *   @0x21a384 bne 0x21a39c <_Z20Audio_ReleaseEmitteri+0xa4>
 *   @0x21a388 ldr r2, [r3, #0x10]
 *   @0x21a38c cmp r2, #0
 *   @0x21a390 blt 0x21a39c <_Z20Audio_ReleaseEmitteri+0xa4>
 *   @0x21a394 ldr r0, [r3, #0x14]
 *   @0x21a398 bl 0x21a210 <_Z15Audio_StopSoundi>
 *   @0x21a39c add r4, r4, #1
 *   @0x21a3a0 cmp r4, r6
 *   @0x21a3a4 bne 0x21a354 <_Z20Audio_ReleaseEmitteri+0x5c>
 *   @0x21a3a8 mov r3, #0
 *   @0x21a3ac strb r3, [r5, #0x18]
 *   @0x21a3b0 pop {r4, r5, r6, pc}
 *   @0x21a3b4 andseq r4, sp, r0, lsr r10
 *   @0x21a3b8 subseq r10, r3, r0, lsl #31
 *
 * ══ §66/156 CPhysicsWorld::BeginParticleGroup(unsigned int, unsigned int, float, float, float, float, float, float, unsigned int, float, float, int)  0x2399a8  size 196  49 条（0x2399a8..0x239a6c）
 * @func 0x2399a8 0x239a6c  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1 / 0x28×1 / 0x18×1 / 0x36×1 / 0x24×1 / 0x14×1 / 0x40×1 / 0x44×1
 * VFP 指令 28 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2399a8 push {r4, r5}
 *   @0x2399ac vldr s13, [pc, #172]
 *   @0x2399b0 vldr s7, [sp, #12]
 *   @0x2399b4 vldr s6, [sp, #24]
 *   @0x2399b8 vnmul.f32 s7, s7, s13
 *   @0x2399bc vldr s14, [pc, #160]
 *   @0x2399c0 vldr s8, [sp, #32]
 *   @0x2399c4 vldr s12, [pc, #156]
 *   @0x2399c8 vldr s15, [r0, #96]
 *   @0x2399cc vldr s9, [sp, #8]
 *   @0x2399d0 vldr s10, [sp, #16]
 *   @0x2399d4 vldr s11, [sp, #20]
 *   @0x2399d8 ldr r12, [sp, #0x1c]
 *   @0x2399dc mov r5, #1
 *   @0x2399e0 ldr r4, [sp, #0x28]
 *   @0x2399e4 str r2, [r0, #0x18]
 *   @0x2399e8 ubfx r2, r12, #0x10, #0x8
 *   @0x2399ec strb r2, [r0, #0x36]
 *   @0x2399f0 ldr r2, [sp, #0x24]
 *   @0x2399f4 str r1, [r0, #0x14]
 *   @0x2399f8 ubfx r1, r12, #0x8, #0x8
 *   @0x2399fc strb r5, [r0, #0x40]
 *   @0x239a00 str r4, [r0, #0x44]
 *   @0x239a04 vmul.f32 s13, s6, s13
 *   @0x239a08 strb r12, [r0, #0x34]
 *   @0x239a0c strb r1, [r0, #0x35]
 *   @0x239a10 str r2, [r0, #0x38]
 *   @0x239a14 pop {r4, r5}
 *   @0x239a18 vdiv.f32 s7, s7, s14
 *   @0x239a1c vdiv.f32 s14, s13, s14
 *   @0x239a20 vstr s7, [r0, #36]
 *   @0x239a24 vmov s13, r3
 *   @0x239a28 vmul.f32 s12, s8, s12
 *   @0x239a2c vstr s14, [r0, #48]
 *   @0x239a30 vcvt.s32.f32 s12, s12
 *   @0x239a34 vmul.f32 s14, s15, s13
 *   @0x239a38 vmov r3, s12
 *   @0x239a3c vmul.f32 s13, s15, s9
 *   @0x239a40 vstr s14, [r0, #28]
 *   @0x239a44 strb r3, [r0, #0x37]
 *   @0x239a48 vmul.f32 s14, s15, s10
 *   @0x239a4c vstr s13, [r0, #32]
 *   @0x239a50 vmul.f32 s15, s15, s11
 *   @0x239a54 vstr s14, [r0, #40]
 *   @0x239a58 vstr s15, [r0, #44]
 *   @0x239a5c bx lr
 *   @0x239a60 ldrdmi r0, r1, [r9], #-251
 *   @0x239a64 teqmi r4, #0
 *   @0x239a68 cmnmi pc, #0
 *
 * ══ §67/156 CPhysicsDebugRender::DrawParticles(b2Vec2 const*, float, b2ParticleColor const*, int)  0x23c274  size 196  49 条（0x23c274..0x23c338）
 * @func 0x23c274 0x23c338  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsDebugRender::DrawParticles(b2Vec2 const*, float, b2ParticleColor const*, int)+0xb8 / YYGML_draw_set_colour(unsigned int) / GR_Draw_Ellipse(float, float, float, float, bool)
 * 字段偏移 top8: 0x38×1 / 0x8×1 / 0x2×1 / 0x3×1 / 0x-3×1
 * VFP 指令 20 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23c274 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x23c278 vpush {d8, d9}
 *   @0x23c27c sub sp, sp, #12
 *   @0x23c280 mov r9, r0
 *   @0x23c284 vmov s17, r2
 *   @0x23c288 ldr r7, [sp, #0x38]
 *   @0x23c28c cmp r7, #0
 *   @0x23c290 ble 0x23c32c <_ZN19CPhysicsDebugRender13DrawParticlesEPK6b2Vec2fPK15b2ParticleColori+0xb8>
 *   @0x23c294 vmov.f32 s18, #1.000000e+00
 *   @0x23c298 mov r4, r3
 *   @0x23c29c mov r5, r1
 *   @0x23c2a0 mov r6, #0
 *   @0x23c2a4 mov r8, #1
 *   @0x23c2a8 ldr r3, [r9, #0x8]
 *   @0x23c2ac vldr s16, [r3, #96]
 *   @0x23c2b0 ldrb r3, [r4, #0x2]
 *   @0x23c2b4 add r6, r6, #1
 *   @0x23c2b8 ldrb r0, [r4, #0x3]
 *   @0x23c2bc add r5, r5, #8
 *   @0x23c2c0 ldrb r1, [r4]
 *   @0x23c2c4 add r4, r4, #4
 *   @0x23c2c8 ldrb r2, [r4, #-0x3]
 *   @0x23c2cc lsl r3, r3, #16
 *   @0x23c2d0 orr r3, r3, r0, lsl #24
 *   @0x23c2d4 vdiv.f32 s16, s18, s16
 *   @0x23c2d8 orr r0, r3, r1
 *   @0x23c2dc orr r0, r0, r2, lsl #8
 *   @0x23c2e0 bl 0x169d98 <_Z21YYGML_draw_set_colourj>
 *   @0x23c2e4 vldr s14, [r5, #-8]
 *   @0x23c2e8 vldr s15, [r5, #-4]
 *   @0x23c2ec str r8, [sp]
 *   @0x23c2f0 vsub.f32 s12, s14, s17
 *   @0x23c2f4 vsub.f32 s13, s15, s17
 *   @0x23c2f8 vadd.f32 s14, s14, s17
 *   @0x23c2fc vadd.f32 s15, s17, s15
 *   @0x23c300 vmul.f32 s12, s12, s16
 *   @0x23c304 vmul.f32 s13, s13, s16
 *   @0x23c308 vmov r0, s12
 *   @0x23c30c vmul.f32 s14, s14, s16
 *   @0x23c310 vmov r1, s13
 *   @0x23c314 vmul.f32 s15, s15, s16
 *   @0x23c318 vmov r2, s14
 *   @0x23c31c vmov r3, s15
 *   @0x23c320 bl 0x16b278 <_Z15GR_Draw_Ellipseffffb>
 *   @0x23c324 cmp r6, r7
 *   @0x23c328 bne 0x23c2a8 <_ZN19CPhysicsDebugRender13DrawParticlesEPK6b2Vec2fPK15b2ParticleColori+0x34>
 *   @0x23c32c add sp, sp, #12
 *   @0x23c330 vpop {d8, d9}
 *   @0x23c334 pop {r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §68/156 JS_Math_atan2(RValue&, CInstance*, CInstance*, int, RValue*)  0x252308  size 196  49 条（0x252308..0x2523cc）
 * @func 0x252308 0x2523cc  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_JS_ToNumber(RValue&, RValue&)×2 / YYGetReal(RValue const*, int)×2 / JS_Math_atan2(RValue&, CInstance*, CInstance*, int, RValue*)+0xac / 0xb6c70 / JSThrowTypeError(char const*)
 * 字段偏移 top8: 0xc×2 / 0x38×2 / 0x1c×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x252308 cmp r3, #1
 *   @0x25230c push {r4, r5, r6, r7, r8, lr}
 *   @0x252310 mov r7, #0
 *   @0x252314 sub sp, sp, #32
 *   @0x252318 mov r6, r0
 *   @0x25231c str r7, [r0, #0xc]
 *   @0x252320 ble 0x2523b4 <_Z13JS_Math_atan2R6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x252324 ldr r1, [sp, #0x38]
 *   @0x252328 mov r0, sp
 *   @0x25232c mov r3, #5
 *   @0x252330 str r3, [sp, #0xc]
 *   @0x252334 str r3, [sp, #0x1c]
 *   @0x252338 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_>
 *   @0x25233c cmp r0, #1
 *   @0x252340 beq 0x2523a0 <_Z13JS_Math_atan2R6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x252344 ldr r3, [sp, #0x38]
 *   @0x252348 add r8, sp, #16
 *   @0x25234c add r1, r3, #16
 *   @0x252350 mov r0, r8
 *   @0x252354 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_>
 *   @0x252358 cmp r0, #1
 *   @0x25235c beq 0x2523a0 <_Z13JS_Math_atan2R6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x252360 mov r0, sp
 *   @0x252364 mov r1, r7
 *   @0x252368 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x25236c mov r4, r0
 *   @0x252370 mov r5, r1
 *   @0x252374 mov r0, r8
 *   @0x252378 mov r1, r7
 *   @0x25237c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x252380 mov r2, r0
 *   @0x252384 mov r3, r1
 *   @0x252388 mov r0, r4
 *   @0x25238c mov r1, r5
 *   @0x252390 bl 0xb6c70 <atan2@plt>
 *   @0x252394 stm r6, {r0, r1}
 *   @0x252398 add sp, sp, #32
 *   @0x25239c pop {r4, r5, r6, r7, r8, pc}
 *   @0x2523a0 ldr r0, [pc, #0x20]
 *   @0x2523a4 add r0, pc, r0
 *   @0x2523a8 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x2523ac add sp, sp, #32
 *   @0x2523b0 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2523b4 mvn r2, #0
 *   @0x2523b8 mvn r3, #-2147483648
 *   @0x2523bc stm r0, {r2, r3}
 *   @0x2523c0 add sp, sp, #32
 *   @0x2523c4 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2523c8 andseq r3, r0, r4, lsr #23
 *
 * ══ §69/156 spAtlas_createFromFile  0x284894  size 196  49 条（0x284894..0x284958）
 * @func 0x284894 0x284958  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6868×2 / _free×2 / _malloc / 0xb65bc / _spUtil_readFile / spAtlas_create
 * 字段偏移 top8: 0x90×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x284894 push {r4, r5, r6, r7, lr}
 *   @0x284898 mov r7, r1
 *   @0x28489c sub sp, sp, #12
 *   @0x2848a0 mov r1, #47
 *   @0x2848a4 mov r4, r0
 *   @0x2848a8 bl 0xb6868 <strrchr@plt>
 *   @0x2848ac mov r1, #92
 *   @0x2848b0 mov r5, r0
 *   @0x2848b4 mov r0, r4
 *   @0x2848b8 bl 0xb6868 <strrchr@plt>
 *   @0x2848bc ldr r1, [pc, #0x90]
 *   @0x2848c0 mov r2, #316
 *   @0x2848c4 add r1, pc, r1
 *   @0x2848c8 cmp r5, r0
 *   @0x2848cc movhs r0, r5
 *   @0x2848d0 cmp r0, r4
 *   @0x2848d4 addeq r0, r0, #1
 *   @0x2848d8 cmp r0, #0
 *   @0x2848dc rsbne r6, r4, r0
 *   @0x2848e0 moveq r6, r0
 *   @0x2848e4 addne r0, r6, #1
 *   @0x2848e8 moveq r0, #1
 *   @0x2848ec bl 0x285c10 <_malloc>
 *   @0x2848f0 mov r1, r4
 *   @0x2848f4 mov r2, r6
 *   @0x2848f8 mov r5, r0
 *   @0x2848fc bl 0xb65bc <memcpy@plt>
 *   @0x284900 mov r0, r4
 *   @0x284904 mov r3, #0
 *   @0x284908 add r1, sp, #4
 *   @0x28490c strb r3, [r5, r6]
 *   @0x284910 bl 0xbd83c <_spUtil_readFile>
 *   @0x284914 subs r4, r0, #0
 *   @0x284918 beq 0x28494c <spAtlas_createFromFile+0xb8>
 *   @0x28491c mov r3, r7
 *   @0x284920 ldr r1, [sp, #0x4]
 *   @0x284924 mov r2, r5
 *   @0x284928 bl 0x284174 <spAtlas_create>
 *   @0x28492c mov r6, r0
 *   @0x284930 mov r0, r4
 *   @0x284934 bl 0x285c80 <_free>
 *   @0x284938 mov r0, r5
 *   @0x28493c bl 0x285c80 <_free>
 *   @0x284940 mov r0, r6
 *   @0x284944 add sp, sp, #12
 *   @0x284948 pop {r4, r5, r6, r7, pc}
 *   @0x28494c mov r6, r4
 *   @0x284950 b 0x284930 <spAtlas_createFromFile+0x9c>
 *   @0x284954 andeq r2, sp, r0, asr #24
 *
 * ══ §70/156 png_do_unpack  0x2a8b2e  size 196  49 条（0x2a8b2e..0x2a8bf2）
 * @func 0x2a8b2e 0x2a8bf2  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x1435f66 / 0x2e9396 / 0x1435f9e
 * 字段偏移 top8: 0x12×2 / 0x9×1 / 0x-1×1 / 0xa×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a8b2e ldrb r2, [r0, #0x9]
 *   @0x2a8b32 cmp r2, #0x7
 *   @0x2a8b36 cmp r2, #0x2
 *   @0x2a8b3a beq 0x2a8b7a <png_do_unpack+0x4c>
 *   @0x2a8b3e beq 0x2a8bb2 <png_do_unpack+0x84>
 *   @0x2a8b42 bne 0x2a8be2 <png_do_unpack+0xb4>
 *   @0x2a8b46 adds r2, r3, #0x7
 *   @0x2a8b4a strtmi r0, [r9], #-1237
 *   @0x2a8b4e mvns r2, r2
 *   @0x2a8b52 and r2, r2, #0x7
 *   @0x2a8b56 cmp r1, r5
 *   @0x2a8b5a ldrb r6, [r4]
 *   @0x2a8b5e it eq
 *   @0x2a8b62 blx 0x1435f66 <b2_toiTime+0xcdcac2>
 *   @0x2a8b66 svclt #0x8f602
 *   @0x2a8b6a moveq r2, #0x0
 *   @0x2a8b6e svclt #0x180601
 *   @0x2a8b72 addne r2, #0x1
 *   @0x2a8b76 strb r6, [sp, r1, lsl #18]!
 *   @0x2a8b7a adds r2, r3, #0x3
 *   @0x2a8b7e mvns r2, r2
 *   @0x2a8b82 bl 0x2e9396 <FT_New_Face+0x2be>
 *   @0x2a8b86 strtmi r0, [r9], #-1173
 *   @0x2a8b8a lsls r2, r2, #0x1
 *   @0x2a8b8e cmp r1, r5
 *   @0x2a8b92 ldrb r6, [r4]
 *   @0x2a8b96 it eq
 *   @0x2a8b9a blx 0x1435f9e <b2_toiTime+0xcdcafa>
 *   @0x2a8b9e svclt #0x8f602
 *   @0x2a8ba2 moveq r2, #0x0
 *   @0x2a8ba6 svclt #0x180603
 *   @0x2a8baa addne r2, #0x2
 *   @0x2a8bae strb r6, [sp, r1, lsl #18]!
 *   @0x2a8bb2 subs r5, r3, #0x1
 *   @0x2a8bb6 svclt #0xc0f01
 *   @0x2a8bba moveq r2, #0x0
 *   @0x2a8bbe add.w r4, r1, r5, lsr #1
 *   @0x2a8bc2 add r1, r5
 *   @0x2a8bc6 cmp r1, r5
 *   @0x2a8bca ldrb r6, [r4]
 *   @0x2a8bce and r6, r6, #0xf
 *   @0x2a8bd2 strb r6, [r1], #-1
 *   @0x2a8bd6 cbz r2, 0x2a8bde <png_do_unpack+0xb0>
 *   @0x2a8bda movs r2, #0x0
 *   @0x2a8bde movs r2, #0x4
 *   @0x2a8be2 movs r2, #0x8
 *   @0x2a8be6 ldrb r2, [r0, #0xa]
 *   @0x2a8bea lsls r1, r2, #0x3
 *   @0x2a8bee str r3, [r0, #0x4]
 *
 * ══ §71/156 b2ChainShape::ComputeAABB(b2AABB*, b2Transform const&, int) const  0x2c487c  size 196  49 条（0x2c487c..0x2c4940）
 * @func 0x2c487c 0x2c4940  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x-4×1 / 0x10×1 / 0xc×1 / 0x4×1
 * VFP 指令 38 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c487c str r4, [sp, #-0x4]!
 *   @0x2c4880 vldr s11, [r2, #8]
 *   @0x2c4884 add r12, r3, #1
 *   @0x2c4888 vldr s10, [r2, #12]
 *   @0x2c488c ldr r4, [r0, #0x10]
 *   @0x2c4890 vldr s13, [r2]
 *   @0x2c4894 vldr s8, [r2, #4]
 *   @0x2c4898 cmp r4, r12
 *   @0x2c489c lslne r4, r12, #3
 *   @0x2c48a0 ldr r12, [r0, #0xc]
 *   @0x2c48a4 moveq r4, #0
 *   @0x2c48a8 add r3, r12, r3, lsl #3
 *   @0x2c48ac add r0, r12, r4
 *   @0x2c48b0 vldr s14, [r3, #4]
 *   @0x2c48b4 vldr s15, [r0, #4]
 *   @0x2c48b8 vmul.f32 s12, s11, s14
 *   @0x2c48bc vldr s6, [r3]
 *   @0x2c48c0 vldr s7, [r0]
 *   @0x2c48c4 ldr r4, [sp], #4
 *   @0x2c48c8 vmul.f32 s9, s11, s15
 *   @0x2c48cc vmul.f32 s14, s10, s14
 *   @0x2c48d0 vmul.f32 s15, s10, s15
 *   @0x2c48d4 vnmls.f32 s12, s10, s6
 *   @0x2c48d8 vnmls.f32 s9, s10, s7
 *   @0x2c48dc vmla.f32 s14, s6, s11
 *   @0x2c48e0 vmla.f32 s15, s11, s7
 *   @0x2c48e4 vadd.f32 s12, s12, s13
 *   @0x2c48e8 vadd.f32 s13, s13, s9
 *   @0x2c48ec vadd.f32 s14, s14, s8
 *   @0x2c48f0 vadd.f32 s15, s8, s15
 *   @0x2c48f4 vcmpe.f32 s12, s13
 *   @0x2c48f8 vmrs APSR_nzcv, fpscr
 *   @0x2c48fc vcmpe.f32 s14, s15
 *   @0x2c4900 vmovpl.f32 s11, s13
 *   @0x2c4904 vmovmi.f32 s11, s12
 *   @0x2c4908 vmrs APSR_nzcv, fpscr
 *   @0x2c490c vstr s11, [r1]
 *   @0x2c4910 vcmpe.f32 s12, s13
 *   @0x2c4914 vmovpl.f32 s11, s15
 *   @0x2c4918 vmovmi.f32 s11, s14
 *   @0x2c491c vmrs APSR_nzcv, fpscr
 *   @0x2c4920 vstr s11, [r1, #4]
 *   @0x2c4924 vcmpe.f32 s14, s15
 *   @0x2c4928 vmovgt.f32 s13, s12
 *   @0x2c492c vmrs APSR_nzcv, fpscr
 *   @0x2c4930 vstr s13, [r1, #8]
 *   @0x2c4934 vmovgt.f32 s15, s14
 *   @0x2c4938 vstr s15, [r1, #12]
 *   @0x2c493c bx lr
 *
 * ══ §72/156 b2PolygonShape::TestPoint(b2Transform const&, b2Vec2 const&) const  0x2c566c  size 196  49 条（0x2c566c..0x2c5730）
 * @func 0x2c566c 0x2c5730  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2PolygonShape::TestPoint(b2Transform const&, b2Vec2 const&) const+0xb4
 * 字段偏移 top8: 0x94×1
 * VFP 指令 32 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c566c vldr s15, [r1, #4]
 *   @0x2c5670 vldr s10, [r2, #4]
 *   @0x2c5674 vsub.f32 s10, s10, s15
 *   @0x2c5678 vldr s13, [r1, #8]
 *   @0x2c567c vldr s15, [r1, #12]
 *   @0x2c5680 vldr s14, [r1]
 *   @0x2c5684 vldr s12, [r2]
 *   @0x2c5688 ldr r1, [r0, #0x94]
 *   @0x2c568c cmp r1, #0
 *   @0x2c5690 vmul.f32 s11, s10, s13
 *   @0x2c5694 vmul.f32 s10, s10, s15
 *   @0x2c5698 vsub.f32 s14, s12, s14
 *   @0x2c569c vmls.f32 s10, s13, s14
 *   @0x2c56a0 vmla.f32 s11, s14, s15
 *   @0x2c56a4 ble 0x2c5720 <_ZNK14b2PolygonShape9TestPointERK11b2TransformRK6b2Vec2+0xb4>
 *   @0x2c56a8 vldr s15, [r0, #24]
 *   @0x2c56ac vldr s12, [r0, #88]
 *   @0x2c56b0 vldr s13, [r0, #20]
 *   @0x2c56b4 vldr s14, [r0, #84]
 *   @0x2c56b8 vsub.f32 s15, s10, s15
 *   @0x2c56bc vmul.f32 s15, s15, s12
 *   @0x2c56c0 vsub.f32 s13, s11, s13
 *   @0x2c56c4 vmla.f32 s15, s13, s14
 *   @0x2c56c8 vcmpe.f32 s15, #0
 *   @0x2c56cc vmrs APSR_nzcv, fpscr
 *   @0x2c56d0 bgt 0x2c5728 <_ZNK14b2PolygonShape9TestPointERK11b2TransformRK6b2Vec2+0xbc>
 *   @0x2c56d4 add r0, r0, #92
 *   @0x2c56d8 mov r2, #0
 *   @0x2c56dc b 0x2c570c <_ZNK14b2PolygonShape9TestPointERK11b2TransformRK6b2Vec2+0xa0>
 *   @0x2c56e0 vldr s15, [r3, #-60]
 *   @0x2c56e4 vsub.f32 s15, s10, s15
 *   @0x2c56e8 vldr s12, [r3, #4]
 *   @0x2c56ec vldr s13, [r3, #-64]
 *   @0x2c56f0 vldr s14, [r3]
 *   @0x2c56f4 vmul.f32 s15, s15, s12
 *   @0x2c56f8 vsub.f32 s13, s11, s13
 *   @0x2c56fc vmla.f32 s15, s13, s14
 *   @0x2c5700 vcmpe.f32 s15, #0
 *   @0x2c5704 vmrs APSR_nzcv, fpscr
 *   @0x2c5708 bgt 0x2c5728 <_ZNK14b2PolygonShape9TestPointERK11b2TransformRK6b2Vec2+0xbc>
 *   @0x2c570c add r2, r2, #1
 *   @0x2c5710 mov r3, r0
 *   @0x2c5714 cmp r2, r1
 *   @0x2c5718 add r0, r0, #8
 *   @0x2c571c bne 0x2c56e0 <_ZNK14b2PolygonShape9TestPointERK11b2TransformRK6b2Vec2+0x74>
 *   @0x2c5720 mov r0, #1
 *   @0x2c5724 bx lr
 *   @0x2c5728 mov r0, #0
 *   @0x2c572c bx lr
 *
 * ══ §73/156 FT_Get_Advances  0x2e788c  size 196  49 条（0x2e788c..0x2e7950）
 * @func 0x2e788c 0x2e7950  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x60×1 / 0x54×1 / 0x44×1 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e788c push.w {r0, r1, r2, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2e7890 mov r5, r1
 *   @0x2e7894 mov r6, r3
 *   @0x2e7898 strmi r8, [r4], -r8, lsr #32
 *   @0x2e789c cmp r0, #0x0
 *   @0x2e78a0 cmp.w r8, #0x0
 *   @0x2e78a4 beq 0x2e7940 <FT_Get_Advances+0xb4>
 *   @0x2e78a8 cmp r1, r3
 *   @0x2e78ac adds.w r9, r1, r2
 *   @0x2e78b0 bhs 0x2e7944 <FT_Get_Advances+0xb8>
 *   @0x2e78b4 bhi 0x2e7944 <FT_Get_Advances+0xb8>
 *   @0x2e78b8 movs r0, #0x0
 *   @0x2e78bc ldr r3, [r0, #0x60]
 *   @0x2e78c0 ldr.w r12, [r3, #0x54]
 *   @0x2e78c4 cmp.w r12, #0x0
 *   @0x2e78c8 bne 0x2e78dc <FT_Get_Advances+0x50>
 *   @0x2e78cc bmi 0x2e7948 <FT_Get_Advances+0xbc>
 *   @0x2e78d0 .word 0xf1a87680
 *   @0x2e78d4 .word 0xf0060704
 *   @0x2e78d8 eor r0, r10, r0, lsl r8
 *   @0x2e78dc lsls r3, r6, #0x1e
 *   @0x2e78e0 ubfx r3, r6, #0x10, #0x4
 *   @0x2e78e4 cmp r3, #0x1
 *   @0x2e78e8 str.w r8, [sp]
 *   @0x2e78ec mov r0, r4
 *   @0x2e78f0 mov r2, r7
 *   @0x2e78f4 blx r12
 *   @0x2e78f8 add.w r0, r4, #0x58
 *   @0x2e78fc mov r1, r8
 *   @0x2e7900 mov r3, r6
 *   @0x2e7904 pop.w {r4, r5, r6, r7, r8, r9, lr}
 *   @0x2e7908 b.w 0x2e4db2 <FT_MulDiv+0x76>
 *   @0x2e790c uxtb r3, r0
 *   @0x2e7910 bne 0x2e794a <FT_Get_Advances+0xbe>
 *   @0x2e7914 mov r0, r4
 *   @0x2e7918 mov r2, r6
 *   @0x2e791c stmiblt r0!, {r0, r1, r5, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2e7920 ldr r3, [r4, #0x54]
 *   @0x2e7924 andle r0, r7, r0, lsl #30
 *   @0x2e7928 ldr r3, [r3, #0x44]
 *   @0x2e792c lsls r3, r3, #0xa
 *   @0x2e7930 strbmi r3, [sp, #-0xf04]
 *   @0x2e7934 bne 0x2e7914 <FT_Get_Advances+0x88>
 *   @0x2e7938 ldr r3, [r3, #0x40]
 *   @0x2e793c movs r0, #0x23
 *   @0x2e7940 movs r0, #0x6
 *   @0x2e7944 movs r0, #0x10
 *   @0x2e7948 movs r0, #0x7
 *   @0x2e794c pop.w {r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §74/156 FT_Stream_OpenLZW  0x316e90  size 196  49 条（0x316e90..0x316f54）
 * @func 0x316e90 0x316f54  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_316cdc+0x13c×2 / 0x395378
 * 字段偏移 top8: 0x1c×2 / 0x4×1 / 0xc×1 / 0x10×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x316e90 push.w {r0, r1, r4, r5, r6, r7, r8, lr}
 *   @0x316e94 mov r5, r1
 *   @0x316e98 cbz r0, 0x316e9c <FT_Stream_OpenLZW+0xc>
 *   @0x316e9c movs r3, #0x28
 *   @0x316ea0 b 0x316f42 <FT_Stream_OpenLZW+0xb2>
 *   @0x316ea4 .word 0x4608801c
 *   @0x316ea8 movs r1, #0x0
 *   @0x316eac .word 0x4607fcfc
 *   @0x316eb0 cbnz r0, 0x316eba <FT_Stream_OpenLZW+0x2a>
 *   @0x316eb4 bl 0x316e18 <FT_Gzip_Uncompress+0x1c0>
 *   @0x316eb8 mov r7, r0
 *   @0x316ebc cmp r7, #0x0
 *   @0x316ec0 mov r1, r7
 *   @0x316ec4 mov r0, r4
 *   @0x316ec8 .word 0xf8c4eb74
 *   @0x316ecc .word 0x4640801c
 *   @0x316ed0 movw r1, #0x10c4
 *   @0x316ed4 add r2, sp, #0x4
 *   @0x316ed8 blls 0x395378 <ft_adobe_glyph_list+0x4a54>
 *   @0x316edc mov r6, r0
 *   @0x316ee0 str r4, [r0, #0x4]
 *   @0x316ee4 andvs r5, r5, r6, lsl #3
 *   @0x316ee8 ldr r3, [r4, #0x1c]
 *   @0x316eec add.w r3, r0, #0x10a0
 *   @0x316ef0 add.w r2, r3, #0x18
 *   @0x316ef4 mov r0, r5
 *   @0x316ef8 mov r1, r7
 *   @0x316efc str r2, [r3, #0x1c]
 *   @0x316f00 .word 0x4607fcd2
 *   @0x316f04 cbnz r0, 0x316f1a <FT_Stream_OpenLZW+0x8a>
 *   @0x316f08 bl 0x316e18 <FT_Gzip_Uncompress+0x1c0>
 *   @0x316f0c mov r7, r0
 *   @0x316f10 add.w r0, r6, #0xc
 *   @0x316f14 mov r1, r5
 *   @0x316f18 strls pc, [r1, -r0, lsr #31]
 *   @0x316f1c cbz r7, 0x316f28 <FT_Stream_OpenLZW+0x98>
 *   @0x316f20 mov r1, r6
 *   @0x316f24 and pc, r12, r8, lsl #20
 *   @0x316f28 str r6, [r4, #0xc]
 *   @0x316f2c rsbvs r4, r3, r0, lsl #6
 *   @0x316f30 movs r3, #0x0
 *   @0x316f34 str r3, [r4]
 *   @0x316f38 add r3, pc
 *   @0x316f3c ldr r3, [pc, #0x10]
 *   @0x316f40 str r3, [r4, #0x18]
 *   @0x316f44 add sp, #0x8
 *   @0x316f48 svclt #0x81f0
 *   @0x316f4c lsls r3, r2, #0xb
 *   @0x316f50 lsls r5, r1, #0x1
 *
 * ══ §75/156 __gnu_Unwind_Backtrace  0x319cf0  size 196  49 条（0x319cf0..0x319db4）
 * @func 0x319cf0 0x319db4  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_319630+0x114 / anon_319cc4 / anon_319630+0x220
 * 字段偏移 top8: 0x3c×1 / 0x40×1 / 0x58×1 / 0x98×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x319cf0 ldr r3, [r2, #0x3c]
 *   @0x319cf4 push {r4, r5, r6, r7, r8, lr}
 *   @0x319cf8 add lr, r2, #4
 *   @0x319cfc str r3, [r2, #0x40]
 *   @0x319d00 mov r7, r0
 *   @0x319d04 mov r8, r1
 *   @0x319d08 sub sp, sp, #568
 *   @0x319d0c ldm lr!, {r0, r1, r2, r3}
 *   @0x319d10 add r12, sp, #92
 *   @0x319d14 add r4, sp, #88
 *   @0x319d18 stm r12!, {r0, r1, r2, r3}
 *   @0x319d1c ldm lr!, {r0, r1, r2, r3}
 *   @0x319d20 stm r12!, {r0, r1, r2, r3}
 *   @0x319d24 ldm lr!, {r0, r1, r2, r3}
 *   @0x319d28 stm r12!, {r0, r1, r2, r3}
 *   @0x319d2c ldm lr, {r0, r1, r2, r3}
 *   @0x319d30 stm r12, {r0, r1, r2, r3}
 *   @0x319d34 mvn r3, #0
 *   @0x319d38 str r3, [sp, #0x58]
 *   @0x319d3c mov r0, sp
 *   @0x319d40 ldr r1, [sp, #0x98]
 *   @0x319d44 bl 0x319744 <__gnu_uldivmod_helper+0x150>
 *   @0x319d48 cmp r0, #0
 *   @0x319d4c beq 0x319d58 <__gnu_Unwind_Backtrace+0x68>
 *   @0x319d50 mov r5, #9
 *   @0x319d54 b 0x319da0 <__gnu_Unwind_Backtrace+0xb0>
 *   @0x319d58 mov r0, r4
 *   @0x319d5c mov r1, #12
 *   @0x319d60 mov r2, sp
 *   @0x319d64 bl 0x319cc4 <_Unwind_VRS_Set+0x5c>
 *   @0x319d68 mov r0, r4
 *   @0x319d6c mov r1, r8
 *   @0x319d70 blx r7
 *   @0x319d74 cmp r0, #0
 *   @0x319d78 bne 0x319d50 <__gnu_Unwind_Backtrace+0x60>
 *   @0x319d7c mov r0, #8
 *   @0x319d80 mov r1, sp
 *   @0x319d84 mov r2, r4
 *   @0x319d88 ldr r3, [sp, #0x10]
 *   @0x319d8c blx r3
 *   @0x319d90 cmp r0, #9
 *   @0x319d94 cmpne r0, #5
 *   @0x319d98 mov r5, r0
 *   @0x319d9c bne 0x319d3c <__gnu_Unwind_Backtrace+0x4c>
 *   @0x319da0 mov r0, r4
 *   @0x319da4 bl 0x319850 <__gnu_uldivmod_helper+0x25c>
 *   @0x319da8 mov r0, r5
 *   @0x319dac add sp, sp, #568
 *   @0x319db0 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §76/156 CSkeletonSprite::DrawTime(char const*, char const*, float, float, float, float, float, float, unsigned int, float)  0xbeb24  size 192  48 条（0xbeb24..0xbebe4）
 * @func 0xbeb24 0xbebe4  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spBone_setYDown / operator new(unsigned int) / CSkeletonInstance::CSkeletonInstance(CSkeletonSprite*) / CSkeletonInstance::SelectAnimation(char const*) / CSkeletonInstance::SelectSkin(char const*) / CSkeletonInstance::SetAnimationTransformTime(float, float, float, float, float, float) / CSkeletonSprite::DrawSkeleton(spSkeleton*, unsigned int, float) / CSkeletonInstance::~CSkeletonInstance()
 * 字段偏移 top8: 0x14×2 / 0x50×1 / 0x54×1 / 0x64×1 / 0x68×1 / 0x1c×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbeb24 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xbeb28 vpush {d8, d9}
 *   @0xbeb2c sub sp, sp, #28
 *   @0xbeb30 vldr s18, [sp, #88]
 *   @0xbeb34 mov r5, r0
 *   @0xbeb38 mov r0, #1
 *   @0xbeb3c mov r10, r2
 *   @0xbeb40 str r3, [sp, #0x14]
 *   @0xbeb44 mov r8, r1
 *   @0xbeb48 ldr r11, [sp, #0x50]
 *   @0xbeb4c ldr r9, [sp, #0x54]
 *   @0xbeb50 vldr s17, [sp, #92]
 *   @0xbeb54 vldr s16, [sp, #96]
 *   @0xbeb58 ldr r7, [sp, #0x64]
 *   @0xbeb5c ldr r6, [sp, #0x68]
 *   @0xbeb60 bl 0x284ed8 <spBone_setYDown>
 *   @0xbeb64 mov r0, #52
 *   @0xbeb68 bl 0x27c524 <_Znwj>
 *   @0xbeb6c mov r1, r5
 *   @0xbeb70 mov r4, r0
 *   @0xbeb74 bl 0xbe67c <_ZN17CSkeletonInstanceC2EP15CSkeletonSprite>
 *   @0xbeb78 mov r0, r4
 *   @0xbeb7c mov r1, r8
 *   @0xbeb80 bl 0xbe578 <_ZN17CSkeletonInstance15SelectAnimationEPKc>
 *   @0xbeb84 mov r0, r4
 *   @0xbeb88 mov r1, r10
 *   @0xbeb8c bl 0xbe590 <_ZN17CSkeletonInstance10SelectSkinEPKc>
 *   @0xbeb90 ldr r3, [sp, #0x14]
 *   @0xbeb94 mov r0, r4
 *   @0xbeb98 mov r2, r11
 *   @0xbeb9c vstr s18, [sp]
 *   @0xbeba0 vstr s17, [sp, #4]
 *   @0xbeba4 mov r1, r3
 *   @0xbeba8 vstr s16, [sp, #8]
 *   @0xbebac mov r3, r9
 *   @0xbebb0 bl 0xbeaa0 <_ZN17CSkeletonInstance25SetAnimationTransformTimeEffffff>
 *   @0xbebb4 mov r0, r5
 *   @0xbebb8 mov r2, r7
 *   @0xbebbc mov r3, r6
 *   @0xbebc0 ldr r1, [r4, #0x1c]
 *   @0xbebc4 bl 0xbe054 <_ZN15CSkeletonSprite12DrawSkeletonEP10spSkeletonjf>
 *   @0xbebc8 mov r0, r4
 *   @0xbebcc bl 0xbe194 <_ZN17CSkeletonInstanceD2Ev>
 *   @0xbebd0 mov r0, r4
 *   @0xbebd4 add sp, sp, #28
 *   @0xbebd8 vpop {d8, d9}
 *   @0xbebdc pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xbebe0 b 0x27d1d0 <_ZdlPv>
 *
 * ══ §77/156 F_BUFFER_Seek(RValue&, CInstance*, CInstance*, int, RValue*)  0xc55e0  size 192  48 条（0xc55e0..0xc56a0）
 * @func 0xc55e0 0xc56a0  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / F_BUFFER_Seek(RValue&, CInstance*, CInstance*, int, RValue*)+0xa4
 * 字段偏移 top8: 0x10×2 / 0x18×1 / 0xc×1 / 0x80×1 / 0x4×1 / 0x2×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc55e0 push {r4, r5, r6, r7, r8, lr}
 *   @0xc55e4 mov r1, #0
 *   @0xc55e8 ldr r5, [sp, #0x18]
 *   @0xc55ec mov r3, r1
 *   @0xc55f0 str r1, [r0, #0xc]
 *   @0xc55f4 movt r3, #0xbff0
 *   @0xc55f8 mov r4, r0
 *   @0xc55fc stm r0, {r1, r3}
 *   @0xc5600 mov r0, r5
 *   @0xc5604 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc5608 cmp r0, #0
 *   @0xc560c blt 0xc5684 <_Z13F_BUFFER_SeekR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0xc5610 ldr r3, [pc, #0x80]
 *   @0xc5614 add r3, pc, r3
 *   @0xc5618 ldr r2, [r3]
 *   @0xc561c cmp r0, r2
 *   @0xc5620 bge 0xc5684 <_Z13F_BUFFER_SeekR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0xc5624 ldr r3, [r3, #0x4]
 *   @0xc5628 ldr r6, [r3, r0, lsl #2]
 *   @0xc562c cmp r6, #0
 *   @0xc5630 beq 0xc5684 <_Z13F_BUFFER_SeekR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0xc5634 ldr r3, [r6]
 *   @0xc5638 mov r1, #1
 *   @0xc563c mov r0, r5
 *   @0xc5640 ldr r7, [r3, #0x10]
 *   @0xc5644 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc5648 mov r1, #2
 *   @0xc564c mov r8, r0
 *   @0xc5650 mov r0, r5
 *   @0xc5654 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc5658 mov r1, r8
 *   @0xc565c mov r2, r0
 *   @0xc5660 mov r0, r6
 *   @0xc5664 blx r7
 *   @0xc5668 vmov s15, r0
 *   @0xc566c vcvt.f64.s32 d7, s15
 *   @0xc5670 vmov r0, r1, d7
 *   @0xc5674 vmov r2, s14
 *   @0xc5678 mov r3, r1
 *   @0xc567c stm r4, {r2, r3}
 *   @0xc5680 pop {r4, r5, r6, r7, r8, pc}
 *   @0xc5684 ldr r0, [pc, #0x10]
 *   @0xc5688 mov r1, #0
 *   @0xc568c pop {r4, r5, r6, r7, r8, lr}
 *   @0xc5690 add r0, pc, r0
 *   @0xc5694 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc5698 eorseq r4, r11, r0, lsl #22
 *   @0xc569c eoreq r11, r6, r4, lsr #10
 *
 * ══ §78/156 IBuffer::GetBufferFileHeaderFromBase64(char const*, BufferFileHeader&)  0xcd040  size 192  48 条（0xcd040..0xcd100）
 * @func 0xcd040 0xcd100  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / 0xb6538 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / base64_decode(char const*, unsigned int, char*, bool)
 * 字段偏移 top8: 0xa0×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcd040 push {r3, r4, r5, r6, r7, lr}
 *   @0xcd044 subs r6, r0, #0
 *   @0xcd048 mov r7, r1
 *   @0xcd04c beq 0xcd0d0 <_ZN7IBuffer29GetBufferFileHeaderFromBase64EPKcR16BufferFileHeader+0x90>
 *   @0xcd050 bl 0xb6538 <strlen@plt>
 *   @0xcd054 ldr r1, [pc, #0xa0]
 *   @0xcd058 movw r2, #0x1fe
 *   @0xcd05c mov r3, #1
 *   @0xcd060 add r1, pc, r1
 *   @0xcd064 add r0, r0, r0, lsl #1
 *   @0xcd068 cmp r0, #0
 *   @0xcd06c add r5, r0, #3
 *   @0xcd070 movge r12, r0
 *   @0xcd074 movlt r12, r5
 *   @0xcd078 asr r5, r12, #2
 *   @0xcd07c add r5, r5, #4
 *   @0xcd080 mov r0, r5
 *   @0xcd084 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xcd088 mov r1, r5
 *   @0xcd08c mov r3, #0
 *   @0xcd090 mov r4, r0
 *   @0xcd094 mov r0, r6
 *   @0xcd098 mov r2, r4
 *   @0xcd09c bl 0x1d1ff0 <_Z13base64_decodePKcjPcb>
 *   @0xcd0a0 cmp r4, #0
 *   @0xcd0a4 beq 0xcd0d0 <_ZN7IBuffer29GetBufferFileHeaderFromBase64EPKcR16BufferFileHeader+0x90>
 *   @0xcd0a8 ldr r2, [r4]
 *   @0xcd0ac movw r3, #0x5542
 *   @0xcd0b0 movt r3, #0x4646
 *   @0xcd0b4 cmp r2, r3
 *   @0xcd0b8 bne 0xcd0c8 <_ZN7IBuffer29GetBufferFileHeaderFromBase64EPKcR16BufferFileHeader+0x88>
 *   @0xcd0bc ldr r5, [r4, #0x4]
 *   @0xcd0c0 cmp r5, #1
 *   @0xcd0c4 beq 0xcd0d8 <_ZN7IBuffer29GetBufferFileHeaderFromBase64EPKcR16BufferFileHeader+0x98>
 *   @0xcd0c8 mov r0, r4
 *   @0xcd0cc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xcd0d0 mov r0, #0
 *   @0xcd0d4 pop {r3, r4, r5, r6, r7, pc}
 *   @0xcd0d8 mov r12, r4
 *   @0xcd0dc ldm r12!, {r0, r1, r2, r3}
 *   @0xcd0e0 stm r7!, {r0, r1, r2, r3}
 *   @0xcd0e4 mov r0, r4
 *   @0xcd0e8 ldr r3, [r12]
 *   @0xcd0ec str r3, [r7]
 *   @0xcd0f0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xcd0f4 mov r0, r5
 *   @0xcd0f8 pop {r3, r4, r5, r6, r7, pc}
 *   @0xcd0fc eoreq r5, r6, r0, lsl r1
 *
 * ══ §79/156 CFontGM::GetFont()  0xf6ca0  size 192  48 条（0xf6ca0..0xf6d60）
 * @func 0xf6ca0 0xf6d60  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / TFont::TFont()
 * 字段偏移 top8: 0x20×3 / 0x24×2 / 0x2c×1 / 0x4×1 / 0x14×1 / 0x8×1 / 0x1c×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf6ca0 push {r4, r5, r6, lr}
 *   @0xf6ca4 mov r5, r0
 *   @0xf6ca8 mov r6, #0
 *   @0xf6cac mov r0, #24
 *   @0xf6cb0 str r6, [r5, #0x2c]
 *   @0xf6cb4 bl 0x27c524 <_Znwj>
 *   @0xf6cb8 mov r4, r0
 *   @0xf6cbc bl 0x1a867c <_ZN5TFontC2Ev>
 *   @0xf6cc0 ldr r3, [r4]
 *   @0xf6cc4 mov r0, r4
 *   @0xf6cc8 ldr r1, [r5, #0x4]
 *   @0xf6ccc ldr r3, [r3, #0x14]
 *   @0xf6cd0 blx r3
 *   @0xf6cd4 ldr r3, [r4]
 *   @0xf6cd8 mov r0, r4
 *   @0xf6cdc ldr r1, [r5, #0x8]
 *   @0xf6ce0 ldr r3, [r3, #0x1c]
 *   @0xf6ce4 blx r3
 *   @0xf6ce8 ldr r3, [r4]
 *   @0xf6cec mov r1, r6
 *   @0xf6cf0 mov r0, r4
 *   @0xf6cf4 ldr r3, [r3, #0x20]
 *   @0xf6cf8 blx r3
 *   @0xf6cfc ldrb r3, [r5, #0xc]
 *   @0xf6d00 cmp r3, r6
 *   @0xf6d04 bne 0xf6d3c <_ZN7CFontGM7GetFontEv+0x9c>
 *   @0xf6d08 ldrb r3, [r5, #0xd]
 *   @0xf6d0c cmp r3, #0
 *   @0xf6d10 beq 0xf6d34 <_ZN7CFontGM7GetFontEv+0x94>
 *   @0xf6d14 ldr r3, [r4]
 *   @0xf6d18 mov r0, r4
 *   @0xf6d1c ldr r2, [r3, #0x24]
 *   @0xf6d20 ldr r5, [r3, #0x20]
 *   @0xf6d24 blx r2
 *   @0xf6d28 orr r1, r0, #2
 *   @0xf6d2c mov r0, r4
 *   @0xf6d30 blx r5
 *   @0xf6d34 mov r0, r4
 *   @0xf6d38 pop {r4, r5, r6, pc}
 *   @0xf6d3c ldr r3, [r4]
 *   @0xf6d40 mov r0, r4
 *   @0xf6d44 ldr r2, [r3, #0x24]
 *   @0xf6d48 ldr r6, [r3, #0x20]
 *   @0xf6d4c blx r2
 *   @0xf6d50 orr r1, r0, #1
 *   @0xf6d54 mov r0, r4
 *   @0xf6d58 blx r6
 *   @0xf6d5c b 0xf6d08 <_ZN7CFontGM7GetFontEv+0x68>
 *
 * ══ §80/156 F_DsMapEmpty(RValue&, CInstance*, CInstance*, int, RValue*)  0xfef54  size 192  48 条（0xfef54..0xff014）
 * @func 0xfef54 0xff014  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DS_AutoMutex::~DS_AutoMutex()×2 / DS_AutoMutex::DS_AutoMutex() / YYGetInt32(RValue const*, int) / F_DsMapEmpty(RValue&, CInstance*, CInstance*, int, RValue*)+0x94 / CDS_Map::Empty() / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x4×2 / 0x18×1 / 0x7c×1 / 0x6c×1 / 0x2×1 / 0xc×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfef54 push {r4, r5, r6, lr}
 *   @0xfef58 sub sp, sp, #8
 *   @0xfef5c add r4, sp, #4
 *   @0xfef60 mov r5, r0
 *   @0xfef64 ldr r6, [sp, #0x18]
 *   @0xfef68 mov r0, r4
 *   @0xfef6c bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0xfef70 mov r1, #0
 *   @0xfef74 mov r0, r6
 *   @0xfef78 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfef7c cmp r0, #0
 *   @0xfef80 blt 0xfefe8 <_Z12F_DsMapEmptyR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0xfef84 ldr r3, [pc, #0x7c]
 *   @0xfef88 ldr r3, [pc, r3]
 *   @0xfef8c ldr r3, [r3]
 *   @0xfef90 cmp r0, r3
 *   @0xfef94 bge 0xfefe8 <_Z12F_DsMapEmptyR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0xfef98 ldr r3, [pc, #0x6c]
 *   @0xfef9c ldr r3, [pc, r3]
 *   @0xfefa0 ldr r3, [r3, #0x4]
 *   @0xfefa4 ldr r0, [r3, r0, lsl #2]
 *   @0xfefa8 cmp r0, #0
 *   @0xfefac beq 0xfefe8 <_Z12F_DsMapEmptyR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0xfefb0 mov r6, #0
 *   @0xfefb4 str r6, [r5, #0xc]
 *   @0xfefb8 bl 0x203a58 <_ZN7CDS_Map5EmptyEv>
 *   @0xfefbc cmp r0, #0
 *   @0xfefc0 moveq r6, r0
 *   @0xfefc4 movne r3, r6
 *   @0xfefc8 moveq r3, r6
 *   @0xfefcc movtne r3, #0x3ff0
 *   @0xfefd0 str r6, [r5]
 *   @0xfefd4 mov r0, r4
 *   @0xfefd8 str r3, [r5, #0x4]
 *   @0xfefdc bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xfefe0 add sp, sp, #8
 *   @0xfefe4 pop {r4, r5, r6, pc}
 *   @0xfefe8 ldr r0, [pc, #0x20]
 *   @0xfefec mov r1, #0
 *   @0xfeff0 add r0, pc, r0
 *   @0xfeff4 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfeff8 mov r0, r4
 *   @0xfeffc bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xff000 add sp, sp, #8
 *   @0xff004 pop {r4, r5, r6, pc}
 *   @0xff008 .word 0x002eecf0
 *   @0xff00c eoreq lr, lr, r0, lsr #19
 *   @0xff010 eoreq r8, r3, r12, lsl #24
 *
 * ══ §81/156 F_Point_In_Circle(RValue&, CInstance*, CInstance*, int, RValue*)  0x108698  size 192  48 条（0x108698..0x108758）
 * @func 0x108698 0x108758  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×5 / 0xb6700
 * 字段偏移 top8: 0x28×1 / 0xc×1 / 0x4×1
 * VFP 指令 18 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x108698 push {r3, r4, r5, lr}
 *   @0x10869c vpush {d8, d9, d10}
 *   @0x1086a0 mov r3, #0
 *   @0x1086a4 ldr r4, [sp, #0x28]
 *   @0x1086a8 mov r1, r3
 *   @0x1086ac str r3, [r0, #0xc]
 *   @0x1086b0 mov r5, r0
 *   @0x1086b4 str r3, [r0]
 *   @0x1086b8 str r3, [r0, #0x4]
 *   @0x1086bc mov r0, r4
 *   @0x1086c0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1086c4 mov r1, #1
 *   @0x1086c8 vmov s18, r0
 *   @0x1086cc mov r0, r4
 *   @0x1086d0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1086d4 mov r1, #2
 *   @0x1086d8 vmov s20, r0
 *   @0x1086dc mov r0, r4
 *   @0x1086e0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1086e4 mov r1, #3
 *   @0x1086e8 vmov s17, r0
 *   @0x1086ec mov r0, r4
 *   @0x1086f0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1086f4 mov r1, #4
 *   @0x1086f8 vmov s19, r0
 *   @0x1086fc mov r0, r4
 *   @0x108700 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x108704 vsub.f32 s15, s18, s17
 *   @0x108708 vsub.f32 s14, s20, s19
 *   @0x10870c vmul.f32 s14, s14, s14
 *   @0x108710 vmla.f32 s14, s15, s15
 *   @0x108714 vmov s16, r0
 *   @0x108718 vsqrt.f32 s15, s14
 *   @0x10871c vcmp.f32 s15, s15
 *   @0x108720 vmrs APSR_nzcv, fpscr
 *   @0x108724 bne 0x108748 <_Z17F_Point_In_CircleR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x108728 vcmpe.f32 s16, s15
 *   @0x10872c vmrs APSR_nzcv, fpscr
 *   @0x108730 movge r3, #0
 *   @0x108734 movge r2, r3
 *   @0x108738 movtge r3, #0x3ff0
 *   @0x10873c stmge r5, {r2, r3}
 *   @0x108740 vpop {d8, d9, d10}
 *   @0x108744 pop {r3, r4, r5, pc}
 *   @0x108748 vmov r0, s14
 *   @0x10874c bl 0xb6700 <sqrtf@plt>
 *   @0x108750 vmov s15, r0
 *   @0x108754 b 0x108728 <_Z17F_Point_In_CircleR6RValueP9CInstanceS2_iPS_+0x90>
 *
 * ══ §82/156 Point_In_Triangle(float, float, float, float, float, float, float, float)  0x10c328  size 192  48 条（0x10c328..0x10c3e8）
 * @func 0x10c328 0x10c3e8  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Point_In_Triangle(float, float, float, float, float, float, float, float)+0xb8×2
 * 字段偏移 top8: 无
 * VFP 指令 41 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10c328 vmov s14, r3
 *   @0x10c32c vldr s10, [sp, #4]
 *   @0x10c330 vldr s11, [sp, #12]
 *   @0x10c334 vmov s7, r2
 *   @0x10c338 vsub.f32 s11, s11, s14
 *   @0x10c33c vldr s12, [sp]
 *   @0x10c340 vldr s13, [sp, #8]
 *   @0x10c344 vmov s5, r1
 *   @0x10c348 vsub.f32 s10, s10, s14
 *   @0x10c34c vmul.f32 s15, s11, s10
 *   @0x10c350 vsub.f32 s12, s12, s7
 *   @0x10c354 vsub.f32 s13, s13, s7
 *   @0x10c358 vsub.f32 s6, s5, s14
 *   @0x10c35c vmov s5, r0
 *   @0x10c360 vmla.f32 s15, s13, s12
 *   @0x10c364 vmul.f32 s9, s11, s11
 *   @0x10c368 vmul.f32 s14, s10, s10
 *   @0x10c36c vmla.f32 s9, s13, s13
 *   @0x10c370 vmla.f32 s14, s12, s12
 *   @0x10c374 vmul.f32 s8, s15, s15
 *   @0x10c378 vmul.f32 s10, s10, s6
 *   @0x10c37c vsub.f32 s7, s5, s7
 *   @0x10c380 vnmls.f32 s8, s9, s14
 *   @0x10c384 vmla.f32 s10, s12, s7
 *   @0x10c388 vmul.f32 s11, s11, s6
 *   @0x10c38c vmov.f32 s12, #1.000000e+00
 *   @0x10c390 vmla.f32 s11, s13, s7
 *   @0x10c394 vdiv.f32 s8, s12, s8
 *   @0x10c398 vmul.f32 s13, s15, s10
 *   @0x10c39c vnmls.f32 s13, s14, s11
 *   @0x10c3a0 vmul.f32 s13, s13, s8
 *   @0x10c3a4 vcmpe.f32 s13, #0
 *   @0x10c3a8 vmrs APSR_nzcv, fpscr
 *   @0x10c3ac blt 0x10c3e0 <_Z17Point_In_Triangleffffffff+0xb8>
 *   @0x10c3b0 vmul.f32 s11, s15, s11
 *   @0x10c3b4 vnmls.f32 s11, s9, s10
 *   @0x10c3b8 vmul.f32 s11, s11, s8
 *   @0x10c3bc vcmpe.f32 s11, #0
 *   @0x10c3c0 vmrs APSR_nzcv, fpscr
 *   @0x10c3c4 blt 0x10c3e0 <_Z17Point_In_Triangleffffffff+0xb8>
 *   @0x10c3c8 vadd.f32 s11, s13, s11
 *   @0x10c3cc vcmpe.f32 s11, s12
 *   @0x10c3d0 vmrs APSR_nzcv, fpscr
 *   @0x10c3d4 movpl r0, #0
 *   @0x10c3d8 movmi r0, #1
 *   @0x10c3dc bx lr
 *   @0x10c3e0 mov r0, #0
 *   @0x10c3e4 bx lr
 *
 * ══ §83/156 utf8_stricmp  0x110a74  size 192  48 条（0x110a74..0x110b34）
 * @func 0x110a74 0x110b34  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: utf8_extract_char×4
 * 字段偏移 top8: 0x4×3 / 0x78×1 / 0x6c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x110a74 push {r4, r5, r6, r7, r8, lr}
 *   @0x110a78 sub sp, sp, #8
 *   @0x110a7c add r5, sp, #4
 *   @0x110a80 str r0, [sp, #0x4]
 *   @0x110a84 str r1, [sp]
 *   @0x110a88 b 0x110aec <utf8_stricmp+0x78>
 *   @0x110a8c ldr r8, [sp]
 *   @0x110a90 ldrb r3, [r8]
 *   @0x110a94 cmp r3, #0
 *   @0x110a98 beq 0x110b00 <utf8_stricmp+0x8c>
 *   @0x110a9c bl 0x10fb38 <utf8_extract_char>
 *   @0x110aa0 mov r4, r0
 *   @0x110aa4 mov r0, sp
 *   @0x110aa8 bl 0x10fb38 <utf8_extract_char>
 *   @0x110aac ldr r2, [pc, #0x78]
 *   @0x110ab0 cmp r4, #255
 *   @0x110ab4 mov r1, r4
 *   @0x110ab8 ldrls r2, [pc, r2]
 *   @0x110abc ldr r12, [pc, #0x6c]
 *   @0x110ac0 ldrls r2, [r2]
 *   @0x110ac4 addls r4, r2, r4, lsl #1
 *   @0x110ac8 ldrshls r1, [r4, #2]
 *   @0x110acc cmp r0, #255
 *   @0x110ad0 mov r2, r0
 *   @0x110ad4 ldrls r12, [pc, r12]
 *   @0x110ad8 ldrls r2, [r12]
 *   @0x110adc addls r3, r2, r0, lsl #1
 *   @0x110ae0 ldrshls r2, [r3, #2]
 *   @0x110ae4 cmp r1, r2
 *   @0x110ae8 bne 0x110b20 <utf8_stricmp+0xac>
 *   @0x110aec ldr r7, [sp, #0x4]
 *   @0x110af0 mov r0, r5
 *   @0x110af4 ldrb r3, [r7]
 *   @0x110af8 cmp r3, #0
 *   @0x110afc bne 0x110a8c <utf8_stricmp+0x18>
 *   @0x110b00 mov r0, r5
 *   @0x110b04 bl 0x10fb38 <utf8_extract_char>
 *   @0x110b08 mov r4, r0
 *   @0x110b0c mov r0, sp
 *   @0x110b10 bl 0x10fb38 <utf8_extract_char>
 *   @0x110b14 rsb r0, r0, r4
 *   @0x110b18 add sp, sp, #8
 *   @0x110b1c pop {r4, r5, r6, r7, r8, pc}
 *   @0x110b20 str r7, [sp, #0x4]
 *   @0x110b24 str r8, [sp]
 *   @0x110b28 b 0x110b00 <utf8_stricmp+0x8c>
 *   @0x110b2c eoreq r12, sp, r12, asr #29
 *   @0x110b30 .word 0x002dceb0
 *
 * ══ §84/156 String_Add(char const*&, char const*)  0x1115e4  size 192  48 条（0x1115e4..0x1116a4）
 * @func 0x1115e4 0x1116a4  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538×3 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / 0xb65bc×2 / String_Add(char const*&, char const*)+0x64 / YYFree(void const*)
 * 字段偏移 top8: 0x84×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1115e4 push {r4, r5, r6, r7, r8, lr}
 *   @0x1115e8 mov r4, r0
 *   @0x1115ec ldr r5, [r0]
 *   @0x1115f0 mov r8, r1
 *   @0x1115f4 cmp r5, #0
 *   @0x1115f8 beq 0x11166c <_Z10String_AddRPKcS0_+0x88>
 *   @0x1115fc mov r0, r5
 *   @0x111600 bl 0xb6538 <strlen@plt>
 *   @0x111604 mov r5, r0
 *   @0x111608 mov r0, r8
 *   @0x11160c bl 0xb6538 <strlen@plt>
 *   @0x111610 ldr r1, [pc, #0x84]
 *   @0x111614 movw r2, #0x8b4
 *   @0x111618 mov r3, #1
 *   @0x11161c add r1, pc, r1
 *   @0x111620 mov r7, r0
 *   @0x111624 add r0, r5, r0
 *   @0x111628 add r0, r0, #1
 *   @0x11162c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x111630 cmp r5, #0
 *   @0x111634 mov r6, r0
 *   @0x111638 ble 0x111648 <_Z10String_AddRPKcS0_+0x64>
 *   @0x11163c ldr r1, [r4]
 *   @0x111640 mov r2, r5
 *   @0x111644 bl 0xb65bc <memcpy@plt>
 *   @0x111648 mov r0, r5
 *   @0x11164c mov r1, r8
 *   @0x111650 mov r2, r7
 *   @0x111654 add r0, r6, r0
 *   @0x111658 bl 0xb65bc <memcpy@plt>
 *   @0x11165c ldr r0, [r4]
 *   @0x111660 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x111664 str r6, [r4]
 *   @0x111668 pop {r4, r5, r6, r7, r8, pc}
 *   @0x11166c mov r0, r1
 *   @0x111670 bl 0xb6538 <strlen@plt>
 *   @0x111674 ldr r1, [pc, #0x24]
 *   @0x111678 movw r2, #0x8b4
 *   @0x11167c mov r3, #1
 *   @0x111680 add r1, pc, r1
 *   @0x111684 mov r7, r0
 *   @0x111688 add r0, r0, #1
 *   @0x11168c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x111690 mov r6, r0
 *   @0x111694 mov r0, r5
 *   @0x111698 b 0x11164c <_Z10String_AddRPKcS0_+0x68>
 *   @0x11169c eoreq r7, r2, r8, lsr #16
 *   @0x1116a0 eoreq r7, r2, r4, asr #15
 *
 * ══ §85/156 F_SurfaceSave(RValue&, CInstance*, CInstance*, int, RValue*)  0x11ef28  size 192  48 条（0x11ef28..0x11efe8）
 * @func 0x11ef28 0x11efe8  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetString(RValue const*, int) / GR_Surface_Exists(int) / GR_Surface_Get_Width(int) / GR_Surface_Get_Height(int) / GR_Surface_Get_Texture(int) / GR_Texture_Get_Surface(int) / Graphics::Surface_GrabRect(void*, int, int, int, int)
 * 字段偏移 top8: 0x20×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11ef28 push {r4, r5, r6, r7, lr}
 *   @0x11ef2c sub sp, sp, #12
 *   @0x11ef30 mov r1, #0
 *   @0x11ef34 ldr r5, [sp, #0x20]
 *   @0x11ef38 mov r0, r5
 *   @0x11ef3c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11ef40 mov r1, #1
 *   @0x11ef44 mov r4, r0
 *   @0x11ef48 mov r0, r5
 *   @0x11ef4c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x11ef50 mov r7, r0
 *   @0x11ef54 mov r0, r4
 *   @0x11ef58 bl 0x1714c0 <_Z17GR_Surface_Existsi>
 *   @0x11ef5c subs r1, r0, #0
 *   @0x11ef60 beq 0x11efc8 <_Z13F_SurfaceSaveR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x11ef64 mov r0, r4
 *   @0x11ef68 bl 0x1714d4 <_Z20GR_Surface_Get_Widthi>
 *   @0x11ef6c mov r6, r0
 *   @0x11ef70 mov r0, r4
 *   @0x11ef74 bl 0x171518 <_Z21GR_Surface_Get_Heighti>
 *   @0x11ef78 mov r5, r0
 *   @0x11ef7c mov r0, r4
 *   @0x11ef80 bl 0x17155c <_Z22GR_Surface_Get_Texturei>
 *   @0x11ef84 bl 0x17435c <_Z22GR_Texture_Get_Surfacei>
 *   @0x11ef88 mov r1, #0
 *   @0x11ef8c str r5, [sp]
 *   @0x11ef90 mov r3, r6
 *   @0x11ef94 mov r2, r1
 *   @0x11ef98 bl 0x17e594 <_ZN8Graphics16Surface_GrabRectEPviiii>
 *   @0x11ef9c subs r4, r0, #0
 *   @0x11efa0 beq 0x11efdc <_Z13F_SurfaceSaveR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x11efa4 mov r0, r7
 *   @0x11efa8 mov r2, r6
 *   @0x11efac mov r3, r5
 *   @0x11efb0 mov r1, r4
 *   @0x11efb4 bl 0x16cc8c <_Z10WritePNG32PcPvii>
 *   @0x11efb8 mov r0, r4
 *   @0x11efbc add sp, sp, #12
 *   @0x11efc0 pop {r4, r5, r6, r7, lr}
 *   @0x11efc4 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x11efc8 ldr r0, [pc, #0x14]
 *   @0x11efcc add r0, pc, r0
 *   @0x11efd0 add sp, sp, #12
 *   @0x11efd4 pop {r4, r5, r6, r7, lr}
 *   @0x11efd8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11efdc add sp, sp, #12
 *   @0x11efe0 pop {r4, r5, r6, r7, pc}
 *   @0x11efe4 mlaeq r1, r12, r2, r11
 *
 * ══ §86/156 F_SkeletonAnimationList(RValue&, CInstance*, CInstance*, int, RValue*)  0x11fc94  size 192  48 条（0x11fc94..0x11fd54）
 * @func 0x11fc94 0x11fd54  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / Sprite_Data(int) / F_SkeletonAnimationList(RValue&, CInstance*, CInstance*, int, RValue*)+0x9c
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x74×1 / 0x6c×1 / 0x48×1 / 0x38×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11fc94 push {r3, r4, r5, lr}
 *   @0x11fc98 mov r1, #0
 *   @0x11fc9c ldr r4, [sp, #0x10]
 *   @0x11fca0 mov r3, r1
 *   @0x11fca4 str r1, [r0, #0xc]
 *   @0x11fca8 movt r3, #0xbff0
 *   @0x11fcac stm r0, {r1, r3}
 *   @0x11fcb0 mov r0, r4
 *   @0x11fcb4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11fcb8 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x11fcbc subs r5, r0, #0
 *   @0x11fcc0 beq 0x11fcd0 <_Z23F_SkeletonAnimationListR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x11fcc4 ldr r3, [r5, #0x74]
 *   @0x11fcc8 cmp r3, #2
 *   @0x11fccc beq 0x11fce4 <_Z23F_SkeletonAnimationListR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x11fcd0 ldr r0, [pc, #0x6c]
 *   @0x11fcd4 mov r1, #0
 *   @0x11fcd8 pop {r3, r4, r5, lr}
 *   @0x11fcdc add r0, pc, r0
 *   @0x11fce0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11fce4 mov r0, r4
 *   @0x11fce8 mov r1, #1
 *   @0x11fcec bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11fcf0 cmp r0, #0
 *   @0x11fcf4 blt 0x11fd30 <_Z23F_SkeletonAnimationListR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x11fcf8 ldr r3, [pc, #0x48]
 *   @0x11fcfc ldr r3, [pc, r3]
 *   @0x11fd00 ldr r3, [r3]
 *   @0x11fd04 cmp r0, r3
 *   @0x11fd08 bge 0x11fd30 <_Z23F_SkeletonAnimationListR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x11fd0c ldr r3, [pc, #0x38]
 *   @0x11fd10 ldr r3, [pc, r3]
 *   @0x11fd14 ldr r3, [r3, #0x4]
 *   @0x11fd18 ldr r1, [r3, r0, lsl #2]
 *   @0x11fd1c cmp r1, #0
 *   @0x11fd20 beq 0x11fd30 <_Z23F_SkeletonAnimationListR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x11fd24 ldr r0, [r5, #0x58]
 *   @0x11fd28 pop {r3, r4, r5, lr}
 *   @0x11fd2c b 0xc1bd8 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List>
 *   @0x11fd30 ldr r0, [pc, #0x18]
 *   @0x11fd34 mov r1, #0
 *   @0x11fd38 pop {r3, r4, r5, lr}
 *   @0x11fd3c add r0, pc, r0
 *   @0x11fd40 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11fd44 eoreq r10, r1, r8, asr #13
 *   @0x11fd48 eoreq sp, r12, r0, lsl #31
 *   @0x11fd4c eoreq sp, r12, r0, ror pc
 *   @0x11fd50 eoreq r7, r1, r0, asr #29
 *
 * ══ §87/156 F_SkeletonSkinList(RValue&, CInstance*, CInstance*, int, RValue*)  0x11fd54  size 192  48 条（0x11fd54..0x11fe14）
 * @func 0x11fd54 0x11fe14  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / Sprite_Data(int) / F_SkeletonSkinList(RValue&, CInstance*, CInstance*, int, RValue*)+0x9c
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x74×1 / 0x6c×1 / 0x48×1 / 0x38×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11fd54 push {r3, r4, r5, lr}
 *   @0x11fd58 mov r1, #0
 *   @0x11fd5c ldr r4, [sp, #0x10]
 *   @0x11fd60 mov r3, r1
 *   @0x11fd64 str r1, [r0, #0xc]
 *   @0x11fd68 movt r3, #0xbff0
 *   @0x11fd6c stm r0, {r1, r3}
 *   @0x11fd70 mov r0, r4
 *   @0x11fd74 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11fd78 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x11fd7c subs r5, r0, #0
 *   @0x11fd80 beq 0x11fd90 <_Z18F_SkeletonSkinListR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x11fd84 ldr r3, [r5, #0x74]
 *   @0x11fd88 cmp r3, #2
 *   @0x11fd8c beq 0x11fda4 <_Z18F_SkeletonSkinListR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x11fd90 ldr r0, [pc, #0x6c]
 *   @0x11fd94 mov r1, #0
 *   @0x11fd98 pop {r3, r4, r5, lr}
 *   @0x11fd9c add r0, pc, r0
 *   @0x11fda0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11fda4 mov r0, r4
 *   @0x11fda8 mov r1, #1
 *   @0x11fdac bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11fdb0 cmp r0, #0
 *   @0x11fdb4 blt 0x11fdf0 <_Z18F_SkeletonSkinListR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x11fdb8 ldr r3, [pc, #0x48]
 *   @0x11fdbc ldr r3, [pc, r3]
 *   @0x11fdc0 ldr r3, [r3]
 *   @0x11fdc4 cmp r0, r3
 *   @0x11fdc8 bge 0x11fdf0 <_Z18F_SkeletonSkinListR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x11fdcc ldr r3, [pc, #0x38]
 *   @0x11fdd0 ldr r3, [pc, r3]
 *   @0x11fdd4 ldr r3, [r3, #0x4]
 *   @0x11fdd8 ldr r1, [r3, r0, lsl #2]
 *   @0x11fddc cmp r1, #0
 *   @0x11fde0 beq 0x11fdf0 <_Z18F_SkeletonSkinListR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x11fde4 ldr r0, [r5, #0x58]
 *   @0x11fde8 pop {r3, r4, r5, lr}
 *   @0x11fdec b 0xc1974 <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List>
 *   @0x11fdf0 ldr r0, [pc, #0x18]
 *   @0x11fdf4 mov r1, #0
 *   @0x11fdf8 pop {r3, r4, r5, lr}
 *   @0x11fdfc add r0, pc, r0
 *   @0x11fe00 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11fe04 eoreq r10, r1, r12, lsr r6
 *   @0x11fe08 eoreq sp, r12, r0, asr #29
 *   @0x11fe0c .word 0x002cdeb0
 *   @0x11fe10 eoreq r7, r1, r0, lsl #28
 *
 * ══ §88/156 F_SkeletonSlotData(RValue&, CInstance*, CInstance*, int, RValue*)  0x11fe14  size 192  48 条（0x11fe14..0x11fed4）
 * @func 0x11fe14 0x11fed4  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / Sprite_Data(int) / F_SkeletonSlotData(RValue&, CInstance*, CInstance*, int, RValue*)+0x9c
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x74×1 / 0x6c×1 / 0x48×1 / 0x38×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11fe14 push {r3, r4, r5, lr}
 *   @0x11fe18 mov r1, #0
 *   @0x11fe1c ldr r4, [sp, #0x10]
 *   @0x11fe20 mov r3, r1
 *   @0x11fe24 str r1, [r0, #0xc]
 *   @0x11fe28 movt r3, #0xbff0
 *   @0x11fe2c stm r0, {r1, r3}
 *   @0x11fe30 mov r0, r4
 *   @0x11fe34 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11fe38 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x11fe3c subs r5, r0, #0
 *   @0x11fe40 beq 0x11fe50 <_Z18F_SkeletonSlotDataR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x11fe44 ldr r3, [r5, #0x74]
 *   @0x11fe48 cmp r3, #2
 *   @0x11fe4c beq 0x11fe64 <_Z18F_SkeletonSlotDataR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x11fe50 ldr r0, [pc, #0x6c]
 *   @0x11fe54 mov r1, #0
 *   @0x11fe58 pop {r3, r4, r5, lr}
 *   @0x11fe5c add r0, pc, r0
 *   @0x11fe60 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11fe64 mov r0, r4
 *   @0x11fe68 mov r1, #1
 *   @0x11fe6c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11fe70 cmp r0, #0
 *   @0x11fe74 blt 0x11feb0 <_Z18F_SkeletonSlotDataR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x11fe78 ldr r3, [pc, #0x48]
 *   @0x11fe7c ldr r3, [pc, r3]
 *   @0x11fe80 ldr r3, [r3]
 *   @0x11fe84 cmp r0, r3
 *   @0x11fe88 bge 0x11feb0 <_Z18F_SkeletonSlotDataR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x11fe8c ldr r3, [pc, #0x38]
 *   @0x11fe90 ldr r3, [pc, r3]
 *   @0x11fe94 ldr r3, [r3, #0x4]
 *   @0x11fe98 ldr r1, [r3, r0, lsl #2]
 *   @0x11fe9c cmp r1, #0
 *   @0x11fea0 beq 0x11feb0 <_Z18F_SkeletonSlotDataR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x11fea4 ldr r0, [r5, #0x58]
 *   @0x11fea8 pop {r3, r4, r5, lr}
 *   @0x11feac b 0xc1350 <_ZN15CSkeletonSprite11GetSlotDataEP8CDS_List>
 *   @0x11feb0 ldr r0, [pc, #0x18]
 *   @0x11feb4 mov r1, #0
 *   @0x11feb8 pop {r3, r4, r5, lr}
 *   @0x11febc add r0, pc, r0
 *   @0x11fec0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11fec4 eoreq r10, r1, r12, lsr #11
 *   @0x11fec8 eoreq sp, r12, r0, lsl #28
 *   @0x11fecc .word 0x002cddf0
 *   @0x11fed0 eoreq r7, r1, r0, asr #26
 *
 * ══ §89/156 F_PartSystemCreateLayer(RValue&, CInstance*, CInstance*, int, RValue*)  0x129768  size 192  48 条（0x129768..0x129828）
 * @func 0x129768 0x129828  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetLayerFromID(CRoom*, int) / F_PartSystemCreateLayer(RValue&, CInstance*, CInstance*, int, RValue*)+0x70 / YYGetBool(RValue const*, int) / ParticleSystem_Create(int, bool) / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0xc×2 / 0x18×1 / 0x4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x129768 push {r4, r5, r6, r7, r8, lr}
 *   @0x12976c mov r6, #0
 *   @0x129770 str r6, [r0, #0xc]
 *   @0x129774 mov r4, r0
 *   @0x129778 ldr r5, [sp, #0x18]
 *   @0x12977c mov r8, r3
 *   @0x129780 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x129784 mov r1, r6
 *   @0x129788 ldr r2, [r5, #0xc]
 *   @0x12978c bic r2, r2, #-16777216
 *   @0x129790 cmp r2, #1
 *   @0x129794 mov r7, r0
 *   @0x129798 mov r0, r5
 *   @0x12979c beq 0x1297fc <_Z23F_PartSystemCreateLayerR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x1297a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1297a4 mov r1, r0
 *   @0x1297a8 mov r0, r7
 *   @0x1297ac bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1297b0 cmp r0, #0
 *   @0x1297b4 beq 0x129814 <_Z23F_PartSystemCreateLayerR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x1297b8 cmp r8, #1
 *   @0x1297bc ldr r6, [r0]
 *   @0x1297c0 movle r1, #0
 *   @0x1297c4 ble 0x1297d8 <_Z23F_PartSystemCreateLayerR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x1297c8 mov r1, #1
 *   @0x1297cc mov r0, r5
 *   @0x1297d0 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x1297d4 mov r1, r0
 *   @0x1297d8 mov r0, r6
 *   @0x1297dc bl 0x1a42dc <_Z21ParticleSystem_Createib>
 *   @0x1297e0 vmov s15, r0
 *   @0x1297e4 vcvt.f64.s32 d7, s15
 *   @0x1297e8 vmov r0, r1, d7
 *   @0x1297ec vmov r2, s14
 *   @0x1297f0 mov r3, r1
 *   @0x1297f4 stm r4, {r2, r3}
 *   @0x1297f8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1297fc bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x129800 mov r1, r0
 *   @0x129804 mov r0, r7
 *   @0x129808 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x12980c cmp r0, #0
 *   @0x129810 bne 0x1297b8 <_Z23F_PartSystemCreateLayerR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x129814 mov r3, #0
 *   @0x129818 str r0, [r4]
 *   @0x12981c movt r3, #0xbff0
 *   @0x129820 str r3, [r4, #0x4]
 *   @0x129824 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §90/156 yyFindData::AddFile(char const*)  0x13ac60  size 192  48 条（0x13ac60..0x13ad20）
 * @func 0x13ac60 0x13ad20  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6574×3 / yyFindData::AddFile(char const*)+0x70 / 0xb6544 / 0xb65bc / 0xb655c / 0xb6640
 * 字段偏移 top8: 0x4×3 / 0x8×2 / 0xa8×1 / 0x90×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13ac60 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x13ac64 mov r6, r1
 *   @0x13ac68 ldr r1, [pc, #0xa8]
 *   @0x13ac6c mov r8, r0
 *   @0x13ac70 mov r0, r6
 *   @0x13ac74 add r1, pc, r1
 *   @0x13ac78 bl 0xb6574 <strcmp@plt>
 *   @0x13ac7c cmp r0, #0
 *   @0x13ac80 popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x13ac84 ldr r1, [pc, #0x90]
 *   @0x13ac88 mov r0, r6
 *   @0x13ac8c add r1, pc, r1
 *   @0x13ac90 bl 0xb6574 <strcmp@plt>
 *   @0x13ac94 cmp r0, #0
 *   @0x13ac98 popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x13ac9c ldmib r8, {r7, r9}
 *   @0x13aca0 cmp r7, #0
 *   @0x13aca4 subgt r5, r9, #4
 *   @0x13aca8 movgt r4, #0
 *   @0x13acac ble 0x13acd0 <_ZN10yyFindData7AddFileEPKc+0x70>
 *   @0x13acb0 mov r0, r6
 *   @0x13acb4 ldr r1, [r5, #0x4]!
 *   @0x13acb8 bl 0xb6574 <strcmp@plt>
 *   @0x13acbc add r4, r4, #1
 *   @0x13acc0 cmp r0, #0
 *   @0x13acc4 popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x13acc8 cmp r4, r7
 *   @0x13accc bne 0x13acb0 <_ZN10yyFindData7AddFileEPKc+0x50>
 *   @0x13acd0 add r7, r7, #1
 *   @0x13acd4 str r7, [r8, #0x4]
 *   @0x13acd8 lsl r7, r7, #2
 *   @0x13acdc mov r0, r7
 *   @0x13ace0 bl 0xb6544 <malloc@plt>
 *   @0x13ace4 mov r1, r9
 *   @0x13ace8 sub r2, r7, #4
 *   @0x13acec mov r4, r0
 *   @0x13acf0 bl 0xb65bc <memcpy@plt>
 *   @0x13acf4 ldr r0, [r8, #0x8]
 *   @0x13acf8 bl 0xb655c <free@plt>
 *   @0x13acfc str r4, [r8, #0x8]
 *   @0x13ad00 mov r0, r6
 *   @0x13ad04 ldr r5, [r8, #0x4]
 *   @0x13ad08 bl 0xb6640 <strdup@plt>
 *   @0x13ad0c sub r5, r5, #-1073741823
 *   @0x13ad10 str r0, [r4, r5, lsl #2]
 *   @0x13ad14 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x13ad18 eoreq r5, r0, r8, asr #13
 *   @0x13ad1c .word 0x002056b4
 *
 * ══ §91/156 F_ActionEffect(RValue&, CInstance*, CInstance*, int, RValue*)  0x140a0c  size 192  48 条（0x140a0c..0x140acc）
 * @func 0x140a0c 0x140acc  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / YYGetFloat(RValue const*, int)×2 / YYGetBool(RValue const*, int) / Effect_Create(bool, int, float, float, int, unsigned int)
 * 字段偏移 top8: 0x28×1 / 0x44×1 / 0x4×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x140a0c push {r4, r5, r6, r7, r8, lr}
 *   @0x140a10 vpush {d8}
 *   @0x140a14 sub sp, sp, #8
 *   @0x140a18 mov r8, r1
 *   @0x140a1c mov r1, #0
 *   @0x140a20 ldr r4, [sp, #0x28]
 *   @0x140a24 mov r0, r4
 *   @0x140a28 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x140a2c mov r1, #1
 *   @0x140a30 mov r6, r0
 *   @0x140a34 mov r0, r4
 *   @0x140a38 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x140a3c mov r1, #2
 *   @0x140a40 vmov s17, r0
 *   @0x140a44 mov r0, r4
 *   @0x140a48 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x140a4c mov r1, #3
 *   @0x140a50 vmov s16, r0
 *   @0x140a54 mov r0, r4
 *   @0x140a58 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x140a5c mov r1, #4
 *   @0x140a60 mov r7, r0
 *   @0x140a64 mov r0, r4
 *   @0x140a68 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x140a6c mov r1, #5
 *   @0x140a70 mov r5, r0
 *   @0x140a74 mov r0, r4
 *   @0x140a78 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x140a7c ldr r3, [pc, #0x44]
 *   @0x140a80 mov r1, r6
 *   @0x140a84 ldr r3, [pc, r3]
 *   @0x140a88 ldrb r3, [r3]
 *   @0x140a8c str r7, [sp]
 *   @0x140a90 cmp r3, #0
 *   @0x140a94 str r5, [sp, #0x4]
 *   @0x140a98 vldrne s14, [r8, #180]
 *   @0x140a9c vldrne s15, [r8, #184]
 *   @0x140aa0 vmoveq r2, s17
 *   @0x140aa4 vmoveq r3, s16
 *   @0x140aa8 vaddne.f32 s14, s17, s14
 *   @0x140aac vaddne.f32 s15, s16, s15
 *   @0x140ab0 vmovne r2, s14
 *   @0x140ab4 vmovne r3, s15
 *   @0x140ab8 bl 0x1a25d0 <_Z13Effect_Createbiffij>
 *   @0x140abc add sp, sp, #8
 *   @0x140ac0 vpop {d8}
 *   @0x140ac4 pop {r4, r5, r6, r7, r8, pc}
 *   @0x140ac8 strhteq sp, [r10], -r8
 *
 * ══ §92/156 F_PhysicsFixtureSetBoxShape(RValue&, CInstance*, CInstance*, int, RValue*)  0x14c2e4  size 192  48 条（0x14c2e4..0x14c3a4）
 * @func 0x14c2e4 0x14c3a4  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / YYGetInt32(RValue const*, int) / CPhysicsFixtureFactory::FindFixture(unsigned int)
 * 字段偏移 top8: 0x18×1 / 0x88×1 / 0xb4×1 / 0x24×1 / 0x10×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14c2e4 push {r4, r5, r6, lr}
 *   @0x14c2e8 vpush {d8}
 *   @0x14c2ec mov r1, #0
 *   @0x14c2f0 ldr r5, [sp, #0x18]
 *   @0x14c2f4 mov r0, r5
 *   @0x14c2f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14c2fc bl 0x236404 <_ZN22CPhysicsFixtureFactory11FindFixtureEj>
 *   @0x14c300 subs r6, r0, #0
 *   @0x14c304 beq 0x14c380 <_Z27F_PhysicsFixtureSetBoxShapeR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x14c308 ldr r3, [pc, #0x88]
 *   @0x14c30c ldr r3, [pc, r3]
 *   @0x14c310 ldr r3, [r3]
 *   @0x14c314 ldr r4, [r3, #0xb4]
 *   @0x14c318 cmp r4, #0
 *   @0x14c31c beq 0x14c368 <_Z27F_PhysicsFixtureSetBoxShapeR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x14c320 mov r0, r5
 *   @0x14c324 mov r1, #1
 *   @0x14c328 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14c32c mov r1, #2
 *   @0x14c330 vldr s16, [r4, #96]
 *   @0x14c334 vmov s14, r0
 *   @0x14c338 mov r0, r5
 *   @0x14c33c vmul.f32 s16, s14, s16
 *   @0x14c340 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14c344 vldr s15, [r4, #96]
 *   @0x14c348 vmov r1, s16
 *   @0x14c34c vpop {d8}
 *   @0x14c350 vmov s14, r0
 *   @0x14c354 mov r0, r6
 *   @0x14c358 pop {r4, r5, r6, lr}
 *   @0x14c35c vmul.f32 s15, s14, s15
 *   @0x14c360 vmov r2, s15
 *   @0x14c364 b 0x2367d8 <_ZN15CPhysicsFixture11SetBoxShapeEff>
 *   @0x14c368 vpop {d8}
 *   @0x14c36c mov r1, r4
 *   @0x14c370 ldr r0, [pc, #0x24]
 *   @0x14c374 add r0, pc, r0
 *   @0x14c378 pop {r4, r5, r6, lr}
 *   @0x14c37c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14c380 vpop {d8}
 *   @0x14c384 mov r1, r6
 *   @0x14c388 ldr r0, [pc, #0x10]
 *   @0x14c38c add r0, pc, r0
 *   @0x14c390 pop {r4, r5, r6, lr}
 *   @0x14c394 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14c398 eoreq r1, r10, r12, lsl r6
 *   @0x14c39c ldrheq r7, [pc], -r0
 *   @0x14c3a0 andseq r7, pc, r12, lsl r10
 *
 * ══ §93/156 YYIAPPurchaseEvent(char const*)  0x1554ac  size 192  48 条（0x1554ac..0x15556c）
 * @func 0x1554ac 0x15556c  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Mutex::Lock() / json_tokener_parse / YYIAPPurchaseEvent(char const*)+0x64 / anon_154a70 / anon_153020+0x1ac
 * 字段偏移 top8: 0x48×2 / 0xa0×1 / 0x78×1 / 0x74×1 / 0xc×1 / 0x5c×1 / 0x4×1 / 0x10×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1554ac ldr r3, [pc, #0xa0]
 *   @0x1554b0 push {r4, lr}
 *   @0x1554b4 add r3, pc, r3
 *   @0x1554b8 sub sp, sp, #24
 *   @0x1554bc mov r4, r0
 *   @0x1554c0 ldr r0, [r3]
 *   @0x1554c4 bl 0x27e084 <_ZN5Mutex4LockEv>
 *   @0x1554c8 mov r0, r4
 *   @0x1554cc bl 0x28075c <json_tokener_parse>
 *   @0x1554d0 cmn r0, #4000
 *   @0x1554d4 bls 0x155510 <_Z18YYIAPPurchaseEventPKc+0x64>
 *   @0x1554d8 ldr r3, [pc, #0x78]
 *   @0x1554dc mov r2, r4
 *   @0x1554e0 ldr r1, [pc, #0x74]
 *   @0x1554e4 ldr r3, [pc, r3]
 *   @0x1554e8 add r1, pc, r1
 *   @0x1554ec ldr r0, [r3]
 *   @0x1554f0 ldr r3, [r0]
 *   @0x1554f4 ldr r3, [r3, #0xc]
 *   @0x1554f8 blx r3
 *   @0x1554fc ldr r3, [pc, #0x5c]
 *   @0x155500 ldr r0, [pc, r3]
 *   @0x155504 add sp, sp, #24
 *   @0x155508 pop {r4, lr}
 *   @0x15550c b 0x27e09c <_ZN5Mutex6UnlockEv>
 *   @0x155510 vmov s13, r0
 *   @0x155514 ldr r2, [pc, #0x48]
 *   @0x155518 ldr r1, [pc, #0x48]
 *   @0x15551c mov r3, #0
 *   @0x155520 vcvt.f64.s32 d7, s13
 *   @0x155524 add r2, pc, r2
 *   @0x155528 str r3, [sp]
 *   @0x15552c add r1, pc, r1
 *   @0x155530 str r2, [sp, #0x4]
 *   @0x155534 mov r0, #2
 *   @0x155538 str r3, [sp, #0x10]
 *   @0x15553c mov r2, #0
 *   @0x155540 mov r3, #1073741824
 *   @0x155544 vstr d7, [sp, #8]
 *   @0x155548 bl 0x154a70 <_Z19YYIAPEventsDispatchv+0xe88>
 *   @0x15554c bl 0x1531cc <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x1d8>
 *   @0x155550 b 0x1554fc <_Z18YYIAPPurchaseEventPKc+0x50>
 *   @0x155554 eorseq pc, r2, r12, lsl #11
 *   @0x155558 eoreq r8, r9, r12, asr r4
 *   @0x15555c andseq r0, pc, r8, ror #28
 *   @0x155560 eorseq pc, r2, r0, asr #10
 *   @0x155564 ldrsbeq r0, [pc], -r12
 *   @0x155568 ldrsheq r0, [pc], -r12
 *
 * ══ §94/156 F_YoYo_FacebookPostMessage(RValue&, CInstance*, CInstance*, int, RValue*)  0x157390  size 192  48 条（0x157390..0x157450）
 * @func 0x157390 0x157450  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)×7 / FacebookPostMessageM(char*, char*, char*, char*, char*, char*, char*)
 * 字段偏移 top8: 0x38×1 / 0xc×1 / 0x4×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x157390 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x157394 sub sp, sp, #20
 *   @0x157398 mov r5, r0
 *   @0x15739c mov r1, #0
 *   @0x1573a0 ldr r4, [sp, #0x38]
 *   @0x1573a4 str r1, [r0, #0xc]
 *   @0x1573a8 mov r0, r4
 *   @0x1573ac bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1573b0 mov r1, #1
 *   @0x1573b4 mov r6, r0
 *   @0x1573b8 mov r0, r4
 *   @0x1573bc bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1573c0 mov r1, #2
 *   @0x1573c4 mov r9, r0
 *   @0x1573c8 mov r0, r4
 *   @0x1573cc bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1573d0 mov r1, #3
 *   @0x1573d4 mov r8, r0
 *   @0x1573d8 mov r0, r4
 *   @0x1573dc bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1573e0 mov r1, #4
 *   @0x1573e4 mov r7, r0
 *   @0x1573e8 mov r0, r4
 *   @0x1573ec bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1573f0 mov r1, #5
 *   @0x1573f4 mov r11, r0
 *   @0x1573f8 mov r0, r4
 *   @0x1573fc bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x157400 mov r1, #6
 *   @0x157404 mov r10, r0
 *   @0x157408 mov r0, r4
 *   @0x15740c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x157410 mov r1, r9
 *   @0x157414 mov r2, r8
 *   @0x157418 mov r3, r7
 *   @0x15741c str r11, [sp]
 *   @0x157420 str r10, [sp, #0x4]
 *   @0x157424 str r0, [sp, #0x8]
 *   @0x157428 mov r0, r6
 *   @0x15742c bl 0x15e8a0 <_Z20FacebookPostMessageMPcS_S_S_S_S_S_>
 *   @0x157430 vmov s15, r0
 *   @0x157434 vcvt.f64.s32 d7, s15
 *   @0x157438 vmov r0, r1, d7
 *   @0x15743c vmov r2, s14
 *   @0x157440 mov r3, r1
 *   @0x157444 stm r5, {r2, r3}
 *   @0x157448 add sp, sp, #20
 *   @0x15744c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §95/156 LeaveRating(char*, char const*, char const*, char const*)  0x15e538  size 192  48 条（0x15e538..0x15e5f8）
 * @func 0x15e538 0x15e5f8  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×5 / _JNIEnv::CallStaticVoidMethod(_jclass*, _jmethodID*, ...)
 * 字段偏移 top8: 0x29c×4 / 0x34×1 / 0x30×1 / 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15e538 push {r4, r5, r6, r7, lr}
 *   @0x15e53c sub sp, sp, #20
 *   @0x15e540 mov r4, r2
 *   @0x15e544 mov r6, r1
 *   @0x15e548 mov r7, r3
 *   @0x15e54c mov r5, r0
 *   @0x15e550 bl 0x290274 <getJNIEnv>
 *   @0x15e554 mov r1, r7
 *   @0x15e558 ldr r3, [r0]
 *   @0x15e55c ldr r3, [r3, #0x29c]
 *   @0x15e560 blx r3
 *   @0x15e564 mov r7, r0
 *   @0x15e568 bl 0x290274 <getJNIEnv>
 *   @0x15e56c mov r1, r4
 *   @0x15e570 ldr r3, [r0]
 *   @0x15e574 ldr r3, [r3, #0x29c]
 *   @0x15e578 blx r3
 *   @0x15e57c mov r4, r0
 *   @0x15e580 bl 0x290274 <getJNIEnv>
 *   @0x15e584 mov r1, r6
 *   @0x15e588 ldr r3, [r0]
 *   @0x15e58c ldr r3, [r3, #0x29c]
 *   @0x15e590 blx r3
 *   @0x15e594 mov r6, r0
 *   @0x15e598 bl 0x290274 <getJNIEnv>
 *   @0x15e59c mov r1, r5
 *   @0x15e5a0 ldr r3, [r0]
 *   @0x15e5a4 ldr r3, [r3, #0x29c]
 *   @0x15e5a8 blx r3
 *   @0x15e5ac mov r5, r0
 *   @0x15e5b0 bl 0x290274 <getJNIEnv>
 *   @0x15e5b4 ldr r1, [pc, #0x34]
 *   @0x15e5b8 mov r3, r5
 *   @0x15e5bc ldr r2, [pc, #0x30]
 *   @0x15e5c0 ldr r1, [pc, r1]
 *   @0x15e5c4 ldr r2, [pc, r2]
 *   @0x15e5c8 ldr r1, [r1]
 *   @0x15e5cc ldr r2, [r2]
 *   @0x15e5d0 str r7, [sp, #0x8]
 *   @0x15e5d4 str r6, [sp]
 *   @0x15e5d8 str r4, [sp, #0x4]
 *   @0x15e5dc bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x15e5e0 mov r0, #0
 *   @0x15e5e4 mov r1, #0
 *   @0x15e5e8 add sp, sp, #20
 *   @0x15e5ec pop {r4, r5, r6, r7, pc}
 *   @0x15e5f0 eoreq pc, r8, r4, ror #7
 *   @0x15e5f4 .word 0x002918d0
 *
 * ══ §96/156 EmbeddedImages_Load(unsigned char*, unsigned int, unsigned char*)  0x176830  size 192  48 条（0x176830..0x1768f0）
 * @func 0x176830 0x1768f0  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x4×2 / 0x74×2 / 0x84×1 / 0x5c×1 / 0x-8×1 / 0x-c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x176830 ldr r3, [r0]
 *   @0x176834 push {r5, r6, r7, lr}
 *   @0x176838 cmp r3, #1
 *   @0x17683c mov r5, r0
 *   @0x176840 beq 0x17684c <_Z19EmbeddedImages_LoadPhjS_+0x1c>
 *   @0x176844 mov r0, #0
 *   @0x176848 pop {r5, r6, r7, pc}
 *   @0x17684c ldr r7, [r0, #0x4]
 *   @0x176850 mov r2, #70
 *   @0x176854 ldr r1, [pc, #0x84]
 *   @0x176858 lsl r6, r7, #3
 *   @0x17685c add r1, pc, r1
 *   @0x176860 mov r0, r6
 *   @0x176864 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x176868 ldr r2, [pc, #0x74]
 *   @0x17686c ldr r3, [pc, #0x74]
 *   @0x176870 cmp r7, #0
 *   @0x176874 ldr r2, [pc, r2]
 *   @0x176878 ldr r3, [pc, r3]
 *   @0x17687c str r7, [r3]
 *   @0x176880 str r0, [r2]
 *   @0x176884 beq 0x1768d8 <_Z19EmbeddedImages_LoadPhjS_+0xa8>
 *   @0x176888 ldr r1, [pc, #0x5c]
 *   @0x17688c add r2, r5, #16
 *   @0x176890 mov r3, #0
 *   @0x176894 ldr r1, [pc, r1]
 *   @0x176898 ldr r5, [r1]
 *   @0x17689c ldr r1, [r2, #-0x8]
 *   @0x1768a0 add r2, r2, #8
 *   @0x1768a4 cmp r1, #0
 *   @0x1768a8 add r12, r1, r5
 *   @0x1768ac moveq r12, r1
 *   @0x1768b0 ldr r1, [r2, #-0xc]
 *   @0x1768b4 str r12, [r0, r3]
 *   @0x1768b8 cmp r1, #0
 *   @0x1768bc add r12, r5, r1
 *   @0x1768c0 moveq r12, r1
 *   @0x1768c4 add r1, r0, r3
 *   @0x1768c8 add r3, r3, #8
 *   @0x1768cc cmp r6, r3
 *   @0x1768d0 str r12, [r1, #0x4]
 *   @0x1768d4 bne 0x17689c <_Z19EmbeddedImages_LoadPhjS_+0x6c>
 *   @0x1768d8 mov r0, #1
 *   @0x1768dc pop {r5, r6, r7, pc}
 *   @0x1768e0 ldrsbeq r10, [r11], -r4
 *   @0x1768e4 eoreq r9, r7, r4, asr #20
 *   @0x1768e8 eoreq r9, r7, r4, asr #20
 *   @0x1768ec strhteq r7, [r7], -r0
 *
 * ══ §97/156 GamePadRestart()  0x18e58c  size 192  48 条（0x18e58c..0x18e64c）
 * @func 0x18e58c 0x18e64c  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GamePadRestart()+0xa4 / CreateDsMap(int, ...) / CreateAsynEventWithDSMap(int, int)
 * 字段偏移 top8: 0x80×2 / 0x4×2 / 0xa4×1 / 0x8c×1 / 0x88×1 / 0x10×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18e58c ldr r3, [pc, #0xa4]
 *   @0x18e590 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x18e594 ldr r3, [pc, r3]
 *   @0x18e598 sub sp, sp, #24
 *   @0x18e59c ldr r6, [r3]
 *   @0x18e5a0 cmp r6, #0
 *   @0x18e5a4 ble 0x18e630 <_Z14GamePadRestartv+0xa4>
 *   @0x18e5a8 ldr r3, [pc, #0x8c]
 *   @0x18e5ac mov r4, #0
 *   @0x18e5b0 ldr r10, [pc, #0x88]
 *   @0x18e5b4 mov r9, r4
 *   @0x18e5b8 ldr r3, [pc, r3]
 *   @0x18e5bc ldr r8, [pc, #0x80]
 *   @0x18e5c0 ldr r7, [pc, #0x80]
 *   @0x18e5c4 add r10, pc, r10
 *   @0x18e5c8 ldr r5, [r3]
 *   @0x18e5cc add r8, pc, r8
 *   @0x18e5d0 add r7, pc, r7
 *   @0x18e5d4 sub r5, r5, #4
 *   @0x18e5d8 ldr r12, [r5, #0x4]!
 *   @0x18e5dc mov r1, r10
 *   @0x18e5e0 mov r2, #0
 *   @0x18e5e4 mov r3, #0
 *   @0x18e5e8 cmp r12, #0
 *   @0x18e5ec mov r0, #2
 *   @0x18e5f0 beq 0x18e624 <_Z14GamePadRestartv+0x98>
 *   @0x18e5f4 ldrb r12, [r12]
 *   @0x18e5f8 cmp r12, #0
 *   @0x18e5fc beq 0x18e624 <_Z14GamePadRestartv+0x98>
 *   @0x18e600 vmov s13, r4
 *   @0x18e604 str r8, [sp]
 *   @0x18e608 str r7, [sp, #0x4]
 *   @0x18e60c vcvt.f64.s32 d7, s13
 *   @0x18e610 str r9, [sp, #0x10]
 *   @0x18e614 vstr d7, [sp, #8]
 *   @0x18e618 bl 0x20bdc0 <_Z11CreateDsMapiz>
 *   @0x18e61c mov r1, #75
 *   @0x18e620 bl 0x18da04 <_Z24CreateAsynEventWithDSMapii>
 *   @0x18e624 add r4, r4, #1
 *   @0x18e628 cmp r4, r6
 *   @0x18e62c bne 0x18e5d8 <_Z14GamePadRestartv+0x4c>
 *   @0x18e630 add sp, sp, #24
 *   @0x18e634 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x18e638 eoreq r1, r6, r12, asr #9
 *   @0x18e63c eoreq r1, r6, r12, lsr #9
 *   @0x18e640 andseq sp, r11, r0, asr #27
 *   @0x18e644 andseq sp, r11, r4, asr #27
 *   @0x18e648 ldrsbeq sp, [r11], -r4
 *
 * ══ §98/156 ParticleSystem_Depth(int, float)  0x1a47d4  size 192  48 条（0x1a47d4..0x1a4894）
 * @func 0x1a47d4 0x1a4894  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleSystem_Exists(int) / CLayerManager::RemoveElement(CRoom*, int, bool, bool) / CLayerManager::GetNewParticleElement() / CLayerManager::AddNewElementAtDepth(CRoom*, int, CLayerElementBase*, bool, bool)
 * 字段偏移 top8: 0x90×2 / 0x4×2 / 0x2×2 / 0x1c×2 / 0x2c×2 / 0x68×1 / 0x30×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a47d4 push {r4, r5, r6, lr}
 *   @0x1a47d8 sub sp, sp, #8
 *   @0x1a47dc mov r6, r1
 *   @0x1a47e0 mov r5, r0
 *   @0x1a47e4 bl 0x1a3770 <_Z21ParticleSystem_Existsi>
 *   @0x1a47e8 cmp r0, #0
 *   @0x1a47ec beq 0x1a4818 <_Z20ParticleSystem_Depthif+0x44>
 *   @0x1a47f0 ldr r3, [pc, #0x90]
 *   @0x1a47f4 ldr r4, [pc, #0x90]
 *   @0x1a47f8 ldr r3, [pc, r3]
 *   @0x1a47fc ldr r4, [pc, r4]
 *   @0x1a4800 ldrb r2, [r3]
 *   @0x1a4804 ldr r3, [r4, #0x4]
 *   @0x1a4808 cmp r2, #0
 *   @0x1a480c ldr r3, [r3, r5, lsl #2]
 *   @0x1a4810 str r6, [r3, #0x1c]
 *   @0x1a4814 bne 0x1a4820 <_Z20ParticleSystem_Depthif+0x4c>
 *   @0x1a4818 add sp, sp, #8
 *   @0x1a481c pop {r4, r5, r6, pc}
 *   @0x1a4820 ldr r6, [pc, #0x68]
 *   @0x1a4824 mov r2, #1
 *   @0x1a4828 ldr r1, [r3, #0x2c]
 *   @0x1a482c mov r3, #0
 *   @0x1a4830 ldr r6, [pc, r6]
 *   @0x1a4834 ldr r0, [r6]
 *   @0x1a4838 bl 0x1c013c <_ZN13CLayerManager13RemoveElementEP5CRoomibb>
 *   @0x1a483c bl 0x1c115c <_ZN13CLayerManager21GetNewParticleElementEv>
 *   @0x1a4840 ldr r1, [r4, #0x4]
 *   @0x1a4844 mov r12, #1
 *   @0x1a4848 mvn lr, #0
 *   @0x1a484c ldr r4, [r1, r5, lsl #2]
 *   @0x1a4850 vldr s15, [r4, #28]
 *   @0x1a4854 vcvt.s32.f32 s15, s15
 *   @0x1a4858 vmov r1, s15
 *   @0x1a485c mov r3, r0
 *   @0x1a4860 ldr r0, [r6]
 *   @0x1a4864 str r5, [r3, #0x1c]
 *   @0x1a4868 mov r2, r3
 *   @0x1a486c str lr, [r4, #0x30]
 *   @0x1a4870 mov r3, r12
 *   @0x1a4874 str r12, [sp]
 *   @0x1a4878 bl 0x1c6c78 <_ZN13CLayerManager20AddNewElementAtDepthEP5CRoomiP17CLayerElementBasebb>
 *   @0x1a487c str r0, [r4, #0x2c]
 *   @0x1a4880 add sp, sp, #8
 *   @0x1a4884 pop {r4, r5, r6, pc}
 *   @0x1a4888 eoreq r9, r4, r12, lsr #2
 *   @0x1a488c .word 0x0024bfbc
 *   @0x1a4890 .word 0x002490f8
 *
 * ══ §99/156 Path_Quit()  0x1a7be8  size 192  48 条（0x1a7be8..0x1a7ca8）
 * @func 0x1a7be8 0x1a7ca8  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / Path_Quit()+0x68 / CPath::Free()
 * 字段偏移 top8: 0x4×4 / 0x2×2 / 0xa0×1 / 0x90×1 / 0x80×1 / 0x48×1 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a7be8 push {r3, r4, r5, r6, r7, lr}
 *   @0x1a7bec ldr r3, [pc, #0xa0]
 *   @0x1a7bf0 add r3, pc, r3
 *   @0x1a7bf4 ldr r3, [r3, #0x4]
 *   @0x1a7bf8 cmp r3, #0
 *   @0x1a7bfc popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1a7c00 ldr r5, [pc, #0x90]
 *   @0x1a7c04 ldr r5, [pc, r5]
 *   @0x1a7c08 ldr r2, [r5]
 *   @0x1a7c0c cmp r2, #0
 *   @0x1a7c10 ble 0x1a7c50 <_Z9Path_Quitv+0x68>
 *   @0x1a7c14 ldr r6, [pc, #0x80]
 *   @0x1a7c18 mov r4, #0
 *   @0x1a7c1c mov r7, r4
 *   @0x1a7c20 add r6, pc, r6
 *   @0x1a7c24 ldr r0, [r3, r4, lsl #2]
 *   @0x1a7c28 cmp r0, #0
 *   @0x1a7c2c beq 0x1a7c40 <_Z9Path_Quitv+0x58>
 *   @0x1a7c30 bl 0x1a6ffc <_ZN5CPath4FreeEv>
 *   @0x1a7c34 ldr r3, [r6, #0x4]
 *   @0x1a7c38 str r7, [r3, r4, lsl #2]
 *   @0x1a7c3c ldr r3, [r6, #0x4]
 *   @0x1a7c40 ldr r2, [r5]
 *   @0x1a7c44 add r4, r4, #1
 *   @0x1a7c48 cmp r2, r4
 *   @0x1a7c4c bgt 0x1a7c24 <_Z9Path_Quitv+0x3c>
 *   @0x1a7c50 ldr r4, [pc, #0x48]
 *   @0x1a7c54 mov r0, r3
 *   @0x1a7c58 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1a7c5c ldr r3, [pc, #0x40]
 *   @0x1a7c60 ldr r4, [pc, r4]
 *   @0x1a7c64 mov r2, #0
 *   @0x1a7c68 add r3, pc, r3
 *   @0x1a7c6c ldr r0, [r4]
 *   @0x1a7c70 str r2, [r3, #0x4]
 *   @0x1a7c74 cmp r0, r2
 *   @0x1a7c78 str r2, [r3]
 *   @0x1a7c7c beq 0x1a7c84 <_Z9Path_Quitv+0x9c>
 *   @0x1a7c80 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1a7c84 mov r3, #0
 *   @0x1a7c88 str r3, [r4]
 *   @0x1a7c8c str r3, [r5]
 *   @0x1a7c90 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1a7c94 eorseq r10, r9, r8, lsr r9
 *   @0x1a7c98 eoreq r8, r4, r8, asr #23
 *   @0x1a7c9c eorseq r10, r9, r8, lsl #18
 *   @0x1a7ca0 eoreq r8, r4, r0, ror r11
 *   @0x1a7ca4 eorseq r10, r9, r0, asr #17
 *
 * ══ §100/156 CLayerManager::RemoveBackgroundElement(CLayer*, CLayerBackgroundElement*)  0x1b7a04  size 192  48 条（0x1b7a04..0x1b7ac4）
 * @func 0x1b7a04 0x1b7ac4  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x1c×3 / 0x8×3 / 0x18×2 / 0x14×2 / 0x60×2 / 0x54×1 / 0x4×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b7a04 push {r4, r5, r6, lr}
 *   @0x1b7a08 mov r5, r0
 *   @0x1b7a0c ldr r0, [r1, #0x1c]
 *   @0x1b7a10 mov r4, r1
 *   @0x1b7a14 cmp r0, #0
 *   @0x1b7a18 beq 0x1b7a28 <_ZN13CLayerManager23RemoveBackgroundElementEP6CLayerP23CLayerBackgroundElement+0x24>
 *   @0x1b7a1c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b7a20 mov r3, #0
 *   @0x1b7a24 str r3, [r4, #0x1c]
 *   @0x1b7a28 ldr r3, [r4, #0x18]
 *   @0x1b7a2c mvn r6, #0
 *   @0x1b7a30 ldr r2, [r4, #0x14]
 *   @0x1b7a34 mov r12, #1
 *   @0x1b7a38 cmp r3, #0
 *   @0x1b7a3c ldr r1, [r5, #0x60]
 *   @0x1b7a40 strne r2, [r3, #0x14]
 *   @0x1b7a44 add r1, r1, r6
 *   @0x1b7a48 ldrne r2, [r4, #0x14]
 *   @0x1b7a4c ldrne r3, [r4, #0x18]
 *   @0x1b7a50 streq r2, [r5, #0x58]
 *   @0x1b7a54 cmp r2, #0
 *   @0x1b7a58 streq r3, [r5, #0x5c]
 *   @0x1b7a5c strne r3, [r2, #0x18]
 *   @0x1b7a60 mov r3, #0
 *   @0x1b7a64 ldr r2, [pc, #0x54]
 *   @0x1b7a68 str r1, [r5, #0x60]
 *   @0x1b7a6c ldr r2, [pc, r2]
 *   @0x1b7a70 str r3, [r4, #0x14]
 *   @0x1b7a74 str r3, [r4, #0x18]
 *   @0x1b7a78 ldr r1, [r2]
 *   @0x1b7a7c ldr r0, [r2, #0x8]
 *   @0x1b7a80 cmp r1, r3
 *   @0x1b7a84 str r12, [r4]
 *   @0x1b7a88 str r6, [r4, #0x4]
 *   @0x1b7a8c add r0, r0, r12
 *   @0x1b7a90 strb r3, [r4, #0x8]
 *   @0x1b7a94 str r3, [r4, #0xc]
 *   @0x1b7a98 str r3, [r4, #0x10]
 *   @0x1b7a9c str r3, [r4, #0x1c]
 *   @0x1b7aa0 str r0, [r2, #0x8]
 *   @0x1b7aa4 strne r4, [r1, #0x18]
 *   @0x1b7aa8 streq r4, [r2, #0x4]
 *   @0x1b7aac streq r4, [r2]
 *   @0x1b7ab0 strne r4, [r2]
 *   @0x1b7ab4 strne r1, [r4, #0x14]
 *   @0x1b7ab8 strne r3, [r4, #0x18]
 *   @0x1b7abc pop {r4, r5, r6, pc}
 *   @0x1b7ac0 .word 0x00238df4
 *
 * ══ §101/156 F_TilemapGetMask(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bf160  size 192  48 条（0x1bf160..0x1bf220）
 * @func 0x1bf160 0x1bf220  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0x38×3 / 0xc×2 / 0x4×1 / 0x18×1 / 0x80×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bf160 cmp r3, #1
 *   @0x1bf164 push {r3, r4, r5, r6, r7, lr}
 *   @0x1bf168 mov r3, #0
 *   @0x1bf16c mov r4, r3
 *   @0x1bf170 mov r5, r0
 *   @0x1bf174 movt r3, #0xbff0
 *   @0x1bf178 str r4, [r0, #0xc]
 *   @0x1bf17c str r3, [r0, #0x4]
 *   @0x1bf180 str r4, [r0]
 *   @0x1bf184 ldr r6, [sp, #0x18]
 *   @0x1bf188 beq 0x1bf1a0 <_Z16F_TilemapGetMaskR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bf18c ldr r0, [pc, #0x80]
 *   @0x1bf190 mov r1, r4
 *   @0x1bf194 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bf198 add r0, pc, r0
 *   @0x1bf19c b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bf1a0 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bf1a4 mov r1, r4
 *   @0x1bf1a8 mov r7, r0
 *   @0x1bf1ac mov r0, r6
 *   @0x1bf1b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bf1b4 mov r2, r4
 *   @0x1bf1b8 mov r1, r0
 *   @0x1bf1bc mov r0, r7
 *   @0x1bf1c0 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bf1c4 cmp r0, #0
 *   @0x1bf1c8 beq 0x1bf1d8 <_Z16F_TilemapGetMaskR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x1bf1cc ldr r3, [r0]
 *   @0x1bf1d0 cmp r3, #5
 *   @0x1bf1d4 beq 0x1bf1fc <_Z16F_TilemapGetMaskR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x1bf1d8 ldr r3, [pc, #0x38]
 *   @0x1bf1dc ldr r1, [pc, #0x38]
 *   @0x1bf1e0 ldr r3, [pc, r3]
 *   @0x1bf1e4 add r1, pc, r1
 *   @0x1bf1e8 ldr r0, [r3]
 *   @0x1bf1ec ldr r3, [r0]
 *   @0x1bf1f0 ldr r3, [r3, #0xc]
 *   @0x1bf1f4 blx r3
 *   @0x1bf1f8 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bf1fc ldr r2, [r0, #0x38]
 *   @0x1bf200 vmov s15, r2
 *   @0x1bf204 vcvt.f64.u32 d7, s15
 *   @0x1bf208 vmov r2, r3, d7
 *   @0x1bf20c stm r5, {r2, r3}
 *   @0x1bf210 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bf214 andseq pc, r8, r12, ror #29
 *   @0x1bf218 eoreq lr, r2, r4, lsr r5
 *   @0x1bf21c andseq pc, r8, r8, ror #28
 *
 * ══ §102/156 IsTouchDown(int, int)  0x1d749c  size 192  48 条（0x1d749c..0x1d755c）
 * @func 0x1d749c 0x1d755c  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×2 / 0x830×2 / 0xb4×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d749c ldr r3, [pc, #0xb4]
 *   @0x1d74a0 cmn r1, #1
 *   @0x1d74a4 ldr r3, [pc, r3]
 *   @0x1d74a8 ldr r12, [r3]
 *   @0x1d74ac beq 0x1d7504 <_Z11IsTouchDownii+0x68>
 *   @0x1d74b0 cmp r12, #0
 *   @0x1d74b4 beq 0x1d74dc <_Z11IsTouchDownii+0x40>
 *   @0x1d74b8 ldr r2, [r12, #0x8]
 *   @0x1d74bc cmp r2, #0
 *   @0x1d74c0 beq 0x1d7550 <_Z11IsTouchDownii+0xb4>
 *   @0x1d74c4 ldrb r3, [r2, #0x830]
 *   @0x1d74c8 cmp r3, #0
 *   @0x1d74cc beq 0x1d74e4 <_Z11IsTouchDownii+0x48>
 *   @0x1d74d0 ldr r12, [r12]
 *   @0x1d74d4 cmp r12, #0
 *   @0x1d74d8 bne 0x1d74b8 <_Z11IsTouchDownii+0x1c>
 *   @0x1d74dc mov r0, r12
 *   @0x1d74e0 bx lr
 *   @0x1d74e4 ldr r3, [r2]
 *   @0x1d74e8 cmp r3, r0
 *   @0x1d74ec bne 0x1d74d0 <_Z11IsTouchDownii+0x34>
 *   @0x1d74f0 ldr r3, [r2, #0x4]
 *   @0x1d74f4 cmp r3, r1
 *   @0x1d74f8 bne 0x1d74d0 <_Z11IsTouchDownii+0x34>
 *   @0x1d74fc mov r0, #1
 *   @0x1d7500 bx lr
 *   @0x1d7504 cmp r12, #0
 *   @0x1d7508 beq 0x1d74dc <_Z11IsTouchDownii+0x40>
 *   @0x1d750c ldr r3, [r12, #0x8]
 *   @0x1d7510 cmp r3, #0
 *   @0x1d7514 beq 0x1d7548 <_Z11IsTouchDownii+0xac>
 *   @0x1d7518 ldrb r2, [r3, #0x830]
 *   @0x1d751c cmp r2, #0
 *   @0x1d7520 beq 0x1d7534 <_Z11IsTouchDownii+0x98>
 *   @0x1d7524 ldr r12, [r12]
 *   @0x1d7528 cmp r12, #0
 *   @0x1d752c bne 0x1d750c <_Z11IsTouchDownii+0x70>
 *   @0x1d7530 b 0x1d74dc <_Z11IsTouchDownii+0x40>
 *   @0x1d7534 ldr r3, [r3]
 *   @0x1d7538 cmp r3, r0
 *   @0x1d753c bne 0x1d7524 <_Z11IsTouchDownii+0x88>
 *   @0x1d7540 mov r0, #1
 *   @0x1d7544 bx lr
 *   @0x1d7548 mov r0, r3
 *   @0x1d754c bx lr
 *   @0x1d7550 mov r0, r2
 *   @0x1d7554 bx lr
 *   @0x1d7558 eoreq r9, r1, r0, ror #14
 *
 * ══ §103/156 CleanGestures()  0x1dba70  size 192  48 条（0x1dba70..0x1dbb30）
 * @func 0x1dba70 0x1dbb30  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / CGestureEvent::~CGestureEvent() / operator delete(void*)
 * 字段偏移 top8: 0x8×4 / 0x4×3 / 0xac×1 / 0x68×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dba70 push {r3, r4, r5, r6, r7, lr}
 *   @0x1dba74 ldr r6, [pc, #0xac]
 *   @0x1dba78 ldr r6, [pc, r6]
 *   @0x1dba7c ldr r4, [r6]
 *   @0x1dba80 cmp r4, #0
 *   @0x1dba84 beq 0x1dbabc <_Z13CleanGesturesv+0x4c>
 *   @0x1dba88 ldr r3, [r4, #0x8]
 *   @0x1dba8c ldr r5, [r4]
 *   @0x1dba90 cmp r3, #0
 *   @0x1dba94 mov r0, r3
 *   @0x1dba98 beq 0x1dbaa8 <_Z13CleanGesturesv+0x38>
 *   @0x1dba9c ldr r3, [r3]
 *   @0x1dbaa0 ldr r3, [r3, #0x4]
 *   @0x1dbaa4 blx r3
 *   @0x1dbaa8 mov r0, r4
 *   @0x1dbaac mov r4, r5
 *   @0x1dbab0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1dbab4 cmp r5, #0
 *   @0x1dbab8 bne 0x1dba88 <_Z13CleanGesturesv+0x18>
 *   @0x1dbabc ldr r7, [pc, #0x68]
 *   @0x1dbac0 mov r3, #0
 *   @0x1dbac4 str r3, [r6, #0x8]
 *   @0x1dbac8 ldr r7, [pc, r7]
 *   @0x1dbacc str r3, [r6, #0x4]
 *   @0x1dbad0 str r3, [r6]
 *   @0x1dbad4 ldr r4, [r7]
 *   @0x1dbad8 cmp r4, r3
 *   @0x1dbadc beq 0x1dbb14 <_Z13CleanGesturesv+0xa4>
 *   @0x1dbae0 ldr r5, [r4, #0x8]
 *   @0x1dbae4 ldr r6, [r4]
 *   @0x1dbae8 cmp r5, #0
 *   @0x1dbaec mov r0, r5
 *   @0x1dbaf0 beq 0x1dbb00 <_Z13CleanGesturesv+0x90>
 *   @0x1dbaf4 bl 0x1db510 <_ZN13CGestureEventD2Ev>
 *   @0x1dbaf8 mov r0, r5
 *   @0x1dbafc bl 0x27d1d0 <_ZdlPv>
 *   @0x1dbb00 mov r0, r4
 *   @0x1dbb04 mov r4, r6
 *   @0x1dbb08 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1dbb0c cmp r6, #0
 *   @0x1dbb10 bne 0x1dbae0 <_Z13CleanGesturesv+0x70>
 *   @0x1dbb14 mov r3, #0
 *   @0x1dbb18 str r3, [r7, #0x8]
 *   @0x1dbb1c str r3, [r7, #0x4]
 *   @0x1dbb20 str r3, [r7]
 *   @0x1dbb24 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1dbb28 mlaeq r1, r12, r1, r5
 *   @0x1dbb2c eoreq r5, r1, r8, lsr r1
 *
 * ══ §104/156 DeleteVertexFormat(VertexFormat*)  0x1e2e98  size 192  48 条（0x1e2e98..0x1e2f58）
 * @func 0x1e2e98 0x1e2f58  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / operator delete(void*)
 * 字段偏移 top8: 0x8×4 / 0x4×3 / 0xa4×2 / 0x3×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e2e98 push {r3, r4, r5, lr}
 *   @0x1e2e9c subs r4, r0, #0
 *   @0x1e2ea0 popeq {r3, r4, r5, pc}
 *   @0x1e2ea4 ldr r3, [pc, #0xa4]
 *   @0x1e2ea8 ldr r5, [pc, #0xa4]
 *   @0x1e2eac ldr r3, [pc, r3]
 *   @0x1e2eb0 ldr r0, [r4, #0x8]
 *   @0x1e2eb4 ldr r2, [r3]
 *   @0x1e2eb8 cmp r2, r4
 *   @0x1e2ebc moveq r2, #0
 *   @0x1e2ec0 streq r2, [r3]
 *   @0x1e2ec4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e2ec8 ldr r5, [pc, r5]
 *   @0x1e2ecc ldr r2, [r4]
 *   @0x1e2ed0 ldr r0, [r5, #0x4]
 *   @0x1e2ed4 ldr r1, [r5]
 *   @0x1e2ed8 and r0, r2, r0
 *   @0x1e2edc ldr r4, [r1, r0, lsl #3]
 *   @0x1e2ee0 add r12, r1, r0, lsl #3
 *   @0x1e2ee4 cmp r4, #0
 *   @0x1e2ee8 bne 0x1e2efc <_Z18DeleteVertexFormatP12VertexFormat+0x64>
 *   @0x1e2eec pop {r3, r4, r5, pc}
 *   @0x1e2ef0 ldr r4, [r4, #0x4]
 *   @0x1e2ef4 cmp r4, #0
 *   @0x1e2ef8 beq 0x1e2f4c <_Z18DeleteVertexFormatP12VertexFormat+0xb4>
 *   @0x1e2efc ldr r3, [r4, #0x8]
 *   @0x1e2f00 cmp r2, r3
 *   @0x1e2f04 bne 0x1e2ef0 <_Z18DeleteVertexFormatP12VertexFormat+0x58>
 *   @0x1e2f08 ldr r3, [r4]
 *   @0x1e2f0c ldr r2, [r4, #0x4]
 *   @0x1e2f10 cmp r3, #0
 *   @0x1e2f14 strne r2, [r3, #0x4]
 *   @0x1e2f18 ldrne r2, [r4, #0x4]
 *   @0x1e2f1c streq r2, [r1, r0, lsl #3]
 *   @0x1e2f20 cmp r2, #0
 *   @0x1e2f24 ldr r0, [r4, #0xc]
 *   @0x1e2f28 streq r3, [r12, #0x4]
 *   @0x1e2f2c strne r3, [r2]
 *   @0x1e2f30 bl 0x27d1d0 <_ZdlPv>
 *   @0x1e2f34 mov r0, r4
 *   @0x1e2f38 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e2f3c ldr r3, [r5, #0x8]
 *   @0x1e2f40 sub r3, r3, #1
 *   @0x1e2f44 str r3, [r5, #0x8]
 *   @0x1e2f48 pop {r3, r4, r5, pc}
 *   @0x1e2f4c pop {r3, r4, r5, pc}
 *   @0x1e2f50 eoreq sp, r0, r12, ror #29
 *   @0x1e2f54 .word 0x0020ded4
 *
 * ══ §105/156 CDS_Grid::WriteToString(char const*&)  0x204108  size 192  48 条（0x204108..0x2041c8）
 * @func 0x204108 0x2041c8  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::WriteInteger(int)×3 / operator new(unsigned int) / CStream::CStream(int) / CDS_Grid::WriteToString(char const*&)+0x98 / CDS_Grid::WriteToString(char const*&)+0x8c / WriteValue(CStream&, RValue&) / CDS_Grid::WriteToString(char const*&)+0x58 / CStream::ConvertToString(char const*&)
 * 字段偏移 top8: 0x4×3 / 0x8×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x204108 push {r4, r5, r6, r7, r8, lr}
 *   @0x20410c mov r5, r0
 *   @0x204110 mov r0, #32
 *   @0x204114 mov r8, r1
 *   @0x204118 bl 0x27c524 <_Znwj>
 *   @0x20411c mov r1, #0
 *   @0x204120 mov r7, r0
 *   @0x204124 bl 0x2010ec <_ZN7CStreamC2Ei>
 *   @0x204128 mov r0, r7
 *   @0x20412c movw r1, #0x25a
 *   @0x204130 bl 0x201a10 <_ZN7CStream12WriteIntegerEi>
 *   @0x204134 mov r0, r7
 *   @0x204138 ldr r1, [r5, #0x4]
 *   @0x20413c bl 0x201a10 <_ZN7CStream12WriteIntegerEi>
 *   @0x204140 mov r0, r7
 *   @0x204144 ldr r1, [r5, #0x8]
 *   @0x204148 bl 0x201a10 <_ZN7CStream12WriteIntegerEi>
 *   @0x20414c ldr r3, [r5, #0x4]
 *   @0x204150 cmp r3, #0
 *   @0x204154 ble 0x2041a0 <_ZN8CDS_Grid13WriteToStringERPKc+0x98>
 *   @0x204158 ldr r2, [r5, #0x8]
 *   @0x20415c mov r6, #0
 *   @0x204160 cmp r2, #0
 *   @0x204164 ble 0x204194 <_ZN8CDS_Grid13WriteToStringERPKc+0x8c>
 *   @0x204168 mov r4, #0
 *   @0x20416c mla r3, r3, r4, r6
 *   @0x204170 ldr r1, [r5]
 *   @0x204174 mov r0, r7
 *   @0x204178 add r4, r4, #1
 *   @0x20417c add r1, r1, r3, lsl #4
 *   @0x204180 bl 0x202af8 <_Z10WriteValueR7CStreamR6RValue>
 *   @0x204184 ldr r2, [r5, #0x8]
 *   @0x204188 ldr r3, [r5, #0x4]
 *   @0x20418c cmp r2, r4
 *   @0x204190 bgt 0x20416c <_ZN8CDS_Grid13WriteToStringERPKc+0x64>
 *   @0x204194 add r6, r6, #1
 *   @0x204198 cmp r6, r3
 *   @0x20419c blt 0x204160 <_ZN8CDS_Grid13WriteToStringERPKc+0x58>
 *   @0x2041a0 mov r1, r8
 *   @0x2041a4 mov r0, r7
 *   @0x2041a8 bl 0x2024b0 <_ZN7CStream15ConvertToStringERPKc>
 *   @0x2041ac cmp r7, #0
 *   @0x2041b0 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x2041b4 mov r0, r7
 *   @0x2041b8 bl 0x201328 <_ZN7CStreamD2Ev>
 *   @0x2041bc mov r0, r7
 *   @0x2041c0 pop {r4, r5, r6, r7, r8, lr}
 *   @0x2041c4 b 0x27d1d0 <_ZdlPv>
 *
 * ══ §106/156 DayFromYear(double)  0x244aa8  size 192  48 条（0x244aa8..0x244b68）
 * @func 0x244aa8 0x244b68  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6598×3
 * 字段偏移 top8: 无
 * VFP 指令 28 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x244aa8 push {r3, lr}
 *   @0x244aac vpush {d8, d9, d10}
 *   @0x244ab0 vmov d8, r0, r1
 *   @0x244ab4 vldr d6, [pc, #116]
 *   @0x244ab8 vmov.f64 d7, #2.500000e-01
 *   @0x244abc vsub.f64 d6, d8, d6
 *   @0x244ac0 vmul.f64 d5, d6, d7
 *   @0x244ac4 vmov r0, r1, d5
 *   @0x244ac8 bl 0xb6598 <floor@plt>
 *   @0x244acc vldr d6, [pc, #100]
 *   @0x244ad0 vsub.f64 d6, d8, d6
 *   @0x244ad4 vldr d7, [pc, #100]
 *   @0x244ad8 vdiv.f64 d5, d6, d7
 *   @0x244adc vmov d10, r0, r1
 *   @0x244ae0 vmov r0, r1, d5
 *   @0x244ae4 bl 0xb6598 <floor@plt>
 *   @0x244ae8 vldr d6, [pc, #88]
 *   @0x244aec vsub.f64 d6, d8, d6
 *   @0x244af0 vldr d7, [pc, #88]
 *   @0x244af4 vdiv.f64 d5, d6, d7
 *   @0x244af8 vmov d9, r0, r1
 *   @0x244afc vmov r0, r1, d5
 *   @0x244b00 bl 0xb6598 <floor@plt>
 *   @0x244b04 vldr d6, [pc, #76]
 *   @0x244b08 vsub.f64 d8, d8, d6
 *   @0x244b0c vldr d7, [pc, #76]
 *   @0x244b10 vmla.f64 d10, d8, d7
 *   @0x244b14 vmov d7, r0, r1
 *   @0x244b18 vsub.f64 d9, d10, d9
 *   @0x244b1c vadd.f64 d7, d9, d7
 *   @0x244b20 vpop {d8, d9, d10}
 *   @0x244b24 vmov r0, r1, d7
 *   @0x244b28 pop {r3, pc}
 *   @0x244b2c nop
 *   @0x244b30 andeq r0, r0, r0
 *   @0x244b34 addsmi r12, lr, r0, lsl #8
 *   @0x244b38 andeq r0, r0, r0
 *   @0x244b3c addsmi r11, sp, r0, lsl #8
 *   @0x244b40 andeq r0, r0, r0
 *   @0x244b44 subsmi r0, r9, r0
 *   @0x244b48 andeq r0, r0, r0
 *   @0x244b4c addsmi r0, r9, r0, lsl #8
 *   @0x244b50 andeq r0, r0, r0
 *   @0x244b54 rsbsmi r0, r9, r0
 *   @0x244b58 andeq r0, r0, r0
 *   @0x244b5c addsmi r12, lr, r0, lsl #16
 *   @0x244b60 andeq r0, r0, r0
 *   @0x244b64 rsbsmi sp, r6, r0
 *
 * ══ §107/156 JS_String_prototype_localeCompare(RValue&, CInstance*, CInstance*, int, RValue*)  0x255578  size 192  48 条（0x255578..0x255638）
 * @func 0x255578 0x255638  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_JS_ToString(RValue&, RValue*)×2 / JS_CheckObjectCoercible(RValue&) / 0xb6574 / JSThrowTypeError(char const*)
 * 字段偏移 top8: 0xc×3 / 0x-30×1 / 0x18×1 / 0x1c×1 / 0x10×1 / 0x50×1 / 0x28×1 / 0x2c×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x255578 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x25557c sub sp, sp, #52
 *   @0x255580 add r4, sp, #48
 *   @0x255584 mov r6, r0
 *   @0x255588 mov r0, sp
 *   @0x25558c mov r3, #6
 *   @0x255590 str r1, [r4, #-0x30]!
 *   @0x255594 str r3, [sp, #0xc]
 *   @0x255598 bl 0x2423a4 <_Z23JS_CheckObjectCoercibleR6RValue>
 *   @0x25559c cmp r0, #1
 *   @0x2555a0 beq 0x255620 <_Z33JS_String_prototype_localeCompareR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x2555a4 mov r1, sp
 *   @0x2555a8 add r0, sp, #16
 *   @0x2555ac mov r7, #0
 *   @0x2555b0 mov r4, #0
 *   @0x2555b4 mov r5, #0
 *   @0x2555b8 mvn r8, #-16777216
 *   @0x2555bc strd r4, r5, [sp, #16]
 *   @0x2555c0 str r7, [sp, #0x18]
 *   @0x2555c4 str r8, [sp, #0x1c]
 *   @0x2555c8 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x2555cc ldr r3, [sp, #0x10]
 *   @0x2555d0 add r0, sp, #32
 *   @0x2555d4 ldr r1, [sp, #0x50]
 *   @0x2555d8 ldr r9, [r3]
 *   @0x2555dc strd r4, r5, [sp, #32]
 *   @0x2555e0 str r7, [sp, #0x28]
 *   @0x2555e4 str r8, [sp, #0x2c]
 *   @0x2555e8 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x2555ec ldr r3, [sp, #0x20]
 *   @0x2555f0 mov r0, r9
 *   @0x2555f4 ldr r1, [r3]
 *   @0x2555f8 str r7, [r6, #0xc]
 *   @0x2555fc bl 0xb6574 <strcmp@plt>
 *   @0x255600 vmov s15, r0
 *   @0x255604 vcvt.f64.s32 d7, s15
 *   @0x255608 vmov r0, r1, d7
 *   @0x25560c vmov r2, s14
 *   @0x255610 mov r3, r1
 *   @0x255614 stm r6, {r2, r3}
 *   @0x255618 add sp, sp, #52
 *   @0x25561c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x255620 ldr r0, [pc, #0xc]
 *   @0x255624 add r0, pc, r0
 *   @0x255628 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x25562c add sp, sp, #52
 *   @0x255630 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x255634 andseq r0, r0, r4, lsr #18
 *
 * ══ §108/156 F_NETWORK_Send_Packet(RValue&, CInstance*, CInstance*, int, RValue*)  0x297fbc  size 192  48 条（0x297fbc..0x29807c）
 * @func 0x297fbc 0x29807c  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / GetIBuffer(int) / yySocket::SendPacket(unsigned char*, int)
 * 字段偏移 top8: 0xc×2 / 0x18×1 / 0x5c×1 / 0x4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x297fbc push {r4, r5, r6, r7, r8, lr}
 *   @0x297fc0 mov r1, #0
 *   @0x297fc4 ldr r5, [sp, #0x18]
 *   @0x297fc8 mov r3, r1
 *   @0x297fcc str r1, [r0, #0xc]
 *   @0x297fd0 movt r3, #0xbff0
 *   @0x297fd4 mov r4, r0
 *   @0x297fd8 stm r0, {r1, r3}
 *   @0x297fdc mov r0, r5
 *   @0x297fe0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x297fe4 mov r1, #1
 *   @0x297fe8 mov r6, r0
 *   @0x297fec mov r0, r5
 *   @0x297ff0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x297ff4 mov r1, #2
 *   @0x297ff8 mov r7, r0
 *   @0x297ffc mov r0, r5
 *   @0x298000 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x298004 cmp r6, #63
 *   @0x298008 mov r5, r0
 *   @0x29800c pophi {r4, r5, r6, r7, r8, pc}
 *   @0x298010 add r6, r6, r6, lsl #1
 *   @0x298014 ldr r3, [pc, #0x5c]
 *   @0x298018 lsl r6, r6, #2
 *   @0x29801c ldr r3, [pc, r3]
 *   @0x298020 add r8, r3, r6
 *   @0x298024 ldrb r3, [r3, r6]
 *   @0x298028 cmp r3, #0
 *   @0x29802c popeq {r4, r5, r6, r7, r8, pc}
 *   @0x298030 mov r0, r7
 *   @0x298034 bl 0xc6720 <_Z10GetIBufferi>
 *   @0x298038 subs r3, r0, #0
 *   @0x29803c popeq {r4, r5, r6, r7, r8, pc}
 *   @0x298040 ldr r0, [r8, #0x4]
 *   @0x298044 mov r2, r5
 *   @0x298048 ldr r1, [r3, #0xc]
 *   @0x29804c cmp r0, #0
 *   @0x298050 ldreq r3, [r8, #0x8]
 *   @0x298054 ldreq r0, [r3]
 *   @0x298058 bl 0x296944 <_ZN8yySocket10SendPacketEPhi>
 *   @0x29805c vmov s15, r0
 *   @0x298060 vcvt.f64.s32 d7, s15
 *   @0x298064 vmov r0, r1, d7
 *   @0x298068 vmov r2, s14
 *   @0x29806c mov r3, r1
 *   @0x298070 stm r4, {r2, r3}
 *   @0x298074 pop {r4, r5, r6, r7, r8, pc}
 *   @0x298078 andseq r9, r5, r8, lsl #19
 *
 * ══ §109/156 CProfiler::BeginFrame()  0x2a03f8  size 192  48 条（0x2a03f8..0x2a04b8）
 * @func 0x2a03f8 0x2a04b8  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x2a0420→0x757e7c, 0x2a0428→0x5429e8, 0x2a048c→0x757e7c
 * 调用序列: Timing_Time
 * 字段偏移 top8: 0x11×1 / 0xa8×1 / 0x12×1 / 0x88×1 / 0x84×1 / 0x13×1 / 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a03f8 ldrb r3, [r0, #0x11]
 *   @0x2a03fc ldr r12, [pc, #0xa8]
 *   @0x2a0400 cmp r3, #0
 *   @0x2a0404 push {r4, r5, r6, r7, r8, lr}
 *   @0x2a0408 add r12, pc, r12
 *   @0x2a040c mov r8, r0
 *   @0x2a0410 beq 0x2a048c <_ZN9CProfiler10BeginFrameEv+0x94>
 *   @0x2a0414 ldrb r4, [r0, #0x12]
 *   @0x2a0418 cmp r4, #0
 *   @0x2a041c bne 0x2a048c <_ZN9CProfiler10BeginFrameEv+0x94>
 *   @0x2a0420 ldr r5, [pc, #0x88]
 *   @0x2a0424 mov lr, #1
 *   @0x2a0428 ldr r6, [pc, #0x84]
 *   @0x2a042c mov r3, #0
 *   @0x2a0430 ldrd r0, r1, [r0]
 *   @0x2a0434 mov r2, #0
 *   @0x2a0438 ldr r7, [r12, r5]
 *   @0x2a043c strb lr, [r8, #0x13]
 *   @0x2a0440 ldr r5, [r8, #0x8]
 *   @0x2a0444 strb lr, [r7]
 *   @0x2a0448 ldr r12, [r12, r6]
 *   @0x2a044c strd r0, r1, [r12]
 *   @0x2a0450 strd r2, r3, [r8]
 *   @0x2a0454 str r4, [r5, #0x4]
 *   @0x2a0458 str r4, [r8, #0x70]
 *   @0x2a045c bl 0x215148 <Timing_Time>
 *   @0x2a0460 ldrd r6, r7, [r8, #64]
 *   @0x2a0464 orrs r3, r6, r7
 *   @0x2a0468 beq 0x2a0484 <_ZN9CProfiler10BeginFrameEv+0x8c>
 *   @0x2a046c ldrd r4, r5, [r8, #80]
 *   @0x2a0470 subs r4, r4, r6
 *   @0x2a0474 sbc r5, r5, r7
 *   @0x2a0478 adds r4, r4, r0
 *   @0x2a047c adc r5, r5, r1
 *   @0x2a0480 strd r4, r5, [r8, #80]
 *   @0x2a0484 strd r0, r1, [r8, #64]
 *   @0x2a0488 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2a048c ldr r1, [pc, #0x1c]
 *   @0x2a0490 mov r0, #0
 *   @0x2a0494 mov r2, #0
 *   @0x2a0498 mov r3, #0
 *   @0x2a049c ldr r1, [r12, r1]
 *   @0x2a04a0 strd r2, r3, [r8, #64]
 *   @0x2a04a4 strb r0, [r1]
 *   @0x2a04a8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2a04ac andseq r1, r5, r8, asr #16
 *   @0x2a04b0 .word 0xffffbf18
 *   @0x2a04b4 .word 0xffffef4c
 *
 * ══ §110/156 _zip_filerange_crc(__sFILE*, long, long, unsigned long*, zip_error*)  0x2a43f8  size 192  48 条（0x2a43f8..0x2a44b8）
 * @func 0x2a43f8 0x2a44b8  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6ea4 / 0xb6ed4 / 0xb6bf8 / 0xb65d4
 * 字段偏移 top8: 0x128×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a43f8 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2a43fc sub.w sp, sp, #0x2000
 *   @0x2a4400 sub sp, #0xc
 *   @0x2a4404 mov r4, r2
 *   @0x2a4408 ldrbtmi r5, [lr], #-512
 *   @0x2a440c ldr r6, [r6]
 *   @0x2a4410 mov r7, r3
 *   @0x2a4414 ldmdavs r3!, {r12, pc}
 *   @0x2a4418 add.w r2, sp, #0x2000
 *   @0x2a441c adds r2, #0x4
 *   @0x2a4420 movs r0, #0x0
 *   @0x2a4424 str r3, [r2]
 *   @0x2a4428 mov r2, r0
 *   @0x2a442c blx 0xb6ea4 <crc32@plt>
 *   @0x2a4430 mov r1, r5
 *   @0x2a4434 str r0, [r7]
 *   @0x2a4438 blx 0xb6ed4 <fseeko@plt>
 *   @0x2a443c mov r5, r0
 *   @0x2a4440 add.w r10, sp, #0x4
 *   @0x2a4444 b 0x2a4460 <_Z18_zip_filerange_crcP7__sFILEllPmP9zip_error+0x68>
 *   @0x2a4448 ldrdhs lr, pc, [r4, -r8]
 *   @0x2a444c ldr r2, [r0]
 *   @0x2a4450 b 0x2a448a <_Z18_zip_filerange_crcP7__sFILEllPmP9zip_error+0x92>
 *   @0x2a4454 mov r1, r10
 *   @0x2a4458 subs r4, r4, r6
 *   @0x2a445c eorsvs lr, r8, r4, lsr #26
 *   @0x2a4460 cmp r4, #0x0
 *   @0x2a4464 mov r0, r10
 *   @0x2a4468 cmp.w r4, #0x2000
 *   @0x2a446c ite lt
 *   @0x2a4470 movge.w r2, #0x2000
 *   @0x2a4474 mov r3, r8
 *   @0x2a4478 strmi lr, [r6], -r8, lsr #20
 *   @0x2a447c cmp r0, #0x0
 *   @0x2a4480 blx 0xb6bf8 <__errno@plt>
 *   @0x2a4484 movs r1, #0x5
 *   @0x2a4488 mov r0, r9
 *   @0x2a448c .word 0xf04fff65
 *   @0x2a4490 .word 0xf50d35ff
 *   @0x2a4494 strtmi r5, [r8], -r0, lsl #6
 *   @0x2a4498 adds r3, #0x4
 *   @0x2a449c ldr.w r3, [r11]
 *   @0x2a44a0 cmp r2, r3
 *   @0x2a44a4 blx 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2a44a8 add.w sp, sp, #0x2000
 *   @0x2a44ac add sp, #0xc
 *   @0x2a44b0 svclt #0x8ff0
 *   @0x2a44b4 str r5, [sp, #0x128]
 *
 * ══ §111/156 png_handle_hIST  0x2ace98  size 192  48 条（0x2ace98..0x2acf58）
 * @func 0x2ace98 0x2acf58  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_crc_read
 * 字段偏移 top8: 0x88×1 / 0x6c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ace98 push.w {r4, r5, r6, r7, r8, r9, lr}
 *   @0x2ace9c mov r4, r0
 *   @0x2acea0 .word 0xf5ad312c
 *   @0x2acea4 strmi r7, [pc], -r3, lsl #26
 *   @0x2acea8 mov r5, r2
 *   @0x2aceac bmi 0x2aceb8 <png_handle_hIST+0x20>
 *   @0x2aceb0 add r1, pc
 *   @0x2aceb4 ldrh pc, [r6], -r11
 *   @0x2aceb8 lsls r1, r3, #0x1d
 *   @0x2acebc ldr r1, [pc, #0x88]
 *   @0x2acec0 b 0x2aceca <png_handle_hIST+0x32>
 *   @0x2acec4 bmi 0x2aced8 <png_handle_hIST+0x40>
 *   @0x2acec8 add r1, pc
 *   @0x2acecc .word 0x4620fad3
 *   @0x2aced0 mov r1, r5
 *   @0x2aced4 ldrsbt pc, [r0], -pc
 *   @0x2aced8 cbz r7, 0x2acee6 <png_handle_hIST+0x4e>
 *   @0x2acedc lsls r3, r3, #0x19
 *   @0x2acee0 ldr r1, [pc, #0x6c]
 *   @0x2acee4 b 0x2aceca <png_handle_hIST+0x32>
 *   @0x2acee8 stmdale r4, {r8, r9, r10, r11, r12, sp, lr}
 *   @0x2aceec ldrh.w r3, [r4, #0x1dc]
 *   @0x2acef0 cmp.w r5, r3, lsl #1
 *   @0x2acef4 beq 0x2acefe <png_handle_hIST+0x66>
 *   @0x2acef8 mov r0, r4
 *   @0x2acefc b 0x2aceca <png_handle_hIST+0x32>
 *   @0x2acf00 .word 0xf10d0955
 *   @0x2acf04 stcge p8, c0, [r1, #-32]
 *   @0x2acf08 movs r6, #0x0
 *   @0x2acf0c mov r0, r4
 *   @0x2acf10 movs r2, #0x2
 *   @0x2acf14 bl 0x2abc0c <png_crc_read>
 *   @0x2acf18 ldrb r2, [r5]
 *   @0x2acf1c add.w r3, r3, r2, lsl #8
 *   @0x2acf20 strh.w r3, [r8, r6, lsl #1]
 *   @0x2acf24 adds r6, #0x1
 *   @0x2acf28 movs r1, #0x0
 *   @0x2acf2c stmdblt r0!, {r0, r1, r4, r5, r7, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2acf30 mov r0, r4
 *   @0x2acf34 add r2, sp, #0x8
 *   @0x2acf38 .word 0xf50dfd67
 *   @0x2acf3c pop {r0, r1, r8, r10, r11, r12, sp, lr}
 *   @0x2acf40 svclt #0x83f0
 *   @0x2acf44 lsls r2, r3, #0x14
 *   @0x2acf48 lsls r5, r4, #0x14
 *   @0x2acf4c lsls r3, r6, #0x14
 *   @0x2acf50 lsls r2, r6, #0x14
 *   @0x2acf54 lsls r7, r5, #0x14
 *
 * ══ §112/156 png_set_tRNS  0x2af14c  size 192  48 条（0x2af14c..0x2af20c）
 * @func 0x2af14c 0x2af20c  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_free_data / 0xb65bc
 * 字段偏移 top8: 0x4×2 / 0x8×2 / 0x98×1 / 0x3c×1
 * VFP 指令 1 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2af14c push.w {r4, r5, r6, r7, r8, lr}
 *   @0x2af150 mov r4, r1
 *   @0x2af154 mov r5, r3
 *   @0x2af158 mov r7, r0
 *   @0x2af15c beq 0x2af1fe <png_set_tRNS+0xb2>
 *   @0x2af160 beq 0x2af1fe <png_set_tRNS+0xb2>
 *   @0x2af164 stmdble r5, {r7, r8, r9, r10, r11, r12, sp, lr}
 *   @0x2af168 ldr r1, [pc, #0x98]
 *   @0x2af16c ldrbtmi r4, [r9], #-496
 *   @0x2af170 b.w 0x2a6474 <png_warning>
 *   @0x2af174 cbz r2, 0x2af1a0 <png_set_tRNS+0x54>
 *   @0x2af178 mov.w r2, #0x2000
 *   @0x2af17c bl 0x2a5bc0 <png_free_data>
 *   @0x2af180 mov r0, r7
 *   @0x2af184 .word 0xf7f77180
 *   @0x2af188 cdpne p13, #0x6, c15, c11, c11, #0x4
 *   @0x2af18c cmp r3, #0xff
 *   @0x2af190 str.w r0, [r7, #0x24c]
 *   @0x2af194 bhi 0x2af1a0 <png_set_tRNS+0x54>
 *   @0x2af198 mov r1, r8
 *   @0x2af19c blx 0xb65bc <memcpy@plt>
 *   @0x2af1a0 cbz r6, 0x2af1e6 <png_set_tRNS+0x9a>
 *   @0x2af1a4 movs r2, #0x1
 *   @0x2af1a8 cdpvc p3, #0x6, c15, c2, c3, #0x0
 *   @0x2af1ac cbnz r2, 0x2af1b2 <png_set_tRNS+0x66>
 *   @0x2af1b0 b 0x2af1c4 <png_set_tRNS+0x78>
 *   @0x2af1b4 bne 0x2af1d2 <png_set_tRNS+0x86>
 *   @0x2af1b8 cmp r2, r3
 *   @0x2af1bc ldrh r2, [r6, #0x4]
 *   @0x2af1c0 bgt 0x2af1c8 <png_set_tRNS+0x7c>
 *   @0x2af1c4 cmp r2, r3
 *   @0x2af1c8 ldr r1, [pc, #0x3c]
 *   @0x2af1cc add r1, pc
 *   @0x2af1d0 ldmdavs r3!, {r0, r4, r6, r8, r11, r12, sp, lr, pc}
 *   @0x2af1d4 cmp r5, #0x0
 *   @0x2af1d8 moveq r5, #0x1
 *   @0x2af1dc ldr r3, [r6, #0x4]
 *   @0x2af1e0 ldrh r3, [r6, #0x8]
 *   @0x2af1e4 rschi r3, r5, #88
 *   @0x2af1e8 cbz r5, 0x2af1fe <png_set_tRNS+0xb2>
 *   @0x2af1ec orr r3, r3, #0x10
 *   @0x2af1f0 str r3, [r4, #0x8]
 *   @0x2af1f4 vst4.32 {d19, d20, d21, d22}, [r3:256], r8
 *   @0x2af1f8 .word 0xf8c45300
 *   @0x2af1fc pop {r3, r4, r5, r7, r12, sp}
 *   @0x2af200 svclt #0x81f0
 *   @0x2af204 add.w r0, r12, sp
 *   @0x2af208 pkhbt r0, pc, sp
 *
 * ══ §113/156 png_set_keep_unknown_chunks  0x2af460  size 192  48 条（0x2af460..0x2af520）
 * @func 0x2af460 0x2af520  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x3718c8 / 0x4f1cda / png_free
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2af460 push.w {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2af464 mov r6, r1
 *   @0x2af468 mov r5, r3
 *   @0x2af46c cmp r0, #0x0
 *   @0x2af470 cbnz r3, 0x2af4a4 <png_set_keep_unknown_chunks+0x44>
 *   @0x2af474 cmp r3, #0x1
 *   @0x2af478 stmdale r7, {r4, r5, r8, r12, sp}
 *   @0x2af47c cmp r1, #0x3
 *   @0x2af480 orreq r3, r3, #0x18000
 *   @0x2af484 beq 0x2af49c <png_set_keep_unknown_chunks+0x3c>
 *   @0x2af488 and r4, r1, r0, lsl #6
 *   @0x2af48c bic r3, r3, #0x8000
 *   @0x2af490 str.w r3, [r4, #0x130]
 *   @0x2af494 ldr.w r3, [r4, #0x130]
 *   @0x2af498 bic r3, r3, #0x10000
 *   @0x2af49c str.w r3, [r4, #0x130]
 *   @0x2af4a0 pop.w {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2af4a4 cbz r2, 0x2af51c <png_set_keep_unknown_chunks+0xbc>
 *   @0x2af4a8 .word 0xf04f82cc
 *   @0x2af4ac bl 0x3718c8 <_ZTS13C_UTF16String+0x8974>
 *   @0x2af4b0 blx 0x4f1cda <SrcVerts+0x4ed1e>
 *   @0x2af4b4 .word 0xf7f7f10a
 *   @0x2af4b8 .word 0xf8d4fbf3
 *   @0x2af4bc .word 0x460712d0
 *   @0x2af4c0 cbz r1, 0x2af4da <png_set_keep_unknown_chunks+0x7a>
 *   @0x2af4c4 .word 0xf607f208
 *   @0x2af4c8 qsub16mi lr, r0, r10
 *   @0x2af4cc ldr.w r1, [r4, #0x2d0]
 *   @0x2af4d0 bl 0x2a6cfc <png_free>
 *   @0x2af4d4 movs r3, #0x0
 *   @0x2af4d8 .word 0xf04f32d0
 *   @0x2af4dc ldrbmi r0, [r9], -r5, lsl #18
 *   @0x2af4e0 mul r8, r9, r8
 *   @0x2af4e4 mul r2, r9, r5
 *   @0x2af4e8 add.w r0, r7, r8
 *   @0x2af4ec add.w r8, r8, #0x4
 *   @0x2af4f0 add r8, r7
 *   @0x2af4f4 movwhs lr, #0x864
 *   @0x2af4f8 cmp r3, r5
 *   @0x2af4fc mul r2, r9, r3
 *   @0x2af500 adds r3, #0x1
 *   @0x2af504 ldrb r6, [r7, r2]!
 *   @0x2af508 ldr.w r3, [r4, #0x2c0]
 *   @0x2af50c str.w r10, [r4, #0x2cc]
 *   @0x2af510 orr r3, r3, #0x400
 *   @0x2af514 str.w r7, [r4, #0x2d0]
 *   @0x2af518 str.w r3, [r4, #0x2c0]
 *   @0x2af51c pop.w {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §114/156 png_write_cHRM_fixed  0x2b1cc0  size 192  48 条（0x2b1cc0..0x2b1d80）
 * @func 0x2b1cc0 0x2b1d80  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_save_uint_32×5 / png_check_cHRM_fixed / png_write_chunk
 * 字段偏移 top8: 0x44×2 / 0x74×1 / 0x78×1 / 0x70×1 / 0xc×1 / 0x10×1 / 0x7c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b1cc0 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2b1cc4 mov r5, r0
 *   @0x2b1cc8 sub sp, #0x4c
 *   @0x2b1ccc selmi lr, r8, r0
 *   @0x2b1cd0 add r4, pc
 *   @0x2b1cd4 ldr r7, [sp, #0x74]
 *   @0x2b1cd8 ldr r6, [sp, #0x78]
 *   @0x2b1cdc mov r11, r2
 *   @0x2b1ce0 mov r9, r4
 *   @0x2b1ce4 str r0, [sp, #0x44]
 *   @0x2b1ce8 andls r0, r7, r5, lsr pc
 *   @0x2b1cec ldrb.w r0, [lr, #0x4]
 *   @0x2b1cf0 strb.w r0, [sp, #0x20]
 *   @0x2b1cf4 ldr r0, [sp, #0x70]
 *   @0x2b1cf8 ldmdals pc, {r0, r7}
 *   @0x2b1cfc str r0, [sp, #0xc]
 *   @0x2b1d00 str r0, [sp, #0x10]
 *   @0x2b1d04 bl 0x2a6068 <png_check_cHRM_fixed>
 *   @0x2b1d08 cbz r0, 0x2b1d64 <png_write_cHRM_fixed+0xa4>
 *   @0x2b1d0c mov r1, r8
 *   @0x2b1d10 bl 0x2b1124 <png_save_uint_32>
 *   @0x2b1d14 adds r0, r4, #0x4
 *   @0x2b1d18 bl 0x2b1124 <png_save_uint_32>
 *   @0x2b1d1c add.w r0, r4, #0x8
 *   @0x2b1d20 mov r1, r10
 *   @0x2b1d24 .word 0xf104f9ff
 *   @0x2b1d28 ldmdbls r12, {r2, r3}
 *   @0x2b1d2c bl 0x2b1124 <png_save_uint_32>
 *   @0x2b1d30 add.w r0, r4, #0x10
 *   @0x2b1d34 mov r1, r7
 *   @0x2b1d38 .word 0xf104f9f5
 *   @0x2b1d3c shadd16mi r0, r1, r4
 *   @0x2b1d40 bl 0x2b1124 <png_save_uint_32>
 *   @0x2b1d44 add.w r0, r4, #0x18
 *   @0x2b1d48 ldr r1, [sp, #0x7c]
 *   @0x2b1d4c .word 0xf104f9eb
 *   @0x2b1d50 stmdbls r0!, {r2, r3, r4}
 *   @0x2b1d54 bl 0x2b1124 <png_save_uint_32>
 *   @0x2b1d58 mov r0, r5
 *   @0x2b1d5c mov r2, r4
 *   @0x2b1d60 bl 0x2b12bc <png_write_chunk>
 *   @0x2b1d64 ldr r2, [sp, #0x44]
 *   @0x2b1d68 addsmi r3, r10, #0
 *   @0x2b1d6c beq 0x2b1d72 <png_write_cHRM_fixed+0xb2>
 *   @0x2b1d70 andslt lr, r3, r2, lsr r12
 *   @0x2b1d74 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2b1d78 pop {r2, r7}
 *   @0x2b1d7c b 0x2b1e94 <png_write_bKGD+0x40>
 *
 * ══ §115/156 jinit_marker_reader  0x2b5efc  size 192  48 条（0x2b5efc..0x2b5fbc）
 * @func 0x2b5efc 0x2b5fbc  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x80×2 / 0x1c×2 / 0x90×1 / 0x8c×1 / 0x194×1 / 0x8×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b5efc push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2b5f00 mov r1, #0
 *   @0x2b5f04 ldr r3, [r0, #0x4]
 *   @0x2b5f08 mov r2, #168
 *   @0x2b5f0c mov r4, r0
 *   @0x2b5f10 ldr r6, [pc, #0x90]
 *   @0x2b5f14 mov r5, #0
 *   @0x2b5f18 ldr r9, [pc, #0x8c]
 *   @0x2b5f1c ldr r3, [r3]
 *   @0x2b5f20 add r6, pc, r6
 *   @0x2b5f24 blx r3
 *   @0x2b5f28 ldr r8, [pc, #0x80]
 *   @0x2b5f2c ldr r7, [pc, #0x80]
 *   @0x2b5f30 mov r12, r5
 *   @0x2b5f34 mov r1, r6
 *   @0x2b5f38 mov r2, #16
 *   @0x2b5f3c add r9, pc, r9
 *   @0x2b5f40 add r8, pc, r8
 *   @0x2b5f44 add r7, pc, r7
 *   @0x2b5f48 mov r3, r0
 *   @0x2b5f4c str r0, [r4, #0x194]
 *   @0x2b5f50 str r9, [r0]
 *   @0x2b5f54 str r8, [r0, #0x4]
 *   @0x2b5f58 str r7, [r0, #0x8]
 *   @0x2b5f5c str r6, [r0, #0x18]
 *   @0x2b5f60 str r5, [r0, #0x5c]
 *   @0x2b5f64 subs r2, r2, #1
 *   @0x2b5f68 str r1, [r3, #0x1c]
 *   @0x2b5f6c str r12, [r3, #0x60]
 *   @0x2b5f70 add r3, r3, #4
 *   @0x2b5f74 bne 0x2b5f64 <jinit_marker_reader+0x68>
 *   @0x2b5f78 ldr r3, [pc, #0x38]
 *   @0x2b5f7c add r3, pc, r3
 *   @0x2b5f80 str r3, [r0, #0x1c]
 *   @0x2b5f84 str r3, [r0, #0x54]
 *   @0x2b5f88 str r2, [r4, #0xc4]
 *   @0x2b5f8c str r2, [r4, #0x7c]
 *   @0x2b5f90 str r2, [r4, #0x17c]
 *   @0x2b5f94 strb r2, [r0, #0xc]
 *   @0x2b5f98 strb r2, [r0, #0xd]
 *   @0x2b5f9c str r2, [r0, #0x14]
 *   @0x2b5fa0 str r2, [r0, #0xa0]
 *   @0x2b5fa4 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2b5fa8 .word 0xffffe6dc
 *   @0x2b5fac .word 0xffffe90c
 *   @0x2b5fb0 .word 0xffffed04
 *   @0x2b5fb4 .word 0xfffffda8
 *   @0x2b5fb8 .word 0xfffff908
 *
 * ══ §116/156 b2Mat33::GetSymInverse33(b2Mat33*) const  0x2c69a8  size 192  48 条（0x2c69a8..0x2c6a68）
 * @func 0x2c69a8 0x2c6a68  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 47 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c69a8 vldr s12, [r0, #12]
 *   @0x2c69ac vldr s5, [r0, #32]
 *   @0x2c69b0 vmul.f32 s4, s5, s12
 *   @0x2c69b4 vldr s6, [r0, #16]
 *   @0x2c69b8 vldr s14, [r0, #24]
 *   @0x2c69bc vldr s11, [r0, #20]
 *   @0x2c69c0 vldr s13, [r0, #28]
 *   @0x2c69c4 vldr s15, [r0, #4]
 *   @0x2c69c8 vldr s10, [r0]
 *   @0x2c69cc vldr s9, [r0, #8]
 *   @0x2c69d0 vmov.f32 s7, s4
 *   @0x2c69d4 vmul.f32 s3, s6, s5
 *   @0x2c69d8 vnmls.f32 s7, s11, s14
 *   @0x2c69dc vmov.f32 s8, s3
 *   @0x2c69e0 vmls.f32 s8, s11, s13
 *   @0x2c69e4 vmul.f32 s15, s7, s15
 *   @0x2c69e8 vmul.f32 s11, s6, s14
 *   @0x2c69ec vmla.f32 s15, s8, s10
 *   @0x2c69f0 vnmls.f32 s11, s13, s12
 *   @0x2c69f4 vmla.f32 s15, s11, s9
 *   @0x2c69f8 vcmp.f32 s15, #0
 *   @0x2c69fc vmrs APSR_nzcv, fpscr
 *   @0x2c6a00 vmovne.f32 s9, #1.000000e+00
 *   @0x2c6a04 vdivne.f32 s15, s9, s15
 *   @0x2c6a08 vmul.f32 s8, s14, s14
 *   @0x2c6a0c vmul.f32 s7, s13, s10
 *   @0x2c6a10 vmul.f32 s9, s12, s12
 *   @0x2c6a14 vnmls.f32 s7, s14, s12
 *   @0x2c6a18 vmls.f32 s3, s13, s13
 *   @0x2c6a1c vnmls.f32 s4, s13, s14
 *   @0x2c6a20 vnmls.f32 s8, s5, s10
 *   @0x2c6a24 vnmls.f32 s9, s6, s10
 *   @0x2c6a28 vmul.f32 s7, s7, s15
 *   @0x2c6a2c vmul.f32 s14, s4, s15
 *   @0x2c6a30 vstr s7, [r1, #20]
 *   @0x2c6a34 vstr s7, [r1, #28]
 *   @0x2c6a38 vmul.f32 s3, s3, s15
 *   @0x2c6a3c vstr s14, [r1, #4]
 *   @0x2c6a40 vstr s14, [r1, #12]
 *   @0x2c6a44 vmul.f32 s8, s8, s15
 *   @0x2c6a48 vstr s3, [r1]
 *   @0x2c6a4c vmul.f32 s9, s9, s15
 *   @0x2c6a50 vstr s8, [r1, #16]
 *   @0x2c6a54 vmul.f32 s15, s15, s11
 *   @0x2c6a58 vstr s9, [r1, #32]
 *   @0x2c6a5c vstr s15, [r1, #8]
 *   @0x2c6a60 vstr s15, [r1, #24]
 *   @0x2c6a64 bx lr
 *
 * ══ §117/156 b2Contact::Create(b2Fixture*, int, b2Fixture*, int, b2BlockAllocator*)  0x2cbfbc  size 192  48 条（0x2cbfbc..0x2cc07c）
 * @func 0x2cbfbc 0x2cc07c  size 192  48 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Contact::InitializeRegisters()
 * 字段偏移 top8: 0xc×2 / 0x4×2 / 0xa8×1 / 0x80×1 / 0x8×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cbfbc push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2cbfc0 mov r10, r3
 *   @0x2cbfc4 ldr r4, [pc, #0xa8]
 *   @0x2cbfc8 sub sp, sp, #8
 *   @0x2cbfcc mov r7, r0
 *   @0x2cbfd0 mov r9, r1
 *   @0x2cbfd4 ldr r4, [pc, r4]
 *   @0x2cbfd8 mov r8, r2
 *   @0x2cbfdc ldrb r3, [r4]
 *   @0x2cbfe0 cmp r3, #0
 *   @0x2cbfe4 beq 0x2cc05c <_ZN9b2Contact6CreateEP9b2FixtureiS1_iP16b2BlockAllocator+0xa0>
 *   @0x2cbfe8 ldr r2, [r7, #0xc]
 *   @0x2cbfec ldr r3, [r8, #0xc]
 *   @0x2cbff0 ldr r12, [pc, #0x80]
 *   @0x2cbff4 ldr r5, [r2, #0x4]
 *   @0x2cbff8 ldr r4, [r3, #0x4]
 *   @0x2cbffc ldr r12, [pc, r12]
 *   @0x2cc000 add r5, r5, r5, lsl #1
 *   @0x2cc004 add r4, r4, r4, lsl #1
 *   @0x2cc008 lsl r5, r5, #4
 *   @0x2cc00c add r4, r5, r4, lsl #2
 *   @0x2cc010 ldr r6, [r12, r4]
 *   @0x2cc014 cmp r6, #0
 *   @0x2cc018 beq 0x2cc06c <_ZN9b2Contact6CreateEP9b2FixtureiS1_iP16b2BlockAllocator+0xb0>
 *   @0x2cc01c add r12, r12, r4
 *   @0x2cc020 ldrb r3, [r12, #0x8]
 *   @0x2cc024 cmp r3, #0
 *   @0x2cc028 ldr r3, [sp, #0x28]
 *   @0x2cc02c movne r0, r7
 *   @0x2cc030 movne r1, r9
 *   @0x2cc034 str r3, [sp]
 *   @0x2cc038 movne r2, r8
 *   @0x2cc03c movne r3, r10
 *   @0x2cc040 moveq r0, r8
 *   @0x2cc044 moveq r1, r10
 *   @0x2cc048 moveq r2, r7
 *   @0x2cc04c moveq r3, r9
 *   @0x2cc050 blx r6
 *   @0x2cc054 add sp, sp, #8
 *   @0x2cc058 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2cc05c bl 0x2cbeac <_ZN9b2Contact19InitializeRegistersEv>
 *   @0x2cc060 mov r3, #1
 *   @0x2cc064 strb r3, [r4]
 *   @0x2cc068 b 0x2cbfe8 <_ZN9b2Contact6CreateEP9b2FixtureiS1_iP16b2BlockAllocator+0x2c>
 *   @0x2cc06c mov r0, r6
 *   @0x2cc070 b 0x2cc054 <_ZN9b2Contact6CreateEP9b2FixtureiS1_iP16b2BlockAllocator+0x98>
 *   @0x2cc074 andseq r5, r2, r12, ror #22
 *   @0x2cc078 andseq r5, r2, r8, lsl #22
 *
 * ══ §118/156 CBackground::LoadFromFile(char const*, bool, bool, bool, bool)  0xc2984  size 188  47 条（0xc2984..0xc2a40）
 * @func 0xc2984 0xc2a40  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBackground::FreeTexture()×2 / LoadSave::SaveFileExists(char const*) / LoadSave::ReadSaveFile(char const*, int*) / CBackground::LoadFromFileData(char const*, void*, int, bool, bool, bool, bool) / MemoryManager::Free(void const*) / LoadSave::BundleFileExists(char const*) / LoadSave::ReadBundleFile(char const*, int*)
 * 字段偏移 top8: 0x14×2 / 0x38×1 / 0x3c×1 / 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc2984 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xc2988 sub sp, sp, #24
 *   @0xc298c mov r6, r0
 *   @0xc2990 mov r0, r1
 *   @0xc2994 mov r4, r1
 *   @0xc2998 mov r10, r2
 *   @0xc299c mov r1, #0
 *   @0xc29a0 mov r9, r3
 *   @0xc29a4 ldrb r8, [sp, #0x38]
 *   @0xc29a8 str r1, [sp, #0x14]
 *   @0xc29ac ldrb r7, [sp, #0x3c]
 *   @0xc29b0 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0xc29b4 cmp r0, #0
 *   @0xc29b8 mov r0, r4
 *   @0xc29bc beq 0xc2a14 <_ZN11CBackground12LoadFromFileEPKcbbbb+0x90>
 *   @0xc29c0 add r1, sp, #20
 *   @0xc29c4 bl 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi>
 *   @0xc29c8 mov r5, r0
 *   @0xc29cc mov r0, r6
 *   @0xc29d0 bl 0xc1e3c <_ZN11CBackground11FreeTextureEv>
 *   @0xc29d4 cmp r5, #0
 *   @0xc29d8 beq 0xc2a00 <_ZN11CBackground12LoadFromFileEPKcbbbb+0x7c>
 *   @0xc29dc ldr r3, [sp, #0x14]
 *   @0xc29e0 mov r0, r6
 *   @0xc29e4 str r10, [sp]
 *   @0xc29e8 mov r1, r4
 *   @0xc29ec str r9, [sp, #0x4]
 *   @0xc29f0 mov r2, r5
 *   @0xc29f4 str r8, [sp, #0x8]
 *   @0xc29f8 str r7, [sp, #0xc]
 *   @0xc29fc bl 0xc281c <_ZN11CBackground16LoadFromFileDataEPKcPvibbbb>
 *   @0xc2a00 mov r0, r5
 *   @0xc2a04 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xc2a08 mov r0, #1
 *   @0xc2a0c add sp, sp, #24
 *   @0xc2a10 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xc2a14 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0xc2a18 subs r5, r0, #0
 *   @0xc2a1c bne 0xc2a2c <_ZN11CBackground12LoadFromFileEPKcbbbb+0xa8>
 *   @0xc2a20 mov r0, r6
 *   @0xc2a24 bl 0xc1e3c <_ZN11CBackground11FreeTextureEv>
 *   @0xc2a28 b 0xc2a00 <_ZN11CBackground12LoadFromFileEPKcbbbb+0x7c>
 *   @0xc2a2c mov r0, r4
 *   @0xc2a30 add r1, sp, #20
 *   @0xc2a34 bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi>
 *   @0xc2a38 mov r5, r0
 *   @0xc2a3c b 0xc29cc <_ZN11CBackground12LoadFromFileEPKcbbbb+0x48>
 *
 * ══ §119/156 IBuffer::Write(char const*)  0xcddb8  size 188  47 条（0xcddb8..0xcde74）
 * @func 0xcddb8 0xcde74  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYCreateString(RValue*, char const*) / FREE_RValue__Pre(RValue*) / 0xb65d4
 * 字段偏移 top8: 0x-18×2 / 0x38×2 / 0xa8×1 / 0x8×1 / 0x34×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcddb8 push {r4, r5, r6, r7, r11, lr}
 *   @0xcddbc add r11, sp, #20
 *   @0xcddc0 ldr r5, [pc, #0xa8]
 *   @0xcddc4 sub sp, sp, #8
 *   @0xcddc8 subs r3, r1, #0
 *   @0xcddcc ldr r5, [pc, r5]
 *   @0xcddd0 subeq sp, sp, #16
 *   @0xcddd4 add r6, r0, #44
 *   @0xcddd8 mov r4, r0
 *   @0xcdddc ldr r2, [r5]
 *   @0xcdde0 moveq r3, sp
 *   @0xcdde4 strbeq r1, [r3, #0x1]
 *   @0xcdde8 mov r0, r6
 *   @0xcddec mov r1, r3
 *   @0xcddf0 str r2, [r11, #-0x18]
 *   @0xcddf4 moveq r2, #4
 *   @0xcddf8 strbeq r2, [r3]
 *   @0xcddfc bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0xcde00 ldr r3, [r4]
 *   @0xcde04 mov r2, r6
 *   @0xcde08 mov r0, r4
 *   @0xcde0c mov r1, #11
 *   @0xcde10 ldr r3, [r3, #0x8]
 *   @0xcde14 blx r3
 *   @0xcde18 ldr r3, [r4, #0x38]
 *   @0xcde1c sub r3, r3, #1
 *   @0xcde20 bic r3, r3, #-16777216
 *   @0xcde24 bic r3, r3, #3
 *   @0xcde28 cmp r3, #0
 *   @0xcde2c mov r7, r0
 *   @0xcde30 bne 0xcde3c <_ZN7IBuffer5WriteEPKc+0x84>
 *   @0xcde34 mov r0, r6
 *   @0xcde38 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xcde3c ldr r12, [r11, #-0x18]
 *   @0xcde40 mov r3, #0
 *   @0xcde44 ldr r1, [r5]
 *   @0xcde48 mov r2, #5
 *   @0xcde4c mov r0, r7
 *   @0xcde50 str r3, [r4, #0x34]
 *   @0xcde54 cmp r12, r1
 *   @0xcde58 str r3, [r4, #0x2c]
 *   @0xcde5c str r2, [r4, #0x38]
 *   @0xcde60 bne 0xcde6c <_ZN7IBuffer5WriteEPKc+0xb4>
 *   @0xcde64 sub sp, r11, #20
 *   @0xcde68 pop {r4, r5, r6, r7, r11, pc}
 *   @0xcde6c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0xcde70 eorseq pc, r1, r4, lsl #23
 *
 * ══ §120/156 Font_Replace(int, char const*, int, bool, bool, int, int)  0xfa908  size 188  47 条（0xfa908..0xfa9c4）
 * @func 0xfa908 0xfa9c4  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Font_Replace(int, char const*, int, bool, bool, int, int)+0x34 / Font_Replace(int, char const*, int, bool, bool, int, int)+0x40 / operator new(unsigned int) / CFontGM::CFontGM(char const*, int, bool, bool, int, int)
 * 字段偏移 top8: 0x4×4 / 0x30×1 / 0x8c×1 / 0x6c×1 / 0x34×1 / 0x38×1 / 0x8×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfa908 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xfa90c subs r4, r0, #0
 *   @0xfa910 sub sp, sp, #16
 *   @0xfa914 mov r8, r1
 *   @0xfa918 mov r7, r2
 *   @0xfa91c mov r6, r3
 *   @0xfa920 ldrb r9, [sp, #0x30]
 *   @0xfa924 blt 0xfa93c <_Z12Font_ReplaceiPKcibbii+0x34>
 *   @0xfa928 ldr r12, [pc, #0x8c]
 *   @0xfa92c ldr r12, [pc, r12]
 *   @0xfa930 ldr r0, [r12]
 *   @0xfa934 cmp r4, r0
 *   @0xfa938 blt 0xfa948 <_Z12Font_ReplaceiPKcibbii+0x40>
 *   @0xfa93c mov r0, #0
 *   @0xfa940 add sp, sp, #16
 *   @0xfa944 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xfa948 mov r0, #144
 *   @0xfa94c ldr r5, [pc, #0x6c]
 *   @0xfa950 bl 0x27c524 <_Znwj>
 *   @0xfa954 ldr r3, [sp, #0x34]
 *   @0xfa958 mov r2, r7
 *   @0xfa95c str r9, [sp]
 *   @0xfa960 mov r1, r8
 *   @0xfa964 str r3, [sp, #0x4]
 *   @0xfa968 ldr r3, [sp, #0x38]
 *   @0xfa96c str r3, [sp, #0x8]
 *   @0xfa970 mov r3, r6
 *   @0xfa974 lsl r6, r4, #2
 *   @0xfa978 mov r10, r0
 *   @0xfa97c bl 0xf9e08 <_ZN7CFontGMC2EPKcibbii>
 *   @0xfa980 ldr r5, [pc, r5]
 *   @0xfa984 ldr r3, [r5, #0x4]
 *   @0xfa988 add r2, r3, r6
 *   @0xfa98c ldr r0, [r3, r4, lsl #2]
 *   @0xfa990 cmp r0, #0
 *   @0xfa994 beq 0xfa9ac <_Z12Font_ReplaceiPKcibbii+0xa4>
 *   @0xfa998 ldr r3, [r0]
 *   @0xfa99c ldr r3, [r3, #0x4]
 *   @0xfa9a0 blx r3
 *   @0xfa9a4 ldr r2, [r5, #0x4]
 *   @0xfa9a8 add r2, r2, r6
 *   @0xfa9ac mov r0, #1
 *   @0xfa9b0 str r10, [r2]
 *   @0xfa9b4 add sp, sp, #16
 *   @0xfa9b8 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xfa9bc eoreq r3, pc, r4, lsr r5
 *   @0xfa9c0 .word 0x002f34dc
 *
 * ══ §121/156 F_DsListRead(RValue&, CInstance*, CInstance*, int, RValue*)  0xfc9f4  size 188  47 条（0xfc9f4..0xfcab0）
 * @func 0xfc9f4 0xfcab0  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / YYGetString(RValue const*, int) / F_DsListRead(RValue&, CInstance*, CInstance*, int, RValue*)+0x80
 * 字段偏移 top8: 0x18×1 / 0x68×1 / 0x58×1 / 0x4×1 / 0x2×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfc9f4 push {r3, r4, r5, r6, r7, lr}
 *   @0xfc9f8 mov r1, #0
 *   @0xfc9fc ldr r5, [sp, #0x18]
 *   @0xfca00 mov r6, r3
 *   @0xfca04 mov r0, r5
 *   @0xfca08 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfca0c mov r1, #1
 *   @0xfca10 mov r4, r0
 *   @0xfca14 mov r0, r5
 *   @0xfca18 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0xfca1c cmp r6, #3
 *   @0xfca20 movne r2, #0
 *   @0xfca24 mov r7, r0
 *   @0xfca28 beq 0xfca88 <_Z12F_DsListReadR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0xfca2c cmp r4, #0
 *   @0xfca30 blt 0xfca74 <_Z12F_DsListReadR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0xfca34 ldr r3, [pc, #0x68]
 *   @0xfca38 ldr r3, [pc, r3]
 *   @0xfca3c ldr r3, [r3]
 *   @0xfca40 cmp r4, r3
 *   @0xfca44 bge 0xfca74 <_Z12F_DsListReadR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0xfca48 ldr r3, [pc, #0x58]
 *   @0xfca4c ldr r3, [pc, r3]
 *   @0xfca50 ldr r3, [r3, #0x4]
 *   @0xfca54 ldr r0, [r3, r4, lsl #2]
 *   @0xfca58 cmp r0, #0
 *   @0xfca5c beq 0xfca74 <_Z12F_DsListReadR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0xfca60 cmp r7, #0
 *   @0xfca64 popeq {r3, r4, r5, r6, r7, pc}
 *   @0xfca68 mov r1, r7
 *   @0xfca6c pop {r3, r4, r5, r6, r7, lr}
 *   @0xfca70 b 0x20e968 <_ZN8CDS_List14ReadFromStringEPKcb>
 *   @0xfca74 ldr r0, [pc, #0x30]
 *   @0xfca78 mov r1, #0
 *   @0xfca7c pop {r3, r4, r5, r6, r7, lr}
 *   @0xfca80 add r0, pc, r0
 *   @0xfca84 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfca88 mov r0, r5
 *   @0xfca8c mov r1, #2
 *   @0xfca90 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfca94 cmp r0, #0
 *   @0xfca98 movle r2, #0
 *   @0xfca9c movgt r2, #1
 *   @0xfcaa0 b 0xfca2c <_Z12F_DsListReadR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0xfcaa4 eoreq r1, pc, r4, asr #4
 *   @0xfcaa8 eoreq r1, pc, r4, lsr r2
 *   @0xfcaac eoreq r11, r3, r12, ror r1
 *
 * ══ §122/156 F_DsGridResize(RValue&, CInstance*, CInstance*, int, RValue*)  0xfd100  size 188  47 条（0xfd100..0xfd1bc）
 * @func 0xfd100 0xfd1bc  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / F_DsGridResize(RValue&, CInstance*, CInstance*, int, RValue*)+0x84 / F_DsGridResize(RValue&, CInstance*, CInstance*, int, RValue*)+0x98
 * 字段偏移 top8: 0x10×1 / 0x64×1 / 0x54×1 / 0x4×1 / 0x2×1 / 0x28×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfd100 push {r4, r5, r6, lr}
 *   @0xfd104 mov r1, #0
 *   @0xfd108 ldr r4, [sp, #0x10]
 *   @0xfd10c mov r0, r4
 *   @0xfd110 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfd114 mov r1, #1
 *   @0xfd118 mov r5, r0
 *   @0xfd11c mov r0, r4
 *   @0xfd120 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfd124 mov r1, #2
 *   @0xfd128 mov r6, r0
 *   @0xfd12c mov r0, r4
 *   @0xfd130 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfd134 cmp r5, #0
 *   @0xfd138 mov r2, r0
 *   @0xfd13c blt 0xfd184 <_Z14F_DsGridResizeR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0xfd140 ldr r3, [pc, #0x64]
 *   @0xfd144 ldr r3, [pc, r3]
 *   @0xfd148 ldr r3, [r3]
 *   @0xfd14c cmp r5, r3
 *   @0xfd150 bge 0xfd184 <_Z14F_DsGridResizeR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0xfd154 ldr r3, [pc, #0x54]
 *   @0xfd158 ldr r3, [pc, r3]
 *   @0xfd15c ldr r3, [r3, #0x4]
 *   @0xfd160 ldr r0, [r3, r5, lsl #2]
 *   @0xfd164 cmp r0, #0
 *   @0xfd168 beq 0xfd184 <_Z14F_DsGridResizeR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0xfd16c cmp r6, #0
 *   @0xfd170 cmpgt r2, #0
 *   @0xfd174 ble 0xfd198 <_Z14F_DsGridResizeR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0xfd178 mov r1, r6
 *   @0xfd17c pop {r4, r5, r6, lr}
 *   @0xfd180 b 0x20c3bc <_ZN8CDS_Grid6ResizeEii>
 *   @0xfd184 ldr r0, [pc, #0x28]
 *   @0xfd188 mov r1, #0
 *   @0xfd18c pop {r4, r5, r6, lr}
 *   @0xfd190 add r0, pc, r0
 *   @0xfd194 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfd198 ldr r0, [pc, #0x18]
 *   @0xfd19c mov r1, #1
 *   @0xfd1a0 pop {r4, r5, r6, lr}
 *   @0xfd1a4 add r0, pc, r0
 *   @0xfd1a8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfd1ac eoreq r0, pc, r0, asr #26
 *   @0xfd1b0 eoreq r0, pc, r0, lsr sp
 *   @0xfd1b4 eoreq r10, r3, r12, ror #20
 *   @0xfd1b8 eoreq r10, r3, r4, lsl #21
 *
 * ══ §123/156 F_DsMapWrite(RValue&, CInstance*, CInstance*, int, RValue*)  0xff954  size 188  47 条（0xff954..0xffa10）
 * @func 0xff954 0xffa10  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DS_AutoMutex::~DS_AutoMutex()×2 / DS_AutoMutex::DS_AutoMutex() / YYGetInt32(RValue const*, int) / F_DsMapWrite(RValue&, CInstance*, CInstance*, int, RValue*)+0x90 / CDS_Map::WriteToString(char const*&) / YYCreateString(RValue*, char const*) / YYFree(void const*) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x4×3 / 0x2×2 / 0x18×1 / 0x7c×1 / 0x6c×1 / 0x-4×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xff954 push {r4, r5, r6, lr}
 *   @0xff958 sub sp, sp, #8
 *   @0xff95c mov r6, r0
 *   @0xff960 ldr r5, [sp, #0x18]
 *   @0xff964 mov r0, sp
 *   @0xff968 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0xff96c mov r1, #0
 *   @0xff970 mov r0, r5
 *   @0xff974 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xff978 subs r2, r0, #0
 *   @0xff97c blt 0xff9e4 <_Z12F_DsMapWriteR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0xff980 ldr r3, [pc, #0x7c]
 *   @0xff984 ldr r3, [pc, r3]
 *   @0xff988 ldr r3, [r3]
 *   @0xff98c cmp r2, r3
 *   @0xff990 bge 0xff9e4 <_Z12F_DsMapWriteR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0xff994 ldr r3, [pc, #0x6c]
 *   @0xff998 ldr r3, [pc, r3]
 *   @0xff99c ldr r3, [r3, #0x4]
 *   @0xff9a0 ldr r1, [r3, r2, lsl #2]
 *   @0xff9a4 cmp r1, #0
 *   @0xff9a8 beq 0xff9e4 <_Z12F_DsMapWriteR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0xff9ac add r1, sp, #8
 *   @0xff9b0 mov r0, #0
 *   @0xff9b4 str r0, [r1, #-0x4]!
 *   @0xff9b8 ldr r0, [r3, r2, lsl #2]
 *   @0xff9bc bl 0x203948 <_ZN7CDS_Map13WriteToStringERPKc>
 *   @0xff9c0 ldr r1, [sp, #0x4]
 *   @0xff9c4 mov r0, r6
 *   @0xff9c8 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0xff9cc ldr r0, [sp, #0x4]
 *   @0xff9d0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xff9d4 mov r0, sp
 *   @0xff9d8 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xff9dc add sp, sp, #8
 *   @0xff9e0 pop {r4, r5, r6, pc}
 *   @0xff9e4 ldr r0, [pc, #0x20]
 *   @0xff9e8 mov r1, #0
 *   @0xff9ec add r0, pc, r0
 *   @0xff9f0 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xff9f4 mov r0, sp
 *   @0xff9f8 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xff9fc add sp, sp, #8
 *   @0xffa00 pop {r4, r5, r6, pc}
 *   @0xffa04 .word 0x002ee2f4
 *   @0xffa08 eoreq sp, lr, r4, lsr #31
 *   @0xffa0c eoreq r8, r3, r0, lsl r2
 *
 * ══ §124/156 F_MpGridAddInstances(RValue&, CInstance*, CInstance*, int, RValue*)  0x108e78  size 188  47 条（0x108e78..0x108f34）
 * @func 0x108e78 0x108f34  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / WithObjIterator::operator*()×2 / YYGetBool(RValue const*, int) / WithObjIterator::WithObjIterator(int, CInstance*, CInstance*, bool) / WithObjIterator::Next() / Motion_Grid_AddInstance(int, CInstance*, bool)
 * 字段偏移 top8: 0x50×1 / 0x68×1 / 0x69×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x108e78 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x108e7c sub sp, sp, #48
 *   @0x108e80 mov r9, r1
 *   @0x108e84 mov r1, #0
 *   @0x108e88 ldr r5, [sp, #0x50]
 *   @0x108e8c mov r6, r2
 *   @0x108e90 add r4, sp, #12
 *   @0x108e94 mov r0, r5
 *   @0x108e98 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x108e9c mov r1, #1
 *   @0x108ea0 mov r7, r0
 *   @0x108ea4 mov r0, r5
 *   @0x108ea8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x108eac mov r1, #2
 *   @0x108eb0 mov r10, r0
 *   @0x108eb4 mov r0, r5
 *   @0x108eb8 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x108ebc mov r12, #0
 *   @0x108ec0 mov r1, r10
 *   @0x108ec4 mov r2, r9
 *   @0x108ec8 mov r3, r6
 *   @0x108ecc str r12, [sp]
 *   @0x108ed0 mov r8, r0
 *   @0x108ed4 mov r0, r4
 *   @0x108ed8 bl 0x19d060 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b>
 *   @0x108edc mov r0, r4
 *   @0x108ee0 bl 0x19de4c <_ZN15WithObjIteratordeEv>
 *   @0x108ee4 cmp r0, #0
 *   @0x108ee8 mov r0, r4
 *   @0x108eec beq 0x108f2c <_Z20F_MpGridAddInstancesR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x108ef0 bl 0x19de4c <_ZN15WithObjIteratordeEv>
 *   @0x108ef4 mov r5, r0
 *   @0x108ef8 mov r0, r4
 *   @0x108efc bl 0x19d1c8 <_ZN15WithObjIterator4NextEv>
 *   @0x108f00 ldrb r3, [r5, #0x68]
 *   @0x108f04 cmp r3, #0
 *   @0x108f08 bne 0x108edc <_Z20F_MpGridAddInstancesR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x108f0c ldrb r3, [r5, #0x69]
 *   @0x108f10 cmp r3, #0
 *   @0x108f14 bne 0x108edc <_Z20F_MpGridAddInstancesR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x108f18 mov r1, r5
 *   @0x108f1c mov r0, r7
 *   @0x108f20 mov r2, r8
 *   @0x108f24 bl 0x19a618 <_Z23Motion_Grid_AddInstanceiP9CInstanceb>
 *   @0x108f28 b 0x108edc <_Z20F_MpGridAddInstancesR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x108f2c add sp, sp, #48
 *   @0x108f30 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ §125/156 F_Median(RValue&, CInstance*, CInstance*, int, RValue*)  0x10eb68  size 188  47 条（0x10eb68..0x10ec24）
 * @func 0x10eb68 0x10ec24  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_Median(RValue&, CInstance*, CInstance*, int, RValue*)+0x98 / YYGetReal(RValue const*, int) / 0xb66dc / 0xb65d4
 * 字段偏移 top8: 0x4×3 / 0x-28×2 / 0xa4×1 / 0xc×1 / 0x44×1 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10eb68 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x10eb6c add r11, sp, #32
 *   @0x10eb70 ldr r9, [pc, #0xa4]
 *   @0x10eb74 sub sp, sp, #12
 *   @0x10eb78 subs r6, r3, #0
 *   @0x10eb7c ldr r9, [pc, r9]
 *   @0x10eb80 mov r4, #0
 *   @0x10eb84 mov r8, r0
 *   @0x10eb88 str r4, [r0, #0xc]
 *   @0x10eb8c ldr r3, [r9]
 *   @0x10eb90 str r4, [r0, #0x4]
 *   @0x10eb94 ldr r7, [r11, #0x4]
 *   @0x10eb98 str r4, [r0]
 *   @0x10eb9c str r3, [r11, #-0x28]
 *   @0x10eba0 ble 0x10ec00 <_Z8F_MedianR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x10eba4 lsl r3, r6, #3
 *   @0x10eba8 add r3, r3, #8
 *   @0x10ebac sub sp, sp, r3
 *   @0x10ebb0 mov r10, sp
 *   @0x10ebb4 mov r5, sp
 *   @0x10ebb8 mov r1, r4
 *   @0x10ebbc mov r0, r7
 *   @0x10ebc0 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x10ebc4 add r4, r4, #1
 *   @0x10ebc8 cmp r4, r6
 *   @0x10ebcc strd r0, r1, [r5], #8
 *   @0x10ebd0 bne 0x10ebb8 <_Z8F_MedianR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x10ebd4 ldr r3, [pc, #0x44]
 *   @0x10ebd8 mov r1, r4
 *   @0x10ebdc asr r4, r4, #1
 *   @0x10ebe0 mov r2, #8
 *   @0x10ebe4 ldr r3, [pc, r3]
 *   @0x10ebe8 mov r0, r10
 *   @0x10ebec bl 0xb66dc <qsort@plt>
 *   @0x10ebf0 add r3, r10, r4, lsl #3
 *   @0x10ebf4 ldr r2, [r10, r4, lsl #3]
 *   @0x10ebf8 ldr r3, [r3, #0x4]
 *   @0x10ebfc stm r8, {r2, r3}
 *   @0x10ec00 ldr r2, [r11, #-0x28]
 *   @0x10ec04 ldr r3, [r9]
 *   @0x10ec08 cmp r2, r3
 *   @0x10ec0c bne 0x10ec18 <_Z8F_MedianR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x10ec10 sub sp, r11, #32
 *   @0x10ec14 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x10ec18 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x10ec1c .word 0x002dedd4
 *   @0x10ec20 eoreq pc, sp, r12, ror #12
 *
 * ══ §126/156 F_DateValidDateTime(RValue&, CInstance*, CInstance*, int, RValue*)  0x117f98  size 188  47 条（0x117f98..0x118054）
 * @func 0x117f98 0x118054  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×6 / date_is_valid(int, int, int)
 * 字段偏移 top8: 0x28×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x117f98 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x117f9c mov r5, #0
 *   @0x117fa0 ldr r4, [sp, #0x28]
 *   @0x117fa4 mov r1, r5
 *   @0x117fa8 str r5, [r0, #0xc]
 *   @0x117fac mov r6, r0
 *   @0x117fb0 str r5, [r0]
 *   @0x117fb4 str r5, [r0, #0x4]
 *   @0x117fb8 mov r0, r4
 *   @0x117fbc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x117fc0 mov r1, #1
 *   @0x117fc4 mov r7, r0
 *   @0x117fc8 mov r0, r4
 *   @0x117fcc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x117fd0 mov r1, #2
 *   @0x117fd4 mov r8, r0
 *   @0x117fd8 mov r0, r4
 *   @0x117fdc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x117fe0 mov r1, #3
 *   @0x117fe4 mov r9, r0
 *   @0x117fe8 mov r0, r4
 *   @0x117fec bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x117ff0 mov r1, #4
 *   @0x117ff4 mov r10, r0
 *   @0x117ff8 mov r0, r4
 *   @0x117ffc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x118000 mov r1, #5
 *   @0x118004 mov r11, r0
 *   @0x118008 mov r0, r4
 *   @0x11800c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x118010 mov r1, r8
 *   @0x118014 mov r2, r7
 *   @0x118018 mov r4, r0
 *   @0x11801c mov r0, r9
 *   @0x118020 bl 0x117eec <_Z13date_is_validiii>
 *   @0x118024 cmp r0, r5
 *   @0x118028 popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x11802c cmp r10, #23
 *   @0x118030 pophi {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x118034 cmp r11, #59
 *   @0x118038 pophi {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x11803c cmp r4, #59
 *   @0x118040 strls r5, [r6]
 *   @0x118044 movls r3, r5
 *   @0x118048 movtls r3, #0x3ff0
 *   @0x11804c strls r3, [r6, #0x4]
 *   @0x118050 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §127/156 F_TileSetVisible(RValue&, CInstance*, CInstance*, int, RValue*)  0x1206f8  size 188  47 条（0x1206f8..0x1207b4）
 * @func 0x1206f8 0x1207b4  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CRoom::FindTile(int) / F_TileSetVisible(RValue&, CInstance*, CInstance*, int, RValue*)+0xa0 / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0xb8×2 / 0x18×1 / 0xa0×1 / 0x34×1 / 0xc0×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1206f8 push {r3, r4, r5, r6, r7, lr}
 *   @0x1206fc mov r1, #0
 *   @0x120700 ldr r7, [sp, #0x18]
 *   @0x120704 ldr r5, [pc, #0xa0]
 *   @0x120708 ldr r5, [pc, r5]
 *   @0x12070c mov r0, r7
 *   @0x120710 ldr r4, [r5]
 *   @0x120714 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x120718 mov r1, r0
 *   @0x12071c mov r0, r4
 *   @0x120720 bl 0x1af2bc <_ZN5CRoom8FindTileEi>
 *   @0x120724 subs r6, r0, #0
 *   @0x120728 blt 0x120798 <_Z16F_TileSetVisibleR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x12072c ldr r3, [r5]
 *   @0x120730 mov r0, r7
 *   @0x120734 mov r1, #1
 *   @0x120738 ldr r2, [r3, #0xb8]
 *   @0x12073c cmp r6, r2
 *   @0x120740 rsblt r4, r6, r6, lsl #3
 *   @0x120744 ldrlt r3, [r3, #0xc0]
 *   @0x120748 movge r4, #0
 *   @0x12074c addlt r4, r3, r4, lsl #3
 *   @0x120750 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x120754 ldr r3, [r5]
 *   @0x120758 ldr r2, [r3, #0xb8]
 *   @0x12075c cmp r6, r2
 *   @0x120760 strb r0, [r4, #0x34]
 *   @0x120764 popge {r3, r4, r5, r6, r7, pc}
 *   @0x120768 ldr r5, [r3, #0xc0]
 *   @0x12076c rsb r6, r6, r6, lsl #3
 *   @0x120770 ldm r4!, {r0, r1, r2, r3}
 *   @0x120774 add r12, r5, r6, lsl #3
 *   @0x120778 stm r12!, {r0, r1, r2, r3}
 *   @0x12077c ldm r4!, {r0, r1, r2, r3}
 *   @0x120780 stm r12!, {r0, r1, r2, r3}
 *   @0x120784 ldm r4!, {r0, r1, r2, r3}
 *   @0x120788 stm r12!, {r0, r1, r2, r3}
 *   @0x12078c ldm r4, {r0, r1}
 *   @0x120790 stm r12, {r0, r1}
 *   @0x120794 pop {r3, r4, r5, r6, r7, pc}
 *   @0x120798 ldr r0, [pc, #0x10]
 *   @0x12079c mov r1, #0
 *   @0x1207a0 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1207a4 add r0, pc, r0
 *   @0x1207a8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1207ac eoreq sp, r12, r0, lsr #4
 *   @0x1207b0 eoreq r9, r1, r8, asr r10
 *
 * ══ §128/156 F_TileSetBackground(RValue&, CInstance*, CInstance*, int, RValue*)  0x1207b4  size 188  47 条（0x1207b4..0x120870）
 * @func 0x1207b4 0x120870  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / CRoom::FindTile(int) / F_TileSetBackground(RValue&, CInstance*, CInstance*, int, RValue*)+0xa0
 * 字段偏移 top8: 0xb8×2 / 0x18×1 / 0xa0×1 / 0x8×1 / 0xc0×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1207b4 push {r3, r4, r5, r6, r7, lr}
 *   @0x1207b8 mov r1, #0
 *   @0x1207bc ldr r7, [sp, #0x18]
 *   @0x1207c0 ldr r5, [pc, #0xa0]
 *   @0x1207c4 ldr r5, [pc, r5]
 *   @0x1207c8 mov r0, r7
 *   @0x1207cc ldr r4, [r5]
 *   @0x1207d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1207d4 mov r1, r0
 *   @0x1207d8 mov r0, r4
 *   @0x1207dc bl 0x1af2bc <_ZN5CRoom8FindTileEi>
 *   @0x1207e0 subs r6, r0, #0
 *   @0x1207e4 blt 0x120854 <_Z19F_TileSetBackgroundR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x1207e8 ldr r3, [r5]
 *   @0x1207ec mov r0, r7
 *   @0x1207f0 mov r1, #1
 *   @0x1207f4 ldr r2, [r3, #0xb8]
 *   @0x1207f8 cmp r6, r2
 *   @0x1207fc rsblt r4, r6, r6, lsl #3
 *   @0x120800 ldrlt r3, [r3, #0xc0]
 *   @0x120804 movge r4, #0
 *   @0x120808 addlt r4, r3, r4, lsl #3
 *   @0x12080c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x120810 ldr r3, [r5]
 *   @0x120814 ldr r2, [r3, #0xb8]
 *   @0x120818 cmp r6, r2
 *   @0x12081c str r0, [r4, #0x8]
 *   @0x120820 popge {r3, r4, r5, r6, r7, pc}
 *   @0x120824 ldr r5, [r3, #0xc0]
 *   @0x120828 rsb r6, r6, r6, lsl #3
 *   @0x12082c ldm r4!, {r0, r1, r2, r3}
 *   @0x120830 add r12, r5, r6, lsl #3
 *   @0x120834 stm r12!, {r0, r1, r2, r3}
 *   @0x120838 ldm r4!, {r0, r1, r2, r3}
 *   @0x12083c stm r12!, {r0, r1, r2, r3}
 *   @0x120840 ldm r4!, {r0, r1, r2, r3}
 *   @0x120844 stm r12!, {r0, r1, r2, r3}
 *   @0x120848 ldm r4, {r0, r1}
 *   @0x12084c stm r12, {r0, r1}
 *   @0x120850 pop {r3, r4, r5, r6, r7, pc}
 *   @0x120854 ldr r0, [pc, #0x10]
 *   @0x120858 mov r1, #0
 *   @0x12085c pop {r3, r4, r5, r6, r7, lr}
 *   @0x120860 add r0, pc, r0
 *   @0x120864 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x120868 eoreq sp, r12, r4, ror #2
 *   @0x12086c mlaeq r1, r12, r9, r9
 *
 * ══ §129/156 F_TileSetDepth(RValue&, CInstance*, CInstance*, int, RValue*)  0x120870  size 188  47 条（0x120870..0x12092c）
 * @func 0x120870 0x12092c  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CRoom::FindTile(int) / F_TileSetDepth(RValue&, CInstance*, CInstance*, int, RValue*)+0xa0 / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0xb8×2 / 0x18×1 / 0xa0×1 / 0x1c×1 / 0xc0×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x120870 push {r3, r4, r5, r6, r7, lr}
 *   @0x120874 mov r1, #0
 *   @0x120878 ldr r7, [sp, #0x18]
 *   @0x12087c ldr r5, [pc, #0xa0]
 *   @0x120880 ldr r5, [pc, r5]
 *   @0x120884 mov r0, r7
 *   @0x120888 ldr r4, [r5]
 *   @0x12088c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x120890 mov r1, r0
 *   @0x120894 mov r0, r4
 *   @0x120898 bl 0x1af2bc <_ZN5CRoom8FindTileEi>
 *   @0x12089c subs r6, r0, #0
 *   @0x1208a0 blt 0x120910 <_Z14F_TileSetDepthR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x1208a4 ldr r3, [r5]
 *   @0x1208a8 mov r0, r7
 *   @0x1208ac mov r1, #1
 *   @0x1208b0 ldr r2, [r3, #0xb8]
 *   @0x1208b4 cmp r6, r2
 *   @0x1208b8 rsblt r4, r6, r6, lsl #3
 *   @0x1208bc ldrlt r3, [r3, #0xc0]
 *   @0x1208c0 movge r4, #0
 *   @0x1208c4 addlt r4, r3, r4, lsl #3
 *   @0x1208c8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1208cc ldr r3, [r5]
 *   @0x1208d0 ldr r2, [r3, #0xb8]
 *   @0x1208d4 cmp r6, r2
 *   @0x1208d8 str r0, [r4, #0x1c]
 *   @0x1208dc popge {r3, r4, r5, r6, r7, pc}
 *   @0x1208e0 ldr r5, [r3, #0xc0]
 *   @0x1208e4 rsb r6, r6, r6, lsl #3
 *   @0x1208e8 ldm r4!, {r0, r1, r2, r3}
 *   @0x1208ec add r12, r5, r6, lsl #3
 *   @0x1208f0 stm r12!, {r0, r1, r2, r3}
 *   @0x1208f4 ldm r4!, {r0, r1, r2, r3}
 *   @0x1208f8 stm r12!, {r0, r1, r2, r3}
 *   @0x1208fc ldm r4!, {r0, r1, r2, r3}
 *   @0x120900 stm r12!, {r0, r1, r2, r3}
 *   @0x120904 ldm r4, {r0, r1}
 *   @0x120908 stm r12, {r0, r1}
 *   @0x12090c pop {r3, r4, r5, r6, r7, pc}
 *   @0x120910 ldr r0, [pc, #0x10]
 *   @0x120914 mov r1, #0
 *   @0x120918 pop {r3, r4, r5, r6, r7, lr}
 *   @0x12091c add r0, pc, r0
 *   @0x120920 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x120924 eoreq sp, r12, r8, lsr #1
 *   @0x120928 eoreq r9, r1, r0, ror #17
 *
 * ══ §130/156 F_TileSetBlend(RValue&, CInstance*, CInstance*, int, RValue*)  0x12092c  size 188  47 条（0x12092c..0x1209e8）
 * @func 0x12092c 0x1209e8  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / CRoom::FindTile(int) / F_TileSetBlend(RValue&, CInstance*, CInstance*, int, RValue*)+0xa0
 * 字段偏移 top8: 0xb8×2 / 0x18×1 / 0xa0×1 / 0x2c×1 / 0xc0×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12092c push {r3, r4, r5, r6, r7, lr}
 *   @0x120930 mov r1, #0
 *   @0x120934 ldr r7, [sp, #0x18]
 *   @0x120938 ldr r5, [pc, #0xa0]
 *   @0x12093c ldr r5, [pc, r5]
 *   @0x120940 mov r0, r7
 *   @0x120944 ldr r4, [r5]
 *   @0x120948 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12094c mov r1, r0
 *   @0x120950 mov r0, r4
 *   @0x120954 bl 0x1af2bc <_ZN5CRoom8FindTileEi>
 *   @0x120958 subs r6, r0, #0
 *   @0x12095c blt 0x1209cc <_Z14F_TileSetBlendR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x120960 ldr r3, [r5]
 *   @0x120964 mov r0, r7
 *   @0x120968 mov r1, #1
 *   @0x12096c ldr r2, [r3, #0xb8]
 *   @0x120970 cmp r6, r2
 *   @0x120974 rsblt r4, r6, r6, lsl #3
 *   @0x120978 ldrlt r3, [r3, #0xc0]
 *   @0x12097c movge r4, #0
 *   @0x120980 addlt r4, r3, r4, lsl #3
 *   @0x120984 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x120988 ldr r3, [r5]
 *   @0x12098c ldr r2, [r3, #0xb8]
 *   @0x120990 cmp r6, r2
 *   @0x120994 str r0, [r4, #0x2c]
 *   @0x120998 popge {r3, r4, r5, r6, r7, pc}
 *   @0x12099c ldr r5, [r3, #0xc0]
 *   @0x1209a0 rsb r6, r6, r6, lsl #3
 *   @0x1209a4 ldm r4!, {r0, r1, r2, r3}
 *   @0x1209a8 add r12, r5, r6, lsl #3
 *   @0x1209ac stm r12!, {r0, r1, r2, r3}
 *   @0x1209b0 ldm r4!, {r0, r1, r2, r3}
 *   @0x1209b4 stm r12!, {r0, r1, r2, r3}
 *   @0x1209b8 ldm r4!, {r0, r1, r2, r3}
 *   @0x1209bc stm r12!, {r0, r1, r2, r3}
 *   @0x1209c0 ldm r4, {r0, r1}
 *   @0x1209c4 stm r12, {r0, r1}
 *   @0x1209c8 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1209cc ldr r0, [pc, #0x10]
 *   @0x1209d0 mov r1, #0
 *   @0x1209d4 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1209d8 add r0, pc, r0
 *   @0x1209dc b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1209e0 eoreq r12, r12, r12, ror #31
 *   @0x1209e4 eoreq r9, r1, r4, lsr #16
 *
 * ══ §131/156 F_TileSetAlpha(RValue&, CInstance*, CInstance*, int, RValue*)  0x1209e8  size 188  47 条（0x1209e8..0x120aa4）
 * @func 0x1209e8 0x120aa4  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / CRoom::FindTile(int) / F_TileSetAlpha(RValue&, CInstance*, CInstance*, int, RValue*)+0xa0 / YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0xb8×2 / 0x18×1 / 0xa0×1 / 0x30×1 / 0xc0×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1209e8 push {r3, r4, r5, r6, r7, lr}
 *   @0x1209ec mov r1, #0
 *   @0x1209f0 ldr r7, [sp, #0x18]
 *   @0x1209f4 ldr r5, [pc, #0xa0]
 *   @0x1209f8 ldr r5, [pc, r5]
 *   @0x1209fc mov r0, r7
 *   @0x120a00 ldr r4, [r5]
 *   @0x120a04 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x120a08 mov r1, r0
 *   @0x120a0c mov r0, r4
 *   @0x120a10 bl 0x1af2bc <_ZN5CRoom8FindTileEi>
 *   @0x120a14 subs r6, r0, #0
 *   @0x120a18 blt 0x120a88 <_Z14F_TileSetAlphaR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x120a1c ldr r3, [r5]
 *   @0x120a20 mov r0, r7
 *   @0x120a24 mov r1, #1
 *   @0x120a28 ldr r2, [r3, #0xb8]
 *   @0x120a2c cmp r6, r2
 *   @0x120a30 rsblt r4, r6, r6, lsl #3
 *   @0x120a34 ldrlt r3, [r3, #0xc0]
 *   @0x120a38 movge r4, #0
 *   @0x120a3c addlt r4, r3, r4, lsl #3
 *   @0x120a40 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x120a44 ldr r3, [r5]
 *   @0x120a48 ldr r2, [r3, #0xb8]
 *   @0x120a4c cmp r6, r2
 *   @0x120a50 str r0, [r4, #0x30]
 *   @0x120a54 popge {r3, r4, r5, r6, r7, pc}
 *   @0x120a58 ldr r5, [r3, #0xc0]
 *   @0x120a5c rsb r6, r6, r6, lsl #3
 *   @0x120a60 ldm r4!, {r0, r1, r2, r3}
 *   @0x120a64 add r12, r5, r6, lsl #3
 *   @0x120a68 stm r12!, {r0, r1, r2, r3}
 *   @0x120a6c ldm r4!, {r0, r1, r2, r3}
 *   @0x120a70 stm r12!, {r0, r1, r2, r3}
 *   @0x120a74 ldm r4!, {r0, r1, r2, r3}
 *   @0x120a78 stm r12!, {r0, r1, r2, r3}
 *   @0x120a7c ldm r4, {r0, r1}
 *   @0x120a80 stm r12, {r0, r1}
 *   @0x120a84 pop {r3, r4, r5, r6, r7, pc}
 *   @0x120a88 ldr r0, [pc, #0x10]
 *   @0x120a8c mov r1, #0
 *   @0x120a90 pop {r3, r4, r5, r6, r7, lr}
 *   @0x120a94 add r0, pc, r0
 *   @0x120a98 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x120a9c eoreq r12, r12, r0, lsr pc
 *   @0x120aa0 eoreq r9, r1, r8, ror #14
 *
 * ══ §132/156 F_FileOpenRead(RValue&, CInstance*, CInstance*, int, RValue*)  0x1383b8  size 188  47 条（0x1383b8..0x138474）
 * @func 0x1383b8 0x138474  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1383cc→0x483724, 0x138400→0x4837a4, 0x13843c→0x4837a4
 * 调用序列: MemoryManager::Free(void const*)×2 / YYGetString(RValue const*, int) / FileExists(char const*) / YYStrDup(char const*) / 0xb6844 / 0xb6850
 * 字段偏移 top8: 0x8×3 / 0x94×2 / 0x18×1 / 0x64×1 / 0x4c×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1383b8 push {r4, r5, r6, r7, r8, lr}
 *   @0x1383bc mov r1, #0
 *   @0x1383c0 ldr r0, [sp, #0x18]
 *   @0x1383c4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1383c8 ldr r4, [pc, #0x94]
 *   @0x1383cc ldr r3, [pc, #0x94]
 *   @0x1383d0 add r4, pc, r4
 *   @0x1383d4 ldr r5, [r4, r3]
 *   @0x1383d8 ldr r3, [r5]
 *   @0x1383dc cmp r3, #0
 *   @0x1383e0 mov r7, r0
 *   @0x1383e4 bne 0x13843c <_Z14F_FileOpenReadR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x1383e8 mov r0, r7
 *   @0x1383ec mov r6, #0
 *   @0x1383f0 str r6, [r5]
 *   @0x1383f4 bl 0x214e48 <_Z10FileExistsPKc>
 *   @0x1383f8 cmp r0, r6
 *   @0x1383fc popeq {r4, r5, r6, r7, r8, pc}
 *   @0x138400 ldr r3, [pc, #0x64]
 *   @0x138404 ldr r4, [r4, r3]
 *   @0x138408 ldr r0, [r4]
 *   @0x13840c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x138410 mov r0, r7
 *   @0x138414 str r6, [r4]
 *   @0x138418 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x13841c ldr r1, [pc, #0x4c]
 *   @0x138420 add r1, pc, r1
 *   @0x138424 str r0, [r4]
 *   @0x138428 bl 0xb6844 <fopen@plt>
 *   @0x13842c mov r3, #1
 *   @0x138430 str r3, [r5]
 *   @0x138434 str r0, [r4, #0x8]
 *   @0x138438 pop {r4, r5, r6, r7, r8, pc}
 *   @0x13843c ldr r3, [pc, #0x28]
 *   @0x138440 mov r8, #0
 *   @0x138444 ldr r6, [r4, r3]
 *   @0x138448 ldr r0, [r6]
 *   @0x13844c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x138450 ldr r0, [r6, #0x8]
 *   @0x138454 str r8, [r6]
 *   @0x138458 bl 0xb6850 <fclose@plt>
 *   @0x13845c str r8, [r6, #0x8]
 *   @0x138460 b 0x1383e8 <_Z14F_FileOpenReadR6RValueP9CInstanceS2_iPS_+0x30>
 *   @0x138464 eoreq r9, r11, r0, lsl #17
 *   @0x138468 .word 0xffffd620
 *   @0x13846c .word 0xffffd624
 *   @0x138470 .word 0x00207bdc
 *
 * ══ §133/156 F_FileBinSize(RValue&, CInstance*, CInstance*, int, RValue*)  0x13953c  size 188  47 条（0x13953c..0x1395f8）
 * @func 0x13953c 0x1395f8  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LoadSave::ftell(_YYFILE*)×2 / YYGetInt32(RValue const*, int) / LoadSave::fseek(_YYFILE*, long, int)
 * 字段偏移 top8: 0x8×4 / 0x18×1 / 0x88×1 / 0x78×1 / 0xc×1 / 0x14×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13953c push {r3, r4, r5, r6, r7, lr}
 *   @0x139540 mov r1, #0
 *   @0x139544 mov r6, r0
 *   @0x139548 ldr r0, [sp, #0x18]
 *   @0x13954c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x139550 sub r3, r0, #1
 *   @0x139554 cmp r3, #30
 *   @0x139558 bhi 0x1395d8 <_Z13F_FileBinSizeR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x13955c ldr r3, [pc, #0x88]
 *   @0x139560 ldr r3, [pc, r3]
 *   @0x139564 ldrb r3, [r3, r0]
 *   @0x139568 cmp r3, #0
 *   @0x13956c beq 0x1395d8 <_Z13F_FileBinSizeR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x139570 ldr r3, [pc, #0x78]
 *   @0x139574 add r0, r0, r0, lsl #1
 *   @0x139578 mov r4, #0
 *   @0x13957c str r4, [r6, #0xc]
 *   @0x139580 ldr r3, [pc, r3]
 *   @0x139584 add r7, r3, r0, lsl #2
 *   @0x139588 ldr r0, [r7, #0x8]
 *   @0x13958c bl 0x18de24 <_ZN8LoadSave5ftellEP7_YYFILE>
 *   @0x139590 mov r1, r4
 *   @0x139594 mov r2, #2
 *   @0x139598 mov r5, r0
 *   @0x13959c ldr r0, [r7, #0x8]
 *   @0x1395a0 bl 0x18de30 <_ZN8LoadSave5fseekEP7_YYFILEli>
 *   @0x1395a4 ldr r0, [r7, #0x8]
 *   @0x1395a8 bl 0x18de24 <_ZN8LoadSave5ftellEP7_YYFILE>
 *   @0x1395ac mov r1, r5
 *   @0x1395b0 mov r2, r4
 *   @0x1395b4 vmov s15, r0
 *   @0x1395b8 vcvt.f64.s32 d7, s15
 *   @0x1395bc vmov r4, r5, d7
 *   @0x1395c0 vmov r0, s14
 *   @0x1395c4 mov r3, r5
 *   @0x1395c8 stm r6, {r0, r3}
 *   @0x1395cc ldr r0, [r7, #0x8]
 *   @0x1395d0 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1395d4 b 0x18de30 <_ZN8LoadSave5fseekEP7_YYFILEli>
 *   @0x1395d8 ldr r0, [pc, #0x14]
 *   @0x1395dc mov r1, #0
 *   @0x1395e0 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1395e4 add r0, pc, r0
 *   @0x1395e8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1395ec eoreq r5, r11, r12, lsr #26
 *   @0x1395f0 eoreq r5, r11, r0, lsl sp
 *   @0x1395f4 mlaeq r0, r12, r11, r6
 *
 * ══ §134/156 F_ActionIfObject(RValue&, CInstance*, CInstance*, int, RValue*)  0x13eec8  size 188  47 条（0x13eec8..0x13ef84）
 * @func 0x13eec8 0x13ef84  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / Command_IsMeeting(CInstance*, int, float, float)×2 / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x20×1 / 0x70×1 / 0xc×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13eec8 push {r3, r4, r5, r6, r7, lr}
 *   @0x13eecc vpush {d8}
 *   @0x13eed0 mov r5, r0
 *   @0x13eed4 ldr r4, [sp, #0x20]
 *   @0x13eed8 mov r6, r1
 *   @0x13eedc mov r1, #0
 *   @0x13eee0 mov r0, r4
 *   @0x13eee4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13eee8 mov r1, #1
 *   @0x13eeec mov r7, r0
 *   @0x13eef0 mov r0, r4
 *   @0x13eef4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13eef8 mov r1, #2
 *   @0x13eefc vmov s16, r0
 *   @0x13ef00 mov r0, r4
 *   @0x13ef04 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13ef08 ldr r3, [pc, #0x70]
 *   @0x13ef0c ldr r3, [pc, r3]
 *   @0x13ef10 ldrb r3, [r3]
 *   @0x13ef14 cmp r3, #0
 *   @0x13ef18 vmov s15, r0
 *   @0x13ef1c beq 0x13ef68 <_Z16F_ActionIfObjectR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x13ef20 vldr s13, [r6, #180]
 *   @0x13ef24 vldr s14, [r6, #184]
 *   @0x13ef28 vadd.f32 s13, s16, s13
 *   @0x13ef2c mov r1, r7
 *   @0x13ef30 mov r0, r6
 *   @0x13ef34 vadd.f32 s14, s15, s14
 *   @0x13ef38 vmov r2, s13
 *   @0x13ef3c vmov r3, s14
 *   @0x13ef40 bl 0x1ca9f8 <_Z17Command_IsMeetingP9CInstanceiff>
 *   @0x13ef44 cmp r0, #0
 *   @0x13ef48 mov r3, #0
 *   @0x13ef4c str r3, [r5, #0xc]
 *   @0x13ef50 movne r0, r3
 *   @0x13ef54 moveq r3, r0
 *   @0x13ef58 movtne r3, #0x3ff0
 *   @0x13ef5c stm r5, {r0, r3}
 *   @0x13ef60 vpop {d8}
 *   @0x13ef64 pop {r3, r4, r5, r6, r7, pc}
 *   @0x13ef68 mov r0, r6
 *   @0x13ef6c mov r1, r7
 *   @0x13ef70 vmov r2, s16
 *   @0x13ef74 vmov r3, s15
 *   @0x13ef78 bl 0x1ca9f8 <_Z17Command_IsMeetingP9CInstanceiff>
 *   @0x13ef7c b 0x13ef44 <_Z16F_ActionIfObjectR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x13ef80 eoreq lr, r10, r0, lsr r12
 *
 * ══ §135/156 F_PhysicsCreateWorld(RValue&, CInstance*, CInstance*, int, RValue*)  0x14eb70  size 188  47 条（0x14eb70..0x14ec2c）
 * @func 0x14eb70 0x14ec2c  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int) / CTimingSource::GetFPS() / operator new(unsigned int) / CPhysicsWorld::CPhysicsWorld(float, int)
 * 字段偏移 top8: 0xb4×3 / 0xa0×1 / 0x18×1 / 0x84×1 / 0x60×1 / 0x58×1 / 0x50×1 / 0x38×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14eb70 push {r3, r4, r5, r6, r7, lr}
 *   @0x14eb74 ldr r3, [pc, #0xa0]
 *   @0x14eb78 ldr r0, [sp, #0x18]
 *   @0x14eb7c ldr r3, [pc, r3]
 *   @0x14eb80 ldr r4, [r3]
 *   @0x14eb84 cmp r4, #0
 *   @0x14eb88 beq 0x14ebe8 <_Z20F_PhysicsCreateWorldR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x14eb8c mov r1, #0
 *   @0x14eb90 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14eb94 ldr r3, [pc, #0x84]
 *   @0x14eb98 ldr r3, [pc, r3]
 *   @0x14eb9c ldrb r3, [r3]
 *   @0x14eba0 cmp r3, #0
 *   @0x14eba4 ldreq r5, [r4, #0xc]
 *   @0x14eba8 mov r6, r0
 *   @0x14ebac bne 0x14ebcc <_Z20F_PhysicsCreateWorldR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x14ebb0 ldr r3, [r4, #0xb4]
 *   @0x14ebb4 cmp r3, #0
 *   @0x14ebb8 beq 0x14ebfc <_Z20F_PhysicsCreateWorldR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x14ebbc str r6, [r3, #0x60]
 *   @0x14ebc0 ldr r3, [r4, #0xb4]
 *   @0x14ebc4 str r5, [r3, #0x58]
 *   @0x14ebc8 pop {r3, r4, r5, r6, r7, pc}
 *   @0x14ebcc ldr r0, [pc, #0x50]
 *   @0x14ebd0 ldr r0, [pc, r0]
 *   @0x14ebd4 bl 0x214808 <_ZN13CTimingSource6GetFPSEv>
 *   @0x14ebd8 vmov d7, r0, r1
 *   @0x14ebdc vcvt.s32.f64 s15, d7
 *   @0x14ebe0 vmov r5, s15
 *   @0x14ebe4 b 0x14ebb0 <_Z20F_PhysicsCreateWorldR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x14ebe8 ldr r0, [pc, #0x38]
 *   @0x14ebec mov r1, r4
 *   @0x14ebf0 pop {r3, r4, r5, r6, r7, lr}
 *   @0x14ebf4 add r0, pc, r0
 *   @0x14ebf8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14ebfc mov r0, #488
 *   @0x14ec00 bl 0x27c524 <_Znwj>
 *   @0x14ec04 mov r1, r6
 *   @0x14ec08 mov r2, r5
 *   @0x14ec0c mov r7, r0
 *   @0x14ec10 bl 0x237ca0 <_ZN13CPhysicsWorldC2Efi>
 *   @0x14ec14 str r7, [r4, #0xb4]
 *   @0x14ec18 pop {r3, r4, r5, r6, r7, pc}
 *   @0x14ec1c eoreq lr, r9, r12, lsr #27
 *   @0x14ec20 eoreq lr, r9, r12, lsl #27
 *   @0x14ec24 eoreq lr, r9, r12, asr sp
 *   @0x14ec28 andseq r5, pc, r8, lsl r3
 *
 * ══ §136/156 F_YoYo_CloudStringSave(RValue&, CInstance*, CInstance*, int, RValue*)  0x159038  size 188  47 条（0x159038..0x1590f4）
 * @func 0x159038 0x1590f4  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)×2 / Cloud_String_Save(char const*, char const*, int (*)(HTTP_REQ_CONTEXT*, void*, int*))
 * 字段偏移 top8: 0xc×2 / 0x18×1 / 0x4×1 / 0x1c×1 / 0x68×1 / 0x44×1 / 0x20×1 / 0x14×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x159038 cmp r3, #2
 *   @0x15903c mov r1, #0
 *   @0x159040 push {r3, r4, r5, r6, r7, lr}
 *   @0x159044 mov r4, r0
 *   @0x159048 ldr r5, [sp, #0x18]
 *   @0x15904c str r1, [r0, #0xc]
 *   @0x159050 str r1, [r0]
 *   @0x159054 str r1, [r0, #0x4]
 *   @0x159058 bne 0x1590d4 <_Z22F_YoYo_CloudStringSaveR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x15905c ldr r3, [r5, #0xc]
 *   @0x159060 cmp r3, #1
 *   @0x159064 beq 0x159074 <_Z22F_YoYo_CloudStringSaveR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x159068 ldr r3, [r5, #0x1c]
 *   @0x15906c cmp r3, #1
 *   @0x159070 bne 0x1590c4 <_Z22F_YoYo_CloudStringSaveR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x159074 ldr r3, [pc, #0x68]
 *   @0x159078 mov r1, #0
 *   @0x15907c mov r0, r5
 *   @0x159080 ldr r3, [pc, r3]
 *   @0x159084 ldr r7, [r3]
 *   @0x159088 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x15908c mov r1, #1
 *   @0x159090 mov r6, r0
 *   @0x159094 mov r0, r5
 *   @0x159098 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x15909c ldr r3, [pc, #0x44]
 *   @0x1590a0 ldr r2, [pc, r3]
 *   @0x1590a4 mov r1, r0
 *   @0x1590a8 mov r0, r6
 *   @0x1590ac bl 0x1612b0 <_Z17Cloud_String_SavePKcS0_PFiP16HTTP_REQ_CONTEXTPvPiE>
 *   @0x1590b0 vmov s15, r7
 *   @0x1590b4 vcvt.f64.s32 d7, s15
 *   @0x1590b8 vmov r2, r3, d7
 *   @0x1590bc stm r4, {r2, r3}
 *   @0x1590c0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1590c4 ldr r0, [pc, #0x20]
 *   @0x1590c8 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1590cc add r0, pc, r0
 *   @0x1590d0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1590d4 ldr r0, [pc, #0x14]
 *   @0x1590d8 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1590dc add r0, pc, r0
 *   @0x1590e0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1590e4 .word 0x002961f8
 *   @0x1590e8 .word 0x00296ab8
 *   @0x1590ec andseq r9, lr, r0, ror #17
 *   @0x1590f0 andseq sp, lr, r12, ror #9
 *
 * ══ §137/156 CBitmap32::CBitmap32(int, int, unsigned int)  0x166140  size 188  47 条（0x166140..0x1661fc）
 * @func 0x166140 0x1661fc  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool) / CBitmap32::CBitmap32(int, int, unsigned int)+0xac
 * 字段偏移 top8: 0x8×3 / 0xc×3 / 0x10×2 / 0x14×2 / 0x4×2 / 0x90×1 / 0x88×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x166140 cmp r1, #1
 *   @0x166144 movlt r1, #1
 *   @0x166148 cmp r2, #1
 *   @0x16614c movlt r2, #1
 *   @0x166150 push {r4, r5, r6, lr}
 *   @0x166154 mov r4, r0
 *   @0x166158 mul r0, r2, r1
 *   @0x16615c ldr r12, [pc, #0x90]
 *   @0x166160 str r1, [r4, #0x8]
 *   @0x166164 mov lr, #1
 *   @0x166168 ldr r1, [pc, #0x88]
 *   @0x16616c ldr r12, [pc, r12]
 *   @0x166170 mov r5, #0
 *   @0x166174 str r2, [r4, #0xc]
 *   @0x166178 mov r6, r3
 *   @0x16617c add r12, r12, #8
 *   @0x166180 mov r3, lr
 *   @0x166184 movw r2, #0x105
 *   @0x166188 add r1, pc, r1
 *   @0x16618c str r12, [r4]
 *   @0x166190 lsl r0, r0, #2
 *   @0x166194 str r5, [r4, #0x10]
 *   @0x166198 str r5, [r4, #0x14]
 *   @0x16619c strb lr, [r4, #0x4]
 *   @0x1661a0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1661a4 ldr r2, [r4, #0x8]
 *   @0x1661a8 ldr r1, [r4, #0xc]
 *   @0x1661ac orr r3, r6, #-16777216
 *   @0x1661b0 mul r2, r1, r2
 *   @0x1661b4 cmp r2, r5
 *   @0x1661b8 lsl r2, r2, #2
 *   @0x1661bc str r2, [r4, #0x10]
 *   @0x1661c0 str r0, [r4, #0x14]
 *   @0x1661c4 ble 0x1661ec <_ZN9CBitmap32C2Eiij+0xac>
 *   @0x1661c8 sub r0, r0, #4
 *   @0x1661cc mov r2, r5
 *   @0x1661d0 str r3, [r0, #0x4]!
 *   @0x1661d4 add r2, r2, #1
 *   @0x1661d8 ldr r1, [r4, #0xc]
 *   @0x1661dc ldr r12, [r4, #0x8]
 *   @0x1661e0 mul r1, r12, r1
 *   @0x1661e4 cmp r1, r2
 *   @0x1661e8 bgt 0x1661d0 <_ZN9CBitmap32C2Eiij+0x90>
 *   @0x1661ec mov r0, r4
 *   @0x1661f0 pop {r4, r5, r6, pc}
 *   @0x1661f4 eoreq r9, r8, r12, lsl #31
 *   @0x1661f8 andseq r4, lr, r8, lsr r4
 *
 * ══ §138/156 GR_3D_Vertex_N(float, float, float, float, float, float)  0x177214  size 188  47 条（0x177214..0x1772d0）
 * @func 0x177214 0x1772d0  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3D_Vertex_N(float, float, float, float, float, float)+0x50 / HandleOverflow()
 * 字段偏移 top8: 0x90×1 / 0x8c×1 / 0x88×1 / 0x5c×1 / 0x58×1 / 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x177214 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x177218 vpush {d8}
 *   @0x17721c mov r8, r0
 *   @0x177220 vldr s17, [sp, #48]
 *   @0x177224 ldr r4, [pc, #0x90]
 *   @0x177228 mov r9, r1
 *   @0x17722c ldr r0, [pc, #0x8c]
 *   @0x177230 mov r11, r3
 *   @0x177234 ldr r1, [pc, #0x88]
 *   @0x177238 add r4, pc, r4
 *   @0x17723c mov r10, r2
 *   @0x177240 vldr s16, [sp, #52]
 *   @0x177244 ldr r6, [r4, r0]
 *   @0x177248 ldr r3, [r4, r1]
 *   @0x17724c ldr r5, [r6]
 *   @0x177250 ldr r3, [r3]
 *   @0x177254 cmp r5, r3
 *   @0x177258 blt 0x177264 <_Z14GR_3D_Vertex_Nffffff+0x50>
 *   @0x17725c bl 0x176bb0 <_Z14HandleOverflowv>
 *   @0x177260 ldr r5, [r6]
 *   @0x177264 ldr r2, [pc, #0x5c]
 *   @0x177268 add r12, r5, r5, lsl #3
 *   @0x17726c ldr r3, [pc, #0x58]
 *   @0x177270 mov r7, #0
 *   @0x177274 add r5, r5, #1
 *   @0x177278 ldr r2, [r4, r2]
 *   @0x17727c add r12, r2, r12, lsl #2
 *   @0x177280 vstr s17, [r12, #16]
 *   @0x177284 vstr s16, [r12, #20]
 *   @0x177288 str r8, [r12]
 *   @0x17728c str r9, [r12, #0x4]
 *   @0x177290 str r10, [r12, #0x8]
 *   @0x177294 str r11, [r12, #0xc]
 *   @0x177298 ldr r3, [r4, r3]
 *   @0x17729c str r7, [r12, #0x1c]
 *   @0x1772a0 str r7, [r12, #0x20]
 *   @0x1772a4 vpop {d8}
 *   @0x1772a8 ldr r3, [r3]
 *   @0x1772ac str r5, [r6]
 *   @0x1772b0 bic r3, r3, #1
 *   @0x1772b4 str r3, [r12, #0x18]
 *   @0x1772b8 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1772bc eoreq r10, r7, r8, lsl r10
 *   @0x1772c0 .word 0xffffe670
 *   @0x1772c4 .word 0xffffe67c
 *   @0x1772c8 .word 0xffffe680
 *   @0x1772cc .word 0xffffc0ac
 *
 * ══ §139/156 GR_3D_Vertex_N_Color(float, float, float, float, float, float, unsigned int, float)  0x1772d0  size 188  47 条（0x1772d0..0x17738c）
 * @func 0x1772d0 0x17738c  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3D_Vertex_N_Color(float, float, float, float, float, float, unsigned int, float)+0x4c / HandleOverflow() / ConvertAlpha(float) / GR_Color_To_D3DColor(unsigned int, unsigned int)
 * 字段偏移 top8: 0x98×1 / 0x94×1 / 0x34×1 / 0x38×1 / 0x3c×1 / 0x58×1 / 0x4×1 / 0x8×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1772d0 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1772d4 vpush {d8}
 *   @0x1772d8 mov r7, r2
 *   @0x1772dc vldr s16, [sp, #48]
 *   @0x1772e0 ldr r5, [pc, #0x98]
 *   @0x1772e4 mov r6, r3
 *   @0x1772e8 ldr r12, [pc, #0x94]
 *   @0x1772ec mov r9, r0
 *   @0x1772f0 ldr r5, [pc, r5]
 *   @0x1772f4 mov r8, r1
 *   @0x1772f8 ldr r12, [pc, r12]
 *   @0x1772fc ldr r11, [sp, #0x34]
 *   @0x177300 ldr r2, [r5]
 *   @0x177304 ldr r3, [r12]
 *   @0x177308 ldr r10, [sp, #0x38]
 *   @0x17730c cmp r2, r3
 *   @0x177310 ldr r4, [sp, #0x3c]
 *   @0x177314 blt 0x17731c <_Z20GR_3D_Vertex_N_Colorffffffjf+0x4c>
 *   @0x177318 bl 0x176bb0 <_Z14HandleOverflowv>
 *   @0x17731c mov r0, r4
 *   @0x177320 bl 0x16ca2c <_Z12ConvertAlphaf>
 *   @0x177324 ldr r4, [r5]
 *   @0x177328 ldr r12, [pc, #0x58]
 *   @0x17732c add r4, r4, r4, lsl #3
 *   @0x177330 ldr r12, [pc, r12]
 *   @0x177334 add r4, r12, r4, lsl #2
 *   @0x177338 vstr s16, [r4, #16]
 *   @0x17733c str r9, [r4]
 *   @0x177340 str r8, [r4, #0x4]
 *   @0x177344 str r7, [r4, #0x8]
 *   @0x177348 str r6, [r4, #0xc]
 *   @0x17734c str r11, [r4, #0x14]
 *   @0x177350 mov r1, r0
 *   @0x177354 orr r0, r10, #1
 *   @0x177358 bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj>
 *   @0x17735c mov r3, #0
 *   @0x177360 str r3, [r4, #0x20]
 *   @0x177364 str r3, [r4, #0x1c]
 *   @0x177368 vpop {d8}
 *   @0x17736c ldr r2, [r5]
 *   @0x177370 add r3, r2, #1
 *   @0x177374 str r3, [r5]
 *   @0x177378 str r0, [r4, #0x18]
 *   @0x17737c pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x177380 .word 0x00278fd0
 *   @0x177384 .word 0x00278fd4
 *   @0x177388 eoreq r8, r7, r0, lsr #31
 *
 * ══ §140/156 IO_Button_Clear_All(int)  0x18c20c  size 188  47 条（0x18c20c..0x18c2c8）
 * @func 0x18c20c 0x18c2c8  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x18c220→0x534b78, 0x18c228→0x534b50, 0x18c230→0x534b30, 0x18c238→0x534af0, 0x18c23c→0x534b10, 0x18c248→0x534ae4, 0x18c24c→0x534ad8
 * 调用序列: 无
 * 字段偏移 top8: 0x2×5 / 0x1×3 / 0x78×2 / 0x70×2 / 0x90×1 / 0x84×1 / 0x80×1 / 0x7c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18c20c cmp r0, #9
 *   @0x18c210 ldr r2, [pc, #0x90]
 *   @0x18c214 push {r4, r5, r6, r7, r8}
 *   @0x18c218 add r2, pc, r2
 *   @0x18c21c bhi 0x18c2a0 <_Z19IO_Button_Clear_Alli+0x94>
 *   @0x18c220 ldr r5, [pc, #0x84]
 *   @0x18c224 mov r3, #0
 *   @0x18c228 ldr r4, [pc, #0x80]
 *   @0x18c22c add r1, r0, r0, lsl #1
 *   @0x18c230 ldr r12, [pc, #0x7c]
 *   @0x18c234 ldr r7, [r2, r5]
 *   @0x18c238 ldr r6, [pc, #0x78]
 *   @0x18c23c ldr r5, [pc, #0x78]
 *   @0x18c240 str r3, [r7, r0, lsl #2]
 *   @0x18c244 ldr r4, [r2, r4]
 *   @0x18c248 ldr r8, [pc, #0x70]
 *   @0x18c24c ldr r7, [pc, #0x70]
 *   @0x18c250 str r3, [r4, r0, lsl #2]
 *   @0x18c254 ldr r4, [r2, r12]
 *   @0x18c258 add r12, r4, r1
 *   @0x18c25c strb r3, [r4, r1]
 *   @0x18c260 ldr r4, [r2, r6]
 *   @0x18c264 add r6, r4, r1
 *   @0x18c268 strb r3, [r4, r1]
 *   @0x18c26c ldr r5, [r2, r5]
 *   @0x18c270 strb r3, [r6, #0x1]
 *   @0x18c274 add r4, r5, r1
 *   @0x18c278 strb r3, [r6, #0x2]
 *   @0x18c27c strb r3, [r5, r1]
 *   @0x18c280 strb r3, [r12, #0x1]
 *   @0x18c284 strb r3, [r4, #0x1]
 *   @0x18c288 strb r3, [r4, #0x2]
 *   @0x18c28c strb r3, [r12, #0x2]
 *   @0x18c290 ldr r1, [r2, r8]
 *   @0x18c294 strb r3, [r1, r0]
 *   @0x18c298 ldr r2, [r2, r7]
 *   @0x18c29c strb r3, [r2, r0]
 *   @0x18c2a0 pop {r4, r5, r6, r7, r8}
 *   @0x18c2a4 bx lr
 *   @0x18c2a8 eoreq r5, r6, r8, lsr r10
 *   @0x18c2ac .word 0xffffe99c
 *   @0x18c2b0 .word 0xffffe9a0
 *   @0x18c2b4 .word 0xffffe9a4
 *   @0x18c2b8 .word 0xffffe9ac
 *   @0x18c2bc .word 0xffffe9a8
 *   @0x18c2c0 .word 0xffffe9b0
 *   @0x18c2c4 .word 0xffffe9b4
 *
 * ══ §141/156 LoadSave::_GetBundleFileName(char*, int, char const*)  0x18f78c  size 188  47 条（0x18f78c..0x18f848）
 * @func 0x18f78c 0x18f848  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65a4×2 / GetFilePrePend() / 0xb65e0 / 0xb6628
 * 字段偏移 top8: 0x6×1 / 0x1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18f78c push {r4, r5, r6, lr}
 *   @0x18f790 subs r5, r2, #0
 *   @0x18f794 mov r4, r0
 *   @0x18f798 strbeq r5, [r0]
 *   @0x18f79c beq 0x18f800 <_ZN8LoadSave18_GetBundleFileNameEPciPKc+0x74>
 *   @0x18f7a0 ldrb r3, [r5]
 *   @0x18f7a4 cmp r3, #47
 *   @0x18f7a8 cmpne r3, #92
 *   @0x18f7ac beq 0x18f83c <_ZN8LoadSave18_GetBundleFileNameEPciPKc+0xb0>
 *   @0x18f7b0 bl 0x28fd5c <_Z14GetFilePrePendv>
 *   @0x18f7b4 mov r3, #0
 *   @0x18f7b8 mov r2, #6
 *   @0x18f7bc strb r3, [r4]
 *   @0x18f7c0 mov r1, r0
 *   @0x18f7c4 mov r6, r0
 *   @0x18f7c8 mov r0, r5
 *   @0x18f7cc bl 0xb65e0 <strncmp@plt>
 *   @0x18f7d0 cmp r0, #0
 *   @0x18f7d4 bne 0x18f7e8 <_ZN8LoadSave18_GetBundleFileNameEPciPKc+0x5c>
 *   @0x18f7d8 ldrb r3, [r5, #0x6]
 *   @0x18f7dc cmp r3, #47
 *   @0x18f7e0 cmpne r3, #92
 *   @0x18f7e4 beq 0x18f7f4 <_ZN8LoadSave18_GetBundleFileNameEPciPKc+0x68>
 *   @0x18f7e8 mov r1, r6
 *   @0x18f7ec mov r0, r4
 *   @0x18f7f0 bl 0xb65a4 <strcpy@plt>
 *   @0x18f7f4 mov r1, r5
 *   @0x18f7f8 mov r0, r4
 *   @0x18f7fc bl 0xb6628 <strcat@plt>
 *   @0x18f800 ldrb r3, [r4]
 *   @0x18f804 cmp r3, #0
 *   @0x18f808 popeq {r4, r5, r6, pc}
 *   @0x18f80c add r0, r4, #1
 *   @0x18f810 mov r1, #95
 *   @0x18f814 mov r2, #47
 *   @0x18f818 cmp r3, #92
 *   @0x18f81c strbeq r2, [r0, #-0x1]
 *   @0x18f820 beq 0x18f82c <_ZN8LoadSave18_GetBundleFileNameEPciPKc+0xa0>
 *   @0x18f824 cmp r3, #32
 *   @0x18f828 strbeq r1, [r0, #-0x1]
 *   @0x18f82c ldrb r3, [r0], #1
 *   @0x18f830 cmp r3, #0
 *   @0x18f834 bne 0x18f818 <_ZN8LoadSave18_GetBundleFileNameEPciPKc+0x8c>
 *   @0x18f838 pop {r4, r5, r6, pc}
 *   @0x18f83c mov r1, r5
 *   @0x18f840 bl 0xb65a4 <strcpy@plt>
 *   @0x18f844 b 0x18f800 <_ZN8LoadSave18_GetBundleFileNameEPciPKc+0x74>
 *
 * ══ §142/156 DiffDir(float, float)  0x19c7ec  size 188  47 条（0x19c7ec..0x19c8a8）
 * @func 0x19c7ec 0x19c8a8  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DiffDir(float, float)+0x18 / DiffDir(float, float)+0x48 / DiffDir(float, float)+0x88
 * 字段偏移 top8: 无
 * VFP 指令 36 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19c7ec vmov s15, r0
 *   @0x19c7f0 vmov s14, r1
 *   @0x19c7f4 vcmpe.f32 s15, #0
 *   @0x19c7f8 vmrs APSR_nzcv, fpscr
 *   @0x19c7fc bhi 0x19c814 <_Z7DiffDirff+0x28>
 *   @0x19c800 vldr s13, [pc, #152]
 *   @0x19c804 vadd.f32 s15, s15, s13
 *   @0x19c808 vcmpe.f32 s15, #0
 *   @0x19c80c vmrs APSR_nzcv, fpscr
 *   @0x19c810 bls 0x19c804 <_Z7DiffDirff+0x18>
 *   @0x19c814 vldr s13, [pc, #132]
 *   @0x19c818 vcmpe.f32 s15, s13
 *   @0x19c81c vmrs APSR_nzcv, fpscr
 *   @0x19c820 blt 0x19c834 <_Z7DiffDirff+0x48>
 *   @0x19c824 vsub.f32 s15, s15, s13
 *   @0x19c828 vcmpe.f32 s15, s13
 *   @0x19c82c vmrs APSR_nzcv, fpscr
 *   @0x19c830 bge 0x19c824 <_Z7DiffDirff+0x38>
 *   @0x19c834 vcmpe.f32 s14, #0
 *   @0x19c838 vmrs APSR_nzcv, fpscr
 *   @0x19c83c bpl 0x19c854 <_Z7DiffDirff+0x68>
 *   @0x19c840 vldr s13, [pc, #88]
 *   @0x19c844 vadd.f32 s14, s14, s13
 *   @0x19c848 vcmpe.f32 s14, #0
 *   @0x19c84c vmrs APSR_nzcv, fpscr
 *   @0x19c850 bmi 0x19c844 <_Z7DiffDirff+0x58>
 *   @0x19c854 vldr s13, [pc, #68]
 *   @0x19c858 vcmpe.f32 s14, s13
 *   @0x19c85c vmrs APSR_nzcv, fpscr
 *   @0x19c860 blt 0x19c874 <_Z7DiffDirff+0x88>
 *   @0x19c864 vsub.f32 s14, s14, s13
 *   @0x19c868 vcmpe.f32 s14, s13
 *   @0x19c86c vmrs APSR_nzcv, fpscr
 *   @0x19c870 bge 0x19c864 <_Z7DiffDirff+0x78>
 *   @0x19c874 vsub.f32 s15, s14, s15
 *   @0x19c878 vldr s14, [pc, #36]
 *   @0x19c87c vcmpe.f32 s15, #0
 *   @0x19c880 vmrs APSR_nzcv, fpscr
 *   @0x19c884 vnegmi.f32 s15, s15
 *   @0x19c888 vcmpe.f32 s15, s14
 *   @0x19c88c vmrs APSR_nzcv, fpscr
 *   @0x19c890 vldrgt s14, [pc, #8]
 *   @0x19c894 vsubgt.f32 s15, s14, s15
 *   @0x19c898 vmov r0, s15
 *   @0x19c89c bx lr
 *   @0x19c8a0 .word 0x43b40000
 *   @0x19c8a4 teqmi r4, #0
 *
 * ══ §143/156 F_TilemapGetTileWidth(RValue&, CInstance*, CInstance*, int, RValue*)  0x1be34c  size 188  47 条（0x1be34c..0x1be408）
 * @func 0x1be34c 0x1be408  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / Background_Data(int)
 * 字段偏移 top8: 0xc×2 / 0x1c×2 / 0x4×1 / 0x18×1 / 0x80×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1be34c cmp r3, #1
 *   @0x1be350 push {r3, r4, r5, r6, r7, lr}
 *   @0x1be354 mov r3, #0
 *   @0x1be358 mov r4, r3
 *   @0x1be35c mov r5, r0
 *   @0x1be360 movt r3, #0xbff0
 *   @0x1be364 str r4, [r0, #0xc]
 *   @0x1be368 str r3, [r0, #0x4]
 *   @0x1be36c str r4, [r0]
 *   @0x1be370 ldr r6, [sp, #0x18]
 *   @0x1be374 beq 0x1be38c <_Z21F_TilemapGetTileWidthR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1be378 ldr r0, [pc, #0x80]
 *   @0x1be37c mov r1, r4
 *   @0x1be380 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1be384 add r0, pc, r0
 *   @0x1be388 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1be38c bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1be390 mov r1, r4
 *   @0x1be394 mov r7, r0
 *   @0x1be398 mov r0, r6
 *   @0x1be39c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1be3a0 mov r2, r4
 *   @0x1be3a4 mov r1, r0
 *   @0x1be3a8 mov r0, r7
 *   @0x1be3ac bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1be3b0 cmp r0, #0
 *   @0x1be3b4 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1be3b8 ldr r3, [r0]
 *   @0x1be3bc cmp r3, #5
 *   @0x1be3c0 popne {r3, r4, r5, r6, r7, pc}
 *   @0x1be3c4 ldr r0, [r0, #0x1c]
 *   @0x1be3c8 bl 0xc3794 <_Z15Background_Datai>
 *   @0x1be3cc cmp r0, #0
 *   @0x1be3d0 beq 0x1be3ec <_Z21F_TilemapGetTileWidthR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x1be3d4 ldr r2, [r0, #0x1c]
 *   @0x1be3d8 vmov s15, r2
 *   @0x1be3dc vcvt.f64.s32 d7, s15
 *   @0x1be3e0 vmov r2, r3, d7
 *   @0x1be3e4 stm r5, {r2, r3}
 *   @0x1be3e8 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1be3ec mov r1, r0
 *   @0x1be3f0 ldr r0, [pc, #0xc]
 *   @0x1be3f4 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1be3f8 add r0, pc, r0
 *   @0x1be3fc b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1be400 mulseq r9, r8, r6
 *   @0x1be404 andseq r0, r9, r12, asr r6
 *
 * ══ §144/156 F_TilemapGetTileHeight(RValue&, CInstance*, CInstance*, int, RValue*)  0x1be408  size 188  47 条（0x1be408..0x1be4c4）
 * @func 0x1be408 0x1be4c4  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / Background_Data(int)
 * 字段偏移 top8: 0xc×2 / 0x4×1 / 0x18×1 / 0x80×1 / 0x1c×1 / 0x20×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1be408 cmp r3, #1
 *   @0x1be40c push {r3, r4, r5, r6, r7, lr}
 *   @0x1be410 mov r3, #0
 *   @0x1be414 mov r4, r3
 *   @0x1be418 mov r5, r0
 *   @0x1be41c movt r3, #0xbff0
 *   @0x1be420 str r4, [r0, #0xc]
 *   @0x1be424 str r3, [r0, #0x4]
 *   @0x1be428 str r4, [r0]
 *   @0x1be42c ldr r6, [sp, #0x18]
 *   @0x1be430 beq 0x1be448 <_Z22F_TilemapGetTileHeightR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1be434 ldr r0, [pc, #0x80]
 *   @0x1be438 mov r1, r4
 *   @0x1be43c pop {r3, r4, r5, r6, r7, lr}
 *   @0x1be440 add r0, pc, r0
 *   @0x1be444 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1be448 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1be44c mov r1, r4
 *   @0x1be450 mov r7, r0
 *   @0x1be454 mov r0, r6
 *   @0x1be458 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1be45c mov r2, r4
 *   @0x1be460 mov r1, r0
 *   @0x1be464 mov r0, r7
 *   @0x1be468 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1be46c cmp r0, #0
 *   @0x1be470 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1be474 ldr r3, [r0]
 *   @0x1be478 cmp r3, #5
 *   @0x1be47c popne {r3, r4, r5, r6, r7, pc}
 *   @0x1be480 ldr r0, [r0, #0x1c]
 *   @0x1be484 bl 0xc3794 <_Z15Background_Datai>
 *   @0x1be488 cmp r0, #0
 *   @0x1be48c beq 0x1be4a8 <_Z22F_TilemapGetTileHeightR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x1be490 ldr r2, [r0, #0x20]
 *   @0x1be494 vmov s15, r2
 *   @0x1be498 vcvt.f64.s32 d7, s15
 *   @0x1be49c vmov r2, r3, d7
 *   @0x1be4a0 stm r5, {r2, r3}
 *   @0x1be4a4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1be4a8 mov r1, r0
 *   @0x1be4ac ldr r0, [pc, #0xc]
 *   @0x1be4b0 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1be4b4 add r0, pc, r0
 *   @0x1be4b8 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1be4bc andseq r0, r9, r4, asr r6
 *   @0x1be4c0 andseq r0, r9, r8, lsl r6
 *
 * ══ §145/156 F_TilemapGetFrame(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bf220  size 188  47 条（0x1bf220..0x1bf2dc）
 * @func 0x1bf220 0x1bf2dc  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0xc×2 / 0x34×2 / 0x4×1 / 0x18×1 / 0x7c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bf220 cmp r3, #1
 *   @0x1bf224 push {r3, r4, r5, r6, r7, lr}
 *   @0x1bf228 mov r3, #0
 *   @0x1bf22c mov r4, r3
 *   @0x1bf230 mov r5, r0
 *   @0x1bf234 movt r3, #0xbff0
 *   @0x1bf238 str r4, [r0, #0xc]
 *   @0x1bf23c str r3, [r0, #0x4]
 *   @0x1bf240 str r4, [r0]
 *   @0x1bf244 ldr r6, [sp, #0x18]
 *   @0x1bf248 beq 0x1bf260 <_Z17F_TilemapGetFrameR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bf24c ldr r0, [pc, #0x7c]
 *   @0x1bf250 mov r1, r4
 *   @0x1bf254 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bf258 add r0, pc, r0
 *   @0x1bf25c b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bf260 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bf264 mov r1, r4
 *   @0x1bf268 mov r7, r0
 *   @0x1bf26c mov r0, r6
 *   @0x1bf270 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bf274 mov r2, r4
 *   @0x1bf278 mov r1, r0
 *   @0x1bf27c mov r0, r7
 *   @0x1bf280 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bf284 cmp r0, #0
 *   @0x1bf288 beq 0x1bf298 <_Z17F_TilemapGetFrameR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x1bf28c ldr r3, [r0]
 *   @0x1bf290 cmp r3, #5
 *   @0x1bf294 beq 0x1bf2bc <_Z17F_TilemapGetFrameR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x1bf298 ldr r3, [pc, #0x34]
 *   @0x1bf29c ldr r1, [pc, #0x34]
 *   @0x1bf2a0 ldr r3, [pc, r3]
 *   @0x1bf2a4 add r1, pc, r1
 *   @0x1bf2a8 ldr r0, [r3]
 *   @0x1bf2ac ldr r3, [r0]
 *   @0x1bf2b0 ldr r3, [r3, #0xc]
 *   @0x1bf2b4 blx r3
 *   @0x1bf2b8 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bf2bc vldr s15, [r0, #48]
 *   @0x1bf2c0 vcvt.f64.f32 d6, s15
 *   @0x1bf2c4 vmov r2, r3, d6
 *   @0x1bf2c8 stm r5, {r2, r3}
 *   @0x1bf2cc pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bf2d0 andseq pc, r8, r12, asr lr
 *   @0x1bf2d4 eoreq lr, r2, r4, ror r4
 *   @0x1bf2d8 andseq pc, r8, r0, asr #28
 *
 * ══ §146/156 F_LayerTileRegion(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bfe08  size 188  47 条（0x1bfe08..0x1bfec4）
 * @func 0x1bfe08 0x1bfec4  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×5 / CLayerManager::GetTargetRoomObj() / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x4×1 / 0x88×1 / 0x48×1 / 0x4c×1 / 0x2c×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bfe08 cmp r3, #5
 *   @0x1bfe0c mov r3, #0
 *   @0x1bfe10 push {r4, r5, r6, lr}
 *   @0x1bfe14 mov r4, r3
 *   @0x1bfe18 ldr r5, [sp, #0x10]
 *   @0x1bfe1c movt r3, #0xbff0
 *   @0x1bfe20 str r4, [r0, #0xc]
 *   @0x1bfe24 str r3, [r0, #0x4]
 *   @0x1bfe28 str r4, [r0]
 *   @0x1bfe2c beq 0x1bfe44 <_Z17F_LayerTileRegionR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bfe30 ldr r0, [pc, #0x88]
 *   @0x1bfe34 mov r1, r4
 *   @0x1bfe38 pop {r4, r5, r6, lr}
 *   @0x1bfe3c add r0, pc, r0
 *   @0x1bfe40 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bfe44 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bfe48 mov r1, r4
 *   @0x1bfe4c mov r6, r0
 *   @0x1bfe50 mov r0, r5
 *   @0x1bfe54 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bfe58 mov r2, r4
 *   @0x1bfe5c mov r1, r0
 *   @0x1bfe60 mov r0, r6
 *   @0x1bfe64 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bfe68 subs r4, r0, #0
 *   @0x1bfe6c popeq {r4, r5, r6, pc}
 *   @0x1bfe70 ldr r3, [r4]
 *   @0x1bfe74 cmp r3, #7
 *   @0x1bfe78 popne {r4, r5, r6, pc}
 *   @0x1bfe7c mov r1, #1
 *   @0x1bfe80 mov r0, r5
 *   @0x1bfe84 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bfe88 mov r1, #2
 *   @0x1bfe8c str r0, [r4, #0x48]
 *   @0x1bfe90 mov r0, r5
 *   @0x1bfe94 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bfe98 mov r1, #3
 *   @0x1bfe9c str r0, [r4, #0x4c]
 *   @0x1bfea0 mov r0, r5
 *   @0x1bfea4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bfea8 mov r1, #4
 *   @0x1bfeac str r0, [r4, #0x2c]
 *   @0x1bfeb0 mov r0, r5
 *   @0x1bfeb4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bfeb8 str r0, [r4, #0x30]
 *   @0x1bfebc pop {r4, r5, r6, pc}
 *   @0x1bfec0 ldrheq pc, [r8], -r0
 *
 * ══ §147/156 CStream::LoadFromFile(char const*, int)  0x201358  size 188  47 条（0x201358..0x201414）
 * @func 0x201358 0x201414  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::Clear() / LoadSave::SaveFileExists(char const*) / LoadSave::ReadSaveFile(char const*, int*) / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65bc / MemoryManager::Free(void const*) / LoadSave::BundleFileExists(char const*) / LoadSave::ReadBundleFile(char const*, int*)
 * 字段偏移 top8: 0x18×2 / 0x4×1 / 0x5c×1 / 0xc×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x201358 ldr r3, [r0, #0x18]
 *   @0x20135c push {r4, r5, r6, r7, lr}
 *   @0x201360 cmp r3, #0
 *   @0x201364 sub sp, sp, #12
 *   @0x201368 mov r4, r0
 *   @0x20136c mov r5, r1
 *   @0x201370 mov r6, r2
 *   @0x201374 beq 0x20137c <_ZN7CStream12LoadFromFileEPKci+0x24>
 *   @0x201378 bl 0x2012f0 <_ZN7CStream5ClearEv>
 *   @0x20137c mov r0, r5
 *   @0x201380 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0x201384 cmp r0, #0
 *   @0x201388 mov r0, r5
 *   @0x20138c beq 0x2013f0 <_ZN7CStream12LoadFromFileEPKci+0x98>
 *   @0x201390 add r1, sp, #4
 *   @0x201394 bl 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi>
 *   @0x201398 mov r5, r0
 *   @0x20139c cmp r5, #0
 *   @0x2013a0 beq 0x2013e8 <_ZN7CStream12LoadFromFileEPKci+0x90>
 *   @0x2013a4 ldr r7, [sp, #0x4]
 *   @0x2013a8 mov r3, #0
 *   @0x2013ac ldr r1, [pc, #0x5c]
 *   @0x2013b0 mov r2, #272
 *   @0x2013b4 rsb r7, r6, r7
 *   @0x2013b8 str r3, [r4, #0xc]
 *   @0x2013bc add r1, pc, r1
 *   @0x2013c0 mov r3, #1
 *   @0x2013c4 str r7, [r4, #0x8]
 *   @0x2013c8 mov r0, r7
 *   @0x2013cc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x2013d0 mov r2, r7
 *   @0x2013d4 add r1, r5, r6
 *   @0x2013d8 str r0, [r4, #0x18]
 *   @0x2013dc bl 0xb65bc <memcpy@plt>
 *   @0x2013e0 mov r0, r5
 *   @0x2013e4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2013e8 add sp, sp, #12
 *   @0x2013ec pop {r4, r5, r6, r7, pc}
 *   @0x2013f0 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0x2013f4 cmp r0, #0
 *   @0x2013f8 beq 0x2013e8 <_ZN7CStream12LoadFromFileEPKci+0x90>
 *   @0x2013fc mov r0, r5
 *   @0x201400 add r1, sp, #4
 *   @0x201404 bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi>
 *   @0x201408 mov r5, r0
 *   @0x20140c b 0x20139c <_ZN7CStream12LoadFromFileEPKci+0x44>
 *   @0x201410 andseq r2, r5, r12, ror #6
 *
 * ══ §148/156 CStream::ConvertToString(char const*&)  0x2024b0  size 188  47 条（0x2024b0..0x20256c）
 * @func 0x2024b0 0x20256c  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IntToHex(int)×2 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / CStream::ConvertToString(char const*&)+0xa8 / CStream::ConvertToString(char const*&)+0x60
 * 字段偏移 top8: 0x-1×2 / 0x8c×1 / 0x18×1 / 0x-2×1 / 0x1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2024b0 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2024b4 mov r8, r1
 *   @0x2024b8 ldrd r2, r3, [r0, #16]
 *   @0x2024bc mov r1, #0
 *   @0x2024c0 str r1, [r8]
 *   @0x2024c4 mov r10, r0
 *   @0x2024c8 cmp r2, #1
 *   @0x2024cc sbcs r1, r3, #0
 *   @0x2024d0 poplt {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2024d4 ldr r1, [pc, #0x8c]
 *   @0x2024d8 lsl r0, r2, #1
 *   @0x2024dc mov r3, #1
 *   @0x2024e0 movw r2, #0x50c
 *   @0x2024e4 add r1, pc, r1
 *   @0x2024e8 add r0, r0, #1
 *   @0x2024ec bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x2024f0 ldrd r2, r3, [r10, #16]
 *   @0x2024f4 cmp r2, #1
 *   @0x2024f8 sbcs r1, r3, #0
 *   @0x2024fc mov r9, r0
 *   @0x202500 blt 0x202558 <_ZN7CStream15ConvertToStringERPKc+0xa8>
 *   @0x202504 mov r4, #1
 *   @0x202508 mov r5, #0
 *   @0x20250c mov r11, r0
 *   @0x202510 ldr r3, [r10, #0x18]
 *   @0x202514 mov r7, r5
 *   @0x202518 add r11, r11, #2
 *   @0x20251c add r3, r3, r4
 *   @0x202520 ldrb r6, [r3, #-0x1]
 *   @0x202524 lsr r0, r6, #4
 *   @0x202528 bl 0x202498 <_Z8IntToHexi>
 *   @0x20252c strb r0, [r11, #-0x2]
 *   @0x202530 and r0, r6, #15
 *   @0x202534 bl 0x202498 <_Z8IntToHexi>
 *   @0x202538 mov r6, r4
 *   @0x20253c adds r4, r4, #1
 *   @0x202540 adc r5, r5, #0
 *   @0x202544 strb r0, [r11, #-0x1]
 *   @0x202548 ldrd r2, r3, [r10, #16]
 *   @0x20254c cmp r6, r2
 *   @0x202550 sbcs r1, r7, r3
 *   @0x202554 blt 0x202510 <_ZN7CStream15ConvertToStringERPKc+0x60>
 *   @0x202558 mov r3, #0
 *   @0x20255c strb r3, [r9, r2, lsl #1]
 *   @0x202560 str r9, [r8]
 *   @0x202564 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x202568 andseq r1, r5, r4, asr #4
 *
 * ══ §149/156 CDS_Priority::WriteToString(char const*&)  0x203d6c  size 188  47 条（0x203d6c..0x203e28）
 * @func 0x203d6c 0x203e28  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::WriteInteger(int)×2 / CDS_Priority::WriteToString(char const*&)+0x94×2 / WriteValue(CStream&, RValue&)×2 / operator new(unsigned int) / CStream::CStream(int) / CStream::ConvertToString(char const*&) / CStream::~CStream()
 * 字段偏移 top8: 0x4×4 / 0x14×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x203d6c push {r3, r4, r5, r6, r7, lr}
 *   @0x203d70 mov r4, r0
 *   @0x203d74 mov r0, #32
 *   @0x203d78 mov r7, r1
 *   @0x203d7c bl 0x27c524 <_Znwj>
 *   @0x203d80 mov r1, #0
 *   @0x203d84 mov r6, r0
 *   @0x203d88 bl 0x2010ec <_ZN7CStreamC2Ei>
 *   @0x203d8c mov r0, r6
 *   @0x203d90 movw r1, #0x1f6
 *   @0x203d94 bl 0x201a10 <_ZN7CStream12WriteIntegerEi>
 *   @0x203d98 mov r0, r6
 *   @0x203d9c ldr r1, [r4, #0x4]
 *   @0x203da0 bl 0x201a10 <_ZN7CStream12WriteIntegerEi>
 *   @0x203da4 ldr r3, [r4, #0x4]
 *   @0x203da8 cmp r3, #0
 *   @0x203dac movgt r5, #0
 *   @0x203db0 ble 0x203e00 <_ZN12CDS_Priority13WriteToStringERPKc+0x94>
 *   @0x203db4 ldr r1, [r4, #0x14]
 *   @0x203db8 mov r0, r6
 *   @0x203dbc add r1, r1, r5, lsl #4
 *   @0x203dc0 add r5, r5, #1
 *   @0x203dc4 bl 0x202af8 <_Z10WriteValueR7CStreamR6RValue>
 *   @0x203dc8 ldr r3, [r4, #0x4]
 *   @0x203dcc cmp r3, r5
 *   @0x203dd0 bgt 0x203db4 <_ZN12CDS_Priority13WriteToStringERPKc+0x48>
 *   @0x203dd4 cmp r3, #0
 *   @0x203dd8 ble 0x203e00 <_ZN12CDS_Priority13WriteToStringERPKc+0x94>
 *   @0x203ddc mov r5, #0
 *   @0x203de0 ldr r1, [r4, #0xc]
 *   @0x203de4 mov r0, r6
 *   @0x203de8 add r1, r1, r5, lsl #4
 *   @0x203dec add r5, r5, #1
 *   @0x203df0 bl 0x202af8 <_Z10WriteValueR7CStreamR6RValue>
 *   @0x203df4 ldr r3, [r4, #0x4]
 *   @0x203df8 cmp r3, r5
 *   @0x203dfc bgt 0x203de0 <_ZN12CDS_Priority13WriteToStringERPKc+0x74>
 *   @0x203e00 mov r1, r7
 *   @0x203e04 mov r0, r6
 *   @0x203e08 bl 0x2024b0 <_ZN7CStream15ConvertToStringERPKc>
 *   @0x203e0c cmp r6, #0
 *   @0x203e10 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x203e14 mov r0, r6
 *   @0x203e18 bl 0x201328 <_ZN7CStreamD2Ev>
 *   @0x203e1c mov r0, r6
 *   @0x203e20 pop {r3, r4, r5, r6, r7, lr}
 *   @0x203e24 b 0x27d1d0 <_ZdlPv>
 *
 * ══ §150/156 COggAudio::GetOggChannel(int, int)  0x226118  size 188  47 条（0x226118..0x2261d4）
 * @func 0x226118 0x2261d4  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: COggAudio::GetOggChannel(int, int)+0x70 / __aeabi_idivmod / __divsi3
 * 字段偏移 top8: 0x804×2 / 0x4×1 / 0x80c×1 / 0x2b8×1 / 0x-48×1 / 0x14×1 / 0x802×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x226118 cmn r2, #1
 *   @0x22611c push {r4, r5, r6, lr}
 *   @0x226120 mov r5, r0
 *   @0x226124 mov r4, r1
 *   @0x226128 beq 0x226190 <_ZN9COggAudio13GetOggChannelEii+0x78>
 *   @0x22612c ldr r3, [r0, #0x4]
 *   @0x226130 cmp r2, r3
 *   @0x226134 ldrlt r3, [r0, #0x10]
 *   @0x226138 movge r3, #0
 *   @0x22613c ldrlt r3, [r3, r2, lsl #2]
 *   @0x226140 ldr r1, [r3, #0x80c]
 *   @0x226144 cmp r1, #0
 *   @0x226148 ble 0x226188 <_ZN9COggAudio13GetOggChannelEii+0x70>
 *   @0x22614c ldr r0, [r3, #0x804]
 *   @0x226150 ldr r3, [r0, #0x2b8]
 *   @0x226154 cmp r3, r4
 *   @0x226158 popeq {r4, r5, r6, pc}
 *   @0x22615c add r3, r0, #768
 *   @0x226160 mov r2, #0
 *   @0x226164 b 0x226174 <_ZN9COggAudio13GetOggChannelEii+0x5c>
 *   @0x226168 ldr r12, [r3, #-0x48]
 *   @0x22616c cmp r12, r4
 *   @0x226170 popeq {r4, r5, r6, pc}
 *   @0x226174 add r2, r2, #1
 *   @0x226178 mov r0, r3
 *   @0x22617c cmp r2, r1
 *   @0x226180 add r3, r3, #768
 *   @0x226184 bne 0x226168 <_ZN9COggAudio13GetOggChannelEii+0x50>
 *   @0x226188 mov r0, #0
 *   @0x22618c pop {r4, r5, r6, pc}
 *   @0x226190 ldr r6, [r0, #0x14]
 *   @0x226194 mov r0, r1
 *   @0x226198 mov r1, r6
 *   @0x22619c bl 0x318dec <__aeabi_idivmod>
 *   @0x2261a0 ldr r3, [r5]
 *   @0x2261a4 movw r5, #0x834
 *   @0x2261a8 mla r5, r5, r1, r3
 *   @0x2261ac ldrb r0, [r5, #0x802]
 *   @0x2261b0 cmp r0, #0
 *   @0x2261b4 popeq {r4, r5, r6, pc}
 *   @0x2261b8 mov r0, r4
 *   @0x2261bc mov r1, r6
 *   @0x2261c0 bl 0x318d10 <__divsi3>
 *   @0x2261c4 ldr r3, [r5, #0x804]
 *   @0x2261c8 add r0, r0, r0, lsl #1
 *   @0x2261cc add r0, r3, r0, lsl #8
 *   @0x2261d0 pop {r4, r5, r6, pc}
 *
 * ══ §151/156 CPhysicsWorld::DeleteParticleBoxRegion(float, float, float, float)  0x239fd0  size 188  47 条（0x239fd0..0x23a08c）
 * @func 0x239fd0 0x23a08c  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2PolygonShape::SetAsBox(float, float) / b2World::DestroyParticlesInShape(b2Shape const&, b2Transform const&, bool)
 * 字段偏移 top8: 0x10×2 / 0x90×1 / 0x18×1 / 0x14×1 / 0x1c×1 / 0xa4×1 / 0x20×1 / 0x8×1
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x239fd0 vmov s13, r3
 *   @0x239fd4 vldr s14, [r0, #96]
 *   @0x239fd8 push {r4, r5, r6, r7, lr}
 *   @0x239fdc vpush {d8}
 *   @0x239fe0 vmul.f32 s13, s14, s13
 *   @0x239fe4 sub sp, sp, #172
 *   @0x239fe8 vldr s15, [sp, #200]
 *   @0x239fec add r6, sp, #16
 *   @0x239ff0 ldr r12, [pc, #0x90]
 *   @0x239ff4 vmov s16, r2
 *   @0x239ff8 mov r4, r0
 *   @0x239ffc vmov s17, r1
 *   @0x23a000 mov r0, r6
 *   @0x23a004 ldr r12, [pc, r12]
 *   @0x23a008 movw r2, #0xd70a
 *   @0x23a00c movt r2, #0x3c23
 *   @0x23a010 str r2, [sp, #0x18]
 *   @0x23a014 mov r5, #0
 *   @0x23a018 add r12, r12, #8
 *   @0x23a01c mov r3, #2
 *   @0x23a020 str r12, [sp, #0x10]
 *   @0x23a024 str r3, [sp, #0x14]
 *   @0x23a028 mov r7, #0
 *   @0x23a02c str r5, [sp, #0x1c]
 *   @0x23a030 str r7, [sp, #0xa4]
 *   @0x23a034 vmul.f32 s15, s14, s15
 *   @0x23a038 str r5, [sp, #0x20]
 *   @0x23a03c vmov r1, s13
 *   @0x23a040 vmov r2, s15
 *   @0x23a044 bl 0x2c5e9c <_ZN14b2PolygonShape8SetAsBoxEff>
 *   @0x23a048 vldr s15, [r4, #96]
 *   @0x23a04c vmul.f32 s17, s15, s17
 *   @0x23a050 mov r1, r6
 *   @0x23a054 mov r3, r7
 *   @0x23a058 ldr r0, [r4, #0x10]
 *   @0x23a05c mov r2, sp
 *   @0x23a060 mov r12, #1065353216
 *   @0x23a064 str r5, [sp, #0x8]
 *   @0x23a068 str r12, [sp, #0xc]
 *   @0x23a06c vmul.f32 s15, s15, s16
 *   @0x23a070 vstr s17, [sp]
 *   @0x23a074 vstr s15, [sp, #4]
 *   @0x23a078 bl 0x2cb4d8 <_ZN7b2World23DestroyParticlesInShapeERK7b2ShapeRK11b2Transformb>
 *   @0x23a07c add sp, sp, #172
 *   @0x23a080 vpop {d8}
 *   @0x23a084 pop {r4, r5, r6, r7, pc}
 *   @0x23a088 andseq r7, r11, r12, lsr #9
 *
 * ══ §152/156 pcre_config  0x25ed64  size 188  47 条（0x25ed64..0x25ee20）
 * @func 0x25ed64 0x25ee20  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x25ed64 cmp r0, #13
 *   @0x25ed68 addls pc, pc, r0, lsl #2
 *   @0x25ed6c b 0x25ee18 <pcre_config+0xb4>
 *   @0x25ed70 b 0x25edc4 <pcre_config+0x60>
 *   @0x25ed74 b 0x25edb4 <pcre_config+0x50>
 *   @0x25ed78 b 0x25edf8 <pcre_config+0x94>
 *   @0x25ed7c b 0x25edb4 <pcre_config+0x50>
 *   @0x25ed80 b 0x25edd4 <pcre_config+0x70>
 *   @0x25ed84 b 0x25edc4 <pcre_config+0x60>
 *   @0x25ed88 b 0x25eda8 <pcre_config+0x44>
 *   @0x25ed8c b 0x25edd4 <pcre_config+0x70>
 *   @0x25ed90 b 0x25eda8 <pcre_config+0x44>
 *   @0x25ed94 b 0x25eda8 <pcre_config+0x44>
 *   @0x25ed98 b 0x25ede8 <pcre_config+0x84>
 *   @0x25ed9c b 0x25eda8 <pcre_config+0x44>
 *   @0x25eda0 b 0x25ede8 <pcre_config+0x84>
 *   @0x25eda4 b 0x25ee08 <pcre_config+0xa4>
 *   @0x25eda8 mov r0, #0
 *   @0x25edac str r0, [r1]
 *   @0x25edb0 bx lr
 *   @0x25edb4 mov r3, #10
 *   @0x25edb8 mov r0, #0
 *   @0x25edbc str r3, [r1]
 *   @0x25edc0 bx lr
 *   @0x25edc4 mov r3, #1
 *   @0x25edc8 mov r0, #0
 *   @0x25edcc str r3, [r1]
 *   @0x25edd0 bx lr
 *   @0x25edd4 movw r3, #0x9680
 *   @0x25edd8 mov r0, #0
 *   @0x25eddc movt r3, #0x98
 *   @0x25ede0 str r3, [r1]
 *   @0x25ede4 bx lr
 *   @0x25ede8 mov r3, #0
 *   @0x25edec mvn r0, #2
 *   @0x25edf0 str r3, [r1]
 *   @0x25edf4 bx lr
 *   @0x25edf8 mov r3, #2
 *   @0x25edfc mov r0, #0
 *   @0x25ee00 str r3, [r1]
 *   @0x25ee04 bx lr
 *   @0x25ee08 mov r3, #250
 *   @0x25ee0c mov r0, #0
 *   @0x25ee10 str r3, [r1]
 *   @0x25ee14 bx lr
 *   @0x25ee18 mvn r0, #2
 *   @0x25ee1c bx lr
 *
 * ══ §153/156 MemoryManager::AllocAligned(unsigned int, int, char const*, int, bool)  0x27d090  size 188  47 条（0x27d090..0x27d14c）
 * @func 0x27d090 0x27d14c  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::_Alloc(unsigned int, char const*, int, bool) / Mutex::Lock() / logLocation(ELogType, void const*, void const*, unsigned int) / Mutex::Unlock() / 0xb65b0 / anon_27b918
 * 字段偏移 top8: 0x18×1 / 0x78×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27d090 push {r4, r5, r6, r7, r8, lr}
 *   @0x27d094 subs r8, r0, #0
 *   @0x27d098 mov r6, r1
 *   @0x27d09c ldrb r4, [sp, #0x18]
 *   @0x27d0a0 beq 0x27d134 <_ZN13MemoryManager12AllocAlignedEjiPKcib+0xa4>
 *   @0x27d0a4 sub r0, r1, #1
 *   @0x27d0a8 mov r1, r2
 *   @0x27d0ac add r0, r0, r8
 *   @0x27d0b0 mov r2, r3
 *   @0x27d0b4 mov r3, #0
 *   @0x27d0b8 bl 0x27cd54 <_ZN13MemoryManager6_AllocEjPKcib>
 *   @0x27d0bc cmp r4, #0
 *   @0x27d0c0 mov r7, r0
 *   @0x27d0c4 bne 0x27d124 <_ZN13MemoryManager12AllocAlignedEjiPKcib+0x94>
 *   @0x27d0c8 ldr r5, [pc, #0x78]
 *   @0x27d0cc ldr r5, [pc, r5]
 *   @0x27d0d0 ldr r0, [r5]
 *   @0x27d0d4 cmp r0, #0
 *   @0x27d0d8 beq 0x27d13c <_ZN13MemoryManager12AllocAlignedEjiPKcib+0xac>
 *   @0x27d0dc add r4, r7, r6
 *   @0x27d0e0 rsb r6, r6, #0
 *   @0x27d0e4 sub r4, r4, #1
 *   @0x27d0e8 bl 0x27e084 <_ZN5Mutex4LockEv>
 *   @0x27d0ec and r4, r4, r6
 *   @0x27d0f0 mov r0, #0
 *   @0x27d0f4 cmp r4, r7
 *   @0x27d0f8 mov r1, r0
 *   @0x27d0fc rsbne r7, r7, r4
 *   @0x27d100 mov r3, r8
 *   @0x27d104 addne r7, r7, #-2147483648
 *   @0x27d108 mov r2, r4
 *   @0x27d10c strne r7, [r4, #-0x4]
 *   @0x27d110 bl 0x27bcf4 <_Z11logLocation8ELogTypePKvS1_j>
 *   @0x27d114 ldr r0, [r5]
 *   @0x27d118 bl 0x27e09c <_ZN5Mutex6UnlockEv>
 *   @0x27d11c mov r0, r4
 *   @0x27d120 pop {r4, r5, r6, r7, r8, pc}
 *   @0x27d124 mov r1, #0
 *   @0x27d128 mov r2, r8
 *   @0x27d12c bl 0xb65b0 <memset@plt>
 *   @0x27d130 b 0x27d0c8 <_ZN13MemoryManager12AllocAlignedEjiPKcib+0x38>
 *   @0x27d134 mov r0, r8
 *   @0x27d138 pop {r4, r5, r6, r7, r8, pc}
 *   @0x27d13c bl 0x27b918 <_ZN7CBucketILj8ELj131072ELb1EE4FreeEPKv+0x38>
 *   @0x27d140 ldr r0, [r5]
 *   @0x27d144 b 0x27d0dc <_ZN13MemoryManager12AllocAlignedEjiPKcib+0x4c>
 *   @0x27d148 andseq r4, r7, r0, asr r7
 *
 * ══ §154/156 array_list_put_idx  0x27e218  size 188  47 条（0x27e218..0x27e2d4）
 * @func 0x27e218 0x27e2d4  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: array_list_put_idx+0xac / 0xb6c28 / 0xb65b0
 * 字段偏移 top8: 0x8×3 / 0x4×2 / 0x2×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27e218 push {r3, r4, r5, r6, r7, lr}
 *   @0x27e21c mov r4, r0
 *   @0x27e220 ldr r3, [r0, #0x8]
 *   @0x27e224 mov r5, r1
 *   @0x27e228 mov r7, r2
 *   @0x27e22c cmp r1, r3
 *   @0x27e230 bge 0x27e27c <array_list_put_idx+0x64>
 *   @0x27e234 ldr r3, [r4]
 *   @0x27e238 lsl r6, r5, #2
 *   @0x27e23c add r1, r3, r6
 *   @0x27e240 ldr r0, [r3, r5, lsl #2]
 *   @0x27e244 cmp r0, #0
 *   @0x27e248 beq 0x27e25c <array_list_put_idx+0x44>
 *   @0x27e24c ldr r3, [r4, #0xc]
 *   @0x27e250 blx r3
 *   @0x27e254 ldr r1, [r4]
 *   @0x27e258 add r1, r1, r6
 *   @0x27e25c ldr r3, [r4, #0x4]
 *   @0x27e260 str r7, [r1]
 *   @0x27e264 cmp r5, r3
 *   @0x27e268 blt 0x27e2c4 <array_list_put_idx+0xac>
 *   @0x27e26c add r5, r5, #1
 *   @0x27e270 mov r0, #0
 *   @0x27e274 str r5, [r4, #0x4]
 *   @0x27e278 pop {r3, r4, r5, r6, r7, pc}
 *   @0x27e27c lsl r3, r3, #1
 *   @0x27e280 ldr r0, [r0]
 *   @0x27e284 cmp r3, r1
 *   @0x27e288 movge r6, r3
 *   @0x27e28c movlt r6, r1
 *   @0x27e290 lsl r1, r6, #2
 *   @0x27e294 bl 0xb6c28 <realloc@plt>
 *   @0x27e298 cmp r0, #0
 *   @0x27e29c beq 0x27e2cc <array_list_put_idx+0xb4>
 *   @0x27e2a0 ldr r3, [r4, #0x8]
 *   @0x27e2a4 mov r1, #0
 *   @0x27e2a8 str r0, [r4]
 *   @0x27e2ac rsb r2, r3, r6
 *   @0x27e2b0 add r0, r0, r3, lsl #2
 *   @0x27e2b4 lsl r2, r2, #2
 *   @0x27e2b8 bl 0xb65b0 <memset@plt>
 *   @0x27e2bc str r6, [r4, #0x8]
 *   @0x27e2c0 b 0x27e234 <array_list_put_idx+0x1c>
 *   @0x27e2c4 mov r0, #0
 *   @0x27e2c8 pop {r3, r4, r5, r6, r7, pc}
 *   @0x27e2cc mvn r0, #0
 *   @0x27e2d0 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §155/156 _spAttachmentTimeline_apply  0x281114  size 188  47 条（0x281114..0x2811d0）
 * @func 0x281114 0x2811d0  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _spAttachmentTimeline_apply+0x78 / spSkeleton_getAttachmentForSlotIndex
 * 字段偏移 top8: 0x14×2 / 0xc×1 / 0x8×1 / 0x10×1 / 0x2×1
 * VFP 指令 10 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x281114 vmov s15, r3
 *   @0x281118 push {r4, r5, r6, lr}
 *   @0x28111c ldr r5, [r0, #0xc]
 *   @0x281120 vldr s14, [r5]
 *   @0x281124 vcmpe.f32 s14, s15
 *   @0x281128 vmrs APSR_nzcv, fpscr
 *   @0x28112c popgt {r4, r5, r6, pc}
 *   @0x281130 ldr r12, [r0, #0x8]
 *   @0x281134 sub r3, r12, #-1073741823
 *   @0x281138 lsl r3, r3, #2
 *   @0x28113c add r2, r5, r3
 *   @0x281140 vldr s14, [r2]
 *   @0x281144 vcmpe.f32 s15, s14
 *   @0x281148 vmrs APSR_nzcv, fpscr
 *   @0x28114c blt 0x28118c <_spAttachmentTimeline_apply+0x78>
 *   @0x281150 ldr r2, [r0, #0x14]
 *   @0x281154 ldr r12, [r0, #0x10]
 *   @0x281158 ldr r0, [r1, #0x14]
 *   @0x28115c ldr r2, [r2, r3]
 *   @0x281160 cmp r2, #0
 *   @0x281164 ldr r4, [r0, r12, lsl #2]
 *   @0x281168 moveq r1, r2
 *   @0x28116c beq 0x281180 <_spAttachmentTimeline_apply+0x6c>
 *   @0x281170 mov r0, r1
 *   @0x281174 mov r1, r12
 *   @0x281178 bl 0x28a314 <spSkeleton_getAttachmentForSlotIndex>
 *   @0x28117c mov r1, r0
 *   @0x281180 mov r0, r4
 *   @0x281184 pop {r4, r5, r6, lr}
 *   @0x281188 b 0x28ee1c <spSlot_setAttachment>
 *   @0x28118c subs r3, r12, #2
 *   @0x281190 beq 0x281150 <_spAttachmentTimeline_apply+0x3c>
 *   @0x281194 asr r12, r3, #1
 *   @0x281198 mov r2, #0
 *   @0x28119c add r4, r12, #1
 *   @0x2811a0 add r6, r5, r4, lsl #2
 *   @0x2811a4 vldr s14, [r6]
 *   @0x2811a8 vcmpe.f32 s15, s14
 *   @0x2811ac vmrs APSR_nzcv, fpscr
 *   @0x2811b0 movge r2, r4
 *   @0x2811b4 movlt r3, r12
 *   @0x2811b8 add r12, r2, r3
 *   @0x2811bc cmp r2, r3
 *   @0x2811c0 asr r12, r12, #1
 *   @0x2811c4 bne 0x28119c <_spAttachmentTimeline_apply+0x88>
 *   @0x2811c8 lsl r3, r2, #2
 *   @0x2811cc b 0x281150 <_spAttachmentTimeline_apply+0x3c>
 *
 * ══ §156/156 VMWriteBuffer::AddVal(int)  0xec710  size 12  3 条（0xec710..0xec71c）
 * @func 0xec710 0xec71c  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xec710 mov r2, r1
 *   @0xec714 mov r1, #1
 *   @0xec718 b 0xec674 <_ZN13VMWriteBuffer3AddEiz>
 */
