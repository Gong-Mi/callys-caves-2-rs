/* cally 逆向卡：Reach_13 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 350 个函数｜锚点 2840 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/350 CDS_Stack::Add4GC  0x202d98  size 64  16 条（0x202d98..0x202dd8）
 * @func 0x202d98 0x202dd8  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RVALUE_GC_ADDROOT(RValue const*, CGCGeneration*)
 * 字段偏移 top8: 0x4×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x202d98 ldr r3, [r0, #0x4]
 *   @0x202d9c push {r4, r5, r6, lr}
 *   @0x202da0 cmp r3, #0
 *   @0x202da4 mov r5, r0
 *   @0x202da8 mov r6, r1
 *   @0x202dac pople {r4, r5, r6, pc}
 *   @0x202db0 mov r4, #0
 *   @0x202db4 ldr r0, [r5, #0xc]
 *   @0x202db8 mov r1, r6
 *   @0x202dbc add r0, r0, r4, lsl #4
 *   @0x202dc0 add r4, r4, #1
 *   @0x202dc4 bl 0x191bac <_Z17RVALUE_GC_ADDROOTPK6RValueP13CGCGeneration>
 *   @0x202dc8 ldr r3, [r5, #0x4]
 *   @0x202dcc cmp r3, r4
 *   @0x202dd0 bgt 0x202db4 <_ZN9CDS_Stack6Add4GCEP13CGCGeneration+0x1c>
 *   @0x202dd4 pop {r4, r5, r6, pc}
 *
 * ══ §2/350 CDS_Queue::Add4GC  0x202f20  size 64  16 条（0x202f20..0x202f60）
 * @func 0x202f20 0x202f60  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RVALUE_GC_ADDROOT(RValue const*, CGCGeneration*)
 * 字段偏移 top8: 0xc×2 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x202f20 ldr r3, [r0, #0xc]
 *   @0x202f24 push {r4, r5, r6, lr}
 *   @0x202f28 cmp r3, #0
 *   @0x202f2c mov r5, r0
 *   @0x202f30 mov r6, r1
 *   @0x202f34 pople {r4, r5, r6, pc}
 *   @0x202f38 mov r4, #0
 *   @0x202f3c ldr r0, [r5, #0x10]
 *   @0x202f40 mov r1, r6
 *   @0x202f44 add r0, r0, r4, lsl #4
 *   @0x202f48 add r4, r4, #1
 *   @0x202f4c bl 0x191bac <_Z17RVALUE_GC_ADDROOTPK6RValueP13CGCGeneration>
 *   @0x202f50 ldr r3, [r5, #0xc]
 *   @0x202f54 cmp r3, r4
 *   @0x202f58 bgt 0x202f3c <_ZN9CDS_Queue6Add4GCEP13CGCGeneration+0x1c>
 *   @0x202f5c pop {r4, r5, r6, pc}
 *
 * ══ §3/350 CDS_List::Add4GC  0x2030f4  size 64  16 条（0x2030f4..0x203134）
 * @func 0x2030f4 0x203134  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RVALUE_GC_ADDROOT(RValue const*, CGCGeneration*)
 * 字段偏移 top8: 0x4×2 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2030f4 ldr r3, [r0, #0x4]
 *   @0x2030f8 push {r4, r5, r6, lr}
 *   @0x2030fc cmp r3, #0
 *   @0x203100 mov r5, r0
 *   @0x203104 mov r6, r1
 *   @0x203108 pople {r4, r5, r6, pc}
 *   @0x20310c mov r4, #0
 *   @0x203110 ldr r0, [r5, #0xc]
 *   @0x203114 mov r1, r6
 *   @0x203118 add r0, r0, r4, lsl #4
 *   @0x20311c add r4, r4, #1
 *   @0x203120 bl 0x191bac <_Z17RVALUE_GC_ADDROOTPK6RValueP13CGCGeneration>
 *   @0x203124 ldr r3, [r5, #0x4]
 *   @0x203128 cmp r3, r4
 *   @0x20312c bgt 0x203110 <_ZN8CDS_List6Add4GCEP13CGCGeneration+0x1c>
 *   @0x203130 pop {r4, r5, r6, pc}
 *
 * ══ §4/350 MD5Init  0x2140d8  size 64  16 条（0x2140d8..0x214118）
 * @func 0x2140d8 0x214118  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1 / 0xc×1 / 0x10×1 / 0x14×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2140d8 movw r2, #0x2301
 *   @0x2140dc movw r3, #0xab89
 *   @0x2140e0 movt r2, #0x6745
 *   @0x2140e4 movt r3, #0xefcd
 *   @0x2140e8 str r2, [r0, #0x8]
 *   @0x2140ec movw r2, #0xdcfe
 *   @0x2140f0 str r3, [r0, #0xc]
 *   @0x2140f4 movt r2, #0x98ba
 *   @0x2140f8 movw r3, #0x5476
 *   @0x2140fc str r2, [r0, #0x10]
 *   @0x214100 movt r3, #0x1032
 *   @0x214104 str r3, [r0, #0x14]
 *   @0x214108 mov r3, #0
 *   @0x21410c str r3, [r0, #0x4]
 *   @0x214110 str r3, [r0]
 *   @0x214114 bx lr
 *
 * ══ §5/350 JS_IsDataDescriptor  0x2407e8  size 64  16 条（0x2407e8..0x240828）
 * @func 0x2407e8 0x24083c  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2407e8 ldr r3, [r0, #0xc]
 *   @0x2407ec mvn r2, #-16777216
 *   @0x2407f0 and r3, r3, r2
 *   @0x2407f4 cmp r3, r2
 *   @0x2407f8 beq 0x240820 <_Z19JS_IsDataDescriptorP6RValue+0x38>
 *   @0x2407fc cmp r3, #6
 *   @0x240800 beq 0x24080c <_Z19JS_IsDataDescriptorP6RValue+0x24>
 *   @0x240804 mov r0, #1
 *   @0x240808 bx lr
 *   @0x24080c ldr r3, [r0]
 *   @0x240810 ldr r0, [r3, #0x48]
 *   @0x240814 subs r0, r0, #2
 *   @0x240818 movne r0, #1
 *   @0x24081c bx lr
 *   @0x240820 mov r0, #0
 *   @0x240824 bx lr
 *
 * ══ §6/350 json_tokener_reset  0x27efb0  size 64  16 条（0x27efb0..0x27eff0）
 * @func 0x27efb0 0x27f004  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: json_tokener_reset+0x30 / anon_27ee08+0xbc
 * 字段偏移 top8: 0x8×2 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27efb0 push {r3, r4, r5, lr}
 *   @0x27efb4 subs r5, r0, #0
 *   @0x27efb8 popeq {r3, r4, r5, pc}
 *   @0x27efbc ldr r4, [r5, #0x8]
 *   @0x27efc0 cmp r4, #0
 *   @0x27efc4 blt 0x27efe0 <json_tokener_reset+0x30>
 *   @0x27efc8 mov r1, r4
 *   @0x27efcc mov r0, r5
 *   @0x27efd0 sub r4, r4, #1
 *   @0x27efd4 bl 0x27eec4 <json_object_array_get_idx+0xc4>
 *   @0x27efd8 cmn r4, #1
 *   @0x27efdc bne 0x27efc8 <json_tokener_reset+0x18>
 *   @0x27efe0 mov r3, #0
 *   @0x27efe4 str r3, [r5, #0x8]
 *   @0x27efe8 str r3, [r5, #0x18]
 *   @0x27efec pop {r3, r4, r5, pc}
 *
 * ══ §7/350 spBone_updateWorldTransform  0x285348  size 64  16 条（0x285348..0x285388）
 * @func 0x285348 0x28539c  size 84  21 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spBone_updateWorldTransformWith
 * 字段偏移 top8: 0x20×1 / 0x24×1 / 0x2c×1 / 0x28×1 / 0x14×1 / 0x18×1 / 0x1c×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x285348 push {r4, lr}
 *   @0x28534c sub sp, sp, #16
 *   @0x285350 ldr lr, [r0, #0x20]
 *   @0x285354 ldr r4, [r0, #0x24]
 *   @0x285358 ldr r12, [r0, #0x2c]
 *   @0x28535c str lr, [sp]
 *   @0x285360 ldr lr, [r0, #0x28]
 *   @0x285364 ldr r1, [r0, #0x14]
 *   @0x285368 ldr r2, [r0, #0x18]
 *   @0x28536c ldr r3, [r0, #0x1c]
 *   @0x285370 str r4, [sp, #0x4]
 *   @0x285374 str lr, [sp, #0x8]
 *   @0x285378 str r12, [sp, #0xc]
 *   @0x28537c bl 0x284f18 <spBone_updateWorldTransformWith>
 *   @0x285380 add sp, sp, #16
 *   @0x285384 pop {r4, pc}
 *
 * ══ §8/350 spBone_setToSetupPose  0x285388  size 64  16 条（0x285388..0x2853c8）
 * @func 0x285388 0x2853c8  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×2 / 0x18×2 / 0x1c×2 / 0x20×2 / 0x24×2 / 0x28×2 / 0x10×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x285388 ldr r3, [r0]
 *   @0x28538c ldr r1, [r3, #0x10]
 *   @0x285390 ldr r2, [r3, #0x14]
 *   @0x285394 str r1, [r0, #0x14]
 *   @0x285398 str r2, [r0, #0x18]
 *   @0x28539c ldr r1, [r3, #0x18]
 *   @0x2853a0 ldr r2, [r3, #0x1c]
 *   @0x2853a4 str r1, [r0, #0x1c]
 *   @0x2853a8 str r2, [r0, #0x20]
 *   @0x2853ac ldr r1, [r3, #0x20]
 *   @0x2853b0 ldr r2, [r3, #0x24]
 *   @0x2853b4 ldr r3, [r3, #0x28]
 *   @0x2853b8 str r1, [r0, #0x24]
 *   @0x2853bc str r2, [r0, #0x28]
 *   @0x2853c0 str r3, [r0, #0x2c]
 *   @0x2853c4 bx lr
 *
 * ══ §9/350 spSlot_create  0x28eeec  size 64  16 条（0x28eeec..0x28ef2c）
 * @func 0x28eeec 0x28ef2c  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _calloc / spSlot_setToSetupPose
 * 字段偏移 top8: 0x34×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28eeec ldr r2, [pc, #0x34]
 *   @0x28eef0 mov r3, #41
 *   @0x28eef4 push {r4, r5, r6, lr}
 *   @0x28eef8 add r2, pc, r2
 *   @0x28eefc mov r6, r0
 *   @0x28ef00 mov r5, r1
 *   @0x28ef04 mov r0, #1
 *   @0x28ef08 mov r1, #44
 *   @0x28ef0c bl 0x285c4c <_calloc>
 *   @0x28ef10 mov r4, r0
 *   @0x28ef14 str r6, [r0]
 *   @0x28ef18 str r5, [r0, #0x4]
 *   @0x28ef1c bl 0x28ee80 <spSlot_setToSetupPose>
 *   @0x28ef20 mov r0, r4
 *   @0x28ef24 pop {r4, r5, r6, pc}
 *   @0x28ef28 andeq r9, r12, r4, asr #1
 *
 * ══ §10/350 __extendsfdf2  0x319110  size 64  16 条（0x319110..0x319150）
 * @func 0x319110 0x319150  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x319110 lsls r2, r0, #1
 *   @0x319114 asr r1, r2, #3
 *   @0x319118 rrx r1, r1
 *   @0x31911c lsl r0, r2, #28
 *   @0x319120 andsne r3, r2, #-16777216
 *   @0x319124 teqne r3, #-16777216
 *   @0x319128 eorne r1, r1, #939524096
 *   @0x31912c bxne lr
 *   @0x319130 teq r2, #0
 *   @0x319134 teqne r3, #-16777216
 *   @0x319138 bxeq lr
 *   @0x31913c push {r4, r5, lr}
 *   @0x319140 mov r4, #896
 *   @0x319144 and r5, r1, #-2147483648
 *   @0x319148 bic r1, r1, #-2147483648
 *   @0x31914c b 0x318f60 <__aeabi_dadd+0x148>
 *
 * ══ §11/350 IBuffer::GetPOW2Alignment  0xcc958  size 60  15 条（0xcc958..0xcc994）
 * @func 0xcc958 0xcc994  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IBuffer::GetPOW2Alignment(int)+0x34 / IBuffer::GetPOW2Alignment(int)+0x2c
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcc958 cmp r0, #1
 *   @0xcc95c ble 0xcc98c <_ZN7IBuffer16GetPOW2AlignmentEi+0x34>
 *   @0xcc960 mov r2, #10
 *   @0xcc964 mov r3, #2
 *   @0xcc968 cmp r0, r3
 *   @0xcc96c ble 0xcc984 <_ZN7IBuffer16GetPOW2AlignmentEi+0x2c>
 *   @0xcc970 subs r2, r2, #1
 *   @0xcc974 lsl r3, r3, #1
 *   @0xcc978 bne 0xcc968 <_ZN7IBuffer16GetPOW2AlignmentEi+0x10>
 *   @0xcc97c mov r0, #1024
 *   @0xcc980 bx lr
 *   @0xcc984 mov r0, r3
 *   @0xcc988 bx lr
 *   @0xcc98c mov r0, #1
 *   @0xcc990 bx lr
 *
 * ══ §12/350 YYSetScriptRef  0xdc3b0  size 60  15 条（0xdc3b0..0xdc3ec）
 * @func 0xdc3b0 0xdc3ec  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / CScriptRef::CScriptRef(int, int)
 * 字段偏移 top8: 0xc×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xdc3b0 push {r3, r4, r5, lr}
 *   @0xdc3b4 mov r4, r0
 *   @0xdc3b8 mov r3, #6
 *   @0xdc3bc mov r0, #156
 *   @0xdc3c0 str r3, [r4, #0xc]
 *   @0xdc3c4 bl 0x27c524 <_Znwj>
 *   @0xdc3c8 ldr r3, [pc, #0x18]
 *   @0xdc3cc mvn r2, #-16777216
 *   @0xdc3d0 ldr r3, [pc, r3]
 *   @0xdc3d4 ldr r1, [r3]
 *   @0xdc3d8 mov r5, r0
 *   @0xdc3dc bl 0x191de0 <_ZN10CScriptRefC2Eii>
 *   @0xdc3e0 str r5, [r4]
 *   @0xdc3e4 pop {r3, r4, r5, pc}
 *   @0xdc3e8 eorseq r1, r1, r4, asr #18
 *
 * ══ §13/350 WriteString  0x159604  size 60  15 条（0x159604..0x159640）
 * @func 0x159604 0x159640  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538 / 0xb65bc
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x159604 push {r4, r5, r6, lr}
 *   @0x159608 mov r4, r2
 *   @0x15960c mov r6, r1
 *   @0x159610 mov r5, r0
 *   @0x159614 bl 0xb6538 <strlen@plt>
 *   @0x159618 ldr r3, [r4]
 *   @0x15961c mov r1, r5
 *   @0x159620 add r5, r0, #1
 *   @0x159624 add r0, r6, r3
 *   @0x159628 mov r2, r5
 *   @0x15962c bl 0xb65bc <memcpy@plt>
 *   @0x159630 ldr r3, [r4]
 *   @0x159634 add r5, r3, r5
 *   @0x159638 str r5, [r4]
 *   @0x15963c pop {r4, r5, r6, pc}
 *
 * ══ §14/350 CCamera::GetProjMat  0x16d134  size 60  15 条（0x16d134..0x16d170）
 * @func 0x16d134 0x16d184  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d134 push {r4, r5}
 *   @0x16d138 add r4, r1, #4
 *   @0x16d13c mov r5, r0
 *   @0x16d140 mov r12, r0
 *   @0x16d144 ldm r4!, {r0, r1, r2, r3}
 *   @0x16d148 stm r12!, {r0, r1, r2, r3}
 *   @0x16d14c ldm r4!, {r0, r1, r2, r3}
 *   @0x16d150 stm r12!, {r0, r1, r2, r3}
 *   @0x16d154 ldm r4!, {r0, r1, r2, r3}
 *   @0x16d158 stm r12!, {r0, r1, r2, r3}
 *   @0x16d15c ldm r4, {r0, r1, r2, r3}
 *   @0x16d160 stm r12, {r0, r1, r2, r3}
 *   @0x16d164 mov r0, r5
 *   @0x16d168 pop {r4, r5}
 *   @0x16d16c bx lr
 *
 * ══ §15/350 CCamera::GetViewMat  0x16d170  size 60  15 条（0x16d170..0x16d1ac）
 * @func 0x16d170 0x16d1ac  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d170 push {r4, r5}
 *   @0x16d174 add r4, r1, #68
 *   @0x16d178 mov r5, r0
 *   @0x16d17c mov r12, r0
 *   @0x16d180 ldm r4!, {r0, r1, r2, r3}
 *   @0x16d184 stm r12!, {r0, r1, r2, r3}
 *   @0x16d188 ldm r4!, {r0, r1, r2, r3}
 *   @0x16d18c stm r12!, {r0, r1, r2, r3}
 *   @0x16d190 ldm r4!, {r0, r1, r2, r3}
 *   @0x16d194 stm r12!, {r0, r1, r2, r3}
 *   @0x16d198 ldm r4, {r0, r1, r2, r3}
 *   @0x16d19c stm r12, {r0, r1, r2, r3}
 *   @0x16d1a0 mov r0, r5
 *   @0x16d1a4 pop {r4, r5}
 *   @0x16d1a8 bx lr
 *
 * ══ §16/350 CCamera::GetInvViewProjMat  0x16d260  size 60  15 条（0x16d260..0x16d29c）
 * @func 0x16d260 0x16d2b0  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d260 push {r4, r5}
 *   @0x16d264 add r4, r1, #324
 *   @0x16d268 mov r5, r0
 *   @0x16d26c mov r12, r0
 *   @0x16d270 ldm r4!, {r0, r1, r2, r3}
 *   @0x16d274 stm r12!, {r0, r1, r2, r3}
 *   @0x16d278 ldm r4!, {r0, r1, r2, r3}
 *   @0x16d27c stm r12!, {r0, r1, r2, r3}
 *   @0x16d280 ldm r4!, {r0, r1, r2, r3}
 *   @0x16d284 stm r12!, {r0, r1, r2, r3}
 *   @0x16d288 ldm r4, {r0, r1, r2, r3}
 *   @0x16d28c stm r12, {r0, r1, r2, r3}
 *   @0x16d290 mov r0, r5
 *   @0x16d294 pop {r4, r5}
 *   @0x16d298 bx lr
 *
 * ══ §17/350 _SetTextureNPOTFlags  0x180aec  size 60  15 条（0x180aec..0x180b28）
 * @func 0x180aec 0x180b28  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _IsPowerOfTwo(int)×2
 * 字段偏移 top8: 0x10×2 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x180aec push {r4, lr}
 *   @0x180af0 mov r4, r0
 *   @0x180af4 ldr r0, [r0, #0x4]
 *   @0x180af8 bl 0x180ad0 <_Z13_IsPowerOfTwoi>
 *   @0x180afc cmp r0, #0
 *   @0x180b00 bne 0x180b14 <_Z20_SetTextureNPOTFlagsP7Texture+0x28>
 *   @0x180b04 ldr r3, [r4, #0x10]
 *   @0x180b08 orr r3, r3, #4
 *   @0x180b0c str r3, [r4, #0x10]
 *   @0x180b10 pop {r4, pc}
 *   @0x180b14 ldr r0, [r4, #0x8]
 *   @0x180b18 bl 0x180ad0 <_Z13_IsPowerOfTwoi>
 *   @0x180b1c cmp r0, #0
 *   @0x180b20 popne {r4, pc}
 *   @0x180b24 b 0x180b04 <_Z20_SetTextureNPOTFlagsP7Texture+0x18>
 *
 * ══ §18/350 SetTransformUniforms  0x184230  size 60  15 条（0x184230..0x18426c）
 * @func 0x184230 0x18426c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x3c×1 / 0x1c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x184230 ldr r0, [r0, #0x3c]
 *   @0x184234 push {r3, lr}
 *   @0x184238 cmn r0, #1
 *   @0x18423c popeq {r3, pc}
 *   @0x184240 ldr r12, [pc, #0x1c]
 *   @0x184244 mov r1, #5
 *   @0x184248 ldr r3, [pc, #0x18]
 *   @0x18424c mov r2, #0
 *   @0x184250 ldr r12, [pc, r12]
 *   @0x184254 ldr r3, [pc, r3]
 *   @0x184258 ldr r12, [r12]
 *   @0x18425c blx r12
 *   @0x184260 pop {r3, pc}
 *   @0x184264 eoreq r9, r6, r12, ror #11
 *   @0x184268 eoreq r12, r6, r0, lsr #4
 *
 * ══ §19/350 IO_Button_Down  0x18c0b4  size 60  15 条（0x18c0b4..0x18c0f0）
 * @func 0x18c0b4 0x18c104  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1 / 0x-1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18c0b4 sub r3, r0, #1
 *   @0x18c0b8 cmp r3, #2
 *   @0x18c0bc bhi 0x18c0e4 <_Z14IO_Button_Downii+0x30>
 *   @0x18c0c0 cmp r1, #9
 *   @0x18c0c4 bhi 0x18c0e4 <_Z14IO_Button_Downii+0x30>
 *   @0x18c0c8 ldr r3, [pc, #0x1c]
 *   @0x18c0cc add r1, r1, r1, lsl #1
 *   @0x18c0d0 ldr r3, [pc, r3]
 *   @0x18c0d4 add r3, r3, r1
 *   @0x18c0d8 add r0, r3, r0
 *   @0x18c0dc ldrb r0, [r0, #-0x1]
 *   @0x18c0e0 bx lr
 *   @0x18c0e4 mov r0, #0
 *   @0x18c0e8 bx lr
 *   @0x18c0ec eoreq r4, r6, r4, lsr #10
 *
 * ══ §20/350 IO_Button_Pressed  0x18c0f0  size 60  15 条（0x18c0f0..0x18c12c）
 * @func 0x18c0f0 0x18c140  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1 / 0x-1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18c0f0 sub r3, r0, #1
 *   @0x18c0f4 cmp r3, #2
 *   @0x18c0f8 bhi 0x18c120 <_Z17IO_Button_Pressedii+0x30>
 *   @0x18c0fc cmp r1, #9
 *   @0x18c100 bhi 0x18c120 <_Z17IO_Button_Pressedii+0x30>
 *   @0x18c104 ldr r3, [pc, #0x1c]
 *   @0x18c108 add r1, r1, r1, lsl #1
 *   @0x18c10c ldr r3, [pc, r3]
 *   @0x18c110 add r3, r3, r1
 *   @0x18c114 add r0, r3, r0
 *   @0x18c118 ldrb r0, [r0, #-0x1]
 *   @0x18c11c bx lr
 *   @0x18c120 mov r0, #0
 *   @0x18c124 bx lr
 *   @0x18c128 .word 0x002644f0
 *
 * ══ §21/350 IO_Button_Released  0x18c12c  size 60  15 条（0x18c12c..0x18c168）
 * @func 0x18c12c 0x18c17c  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1 / 0x-1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18c12c sub r3, r0, #1
 *   @0x18c130 cmp r3, #2
 *   @0x18c134 bhi 0x18c15c <_Z18IO_Button_Releasedii+0x30>
 *   @0x18c138 cmp r1, #9
 *   @0x18c13c bhi 0x18c15c <_Z18IO_Button_Releasedii+0x30>
 *   @0x18c140 ldr r3, [pc, #0x1c]
 *   @0x18c144 add r1, r1, r1, lsl #1
 *   @0x18c148 ldr r3, [pc, r3]
 *   @0x18c14c add r3, r3, r1
 *   @0x18c150 add r0, r3, r0
 *   @0x18c154 ldrb r0, [r0, #-0x1]
 *   @0x18c158 bx lr
 *   @0x18c15c mov r0, #0
 *   @0x18c160 bx lr
 *   @0x18c164 .word 0x002644b0
 *
 * ══ §22/350 Room_Name  0x1b530c  size 60  15 条（0x1b530c..0x1b5348）
 * @func 0x1b530c 0x1b5348  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Room_Exists(int)
 * 字段偏移 top8: 0x18×1 / 0xc×1 / 0x2×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b530c push {r4, lr}
 *   @0x1b5310 mov r4, r0
 *   @0x1b5314 bl 0x1b52f8 <_Z11Room_Existsi>
 *   @0x1b5318 cmp r0, #0
 *   @0x1b531c beq 0x1b5334 <_Z9Room_Namei+0x28>
 *   @0x1b5320 ldr r3, [pc, #0x18]
 *   @0x1b5324 add r3, pc, r3
 *   @0x1b5328 ldr r3, [r3, #0xc]
 *   @0x1b532c ldr r0, [r3, r4, lsl #2]
 *   @0x1b5330 pop {r4, pc}
 *   @0x1b5334 ldr r0, [pc, #0x8]
 *   @0x1b5338 add r0, pc, r0
 *   @0x1b533c pop {r4, pc}
 *   @0x1b5340 eorseq sp, r8, r4, lsr #5
 *   @0x1b5344 andseq r11, r7, r8, lsl #15
 *
 * ══ §23/350 IsPathDelimiter  0x21503c  size 60  15 条（0x21503c..0x215078）
 * @func 0x21503c 0x21508c  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IsPathDelimiter(char const*, int)+0x34 / 0xb6538
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21503c push {r3, r4, r5, lr}
 *   @0x215040 subs r4, r1, #0
 *   @0x215044 mov r5, r0
 *   @0x215048 ble 0x215070 <_Z15IsPathDelimiterPKci+0x34>
 *   @0x21504c bl 0xb6538 <strlen@plt>
 *   @0x215050 cmp r4, r0
 *   @0x215054 bge 0x215070 <_Z15IsPathDelimiterPKci+0x34>
 *   @0x215058 ldrb r0, [r5, r4]
 *   @0x21505c cmp r0, #92
 *   @0x215060 cmpne r0, #47
 *   @0x215064 movne r0, #0
 *   @0x215068 moveq r0, #1
 *   @0x21506c pop {r3, r4, r5, pc}
 *   @0x215070 mov r0, #0
 *   @0x215074 pop {r3, r4, r5, pc}
 *
 * ══ §24/350 ExcludeTrailingPathDelimiter  0x215078  size 60  15 条（0x215078..0x2150b4）
 * @func 0x215078 0x2150b4  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538×2 / IsPathDelimiter(char const*, int)
 * 字段偏移 top8: 0x-1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x215078 push {r4, lr}
 *   @0x21507c mov r4, r0
 *   @0x215080 bl 0xb6538 <strlen@plt>
 *   @0x215084 sub r1, r0, #1
 *   @0x215088 mov r0, r4
 *   @0x21508c bl 0x21503c <_Z15IsPathDelimiterPKci>
 *   @0x215090 cmp r0, #0
 *   @0x215094 beq 0x2150ac <_Z28ExcludeTrailingPathDelimiterPKc+0x34>
 *   @0x215098 mov r0, r4
 *   @0x21509c bl 0xb6538 <strlen@plt>
 *   @0x2150a0 mov r3, #0
 *   @0x2150a4 add r0, r4, r0
 *   @0x2150a8 strb r3, [r0, #-0x1]
 *   @0x2150ac mov r0, r4
 *   @0x2150b0 pop {r4, pc}
 *
 * ══ §25/350 ogg_sync_wrote  0x234c54  size 60  15 条（0x234c54..0x234c90）
 * @func 0x234c54 0x234c90  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ogg_sync_check
 * 字段偏移 top8: 0x8×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x234c54 push {r3, r4, r5, lr}
 *   @0x234c58 mov r5, r1
 *   @0x234c5c mov r4, r0
 *   @0x234c60 bl 0x234b80 <ogg_sync_check>
 *   @0x234c64 cmp r0, #0
 *   @0x234c68 bne 0x234c88 <ogg_sync_wrote+0x34>
 *   @0x234c6c ldr r1, [r4, #0x8]
 *   @0x234c70 ldr r3, [r4, #0x4]
 *   @0x234c74 add r1, r5, r1
 *   @0x234c78 cmp r1, r3
 *   @0x234c7c bgt 0x234c88 <ogg_sync_wrote+0x34>
 *   @0x234c80 str r1, [r4, #0x8]
 *   @0x234c84 pop {r3, r4, r5, pc}
 *   @0x234c88 mvn r0, #0
 *   @0x234c8c pop {r3, r4, r5, pc}
 *
 * ══ §26/350 json_tokener_parse  0x28075c  size 60  15 条（0x28075c..0x280798）
 * @func 0x28075c 0x280798  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: json_tokener_new / json_tokener_parse_ex / json_tokener_free
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28075c push {r3, r4, r5, lr}
 *   @0x280760 mov r5, r0
 *   @0x280764 bl 0x27eff0 <json_tokener_new>
 *   @0x280768 mov r1, r5
 *   @0x28076c mvn r2, #0
 *   @0x280770 mov r4, r0
 *   @0x280774 bl 0x27f048 <json_tokener_parse_ex>
 *   @0x280778 ldr r3, [r4, #0x18]
 *   @0x28077c cmp r3, #0
 *   @0x280780 mov r5, r0
 *   @0x280784 rsbne r5, r3, #0
 *   @0x280788 mov r0, r4
 *   @0x28078c bl 0x27f020 <json_tokener_free>
 *   @0x280790 mov r0, r5
 *   @0x280794 pop {r3, r4, r5, pc}
 *
 * ══ §27/350 _malloc  0x285c10  size 60  15 条（0x285c10..0x285c4c）
 * @func 0x285c10 0x285c60  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x28×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x285c10 push {r3, lr}
 *   @0x285c14 ldr r3, [pc, #0x28]
 *   @0x285c18 add r3, pc, r3
 *   @0x285c1c ldr r3, [r3]
 *   @0x285c20 cmp r3, #0
 *   @0x285c24 beq 0x285c30 <_malloc+0x20>
 *   @0x285c28 blx r3
 *   @0x285c2c pop {r3, pc}
 *   @0x285c30 ldr r3, [pc, #0x10]
 *   @0x285c34 add r3, pc, r3
 *   @0x285c38 ldr r3, [r3]
 *   @0x285c3c blx r3
 *   @0x285c40 pop {r3, pc}
 *   @0x285c44 subeq r0, sp, r4, lsr #31
 *   @0x285c48 andseq r1, r7, r4, asr r11
 *
 * ══ §28/350 yySocket::CommonDestructor  0x296044  size 60  15 条（0x296044..0x296080）
 * @func 0x296044 0x296080  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2
 * 字段偏移 top8: 0x50×2 / 0x60×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x296044 push {r4, lr}
 *   @0x296048 mov r4, r0
 *   @0x29604c ldr r0, [r0, #0x50]
 *   @0x296050 cmp r0, #0
 *   @0x296054 beq 0x296064 <_ZN8yySocket16CommonDestructorEv+0x20>
 *   @0x296058 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x29605c mov r3, #0
 *   @0x296060 str r3, [r4, #0x50]
 *   @0x296064 ldr r0, [r4, #0x60]
 *   @0x296068 cmp r0, #0
 *   @0x29606c popeq {r4, pc}
 *   @0x296070 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x296074 mov r3, #0
 *   @0x296078 str r3, [r4, #0x60]
 *   @0x29607c pop {r4, pc}
 *
 * ══ §29/350 RelyFindPacket  0x299b60  size 60  15 条（0x299b60..0x299b9c）
 * @func 0x299b60 0x299b9c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x30×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x299b60 ldr r3, [pc, #0x30]
 *   @0x299b64 ldr r3, [pc, r3]
 *   @0x299b68 ldr r3, [r3]
 *   @0x299b6c cmp r3, #0
 *   @0x299b70 bne 0x299b84 <_Z14RelyFindPacketi+0x24>
 *   @0x299b74 b 0x299b90 <_Z14RelyFindPacketi+0x30>
 *   @0x299b78 ldr r3, [r3, #0x20]
 *   @0x299b7c cmp r3, #0
 *   @0x299b80 beq 0x299b90 <_Z14RelyFindPacketi+0x30>
 *   @0x299b84 ldr r2, [r3]
 *   @0x299b88 cmp r2, r0
 *   @0x299b8c bne 0x299b78 <_Z14RelyFindPacketi+0x18>
 *   @0x299b90 mov r0, r3
 *   @0x299b94 bx lr
 *   @0x299b98 mulseq r5, r0, lr
 *
 * ══ §30/350 b2ChainShape::CreateChain  0x2c4ae0  size 60  15 条（0x2c4ae0..0x2c4b1c）
 * @func 0x2c4ae0 0x2c4b1c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Alloc(int) / 0xb65bc
 * 字段偏移 top8: 0x10×2 / 0xc×1 / 0x24×1 / 0x25×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c4ae0 push {r3, r4, r5, lr}
 *   @0x2c4ae4 mov r4, r0
 *   @0x2c4ae8 str r2, [r4, #0x10]
 *   @0x2c4aec lsl r0, r2, #3
 *   @0x2c4af0 mov r5, r1
 *   @0x2c4af4 bl 0x2c6a6c <_Z7b2Alloci>
 *   @0x2c4af8 ldr r2, [r4, #0x10]
 *   @0x2c4afc mov r1, r5
 *   @0x2c4b00 lsl r2, r2, #3
 *   @0x2c4b04 str r0, [r4, #0xc]
 *   @0x2c4b08 bl 0xb65bc <memcpy@plt>
 *   @0x2c4b0c mov r3, #0
 *   @0x2c4b10 strb r3, [r4, #0x24]
 *   @0x2c4b14 strb r3, [r4, #0x25]
 *   @0x2c4b18 pop {r3, r4, r5, pc}
 *
 * ══ §31/350 b2BlockAllocator::Free  0x2c6710  size 60  15 条（0x2c6710..0x2c674c）
 * @func 0x2c6710 0x2c674c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c6710 cmp r2, #0
 *   @0x2c6714 bxeq lr
 *   @0x2c6718 cmp r2, #640
 *   @0x2c671c bgt 0x2c6740 <_ZN16b2BlockAllocator4FreeEPvi+0x30>
 *   @0x2c6720 ldr r3, [pc, #0x20]
 *   @0x2c6724 ldr r3, [pc, r3]
 *   @0x2c6728 ldrb r3, [r3, r2]
 *   @0x2c672c add r0, r0, r3, lsl #2
 *   @0x2c6730 ldr r3, [r0, #0xc]
 *   @0x2c6734 str r3, [r1]
 *   @0x2c6738 str r1, [r0, #0xc]
 *   @0x2c673c bx lr
 *   @0x2c6740 mov r0, r1
 *   @0x2c6744 b 0x2c6a70 <_Z6b2FreePv>
 *   @0x2c6748 ldrheq r11, [r2], -r8
 *
 * ══ §32/350 b2Fixture::b2Fixture  0x2c84e0  size 60  15 条（0x2c84e0..0x2c851c）
 * @func 0x2c84e0 0x2c851c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×1 / 0x24×1 / 0x28×1 / 0x30×1 / 0x8×1 / 0x4×1 / 0x18×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c84e0 mov r1, #1
 *   @0x2c84e4 movw r2, #0xffff
 *   @0x2c84e8 str r1, [r0, #0x20]
 *   @0x2c84ec mov r1, #0
 *   @0x2c84f0 str r2, [r0, #0x24]
 *   @0x2c84f4 mov r2, #0
 *   @0x2c84f8 str r1, [r0]
 *   @0x2c84fc strh r2, [r0, #40]
 *   @0x2c8500 str r2, [r0, #0x30]
 *   @0x2c8504 str r2, [r0, #0x8]
 *   @0x2c8508 str r2, [r0, #0x4]
 *   @0x2c850c str r2, [r0, #0x18]
 *   @0x2c8510 str r2, [r0, #0x1c]
 *   @0x2c8514 str r2, [r0, #0xc]
 *   @0x2c8518 bx lr
 *
 * ══ §33/350 b2StackAllocator::b2StackAllocator  0x2e0f04  size 60  15 条（0x2e0f04..0x2e0f40）
 * @func 0x2e0f04 0x2e0f40  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e0f04 push {r4, r5}
 *   @0x2e0f08 movw r4, #0x9004
 *   @0x2e0f0c movw r12, #0x9008
 *   @0x2e0f10 movt r4, #0x1
 *   @0x2e0f14 movt r12, #0x1
 *   @0x2e0f18 movw r1, #0x918c
 *   @0x2e0f1c movt r1, #0x1
 *   @0x2e0f20 mov r5, #102400
 *   @0x2e0f24 mov r2, #0
 *   @0x2e0f28 str r2, [r0, r5]
 *   @0x2e0f2c str r2, [r0, r4]
 *   @0x2e0f30 str r2, [r0, r12]
 *   @0x2e0f34 pop {r4, r5}
 *   @0x2e0f38 str r2, [r0, r1]
 *   @0x2e0f3c bx lr
 *
 * ══ §34/350 __gnu_ldivmod_helper  0x3195b8  size 60  15 条（0x3195b8..0x3195f4）
 * @func 0x3195b8 0x3195f4  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __divdi3
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x3195b8 push {r3, r4, r5, r6, r7, lr}
 *   @0x3195bc mov r6, r2
 *   @0x3195c0 mov r4, r0
 *   @0x3195c4 mov r5, r1
 *   @0x3195c8 mov r7, r3
 *   @0x3195cc bl 0x31b220 <__divdi3>
 *   @0x3195d0 ldr r12, [sp, #0x18]
 *   @0x3195d4 mul r3, r6, r1
 *   @0x3195d8 mla r7, r0, r7, r3
 *   @0x3195dc umull r2, r3, r6, r0
 *   @0x3195e0 add r3, r7, r3
 *   @0x3195e4 subs r2, r4, r2
 *   @0x3195e8 sbc r3, r5, r3
 *   @0x3195ec strd r2, r3, [r12]
 *   @0x3195f0 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §35/350 _JNIEnv::CallStaticVoidMethod  0xc4ad4  size 56  14 条（0xc4ad4..0xc4b0c）
 * @func 0xc4ad4 0xc4b0c  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x-4×1 / 0x10×1 / 0x238×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc4ad4 push {r2, r3}
 *   @0xc4ad8 str lr, [sp, #-0x4]!
 *   @0xc4adc sub sp, sp, #12
 *   @0xc4ae0 ldr lr, [r0]
 *   @0xc4ae4 add r12, sp, #20
 *   @0xc4ae8 ldr r2, [sp, #0x10]
 *   @0xc4aec mov r3, r12
 *   @0xc4af0 str r12, [sp, #0x4]
 *   @0xc4af4 ldr r12, [lr, #0x238]
 *   @0xc4af8 blx r12
 *   @0xc4afc add sp, sp, #12
 *   @0xc4b00 ldr lr, [sp], #4
 *   @0xc4b04 add sp, sp, #8
 *   @0xc4b08 bx lr
 *
 * ══ §36/350 Code_GetEntry  0xced64  size 56  14 条（0xced64..0xced9c）
 * @func 0xced64 0xced9c  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Code_GetEntry(int)+0x28
 * 字段偏移 top8: 0x28×1 / 0x18×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xced64 ldr r3, [pc, #0x28]
 *   @0xced68 ldr r3, [pc, r3]
 *   @0xced6c ldr r3, [r3]
 *   @0xced70 cmp r3, r0
 *   @0xced74 ble 0xced8c <_Z13Code_GetEntryi+0x28>
 *   @0xced78 ldr r3, [pc, #0x18]
 *   @0xced7c ldr r3, [pc, r3]
 *   @0xced80 ldr r3, [r3]
 *   @0xced84 ldr r0, [r3, r0, lsl #2]
 *   @0xced88 bx lr
 *   @0xced8c mov r0, #0
 *   @0xced90 bx lr
 *   @0xced94 eorseq lr, r1, r12, asr #27
 *   @0xced98 ldrhteq lr, [r1], -r12
 *
 * ══ §37/350 VM::WriteBreakpointsToMemory  0xd83cc  size 56  14 条（0xd83cc..0xd8404）
 * @func 0xd83cc 0xd8418  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x2c×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd83cc ldr r1, [pc, #0x2c]
 *   @0xd83d0 mov r0, #0
 *   @0xd83d4 movt r0, #0xffff
 *   @0xd83d8 mov r3, #0
 *   @0xd83dc ldr r1, [pc, r1]
 *   @0xd83e0 add r2, r1, r3
 *   @0xd83e4 add r3, r3, #16
 *   @0xd83e8 ldr r2, [r2, #0x4]
 *   @0xd83ec cmn r2, #1
 *   @0xd83f0 strne r0, [r2]
 *   @0xd83f4 cmp r3, #4096
 *   @0xd83f8 bne 0xd83e0 <_ZN2VM24WriteBreakpointsToMemoryEv+0x14>
 *   @0xd83fc bx lr
 *   @0xd8400 eorseq r5, r1, r8, lsl #18
 *
 * ══ §38/350 _JNIEnv::CallStaticObjectMethod  0xf2840  size 56  14 条（0xf2840..0xf2878）
 * @func 0xf2840 0xf288c  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x-4×1 / 0x10×1 / 0x1cc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2840 push {r2, r3}
 *   @0xf2844 str lr, [sp, #-0x4]!
 *   @0xf2848 sub sp, sp, #12
 *   @0xf284c ldr lr, [r0]
 *   @0xf2850 add r12, sp, #20
 *   @0xf2854 ldr r2, [sp, #0x10]
 *   @0xf2858 mov r3, r12
 *   @0xf285c str r12, [sp, #0x4]
 *   @0xf2860 ldr r12, [lr, #0x1cc]
 *   @0xf2864 blx r12
 *   @0xf2868 add sp, sp, #12
 *   @0xf286c ldr lr, [sp], #4
 *   @0xf2870 add sp, sp, #8
 *   @0xf2874 bx lr
 *
 * ══ §39/350 _JNIEnv::CallStaticIntMethod  0xf2878  size 56  14 条（0xf2878..0xf28b0）
 * @func 0xf2878 0xf28b0  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x-4×1 / 0x10×1 / 0x208×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2878 push {r2, r3}
 *   @0xf287c str lr, [sp, #-0x4]!
 *   @0xf2880 sub sp, sp, #12
 *   @0xf2884 ldr lr, [r0]
 *   @0xf2888 add r12, sp, #20
 *   @0xf288c ldr r2, [sp, #0x10]
 *   @0xf2890 mov r3, r12
 *   @0xf2894 str r12, [sp, #0x4]
 *   @0xf2898 ldr r12, [lr, #0x208]
 *   @0xf289c blx r12
 *   @0xf28a0 add sp, sp, #12
 *   @0xf28a4 ldr lr, [sp], #4
 *   @0xf28a8 add sp, sp, #8
 *   @0xf28ac bx lr
 *
 * ══ §40/350 _JNIEnv::CallStaticLongMethod  0x161704  size 56  14 条（0x161704..0x16173c）
 * @func 0x161704 0x16173c  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x-4×1 / 0x10×1 / 0x214×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161704 push {r2, r3}
 *   @0x161708 str lr, [sp, #-0x4]!
 *   @0x16170c sub sp, sp, #12
 *   @0x161710 ldr lr, [r0]
 *   @0x161714 add r12, sp, #20
 *   @0x161718 ldr r2, [sp, #0x10]
 *   @0x16171c mov r3, r12
 *   @0x161720 str r12, [sp, #0x4]
 *   @0x161724 ldr r12, [lr, #0x214]
 *   @0x161728 blx r12
 *   @0x16172c add sp, sp, #12
 *   @0x161730 ldr lr, [sp], #4
 *   @0x161734 add sp, sp, #8
 *   @0x161738 bx lr
 *
 * ══ §41/350 RenderStateManager::Force  0x168294  size 56  14 条（0x168294..0x1682cc）
 * @func 0x168294 0x1682cc  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x168294 push {r4, r5, r6, r7}
 *   @0x168298 mov r12, #944
 *   @0x16829c ldrd r4, r5, [r0, #8]
 *   @0x1682a0 movw r6, #0x3ff
 *   @0x1682a4 mov r7, #0
 *   @0x1682a8 mvn r2, #0
 *   @0x1682ac mvn r3, #0
 *   @0x1682b0 orr r4, r4, r6
 *   @0x1682b4 strd r2, r3, [r0, r12]
 *   @0x1682b8 orr r5, r5, r7
 *   @0x1682bc strd r2, r3, [r0]
 *   @0x1682c0 strd r4, r5, [r0, #8]
 *   @0x1682c4 pop {r4, r5, r6, r7}
 *   @0x1682c8 b 0x168134 <_ZN18RenderStateManager5FlushEv>
 *
 * ══ §42/350 GR_Surface_Resize  0x171b68  size 56  14 条（0x171b68..0x171ba0）
 * @func 0x171b68 0x171ba0  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Texture_Free_Only(int) / GR_Surface_Create(int, int, int)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x171b68 push {r4, r5, r6, lr}
 *   @0x171b6c mov r6, r1
 *   @0x171b70 mov r5, r2
 *   @0x171b74 mov r4, r0
 *   @0x171b78 bl 0x171ae4 <_Z20GR_Texture_Free_Onlyi>
 *   @0x171b7c cmp r0, #0
 *   @0x171b80 popeq {r4, r5, r6, pc}
 *   @0x171b84 mov r0, r6
 *   @0x171b88 mov r1, r5
 *   @0x171b8c mov r2, r4
 *   @0x171b90 bl 0x170f98 <_Z17GR_Surface_Createiii>
 *   @0x171b94 mvn r0, r0
 *   @0x171b98 lsr r0, r0, #31
 *   @0x171b9c pop {r4, r5, r6, pc}
 *
 * ══ §43/350 Graphics::SaveRenderTarget  0x1833cc  size 56  14 条（0x1833cc..0x183404）
 * @func 0x1833cc 0x183404  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1833cc push {r3, lr}
 *   @0x1833d0 movw r0, #0xba2
 *   @0x1833d4 ldr r3, [pc, #0x20]
 *   @0x1833d8 ldr r1, [pc, #0x20]
 *   @0x1833dc ldr r3, [pc, r3]
 *   @0x1833e0 add r1, pc, r1
 *   @0x1833e4 add r1, r1, #2800
 *   @0x1833e8 ldr r3, [r3]
 *   @0x1833ec add r1, r1, #4
 *   @0x1833f0 blx r3
 *   @0x1833f4 pop {r3, lr}
 *   @0x1833f8 b 0x18072c <_Z21pushRenderBufferStackv>
 *   @0x1833fc .word 0x0026a3bc
 *   @0x183400 eorseq pc, r1, r12, lsl r0
 *
 * ══ §44/350 TimeLine_Data  0x1f2c48  size 56  14 条（0x1f2c48..0x1f2c80）
 * @func 0x1f2c48 0x1f2c80  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: TimeLine_Data(int)+0x20 / TimeLine_Data(int)+0x28
 * 字段偏移 top8: 0x24×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f2c48 cmp r0, #0
 *   @0x1f2c4c blt 0x1f2c68 <_Z13TimeLine_Datai+0x20>
 *   @0x1f2c50 ldr r3, [pc, #0x24]
 *   @0x1f2c54 add r3, pc, r3
 *   @0x1f2c58 ldr r3, [r3]
 *   @0x1f2c5c ldr r2, [r3]
 *   @0x1f2c60 cmp r0, r2
 *   @0x1f2c64 blt 0x1f2c70 <_Z13TimeLine_Datai+0x28>
 *   @0x1f2c68 mov r0, #0
 *   @0x1f2c6c bx lr
 *   @0x1f2c70 ldr r3, [r3, #0x4]
 *   @0x1f2c74 ldr r0, [r3, r0, lsl #2]
 *   @0x1f2c78 bx lr
 *   @0x1f2c7c .word 0x00560498
 *
 * ══ §45/350 Variable_Global_Declared  0x1f3484  size 56  14 条（0x1f3484..0x1f34bc）
 * @func 0x1f3484 0x1f34bc  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f3484 sub r0, r0, #99328
 *   @0x1f3488 subs r0, r0, #672
 *   @0x1f348c bmi 0x1f34b0 <_Z24Variable_Global_Declaredi+0x2c>
 *   @0x1f3490 ldr r3, [pc, #0x20]
 *   @0x1f3494 ldr r3, [pc, r3]
 *   @0x1f3498 ldr r2, [r3]
 *   @0x1f349c cmp r0, r2
 *   @0x1f34a0 bge 0x1f34b0 <_Z24Variable_Global_Declaredi+0x2c>
 *   @0x1f34a4 ldr r3, [r3, #0x4]
 *   @0x1f34a8 ldrb r0, [r3, r0]
 *   @0x1f34ac bx lr
 *   @0x1f34b0 mov r0, #0
 *   @0x1f34b4 bx lr
 *   @0x1f34b8 mulseq pc, r4, r9
 *
 * ══ §46/350 DirectoryExists  0x214f24  size 56  14 条（0x214f24..0x214f5c）
 * @func 0x214f24 0x214f5c  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb69f4
 * 字段偏移 top8: 0x-4×1 / 0x10×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x214f24 str lr, [sp, #-0x4]!
 *   @0x214f28 sub sp, sp, #108
 *   @0x214f2c mov r1, sp
 *   @0x214f30 bl 0xb69f4 <stat@plt>
 *   @0x214f34 cmp r0, #0
 *   @0x214f38 movne r0, #0
 *   @0x214f3c bne 0x214f54 <_Z15DirectoryExistsPKc+0x30>
 *   @0x214f40 ldr r0, [sp, #0x10]
 *   @0x214f44 and r0, r0, #61440
 *   @0x214f48 subs r3, r0, #16384
 *   @0x214f4c rsbs r0, r3, #0
 *   @0x214f50 adcs r0, r0, r3
 *   @0x214f54 add sp, sp, #108
 *   @0x214f58 ldr pc, [sp], #4
 *
 * ══ §47/350 yyisinf  0x240970  size 56  14 条（0x240970..0x2409a8）
 * @func 0x240970 0x2409a8  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x240970 ldr r2, [r0]
 *   @0x240974 ldr r3, [r0, #0x4]
 *   @0x240978 push {r4, r5}
 *   @0x24097c mov r5, #0
 *   @0x240980 movt r5, #0x7ff0
 *   @0x240984 mov r4, #0
 *   @0x240988 and r3, r3, r5
 *   @0x24098c and r2, r2, r4
 *   @0x240990 cmp r3, r5
 *   @0x240994 cmpeq r2, r4
 *   @0x240998 pop {r4, r5}
 *   @0x24099c movne r0, #0
 *   @0x2409a0 moveq r0, #1
 *   @0x2409a4 bx lr
 *
 * ══ §48/350 Mutex::Init  0x27e038  size 56  14 条（0x27e038..0x27e070）
 * @func 0x27e038 0x27e084  size 76  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6ca0 / 0xb6cac / 0xb6cb8
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27e038 push {r4, r5, lr}
 *   @0x27e03c sub sp, sp, #12
 *   @0x27e040 add r4, sp, #4
 *   @0x27e044 mov r5, r0
 *   @0x27e048 mov r0, r4
 *   @0x27e04c bl 0xb6ca0 <pthread_mutexattr_init@plt>
 *   @0x27e050 mov r0, r4
 *   @0x27e054 mov r1, #1
 *   @0x27e058 bl 0xb6cac <pthread_mutexattr_settype@plt>
 *   @0x27e05c add r0, r5, #4
 *   @0x27e060 mov r1, r4
 *   @0x27e064 bl 0xb6cb8 <pthread_mutex_init@plt>
 *   @0x27e068 add sp, sp, #12
 *   @0x27e06c pop {r4, r5, pc}
 *
 * ══ §49/350 json_object_object_add  0x27ea00  size 56  14 条（0x27ea00..0x27ea38）
 * @func 0x27ea00 0x27ea38  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: lh_table_delete / 0xb6640
 * 字段偏移 top8: 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27ea00 push {r4, r5, r6, lr}
 *   @0x27ea04 mov r5, r1
 *   @0x27ea08 mov r4, r0
 *   @0x27ea0c ldr r0, [r0, #0x18]
 *   @0x27ea10 mov r6, r2
 *   @0x27ea14 bl 0x280ca0 <lh_table_delete>
 *   @0x27ea18 mov r0, r5
 *   @0x27ea1c ldr r4, [r4, #0x18]
 *   @0x27ea20 bl 0xb6640 <strdup@plt>
 *   @0x27ea24 mov r2, r6
 *   @0x27ea28 mov r1, r0
 *   @0x27ea2c mov r0, r4
 *   @0x27ea30 pop {r4, r5, r6, lr}
 *   @0x27ea34 b 0x280998 <lh_table_insert>
 *
 * ══ §50/350 spSkeleton_setSkinByName  0x28a2dc  size 56  14 条（0x28a2dc..0x28a314）
 * @func 0x28a2dc 0x28a314  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeletonData_findSkin / spSkeleton_setSkin
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28a2dc cmp r1, #0
 *   @0x28a2e0 push {r4, lr}
 *   @0x28a2e4 mov r4, r0
 *   @0x28a2e8 beq 0x28a300 <spSkeleton_setSkinByName+0x24>
 *   @0x28a2ec ldr r0, [r0]
 *   @0x28a2f0 bl 0x28b124 <spSkeletonData_findSkin>
 *   @0x28a2f4 subs r1, r0, #0
 *   @0x28a2f8 beq 0x28a30c <spSkeleton_setSkinByName+0x30>
 *   @0x28a2fc mov r0, r4
 *   @0x28a300 bl 0x28a250 <spSkeleton_setSkin>
 *   @0x28a304 mov r0, #1
 *   @0x28a308 pop {r4, pc}
 *   @0x28a30c mov r0, r1
 *   @0x28a310 pop {r4, pc}
 *
 * ══ §51/350 b2DynamicTree::FreeNode  0x2deaac  size 56  14 条（0x2deaac..0x2deae4）
 * @func 0x2deaac 0x2deae4  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x10×2 / 0x8×2 / 0x-4×1 / 0x14×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2deaac str r4, [sp, #-0x4]!
 *   @0x2deab0 add r4, r1, r1, lsl #3
 *   @0x2deab4 ldr r3, [r0, #0x4]
 *   @0x2deab8 mvn r12, #0
 *   @0x2deabc ldr r2, [r0, #0x10]
 *   @0x2deac0 add r3, r3, r4, lsl #2
 *   @0x2deac4 str r2, [r3, #0x14]
 *   @0x2deac8 ldr r2, [r0, #0x8]
 *   @0x2deacc ldr r4, [sp], #4
 *   @0x2dead0 str r12, [r3, #0x20]
 *   @0x2dead4 add r3, r2, r12
 *   @0x2dead8 str r1, [r0, #0x10]
 *   @0x2deadc str r3, [r0, #0x8]
 *   @0x2deae0 bx lr
 *
 * ══ §52/350 __fixsfdi  0x319468  size 56  14 条（0x319468..0x3194a0）
 * @func 0x319468 0x3194a0  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __aeabi_fcmplt / __fixunssfdi
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x319468 push {r4, lr}
 *   @0x31946c mov r1, #0
 *   @0x319470 mov r4, r0
 *   @0x319474 bl 0x31b1d0 <__aeabi_fcmplt>
 *   @0x319478 cmp r0, #0
 *   @0x31947c beq 0x319494 <__fixsfdi+0x2c>
 *   @0x319480 add r0, r4, #-2147483648
 *   @0x319484 bl 0x3194e4 <__fixunssfdi>
 *   @0x319488 rsbs r0, r0, #0
 *   @0x31948c rsc r1, r1, #0
 *   @0x319490 pop {r4, pc}
 *   @0x319494 mov r0, r4
 *   @0x319498 pop {r4, lr}
 *   @0x31949c b 0x3194e4 <__fixunssfdi>
 *
 * ══ §53/350 GetIBuffer  0xc6720  size 52  13 条（0xc6720..0xc6754）
 * @func 0xc6720 0xc6754  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetIBuffer(int)+0x28
 * 字段偏移 top8: 0x20×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc6720 cmp r0, #0
 *   @0xc6724 blt 0xc6748 <_Z10GetIBufferi+0x28>
 *   @0xc6728 ldr r3, [pc, #0x20]
 *   @0xc672c add r3, pc, r3
 *   @0xc6730 ldr r2, [r3]
 *   @0xc6734 cmp r0, r2
 *   @0xc6738 bge 0xc6748 <_Z10GetIBufferi+0x28>
 *   @0xc673c ldr r3, [r3, #0x4]
 *   @0xc6740 ldr r0, [r3, r0, lsl #2]
 *   @0xc6744 bx lr
 *   @0xc6748 mov r0, #0
 *   @0xc674c bx lr
 *   @0xc6750 eorseq r3, r11, r8, ror #19
 *
 * ══ §54/350 YYSetInstance  0xdc37c  size 52  13 条（0xdc37c..0xdc3b0）
 * @func 0xdc37c 0xdc3c4  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYObjectBase::Alloc(unsigned int, int, bool)
 * 字段偏移 top8: 0x28×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xdc37c ldr r3, [pc, #0x28]
 *   @0xdc380 mov r2, #6
 *   @0xdc384 push {r4, lr}
 *   @0xdc388 ldr r3, [pc, r3]
 *   @0xdc38c str r2, [r0, #0xc]
 *   @0xdc390 mov r4, r0
 *   @0xdc394 mvn r1, #-16777216
 *   @0xdc398 mov r2, #0
 *   @0xdc39c ldr r0, [r3]
 *   @0xdc3a0 bl 0x19198c <_ZN12YYObjectBase5AllocEjib>
 *   @0xdc3a4 str r0, [r4]
 *   @0xdc3a8 pop {r4, pc}
 *   @0xdc3ac eorseq r1, r1, r12, lsl #19
 *
 * ══ §55/350 Shader_Get  0x187e70  size 52  13 条（0x187e70..0x187ea4）
 * @func 0x187e70 0x187ea4  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Shader_Get(int)+0x28
 * 字段偏移 top8: 0x20×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x187e70 cmp r0, #0
 *   @0x187e74 blt 0x187e98 <_Z10Shader_Geti+0x28>
 *   @0x187e78 ldr r3, [pc, #0x20]
 *   @0x187e7c ldr r3, [pc, r3]
 *   @0x187e80 ldr r2, [r3]
 *   @0x187e84 cmp r0, r2
 *   @0x187e88 bge 0x187e98 <_Z10Shader_Geti+0x28>
 *   @0x187e8c ldr r3, [r3, #0x4]
 *   @0x187e90 ldr r0, [r3, r0, lsl #2]
 *   @0x187e94 bx lr
 *   @0x187e98 mov r0, #0
 *   @0x187e9c bx lr
 *   @0x187ea0 eoreq r8, r6, r12, lsr r7
 *
 * ══ §56/350 IO_String_Clear  0x18be60  size 52  13 条（0x18be60..0x18be94）
 * @func 0x18be60 0x18be94  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65b0
 * 字段偏移 top8: 0x24×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18be60 ldr r0, [pc, #0x24]
 *   @0x18be64 movw r2, #0x401
 *   @0x18be68 push {r3, lr}
 *   @0x18be6c mov r1, #0
 *   @0x18be70 ldr r0, [pc, r0]
 *   @0x18be74 bl 0xb65b0 <memset@plt>
 *   @0x18be78 ldr r3, [pc, #0x10]
 *   @0x18be7c mov r2, #0
 *   @0x18be80 ldr r3, [pc, r3]
 *   @0x18be84 str r2, [r3]
 *   @0x18be88 pop {r3, pc}
 *   @0x18be8c eoreq r4, r6, r4, ror #14
 *   @0x18be90 eoreq r4, r6, r12, lsl #15
 *
 * ══ §57/350 Room_Data  0x1b52c4  size 52  13 条（0x1b52c4..0x1b52f8）
 * @func 0x1b52c4 0x1b530c  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Room_Data(int)+0x1c / Room_Data(int)+0x24
 * 字段偏移 top8: 0x20×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b52c4 cmp r0, #0
 *   @0x1b52c8 blt 0x1b52e0 <_Z9Room_Datai+0x1c>
 *   @0x1b52cc ldr r3, [pc, #0x20]
 *   @0x1b52d0 add r3, pc, r3
 *   @0x1b52d4 ldr r2, [r3]
 *   @0x1b52d8 cmp r0, r2
 *   @0x1b52dc blt 0x1b52e8 <_Z9Room_Datai+0x24>
 *   @0x1b52e0 mov r0, #0
 *   @0x1b52e4 bx lr
 *   @0x1b52e8 ldr r3, [r3, #0x4]
 *   @0x1b52ec ldr r0, [r3, r0, lsl #2]
 *   @0x1b52f0 bx lr
 *   @0x1b52f4 ldrshteq sp, [r8], -r8
 *
 * ══ §58/350 DsQueueCreate  0x2053bc  size 52  13 条（0x2053bc..0x2053f0）
 * @func 0x2053bc 0x2053f0  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_DsQueueCreate(RValue&, CInstance*, CInstance*, int, RValue*) / 0xb66e8
 * 字段偏移 top8: 0x-4×1 / 0x-10×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2053bc str lr, [sp, #-0x4]!
 *   @0x2053c0 sub sp, sp, #28
 *   @0x2053c4 add r0, sp, #24
 *   @0x2053c8 mov r3, #0
 *   @0x2053cc mov r1, r3
 *   @0x2053d0 str r3, [sp]
 *   @0x2053d4 mov r2, r3
 *   @0x2053d8 str r3, [r0, #-0x10]!
 *   @0x2053dc bl 0xfad10 <_Z15F_DsQueueCreateR6RValueP9CInstanceS2_iPS_>
 *   @0x2053e0 ldrd r0, r1, [sp, #8]
 *   @0x2053e4 bl 0xb66e8 <lrint@plt>
 *   @0x2053e8 add sp, sp, #28
 *   @0x2053ec ldr pc, [sp], #4
 *
 * ══ §59/350 Color_HSVToColor  0x20feac  size 52  13 条（0x20feac..0x20fee0）
 * @func 0x20feac 0x20fee0  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Color_HSVToRGB(THSV&) / Color_RGBToColor(TRGB&)
 * 字段偏移 top8: 0x4×2 / 0x-4×1 / 0x5×1 / 0x6×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20feac str lr, [sp, #-0x4]!
 *   @0x20feb0 sub sp, sp, #12
 *   @0x20feb4 bl 0x20fd04 <_Z14Color_HSVToRGBR4THSV>
 *   @0x20feb8 mov r3, r0
 *   @0x20febc add r0, sp, #4
 *   @0x20fec0 ubfx r2, r3, #0x8, #0x8
 *   @0x20fec4 strb r3, [sp, #0x4]
 *   @0x20fec8 strb r2, [sp, #0x5]
 *   @0x20fecc ubfx r3, r3, #0x10, #0x8
 *   @0x20fed0 strb r3, [sp, #0x6]
 *   @0x20fed4 bl 0x20fa2c <_Z16Color_RGBToColorR4TRGB>
 *   @0x20fed8 add sp, sp, #12
 *   @0x20fedc ldr pc, [sp], #4
 *
 * ══ §60/350 CListener::CListener  0x215ae8  size 52  13 条（0x215ae8..0x215b1c）
 * @func 0x215ae8 0x215b1c  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CListener::Reset()
 * 字段偏移 top8: 0x4×1 / 0x8×1 / 0xc×1 / 0x10×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x215ae8 push {r4, lr}
 *   @0x215aec movw r3, #0x4f80
 *   @0x215af0 mov r4, r0
 *   @0x215af4 movt r3, #0xc7c3
 *   @0x215af8 str r3, [r0]
 *   @0x215afc str r3, [r0, #0x4]
 *   @0x215b00 str r3, [r0, #0x8]
 *   @0x215b04 str r3, [r0, #0xc]
 *   @0x215b08 str r3, [r0, #0x10]
 *   @0x215b0c str r3, [r0, #0x14]
 *   @0x215b10 bl 0x215ab8 <_ZN9CListener5ResetEv>
 *   @0x215b14 mov r0, r4
 *   @0x215b18 pop {r4, pc}
 *
 * ══ §61/350 vorbis_block_clear  0x227208  size 52  13 条（0x227208..0x22723c）
 * @func 0x227208 0x22723c  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _vorbis_block_ripcord / 0xb655c / 0xb65b0
 * 字段偏移 top8: 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x227208 push {r4, lr}
 *   @0x22720c mov r4, r0
 *   @0x227210 bl 0x227164 <_vorbis_block_ripcord>
 *   @0x227214 ldr r0, [r4, #0x44]
 *   @0x227218 cmp r0, #0
 *   @0x22721c beq 0x227224 <vorbis_block_clear+0x1c>
 *   @0x227220 bl 0xb655c <free@plt>
 *   @0x227224 mov r0, r4
 *   @0x227228 mov r1, #0
 *   @0x22722c mov r2, #88
 *   @0x227230 bl 0xb65b0 <memset@plt>
 *   @0x227234 mov r0, #0
 *   @0x227238 pop {r4, pc}
 *
 * ══ §62/350 vorbis_synthesis_read  0x227cfc  size 52  13 条（0x227cfc..0x227d30）
 * @func 0x227cfc 0x227d30  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: vorbis_synthesis_read+0xc
 * 字段偏移 top8: 0x18×3 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x227cfc cmp r1, #0
 *   @0x227d00 bne 0x227d14 <vorbis_synthesis_read+0x18>
 *   @0x227d04 ldr r1, [r0, #0x18]
 *   @0x227d08 str r1, [r0, #0x18]
 *   @0x227d0c mov r0, #0
 *   @0x227d10 bx lr
 *   @0x227d14 ldr r2, [r0, #0x18]
 *   @0x227d18 ldr r3, [r0, #0x14]
 *   @0x227d1c add r1, r1, r2
 *   @0x227d20 cmp r1, r3
 *   @0x227d24 ble 0x227d08 <vorbis_synthesis_read+0xc>
 *   @0x227d28 mvn r0, #130
 *   @0x227d2c bx lr
 *
 * ══ §63/350 ogg_sync_clear  0x234b2c  size 52  13 条（0x234b2c..0x234b60）
 * @func 0x234b2c 0x234b60  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb655c / 0xb65b0
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x234b2c push {r4, lr}
 *   @0x234b30 subs r4, r0, #0
 *   @0x234b34 beq 0x234b58 <ogg_sync_clear+0x2c>
 *   @0x234b38 ldr r0, [r4]
 *   @0x234b3c cmp r0, #0
 *   @0x234b40 beq 0x234b48 <ogg_sync_clear+0x1c>
 *   @0x234b44 bl 0xb655c <free@plt>
 *   @0x234b48 mov r0, r4
 *   @0x234b4c mov r1, #0
 *   @0x234b50 mov r2, #28
 *   @0x234b54 bl 0xb65b0 <memset@plt>
 *   @0x234b58 mov r0, #0
 *   @0x234b5c pop {r4, pc}
 *
 * ══ §64/350 ogg_stream_reset_serialno  0x2352f4  size 52  13 条（0x2352f4..0x235328）
 * @func 0x2352f4 0x23533c  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ogg_stream_check / ogg_stream_reset
 * 字段偏移 top8: 0x150×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2352f4 push {r4, r5, r6, lr}
 *   @0x2352f8 mov r6, r1
 *   @0x2352fc mov r4, r0
 *   @0x235300 bl 0x23412c <ogg_stream_check>
 *   @0x235304 subs r5, r0, #0
 *   @0x235308 bne 0x235320 <ogg_stream_reset_serialno+0x2c>
 *   @0x23530c mov r0, r4
 *   @0x235310 bl 0x235294 <ogg_stream_reset>
 *   @0x235314 str r6, [r4, #0x150]
 *   @0x235318 mov r0, r5
 *   @0x23531c pop {r4, r5, r6, pc}
 *   @0x235320 mvn r5, #0
 *   @0x235324 b 0x235318 <ogg_stream_reset_serialno+0x24>
 *
 * ══ §65/350 ogg_stream_packetout  0x235328  size 52  13 条（0x235328..0x23535c）
 * @func 0x235328 0x23535c  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ogg_stream_check
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x235328 push {r3, r4, r5, lr}
 *   @0x23532c mov r4, r1
 *   @0x235330 mov r5, r0
 *   @0x235334 bl 0x23412c <ogg_stream_check>
 *   @0x235338 cmp r0, #0
 *   @0x23533c beq 0x235348 <ogg_stream_packetout+0x20>
 *   @0x235340 mov r0, #0
 *   @0x235344 pop {r3, r4, r5, pc}
 *   @0x235348 mov r0, r5
 *   @0x23534c mov r1, r4
 *   @0x235350 mov r2, #1
 *   @0x235354 pop {r3, r4, r5, lr}
 *   @0x235358 b 0x233e64 <oggpackB_get_buffer+0x4>
 *
 * ══ §66/350 CPhysicsWorld::GetCollisionCategory  0x238488  size 52  13 条（0x238488..0x2384bc）
 * @func 0x238488 0x2384bc  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x68×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x238488 mov r3, #0
 *   @0x23848c b 0x23849c <_ZN13CPhysicsWorld20GetCollisionCategoryEi+0x14>
 *   @0x238490 add r3, r3, #1
 *   @0x238494 cmp r3, #32
 *   @0x238498 beq 0x2384b4 <_ZN13CPhysicsWorld20GetCollisionCategoryEi+0x2c>
 *   @0x23849c ldr r2, [r0, #0x68]
 *   @0x2384a0 add r0, r0, #12
 *   @0x2384a4 cmp r2, r1
 *   @0x2384a8 bne 0x238490 <_ZN13CPhysicsWorld20GetCollisionCategoryEi+0x8>
 *   @0x2384ac mov r0, r3
 *   @0x2384b0 bx lr
 *   @0x2384b4 mvn r0, #0
 *   @0x2384b8 bx lr
 *
 * ══ §67/350 CPhysicsWorld::DeleteParticleGroup  0x239e34  size 52  13 条（0x239e34..0x239e68）
 * @func 0x239e34 0x239e68  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsWorld::GetParticleGroup(int) / b2World::DestroyParticlesInGroup(b2ParticleGroup*, bool)
 * 字段偏移 top8: 0x10×1 / 0x48×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x239e34 push {r3, r4, r5, lr}
 *   @0x239e38 mov r5, r1
 *   @0x239e3c mov r4, r0
 *   @0x239e40 bl 0x239dc0 <_ZN13CPhysicsWorld16GetParticleGroupEi>
 *   @0x239e44 subs r1, r0, #0
 *   @0x239e48 popeq {r3, r4, r5, pc}
 *   @0x239e4c mov r2, #0
 *   @0x239e50 ldr r0, [r4, #0x10]
 *   @0x239e54 bl 0x2cb548 <_ZN7b2World23DestroyParticlesInGroupEP15b2ParticleGroupb>
 *   @0x239e58 ldr r3, [r4, #0x48]
 *   @0x239e5c mov r2, #0
 *   @0x239e60 str r2, [r3, r5, lsl #2]
 *   @0x239e64 pop {r3, r4, r5, pc}
 *
 * ══ §68/350 Bfree_D2A  0x23d2a0  size 52  13 条（0x23d2a0..0x23d2d4）
 * @func 0x23d2a0 0x23d2d4  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x2×2 / 0x4×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23d2a0 subs r3, r0, #0
 *   @0x23d2a4 bxeq lr
 *   @0x23d2a8 ldr r2, [r3, #0x4]
 *   @0x23d2ac cmp r2, #9
 *   @0x23d2b0 bgt 0x23d2cc <Bfree_D2A+0x2c>
 *   @0x23d2b4 ldr r1, [pc, #0x14]
 *   @0x23d2b8 add r1, pc, r1
 *   @0x23d2bc ldr r0, [r1, r2, lsl #2]
 *   @0x23d2c0 str r3, [r1, r2, lsl #2]
 *   @0x23d2c4 str r0, [r3]
 *   @0x23d2c8 bx lr
 *   @0x23d2cc b 0xb655c <free@plt>
 *   @0x23d2d0 subseq r8, r1, r8, ror #15
 *
 * ══ §69/350 json_object_new_double  0x27ebb8  size 52  13 条（0x27ebb8..0x27ebec）
 * @func 0x27ebb8 0x27ebec  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_27e408+0x31c
 * 字段偏移 top8: 0xc×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27ebb8 push {r3, r4, r5, lr}
 *   @0x27ebbc mov r4, r0
 *   @0x27ebc0 mov r0, #2
 *   @0x27ebc4 mov r5, r1
 *   @0x27ebc8 bl 0x27e724 <mc_info+0x35c>
 *   @0x27ebcc cmp r0, #0
 *   @0x27ebd0 popeq {r3, r4, r5, pc}
 *   @0x27ebd4 ldr r3, [pc, #0xc]
 *   @0x27ebd8 strd r4, r5, [r0, #24]
 *   @0x27ebdc add r3, pc, r3
 *   @0x27ebe0 str r3, [r0, #0x8]
 *   @0x27ebe4 pop {r3, r4, r5, pc}
 *   @0x27ebe8 .word 0xfffff83c
 *
 * ══ §70/350 spTimeline_apply  0x2814cc  size 52  13 条（0x2814cc..0x281500）
 * @func 0x2814cc 0x281500  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x18×1 / 0x1c×1 / 0x20×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2814cc push {r4, lr}
 *   @0x2814d0 sub sp, sp, #16
 *   @0x2814d4 ldr r12, [r0, #0x4]
 *   @0x2814d8 ldr r4, [sp, #0x18]
 *   @0x2814dc ldr lr, [sp, #0x1c]
 *   @0x2814e0 str r4, [sp]
 *   @0x2814e4 ldr r4, [sp, #0x20]
 *   @0x2814e8 str lr, [sp, #0x4]
 *   @0x2814ec str r4, [sp, #0x8]
 *   @0x2814f0 ldr r12, [r12]
 *   @0x2814f4 blx r12
 *   @0x2814f8 add sp, sp, #16
 *   @0x2814fc pop {r4, pc}
 *
 * ══ §71/350 _calloc  0x285c4c  size 52  13 条（0x285c4c..0x285c80）
 * @func 0x285c4c 0x285c94  size 72  18 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _malloc / 0xb65b0
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x285c4c push {r3, r4, r5, lr}
 *   @0x285c50 mul r4, r1, r0
 *   @0x285c54 mov r1, r2
 *   @0x285c58 mov r2, r3
 *   @0x285c5c mov r0, r4
 *   @0x285c60 bl 0x285c10 <_malloc>
 *   @0x285c64 subs r5, r0, #0
 *   @0x285c68 beq 0x285c78 <_calloc+0x2c>
 *   @0x285c6c mov r2, r4
 *   @0x285c70 mov r1, #0
 *   @0x285c74 bl 0xb65b0 <memset@plt>
 *   @0x285c78 mov r0, r5
 *   @0x285c7c pop {r3, r4, r5, pc}
 *
 * ══ §72/350 yySocket::Close  0x295474  size 52  13 条（0x295474..0x2954a8）
 * @func 0x295474 0x2954a8  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6d6c / 0xb6d78
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x295474 ldr r3, [r0]
 *   @0x295478 push {r4, lr}
 *   @0x29547c cmn r3, #1
 *   @0x295480 mov r4, r0
 *   @0x295484 beq 0x29549c <_ZN8yySocket5CloseEv+0x28>
 *   @0x295488 ldr r0, [r0, #0x4]
 *   @0x29548c mov r1, #2
 *   @0x295490 bl 0xb6d6c <shutdown@plt>
 *   @0x295494 ldr r0, [r4]
 *   @0x295498 bl 0xb6d78 <close@plt>
 *   @0x29549c mvn r3, #0
 *   @0x2954a0 str r3, [r4]
 *   @0x2954a4 pop {r4, pc}
 *
 * ══ §73/350 DbgServer::~DbgServer  0x29d038  size 52  13 条（0x29d038..0x29d06c）
 * @func 0x29d038 0x29d06c  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: yyServer::~yyServer() / operator delete(void*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29d038 push {r3, r4, r5, lr}
 *   @0x29d03c mov r4, r0
 *   @0x29d040 ldr r5, [r0]
 *   @0x29d044 cmp r5, #0
 *   @0x29d048 beq 0x29d05c <_ZN9DbgServerD2Ev+0x24>
 *   @0x29d04c mov r0, r5
 *   @0x29d050 bl 0x297184 <_ZN8yyServerD2Ev>
 *   @0x29d054 mov r0, r5
 *   @0x29d058 bl 0x27d1d0 <_ZdlPv>
 *   @0x29d05c mov r3, #0
 *   @0x29d060 mov r0, r4
 *   @0x29d064 str r3, [r4]
 *   @0x29d068 pop {r3, r4, r5, pc}
 *
 * ══ §74/350 b2World::ClearForces  0x2ca658  size 52  13 条（0x2ca658..0x2ca68c）
 * @func 0x2ca658 0x2ca68c  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x5c×1 / 0x60×1 / 0x64×1 / 0x70×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ca658 movw r3, #0x9228
 *   @0x2ca65c movt r3, #0x1
 *   @0x2ca660 ldr r3, [r0, r3]
 *   @0x2ca664 cmp r3, #0
 *   @0x2ca668 bxeq lr
 *   @0x2ca66c mov r2, #0
 *   @0x2ca670 str r2, [r3, #0x5c]
 *   @0x2ca674 str r2, [r3, #0x60]
 *   @0x2ca678 str r2, [r3, #0x64]
 *   @0x2ca67c ldr r3, [r3, #0x70]
 *   @0x2ca680 cmp r3, #0
 *   @0x2ca684 bne 0x2ca670 <_ZN7b2World11ClearForcesEv+0x18>
 *   @0x2ca688 bx lr
 *
 * ══ §75/350 VM::ClearBreakpointsFromMemory  0xd8404  size 48  12 条（0xd8404..0xd8434）
 * @func 0xd8404 0xd8434  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x24×1 / 0xff4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd8404 ldr r3, [pc, #0x24]
 *   @0xd8408 ldr r3, [pc, r3]
 *   @0xd840c sub r0, r3, #4096
 *   @0xd8410 ldr r2, [r3, #0xff4]
 *   @0xd8414 cmn r2, #1
 *   @0xd8418 ldrne r1, [r3, #0xff0]
 *   @0xd841c sub r3, r3, #16
 *   @0xd8420 strne r1, [r2]
 *   @0xd8424 cmp r3, r0
 *   @0xd8428 bne 0xd8410 <_ZN2VM26ClearBreakpointsFromMemoryEv+0xc>
 *   @0xd842c bx lr
 *   @0xd8430 ldrsbteq r5, [r1], -r12
 *
 * ══ §76/350 IAP_RestoreM  0x16186c  size 48  12 条（0x16186c..0x16189c）
 * @func 0x16186c 0x16189c  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv
 * 字段偏移 top8: 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16186c push {r3, lr}
 *   @0x161870 bl 0x290274 <getJNIEnv>
 *   @0x161874 ldr r2, [pc, #0x18]
 *   @0x161878 ldr r3, [pc, #0x18]
 *   @0x16187c ldr r2, [pc, r2]
 *   @0x161880 ldr r3, [pc, r3]
 *   @0x161884 ldr r1, [r2]
 *   @0x161888 ldr r2, [r3]
 *   @0x16188c pop {r3, lr}
 *   @0x161890 b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x161894 eoreq r12, r8, r8, lsr #2
 *   @0x161898 eoreq lr, r8, r4, ror #13
 *
 * ══ §77/350 GR_Texture_Get_Surface  0x17435c  size 48  12 条（0x17435c..0x17438c）
 * @func 0x17435c 0x17438c  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Texture_Exists(int)
 * 字段偏移 top8: 0x10×1 / 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17435c push {r4, lr}
 *   @0x174360 mov r4, r0
 *   @0x174364 bl 0x173e2c <_Z17GR_Texture_Existsi>
 *   @0x174368 cmp r0, #0
 *   @0x17436c popeq {r4, pc}
 *   @0x174370 ldr r3, [pc, #0x10]
 *   @0x174374 ldr r3, [pc, r3]
 *   @0x174378 ldr r3, [r3, #0x4]
 *   @0x17437c ldr r3, [r3, r4, lsl #2]
 *   @0x174380 ldr r0, [r3]
 *   @0x174384 pop {r4, pc}
 *   @0x174388 eoreq r9, r7, r8, lsr #11
 *
 * ══ §78/350 ConvertBlend  0x17fc0c  size 48  12 条（0x17fc0c..0x17fc3c）
 * @func 0x17fc0c 0x17fc50  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17fc0c sub r0, r0, #2
 *   @0x17fc10 mvn r3, #0
 *   @0x17fc14 cmp r0, #9
 *   @0x17fc18 str r3, [r1]
 *   @0x17fc1c bhi 0x17fc30 <_Z12ConvertBlend6eBlendPi+0x24>
 *   @0x17fc20 ldr r3, [pc, #0x10]
 *   @0x17fc24 add r3, pc, r3
 *   @0x17fc28 ldr r0, [r3, r0, lsl #2]
 *   @0x17fc2c bx lr
 *   @0x17fc30 mov r0, #0
 *   @0x17fc34 bx lr
 *   @0x17fc38 andseq sp, sp, r8, lsr #30
 *
 * ══ §79/350 countRenderBufferStack  0x1806fc  size 48  12 条（0x1806fc..0x18072c）
 * @func 0x1806fc 0x18072c  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: initRenderBufferStack()
 * 字段偏移 top8: 0x1c×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1806fc push {r3, lr}
 *   @0x180700 ldr r3, [pc, #0x1c]
 *   @0x180704 ldr r3, [pc, r3]
 *   @0x180708 ldrb r3, [r3]
 *   @0x18070c cmp r3, #0
 *   @0x180710 bne 0x180718 <_Z22countRenderBufferStackv+0x1c>
 *   @0x180714 bl 0x180650 <_Z21initRenderBufferStackv>
 *   @0x180718 ldr r3, [pc, #0x8]
 *   @0x18071c ldr r0, [pc, r3]
 *   @0x180720 pop {r3, pc}
 *   @0x180724 eoreq pc, r6, r0, lsr lr
 *   @0x180728 eorseq r1, r2, r0, ror #25
 *
 * ══ §80/350 Graphics::DrawArrayEx  0x185188  size 48  12 条（0x185188..0x1851b8）
 * @func 0x185188 0x1851b8  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _DrawArray(ePrimType, int, void*, int, void*)
 * 字段偏移 top8: 0x-4×1 / 0x14×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x185188 cmp r1, #0
 *   @0x18518c str lr, [sp, #-0x4]!
 *   @0x185190 sub sp, sp, #12
 *   @0x185194 beq 0x1851ac <_ZN8Graphics11DrawArrayExE9ePrimTypeiPvi+0x24>
 *   @0x185198 ldr r12, [pc, #0x14]
 *   @0x18519c ldr r12, [pc, r12]
 *   @0x1851a0 ldr r12, [r12]
 *   @0x1851a4 str r12, [sp]
 *   @0x1851a8 bl 0x184868 <_Z10_DrawArray9ePrimTypeiPviS0_>
 *   @0x1851ac add sp, sp, #12
 *   @0x1851b0 ldr pc, [sp], #4
 *   @0x1851b4 eoreq r11, r6, r12, lsr #7
 *
 * ══ §81/350 SetShader  0x188650  size 48  12 条（0x188650..0x188680）
 * @func 0x188650 0x188680  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x24×1 / 0x64×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x188650 ldr r3, [pc, #0x24]
 *   @0x188654 ldr r3, [pc, r3]
 *   @0x188658 ldr r3, [r3]
 *   @0x18865c cmp r3, #1
 *   @0x188660 bxne lr
 *   @0x188664 cmp r0, #0
 *   @0x188668 beq 0x188674 <_Z9SetShaderP6Shader+0x24>
 *   @0x18866c ldr r0, [r0, #0x64]
 *   @0x188670 b 0x1880ec <_Z11Shader_SetMi>
 *   @0x188674 mvn r0, #0
 *   @0x188678 b 0x1880ec <_Z11Shader_SetMi>
 *   @0x18867c .word 0x00267db4
 *
 * ══ §82/350 RVALUE_GC_ADDROOT  0x191bac  size 48  12 条（0x191bac..0x191bdc）
 * @func 0x191bac 0x191bdc  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x191bac ldr r2, [r0]
 *   @0x191bb0 cmp r2, #0
 *   @0x191bb4 bxeq lr
 *   @0x191bb8 ldr r3, [r0, #0xc]
 *   @0x191bbc bic r3, r3, #-16777216
 *   @0x191bc0 cmp r3, #6
 *   @0x191bc4 cmpne r3, #11
 *   @0x191bc8 bxne lr
 *   @0x191bcc mov r0, r1
 *   @0x191bd0 mov r1, r2
 *   @0x191bd4 mov r2, #1
 *   @0x191bd8 b 0x19135c <_ZN13CGCGeneration14AddDynamicRootEP12YYObjectBaseb>
 *
 * ══ §83/350 YYObjectBase::FindOrAllocValue  0x196bc4  size 48  12 条（0x196bc4..0x196bf4）
 * @func 0x196bc4 0x196bf4  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Code_Variable_FindAlloc_Slot_From_Name(YYObjectBase*, char const*)
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x196bc4 push {r4, lr}
 *   @0x196bc8 mov r4, r0
 *   @0x196bcc bl 0xd2c84 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc>
 *   @0x196bd0 ldr r3, [r4, #0x4]
 *   @0x196bd4 cmp r3, #0
 *   @0x196bd8 mov r1, r0
 *   @0x196bdc beq 0x196be8 <_ZN12YYObjectBase16FindOrAllocValueEPKc+0x24>
 *   @0x196be0 add r0, r3, r0, lsl #4
 *   @0x196be4 pop {r4, pc}
 *   @0x196be8 mov r0, r4
 *   @0x196bec pop {r4, lr}
 *   @0x196bf0 b 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *
 * ══ §84/350 Effect_Clear  0x1a277c  size 48  12 条（0x1a277c..0x1a27ac）
 * @func 0x1a277c 0x1a27ac  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleSystem_Particles_Clear(int)
 * 字段偏移 top8: 0x1c×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a277c push {r3, lr}
 *   @0x1a2780 ldr r3, [pc, #0x1c]
 *   @0x1a2784 ldr r3, [pc, r3]
 *   @0x1a2788 ldr r0, [r3]
 *   @0x1a278c bl 0x1a40d4 <_Z30ParticleSystem_Particles_Cleari>
 *   @0x1a2790 ldr r3, [pc, #0x10]
 *   @0x1a2794 ldr r3, [pc, r3]
 *   @0x1a2798 ldr r0, [r3]
 *   @0x1a279c pop {r3, lr}
 *   @0x1a27a0 b 0x1a40d4 <_Z30ParticleSystem_Particles_Cleari>
 *   @0x1a27a4 eoreq lr, r4, r0, lsr #32
 *   @0x1a27a8 eoreq lr, r4, r4, lsl r0
 *
 * ══ §85/350 _GetSpriteFrames  0x1abf6c  size 48  12 条（0x1abf6c..0x1abf9c）
 * @func 0x1abf6c 0x1abf9c  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Sprite_Exists(int) / Sprite_Data(int)
 * 字段偏移 top8: 0x74×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1abf6c push {r4, lr}
 *   @0x1abf70 mov r4, r0
 *   @0x1abf74 bl 0x1eee98 <_Z13Sprite_Existsi>
 *   @0x1abf78 cmp r0, #0
 *   @0x1abf7c popeq {r4, pc}
 *   @0x1abf80 mov r0, r4
 *   @0x1abf84 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x1abf88 ldr r3, [r0, #0x74]
 *   @0x1abf8c cmp r3, #2
 *   @0x1abf90 ldrne r0, [r0, #0x18]
 *   @0x1abf94 moveq r0, #1
 *   @0x1abf98 pop {r4, pc}
 *
 * ══ §86/350 ResetLayerShader  0x1b1170  size 48  12 条（0x1b1170..0x1b11a0）
 * @func 0x1b1170 0x1b11a0  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_Shader_Reset(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x-4×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b1170 cmn r0, #1
 *   @0x1b1174 str lr, [sp, #-0x4]!
 *   @0x1b1178 sub sp, sp, #28
 *   @0x1b117c beq 0x1b1198 <_Z16ResetLayerShaderi+0x28>
 *   @0x1b1180 mov r3, #0
 *   @0x1b1184 add r0, sp, #8
 *   @0x1b1188 mov r1, r3
 *   @0x1b118c str r3, [sp]
 *   @0x1b1190 mov r2, r3
 *   @0x1b1194 bl 0x1e2110 <_Z14F_Shader_ResetR6RValueP9CInstanceS2_iPS_>
 *   @0x1b1198 add sp, sp, #28
 *   @0x1b119c ldr pc, [sp], #4
 *
 * ══ §87/350 ProcessActivateDeactveLists  0x1d3074  size 48  12 条（0x1d3074..0x1d30a4）
 * @func 0x1d3074 0x1d30a4  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CRoom::UpdateActive()
 * 字段偏移 top8: 0x1c×1 / 0x10×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d3074 push {r3, lr}
 *   @0x1d3078 ldr r3, [pc, #0x1c]
 *   @0x1d307c ldr r3, [pc, r3]
 *   @0x1d3080 ldr r0, [r3]
 *   @0x1d3084 bl 0x1abd9c <_ZN5CRoom12UpdateActiveEv>
 *   @0x1d3088 ldr r3, [pc, #0x10]
 *   @0x1d308c mov r2, #0
 *   @0x1d3090 ldr r3, [pc, r3]
 *   @0x1d3094 str r2, [r3, #0x8]
 *   @0x1d3098 pop {r3, pc}
 *   @0x1d309c eoreq r10, r1, r12, lsr #17
 *   @0x1d30a0 .word 0x0021abb8
 *
 * ══ §88/350 CListener::Reset  0x215ab8  size 48  12 条（0x215ab8..0x215ae8）
 * @func 0x215ab8 0x215afc  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65b0
 * 字段偏移 top8: 0x2c×1 / 0x30×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x215ab8 push {r4, lr}
 *   @0x215abc mov r2, #52
 *   @0x215ac0 mov r4, r0
 *   @0x215ac4 mov r1, #0
 *   @0x215ac8 bl 0xb65b0 <memset@plt>
 *   @0x215acc mov r3, #1065353216
 *   @0x215ad0 mov r2, #0
 *   @0x215ad4 str r3, [r4, #0x2c]
 *   @0x215ad8 movt r2, #0xbf80
 *   @0x215adc str r3, [r4, #0x30]
 *   @0x215ae0 str r2, [r4, #0x20]
 *   @0x215ae4 pop {r4, pc}
 *
 * ══ §89/350 _alutInputStreamConstructFromMemory  0x221d94  size 48  12 条（0x221d94..0x221dc4）
 * @func 0x221d94 0x221dc4  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _alutMalloc
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x221d94 push {r3, r4, r5, lr}
 *   @0x221d98 mov r4, r0
 *   @0x221d9c mov r0, #16
 *   @0x221da0 mov r5, r1
 *   @0x221da4 bl 0x222a98 <_alutMalloc>
 *   @0x221da8 cmp r0, #0
 *   @0x221dac strne r5, [r0, #0x8]
 *   @0x221db0 strne r4, [r0, #0xc]
 *   @0x221db4 movne r3, #0
 *   @0x221db8 strbne r3, [r0]
 *   @0x221dbc strne r3, [r0, #0x4]
 *   @0x221dc0 pop {r3, r4, r5, pc}
 *
 * ══ §90/350 _alutMalloc  0x222a98  size 48  12 条（0x222a98..0x222ac8）
 * @func 0x222a98 0x222ac8  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6544 / _alutSetError
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x222a98 cmp r0, #0
 *   @0x222a9c push {r4, lr}
 *   @0x222aa0 moveq r0, #1
 *   @0x222aa4 bl 0xb6544 <malloc@plt>
 *   @0x222aa8 subs r4, r0, #0
 *   @0x222aac beq 0x222ab8 <_alutMalloc+0x20>
 *   @0x222ab0 mov r0, r4
 *   @0x222ab4 pop {r4, pc}
 *   @0x222ab8 mov r0, #512
 *   @0x222abc bl 0x221940 <_alutSetError>
 *   @0x222ac0 mov r0, r4
 *   @0x222ac4 pop {r4, pc}
 *
 * ══ §91/350 JS_IsAccessorDescriptor  0x240828  size 48  12 条（0x240828..0x240858）
 * @func 0x240828 0x240858  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x240828 ldr r3, [r0, #0xc]
 *   @0x24082c bic r3, r3, #-16777216
 *   @0x240830 cmp r3, #6
 *   @0x240834 beq 0x240840 <_Z23JS_IsAccessorDescriptorP6RValue+0x18>
 *   @0x240838 mov r0, #0
 *   @0x24083c bx lr
 *   @0x240840 ldr r3, [r0]
 *   @0x240844 ldr r0, [r3, #0x48]
 *   @0x240848 subs r3, r0, #2
 *   @0x24084c rsbs r0, r3, #0
 *   @0x240850 adcs r0, r0, r3
 *   @0x240854 bx lr
 *
 * ══ §92/350 CodepointToUTF16  0x2424c4  size 48  12 条（0x2424c4..0x2424f4）
 * @func 0x2424c4 0x2424f4  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2424c4 cmp r0, #65536
 *   @0x2424c8 strhlt r0, [r1]
 *   @0x2424cc subge r3, r0, #65536
 *   @0x2424d0 ubfxge r12, r3, #0xa, #0xa
 *   @0x2424d4 ubfxge r3, r3, #0x0, #0xa
 *   @0x2424d8 movlt r0, #1
 *   @0x2424dc subge r12, r12, #10240
 *   @0x2424e0 subge r3, r3, #9216
 *   @0x2424e4 strhge r12, [r1]
 *   @0x2424e8 movge r0, #2
 *   @0x2424ec strhge r3, [r2]
 *   @0x2424f0 bx lr
 *
 * ══ §93/350 bucketFree  0x27c20c  size 48  12 条（0x27c20c..0x27c23c）
 * @func 0x27c20c 0x27c23c  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: globalPageListFindAddr(void const*)
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27c20c push {r4, lr}
 *   @0x27c210 mov r4, r0
 *   @0x27c214 bl 0x27be34 <_Z22globalPageListFindAddrPKv>
 *   @0x27c218 subs r3, r0, #0
 *   @0x27c21c beq 0x27c234 <_Z10bucketFreePKv+0x28>
 *   @0x27c220 ldr r3, [r3]
 *   @0x27c224 mov r1, r4
 *   @0x27c228 ldr r3, [r3, #0xc]
 *   @0x27c22c blx r3
 *   @0x27c230 pop {r4, pc}
 *   @0x27c234 mov r0, r3
 *   @0x27c238 pop {r4, pc}
 *
 * ══ §94/350 json_object_new_boolean  0x27ea48  size 48  12 条（0x27ea48..0x27ea78）
 * @func 0x27ea48 0x27ea78  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_27e408+0x31c
 * 字段偏移 top8: 0xc×1 / 0x18×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27ea48 push {r4, lr}
 *   @0x27ea4c mov r4, r0
 *   @0x27ea50 mov r0, #1
 *   @0x27ea54 bl 0x27e724 <mc_info+0x35c>
 *   @0x27ea58 cmp r0, #0
 *   @0x27ea5c popeq {r4, pc}
 *   @0x27ea60 ldr r3, [pc, #0xc]
 *   @0x27ea64 str r4, [r0, #0x18]
 *   @0x27ea68 add r3, pc, r3
 *   @0x27ea6c str r3, [r0, #0x8]
 *   @0x27ea70 pop {r4, pc}
 *   @0x27ea74 .word 0xfffffd14
 *
 * ══ §95/350 utf8_char_sizeW  0x27ef80  size 48  12 条（0x27ef80..0x27efb0）
 * @func 0x27ef80 0x27efc4  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: utf8_char_sizeW+0x28
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27ef80 cmp r0, #127
 *   @0x27ef84 ble 0x27efa8 <utf8_char_sizeW+0x28>
 *   @0x27ef88 cmp r0, #2048
 *   @0x27ef8c bge 0x27ef98 <utf8_char_sizeW+0x18>
 *   @0x27ef90 mov r0, #2
 *   @0x27ef94 bx lr
 *   @0x27ef98 cmp r0, #65536
 *   @0x27ef9c movlt r0, #3
 *   @0x27efa0 movge r0, #4
 *   @0x27efa4 bx lr
 *   @0x27efa8 mov r0, #1
 *   @0x27efac bx lr
 *
 * ══ §96/350 json_tokener_new  0x27eff0  size 48  12 条（0x27eff0..0x27f020）
 * @func 0x27eff0 0x27f034  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6c34 / printbuf_new / json_tokener_reset
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27eff0 push {r4, lr}
 *   @0x27eff4 mov r0, #1
 *   @0x27eff8 mov r1, #676
 *   @0x27effc bl 0xb6c34 <calloc@plt>
 *   @0x27f000 subs r4, r0, #0
 *   @0x27f004 beq 0x27f018 <json_tokener_new+0x28>
 *   @0x27f008 bl 0x280cc8 <printbuf_new>
 *   @0x27f00c str r0, [r4, #0x4]
 *   @0x27f010 mov r0, r4
 *   @0x27f014 bl 0x27efb0 <json_tokener_reset>
 *   @0x27f018 mov r0, r4
 *   @0x27f01c pop {r4, pc}
 *
 * ══ §97/350 lh_kchar_table_new  0x2808ec  size 48  12 条（0x2808ec..0x28091c）
 * @func 0x2808ec 0x28091c  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: lh_table_new
 * 字段偏移 top8: 0x18×2 / 0x-4×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2808ec str lr, [sp, #-0x4]!
 *   @0x2808f0 sub sp, sp, #12
 *   @0x2808f4 ldr r3, [pc, #0x18]
 *   @0x2808f8 ldr r12, [pc, #0x18]
 *   @0x2808fc ldr r3, [pc, r3]
 *   @0x280900 ldr r12, [pc, r12]
 *   @0x280904 str r12, [sp]
 *   @0x280908 bl 0x280834 <lh_table_new>
 *   @0x28090c add sp, sp, #12
 *   @0x280910 ldr pc, [sp], #4
 *   @0x280914 mulseq r7, r4, pc
 *   @0x280918 mulseq r7, r4, pc
 *
 * ══ §98/350 _spAnimationState_disposeAllEntries  0x28319c  size 48  12 条（0x28319c..0x2831cc）
 * @func 0x28319c 0x2831cc  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28319c cmp r1, #0
 *   @0x2831a0 push {r3, r4, r5, lr}
 *   @0x2831a4 mov r5, r0
 *   @0x2831a8 popeq {r3, r4, r5, pc}
 *   @0x2831ac ldr r4, [r1, #0x4]
 *   @0x2831b0 mov r0, r1
 *   @0x2831b4 ldr r3, [r5, #0x20]
 *   @0x2831b8 blx r3
 *   @0x2831bc cmp r4, #0
 *   @0x2831c0 mov r1, r4
 *   @0x2831c4 bne 0x2831ac <_spAnimationState_disposeAllEntries+0x10>
 *   @0x2831c8 pop {r3, r4, r5, pc}
 *
 * ══ §99/350 b2BroadPhase::CreateProxy  0x2dc888  size 48  12 条（0x2dc888..0x2dc8b8）
 * @func 0x2dc888 0x2dc8cc  size 68  17 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2DynamicTree::CreateProxy(b2AABB const&, void*) / b2BroadPhase::BufferMove(int)
 * 字段偏移 top8: 0x1c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2dc888 push {r3, r4, r5, lr}
 *   @0x2dc88c mov r4, r0
 *   @0x2dc890 bl 0x2df46c <_ZN13b2DynamicTree11CreateProxyERK6b2AABBPv>
 *   @0x2dc894 ldr r3, [r4, #0x1c]
 *   @0x2dc898 add r3, r3, #1
 *   @0x2dc89c str r3, [r4, #0x1c]
 *   @0x2dc8a0 mov r5, r0
 *   @0x2dc8a4 mov r0, r4
 *   @0x2dc8a8 mov r1, r5
 *   @0x2dc8ac bl 0x2dc81c <_ZN12b2BroadPhase10BufferMoveEi>
 *   @0x2dc8b0 mov r0, r5
 *   @0x2dc8b4 pop {r3, r4, r5, pc}
 *
 * ══ §100/350 __aeabi_cdrcmple  0x31b03c  size 48  12 条（0x31b03c..0x31b06c）
 * @func 0x31b03c 0x31b06c  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __nedf2
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31b03c mov r12, r0
 *   @0x31b040 mov r0, r2
 *   @0x31b044 mov r2, r12
 *   @0x31b048 mov r12, r1
 *   @0x31b04c mov r1, r3
 *   @0x31b050 mov r3, r12
 *   @0x31b054 b 0x31b058 <__aeabi_cdcmple>
 *   @0x31b058 push {r0, lr}
 *   @0x31b05c bl 0x31afb4 <__nedf2>
 *   @0x31b060 cmp r0, #0
 *   @0x31b064 cmnmi r0, #0
 *   @0x31b068 pop {r0, pc}
 *
 * ══ §101/350 YYRealloc  0xcef64  size 44  11 条（0xcef64..0xcef90）
 * @func 0xcef64 0xcef90  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x-4×1 / 0x18×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcef64 str lr, [sp, #-0x4]!
 *   @0xcef68 sub sp, sp, #12
 *   @0xcef6c ldr r2, [pc, #0x18]
 *   @0xcef70 mov r3, #0
 *   @0xcef74 str r3, [sp]
 *   @0xcef78 movw r3, #0x512
 *   @0xcef7c add r2, pc, r2
 *   @0xcef80 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0xcef84 add sp, sp, #12
 *   @0xcef88 ldr pc, [sp], #4
 *   @0xcef8c eoreq r3, r6, r0, lsl #5
 *
 * ══ §102/350 YYAllocLocalStackNew  0xd41e4  size 44  11 条（0xd41e4..0xd4210）
 * @func 0xd41e4 0xd4210  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYObjectBase::Alloc(unsigned int, int, bool)
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd41e4 push {r3, lr}
 *   @0xd41e8 mvn r1, #-16777216
 *   @0xd41ec mov r2, #0
 *   @0xd41f0 bl 0x19198c <_ZN12YYObjectBase5AllocEjib>
 *   @0xd41f4 ldr r2, [pc, #0x10]
 *   @0xd41f8 mov r1, #0
 *   @0xd41fc add r2, pc, r2
 *   @0xd4200 str r1, [r0, #0xc]
 *   @0xd4204 str r2, [r0, #0x40]
 *   @0xd4208 pop {r3, pc}
 *   @0xd420c .word 0x0025e5fc
 *
 * ══ §103/350 RenderStateManager::GetSamplerState  0x167fa0  size 44  11 条（0x167fa0..0x167fcc）
 * @func 0x167fa0 0x167fcc  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x167fa0 cmp r1, #7
 *   @0x167fa4 bhi 0x167fc4 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState+0x24>
 *   @0x167fa8 cmp r2, #9
 *   @0x167fac bhi 0x167fc4 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState+0x24>
 *   @0x167fb0 add r1, r1, r1, lsl #2
 *   @0x167fb4 add r2, r2, r1, lsl #1
 *   @0x167fb8 add r2, r2, #156
 *   @0x167fbc ldr r0, [r0, r2, lsl #2]
 *   @0x167fc0 bx lr
 *   @0x167fc4 mov r0, #0
 *   @0x167fc8 bx lr
 *
 * ══ §104/350 GR_D3D_Get_Region  0x168cac  size 44  11 条（0x168cac..0x168cd8）
 * @func 0x168cac 0x168cd8  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x168cac ldr r2, [pc, #0x1c]
 *   @0x168cb0 ldr r3, [pc, #0x1c]
 *   @0x168cb4 ldr r2, [pc, r2]
 *   @0x168cb8 ldr r3, [pc, r3]
 *   @0x168cbc ldr r2, [r2]
 *   @0x168cc0 str r2, [r0]
 *   @0x168cc4 ldr r3, [r3]
 *   @0x168cc8 str r3, [r1]
 *   @0x168ccc bx lr
 *   @0x168cd0 eoreq r7, r8, r0, lsl #9
 *   @0x168cd4 eoreq r7, r8, r0, lsl #9
 *
 * ══ §105/350 CCameraManager::EndRoom  0x16ecf0  size 44  11 条（0x16ecf0..0x16ed1c）
 * @func 0x16ecf0 0x16ed1c  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16ecf0 push {r4, lr}
 *   @0x16ecf4 mov r4, r0
 *   @0x16ecf8 ldr r0, [r0, #0x8]
 *   @0x16ecfc cmp r0, #0
 *   @0x16ed00 popeq {r4, pc}
 *   @0x16ed04 ldr r2, [r0]
 *   @0x16ed08 ldr r3, [r2, #0x4]
 *   @0x16ed0c blx r3
 *   @0x16ed10 mov r3, #0
 *   @0x16ed14 str r3, [r4, #0x8]
 *   @0x16ed18 pop {r4, pc}
 *
 * ══ §106/350 CCameraManager::SetActiveCamera  0x1707c8  size 44  11 条（0x1707c8..0x1707f4）
 * @func 0x1707c8 0x1707f4  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CCameraManager::FindCameraInList(int)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1707c8 cmn r1, #1
 *   @0x1707cc push {r4, lr}
 *   @0x1707d0 moveq r3, #0
 *   @0x1707d4 streq r3, [r0, #0x4]
 *   @0x1707d8 mov r4, r0
 *   @0x1707dc bl 0x16f234 <_ZN14CCameraManager16FindCameraInListEi>
 *   @0x1707e0 cmn r0, #1
 *   @0x1707e4 ldrne r3, [r4, #0xc]
 *   @0x1707e8 ldrne r3, [r3, r0, lsl #2]
 *   @0x1707ec strne r3, [r4, #0x4]
 *   @0x1707f0 pop {r4, pc}
 *
 * ══ §107/350 ConvertComparison  0x17fc3c  size 44  11 条（0x17fc3c..0x17fc68）
 * @func 0x17fc3c 0x17fc68  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17fc3c sub r0, r0, #1
 *   @0x17fc40 cmp r0, #6
 *   @0x17fc44 bhi 0x17fc5c <_Z17ConvertComparison8eCmpFunc+0x20>
 *   @0x17fc48 ldr r3, [pc, #0x14]
 *   @0x17fc4c add r3, pc, r3
 *   @0x17fc50 add r0, r3, r0, lsl #2
 *   @0x17fc54 ldr r0, [r0, #0x28]
 *   @0x17fc58 bx lr
 *   @0x17fc5c movw r0, #0x207
 *   @0x17fc60 bx lr
 *   @0x17fc64 andseq sp, sp, r0, lsl #30
 *
 * ══ §108/350 ConvertFogMode  0x17fcc8  size 44  11 条（0x17fcc8..0x17fcf4）
 * @func 0x17fcc8 0x17fcf4  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×1 / 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17fcc8 cmp r0, #2
 *   @0x17fccc bhi 0x17fce4 <_Z14ConvertFogMode4eFog+0x1c>
 *   @0x17fcd0 ldr r3, [pc, #0x18]
 *   @0x17fcd4 add r3, pc, r3
 *   @0x17fcd8 add r0, r3, r0, lsl #2
 *   @0x17fcdc ldr r0, [r0, #0x44]
 *   @0x17fce0 bx lr
 *   @0x17fce4 mov r0, #1024
 *   @0x17fce8 movt r0, #0x4618
 *   @0x17fcec bx lr
 *   @0x17fcf0 andseq sp, sp, r8, ror lr
 *
 * ══ §109/350 ConvertStencilOp  0x17fcf8  size 44  11 条（0x17fcf8..0x17fd24）
 * @func 0x17fcf8 0x17fd24  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×1 / 0x50×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17fcf8 sub r0, r0, #2
 *   @0x17fcfc cmp r0, #6
 *   @0x17fd00 bhi 0x17fd18 <_Z16ConvertStencilOp10eStencilOp+0x20>
 *   @0x17fd04 ldr r3, [pc, #0x14]
 *   @0x17fd08 add r3, pc, r3
 *   @0x17fd0c add r0, r3, r0, lsl #2
 *   @0x17fd10 ldr r0, [r0, #0x50]
 *   @0x17fd14 bx lr
 *   @0x17fd18 mov r0, #7680
 *   @0x17fd1c bx lr
 *   @0x17fd20 andseq sp, sp, r4, asr #28
 *
 * ══ §110/350 Color_RGB  0x20f9ac  size 44  11 条（0x20f9ac..0x20f9d8）
 * @func 0x20f9ac 0x20f9ec  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20f9ac uxtb r2, r2
 *   @0x20f9b0 uxtb r1, r1
 *   @0x20f9b4 mov r3, #0
 *   @0x20f9b8 bfi r3, r2, #0, #8
 *   @0x20f9bc uxtb r0, r0
 *   @0x20f9c0 bfi r3, r1, #8, #8
 *   @0x20f9c4 bfi r3, r0, #16, #8
 *   @0x20f9c8 sub sp, sp, #8
 *   @0x20f9cc mov r0, r3
 *   @0x20f9d0 add sp, sp, #8
 *   @0x20f9d4 bx lr
 *
 * ══ §111/350 Color_ColorToRGB  0x20fa00  size 44  11 条（0x20fa00..0x20fa2c）
 * @func 0x20fa00 0x20fa40  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20fa00 ldr r3, [r0]
 *   @0x20fa04 mov r0, #0
 *   @0x20fa08 sub sp, sp, #8
 *   @0x20fa0c ubfx r1, r3, #0x10, #0x8
 *   @0x20fa10 ubfx r2, r3, #0x8, #0x8
 *   @0x20fa14 bfi r0, r1, #0, #8
 *   @0x20fa18 uxtb r3, r3
 *   @0x20fa1c bfi r0, r2, #8, #8
 *   @0x20fa20 bfi r0, r3, #16, #8
 *   @0x20fa24 add sp, sp, #8
 *   @0x20fa28 bx lr
 *
 * ══ §112/350 alutCreateBufferFromFileImage  0x222638  size 44  11 条（0x222638..0x222664）
 * @func 0x222638 0x222664  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _alutSanityCheck / _alutInputStreamConstructFromMemory
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x222638 push {r3, r4, r5, lr}
 *   @0x22263c mov r5, r0
 *   @0x222640 mov r4, r1
 *   @0x222644 bl 0x2219a8 <_alutSanityCheck>
 *   @0x222648 cmp r0, #0
 *   @0x22264c popeq {r3, r4, r5, pc}
 *   @0x222650 mov r0, r5
 *   @0x222654 mov r1, r4
 *   @0x222658 bl 0x221d94 <_alutInputStreamConstructFromMemory>
 *   @0x22265c pop {r3, r4, r5, lr}
 *   @0x222660 b 0x2225cc <_alutCreateBufferFromInputStream>
 *
 * ══ §113/350 oggpack_readinit  0x23385c  size 44  11 条（0x23385c..0x233888）
 * @func 0x23385c 0x233888  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65b0
 * 字段偏移 top8: 0x10×1 / 0xc×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23385c push {r4, r5, r6, lr}
 *   @0x233860 mov r4, r0
 *   @0x233864 mov r5, r1
 *   @0x233868 mov r6, r2
 *   @0x23386c mov r1, #0
 *   @0x233870 mov r2, #20
 *   @0x233874 bl 0xb65b0 <memset@plt>
 *   @0x233878 str r6, [r4, #0x10]
 *   @0x23387c str r5, [r4, #0xc]
 *   @0x233880 str r5, [r4, #0x8]
 *   @0x233884 pop {r4, r5, r6, pc}
 *
 * ══ §114/350 ogg_sync_reset  0x235268  size 44  11 条（0x235268..0x235294）
 * @func 0x235268 0x235294  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ogg_sync_check
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x235268 push {r4, lr}
 *   @0x23526c mov r4, r0
 *   @0x235270 bl 0x234b80 <ogg_sync_check>
 *   @0x235274 cmp r0, #0
 *   @0x235278 streq r0, [r4, #0x8]
 *   @0x23527c streq r0, [r4, #0xc]
 *   @0x235280 streq r0, [r4, #0x10]
 *   @0x235284 mvnne r0, #0
 *   @0x235288 streq r0, [r4, #0x14]
 *   @0x23528c streq r0, [r4, #0x18]
 *   @0x235290 pop {r4, pc}
 *
 * ══ §115/350 CPhysicsFixture::~CPhysicsFixture  0x23661c  size 44  11 条（0x23661c..0x236648）
 * @func 0x23661c 0x236648  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsFixture::DeleteShape() / operator delete(void*)
 * 字段偏移 top8: 0x20×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23661c push {r4, lr}
 *   @0x236620 mov r4, r0
 *   @0x236624 bl 0x2365d0 <_ZN15CPhysicsFixture11DeleteShapeEv>
 *   @0x236628 ldr r0, [r4, #0x20]
 *   @0x23662c cmp r0, #0
 *   @0x236630 beq 0x236640 <_ZN15CPhysicsFixtureD2Ev+0x24>
 *   @0x236634 bl 0x27d1d0 <_ZdlPv>
 *   @0x236638 mov r3, #0
 *   @0x23663c str r3, [r4, #0x20]
 *   @0x236640 mov r0, r4
 *   @0x236644 pop {r4, pc}
 *
 * ══ §116/350 strcp_D2A  0x23db24  size 44  11 条（0x23db24..0x23db50）
 * @func 0x23db24 0x23db50  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23db24 ldrb r3, [r1]
 *   @0x23db28 cmp r3, #0
 *   @0x23db2c strb r3, [r0]
 *   @0x23db30 bxeq lr
 *   @0x23db34 add r3, r0, #1
 *   @0x23db38 ldrb r2, [r1, #0x1]!
 *   @0x23db3c mov r0, r3
 *   @0x23db40 cmp r2, #0
 *   @0x23db44 strb r2, [r3], #1
 *   @0x23db48 bne 0x23db38 <strcp_D2A+0x14>
 *   @0x23db4c bx lr
 *
 * ══ §117/350 anon_27b918  0x27b918  size 44  11 条（0x27b918..0x27b944）
 * @func 0x27b918 0x27b944  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6544
 * 字段偏移 top8: 0x14×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27b918 push {r3, lr}
 *   @0x27b91c mov r0, #8
 *   @0x27b920 bl 0xb6544 <malloc@plt>
 *   @0x27b924 ldr r3, [pc, #0x14]
 *   @0x27b928 ldr r1, [pc, #0x14]
 *   @0x27b92c ldr r3, [pc, r3]
 *   @0x27b930 add r1, pc, r1
 *   @0x27b934 str r0, [r3]
 *   @0x27b938 pop {r3, lr}
 *   @0x27b93c b 0x27e038 <_ZN5Mutex4InitEPKc>
 *   @0x27b940 ldrsheq r5, [r7], -r0
 *
 * ══ §118/350 json_object_put  0x27e7c8  size 44  11 条（0x27e7c8..0x27e7f4）
 * @func 0x27e7c8 0x27e7f4  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27e7c8 push {r3, lr}
 *   @0x27e7cc subs r3, r0, #0
 *   @0x27e7d0 popeq {r3, pc}
 *   @0x27e7d4 ldr r2, [r3, #0xc]
 *   @0x27e7d8 sub r2, r2, #1
 *   @0x27e7dc str r2, [r3, #0xc]
 *   @0x27e7e0 cmp r2, #0
 *   @0x27e7e4 popne {r3, pc}
 *   @0x27e7e8 ldr r3, [r3, #0x4]
 *   @0x27e7ec blx r3
 *   @0x27e7f0 pop {r3, pc}
 *
 * ══ §119/350 spAnimationStateData_create  0x283b2c  size 44  11 条（0x283b2c..0x283b58）
 * @func 0x283b2c 0x283b58  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _calloc
 * 字段偏移 top8: 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x283b2c ldr r2, [pc, #0x20]
 *   @0x283b30 mov r1, #12
 *   @0x283b34 push {r4, lr}
 *   @0x283b38 add r2, pc, r2
 *   @0x283b3c mov r4, r0
 *   @0x283b40 mov r3, #75
 *   @0x283b44 mov r0, #1
 *   @0x283b48 bl 0x285c4c <_calloc>
 *   @0x283b4c str r4, [r0]
 *   @0x283b50 pop {r4, pc}
 *   @0x283b54 andeq r3, sp, r12, lsl #19
 *
 * ══ §120/350 spAtlasRegion_dispose  0x2840f4  size 44  11 条（0x2840f4..0x284120）
 * @func 0x2840f4 0x284120  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _free×3
 * 字段偏移 top8: 0x40×1 / 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2840f4 push {r4, lr}
 *   @0x2840f8 mov r4, r0
 *   @0x2840fc ldr r0, [r0]
 *   @0x284100 bl 0x285c80 <_free>
 *   @0x284104 ldr r0, [r4, #0x40]
 *   @0x284108 bl 0x285c80 <_free>
 *   @0x28410c ldr r0, [r4, #0x44]
 *   @0x284110 bl 0x285c80 <_free>
 *   @0x284114 mov r0, r4
 *   @0x284118 pop {r4, lr}
 *   @0x28411c b 0x285c80 <_free>
 *
 * ══ §121/350 spSlot_setAttachment  0x28ee1c  size 44  11 条（0x28ee1c..0x28ee48）
 * @func 0x28ee1c 0x28ee48  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×2 / 0x4×2 / 0x4c×1 / 0x20×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28ee1c ldr r3, [r0, #0x18]
 *   @0x28ee20 cmp r3, r1
 *   @0x28ee24 bxeq lr
 *   @0x28ee28 ldr r2, [r0, #0x4]
 *   @0x28ee2c mov r3, #0
 *   @0x28ee30 str r1, [r0, #0x18]
 *   @0x28ee34 ldr r2, [r2, #0x4]
 *   @0x28ee38 ldr r2, [r2, #0x4c]
 *   @0x28ee3c str r3, [r0, #0x20]
 *   @0x28ee40 str r2, [r0, #0x28]
 *   @0x28ee44 bx lr
 *
 * ══ §122/350 yySocket::Peek  0x295438  size 44  11 条（0x295438..0x295464）
 * @func 0x295438 0x295478  size 64  16 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6db4
 * 字段偏移 top8: 0x-4×2 / 0x4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x295438 str lr, [sp, #-0x4]!
 *   @0x29543c sub sp, sp, #12
 *   @0x295440 add r2, sp, #8
 *   @0x295444 mov r3, #0
 *   @0x295448 movw r1, #0x541b
 *   @0x29544c ldr r0, [r0]
 *   @0x295450 str r3, [r2, #-0x4]!
 *   @0x295454 bl 0xb6db4 <ioctl@plt>
 *   @0x295458 ldr r0, [sp, #0x4]
 *   @0x29545c add sp, sp, #12
 *   @0x295460 ldr pc, [sp], #4
 *
 * ══ §123/350 _spAtlasPage_disposeTexture  0xbd814  size 40  10 条（0xbd814..0xbd83c）
 * @func 0xbd814 0xbd83c  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbd814 ldr r0, [r0, #0x1c]
 *   @0xbd818 cmp r0, #0
 *   @0xbd81c bxeq lr
 *   @0xbd820 ldr r3, [pc, #0x10]
 *   @0xbd824 ldr r3, [pc, r3]
 *   @0xbd828 ldrb r3, [r3]
 *   @0xbd82c cmp r3, #0
 *   @0xbd830 bxeq lr
 *   @0xbd834 b 0x173f84 <_Z15GR_Texture_Freei>
 *   @0xbd838 ldrshteq r0, [r3], -r4
 *
 * ══ §124/350 GetTheStacks  0xffc9c  size 40  10 条（0xffc9c..0xffcc4）
 * @func 0xffc9c 0xffcc4  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xffc9c ldr r2, [pc, #0x18]
 *   @0xffca0 ldr r3, [pc, #0x18]
 *   @0xffca4 ldr r2, [pc, r2]
 *   @0xffca8 ldr r3, [pc, r3]
 *   @0xffcac ldr r2, [r2]
 *   @0xffcb0 str r2, [r0]
 *   @0xffcb4 ldr r0, [r3, #0x4]
 *   @0xffcb8 bx lr
 *   @0xffcbc .word 0x002ee1d8
 *   @0xffcc0 .word 0x002ee1d8
 *
 * ══ §125/350 GetTheQueues  0xffee8  size 40  10 条（0xffee8..0xfff10）
 * @func 0xffee8 0xfff10  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xffee8 ldr r2, [pc, #0x18]
 *   @0xffeec ldr r3, [pc, #0x18]
 *   @0xffef0 ldr r2, [pc, r2]
 *   @0xffef4 ldr r3, [pc, r3]
 *   @0xffef8 ldr r2, [r2]
 *   @0xffefc str r2, [r0]
 *   @0xfff00 ldr r0, [r3, #0x4]
 *   @0xfff04 bx lr
 *   @0xfff08 eoreq sp, lr, r12, ror pc
 *   @0xfff0c eoreq sp, lr, r12, ror pc
 *
 * ══ §126/350 GetThePriorityQueues  0x100244  size 40  10 条（0x100244..0x10026c）
 * @func 0x100244 0x100280  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x100244 ldr r2, [pc, #0x18]
 *   @0x100248 ldr r3, [pc, #0x18]
 *   @0x10024c ldr r2, [pc, r2]
 *   @0x100250 ldr r3, [pc, r3]
 *   @0x100254 ldr r2, [r2]
 *   @0x100258 str r2, [r0]
 *   @0x10025c ldr r0, [r3, #0x4]
 *   @0x100260 bx lr
 *   @0x100264 eoreq sp, lr, r8, lsr #24
 *   @0x100268 eoreq sp, lr, r8, lsr #24
 *
 * ══ §127/350 GetTheGrids  0x10026c  size 40  10 条（0x10026c..0x100294）
 * @func 0x10026c 0x100294  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10026c ldr r2, [pc, #0x18]
 *   @0x100270 ldr r3, [pc, #0x18]
 *   @0x100274 ldr r2, [pc, r2]
 *   @0x100278 ldr r3, [pc, r3]
 *   @0x10027c ldr r2, [r2]
 *   @0x100280 str r2, [r0]
 *   @0x100284 ldr r0, [r3, #0x4]
 *   @0x100288 bx lr
 *   @0x10028c eoreq sp, lr, r0, lsl r12
 *   @0x100290 eoreq sp, lr, r0, lsl r12
 *
 * ══ §128/350 GR_Draw_Get_Alpha  0x169f1c  size 40  10 条（0x169f1c..0x169f44）
 * @func 0x169f1c 0x169f44  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x169f1c ldr r3, [pc, #0x1c]
 *   @0x169f20 vldr s15, [pc, #20]
 *   @0x169f24 ldr r3, [pc, r3]
 *   @0x169f28 vldr s14, [r3]
 *   @0x169f2c vcvt.f32.u32 s14, s14
 *   @0x169f30 vdiv.f32 s15, s14, s15
 *   @0x169f34 vmov r0, s15
 *   @0x169f38 bx lr
 *   @0x169f3c cmnmi pc, #0
 *   @0x169f40 .word 0x00283ddc
 *
 * ══ §129/350 RVALUE_GC  0x191db8  size 40  10 条（0x191db8..0x191de0）
 * @func 0x191db8 0x191de0  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x191db8 ldr r12, [r0]
 *   @0x191dbc cmp r12, #0
 *   @0x191dc0 bxeq lr
 *   @0x191dc4 ldr r3, [r0, #0xc]
 *   @0x191dc8 bic r3, r3, #-16777216
 *   @0x191dcc cmp r3, #6
 *   @0x191dd0 cmpne r3, #11
 *   @0x191dd4 bxne lr
 *   @0x191dd8 mov r0, r12
 *   @0x191ddc b 0x191bdc <_ZN12YYObjectBase7Mark4GCEPji>
 *
 * ══ §130/350 CPath::XPosition  0x1a7598  size 40  10 条（0x1a7598..0x1a75c0）
 * @func 0x1a7598 0x1a75d4  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPath::GetPosition(float, float&, float&, float&)
 * 字段偏移 top8: 0x-4×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a7598 str lr, [sp, #-0x4]!
 *   @0x1a759c sub sp, sp, #28
 *   @0x1a75a0 add r3, sp, #20
 *   @0x1a75a4 add r2, sp, #12
 *   @0x1a75a8 str r3, [sp]
 *   @0x1a75ac add r3, sp, #16
 *   @0x1a75b0 bl 0x1a73bc <_ZN5CPath11GetPositionEfRfS0_S0_>
 *   @0x1a75b4 ldr r0, [sp, #0xc]
 *   @0x1a75b8 add sp, sp, #28
 *   @0x1a75bc ldr pc, [sp], #4
 *
 * ══ §131/350 CPath::YPosition  0x1a75c0  size 40  10 条（0x1a75c0..0x1a75e8）
 * @func 0x1a75c0 0x1a75e8  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPath::GetPosition(float, float&, float&, float&)
 * 字段偏移 top8: 0x-4×1 / 0x10×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a75c0 str lr, [sp, #-0x4]!
 *   @0x1a75c4 sub sp, sp, #28
 *   @0x1a75c8 add r3, sp, #20
 *   @0x1a75cc add r2, sp, #12
 *   @0x1a75d0 str r3, [sp]
 *   @0x1a75d4 add r3, sp, #16
 *   @0x1a75d8 bl 0x1a73bc <_ZN5CPath11GetPositionEfRfS0_S0_>
 *   @0x1a75dc ldr r0, [sp, #0x10]
 *   @0x1a75e0 add sp, sp, #28
 *   @0x1a75e4 ldr pc, [sp], #4
 *
 * ══ §132/350 CTimeLine::GetEvent  0x1f1710  size 40  10 条（0x1f1710..0x1f1738）
 * @func 0x1f1710 0x1f174c  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CTimeLine::GetEvent(int)+0x14 / CTimeLine::GetEvent(int)+0x1c
 * 字段偏移 top8: 0x8×1 / 0xc×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f1710 cmp r1, #0
 *   @0x1f1714 blt 0x1f1724 <_ZN9CTimeLine8GetEventEi+0x14>
 *   @0x1f1718 ldr r3, [r0, #0x8]
 *   @0x1f171c cmp r1, r3
 *   @0x1f1720 blt 0x1f172c <_ZN9CTimeLine8GetEventEi+0x1c>
 *   @0x1f1724 mov r0, #0
 *   @0x1f1728 bx lr
 *   @0x1f172c ldr r3, [r0, #0xc]
 *   @0x1f1730 ldr r0, [r3, r1, lsl #2]
 *   @0x1f1734 bx lr
 *
 * ══ §133/350 CTimeLine::GetStep  0x1f1738  size 40  10 条（0x1f1738..0x1f1760）
 * @func 0x1f1738 0x1f1768  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CTimeLine::GetStep(int)+0x14 / CTimeLine::GetStep(int)+0x1c
 * 字段偏移 top8: 0x8×1 / 0x14×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f1738 cmp r1, #0
 *   @0x1f173c blt 0x1f174c <_ZN9CTimeLine7GetStepEi+0x14>
 *   @0x1f1740 ldr r3, [r0, #0x8]
 *   @0x1f1744 cmp r1, r3
 *   @0x1f1748 blt 0x1f1754 <_ZN9CTimeLine7GetStepEi+0x1c>
 *   @0x1f174c mov r0, #0
 *   @0x1f1750 bx lr
 *   @0x1f1754 ldr r3, [r0, #0x14]
 *   @0x1f1758 ldr r0, [r3, r1, lsl #2]
 *   @0x1f175c bx lr
 *
 * ══ §134/350 Color_HSV  0x20f9d8  size 40  10 条（0x20f9d8..0x20fa00）
 * @func 0x20f9d8 0x20fa14  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20f9d8 uxtb r3, r0
 *   @0x20f9dc uxtb r1, r1
 *   @0x20f9e0 mov r0, #0
 *   @0x20f9e4 bfi r0, r3, #0, #8
 *   @0x20f9e8 uxtb r2, r2
 *   @0x20f9ec bfi r0, r1, #8, #8
 *   @0x20f9f0 bfi r0, r2, #16, #8
 *   @0x20f9f4 sub sp, sp, #8
 *   @0x20f9f8 add sp, sp, #8
 *   @0x20f9fc bx lr
 *
 * ══ §135/350 CAudioGroupMan::GetGroup  0x21df0c  size 40  10 条（0x21df0c..0x21df34）
 * @func 0x21df0c 0x21df34  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CAudioGroupMan::GetGroup(int)+0x20
 * 字段偏移 top8: 0x4×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21df0c cmp r1, #0
 *   @0x21df10 blt 0x21df2c <_ZN14CAudioGroupMan8GetGroupEi+0x20>
 *   @0x21df14 ldr r3, [r0, #0x4]
 *   @0x21df18 cmp r1, r3
 *   @0x21df1c bge 0x21df2c <_ZN14CAudioGroupMan8GetGroupEi+0x20>
 *   @0x21df20 ldr r3, [r0]
 *   @0x21df24 ldr r0, [r3, r1, lsl #2]
 *   @0x21df28 bx lr
 *   @0x21df2c mov r0, #0
 *   @0x21df30 bx lr
 *
 * ══ §136/350 vorbis_block_init  0x2270bc  size 40  10 条（0x2270bc..0x2270e4）
 * @func 0x2270bc 0x2270e4  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65b0
 * 字段偏移 top8: 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2270bc push {r3, r4, r5, lr}
 *   @0x2270c0 mov r4, r1
 *   @0x2270c4 mov r5, r0
 *   @0x2270c8 mov r1, #0
 *   @0x2270cc mov r0, r4
 *   @0x2270d0 mov r2, #88
 *   @0x2270d4 bl 0xb65b0 <memset@plt>
 *   @0x2270d8 str r5, [r4, #0x40]
 *   @0x2270dc mov r0, #0
 *   @0x2270e0 pop {r3, r4, r5, pc}
 *
 * ══ §137/350 vorbis_info_init  0x22ace8  size 40  10 条（0x22ace8..0x22ad10）
 * @func 0x22ace8 0x22ad10  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65b0 / 0xb6c34
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22ace8 push {r4, lr}
 *   @0x22acec mov r1, #0
 *   @0x22acf0 mov r2, #32
 *   @0x22acf4 mov r4, r0
 *   @0x22acf8 bl 0xb65b0 <memset@plt>
 *   @0x22acfc mov r0, #1
 *   @0x22ad00 movw r1, #0xca8
 *   @0x22ad04 bl 0xb6c34 <calloc@plt>
 *   @0x22ad08 str r0, [r4, #0x1c]
 *   @0x22ad0c pop {r4, pc}
 *
 * ══ §138/350 ogg_page_serialno  0x23409c  size 40  10 条（0x23409c..0x2340c4）
 * @func 0x23409c 0x2340d8  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1 / 0xf×1 / 0xe×1 / 0x11×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23409c ldr r3, [r0]
 *   @0x2340a0 ldrb r1, [r3, #0x10]
 *   @0x2340a4 ldrb r12, [r3, #0xf]
 *   @0x2340a8 ldrb r2, [r3, #0xe]
 *   @0x2340ac ldrb r0, [r3, #0x11]
 *   @0x2340b0 lsl r1, r1, #16
 *   @0x2340b4 orr r3, r1, r12, lsl #8
 *   @0x2340b8 orr r3, r3, r2
 *   @0x2340bc orr r0, r3, r0, lsl #24
 *   @0x2340c0 bx lr
 *
 * ══ §139/350 ogg_page_pageno  0x2340c4  size 40  10 条（0x2340c4..0x2340ec）
 * @func 0x2340c4 0x2340ec  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×1 / 0x13×1 / 0x12×1 / 0x15×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2340c4 ldr r3, [r0]
 *   @0x2340c8 ldrb r1, [r3, #0x14]
 *   @0x2340cc ldrb r12, [r3, #0x13]
 *   @0x2340d0 ldrb r2, [r3, #0x12]
 *   @0x2340d4 ldrb r0, [r3, #0x15]
 *   @0x2340d8 lsl r1, r1, #16
 *   @0x2340dc orr r3, r1, r12, lsl #8
 *   @0x2340e0 orr r3, r3, r2
 *   @0x2340e4 orr r0, r3, r0, lsl #24
 *   @0x2340e8 bx lr
 *
 * ══ §140/350 ogg_sync_init  0x234b04  size 40  10 条（0x234b04..0x234b2c）
 * @func 0x234b04 0x234b40  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65b0
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x234b04 push {r3, lr}
 *   @0x234b08 subs r3, r0, #0
 *   @0x234b0c beq 0x234b24 <ogg_sync_init+0x20>
 *   @0x234b10 mvn r2, #0
 *   @0x234b14 mov r1, #0
 *   @0x234b18 str r2, [r3, #0x4]
 *   @0x234b1c mov r2, #28
 *   @0x234b20 bl 0xb65b0 <memset@plt>
 *   @0x234b24 mov r0, #0
 *   @0x234b28 pop {r3, pc}
 *
 * ══ §141/350 CPhysicsWorld::GetParticleGroup  0x239dc0  size 40  10 条（0x239dc0..0x239de8）
 * @func 0x239dc0 0x239de8  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsWorld::GetParticleGroup(int)+0x20
 * 字段偏移 top8: 0x4c×1 / 0x48×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x239dc0 cmp r1, #0
 *   @0x239dc4 blt 0x239de0 <_ZN13CPhysicsWorld16GetParticleGroupEi+0x20>
 *   @0x239dc8 ldr r3, [r0, #0x4c]
 *   @0x239dcc cmp r1, r3
 *   @0x239dd0 bge 0x239de0 <_ZN13CPhysicsWorld16GetParticleGroupEi+0x20>
 *   @0x239dd4 ldr r3, [r0, #0x48]
 *   @0x239dd8 ldr r0, [r3, r1, lsl #2]
 *   @0x239ddc bx lr
 *   @0x239de0 mov r0, #0
 *   @0x239de4 bx lr
 *
 * ══ §142/350 bucketSize  0x27c1e4  size 40  10 条（0x27c1e4..0x27c20c）
 * @func 0x27c1e4 0x27c220  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: globalPageListFindAddr(void const*)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27c1e4 push {r3, lr}
 *   @0x27c1e8 bl 0x27be34 <_Z22globalPageListFindAddrPKv>
 *   @0x27c1ec subs r3, r0, #0
 *   @0x27c1f0 beq 0x27c204 <_Z10bucketSizePKv+0x20>
 *   @0x27c1f4 ldr r3, [r3]
 *   @0x27c1f8 ldr r3, [r3, #0x8]
 *   @0x27c1fc blx r3
 *   @0x27c200 pop {r3, pc}
 *   @0x27c204 mov r0, r3
 *   @0x27c208 pop {r3, pc}
 *
 * ══ §143/350 MemoryManager::SetLength  0x27d068  size 40  10 条（0x27d068..0x27d090）
 * @func 0x27d068 0x27d090  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27d068 push {r4, lr}
 *   @0x27d06c sub sp, sp, #8
 *   @0x27d070 mov r4, r0
 *   @0x27d074 mov r12, #0
 *   @0x27d078 ldr r0, [r0]
 *   @0x27d07c str r12, [sp]
 *   @0x27d080 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x27d084 str r0, [r4]
 *   @0x27d088 add sp, sp, #8
 *   @0x27d08c pop {r4, pc}
 *
 * ══ §144/350 json_object_get_string  0x27ed58  size 40  10 条（0x27ed58..0x27ed80）
 * @func 0x27ed58 0x27ed80  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27ed58 subs r3, r0, #0
 *   @0x27ed5c beq 0x27ed78 <json_object_get_string+0x20>
 *   @0x27ed60 ldr r2, [r3]
 *   @0x27ed64 cmp r2, #6
 *   @0x27ed68 bne 0x27ed74 <json_object_get_string+0x1c>
 *   @0x27ed6c ldr r0, [r3, #0x18]
 *   @0x27ed70 bx lr
 *   @0x27ed74 b 0x27e830 <json_object_to_json_string>
 *   @0x27ed78 mov r0, r3
 *   @0x27ed7c bx lr
 *
 * ══ §145/350 json_tokener_free  0x27f020  size 40  10 条（0x27f020..0x27f048）
 * @func 0x27f020 0x27f048  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: json_tokener_reset / printbuf_free
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27f020 push {r4, lr}
 *   @0x27f024 mov r4, r0
 *   @0x27f028 bl 0x27efb0 <json_tokener_reset>
 *   @0x27f02c cmp r4, #0
 *   @0x27f030 beq 0x27f03c <json_tokener_free+0x1c>
 *   @0x27f034 ldr r0, [r4, #0x4]
 *   @0x27f038 bl 0x280eb0 <printbuf_free>
 *   @0x27f03c mov r0, r4
 *   @0x27f040 pop {r4, lr}
 *   @0x27f044 b 0xb655c <free@plt>
 *
 * ══ §146/350 lh_table_delete  0x280ca0  size 40  10 条（0x280ca0..0x280cc8）
 * @func 0x280ca0 0x280cc8  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: lh_table_lookup_entry
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x280ca0 push {r4, lr}
 *   @0x280ca4 mov r4, r0
 *   @0x280ca8 bl 0x280b1c <lh_table_lookup_entry>
 *   @0x280cac subs r1, r0, #0
 *   @0x280cb0 beq 0x280cc0 <lh_table_delete+0x20>
 *   @0x280cb4 mov r0, r4
 *   @0x280cb8 pop {r4, lr}
 *   @0x280cbc b 0x280bc0 <lh_table_delete_entry>
 *   @0x280cc0 mvn r0, #0
 *   @0x280cc4 pop {r4, pc}
 *
 * ══ §147/350 RelyDeletePacket  0x299be8  size 40  10 条（0x299be8..0x299c10）
 * @func 0x299be8 0x299c24  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RelyRemovePacket(SRelyEntry*) / FreeIBuffer(int) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x299be8 push {r4, lr}
 *   @0x299bec mov r4, r0
 *   @0x299bf0 bl 0x299b9c <_Z16RelyRemovePacketP10SRelyEntry>
 *   @0x299bf4 ldr r0, [r4, #0x4]
 *   @0x299bf8 bl 0xc6a88 <_Z11FreeIBufferi>
 *   @0x299bfc ldr r0, [r4, #0x8]
 *   @0x299c00 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x299c04 mov r0, r4
 *   @0x299c08 pop {r4, lr}
 *   @0x299c0c b 0xb655c <free@plt>
 *
 * ══ §148/350 b2Fixture::SetFilterData  0x2c899c  size 40  10 条（0x2c899c..0x2c89c4）
 * @func 0x2c899c 0x2c89c4  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x8×2 / 0x-4×1 / 0x20×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c899c str r4, [sp, #-0x4]!
 *   @0x2c89a0 add r3, r0, #32
 *   @0x2c89a4 ldr r4, [r1]
 *   @0x2c89a8 ldr r12, [r1, #0x4]
 *   @0x2c89ac str r4, [r0, #0x20]
 *   @0x2c89b0 str r12, [r0, #0x24]
 *   @0x2c89b4 ldrh r2, [r1, #8]
 *   @0x2c89b8 ldr r4, [sp], #4
 *   @0x2c89bc strh r2, [r3, #8]
 *   @0x2c89c0 b 0x2c88fc <_ZN9b2Fixture8RefilterEv>
 *
 * ══ §149/350 b2BroadPhase::~b2BroadPhase  0x2dc7f4  size 40  10 条（0x2dc7f4..0x2dc81c）
 * @func 0x2dc7f4 0x2dc81c  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Free(void*)×2 / b2DynamicTree::~b2DynamicTree()
 * 字段偏移 top8: 0x20×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2dc7f4 push {r4, lr}
 *   @0x2dc7f8 mov r4, r0
 *   @0x2dc7fc ldr r0, [r0, #0x20]
 *   @0x2dc800 bl 0x2c6a70 <_Z6b2FreePv>
 *   @0x2dc804 ldr r0, [r4, #0x2c]
 *   @0x2dc808 bl 0x2c6a70 <_Z6b2FreePv>
 *   @0x2dc80c mov r0, r4
 *   @0x2dc810 bl 0x2de9a4 <_ZN13b2DynamicTreeD2Ev>
 *   @0x2dc814 mov r0, r4
 *   @0x2dc818 pop {r4, pc}
 *
 * ══ §150/350 b2BroadPhase::MoveProxy  0x2dc8b8  size 40  10 条（0x2dc8b8..0x2dc8e0）
 * @func 0x2dc8b8 0x2dc8e0  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2DynamicTree::MoveProxy(int, b2AABB const&, b2Vec2 const&)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2dc8b8 push {r3, r4, r5, lr}
 *   @0x2dc8bc mov r5, r0
 *   @0x2dc8c0 mov r4, r1
 *   @0x2dc8c4 bl 0x2df660 <_ZN13b2DynamicTree9MoveProxyEiRK6b2AABBRK6b2Vec2>
 *   @0x2dc8c8 cmp r0, #0
 *   @0x2dc8cc popeq {r3, r4, r5, pc}
 *   @0x2dc8d0 mov r0, r5
 *   @0x2dc8d4 mov r1, r4
 *   @0x2dc8d8 pop {r3, r4, r5, lr}
 *   @0x2dc8dc b 0x2dc81c <_ZN12b2BroadPhase10BufferMoveEi>
 *
 * ══ §151/350 b2Timer::Reset  0x2e1090  size 40  10 条（0x2e1090..0x2e10b8）
 * @func 0x2e1090 0x2e10cc  size 60  15 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6f70
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e1090 push {r4, lr}
 *   @0x2e1094 sub sp, sp, #8
 *   @0x2e1098 mov r4, r0
 *   @0x2e109c mov r1, #0
 *   @0x2e10a0 mov r0, sp
 *   @0x2e10a4 bl 0xb6f70 <gettimeofday@plt>
 *   @0x2e10a8 ldm sp, {r2, r3}
 *   @0x2e10ac stm r4, {r2, r3}
 *   @0x2e10b0 add sp, sp, #8
 *   @0x2e10b4 pop {r4, pc}
 *
 * ══ §152/350 b2ContactSolver::~b2ContactSolver  0x2e2370  size 40  10 条（0x2e2370..0x2e2398）
 * @func 0x2e2370 0x2e2398  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2StackAllocator::Free(void*)×2
 * 字段偏移 top8: 0x20×2 / 0x28×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e2370 push {r4, lr}
 *   @0x2e2374 mov r4, r0
 *   @0x2e2378 ldr r1, [r4, #0x28]
 *   @0x2e237c ldr r0, [r0, #0x20]
 *   @0x2e2380 bl 0x2e0ffc <_ZN16b2StackAllocator4FreeEPv>
 *   @0x2e2384 ldr r0, [r4, #0x20]
 *   @0x2e2388 ldr r1, [r4, #0x24]
 *   @0x2e238c bl 0x2e0ffc <_ZN16b2StackAllocator4FreeEPv>
 *   @0x2e2390 mov r0, r4
 *   @0x2e2394 pop {r4, pc}
 *
 * ══ §153/350 ParamSizeOnStack  0xd7760  size 36  9 条（0xd7760..0xd7784）
 * @func 0xd7760 0xd7784  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd7760 cmp r0, #6
 *   @0xd7764 bhi 0xd7778 <_Z16ParamSizeOnStacki+0x18>
 *   @0xd7768 ldr r3, [pc, #0x10]
 *   @0xd776c add r3, pc, r3
 *   @0xd7770 ldr r0, [r3, r0, lsl #2]
 *   @0xd7774 bx lr
 *   @0xd7778 mov r0, #0
 *   @0xd777c bx lr
 *   @0xd7780 .word 0x002850f4
 *
 * ══ §154/350 DS_AutoMutex::~DS_AutoMutex  0xfec6c  size 36  9 条（0xfec6c..0xfec90）
 * @func 0xfec6c 0xfec90  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Mutex::Unlock()
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfec6c ldr r3, [pc, #0x18]
 *   @0xfec70 push {r4, lr}
 *   @0xfec74 ldr r3, [pc, r3]
 *   @0xfec78 mov r4, r0
 *   @0xfec7c ldr r0, [r3]
 *   @0xfec80 bl 0x27e09c <_ZN5Mutex6UnlockEv>
 *   @0xfec84 mov r0, r4
 *   @0xfec88 pop {r4, pc}
 *   @0xfec8c eoreq pc, lr, r8, lsl r2
 *
 * ══ §155/350 GetRawMouseX  0x159e8c  size 36  9 条（0x159e8c..0x159eb0）
 * @func 0x159e8c 0x159eb0  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x159e8c cmp r0, #10
 *   @0x159e90 bhi 0x159ea4 <_Z12GetRawMouseXi+0x18>
 *   @0x159e94 ldr r3, [pc, #0x10]
 *   @0x159e98 ldr r3, [pc, r3]
 *   @0x159e9c ldr r0, [r3, r0, lsl #2]
 *   @0x159ea0 bx lr
 *   @0x159ea4 mov r0, #0
 *   @0x159ea8 bx lr
 *   @0x159eac eoreq r5, r9, r4, lsl #26
 *
 * ══ §156/350 GetRawMouseY  0x159eec  size 36  9 条（0x159eec..0x159f10）
 * @func 0x159eec 0x159f10  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x159eec cmp r0, #10
 *   @0x159ef0 bhi 0x159f04 <_Z12GetRawMouseYi+0x18>
 *   @0x159ef4 ldr r3, [pc, #0x10]
 *   @0x159ef8 ldr r3, [pc, r3]
 *   @0x159efc ldr r0, [r3, r0, lsl #2]
 *   @0x159f00 bx lr
 *   @0x159f04 mov r0, #0
 *   @0x159f08 bx lr
 *   @0x159f0c eoreq r5, r9, r0, lsr #25
 *
 * ══ §157/350 GR_Window_Views_Mouse_Get_X  0x17ad8c  size 36  9 条（0x17ad8c..0x17adb0）
 * @func 0x17ad8c 0x17adc4  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Window_Views_Mouse_Get_XY(int&, int&, int)
 * 字段偏移 top8: 0x-4×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17ad8c str lr, [sp, #-0x4]!
 *   @0x17ad90 sub sp, sp, #12
 *   @0x17ad94 mov r2, r0
 *   @0x17ad98 add r1, sp, #4
 *   @0x17ad9c mov r0, sp
 *   @0x17ada0 bl 0x17acec <_Z28GR_Window_Views_Mouse_Get_XYRiS_i>
 *   @0x17ada4 ldr r0, [sp]
 *   @0x17ada8 add sp, sp, #12
 *   @0x17adac ldr pc, [sp], #4
 *
 * ══ §158/350 GR_Window_Views_Mouse_Get_Y  0x17adb0  size 36  9 条（0x17adb0..0x17add4）
 * @func 0x17adb0 0x17add4  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Window_Views_Mouse_Get_XY(int&, int&, int)
 * 字段偏移 top8: 0x4×2 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17adb0 str lr, [sp, #-0x4]!
 *   @0x17adb4 sub sp, sp, #12
 *   @0x17adb8 mov r2, r0
 *   @0x17adbc add r1, sp, #4
 *   @0x17adc0 mov r0, sp
 *   @0x17adc4 bl 0x17acec <_Z28GR_Window_Views_Mouse_Get_XYRiS_i>
 *   @0x17adc8 ldr r0, [sp, #0x4]
 *   @0x17adcc add sp, sp, #12
 *   @0x17add0 ldr pc, [sp], #4
 *
 * ══ §159/350 IO_Wheel_Up  0x18c168  size 36  9 条（0x18c168..0x18c18c）
 * @func 0x18c168 0x18c1a0  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18c168 cmp r0, #9
 *   @0x18c16c bhi 0x18c180 <_Z11IO_Wheel_Upi+0x18>
 *   @0x18c170 ldr r3, [pc, #0x10]
 *   @0x18c174 ldr r3, [pc, r3]
 *   @0x18c178 ldrb r0, [r3, r0]
 *   @0x18c17c bx lr
 *   @0x18c180 mov r0, #0
 *   @0x18c184 bx lr
 *   @0x18c188 eoreq r4, r6, r12, lsl #9
 *
 * ══ §160/350 IO_Wheel_Down  0x18c18c  size 36  9 条（0x18c18c..0x18c1b0）
 * @func 0x18c18c 0x18c1b0  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18c18c cmp r0, #9
 *   @0x18c190 bhi 0x18c1a4 <_Z13IO_Wheel_Downi+0x18>
 *   @0x18c194 ldr r3, [pc, #0x10]
 *   @0x18c198 ldr r3, [pc, r3]
 *   @0x18c19c ldrb r0, [r3, r0]
 *   @0x18c1a0 bx lr
 *   @0x18c1a4 mov r0, #0
 *   @0x18c1a8 bx lr
 *   @0x18c1ac eoreq r4, r6, r12, ror #8
 *
 * ══ §161/350 CGCGeneration::UpdateRange  0x19150c  size 36  9 条（0x19150c..0x191530）
 * @func 0x19150c 0x191530  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19150c ldr r2, [r0, #0x14]
 *   @0x191510 ldr r3, [r0, #0x18]
 *   @0x191514 cmp r2, r1
 *   @0x191518 strle r2, [r0, #0x14]
 *   @0x19151c strgt r1, [r0, #0x14]
 *   @0x191520 cmp r3, r1
 *   @0x191524 strge r3, [r0, #0x18]
 *   @0x191528 strlt r1, [r0, #0x18]
 *   @0x19152c bx lr
 *
 * ══ §162/350 ConvertXDPI  0x1d66c0  size 36  9 条（0x1d66c0..0x1d66e4）
 * @func 0x1d66c0 0x1d66f8  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetDPIX()
 * 字段偏移 top8: 无
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d66c0 push {r3, lr}
 *   @0x1d66c4 vpush {d8}
 *   @0x1d66c8 vmov s16, r0
 *   @0x1d66cc bl 0x15f244 <_Z7GetDPIXv>
 *   @0x1d66d0 vmov s15, r0
 *   @0x1d66d4 vdiv.f32 s15, s16, s15
 *   @0x1d66d8 vpop {d8}
 *   @0x1d66dc vmov r0, s15
 *   @0x1d66e0 pop {r3, pc}
 *
 * ══ §163/350 ConvertYDPI  0x1d66e4  size 36  9 条（0x1d66e4..0x1d6708）
 * @func 0x1d66e4 0x1d6708  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetDPIY()
 * 字段偏移 top8: 无
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d66e4 push {r3, lr}
 *   @0x1d66e8 vpush {d8}
 *   @0x1d66ec vmov s16, r0
 *   @0x1d66f0 bl 0x15f258 <_Z7GetDPIYv>
 *   @0x1d66f4 vmov s15, r0
 *   @0x1d66f8 vdiv.f32 s15, s16, s15
 *   @0x1d66fc vpop {d8}
 *   @0x1d6700 vmov r0, s15
 *   @0x1d6704 pop {r3, pc}
 *
 * ══ §164/350 _ilog  0x22eaf0  size 36  9 条（0x22eaf0..0x22eb14）
 * @func 0x22eaf0 0x22eb14  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22eaf0 subs r3, r0, #0
 *   @0x22eaf4 beq 0x22eb0c <_ilog+0x1c>
 *   @0x22eaf8 mov r0, #0
 *   @0x22eafc lsrs r3, r3, #1
 *   @0x22eb00 add r0, r0, #1
 *   @0x22eb04 bne 0x22eafc <_ilog+0xc>
 *   @0x22eb08 bx lr
 *   @0x22eb0c mov r0, r3
 *   @0x22eb10 bx lr
 *
 * ══ §165/350 ogg_stream_check  0x23412c  size 36  9 条（0x23412c..0x234150）
 * @func 0x23412c 0x234150  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23412c cmp r0, #0
 *   @0x234130 beq 0x234148 <ogg_stream_check+0x1c>
 *   @0x234134 ldr r0, [r0]
 *   @0x234138 cmp r0, #0
 *   @0x23413c movne r0, #0
 *   @0x234140 mvneq r0, #0
 *   @0x234144 bx lr
 *   @0x234148 mvn r0, #0
 *   @0x23414c bx lr
 *
 * ══ §166/350 CCodepointIterator_UTF8::CCodepointIterator_UTF8  0x2423d8  size 36  9 条（0x2423d8..0x2423fc）
 * @func 0x2423d8 0x242408  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538
 * 字段偏移 top8: 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2423d8 push {r4, lr}
 *   @0x2423dc mov r4, r0
 *   @0x2423e0 str r1, [r4]
 *   @0x2423e4 mov r0, r1
 *   @0x2423e8 str r1, [r4, #0x4]
 *   @0x2423ec bl 0xb6538 <strlen@plt>
 *   @0x2423f0 str r0, [r4, #0x8]
 *   @0x2423f4 mov r0, r4
 *   @0x2423f8 pop {r4, pc}
 *
 * ══ §167/350 lh_abort  0x280810  size 36  9 条（0x280810..0x280834）
 * @func 0x280810 0x280834  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6cf4 / 0xb6688
 * 字段偏移 top8: 0x-4×1 / 0x10×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x280810 push {r0, r1, r2, r3}
 *   @0x280814 str lr, [sp, #-0x4]!
 *   @0x280818 sub sp, sp, #12
 *   @0x28081c add r1, sp, #20
 *   @0x280820 ldr r0, [sp, #0x10]
 *   @0x280824 str r1, [sp, #0x4]
 *   @0x280828 bl 0xb6cf4 <vprintf@plt>
 *   @0x28082c mov r0, #1
 *   @0x280830 bl 0xb6688 <exit@plt>
 *
 * ══ §168/350 spSkeletonBounds_create  0x28a834  size 36  9 条（0x28a834..0x28a858）
 * @func 0x28a834 0x28a858  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _calloc
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28a834 ldr r2, [pc, #0x18]
 *   @0x28a838 mov r1, #32
 *   @0x28a83c push {r3, lr}
 *   @0x28a840 add r2, pc, r2
 *   @0x28a844 mov r3, #93
 *   @0x28a848 mov r0, #1
 *   @0x28a84c bl 0x285c4c <_calloc>
 *   @0x28a850 pop {r3, pc}
 *   @0x28a854 andeq sp, r12, r12, lsr #4
 *
 * ══ §169/350 yyServer::Process  0x297f98  size 36  9 条（0x297f98..0x297fbc）
 * @func 0x297f98 0x297fbc  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x297f98 ldr r2, [r0]
 *   @0x297f9c cmp r2, #0
 *   @0x297fa0 bxeq lr
 *   @0x297fa4 ldr r3, [r0, #0x20]
 *   @0x297fa8 cmp r3, #0
 *   @0x297fac cmpne r3, #3
 *   @0x297fb0 beq 0x297fb8 <_ZN8yyServer7ProcessEv+0x20>
 *   @0x297fb4 b 0x297dec <_ZN8yyServer10ProcessUDPEv>
 *   @0x297fb8 b 0x297750 <_ZN8yyServer10ProcessTCPEv>
 *
 * ══ §170/350 RelyDeletePacket  0x299c10  size 36  9 条（0x299c10..0x299c34）
 * @func 0x299c10 0x299c34  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RelyFindPacket(int) / RelyDeletePacket(SRelyEntry*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x299c10 push {r3, lr}
 *   @0x299c14 bl 0x299b60 <_Z14RelyFindPacketi>
 *   @0x299c18 subs r3, r0, #0
 *   @0x299c1c beq 0x299c2c <_Z16RelyDeletePacketi+0x1c>
 *   @0x299c20 bl 0x299be8 <_Z16RelyDeletePacketP10SRelyEntry>
 *   @0x299c24 mov r0, #1
 *   @0x299c28 pop {r3, pc}
 *   @0x299c2c mov r0, r3
 *   @0x299c30 pop {r3, pc}
 *
 * ══ §171/350 b2ParticleSystem::GetCriticalPressure  0x2d8584  size 36  9 条（0x2d8584..0x2d85a8）
 * @func 0x2d8584 0x2d85bc  size 56  14 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ParticleSystem::GetCriticalVelocitySquared(b2TimeStep const&) const
 * 字段偏移 top8: 无
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d8584 push {r3, lr}
 *   @0x2d8588 vpush {d8}
 *   @0x2d858c vldr s16, [r0, #12]
 *   @0x2d8590 bl 0x2d856c <_ZNK16b2ParticleSystem26GetCriticalVelocitySquaredERK10b2TimeStep>
 *   @0x2d8594 vmov s15, r0
 *   @0x2d8598 vmul.f32 s15, s16, s15
 *   @0x2d859c vpop {d8}
 *   @0x2d85a0 vmov r0, s15
 *   @0x2d85a4 pop {r3, pc}
 *
 * ══ §172/350 b2ParticleSystem::GetParticleMass  0x2d85bc  size 36  9 条（0x2d85bc..0x2d85e0）
 * @func 0x2d85bc 0x2d85e0  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ParticleSystem::GetParticleStride() const
 * 字段偏移 top8: 无
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d85bc push {r4, lr}
 *   @0x2d85c0 mov r4, r0
 *   @0x2d85c4 bl 0x2d85a8 <_ZNK16b2ParticleSystem17GetParticleStrideEv>
 *   @0x2d85c8 vldr s15, [r4, #12]
 *   @0x2d85cc vmov s14, r0
 *   @0x2d85d0 vmul.f32 s15, s14, s15
 *   @0x2d85d4 vmul.f32 s14, s15, s14
 *   @0x2d85d8 vmov r0, s14
 *   @0x2d85dc pop {r4, pc}
 *
 * ══ §173/350 b2ParticleSystem::GetParticleInvMass  0x2d8a20  size 36  9 条（0x2d8a20..0x2d8a44）
 * @func 0x2d8a20 0x2d8a44  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d8a20 vldr s14, [r0, #16]
 *   @0x2d8a24 vldr s15, [pc, #20]
 *   @0x2d8a28 vmul.f32 s14, s14, s15
 *   @0x2d8a2c vldr s15, [r0, #28]
 *   @0x2d8a30 vmul.f32 s14, s14, s15
 *   @0x2d8a34 vmul.f32 s14, s15, s14
 *   @0x2d8a38 vmov r0, s14
 *   @0x2d8a3c bx lr
 *   @0x2d8a40 svclo #0xe38e32
 *
 * ══ §174/350 __floatunsidf  0x3190c4  size 36  9 条（0x3190c4..0x3190e8）
 * @func 0x3190c4 0x3190e8  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x3190c4 teq r0, #0
 *   @0x3190c8 moveq r1, #0
 *   @0x3190cc bxeq lr
 *   @0x3190d0 push {r4, r5, lr}
 *   @0x3190d4 mov r4, #1024
 *   @0x3190d8 add r4, r4, #50
 *   @0x3190dc mov r5, #0
 *   @0x3190e0 mov r1, #0
 *   @0x3190e4 b 0x318f60 <__aeabi_dadd+0x148>
 *
 * ══ §175/350 __aeabi_cfrcmple  0x31b198  size 36  9 条（0x31b198..0x31b1bc）
 * @func 0x31b198 0x31b1bc  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __nesf2
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31b198 mov r12, r0
 *   @0x31b19c mov r0, r1
 *   @0x31b1a0 mov r1, r12
 *   @0x31b1a4 b 0x31b1a8 <__aeabi_cfcmple>
 *   @0x31b1a8 push {r0, r1, r2, r3, lr}
 *   @0x31b1ac bl 0x31b134 <__nesf2>
 *   @0x31b1b0 cmp r0, #0
 *   @0x31b1b4 cmnmi r0, #0
 *   @0x31b1b8 pop {r0, r1, r2, r3, pc}
 *
 * ══ §176/350 YYRandom  0xc4600  size 32  8 条（0xc4600..0xc4620）
 * @func 0xc4600 0xc4620  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYRandom() / __aeabi_uidivmod
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc4600 push {r4, lr}
 *   @0xc4604 mov r4, r0
 *   @0xc4608 bl 0xc44ec <_Z8YYRandomv>
 *   @0xc460c eor r1, r4, r4, asr #31
 *   @0xc4610 sub r1, r1, r4, asr #31
 *   @0xc4614 bl 0x318cf0 <__aeabi_uidivmod>
 *   @0xc4618 mov r0, r1
 *   @0xc461c pop {r4, pc}
 *
 * ══ §177/350 SPushNotificationEvent::~SPushNotificationEvent  0x155b80  size 32  8 条（0x155b80..0x155ba0）
 * @func 0x155b80 0x155ba0  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)
 * 字段偏移 top8: 0xc×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x155b80 push {r4, lr}
 *   @0x155b84 mov r4, r0
 *   @0x155b88 ldr r0, [r0, #0xc]
 *   @0x155b8c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x155b90 mov r3, #0
 *   @0x155b94 mov r0, r4
 *   @0x155b98 str r3, [r4, #0xc]
 *   @0x155b9c pop {r4, pc}
 *
 * ══ §178/350 GetBrowserWidthM  0x15e60c  size 32  8 条（0x15e60c..0x15e62c）
 * @func 0x15e60c 0x15e640  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15e60c ldr r3, [pc, #0x14]
 *   @0x15e610 ldr r3, [pc, r3]
 *   @0x15e614 ldr r0, [r3]
 *   @0x15e618 vmov s15, r0
 *   @0x15e61c vcvt.f64.s32 d7, s15
 *   @0x15e620 vmov r0, r1, d7
 *   @0x15e624 bx lr
 *   @0x15e628 eoreq r1, r9, r12, lsl #17
 *
 * ══ §179/350 GetBrowserHeightM  0x15e62c  size 32  8 条（0x15e62c..0x15e64c）
 * @func 0x15e62c 0x15e64c  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15e62c ldr r3, [pc, #0x14]
 *   @0x15e630 ldr r3, [pc, r3]
 *   @0x15e634 ldr r0, [r3]
 *   @0x15e638 vmov s15, r0
 *   @0x15e63c vcvt.f64.s32 d7, s15
 *   @0x15e640 vmov r0, r1, d7
 *   @0x15e644 bx lr
 *   @0x15e648 eoreq r1, r9, r0, ror r8
 *
 * ══ §180/350 CCameraManager::GetCamera  0x16f45c  size 32  8 条（0x16f45c..0x16f47c）
 * @func 0x16f45c 0x16f47c  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CCameraManager::FindCameraInList(int)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16f45c push {r4, lr}
 *   @0x16f460 mov r4, r0
 *   @0x16f464 bl 0x16f234 <_ZN14CCameraManager16FindCameraInListEi>
 *   @0x16f468 cmn r0, #1
 *   @0x16f46c ldrne r3, [r4, #0xc]
 *   @0x16f470 ldrne r0, [r3, r0, lsl #2]
 *   @0x16f474 moveq r0, #0
 *   @0x16f478 pop {r4, pc}
 *
 * ══ §181/350 unsigned int CHashMapCalculateHash<char const*>  0x1eeb88  size 32  8 条（0x1eeb88..0x1eeba8）
 * @func 0x1eeb88 0x1eebbc  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1eeb88 push {r4, lr}
 *   @0x1eeb8c mov r4, r0
 *   @0x1eeb90 bl 0xb6538 <strlen@plt>
 *   @0x1eeb94 mov r2, #0
 *   @0x1eeb98 mov r1, r0
 *   @0x1eeb9c mov r0, r4
 *   @0x1eeba0 pop {r4, lr}
 *   @0x1eeba4 b 0x1eea84 <_Z10murmurhashPKcjj>
 *
 * ══ §182/350 ContactsStack::Pop  0x23c128  size 32  8 条（0x23c128..0x23c148）
 * @func 0x23c128 0x23c148  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23c128 ldm r0, {r2, r3}
 *   @0x23c12c cmp r3, #0
 *   @0x23c130 subgt r3, r3, #1
 *   @0x23c134 strgt r3, [r0, #0x4]
 *   @0x23c138 movgt r1, #716
 *   @0x23c13c mlagt r0, r1, r3, r2
 *   @0x23c140 movle r0, #0
 *   @0x23c144 bx lr
 *
 * ══ §183/350 i2b_D2A  0x23d478  size 32  8 条（0x23d478..0x23d498）
 * @func 0x23d478 0x23d498  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Balloc_D2A
 * 字段偏移 top8: 0x14×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23d478 push {r4, lr}
 *   @0x23d47c mov r4, r0
 *   @0x23d480 mov r0, #1
 *   @0x23d484 bl 0x23d1f8 <Balloc_D2A>
 *   @0x23d488 mov r2, #1
 *   @0x23d48c str r4, [r0, #0x14]
 *   @0x23d490 str r2, [r0, #0x10]
 *   @0x23d494 pop {r4, pc}
 *
 * ══ §184/350 printbuf_free  0x280eb0  size 32  8 条（0x280eb0..0x280ed0）
 * @func 0x280eb0 0x280ed0  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb655c
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x280eb0 push {r4, lr}
 *   @0x280eb4 subs r4, r0, #0
 *   @0x280eb8 popeq {r4, pc}
 *   @0x280ebc ldr r0, [r4]
 *   @0x280ec0 bl 0xb655c <free@plt>
 *   @0x280ec4 mov r0, r4
 *   @0x280ec8 pop {r4, lr}
 *   @0x280ecc b 0xb655c <free@plt>
 *
 * ══ §185/350 spAtlasPage_dispose  0x2840b8  size 32  8 条（0x2840b8..0x2840d8）
 * @func 0x2840b8 0x2840ec  size 52  13 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _spAtlasPage_disposeTexture / _free
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2840b8 push {r4, lr}
 *   @0x2840bc mov r4, r0
 *   @0x2840c0 bl 0xbd814 <_spAtlasPage_disposeTexture>
 *   @0x2840c4 ldr r0, [r4, #0x4]
 *   @0x2840c8 bl 0x285c80 <_free>
 *   @0x2840cc mov r0, r4
 *   @0x2840d0 pop {r4, lr}
 *   @0x2840d4 b 0x285c80 <_free>
 *
 * ══ §186/350 spAttachmentLoader_dispose  0x284d38  size 32  8 条（0x284d38..0x284d58）
 * @func 0x284d38 0x284d58  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x284d38 ldr r3, [r0, #0x8]
 *   @0x284d3c push {r4, lr}
 *   @0x284d40 mov r4, r0
 *   @0x284d44 ldr r3, [r3, #0xc]
 *   @0x284d48 blx r3
 *   @0x284d4c mov r0, r4
 *   @0x284d50 pop {r4, lr}
 *   @0x284d54 b 0x285c80 <_free>
 *
 * ══ §187/350 CProfiler::Pause  0x2a04b8  size 32  8 条（0x2a04b8..0x2a04d8）
 * @func 0x2a04b8 0x2a04d8  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x12×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a04b8 cmp r1, #0
 *   @0x2a04bc strb r1, [r0, #0x12]
 *   @0x2a04c0 ldrne r3, [pc, #0xc]
 *   @0x2a04c4 movne r2, #0
 *   @0x2a04c8 ldrne r3, [pc, r3]
 *   @0x2a04cc strbne r2, [r3]
 *   @0x2a04d0 bx lr
 *   @0x2a04d4 andseq sp, r4, r0, lsr #13
 *
 * ══ §188/350 b2Draw::b2Draw  0x2c67b8  size 32  8 条（0x2c67b8..0x2c67d8）
 * @func 0x2c67b8 0x2c67d8  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c67b8 ldr r3, [pc, #0x14]
 *   @0x2c67bc mov r1, #0
 *   @0x2c67c0 str r1, [r0, #0x4]
 *   @0x2c67c4 ldr r3, [pc, r3]
 *   @0x2c67c8 add r3, r3, #8
 *   @0x2c67cc str r3, [r0]
 *   @0x2c67d0 bx lr
 *   @0x2c67d4 andseq r10, r2, r8, lsr #26
 *
 * ══ §189/350 b2World::DestroyParticlesInGroup  0x2cb548  size 32  8 条（0x2cb548..0x2cb568）
 * @func 0x2cb548 0x2cb568  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb548 movw r3, #0x91d4
 *   @0x2cb54c movt r3, #0x1
 *   @0x2cb550 ldr r3, [r0, r3]
 *   @0x2cb554 tst r3, #2
 *   @0x2cb558 bxne lr
 *   @0x2cb55c add r0, r0, #102400
 *   @0x2cb560 add r0, r0, #628
 *   @0x2cb564 b 0x2d52c4 <_ZN16b2ParticleSystem23DestroyParticlesInGroupEP15b2ParticleGroupb>
 *
 * ══ §190/350 __aeabi_uidivmod  0x318cf0  size 32  8 条（0x318cf0..0x318d10）
 * @func 0x318cf0 0x318d10  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __udivsi3
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x318cf0 cmp r1, #0
 *   @0x318cf4 beq 0x318ce4 <__udivsi3+0x9c>
 *   @0x318cf8 push {r0, r1, lr}
 *   @0x318cfc bl 0x318c48 <__udivsi3>
 *   @0x318d00 pop {r1, r2, lr}
 *   @0x318d04 mul r3, r2, r0
 *   @0x318d08 sub r1, r1, r3
 *   @0x318d0c bx lr
 *
 * ══ §191/350 __aeabi_idivmod  0x318dec  size 32  8 条（0x318dec..0x318e0c）
 * @func 0x318dec 0x318e0c  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __divsi3+0x8
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x318dec cmp r1, #0
 *   @0x318df0 beq 0x318ddc <__divsi3+0xcc>
 *   @0x318df4 push {r0, r1, lr}
 *   @0x318df8 bl 0x318d18 <__divsi3+0x8>
 *   @0x318dfc pop {r1, r2, lr}
 *   @0x318e00 mul r3, r2, r0
 *   @0x318e04 sub r1, r1, r3
 *   @0x318e08 bx lr
 *
 * ══ §192/350 _IsPowerOfTwo  0x180ad0  size 28  7 条（0x180ad0..0x180aec）
 * @func 0x180ad0 0x180b00  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x180ad0 cmp r0, #0
 *   @0x180ad4 bxeq lr
 *   @0x180ad8 sub r3, r0, #1
 *   @0x180adc tst r3, r0
 *   @0x180ae0 movne r0, #0
 *   @0x180ae4 moveq r0, #1
 *   @0x180ae8 bx lr
 *
 * ══ §193/350 Graphics::FreeVerts  0x185600  size 28  7 条（0x185600..0x18561c）
 * @func 0x185600 0x185624  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x185600 ldr r3, [pc, #0x10]
 *   @0x185604 ldr r3, [pc, r3]
 *   @0x185608 ldr r2, [r3]
 *   @0x18560c rsb r0, r0, r2
 *   @0x185610 str r0, [r3]
 *   @0x185614 bx lr
 *   @0x185618 mlaeq r6, r8, pc, r10
 *
 * ══ §194/350 Color_RGBToColor  0x20fa2c  size 28  7 条（0x20fa2c..0x20fa48）
 * @func 0x20fa2c 0x20fa48  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20fa2c ldrb r1, [r0, #0x1]
 *   @0x20fa30 ldrb r2, [r0]
 *   @0x20fa34 ldrb r3, [r0, #0x2]
 *   @0x20fa38 lsl r0, r1, #8
 *   @0x20fa3c add r0, r0, r2, lsl #16
 *   @0x20fa40 add r0, r0, r3
 *   @0x20fa44 bx lr
 *
 * ══ §195/350 CAudioGroupMan::IncSoundCount  0x21df5c  size 28  7 条（0x21df5c..0x21df78）
 * @func 0x21df5c 0x21df78  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CAudioGroupMan::GetGroup(int)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21df5c push {r3, lr}
 *   @0x21df60 bl 0x21df0c <_ZN14CAudioGroupMan8GetGroupEi>
 *   @0x21df64 cmp r0, #0
 *   @0x21df68 ldrne r3, [r0, #0x8]
 *   @0x21df6c addne r3, r3, #1
 *   @0x21df70 strne r3, [r0, #0x8]
 *   @0x21df74 pop {r3, pc}
 *
 * ══ §196/350 alutGetError  0x221714  size 28  7 条（0x221714..0x221730）
 * @func 0x221714 0x221730  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x221714 ldr r3, [pc, #0x10]
 *   @0x221718 mov r2, #0
 *   @0x22171c add r3, pc, r3
 *   @0x221720 ldr r0, [r3]
 *   @0x221724 str r2, [r3]
 *   @0x221728 bx lr
 *   @0x22172c subseq r3, r3, r8, asr #26
 *
 * ══ §197/350 pcre_free_substring  0x25f6ac  size 28  7 条（0x25f6ac..0x25f6c8）
 * @func 0x25f6ac 0x25f6c8  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x25f6ac push {r3, lr}
 *   @0x25f6b0 ldr r3, [pc, #0xc]
 *   @0x25f6b4 ldr r3, [pc, r3]
 *   @0x25f6b8 ldr r3, [r3]
 *   @0x25f6bc blx r3
 *   @0x25f6c0 pop {r3, pc}
 *   @0x25f6c4 ldrsbeq r0, [r9], -r4
 *
 * ══ §198/350 json_object_get_object  0x27e8f4  size 28  7 条（0x27e8f4..0x27e910）
 * @func 0x27e8f4 0x27e910  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27e8f4 cmp r0, #0
 *   @0x27e8f8 bxeq lr
 *   @0x27e8fc ldr r3, [r0]
 *   @0x27e900 cmp r3, #4
 *   @0x27e904 ldreq r0, [r0, #0x18]
 *   @0x27e908 movne r0, #0
 *   @0x27e90c bx lr
 *
 * ══ §199/350 spAtlasRegion_create  0x2840d8  size 28  7 条（0x2840d8..0x2840f4）
 * @func 0x2840d8 0x284108  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2840d8 ldr r2, [pc, #0x10]
 *   @0x2840dc mov r0, #1
 *   @0x2840e0 mov r1, #80
 *   @0x2840e4 mov r3, #52
 *   @0x2840e8 add r2, pc, r2
 *   @0x2840ec b 0x285c4c <_calloc>
 *   @0x2840f0 andeq r3, sp, r12, lsl r4
 *
 * ══ §200/350 spBone_dispose  0x284efc  size 28  7 条（0x284efc..0x284f18）
 * @func 0x284efc 0x284f18  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _free
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x284efc push {r4, lr}
 *   @0x284f00 mov r4, r0
 *   @0x284f04 ldr r0, [r0, #0x10]
 *   @0x284f08 bl 0x285c80 <_free>
 *   @0x284f0c mov r0, r4
 *   @0x284f10 pop {r4, lr}
 *   @0x284f14 b 0x285c80 <_free>
 *
 * ══ §201/350 _free  0x285c80  size 28  7 条（0x285c80..0x285c9c）
 * @func 0x285c80 0x285c9c  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x285c80 push {r3, lr}
 *   @0x285c84 ldr r3, [pc, #0xc]
 *   @0x285c88 add r3, pc, r3
 *   @0x285c8c ldr r3, [r3, #0x4]
 *   @0x285c90 blx r3
 *   @0x285c94 pop {r3, pc}
 *   @0x285c98 andseq r1, r7, r0, lsl #22
 *
 * ══ §202/350 spIkConstraint_dispose  0x285e2c  size 28  7 条（0x285e2c..0x285e48）
 * @func 0x285e2c 0x285e48  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _free
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x285e2c push {r4, lr}
 *   @0x285e30 mov r4, r0
 *   @0x285e34 ldr r0, [r0, #0x8]
 *   @0x285e38 bl 0x285c80 <_free>
 *   @0x285e3c mov r0, r4
 *   @0x285e40 pop {r4, lr}
 *   @0x285e44 b 0x285c80 <_free>
 *
 * ══ §203/350 spPathAttachment_computeWorldVertices1  0x287740  size 28  7 条（0x287740..0x28775c）
 * @func 0x287740 0x28775c  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x-4×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x287740 str r4, [sp, #-0x4]!
 *   @0x287744 mov r4, r1
 *   @0x287748 mov r1, r2
 *   @0x28774c mov r2, r3
 *   @0x287750 mov r3, r4
 *   @0x287754 ldr r4, [sp], #4
 *   @0x287758 b 0x28f64c <spVertexAttachment_computeWorldVertices1>
 *
 * ══ §204/350 spPolygon_dispose  0x28a5b8  size 28  7 条（0x28a5b8..0x28a5d4）
 * @func 0x28a5b8 0x28a5d4  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _free
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28a5b8 push {r4, lr}
 *   @0x28a5bc mov r4, r0
 *   @0x28a5c0 ldr r0, [r0]
 *   @0x28a5c4 bl 0x285c80 <_free>
 *   @0x28a5c8 mov r0, r4
 *   @0x28a5cc pop {r4, lr}
 *   @0x28a5d0 b 0x285c80 <_free>
 *
 * ══ §205/350 spSlot_dispose  0x28ee00  size 28  7 条（0x28ee00..0x28ee1c）
 * @func 0x28ee00 0x28ee30  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _free
 * 字段偏移 top8: 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28ee00 push {r4, lr}
 *   @0x28ee04 mov r4, r0
 *   @0x28ee08 ldr r0, [r0, #0x24]
 *   @0x28ee0c bl 0x285c80 <_free>
 *   @0x28ee10 mov r0, r4
 *   @0x28ee14 pop {r4, lr}
 *   @0x28ee18 b 0x285c80 <_free>
 *
 * ══ §206/350 spTransformConstraint_dispose  0x28f0f4  size 28  7 条（0x28f0f4..0x28f110）
 * @func 0x28f0f4 0x28f110  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _free
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28f0f4 push {r4, lr}
 *   @0x28f0f8 mov r4, r0
 *   @0x28f0fc ldr r0, [r0, #0x8]
 *   @0x28f100 bl 0x285c80 <_free>
 *   @0x28f104 mov r0, r4
 *   @0x28f108 pop {r4, lr}
 *   @0x28f10c b 0x285c80 <_free>
 *
 * ══ §207/350 RelyAckNumPackets  0x299944  size 28  7 条（0x299944..0x299960）
 * @func 0x299944 0x29996c  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x408×1 / 0x409×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x299944 ldrb r3, [r0, #0x408]
 *   @0x299948 ldrb r2, [r0, #0x409]
 *   @0x29994c cmp r2, r3
 *   @0x299950 rsblo r3, r3, #255
 *   @0x299954 addlo r0, r3, r2
 *   @0x299958 rsbhs r0, r3, r2
 *   @0x29995c bx lr
 *
 * ══ §208/350 DirtyRoomExtents  0x168d7c  size 24  6 条（0x168d7c..0x168d94）
 * @func 0x168d7c 0x168d94  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x168d7c ldr r3, [pc, #0xc]
 *   @0x168d80 mov r2, #1
 *   @0x168d84 ldr r3, [pc, r3]
 *   @0x168d88 strb r2, [r3]
 *   @0x168d8c bx lr
 *   @0x168d90 eoreq r6, r8, r12, lsr #17
 *
 * ══ §209/350 CCamera::IsOrthoProj  0x16d380  size 24  6 条（0x16d380..0x16d398）
 * @func 0x16d380 0x16d3a0  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d380 vldr s15, [r0, #48]
 *   @0x16d384 vcmp.f32 s15, #0
 *   @0x16d388 vmrs APSR_nzcv, fpscr
 *   @0x16d38c movne r0, #0
 *   @0x16d390 moveq r0, #1
 *   @0x16d394 bx lr
 *
 * ══ §210/350 GR_Surface_Get_Texture  0x17155c  size 24  6 条（0x17155c..0x171574）
 * @func 0x17155c 0x171574  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Surface_Get(int)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17155c push {r3, lr}
 *   @0x171560 bl 0x170f48 <_Z14GR_Surface_Geti>
 *   @0x171564 cmp r0, #0
 *   @0x171568 ldrne r0, [r0, #0x4]
 *   @0x17156c mvneq r0, #0
 *   @0x171570 pop {r3, pc}
 *
 * ══ §211/350 GR_Window_Get_Color  0x17ae20  size 24  6 条（0x17ae20..0x17ae38）
 * @func 0x17ae20 0x17ae38  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17ae20 ldr r3, [pc, #0xc]
 *   @0x17ae24 ldr r3, [pc, r3]
 *   @0x17ae28 ldr r0, [r3]
 *   @0x17ae2c bic r0, r0, #-16777216
 *   @0x17ae30 bx lr
 *   @0x17ae34 .word 0x002754f8
 *
 * ══ §212/350 IO_Clear  0x18c2c8  size 24  6 条（0x18c2c8..0x18c2e0）
 * @func 0x18c2c8 0x18c2e0  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IO_String_Clear() / IO_Key_Clear_All()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18c2c8 push {r3, lr}
 *   @0x18c2cc bl 0x18be60 <_Z15IO_String_Clearv>
 *   @0x18c2d0 bl 0x18bf94 <_Z16IO_Key_Clear_Allv>
 *   @0x18c2d4 mov r0, #0
 *   @0x18c2d8 pop {r3, lr}
 *   @0x18c2dc b 0x18c20c <_Z19IO_Button_Clear_Alli>
 *
 * ══ §213/350 Room_First  0x1b5d08  size 24  6 条（0x1b5d08..0x1b5d20）
 * @func 0x1b5d08 0x1b5d20  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b5d08 ldr r3, [pc, #0xc]
 *   @0x1b5d0c add r3, pc, r3
 *   @0x1b5d10 ldr r3, [r3, #0x14]
 *   @0x1b5d14 ldr r0, [r3]
 *   @0x1b5d18 bx lr
 *   @0x1b5d1c ldrhteq r12, [r8], -r12
 *
 * ══ §214/350 Audio_GetDeviceName  0x21dac0  size 24  6 条（0x21dac0..0x21dad8）
 * @func 0x21dac0 0x21dad8  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6a3c / 0xb6b98
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21dac0 push {r3, lr}
 *   @0x21dac4 bl 0xb6a3c <alcGetCurrentContext@plt>
 *   @0x21dac8 bl 0xb6b98 <alcGetContextsDevice@plt>
 *   @0x21dacc movw r1, #0x1005
 *   @0x21dad0 pop {r3, lr}
 *   @0x21dad4 b 0xb6b50 <alcGetString@plt>
 *
 * ══ §215/350 oggpack_bytes  0x233e28  size 24  6 条（0x233e28..0x233e40）
 * @func 0x233e28 0x233e40  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x233e28 ldm r0, {r0, r3}
 *   @0x233e2c adds r1, r3, #7
 *   @0x233e30 addmi r3, r3, #14
 *   @0x233e34 movpl r3, r1
 *   @0x233e38 add r0, r0, r3, asr #3
 *   @0x233e3c bx lr
 *
 * ══ §216/350 operator new[]  0x27d14c  size 24  6 条（0x27d14c..0x27d164）
 * @func 0x27d14c 0x27d164  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27d14c ldr r1, [pc, #0xc]
 *   @0x27d150 movw r2, #0x52b
 *   @0x27d154 mov r3, #1
 *   @0x27d158 add r1, pc, r1
 *   @0x27d15c b 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x27d160 andeq r10, sp, r8, lsl #1
 *
 * ══ §217/350 Mutex::Lock  0x27e084  size 24  6 条（0x27e084..0x27e09c）
 * @func 0x27e084 0x27e0a4  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6cc4
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27e084 push {r3, lr}
 *   @0x27e088 add r0, r0, #4
 *   @0x27e08c bl 0xb6cc4 <pthread_mutex_lock@plt>
 *   @0x27e090 rsbs r0, r0, #1
 *   @0x27e094 movlo r0, #0
 *   @0x27e098 pop {r3, pc}
 *
 * ══ §218/350 b2ParticleSystem::GetCriticalVelocitySquared  0x2d856c  size 24  6 条（0x2d856c..0x2d8584）
 * @func 0x2d856c 0x2d8598  size 44  11 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ParticleSystem::GetCriticalVelocity(b2TimeStep const&) const
 * 字段偏移 top8: 无
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d856c push {r3, lr}
 *   @0x2d8570 bl 0x2d82e8 <_ZNK16b2ParticleSystem19GetCriticalVelocityERK10b2TimeStep>
 *   @0x2d8574 vmov s14, r0
 *   @0x2d8578 vmul.f32 s14, s14, s14
 *   @0x2d857c vmov r0, s14
 *   @0x2d8580 pop {r3, pc}
 *
 * ══ §219/350 b2DynamicTree::~b2DynamicTree  0x2de9a4  size 24  6 条（0x2de9a4..0x2de9bc）
 * @func 0x2de9a4 0x2de9bc  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Free(void*)
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2de9a4 push {r4, lr}
 *   @0x2de9a8 mov r4, r0
 *   @0x2de9ac ldr r0, [r0, #0x4]
 *   @0x2de9b0 bl 0x2c6a70 <_Z6b2FreePv>
 *   @0x2de9b4 mov r0, r4
 *   @0x2de9b8 pop {r4, pc}
 *
 * ══ §220/350 CBackground::GetTexture  0xc1e8c  size 20  5 条（0xc1e8c..0xc1ea0）
 * @func 0xc1e8c 0xc1ea0  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc1e8c ldr r3, [r0, #0x14]
 *   @0xc1e90 cmp r3, #0
 *   @0xc1e94 movne r0, r3
 *   @0xc1e98 ldreq r0, [r0, #0xc]
 *   @0xc1e9c bx lr
 *
 * ══ §221/350 Code_Error::Show  0xf1c94  size 20  5 条（0xf1c94..0xf1ca8）
 * @func 0xf1c94 0xf1ca8  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ShowMessage(char const*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf1c94 push {r3, lr}
 *   @0xf1c98 ldr r0, [r0]
 *   @0xf1c9c bl 0xc4b0c <_Z11ShowMessagePKc>
 *   @0xf1ca0 mov r0, #1
 *   @0xf1ca4 pop {r3, pc}
 *
 * ══ §222/350 CExtensionFunction::GetArgType  0xf4974  size 20  5 条（0xf4974..0xf4988）
 * @func 0xf4974 0xf4988  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4974 cmp r1, #15
 *   @0xf4978 addls r1, r1, #6
 *   @0xf497c ldrls r0, [r0, r1, lsl #2]
 *   @0xf4980 movhi r0, #2
 *   @0xf4984 bx lr
 *
 * ══ §223/350 Threaded_UpdateComsState  0x159a88  size 20  5 条（0x159a88..0x159a9c）
 * @func 0x159a88 0x159a9c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x159a88 ldr r3, [pc, #0x8]
 *   @0x159a8c ldr r3, [pc, r3]
 *   @0x159a90 str r0, [r3]
 *   @0x159a94 bx lr
 *   @0x159a98 eoreq r6, r9, r12, asr #2
 *
 * ══ §224/350 UpdateYoYoFunctions  0x15a0ac  size 20  5 条（0x15a0ac..0x15a0c0）
 * @func 0x15a0ac 0x15a0c0  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: UpdateYoYoFunctionsM() / UpdateAchievementCache()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15a0ac push {r3, lr}
 *   @0x15a0b0 bl 0x15e29c <_Z20UpdateYoYoFunctionsMv>
 *   @0x15a0b4 bl 0x1598c4 <_Z22UpdateAchievementCachev>
 *   @0x15a0b8 pop {r3, lr}
 *   @0x15a0bc b 0x159ddc <_Z14UpdateOSEventsv>
 *
 * ══ §225/350 GetVersionM  0x15e5f8  size 20  5 条（0x15e5f8..0x15e60c）
 * @func 0x15e5f8 0x15e620  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15e5f8 ldr r3, [pc, #0x8]
 *   @0x15e5fc ldr r3, [pc, r3]
 *   @0x15e600 ldrd r0, r1, [r3]
 *   @0x15e604 bx lr
 *   @0x15e608 mlaeq r9, r12, r8, r1
 *
 * ══ §226/350 GetLanguageString  0x15f21c  size 20  5 条（0x15f21c..0x15f230）
 * @func 0x15f21c 0x15f244  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15f21c ldr r3, [pc, #0x8]
 *   @0x15f220 ldr r3, [pc, r3]
 *   @0x15f224 ldr r0, [r3]
 *   @0x15f228 bx lr
 *   @0x15f22c .word 0x00290cb0
 *
 * ══ §227/350 GetRegionString  0x15f230  size 20  5 条（0x15f230..0x15f244）
 * @func 0x15f230 0x15f258  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15f230 ldr r3, [pc, #0x8]
 *   @0x15f234 ldr r3, [pc, r3]
 *   @0x15f238 ldr r0, [r3]
 *   @0x15f23c bx lr
 *   @0x15f240 eoreq r0, r9, r0, lsr #25
 *
 * ══ §228/350 GetDPIX  0x15f244  size 20  5 条（0x15f244..0x15f258）
 * @func 0x15f244 0x15f26c  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15f244 ldr r3, [pc, #0x8]
 *   @0x15f248 ldr r3, [pc, r3]
 *   @0x15f24c ldr r0, [r3]
 *   @0x15f250 bx lr
 *   @0x15f254 mlaeq r9, r0, r12, r0
 *
 * ══ §229/350 GetDPIY  0x15f258  size 20  5 条（0x15f258..0x15f26c）
 * @func 0x15f258 0x15f26c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15f258 ldr r3, [pc, #0x8]
 *   @0x15f25c ldr r3, [pc, r3]
 *   @0x15f260 ldr r0, [r3]
 *   @0x15f264 bx lr
 *   @0x15f268 eoreq r0, r9, r0, lsl #25
 *
 * ══ §230/350 RenderStateManager::GetRenderState  0x167f8c  size 20  5 条（0x167f8c..0x167fa0）
 * @func 0x167f8c 0x167fb4  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x167f8c cmp r1, #35
 *   @0x167f90 addls r1, r1, #120
 *   @0x167f94 ldrls r0, [r0, r1, lsl #2]
 *   @0x167f98 movhi r0, #0
 *   @0x167f9c bx lr
 *
 * ══ §231/350 GR_D3D_Set_Perspective  0x1682f0  size 20  5 条（0x1682f0..0x168304）
 * @func 0x1682f0 0x168304  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1682f0 ldr r3, [pc, #0x8]
 *   @0x1682f4 ldr r3, [pc, r3]
 *   @0x1682f8 strb r0, [r3]
 *   @0x1682fc bx lr
 *   @0x168300 eoreq r7, r8, r12, lsl #28
 *
 * ══ §232/350 GR_Surface_Exists  0x1714c0  size 20  5 条（0x1714c0..0x1714d4）
 * @func 0x1714c0 0x1714d4  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Surface_Get(int)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1714c0 push {r3, lr}
 *   @0x1714c4 bl 0x170f48 <_Z14GR_Surface_Geti>
 *   @0x1714c8 adds r0, r0, #0
 *   @0x1714cc movne r0, #1
 *   @0x1714d0 pop {r3, pc}
 *
 * ══ §233/350 GR_Window_Get_Region_Width  0x179988  size 20  5 条（0x179988..0x17999c）
 * @func 0x179988 0x1799b0  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x179988 ldr r3, [pc, #0x8]
 *   @0x17998c ldr r3, [pc, r3]
 *   @0x179990 ldr r0, [r3]
 *   @0x179994 bx lr
 *   @0x179998 eoreq r6, r7, r12, asr #18
 *
 * ══ §234/350 GR_Window_Get_Region_Height  0x17999c  size 20  5 条（0x17999c..0x1799b0）
 * @func 0x17999c 0x1799b0  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17999c ldr r3, [pc, #0x8]
 *   @0x1799a0 ldr r3, [pc, r3]
 *   @0x1799a4 ldr r0, [r3]
 *   @0x1799a8 bx lr
 *   @0x1799ac eoreq r6, r7, r12, lsr r9
 *
 * ══ §235/350 GR_Window_Set_Cursor  0x17af8c  size 20  5 条（0x17af8c..0x17afa0）
 * @func 0x17af8c 0x17afa0  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17af8c ldr r3, [pc, #0x8]
 *   @0x17af90 ldr r3, [pc, r3]
 *   @0x17af94 str r0, [r3]
 *   @0x17af98 bx lr
 *   @0x17af9c mlaeq r7, r4, r3, r5
 *
 * ══ §236/350 Graphics_DisplayWidth  0x17db24  size 20  5 条（0x17db24..0x17db38）
 * @func 0x17db24 0x17db4c  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17db24 ldr r3, [pc, #0x8]
 *   @0x17db28 ldr r3, [pc, r3]
 *   @0x17db2c ldr r0, [r3]
 *   @0x17db30 bx lr
 *   @0x17db34 eoreq r2, r7, r4, ror r3
 *
 * ══ §237/350 Graphics_DisplayHeight  0x17db38  size 20  5 条（0x17db38..0x17db4c）
 * @func 0x17db38 0x17db4c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17db38 ldr r3, [pc, #0x8]
 *   @0x17db3c ldr r3, [pc, r3]
 *   @0x17db40 ldr r0, [r3]
 *   @0x17db44 bx lr
 *   @0x17db48 eoreq r2, r7, r4, ror #6
 *
 * ══ §238/350 GMGamePad::ButtonCount  0x18ead0  size 20  5 条（0x18ead0..0x18eae4）
 * @func 0x18ead0 0x18eae4  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18ead0 ldrb r3, [r0]
 *   @0x18ead4 cmp r3, #0
 *   @0x18ead8 ldrne r0, [r0, #0x4]
 *   @0x18eadc moveq r0, r3
 *   @0x18eae0 bx lr
 *
 * ══ §239/350 GMGamePad::AxisCount  0x18ed88  size 20  5 条（0x18ed88..0x18ed9c）
 * @func 0x18ed88 0x18ed9c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18ed88 ldrb r3, [r0]
 *   @0x18ed8c cmp r3, #0
 *   @0x18ed90 ldrne r0, [r0, #0x8]
 *   @0x18ed94 moveq r0, r3
 *   @0x18ed98 bx lr
 *
 * ══ §240/350 Room_Exists  0x1b52f8  size 20  5 条（0x1b52f8..0x1b530c）
 * @func 0x1b52f8 0x1b5320  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Room_Data(int)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b52f8 push {r3, lr}
 *   @0x1b52fc bl 0x1b52c4 <_Z9Room_Datai>
 *   @0x1b5300 adds r0, r0, #0
 *   @0x1b5304 movne r0, #1
 *   @0x1b5308 pop {r3, pc}
 *
 * ══ §241/350 Script_Number  0x1e0530  size 20  5 条（0x1e0530..0x1e0544）
 * @func 0x1e0530 0x1e0544  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e0530 ldr r3, [pc, #0x8]
 *   @0x1e0534 ldr r3, [pc, r3]
 *   @0x1e0538 ldr r0, [r3]
 *   @0x1e053c bx lr
 *   @0x1e0540 .word 0x002107f8
 *
 * ══ §242/350 bool CHashMapCompareKeys<char const*>  0x1eeba8  size 20  5 条（0x1eeba8..0x1eebbc）
 * @func 0x1eeba8 0x1eebbc  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6574
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1eeba8 push {r3, lr}
 *   @0x1eebac bl 0xb6574 <strcmp@plt>
 *   @0x1eebb0 rsbs r0, r0, #1
 *   @0x1eebb4 movlo r0, #0
 *   @0x1eebb8 pop {r3, pc}
 *
 * ══ §243/350 Sound_Number  0x21fb6c  size 20  5 条（0x21fb6c..0x21fb80）
 * @func 0x21fb6c 0x21fb80  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21fb6c ldr r3, [pc, #0x8]
 *   @0x21fb70 add r3, pc, r3
 *   @0x21fb74 ldr r0, [r3, #0x10]
 *   @0x21fb78 bx lr
 *   @0x21fb7c subseq r5, r3, r8, asr #15
 *
 * ══ §244/350 JS_IsCallable_Object  0x240758  size 20  5 条（0x240758..0x24076c）
 * @func 0x240758 0x24076c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x240758 ldr r0, [r0, #0x48]
 *   @0x24075c subs r3, r0, #3
 *   @0x240760 rsbs r0, r3, #0
 *   @0x240764 adcs r0, r0, r3
 *   @0x240768 bx lr
 *
 * ══ §245/350 Mutex::Mutex  0x27e070  size 20  5 条（0x27e070..0x27e084）
 * @func 0x27e070 0x27e098  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Mutex::Init(char const*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27e070 push {r4, lr}
 *   @0x27e074 mov r4, r0
 *   @0x27e078 bl 0x27e038 <_ZN5Mutex4InitEPKc>
 *   @0x27e07c mov r0, r4
 *   @0x27e080 pop {r4, pc}
 *
 * ══ §246/350 json_object_get  0x27e7b4  size 20  5 条（0x27e7b4..0x27e7c8）
 * @func 0x27e7b4 0x27e7dc  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27e7b4 cmp r0, #0
 *   @0x27e7b8 ldrne r3, [r0, #0xc]
 *   @0x27e7bc addne r3, r3, #1
 *   @0x27e7c0 strne r3, [r0, #0xc]
 *   @0x27e7c4 bx lr
 *
 * ══ §247/350 printbuf_reset  0x280e9c  size 20  5 条（0x280e9c..0x280eb0）
 * @func 0x280e9c 0x280ec4  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x280e9c ldr r2, [r0]
 *   @0x280ea0 mov r3, #0
 *   @0x280ea4 strb r3, [r2]
 *   @0x280ea8 str r3, [r0, #0x4]
 *   @0x280eac bx lr
 *
 * ══ §248/350 spAttachment_dispose  0x284cb4  size 20  5 条（0x284cb4..0x284cc8）
 * @func 0x284cb4 0x284cc8  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x284cb4 push {r3, lr}
 *   @0x284cb8 ldr r3, [r0, #0x8]
 *   @0x284cbc ldr r3, [r3]
 *   @0x284cc0 blx r3
 *   @0x284cc4 pop {r3, pc}
 *
 * ══ §249/350 spBone_setYDown  0x284ed8  size 20  5 条（0x284ed8..0x284eec）
 * @func 0x284ed8 0x284eec  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x284ed8 ldr r3, [pc, #0x8]
 *   @0x284edc add r3, pc, r3
 *   @0x284ee0 str r0, [r3]
 *   @0x284ee4 bx lr
 *   @0x284ee8 ldrdeq r1, r2, [sp], #-204
 *
 * ══ §250/350 getJNIEnv  0x290274  size 20  5 条（0x290274..0x290288）
 * @func 0x290274 0x290288  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x290274 ldr r3, [pc, #0x8]
 *   @0x290278 ldr r3, [pc, r3]
 *   @0x29027c ldr r0, [r3]
 *   @0x290280 b 0xb6d30 <pthread_getspecific@plt>
 *   @0x290284 andseq r1, r6, r12, lsr #13
 *
 * ══ §251/350 DebuggerIsConnected  0x29cb74  size 20  5 条（0x29cb74..0x29cb88）
 * @func 0x29cb74 0x29cb88  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1 / 0x210×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29cb74 ldr r3, [pc, #0x8]
 *   @0x29cb78 add r3, pc, r3
 *   @0x29cb7c ldrb r0, [r3, #0x210]
 *   @0x29cb80 bx lr
 *   @0x29cb84 umaaleq r11, r11, r0, r0
 *
 * ══ §252/350 b2ParticleSystem::GetCriticalVelocity  0x2d82e8  size 20  5 条（0x2d82e8..0x2d82fc）
 * @func 0x2d82e8 0x2d82fc  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d82e8 vldr s14, [r0, #24]
 *   @0x2d82ec vldr s15, [r1, #4]
 *   @0x2d82f0 vmul.f32 s15, s14, s15
 *   @0x2d82f4 vmov r0, s15
 *   @0x2d82f8 bx lr
 *
 * ══ §253/350 b2ParticleSystem::GetParticleStride  0x2d85a8  size 20  5 条（0x2d85a8..0x2d85bc）
 * @func 0x2d85a8 0x2d85d0  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d85a8 vmov.f32 s15, #7.500000e-01
 *   @0x2d85ac vldr s14, [r0, #24]
 *   @0x2d85b0 vmul.f32 s15, s14, s15
 *   @0x2d85b4 vmov r0, s15
 *   @0x2d85b8 bx lr
 *
 * ══ §254/350 b2Timer::b2Timer  0x2e10b8  size 20  5 条（0x2e10b8..0x2e10cc）
 * @func 0x2e10b8 0x2e10cc  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Timer::Reset()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e10b8 push {r4, lr}
 *   @0x2e10bc mov r4, r0
 *   @0x2e10c0 bl 0x2e1090 <_ZN7b2Timer5ResetEv>
 *   @0x2e10c4 mov r0, r4
 *   @0x2e10c8 pop {r4, pc}
 *
 * ══ §255/350 __aeabi_dcmplt  0x31b080  size 20  5 条（0x31b080..0x31b094）
 * @func 0x31b080 0x31b094  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __aeabi_cdcmple
 * 字段偏移 top8: 0x-8×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31b080 str lr, [sp, #-0x8]!
 *   @0x31b084 bl 0x31b058 <__aeabi_cdcmple>
 *   @0x31b088 movlo r0, #1
 *   @0x31b08c movhs r0, #0
 *   @0x31b090 ldr pc, [sp], #8
 *
 * ══ §256/350 __aeabi_fcmplt  0x31b1d0  size 20  5 条（0x31b1d0..0x31b1e4）
 * @func 0x31b1d0 0x31b1e4  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __aeabi_cfcmple
 * 字段偏移 top8: 0x-8×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31b1d0 str lr, [sp, #-0x8]!
 *   @0x31b1d4 bl 0x31b1a8 <__aeabi_cfcmple>
 *   @0x31b1d8 movlo r0, #1
 *   @0x31b1dc movhs r0, #0
 *   @0x31b1e0 ldr pc, [sp], #8
 *
 * ══ §257/350 CSkeletonInstance::SetAnimationMix  0xbe580  size 16  4 条（0xbe580..0xbe590）
 * @func 0xbe580 0xbe590  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbe580 ldr r0, [r0, #0x2c]
 *   @0xbe584 cmp r0, #0
 *   @0xbe588 bxeq lr
 *   @0xbe58c b 0x283c60 <spAnimationStateData_setMixByName>
 *
 * ══ §258/350 YoYo_GetPlatform_DoWork  0x159cf4  size 16  4 条（0x159cf4..0x159d04）
 * @func 0x159cf4 0x159d04  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x159cf4 mov r0, #0
 *   @0x159cf8 mov r1, #0
 *   @0x159cfc movt r1, #0x4010
 *   @0x159d00 bx lr
 *
 * ══ §259/350 Achievement_PlayerID  0x161210  size 16  4 条（0x161210..0x161220）
 * @func 0x161210 0x161220  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161210 ldr r0, [pc, #0x4]
 *   @0x161214 add r0, pc, r0
 *   @0x161218 bx lr
 *   @0x16121c andseq r8, lr, r8, asr #17
 *
 * ══ §260/350 bool CHashMapCompareKeys<YYObjectBase*>  0x190f48  size 16  4 条（0x190f48..0x190f58）
 * @func 0x190f48 0x190f58  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x190f48 subs r3, r1, r0
 *   @0x190f4c rsbs r0, r3, #0
 *   @0x190f50 adcs r0, r0, r3
 *   @0x190f54 bx lr
 *
 * ══ §261/350 Room_Number  0x1b523c  size 16  4 条（0x1b523c..0x1b524c）
 * @func 0x1b523c 0x1b524c  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b523c ldr r3, [pc, #0x4]
 *   @0x1b5240 ldr r0, [pc, r3]
 *   @0x1b5244 bx lr
 *   @0x1b5248 eorseq sp, r8, r8, lsl #7
 *
 * ══ §262/350 CSound::Prepare  0x21568c  size 16  4 条（0x21568c..0x21569c）
 * @func 0x21568c 0x21569c  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21568c ldrb r3, [r0, #0x14]
 *   @0x215690 cmp r3, #0
 *   @0x215694 bxeq lr
 *   @0x215698 b 0x215540 <_ZN6CSound7RestoreEv>
 *
 * ══ §263/350 ogg_page_continued  0x233f80  size 16  4 条（0x233f80..0x233f90）
 * @func 0x233f80 0x233fa4  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x5×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x233f80 ldr r3, [r0]
 *   @0x233f84 ldrb r0, [r3, #0x5]
 *   @0x233f88 and r0, r0, #1
 *   @0x233f8c bx lr
 *
 * ══ §264/350 ogg_page_bos  0x233f90  size 16  4 条（0x233f90..0x233fa0）
 * @func 0x233f90 0x233fb0  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x5×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x233f90 ldr r3, [r0]
 *   @0x233f94 ldrb r0, [r3, #0x5]
 *   @0x233f98 and r0, r0, #2
 *   @0x233f9c bx lr
 *
 * ══ §265/350 ogg_page_eos  0x233fa0  size 16  4 条（0x233fa0..0x233fb0）
 * @func 0x233fa0 0x233fb0  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x5×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x233fa0 ldr r3, [r0]
 *   @0x233fa4 ldrb r0, [r3, #0x5]
 *   @0x233fa8 and r0, r0, #4
 *   @0x233fac bx lr
 *
 * ══ §266/350 GetFilePrePend  0x28fd5c  size 16  4 条（0x28fd5c..0x28fd6c）
 * @func 0x28fd5c 0x28fd6c  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28fd5c ldr r0, [pc, #0x4]
 *   @0x28fd60 add r0, pc, r0
 *   @0x28fd64 bx lr
 *   @0x28fd68 andeq r2, r12, r8, lsl sp
 *
 * ══ §267/350 yySocket::Read  0x2952dc  size 16  4 条（0x2952dc..0x2952ec）
 * @func 0x2952dc 0x2952ec  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2952dc ldr r12, [r0, #0xc]
 *   @0x2952e0 ldr r0, [r0]
 *   @0x2952e4 orr r3, r3, r12
 *   @0x2952e8 b 0xb6df0 <recv@plt>
 *
 * ══ §268/350 yySocket::Write  0x295464  size 16  4 条（0x295464..0x295474）
 * @func 0x295464 0x295488  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x295464 mov r3, r0
 *   @0x295468 ldr r0, [r0]
 *   @0x29546c ldr r3, [r3, #0xc]
 *   @0x295470 b 0xb6e20 <send@plt>
 *
 * ══ §269/350 b2World::SetContactListener  0x2c901c  size 16  4 条（0x2c901c..0x2c902c）
 * @func 0x2c901c 0x2c902c  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c901c movw r3, #0x9220
 *   @0x2c9020 movt r3, #0x1
 *   @0x2c9024 str r1, [r0, r3]
 *   @0x2c9028 bx lr
 *
 * ══ §270/350 unsigned int CHashMapCalculateHash<YYObjectBase*>  0x190f34  size 12  3 条（0x190f34..0x190f40）
 * @func 0x190f34 0x190f40  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x190f34 asr r0, r0, #8
 *   @0x190f38 add r0, r0, #1
 *   @0x190f3c bx lr
 *
 * ══ §271/350 CGCGeneration::ResetDynamicRoots  0x191400  size 12  3 条（0x191400..0x19140c）
 * @func 0x191400 0x19140c  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x191400 mov r3, #0
 *   @0x191404 str r3, [r0, #0x8]
 *   @0x191408 bx lr
 *
 * ══ §272/350 YYObjectBase::IsExtensible  0x19220c  size 12  3 条（0x19220c..0x192218）
 * @func 0x19220c 0x192218  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19220c ldr r0, [r0, #0x28]
 *   @0x192210 and r0, r0, #1
 *   @0x192214 bx lr
 *
 * ══ §273/350 SoundHardware::SoundHardware  0x220188  size 12  3 条（0x220188..0x220194）
 * @func 0x220188 0x220194  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x220188 mov r3, #1065353216
 *   @0x22018c str r3, [r0]
 *   @0x220190 bx lr
 *
 * ══ §274/350 vorbis_comment_init  0x22aa80  size 12  3 条（0x22aa80..0x22aa8c）
 * @func 0x22aa80 0x22aa8c  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22aa80 mov r1, #0
 *   @0x22aa84 mov r2, #16
 *   @0x22aa88 b 0xb65b0 <memset@plt>
 *
 * ══ §275/350 ogg_page_version  0x233f74  size 12  3 条（0x233f74..0x233f80）
 * @func 0x233f74 0x233f94  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x233f74 ldr r3, [r0]
 *   @0x233f78 ldrb r0, [r3, #0x4]
 *   @0x233f7c bx lr
 *
 * ══ §276/350 ogg_sync_check  0x234b80  size 12  3 条（0x234b80..0x234b8c）
 * @func 0x234b80 0x234b8c  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x234b80 ldr r0, [r0, #0x4]
 *   @0x234b84 asr r0, r0, #31
 *   @0x234b88 bx lr
 *
 * ══ §277/350 CPhysicsWorld::DestroyBody  0x238c08  size 12  3 条（0x238c08..0x238c14）
 * @func 0x238c08 0x238c14  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x238c08 ldr r0, [r0, #0x10]
 *   @0x238c0c ldr r1, [r1]
 *   @0x238c10 b 0x2c93e4 <_ZN7b2World11DestroyBodyEP6b2Body>
 *
 * ══ §278/350 CCodepointIterator_UTF8::Reset  0x2423fc  size 12  3 条（0x2423fc..0x242408）
 * @func 0x2423fc 0x242408  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2423fc ldr r3, [r0]
 *   @0x242400 str r3, [r0, #0x4]
 *   @0x242404 bx lr
 *
 * ══ §279/350 RelyAckClearPackets  0x299960  size 12  3 条（0x299960..0x29996c）
 * @func 0x299960 0x29996c  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x409×1 / 0x408×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x299960 ldrb r3, [r0, #0x409]
 *   @0x299964 strb r3, [r0, #0x408]
 *   @0x299968 bx lr
 *
 * ══ §280/350 CSkeletonInstance::SelectAnimation  0xbe578  size 8  2 条（0xbe578..0xbe580）
 * @func 0xbe578 0xbe590  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbe578 mov r2, #0
 *   @0xbe57c b 0xbe4ec <_ZN17CSkeletonInstance18SelectAnimationExtEPKci>
 *
 * ══ §281/350 CBackground::GetWidth  0xc2d78  size 8  2 条（0xc2d78..0xc2d80）
 * @func 0xc2d78 0xc2d88  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc2d78 ldr r0, [r0]
 *   @0xc2d7c bx lr
 *
 * ══ §282/350 CBackground::GetHeight  0xc2d80  size 8  2 条（0xc2d80..0xc2d88）
 * @func 0xc2d80 0xc2d88  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc2d80 ldr r0, [r0, #0x4]
 *   @0xc2d84 bx lr
 *
 * ══ §283/350 unsigned int CHashMapCalculateHash<unsigned char*>  0xec748  size 8  2 条（0xec748..0xec750）
 * @func 0xec748 0xec750  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xec748 add r0, r0, #1
 *   @0xec74c bx lr
 *
 * ══ §284/350 CEvent::Compile  0xf2e10  size 8  2 条（0xf2e10..0xf2e18）
 * @func 0xf2e10 0xf2e18  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2e10 mov r0, #1
 *   @0xf2e14 bx lr
 *
 * ══ §285/350 CExtensionConstant::GetName  0xf490c  size 8  2 条（0xf490c..0xf4914）
 * @func 0xf490c 0xf4914  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf490c ldr r0, [r0, #0x4]
 *   @0xf4910 bx lr
 *
 * ══ §286/350 CExtensionConstant::GetValue  0xf4940  size 8  2 条（0xf4940..0xf4948）
 * @func 0xf4940 0xf4948  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4940 ldr r0, [r0, #0x8]
 *   @0xf4944 bx lr
 *
 * ══ §287/350 CExtensionFunction::GetExternalName  0xf4be4  size 8  2 条（0xf4be4..0xf4bec）
 * @func 0xf4be4 0xf4bec  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4be4 ldr r0, [r0, #0x8]
 *   @0xf4be8 bx lr
 *
 * ══ §288/350 CExtensionFunction::GetKind  0xf4c18  size 8  2 条（0xf4c18..0xf4c20）
 * @func 0xf4c18 0xf4c20  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4c18 ldr r0, [r0, #0xc]
 *   @0xf4c1c bx lr
 *
 * ══ §289/350 CExtensionFunction::GetId  0xf4c28  size 8  2 条（0xf4c28..0xf4c30）
 * @func 0xf4c28 0xf4c30  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4c28 ldr r0, [r0, #0x10]
 *   @0xf4c2c bx lr
 *
 * ══ §290/350 CExtensionFunction::GetArgCount  0xf4c38  size 8  2 条（0xf4c38..0xf4c40）
 * @func 0xf4c38 0xf4c40  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4c38 ldr r0, [r0, #0x14]
 *   @0xf4c3c bx lr
 *
 * ══ §291/350 CExtensionFunction::GetReturnType  0xf4c48  size 8  2 条（0xf4c48..0xf4c50）
 * @func 0xf4c48 0xf4c50  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x58×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4c48 ldr r0, [r0, #0x58]
 *   @0xf4c4c bx lr
 *
 * ══ §292/350 CExtensionFile::GetFileName  0xf4fac  size 8  2 条（0xf4fac..0xf4fb4）
 * @func 0xf4fac 0xf4fb4  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4fac ldr r0, [r0, #0x4]
 *   @0xf4fb0 bx lr
 *
 * ══ §293/350 CExtensionFile::GetFunction_Init  0xf4ff0  size 8  2 条（0xf4ff0..0xf4ff8）
 * @func 0xf4ff0 0xf4ff8  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4ff0 ldr r0, [r0, #0xc]
 *   @0xf4ff4 bx lr
 *
 * ══ §294/350 CExtensionFile::GetFunctionsCount  0xf5044  size 8  2 条（0xf5044..0xf504c）
 * @func 0xf5044 0xf504c  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf5044 ldr r0, [r0, #0x1c]
 *   @0xf5048 bx lr
 *
 * ══ §295/350 CExtensionFile::GetConstantsCount  0xf5058  size 8  2 条（0xf5058..0xf5060）
 * @func 0xf5058 0xf5060  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf5058 ldr r0, [r0, #0x28]
 *   @0xf505c bx lr
 *
 * ══ §296/350 CExtensionPackage::GetClassName  0xf55c8  size 8  2 条（0xf55c8..0xf55d0）
 * @func 0xf55c8 0xf55d0  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf55c8 ldr r0, [r0, #0xc]
 *   @0xf55cc bx lr
 *
 * ══ §297/350 CExtensionPackage::GetFolder  0xf55fc  size 8  2 条（0xf55fc..0xf5604）
 * @func 0xf55fc 0xf5604  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf55fc ldr r0, [r0, #0x8]
 *   @0xf5600 bx lr
 *
 * ══ §298/350 CExtensionPackage::GetIncludesCount  0xf5630  size 8  2 条（0xf5630..0xf5638）
 * @func 0xf5630 0xf5638  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf5630 ldr r0, [r0, #0x18]
 *   @0xf5634 bx lr
 *
 * ══ §299/350 CCamera::SetID  0x16d124  size 8  2 条（0x16d124..0x16d12c）
 * @func 0x16d124 0x16d140  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d124 str r1, [r0]
 *   @0x16d128 bx lr
 *
 * ══ §300/350 CCamera::GetID  0x16d12c  size 8  2 条（0x16d12c..0x16d134）
 * @func 0x16d12c 0x16d148  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d12c ldr r0, [r0]
 *   @0x16d130 bx lr
 *
 * ══ §301/350 CCamera::SetViewX  0x16d29c  size 8  2 条（0x16d29c..0x16d2a4）
 * @func 0x16d29c 0x16d2b8  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x184×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d29c str r1, [r0, #0x184]
 *   @0x16d2a0 bx lr
 *
 * ══ §302/350 CCamera::GetViewX  0x16d2a4  size 8  2 条（0x16d2a4..0x16d2ac）
 * @func 0x16d2a4 0x16d2c0  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x184×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d2a4 ldr r0, [r0, #0x184]
 *   @0x16d2a8 bx lr
 *
 * ══ §303/350 CCamera::SetViewY  0x16d2ac  size 8  2 条（0x16d2ac..0x16d2b4）
 * @func 0x16d2ac 0x16d2c8  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x188×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d2ac str r1, [r0, #0x188]
 *   @0x16d2b0 bx lr
 *
 * ══ §304/350 CCamera::GetViewY  0x16d2b4  size 8  2 条（0x16d2b4..0x16d2bc）
 * @func 0x16d2b4 0x16d2d0  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x188×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d2b4 ldr r0, [r0, #0x188]
 *   @0x16d2b8 bx lr
 *
 * ══ §305/350 CCamera::SetViewWidth  0x16d2bc  size 8  2 条（0x16d2bc..0x16d2c4）
 * @func 0x16d2bc 0x16d2d8  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d2bc str r1, [r0, #0x18c]
 *   @0x16d2c0 bx lr
 *
 * ══ §306/350 CCamera::GetViewWidth  0x16d2c4  size 8  2 条（0x16d2c4..0x16d2cc）
 * @func 0x16d2c4 0x16d2e0  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d2c4 ldr r0, [r0, #0x18c]
 *   @0x16d2c8 bx lr
 *
 * ══ §307/350 CCamera::SetViewHeight  0x16d2cc  size 8  2 条（0x16d2cc..0x16d2d4）
 * @func 0x16d2cc 0x16d2e8  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x190×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d2cc str r1, [r0, #0x190]
 *   @0x16d2d0 bx lr
 *
 * ══ §308/350 CCamera::GetViewHeight  0x16d2d4  size 8  2 条（0x16d2d4..0x16d2dc）
 * @func 0x16d2d4 0x16d2f0  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x190×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d2d4 ldr r0, [r0, #0x190]
 *   @0x16d2d8 bx lr
 *
 * ══ §309/350 CCamera::SetViewSpeedX  0x16d2dc  size 8  2 条（0x16d2dc..0x16d2e4）
 * @func 0x16d2dc 0x16d2f8  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x194×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d2dc str r1, [r0, #0x194]
 *   @0x16d2e0 bx lr
 *
 * ══ §310/350 CCamera::GetViewSpeedX  0x16d2e4  size 8  2 条（0x16d2e4..0x16d2ec）
 * @func 0x16d2e4 0x16d300  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x194×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d2e4 ldr r0, [r0, #0x194]
 *   @0x16d2e8 bx lr
 *
 * ══ §311/350 CCamera::SetViewSpeedY  0x16d2ec  size 8  2 条（0x16d2ec..0x16d2f4）
 * @func 0x16d2ec 0x16d308  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x198×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d2ec str r1, [r0, #0x198]
 *   @0x16d2f0 bx lr
 *
 * ══ §312/350 CCamera::GetViewSpeedY  0x16d2f4  size 8  2 条（0x16d2f4..0x16d2fc）
 * @func 0x16d2f4 0x16d310  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x198×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d2f4 ldr r0, [r0, #0x198]
 *   @0x16d2f8 bx lr
 *
 * ══ §313/350 CCamera::SetViewBorderX  0x16d2fc  size 8  2 条（0x16d2fc..0x16d304）
 * @func 0x16d2fc 0x16d318  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x19c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d2fc str r1, [r0, #0x19c]
 *   @0x16d300 bx lr
 *
 * ══ §314/350 CCamera::GetViewBorderX  0x16d304  size 8  2 条（0x16d304..0x16d30c）
 * @func 0x16d304 0x16d320  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x19c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d304 ldr r0, [r0, #0x19c]
 *   @0x16d308 bx lr
 *
 * ══ §315/350 CCamera::SetViewBorderY  0x16d30c  size 8  2 条（0x16d30c..0x16d314）
 * @func 0x16d30c 0x16d328  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1a0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d30c str r1, [r0, #0x1a0]
 *   @0x16d310 bx lr
 *
 * ══ §316/350 CCamera::GetViewBorderY  0x16d314  size 8  2 条（0x16d314..0x16d31c）
 * @func 0x16d314 0x16d330  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1a0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d314 ldr r0, [r0, #0x1a0]
 *   @0x16d318 bx lr
 *
 * ══ §317/350 CCamera::SetViewAngle  0x16d31c  size 8  2 条（0x16d31c..0x16d324）
 * @func 0x16d31c 0x16d338  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1a4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d31c str r1, [r0, #0x1a4]
 *   @0x16d320 bx lr
 *
 * ══ §318/350 CCamera::GetViewAngle  0x16d324  size 8  2 条（0x16d324..0x16d32c）
 * @func 0x16d324 0x16d340  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1a4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d324 ldr r0, [r0, #0x1a4]
 *   @0x16d328 bx lr
 *
 * ══ §319/350 CCamera::SetTargetInstance  0x16d32c  size 8  2 条（0x16d32c..0x16d334）
 * @func 0x16d32c 0x16d348  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1a8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d32c str r1, [r0, #0x1a8]
 *   @0x16d330 bx lr
 *
 * ══ §320/350 CCamera::GetTargetInstance  0x16d334  size 8  2 条（0x16d334..0x16d33c）
 * @func 0x16d334 0x16d350  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1a8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d334 ldr r0, [r0, #0x1a8]
 *   @0x16d338 bx lr
 *
 * ══ §321/350 CCamera::SetBeginScript  0x16d33c  size 8  2 条（0x16d33c..0x16d344）
 * @func 0x16d33c 0x16d358  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1ac×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d33c str r1, [r0, #0x1ac]
 *   @0x16d340 bx lr
 *
 * ══ §322/350 CCamera::GetBeginScript  0x16d344  size 8  2 条（0x16d344..0x16d34c）
 * @func 0x16d344 0x16d360  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1ac×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d344 ldr r0, [r0, #0x1ac]
 *   @0x16d348 bx lr
 *
 * ══ §323/350 CCamera::SetEndScript  0x16d34c  size 8  2 条（0x16d34c..0x16d354）
 * @func 0x16d34c 0x16d368  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1b0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d34c str r1, [r0, #0x1b0]
 *   @0x16d350 bx lr
 *
 * ══ §324/350 CCamera::GetEndScript  0x16d354  size 8  2 条（0x16d354..0x16d35c）
 * @func 0x16d354 0x16d36c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1b0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d354 ldr r0, [r0, #0x1b0]
 *   @0x16d358 bx lr
 *
 * ══ §325/350 CCamera::SetUpdateScript  0x16d35c  size 8  2 条（0x16d35c..0x16d364）
 * @func 0x16d35c 0x16d36c  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1b4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d35c str r1, [r0, #0x1b4]
 *   @0x16d360 bx lr
 *
 * ══ §326/350 CCamera::GetUpdateScript  0x16d364  size 8  2 条（0x16d364..0x16d36c）
 * @func 0x16d364 0x16d36c  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1b4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d364 ldr r0, [r0, #0x1b4]
 *   @0x16d368 bx lr
 *
 * ══ §327/350 CCamera::IsViewDirty  0x16d378  size 8  2 条（0x16d378..0x16d380）
 * @func 0x16d378 0x16d394  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1b9×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d378 ldrb r0, [r0, #0x1b9]
 *   @0x16d37c bx lr
 *
 * ══ §328/350 CCamera::Is2D  0x16d398  size 8  2 条（0x16d398..0x16d3a0）
 * @func 0x16d398 0x16d3a0  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1b8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d398 ldrb r0, [r0, #0x1b8]
 *   @0x16d39c bx lr
 *
 * ══ §329/350 CCameraManager::GetActiveCamera  0x16ec3c  size 8  2 条（0x16ec3c..0x16ec44）
 * @func 0x16ec3c 0x16ec44  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16ec3c ldr r0, [r0, #0x4]
 *   @0x16ec40 bx lr
 *
 * ══ §330/350 CCamera::Begin  0x170b20  size 8  2 条（0x170b20..0x170b28）
 * @func 0x170b20 0x170b30  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1ac×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x170b20 ldr r1, [r0, #0x1ac]
 *   @0x170b24 b 0x170888 <_ZN7CCamera13ExecuteScriptEi>
 *
 * ══ §331/350 CCamera::End  0x170b28  size 8  2 条（0x170b28..0x170b30）
 * @func 0x170b28 0x170b30  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1b0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x170b28 ldr r1, [r0, #0x1b0]
 *   @0x170b2c b 0x170888 <_ZN7CCamera13ExecuteScriptEi>
 *
 * ══ §332/350 Graphics::GetMaxDynamicVertexCount  0x18561c  size 8  2 条（0x18561c..0x185624）
 * @func 0x18561c 0x185624  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18561c mov r0, #16384
 *   @0x185620 bx lr
 *
 * ══ §333/350 CPath::GetPathLength  0x1a7ab8  size 8  2 条（0x1a7ab8..0x1a7ac0）
 * @func 0x1a7ab8 0x1a7ac0  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a7ab8 ldr r0, [r0, #0x24]
 *   @0x1a7abc bx lr
 *
 * ══ §334/350 DrawLayerParticleElement  0x1b2834  size 8  2 条（0x1b2834..0x1b283c）
 * @func 0x1b2834 0x1b283c  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b2834 ldr r0, [r2, #0x1c]
 *   @0x1b2838 b 0x1a5d98 <_Z23ParticleSystem_AutoDrawi>
 *
 * ══ §335/350 Room_Prepare  0x1b4cd0  size 8  2 条（0x1b4cd0..0x1b4cd8）
 * @func 0x1b4cd0 0x1b4cd8  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b4cd0 mov r0, #1
 *   @0x1b4cd4 bx lr
 *
 * ══ §336/350 CHashMapCalculateHash  0x1b6e44  size 8  2 条（0x1b6e44..0x1b6e4c）
 * @func 0x1b6e44 0x1b6e4c  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b6e44 add r0, r0, #1
 *   @0x1b6e48 bx lr
 *
 * ══ §337/350 CScript::GetCode  0x1dfba8  size 8  2 条（0x1dfba8..0x1dfbb0）
 * @func 0x1dfba8 0x1dfbb0  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dfba8 ldr r0, [r0, #0x8]
 *   @0x1dfbac bx lr
 *
 * ══ §338/350 CTimeLine::GetCount  0x1f1760  size 8  2 条（0x1f1760..0x1f1768）
 * @func 0x1f1760 0x1f1768  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f1760 ldr r0, [r0, #0x8]
 *   @0x1f1764 bx lr
 *
 * ══ §339/350 DLL_Define  0x2148fc  size 8  2 条（0x2148fc..0x214904）
 * @func 0x2148fc 0x214904  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2148fc mvn r0, #0
 *   @0x214900 bx lr
 *
 * ══ §340/350 vorbis_synthesis  0x22fc6c  size 8  2 条（0x22fc6c..0x22fc74）
 * @func 0x22fc6c 0x22fc74  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22fc6c mov r2, #1
 *   @0x22fc70 b 0x22fa78 <vorbis_book_init_decode+0x474>
 *
 * ══ §341/350 MemoryManager::GetStackTrace  0x27d258  size 8  2 条（0x27d258..0x27d260）
 * @func 0x27d258 0x27d260  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27d258 mov r0, #0
 *   @0x27d25c bx lr
 *
 * ══ §342/350 CalcCRC  0x27dfa0  size 8  2 条（0x27dfa0..0x27dfa8）
 * @func 0x27dfa0 0x27dfa8  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27dfa0 mvn r2, #0
 *   @0x27dfa4 b 0x27df34 <_Z7CalcCRCPKcij>
 *
 * ══ §343/350 Mutex::Unlock  0x27e09c  size 8  2 条（0x27e09c..0x27e0a4）
 * @func 0x27e09c 0x27e0a4  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27e09c add r0, r0, #4
 *   @0x27e0a0 b 0xb6cd0 <pthread_mutex_unlock@plt>
 *
 * ══ §344/350 json_object_get_type  0x27e828  size 8  2 条（0x27e828..0x27e830）
 * @func 0x27e828 0x27e830  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27e828 ldr r0, [r0]
 *   @0x27e82c bx lr
 *
 * ══ §345/350 json_object_array_length  0x27ede8  size 8  2 条（0x27ede8..0x27edf0）
 * @func 0x27ede8 0x27edf8  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27ede8 ldr r0, [r0, #0x18]
 *   @0x27edec b 0x27e2e0 <array_list_length>
 *
 * ══ §346/350 json_object_array_add  0x27edf0  size 8  2 条（0x27edf0..0x27edf8）
 * @func 0x27edf0 0x27edf8  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27edf0 ldr r0, [r0, #0x18]
 *   @0x27edf4 b 0x27e2d4 <array_list_add>
 *
 * ══ §347/350 json_object_array_get_idx  0x27ee00  size 8  2 条（0x27ee00..0x27ee08）
 * @func 0x27ee00 0x27ee08  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27ee00 ldr r0, [r0, #0x18]
 *   @0x27ee04 b 0x27e200 <array_list_get_idx>
 *
 * ══ §348/350 yySocket::DetectIPv6  0x297000  size 8  2 条（0x297000..0x297008）
 * @func 0x297000 0x297008  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x297000 mov r0, #0
 *   @0x297004 bx lr
 *
 * ══ §349/350 DbgServer::Process  0x29d62c  size 8  2 条（0x29d62c..0x29d634）
 * @func 0x29d62c 0x29d634  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29d62c ldr r0, [r0]
 *   @0x29d630 b 0x297f98 <_ZN8yyServer7ProcessEv>
 *
 * ══ §350/350 b2ContactManager::FindNewContacts  0x2c84d8  size 8  2 条（0x2c84d8..0x2c84e0）
 * @func 0x2c84d8 0x2c84f4  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c84d8 mov r1, r0
 *   @0x2c84dc b 0x2c8300 <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_>
 */
