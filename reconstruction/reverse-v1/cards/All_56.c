/* cally 逆向卡：All_56 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 168 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/168 GifAddExtensionBlock(int*, ExtensionBlock**, int, unsigned int, unsigned char*)  0x2c2f3c  size 188  47 条（0x2c2f3c..0x2c2ff8）
 * @func 0x2c2f3c 0x2c2ff8  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6544×2 / 0xb6c28 / 0xb65bc
 * 字段偏移 top8: 0x18×1 / 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c2f3c push {r4, r5, r6, r7, r8, lr}
 *   @0x2c2f40 mov r4, r0
 *   @0x2c2f44 ldr r0, [r1]
 *   @0x2c2f48 mov r6, r1
 *   @0x2c2f4c mov r8, r2
 *   @0x2c2f50 mov r5, r3
 *   @0x2c2f54 cmp r0, #0
 *   @0x2c2f58 ldr r7, [sp, #0x18]
 *   @0x2c2f5c beq 0x2c2fe4 <_Z20GifAddExtensionBlockPiPP14ExtensionBlockijPh+0xa8>
 *   @0x2c2f60 ldr r1, [r4]
 *   @0x2c2f64 add r1, r1, #1
 *   @0x2c2f68 add r1, r1, r1, lsl #1
 *   @0x2c2f6c lsl r1, r1, #2
 *   @0x2c2f70 bl 0xb6c28 <realloc@plt>
 *   @0x2c2f74 mov r12, r0
 *   @0x2c2f78 str r0, [r6]
 *   @0x2c2f7c cmp r12, #0
 *   @0x2c2f80 beq 0x2c2fd4 <_Z20GifAddExtensionBlockPiPP14ExtensionBlockijPh+0x98>
 *   @0x2c2f84 ldr lr, [r4]
 *   @0x2c2f88 mov r0, r5
 *   @0x2c2f8c add r3, lr, #1
 *   @0x2c2f90 str r3, [r4]
 *   @0x2c2f94 add lr, lr, lr, lsl #1
 *   @0x2c2f98 lsl lr, lr, #2
 *   @0x2c2f9c add r4, r12, lr
 *   @0x2c2fa0 str r8, [r4, #0x8]
 *   @0x2c2fa4 str r5, [r12, lr]
 *   @0x2c2fa8 bl 0xb6544 <malloc@plt>
 *   @0x2c2fac cmp r0, #0
 *   @0x2c2fb0 str r0, [r4, #0x4]
 *   @0x2c2fb4 beq 0x2c2fd4 <_Z20GifAddExtensionBlockPiPP14ExtensionBlockijPh+0x98>
 *   @0x2c2fb8 cmp r7, #0
 *   @0x2c2fbc beq 0x2c2fdc <_Z20GifAddExtensionBlockPiPP14ExtensionBlockijPh+0xa0>
 *   @0x2c2fc0 mov r1, r7
 *   @0x2c2fc4 mov r2, r5
 *   @0x2c2fc8 bl 0xb65bc <memcpy@plt>
 *   @0x2c2fcc mov r0, #1
 *   @0x2c2fd0 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2c2fd4 mov r0, #0
 *   @0x2c2fd8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2c2fdc mov r0, #1
 *   @0x2c2fe0 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2c2fe4 mov r0, #12
 *   @0x2c2fe8 bl 0xb6544 <malloc@plt>
 *   @0x2c2fec mov r12, r0
 *   @0x2c2ff0 str r0, [r6]
 *   @0x2c2ff4 b 0x2c2f7c <_Z20GifAddExtensionBlockPiPP14ExtensionBlockijPh+0x40>
 *
 * ══ §2/168 b2PolygonShape::Validate() const  0x2c6414  size 188  47 条（0x2c6414..0x2c64d0）
 * @func 0x2c6414 0x2c64d0  size 188  47 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2PolygonShape::Validate() const+0xb0
 * 字段偏移 top8: 0x94×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c6414 push {r4, r5, r6, r7, r8}
 *   @0x2c6418 mov r6, r0
 *   @0x2c641c ldr r4, [r0, #0x94]
 *   @0x2c6420 cmp r4, #0
 *   @0x2c6424 ble 0x2c64c4 <_ZNK14b2PolygonShape8ValidateEv+0xb0>
 *   @0x2c6428 add r7, r0, #20
 *   @0x2c642c sub r8, r4, #1
 *   @0x2c6430 mov r1, #0
 *   @0x2c6434 mov r5, r7
 *   @0x2c6438 cmp r1, r8
 *   @0x2c643c vldr s12, [r5]
 *   @0x2c6440 addlt r12, r1, #1
 *   @0x2c6444 vldr s13, [r5, #4]
 *   @0x2c6448 movge r12, #0
 *   @0x2c644c add r3, r12, #2
 *   @0x2c6450 mov r2, r7
 *   @0x2c6454 add r3, r6, r3, lsl #3
 *   @0x2c6458 vldr s10, [r3, #4]
 *   @0x2c645c vldr s11, [r3, #8]
 *   @0x2c6460 vsub.f32 s10, s10, s12
 *   @0x2c6464 mov r3, #0
 *   @0x2c6468 vsub.f32 s11, s11, s13
 *   @0x2c646c cmp r1, r3
 *   @0x2c6470 cmpne r3, r12
 *   @0x2c6474 add r3, r3, #1
 *   @0x2c6478 movne r0, #0
 *   @0x2c647c moveq r0, #1
 *   @0x2c6480 beq 0x2c64a8 <_ZNK14b2PolygonShape8ValidateEv+0x94>
 *   @0x2c6484 vldr s15, [r2]
 *   @0x2c6488 vldr s14, [r2, #4]
 *   @0x2c648c vsub.f32 s15, s15, s12
 *   @0x2c6490 vmul.f32 s15, s11, s15
 *   @0x2c6494 vsub.f32 s14, s14, s13
 *   @0x2c6498 vnmls.f32 s15, s10, s14
 *   @0x2c649c vcmpe.f32 s15, #0
 *   @0x2c64a0 vmrs APSR_nzcv, fpscr
 *   @0x2c64a4 bmi 0x2c64c8 <_ZNK14b2PolygonShape8ValidateEv+0xb4>
 *   @0x2c64a8 cmp r3, r4
 *   @0x2c64ac add r2, r2, #8
 *   @0x2c64b0 bne 0x2c646c <_ZNK14b2PolygonShape8ValidateEv+0x58>
 *   @0x2c64b4 add r1, r1, #1
 *   @0x2c64b8 add r5, r5, #8
 *   @0x2c64bc cmp r1, r3
 *   @0x2c64c0 bne 0x2c6438 <_ZNK14b2PolygonShape8ValidateEv+0x24>
 *   @0x2c64c4 mov r0, #1
 *   @0x2c64c8 pop {r4, r5, r6, r7, r8}
 *   @0x2c64cc bx lr
 *
 * ══ §3/168 FT_Match_Size  0x2e5424  size 188  47 条（0x2e5424..0x2e54e0）
 * @func 0x2e5424 0x2e54e0  size 188  47 条
 * 部分覆盖: 本节 47/87 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __divsi3
 * 字段偏移 top8: 0xc×1 / 0x8×1 / 0x1c×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5424 push.w {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2e5428 mov r7, r3
 *   @0x2e542c mov r6, r0
 *   @0x2e5430 mov r8, r2
 *   @0x2e5434 bpl 0x2e54ce <FT_Match_Size+0xaa>
 *   @0x2e5438 cmp r3, #0x0
 *   @0x2e543c ldr r0, [r1, #0xc]
 *   @0x2e5440 teqlt r8, r4
 *   @0x2e5444 mul r0, r9, r0
 *   @0x2e5448 movs r1, #0x48
 *   @0x2e544c blx 0x318d10 <__divsi3>
 *   @0x2e5450 mov r5, r0
 *   @0x2e5454 mov r5, r9
 *   @0x2e5458 ldr r4, [r4, #0x8]
 *   @0x2e545c muls r0, r4, r0
 *   @0x2e5460 adds r0, #0x24
 *   @0x2e5464 and lr, r0, r6, asr r12
 *   @0x2e5468 mov r0, r4
 *   @0x2e546c andle r0, r3, r0, lsl #30
 *   @0x2e5470 cmp r4, #0x0
 *   @0x2e5474 moveq r0, r5
 *   @0x2e5478 cmp r4, #0x0
 *   @0x2e547c movne r5, r0
 *   @0x2e5480 bics r5, r5, #0x3f
 *   @0x2e5484 beq 0x2e54da <FT_Match_Size+0xb6>
 *   @0x2e5488 .word 0xf0310120
 *   @0x2e548c eorle r0, r4, pc, lsr r4
 *   @0x2e5490 ldr r0, [r6, #0x1c]
 *   @0x2e5494 cmp r1, r0
 *   @0x2e5498 ldr r3, [r6, #0x20]
 *   @0x2e549c ldmvs r10, {r0, r8, r9, r12} ^
 *   @0x2e54a0 adds r2, #0x20
 *   @0x2e54a4 addsmi r0, r4, #-268435453
 *   @0x2e54a8 bne 0x2e54ca <FT_Match_Size+0xa6>
 *   @0x2e54ac adds r3, #0x20
 *   @0x2e54b0 addsmi r0, sp, #-67108864
 *   @0x2e54b4 bne 0x2e54bc <FT_Match_Size+0x98>
 *   @0x2e54b8 str r1, [r7]
 *   @0x2e54bc cmp.w r8, #0x0
 *   @0x2e54c0 beq 0x2e54ca <FT_Match_Size+0xa6>
 *   @0x2e54c4 movs r0, #0x0
 *   @0x2e54c8 strdlo r8, r9, [r1, -r8]
 *   @0x2e54cc b 0x2e5494 <FT_Match_Size+0x70>
 *   @0x2e54d0 pop.w {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2e54d4 movs r0, #0x7
 *   @0x2e54d8 ldrshhs r8, [r7], -r8
 *   @0x2e54dc pop.w {r3, r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §4/168 CSkeletonInstance::FindAttachment(char const*, char const*)  0xc0810  size 184  46 条（0xc0810..0xc08c8）
 * @func 0xc0810 0xc08c8  size 184  46 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeleton_findSlotIndex / CSkeletonInstance::FindAttachment(char const*, char const*)+0x70 / spSkin_getAttachment / CSkeletonInstance::FindAttachment(char const*, char const*)+0xac / 0xb6574
 * 字段偏移 top8: 0x30×2 / 0x20×2 / 0x1c×1 / 0x24×1 / 0x2×1 / 0x10×1 / 0x14×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc0810 push {r3, r4, r5, r6, r7, lr}
 *   @0xc0814 mov r6, r0
 *   @0xc0818 ldr r0, [r0, #0x1c]
 *   @0xc081c mov r5, r2
 *   @0xc0820 bl 0x28a1f4 <spSkeleton_findSlotIndex>
 *   @0xc0824 ldr r3, [r6, #0x30]
 *   @0xc0828 ldr r2, [r3, #0x20]
 *   @0xc082c cmp r2, #0
 *   @0xc0830 movgt r4, #0
 *   @0xc0834 mov r7, r0
 *   @0xc0838 bgt 0xc0850 <_ZN17CSkeletonInstance14FindAttachmentEPKcS1_+0x40>
 *   @0xc083c b 0xc0880 <_ZN17CSkeletonInstance14FindAttachmentEPKcS1_+0x70>
 *   @0xc0840 ldr r3, [r6, #0x30]
 *   @0xc0844 ldr r12, [r3, #0x20]
 *   @0xc0848 cmp r12, r4
 *   @0xc084c ble 0xc0880 <_ZN17CSkeletonInstance14FindAttachmentEPKcS1_+0x70>
 *   @0xc0850 ldr r3, [r3, #0x24]
 *   @0xc0854 mov r1, r7
 *   @0xc0858 mov r2, r5
 *   @0xc085c ldr r0, [r3, r4, lsl #2]
 *   @0xc0860 add r4, r4, #1
 *   @0xc0864 bl 0x28ed00 <spSkin_getAttachment>
 *   @0xc0868 cmp r0, #0
 *   @0xc086c beq 0xc0840 <_ZN17CSkeletonInstance14FindAttachmentEPKcS1_+0x30>
 *   @0xc0870 cmp r5, #0
 *   @0xc0874 beq 0xc0880 <_ZN17CSkeletonInstance14FindAttachmentEPKcS1_+0x70>
 *   @0xc0878 mov r0, r5
 *   @0xc087c pop {r3, r4, r5, r6, r7, pc}
 *   @0xc0880 ldr r7, [r6, #0x10]
 *   @0xc0884 cmp r7, #0
 *   @0xc0888 ble 0xc08bc <_ZN17CSkeletonInstance14FindAttachmentEPKcS1_+0xac>
 *   @0xc088c ldr r6, [r6, #0x14]
 *   @0xc0890 mov r4, #0
 *   @0xc0894 sub r6, r6, #4
 *   @0xc0898 ldr r3, [r6, #0x4]!
 *   @0xc089c mov r1, r5
 *   @0xc08a0 add r4, r4, #1
 *   @0xc08a4 ldr r0, [r3]
 *   @0xc08a8 bl 0xb6574 <strcmp@plt>
 *   @0xc08ac cmp r0, #0
 *   @0xc08b0 beq 0xc0878 <_ZN17CSkeletonInstance14FindAttachmentEPKcS1_+0x68>
 *   @0xc08b4 cmp r4, r7
 *   @0xc08b8 bne 0xc0898 <_ZN17CSkeletonInstance14FindAttachmentEPKcS1_+0x88>
 *   @0xc08bc mov r5, #0
 *   @0xc08c0 mov r0, r5
 *   @0xc08c4 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §5/168 HASH_RValue(RValue const*)  0xcee94  size 184  46 条（0xcee94..0xcef4c）
 * @func 0xcee94 0xcef4c  size 184  46 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYError(char const*, ...)
 * 字段偏移 top8: 0xc×1 / 0x3c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcee94 push {r4, lr}
 *   @0xcee98 ldr r3, [r0, #0xc]
 *   @0xcee9c ldr r1, [r0]
 *   @0xceea0 bic r3, r3, #-16777216
 *   @0xceea4 mov r4, r1
 *   @0xceea8 cmp r3, #10
 *   @0xceeac addls pc, pc, r3, lsl #2
 *   @0xceeb0 b 0xceef8 <_Z11HASH_RValuePK6RValue+0x64>
 *   @0xceeb4 b 0xcef14 <_Z11HASH_RValuePK6RValue+0x80>
 *   @0xceeb8 b 0xcef2c <_Z11HASH_RValuePK6RValue+0x98>
 *   @0xceebc b 0xceeec <_Z11HASH_RValuePK6RValue+0x58>
 *   @0xceec0 b 0xceef8 <_Z11HASH_RValuePK6RValue+0x64>
 *   @0xceec4 b 0xceef8 <_Z11HASH_RValuePK6RValue+0x64>
 *   @0xceec8 b 0xceeec <_Z11HASH_RValuePK6RValue+0x58>
 *   @0xceecc b 0xceef8 <_Z11HASH_RValuePK6RValue+0x64>
 *   @0xceed0 b 0xceee4 <_Z11HASH_RValuePK6RValue+0x50>
 *   @0xceed4 b 0xceef8 <_Z11HASH_RValuePK6RValue+0x64>
 *   @0xceed8 b 0xceef8 <_Z11HASH_RValuePK6RValue+0x64>
 *   @0xceedc b 0xceee0 <_Z11HASH_RValuePK6RValue+0x4c>
 *   @0xceee0 ldr r4, [r0]
 *   @0xceee4 mov r0, r4
 *   @0xceee8 pop {r4, pc}
 *   @0xceeec cmp r1, #0
 *   @0xceef0 ldrne r4, [r1, #0x4]
 *   @0xceef4 moveq r4, r1
 *   @0xceef8 mvn r2, #-16777216
 *   @0xceefc cmp r3, r2
 *   @0xcef00 bne 0xceee4 <_Z11HASH_RValuePK6RValue+0x50>
 *   @0xcef04 ldr r0, [pc, #0x3c]
 *   @0xcef08 add r0, pc, r0
 *   @0xcef0c bl 0xd547c <_Z7YYErrorPKcz>
 *   @0xcef10 b 0xceee4 <_Z11HASH_RValuePK6RValue+0x50>
 *   @0xcef14 ldm r0, {r2, r3}
 *   @0xcef18 vmov d7, r2, r3
 *   @0xcef1c vcvt.s32.f64 s15, d7
 *   @0xcef20 vmov r4, s15
 *   @0xcef24 mov r0, r4
 *   @0xcef28 pop {r4, pc}
 *   @0xcef2c cmp r1, #0
 *   @0xcef30 beq 0xcef40 <_Z11HASH_RValuePK6RValue+0xac>
 *   @0xcef34 ldr r0, [r1]
 *   @0xcef38 pop {r4, lr}
 *   @0xcef3c b 0x27dfa8 <_Z14CalcCRC_stringPKc>
 *   @0xcef40 mov r4, r1
 *   @0xcef44 b 0xceee4 <_Z11HASH_RValuePK6RValue+0x50>
 *   @0xcef48 .word 0x002635bc
 *
 * ══ §6/168 AddObjectToGCFreeList(YYObjectBase*)  0xd3a90  size 184  46 条（0xd3a90..0xd3b48）
 * @func 0xd3a90 0xd3b48  size 184  46 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xd3aa8→0x47f26c, 0xd3aac→0x47f268, 0xd3ac8→0x47f278, 0xd3ae8→0x47f278
 * 调用序列: MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x88×2 / 0x94×1 / 0x70×1 / 0x2×1 / 0x50×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd3a90 push {r4, r5, r6, lr}
 *   @0xd3a94 subs r5, r0, #0
 *   @0xd3a98 ldr r12, [pc, #0x94]
 *   @0xd3a9c sub sp, sp, #8
 *   @0xd3aa0 add r12, pc, r12
 *   @0xd3aa4 beq 0xd3ae0 <_Z21AddObjectToGCFreeListP12YYObjectBase+0x50>
 *   @0xd3aa8 ldr r2, [pc, #0x88]
 *   @0xd3aac ldr r3, [pc, #0x88]
 *   @0xd3ab0 ldr r4, [r12, r2]
 *   @0xd3ab4 ldr r3, [r12, r3]
 *   @0xd3ab8 ldr r1, [r4]
 *   @0xd3abc ldr r2, [r3]
 *   @0xd3ac0 cmp r1, r2
 *   @0xd3ac4 beq 0xd3ae8 <_Z21AddObjectToGCFreeListP12YYObjectBase+0x58>
 *   @0xd3ac8 ldr r3, [pc, #0x70]
 *   @0xd3acc ldr r3, [r12, r3]
 *   @0xd3ad0 ldr r3, [r3]
 *   @0xd3ad4 add r2, r1, #1
 *   @0xd3ad8 str r2, [r4]
 *   @0xd3adc str r5, [r3, r1, lsl #2]
 *   @0xd3ae0 add sp, sp, #8
 *   @0xd3ae4 pop {r4, r5, r6, pc}
 *   @0xd3ae8 ldr lr, [pc, #0x50]
 *   @0xd3aec lsls r2, r1, #1
 *   @0xd3af0 strne r2, [r3]
 *   @0xd3af4 lslne r1, r1, #3
 *   @0xd3af8 moveq r2, #1
 *   @0xd3afc streq r2, [r3]
 *   @0xd3b00 ldr r6, [r12, lr]
 *   @0xd3b04 moveq r1, #4
 *   @0xd3b08 ldr r2, [pc, #0x34]
 *   @0xd3b0c mov r0, #0
 *   @0xd3b10 mov r3, #74
 *   @0xd3b14 str r0, [sp]
 *   @0xd3b18 add r2, pc, r2
 *   @0xd3b1c ldr r0, [r6]
 *   @0xd3b20 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0xd3b24 ldr r1, [r4]
 *   @0xd3b28 mov r3, r0
 *   @0xd3b2c str r0, [r6]
 *   @0xd3b30 b 0xd3ad4 <_Z21AddObjectToGCFreeListP12YYObjectBase+0x44>
 *   @0xd3b34 ldrhteq lr, [r1], -r0
 *   @0xd3b38 .word 0xffffbf84
 *   @0xd3b3c .word 0xffffbfbc
 *   @0xd3b40 .word 0xffffbf8c
 *   @0xd3b44 eoreq sp, r5, r8, lsl r5
 *
 * ══ §7/168 AddObjectToDisposeList(YYObjectBase*)  0xd3c1c  size 184  46 条（0xd3c1c..0xd3cd4）
 * @func 0xd3c1c 0xd3cd4  size 184  46 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xd3c34→0x47f260, 0xd3c38→0x47f25c, 0xd3c54→0x47f264, 0xd3c74→0x47f264
 * 调用序列: MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x88×2 / 0x94×1 / 0x70×1 / 0x2×1 / 0x50×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd3c1c push {r4, r5, r6, lr}
 *   @0xd3c20 subs r5, r0, #0
 *   @0xd3c24 ldr r12, [pc, #0x94]
 *   @0xd3c28 sub sp, sp, #8
 *   @0xd3c2c add r12, pc, r12
 *   @0xd3c30 beq 0xd3c6c <_Z22AddObjectToDisposeListP12YYObjectBase+0x50>
 *   @0xd3c34 ldr r2, [pc, #0x88]
 *   @0xd3c38 ldr r3, [pc, #0x88]
 *   @0xd3c3c ldr r4, [r12, r2]
 *   @0xd3c40 ldr r3, [r12, r3]
 *   @0xd3c44 ldr r1, [r4]
 *   @0xd3c48 ldr r2, [r3]
 *   @0xd3c4c cmp r1, r2
 *   @0xd3c50 beq 0xd3c74 <_Z22AddObjectToDisposeListP12YYObjectBase+0x58>
 *   @0xd3c54 ldr r3, [pc, #0x70]
 *   @0xd3c58 ldr r3, [r12, r3]
 *   @0xd3c5c ldr r3, [r3]
 *   @0xd3c60 add r2, r1, #1
 *   @0xd3c64 str r2, [r4]
 *   @0xd3c68 str r5, [r3, r1, lsl #2]
 *   @0xd3c6c add sp, sp, #8
 *   @0xd3c70 pop {r4, r5, r6, pc}
 *   @0xd3c74 ldr lr, [pc, #0x50]
 *   @0xd3c78 lsls r2, r1, #1
 *   @0xd3c7c strne r2, [r3]
 *   @0xd3c80 lslne r1, r1, #3
 *   @0xd3c84 moveq r2, #1
 *   @0xd3c88 streq r2, [r3]
 *   @0xd3c8c ldr r6, [r12, lr]
 *   @0xd3c90 moveq r1, #4
 *   @0xd3c94 ldr r2, [pc, #0x34]
 *   @0xd3c98 mov r0, #0
 *   @0xd3c9c mov r3, #74
 *   @0xd3ca0 str r0, [sp]
 *   @0xd3ca4 add r2, pc, r2
 *   @0xd3ca8 ldr r0, [r6]
 *   @0xd3cac bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0xd3cb0 ldr r1, [r4]
 *   @0xd3cb4 mov r3, r0
 *   @0xd3cb8 str r0, [r6]
 *   @0xd3cbc b 0xd3c60 <_Z22AddObjectToDisposeListP12YYObjectBase+0x44>
 *   @0xd3cc0 eorseq lr, r1, r4, lsr #32
 *   @0xd3cc4 .word 0xffffbfc8
 *   @0xd3cc8 .word 0xffffbfcc
 *   @0xd3ccc .word 0xffffbfd0
 *   @0xd3cd0 eoreq sp, r5, r12, lsl #7
 *
 * ══ §8/168 F_ExecuteProgram(RValue&, CInstance*, CInstance*, int, RValue*)  0x1389e4  size 184  46 条（0x1389e4..0x138a9c）
 * @func 0x1389e4 0x138ab0  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)×2 / YYGetBool(RValue const*, int) / GetCurrentDir() / File_Execute(char const*, char const*, char const*, bool)
 * 字段偏移 top8: 0xc×2 / 0x4×2 / 0x18×1 / 0x38×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1389e4 push {r4, r5, r6, r7, r8, lr}
 *   @0x1389e8 mov r1, #0
 *   @0x1389ec ldr r5, [sp, #0x18]
 *   @0x1389f0 mov r4, r0
 *   @0x1389f4 mov r0, r5
 *   @0x1389f8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1389fc mov r1, #1
 *   @0x138a00 mov r6, r0
 *   @0x138a04 mov r0, r5
 *   @0x138a08 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x138a0c mov r1, #2
 *   @0x138a10 mov r8, r0
 *   @0x138a14 mov r0, r5
 *   @0x138a18 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x138a1c mov r12, #0
 *   @0x138a20 str r12, [r4, #0xc]
 *   @0x138a24 str r12, [r4]
 *   @0x138a28 str r12, [r4, #0x4]
 *   @0x138a2c mov r7, r0
 *   @0x138a30 bl 0x214e1c <_Z13GetCurrentDirv>
 *   @0x138a34 mov r1, r8
 *   @0x138a38 mov r3, r7
 *   @0x138a3c mov r5, r0
 *   @0x138a40 mov r0, r6
 *   @0x138a44 mov r2, r5
 *   @0x138a48 bl 0x214de4 <_Z12File_ExecutePKcS0_S0_b>
 *   @0x138a4c cmp r0, #0
 *   @0x138a50 bne 0x138a88 <_Z16F_ExecuteProgramR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x138a54 ldr r3, [pc, #0x38]
 *   @0x138a58 mov r2, #0
 *   @0x138a5c str r0, [r4]
 *   @0x138a60 movt r2, #0xbff0
 *   @0x138a64 ldr r3, [pc, r3]
 *   @0x138a68 str r2, [r4, #0x4]
 *   @0x138a6c ldr r1, [pc, #0x24]
 *   @0x138a70 mov r2, r6
 *   @0x138a74 ldr r0, [r3]
 *   @0x138a78 add r1, pc, r1
 *   @0x138a7c ldr r3, [r0]
 *   @0x138a80 ldr r3, [r3, #0xc]
 *   @0x138a84 blx r3
 *   @0x138a88 mov r0, r5
 *   @0x138a8c pop {r4, r5, r6, r7, r8, lr}
 *   @0x138a90 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x138a94 .word 0x002b4cb0
 *   @0x138a98 eoreq r7, r0, r0, asr #12
 *
 * ══ §9/168 F_ExecuteShell(RValue&, CInstance*, CInstance*, int, RValue*)  0x138a9c  size 184  46 条（0x138a9c..0x138b54）
 * @func 0x138a9c 0x138b54  size 184  46 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)×2 / GetCurrentDir() / File_ShellExecute(char const*, char const*, char const*)
 * 字段偏移 top8: 0xc×2 / 0x4×2 / 0x18×1 / 0x38×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x138a9c push {r3, r4, r5, r6, r7, lr}
 *   @0x138aa0 mov r1, #0
 *   @0x138aa4 ldr r6, [sp, #0x18]
 *   @0x138aa8 mov r4, r0
 *   @0x138aac mov r0, r6
 *   @0x138ab0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x138ab4 mov r1, #1
 *   @0x138ab8 mov r5, r0
 *   @0x138abc mov r0, r6
 *   @0x138ac0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x138ac4 cmp r5, #0
 *   @0x138ac8 mov r3, #0
 *   @0x138acc str r3, [r4, #0xc]
 *   @0x138ad0 str r3, [r4]
 *   @0x138ad4 str r3, [r4, #0x4]
 *   @0x138ad8 mov r7, r0
 *   @0x138adc popeq {r3, r4, r5, r6, r7, pc}
 *   @0x138ae0 bl 0x214e1c <_Z13GetCurrentDirv>
 *   @0x138ae4 mov r1, r7
 *   @0x138ae8 mov r6, r0
 *   @0x138aec mov r0, r5
 *   @0x138af0 mov r2, r6
 *   @0x138af4 bl 0x214ddc <_Z17File_ShellExecutePKcS0_S0_>
 *   @0x138af8 cmp r0, #0
 *   @0x138afc beq 0x138b0c <_Z14F_ExecuteShellR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x138b00 mov r0, r6
 *   @0x138b04 pop {r3, r4, r5, r6, r7, lr}
 *   @0x138b08 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x138b0c ldr r3, [pc, #0x38]
 *   @0x138b10 mov r2, #0
 *   @0x138b14 str r0, [r4]
 *   @0x138b18 movt r2, #0xbff0
 *   @0x138b1c ldr r3, [pc, r3]
 *   @0x138b20 str r2, [r4, #0x4]
 *   @0x138b24 ldr r1, [pc, #0x24]
 *   @0x138b28 mov r2, r5
 *   @0x138b2c ldr r0, [r3]
 *   @0x138b30 add r1, pc, r1
 *   @0x138b34 ldr r3, [r0]
 *   @0x138b38 ldr r3, [r3, #0xc]
 *   @0x138b3c blx r3
 *   @0x138b40 mov r0, r6
 *   @0x138b44 pop {r3, r4, r5, r6, r7, lr}
 *   @0x138b48 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x138b4c .word 0x002b4bf8
 *   @0x138b50 eoreq r7, r0, r8, lsl #11
 *
 * ══ §10/168 F_ActionIfHealth(RValue&, CInstance*, CInstance*, int, RValue*)  0x13e940  size 184  46 条（0x13e940..0x13e9f8）
 * @func 0x13e940 0x13e9f8  size 184  46 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x13e974→0x542930
 * 调用序列: YYGetReal(RValue const*, int) / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x18×1 / 0x94×1 / 0x78×1 / 0xc×1 / 0x4×1
 * VFP 指令 10 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13e940 push {r4, r5, r6, lr}
 *   @0x13e944 vpush {d8}
 *   @0x13e948 mov r4, r0
 *   @0x13e94c ldr r5, [sp, #0x18]
 *   @0x13e950 mov r1, #0
 *   @0x13e954 ldr r6, [pc, #0x94]
 *   @0x13e958 mov r0, r5
 *   @0x13e95c add r6, pc, r6
 *   @0x13e960 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x13e964 vmov d8, r0, r1
 *   @0x13e968 mov r0, r5
 *   @0x13e96c mov r1, #1
 *   @0x13e970 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13e974 ldr r3, [pc, #0x78]
 *   @0x13e978 ldr r3, [r6, r3]
 *   @0x13e97c vldr d7, [r3]
 *   @0x13e980 cmp r0, #1
 *   @0x13e984 beq 0x13e9c8 <_Z16F_ActionIfHealthR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x13e988 cmp r0, #2
 *   @0x13e98c beq 0x13e9dc <_Z16F_ActionIfHealthR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x13e990 vcmp.f64 d7, d8
 *   @0x13e994 vmrs APSR_nzcv, fpscr
 *   @0x13e998 movne r3, #0
 *   @0x13e99c moveq r3, #1
 *   @0x13e9a0 cmp r3, #0
 *   @0x13e9a4 mov r2, #0
 *   @0x13e9a8 str r2, [r4, #0xc]
 *   @0x13e9ac movne r3, r2
 *   @0x13e9b0 moveq r2, r3
 *   @0x13e9b4 movtne r2, #0x3ff0
 *   @0x13e9b8 str r3, [r4]
 *   @0x13e9bc str r2, [r4, #0x4]
 *   @0x13e9c0 vpop {d8}
 *   @0x13e9c4 pop {r4, r5, r6, pc}
 *   @0x13e9c8 vcmpe.f64 d7, d8
 *   @0x13e9cc vmrs APSR_nzcv, fpscr
 *   @0x13e9d0 movpl r3, #0
 *   @0x13e9d4 movmi r3, #1
 *   @0x13e9d8 b 0x13e9a0 <_Z16F_ActionIfHealthR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x13e9dc vcmpe.f64 d7, d8
 *   @0x13e9e0 vmrs APSR_nzcv, fpscr
 *   @0x13e9e4 movle r3, #0
 *   @0x13e9e8 movgt r3, #1
 *   @0x13e9ec b 0x13e9a0 <_Z16F_ActionIfHealthR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x13e9f0 .word 0x002b32f4
 *   @0x13e9f4 .word 0xffffd788
 *
 * ══ §11/168 F_ActionDrawLine(RValue&, CInstance*, CInstance*, int, RValue*)  0x140830  size 184  46 条（0x140830..0x1408e8）
 * @func 0x140830 0x1408e8  size 184  46 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4
 * 字段偏移 top8: 0x20×1 / 0x60×1
 * VFP 指令 21 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x140830 push {r4, r5, r6, lr}
 *   @0x140834 vpush {d8, d9}
 *   @0x140838 mov r5, r1
 *   @0x14083c ldr r4, [sp, #0x20]
 *   @0x140840 mov r1, #0
 *   @0x140844 mov r0, r4
 *   @0x140848 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14084c mov r1, #1
 *   @0x140850 vmov s18, r0
 *   @0x140854 mov r0, r4
 *   @0x140858 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14085c mov r1, #2
 *   @0x140860 vmov s17, r0
 *   @0x140864 mov r0, r4
 *   @0x140868 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14086c mov r1, #3
 *   @0x140870 vmov s16, r0
 *   @0x140874 mov r0, r4
 *   @0x140878 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14087c ldr r3, [pc, #0x60]
 *   @0x140880 ldr r3, [pc, r3]
 *   @0x140884 ldrb r3, [r3]
 *   @0x140888 cmp r3, #0
 *   @0x14088c vmov s15, r0
 *   @0x140890 bne 0x1408b0 <_Z16F_ActionDrawLineR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x140894 vmov r0, s18
 *   @0x140898 vmov r1, s17
 *   @0x14089c vmov r2, s16
 *   @0x1408a0 vpop {d8, d9}
 *   @0x1408a4 vmov r3, s15
 *   @0x1408a8 pop {r4, r5, r6, lr}
 *   @0x1408ac b 0x16a21c <_Z12GR_Draw_Lineffff>
 *   @0x1408b0 vldr s13, [r5, #180]
 *   @0x1408b4 vldr s14, [r5, #184]
 *   @0x1408b8 vadd.f32 s18, s18, s13
 *   @0x1408bc vadd.f32 s17, s17, s14
 *   @0x1408c0 vmov r0, s18
 *   @0x1408c4 vadd.f32 s13, s16, s13
 *   @0x1408c8 vmov r1, s17
 *   @0x1408cc vpop {d8, d9}
 *   @0x1408d0 pop {r4, r5, r6, lr}
 *   @0x1408d4 vadd.f32 s14, s15, s14
 *   @0x1408d8 vmov r2, s13
 *   @0x1408dc vmov r3, s14
 *   @0x1408e0 b 0x16a21c <_Z12GR_Draw_Lineffff>
 *   @0x1408e4 .word 0x002ad2bc
 *
 * ══ §12/168 ValidateArgs(int, RValue*, int, ...)  0x1624d4  size 184  46 条（0x1624d4..0x16258c）
 * @func 0x1624d4 0x16258c  size 184  46 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Error_Show_Action(char const*, bool)×2 / ValidateArgs(int, RValue*, int, ...)+0x54
 * 字段偏移 top8: 0x10×1 / 0x4×1 / 0xc×1 / 0x-4×1 / 0x40×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1624d4 push {r2, r3}
 *   @0x1624d8 push {r4, lr}
 *   @0x1624dc sub sp, sp, #8
 *   @0x1624e0 ldr r3, [sp, #0x10]
 *   @0x1624e4 cmp r0, r3
 *   @0x1624e8 bne 0x16253c <_Z12ValidateArgsiP6RValueiz+0x68>
 *   @0x1624ec cmp r0, #0
 *   @0x1624f0 ble 0x162528 <_Z12ValidateArgsiP6RValueiz+0x54>
 *   @0x1624f4 add r3, sp, #24
 *   @0x1624f8 mov r2, #0
 *   @0x1624fc add r12, sp, #20
 *   @0x162500 str r12, [sp, #0x4]
 *   @0x162504 ldr r4, [r1, #0xc]
 *   @0x162508 add r2, r2, #1
 *   @0x16250c ldr r12, [r3, #-0x4]
 *   @0x162510 add r1, r1, #16
 *   @0x162514 add r3, r3, #4
 *   @0x162518 cmp r4, r12
 *   @0x16251c bne 0x162560 <_Z12ValidateArgsiP6RValueiz+0x8c>
 *   @0x162520 cmp r2, r0
 *   @0x162524 bne 0x162504 <_Z12ValidateArgsiP6RValueiz+0x30>
 *   @0x162528 mov r0, #1
 *   @0x16252c add sp, sp, #8
 *   @0x162530 pop {r4, lr}
 *   @0x162534 add sp, sp, #8
 *   @0x162538 bx lr
 *   @0x16253c ldr r0, [pc, #0x40]
 *   @0x162540 mov r1, #0
 *   @0x162544 add r0, pc, r0
 *   @0x162548 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x16254c mov r0, #0
 *   @0x162550 add sp, sp, #8
 *   @0x162554 pop {r4, lr}
 *   @0x162558 add sp, sp, #8
 *   @0x16255c bx lr
 *   @0x162560 ldr r0, [pc, #0x20]
 *   @0x162564 mov r1, #0
 *   @0x162568 add r0, pc, r0
 *   @0x16256c bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x162570 mov r0, #0
 *   @0x162574 add sp, sp, #8
 *   @0x162578 pop {r4, lr}
 *   @0x16257c add sp, sp, #8
 *   @0x162580 bx lr
 *   @0x162584 andseq r4, lr, r4, lsl #1
 *   @0x162588 andseq r0, lr, r4, asr #8
 *
 * ══ §13/168 Graphics::CreateTextureFromData(unsigned char*, int, int, ImageInfo*, eTextureFormat)  0x183188  size 184  46 条（0x183188..0x183240）
 * @func 0x183188 0x183240  size 184  46 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetPOW2Size(int)×2 / Graphics::CreateTexture(int, int, int, eTextureFlags, eTextureFormat) / Graphics::CopySurface(void*, int, int, int, void*)
 * 字段偏移 top8: 0x7c×1 / 0x14×1 / 0xc×1 / 0x8×1 / 0x18×1 / 0x10×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x183188 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x18318c mov r9, r0
 *   @0x183190 sub sp, sp, #12
 *   @0x183194 mov r0, r1
 *   @0x183198 mov r4, r3
 *   @0x18319c mov r5, r2
 *   @0x1831a0 mov r6, r1
 *   @0x1831a4 bl 0x181320 <_Z11GetPOW2Sizei>
 *   @0x1831a8 mov r7, #0
 *   @0x1831ac mov r8, r0
 *   @0x1831b0 mov r0, r5
 *   @0x1831b4 bl 0x181320 <_Z11GetPOW2Sizei>
 *   @0x1831b8 ldr r3, [pc, #0x7c]
 *   @0x1831bc mvn r2, #0
 *   @0x1831c0 str r2, [r4, #0x14]
 *   @0x1831c4 ldr r3, [pc, r3]
 *   @0x1831c8 str r7, [r4, #0xc]
 *   @0x1831cc mov r1, #32
 *   @0x1831d0 str r1, [r4, #0x8]
 *   @0x1831d4 ldrb r2, [r3]
 *   @0x1831d8 mov r1, r5
 *   @0x1831dc mov r3, #6
 *   @0x1831e0 str r3, [r4, #0x18]
 *   @0x1831e4 cmp r2, r7
 *   @0x1831e8 str r3, [r4, #0x10]
 *   @0x1831ec mov r2, r7
 *   @0x1831f0 str r3, [sp]
 *   @0x1831f4 movne r8, r6
 *   @0x1831f8 mov r3, r7
 *   @0x1831fc str r8, [r4]
 *   @0x183200 moveq r12, r0
 *   @0x183204 movne r12, r5
 *   @0x183208 mov r0, r6
 *   @0x18320c str r12, [r4, #0x4]
 *   @0x183210 bl 0x18269c <_ZN8Graphics13CreateTextureEiii13eTextureFlags14eTextureFormat>
 *   @0x183214 subs r4, r0, #0
 *   @0x183218 beq 0x183230 <_ZN8Graphics21CreateTextureFromDataEPhiiP9ImageInfo14eTextureFormat+0xa8>
 *   @0x18321c str r9, [sp]
 *   @0x183220 mov r1, r7
 *   @0x183224 mov r2, r6
 *   @0x183228 mov r3, r5
 *   @0x18322c bl 0x183000 <_ZN8Graphics11CopySurfaceEPviiiS0_>
 *   @0x183230 mov r0, r4
 *   @0x183234 add sp, sp, #12
 *   @0x183238 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x18323c eoreq sp, r6, r8, asr r2
 *
 * ══ §14/168 GMGamePad::ButtonPressed(int) const  0x18ebd8  size 184  46 条（0x18ebd8..0x18ec90）
 * @func 0x18ebd8 0x18eca4  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GMGamePad::ButtonPressed(int) const+0xac×4 / GMGamePad::GetButtonValueFromAxis(int, float*) const×2
 * 字段偏移 top8: 0x4×1 / 0x10×1 / 0xc×1 / 0x14×1 / 0x18×1
 * VFP 指令 17 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18ebd8 push {r3, r4, r5, lr}
 *   @0x18ebdc vpush {d8}
 *   @0x18ebe0 subs r4, r1, #0
 *   @0x18ebe4 mov r5, r0
 *   @0x18ebe8 blt 0x18ec84 <_ZNK9GMGamePad13ButtonPressedEi+0xac>
 *   @0x18ebec ands r2, r4, #4096
 *   @0x18ebf0 bne 0x18ec48 <_ZNK9GMGamePad13ButtonPressedEi+0x70>
 *   @0x18ebf4 ldr r3, [r0, #0x4]
 *   @0x18ebf8 cmp r4, r3
 *   @0x18ebfc movge r0, r2
 *   @0x18ec00 bge 0x18ec40 <_ZNK9GMGamePad13ButtonPressedEi+0x68>
 *   @0x18ec04 ldr r3, [r5, #0x10]
 *   @0x18ec08 lsl r4, r4, #2
 *   @0x18ec0c vldr s15, [r5, #28]
 *   @0x18ec10 add r3, r3, r4
 *   @0x18ec14 vldr s14, [r3]
 *   @0x18ec18 vcmpe.f32 s14, s15
 *   @0x18ec1c vmrs APSR_nzcv, fpscr
 *   @0x18ec20 blt 0x18ec84 <_ZNK9GMGamePad13ButtonPressedEi+0xac>
 *   @0x18ec24 ldr r3, [r5, #0xc]
 *   @0x18ec28 add r4, r3, r4
 *   @0x18ec2c vldr s14, [r4]
 *   @0x18ec30 vcmpe.f32 s15, s14
 *   @0x18ec34 vmrs APSR_nzcv, fpscr
 *   @0x18ec38 ble 0x18ec84 <_ZNK9GMGamePad13ButtonPressedEi+0xac>
 *   @0x18ec3c mov r0, #1
 *   @0x18ec40 vpop {d8}
 *   @0x18ec44 pop {r3, r4, r5, pc}
 *   @0x18ec48 ldr r2, [r0, #0x14]
 *   @0x18ec4c bl 0x18eae4 <_ZNK9GMGamePad22GetButtonValueFromAxisEiPf>
 *   @0x18ec50 mov r1, r4
 *   @0x18ec54 ldr r2, [r5, #0x18]
 *   @0x18ec58 vmov s16, r0
 *   @0x18ec5c mov r0, r5
 *   @0x18ec60 bl 0x18eae4 <_ZNK9GMGamePad22GetButtonValueFromAxisEiPf>
 *   @0x18ec64 vldr s15, [r5, #28]
 *   @0x18ec68 vcmpe.f32 s16, s15
 *   @0x18ec6c vmrs APSR_nzcv, fpscr
 *   @0x18ec70 vmov s14, r0
 *   @0x18ec74 blt 0x18ec84 <_ZNK9GMGamePad13ButtonPressedEi+0xac>
 *   @0x18ec78 vcmpe.f32 s14, s15
 *   @0x18ec7c vmrs APSR_nzcv, fpscr
 *   @0x18ec80 bmi 0x18ec3c <_ZNK9GMGamePad13ButtonPressedEi+0x64>
 *   @0x18ec84 vpop {d8}
 *   @0x18ec88 mov r0, #0
 *   @0x18ec8c pop {r3, r4, r5, pc}
 *
 * ══ §15/168 GMGamePad::ButtonReleased(int) const  0x18ec90  size 184  46 条（0x18ec90..0x18ed48）
 * @func 0x18ec90 0x18ed48  size 184  46 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GMGamePad::GetButtonValueFromAxis(int, float*) const×2 / GMGamePad::ButtonReleased(int) const+0xac
 * 字段偏移 top8: 0x4×1 / 0x10×1 / 0xc×1 / 0x14×1 / 0x18×1
 * VFP 指令 17 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18ec90 push {r3, r4, r5, lr}
 *   @0x18ec94 vpush {d8}
 *   @0x18ec98 subs r4, r1, #0
 *   @0x18ec9c mov r5, r0
 *   @0x18eca0 blt 0x18ed3c <_ZNK9GMGamePad14ButtonReleasedEi+0xac>
 *   @0x18eca4 ands r2, r4, #4096
 *   @0x18eca8 bne 0x18ed00 <_ZNK9GMGamePad14ButtonReleasedEi+0x70>
 *   @0x18ecac ldr r3, [r0, #0x4]
 *   @0x18ecb0 cmp r4, r3
 *   @0x18ecb4 movge r0, r2
 *   @0x18ecb8 bge 0x18ecf8 <_ZNK9GMGamePad14ButtonReleasedEi+0x68>
 *   @0x18ecbc ldr r3, [r5, #0x10]
 *   @0x18ecc0 lsl r4, r4, #2
 *   @0x18ecc4 vldr s15, [r5, #28]
 *   @0x18ecc8 add r3, r3, r4
 *   @0x18eccc vldr s14, [r3]
 *   @0x18ecd0 vcmpe.f32 s14, s15
 *   @0x18ecd4 vmrs APSR_nzcv, fpscr
 *   @0x18ecd8 bpl 0x18ed3c <_ZNK9GMGamePad14ButtonReleasedEi+0xac>
 *   @0x18ecdc ldr r3, [r5, #0xc]
 *   @0x18ece0 add r4, r3, r4
 *   @0x18ece4 vldr s14, [r4]
 *   @0x18ece8 vcmpe.f32 s15, s14
 *   @0x18ecec vmrs APSR_nzcv, fpscr
 *   @0x18ecf0 bhi 0x18ed3c <_ZNK9GMGamePad14ButtonReleasedEi+0xac>
 *   @0x18ecf4 mov r0, #1
 *   @0x18ecf8 vpop {d8}
 *   @0x18ecfc pop {r3, r4, r5, pc}
 *   @0x18ed00 ldr r2, [r0, #0x14]
 *   @0x18ed04 bl 0x18eae4 <_ZNK9GMGamePad22GetButtonValueFromAxisEiPf>
 *   @0x18ed08 mov r1, r4
 *   @0x18ed0c ldr r2, [r5, #0x18]
 *   @0x18ed10 vmov s16, r0
 *   @0x18ed14 mov r0, r5
 *   @0x18ed18 bl 0x18eae4 <_ZNK9GMGamePad22GetButtonValueFromAxisEiPf>
 *   @0x18ed1c vldr s15, [r5, #28]
 *   @0x18ed20 vcmpe.f32 s16, s15
 *   @0x18ed24 vmrs APSR_nzcv, fpscr
 *   @0x18ed28 vmov s14, r0
 *   @0x18ed2c bpl 0x18ed3c <_ZNK9GMGamePad14ButtonReleasedEi+0xac>
 *   @0x18ed30 vcmpe.f32 s14, s15
 *   @0x18ed34 vmrs APSR_nzcv, fpscr
 *   @0x18ed38 bge 0x18ecf4 <_ZNK9GMGamePad14ButtonReleasedEi+0x64>
 *   @0x18ed3c vpop {d8}
 *   @0x18ed40 mov r0, #0
 *   @0x18ed44 pop {r3, r4, r5, pc}
 *
 * ══ §16/168 LoadSave::HTTP_Post(char const*, char const*, int (*)(HTTP_REQ_CONTEXT*, void*, int*), void (*)(HTTP_REQ_CONTEXT*), void*)  0x18fd00  size 184  46 条（0x18fd00..0x18fdb8）
 * @func 0x18fd00 0x18fdb8  size 184  46 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×3 / operator new(unsigned int) / HTTP_REQ_CONTEXT::HTTP_REQ_CONTEXT(char const*, int, int (*)(HTTP_REQ_CONTEXT*, void*, int*), void (*)(HTTP_REQ_CONTEXT*), void*, bool) / _JNIEnv::CallStaticVoidMethod(_jclass*, _jmethodID*, ...)
 * 字段偏移 top8: 0x4×2 / 0x29c×2 / 0x30×1 / 0x8×1 / 0x2c×1 / 0x28×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18fd00 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x18fd04 sub sp, sp, #20
 *   @0x18fd08 mov r4, r0
 *   @0x18fd0c mov r0, #68
 *   @0x18fd10 ldr r5, [sp, #0x30]
 *   @0x18fd14 mov r8, r2
 *   @0x18fd18 mov r7, r1
 *   @0x18fd1c mov r9, r3
 *   @0x18fd20 bl 0x27c524 <_Znwj>
 *   @0x18fd24 mov r12, #0
 *   @0x18fd28 mov r2, #131072
 *   @0x18fd2c str r12, [sp, #0x8]
 *   @0x18fd30 mov r3, r8
 *   @0x18fd34 mov r1, r4
 *   @0x18fd38 str r5, [sp, #0x4]
 *   @0x18fd3c str r9, [sp]
 *   @0x18fd40 mov r6, r0
 *   @0x18fd44 bl 0x18d834 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b>
 *   @0x18fd48 bl 0x290274 <getJNIEnv>
 *   @0x18fd4c mov r1, r4
 *   @0x18fd50 ldr r3, [r0]
 *   @0x18fd54 ldr r3, [r3, #0x29c]
 *   @0x18fd58 blx r3
 *   @0x18fd5c mov r5, r0
 *   @0x18fd60 bl 0x290274 <getJNIEnv>
 *   @0x18fd64 mov r1, r7
 *   @0x18fd68 ldr r3, [r0]
 *   @0x18fd6c ldr r3, [r3, #0x29c]
 *   @0x18fd70 blx r3
 *   @0x18fd74 mov r4, r0
 *   @0x18fd78 bl 0x290274 <getJNIEnv>
 *   @0x18fd7c ldr r1, [pc, #0x2c]
 *   @0x18fd80 mov r3, r5
 *   @0x18fd84 ldr r2, [pc, #0x28]
 *   @0x18fd88 ldr r1, [pc, r1]
 *   @0x18fd8c ldr r2, [pc, r2]
 *   @0x18fd90 ldr r1, [r1]
 *   @0x18fd94 ldr r2, [r2]
 *   @0x18fd98 str r4, [sp]
 *   @0x18fd9c ldr r12, [r6, #0x24]
 *   @0x18fda0 str r12, [sp, #0x4]
 *   @0x18fda4 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x18fda8 add sp, sp, #20
 *   @0x18fdac pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x18fdb0 eoreq sp, r5, r12, lsl r12
 *   @0x18fdb4 .word 0x002608d4
 *
 * ══ §17/168 Path_Assign(int, int)  0x1a8460  size 184  46 条（0x1a8460..0x1a8518）
 * @func 0x1a8460 0x1a8518  size 184  46 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Path_Assign(int, int)+0x7c×3 / CPath::Assign(CPath*) / Error_Show_Action(char const*, bool) / operator new(unsigned int) / CPath::CPath()
 * 字段偏移 top8: 0x2×5 / 0x4×3 / 0x94×1 / 0x84×1 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a8460 push {r3, r4, r5, r6, r7, lr}
 *   @0x1a8464 subs r4, r1, #0
 *   @0x1a8468 mov r5, r0
 *   @0x1a846c blt 0x1a84dc <_Z11Path_Assignii+0x7c>
 *   @0x1a8470 ldr r3, [pc, #0x94]
 *   @0x1a8474 ldr r3, [pc, r3]
 *   @0x1a8478 ldr r3, [r3]
 *   @0x1a847c cmp r4, r3
 *   @0x1a8480 bge 0x1a84dc <_Z11Path_Assignii+0x7c>
 *   @0x1a8484 ldr r6, [pc, #0x84]
 *   @0x1a8488 add r6, pc, r6
 *   @0x1a848c ldr r2, [r6, #0x4]
 *   @0x1a8490 ldr r1, [r2, r4, lsl #2]
 *   @0x1a8494 cmp r1, #0
 *   @0x1a8498 beq 0x1a84dc <_Z11Path_Assignii+0x7c>
 *   @0x1a849c cmp r0, #0
 *   @0x1a84a0 blt 0x1a84dc <_Z11Path_Assignii+0x7c>
 *   @0x1a84a4 cmp r3, r0
 *   @0x1a84a8 ble 0x1a84dc <_Z11Path_Assignii+0x7c>
 *   @0x1a84ac cmp r0, r4
 *   @0x1a84b0 beq 0x1a84cc <_Z11Path_Assignii+0x6c>
 *   @0x1a84b4 ldr r0, [r2, r0, lsl #2]
 *   @0x1a84b8 cmp r0, #0
 *   @0x1a84bc beq 0x1a84e4 <_Z11Path_Assignii+0x84>
 *   @0x1a84c0 bl 0x1a6ed0 <_ZN5CPath6AssignEPS_>
 *   @0x1a84c4 mov r0, #1
 *   @0x1a84c8 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1a84cc ldr r0, [pc, #0x40]
 *   @0x1a84d0 mov r1, #0
 *   @0x1a84d4 add r0, pc, r0
 *   @0x1a84d8 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1a84dc mov r0, #0
 *   @0x1a84e0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1a84e4 mov r0, #44
 *   @0x1a84e8 bl 0x27c524 <_Znwj>
 *   @0x1a84ec mov r7, r0
 *   @0x1a84f0 bl 0x1a6e9c <_ZN5CPathC2Ev>
 *   @0x1a84f4 ldr r3, [r6, #0x4]
 *   @0x1a84f8 str r7, [r3, r5, lsl #2]
 *   @0x1a84fc ldr r3, [r6, #0x4]
 *   @0x1a8500 ldr r0, [r3, r5, lsl #2]
 *   @0x1a8504 ldr r1, [r3, r4, lsl #2]
 *   @0x1a8508 b 0x1a84c0 <_Z11Path_Assignii+0x60>
 *   @0x1a850c eoreq r8, r4, r8, asr r3
 *   @0x1a8510 eorseq r10, r9, r0, lsr #1
 *   @0x1a8514 andseq r4, r10, r8, ror r12
 *
 * ══ §18/168 F_TilemapSetMask(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bf0a8  size 184  46 条（0x1bf0a8..0x1bf160）
 * @func 0x1bf0a8 0x1bf160  size 184  46 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / YYGetUint32(RValue const*, int)
 * 字段偏移 top8: 0xc×2 / 0x34×2 / 0x10×1 / 0x4×1 / 0x7c×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bf0a8 cmp r3, #2
 *   @0x1bf0ac mov r3, #0
 *   @0x1bf0b0 push {r4, r5, r6, lr}
 *   @0x1bf0b4 mov r4, r3
 *   @0x1bf0b8 ldr r5, [sp, #0x10]
 *   @0x1bf0bc movt r3, #0xbff0
 *   @0x1bf0c0 str r4, [r0, #0xc]
 *   @0x1bf0c4 str r3, [r0, #0x4]
 *   @0x1bf0c8 str r4, [r0]
 *   @0x1bf0cc beq 0x1bf0e4 <_Z16F_TilemapSetMaskR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bf0d0 ldr r0, [pc, #0x7c]
 *   @0x1bf0d4 mov r1, r4
 *   @0x1bf0d8 pop {r4, r5, r6, lr}
 *   @0x1bf0dc add r0, pc, r0
 *   @0x1bf0e0 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bf0e4 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bf0e8 mov r1, r4
 *   @0x1bf0ec mov r6, r0
 *   @0x1bf0f0 mov r0, r5
 *   @0x1bf0f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bf0f8 mov r2, r4
 *   @0x1bf0fc mov r1, r0
 *   @0x1bf100 mov r0, r6
 *   @0x1bf104 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bf108 subs r4, r0, #0
 *   @0x1bf10c beq 0x1bf11c <_Z16F_TilemapSetMaskR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x1bf110 ldr r3, [r4]
 *   @0x1bf114 cmp r3, #5
 *   @0x1bf118 beq 0x1bf140 <_Z16F_TilemapSetMaskR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x1bf11c ldr r3, [pc, #0x34]
 *   @0x1bf120 ldr r1, [pc, #0x34]
 *   @0x1bf124 ldr r3, [pc, r3]
 *   @0x1bf128 add r1, pc, r1
 *   @0x1bf12c ldr r0, [r3]
 *   @0x1bf130 ldr r3, [r0]
 *   @0x1bf134 ldr r3, [r3, #0xc]
 *   @0x1bf138 blx r3
 *   @0x1bf13c pop {r4, r5, r6, pc}
 *   @0x1bf140 mov r0, r5
 *   @0x1bf144 mov r1, #1
 *   @0x1bf148 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x1bf14c str r0, [r4, #0x38]
 *   @0x1bf150 pop {r4, r5, r6, pc}
 *   @0x1bf154 andseq pc, r8, r0, asr #30
 *   @0x1bf158 .word 0x0022e5f0
 *   @0x1bf15c andseq pc, r8, r4, lsr #30
 *
 * ══ §19/168 _GetNumEntriesInLine(char*)  0x212fec  size 184  46 条（0x212fec..0x2130a4）
 * @func 0x212fec 0x2130a4  size 184  46 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x212fec push {r4, r5}
 *   @0x212ff0 mov r4, r0
 *   @0x212ff4 ldrb r3, [r0]
 *   @0x212ff8 cmp r3, #0
 *   @0x212ffc beq 0x21309c <_Z20_GetNumEntriesInLinePc+0xb0>
 *   @0x213000 mov r1, #0
 *   @0x213004 mov r2, r0
 *   @0x213008 mov r12, r1
 *   @0x21300c mov r0, #1
 *   @0x213010 b 0x213030 <_Z20_GetNumEntriesInLinePc+0x44>
 *   @0x213014 cmp r3, #34
 *   @0x213018 beq 0x213060 <_Z20_GetNumEntriesInLinePc+0x74>
 *   @0x21301c ldrb r3, [r2, #0x1]
 *   @0x213020 mov r1, #0
 *   @0x213024 cmp r3, #0
 *   @0x213028 add r2, r2, #1
 *   @0x21302c beq 0x213058 <_Z20_GetNumEntriesInLinePc+0x6c>
 *   @0x213030 cmp r3, #44
 *   @0x213034 bne 0x213014 <_Z20_GetNumEntriesInLinePc+0x28>
 *   @0x213038 cmp r12, #0
 *   @0x21303c bne 0x21301c <_Z20_GetNumEntriesInLinePc+0x30>
 *   @0x213040 ldrb r3, [r2, #0x1]
 *   @0x213044 add r0, r0, #1
 *   @0x213048 mov r1, #1
 *   @0x21304c add r2, r2, #1
 *   @0x213050 cmp r3, #0
 *   @0x213054 bne 0x213030 <_Z20_GetNumEntriesInLinePc+0x44>
 *   @0x213058 pop {r4, r5}
 *   @0x21305c bx lr
 *   @0x213060 cmp r12, #0
 *   @0x213064 ldrb r3, [r2, #0x1]
 *   @0x213068 beq 0x213080 <_Z20_GetNumEntriesInLinePc+0x94>
 *   @0x21306c cmp r3, #44
 *   @0x213070 cmpne r3, #0
 *   @0x213074 moveq r1, #0
 *   @0x213078 moveq r12, r1
 *   @0x21307c beq 0x213024 <_Z20_GetNumEntriesInLinePc+0x38>
 *   @0x213080 cmp r2, r4
 *   @0x213084 movne r5, r1
 *   @0x213088 orreq r5, r1, #1
 *   @0x21308c mov r1, #0
 *   @0x213090 cmp r5, r1
 *   @0x213094 movne r12, #1
 *   @0x213098 b 0x213024 <_Z20_GetNumEntriesInLinePc+0x38>
 *   @0x21309c mov r0, #1
 *   @0x2130a0 b 0x213058 <_Z20_GetNumEntriesInLinePc+0x6c>
 *
 * ══ §20/168 CSound::Clear()  0x21529c  size 184  46 条（0x21529c..0x215354）
 * @func 0x21529c 0x215354  size 184  46 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×3 / CStream::Free() / CSound::Clear()+0x94 / SND_Delete(int)
 * 字段偏移 top8: 0x8×2 / 0xc×2 / 0x10×2 / 0x30×2 / 0x34×2 / 0x4×1 / 0x18×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21529c push {r4, r5, r6, lr}
 *   @0x2152a0 mov r6, r0
 *   @0x2152a4 ldr r0, [r0, #0x8]
 *   @0x2152a8 mvn r3, #0
 *   @0x2152ac str r3, [r6, #0x4]
 *   @0x2152b0 cmp r0, #0
 *   @0x2152b4 beq 0x2152c4 <_ZN6CSound5ClearEv+0x28>
 *   @0x2152b8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2152bc mov r3, #0
 *   @0x2152c0 str r3, [r6, #0x8]
 *   @0x2152c4 ldr r0, [r6, #0xc]
 *   @0x2152c8 cmp r0, #0
 *   @0x2152cc beq 0x2152dc <_ZN6CSound5ClearEv+0x40>
 *   @0x2152d0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2152d4 mov r3, #0
 *   @0x2152d8 str r3, [r6, #0xc]
 *   @0x2152dc ldr r0, [r6, #0x10]
 *   @0x2152e0 mov r1, #0
 *   @0x2152e4 mov r2, #0
 *   @0x2152e8 mov r3, #0
 *   @0x2152ec cmp r0, r1
 *   @0x2152f0 movt r3, #0x3ff0
 *   @0x2152f4 mov r4, #0
 *   @0x2152f8 mov r5, #0
 *   @0x2152fc str r1, [r6, #0x18]
 *   @0x215300 mov r1, #1
 *   @0x215304 strd r4, r5, [r6, #40]
 *   @0x215308 strb r1, [r6, #0x14]
 *   @0x21530c strd r2, r3, [r6, #32]
 *   @0x215310 beq 0x215318 <_ZN6CSound5ClearEv+0x7c>
 *   @0x215314 bl 0x20133c <_ZN7CStream4FreeEv>
 *   @0x215318 ldr r0, [r6, #0x30]
 *   @0x21531c mov r3, #0
 *   @0x215320 str r3, [r6, #0x10]
 *   @0x215324 cmp r0, r3
 *   @0x215328 blt 0x215330 <_ZN6CSound5ClearEv+0x94>
 *   @0x21532c bl 0x21eadc <_Z10SND_Deletei>
 *   @0x215330 ldr r0, [r6, #0x34]
 *   @0x215334 mvn r3, #0
 *   @0x215338 str r3, [r6, #0x30]
 *   @0x21533c cmp r0, #0
 *   @0x215340 popeq {r4, r5, r6, pc}
 *   @0x215344 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x215348 mov r3, #0
 *   @0x21534c str r3, [r6, #0x34]
 *   @0x215350 pop {r4, r5, r6, pc}
 *
 * ══ §21/168 ov_time_total  0x231424  size 184  46 条（0x231424..0x2314dc）
 * @func 0x231424 0x2314dc  size 184  46 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ov_time_total+0xac×2 / ov_time_total+0x68 / anon_319414 / ov_time_total+0xa0 / ov_time_total / ov_time_total+0x7c
 * 字段偏移 top8: 0x34×2 / 0x8×2 / 0x58×1 / 0x4×1 / 0x44×1 / 0x48×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x231424 push {r3, r4, r5, r6, r7, lr}
 *   @0x231428 mov r6, r0
 *   @0x23142c ldr r3, [r0, #0x58]
 *   @0x231430 cmp r3, #1
 *   @0x231434 ble 0x2314d0 <ov_time_total+0xac>
 *   @0x231438 ldr r3, [r0, #0x4]
 *   @0x23143c cmp r3, #0
 *   @0x231440 beq 0x2314d0 <ov_time_total+0xac>
 *   @0x231444 ldr r3, [r0, #0x34]
 *   @0x231448 cmp r3, r1
 *   @0x23144c ble 0x2314d0 <ov_time_total+0xac>
 *   @0x231450 cmp r1, #0
 *   @0x231454 blt 0x23148c <ov_time_total+0x68>
 *   @0x231458 ldr r3, [r0, #0x44]
 *   @0x23145c mov r12, #1000
 *   @0x231460 ldr r2, [r0, #0x48]
 *   @0x231464 add r3, r3, r1, lsl #4
 *   @0x231468 add r1, r2, r1, lsl #5
 *   @0x23146c ldr r0, [r3, #0x8]
 *   @0x231470 ldr r2, [r1, #0x8]
 *   @0x231474 ldr lr, [r3, #0xc]
 *   @0x231478 umull r0, r1, r0, r12
 *   @0x23147c asr r3, r2, #31
 *   @0x231480 mla r1, r12, lr, r1
 *   @0x231484 bl 0x319414 <__aeabi_ldivmod>
 *   @0x231488 pop {r3, r4, r5, r6, r7, pc}
 *   @0x23148c cmp r3, #0
 *   @0x231490 mov r4, #0
 *   @0x231494 mov r5, #0
 *   @0x231498 ble 0x2314c4 <ov_time_total+0xa0>
 *   @0x23149c mov r7, #0
 *   @0x2314a0 mov r1, r7
 *   @0x2314a4 mov r0, r6
 *   @0x2314a8 bl 0x231424 <ov_time_total>
 *   @0x2314ac ldr r3, [r6, #0x34]
 *   @0x2314b0 add r7, r7, #1
 *   @0x2314b4 adds r4, r4, r0
 *   @0x2314b8 adc r5, r5, r1
 *   @0x2314bc cmp r7, r3
 *   @0x2314c0 blt 0x2314a0 <ov_time_total+0x7c>
 *   @0x2314c4 mov r0, r4
 *   @0x2314c8 mov r1, r5
 *   @0x2314cc pop {r3, r4, r5, r6, r7, pc}
 *   @0x2314d0 mvn r0, #130
 *   @0x2314d4 mvn r1, #0
 *   @0x2314d8 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §22/168 CPhysicsObject::ApplyLocalForce(float, float, float, float)  0x2370d8  size 184  46 条（0x2370d8..0x237190）
 * @func 0x2370d8 0x237190  size 184  46 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0xa0×1
 * VFP 指令 33 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2370d8 ldr r0, [r0]
 *   @0x2370dc vmov s13, r1
 *   @0x2370e0 vldr s15, [r0, #24]
 *   @0x2370e4 vldr s14, [r0, #20]
 *   @0x2370e8 vldr s9, [r0, #12]
 *   @0x2370ec vldr s8, [r0, #16]
 *   @0x2370f0 ldr r1, [r0]
 *   @0x2370f4 vmov s12, r2
 *   @0x2370f8 vmov s11, r3
 *   @0x2370fc cmp r1, #2
 *   @0x237100 bxne lr
 *   @0x237104 ldrh r3, [r0, #4]
 *   @0x237108 tst r3, #2
 *   @0x23710c beq 0x23717c <_ZN14CPhysicsObject15ApplyLocalForceEffff+0xa4>
 *   @0x237110 vmul.f32 s7, s12, s15
 *   @0x237114 vldr s1, [sp]
 *   @0x237118 vldr s2, [r0, #64]
 *   @0x23711c vldr s3, [r0, #60]
 *   @0x237120 vldr s5, [r0, #100]
 *   @0x237124 vldr s4, [r0, #92]
 *   @0x237128 vldr s6, [r0, #96]
 *   @0x23712c vmla.f32 s7, s13, s14
 *   @0x237130 vmul.f32 s12, s12, s14
 *   @0x237134 vmul.f32 s10, s1, s14
 *   @0x237138 vnmls.f32 s12, s13, s15
 *   @0x23713c vnmls.f32 s10, s11, s15
 *   @0x237140 vmul.f32 s15, s1, s15
 *   @0x237144 vadd.f32 s8, s7, s8
 *   @0x237148 vsub.f32 s8, s8, s2
 *   @0x23714c vmla.f32 s15, s11, s14
 *   @0x237150 vadd.f32 s12, s12, s9
 *   @0x237154 vmul.f32 s8, s10, s8
 *   @0x237158 vsub.f32 s12, s12, s3
 *   @0x23715c vnmls.f32 s8, s15, s12
 *   @0x237160 vadd.f32 s10, s4, s10
 *   @0x237164 vadd.f32 s8, s5, s8
 *   @0x237168 vstr s10, [r0, #92]
 *   @0x23716c vadd.f32 s15, s6, s15
 *   @0x237170 vstr s8, [r0, #100]
 *   @0x237174 vstr s15, [r0, #96]
 *   @0x237178 bx lr
 *   @0x23717c orr r3, r3, #2
 *   @0x237180 mov r2, #0
 *   @0x237184 strh r3, [r0, #4]
 *   @0x237188 str r2, [r0, #0xa0]
 *   @0x23718c b 0x237110 <_ZN14CPhysicsObject15ApplyLocalForceEffff+0x38>
 *
 * ══ §23/168 CPhysicsWorld::GetCurrentContactPosition(CInstance*, int, float&, float&)  0x238ce4  size 184  46 条（0x238ce4..0x238d9c）
 * @func 0x238ce4 0x238d9c  size 184  46 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsWorld::GetValidCollisionData(CInstance*) / CPhysicsWorld::GetCurrentContactPosition(CInstance*, int, float&, float&)+0x68
 * 字段偏移 top8: 0x48×1 / 0x88×1 / 0x18×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x238ce4 push {r3, r4, r5, r6, r7, lr}
 *   @0x238ce8 mov r7, r3
 *   @0x238cec mov r6, r2
 *   @0x238cf0 mov r4, r0
 *   @0x238cf4 bl 0x238cb0 <_ZN13CPhysicsWorld21GetValidCollisionDataEP9CInstance>
 *   @0x238cf8 subs r3, r0, #0
 *   @0x238cfc beq 0x238d4c <_ZN13CPhysicsWorld25GetCurrentContactPositionEP9CInstanceiRfS2_+0x68>
 *   @0x238d00 ldr r2, [r3]
 *   @0x238d04 vldr s15, [r4, #96]
 *   @0x238d08 cmp r2, #0
 *   @0x238d0c ble 0x238d4c <_ZN13CPhysicsWorld25GetCurrentContactPositionEP9CInstanceiRfS2_+0x68>
 *   @0x238d10 ldr r5, [r3, #0x48]
 *   @0x238d14 cmp r6, r5
 *   @0x238d18 movgt r12, r3
 *   @0x238d1c movgt r1, #0
 *   @0x238d20 bgt 0x238d40 <_ZN13CPhysicsWorld25GetCurrentContactPositionEP9CInstanceiRfS2_+0x5c>
 *   @0x238d24 b 0x238d54 <_ZN13CPhysicsWorld25GetCurrentContactPositionEP9CInstanceiRfS2_+0x70>
 *   @0x238d28 ldr r4, [r12, #0x88]
 *   @0x238d2c add r12, r12, #64
 *   @0x238d30 add r4, r5, r4
 *   @0x238d34 cmp r4, r6
 *   @0x238d38 bge 0x238d5c <_ZN13CPhysicsWorld25GetCurrentContactPositionEP9CInstanceiRfS2_+0x78>
 *   @0x238d3c mov r5, r4
 *   @0x238d40 add r1, r1, #1
 *   @0x238d44 cmp r1, r2
 *   @0x238d48 bne 0x238d28 <_ZN13CPhysicsWorld25GetCurrentContactPositionEP9CInstanceiRfS2_+0x44>
 *   @0x238d4c mov r0, #0
 *   @0x238d50 pop {r3, r4, r5, r6, r7, pc}
 *   @0x238d54 mov r1, #0
 *   @0x238d58 mov r5, r1
 *   @0x238d5c vmov.f32 s13, #1.000000e+00
 *   @0x238d60 add r1, r1, r1, lsl #1
 *   @0x238d64 rsb r5, r5, r6
 *   @0x238d68 mov r0, #1
 *   @0x238d6c add r3, r3, r1, lsl #3
 *   @0x238d70 add r3, r3, #524
 *   @0x238d74 add r5, r3, r5, lsl #3
 *   @0x238d78 vldr s14, [r5, #8]
 *   @0x238d7c ldr r3, [sp, #0x18]
 *   @0x238d80 vdiv.f32 s15, s13, s15
 *   @0x238d84 vmul.f32 s14, s14, s15
 *   @0x238d88 vstr s14, [r7]
 *   @0x238d8c vldr s14, [r5, #12]
 *   @0x238d90 vmul.f32 s15, s14, s15
 *   @0x238d94 vstr s15, [r3]
 *   @0x238d98 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §24/168 CPhysicsWorld::CreateParticle(unsigned int, float, float, float, float, unsigned int, float, int)  0x2398e4  size 184  46 条（0x2398e4..0x23999c）
 * @func 0x2398e4 0x23999c  size 184  46 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2World::CreateParticle(b2ParticleDef const&)
 * 字段偏移 top8: 0x88×1 / 0x40×1 / 0x48×1 / 0x4×1 / 0x18×1 / 0x19×1 / 0x10×1 / 0x1a×1
 * VFP 指令 18 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2398e4 push {r4, r5, r6, r7, r8, lr}
 *   @0x2398e8 vldr s14, [pc, #164]
 *   @0x2398ec sub sp, sp, #32
 *   @0x2398f0 vldr s11, [sp, #68]
 *   @0x2398f4 vmul.f32 s14, s11, s14
 *   @0x2398f8 vldr s15, [r0, #96]
 *   @0x2398fc vmov s9, r2
 *   @0x239900 vldr s13, [sp, #56]
 *   @0x239904 vldr s12, [sp, #60]
 *   @0x239908 ldr r12, [pc, #0x88]
 *   @0x23990c ldr lr, [sp, #0x40]
 *   @0x239910 mov r4, r0
 *   @0x239914 ldr r12, [pc, r12]
 *   @0x239918 mov r5, r1
 *   @0x23991c ldr r6, [sp, #0x48]
 *   @0x239920 ubfx r8, lr, #0x8, #0x8
 *   @0x239924 ldm r12, {r0, r1}
 *   @0x239928 add r12, sp, #16
 *   @0x23992c str r5, [sp, #0x4]
 *   @0x239930 add r5, sp, #8
 *   @0x239934 strb lr, [sp, #0x18]
 *   @0x239938 ubfx r7, lr, #0x10, #0x8
 *   @0x23993c stm r5, {r0, r1}
 *   @0x239940 strb r8, [sp, #0x19]
 *   @0x239944 stm r12, {r0, r1}
 *   @0x239948 add r1, sp, #4
 *   @0x23994c vcvt.s32.f32 s14, s14
 *   @0x239950 ldr r0, [r4, #0x10]
 *   @0x239954 strb r7, [sp, #0x1a]
 *   @0x239958 str r6, [sp, #0x1c]
 *   @0x23995c vmul.f32 s10, s15, s9
 *   @0x239960 vmov s9, r3
 *   @0x239964 vmov r3, s14
 *   @0x239968 vmul.f32 s11, s15, s9
 *   @0x23996c vstr s10, [sp, #8]
 *   @0x239970 strb r3, [sp, #0x1b]
 *   @0x239974 vmul.f32 s13, s15, s13
 *   @0x239978 vstr s11, [sp, #12]
 *   @0x23997c vmul.f32 s15, s15, s12
 *   @0x239980 vstr s13, [sp, #16]
 *   @0x239984 vstr s15, [sp, #20]
 *   @0x239988 bl 0x2cb4a4 <_ZN7b2World14CreateParticleERK13b2ParticleDef>
 *   @0x23998c add sp, sp, #32
 *   @0x239990 pop {r4, r5, r6, r7, r8, pc}
 *   @0x239994 cmnmi pc, #0
 *   @0x239998 andseq r7, r11, r4, asr #23
 *
 * ══ §25/168 UTF8_get_U16_at_pos(RValue&, int)  0x2424f4  size 184  46 条（0x2424f4..0x2425ac）
 * @func 0x2424f4 0x2425ac  size 184  46 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CCodepointIterator_UTF8::CCodepointIterator_UTF8(char const*) / CCodepointIterator_UTF8::GetNext() / CodepointToUTF16(int, unsigned short&, unsigned short&)
 * 字段偏移 top8: 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2424f4 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x2424f8 sub sp, sp, #20
 *   @0x2424fc ldr r3, [r0]
 *   @0x242500 add r6, sp, #4
 *   @0x242504 mov r5, r1
 *   @0x242508 add r7, sp, #2
 *   @0x24250c mov r0, r6
 *   @0x242510 mov r4, #0
 *   @0x242514 ldr r1, [r3]
 *   @0x242518 bl 0x2423d8 <_ZN23CCodepointIterator_UTF8C2EPKc>
 *   @0x24251c b 0x242524 <_Z19UTF8_get_U16_at_posR6RValuei+0x30>
 *   @0x242520 add r4, r4, r0
 *   @0x242524 mov r0, r6
 *   @0x242528 bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv>
 *   @0x24252c mov r1, sp
 *   @0x242530 mov r2, r7
 *   @0x242534 subs r9, r0, #0
 *   @0x242538 beq 0x242588 <_Z19UTF8_get_U16_at_posR6RValuei+0x94>
 *   @0x24253c bl 0x2424c4 <_Z16CodepointToUTF16iRtS_>
 *   @0x242540 subs r1, r4, r5
 *   @0x242544 rsbs r12, r1, #0
 *   @0x242548 adcs r12, r12, r1
 *   @0x24254c cmp r0, #1
 *   @0x242550 cmpeq r4, r5
 *   @0x242554 beq 0x242594 <_Z19UTF8_get_U16_at_posR6RValuei+0xa0>
 *   @0x242558 subs r2, r0, #2
 *   @0x24255c rsbs r3, r2, #0
 *   @0x242560 adcs r3, r3, r2
 *   @0x242564 tst r3, r12
 *   @0x242568 bne 0x2425a0 <_Z19UTF8_get_U16_at_posR6RValuei+0xac>
 *   @0x24256c cmp r3, #0
 *   @0x242570 beq 0x242520 <_Z19UTF8_get_U16_at_posR6RValuei+0x2c>
 *   @0x242574 add r3, r4, #1
 *   @0x242578 cmp r3, r5
 *   @0x24257c bne 0x242520 <_Z19UTF8_get_U16_at_posR6RValuei+0x2c>
 *   @0x242580 ldrh r0, [sp, #2]
 *   @0x242584 b 0x24258c <_Z19UTF8_get_U16_at_posR6RValuei+0x98>
 *   @0x242588 mov r0, r9
 *   @0x24258c add sp, sp, #20
 *   @0x242590 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x242594 uxth r0, r9
 *   @0x242598 add sp, sp, #20
 *   @0x24259c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x2425a0 ldrh r0, [sp]
 *   @0x2425a4 add sp, sp, #20
 *   @0x2425a8 pop {r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §26/168 F_JS_ToInteger(RValue&)  0x24d730  size 184  44 条（0x24d730..0x24d7e8）
 * @func 0x24d730 0x24d7e0  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_JS_ToNumber(RValue&, RValue&) / yyisinf(RValue&) / 0xb6598
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 21 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24d730 push {r4, lr}
 *   @0x24d734 vpush {d8}
 *   @0x24d738 sub sp, sp, #16
 *   @0x24d73c mov r1, r0
 *   @0x24d740 mov r2, #0
 *   @0x24d744 mov r0, sp
 *   @0x24d748 mov r3, #0
 *   @0x24d74c strd r2, r3, [sp]
 *   @0x24d750 mov r2, #0
 *   @0x24d754 mvn r3, #-16777216
 *   @0x24d758 str r2, [sp, #0x8]
 *   @0x24d75c str r3, [sp, #0xc]
 *   @0x24d760 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_>
 *   @0x24d764 vldr d7, [sp]
 *   @0x24d768 vcmp.f64 d7, d7
 *   @0x24d76c vmrs APSR_nzcv, fpscr
 *   @0x24d770 bvs 0x24d7cc <_Z14F_JS_ToIntegerR6RValue+0x9c>
 *   @0x24d774 mov r0, sp
 *   @0x24d778 bl 0x240970 <_Z7yyisinfR6RValue>
 *   @0x24d77c vldr d7, [sp]
 *   @0x24d780 cmp r0, #0
 *   @0x24d784 bne 0x24d7bc <_Z14F_JS_ToIntegerR6RValue+0x8c>
 *   @0x24d788 vcmp.f64 d7, #0
 *   @0x24d78c vmrs APSR_nzcv, fpscr
 *   @0x24d790 beq 0x24d7bc <_Z14F_JS_ToIntegerR6RValue+0x8c>
 *   @0x24d794 vmov.f64 d6, #1.000000e+00
 *   @0x24d798 vmov.f64 d8, #-1.000000e+00
 *   @0x24d79c vabs.f64 d5, d7
 *   @0x24d7a0 vcmpe.f64 d7, #0
 *   @0x24d7a4 vmov r0, r1, d5
 *   @0x24d7a8 vmrs APSR_nzcv, fpscr
 *   @0x24d7ac vmovpl.f64 d8, d6
 *   @0x24d7b0 bl 0xb6598 <floor@plt>
 *   @0x24d7b4 vmov d6, r0, r1
 *   @0x24d7b8 vmul.f64 d7, d8, d6
 *   @0x24d7bc vmov r0, r1, d7
 *   @0x24d7c0 add sp, sp, #16
 *   @0x24d7c4 vpop {d8}
 *   @0x24d7c8 pop {r4, pc}
 *   @0x24d7cc vldr d7, [pc, #12]
 *   @0x24d7d0 vmov r0, r1, d7
 *   @0x24d7d4 add sp, sp, #16
 *   @0x24d7d8 vpop {d8}
 *   @0x24d7dc pop {r4, pc}
 *
 * ══ §27/168 JS_Function_prototype_call(RValue&, CInstance*, CInstance*, int, RValue*)  0x24ea70  size 184  46 条（0x24ea70..0x24eb28）
 * @func 0x24ea70 0x24eb28  size 184  46 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_IsCallable_Object(YYObjectBase*) / F_JS_IsPrimitive(RValue&) / Call_ScriptRef(YYObjectBase*, RValue*, CScriptRef*, int, RValue*) / JSThrowTypeError(char const*) / F_JS_ToObject(RValue&, RValue*)
 * 字段偏移 top8: 0x38×1 / 0xc×1 / 0x7c×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24ea70 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x24ea74 sub sp, sp, #28
 *   @0x24ea78 mov r9, r0
 *   @0x24ea7c mov r0, r1
 *   @0x24ea80 mov r6, r1
 *   @0x24ea84 mov r8, r3
 *   @0x24ea88 ldr r4, [sp, #0x38]
 *   @0x24ea8c bl 0x240758 <_Z20JS_IsCallable_ObjectP12YYObjectBase>
 *   @0x24ea90 cmp r0, #0
 *   @0x24ea94 beq 0x24eaf0 <_Z26JS_Function_prototype_callR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x24ea98 ldr r3, [r4, #0xc]
 *   @0x24ea9c ldr r5, [pc, #0x7c]
 *   @0x24eaa0 bic r3, r3, #-16777216
 *   @0x24eaa4 ldr r5, [pc, r5]
 *   @0x24eaa8 cmp r3, #6
 *   @0x24eaac ldr r7, [r5]
 *   @0x24eab0 beq 0x24eae8 <_Z26JS_Function_prototype_callR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x24eab4 mov r0, r4
 *   @0x24eab8 bl 0x241dc0 <_Z16F_JS_IsPrimitiveR6RValue>
 *   @0x24eabc cmp r0, #0
 *   @0x24eac0 bne 0x24eb04 <_Z26JS_Function_prototype_callR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x24eac4 add r4, r4, #16
 *   @0x24eac8 mov r0, r7
 *   @0x24eacc str r4, [sp]
 *   @0x24ead0 mov r1, r9
 *   @0x24ead4 mov r2, r6
 *   @0x24ead8 sub r3, r8, #1
 *   @0x24eadc bl 0x249590 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_>
 *   @0x24eae0 add sp, sp, #28
 *   @0x24eae4 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x24eae8 ldr r7, [r4]
 *   @0x24eaec b 0x24eac4 <_Z26JS_Function_prototype_callR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x24eaf0 ldr r0, [pc, #0x2c]
 *   @0x24eaf4 add r0, pc, r0
 *   @0x24eaf8 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x24eafc add sp, sp, #28
 *   @0x24eb00 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x24eb04 add r0, sp, #8
 *   @0x24eb08 mov r1, r4
 *   @0x24eb0c bl 0x247388 <_Z13F_JS_ToObjectR6RValuePS_>
 *   @0x24eb10 cmp r0, #0
 *   @0x24eb14 ldrne r7, [r5]
 *   @0x24eb18 ldreq r7, [sp, #0x8]
 *   @0x24eb1c b 0x24eac4 <_Z26JS_Function_prototype_callR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x24eb20 andseq pc, r9, r4, lsl #4
 *   @0x24eb24 andseq r7, r0, r0, lsl #10
 *
 * ══ §28/168 JS_String_prototype_charCodeAt(RValue&, CInstance*, CInstance*, int, RValue*)  0x2554c0  size 184  46 条（0x2554c0..0x255578）
 * @func 0x2554c0 0x255578  size 184  46 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_CheckObjectCoercible(RValue&) / F_JS_ToString(RValue&, RValue*) / F_JS_ToInteger(RValue&) / UTF8_get_U16_at_pos(RValue&, int) / JSThrowTypeError(char const*)
 * 字段偏移 top8: 0xc×3 / 0x-20×1 / 0x18×1 / 0x1c×1 / 0x30×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2554c0 push {r4, r5, r6, lr}
 *   @0x2554c4 sub sp, sp, #32
 *   @0x2554c8 add r4, sp, #32
 *   @0x2554cc mov r5, r0
 *   @0x2554d0 mov r0, sp
 *   @0x2554d4 mov r3, #6
 *   @0x2554d8 str r1, [r4, #-0x20]!
 *   @0x2554dc str r3, [sp, #0xc]
 *   @0x2554e0 bl 0x2423a4 <_Z23JS_CheckObjectCoercibleR6RValue>
 *   @0x2554e4 cmp r0, #1
 *   @0x2554e8 beq 0x255560 <_Z30JS_String_prototype_charCodeAtR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x2554ec add r6, sp, #16
 *   @0x2554f0 mov r1, sp
 *   @0x2554f4 mov r2, #0
 *   @0x2554f8 mov r3, #0
 *   @0x2554fc mov r0, r6
 *   @0x255500 strd r2, r3, [sp, #16]
 *   @0x255504 mov r4, #0
 *   @0x255508 mvn r3, #-16777216
 *   @0x25550c str r4, [sp, #0x18]
 *   @0x255510 str r3, [sp, #0x1c]
 *   @0x255514 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x255518 cmp r0, #1
 *   @0x25551c beq 0x255560 <_Z30JS_String_prototype_charCodeAtR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x255520 ldr r0, [sp, #0x30]
 *   @0x255524 bl 0x24d730 <_Z14F_JS_ToIntegerR6RValue>
 *   @0x255528 str r4, [r5, #0xc]
 *   @0x25552c vmov d7, r0, r1
 *   @0x255530 mov r0, r6
 *   @0x255534 vcvt.s32.f64 s15, d7
 *   @0x255538 vmov r1, s15
 *   @0x25553c bl 0x2424f4 <_Z19UTF8_get_U16_at_posR6RValuei>
 *   @0x255540 vmov s15, r0
 *   @0x255544 vcvt.f64.u32 d7, s15
 *   @0x255548 vmov r0, r1, d7
 *   @0x25554c vmov r2, s14
 *   @0x255550 mov r3, r1
 *   @0x255554 stm r5, {r2, r3}
 *   @0x255558 add sp, sp, #32
 *   @0x25555c pop {r4, r5, r6, pc}
 *   @0x255560 ldr r0, [pc, #0xc]
 *   @0x255564 add r0, pc, r0
 *   @0x255568 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x25556c add sp, sp, #32
 *   @0x255570 pop {r4, r5, r6, pc}
 *   @0x255574 andseq r0, r0, r4, ror #19
 *
 * ══ §29/168 F_NETWORK_Send_UDP(RValue&, CInstance*, CInstance*, int, RValue*)  0x299e88  size 184  46 条（0x299e88..0x299f40）
 * @func 0x299e88 0x299f40  size 184  46 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×4 / YYGetString(RValue const*, int) / anon_299da0
 * 字段偏移 top8: 0xac×1 / 0xc×1 / 0x4×1 / 0x28×1
 * VFP 指令 2 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x299e88 ldr r3, [pc, #0xac]
 *   @0x299e8c mov r1, #0
 *   @0x299e90 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x299e94 ldr r3, [pc, r3]
 *   @0x299e98 str r1, [r0]
 *   @0x299e9c sub sp, sp, #12
 *   @0x299ea0 ldr r3, [r3]
 *   @0x299ea4 mov r2, r1
 *   @0x299ea8 mov r4, r0
 *   @0x299eac movt r2, #0xbff0
 *   @0x299eb0 sub r3, r3, #2
 *   @0x299eb4 str r1, [r0, #0xc]
 *   @0x299eb8 cmp r3, #2
 *   @0x299ebc str r2, [r0, #0x4]
 *   @0x299ec0 ldr r5, [sp, #0x28]
 *   @0x299ec4 bhi 0x299f34 <_Z18F_NETWORK_Send_UDPR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x299ec8 mov r0, r5
 *   @0x299ecc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x299ed0 mov r1, #1
 *   @0x299ed4 mov r6, r0
 *   @0x299ed8 mov r0, r5
 *   @0x299edc bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x299ee0 mov r1, #2
 *   @0x299ee4 mov r9, r0
 *   @0x299ee8 mov r0, r5
 *   @0x299eec bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x299ef0 mov r1, #3
 *   @0x299ef4 mov r8, r0
 *   @0x299ef8 mov r0, r5
 *   @0x299efc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x299f00 mov r1, #4
 *   @0x299f04 mov r7, r0
 *   @0x299f08 mov r0, r5
 *   @0x299f0c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x299f10 mov r12, #1
 *   @0x299f14 mov r1, r9
 *   @0x299f18 mov r2, r8
 *   @0x299f1c mov r3, r7
 *   @0x299f20 stm sp, {r0, r12}
 *   @0x299f24 mov r0, r6
 *   @0x299f28 bl 0x299da0 <_Z16RelySendReliableiPKciii+0x138>
 *   @0x299f2c vstr s0, [r4]
 *   @0x299f30 vstr s1, [r4, #4]
 *   @0x299f34 add sp, sp, #12
 *   @0x299f38 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x299f3c andseq r6, r5, r12, lsl #9
 *
 * ══ §30/168 DebuggerCreateIPSocket()  0x29ccc8  size 184  46 条（0x29ccc8..0x29cd80）
 * @func 0x29ccc8 0x29cd80  size 184  46 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_NETWORK_Create_Socket(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x30×2 / 0x9c×1 / 0x84×1 / 0x80×1 / 0xc×1 / 0x14×1 / 0x218×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29ccc8 ldr r3, [pc, #0x9c]
 *   @0x29cccc push {r4, r5, lr}
 *   @0x29ccd0 ldr r3, [pc, r3]
 *   @0x29ccd4 sub sp, sp, #44
 *   @0x29ccd8 ldr r3, [r3]
 *   @0x29ccdc cmp r3, #0
 *   @0x29cce0 beq 0x29cd64 <_Z22DebuggerCreateIPSocketv+0x9c>
 *   @0x29cce4 ldr r3, [pc, #0x84]
 *   @0x29cce8 mov r4, #0
 *   @0x29ccec ldr r1, [pc, #0x80]
 *   @0x29ccf0 mov r5, #0
 *   @0x29ccf4 ldr r3, [pc, r3]
 *   @0x29ccf8 movt r5, #0x3ff0
 *   @0x29ccfc add r1, pc, r1
 *   @0x29cd00 ldr r0, [r3]
 *   @0x29cd04 ldr r3, [r0]
 *   @0x29cd08 ldr r3, [r3, #0xc]
 *   @0x29cd0c blx r3
 *   @0x29cd10 mov r12, #0
 *   @0x29cd14 mov r1, r12
 *   @0x29cd18 add r3, sp, #8
 *   @0x29cd1c mov r2, r12
 *   @0x29cd20 str r3, [sp]
 *   @0x29cd24 add r0, sp, #24
 *   @0x29cd28 mov r3, #1
 *   @0x29cd2c str r12, [sp, #0x14]
 *   @0x29cd30 strd r4, r5, [sp, #8]
 *   @0x29cd34 bl 0x298e94 <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_>
 *   @0x29cd38 vldr d7, [sp, #24]
 *   @0x29cd3c vcvt.s32.f64 s13, d7
 *   @0x29cd40 ldr r2, [pc, #0x30]
 *   @0x29cd44 ldr r1, [pc, #0x30]
 *   @0x29cd48 add r2, pc, r2
 *   @0x29cd4c add r1, pc, r1
 *   @0x29cd50 vmov r3, s13
 *   @0x29cd54 vstr s13, [r1, #4]
 *   @0x29cd58 mvn r3, r3
 *   @0x29cd5c lsr r3, r3, #31
 *   @0x29cd60 strb r3, [r2, #0x218]
 *   @0x29cd64 add sp, sp, #44
 *   @0x29cd68 pop {r4, r5, pc}
 *   @0x29cd6c andseq r4, r5, r4, lsr #32
 *   @0x29cd70 andseq r0, r5, r12, asr #24
 *   @0x29cd74 andeq r12, r11, r0, asr #27
 *   @0x29cd78 subeq r10, r11, r0, asr #29
 *   @0x29cd7c andseq r10, r5, r4, asr #21
 *
 * ══ §31/168 af_shaper_get_cluster  0x30a6da  size 184  46 条（0x30a6da..0x30a792）
 * @func 0x30a6da 0x30a792  size 184  46 条
 * 部分覆盖: 本节 46/83 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FT_Get_Char_Index
 * 字段偏移 top8: 0x1×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x30a6da push.w {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x30a6de mov r9, r3
 *   @0x30a6e2 mov r8, r2
 *   @0x30a6e6 mov r4, r0
 *   @0x30a6ea stmdbhs r0!, {r0, r8, r9, r11, r12}
 *   @0x30a6ee beq 0x30a6e6 <af_shaper_get_cluster+0xc>
 *   @0x30a6f2 mov r5, r0
 *   @0x30a6f6 cmp r1, #0xdf
 *   @0x30a6fa and r1, r1, #0x1f
 *   @0x30a6fe movs r5, #0x1
 *   @0x30a702 b 0x30a716 <af_shaper_get_cluster+0x3c>
 *   @0x30a706 itete ls
 *   @0x30a70a .word 0xf001010f
 *   @0x30a70e strhs r0, [r2, #-0x107]
 *   @0x30a712 movhi r5, #0x3
 *   @0x30a716 ldrb r6, [r4, #1]!
 *   @0x30a71a cmp r4, r2
 *   @0x30a71e b 0x148c022 <b2_toiTime+0xd32b7e>
 *   @0x30a722 mvnsle r1, r1, lsl #3
 *   @0x30a726 add r5, r0
 *   @0x30a72a ldrb r7, [r5]
 *   @0x30a72e adds r5, #0x1
 *   @0x30a732 ldrsble r0, [r12], -pc
 *   @0x30a736 cmp r7, #0x7f
 *   @0x30a73a mov r4, r7
 *   @0x30a73e cmp r7, #0xdf
 *   @0x30a742 and r4, r7, #0x1f
 *   @0x30a746 movs r0, #0x1
 *   @0x30a74a b 0x30a75e <af_shaper_get_cluster+0x84>
 *   @0x30a74e itete ls
 *   @0x30a752 .word 0xf004040f
 *   @0x30a756 andhs r0, r2, r7, lsl #8
 *   @0x30a75a movhi r0, #0x3
 *   @0x30a75e ldrb r0, [r2], #1
 *   @0x30a762 cmp r2, r5
 *   @0x30a766 b 0x130a86a <b2_toiTime+0xbb13c6>
 *   @0x30a76a mvnsle r1, r4, lsl #9
 *   @0x30a76e b 0x30a72a <af_shaper_get_cluster+0x50>
 *   @0x30a772 str.w r2, [r8]
 *   @0x30a776 str.w r2, [r9]
 *   @0x30a77a b 0x30a78c <af_shaper_get_cluster+0xb2>
 *   @0x30a77e bl 0x2e5960 <FT_Get_Char_Index>
 *   @0x30a782 movs r3, #0x1
 *   @0x30a786 .word 0xf8c90000
 *   @0x30a78a ldrtmi r3, [r0], -r0
 *   @0x30a78e pop.w {r3, r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §32/168 png_do_bgr  0x2afae8  size 182  46 条（0x2afae8..0x2afb9e）
 * @func 0x2afae8 0x2afba0  size 184  46 条
 * 部分覆盖: 本节 46/85 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×3 / 0x-5×2 / 0x-1×2 / 0x-4×1 / 0x4×1 / 0x-2×1 / 0x-6×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2afae8 push {r4, lr}
 *   @0x2afaec lsls r2, r3, #0x1e
 *   @0x2afaf0 ldr r2, [r0]
 *   @0x2afaf4 cmp r0, #0x8
 *   @0x2afaf8 cmp r3, #0x2
 *   @0x2afafc movs r3, #0x3
 *   @0x2afb00 addsmi r1, r1, #536870912
 *   @0x2afb04 beq 0x2afb18 <png_do_bgr+0x30>
 *   @0x2afb08 adds r1, #0x3
 *   @0x2afb0c .word 0xf8010c01
 *   @0x2afb10 .word 0xf8013c01
 *   @0x2afb14 ldrb r0, [r4, r3, lsl #24]!
 *   @0x2afb18 pop {r4, pc}
 *   @0x2afb1c bne 0x2afb9c <png_do_bgr+0xb4>
 *   @0x2afb20 cmp r3, r2
 *   @0x2afb24 andle r0, r9, r4, lsl #2
 *   @0x2afb28 ldrb r0, [r1, #-4]
 *   @0x2afb2c adds r3, #0x1
 *   @0x2afb30 .word 0xf8014c02
 *   @0x2afb34 .word 0xf8010c02
 *   @0x2afb38 ldrb r4, [r1, r4, lsl #24]!
 *   @0x2afb3c pop {r4, pc}
 *   @0x2afb40 bne 0x2afb9c <png_do_bgr+0xb4>
 *   @0x2afb44 bne 0x2afb70 <png_do_bgr+0x88>
 *   @0x2afb48 cmp r3, r2
 *   @0x2afb4c ldrb r0, [r1]
 *   @0x2afb50 ldrb r4, [r1, #0x4]
 *   @0x2afb54 strb r0, [r1, #-2]
 *   @0x2afb58 strb r4, [r1, #-6]
 *   @0x2afb5c ldrb r0, [r1, #-5]
 *   @0x2afb60 ldrb r4, [r1, #-1]
 *   @0x2afb64 strb r0, [r1, #-1]
 *   @0x2afb68 strb r4, [r1, #-5]
 *   @0x2afb6c b 0x2afb48 <png_do_bgr+0x60>
 *   @0x2afb70 cmp r3, #0x6
 *   @0x2afb74 movs r3, #0x0
 *   @0x2afb78 beq 0x2afb9c <png_do_bgr+0xb4>
 *   @0x2afb7c adds r3, #0x1
 *   @0x2afb80 adds r1, #0x8
 *   @0x2afb84 .word 0xf8010c04
 *   @0x2afb88 .word 0xf8114c08
 *   @0x2afb8c .word 0xf8110c07
 *   @0x2afb90 .word 0xf8014c03
 *   @0x2afb94 .word 0xf8010c03
 *   @0x2afb98 strb r4, [r12, r7, lsl #24]!
 *   @0x2afb9c pop {r4, pc}
 *
 * ══ §33/168 CBackground::Assign(CBackground*)  0xc2b80  size 180  45 条（0xc2b80..0xc2c34）
 * @func 0xc2b80 0xc2c34  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBackground::Clear() / operator new(unsigned int) / CBitmap32::CBitmap32(CBitmap32*) / CBackground::InitTexture()
 * 字段偏移 top8: 0x10×4 / 0x4×3 / 0x18×2 / 0xa×2 / 0x8×2 / 0x9×2 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc2b80 push {r4, r5, r6, lr}
 *   @0xc2b84 mov r4, r1
 *   @0xc2b88 mov r5, r0
 *   @0xc2b8c bl 0xc23c0 <_ZN11CBackground5ClearEv>
 *   @0xc2b90 ldrb r3, [r4, #0x18]
 *   @0xc2b94 ldrb r2, [r4, #0xa]
 *   @0xc2b98 cmp r3, #0
 *   @0xc2b9c ldr lr, [r4]
 *   @0xc2ba0 ldr r12, [r4, #0x4]
 *   @0xc2ba4 ldrb r0, [r4, #0x8]
 *   @0xc2ba8 ldrb r1, [r4, #0x9]
 *   @0xc2bac strb r2, [r5, #0xa]
 *   @0xc2bb0 ldreq r2, [r4, #0x14]
 *   @0xc2bb4 strbeq r3, [r5, #0x18]
 *   @0xc2bb8 ldr r3, [r4, #0x10]
 *   @0xc2bbc streq r2, [r5, #0x14]
 *   @0xc2bc0 cmp r3, #0
 *   @0xc2bc4 str lr, [r5]
 *   @0xc2bc8 str r12, [r5, #0x4]
 *   @0xc2bcc strb r0, [r5, #0x8]
 *   @0xc2bd0 strb r1, [r5, #0x9]
 *   @0xc2bd4 beq 0xc2c08 <_ZN11CBackground6AssignEPS_+0x88>
 *   @0xc2bd8 ldr r0, [r5, #0x10]
 *   @0xc2bdc cmp r0, #0
 *   @0xc2be0 beq 0xc2bf0 <_ZN11CBackground6AssignEPS_+0x70>
 *   @0xc2be4 ldr r3, [r0]
 *   @0xc2be8 ldr r3, [r3, #0x4]
 *   @0xc2bec blx r3
 *   @0xc2bf0 mov r0, #24
 *   @0xc2bf4 bl 0x27c524 <_Znwj>
 *   @0xc2bf8 ldr r1, [r4, #0x10]
 *   @0xc2bfc mov r6, r0
 *   @0xc2c00 bl 0x165f98 <_ZN9CBitmap32C2EPS_>
 *   @0xc2c04 str r6, [r5, #0x10]
 *   @0xc2c08 mov r0, r5
 *   @0xc2c0c bl 0xc1e60 <_ZN11CBackground11InitTextureEv>
 *   @0xc2c10 ldr r3, [r4, #0x14]
 *   @0xc2c14 cmp r3, #0
 *   @0xc2c18 beq 0xc2c28 <_ZN11CBackground6AssignEPS_+0xa8>
 *   @0xc2c1c ldrb r3, [r4, #0x18]
 *   @0xc2c20 cmp r3, #0
 *   @0xc2c24 popeq {r4, r5, r6, pc}
 *   @0xc2c28 mov r0, r5
 *   @0xc2c2c pop {r4, r5, r6, lr}
 *   @0xc2c30 b 0xc1ea0 <_ZN11CBackground12InitLocalTPEEv>
 *
 * ══ §34/168 Background_Init()  0xc329c  size 180  45 条（0xc329c..0xc3350）
 * @func 0xc329c 0xc3350  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / Background_Init()+0x68 / CBackground::Free()
 * 字段偏移 top8: 0x4×4 / 0x2×2 / 0x94×1 / 0x84×1 / 0x74×1 / 0x38×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc329c push {r3, r4, r5, r6, r7, lr}
 *   @0xc32a0 ldr r3, [pc, #0x94]
 *   @0xc32a4 add r3, pc, r3
 *   @0xc32a8 ldr r3, [r3, #0x4]
 *   @0xc32ac cmp r3, #0
 *   @0xc32b0 popeq {r3, r4, r5, r6, r7, pc}
 *   @0xc32b4 ldr r5, [pc, #0x84]
 *   @0xc32b8 ldr r5, [pc, r5]
 *   @0xc32bc ldr r2, [r5]
 *   @0xc32c0 cmp r2, #0
 *   @0xc32c4 ble 0xc3304 <_Z15Background_Initv+0x68>
 *   @0xc32c8 ldr r6, [pc, #0x74]
 *   @0xc32cc mov r4, #0
 *   @0xc32d0 mov r7, r4
 *   @0xc32d4 add r6, pc, r6
 *   @0xc32d8 ldr r0, [r3, r4, lsl #2]
 *   @0xc32dc cmp r0, #0
 *   @0xc32e0 beq 0xc32f4 <_Z15Background_Initv+0x58>
 *   @0xc32e4 bl 0xc2d5c <_ZN11CBackground4FreeEv>
 *   @0xc32e8 ldr r3, [r6, #0x4]
 *   @0xc32ec str r7, [r3, r4, lsl #2]
 *   @0xc32f0 ldr r3, [r6, #0x4]
 *   @0xc32f4 ldr r2, [r5]
 *   @0xc32f8 add r4, r4, #1
 *   @0xc32fc cmp r2, r4
 *   @0xc3300 bgt 0xc32d8 <_Z15Background_Initv+0x3c>
 *   @0xc3304 mov r0, r3
 *   @0xc3308 ldr r6, [pc, #0x38]
 *   @0xc330c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xc3310 ldr r3, [pc, #0x34]
 *   @0xc3314 ldr r6, [pc, r6]
 *   @0xc3318 mov r4, #0
 *   @0xc331c add r3, pc, r3
 *   @0xc3320 ldr r0, [r6]
 *   @0xc3324 str r4, [r3, #0x4]
 *   @0xc3328 str r4, [r3]
 *   @0xc332c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xc3330 str r4, [r6]
 *   @0xc3334 str r4, [r5]
 *   @0xc3338 pop {r3, r4, r5, r6, r7, pc}
 *   @0xc333c eorseq r6, r11, r4, lsl #20
 *   @0xc3340 mlaseq r2, r0, r6, r10
 *   @0xc3344 ldrsbteq r6, [r11], -r4
 *   @0xc3348 eorseq r10, r2, r8, lsr r6
 *   @0xc334c eorseq r6, r11, r12, lsl #19
 *
 * ══ §35/168 F_BUFFER_Write(RValue&, CInstance*, CInstance*, int, RValue*)  0xc5324  size 180  45 条（0xc5324..0xc53d8）
 * @func 0xc5324 0xc53d8  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / F_BUFFER_Write(RValue&, CInstance*, CInstance*, int, RValue*)+0x98
 * 字段偏移 top8: 0x4×2 / 0x2×2 / 0x18×1 / 0xc×1 / 0x74×1 / 0x8×1 / 0x10×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc5324 push {r3, r4, r5, r6, r7, lr}
 *   @0xc5328 mov r1, #0
 *   @0xc532c ldr r6, [sp, #0x18]
 *   @0xc5330 mov r3, r1
 *   @0xc5334 str r1, [r0, #0xc]
 *   @0xc5338 movt r3, #0xbff0
 *   @0xc533c mov r4, r0
 *   @0xc5340 stm r0, {r1, r3}
 *   @0xc5344 mov r0, r6
 *   @0xc5348 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc534c subs r5, r0, #0
 *   @0xc5350 blt 0xc53bc <_Z14F_BUFFER_WriteR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0xc5354 ldr r7, [pc, #0x74]
 *   @0xc5358 add r7, pc, r7
 *   @0xc535c ldr r3, [r7]
 *   @0xc5360 cmp r5, r3
 *   @0xc5364 bge 0xc53bc <_Z14F_BUFFER_WriteR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0xc5368 ldr r3, [r7, #0x4]
 *   @0xc536c ldr r3, [r3, r5, lsl #2]
 *   @0xc5370 cmp r3, #0
 *   @0xc5374 beq 0xc53bc <_Z14F_BUFFER_WriteR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0xc5378 mov r1, #1
 *   @0xc537c mov r0, r6
 *   @0xc5380 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc5384 ldr r3, [r7, #0x4]
 *   @0xc5388 add r2, r6, #32
 *   @0xc538c mov r1, r0
 *   @0xc5390 ldr r0, [r3, r5, lsl #2]
 *   @0xc5394 ldr r3, [r0]
 *   @0xc5398 ldr r3, [r3, #0x8]
 *   @0xc539c blx r3
 *   @0xc53a0 vmov s15, r0
 *   @0xc53a4 vcvt.f64.s32 d7, s15
 *   @0xc53a8 vmov r0, r1, d7
 *   @0xc53ac vmov r2, s14
 *   @0xc53b0 mov r3, r1
 *   @0xc53b4 stm r4, {r2, r3}
 *   @0xc53b8 pop {r3, r4, r5, r6, r7, pc}
 *   @0xc53bc ldr r0, [pc, #0x10]
 *   @0xc53c0 mov r1, #0
 *   @0xc53c4 pop {r3, r4, r5, r6, r7, lr}
 *   @0xc53c8 add r0, pc, r0
 *   @0xc53cc b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc53d0 ldrhteq r4, [r11], -r12
 *   @0xc53d4 eoreq r11, r6, r12, ror #15
 *
 * ══ §36/168 CCode::~CCode()  0xce2b8  size 180  45 条（0xce2b8..0xce36c）
 * @func 0xce2b8 0xce36c  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×5 / 0x9c×2 / 0x68×1 / 0x4c×1 / 0x50×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xce2b8 ldrb r2, [r0, #0x68]
 *   @0xce2bc ldr r3, [pc, #0x9c]
 *   @0xce2c0 ldr r1, [pc, #0x9c]
 *   @0xce2c4 cmp r2, #0
 *   @0xce2c8 ldr r3, [pc, r3]
 *   @0xce2cc ldr r1, [pc, r1]
 *   @0xce2d0 push {r4, lr}
 *   @0xce2d4 add r1, r1, #8
 *   @0xce2d8 ldr r2, [r3]
 *   @0xce2dc mov r4, r0
 *   @0xce2e0 str r1, [r0]
 *   @0xce2e4 bne 0xce328 <_ZN5CCodeD2Ev+0x70>
 *   @0xce2e8 cmp r2, #0
 *   @0xce2ec beq 0xce314 <_ZN5CCodeD2Ev+0x5c>
 *   @0xce2f0 cmp r0, r2
 *   @0xce2f4 bne 0xce308 <_ZN5CCodeD2Ev+0x50>
 *   @0xce2f8 b 0xce354 <_ZN5CCodeD2Ev+0x9c>
 *   @0xce2fc cmp r4, r3
 *   @0xce300 beq 0xce348 <_ZN5CCodeD2Ev+0x90>
 *   @0xce304 mov r2, r3
 *   @0xce308 ldr r3, [r2, #0x4]
 *   @0xce30c cmp r3, #0
 *   @0xce310 bne 0xce2fc <_ZN5CCodeD2Ev+0x44>
 *   @0xce314 ldr r3, [pc, #0x4c]
 *   @0xce318 ldr r3, [pc, r3]
 *   @0xce31c ldr r2, [r3]
 *   @0xce320 sub r2, r2, #1
 *   @0xce324 str r2, [r3]
 *   @0xce328 ldr r0, [r4, #0x50]
 *   @0xce32c cmp r0, #0
 *   @0xce330 beq 0xce340 <_ZN5CCodeD2Ev+0x88>
 *   @0xce334 ldr r3, [r0]
 *   @0xce338 ldr r3, [r3, #0x4]
 *   @0xce33c blx r3
 *   @0xce340 mov r0, r4
 *   @0xce344 pop {r4, pc}
 *   @0xce348 ldr r3, [r4, #0x4]
 *   @0xce34c str r3, [r2, #0x4]
 *   @0xce350 b 0xce314 <_ZN5CCodeD2Ev+0x5c>
 *   @0xce354 ldr r2, [r0, #0x4]
 *   @0xce358 str r2, [r3]
 *   @0xce35c b 0xce314 <_ZN5CCodeD2Ev+0x5c>
 *   @0xce360 eorseq pc, r1, r8, asr r8
 *   @0xce364 eorseq pc, r1, r8, asr r8
 *   @0xce368 eorseq pc, r1, r0, lsl r8
 *
 * ══ §37/168 YYGML_AddString(char const*, char const*)  0xdc254  size 180  45 条（0xdc254..0xdc308）
 * @func 0xdc254 0xdc308  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538×2 / 0xb65a4×2 / MemoryManager::Alloc(unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xdc254 push {r3, r4, r5, r6, r7, lr}
 *   @0xdc258 adds r3, r0, #0
 *   @0xdc25c mov r4, r1
 *   @0xdc260 mov r5, r0
 *   @0xdc264 movne r3, #1
 *   @0xdc268 adds r2, r1, #0
 *   @0xdc26c movne r2, #1
 *   @0xdc270 tst r3, r2
 *   @0xdc274 bne 0xdc2ac <_Z15YYGML_AddStringPKcS0_+0x58>
 *   @0xdc278 cmp r1, #0
 *   @0xdc27c movne r3, #0
 *   @0xdc280 andeq r3, r3, #1
 *   @0xdc284 cmp r3, #0
 *   @0xdc288 bne 0xdc2a4 <_Z15YYGML_AddStringPKcS0_+0x50>
 *   @0xdc28c cmp r0, #0
 *   @0xdc290 movne r2, #0
 *   @0xdc294 andeq r2, r2, #1
 *   @0xdc298 cmp r2, #0
 *   @0xdc29c beq 0xdc2f8 <_Z15YYGML_AddStringPKcS0_+0xa4>
 *   @0xdc2a0 mov r0, r1
 *   @0xdc2a4 pop {r3, r4, r5, r6, r7, lr}
 *   @0xdc2a8 b 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xdc2ac bl 0xb6538 <strlen@plt>
 *   @0xdc2b0 mov r7, r0
 *   @0xdc2b4 mov r0, r4
 *   @0xdc2b8 bl 0xb6538 <strlen@plt>
 *   @0xdc2bc ldr r1, [pc, #0x40]
 *   @0xdc2c0 mov r3, #1
 *   @0xdc2c4 movw r2, #0x2ca8
 *   @0xdc2c8 add r1, pc, r1
 *   @0xdc2cc add r0, r7, r0
 *   @0xdc2d0 add r0, r0, r3
 *   @0xdc2d4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xdc2d8 mov r1, r5
 *   @0xdc2dc mov r6, r0
 *   @0xdc2e0 bl 0xb65a4 <strcpy@plt>
 *   @0xdc2e4 add r0, r6, r7
 *   @0xdc2e8 mov r1, r4
 *   @0xdc2ec bl 0xb65a4 <strcpy@plt>
 *   @0xdc2f0 mov r0, r6
 *   @0xdc2f4 pop {r3, r4, r5, r6, r7, pc}
 *   @0xdc2f8 mov r6, r2
 *   @0xdc2fc mov r0, r6
 *   @0xdc300 pop {r3, r4, r5, r6, r7, pc}
 *   @0xdc304 .word 0x002564b4
 *
 * ══ §38/168 F_DsStackRead(RValue&, CInstance*, CInstance*, int, RValue*)  0xfbd60  size 180  45 条（0xfbd60..0xfbe14）
 * @func 0xfbd60 0xfbe14  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / YYGetString(RValue const*, int) / F_DsStackRead(RValue&, CInstance*, CInstance*, int, RValue*)+0x78
 * 字段偏移 top8: 0x18×1 / 0x60×1 / 0x50×1 / 0x4×1 / 0x2×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfbd60 push {r3, r4, r5, r6, r7, lr}
 *   @0xfbd64 mov r1, #0
 *   @0xfbd68 ldr r5, [sp, #0x18]
 *   @0xfbd6c mov r6, r3
 *   @0xfbd70 mov r0, r5
 *   @0xfbd74 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfbd78 mov r1, #1
 *   @0xfbd7c mov r4, r0
 *   @0xfbd80 mov r0, r5
 *   @0xfbd84 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0xfbd88 cmp r6, #3
 *   @0xfbd8c movne r2, #0
 *   @0xfbd90 mov r7, r0
 *   @0xfbd94 beq 0xfbdec <_Z13F_DsStackReadR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0xfbd98 cmp r4, #0
 *   @0xfbd9c blt 0xfbdd8 <_Z13F_DsStackReadR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0xfbda0 ldr r3, [pc, #0x60]
 *   @0xfbda4 ldr r3, [pc, r3]
 *   @0xfbda8 ldr r3, [r3]
 *   @0xfbdac cmp r4, r3
 *   @0xfbdb0 bge 0xfbdd8 <_Z13F_DsStackReadR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0xfbdb4 ldr r3, [pc, #0x50]
 *   @0xfbdb8 ldr r3, [pc, r3]
 *   @0xfbdbc ldr r3, [r3, #0x4]
 *   @0xfbdc0 ldr r0, [r3, r4, lsl #2]
 *   @0xfbdc4 cmp r0, #0
 *   @0xfbdc8 beq 0xfbdd8 <_Z13F_DsStackReadR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0xfbdcc mov r1, r7
 *   @0xfbdd0 pop {r3, r4, r5, r6, r7, lr}
 *   @0xfbdd4 b 0x20f860 <_ZN9CDS_Stack14ReadFromStringEPKcb>
 *   @0xfbdd8 ldr r0, [pc, #0x30]
 *   @0xfbddc mov r1, #0
 *   @0xfbde0 pop {r3, r4, r5, r6, r7, lr}
 *   @0xfbde4 add r0, pc, r0
 *   @0xfbde8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfbdec mov r0, r5
 *   @0xfbdf0 mov r1, #2
 *   @0xfbdf4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfbdf8 cmp r0, #0
 *   @0xfbdfc movle r2, #0
 *   @0xfbe00 movgt r2, #1
 *   @0xfbe04 b 0xfbd98 <_Z13F_DsStackReadR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0xfbe08 .word 0x002f20d8
 *   @0xfbe0c eoreq r2, pc, r8, asr #1
 *   @0xfbe10 eoreq r11, r3, r8, lsl lr
 *
 * ══ §39/168 F_DsQueueRead(RValue&, CInstance*, CInstance*, int, RValue*)  0xfc18c  size 180  45 条（0xfc18c..0xfc240）
 * @func 0xfc18c 0xfc240  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / YYGetString(RValue const*, int) / F_DsQueueRead(RValue&, CInstance*, CInstance*, int, RValue*)+0x78
 * 字段偏移 top8: 0x18×1 / 0x60×1 / 0x50×1 / 0x4×1 / 0x2×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfc18c push {r3, r4, r5, r6, r7, lr}
 *   @0xfc190 mov r1, #0
 *   @0xfc194 ldr r5, [sp, #0x18]
 *   @0xfc198 mov r6, r3
 *   @0xfc19c mov r0, r5
 *   @0xfc1a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfc1a4 mov r1, #1
 *   @0xfc1a8 mov r4, r0
 *   @0xfc1ac mov r0, r5
 *   @0xfc1b0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0xfc1b4 cmp r6, #3
 *   @0xfc1b8 movne r2, #0
 *   @0xfc1bc mov r7, r0
 *   @0xfc1c0 beq 0xfc218 <_Z13F_DsQueueReadR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0xfc1c4 cmp r4, #0
 *   @0xfc1c8 blt 0xfc204 <_Z13F_DsQueueReadR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0xfc1cc ldr r3, [pc, #0x60]
 *   @0xfc1d0 ldr r3, [pc, r3]
 *   @0xfc1d4 ldr r3, [r3]
 *   @0xfc1d8 cmp r4, r3
 *   @0xfc1dc bge 0xfc204 <_Z13F_DsQueueReadR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0xfc1e0 ldr r3, [pc, #0x50]
 *   @0xfc1e4 ldr r3, [pc, r3]
 *   @0xfc1e8 ldr r3, [r3, #0x4]
 *   @0xfc1ec ldr r0, [r3, r4, lsl #2]
 *   @0xfc1f0 cmp r0, #0
 *   @0xfc1f4 beq 0xfc204 <_Z13F_DsQueueReadR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0xfc1f8 mov r1, r7
 *   @0xfc1fc pop {r3, r4, r5, r6, r7, lr}
 *   @0xfc200 b 0x20f104 <_ZN9CDS_Queue14ReadFromStringEPKcb>
 *   @0xfc204 ldr r0, [pc, #0x30]
 *   @0xfc208 mov r1, #0
 *   @0xfc20c pop {r3, r4, r5, r6, r7, lr}
 *   @0xfc210 add r0, pc, r0
 *   @0xfc214 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfc218 mov r0, r5
 *   @0xfc21c mov r1, #2
 *   @0xfc220 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfc224 cmp r0, #0
 *   @0xfc228 movle r2, #0
 *   @0xfc22c movgt r2, #1
 *   @0xfc230 b 0xfc1c4 <_Z13F_DsQueueReadR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0xfc234 mlaeq pc, r12, r12, r1
 *   @0xfc238 eoreq r1, pc, r12, lsl #25
 *   @0xfc23c eoreq r11, r3, r12, ror #19
 *
 * ══ §40/168 F_DsGridAdd(RValue&, CInstance*, CInstance*, int, RValue*)  0xfd2d0  size 180  45 条（0xfd2d0..0xfd384）
 * @func 0xfd2d0 0xfd398  size 200  50 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / F_DsGridAdd(RValue&, CInstance*, CInstance*, int, RValue*)+0x90 / CDS_Grid::Cell_Operation(int, int, int, int, RValue*)
 * 字段偏移 top8: 0x18×2 / 0x60×1 / 0x50×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfd2d0 push {r4, r5, r6, lr}
 *   @0xfd2d4 sub sp, sp, #8
 *   @0xfd2d8 mov r1, #0
 *   @0xfd2dc ldr r4, [sp, #0x18]
 *   @0xfd2e0 mov r0, r4
 *   @0xfd2e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfd2e8 mov r1, #1
 *   @0xfd2ec mov r5, r0
 *   @0xfd2f0 mov r0, r4
 *   @0xfd2f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfd2f8 mov r1, #2
 *   @0xfd2fc mov r6, r0
 *   @0xfd300 mov r0, r4
 *   @0xfd304 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfd308 cmp r5, #0
 *   @0xfd30c blt 0xfd360 <_Z11F_DsGridAddR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0xfd310 ldr r2, [pc, #0x60]
 *   @0xfd314 ldr r2, [pc, r2]
 *   @0xfd318 ldr r2, [r2]
 *   @0xfd31c cmp r5, r2
 *   @0xfd320 bge 0xfd360 <_Z11F_DsGridAddR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0xfd324 ldr r2, [pc, #0x50]
 *   @0xfd328 ldr r2, [pc, r2]
 *   @0xfd32c ldr r3, [r2, #0x4]
 *   @0xfd330 ldr r2, [r3, r5, lsl #2]
 *   @0xfd334 cmp r2, #0
 *   @0xfd338 beq 0xfd360 <_Z11F_DsGridAddR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0xfd33c add r4, r4, #48
 *   @0xfd340 mov r1, r5
 *   @0xfd344 stm sp, {r0, r4}
 *   @0xfd348 mov r3, r6
 *   @0xfd34c mov r0, r2
 *   @0xfd350 mov r2, #2
 *   @0xfd354 bl 0x207d1c <_ZN8CDS_Grid14Cell_OperationEiiiiP6RValue>
 *   @0xfd358 add sp, sp, #8
 *   @0xfd35c pop {r4, r5, r6, pc}
 *   @0xfd360 ldr r0, [pc, #0x18]
 *   @0xfd364 mov r1, #0
 *   @0xfd368 add r0, pc, r0
 *   @0xfd36c add sp, sp, #8
 *   @0xfd370 pop {r4, r5, r6, lr}
 *   @0xfd374 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfd378 eoreq r0, pc, r0, ror r11
 *   @0xfd37c eoreq r0, pc, r0, ror #22
 *   @0xfd380 mlaeq r3, r4, r8, r10
 *
 * ══ §41/168 F_DsGridMultiply(RValue&, CInstance*, CInstance*, int, RValue*)  0xfd384  size 180  45 条（0xfd384..0xfd438）
 * @func 0xfd384 0xfd438  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / F_DsGridMultiply(RValue&, CInstance*, CInstance*, int, RValue*)+0x90 / CDS_Grid::Cell_Operation(int, int, int, int, RValue*)
 * 字段偏移 top8: 0x18×2 / 0x60×1 / 0x50×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfd384 push {r4, r5, r6, lr}
 *   @0xfd388 sub sp, sp, #8
 *   @0xfd38c mov r1, #0
 *   @0xfd390 ldr r4, [sp, #0x18]
 *   @0xfd394 mov r0, r4
 *   @0xfd398 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfd39c mov r1, #1
 *   @0xfd3a0 mov r5, r0
 *   @0xfd3a4 mov r0, r4
 *   @0xfd3a8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfd3ac mov r1, #2
 *   @0xfd3b0 mov r6, r0
 *   @0xfd3b4 mov r0, r4
 *   @0xfd3b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfd3bc cmp r5, #0
 *   @0xfd3c0 blt 0xfd414 <_Z16F_DsGridMultiplyR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0xfd3c4 ldr r2, [pc, #0x60]
 *   @0xfd3c8 ldr r2, [pc, r2]
 *   @0xfd3cc ldr r2, [r2]
 *   @0xfd3d0 cmp r5, r2
 *   @0xfd3d4 bge 0xfd414 <_Z16F_DsGridMultiplyR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0xfd3d8 ldr r2, [pc, #0x50]
 *   @0xfd3dc ldr r2, [pc, r2]
 *   @0xfd3e0 ldr r3, [r2, #0x4]
 *   @0xfd3e4 ldr r2, [r3, r5, lsl #2]
 *   @0xfd3e8 cmp r2, #0
 *   @0xfd3ec beq 0xfd414 <_Z16F_DsGridMultiplyR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0xfd3f0 add r4, r4, #48
 *   @0xfd3f4 mov r1, r5
 *   @0xfd3f8 stm sp, {r0, r4}
 *   @0xfd3fc mov r3, r6
 *   @0xfd400 mov r0, r2
 *   @0xfd404 mov r2, #3
 *   @0xfd408 bl 0x207d1c <_ZN8CDS_Grid14Cell_OperationEiiiiP6RValue>
 *   @0xfd40c add sp, sp, #8
 *   @0xfd410 pop {r4, r5, r6, pc}
 *   @0xfd414 ldr r0, [pc, #0x18]
 *   @0xfd418 mov r1, #0
 *   @0xfd41c add r0, pc, r0
 *   @0xfd420 add sp, sp, #8
 *   @0xfd424 pop {r4, r5, r6, lr}
 *   @0xfd428 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfd42c .word 0x002f0abc
 *   @0xfd430 eoreq r0, pc, r12, lsr #21
 *   @0xfd434 eoreq r10, r3, r0, ror #15
 *
 * ══ §42/168 F_DsGridRead(RValue&, CInstance*, CInstance*, int, RValue*)  0xfe9a4  size 180  45 条（0xfe9a4..0xfea58）
 * @func 0xfe9a4 0xfea58  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / YYGetString(RValue const*, int) / F_DsGridRead(RValue&, CInstance*, CInstance*, int, RValue*)+0x78
 * 字段偏移 top8: 0x18×1 / 0x60×1 / 0x50×1 / 0x4×1 / 0x2×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfe9a4 push {r3, r4, r5, r6, r7, lr}
 *   @0xfe9a8 mov r1, #0
 *   @0xfe9ac ldr r5, [sp, #0x18]
 *   @0xfe9b0 mov r6, r3
 *   @0xfe9b4 mov r0, r5
 *   @0xfe9b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfe9bc mov r1, #1
 *   @0xfe9c0 mov r4, r0
 *   @0xfe9c4 mov r0, r5
 *   @0xfe9c8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0xfe9cc cmp r6, #3
 *   @0xfe9d0 movne r2, #0
 *   @0xfe9d4 mov r7, r0
 *   @0xfe9d8 beq 0xfea30 <_Z12F_DsGridReadR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0xfe9dc cmp r4, #0
 *   @0xfe9e0 blt 0xfea1c <_Z12F_DsGridReadR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0xfe9e4 ldr r3, [pc, #0x60]
 *   @0xfe9e8 ldr r3, [pc, r3]
 *   @0xfe9ec ldr r3, [r3]
 *   @0xfe9f0 cmp r4, r3
 *   @0xfe9f4 bge 0xfea1c <_Z12F_DsGridReadR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0xfe9f8 ldr r3, [pc, #0x50]
 *   @0xfe9fc ldr r3, [pc, r3]
 *   @0xfea00 ldr r3, [r3, #0x4]
 *   @0xfea04 ldr r0, [r3, r4, lsl #2]
 *   @0xfea08 cmp r0, #0
 *   @0xfea0c beq 0xfea1c <_Z12F_DsGridReadR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0xfea10 mov r1, r7
 *   @0xfea14 pop {r3, r4, r5, r6, r7, lr}
 *   @0xfea18 b 0x20b138 <_ZN8CDS_Grid14ReadFromStringEPKcb>
 *   @0xfea1c ldr r0, [pc, #0x30]
 *   @0xfea20 mov r1, #0
 *   @0xfea24 pop {r3, r4, r5, r6, r7, lr}
 *   @0xfea28 add r0, pc, r0
 *   @0xfea2c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfea30 mov r0, r5
 *   @0xfea34 mov r1, #2
 *   @0xfea38 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfea3c cmp r0, #0
 *   @0xfea40 movle r2, #0
 *   @0xfea44 movgt r2, #1
 *   @0xfea48 b 0xfe9dc <_Z12F_DsGridReadR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0xfea4c mlaeq lr, r12, r4, pc
 *   @0xfea50 eoreq pc, lr, r12, lsl #9
 *   @0xfea54 .word 0x002391d4
 *
 * ══ §43/168 F_DsMapSize(RValue&, CInstance*, CInstance*, int, RValue*)  0xfeea0  size 180  45 条（0xfeea0..0xfef54）
 * @func 0xfeea0 0xfef54  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DS_AutoMutex::~DS_AutoMutex()×2 / DS_AutoMutex::DS_AutoMutex() / YYGetInt32(RValue const*, int) / F_DsMapSize(RValue&, CInstance*, CInstance*, int, RValue*)+0x88 / CDS_Map::Size() / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x18×1 / 0x70×1 / 0x60×1 / 0x4×1 / 0x2×1 / 0xc×1 / 0x20×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfeea0 push {r4, r5, r6, lr}
 *   @0xfeea4 sub sp, sp, #8
 *   @0xfeea8 add r4, sp, #4
 *   @0xfeeac mov r5, r0
 *   @0xfeeb0 ldr r6, [sp, #0x18]
 *   @0xfeeb4 mov r0, r4
 *   @0xfeeb8 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0xfeebc mov r1, #0
 *   @0xfeec0 mov r0, r6
 *   @0xfeec4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfeec8 cmp r0, #0
 *   @0xfeecc blt 0xfef28 <_Z11F_DsMapSizeR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0xfeed0 ldr r3, [pc, #0x70]
 *   @0xfeed4 ldr r3, [pc, r3]
 *   @0xfeed8 ldr r3, [r3]
 *   @0xfeedc cmp r0, r3
 *   @0xfeee0 bge 0xfef28 <_Z11F_DsMapSizeR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0xfeee4 ldr r3, [pc, #0x60]
 *   @0xfeee8 ldr r3, [pc, r3]
 *   @0xfeeec ldr r3, [r3, #0x4]
 *   @0xfeef0 ldr r0, [r3, r0, lsl #2]
 *   @0xfeef4 cmp r0, #0
 *   @0xfeef8 beq 0xfef28 <_Z11F_DsMapSizeR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0xfeefc mov r3, #0
 *   @0xfef00 str r3, [r5, #0xc]
 *   @0xfef04 bl 0x2052c0 <_ZN7CDS_Map4SizeEv>
 *   @0xfef08 vmov s15, r0
 *   @0xfef0c mov r0, r4
 *   @0xfef10 vcvt.f64.s32 d7, s15
 *   @0xfef14 vmov r2, r3, d7
 *   @0xfef18 stm r5, {r2, r3}
 *   @0xfef1c bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xfef20 add sp, sp, #8
 *   @0xfef24 pop {r4, r5, r6, pc}
 *   @0xfef28 ldr r0, [pc, #0x20]
 *   @0xfef2c mov r1, #0
 *   @0xfef30 add r0, pc, r0
 *   @0xfef34 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfef38 mov r0, r4
 *   @0xfef3c bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xfef40 add sp, sp, #8
 *   @0xfef44 pop {r4, r5, r6, pc}
 *   @0xfef48 eoreq lr, lr, r4, lsr #27
 *   @0xfef4c eoreq lr, lr, r4, asr r10
 *   @0xfef50 eoreq r8, r3, r12, asr #25
 *
 * ══ §44/168 FindFreeDsListIndex()  0xfff10  size 180  45 条（0xfff10..0xfffc4）
 * @func 0xfff10 0xfffc4  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xfff14→0x4836b8, 0xfff24→0x4836bc
 * 调用序列: FindFreeDsListIndex()+0x58 / MemoryManager::SetLength(void**, unsigned int, char const*, int)
 * 字段偏移 top8: 0x9c×2 / 0x4×2 / 0x90×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfff10 ldr r3, [pc, #0x9c]
 *   @0xfff14 ldr r2, [pc, #0x9c]
 *   @0xfff18 add r3, pc, r3
 *   @0xfff1c push {r4, r5, r6, lr}
 *   @0xfff20 ldr r6, [r3, r2]
 *   @0xfff24 ldr r2, [pc, #0x90]
 *   @0xfff28 ldr r4, [r6]
 *   @0xfff2c ldr r5, [r3, r2]
 *   @0xfff30 cmp r4, #0
 *   @0xfff34 ble 0xfff68 <_Z19FindFreeDsListIndexv+0x58>
 *   @0xfff38 ldr r3, [r5, #0x4]
 *   @0xfff3c ldr r0, [r3]
 *   @0xfff40 cmp r0, #0
 *   @0xfff44 popeq {r4, r5, r6, pc}
 *   @0xfff48 mov r0, #0
 *   @0xfff4c b 0xfff5c <_Z19FindFreeDsListIndexv+0x4c>
 *   @0xfff50 ldr r2, [r3, #0x4]!
 *   @0xfff54 cmp r2, #0
 *   @0xfff58 popeq {r4, r5, r6, pc}
 *   @0xfff5c add r0, r0, #1
 *   @0xfff60 cmp r0, r4
 *   @0xfff64 bne 0xfff50 <_Z19FindFreeDsListIndexv+0x40>
 *   @0xfff68 ldr r3, [r5]
 *   @0xfff6c cmp r4, r3
 *   @0xfff70 movlt r3, r4
 *   @0xfff74 bge 0xfff88 <_Z19FindFreeDsListIndexv+0x78>
 *   @0xfff78 add r3, r3, #1
 *   @0xfff7c mov r0, r4
 *   @0xfff80 str r3, [r6]
 *   @0xfff84 pop {r4, r5, r6, pc}
 *   @0xfff88 add r1, r4, #16
 *   @0xfff8c ldr r2, [pc, #0x2c]
 *   @0xfff90 movw r3, #0x246
 *   @0xfff94 add r0, r5, #4
 *   @0xfff98 add r2, pc, r2
 *   @0xfff9c lsl r1, r1, #2
 *   @0xfffa0 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xfffa4 ldr r3, [r6]
 *   @0xfffa8 add r2, r3, #16
 *   @0xfffac str r2, [r5]
 *   @0xfffb0 b 0xfff78 <_Z19FindFreeDsListIndexv+0x68>
 *   @0xfffb4 eoreq r1, pc, r8, lsr sp
 *   @0xfffb8 .word 0xffffc02c
 *   @0xfffbc .word 0xffffc030
 *   @0xfffc0 eoreq r7, r3, r4, lsl #24
 *
 * ══ §45/168 F_StringLetters(RValue&, CInstance*, CInstance*, int, RValue*)  0x10feb8  size 180  45 条（0x10feb8..0x10ff6c）
 * @func 0x10feb8 0x10ff6c  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: utf8_add_char×2 / YYGetString(RValue const*, int) / 0xb6538 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / utf8_extract_char / F_StringLetters(RValue&, CInstance*, CInstance*, int, RValue*)+0xa0 / YYCreateString(RValue*, char const*) / YYFree(void const*)
 * 字段偏移 top8: 0x20×1 / 0x84×1 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10feb8 push {r4, r5, r6, r7, r8, lr}
 *   @0x10febc sub sp, sp, #8
 *   @0x10fec0 mov r1, #0
 *   @0x10fec4 mov r7, r0
 *   @0x10fec8 ldr r0, [sp, #0x20]
 *   @0x10fecc add r5, sp, #8
 *   @0x10fed0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x10fed4 mov r8, r0
 *   @0x10fed8 bl 0xb6538 <strlen@plt>
 *   @0x10fedc ldr r1, [pc, #0x84]
 *   @0x10fee0 mov r3, #1
 *   @0x10fee4 movw r2, #0x843
 *   @0x10fee8 add r1, pc, r1
 *   @0x10feec add r0, r0, r3
 *   @0x10fef0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x10fef4 str r8, [sp]
 *   @0x10fef8 mov r3, r8
 *   @0x10fefc mov r6, r0
 *   @0x10ff00 str r0, [r5, #-0x4]!
 *   @0x10ff04 b 0x10ff24 <_Z15F_StringLettersR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x10ff08 bl 0x10fb38 <utf8_extract_char>
 *   @0x10ff0c bic r3, r0, #32
 *   @0x10ff10 sub r3, r3, #65
 *   @0x10ff14 uxth r3, r3
 *   @0x10ff18 cmp r3, #25
 *   @0x10ff1c bls 0x10ff58 <_Z15F_StringLettersR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x10ff20 ldr r3, [sp]
 *   @0x10ff24 ldrb r1, [r3]
 *   @0x10ff28 mov r0, sp
 *   @0x10ff2c cmp r1, #0
 *   @0x10ff30 bne 0x10ff08 <_Z15F_StringLettersR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x10ff34 mov r0, r5
 *   @0x10ff38 bl 0x10fe28 <utf8_add_char>
 *   @0x10ff3c mov r0, r7
 *   @0x10ff40 mov r1, r6
 *   @0x10ff44 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x10ff48 mov r0, r6
 *   @0x10ff4c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x10ff50 add sp, sp, #8
 *   @0x10ff54 pop {r4, r5, r6, r7, r8, pc}
 *   @0x10ff58 mov r1, r0
 *   @0x10ff5c mov r0, r5
 *   @0x10ff60 bl 0x10fe28 <utf8_add_char>
 *   @0x10ff64 b 0x10ff20 <_Z15F_StringLettersR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x10ff68 eoreq r8, r2, r12, asr pc
 *
 * ══ §46/168 StringPos(char const*, char const*)  0x1111e0  size 180  45 条（0x1111e0..0x111294）
 * @func 0x1111e0 0x111294  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: utf8_strlen / utf8_strncmp / utf8_extract_char
 * 字段偏移 top8: 0x4×4
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1111e0 cmp r0, #0
 *   @0x1111e4 cmpne r1, #0
 *   @0x1111e8 push {r4, r5, r6, r7, lr}
 *   @0x1111ec movne r4, #0
 *   @0x1111f0 moveq r4, #1
 *   @0x1111f4 sub sp, sp, #12
 *   @0x1111f8 mov r5, r0
 *   @0x1111fc beq 0x111234 <_Z9StringPosPKcS0_+0x54>
 *   @0x111200 ldrb r2, [r1]
 *   @0x111204 cmp r2, #0
 *   @0x111208 beq 0x111234 <_Z9StringPosPKcS0_+0x54>
 *   @0x11120c ldrb r2, [r0]
 *   @0x111210 cmp r2, #0
 *   @0x111214 beq 0x111234 <_Z9StringPosPKcS0_+0x54>
 *   @0x111218 str r1, [sp, #0x4]
 *   @0x11121c bl 0x110648 <utf8_strlen>
 *   @0x111220 mov r6, r0
 *   @0x111224 ldr r0, [sp, #0x4]
 *   @0x111228 ldrb r2, [r0]
 *   @0x11122c cmp r2, #0
 *   @0x111230 bne 0x111240 <_Z9StringPosPKcS0_+0x60>
 *   @0x111234 mvn r0, #0
 *   @0x111238 add sp, sp, #12
 *   @0x11123c pop {r4, r5, r6, r7, pc}
 *   @0x111240 add r7, sp, #4
 *   @0x111244 mov r1, r5
 *   @0x111248 mov r2, r6
 *   @0x11124c bl 0x110b34 <utf8_strncmp>
 *   @0x111250 cmp r0, #0
 *   @0x111254 mov r0, r7
 *   @0x111258 beq 0x111278 <_Z9StringPosPKcS0_+0x98>
 *   @0x11125c bl 0x10fb38 <utf8_extract_char>
 *   @0x111260 ldr r0, [sp, #0x4]
 *   @0x111264 add r4, r4, #1
 *   @0x111268 ldrb r2, [r0]
 *   @0x11126c cmp r2, #0
 *   @0x111270 beq 0x111234 <_Z9StringPosPKcS0_+0x54>
 *   @0x111274 b 0x111244 <_Z9StringPosPKcS0_+0x64>
 *   @0x111278 ldr r3, [sp, #0x4]
 *   @0x11127c ldrb r3, [r3]
 *   @0x111280 cmp r3, #0
 *   @0x111284 movne r0, r4
 *   @0x111288 beq 0x111234 <_Z9StringPosPKcS0_+0x54>
 *   @0x11128c add sp, sp, #12
 *   @0x111290 pop {r4, r5, r6, r7, pc}
 *
 * ══ §47/168 F_DrawRoundRect_EXT(RValue&, CInstance*, CInstance*, int, RValue*)  0x11afd0  size 180  45 条（0x11afd0..0x11b084）
 * @func 0x11afd0 0x11b098  size 200  50 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×7 / GR_Draw_RoundRect(float, float, float, float, float, float, bool)
 * 字段偏移 top8: 0x30×1 / 0x4×1 / 0x8×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11afd0 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x11afd4 sub sp, sp, #16
 *   @0x11afd8 mov r1, #4
 *   @0x11afdc ldr r4, [sp, #0x30]
 *   @0x11afe0 mov r0, r4
 *   @0x11afe4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11afe8 mov r1, #5
 *   @0x11afec mov r10, r0
 *   @0x11aff0 mov r0, r4
 *   @0x11aff4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11aff8 mov r1, #0
 *   @0x11affc mov r9, r0
 *   @0x11b000 mov r0, r4
 *   @0x11b004 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b008 mov r1, #1
 *   @0x11b00c mov r5, r0
 *   @0x11b010 mov r0, r4
 *   @0x11b014 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b018 mov r1, #2
 *   @0x11b01c mov r8, r0
 *   @0x11b020 mov r0, r4
 *   @0x11b024 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b028 mov r1, #3
 *   @0x11b02c mov r7, r0
 *   @0x11b030 mov r0, r4
 *   @0x11b034 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b038 mov r1, #6
 *   @0x11b03c mov r6, r0
 *   @0x11b040 mov r0, r4
 *   @0x11b044 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b048 str r10, [sp]
 *   @0x11b04c str r9, [sp, #0x4]
 *   @0x11b050 mov r1, r8
 *   @0x11b054 mov r2, r7
 *   @0x11b058 mov r3, r6
 *   @0x11b05c vmov s15, r0
 *   @0x11b060 mov r0, r5
 *   @0x11b064 vcmpe.f32 s15, #0
 *   @0x11b068 vmrs APSR_nzcv, fpscr
 *   @0x11b06c movle r12, #0
 *   @0x11b070 movgt r12, #1
 *   @0x11b074 str r12, [sp, #0x8]
 *   @0x11b078 bl 0x16b77c <_Z17GR_Draw_RoundRectffffffb>
 *   @0x11b07c add sp, sp, #16
 *   @0x11b080 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ §48/168 F_DrawTriangle(RValue&, CInstance*, CInstance*, int, RValue*)  0x11b084  size 180  45 条（0x11b084..0x11b138）
 * @func 0x11b084 0x11b138  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×7 / GR_Draw_Triangle(float, float, float, float, float, float, bool)
 * 字段偏移 top8: 0x30×1 / 0x4×1 / 0x8×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11b084 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x11b088 sub sp, sp, #16
 *   @0x11b08c mov r1, #0
 *   @0x11b090 ldr r4, [sp, #0x30]
 *   @0x11b094 mov r0, r4
 *   @0x11b098 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b09c mov r1, #1
 *   @0x11b0a0 mov r5, r0
 *   @0x11b0a4 mov r0, r4
 *   @0x11b0a8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b0ac mov r1, #2
 *   @0x11b0b0 mov r8, r0
 *   @0x11b0b4 mov r0, r4
 *   @0x11b0b8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b0bc mov r1, #3
 *   @0x11b0c0 mov r7, r0
 *   @0x11b0c4 mov r0, r4
 *   @0x11b0c8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b0cc mov r1, #4
 *   @0x11b0d0 mov r6, r0
 *   @0x11b0d4 mov r0, r4
 *   @0x11b0d8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b0dc mov r1, #5
 *   @0x11b0e0 mov r10, r0
 *   @0x11b0e4 mov r0, r4
 *   @0x11b0e8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b0ec mov r1, #6
 *   @0x11b0f0 mov r9, r0
 *   @0x11b0f4 mov r0, r4
 *   @0x11b0f8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b0fc str r10, [sp]
 *   @0x11b100 str r9, [sp, #0x4]
 *   @0x11b104 mov r1, r8
 *   @0x11b108 mov r2, r7
 *   @0x11b10c mov r3, r6
 *   @0x11b110 vmov s15, r0
 *   @0x11b114 mov r0, r5
 *   @0x11b118 vcmpe.f32 s15, #0
 *   @0x11b11c vmrs APSR_nzcv, fpscr
 *   @0x11b120 movle r12, #0
 *   @0x11b124 movgt r12, #1
 *   @0x11b128 str r12, [sp, #0x8]
 *   @0x11b12c bl 0x16a6f0 <_Z16GR_Draw_Triangleffffffb>
 *   @0x11b130 add sp, sp, #16
 *   @0x11b134 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ §49/168 F_DrawSpriteStretched(RValue&, CInstance*, CInstance*, int, RValue*)  0x122d14  size 180  45 条（0x122d14..0x122dc8）
 * @func 0x122d14 0x122dc8  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4 / GetSpriteIndices(CInstance*, RValue*, int&, int&) / Sprite_Data(int) / GR_Draw_Get_Alpha() / CSprite::DrawStretched(int, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0x38×1 / 0x10×1 / 0x14×1 / 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x122d14 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x122d18 sub sp, sp, #28
 *   @0x122d1c mov r0, r1
 *   @0x122d20 add r2, sp, #16
 *   @0x122d24 ldr r4, [sp, #0x38]
 *   @0x122d28 add r3, sp, #20
 *   @0x122d2c mov r1, r4
 *   @0x122d30 bl 0x1226c4 <_Z16GetSpriteIndicesP9CInstanceP6RValueRiS3_>
 *   @0x122d34 cmp r0, #0
 *   @0x122d38 bne 0x122d44 <_Z21F_DrawSpriteStretchedR6RValueP9CInstanceS2_iPS_+0x30>
 *   @0x122d3c add sp, sp, #28
 *   @0x122d40 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x122d44 ldr r0, [sp, #0x10]
 *   @0x122d48 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x122d4c mov r1, #2
 *   @0x122d50 ldr r8, [sp, #0x14]
 *   @0x122d54 mov r5, r0
 *   @0x122d58 mov r0, r4
 *   @0x122d5c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122d60 mov r1, #3
 *   @0x122d64 mov r7, r0
 *   @0x122d68 mov r0, r4
 *   @0x122d6c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122d70 mov r1, #4
 *   @0x122d74 mov r6, r0
 *   @0x122d78 mov r0, r4
 *   @0x122d7c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122d80 mov r1, #5
 *   @0x122d84 mov r9, r0
 *   @0x122d88 mov r0, r4
 *   @0x122d8c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122d90 mov r4, r0
 *   @0x122d94 bl 0x169f1c <_Z17GR_Draw_Get_Alphav>
 *   @0x122d98 mvn r12, #-16777216
 *   @0x122d9c str r9, [sp]
 *   @0x122da0 str r4, [sp, #0x4]
 *   @0x122da4 mov r1, r8
 *   @0x122da8 mov r2, r7
 *   @0x122dac mov r3, r6
 *   @0x122db0 str r12, [sp, #0x8]
 *   @0x122db4 str r0, [sp, #0xc]
 *   @0x122db8 mov r0, r5
 *   @0x122dbc bl 0x1ecdc4 <_ZN7CSprite13DrawStretchedEiffffjf>
 *   @0x122dc0 add sp, sp, #28
 *   @0x122dc4 pop {r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §50/168 F_GetIntegerAsync(RValue&, CInstance*, CInstance*, int, RValue*)  0x127188  size 180  45 条（0x127188..0x12723c）
 * @func 0x127188 0x12723c  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool) / STRING_RValue(char**, char**, int*, RValue const*) / String_Replace_Hash(char*) / YYGetString(RValue const*, int) / InputQuery::InputAsync(char const*, char const*, char const*) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x8×4 / 0xa4×1 / 0x4×1 / 0x20×1 / 0x-4×1 / 0x48×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x127188 ldr r1, [pc, #0xa4]
 *   @0x12718c mov r12, #16
 *   @0x127190 push {r4, r5, r6, lr}
 *   @0x127194 sub sp, sp, #16
 *   @0x127198 mov r4, r0
 *   @0x12719c add r1, pc, r1
 *   @0x1271a0 mov r0, r12
 *   @0x1271a4 movw r2, #0x60d
 *   @0x1271a8 mov r3, #1
 *   @0x1271ac str r12, [sp, #0x4]
 *   @0x1271b0 ldr r6, [sp, #0x20]
 *   @0x1271b4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1271b8 mov r5, #0
 *   @0x1271bc add r2, sp, #4
 *   @0x1271c0 add r1, sp, #8
 *   @0x1271c4 mov r3, r0
 *   @0x1271c8 add r0, sp, #16
 *   @0x1271cc str r3, [sp, #0x8]
 *   @0x1271d0 str r3, [r0, #-0x4]!
 *   @0x1271d4 strb r5, [r3]
 *   @0x1271d8 add r3, r6, #16
 *   @0x1271dc bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue>
 *   @0x1271e0 ldr r0, [sp, #0x8]
 *   @0x1271e4 bl 0x212da8 <_Z19String_Replace_HashPc>
 *   @0x1271e8 ldr r3, [pc, #0x48]
 *   @0x1271ec str r5, [r4, #0xc]
 *   @0x1271f0 mov r1, r5
 *   @0x1271f4 ldr r3, [pc, r3]
 *   @0x1271f8 mov r0, r6
 *   @0x1271fc ldr r5, [r3]
 *   @0x127200 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x127204 ldr r2, [sp, #0x8]
 *   @0x127208 mov r1, r0
 *   @0x12720c mov r0, r5
 *   @0x127210 bl 0xf26c4 <_ZN10InputQuery10InputAsyncEPKcS1_S1_>
 *   @0x127214 vmov s15, r0
 *   @0x127218 ldr r0, [sp, #0x8]
 *   @0x12721c vcvt.f64.s32 d7, s15
 *   @0x127220 vmov r2, r3, d7
 *   @0x127224 stm r4, {r2, r3}
 *   @0x127228 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x12722c add sp, sp, #16
 *   @0x127230 pop {r4, r5, r6, pc}
 *   @0x127234 mlaeq r1, r8, r0, r5
 *   @0x127238 eoreq r7, r12, r12, lsl #17
 *
 * ══ §51/168 F_PartEmitterRegion(RValue&, CInstance*, CInstance*, int, RValue*)  0x129d0c  size 180  45 条（0x129d0c..0x129dc0）
 * @func 0x129d0c 0x129dc0  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×4 / YYGetFloat(RValue const*, int)×4 / ParticleSystem_Emitter_Region(int, int, float, float, float, float, int, int)
 * 字段偏移 top8: 0x38×1 / 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x129d0c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x129d10 sub sp, sp, #20
 *   @0x129d14 mov r1, #0
 *   @0x129d18 ldr r4, [sp, #0x38]
 *   @0x129d1c mov r0, r4
 *   @0x129d20 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129d24 mov r1, #1
 *   @0x129d28 mov r5, r0
 *   @0x129d2c mov r0, r4
 *   @0x129d30 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129d34 mov r1, #2
 *   @0x129d38 mov r8, r0
 *   @0x129d3c mov r0, r4
 *   @0x129d40 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x129d44 mov r1, #3
 *   @0x129d48 mov r7, r0
 *   @0x129d4c mov r0, r4
 *   @0x129d50 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x129d54 mov r1, #4
 *   @0x129d58 mov r6, r0
 *   @0x129d5c mov r0, r4
 *   @0x129d60 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x129d64 mov r1, #5
 *   @0x129d68 mov r11, r0
 *   @0x129d6c mov r0, r4
 *   @0x129d70 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x129d74 mov r1, #6
 *   @0x129d78 mov r10, r0
 *   @0x129d7c mov r0, r4
 *   @0x129d80 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129d84 mov r1, #7
 *   @0x129d88 mov r9, r0
 *   @0x129d8c mov r0, r4
 *   @0x129d90 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129d94 str r11, [sp]
 *   @0x129d98 str r10, [sp, #0x4]
 *   @0x129d9c mov r1, r8
 *   @0x129da0 str r9, [sp, #0x8]
 *   @0x129da4 mov r2, r7
 *   @0x129da8 mov r3, r6
 *   @0x129dac str r0, [sp, #0xc]
 *   @0x129db0 mov r0, r5
 *   @0x129db4 bl 0x1a394c <_Z29ParticleSystem_Emitter_Regioniiffffii>
 *   @0x129db8 add sp, sp, #20
 *   @0x129dbc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §52/168 F_SpriteAddAlpha(RValue&, CInstance*, CInstance*, int, RValue*)  0x12bfb8  size 180  45 条（0x12bfb8..0x12c06c）
 * @func 0x12bfb8 0x12c06c  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×4 / YYGetString(RValue const*, int) / YYGetBool(RValue const*, int) / Sprite_Add_Alpha(char const*, int, bool, bool, int, int)
 * 字段偏移 top8: 0x28×1 / 0xc×1 / 0x4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12bfb8 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x12bfbc sub sp, sp, #8
 *   @0x12bfc0 mov r5, r0
 *   @0x12bfc4 mov r1, #0
 *   @0x12bfc8 ldr r4, [sp, #0x28]
 *   @0x12bfcc str r1, [r0, #0xc]
 *   @0x12bfd0 mov r0, r4
 *   @0x12bfd4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x12bfd8 mov r1, #1
 *   @0x12bfdc mov r6, r0
 *   @0x12bfe0 mov r0, r4
 *   @0x12bfe4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12bfe8 mov r1, #2
 *   @0x12bfec mov r9, r0
 *   @0x12bff0 mov r0, r4
 *   @0x12bff4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12bff8 mov r1, #3
 *   @0x12bffc mov r8, r0
 *   @0x12c000 mov r0, r4
 *   @0x12c004 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12c008 mov r1, #4
 *   @0x12c00c mov r7, r0
 *   @0x12c010 mov r0, r4
 *   @0x12c014 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c018 mov r1, #5
 *   @0x12c01c mov r10, r0
 *   @0x12c020 mov r0, r4
 *   @0x12c024 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c028 cmp r8, #0
 *   @0x12c02c mov r1, r9
 *   @0x12c030 mov r3, r7
 *   @0x12c034 movle r2, #0
 *   @0x12c038 movgt r2, #1
 *   @0x12c03c str r10, [sp]
 *   @0x12c040 str r0, [sp, #0x4]
 *   @0x12c044 mov r0, r6
 *   @0x12c048 bl 0x1f03cc <_Z16Sprite_Add_AlphaPKcibbii>
 *   @0x12c04c vmov s15, r0
 *   @0x12c050 vcvt.f64.s32 d7, s15
 *   @0x12c054 vmov r0, r1, d7
 *   @0x12c058 vmov r2, s14
 *   @0x12c05c mov r3, r1
 *   @0x12c060 stm r5, {r2, r3}
 *   @0x12c064 add sp, sp, #8
 *   @0x12c068 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ §53/168 F_Sound3DSetSoundVelocity(RValue&, CInstance*, CInstance*, int, RValue*)  0x1361e8  size 180  45 条（0x1361e8..0x13629c）
 * @func 0x1361e8 0x13629c  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×3 / YYGetInt32(RValue const*, int) / Sound_Data(int) / CSound::GetSoundId() / SND_3D_Set_Sound_Velocity(int, double, double, double)
 * 字段偏移 top8: 0xa4×1 / 0x30×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1361e8 ldr r3, [pc, #0xa4]
 *   @0x1361ec push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x1361f0 ldr r3, [pc, r3]
 *   @0x1361f4 sub sp, sp, #20
 *   @0x1361f8 ldrb r1, [r3]
 *   @0x1361fc ldr r8, [sp, #0x30]
 *   @0x136200 cmp r1, #0
 *   @0x136204 beq 0x136210 <_Z25F_Sound3DSetSoundVelocityR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x136208 add sp, sp, #20
 *   @0x13620c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x136210 mov r0, r8
 *   @0x136214 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x136218 bl 0x21fcd4 <_Z10Sound_Datai>
 *   @0x13621c subs r1, r0, #0
 *   @0x136220 beq 0x136280 <_Z25F_Sound3DSetSoundVelocityR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x136224 bl 0x215748 <_ZN6CSound10GetSoundIdEv>
 *   @0x136228 mov r1, #1
 *   @0x13622c mov r9, r0
 *   @0x136230 mov r0, r8
 *   @0x136234 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x136238 mov r4, r0
 *   @0x13623c mov r5, r1
 *   @0x136240 mov r0, r8
 *   @0x136244 mov r1, #2
 *   @0x136248 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x13624c mov r6, r0
 *   @0x136250 mov r7, r1
 *   @0x136254 mov r0, r8
 *   @0x136258 mov r1, #3
 *   @0x13625c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x136260 strd r6, r7, [sp]
 *   @0x136264 mov r2, r4
 *   @0x136268 mov r3, r5
 *   @0x13626c strd r0, r1, [sp, #8]
 *   @0x136270 mov r0, r9
 *   @0x136274 bl 0x21f170 <_Z25SND_3D_Set_Sound_Velocityiddd>
 *   @0x136278 add sp, sp, #20
 *   @0x13627c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x136280 ldr r0, [pc, #0x10]
 *   @0x136284 add r0, pc, r0
 *   @0x136288 add sp, sp, #20
 *   @0x13628c pop {r4, r5, r6, r7, r8, r9, lr}
 *   @0x136290 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x136294 eoreq r8, r11, r12, asr lr
 *   @0x136298 eoreq r9, r0, r8, lsl #4
 *
 * ══ §54/168 anon_139aa0  0x139aa0  size 180  45 条（0x139aa0..0x139b54）
 * @func 0x139aa0 0x139b54  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6874×2 / 0xb65b0 / 0xb6880 / YYCreateString(RValue*, char const*) / 0xb65d4
 * 字段偏移 top8: 0x404×2 / 0x8×2 / 0xa0×1 / 0x98×1 / 0x1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x139aa0 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x139aa4 sub sp, sp, #1024
 *   @0x139aa8 ldr r5, [pc, #0xa0]
 *   @0x139aac sub sp, sp, #12
 *   @0x139ab0 add r7, sp, #4
 *   @0x139ab4 ldr r4, [pc, #0x98]
 *   @0x139ab8 ldr r5, [pc, r5]
 *   @0x139abc mov r8, r0
 *   @0x139ac0 mov r1, #0
 *   @0x139ac4 mov r0, r7
 *   @0x139ac8 ldr r3, [r5]
 *   @0x139acc mov r2, #1024
 *   @0x139ad0 add r9, sp, #1024
 *   @0x139ad4 add r6, sp, #3
 *   @0x139ad8 add r9, r9, #3
 *   @0x139adc str r3, [sp, #0x404]
 *   @0x139ae0 bl 0xb65b0 <memset@plt>
 *   @0x139ae4 ldr r4, [pc, r4]
 *   @0x139ae8 ldr r0, [r4, #0x8]
 *   @0x139aec bl 0xb6880 <fgetc@plt>
 *   @0x139af0 uxtb r3, r0
 *   @0x139af4 ldr r0, [r4, #0x8]
 *   @0x139af8 cmp r3, #13
 *   @0x139afc cmpne r3, #10
 *   @0x139b00 bne 0x139b30 <_Z9F_FileEofR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0x139b04 bl 0xb6874 <feof@plt>
 *   @0x139b08 mov r0, r8
 *   @0x139b0c mov r1, r7
 *   @0x139b10 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x139b14 ldr r2, [sp, #0x404]
 *   @0x139b18 ldr r3, [r5]
 *   @0x139b1c cmp r2, r3
 *   @0x139b20 bne 0x139b4c <_Z9F_FileEofR6RValueP9CInstanceS2_iPS_+0x120>
 *   @0x139b24 add sp, sp, #1024
 *   @0x139b28 add sp, sp, #12
 *   @0x139b2c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x139b30 strb r3, [r6, #0x1]!
 *   @0x139b34 bl 0xb6874 <feof@plt>
 *   @0x139b38 cmp r0, #0
 *   @0x139b3c bne 0x139b08 <_Z9F_FileEofR6RValueP9CInstanceS2_iPS_+0xdc>
 *   @0x139b40 cmp r6, r9
 *   @0x139b44 bne 0x139ae8 <_Z9F_FileEofR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x139b48 b 0x139b08 <_Z9F_FileEofR6RValueP9CInstanceS2_iPS_+0xdc>
 *   @0x139b4c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x139b50 mlaeq r11, r8, lr, r3
 *
 * ══ §55/168 anon_139b88  0x139b88  size 180  45 条（0x139b88..0x139c3c）
 * @func 0x139b88 0x139c3c  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65b0 / 0xb6880 / 0xb6874 / YYCreateString(RValue*, char const*) / 0xb65d4
 * 字段偏移 top8: 0x404×2 / 0x8×2 / 0xa0×1 / 0x98×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x139b88 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x139b8c sub sp, sp, #1024
 *   @0x139b90 ldr r8, [pc, #0xa0]
 *   @0x139b94 sub sp, sp, #8
 *   @0x139b98 add r7, sp, #4
 *   @0x139b9c ldr r6, [pc, #0x98]
 *   @0x139ba0 ldr r8, [pc, r8]
 *   @0x139ba4 mov r1, #0
 *   @0x139ba8 mov r9, r0
 *   @0x139bac mov r2, #1024
 *   @0x139bb0 ldr r3, [r8]
 *   @0x139bb4 mov r0, r7
 *   @0x139bb8 mov r4, r1
 *   @0x139bbc movw r10, #0x3ff
 *   @0x139bc0 str r3, [sp, #0x404]
 *   @0x139bc4 bl 0xb65b0 <memset@plt>
 *   @0x139bc8 ldr r6, [pc, r6]
 *   @0x139bcc ldr r0, [r6, #0x8]
 *   @0x139bd0 bl 0xb6880 <fgetc@plt>
 *   @0x139bd4 uxtb r5, r0
 *   @0x139bd8 ldr r0, [r6, #0x8]
 *   @0x139bdc strb r5, [r7, r4]
 *   @0x139be0 bl 0xb6874 <feof@plt>
 *   @0x139be4 cmp r0, #0
 *   @0x139be8 bne 0x139c0c <_Z16F_FileReadStringR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x139bec add r4, r4, #1
 *   @0x139bf0 cmp r4, r10
 *   @0x139bf4 movgt r3, #0
 *   @0x139bf8 movle r3, #1
 *   @0x139bfc cmp r5, #10
 *   @0x139c00 moveq r3, #0
 *   @0x139c04 cmp r3, #0
 *   @0x139c08 bne 0x139bcc <_Z16F_FileReadStringR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x139c0c mov r0, r9
 *   @0x139c10 mov r1, r7
 *   @0x139c14 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x139c18 ldr r2, [sp, #0x404]
 *   @0x139c1c ldr r3, [r8]
 *   @0x139c20 cmp r2, r3
 *   @0x139c24 bne 0x139c34 <_Z16F_FileReadStringR6RValueP9CInstanceS2_iPS_+0xdc>
 *   @0x139c28 add sp, sp, #1024
 *   @0x139c2c add sp, sp, #8
 *   @0x139c30 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x139c34 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x139c38 .word 0x002b3db0
 *
 * ══ §56/168 F_ActionReplaceBackground(RValue&, CInstance*, CInstance*, int, RValue*)  0x140acc  size 180  45 条（0x140acc..0x140b80）
 * @func 0x140acc 0x140b80  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetString(RValue const*, int) / Background_Exists(int) / FileExists(char const*) / Background_Data(int) / CBackground::GetTransparent() / CBackground::Smooth() / CBackground::GetPreload()
 * 字段偏移 top8: 0x18×3 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x140acc push {r4, r5, r6, r7, r8, lr}
 *   @0x140ad0 mov r1, #0
 *   @0x140ad4 ldr r4, [sp, #0x18]
 *   @0x140ad8 mov r0, r4
 *   @0x140adc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x140ae0 mov r1, #1
 *   @0x140ae4 mov r5, r0
 *   @0x140ae8 mov r0, r4
 *   @0x140aec bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x140af0 mov r4, r0
 *   @0x140af4 mov r0, r5
 *   @0x140af8 bl 0xc3640 <_Z17Background_Existsi>
 *   @0x140afc subs r1, r0, #0
 *   @0x140b00 beq 0x140b68 <_Z25F_ActionReplaceBackgroundR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x140b04 mov r0, r4
 *   @0x140b08 bl 0x214e48 <_Z10FileExistsPKc>
 *   @0x140b0c subs r1, r0, #0
 *   @0x140b10 beq 0x140b58 <_Z25F_ActionReplaceBackgroundR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x140b14 mov r0, r5
 *   @0x140b18 bl 0xc3794 <_Z15Background_Datai>
 *   @0x140b1c mov r6, r0
 *   @0x140b20 bl 0xc2d88 <_ZN11CBackground14GetTransparentEv>
 *   @0x140b24 mov r8, r0
 *   @0x140b28 mov r0, r6
 *   @0x140b2c bl 0xc2d90 <_ZN11CBackground6SmoothEv>
 *   @0x140b30 mov r7, r0
 *   @0x140b34 mov r0, r6
 *   @0x140b38 bl 0xc2d98 <_ZN11CBackground10GetPreloadEv>
 *   @0x140b3c mov r2, r8
 *   @0x140b40 mov r3, r7
 *   @0x140b44 mov r1, r4
 *   @0x140b48 str r0, [sp, #0x18]
 *   @0x140b4c mov r0, r5
 *   @0x140b50 pop {r4, r5, r6, r7, r8, lr}
 *   @0x140b54 b 0xc3aa4 <_Z18Background_ReplaceiPKcbbb>
 *   @0x140b58 ldr r0, [pc, #0x18]
 *   @0x140b5c pop {r4, r5, r6, r7, r8, lr}
 *   @0x140b60 add r0, pc, r0
 *   @0x140b64 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x140b68 ldr r0, [pc, #0xc]
 *   @0x140b6c pop {r4, r5, r6, r7, r8, lr}
 *   @0x140b70 add r0, pc, r0
 *   @0x140b74 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x140b78 andseq pc, pc, r0, lsl lr
 *   @0x140b7c ldrsbeq pc, [pc], -r4
 *
 * ══ §57/168 F_D3DVertexNormalColor(RValue&, CInstance*, CInstance*, int, RValue*)  0x143ee0  size 180  45 条（0x143ee0..0x143f94）
 * @func 0x143ee0 0x143fa8  size 200  50 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×7 / YYGetInt32(RValue const*, int) / GR_3D_Vertex_N_Color(float, float, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0x38×1 / 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x143ee0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x143ee4 sub sp, sp, #20
 *   @0x143ee8 mov r1, #0
 *   @0x143eec ldr r4, [sp, #0x38]
 *   @0x143ef0 mov r0, r4
 *   @0x143ef4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x143ef8 mov r1, #1
 *   @0x143efc mov r5, r0
 *   @0x143f00 mov r0, r4
 *   @0x143f04 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x143f08 mov r1, #2
 *   @0x143f0c mov r8, r0
 *   @0x143f10 mov r0, r4
 *   @0x143f14 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x143f18 mov r1, #3
 *   @0x143f1c mov r7, r0
 *   @0x143f20 mov r0, r4
 *   @0x143f24 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x143f28 mov r1, #4
 *   @0x143f2c mov r6, r0
 *   @0x143f30 mov r0, r4
 *   @0x143f34 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x143f38 mov r1, #5
 *   @0x143f3c mov r11, r0
 *   @0x143f40 mov r0, r4
 *   @0x143f44 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x143f48 mov r1, #6
 *   @0x143f4c mov r10, r0
 *   @0x143f50 mov r0, r4
 *   @0x143f54 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x143f58 mov r1, #7
 *   @0x143f5c mov r9, r0
 *   @0x143f60 mov r0, r4
 *   @0x143f64 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x143f68 str r11, [sp]
 *   @0x143f6c str r10, [sp, #0x4]
 *   @0x143f70 mov r1, r8
 *   @0x143f74 str r9, [sp, #0x8]
 *   @0x143f78 mov r2, r7
 *   @0x143f7c mov r3, r6
 *   @0x143f80 str r0, [sp, #0xc]
 *   @0x143f84 mov r0, r5
 *   @0x143f88 bl 0x1772d0 <_Z20GR_3D_Vertex_N_Colorffffffjf>
 *   @0x143f8c add sp, sp, #20
 *   @0x143f90 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §58/168 F_D3DVertexNormalTexture(RValue&, CInstance*, CInstance*, int, RValue*)  0x143f94  size 180  45 条（0x143f94..0x144048）
 * @func 0x143f94 0x144048  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×8 / GR_3D_Vertex_N_Texture(float, float, float, float, float, float, float, float)
 * 字段偏移 top8: 0x38×1 / 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x143f94 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x143f98 sub sp, sp, #20
 *   @0x143f9c mov r1, #0
 *   @0x143fa0 ldr r4, [sp, #0x38]
 *   @0x143fa4 mov r0, r4
 *   @0x143fa8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x143fac mov r1, #1
 *   @0x143fb0 mov r5, r0
 *   @0x143fb4 mov r0, r4
 *   @0x143fb8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x143fbc mov r1, #2
 *   @0x143fc0 mov r8, r0
 *   @0x143fc4 mov r0, r4
 *   @0x143fc8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x143fcc mov r1, #3
 *   @0x143fd0 mov r7, r0
 *   @0x143fd4 mov r0, r4
 *   @0x143fd8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x143fdc mov r1, #4
 *   @0x143fe0 mov r6, r0
 *   @0x143fe4 mov r0, r4
 *   @0x143fe8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x143fec mov r1, #5
 *   @0x143ff0 mov r11, r0
 *   @0x143ff4 mov r0, r4
 *   @0x143ff8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x143ffc mov r1, #6
 *   @0x144000 mov r10, r0
 *   @0x144004 mov r0, r4
 *   @0x144008 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14400c mov r1, #7
 *   @0x144010 mov r9, r0
 *   @0x144014 mov r0, r4
 *   @0x144018 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14401c str r11, [sp]
 *   @0x144020 str r10, [sp, #0x4]
 *   @0x144024 mov r1, r8
 *   @0x144028 str r9, [sp, #0x8]
 *   @0x14402c mov r2, r7
 *   @0x144030 mov r3, r6
 *   @0x144034 str r0, [sp, #0xc]
 *   @0x144038 mov r0, r5
 *   @0x14403c bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff>
 *   @0x144040 add sp, sp, #20
 *   @0x144044 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §59/168 F_D3DModelVertexTextureColor(RValue&, CInstance*, CInstance*, int, RValue*)  0x145670  size 180  45 条（0x145670..0x145724）
 * @func 0x145670 0x145724  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×6 / YYGetInt32(RValue const*, int)×2 / GR_3DM_Vertex_Texture_Color(int, float, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0x38×1 / 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x145670 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x145674 sub sp, sp, #20
 *   @0x145678 mov r1, #0
 *   @0x14567c ldr r4, [sp, #0x38]
 *   @0x145680 mov r0, r4
 *   @0x145684 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x145688 mov r1, #1
 *   @0x14568c mov r5, r0
 *   @0x145690 mov r0, r4
 *   @0x145694 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145698 mov r1, #2
 *   @0x14569c mov r8, r0
 *   @0x1456a0 mov r0, r4
 *   @0x1456a4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1456a8 mov r1, #3
 *   @0x1456ac mov r7, r0
 *   @0x1456b0 mov r0, r4
 *   @0x1456b4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1456b8 mov r1, #4
 *   @0x1456bc mov r6, r0
 *   @0x1456c0 mov r0, r4
 *   @0x1456c4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1456c8 mov r1, #5
 *   @0x1456cc mov r11, r0
 *   @0x1456d0 mov r0, r4
 *   @0x1456d4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1456d8 mov r1, #6
 *   @0x1456dc mov r10, r0
 *   @0x1456e0 mov r0, r4
 *   @0x1456e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1456e8 mov r1, #7
 *   @0x1456ec mov r9, r0
 *   @0x1456f0 mov r0, r4
 *   @0x1456f4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1456f8 str r11, [sp]
 *   @0x1456fc str r10, [sp, #0x4]
 *   @0x145700 mov r1, r8
 *   @0x145704 str r9, [sp, #0x8]
 *   @0x145708 mov r2, r7
 *   @0x14570c mov r3, r6
 *   @0x145710 str r0, [sp, #0xc]
 *   @0x145714 mov r0, r5
 *   @0x145718 bl 0x1655e0 <_Z27GR_3DM_Vertex_Texture_Colorifffffjf>
 *   @0x14571c add sp, sp, #20
 *   @0x145720 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §60/168 F_GPUGetFog(RValue&, CInstance*, CInstance*, int, RValue*)  0x145fd8  size 180  43 条（0x145fd8..0x14608c）
 * @func 0x145fd8 0x14608c  size 180  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RenderStateManager::GetRenderState(eRenderState)×4 / CreateArray(RValue*, int, ...)
 * 字段偏移 top8: 0x1c×2 / 0x18×2 / 0x9c×1
 * VFP 指令 15 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x145fd8 push {r4, r5, lr}
 *   @0x145fdc vpush {d8}
 *   @0x145fe0 mov r5, r0
 *   @0x145fe4 ldr r4, [pc, #0x9c]
 *   @0x145fe8 sub sp, sp, #36
 *   @0x145fec mov r1, #17
 *   @0x145ff0 ldr r4, [pc, r4]
 *   @0x145ff4 mov r0, r4
 *   @0x145ff8 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState>
 *   @0x145ffc mov r1, #18
 *   @0x146000 vmov s17, r0
 *   @0x146004 mov r0, r4
 *   @0x146008 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState>
 *   @0x14600c mov r1, #13
 *   @0x146010 vmov s16, r0
 *   @0x146014 mov r0, r4
 *   @0x146018 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState>
 *   @0x14601c vmov.f64 d5, #1.000000e+00
 *   @0x146020 vldr d4, [pc, #88]
 *   @0x146024 mov r1, #15
 *   @0x146028 cmp r0, #0
 *   @0x14602c mov r0, r4
 *   @0x146030 vmovne r2, r3, d5
 *   @0x146034 vmoveq r2, r3, d4
 *   @0x146038 str r2, [sp, #0x1c]
 *   @0x14603c str r3, [sp, #0x18]
 *   @0x146040 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState>
 *   @0x146044 vcvt.f64.f32 d6, s17
 *   @0x146048 mov r1, #4
 *   @0x14604c ldr r2, [sp, #0x1c]
 *   @0x146050 ldr r3, [sp, #0x18]
 *   @0x146054 vcvt.f64.f32 d7, s16
 *   @0x146058 vstr d6, [sp, #8]
 *   @0x14605c vstr d7, [sp, #16]
 *   @0x146060 vmov s13, r0
 *   @0x146064 mov r0, r5
 *   @0x146068 vcvt.f64.u32 d7, s13
 *   @0x14606c vstr d7, [sp]
 *   @0x146070 bl 0x120eb4 <_Z11CreateArrayP6RValueiz>
 *   @0x146074 add sp, sp, #36
 *   @0x146078 vpop {d8}
 *   @0x14607c pop {r4, r5, pc}
 *   @0x146088 eoreq r7, r10, r8, lsl #26
 *
 * ══ §61/168 FacebookAccessTokenM()  0x15f028  size 180  45 条（0x15f028..0x15f0dc）
 * @func 0x15f028 0x15f0dc  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×4 / _JNIEnv::CallStaticObjectMethod(_jclass*, _jmethodID*, ...) / 0xb6568
 * 字段偏移 top8: 0x94×2 / 0x5c×2 / 0x2a4×1 / 0x2a8×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15f028 push {r3, r4, r5, lr}
 *   @0x15f02c bl 0x290274 <getJNIEnv>
 *   @0x15f030 ldr r2, [pc, #0x94]
 *   @0x15f034 ldr r3, [pc, #0x94]
 *   @0x15f038 ldr r2, [pc, r2]
 *   @0x15f03c ldr r3, [pc, r3]
 *   @0x15f040 ldr r1, [r2]
 *   @0x15f044 ldr r2, [r3]
 *   @0x15f048 bl 0xf2840 <_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz>
 *   @0x15f04c mov r4, r0
 *   @0x15f050 bl 0x290274 <getJNIEnv>
 *   @0x15f054 mov r1, r4
 *   @0x15f058 mov r2, #0
 *   @0x15f05c ldr r3, [r0]
 *   @0x15f060 ldr r3, [r3, #0x2a4]
 *   @0x15f064 blx r3
 *   @0x15f068 mov r2, #255
 *   @0x15f06c mov r5, r0
 *   @0x15f070 ldr r0, [pc, #0x5c]
 *   @0x15f074 mov r1, r5
 *   @0x15f078 add r0, pc, r0
 *   @0x15f07c add r0, r0, #256
 *   @0x15f080 bl 0xb6568 <strncpy@plt>
 *   @0x15f084 cmp r5, #0
 *   @0x15f088 cmpne r4, #0
 *   @0x15f08c beq 0x15f0bc <_Z20FacebookAccessTokenMv+0x94>
 *   @0x15f090 bl 0x290274 <getJNIEnv>
 *   @0x15f094 mov r1, r4
 *   @0x15f098 mov r2, r5
 *   @0x15f09c ldr r3, [r0]
 *   @0x15f0a0 ldr r3, [r3, #0x2a8]
 *   @0x15f0a4 blx r3
 *   @0x15f0a8 bl 0x290274 <getJNIEnv>
 *   @0x15f0ac mov r1, r4
 *   @0x15f0b0 ldr r3, [r0]
 *   @0x15f0b4 ldr r3, [r3, #0x5c]
 *   @0x15f0b8 blx r3
 *   @0x15f0bc ldr r0, [pc, #0x14]
 *   @0x15f0c0 add r0, pc, r0
 *   @0x15f0c4 add r0, r0, #256
 *   @0x15f0c8 pop {r3, r4, r5, pc}
 *   @0x15f0cc eoreq lr, r8, r12, ror #18
 *   @0x15f0d0 eoreq r0, r9, r8, lsl #29
 *   @0x15f0d4 eorseq r5, r2, r0, asr #20
 *   @0x15f0d8 ldrshteq r5, [r2], -r8
 *
 * ══ §62/168 FacebookDialogM(char*, int, int)  0x15ff70  size 180  45 条（0x15ff70..0x160024）
 * @func 0x15ff70 0x160024  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×2 / BuildFacebookWallPost(int, _jobjectArray*&) / FacebookDialogM(char*, int, int)+0x58 / F_DsMapClear(RValue&, CInstance*, CInstance*, int, RValue*) / _JNIEnv::CallStaticVoidMethod(_jclass*, _jmethodID*, ...)
 * 字段偏移 top8: 0x1c×1 / 0x29c×1 / 0x30×1 / 0x2c×1 / 0xc×1 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15ff70 push {r4, r5, r6, r7, lr}
 *   @0x15ff74 sub sp, sp, #36
 *   @0x15ff78 mov r5, r0
 *   @0x15ff7c mov r0, r1
 *   @0x15ff80 add r1, sp, #12
 *   @0x15ff84 mov r4, r2
 *   @0x15ff88 bl 0x15faa8 <_Z21BuildFacebookWallPostiRP13_jobjectArray>
 *   @0x15ff8c cmp r4, #0
 *   @0x15ff90 blt 0x15ffc8 <_Z15FacebookDialogMPcii+0x58>
 *   @0x15ff94 vmov s13, r4
 *   @0x15ff98 add r12, sp, #32
 *   @0x15ff9c mov r0, #0
 *   @0x15ffa0 mov r3, #1
 *   @0x15ffa4 vcvt.f64.s32 d7, s13
 *   @0x15ffa8 mov r1, r0
 *   @0x15ffac mov r2, r0
 *   @0x15ffb0 str r0, [sp, #0x1c]
 *   @0x15ffb4 vmov r6, r7, d7
 *   @0x15ffb8 strd r6, r7, [r12, #-16]!
 *   @0x15ffbc mov r0, r12
 *   @0x15ffc0 str r12, [sp]
 *   @0x15ffc4 bl 0xfed40 <_Z12F_DsMapClearR6RValueP9CInstanceS2_iPS_>
 *   @0x15ffc8 bl 0x290274 <getJNIEnv>
 *   @0x15ffcc mov r1, r5
 *   @0x15ffd0 ldr r3, [r0]
 *   @0x15ffd4 ldr r3, [r3, #0x29c]
 *   @0x15ffd8 blx r3
 *   @0x15ffdc mov r5, r0
 *   @0x15ffe0 bl 0x290274 <getJNIEnv>
 *   @0x15ffe4 ldr r1, [pc, #0x30]
 *   @0x15ffe8 mov r3, r5
 *   @0x15ffec ldr r12, [pc, #0x2c]
 *   @0x15fff0 ldr lr, [sp, #0xc]
 *   @0x15fff4 ldr r1, [pc, r1]
 *   @0x15fff8 ldr r12, [pc, r12]
 *   @0x15fffc ldr r1, [r1]
 *   @0x160000 ldr r2, [r12]
 *   @0x160004 str r4, [sp, #0x4]
 *   @0x160008 str lr, [sp]
 *   @0x16000c bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x160010 mov r0, #1
 *   @0x160014 add sp, sp, #36
 *   @0x160018 pop {r4, r5, r6, r7, pc}
 *   @0x16001c .word 0x0028d9b0
 *   @0x160020 eoreq pc, r8, r0, lsl pc
 *
 * ══ §63/168 YYGML_draw_point_ext(float, float, unsigned int)  0x16a168  size 180  45 条（0x16a168..0x16a21c）
 * @func 0x16a168 0x16a21c  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x16a17c→0x4859c0, 0x16a1a8→0x3f23d4, 0x16a1ac→0x3f23d8, 0x16a1b4→0x4859ac, 0x16a1cc→0x3f23cc
 * 调用序列: Graphics::AllocVerts(ePrimType, void*, int, int)
 * 字段偏移 top8: 0x5c×2 / 0x88×1 / 0x84×1 / 0x58×1 / 0x44×1 / 0x8×1 / 0xc×1
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16a168 push {r3, r4, r5, lr}
 *   @0x16a16c vpush {d8}
 *   @0x16a170 vmov s17, r1
 *   @0x16a174 ldr r4, [pc, #0x88]
 *   @0x16a178 vmov s16, r0
 *   @0x16a17c ldr r12, [pc, #0x84]
 *   @0x16a180 mov r0, #1
 *   @0x16a184 add r4, pc, r4
 *   @0x16a188 mov r5, r2
 *   @0x16a18c mov r3, r0
 *   @0x16a190 mov r2, #16
 *   @0x16a194 ldr r1, [r4, r12]
 *   @0x16a198 bic r5, r5, #-16777216
 *   @0x16a19c ldr r1, [r1]
 *   @0x16a1a0 ldr r1, [r1]
 *   @0x16a1a4 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x16a1a8 ldr r1, [pc, #0x5c]
 *   @0x16a1ac ldr r3, [pc, #0x5c]
 *   @0x16a1b0 vldr s15, [pc, #72]
 *   @0x16a1b4 ldr r2, [pc, #0x58]
 *   @0x16a1b8 ldr r1, [r4, r1]
 *   @0x16a1bc vldr s14, [r1]
 *   @0x16a1c0 ldr r3, [r4, r3]
 *   @0x16a1c4 vmla.f32 s17, s14, s15
 *   @0x16a1c8 vldr s14, [r3]
 *   @0x16a1cc ldr r3, [pc, #0x44]
 *   @0x16a1d0 vmla.f32 s16, s14, s15
 *   @0x16a1d4 vstr s17, [r0, #4]
 *   @0x16a1d8 vstr s16, [r0]
 *   @0x16a1dc ldr r2, [r4, r2]
 *   @0x16a1e0 vpop {d8}
 *   @0x16a1e4 ldr r2, [r2]
 *   @0x16a1e8 str r2, [r0, #0x8]
 *   @0x16a1ec ldr r3, [r4, r3]
 *   @0x16a1f0 ldr r3, [r3]
 *   @0x16a1f4 orr r5, r5, r3, lsl #24
 *   @0x16a1f8 str r5, [r0, #0xc]
 *   @0x16a1fc pop {r3, r4, r5, pc}
 *   @0x16a200 stclo p7, c13, [r3], #-40
 *   @0x16a204 eoreq r7, r8, r12, asr #21
 *   @0x16a208 .word 0xffffe4e0
 *   @0x16a20c .word 0xffffe520
 *   @0x16a210 .word 0xffffe524
 *   @0x16a214 .word 0xffffbcd0
 *   @0x16a218 .word 0xffffc0b0
 *
 * ══ §64/168 GR_Surface_DrawGeneral(int, float, float, float, float, float, float, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, float)  0x171fa4  size 180  45 条（0x171fa4..0x172058）
 * @func 0x171fa4 0x172058  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Surface_Get(int)
 * 字段偏移 top8: 0x58×2 / 0x5c×2 / 0x60×2 / 0x64×2 / 0x68×2 / 0x4×1
 * VFP 指令 18 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x171fa4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x171fa8 vpush {d8, d9, d10}
 *   @0x171fac sub sp, sp, #4
 *   @0x171fb0 vldr s21, [sp, #64]
 *   @0x171fb4 mov r10, r1
 *   @0x171fb8 mov r9, r2
 *   @0x171fbc vldr s20, [sp, #68]
 *   @0x171fc0 mov r8, r3
 *   @0x171fc4 vldr s19, [sp, #72]
 *   @0x171fc8 vldr s18, [sp, #76]
 *   @0x171fcc vldr s17, [sp, #80]
 *   @0x171fd0 vldr s16, [sp, #84]
 *   @0x171fd4 ldr r7, [sp, #0x58]
 *   @0x171fd8 ldr r6, [sp, #0x5c]
 *   @0x171fdc ldr r5, [sp, #0x60]
 *   @0x171fe0 ldr r4, [sp, #0x64]
 *   @0x171fe4 ldr r11, [sp, #0x68]
 *   @0x171fe8 bl 0x170f48 <_Z14GR_Surface_Geti>
 *   @0x171fec cmp r0, #0
 *   @0x171ff0 beq 0x172048 <_Z22GR_Surface_DrawGeneralifffffffffjjjjf+0xa4>
 *   @0x171ff4 vldr s15, [pc, #88]
 *   @0x171ff8 vmul.f32 s16, s16, s15
 *   @0x171ffc ldr r0, [r0, #0x4]
 *   @0x172000 mov r1, r10
 *   @0x172004 vstr s21, [sp, #64]
 *   @0x172008 vstr s20, [sp, #68]
 *   @0x17200c vstr s19, [sp, #72]
 *   @0x172010 vstr s18, [sp, #76]
 *   @0x172014 vstr s17, [sp, #80]
 *   @0x172018 str r7, [sp, #0x58]
 *   @0x17201c str r6, [sp, #0x5c]
 *   @0x172020 mov r2, r9
 *   @0x172024 str r5, [sp, #0x60]
 *   @0x172028 mov r3, r8
 *   @0x17202c str r4, [sp, #0x64]
 *   @0x172030 str r11, [sp, #0x68]
 *   @0x172034 vstr s16, [sp, #84]
 *   @0x172038 add sp, sp, #4
 *   @0x17203c vpop {d8, d9, d10}
 *   @0x172040 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x172044 b 0x175834 <_Z26GR_Texture_Draw_Part_Colorifffffffffjjjjf>
 *   @0x172048 add sp, sp, #4
 *   @0x17204c vpop {d8, d9, d10}
 *   @0x172050 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x172054 vstmialo lr, {s30, s31}
 *
 * ══ §65/168 GR_Window_GUI_Convert(int, int, int&, int&)  0x179b48  size 180  45 条（0x179b48..0x179bfc）
 * @func 0x179b48 0x179bfc  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x179b58→0x3f50cc, 0x179b64→0x3f50d0, 0x179b74→0x3f26c0, 0x179b8c→0x3f26bc, 0x179b9c→0x5425ac, 0x179bb8→0x5425a8
 * 调用序列: __divsi3×2
 * 字段偏移 top8: 0x88×1 / 0x84×1 / 0x7c×1 / 0x70×1 / 0x5c×1 / 0x50×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x179b48 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x179b4c mov r7, r1
 *   @0x179b50 ldr r4, [pc, #0x88]
 *   @0x179b54 mov r9, r3
 *   @0x179b58 ldr r1, [pc, #0x84]
 *   @0x179b5c mov r8, r2
 *   @0x179b60 add r4, pc, r4
 *   @0x179b64 ldr r12, [pc, #0x7c]
 *   @0x179b68 ldr r3, [r4, r1]
 *   @0x179b6c ldr r2, [r4, r12]
 *   @0x179b70 ldr r5, [r3]
 *   @0x179b74 ldr r3, [pc, #0x70]
 *   @0x179b78 ldr r12, [r2]
 *   @0x179b7c ldr r3, [r4, r3]
 *   @0x179b80 cmp r12, #0
 *   @0x179b84 ldrlt r12, [r3]
 *   @0x179b88 ldrge r1, [r3]
 *   @0x179b8c ldr r3, [pc, #0x5c]
 *   @0x179b90 movlt r1, r12
 *   @0x179b94 cmp r5, #0
 *   @0x179b98 ldr r6, [r4, r3]
 *   @0x179b9c ldr r3, [pc, #0x50]
 *   @0x179ba0 ldrlt r5, [r6]
 *   @0x179ba4 ldr r3, [r4, r3]
 *   @0x179ba8 ldr r3, [r3]
 *   @0x179bac rsb r0, r3, r0
 *   @0x179bb0 mul r0, r12, r0
 *   @0x179bb4 bl 0x318d10 <__divsi3>
 *   @0x179bb8 ldr r3, [pc, #0x38]
 *   @0x179bbc str r0, [r8]
 *   @0x179bc0 ldr r3, [r4, r3]
 *   @0x179bc4 ldr r1, [r6]
 *   @0x179bc8 ldr r3, [r3]
 *   @0x179bcc rsb r0, r3, r7
 *   @0x179bd0 mul r0, r5, r0
 *   @0x179bd4 bl 0x318d10 <__divsi3>
 *   @0x179bd8 str r0, [r9]
 *   @0x179bdc pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x179be0 .word 0x002780f0
 *   @0x179be4 .word 0xffffdf24
 *   @0x179be8 .word 0xffffdf18
 *   @0x179bec .word 0xffffe24c
 *   @0x179bf0 .word 0xffffe250
 *   @0x179bf4 .word 0xffffe6a8
 *   @0x179bf8 .word 0xffffe6ac
 *
 * ══ §66/168 GraphicsRecorder::ChangeColour(unsigned int)  0x189120  size 180  45 条（0x189120..0x1891d4）
 * @func 0x189120 0x1891d4  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GraphicsRecorder::ChangeColour(unsigned int)+0x44 / GraphicsRecorder::ChangeColour(unsigned int)+0x74 / GraphicsRecorder::ChangeColour(unsigned int)+0xa4 / GraphicsRecorder::DeleteHWBuffers()
 * 字段偏移 top8: 0x18×3 / 0x8×2 / 0x1c×1 / 0x14×1 / 0x2c×1 / 0x24×1 / 0x3c×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x189120 push {r3, r4, r5, lr}
 *   @0x189124 mov r4, r0
 *   @0x189128 ldr r3, [r0, #0x8]
 *   @0x18912c ands r12, r3, #1
 *   @0x189130 popne {r3, r4, r5, pc}
 *   @0x189134 ldr r0, [r0, #0x1c]
 *   @0x189138 bic r5, r1, #1
 *   @0x18913c ldr r2, [r4, #0x14]
 *   @0x189140 cmp r0, #0
 *   @0x189144 ble 0x189164 <_ZN16GraphicsRecorder12ChangeColourEj+0x44>
 *   @0x189148 ldr lr, [r2, #0x18]
 *   @0x18914c add r12, r12, #1
 *   @0x189150 add r2, r2, #36
 *   @0x189154 cmp r3, lr
 *   @0x189158 streq r5, [r2, #-0xc]
 *   @0x18915c cmp r12, r0
 *   @0x189160 bne 0x189148 <_ZN16GraphicsRecorder12ChangeColourEj+0x28>
 *   @0x189164 ldr r1, [r4, #0x2c]
 *   @0x189168 ldr r2, [r4, #0x24]
 *   @0x18916c cmp r1, #0
 *   @0x189170 movgt r12, #0
 *   @0x189174 ble 0x189194 <_ZN16GraphicsRecorder12ChangeColourEj+0x74>
 *   @0x189178 ldr lr, [r2, #0x18]
 *   @0x18917c add r12, r12, #1
 *   @0x189180 add r2, r2, #36
 *   @0x189184 cmp r3, lr
 *   @0x189188 streq r5, [r2, #-0xc]
 *   @0x18918c cmp r12, r1
 *   @0x189190 bne 0x189178 <_ZN16GraphicsRecorder12ChangeColourEj+0x58>
 *   @0x189194 ldr r1, [r4, #0x3c]
 *   @0x189198 ldr r2, [r4, #0x34]
 *   @0x18919c cmp r1, #0
 *   @0x1891a0 movgt r12, #0
 *   @0x1891a4 ble 0x1891c4 <_ZN16GraphicsRecorder12ChangeColourEj+0xa4>
 *   @0x1891a8 ldr lr, [r2, #0x18]
 *   @0x1891ac add r12, r12, #1
 *   @0x1891b0 add r2, r2, #36
 *   @0x1891b4 cmp r3, lr
 *   @0x1891b8 streq r5, [r2, #-0xc]
 *   @0x1891bc cmp r12, r1
 *   @0x1891c0 bne 0x1891a8 <_ZN16GraphicsRecorder12ChangeColourEj+0x88>
 *   @0x1891c4 mov r0, r4
 *   @0x1891c8 bl 0x1857d8 <_ZN16GraphicsRecorder15DeleteHWBuffersEv>
 *   @0x1891cc str r5, [r4, #0x8]
 *   @0x1891d0 pop {r3, r4, r5, pc}
 *
 * ══ §67/168 HTTP_REQ_CONTEXT::~HTTP_REQ_CONTEXT()  0x18d724  size 180  45 条（0x18d724..0x18d7d8）
 * @func 0x18d724 0x18d7d8  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / DS_AutoMutex::DS_AutoMutex() / CDS_Map::~CDS_Map() / operator delete(void*) / DS_AutoMutex::~DS_AutoMutex()
 * 字段偏移 top8: 0x2c×3 / 0x34×2 / 0x20×2 / 0x4×2 / 0xa4×1 / 0x64×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18d724 ldr r3, [pc, #0xa4]
 *   @0x18d728 push {r4, r5, r6, r7, lr}
 *   @0x18d72c ldr r3, [pc, r3]
 *   @0x18d730 mov r4, r0
 *   @0x18d734 add r3, r3, #8
 *   @0x18d738 ldr r0, [r0, #0x34]
 *   @0x18d73c sub sp, sp, #12
 *   @0x18d740 str r3, [r4]
 *   @0x18d744 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x18d748 mov r3, #0
 *   @0x18d74c ldr r0, [r4, #0x20]
 *   @0x18d750 str r3, [r4, #0x34]
 *   @0x18d754 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x18d758 ldr r3, [r4, #0x2c]
 *   @0x18d75c cmn r3, #1
 *   @0x18d760 beq 0x18d7bc <_ZN16HTTP_REQ_CONTEXTD2Ev+0x98>
 *   @0x18d764 add r7, sp, #4
 *   @0x18d768 ldr r5, [pc, #0x64]
 *   @0x18d76c mov r0, r7
 *   @0x18d770 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0x18d774 ldr r5, [pc, r5]
 *   @0x18d778 ldr r2, [r4, #0x2c]
 *   @0x18d77c ldr r3, [r5, #0x4]
 *   @0x18d780 add r1, r3, r2, lsl #2
 *   @0x18d784 ldr r6, [r3, r2, lsl #2]
 *   @0x18d788 cmp r6, #0
 *   @0x18d78c beq 0x18d7ac <_ZN16HTTP_REQ_CONTEXTD2Ev+0x88>
 *   @0x18d790 mov r0, r6
 *   @0x18d794 bl 0x20d9e8 <_ZN7CDS_MapD2Ev>
 *   @0x18d798 mov r0, r6
 *   @0x18d79c bl 0x27d1d0 <_ZdlPv>
 *   @0x18d7a0 ldr r1, [r4, #0x2c]
 *   @0x18d7a4 ldr r3, [r5, #0x4]
 *   @0x18d7a8 add r1, r3, r1, lsl #2
 *   @0x18d7ac mov r3, #0
 *   @0x18d7b0 mov r0, r7
 *   @0x18d7b4 str r3, [r1]
 *   @0x18d7b8 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x18d7bc mov r3, #0
 *   @0x18d7c0 mov r0, r4
 *   @0x18d7c4 str r3, [r4, #0x20]
 *   @0x18d7c8 add sp, sp, #12
 *   @0x18d7cc pop {r4, r5, r6, r7, pc}
 *   @0x18d7d0 eoreq r2, r6, r12, lsl #30
 *   @0x18d7d4 eoreq r0, r6, r8, asr #3
 *
 * ══ §68/168 CObjectGM::~CObjectGM()  0x19d558  size 180  45 条（0x19d558..0x19d60c）
 * @func 0x19d558 0x19d60c  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / CObjectGM::Clear()
 * 字段偏移 top8: 0xd0×2 / 0x8×2 / 0x4×2 / 0xc4×2 / 0xd8×1 / 0xd4×1 / 0xcc×1 / 0xc8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19d558 push {r4, r5, r6, lr}
 *   @0x19d55c mov r6, r0
 *   @0x19d560 bl 0x19d3d8 <_ZN9CObjectGM5ClearEv>
 *   @0x19d564 ldr r4, [r6, #0xd0]
 *   @0x19d568 cmp r4, #0
 *   @0x19d56c beq 0x19d5a4 <_ZN9CObjectGMD2Ev+0x4c>
 *   @0x19d570 ldr r3, [r4, #0x8]
 *   @0x19d574 ldr r5, [r4]
 *   @0x19d578 cmp r3, #0
 *   @0x19d57c mov r0, r3
 *   @0x19d580 beq 0x19d590 <_ZN9CObjectGMD2Ev+0x38>
 *   @0x19d584 ldr r3, [r3]
 *   @0x19d588 ldr r3, [r3, #0x4]
 *   @0x19d58c blx r3
 *   @0x19d590 mov r0, r4
 *   @0x19d594 mov r4, r5
 *   @0x19d598 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x19d59c cmp r5, #0
 *   @0x19d5a0 bne 0x19d570 <_ZN9CObjectGMD2Ev+0x18>
 *   @0x19d5a4 ldr r4, [r6, #0xc4]
 *   @0x19d5a8 mov r3, #0
 *   @0x19d5ac str r3, [r6, #0xd8]
 *   @0x19d5b0 cmp r4, r3
 *   @0x19d5b4 str r3, [r6, #0xd4]
 *   @0x19d5b8 str r3, [r6, #0xd0]
 *   @0x19d5bc beq 0x19d5f4 <_ZN9CObjectGMD2Ev+0x9c>
 *   @0x19d5c0 ldr r3, [r4, #0x8]
 *   @0x19d5c4 ldr r5, [r4]
 *   @0x19d5c8 cmp r3, #0
 *   @0x19d5cc mov r0, r3
 *   @0x19d5d0 beq 0x19d5e0 <_ZN9CObjectGMD2Ev+0x88>
 *   @0x19d5d4 ldr r3, [r3]
 *   @0x19d5d8 ldr r3, [r3, #0x4]
 *   @0x19d5dc blx r3
 *   @0x19d5e0 mov r0, r4
 *   @0x19d5e4 mov r4, r5
 *   @0x19d5e8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x19d5ec cmp r5, #0
 *   @0x19d5f0 bne 0x19d5c0 <_ZN9CObjectGMD2Ev+0x68>
 *   @0x19d5f4 mov r3, #0
 *   @0x19d5f8 mov r0, r6
 *   @0x19d5fc str r3, [r6, #0xcc]
 *   @0x19d600 str r3, [r6, #0xc8]
 *   @0x19d604 str r3, [r6, #0xc4]
 *   @0x19d608 pop {r4, r5, r6, pc}
 *
 * ══ §69/168 F_LayerCreate(RValue&, CInstance*, CInstance*, int, RValue*)  0x1c3798  size 180  45 条（0x1c3798..0x1c384c）
 * @func 0x1c3798 0x1c384c  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_LayerCreate(RValue&, CInstance*, CInstance*, int, RValue*)+0x84 / YYGetInt32(RValue const*, int) / YYGetString(RValue const*, int) / CLayerManager::GetTargetRoomObj() / CLayerManager::AddLayer(CRoom*, int, char const*)
 * 字段偏移 top8: 0xc×2 / 0x18×1 / 0x4×1 / 0x20×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c3798 push {r4, r5, r6, r7, r8, lr}
 *   @0x1c379c subs r7, r3, #0
 *   @0x1c37a0 mov r2, #0
 *   @0x1c37a4 mov r4, r0
 *   @0x1c37a8 mov r5, r2
 *   @0x1c37ac ldr r6, [sp, #0x18]
 *   @0x1c37b0 movt r2, #0xbff0
 *   @0x1c37b4 str r5, [r0, #0xc]
 *   @0x1c37b8 str r2, [r0, #0x4]
 *   @0x1c37bc str r5, [r0]
 *   @0x1c37c0 ble 0x1c381c <_Z13F_LayerCreateR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x1c37c4 mov r0, r6
 *   @0x1c37c8 mov r1, r5
 *   @0x1c37cc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1c37d0 cmp r7, #1
 *   @0x1c37d4 mov r8, r0
 *   @0x1c37d8 beq 0x1c37ec <_Z13F_LayerCreateR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x1c37dc mov r0, r6
 *   @0x1c37e0 mov r1, #1
 *   @0x1c37e4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1c37e8 mov r5, r0
 *   @0x1c37ec bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1c37f0 mov r1, r8
 *   @0x1c37f4 mov r2, r5
 *   @0x1c37f8 bl 0x1c3598 <_ZN13CLayerManager8AddLayerEP5CRoomiPKc>
 *   @0x1c37fc cmp r0, #0
 *   @0x1c3800 beq 0x1c3830 <_Z13F_LayerCreateR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x1c3804 ldr r2, [r0]
 *   @0x1c3808 vmov s15, r2
 *   @0x1c380c vcvt.f64.s32 d7, s15
 *   @0x1c3810 vmov r2, r3, d7
 *   @0x1c3814 stm r4, {r2, r3}
 *   @0x1c3818 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1c381c ldr r0, [pc, #0x20]
 *   @0x1c3820 mov r1, r5
 *   @0x1c3824 pop {r4, r5, r6, r7, r8, lr}
 *   @0x1c3828 add r0, pc, r0
 *   @0x1c382c b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1c3830 mov r1, r0
 *   @0x1c3834 ldr r0, [pc, #0xc]
 *   @0x1c3838 pop {r4, r5, r6, r7, r8, lr}
 *   @0x1c383c add r0, pc, r0
 *   @0x1c3840 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1c3844 andseq r12, r8, r0, ror #31
 *   @0x1c3848 ldrsheq r12, [r8], -r12
 *
 * ══ §70/168 CScript::LoadFromStream(CStream*)  0x1dfc88  size 180  45 条（0x1dfc88..0x1dfd3c）
 * @func 0x1dfc88 0x1dfd3c  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CScript::Clear() / CStream::ReadInteger() / CStream::ReadString() / CStream::ReadCompressedStream() / operator new(unsigned int) / CStream::CStream(int) / CStream::CopyFrom(CStream*, long long, bool) / CStream::~CStream()
 * 字段偏移 top8: 0x10×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dfc88 push {r4, r5, r6, r7, lr}
 *   @0x1dfc8c mov r5, r1
 *   @0x1dfc90 sub sp, sp, #12
 *   @0x1dfc94 mov r6, r0
 *   @0x1dfc98 bl 0x1dfbb0 <_ZN7CScript5ClearEv>
 *   @0x1dfc9c mov r0, r5
 *   @0x1dfca0 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x1dfca4 cmp r0, #400
 *   @0x1dfca8 mov r4, r0
 *   @0x1dfcac beq 0x1dfce0 <_ZN7CScript14LoadFromStreamEP7CStream+0x58>
 *   @0x1dfcb0 cmp r0, #800
 *   @0x1dfcb4 beq 0x1dfcd0 <_ZN7CScript14LoadFromStreamEP7CStream+0x48>
 *   @0x1dfcb8 cmp r4, #400
 *   @0x1dfcbc cmpne r4, #800
 *   @0x1dfcc0 movne r0, #0
 *   @0x1dfcc4 moveq r0, #1
 *   @0x1dfcc8 add sp, sp, #12
 *   @0x1dfccc pop {r4, r5, r6, r7, pc}
 *   @0x1dfcd0 mov r0, r5
 *   @0x1dfcd4 bl 0x201950 <_ZN7CStream10ReadStringEv>
 *   @0x1dfcd8 str r0, [r6, #0x10]
 *   @0x1dfcdc b 0x1dfcb8 <_ZN7CScript14LoadFromStreamEP7CStream+0x30>
 *   @0x1dfce0 mov r0, r5
 *   @0x1dfce4 bl 0x201db0 <_ZN7CStream20ReadCompressedStreamEv>
 *   @0x1dfce8 mov r5, r0
 *   @0x1dfcec mov r0, #32
 *   @0x1dfcf0 bl 0x27c524 <_Znwj>
 *   @0x1dfcf4 mov r1, #0
 *   @0x1dfcf8 mov r7, r0
 *   @0x1dfcfc bl 0x2010ec <_ZN7CStreamC2Ei>
 *   @0x1dfd00 str r7, [r6, #0x4]
 *   @0x1dfd04 mov r12, #1
 *   @0x1dfd08 mov r0, r7
 *   @0x1dfd0c mov r1, r5
 *   @0x1dfd10 mov r2, #0
 *   @0x1dfd14 mov r3, #0
 *   @0x1dfd18 str r12, [sp]
 *   @0x1dfd1c bl 0x2015c8 <_ZN7CStream8CopyFromEPS_xb>
 *   @0x1dfd20 cmp r5, #0
 *   @0x1dfd24 beq 0x1dfcb8 <_ZN7CScript14LoadFromStreamEP7CStream+0x30>
 *   @0x1dfd28 mov r0, r5
 *   @0x1dfd2c bl 0x201328 <_ZN7CStreamD2Ev>
 *   @0x1dfd30 mov r0, r5
 *   @0x1dfd34 bl 0x27d1d0 <_ZdlPv>
 *   @0x1dfd38 b 0x1dfcb8 <_ZN7CScript14LoadFromStreamEP7CStream+0x30>
 *
 * ══ §71/168 AddVertexFormat(VertexFormat*)  0x1e2d68  size 180  45 条（0x1e2d68..0x1e2e1c）
 * @func 0x1e2d68 0x1e2e1c  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x8×3 / 0x94×1 / 0x90×1 / 0x88×1 / 0x4×1 / 0x3×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e2d68 push {r4, r5, r6, r7, r8, lr}
 *   @0x1e2d6c subs r5, r0, #0
 *   @0x1e2d70 beq 0x1e2e08 <_Z15AddVertexFormatP12VertexFormat+0xa0>
 *   @0x1e2d74 ldr r12, [pc, #0x94]
 *   @0x1e2d78 mov r3, #1
 *   @0x1e2d7c ldr r4, [pc, #0x90]
 *   @0x1e2d80 movw r2, #0x132
 *   @0x1e2d84 add r12, pc, r12
 *   @0x1e2d88 ldr r1, [pc, #0x88]
 *   @0x1e2d8c ldr r4, [pc, r4]
 *   @0x1e2d90 mov r0, #16
 *   @0x1e2d94 ldr lr, [r12]
 *   @0x1e2d98 add r1, pc, r1
 *   @0x1e2d9c ldr r7, [r4]
 *   @0x1e2da0 orr r6, lr, #16777216
 *   @0x1e2da4 ldr r8, [r4, #0x4]
 *   @0x1e2da8 str r6, [r5]
 *   @0x1e2dac add lr, lr, r3
 *   @0x1e2db0 str lr, [r12]
 *   @0x1e2db4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1e2db8 and r8, r6, r8
 *   @0x1e2dbc ldr r1, [r7, r8, lsl #3]
 *   @0x1e2dc0 add r2, r7, r8, lsl #3
 *   @0x1e2dc4 cmp r1, #0
 *   @0x1e2dc8 ldrne r1, [r2, #0x4]
 *   @0x1e2dcc mov r3, r0
 *   @0x1e2dd0 str r6, [r0, #0x8]
 *   @0x1e2dd4 str r5, [r0, #0xc]
 *   @0x1e2dd8 movne r0, #0
 *   @0x1e2ddc strne r1, [r3]
 *   @0x1e2de0 strne r3, [r1, #0x4]
 *   @0x1e2de4 strne r3, [r2, #0x4]
 *   @0x1e2de8 strne r0, [r3, #0x4]
 *   @0x1e2dec ldr r3, [r4, #0x8]
 *   @0x1e2df0 streq r0, [r2, #0x4]
 *   @0x1e2df4 add r3, r3, #1
 *   @0x1e2df8 streq r0, [r7, r8, lsl #3]
 *   @0x1e2dfc streq r1, [r0, #0x4]
 *   @0x1e2e00 streq r1, [r0]
 *   @0x1e2e04 str r3, [r4, #0x8]
 *   @0x1e2e08 mov r0, r5
 *   @0x1e2e0c pop {r4, r5, r6, r7, r8, pc}
 *   @0x1e2e10 eorseq r1, r6, r0, lsl #30
 *   @0x1e2e14 eoreq lr, r0, r0, lsl r0
 *   @0x1e2e18 andseq r8, r6, r12, lsl #12
 *
 * ══ §72/168 CStream::_AllocExtraSpace(int)  0x201414  size 180  45 条（0x201414..0x2014c8）
 * @func 0x201414 0x2014c8  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::_AllocExtraSpace(int)+0xa8 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x18×2 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x201414 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x201418 subs r9, r1, #0
 *   @0x20141c mov r8, r0
 *   @0x201420 sub sp, sp, #12
 *   @0x201424 movle r0, #0
 *   @0x201428 ble 0x2014bc <_ZN7CStream16_AllocExtraSpaceEi+0xa8>
 *   @0x20142c ldrd r4, r5, [r8, #8]
 *   @0x201430 asr r1, r9, #31
 *   @0x201434 ldrd r2, r3, [r8, #16]
 *   @0x201438 mov r0, r9
 *   @0x20143c mov r6, r4
 *   @0x201440 mov r7, r5
 *   @0x201444 subs r6, r6, r2
 *   @0x201448 sbc r7, r7, r3
 *   @0x20144c cmp r6, r0
 *   @0x201450 sbcs r12, r7, r1
 *   @0x201454 movge r0, r9
 *   @0x201458 bge 0x2014bc <_ZN7CStream16_AllocExtraSpaceEi+0xa8>
 *   @0x20145c adds r0, r0, r2
 *   @0x201460 lsl r4, r4, #1
 *   @0x201464 adc r1, r1, r3
 *   @0x201468 mov r7, #0
 *   @0x20146c mov r6, r4
 *   @0x201470 cmp r0, r6
 *   @0x201474 sbcs r12, r1, r7
 *   @0x201478 addge r4, r9, r2
 *   @0x20147c movge r7, #0
 *   @0x201480 movge r6, r4
 *   @0x201484 ldr r2, [pc, #0x38]
 *   @0x201488 mov r3, #0
 *   @0x20148c ldr r0, [r8, #0x18]
 *   @0x201490 mov r1, r4
 *   @0x201494 str r3, [sp]
 *   @0x201498 add r2, pc, r2
 *   @0x20149c mov r3, #384
 *   @0x2014a0 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x2014a4 strd r6, r7, [r8, #8]
 *   @0x2014a8 cmp r0, #0
 *   @0x2014ac mov r3, r0
 *   @0x2014b0 str r3, [r8, #0x18]
 *   @0x2014b4 movne r0, r9
 *   @0x2014b8 moveq r0, #0
 *   @0x2014bc add sp, sp, #12
 *   @0x2014c0 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x2014c4 mulseq r5, r0, r2
 *
 * ══ §73/168 DsQueueEnqueue(int, int, ...)  0x2053f0  size 180  45 条（0x2053f0..0x2054a4）
 * @func 0x2053f0 0x2054a4  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DsQueueEnqueue(int, int, ...)+0xa4×2 / YYSetString(RValue*, char const*) / F_DsQueueEnqueue(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0xc×2 / 0x64×1 / 0x10×1 / 0x2c×1 / 0x3c×1 / 0x8×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2053f0 push {r1, r2, r3}
 *   @0x2053f4 cmp r0, #0
 *   @0x2053f8 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2053fc sub sp, sp, #68
 *   @0x205400 ldr r5, [sp, #0x64]
 *   @0x205404 blt 0x205494 <_Z14DsQueueEnqueueiiz+0xa4>
 *   @0x205408 vmov s13, r0
 *   @0x20540c cmp r5, #0
 *   @0x205410 mov r4, #0
 *   @0x205414 add r10, sp, #104
 *   @0x205418 vcvt.f64.s32 d7, s13
 *   @0x20541c str r4, [sp, #0x10]
 *   @0x205420 str r4, [sp, #0x2c]
 *   @0x205424 str r10, [sp, #0xc]
 *   @0x205428 vstr d7, [sp, #32]
 *   @0x20542c ble 0x205494 <_Z14DsQueueEnqueueiiz+0xa4>
 *   @0x205430 add r9, sp, #16
 *   @0x205434 add r8, sp, #32
 *   @0x205438 add r7, sp, #48
 *   @0x20543c mov r6, r4
 *   @0x205440 add r10, r10, #7
 *   @0x205444 mov r0, r7
 *   @0x205448 bic r3, r10, #7
 *   @0x20544c add r4, r4, #1
 *   @0x205450 str r6, [sp, #0x3c]
 *   @0x205454 mov r10, r3
 *   @0x205458 ldr r1, [r3, #0x8]
 *   @0x20545c ldrd r2, r3, [r10], #12
 *   @0x205460 cmp r1, #0
 *   @0x205464 strd r2, r3, [sp, #48]
 *   @0x205468 str r10, [sp, #0xc]
 *   @0x20546c beq 0x205474 <_Z14DsQueueEnqueueiiz+0x84>
 *   @0x205470 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x205474 mov r1, #0
 *   @0x205478 str r8, [sp]
 *   @0x20547c mov r2, r1
 *   @0x205480 mov r0, r9
 *   @0x205484 mov r3, #2
 *   @0x205488 bl 0xfc048 <_Z16F_DsQueueEnqueueR6RValueP9CInstanceS2_iPS_>
 *   @0x20548c cmp r4, r5
 *   @0x205490 bne 0x205440 <_Z14DsQueueEnqueueiiz+0x50>
 *   @0x205494 add sp, sp, #68
 *   @0x205498 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x20549c add sp, sp, #12
 *   @0x2054a0 bx lr
 *
 * ══ §74/168 File_TempFile(char const*)  0x214e70  size 180  45 条（0x214e70..0x214f24）
 * @func 0x214e70 0x214f24  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65b0 / YYRandom(int) / 0xb65c8 / FileExists(char const*) / YYStrDup(char const*) / 0xb65d4
 * 字段偏移 top8: 0x40c×2 / 0x98×1 / 0x90×1 / 0x8c×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x214e70 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x214e74 sub sp, sp, #1040
 *   @0x214e78 ldr r9, [pc, #0x98]
 *   @0x214e7c sub sp, sp, #4
 *   @0x214e80 add r4, sp, #12
 *   @0x214e84 ldr r6, [pc, #0x90]
 *   @0x214e88 ldr r9, [pc, r9]
 *   @0x214e8c ldr r7, [pc, #0x8c]
 *   @0x214e90 mov r8, r0
 *   @0x214e94 mov r1, #0
 *   @0x214e98 ldr r3, [r9]
 *   @0x214e9c mov r0, r4
 *   @0x214ea0 mov r2, #1024
 *   @0x214ea4 add r7, pc, r7
 *   @0x214ea8 str r3, [sp, #0x40c]
 *   @0x214eac bl 0xb65b0 <memset@plt>
 *   @0x214eb0 ldr r6, [pc, r6]
 *   @0x214eb4 movw r0, #0x86a0
 *   @0x214eb8 movt r0, #0x1
 *   @0x214ebc ldr r5, [r6]
 *   @0x214ec0 bl 0xc4600 <_Z8YYRandomi>
 *   @0x214ec4 mov r1, #1024
 *   @0x214ec8 mov r2, r7
 *   @0x214ecc str r8, [sp, #0x4]
 *   @0x214ed0 mov r3, r5
 *   @0x214ed4 str r0, [sp]
 *   @0x214ed8 mov r0, r4
 *   @0x214edc bl 0xb65c8 <snprintf@plt>
 *   @0x214ee0 mov r0, r4
 *   @0x214ee4 bl 0x214e48 <_Z10FileExistsPKc>
 *   @0x214ee8 cmp r0, #0
 *   @0x214eec bne 0x214eb4 <_Z13File_TempFilePKc+0x44>
 *   @0x214ef0 mov r0, r4
 *   @0x214ef4 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x214ef8 ldr r2, [sp, #0x40c]
 *   @0x214efc ldr r3, [r9]
 *   @0x214f00 cmp r2, r3
 *   @0x214f04 bne 0x214f14 <_Z13File_TempFilePKc+0xa4>
 *   @0x214f08 add sp, sp, #1040
 *   @0x214f0c add sp, sp, #4
 *   @0x214f10 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x214f14 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x214f18 andseq r8, sp, r8, asr #21
 *   @0x214f1c andseq r12, sp, r0, lsl r5
 *   @0x214f20 andseq lr, r3, r12, ror #23
 *
 * ══ §75/168 Sound_Replace(int, char const*, int, bool)  0x220018  size 180  45 条（0x220018..0x2200cc）
 * @func 0x220018 0x2200cc  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Sound_Replace(int, char const*, int, bool)+0xa4 / CSound::~CSound() / operator delete(void*) / operator new(unsigned int) / CSound::CSound()
 * 字段偏移 top8: 0x8c×1 / 0x10×1 / 0x4×1 / 0x2×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x220018 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x22001c subs r4, r0, #0
 *   @0x220020 mov r7, r1
 *   @0x220024 mov r6, r2
 *   @0x220028 mov r5, r3
 *   @0x22002c blt 0x2200bc <_Z13Sound_ReplaceiPKcib+0xa4>
 *   @0x220030 ldr r0, [pc, #0x8c]
 *   @0x220034 add r0, pc, r0
 *   @0x220038 ldr r12, [r0, #0x10]
 *   @0x22003c cmp r4, r12
 *   @0x220040 bge 0x2200bc <_Z13Sound_ReplaceiPKcib+0xa4>
 *   @0x220044 ldr r3, [r0]
 *   @0x220048 cmp r4, r3
 *   @0x22004c lslge r8, r4, #2
 *   @0x220050 bge 0x220078 <_Z13Sound_ReplaceiPKcib+0x60>
 *   @0x220054 ldr r3, [r0, #0x4]
 *   @0x220058 lsl r8, r4, #2
 *   @0x22005c ldr r9, [r3, r4, lsl #2]
 *   @0x220060 cmp r9, #0
 *   @0x220064 beq 0x220078 <_Z13Sound_ReplaceiPKcib+0x60>
 *   @0x220068 mov r0, r9
 *   @0x22006c bl 0x215384 <_ZN6CSoundD2Ev>
 *   @0x220070 mov r0, r9
 *   @0x220074 bl 0x27d1d0 <_ZdlPv>
 *   @0x220078 mov r0, #64
 *   @0x22007c bl 0x27c524 <_Znwj>
 *   @0x220080 mov r9, r0
 *   @0x220084 bl 0x215354 <_ZN6CSoundC2Ev>
 *   @0x220088 ldr r12, [pc, #0x38]
 *   @0x22008c mov r1, r7
 *   @0x220090 add r12, pc, r12
 *   @0x220094 ldm r12, {r2, r3}
 *   @0x220098 cmp r4, r2
 *   @0x22009c mov r2, r6
 *   @0x2200a0 str r9, [r3, r8]
 *   @0x2200a4 ldrlt r3, [r12, #0x4]
 *   @0x2200a8 movge r0, #0
 *   @0x2200ac ldrlt r0, [r3, r8]
 *   @0x2200b0 mov r3, r5
 *   @0x2200b4 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2200b8 b 0x21569c <_ZN6CSound12LoadFromFileEPKcib>
 *   @0x2200bc mov r0, #0
 *   @0x2200c0 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2200c4 subseq r5, r3, r4, lsl #6
 *   @0x2200c8 subseq r5, r3, r8, lsr #5
 *
 * ══ §76/168 _alutInputStreamConstructFromFile  0x221ce0  size 180  45 条（0x221ce0..0x221d94）
 * @func 0x221ce0 0x221d94  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _alutMalloc×2 / 0xb69f4 / 0xb6844 / 0xb6538 / 0xb65a4 / _alutSetError / 0xb655c
 * 字段偏移 top8: 0x78×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x221ce0 push {r4, r5, r6, r7, lr}
 *   @0x221ce4 mov r5, r0
 *   @0x221ce8 sub sp, sp, #108
 *   @0x221cec mov r0, #16
 *   @0x221cf0 bl 0x222a98 <_alutMalloc>
 *   @0x221cf4 subs r4, r0, #0
 *   @0x221cf8 beq 0x221d88 <_alutInputStreamConstructFromFile+0xa8>
 *   @0x221cfc mov r0, r5
 *   @0x221d00 mov r1, sp
 *   @0x221d04 bl 0xb69f4 <stat@plt>
 *   @0x221d08 cmp r0, #0
 *   @0x221d0c bne 0x221d68 <_alutInputStreamConstructFromFile+0x88>
 *   @0x221d10 ldr r1, [pc, #0x78]
 *   @0x221d14 mov r0, r5
 *   @0x221d18 add r1, pc, r1
 *   @0x221d1c bl 0xb6844 <fopen@plt>
 *   @0x221d20 subs r6, r0, #0
 *   @0x221d24 beq 0x221d68 <_alutInputStreamConstructFromFile+0x88>
 *   @0x221d28 mov r0, r5
 *   @0x221d2c bl 0xb6538 <strlen@plt>
 *   @0x221d30 add r0, r0, #1
 *   @0x221d34 bl 0x222a98 <_alutMalloc>
 *   @0x221d38 subs r7, r0, #0
 *   @0x221d3c beq 0x221d70 <_alutInputStreamConstructFromFile+0x90>
 *   @0x221d40 mov r3, #1
 *   @0x221d44 mov r1, r5
 *   @0x221d48 strb r3, [r4]
 *   @0x221d4c bl 0xb65a4 <strcpy@plt>
 *   @0x221d50 ldr r2, [sp, #0x30]
 *   @0x221d54 mov r3, r4
 *   @0x221d58 stmib r4, {r0, r2, r6}
 *   @0x221d5c mov r0, r3
 *   @0x221d60 add sp, sp, #108
 *   @0x221d64 pop {r4, r5, r6, r7, pc}
 *   @0x221d68 movw r0, #0x20e
 *   @0x221d6c bl 0x221940 <_alutSetError>
 *   @0x221d70 mov r0, r4
 *   @0x221d74 bl 0xb655c <free@plt>
 *   @0x221d78 mov r3, #0
 *   @0x221d7c mov r0, r3
 *   @0x221d80 add sp, sp, #108
 *   @0x221d84 pop {r4, r5, r6, r7, pc}
 *   @0x221d88 mov r3, r4
 *   @0x221d8c b 0x221d5c <_alutInputStreamConstructFromFile+0x7c>
 *   @0x221d90 andseq r5, r1, r0, ror #29
 *
 * ══ §77/168 _alutLoadMemoryFromInputStream  0x222664  size 180  45 条（0x222664..0x222718）
 * @func 0x222664 0x222718  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _alutInputStreamDestroy×2 / anon_221ff4+0x4c / _alutGetFormat / _alutBufferDataGetLength / _alutBufferDataGetSampleFrequency / _alutBufferDataGetData / _alutBufferDataDetachData / _alutBufferDataDestroy
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x222664 push {r4, r5, r6, r7, r8, lr}
 *   @0x222668 subs r8, r0, #0
 *   @0x22266c sub sp, sp, #8
 *   @0x222670 mov r5, r1
 *   @0x222674 mov r7, r2
 *   @0x222678 mov r6, r3
 *   @0x22267c beq 0x222704 <_alutLoadMemoryFromInputStream+0xa0>
 *   @0x222680 bl 0x222040 <_alutInputStreamReadUInt32LE+0x9c>
 *   @0x222684 subs r4, r0, #0
 *   @0x222688 mov r0, r8
 *   @0x22268c beq 0x22270c <_alutLoadMemoryFromInputStream+0xa8>
 *   @0x222690 bl 0x221dcc <_alutInputStreamDestroy>
 *   @0x222694 mov r0, r4
 *   @0x222698 add r1, sp, #4
 *   @0x22269c bl 0x2213ec <_alutGetFormat>
 *   @0x2226a0 subs r8, r0, #0
 *   @0x2226a4 beq 0x2226f0 <_alutLoadMemoryFromInputStream+0x8c>
 *   @0x2226a8 cmp r7, #0
 *   @0x2226ac beq 0x2226bc <_alutLoadMemoryFromInputStream+0x58>
 *   @0x2226b0 mov r0, r4
 *   @0x2226b4 bl 0x2213dc <_alutBufferDataGetLength>
 *   @0x2226b8 str r0, [r7]
 *   @0x2226bc cmp r5, #0
 *   @0x2226c0 ldrne r3, [sp, #0x4]
 *   @0x2226c4 strne r3, [r5]
 *   @0x2226c8 cmp r6, #0
 *   @0x2226cc beq 0x2226dc <_alutLoadMemoryFromInputStream+0x78>
 *   @0x2226d0 mov r0, r4
 *   @0x2226d4 bl 0x2213e4 <_alutBufferDataGetSampleFrequency>
 *   @0x2226d8 str r0, [r6]
 *   @0x2226dc mov r0, r4
 *   @0x2226e0 bl 0x2213c8 <_alutBufferDataGetData>
 *   @0x2226e4 mov r8, r0
 *   @0x2226e8 mov r0, r4
 *   @0x2226ec bl 0x2213d0 <_alutBufferDataDetachData>
 *   @0x2226f0 mov r0, r4
 *   @0x2226f4 bl 0x2213b8 <_alutBufferDataDestroy>
 *   @0x2226f8 mov r0, r8
 *   @0x2226fc add sp, sp, #8
 *   @0x222700 pop {r4, r5, r6, r7, r8, pc}
 *   @0x222704 mov r0, r8
 *   @0x222708 b 0x2226fc <_alutLoadMemoryFromInputStream+0x98>
 *   @0x22270c bl 0x221dcc <_alutInputStreamDestroy>
 *   @0x222710 mov r0, r4
 *   @0x222714 b 0x2226fc <_alutLoadMemoryFromInputStream+0x98>
 *
 * ══ §78/168 COggSyncThread::COggSyncThread()  0x224834  size 180  45 条（0x224834..0x2248e8）
 * @func 0x224834 0x2248e8  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / Mutex::Mutex(char const*)
 * 字段偏移 top8: 0x83c×1 / 0x834×1 / 0x838×1 / 0x83d×1 / 0x840×1 / 0x844×1 / 0x7c×1 / 0x848×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x224834 push {r4, r5, r6, lr}
 *   @0x224838 mov r4, r0
 *   @0x22483c mov r5, #0
 *   @0x224840 mov r0, #8
 *   @0x224844 strb r5, [r4, #0x83c]
 *   @0x224848 str r5, [r4, #0x834]
 *   @0x22484c str r5, [r4, #0x838]
 *   @0x224850 strb r5, [r4, #0x83d]
 *   @0x224854 str r5, [r4, #0x840]
 *   @0x224858 str r5, [r4, #0x844]
 *   @0x22485c bl 0x27c524 <_Znwj>
 *   @0x224860 ldr r1, [pc, #0x7c]
 *   @0x224864 add r1, pc, r1
 *   @0x224868 mov r6, r0
 *   @0x22486c bl 0x27e070 <_ZN5MutexC2EPKc>
 *   @0x224870 mov r1, #2080
 *   @0x224874 str r6, [r4, #0x848]
 *   @0x224878 mvn r12, #0
 *   @0x22487c strb r5, [r4, #0x800]
 *   @0x224880 mov r2, #0
 *   @0x224884 mov r3, #0
 *   @0x224888 strb r5, [r4, #0x801]
 *   @0x22488c mov r0, r4
 *   @0x224890 strb r5, [r4]
 *   @0x224894 strb r5, [r4, #0x802]
 *   @0x224898 strb r5, [r4, #0x803]
 *   @0x22489c str r5, [r4, #0x808]
 *   @0x2248a0 str r5, [r4, #0x82c]
 *   @0x2248a4 strb r5, [r4, #0x84d]
 *   @0x2248a8 strb r5, [r4, #0x84e]
 *   @0x2248ac str r5, [r4, #0x80c]
 *   @0x2248b0 strb r5, [r4, #0x850]
 *   @0x2248b4 strb r5, [r4, #0x84f]
 *   @0x2248b8 strb r5, [r4, #0x851]
 *   @0x2248bc strb r5, [r4, #0x852]
 *   @0x2248c0 strb r5, [r4, #0x853]
 *   @0x2248c4 strb r5, [r4, #0x854]
 *   @0x2248c8 str r5, [r4, #0x828]
 *   @0x2248cc str r5, [r4, #0x858]
 *   @0x2248d0 str r5, [r4, #0x85c]
 *   @0x2248d4 str r5, [r4, #0x860]
 *   @0x2248d8 str r12, [r4, #0x810]
 *   @0x2248dc strd r2, r3, [r4, r1]
 *   @0x2248e0 pop {r4, r5, r6, pc}
 *   @0x2248e4 andseq sp, r0, r0, asr pc
 *
 * ══ §79/168 ov_raw_total  0x2312d8  size 180  45 条（0x2312d8..0x23138c）
 * @func 0x2312d8 0x23138c  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ov_raw_total+0x9c×2 / ov_raw_total+0x58 / ov_raw_total+0xa8 / ov_raw_total
 * 字段偏移 top8: 0x34×2 / 0x58×1 / 0x4×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2312d8 push {r3, r4, r5, r6, r7, lr}
 *   @0x2312dc mov r7, r0
 *   @0x2312e0 ldr r3, [r0, #0x58]
 *   @0x2312e4 cmp r3, #1
 *   @0x2312e8 ble 0x231374 <ov_raw_total+0x9c>
 *   @0x2312ec ldr r3, [r0, #0x4]
 *   @0x2312f0 cmp r3, #0
 *   @0x2312f4 beq 0x231374 <ov_raw_total+0x9c>
 *   @0x2312f8 ldr r3, [r0, #0x34]
 *   @0x2312fc cmp r3, r1
 *   @0x231300 ble 0x231374 <ov_raw_total+0x9c>
 *   @0x231304 cmp r1, #0
 *   @0x231308 blt 0x231330 <ov_raw_total+0x58>
 *   @0x23130c add r1, r1, #1
 *   @0x231310 ldr r3, [r0, #0x38]
 *   @0x231314 lsl r1, r1, #3
 *   @0x231318 add r2, r3, r1
 *   @0x23131c ldrd r0, r1, [r1, r3]
 *   @0x231320 ldrd r2, r3, [r2, #-8]
 *   @0x231324 subs r0, r0, r2
 *   @0x231328 sbc r1, r1, r3
 *   @0x23132c pop {r3, r4, r5, r6, r7, pc}
 *   @0x231330 cmp r3, #0
 *   @0x231334 ble 0x231380 <ov_raw_total+0xa8>
 *   @0x231338 mov r4, #0
 *   @0x23133c mov r5, #0
 *   @0x231340 mov r6, #0
 *   @0x231344 mov r1, r6
 *   @0x231348 mov r0, r7
 *   @0x23134c bl 0x2312d8 <ov_raw_total>
 *   @0x231350 ldr r3, [r7, #0x34]
 *   @0x231354 add r6, r6, #1
 *   @0x231358 adds r4, r4, r0
 *   @0x23135c adc r5, r5, r1
 *   @0x231360 cmp r3, r6
 *   @0x231364 bgt 0x231344 <ov_raw_total+0x6c>
 *   @0x231368 mov r0, r4
 *   @0x23136c mov r1, r5
 *   @0x231370 pop {r3, r4, r5, r6, r7, pc}
 *   @0x231374 mvn r0, #130
 *   @0x231378 mvn r1, #0
 *   @0x23137c pop {r3, r4, r5, r6, r7, pc}
 *   @0x231380 mov r0, #0
 *   @0x231384 mov r1, #0
 *   @0x231388 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §80/168 CPhysicsWorld::ParticleGroupBox(float, float)  0x239ae4  size 180  45 条（0x239ae4..0x239b98）
 * @func 0x239ae4 0x239b98  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / b2PolygonShape::SetAsBox(float, float)
 * 字段偏移 top8: 0x3c×2 / 0x4×2 / 0x50×1 / 0x8×1 / 0x94×1 / 0xc×1 / 0x10×1
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x239ae4 push {r3, r4, r5, lr}
 *   @0x239ae8 vpush {d8}
 *   @0x239aec vmov.f32 s15, #1.000000e+00
 *   @0x239af0 vmov s17, r1
 *   @0x239af4 mov r5, r0
 *   @0x239af8 vmov s16, r2
 *   @0x239afc ldr r0, [r0, #0x3c]
 *   @0x239b00 vcmp.f32 s17, #0
 *   @0x239b04 vmrs APSR_nzcv, fpscr
 *   @0x239b08 vcmp.f32 s16, #0
 *   @0x239b0c vmoveq.f32 s17, s15
 *   @0x239b10 vmrs APSR_nzcv, fpscr
 *   @0x239b14 vmoveq.f32 s16, s15
 *   @0x239b18 cmp r0, #0
 *   @0x239b1c beq 0x239b2c <_ZN13CPhysicsWorld16ParticleGroupBoxEff+0x48>
 *   @0x239b20 ldr r3, [r0]
 *   @0x239b24 ldr r3, [r3, #0x4]
 *   @0x239b28 blx r3
 *   @0x239b2c mov r0, #152
 *   @0x239b30 bl 0x27c524 <_Znwj>
 *   @0x239b34 vldr s15, [r5, #96]
 *   @0x239b38 vmul.f32 s17, s15, s17
 *   @0x239b3c ldr r3, [pc, #0x50]
 *   @0x239b40 mov r2, #2
 *   @0x239b44 movw r1, #0xd70a
 *   @0x239b48 ldr r3, [pc, r3]
 *   @0x239b4c movt r1, #0x3c23
 *   @0x239b50 add r3, r3, #8
 *   @0x239b54 vmul.f32 s16, s16, s15
 *   @0x239b58 str r2, [r0, #0x4]
 *   @0x239b5c mov r2, #0
 *   @0x239b60 str r1, [r0, #0x8]
 *   @0x239b64 mov r4, r0
 *   @0x239b68 str r3, [r0]
 *   @0x239b6c mov r3, #0
 *   @0x239b70 str r2, [r0, #0x94]
 *   @0x239b74 vmov r1, s17
 *   @0x239b78 vmov r2, s16
 *   @0x239b7c str r3, [r0, #0xc]
 *   @0x239b80 str r3, [r0, #0x10]
 *   @0x239b84 bl 0x2c5e9c <_ZN14b2PolygonShape8SetAsBoxEff>
 *   @0x239b88 vpop {d8}
 *   @0x239b8c str r4, [r5, #0x3c]
 *   @0x239b90 pop {r3, r4, r5, pc}
 *   @0x239b94 andseq r7, r11, r8, ror #18
 *
 * ══ §81/168 CPhysicsDebugRender::DrawSolidPolygon(b2Vec2 const*, int, b2Color const&)  0x23c41c  size 180  45 条（0x23c41c..0x23c4d0）
 * @func 0x23c41c 0x23c4d0  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsDebugRender::TranslateColour(b2Color const&) / YYGML_draw_set_colour(unsigned int) / CPhysicsDebugRender::DrawSolidPolygon(b2Vec2 const*, int, b2Color const&)+0xa8 / GR_Draw_Triangle(float, float, float, float, float, float, bool)
 * 字段偏移 top8: 0x8×2
 * VFP 指令 23 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23c41c push {r4, r5, r6, r7, r8, lr}
 *   @0x23c420 vpush {d8}
 *   @0x23c424 vmov.f32 s16, #1.000000e+00
 *   @0x23c428 sub sp, sp, #16
 *   @0x23c42c mov r6, r1
 *   @0x23c430 mov r1, r3
 *   @0x23c434 mov r7, r2
 *   @0x23c438 mov r4, r0
 *   @0x23c43c bl 0x23c338 <_ZN19CPhysicsDebugRender15TranslateColourERK7b2Color>
 *   @0x23c440 bl 0x169d98 <_Z21YYGML_draw_set_colourj>
 *   @0x23c444 cmp r7, #2
 *   @0x23c448 ldr r3, [r4, #0x8]
 *   @0x23c44c vldr s15, [r3, #96]
 *   @0x23c450 vdiv.f32 s16, s16, s15
 *   @0x23c454 ble 0x23c4c4 <_ZN19CPhysicsDebugRender16DrawSolidPolygonEPK6b2Vec2iRK7b2Color+0xa8>
 *   @0x23c458 add r4, r6, #16
 *   @0x23c45c mov r5, #2
 *   @0x23c460 mov r8, #0
 *   @0x23c464 vldr s11, [r4]
 *   @0x23c468 vldr s12, [r4, #-8]
 *   @0x23c46c vldr s13, [r4, #-4]
 *   @0x23c470 vldr s14, [r6]
 *   @0x23c474 vldr s15, [r6, #4]
 *   @0x23c478 add r5, r5, #1
 *   @0x23c47c add r4, r4, #8
 *   @0x23c480 vmul.f32 s11, s16, s11
 *   @0x23c484 vmul.f32 s12, s16, s12
 *   @0x23c488 vstr s11, [sp]
 *   @0x23c48c vldr s11, [r4, #-4]
 *   @0x23c490 str r8, [sp, #0x8]
 *   @0x23c494 vmul.f32 s11, s16, s11
 *   @0x23c498 vmov r2, s12
 *   @0x23c49c vmul.f32 s13, s16, s13
 *   @0x23c4a0 vstr s11, [sp, #4]
 *   @0x23c4a4 vmul.f32 s14, s16, s14
 *   @0x23c4a8 vmov r3, s13
 *   @0x23c4ac vmul.f32 s15, s16, s15
 *   @0x23c4b0 vmov r0, s14
 *   @0x23c4b4 vmov r1, s15
 *   @0x23c4b8 bl 0x16a6f0 <_Z16GR_Draw_Triangleffffffb>
 *   @0x23c4bc cmp r5, r7
 *   @0x23c4c0 bne 0x23c464 <_ZN19CPhysicsDebugRender16DrawSolidPolygonEPK6b2Vec2iRK7b2Color+0x48>
 *   @0x23c4c4 add sp, sp, #16
 *   @0x23c4c8 vpop {d8}
 *   @0x23c4cc pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §82/168 JS_String_prototype_charAt(RValue&, CInstance*, CInstance*, int, RValue*)  0x25540c  size 180  45 条（0x25540c..0x2554c0）
 * @func 0x25540c 0x2554d4  size 200  50 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_CheckObjectCoercible(RValue&) / F_JS_ToString(RValue&, RValue*) / F_JS_ToInteger(RValue&) / UTF8_get_U16_at_pos(RValue&, int) / JS_String_fromCharCode(RValue&, CInstance*, CInstance*, int, RValue*) / JSThrowTypeError(char const*)
 * 字段偏移 top8: 0x14×1 / 0x-30×1 / 0x48×1 / 0x34×1 / 0xc×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x25540c push {r4, r5, r6, lr}
 *   @0x255410 sub sp, sp, #56
 *   @0x255414 add r4, sp, #56
 *   @0x255418 mov r6, r0
 *   @0x25541c mov r3, #6
 *   @0x255420 str r3, [sp, #0x14]
 *   @0x255424 str r1, [r4, #-0x30]!
 *   @0x255428 mov r0, r4
 *   @0x25542c bl 0x2423a4 <_Z23JS_CheckObjectCoercibleR6RValue>
 *   @0x255430 cmp r0, #1
 *   @0x255434 beq 0x2554a8 <_Z26JS_String_prototype_charAtR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x255438 add r5, sp, #24
 *   @0x25543c mov r1, r4
 *   @0x255440 mov r0, r5
 *   @0x255444 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x255448 cmp r0, #1
 *   @0x25544c beq 0x2554a8 <_Z26JS_String_prototype_charAtR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x255450 ldr r0, [sp, #0x48]
 *   @0x255454 mov r4, #0
 *   @0x255458 bl 0x24d730 <_Z14F_JS_ToIntegerR6RValue>
 *   @0x25545c str r4, [sp, #0x34]
 *   @0x255460 vmov d7, r0, r1
 *   @0x255464 mov r0, r5
 *   @0x255468 vcvt.s32.f64 s15, d7
 *   @0x25546c vmov r1, s15
 *   @0x255470 bl 0x2424f4 <_Z19UTF8_get_U16_at_posR6RValuei>
 *   @0x255474 mov r1, r4
 *   @0x255478 mov r2, r4
 *   @0x25547c add r12, sp, #56
 *   @0x255480 mov r3, #1
 *   @0x255484 vmov s13, r0
 *   @0x255488 mov r0, r6
 *   @0x25548c vcvt.f64.u32 d7, s13
 *   @0x255490 vmov r4, r5, d7
 *   @0x255494 strd r4, r5, [r12, #-16]!
 *   @0x255498 str r12, [sp]
 *   @0x25549c bl 0x24d988 <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_>
 *   @0x2554a0 add sp, sp, #56
 *   @0x2554a4 pop {r4, r5, r6, pc}
 *   @0x2554a8 ldr r0, [pc, #0xc]
 *   @0x2554ac add r0, pc, r0
 *   @0x2554b0 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x2554b4 add sp, sp, #56
 *   @0x2554b8 pop {r4, r5, r6, pc}
 *   @0x2554bc mulseq r0, r12, r10
 *
 * ══ §83/168 Debug_BufferOutput(char const*)  0x29bfcc  size 180  45 条（0x29bfcc..0x29c080）
 * @func 0x29bfcc 0x29c080  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538 / 0xb65bc / MemoryManager::Alloc(unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x4×3 / 0x94×1 / 0x64×1 / 0x38×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29bfcc push {r4, r5, r6, r7, r8, lr}
 *   @0x29bfd0 mov r5, r0
 *   @0x29bfd4 ldr r4, [pc, #0x94]
 *   @0x29bfd8 add r4, pc, r4
 *   @0x29bfdc ldr r6, [r4]
 *   @0x29bfe0 cmp r6, #0
 *   @0x29bfe4 beq 0x29c038 <_Z18Debug_BufferOutputPKc+0x6c>
 *   @0x29bfe8 ldr r7, [r4, #0x4]
 *   @0x29bfec mov r0, r5
 *   @0x29bff0 bl 0xb6538 <strlen@plt>
 *   @0x29bff4 movw r3, #0x7ffe
 *   @0x29bff8 add r6, r7, r0
 *   @0x29bffc mov r4, r0
 *   @0x29c000 cmp r6, r3
 *   @0x29c004 pophi {r4, r5, r6, r7, r8, pc}
 *   @0x29c008 ldr r8, [pc, #0x64]
 *   @0x29c00c mov r2, r0
 *   @0x29c010 mov r1, r5
 *   @0x29c014 add r8, pc, r8
 *   @0x29c018 ldr r3, [r8]
 *   @0x29c01c add r7, r3, r7
 *   @0x29c020 mov r0, r7
 *   @0x29c024 bl 0xb65bc <memcpy@plt>
 *   @0x29c028 mov r3, #0
 *   @0x29c02c str r6, [r8, #0x4]
 *   @0x29c030 strb r3, [r7, r4]
 *   @0x29c034 pop {r4, r5, r6, r7, r8, pc}
 *   @0x29c038 ldr r1, [pc, #0x38]
 *   @0x29c03c movw r2, #0x3a1
 *   @0x29c040 mov r3, #1
 *   @0x29c044 mov r0, #32768
 *   @0x29c048 add r1, pc, r1
 *   @0x29c04c mov r7, r6
 *   @0x29c050 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x29c054 ldr r3, [pc, #0x20]
 *   @0x29c058 mov r2, #32768
 *   @0x29c05c str r6, [r4, #0x4]
 *   @0x29c060 ldr r3, [pc, r3]
 *   @0x29c064 str r2, [r3]
 *   @0x29c068 str r0, [r4]
 *   @0x29c06c b 0x29bfec <_Z18Debug_BufferOutputPKc+0x20>
 *   @0x29c070 subeq r11, r11, r0, lsr r12
 *   @0x29c074 strdeq r11, r12, [r11], #-180
 *   @0x29c078 andeq sp, r11, r12, ror r9
 *   @0x29c07c andseq r5, r5, r8, lsr #19
 *
 * ══ §84/168 anon_29ffec  0x29ffec  size 180  45 条（0x29ffec..0x2a00a0）
 * @func 0x29ffec 0x2a00a0  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6610 / 0xb6538 / 0xb68bc / 0xb65d4
 * 字段偏移 top8: 0x404×2 / 0x98×1 / 0x418×1 / 0x60×1 / 0x-404×1 / 0x1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29ffec push {r0, r1, r2, r3}
 *   @0x29fff0 movw r1, #0x3fe
 *   @0x29fff4 push {r4, r5, lr}
 *   @0x29fff8 sub sp, sp, #1024
 *   @0x29fffc ldr r4, [pc, #0x98]
 *   @0x2a0000 sub sp, sp, #12
 *   @0x2a0004 add r12, sp, #1040
 *   @0x2a0008 add r5, sp, #4
 *   @0x2a000c ldr r4, [pc, r4]
 *   @0x2a0010 add r12, r12, #12
 *   @0x2a0014 ldr r2, [sp, #0x418]
 *   @0x2a0018 mov r0, r5
 *   @0x2a001c ldr lr, [r4]
 *   @0x2a0020 mov r3, r12
 *   @0x2a0024 str r12, [sp]
 *   @0x2a0028 str lr, [sp, #0x404]
 *   @0x2a002c bl 0xb6610 <vsnprintf@plt>
 *   @0x2a0030 mov r0, r5
 *   @0x2a0034 bl 0xb6538 <strlen@plt>
 *   @0x2a0038 ldr r3, [pc, #0x60]
 *   @0x2a003c add r12, sp, #1024
 *   @0x2a0040 mov lr, #10
 *   @0x2a0044 add r12, r12, #8
 *   @0x2a0048 add r3, pc, r3
 *   @0x2a004c ldr r3, [r3]
 *   @0x2a0050 add r1, r12, r0
 *   @0x2a0054 add r2, r5, r0
 *   @0x2a0058 mov r12, #0
 *   @0x2a005c mov r0, r5
 *   @0x2a0060 strb lr, [r1, #-0x404]
 *   @0x2a0064 mov r1, #1
 *   @0x2a0068 strb r12, [r2, #0x1]!
 *   @0x2a006c rsb r2, r5, r2
 *   @0x2a0070 bl 0xb68bc <fwrite@plt>
 *   @0x2a0074 ldr r2, [sp, #0x404]
 *   @0x2a0078 ldr r3, [r4]
 *   @0x2a007c cmp r2, r3
 *   @0x2a0080 bne 0x2a0098 <_Z11cmpDumpNodePKvS0_+0xd4>
 *   @0x2a0084 add sp, sp, #1024
 *   @0x2a0088 add sp, sp, #12
 *   @0x2a008c pop {r4, r5, lr}
 *   @0x2a0090 add sp, sp, #16
 *   @0x2a0094 bx lr
 *   @0x2a0098 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2a009c andseq sp, r4, r4, asr #18
 *
 * ══ §85/168 _zip_name_locate(zip*, char const*, int, zip_error*)  0x2a49a4  size 180  45 条（0x2a49a4..0x2a4a58）
 * @func 0x2a49a4 0x2a4a58  size 180  45 条
 * 部分覆盖: 本节 45/85 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6868 / _zip_error_set(zip_error*, int, int)
 * 字段偏移 top8: 0x8c×1 / 0x88×1 / 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a49a4 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2a49a8 mov r11, r0
 *   @0x2a49ac mov r6, r2
 *   @0x2a49b0 mov r8, r1
 *   @0x2a49b4 mov r0, r3
 *   @0x2a49b8 mov r2, r8
 *   @0x2a49bc lsls r3, r2, #0x1f
 *   @0x2a49c0 ldr r5, [pc, #0x8c]
 *   @0x2a49c4 ldr r5, [r5]
 *   @0x2a49c8 ldr r5, [pc, #0x88]
 *   @0x2a49cc ldr r5, [r5]
 *   @0x2a49d0 .word 0xf04f0208
 *   @0x2a49d4 .word 0xf04f0400
 *   @0x2a49d8 andls r0, r2, #60, #20
 *   @0x2a49dc itet ne
 *   @0x2a49e0 .word 0xf8db3020
 *   @0x2a49e4 .word 0xf8d3902c
 *   @0x2a49e8 .word 0xf0069004
 *   @0x2a49ec movwls r0, #0x3302
 *   @0x2a49f0 cmp r4, r9
 *   @0x2a49f4 ldr r2, [sp, #0x8]
 *   @0x2a49f8 ldr.w r3, [r11, #0x20]
 *   @0x2a49fc ldr r3, [r3]
 *   @0x2a4a00 ldmibvs r11, {r2, r8, r9, r12, sp}
 *   @0x2a4a04 b 0x2a4a14 <_Z16_zip_name_locateP3zipPKciP9zip_error+0x70>
 *   @0x2a4a08 mov r0, r11
 *   @0x2a4a0c mov r2, r6
 *   @0x2a4a10 strmi pc, [r3], -r4, lsl #31
 *   @0x2a4a14 cbz r3, 0x2a4a32 <_Z16_zip_name_locateP3zipPKciP9zip_error+0x8e>
 *   @0x2a4a18 cbz r2, 0x2a4a2a <_Z16_zip_name_locateP3zipPKciP9zip_error+0x86>
 *   @0x2a4a1c movs r1, #0x2f
 *   @0x2a4a20 blx 0xb6868 <strrchr@plt>
 *   @0x2a4a24 ldr r3, [sp, #0x4]
 *   @0x2a4a28 adds r3, r0, #0x1
 *   @0x2a4a2c mov r1, r3
 *   @0x2a4a30 cbz r0, 0x2a4a46 <_Z16_zip_name_locateP3zipPKciP9zip_error+0xa2>
 *   @0x2a4a34 b 0x2a49f0 <_Z16_zip_name_locateP3zipPKciP9zip_error+0x4c>
 *   @0x2a4a38 movs r1, #0x9
 *   @0x2a4a3c bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii>
 *   @0x2a4a40 mov.w r0, #0xffffffff
 *   @0x2a4a44 b 0x2a4a48 <_Z16_zip_name_locateP3zipPKciP9zip_error+0xa4>
 *   @0x2a4a48 add sp, #0x14
 *   @0x2a4a4c svclt #0x8ff0
 *   @0x2a4a50 beq 0x2a49e8 <_Z16_zip_name_locateP3zipPKciP9zip_error+0x44>
 *   @0x2a4a54 beq 0x2a49e4 <_Z16_zip_name_locateP3zipPKciP9zip_error+0x40>
 *
 * ══ §86/168 png_set_rgb_to_gray  0x2a88f0  size 180  45 条（0x2a88f0..0x2a89a4）
 * @func 0x2a88f0 0x2a89a4  size 180  45 条
 * 部分覆盖: 本节 45/66 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_warning
 * 字段偏移 top8: 0x1e×1 / 0xc×1 / 0x20×1
 * VFP 指令 21 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a88f0 push {r4, r5, r6, lr}
 *   @0x2a88f4 vldr d2, [sp, #88]
 *   @0x2a88f8 strmi r7, [sp], -r4, lsl #22
 *   @0x2a88fc mov r4, r0
 *   @0x2a8900 beq 0x2a8984 <png_set_rgb_to_gray+0x94>
 *   @0x2a8904 .word 0xeeb44b21
 *   @0x2a8908 vsqrt.f64 d22, d4
 *   @0x2a890c .word 0xdc10fa10
 *   @0x2a8910 vldr d5, [pc, #124]
 *   @0x2a8914 vcmpe.f64 d6, d5
 *   @0x2a8918 vmrs APSR_nzcv, fpscr
 *   @0x2a891c bmi 0x2a8932 <png_set_rgb_to_gray+0x42>
 *   @0x2a8920 vsqrt.f64 d23, d4
 *   @0x2a8924 .word 0xdc04fa10
 *   @0x2a8928 vcmpe.f64 d7, d5
 *   @0x2a892c vmrs APSR_nzcv, fpscr
 *   @0x2a8930 bpl 0x2a8944 <png_set_rgb_to_gray+0x54>
 *   @0x2a8934 mov r0, r4
 *   @0x2a8938 bl 0x2a6474 <png_warning>
 *   @0x2a893c mov.w r3, #0xffffffff
 *   @0x2a8940 mov r2, r3
 *   @0x2a8944 vmov.f64 d5, #5.000000e-01
 *   @0x2a8948 vldr d4, [pc, #76]
 *   @0x2a894c vcvt.f32.f64 s12, d6
 *   @0x2a8950 vcvt.f32.f64 s14, d7
 *   @0x2a8954 vcvt.f64.f32 d6, s12
 *   @0x2a8958 vcvt.f64.f32 d7, s14
 *   @0x2a895c vmov.f64 d3, d5
 *   @0x2a8960 vmla.f64 d5, d7, d4
 *   @0x2a8964 vmla.f64 d3, d6, d4
 *   @0x2a8968 vcvt.s32.f64 s15, d5
 *   @0x2a896c vcvt.s32.f64 s7, d3
 *   @0x2a8970 vmov r3, s15
 *   @0x2a8974 vmov r2, s7
 *   @0x2a8978 mov r0, r4
 *   @0x2a897c pop.w {r4, r5, r6, lr}
 *   @0x2a8980 b.w 0x2a8824 <png_set_rgb_to_gray_fixed>
 *   @0x2a8984 pop {r4, r5, r6, pc}
 *   @0x2a8988 strb r5, [r0, #0x1e]
 *   @0x2a898c ldrh.w r4, [r5, #0xd4]
 *   @0x2a8990 ldr r1, [r6, #0xc]
 *   @0x2a8994 ldrh.w r12, [r5, #0xd4]
 *   @0x2a8998 movs r0, r0
 *   @0x2a899c ldr r0, [r0, #0x20]
 *   @0x2a89a0 lsrs r6, r3
 *
 * ══ §87/168 png_handle_tIME  0x2ad4d0  size 180  45 条（0x2ad4d0..0x2ad584）
 * @func 0x2ad4d0 0x2ad584  size 180  45 条
 * 部分覆盖: 本节 45/82 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_error / png_crc_read / png_crc_finish / 0x379570 / png_set_tIME
 * 字段偏移 top8: 0x94×1 / 0x8×1 / 0x-8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ad4d0 push {r0, r1, r2, r3, r4, r5, r6, lr}
 *   @0x2ad4d4 ldr.w r3, [r0, #0x12c]
 *   @0x2ad4d8 mov r6, r1
 *   @0x2ad4dc lsls r3, r3, #0x1f
 *   @0x2ad4e0 ldr r1, [pc, #0x94]
 *   @0x2ad4e4 bl 0x2a642c <png_error>
 *   @0x2ad4e8 b 0x2ad4f8 <png_handle_tIME+0x28>
 *   @0x2ad4ec ldr r3, [r1, #0x8]
 *   @0x2ad4f0 bpl 0x2ad4f8 <png_handle_tIME+0x28>
 *   @0x2ad4f4 add r1, pc
 *   @0x2ad4f8 ldr.w r3, [r4, #0x12c]
 *   @0x2ad4fc mov r0, r4
 *   @0x2ad500 itt mi
 *   @0x2ad504 .word 0xf8c40308
 *   @0x2ad508 stchs p1, c3, [r7, #-176]
 *   @0x2ad50c beq 0x2ad520 <png_handle_tIME+0x50>
 *   @0x2ad510 add r1, pc
 *   @0x2ad514 strtmi pc, [r0], -pc, lsr #31
 *   @0x2ad518 mov r1, r5
 *   @0x2ad51c .word 0xe029fbbb
 *   @0x2ad520 mov r1, sp
 *   @0x2ad524 bl 0x2abc0c <png_crc_read>
 *   @0x2ad528 mov r0, r4
 *   @0x2ad52c bl 0x2abc94 <png_crc_finish>
 *   @0x2ad530 cbnz r0, 0x2ad574 <png_handle_tIME+0xa4>
 *   @0x2ad534 strtmi r3, [r0], -r6
 *   @0x2ad538 ldrb.w r2, [sp]
 *   @0x2ad53c mov r1, r6
 *   @0x2ad540 .word 0xf89d300e
 *   @0x2ad544 .word 0xf88d3005
 *   @0x2ad548 .word 0xf89d300d
 *   @0x2ad54c .word 0xf88d3004
 *   @0x2ad550 .word 0xf89d300c
 *   @0x2ad554 .word 0xf88d3003
 *   @0x2ad558 .word 0xf89d300b
 *   @0x2ad55c .word 0xf88d3002
 *   @0x2ad560 .word 0xf89d300a
 *   @0x2ad564 bl 0x379570 <_ZTS13C_UTF16String+0x1061c>
 *   @0x2ad568 bge 0x3b6178 <error_g0017+0xee1c>
 *   @0x2ad56c strh r3, [r2, #-8]!
 *   @0x2ad570 bl 0x2af100 <png_set_tIME>
 *   @0x2ad574 add sp, #0x10
 *   @0x2ad578 lsls r7, r7, #0x7
 *   @0x2ad57c lsls r5, r0, #0x8
 *   @0x2ad580 lsls r6, r7, #0x7
 *
 * ══ §88/168 png_write_zTXt  0x2b2004  size 180  45 条（0x2b2004..0x2b20b8）
 * @func 0x2b2004 0x2b20b8  size 180  45 条
 * 部分覆盖: 本节 45/84 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_check_keyword / png_write_chunk_data / png_free / png_write_chunk_end / png_write_iTXt+0xac
 * 字段偏移 top8: 0x10×2 / 0xac×1 / 0x4e×1 / 0x24×1 / 0x4×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b2004 ldr r3, [pc, #0xac]
 *   @0x2b2008 ldrbtmi r4, [r11], #-496
 *   @0x2b200c mov r4, r0
 *   @0x2b2010 ldr r0, [r3, #78]!
 *   @0x2b2014 mov r5, r2
 *   @0x2b2018 str r2, [sp, #0x24]
 *   @0x2b201c ldrb r3, [r3, #0x4]
 *   @0x2b2020 mov r0, r4
 *   @0x2b2024 str r2, [sp, #0x1c]
 *   @0x2b2028 add r2, sp, #0x10
 *   @0x2b202c strb.w r3, [sp, #0x18]
 *   @0x2b2030 bl 0x2af5b0 <png_check_keyword>
 *   @0x2b2034 mov r7, r0
 *   @0x2b2038 cbz r5, 0x2b2042 <png_write_zTXt+0x3e>
 *   @0x2b203c cbz r3, 0x2b2042 <png_write_zTXt+0x3e>
 *   @0x2b2040 bne 0x2b2058 <png_write_zTXt+0x54>
 *   @0x2b2044 ldr r1, [sp, #0x10]
 *   @0x2b2048 movs r3, #0x0
 *   @0x2b204c strtmi pc, [r0], -r3, lsr #31
 *   @0x2b2050 ldr r1, [sp, #0x10]
 *   @0x2b2054 eor pc, r9, r3, asr lr
 *   @0x2b2058 mov r0, r5
 *   @0x2b205c .word 0xf604081c
 *   @0x2b2060 ldrtmi lr, [r3], -r12, ror #20
 *   @0x2b2064 mov r1, r5
 *   @0x2b2068 strmi r8, [r2], -r0
 *   @0x2b206c mov r0, r4
 *   @0x2b2070 ldcne p15, c15, [r10], #404
 *   @0x2b2074 add r1, sp, #0x14
 *   @0x2b2078 mov r0, r4
 *   @0x2b207c ldclne p8, c15, [r10], #-580
 *   @0x2b2080 mov r0, r4
 *   @0x2b2084 bl 0x2b1204 <png_write_chunk_data>
 *   @0x2b2088 mov r0, r4
 *   @0x2b208c bl 0x2a6cfc <png_free>
 *   @0x2b2090 add r1, sp, #0x30
 *   @0x2b2094 movs r2, #0x1
 *   @0x2b2098 .word 0xf7ff6d24
 *   @0x2b209c .word 0x4620f8b3
 *   @0x2b20a0 mov r1, r8
 *   @0x2b20a4 strtmi pc, [r0], -r0, asr #17
 *   @0x2b20a8 bl 0x2b1296 <png_write_chunk_end>
 *   @0x2b20ac add sp, #0x30
 *   @0x2b20b0 svclt #0x81f0
 *   @0x2b20b4 ble 0x2b2164 <png_write_iTXt+0xac>
 *
 * ══ §89/168 DGifGetPixel(GifFileType*, unsigned char)  0x2c2750  size 180  45 条（0x2c2750..0x2c2804）
 * @func 0x2c2750 0x2c2804  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DGifGetPixel(GifFileType*, unsigned char)+0x54 / anon_2c143c+0x25c / DGifGetCodeNext(GifFileType*, unsigned char**)
 * 字段偏移 top8: 0x34×3 / 0x48×1 / 0x7×1 / 0x40×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c2750 push {r4, r5, r6, lr}
 *   @0x2c2754 sub sp, sp, #16
 *   @0x2c2758 ldr r5, [r0, #0x48]
 *   @0x2c275c mov r4, r0
 *   @0x2c2760 strb r1, [sp, #0x7]
 *   @0x2c2764 ldr r6, [r5]
 *   @0x2c2768 ands r6, r6, #8
 *   @0x2c276c moveq r3, #111
 *   @0x2c2770 streq r3, [r0, #0x40]
 *   @0x2c2774 beq 0x2c2798 <_Z12DGifGetPixelP11GifFileTypeh+0x48>
 *   @0x2c2778 ldr r3, [r5, #0x34]
 *   @0x2c277c sub r3, r3, #1
 *   @0x2c2780 str r3, [r5, #0x34]
 *   @0x2c2784 cmn r3, #65536
 *   @0x2c2788 bls 0x2c27a4 <_Z12DGifGetPixelP11GifFileTypeh+0x54>
 *   @0x2c278c mov r6, #0
 *   @0x2c2790 mov r3, #108
 *   @0x2c2794 str r3, [r0, #0x40]
 *   @0x2c2798 mov r0, r6
 *   @0x2c279c add sp, sp, #16
 *   @0x2c27a0 pop {r4, r5, r6, pc}
 *   @0x2c27a4 add r1, sp, #7
 *   @0x2c27a8 mov r2, #1
 *   @0x2c27ac bl 0x2c1698 <jpeg_mem_term+0x260>
 *   @0x2c27b0 cmp r0, #1
 *   @0x2c27b4 mov r6, r0
 *   @0x2c27b8 beq 0x2c27cc <_Z12DGifGetPixelP11GifFileTypeh+0x7c>
 *   @0x2c27bc mov r6, #0
 *   @0x2c27c0 mov r0, r6
 *   @0x2c27c4 add sp, sp, #16
 *   @0x2c27c8 pop {r4, r5, r6, pc}
 *   @0x2c27cc ldr r3, [r5, #0x34]
 *   @0x2c27d0 cmp r3, #0
 *   @0x2c27d4 bne 0x2c2798 <_Z12DGifGetPixelP11GifFileTypeh+0x48>
 *   @0x2c27d8 add r5, sp, #12
 *   @0x2c27dc b 0x2c27ec <_Z12DGifGetPixelP11GifFileTypeh+0x9c>
 *   @0x2c27e0 ldr r3, [sp, #0xc]
 *   @0x2c27e4 cmp r3, #0
 *   @0x2c27e8 beq 0x2c2798 <_Z12DGifGetPixelP11GifFileTypeh+0x48>
 *   @0x2c27ec mov r0, r4
 *   @0x2c27f0 mov r1, r5
 *   @0x2c27f4 bl 0x2c25c0 <_Z15DGifGetCodeNextP11GifFileTypePPh>
 *   @0x2c27f8 cmp r0, #0
 *   @0x2c27fc bne 0x2c27e0 <_Z12DGifGetPixelP11GifFileTypeh+0x90>
 *   @0x2c2800 b 0x2c27bc <_Z12DGifGetPixelP11GifFileTypeh+0x6c>
 *
 * ══ §90/168 b2CircleShape::ComputeDistance(b2Transform const&, b2Vec2 const&, float*, b2Vec2*, int) const  0x2c4f0c  size 180  45 条（0x2c4f0c..0x2c4fc0）
 * @func 0x2c4f0c 0x2c4fc0  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6700
 * 字段偏移 top8: 0x4×2 / 0x20×1
 * VFP 指令 34 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c4f0c vldr s15, [r0, #16]
 *   @0x2c4f10 vldr s12, [r1, #12]
 *   @0x2c4f14 vmul.f32 s14, s12, s15
 *   @0x2c4f18 vldr s11, [r1, #8]
 *   @0x2c4f1c vldr s13, [r0, #12]
 *   @0x2c4f20 vldr s9, [r1, #4]
 *   @0x2c4f24 push {r4, r5, lr}
 *   @0x2c4f28 vpush {d8}
 *   @0x2c4f2c vldr s16, [r2, #4]
 *   @0x2c4f30 vldr s10, [r1]
 *   @0x2c4f34 vldr s17, [r2]
 *   @0x2c4f38 sub sp, sp, #12
 *   @0x2c4f3c mov r4, r0
 *   @0x2c4f40 ldr r5, [sp, #0x20]
 *   @0x2c4f44 vmul.f32 s15, s11, s15
 *   @0x2c4f48 vmla.f32 s14, s13, s11
 *   @0x2c4f4c vnmls.f32 s15, s12, s13
 *   @0x2c4f50 vadd.f32 s14, s14, s9
 *   @0x2c4f54 vsub.f32 s16, s16, s14
 *   @0x2c4f58 vadd.f32 s15, s15, s10
 *   @0x2c4f5c vmul.f32 s14, s16, s16
 *   @0x2c4f60 vsub.f32 s17, s17, s15
 *   @0x2c4f64 vmla.f32 s14, s17, s17
 *   @0x2c4f68 vsqrt.f32 s15, s14
 *   @0x2c4f6c vcmp.f32 s15, s15
 *   @0x2c4f70 vmrs APSR_nzcv, fpscr
 *   @0x2c4f74 bne 0x2c4fa8 <_ZNK13b2CircleShape15ComputeDistanceERK11b2TransformRK6b2Vec2PfPS3_i+0x9c>
 *   @0x2c4f78 vmov.f32 s14, #1.000000e+00
 *   @0x2c4f7c vldr s13, [r4, #8]
 *   @0x2c4f80 vdiv.f32 s14, s14, s15
 *   @0x2c4f84 vmul.f32 s17, s14, s17
 *   @0x2c4f88 vmul.f32 s16, s14, s16
 *   @0x2c4f8c vsub.f32 s15, s15, s13
 *   @0x2c4f90 vstr s15, [r3]
 *   @0x2c4f94 vstr s17, [r5]
 *   @0x2c4f98 vstr s16, [r5, #4]
 *   @0x2c4f9c add sp, sp, #12
 *   @0x2c4fa0 vpop {d8}
 *   @0x2c4fa4 pop {r4, r5, pc}
 *   @0x2c4fa8 vmov r0, s14
 *   @0x2c4fac str r3, [sp, #0x4]
 *   @0x2c4fb0 bl 0xb6700 <sqrtf@plt>
 *   @0x2c4fb4 ldr r3, [sp, #0x4]
 *   @0x2c4fb8 vmov s15, r0
 *   @0x2c4fbc b 0x2c4f78 <_ZNK13b2CircleShape15ComputeDistanceERK11b2TransformRK6b2Vec2PfPS3_i+0x6c>
 *
 * ══ §91/168 b2Joint::b2Joint(b2JointDef const*)  0x2cdee0  size 180  45 条（0x2cdee0..0x2cdf94）
 * @func 0x2cdee0 0x2cdf94  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×3 / 0xc×3 / 0x10×2 / 0x4×2 / 0x90×1 / 0x8c×1 / 0x84×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cdee0 push {r3, r4, r5, r6, r7, lr}
 *   @0x2cdee4 mov r4, r0
 *   @0x2cdee8 mov r5, r1
 *   @0x2cdeec ldr r0, [r1, #0x8]
 *   @0x2cdef0 ldr r3, [pc, #0x90]
 *   @0x2cdef4 ldr r1, [r1, #0xc]
 *   @0x2cdef8 ldr r2, [pc, #0x8c]
 *   @0x2cdefc ldr r3, [pc, r3]
 *   @0x2cdf00 subs r0, r0, r1
 *   @0x2cdf04 ldr r1, [pc, #0x84]
 *   @0x2cdf08 ldr r2, [pc, r2]
 *   @0x2cdf0c ldr r3, [r3]
 *   @0x2cdf10 add r2, r2, #8
 *   @0x2cdf14 movne r0, #1
 *   @0x2cdf18 str r2, [r4]
 *   @0x2cdf1c add r1, pc, r1
 *   @0x2cdf20 blx r3
 *   @0x2cdf24 ldr r7, [r5]
 *   @0x2cdf28 ldr r6, [r5, #0x8]
 *   @0x2cdf2c mov r3, #0
 *   @0x2cdf30 ldr r12, [r5, #0xc]
 *   @0x2cdf34 mov r0, r4
 *   @0x2cdf38 ldrb r1, [r5, #0x10]
 *   @0x2cdf3c ldr r2, [r5, #0x4]
 *   @0x2cdf40 str r7, [r4, #0x4]
 *   @0x2cdf44 str r6, [r4, #0x30]
 *   @0x2cdf48 str r12, [r4, #0x34]
 *   @0x2cdf4c strb r1, [r4, #0x3d]
 *   @0x2cdf50 str r2, [r4, #0x40]
 *   @0x2cdf54 str r3, [r4, #0x8]
 *   @0x2cdf58 str r3, [r4, #0xc]
 *   @0x2cdf5c str r3, [r4, #0x38]
 *   @0x2cdf60 strb r3, [r4, #0x3c]
 *   @0x2cdf64 str r3, [r4, #0x14]
 *   @0x2cdf68 str r3, [r4, #0x10]
 *   @0x2cdf6c str r3, [r4, #0x18]
 *   @0x2cdf70 str r3, [r4, #0x1c]
 *   @0x2cdf74 str r3, [r4, #0x24]
 *   @0x2cdf78 str r3, [r4, #0x20]
 *   @0x2cdf7c str r3, [r4, #0x28]
 *   @0x2cdf80 str r3, [r4, #0x2c]
 *   @0x2cdf84 pop {r3, r4, r5, r6, r7, pc}
 *   @0x2cdf88 andseq r3, r2, r12, asr #11
 *   @0x2cdf8c andseq r3, r2, r12, asr #24
 *   @0x2cdf90 strheq pc, [r8], -r12
 *
 * ══ §92/168 b2PrismaticJointDef::Initialize(b2Body*, b2Body*, b2Vec2 const&, b2Vec2 const&)  0x2cff74  size 180  45 条（0x2cff74..0x2d0028）
 * @func 0x2cff74 0x2d0028  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 41 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cff74 vldr s15, [r1, #16]
 *   @0x2cff78 vldr s12, [r3, #4]
 *   @0x2cff7c vsub.f32 s12, s12, s15
 *   @0x2cff80 vldr s13, [r1, #20]
 *   @0x2cff84 vldr s15, [r1, #24]
 *   @0x2cff88 vldr s10, [r1, #12]
 *   @0x2cff8c vldr s7, [r3]
 *   @0x2cff90 vldr s9, [r2, #20]
 *   @0x2cff94 vldr s8, [r2, #24]
 *   @0x2cff98 vldr s14, [r2, #16]
 *   @0x2cff9c vldr s4, [r2, #12]
 *   @0x2cffa0 vldr s5, [r2, #72]
 *   @0x2cffa4 vldr s6, [r1, #72]
 *   @0x2cffa8 ldr r12, [sp]
 *   @0x2cffac str r1, [r0, #0x8]
 *   @0x2cffb0 str r2, [r0, #0xc]
 *   @0x2cffb4 vmul.f32 s11, s12, s13
 *   @0x2cffb8 vmul.f32 s12, s12, s15
 *   @0x2cffbc vsub.f32 s7, s7, s10
 *   @0x2cffc0 vneg.f32 s10, s13
 *   @0x2cffc4 vmla.f32 s11, s7, s15
 *   @0x2cffc8 vmla.f32 s12, s7, s10
 *   @0x2cffcc vstr s11, [r0, #20]
 *   @0x2cffd0 vstr s12, [r0, #24]
 *   @0x2cffd4 vldr s12, [r3, #4]
 *   @0x2cffd8 vsub.f32 s14, s12, s14
 *   @0x2cffdc vldr s11, [r3]
 *   @0x2cffe0 vmul.f32 s12, s14, s9
 *   @0x2cffe4 vmul.f32 s14, s14, s8
 *   @0x2cffe8 vsub.f32 s11, s11, s4
 *   @0x2cffec vmla.f32 s12, s11, s8
 *   @0x2cfff0 vmls.f32 s14, s9, s11
 *   @0x2cfff4 vstr s12, [r0, #28]
 *   @0x2cfff8 vstr s14, [r0, #32]
 *   @0x2cfffc vldr s14, [r12, #4]
 *   @0x2d0000 vmul.f32 s13, s13, s14
 *   @0x2d0004 vldr s12, [r12]
 *   @0x2d0008 vmul.f32 s14, s15, s14
 *   @0x2d000c vmla.f32 s13, s15, s12
 *   @0x2d0010 vmla.f32 s14, s10, s12
 *   @0x2d0014 vstr s13, [r0, #36]
 *   @0x2d0018 vsub.f32 s15, s5, s6
 *   @0x2d001c vstr s14, [r0, #40]
 *   @0x2d0020 vstr s15, [r0, #44]
 *   @0x2d0024 bx lr
 *
 * ══ §93/168 b2PrismaticJoint::SetLimits(float, float)  0x2d0380  size 180  45 条（0x2d0380..0x2d0434）
 * @func 0x2d0380 0x2d0434  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x94×2 / 0x4×2 / 0x30×1 / 0x34×1 / 0x70×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d0380 push {r4, lr}
 *   @0x2d0384 vpush {d8}
 *   @0x2d0388 vmov s16, r1
 *   @0x2d038c vmov s17, r2
 *   @0x2d0390 ldr r3, [pc, #0x94]
 *   @0x2d0394 ldr r1, [pc, #0x94]
 *   @0x2d0398 mov r4, r0
 *   @0x2d039c vcmpe.f32 s16, s17
 *   @0x2d03a0 ldr r3, [pc, r3]
 *   @0x2d03a4 add r1, pc, r1
 *   @0x2d03a8 ldr r3, [r3]
 *   @0x2d03ac vmrs APSR_nzcv, fpscr
 *   @0x2d03b0 movhi r0, #0
 *   @0x2d03b4 movls r0, #1
 *   @0x2d03b8 blx r3
 *   @0x2d03bc vldr s15, [r4, #120]
 *   @0x2d03c0 vcmp.f32 s15, s16
 *   @0x2d03c4 vmrs APSR_nzcv, fpscr
 *   @0x2d03c8 bne 0x2d03dc <_ZN16b2PrismaticJoint9SetLimitsEff+0x5c>
 *   @0x2d03cc vldr s15, [r4, #124]
 *   @0x2d03d0 vcmp.f32 s15, s17
 *   @0x2d03d4 vmrs APSR_nzcv, fpscr
 *   @0x2d03d8 beq 0x2d0424 <_ZN16b2PrismaticJoint9SetLimitsEff+0xa4>
 *   @0x2d03dc ldr r3, [r4, #0x30]
 *   @0x2d03e0 ldrh r2, [r3, #4]
 *   @0x2d03e4 tst r2, #2
 *   @0x2d03e8 orreq r2, r2, #2
 *   @0x2d03ec strheq r2, [r3, #4]
 *   @0x2d03f0 moveq r1, #0
 *   @0x2d03f4 streq r1, [r3, #0xa0]
 *   @0x2d03f8 ldr r3, [r4, #0x34]
 *   @0x2d03fc ldrh r2, [r3, #4]
 *   @0x2d0400 tst r2, #2
 *   @0x2d0404 orreq r2, r2, #2
 *   @0x2d0408 strheq r2, [r3, #4]
 *   @0x2d040c moveq r1, #0
 *   @0x2d0410 streq r1, [r3, #0xa0]
 *   @0x2d0414 mov r3, #0
 *   @0x2d0418 vstr s16, [r4, #120]
 *   @0x2d041c vstr s17, [r4, #124]
 *   @0x2d0420 str r3, [r4, #0x70]
 *   @0x2d0424 vpop {d8}
 *   @0x2d0428 pop {r4, pc}
 *   @0x2d042c andseq r1, r2, r8, lsr #2
 *   @0x2d0430 andeq sp, r8, r0, lsl #9
 *
 * ══ §94/168 b2RevoluteJoint::SetLimits(float, float)  0x2d228c  size 180  45 条（0x2d228c..0x2d2340）
 * @func 0x2d228c 0x2d2340  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x94×2 / 0x4×2 / 0x30×1 / 0x34×1 / 0x5c×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d228c push {r4, lr}
 *   @0x2d2290 vpush {d8}
 *   @0x2d2294 vmov s16, r1
 *   @0x2d2298 vmov s17, r2
 *   @0x2d229c ldr r3, [pc, #0x94]
 *   @0x2d22a0 ldr r1, [pc, #0x94]
 *   @0x2d22a4 mov r4, r0
 *   @0x2d22a8 vcmpe.f32 s16, s17
 *   @0x2d22ac ldr r3, [pc, r3]
 *   @0x2d22b0 add r1, pc, r1
 *   @0x2d22b4 ldr r3, [r3]
 *   @0x2d22b8 vmrs APSR_nzcv, fpscr
 *   @0x2d22bc movhi r0, #0
 *   @0x2d22c0 movls r0, #1
 *   @0x2d22c4 blx r3
 *   @0x2d22c8 vldr s15, [r4, #120]
 *   @0x2d22cc vcmp.f32 s15, s16
 *   @0x2d22d0 vmrs APSR_nzcv, fpscr
 *   @0x2d22d4 bne 0x2d22e8 <_ZN15b2RevoluteJoint9SetLimitsEff+0x5c>
 *   @0x2d22d8 vldr s15, [r4, #124]
 *   @0x2d22dc vcmp.f32 s15, s17
 *   @0x2d22e0 vmrs APSR_nzcv, fpscr
 *   @0x2d22e4 beq 0x2d2330 <_ZN15b2RevoluteJoint9SetLimitsEff+0xa4>
 *   @0x2d22e8 ldr r3, [r4, #0x30]
 *   @0x2d22ec ldrh r2, [r3, #4]
 *   @0x2d22f0 tst r2, #2
 *   @0x2d22f4 orreq r2, r2, #2
 *   @0x2d22f8 strheq r2, [r3, #4]
 *   @0x2d22fc moveq r1, #0
 *   @0x2d2300 streq r1, [r3, #0xa0]
 *   @0x2d2304 ldr r3, [r4, #0x34]
 *   @0x2d2308 ldrh r2, [r3, #4]
 *   @0x2d230c tst r2, #2
 *   @0x2d2310 orreq r2, r2, #2
 *   @0x2d2314 strheq r2, [r3, #4]
 *   @0x2d2318 moveq r1, #0
 *   @0x2d231c streq r1, [r3, #0xa0]
 *   @0x2d2320 mov r3, #0
 *   @0x2d2324 vstr s16, [r4, #120]
 *   @0x2d2328 vstr s17, [r4, #124]
 *   @0x2d232c str r3, [r4, #0x5c]
 *   @0x2d2330 vpop {d8}
 *   @0x2d2334 pop {r4, pc}
 *   @0x2d2338 andseq pc, r1, r12, lsl r2
 *   @0x2d233c andeq r11, r8, r4, ror r5
 *
 * ══ §95/168 b2DynamicTree::GetAreaRatio() const  0x2df798  size 180  45 条（0x2df798..0x2df84c）
 * @func 0x2df798 0x2df84c  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2DynamicTree::GetAreaRatio() const+0xa8 / b2DynamicTree::GetAreaRatio() const+0x84
 * 字段偏移 top8: 0x4×1 / 0xc×1
 * VFP 指令 23 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2df798 ldr r2, [r0]
 *   @0x2df79c cmn r2, #1
 *   @0x2df7a0 beq 0x2df834 <_ZNK13b2DynamicTree12GetAreaRatioEv+0x9c>
 *   @0x2df7a4 add r2, r2, r2, lsl #3
 *   @0x2df7a8 ldr r3, [r0, #0x4]
 *   @0x2df7ac ldr r1, [r0, #0xc]
 *   @0x2df7b0 add r2, r3, r2, lsl #2
 *   @0x2df7b4 vldr s15, [r2]
 *   @0x2df7b8 vldr s14, [r2, #8]
 *   @0x2df7bc vldr s13, [r2, #12]
 *   @0x2df7c0 vsub.f32 s14, s14, s15
 *   @0x2df7c4 vldr s15, [r2, #4]
 *   @0x2df7c8 cmp r1, #0
 *   @0x2df7cc vsub.f32 s15, s13, s15
 *   @0x2df7d0 vadd.f32 s14, s14, s15
 *   @0x2df7d4 vadd.f32 s11, s14, s14
 *   @0x2df7d8 ble 0x2df840 <_ZNK13b2DynamicTree12GetAreaRatioEv+0xa8>
 *   @0x2df7dc add r1, r1, r1, lsl #3
 *   @0x2df7e0 add r3, r3, #32
 *   @0x2df7e4 vldr s14, [pc, #92]
 *   @0x2df7e8 add r1, r3, r1, lsl #2
 *   @0x2df7ec ldr r2, [r3]
 *   @0x2df7f0 cmp r2, #0
 *   @0x2df7f4 blt 0x2df81c <_ZNK13b2DynamicTree12GetAreaRatioEv+0x84>
 *   @0x2df7f8 vldr s15, [r3, #-32]
 *   @0x2df7fc vldr s13, [r3, #-24]
 *   @0x2df800 vldr s12, [r3, #-20]
 *   @0x2df804 vsub.f32 s13, s13, s15
 *   @0x2df808 vldr s15, [r3, #-28]
 *   @0x2df80c vsub.f32 s15, s12, s15
 *   @0x2df810 vadd.f32 s15, s13, s15
 *   @0x2df814 vadd.f32 s15, s15, s15
 *   @0x2df818 vadd.f32 s14, s14, s15
 *   @0x2df81c add r3, r3, #36
 *   @0x2df820 cmp r3, r1
 *   @0x2df824 bne 0x2df7ec <_ZNK13b2DynamicTree12GetAreaRatioEv+0x54>
 *   @0x2df828 vdiv.f32 s14, s14, s11
 *   @0x2df82c vmov r0, s14
 *   @0x2df830 bx lr
 *   @0x2df834 vldr s14, [pc, #12]
 *   @0x2df838 vmov r0, s14
 *   @0x2df83c bx lr
 *   @0x2df840 vldr s14, [pc]
 *   @0x2df844 b 0x2df828 <_ZNK13b2DynamicTree12GetAreaRatioEv+0x90>
 *   @0x2df848 andeq r0, r0, r0
 *
 * ══ §96/168 anon_2e84f0  0x2e84f0  size 180  45 条（0x2e84f0..0x2e85a4）
 * @func 0x2e84f0 0x2e85a4  size 180  45 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2f9f10 / 0x639dd8 / 0x212461c / 0x9a6578 / 0x3e80dc
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e84f0 ldrbmi lr, [pc, sp, lsr #18]!
 *   @0x2e84f4 ldrmi r4, [r1], -pc, lsl #12
 *   @0x2e84f8 pkhbtmi r4, r1, lr, lsl #12
 *   @0x2e84fc .word 0xf7fc4614
 *   @0x2e8500 movwhs pc, #0xa5b
 *   @0x2e8504 stmdavs r3, {r1, r8, r9, r12, pc}
 *   @0x2e8508 blhs 0x2f9f10 <ps_hints_apply+0x8b10>
 *   @0x2e850c .word 0x2108d147
 *   @0x2e8510 bl 0x639dd8 <g_SWFaavertbuff+0x66d10>
 *   @0x2e8514 .word 0xf7fe0201
 *   @0x2e8518 stcls p14, c15, [r2, #-24]
 *   @0x2e851c teqle pc, r0, lsl #26
 *   @0x2e8520 andeq pc, r0, r8, asr #17
 *   @0x2e8524 andls pc, r0, r0, asr #17
 *   @0x2e8528 stmvs r2!, {r0, r1, r2, r6, sp, lr}
 *   @0x2e852c addsmi r6, r10, #2293760
 *   @0x2e8530 stmvs r3!, {r0, r1, r9, r12, lr, pc}
 *   @0x2e8534 adcvs r3, r3, r1, lsl #6
 *   @0x2e8538 .word 0xf8d4e032
 *   @0x2e853c .word 0xf10d9004
 *   @0x2e8540 .word 0x21030a10
 *   @0x2e8544 ldrsbhi pc, [r4], -r4
 *   @0x2e8548 stcpl p8, c15, [r4, #-296]
 *   @0x2e854c strbeq lr, [r9, -pc, asr #20]
 *   @0x2e8550 ldrtmi r6, [r8], -r7, rrx
 *   @0x2e8554 bl 0x212461c <b2_toiTime+0x19cb178>
 *   @0x2e8558 strteq lr, [r0], #-2189
 *   @0x2e855c .word 0x2104462a
 *   @0x2e8560 eorvs r4, r0, r11, lsr r6
 *   @0x2e8564 .word 0xf7ff4630
 *   @0x2e8568 stcls p13, c15, [r3, #-584]
 *   @0x2e856c ldmiblt r5, {r5, r6, r8, sp, lr}
 *   @0x2e8570 strbmi r4, [sp, #-0x647]
 *   @0x2e8574 .word 0xf857d00b
 *   @0x2e8578 teqlt r3, r4, lsl #22
 *   @0x2e857c qadd16mi r6, r1, r8
 *   @0x2e8580 blx 0x9a6578 <b2_toiTime+0x24d0d4>
 *   @0x2e8584 .word 0x3c04f857
 *   @0x2e8588 strlo r6, [r1, #-0x3]
 *   @0x2e858c shsub8mi lr, r0, r1
 *   @0x2e8590 .word 0xf7fe4641
 *   @0x2e8594 blls 0x3e80dc <error_g0017+0x40d80>
 *   @0x2e8598 stmdblt r11, {r1, r8, r9, r12, pc}
 *   @0x2e859c subsvs lr, pc, r9, asr #15
 *   @0x2e85a0 andlt r9, r4, r2, lsl #16
 *
 * ══ §97/168 CBackground::InitLocalTPE()  0xc1ea0  size 176  44 条（0xc1ea0..0xc1f50）
 * @func 0xc1ea0 0xc1f50  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*) / MemoryManager::Alloc(unsigned int, char const*, int, bool) / CBitmap32::GetWidth() / CBitmap32::GetHeight()
 * 字段偏移 top8: 0x14×6 / 0x10×3 / 0x18×2 / 0x4×2 / 0xc×2 / 0x6×2 / 0x78×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc1ea0 push {r3, r4, r5, r6, r7, lr}
 *   @0xc1ea4 mov r4, r0
 *   @0xc1ea8 ldr r0, [r0, #0x14]
 *   @0xc1eac cmp r0, #0
 *   @0xc1eb0 beq 0xc1ecc <_ZN11CBackground12InitLocalTPEEv+0x2c>
 *   @0xc1eb4 ldrb r3, [r4, #0x18]
 *   @0xc1eb8 cmp r3, #0
 *   @0xc1ebc popeq {r3, r4, r5, r6, r7, pc}
 *   @0xc1ec0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xc1ec4 mov r3, #0
 *   @0xc1ec8 str r3, [r4, #0x14]
 *   @0xc1ecc ldr r1, [pc, #0x78]
 *   @0xc1ed0 movw r2, #0x192
 *   @0xc1ed4 mov r3, #1
 *   @0xc1ed8 mov r0, #22
 *   @0xc1edc add r1, pc, r1
 *   @0xc1ee0 mov r5, #0
 *   @0xc1ee4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xc1ee8 mov r6, r0
 *   @0xc1eec str r0, [r4, #0x14]
 *   @0xc1ef0 ldr r0, [r4, #0x10]
 *   @0xc1ef4 strh r5, [r6]
 *   @0xc1ef8 strh r5, [r6, #2]
 *   @0xc1efc bl 0x167960 <_ZN9CBitmap328GetWidthEv>
 *   @0xc1f00 ldr r7, [r4, #0x14]
 *   @0xc1f04 strh r0, [r6, #4]
 *   @0xc1f08 ldr r0, [r4, #0x10]
 *   @0xc1f0c bl 0x167968 <_ZN9CBitmap329GetHeightEv>
 *   @0xc1f10 ldr r3, [r4, #0x14]
 *   @0xc1f14 ldr r6, [r4, #0xc]
 *   @0xc1f18 mov r12, #1
 *   @0xc1f1c ldrh r2, [r3, #4]
 *   @0xc1f20 strh r0, [r7, #6]
 *   @0xc1f24 ldrh r1, [r3, #6]
 *   @0xc1f28 strh r5, [r3, #8]
 *   @0xc1f2c strh r5, [r3, #10]
 *   @0xc1f30 strh r1, [r3, #14]
 *   @0xc1f34 strh r1, [r3, #18]
 *   @0xc1f38 strh r6, [r3, #20]
 *   @0xc1f3c strh r2, [r3, #12]
 *   @0xc1f40 strh r2, [r3, #16]
 *   @0xc1f44 strb r12, [r4, #0x18]
 *   @0xc1f48 pop {r3, r4, r5, r6, r7, pc}
 *   @0xc1f4c eoreq lr, r6, r12, ror #20
 *
 * ══ §98/168 _itoa(int, char*, int)  0xc4964  size 176  44 条（0xc4964..0xc4a14）
 * @func 0xc4964 0xc4a14  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __divsi3
 * 字段偏移 top8: 0x1×2 / 0x80×1 / 0x23×1 / 0x-1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc4964 sub r3, r2, #2
 *   @0xc4968 cmp r3, #34
 *   @0xc496c push {r4, r5, r6, r7, r8, lr}
 *   @0xc4970 movhi r3, #0
 *   @0xc4974 mov r5, r2
 *   @0xc4978 mov r4, r0
 *   @0xc497c mov r7, r1
 *   @0xc4980 strbhi r3, [r1]
 *   @0xc4984 bhi 0xc4a08 <_Z5_itoaiPci+0xa4>
 *   @0xc4988 ldr r8, [pc, #0x80]
 *   @0xc498c mov r6, r1
 *   @0xc4990 add r8, pc, r8
 *   @0xc4994 b 0xc49a0 <_Z5_itoaiPci+0x3c>
 *   @0xc4998 mov r4, r0
 *   @0xc499c mov r6, r3
 *   @0xc49a0 mov r0, r4
 *   @0xc49a4 mov r1, r5
 *   @0xc49a8 bl 0x318d10 <__divsi3>
 *   @0xc49ac mov r3, r6
 *   @0xc49b0 mls r2, r5, r0, r4
 *   @0xc49b4 cmp r0, #0
 *   @0xc49b8 add r2, r8, r2
 *   @0xc49bc ldrb r2, [r2, #0x23]
 *   @0xc49c0 strb r2, [r3], #1
 *   @0xc49c4 bne 0xc4998 <_Z5_itoaiPci+0x34>
 *   @0xc49c8 cmp r4, #0
 *   @0xc49cc mov r1, #0
 *   @0xc49d0 addlt r3, r6, #2
 *   @0xc49d4 movlt r2, #45
 *   @0xc49d8 strblt r2, [r6, #0x1]
 *   @0xc49dc sub r2, r3, #1
 *   @0xc49e0 strb r1, [r3]
 *   @0xc49e4 cmp r7, r2
 *   @0xc49e8 bhs 0xc4a08 <_Z5_itoaiPci+0xa4>
 *   @0xc49ec mov r3, r7
 *   @0xc49f0 ldrb r1, [r2]
 *   @0xc49f4 ldrb r0, [r3]
 *   @0xc49f8 strb r0, [r2], #-1
 *   @0xc49fc strb r1, [r3], #1
 *   @0xc4a00 cmp r2, r3
 *   @0xc4a04 bhi 0xc49f0 <_Z5_itoaiPci+0x8c>
 *   @0xc4a08 mov r0, r7
 *   @0xc4a0c pop {r4, r5, r6, r7, r8, pc}
 *   @0xc4a10 eoreq r12, r6, r12, lsr #3
 *
 * ══ §99/168 ARRAY_RVAL_RValue(RValue const*, int)  0xcede4  size 176  44 条（0xcede4..0xcee94）
 * @func 0xcede4 0xceea8  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ARRAY_RVAL_RValue(RValue const*, int)+0x3c×3 / 0xb664c / YYError(char const*, ...)
 * 字段偏移 top8: 0x4×3 / 0x10×2 / 0xc×1 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcede4 push {r4, lr}
 *   @0xcede8 sub sp, sp, #8
 *   @0xcedec mov r4, r0
 *   @0xcedf0 mov r2, #32000
 *   @0xcedf4 mov r0, sp
 *   @0xcedf8 bl 0xb664c <ldiv@plt>
 *   @0xcedfc ldr r3, [r4, #0xc]
 *   @0xcee00 ldr r2, [sp]
 *   @0xcee04 bic r3, r3, #-16777216
 *   @0xcee08 ldr r1, [sp, #0x4]
 *   @0xcee0c cmp r3, #2
 *   @0xcee10 beq 0xcee2c <_Z17ARRAY_RVAL_RValuePK6RValuei+0x48>
 *   @0xcee14 mvn r2, #-16777216
 *   @0xcee18 cmp r3, r2
 *   @0xcee1c beq 0xcee78 <_Z17ARRAY_RVAL_RValuePK6RValuei+0x94>
 *   @0xcee20 mov r0, #0
 *   @0xcee24 add sp, sp, #8
 *   @0xcee28 pop {r4, pc}
 *   @0xcee2c ldr r0, [r4]
 *   @0xcee30 cmp r0, #0
 *   @0xcee34 beq 0xcee24 <_Z17ARRAY_RVAL_RValuePK6RValuei+0x40>
 *   @0xcee38 cmp r2, #0
 *   @0xcee3c blt 0xcee20 <_Z17ARRAY_RVAL_RValuePK6RValuei+0x3c>
 *   @0xcee40 ldr r3, [r0, #0x10]
 *   @0xcee44 cmp r3, r2
 *   @0xcee48 ble 0xcee20 <_Z17ARRAY_RVAL_RValuePK6RValuei+0x3c>
 *   @0xcee4c ldr r3, [r0, #0x4]
 *   @0xcee50 cmp r1, #0
 *   @0xcee54 add r0, r3, r2, lsl #3
 *   @0xcee58 blt 0xcee20 <_Z17ARRAY_RVAL_RValuePK6RValuei+0x3c>
 *   @0xcee5c ldr r3, [r3, r2, lsl #3]
 *   @0xcee60 cmp r1, r3
 *   @0xcee64 bge 0xcee20 <_Z17ARRAY_RVAL_RValuePK6RValuei+0x3c>
 *   @0xcee68 ldr r0, [r0, #0x4]
 *   @0xcee6c add r0, r0, r1, lsl #4
 *   @0xcee70 add sp, sp, #8
 *   @0xcee74 pop {r4, pc}
 *   @0xcee78 ldr r0, [pc, #0x10]
 *   @0xcee7c add r0, pc, r0
 *   @0xcee80 bl 0xd547c <_Z7YYErrorPKcz>
 *   @0xcee84 mov r0, #0
 *   @0xcee88 add sp, sp, #8
 *   @0xcee8c pop {r4, pc}
 *   @0xcee90 eoreq r3, r6, r0, lsr r6
 *
 * ══ §100/168 VM::WriteDSSizeCount(Buffer_Standard*, int, int&)  0xdb080  size 176  44 条（0xdb080..0xdb130）
 * @func 0xdb080 0xdb130  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: VM::WriteDSSizeCount(Buffer_Standard*, int, int&)+0x98
 * 字段偏移 top8: 0x38×2 / 0x30×2 / 0x8×2 / 0x2c×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xdb080 vmov s15, r1
 *   @0xdb084 ldr r3, [r0]
 *   @0xdb088 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xdb08c vcvt.f64.u32 d7, s15
 *   @0xdb090 add r8, r0, #44
 *   @0xdb094 mov r6, r0
 *   @0xdb098 mov r10, r2
 *   @0xdb09c mov r9, #0
 *   @0xdb0a0 mov r7, r1
 *   @0xdb0a4 str r9, [r0, #0x38]
 *   @0xdb0a8 mov r1, #5
 *   @0xdb0ac mov r2, r8
 *   @0xdb0b0 vmov r4, r5, d7
 *   @0xdb0b4 vstr s14, [r6, #44]
 *   @0xdb0b8 str r5, [r6, #0x30]
 *   @0xdb0bc ldr r3, [r3, #0x8]
 *   @0xdb0c0 blx r3
 *   @0xdb0c4 ldr r3, [r10]
 *   @0xdb0c8 cmp r3, r9
 *   @0xdb0cc blt 0xdb118 <_ZN2VM16WriteDSSizeCountEP15Buffer_StandardiRi+0x98>
 *   @0xdb0d0 rsb r7, r3, r7
 *   @0xdb0d4 cmp r7, #50
 *   @0xdb0d8 movge r7, #50
 *   @0xdb0dc vmov s15, r7
 *   @0xdb0e0 vcvt.f64.u32 d7, s15
 *   @0xdb0e4 vmov r4, r5, d7
 *   @0xdb0e8 ldr r3, [r6]
 *   @0xdb0ec mov r12, #0
 *   @0xdb0f0 str r4, [r6, #0x2c]
 *   @0xdb0f4 mov r2, r8
 *   @0xdb0f8 str r5, [r6, #0x30]
 *   @0xdb0fc mov r0, r6
 *   @0xdb100 ldr r3, [r3, #0x8]
 *   @0xdb104 mov r1, #5
 *   @0xdb108 str r12, [r6, #0x38]
 *   @0xdb10c blx r3
 *   @0xdb110 mov r0, r7
 *   @0xdb114 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xdb118 cmp r7, #50
 *   @0xdb11c str r9, [r10]
 *   @0xdb120 movgt r7, r9
 *   @0xdb124 movgt r4, #0
 *   @0xdb128 movgt r5, #0
 *   @0xdb12c b 0xdb0e8 <_ZN2VM16WriteDSSizeCountEP15Buffer_StandardiRi+0x68>
 *
 * ══ §101/168 CExtensionFile::SetCFunctions(int)  0xf4cd8  size 176  44 条（0xf4cd8..0xf4d88）
 * @func 0xf4cd8 0xf4d88  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CExtensionFunction::Free() / MemoryManager::SetLength(void**, unsigned int, char const*, int) / CExtensionFile::SetCFunctions(int)+0xa4 / operator new(unsigned int) / CExtensionFunction::CExtensionFunction()
 * 字段偏移 top8: 0x1c×4 / 0x18×3 / 0x54×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4cd8 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0xf4cdc bic r7, r1, r1, asr #31
 *   @0xf4ce0 ldr r3, [r0, #0x1c]
 *   @0xf4ce4 mov r4, r0
 *   @0xf4ce8 lsl r9, r7, #2
 *   @0xf4cec cmp r7, r3
 *   @0xf4cf0 bge 0xf4d28 <_ZN14CExtensionFile13SetCFunctionsEi+0x50>
 *   @0xf4cf4 mov r6, r7
 *   @0xf4cf8 mov r8, #0
 *   @0xf4cfc mov r5, r9
 *   @0xf4d00 ldr r3, [r4, #0x18]
 *   @0xf4d04 add r6, r6, #1
 *   @0xf4d08 ldr r0, [r3, r5]
 *   @0xf4d0c bl 0xf4b94 <_ZN18CExtensionFunction4FreeEv>
 *   @0xf4d10 ldr r2, [r4, #0x1c]
 *   @0xf4d14 ldr r3, [r4, #0x18]
 *   @0xf4d18 cmp r2, r6
 *   @0xf4d1c str r8, [r3, r5]
 *   @0xf4d20 add r5, r5, #4
 *   @0xf4d24 bgt 0xf4d00 <_ZN14CExtensionFile13SetCFunctionsEi+0x28>
 *   @0xf4d28 ldr r2, [pc, #0x54]
 *   @0xf4d2c mov r1, r9
 *   @0xf4d30 add r0, r4, #24
 *   @0xf4d34 movw r3, #0x152
 *   @0xf4d38 add r2, pc, r2
 *   @0xf4d3c bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xf4d40 ldr r5, [r4, #0x1c]
 *   @0xf4d44 str r7, [r4, #0x14]
 *   @0xf4d48 cmp r7, r5
 *   @0xf4d4c lslgt r6, r5, #2
 *   @0xf4d50 ble 0xf4d7c <_ZN14CExtensionFile13SetCFunctionsEi+0xa4>
 *   @0xf4d54 mov r0, #100
 *   @0xf4d58 add r5, r5, #1
 *   @0xf4d5c bl 0x27c524 <_Znwj>
 *   @0xf4d60 mov r8, r0
 *   @0xf4d64 bl 0xf49e4 <_ZN18CExtensionFunctionC2Ev>
 *   @0xf4d68 ldr r3, [r4, #0x18]
 *   @0xf4d6c cmp r5, r7
 *   @0xf4d70 str r8, [r3, r6]
 *   @0xf4d74 add r6, r6, #4
 *   @0xf4d78 bne 0xf4d54 <_ZN14CExtensionFile13SetCFunctionsEi+0x7c>
 *   @0xf4d7c str r7, [r4, #0x1c]
 *   @0xf4d80 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xf4d84 .word 0x00242bdc
 *
 * ══ §102/168 CExtensionFile::SetCConstants(int)  0xf4dd4  size 176  44 条（0xf4dd4..0xf4e84）
 * @func 0xf4dd4 0xf4e84  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CExtensionConstant::Free() / MemoryManager::SetLength(void**, unsigned int, char const*, int) / CExtensionFile::SetCConstants(int)+0xa4 / operator new(unsigned int) / CExtensionConstant::CExtensionConstant()
 * 字段偏移 top8: 0x28×4 / 0x24×3 / 0x54×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4dd4 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0xf4dd8 bic r7, r1, r1, asr #31
 *   @0xf4ddc ldr r3, [r0, #0x28]
 *   @0xf4de0 mov r4, r0
 *   @0xf4de4 lsl r9, r7, #2
 *   @0xf4de8 cmp r7, r3
 *   @0xf4dec bge 0xf4e24 <_ZN14CExtensionFile13SetCConstantsEi+0x50>
 *   @0xf4df0 mov r6, r7
 *   @0xf4df4 mov r8, #0
 *   @0xf4df8 mov r5, r9
 *   @0xf4dfc ldr r3, [r4, #0x24]
 *   @0xf4e00 add r6, r6, #1
 *   @0xf4e04 ldr r0, [r3, r5]
 *   @0xf4e08 bl 0xf48f0 <_ZN18CExtensionConstant4FreeEv>
 *   @0xf4e0c ldr r2, [r4, #0x28]
 *   @0xf4e10 ldr r3, [r4, #0x24]
 *   @0xf4e14 cmp r2, r6
 *   @0xf4e18 str r8, [r3, r5]
 *   @0xf4e1c add r5, r5, #4
 *   @0xf4e20 bgt 0xf4dfc <_ZN14CExtensionFile13SetCConstantsEi+0x28>
 *   @0xf4e24 ldr r2, [pc, #0x54]
 *   @0xf4e28 mov r1, r9
 *   @0xf4e2c add r0, r4, #36
 *   @0xf4e30 mov r3, #380
 *   @0xf4e34 add r2, pc, r2
 *   @0xf4e38 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xf4e3c ldr r5, [r4, #0x28]
 *   @0xf4e40 str r7, [r4, #0x20]
 *   @0xf4e44 cmp r7, r5
 *   @0xf4e48 lslgt r6, r5, #2
 *   @0xf4e4c ble 0xf4e78 <_ZN14CExtensionFile13SetCConstantsEi+0xa4>
 *   @0xf4e50 mov r0, #12
 *   @0xf4e54 add r5, r5, #1
 *   @0xf4e58 bl 0x27c524 <_Znwj>
 *   @0xf4e5c mov r8, r0
 *   @0xf4e60 bl 0xf4804 <_ZN18CExtensionConstantC2Ev>
 *   @0xf4e64 ldr r3, [r4, #0x24]
 *   @0xf4e68 cmp r5, r7
 *   @0xf4e6c str r8, [r3, r6]
 *   @0xf4e70 add r6, r6, #4
 *   @0xf4e74 bne 0xf4e50 <_ZN14CExtensionFile13SetCConstantsEi+0x7c>
 *   @0xf4e78 str r7, [r4, #0x28]
 *   @0xf4e7c pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xf4e80 eoreq r2, r4, r0, ror #21
 *
 * ══ §103/168 CExtensionPackage::SetCIncludes(int)  0xf53e4  size 176  44 条（0xf53e4..0xf5494）
 * @func 0xf53e4 0xf5494  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CExtensionFile::Free() / MemoryManager::SetLength(void**, unsigned int, char const*, int) / CExtensionPackage::SetCIncludes(int)+0xa4 / operator new(unsigned int) / CExtensionFile::CExtensionFile()
 * 字段偏移 top8: 0x18×4 / 0x14×3 / 0x54×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf53e4 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0xf53e8 bic r7, r1, r1, asr #31
 *   @0xf53ec ldr r3, [r0, #0x18]
 *   @0xf53f0 mov r4, r0
 *   @0xf53f4 lsl r9, r7, #2
 *   @0xf53f8 cmp r7, r3
 *   @0xf53fc bge 0xf5434 <_ZN17CExtensionPackage12SetCIncludesEi+0x50>
 *   @0xf5400 mov r6, r7
 *   @0xf5404 mov r8, #0
 *   @0xf5408 mov r5, r9
 *   @0xf540c ldr r3, [r4, #0x14]
 *   @0xf5410 add r6, r6, #1
 *   @0xf5414 ldr r0, [r3, r5]
 *   @0xf5418 bl 0xf4f90 <_ZN14CExtensionFile4FreeEv>
 *   @0xf541c ldr r2, [r4, #0x18]
 *   @0xf5420 ldr r3, [r4, #0x14]
 *   @0xf5424 cmp r2, r6
 *   @0xf5428 str r8, [r3, r5]
 *   @0xf542c add r5, r5, #4
 *   @0xf5430 bgt 0xf540c <_ZN17CExtensionPackage12SetCIncludesEi+0x28>
 *   @0xf5434 ldr r2, [pc, #0x54]
 *   @0xf5438 mov r1, r9
 *   @0xf543c add r0, r4, #20
 *   @0xf5440 movw r3, #0x2a1
 *   @0xf5444 add r2, pc, r2
 *   @0xf5448 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xf544c ldr r5, [r4, #0x18]
 *   @0xf5450 str r7, [r4, #0x10]
 *   @0xf5454 cmp r7, r5
 *   @0xf5458 lslgt r6, r5, #2
 *   @0xf545c ble 0xf5488 <_ZN17CExtensionPackage12SetCIncludesEi+0xa4>
 *   @0xf5460 mov r0, #44
 *   @0xf5464 add r5, r5, #1
 *   @0xf5468 bl 0x27c524 <_Znwj>
 *   @0xf546c mov r8, r0
 *   @0xf5470 bl 0xf5098 <_ZN14CExtensionFileC2Ev>
 *   @0xf5474 ldr r3, [r4, #0x14]
 *   @0xf5478 cmp r5, r7
 *   @0xf547c str r8, [r3, r6]
 *   @0xf5480 add r6, r6, #4
 *   @0xf5484 bne 0xf5460 <_ZN17CExtensionPackage12SetCIncludesEi+0x7c>
 *   @0xf5488 str r7, [r4, #0x18]
 *   @0xf548c pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xf5490 .word 0x002424d0
 *
 * ══ §104/168 F_InstanceCreateDepth(RValue&, CInstance*, CInstance*, int, RValue*)  0x109634  size 176  44 条（0x109634..0x1096e4）
 * @func 0x109634 0x1096e4  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / YYGetFloat(RValue const*, int)×2 / Command_Create_Depth(int, float, float, int)
 * 字段偏移 top8: 0xc×2 / 0x18×1 / 0x48×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x109634 push {r4, r5, r6, r7, r8, lr}
 *   @0x109638 mov r1, #3
 *   @0x10963c ldr r4, [sp, #0x18]
 *   @0x109640 mov r5, r0
 *   @0x109644 mov r0, r4
 *   @0x109648 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x10964c mov r1, #0
 *   @0x109650 mov r8, r0
 *   @0x109654 mov r0, r4
 *   @0x109658 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10965c mov r1, #1
 *   @0x109660 mov r7, r0
 *   @0x109664 mov r0, r4
 *   @0x109668 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10966c mov r1, #2
 *   @0x109670 mov r6, r0
 *   @0x109674 mov r0, r4
 *   @0x109678 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x10967c mov r1, r7
 *   @0x109680 mov r2, r6
 *   @0x109684 mov r3, r0
 *   @0x109688 mov r0, r8
 *   @0x10968c bl 0x1c98d4 <_Z20Command_Create_Depthiffi>
 *   @0x109690 ldr r3, [pc, #0x48]
 *   @0x109694 ldr r3, [pc, r3]
 *   @0x109698 ldrb r3, [r3]
 *   @0x10969c cmp r3, #0
 *   @0x1096a0 bne 0x1096d0 <_Z21F_InstanceCreateDepthR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x1096a4 cmp r0, #0
 *   @0x1096a8 str r3, [r5, #0xc]
 *   @0x1096ac ldrne r2, [r0, #0x78]
 *   @0x1096b0 moveq r3, #0
 *   @0x1096b4 moveq r2, #0
 *   @0x1096b8 movteq r3, #0xbff0
 *   @0x1096bc vmovne s15, r2
 *   @0x1096c0 vcvtne.f64.s32 d7, s15
 *   @0x1096c4 vmovne r2, r3, d7
 *   @0x1096c8 stm r5, {r2, r3}
 *   @0x1096cc pop {r4, r5, r6, r7, r8, pc}
 *   @0x1096d0 mov r3, #6
 *   @0x1096d4 str r0, [r5]
 *   @0x1096d8 str r3, [r5, #0xc]
 *   @0x1096dc pop {r4, r5, r6, r7, r8, pc}
 *   @0x1096e0 eoreq r4, lr, r4, lsr #10
 *
 * ══ §105/168 F_DArcCos(RValue&, CInstance*, CInstance*, int, RValue*)  0x10e8cc  size 176  44 条（0x10e8cc..0x10e97c）
 * @func 0x10e8cc 0x10e97c  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int) / F_DArcCos(RValue&, CInstance*, CInstance*, int, RValue*)+0x4c / F_DArcCos(RValue&, CInstance*, CInstance*, int, RValue*)+0x60 / 0xb6760
 * 字段偏移 top8: 0x8×1 / 0xc×1 / 0x4×1 / 0x58×1
 * VFP 指令 18 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10e8cc push {r4, lr}
 *   @0x10e8d0 mov r3, #0
 *   @0x10e8d4 ldr r2, [sp, #0x8]
 *   @0x10e8d8 mov r4, r0
 *   @0x10e8dc str r3, [r0, #0xc]
 *   @0x10e8e0 mov r1, r3
 *   @0x10e8e4 str r3, [r0]
 *   @0x10e8e8 str r3, [r0, #0x4]
 *   @0x10e8ec mov r0, r2
 *   @0x10e8f0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x10e8f4 vmov.f32 s14, #-1.000000e+00
 *   @0x10e8f8 vmov s15, r0
 *   @0x10e8fc vcmpe.f32 s15, s14
 *   @0x10e900 vmrs APSR_nzcv, fpscr
 *   @0x10e904 blt 0x10e918 <_Z9F_DArcCosR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x10e908 vmov.f32 s14, #1.000000e+00
 *   @0x10e90c vcmpe.f32 s15, s14
 *   @0x10e910 vmrs APSR_nzcv, fpscr
 *   @0x10e914 bls 0x10e92c <_Z9F_DArcCosR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x10e918 ldr r0, [pc, #0x58]
 *   @0x10e91c mov r1, #0
 *   @0x10e920 pop {r4, lr}
 *   @0x10e924 add r0, pc, r0
 *   @0x10e928 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x10e92c bl 0xb6760 <acosf@plt>
 *   @0x10e930 vldr s15, [pc, #52]
 *   @0x10e934 vldr s13, [pc, #52]
 *   @0x10e938 vldr s14, [pc, #52]
 *   @0x10e93c vmov s12, r0
 *   @0x10e940 vmul.f32 s15, s12, s15
 *   @0x10e944 vdiv.f32 s15, s15, s13
 *   @0x10e948 vabs.f32 s13, s15
 *   @0x10e94c vcmpe.f32 s13, s14
 *   @0x10e950 vmrs APSR_nzcv, fpscr
 *   @0x10e954 vcvtpl.f64.f32 d6, s15
 *   @0x10e958 movmi r2, #0
 *   @0x10e95c movmi r3, #0
 *   @0x10e960 vmovpl r2, r3, d6
 *   @0x10e964 stm r4, {r2, r3}
 *   @0x10e968 pop {r4, pc}
 *   @0x10e96c teqmi r4, #0
 *   @0x10e970 ldrdmi r0, r1, [r9], #-251
 *   @0x10e974 strlo r12, [r7, -r12, lsr #11]!
 *   @0x10e978 eoreq r10, r2, r4, lsl #10
 *
 * ══ §106/168 F_DrawRoundRectColour(RValue&, CInstance*, CInstance*, int, RValue*)  0x11b628  size 176  44 条（0x11b628..0x11b6d8）
 * @func 0x11b628 0x11b6d8  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4 / YYGetInt32(RValue const*, int)×2 / YYGetBool(RValue const*, int) / GR_Draw_RoundRect_Ext(float, float, float, float, float, float, unsigned int, unsigned int, bool)
 * 字段偏移 top8: 0x38×1 / 0x8×1 / 0xc×1 / 0x4×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11b628 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x11b62c sub sp, sp, #24
 *   @0x11b630 mov r1, #0
 *   @0x11b634 ldr r4, [sp, #0x38]
 *   @0x11b638 mov r0, r4
 *   @0x11b63c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b640 mov r1, #1
 *   @0x11b644 mov r5, r0
 *   @0x11b648 mov r0, r4
 *   @0x11b64c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b650 mov r1, #2
 *   @0x11b654 mov r8, r0
 *   @0x11b658 mov r0, r4
 *   @0x11b65c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b660 mov r1, #3
 *   @0x11b664 mov r7, r0
 *   @0x11b668 mov r0, r4
 *   @0x11b66c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b670 mov r1, #4
 *   @0x11b674 mov r6, r0
 *   @0x11b678 mov r0, r4
 *   @0x11b67c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11b680 mov r1, #5
 *   @0x11b684 mov r10, r0
 *   @0x11b688 mov r0, r4
 *   @0x11b68c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11b690 mov r1, #6
 *   @0x11b694 mov r9, r0
 *   @0x11b698 mov r0, r4
 *   @0x11b69c bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x11b6a0 str r10, [sp, #0x8]
 *   @0x11b6a4 str r9, [sp, #0xc]
 *   @0x11b6a8 mov r1, r8
 *   @0x11b6ac mov r2, r7
 *   @0x11b6b0 mov r3, r6
 *   @0x11b6b4 mov r12, #0
 *   @0x11b6b8 movt r12, #0x4120
 *   @0x11b6bc str r12, [sp]
 *   @0x11b6c0 str r12, [sp, #0x4]
 *   @0x11b6c4 str r0, [sp, #0x10]
 *   @0x11b6c8 mov r0, r5
 *   @0x11b6cc bl 0x16b864 <_Z21GR_Draw_RoundRect_Extffffffjjb>
 *   @0x11b6d0 add sp, sp, #24
 *   @0x11b6d4 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ §107/168 F_DrawSurfaceStretched(RValue&, CInstance*, CInstance*, int, RValue*)  0x11edb4  size 176  44 条（0x11edb4..0x11ee64）
 * @func 0x11edb4 0x11ee64  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4 / YYGetInt32(RValue const*, int) / GR_Surface_Exists(int) / GR_Draw_Get_Alpha() / GR_Surface_DrawStretched(int, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0x28×1 / 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11edb4 push {r4, r5, r6, r7, r8, lr}
 *   @0x11edb8 sub sp, sp, #16
 *   @0x11edbc mov r1, #0
 *   @0x11edc0 ldr r4, [sp, #0x28]
 *   @0x11edc4 mov r0, r4
 *   @0x11edc8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11edcc mov r5, r0
 *   @0x11edd0 bl 0x1714c0 <_Z17GR_Surface_Existsi>
 *   @0x11edd4 subs r1, r0, #0
 *   @0x11edd8 beq 0x11ee4c <_Z22F_DrawSurfaceStretchedR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x11eddc mov r0, r4
 *   @0x11ede0 mov r1, #1
 *   @0x11ede4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11ede8 mov r1, #2
 *   @0x11edec mov r8, r0
 *   @0x11edf0 mov r0, r4
 *   @0x11edf4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11edf8 mov r1, #3
 *   @0x11edfc mov r7, r0
 *   @0x11ee00 mov r0, r4
 *   @0x11ee04 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11ee08 mov r1, #4
 *   @0x11ee0c mov r6, r0
 *   @0x11ee10 mov r0, r4
 *   @0x11ee14 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11ee18 mov r4, r0
 *   @0x11ee1c bl 0x169f1c <_Z17GR_Draw_Get_Alphav>
 *   @0x11ee20 mvn r12, #-16777216
 *   @0x11ee24 str r4, [sp]
 *   @0x11ee28 mov r1, r8
 *   @0x11ee2c mov r2, r7
 *   @0x11ee30 mov r3, r6
 *   @0x11ee34 str r12, [sp, #0x4]
 *   @0x11ee38 str r0, [sp, #0x8]
 *   @0x11ee3c mov r0, r5
 *   @0x11ee40 bl 0x171e2c <_Z24GR_Surface_DrawStretchediffffjf>
 *   @0x11ee44 add sp, sp, #16
 *   @0x11ee48 pop {r4, r5, r6, r7, r8, pc}
 *   @0x11ee4c ldr r0, [pc, #0xc]
 *   @0x11ee50 add r0, pc, r0
 *   @0x11ee54 add sp, sp, #16
 *   @0x11ee58 pop {r4, r5, r6, r7, r8, lr}
 *   @0x11ee5c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x11ee60 eoreq r11, r1, r8, lsl r4
 *
 * ══ §108/168 F_SkeletonGetMinmax(RValue&, CInstance*, CInstance*, int, RValue*)  0x1214bc  size 176  44 条（0x1214bc..0x12156c）
 * @func 0x1214bc 0x12156c  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CreateArray(RValue*, int, ...)×2 / CInstance::SkeletonAnimation() / CSkeletonInstance::GetBoundingBox(float&, float&, float&, float&)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1214bc push {r4, lr}
 *   @0x1214c0 mov r4, r0
 *   @0x1214c4 mov r3, #2
 *   @0x1214c8 sub sp, sp, #40
 *   @0x1214cc mov r0, r1
 *   @0x1214d0 str r3, [r4, #0xc]
 *   @0x1214d4 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv>
 *   @0x1214d8 cmp r0, #0
 *   @0x1214dc beq 0x121500 <_Z19F_SkeletonGetMinmaxR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x1214e0 add r3, sp, #36
 *   @0x1214e4 add r1, sp, #24
 *   @0x1214e8 str r3, [sp]
 *   @0x1214ec add r2, sp, #28
 *   @0x1214f0 add r3, sp, #32
 *   @0x1214f4 bl 0xbee60 <_ZN17CSkeletonInstance14GetBoundingBoxERfS0_S0_S0_>
 *   @0x1214f8 cmp r0, #0
 *   @0x1214fc bne 0x121528 <_Z19F_SkeletonGetMinmaxR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x121500 mov r2, #0
 *   @0x121504 mov r3, #0
 *   @0x121508 mov r0, r4
 *   @0x12150c mov r1, #4
 *   @0x121510 strd r2, r3, [sp]
 *   @0x121514 strd r2, r3, [sp, #8]
 *   @0x121518 strd r2, r3, [sp, #16]
 *   @0x12151c bl 0x120eb4 <_Z11CreateArrayP6RValueiz>
 *   @0x121520 add sp, sp, #40
 *   @0x121524 pop {r4, pc}
 *   @0x121528 vldr s14, [sp, #36]
 *   @0x12152c vcvt.f64.f32 d7, s14
 *   @0x121530 vldr s10, [sp, #28]
 *   @0x121534 vldr s12, [sp, #32]
 *   @0x121538 vldr s9, [sp, #24]
 *   @0x12153c mov r0, r4
 *   @0x121540 mov r1, #4
 *   @0x121544 vcvt.f64.f32 d5, s10
 *   @0x121548 vstr d7, [sp, #16]
 *   @0x12154c vcvt.f64.f32 d6, s12
 *   @0x121550 vstr d5, [sp]
 *   @0x121554 vcvt.f64.f32 d7, s9
 *   @0x121558 vstr d6, [sp, #8]
 *   @0x12155c vmov r2, r3, d7
 *   @0x121560 bl 0x120eb4 <_Z11CreateArrayP6RValueiz>
 *   @0x121564 add sp, sp, #40
 *   @0x121568 pop {r4, pc}
 *
 * ══ §109/168 F_GetOpenFileNameExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x126c08  size 176  44 条（0x126c08..0x126cb8）
 * @func 0x126c08 0x126cb8  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)×4 / YYGetOpenFileName(char*, char*, char*, char*) / operator new(unsigned int) / 0xb6640 / YYCreateString(RValue*, char const*)
 * 字段偏移 top8: 0x18×1 / 0x2c×1 / 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x126c08 push {r4, r5, r6, r7, r8, lr}
 *   @0x126c0c mov r1, #0
 *   @0x126c10 ldr r4, [sp, #0x18]
 *   @0x126c14 mov r6, r0
 *   @0x126c18 mov r0, r4
 *   @0x126c1c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x126c20 mov r1, #1
 *   @0x126c24 mov r8, r0
 *   @0x126c28 mov r0, r4
 *   @0x126c2c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x126c30 mov r1, #2
 *   @0x126c34 mov r7, r0
 *   @0x126c38 mov r0, r4
 *   @0x126c3c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x126c40 mov r1, #3
 *   @0x126c44 mov r5, r0
 *   @0x126c48 mov r0, r4
 *   @0x126c4c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x126c50 mov r2, r5
 *   @0x126c54 mov r1, r7
 *   @0x126c58 mov r3, r0
 *   @0x126c5c mov r0, r8
 *   @0x126c60 bl 0x160ec0 <_Z17YYGetOpenFileNamePcS_S_S_>
 *   @0x126c64 subs r5, r0, #0
 *   @0x126c68 beq 0x126ca0 <_Z20F_GetOpenFileNameExtR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x126c6c mov r0, #12
 *   @0x126c70 bl 0x27c524 <_Znwj>
 *   @0x126c74 mov r4, r0
 *   @0x126c78 mov r0, r5
 *   @0x126c7c bl 0xb6640 <strdup@plt>
 *   @0x126c80 ldr r3, [pc, #0x2c]
 *   @0x126c84 mov r2, #0
 *   @0x126c88 strb r2, [r4, #0x8]
 *   @0x126c8c ldr r3, [pc, r3]
 *   @0x126c90 ldr r2, [r3]
 *   @0x126c94 str r2, [r4]
 *   @0x126c98 str r4, [r3]
 *   @0x126c9c str r0, [r4, #0x4]
 *   @0x126ca0 mov r0, r6
 *   @0x126ca4 mov r1, r5
 *   @0x126ca8 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x126cac pop {r4, r5, r6, r7, r8, lr}
 *   @0x126cb0 b 0x18c2c8 <_Z8IO_Clearv>
 *   @0x126cb4 .word 0x002c7dfc
 *
 * ══ §110/168 F_GetSaveFileNameExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x126d48  size 176  44 条（0x126d48..0x126df8）
 * @func 0x126d48 0x126df8  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)×4 / YYGetSaveFileName(char*, char*, char*, char*) / operator new(unsigned int) / 0xb6640 / YYCreateString(RValue*, char const*)
 * 字段偏移 top8: 0x18×1 / 0x2c×1 / 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x126d48 push {r4, r5, r6, r7, r8, lr}
 *   @0x126d4c mov r1, #0
 *   @0x126d50 ldr r4, [sp, #0x18]
 *   @0x126d54 mov r6, r0
 *   @0x126d58 mov r0, r4
 *   @0x126d5c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x126d60 mov r1, #1
 *   @0x126d64 mov r8, r0
 *   @0x126d68 mov r0, r4
 *   @0x126d6c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x126d70 mov r1, #2
 *   @0x126d74 mov r7, r0
 *   @0x126d78 mov r0, r4
 *   @0x126d7c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x126d80 mov r1, #3
 *   @0x126d84 mov r5, r0
 *   @0x126d88 mov r0, r4
 *   @0x126d8c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x126d90 mov r2, r5
 *   @0x126d94 mov r1, r7
 *   @0x126d98 mov r3, r0
 *   @0x126d9c mov r0, r8
 *   @0x126da0 bl 0x160ec8 <_Z17YYGetSaveFileNamePcS_S_S_>
 *   @0x126da4 subs r5, r0, #0
 *   @0x126da8 beq 0x126de0 <_Z20F_GetSaveFileNameExtR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x126dac mov r0, #12
 *   @0x126db0 bl 0x27c524 <_Znwj>
 *   @0x126db4 mov r4, r0
 *   @0x126db8 mov r0, r5
 *   @0x126dbc bl 0xb6640 <strdup@plt>
 *   @0x126dc0 ldr r3, [pc, #0x2c]
 *   @0x126dc4 mov r2, #0
 *   @0x126dc8 strb r2, [r4, #0x8]
 *   @0x126dcc ldr r3, [pc, r3]
 *   @0x126dd0 ldr r2, [r3]
 *   @0x126dd4 str r2, [r4]
 *   @0x126dd8 str r4, [r3]
 *   @0x126ddc str r0, [r4, #0x4]
 *   @0x126de0 mov r0, r6
 *   @0x126de4 mov r1, r5
 *   @0x126de8 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x126dec pop {r4, r5, r6, r7, r8, lr}
 *   @0x126df0 b 0x18c2c8 <_Z8IO_Clearv>
 *   @0x126df4 eoreq r6, r12, r0, lsl #24
 *
 * ══ §111/168 F_GetStringAsync(RValue&, CInstance*, CInstance*, int, RValue*)  0x1270d8  size 176  44 条（0x1270d8..0x127188）
 * @func 0x1270d8 0x12719c  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool) / STRING_RValue(char**, char**, int*, RValue const*) / String_Replace_Hash(char*) / YYGetString(RValue const*, int) / InputQuery::InputAsync(char const*, char const*, char const*) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x8×4 / 0xa0×1 / 0x4×1 / 0x20×1 / 0x-4×1 / 0x38×1 / 0xc×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1270d8 ldr r1, [pc, #0xa0]
 *   @0x1270dc mov r12, #16
 *   @0x1270e0 push {r4, r5, r6, lr}
 *   @0x1270e4 sub sp, sp, #16
 *   @0x1270e8 mov r4, r0
 *   @0x1270ec add r1, pc, r1
 *   @0x1270f0 mov r0, r12
 *   @0x1270f4 movw r2, #0x5d1
 *   @0x1270f8 mov r3, #1
 *   @0x1270fc str r12, [sp, #0x4]
 *   @0x127100 ldr r6, [sp, #0x20]
 *   @0x127104 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x127108 mov r5, #0
 *   @0x12710c add r2, sp, #4
 *   @0x127110 add r1, sp, #8
 *   @0x127114 mov r3, r0
 *   @0x127118 add r0, sp, #16
 *   @0x12711c str r3, [sp, #0x8]
 *   @0x127120 str r3, [r0, #-0x4]!
 *   @0x127124 strb r5, [r3]
 *   @0x127128 add r3, r6, #16
 *   @0x12712c bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue>
 *   @0x127130 ldr r0, [sp, #0x8]
 *   @0x127134 bl 0x212da8 <_Z19String_Replace_HashPc>
 *   @0x127138 mov r1, r5
 *   @0x12713c mov r0, r6
 *   @0x127140 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x127144 ldr r3, [pc, #0x38]
 *   @0x127148 ldr r2, [sp, #0x8]
 *   @0x12714c ldr r3, [pc, r3]
 *   @0x127150 str r5, [r4, #0xc]
 *   @0x127154 mov r1, r0
 *   @0x127158 ldr r0, [r3]
 *   @0x12715c bl 0xf26c4 <_ZN10InputQuery10InputAsyncEPKcS1_S1_>
 *   @0x127160 vmov s15, r0
 *   @0x127164 ldr r0, [sp, #0x8]
 *   @0x127168 vcvt.f64.s32 d7, s15
 *   @0x12716c vmov r2, r3, d7
 *   @0x127170 stm r4, {r2, r3}
 *   @0x127174 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x127178 add sp, sp, #16
 *   @0x12717c pop {r4, r5, r6, pc}
 *   @0x127180 eoreq r5, r1, r8, asr #2
 *   @0x127184 eoreq r7, r12, r4, lsr r9
 *
 * ══ §112/168 F_SoundReplace(RValue&, CInstance*, CInstance*, int, RValue*)  0x12f7a8  size 176  44 条（0x12f7a8..0x12f858）
 * @func 0x12f7a8 0x12f858  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / Sound_Data(int) / YYGetString(RValue const*, int) / YYGetBool(RValue const*, int) / Sound_Replace(int, char const*, int, bool)
 * 字段偏移 top8: 0xc×2 / 0x9c×1 / 0x20×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12f7a8 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x12f7ac mov r6, r0
 *   @0x12f7b0 ldr r3, [pc, #0x9c]
 *   @0x12f7b4 ldr r5, [sp, #0x20]
 *   @0x12f7b8 ldr r3, [pc, r3]
 *   @0x12f7bc ldrb r4, [r3]
 *   @0x12f7c0 cmp r4, #0
 *   @0x12f7c4 popne {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x12f7c8 mov r1, r4
 *   @0x12f7cc mov r0, r5
 *   @0x12f7d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f7d4 mov r7, r0
 *   @0x12f7d8 bl 0x21fcd4 <_Z10Sound_Datai>
 *   @0x12f7dc cmp r0, #0
 *   @0x12f7e0 beq 0x12f844 <_Z14F_SoundReplaceR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x12f7e4 mov r1, #1
 *   @0x12f7e8 mov r0, r5
 *   @0x12f7ec bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x12f7f0 mov r1, #2
 *   @0x12f7f4 mov r9, r0
 *   @0x12f7f8 mov r0, r5
 *   @0x12f7fc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f800 mov r1, #3
 *   @0x12f804 mov r8, r0
 *   @0x12f808 mov r0, r5
 *   @0x12f80c bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12f810 mov r1, r9
 *   @0x12f814 mov r2, r8
 *   @0x12f818 mov r3, r0
 *   @0x12f81c mov r0, r7
 *   @0x12f820 bl 0x220018 <_Z13Sound_ReplaceiPKcib>
 *   @0x12f824 str r4, [r6, #0xc]
 *   @0x12f828 cmp r0, #0
 *   @0x12f82c movne r3, #0
 *   @0x12f830 movtne r3, #0x3ff0
 *   @0x12f834 beq 0x12f848 <_Z14F_SoundReplaceR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x12f838 str r4, [r6]
 *   @0x12f83c str r3, [r6, #0x4]
 *   @0x12f840 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x12f844 str r0, [r6, #0xc]
 *   @0x12f848 mov r4, #0
 *   @0x12f84c mov r3, r4
 *   @0x12f850 b 0x12f838 <_Z14F_SoundReplaceR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x12f854 eoreq pc, r11, r8, ror r5
 *
 * ══ §113/168 F_FileBinRewrite(RValue&, CInstance*, CInstance*, int, RValue*)  0x139404  size 176  44 条（0x139404..0x1394b4）
 * @func 0x139404 0x1394b4  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / LoadSave::fclose(_YYFILE*) / LoadSave::fopen(char const*, char const*)
 * 字段偏移 top8: 0x10×2 / 0x8×2 / 0x7c×1 / 0x68×1 / 0x4c×1 / 0x4×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x139404 push {r4, r5, r6, lr}
 *   @0x139408 mov r1, #0
 *   @0x13940c ldr r0, [sp, #0x10]
 *   @0x139410 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x139414 sub r3, r0, #1
 *   @0x139418 cmp r3, #30
 *   @0x13941c bhi 0x139490 <_Z16F_FileBinRewriteR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x139420 ldr r3, [pc, #0x7c]
 *   @0x139424 ldr r3, [pc, r3]
 *   @0x139428 ldrb r3, [r3, r0]
 *   @0x13942c cmp r3, #0
 *   @0x139430 beq 0x139490 <_Z16F_FileBinRewriteR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x139434 add r0, r0, r0, lsl #1
 *   @0x139438 ldr r4, [pc, #0x68]
 *   @0x13943c lsl r6, r0, #2
 *   @0x139440 ldr r4, [pc, r4]
 *   @0x139444 add r5, r6, r4
 *   @0x139448 ldr r0, [r5, #0x8]
 *   @0x13944c cmp r0, #0
 *   @0x139450 beq 0x139458 <_Z16F_FileBinRewriteR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x139454 bl 0x18ddb8 <_ZN8LoadSave6fcloseEP7_YYFILE>
 *   @0x139458 ldr r1, [pc, #0x4c]
 *   @0x13945c ldr r0, [r4, r6]
 *   @0x139460 add r1, pc, r1
 *   @0x139464 bl 0x18db48 <_ZN8LoadSave5fopenEPKcS1_>
 *   @0x139468 mov r1, #0
 *   @0x13946c mov r2, r1
 *   @0x139470 str r0, [r5, #0x8]
 *   @0x139474 ldr r0, [r0]
 *   @0x139478 ldr r3, [r0]
 *   @0x13947c ldr r3, [r3, #0x10]
 *   @0x139480 blx r3
 *   @0x139484 mov r3, #1
 *   @0x139488 str r3, [r5, #0x4]
 *   @0x13948c pop {r4, r5, r6, pc}
 *   @0x139490 ldr r0, [pc, #0x18]
 *   @0x139494 mov r1, #0
 *   @0x139498 pop {r4, r5, r6, lr}
 *   @0x13949c add r0, pc, r0
 *   @0x1394a0 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1394a4 eoreq r5, r11, r8, ror #28
 *   @0x1394a8 eoreq r5, r11, r0, asr lr
 *   @0x1394ac eoreq r6, r0, r12, lsl sp
 *   @0x1394b0 .word 0x00206cbc
 *
 * ══ §114/168 F_GPUSetTexMaxAniso(RValue&, CInstance*, CInstance*, int, RValue*)  0x147b14  size 176  44 条（0x147b14..0x147bc4）
 * @func 0x147b14 0x147bd8  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / RenderStateManager::SetSamplerState(int, eSamplerState, unsigned int)
 * 字段偏移 top8: 0xc×2 / 0x24×2 / 0x4×1 / 0x10×1 / 0x6c×1 / 0x4c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x147b14 cmp r3, #1
 *   @0x147b18 mov r3, #0
 *   @0x147b1c push {r4, r5, r6, lr}
 *   @0x147b20 mov r4, r3
 *   @0x147b24 mov r1, r4
 *   @0x147b28 movt r3, #0xbff0
 *   @0x147b2c str r4, [r0, #0xc]
 *   @0x147b30 str r3, [r0, #0x4]
 *   @0x147b34 str r4, [r0]
 *   @0x147b38 ldr r0, [sp, #0x10]
 *   @0x147b3c beq 0x147b50 <_Z19F_GPUSetTexMaxAnisoR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x147b40 ldr r0, [pc, #0x6c]
 *   @0x147b44 pop {r4, r5, r6, lr}
 *   @0x147b48 add r0, pc, r0
 *   @0x147b4c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x147b50 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x147b54 sub r3, r0, #1
 *   @0x147b58 mov r6, r0
 *   @0x147b5c cmp r3, #15
 *   @0x147b60 bhi 0x147b90 <_Z19F_GPUSetTexMaxAnisoR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x147b64 ldr r5, [pc, #0x4c]
 *   @0x147b68 ldr r5, [pc, r5]
 *   @0x147b6c mov r1, r4
 *   @0x147b70 mov r0, r5
 *   @0x147b74 mov r2, #8
 *   @0x147b78 add r4, r4, #1
 *   @0x147b7c mov r3, r6
 *   @0x147b80 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x147b84 cmp r4, #8
 *   @0x147b88 bne 0x147b6c <_Z19F_GPUSetTexMaxAnisoR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x147b8c pop {r4, r5, r6, pc}
 *   @0x147b90 ldr r3, [pc, #0x24]
 *   @0x147b94 ldr r1, [pc, #0x24]
 *   @0x147b98 ldr r3, [pc, r3]
 *   @0x147b9c add r1, pc, r1
 *   @0x147ba0 ldr r0, [r3]
 *   @0x147ba4 ldr r3, [r0]
 *   @0x147ba8 ldr r3, [r3, #0xc]
 *   @0x147bac blx r3
 *   @0x147bb0 pop {r4, r5, r6, pc}
 *   @0x147bb4 andseq r10, pc, r0, ror #4
 *   @0x147bb8 mlaeq r10, r0, r1, r6
 *   @0x147bbc eoreq r5, r10, r12, ror r11
 *   @0x147bc0 andseq r10, pc, r8, asr #4
 *
 * ══ §115/168 F_GPUSetTexMaxAnisoExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x147bc4  size 176  44 条（0x147bc4..0x147c74）
 * @func 0x147bc4 0x147c74  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2
 * 字段偏移 top8: 0xc×2 / 0x24×2 / 0x10×1 / 0x74×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x147bc4 cmp r3, #2
 *   @0x147bc8 mov r3, #0
 *   @0x147bcc push {r4, r5, r6, lr}
 *   @0x147bd0 mov r1, r3
 *   @0x147bd4 ldr r4, [sp, #0x10]
 *   @0x147bd8 movt r3, #0xbff0
 *   @0x147bdc str r1, [r0, #0xc]
 *   @0x147be0 stm r0, {r1, r3}
 *   @0x147be4 beq 0x147bf8 <_Z22F_GPUSetTexMaxAnisoExtR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x147be8 ldr r0, [pc, #0x74]
 *   @0x147bec pop {r4, r5, r6, lr}
 *   @0x147bf0 add r0, pc, r0
 *   @0x147bf4 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x147bf8 mov r0, r4
 *   @0x147bfc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x147c00 mov r1, #1
 *   @0x147c04 mov r5, r0
 *   @0x147c08 mov r0, r4
 *   @0x147c0c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x147c10 sub r2, r0, #1
 *   @0x147c14 mov r3, r0
 *   @0x147c18 cmp r2, #15
 *   @0x147c1c bhi 0x147c40 <_Z22F_GPUSetTexMaxAnisoExtR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x147c20 cmp r5, #7
 *   @0x147c24 pophi {r4, r5, r6, pc}
 *   @0x147c28 ldr r0, [pc, #0x38]
 *   @0x147c2c mov r1, r5
 *   @0x147c30 mov r2, #8
 *   @0x147c34 ldr r0, [pc, r0]
 *   @0x147c38 pop {r4, r5, r6, lr}
 *   @0x147c3c b 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x147c40 ldr r3, [pc, #0x24]
 *   @0x147c44 ldr r1, [pc, #0x24]
 *   @0x147c48 ldr r3, [pc, r3]
 *   @0x147c4c add r1, pc, r1
 *   @0x147c50 ldr r0, [r3]
 *   @0x147c54 ldr r3, [r0]
 *   @0x147c58 ldr r3, [r3, #0xc]
 *   @0x147c5c blx r3
 *   @0x147c60 pop {r4, r5, r6, pc}
 *   @0x147c64 andseq r10, pc, r0, lsr r2
 *   @0x147c68 eoreq r6, r10, r4, asr #1
 *   @0x147c6c eoreq r5, r10, r12, asr #21
 *   @0x147c70 mulseq pc, r8, r1
 *
 * ══ §116/168 F_GPUGetColourWriteEnable(RValue&, CInstance*, CInstance*, int, RValue*)  0x148310  size 176  42 条（0x148310..0x1483c0）
 * @func 0x148310 0x1483c0  size 176  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RenderStateManager::GetRenderState(eRenderState) / CreateArray(RValue*, int, ...)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x7c×1 / 0x18×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x148310 cmp r3, #0
 *   @0x148314 mov r1, #0
 *   @0x148318 push {r4, lr}
 *   @0x14831c mov r4, r0
 *   @0x148320 sub sp, sp, #24
 *   @0x148324 str r1, [r0, #0xc]
 *   @0x148328 str r1, [r0]
 *   @0x14832c str r1, [r0, #0x4]
 *   @0x148330 bne 0x14839c <_Z25F_GPUGetColourWriteEnableR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x148334 ldr r0, [pc, #0x7c]
 *   @0x148338 mov r1, #24
 *   @0x14833c ldr r0, [pc, r0]
 *   @0x148340 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState>
 *   @0x148344 vmov.f64 d7, #1.000000e+00
 *   @0x148348 vldr d6, [pc, #96]
 *   @0x14834c mov r1, #4
 *   @0x148350 tst r0, #1
 *   @0x148354 mov r12, r0
 *   @0x148358 mov r0, r4
 *   @0x14835c vmovne r2, r3, d7
 *   @0x148360 vmoveq r2, r3, d6
 *   @0x148364 tst r12, #2
 *   @0x148368 vmovne.f64 d5, d7
 *   @0x14836c vmoveq.f64 d5, d6
 *   @0x148370 tst r12, #4
 *   @0x148374 vstr d5, [sp]
 *   @0x148378 vmovne.f64 d5, d7
 *   @0x14837c vmoveq.f64 d5, d6
 *   @0x148380 tst r12, #8
 *   @0x148384 vstr d5, [sp, #8]
 *   @0x148388 vmoveq.f64 d7, d6
 *   @0x14838c vstr d7, [sp, #16]
 *   @0x148390 bl 0x120eb4 <_Z11CreateArrayP6RValueiz>
 *   @0x148394 add sp, sp, #24
 *   @0x148398 pop {r4, pc}
 *   @0x14839c ldr r0, [pc, #0x18]
 *   @0x1483a0 add r0, pc, r0
 *   @0x1483a4 add sp, sp, #24
 *   @0x1483a8 pop {r4, lr}
 *   @0x1483ac b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1483b8 .word 0x002a59bc
 *   @0x1483bc ldrheq r9, [pc], -r12
 *
 * ══ §117/168 F_PhysicsDrawParticles(RValue&, CInstance*, CInstance*, int, RValue*)  0x14dc68  size 176  44 条（0x14dc68..0x14dd18）
 * @func 0x14dc68 0x14dd18  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / Sprite_Data(int) / YYGetUint32(RValue const*, int)
 * 字段偏移 top8: 0x18×2 / 0xb4×2 / 0x9c×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14dc68 push {r4, r5, r6, r7, r8, lr}
 *   @0x14dc6c ldr r4, [pc, #0x9c]
 *   @0x14dc70 ldr r5, [sp, #0x18]
 *   @0x14dc74 ldr r4, [pc, r4]
 *   @0x14dc78 ldr r3, [r4]
 *   @0x14dc7c cmp r3, #0
 *   @0x14dc80 beq 0x14dcf8 <_Z22F_PhysicsDrawParticlesR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x14dc84 ldr r3, [r3, #0xb4]
 *   @0x14dc88 cmp r3, #0
 *   @0x14dc8c beq 0x14dcf8 <_Z22F_PhysicsDrawParticlesR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x14dc90 mov r1, #2
 *   @0x14dc94 mov r0, r5
 *   @0x14dc98 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14dc9c bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x14dca0 subs r6, r0, #0
 *   @0x14dca4 beq 0x14dd0c <_Z22F_PhysicsDrawParticlesR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x14dca8 ldr r3, [r4]
 *   @0x14dcac mov r0, r5
 *   @0x14dcb0 mov r1, #0
 *   @0x14dcb4 ldr r4, [r3, #0xb4]
 *   @0x14dcb8 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x14dcbc mov r1, #1
 *   @0x14dcc0 mov r8, r0
 *   @0x14dcc4 mov r0, r5
 *   @0x14dcc8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14dccc mov r1, #3
 *   @0x14dcd0 mov r7, r0
 *   @0x14dcd4 mov r0, r5
 *   @0x14dcd8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14dcdc mov r1, r8
 *   @0x14dce0 mov r2, r7
 *   @0x14dce4 mov r3, r6
 *   @0x14dce8 str r0, [sp, #0x18]
 *   @0x14dcec mov r0, r4
 *   @0x14dcf0 pop {r4, r5, r6, r7, r8, lr}
 *   @0x14dcf4 b 0x23a8c0 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei>
 *   @0x14dcf8 ldr r0, [pc, #0x14]
 *   @0x14dcfc mov r1, #0
 *   @0x14dd00 pop {r4, r5, r6, r7, r8, lr}
 *   @0x14dd04 add r0, pc, r0
 *   @0x14dd08 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14dd0c pop {r4, r5, r6, r7, r8, pc}
 *   @0x14dd10 .word 0x0029fcb4
 *   @0x14dd14 andseq r6, pc, r12, lsr #15
 *
 * ══ §118/168 F_PhysicsParticleData(RValue&, CInstance*, CInstance*, int, RValue*)  0x14ded4  size 176  44 条（0x14ded4..0x14df84）
 * @func 0x14ded4 0x14df84  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / GetIBuffer(int) / YYGetUint32(RValue const*, int)
 * 字段偏移 top8: 0xb4×2 / 0x94×1 / 0xc×1 / 0x4×1 / 0x10×1 / 0x24×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14ded4 push {r4, r5, r6, lr}
 *   @0x14ded8 mov r1, #0
 *   @0x14dedc ldr r4, [pc, #0x94]
 *   @0x14dee0 mov r3, r1
 *   @0x14dee4 str r1, [r0]
 *   @0x14dee8 movt r3, #0xbff0
 *   @0x14deec ldr r4, [pc, r4]
 *   @0x14def0 str r1, [r0, #0xc]
 *   @0x14def4 str r3, [r0, #0x4]
 *   @0x14def8 ldr r2, [r4]
 *   @0x14defc ldr r5, [sp, #0x10]
 *   @0x14df00 cmp r2, r1
 *   @0x14df04 beq 0x14df50 <_Z21F_PhysicsParticleDataR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x14df08 ldr r3, [r2, #0xb4]
 *   @0x14df0c cmp r3, r1
 *   @0x14df10 beq 0x14df50 <_Z21F_PhysicsParticleDataR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x14df14 mov r0, r5
 *   @0x14df18 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14df1c bl 0xc6720 <_Z10GetIBufferi>
 *   @0x14df20 subs r6, r0, #0
 *   @0x14df24 beq 0x14df64 <_Z21F_PhysicsParticleDataR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x14df28 ldr r3, [r4]
 *   @0x14df2c mov r0, r5
 *   @0x14df30 mov r1, #1
 *   @0x14df34 ldr r4, [r3, #0xb4]
 *   @0x14df38 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x14df3c mov r1, r6
 *   @0x14df40 mov r2, r0
 *   @0x14df44 mov r0, r4
 *   @0x14df48 pop {r4, r5, r6, lr}
 *   @0x14df4c b 0x23a57c <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferj>
 *   @0x14df50 ldr r0, [pc, #0x24]
 *   @0x14df54 mov r1, #0
 *   @0x14df58 pop {r4, r5, r6, lr}
 *   @0x14df5c add r0, pc, r0
 *   @0x14df60 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14df64 ldr r0, [pc, #0x14]
 *   @0x14df68 mov r1, r6
 *   @0x14df6c pop {r4, r5, r6, lr}
 *   @0x14df70 add r0, pc, r0
 *   @0x14df74 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14df78 eoreq pc, r9, r12, lsr r10
 *   @0x14df7c andseq r6, pc, r4, lsl #12
 *   @0x14df80 andseq r2, lr, r4, asr #24
 *
 * ══ §119/168 F_GamepadSetColour(RValue&, CInstance*, CInstance*, int, RValue*)  0x15179c  size 176  44 条（0x15179c..0x15184c）
 * @func 0x15179c 0x15184c  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / anon_15149c
 * 字段偏移 top8: 0xc×2 / 0x4c×2 / 0x10×1 / 0x4×1 / 0x68×1 / 0x24×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15179c push {r3, r4, r5, lr}
 *   @0x1517a0 mov r4, #0
 *   @0x1517a4 ldr r5, [sp, #0x10]
 *   @0x1517a8 str r4, [r0, #0xc]
 *   @0x1517ac str r4, [r0]
 *   @0x1517b0 str r4, [r0, #0x4]
 *   @0x1517b4 bl 0x15149c <_Z20F_GamepadButtonCountR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x1517b8 mov r1, r4
 *   @0x1517bc mov r0, r5
 *   @0x1517c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1517c4 subs r4, r0, #0
 *   @0x1517c8 poplt {r3, r4, r5, pc}
 *   @0x1517cc ldr r3, [pc, #0x68]
 *   @0x1517d0 ldr r3, [pc, r3]
 *   @0x1517d4 ldr r3, [r3]
 *   @0x1517d8 cmp r4, r3
 *   @0x1517dc popge {r3, r4, r5, pc}
 *   @0x1517e0 mov r0, r5
 *   @0x1517e4 mov r1, #1
 *   @0x1517e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1517ec ldr r3, [pc, #0x4c]
 *   @0x1517f0 ldr r1, [pc, #0x4c]
 *   @0x1517f4 ldr r3, [pc, r3]
 *   @0x1517f8 add r1, pc, r1
 *   @0x1517fc ldr r3, [r3]
 *   @0x151800 ldr r2, [r3]
 *   @0x151804 ldr r12, [r2, #0xc]
 *   @0x151808 bic r5, r0, #-16777216
 *   @0x15180c mov r0, r3
 *   @0x151810 orr r5, r5, #16777216
 *   @0x151814 mov r2, r5
 *   @0x151818 blx r12
 *   @0x15181c ldr r3, [pc, #0x24]
 *   @0x151820 mov r2, r5
 *   @0x151824 mov r1, r4
 *   @0x151828 ldr r3, [pc, r3]
 *   @0x15182c ldr r3, [r3]
 *   @0x151830 ldr r0, [r3, r4, lsl #2]
 *   @0x151834 pop {r3, r4, r5, lr}
 *   @0x151838 b 0x18ed84 <_ZN9GMGamePad9SetColourEij>
 *   @0x15183c mlaeq r9, r0, r2, lr
 *   @0x151840 eoreq r11, r9, r0, lsr #30
 *   @0x151844 andseq r4, pc, r12, asr r3
 *   @0x151848 eoreq lr, r9, r12, lsr r2
 *
 * ══ §120/168 F_YoYo_PostAchievement(RValue&, CInstance*, CInstance*, int, RValue*)  0x1590f4  size 176  44 条（0x1590f4..0x1591a4）
 * @func 0x1590f4 0x1591b8  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Error_Show_Action(char const*, bool)×2 / YYGetFloat(RValue const*, int) / YYGetString(RValue const*, int) / YoYo_CacheAchievement(char const*, unsigned int*)
 * 字段偏移 top8: 0xc×2 / 0x18×1 / 0x4×1 / 0x1c×1 / 0x60×1 / 0x-4×1 / 0x28×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1590f4 push {r4, r5, r6, lr}
 *   @0x1590f8 cmp r3, #2
 *   @0x1590fc sub sp, sp, #8
 *   @0x159100 mov r1, #0
 *   @0x159104 str r1, [r0, #0xc]
 *   @0x159108 ldr r4, [sp, #0x18]
 *   @0x15910c str r1, [r0]
 *   @0x159110 str r1, [r0, #0x4]
 *   @0x159114 bne 0x159184 <_Z22F_YoYo_PostAchievementR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x159118 ldr r1, [r4, #0xc]
 *   @0x15911c cmp r1, #1
 *   @0x159120 bne 0x15916c <_Z22F_YoYo_PostAchievementR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x159124 ldr r5, [r4, #0x1c]
 *   @0x159128 cmp r5, #0
 *   @0x15912c bne 0x15916c <_Z22F_YoYo_PostAchievementR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x159130 ldr r2, [pc, #0x60]
 *   @0x159134 ldr r2, [pc, r2]
 *   @0x159138 ldrb r2, [r2]
 *   @0x15913c cmp r2, #0
 *   @0x159140 beq 0x15917c <_Z22F_YoYo_PostAchievementR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x159144 mov r0, r4
 *   @0x159148 add r6, sp, #8
 *   @0x15914c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x159150 mov r1, r5
 *   @0x159154 str r0, [r6, #-0x4]!
 *   @0x159158 mov r0, r4
 *   @0x15915c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x159160 mov r1, r6
 *   @0x159164 bl 0x16163c <_Z21YoYo_CacheAchievementPKcPj>
 *   @0x159168 b 0x15917c <_Z22F_YoYo_PostAchievementR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x15916c ldr r0, [pc, #0x28]
 *   @0x159170 mov r1, #0
 *   @0x159174 add r0, pc, r0
 *   @0x159178 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x15917c add sp, sp, #8
 *   @0x159180 pop {r4, r5, r6, pc}
 *   @0x159184 ldr r0, [pc, #0x14]
 *   @0x159188 add r0, pc, r0
 *   @0x15918c bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x159190 add sp, sp, #8
 *   @0x159194 pop {r4, r5, r6, pc}
 *   @0x159198 .word 0x002969fc
 *   @0x15919c andseq r9, lr, r8, lsr r8
 *   @0x1591a0 andseq sp, lr, r0, asr #8
 *
 * ══ §121/168 F_YoYo_IncrementAchievement(RValue&, CInstance*, CInstance*, int, RValue*)  0x1591a4  size 176  44 条（0x1591a4..0x159254）
 * @func 0x1591a4 0x159268  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Error_Show_Action(char const*, bool)×2 / YYGetFloat(RValue const*, int) / YYGetString(RValue const*, int) / YoYo_IncrementAchievement(char const*, unsigned int*)
 * 字段偏移 top8: 0xc×2 / 0x18×1 / 0x4×1 / 0x1c×1 / 0x60×1 / 0x-4×1 / 0x28×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1591a4 push {r4, r5, r6, lr}
 *   @0x1591a8 cmp r3, #2
 *   @0x1591ac sub sp, sp, #8
 *   @0x1591b0 mov r1, #0
 *   @0x1591b4 str r1, [r0, #0xc]
 *   @0x1591b8 ldr r4, [sp, #0x18]
 *   @0x1591bc str r1, [r0]
 *   @0x1591c0 str r1, [r0, #0x4]
 *   @0x1591c4 bne 0x159234 <_Z27F_YoYo_IncrementAchievementR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x1591c8 ldr r1, [r4, #0xc]
 *   @0x1591cc cmp r1, #1
 *   @0x1591d0 bne 0x15921c <_Z27F_YoYo_IncrementAchievementR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x1591d4 ldr r5, [r4, #0x1c]
 *   @0x1591d8 cmp r5, #0
 *   @0x1591dc bne 0x15921c <_Z27F_YoYo_IncrementAchievementR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x1591e0 ldr r2, [pc, #0x60]
 *   @0x1591e4 ldr r2, [pc, r2]
 *   @0x1591e8 ldrb r2, [r2]
 *   @0x1591ec cmp r2, #0
 *   @0x1591f0 beq 0x15922c <_Z27F_YoYo_IncrementAchievementR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x1591f4 mov r0, r4
 *   @0x1591f8 add r6, sp, #8
 *   @0x1591fc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x159200 mov r1, r5
 *   @0x159204 str r0, [r6, #-0x4]!
 *   @0x159208 mov r0, r4
 *   @0x15920c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x159210 mov r1, r6
 *   @0x159214 bl 0x1615f0 <_Z25YoYo_IncrementAchievementPKcPj>
 *   @0x159218 b 0x15922c <_Z27F_YoYo_IncrementAchievementR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x15921c ldr r0, [pc, #0x28]
 *   @0x159220 mov r1, #0
 *   @0x159224 add r0, pc, r0
 *   @0x159228 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x15922c add sp, sp, #8
 *   @0x159230 pop {r4, r5, r6, pc}
 *   @0x159234 ldr r0, [pc, #0x14]
 *   @0x159238 add r0, pc, r0
 *   @0x15923c bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x159240 add sp, sp, #8
 *   @0x159244 pop {r4, r5, r6, pc}
 *   @0x159248 eoreq r6, r9, r12, asr #18
 *   @0x15924c andseq r9, lr, r8, lsl #15
 *   @0x159250 mulseq lr, r0, r3
 *
 * ══ §122/168 F_YoYo_PostScore(RValue&, CInstance*, CInstance*, int, RValue*)  0x159254  size 176  44 条（0x159254..0x159304）
 * @func 0x159254 0x159304  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Error_Show_Action(char const*, bool)×2 / YYGetInt32(RValue const*, int) / YYGetString(RValue const*, int) / YoYo_ScoreAchievement(char const*, unsigned int*)
 * 字段偏移 top8: 0xc×2 / 0x18×1 / 0x4×1 / 0x1c×1 / 0x60×1 / 0x-4×1 / 0x28×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x159254 push {r4, r5, r6, lr}
 *   @0x159258 cmp r3, #2
 *   @0x15925c sub sp, sp, #8
 *   @0x159260 mov r1, #0
 *   @0x159264 str r1, [r0, #0xc]
 *   @0x159268 ldr r4, [sp, #0x18]
 *   @0x15926c str r1, [r0]
 *   @0x159270 str r1, [r0, #0x4]
 *   @0x159274 bne 0x1592e4 <_Z16F_YoYo_PostScoreR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x159278 ldr r1, [r4, #0xc]
 *   @0x15927c cmp r1, #1
 *   @0x159280 bne 0x1592cc <_Z16F_YoYo_PostScoreR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x159284 ldr r5, [r4, #0x1c]
 *   @0x159288 cmp r5, #0
 *   @0x15928c bne 0x1592cc <_Z16F_YoYo_PostScoreR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x159290 ldr r2, [pc, #0x60]
 *   @0x159294 ldr r2, [pc, r2]
 *   @0x159298 ldrb r2, [r2]
 *   @0x15929c cmp r2, #0
 *   @0x1592a0 beq 0x1592dc <_Z16F_YoYo_PostScoreR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x1592a4 mov r0, r4
 *   @0x1592a8 add r6, sp, #8
 *   @0x1592ac bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1592b0 mov r1, r5
 *   @0x1592b4 str r0, [r6, #-0x4]!
 *   @0x1592b8 mov r0, r4
 *   @0x1592bc bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1592c0 mov r1, r6
 *   @0x1592c4 bl 0x161688 <_Z21YoYo_ScoreAchievementPKcPj>
 *   @0x1592c8 b 0x1592dc <_Z16F_YoYo_PostScoreR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x1592cc ldr r0, [pc, #0x28]
 *   @0x1592d0 mov r1, #0
 *   @0x1592d4 add r0, pc, r0
 *   @0x1592d8 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1592dc add sp, sp, #8
 *   @0x1592e0 pop {r4, r5, r6, pc}
 *   @0x1592e4 ldr r0, [pc, #0x14]
 *   @0x1592e8 add r0, pc, r0
 *   @0x1592ec bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1592f0 add sp, sp, #8
 *   @0x1592f4 pop {r4, r5, r6, pc}
 *   @0x1592f8 mlaeq r9, r12, r8, r6
 *   @0x1592fc ldrsbeq r9, [lr], -r8
 *   @0x159300 andseq sp, lr, r0, ror #5
 *
 * ══ §123/168 UpdateOSEvents()  0x159ddc  size 176  44 条（0x159ddc..0x159e8c）
 * @func 0x159ddc 0x159e8c  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x159de4→0x484aac, 0x159dfc→0x484aad, 0x159e10→0x3eb70c, 0x159e38→0x3eb70c, 0x159e58→0x484aad
 * 调用序列: 无
 * 字段偏移 top8: 0x8c×2 / 0x68×2 / 0xc×2 / 0x78×1 / 0x40×1 / 0x44×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x159ddc push {r4, r5, r6, lr}
 *   @0x159de0 ldr r4, [pc, #0x8c]
 *   @0x159de4 ldr r3, [pc, #0x8c]
 *   @0x159de8 add r4, pc, r4
 *   @0x159dec ldr r6, [r4, r3]
 *   @0x159df0 ldrb r5, [r6]
 *   @0x159df4 cmp r5, #0
 *   @0x159df8 bne 0x159e38 <_Z14UpdateOSEventsv+0x5c>
 *   @0x159dfc ldr r3, [pc, #0x78]
 *   @0x159e00 ldr r6, [r4, r3]
 *   @0x159e04 ldrb r3, [r6]
 *   @0x159e08 cmp r3, #0
 *   @0x159e0c popeq {r4, r5, r6, pc}
 *   @0x159e10 ldr r3, [pc, #0x68]
 *   @0x159e14 ldr r1, [pc, #0x68]
 *   @0x159e18 ldr r3, [r4, r3]
 *   @0x159e1c add r1, pc, r1
 *   @0x159e20 ldr r0, [r3]
 *   @0x159e24 ldr r3, [r0]
 *   @0x159e28 ldr r3, [r3, #0xc]
 *   @0x159e2c blx r3
 *   @0x159e30 strb r5, [r6]
 *   @0x159e34 pop {r4, r5, r6, pc}
 *   @0x159e38 ldr r3, [pc, #0x40]
 *   @0x159e3c ldr r1, [pc, #0x44]
 *   @0x159e40 ldr r3, [r4, r3]
 *   @0x159e44 add r1, pc, r1
 *   @0x159e48 ldr r0, [r3]
 *   @0x159e4c ldr r3, [r0]
 *   @0x159e50 ldr r3, [r3, #0xc]
 *   @0x159e54 blx r3
 *   @0x159e58 ldr r3, [pc, #0x1c]
 *   @0x159e5c mov r2, #1
 *   @0x159e60 mov r1, #0
 *   @0x159e64 ldr r3, [r4, r3]
 *   @0x159e68 strb r1, [r6]
 *   @0x159e6c strb r2, [r3]
 *   @0x159e70 pop {r4, r5, r6, pc}
 *   @0x159e74 eoreq r7, r9, r8, ror #28
 *   @0x159e78 .word 0xffffdf98
 *   @0x159e7c .word 0xffffdef4
 *   @0x159e80 .word 0xffffbac4
 *   @0x159e84 andseq r12, lr, r4, ror #25
 *   @0x159e88 andseq r12, lr, r12, lsl #25
 *
 * ══ §124/168 Push_SendLocalNotification(double, char const*, char const*, char const*)  0x161b4c  size 176  44 条（0x161b4c..0x161bfc）
 * @func 0x161b4c 0x161bfc  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×4 / _JNIEnv::CallStaticVoidMethod(_jclass*, _jmethodID*, ...)
 * 字段偏移 top8: 0x29c×3 / 0x34×2 / 0x38×1 / 0x8×1 / 0xc×1 / 0x10×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161b4c push {r4, r5, r6, r7, lr}
 *   @0x161b50 vpush {d8}
 *   @0x161b54 sub sp, sp, #28
 *   @0x161b58 mov r5, r2
 *   @0x161b5c mov r7, r3
 *   @0x161b60 vmov d8, r0, r1
 *   @0x161b64 ldr r4, [sp, #0x38]
 *   @0x161b68 bl 0x290274 <getJNIEnv>
 *   @0x161b6c mov r1, r5
 *   @0x161b70 ldr r3, [r0]
 *   @0x161b74 ldr r3, [r3, #0x29c]
 *   @0x161b78 blx r3
 *   @0x161b7c mov r6, r0
 *   @0x161b80 bl 0x290274 <getJNIEnv>
 *   @0x161b84 mov r1, r7
 *   @0x161b88 ldr r3, [r0]
 *   @0x161b8c ldr r3, [r3, #0x29c]
 *   @0x161b90 blx r3
 *   @0x161b94 mov r5, r0
 *   @0x161b98 bl 0x290274 <getJNIEnv>
 *   @0x161b9c mov r1, r4
 *   @0x161ba0 ldr r3, [r0]
 *   @0x161ba4 ldr r3, [r3, #0x29c]
 *   @0x161ba8 blx r3
 *   @0x161bac mov r4, r0
 *   @0x161bb0 bl 0x290274 <getJNIEnv>
 *   @0x161bb4 vcvt.f32.f64 s16, d8
 *   @0x161bb8 ldr r2, [pc, #0x34]
 *   @0x161bbc ldr r3, [pc, #0x34]
 *   @0x161bc0 ldr r2, [pc, r2]
 *   @0x161bc4 ldr r3, [pc, r3]
 *   @0x161bc8 ldr r1, [r2]
 *   @0x161bcc ldr r2, [r3]
 *   @0x161bd0 str r6, [sp, #0x8]
 *   @0x161bd4 vcvt.f64.f32 d8, s16
 *   @0x161bd8 str r5, [sp, #0xc]
 *   @0x161bdc str r4, [sp, #0x10]
 *   @0x161be0 vstr d8, [sp]
 *   @0x161be4 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x161be8 add sp, sp, #28
 *   @0x161bec vpop {d8}
 *   @0x161bf0 pop {r4, r5, r6, r7, pc}
 *   @0x161bf4 eoreq r11, r8, r4, ror #27
 *   @0x161bf8 .word 0x0028e3b0
 *
 * ══ §125/168 GR_Texture_Create_Bitmap(IBitmap*, bool, bool)  0x173ed4  size 176  44 条（0x173ed4..0x173f84）
 * @func 0x173ed4 0x173f84  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CBitmap32::GetWidth()×2 / CBitmap32::GetHeight()×2 / operator new(unsigned int) / CBitmap32::CBitmap32(IBitmap*, bool, bool) / CBitmap32::GetData() / GR_Texture_Create_And_Fill(int, int, unsigned char*, unsigned int)
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x173ed4 push {r4, r5, r6, r7, r8, lr}
 *   @0x173ed8 subs r7, r0, #0
 *   @0x173edc mov r6, r1
 *   @0x173ee0 mov r5, r2
 *   @0x173ee4 beq 0x173f7c <_Z24GR_Texture_Create_BitmapP7IBitmapbb+0xa8>
 *   @0x173ee8 mov r0, #24
 *   @0x173eec bl 0x27c524 <_Znwj>
 *   @0x173ef0 mov r1, r7
 *   @0x173ef4 mov r2, r6
 *   @0x173ef8 mov r3, r5
 *   @0x173efc mov r4, r0
 *   @0x173f00 bl 0x166e70 <_ZN9CBitmap32C2EP7IBitmapbb>
 *   @0x173f04 mov r0, r4
 *   @0x173f08 bl 0x167960 <_ZN9CBitmap328GetWidthEv>
 *   @0x173f0c mov r5, r0
 *   @0x173f10 mov r0, r4
 *   @0x173f14 bl 0x167968 <_ZN9CBitmap329GetHeightEv>
 *   @0x173f18 mov r8, r0
 *   @0x173f1c mov r0, r4
 *   @0x173f20 bl 0x167970 <_ZN9CBitmap327GetDataEv>
 *   @0x173f24 mov r7, r0
 *   @0x173f28 mov r0, r4
 *   @0x173f2c bl 0x167960 <_ZN9CBitmap328GetWidthEv>
 *   @0x173f30 mov r6, r0
 *   @0x173f34 mov r0, r4
 *   @0x173f38 bl 0x167968 <_ZN9CBitmap329GetHeightEv>
 *   @0x173f3c mov r1, r8
 *   @0x173f40 mov r2, r7
 *   @0x173f44 mul r3, r0, r6
 *   @0x173f48 mov r0, r5
 *   @0x173f4c lsl r3, r3, #2
 *   @0x173f50 bl 0x173c18 <_Z26GR_Texture_Create_And_FilliiPhj>
 *   @0x173f54 cmp r4, #0
 *   @0x173f58 mov r5, r0
 *   @0x173f5c beq 0x173f78 <_Z24GR_Texture_Create_BitmapP7IBitmapbb+0xa4>
 *   @0x173f60 ldr r3, [r4]
 *   @0x173f64 mov r0, r4
 *   @0x173f68 ldr r3, [r3, #0x4]
 *   @0x173f6c blx r3
 *   @0x173f70 mov r0, r5
 *   @0x173f74 pop {r4, r5, r6, r7, r8, pc}
 *   @0x173f78 pop {r4, r5, r6, r7, r8, pc}
 *   @0x173f7c mvn r0, #0
 *   @0x173f80 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §126/168 InitVertexBuilderResources()  0x183c80  size 176  44 条（0x183c80..0x183d30）
 * @func 0x183c80 0x183d30  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x183c90→0x3f30c8, 0x183c98→0x3f4a88, 0x183cb0→0x3f2e34, 0x183cb4→0x3f489c, 0x183ccc→0x3f2b5c, 0x183cd0→0x3f46b0, 0x183ce8→0x3f2938, 0x183cec→0x3f456c
 * 调用序列: InitShaderVariations(int*, char*, char*, bool)×3
 * 字段偏移 top8: 0x78×3 / 0x60×2 / 0x4c×2 / 0x38×2 / 0x74×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x183c80 push {r4, r5, r6, lr}
 *   @0x183c84 mov r3, #0
 *   @0x183c88 ldr r4, [pc, #0x78]
 *   @0x183c8c ldr r5, [pc, #0x78]
 *   @0x183c90 ldr r1, [pc, #0x78]
 *   @0x183c94 add r4, pc, r4
 *   @0x183c98 ldr r2, [pc, #0x74]
 *   @0x183c9c add r5, pc, r5
 *   @0x183ca0 ldr r1, [r4, r1]
 *   @0x183ca4 mov r0, r5
 *   @0x183ca8 ldr r2, [r4, r2]
 *   @0x183cac bl 0x183b70 <_Z20InitShaderVariationsPiPcS0_b>
 *   @0x183cb0 ldr r1, [pc, #0x60]
 *   @0x183cb4 ldr r2, [pc, #0x60]
 *   @0x183cb8 add r0, r5, #16
 *   @0x183cbc mov r3, #0
 *   @0x183cc0 ldr r1, [r4, r1]
 *   @0x183cc4 ldr r2, [r4, r2]
 *   @0x183cc8 bl 0x183b70 <_Z20InitShaderVariationsPiPcS0_b>
 *   @0x183ccc ldr r1, [pc, #0x4c]
 *   @0x183cd0 ldr r2, [pc, #0x4c]
 *   @0x183cd4 add r0, r5, #32
 *   @0x183cd8 mov r3, #1
 *   @0x183cdc ldr r1, [r4, r1]
 *   @0x183ce0 ldr r2, [r4, r2]
 *   @0x183ce4 bl 0x183b70 <_Z20InitShaderVariationsPiPcS0_b>
 *   @0x183ce8 ldr r1, [pc, #0x38]
 *   @0x183cec ldr r2, [pc, #0x38]
 *   @0x183cf0 add r0, r5, #96
 *   @0x183cf4 mov r3, #0
 *   @0x183cf8 ldr r1, [r4, r1]
 *   @0x183cfc ldr r2, [r4, r2]
 *   @0x183d00 pop {r4, r5, r6, lr}
 *   @0x183d04 b 0x183b70 <_Z20InitShaderVariationsPiPcS0_b>
 *   @0x183d08 .word 0x0026dfbc
 *   @0x183d0c eoreq lr, r6, r12, lsl #24
 *   @0x183d10 .word 0xffffe920
 *   @0x183d14 .word 0xffffe924
 *   @0x183d18 .word 0xffffe928
 *   @0x183d1c .word 0xffffe92c
 *   @0x183d20 .word 0xffffe930
 *   @0x183d24 .word 0xffffe934
 *   @0x183d28 .word 0xffffe938
 *   @0x183d2c .word 0xffffe93c
 *
 * ══ §127/168 Shader_Reload_All()  0x187fac  size 176  44 条（0x187fac..0x18805c）
 * @func 0x187fac 0x18805c  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Shader_Reload_All()+0x64 / Shader_Reload(int) / Shader_Get(int)
 * 字段偏移 top8: 0x8×2 / 0x98×1 / 0x4×1 / 0x2×1 / 0x3c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x187fac push {r3, r4, r5, lr}
 *   @0x187fb0 ldr r5, [pc, #0x98]
 *   @0x187fb4 ldr r5, [pc, r5]
 *   @0x187fb8 ldr r3, [r5]
 *   @0x187fbc cmp r3, #0
 *   @0x187fc0 movgt r4, #0
 *   @0x187fc4 bgt 0x187fdc <_Z17Shader_Reload_Allv+0x30>
 *   @0x187fc8 b 0x188010 <_Z17Shader_Reload_Allv+0x64>
 *   @0x187fcc ldr r3, [r5]
 *   @0x187fd0 add r4, r4, #1
 *   @0x187fd4 cmp r3, r4
 *   @0x187fd8 ble 0x188010 <_Z17Shader_Reload_Allv+0x64>
 *   @0x187fdc ldr r3, [r5, #0x4]
 *   @0x187fe0 ldr r3, [r3, r4, lsl #2]
 *   @0x187fe4 cmp r3, #0
 *   @0x187fe8 beq 0x187fcc <_Z17Shader_Reload_Allv+0x20>
 *   @0x187fec ldr r3, [r3, #0x8]
 *   @0x187ff0 cmn r3, #1
 *   @0x187ff4 bne 0x187fcc <_Z17Shader_Reload_Allv+0x20>
 *   @0x187ff8 mov r0, r4
 *   @0x187ffc add r4, r4, #1
 *   @0x188000 bl 0x187ea4 <_Z13Shader_Reloadi>
 *   @0x188004 ldr r3, [r5]
 *   @0x188008 cmp r3, r4
 *   @0x18800c bgt 0x187fdc <_Z17Shader_Reload_Allv+0x30>
 *   @0x188010 ldr r4, [pc, #0x3c]
 *   @0x188014 ldr r4, [pc, r4]
 *   @0x188018 ldr r0, [r4]
 *   @0x18801c cmn r0, #1
 *   @0x188020 popeq {r3, r4, r5, pc}
 *   @0x188024 bl 0x187e70 <_Z10Shader_Geti>
 *   @0x188028 cmp r0, #0
 *   @0x18802c mvneq r3, #0
 *   @0x188030 streq r3, [r4]
 *   @0x188034 popeq {r3, r4, r5, pc}
 *   @0x188038 ldr r3, [pc, #0x18]
 *   @0x18803c ldr r0, [r0, #0x8]
 *   @0x188040 ldr r3, [pc, r3]
 *   @0x188044 ldr r3, [r3]
 *   @0x188048 blx r3
 *   @0x18804c pop {r3, r4, r5, pc}
 *   @0x188050 eoreq r8, r6, r4, lsl #12
 *   @0x188054 eoreq r8, r6, r12, ror r5
 *   @0x188058 mlaeq r6, r0, r7, r5
 *
 * ══ §128/168 Shader_Get_Uniform_Handle(Shader*, char const*)  0x1883b8  size 176  44 条（0x1883b8..0x188468）
 * @func 0x1883b8 0x188468  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Shader_Get(int) / Shader_Get_Uniform_Handle(Shader*, char const*)+0x90
 * 字段偏移 top8: 0x78×2 / 0x4×2 / 0x98×1 / 0x64×1 / 0x6c×1 / 0x8×1 / 0x7c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1883b8 push {r3, r4, r5, lr}
 *   @0x1883bc mov r5, r1
 *   @0x1883c0 ldr r3, [pc, #0x98]
 *   @0x1883c4 ldr r3, [pc, r3]
 *   @0x1883c8 ldr r3, [r3]
 *   @0x1883cc cmp r3, #1
 *   @0x1883d0 bne 0x188448 <_Z25Shader_Get_Uniform_HandleP6ShaderPKc+0x90>
 *   @0x1883d4 ldr r0, [r0, #0x64]
 *   @0x1883d8 bl 0x187e70 <_Z10Shader_Geti>
 *   @0x1883dc subs r4, r0, #0
 *   @0x1883e0 beq 0x188448 <_Z25Shader_Get_Uniform_HandleP6ShaderPKc+0x90>
 *   @0x1883e4 ldr r3, [r4, #0x78]
 *   @0x1883e8 cmp r3, #0
 *   @0x1883ec beq 0x188448 <_Z25Shader_Get_Uniform_HandleP6ShaderPKc+0x90>
 *   @0x1883f0 ldr r3, [pc, #0x6c]
 *   @0x1883f4 mov r1, r5
 *   @0x1883f8 ldr r0, [r4, #0x8]
 *   @0x1883fc ldr r3, [pc, r3]
 *   @0x188400 ldr r3, [r3]
 *   @0x188404 blx r3
 *   @0x188408 ldr r12, [r4, #0x7c]
 *   @0x18840c cmp r12, #0
 *   @0x188410 ble 0x188448 <_Z25Shader_Get_Uniform_HandleP6ShaderPKc+0x90>
 *   @0x188414 ldr r2, [r4, #0x78]
 *   @0x188418 ldr r3, [r2, #0x4]
 *   @0x18841c cmp r3, r0
 *   @0x188420 beq 0x188458 <_Z25Shader_Get_Uniform_HandleP6ShaderPKc+0xa0>
 *   @0x188424 mov r3, #0
 *   @0x188428 b 0x188438 <_Z25Shader_Get_Uniform_HandleP6ShaderPKc+0x80>
 *   @0x18842c ldr r1, [r2, #0x4]
 *   @0x188430 cmp r1, r0
 *   @0x188434 beq 0x188450 <_Z25Shader_Get_Uniform_HandleP6ShaderPKc+0x98>
 *   @0x188438 add r3, r3, #1
 *   @0x18843c add r2, r2, #28
 *   @0x188440 cmp r3, r12
 *   @0x188444 bne 0x18842c <_Z25Shader_Get_Uniform_HandleP6ShaderPKc+0x74>
 *   @0x188448 mvn r0, #0
 *   @0x18844c pop {r3, r4, r5, pc}
 *   @0x188450 mov r0, r3
 *   @0x188454 pop {r3, r4, r5, pc}
 *   @0x188458 mov r0, #0
 *   @0x18845c pop {r3, r4, r5, pc}
 *   @0x188460 eoreq r8, r6, r4, asr #32
 *   @0x188464 eoreq r5, r6, r4, lsl r4
 *
 * ══ §129/168 CPath::LoadFromChunk(YYPath*, unsigned char*)  0x1a7120  size 176  44 条（0x1a7120..0x1a71d0）
 * @func 0x1a7120 0x1a71d0  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::SetLength(void**, unsigned int, char const*, int) / CPath::LoadFromChunk(YYPath*, unsigned char*)+0x9c / CPath::ComputeInternal()
 * 字段偏移 top8: 0x10×3 / 0x4×2 / 0xc×2 / 0x8×1 / 0x78×1 / 0x14×1 / 0x1c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a7120 ldr r2, [r1, #0x10]
 *   @0x1a7124 mov r3, #460
 *   @0x1a7128 ldr r12, [r1, #0x8]
 *   @0x1a712c push {r4, r5, r6, lr}
 *   @0x1a7130 mov r5, r0
 *   @0x1a7134 ldr r4, [r1, #0x4]
 *   @0x1a7138 adds r12, r12, #0
 *   @0x1a713c ldr lr, [r1, #0xc]
 *   @0x1a7140 mov r6, r1
 *   @0x1a7144 str r2, [r5, #0x10]
 *   @0x1a7148 add r1, r2, r2, lsl #1
 *   @0x1a714c ldr r2, [pc, #0x78]
 *   @0x1a7150 movne r12, #1
 *   @0x1a7154 str r4, [r5, #0x14]
 *   @0x1a7158 add r0, r0, #4
 *   @0x1a715c str lr, [r5, #0x1c]
 *   @0x1a7160 lsl r1, r1, #2
 *   @0x1a7164 strb r12, [r5, #0x18]
 *   @0x1a7168 add r2, pc, r2
 *   @0x1a716c bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1a7170 ldr r4, [r5, #0x10]
 *   @0x1a7174 cmp r4, #0
 *   @0x1a7178 str r4, [r5]
 *   @0x1a717c ble 0x1a71bc <_ZN5CPath13LoadFromChunkEP6YYPathPh+0x9c>
 *   @0x1a7180 add r4, r4, r4, lsl #1
 *   @0x1a7184 ldr r2, [r5, #0x4]
 *   @0x1a7188 add r3, r6, #32
 *   @0x1a718c add r4, r6, r4, lsl #2
 *   @0x1a7190 add r2, r2, #8
 *   @0x1a7194 add r4, r4, #32
 *   @0x1a7198 ldr lr, [r3, #-0xc]
 *   @0x1a719c add r3, r3, #12
 *   @0x1a71a0 ldr r12, [r3, #-0x14]
 *   @0x1a71a4 ldr r1, [r3, #-0x10]
 *   @0x1a71a8 cmp r3, r4
 *   @0x1a71ac str lr, [r2, #-0x8]
 *   @0x1a71b0 str r12, [r2, #-0x4]
 *   @0x1a71b4 str r1, [r2], #12
 *   @0x1a71b8 bne 0x1a7198 <_ZN5CPath13LoadFromChunkEP6YYPathPh+0x78>
 *   @0x1a71bc mov r0, r5
 *   @0x1a71c0 bl 0x1a6e30 <_ZN5CPath15ComputeInternalEv>
 *   @0x1a71c4 mov r0, #1
 *   @0x1a71c8 pop {r4, r5, r6, pc}
 *   @0x1a71cc andseq r5, r10, r0, ror pc
 *
 * ══ §130/168 F_LayerX(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bb028  size 176  44 条（0x1bb028..0x1bb0d8）
 * @func 0x1bb028 0x1bb0ec  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetLayerFromID(CRoom*, int) / YYGetFloat(RValue const*, int) / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0xc×2 / 0x10×1 / 0x4×1 / 0x7c×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bb028 cmp r3, #2
 *   @0x1bb02c mov r3, #0
 *   @0x1bb030 push {r4, r5, r6, lr}
 *   @0x1bb034 mov r4, r3
 *   @0x1bb038 ldr r5, [sp, #0x10]
 *   @0x1bb03c movt r3, #0xbff0
 *   @0x1bb040 str r4, [r0, #0xc]
 *   @0x1bb044 str r3, [r0, #0x4]
 *   @0x1bb048 str r4, [r0]
 *   @0x1bb04c beq 0x1bb064 <_Z8F_LayerXR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bb050 ldr r0, [pc, #0x7c]
 *   @0x1bb054 mov r1, r4
 *   @0x1bb058 pop {r4, r5, r6, lr}
 *   @0x1bb05c add r0, pc, r0
 *   @0x1bb060 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bb064 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bb068 ldr r3, [r5, #0xc]
 *   @0x1bb06c mov r1, r4
 *   @0x1bb070 bic r3, r3, #-16777216
 *   @0x1bb074 cmp r3, #1
 *   @0x1bb078 mov r6, r0
 *   @0x1bb07c mov r0, r5
 *   @0x1bb080 beq 0x1bb0b4 <_Z8F_LayerXR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x1bb084 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bb088 mov r1, r0
 *   @0x1bb08c mov r0, r6
 *   @0x1bb090 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1bb094 mov r4, r0
 *   @0x1bb098 cmp r4, #0
 *   @0x1bb09c popeq {r4, r5, r6, pc}
 *   @0x1bb0a0 mov r0, r5
 *   @0x1bb0a4 mov r1, #1
 *   @0x1bb0a8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1bb0ac str r0, [r4, #0x8]
 *   @0x1bb0b0 pop {r4, r5, r6, pc}
 *   @0x1bb0b4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1bb0b8 mov r1, r0
 *   @0x1bb0bc mov r0, r6
 *   @0x1bb0c0 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1bb0c4 mov r4, r0
 *   @0x1bb0c8 cmp r4, #0
 *   @0x1bb0cc bne 0x1bb0a0 <_Z8F_LayerXR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x1bb0d0 pop {r4, r5, r6, pc}
 *   @0x1bb0d4 ldrheq r2, [r9], -r0
 *
 * ══ §131/168 F_LayerY(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bb0d8  size 176  44 条（0x1bb0d8..0x1bb188）
 * @func 0x1bb0d8 0x1bb188  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetLayerFromID(CRoom*, int) / YYGetFloat(RValue const*, int) / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0xc×3 / 0x10×1 / 0x4×1 / 0x7c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bb0d8 cmp r3, #2
 *   @0x1bb0dc mov r3, #0
 *   @0x1bb0e0 push {r4, r5, r6, lr}
 *   @0x1bb0e4 mov r4, r3
 *   @0x1bb0e8 ldr r5, [sp, #0x10]
 *   @0x1bb0ec movt r3, #0xbff0
 *   @0x1bb0f0 str r4, [r0, #0xc]
 *   @0x1bb0f4 str r3, [r0, #0x4]
 *   @0x1bb0f8 str r4, [r0]
 *   @0x1bb0fc beq 0x1bb114 <_Z8F_LayerYR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bb100 ldr r0, [pc, #0x7c]
 *   @0x1bb104 mov r1, r4
 *   @0x1bb108 pop {r4, r5, r6, lr}
 *   @0x1bb10c add r0, pc, r0
 *   @0x1bb110 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bb114 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bb118 ldr r3, [r5, #0xc]
 *   @0x1bb11c mov r1, r4
 *   @0x1bb120 bic r3, r3, #-16777216
 *   @0x1bb124 cmp r3, #1
 *   @0x1bb128 mov r6, r0
 *   @0x1bb12c mov r0, r5
 *   @0x1bb130 beq 0x1bb164 <_Z8F_LayerYR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x1bb134 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bb138 mov r1, r0
 *   @0x1bb13c mov r0, r6
 *   @0x1bb140 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1bb144 mov r4, r0
 *   @0x1bb148 cmp r4, #0
 *   @0x1bb14c popeq {r4, r5, r6, pc}
 *   @0x1bb150 mov r0, r5
 *   @0x1bb154 mov r1, #1
 *   @0x1bb158 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1bb15c str r0, [r4, #0xc]
 *   @0x1bb160 pop {r4, r5, r6, pc}
 *   @0x1bb164 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1bb168 mov r1, r0
 *   @0x1bb16c mov r0, r6
 *   @0x1bb170 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1bb174 mov r4, r0
 *   @0x1bb178 cmp r4, #0
 *   @0x1bb17c bne 0x1bb150 <_Z8F_LayerYR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x1bb180 pop {r4, r5, r6, pc}
 *   @0x1bb184 andseq r2, r9, r8, lsr #18
 *
 * ══ §132/168 F_LayerHspeed(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bb2d0  size 176  44 条（0x1bb2d0..0x1bb380）
 * @func 0x1bb2d0 0x1bb394  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetLayerFromID(CRoom*, int) / YYGetFloat(RValue const*, int) / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0x10×2 / 0xc×2 / 0x4×1 / 0x7c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bb2d0 cmp r3, #2
 *   @0x1bb2d4 mov r3, #0
 *   @0x1bb2d8 push {r4, r5, r6, lr}
 *   @0x1bb2dc mov r4, r3
 *   @0x1bb2e0 ldr r5, [sp, #0x10]
 *   @0x1bb2e4 movt r3, #0xbff0
 *   @0x1bb2e8 str r4, [r0, #0xc]
 *   @0x1bb2ec str r3, [r0, #0x4]
 *   @0x1bb2f0 str r4, [r0]
 *   @0x1bb2f4 beq 0x1bb30c <_Z13F_LayerHspeedR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bb2f8 ldr r0, [pc, #0x7c]
 *   @0x1bb2fc mov r1, r4
 *   @0x1bb300 pop {r4, r5, r6, lr}
 *   @0x1bb304 add r0, pc, r0
 *   @0x1bb308 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bb30c bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bb310 ldr r3, [r5, #0xc]
 *   @0x1bb314 mov r1, r4
 *   @0x1bb318 bic r3, r3, #-16777216
 *   @0x1bb31c cmp r3, #1
 *   @0x1bb320 mov r6, r0
 *   @0x1bb324 mov r0, r5
 *   @0x1bb328 beq 0x1bb35c <_Z13F_LayerHspeedR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x1bb32c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bb330 mov r1, r0
 *   @0x1bb334 mov r0, r6
 *   @0x1bb338 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1bb33c mov r4, r0
 *   @0x1bb340 cmp r4, #0
 *   @0x1bb344 popeq {r4, r5, r6, pc}
 *   @0x1bb348 mov r0, r5
 *   @0x1bb34c mov r1, #1
 *   @0x1bb350 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1bb354 str r0, [r4, #0x10]
 *   @0x1bb358 pop {r4, r5, r6, pc}
 *   @0x1bb35c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1bb360 mov r1, r0
 *   @0x1bb364 mov r0, r6
 *   @0x1bb368 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1bb36c mov r4, r0
 *   @0x1bb370 cmp r4, #0
 *   @0x1bb374 bne 0x1bb348 <_Z13F_LayerHspeedR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x1bb378 pop {r4, r5, r6, pc}
 *   @0x1bb37c ldrheq r2, [r9], -r0
 *
 * ══ §133/168 F_LayerVspeed(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bb380  size 176  44 条（0x1bb380..0x1bb430）
 * @func 0x1bb380 0x1bb430  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetLayerFromID(CRoom*, int) / YYGetFloat(RValue const*, int) / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0xc×2 / 0x10×1 / 0x4×1 / 0x7c×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bb380 cmp r3, #2
 *   @0x1bb384 mov r3, #0
 *   @0x1bb388 push {r4, r5, r6, lr}
 *   @0x1bb38c mov r4, r3
 *   @0x1bb390 ldr r5, [sp, #0x10]
 *   @0x1bb394 movt r3, #0xbff0
 *   @0x1bb398 str r4, [r0, #0xc]
 *   @0x1bb39c str r3, [r0, #0x4]
 *   @0x1bb3a0 str r4, [r0]
 *   @0x1bb3a4 beq 0x1bb3bc <_Z13F_LayerVspeedR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bb3a8 ldr r0, [pc, #0x7c]
 *   @0x1bb3ac mov r1, r4
 *   @0x1bb3b0 pop {r4, r5, r6, lr}
 *   @0x1bb3b4 add r0, pc, r0
 *   @0x1bb3b8 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bb3bc bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bb3c0 ldr r3, [r5, #0xc]
 *   @0x1bb3c4 mov r1, r4
 *   @0x1bb3c8 bic r3, r3, #-16777216
 *   @0x1bb3cc cmp r3, #1
 *   @0x1bb3d0 mov r6, r0
 *   @0x1bb3d4 mov r0, r5
 *   @0x1bb3d8 beq 0x1bb40c <_Z13F_LayerVspeedR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x1bb3dc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bb3e0 mov r1, r0
 *   @0x1bb3e4 mov r0, r6
 *   @0x1bb3e8 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1bb3ec mov r4, r0
 *   @0x1bb3f0 cmp r4, #0
 *   @0x1bb3f4 popeq {r4, r5, r6, pc}
 *   @0x1bb3f8 mov r0, r5
 *   @0x1bb3fc mov r1, #1
 *   @0x1bb400 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1bb404 str r0, [r4, #0x14]
 *   @0x1bb408 pop {r4, r5, r6, pc}
 *   @0x1bb40c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1bb410 mov r1, r0
 *   @0x1bb414 mov r0, r6
 *   @0x1bb418 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1bb41c mov r4, r0
 *   @0x1bb420 cmp r4, #0
 *   @0x1bb424 bne 0x1bb3f8 <_Z13F_LayerVspeedR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x1bb428 pop {r4, r5, r6, pc}
 *   @0x1bb42c andseq r2, r9, r12, lsr #14
 *
 * ══ §134/168 F_LayerScriptBegin(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bb578  size 176  44 条（0x1bb578..0x1bb628）
 * @func 0x1bb578 0x1bb63c  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / CLayerManager::GetTargetRoomObj() / CLayerManager::GetLayerFromID(CRoom*, int) / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0xc×2 / 0x10×1 / 0x4×1 / 0x7c×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bb578 cmp r3, #2
 *   @0x1bb57c mov r3, #0
 *   @0x1bb580 push {r4, r5, r6, lr}
 *   @0x1bb584 mov r4, r3
 *   @0x1bb588 ldr r5, [sp, #0x10]
 *   @0x1bb58c movt r3, #0xbff0
 *   @0x1bb590 str r4, [r0, #0xc]
 *   @0x1bb594 str r3, [r0, #0x4]
 *   @0x1bb598 str r4, [r0]
 *   @0x1bb59c beq 0x1bb5b4 <_Z18F_LayerScriptBeginR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bb5a0 ldr r0, [pc, #0x7c]
 *   @0x1bb5a4 mov r1, r4
 *   @0x1bb5a8 pop {r4, r5, r6, lr}
 *   @0x1bb5ac add r0, pc, r0
 *   @0x1bb5b0 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bb5b4 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bb5b8 ldr r3, [r5, #0xc]
 *   @0x1bb5bc mov r1, r4
 *   @0x1bb5c0 bic r3, r3, #-16777216
 *   @0x1bb5c4 cmp r3, #1
 *   @0x1bb5c8 mov r6, r0
 *   @0x1bb5cc mov r0, r5
 *   @0x1bb5d0 beq 0x1bb604 <_Z18F_LayerScriptBeginR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x1bb5d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bb5d8 mov r1, r0
 *   @0x1bb5dc mov r0, r6
 *   @0x1bb5e0 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1bb5e4 mov r4, r0
 *   @0x1bb5e8 cmp r4, #0
 *   @0x1bb5ec popeq {r4, r5, r6, pc}
 *   @0x1bb5f0 mov r0, r5
 *   @0x1bb5f4 mov r1, #1
 *   @0x1bb5f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bb5fc str r0, [r4, #0x20]
 *   @0x1bb600 pop {r4, r5, r6, pc}
 *   @0x1bb604 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1bb608 mov r1, r0
 *   @0x1bb60c mov r0, r6
 *   @0x1bb610 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1bb614 mov r4, r0
 *   @0x1bb618 cmp r4, #0
 *   @0x1bb61c bne 0x1bb5f0 <_Z18F_LayerScriptBeginR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x1bb620 pop {r4, r5, r6, pc}
 *   @0x1bb624 andseq r2, r9, r0, asr #11
 *
 * ══ §135/168 F_LayerScriptEnd(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bb628  size 176  44 条（0x1bb628..0x1bb6d8）
 * @func 0x1bb628 0x1bb6ec  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / CLayerManager::GetTargetRoomObj() / CLayerManager::GetLayerFromID(CRoom*, int) / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0xc×2 / 0x10×1 / 0x4×1 / 0x7c×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bb628 cmp r3, #2
 *   @0x1bb62c mov r3, #0
 *   @0x1bb630 push {r4, r5, r6, lr}
 *   @0x1bb634 mov r4, r3
 *   @0x1bb638 ldr r5, [sp, #0x10]
 *   @0x1bb63c movt r3, #0xbff0
 *   @0x1bb640 str r4, [r0, #0xc]
 *   @0x1bb644 str r3, [r0, #0x4]
 *   @0x1bb648 str r4, [r0]
 *   @0x1bb64c beq 0x1bb664 <_Z16F_LayerScriptEndR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bb650 ldr r0, [pc, #0x7c]
 *   @0x1bb654 mov r1, r4
 *   @0x1bb658 pop {r4, r5, r6, lr}
 *   @0x1bb65c add r0, pc, r0
 *   @0x1bb660 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bb664 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bb668 ldr r3, [r5, #0xc]
 *   @0x1bb66c mov r1, r4
 *   @0x1bb670 bic r3, r3, #-16777216
 *   @0x1bb674 cmp r3, #1
 *   @0x1bb678 mov r6, r0
 *   @0x1bb67c mov r0, r5
 *   @0x1bb680 beq 0x1bb6b4 <_Z16F_LayerScriptEndR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x1bb684 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bb688 mov r1, r0
 *   @0x1bb68c mov r0, r6
 *   @0x1bb690 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1bb694 mov r4, r0
 *   @0x1bb698 cmp r4, #0
 *   @0x1bb69c popeq {r4, r5, r6, pc}
 *   @0x1bb6a0 mov r0, r5
 *   @0x1bb6a4 mov r1, #1
 *   @0x1bb6a8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bb6ac str r0, [r4, #0x24]
 *   @0x1bb6b0 pop {r4, r5, r6, pc}
 *   @0x1bb6b4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1bb6b8 mov r1, r0
 *   @0x1bb6bc mov r0, r6
 *   @0x1bb6c0 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1bb6c4 mov r4, r0
 *   @0x1bb6c8 cmp r4, #0
 *   @0x1bb6cc bne 0x1bb6a0 <_Z16F_LayerScriptEndR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x1bb6d0 pop {r4, r5, r6, pc}
 *   @0x1bb6d4 andseq r2, r9, r4, asr #10
 *
 * ══ §136/168 F_LayerShader(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bb6d8  size 176  44 条（0x1bb6d8..0x1bb788）
 * @func 0x1bb6d8 0x1bb79c  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / CLayerManager::GetTargetRoomObj() / CLayerManager::GetLayerFromID(CRoom*, int) / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0xc×2 / 0x10×1 / 0x4×1 / 0x7c×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bb6d8 cmp r3, #2
 *   @0x1bb6dc mov r3, #0
 *   @0x1bb6e0 push {r4, r5, r6, lr}
 *   @0x1bb6e4 mov r4, r3
 *   @0x1bb6e8 ldr r5, [sp, #0x10]
 *   @0x1bb6ec movt r3, #0xbff0
 *   @0x1bb6f0 str r4, [r0, #0xc]
 *   @0x1bb6f4 str r3, [r0, #0x4]
 *   @0x1bb6f8 str r4, [r0]
 *   @0x1bb6fc beq 0x1bb714 <_Z13F_LayerShaderR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bb700 ldr r0, [pc, #0x7c]
 *   @0x1bb704 mov r1, r4
 *   @0x1bb708 pop {r4, r5, r6, lr}
 *   @0x1bb70c add r0, pc, r0
 *   @0x1bb710 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bb714 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bb718 ldr r3, [r5, #0xc]
 *   @0x1bb71c mov r1, r4
 *   @0x1bb720 bic r3, r3, #-16777216
 *   @0x1bb724 cmp r3, #1
 *   @0x1bb728 mov r6, r0
 *   @0x1bb72c mov r0, r5
 *   @0x1bb730 beq 0x1bb764 <_Z13F_LayerShaderR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x1bb734 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bb738 mov r1, r0
 *   @0x1bb73c mov r0, r6
 *   @0x1bb740 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1bb744 mov r4, r0
 *   @0x1bb748 cmp r4, #0
 *   @0x1bb74c popeq {r4, r5, r6, pc}
 *   @0x1bb750 mov r0, r5
 *   @0x1bb754 mov r1, #1
 *   @0x1bb758 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bb75c str r0, [r4, #0x28]
 *   @0x1bb760 pop {r4, r5, r6, pc}
 *   @0x1bb764 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1bb768 mov r1, r0
 *   @0x1bb76c mov r0, r6
 *   @0x1bb770 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1bb774 mov r4, r0
 *   @0x1bb778 cmp r4, #0
 *   @0x1bb77c bne 0x1bb750 <_Z13F_LayerShaderR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x1bb780 pop {r4, r5, r6, pc}
 *   @0x1bb784 andseq r2, r9, r4, asr #9
 *
 * ══ §137/168 F_LayerGetScriptBegin(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bb788  size 176  44 条（0x1bb788..0x1bb838）
 * @func 0x1bb788 0x1bb84c  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetLayerFromID(CRoom*, int) / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0xc×2 / 0x4×1 / 0x18×1 / 0x78×1 / 0x20×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bb788 cmp r3, #1
 *   @0x1bb78c push {r3, r4, r5, r6, r7, lr}
 *   @0x1bb790 mov r3, #0
 *   @0x1bb794 mov r5, r3
 *   @0x1bb798 mov r4, r0
 *   @0x1bb79c movt r3, #0xbff0
 *   @0x1bb7a0 str r5, [r0, #0xc]
 *   @0x1bb7a4 str r3, [r0, #0x4]
 *   @0x1bb7a8 str r5, [r0]
 *   @0x1bb7ac ldr r6, [sp, #0x18]
 *   @0x1bb7b0 beq 0x1bb7c8 <_Z21F_LayerGetScriptBeginR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bb7b4 ldr r0, [pc, #0x78]
 *   @0x1bb7b8 mov r1, r5
 *   @0x1bb7bc pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bb7c0 add r0, pc, r0
 *   @0x1bb7c4 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bb7c8 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bb7cc ldr r3, [r6, #0xc]
 *   @0x1bb7d0 mov r1, r5
 *   @0x1bb7d4 bic r3, r3, #-16777216
 *   @0x1bb7d8 cmp r3, #1
 *   @0x1bb7dc mov r7, r0
 *   @0x1bb7e0 mov r0, r6
 *   @0x1bb7e4 beq 0x1bb818 <_Z21F_LayerGetScriptBeginR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x1bb7e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bb7ec mov r1, r0
 *   @0x1bb7f0 mov r0, r7
 *   @0x1bb7f4 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1bb7f8 cmp r0, #0
 *   @0x1bb7fc popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bb800 ldr r2, [r0, #0x20]
 *   @0x1bb804 vmov s15, r2
 *   @0x1bb808 vcvt.f64.s32 d7, s15
 *   @0x1bb80c vmov r2, r3, d7
 *   @0x1bb810 stm r4, {r2, r3}
 *   @0x1bb814 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bb818 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1bb81c mov r1, r0
 *   @0x1bb820 mov r0, r7
 *   @0x1bb824 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1bb828 cmp r0, #0
 *   @0x1bb82c bne 0x1bb800 <_Z21F_LayerGetScriptBeginR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x1bb830 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bb834 andseq r2, r9, r12, lsr r4
 *
 * ══ §138/168 F_LayerGetScriptEnd(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bb838  size 176  44 条（0x1bb838..0x1bb8e8）
 * @func 0x1bb838 0x1bb8fc  size 196  49 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetLayerFromID(CRoom*, int) / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0xc×2 / 0x4×1 / 0x18×1 / 0x78×1 / 0x24×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bb838 cmp r3, #1
 *   @0x1bb83c push {r3, r4, r5, r6, r7, lr}
 *   @0x1bb840 mov r3, #0
 *   @0x1bb844 mov r5, r3
 *   @0x1bb848 mov r4, r0
 *   @0x1bb84c movt r3, #0xbff0
 *   @0x1bb850 str r5, [r0, #0xc]
 *   @0x1bb854 str r3, [r0, #0x4]
 *   @0x1bb858 str r5, [r0]
 *   @0x1bb85c ldr r6, [sp, #0x18]
 *   @0x1bb860 beq 0x1bb878 <_Z19F_LayerGetScriptEndR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bb864 ldr r0, [pc, #0x78]
 *   @0x1bb868 mov r1, r5
 *   @0x1bb86c pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bb870 add r0, pc, r0
 *   @0x1bb874 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bb878 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bb87c ldr r3, [r6, #0xc]
 *   @0x1bb880 mov r1, r5
 *   @0x1bb884 bic r3, r3, #-16777216
 *   @0x1bb888 cmp r3, #1
 *   @0x1bb88c mov r7, r0
 *   @0x1bb890 mov r0, r6
 *   @0x1bb894 beq 0x1bb8c8 <_Z19F_LayerGetScriptEndR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x1bb898 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bb89c mov r1, r0
 *   @0x1bb8a0 mov r0, r7
 *   @0x1bb8a4 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1bb8a8 cmp r0, #0
 *   @0x1bb8ac popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bb8b0 ldr r2, [r0, #0x24]
 *   @0x1bb8b4 vmov s15, r2
 *   @0x1bb8b8 vcvt.f64.s32 d7, s15
 *   @0x1bb8bc vmov r2, r3, d7
 *   @0x1bb8c0 stm r4, {r2, r3}
 *   @0x1bb8c4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bb8c8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1bb8cc mov r1, r0
 *   @0x1bb8d0 mov r0, r7
 *   @0x1bb8d4 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1bb8d8 cmp r0, #0
 *   @0x1bb8dc bne 0x1bb8b0 <_Z19F_LayerGetScriptEndR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x1bb8e0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bb8e4 andseq r2, r9, r4, asr #7
 *
 * ══ §139/168 F_LayerGetShader(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bb8e8  size 176  44 条（0x1bb8e8..0x1bb998）
 * @func 0x1bb8e8 0x1bb998  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetLayerFromID(CRoom*, int) / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0xc×2 / 0x4×1 / 0x18×1 / 0x78×1 / 0x28×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bb8e8 cmp r3, #1
 *   @0x1bb8ec push {r3, r4, r5, r6, r7, lr}
 *   @0x1bb8f0 mov r3, #0
 *   @0x1bb8f4 mov r5, r3
 *   @0x1bb8f8 mov r4, r0
 *   @0x1bb8fc movt r3, #0xbff0
 *   @0x1bb900 str r5, [r0, #0xc]
 *   @0x1bb904 str r3, [r0, #0x4]
 *   @0x1bb908 str r5, [r0]
 *   @0x1bb90c ldr r6, [sp, #0x18]
 *   @0x1bb910 beq 0x1bb928 <_Z16F_LayerGetShaderR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bb914 ldr r0, [pc, #0x78]
 *   @0x1bb918 mov r1, r5
 *   @0x1bb91c pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bb920 add r0, pc, r0
 *   @0x1bb924 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bb928 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bb92c ldr r3, [r6, #0xc]
 *   @0x1bb930 mov r1, r5
 *   @0x1bb934 bic r3, r3, #-16777216
 *   @0x1bb938 cmp r3, #1
 *   @0x1bb93c mov r7, r0
 *   @0x1bb940 mov r0, r6
 *   @0x1bb944 beq 0x1bb978 <_Z16F_LayerGetShaderR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x1bb948 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bb94c mov r1, r0
 *   @0x1bb950 mov r0, r7
 *   @0x1bb954 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1bb958 cmp r0, #0
 *   @0x1bb95c popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bb960 ldr r2, [r0, #0x28]
 *   @0x1bb964 vmov s15, r2
 *   @0x1bb968 vcvt.f64.s32 d7, s15
 *   @0x1bb96c vmov r2, r3, d7
 *   @0x1bb970 stm r4, {r2, r3}
 *   @0x1bb974 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bb978 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1bb97c mov r1, r0
 *   @0x1bb980 mov r0, r7
 *   @0x1bb984 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1bb988 cmp r0, #0
 *   @0x1bb98c bne 0x1bb960 <_Z16F_LayerGetShaderR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x1bb990 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bb994 andseq r2, r9, r8, asr #6
 *
 * ══ §140/168 F_LayerBackgroundGetVisible(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bca14  size 176  44 条（0x1bca14..0x1bcac4）
 * @func 0x1bca14 0x1bcac4  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**)
 * 字段偏移 top8: 0x4×2 / 0xc×1 / 0x18×1 / 0x78×1 / 0x1c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bca14 cmp r3, #1
 *   @0x1bca18 push {r3, r4, r5, r6, r7, lr}
 *   @0x1bca1c mov r3, #0
 *   @0x1bca20 mov r5, r3
 *   @0x1bca24 mov r4, r0
 *   @0x1bca28 movt r3, #0xbff0
 *   @0x1bca2c str r5, [r0, #0xc]
 *   @0x1bca30 str r3, [r0, #0x4]
 *   @0x1bca34 str r5, [r0]
 *   @0x1bca38 ldr r6, [sp, #0x18]
 *   @0x1bca3c beq 0x1bca54 <_Z27F_LayerBackgroundGetVisibleR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bca40 ldr r0, [pc, #0x78]
 *   @0x1bca44 mov r1, r5
 *   @0x1bca48 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bca4c add r0, pc, r0
 *   @0x1bca50 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bca54 str r5, [r0]
 *   @0x1bca58 mov r3, #0
 *   @0x1bca5c movt r3, #0x3ff0
 *   @0x1bca60 str r3, [r0, #0x4]
 *   @0x1bca64 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bca68 mov r1, r5
 *   @0x1bca6c mov r7, r0
 *   @0x1bca70 mov r0, r6
 *   @0x1bca74 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bca78 mov r2, r5
 *   @0x1bca7c mov r1, r0
 *   @0x1bca80 mov r0, r7
 *   @0x1bca84 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bca88 cmp r0, #0
 *   @0x1bca8c popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bca90 ldr r3, [r0]
 *   @0x1bca94 cmp r3, #1
 *   @0x1bca98 popne {r3, r4, r5, r6, r7, pc}
 *   @0x1bca9c ldr r3, [r0, #0x1c]
 *   @0x1bcaa0 cmp r3, #0
 *   @0x1bcaa4 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1bcaa8 ldrb r2, [r3]
 *   @0x1bcaac vmov s15, r2
 *   @0x1bcab0 vcvt.f64.u32 d7, s15
 *   @0x1bcab4 vmov r2, r3, d7
 *   @0x1bcab8 stm r4, {r2, r3}
 *   @0x1bcabc pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bcac0 andseq r1, r9, r0, ror r6
 *
 * ══ §141/168 CLayerManager::ChangeInstanceDepth(CRoom*, CInstance*)  0x1c5f40  size 176  44 条（0x1c5f40..0x1c5ff0）
 * @func 0x1c5f40 0x1c5ff0  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetLayerFromID(CRoom*, int) / CLayerManager::RemoveInstance(CRoom*, CInstance*)
 * 字段偏移 top8: 0x170×2 / 0x174×1 / 0x4×1 / 0x19×1 / 0x60×1 / 0x58×1 / 0x20×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c5f40 push {r4, r5, r6, lr}
 *   @0x1c5f44 subs r5, r0, #0
 *   @0x1c5f48 mov r4, r1
 *   @0x1c5f4c popeq {r4, r5, r6, pc}
 *   @0x1c5f50 cmp r1, #0
 *   @0x1c5f54 popeq {r4, r5, r6, pc}
 *   @0x1c5f58 ldrb r3, [r1, #0x174]
 *   @0x1c5f5c cmp r3, #0
 *   @0x1c5f60 popeq {r4, r5, r6, pc}
 *   @0x1c5f64 ldr r1, [r1, #0x170]
 *   @0x1c5f68 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1c5f6c subs r1, r0, #0
 *   @0x1c5f70 popeq {r4, r5, r6, pc}
 *   @0x1c5f74 vldr s15, [r4, #384]
 *   @0x1c5f78 vcvt.s32.f32 s15, s15
 *   @0x1c5f7c ldr r3, [r1, #0x4]
 *   @0x1c5f80 vmov r2, s15
 *   @0x1c5f84 cmp r3, r2
 *   @0x1c5f88 popeq {r4, r5, r6, pc}
 *   @0x1c5f8c ldrb r3, [r1, #0x19]
 *   @0x1c5f90 cmp r3, #0
 *   @0x1c5f94 beq 0x1c5fa4 <_ZN13CLayerManager19ChangeInstanceDepthEP5CRoomP9CInstance+0x64>
 *   @0x1c5f98 ldr r3, [r1, #0x60]
 *   @0x1c5f9c cmp r3, #1
 *   @0x1c5fa0 beq 0x1c5fc8 <_ZN13CLayerManager19ChangeInstanceDepthEP5CRoomP9CInstance+0x88>
 *   @0x1c5fa4 mov r0, r5
 *   @0x1c5fa8 mov r1, r4
 *   @0x1c5fac bl 0x1b9e5c <_ZN13CLayerManager14RemoveInstanceEP5CRoomP9CInstance>
 *   @0x1c5fb0 mov r0, r5
 *   @0x1c5fb4 mvn r3, #0
 *   @0x1c5fb8 mov r1, r4
 *   @0x1c5fbc str r3, [r4, #0x170]
 *   @0x1c5fc0 pop {r4, r5, r6, lr}
 *   @0x1c5fc4 b 0x1c5d18 <_ZN13CLayerManager11AddInstanceEP5CRoomP9CInstance>
 *   @0x1c5fc8 ldr r0, [r1, #0x58]
 *   @0x1c5fcc ldr r12, [r0]
 *   @0x1c5fd0 cmp r12, #2
 *   @0x1c5fd4 popne {r4, r5, r6, pc}
 *   @0x1c5fd8 ldr r0, [r0, #0x20]
 *   @0x1c5fdc cmp r0, r4
 *   @0x1c5fe0 popne {r4, r5, r6, pc}
 *   @0x1c5fe4 mov r0, r5
 *   @0x1c5fe8 pop {r4, r5, r6, lr}
 *   @0x1c5fec b 0x1b8200 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib>
 *
 * ══ §142/168 F_Shader_Current(RValue&, CInstance*, CInstance*, int, RValue*)  0x1e0da8  size 176  44 条（0x1e0da8..0x1e0e58）
 * @func 0x1e0da8 0x1e0e58  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_Shader_Current(RValue&, CInstance*, CInstance*, int, RValue*)+0x78
 * 字段偏移 top8: 0x4×4 / 0x9c×1 / 0x-4×1 / 0xc×1 / 0x70×1 / 0x60×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e0da8 ldr r3, [pc, #0x9c]
 *   @0x1e0dac mov r2, #0
 *   @0x1e0db0 str r2, [r0]
 *   @0x1e0db4 mov r1, r2
 *   @0x1e0db8 ldr r3, [pc, r3]
 *   @0x1e0dbc movt r1, #0xbff0
 *   @0x1e0dc0 str r4, [sp, #-0x4]!
 *   @0x1e0dc4 ldr r12, [r3]
 *   @0x1e0dc8 str r2, [r0, #0xc]
 *   @0x1e0dcc cmp r12, r2
 *   @0x1e0dd0 str r1, [r0, #0x4]
 *   @0x1e0dd4 beq 0x1e0e20 <_Z16F_Shader_CurrentR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x1e0dd8 ldr r3, [pc, #0x70]
 *   @0x1e0ddc ldr r3, [pc, r3]
 *   @0x1e0de0 ldr r4, [r3]
 *   @0x1e0de4 cmp r4, r2
 *   @0x1e0de8 ble 0x1e0e20 <_Z16F_Shader_CurrentR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x1e0dec ldr r3, [pc, #0x60]
 *   @0x1e0df0 ldr r3, [pc, r3]
 *   @0x1e0df4 ldr r3, [r3]
 *   @0x1e0df8 ldr r1, [r3]
 *   @0x1e0dfc cmp r12, r1
 *   @0x1e0e00 bne 0x1e0e14 <_Z16F_Shader_CurrentR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x1e0e04 b 0x1e0e40 <_Z16F_Shader_CurrentR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x1e0e08 ldr r1, [r3, #0x4]!
 *   @0x1e0e0c cmp r12, r1
 *   @0x1e0e10 beq 0x1e0e28 <_Z16F_Shader_CurrentR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x1e0e14 add r2, r2, #1
 *   @0x1e0e18 cmp r2, r4
 *   @0x1e0e1c bne 0x1e0e08 <_Z16F_Shader_CurrentR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x1e0e20 ldr r4, [sp], #4
 *   @0x1e0e24 bx lr
 *   @0x1e0e28 vmov s15, r2
 *   @0x1e0e2c vcvt.f64.s32 d7, s15
 *   @0x1e0e30 vmov r2, r3, d7
 *   @0x1e0e34 stm r0, {r2, r3}
 *   @0x1e0e38 ldr r4, [sp], #4
 *   @0x1e0e3c bx lr
 *   @0x1e0e40 mov r2, #0
 *   @0x1e0e44 mov r3, #0
 *   @0x1e0e48 b 0x1e0e34 <_Z16F_Shader_CurrentR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x1e0e4c eoreq pc, r0, r8, lsl #31
 *   @0x1e0e50 eoreq pc, r0, r8, ror #30
 *   @0x1e0e54 eoreq pc, r0, r8, asr pc
 *
 * ══ §143/168 TrackView_Load(unsigned char*, unsigned int, unsigned char*)  0x1f2a50  size 176  44 条（0x1f2a50..0x1f2b00）
 * @func 0x1f2a50 0x1f2b00  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: TrackView_Load(unsigned char*, unsigned int, unsigned char*)+0x98
 * 字段偏移 top8: 0xc×3 / 0x98×1 / 0x84×1 / 0x64×1 / 0x60×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f2a50 ldr r3, [pc, #0x98]
 *   @0x1f2a54 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1f2a58 ldr r3, [pc, r3]
 *   @0x1f2a5c ldr r8, [r0]
 *   @0x1f2a60 mov r5, r0
 *   @0x1f2a64 ldr r4, [r3]
 *   @0x1f2a68 ldr r1, [pc, #0x84]
 *   @0x1f2a6c mov r2, r8
 *   @0x1f2a70 ldr r3, [r4]
 *   @0x1f2a74 add r1, pc, r1
 *   @0x1f2a78 mov r0, r4
 *   @0x1f2a7c ldr r3, [r3, #0xc]
 *   @0x1f2a80 blx r3
 *   @0x1f2a84 cmp r8, #0
 *   @0x1f2a88 ble 0x1f2ae8 <_Z14TrackView_LoadPhjS_+0x98>
 *   @0x1f2a8c ldr r10, [pc, #0x64]
 *   @0x1f2a90 add r5, r5, #4
 *   @0x1f2a94 ldr r9, [pc, #0x60]
 *   @0x1f2a98 mov r6, #0
 *   @0x1f2a9c add r10, pc, r10
 *   @0x1f2aa0 add r9, pc, r9
 *   @0x1f2aa4 ldr r3, [r4]
 *   @0x1f2aa8 add r5, r5, #4
 *   @0x1f2aac mov r0, r4
 *   @0x1f2ab0 mov r1, r10
 *   @0x1f2ab4 ldr r2, [r5]
 *   @0x1f2ab8 add r6, r6, #1
 *   @0x1f2abc ldr r3, [r3, #0xc]
 *   @0x1f2ac0 ldr r7, [r5, #0x4]
 *   @0x1f2ac4 blx r3
 *   @0x1f2ac8 ldr r3, [r4]
 *   @0x1f2acc mov r0, r4
 *   @0x1f2ad0 mov r1, r9
 *   @0x1f2ad4 mov r2, r7
 *   @0x1f2ad8 ldr r3, [r3, #0xc]
 *   @0x1f2adc blx r3
 *   @0x1f2ae0 cmp r8, r6
 *   @0x1f2ae4 bgt 0x1f2aa4 <_Z14TrackView_LoadPhjS_+0x54>
 *   @0x1f2ae8 mov r0, #1
 *   @0x1f2aec pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1f2af0 ldrheq r10, [pc], -r12
 *   @0x1f2af4 andseq pc, r5, r12, ror #25
 *   @0x1f2af8 ldrsbeq pc, [r5], -r12
 *   @0x1f2afc ldrsheq pc, [r5], -r4
 *
 * ══ §144/168 SHA1Input(SHA1Context*, unsigned char const*, unsigned int)  0x214538  size 176  44 条（0x214538..0x2145e8）
 * @func 0x214538 0x2145e8  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SHA1ProcessMessageBlock(SHA1Context*)
 * 字段偏移 top8: 0x64×3 / 0x5c×2 / 0x14×2 / 0x18×2 / 0x60×1 / 0x-1×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x214538 cmp r2, #0
 *   @0x21453c push {r3, r4, r5, r6, r7, lr}
 *   @0x214540 mov r4, r0
 *   @0x214544 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x214548 ldr r3, [r0, #0x60]
 *   @0x21454c cmp r3, #0
 *   @0x214550 bne 0x2145dc <_Z9SHA1InputP11SHA1ContextPKhj+0xa4>
 *   @0x214554 ldr r3, [r0, #0x64]
 *   @0x214558 cmp r3, #0
 *   @0x21455c bne 0x2145dc <_Z9SHA1InputP11SHA1ContextPKhj+0xa4>
 *   @0x214560 add r6, r1, r2
 *   @0x214564 add r5, r1, #1
 *   @0x214568 mov r7, #1
 *   @0x21456c b 0x214590 <_Z9SHA1InputP11SHA1ContextPKhj+0x58>
 *   @0x214570 mov r0, r4
 *   @0x214574 bl 0x2142e8 <_Z23SHA1ProcessMessageBlockP11SHA1Context>
 *   @0x214578 cmp r5, r6
 *   @0x21457c add r5, r5, #1
 *   @0x214580 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x214584 ldr r3, [r4, #0x64]
 *   @0x214588 cmp r3, #0
 *   @0x21458c popne {r3, r4, r5, r6, r7, pc}
 *   @0x214590 ldr r1, [r4, #0x5c]
 *   @0x214594 ldr r2, [r4, #0x14]
 *   @0x214598 add r3, r1, #1
 *   @0x21459c str r3, [r4, #0x5c]
 *   @0x2145a0 add r2, r2, #8
 *   @0x2145a4 ldrb r0, [r5, #-0x1]
 *   @0x2145a8 add r1, r4, r1
 *   @0x2145ac cmp r2, #0
 *   @0x2145b0 strb r0, [r1, #0x1c]
 *   @0x2145b4 str r2, [r4, #0x14]
 *   @0x2145b8 bne 0x2145d0 <_Z9SHA1InputP11SHA1ContextPKhj+0x98>
 *   @0x2145bc ldr r2, [r4, #0x18]
 *   @0x2145c0 add r2, r2, #1
 *   @0x2145c4 str r2, [r4, #0x18]
 *   @0x2145c8 cmp r2, #0
 *   @0x2145cc streq r7, [r4, #0x64]
 *   @0x2145d0 cmp r3, #64
 *   @0x2145d4 bne 0x214578 <_Z9SHA1InputP11SHA1ContextPKhj+0x40>
 *   @0x2145d8 b 0x214570 <_Z9SHA1InputP11SHA1ContextPKhj+0x38>
 *   @0x2145dc mov r3, #1
 *   @0x2145e0 str r3, [r4, #0x64]
 *   @0x2145e4 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §145/168 CPhysicsFixture::SetEdgeShape(float, float, float, float)  0x236848  size 176  44 条（0x236848..0x2368f8）
 * @func 0x236848 0x2368f8  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsFixture::DeleteShape() / operator new(unsigned int) / CPhysicsFixture::AllocVertices(int) / b2EdgeShape::Set(b2Vec2 const&, b2Vec2 const&)
 * 字段偏移 top8: 0x20×3 / 0x4×2 / 0x8×2 / 0xc×2 / 0x64×1 / 0x2c×1 / 0x2d×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x236848 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x23684c mov r5, r0
 *   @0x236850 mov r6, r1
 *   @0x236854 mov r7, r2
 *   @0x236858 mov r8, r3
 *   @0x23685c ldr r9, [sp, #0x20]
 *   @0x236860 bl 0x2365d0 <_ZN15CPhysicsFixture11DeleteShapeEv>
 *   @0x236864 mov r0, #48
 *   @0x236868 bl 0x27c524 <_Znwj>
 *   @0x23686c mov r12, #2
 *   @0x236870 mov r3, #1
 *   @0x236874 mov lr, #0
 *   @0x236878 mov r1, r12
 *   @0x23687c movw r2, #0xd70a
 *   @0x236880 movt r2, #0x3c23
 *   @0x236884 mov r4, r0
 *   @0x236888 ldr r0, [pc, #0x64]
 *   @0x23688c str r3, [r4, #0x4]
 *   @0x236890 ldr r0, [pc, r0]
 *   @0x236894 str r2, [r4, #0x8]
 *   @0x236898 strb lr, [r4, #0x2c]
 *   @0x23689c add r0, r0, #8
 *   @0x2368a0 strb lr, [r4, #0x2d]
 *   @0x2368a4 str r0, [r4]
 *   @0x2368a8 mov r0, #0
 *   @0x2368ac str r0, [r4, #0x1c]
 *   @0x2368b0 str r0, [r4, #0x20]
 *   @0x2368b4 str r0, [r4, #0x24]
 *   @0x2368b8 str r0, [r4, #0x28]
 *   @0x2368bc mov r0, r5
 *   @0x2368c0 str r12, [r5, #0xc]
 *   @0x2368c4 bl 0x23658c <_ZN15CPhysicsFixture13AllocVerticesEi>
 *   @0x2368c8 ldr r1, [r5, #0x14]
 *   @0x2368cc mov r0, r4
 *   @0x2368d0 add r2, r1, #8
 *   @0x2368d4 str r6, [r1]
 *   @0x2368d8 str r7, [r1, #0x4]
 *   @0x2368dc str r8, [r1, #0x8]
 *   @0x2368e0 str r9, [r1, #0xc]
 *   @0x2368e4 bl 0x2c5630 <_ZN11b2EdgeShape3SetERK6b2Vec2S2_>
 *   @0x2368e8 ldr r3, [r5, #0x20]
 *   @0x2368ec str r4, [r3]
 *   @0x2368f0 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2368f4 andseq r10, r11, r4, lsr #24
 *
 * ══ §146/168 CalcTimeFromYear(double)  0x2452c0  size 176  42 条（0x2452c0..0x245370）
 * @func 0x2452c0 0x245368  size 168  42 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DayFromYear(double)×2 / 0xb6598
 * 字段偏移 top8: 无
 * VFP 指令 28 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2452c0 push {r3, lr}
 *   @0x2452c4 vpush {d8, d9, d10, d11}
 *   @0x2452c8 bl 0xb6598 <floor@plt>
 *   @0x2452cc vldr d11, [pc, #132]
 *   @0x2452d0 vmov d8, r0, r1
 *   @0x2452d4 vcmp.f64 d8, d11
 *   @0x2452d8 vmrs APSR_nzcv, fpscr
 *   @0x2452dc beq 0x245344 <_Z16CalcTimeFromYeard+0x84>
 *   @0x2452e0 vmov.f64 d7, #-1.000000e+00
 *   @0x2452e4 vmov r0, r1, d11
 *   @0x2452e8 vmov.f64 d10, #1.000000e+00
 *   @0x2452ec vcmpe.f64 d8, d11
 *   @0x2452f0 vmrs APSR_nzcv, fpscr
 *   @0x2452f4 vmovpl.f64 d10, d7
 *   @0x2452f8 bl 0x244aa8 <_Z11DayFromYeard>
 *   @0x2452fc vadd.f64 d8, d10, d8
 *   @0x245300 vcmp.f64 d8, d11
 *   @0x245304 vmrs APSR_nzcv, fpscr
 *   @0x245308 vmov d9, r0, r1
 *   @0x24530c beq 0x245330 <_Z16CalcTimeFromYeard+0x70>
 *   @0x245310 vmov r0, r1, d8
 *   @0x245314 bl 0x244aa8 <_Z11DayFromYeard>
 *   @0x245318 vadd.f64 d8, d8, d10
 *   @0x24531c vcmp.f64 d8, d11
 *   @0x245320 vmrs APSR_nzcv, fpscr
 *   @0x245324 vmov d7, r0, r1
 *   @0x245328 vadd.f64 d9, d9, d7
 *   @0x24532c bne 0x245310 <_Z16CalcTimeFromYeard+0x50>
 *   @0x245330 vldr d7, [pc, #40]
 *   @0x245334 vmul.f64 d9, d9, d7
 *   @0x245338 vmov r0, r1, d9
 *   @0x24533c vpop {d8, d9, d10, d11}
 *   @0x245340 pop {r3, pc}
 *   @0x245344 vldr d9, [pc, #28]
 *   @0x245348 vmov r0, r1, d9
 *   @0x24534c vpop {d8, d9, d10, d11}
 *   @0x245350 pop {r3, pc}
 *   @0x245354 nop
 *   @0x245358 andeq r0, r0, r0
 *   @0x24535c addsmi r12, lr, r0, lsl #16
 *   @0x245360 andeq r0, r0, r0
 *   @0x245364 orrsmi r9, r4, r0, ror r9
 *
 * ══ §147/168 SMemoryArray::Init(int, int, int)  0x27dc64  size 176  44 条（0x27dc64..0x27dd14）
 * @func 0x27dc64 0x27dd14  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6544 / SMemoryArray::Init(int, int, int)+0xa0
 * 字段偏移 top8: 0x18×1 / 0x1c×1 / 0x8×1 / 0x68×1 / 0x64×1 / 0xc×1 / 0x10×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27dc64 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x27dc68 add r7, r1, #2
 *   @0x27dc6c mov r5, r0
 *   @0x27dc70 str r1, [r0, #0x18]
 *   @0x27dc74 mul r7, r2, r7
 *   @0x27dc78 str r2, [r5, #0x1c]
 *   @0x27dc7c mov r8, #0
 *   @0x27dc80 str r8, [r0]
 *   @0x27dc84 mov r4, r2
 *   @0x27dc88 mov r0, r7
 *   @0x27dc8c bl 0xb6544 <malloc@plt>
 *   @0x27dc90 cmp r0, r8
 *   @0x27dc94 str r0, [r5, #0x8]
 *   @0x27dc98 popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x27dc9c ldr r12, [pc, #0x68]
 *   @0x27dca0 lsl r6, r4, #1
 *   @0x27dca4 ldr r2, [pc, #0x64]
 *   @0x27dca8 rsb r7, r6, r7
 *   @0x27dcac ldr r12, [pc, r12]
 *   @0x27dcb0 add r1, r0, r7
 *   @0x27dcb4 ldr r2, [pc, r2]
 *   @0x27dcb8 cmp r4, r8
 *   @0x27dcbc ldr r9, [r12]
 *   @0x27dcc0 sub r3, r4, #1
 *   @0x27dcc4 ldr r0, [r2]
 *   @0x27dcc8 add r9, r6, r9
 *   @0x27dccc str r1, [r5, #0xc]
 *   @0x27dcd0 add r7, r9, r7
 *   @0x27dcd4 str r1, [r5, #0x10]
 *   @0x27dcd8 add r6, r6, r0
 *   @0x27dcdc str r3, [r5, #0x14]
 *   @0x27dce0 str r7, [r12]
 *   @0x27dce4 subgt r1, r1, #2
 *   @0x27dce8 str r6, [r2]
 *   @0x27dcec movgt r3, r8
 *   @0x27dcf0 ble 0x27dd04 <_ZN12SMemoryArray4InitEiii+0xa0>
 *   @0x27dcf4 strh r3, [r1, #2]!
 *   @0x27dcf8 add r3, r3, #1
 *   @0x27dcfc cmp r3, r4
 *   @0x27dd00 bne 0x27dcf4 <_ZN12SMemoryArray4InitEiii+0x90>
 *   @0x27dd04 mov r0, #1
 *   @0x27dd08 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x27dd0c andseq r2, r7, r12, lsr #14
 *   @0x27dd10 andseq r2, r7, r0, lsr r7
 *
 * ══ §148/168 spAnimationStateData_setMix  0x283bb0  size 176  44 条（0x283bb0..0x283c60）
 * @func 0x283bb0 0x283c60  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _FromEntry_create / _ToEntry_create
 * 字段偏移 top8: 0x8×7 / 0x4×4
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x283bb0 push {r3, r4, r5, r6, r7, lr}
 *   @0x283bb4 mov r5, r0
 *   @0x283bb8 ldr r4, [r0, #0x8]
 *   @0x283bbc mov r6, r2
 *   @0x283bc0 mov r7, r3
 *   @0x283bc4 cmp r4, #0
 *   @0x283bc8 beq 0x283bf4 <spAnimationStateData_setMix+0x44>
 *   @0x283bcc ldr r3, [r4]
 *   @0x283bd0 cmp r3, r1
 *   @0x283bd4 bne 0x283be8 <spAnimationStateData_setMix+0x38>
 *   @0x283bd8 b 0x283c28 <spAnimationStateData_setMix+0x78>
 *   @0x283bdc ldr r12, [r4]
 *   @0x283be0 cmp r12, r1
 *   @0x283be4 beq 0x283c28 <spAnimationStateData_setMix+0x78>
 *   @0x283be8 ldr r4, [r4, #0x8]
 *   @0x283bec cmp r4, #0
 *   @0x283bf0 bne 0x283bdc <spAnimationStateData_setMix+0x2c>
 *   @0x283bf4 mov r0, r1
 *   @0x283bf8 bl 0x283afc <_FromEntry_create>
 *   @0x283bfc ldr r3, [r5, #0x8]
 *   @0x283c00 mov r4, r0
 *   @0x283c04 str r3, [r0, #0x8]
 *   @0x283c08 str r0, [r5, #0x8]
 *   @0x283c0c mov r0, r6
 *   @0x283c10 mov r1, r7
 *   @0x283c14 bl 0x283ac4 <_ToEntry_create>
 *   @0x283c18 ldr r3, [r4, #0x4]
 *   @0x283c1c str r3, [r0, #0x8]
 *   @0x283c20 str r0, [r4, #0x4]
 *   @0x283c24 pop {r3, r4, r5, r6, r7, pc}
 *   @0x283c28 ldr r12, [r4, #0x4]
 *   @0x283c2c cmp r12, #0
 *   @0x283c30 beq 0x283c0c <spAnimationStateData_setMix+0x5c>
 *   @0x283c34 ldr r3, [r12]
 *   @0x283c38 cmp r3, r6
 *   @0x283c3c beq 0x283c58 <spAnimationStateData_setMix+0xa8>
 *   @0x283c40 ldr r12, [r12, #0x8]
 *   @0x283c44 cmp r12, #0
 *   @0x283c48 beq 0x283c0c <spAnimationStateData_setMix+0x5c>
 *   @0x283c4c ldr r5, [r12]
 *   @0x283c50 cmp r5, r6
 *   @0x283c54 bne 0x283c40 <spAnimationStateData_setMix+0x90>
 *   @0x283c58 str r7, [r12, #0x4]
 *   @0x283c5c pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §149/168 spAtlas_findRegion  0x284958  size 176  44 条（0x284958..0x284a08）
 * @func 0x284958 0x284a08  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6574×2 / 0xb6538
 * 字段偏移 top8: 0x4c×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x284958 push {r4, r5, r6, lr}
 *   @0x28495c mov r4, r1
 *   @0x284960 ldr r5, [r0, #0x4]
 *   @0x284964 cmp r5, #0
 *   @0x284968 beq 0x2849d0 <spAtlas_findRegion+0x78>
 *   @0x28496c ldr r6, [r5]
 *   @0x284970 mov r1, r4
 *   @0x284974 mov r0, r6
 *   @0x284978 bl 0xb6574 <strcmp@plt>
 *   @0x28497c cmp r0, #0
 *   @0x284980 beq 0x2849d0 <spAtlas_findRegion+0x78>
 *   @0x284984 cmp r4, #0
 *   @0x284988 beq 0x2849c4 <spAtlas_findRegion+0x6c>
 *   @0x28498c mov r0, r4
 *   @0x284990 bl 0xb6538 <strlen@plt>
 *   @0x284994 subs r0, r0, #1
 *   @0x284998 bmi 0x2849c4 <spAtlas_findRegion+0x6c>
 *   @0x28499c ldrb r3, [r4, r0]
 *   @0x2849a0 cmp r3, #47
 *   @0x2849a4 movne r3, r0
 *   @0x2849a8 bne 0x2849bc <spAtlas_findRegion+0x64>
 *   @0x2849ac b 0x2849c4 <spAtlas_findRegion+0x6c>
 *   @0x2849b0 ldrb r2, [r4, r3]
 *   @0x2849b4 cmp r2, #47
 *   @0x2849b8 beq 0x2849d8 <spAtlas_findRegion+0x80>
 *   @0x2849bc subs r3, r3, #1
 *   @0x2849c0 bhs 0x2849b0 <spAtlas_findRegion+0x58>
 *   @0x2849c4 ldr r5, [r5, #0x4c]
 *   @0x2849c8 cmp r5, #0
 *   @0x2849cc bne 0x28496c <spAtlas_findRegion+0x14>
 *   @0x2849d0 mov r0, r5
 *   @0x2849d4 pop {r4, r5, r6, pc}
 *   @0x2849d8 cmp r0, r3
 *   @0x2849dc beq 0x2849c4 <spAtlas_findRegion+0x6c>
 *   @0x2849e0 add r1, r3, #1
 *   @0x2849e4 mov r0, r6
 *   @0x2849e8 add r1, r4, r1
 *   @0x2849ec bl 0xb6574 <strcmp@plt>
 *   @0x2849f0 cmp r0, #0
 *   @0x2849f4 beq 0x2849d0 <spAtlas_findRegion+0x78>
 *   @0x2849f8 ldr r5, [r5, #0x4c]
 *   @0x2849fc cmp r5, #0
 *   @0x284a00 bne 0x28496c <spAtlas_findRegion+0x14>
 *   @0x284a04 b 0x2849d0 <spAtlas_findRegion+0x78>
 *
 * ══ §150/168 Java_com_yoyogames_runner_RunnerJNILib_dsMapAddString  0x292ab8  size 176  44 条（0x292ab8..0x292b68）
 * @func 0x292ab8 0x292b68  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: setJNIEnv / dsMapAddString
 * 字段偏移 top8: 0x2a4×2 / 0x2a8×2 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x292ab8 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x292abc mov r4, r0
 *   @0x292ac0 mov r8, r3
 *   @0x292ac4 mov r9, r2
 *   @0x292ac8 ldr r5, [sp, #0x20]
 *   @0x292acc bl 0x290614 <setJNIEnv>
 *   @0x292ad0 ldr r3, [r4]
 *   @0x292ad4 mov r1, r8
 *   @0x292ad8 mov r2, #0
 *   @0x292adc mov r0, r4
 *   @0x292ae0 ldr r3, [r3, #0x2a4]
 *   @0x292ae4 blx r3
 *   @0x292ae8 ldr r3, [r4]
 *   @0x292aec mov r1, r5
 *   @0x292af0 mov r2, #0
 *   @0x292af4 ldr r3, [r3, #0x2a4]
 *   @0x292af8 mov r7, r0
 *   @0x292afc mov r0, r4
 *   @0x292b00 blx r3
 *   @0x292b04 mov r1, r7
 *   @0x292b08 mov r6, r0
 *   @0x292b0c mov r0, r9
 *   @0x292b10 mov r2, r6
 *   @0x292b14 bl 0x1019f4 <dsMapAddString>
 *   @0x292b18 cmp r7, #0
 *   @0x292b1c cmpne r8, #0
 *   @0x292b20 bne 0x292b4c <Java_com_yoyogames_runner_RunnerJNILib_dsMapAddString+0x94>
 *   @0x292b24 cmp r6, #0
 *   @0x292b28 cmpne r5, #0
 *   @0x292b2c popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x292b30 ldr r3, [r4]
 *   @0x292b34 mov r1, r5
 *   @0x292b38 mov r2, r6
 *   @0x292b3c mov r0, r4
 *   @0x292b40 ldr r3, [r3, #0x2a8]
 *   @0x292b44 blx r3
 *   @0x292b48 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x292b4c ldr r3, [r4]
 *   @0x292b50 mov r1, r8
 *   @0x292b54 mov r2, r7
 *   @0x292b58 mov r0, r4
 *   @0x292b5c ldr r3, [r3, #0x2a8]
 *   @0x292b60 blx r3
 *   @0x292b64 b 0x292b24 <Java_com_yoyogames_runner_RunnerJNILib_dsMapAddString+0x6c>
 *
 * ══ §151/168 Java_com_yoyogames_runner_RunnerJNILib_InputResult  0x292c58  size 176  44 条（0x292c58..0x292d08）
 * @func 0x292c58 0x292d08  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: setJNIEnv / 0xb6640 / InputQuery::SetResult(int, int, char const*)
 * 字段偏移 top8: 0x6c×2 / 0x20×1 / 0x2a4×1 / 0xc×1 / 0x2a8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x292c58 push {r4, r5, r6, r7, r8, lr}
 *   @0x292c5c sub sp, sp, #8
 *   @0x292c60 mov r5, r0
 *   @0x292c64 mov r6, r2
 *   @0x292c68 mov r7, r3
 *   @0x292c6c ldr r8, [sp, #0x20]
 *   @0x292c70 bl 0x290614 <setJNIEnv>
 *   @0x292c74 ldr r3, [r5]
 *   @0x292c78 mov r1, r6
 *   @0x292c7c mov r2, #0
 *   @0x292c80 mov r0, r5
 *   @0x292c84 ldr r3, [r3, #0x2a4]
 *   @0x292c88 blx r3
 *   @0x292c8c ldr r12, [pc, #0x6c]
 *   @0x292c90 ldr r1, [pc, #0x6c]
 *   @0x292c94 mov r3, r7
 *   @0x292c98 ldr r12, [pc, r12]
 *   @0x292c9c add r1, pc, r1
 *   @0x292ca0 mov r2, r0
 *   @0x292ca4 mov r4, r0
 *   @0x292ca8 ldr r0, [r12]
 *   @0x292cac ldr r12, [r0]
 *   @0x292cb0 str r8, [sp]
 *   @0x292cb4 ldr r12, [r12, #0xc]
 *   @0x292cb8 blx r12
 *   @0x292cbc mov r0, r4
 *   @0x292cc0 bl 0xb6640 <strdup@plt>
 *   @0x292cc4 mov r1, r7
 *   @0x292cc8 mov r2, r0
 *   @0x292ccc mov r0, r8
 *   @0x292cd0 bl 0xf274c <_ZN10InputQuery9SetResultEiiPKc>
 *   @0x292cd4 cmp r4, #0
 *   @0x292cd8 cmpne r6, #0
 *   @0x292cdc beq 0x292cf8 <Java_com_yoyogames_runner_RunnerJNILib_InputResult+0xa0>
 *   @0x292ce0 ldr r3, [r5]
 *   @0x292ce4 mov r1, r6
 *   @0x292ce8 mov r2, r4
 *   @0x292cec mov r0, r5
 *   @0x292cf0 ldr r3, [r3, #0x2a8]
 *   @0x292cf4 blx r3
 *   @0x292cf8 add sp, sp, #8
 *   @0x292cfc pop {r4, r5, r6, r7, r8, pc}
 *   @0x292d00 andseq r10, r5, r12, ror r10
 *   @0x292d04 andeq r6, r12, r4, asr #7
 *
 * ══ §152/168 Java_com_yoyogames_runner_RunnerJNILib_DsMapAddString  0x293c90  size 176  44 条（0x293c90..0x293d40）
 * @func 0x293c90 0x293d40  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: setJNIEnv / F_DsMapAdd_Internal(int, char*, char*)
 * 字段偏移 top8: 0x2a4×2 / 0x2a8×2 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x293c90 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x293c94 mov r4, r0
 *   @0x293c98 mov r8, r3
 *   @0x293c9c mov r9, r2
 *   @0x293ca0 ldr r5, [sp, #0x20]
 *   @0x293ca4 bl 0x290614 <setJNIEnv>
 *   @0x293ca8 ldr r3, [r4]
 *   @0x293cac mov r1, r8
 *   @0x293cb0 mov r2, #0
 *   @0x293cb4 mov r0, r4
 *   @0x293cb8 ldr r3, [r3, #0x2a4]
 *   @0x293cbc blx r3
 *   @0x293cc0 ldr r3, [r4]
 *   @0x293cc4 mov r1, r5
 *   @0x293cc8 mov r2, #0
 *   @0x293ccc ldr r3, [r3, #0x2a4]
 *   @0x293cd0 mov r7, r0
 *   @0x293cd4 mov r0, r4
 *   @0x293cd8 blx r3
 *   @0x293cdc mov r1, r7
 *   @0x293ce0 mov r6, r0
 *   @0x293ce4 mov r0, r9
 *   @0x293ce8 mov r2, r6
 *   @0x293cec bl 0x104f64 <_Z19F_DsMapAdd_InternaliPcS_>
 *   @0x293cf0 cmp r7, #0
 *   @0x293cf4 cmpne r8, #0
 *   @0x293cf8 bne 0x293d24 <Java_com_yoyogames_runner_RunnerJNILib_DsMapAddString+0x94>
 *   @0x293cfc cmp r6, #0
 *   @0x293d00 cmpne r5, #0
 *   @0x293d04 popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x293d08 ldr r3, [r4]
 *   @0x293d0c mov r1, r5
 *   @0x293d10 mov r2, r6
 *   @0x293d14 mov r0, r4
 *   @0x293d18 ldr r3, [r3, #0x2a8]
 *   @0x293d1c blx r3
 *   @0x293d20 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x293d24 ldr r3, [r4]
 *   @0x293d28 mov r1, r8
 *   @0x293d2c mov r2, r7
 *   @0x293d30 mov r0, r4
 *   @0x293d34 ldr r3, [r3, #0x2a8]
 *   @0x293d38 blx r3
 *   @0x293d3c b 0x293cfc <Java_com_yoyogames_runner_RunnerJNILib_DsMapAddString+0x6c>
 *
 * ══ §153/168 _zip_cdir_write(zip_cdir*, __sFILE*, zip_error*)  0x2a3e10  size 176  44 条（0x2a3e10..0x2a3ec0）
 * @func 0x2a3e10 0x2a3ec0  size 176  44 条
 * 部分覆盖: 本节 44/74 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2a399c×3 / anon_2a399c+0x2c×3 / 0xb6ee0×2 / 0xb68bc×2 / _zip_error_set(zip_error*, int, int)
 * 字段偏移 top8: 0xc×4 / 0x4×3 / 0x8×2 / 0x14×2 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a3e10 push.w {r4, r5, r6, r7, r8, lr}
 *   @0x2a3e14 mov r5, r0
 *   @0x2a3e18 mov r4, r1
 *   @0x2a3e1c blx 0xb6ee0 <ftello@plt>
 *   @0x2a3e20 movs r6, #0x0
 *   @0x2a3e24 rscvs r0, r8, r12, lsr r8
 *   @0x2a3e28 ldr r3, [r5, #0x4]
 *   @0x2a3e2c bge 0x2a3e46 <_Z15_zip_cdir_writeP8zip_cdirP7__sFILEP9zip_error+0x36>
 *   @0x2a3e30 mov r1, r4
 *   @0x2a3e34 mov r3, r7
 *   @0x2a3e38 .word 0xf7ff0006
 *   @0x2a3e3c stmdahs r0, {r0, r4, r6, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2a3e40 bne 0x2a3eb4 <_Z15_zip_cdir_writeP8zip_cdirP7__sFILEP9zip_error+0xa4>
 *   @0x2a3e44 b 0x2a3e28 <_Z15_zip_cdir_writeP8zip_cdirP7__sFILEP9zip_error+0x18>
 *   @0x2a3e48 blx 0xb6ee0 <ftello@plt>
 *   @0x2a3e4c ldr r3, [r5, #0xc]
 *   @0x2a3e50 movs r1, #0x1
 *   @0x2a3e54 str r0, [r5, #0x8]
 *   @0x2a3e58 mov r3, r4
 *   @0x2a3e5c blx 0xb68bc <fwrite@plt>
 *   @0x2a3e60 movs r0, #0x0
 *   @0x2a3e64 bl 0x2a399c <zip_close+0x7b0>
 *   @0x2a3e68 ldrh r0, [r5, #0x4]
 *   @0x2a3e6c bl 0x2a39c8 <zip_close+0x7dc>
 *   @0x2a3e70 ldrh r0, [r5, #0x4]
 *   @0x2a3e74 bl 0x2a39c8 <zip_close+0x7dc>
 *   @0x2a3e78 ldr r0, [r5, #0x8]
 *   @0x2a3e7c bl 0x2a399c <zip_close+0x7b0>
 *   @0x2a3e80 ldr r0, [r5, #0xc]
 *   @0x2a3e84 bl 0x2a399c <zip_close+0x7b0>
 *   @0x2a3e88 ldrh r0, [r5, #0x14]
 *   @0x2a3e8c bl 0x2a39c8 <zip_close+0x7dc>
 *   @0x2a3e90 ldr r0, [r5, #0x10]
 *   @0x2a3e94 ldrh r2, [r5, #0x14]
 *   @0x2a3e98 blx 0xb68bc <fwrite@plt>
 *   @0x2a3e9c ldrh r0, [r4, #0xc]
 *   @0x2a3ea0 addlt r0, r0, #64
 *   @0x2a3ea4 cbz r0, 0x2a3eb8 <_Z15_zip_cdir_writeP8zip_cdirP7__sFILEP9zip_error+0xa8>
 *   @0x2a3ea8 smlatbhs r6, r8, lr, lr
 *   @0x2a3eac ldr r2, [r0]
 *   @0x2a3eb0 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii>
 *   @0x2a3eb4 mov.w r0, #0xffffffff
 *   @0x2a3eb8 pop.w {r4, r5, r6, r7, r8, pc}
 *   @0x2a3ebc strh r6, [r5, #0xc]
 *
 * ══ §154/168 png_set_iCCP  0x2aee48  size 176  44 条（0x2aee48..0x2aeef8）
 * @func 0x2aee48 0x2aeef8  size 176  44 条
 * 部分覆盖: 本节 44/76 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65bc / png_free_data
 * 字段偏移 top8: 0x2c×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2aee48 push.w {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2aee4c mov r4, r1
 *   @0x2aee50 mov r11, r3
 *   @0x2aee54 strmi r9, [r5], -r8, lsr #32
 *   @0x2aee58 ldr r6, [sp, #0x2c]
 *   @0x2aee5c beq 0x2aeeec <png_set_iCCP+0xa4>
 *   @0x2aee60 beq 0x2aeeec <png_set_iCCP+0xa4>
 *   @0x2aee64 beq 0x2aeeec <png_set_iCCP+0xa4>
 *   @0x2aee68 eorsle r0, pc, r0, lsl #30
 *   @0x2aee6c mov r0, r2
 *   @0x2aee70 .word 0xf100eb64
 *   @0x2aee74 strtmi r0, [r8], -r1, lsl #20
 *   @0x2aee78 mov r1, r10
 *   @0x2aee7c strmi pc, [r0], r12, asr #30
 *   @0x2aee80 cbnz r0, 0x2aee8a <png_set_iCCP+0x42>
 *   @0x2aee84 mov r0, r5
 *   @0x2aee88 b 0x2aeeac <png_set_iCCP+0x64>
 *   @0x2aee8c mov r2, r10
 *   @0x2aee90 qadd8mi lr, r8, r6
 *   @0x2aee94 mov r1, r6
 *   @0x2aee98 .word 0x4607ff3e
 *   @0x2aee9c cbnz r0, 0x2aeeb4 <png_set_iCCP+0x6c>
 *   @0x2aeea0 mov r1, r8
 *   @0x2aeea4 ldmdbmi r3, {r0, r1, r3, r5, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2aeea8 mov r0, r5
 *   @0x2aeeac pop.w {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2aeeb0 b.w 0x2a6474 <png_warning>
 *   @0x2aeeb4 mov r1, r9
 *   @0x2aeeb8 blx 0xb65bc <memcpy@plt>
 *   @0x2aeebc movs r3, #0x0
 *   @0x2aeec0 mov r1, r4
 *   @0x2aeec4 bl 0x2a5bc0 <png_free_data>
 *   @0x2aeec8 ldr.w r3, [r4, #0xb8]
 *   @0x2aeecc str.w r6, [r4, #0xcc]
 *   @0x2aeed0 orr r3, r3, #0x10
 *   @0x2aeed4 str.w r3, [r4, #0xb8]
 *   @0x2aeed8 ldr r3, [r4, #0x8]
 *   @0x2aeedc .word 0xf44380c4
 *   @0x2aeee0 .word 0xf8c45380
 *   @0x2aeee4 .word 0xf88470c8
 *   @0x2aeee8 .word 0x60a3b0d0
 *   @0x2aeeec pop.w {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2aeef0 ldc p0, c0, [r10, #-52]!
 *   @0x2aeef4 stcl p0, c0, [r0, #-52]
 *
 * ══ §155/168 DGifGetExtension(GifFileType*, int*, unsigned char**)  0x2c2348  size 176  44 条（0x2c2348..0x2c23f8）
 * @func 0x2c2348 0x2c23f8  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DGifGetExtensionNext(GifFileType*, unsigned char**) / 0xb68c8
 * 字段偏移 top8: 0x48×1 / 0x3c×1 / 0x40×1 / 0x7×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c2348 ldr r12, [r0, #0x48]
 *   @0x2c234c push {r4, r5, r6, lr}
 *   @0x2c2350 mov r6, r2
 *   @0x2c2354 ldr r3, [r12]
 *   @0x2c2358 sub sp, sp, #8
 *   @0x2c235c mov r4, r0
 *   @0x2c2360 mov r5, r1
 *   @0x2c2364 ands r3, r3, #8
 *   @0x2c2368 moveq r2, #111
 *   @0x2c236c streq r2, [r0, #0x40]
 *   @0x2c2370 beq 0x2c23a8 <_Z16DGifGetExtensionP11GifFileTypePiPPh+0x60>
 *   @0x2c2374 ldr r3, [r12, #0x3c]
 *   @0x2c2378 cmp r3, #0
 *   @0x2c237c beq 0x2c23d8 <_Z16DGifGetExtensionP11GifFileTypePiPPh+0x90>
 *   @0x2c2380 add r1, sp, #7
 *   @0x2c2384 mov r2, #1
 *   @0x2c2388 blx r3
 *   @0x2c238c subs r0, r0, #1
 *   @0x2c2390 movne r0, #1
 *   @0x2c2394 cmp r0, #0
 *   @0x2c2398 beq 0x2c23b4 <_Z16DGifGetExtensionP11GifFileTypePiPPh+0x6c>
 *   @0x2c239c mov r3, #0
 *   @0x2c23a0 mov r2, #102
 *   @0x2c23a4 str r2, [r4, #0x40]
 *   @0x2c23a8 mov r0, r3
 *   @0x2c23ac add sp, sp, #8
 *   @0x2c23b0 pop {r4, r5, r6, pc}
 *   @0x2c23b4 ldrb r3, [sp, #0x7]
 *   @0x2c23b8 mov r0, r4
 *   @0x2c23bc mov r1, r6
 *   @0x2c23c0 str r3, [r5]
 *   @0x2c23c4 bl 0x2c2270 <_Z20DGifGetExtensionNextP11GifFileTypePPh>
 *   @0x2c23c8 mov r3, r0
 *   @0x2c23cc mov r0, r3
 *   @0x2c23d0 add sp, sp, #8
 *   @0x2c23d4 pop {r4, r5, r6, pc}
 *   @0x2c23d8 mov r1, #1
 *   @0x2c23dc ldr r3, [r12, #0x38]
 *   @0x2c23e0 mov r2, r1
 *   @0x2c23e4 add r0, sp, #7
 *   @0x2c23e8 bl 0xb68c8 <fread@plt>
 *   @0x2c23ec subs r0, r0, #1
 *   @0x2c23f0 movne r0, #1
 *   @0x2c23f4 b 0x2c2394 <_Z16DGifGetExtensionP11GifFileTypePiPPh+0x4c>
 *
 * ══ §156/168 b2ChainShape::GetChildEdge(b2EdgeShape*, int) const  0x2c4bf4  size 176  44 条（0x2c4bf4..0x2c4ca4）
 * @func 0x2c4bf4 0x2c4ca4  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×2 / 0xc×1 / 0x4×1 / 0x10×1 / 0x2d×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c4bf4 push {r4, r5, r6, r7, r8, r9, r10}
 *   @0x2c4bf8 mov r3, r1
 *   @0x2c4bfc ldr r10, [r0, #0xc]
 *   @0x2c4c00 lsl r9, r2, #3
 *   @0x2c4c04 add r7, r1, #12
 *   @0x2c4c08 ldr r1, [r0, #0x8]
 *   @0x2c4c0c add r4, r10, r9
 *   @0x2c4c10 mov r12, r0
 *   @0x2c4c14 add r6, r4, #8
 *   @0x2c4c18 mov r8, #1
 *   @0x2c4c1c str r1, [r3, #0x8]
 *   @0x2c4c20 add r5, r3, #20
 *   @0x2c4c24 ldm r4, {r0, r1}
 *   @0x2c4c28 cmp r2, #0
 *   @0x2c4c2c str r8, [r3, #0x4]
 *   @0x2c4c30 addle r4, r3, #28
 *   @0x2c4c34 stm r7, {r0, r1}
 *   @0x2c4c38 ldm r6, {r0, r1}
 *   @0x2c4c3c stm r5, {r0, r1}
 *   @0x2c4c40 addle r1, r12, #20
 *   @0x2c4c44 ldmdbgt r4, {r0, r1}
 *   @0x2c4c48 addgt r4, r3, #28
 *   @0x2c4c4c ldmle r1, {r0, r1}
 *   @0x2c4c50 ldrble r5, [r12, #0x24]
 *   @0x2c4c54 stmgt r4, {r0, r1}
 *   @0x2c4c58 stmle r4, {r0, r1}
 *   @0x2c4c5c ldr r1, [r12, #0x10]
 *   @0x2c4c60 strbgt r8, [r3, #0x2c]
 *   @0x2c4c64 sub r1, r1, #2
 *   @0x2c4c68 strble r5, [r3, #0x2c]
 *   @0x2c4c6c cmp r2, r1
 *   @0x2c4c70 addlt r9, r10, r9
 *   @0x2c4c74 addge r1, r12, #28
 *   @0x2c4c78 addlt r9, r9, #16
 *   @0x2c4c7c ldrbge r12, [r12, #0x25]
 *   @0x2c4c80 ldmge r1, {r0, r1}
 *   @0x2c4c84 addlt r2, r3, #36
 *   @0x2c4c88 ldmlt r9, {r0, r1}
 *   @0x2c4c8c addge r2, r3, #36
 *   @0x2c4c90 movlt r12, #1
 *   @0x2c4c94 pop {r4, r5, r6, r7, r8, r9, r10}
 *   @0x2c4c98 stm r2, {r0, r1}
 *   @0x2c4c9c strb r12, [r3, #0x2d]
 *   @0x2c4ca0 bx lr
 *
 * ══ §157/168 b2EdgeShape::ComputeAABB(b2AABB*, b2Transform const&, int) const  0x2c5154  size 176  44 条（0x2c5154..0x2c5204）
 * @func 0x2c5154 0x2c5204  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 43 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c5154 vldr s10, [r2, #8]
 *   @0x2c5158 vldr s13, [r0, #16]
 *   @0x2c515c vldr s14, [r0, #24]
 *   @0x2c5160 vmul.f32 s11, s10, s13
 *   @0x2c5164 vldr s9, [r2, #12]
 *   @0x2c5168 vldr s5, [r0, #12]
 *   @0x2c516c vldr s6, [r0, #20]
 *   @0x2c5170 vldr s12, [r2]
 *   @0x2c5174 vldr s7, [r2, #4]
 *   @0x2c5178 vldr s15, [r0, #8]
 *   @0x2c517c vmul.f32 s8, s10, s14
 *   @0x2c5180 vmul.f32 s13, s9, s13
 *   @0x2c5184 vmul.f32 s14, s9, s14
 *   @0x2c5188 vnmls.f32 s11, s9, s5
 *   @0x2c518c vnmls.f32 s8, s9, s6
 *   @0x2c5190 vmla.f32 s13, s5, s10
 *   @0x2c5194 vmla.f32 s14, s10, s6
 *   @0x2c5198 vadd.f32 s11, s11, s12
 *   @0x2c519c vadd.f32 s12, s12, s8
 *   @0x2c51a0 vadd.f32 s13, s13, s7
 *   @0x2c51a4 vadd.f32 s14, s7, s14
 *   @0x2c51a8 vcmpe.f32 s11, s12
 *   @0x2c51ac vmrs APSR_nzcv, fpscr
 *   @0x2c51b0 vcmpe.f32 s13, s14
 *   @0x2c51b4 vmovpl.f32 s9, s12
 *   @0x2c51b8 vmovmi.f32 s9, s11
 *   @0x2c51bc vmrs APSR_nzcv, fpscr
 *   @0x2c51c0 vcmpe.f32 s11, s12
 *   @0x2c51c4 vmovpl.f32 s10, s14
 *   @0x2c51c8 vmovmi.f32 s10, s13
 *   @0x2c51cc vmrs APSR_nzcv, fpscr
 *   @0x2c51d0 vcmpe.f32 s13, s14
 *   @0x2c51d4 vmovgt.f32 s12, s11
 *   @0x2c51d8 vmrs APSR_nzcv, fpscr
 *   @0x2c51dc vmovgt.f32 s14, s13
 *   @0x2c51e0 vsub.f32 s11, s9, s15
 *   @0x2c51e4 vsub.f32 s13, s10, s15
 *   @0x2c51e8 vstr s11, [r1]
 *   @0x2c51ec vadd.f32 s12, s15, s12
 *   @0x2c51f0 vstr s13, [r1, #4]
 *   @0x2c51f4 vadd.f32 s15, s15, s14
 *   @0x2c51f8 vstr s12, [r1, #8]
 *   @0x2c51fc vstr s15, [r1, #12]
 *   @0x2c5200 bx lr
 *
 * ══ §158/168 anon_2c7f2c  0x2c7f2c  size 176  44 条（0x2c7f2c..0x2c7fdc）
 * @func 0x2c7f2c 0x2c7fdc  size 176  44 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2c7f2c+0x80 / void std::priv::__unguarded_linear_insert<b2Pair*, b2Pair, bool (*)(b2Pair const&, b2Pair const&)>(b2Pair*, b2Pair, bool (*)(b2Pair const&, b2Pair const&))
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c7f2c cmp r0, r1
 *   @0x2c7f30 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2c7f34 mov r7, r0
 *   @0x2c7f38 sub sp, sp, #12
 *   @0x2c7f3c mov r10, r1
 *   @0x2c7f40 mov r9, r2
 *   @0x2c7f44 beq 0x2c7fc4 <_ZNSt4priv25__unguarded_linear_insertIP6b2PairS1_PFbRKS1_S4_EEEvT_T0_T1_+0xf4>
 *   @0x2c7f48 add r11, r0, #8
 *   @0x2c7f4c cmp r1, r11
 *   @0x2c7f50 beq 0x2c7fc4 <_ZNSt4priv25__unguarded_linear_insertIP6b2PairS1_PFbRKS1_S4_EEEvT_T0_T1_+0xf4>
 *   @0x2c7f54 add r5, r0, #16
 *   @0x2c7f58 mov r6, sp
 *   @0x2c7f5c ldmdb r5, {r0, r1}
 *   @0x2c7f60 mov r8, r5
 *   @0x2c7f64 stm r6, {r0, r1}
 *   @0x2c7f68 mov r0, sp
 *   @0x2c7f6c mov r1, r7
 *   @0x2c7f70 blx r9
 *   @0x2c7f74 cmp r0, #0
 *   @0x2c7f78 beq 0x2c7fcc <_ZNSt4priv25__unguarded_linear_insertIP6b2PairS1_PFbRKS1_S4_EEEvT_T0_T1_+0xfc>
 *   @0x2c7f7c rsb r4, r7, r11
 *   @0x2c7f80 asr r4, r4, #3
 *   @0x2c7f84 cmp r4, #0
 *   @0x2c7f88 movgt r3, r5
 *   @0x2c7f8c ble 0x2c7fac <_ZNSt4priv25__unguarded_linear_insertIP6b2PairS1_PFbRKS1_S4_EEEvT_T0_T1_+0xdc>
 *   @0x2c7f90 sub r2, r3, #16
 *   @0x2c7f94 sub r12, r3, #8
 *   @0x2c7f98 subs r4, r4, #1
 *   @0x2c7f9c ldm r2, {r0, r1}
 *   @0x2c7fa0 mov r3, r12
 *   @0x2c7fa4 stm r12, {r0, r1}
 *   @0x2c7fa8 bne 0x2c7f90 <_ZNSt4priv25__unguarded_linear_insertIP6b2PairS1_PFbRKS1_S4_EEEvT_T0_T1_+0xc0>
 *   @0x2c7fac ldm r6, {r0, r1}
 *   @0x2c7fb0 stm r7, {r0, r1}
 *   @0x2c7fb4 cmp r10, r8
 *   @0x2c7fb8 add r11, r11, #8
 *   @0x2c7fbc add r5, r5, #8
 *   @0x2c7fc0 bne 0x2c7f5c <_ZNSt4priv25__unguarded_linear_insertIP6b2PairS1_PFbRKS1_S4_EEEvT_T0_T1_+0x8c>
 *   @0x2c7fc4 add sp, sp, #12
 *   @0x2c7fc8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2c7fcc mov r0, r11
 *   @0x2c7fd0 ldm r6, {r1, r2}
 *   @0x2c7fd4 mov r3, r9
 *   @0x2c7fd8 bl 0x2c7ed0 <_ZNSt4priv25__unguarded_linear_insertIP6b2PairS1_PFbRKS1_S4_EEEvT_T0_T1_>
 *
 * ══ §159/168 FT_Get_Sfnt_LangTag  0x2e87e8  size 176  44 条（0x2e87e8..0x2e8898）
 * @func 0x2e87e8 0x2e8898  size 176  44 条
 * 部分覆盖: 本节 44/81 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ft_mem_realloc / 0xff1b4888
 * 字段偏移 top8: 0x8×4 / 0xc×2 / 0x68×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e87e8 push.w {r4, r5, r6, r7, r8, r9, lr}
 *   @0x2e87ec sub sp, #0x14
 *   @0x2e87f0 mov r5, r0
 *   @0x2e87f4 mov r8, r2
 *   @0x2e87f8 cmp r2, #0x0
 *   @0x2e87fc cmp r0, #0x0
 *   @0x2e8800 ldr r2, [r0, #0x8]
 *   @0x2e8804 bpl 0x2e888c <FT_Get_Sfnt_LangTag+0xa4>
 *   @0x2e8808 stmdbhs r1, {r3, r4, r6, r8, r12}
 *   @0x2e880c bne 0x2e8890 <FT_Get_Sfnt_LangTag+0xa8>
 *   @0x2e8810 ldmdble r11!, {r8, r9, r10, r11, lr}
 *   @0x2e8814 ldr.w r2, [r5, #0x168]
 *   @0x2e8818 sub.w r0, r3, #0x8000
 *   @0x2e881c cmp r0, r2
 *   @0x2e8820 movs r6, #0xc
 *   @0x2e8824 cmpmi lr, #108, #2
 *   @0x2e8828 sub.w r6, r6, #0x60000
 *   @0x2e882c adds r4, r7, r6
 *   @0x2e8830 cbz r3, 0x2e887c <FT_Get_Sfnt_LangTag+0x94>
 *   @0x2e8834 cbnz r2, 0x2e887c <FT_Get_Sfnt_LangTag+0x94>
 *   @0x2e8838 stmdage r3, {r2, r5, r6, r12, pc}
 *   @0x2e883c ldr r5, [r5, #0x68]
 *   @0x2e8840 str r2, [sp]
 *   @0x2e8844 bl 0x2e808e <ft_mem_realloc>
 *   @0x2e8848 ldr r3, [sp, #0xc]
 *   @0x2e884c cbz r3, 0x2e885e <FT_Get_Sfnt_LangTag+0x76>
 *   @0x2e8850 ldr r1, [r4, #0x8]
 *   @0x2e8854 movwhs pc, #0xd70
 *   @0x2e8858 str r3, [r4, #0x8]
 *   @0x2e885c b 0x2e887c <FT_Get_Sfnt_LangTag+0x94>
 *   @0x2e8860 ldr r1, [r4, #0x4]
 *   @0x2e8864 andls pc, r3, r0, lsr #16
 *   @0x2e8868 cmp r0, #0x0
 *   @0x2e886c mov r0, r5
 *   @0x2e8870 ldrh r2, [r7, r6]
 *   @0x2e8874 andls pc, r3, r12, lsl #17
 *   @0x2e8878 cmp r0, #0x0
 *   @0x2e887c ldr r3, [r4, #0x8]
 *   @0x2e8880 blpl 0xff1b4888 <b2_toiTime+0xfffffffffea5b3e4>
 *   @0x2e8884 str.w r3, [r8, #0x4]
 *   @0x2e8888 movs r3, #0x0
 *   @0x2e888c ldr r0, [sp, #0xc]
 *   @0x2e8890 movs r0, #0x8
 *   @0x2e8894 pop.w {r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §160/168 _zip_file_fillbuf(void*, unsigned int, zip_file*)  0x2a44d6  size 174  44 条（0x2a44d6..0x2a4584）
 * @func 0x2a44d6 0x2a4586  size 176  44 条
 * 部分覆盖: 本节 44/84 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb68c8 / _zip_error_set(zip_error*, int, int)
 * 字段偏移 top8: 0x10×2 / 0x20×2 / 0x8×1 / 0x17×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a44d6 push.w {r3, r4, r5, r7, r8, lr}
 *   @0x2a44da mov r7, r0
 *   @0x2a44de mov r8, r1
 *   @0x2a44e2 cmp r5, #0x0
 *   @0x2a44e6 ldr r3, [r2, #0x10]
 *   @0x2a44ea bmi 0x2a457e <_Z17_zip_file_fillbufPvjP8zip_file+0xa8>
 *   @0x2a44ee cmp r3, #0x0
 *   @0x2a44f2 cmp r1, #0x0
 *   @0x2a44f6 ldr r3, [r2]
 *   @0x2a44fa cbz r0, 0x2a4514 <_Z17_zip_file_fillbufPvjP8zip_file+0x3e>
 *   @0x2a44fe mov r2, r5
 *   @0x2a4502 stmdahs r0, {r3, r5, r6, r7, r10, r11, sp, lr, pc}
 *   @0x2a4506 bge 0x2a4522 <_Z17_zip_file_fillbufPvjP8zip_file+0x4c>
 *   @0x2a450a .word 0x2104eb76
 *   @0x2a450e ldr r2, [r0]
 *   @0x2a4512 b 0x2a4544 <_Z17_zip_file_fillbufPvjP8zip_file+0x6e>
 *   @0x2a4516 cbz r0, 0x2a4522 <_Z17_zip_file_fillbufPvjP8zip_file+0x4c>
 *   @0x2a451a mov r1, r5
 *   @0x2a451e ldr r3, [r3, #0x10]
 *   @0x2a4522 ldr r2, [r4]
 *   @0x2a4526 cmp r8, r3
 *   @0x2a452a movhs r8, r3
 *   @0x2a452e cbz r3, 0x2a454a <_Z17_zip_file_fillbufPvjP8zip_file+0x74>
 *   @0x2a4532 movs r1, #0x1
 *   @0x2a4536 blx 0xb68c8 <fread@plt>
 *   @0x2a453a subs r5, r0, #0x0
 *   @0x2a453e adds r0, r4, #0x4
 *   @0x2a4542 movs r2, #0x0
 *   @0x2a4546 ands pc, r7, r8, lsl #30
 *   @0x2a454a ldr r0, [r2, #0x8]
 *   @0x2a454e mov r1, r7
 *   @0x2a4552 mov r3, r8
 *   @0x2a4556 strb lr, [pc, r2, lsr #23]!
 *   @0x2a455a bge 0x2a456c <_Z17_zip_file_fillbufPvjP8zip_file+0x96>
 *   @0x2a455e .word 0x2105eb4c
 *   @0x2a4562 ldr r2, [r0]
 *   @0x2a4566 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii>
 *   @0x2a456a b 0x2a457e <_Z17_zip_file_fillbufPvjP8zip_file+0xa8>
 *   @0x2a456e add r3, r5
 *   @0x2a4572 ldr r3, [r4, #0x20]
 *   @0x2a4576 str r3, [r4, #0x20]
 *   @0x2a457a mov.w r5, #0xffffffff
 *   @0x2a457e mov r0, r5
 *   @0x2a4582 push {r3, r4, r5, r7, r8, pc}
 *
 * ══ §161/168 _FreezeBuffer(Buffer_Vertex*)  0xca1a0  size 172  43 条（0xca1a0..0xca24c）
 * @func 0xca1a0 0xca24c  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / VertexBuffer::Init(int, int, int) / VertexBuffer::~VertexBuffer() / operator delete(void*) / VertexBuffer::UpdateFromBuffer(void*, int)
 * 字段偏移 top8: 0x30×5 / 0x20×3 / 0xc×2 / 0x28×2 / 0x1c×1 / 0x4×1 / 0x24×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xca1a0 push {r4, r5, r6, lr}
 *   @0xca1a4 mov r6, r0
 *   @0xca1a8 mov r0, #64
 *   @0xca1ac mov r4, #0
 *   @0xca1b0 bl 0x27c524 <_Znwj>
 *   @0xca1b4 mov r1, #0
 *   @0xca1b8 mov r3, r1
 *   @0xca1bc mov r5, #0
 *   @0xca1c0 ldr r2, [r6, #0x1c]
 *   @0xca1c4 str r1, [r0]
 *   @0xca1c8 str r1, [r0, #0x4]
 *   @0xca1cc str r1, [r0, #0xc]
 *   @0xca1d0 str r1, [r0, #0x20]
 *   @0xca1d4 str r1, [r0, #0x24]
 *   @0xca1d8 str r1, [r0, #0x2c]
 *   @0xca1dc str r1, [r0, #0x30]
 *   @0xca1e0 str r1, [r0, #0x28]
 *   @0xca1e4 str r1, [r0, #0x34]
 *   @0xca1e8 str r1, [r0, #0x8]
 *   @0xca1ec strd r4, r5, [r0, #56]
 *   @0xca1f0 ldr r1, [r6, #0x28]
 *   @0xca1f4 str r0, [r6, #0x30]
 *   @0xca1f8 bl 0x18378c <_ZN12VertexBuffer4InitEiii>
 *   @0xca1fc cmp r0, #0
 *   @0xca200 bne 0xca230 <_Z13_FreezeBufferP13Buffer_Vertex+0x90>
 *   @0xca204 ldr r4, [r6, #0x30]
 *   @0xca208 cmp r4, #0
 *   @0xca20c beq 0xca220 <_Z13_FreezeBufferP13Buffer_Vertex+0x80>
 *   @0xca210 mov r0, r4
 *   @0xca214 bl 0x18373c <_ZN12VertexBufferD2Ev>
 *   @0xca218 mov r0, r4
 *   @0xca21c bl 0x27d1d0 <_ZdlPv>
 *   @0xca220 mov r3, #0
 *   @0xca224 str r3, [r6, #0x30]
 *   @0xca228 strb r3, [r6, #0x20]
 *   @0xca22c pop {r4, r5, r6, pc}
 *   @0xca230 ldr r0, [r6, #0x30]
 *   @0xca234 ldr r1, [r6]
 *   @0xca238 ldr r2, [r6, #0xc]
 *   @0xca23c bl 0x1838c0 <_ZN12VertexBuffer16UpdateFromBufferEPvi>
 *   @0xca240 mov r3, #1
 *   @0xca244 strb r3, [r6, #0x20]
 *   @0xca248 pop {r4, r5, r6, pc}
 *
 * ══ §162/168 CExtensionFunction::Assign(CExtensionFunction*)  0xf4a0c  size 172  43 条（0xf4a0c..0xf4ab8）
 * @func 0xf4a0c 0xf4ab8  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYFree(void const*)×3 / YYStrDup(char const*)×3
 * 字段偏移 top8: 0x4×3 / 0x8×3 / 0x14×3 / 0x5c×3 / 0xc×2 / 0x10×2 / 0x58×2 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4a0c push {r4, r5, r6, lr}
 *   @0xf4a10 mov r4, r0
 *   @0xf4a14 ldr r0, [r0, #0x4]
 *   @0xf4a18 mov r5, r1
 *   @0xf4a1c cmp r0, #0
 *   @0xf4a20 beq 0xf4a28 <_ZN18CExtensionFunction6AssignEPS_+0x1c>
 *   @0xf4a24 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xf4a28 ldr r0, [r5, #0x4]
 *   @0xf4a2c bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xf4a30 ldr r3, [r4, #0x8]
 *   @0xf4a34 cmp r3, #0
 *   @0xf4a38 str r0, [r4, #0x4]
 *   @0xf4a3c beq 0xf4a48 <_ZN18CExtensionFunction6AssignEPS_+0x3c>
 *   @0xf4a40 mov r0, r3
 *   @0xf4a44 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xf4a48 ldr r0, [r5, #0x8]
 *   @0xf4a4c bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xf4a50 ldr r6, [r5, #0xc]
 *   @0xf4a54 ldr lr, [r5, #0x10]
 *   @0xf4a58 mov r12, r5
 *   @0xf4a5c ldr r1, [r5, #0x14]
 *   @0xf4a60 mov r2, r4
 *   @0xf4a64 mov r3, #16
 *   @0xf4a68 str r6, [r4, #0xc]
 *   @0xf4a6c str lr, [r4, #0x10]
 *   @0xf4a70 str r1, [r4, #0x14]
 *   @0xf4a74 str r0, [r4, #0x8]
 *   @0xf4a78 ldr lr, [r12, #0x18]
 *   @0xf4a7c subs r3, r3, #1
 *   @0xf4a80 add r12, r12, #4
 *   @0xf4a84 add r2, r2, #4
 *   @0xf4a88 str lr, [r2, #0x14]
 *   @0xf4a8c bne 0xf4a78 <_ZN18CExtensionFunction6AssignEPS_+0x6c>
 *   @0xf4a90 ldr r0, [r4, #0x5c]
 *   @0xf4a94 ldr r3, [r5, #0x58]
 *   @0xf4a98 cmp r0, #0
 *   @0xf4a9c str r3, [r4, #0x58]
 *   @0xf4aa0 beq 0xf4aa8 <_ZN18CExtensionFunction6AssignEPS_+0x9c>
 *   @0xf4aa4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xf4aa8 ldr r0, [r5, #0x5c]
 *   @0xf4aac bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xf4ab0 str r0, [r4, #0x5c]
 *   @0xf4ab4 pop {r4, r5, r6, pc}
 *
 * ══ §163/168 Font_ReplaceSpriteExt(int, int, char const*, bool, int)  0xfab0c  size 172  43 条（0xfab0c..0xfabb8）
 * @func 0xfab0c 0xfabb8  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Font_ReplaceSpriteExt(int, int, char const*, bool, int)+0x30 / Font_ReplaceSpriteExt(int, int, char const*, bool, int)+0x3c / operator new(unsigned int) / CFontGM::CFontGM(int, char const*, bool, int)
 * 字段偏移 top8: 0x4×3 / 0x80×1 / 0x60×1 / 0x28×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfab0c push {r4, r5, r6, r7, r8, r9, lr}
 *   @0xfab10 subs r4, r0, #0
 *   @0xfab14 sub sp, sp, #12
 *   @0xfab18 mov r8, r1
 *   @0xfab1c mov r7, r2
 *   @0xfab20 mov r6, r3
 *   @0xfab24 blt 0xfab3c <_Z21Font_ReplaceSpriteExtiiPKcbi+0x30>
 *   @0xfab28 ldr r12, [pc, #0x80]
 *   @0xfab2c ldr r12, [pc, r12]
 *   @0xfab30 ldr r0, [r12]
 *   @0xfab34 cmp r4, r0
 *   @0xfab38 blt 0xfab48 <_Z21Font_ReplaceSpriteExtiiPKcbi+0x3c>
 *   @0xfab3c mov r0, #0
 *   @0xfab40 add sp, sp, #12
 *   @0xfab44 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0xfab48 mov r0, #144
 *   @0xfab4c ldr r5, [pc, #0x60]
 *   @0xfab50 bl 0x27c524 <_Znwj>
 *   @0xfab54 ldr r3, [sp, #0x28]
 *   @0xfab58 mov r2, r7
 *   @0xfab5c mov r1, r8
 *   @0xfab60 str r3, [sp]
 *   @0xfab64 mov r3, r6
 *   @0xfab68 lsl r6, r4, #2
 *   @0xfab6c mov r9, r0
 *   @0xfab70 bl 0xf7270 <_ZN7CFontGMC2EiPKcbi>
 *   @0xfab74 ldr r5, [pc, r5]
 *   @0xfab78 ldr r3, [r5, #0x4]
 *   @0xfab7c add r2, r3, r6
 *   @0xfab80 ldr r0, [r3, r4, lsl #2]
 *   @0xfab84 cmp r0, #0
 *   @0xfab88 beq 0xfaba0 <_Z21Font_ReplaceSpriteExtiiPKcbi+0x94>
 *   @0xfab8c ldr r3, [r0]
 *   @0xfab90 ldr r3, [r3, #0x4]
 *   @0xfab94 blx r3
 *   @0xfab98 ldr r2, [r5, #0x4]
 *   @0xfab9c add r2, r2, r6
 *   @0xfaba0 mov r0, #1
 *   @0xfaba4 str r9, [r2]
 *   @0xfaba8 add sp, sp, #12
 *   @0xfabac pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0xfabb0 eoreq r3, pc, r4, lsr r3
 *   @0xfabb4 eoreq r3, pc, r8, ror #5
 *
 * ══ §164/168 F_DsPriorityRead(RValue&, CInstance*, CInstance*, int, RValue*)  0xfcfd0  size 172  43 条（0xfcfd0..0xfd07c）
 * @func 0xfcfd0 0xfd07c  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int) / YYGetString(RValue const*, int) / F_DsPriorityRead(RValue&, CInstance*, CInstance*, int, RValue*)+0x78 / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x18×1 / 0x58×1 / 0x48×1 / 0x4×1 / 0x2×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfcfd0 push {r3, r4, r5, r6, r7, lr}
 *   @0xfcfd4 mov r1, #0
 *   @0xfcfd8 ldr r5, [sp, #0x18]
 *   @0xfcfdc mov r6, r3
 *   @0xfcfe0 mov r0, r5
 *   @0xfcfe4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfcfe8 mov r1, #1
 *   @0xfcfec mov r4, r0
 *   @0xfcff0 mov r0, r5
 *   @0xfcff4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0xfcff8 cmp r6, #3
 *   @0xfcffc movne r2, #0
 *   @0xfd000 mov r7, r0
 *   @0xfd004 beq 0xfd05c <_Z16F_DsPriorityReadR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0xfd008 cmp r4, #0
 *   @0xfd00c blt 0xfd048 <_Z16F_DsPriorityReadR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0xfd010 ldr r3, [pc, #0x58]
 *   @0xfd014 ldr r3, [pc, r3]
 *   @0xfd018 ldr r3, [r3]
 *   @0xfd01c cmp r4, r3
 *   @0xfd020 bge 0xfd048 <_Z16F_DsPriorityReadR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0xfd024 ldr r3, [pc, #0x48]
 *   @0xfd028 ldr r3, [pc, r3]
 *   @0xfd02c ldr r3, [r3, #0x4]
 *   @0xfd030 ldr r0, [r3, r4, lsl #2]
 *   @0xfd034 cmp r0, #0
 *   @0xfd038 beq 0xfd048 <_Z16F_DsPriorityReadR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0xfd03c mov r1, r7
 *   @0xfd040 pop {r3, r4, r5, r6, r7, lr}
 *   @0xfd044 b 0x2098d0 <_ZN12CDS_Priority14ReadFromStringEPKcb>
 *   @0xfd048 ldr r0, [pc, #0x28]
 *   @0xfd04c mov r1, #0
 *   @0xfd050 pop {r3, r4, r5, r6, r7, lr}
 *   @0xfd054 add r0, pc, r0
 *   @0xfd058 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfd05c mov r0, r5
 *   @0xfd060 mov r1, #2
 *   @0xfd064 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0xfd068 mov r2, r0
 *   @0xfd06c b 0xfd008 <_Z16F_DsPriorityReadR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0xfd070 eoreq r0, pc, r0, ror #28
 *   @0xfd074 eoreq r0, pc, r0, asr lr
 *   @0xfd078 eoreq r10, r3, r8, lsr #23
 *
 * ══ §165/168 F_MpGridCreate(RValue&, CInstance*, CInstance*, int, RValue*)  0x108bc4  size 172  43 条（0x108bc4..0x108c70）
 * @func 0x108bc4 0x108c70  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×6 / Motion_Grid_Create(int, int, int, int, int, int)
 * 字段偏移 top8: 0x28×1 / 0xc×1 / 0x4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x108bc4 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x108bc8 sub sp, sp, #8
 *   @0x108bcc mov r5, r0
 *   @0x108bd0 mov r1, #0
 *   @0x108bd4 ldr r4, [sp, #0x28]
 *   @0x108bd8 str r1, [r0, #0xc]
 *   @0x108bdc mov r0, r4
 *   @0x108be0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x108be4 mov r1, #1
 *   @0x108be8 mov r6, r0
 *   @0x108bec mov r0, r4
 *   @0x108bf0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x108bf4 mov r1, #2
 *   @0x108bf8 mov r9, r0
 *   @0x108bfc mov r0, r4
 *   @0x108c00 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x108c04 mov r1, #3
 *   @0x108c08 mov r8, r0
 *   @0x108c0c mov r0, r4
 *   @0x108c10 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x108c14 mov r1, #4
 *   @0x108c18 mov r7, r0
 *   @0x108c1c mov r0, r4
 *   @0x108c20 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x108c24 mov r1, #5
 *   @0x108c28 mov r10, r0
 *   @0x108c2c mov r0, r4
 *   @0x108c30 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x108c34 mov r1, r9
 *   @0x108c38 mov r2, r8
 *   @0x108c3c mov r3, r7
 *   @0x108c40 str r10, [sp]
 *   @0x108c44 str r0, [sp, #0x4]
 *   @0x108c48 mov r0, r6
 *   @0x108c4c bl 0x199fc0 <_Z18Motion_Grid_Createiiiiii>
 *   @0x108c50 vmov s15, r0
 *   @0x108c54 vcvt.f64.s32 d7, s15
 *   @0x108c58 vmov r0, r1, d7
 *   @0x108c5c vmov r2, s14
 *   @0x108c60 mov r3, r1
 *   @0x108c64 stm r5, {r2, r3}
 *   @0x108c68 add sp, sp, #8
 *   @0x108c6c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ §166/168 YYGML_point_direction(float, float, float, float)  0x1119a4  size 172  43 条（0x1119a4..0x111a50）
 * @func 0x1119a4 0x111a50  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGML_point_direction(float, float, float, float)+0x40 / 0xb6778
 * 字段偏移 top8: 无
 * VFP 指令 28 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1119a4 vmov s12, r2
 *   @0x1119a8 vmov s13, r0
 *   @0x1119ac push {r3, lr}
 *   @0x1119b0 vsub.f32 s15, s12, s13
 *   @0x1119b4 vmov s12, r3
 *   @0x1119b8 vmov s13, r1
 *   @0x1119bc vcmp.f32 s15, #0
 *   @0x1119c0 vsub.f32 s14, s12, s13
 *   @0x1119c4 vmrs APSR_nzcv, fpscr
 *   @0x1119c8 bne 0x1119f4 <_Z21YYGML_point_directionffff+0x50>
 *   @0x1119cc vcmpe.f32 s14, #0
 *   @0x1119d0 vmrs APSR_nzcv, fpscr
 *   @0x1119d4 ble 0x1119e4 <_Z21YYGML_point_directionffff+0x40>
 *   @0x1119d8 vldr s15, [pc, #88]
 *   @0x1119dc vmov r0, s15
 *   @0x1119e0 pop {r3, pc}
 *   @0x1119e4 bmi 0x111a30 <_Z21YYGML_point_directionffff+0x8c>
 *   @0x1119e8 vldr s15, [pc, #76]
 *   @0x1119ec vmov r0, s15
 *   @0x1119f0 pop {r3, pc}
 *   @0x1119f4 vmov r1, s15
 *   @0x1119f8 vmov r0, s14
 *   @0x1119fc bl 0xb6778 <atan2f@plt>
 *   @0x111a00 vldr s15, [pc, #56]
 *   @0x111a04 vldr s14, [pc, #56]
 *   @0x111a08 vmov s12, r0
 *   @0x111a0c vmul.f32 s15, s12, s15
 *   @0x111a10 vdiv.f32 s15, s15, s14
 *   @0x111a14 vcmpe.f32 s15, #0
 *   @0x111a18 vmrs APSR_nzcv, fpscr
 *   @0x111a1c vldrhi s14, [pc, #36]
 *   @0x111a20 vsubhi.f32 s15, s14, s15
 *   @0x111a24 vnegls.f32 s15, s15
 *   @0x111a28 vmov r0, s15
 *   @0x111a2c pop {r3, pc}
 *   @0x111a30 vldr s15, [pc, #20]
 *   @0x111a34 b 0x1119dc <_Z21YYGML_point_directionffff+0x38>
 *   @0x111a38 orrmi r0, r7, #0
 *   @0x111a3c andeq r0, r0, r0
 *   @0x111a40 teqmi r4, #0
 *   @0x111a44 ldrdmi r0, r1, [r9], #-251
 *   @0x111a48 .word 0x43b40000
 *   @0x111a4c adcsmi r0, r4, #0
 *
 * ══ §167/168 date_is_valid(int, int, int)  0x117eec  size 172  43 条（0x117eec..0x117f98）
 * @func 0x117eec 0x117f98  size 172  43 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: date_is_valid(int, int, int)+0x9c×2 / is_leap_year(int)
 * 字段偏移 top8: 0x98×1 / 0x-34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x117eec push {r4, r5, r6, r7, lr}
 *   @0x117ef0 cmp r2, #0
 *   @0x117ef4 ldr r4, [pc, #0x98]
 *   @0x117ef8 mov r7, r0
 *   @0x117efc mov r6, r1
 *   @0x117f00 mov r5, r2
 *   @0x117f04 add r4, pc, r4
 *   @0x117f08 sub sp, sp, #60
 *   @0x117f0c add r12, sp, #4
 *   @0x117f10 ldm r4!, {r0, r1, r2, r3}
 *   @0x117f14 stm r12!, {r0, r1, r2, r3}
 *   @0x117f18 ldm r4!, {r0, r1, r2, r3}
 *   @0x117f1c stm r12!, {r0, r1, r2, r3}
 *   @0x117f20 ldm r4!, {r0, r1, r2, r3}
 *   @0x117f24 ldr r4, [r4]
 *   @0x117f28 stm r12!, {r0, r1, r2, r3}
 *   @0x117f2c str r4, [r12]
 *   @0x117f30 blt 0x117f88 <_Z13date_is_validiii+0x9c>
 *   @0x117f34 mov r0, r5
 *   @0x117f38 bl 0x117a5c <_Z12is_leap_yeari>
 *   @0x117f3c cmp r0, #0
 *   @0x117f40 movne r3, #29
 *   @0x117f44 strne r3, [sp, #0xc]
 *   @0x117f48 sub r3, r6, #1
 *   @0x117f4c cmp r3, #11
 *   @0x117f50 bhi 0x117f88 <_Z13date_is_validiii+0x9c>
 *   @0x117f54 cmp r7, #0
 *   @0x117f58 ble 0x117f88 <_Z13date_is_validiii+0x9c>
 *   @0x117f5c add r3, sp, #56
 *   @0x117f60 add r6, r3, r6, lsl #2
 *   @0x117f64 ldr r3, [r6, #-0x34]
 *   @0x117f68 cmp r7, r3
 *   @0x117f6c bgt 0x117f88 <_Z13date_is_validiii+0x9c>
 *   @0x117f70 movw r0, #0x7b1
 *   @0x117f74 cmp r5, r0
 *   @0x117f78 movle r0, #0
 *   @0x117f7c movgt r0, #1
 *   @0x117f80 add sp, sp, #60
 *   @0x117f84 pop {r4, r5, r6, r7, pc}
 *   @0x117f88 mov r0, #0
 *   @0x117f8c add sp, sp, #60
 *   @0x117f90 pop {r4, r5, r6, r7, pc}
 *   @0x117f94 eoreq r4, r4, r12, lsr r10
 *
 * ══ §168/168 F_BUFFER_Exists(RValue&, CInstance*, CInstance*, int, RValue*)  0xc5214  size 144  36 条（0xc5214..0xc52a4）
 * @func 0xc5214 0xc52a4  size 144  36 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0xc×2 / 0x4×2 / 0x10×1 / 0x2c×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc5214 push {r3, r4, r5, lr}
 *   @0xc5218 mov r3, #13
 *   @0xc521c ldr r1, [sp, #0x10]
 *   @0xc5220 mov r5, #0
 *   @0xc5224 str r3, [r0, #0xc]
 *   @0xc5228 mov r4, r0
 *   @0xc522c str r5, [r0]
 *   @0xc5230 ldr r3, [r1, #0xc]
 *   @0xc5234 str r5, [r0, #0x4]
 *   @0xc5238 cmp r3, #13
 *   @0xc523c pophi {r3, r4, r5, pc}
 *   @0xc5240 mov r0, #1
 *   @0xc5244 movw r2, #0x2483
 *   @0xc5248 lsl r3, r0, r3
 *   @0xc524c and r2, r3, r2
 *   @0xc5250 cmp r2, r5
 *   @0xc5254 popeq {r3, r4, r5, pc}
 *   @0xc5258 mov r0, r1
 *   @0xc525c mov r1, r5
 *   @0xc5260 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc5264 cmp r0, #0
 *   @0xc5268 poplt {r3, r4, r5, pc}
 *   @0xc526c ldr r3, [pc, #0x2c]
 *   @0xc5270 add r3, pc, r3
 *   @0xc5274 ldr r2, [r3]
 *   @0xc5278 cmp r0, r2
 *   @0xc527c popge {r3, r4, r5, pc}
 *   @0xc5280 ldr r3, [r3, #0x4]
 *   @0xc5284 ldr r3, [r3, r0, lsl #2]
 *   @0xc5288 cmp r3, r5
 *   @0xc528c strne r5, [r4]
 *   @0xc5290 movne r3, r5
 *   @0xc5294 movtne r3, #0x3ff0
 *   @0xc5298 strne r3, [r4, #0x4]
 *   @0xc529c pop {r3, r4, r5, pc}
 *   @0xc52a0 eorseq r4, r11, r4, lsr #29
 */
