/* cally 逆向卡：Reach_07 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 54 个函数｜锚点 7482 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/54 GR_Texture_Draw_Simple  0x174868  size 624  156 条（0x174868..0x174ad8）
 * @func 0x174868 0x174ad8  size 624  156 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Texture_Exists(int) / Graphics::AllocVerts(ePrimType, void*, int, int) / GR_Draw_Get_Alpha() / GR_Texture_Draw_Simple(YYTPageEntry*, float, float)+0x244
 * 字段偏移 top8: 0xc×2 / 0x224×1 / 0x4×1 / 0x2×1 / 0x1d4×1 / 0xe×1 / 0x14c×1 / 0x84×1
 * VFP 指令 64 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x174868 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x17486c vpush {d8}
 *   @0x174870 subs r5, r0, #0
 *   @0x174874 vmov s17, r1
 *   @0x174878 vmov s16, r2
 *   @0x17487c beq 0x174890 <_Z22GR_Texture_Draw_SimpleP12YYTPageEntryff+0x28>
 *   @0x174880 ldrsh r0, [r5, #20]
 *   @0x174884 bl 0x173e2c <_Z17GR_Texture_Existsi>
 *   @0x174888 subs r6, r0, #0
 *   @0x17488c bne 0x1748a0 <_Z22GR_Texture_Draw_SimpleP12YYTPageEntryff+0x38>
 *   @0x174890 vpop {d8}
 *   @0x174894 mov r6, #0
 *   @0x174898 mov r0, r6
 *   @0x17489c pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1748a0 ldr r1, [pc, #0x224]
 *   @0x1748a4 mov r3, #6
 *   @0x1748a8 ldrsh r12, [r5, #20]
 *   @0x1748ac mov r2, #24
 *   @0x1748b0 ldr r1, [pc, r1]
 *   @0x1748b4 mov r0, #4
 *   @0x1748b8 ldr r1, [r1, #0x4]
 *   @0x1748bc ldr r7, [r1, r12, lsl #2]
 *   @0x1748c0 ldr r1, [r7]
 *   @0x1748c4 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x1748c8 mov r4, r0
 *   @0x1748cc bl 0x169f1c <_Z17GR_Draw_Get_Alphav>
 *   @0x1748d0 vldr s15, [pc, #496]
 *   @0x1748d4 vmov s14, r0
 *   @0x1748d8 vmul.f32 s15, s14, s15
 *   @0x1748dc vcvt.s32.f32 s15, s15
 *   @0x1748e0 vmov r3, s15
 *   @0x1748e4 cmp r3, #255
 *   @0x1748e8 mvngt r1, #0
 *   @0x1748ec movgt r0, #-16777216
 *   @0x1748f0 ble 0x174aac <_Z22GR_Texture_Draw_SimpleP12YYTPageEntryff+0x244>
 *   @0x1748f4 ldr r3, [pc, #0x1d4]
 *   @0x1748f8 ldr r3, [pc, r3]
 *   @0x1748fc ldrb r2, [r3]
 *   @0x174900 cmp r2, #0
 *   @0x174904 bne 0x174a84 <_Z22GR_Texture_Draw_SimpleP12YYTPageEntryff+0x21c>
 *   @0x174908 mov r2, r1
 *   @0x17490c mov r12, r1
 *   @0x174910 mov r3, r1
 *   @0x174914 ldrsh r8, [r5, #10]
 *   @0x174918 vldr s9, [r7, #8]
 *   @0x17491c ldrsh r9, [r5, #8]
 *   @0x174920 rsb r8, r8, #0
 *   @0x174924 ldrh r0, [r5, #12]
 *   @0x174928 rsb r9, r9, #0
 *   @0x17492c vmov s14, r8
 *   @0x174930 ldrsh r8, [r5]
 *   @0x174934 vmov s15, r9
 *   @0x174938 cmp r0, #0
 *   @0x17493c vcvt.f32.s32 s8, s14
 *   @0x174940 sxthne r0, r0
 *   @0x174944 vmov s14, r8
 *   @0x174948 moveq r0, #1
 *   @0x17494c vmovne s11, r0
 *   @0x174950 strheq r0, [r5, #12]
 *   @0x174954 ldrh r0, [r5, #14]
 *   @0x174958 vcvt.f32.s32 s7, s15
 *   @0x17495c vcvt.f32.s32 s15, s14
 *   @0x174960 vmul.f32 s15, s15, s9
 *   @0x174964 vcvtne.f32.s32 s11, s11
 *   @0x174968 vmoveq.f32 s11, #1.000000e+00
 *   @0x17496c cmp r0, #0
 *   @0x174970 sxthne r0, r0
 *   @0x174974 moveq r0, #1
 *   @0x174978 strheq r0, [r5, #14]
 *   @0x17497c vmovne s12, r0
 *   @0x174980 ldr r0, [pc, #0x14c]
 *   @0x174984 str r3, [r4, #0xc]
 *   @0x174988 vstr s15, [r4, #112]
 *   @0x17498c ldr r0, [pc, r0]
 *   @0x174990 str r3, [r4, #0x84]
 *   @0x174994 vstr s15, [r4, #16]
 *   @0x174998 vstr s15, [r4, #136]
 *   @0x17499c ldr r3, [r0]
 *   @0x1749a0 vldr s10, [r7, #12]
 *   @0x1749a4 str r2, [r4, #0x3c]
 *   @0x1749a8 mov r0, r6
 *   @0x1749ac str r2, [r4, #0x54]
 *   @0x1749b0 vmoveq.f32 s12, #1.000000e+00
 *   @0x1749b4 str r3, [r4, #0x68]
 *   @0x1749b8 str r3, [r4, #0x38]
 *   @0x1749bc str r3, [r4, #0x50]
 *   @0x1749c0 str r3, [r4, #0x20]
 *   @0x1749c4 str r3, [r4, #0x8]
 *   @0x1749c8 str r3, [r4, #0x80]
 *   @0x1749cc ldrsh r3, [r5, #2]
 *   @0x1749d0 str r12, [r4, #0x24]
 *   @0x1749d4 str r1, [r4, #0x6c]
 *   @0x1749d8 vmov s15, r3
 *   @0x1749dc vcvtne.f32.s32 s12, s12
 *   @0x1749e0 vsub.f32 s11, s11, s7
 *   @0x1749e4 vsub.f32 s12, s12, s8
 *   @0x1749e8 vcvt.f32.s32 s13, s15
 *   @0x1749ec vmul.f32 s13, s13, s10
 *   @0x1749f0 vadd.f32 s11, s17, s11
 *   @0x1749f4 vadd.f32 s12, s16, s12
 *   @0x1749f8 vstr s11, [r4, #48]
 *   @0x1749fc vstr s11, [r4, #72]
 *   @0x174a00 vstr s11, [r4, #24]
 *   @0x174a04 vsub.f32 s17, s17, s7
 *   @0x174a08 vstr s12, [r4, #100]
 *   @0x174a0c vstr s12, [r4, #52]
 *   @0x174a10 vstr s12, [r4, #76]
 *   @0x174a14 vstr s17, [r4]
 *   @0x174a18 vstr s13, [r4, #44]
 *   @0x174a1c vstr s13, [r4, #20]
 *   @0x174a20 vstr s13, [r4, #140]
 *   @0x174a24 ldrsh r2, [r5, #4]
 *   @0x174a28 vsub.f32 s16, s16, s8
 *   @0x174a2c vstr s17, [r4, #120]
 *   @0x174a30 vstr s17, [r4, #96]
 *   @0x174a34 add r2, r8, r2
 *   @0x174a38 vmov s14, r2
 *   @0x174a3c vcvt.f32.s32 s14, s14
 *   @0x174a40 vstr s16, [r4, #28]
 *   @0x174a44 vstr s16, [r4, #4]
 *   @0x174a48 vstr s16, [r4, #124]
 *   @0x174a4c vmul.f32 s14, s9, s14
 *   @0x174a50 vstr s14, [r4, #64]
 *   @0x174a54 vstr s14, [r4, #88]
 *   @0x174a58 vstr s14, [r4, #40]
 *   @0x174a5c ldrsh r2, [r5, #6]
 *   @0x174a60 add r2, r3, r2
 *   @0x174a64 vmov s15, r2
 *   @0x174a68 vcvt.f32.s32 s15, s15
 *   @0x174a6c vmul.f32 s15, s10, s15
 *   @0x174a70 vstr s15, [r4, #116]
 *   @0x174a74 vstr s15, [r4, #68]
 *   @0x174a78 vstr s15, [r4, #92]
 *   @0x174a7c vpop {d8}
 *   @0x174a80 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x174a84 movw r3, #0xfffe
 *   @0x174a88 movw r12, #0xffff
 *   @0x174a8c movt r3, #0xfe
 *   @0x174a90 movt r12, #0xfe
 *   @0x174a94 movw r2, #0xfffe
 *   @0x174a98 movt r2, #0xff
 *   @0x174a9c orr r3, r0, r3
 *   @0x174aa0 orr r12, r0, r12
 *   @0x174aa4 orr r2, r0, r2
 *   @0x174aa8 b 0x174914 <_Z22GR_Texture_Draw_SimpleP12YYTPageEntryff+0xac>
 *   @0x174aac cmp r3, #0
 *   @0x174ab0 lslge r0, r3, #24
 *   @0x174ab4 mvnlt r1, #-16777216
 *   @0x174ab8 movlt r0, #0
 *   @0x174abc mvnge r1, r0, lsr #24
 *   @0x174ac0 mvnge r1, r1, lsl #24
 *   @0x174ac4 b 0x1748f4 <_Z22GR_Texture_Draw_SimpleP12YYTPageEntryff+0x8c>
 *   @0x174ac8 cmnmi pc, #0
 *   @0x174acc eoreq r9, r7, r12, rrx
 *   @0x174ad0 eoreq r9, r7, r4, asr r5
 *   @0x174ad4 mlaeq r7, r4, pc, r8
 *
 * ══ §2/54 YYObjectBase::Add  0x199b84  size 624  156 条（0x199b84..0x199df4）
 * @func 0x199b84 0x199df4  size 624  156 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / YYObjectBase::IsExtensible() / YYObjectBase::FindOrAllocValue(char const*) / PushContextStack(YYObjectBase*) / PopContextStack()
 * 字段偏移 top8: 0x8×9 / 0x4×8 / 0xc×5
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x199b84 push {r4, r5, r6, r7, r8, lr}
 *   @0x199b88 mov r4, r1
 *   @0x199b8c mov r5, r2
 *   @0x199b90 mov r7, r3
 *   @0x199b94 mov r6, r0
 *   @0x199b98 bl 0x19220c <_ZN12YYObjectBase12IsExtensibleEv>
 *   @0x199b9c cmp r0, #0
 *   @0x199ba0 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x199ba4 mov r1, r4
 *   @0x199ba8 mov r0, r6
 *   @0x199bac bl 0x196bc4 <_ZN12YYObjectBase16FindOrAllocValueEPKc>
 *   @0x199bb0 mov r4, r0
 *   @0x199bb4 mov r0, r6
 *   @0x199bb8 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase>
 *   @0x199bbc ldr r2, [r4, #0xc]
 *   @0x199bc0 bic r3, r2, #-16777216
 *   @0x199bc4 cmp r3, #1
 *   @0x199bc8 beq 0x199c80 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xfc>
 *   @0x199bcc cmp r3, #2
 *   @0x199bd0 bne 0x199bf8 <_ZN12YYObjectBase3AddEPKcR6RValuei+0x74>
 *   @0x199bd4 sub r2, r2, #1
 *   @0x199bd8 bic r2, r2, #-16777216
 *   @0x199bdc bic r2, r2, #3
 *   @0x199be0 cmp r2, #0
 *   @0x199be4 beq 0x199d54 <_ZN12YYObjectBase3AddEPKcR6RValuei+0x1d0>
 *   @0x199be8 mov r2, #0
 *   @0x199bec mov r3, #5
 *   @0x199bf0 str r2, [r4, #0x8]
 *   @0x199bf4 str r3, [r4, #0xc]
 *   @0x199bf8 ldr r3, [r5, #0xc]
 *   @0x199bfc mov r1, #0
 *   @0x199c00 ldr r2, [r5, #0x8]
 *   @0x199c04 str r1, [r4]
 *   @0x199c08 str r3, [r4, #0xc]
 *   @0x199c0c ldr r3, [r5, #0xc]
 *   @0x199c10 str r2, [r4, #0x8]
 *   @0x199c14 bic r3, r3, #-16777216
 *   @0x199c18 cmp r3, #14
 *   @0x199c1c addls pc, pc, r3, lsl #2
 *   @0x199c20 b 0x199c68 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xe4>
 *   @0x199c24 b 0x199c74 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xf0>
 *   @0x199c28 b 0x199cd8 <_ZN12YYObjectBase3AddEPKcR6RValuei+0x154>
 *   @0x199c2c b 0x199cf0 <_ZN12YYObjectBase3AddEPKcR6RValuei+0x16c>
 *   @0x199c30 b 0x199c60 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xdc>
 *   @0x199c34 b 0x199c68 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xe4>
 *   @0x199c38 b 0x199c68 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xe4>
 *   @0x199c3c b 0x199cb4 <_ZN12YYObjectBase3AddEPKcR6RValuei+0x130>
 *   @0x199c40 b 0x199c60 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xdc>
 *   @0x199c44 b 0x199c68 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xe4>
 *   @0x199c48 b 0x199c68 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xe4>
 *   @0x199c4c b 0x199c74 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xf0>
 *   @0x199c50 b 0x199c68 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xe4>
 *   @0x199c54 b 0x199c68 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xe4>
 *   @0x199c58 b 0x199c74 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xf0>
 *   @0x199c5c b 0x199c60 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xdc>
 *   @0x199c60 ldr r3, [r5]
 *   @0x199c64 str r3, [r4]
 *   @0x199c68 bl 0xd3a34 <_Z15PopContextStackv>
 *   @0x199c6c str r7, [r4, #0x8]
 *   @0x199c70 pop {r4, r5, r6, r7, r8, pc}
 *   @0x199c74 ldm r5, {r2, r3}
 *   @0x199c78 stm r4, {r2, r3}
 *   @0x199c7c b 0x199c68 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xe4>
 *   @0x199c80 ldr r6, [r4]
 *   @0x199c84 cmp r6, #0
 *   @0x199c88 beq 0x199ca8 <_ZN12YYObjectBase3AddEPKcR6RValuei+0x124>
 *   @0x199c8c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x199c90 ldr r8, [r6, #0x4]
 *   @0x199c94 sub r8, r8, #1
 *   @0x199c98 str r8, [r6, #0x4]
 *   @0x199c9c cmp r8, #0
 *   @0x199ca0 beq 0x199d1c <_ZN12YYObjectBase3AddEPKcR6RValuei+0x198>
 *   @0x199ca4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x199ca8 mov r3, #0
 *   @0x199cac str r3, [r4]
 *   @0x199cb0 b 0x199bf8 <_ZN12YYObjectBase3AddEPKcR6RValuei+0x74>
 *   @0x199cb4 ldr r3, [r5]
 *   @0x199cb8 str r3, [r4]
 *   @0x199cbc ldr r3, [r5]
 *   @0x199cc0 cmp r3, #0
 *   @0x199cc4 beq 0x199c68 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xe4>
 *   @0x199cc8 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x199ccc ldr r1, [r5]
 *   @0x199cd0 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x199cd4 b 0x199c68 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xe4>
 *   @0x199cd8 ldr r3, [r5]
 *   @0x199cdc cmp r3, #0
 *   @0x199ce0 ldrne r2, [r3, #0x4]
 *   @0x199ce4 addne r2, r2, #1
 *   @0x199ce8 strne r2, [r3, #0x4]
 *   @0x199cec b 0x199c64 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xe0>
 *   @0x199cf0 ldr r3, [r5]
 *   @0x199cf4 cmp r3, #0
 *   @0x199cf8 str r3, [r4]
 *   @0x199cfc beq 0x199c68 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xe4>
 *   @0x199d00 ldr r1, [r3, #0x8]
 *   @0x199d04 ldr r2, [r3]
 *   @0x199d08 cmp r1, #0
 *   @0x199d0c streq r4, [r3, #0x8]
 *   @0x199d10 add r2, r2, #1
 *   @0x199d14 str r2, [r3]
 *   @0x199d18 b 0x199c68 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xe4>
 *   @0x199d1c ldr r0, [r6]
 *   @0x199d20 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x199d24 str r8, [r6]
 *   @0x199d28 str r8, [r6, #0x8]
 *   @0x199d2c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x199d30 ldr r8, [r6, #0x4]
 *   @0x199d34 sub r8, r8, #1
 *   @0x199d38 str r8, [r6, #0x4]
 *   @0x199d3c cmp r8, #0
 *   @0x199d40 beq 0x199d60 <_ZN12YYObjectBase3AddEPKcR6RValuei+0x1dc>
 *   @0x199d44 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x199d48 mov r0, r6
 *   @0x199d4c bl 0x27d1d0 <_ZdlPv>
 *   @0x199d50 b 0x199ca4 <_ZN12YYObjectBase3AddEPKcR6RValuei+0x120>
 *   @0x199d54 mov r0, r4
 *   @0x199d58 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x199d5c b 0x199be8 <_ZN12YYObjectBase3AddEPKcR6RValuei+0x64>
 *   @0x199d60 ldr r0, [r6]
 *   @0x199d64 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x199d68 str r8, [r6]
 *   @0x199d6c str r8, [r6, #0x8]
 *   @0x199d70 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x199d74 ldr r8, [r6, #0x4]
 *   @0x199d78 sub r8, r8, #1
 *   @0x199d7c str r8, [r6, #0x4]
 *   @0x199d80 cmp r8, #0
 *   @0x199d84 beq 0x199d98 <_ZN12YYObjectBase3AddEPKcR6RValuei+0x214>
 *   @0x199d88 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x199d8c mov r0, r6
 *   @0x199d90 bl 0x27d1d0 <_ZdlPv>
 *   @0x199d94 b 0x199d44 <_ZN12YYObjectBase3AddEPKcR6RValuei+0x1c0>
 *   @0x199d98 ldr r0, [r6]
 *   @0x199d9c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x199da0 str r8, [r6]
 *   @0x199da4 str r8, [r6, #0x8]
 *   @0x199da8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x199dac ldr r8, [r6, #0x4]
 *   @0x199db0 sub r8, r8, #1
 *   @0x199db4 str r8, [r6, #0x4]
 *   @0x199db8 cmp r8, #0
 *   @0x199dbc beq 0x199dd0 <_ZN12YYObjectBase3AddEPKcR6RValuei+0x24c>
 *   @0x199dc0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x199dc4 mov r0, r6
 *   @0x199dc8 bl 0x27d1d0 <_ZdlPv>
 *   @0x199dcc b 0x199d88 <_ZN12YYObjectBase3AddEPKcR6RValuei+0x204>
 *   @0x199dd0 ldr r0, [r6]
 *   @0x199dd4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x199dd8 mov r0, r6
 *   @0x199ddc str r8, [r6]
 *   @0x199de0 str r8, [r6, #0x8]
 *   @0x199de4 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x199de8 mov r0, r6
 *   @0x199dec bl 0x27d1d0 <_ZdlPv>
 *   @0x199df0 b 0x199dc0 <_ZN12YYObjectBase3AddEPKcR6RValuei+0x23c>
 *
 * ══ §3/54 b2ParticleSystem::SolveTensile  0x2d82fc  size 624  156 条（0x2d82fc..0x2d856c）
 * @func 0x2d82fc 0x2d856c  size 624  156 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ParticleSystem::GetCriticalVelocity(b2TimeStep const&) const×2 / b2ParticleSystem::SolveTensile(b2TimeStep const&)+0x60 / b2ParticleSystem::SolveTensile(b2TimeStep const&)+0x11c / b2ParticleSystem::SolveTensile(b2TimeStep const&)+0x23c / b2BlockAllocator::Allocate(int) / 0xb65b0
 * 字段偏移 top8: 0x4c×3 / 0x48×3 / 0x74×2 / 0x7c×2 / 0x8×2 / 0x-8×2 / 0x-4×2 / 0x28×2
 * VFP 指令 67 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d82fc push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2d8300 vpush {d8}
 *   @0x2d8304 mov r4, r0
 *   @0x2d8308 ldr r5, [r0, #0x4c]
 *   @0x2d830c mov r6, r1
 *   @0x2d8310 cmp r5, #0
 *   @0x2d8314 beq 0x2d8540 <_ZN16b2ParticleSystem12SolveTensileERK10b2TimeStep+0x244>
 *   @0x2d8318 ldr r7, [r4, #0x24]
 *   @0x2d831c str r5, [r4, #0x4c]
 *   @0x2d8320 cmp r7, #0
 *   @0x2d8324 ble 0x2d835c <_ZN16b2ParticleSystem12SolveTensileERK10b2TimeStep+0x60>
 *   @0x2d8328 ldr r3, [r4, #0x48]
 *   @0x2d832c mov r2, #0
 *   @0x2d8330 ldr lr, [pc, #0x230]
 *   @0x2d8334 mov r8, #0
 *   @0x2d8338 add r7, r3, r7, lsl #2
 *   @0x2d833c ldr lr, [pc, lr]
 *   @0x2d8340 ldm lr, {r0, r1}
 *   @0x2d8344 add r12, r5, r2
 *   @0x2d8348 str r8, [r3], #4
 *   @0x2d834c cmp r3, r7
 *   @0x2d8350 add r2, r2, #8
 *   @0x2d8354 stm r12, {r0, r1}
 *   @0x2d8358 bne 0x2d8340 <_ZN16b2ParticleSystem12SolveTensileERK10b2TimeStep+0x44>
 *   @0x2d835c ldr r7, [r4, #0x74]
 *   @0x2d8360 cmp r7, #0
 *   @0x2d8364 ble 0x2d8418 <_ZN16b2ParticleSystem12SolveTensileERK10b2TimeStep+0x11c>
 *   @0x2d8368 vmov.f32 s10, #1.000000e+00
 *   @0x2d836c ldr r3, [r4, #0x7c]
 *   @0x2d8370 add r7, r7, r7, lsl #1
 *   @0x2d8374 add r2, r3, #8
 *   @0x2d8378 add r7, r3, r7, lsl #3
 *   @0x2d837c ldr r1, [r3, #0x8]
 *   @0x2d8380 tst r1, #128
 *   @0x2d8384 beq 0x2d8408 <_ZN16b2ParticleSystem12SolveTensileERK10b2TimeStep+0x10c>
 *   @0x2d8388 vldr s15, [r2, #4]
 *   @0x2d838c vsub.f32 s14, s10, s15
 *   @0x2d8390 ldr lr, [r2, #-0x8]
 *   @0x2d8394 vldr s13, [r3, #16]
 *   @0x2d8398 ldr r1, [r4, #0x48]
 *   @0x2d839c vldr s11, [r3, #20]
 *   @0x2d83a0 ldr r12, [r2, #-0x4]
 *   @0x2d83a4 add r0, r1, lr, lsl #2
 *   @0x2d83a8 vldr s12, [r0]
 *   @0x2d83ac add lr, r5, lr, lsl #3
 *   @0x2d83b0 add r1, r1, r12, lsl #2
 *   @0x2d83b4 add r12, r5, r12, lsl #3
 *   @0x2d83b8 vmul.f32 s14, s14, s15
 *   @0x2d83bc vadd.f32 s12, s12, s15
 *   @0x2d83c0 vmul.f32 s13, s14, s13
 *   @0x2d83c4 vstr s12, [r0]
 *   @0x2d83c8 vldr s12, [r1]
 *   @0x2d83cc vmul.f32 s14, s14, s11
 *   @0x2d83d0 vadd.f32 s15, s12, s15
 *   @0x2d83d4 vstr s15, [r1]
 *   @0x2d83d8 vldr s15, [lr]
 *   @0x2d83dc vldr s12, [lr, #4]
 *   @0x2d83e0 vsub.f32 s15, s15, s13
 *   @0x2d83e4 vsub.f32 s12, s12, s14
 *   @0x2d83e8 vstr s15, [lr]
 *   @0x2d83ec vldr s15, [r12]
 *   @0x2d83f0 vstr s12, [lr, #4]
 *   @0x2d83f4 vadd.f32 s13, s15, s13
 *   @0x2d83f8 vldr s15, [r12, #4]
 *   @0x2d83fc vadd.f32 s14, s15, s14
 *   @0x2d8400 vstr s13, [r12]
 *   @0x2d8404 vstr s14, [r12, #4]
 *   @0x2d8408 add r3, r3, #24
 *   @0x2d840c add r2, r2, #24
 *   @0x2d8410 cmp r3, r7
 *   @0x2d8414 bne 0x2d837c <_ZN16b2ParticleSystem12SolveTensileERK10b2TimeStep+0x80>
 *   @0x2d8418 mov r1, r6
 *   @0x2d841c mov r0, r4
 *   @0x2d8420 vldr s16, [r4, #192]
 *   @0x2d8424 bl 0x2d82e8 <_ZNK16b2ParticleSystem19GetCriticalVelocityERK10b2TimeStep>
 *   @0x2d8428 mov r1, r6
 *   @0x2d842c vldr s17, [r4, #196]
 *   @0x2d8430 vmov s15, r0
 *   @0x2d8434 mov r0, r4
 *   @0x2d8438 vmul.f32 s16, s16, s15
 *   @0x2d843c bl 0x2d82e8 <_ZNK16b2ParticleSystem19GetCriticalVelocityERK10b2TimeStep>
 *   @0x2d8440 ldr r7, [r4, #0x74]
 *   @0x2d8444 cmp r7, #0
 *   @0x2d8448 vmov s15, r0
 *   @0x2d844c vmul.f32 s5, s17, s15
 *   @0x2d8450 ble 0x2d8538 <_ZN16b2ParticleSystem12SolveTensileERK10b2TimeStep+0x23c>
 *   @0x2d8454 ldr r3, [r4, #0x7c]
 *   @0x2d8458 add r7, r7, r7, lsl #1
 *   @0x2d845c add r2, r3, #8
 *   @0x2d8460 add r7, r3, r7, lsl #3
 *   @0x2d8464 vmov.f32 s4, #2.000000e+00
 *   @0x2d8468 ldr r1, [r3, #0x8]
 *   @0x2d846c tst r1, #128
 *   @0x2d8470 beq 0x2d8528 <_ZN16b2ParticleSystem12SolveTensileERK10b2TimeStep+0x22c>
 *   @0x2d8474 ldr r6, [r2, #-0x8]
 *   @0x2d8478 vldr s13, [r3, #20]
 *   @0x2d847c ldr r5, [r2, #-0x4]
 *   @0x2d8480 vldr s14, [r3, #16]
 *   @0x2d8484 ldr r9, [r4, #0x4c]
 *   @0x2d8488 vldr s10, [r2, #4]
 *   @0x2d848c lsl r0, r6, #3
 *   @0x2d8490 ldr r12, [r4, #0x48]
 *   @0x2d8494 lsl r1, r5, #3
 *   @0x2d8498 add r8, r9, r0
 *   @0x2d849c add r9, r9, r1
 *   @0x2d84a0 vldr s15, [r8, #4]
 *   @0x2d84a4 vldr s12, [r9, #4]
 *   @0x2d84a8 vsub.f32 s15, s12, s15
 *   @0x2d84ac vldr s6, [r9]
 *   @0x2d84b0 vldr s7, [r8]
 *   @0x2d84b4 add r6, r12, r6, lsl #2
 *   @0x2d84b8 add r12, r12, r5, lsl #2
 *   @0x2d84bc vldr s8, [r6]
 *   @0x2d84c0 vldr s9, [r12]
 *   @0x2d84c4 ldr r12, [r4, #0x40]
 *   @0x2d84c8 add r0, r12, r0
 *   @0x2d84cc vldr s11, [r0]
 *   @0x2d84d0 vldr s12, [r0, #4]
 *   @0x2d84d4 add r1, r12, r1
 *   @0x2d84d8 vmul.f32 s15, s15, s13
 *   @0x2d84dc vsub.f32 s7, s6, s7
 *   @0x2d84e0 vmla.f32 s15, s7, s14
 *   @0x2d84e4 vadd.f32 s9, s8, s9
 *   @0x2d84e8 vmul.f32 s15, s5, s15
 *   @0x2d84ec vsub.f32 s9, s9, s4
 *   @0x2d84f0 vmla.f32 s15, s9, s16
 *   @0x2d84f4 vmul.f32 s15, s15, s10
 *   @0x2d84f8 vmul.f32 s14, s15, s14
 *   @0x2d84fc vmul.f32 s15, s15, s13
 *   @0x2d8500 vsub.f32 s13, s11, s14
 *   @0x2d8504 vsub.f32 s12, s12, s15
 *   @0x2d8508 vstr s13, [r0]
 *   @0x2d850c vldr s13, [r1]
 *   @0x2d8510 vstr s12, [r0, #4]
 *   @0x2d8514 vadd.f32 s14, s13, s14
 *   @0x2d8518 vldr s13, [r1, #4]
 *   @0x2d851c vadd.f32 s15, s13, s15
 *   @0x2d8520 vstr s14, [r1]
 *   @0x2d8524 vstr s15, [r1, #4]
 *   @0x2d8528 add r3, r3, #24
 *   @0x2d852c add r2, r2, #24
 *   @0x2d8530 cmp r3, r7
 *   @0x2d8534 bne 0x2d8468 <_ZN16b2ParticleSystem12SolveTensileERK10b2TimeStep+0x16c>
 *   @0x2d8538 vpop {d8}
 *   @0x2d853c pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2d8540 ldr r1, [r0, #0x28]
 *   @0x2d8544 ldr r0, [r0, #0xd4]
 *   @0x2d8548 lsl r1, r1, #3
 *   @0x2d854c bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2d8550 ldr r2, [r4, #0x28]
 *   @0x2d8554 mov r1, #0
 *   @0x2d8558 lsl r2, r2, #3
 *   @0x2d855c mov r5, r0
 *   @0x2d8560 bl 0xb65b0 <memset@plt>
 *   @0x2d8564 b 0x2d8318 <_ZN16b2ParticleSystem12SolveTensileERK10b2TimeStep+0x1c>
 *   @0x2d8568 mulseq r1, r12, r1
 *
 * ══ §4/54 Find_Event  0xf2e80  size 620  155 条（0xf2e80..0xf30ec）
 * @func 0xf2e80 0xf30ec  size 620  155 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Object_Exists(int)×4 / CObjectGM::GetEventDirect(int, int)×2 / Find_Event(int, int, int, int&)+0xec / Find_Event(int, int, int, int&)+0xf4 / Find_Event(int, int, int, int&)+0x230
 * 字段偏移 top8: 0xc×12 / 0x4×9 / 0x8×8 / 0x3×6 / 0x258×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2e80 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0xf2e84 mov r7, r3
 *   @0xf2e88 ldr r6, [pc, #0x258]
 *   @0xf2e8c mov r8, r2
 *   @0xf2e90 str r0, [r7]
 *   @0xf2e94 mov r5, r0
 *   @0xf2e98 ldr r6, [pc, r6]
 *   @0xf2e9c mov r9, r1
 *   @0xf2ea0 ldr r3, [r6]
 *   @0xf2ea4 ldr r2, [r3, #0x4]
 *   @0xf2ea8 ldr r3, [r3]
 *   @0xf2eac and r2, r0, r2
 *   @0xf2eb0 ldr r3, [r3, r2, lsl #3]
 *   @0xf2eb4 cmp r3, #0
 *   @0xf2eb8 bne 0xf2ecc <_Z10Find_EventiiiRi+0x4c>
 *   @0xf2ebc b 0xf2f6c <_Z10Find_EventiiiRi+0xec>
 *   @0xf2ec0 ldr r3, [r3, #0x4]
 *   @0xf2ec4 cmp r3, #0
 *   @0xf2ec8 beq 0xf2f6c <_Z10Find_EventiiiRi+0xec>
 *   @0xf2ecc ldr r2, [r3, #0x8]
 *   @0xf2ed0 cmp r5, r2
 *   @0xf2ed4 bne 0xf2ec0 <_Z10Find_EventiiiRi+0x40>
 *   @0xf2ed8 ldr r4, [r3, #0xc]
 *   @0xf2edc cmp r4, #0
 *   @0xf2ee0 beq 0xf2f6c <_Z10Find_EventiiiRi+0xec>
 *   @0xf2ee4 mov r0, r4
 *   @0xf2ee8 mov r1, r9
 *   @0xf2eec mov r2, r8
 *   @0xf2ef0 bl 0x19da74 <_ZN9CObjectGM14GetEventDirectEii>
 *   @0xf2ef4 cmp r0, #0
 *   @0xf2ef8 popne {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xf2efc ldr r0, [r4, #0xc]
 *   @0xf2f00 cmp r0, #0
 *   @0xf2f04 blt 0xf2f6c <_Z10Find_EventiiiRi+0xec>
 *   @0xf2f08 bl 0x19ecf8 <_Z13Object_Existsi>
 *   @0xf2f0c cmp r0, #0
 *   @0xf2f10 beq 0xf2f6c <_Z10Find_EventiiiRi+0xec>
 *   @0xf2f14 ldr r2, [r6]
 *   @0xf2f18 ldr r3, [r4, #0xc]
 *   @0xf2f1c str r3, [r7]
 *   @0xf2f20 ldr r1, [r2, #0x4]
 *   @0xf2f24 ldr r3, [r4, #0xc]
 *   @0xf2f28 ldr r2, [r2]
 *   @0xf2f2c and r1, r3, r1
 *   @0xf2f30 ldr r12, [r2, r1, lsl #3]
 *   @0xf2f34 cmp r12, #0
 *   @0xf2f38 beq 0xf2f6c <_Z10Find_EventiiiRi+0xec>
 *   @0xf2f3c ldr r2, [r12, #0x8]
 *   @0xf2f40 cmp r3, r2
 *   @0xf2f44 beq 0xf2f60 <_Z10Find_EventiiiRi+0xe0>
 *   @0xf2f48 ldr r12, [r12, #0x4]
 *   @0xf2f4c cmp r12, #0
 *   @0xf2f50 beq 0xf2f6c <_Z10Find_EventiiiRi+0xec>
 *   @0xf2f54 ldr r4, [r12, #0x8]
 *   @0xf2f58 cmp r3, r4
 *   @0xf2f5c bne 0xf2f48 <_Z10Find_EventiiiRi+0xc8>
 *   @0xf2f60 ldr r4, [r12, #0xc]
 *   @0xf2f64 cmp r4, #0
 *   @0xf2f68 bne 0xf2ee4 <_Z10Find_EventiiiRi+0x64>
 *   @0xf2f6c cmp r9, #4
 *   @0xf2f70 beq 0xf2f7c <_Z10Find_EventiiiRi+0xfc>
 *   @0xf2f74 mov r0, #0
 *   @0xf2f78 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xf2f7c mov r0, r8
 *   @0xf2f80 bl 0x19ecf8 <_Z13Object_Existsi>
 *   @0xf2f84 cmp r0, #0
 *   @0xf2f88 beq 0xf2f74 <_Z10Find_EventiiiRi+0xf4>
 *   @0xf2f8c ldr r3, [r6]
 *   @0xf2f90 ldr r2, [r3, #0x4]
 *   @0xf2f94 ldr r3, [r3]
 *   @0xf2f98 and r2, r8, r2
 *   @0xf2f9c ldr r3, [r3, r2, lsl #3]
 *   @0xf2fa0 cmp r3, #0
 *   @0xf2fa4 bne 0xf2fb8 <_Z10Find_EventiiiRi+0x138>
 *   @0xf2fa8 b 0xf2fc8 <_Z10Find_EventiiiRi+0x148>
 *   @0xf2fac ldr r3, [r3, #0x4]
 *   @0xf2fb0 cmp r3, #0
 *   @0xf2fb4 beq 0xf2fc8 <_Z10Find_EventiiiRi+0x148>
 *   @0xf2fb8 ldr r2, [r3, #0x8]
 *   @0xf2fbc cmp r8, r2
 *   @0xf2fc0 bne 0xf2fac <_Z10Find_EventiiiRi+0x12c>
 *   @0xf2fc4 ldr r3, [r3, #0xc]
 *   @0xf2fc8 ldr r8, [r3, #0xc]
 *   @0xf2fcc cmp r8, #0
 *   @0xf2fd0 blt 0xf2f74 <_Z10Find_EventiiiRi+0xf4>
 *   @0xf2fd4 mov r0, r8
 *   @0xf2fd8 bl 0x19ecf8 <_Z13Object_Existsi>
 *   @0xf2fdc cmp r0, #0
 *   @0xf2fe0 beq 0xf2f74 <_Z10Find_EventiiiRi+0xf4>
 *   @0xf2fe4 ldr r3, [r6]
 *   @0xf2fe8 str r5, [r7]
 *   @0xf2fec ldm r3, {r0, r9}
 *   @0xf2ff0 and r3, r5, r9
 *   @0xf2ff4 ldr r3, [r0, r3, lsl #3]
 *   @0xf2ff8 cmp r3, #0
 *   @0xf2ffc bne 0xf3010 <_Z10Find_EventiiiRi+0x190>
 *   @0xf3000 b 0xf30b8 <_Z10Find_EventiiiRi+0x238>
 *   @0xf3004 ldr r3, [r3, #0x4]
 *   @0xf3008 cmp r3, #0
 *   @0xf300c beq 0xf30b8 <_Z10Find_EventiiiRi+0x238>
 *   @0xf3010 ldr r2, [r3, #0x8]
 *   @0xf3014 cmp r5, r2
 *   @0xf3018 bne 0xf3004 <_Z10Find_EventiiiRi+0x184>
 *   @0xf301c ldr r4, [r3, #0xc]
 *   @0xf3020 cmp r4, #0
 *   @0xf3024 beq 0xf30b8 <_Z10Find_EventiiiRi+0x238>
 *   @0xf3028 mov r0, r4
 *   @0xf302c mov r1, #4
 *   @0xf3030 mov r2, r8
 *   @0xf3034 bl 0x19da74 <_ZN9CObjectGM14GetEventDirectEii>
 *   @0xf3038 cmp r0, #0
 *   @0xf303c popne {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xf3040 ldr r0, [r4, #0xc]
 *   @0xf3044 cmp r0, #0
 *   @0xf3048 blt 0xf30b0 <_Z10Find_EventiiiRi+0x230>
 *   @0xf304c bl 0x19ecf8 <_Z13Object_Existsi>
 *   @0xf3050 cmp r0, #0
 *   @0xf3054 beq 0xf30b0 <_Z10Find_EventiiiRi+0x230>
 *   @0xf3058 ldr r3, [r6]
 *   @0xf305c ldr r2, [r4, #0xc]
 *   @0xf3060 str r2, [r7]
 *   @0xf3064 ldm r3, {r0, r9}
 *   @0xf3068 ldr r4, [r4, #0xc]
 *   @0xf306c and r3, r4, r9
 *   @0xf3070 ldr r1, [r0, r3, lsl #3]
 *   @0xf3074 cmp r1, #0
 *   @0xf3078 beq 0xf30b8 <_Z10Find_EventiiiRi+0x238>
 *   @0xf307c ldr r3, [r1, #0x8]
 *   @0xf3080 cmp r4, r3
 *   @0xf3084 beq 0xf30a0 <_Z10Find_EventiiiRi+0x220>
 *   @0xf3088 ldr r1, [r1, #0x4]
 *   @0xf308c cmp r1, #0
 *   @0xf3090 beq 0xf30b8 <_Z10Find_EventiiiRi+0x238>
 *   @0xf3094 ldr r12, [r1, #0x8]
 *   @0xf3098 cmp r4, r12
 *   @0xf309c bne 0xf3088 <_Z10Find_EventiiiRi+0x208>
 *   @0xf30a0 ldr r4, [r1, #0xc]
 *   @0xf30a4 cmp r4, #0
 *   @0xf30a8 bne 0xf3028 <_Z10Find_EventiiiRi+0x1a8>
 *   @0xf30ac b 0xf30b8 <_Z10Find_EventiiiRi+0x238>
 *   @0xf30b0 ldr r3, [r6]
 *   @0xf30b4 ldm r3, {r0, r9}
 *   @0xf30b8 and r9, r9, r8
 *   @0xf30bc ldr r3, [r0, r9, lsl #3]
 *   @0xf30c0 cmp r3, #0
 *   @0xf30c4 bne 0xf30d8 <_Z10Find_EventiiiRi+0x258>
 *   @0xf30c8 b 0xf2fc8 <_Z10Find_EventiiiRi+0x148>
 *   @0xf30cc ldr r3, [r3, #0x4]
 *   @0xf30d0 cmp r3, #0
 *   @0xf30d4 beq 0xf2fc8 <_Z10Find_EventiiiRi+0x148>
 *   @0xf30d8 ldr r2, [r3, #0x8]
 *   @0xf30dc cmp r8, r2
 *   @0xf30e0 bne 0xf30cc <_Z10Find_EventiiiRi+0x24c>
 *   @0xf30e4 b 0xf2fc4 <_Z10Find_EventiiiRi+0x144>
 *   @0xf30e8 eoreq r10, pc, r4, lsr #27
 *
 * ══ §5/54 HandleLife  0x1a4938  size 620  155 条（0x1a4938..0x1a4ba4）
 * @func 0x1a4938 0x1a4bb4  size 636  159 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: HandleLife(int)+0x258×2 / ParticleSystem_Particles_Create(int, float, float, int, int)×2 / fYYRandom(double)×2 / HandleLife(int)+0x154 / HandleLife(int)+0x1b4 / HandleLife(int)+0x1f4 / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x4×10 / 0x8×8 / 0x2×5 / 0xc×3 / 0x10×2 / 0x14×2 / 0x-c×2 / 0x-8×2
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a4938 ldr r3, [pc, #0x258]
 *   @0x1a493c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1a4940 ldr r3, [pc, r3]
 *   @0x1a4944 mov r9, r0
 *   @0x1a4948 sub sp, sp, #20
 *   @0x1a494c ldr r3, [r3, #0x4]
 *   @0x1a4950 ldr r6, [r3, r0, lsl #2]
 *   @0x1a4954 ldr r0, [r6, #0x8]
 *   @0x1a4958 cmp r0, #0
 *   @0x1a495c ble 0x1a4b90 <_Z10HandleLifei+0x258>
 *   @0x1a4960 ldr r8, [pc, #0x234]
 *   @0x1a4964 mov r4, #0
 *   @0x1a4968 ldr r11, [pc, #0x230]
 *   @0x1a496c mov r10, r4
 *   @0x1a4970 ldr r8, [pc, r8]
 *   @0x1a4974 add r11, pc, r11
 *   @0x1a4978 str r11, [sp, #0xc]
 *   @0x1a497c mov r11, r8
 *   @0x1a4980 ldr r1, [r6, #0x4]
 *   @0x1a4984 lsl r7, r4, #2
 *   @0x1a4988 ldr r12, [r11, #0x4]
 *   @0x1a498c ldr r2, [r1, r4, lsl #2]
 *   @0x1a4990 ldr r3, [r2, #0x8]
 *   @0x1a4994 ldr r8, [r2, #0xc]
 *   @0x1a4998 add r3, r3, #1
 *   @0x1a499c ldr r5, [r2, #0x4]
 *   @0x1a49a0 cmp r3, r8
 *   @0x1a49a4 ldr r5, [r12, r5, lsl #2]
 *   @0x1a49a8 str r3, [r2, #0x8]
 *   @0x1a49ac blt 0x1a4a8c <_Z10HandleLifei+0x154>
 *   @0x1a49b0 cmp r5, #0
 *   @0x1a49b4 strb r10, [r2]
 *   @0x1a49b8 beq 0x1a4adc <_Z10HandleLifei+0x1a4>
 *   @0x1a49bc ldr r8, [r5, #0x30]
 *   @0x1a49c0 cmp r8, #0
 *   @0x1a49c4 blt 0x1a4aec <_Z10HandleLifei+0x1b4>
 *   @0x1a49c8 beq 0x1a4adc <_Z10HandleLifei+0x1a4>
 *   @0x1a49cc ldr r1, [r2, #0x10]
 *   @0x1a49d0 mov r0, r9
 *   @0x1a49d4 ldr r3, [r5, #0x2c]
 *   @0x1a49d8 ldr r2, [r2, #0x14]
 *   @0x1a49dc str r8, [sp]
 *   @0x1a49e0 bl 0x1a3b78 <_Z31ParticleSystem_Particles_Createiffii>
 *   @0x1a49e4 ldr r1, [r6, #0x4]
 *   @0x1a49e8 ldr r3, [r1, r7]
 *   @0x1a49ec ldrb r3, [r3]
 *   @0x1a49f0 cmp r3, #0
 *   @0x1a49f4 bne 0x1a4aa0 <_Z10HandleLifei+0x168>
 *   @0x1a49f8 ldr r0, [r6, #0x8]
 *   @0x1a49fc add r4, r4, #1
 *   @0x1a4a00 cmp r0, r4
 *   @0x1a4a04 bgt 0x1a4980 <_Z10HandleLifei+0x48>
 *   @0x1a4a08 cmp r0, #0
 *   @0x1a4a0c ble 0x1a4b90 <_Z10HandleLifei+0x258>
 *   @0x1a4a10 mov r12, #0
 *   @0x1a4a14 mov r3, r12
 *   @0x1a4a18 ldr r1, [r6, #0x4]
 *   @0x1a4a1c ldr r2, [r1, r3, lsl #2]
 *   @0x1a4a20 ldrb r4, [r2]
 *   @0x1a4a24 cmp r4, #0
 *   @0x1a4a28 beq 0x1a4a74 <_Z10HandleLifei+0x13c>
 *   @0x1a4a2c cmp r3, r12
 *   @0x1a4a30 beq 0x1a4a70 <_Z10HandleLifei+0x138>
 *   @0x1a4a34 ldr r1, [r1, r12, lsl #2]
 *   @0x1a4a38 add r0, r2, #64
 *   @0x1a4a3c ldr r8, [r2]
 *   @0x1a4a40 add r2, r2, #16
 *   @0x1a4a44 ldr r7, [r2, #-0xc]
 *   @0x1a4a48 add r1, r1, #16
 *   @0x1a4a4c ldr r5, [r2, #-0x8]
 *   @0x1a4a50 ldr r4, [r2, #-0x4]
 *   @0x1a4a54 cmp r2, r0
 *   @0x1a4a58 str r8, [r1, #-0x10]
 *   @0x1a4a5c str r7, [r1, #-0xc]
 *   @0x1a4a60 str r5, [r1, #-0x8]
 *   @0x1a4a64 str r4, [r1, #-0x4]
 *   @0x1a4a68 bne 0x1a4a3c <_Z10HandleLifei+0x104>
 *   @0x1a4a6c ldr r0, [r6, #0x8]
 *   @0x1a4a70 add r12, r12, #1
 *   @0x1a4a74 add r3, r3, #1
 *   @0x1a4a78 cmp r0, r3
 *   @0x1a4a7c bgt 0x1a4a18 <_Z10HandleLifei+0xe0>
 *   @0x1a4a80 str r12, [r6, #0x8]
 *   @0x1a4a84 add sp, sp, #20
 *   @0x1a4a88 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1a4a8c ldrb r3, [r2]
 *   @0x1a4a90 cmp r3, #0
 *   @0x1a4a94 beq 0x1a4adc <_Z10HandleLifei+0x1a4>
 *   @0x1a4a98 cmp r5, #0
 *   @0x1a4a9c beq 0x1a4adc <_Z10HandleLifei+0x1a4>
 *   @0x1a4aa0 ldr r8, [r5, #0x38]
 *   @0x1a4aa4 cmp r8, #0
 *   @0x1a4aa8 blt 0x1a4b2c <_Z10HandleLifei+0x1f4>
 *   @0x1a4aac beq 0x1a49f8 <_Z10HandleLifei+0xc0>
 *   @0x1a4ab0 ldr r2, [r1, r7]
 *   @0x1a4ab4 ldr r3, [r5, #0x34]
 *   @0x1a4ab8 ldr r1, [r2, #0x4]
 *   @0x1a4abc cmp r3, r1
 *   @0x1a4ac0 beq 0x1a4b7c <_Z10HandleLifei+0x244>
 *   @0x1a4ac4 ldr r1, [r2, #0x10]
 *   @0x1a4ac8 mov r0, r9
 *   @0x1a4acc ldr r2, [r2, #0x14]
 *   @0x1a4ad0 str r8, [sp]
 *   @0x1a4ad4 bl 0x1a3b78 <_Z31ParticleSystem_Particles_Createiffii>
 *   @0x1a4ad8 ldr r0, [r6, #0x8]
 *   @0x1a4adc add r4, r4, #1
 *   @0x1a4ae0 cmp r0, r4
 *   @0x1a4ae4 bgt 0x1a4980 <_Z10HandleLifei+0x48>
 *   @0x1a4ae8 b 0x1a4a08 <_Z10HandleLifei+0xd0>
 *   @0x1a4aec mov r0, #0
 *   @0x1a4af0 mov r1, #0
 *   @0x1a4af4 movt r1, #0x3ff0
 *   @0x1a4af8 rsb r8, r8, #0
 *   @0x1a4afc bl 0xc4598 <_Z9fYYRandomd>
 *   @0x1a4b00 vmov s14, r8
 *   @0x1a4b04 vcvt.f64.s32 d7, s14
 *   @0x1a4b08 vmov d6, r0, r1
 *   @0x1a4b0c vmul.f64 d7, d6, d7
 *   @0x1a4b10 vcmp.f64 d7, #0
 *   @0x1a4b14 vmrs APSR_nzcv, fpscr
 *   @0x1a4b18 bne 0x1a4b6c <_Z10HandleLifei+0x234>
 *   @0x1a4b1c ldr r3, [r6, #0x4]
 *   @0x1a4b20 mov r8, #1
 *   @0x1a4b24 ldr r2, [r3, r7]
 *   @0x1a4b28 b 0x1a49cc <_Z10HandleLifei+0x94>
 *   @0x1a4b2c mov r0, #0
 *   @0x1a4b30 mov r1, #0
 *   @0x1a4b34 movt r1, #0x3ff0
 *   @0x1a4b38 rsb r8, r8, #0
 *   @0x1a4b3c bl 0xc4598 <_Z9fYYRandomd>
 *   @0x1a4b40 vmov s14, r8
 *   @0x1a4b44 vcvt.f64.s32 d7, s14
 *   @0x1a4b48 vmov d6, r0, r1
 *   @0x1a4b4c vmul.f64 d7, d7, d6
 *   @0x1a4b50 vcvt.s32.f64 s14, d7
 *   @0x1a4b54 vmov r3, s14
 *   @0x1a4b58 cmp r3, #0
 *   @0x1a4b5c bne 0x1a49f8 <_Z10HandleLifei+0xc0>
 *   @0x1a4b60 ldr r1, [r6, #0x4]
 *   @0x1a4b64 mov r8, #1
 *   @0x1a4b68 b 0x1a4ab0 <_Z10HandleLifei+0x178>
 *   @0x1a4b6c ldr r1, [r6, #0x4]
 *   @0x1a4b70 ldr r3, [r1, r7]
 *   @0x1a4b74 ldrb r3, [r3]
 *   @0x1a4b78 b 0x1a49f0 <_Z10HandleLifei+0xb8>
 *   @0x1a4b7c ldr r0, [sp, #0xc]
 *   @0x1a4b80 mov r1, #0
 *   @0x1a4b84 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1a4b88 ldr r0, [r6, #0x8]
 *   @0x1a4b8c b 0x1a49fc <_Z10HandleLifei+0xc4>
 *   @0x1a4b90 mov r12, #0
 *   @0x1a4b94 b 0x1a4a80 <_Z10HandleLifei+0x148>
 *   @0x1a4b98 eoreq r11, r4, r8, ror lr
 *   @0x1a4b9c eoreq r11, r4, r12, lsr lr
 *   @0x1a4ba0 andseq r8, r10, r12, lsr #14
 *
 * ══ §6/54 __muldf3  0x31ab34  size 620  155 条（0x31ab34..0x31ada0）
 * @func 0x31ab34 0x31ada0  size 620  155 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __muldf3+0x1e0
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31ab34 push {r4, r5, r6, lr}
 *   @0x31ab38 mov r12, #255
 *   @0x31ab3c orr r12, r12, #1792
 *   @0x31ab40 ands r4, r12, r1, lsr #20
 *   @0x31ab44 andsne r5, r12, r3, lsr #20
 *   @0x31ab48 teqne r4, r12
 *   @0x31ab4c teqne r5, r12
 *   @0x31ab50 bleq 0x31ad14 <__muldf3+0x1e0>
 *   @0x31ab54 add r4, r4, r5
 *   @0x31ab58 eor r6, r1, r3
 *   @0x31ab5c bic r1, r1, r12, lsl #21
 *   @0x31ab60 bic r3, r3, r12, lsl #21
 *   @0x31ab64 orrs r5, r0, r1, lsl #12
 *   @0x31ab68 orrsne r5, r2, r3, lsl #12
 *   @0x31ab6c orr r1, r1, #1048576
 *   @0x31ab70 orr r3, r3, #1048576
 *   @0x31ab74 beq 0x31abec <__muldf3+0xb8>
 *   @0x31ab78 umull r12, lr, r0, r2
 *   @0x31ab7c mov r5, #0
 *   @0x31ab80 umlal lr, r5, r1, r2
 *   @0x31ab84 and r2, r6, #-2147483648
 *   @0x31ab88 umlal lr, r5, r0, r3
 *   @0x31ab8c mov r6, #0
 *   @0x31ab90 umlal r5, r6, r1, r3
 *   @0x31ab94 teq r12, #0
 *   @0x31ab98 orrne lr, lr, #1
 *   @0x31ab9c sub r4, r4, #255
 *   @0x31aba0 cmp r6, #512
 *   @0x31aba4 sbc r4, r4, #768
 *   @0x31aba8 bhs 0x31abb8 <__muldf3+0x84>
 *   @0x31abac lsls lr, lr, #1
 *   @0x31abb0 adcs r5, r5, r5
 *   @0x31abb4 adc r6, r6, r6
 *   @0x31abb8 orr r1, r2, r6, lsl #11
 *   @0x31abbc orr r1, r1, r5, lsr #21
 *   @0x31abc0 lsl r0, r5, #11
 *   @0x31abc4 orr r0, r0, lr, lsr #21
 *   @0x31abc8 lsl lr, lr, #11
 *   @0x31abcc subs r12, r4, #253
 *   @0x31abd0 cmphi r12, #1792
 *   @0x31abd4 bhi 0x31ac18 <__muldf3+0xe4>
 *   @0x31abd8 cmp lr, #-2147483648
 *   @0x31abdc lsrseq lr, r0, #1
 *   @0x31abe0 adcs r0, r0, #0
 *   @0x31abe4 adc r1, r1, r4, lsl #20
 *   @0x31abe8 pop {r4, r5, r6, pc}
 *   @0x31abec and r6, r6, #-2147483648
 *   @0x31abf0 orr r1, r6, r1
 *   @0x31abf4 orr r0, r0, r2
 *   @0x31abf8 eor r1, r1, r3
 *   @0x31abfc subs r4, r4, r12, lsr #1
 *   @0x31ac00 rsbsgt r5, r4, r12
 *   @0x31ac04 orrgt r1, r1, r4, lsl #20
 *   @0x31ac08 popgt {r4, r5, r6, pc}
 *   @0x31ac0c orr r1, r1, #1048576
 *   @0x31ac10 mov lr, #0
 *   @0x31ac14 subs r4, r4, #1
 *   @0x31ac18 bgt 0x31ad80 <__muldf3+0x24c>
 *   @0x31ac1c cmn r4, #54
 *   @0x31ac20 movle r0, #0
 *   @0x31ac24 andle r1, r1, #-2147483648
 *   @0x31ac28 pople {r4, r5, r6, pc}
 *   @0x31ac2c rsb r4, r4, #0
 *   @0x31ac30 subs r4, r4, #32
 *   @0x31ac34 bge 0x31ac9c <__muldf3+0x168>
 *   @0x31ac38 adds r4, r4, #12
 *   @0x31ac3c bgt 0x31ac70 <__muldf3+0x13c>
 *   @0x31ac40 add r4, r4, #20
 *   @0x31ac44 rsb r5, r4, #32
 *   @0x31ac48 lsl r3, r0, r5
 *   @0x31ac4c lsr r0, r0, r4
 *   @0x31ac50 orr r0, r0, r1, lsl r5
 *   @0x31ac54 and r2, r1, #-2147483648
 *   @0x31ac58 bic r1, r1, #-2147483648
 *   @0x31ac5c adds r0, r0, r3, lsr #31
 *   @0x31ac60 adc r1, r2, r1, lsr r4
 *   @0x31ac64 orrs lr, lr, r3, lsl #1
 *   @0x31ac68 biceq r0, r0, r3, lsr #31
 *   @0x31ac6c pop {r4, r5, r6, pc}
 *   @0x31ac70 rsb r4, r4, #12
 *   @0x31ac74 rsb r5, r4, #32
 *   @0x31ac78 lsl r3, r0, r4
 *   @0x31ac7c lsr r0, r0, r5
 *   @0x31ac80 orr r0, r0, r1, lsl r4
 *   @0x31ac84 and r1, r1, #-2147483648
 *   @0x31ac88 adds r0, r0, r3, lsr #31
 *   @0x31ac8c adc r1, r1, #0
 *   @0x31ac90 orrs lr, lr, r3, lsl #1
 *   @0x31ac94 biceq r0, r0, r3, lsr #31
 *   @0x31ac98 pop {r4, r5, r6, pc}
 *   @0x31ac9c rsb r5, r4, #32
 *   @0x31aca0 orr lr, lr, r0, lsl r5
 *   @0x31aca4 lsr r3, r0, r4
 *   @0x31aca8 orr r3, r3, r1, lsl r5
 *   @0x31acac lsr r0, r1, r4
 *   @0x31acb0 and r1, r1, #-2147483648
 *   @0x31acb4 bic r0, r0, r1, lsr r4
 *   @0x31acb8 add r0, r0, r3, lsr #31
 *   @0x31acbc orrs lr, lr, r3, lsl #1
 *   @0x31acc0 biceq r0, r0, r3, lsr #31
 *   @0x31acc4 pop {r4, r5, r6, pc}
 *   @0x31acc8 teq r4, #0
 *   @0x31accc bne 0x31acf4 <__muldf3+0x1c0>
 *   @0x31acd0 and r6, r1, #-2147483648
 *   @0x31acd4 lsls r0, r0, #1
 *   @0x31acd8 adc r1, r1, r1
 *   @0x31acdc tst r1, #1048576
 *   @0x31ace0 subeq r4, r4, #1
 *   @0x31ace4 beq 0x31acd4 <__muldf3+0x1a0>
 *   @0x31ace8 orr r1, r1, r6
 *   @0x31acec teq r5, #0
 *   @0x31acf0 bxne lr
 *   @0x31acf4 and r6, r3, #-2147483648
 *   @0x31acf8 lsls r2, r2, #1
 *   @0x31acfc adc r3, r3, r3
 *   @0x31ad00 tst r3, #1048576
 *   @0x31ad04 subeq r5, r5, #1
 *   @0x31ad08 beq 0x31acf8 <__muldf3+0x1c4>
 *   @0x31ad0c orr r3, r3, r6
 *   @0x31ad10 bx lr
 *   @0x31ad14 teq r4, r12
 *   @0x31ad18 and r5, r12, r3, lsr #20
 *   @0x31ad1c teqne r5, r12
 *   @0x31ad20 beq 0x31ad40 <__muldf3+0x20c>
 *   @0x31ad24 orrs r6, r0, r1, lsl #1
 *   @0x31ad28 orrsne r6, r2, r3, lsl #1
 *   @0x31ad2c bne 0x31acc8 <__muldf3+0x194>
 *   @0x31ad30 eor r1, r1, r3
 *   @0x31ad34 and r1, r1, #-2147483648
 *   @0x31ad38 mov r0, #0
 *   @0x31ad3c pop {r4, r5, r6, pc}
 *   @0x31ad40 orrs r6, r0, r1, lsl #1
 *   @0x31ad44 moveq r0, r2
 *   @0x31ad48 moveq r1, r3
 *   @0x31ad4c orrsne r6, r2, r3, lsl #1
 *   @0x31ad50 beq 0x31ad94 <__muldf3+0x260>
 *   @0x31ad54 teq r4, r12
 *   @0x31ad58 bne 0x31ad64 <__muldf3+0x230>
 *   @0x31ad5c orrs r6, r0, r1, lsl #12
 *   @0x31ad60 bne 0x31ad94 <__muldf3+0x260>
 *   @0x31ad64 teq r5, r12
 *   @0x31ad68 bne 0x31ad7c <__muldf3+0x248>
 *   @0x31ad6c orrs r6, r2, r3, lsl #12
 *   @0x31ad70 movne r0, r2
 *   @0x31ad74 movne r1, r3
 *   @0x31ad78 bne 0x31ad94 <__muldf3+0x260>
 *   @0x31ad7c eor r1, r1, r3
 *   @0x31ad80 and r1, r1, #-2147483648
 *   @0x31ad84 orr r1, r1, #2130706432
 *   @0x31ad88 orr r1, r1, #15728640
 *   @0x31ad8c mov r0, #0
 *   @0x31ad90 pop {r4, r5, r6, pc}
 *   @0x31ad94 orr r1, r1, #2130706432
 *   @0x31ad98 orr r1, r1, #16252928
 *   @0x31ad9c pop {r4, r5, r6, pc}
 *
 * ══ §7/54 CDS_Queue::Dequeue  0x205ab0  size 616  154 条（0x205ab0..0x205d18）
 * @func 0x205ab0 0x205d18  size 616  154 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CDS_Queue::Dequeue()+0xf8×2 / CDS_Queue::Dequeue()+0x210×2 / LOCK_RVALUE_MUTEX()×2 / UNLOCK_RVALUE_MUTEX()×2 / YYFree(void const*)×2 / operator delete(void*)×2 / GetContextStackTop() / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)
 * 字段偏移 top8: 0x4×11 / 0x8×9 / 0xc×5 / 0x10×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x205ab0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x205ab4 mov r7, r0
 *   @0x205ab8 ldmib r0, {r2, r9}
 *   @0x205abc sub sp, sp, #12
 *   @0x205ac0 cmp r9, r2
 *   @0x205ac4 beq 0x205d10 <_ZN9CDS_Queue7DequeueEv+0x260>
 *   @0x205ac8 add r6, r9, #1
 *   @0x205acc ldr r3, [r0, #0x10]
 *   @0x205ad0 cmp r6, #16
 *   @0x205ad4 str r6, [r0, #0x8]
 *   @0x205ad8 add r9, r3, r9, lsl #4
 *   @0x205adc ble 0x205ba8 <_ZN9CDS_Queue7DequeueEv+0xf8>
 *   @0x205ae0 add r1, r2, r2, lsr #31
 *   @0x205ae4 cmp r6, r1, asr #1
 *   @0x205ae8 ble 0x205ba8 <_ZN9CDS_Queue7DequeueEv+0xf8>
 *   @0x205aec rsb r2, r6, r2
 *   @0x205af0 cmp r2, #0
 *   @0x205af4 ble 0x205cc0 <_ZN9CDS_Queue7DequeueEv+0x210>
 *   @0x205af8 mov r5, #0
 *   @0x205afc mov r10, #5
 *   @0x205b00 mov r8, r5
 *   @0x205b04 add r4, r3, r5, lsl #4
 *   @0x205b08 add r6, r5, r6
 *   @0x205b0c ldr r1, [r4, #0xc]
 *   @0x205b10 add r6, r3, r6, lsl #4
 *   @0x205b14 bic r2, r1, #-16777216
 *   @0x205b18 cmp r2, #1
 *   @0x205b1c beq 0x205c50 <_ZN9CDS_Queue7DequeueEv+0x1a0>
 *   @0x205b20 cmp r2, #2
 *   @0x205b24 bne 0x205b44 <_ZN9CDS_Queue7DequeueEv+0x94>
 *   @0x205b28 sub r1, r1, #1
 *   @0x205b2c bic r1, r1, #-16777216
 *   @0x205b30 bic r1, r1, #3
 *   @0x205b34 cmp r1, #0
 *   @0x205b38 beq 0x205cd8 <_ZN9CDS_Queue7DequeueEv+0x228>
 *   @0x205b3c str r8, [r4, #0x8]
 *   @0x205b40 str r10, [r4, #0xc]
 *   @0x205b44 ldr r3, [r6, #0xc]
 *   @0x205b48 ldr r2, [r6, #0x8]
 *   @0x205b4c str r8, [r4]
 *   @0x205b50 str r3, [r4, #0xc]
 *   @0x205b54 ldr r3, [r6, #0xc]
 *   @0x205b58 str r2, [r4, #0x8]
 *   @0x205b5c bic r3, r3, #-16777216
 *   @0x205b60 cmp r3, #14
 *   @0x205b64 addls pc, pc, r3, lsl #2
 *   @0x205b68 b 0x205bbc <_ZN9CDS_Queue7DequeueEv+0x10c>
 *   @0x205b6c b 0x205bdc <_ZN9CDS_Queue7DequeueEv+0x12c>
 *   @0x205b70 b 0x205c38 <_ZN9CDS_Queue7DequeueEv+0x188>
 *   @0x205b74 b 0x205c0c <_ZN9CDS_Queue7DequeueEv+0x15c>
 *   @0x205b78 b 0x205bb4 <_ZN9CDS_Queue7DequeueEv+0x104>
 *   @0x205b7c b 0x205bbc <_ZN9CDS_Queue7DequeueEv+0x10c>
 *   @0x205b80 b 0x205bbc <_ZN9CDS_Queue7DequeueEv+0x10c>
 *   @0x205b84 b 0x205be8 <_ZN9CDS_Queue7DequeueEv+0x138>
 *   @0x205b88 b 0x205bb4 <_ZN9CDS_Queue7DequeueEv+0x104>
 *   @0x205b8c b 0x205bbc <_ZN9CDS_Queue7DequeueEv+0x10c>
 *   @0x205b90 b 0x205bbc <_ZN9CDS_Queue7DequeueEv+0x10c>
 *   @0x205b94 b 0x205bdc <_ZN9CDS_Queue7DequeueEv+0x12c>
 *   @0x205b98 b 0x205bbc <_ZN9CDS_Queue7DequeueEv+0x10c>
 *   @0x205b9c b 0x205bbc <_ZN9CDS_Queue7DequeueEv+0x10c>
 *   @0x205ba0 b 0x205bdc <_ZN9CDS_Queue7DequeueEv+0x12c>
 *   @0x205ba4 b 0x205bb4 <_ZN9CDS_Queue7DequeueEv+0x104>
 *   @0x205ba8 mov r0, r9
 *   @0x205bac add sp, sp, #12
 *   @0x205bb0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x205bb4 ldr r3, [r6]
 *   @0x205bb8 str r3, [r4]
 *   @0x205bbc ldr r6, [r7, #0x8]
 *   @0x205bc0 add r5, r5, #1
 *   @0x205bc4 ldr r2, [r7, #0x4]
 *   @0x205bc8 rsb r2, r6, r2
 *   @0x205bcc cmp r2, r5
 *   @0x205bd0 ble 0x205cc0 <_ZN9CDS_Queue7DequeueEv+0x210>
 *   @0x205bd4 ldr r3, [r7, #0x10]
 *   @0x205bd8 b 0x205b04 <_ZN9CDS_Queue7DequeueEv+0x54>
 *   @0x205bdc ldm r6, {r2, r3}
 *   @0x205be0 stm r4, {r2, r3}
 *   @0x205be4 b 0x205bbc <_ZN9CDS_Queue7DequeueEv+0x10c>
 *   @0x205be8 ldr r3, [r6]
 *   @0x205bec str r3, [r4]
 *   @0x205bf0 ldr r3, [r6]
 *   @0x205bf4 cmp r3, #0
 *   @0x205bf8 beq 0x205bbc <_ZN9CDS_Queue7DequeueEv+0x10c>
 *   @0x205bfc bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x205c00 ldr r1, [r6]
 *   @0x205c04 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x205c08 b 0x205bbc <_ZN9CDS_Queue7DequeueEv+0x10c>
 *   @0x205c0c ldr r3, [r6]
 *   @0x205c10 cmp r3, #0
 *   @0x205c14 str r3, [r4]
 *   @0x205c18 beq 0x205bbc <_ZN9CDS_Queue7DequeueEv+0x10c>
 *   @0x205c1c ldr r1, [r3, #0x8]
 *   @0x205c20 ldr r2, [r3]
 *   @0x205c24 cmp r1, #0
 *   @0x205c28 streq r4, [r3, #0x8]
 *   @0x205c2c add r2, r2, #1
 *   @0x205c30 str r2, [r3]
 *   @0x205c34 b 0x205bbc <_ZN9CDS_Queue7DequeueEv+0x10c>
 *   @0x205c38 ldr r3, [r6]
 *   @0x205c3c cmp r3, #0
 *   @0x205c40 ldrne r2, [r3, #0x4]
 *   @0x205c44 addne r2, r2, #1
 *   @0x205c48 strne r2, [r3, #0x4]
 *   @0x205c4c b 0x205bb8 <_ZN9CDS_Queue7DequeueEv+0x108>
 *   @0x205c50 ldr r11, [r3, r5, lsl #4]
 *   @0x205c54 cmp r11, #0
 *   @0x205c58 beq 0x205c78 <_ZN9CDS_Queue7DequeueEv+0x1c8>
 *   @0x205c5c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x205c60 ldr r3, [r11, #0x4]
 *   @0x205c64 sub r3, r3, #1
 *   @0x205c68 str r3, [r11, #0x4]
 *   @0x205c6c cmp r3, #0
 *   @0x205c70 beq 0x205c80 <_ZN9CDS_Queue7DequeueEv+0x1d0>
 *   @0x205c74 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x205c78 str r8, [r4]
 *   @0x205c7c b 0x205b44 <_ZN9CDS_Queue7DequeueEv+0x94>
 *   @0x205c80 ldr r0, [r11]
 *   @0x205c84 str r3, [sp, #0x4]
 *   @0x205c88 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x205c8c ldr r3, [sp, #0x4]
 *   @0x205c90 str r3, [r11]
 *   @0x205c94 str r3, [r11, #0x8]
 *   @0x205c98 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x205c9c ldr r3, [r11, #0x4]
 *   @0x205ca0 sub r3, r3, #1
 *   @0x205ca4 str r3, [r11, #0x4]
 *   @0x205ca8 cmp r3, #0
 *   @0x205cac beq 0x205ce4 <_ZN9CDS_Queue7DequeueEv+0x234>
 *   @0x205cb0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x205cb4 mov r0, r11
 *   @0x205cb8 bl 0x27d1d0 <_ZdlPv>
 *   @0x205cbc b 0x205c74 <_ZN9CDS_Queue7DequeueEv+0x1c4>
 *   @0x205cc0 mov r0, r9
 *   @0x205cc4 mov r3, #0
 *   @0x205cc8 str r2, [r7, #0x4]
 *   @0x205ccc str r3, [r7, #0x8]
 *   @0x205cd0 add sp, sp, #12
 *   @0x205cd4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x205cd8 mov r0, r4
 *   @0x205cdc bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x205ce0 b 0x205b3c <_ZN9CDS_Queue7DequeueEv+0x8c>
 *   @0x205ce4 ldr r0, [r11]
 *   @0x205ce8 str r3, [sp, #0x4]
 *   @0x205cec bl 0xcef90 <_Z6YYFreePKv>
 *   @0x205cf0 ldr r3, [sp, #0x4]
 *   @0x205cf4 mov r0, r11
 *   @0x205cf8 str r3, [r11]
 *   @0x205cfc str r3, [r11, #0x8]
 *   @0x205d00 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x205d04 mov r0, r11
 *   @0x205d08 bl 0x27d1d0 <_ZdlPv>
 *   @0x205d0c b 0x205cb0 <_ZN9CDS_Queue7DequeueEv+0x200>
 *   @0x205d10 mov r0, #0
 *   @0x205d14 b 0x205bac <_ZN9CDS_Queue7DequeueEv+0xfc>
 *
 * ══ §8/54 vorbis_synthesis_init  0x2273d0  size 616  154 条（0x2273d0..0x227638）
 * @func 0x2273d0 0x227638  size 616  154 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6c34×4 / _vorbis_window×2 / 0xb6544×2 / vorbis_staticbook_destroy×2 / 0xb65b0 / vorbis_synthesis_init+0x15c / vorbis_synthesis_init+0x120 / vorbis_synthesis_restart
 * 字段偏移 top8: 0x4×8 / 0x8×6 / 0x1c×5 / 0xc×4 / 0x820×4 / 0xc20×3 / 0x2×3 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2273d0 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2273d4 mov r6, r1
 *   @0x2273d8 ldr r5, [r1, #0x1c]
 *   @0x2273dc mov r7, r0
 *   @0x2273e0 cmp r5, #0
 *   @0x2273e4 beq 0x2275e8 <vorbis_synthesis_init+0x218>
 *   @0x2273e8 mov r2, #80
 *   @0x2273ec mov r1, #0
 *   @0x2273f0 bl 0xb65b0 <memset@plt>
 *   @0x2273f4 mov r0, #1
 *   @0x2273f8 mov r1, #24
 *   @0x2273fc bl 0xb6c34 <calloc@plt>
 *   @0x227400 ldr r2, [r5, #0x8]
 *   @0x227404 str r6, [r7, #0x4]
 *   @0x227408 cmp r2, #0
 *   @0x22740c mov r8, r0
 *   @0x227410 str r0, [r7, #0x48]
 *   @0x227414 bne 0x22753c <vorbis_synthesis_init+0x16c>
 *   @0x227418 ldr r3, [r5]
 *   @0x22741c mov r0, #0
 *   @0x227420 str r2, [r8, #0x8]
 *   @0x227424 add r1, r3, r3, lsr #31
 *   @0x227428 asr r1, r1, #1
 *   @0x22742c bl 0x233028 <_vorbis_window>
 *   @0x227430 ldr r3, [r5, #0x4]
 *   @0x227434 add r1, r3, r3, lsr #31
 *   @0x227438 asr r1, r1, #1
 *   @0x22743c str r0, [r8]
 *   @0x227440 mov r0, #0
 *   @0x227444 bl 0x233028 <_vorbis_window>
 *   @0x227448 ldr r9, [r5, #0xc20]
 *   @0x22744c cmp r9, #0
 *   @0x227450 str r0, [r8, #0x4]
 *   @0x227454 beq 0x22755c <vorbis_synthesis_init+0x18c>
 *   @0x227458 ldr r9, [r6, #0x4]
 *   @0x22745c ldr r10, [r5, #0x4]
 *   @0x227460 lsl r4, r9, #2
 *   @0x227464 str r10, [r7, #0x10]
 *   @0x227468 mov r0, r4
 *   @0x22746c bl 0xb6544 <malloc@plt>
 *   @0x227470 mov r6, r0
 *   @0x227474 mov r0, r4
 *   @0x227478 str r6, [r7, #0x8]
 *   @0x22747c bl 0xb6544 <malloc@plt>
 *   @0x227480 cmp r9, #0
 *   @0x227484 movgt r4, #0
 *   @0x227488 str r0, [r7, #0xc]
 *   @0x22748c bgt 0x227498 <vorbis_synthesis_init+0xc8>
 *   @0x227490 b 0x2274b4 <vorbis_synthesis_init+0xe4>
 *   @0x227494 ldr r6, [r7, #0x8]
 *   @0x227498 mov r0, r10
 *   @0x22749c mov r1, #4
 *   @0x2274a0 bl 0xb6c34 <calloc@plt>
 *   @0x2274a4 str r0, [r6, r4, lsl #2]
 *   @0x2274a8 add r4, r4, #1
 *   @0x2274ac cmp r4, r9
 *   @0x2274b0 bne 0x227494 <vorbis_synthesis_init+0xc4>
 *   @0x2274b4 ldr r6, [r5, #0x8]
 *   @0x2274b8 mov r4, #0
 *   @0x2274bc mov r1, #4
 *   @0x2274c0 str r4, [r7, #0x24]
 *   @0x2274c4 str r4, [r7, #0x28]
 *   @0x2274c8 mov r0, r6
 *   @0x2274cc bl 0xb6c34 <calloc@plt>
 *   @0x2274d0 cmp r6, r4
 *   @0x2274d4 str r0, [r8, #0xc]
 *   @0x2274d8 ble 0x22752c <vorbis_synthesis_init+0x15c>
 *   @0x2274dc ldr r9, [pc, #0x150]
 *   @0x2274e0 add r6, r5, #28
 *   @0x2274e4 mov r10, r0
 *   @0x2274e8 ldr r9, [pc, r9]
 *   @0x2274ec b 0x2274f4 <vorbis_synthesis_init+0x124>
 *   @0x2274f0 ldr r10, [r8, #0xc]
 *   @0x2274f4 ldr r1, [r6, #0x4]!
 *   @0x2274f8 mov r0, r7
 *   @0x2274fc ldr r3, [r1, #0xc]
 *   @0x227500 add r3, r5, r3, lsl #2
 *   @0x227504 ldr r12, [r3, #0x120]
 *   @0x227508 ldr r2, [r3, #0x220]
 *   @0x22750c ldr r3, [r9, r12, lsl #2]
 *   @0x227510 ldr r3, [r3, #0x4]
 *   @0x227514 blx r3
 *   @0x227518 ldr r3, [r5, #0x8]
 *   @0x22751c str r0, [r10, r4, lsl #2]
 *   @0x227520 add r4, r4, #1
 *   @0x227524 cmp r4, r3
 *   @0x227528 blt 0x2274f0 <vorbis_synthesis_init+0x120>
 *   @0x22752c mov r0, r7
 *   @0x227530 bl 0x22723c <vorbis_synthesis_restart>
 *   @0x227534 mov r0, #0
 *   @0x227538 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x22753c subs r3, r2, #1
 *   @0x227540 moveq r2, r3
 *   @0x227544 beq 0x227418 <vorbis_synthesis_init+0x48>
 *   @0x227548 mov r2, #0
 *   @0x22754c lsrs r3, r3, #1
 *   @0x227550 add r2, r2, #1
 *   @0x227554 bne 0x22754c <vorbis_synthesis_init+0x17c>
 *   @0x227558 b 0x227418 <vorbis_synthesis_init+0x48>
 *   @0x22755c ldr r4, [r5, #0x1c]
 *   @0x227560 mov r1, #52
 *   @0x227564 mov r0, r4
 *   @0x227568 bl 0xb6c34 <calloc@plt>
 *   @0x22756c cmp r4, #0
 *   @0x227570 str r0, [r5, #0xc20]
 *   @0x227574 ble 0x227458 <vorbis_synthesis_init+0x88>
 *   @0x227578 ldr r1, [r5, #0x820]
 *   @0x22757c cmp r1, #0
 *   @0x227580 beq 0x2275f4 <vorbis_synthesis_init+0x224>
 *   @0x227584 mov r10, r9
 *   @0x227588 mov r4, r5
 *   @0x22758c b 0x2275bc <vorbis_synthesis_init+0x1ec>
 *   @0x227590 ldr r0, [r4, #0x820]
 *   @0x227594 bl 0x22f554 <vorbis_staticbook_destroy>
 *   @0x227598 str r11, [r4, #0x820]
 *   @0x22759c ldr r3, [r5, #0x1c]
 *   @0x2275a0 cmp r10, r3
 *   @0x2275a4 bge 0x227458 <vorbis_synthesis_init+0x88>
 *   @0x2275a8 ldr r1, [r4, #0x824]
 *   @0x2275ac add r4, r4, #4
 *   @0x2275b0 cmp r1, #0
 *   @0x2275b4 beq 0x2275f0 <vorbis_synthesis_init+0x220>
 *   @0x2275b8 ldr r0, [r5, #0xc20]
 *   @0x2275bc add r0, r0, r9
 *   @0x2275c0 add r10, r10, #1
 *   @0x2275c4 bl 0x22f604 <vorbis_book_init_decode>
 *   @0x2275c8 add r9, r9, #52
 *   @0x2275cc subs r11, r0, #0
 *   @0x2275d0 beq 0x227590 <vorbis_synthesis_init+0x1c0>
 *   @0x2275d4 ldr r3, [r5, #0x1c]
 *   @0x2275d8 cmp r3, #0
 *   @0x2275dc bgt 0x2275f0 <vorbis_synthesis_init+0x220>
 *   @0x2275e0 mov r0, r7
 *   @0x2275e4 bl 0x2272ac <vorbis_dsp_clear>
 *   @0x2275e8 mov r0, #1
 *   @0x2275ec pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2275f0 ldr r1, [r5, #0x820]
 *   @0x2275f4 add r6, r5, #2080
 *   @0x2275f8 mov r4, #0
 *   @0x2275fc add r6, r6, #4
 *   @0x227600 mov r8, r4
 *   @0x227604 b 0x22760c <vorbis_synthesis_init+0x23c>
 *   @0x227608 ldr r1, [r6], #4
 *   @0x22760c cmp r1, #0
 *   @0x227610 add r4, r4, #1
 *   @0x227614 mov r0, r1
 *   @0x227618 beq 0x227624 <vorbis_synthesis_init+0x254>
 *   @0x22761c bl 0x22f554 <vorbis_staticbook_destroy>
 *   @0x227620 str r8, [r6, #-0x4]
 *   @0x227624 ldr r3, [r5, #0x1c]
 *   @0x227628 cmp r4, r3
 *   @0x22762c blt 0x227608 <vorbis_synthesis_init+0x238>
 *   @0x227630 b 0x2275e0 <vorbis_synthesis_init+0x210>
 *   @0x227634 mulseq r12, r8, pc
 *
 * ══ §9/54 RenderSurface_AspectAdjusted  0x1b2bb8  size 604  151 条（0x1b2bb8..0x1b2e14）
 * @func 0x1b2bb8 0x1b2e14  size 604  151 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::SetRenderState(eRenderState, unsigned int)×7 / Graphics::Flush()×2 / GR_Surface_Get_Texture(int) / GR_Texture_Get_Surface(int) / GR_Surface_Get_Width(int) / GR_Surface_Get_Height(int) / GR_Surface_DrawStretched(int, float, float, float, float, unsigned int, float) / RenderSurface_AspectAdjusted(int, int, int, int, int, bool, bool, bool)+0x224
 * 字段偏移 top8: 0x14c×3 / 0x154×2 / 0x140×2 / 0x21c×1 / 0x4c×1 / 0x54×1 / 0x200×1 / 0x4×1
 * VFP 指令 51 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b2bb8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1b2bbc vpush {d8, d9}
 *   @0x1b2bc0 sub sp, sp, #20
 *   @0x1b2bc4 vldr s18, [sp, #72]
 *   @0x1b2bc8 ldr r4, [pc, #0x21c]
 *   @0x1b2bcc mov r10, r1
 *   @0x1b2bd0 mov r9, r2
 *   @0x1b2bd4 vmov s17, r3
 *   @0x1b2bd8 mov r7, r0
 *   @0x1b2bdc ldrb r8, [sp, #0x4c]
 *   @0x1b2be0 ldrb r6, [sp, #0x54]
 *   @0x1b2be4 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x1b2be8 ldr r0, [pc, #0x200]
 *   @0x1b2bec add r4, pc, r4
 *   @0x1b2bf0 ldr r5, [r4, r0]
 *   @0x1b2bf4 ldr r0, [r5]
 *   @0x1b2bf8 bl 0x17155c <_Z22GR_Surface_Get_Texturei>
 *   @0x1b2bfc bl 0x17435c <_Z22GR_Texture_Get_Surfacei>
 *   @0x1b2c00 cmp r0, #0
 *   @0x1b2c04 beq 0x1b2d0c <_Z28RenderSurface_AspectAdjustediiiiibbb+0x154>
 *   @0x1b2c08 mov r0, r7
 *   @0x1b2c0c bl 0x1714d4 <_Z20GR_Surface_Get_Widthi>
 *   @0x1b2c10 mov r11, r0
 *   @0x1b2c14 mov r0, r7
 *   @0x1b2c18 bl 0x171518 <_Z21GR_Surface_Get_Heighti>
 *   @0x1b2c1c cmp r6, #0
 *   @0x1b2c20 mov r7, r0
 *   @0x1b2c24 bne 0x1b2d64 <_Z28RenderSurface_AspectAdjustediiiiibbb+0x1ac>
 *   @0x1b2c28 cmp r8, #0
 *   @0x1b2c2c bne 0x1b2d18 <_Z28RenderSurface_AspectAdjustediiiiibbb+0x160>
 *   @0x1b2c30 vcvt.f32.s32 s17, s17
 *   @0x1b2c34 vldr s15, [pc, #428]
 *   @0x1b2c38 vcvt.f32.s32 s14, s18
 *   @0x1b2c3c vmov.f32 s16, s15
 *   @0x1b2c40 vmov s12, r10
 *   @0x1b2c44 ldr r0, [r5]
 *   @0x1b2c48 mvn r3, #-16777216
 *   @0x1b2c4c str r3, [sp, #0x4]
 *   @0x1b2c50 vsub.f32 s14, s14, s15
 *   @0x1b2c54 mov r3, #1065353216
 *   @0x1b2c58 str r3, [sp, #0x8]
 *   @0x1b2c5c vcvt.f32.s32 s13, s12
 *   @0x1b2c60 vstr s14, [sp]
 *   @0x1b2c64 vmov s12, r9
 *   @0x1b2c68 vcvt.f32.s32 s14, s12
 *   @0x1b2c6c vadd.f32 s14, s14, s15
 *   @0x1b2c70 vadd.f32 s13, s13, s16
 *   @0x1b2c74 vmov r2, s14
 *   @0x1b2c78 vsub.f32 s14, s17, s16
 *   @0x1b2c7c vmov r1, s13
 *   @0x1b2c80 vmov r3, s14
 *   @0x1b2c84 bl 0x171e2c <_Z24GR_Surface_DrawStretchediffffjf>
 *   @0x1b2c88 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x1b2c8c cmp r6, #0
 *   @0x1b2c90 beq 0x1b2d0c <_Z28RenderSurface_AspectAdjustediiiiibbb+0x154>
 *   @0x1b2c94 vcvt.s32.f32 s16, s16
 *   @0x1b2c98 ldr r2, [pc, #0x154]
 *   @0x1b2c9c ldr r8, [pc, #0x154]
 *   @0x1b2ca0 mov r3, #0
 *   @0x1b2ca4 ldr r6, [pc, #0x150]
 *   @0x1b2ca8 ldr r9, [r4, r2]
 *   @0x1b2cac ldr r5, [pc, #0x14c]
 *   @0x1b2cb0 ldr r7, [pc, #0x14c]
 *   @0x1b2cb4 ldr r12, [pc, #0x14c]
 *   @0x1b2cb8 vcvt.s32.f32 s17, s17
 *   @0x1b2cbc vstr s16, [r9]
 *   @0x1b2cc0 ldr r8, [r4, r8]
 *   @0x1b2cc4 ldr r0, [pc, #0x140]
 *   @0x1b2cc8 ldr r1, [pc, #0x140]
 *   @0x1b2ccc str r3, [r8]
 *   @0x1b2cd0 ldr r7, [r4, r7]
 *   @0x1b2cd4 vstr s16, [r7]
 *   @0x1b2cd8 ldr r2, [r4, r6]
 *   @0x1b2cdc vstr s17, [r2]
 *   @0x1b2ce0 ldr r2, [r4, r5]
 *   @0x1b2ce4 str r3, [r2]
 *   @0x1b2ce8 ldr r2, [r4, r12]
 *   @0x1b2cec ldr r3, [r4, r0]
 *   @0x1b2cf0 ldr r2, [r2]
 *   @0x1b2cf4 str r2, [r3]
 *   @0x1b2cf8 ldr r0, [r4, r1]
 *   @0x1b2cfc add sp, sp, #20
 *   @0x1b2d00 vpop {d8, d9}
 *   @0x1b2d04 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1b2d08 b 0x168294 <_ZN18RenderStateManager5ForceEv>
 *   @0x1b2d0c add sp, sp, #20
 *   @0x1b2d10 vpop {d8, d9}
 *   @0x1b2d14 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1b2d18 vmov s12, r11
 *   @0x1b2d1c vmov s14, r7
 *   @0x1b2d20 vcvt.f32.s32 s15, s12
 *   @0x1b2d24 vcvt.f32.s32 s13, s14
 *   @0x1b2d28 vdiv.f32 s12, s15, s13
 *   @0x1b2d2c vcvt.f32.s32 s17, s17
 *   @0x1b2d30 vdiv.f32 s11, s17, s12
 *   @0x1b2d34 vcvt.f32.s32 s14, s18
 *   @0x1b2d38 vcmpe.f32 s11, s14
 *   @0x1b2d3c vmrs APSR_nzcv, fpscr
 *   @0x1b2d40 bmi 0x1b2dbc <_Z28RenderSurface_AspectAdjustediiiiibbb+0x204>
 *   @0x1b2d44 ble 0x1b2ddc <_Z28RenderSurface_AspectAdjustediiiiibbb+0x224>
 *   @0x1b2d48 vmul.f32 s12, s12, s14
 *   @0x1b2d4c vldr s15, [pc, #148]
 *   @0x1b2d50 vsub.f32 s16, s17, s12
 *   @0x1b2d54 vmov.f32 s13, #5.000000e-01
 *   @0x1b2d58 vmul.f32 s16, s16, s13
 *   @0x1b2d5c vadd.f32 s17, s16, s12
 *   @0x1b2d60 b 0x1b2c40 <_Z28RenderSurface_AspectAdjustediiiiibbb+0x88>
 *   @0x1b2d64 mov r0, #8
 *   @0x1b2d68 mov r1, #0
 *   @0x1b2d6c bl 0x17fd24 <_ZN8Graphics14SetRenderStateE12eRenderStatej>
 *   @0x1b2d70 mov r0, #1
 *   @0x1b2d74 mov r1, #0
 *   @0x1b2d78 bl 0x17fd24 <_ZN8Graphics14SetRenderStateE12eRenderStatej>
 *   @0x1b2d7c mov r0, #21
 *   @0x1b2d80 mov r1, #0
 *   @0x1b2d84 bl 0x17fd24 <_ZN8Graphics14SetRenderStateE12eRenderStatej>
 *   @0x1b2d88 mov r0, #13
 *   @0x1b2d8c mov r1, #0
 *   @0x1b2d90 bl 0x17fd24 <_ZN8Graphics14SetRenderStateE12eRenderStatej>
 *   @0x1b2d94 mov r0, #12
 *   @0x1b2d98 mov r1, #0
 *   @0x1b2d9c bl 0x17fd24 <_ZN8Graphics14SetRenderStateE12eRenderStatej>
 *   @0x1b2da0 mov r0, #5
 *   @0x1b2da4 mov r1, #0
 *   @0x1b2da8 bl 0x17fd24 <_ZN8Graphics14SetRenderStateE12eRenderStatej>
 *   @0x1b2dac mov r0, #25
 *   @0x1b2db0 mov r1, #0
 *   @0x1b2db4 bl 0x17fd24 <_ZN8Graphics14SetRenderStateE12eRenderStatej>
 *   @0x1b2db8 b 0x1b2c28 <_Z28RenderSurface_AspectAdjustediiiiibbb+0x70>
 *   @0x1b2dbc vdiv.f32 s13, s13, s15
 *   @0x1b2dc0 vldr s16, [pc, #32]
 *   @0x1b2dc4 vmul.f32 s13, s17, s13
 *   @0x1b2dc8 vmov.f32 s12, #5.000000e-01
 *   @0x1b2dcc vsub.f32 s15, s14, s13
 *   @0x1b2dd0 vmul.f32 s15, s15, s12
 *   @0x1b2dd4 vadd.f32 s14, s15, s13
 *   @0x1b2dd8 b 0x1b2c40 <_Z28RenderSurface_AspectAdjustediiiiibbb+0x88>
 *   @0x1b2ddc vldr s15, [pc, #4]
 *   @0x1b2de0 vmov.f32 s16, s15
 *   @0x1b2de4 b 0x1b2c40 <_Z28RenderSurface_AspectAdjustediiiiibbb+0x88>
 *   @0x1b2de8 andeq r0, r0, r0
 *   @0x1b2dec eoreq pc, r3, r4, rrx
 *   @0x1b2df0 .word 0xffffc988
 *   @0x1b2df4 .word 0xffffeb94
 *   @0x1b2df8 .word 0xffffeb98
 *   @0x1b2dfc .word 0xffffebd0
 *   @0x1b2e00 .word 0xffffebd4
 *   @0x1b2e04 .word 0xffffebd8
 *   @0x1b2e08 .word 0xffffe250
 *   @0x1b2e0c .word 0xffffebdc
 *   @0x1b2e10 .word 0xffffc0a8
 *
 * ══ §10/54 ParticleSystem_Emitter_Burst  0x1a3cf0  size 600  150 条（0x1a3cf0..0x1a3f48）
 * @func 0x1a3cf0 0x1a3f48  size 600  150 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MyRandom(float, float, int)×4 / ParticleSystem_Particles_Create(int, float, float, int, int)×2 / ParticleSystem_Emitter_Exists(int, int) / ParticleSystem_Emitter_Burst(int, int, int, int)+0x238 / ParticleSystem_Emitter_Burst(int, int, int, int)+0x210 / fYYRandom(double) / MemoryManager::SetLength(void**, unsigned int, char const*, int) / YYRandom(int)
 * 字段偏移 top8: 0x18×3 / 0x2×2 / 0x8×2 / 0x1c×2 / 0x220×1 / 0x4×1 / 0x10×1 / 0x3c×1
 * VFP 指令 46 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a3cf0 push {r4, r5, r6, r7, r8, lr}
 *   @0x1a3cf4 vpush {d8, d9, d10}
 *   @0x1a3cf8 sub sp, sp, #8
 *   @0x1a3cfc mov r8, r2
 *   @0x1a3d00 mov r6, r3
 *   @0x1a3d04 mov r7, r0
 *   @0x1a3d08 mov r5, r1
 *   @0x1a3d0c bl 0x1a3854 <_Z29ParticleSystem_Emitter_Existsii>
 *   @0x1a3d10 cmp r0, #0
 *   @0x1a3d14 beq 0x1a3df8 <_Z28ParticleSystem_Emitter_Burstiiii+0x108>
 *   @0x1a3d18 ldr r3, [pc, #0x220]
 *   @0x1a3d1c cmp r6, #0
 *   @0x1a3d20 ldr r3, [pc, r3]
 *   @0x1a3d24 ldr r3, [r3, #0x4]
 *   @0x1a3d28 ldr r4, [r3, r7, lsl #2]
 *   @0x1a3d2c blt 0x1a3f28 <_Z28ParticleSystem_Emitter_Burstiiii+0x238>
 *   @0x1a3d30 ldr r1, [r4, #0x8]
 *   @0x1a3d34 ldr r3, [r4]
 *   @0x1a3d38 add r1, r6, r1
 *   @0x1a3d3c cmp r3, r1
 *   @0x1a3d40 ble 0x1a3f00 <_Z28ParticleSystem_Emitter_Burstiiii+0x210>
 *   @0x1a3d44 ldr r3, [r4, #0x10]
 *   @0x1a3d48 cmp r6, #0
 *   @0x1a3d4c ldr r4, [r3, r5, lsl #2]
 *   @0x1a3d50 beq 0x1a3df8 <_Z28ParticleSystem_Emitter_Burstiiii+0x108>
 *   @0x1a3d54 vmov.f64 d8, #5.000000e-01
 *   @0x1a3d58 mov r5, #0
 *   @0x1a3d5c vmov.f32 s20, #5.000000e-01
 *   @0x1a3d60 mov r1, #1065353216
 *   @0x1a3d64 ldr r2, [r4, #0x18]
 *   @0x1a3d68 mov r0, #0
 *   @0x1a3d6c bl 0x1a27ac <_Z8MyRandomffi>
 *   @0x1a3d70 mov r1, #1065353216
 *   @0x1a3d74 ldr r2, [r4, #0x18]
 *   @0x1a3d78 vmov s18, r0
 *   @0x1a3d7c mov r0, #0
 *   @0x1a3d80 bl 0x1a27ac <_Z8MyRandomffi>
 *   @0x1a3d84 ldr r1, [r4, #0x18]
 *   @0x1a3d88 cmp r1, #2
 *   @0x1a3d8c vmov s19, r0
 *   @0x1a3d90 beq 0x1a3e5c <_Z28ParticleSystem_Emitter_Burstiiii+0x16c>
 *   @0x1a3d94 ldr r1, [r4, #0x1c]
 *   @0x1a3d98 cmp r1, #1
 *   @0x1a3d9c beq 0x1a3e04 <_Z28ParticleSystem_Emitter_Burstiiii+0x114>
 *   @0x1a3da0 cmp r1, #2
 *   @0x1a3da4 beq 0x1a3e34 <_Z28ParticleSystem_Emitter_Burstiiii+0x144>
 *   @0x1a3da8 cmp r1, #3
 *   @0x1a3dac beq 0x1a3e68 <_Z28ParticleSystem_Emitter_Burstiiii+0x178>
 *   @0x1a3db0 vldr s14, [r4, #8]
 *   @0x1a3db4 vldr s15, [r4, #16]
 *   @0x1a3db8 vldr s12, [r4, #12]
 *   @0x1a3dbc vldr s13, [r4, #20]
 *   @0x1a3dc0 vsub.f32 s12, s12, s14
 *   @0x1a3dc4 mov r3, #1
 *   @0x1a3dc8 mov r0, r7
 *   @0x1a3dcc str r3, [sp]
 *   @0x1a3dd0 add r5, r5, #1
 *   @0x1a3dd4 mov r3, r8
 *   @0x1a3dd8 vsub.f32 s13, s13, s15
 *   @0x1a3ddc vmla.f32 s14, s12, s18
 *   @0x1a3de0 vmla.f32 s15, s13, s19
 *   @0x1a3de4 vmov r1, s14
 *   @0x1a3de8 vmov r2, s15
 *   @0x1a3dec bl 0x1a3b78 <_Z31ParticleSystem_Particles_Createiffii>
 *   @0x1a3df0 cmp r5, r6
 *   @0x1a3df4 bne 0x1a3d60 <_Z28ParticleSystem_Emitter_Burstiiii+0x70>
 *   @0x1a3df8 add sp, sp, #8
 *   @0x1a3dfc vpop {d8, d9, d10}
 *   @0x1a3e00 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1a3e04 vsub.f32 s15, s19, s20
 *   @0x1a3e08 vmul.f32 s15, s15, s15
 *   @0x1a3e0c vsub.f32 s14, s18, s20
 *   @0x1a3e10 vmla.f32 s15, s14, s14
 *   @0x1a3e14 vmov.f32 s14, #2.500000e-01
 *   @0x1a3e18 vcmpe.f32 s15, s14
 *   @0x1a3e1c vmrs APSR_nzcv, fpscr
 *   @0x1a3e20 movhi r12, #0
 *   @0x1a3e24 movls r12, #1
 *   @0x1a3e28 cmp r12, #0
 *   @0x1a3e2c beq 0x1a3d60 <_Z28ParticleSystem_Emitter_Burstiiii+0x70>
 *   @0x1a3e30 b 0x1a3da8 <_Z28ParticleSystem_Emitter_Burstiiii+0xb8>
 *   @0x1a3e34 vsub.f32 s14, s18, s20
 *   @0x1a3e38 vsub.f32 s15, s19, s20
 *   @0x1a3e3c vabs.f32 s14, s14
 *   @0x1a3e40 vabs.f32 s15, s15
 *   @0x1a3e44 vadd.f32 s15, s14, s15
 *   @0x1a3e48 vcmpe.f32 s15, s20
 *   @0x1a3e4c vmrs APSR_nzcv, fpscr
 *   @0x1a3e50 movhi r12, #0
 *   @0x1a3e54 movls r12, #1
 *   @0x1a3e58 b 0x1a3e28 <_Z28ParticleSystem_Emitter_Burstiiii+0x138>
 *   @0x1a3e5c ldr r1, [r4, #0x1c]
 *   @0x1a3e60 cmp r1, #3
 *   @0x1a3e64 bne 0x1a3ebc <_Z28ParticleSystem_Emitter_Burstiiii+0x1cc>
 *   @0x1a3e68 vldr s14, [r4, #8]
 *   @0x1a3e6c vldr s15, [r4, #16]
 *   @0x1a3e70 vldr s12, [r4, #12]
 *   @0x1a3e74 vldr s13, [r4, #20]
 *   @0x1a3e78 vsub.f32 s12, s12, s14
 *   @0x1a3e7c mov r3, #1
 *   @0x1a3e80 mov r0, r7
 *   @0x1a3e84 str r3, [sp]
 *   @0x1a3e88 add r5, r5, #1
 *   @0x1a3e8c mov r3, r8
 *   @0x1a3e90 vsub.f32 s13, s13, s15
 *   @0x1a3e94 vmla.f32 s14, s12, s18
 *   @0x1a3e98 vmla.f32 s15, s13, s18
 *   @0x1a3e9c vmov r1, s14
 *   @0x1a3ea0 vmov r2, s15
 *   @0x1a3ea4 bl 0x1a3b78 <_Z31ParticleSystem_Particles_Createiffii>
 *   @0x1a3ea8 cmp r5, r6
 *   @0x1a3eac bne 0x1a3d60 <_Z28ParticleSystem_Emitter_Burstiiii+0x70>
 *   @0x1a3eb0 add sp, sp, #8
 *   @0x1a3eb4 vpop {d8, d9, d10}
 *   @0x1a3eb8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1a3ebc mov r0, #0
 *   @0x1a3ec0 mov r1, #0
 *   @0x1a3ec4 movt r1, #0x3ff0
 *   @0x1a3ec8 bl 0xc4598 <_Z9fYYRandomd>
 *   @0x1a3ecc mov r2, #0
 *   @0x1a3ed0 vmov d7, r0, r1
 *   @0x1a3ed4 mov r0, #0
 *   @0x1a3ed8 mov r1, #1065353216
 *   @0x1a3edc vcmpe.f64 d7, d8
 *   @0x1a3ee0 vmrs APSR_nzcv, fpscr
 *   @0x1a3ee4 bpl 0x1a3ef4 <_Z28ParticleSystem_Emitter_Burstiiii+0x204>
 *   @0x1a3ee8 bl 0x1a27ac <_Z8MyRandomffi>
 *   @0x1a3eec vmov s18, r0
 *   @0x1a3ef0 b 0x1a3d94 <_Z28ParticleSystem_Emitter_Burstiiii+0xa4>
 *   @0x1a3ef4 bl 0x1a27ac <_Z8MyRandomffi>
 *   @0x1a3ef8 vmov s19, r0
 *   @0x1a3efc b 0x1a3d94 <_Z28ParticleSystem_Emitter_Burstiiii+0xa4>
 *   @0x1a3f00 ldr r2, [pc, #0x3c]
 *   @0x1a3f04 movw r3, #0x4fb
 *   @0x1a3f08 lsl r1, r1, #2
 *   @0x1a3f0c add r0, r4, #4
 *   @0x1a3f10 add r2, pc, r2
 *   @0x1a3f14 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1a3f18 ldr r3, [r4, #0x8]
 *   @0x1a3f1c add r3, r3, r6
 *   @0x1a3f20 str r3, [r4]
 *   @0x1a3f24 b 0x1a3d44 <_Z28ParticleSystem_Emitter_Burstiiii+0x54>
 *   @0x1a3f28 rsb r0, r6, #0
 *   @0x1a3f2c bl 0xc4600 <_Z8YYRandomi>
 *   @0x1a3f30 cmp r0, #0
 *   @0x1a3f34 bne 0x1a3df8 <_Z28ParticleSystem_Emitter_Burstiiii+0x108>
 *   @0x1a3f38 mov r6, #1
 *   @0x1a3f3c b 0x1a3d30 <_Z28ParticleSystem_Emitter_Burstiiii+0x40>
 *   @0x1a3f40 mlaeq r4, r8, r10, r12
 *   @0x1a3f44 andseq r9, r10, r0, ror r0
 *
 * ══ §11/54 Call_Accessor_Get  0x248fec  size 596  149 条（0x248fec..0x249240）
 * @func 0x248fec 0x249240  size 596  149 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x249074→0x544b50, 0x2490d0→0x757e7c, 0x249198→0x757e80, 0x2491a8→0x757e80
 * 调用序列: PushContextStack(YYObjectBase*)×3 / PopContextStack()×3 / CScript::GetCode()×2 / YYObjectBase::InternalGetYYVar(int)×2 / YYAllocLocalStackNew(int) / VM::Exec(CCode*, YYObjectBase*, YYObjectBase*, RValue*, YYObjectBase*, int, RValue*, int, YYObjectBase*) / YYObjectBase::Free(YYObjectBase*) / CreateArgumentsObject(RValue&, YYObjectBase*, int, RValue*, bool)
 * 字段偏移 top8: 0xc×4 / 0x4×3 / 0x78×3 / 0x8×3 / 0x1c×2 / 0x22c×1 / 0x48×1 / 0x64×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x248fec ldr r12, [r2, #0xc]
 *   @0x248ff0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x248ff4 bic r12, r12, #-16777216
 *   @0x248ff8 ldr r6, [pc, #0x22c]
 *   @0x248ffc cmp r12, #6
 *   @0x249000 sub sp, sp, #52
 *   @0x249004 mov r7, r0
 *   @0x249008 add r6, pc, r6
 *   @0x24900c mov r8, r1
 *   @0x249010 beq 0x24901c <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x30>
 *   @0x249014 add sp, sp, #52
 *   @0x249018 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x24901c ldr r4, [r2]
 *   @0x249020 ldr r3, [r4, #0x48]
 *   @0x249024 cmp r3, #2
 *   @0x249028 bne 0x249014 <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x28>
 *   @0x24902c ldr r1, [r4, #0x4]
 *   @0x249030 cmp r1, #0
 *   @0x249034 beq 0x2491c4 <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x1d8>
 *   @0x249038 ldr r2, [r1, #0xc]
 *   @0x24903c mvn r3, #-16777216
 *   @0x249040 cmp r2, r3
 *   @0x249044 moveq r3, #5
 *   @0x249048 streq r3, [r8, #0xc]
 *   @0x24904c beq 0x249014 <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x28>
 *   @0x249050 ldr r1, [r4, #0x4]
 *   @0x249054 cmp r1, #0
 *   @0x249058 beq 0x2491d4 <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x1e8>
 *   @0x24905c ldr r10, [r1]
 *   @0x249060 cmp r10, #0
 *   @0x249064 beq 0x249014 <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x28>
 *   @0x249068 ldr r9, [r10, #0x64]
 *   @0x24906c cmp r9, #0
 *   @0x249070 beq 0x24914c <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x160>
 *   @0x249074 ldr r3, [pc, #0x1b4]
 *   @0x249078 mov r4, #0
 *   @0x24907c mov r5, #0
 *   @0x249080 ldr r3, [r6, r3]
 *   @0x249084 ldr r0, [r3]
 *   @0x249088 bl 0xd41e4 <_Z20YYAllocLocalStackNewi>
 *   @0x24908c ldr r3, [r10, #0x78]
 *   @0x249090 mvn r2, #-16777216
 *   @0x249094 strd r4, r5, [sp, #32]
 *   @0x249098 cmp r3, #6
 *   @0x24909c ldreq r3, [r10, #0x6c]
 *   @0x2490a0 mov r11, r0
 *   @0x2490a4 streq r3, [r0, #0xc]
 *   @0x2490a8 mov r0, r9
 *   @0x2490ac mov r3, #0
 *   @0x2490b0 str r2, [sp, #0x2c]
 *   @0x2490b4 str r3, [sp, #0x28]
 *   @0x2490b8 str r3, [sp, #0x1c]
 *   @0x2490bc bl 0x1dfba8 <_ZN7CScript7GetCodeEv>
 *   @0x2490c0 ldr r3, [sp, #0x1c]
 *   @0x2490c4 ldr r2, [r0, #0x78]
 *   @0x2490c8 tst r2, #1
 *   @0x2490cc bne 0x249180 <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x194>
 *   @0x2490d0 ldr r3, [pc, #0x15c]
 *   @0x2490d4 ldr r4, [r6, r3]
 *   @0x2490d8 ldrb r3, [r4]
 *   @0x2490dc cmp r3, #0
 *   @0x2490e0 bne 0x2491a8 <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x1bc>
 *   @0x2490e4 mov r0, r7
 *   @0x2490e8 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase>
 *   @0x2490ec ldr r12, [sp, #0x20]
 *   @0x2490f0 ldr r0, [r9, #0x8]
 *   @0x2490f4 mov r3, r8
 *   @0x2490f8 mov r1, r7
 *   @0x2490fc mov r2, r7
 *   @0x249100 str r12, [sp, #0x10]
 *   @0x249104 mov r12, #0
 *   @0x249108 str r11, [sp]
 *   @0x24910c str r12, [sp, #0x4]
 *   @0x249110 str r12, [sp, #0x8]
 *   @0x249114 str r12, [sp, #0xc]
 *   @0x249118 bl 0xe7fd0 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_>
 *   @0x24911c bl 0xd3a34 <_Z15PopContextStackv>
 *   @0x249120 ldrb r3, [r4]
 *   @0x249124 cmp r3, #0
 *   @0x249128 bne 0x249198 <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x1ac>
 *   @0x24912c mov r0, r9
 *   @0x249130 bl 0x1dfba8 <_ZN7CScript7GetCodeEv>
 *   @0x249134 ldr r3, [r0, #0x78]
 *   @0x249138 tst r3, #2
 *   @0x24913c bne 0x249014 <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x28>
 *   @0x249140 mov r0, r11
 *   @0x249144 bl 0x198f88 <_ZN12YYObjectBase4FreeEPS_>
 *   @0x249148 b 0x249014 <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x28>
 *   @0x24914c ldr r4, [r10, #0x68]
 *   @0x249150 cmp r4, #0
 *   @0x249154 beq 0x2491e4 <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x1f8>
 *   @0x249158 mov r0, r7
 *   @0x24915c bl 0xd3968 <_Z16PushContextStackP12YYObjectBase>
 *   @0x249160 mov r1, r7
 *   @0x249164 mov r0, r8
 *   @0x249168 mov r3, r9
 *   @0x24916c mov r2, r7
 *   @0x249170 str r9, [sp]
 *   @0x249174 blx r4
 *   @0x249178 bl 0xd3a34 <_Z15PopContextStackv>
 *   @0x24917c b 0x249014 <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x28>
 *   @0x249180 mov r2, r3
 *   @0x249184 str r3, [sp]
 *   @0x249188 mov r1, r10
 *   @0x24918c add r0, sp, #32
 *   @0x249190 bl 0x248b58 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b>
 *   @0x249194 b 0x2490d0 <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0xe4>
 *   @0x249198 ldr r3, [pc, #0x98]
 *   @0x24919c ldr r0, [r6, r3]
 *   @0x2491a0 bl 0x2a08ac <_ZN9CProfiler3PopEv>
 *   @0x2491a4 b 0x24912c <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x140>
 *   @0x2491a8 ldr r2, [pc, #0x88]
 *   @0x2491ac mov r1, #1
 *   @0x2491b0 ldr r3, [r9, #0x8]
 *   @0x2491b4 ldr r0, [r6, r2]
 *   @0x2491b8 ldr r2, [r3, #0x60]
 *   @0x2491bc bl 0x2a0738 <_ZN9CProfiler4PushEii>
 *   @0x2491c0 b 0x2490e4 <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0xf8>
 *   @0x2491c4 mov r0, r4
 *   @0x2491c8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x2491cc mov r1, r0
 *   @0x2491d0 b 0x249038 <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x4c>
 *   @0x2491d4 mov r0, r4
 *   @0x2491d8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x2491dc mov r1, r0
 *   @0x2491e0 b 0x24905c <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x70>
 *   @0x2491e4 ldr r1, [pc, #0x50]
 *   @0x2491e8 mov r0, r10
 *   @0x2491ec add r1, pc, r1
 *   @0x2491f0 bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc>
 *   @0x2491f4 subs r3, r0, #0
 *   @0x2491f8 beq 0x249014 <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x28>
 *   @0x2491fc ldr r2, [r3, #0xc]
 *   @0x249200 cmp r2, #3
 *   @0x249204 bne 0x249014 <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x28>
 *   @0x249208 mov r0, r7
 *   @0x24920c ldr r5, [r3]
 *   @0x249210 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase>
 *   @0x249214 mov r1, r4
 *   @0x249218 mov r2, r8
 *   @0x24921c mov r0, r7
 *   @0x249220 blx r5
 *   @0x249224 bl 0xd3a34 <_Z15PopContextStackv>
 *   @0x249228 b 0x249014 <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_+0x28>
 *   @0x24922c andseq r8, r10, r8, asr #24
 *   @0x249230 .word 0xffffc104
 *   @0x249234 .word 0xffffbf18
 *   @0x249238 .word 0xffffbf1c
 *   @0x24923c andseq r12, r0, r12, lsr #4
 *
 * ══ §12/54 HandleMotion  0x1a4ba4  size 592  148 条（0x1a4ba4..0x1a4df4）
 * @func 0x1a4ba4 0x1a4df4  size 592  148 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Direction_To_Vector(float, float, float*, float*)×3 / HandleMotion(int)+0x238×2 / Vector_To_Direction(float, float, float*, float*)
 * 字段偏移 top8: 0x4×6 / 0x2×3 / 0x8×3 / 0x240×1 / 0x208×1 / 0x3c×1 / 0x10×1 / 0x14×1
 * VFP 指令 76 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a4ba4 ldr r3, [pc, #0x240]
 *   @0x1a4ba8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1a4bac vpush {d8, d9}
 *   @0x1a4bb0 ldr r3, [pc, r3]
 *   @0x1a4bb4 vldr s16, [pc, #556]
 *   @0x1a4bb8 sub sp, sp, #28
 *   @0x1a4bbc vstr s16, [sp, #8]
 *   @0x1a4bc0 ldr r3, [r3, #0x4]
 *   @0x1a4bc4 vstr s16, [sp, #12]
 *   @0x1a4bc8 vstr s16, [sp, #16]
 *   @0x1a4bcc vstr s16, [sp, #20]
 *   @0x1a4bd0 ldr r7, [r3, r0, lsl #2]
 *   @0x1a4bd4 ldr r3, [r7, #0x8]
 *   @0x1a4bd8 cmp r3, #0
 *   @0x1a4bdc ble 0x1a4ddc <_Z12HandleMotioni+0x238>
 *   @0x1a4be0 ldr r10, [pc, #0x208]
 *   @0x1a4be4 movw r11, #0xaaab
 *   @0x1a4be8 movw r1, #0x6667
 *   @0x1a4bec vmov.f32 s19, #6.000000e+00
 *   @0x1a4bf0 movt r1, #0x6666
 *   @0x1a4bf4 ldr r10, [pc, r10]
 *   @0x1a4bf8 movt r11, #0x2aaa
 *   @0x1a4bfc str r1, [sp, #0x4]
 *   @0x1a4c00 mov r6, #0
 *   @0x1a4c04 vmov.f32 s18, #2.000000e+00
 *   @0x1a4c08 vmov.f32 s17, #1.000000e+00
 *   @0x1a4c0c b 0x1a4cf0 <_Z12HandleMotioni+0x14c>
 *   @0x1a4c10 ldr r2, [r4, #0x3c]
 *   @0x1a4c14 vmov.f32 s11, #5.000000e+00
 *   @0x1a4c18 ldr r3, [r4, #0x8]
 *   @0x1a4c1c add r1, r2, r2, lsl #1
 *   @0x1a4c20 add r3, r1, r3
 *   @0x1a4c24 smull r1, r0, r11, r3
 *   @0x1a4c28 asr r1, r3, #31
 *   @0x1a4c2c rsb r1, r1, r0, asr #2
 *   @0x1a4c30 add r1, r1, r1, lsl #1
 *   @0x1a4c34 sub r1, r3, r1, lsl #3
 *   @0x1a4c38 add r3, r3, r2
 *   @0x1a4c3c ldr r2, [sp, #0x4]
 *   @0x1a4c40 vmov s10, r1
 *   @0x1a4c44 vcvt.f32.s32 s13, s10
 *   @0x1a4c48 smull r2, r1, r2, r3
 *   @0x1a4c4c asr r2, r3, #31
 *   @0x1a4c50 vdiv.f32 s13, s13, s19
 *   @0x1a4c54 rsb r2, r2, r1, asr #3
 *   @0x1a4c58 add r2, r2, r2, lsl #2
 *   @0x1a4c5c sub r3, r3, r2, lsl #2
 *   @0x1a4c60 mov r2, r9
 *   @0x1a4c64 vmov s10, r3
 *   @0x1a4c68 mov r3, r8
 *   @0x1a4c6c vcmpe.f32 s13, s18
 *   @0x1a4c70 vmrs APSR_nzcv, fpscr
 *   @0x1a4c74 vmovgt.f32 s14, #4.000000e+00
 *   @0x1a4c78 vsubgt.f32 s13, s14, s13
 *   @0x1a4c7c vcvt.f32.s32 s14, s10
 *   @0x1a4c80 vldr s10, [r5, #88]
 *   @0x1a4c84 vdiv.f32 s14, s14, s11
 *   @0x1a4c88 vcmpe.f32 s14, s18
 *   @0x1a4c8c vmrs APSR_nzcv, fpscr
 *   @0x1a4c90 vmovgt.f32 s11, #4.000000e+00
 *   @0x1a4c94 vsubgt.f32 s14, s11, s14
 *   @0x1a4c98 vldr s11, [r5, #72]
 *   @0x1a4c9c vsub.f32 s13, s13, s17
 *   @0x1a4ca0 vsub.f32 s14, s14, s17
 *   @0x1a4ca4 vmla.f32 s12, s13, s10
 *   @0x1a4ca8 vmla.f32 s15, s14, s11
 *   @0x1a4cac vmov r0, s12
 *   @0x1a4cb0 vmov r1, s15
 *   @0x1a4cb4 bl 0x1a2a38 <_Z19Direction_To_VectorffPfS_>
 *   @0x1a4cb8 vldr s12, [r4, #16]
 *   @0x1a4cbc vldr s13, [r4, #20]
 *   @0x1a4cc0 vldr s14, [sp, #8]
 *   @0x1a4cc4 vldr s15, [sp, #12]
 *   @0x1a4cc8 vadd.f32 s14, s12, s14
 *   @0x1a4ccc ldr r3, [r7, #0x8]
 *   @0x1a4cd0 vadd.f32 s15, s13, s15
 *   @0x1a4cd4 vadd.f32 s14, s14, s16
 *   @0x1a4cd8 vadd.f32 s15, s15, s16
 *   @0x1a4cdc vstr s14, [r4, #16]
 *   @0x1a4ce0 vstr s15, [r4, #20]
 *   @0x1a4ce4 add r6, r6, #1
 *   @0x1a4ce8 cmp r3, r6
 *   @0x1a4cec ble 0x1a4ddc <_Z12HandleMotioni+0x238>
 *   @0x1a4cf0 ldr r1, [r7, #0x4]
 *   @0x1a4cf4 ldr r2, [r10, #0x4]
 *   @0x1a4cf8 ldr r4, [r1, r6, lsl #2]
 *   @0x1a4cfc ldr r1, [r4, #0x4]
 *   @0x1a4d00 ldr r5, [r2, r1, lsl #2]
 *   @0x1a4d04 cmp r5, #0
 *   @0x1a4d08 beq 0x1a4ce4 <_Z12HandleMotioni+0x140>
 *   @0x1a4d0c vldr s15, [r5, #68]
 *   @0x1a4d10 vldr s14, [r4, #32]
 *   @0x1a4d14 vadd.f32 s15, s14, s15
 *   @0x1a4d18 vldr s12, [r4, #36]
 *   @0x1a4d1c vldr s14, [r5, #84]
 *   @0x1a4d20 vldr s11, [r4, #40]
 *   @0x1a4d24 vldr s13, [r5, #92]
 *   @0x1a4d28 ldr r2, [r4, #0x10]
 *   @0x1a4d2c ldr r3, [r4, #0x14]
 *   @0x1a4d30 add r9, sp, #8
 *   @0x1a4d34 add r8, sp, #12
 *   @0x1a4d38 str r2, [r4, #0x18]
 *   @0x1a4d3c str r3, [r4, #0x1c]
 *   @0x1a4d40 vadd.f32 s12, s12, s14
 *   @0x1a4d44 vldr s14, [r5, #108]
 *   @0x1a4d48 vadd.f32 s14, s11, s14
 *   @0x1a4d4c vstr s12, [r4, #36]
 *   @0x1a4d50 vcmpe.f32 s15, #0
 *   @0x1a4d54 vstr s14, [r4, #40]
 *   @0x1a4d58 vmrs APSR_nzcv, fpscr
 *   @0x1a4d5c vcmp.f32 s13, #0
 *   @0x1a4d60 vstrpl s15, [r4, #32]
 *   @0x1a4d64 vstrmi s16, [r4, #32]
 *   @0x1a4d68 vldrmi s15, [pc, #120]
 *   @0x1a4d6c vmrs APSR_nzcv, fpscr
 *   @0x1a4d70 beq 0x1a4c10 <_Z12HandleMotioni+0x6c>
 *   @0x1a4d74 vmov r0, s12
 *   @0x1a4d78 mov r2, r9
 *   @0x1a4d7c vmov r1, s15
 *   @0x1a4d80 mov r3, r8
 *   @0x1a4d84 bl 0x1a2a38 <_Z19Direction_To_VectorffPfS_>
 *   @0x1a4d88 ldr r0, [r5, #0x60]
 *   @0x1a4d8c ldr r1, [r5, #0x5c]
 *   @0x1a4d90 add r2, sp, #16
 *   @0x1a4d94 add r3, sp, #20
 *   @0x1a4d98 bl 0x1a2a38 <_Z19Direction_To_VectorffPfS_>
 *   @0x1a4d9c vldr s12, [sp, #8]
 *   @0x1a4da0 vldr s13, [sp, #12]
 *   @0x1a4da4 vldr s14, [sp, #16]
 *   @0x1a4da8 vldr s15, [sp, #20]
 *   @0x1a4dac vadd.f32 s14, s12, s14
 *   @0x1a4db0 add r2, r4, #36
 *   @0x1a4db4 add r3, r4, #32
 *   @0x1a4db8 vadd.f32 s15, s13, s15
 *   @0x1a4dbc vstr s14, [sp, #8]
 *   @0x1a4dc0 vmov r0, s14
 *   @0x1a4dc4 vmov r1, s15
 *   @0x1a4dc8 vstr s15, [sp, #12]
 *   @0x1a4dcc bl 0x1a2920 <_Z19Vector_To_DirectionffPfS_>
 *   @0x1a4dd0 vldr s12, [r4, #36]
 *   @0x1a4dd4 vldr s15, [r4, #32]
 *   @0x1a4dd8 b 0x1a4c10 <_Z12HandleMotioni+0x6c>
 *   @0x1a4ddc add sp, sp, #28
 *   @0x1a4de0 vpop {d8, d9}
 *   @0x1a4de4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1a4de8 andeq r0, r0, r0
 *   @0x1a4dec eoreq r11, r4, r8, lsl #24
 *   @0x1a4df0 .word 0x0024bbb8
 *
 * ══ §13/54 F_JSThrow  0x24e33c  size 592  148 条（0x24e33c..0x24e58c）
 * @func 0x24e33c 0x24e58c  size 592  148 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / GetContextStackTop() / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*) / FREE_RValue__Pre(RValue*) / _RefThing<char const*>::dec()
 * 字段偏移 top8: 0x8×8 / 0x4×8 / 0xc×5 / 0x23c×1 / 0x18×1 / 0x188×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24e33c push {r3, r4, r5, r6, r7, lr}
 *   @0x24e340 ldr r4, [pc, #0x23c]
 *   @0x24e344 ldr r5, [sp, #0x18]
 *   @0x24e348 ldr r4, [pc, r4]
 *   @0x24e34c ldr r2, [r4, #0xc]
 *   @0x24e350 bic r3, r2, #-16777216
 *   @0x24e354 cmp r3, #1
 *   @0x24e358 beq 0x24e41c <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x24e35c cmp r3, #2
 *   @0x24e360 bne 0x24e388 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x24e364 sub r2, r2, #1
 *   @0x24e368 bic r2, r2, #-16777216
 *   @0x24e36c bic r2, r2, #3
 *   @0x24e370 cmp r2, #0
 *   @0x24e374 beq 0x24e4e8 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0x1ac>
 *   @0x24e378 mov r2, #0
 *   @0x24e37c mov r3, #5
 *   @0x24e380 str r2, [r4, #0x8]
 *   @0x24e384 str r3, [r4, #0xc]
 *   @0x24e388 ldr r3, [r5, #0xc]
 *   @0x24e38c mov r1, #0
 *   @0x24e390 ldr r2, [r5, #0x8]
 *   @0x24e394 str r1, [r4]
 *   @0x24e398 str r3, [r4, #0xc]
 *   @0x24e39c ldr r3, [r5, #0xc]
 *   @0x24e3a0 str r2, [r4, #0x8]
 *   @0x24e3a4 bic r3, r3, #-16777216
 *   @0x24e3a8 cmp r3, #14
 *   @0x24e3ac addls pc, pc, r3, lsl #2
 *   @0x24e3b0 b 0x24e3f8 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x24e3b4 b 0x24e410 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x24e3b8 b 0x24e46c <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x24e3bc b 0x24e484 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0x148>
 *   @0x24e3c0 b 0x24e3f0 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x24e3c4 b 0x24e3f8 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x24e3c8 b 0x24e3f8 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x24e3cc b 0x24e448 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0x10c>
 *   @0x24e3d0 b 0x24e3f0 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x24e3d4 b 0x24e3f8 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x24e3d8 b 0x24e3f8 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x24e3dc b 0x24e410 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x24e3e0 b 0x24e3f8 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x24e3e4 b 0x24e3f8 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x24e3e8 b 0x24e410 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x24e3ec b 0x24e3f0 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x24e3f0 ldr r3, [r5]
 *   @0x24e3f4 str r3, [r4]
 *   @0x24e3f8 ldr r3, [pc, #0x188]
 *   @0x24e3fc mov r2, #1
 *   @0x24e400 ldr r3, [pc, r3]
 *   @0x24e404 strb r2, [r3]
 *   @0x24e408 pop {r3, r4, r5, r6, r7, lr}
 *   @0x24e40c b 0x24e0b4 <_Z20UnwindExceptionStackv>
 *   @0x24e410 ldm r5, {r2, r3}
 *   @0x24e414 stm r4, {r2, r3}
 *   @0x24e418 b 0x24e3f8 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x24e41c ldr r6, [r4]
 *   @0x24e420 cmp r6, #0
 *   @0x24e424 beq 0x24e388 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x24e428 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24e42c ldr r7, [r6, #0x4]
 *   @0x24e430 sub r7, r7, #1
 *   @0x24e434 str r7, [r6, #0x4]
 *   @0x24e438 cmp r7, #0
 *   @0x24e43c beq 0x24e4b0 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0x174>
 *   @0x24e440 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x24e444 b 0x24e388 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x24e448 ldr r3, [r5]
 *   @0x24e44c str r3, [r4]
 *   @0x24e450 ldr r3, [r5]
 *   @0x24e454 cmp r3, #0
 *   @0x24e458 beq 0x24e3f8 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x24e45c bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x24e460 ldr r1, [r5]
 *   @0x24e464 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x24e468 b 0x24e3f8 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x24e46c ldr r3, [r5]
 *   @0x24e470 cmp r3, #0
 *   @0x24e474 ldrne r2, [r3, #0x4]
 *   @0x24e478 addne r2, r2, #1
 *   @0x24e47c strne r2, [r3, #0x4]
 *   @0x24e480 b 0x24e3f4 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x24e484 ldr r3, [r5]
 *   @0x24e488 cmp r3, #0
 *   @0x24e48c str r3, [r4]
 *   @0x24e490 beq 0x24e3f8 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x24e494 ldr r1, [r3, #0x8]
 *   @0x24e498 ldr r2, [r3]
 *   @0x24e49c cmp r1, #0
 *   @0x24e4a0 streq r4, [r3, #0x8]
 *   @0x24e4a4 add r2, r2, #1
 *   @0x24e4a8 str r2, [r3]
 *   @0x24e4ac b 0x24e3f8 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x24e4b0 ldr r0, [r6]
 *   @0x24e4b4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24e4b8 str r7, [r6]
 *   @0x24e4bc str r7, [r6, #0x8]
 *   @0x24e4c0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24e4c4 ldr r7, [r6, #0x4]
 *   @0x24e4c8 sub r7, r7, #1
 *   @0x24e4cc str r7, [r6, #0x4]
 *   @0x24e4d0 cmp r7, #0
 *   @0x24e4d4 beq 0x24e4f4 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0x1b8>
 *   @0x24e4d8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x24e4dc mov r0, r6
 *   @0x24e4e0 bl 0x27d1d0 <_ZdlPv>
 *   @0x24e4e4 b 0x24e440 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0x24e4e8 mov r0, r4
 *   @0x24e4ec bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x24e4f0 b 0x24e378 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x24e4f4 ldr r0, [r6]
 *   @0x24e4f8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24e4fc str r7, [r6]
 *   @0x24e500 str r7, [r6, #0x8]
 *   @0x24e504 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24e508 ldr r7, [r6, #0x4]
 *   @0x24e50c sub r7, r7, #1
 *   @0x24e510 str r7, [r6, #0x4]
 *   @0x24e514 cmp r7, #0
 *   @0x24e518 beq 0x24e52c <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0x1f0>
 *   @0x24e51c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x24e520 mov r0, r6
 *   @0x24e524 bl 0x27d1d0 <_ZdlPv>
 *   @0x24e528 b 0x24e4d8 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0x19c>
 *   @0x24e52c ldr r0, [r6]
 *   @0x24e530 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24e534 str r7, [r6]
 *   @0x24e538 str r7, [r6, #0x8]
 *   @0x24e53c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24e540 ldr r7, [r6, #0x4]
 *   @0x24e544 sub r7, r7, #1
 *   @0x24e548 str r7, [r6, #0x4]
 *   @0x24e54c cmp r7, #0
 *   @0x24e550 bne 0x24e574 <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0x238>
 *   @0x24e554 ldr r0, [r6]
 *   @0x24e558 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24e55c mov r0, r6
 *   @0x24e560 str r7, [r6]
 *   @0x24e564 str r7, [r6, #0x8]
 *   @0x24e568 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x24e56c mov r0, r6
 *   @0x24e570 bl 0x27d1d0 <_ZdlPv>
 *   @0x24e574 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x24e578 mov r0, r6
 *   @0x24e57c bl 0x27d1d0 <_ZdlPv>
 *   @0x24e580 b 0x24e51c <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_+0x1e0>
 *   @0x24e584 andseq pc, r9, r0, ror #19
 *   @0x24e588 ldrsheq r3, [r10], -r4
 *
 * ══ §14/54 b2ParticleSystem::SolveElastic  0x2d5fc0  size 588  147 条（0x2d5fc0..0x2d620c）
 * @func 0x2d5fc0 0x2d620c  size 588  147 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ParticleSystem::SolveElastic(b2TimeStep const&)+0x23c
 * 字段偏移 top8: 0x98×1 / 0xa0×1 / 0x-4×1 / 0x-10×1 / 0x-c×1 / 0x38×1 / 0x-8×1 / 0x40×1
 * VFP 指令 105 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d5fc0 push {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x2d5fc4 vldr s15, [r0, #180]
 *   @0x2d5fc8 vpush {d8, d9, d10, d11}
 *   @0x2d5fcc vldr s16, [r1, #4]
 *   @0x2d5fd0 ldr r10, [r0, #0x98]
 *   @0x2d5fd4 vmul.f32 s16, s16, s15
 *   @0x2d5fd8 cmp r10, #0
 *   @0x2d5fdc ble 0x2d61fc <_ZN16b2ParticleSystem12SolveElasticERK10b2TimeStep+0x23c>
 *   @0x2d5fe0 ldr r1, [r0, #0xa0]
 *   @0x2d5fe4 rsb r10, r10, r10, lsl #4
 *   @0x2d5fe8 vldr s0, [pc, #536]
 *   @0x2d5fec add r3, r1, #16
 *   @0x2d5ff0 add r4, r1, #20
 *   @0x2d5ff4 add r12, r1, #28
 *   @0x2d5ff8 add r10, r3, r10, lsl #2
 *   @0x2d5ffc add r1, r1, #36
 *   @0x2d6000 vmov.f32 s18, #5.000000e-01
 *   @0x2d6004 vmov.f32 s17, #1.500000e+00
 *   @0x2d6008 ldr r2, [r3, #-0x4]
 *   @0x2d600c tst r2, #16
 *   @0x2d6010 beq 0x2d61e4 <_ZN16b2ParticleSystem12SolveElasticERK10b2TimeStep+0x224>
 *   @0x2d6014 ldr r9, [r3, #-0x10]
 *   @0x2d6018 vldr s9, [r4, #4]
 *   @0x2d601c ldr r7, [r3, #-0xc]
 *   @0x2d6020 vldr s8, [r12, #4]
 *   @0x2d6024 ldr r6, [r0, #0x38]
 *   @0x2d6028 vldr s19, [r1, #4]
 *   @0x2d602c lsl r9, r9, #3
 *   @0x2d6030 ldr r5, [r3, #-0x8]
 *   @0x2d6034 lsl r7, r7, #3
 *   @0x2d6038 add r2, r6, r9
 *   @0x2d603c add r8, r6, r7
 *   @0x2d6040 vldr s12, [r2, #4]
 *   @0x2d6044 vldr s4, [r8, #4]
 *   @0x2d6048 vmul.f32 s21, s12, s9
 *   @0x2d604c lsl r5, r5, #3
 *   @0x2d6050 vldr s11, [r2]
 *   @0x2d6054 add r6, r6, r5
 *   @0x2d6058 vldr s2, [r6, #4]
 *   @0x2d605c vldr s10, [r4]
 *   @0x2d6060 vldr s7, [r8]
 *   @0x2d6064 vldr s23, [r12]
 *   @0x2d6068 vldr s3, [r6]
 *   @0x2d606c vldr s22, [r1]
 *   @0x2d6070 ldr r2, [r0, #0x40]
 *   @0x2d6074 vldr s15, [r3]
 *   @0x2d6078 add r9, r2, r9
 *   @0x2d607c add r7, r2, r7
 *   @0x2d6080 add r5, r2, r5
 *   @0x2d6084 vldr s5, [r9]
 *   @0x2d6088 vldr s6, [r9, #4]
 *   @0x2d608c vmul.f32 s13, s4, s8
 *   @0x2d6090 vmul.f32 s20, s2, s19
 *   @0x2d6094 vmla.f32 s21, s11, s10
 *   @0x2d6098 vmul.f32 s1, s11, s9
 *   @0x2d609c vmul.f32 s8, s7, s8
 *   @0x2d60a0 vmla.f32 s13, s7, s23
 *   @0x2d60a4 vmul.f32 s19, s3, s19
 *   @0x2d60a8 vmla.f32 s20, s3, s22
 *   @0x2d60ac vnmls.f32 s8, s4, s23
 *   @0x2d60b0 vnmls.f32 s1, s12, s10
 *   @0x2d60b4 vadd.f32 s13, s21, s13
 *   @0x2d60b8 vnmls.f32 s19, s2, s22
 *   @0x2d60bc vadd.f32 s13, s13, s20
 *   @0x2d60c0 vadd.f32 s1, s1, s8
 *   @0x2d60c4 vmul.f32 s8, s13, s13
 *   @0x2d60c8 vadd.f32 s1, s1, s19
 *   @0x2d60cc vmla.f32 s8, s1, s1
 *   @0x2d60d0 vmov r11, s8
 *   @0x2d60d4 vmul.f32 s14, s8, s18
 *   @0x2d60d8 vmov.f32 s19, s17
 *   @0x2d60dc vadd.f32 s7, s11, s7
 *   @0x2d60e0 asr r2, r11, #1
 *   @0x2d60e4 rsb r2, r2, #1593835520
 *   @0x2d60e8 add r2, r2, #3620864
 *   @0x2d60ec add r2, r2, #6592
 *   @0x2d60f0 add r2, r2, #31
 *   @0x2d60f4 vmov s8, r2
 *   @0x2d60f8 vadd.f32 s7, s7, s3
 *   @0x2d60fc vmul.f32 s14, s14, s8
 *   @0x2d6100 vmls.f32 s19, s8, s14
 *   @0x2d6104 vmul.f32 s14, s8, s19
 *   @0x2d6108 vmul.f32 s13, s13, s14
 *   @0x2d610c vmul.f32 s14, s1, s14
 *   @0x2d6110 vadd.f32 s8, s12, s4
 *   @0x2d6114 vmul.f32 s4, s14, s9
 *   @0x2d6118 vmul.f32 s9, s13, s9
 *   @0x2d611c vadd.f32 s8, s8, s2
 *   @0x2d6120 vmul.f32 s7, s7, s0
 *   @0x2d6124 vmul.f32 s8, s8, s0
 *   @0x2d6128 vnmls.f32 s4, s13, s10
 *   @0x2d612c vmla.f32 s9, s14, s10
 *   @0x2d6130 vsub.f32 s11, s11, s7
 *   @0x2d6134 vsub.f32 s12, s12, s8
 *   @0x2d6138 vmul.f32 s15, s16, s15
 *   @0x2d613c vsub.f32 s4, s4, s11
 *   @0x2d6140 vsub.f32 s9, s9, s12
 *   @0x2d6144 vmla.f32 s5, s15, s4
 *   @0x2d6148 vmla.f32 s6, s15, s9
 *   @0x2d614c vstr s5, [r9]
 *   @0x2d6150 vldr s5, [r8]
 *   @0x2d6154 vldr s12, [r7]
 *   @0x2d6158 vstr s6, [r9, #4]
 *   @0x2d615c vldr s11, [r12, #4]
 *   @0x2d6160 vmul.f32 s9, s14, s11
 *   @0x2d6164 vldr s6, [r12]
 *   @0x2d6168 vldr s4, [r8, #4]
 *   @0x2d616c vldr s10, [r7, #4]
 *   @0x2d6170 vmul.f32 s11, s13, s11
 *   @0x2d6174 vnmls.f32 s9, s13, s6
 *   @0x2d6178 vmla.f32 s11, s14, s6
 *   @0x2d617c vsub.f32 s5, s5, s7
 *   @0x2d6180 vsub.f32 s6, s4, s8
 *   @0x2d6184 vsub.f32 s9, s9, s5
 *   @0x2d6188 vsub.f32 s11, s11, s6
 *   @0x2d618c vmla.f32 s12, s15, s9
 *   @0x2d6190 vmla.f32 s10, s15, s11
 *   @0x2d6194 vstr s12, [r7]
 *   @0x2d6198 vldr s5, [r6]
 *   @0x2d619c vldr s12, [r5]
 *   @0x2d61a0 vstr s10, [r7, #4]
 *   @0x2d61a4 vldr s9, [r1, #4]
 *   @0x2d61a8 vmul.f32 s11, s14, s9
 *   @0x2d61ac vldr s10, [r1]
 *   @0x2d61b0 vldr s6, [r6, #4]
 *   @0x2d61b4 vnmls.f32 s11, s13, s10
 *   @0x2d61b8 vmul.f32 s13, s13, s9
 *   @0x2d61bc vsub.f32 s7, s5, s7
 *   @0x2d61c0 vmla.f32 s13, s14, s10
 *   @0x2d61c4 vsub.f32 s11, s11, s7
 *   @0x2d61c8 vmla.f32 s12, s15, s11
 *   @0x2d61cc vsub.f32 s8, s6, s8
 *   @0x2d61d0 vstr s12, [r5]
 *   @0x2d61d4 vldr s14, [r5, #4]
 *   @0x2d61d8 vsub.f32 s13, s13, s8
 *   @0x2d61dc vmla.f32 s14, s15, s13
 *   @0x2d61e0 vstr s14, [r5, #4]
 *   @0x2d61e4 add r3, r3, #60
 *   @0x2d61e8 add r4, r4, #60
 *   @0x2d61ec cmp r3, r10
 *   @0x2d61f0 add r12, r12, #60
 *   @0x2d61f4 add r1, r1, #60
 *   @0x2d61f8 bne 0x2d6008 <_ZN16b2ParticleSystem12SolveElasticERK10b2TimeStep+0x48>
 *   @0x2d61fc vpop {d8, d9, d10, d11}
 *   @0x2d6200 pop {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x2d6204 bx lr
 *   @0x2d6208 .word 0x3eaaaaab
 *
 * ══ §15/54 ShowForm  0xecb34  size 584  146 条（0xecb34..0xecd7c）
 * @func 0xecb34 0xecd8c  size 600  150 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65c8×5 / 0xb6568×4 / 0xb65b0×3 / 0xb6538×2 / ExitFullScreen() / DebuggerIsConnected() / Code_Error::Show() / DebuggerMessageLoop()
 * 字段偏移 top8: 0x-3c×2 / 0x-38×2 / 0x-30×2 / 0x1f0×2 / 0x-28×2 / 0x-40×2 / 0x-34×2 / 0x188×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xecb34 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xecb38 add r11, sp, #32
 *   @0xecb3c ldr r2, [pc, #0x214]
 *   @0xecb40 sub sp, sp, #44
 *   @0xecb44 ldr r3, [pc, #0x210]
 *   @0xecb48 ldr r2, [pc, r2]
 *   @0xecb4c str r1, [r11, #-0x3c]
 *   @0xecb50 add r3, pc, r3
 *   @0xecb54 str r3, [r11, #-0x38]
 *   @0xecb58 ldr r3, [r2]
 *   @0xecb5c mov r5, r0
 *   @0xecb60 str r2, [r11, #-0x30]
 *   @0xecb64 mov r4, #0
 *   @0xecb68 ldr r1, [pc, #0x1f0]
 *   @0xecb6c ldr r2, [pc, #0x1f0]
 *   @0xecb70 add r1, pc, r1
 *   @0xecb74 str r3, [r11, #-0x28]
 *   @0xecb78 str r1, [r11, #-0x40]
 *   @0xecb7c add r2, pc, r2
 *   @0xecb80 str r2, [r11, #-0x34]
 *   @0xecb84 bl 0x17df38 <_Z14ExitFullScreenv>
 *   @0xecb88 mov r0, r5
 *   @0xecb8c bl 0xb6538 <strlen@plt>
 *   @0xecb90 mov r1, r4
 *   @0xecb94 add r0, r0, #128
 *   @0xecb98 lsl r6, r0, #1
 *   @0xecb9c add r3, r6, #14
 *   @0xecba0 bic r3, r3, #7
 *   @0xecba4 mov r2, r6
 *   @0xecba8 sub sp, sp, r3
 *   @0xecbac add r9, sp, #8
 *   @0xecbb0 sub sp, sp, r3
 *   @0xecbb4 add r8, sp, #8
 *   @0xecbb8 sub sp, sp, r3
 *   @0xecbbc mov r0, r9
 *   @0xecbc0 add r7, sp, #8
 *   @0xecbc4 bl 0xb65b0 <memset@plt>
 *   @0xecbc8 mov r2, r6
 *   @0xecbcc mov r1, r4
 *   @0xecbd0 mov r0, r8
 *   @0xecbd4 bl 0xb65b0 <memset@plt>
 *   @0xecbd8 ldr r2, [pc, #0x188]
 *   @0xecbdc ldr r3, [pc, #0x188]
 *   @0xecbe0 mov r0, r9
 *   @0xecbe4 mov r1, r6
 *   @0xecbe8 add r2, pc, r2
 *   @0xecbec add r3, pc, r3
 *   @0xecbf0 bl 0xb65c8 <snprintf@plt>
 *   @0xecbf4 b 0xecc2c <_Z8ShowFormPKcb+0xf8>
 *   @0xecbf8 cmp r3, #9
 *   @0xecbfc mov r1, r8
 *   @0xecc00 mov r2, r6
 *   @0xecc04 beq 0xecc9c <_Z8ShowFormPKcb+0x168>
 *   @0xecc08 bl 0xb6568 <strncpy@plt>
 *   @0xecc0c ldrb r12, [r10]
 *   @0xecc10 mov r0, r8
 *   @0xecc14 mov r1, r6
 *   @0xecc18 ldr r2, [r11, #-0x38]
 *   @0xecc1c mov r3, r7
 *   @0xecc20 str r12, [sp]
 *   @0xecc24 bl 0xb65c8 <snprintf@plt>
 *   @0xecc28 add r4, r4, #1
 *   @0xecc2c mov r0, r5
 *   @0xecc30 bl 0xb6538 <strlen@plt>
 *   @0xecc34 cmp r4, r0
 *   @0xecc38 bge 0xeccb8 <_Z8ShowFormPKcb+0x184>
 *   @0xecc3c ldrb r3, [r5, r4]
 *   @0xecc40 add r10, r5, r4
 *   @0xecc44 mov r0, r7
 *   @0xecc48 cmp r3, #13
 *   @0xecc4c cmpne r3, #10
 *   @0xecc50 bne 0xecbf8 <_Z8ShowFormPKcb+0xc4>
 *   @0xecc54 mov r1, r9
 *   @0xecc58 mov r2, r6
 *   @0xecc5c bl 0xb6568 <strncpy@plt>
 *   @0xecc60 mov r3, r7
 *   @0xecc64 mov r1, r6
 *   @0xecc68 ldr r2, [r11, #-0x34]
 *   @0xecc6c str r8, [sp]
 *   @0xecc70 mov r0, r9
 *   @0xecc74 bl 0xb65c8 <snprintf@plt>
 *   @0xecc78 mov r0, r8
 *   @0xecc7c mov r1, #0
 *   @0xecc80 mov r2, r6
 *   @0xecc84 bl 0xb65b0 <memset@plt>
 *   @0xecc88 ldrb r3, [r10, #0x1]
 *   @0xecc8c cmp r3, #13
 *   @0xecc90 cmpne r3, #10
 *   @0xecc94 addeq r4, r4, #1
 *   @0xecc98 b 0xecc28 <_Z8ShowFormPKcb+0xf4>
 *   @0xecc9c bl 0xb6568 <strncpy@plt>
 *   @0xecca0 mov r0, r8
 *   @0xecca4 mov r1, r6
 *   @0xecca8 ldr r2, [r11, #-0x40]
 *   @0xeccac mov r3, r7
 *   @0xeccb0 bl 0xb65c8 <snprintf@plt>
 *   @0xeccb4 b 0xecc28 <_Z8ShowFormPKcb+0xf4>
 *   @0xeccb8 mov r1, r9
 *   @0xeccbc mov r2, r6
 *   @0xeccc0 mov r0, r7
 *   @0xeccc4 ldr r4, [pc, #0xa4]
 *   @0xeccc8 bl 0xb6568 <strncpy@plt>
 *   @0xecccc ldr r2, [pc, #0xa0]
 *   @0xeccd0 mov r1, r6
 *   @0xeccd4 mov r3, r7
 *   @0xeccd8 add r2, pc, r2
 *   @0xeccdc str r8, [sp]
 *   @0xecce0 mov r0, r9
 *   @0xecce4 bl 0xb65c8 <snprintf@plt>
 *   @0xecce8 ldr r4, [pc, r4]
 *   @0xeccec ldr r1, [r11, #-0x3c]
 *   @0xeccf0 ldr r3, [r4]
 *   @0xeccf4 strb r1, [r3, #0x4]
 *   @0xeccf8 str r9, [r3]
 *   @0xeccfc bl 0x29cb74 <_Z19DebuggerIsConnectedv>
 *   @0xecd00 cmp r0, #0
 *   @0xecd04 bne 0xecd38 <_Z8ShowFormPKcb+0x204>
 *   @0xecd08 ldr r0, [r4]
 *   @0xecd0c bl 0xf1c94 <_ZN10Code_Error4ShowEv>
 *   @0xecd10 subs r3, r0, #1
 *   @0xecd14 rsbs r0, r3, #0
 *   @0xecd18 adcs r0, r0, r3
 *   @0xecd1c ldr r1, [r11, #-0x30]
 *   @0xecd20 ldr r2, [r11, #-0x28]
 *   @0xecd24 ldr r3, [r1]
 *   @0xecd28 cmp r2, r3
 *   @0xecd2c bne 0xecd54 <_Z8ShowFormPKcb+0x220>
 *   @0xecd30 sub sp, r11, #32
 *   @0xecd34 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xecd38 ldr r4, [pc, #0x38]
 *   @0xecd3c ldr r4, [pc, r4]
 *   @0xecd40 str r9, [r4]
 *   @0xecd44 bl 0x29d634 <_Z19DebuggerMessageLoopv>
 *   @0xecd48 mov r0, #0
 *   @0xecd4c str r0, [r4]
 *   @0xecd50 b 0xecd1c <_Z8ShowFormPKcb+0x1e8>
 *   @0xecd54 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0xecd58 eorseq r0, r0, r8, lsl #28
 *   @0xecd5c eoreq r8, r4, r12, ror r0
 *   @0xecd60 eoreq r8, r4, r0, asr r0
 *   @0xecd64 eoreq r8, r4, r12, lsr r0
 *   @0xecd68 mlaeq r4, r12, pc, r7
 *   @0xecd6c eoreq r7, r4, r0, lsr #31
 *   @0xecd70 eorseq r1, r0, r0, lsr #1
 *   @0xecd74 .word 0x00247efc
 *   @0xecd78 eorseq r1, r0, r0, asr r0
 *
 * ══ §16/54 GR_Texture_Draw_Part  0x175208  size 584  146 条（0x175208..0x175450）
 * @func 0x175208 0x175450  size 584  146 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Texture_Exists(int) / GR_Texture_Draw_Part(int, float, float, float, float, float, float, float, float, float, unsigned int, float)+0x224 / Graphics::AllocVerts(ePrimType, void*, int, int) / 0xb6580 / 0xb658c / 0xfe239e08
 * 字段偏移 top8: 0x1e4×1 / 0x60×1 / 0x4×1 / 0x2×1 / 0xec×1 / 0x84×1 / 0x6c×1 / 0x54×1
 * VFP 指令 95 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x175208 push {r3, r4, r5, r6, r7, lr}
 *   @0x17520c vpush {d8, d9, d10, d11, d12, d13}
 *   @0x175210 mov r4, r0
 *   @0x175214 vldr s18, [sp, #72]
 *   @0x175218 vmov s20, r1
 *   @0x17521c vldr s21, [sp, #76]
 *   @0x175220 vmov s17, r2
 *   @0x175224 vldr s22, [sp, #80]
 *   @0x175228 vmov s19, r3
 *   @0x17522c vldr s23, [sp, #92]
 *   @0x175230 bl 0x173e2c <_Z17GR_Texture_Existsi>
 *   @0x175234 subs r7, r0, #0
 *   @0x175238 beq 0x1753dc <_Z20GR_Texture_Draw_Partifffffffffjf+0x1d4>
 *   @0x17523c vldr s15, [pc, #504]
 *   @0x175240 vldr s14, [sp, #100]
 *   @0x175244 vmul.f32 s15, s14, s15
 *   @0x175248 vcvt.s32.f32 s15, s15
 *   @0x17524c vmov r5, s15
 *   @0x175250 cmp r5, #255
 *   @0x175254 movgt r5, #-16777216
 *   @0x175258 ble 0x17542c <_Z20GR_Texture_Draw_Partifffffffffjf+0x224>
 *   @0x17525c ldr r1, [pc, #0x1e4]
 *   @0x175260 vldr s16, [pc, #472]
 *   @0x175264 vmov.f32 s25, s16
 *   @0x175268 ldr r3, [sp, #0x60]
 *   @0x17526c ldr r1, [pc, r1]
 *   @0x175270 mov r0, #4
 *   @0x175274 bic r12, r3, #-16777216
 *   @0x175278 mov r2, #24
 *   @0x17527c ldr r1, [r1, #0x4]
 *   @0x175280 mov r3, #6
 *   @0x175284 vldr s14, [sp, #84]
 *   @0x175288 orr r5, r5, r12
 *   @0x17528c vmla.f32 s25, s14, s19
 *   @0x175290 ldr r6, [r1, r4, lsl #2]
 *   @0x175294 ldr r1, [r6]
 *   @0x175298 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x17529c vldr s15, [pc, #416]
 *   @0x1752a0 vabs.f32 s14, s23
 *   @0x1752a4 vmov.f32 s24, s16
 *   @0x1752a8 vcmpe.f32 s14, s15
 *   @0x1752ac vldr s15, [sp, #88]
 *   @0x1752b0 vmrs APSR_nzcv, fpscr
 *   @0x1752b4 vmla.f32 s24, s15, s18
 *   @0x1752b8 mov r4, r0
 *   @0x1752bc bmi 0x1753e8 <_Z20GR_Texture_Draw_Partifffffffffjf+0x1e0>
 *   @0x1752c0 vmov r0, s23
 *   @0x1752c4 bl 0xb6580 <sinf@plt>
 *   @0x1752c8 vmov s26, r0
 *   @0x1752cc vmov r0, s23
 *   @0x1752d0 bl 0xb658c <cosf@plt>
 *   @0x1752d4 vmov.f32 s12, s22
 *   @0x1752d8 vmov.f32 s13, s21
 *   @0x1752dc vmul.f32 s15, s26, s16
 *   @0x1752e0 vmls.f32 s12, s25, s26
 *   @0x1752e4 vmov s14, r0
 *   @0x1752e8 vmul.f32 s16, s14, s16
 *   @0x1752ec vmla.f32 s13, s25, s14
 *   @0x1752f0 vmul.f32 s26, s24, s26
 *   @0x1752f4 vmul.f32 s14, s24, s14
 *   @0x1752f8 vsub.f32 s22, s22, s15
 *   @0x1752fc vadd.f32 s21, s21, s16
 *   @0x175300 vadd.f32 s11, s16, s22
 *   @0x175304 vadd.f32 s22, s14, s22
 *   @0x175308 vstr s11, [r4, #4]
 *   @0x17530c vstr s11, [r4, #124]
 *   @0x175310 vadd.f32 s14, s14, s12
 *   @0x175314 vstr s22, [r4, #100]
 *   @0x175318 vadd.f32 s16, s16, s12
 *   @0x17531c vstr s14, [r4, #52]
 *   @0x175320 vstr s14, [r4, #76]
 *   @0x175324 vadd.f32 s12, s15, s21
 *   @0x175328 vstr s16, [r4, #28]
 *   @0x17532c vadd.f32 s21, s26, s21
 *   @0x175330 vstr s12, [r4]
 *   @0x175334 vstr s12, [r4, #120]
 *   @0x175338 vadd.f32 s26, s26, s13
 *   @0x17533c vstr s21, [r4, #96]
 *   @0x175340 vadd.f32 s15, s15, s13
 *   @0x175344 vstr s26, [r4, #48]
 *   @0x175348 vstr s26, [r4, #72]
 *   @0x17534c vstr s15, [r4, #24]
 *   @0x175350 vldr s14, [r6, #8]
 *   @0x175354 vmul.f32 s12, s14, s20
 *   @0x175358 ldr r3, [pc, #0xec]
 *   @0x17535c str r5, [r4, #0x84]
 *   @0x175360 ldr r3, [pc, r3]
 *   @0x175364 str r5, [r4, #0x6c]
 *   @0x175368 str r5, [r4, #0x54]
 *   @0x17536c ldr r3, [r3]
 *   @0x175370 str r5, [r4, #0x3c]
 *   @0x175374 str r5, [r4, #0x24]
 *   @0x175378 str r3, [r4, #0x80]
 *   @0x17537c str r3, [r4, #0x68]
 *   @0x175380 str r5, [r4, #0xc]
 *   @0x175384 str r3, [r4, #0x50]
 *   @0x175388 vadd.f32 s13, s20, s19
 *   @0x17538c vstr s12, [r4, #136]
 *   @0x175390 vstr s12, [r4, #112]
 *   @0x175394 vstr s12, [r4, #16]
 *   @0x175398 vldr s12, [r6, #12]
 *   @0x17539c str r3, [r4, #0x38]
 *   @0x1753a0 str r3, [r4, #0x20]
 *   @0x1753a4 str r3, [r4, #0x8]
 *   @0x1753a8 vadd.f32 s15, s17, s18
 *   @0x1753ac vmul.f32 s13, s14, s13
 *   @0x1753b0 vmul.f32 s15, s12, s15
 *   @0x1753b4 vstr s13, [r4, #88]
 *   @0x1753b8 vstr s13, [r4, #64]
 *   @0x1753bc vstr s13, [r4, #40]
 *   @0x1753c0 vmul.f32 s14, s12, s17
 *   @0x1753c4 vstr s15, [r4, #116]
 *   @0x1753c8 vstr s15, [r4, #92]
 *   @0x1753cc vstr s15, [r4, #68]
 *   @0x1753d0 vstr s14, [r4, #140]
 *   @0x1753d4 vstr s14, [r4, #44]
 *   @0x1753d8 vstr s14, [r4, #20]
 *   @0x1753dc vpop {d8, d9, d10, d11, d12, d13}
 *   @0x1753e0 mov r0, r7
 *   @0x1753e4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1753e8 vadd.f32 s25, s21, s25
 *   @0x1753ec vadd.f32 s21, s21, s16
 *   @0x1753f0 vstr s25, [r0, #48]
 *   @0x1753f4 vstr s25, [r0, #72]
 *   @0x1753f8 vstr s25, [r0, #24]
 *   @0x1753fc vadd.f32 s16, s22, s16
 *   @0x175400 vstr s21, [r0]
 *   @0x175404 vstr s21, [r0, #120]
 *   @0x175408 vstr s21, [r0, #96]
 *   @0x17540c vadd.f32 s22, s22, s24
 *   @0x175410 vstr s16, [r0, #28]
 *   @0x175414 vstr s16, [r0, #4]
 *   @0x175418 vstr s16, [r0, #124]
 *   @0x17541c vstr s22, [r0, #100]
 *   @0x175420 vstr s22, [r0, #52]
 *   @0x175424 vstr s22, [r0, #76]
 *   @0x175428 b 0x175350 <_Z20GR_Texture_Draw_Partifffffffffjf+0x148>
 *   @0x17542c cmp r5, #0
 *   @0x175430 lslge r5, r5, #24
 *   @0x175434 movlt r5, #0
 *   @0x175438 b 0x17525c <_Z20GR_Texture_Draw_Partifffffffffjf+0x54>
 *   @0x17543c cmnmi pc, #0
 *   @0x175440 andeq r0, r0, r0
 *   @0x175444 blo 0xfe239e08 <b2_toiTime+0xfffffffffdae0964>
 *   @0x175448 .word 0x002786b0
 *   @0x17544c eoreq r8, r7, r0, asr #11
 *
 * ══ §17/54 UpdateDefaultCamera  0x1aff1c  size 584  146 条（0x1aff1c..0x1b0164）
 * @func 0x1aff1c 0x1b0164  size 584  146 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CCamera::ApplyMatrices()×3 / CCameraManager::GetCamera(int) / CCamera::Is2D() / 0xb6580 / 0xb658c / yyMatrix::LookAtLH(yyMatrix*, yyVector3*, yyVector3*, yyVector3*) / CCamera::SetViewMat(yyMatrix&) / yyMatrix::PerspectiveLH(yyMatrix*, float, float, float, float)
 * 字段偏移 top8: 0x110×5 / 0x214×1 / 0x210×1 / 0x20c×1 / 0x20×1 / 0x2c×1 / 0x24×1 / 0x28×1
 * VFP 指令 53 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1aff1c push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x1aff20 vpush {d8, d9, d10}
 *   @0x1aff24 vmov s20, r0
 *   @0x1aff28 ldr r5, [pc, #0x214]
 *   @0x1aff2c vmov s19, r1
 *   @0x1aff30 ldr r0, [pc, #0x210]
 *   @0x1aff34 sub sp, sp, #116
 *   @0x1aff38 ldr r1, [pc, #0x20c]
 *   @0x1aff3c add r5, pc, r5
 *   @0x1aff40 vmov s16, r2
 *   @0x1aff44 vldr s17, [sp, #168]
 *   @0x1aff48 ldr r7, [r5, r0]
 *   @0x1aff4c vmov s18, r3
 *   @0x1aff50 ldr r6, [r5, r1]
 *   @0x1aff54 mov r0, r7
 *   @0x1aff58 ldr r1, [r6]
 *   @0x1aff5c bl 0x16f45c <_ZN14CCameraManager9GetCameraEi>
 *   @0x1aff60 subs r4, r0, #0
 *   @0x1aff64 beq 0x1b00a0 <_Z19UpdateDefaultCamerafffff+0x184>
 *   @0x1aff68 bl 0x16d398 <_ZN7CCamera4Is2DEv>
 *   @0x1aff6c cmp r0, #0
 *   @0x1aff70 bne 0x1b00ac <_Z19UpdateDefaultCamerafffff+0x190>
 *   @0x1aff74 vmov.f32 s15, #5.000000e-01
 *   @0x1aff78 vldr s21, [pc, #448]
 *   @0x1aff7c mov r8, #0
 *   @0x1aff80 str r8, [sp, #0x20]
 *   @0x1aff84 vmov.f32 s14, s20
 *   @0x1aff88 vmov.f32 s13, s19
 *   @0x1aff8c vmla.f32 s14, s16, s15
 *   @0x1aff90 vmla.f32 s13, s18, s15
 *   @0x1aff94 vstr s14, [sp, #12]
 *   @0x1aff98 vstr s14, [sp, #24]
 *   @0x1aff9c vnmul.f32 s15, s17, s21
 *   @0x1affa0 vstr s13, [sp, #16]
 *   @0x1affa4 vstr s13, [sp, #28]
 *   @0x1affa8 vneg.f32 s14, s16
 *   @0x1affac vmov r0, s15
 *   @0x1affb0 vstr s14, [sp, #20]
 *   @0x1affb4 bl 0xb6580 <sinf@plt>
 *   @0x1affb8 vmul.f32 s21, s17, s21
 *   @0x1affbc mov r9, r0
 *   @0x1affc0 vmov r0, s21
 *   @0x1affc4 bl 0xb658c <cosf@plt>
 *   @0x1affc8 str r8, [sp, #0x2c]
 *   @0x1affcc add r8, sp, #48
 *   @0x1affd0 add r2, sp, #24
 *   @0x1affd4 add r3, sp, #36
 *   @0x1affd8 add r1, sp, #12
 *   @0x1affdc str r9, [sp, #0x24]
 *   @0x1affe0 str r0, [sp, #0x28]
 *   @0x1affe4 mov r0, r8
 *   @0x1affe8 bl 0x27acb0 <_ZN8yyMatrix8LookAtLHEPS_P9yyVector3S2_S2_>
 *   @0x1affec mov r0, r4
 *   @0x1afff0 mov r1, r8
 *   @0x1afff4 bl 0x16da94 <_ZN7CCamera10SetViewMatER8yyMatrix>
 *   @0x1afff8 vdiv.f32 s15, s18, s16
 *   @0x1afffc mov r3, #1065353216
 *   @0x1b0000 mov r0, r8
 *   @0x1b0004 mov r2, #0
 *   @0x1b0008 movt r2, #0x46fa
 *   @0x1b000c str r2, [sp]
 *   @0x1b0010 vdiv.f32 s13, s16, s16
 *   @0x1b0014 vneg.f32 s15, s15
 *   @0x1b0018 vmov r1, s13
 *   @0x1b001c vmov r2, s15
 *   @0x1b0020 bl 0x27b180 <_ZN8yyMatrix13PerspectiveLHEPS_ffff>
 *   @0x1b0024 mov r1, r8
 *   @0x1b0028 mov r0, r4
 *   @0x1b002c bl 0x16d9e4 <_ZN7CCamera10SetProjMatER8yyMatrix>
 *   @0x1b0030 mov r0, r4
 *   @0x1b0034 bl 0x16d3bc <_ZN7CCamera13ApplyMatricesEv>
 *   @0x1b0038 ldr r0, [pc, #0x110]
 *   @0x1b003c ldr r1, [pc, #0x110]
 *   @0x1b0040 ldr r2, [pc, #0x110]
 *   @0x1b0044 ldr r3, [pc, #0x110]
 *   @0x1b0048 ldr r12, [pc, #0x110]
 *   @0x1b004c ldr r0, [r5, r0]
 *   @0x1b0050 vstr s20, [r0]
 *   @0x1b0054 vmov r0, s20
 *   @0x1b0058 ldr r1, [r5, r1]
 *   @0x1b005c vstr s19, [r1]
 *   @0x1b0060 vmov r1, s19
 *   @0x1b0064 ldr r2, [r5, r2]
 *   @0x1b0068 vstr s16, [r2]
 *   @0x1b006c vmov r2, s16
 *   @0x1b0070 ldr r3, [r5, r3]
 *   @0x1b0074 vstr s18, [r3]
 *   @0x1b0078 vmov r3, s18
 *   @0x1b007c ldr r12, [r5, r12]
 *   @0x1b0080 vstr s17, [sp]
 *   @0x1b0084 vstr s17, [r12]
 *   @0x1b0088 bl 0x1692e4 <_Z14SetViewExtentsfffff>
 *   @0x1b008c mov r0, r7
 *   @0x1b0090 ldr r1, [r6]
 *   @0x1b0094 bl 0x1707c8 <_ZN14CCameraManager15SetActiveCameraEi>
 *   @0x1b0098 mov r0, r4
 *   @0x1b009c bl 0x16d3bc <_ZN7CCamera13ApplyMatricesEv>
 *   @0x1b00a0 add sp, sp, #116
 *   @0x1b00a4 vpop {d8, d9, d10}
 *   @0x1b00a8 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x1b00ac mov r0, r4
 *   @0x1b00b0 vmov r1, s20
 *   @0x1b00b4 bl 0x16d29c <_ZN7CCamera8SetViewXEf>
 *   @0x1b00b8 mov r0, r4
 *   @0x1b00bc vmov r1, s19
 *   @0x1b00c0 bl 0x16d2ac <_ZN7CCamera8SetViewYEf>
 *   @0x1b00c4 mov r0, r4
 *   @0x1b00c8 vmov r1, s16
 *   @0x1b00cc bl 0x16d2bc <_ZN7CCamera12SetViewWidthEf>
 *   @0x1b00d0 mov r0, r4
 *   @0x1b00d4 vmov r1, s18
 *   @0x1b00d8 bl 0x16d2cc <_ZN7CCamera13SetViewHeightEf>
 *   @0x1b00dc vmov r1, s17
 *   @0x1b00e0 mov r0, r4
 *   @0x1b00e4 vmov.f32 s17, #5.000000e-01
 *   @0x1b00e8 bl 0x16d31c <_ZN7CCamera12SetViewAngleEf>
 *   @0x1b00ec mov r0, r4
 *   @0x1b00f0 bl 0x16d2a4 <_ZN7CCamera8GetViewXEv>
 *   @0x1b00f4 vmov s16, r0
 *   @0x1b00f8 mov r0, r4
 *   @0x1b00fc bl 0x16d2c4 <_ZN7CCamera12GetViewWidthEv>
 *   @0x1b0100 vmov s13, r0
 *   @0x1b0104 mov r0, r4
 *   @0x1b0108 vmla.f32 s16, s13, s17
 *   @0x1b010c bl 0x16d2b4 <_ZN7CCamera8GetViewYEv>
 *   @0x1b0110 vmov s18, r0
 *   @0x1b0114 mov r0, r4
 *   @0x1b0118 bl 0x16d2d4 <_ZN7CCamera13GetViewHeightEv>
 *   @0x1b011c vmov r1, s16
 *   @0x1b0120 vmov s15, r0
 *   @0x1b0124 mov r0, r4
 *   @0x1b0128 vmla.f32 s18, s15, s17
 *   @0x1b012c vmov r2, s18
 *   @0x1b0130 bl 0x16db44 <_ZN7CCamera11Build2DViewEff>
 *   @0x1b0134 mov r0, r4
 *   @0x1b0138 bl 0x16d3bc <_ZN7CCamera13ApplyMatricesEv>
 *   @0x1b013c b 0x1b008c <_Z19UpdateDefaultCamerafffff+0x170>
 *   @0x1b0140 vstmialo lr, {s30, s31}
 *   @0x1b0144 eoreq r1, r4, r4, lsl sp
 *   @0x1b0148 .word 0xffffc024
 *   @0x1b014c .word 0xffffe60c
 *   @0x1b0150 .word 0xffffe504
 *   @0x1b0154 .word 0xffffe508
 *   @0x1b0158 .word 0xffffe50c
 *   @0x1b015c .word 0xffffe510
 *   @0x1b0160 .word 0xffffe514
 *
 * ══ §18/54 F_JS_ToPrimitive  0x24cd64  size 584  146 条（0x24cd64..0x24cfac）
 * @func 0x24cd64 0x24cfac  size 584  146 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×2 / UNLOCK_RVALUE_MUTEX()×2 / YYFree(void const*)×2 / operator delete(void*)×2 / YYError(char const*, ...) / GetContextStackTop() / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*) / _RefThing<char const*>::dec()
 * 字段偏移 top8: 0xc×7 / 0x8×7 / 0x4×5 / 0x200×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24cd64 push {r3, r4, r5, r6, r7, lr}
 *   @0x24cd68 mov r4, r1
 *   @0x24cd6c ldr r1, [r1, #0xc]
 *   @0x24cd70 mov r5, r0
 *   @0x24cd74 bic r3, r1, #-16777216
 *   @0x24cd78 cmp r3, #13
 *   @0x24cd7c bhi 0x24cda0 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x3c>
 *   @0x24cd80 mov r6, #1
 *   @0x24cd84 movw r12, #0x34a3
 *   @0x24cd88 lsl r6, r6, r3
 *   @0x24cd8c and r12, r6, r12
 *   @0x24cd90 cmp r12, #0
 *   @0x24cd94 bne 0x24cdb8 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x54>
 *   @0x24cd98 tst r6, #64
 *   @0x24cd9c bne 0x24ceb8 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x154>
 *   @0x24cda0 ldr r0, [pc, #0x200]
 *   @0x24cda4 mov r1, r3
 *   @0x24cda8 add r0, pc, r0
 *   @0x24cdac bl 0xd547c <_Z7YYErrorPKcz>
 *   @0x24cdb0 mov r0, #1
 *   @0x24cdb4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x24cdb8 ldr r2, [r0, #0xc]
 *   @0x24cdbc bic r3, r2, #-16777216
 *   @0x24cdc0 cmp r3, #1
 *   @0x24cdc4 beq 0x24ce6c <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x108>
 *   @0x24cdc8 cmp r3, #2
 *   @0x24cdcc bne 0x24cdf8 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x94>
 *   @0x24cdd0 sub r2, r2, #1
 *   @0x24cdd4 bic r2, r2, #-16777216
 *   @0x24cdd8 bic r2, r2, #3
 *   @0x24cddc cmp r2, #0
 *   @0x24cde0 beq 0x24cf98 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x234>
 *   @0x24cde4 mov r2, #5
 *   @0x24cde8 str r2, [r5, #0xc]
 *   @0x24cdec ldr r1, [r4, #0xc]
 *   @0x24cdf0 mov r3, #0
 *   @0x24cdf4 str r3, [r5, #0x8]
 *   @0x24cdf8 str r1, [r5, #0xc]
 *   @0x24cdfc mov r1, #0
 *   @0x24ce00 ldr r3, [r4, #0xc]
 *   @0x24ce04 ldr r2, [r4, #0x8]
 *   @0x24ce08 bic r3, r3, #-16777216
 *   @0x24ce0c str r1, [r5]
 *   @0x24ce10 str r2, [r5, #0x8]
 *   @0x24ce14 cmp r3, #14
 *   @0x24ce18 addls pc, pc, r3, lsl #2
 *   @0x24ce1c b 0x24cf18 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x1b4>
 *   @0x24ce20 b 0x24cea4 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x140>
 *   @0x24ce24 b 0x24cf20 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x1bc>
 *   @0x24ce28 b 0x24cef0 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x18c>
 *   @0x24ce2c b 0x24ce5c <_Z16F_JS_ToPrimitiveR6RValueS0_i+0xf8>
 *   @0x24ce30 b 0x24cf18 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x1b4>
 *   @0x24ce34 b 0x24cf18 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x1b4>
 *   @0x24ce38 b 0x24cec8 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x164>
 *   @0x24ce3c b 0x24ce5c <_Z16F_JS_ToPrimitiveR6RValueS0_i+0xf8>
 *   @0x24ce40 b 0x24cf18 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x1b4>
 *   @0x24ce44 b 0x24cf18 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x1b4>
 *   @0x24ce48 b 0x24cea4 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x140>
 *   @0x24ce4c b 0x24cf18 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x1b4>
 *   @0x24ce50 b 0x24cf18 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x1b4>
 *   @0x24ce54 b 0x24cea4 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x140>
 *   @0x24ce58 b 0x24ce5c <_Z16F_JS_ToPrimitiveR6RValueS0_i+0xf8>
 *   @0x24ce5c ldr r3, [r4]
 *   @0x24ce60 mov r0, #0
 *   @0x24ce64 str r3, [r5]
 *   @0x24ce68 pop {r3, r4, r5, r6, r7, pc}
 *   @0x24ce6c ldr r6, [r0]
 *   @0x24ce70 cmp r6, #0
 *   @0x24ce74 beq 0x24ce98 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x134>
 *   @0x24ce78 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24ce7c ldr r7, [r6, #0x4]
 *   @0x24ce80 sub r7, r7, #1
 *   @0x24ce84 str r7, [r6, #0x4]
 *   @0x24ce88 cmp r7, #0
 *   @0x24ce8c beq 0x24cf40 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x1dc>
 *   @0x24ce90 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x24ce94 ldr r1, [r4, #0xc]
 *   @0x24ce98 mov r3, #0
 *   @0x24ce9c str r3, [r5]
 *   @0x24cea0 b 0x24cdf8 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x94>
 *   @0x24cea4 ldr r2, [r4]
 *   @0x24cea8 mov r0, #0
 *   @0x24ceac ldr r3, [r4, #0x4]
 *   @0x24ceb0 stm r5, {r2, r3}
 *   @0x24ceb4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x24ceb8 ldr r0, [r4]
 *   @0x24cebc mov r1, r5
 *   @0x24cec0 pop {r3, r4, r5, r6, r7, lr}
 *   @0x24cec4 b 0x24c844 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei>
 *   @0x24cec8 ldr r3, [r4]
 *   @0x24cecc str r3, [r5]
 *   @0x24ced0 ldr r3, [r4]
 *   @0x24ced4 cmp r3, #0
 *   @0x24ced8 beq 0x24cf18 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x1b4>
 *   @0x24cedc bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x24cee0 ldr r1, [r4]
 *   @0x24cee4 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x24cee8 mov r0, #0
 *   @0x24ceec pop {r3, r4, r5, r6, r7, pc}
 *   @0x24cef0 ldr r3, [r4]
 *   @0x24cef4 cmp r3, #0
 *   @0x24cef8 str r3, [r5]
 *   @0x24cefc beq 0x24cf18 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x1b4>
 *   @0x24cf00 ldr r0, [r3, #0x8]
 *   @0x24cf04 ldr r2, [r3]
 *   @0x24cf08 cmp r0, #0
 *   @0x24cf0c add r2, r2, #1
 *   @0x24cf10 str r2, [r3]
 *   @0x24cf14 beq 0x24cfa0 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x23c>
 *   @0x24cf18 mov r0, #0
 *   @0x24cf1c pop {r3, r4, r5, r6, r7, pc}
 *   @0x24cf20 ldr r3, [r4]
 *   @0x24cf24 mov r0, #0
 *   @0x24cf28 cmp r3, #0
 *   @0x24cf2c ldrne r2, [r3, #0x4]
 *   @0x24cf30 addne r2, r2, #1
 *   @0x24cf34 strne r2, [r3, #0x4]
 *   @0x24cf38 str r3, [r5]
 *   @0x24cf3c pop {r3, r4, r5, r6, r7, pc}
 *   @0x24cf40 ldr r0, [r6]
 *   @0x24cf44 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24cf48 str r7, [r6]
 *   @0x24cf4c str r7, [r6, #0x8]
 *   @0x24cf50 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24cf54 ldr r7, [r6, #0x4]
 *   @0x24cf58 sub r7, r7, #1
 *   @0x24cf5c str r7, [r6, #0x4]
 *   @0x24cf60 cmp r7, #0
 *   @0x24cf64 bne 0x24cf88 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x224>
 *   @0x24cf68 ldr r0, [r6]
 *   @0x24cf6c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24cf70 mov r0, r6
 *   @0x24cf74 str r7, [r6]
 *   @0x24cf78 str r7, [r6, #0x8]
 *   @0x24cf7c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x24cf80 mov r0, r6
 *   @0x24cf84 bl 0x27d1d0 <_ZdlPv>
 *   @0x24cf88 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x24cf8c mov r0, r6
 *   @0x24cf90 bl 0x27d1d0 <_ZdlPv>
 *   @0x24cf94 b 0x24ce90 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x12c>
 *   @0x24cf98 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x24cf9c b 0x24cde4 <_Z16F_JS_ToPrimitiveR6RValueS0_i+0x80>
 *   @0x24cfa0 str r5, [r3, #0x8]
 *   @0x24cfa4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x24cfa8 andseq r9, r0, r8, ror #1
 *
 * ══ §19/54 CInstance::Collision_Point  0x1944b0  size 580  145 条（0x1944b0..0x1946f4）
 * @func 0x1944b0 0x1946f4  size 580  145 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8×4 / CInstance::Collision_Point(float, float, bool)+0x18c×2 / CInstance::SkeletonAnimation() / CSkeletonInstance::ComputeBoundingBox(tagYYRECT*, int, float, float, float, float, float) / Sprite_Data(int) / CSkeletonInstance::PointCollision(int, float, float, float, float, float, float, float) / CInstance::Compute_BoundingBox(bool) / CSprite::PreciseCollisionPoint(int, tagYYRECT*, int, int, float, float, float, int, int)
 * 字段偏移 top8: 0xa0×3 / 0x9c×3 / 0x8×3 / 0xb8×2 / 0x98×2 / 0xb4×2 / 0xc×2 / 0x4×2
 * VFP 指令 43 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1944b0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1944b4 vpush {d8, d9}
 *   @0x1944b8 sub sp, sp, #28
 *   @0x1944bc mov r4, r0
 *   @0x1944c0 vmov s17, r2
 *   @0x1944c4 mov r8, r3
 *   @0x1944c8 vmov s16, r1
 *   @0x1944cc bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv>
 *   @0x1944d0 subs r7, r0, #0
 *   @0x1944d4 ldrbeq r2, [r4, #0x64]
 *   @0x1944d8 beq 0x194544 <_ZN9CInstance15Collision_PointEffb+0x94>
 *   @0x1944dc vldr s15, [r4, #144]
 *   @0x1944e0 vcvt.s32.f32 s15, s15
 *   @0x1944e4 ldr r5, [pc, #0x204]
 *   @0x1944e8 ldr r1, [r4, #0xa0]
 *   @0x1944ec ldr r9, [r4, #0xb8]
 *   @0x1944f0 ldr r5, [pc, r5]
 *   @0x1944f4 ldr lr, [r4, #0x98]
 *   @0x1944f8 ldr r12, [r4, #0x9c]
 *   @0x1944fc ldr r3, [r4, #0xb4]
 *   @0x194500 ldr r6, [r5]
 *   @0x194504 vmov r2, s15
 *   @0x194508 str r4, [r5]
 *   @0x19450c str r1, [sp, #0xc]
 *   @0x194510 add r1, r4, #232
 *   @0x194514 str r9, [sp]
 *   @0x194518 str lr, [sp, #0x4]
 *   @0x19451c str r12, [sp, #0x8]
 *   @0x194520 bl 0xbeda8 <_ZN17CSkeletonInstance18ComputeBoundingBoxEP9tagYYRECTifffff>
 *   @0x194524 str r6, [r5]
 *   @0x194528 cmp r0, #0
 *   @0x19452c ldrbeq r2, [r4, #0x64]
 *   @0x194530 movne r3, #0
 *   @0x194534 movne r2, r3
 *   @0x194538 movne r1, #1
 *   @0x19453c strbne r3, [r4, #0x64]
 *   @0x194540 strbne r1, [r4, #0xb0]
 *   @0x194544 cmp r2, #0
 *   @0x194548 bne 0x19464c <_ZN9CInstance15Collision_PointEffb+0x19c>
 *   @0x19454c ldr r2, [r4, #0xf0]
 *   @0x194550 add r2, r2, #1
 *   @0x194554 vmov s12, r2
 *   @0x194558 vcvt.f32.s32 s15, s12
 *   @0x19455c vcmpe.f32 s15, s16
 *   @0x194560 vmrs APSR_nzcv, fpscr
 *   @0x194564 bls 0x19463c <_ZN9CInstance15Collision_PointEffb+0x18c>
 *   @0x194568 vldr s13, [r4, #232]
 *   @0x19456c vcvt.f32.s32 s15, s13
 *   @0x194570 vcmpe.f32 s16, s15
 *   @0x194574 vmrs APSR_nzcv, fpscr
 *   @0x194578 bmi 0x19463c <_ZN9CInstance15Collision_PointEffb+0x18c>
 *   @0x19457c ldr r3, [r4, #0xf4]
 *   @0x194580 add r3, r3, #1
 *   @0x194584 vmov s14, r3
 *   @0x194588 vcvt.f32.s32 s15, s14
 *   @0x19458c vcmpe.f32 s15, s17
 *   @0x194590 vmrs APSR_nzcv, fpscr
 *   @0x194594 bls 0x19463c <_ZN9CInstance15Collision_PointEffb+0x18c>
 *   @0x194598 vldr s12, [r4, #236]
 *   @0x19459c vcvt.f32.s32 s15, s12
 *   @0x1945a0 vcmpe.f32 s17, s15
 *   @0x1945a4 vmrs APSR_nzcv, fpscr
 *   @0x1945a8 bmi 0x19463c <_ZN9CInstance15Collision_PointEffb+0x18c>
 *   @0x1945ac ldrb r3, [r4, #0x68]
 *   @0x1945b0 cmp r3, #0
 *   @0x1945b4 bne 0x19463c <_ZN9CInstance15Collision_PointEffb+0x18c>
 *   @0x1945b8 ldr r0, [r4, #0xac]
 *   @0x1945bc cmp r0, #0
 *   @0x1945c0 ldrlt r0, [r4, #0x8c]
 *   @0x1945c4 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x1945c8 cmp r0, #0
 *   @0x1945cc mov r5, r0
 *   @0x1945d0 beq 0x19463c <_ZN9CInstance15Collision_PointEffb+0x18c>
 *   @0x1945d4 ldr r3, [r0, #0x18]
 *   @0x1945d8 cmp r3, #0
 *   @0x1945dc beq 0x19463c <_ZN9CInstance15Collision_PointEffb+0x18c>
 *   @0x1945e0 cmp r8, #0
 *   @0x1945e4 beq 0x19465c <_ZN9CInstance15Collision_PointEffb+0x1ac>
 *   @0x1945e8 ldrb r3, [r5, #0x30]
 *   @0x1945ec cmp r3, #0
 *   @0x1945f0 beq 0x19465c <_ZN9CInstance15Collision_PointEffb+0x1ac>
 *   @0x1945f4 cmp r7, #0
 *   @0x1945f8 beq 0x194664 <_ZN9CInstance15Collision_PointEffb+0x1b4>
 *   @0x1945fc vstr s16, [sp, #12]
 *   @0x194600 vstr s17, [sp, #16]
 *   @0x194604 vldr s15, [r4, #144]
 *   @0x194608 vcvt.s32.f32 s15, s15
 *   @0x19460c ldr r12, [r4, #0x98]
 *   @0x194610 mov r0, r7
 *   @0x194614 ldr r2, [r4, #0xb4]
 *   @0x194618 ldr r3, [r4, #0xb8]
 *   @0x19461c str r12, [sp]
 *   @0x194620 ldr lr, [r4, #0x9c]
 *   @0x194624 ldr r12, [r4, #0xa0]
 *   @0x194628 vmov r1, s15
 *   @0x19462c str lr, [sp, #0x4]
 *   @0x194630 str r12, [sp, #0x8]
 *   @0x194634 bl 0xbf374 <_ZN17CSkeletonInstance14PointCollisionEifffffff>
 *   @0x194638 b 0x194640 <_ZN9CInstance15Collision_PointEffb+0x190>
 *   @0x19463c mov r0, #0
 *   @0x194640 add sp, sp, #28
 *   @0x194644 vpop {d8, d9}
 *   @0x194648 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x19464c mov r0, r4
 *   @0x194650 mov r1, #1
 *   @0x194654 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb>
 *   @0x194658 b 0x19454c <_ZN9CInstance15Collision_PointEffb+0x9c>
 *   @0x19465c mov r0, #1
 *   @0x194660 b 0x194640 <_ZN9CInstance15Collision_PointEffb+0x190>
 *   @0x194664 vldr s15, [r4, #180]
 *   @0x194668 vcvt.f64.f32 d6, s15
 *   @0x19466c vldr s15, [r4, #144]
 *   @0x194670 vcvt.s32.f32 s15, s15
 *   @0x194674 vmov r0, r1, d6
 *   @0x194678 vmov r9, s15
 *   @0x19467c bl 0xb66e8 <lrint@plt>
 *   @0x194680 vldr s15, [r4, #184]
 *   @0x194684 vcvt.f64.f32 d6, s15
 *   @0x194688 mov r6, r0
 *   @0x19468c vmov r0, r1, d6
 *   @0x194690 bl 0xb66e8 <lrint@plt>
 *   @0x194694 vldr s18, [r4, #152]
 *   @0x194698 vcvt.f64.f32 d7, s16
 *   @0x19469c ldr r11, [r4, #0x9c]
 *   @0x1946a0 ldr r10, [r4, #0xa0]
 *   @0x1946a4 mov r8, r0
 *   @0x1946a8 vmov r0, r1, d7
 *   @0x1946ac bl 0xb66e8 <lrint@plt>
 *   @0x1946b0 vcvt.f64.f32 d6, s17
 *   @0x1946b4 mov r7, r0
 *   @0x1946b8 vmov r0, r1, d6
 *   @0x1946bc bl 0xb66e8 <lrint@plt>
 *   @0x1946c0 str r8, [sp]
 *   @0x1946c4 mov r1, r9
 *   @0x1946c8 vstr s18, [sp, #4]
 *   @0x1946cc str r11, [sp, #0x8]
 *   @0x1946d0 mov r3, r6
 *   @0x1946d4 str r10, [sp, #0xc]
 *   @0x1946d8 add r2, r4, #232
 *   @0x1946dc str r7, [sp, #0x10]
 *   @0x1946e0 str r0, [sp, #0x14]
 *   @0x1946e4 mov r0, r5
 *   @0x1946e8 bl 0x1e4a30 <_ZN7CSprite21PreciseCollisionPointEiP9tagYYRECTiifffii>
 *   @0x1946ec b 0x194640 <_ZN9CInstance15Collision_PointEffb+0x190>
 *   @0x1946f0 eoreq r9, r5, r4, asr #8
 *
 * ══ §20/54 RTree<CInstance*, int, float, 6, 2>::InsertRectRec  0x1cd4bc  size 580  145 条（0x1cd4bc..0x1cd700）
 * @func 0x1cd4bc 0x1cd700  size 580  145 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RTree<CInstance*, int, float, 6, 2>::AddBranch(RTree<CInstance*, int, float, 6, 2>::Branch const*, RTree<CInstance*, int, float, 6, 2>::Node*, RTree<CInstance*, int, float, 6, 2>::Node**)×2 / anon_1cbc10+0x50×2 / RTree<CInstance*, int, float, 6, 2>::InsertRectRec(RTree<CInstance*, int, float, 6, 2>::Branch const&, RTree<CInstance*, int, float, 6, 2>::Node*, RTree<CInstance*, int, float, 6, 2>::Node**, int)+0x154 / RTree<CInstance*, int, float, 6, 2>::InsertRectRec(RTree<CInstance*, int, float, 6, 2>::Branch const&, RTree<CInstance*, int, float, 6, 2>::Node*, RTree<CInstance*, int, float, 6, 2>::Node**, int)
 * 字段偏移 top8: 0xc×6 / 0x4×4 / 0x10×4 / 0x8×4 / 0x14×3 / 0x70×2 / 0x18×2 / 0x2c×1
 * VFP 指令 35 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1cd4bc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1cd4c0 sub sp, sp, #76
 *   @0x1cd4c4 ldr r12, [r2, #0x4]
 *   @0x1cd4c8 mov r5, r2
 *   @0x1cd4cc ldr r4, [sp, #0x70]
 *   @0x1cd4d0 mov r6, r1
 *   @0x1cd4d4 str r0, [sp, #0x10]
 *   @0x1cd4d8 cmp r12, r4
 *   @0x1cd4dc str r3, [sp, #0x14]
 *   @0x1cd4e0 bgt 0x1cd4f4 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13InsertRectRecERKNS2_6BranchEPNS2_4NodeEPS7_i+0x38>
 *   @0x1cd4e4 movne r0, #0
 *   @0x1cd4e8 beq 0x1cd6a0 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13InsertRectRecERKNS2_6BranchEPNS2_4NodeEPS7_i+0x1e4>
 *   @0x1cd4ec add sp, sp, #76
 *   @0x1cd4f0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1cd4f4 ldr r11, [r2]
 *   @0x1cd4f8 cmp r11, #0
 *   @0x1cd4fc ble 0x1cd610 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13InsertRectRecERKNS2_6BranchEPNS2_4NodeEPS7_i+0x154>
 *   @0x1cd500 vmov.f32 s7, #-1.000000e+00
 *   @0x1cd504 ldr r1, [r1]
 *   @0x1cd508 ldr r2, [r6, #0x8]
 *   @0x1cd50c mov r12, r5
 *   @0x1cd510 ldr r3, [r6, #0x4]
 *   @0x1cd514 mov r0, #1
 *   @0x1cd518 ldr r4, [r6, #0xc]
 *   @0x1cd51c mov lr, #0
 *   @0x1cd520 str r5, [sp, #0xc]
 *   @0x1cd524 ldr r10, [r12, #0x10]
 *   @0x1cd528 ldr r5, [r12, #0x8]
 *   @0x1cd52c ldr r8, [r12, #0x14]
 *   @0x1cd530 ldr r9, [r12, #0xc]
 *   @0x1cd534 vmov s10, r10
 *   @0x1cd538 vmov s11, r5
 *   @0x1cd53c cmp r5, r1
 *   @0x1cd540 vcvt.f32.s32 s12, s10
 *   @0x1cd544 vmov s15, r8
 *   @0x1cd548 vmov s10, r9
 *   @0x1cd54c vcvt.f32.s32 s13, s11
 *   @0x1cd550 vcvt.f32.s32 s14, s15
 *   @0x1cd554 vcvt.f32.s32 s15, s10
 *   @0x1cd558 vmovge s10, r1
 *   @0x1cd55c vsub.f32 s6, s12, s13
 *   @0x1cd560 vcvtge.f32.s32 s13, s10
 *   @0x1cd564 cmp r10, r2
 *   @0x1cd568 vmovle s10, r2
 *   @0x1cd56c vsub.f32 s11, s14, s15
 *   @0x1cd570 vcvtle.f32.s32 s12, s10
 *   @0x1cd574 cmp r9, r3
 *   @0x1cd578 vmovge s10, r3
 *   @0x1cd57c vcvtge.f32.s32 s15, s10
 *   @0x1cd580 cmp r8, r4
 *   @0x1cd584 vmovle s10, r4
 *   @0x1cd588 vcvtle.f32.s32 s14, s10
 *   @0x1cd58c vmul.f32 s11, s6, s11
 *   @0x1cd590 vsub.f32 s15, s14, s15
 *   @0x1cd594 vsub.f32 s13, s12, s13
 *   @0x1cd598 vmov.f32 s14, s11
 *   @0x1cd59c vnmls.f32 s14, s13, s15
 *   @0x1cd5a0 vcmpe.f32 s14, s7
 *   @0x1cd5a4 vmov.f32 s15, s14
 *   @0x1cd5a8 vmrs APSR_nzcv, fpscr
 *   @0x1cd5ac bmi 0x1cd5d0 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13InsertRectRecERKNS2_6BranchEPNS2_4NodeEPS7_i+0x114>
 *   @0x1cd5b0 cmp r0, #0
 *   @0x1cd5b4 bne 0x1cd5d0 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13InsertRectRecERKNS2_6BranchEPNS2_4NodeEPS7_i+0x114>
 *   @0x1cd5b8 vcmp.f32 s14, s7
 *   @0x1cd5bc vmrs APSR_nzcv, fpscr
 *   @0x1cd5c0 bne 0x1cd5f4 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13InsertRectRecERKNS2_6BranchEPNS2_4NodeEPS7_i+0x138>
 *   @0x1cd5c4 vcmpe.f32 s11, s5
 *   @0x1cd5c8 vmrs APSR_nzcv, fpscr
 *   @0x1cd5cc bpl 0x1cd5f4 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13InsertRectRecERKNS2_6BranchEPNS2_4NodeEPS7_i+0x138>
 *   @0x1cd5d0 mov r7, lr
 *   @0x1cd5d4 add lr, lr, #1
 *   @0x1cd5d8 cmp lr, r11
 *   @0x1cd5dc add r12, r12, #24
 *   @0x1cd5e0 beq 0x1cd60c <_ZN5RTreeIP9CInstanceifLi6ELi2EE13InsertRectRecERKNS2_6BranchEPNS2_4NodeEPS7_i+0x150>
 *   @0x1cd5e4 vmov.f32 s5, s11
 *   @0x1cd5e8 mov r0, #0
 *   @0x1cd5ec vmov.f32 s7, s15
 *   @0x1cd5f0 b 0x1cd524 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13InsertRectRecERKNS2_6BranchEPNS2_4NodeEPS7_i+0x68>
 *   @0x1cd5f4 add lr, lr, #1
 *   @0x1cd5f8 vmov.f32 s11, s5
 *   @0x1cd5fc cmp lr, r11
 *   @0x1cd600 add r12, r12, #24
 *   @0x1cd604 vmov.f32 s15, s7
 *   @0x1cd608 bne 0x1cd5e4 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13InsertRectRecERKNS2_6BranchEPNS2_4NodeEPS7_i+0x128>
 *   @0x1cd60c ldr r5, [sp, #0xc]
 *   @0x1cd610 ldr r4, [sp, #0x70]
 *   @0x1cd614 add r7, r7, r7, lsl #1
 *   @0x1cd618 ldr r0, [sp, #0x10]
 *   @0x1cd61c mov r1, r6
 *   @0x1cd620 lsl r7, r7, #3
 *   @0x1cd624 add r3, sp, #44
 *   @0x1cd628 str r4, [sp]
 *   @0x1cd62c add r4, r5, r7
 *   @0x1cd630 ldr r2, [r4, #0x18]
 *   @0x1cd634 bl 0x1cd4bc <_ZN5RTreeIP9CInstanceifLi6ELi2EE13InsertRectRecERKNS2_6BranchEPNS2_4NodeEPS7_i>
 *   @0x1cd638 cmp r0, #0
 *   @0x1cd63c bne 0x1cd6ac <_ZN5RTreeIP9CInstanceifLi6ELi2EE13InsertRectRecERKNS2_6BranchEPNS2_4NodeEPS7_i+0x1f0>
 *   @0x1cd640 add r2, r7, #8
 *   @0x1cd644 ldr r4, [r6, #0x8]
 *   @0x1cd648 add r3, r5, r2
 *   @0x1cd64c ldr r8, [r6, #0x4]
 *   @0x1cd650 ldr r1, [r6, #0xc]
 *   @0x1cd654 ldr r10, [r5, r2]
 *   @0x1cd658 ldr r6, [r6]
 *   @0x1cd65c ldr r7, [r3, #0x8]
 *   @0x1cd660 ldr r9, [r3, #0x4]
 *   @0x1cd664 ldr r12, [r3, #0xc]
 *   @0x1cd668 cmp r10, r6
 *   @0x1cd66c strle r10, [r5, r2]
 *   @0x1cd670 strgt r6, [r5, r2]
 *   @0x1cd674 cmp r9, r8
 *   @0x1cd678 strle r9, [r3, #0x4]
 *   @0x1cd67c strgt r8, [r3, #0x4]
 *   @0x1cd680 cmp r7, r4
 *   @0x1cd684 strge r7, [r3, #0x8]
 *   @0x1cd688 strlt r4, [r3, #0x8]
 *   @0x1cd68c cmp r12, r1
 *   @0x1cd690 strge r12, [r3, #0xc]
 *   @0x1cd694 strlt r1, [r3, #0xc]
 *   @0x1cd698 add sp, sp, #76
 *   @0x1cd69c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1cd6a0 bl 0x1cd45c <_ZN5RTreeIP9CInstanceifLi6ELi2EE9AddBranchEPKNS2_6BranchEPNS2_4NodeEPS7_>
 *   @0x1cd6a4 add sp, sp, #76
 *   @0x1cd6a8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1cd6ac ldr r1, [r4, #0x18]
 *   @0x1cd6b0 add r6, r4, #8
 *   @0x1cd6b4 add r4, sp, #24
 *   @0x1cd6b8 mov r0, r4
 *   @0x1cd6bc bl 0x1cbc60 <_Z19FINALIZE_Run_Globalv+0x1f4>
 *   @0x1cd6c0 ldm r4, {r0, r1, r2, r3}
 *   @0x1cd6c4 ldr r12, [sp, #0x2c]
 *   @0x1cd6c8 stm r6, {r0, r1, r2, r3}
 *   @0x1cd6cc mov r0, r4
 *   @0x1cd6d0 mov r1, r12
 *   @0x1cd6d4 str r12, [sp, #0x40]
 *   @0x1cd6d8 bl 0x1cbc60 <_Z19FINALIZE_Run_Globalv+0x1f4>
 *   @0x1cd6dc ldm r4, {r0, r1, r2, r3}
 *   @0x1cd6e0 add r12, sp, #48
 *   @0x1cd6e4 stm r12, {r0, r1, r2, r3}
 *   @0x1cd6e8 mov r1, r12
 *   @0x1cd6ec ldr r0, [sp, #0x10]
 *   @0x1cd6f0 mov r2, r5
 *   @0x1cd6f4 ldr r3, [sp, #0x14]
 *   @0x1cd6f8 bl 0x1cd45c <_ZN5RTreeIP9CInstanceifLi6ELi2EE9AddBranchEPKNS2_6BranchEPNS2_4NodeEPS7_>
 *   @0x1cd6fc b 0x1cd4ec <_ZN5RTreeIP9CInstanceifLi6ELi2EE13InsertRectRecERKNS2_6BranchEPNS2_4NodeEPS7_i+0x30>
 *
 * ══ §21/54 anon_289294  0x289294  size 564  141 条（0x289294..0x2894c8）
 * @func 0x289294 0x2894c8  size 564  141 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_289294+0xc4×2 / anon_289294 / 0xb6c28 / anon_289294+0x120 / anon_289294+0x108
 * 字段偏移 top8: 0x4×10 / 0x54×7 / 0xc×3 / 0x60×3 / 0x68×3 / 0x8×3 / 0x10×2 / 0x64×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x289294 push {r4, r5, r6, r7, r8, lr}
 *   @0x289298 subs r7, r1, #0
 *   @0x28929c pople {r4, r5, r6, r7, r8, pc}
 *   @0x2892a0 mov r5, #0
 *   @0x2892a4 sub r6, r0, #4
 *   @0x2892a8 mov r8, r5
 *   @0x2892ac b 0x2892bc <spRegionAttachment_computeWorldVertices+0x148>
 *   @0x2892b0 cmp r5, r7
 *   @0x2892b4 str r8, [r4, #0x54]
 *   @0x2892b8 beq 0x2892e8 <spRegionAttachment_computeWorldVertices+0x174>
 *   @0x2892bc ldr r4, [r6, #0x4]!
 *   @0x2892c0 add r5, r5, #1
 *   @0x2892c4 ldr r3, [r4, #0x54]
 *   @0x2892c8 cmp r3, #0
 *   @0x2892cc beq 0x2892b0 <spRegionAttachment_computeWorldVertices+0x13c>
 *   @0x2892d0 ldr r0, [r4, #0x10]
 *   @0x2892d4 ldr r1, [r4, #0xc]
 *   @0x2892d8 bl 0x289294 <spRegionAttachment_computeWorldVertices+0x120>
 *   @0x2892dc cmp r5, r7
 *   @0x2892e0 str r8, [r4, #0x54]
 *   @0x2892e4 bne 0x2892bc <spRegionAttachment_computeWorldVertices+0x148>
 *   @0x2892e8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2892ec push {r4, r5, lr}
 *   @0x2892f0 mov r5, r1
 *   @0x2892f4 ldr r3, [r0, #0x60]
 *   @0x2892f8 sub sp, sp, #12
 *   @0x2892fc ldr r1, [r0, #0x64]
 *   @0x289300 mov r4, r0
 *   @0x289304 cmp r3, r1
 *   @0x289308 beq 0x28932c <spRegionAttachment_computeWorldVertices+0x1b8>
 *   @0x28930c ldr r12, [r0, #0x68]
 *   @0x289310 add r1, r12, r3, lsl #3
 *   @0x289314 str r5, [r12, r3, lsl #3]
 *   @0x289318 add r3, r3, #1
 *   @0x28931c str r2, [r1, #0x4]
 *   @0x289320 str r3, [r4, #0x60]
 *   @0x289324 add sp, sp, #12
 *   @0x289328 pop {r4, r5, pc}
 *   @0x28932c lsl r0, r3, #1
 *   @0x289330 lsl r1, r3, #4
 *   @0x289334 str r0, [r4, #0x64]
 *   @0x289338 ldr r0, [r4, #0x68]
 *   @0x28933c str r2, [sp, #0x4]
 *   @0x289340 bl 0xb6c28 <realloc@plt>
 *   @0x289344 ldr r3, [r4, #0x60]
 *   @0x289348 ldr r2, [sp, #0x4]
 *   @0x28934c mov r12, r0
 *   @0x289350 str r0, [r4, #0x68]
 *   @0x289354 b 0x289310 <spRegionAttachment_computeWorldVertices+0x19c>
 *   @0x289358 push {r3, r4, r5, lr}
 *   @0x28935c mov r4, r1
 *   @0x289360 ldr r1, [r1, #0x8]
 *   @0x289364 mov r5, r0
 *   @0x289368 cmp r1, #0
 *   @0x28936c beq 0x289380 <spRegionAttachment_computeWorldVertices+0x20c>
 *   @0x289370 ldr r3, [r1, #0x54]
 *   @0x289374 cmp r3, #0
 *   @0x289378 bne 0x289380 <spRegionAttachment_computeWorldVertices+0x20c>
 *   @0x28937c bl 0x289358 <spRegionAttachment_computeWorldVertices+0x1e4>
 *   @0x289380 mov r3, #1
 *   @0x289384 mov r0, r5
 *   @0x289388 mov r2, r4
 *   @0x28938c str r3, [r4, #0x54]
 *   @0x289390 mov r1, #0
 *   @0x289394 pop {r3, r4, r5, lr}
 *   @0x289398 b 0x2892ec <spRegionAttachment_computeWorldVertices+0x178>
 *   @0x28939c ldr r3, [r1, #0x4]
 *   @0x2893a0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2893a4 cmp r3, #4
 *   @0x2893a8 sub sp, sp, #12
 *   @0x2893ac mov r7, r0
 *   @0x2893b0 beq 0x2893bc <spRegionAttachment_computeWorldVertices+0x248>
 *   @0x2893b4 add sp, sp, #12
 *   @0x2893b8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2893bc ldr r8, [r1, #0x14]
 *   @0x2893c0 ldr r1, [r1, #0x10]
 *   @0x2893c4 cmp r8, #0
 *   @0x2893c8 str r1, [sp, #0x4]
 *   @0x2893cc beq 0x289458 <spRegionAttachment_computeWorldVertices+0x2e4>
 *   @0x2893d0 ldr r3, [sp, #0x4]
 *   @0x2893d4 ldr r11, [r0, #0x8]
 *   @0x2893d8 cmp r3, #0
 *   @0x2893dc ble 0x2893b4 <spRegionAttachment_computeWorldVertices+0x240>
 *   @0x2893e0 mov r9, #0
 *   @0x2893e4 ldr r10, [r8, r9, lsl #2]
 *   @0x2893e8 add r6, r9, #1
 *   @0x2893ec add r5, r8, r9, lsl #2
 *   @0x2893f0 add r10, r6, r10
 *   @0x2893f4 cmp r6, r10
 *   @0x2893f8 bge 0x289450 <spRegionAttachment_computeWorldVertices+0x2dc>
 *   @0x2893fc mov r4, r6
 *   @0x289400 b 0x28940c <spRegionAttachment_computeWorldVertices+0x298>
 *   @0x289404 cmp r4, r10
 *   @0x289408 beq 0x289434 <spRegionAttachment_computeWorldVertices+0x2c0>
 *   @0x28940c ldr r3, [r5, #0x4]!
 *   @0x289410 add r4, r4, #1
 *   @0x289414 ldr r1, [r11, r3, lsl #2]
 *   @0x289418 ldr r3, [r1, #0x54]
 *   @0x28941c cmp r3, #0
 *   @0x289420 bne 0x289404 <spRegionAttachment_computeWorldVertices+0x290>
 *   @0x289424 mov r0, r7
 *   @0x289428 bl 0x289358 <spRegionAttachment_computeWorldVertices+0x1e4>
 *   @0x28942c cmp r4, r10
 *   @0x289430 bne 0x28940c <spRegionAttachment_computeWorldVertices+0x298>
 *   @0x289434 rsb r2, r9, r6
 *   @0x289438 sub r2, r2, #1
 *   @0x28943c add r9, r2, r4
 *   @0x289440 ldr r3, [sp, #0x4]
 *   @0x289444 cmp r3, r9
 *   @0x289448 bgt 0x2893e4 <spRegionAttachment_computeWorldVertices+0x270>
 *   @0x28944c b 0x2893b4 <spRegionAttachment_computeWorldVertices+0x240>
 *   @0x289450 mov r9, r6
 *   @0x289454 b 0x289440 <spRegionAttachment_computeWorldVertices+0x2cc>
 *   @0x289458 ldr r3, [r2, #0x54]
 *   @0x28945c cmp r3, #0
 *   @0x289460 bne 0x2893b4 <spRegionAttachment_computeWorldVertices+0x240>
 *   @0x289464 mov r1, r2
 *   @0x289468 add sp, sp, #12
 *   @0x28946c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x289470 b 0x289358 <spRegionAttachment_computeWorldVertices+0x1e4>
 *   @0x289474 push {r3, r4, r5, r6, r7, lr}
 *   @0x289478 mov r6, r0
 *   @0x28947c ldr r4, [r1, #0x4]
 *   @0x289480 mov r5, r2
 *   @0x289484 mov r7, r3
 *   @0x289488 cmp r4, #0
 *   @0x28948c bne 0x2894a0 <spRegionAttachment_computeWorldVertices+0x32c>
 *   @0x289490 pop {r3, r4, r5, r6, r7, pc}
 *   @0x289494 ldr r4, [r4, #0xc]
 *   @0x289498 cmp r4, #0
 *   @0x28949c beq 0x2894c8 <spRegionAttachment_computeWorldVertices+0x354>
 *   @0x2894a0 ldr r1, [r4]
 *   @0x2894a4 cmp r1, r5
 *   @0x2894a8 bne 0x289494 <spRegionAttachment_computeWorldVertices+0x320>
 *   @0x2894ac ldr r1, [r4, #0x8]
 *   @0x2894b0 mov r0, r6
 *   @0x2894b4 mov r2, r7
 *   @0x2894b8 bl 0x28939c <spRegionAttachment_computeWorldVertices+0x228>
 *   @0x2894bc ldr r4, [r4, #0xc]
 *   @0x2894c0 cmp r4, #0
 *   @0x2894c4 bne 0x2894a0 <spRegionAttachment_computeWorldVertices+0x32c>
 *
 * ══ §22/54 RValue::DeSerialise  0xcf6e4  size 560  140 条（0xcf6e4..0xcf914）
 * @func 0xcf6e4 0xcf914  size 560  140 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×4 / MemoryManager::SetLength(void**, unsigned int, char const*, int)×2 / IBuffer::ReadString() / ARRAY_RefAlloc(void*) / RValue::DeSerialise(IBuffer*)+0x1c4 / RValue::DeSerialise(IBuffer*)
 * 字段偏移 top8: 0xc×7 / 0x10×4 / 0x4×3 / 0x2c×2 / 0x3×2 / 0x30×1 / 0x140×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcf6e4 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xcf6e8 mov r4, #0
 *   @0xcf6ec str r4, [r0]
 *   @0xcf6f0 add r9, r1, #44
 *   @0xcf6f4 str r4, [r0, #0x4]
 *   @0xcf6f8 mov r8, r0
 *   @0xcf6fc ldr r3, [r1]
 *   @0xcf700 mov r0, r1
 *   @0xcf704 mov r2, r9
 *   @0xcf708 mov r6, r1
 *   @0xcf70c mov r1, #6
 *   @0xcf710 ldr r3, [r3, #0xc]
 *   @0xcf714 blx r3
 *   @0xcf718 mov r0, r9
 *   @0xcf71c mov r1, r4
 *   @0xcf720 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xcf724 str r0, [r8, #0xc]
 *   @0xcf728 cmp r0, #13
 *   @0xcf72c addls pc, pc, r0, lsl #2
 *   @0xcf730 b 0xcf76c <_ZN6RValue11DeSerialiseEP7IBuffer+0x88>
 *   @0xcf734 b 0xcf798 <_ZN6RValue11DeSerialiseEP7IBuffer+0xb4>
 *   @0xcf738 b 0xcf7ac <_ZN6RValue11DeSerialiseEP7IBuffer+0xc8>
 *   @0xcf73c b 0xcf7c4 <_ZN6RValue11DeSerialiseEP7IBuffer+0xe0>
 *   @0xcf740 b 0xcf8c0 <_ZN6RValue11DeSerialiseEP7IBuffer+0x1dc>
 *   @0xcf744 b 0xcf76c <_ZN6RValue11DeSerialiseEP7IBuffer+0x88>
 *   @0xcf748 b 0xcf76c <_ZN6RValue11DeSerialiseEP7IBuffer+0x88>
 *   @0xcf74c b 0xcf76c <_ZN6RValue11DeSerialiseEP7IBuffer+0x88>
 *   @0xcf750 b 0xcf8e4 <_ZN6RValue11DeSerialiseEP7IBuffer+0x200>
 *   @0xcf754 b 0xcf76c <_ZN6RValue11DeSerialiseEP7IBuffer+0x88>
 *   @0xcf758 b 0xcf76c <_ZN6RValue11DeSerialiseEP7IBuffer+0x88>
 *   @0xcf75c b 0xcf770 <_ZN6RValue11DeSerialiseEP7IBuffer+0x8c>
 *   @0xcf760 b 0xcf76c <_ZN6RValue11DeSerialiseEP7IBuffer+0x88>
 *   @0xcf764 b 0xcf76c <_ZN6RValue11DeSerialiseEP7IBuffer+0x88>
 *   @0xcf768 b 0xcf798 <_ZN6RValue11DeSerialiseEP7IBuffer+0xb4>
 *   @0xcf76c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xcf770 ldr r3, [r6]
 *   @0xcf774 mov r2, r9
 *   @0xcf778 mov r0, r6
 *   @0xcf77c mov r1, #12
 *   @0xcf780 ldr r3, [r3, #0xc]
 *   @0xcf784 blx r3
 *   @0xcf788 ldr r2, [r6, #0x2c]
 *   @0xcf78c ldr r3, [r6, #0x30]
 *   @0xcf790 stm r8, {r2, r3}
 *   @0xcf794 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xcf798 ldr r3, [r6]
 *   @0xcf79c mov r2, r9
 *   @0xcf7a0 mov r0, r6
 *   @0xcf7a4 mov r1, #9
 *   @0xcf7a8 b 0xcf780 <_ZN6RValue11DeSerialiseEP7IBuffer+0x9c>
 *   @0xcf7ac mov r0, r6
 *   @0xcf7b0 bl 0xcde74 <_ZN7IBuffer10ReadStringEv>
 *   @0xcf7b4 mov r1, r0
 *   @0xcf7b8 mov r0, r8
 *   @0xcf7bc pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xcf7c0 b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0xcf7c4 mov r0, r8
 *   @0xcf7c8 ldr r10, [pc, #0x140]
 *   @0xcf7cc bl 0xced9c <_Z14ARRAY_RefAllocPv>
 *   @0xcf7d0 mov r2, r9
 *   @0xcf7d4 mov r1, #6
 *   @0xcf7d8 add r10, pc, r10
 *   @0xcf7dc str r0, [r8]
 *   @0xcf7e0 mov r4, r0
 *   @0xcf7e4 ldr r3, [r6]
 *   @0xcf7e8 mov r0, r6
 *   @0xcf7ec ldr r3, [r3, #0xc]
 *   @0xcf7f0 blx r3
 *   @0xcf7f4 mov r1, #0
 *   @0xcf7f8 mov r0, r9
 *   @0xcf7fc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xcf800 mov r2, r10
 *   @0xcf804 movw r3, #0x766
 *   @0xcf808 str r0, [r4, #0x10]
 *   @0xcf80c ldr r1, [r8]
 *   @0xcf810 add r0, r1, #4
 *   @0xcf814 ldr r1, [r1, #0x10]
 *   @0xcf818 lsl r1, r1, #3
 *   @0xcf81c bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xcf820 ldr r3, [r8]
 *   @0xcf824 ldr r2, [r3, #0x10]
 *   @0xcf828 cmp r2, #0
 *   @0xcf82c pople {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xcf830 mov r7, #0
 *   @0xcf834 ldr r12, [r6]
 *   @0xcf838 mov r2, r9
 *   @0xcf83c ldr r4, [r3, #0x4]
 *   @0xcf840 mov r1, #6
 *   @0xcf844 mov r0, r6
 *   @0xcf848 ldr r3, [r12, #0xc]
 *   @0xcf84c add r5, r4, r7, lsl #3
 *   @0xcf850 blx r3
 *   @0xcf854 mov r1, #0
 *   @0xcf858 mov r0, r9
 *   @0xcf85c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xcf860 movw r3, #0x76c
 *   @0xcf864 mov r2, r10
 *   @0xcf868 str r0, [r4, r7, lsl #3]
 *   @0xcf86c lsl r1, r0, #4
 *   @0xcf870 add r0, r5, #4
 *   @0xcf874 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xcf878 ldr r3, [r4, r7, lsl #3]
 *   @0xcf87c cmp r3, #0
 *   @0xcf880 movgt r4, #0
 *   @0xcf884 ble 0xcf8a8 <_ZN6RValue11DeSerialiseEP7IBuffer+0x1c4>
 *   @0xcf888 ldr r0, [r5, #0x4]
 *   @0xcf88c mov r1, r6
 *   @0xcf890 add r0, r0, r4, lsl #4
 *   @0xcf894 add r4, r4, #1
 *   @0xcf898 bl 0xcf6e4 <_ZN6RValue11DeSerialiseEP7IBuffer>
 *   @0xcf89c ldr r3, [r5]
 *   @0xcf8a0 cmp r3, r4
 *   @0xcf8a4 bgt 0xcf888 <_ZN6RValue11DeSerialiseEP7IBuffer+0x1a4>
 *   @0xcf8a8 ldr r3, [r8]
 *   @0xcf8ac add r7, r7, #1
 *   @0xcf8b0 ldr r2, [r3, #0x10]
 *   @0xcf8b4 cmp r2, r7
 *   @0xcf8b8 bgt 0xcf834 <_ZN6RValue11DeSerialiseEP7IBuffer+0x150>
 *   @0xcf8bc pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xcf8c0 ldr r3, [r6]
 *   @0xcf8c4 mov r2, r9
 *   @0xcf8c8 mov r0, r6
 *   @0xcf8cc mov r1, #12
 *   @0xcf8d0 ldr r3, [r3, #0xc]
 *   @0xcf8d4 blx r3
 *   @0xcf8d8 ldr r3, [r6, #0x2c]
 *   @0xcf8dc str r3, [r8]
 *   @0xcf8e0 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xcf8e4 ldr r3, [r6]
 *   @0xcf8e8 mov r1, #6
 *   @0xcf8ec mov r2, r9
 *   @0xcf8f0 mov r0, r6
 *   @0xcf8f4 ldr r3, [r3, #0xc]
 *   @0xcf8f8 blx r3
 *   @0xcf8fc mov r0, r9
 *   @0xcf900 mov r1, #0
 *   @0xcf904 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xcf908 str r0, [r8]
 *   @0xcf90c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xcf910 eoreq r2, r6, r4, lsr #20
 *
 * ══ §23/54 HandleGestures  0x1db590  size 556  139 条（0x1db590..0x1db7bc）
 * @func 0x1db590 0x1db7bc  size 556  139 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×3 / ProcessGestureEvents()×2 / CGestureEvent::~CGestureEvent() / operator delete(void*) / Timing_Time / UpdateTouchActions(long long) / MemoryManager::Alloc(unsigned int, char const*, int, bool) / AddSingleFingerGestures(long long)
 * 字段偏移 top8: 0x8×13 / 0x4×2 / 0x210×1 / 0x200×1 / 0x1a8×1 / 0x180×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1db590 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1db594 ldr r3, [pc, #0x210]
 *   @0x1db598 ldr r3, [pc, r3]
 *   @0x1db59c ldrb r3, [r3]
 *   @0x1db5a0 cmp r3, #0
 *   @0x1db5a4 popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1db5a8 ldr r7, [pc, #0x200]
 *   @0x1db5ac ldr r7, [pc, r7]
 *   @0x1db5b0 ldr r4, [r7]
 *   @0x1db5b4 cmp r4, #0
 *   @0x1db5b8 beq 0x1db5f0 <_Z14HandleGesturesv+0x60>
 *   @0x1db5bc ldr r5, [r4, #0x8]
 *   @0x1db5c0 ldr r6, [r4]
 *   @0x1db5c4 cmp r5, #0
 *   @0x1db5c8 mov r0, r5
 *   @0x1db5cc beq 0x1db5dc <_Z14HandleGesturesv+0x4c>
 *   @0x1db5d0 bl 0x1db510 <_ZN13CGestureEventD2Ev>
 *   @0x1db5d4 mov r0, r5
 *   @0x1db5d8 bl 0x27d1d0 <_ZdlPv>
 *   @0x1db5dc mov r0, r4
 *   @0x1db5e0 mov r4, r6
 *   @0x1db5e4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1db5e8 cmp r6, #0
 *   @0x1db5ec bne 0x1db5bc <_Z14HandleGesturesv+0x2c>
 *   @0x1db5f0 mov r9, #0
 *   @0x1db5f4 str r9, [r7, #0x8]
 *   @0x1db5f8 str r9, [r7, #0x4]
 *   @0x1db5fc str r9, [r7]
 *   @0x1db600 bl 0x215148 <Timing_Time>
 *   @0x1db604 ldr r8, [pc, #0x1a8]
 *   @0x1db608 mov r4, r0
 *   @0x1db60c mov r5, r1
 *   @0x1db610 bl 0x1d7908 <_Z18UpdateTouchActionsx>
 *   @0x1db614 ldr r8, [pc, r8]
 *   @0x1db618 ldr r6, [r8]
 *   @0x1db61c cmp r6, r9
 *   @0x1db620 beq 0x1db7a4 <_Z14HandleGesturesv+0x214>
 *   @0x1db624 ldr r3, [r6, #0x8]
 *   @0x1db628 cmp r3, #0
 *   @0x1db62c beq 0x1db7a4 <_Z14HandleGesturesv+0x214>
 *   @0x1db630 ldr r10, [pc, #0x180]
 *   @0x1db634 mov r7, r9
 *   @0x1db638 add r10, pc, r10
 *   @0x1db63c b 0x1db658 <_Z14HandleGesturesv+0xc8>
 *   @0x1db640 ldr r6, [r6]
 *   @0x1db644 cmp r6, #0
 *   @0x1db648 beq 0x1db6c8 <_Z14HandleGesturesv+0x138>
 *   @0x1db64c ldr r3, [r6, #0x8]
 *   @0x1db650 cmp r3, #0
 *   @0x1db654 beq 0x1db6c8 <_Z14HandleGesturesv+0x138>
 *   @0x1db658 ldr r11, [r6, #0x8]
 *   @0x1db65c mov r3, r5
 *   @0x1db660 mov r2, r4
 *   @0x1db664 ldr r1, [r11]
 *   @0x1db668 mov r0, r11
 *   @0x1db66c ldr r1, [r1, #0x8]
 *   @0x1db670 blx r1
 *   @0x1db674 ldr r3, [r11, #0x14]
 *   @0x1db678 strd r4, r5, [r11, #32]
 *   @0x1db67c cmn r3, #1
 *   @0x1db680 bne 0x1db640 <_Z14HandleGesturesv+0xb0>
 *   @0x1db684 mov r3, #1
 *   @0x1db688 mov r0, #12
 *   @0x1db68c mov r1, r10
 *   @0x1db690 mov r2, #143
 *   @0x1db694 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1db698 cmp r9, #0
 *   @0x1db69c movne r3, #0
 *   @0x1db6a0 streq r9, [r0, #0x4]
 *   @0x1db6a4 streq r9, [r0]
 *   @0x1db6a8 moveq r9, r0
 *   @0x1db6ac str r11, [r0, #0x8]
 *   @0x1db6b0 moveq r7, r9
 *   @0x1db6b4 strne r0, [r9]
 *   @0x1db6b8 strne r9, [r0, #0x4]
 *   @0x1db6bc movne r9, r0
 *   @0x1db6c0 strne r3, [r0]
 *   @0x1db6c4 b 0x1db640 <_Z14HandleGesturesv+0xb0>
 *   @0x1db6c8 bl 0x1d719c <_Z20ProcessGestureEventsv>
 *   @0x1db6cc cmp r7, #0
 *   @0x1db6d0 beq 0x1db788 <_Z14HandleGesturesv+0x1f8>
 *   @0x1db6d4 ldr r3, [r7, #0x8]
 *   @0x1db6d8 cmp r3, #0
 *   @0x1db6dc beq 0x1db770 <_Z14HandleGesturesv+0x1e0>
 *   @0x1db6e0 mov r9, r7
 *   @0x1db6e4 ldr r6, [r8]
 *   @0x1db6e8 ldr r2, [r9, #0x8]
 *   @0x1db6ec cmp r6, #0
 *   @0x1db6f0 bne 0x1db704 <_Z14HandleGesturesv+0x174>
 *   @0x1db6f4 b 0x1db758 <_Z14HandleGesturesv+0x1c8>
 *   @0x1db6f8 ldr r6, [r6]
 *   @0x1db6fc cmp r6, #0
 *   @0x1db700 beq 0x1db758 <_Z14HandleGesturesv+0x1c8>
 *   @0x1db704 ldr r0, [r6, #0x8]
 *   @0x1db708 cmp r2, r0
 *   @0x1db70c bne 0x1db6f8 <_Z14HandleGesturesv+0x168>
 *   @0x1db710 ldm r6, {r1, r2}
 *   @0x1db714 cmp r2, #0
 *   @0x1db718 strne r1, [r2]
 *   @0x1db71c ldrne r1, [r6]
 *   @0x1db720 streq r1, [r8]
 *   @0x1db724 cmp r1, #0
 *   @0x1db728 streq r2, [r8, #0x4]
 *   @0x1db72c strne r2, [r1, #0x4]
 *   @0x1db730 cmp r0, #0
 *   @0x1db734 beq 0x1db744 <_Z14HandleGesturesv+0x1b4>
 *   @0x1db738 ldr r2, [r0]
 *   @0x1db73c ldr r3, [r2, #0x4]
 *   @0x1db740 blx r3
 *   @0x1db744 mov r0, r6
 *   @0x1db748 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1db74c ldr r3, [r8, #0x8]
 *   @0x1db750 sub r3, r3, #1
 *   @0x1db754 str r3, [r8, #0x8]
 *   @0x1db758 ldr r9, [r9]
 *   @0x1db75c cmp r9, #0
 *   @0x1db760 beq 0x1db770 <_Z14HandleGesturesv+0x1e0>
 *   @0x1db764 ldr r3, [r9, #0x8]
 *   @0x1db768 cmp r3, #0
 *   @0x1db76c bne 0x1db6e4 <_Z14HandleGesturesv+0x154>
 *   @0x1db770 ldr r6, [r7]
 *   @0x1db774 mov r0, r7
 *   @0x1db778 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1db77c cmp r6, #0
 *   @0x1db780 mov r7, r6
 *   @0x1db784 bne 0x1db770 <_Z14HandleGesturesv+0x1e0>
 *   @0x1db788 mov r0, r4
 *   @0x1db78c mov r1, r5
 *   @0x1db790 bl 0x1d8e1c <_Z23AddSingleFingerGesturesx>
 *   @0x1db794 mov r0, r4
 *   @0x1db798 mov r1, r5
 *   @0x1db79c pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1db7a0 b 0x1d87bc <_Z22AddMultiFingerGesturesx>
 *   @0x1db7a4 bl 0x1d719c <_Z20ProcessGestureEventsv>
 *   @0x1db7a8 b 0x1db788 <_Z14HandleGesturesv+0x1f8>
 *   @0x1db7ac eoreq r2, r1, r12, lsl #7
 *   @0x1db7b0 eoreq r5, r1, r4, asr r6
 *   @0x1db7b4 eoreq r5, r1, r0, lsl #12
 *   @0x1db7b8 ldrsheq r1, [r7], -r8
 *
 * ══ §24/54 yyMatrix::Multiply  0x27aa00  size 556  139 条（0x27aa00..0x27ac2c）
 * @func 0x27aa00 0x27ac2c  size 556  139 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 138 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27aa00 vldr s13, [r1, #4]
 *   @0x27aa04 vldr s12, [r2, #16]
 *   @0x27aa08 vmul.f32 s11, s13, s12
 *   @0x27aa0c vpush {d8, d9, d10, d11, d12, d13, d14}
 *   @0x27aa10 vldr s6, [r2]
 *   @0x27aa14 vldr s21, [r1]
 *   @0x27aa18 vldr s2, [r1, #8]
 *   @0x27aa1c vldr s24, [r2, #32]
 *   @0x27aa20 vldr s9, [r1, #12]
 *   @0x27aa24 vldr s4, [r2, #48]
 *   @0x27aa28 vldr s1, [r2, #20]
 *   @0x27aa2c vldr s3, [r1, #28]
 *   @0x27aa30 vldr s23, [r2, #36]
 *   @0x27aa34 vldr s5, [r2, #52]
 *   @0x27aa38 vldr s20, [r2, #40]
 *   @0x27aa3c vldr s17, [r1, #24]
 *   @0x27aa40 vldr s7, [r2, #56]
 *   @0x27aa44 vldr s8, [r2, #60]
 *   @0x27aa48 vldr s0, [r2, #44]
 *   @0x27aa4c vldr s18, [r2, #4]
 *   @0x27aa50 vldr s10, [r2, #24]
 *   @0x27aa54 vldr s14, [r1, #20]
 *   @0x27aa58 vldr s19, [r2, #8]
 *   @0x27aa5c vldr s22, [r1, #16]
 *   @0x27aa60 vldr s15, [r2, #28]
 *   @0x27aa64 vldr s16, [r2, #12]
 *   @0x27aa68 vmla.f32 s11, s21, s6
 *   @0x27aa6c vmla.f32 s11, s2, s24
 *   @0x27aa70 vmla.f32 s11, s9, s4
 *   @0x27aa74 vmul.f32 s13, s13, s1
 *   @0x27aa78 vstr s11, [r0]
 *   @0x27aa7c vldr s6, [r1]
 *   @0x27aa80 vldr s21, [r2]
 *   @0x27aa84 vmla.f32 s13, s6, s18
 *   @0x27aa88 vmla.f32 s13, s2, s23
 *   @0x27aa8c vmla.f32 s13, s9, s5
 *   @0x27aa90 vmul.f32 s12, s12, s14
 *   @0x27aa94 vstr s13, [r0, #4]
 *   @0x27aa98 vldr s13, [r1, #4]
 *   @0x27aa9c vldr s18, [r2, #4]
 *   @0x27aaa0 vmul.f32 s11, s13, s10
 *   @0x27aaa4 vmla.f32 s12, s21, s22
 *   @0x27aaa8 vmla.f32 s11, s6, s19
 *   @0x27aaac vmla.f32 s12, s24, s17
 *   @0x27aab0 vmla.f32 s11, s2, s20
 *   @0x27aab4 vmla.f32 s12, s4, s3
 *   @0x27aab8 vmla.f32 s11, s9, s7
 *   @0x27aabc vmul.f32 s13, s13, s15
 *   @0x27aac0 vstr s11, [r0, #8]
 *   @0x27aac4 vldr s11, [r1, #8]
 *   @0x27aac8 vstr s12, [r0, #16]
 *   @0x27aacc vldr s22, [r1, #16]
 *   @0x27aad0 vldr s28, [r1, #32]
 *   @0x27aad4 vldr s19, [r1, #40]
 *   @0x27aad8 vldr s12, [r1, #52]
 *   @0x27aadc vldr s26, [r1, #48]
 *   @0x27aae0 vmul.f32 s14, s1, s14
 *   @0x27aae4 vldr s1, [r1, #56]
 *   @0x27aae8 vmla.f32 s13, s6, s16
 *   @0x27aaec vldr s16, [r2, #8]
 *   @0x27aaf0 vldr s6, [r1, #44]
 *   @0x27aaf4 vmla.f32 s14, s22, s18
 *   @0x27aaf8 vmla.f32 s13, s0, s11
 *   @0x27aafc vldr s11, [r2, #16]
 *   @0x27ab00 vmla.f32 s14, s23, s17
 *   @0x27ab04 vmla.f32 s13, s9, s8
 *   @0x27ab08 vldr s9, [r1, #60]
 *   @0x27ab0c vmla.f32 s14, s5, s3
 *   @0x27ab10 vstr s13, [r0, #12]
 *   @0x27ab14 vldr s13, [r1, #36]
 *   @0x27ab18 vldr s2, [r2, #12]
 *   @0x27ab1c vstr s14, [r0, #20]
 *   @0x27ab20 vmul.f32 s14, s13, s11
 *   @0x27ab24 vldr s27, [r1, #20]
 *   @0x27ab28 vldr s25, [r2, #20]
 *   @0x27ab2c vmul.f32 s10, s10, s27
 *   @0x27ab30 vmla.f32 s14, s21, s28
 *   @0x27ab34 vmla.f32 s10, s22, s16
 *   @0x27ab38 vmla.f32 s14, s24, s19
 *   @0x27ab3c vmla.f32 s10, s20, s17
 *   @0x27ab40 vmla.f32 s14, s4, s6
 *   @0x27ab44 vmla.f32 s10, s7, s3
 *   @0x27ab48 vmul.f32 s13, s13, s25
 *   @0x27ab4c vstr s10, [r0, #24]
 *   @0x27ab50 vldr s24, [r1, #24]
 *   @0x27ab54 vstr s14, [r0, #32]
 *   @0x27ab58 vldr s17, [r1, #32]
 *   @0x27ab5c vldr s14, [r2, #24]
 *   @0x27ab60 vldr s28, [r2, #32]
 *   @0x27ab64 vmla.f32 s13, s18, s17
 *   @0x27ab68 vmla.f32 s13, s23, s19
 *   @0x27ab6c vmla.f32 s13, s5, s6
 *   @0x27ab70 vmul.f32 s15, s15, s27
 *   @0x27ab74 vstr s13, [r0, #36]
 *   @0x27ab78 vldr s13, [r1, #36]
 *   @0x27ab7c vldr s23, [r2, #36]
 *   @0x27ab80 vmul.f32 s10, s13, s14
 *   @0x27ab84 vmul.f32 s11, s11, s12
 *   @0x27ab88 vmla.f32 s15, s22, s2
 *   @0x27ab8c vmla.f32 s11, s21, s26
 *   @0x27ab90 vmla.f32 s10, s16, s17
 *   @0x27ab94 vmla.f32 s15, s0, s24
 *   @0x27ab98 vmla.f32 s11, s1, s28
 *   @0x27ab9c vmla.f32 s10, s20, s19
 *   @0x27aba0 vmla.f32 s15, s8, s3
 *   @0x27aba4 vmla.f32 s11, s4, s9
 *   @0x27aba8 vstr s15, [r0, #28]
 *   @0x27abac vldr s4, [r2, #28]
 *   @0x27abb0 vmla.f32 s10, s7, s6
 *   @0x27abb4 vmul.f32 s12, s25, s12
 *   @0x27abb8 vstr s10, [r0, #40]
 *   @0x27abbc vldr s3, [r1, #40]
 *   @0x27abc0 vstr s11, [r0, #48]
 *   @0x27abc4 vldr s11, [r1, #48]
 *   @0x27abc8 vldr s10, [r2, #40]
 *   @0x27abcc vmla.f32 s12, s18, s11
 *   @0x27abd0 vmla.f32 s12, s1, s23
 *   @0x27abd4 vmla.f32 s12, s5, s9
 *   @0x27abd8 vmul.f32 s13, s13, s4
 *   @0x27abdc vstr s12, [r0, #52]
 *   @0x27abe0 vldr s15, [r1, #52]
 *   @0x27abe4 vmul.f32 s14, s14, s15
 *   @0x27abe8 vmla.f32 s13, s2, s17
 *   @0x27abec vmla.f32 s14, s16, s11
 *   @0x27abf0 vmla.f32 s13, s0, s3
 *   @0x27abf4 vmla.f32 s14, s1, s10
 *   @0x27abf8 vmul.f32 s15, s4, s15
 *   @0x27abfc vmla.f32 s13, s8, s6
 *   @0x27ac00 vmla.f32 s14, s7, s9
 *   @0x27ac04 vstr s13, [r0, #44]
 *   @0x27ac08 vldr s13, [r2, #44]
 *   @0x27ac0c vpop {d8, d9, d10, d11, d12, d13, d14}
 *   @0x27ac10 vmla.f32 s15, s2, s11
 *   @0x27ac14 vstr s14, [r0, #56]
 *   @0x27ac18 vldr s14, [r1, #56]
 *   @0x27ac1c vmla.f32 s15, s14, s13
 *   @0x27ac20 vmla.f32 s15, s8, s9
 *   @0x27ac24 vstr s15, [r0, #60]
 *   @0x27ac28 bx lr
 *
 * ══ §25/54 yyMatrix::LookAtLH  0x27acb0  size 556  139 条（0x27acb0..0x27aedc）
 * @func 0x27acb0 0x27aedc  size 556  139 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6700×4
 * 字段偏移 top8: 0xc×1 / 0x1c×1 / 0x2c×1 / 0x4×1
 * VFP 指令 109 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27acb0 push {r4, lr}
 *   @0x27acb4 vpush {d8, d9, d10, d11, d12}
 *   @0x27acb8 vldr s18, [r2, #4]
 *   @0x27acbc vldr s15, [r1, #4]
 *   @0x27acc0 vsub.f32 s18, s18, s15
 *   @0x27acc4 vldr s17, [r2]
 *   @0x27acc8 vldr s13, [r1]
 *   @0x27accc vldr s19, [r2, #8]
 *   @0x27acd0 vldr s14, [r1, #8]
 *   @0x27acd4 sub sp, sp, #8
 *   @0x27acd8 mov r4, r0
 *   @0x27acdc vmul.f32 s15, s18, s18
 *   @0x27ace0 vsub.f32 s17, s17, s13
 *   @0x27ace4 vmla.f32 s15, s17, s17
 *   @0x27ace8 vsub.f32 s19, s19, s14
 *   @0x27acec vmla.f32 s15, s19, s19
 *   @0x27acf0 vsqrt.f32 s11, s15
 *   @0x27acf4 vcmp.f32 s11, s11
 *   @0x27acf8 vmrs APSR_nzcv, fpscr
 *   @0x27acfc bne 0x27ae6c <_ZN8yyMatrix8LookAtLHEPS_P9yyVector3S2_S2_+0x1bc>
 *   @0x27ad00 vldr s14, [r3, #4]
 *   @0x27ad04 vmul.f32 s15, s14, s14
 *   @0x27ad08 vldr s13, [r3]
 *   @0x27ad0c vldr s20, [r3, #8]
 *   @0x27ad10 vmla.f32 s15, s13, s13
 *   @0x27ad14 vmla.f32 s15, s20, s20
 *   @0x27ad18 vmov.f32 s16, #1.000000e+00
 *   @0x27ad1c vsqrt.f32 s12, s15
 *   @0x27ad20 vdiv.f32 s16, s16, s11
 *   @0x27ad24 vcmp.f32 s12, s12
 *   @0x27ad28 vmul.f32 s17, s17, s16
 *   @0x27ad2c vmrs APSR_nzcv, fpscr
 *   @0x27ad30 vmul.f32 s18, s18, s16
 *   @0x27ad34 vmul.f32 s16, s19, s16
 *   @0x27ad38 bne 0x27aeb4 <_ZN8yyMatrix8LookAtLHEPS_P9yyVector3S2_S2_+0x204>
 *   @0x27ad3c vmov.f32 s21, #1.000000e+00
 *   @0x27ad40 vdiv.f32 s12, s21, s12
 *   @0x27ad44 vmul.f32 s13, s12, s13
 *   @0x27ad48 vmul.f32 s20, s12, s20
 *   @0x27ad4c vmul.f32 s19, s16, s13
 *   @0x27ad50 vmul.f32 s12, s12, s14
 *   @0x27ad54 vnmls.f32 s19, s17, s20
 *   @0x27ad58 vmul.f32 s20, s18, s20
 *   @0x27ad5c vnmls.f32 s20, s16, s12
 *   @0x27ad60 vmul.f32 s21, s17, s12
 *   @0x27ad64 vmul.f32 s15, s19, s19
 *   @0x27ad68 vnmls.f32 s21, s18, s13
 *   @0x27ad6c vmla.f32 s15, s20, s20
 *   @0x27ad70 vmla.f32 s15, s21, s21
 *   @0x27ad74 vsqrt.f32 s14, s15
 *   @0x27ad78 vcmp.f32 s14, s14
 *   @0x27ad7c vmrs APSR_nzcv, fpscr
 *   @0x27ad80 bne 0x27ae9c <_ZN8yyMatrix8LookAtLHEPS_P9yyVector3S2_S2_+0x1ec>
 *   @0x27ad84 vmov.f32 s24, #1.000000e+00
 *   @0x27ad88 vdiv.f32 s24, s24, s14
 *   @0x27ad8c vmul.f32 s22, s21, s24
 *   @0x27ad90 vmul.f32 s23, s20, s24
 *   @0x27ad94 vmul.f32 s21, s17, s22
 *   @0x27ad98 vmul.f32 s24, s19, s24
 *   @0x27ad9c vnmls.f32 s21, s16, s23
 *   @0x27ada0 vmul.f32 s20, s16, s24
 *   @0x27ada4 vnmls.f32 s20, s18, s22
 *   @0x27ada8 vmul.f32 s15, s21, s21
 *   @0x27adac vmul.f32 s19, s18, s23
 *   @0x27adb0 vmla.f32 s15, s20, s20
 *   @0x27adb4 vnmls.f32 s19, s17, s24
 *   @0x27adb8 vmla.f32 s15, s19, s19
 *   @0x27adbc vsqrt.f32 s14, s15
 *   @0x27adc0 vcmp.f32 s14, s14
 *   @0x27adc4 vmrs APSR_nzcv, fpscr
 *   @0x27adc8 bne 0x27ae84 <_ZN8yyMatrix8LookAtLHEPS_P9yyVector3S2_S2_+0x1d4>
 *   @0x27adcc vmov.f32 s15, #1.000000e+00
 *   @0x27add0 vldr s10, [r1, #4]
 *   @0x27add4 vldr s11, [r1]
 *   @0x27add8 vldr s13, [r1, #8]
 *   @0x27addc vstr s18, [r4, #24]
 *   @0x27ade0 mov r3, #0
 *   @0x27ade4 vstr s23, [r4]
 *   @0x27ade8 vstr s17, [r4, #8]
 *   @0x27adec vstr s24, [r4, #16]
 *   @0x27adf0 vstr s22, [r4, #32]
 *   @0x27adf4 vstr s16, [r4, #40]
 *   @0x27adf8 str r3, [r4, #0xc]
 *   @0x27adfc str r3, [r4, #0x1c]
 *   @0x27ae00 str r3, [r4, #0x2c]
 *   @0x27ae04 vdiv.f32 s12, s15, s14
 *   @0x27ae08 vstr s15, [r4, #60]
 *   @0x27ae0c vmul.f32 s21, s21, s12
 *   @0x27ae10 vmul.f32 s20, s20, s12
 *   @0x27ae14 vstr s21, [r4, #20]
 *   @0x27ae18 vmul.f32 s14, s10, s21
 *   @0x27ae1c vstr s20, [r4, #4]
 *   @0x27ae20 vmul.f32 s15, s10, s24
 *   @0x27ae24 vmul.f32 s18, s10, s18
 *   @0x27ae28 vmla.f32 s14, s11, s20
 *   @0x27ae2c vmla.f32 s15, s11, s23
 *   @0x27ae30 vmla.f32 s18, s11, s17
 *   @0x27ae34 vmul.f32 s19, s19, s12
 *   @0x27ae38 vmla.f32 s15, s13, s22
 *   @0x27ae3c vstr s19, [r4, #36]
 *   @0x27ae40 vmla.f32 s14, s13, s19
 *   @0x27ae44 vmla.f32 s18, s13, s16
 *   @0x27ae48 vneg.f32 s14, s14
 *   @0x27ae4c vneg.f32 s15, s15
 *   @0x27ae50 vstr s14, [r4, #52]
 *   @0x27ae54 vneg.f32 s18, s18
 *   @0x27ae58 vstr s15, [r4, #48]
 *   @0x27ae5c vstr s18, [r4, #56]
 *   @0x27ae60 add sp, sp, #8
 *   @0x27ae64 vpop {d8, d9, d10, d11, d12}
 *   @0x27ae68 pop {r4, pc}
 *   @0x27ae6c vmov r0, s15
 *   @0x27ae70 stm sp, {r1, r3}
 *   @0x27ae74 bl 0xb6700 <sqrtf@plt>
 *   @0x27ae78 ldm sp, {r1, r3}
 *   @0x27ae7c vmov s11, r0
 *   @0x27ae80 b 0x27ad00 <_ZN8yyMatrix8LookAtLHEPS_P9yyVector3S2_S2_+0x50>
 *   @0x27ae84 vmov r0, s15
 *   @0x27ae88 str r1, [sp]
 *   @0x27ae8c bl 0xb6700 <sqrtf@plt>
 *   @0x27ae90 ldr r1, [sp]
 *   @0x27ae94 vmov s14, r0
 *   @0x27ae98 b 0x27adcc <_ZN8yyMatrix8LookAtLHEPS_P9yyVector3S2_S2_+0x11c>
 *   @0x27ae9c vmov r0, s15
 *   @0x27aea0 str r1, [sp]
 *   @0x27aea4 bl 0xb6700 <sqrtf@plt>
 *   @0x27aea8 ldr r1, [sp]
 *   @0x27aeac vmov s14, r0
 *   @0x27aeb0 b 0x27ad84 <_ZN8yyMatrix8LookAtLHEPS_P9yyVector3S2_S2_+0xd4>
 *   @0x27aeb4 vmov r0, s15
 *   @0x27aeb8 stm sp, {r1, r3}
 *   @0x27aebc bl 0xb6700 <sqrtf@plt>
 *   @0x27aec0 ldr r3, [sp, #0x4]
 *   @0x27aec4 vldr s13, [r3]
 *   @0x27aec8 vldr s14, [r3, #4]
 *   @0x27aecc vldr s20, [r3, #8]
 *   @0x27aed0 ldr r1, [sp]
 *   @0x27aed4 vmov s12, r0
 *   @0x27aed8 b 0x27ad3c <_ZN8yyMatrix8LookAtLHEPS_P9yyVector3S2_S2_+0x8c>
 *
 * ══ §26/54 Extension_Initialize  0xf63f0  size 544  136 条（0xf63f0..0xf6610）
 * @func 0xf63f0 0xf6610  size 544  136 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65b0×2 / CInstance::~CInstance()×2 / Error_Show(char const*, bool)×2 / Extension_Initialize()+0x184 / CExtensionPackage::GetIncludesCount() / CExtensionPackage::GetIncludesFile(int) / CExtensionFile::GetFunction_Init() / CInstance::CInstance(float, float, int, int, bool)
 * 字段偏移 top8: 0x14×4 / 0xc×4 / 0x4×3 / 0x6e4×2 / 0x10×2 / 0x1c×2 / 0x1fc×1 / 0x1e0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf63f0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xf63f4 sub sp, sp, #1760
 *   @0xf63f8 ldr r12, [pc, #0x1fc]
 *   @0xf63fc sub sp, sp, #12
 *   @0xf6400 add r8, sp, #48
 *   @0xf6404 mov r1, #0
 *   @0xf6408 mov r2, #256
 *   @0xf640c mov r10, #0
 *   @0xf6410 str r12, [sp, #0x14]
 *   @0xf6414 mov r0, r8
 *   @0xf6418 ldr r12, [pc, #0x1e0]
 *   @0xf641c str r12, [sp, #0xc]
 *   @0xf6420 ldr r12, [sp, #0x14]
 *   @0xf6424 ldr r12, [pc, r12]
 *   @0xf6428 str r12, [sp, #0x14]
 *   @0xf642c ldr r3, [r12]
 *   @0xf6430 str r3, [sp, #0x6e4]
 *   @0xf6434 bl 0xb65b0 <memset@plt>
 *   @0xf6438 ldr r12, [sp, #0xc]
 *   @0xf643c str r10, [sp, #0x20]
 *   @0xf6440 ldr r12, [pc, r12]
 *   @0xf6444 str r10, [sp, #0x24]
 *   @0xf6448 str r12, [sp, #0xc]
 *   @0xf644c ldr r3, [r12]
 *   @0xf6450 str r10, [sp, #0x28]
 *   @0xf6454 cmp r3, r10
 *   @0xf6458 str r10, [sp, #0x2c]
 *   @0xf645c ble 0xf6574 <_Z20Extension_Initializev+0x184>
 *   @0xf6460 ldr r12, [pc, #0x19c]
 *   @0xf6464 add r6, sp, #304
 *   @0xf6468 add r9, sp, #32
 *   @0xf646c add r12, pc, r12
 *   @0xf6470 str r12, [sp, #0x10]
 *   @0xf6474 ldr r12, [sp, #0x10]
 *   @0xf6478 ldr r3, [r12, #0x4]
 *   @0xf647c ldr r5, [r3, r10, lsl #2]
 *   @0xf6480 cmp r5, #0
 *   @0xf6484 movne r4, #0
 *   @0xf6488 movne r7, r4
 *   @0xf648c bne 0xf6498 <_Z20Extension_Initializev+0xa8>
 *   @0xf6490 b 0xf6560 <_Z20Extension_Initializev+0x170>
 *   @0xf6494 add r4, r4, #1
 *   @0xf6498 mov r0, r5
 *   @0xf649c bl 0xf5630 <_ZN17CExtensionPackage16GetIncludesCountEv>
 *   @0xf64a0 cmp r4, r0
 *   @0xf64a4 bge 0xf6560 <_Z20Extension_Initializev+0x170>
 *   @0xf64a8 mov r1, r4
 *   @0xf64ac mov r0, r5
 *   @0xf64b0 bl 0xf5800 <_ZN17CExtensionPackage15GetIncludesFileEi>
 *   @0xf64b4 bl 0xf4ff0 <_ZN14CExtensionFile16GetFunction_InitEv>
 *   @0xf64b8 subs r11, r0, #0
 *   @0xf64bc beq 0xf6494 <_Z20Extension_Initializev+0xa4>
 *   @0xf64c0 ldrb r3, [r11]
 *   @0xf64c4 cmp r3, #0
 *   @0xf64c8 beq 0xf6494 <_Z20Extension_Initializev+0xa4>
 *   @0xf64cc mov r1, #0
 *   @0xf64d0 mov r3, #0
 *   @0xf64d4 mov r2, r1
 *   @0xf64d8 mov r0, r6
 *   @0xf64dc str r7, [sp]
 *   @0xf64e0 mov r12, #16
 *   @0xf64e4 str r7, [sp, #0x4]
 *   @0xf64e8 str r12, [sp, #0x18]
 *   @0xf64ec str r8, [sp, #0x1c]
 *   @0xf64f0 bl 0x1994dc <_ZN9CInstanceC2Effiib>
 *   @0xf64f4 mov r0, r11
 *   @0xf64f8 bl 0x1e0610 <_Z11Script_FindPKc>
 *   @0xf64fc cmp r0, #0
 *   @0xf6500 blt 0xf6534 <_Z20Extension_Initializev+0x144>
 *   @0xf6504 add r3, sp, #24
 *   @0xf6508 str r9, [sp]
 *   @0xf650c str r3, [sp, #0x4]
 *   @0xf6510 mov r1, r6
 *   @0xf6514 mov r2, r6
 *   @0xf6518 mov r3, #0
 *   @0xf651c bl 0x1e0774 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue>
 *   @0xf6520 cmp r0, #0
 *   @0xf6524 beq 0xf657c <_Z20Extension_Initializev+0x18c>
 *   @0xf6528 mov r0, r6
 *   @0xf652c bl 0x199320 <_ZN9CInstanceD2Ev>
 *   @0xf6530 b 0xf6494 <_Z20Extension_Initializev+0xa4>
 *   @0xf6534 mov r1, r11
 *   @0xf6538 mov r0, r5
 *   @0xf653c bl 0xf5494 <_ZN17CExtensionPackage16FunctionFindNameEPKc>
 *   @0xf6540 subs r1, r0, #0
 *   @0xf6544 beq 0xf65c0 <_Z20Extension_Initializev+0x1d0>
 *   @0xf6548 bl 0xf4c28 <_ZN18CExtensionFunction5GetIdEv>
 *   @0xf654c mov r1, #0
 *   @0xf6550 ldr r2, [sp, #0x1c]
 *   @0xf6554 mov r3, r9
 *   @0xf6558 bl 0xf6344 <_Z27Extension_Call_DLL_FunctioniiP6RValueS0_>
 *   @0xf655c b 0xf6528 <_Z20Extension_Initializev+0x138>
 *   @0xf6560 ldr r12, [sp, #0xc]
 *   @0xf6564 add r10, r10, #1
 *   @0xf6568 ldr r3, [r12]
 *   @0xf656c cmp r3, r10
 *   @0xf6570 bgt 0xf6474 <_Z20Extension_Initializev+0x84>
 *   @0xf6574 mov r0, #1
 *   @0xf6578 b 0xf65a0 <_Z20Extension_Initializev+0x1b0>
 *   @0xf657c ldr r3, [pc, #0x84]
 *   @0xf6580 mov r1, #1
 *   @0xf6584 ldr r3, [pc, r3]
 *   @0xf6588 ldr r3, [r3]
 *   @0xf658c ldr r0, [r3]
 *   @0xf6590 bl 0xecd7c <_Z10Error_ShowPKcb>
 *   @0xf6594 mov r0, r6
 *   @0xf6598 bl 0x199320 <_ZN9CInstanceD2Ev>
 *   @0xf659c mov r0, #0
 *   @0xf65a0 ldr r12, [sp, #0x14]
 *   @0xf65a4 ldr r2, [sp, #0x6e4]
 *   @0xf65a8 ldr r3, [r12]
 *   @0xf65ac cmp r2, r3
 *   @0xf65b0 bne 0xf65f8 <_Z20Extension_Initializev+0x208>
 *   @0xf65b4 add sp, sp, #1760
 *   @0xf65b8 add sp, sp, #12
 *   @0xf65bc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xf65c0 add r4, sp, #740
 *   @0xf65c4 mov r2, #1024
 *   @0xf65c8 mov r0, r4
 *   @0xf65cc bl 0xb65b0 <memset@plt>
 *   @0xf65d0 ldr r2, [pc, #0x34]
 *   @0xf65d4 mov r0, r4
 *   @0xf65d8 mov r3, r11
 *   @0xf65dc mov r1, #1024
 *   @0xf65e0 add r2, pc, r2
 *   @0xf65e4 bl 0xb65c8 <snprintf@plt>
 *   @0xf65e8 mov r0, r4
 *   @0xf65ec mov r1, #1
 *   @0xf65f0 bl 0xecd7c <_Z10Error_ShowPKcb>
 *   @0xf65f4 b 0xf6594 <_Z20Extension_Initializev+0x1a4>
 *   @0xf65f8 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0xf65fc eoreq r7, pc, r12, lsr #10
 *   @0xf6600 .word 0x002f79f4
 *   @0xf6604 ldrsbteq sp, [r8], -r12
 *   @0xf6608 eoreq r7, pc, r12, ror #11
 *   @0xf660c eoreq r1, r4, r4, asr #7
 *
 * ══ §27/54 YYObjectBase::Alloc  0x19198c  size 544  136 条（0x19198c..0x191bac）
 * @func 0x19198c 0x191bac  size 544  136 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)×2 / YYObjectBase::Alloc(unsigned int, int, bool)+0x128 / YYObjectBase::Alloc(unsigned int, int, bool)+0x7c / YYObjectBase::Alloc(unsigned int, int, bool)+0xf4 / YYRealloc(void*, int) / 0xb65b0 / operator new(unsigned int) / YYObjectBase::YYObjectBase(int, int)
 * 字段偏移 top8: 0x4×7 / 0xc×4 / 0x2c×3 / 0x8×3 / 0x24×2 / 0x58×2 / 0x204×1 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19198c ldr r3, [pc, #0x204]
 *   @0x191990 push {r4, r5, r6, r7, r8, lr}
 *   @0x191994 ldr r3, [pc, r3]
 *   @0x191998 sub sp, sp, #8
 *   @0x19199c mov r6, r0
 *   @0x1919a0 ldr r5, [r3]
 *   @0x1919a4 mov r4, r1
 *   @0x1919a8 mov r7, r2
 *   @0x1919ac cmp r5, #0
 *   @0x1919b0 beq 0x191b2c <_ZN12YYObjectBase5AllocEjib+0x1a0>
 *   @0x1919b4 ldr r1, [r5, #0x2c]
 *   @0x1919b8 ldr r2, [r5, #0x8]
 *   @0x1919bc cmp r1, r0
 *   @0x1919c0 str r2, [r3]
 *   @0x1919c4 blo 0x191ab4 <_ZN12YYObjectBase5AllocEjib+0x128>
 *   @0x1919c8 cmp r4, #5
 *   @0x1919cc mov r3, #0
 *   @0x1919d0 str r6, [r5, #0x24]
 *   @0x1919d4 str r4, [r5, #0x58]
 *   @0x1919d8 str r3, [r5, #0x48]
 *   @0x1919dc beq 0x191a08 <_ZN12YYObjectBase5AllocEjib+0x7c>
 *   @0x1919e0 ldr r3, [r5, #0x4]
 *   @0x1919e4 cmp r3, #0
 *   @0x1919e8 beq 0x191a08 <_ZN12YYObjectBase5AllocEjib+0x7c>
 *   @0x1919ec cmp r6, #0
 *   @0x1919f0 mov r12, r6
 *   @0x1919f4 ble 0x191a08 <_ZN12YYObjectBase5AllocEjib+0x7c>
 *   @0x1919f8 subs r12, r12, #1
 *   @0x1919fc str r4, [r3, #0xc]
 *   @0x191a00 add r3, r3, #16
 *   @0x191a04 bne 0x1919f8 <_ZN12YYObjectBase5AllocEjib+0x6c>
 *   @0x191a08 cmp r7, #0
 *   @0x191a0c beq 0x191a1c <_ZN12YYObjectBase5AllocEjib+0x90>
 *   @0x191a10 ldr r0, [r5, #0x4]
 *   @0x191a14 cmp r0, #0
 *   @0x191a18 beq 0x191b48 <_ZN12YYObjectBase5AllocEjib+0x1bc>
 *   @0x191a1c ldr r6, [pc, #0x178]
 *   @0x191a20 ldr r6, [pc, r6]
 *   @0x191a24 ldmib r6, {r4, r7}
 *   @0x191a28 cmp r7, r4
 *   @0x191a2c bge 0x191ae8 <_ZN12YYObjectBase5AllocEjib+0x15c>
 *   @0x191a30 cmp r4, #0
 *   @0x191a34 ldr r3, [r6, #0xc]
 *   @0x191a38 ble 0x191a80 <_ZN12YYObjectBase5AllocEjib+0xf4>
 *   @0x191a3c ldr r12, [r6]
 *   @0x191a40 mov r1, r4
 *   @0x191a44 b 0x191a54 <_ZN12YYObjectBase5AllocEjib+0xc8>
 *   @0x191a48 subs r1, r1, #1
 *   @0x191a4c add r3, r3, #1
 *   @0x191a50 beq 0x191a80 <_ZN12YYObjectBase5AllocEjib+0xf4>
 *   @0x191a54 cmp r4, r3
 *   @0x191a58 lsl r2, r3, #2
 *   @0x191a5c movle r3, #0
 *   @0x191a60 movle r2, r3
 *   @0x191a64 add r0, r12, r2
 *   @0x191a68 ldr r2, [r12, r2]
 *   @0x191a6c cmp r2, #0
 *   @0x191a70 bne 0x191a48 <_ZN12YYObjectBase5AllocEjib+0xbc>
 *   @0x191a74 str r5, [r0]
 *   @0x191a78 str r3, [r6, #0xc]
 *   @0x191a7c b 0x191a84 <_ZN12YYObjectBase5AllocEjib+0xf8>
 *   @0x191a80 mvn r3, #0
 *   @0x191a84 ldr r2, [pc, #0x114]
 *   @0x191a88 add r7, r7, #1
 *   @0x191a8c str r3, [r5, #0x44]
 *   @0x191a90 mov r3, #0
 *   @0x191a94 ldr r2, [pc, r2]
 *   @0x191a98 str r3, [r5, #0x38]
 *   @0x191a9c mov r0, r5
 *   @0x191aa0 str r7, [r6, #0x8]
 *   @0x191aa4 ldr r3, [r2]
 *   @0x191aa8 str r3, [r5, #0x3c]
 *   @0x191aac add sp, sp, #8
 *   @0x191ab0 pop {r4, r5, r6, r7, r8, pc}
 *   @0x191ab4 cmp r7, #0
 *   @0x191ab8 str r0, [r5, #0x2c]
 *   @0x191abc beq 0x1919c8 <_ZN12YYObjectBase5AllocEjib+0x3c>
 *   @0x191ac0 ldr r2, [pc, #0xdc]
 *   @0x191ac4 mov r3, #0
 *   @0x191ac8 ldr r0, [r5, #0x4]
 *   @0x191acc lsl r1, r6, #4
 *   @0x191ad0 str r3, [sp]
 *   @0x191ad4 add r2, pc, r2
 *   @0x191ad8 mov r3, #74
 *   @0x191adc bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x191ae0 str r0, [r5, #0x4]
 *   @0x191ae4 b 0x1919c8 <_ZN12YYObjectBase5AllocEjib+0x3c>
 *   @0x191ae8 add r4, r4, r4, lsl #1
 *   @0x191aec ldr r0, [r6]
 *   @0x191af0 add r4, r4, r4, lsr #31
 *   @0x191af4 asr r8, r4, #1
 *   @0x191af8 lsl r1, r8, #2
 *   @0x191afc mov r4, r8
 *   @0x191b00 bl 0xcef64 <_Z9YYReallocPvi>
 *   @0x191b04 ldr r3, [r6, #0x4]
 *   @0x191b08 mov r1, #0
 *   @0x191b0c rsb r2, r3, r8
 *   @0x191b10 lsl r2, r2, #2
 *   @0x191b14 str r0, [r6]
 *   @0x191b18 add r0, r0, r3, lsl #2
 *   @0x191b1c bl 0xb65b0 <memset@plt>
 *   @0x191b20 ldr r7, [r6, #0x8]
 *   @0x191b24 str r8, [r6, #0x4]
 *   @0x191b28 b 0x191a30 <_ZN12YYObjectBase5AllocEjib+0xa4>
 *   @0x191b2c mov r0, #100
 *   @0x191b30 bl 0x27c524 <_Znwj>
 *   @0x191b34 mov r1, r6
 *   @0x191b38 mov r2, r4
 *   @0x191b3c mov r5, r0
 *   @0x191b40 bl 0x19188c <_ZN12YYObjectBaseC2Eii>
 *   @0x191b44 b 0x191a08 <_ZN12YYObjectBase5AllocEjib+0x7c>
 *   @0x191b48 ldr r2, [pc, #0x58]
 *   @0x191b4c lsl r1, r6, #4
 *   @0x191b50 str r0, [sp]
 *   @0x191b54 mov r3, #74
 *   @0x191b58 add r2, pc, r2
 *   @0x191b5c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x191b60 cmp r4, #5
 *   @0x191b64 str r6, [r5, #0x2c]
 *   @0x191b68 str r0, [r5, #0x4]
 *   @0x191b6c beq 0x191a1c <_ZN12YYObjectBase5AllocEjib+0x90>
 *   @0x191b70 cmp r0, #0
 *   @0x191b74 beq 0x191a1c <_ZN12YYObjectBase5AllocEjib+0x90>
 *   @0x191b78 ldr r3, [r5, #0x24]
 *   @0x191b7c cmp r3, #0
 *   @0x191b80 ble 0x191a1c <_ZN12YYObjectBase5AllocEjib+0x90>
 *   @0x191b84 subs r3, r3, #1
 *   @0x191b88 str r4, [r0, #0xc]
 *   @0x191b8c add r0, r0, #16
 *   @0x191b90 bne 0x191b84 <_ZN12YYObjectBase5AllocEjib+0x1f8>
 *   @0x191b94 b 0x191a1c <_ZN12YYObjectBase5AllocEjib+0x90>
 *   @0x191b98 eoreq r12, r5, r12, ror r2
 *   @0x191b9c eoreq r12, r5, r4, asr #4
 *   @0x191ba0 .word 0x0025c1b8
 *   @0x191ba4 andseq pc, r9, r12, asr r5
 *   @0x191ba8 ldrsbeq pc, [r9], -r8
 *
 * ══ §28/54 ExecutePreDrawEvent  0x1b3718  size 544  136 条（0x1b3718..0x1b3938）
 * @func 0x1b3718 0x1b3938  size 544  136 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ExecuteLayerScript(int, int, int, int)×2 / CObjectGM::HasEventRecursive(int, int)×2 / Perform_Event(CInstance*, CInstance*, int, int)×2 / GR_Window_Get_Color()×2 / GR_Draw_Clear(unsigned int)×2 / DirtyRoomExtents() / ExecutePreDrawEvent(tagYYRECT*, int, int, bool)+0x160 / SetLayerShader(int)
 * 字段偏移 top8: 0x6c×2 / 0x28×2 / 0x20×2 / 0x14×2 / 0x69×2 / 0x68×2 / 0x65×2 / 0x80×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b3718 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1b371c mov r7, r1
 *   @0x1b3720 mov r8, r2
 *   @0x1b3724 mov r10, r3
 *   @0x1b3728 ldm r0, {r0, r1, r2, r3}
 *   @0x1b372c ldr r12, [pc, #0x1fc]
 *   @0x1b3730 ldr r12, [pc, r12]
 *   @0x1b3734 stm r12, {r0, r1, r2, r3}
 *   @0x1b3738 bl 0x168d7c <_Z16DirtyRoomExtentsv>
 *   @0x1b373c ldr r3, [pc, #0x1f0]
 *   @0x1b3740 ldr r3, [pc, r3]
 *   @0x1b3744 ldr r3, [r3]
 *   @0x1b3748 cmp r3, #0
 *   @0x1b374c beq 0x1b3878 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x160>
 *   @0x1b3750 ldr r2, [r3, #0xdc]
 *   @0x1b3754 cmp r2, #0
 *   @0x1b3758 ble 0x1b3878 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x160>
 *   @0x1b375c ldr r5, [r3, #0xd8]
 *   @0x1b3760 cmp r5, #0
 *   @0x1b3764 beq 0x1b3920 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x208>
 *   @0x1b3768 mov r9, #0
 *   @0x1b376c b 0x1b377c <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x64>
 *   @0x1b3770 ldr r5, [r5, #0x6c]
 *   @0x1b3774 cmp r5, #0
 *   @0x1b3778 beq 0x1b3870 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x158>
 *   @0x1b377c ldrb r3, [r5, #0x18]
 *   @0x1b3780 cmp r3, #0
 *   @0x1b3784 beq 0x1b3770 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x58>
 *   @0x1b3788 ldr r0, [r5, #0x28]
 *   @0x1b378c bl 0x1b1128 <_Z14SetLayerShaderi>
 *   @0x1b3790 ldr r0, [r5]
 *   @0x1b3794 ldr r1, [r5, #0x20]
 *   @0x1b3798 mov r2, r7
 *   @0x1b379c mov r3, r8
 *   @0x1b37a0 bl 0x1b3418 <_Z18ExecuteLayerScriptiiii>
 *   @0x1b37a4 ldr r4, [r5, #0x58]
 *   @0x1b37a8 cmp r4, #0
 *   @0x1b37ac bne 0x1b37c0 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0xa8>
 *   @0x1b37b0 b 0x1b3848 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x130>
 *   @0x1b37b4 ldr r4, [r4, #0x14]
 *   @0x1b37b8 cmp r4, #0
 *   @0x1b37bc beq 0x1b3848 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x130>
 *   @0x1b37c0 ldr r12, [r4]
 *   @0x1b37c4 cmp r12, #2
 *   @0x1b37c8 bne 0x1b37b4 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x9c>
 *   @0x1b37cc ldr r6, [r4, #0x20]
 *   @0x1b37d0 cmp r6, #0
 *   @0x1b37d4 beq 0x1b37b4 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x9c>
 *   @0x1b37d8 ldrb r3, [r6, #0x69]
 *   @0x1b37dc cmp r3, #0
 *   @0x1b37e0 bne 0x1b3848 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x130>
 *   @0x1b37e4 ldrb r3, [r6, #0x68]
 *   @0x1b37e8 cmp r3, #0
 *   @0x1b37ec bne 0x1b37b4 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x9c>
 *   @0x1b37f0 ldrb r3, [r6, #0x65]
 *   @0x1b37f4 cmp r3, #0
 *   @0x1b37f8 beq 0x1b37b4 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x9c>
 *   @0x1b37fc ldr r0, [r6, #0x80]
 *   @0x1b3800 cmp r0, #0
 *   @0x1b3804 beq 0x1b37b4 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x9c>
 *   @0x1b3808 mov r1, r7
 *   @0x1b380c mov r2, r8
 *   @0x1b3810 bl 0x19dcdc <_ZN9CObjectGM17HasEventRecursiveEii>
 *   @0x1b3814 cmp r0, #0
 *   @0x1b3818 beq 0x1b37b4 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x9c>
 *   @0x1b381c eor r3, r9, #1
 *   @0x1b3820 tst r10, r3
 *   @0x1b3824 bne 0x1b3900 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x1e8>
 *   @0x1b3828 mov r0, r6
 *   @0x1b382c mov r2, r7
 *   @0x1b3830 mov r1, r6
 *   @0x1b3834 mov r3, r8
 *   @0x1b3838 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0x1b383c ldr r4, [r4, #0x14]
 *   @0x1b3840 cmp r4, #0
 *   @0x1b3844 bne 0x1b37c0 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0xa8>
 *   @0x1b3848 ldr r0, [r5]
 *   @0x1b384c mov r2, r7
 *   @0x1b3850 ldr r1, [r5, #0x24]
 *   @0x1b3854 mov r3, r8
 *   @0x1b3858 bl 0x1b3418 <_Z18ExecuteLayerScriptiiii>
 *   @0x1b385c ldr r0, [r5, #0x28]
 *   @0x1b3860 bl 0x1b1170 <_Z16ResetLayerShaderi>
 *   @0x1b3864 ldr r5, [r5, #0x6c]
 *   @0x1b3868 cmp r5, #0
 *   @0x1b386c bne 0x1b377c <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x64>
 *   @0x1b3870 mov r0, r9
 *   @0x1b3874 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1b3878 ldr r4, [r3, #0x84]
 *   @0x1b387c cmp r4, #0
 *   @0x1b3880 beq 0x1b3928 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x210>
 *   @0x1b3884 mov r9, #0
 *   @0x1b3888 ldrb r3, [r4, #0x68]
 *   @0x1b388c cmp r3, #0
 *   @0x1b3890 bne 0x1b38ec <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x1d4>
 *   @0x1b3894 ldrb r3, [r4, #0x69]
 *   @0x1b3898 cmp r3, #0
 *   @0x1b389c bne 0x1b38ec <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x1d4>
 *   @0x1b38a0 ldrb r3, [r4, #0x65]
 *   @0x1b38a4 cmp r3, #0
 *   @0x1b38a8 beq 0x1b38ec <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x1d4>
 *   @0x1b38ac ldr r0, [r4, #0x80]
 *   @0x1b38b0 cmp r0, #0
 *   @0x1b38b4 beq 0x1b38ec <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x1d4>
 *   @0x1b38b8 mov r1, r7
 *   @0x1b38bc mov r2, r8
 *   @0x1b38c0 bl 0x19dcdc <_ZN9CObjectGM17HasEventRecursiveEii>
 *   @0x1b38c4 cmp r0, #0
 *   @0x1b38c8 beq 0x1b38ec <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x1d4>
 *   @0x1b38cc eor r3, r9, #1
 *   @0x1b38d0 tst r10, r3
 *   @0x1b38d4 bne 0x1b3910 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x1f8>
 *   @0x1b38d8 mov r0, r4
 *   @0x1b38dc mov r1, r4
 *   @0x1b38e0 mov r2, r7
 *   @0x1b38e4 mov r3, r8
 *   @0x1b38e8 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0x1b38ec ldr r4, [r4, #0x17c]
 *   @0x1b38f0 cmp r4, #0
 *   @0x1b38f4 bne 0x1b3888 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x170>
 *   @0x1b38f8 mov r0, r9
 *   @0x1b38fc pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1b3900 bl 0x17ae20 <_Z19GR_Window_Get_Colorv>
 *   @0x1b3904 mov r9, #1
 *   @0x1b3908 bl 0x169f58 <_Z13GR_Draw_Clearj>
 *   @0x1b390c b 0x1b3828 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x110>
 *   @0x1b3910 bl 0x17ae20 <_Z19GR_Window_Get_Colorv>
 *   @0x1b3914 mov r9, #1
 *   @0x1b3918 bl 0x169f58 <_Z13GR_Draw_Clearj>
 *   @0x1b391c b 0x1b38d8 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x1c0>
 *   @0x1b3920 mov r9, r5
 *   @0x1b3924 b 0x1b3870 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x158>
 *   @0x1b3928 mov r9, r4
 *   @0x1b392c b 0x1b3870 <_Z19ExecutePreDrawEventP9tagYYRECTiib+0x158>
 *   @0x1b3930 eoreq r12, r3, r12, lsl r10
 *   @0x1b3934 eoreq r10, r3, r8, ror #3
 *
 * ══ §29/54 quorem_D2A  0x23ddac  size 544  136 条（0x23ddac..0x23dfcc）
 * @func 0x23ddac 0x23dfcc  size 544  136 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __udivsi3 / cmp_D2A / quorem_D2A+0x214
 * 字段偏移 top8: 0x10×8 / 0x4×8 / 0x8×4 / 0x2×3 / 0xc×3 / 0x14×2 / 0x18×2 / 0x-4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23ddac push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x23ddb0 sub sp, sp, #60
 *   @0x23ddb4 ldr r3, [r0, #0x10]
 *   @0x23ddb8 mov r12, r0
 *   @0x23ddbc ldr r10, [r1, #0x10]
 *   @0x23ddc0 str r1, [sp, #0x8]
 *   @0x23ddc4 cmp r10, r3
 *   @0x23ddc8 movgt r0, #0
 *   @0x23ddcc bgt 0x23dfc4 <quorem_D2A+0x218>
 *   @0x23ddd0 sub r10, r10, #1
 *   @0x23ddd4 add r8, r1, #20
 *   @0x23ddd8 add r11, r12, #20
 *   @0x23dddc ldr r1, [r8, r10, lsl #2]
 *   @0x23dde0 lsl r7, r10, #2
 *   @0x23dde4 ldr r0, [r11, r10, lsl #2]
 *   @0x23dde8 add r2, r11, r7
 *   @0x23ddec add r1, r1, #1
 *   @0x23ddf0 str r12, [sp, #0x4]
 *   @0x23ddf4 str r2, [sp, #0xc]
 *   @0x23ddf8 bl 0x318c48 <__udivsi3>
 *   @0x23ddfc add r9, r8, r7
 *   @0x23de00 ldr r12, [sp, #0x4]
 *   @0x23de04 cmp r0, #0
 *   @0x23de08 str r0, [sp, #0x10]
 *   @0x23de0c beq 0x23def4 <quorem_D2A+0x148>
 *   @0x23de10 mov r4, #0
 *   @0x23de14 mov r5, #0
 *   @0x23de18 mov lr, r11
 *   @0x23de1c str r10, [sp, #0x14]
 *   @0x23de20 str r7, [sp, #0x1c]
 *   @0x23de24 mov r6, r8
 *   @0x23de28 str r11, [sp, #0x20]
 *   @0x23de2c mov r7, r9
 *   @0x23de30 str r12, [sp, #0x24]
 *   @0x23de34 mov r10, r4
 *   @0x23de38 mov r11, r5
 *   @0x23de3c mov r12, r0
 *   @0x23de40 str r8, [sp, #0x18]
 *   @0x23de44 ldr r3, [r6], #4
 *   @0x23de48 mov r8, r4
 *   @0x23de4c mov r9, r5
 *   @0x23de50 ldr r2, [lr]
 *   @0x23de54 mov r5, #0
 *   @0x23de58 umlal r8, r9, r3, r12
 *   @0x23de5c subs r2, r2, r8
 *   @0x23de60 sbc r3, r2, r2
 *   @0x23de64 subs r2, r2, r10
 *   @0x23de68 sbc r3, r3, r11
 *   @0x23de6c cmp r7, r6
 *   @0x23de70 mov r10, #1
 *   @0x23de74 mov r11, #0
 *   @0x23de78 str r2, [lr], #4
 *   @0x23de7c mov r4, r9
 *   @0x23de80 and r10, r10, r3
 *   @0x23de84 and r11, r11, r5
 *   @0x23de88 bhs 0x23de44 <quorem_D2A+0x98>
 *   @0x23de8c mov r9, r7
 *   @0x23de90 add r7, sp, #28
 *   @0x23de94 ldr r10, [sp, #0x14]
 *   @0x23de98 ldm r7, {r7, r11, r12}
 *   @0x23de9c ldr r8, [sp, #0x18]
 *   @0x23dea0 ldr r3, [r11, r7]
 *   @0x23dea4 cmp r3, r5
 *   @0x23dea8 bne 0x23def4 <quorem_D2A+0x148>
 *   @0x23deac ldr r2, [sp, #0xc]
 *   @0x23deb0 sub r3, r2, #4
 *   @0x23deb4 cmp r11, r3
 *   @0x23deb8 bhs 0x23def0 <quorem_D2A+0x144>
 *   @0x23debc ldr r3, [r2, #-0x4]
 *   @0x23dec0 cmp r3, r5
 *   @0x23dec4 bne 0x23def0 <quorem_D2A+0x144>
 *   @0x23dec8 ldr r2, [sp, #0xc]
 *   @0x23decc sub r5, r2, #8
 *   @0x23ded0 cmp r11, r5
 *   @0x23ded4 mov r3, r5
 *   @0x23ded8 sub r10, r10, #1
 *   @0x23dedc sub r5, r5, #4
 *   @0x23dee0 bhs 0x23def0 <quorem_D2A+0x144>
 *   @0x23dee4 ldr r3, [r3]
 *   @0x23dee8 cmp r3, #0
 *   @0x23deec beq 0x23ded0 <quorem_D2A+0x124>
 *   @0x23def0 str r10, [r12, #0x10]
 *   @0x23def4 mov r0, r12
 *   @0x23def8 ldr r1, [sp, #0x8]
 *   @0x23defc str r12, [sp, #0x4]
 *   @0x23df00 bl 0x23d7c8 <cmp_D2A>
 *   @0x23df04 ldr r12, [sp, #0x4]
 *   @0x23df08 cmp r0, #0
 *   @0x23df0c blt 0x23dfc0 <quorem_D2A+0x214>
 *   @0x23df10 ldr r3, [sp, #0x10]
 *   @0x23df14 mov r4, #0
 *   @0x23df18 str r12, [sp, #0x8]
 *   @0x23df1c mov r5, #0
 *   @0x23df20 mov r12, r9
 *   @0x23df24 mov r6, #1
 *   @0x23df28 mov r9, r8
 *   @0x23df2c mov r7, #0
 *   @0x23df30 mov r8, r11
 *   @0x23df34 add r3, r3, #1
 *   @0x23df38 str r3, [sp, #0x10]
 *   @0x23df3c ldr r3, [r9], #4
 *   @0x23df40 mov r1, #0
 *   @0x23df44 ldr r2, [r8]
 *   @0x23df48 subs r2, r2, r3
 *   @0x23df4c sbc r3, r2, r2
 *   @0x23df50 subs r2, r2, r4
 *   @0x23df54 sbc r3, r3, r5
 *   @0x23df58 cmp r12, r9
 *   @0x23df5c str r2, [r8], #4
 *   @0x23df60 and r4, r3, r6
 *   @0x23df64 and r5, r1, r7
 *   @0x23df68 bhs 0x23df3c <quorem_D2A+0x190>
 *   @0x23df6c ldr r3, [r11, r10, lsl #2]
 *   @0x23df70 add r2, r11, r10, lsl #2
 *   @0x23df74 ldr r12, [sp, #0x8]
 *   @0x23df78 cmp r3, r1
 *   @0x23df7c bne 0x23dfc0 <quorem_D2A+0x214>
 *   @0x23df80 sub r3, r2, #4
 *   @0x23df84 cmp r11, r3
 *   @0x23df88 bhs 0x23dfbc <quorem_D2A+0x210>
 *   @0x23df8c ldr r3, [r2, #-0x4]
 *   @0x23df90 cmp r3, r1
 *   @0x23df94 bne 0x23dfbc <quorem_D2A+0x210>
 *   @0x23df98 sub r2, r2, #8
 *   @0x23df9c cmp r11, r2
 *   @0x23dfa0 mov r3, r2
 *   @0x23dfa4 sub r10, r10, #1
 *   @0x23dfa8 sub r2, r2, #4
 *   @0x23dfac bhs 0x23dfbc <quorem_D2A+0x210>
 *   @0x23dfb0 ldr r3, [r3]
 *   @0x23dfb4 cmp r3, #0
 *   @0x23dfb8 beq 0x23df9c <quorem_D2A+0x1f0>
 *   @0x23dfbc str r10, [r12, #0x10]
 *   @0x23dfc0 ldr r0, [sp, #0x10]
 *   @0x23dfc4 add sp, sp, #60
 *   @0x23dfc8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §30/54 FindDSMap  0x160024  size 540  135 条（0x160024..0x160240）
 * @func 0x160024 0x160240  size 540  135 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×3 / YYStrFree(char const*)×3 / UNLOCK_RVALUE_MUTEX()×2 / YYFree(void const*)×2 / operator delete(void*)×2 / YYCreateString(RValue*, char const*) / CDS_Map::Find(RValue*) / FindDSMap(CDS_Map*, char const*)+0x1d0
 * 字段偏移 top8: 0x4×12 / 0x8×6 / 0xc×4 / 0x10×3 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160024 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x160028 sub sp, sp, #20
 *   @0x16002c mov r5, r0
 *   @0x160030 mov r3, #0
 *   @0x160034 mov r0, sp
 *   @0x160038 str r3, [sp]
 *   @0x16003c str r3, [sp, #0x4]
 *   @0x160040 mov r4, sp
 *   @0x160044 str r3, [sp, #0x8]
 *   @0x160048 str r3, [sp, #0xc]
 *   @0x16004c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x160050 mov r0, r5
 *   @0x160054 mov r1, sp
 *   @0x160058 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue>
 *   @0x16005c ldr r2, [sp, #0xc]
 *   @0x160060 sub r3, r2, #1
 *   @0x160064 bic r3, r3, #-16777216
 *   @0x160068 cmp r0, #0
 *   @0x16006c addne r6, r0, #16
 *   @0x160070 moveq r6, r0
 *   @0x160074 bics r5, r3, #3
 *   @0x160078 beq 0x160088 <_Z9FindDSMapP7CDS_MapPKc+0x64>
 *   @0x16007c mov r0, r6
 *   @0x160080 add sp, sp, #20
 *   @0x160084 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x160088 bic r2, r2, #-16777216
 *   @0x16008c cmp r2, #2
 *   @0x160090 beq 0x160100 <_Z9FindDSMapP7CDS_MapPKc+0xdc>
 *   @0x160094 cmp r2, #3
 *   @0x160098 beq 0x1600d8 <_Z9FindDSMapP7CDS_MapPKc+0xb4>
 *   @0x16009c cmp r2, #1
 *   @0x1600a0 bne 0x16007c <_Z9FindDSMapP7CDS_MapPKc+0x58>
 *   @0x1600a4 ldr r4, [sp]
 *   @0x1600a8 cmp r4, #0
 *   @0x1600ac beq 0x16007c <_Z9FindDSMapP7CDS_MapPKc+0x58>
 *   @0x1600b0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1600b4 ldr r5, [r4, #0x4]
 *   @0x1600b8 sub r5, r5, #1
 *   @0x1600bc str r5, [r4, #0x4]
 *   @0x1600c0 cmp r5, #0
 *   @0x1600c4 beq 0x1601a0 <_Z9FindDSMapP7CDS_MapPKc+0x17c>
 *   @0x1600c8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1600cc mov r0, r6
 *   @0x1600d0 add sp, sp, #20
 *   @0x1600d4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1600d8 ldr r3, [sp, #0x8]
 *   @0x1600dc tst r3, #8
 *   @0x1600e0 beq 0x16007c <_Z9FindDSMapP7CDS_MapPKc+0x58>
 *   @0x1600e4 ldr r0, [sp]
 *   @0x1600e8 cmp r0, #0
 *   @0x1600ec beq 0x16007c <_Z9FindDSMapP7CDS_MapPKc+0x58>
 *   @0x1600f0 ldr r3, [r0]
 *   @0x1600f4 ldr r3, [r3, #0x4]
 *   @0x1600f8 blx r3
 *   @0x1600fc b 0x16007c <_Z9FindDSMapP7CDS_MapPKc+0x58>
 *   @0x160100 ldr r8, [sp]
 *   @0x160104 cmp r8, #0
 *   @0x160108 beq 0x16007c <_Z9FindDSMapP7CDS_MapPKc+0x58>
 *   @0x16010c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x160110 ldr r3, [r8]
 *   @0x160114 ldr r2, [r8, #0x8]
 *   @0x160118 sub r3, r3, #1
 *   @0x16011c str r3, [r8]
 *   @0x160120 cmp r2, r4
 *   @0x160124 streq r5, [r8, #0x8]
 *   @0x160128 cmp r3, #0
 *   @0x16012c bgt 0x1600c8 <_Z9FindDSMapP7CDS_MapPKc+0xa4>
 *   @0x160130 ldr r3, [r8, #0x10]
 *   @0x160134 cmp r3, #0
 *   @0x160138 movgt r7, #0
 *   @0x16013c movgt r11, #5
 *   @0x160140 movgt r5, r7
 *   @0x160144 ble 0x1601f4 <_Z9FindDSMapP7CDS_MapPKc+0x1d0>
 *   @0x160148 ldr r3, [r8, #0x4]
 *   @0x16014c add r9, r3, r7, lsl #3
 *   @0x160150 ldr r10, [r3, r7, lsl #3]
 *   @0x160154 ldr r4, [r9, #0x4]
 *   @0x160158 add r10, r4, r10, lsl #4
 *   @0x16015c cmp r4, r10
 *   @0x160160 blo 0x16017c <_Z9FindDSMapP7CDS_MapPKc+0x158>
 *   @0x160164 b 0x160214 <_Z9FindDSMapP7CDS_MapPKc+0x1f0>
 *   @0x160168 str r5, [r4, #0x8]
 *   @0x16016c str r11, [r4, #0xc]
 *   @0x160170 str r5, [r4], #16
 *   @0x160174 cmp r10, r4
 *   @0x160178 bls 0x1601d8 <_Z9FindDSMapP7CDS_MapPKc+0x1b4>
 *   @0x16017c ldr r3, [r4, #0xc]
 *   @0x160180 sub r3, r3, #1
 *   @0x160184 bic r3, r3, #-16777216
 *   @0x160188 bic r3, r3, #3
 *   @0x16018c cmp r3, #0
 *   @0x160190 bne 0x160168 <_Z9FindDSMapP7CDS_MapPKc+0x144>
 *   @0x160194 mov r0, r4
 *   @0x160198 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x16019c b 0x160168 <_Z9FindDSMapP7CDS_MapPKc+0x144>
 *   @0x1601a0 ldr r0, [r4]
 *   @0x1601a4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1601a8 str r5, [r4]
 *   @0x1601ac str r5, [r4, #0x8]
 *   @0x1601b0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1601b4 ldr r5, [r4, #0x4]
 *   @0x1601b8 sub r5, r5, #1
 *   @0x1601bc str r5, [r4, #0x4]
 *   @0x1601c0 cmp r5, #0
 *   @0x1601c4 beq 0x16021c <_Z9FindDSMapP7CDS_MapPKc+0x1f8>
 *   @0x1601c8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1601cc mov r0, r4
 *   @0x1601d0 bl 0x27d1d0 <_ZdlPv>
 *   @0x1601d4 b 0x1600c8 <_Z9FindDSMapP7CDS_MapPKc+0xa4>
 *   @0x1601d8 ldr r0, [r9, #0x4]
 *   @0x1601dc bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x1601e0 ldr r3, [r8, #0x10]
 *   @0x1601e4 add r7, r7, #1
 *   @0x1601e8 str r5, [r9, #0x4]
 *   @0x1601ec cmp r7, r3
 *   @0x1601f0 blt 0x160148 <_Z9FindDSMapP7CDS_MapPKc+0x124>
 *   @0x1601f4 ldr r0, [r8, #0x4]
 *   @0x1601f8 mov r4, #0
 *   @0x1601fc bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x160200 str r4, [r8, #0x4]
 *   @0x160204 mov r0, r8
 *   @0x160208 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x16020c str r4, [sp]
 *   @0x160210 b 0x1600c8 <_Z9FindDSMapP7CDS_MapPKc+0xa4>
 *   @0x160214 mov r0, r4
 *   @0x160218 b 0x1601dc <_Z9FindDSMapP7CDS_MapPKc+0x1b8>
 *   @0x16021c ldr r0, [r4]
 *   @0x160220 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x160224 mov r0, r4
 *   @0x160228 str r5, [r4]
 *   @0x16022c str r5, [r4, #0x8]
 *   @0x160230 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x160234 mov r0, r4
 *   @0x160238 bl 0x27d1d0 <_ZdlPv>
 *   @0x16023c b 0x1601c8 <_Z9FindDSMapP7CDS_MapPKc+0x1a4>
 *
 * ══ §31/54 FlushShader  0x1e1520  size 540  135 条（0x1e1520..0x1e173c）
 * @func 0x1e1520 0x1e173c  size 540  135 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1e1530→0x544c78, 0x1e153c→0x544c7c, 0x1e1540→0x544c80, 0x1e1570→0x4a2170, 0x1e1584→0x48ffe4, 0x1e1590→0x4848a4, 0x1e159c→0x4848c4, 0x1e15fc→0x3f2148
 * 调用序列: Shader_Set_Uniform_FA(int, int, float*)×4 / Graphics::Flush() / SetShader(Shader*) / Shader_Set_Uniform_Matrix_N(int, int, float*) / Shader_Set_Uniform_B(int, int, double, double, double, double)
 * 字段偏移 top8: 0x1d0×2 / 0x80×2 / 0x1dc×1 / 0x1d8×1 / 0x1a4×1 / 0x6c×1 / 0x194×1 / 0x18c×1
 * VFP 指令 33 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e1520 push {r4, r5, lr}
 *   @0x1e1524 sub sp, sp, #172
 *   @0x1e1528 ldr r4, [pc, #0x1dc]
 *   @0x1e152c bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x1e1530 ldr r1, [pc, #0x1d8]
 *   @0x1e1534 mov r0, #0
 *   @0x1e1538 add r4, pc, r4
 *   @0x1e153c ldr r3, [pc, #0x1d0]
 *   @0x1e1540 ldr r2, [pc, #0x1d0]
 *   @0x1e1544 ldr r1, [r4, r1]
 *   @0x1e1548 strb r0, [r1]
 *   @0x1e154c ldr r3, [r4, r3]
 *   @0x1e1550 ldr r5, [r4, r2]
 *   @0x1e1554 ldr r3, [r3]
 *   @0x1e1558 mov r0, r3
 *   @0x1e155c str r3, [r5]
 *   @0x1e1560 bl 0x188650 <_Z9SetShaderP6Shader>
 *   @0x1e1564 ldr r3, [r5]
 *   @0x1e1568 cmp r3, #0
 *   @0x1e156c beq 0x1e16f4 <_Z11FlushShaderv+0x1d4>
 *   @0x1e1570 ldr r2, [pc, #0x1a4]
 *   @0x1e1574 mov r1, #5
 *   @0x1e1578 ldr r0, [r3, #0x6c]
 *   @0x1e157c ldr r2, [r4, r2]
 *   @0x1e1580 bl 0x1889fc <_Z27Shader_Set_Uniform_Matrix_NiiPf>
 *   @0x1e1584 ldr r3, [pc, #0x194]
 *   @0x1e1588 ldr r12, [r5]
 *   @0x1e158c add r2, sp, #52
 *   @0x1e1590 ldr r1, [pc, #0x18c]
 *   @0x1e1594 ldr r0, [r4, r3]
 *   @0x1e1598 ldr lr, [r12, #0x68]
 *   @0x1e159c ldr r3, [pc, #0x184]
 *   @0x1e15a0 str lr, [r0]
 *   @0x1e15a4 ldr r1, [r4, r1]
 *   @0x1e15a8 ldr r3, [r4, r3]
 *   @0x1e15ac add r0, r1, #32
 *   @0x1e15b0 add r3, r3, #12
 *   @0x1e15b4 vldmia r1!, {s15}
 *   @0x1e15b8 mov lr, r3
 *   @0x1e15bc vldr s11, [r3, #-12]
 *   @0x1e15c0 vldr s12, [r3, #-8]
 *   @0x1e15c4 vldr s14, [r3, #-4]
 *   @0x1e15c8 vldr s13, [lr]
 *   @0x1e15cc vmul.f32 s11, s11, s15
 *   @0x1e15d0 cmp r1, r0
 *   @0x1e15d4 add r3, r3, #16
 *   @0x1e15d8 vmul.f32 s12, s12, s15
 *   @0x1e15dc vstr s11, [r2, #-12]
 *   @0x1e15e0 vmul.f32 s14, s14, s15
 *   @0x1e15e4 vstr s12, [r2, #-8]
 *   @0x1e15e8 vmul.f32 s15, s13, s15
 *   @0x1e15ec vstr s14, [r2, #-4]
 *   @0x1e15f0 vmov lr, s15
 *   @0x1e15f4 str lr, [r2], #16
 *   @0x1e15f8 bne 0x1e15b4 <_Z11FlushShaderv+0x94>
 *   @0x1e15fc ldr r3, [pc, #0x128]
 *   @0x1e1600 vldr s15, [pc, #256]
 *   @0x1e1604 ldr r0, [r12, #0x7c]
 *   @0x1e1608 add r2, sp, #24
 *   @0x1e160c mov r1, #4
 *   @0x1e1610 ldr r3, [r4, r3]
 *   @0x1e1614 ldr r3, [r3]
 *   @0x1e1618 ubfx r12, r3, #0x8, #0x8
 *   @0x1e161c ubfx lr, r3, #0x10, #0x8
 *   @0x1e1620 vmov s12, r12
 *   @0x1e1624 uxtb r12, r3
 *   @0x1e1628 lsr r3, r3, #24
 *   @0x1e162c vmov s14, lr
 *   @0x1e1630 vmov s11, r12
 *   @0x1e1634 vmov s10, r3
 *   @0x1e1638 vcvt.f32.s32 s12, s12
 *   @0x1e163c vcvt.f32.u32 s13, s10
 *   @0x1e1640 vcvt.f32.s32 s11, s11
 *   @0x1e1644 vcvt.f32.s32 s14, s14
 *   @0x1e1648 vdiv.f32 s11, s11, s15
 *   @0x1e164c vdiv.f32 s12, s12, s15
 *   @0x1e1650 vstr s11, [sp, #24]
 *   @0x1e1654 vdiv.f32 s14, s14, s15
 *   @0x1e1658 vstr s12, [sp, #28]
 *   @0x1e165c vdiv.f32 s15, s13, s15
 *   @0x1e1660 vstr s14, [sp, #32]
 *   @0x1e1664 vstr s15, [sp, #36]
 *   @0x1e1668 bl 0x188a9c <_Z21Shader_Set_Uniform_FAiiPf>
 *   @0x1e166c ldr r3, [r5]
 *   @0x1e1670 mov r1, #32
 *   @0x1e1674 ldr r2, [pc, #0xb4]
 *   @0x1e1678 ldr r0, [r3, #0x70]
 *   @0x1e167c ldr r2, [r4, r2]
 *   @0x1e1680 bl 0x188a9c <_Z21Shader_Set_Uniform_FAiiPf>
 *   @0x1e1684 ldr r3, [r5]
 *   @0x1e1688 add r2, sp, #40
 *   @0x1e168c mov r1, #32
 *   @0x1e1690 ldr r0, [r3, #0x78]
 *   @0x1e1694 bl 0x188a9c <_Z21Shader_Set_Uniform_FAiiPf>
 *   @0x1e1698 ldr r3, [r5]
 *   @0x1e169c ldr r2, [pc, #0x90]
 *   @0x1e16a0 mov r1, #32
 *   @0x1e16a4 ldr r0, [r3, #0x74]
 *   @0x1e16a8 ldr r2, [r4, r2]
 *   @0x1e16ac bl 0x188a9c <_Z21Shader_Set_Uniform_FAiiPf>
 *   @0x1e16b0 ldr r12, [pc, #0x80]
 *   @0x1e16b4 ldr r0, [r5]
 *   @0x1e16b8 mov r2, #0
 *   @0x1e16bc mov r3, #0
 *   @0x1e16c0 mov r1, #1
 *   @0x1e16c4 ldr r12, [r4, r12]
 *   @0x1e16c8 ldr r0, [r0, #0x80]
 *   @0x1e16cc strd r2, r3, [sp]
 *   @0x1e16d0 strd r2, r3, [sp, #8]
 *   @0x1e16d4 strd r2, r3, [sp, #16]
 *   @0x1e16d8 ldrb r2, [r12]
 *   @0x1e16dc vmov s15, r2
 *   @0x1e16e0 vcvt.f64.u32 d7, s15
 *   @0x1e16e4 vmov r2, r3, d7
 *   @0x1e16e8 bl 0x188b90 <_Z20Shader_Set_Uniform_Biidddd>
 *   @0x1e16ec add sp, sp, #172
 *   @0x1e16f0 pop {r4, r5, pc}
 *   @0x1e16f4 ldr r2, [pc, #0x24]
 *   @0x1e16f8 ldr r2, [r4, r2]
 *   @0x1e16fc str r3, [r2]
 *   @0x1e1700 add sp, sp, #172
 *   @0x1e1704 pop {r4, r5, pc}
 *   @0x1e1708 cmnmi pc, #0
 *   @0x1e170c eoreq r0, r1, r8, lsl r7
 *   @0x1e1710 .word 0xfffff0fc
 *   @0x1e1714 .word 0xfffff0f0
 *   @0x1e1718 .word 0xffffe828
 *   @0x1e171c .word 0xffffe824
 *   @0x1e1720 .word 0xffffe4d4
 *   @0x1e1724 .word 0xffffd9d4
 *   @0x1e1728 .word 0xffffd9d8
 *   @0x1e172c .word 0xffffd9bc
 *   @0x1e1730 .word 0xffffd9dc
 *   @0x1e1734 .word 0xffffd9d0
 *   @0x1e1738 .word 0xffffd9c0
 *
 * ══ §32/54 void b2DynamicTree::Query<b2WorldQueryWrapper>  0x2cb680  size 540  135 条（0x2cb680..0x2cb89c）
 * @func 0x2cb680 0x2cb89c  size 540  135 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Free(void*)×4 / b2Alloc(int)×2 / 0xb65bc×2 / void b2DynamicTree::Query<b2WorldQueryWrapper>(b2WorldQueryWrapper*, b2AABB const&) const+0x124
 * 字段偏移 top8: 0x4×11 / 0x408×10 / 0x40c×5 / 0x2×2 / 0x18×2 / 0x10×2 / 0x1c×1 / 0x8×1
 * VFP 指令 20 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb680 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2cb684 mov r10, r0
 *   @0x2cb688 sub sp, sp, #1040
 *   @0x2cb68c ldr r12, [r10]
 *   @0x2cb690 add r7, sp, #16
 *   @0x2cb694 mov r9, r2
 *   @0x2cb698 sub r0, r7, #8
 *   @0x2cb69c mov r2, #256
 *   @0x2cb6a0 mov r6, r1
 *   @0x2cb6a4 mov r3, #1
 *   @0x2cb6a8 mov r5, r0
 *   @0x2cb6ac mov r8, r0
 *   @0x2cb6b0 stmib sp, {r0, r12}
 *   @0x2cb6b4 str r2, [sp, #0x40c]
 *   @0x2cb6b8 b 0x2cb6c4 <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0x44>
 *   @0x2cb6bc cmp r3, #0
 *   @0x2cb6c0 ble 0x2cb7a4 <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0x124>
 *   @0x2cb6c4 sub r3, r3, #1
 *   @0x2cb6c8 str r3, [sp, #0x408]
 *   @0x2cb6cc ldr r12, [r5, r3, lsl #2]
 *   @0x2cb6d0 add r2, r5, r3, lsl #2
 *   @0x2cb6d4 cmn r12, #1
 *   @0x2cb6d8 beq 0x2cb6bc <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0x3c>
 *   @0x2cb6dc add r12, r12, r12, lsl #3
 *   @0x2cb6e0 ldr r4, [r10, #0x4]
 *   @0x2cb6e4 vldr s14, [r9]
 *   @0x2cb6e8 vldr s13, [r9, #4]
 *   @0x2cb6ec lsl r12, r12, #2
 *   @0x2cb6f0 vldr s12, [r9, #8]
 *   @0x2cb6f4 add r4, r4, r12
 *   @0x2cb6f8 vldr s15, [r4, #8]
 *   @0x2cb6fc vsub.f32 s15, s14, s15
 *   @0x2cb700 vldr s11, [r4]
 *   @0x2cb704 vldr s14, [r4, #12]
 *   @0x2cb708 vldr s9, [r4, #4]
 *   @0x2cb70c vldr s10, [r9, #12]
 *   @0x2cb710 vcmpe.f32 s15, #0
 *   @0x2cb714 vmrs APSR_nzcv, fpscr
 *   @0x2cb718 bgt 0x2cb6bc <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0x3c>
 *   @0x2cb71c vsub.f32 s14, s13, s14
 *   @0x2cb720 vcmpe.f32 s14, #0
 *   @0x2cb724 vmrs APSR_nzcv, fpscr
 *   @0x2cb728 bgt 0x2cb6bc <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0x3c>
 *   @0x2cb72c vsub.f32 s12, s11, s12
 *   @0x2cb730 vcmpe.f32 s12, #0
 *   @0x2cb734 vmrs APSR_nzcv, fpscr
 *   @0x2cb738 bgt 0x2cb6bc <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0x3c>
 *   @0x2cb73c vsub.f32 s10, s9, s10
 *   @0x2cb740 vcmpe.f32 s10, #0
 *   @0x2cb744 vmrs APSR_nzcv, fpscr
 *   @0x2cb748 bgt 0x2cb6bc <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0x3c>
 *   @0x2cb74c ldr r0, [r4, #0x18]
 *   @0x2cb750 cmn r0, #1
 *   @0x2cb754 beq 0x2cb7c0 <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0x140>
 *   @0x2cb758 ldr r1, [sp, #0x40c]
 *   @0x2cb75c cmp r3, r1
 *   @0x2cb760 movne r3, r0
 *   @0x2cb764 beq 0x2cb838 <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0x1b8>
 *   @0x2cb768 str r3, [r2]
 *   @0x2cb76c ldr r3, [sp, #0x408]
 *   @0x2cb770 ldr r2, [sp, #0x40c]
 *   @0x2cb774 add r3, r3, #1
 *   @0x2cb778 str r3, [sp, #0x408]
 *   @0x2cb77c cmp r3, r2
 *   @0x2cb780 beq 0x2cb7f8 <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0x178>
 *   @0x2cb784 ldr r2, [r4, #0x1c]
 *   @0x2cb788 str r2, [r5, r3, lsl #2]
 *   @0x2cb78c ldr r3, [sp, #0x408]
 *   @0x2cb790 ldr r5, [sp, #0x4]
 *   @0x2cb794 add r3, r3, #1
 *   @0x2cb798 str r3, [sp, #0x408]
 *   @0x2cb79c cmp r3, #0
 *   @0x2cb7a0 bgt 0x2cb6c4 <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0x44>
 *   @0x2cb7a4 sub r7, r7, #8
 *   @0x2cb7a8 cmp r5, r7
 *   @0x2cb7ac beq 0x2cb7b8 <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0x138>
 *   @0x2cb7b0 mov r0, r5
 *   @0x2cb7b4 bl 0x2c6a70 <_Z6b2FreePv>
 *   @0x2cb7b8 add sp, sp, #1040
 *   @0x2cb7bc pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2cb7c0 ldr r3, [r6]
 *   @0x2cb7c4 ldr r0, [r6, #0x4]
 *   @0x2cb7c8 ldr r2, [r3, #0x4]
 *   @0x2cb7cc ldr r3, [r0]
 *   @0x2cb7d0 add r12, r2, r12
 *   @0x2cb7d4 ldr r2, [r12, #0x10]
 *   @0x2cb7d8 ldr r3, [r3, #0x8]
 *   @0x2cb7dc ldr r1, [r2, #0x10]
 *   @0x2cb7e0 blx r3
 *   @0x2cb7e4 cmp r0, #0
 *   @0x2cb7e8 beq 0x2cb884 <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0x204>
 *   @0x2cb7ec ldr r3, [sp, #0x408]
 *   @0x2cb7f0 ldr r5, [sp, #0x4]
 *   @0x2cb7f4 b 0x2cb6bc <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0x3c>
 *   @0x2cb7f8 lsl r0, r3, #3
 *   @0x2cb7fc lsl r3, r3, #1
 *   @0x2cb800 str r3, [sp, #0x40c]
 *   @0x2cb804 bl 0x2c6a6c <_Z7b2Alloci>
 *   @0x2cb808 ldr r2, [sp, #0x408]
 *   @0x2cb80c mov r1, r5
 *   @0x2cb810 lsl r2, r2, #2
 *   @0x2cb814 str r0, [sp, #0x4]
 *   @0x2cb818 bl 0xb65bc <memcpy@plt>
 *   @0x2cb81c cmp r5, r8
 *   @0x2cb820 beq 0x2cb82c <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0x1ac>
 *   @0x2cb824 mov r0, r5
 *   @0x2cb828 bl 0x2c6a70 <_Z6b2FreePv>
 *   @0x2cb82c ldr r5, [sp, #0x4]
 *   @0x2cb830 ldr r3, [sp, #0x408]
 *   @0x2cb834 b 0x2cb784 <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0x104>
 *   @0x2cb838 lsl r0, r3, #3
 *   @0x2cb83c ldr r5, [sp, #0x4]
 *   @0x2cb840 lsl r3, r3, #1
 *   @0x2cb844 str r3, [sp, #0x40c]
 *   @0x2cb848 bl 0x2c6a6c <_Z7b2Alloci>
 *   @0x2cb84c ldr r2, [sp, #0x408]
 *   @0x2cb850 mov r1, r5
 *   @0x2cb854 lsl r2, r2, #2
 *   @0x2cb858 str r0, [sp, #0x4]
 *   @0x2cb85c bl 0xb65bc <memcpy@plt>
 *   @0x2cb860 cmp r5, r8
 *   @0x2cb864 beq 0x2cb870 <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0x1f0>
 *   @0x2cb868 mov r0, r5
 *   @0x2cb86c bl 0x2c6a70 <_Z6b2FreePv>
 *   @0x2cb870 ldr r2, [sp, #0x408]
 *   @0x2cb874 ldr r5, [sp, #0x4]
 *   @0x2cb878 ldr r3, [r4, #0x18]
 *   @0x2cb87c add r2, r5, r2, lsl #2
 *   @0x2cb880 b 0x2cb768 <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0xe8>
 *   @0x2cb884 ldr r0, [sp, #0x4]
 *   @0x2cb888 sub r7, r7, #8
 *   @0x2cb88c cmp r0, r7
 *   @0x2cb890 beq 0x2cb7b8 <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0x138>
 *   @0x2cb894 bl 0x2c6a70 <_Z6b2FreePv>
 *   @0x2cb898 b 0x2cb7b8 <_ZNK13b2DynamicTree5QueryI19b2WorldQueryWrapperEEvPT_RK6b2AABB+0x138>
 *
 * ══ §33/54 ThrowNetworkEvent  0x298b9c  size 536  134 条（0x298b9c..0x298db4）
 * @func 0x298b9c 0x298db4  size 536  134 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_DsMapAdd_Internal(int, char*, double)×5 / InitNetworkEvent() / F_DsMapAdd_Internal(int, char*, char*) / ThrowNetworkEvent(int, int, int)+0x1d0 / Perform_Event_Object_ASync(CInstance*, CInstance*, int, int, int)
 * 字段偏移 top8: 0x8×4 / 0x4×3 / 0xc×3 / 0x154×2 / 0x110×2 / 0x1d4×1 / 0x1c4×1 / 0x1c0×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x298b9c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x298ba0 sub sp, sp, #20
 *   @0x298ba4 ldr r7, [pc, #0x1d4]
 *   @0x298ba8 mov r5, r0
 *   @0x298bac mov r6, r2
 *   @0x298bb0 mov r8, r1
 *   @0x298bb4 bl 0x29871c <_Z16InitNetworkEventv>
 *   @0x298bb8 ldr r0, [pc, #0x1c4]
 *   @0x298bbc add r7, pc, r7
 *   @0x298bc0 ldr r1, [pc, #0x1c0]
 *   @0x298bc4 mov r2, #0
 *   @0x298bc8 mov r3, #0
 *   @0x298bcc ldr r4, [r7, r0]
 *   @0x298bd0 add r1, pc, r1
 *   @0x298bd4 movt r3, #0x4008
 *   @0x298bd8 movw r10, #0x1d10
 *   @0x298bdc ldr r0, [r4]
 *   @0x298be0 bl 0x104d94 <_Z19F_DsMapAdd_InternaliPcd>
 *   @0x298be4 vmov s15, r5
 *   @0x298be8 ldr r1, [pc, #0x19c]
 *   @0x298bec add r5, r5, r5, lsl #1
 *   @0x298bf0 vcvt.f64.s32 d7, s15
 *   @0x298bf4 ldr r0, [r4]
 *   @0x298bf8 add r1, pc, r1
 *   @0x298bfc vmov r2, r3, d7
 *   @0x298c00 bl 0x104d94 <_Z19F_DsMapAdd_InternaliPcd>
 *   @0x298c04 ldr r1, [pc, #0x184]
 *   @0x298c08 vmov s15, r8
 *   @0x298c0c ldr r0, [r4]
 *   @0x298c10 add r1, pc, r1
 *   @0x298c14 vcvt.f64.s32 d7, s15
 *   @0x298c18 vmov r2, r3, d7
 *   @0x298c1c bl 0x104d94 <_Z19F_DsMapAdd_InternaliPcd>
 *   @0x298c20 ldr r1, [pc, #0x16c]
 *   @0x298c24 vmov s15, r6
 *   @0x298c28 ldr r0, [r4]
 *   @0x298c2c add r1, pc, r1
 *   @0x298c30 vcvt.f64.s32 d7, s15
 *   @0x298c34 vmov r2, r3, d7
 *   @0x298c38 bl 0x104d94 <_Z19F_DsMapAdd_InternaliPcd>
 *   @0x298c3c ldr r3, [pc, #0x154]
 *   @0x298c40 ldr r1, [pc, #0x154]
 *   @0x298c44 ldr r0, [r4]
 *   @0x298c48 ldr r3, [r7, r3]
 *   @0x298c4c add r1, pc, r1
 *   @0x298c50 add r3, r3, r5, lsl #2
 *   @0x298c54 ldr r2, [r3, #0x8]
 *   @0x298c58 ldr r5, [r3, #0x4]
 *   @0x298c5c cmp r2, #0
 *   @0x298c60 ldrne r5, [r2]
 *   @0x298c64 add r2, r5, #108
 *   @0x298c68 bl 0x104f64 <_Z19F_DsMapAdd_InternaliPcS_>
 *   @0x298c6c ldr r2, [r5, #0xac]
 *   @0x298c70 ldr r1, [pc, #0x128]
 *   @0x298c74 ldr r0, [r4]
 *   @0x298c78 vmov s15, r2
 *   @0x298c7c add r1, pc, r1
 *   @0x298c80 vcvt.f64.s32 d7, s15
 *   @0x298c84 vmov r2, r3, d7
 *   @0x298c88 bl 0x104d94 <_Z19F_DsMapAdd_InternaliPcd>
 *   @0x298c8c ldr r1, [pc, #0x110]
 *   @0x298c90 ldr r3, [pc, #0x110]
 *   @0x298c94 ldr r2, [r4]
 *   @0x298c98 ldr r1, [r7, r1]
 *   @0x298c9c str r1, [sp, #0xc]
 *   @0x298ca0 str r2, [r1]
 *   @0x298ca4 ldr r6, [r7, r3]
 *   @0x298ca8 ldr r3, [r6, r10]
 *   @0x298cac cmp r3, #0
 *   @0x298cb0 ble 0x298d6c <_Z17ThrowNetworkEventiii+0x1d0>
 *   @0x298cb4 ldr r2, [pc, #0xf0]
 *   @0x298cb8 mov r5, #0
 *   @0x298cbc ldr r3, [pc, #0xec]
 *   @0x298cc0 movw r9, #0x3a24
 *   @0x298cc4 mov r4, #68
 *   @0x298cc8 ldr r8, [r7, r2]
 *   @0x298ccc ldr r7, [r7, r3]
 *   @0x298cd0 ldr r3, [r8]
 *   @0x298cd4 ldr r1, [r7, r9]
 *   @0x298cd8 ldr r2, [r3, #0x4]
 *   @0x298cdc ldr r1, [r1, r5, lsl #2]
 *   @0x298ce0 ldr r3, [r3]
 *   @0x298ce4 and r2, r1, r2
 *   @0x298ce8 ldr r3, [r3, r2, lsl #3]
 *   @0x298cec cmp r3, #0
 *   @0x298cf0 bne 0x298d04 <_Z17ThrowNetworkEventiii+0x168>
 *   @0x298cf4 b 0x298d14 <_Z17ThrowNetworkEventiii+0x178>
 *   @0x298cf8 ldr r3, [r3, #0x4]
 *   @0x298cfc cmp r3, #0
 *   @0x298d00 beq 0x298d14 <_Z17ThrowNetworkEventiii+0x178>
 *   @0x298d04 ldr r2, [r3, #0x8]
 *   @0x298d08 cmp r1, r2
 *   @0x298d0c bne 0x298cf8 <_Z17ThrowNetworkEventiii+0x15c>
 *   @0x298d10 ldr r3, [r3, #0xc]
 *   @0x298d14 ldr r11, [r3, #0xc4]
 *   @0x298d18 cmp r11, #0
 *   @0x298d1c beq 0x298d5c <_Z17ThrowNetworkEventiii+0x1c0>
 *   @0x298d20 ldr r3, [r11, #0x8]
 *   @0x298d24 cmp r3, #0
 *   @0x298d28 beq 0x298d5c <_Z17ThrowNetworkEventiii+0x1c0>
 *   @0x298d2c ldr r2, [r11, #0x8]
 *   @0x298d30 mov r3, #7
 *   @0x298d34 ldr r11, [r11]
 *   @0x298d38 cmp r2, #0
 *   @0x298d3c mov r0, r2
 *   @0x298d40 mov r1, r2
 *   @0x298d44 beq 0x298d18 <_Z17ThrowNetworkEventiii+0x17c>
 *   @0x298d48 ldr r2, [r2, #0x7c]
 *   @0x298d4c str r4, [sp]
 *   @0x298d50 bl 0xf31f8 <_Z26Perform_Event_Object_ASyncP9CInstanceS0_iii>
 *   @0x298d54 cmp r11, #0
 *   @0x298d58 bne 0x298d20 <_Z17ThrowNetworkEventiii+0x184>
 *   @0x298d5c ldr r3, [r6, r10]
 *   @0x298d60 add r5, r5, #1
 *   @0x298d64 cmp r3, r5
 *   @0x298d68 bgt 0x298cd0 <_Z17ThrowNetworkEventiii+0x134>
 *   @0x298d6c ldr r1, [sp, #0xc]
 *   @0x298d70 mvn r3, #0
 *   @0x298d74 str r3, [r1]
 *   @0x298d78 add sp, sp, #20
 *   @0x298d7c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x298d80 mulseq r5, r4, r0
 *   @0x298d84 .word 0xfffff750
 *   @0x298d88 andeq sp, r10, r8, asr r5
 *   @0x298d8c andeq r7, r9, r8, asr #28
 *   @0x298d90 andeq r0, r12, r4, lsr #21
 *   @0x298d94 muleq r12, r0, r10
 *   @0x298d98 .word 0xfffffd54
 *   @0x298d9c andeq r0, r12, r8, asr r10
 *   @0x298da0 andeq r0, r12, r4, lsl r10
 *   @0x298da4 .word 0xffffdec8
 *   @0x298da8 .word 0xffffdeb8
 *   @0x298dac .word 0xffffbfec
 *   @0x298db0 .word 0xffffdebc
 *
 * ══ §34/54 SET_RValue  0xd0b24  size 532  133 条（0xd0b24..0xd0d38）
 * @func 0xd0b24 0xd0d38  size 532  133 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ARRAY_RefAlloc(void*) / FREE_RValue__Pre(RValue*) / GetContextStackTop() / CopyRefArrayAndUnref(RefDynamicArrayOfRValue*, void*)
 * 字段偏移 top8: 0x8×8 / 0xc×7 / 0x4×4
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd0b24 ldr r3, [r0, #0xc]
 *   @0xd0b28 push {r4, r5, lr}
 *   @0xd0b2c mov r5, r1
 *   @0xd0b30 bic r1, r3, #-16777216
 *   @0xd0b34 sub sp, sp, #12
 *   @0xd0b38 cmp r1, #2
 *   @0xd0b3c mov r4, r0
 *   @0xd0b40 beq 0xd0cbc <_Z10SET_RValueP6RValueS0_i+0x198>
 *   @0xd0b44 cmp r2, #-2147483648
 *   @0xd0b48 beq 0xd0b78 <_Z10SET_RValueP6RValueS0_i+0x54>
 *   @0xd0b4c mov r1, #2
 *   @0xd0b50 mov r3, #0
 *   @0xd0b54 str r1, [r0, #0xc]
 *   @0xd0b58 str r3, [r0]
 *   @0xd0b5c mov r0, r4
 *   @0xd0b60 str r2, [sp, #0x4]
 *   @0xd0b64 bl 0xced9c <_Z14ARRAY_RefAllocPv>
 *   @0xd0b68 str r0, [r4]
 *   @0xd0b6c ldr r2, [sp, #0x4]
 *   @0xd0b70 ldr r3, [r0, #0x8]
 *   @0xd0b74 b 0xd0d00 <_Z10SET_RValueP6RValueS0_i+0x1dc>
 *   @0xd0b78 sub r3, r3, #1
 *   @0xd0b7c bic r3, r3, #-16777216
 *   @0xd0b80 bic r3, r3, #3
 *   @0xd0b84 cmp r3, #0
 *   @0xd0b88 beq 0xd0c38 <_Z10SET_RValueP6RValueS0_i+0x114>
 *   @0xd0b8c mov r3, #5
 *   @0xd0b90 str r3, [r4, #0xc]
 *   @0xd0b94 ldr r3, [r5, #0xc]
 *   @0xd0b98 mov r2, #0
 *   @0xd0b9c str r2, [r4, #0x8]
 *   @0xd0ba0 ldr r1, [r5, #0x8]
 *   @0xd0ba4 str r3, [r4, #0xc]
 *   @0xd0ba8 ldr r3, [r5, #0xc]
 *   @0xd0bac str r2, [r4]
 *   @0xd0bb0 bic r3, r3, #-16777216
 *   @0xd0bb4 str r1, [r4, #0x8]
 *   @0xd0bb8 cmp r3, #14
 *   @0xd0bbc addls pc, pc, r3, lsl #2
 *   @0xd0bc0 b 0xd0c08 <_Z10SET_RValueP6RValueS0_i+0xe4>
 *   @0xd0bc4 b 0xd0c40 <_Z10SET_RValueP6RValueS0_i+0x11c>
 *   @0xd0bc8 b 0xd0ca4 <_Z10SET_RValueP6RValueS0_i+0x180>
 *   @0xd0bcc b 0xd0c78 <_Z10SET_RValueP6RValueS0_i+0x154>
 *   @0xd0bd0 b 0xd0c00 <_Z10SET_RValueP6RValueS0_i+0xdc>
 *   @0xd0bd4 b 0xd0c08 <_Z10SET_RValueP6RValueS0_i+0xe4>
 *   @0xd0bd8 b 0xd0c08 <_Z10SET_RValueP6RValueS0_i+0xe4>
 *   @0xd0bdc b 0xd0c50 <_Z10SET_RValueP6RValueS0_i+0x12c>
 *   @0xd0be0 b 0xd0c00 <_Z10SET_RValueP6RValueS0_i+0xdc>
 *   @0xd0be4 b 0xd0c08 <_Z10SET_RValueP6RValueS0_i+0xe4>
 *   @0xd0be8 b 0xd0c08 <_Z10SET_RValueP6RValueS0_i+0xe4>
 *   @0xd0bec b 0xd0c40 <_Z10SET_RValueP6RValueS0_i+0x11c>
 *   @0xd0bf0 b 0xd0c08 <_Z10SET_RValueP6RValueS0_i+0xe4>
 *   @0xd0bf4 b 0xd0c08 <_Z10SET_RValueP6RValueS0_i+0xe4>
 *   @0xd0bf8 b 0xd0c40 <_Z10SET_RValueP6RValueS0_i+0x11c>
 *   @0xd0bfc b 0xd0c00 <_Z10SET_RValueP6RValueS0_i+0xdc>
 *   @0xd0c00 ldr r3, [r5]
 *   @0xd0c04 str r3, [r4]
 *   @0xd0c08 add sp, sp, #12
 *   @0xd0c0c pop {r4, r5, pc}
 *   @0xd0c10 ldr r2, [r5, #0xc]
 *   @0xd0c14 bic r2, r2, #-16777216
 *   @0xd0c18 cmp r2, #2
 *   @0xd0c1c beq 0xd0d1c <_Z10SET_RValueP6RValueS0_i+0x1f8>
 *   @0xd0c20 sub r3, r3, #1
 *   @0xd0c24 bic r3, r3, #-16777216
 *   @0xd0c28 bic r3, r3, #3
 *   @0xd0c2c cmp r3, #0
 *   @0xd0c30 bne 0xd0b8c <_Z10SET_RValueP6RValueS0_i+0x68>
 *   @0xd0c34 mov r0, r4
 *   @0xd0c38 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xd0c3c b 0xd0b8c <_Z10SET_RValueP6RValueS0_i+0x68>
 *   @0xd0c40 ldm r5, {r2, r3}
 *   @0xd0c44 stm r4, {r2, r3}
 *   @0xd0c48 add sp, sp, #12
 *   @0xd0c4c pop {r4, r5, pc}
 *   @0xd0c50 ldr r3, [r5]
 *   @0xd0c54 str r3, [r4]
 *   @0xd0c58 ldr r3, [r5]
 *   @0xd0c5c cmp r3, #0
 *   @0xd0c60 beq 0xd0c08 <_Z10SET_RValueP6RValueS0_i+0xe4>
 *   @0xd0c64 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0xd0c68 ldr r1, [r5]
 *   @0xd0c6c add sp, sp, #12
 *   @0xd0c70 pop {r4, r5, lr}
 *   @0xd0c74 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0xd0c78 ldr r3, [r5]
 *   @0xd0c7c cmp r3, #0
 *   @0xd0c80 str r3, [r4]
 *   @0xd0c84 beq 0xd0c08 <_Z10SET_RValueP6RValueS0_i+0xe4>
 *   @0xd0c88 ldr r1, [r3, #0x8]
 *   @0xd0c8c ldr r2, [r3]
 *   @0xd0c90 cmp r1, #0
 *   @0xd0c94 streq r4, [r3, #0x8]
 *   @0xd0c98 add r2, r2, #1
 *   @0xd0c9c str r2, [r3]
 *   @0xd0ca0 b 0xd0c08 <_Z10SET_RValueP6RValueS0_i+0xe4>
 *   @0xd0ca4 ldr r3, [r5]
 *   @0xd0ca8 cmp r3, #0
 *   @0xd0cac ldrne r2, [r3, #0x4]
 *   @0xd0cb0 addne r2, r2, #1
 *   @0xd0cb4 strne r2, [r3, #0x4]
 *   @0xd0cb8 b 0xd0c04 <_Z10SET_RValueP6RValueS0_i+0xe0>
 *   @0xd0cbc cmp r2, #-2147483648
 *   @0xd0cc0 beq 0xd0c10 <_Z10SET_RValueP6RValueS0_i+0xec>
 *   @0xd0cc4 ldr r0, [r0]
 *   @0xd0cc8 cmp r0, #0
 *   @0xd0ccc beq 0xd0b5c <_Z10SET_RValueP6RValueS0_i+0x38>
 *   @0xd0cd0 ldr r3, [r0, #0x8]
 *   @0xd0cd4 cmp r3, r4
 *   @0xd0cd8 beq 0xd0d08 <_Z10SET_RValueP6RValueS0_i+0x1e4>
 *   @0xd0cdc ldr r1, [r0]
 *   @0xd0ce0 cmp r1, #1
 *   @0xd0ce4 beq 0xd0d00 <_Z10SET_RValueP6RValueS0_i+0x1dc>
 *   @0xd0ce8 mov r1, r4
 *   @0xd0cec str r2, [sp, #0x4]
 *   @0xd0cf0 bl 0xd064c <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv>
 *   @0xd0cf4 str r0, [r4]
 *   @0xd0cf8 ldr r2, [sp, #0x4]
 *   @0xd0cfc ldr r3, [r0, #0x8]
 *   @0xd0d00 cmp r3, #0
 *   @0xd0d04 streq r5, [r0, #0x8]
 *   @0xd0d08 mov r0, r4
 *   @0xd0d0c mov r1, r5
 *   @0xd0d10 add sp, sp, #12
 *   @0xd0d14 pop {r4, r5, lr}
 *   @0xd0d18 b 0xcfcb4 <_Z16SET_RValue_ArrayP6RValueS0_i>
 *   @0xd0d1c ldr r2, [r5]
 *   @0xd0d20 cmp r2, #0
 *   @0xd0d24 beq 0xd0c20 <_Z10SET_RValueP6RValueS0_i+0xfc>
 *   @0xd0d28 ldr r1, [r2, #0x8]
 *   @0xd0d2c cmp r1, #0
 *   @0xd0d30 streq r5, [r2, #0x8]
 *   @0xd0d34 b 0xd0c20 <_Z10SET_RValueP6RValueS0_i+0xfc>
 *
 * ══ §35/54 IO_Playback_Update  0x18b8ec  size 532  133 条（0x18b8ec..0x18bb00）
 * @func 0x18b8ec 0x18bb00  size 532  133 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x18b8f4→0x5346c8, 0x18b918→0x5356aa, 0x18b930→0x534ea8, 0x18b948→0x534ea4, 0x18b960→0x534ea0, 0x18b978→0x534da0, 0x18b990→0x534ca0, 0x18b9a8→0x534ba0
 * 调用序列: 0xb68c8×16 / 0xb6874
 * 字段偏移 top8: 0x1bc×2 / 0x19c×1 / 0x188×1 / 0x174×1 / 0x160×1 / 0x14c×1 / 0x138×1 / 0x124×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18b8ec push {r4, r5, r6, lr}
 *   @0x18b8f0 ldr r4, [pc, #0x1bc]
 *   @0x18b8f4 ldr r3, [pc, #0x1bc]
 *   @0x18b8f8 add r4, pc, r4
 *   @0x18b8fc ldr r5, [r4, r3]
 *   @0x18b900 ldr r0, [r5]
 *   @0x18b904 cmp r0, #0
 *   @0x18b908 popeq {r4, r5, r6, pc}
 *   @0x18b90c bl 0xb6874 <feof@plt>
 *   @0x18b910 cmp r0, #0
 *   @0x18b914 popne {r4, r5, r6, pc}
 *   @0x18b918 ldr r0, [pc, #0x19c]
 *   @0x18b91c mov r1, #2
 *   @0x18b920 ldr r3, [r5]
 *   @0x18b924 mov r2, #1
 *   @0x18b928 ldr r0, [r4, r0]
 *   @0x18b92c bl 0xb68c8 <fread@plt>
 *   @0x18b930 ldr r0, [pc, #0x188]
 *   @0x18b934 ldr r3, [r5]
 *   @0x18b938 movw r1, #0x802
 *   @0x18b93c mov r2, #1
 *   @0x18b940 ldr r0, [r4, r0]
 *   @0x18b944 bl 0xb68c8 <fread@plt>
 *   @0x18b948 ldr r0, [pc, #0x174]
 *   @0x18b94c ldr r3, [r5]
 *   @0x18b950 mov r1, #4
 *   @0x18b954 mov r2, #1
 *   @0x18b958 ldr r0, [r4, r0]
 *   @0x18b95c bl 0xb68c8 <fread@plt>
 *   @0x18b960 ldr r0, [pc, #0x160]
 *   @0x18b964 ldr r3, [r5]
 *   @0x18b968 mov r1, #4
 *   @0x18b96c mov r2, #1
 *   @0x18b970 ldr r0, [r4, r0]
 *   @0x18b974 bl 0xb68c8 <fread@plt>
 *   @0x18b978 ldr r0, [pc, #0x14c]
 *   @0x18b97c ldr r3, [r5]
 *   @0x18b980 mov r1, #256
 *   @0x18b984 mov r2, #1
 *   @0x18b988 ldr r0, [r4, r0]
 *   @0x18b98c bl 0xb68c8 <fread@plt>
 *   @0x18b990 ldr r0, [pc, #0x138]
 *   @0x18b994 ldr r3, [r5]
 *   @0x18b998 mov r1, #256
 *   @0x18b99c mov r2, #1
 *   @0x18b9a0 ldr r0, [r4, r0]
 *   @0x18b9a4 bl 0xb68c8 <fread@plt>
 *   @0x18b9a8 ldr r0, [pc, #0x124]
 *   @0x18b9ac ldr r3, [r5]
 *   @0x18b9b0 mov r1, #256
 *   @0x18b9b4 mov r2, #1
 *   @0x18b9b8 ldr r0, [r4, r0]
 *   @0x18b9bc bl 0xb68c8 <fread@plt>
 *   @0x18b9c0 ldr r0, [pc, #0x110]
 *   @0x18b9c4 ldr r3, [r5]
 *   @0x18b9c8 mov r1, #40
 *   @0x18b9cc mov r2, #1
 *   @0x18b9d0 ldr r0, [r4, r0]
 *   @0x18b9d4 bl 0xb68c8 <fread@plt>
 *   @0x18b9d8 ldr r0, [pc, #0xfc]
 *   @0x18b9dc ldr r3, [r5]
 *   @0x18b9e0 mov r1, #40
 *   @0x18b9e4 mov r2, #1
 *   @0x18b9e8 ldr r0, [r4, r0]
 *   @0x18b9ec bl 0xb68c8 <fread@plt>
 *   @0x18b9f0 ldr r0, [pc, #0xe8]
 *   @0x18b9f4 ldr r3, [r5]
 *   @0x18b9f8 mov r1, #30
 *   @0x18b9fc mov r2, #1
 *   @0x18ba00 ldr r0, [r4, r0]
 *   @0x18ba04 bl 0xb68c8 <fread@plt>
 *   @0x18ba08 ldr r0, [pc, #0xd4]
 *   @0x18ba0c ldr r3, [r5]
 *   @0x18ba10 mov r1, #30
 *   @0x18ba14 mov r2, #1
 *   @0x18ba18 ldr r0, [r4, r0]
 *   @0x18ba1c bl 0xb68c8 <fread@plt>
 *   @0x18ba20 ldr r0, [pc, #0xc0]
 *   @0x18ba24 ldr r3, [r5]
 *   @0x18ba28 mov r1, #30
 *   @0x18ba2c mov r2, #1
 *   @0x18ba30 ldr r0, [r4, r0]
 *   @0x18ba34 bl 0xb68c8 <fread@plt>
 *   @0x18ba38 ldr r0, [pc, #0xac]
 *   @0x18ba3c ldr r3, [r5]
 *   @0x18ba40 mov r1, #10
 *   @0x18ba44 mov r2, #1
 *   @0x18ba48 ldr r0, [r4, r0]
 *   @0x18ba4c bl 0xb68c8 <fread@plt>
 *   @0x18ba50 ldr r0, [pc, #0x98]
 *   @0x18ba54 ldr r3, [r5]
 *   @0x18ba58 mov r1, #10
 *   @0x18ba5c mov r2, #1
 *   @0x18ba60 ldr r0, [r4, r0]
 *   @0x18ba64 bl 0xb68c8 <fread@plt>
 *   @0x18ba68 ldr r0, [pc, #0x84]
 *   @0x18ba6c ldr r3, [r5]
 *   @0x18ba70 mov r1, #8
 *   @0x18ba74 mov r2, #1
 *   @0x18ba78 ldr r0, [r4, r0]
 *   @0x18ba7c bl 0xb68c8 <fread@plt>
 *   @0x18ba80 ldr r0, [pc, #0x70]
 *   @0x18ba84 ldr r3, [r5]
 *   @0x18ba88 mov r1, #4
 *   @0x18ba8c mov r2, #1
 *   @0x18ba90 ldr r0, [r4, r0]
 *   @0x18ba94 bl 0xb68c8 <fread@plt>
 *   @0x18ba98 ldr r0, [pc, #0x5c]
 *   @0x18ba9c ldr r3, [r5]
 *   @0x18baa0 mov r1, #4
 *   @0x18baa4 mov r2, #1
 *   @0x18baa8 ldr r0, [r4, r0]
 *   @0x18baac pop {r4, r5, r6, lr}
 *   @0x18bab0 b 0xb68c8 <fread@plt>
 *   @0x18bab4 eoreq r6, r6, r8, asr r3
 *   @0x18bab8 .word 0xffffe97c
 *   @0x18babc .word 0xffffe980
 *   @0x18bac0 .word 0xffffe984
 *   @0x18bac4 .word 0xffffe988
 *   @0x18bac8 .word 0xffffe98c
 *   @0x18bacc .word 0xffffe990
 *   @0x18bad0 .word 0xffffe994
 *   @0x18bad4 .word 0xffffe998
 *   @0x18bad8 .word 0xffffe99c
 *   @0x18badc .word 0xffffe9a0
 *   @0x18bae0 .word 0xffffe9a4
 *   @0x18bae4 .word 0xffffe9a8
 *   @0x18bae8 .word 0xffffe9ac
 *   @0x18baec .word 0xffffe9b0
 *   @0x18baf0 .word 0xffffe9b4
 *   @0x18baf4 .word 0xffffe9b8
 *   @0x18baf8 .word 0xffffe720
 *   @0x18bafc .word 0xffffe724
 *
 * ══ §36/54 CLayerManager::CleanRoomLayers  0x1b93c8  size 528  129 条（0x1b93c8..0x1b95d8）
 * @func 0x1b93c8 0x1b95d8  size 528  129 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×4 / CLayerManager::RemoveElement(CRoom*, CLayer*, CLayerElementBase*, bool) / MemoryInWad(void*) / CTimingSource::Reset() / operator delete(void*)
 * 字段偏移 top8: 0x68×5 / 0x58×4 / 0x1c×4 / 0x14×4 / 0xd4×3 / 0x6c×3 / 0xdc×2 / 0x64×2
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b93c8 push {r4, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1b93cc vpush {d8, d9}
 *   @0x1b93d0 subs r7, r0, #0
 *   @0x1b93d4 beq 0x1b955c <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0x194>
 *   @0x1b93d8 ldr r6, [r7, #0xd4]
 *   @0x1b93dc cmp r6, #0
 *   @0x1b93e0 beq 0x1b9544 <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0x17c>
 *   @0x1b93e4 ldr r9, [pc, #0x1e8]
 *   @0x1b93e8 mov r8, #0
 *   @0x1b93ec mvn r10, #0
 *   @0x1b93f0 mov r11, #1
 *   @0x1b93f4 ldr r9, [pc, r9]
 *   @0x1b93f8 vldr s16, [pc, #464]
 *   @0x1b93fc vldr d9, [pc, #452]
 *   @0x1b9400 b 0x1b9414 <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0x4c>
 *   @0x1b9404 mov r0, r7
 *   @0x1b9408 mov r1, r6
 *   @0x1b940c mov r3, #0
 *   @0x1b9410 bl 0x1b8fdc <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb>
 *   @0x1b9414 ldr r2, [r6, #0x58]
 *   @0x1b9418 cmp r2, #0
 *   @0x1b941c bne 0x1b9404 <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0x3c>
 *   @0x1b9420 ldr r3, [r6, #0x6c]
 *   @0x1b9424 cmp r3, #0
 *   @0x1b9428 beq 0x1b95ac <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0x1e4>
 *   @0x1b942c ldr r2, [r6, #0x68]
 *   @0x1b9430 str r2, [r3, #0x68]
 *   @0x1b9434 ldr r2, [r6, #0x68]
 *   @0x1b9438 ldr r3, [r6, #0x6c]
 *   @0x1b943c cmp r2, #0
 *   @0x1b9440 strne r3, [r2, #0x6c]
 *   @0x1b9444 streq r3, [r7, #0xd8]
 *   @0x1b9448 ldr r3, [r7, #0xdc]
 *   @0x1b944c ldr r0, [r6, #0x1c]
 *   @0x1b9450 sub r3, r3, #1
 *   @0x1b9454 str r3, [r7, #0xdc]
 *   @0x1b9458 bl 0x1aad50 <_Z11MemoryInWadPv>
 *   @0x1b945c cmp r0, #0
 *   @0x1b9460 bne 0x1b946c <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0xa4>
 *   @0x1b9464 ldr r0, [r6, #0x1c]
 *   @0x1b9468 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b946c ldr r3, [r6, #0x64]
 *   @0x1b9470 str r8, [r6, #0x1c]
 *   @0x1b9474 cmp r3, #0
 *   @0x1b9478 beq 0x1b94b0 <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0xe8>
 *   @0x1b947c ldr r0, [r6, #0x58]
 *   @0x1b9480 cmp r0, #0
 *   @0x1b9484 beq 0x1b94b0 <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0xe8>
 *   @0x1b9488 cmp r3, #2
 *   @0x1b948c beq 0x1b9564 <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0x19c>
 *   @0x1b9490 cmp r3, #3
 *   @0x1b9494 beq 0x1b957c <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0x1b4>
 *   @0x1b9498 cmp r3, #1
 *   @0x1b949c beq 0x1b9594 <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0x1cc>
 *   @0x1b94a0 ldr r4, [r0, #0x14]
 *   @0x1b94a4 cmp r4, #0
 *   @0x1b94a8 mov r0, r4
 *   @0x1b94ac bne 0x1b94a0 <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0xd8>
 *   @0x1b94b0 str r8, [r6, #0x60]
 *   @0x1b94b4 vstr s16, [r6, #8]
 *   @0x1b94b8 str r8, [r6, #0x5c]
 *   @0x1b94bc vstr s16, [r6, #12]
 *   @0x1b94c0 str r8, [r6, #0x58]
 *   @0x1b94c4 vstr s16, [r6, #16]
 *   @0x1b94c8 str r10, [r6]
 *   @0x1b94cc vstr s16, [r6, #20]
 *   @0x1b94d0 str r8, [r6, #0x4]
 *   @0x1b94d4 vstr d9, [r6, #72]
 *   @0x1b94d8 strb r11, [r6, #0x18]
 *   @0x1b94dc add r0, r6, #48
 *   @0x1b94e0 strb r8, [r6, #0x19]
 *   @0x1b94e4 str r8, [r6, #0x1c]
 *   @0x1b94e8 str r10, [r6, #0x20]
 *   @0x1b94ec str r10, [r6, #0x24]
 *   @0x1b94f0 str r10, [r6, #0x28]
 *   @0x1b94f4 bl 0x214728 <_ZN13CTimingSource5ResetEv>
 *   @0x1b94f8 ldr r3, [r9]
 *   @0x1b94fc ldr r2, [r9, #0x8]
 *   @0x1b9500 cmp r3, #0
 *   @0x1b9504 str r8, [r6, #0x68]
 *   @0x1b9508 str r8, [r6, #0x6c]
 *   @0x1b950c add r2, r2, #1
 *   @0x1b9510 str r8, [r6, #0x5c]
 *   @0x1b9514 str r8, [r6, #0x58]
 *   @0x1b9518 str r8, [r6, #0x60]
 *   @0x1b951c str r11, [r6, #0x64]
 *   @0x1b9520 str r2, [r9, #0x8]
 *   @0x1b9524 strne r6, [r3, #0x6c]
 *   @0x1b9528 strne r6, [r9]
 *   @0x1b952c strne r3, [r6, #0x68]
 *   @0x1b9530 strne r8, [r6, #0x6c]
 *   @0x1b9534 beq 0x1b95b8 <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0x1f0>
 *   @0x1b9538 ldr r6, [r7, #0xd4]
 *   @0x1b953c cmp r6, #0
 *   @0x1b9540 bne 0x1b9414 <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0x4c>
 *   @0x1b9544 ldr r0, [r7, #0xf4]
 *   @0x1b9548 cmp r0, #0
 *   @0x1b954c beq 0x1b9554 <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0x18c>
 *   @0x1b9550 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b9554 mov r3, #0
 *   @0x1b9558 str r3, [r7, #0xf4]
 *   @0x1b955c vpop {d8, d9}
 *   @0x1b9560 pop {r4, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1b9564 ldr r4, [r0, #0x14]
 *   @0x1b9568 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b956c cmp r4, #0
 *   @0x1b9570 mov r0, r4
 *   @0x1b9574 bne 0x1b9564 <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0x19c>
 *   @0x1b9578 b 0x1b94b0 <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0xe8>
 *   @0x1b957c ldr r4, [r0, #0x14]
 *   @0x1b9580 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b9584 cmp r4, #0
 *   @0x1b9588 mov r0, r4
 *   @0x1b958c bne 0x1b957c <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0x1b4>
 *   @0x1b9590 b 0x1b94b0 <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0xe8>
 *   @0x1b9594 ldr r4, [r0, #0x14]
 *   @0x1b9598 bl 0x27d1d0 <_ZdlPv>
 *   @0x1b959c cmp r4, #0
 *   @0x1b95a0 mov r0, r4
 *   @0x1b95a4 bne 0x1b9594 <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0x1cc>
 *   @0x1b95a8 b 0x1b94b0 <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0xe8>
 *   @0x1b95ac ldr r2, [r6, #0x68]
 *   @0x1b95b0 str r2, [r7, #0xd4]
 *   @0x1b95b4 b 0x1b943c <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0x74>
 *   @0x1b95b8 str r6, [r9, #0x4]
 *   @0x1b95bc str r6, [r9]
 *   @0x1b95c0 b 0x1b9538 <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0x170>
 *   @0x1b95c4 nop
 *   @0x1b95d4 eoreq r7, r3, r8, ror #8
 *
 * ══ §37/54 alutGetErrorString  0x221730  size 528  132 条（0x221730..0x221940）
 * @func 0x221730 0x221940  size 528  132 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: alutGetErrorString+0x4c / alutGetErrorString+0x1b4 / alutGetErrorString+0x128 / alutGetErrorString+0x184 / alutGetErrorString+0x154
 * 字段偏移 top8: 0x178×1 / 0x138×1 / 0x104×1 / 0xd8×1 / 0xd0×1 / 0xc8×1 / 0xc0×1 / 0xb8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x221730 cmp r0, #520
 *   @0x221734 beq 0x2218cc <alutGetErrorString+0x19c>
 *   @0x221738 ble 0x22177c <alutGetErrorString+0x4c>
 *   @0x22173c movw r3, #0x20d
 *   @0x221740 cmp r0, r3
 *   @0x221744 beq 0x22189c <alutGetErrorString+0x16c>
 *   @0x221748 bgt 0x2217f8 <alutGetErrorString+0xc8>
 *   @0x22174c movw r3, #0x20a
 *   @0x221750 cmp r0, r3
 *   @0x221754 beq 0x22184c <alutGetErrorString+0x11c>
 *   @0x221758 blt 0x2218e4 <alutGetErrorString+0x1b4>
 *   @0x22175c add r3, r3, #1
 *   @0x221760 cmp r0, r3
 *   @0x221764 beq 0x2218d8 <alutGetErrorString+0x1a8>
 *   @0x221768 cmp r0, #524
 *   @0x22176c bne 0x221890 <alutGetErrorString+0x160>
 *   @0x221770 ldr r0, [pc, #0x178]
 *   @0x221774 add r0, pc, r0
 *   @0x221778 bx lr
 *   @0x22177c movw r3, #0x203
 *   @0x221780 cmp r0, r3
 *   @0x221784 beq 0x2218c0 <alutGetErrorString+0x190>
 *   @0x221788 cmp r0, #516
 *   @0x22178c bge 0x2217c0 <alutGetErrorString+0x90>
 *   @0x221790 cmp r0, #512
 *   @0x221794 beq 0x221834 <alutGetErrorString+0x104>
 *   @0x221798 ble 0x221858 <alutGetErrorString+0x128>
 *   @0x22179c movw r3, #0x201
 *   @0x2217a0 cmp r0, r3
 *   @0x2217a4 beq 0x22186c <alutGetErrorString+0x13c>
 *   @0x2217a8 add r3, r3, #1
 *   @0x2217ac cmp r0, r3
 *   @0x2217b0 bne 0x221890 <alutGetErrorString+0x160>
 *   @0x2217b4 ldr r0, [pc, #0x138]
 *   @0x2217b8 add r0, pc, r0
 *   @0x2217bc bx lr
 *   @0x2217c0 movw r3, #0x205
 *   @0x2217c4 cmp r0, r3
 *   @0x2217c8 beq 0x221828 <alutGetErrorString+0xf8>
 *   @0x2217cc cmp r0, #516
 *   @0x2217d0 ble 0x2218b4 <alutGetErrorString+0x184>
 *   @0x2217d4 add r3, r3, #1
 *   @0x2217d8 cmp r0, r3
 *   @0x2217dc beq 0x2218a8 <alutGetErrorString+0x178>
 *   @0x2217e0 add r3, r3, #1
 *   @0x2217e4 cmp r0, r3
 *   @0x2217e8 bne 0x221890 <alutGetErrorString+0x160>
 *   @0x2217ec ldr r0, [pc, #0x104]
 *   @0x2217f0 add r0, pc, r0
 *   @0x2217f4 bx lr
 *   @0x2217f8 movw r3, #0x20f
 *   @0x2217fc cmp r0, r3
 *   @0x221800 beq 0x221840 <alutGetErrorString+0x110>
 *   @0x221804 blt 0x221884 <alutGetErrorString+0x154>
 *   @0x221808 cmp r0, #528
 *   @0x22180c beq 0x221878 <alutGetErrorString+0x148>
 *   @0x221810 add r3, r3, #2
 *   @0x221814 cmp r0, r3
 *   @0x221818 bne 0x221890 <alutGetErrorString+0x160>
 *   @0x22181c ldr r0, [pc, #0xd8]
 *   @0x221820 add r0, pc, r0
 *   @0x221824 bx lr
 *   @0x221828 ldr r0, [pc, #0xd0]
 *   @0x22182c add r0, pc, r0
 *   @0x221830 bx lr
 *   @0x221834 ldr r0, [pc, #0xc8]
 *   @0x221838 add r0, pc, r0
 *   @0x22183c bx lr
 *   @0x221840 ldr r0, [pc, #0xc0]
 *   @0x221844 add r0, pc, r0
 *   @0x221848 bx lr
 *   @0x22184c ldr r0, [pc, #0xb8]
 *   @0x221850 add r0, pc, r0
 *   @0x221854 bx lr
 *   @0x221858 cmp r0, #0
 *   @0x22185c bne 0x221890 <alutGetErrorString+0x160>
 *   @0x221860 ldr r0, [pc, #0xa8]
 *   @0x221864 add r0, pc, r0
 *   @0x221868 bx lr
 *   @0x22186c ldr r0, [pc, #0xa0]
 *   @0x221870 add r0, pc, r0
 *   @0x221874 bx lr
 *   @0x221878 ldr r0, [pc, #0x98]
 *   @0x22187c add r0, pc, r0
 *   @0x221880 bx lr
 *   @0x221884 ldr r0, [pc, #0x90]
 *   @0x221888 add r0, pc, r0
 *   @0x22188c bx lr
 *   @0x221890 ldr r0, [pc, #0x88]
 *   @0x221894 add r0, pc, r0
 *   @0x221898 bx lr
 *   @0x22189c ldr r0, [pc, #0x80]
 *   @0x2218a0 add r0, pc, r0
 *   @0x2218a4 bx lr
 *   @0x2218a8 ldr r0, [pc, #0x78]
 *   @0x2218ac add r0, pc, r0
 *   @0x2218b0 bx lr
 *   @0x2218b4 ldr r0, [pc, #0x70]
 *   @0x2218b8 add r0, pc, r0
 *   @0x2218bc bx lr
 *   @0x2218c0 ldr r0, [pc, #0x68]
 *   @0x2218c4 add r0, pc, r0
 *   @0x2218c8 bx lr
 *   @0x2218cc ldr r0, [pc, #0x60]
 *   @0x2218d0 add r0, pc, r0
 *   @0x2218d4 bx lr
 *   @0x2218d8 ldr r0, [pc, #0x58]
 *   @0x2218dc add r0, pc, r0
 *   @0x2218e0 bx lr
 *   @0x2218e4 ldr r0, [pc, #0x50]
 *   @0x2218e8 add r0, pc, r0
 *   @0x2218ec bx lr
 *   @0x2218f0 andseq r3, r3, r4, asr r3
 *   @0x2218f4 andseq r3, r3, r4, asr #2
 *   @0x2218f8 ldrsheq r3, [r3], -r8
 *   @0x2218fc andseq r3, r3, r0, ror #6
 *   @0x221900 andseq r3, r3, r4, asr #2
 *   @0x221904 andseq r3, r3, r0, lsl #1
 *   @0x221908 andseq r3, r3, r12, ror #5
 *   @0x22190c andseq r3, r3, r12, lsl r2
 *   @0x221910 andseq r3, r3, r0, asr #32
 *   @0x221914 andseq r3, r3, r0, rrx
 *   @0x221918 andseq r3, r3, r12, asr #5
 *   @0x22191c mulseq r3, r12, r2
 *   @0x221920 andseq r3, r3, r4, lsl r3
 *   @0x221924 andseq r3, r3, r4, asr r2
 *   @0x221928 andseq r3, r3, r0, lsl #2
 *   @0x22192c mulseq r3, r8, r0
 *   @0x221930 andseq r3, r3, r8, asr r0
 *   @0x221934 andseq r3, r3, r4, asr #2
 *   @0x221938 ldrheq r3, [r3], -r12
 *   @0x22193c andseq r3, r3, r8, asr r1
 *
 * ══ §38/54 b2ParticleSystem::SolveViscous  0x2d8c88  size 528  132 条（0x2d8c88..0x2d8e98）
 * @func 0x2d8c88 0x2d8ea8  size 544  136 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ParticleSystem::SolveViscous(b2TimeStep const&)+0x108 / b2ParticleSystem::GetParticleInvMass() const / b2ParticleSystem::SolveViscous(b2TimeStep const&)+0x1a0
 * 字段偏移 top8: 0x80×3 / 0x4×2 / 0x40×2 / 0x88×1 / 0x30×1 / 0x2×1 / 0x38×1 / 0x74×1
 * VFP 指令 70 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d8c88 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2d8c8c vpush {d8, d9, d10}
 *   @0x2d8c90 mov r5, r0
 *   @0x2d8c94 vldr s16, [r0, #188]
 *   @0x2d8c98 ldr r0, [r0, #0x80]
 *   @0x2d8c9c cmp r0, #0
 *   @0x2d8ca0 movgt r4, #0
 *   @0x2d8ca4 movgt r9, #0
 *   @0x2d8ca8 movgt r6, r4
 *   @0x2d8cac bgt 0x2d8cc4 <_ZN16b2ParticleSystem12SolveViscousERK10b2TimeStep+0x3c>
 *   @0x2d8cb0 b 0x2d8d90 <_ZN16b2ParticleSystem12SolveViscousERK10b2TimeStep+0x108>
 *   @0x2d8cb4 add r6, r6, #1
 *   @0x2d8cb8 add r4, r4, #24
 *   @0x2d8cbc cmp r0, r6
 *   @0x2d8cc0 ble 0x2d8d90 <_ZN16b2ParticleSystem12SolveViscousERK10b2TimeStep+0x108>
 *   @0x2d8cc4 ldr r3, [r5, #0x88]
 *   @0x2d8cc8 ldr r2, [r5, #0x30]
 *   @0x2d8ccc add r1, r3, r4
 *   @0x2d8cd0 ldr r3, [r3, r4]
 *   @0x2d8cd4 ldr r2, [r2, r3, lsl #2]
 *   @0x2d8cd8 tst r2, #32
 *   @0x2d8cdc beq 0x2d8cb4 <_ZN16b2ParticleSystem12SolveViscousERK10b2TimeStep+0x2c>
 *   @0x2d8ce0 ldr r2, [r5, #0x38]
 *   @0x2d8ce4 lsl r3, r3, #3
 *   @0x2d8ce8 ldr r7, [r1, #0x4]
 *   @0x2d8cec vldr s9, [r7, #60]
 *   @0x2d8cf0 add r2, r2, r3
 *   @0x2d8cf4 vldr s10, [r7, #64]
 *   @0x2d8cf8 vldr s17, [r2]
 *   @0x2d8cfc vldr s20, [r2, #4]
 *   @0x2d8d00 vsub.f32 s9, s17, s9
 *   @0x2d8d04 vldr s12, [r7, #88]
 *   @0x2d8d08 vldr s14, [r7, #84]
 *   @0x2d8d0c vldr s15, [r7, #80]
 *   @0x2d8d10 vldr s13, [r1, #20]
 *   @0x2d8d14 ldr r8, [r5, #0x40]
 *   @0x2d8d18 vldr s11, [r1, #8]
 *   @0x2d8d1c mov r0, r5
 *   @0x2d8d20 add r8, r8, r3
 *   @0x2d8d24 vldr s19, [r8, #4]
 *   @0x2d8d28 vldr s18, [r8]
 *   @0x2d8d2c vsub.f32 s10, s20, s10
 *   @0x2d8d30 vmla.f32 s14, s12, s9
 *   @0x2d8d34 vmls.f32 s15, s12, s10
 *   @0x2d8d38 vmul.f32 s13, s16, s13
 *   @0x2d8d3c vmul.f32 s13, s13, s11
 *   @0x2d8d40 vsub.f32 s14, s14, s19
 *   @0x2d8d44 vsub.f32 s15, s15, s18
 *   @0x2d8d48 vmul.f32 s19, s13, s14
 *   @0x2d8d4c vmul.f32 s18, s13, s15
 *   @0x2d8d50 bl 0x2d8a20 <_ZNK16b2ParticleSystem18GetParticleInvMassEv>
 *   @0x2d8d54 vldr s14, [r8]
 *   @0x2d8d58 vldr s15, [r8, #4]
 *   @0x2d8d5c ldr r3, [r7]
 *   @0x2d8d60 cmp r3, #2
 *   @0x2d8d64 vmov s13, r0
 *   @0x2d8d68 vmla.f32 s14, s13, s18
 *   @0x2d8d6c vmla.f32 s15, s13, s19
 *   @0x2d8d70 vstr s14, [r8]
 *   @0x2d8d74 vstr s15, [r8, #4]
 *   @0x2d8d78 beq 0x2d8e30 <_ZN16b2ParticleSystem12SolveViscousERK10b2TimeStep+0x1a8>
 *   @0x2d8d7c ldr r0, [r5, #0x80]
 *   @0x2d8d80 add r6, r6, #1
 *   @0x2d8d84 add r4, r4, #24
 *   @0x2d8d88 cmp r0, r6
 *   @0x2d8d8c bgt 0x2d8cc4 <_ZN16b2ParticleSystem12SolveViscousERK10b2TimeStep+0x3c>
 *   @0x2d8d90 ldr r0, [r5, #0x74]
 *   @0x2d8d94 cmp r0, #0
 *   @0x2d8d98 ble 0x2d8e28 <_ZN16b2ParticleSystem12SolveViscousERK10b2TimeStep+0x1a0>
 *   @0x2d8d9c ldr r3, [r5, #0x7c]
 *   @0x2d8da0 add r0, r0, r0, lsl #1
 *   @0x2d8da4 add r3, r3, #8
 *   @0x2d8da8 add r0, r3, r0, lsl #3
 *   @0x2d8dac ldr r2, [r3]
 *   @0x2d8db0 tst r2, #32
 *   @0x2d8db4 beq 0x2d8e1c <_ZN16b2ParticleSystem12SolveViscousERK10b2TimeStep+0x194>
 *   @0x2d8db8 ldr r2, [r3, #-0x4]
 *   @0x2d8dbc vldr s11, [r3, #4]
 *   @0x2d8dc0 ldr r12, [r3, #-0x8]
 *   @0x2d8dc4 vmul.f32 s11, s16, s11
 *   @0x2d8dc8 ldr r1, [r5, #0x40]
 *   @0x2d8dcc add r2, r1, r2, lsl #3
 *   @0x2d8dd0 add r1, r1, r12, lsl #3
 *   @0x2d8dd4 vldr s14, [r2]
 *   @0x2d8dd8 vldr s12, [r1]
 *   @0x2d8ddc vldr s13, [r1, #4]
 *   @0x2d8de0 vldr s15, [r2, #4]
 *   @0x2d8de4 vsub.f32 s14, s14, s12
 *   @0x2d8de8 vsub.f32 s15, s15, s13
 *   @0x2d8dec vmul.f32 s14, s11, s14
 *   @0x2d8df0 vmul.f32 s15, s11, s15
 *   @0x2d8df4 vadd.f32 s12, s12, s14
 *   @0x2d8df8 vadd.f32 s13, s13, s15
 *   @0x2d8dfc vstr s12, [r1]
 *   @0x2d8e00 vldr s12, [r2]
 *   @0x2d8e04 vstr s13, [r1, #4]
 *   @0x2d8e08 vsub.f32 s14, s12, s14
 *   @0x2d8e0c vldr s13, [r2, #4]
 *   @0x2d8e10 vsub.f32 s15, s13, s15
 *   @0x2d8e14 vstr s14, [r2]
 *   @0x2d8e18 vstr s15, [r2, #4]
 *   @0x2d8e1c add r3, r3, #24
 *   @0x2d8e20 cmp r3, r0
 *   @0x2d8e24 bne 0x2d8dac <_ZN16b2ParticleSystem12SolveViscousERK10b2TimeStep+0x124>
 *   @0x2d8e28 vpop {d8, d9, d10}
 *   @0x2d8e2c pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2d8e30 vldr s15, [r7, #64]
 *   @0x2d8e34 vsub.f32 s20, s20, s15
 *   @0x2d8e38 vldr s10, [r7, #60]
 *   @0x2d8e3c vldr s14, [r7, #88]
 *   @0x2d8e40 vldr s11, [r7, #136]
 *   @0x2d8e44 vldr s12, [r7, #80]
 *   @0x2d8e48 vldr s15, [r7, #84]
 *   @0x2d8e4c vldr s13, [r7, #144]
 *   @0x2d8e50 ldrh r3, [r7, #4]
 *   @0x2d8e54 ldr r0, [r5, #0x80]
 *   @0x2d8e58 tst r3, #2
 *   @0x2d8e5c orr r3, r3, #2
 *   @0x2d8e60 streq r9, [r7, #0xa0]
 *   @0x2d8e64 strheq r3, [r7, #4]
 *   @0x2d8e68 vneg.f32 s18, s18
 *   @0x2d8e6c vmul.f32 s20, s18, s20
 *   @0x2d8e70 vsub.f32 s17, s17, s10
 *   @0x2d8e74 vneg.f32 s19, s19
 *   @0x2d8e78 vnmls.f32 s20, s19, s17
 *   @0x2d8e7c vmla.f32 s12, s18, s11
 *   @0x2d8e80 vmla.f32 s14, s20, s13
 *   @0x2d8e84 vstr s12, [r7, #80]
 *   @0x2d8e88 vmla.f32 s15, s19, s11
 *   @0x2d8e8c vstr s14, [r7, #88]
 *   @0x2d8e90 vstr s15, [r7, #84]
 *   @0x2d8e94 b 0x2d8cb4 <_ZN16b2ParticleSystem12SolveViscousERK10b2TimeStep+0x2c>
 *
 * ══ §39/54 anon_28775c  0x28775c  size 524  131 条（0x28775c..0x287968）
 * @func 0x28775c 0x287968  size 524  131 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6c70×3 / 0xb67e4×2 / 0xb67d8×2 / 0xfe5b6b80
 * 字段偏移 top8: 无
 * VFP 指令 101 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28775c vcmp.f32 s0, #0
 *   @0x287760 push {r4, lr}
 *   @0x287764 vmrs APSR_nzcv, fpscr
 *   @0x287768 beq 0x287818 <spPathAttachment_computeWorldVertices1+0xd8>
 *   @0x28776c vmov.f32 s12, #1.000000e+00
 *   @0x287770 vsub.f32 s12, s12, s0
 *   @0x287774 vmul.f32 s9, s0, s12
 *   @0x287778 vmov.f32 s13, #3.000000e+00
 *   @0x28777c vmul.f32 s10, s12, s12
 *   @0x287780 vmul.f32 s13, s9, s13
 *   @0x287784 vmul.f32 s11, s0, s0
 *   @0x287788 vmul.f32 s14, s12, s13
 *   @0x28778c vmul.f32 s13, s0, s13
 *   @0x287790 vmul.f32 s12, s12, s10
 *   @0x287794 vmul.f32 s0, s0, s11
 *   @0x287798 cmp r2, #0
 *   @0x28779c add r4, r0, r1, lsl #2
 *   @0x2877a0 vmul.f32 s15, s3, s14
 *   @0x2877a4 vmul.f32 s14, s4, s14
 *   @0x2877a8 vmla.f32 s15, s1, s12
 *   @0x2877ac vmla.f32 s14, s2, s12
 *   @0x2877b0 vmla.f32 s15, s5, s13
 *   @0x2877b4 vmla.f32 s14, s6, s13
 *   @0x2877b8 vmla.f32 s15, s7, s0
 *   @0x2877bc vmla.f32 s14, s8, s0
 *   @0x2877c0 vstr s15, [r4]
 *   @0x2877c4 vstr s14, [r4, #4]
 *   @0x2877c8 popeq {r4, pc}
 *   @0x2877cc vmul.f32 s4, s4, s9
 *   @0x2877d0 vmul.f32 s3, s3, s9
 *   @0x2877d4 vadd.f32 s4, s4, s4
 *   @0x2877d8 vadd.f32 s3, s3, s3
 *   @0x2877dc vmla.f32 s4, s2, s10
 *   @0x2877e0 vmla.f32 s3, s1, s10
 *   @0x2877e4 vmla.f32 s4, s6, s11
 *   @0x2877e8 vmla.f32 s3, s5, s11
 *   @0x2877ec vsub.f32 s14, s14, s4
 *   @0x2877f0 vsub.f32 s15, s15, s3
 *   @0x2877f4 vcvt.f64.f32 d6, s14
 *   @0x2877f8 vmov r0, r1, d6
 *   @0x2877fc vcvt.f64.f32 d6, s15
 *   @0x287800 vmov r2, r3, d6
 *   @0x287804 bl 0xb6c70 <atan2@plt>
 *   @0x287808 vmov d6, r0, r1
 *   @0x28780c vcvt.f32.f64 s15, d6
 *   @0x287810 vstr s15, [r4, #8]
 *   @0x287814 pop {r4, pc}
 *   @0x287818 vldr s13, [pc, #24]
 *   @0x28781c vldr s14, [pc, #24]
 *   @0x287820 vldr s9, [pc, #24]
 *   @0x287824 vldr s12, [pc, #24]
 *   @0x287828 vldr s10, [pc, #24]
 *   @0x28782c vldr s0, [pc, #24]
 *   @0x287830 vldr s11, [pc, #24]
 *   @0x287834 b 0x287798 <spPathAttachment_computeWorldVertices1+0x58>
 *   @0x287838 movwlo sp, #0x60c
 *   @0x28783c ldmiblo sp, {r0, r1, r6, r8, lr}
 *   @0x287840 ldmlo r1, {r3, r4, r5, r7, r8, r12, sp, pc} ^
 *   @0x287844 svclo #0x7fec56
 *   @0x287848 svclo #0x7ff2e4
 *   @0x28784c blhs 0xfe5b6b80 <b2_toiTime+0xfffffffffde5d6dc>
 *   @0x287850 eorlo r12, r11, #30208
 *   @0x287854 add r1, r1, #2
 *   @0x287858 push {r4, lr}
 *   @0x28785c vpush {d8, d9, d10}
 *   @0x287860 add r0, r0, r1, lsl #2
 *   @0x287864 vldr s21, [r0]
 *   @0x287868 vldr s14, [r0, #-8]
 *   @0x28786c vsub.f32 s14, s21, s14
 *   @0x287870 vldr s18, [r0, #4]
 *   @0x287874 vldr s15, [r0, #-4]
 *   @0x287878 lsl r4, r3, #2
 *   @0x28787c add r4, r2, r4
 *   @0x287880 vsub.f32 s15, s18, s15
 *   @0x287884 vcvt.f64.f32 d6, s14
 *   @0x287888 vmov r2, r3, d6
 *   @0x28788c vcvt.f64.f32 d6, s15
 *   @0x287890 vmov r0, r1, d6
 *   @0x287894 vmov.f32 s19, s0
 *   @0x287898 bl 0xb6c70 <atan2@plt>
 *   @0x28789c vmov d7, r0, r1
 *   @0x2878a0 vcvt.f32.f64 s20, d7
 *   @0x2878a4 vcvt.f64.f32 d8, s20
 *   @0x2878a8 vmov r0, r1, d8
 *   @0x2878ac bl 0xb67e4 <cos@plt>
 *   @0x2878b0 vmov d6, r0, r1
 *   @0x2878b4 vcvt.f32.f64 s15, d6
 *   @0x2878b8 vmov r0, r1, d8
 *   @0x2878bc vmla.f32 s21, s15, s19
 *   @0x2878c0 vstr s21, [r4]
 *   @0x2878c4 bl 0xb67d8 <sin@plt>
 *   @0x2878c8 vstr s20, [r4, #8]
 *   @0x2878cc vmov d6, r0, r1
 *   @0x2878d0 vcvt.f32.f64 s15, d6
 *   @0x2878d4 vmla.f32 s18, s15, s19
 *   @0x2878d8 vstr s18, [r4, #4]
 *   @0x2878dc vpop {d8, d9, d10}
 *   @0x2878e0 pop {r4, pc}
 *   @0x2878e4 push {r4, lr}
 *   @0x2878e8 vldr s15, [r0, #8]
 *   @0x2878ec vpush {d8, d9, d10}
 *   @0x2878f0 vldr s21, [r0]
 *   @0x2878f4 vsub.f32 s15, s15, s21
 *   @0x2878f8 vldr s18, [r0, #4]
 *   @0x2878fc vldr s14, [r0, #12]
 *   @0x287900 lsl r4, r2, #2
 *   @0x287904 add r4, r1, r4
 *   @0x287908 vsub.f32 s14, s14, s18
 *   @0x28790c vcvt.f64.f32 d6, s15
 *   @0x287910 vmov r2, r3, d6
 *   @0x287914 vcvt.f64.f32 d6, s14
 *   @0x287918 vmov r0, r1, d6
 *   @0x28791c vmov.f32 s19, s0
 *   @0x287920 bl 0xb6c70 <atan2@plt>
 *   @0x287924 vmov d7, r0, r1
 *   @0x287928 vcvt.f32.f64 s20, d7
 *   @0x28792c vcvt.f64.f32 d8, s20
 *   @0x287930 vmov r0, r1, d8
 *   @0x287934 bl 0xb67e4 <cos@plt>
 *   @0x287938 vmov d6, r0, r1
 *   @0x28793c vcvt.f32.f64 s15, d6
 *   @0x287940 vmov r0, r1, d8
 *   @0x287944 vmla.f32 s21, s15, s19
 *   @0x287948 vstr s21, [r4]
 *   @0x28794c bl 0xb67d8 <sin@plt>
 *   @0x287950 vstr s20, [r4, #8]
 *   @0x287954 vmov d6, r0, r1
 *   @0x287958 vcvt.f32.f64 s15, d6
 *   @0x28795c vmla.f32 s18, s19, s15
 *   @0x287960 vstr s18, [r4, #4]
 *   @0x287964 vpop {d8, d9, d10}
 *
 * ══ §40/54 b2ParticleSystem::SolvePowder  0x2d8e98  size 524  131 条（0x2d8e98..0x2d90a4）
 * @func 0x2d8e98 0x2d90a4  size 524  131 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ParticleSystem::GetCriticalVelocity(b2TimeStep const&) const / b2ParticleSystem::SolvePowder(b2TimeStep const&)+0xfc / b2ParticleSystem::SolvePowder(b2TimeStep const&)+0x3c / b2ParticleSystem::GetParticleInvMass() const / b2ParticleSystem::SolvePowder(b2TimeStep const&)+0x1a4 / b2ParticleSystem::SolvePowder(b2TimeStep const&)+0x194
 * 字段偏移 top8: 0x80×3 / 0x40×2 / 0x4×2 / 0x88×1 / 0x30×1 / 0x2×1 / 0x38×1 / 0x74×1
 * VFP 指令 65 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d8e98 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2d8e9c vpush {d8, d9, d10}
 *   @0x2d8ea0 mov r5, r0
 *   @0x2d8ea4 vldr s17, [r0, #200]
 *   @0x2d8ea8 bl 0x2d82e8 <_ZNK16b2ParticleSystem19GetCriticalVelocityERK10b2TimeStep>
 *   @0x2d8eac ldr r12, [r5, #0x80]
 *   @0x2d8eb0 cmp r12, #0
 *   @0x2d8eb4 movgt r4, #0
 *   @0x2d8eb8 vmovgt.f32 s16, #2.500000e-01
 *   @0x2d8ebc movgt r6, r4
 *   @0x2d8ec0 movgt r9, #0
 *   @0x2d8ec4 vmov s15, r0
 *   @0x2d8ec8 vmul.f32 s17, s17, s15
 *   @0x2d8ecc bgt 0x2d8ee4 <_ZN16b2ParticleSystem11SolvePowderERK10b2TimeStep+0x4c>
 *   @0x2d8ed0 b 0x2d8f94 <_ZN16b2ParticleSystem11SolvePowderERK10b2TimeStep+0xfc>
 *   @0x2d8ed4 add r6, r6, #1
 *   @0x2d8ed8 add r4, r4, #24
 *   @0x2d8edc cmp r12, r6
 *   @0x2d8ee0 ble 0x2d8f94 <_ZN16b2ParticleSystem11SolvePowderERK10b2TimeStep+0xfc>
 *   @0x2d8ee4 ldr r3, [r5, #0x88]
 *   @0x2d8ee8 ldr r1, [r5, #0x30]
 *   @0x2d8eec add r2, r3, r4
 *   @0x2d8ef0 ldr r3, [r3, r4]
 *   @0x2d8ef4 ldr r1, [r1, r3, lsl #2]
 *   @0x2d8ef8 tst r1, #64
 *   @0x2d8efc beq 0x2d8ed4 <_ZN16b2ParticleSystem11SolvePowderERK10b2TimeStep+0x3c>
 *   @0x2d8f00 vldr s15, [r2, #8]
 *   @0x2d8f04 vcmpe.f32 s15, s16
 *   @0x2d8f08 vmrs APSR_nzcv, fpscr
 *   @0x2d8f0c ble 0x2d8ed4 <_ZN16b2ParticleSystem11SolvePowderERK10b2TimeStep+0x3c>
 *   @0x2d8f10 vldr s14, [r2, #20]
 *   @0x2d8f14 vmul.f32 s14, s17, s14
 *   @0x2d8f18 ldr r1, [r5, #0x38]
 *   @0x2d8f1c lsl r3, r3, #3
 *   @0x2d8f20 ldr r7, [r5, #0x40]
 *   @0x2d8f24 mov r0, r5
 *   @0x2d8f28 vldr s18, [r2, #12]
 *   @0x2d8f2c vldr s19, [r2, #16]
 *   @0x2d8f30 add r7, r7, r3
 *   @0x2d8f34 ldr r8, [r2, #0x4]
 *   @0x2d8f38 add r2, r1, r3
 *   @0x2d8f3c vldr s20, [r2]
 *   @0x2d8f40 vldr s21, [r2, #4]
 *   @0x2d8f44 vsub.f32 s15, s15, s16
 *   @0x2d8f48 vmul.f32 s15, s14, s15
 *   @0x2d8f4c vmul.f32 s18, s15, s18
 *   @0x2d8f50 vmul.f32 s19, s15, s19
 *   @0x2d8f54 bl 0x2d8a20 <_ZNK16b2ParticleSystem18GetParticleInvMassEv>
 *   @0x2d8f58 vldr s13, [r7]
 *   @0x2d8f5c vldr s14, [r7, #4]
 *   @0x2d8f60 ldr r3, [r8]
 *   @0x2d8f64 cmp r3, #2
 *   @0x2d8f68 vmov s12, r0
 *   @0x2d8f6c vmls.f32 s13, s12, s18
 *   @0x2d8f70 vmls.f32 s14, s12, s19
 *   @0x2d8f74 vstr s13, [r7]
 *   @0x2d8f78 vstr s14, [r7, #4]
 *   @0x2d8f7c beq 0x2d9044 <_ZN16b2ParticleSystem11SolvePowderERK10b2TimeStep+0x1ac>
 *   @0x2d8f80 ldr r12, [r5, #0x80]
 *   @0x2d8f84 add r6, r6, #1
 *   @0x2d8f88 add r4, r4, #24
 *   @0x2d8f8c cmp r12, r6
 *   @0x2d8f90 bgt 0x2d8ee4 <_ZN16b2ParticleSystem11SolvePowderERK10b2TimeStep+0x4c>
 *   @0x2d8f94 ldr r12, [r5, #0x74]
 *   @0x2d8f98 cmp r12, #0
 *   @0x2d8f9c ble 0x2d903c <_ZN16b2ParticleSystem11SolvePowderERK10b2TimeStep+0x1a4>
 *   @0x2d8fa0 vmov.f32 s14, #2.500000e-01
 *   @0x2d8fa4 ldr r3, [r5, #0x7c]
 *   @0x2d8fa8 add r12, r12, r12, lsl #1
 *   @0x2d8fac add r2, r3, #8
 *   @0x2d8fb0 add r12, r3, r12, lsl #3
 *   @0x2d8fb4 ldr r1, [r3, #0x8]
 *   @0x2d8fb8 tst r1, #64
 *   @0x2d8fbc beq 0x2d902c <_ZN16b2ParticleSystem11SolvePowderERK10b2TimeStep+0x194>
 *   @0x2d8fc0 vldr s15, [r2, #4]
 *   @0x2d8fc4 vcmpe.f32 s15, s14
 *   @0x2d8fc8 vmrs APSR_nzcv, fpscr
 *   @0x2d8fcc ble 0x2d902c <_ZN16b2ParticleSystem11SolvePowderERK10b2TimeStep+0x194>
 *   @0x2d8fd0 vsub.f32 s15, s15, s14
 *   @0x2d8fd4 vldr s13, [r3, #16]
 *   @0x2d8fd8 vldr s10, [r3, #20]
 *   @0x2d8fdc ldr r0, [r2, #-0x8]
 *   @0x2d8fe0 ldr r1, [r5, #0x40]
 *   @0x2d8fe4 ldr r4, [r2, #-0x4]
 *   @0x2d8fe8 add r0, r1, r0, lsl #3
 *   @0x2d8fec vldr s12, [r0]
 *   @0x2d8ff0 vldr s11, [r0, #4]
 *   @0x2d8ff4 add r1, r1, r4, lsl #3
 *   @0x2d8ff8 vmul.f32 s15, s15, s17
 *   @0x2d8ffc vmul.f32 s13, s15, s13
 *   @0x2d9000 vmul.f32 s15, s15, s10
 *   @0x2d9004 vsub.f32 s12, s12, s13
 *   @0x2d9008 vsub.f32 s11, s11, s15
 *   @0x2d900c vstr s12, [r0]
 *   @0x2d9010 vldr s12, [r1]
 *   @0x2d9014 vstr s11, [r0, #4]
 *   @0x2d9018 vadd.f32 s13, s12, s13
 *   @0x2d901c vldr s12, [r1, #4]
 *   @0x2d9020 vadd.f32 s15, s12, s15
 *   @0x2d9024 vstr s13, [r1]
 *   @0x2d9028 vstr s15, [r1, #4]
 *   @0x2d902c add r3, r3, #24
 *   @0x2d9030 add r2, r2, #24
 *   @0x2d9034 cmp r3, r12
 *   @0x2d9038 bne 0x2d8fb4 <_ZN16b2ParticleSystem11SolvePowderERK10b2TimeStep+0x11c>
 *   @0x2d903c vpop {d8, d9, d10}
 *   @0x2d9040 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2d9044 vldr s15, [r8, #64]
 *   @0x2d9048 vsub.f32 s21, s21, s15
 *   @0x2d904c vldr s10, [r8, #60]
 *   @0x2d9050 vldr s14, [r8, #88]
 *   @0x2d9054 vldr s12, [r8, #136]
 *   @0x2d9058 vldr s13, [r8, #80]
 *   @0x2d905c vldr s15, [r8, #84]
 *   @0x2d9060 vldr s11, [r8, #144]
 *   @0x2d9064 ldrh r3, [r8, #4]
 *   @0x2d9068 ldr r12, [r5, #0x80]
 *   @0x2d906c tst r3, #2
 *   @0x2d9070 orr r3, r3, #2
 *   @0x2d9074 streq r9, [r8, #0xa0]
 *   @0x2d9078 strheq r3, [r8, #4]
 *   @0x2d907c vmul.f32 s21, s18, s21
 *   @0x2d9080 vsub.f32 s20, s20, s10
 *   @0x2d9084 vnmls.f32 s21, s19, s20
 *   @0x2d9088 vmla.f32 s13, s18, s12
 *   @0x2d908c vmla.f32 s14, s21, s11
 *   @0x2d9090 vstr s13, [r8, #80]
 *   @0x2d9094 vmla.f32 s15, s19, s12
 *   @0x2d9098 vstr s14, [r8, #88]
 *   @0x2d909c vstr s15, [r8, #84]
 *   @0x2d90a0 b 0x2d8ed4 <_ZN16b2ParticleSystem11SolvePowderERK10b2TimeStep+0x3c>
 *
 * ══ §41/54 Graphics::CreateTexture  0x18269c  size 520  130 条（0x18269c..0x1828a4）
 * @func 0x18269c 0x1828a4  size 520  130 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1826e4→0x4a2120, 0x182704→0x4a2110, 0x182794→0x479bb4, 0x1827b4→0x479bbc, 0x1827cc→0x479bb0, 0x182834→0x4a2110
 * 调用序列: GetPOW2Size(int)×2 / operator new(unsigned int)×2 / _InvalidateTextureState() / MemoryManager::Alloc(unsigned int, char const*, int, bool) / _SetTextureNPOTFlags(Texture*) / _SetupRenderTargetFBO(Texture*, int, int)
 * 字段偏移 top8: 0x24×4 / 0x28×4 / 0x10×3 / 0x4×3 / 0x8×3 / 0xc×3 / 0x14×3 / 0x2c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18269c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1826a0 cmp r1, #0
 *   @0x1826a4 cmpne r0, #0
 *   @0x1826a8 sub sp, sp, #28
 *   @0x1826ac ldr r7, [pc, #0x1d4]
 *   @0x1826b0 mov r5, r1
 *   @0x1826b4 movne r6, #0
 *   @0x1826b8 moveq r6, #1
 *   @0x1826bc add r7, pc, r7
 *   @0x1826c0 mov r11, r2
 *   @0x1826c4 mov r10, r3
 *   @0x1826c8 mov r8, r0
 *   @0x1826cc ldr r9, [sp, #0x40]
 *   @0x1826d0 beq 0x18282c <_ZN8Graphics13CreateTextureEiii13eTextureFlags14eTextureFormat+0x190>
 *   @0x1826d4 bl 0x181320 <_Z11GetPOW2Sizei>
 *   @0x1826d8 mov r4, r0
 *   @0x1826dc mov r0, r5
 *   @0x1826e0 bl 0x181320 <_Z11GetPOW2Sizei>
 *   @0x1826e4 ldr r3, [pc, #0x1a0]
 *   @0x1826e8 ldr r3, [r7, r3]
 *   @0x1826ec ldrb r3, [r3]
 *   @0x1826f0 cmp r3, #0
 *   @0x1826f4 moveq r8, r4
 *   @0x1826f8 moveq r5, r0
 *   @0x1826fc mov r0, #56
 *   @0x182700 bl 0x27c524 <_Znwj>
 *   @0x182704 ldr r3, [pc, #0x184]
 *   @0x182708 mvn r1, #0
 *   @0x18270c str r6, [r0, #0x24]
 *   @0x182710 mov r4, r0
 *   @0x182714 str r6, [r0, #0x28]
 *   @0x182718 str r6, [r0, #0x2c]
 *   @0x18271c str r6, [r0, #0x30]
 *   @0x182720 str r6, [r0, #0x10]
 *   @0x182724 ldr r3, [r7, r3]
 *   @0x182728 str r8, [r0, #0x4]
 *   @0x18272c str r5, [r0, #0x8]
 *   @0x182730 ldr r2, [r3]
 *   @0x182734 str r11, [r0, #0xc]
 *   @0x182738 str r0, [r3]
 *   @0x18273c str r2, [r0, #0x34]
 *   @0x182740 str r9, [r0]
 *   @0x182744 str r1, [r0, #0x14]
 *   @0x182748 str r1, [r0, #0x18]
 *   @0x18274c str r1, [r0, #0x1c]
 *   @0x182750 str r1, [r0, #0x20]
 *   @0x182754 bl 0x182598 <_Z23_InvalidateTextureStatev>
 *   @0x182758 ands r3, r10, #2
 *   @0x18275c bne 0x182794 <_ZN8Graphics13CreateTextureEiii13eTextureFlags14eTextureFormat+0xf8>
 *   @0x182760 mul r5, r5, r8
 *   @0x182764 ldr r1, [pc, #0x128]
 *   @0x182768 movw r2, #0x506
 *   @0x18276c add r1, pc, r1
 *   @0x182770 add r0, r5, #4
 *   @0x182774 lsl r0, r0, #2
 *   @0x182778 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x18277c mov r3, r0
 *   @0x182780 mov r0, r4
 *   @0x182784 str r3, [r4, #0x24]
 *   @0x182788 str r3, [r4, #0x28]
 *   @0x18278c add sp, sp, #28
 *   @0x182790 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x182794 ldr r3, [pc, #0xfc]
 *   @0x182798 add r1, r4, #20
 *   @0x18279c str r6, [r4, #0x24]
 *   @0x1827a0 mov r0, #1
 *   @0x1827a4 str r6, [r4, #0x28]
 *   @0x1827a8 ldr r3, [r7, r3]
 *   @0x1827ac ldr r3, [r3]
 *   @0x1827b0 blx r3
 *   @0x1827b4 ldr r3, [pc, #0xe0]
 *   @0x1827b8 ldr r1, [r4, #0x14]
 *   @0x1827bc movw r0, #0xde1
 *   @0x1827c0 ldr r3, [r7, r3]
 *   @0x1827c4 ldr r3, [r3]
 *   @0x1827c8 blx r3
 *   @0x1827cc ldr r3, [pc, #0xcc]
 *   @0x1827d0 movw r12, #0x1908
 *   @0x1827d4 movw lr, #0x1401
 *   @0x1827d8 mov r2, r12
 *   @0x1827dc mov r1, r6
 *   @0x1827e0 ldr r7, [r7, r3]
 *   @0x1827e4 movw r0, #0xde1
 *   @0x1827e8 mov r3, r8
 *   @0x1827ec str r5, [sp]
 *   @0x1827f0 str r6, [sp, #0x4]
 *   @0x1827f4 ldr r7, [r7]
 *   @0x1827f8 str r12, [sp, #0x8]
 *   @0x1827fc str lr, [sp, #0xc]
 *   @0x182800 str r6, [sp, #0x10]
 *   @0x182804 blx r7
 *   @0x182808 mov r0, r4
 *   @0x18280c bl 0x180aec <_Z20_SetTextureNPOTFlagsP7Texture>
 *   @0x182810 mov r0, r4
 *   @0x182814 mov r1, r8
 *   @0x182818 mov r2, r5
 *   @0x18281c bl 0x1814a0 <_Z21_SetupRenderTargetFBOP7Textureii>
 *   @0x182820 mov r0, r4
 *   @0x182824 add sp, sp, #28
 *   @0x182828 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x18282c mov r0, #56
 *   @0x182830 bl 0x27c524 <_Znwj>
 *   @0x182834 ldr r1, [pc, #0x54]
 *   @0x182838 mov r2, #0
 *   @0x18283c mov r3, r0
 *   @0x182840 str r2, [r0, #0x4]
 *   @0x182844 str r2, [r3, #0x8]
 *   @0x182848 str r2, [r3, #0xc]
 *   @0x18284c str r2, [r3, #0x24]
 *   @0x182850 str r2, [r3, #0x28]
 *   @0x182854 str r2, [r3, #0x1c]
 *   @0x182858 str r2, [r3, #0x18]
 *   @0x18285c str r2, [r3, #0x14]
 *   @0x182860 str r2, [r3, #0x2c]
 *   @0x182864 str r2, [r3, #0x30]
 *   @0x182868 str r2, [r3, #0x10]
 *   @0x18286c ldr r2, [r7, r1]
 *   @0x182870 ldr r1, [r2]
 *   @0x182874 str r3, [r2]
 *   @0x182878 str r9, [r3]
 *   @0x18287c str r1, [r3, #0x34]
 *   @0x182880 add sp, sp, #28
 *   @0x182884 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x182888 mlaeq r6, r4, r5, pc
 *   @0x18288c .word 0xffffe7cc
 *   @0x182890 .word 0xffffe664
 *   @0x182894 andseq r9, r12, r0, asr r2
 *   @0x182898 .word 0xffffbb28
 *   @0x18289c .word 0xffffbb20
 *   @0x1828a0 .word 0xffffbb2c
 *
 * ══ §42/54 HandleAsyncEvents  0x1ce38c  size 520  130 条（0x1ce38c..0x1ce594）
 * @func 0x1ce38c 0x1ce594  size 520  130 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: HandleWebEvent(int)×2 / CDS_Map::~CDS_Map()×2 / operator delete(void*)×2 / YYIAPEventsDispatch() / Push_DispatchEvents() / ProcessGMLCallbacks() / DS_AutoMutex::DS_AutoMutex() / HandleAsyncEvents()+0x94
 * 字段偏移 top8: 0x4×7 / 0x10×2 / 0x1c×2 / 0x2×2 / 0x1e0×1 / 0x1d0×1 / 0x1a4×1 / 0x15c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1ce38c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1ce390 sub sp, sp, #20
 *   @0x1ce394 add r10, sp, #12
 *   @0x1ce398 bl 0x153be8 <_Z19YYIAPEventsDispatchv>
 *   @0x1ce39c ldr r6, [pc, #0x1e0]
 *   @0x1ce3a0 bl 0x155bf8 <_Z19Push_DispatchEventsv>
 *   @0x1ce3a4 bl 0x15dbe8 <_Z19ProcessGMLCallbacksv>
 *   @0x1ce3a8 mov r0, r10
 *   @0x1ce3ac bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0x1ce3b0 ldr r3, [pc, #0x1d0]
 *   @0x1ce3b4 add r6, pc, r6
 *   @0x1ce3b8 ldr r8, [r6, r3]
 *   @0x1ce3bc ldr r4, [r8]
 *   @0x1ce3c0 cmp r4, #0
 *   @0x1ce3c4 movne r11, #0
 *   @0x1ce3c8 mvnne r7, #0
 *   @0x1ce3cc movne r9, r11
 *   @0x1ce3d0 bne 0x1ce4b0 <_Z17HandleAsyncEventsv+0x124>
 *   @0x1ce3d4 b 0x1ce574 <_Z17HandleAsyncEventsv+0x1e8>
 *   @0x1ce3d8 cmp r3, #7
 *   @0x1ce3dc bne 0x1ce4a0 <_Z17HandleAsyncEventsv+0x114>
 *   @0x1ce3e0 ldr r2, [pc, #0x1a4]
 *   @0x1ce3e4 cmp r11, #0
 *   @0x1ce3e8 ldr r3, [r4, #0x10]
 *   @0x1ce3ec strne r5, [r11, #0x4]
 *   @0x1ce3f0 streq r5, [r8]
 *   @0x1ce3f4 cmp r3, #0
 *   @0x1ce3f8 ldr r11, [r6, r2]
 *   @0x1ce3fc str r7, [r11]
 *   @0x1ce400 beq 0x1ce470 <_Z17HandleAsyncEventsv+0xe4>
 *   @0x1ce404 mov r0, r4
 *   @0x1ce408 ldr r1, [r4, #0x1c]
 *   @0x1ce40c mov r2, r11
 *   @0x1ce410 blx r3
 *   @0x1ce414 cmp r0, #59
 *   @0x1ce418 ble 0x1ce420 <_Z17HandleAsyncEventsv+0x94>
 *   @0x1ce41c bl 0x1ce134 <_Z14HandleWebEventi>
 *   @0x1ce420 ldr r3, [r11]
 *   @0x1ce424 cmp r3, #0
 *   @0x1ce428 blt 0x1ce470 <_Z17HandleAsyncEventsv+0xe4>
 *   @0x1ce42c ldr r2, [pc, #0x15c]
 *   @0x1ce430 ldr r1, [r6, r2]
 *   @0x1ce434 ldr r2, [r1, #0x4]
 *   @0x1ce438 add r0, r2, r3, lsl #2
 *   @0x1ce43c ldr r5, [r2, r3, lsl #2]
 *   @0x1ce440 cmp r5, #0
 *   @0x1ce444 beq 0x1ce46c <_Z17HandleAsyncEventsv+0xe0>
 *   @0x1ce448 mov r0, r5
 *   @0x1ce44c str r1, [sp]
 *   @0x1ce450 bl 0x20d9e8 <_ZN7CDS_MapD2Ev>
 *   @0x1ce454 mov r0, r5
 *   @0x1ce458 bl 0x27d1d0 <_ZdlPv>
 *   @0x1ce45c ldr r1, [sp]
 *   @0x1ce460 ldr r0, [r11]
 *   @0x1ce464 ldr r3, [r1, #0x4]
 *   @0x1ce468 add r0, r3, r0, lsl #2
 *   @0x1ce46c str r9, [r0]
 *   @0x1ce470 ldr r3, [r4, #0x14]
 *   @0x1ce474 str r7, [r11]
 *   @0x1ce478 cmp r3, #0
 *   @0x1ce47c beq 0x1ce488 <_Z17HandleAsyncEventsv+0xfc>
 *   @0x1ce480 mov r0, r4
 *   @0x1ce484 blx r3
 *   @0x1ce488 ldr r3, [r4]
 *   @0x1ce48c mov r0, r4
 *   @0x1ce490 mov r4, #0
 *   @0x1ce494 ldr r3, [r3, #0x4]
 *   @0x1ce498 blx r3
 *   @0x1ce49c ldr r5, [r8]
 *   @0x1ce4a0 cmp r5, #0
 *   @0x1ce4a4 beq 0x1ce574 <_Z17HandleAsyncEventsv+0x1e8>
 *   @0x1ce4a8 mov r11, r4
 *   @0x1ce4ac mov r4, r5
 *   @0x1ce4b0 ldrb r3, [r4, #0x8]
 *   @0x1ce4b4 ldr r5, [r4, #0x4]
 *   @0x1ce4b8 cmp r3, #0
 *   @0x1ce4bc beq 0x1ce4a0 <_Z17HandleAsyncEventsv+0x114>
 *   @0x1ce4c0 ldr r3, [r4, #0x18]
 *   @0x1ce4c4 cmp r3, #0
 *   @0x1ce4c8 beq 0x1ce4d4 <_Z17HandleAsyncEventsv+0x148>
 *   @0x1ce4cc mov r0, r4
 *   @0x1ce4d0 blx r3
 *   @0x1ce4d4 ldr r3, [r4, #0xc]
 *   @0x1ce4d8 cmp r3, #3
 *   @0x1ce4dc bne 0x1ce3d8 <_Z17HandleAsyncEventsv+0x4c>
 *   @0x1ce4e0 ldr r2, [pc, #0xa4]
 *   @0x1ce4e4 ldr r3, [r4, #0x10]
 *   @0x1ce4e8 ldr r11, [r6, r2]
 *   @0x1ce4ec cmp r3, #0
 *   @0x1ce4f0 str r7, [r11]
 *   @0x1ce4f4 beq 0x1ce568 <_Z17HandleAsyncEventsv+0x1dc>
 *   @0x1ce4f8 mov r0, r4
 *   @0x1ce4fc ldr r1, [r4, #0x1c]
 *   @0x1ce500 mov r2, r11
 *   @0x1ce504 bl 0x1ce2bc <_Z19HttpCreateUpdateMapP16HTTP_REQ_CONTEXTPvPi>
 *   @0x1ce508 cmp r0, #59
 *   @0x1ce50c ble 0x1ce514 <_Z17HandleAsyncEventsv+0x188>
 *   @0x1ce510 bl 0x1ce134 <_Z14HandleWebEventi>
 *   @0x1ce514 ldr r3, [r11]
 *   @0x1ce518 cmp r3, #0
 *   @0x1ce51c blt 0x1ce568 <_Z17HandleAsyncEventsv+0x1dc>
 *   @0x1ce520 ldr r2, [pc, #0x68]
 *   @0x1ce524 ldr r1, [r6, r2]
 *   @0x1ce528 ldr r2, [r1, #0x4]
 *   @0x1ce52c add r0, r2, r3, lsl #2
 *   @0x1ce530 ldr r3, [r2, r3, lsl #2]
 *   @0x1ce534 cmp r3, #0
 *   @0x1ce538 beq 0x1ce564 <_Z17HandleAsyncEventsv+0x1d8>
 *   @0x1ce53c mov r0, r3
 *   @0x1ce540 stm sp, {r1, r3}
 *   @0x1ce544 bl 0x20d9e8 <_ZN7CDS_MapD2Ev>
 *   @0x1ce548 ldr r3, [sp, #0x4]
 *   @0x1ce54c mov r0, r3
 *   @0x1ce550 bl 0x27d1d0 <_ZdlPv>
 *   @0x1ce554 ldr r1, [sp]
 *   @0x1ce558 ldr r0, [r11]
 *   @0x1ce55c ldr r3, [r1, #0x4]
 *   @0x1ce560 add r0, r3, r0, lsl #2
 *   @0x1ce564 str r9, [r0]
 *   @0x1ce568 cmp r5, #0
 *   @0x1ce56c str r7, [r11]
 *   @0x1ce570 bne 0x1ce4a8 <_Z17HandleAsyncEventsv+0x11c>
 *   @0x1ce574 mov r0, r10
 *   @0x1ce578 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x1ce57c add sp, sp, #20
 *   @0x1ce580 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1ce584 mlaeq r2, r12, r8, r3
 *   @0x1ce588 .word 0xffffc1a8
 *   @0x1ce58c .word 0xffffdec8
 *   @0x1ce590 .word 0xffffbcec
 *
 * ══ §43/54 ExecuteDebugScript  0x29a83c  size 520  130 条（0x29a83c..0x29aa44）
 * @func 0x29a83c 0x29aa44  size 520  130 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x29a84c→0x757e74, 0x29a86c→0x47b238, 0x29a888→0x3f506c, 0x29a890→0x47f298, 0x29a8dc→0x47f3c4, 0x29a9b8→0x544b50
 * 调用序列: VM::ExecDebug(VMExec&, RValue*, bool)×2 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / YYCreateString(RValue*, char const*) / YYAllocLocalStackNew(int) / operator new(unsigned int) / CInstance::CInstance(float, float, int, int, bool)
 * 字段偏移 top8: 0x10×4 / 0x4×3 / 0xc×3 / 0x14×3 / 0x58×2 / 0x28×2 / 0x1d0×1 / 0x1cc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29a83c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x29a840 mov r9, r1
 *   @0x29a844 ldr r5, [pc, #0x1d0]
 *   @0x29a848 sub sp, sp, #124
 *   @0x29a84c ldr r3, [pc, #0x1cc]
 *   @0x29a850 mov r6, r2
 *   @0x29a854 add r5, pc, r5
 *   @0x29a858 ldr r7, [r5, r3]
 *   @0x29a85c ldr r4, [r7]
 *   @0x29a860 cmp r4, #0
 *   @0x29a864 movne lr, r4
 *   @0x29a868 beq 0x29a9ec <_Z18ExecuteDebugScriptPcP8VMBufferP6RValue+0x1b0>
 *   @0x29a86c ldr r12, [pc, #0x1b0]
 *   @0x29a870 mov r3, #0
 *   @0x29a874 mvn r2, #-16777216
 *   @0x29a878 str r3, [r6]
 *   @0x29a87c str r3, [r6, #0x4]
 *   @0x29a880 mov r1, #1
 *   @0x29a884 str r2, [r6, #0xc]
 *   @0x29a888 ldr r0, [pc, #0x198]
 *   @0x29a88c ldr r12, [r5, r12]
 *   @0x29a890 ldr r2, [pc, #0x194]
 *   @0x29a894 str r12, [sp, #0x10]
 *   @0x29a898 ldr r0, [r5, r0]
 *   @0x29a89c ldrb r11, [r12]
 *   @0x29a8a0 strb r1, [r12]
 *   @0x29a8a4 mov r12, #16384
 *   @0x29a8a8 str r0, [sp, #0xc]
 *   @0x29a8ac ldrb r10, [r0]
 *   @0x29a8b0 strb r3, [r0]
 *   @0x29a8b4 mov r0, r12
 *   @0x29a8b8 ldr r7, [r5, r2]
 *   @0x29a8bc mov r2, #202
 *   @0x29a8c0 ldr r1, [pc, #0x168]
 *   @0x29a8c4 ldr r3, [r7]
 *   @0x29a8c8 add r1, pc, r1
 *   @0x29a8cc cmp r3, #0
 *   @0x29a8d0 ldrne lr, [r3, #0x14]
 *   @0x29a8d4 moveq r4, lr
 *   @0x29a8d8 ldrne r4, [r3, #0x18]
 *   @0x29a8dc ldr r3, [pc, #0x150]
 *   @0x29a8e0 ldr r3, [r5, r3]
 *   @0x29a8e4 str r12, [sp, #0x58]
 *   @0x29a8e8 str lr, [sp, #0x2c]
 *   @0x29a8ec str r3, [sp, #0x14]
 *   @0x29a8f0 mov r3, #1
 *   @0x29a8f4 ldr r12, [sp, #0x14]
 *   @0x29a8f8 str r4, [sp, #0x30]
 *   @0x29a8fc mov r4, #0
 *   @0x29a900 strb r4, [r12]
 *   @0x29a904 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x29a908 ldr r8, [r7]
 *   @0x29a90c ldr r12, [sp, #0x58]
 *   @0x29a910 ldr r1, [r9, #0x10]
 *   @0x29a914 cmp r8, r4
 *   @0x29a918 ldr lr, [r9, #0x4]
 *   @0x29a91c sub r12, r12, #16
 *   @0x29a920 ldr r2, [pc, #0x110]
 *   @0x29a924 str r4, [sp, #0x50]
 *   @0x29a928 add r2, pc, r2
 *   @0x29a92c str r4, [sp, #0x54]
 *   @0x29a930 str r4, [sp, #0x5c]
 *   @0x29a934 str r4, [sp, #0x64]
 *   @0x29a938 str r4, [sp, #0x74]
 *   @0x29a93c str r9, [sp, #0x44]
 *   @0x29a940 str r1, [sp, #0x3c]
 *   @0x29a944 str lr, [sp, #0x68]
 *   @0x29a948 str r2, [sp, #0x4c]
 *   @0x29a94c str r0, [sp, #0x20]
 *   @0x29a950 add r0, r0, r12
 *   @0x29a954 str r0, [sp, #0x40]
 *   @0x29a958 beq 0x29a9b8 <_Z18ExecuteDebugScriptPcP8VMBufferP6RValue+0x17c>
 *   @0x29a95c add r12, sp, #24
 *   @0x29a960 ldr lr, [r8, #0x10]
 *   @0x29a964 mov r2, r4
 *   @0x29a968 mov r1, r6
 *   @0x29a96c mov r0, r12
 *   @0x29a970 str r12, [r7]
 *   @0x29a974 str lr, [sp, #0x28]
 *   @0x29a978 bl 0xe47c8 <_ZN2VM9ExecDebugER6VMExecP6RValueb>
 *   @0x29a97c ldr r12, [sp, #0x14]
 *   @0x29a980 str r8, [r7]
 *   @0x29a984 ldrb r2, [r12]
 *   @0x29a988 cmp r2, #0
 *   @0x29a98c beq 0x29a9a0 <_Z18ExecuteDebugScriptPcP8VMBufferP6RValue+0x164>
 *   @0x29a990 ldr r1, [pc, #0xa4]
 *   @0x29a994 mov r0, r6
 *   @0x29a998 add r1, pc, r1
 *   @0x29a99c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x29a9a0 ldr r12, [sp, #0x10]
 *   @0x29a9a4 strb r11, [r12]
 *   @0x29a9a8 ldr r12, [sp, #0xc]
 *   @0x29a9ac strb r10, [r12]
 *   @0x29a9b0 add sp, sp, #124
 *   @0x29a9b4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x29a9b8 ldr r2, [pc, #0x80]
 *   @0x29a9bc ldr r2, [r5, r2]
 *   @0x29a9c0 ldr r0, [r2]
 *   @0x29a9c4 bl 0xd41e4 <_Z20YYAllocLocalStackNewi>
 *   @0x29a9c8 add r12, sp, #24
 *   @0x29a9cc mov r1, r6
 *   @0x29a9d0 mov r2, #1
 *   @0x29a9d4 str r8, [sp, #0x24]
 *   @0x29a9d8 str r12, [r7]
 *   @0x29a9dc str r0, [sp, #0x28]
 *   @0x29a9e0 mov r0, r12
 *   @0x29a9e4 bl 0xe47c8 <_ZN2VM9ExecDebugER6VMExecP6RValueb>
 *   @0x29a9e8 b 0x29a97c <_Z18ExecuteDebugScriptPcP8VMBufferP6RValue+0x140>
 *   @0x29a9ec mov r0, #432
 *   @0x29a9f0 bl 0x27c524 <_Znwj>
 *   @0x29a9f4 mov r1, #0
 *   @0x29a9f8 mov r3, r4
 *   @0x29a9fc str r4, [sp]
 *   @0x29aa00 str r4, [sp, #0x4]
 *   @0x29aa04 mov r2, r1
 *   @0x29aa08 mov r8, r0
 *   @0x29aa0c bl 0x1994dc <_ZN9CInstanceC2Effiib>
 *   @0x29aa10 str r8, [r7]
 *   @0x29aa14 mov lr, r8
 *   @0x29aa18 b 0x29a86c <_Z18ExecuteDebugScriptPcP8VMBufferP6RValue+0x30>
 *   @0x29aa1c ldrsheq r7, [r5], -r12
 *   @0x29aa20 .word 0xfffffdb4
 *   @0x29aa24 .word 0xffffbfdc
 *   @0x29aa28 .word 0xffffc158
 *   @0x29aa2c .word 0xffffbf58
 *   @0x29aa30 .word 0x000bf0fc
 *   @0x29aa34 .word 0xffffbf14
 *   @0x29aa38 .word 0x000bf0dc
 *   @0x29aa3c andeq pc, r11, r4, ror r0
 *   @0x29aa40 .word 0xffffc104
 *
 * ══ §44/54 anon_153020  0x153020  size 508  127 条（0x153020..0x15321c）
 * @func 0x153020 0x15321c  size 508  127 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x153028→0x484a4c, 0x153034→0x484a50
 * 调用序列: operator new(unsigned int)×2 / anon_153020+0x5c / anon_153020+0xfc / MemoryManager::SetLength(void**, unsigned int, char const*, int) / anon_153020+0x194 / 0xb6574 / DsQueueEnqueuePtr(int, int, ...) / DsQueueCreate()
 * 字段偏移 top8: 0x4×9 / 0x1c×3 / 0x110×2 / 0x8×2 / 0xc×2 / 0x10×2 / 0x18×2 / 0x14×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x153020 push {r3, r4, r5, r6, r7, lr}
 *   @0x153024 ldr r3, [pc, #0x110]
 *   @0x153028 ldr r2, [pc, #0x110]
 *   @0x15302c add r3, pc, r3
 *   @0x153030 ldr r1, [r3, r2]
 *   @0x153034 ldr r2, [pc, #0x108]
 *   @0x153038 ldr r5, [r1]
 *   @0x15303c ldr r7, [r3, r2]
 *   @0x153040 cmp r5, #0
 *   @0x153044 ble 0x15307c <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x153048 ldr r3, [r7, #0x4]
 *   @0x15304c ldr r6, [r3]
 *   @0x153050 cmp r6, #0
 *   @0x153054 movne r4, #0
 *   @0x153058 bne 0x15306c <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x15305c b 0x1530d4 <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x153060 ldr r2, [r3, #0x4]!
 *   @0x153064 cmp r2, #0
 *   @0x153068 beq 0x1530d8 <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x15306c add r4, r4, #1
 *   @0x153070 cmp r4, r5
 *   @0x153074 lsl r6, r4, #2
 *   @0x153078 bne 0x153060 <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x15307c ldr r3, [r7]
 *   @0x153080 add r4, r5, #1
 *   @0x153084 str r4, [r1]
 *   @0x153088 cmp r3, r5
 *   @0x15308c ble 0x15311c <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x153090 mov r0, #32
 *   @0x153094 bl 0x27c524 <_Znwj>
 *   @0x153098 ldr r1, [r7, #0x4]
 *   @0x15309c mov r2, #0
 *   @0x1530a0 mvn r12, #1
 *   @0x1530a4 mov r3, r0
 *   @0x1530a8 mov r0, r5
 *   @0x1530ac str r12, [r3, #0x1c]
 *   @0x1530b0 str r2, [r3]
 *   @0x1530b4 str r2, [r3, #0x4]
 *   @0x1530b8 str r2, [r3, #0x8]
 *   @0x1530bc str r2, [r3, #0xc]
 *   @0x1530c0 str r2, [r3, #0x10]
 *   @0x1530c4 str r2, [r3, #0x18]
 *   @0x1530c8 str r2, [r3, #0x14]
 *   @0x1530cc str r3, [r1, r5, lsl #2]
 *   @0x1530d0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1530d4 mov r4, r6
 *   @0x1530d8 mov r0, #32
 *   @0x1530dc bl 0x27c524 <_Znwj>
 *   @0x1530e0 ldr r1, [r7, #0x4]
 *   @0x1530e4 mov r2, #0
 *   @0x1530e8 mvn r12, #1
 *   @0x1530ec mov r3, r0
 *   @0x1530f0 mov r0, r4
 *   @0x1530f4 str r12, [r3, #0x1c]
 *   @0x1530f8 str r2, [r3]
 *   @0x1530fc str r2, [r3, #0x4]
 *   @0x153100 str r2, [r3, #0x8]
 *   @0x153104 str r2, [r3, #0xc]
 *   @0x153108 str r2, [r3, #0x10]
 *   @0x15310c str r2, [r3, #0x18]
 *   @0x153110 str r2, [r3, #0x14]
 *   @0x153114 str r3, [r1, r6]
 *   @0x153118 pop {r3, r4, r5, r6, r7, pc}
 *   @0x15311c ldr r2, [pc, #0x24]
 *   @0x153120 add r0, r7, #4
 *   @0x153124 lsl r1, r4, #2
 *   @0x153128 mov r3, #190
 *   @0x15312c add r2, pc, r2
 *   @0x153130 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x153134 str r4, [r7]
 *   @0x153138 b 0x153090 <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x15313c eoreq lr, r9, r4, lsr #24
 *   @0x153140 .word 0xffffde78
 *   @0x153144 .word 0xffffde7c
 *   @0x153148 andseq r2, pc, r0, lsl #29
 *   @0x15314c ldr r3, [pc, #0x70]
 *   @0x153150 push {r4, r5, r6, r7, r8, lr}
 *   @0x153154 ldr r3, [pc, r3]
 *   @0x153158 mov r8, r0
 *   @0x15315c ldr r7, [r3]
 *   @0x153160 cmp r7, #0
 *   @0x153164 ble 0x1531b4 <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x1c0>
 *   @0x153168 ldr r3, [pc, #0x58]
 *   @0x15316c mov r5, #0
 *   @0x153170 ldr r3, [pc, r3]
 *   @0x153174 ldr r6, [r3, #0x4]
 *   @0x153178 sub r6, r6, #4
 *   @0x15317c ldr r4, [r6, #0x4]!
 *   @0x153180 mov r1, r8
 *   @0x153184 cmp r4, #0
 *   @0x153188 beq 0x1531a8 <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x1b4>
 *   @0x15318c ldr r0, [r4, #0x4]
 *   @0x153190 bl 0xb6574 <strcmp@plt>
 *   @0x153194 cmp r0, #0
 *   @0x153198 bne 0x1531a8 <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x1b4>
 *   @0x15319c ldr r3, [r4, #0x1c]
 *   @0x1531a0 cmp r3, #0
 *   @0x1531a4 beq 0x1531bc <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x1c8>
 *   @0x1531a8 add r5, r5, #1
 *   @0x1531ac cmp r5, r7
 *   @0x1531b0 bne 0x15317c <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x188>
 *   @0x1531b4 mvn r0, #0
 *   @0x1531b8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1531bc mov r0, r5
 *   @0x1531c0 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1531c4 eoreq r12, r9, r4, ror r9
 *   @0x1531c8 eoreq r12, r9, r12, asr r9
 *   @0x1531cc push {r4, r5, lr}
 *   @0x1531d0 mov r5, r0
 *   @0x1531d4 ldr r4, [pc, #0x40]
 *   @0x1531d8 sub sp, sp, #12
 *   @0x1531dc add r4, pc, r4
 *   @0x1531e0 ldr r3, [r4]
 *   @0x1531e4 cmn r3, #1
 *   @0x1531e8 movne r0, r3
 *   @0x1531ec beq 0x15320c <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x218>
 *   @0x1531f0 str r5, [sp]
 *   @0x1531f4 mov r1, #1
 *   @0x1531f8 mov r2, #0
 *   @0x1531fc mov r3, #0
 *   @0x153200 bl 0x2054a4 <_Z17DsQueueEnqueuePtriiz>
 *   @0x153204 add sp, sp, #12
 *   @0x153208 pop {r4, r5, pc}
 *   @0x15320c bl 0x2053bc <_Z13DsQueueCreatev>
 *   @0x153210 mov r3, r0
 *   @0x153214 str r3, [r4]
 *   @0x153218 b 0x1531f0 <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x1fc>
 *
 * ══ §45/54 HandleAlarm  0x1cdd70  size 508  127 条（0x1cdd70..0x1cdf6c）
 * @func 0x1cdd70 0x1cdf6c  size 508  127 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1cdd74→0x757e7c, 0x1cdd9c→0x536f20, 0x1cdda8→0x536f70, 0x1cdddc→0x53ab70, 0x1cdde0→0x542374, 0x1cdf20→0x757e80, 0x1cdf38→0x757e80
 * 调用序列: CInstance::GetTimer(int)×3 / HandleAlarm()+0x18c / HandleAlarm()+0xd8 / HandleAlarm()+0x14c / CInstance::SetTimer(int, int) / Perform_Event(CInstance*, CInstance*, int, int) / CProfiler::Push(int, int)
 * 字段偏移 top8: 0x8×7 / 0x4×5 / 0xc×3 / 0x1d8×2 / 0x17c×2 / 0x1b4×1 / 0x1ac×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1cdd70 ldr r12, [pc, #0x1d8]
 *   @0x1cdd74 ldr r3, [pc, #0x1d8]
 *   @0x1cdd78 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1cdd7c add r12, pc, r12
 *   @0x1cdd80 sub sp, sp, #20
 *   @0x1cdd84 str r12, [sp, #0x8]
 *   @0x1cdd88 ldr r3, [r12, r3]
 *   @0x1cdd8c str r3, [sp, #0xc]
 *   @0x1cdd90 ldrb r3, [r3]
 *   @0x1cdd94 cmp r3, #0
 *   @0x1cdd98 bne 0x1cdf38 <_Z11HandleAlarmv+0x1c8>
 *   @0x1cdd9c ldr r3, [pc, #0x1b4]
 *   @0x1cdda0 mov r6, #0
 *   @0x1cdda4 ldr r12, [sp, #0x8]
 *   @0x1cdda8 ldr r0, [pc, #0x1ac]
 *   @0x1cddac ldr r1, [r12, r3]
 *   @0x1cddb0 ldrd r4, r5, [r1]
 *   @0x1cddb4 adds r2, r4, #1
 *   @0x1cddb8 adc r3, r5, #0
 *   @0x1cddbc strd r2, r3, [r1]
 *   @0x1cddc0 ldr r9, [r12, r0]
 *   @0x1cddc4 add r9, r9, #2048
 *   @0x1cddc8 ldr r3, [r9], #4
 *   @0x1cddcc cmp r3, #0
 *   @0x1cddd0 ble 0x1cdefc <_Z11HandleAlarmv+0x18c>
 *   @0x1cddd4 ldr r12, [sp, #0x8]
 *   @0x1cddd8 mov r7, #0
 *   @0x1cdddc ldr r2, [pc, #0x17c]
 *   @0x1cdde0 ldr r3, [pc, #0x17c]
 *   @0x1cdde4 ldr r8, [r12, r2]
 *   @0x1cdde8 ldr r3, [r12, r3]
 *   @0x1cddec add r8, r8, r6, lsl #3
 *   @0x1cddf0 add r8, r8, #4096
 *   @0x1cddf4 add r8, r8, #4
 *   @0x1cddf8 str r3, [sp, #0x4]
 *   @0x1cddfc ldr r12, [sp, #0x4]
 *   @0x1cde00 ldr r1, [r8]
 *   @0x1cde04 ldr r3, [r12]
 *   @0x1cde08 ldr r1, [r1, r7, lsl #2]
 *   @0x1cde0c ldr r2, [r3, #0x4]
 *   @0x1cde10 ldr r3, [r3]
 *   @0x1cde14 and r2, r1, r2
 *   @0x1cde18 ldr r3, [r3, r2, lsl #3]
 *   @0x1cde1c cmp r3, #0
 *   @0x1cde20 bne 0x1cde34 <_Z11HandleAlarmv+0xc4>
 *   @0x1cde24 b 0x1cde44 <_Z11HandleAlarmv+0xd4>
 *   @0x1cde28 ldr r3, [r3, #0x4]
 *   @0x1cde2c cmp r3, #0
 *   @0x1cde30 beq 0x1cde44 <_Z11HandleAlarmv+0xd4>
 *   @0x1cde34 ldr r2, [r3, #0x8]
 *   @0x1cde38 cmp r1, r2
 *   @0x1cde3c bne 0x1cde28 <_Z11HandleAlarmv+0xb8>
 *   @0x1cde40 ldr r3, [r3, #0xc]
 *   @0x1cde44 ldr r10, [r3, #0xc4]
 *   @0x1cde48 cmp r10, #0
 *   @0x1cde4c beq 0x1cdeec <_Z11HandleAlarmv+0x17c>
 *   @0x1cde50 ldr r3, [r10, #0x8]
 *   @0x1cde54 cmp r3, #0
 *   @0x1cde58 beq 0x1cdeec <_Z11HandleAlarmv+0x17c>
 *   @0x1cde5c ldr r11, [r10, #0x8]
 *   @0x1cde60 ldr r10, [r10]
 *   @0x1cde64 ldrb r3, [r11, #0x68]
 *   @0x1cde68 cmp r3, #0
 *   @0x1cde6c bne 0x1cde48 <_Z11HandleAlarmv+0xd8>
 *   @0x1cde70 ldrb r3, [r11, #0x69]
 *   @0x1cde74 cmp r3, #0
 *   @0x1cde78 bne 0x1cde48 <_Z11HandleAlarmv+0xd8>
 *   @0x1cde7c ldrd r2, r3, [r11, #112]
 *   @0x1cde80 cmp r4, r2
 *   @0x1cde84 sbcs r1, r5, r3
 *   @0x1cde88 blt 0x1cde48 <_Z11HandleAlarmv+0xd8>
 *   @0x1cde8c mov r0, r11
 *   @0x1cde90 mov r1, r6
 *   @0x1cde94 bl 0x193134 <_ZN9CInstance8GetTimerEi>
 *   @0x1cde98 cmp r0, #0
 *   @0x1cde9c blt 0x1cdebc <_Z11HandleAlarmv+0x14c>
 *   @0x1cdea0 mov r1, r6
 *   @0x1cdea4 mov r0, r11
 *   @0x1cdea8 bl 0x193134 <_ZN9CInstance8GetTimerEi>
 *   @0x1cdeac mov r1, r6
 *   @0x1cdeb0 sub r2, r0, #1
 *   @0x1cdeb4 mov r0, r11
 *   @0x1cdeb8 bl 0x193148 <_ZN9CInstance8SetTimerEii>
 *   @0x1cdebc mov r0, r11
 *   @0x1cdec0 mov r1, r6
 *   @0x1cdec4 bl 0x193134 <_ZN9CInstance8GetTimerEi>
 *   @0x1cdec8 cmp r0, #0
 *   @0x1cdecc bne 0x1cde48 <_Z11HandleAlarmv+0xd8>
 *   @0x1cded0 mov r0, r11
 *   @0x1cded4 mov r2, #2
 *   @0x1cded8 mov r1, r11
 *   @0x1cdedc mov r3, r6
 *   @0x1cdee0 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0x1cdee4 cmp r10, #0
 *   @0x1cdee8 bne 0x1cde50 <_Z11HandleAlarmv+0xe0>
 *   @0x1cdeec ldr r3, [r9, #-0x4]
 *   @0x1cdef0 add r7, r7, #1
 *   @0x1cdef4 cmp r3, r7
 *   @0x1cdef8 bgt 0x1cddfc <_Z11HandleAlarmv+0x8c>
 *   @0x1cdefc add r6, r6, #1
 *   @0x1cdf00 cmp r6, #12
 *   @0x1cdf04 bne 0x1cddc8 <_Z11HandleAlarmv+0x58>
 *   @0x1cdf08 ldr r12, [sp, #0xc]
 *   @0x1cdf0c ldrb r3, [r12]
 *   @0x1cdf10 cmp r3, #0
 *   @0x1cdf14 bne 0x1cdf20 <_Z11HandleAlarmv+0x1b0>
 *   @0x1cdf18 add sp, sp, #20
 *   @0x1cdf1c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1cdf20 ldr r3, [pc, #0x40]
 *   @0x1cdf24 ldr r12, [sp, #0x8]
 *   @0x1cdf28 ldr r0, [r12, r3]
 *   @0x1cdf2c add sp, sp, #20
 *   @0x1cdf30 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1cdf34 b 0x2a08ac <_ZN9CProfiler3PopEv>
 *   @0x1cdf38 ldr r3, [pc, #0x28]
 *   @0x1cdf3c mov r1, #6
 *   @0x1cdf40 mov r2, #8
 *   @0x1cdf44 ldr r0, [r12, r3]
 *   @0x1cdf48 bl 0x2a0738 <_ZN9CProfiler4PushEii>
 *   @0x1cdf4c b 0x1cdd9c <_Z11HandleAlarmv+0x2c>
 *   @0x1cdf50 .word 0x00223ed4
 *   @0x1cdf54 .word 0xffffbf18
 *   @0x1cdf58 .word 0xffffdeb4
 *   @0x1cdf5c .word 0xffffdeb8
 *   @0x1cdf60 .word 0xffffdebc
 *   @0x1cdf64 .word 0xffffbfec
 *   @0x1cdf68 .word 0xffffbf1c
 *
 * ══ §46/54 b2Body::ResetMassData  0x2c6c00  size 508  127 条（0x2c6c00..0x2c6dfc）
 * @func 0x2c6c00 0x2c6dfc  size 508  127 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Body::ResetMassData()+0x1c8 / b2Body::ResetMassData()+0x1b8 / b2Body::ResetMassData()+0x108
 * 字段偏移 top8: 0x4×3 / 0x84×2 / 0x88×2 / 0x8c×2 / 0x90×2 / 0x2c×1 / 0x30×1 / 0x74×1
 * VFP 指令 65 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c6c00 ldr r2, [r0]
 *   @0x2c6c04 mov r3, #0
 *   @0x2c6c08 push {r4, r5, r6, lr}
 *   @0x2c6c0c vpush {d8}
 *   @0x2c6c10 cmp r2, #1
 *   @0x2c6c14 sub sp, sp, #16
 *   @0x2c6c18 mov r4, r0
 *   @0x2c6c1c str r3, [r0, #0x84]
 *   @0x2c6c20 str r3, [r0, #0x88]
 *   @0x2c6c24 str r3, [r0, #0x8c]
 *   @0x2c6c28 str r3, [r0, #0x90]
 *   @0x2c6c2c str r3, [r0, #0x2c]
 *   @0x2c6c30 str r3, [r0, #0x30]
 *   @0x2c6c34 bls 0x2c6dc8 <_ZN6b2Body13ResetMassDataEv+0x1c8>
 *   @0x2c6c38 ldr r5, [r0, #0x74]
 *   @0x2c6c3c ldr r3, [pc, #0x1b4]
 *   @0x2c6c40 cmp r5, #0
 *   @0x2c6c44 ldr r3, [pc, r3]
 *   @0x2c6c48 vldr s16, [r3]
 *   @0x2c6c4c vldr s17, [r3, #4]
 *   @0x2c6c50 bne 0x2c6c64 <_ZN6b2Body13ResetMassDataEv+0x64>
 *   @0x2c6c54 b 0x2c6db8 <_ZN6b2Body13ResetMassDataEv+0x1b8>
 *   @0x2c6c58 ldr r5, [r5, #0x4]
 *   @0x2c6c5c cmp r5, #0
 *   @0x2c6c60 beq 0x2c6cc8 <_ZN6b2Body13ResetMassDataEv+0xc8>
 *   @0x2c6c64 vldr s15, [r5]
 *   @0x2c6c68 vcmp.f32 s15, #0
 *   @0x2c6c6c vmrs APSR_nzcv, fpscr
 *   @0x2c6c70 beq 0x2c6c58 <_ZN6b2Body13ResetMassDataEv+0x58>
 *   @0x2c6c74 ldr r0, [r5, #0xc]
 *   @0x2c6c78 mov r1, sp
 *   @0x2c6c7c vmov r2, s15
 *   @0x2c6c80 ldr r3, [r0]
 *   @0x2c6c84 ldr r3, [r3, #0x20]
 *   @0x2c6c88 blx r3
 *   @0x2c6c8c vldr s15, [sp]
 *   @0x2c6c90 vldr s11, [r4, #132]
 *   @0x2c6c94 vldr s13, [r4, #140]
 *   @0x2c6c98 vadd.f32 s11, s11, s15
 *   @0x2c6c9c vldr s10, [sp, #4]
 *   @0x2c6ca0 vldr s12, [sp, #8]
 *   @0x2c6ca4 vldr s14, [sp, #12]
 *   @0x2c6ca8 ldr r5, [r5, #0x4]
 *   @0x2c6cac cmp r5, #0
 *   @0x2c6cb0 vmla.f32 s16, s15, s10
 *   @0x2c6cb4 vstr s11, [r4, #132]
 *   @0x2c6cb8 vmla.f32 s17, s15, s12
 *   @0x2c6cbc vadd.f32 s15, s13, s14
 *   @0x2c6cc0 vstr s15, [r4, #140]
 *   @0x2c6cc4 bne 0x2c6c64 <_ZN6b2Body13ResetMassDataEv+0x64>
 *   @0x2c6cc8 vldr s15, [r4, #132]
 *   @0x2c6ccc vcmpe.f32 s15, #0
 *   @0x2c6cd0 vmrs APSR_nzcv, fpscr
 *   @0x2c6cd4 ble 0x2c6db8 <_ZN6b2Body13ResetMassDataEv+0x1b8>
 *   @0x2c6cd8 vmov.f32 s14, #1.000000e+00
 *   @0x2c6cdc vdiv.f32 s15, s14, s15
 *   @0x2c6ce0 vmul.f32 s16, s16, s15
 *   @0x2c6ce4 vstr s15, [r4, #136]
 *   @0x2c6ce8 vmul.f32 s17, s17, s15
 *   @0x2c6cec vldr s15, [r4, #140]
 *   @0x2c6cf0 vcmpe.f32 s15, #0
 *   @0x2c6cf4 vmrs APSR_nzcv, fpscr
 *   @0x2c6cf8 ble 0x2c6d08 <_ZN6b2Body13ResetMassDataEv+0x108>
 *   @0x2c6cfc ldrh r3, [r4, #4]
 *   @0x2c6d00 tst r3, #16
 *   @0x2c6d04 beq 0x2c6d94 <_ZN6b2Body13ResetMassDataEv+0x194>
 *   @0x2c6d08 mov r3, #0
 *   @0x2c6d0c str r3, [r4, #0x8c]
 *   @0x2c6d10 str r3, [r4, #0x90]
 *   @0x2c6d14 vldr s14, [r4, #24]
 *   @0x2c6d18 vldr s11, [r4, #20]
 *   @0x2c6d1c vstr s17, [r4, #48]
 *   @0x2c6d20 vmul.f32 s15, s14, s17
 *   @0x2c6d24 vldr s8, [r4, #12]
 *   @0x2c6d28 vldr s12, [r4, #16]
 *   @0x2c6d2c vldr s9, [r4, #60]
 *   @0x2c6d30 vldr s10, [r4, #64]
 *   @0x2c6d34 add r2, r4, #60
 *   @0x2c6d38 vstr s16, [r4, #44]
 *   @0x2c6d3c add r3, r4, #52
 *   @0x2c6d40 vldr s13, [r4, #88]
 *   @0x2c6d44 vmul.f32 s17, s11, s17
 *   @0x2c6d48 vmla.f32 s15, s11, s16
 *   @0x2c6d4c vnmls.f32 s17, s14, s16
 *   @0x2c6d50 vadd.f32 s12, s15, s12
 *   @0x2c6d54 vadd.f32 s17, s17, s8
 *   @0x2c6d58 vstr s12, [r4, #64]
 *   @0x2c6d5c vsub.f32 s11, s17, s9
 *   @0x2c6d60 vstr s17, [r4, #60]
 *   @0x2c6d64 ldm r2, {r0, r1}
 *   @0x2c6d68 stm r3, {r0, r1}
 *   @0x2c6d6c vldr s14, [r4, #84]
 *   @0x2c6d70 vldr s15, [r4, #80]
 *   @0x2c6d74 vsub.f32 s12, s12, s10
 *   @0x2c6d78 vmla.f32 s14, s13, s11
 *   @0x2c6d7c vmls.f32 s15, s13, s12
 *   @0x2c6d80 vstr s14, [r4, #84]
 *   @0x2c6d84 vstr s15, [r4, #80]
 *   @0x2c6d88 add sp, sp, #16
 *   @0x2c6d8c vpop {d8}
 *   @0x2c6d90 pop {r4, r5, r6, pc}
 *   @0x2c6d94 vmul.f32 s14, s17, s17
 *   @0x2c6d98 vldr s13, [r4, #132]
 *   @0x2c6d9c vmla.f32 s14, s16, s16
 *   @0x2c6da0 vmls.f32 s15, s14, s13
 *   @0x2c6da4 vmov.f32 s14, #1.000000e+00
 *   @0x2c6da8 vstr s15, [r4, #140]
 *   @0x2c6dac vdiv.f32 s15, s14, s15
 *   @0x2c6db0 vstr s15, [r4, #144]
 *   @0x2c6db4 b 0x2c6d14 <_ZN6b2Body13ResetMassDataEv+0x114>
 *   @0x2c6db8 mov r3, #1065353216
 *   @0x2c6dbc str r3, [r4, #0x84]
 *   @0x2c6dc0 str r3, [r4, #0x88]
 *   @0x2c6dc4 b 0x2c6cec <_ZN6b2Body13ResetMassDataEv+0xec>
 *   @0x2c6dc8 add r3, r0, #12
 *   @0x2c6dcc ldr r5, [r0, #0x48]
 *   @0x2c6dd0 add r12, r0, #52
 *   @0x2c6dd4 add r2, r0, #60
 *   @0x2c6dd8 ldm r3, {r0, r1}
 *   @0x2c6ddc stm r12, {r0, r1}
 *   @0x2c6de0 ldm r3, {r0, r1}
 *   @0x2c6de4 stm r2, {r0, r1}
 *   @0x2c6de8 str r5, [r4, #0x44]
 *   @0x2c6dec add sp, sp, #16
 *   @0x2c6df0 vpop {d8}
 *   @0x2c6df4 pop {r4, r5, r6, pc}
 *   @0x2c6df8 mulseq r2, r4, r8
 *
 * ══ §47/54 Graphics::FreeTexture  0x180f98  size 504  126 条（0x180f98..0x181190）
 * @func 0x180f98 0x181190  size 504  126 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x180fa4→0x4a2fb4, 0x180fcc→0x479bb8, 0x180ff8→0x3f26dc, 0x18100c→0x479bfc, 0x181038→0x3f26dc, 0x18104c→0x479b68, 0x181078→0x3f26dc, 0x18108c→0x479b68
 * 调用序列: MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x1c4×2 / 0x14×2 / 0x18×2 / 0x1c×2 / 0x20×2 / 0x24×2 / 0x34×2 / 0x1a0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x180f98 push {r3, r4, r5, lr}
 *   @0x180f9c mov r4, r0
 *   @0x180fa0 ldr r5, [pc, #0x1c4]
 *   @0x180fa4 ldr r3, [pc, #0x1c4]
 *   @0x180fa8 add r5, pc, r5
 *   @0x180fac ldr r3, [r5, r3]
 *   @0x180fb0 ldr r2, [r3]
 *   @0x180fb4 cmp r0, r2
 *   @0x180fb8 moveq r2, #0
 *   @0x180fbc streq r2, [r3]
 *   @0x180fc0 ldr r3, [r0, #0x14]
 *   @0x180fc4 cmn r3, #1
 *   @0x180fc8 beq 0x180fec <_ZN8Graphics11FreeTextureEPv+0x54>
 *   @0x180fcc ldr r3, [pc, #0x1a0]
 *   @0x180fd0 mov r0, #1
 *   @0x180fd4 add r1, r4, #20
 *   @0x180fd8 ldr r3, [r5, r3]
 *   @0x180fdc ldr r3, [r3]
 *   @0x180fe0 blx r3
 *   @0x180fe4 mvn r3, #0
 *   @0x180fe8 str r3, [r4, #0x14]
 *   @0x180fec ldr r3, [r4, #0x18]
 *   @0x180ff0 cmn r3, #1
 *   @0x180ff4 beq 0x18102c <_ZN8Graphics11FreeTextureEPv+0x94>
 *   @0x180ff8 ldr r3, [pc, #0x178]
 *   @0x180ffc ldr r3, [r5, r3]
 *   @0x181000 ldr r0, [r3]
 *   @0x181004 cmp r0, #1
 *   @0x181008 beq 0x181154 <_ZN8Graphics11FreeTextureEPv+0x1bc>
 *   @0x18100c ldr r3, [pc, #0x168]
 *   @0x181010 mov r0, #1
 *   @0x181014 add r1, r4, #24
 *   @0x181018 ldr r3, [r5, r3]
 *   @0x18101c ldr r3, [r3]
 *   @0x181020 blx r3
 *   @0x181024 mvn r3, #0
 *   @0x181028 str r3, [r4, #0x18]
 *   @0x18102c ldr r3, [r4, #0x1c]
 *   @0x181030 cmn r3, #1
 *   @0x181034 beq 0x18106c <_ZN8Graphics11FreeTextureEPv+0xd4>
 *   @0x181038 ldr r3, [pc, #0x138]
 *   @0x18103c ldr r3, [r5, r3]
 *   @0x181040 ldr r0, [r3]
 *   @0x181044 cmp r0, #1
 *   @0x181048 beq 0x18113c <_ZN8Graphics11FreeTextureEPv+0x1a4>
 *   @0x18104c ldr r3, [pc, #0x12c]
 *   @0x181050 mov r0, #1
 *   @0x181054 add r1, r4, #28
 *   @0x181058 ldr r3, [r5, r3]
 *   @0x18105c ldr r3, [r3]
 *   @0x181060 blx r3
 *   @0x181064 mvn r3, #0
 *   @0x181068 str r3, [r4, #0x1c]
 *   @0x18106c ldr r3, [r4, #0x20]
 *   @0x181070 cmn r3, #1
 *   @0x181074 beq 0x1810ac <_ZN8Graphics11FreeTextureEPv+0x114>
 *   @0x181078 ldr r3, [pc, #0xf8]
 *   @0x18107c ldr r3, [r5, r3]
 *   @0x181080 ldr r0, [r3]
 *   @0x181084 cmp r0, #1
 *   @0x181088 beq 0x181124 <_ZN8Graphics11FreeTextureEPv+0x18c>
 *   @0x18108c ldr r3, [pc, #0xec]
 *   @0x181090 mov r0, #1
 *   @0x181094 add r1, r4, #32
 *   @0x181098 ldr r3, [r5, r3]
 *   @0x18109c ldr r3, [r3]
 *   @0x1810a0 blx r3
 *   @0x1810a4 mvn r3, #0
 *   @0x1810a8 str r3, [r4, #0x20]
 *   @0x1810ac ldr r0, [r4, #0x24]
 *   @0x1810b0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1810b4 ldr r2, [pc, #0xc8]
 *   @0x1810b8 mov r3, #0
 *   @0x1810bc str r3, [r4, #0x2c]
 *   @0x1810c0 str r3, [r4, #0x24]
 *   @0x1810c4 ldr r0, [r5, r2]
 *   @0x1810c8 ldr r1, [r0]
 *   @0x1810cc cmp r1, #0
 *   @0x1810d0 beq 0x181100 <_ZN8Graphics11FreeTextureEPv+0x168>
 *   @0x1810d4 cmp r4, r1
 *   @0x1810d8 ldr r3, [r1, #0x34]
 *   @0x1810dc bne 0x1810f8 <_ZN8Graphics11FreeTextureEPv+0x160>
 *   @0x1810e0 b 0x18111c <_ZN8Graphics11FreeTextureEPv+0x184>
 *   @0x1810e4 cmp r4, r3
 *   @0x1810e8 ldr r2, [r3, #0x34]
 *   @0x1810ec beq 0x18110c <_ZN8Graphics11FreeTextureEPv+0x174>
 *   @0x1810f0 mov r1, r3
 *   @0x1810f4 mov r3, r2
 *   @0x1810f8 cmp r3, #0
 *   @0x1810fc bne 0x1810e4 <_ZN8Graphics11FreeTextureEPv+0x14c>
 *   @0x181100 mov r0, r4
 *   @0x181104 pop {r3, r4, r5, lr}
 *   @0x181108 b 0x27d1d0 <_ZdlPv>
 *   @0x18110c cmp r1, #0
 *   @0x181110 strne r2, [r1, #0x34]
 *   @0x181114 bne 0x181100 <_ZN8Graphics11FreeTextureEPv+0x168>
 *   @0x181118 mov r3, r2
 *   @0x18111c str r3, [r0]
 *   @0x181120 b 0x181100 <_ZN8Graphics11FreeTextureEPv+0x168>
 *   @0x181124 ldr r3, [pc, #0x5c]
 *   @0x181128 add r1, r4, #32
 *   @0x18112c ldr r3, [r5, r3]
 *   @0x181130 ldr r3, [r3]
 *   @0x181134 blx r3
 *   @0x181138 b 0x1810a4 <_ZN8Graphics11FreeTextureEPv+0x10c>
 *   @0x18113c ldr r3, [pc, #0x44]
 *   @0x181140 add r1, r4, #28
 *   @0x181144 ldr r3, [r5, r3]
 *   @0x181148 ldr r3, [r3]
 *   @0x18114c blx r3
 *   @0x181150 b 0x181064 <_ZN8Graphics11FreeTextureEPv+0xcc>
 *   @0x181154 ldr r3, [pc, #0x30]
 *   @0x181158 add r1, r4, #24
 *   @0x18115c ldr r3, [r5, r3]
 *   @0x181160 ldr r3, [r3]
 *   @0x181164 blx r3
 *   @0x181168 b 0x181024 <_ZN8Graphics11FreeTextureEPv+0x8c>
 *   @0x18116c eoreq r0, r7, r8, lsr #25
 *   @0x181170 .word 0xffffe8f8
 *   @0x181174 .word 0xffffbb24
 *   @0x181178 .word 0xffffe7b8
 *   @0x18117c .word 0xffffbc80
 *   @0x181180 .word 0xffffbcbc
 *   @0x181184 .word 0xffffe664
 *   @0x181188 .word 0xffffbc0c
 *   @0x18118c .word 0xffffbb70
 *
 * ══ §48/54 CGCGeneration::AddRoot  0x196210  size 504  126 条（0x196210..0x196408）
 * @func 0x196210 0x196408  size 504  126 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: unsigned int CHashMapCalculateHash<YYObjectBase*>(YYObjectBase*) / CGCGeneration::AddRoot(YYObjectBase*)+0x64 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65b0 / CGCGeneration::AddRoot(YYObjectBase*)+0x190 / CGCGeneration::AddRoot(YYObjectBase*)+0x1c8 / CGCGeneration::AddRoot(YYObjectBase*)+0x1bc / CHashMap<YYObjectBase*, YYObjectBase*, 4>::Insert(YYObjectBase*, YYObjectBase*)
 * 字段偏移 top8: 0x8×9 / 0x4×8 / 0x10×4 / 0xc×1 / 0xe4×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x196210 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x196214 subs r7, r1, #0
 *   @0x196218 popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x19621c ldr r8, [r0]
 *   @0x196220 ldr r3, [r8, #0x4]
 *   @0x196224 ldr r2, [r8, #0xc]
 *   @0x196228 cmp r3, r2
 *   @0x19622c bgt 0x196310 <_ZN13CGCGeneration7AddRootEP12YYObjectBase+0x100>
 *   @0x196230 add r3, r3, #1
 *   @0x196234 mov r0, r7
 *   @0x196238 str r3, [r8, #0x4]
 *   @0x19623c bl 0x190f34 <_Z21CHashMapCalculateHashIP12YYObjectBaseEjT_>
 *   @0x196240 ldr r5, [r8, #0x8]
 *   @0x196244 ldr r9, [r8, #0x10]
 *   @0x196248 bic r0, r0, #-2147483648
 *   @0x19624c and r3, r0, r5
 *   @0x196250 add r2, r3, r3, lsl #1
 *   @0x196254 add r2, r9, r2, lsl #2
 *   @0x196258 ldr r12, [r2, #0x8]
 *   @0x19625c cmp r12, #0
 *   @0x196260 beq 0x196300 <_ZN13CGCGeneration7AddRootEP12YYObjectBase+0xf0>
 *   @0x196264 ldr r10, [r8]
 *   @0x196268 mov r1, r7
 *   @0x19626c mov r6, #0
 *   @0x196270 b 0x1962b4 <_ZN13CGCGeneration7AddRootEP12YYObjectBase+0xa4>
 *   @0x196274 ldr r11, [r2]
 *   @0x196278 ldr r6, [r2, #0x4]
 *   @0x19627c str r0, [r2, #0x8]
 *   @0x196280 mov r0, r12
 *   @0x196284 str r1, [r2]
 *   @0x196288 mov r1, r11
 *   @0x19628c str r7, [r2, #0x4]
 *   @0x196290 mov r7, r6
 *   @0x196294 add r3, r3, #1
 *   @0x196298 add r6, r4, #1
 *   @0x19629c and r3, r3, r5
 *   @0x1962a0 add r2, r3, r3, lsl #1
 *   @0x1962a4 add r2, r9, r2, lsl #2
 *   @0x1962a8 ldr r12, [r2, #0x8]
 *   @0x1962ac cmp r12, #0
 *   @0x1962b0 beq 0x196304 <_ZN13CGCGeneration7AddRootEP12YYObjectBase+0xf4>
 *   @0x1962b4 add r4, r10, r3
 *   @0x1962b8 and r11, r12, r5
 *   @0x1962bc rsb r4, r11, r4
 *   @0x1962c0 and r4, r4, r5
 *   @0x1962c4 cmp r4, r6
 *   @0x1962c8 blt 0x196274 <_ZN13CGCGeneration7AddRootEP12YYObjectBase+0x64>
 *   @0x1962cc movne r4, r6
 *   @0x1962d0 bne 0x196294 <_ZN13CGCGeneration7AddRootEP12YYObjectBase+0x84>
 *   @0x1962d4 cmp r12, r0
 *   @0x1962d8 bne 0x196294 <_ZN13CGCGeneration7AddRootEP12YYObjectBase+0x84>
 *   @0x1962dc ldr r6, [r2]
 *   @0x1962e0 cmp r1, r6
 *   @0x1962e4 bne 0x196294 <_ZN13CGCGeneration7AddRootEP12YYObjectBase+0x84>
 *   @0x1962e8 ldr r3, [r8, #0x4]
 *   @0x1962ec stm r2, {r1, r7}
 *   @0x1962f0 sub r3, r3, #1
 *   @0x1962f4 str r12, [r2, #0x8]
 *   @0x1962f8 str r3, [r8, #0x4]
 *   @0x1962fc pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x196300 mov r1, r7
 *   @0x196304 stm r2, {r1, r7}
 *   @0x196308 str r0, [r2, #0x8]
 *   @0x19630c pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x196310 ldr r6, [r8]
 *   @0x196314 mov r3, #1
 *   @0x196318 ldr r1, [pc, #0xe4]
 *   @0x19631c mov r2, #70
 *   @0x196320 ldr r9, [r8, #0x10]
 *   @0x196324 lsl r0, r6, r3
 *   @0x196328 add r1, pc, r1
 *   @0x19632c add r4, r0, r6, lsl #2
 *   @0x196330 str r0, [r8]
 *   @0x196334 sub r0, r0, #1
 *   @0x196338 str r0, [r8, #0x8]
 *   @0x19633c lsl r4, r4, #2
 *   @0x196340 mov r0, r4
 *   @0x196344 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x196348 mov r2, r4
 *   @0x19634c mov r1, #0
 *   @0x196350 str r0, [r8, #0x10]
 *   @0x196354 bl 0xb65b0 <memset@plt>
 *   @0x196358 ldr r2, [r8]
 *   @0x19635c vldr s15, [pc, #156]
 *   @0x196360 mov r1, #0
 *   @0x196364 cmp r2, r1
 *   @0x196368 str r1, [r8, #0x4]
 *   @0x19636c vmov s13, r2
 *   @0x196370 vcvt.f32.s32 s14, s13
 *   @0x196374 vmul.f32 s15, s14, s15
 *   @0x196378 vcvt.s32.f32 s15, s15
 *   @0x19637c vstr s15, [r8, #12]
 *   @0x196380 ble 0x1963a0 <_ZN13CGCGeneration7AddRootEP12YYObjectBase+0x190>
 *   @0x196384 add r2, r2, r2, lsl #1
 *   @0x196388 ldr r3, [r8, #0x10]
 *   @0x19638c add r2, r3, r2, lsl #2
 *   @0x196390 str r1, [r3, #0x8]
 *   @0x196394 add r3, r3, #12
 *   @0x196398 cmp r3, r2
 *   @0x19639c bne 0x196390 <_ZN13CGCGeneration7AddRootEP12YYObjectBase+0x180>
 *   @0x1963a0 cmp r6, #0
 *   @0x1963a4 movgt r4, r9
 *   @0x1963a8 movgt r5, #0
 *   @0x1963ac ble 0x1963d8 <_ZN13CGCGeneration7AddRootEP12YYObjectBase+0x1c8>
 *   @0x1963b0 ldr r3, [r4, #0x8]
 *   @0x1963b4 mov r0, r8
 *   @0x1963b8 add r5, r5, #1
 *   @0x1963bc cmp r3, #0
 *   @0x1963c0 ble 0x1963cc <_ZN13CGCGeneration7AddRootEP12YYObjectBase+0x1bc>
 *   @0x1963c4 ldm r4, {r1, r2}
 *   @0x1963c8 bl 0x195ba8 <_ZN8CHashMapIP12YYObjectBaseS1_Li4EE6InsertES1_S1_>
 *   @0x1963cc cmp r5, r6
 *   @0x1963d0 add r4, r4, #12
 *   @0x1963d4 bne 0x1963b0 <_ZN13CGCGeneration7AddRootEP12YYObjectBase+0x1a0>
 *   @0x1963d8 mov r0, r9
 *   @0x1963dc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1963e0 vldr s13, [r8]
 *   @0x1963e4 vcvt.f32.s32 s14, s13
 *   @0x1963e8 vldr s15, [pc, #16]
 *   @0x1963ec ldr r3, [r8, #0x4]
 *   @0x1963f0 vmul.f32 s15, s14, s15
 *   @0x1963f4 vcvt.s32.f32 s15, s15
 *   @0x1963f8 vstr s15, [r8, #12]
 *   @0x1963fc b 0x196230 <_ZN13CGCGeneration7AddRootEP12YYObjectBase+0x20>
 *   @0x196400 svclo #0x19999a
 *   @0x196404 andseq r10, r9, r8, lsl #26
 *
 * ══ §49/54 PrepareGame  0x1df714  size 504  126 条（0x1df714..0x1df90c）
 * @func 0x1df714 0x1df90c  size 504  126 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ShowMessage(char const*)×6 / Extension_Prepare() / Code_Constant_Prepare() / Script_Prepare() / TimeLine_Prepare() / Object_Prepare() / Room_Prepare() / SND_Init()
 * 字段偏移 top8: 0xc×9 / 0x1ac×2 / 0x17c×1 / 0x15c×1 / 0x13c×1 / 0x11c×1 / 0xfc×1 / 0xdc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1df714 push {r3, r4, r5, lr}
 *   @0x1df718 ldr r3, [pc, #0x1ac]
 *   @0x1df71c ldr r1, [pc, #0x1ac]
 *   @0x1df720 ldr r3, [pc, r3]
 *   @0x1df724 add r1, pc, r1
 *   @0x1df728 ldr r4, [r3]
 *   @0x1df72c ldr r3, [r4]
 *   @0x1df730 mov r0, r4
 *   @0x1df734 ldr r3, [r3, #0xc]
 *   @0x1df738 blx r3
 *   @0x1df73c bl 0xf5834 <_Z17Extension_Preparev>
 *   @0x1df740 subs r5, r0, #0
 *   @0x1df744 beq 0x1df870 <_Z11PrepareGamev+0x15c>
 *   @0x1df748 ldr r3, [r4]
 *   @0x1df74c mov r0, r4
 *   @0x1df750 ldr r1, [pc, #0x17c]
 *   @0x1df754 ldr r3, [r3, #0xc]
 *   @0x1df758 add r1, pc, r1
 *   @0x1df75c blx r3
 *   @0x1df760 bl 0xf1b44 <_Z21Code_Constant_Preparev>
 *   @0x1df764 subs r5, r0, #0
 *   @0x1df768 beq 0x1df85c <_Z11PrepareGamev+0x148>
 *   @0x1df76c ldr r3, [r4]
 *   @0x1df770 mov r0, r4
 *   @0x1df774 ldr r1, [pc, #0x15c]
 *   @0x1df778 ldr r3, [r3, #0xc]
 *   @0x1df77c add r1, pc, r1
 *   @0x1df780 blx r3
 *   @0x1df784 bl 0x1e0af0 <_Z14Script_Preparev>
 *   @0x1df788 subs r5, r0, #0
 *   @0x1df78c beq 0x1df894 <_Z11PrepareGamev+0x180>
 *   @0x1df790 ldr r3, [r4]
 *   @0x1df794 mov r0, r4
 *   @0x1df798 ldr r1, [pc, #0x13c]
 *   @0x1df79c ldr r3, [r3, #0xc]
 *   @0x1df7a0 add r1, pc, r1
 *   @0x1df7a4 blx r3
 *   @0x1df7a8 bl 0x1f2c80 <_Z16TimeLine_Preparev>
 *   @0x1df7ac subs r5, r0, #0
 *   @0x1df7b0 beq 0x1df884 <_Z11PrepareGamev+0x170>
 *   @0x1df7b4 ldr r3, [r4]
 *   @0x1df7b8 mov r0, r4
 *   @0x1df7bc ldr r1, [pc, #0x11c]
 *   @0x1df7c0 ldr r3, [r3, #0xc]
 *   @0x1df7c4 add r1, pc, r1
 *   @0x1df7c8 blx r3
 *   @0x1df7cc bl 0x19ebb4 <_Z14Object_Preparev>
 *   @0x1df7d0 cmp r0, #0
 *   @0x1df7d4 beq 0x1df8a8 <_Z11PrepareGamev+0x194>
 *   @0x1df7d8 ldr r3, [r4]
 *   @0x1df7dc mov r0, r4
 *   @0x1df7e0 ldr r1, [pc, #0xfc]
 *   @0x1df7e4 ldr r3, [r3, #0xc]
 *   @0x1df7e8 add r1, pc, r1
 *   @0x1df7ec blx r3
 *   @0x1df7f0 bl 0x1b4cd0 <_Z12Room_Preparev>
 *   @0x1df7f4 cmp r0, #0
 *   @0x1df7f8 beq 0x1df8a8 <_Z11PrepareGamev+0x194>
 *   @0x1df7fc ldr r3, [r4]
 *   @0x1df800 mov r0, r4
 *   @0x1df804 ldr r1, [pc, #0xdc]
 *   @0x1df808 ldr r3, [r3, #0xc]
 *   @0x1df80c add r1, pc, r1
 *   @0x1df810 blx r3
 *   @0x1df814 bl 0x21e940 <_Z8SND_Initv>
 *   @0x1df818 bl 0x21fb80 <_Z13Sound_Preparev>
 *   @0x1df81c subs r5, r0, #0
 *   @0x1df820 beq 0x1df8bc <_Z11PrepareGamev+0x1a8>
 *   @0x1df824 bl 0x2194e0 <_Z13Audio_Preparev>
 *   @0x1df828 ldr r3, [r4]
 *   @0x1df82c ldr r1, [pc, #0xb8]
 *   @0x1df830 mov r0, r4
 *   @0x1df834 add r1, pc, r1
 *   @0x1df838 ldr r3, [r3, #0xc]
 *   @0x1df83c blx r3
 *   @0x1df840 ldr r3, [r4]
 *   @0x1df844 ldr r1, [pc, #0xa4]
 *   @0x1df848 mov r0, r4
 *   @0x1df84c add r1, pc, r1
 *   @0x1df850 ldr r3, [r3, #0xc]
 *   @0x1df854 blx r3
 *   @0x1df858 b 0x1df868 <_Z11PrepareGamev+0x154>
 *   @0x1df85c ldr r0, [pc, #0x90]
 *   @0x1df860 add r0, pc, r0
 *   @0x1df864 bl 0xc4b0c <_Z11ShowMessagePKc>
 *   @0x1df868 mov r0, r5
 *   @0x1df86c pop {r3, r4, r5, pc}
 *   @0x1df870 ldr r0, [pc, #0x80]
 *   @0x1df874 add r0, pc, r0
 *   @0x1df878 bl 0xc4b0c <_Z11ShowMessagePKc>
 *   @0x1df87c mov r0, r5
 *   @0x1df880 pop {r3, r4, r5, pc}
 *   @0x1df884 ldr r0, [pc, #0x70]
 *   @0x1df888 add r0, pc, r0
 *   @0x1df88c bl 0xc4b0c <_Z11ShowMessagePKc>
 *   @0x1df890 b 0x1df868 <_Z11PrepareGamev+0x154>
 *   @0x1df894 ldr r0, [pc, #0x64]
 *   @0x1df898 add r0, pc, r0
 *   @0x1df89c bl 0xc4b0c <_Z11ShowMessagePKc>
 *   @0x1df8a0 mov r0, r5
 *   @0x1df8a4 pop {r3, r4, r5, pc}
 *   @0x1df8a8 ldr r0, [pc, #0x54]
 *   @0x1df8ac mov r5, #0
 *   @0x1df8b0 add r0, pc, r0
 *   @0x1df8b4 bl 0xc4b0c <_Z11ShowMessagePKc>
 *   @0x1df8b8 b 0x1df868 <_Z11PrepareGamev+0x154>
 *   @0x1df8bc ldr r0, [pc, #0x44]
 *   @0x1df8c0 add r0, pc, r0
 *   @0x1df8c4 bl 0xc4b0c <_Z11ShowMessagePKc>
 *   @0x1df8c8 b 0x1df868 <_Z11PrepareGamev+0x154>
 *   @0x1df8cc .word 0x002103fc
 *   @0x1df8d0 andseq r2, r7, r8, ror r3
 *   @0x1df8d4 andseq r2, r7, r4, lsl #7
 *   @0x1df8d8 mulseq r7, r12, r3
 *   @0x1df8dc andseq r2, r7, r12, lsr #7
 *   @0x1df8e0 ldrsbeq r2, [r7], -r4
 *   @0x1df8e4 ldrsheq r2, [r7], -r4
 *   @0x1df8e8 andseq r2, r7, r4, ror #7
 *   @0x1df8ec ldrsheq r2, [r7], -r0
 *   @0x1df8f0 andseq r2, r7, r12, ror #7
 *   @0x1df8f4 mulseq r7, r8, r2
 *   @0x1df8f8 andseq r2, r7, r0, asr #4
 *   @0x1df8fc ldrsbeq r2, [r7], -r12
 *   @0x1df900 mulseq r7, r4, r2
 *   @0x1df904 ldrsheq r2, [r7], -r12
 *   @0x1df908 andseq r2, r7, r4, asr #6
 *
 * ══ §50/54 Error_Show  0xecd7c  size 500  125 条（0xecd7c..0xecf70）
 * @func 0xecd7c 0xecf70  size 500  125 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xecd8c→0x47f3c5, 0xecda4→0x54238a, 0xecda8→0x7590af, 0xecdd0→0x47f3b8, 0xece24→0x47b238, 0xece44→0x47f3b4, 0xece5c→0x542954, 0xece8c→0x3f506c
 * 调用序列: LOCK_RVALUE_MUTEX()×2 / UNLOCK_RVALUE_MUTEX()×2 / ShowForm(char const*, bool)×2 / YYFree(void const*)×2 / operator delete(void*)×2 / IO_Clear() / operator new(unsigned int) / 0xb6538
 * 字段偏移 top8: 0x4×4 / 0x8×3 / 0x1a0×2 / 0x1b8×1 / 0x1b4×1 / 0x17c×1 / 0x12c×1 / 0x110×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xecd7c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xecd80 mov r6, r0
 *   @0xecd84 ldr r4, [pc, #0x1b8]
 *   @0xecd88 mov r7, r1
 *   @0xecd8c ldr r3, [pc, #0x1b4]
 *   @0xecd90 add r4, pc, r4
 *   @0xecd94 ldr r8, [r4, r3]
 *   @0xecd98 ldrb r3, [r8]
 *   @0xecd9c cmp r3, #0
 *   @0xecda0 popne {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xecda4 ldr r3, [pc, #0x1a0]
 *   @0xecda8 ldr r2, [pc, #0x1a0]
 *   @0xecdac ldr r3, [r4, r3]
 *   @0xecdb0 ldr r5, [r4, r2]
 *   @0xecdb4 ldrb r2, [r3]
 *   @0xecdb8 ldrb r3, [r5]
 *   @0xecdbc cmp r2, #0
 *   @0xecdc0 movne r7, #1
 *   @0xecdc4 cmp r3, #0
 *   @0xecdc8 beq 0xece7c <_Z10Error_ShowPKcb+0x100>
 *   @0xecdcc bl 0x18c2c8 <_Z8IO_Clearv>
 *   @0xecdd0 ldr r3, [pc, #0x17c]
 *   @0xecdd4 ldr r9, [r4, r3]
 *   @0xecdd8 ldr r5, [r9]
 *   @0xecddc cmp r5, #0
 *   @0xecde0 beq 0xece00 <_Z10Error_ShowPKcb+0x84>
 *   @0xecde4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xecde8 ldr r10, [r5, #0x4]
 *   @0xecdec sub r10, r10, #1
 *   @0xecdf0 str r10, [r5, #0x4]
 *   @0xecdf4 cmp r10, #0
 *   @0xecdf8 beq 0xecedc <_Z10Error_ShowPKcb+0x160>
 *   @0xecdfc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xece00 mov r0, #12
 *   @0xece04 bl 0x27c524 <_Znwj>
 *   @0xece08 mov r5, r0
 *   @0xece0c subs r0, r6, #0
 *   @0xece10 beq 0xece18 <_Z10Error_ShowPKcb+0x9c>
 *   @0xece14 bl 0xb6538 <strlen@plt>
 *   @0xece18 str r0, [r5, #0x8]
 *   @0xece1c mov r0, r6
 *   @0xece20 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xece24 ldr r3, [pc, #0x12c]
 *   @0xece28 mov r2, #1
 *   @0xece2c stm r5, {r0, r2}
 *   @0xece30 str r5, [r9]
 *   @0xece34 ldr r3, [r4, r3]
 *   @0xece38 ldrb r3, [r3]
 *   @0xece3c cmp r3, #0
 *   @0xece40 beq 0xeceb4 <_Z10Error_ShowPKcb+0x138>
 *   @0xece44 ldr r2, [pc, #0x110]
 *   @0xece48 cmp r7, #0
 *   @0xece4c mov r3, #1
 *   @0xece50 ldr r2, [r4, r2]
 *   @0xece54 strb r3, [r2]
 *   @0xece58 popeq {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xece5c ldr r1, [pc, #0xfc]
 *   @0xece60 movw r2, #0xfe70
 *   @0xece64 strb r3, [r8]
 *   @0xece68 movt r2, #0xffff
 *   @0xece6c ldr r3, [r4, r1]
 *   @0xece70 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xece74 str r2, [r3]
 *   @0xece78 b 0x28fe4c <_Z9Terminatev>
 *   @0xece7c bl 0x17df38 <_Z14ExitFullScreenv>
 *   @0xece80 ldrb r1, [r5]
 *   @0xece84 cmp r1, #0
 *   @0xece88 bne 0xecdcc <_Z10Error_ShowPKcb+0x50>
 *   @0xece8c ldr r3, [pc, #0xd0]
 *   @0xece90 ldr r3, [r4, r3]
 *   @0xece94 ldrb r3, [r3]
 *   @0xece98 cmp r3, #0
 *   @0xece9c beq 0xecdcc <_Z10Error_ShowPKcb+0x50>
 *   @0xecea0 cmp r7, #0
 *   @0xecea4 mov r0, r6
 *   @0xecea8 beq 0xecf34 <_Z10Error_ShowPKcb+0x1b8>
 *   @0xeceac bl 0xecb34 <_Z8ShowFormPKcb>
 *   @0xeceb0 b 0xecdcc <_Z10Error_ShowPKcb+0x50>
 *   @0xeceb4 ldr r3, [pc, #0xac]
 *   @0xeceb8 mov r2, r6
 *   @0xecebc ldr r1, [pc, #0xa8]
 *   @0xecec0 ldr r3, [r4, r3]
 *   @0xecec4 add r1, pc, r1
 *   @0xecec8 ldr r0, [r3]
 *   @0xececc ldr r3, [r0]
 *   @0xeced0 ldr r3, [r3, #0xc]
 *   @0xeced4 blx r3
 *   @0xeced8 b 0xece44 <_Z10Error_ShowPKcb+0xc8>
 *   @0xecedc ldr r0, [r5]
 *   @0xecee0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xecee4 str r10, [r5]
 *   @0xecee8 str r10, [r5, #0x8]
 *   @0xeceec bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xecef0 ldr r10, [r5, #0x4]
 *   @0xecef4 sub r10, r10, #1
 *   @0xecef8 str r10, [r5, #0x4]
 *   @0xecefc cmp r10, #0
 *   @0xecf00 bne 0xecf24 <_Z10Error_ShowPKcb+0x1a8>
 *   @0xecf04 ldr r0, [r5]
 *   @0xecf08 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xecf0c mov r0, r5
 *   @0xecf10 str r10, [r5]
 *   @0xecf14 str r10, [r5, #0x8]
 *   @0xecf18 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0xecf1c mov r0, r5
 *   @0xecf20 bl 0x27d1d0 <_ZdlPv>
 *   @0xecf24 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xecf28 mov r0, r5
 *   @0xecf2c bl 0x27d1d0 <_ZdlPv>
 *   @0xecf30 b 0xecdfc <_Z10Error_ShowPKcb+0x80>
 *   @0xecf34 mov r1, #1
 *   @0xecf38 bl 0xecb34 <_Z8ShowFormPKcb>
 *   @0xecf3c mov r7, r0
 *   @0xecf40 b 0xecdcc <_Z10Error_ShowPKcb+0x50>
 *   @0xecf44 eorseq r4, r0, r0, asr #29
 *   @0xecf48 .word 0xffffc140
 *   @0xecf4c .word 0xffffc144
 *   @0xecf50 .word 0xffffc148
 *   @0xecf54 .word 0xffffc14c
 *   @0xecf58 .word 0xffffbfdc
 *   @0xecf5c .word 0xffffc150
 *   @0xecf60 .word 0xffffc154
 *   @0xecf64 .word 0xffffc158
 *   @0xecf68 .word 0xffffbcf0
 *   @0xecf6c eoreq r7, r4, r8, lsl sp
 *
 * ══ §51/54 YYObjectBase::~YYObjectBase  0x199110  size 500  125 条（0x199110..0x199304）
 * @func 0x199110 0x199304  size 500  125 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x19911c→0x3ebad8, 0x19926c→0x3f76dc, 0x19928c→0x3f76dc, 0x1992d4→0x3eba78
 * 调用序列: MemoryManager::Free(void const*)×4 / FREE_RValue__Pre(RValue*)×2 / operator delete(void*) / YYObjectBase::~YYObjectBase()+0x1dc / FreeRValue(RValue*, RValue**, RValue**)
 * 字段偏移 top8: 0x10×5 / 0x4×5 / 0xc×4 / 0x60×3 / 0x8×3 / 0x24×3 / 0x1d4×2 / 0x1c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x199110 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x199114 mov r6, r0
 *   @0x199118 ldr r9, [pc, #0x1d4]
 *   @0x19911c ldr r3, [pc, #0x1d4]
 *   @0x199120 add r9, pc, r9
 *   @0x199124 ldr r10, [r0, #0x60]
 *   @0x199128 ldr r3, [r9, r3]
 *   @0x19912c cmp r10, #0
 *   @0x199130 add r3, r3, #8
 *   @0x199134 str r3, [r0]
 *   @0x199138 beq 0x1991a0 <_ZN12YYObjectBaseD2Ev+0x90>
 *   @0x19913c mov r4, #0
 *   @0x199140 mov r8, #5
 *   @0x199144 mov r7, r4
 *   @0x199148 ldr r0, [r10, #0x10]
 *   @0x19914c add r3, r4, r4, lsl #1
 *   @0x199150 ldr r1, [r10]
 *   @0x199154 add r3, r0, r3, lsl #2
 *   @0x199158 b 0x199168 <_ZN12YYObjectBaseD2Ev+0x58>
 *   @0x19915c ldr r2, [r5, #0x8]
 *   @0x199160 cmp r2, #0
 *   @0x199164 bgt 0x1991fc <_ZN12YYObjectBaseD2Ev+0xec>
 *   @0x199168 add r4, r4, #1
 *   @0x19916c mov r5, r3
 *   @0x199170 cmp r1, r4
 *   @0x199174 add r3, r3, #12
 *   @0x199178 bge 0x19915c <_ZN12YYObjectBaseD2Ev+0x4c>
 *   @0x19917c cmp r0, #0
 *   @0x199180 beq 0x199190 <_ZN12YYObjectBaseD2Ev+0x80>
 *   @0x199184 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x199188 mov r3, #0
 *   @0x19918c str r3, [r10, #0x10]
 *   @0x199190 mov r0, r10
 *   @0x199194 bl 0x27d1d0 <_ZdlPv>
 *   @0x199198 mov r3, #0
 *   @0x19919c str r3, [r6, #0x60]
 *   @0x1991a0 ldr r4, [r6, #0x4]
 *   @0x1991a4 cmp r4, #0
 *   @0x1991a8 beq 0x199254 <_ZN12YYObjectBaseD2Ev+0x144>
 *   @0x1991ac ldr r5, [r6, #0x24]
 *   @0x1991b0 cmp r5, #0
 *   @0x1991b4 ble 0x1992ec <_ZN12YYObjectBaseD2Ev+0x1dc>
 *   @0x1991b8 mov r7, #0
 *   @0x1991bc mov r8, #5
 *   @0x1991c0 b 0x1991d8 <_ZN12YYObjectBaseD2Ev+0xc8>
 *   @0x1991c4 subs r5, r5, #1
 *   @0x1991c8 str r7, [r4, #0x8]
 *   @0x1991cc str r8, [r4, #0xc]
 *   @0x1991d0 str r7, [r4], #16
 *   @0x1991d4 beq 0x199244 <_ZN12YYObjectBaseD2Ev+0x134>
 *   @0x1991d8 ldr r3, [r4, #0xc]
 *   @0x1991dc sub r3, r3, #1
 *   @0x1991e0 bic r3, r3, #-16777216
 *   @0x1991e4 bic r3, r3, #3
 *   @0x1991e8 cmp r3, #0
 *   @0x1991ec bne 0x1991c4 <_ZN12YYObjectBaseD2Ev+0xb4>
 *   @0x1991f0 mov r0, r4
 *   @0x1991f4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x1991f8 b 0x1991c4 <_ZN12YYObjectBaseD2Ev+0xb4>
 *   @0x1991fc ldr r10, [r5, #0x4]
 *   @0x199200 ldr r3, [r10, #0xc]
 *   @0x199204 sub r3, r3, #1
 *   @0x199208 bic r3, r3, #-16777216
 *   @0x19920c bic r3, r3, #3
 *   @0x199210 cmp r3, #0
 *   @0x199214 bne 0x199220 <_ZN12YYObjectBaseD2Ev+0x110>
 *   @0x199218 mov r0, r10
 *   @0x19921c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x199220 mov r1, #0
 *   @0x199224 str r7, [r10]
 *   @0x199228 str r7, [r10, #0x8]
 *   @0x19922c mov r2, r1
 *   @0x199230 ldr r0, [r5, #0x4]
 *   @0x199234 str r8, [r10, #0xc]
 *   @0x199238 bl 0x190e84 <_Z10FreeRValueP6RValuePS0_S1_>
 *   @0x19923c ldr r10, [r6, #0x60]
 *   @0x199240 b 0x199148 <_ZN12YYObjectBaseD2Ev+0x38>
 *   @0x199244 ldr r0, [r6, #0x4]
 *   @0x199248 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x19924c mov r3, #0
 *   @0x199250 str r3, [r6, #0x4]
 *   @0x199254 ldr r0, [r6, #0x1c]
 *   @0x199258 mov r4, #0
 *   @0x19925c str r4, [r6, #0x18]
 *   @0x199260 cmp r0, r4
 *   @0x199264 str r4, [r6, #0x24]
 *   @0x199268 beq 0x199280 <_ZN12YYObjectBaseD2Ev+0x170>
 *   @0x19926c ldr r3, [pc, #0x88]
 *   @0x199270 ldr r3, [r9, r3]
 *   @0x199274 ldr r3, [r3]
 *   @0x199278 blx r3
 *   @0x19927c str r4, [r6, #0x1c]
 *   @0x199280 ldr r0, [r6, #0x20]
 *   @0x199284 cmp r0, #0
 *   @0x199288 beq 0x1992a4 <_ZN12YYObjectBaseD2Ev+0x194>
 *   @0x19928c ldr r3, [pc, #0x68]
 *   @0x199290 ldr r3, [r9, r3]
 *   @0x199294 ldr r3, [r3]
 *   @0x199298 blx r3
 *   @0x19929c mov r3, #0
 *   @0x1992a0 str r3, [r6, #0x20]
 *   @0x1992a4 ldr r0, [r6, #0x10]
 *   @0x1992a8 cmp r0, #0
 *   @0x1992ac beq 0x1992bc <_ZN12YYObjectBaseD2Ev+0x1ac>
 *   @0x1992b0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1992b4 mov r3, #0
 *   @0x1992b8 str r3, [r6, #0x10]
 *   @0x1992bc ldr r0, [r6, #0x14]
 *   @0x1992c0 cmp r0, #0
 *   @0x1992c4 beq 0x1992d4 <_ZN12YYObjectBaseD2Ev+0x1c4>
 *   @0x1992c8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1992cc mov r3, #0
 *   @0x1992d0 str r3, [r6, #0x14]
 *   @0x1992d4 ldr r3, [pc, #0x24]
 *   @0x1992d8 mov r0, r6
 *   @0x1992dc ldr r3, [r9, r3]
 *   @0x1992e0 add r3, r3, #8
 *   @0x1992e4 str r3, [r6]
 *   @0x1992e8 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1992ec mov r0, r4
 *   @0x1992f0 b 0x199248 <_ZN12YYObjectBaseD2Ev+0x138>
 *   @0x1992f4 eoreq r8, r5, r0, lsr r11
 *   @0x1992f8 .word 0xffffea28
 *   @0x1992fc .word 0xffffea38
 *   @0x199300 .word 0xffffea1c
 *
 * ══ §52/54 CSprite::PreciseCollisionPoint  0x1e4a30  size 500  125 条（0x1e4a30..0x1e4c24）
 * @func 0x1e4a30 0x1e4c24  size 500  125 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6910×4 / CSprite::PreciseCollisionPoint(int, tagYYRECT*, int, int, float, float, float, int, int)+0x11c×3 / CSprite::UnpackWADMask(int) / __aeabi_idivmod / 0xb6580 / 0xb658c
 * 字段偏移 top8: 0x3c×3 / 0x38×2 / 0x28×2 / 0x31×1 / 0x18×1 / 0x1c×1 / 0x20×1 / 0x40×1
 * VFP 指令 68 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e4a30 push {r4, r5, r6, r7, r8, lr}
 *   @0x1e4a34 vpush {d8, d9}
 *   @0x1e4a38 mov r4, r0
 *   @0x1e4a3c mov r6, r3
 *   @0x1e4a40 mov r5, r1
 *   @0x1e4a44 bl 0x1e3994 <_ZN7CSprite13UnpackWADMaskEi>
 *   @0x1e4a48 ldrb r2, [r4, #0x31]
 *   @0x1e4a4c cmp r2, #0
 *   @0x1e4a50 moveq r0, #1
 *   @0x1e4a54 beq 0x1e4b44 <_ZN7CSprite21PreciseCollisionPointEiP9tagYYRECTiifffii+0x114>
 *   @0x1e4a58 ldr r3, [r4, #0x18]
 *   @0x1e4a5c cmp r3, #0
 *   @0x1e4a60 ble 0x1e4b4c <_ZN7CSprite21PreciseCollisionPointEiP9tagYYRECTiifffii+0x11c>
 *   @0x1e4a64 ldr r7, [r4, #0x3c]
 *   @0x1e4a68 mov r0, r5
 *   @0x1e4a6c mov r1, r7
 *   @0x1e4a70 bl 0x318dec <__aeabi_idivmod>
 *   @0x1e4a74 vldr s13, [sp, #52]
 *   @0x1e4a78 vabs.f32 s14, s13
 *   @0x1e4a7c vldr s15, [pc, #404]
 *   @0x1e4a80 vcmpe.f32 s14, s15
 *   @0x1e4a84 subs r8, r1, #0
 *   @0x1e4a88 addlt r8, r8, r7
 *   @0x1e4a8c vmrs APSR_nzcv, fpscr
 *   @0x1e4a90 bpl 0x1e4b58 <_ZN7CSprite21PreciseCollisionPointEiP9tagYYRECTiifffii+0x128>
 *   @0x1e4a94 ldr r2, [sp, #0x38]
 *   @0x1e4a98 vldr s13, [sp, #44]
 *   @0x1e4a9c rsb r2, r6, r2
 *   @0x1e4aa0 vmov s14, r2
 *   @0x1e4aa4 vcvt.f32.s32 s14, s14
 *   @0x1e4aa8 vdiv.f32 s14, s14, s13
 *   @0x1e4aac vldr s13, [r4, #36]
 *   @0x1e4ab0 vcvt.f32.s32 s15, s13
 *   @0x1e4ab4 vadd.f32 s15, s14, s15
 *   @0x1e4ab8 vmov r0, s15
 *   @0x1e4abc bl 0xb6910 <floorf@plt>
 *   @0x1e4ac0 ldr r3, [sp, #0x28]
 *   @0x1e4ac4 ldr r2, [sp, #0x3c]
 *   @0x1e4ac8 vldr s13, [sp, #48]
 *   @0x1e4acc rsb r2, r3, r2
 *   @0x1e4ad0 vmov s14, r2
 *   @0x1e4ad4 vcvt.f32.s32 s14, s14
 *   @0x1e4ad8 vdiv.f32 s14, s14, s13
 *   @0x1e4adc vldr s13, [r4, #40]
 *   @0x1e4ae0 vcvt.f32.s32 s15, s13
 *   @0x1e4ae4 vmov s13, r0
 *   @0x1e4ae8 vadd.f32 s15, s14, s15
 *   @0x1e4aec vcvt.s32.f32 s13, s13
 *   @0x1e4af0 vmov r0, s15
 *   @0x1e4af4 vmov r5, s13
 *   @0x1e4af8 bl 0xb6910 <floorf@plt>
 *   @0x1e4afc vmov s14, r0
 *   @0x1e4b00 vcvt.s32.f32 s14, s14
 *   @0x1e4b04 vmov r0, s14
 *   @0x1e4b08 cmp r5, #0
 *   @0x1e4b0c blt 0x1e4b4c <_ZN7CSprite21PreciseCollisionPointEiP9tagYYRECTiifffii+0x11c>
 *   @0x1e4b10 ldr r3, [r4, #0x1c]
 *   @0x1e4b14 cmp r5, r3
 *   @0x1e4b18 bge 0x1e4b4c <_ZN7CSprite21PreciseCollisionPointEiP9tagYYRECTiifffii+0x11c>
 *   @0x1e4b1c cmp r0, #0
 *   @0x1e4b20 blt 0x1e4b4c <_ZN7CSprite21PreciseCollisionPointEiP9tagYYRECTiifffii+0x11c>
 *   @0x1e4b24 ldr r2, [r4, #0x20]
 *   @0x1e4b28 cmp r0, r2
 *   @0x1e4b2c bge 0x1e4b4c <_ZN7CSprite21PreciseCollisionPointEiP9tagYYRECTiifffii+0x11c>
 *   @0x1e4b30 ldr r2, [r4, #0x40]
 *   @0x1e4b34 add r8, r2, r8, lsl #3
 *   @0x1e4b38 ldr r2, [r8, #0x4]
 *   @0x1e4b3c mla r0, r3, r0, r2
 *   @0x1e4b40 ldrb r0, [r0, r5]
 *   @0x1e4b44 vpop {d8, d9}
 *   @0x1e4b48 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1e4b4c vpop {d8, d9}
 *   @0x1e4b50 mov r0, #0
 *   @0x1e4b54 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1e4b58 vldr s13, [sp, #52]
 *   @0x1e4b5c vldr s17, [pc, #184]
 *   @0x1e4b60 vnmul.f32 s15, s13, s17
 *   @0x1e4b64 vldr s16, [pc, #180]
 *   @0x1e4b68 vdiv.f32 s15, s15, s16
 *   @0x1e4b6c vmov r0, s15
 *   @0x1e4b70 bl 0xb6580 <sinf@plt>
 *   @0x1e4b74 vldr s14, [sp, #52]
 *   @0x1e4b78 vmul.f32 s17, s14, s17
 *   @0x1e4b7c vdiv.f32 s17, s17, s16
 *   @0x1e4b80 vmov s19, r0
 *   @0x1e4b84 vmov r0, s17
 *   @0x1e4b88 bl 0xb658c <cosf@plt>
 *   @0x1e4b8c ldr r3, [sp, #0x28]
 *   @0x1e4b90 ldr r2, [sp, #0x3c]
 *   @0x1e4b94 vldr s15, [sp, #44]
 *   @0x1e4b98 rsb r2, r3, r2
 *   @0x1e4b9c vmov s16, r2
 *   @0x1e4ba0 ldr r2, [sp, #0x38]
 *   @0x1e4ba4 vcvt.f32.s32 s16, s16
 *   @0x1e4ba8 rsb r6, r6, r2
 *   @0x1e4bac vmov s13, r6
 *   @0x1e4bb0 vmul.f32 s14, s16, s19
 *   @0x1e4bb4 vcvt.f32.s32 s18, s13
 *   @0x1e4bb8 vldr s13, [r4, #36]
 *   @0x1e4bbc vmov s17, r0
 *   @0x1e4bc0 vmla.f32 s14, s18, s17
 *   @0x1e4bc4 vdiv.f32 s14, s14, s15
 *   @0x1e4bc8 vcvt.f32.s32 s15, s13
 *   @0x1e4bcc vadd.f32 s15, s14, s15
 *   @0x1e4bd0 vmov r0, s15
 *   @0x1e4bd4 bl 0xb6910 <floorf@plt>
 *   @0x1e4bd8 vmul.f32 s15, s19, s18
 *   @0x1e4bdc vldr s14, [sp, #48]
 *   @0x1e4be0 vldr s13, [r4, #40]
 *   @0x1e4be4 vnmls.f32 s15, s17, s16
 *   @0x1e4be8 vdiv.f32 s15, s15, s14
 *   @0x1e4bec vcvt.f32.s32 s14, s13
 *   @0x1e4bf0 vmov s13, r0
 *   @0x1e4bf4 vadd.f32 s14, s15, s14
 *   @0x1e4bf8 vcvt.s32.f32 s13, s13
 *   @0x1e4bfc vmov r0, s14
 *   @0x1e4c00 vmov r5, s13
 *   @0x1e4c04 bl 0xb6910 <floorf@plt>
 *   @0x1e4c08 vmov s14, r0
 *   @0x1e4c0c vcvt.s32.f32 s14, s14
 *   @0x1e4c10 vmov r0, s14
 *   @0x1e4c14 b 0x1e4b08 <_ZN7CSprite21PreciseCollisionPointEiP9tagYYRECTiifffii+0xd8>
 *   @0x1e4c18 ldmlo r1, {r0, r1, r2, r4, r8, r9, r10, r12, sp, pc} ^
 *   @0x1e4c1c ldrdmi r0, r1, [r9], #-251
 *   @0x1e4c20 teqmi r4, #0
 *
 * ══ §53/54 CSkeletonInstance::SetAnimationTransform  0xbe80c  size 496  124 条（0xbe80c..0xbe9fc）
 * @func 0xbe80c 0xbe9fc  size 496  124 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __aeabi_idivmod×2 / CSkeletonInstance::FrameCount(int) / CSkeletonInstance::SetAnimationTransform(int, float, float, float, float, float, CInstance*)+0xe8 / spAnimationState_update / spAnimationState_apply / Perform_Event(CInstance*, CInstance*, int, int) / spSkeleton_updateWorldTransform
 * 字段偏移 top8: 0x1c×5 / 0x5×2 / 0x28×2 / 0xc×2 / 0x44×1 / 0x24×1 / 0x5c×1 / 0x50×1
 * VFP 指令 49 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbe80c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xbe810 vpush {d8, d9, d10}
 *   @0xbe814 mov r6, r1
 *   @0xbe818 vldr s17, [sp, #56]
 *   @0xbe81c ldr r1, [r0, #0x1c]
 *   @0xbe820 mov r4, r0
 *   @0xbe824 mov r10, r3
 *   @0xbe828 vmov s18, r2
 *   @0xbe82c cmp r1, #0
 *   @0xbe830 vldr s16, [sp, #60]
 *   @0xbe834 vldr s19, [sp, #64]
 *   @0xbe838 ldr r8, [sp, #0x44]
 *   @0xbe83c beq 0xbe9f4 <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance+0x1e8>
 *   @0xbe840 vldr s20, [r0, #8]
 *   @0xbe844 vldr s21, [r0, #12]
 *   @0xbe848 vmul.f32 s20, s17, s20
 *   @0xbe84c adds r9, r8, #0
 *   @0xbe850 ldrb r3, [r0, #0x5]
 *   @0xbe854 movne r9, #1
 *   @0xbe858 cmp r3, #0
 *   @0xbe85c vmul.f32 s21, s16, s21
 *   @0xbe860 vabs.f32 s20, s20
 *   @0xbe864 vabs.f32 s21, s21
 *   @0xbe868 bne 0xbe878 <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance+0x6c>
 *   @0xbe86c ldr r3, [r0]
 *   @0xbe870 cmp r3, r6
 *   @0xbe874 beq 0xbe994 <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance+0x188>
 *   @0xbe878 mov r0, r4
 *   @0xbe87c mov r1, #0
 *   @0xbe880 bl 0xbe220 <_ZN17CSkeletonInstance10FrameCountEi>
 *   @0xbe884 subs r5, r0, #0
 *   @0xbe888 ble 0xbe8f4 <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance+0xe8>
 *   @0xbe88c mov r0, r6
 *   @0xbe890 mov r1, r5
 *   @0xbe894 bl 0x318dec <__aeabi_idivmod>
 *   @0xbe898 ldr r0, [r4]
 *   @0xbe89c mov r7, r1
 *   @0xbe8a0 mov r1, r5
 *   @0xbe8a4 bl 0x318dec <__aeabi_idivmod>
 *   @0xbe8a8 sub r3, r5, #1
 *   @0xbe8ac vmov s15, r5
 *   @0xbe8b0 ldr r0, [r4, #0x28]
 *   @0xbe8b4 vcvt.f32.s32 s13, s15
 *   @0xbe8b8 rsb r2, r7, r1
 *   @0xbe8bc cmp r2, r3
 *   @0xbe8c0 ldr r3, [r4, #0x24]
 *   @0xbe8c4 addge r7, r7, r5
 *   @0xbe8c8 vldr s15, [r3, #4]
 *   @0xbe8cc rsb r1, r1, r7
 *   @0xbe8d0 vmov s14, r1
 *   @0xbe8d4 vcvt.f32.s32 s14, s14
 *   @0xbe8d8 vdiv.f32 s14, s14, s13
 *   @0xbe8dc vmul.f32 s15, s14, s15
 *   @0xbe8e0 vmov r1, s15
 *   @0xbe8e4 bl 0x2837fc <spAnimationState_update>
 *   @0xbe8e8 ldr r0, [r4, #0x28]
 *   @0xbe8ec ldr r1, [r4, #0x1c]
 *   @0xbe8f0 bl 0x283220 <spAnimationState_apply>
 *   @0xbe8f4 vldr s14, [r4, #8]
 *   @0xbe8f8 vmul.f32 s17, s17, s14
 *   @0xbe8fc vldr s15, [r4, #12]
 *   @0xbe900 ldr r2, [r4, #0x1c]
 *   @0xbe904 str r6, [r4]
 *   @0xbe908 mov r1, #0
 *   @0xbe90c vstr s18, [r2, #88]
 *   @0xbe910 str r10, [r2, #0x5c]
 *   @0xbe914 ldr r3, [r2, #0xc]
 *   @0xbe918 vmul.f32 s16, s16, s15
 *   @0xbe91c vcmpe.f32 s17, #0
 *   @0xbe920 vmrs APSR_nzcv, fpscr
 *   @0xbe924 vcmpe.f32 s16, #0
 *   @0xbe928 movpl r0, #0
 *   @0xbe92c movmi r0, #1
 *   @0xbe930 str r0, [r2, #0x50]
 *   @0xbe934 vmrs APSR_nzcv, fpscr
 *   @0xbe938 movpl r0, #0
 *   @0xbe93c movmi r0, #1
 *   @0xbe940 cmp r9, r1
 *   @0xbe944 str r0, [r2, #0x54]
 *   @0xbe948 vstr s20, [r3, #32]
 *   @0xbe94c vstr s21, [r3, #36]
 *   @0xbe950 vstr s19, [r3, #28]
 *   @0xbe954 strb r1, [r4, #0x5]
 *   @0xbe958 beq 0xbe974 <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance+0x168>
 *   @0xbe95c mov r2, #7
 *   @0xbe960 mov r0, r8
 *   @0xbe964 mov r1, r8
 *   @0xbe968 mov r3, #58
 *   @0xbe96c bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0xbe970 ldr r2, [r4, #0x1c]
 *   @0xbe974 mov r0, r2
 *   @0xbe978 bl 0x289ee4 <spSkeleton_updateWorldTransform>
 *   @0xbe97c vpop {d8, d9, d10}
 *   @0xbe980 mov r2, #1
 *   @0xbe984 ldr r0, [r4, #0x20]
 *   @0xbe988 ldr r1, [r4, #0x1c]
 *   @0xbe98c pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xbe990 b 0x28a8b4 <spSkeletonBounds_update>
 *   @0xbe994 vldr s15, [r1, #88]
 *   @0xbe998 vcmp.f32 s15, s18
 *   @0xbe99c vmrs APSR_nzcv, fpscr
 *   @0xbe9a0 bne 0xbe878 <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance+0x6c>
 *   @0xbe9a4 vmov s14, r10
 *   @0xbe9a8 vldr s15, [r1, #92]
 *   @0xbe9ac vcmp.f32 s15, s14
 *   @0xbe9b0 vmrs APSR_nzcv, fpscr
 *   @0xbe9b4 bne 0xbe878 <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance+0x6c>
 *   @0xbe9b8 ldr r3, [r1, #0xc]
 *   @0xbe9bc vldr s15, [r3, #32]
 *   @0xbe9c0 vcmp.f32 s15, s20
 *   @0xbe9c4 vmrs APSR_nzcv, fpscr
 *   @0xbe9c8 bne 0xbe878 <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance+0x6c>
 *   @0xbe9cc vldr s15, [r3, #36]
 *   @0xbe9d0 vcmp.f32 s15, s21
 *   @0xbe9d4 vmrs APSR_nzcv, fpscr
 *   @0xbe9d8 bne 0xbe878 <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance+0x6c>
 *   @0xbe9dc vldr s15, [r3, #28]
 *   @0xbe9e0 vcmp.f32 s15, s19
 *   @0xbe9e4 vmrs APSR_nzcv, fpscr
 *   @0xbe9e8 bne 0xbe878 <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance+0x6c>
 *   @0xbe9ec cmp r9, #0
 *   @0xbe9f0 bne 0xbe95c <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance+0x150>
 *   @0xbe9f4 vpop {d8, d9, d10}
 *   @0xbe9f8 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ §54/54 ThrowNonBlockingConnectSocketNetworkEvent  0x2989ac  size 496  124 条（0x2989ac..0x298b9c）
 * @func 0x2989ac 0x298bac  size 512  128 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x2989c4→0x3f7814, 0x298a40→0x75790c, 0x298a90→0x3f5254, 0x298a94→0x536f70, 0x298ab4→0x542374, 0x298abc→0x53ab70
 * 调用序列: F_DsMapAdd_Internal(int, char*, double)×5 / InitNetworkEvent() / F_DsMapAdd_Internal(int, char*, char*) / ThrowNonBlockingConnectSocketNetworkEvent(int, bool)+0x1ac / Perform_Event(CInstance*, CInstance*, int, int)
 * 字段偏移 top8: 0x8×3 / 0x4×3 / 0x138×2 / 0xf4×2 / 0x1a8×1 / 0x1a0×1 / 0x19c×1 / 0x178×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2989ac push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2989b0 vpush {d8}
 *   @0x2989b4 mov r6, r0
 *   @0x2989b8 ldr r5, [pc, #0x1a8]
 *   @0x2989bc mov r7, r1
 *   @0x2989c0 bl 0x29871c <_Z16InitNetworkEventv>
 *   @0x2989c4 ldr r0, [pc, #0x1a0]
 *   @0x2989c8 add r5, pc, r5
 *   @0x2989cc ldr r1, [pc, #0x19c]
 *   @0x2989d0 mov r2, #0
 *   @0x2989d4 mov r3, #0
 *   @0x2989d8 ldr r4, [r5, r0]
 *   @0x2989dc add r1, pc, r1
 *   @0x2989e0 movt r3, #0x4010
 *   @0x2989e4 movw r10, #0x1d10
 *   @0x2989e8 ldr r0, [r4]
 *   @0x2989ec bl 0x104d94 <_Z19F_DsMapAdd_InternaliPcd>
 *   @0x2989f0 vmov s14, r6
 *   @0x2989f4 ldr r1, [pc, #0x178]
 *   @0x2989f8 add r6, r6, r6, lsl #1
 *   @0x2989fc vcvt.f64.s32 d8, s14
 *   @0x298a00 ldr r0, [r4]
 *   @0x298a04 add r1, pc, r1
 *   @0x298a08 vmov r2, r3, d8
 *   @0x298a0c bl 0x104d94 <_Z19F_DsMapAdd_InternaliPcd>
 *   @0x298a10 ldr r1, [pc, #0x160]
 *   @0x298a14 vmov r2, r3, d8
 *   @0x298a18 add r1, pc, r1
 *   @0x298a1c ldr r0, [r4]
 *   @0x298a20 bl 0x104d94 <_Z19F_DsMapAdd_InternaliPcd>
 *   @0x298a24 vmov s15, r7
 *   @0x298a28 ldr r1, [pc, #0x14c]
 *   @0x298a2c vcvt.f64.u32 d7, s15
 *   @0x298a30 ldr r0, [r4]
 *   @0x298a34 add r1, pc, r1
 *   @0x298a38 vmov r2, r3, d7
 *   @0x298a3c bl 0x104d94 <_Z19F_DsMapAdd_InternaliPcd>
 *   @0x298a40 ldr r3, [pc, #0x138]
 *   @0x298a44 ldr r1, [pc, #0x138]
 *   @0x298a48 ldr r0, [r4]
 *   @0x298a4c ldr r3, [r5, r3]
 *   @0x298a50 add r1, pc, r1
 *   @0x298a54 add r3, r3, r6, lsl #2
 *   @0x298a58 ldr r2, [r3, #0x8]
 *   @0x298a5c ldr r6, [r3, #0x4]
 *   @0x298a60 cmp r2, #0
 *   @0x298a64 ldrne r6, [r2]
 *   @0x298a68 add r2, r6, #108
 *   @0x298a6c bl 0x104f64 <_Z19F_DsMapAdd_InternaliPcS_>
 *   @0x298a70 ldr r2, [r6, #0xac]
 *   @0x298a74 ldr r1, [pc, #0x10c]
 *   @0x298a78 ldr r0, [r4]
 *   @0x298a7c vmov s15, r2
 *   @0x298a80 add r1, pc, r1
 *   @0x298a84 vcvt.f64.s32 d7, s15
 *   @0x298a88 vmov r2, r3, d7
 *   @0x298a8c bl 0x104d94 <_Z19F_DsMapAdd_InternaliPcd>
 *   @0x298a90 ldr r1, [pc, #0xf4]
 *   @0x298a94 ldr r3, [pc, #0xf4]
 *   @0x298a98 ldr r2, [r4]
 *   @0x298a9c ldr r8, [r5, r1]
 *   @0x298aa0 str r2, [r8]
 *   @0x298aa4 ldr r9, [r5, r3]
 *   @0x298aa8 ldr r3, [r9, r10]
 *   @0x298aac cmp r3, #0
 *   @0x298ab0 ble 0x298b58 <_Z41ThrowNonBlockingConnectSocketNetworkEventib+0x1ac>
 *   @0x298ab4 ldr r2, [pc, #0xd8]
 *   @0x298ab8 mov r4, #0
 *   @0x298abc ldr r3, [pc, #0xd4]
 *   @0x298ac0 movw r7, #0x3a24
 *   @0x298ac4 ldr r6, [r5, r2]
 *   @0x298ac8 ldr r5, [r5, r3]
 *   @0x298acc ldr r3, [r6]
 *   @0x298ad0 ldr r1, [r5, r7]
 *   @0x298ad4 ldr r2, [r3, #0x4]
 *   @0x298ad8 ldr r1, [r1, r4, lsl #2]
 *   @0x298adc ldr r3, [r3]
 *   @0x298ae0 and r2, r1, r2
 *   @0x298ae4 ldr r3, [r3, r2, lsl #3]
 *   @0x298ae8 cmp r3, #0
 *   @0x298aec bne 0x298b00 <_Z41ThrowNonBlockingConnectSocketNetworkEventib+0x154>
 *   @0x298af0 b 0x298b10 <_Z41ThrowNonBlockingConnectSocketNetworkEventib+0x164>
 *   @0x298af4 ldr r3, [r3, #0x4]
 *   @0x298af8 cmp r3, #0
 *   @0x298afc beq 0x298b10 <_Z41ThrowNonBlockingConnectSocketNetworkEventib+0x164>
 *   @0x298b00 ldr r2, [r3, #0x8]
 *   @0x298b04 cmp r1, r2
 *   @0x298b08 bne 0x298af4 <_Z41ThrowNonBlockingConnectSocketNetworkEventib+0x148>
 *   @0x298b0c ldr r3, [r3, #0xc]
 *   @0x298b10 ldr r11, [r3, #0xc4]
 *   @0x298b14 cmp r11, #0
 *   @0x298b18 bne 0x298b3c <_Z41ThrowNonBlockingConnectSocketNetworkEventib+0x190>
 *   @0x298b1c b 0x298b48 <_Z41ThrowNonBlockingConnectSocketNetworkEventib+0x19c>
 *   @0x298b20 ldr r11, [r11]
 *   @0x298b24 mov r1, r0
 *   @0x298b28 mov r2, #7
 *   @0x298b2c mov r3, #68
 *   @0x298b30 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0x298b34 cmp r11, #0
 *   @0x298b38 beq 0x298b48 <_Z41ThrowNonBlockingConnectSocketNetworkEventib+0x19c>
 *   @0x298b3c ldr r0, [r11, #0x8]
 *   @0x298b40 cmp r0, #0
 *   @0x298b44 bne 0x298b20 <_Z41ThrowNonBlockingConnectSocketNetworkEventib+0x174>
 *   @0x298b48 ldr r3, [r9, r10]
 *   @0x298b4c add r4, r4, #1
 *   @0x298b50 cmp r3, r4
 *   @0x298b54 bgt 0x298acc <_Z41ThrowNonBlockingConnectSocketNetworkEventib+0x120>
 *   @0x298b58 vpop {d8}
 *   @0x298b5c mvn r3, #0
 *   @0x298b60 str r3, [r8]
 *   @0x298b64 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x298b68 andseq r9, r5, r8, lsl #5
 *   @0x298b6c .word 0xfffff750
 *   @0x298b70 andeq sp, r10, r12, asr #14
 *   @0x298b74 andeq r0, r12, r4, lsl #25
 *   @0x298b78 andeq r8, r9, r8, lsr #32
 *   @0x298b7c andeq r0, r12, r4, ror r12
 *   @0x298b80 .word 0xfffffd54
 *   @0x298b84 andeq r0, r12, r4, asr r12
 *   @0x298b88 andeq r0, r12, r0, lsl r12
 *   @0x298b8c .word 0xffffdec8
 *   @0x298b90 .word 0xffffdeb8
 *   @0x298b94 .word 0xffffbfec
 *   @0x298b98 .word 0xffffdebc
 */
