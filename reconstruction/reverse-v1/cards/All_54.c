/* cally 逆向卡：All_54 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 146 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/146 SoundHardware::Stop(void*)  0x220d90  size 216  47 条（0x220d90..0x220e68）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x220d90 0x220e68  size 216  47 条
 * 部分覆盖: 本节 47/54 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x220d9c→0x755361, 0x220db4→0x755363, 0x220dc8→0x755362, 0x220ddc→0x755360, 0x220e18→0x3eb70c
 * 调用序列: 0xb6b14 / CheckALError()
 * 字段偏移 top8: 0x3c×3 / 0xa8×2 / 0x94×1 / 0x84×1 / 0x74×1 / 0x4×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x220d90 push {r3, r4, r5, lr}
 *   @0x220d94 mov r5, r1
 *   @0x220d98 ldr r4, [pc, #0xa8]
 *   @0x220d9c ldr r3, [pc, #0xa8]
 *   @0x220da0 add r4, pc, r4
 *   @0x220da4 ldr r3, [r4, r3]
 *   @0x220da8 ldrb r3, [r3]
 *   @0x220dc8 ldr r3, [pc, #0x84]
 *   @0x220dcc ldr r3, [r4, r3]
 *   @0x220dd0 ldrb r3, [r3]
 *   @0x220dd4 cmp r3, #0
 *   @0x220dd8 popne {r3, r4, r5, pc}
 *   @0x220ddc ldr r3, [pc, #0x74]
 *   @0x220de0 ldr r3, [r4, r3]
 *   @0x220de4 ldrb r4, [r3]
 *   @0x220de8 cmp r4, #0
 *   @0x220dec popne {r3, r4, r5, pc}
 *   @0x220df0 cmp r5, #0
 *   @0x220df4 popeq {r3, r4, r5, pc}
 *   @0x220df8 add r3, r5, r4
 *   @0x220dfc add r4, r4, #4
 *   @0x220e00 ldr r0, [r3, #0x4]
 *   @0x220e04 bl 0xb6b14 <alSourceStop@plt>
 *   @0x220e08 bl 0x220198 <_Z12CheckALErrorv>
 *   @0x220e0c cmp r4, #16
 *   @0x220e10 bne 0x220df8 <_ZN13SoundHardware4StopEPv+0x68>
 *   @0x220e14 pop {r3, r4, r5, pc}
 *   @0x220e18 ldr r3, [pc, #0x3c]
 *   @0x220e1c ldr r2, [pc, #0x3c]
 *   @0x220e20 ldr r1, [pc, #0x3c]
 *   @0x220e24 ldr r3, [r4, r3]
 *   @0x220e28 add r2, pc, r2
 *   @0x220e2c add r1, pc, r1
 *   @0x220e30 add r2, r2, #144
 *   @0x220e34 ldr r0, [r3]
 *   @0x220e38 ldr r3, [r0]
 *   @0x220e3c ldr r3, [r3, #0xc]
 *   @0x220e40 blx r3
 *   @0x220e44 b 0x220db4 <_ZN13SoundHardware4StopEPv+0x24>
 *   @0x220e48 ldrheq r0, [sp], -r0
 *   @0x220e4c .word 0xfffff7d8
 *   @0x220e50 .word 0xffffd3fc
 *   @0x220e54 .word 0xfffff7e0
 *   @0x220e58 .word 0xfffff7e4
 *   @0x220e5c .word 0xffffbac4
 *   @0x220e60 andseq sp, r3, r0, lsr #3
 *   @0x220e64 andseq r3, r3, r0, lsl r10
 *
 * ══ §2/146 rescale64  0x231dfc  size 216  54 条（0x231dfc..0x231ed4）
 * @func 0x231dfc 0x231ed4  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: rescale64+0xc8 / rescale64+0x3c
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x231dfc push {r4, r5, r6, r7, r8, r9, r10}
 *   @0x231e00 cmp r0, r2
 *   @0x231e04 sbcs r10, r1, r3
 *   @0x231e08 ldrd r8, r9, [sp, #28]
 *   @0x231e0c movge r0, r8
 *   @0x231e10 movge r1, r9
 *   @0x231e14 bge 0x231ebc <rescale64+0xc0>
 *   @0x231e18 cmp r0, #1
 *   @0x231e1c sbcs r12, r1, #0
 *   @0x231e20 blt 0x231ec4 <rescale64+0xc8>
 *   @0x231e24 mov r12, #64
 *   @0x231e28 mov r4, #0
 *   @0x231e2c mov r5, #0
 *   @0x231e30 mov r6, #1
 *   @0x231e34 mov r7, #0
 *   @0x231e38 adds r0, r0, r0
 *   @0x231e3c adc r1, r1, r1
 *   @0x231e40 adds r4, r4, r4
 *   @0x231e44 adc r5, r5, r5
 *   @0x231e48 subs r12, r12, #1
 *   @0x231e4c beq 0x231e70 <rescale64+0x74>
 *   @0x231e50 cmp r0, r2
 *   @0x231e54 sbcs r10, r1, r3
 *   @0x231e58 blt 0x231e38 <rescale64+0x3c>
 *   @0x231e5c orr r4, r4, r6
 *   @0x231e60 orr r5, r5, r7
 *   @0x231e64 subs r0, r0, r2
 *   @0x231e68 sbc r1, r1, r3
 *   @0x231e6c b 0x231e38 <rescale64+0x3c>
 *   @0x231e70 mov r2, #0
 *   @0x231e74 mov r3, #0
 *   @0x231e78 mov r6, #1
 *   @0x231e7c mov r7, #0
 *   @0x231e80 mov r12, #64
 *   @0x231e84 and r0, r4, r6
 *   @0x231e88 and r1, r5, r7
 *   @0x231e8c orrs r10, r0, r1
 *   @0x231e90 beq 0x231e9c <rescale64+0xa0>
 *   @0x231e94 adds r2, r2, r8
 *   @0x231e98 adc r3, r3, r9
 *   @0x231e9c asrs r5, r5, #1
 *   @0x231ea0 rrx r4, r4
 *   @0x231ea4 asrs r3, r3, #1
 *   @0x231ea8 rrx r2, r2
 *   @0x231eac subs r12, r12, #1
 *   @0x231eb0 bne 0x231e84 <rescale64+0x88>
 *   @0x231eb4 mov r0, r2
 *   @0x231eb8 mov r1, r3
 *   @0x231ebc pop {r4, r5, r6, r7, r8, r9, r10}
 *   @0x231ec0 bx lr
 *   @0x231ec4 mov r0, #0
 *   @0x231ec8 mov r1, r0
 *   @0x231ecc pop {r4, r5, r6, r7, r8, r9, r10}
 *   @0x231ed0 bx lr
 *
 * ══ §3/146 CPhysicsWorld::CreateFrictionJoint(CPhysicsObject*, CPhysicsObject*, float, float, float, float, bool)  0x239674  size 216  54 条（0x239674..0x23974c）
 * @func 0x239674 0x23975c  size 232  58 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2FrictionJointDef::Initialize(b2Body*, b2Body*, b2Vec2 const&) / CPhysicsJointFactory::CreateJoint(CPhysicsWorld*, b2JointDef const&)
 * 字段偏移 top8: 0x4×2 / 0x1c×2 / 0x30×2 / 0x34×2 / 0x5c×1 / 0x60×1 / 0x64×1 / 0x10×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x239674 vmov s14, r3
 *   @0x239678 ldr r1, [r1]
 *   @0x23967c push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x239680 mov r4, r0
 *   @0x239684 vldr s15, [r4, #96]
 *   @0x239688 sub sp, sp, #60
 *   @0x23968c vmul.f32 s14, s15, s14
 *   @0x239690 vldr s13, [sp, #88]
 *   @0x239694 ldrh r3, [r1, #4]
 *   @0x239698 ldr r2, [r2]
 *   @0x23969c add r5, sp, #12
 *   @0x2396a0 tst r3, #2
 *   @0x2396a4 ldr r9, [sp, #0x5c]
 *   @0x2396a8 orreq r3, r3, #2
 *   @0x2396ac strheq r3, [r1, #4]
 *   @0x2396b0 ldrh r3, [r2, #4]
 *   @0x2396b4 moveq r0, #0
 *   @0x2396b8 streq r0, [r1, #0xa0]
 *   @0x2396bc mov r12, #0
 *   @0x2396c0 tst r3, #2
 *   @0x2396c4 ldr r8, [sp, #0x60]
 *   @0x2396c8 ldrb r6, [sp, #0x64]
 *   @0x2396cc orreq r3, r3, #2
 *   @0x2396d0 moveq r0, #0
 *   @0x2396d4 strheq r3, [r2, #4]
 *   @0x2396d8 streq r0, [r2, #0xa0]
 *   @0x2396dc add r3, sp, #4
 *   @0x2396e0 mov r0, r5
 *   @0x2396e4 mov lr, #0
 *   @0x2396e8 vmul.f32 s15, s15, s13
 *   @0x2396ec str lr, [sp, #0x10]
 *   @0x2396f0 str lr, [sp, #0x14]
 *   @0x2396f4 vstr s14, [sp, #4]
 *   @0x2396f8 str lr, [sp, #0x18]
 *   @0x2396fc mov r7, #9
 *   @0x239700 strb lr, [sp, #0x1c]
 *   @0x239704 str r12, [sp, #0x20]
 *   @0x239708 str r12, [sp, #0x24]
 *   @0x23970c str r12, [sp, #0x28]
 *   @0x239710 str r12, [sp, #0x2c]
 *   @0x239714 str r12, [sp, #0x30]
 *   @0x239718 str r12, [sp, #0x34]
 *   @0x23971c str r7, [sp, #0xc]
 *   @0x239720 vstr s15, [sp, #8]
 *   @0x239724 bl 0x2cd998 <_ZN18b2FrictionJointDef10InitializeEP6b2BodyS1_RK6b2Vec2>
 *   @0x239728 mov r1, r5
 *   @0x23972c mov r0, r4
 *   @0x239730 str r9, [sp, #0x30]
 *   @0x239734 str r8, [sp, #0x34]
 *   @0x239738 strb r6, [sp, #0x1c]
 *   @0x23973c bl 0x23b2a8 <_ZN20CPhysicsJointFactory11CreateJointEP13CPhysicsWorldRK10b2JointDef>
 *   @0x239740 ldr r0, [r0, #0x8]
 *   @0x239744 add sp, sp, #60
 *   @0x239748 pop {r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §4/146 iffLogGetName(char const*)  0x27b950  size 216  54 条（0x27b950..0x27ba28）
 * @func 0x27b950 0x27ba28  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: unsigned int CHashMapCalculateHash<char const*>(char const*) / iffLogGetName(char const*)+0xa4
 * 字段偏移 top8: 0x8×3 / 0xc4×1 / 0x10×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27b950 push {r4, r5, r6, r7, r8, lr}
 *   @0x27b954 bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_>
 *   @0x27b958 ldr r2, [pc, #0xc4]
 *   @0x27b95c ldr r2, [pc, r2]
 *   @0x27b960 ldr r1, [r2, #0x8]
 *   @0x27b964 ldr r7, [r2, #0x10]
 *   @0x27b968 bic r0, r0, #-2147483648
 *   @0x27b96c and r3, r0, r1
 *   @0x27b970 lsl r4, r3, #1
 *   @0x27b974 add r12, r4, r3
 *   @0x27b978 add r12, r7, r12, lsl #2
 *   @0x27b97c ldr r12, [r12, #0x8]
 *   @0x27b980 cmp r12, #0
 *   @0x27b984 beq 0x27b9f4 <_Z13iffLogGetNamePKc+0xa4>
 *   @0x27b988 cmp r0, r12
 *   @0x27b98c beq 0x27ba04 <_Z13iffLogGetNamePKc+0xb4>
 *   @0x27b990 ldr r8, [r2]
 *   @0x27b994 and r12, r1, r12
 *   @0x27b998 add r2, r3, r8
 *   @0x27b99c rsb r12, r12, r2
 *   @0x27b9a0 tst r12, r1
 *   @0x27b9a4 bmi 0x27b9f4 <_Z13iffLogGetNamePKc+0xa4>
 *   @0x27b9a8 mov r12, #0
 *   @0x27b9ac b 0x27b9c0 <_Z13iffLogGetNamePKc+0x70>
 *   @0x27b9b0 cmp r0, r2
 *   @0x27b9b4 beq 0x27b9fc <_Z13iffLogGetNamePKc+0xac>
 *   @0x27b9b8 cmp r5, r12
 *   @0x27b9bc blt 0x27b9f4 <_Z13iffLogGetNamePKc+0xa4>
 *   @0x27b9c0 add r3, r3, #1
 *   @0x27b9c4 add r12, r12, #1
 *   @0x27b9c8 and r3, r3, r1
 *   @0x27b9cc add r6, r3, r8
 *   @0x27b9d0 lsl r4, r3, #1
 *   @0x27b9d4 add r2, r4, r3
 *   @0x27b9d8 add r2, r7, r2, lsl #2
 *   @0x27b9dc ldr r2, [r2, #0x8]
 *   @0x27b9e0 and r5, r1, r2
 *   @0x27b9e4 cmp r2, #0
 *   @0x27b9e8 rsb r5, r5, r6
 *   @0x27b9ec and r5, r5, r1
 *   @0x27b9f0 bne 0x27b9b0 <_Z13iffLogGetNamePKc+0x60>
 *   @0x27b9f4 mvn r0, #0
 *   @0x27b9f8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x27b9fc cmn r3, #1
 *   @0x27ba00 beq 0x27ba1c <_Z13iffLogGetNamePKc+0xcc>
 *   @0x27ba04 add r3, r4, r3
 *   @0x27ba08 add r7, r7, r3, lsl #2
 *   @0x27ba0c cmn r7, #4
 *   @0x27ba10 beq 0x27b9f4 <_Z13iffLogGetNamePKc+0xa4>
 *   @0x27ba14 ldr r0, [r7, #0x4]
 *   @0x27ba18 pop {r4, r5, r6, r7, r8, pc}
 *   @0x27ba1c mov r0, r3
 *   @0x27ba20 pop {r4, r5, r6, r7, r8, pc}
 *   @0x27ba24 andseq r5, r7, r4, asr #29
 *
 * ══ §5/146 png_handle_pHYs  0x2acf58  size 216  54 条（0x2acf58..0x2ad030）
 * @func 0x2acf58 0x2ad030  size 216  54 条
 * 部分覆盖: 本节 54/98 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_error / png_warning / png_crc_finish / 0x6ec96c / 0x339024 / 0x371044 / 0x42c8d0
 * 字段偏移 top8: 0xc0×1 / 0x14×1 / 0xa4×1 / 0x90×1 / 0x7c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2acf58 ldr r3, [pc, #0xc0]
 *   @0x2acf5c add r3, pc
 *   @0x2acf60 mov r5, r2
 *   @0x2acf64 ldr r2, [r3]
 *   @0x2acf68 mov r6, r1
 *   @0x2acf6c str r2, [sp, #0x14]
 *   @0x2acf70 .word 0xf012212c
 *   @0x2acf74 .word 0xd1040f01
 *   @0x2acf78 ldr r1, [pc, #0xa4]
 *   @0x2acf7c bl 0x2a642c <png_error>
 *   @0x2acf80 b 0x2acfa6 <png_handle_pHYs+0x4e>
 *   @0x2acf84 bpl 0x2acf8c <png_handle_pHYs+0x34>
 *   @0x2acf88 add r1, pc
 *   @0x2acf8c cbz r1, 0x2acfa6 <png_handle_pHYs+0x4e>
 *   @0x2acf90 lsls r3, r2, #0x18
 *   @0x2acf94 ldr r1, [pc, #0x90]
 *   @0x2acf98 bl 0x2a6474 <png_warning>
 *   @0x2acf9c mov r0, r4
 *   @0x2acfa0 bl 0x2abc94 <png_crc_finish>
 *   @0x2acfa4 b 0x2ad00a <png_handle_pHYs+0xb2>
 *   @0x2acfa8 mov r0, r4
 *   @0x2acfac ldr r1, [pc, #0x7c]
 *   @0x2acfb0 b 0x2acf98 <png_handle_pHYs+0x40>
 *   @0x2acfb4 mov r2, r5
 *   @0x2acfb8 strtmi pc, [r0], -r9, lsr #28
 *   @0x2acfbc movs r1, #0x0
 *   @0x2acfc0 bllt 0x6ec96c <g_SWFvertbuff+0x198a4>
 *   @0x2acfc4 ldrb.w r2, [sp, #0x9]
 *   @0x2acfc8 mov r0, r4
 *   @0x2acfcc .word 0xf89d3008
 *   @0x2acfd0 ldreq r1, [r2], #-12
 *   @0x2acfd4 ldrb.w lr, [sp, #0xa]
 *   @0x2acfd8 add.w r2, r2, r3, lsl #24
 *   @0x2acfdc ldrb.w r3, [sp, #0xb]
 *   @0x2acfe0 ldrb.w r5, [sp, #0xe]
 *   @0x2acfe4 add r2, r3
 *   @0x2acfe8 bl 0x339024
 *   @0x2acfec ldreq r2, [r11], #-526
 *   @0x2acff0 add.w r3, r3, r1, lsl #24
 *   @0x2acff4 ldrb.w r1, [sp, #0xf]
 *   @0x2acff8 add r3, r1
 *   @0x2acffc bl 0x371044 <_ZTS13C_UTF16String+0x80f0>
 *   @0x2ad000 .word 0x91002305
 *   @0x2ad004 mov r1, r6
 *   @0x2ad008 bls 0x42c8d0 <g_RomDisk+0x350b0>
 *   @0x2ad00c ldr r3, [r7]
 *   @0x2ad010 beq 0x2ad016 <png_handle_pHYs+0xbe>
 *   @0x2ad014 andlt lr, r7, r0, ror #21
 *   @0x2ad018 pop {r4, r5, r6, r7, pc}
 *   @0x2ad01c lsrs r0, r7, #0x7
 *   @0x2ad020 lsls r3, r1, #0x13
 *   @0x2ad024 lsls r6, r2, #0x13
 *   @0x2ad028 lsls r0, r4, #0x13
 *   @0x2ad02c lsls r5, r3, #0x13
 *
 * ══ §6/146 jpeg_read_scanlines  0x2b35c0  size 216  54 条（0x2b35c0..0x2b3698）
 * @func 0x2b35c0 0x2b3698  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×4 / 0x14×3 / 0x78×3 / 0x8×2 / 0x18×1 / 0x60×1 / 0x184×1 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b35c0 ldr r12, [r0, #0x14]
 *   @0x2b35c4 push {r4, r5, r6, lr}
 *   @0x2b35c8 cmp r12, #205
 *   @0x2b35cc sub sp, sp, #8
 *   @0x2b35d0 mov r4, r0
 *   @0x2b35d4 mov r6, r1
 *   @0x2b35d8 mov r5, r2
 *   @0x2b35dc beq 0x2b35fc <jpeg_read_scanlines+0x3c>
 *   @0x2b35e0 ldr r3, [r0]
 *   @0x2b35e4 mov r1, #20
 *   @0x2b35e8 str r12, [r3, #0x18]
 *   @0x2b35ec ldr r2, [r0]
 *   @0x2b35f0 str r1, [r3, #0x14]
 *   @0x2b35f4 ldr r3, [r2]
 *   @0x2b35f8 blx r3
 *   @0x2b35fc ldr r0, [r4, #0x78]
 *   @0x2b3600 ldr lr, [r4, #0x60]
 *   @0x2b3604 cmp r0, lr
 *   @0x2b3608 bhs 0x2b3670 <jpeg_read_scanlines+0xb0>
 *   @0x2b360c ldr r12, [r4, #0x8]
 *   @0x2b3610 cmp r12, #0
 *   @0x2b3614 beq 0x2b362c <jpeg_read_scanlines+0x6c>
 *   @0x2b3618 str r0, [r12, #0x4]
 *   @0x2b361c mov r0, r4
 *   @0x2b3620 str lr, [r12, #0x8]
 *   @0x2b3624 ldr r3, [r12]
 *   @0x2b3628 blx r3
 *   @0x2b362c ldr lr, [r4, #0x184]
 *   @0x2b3630 add r12, sp, #8
 *   @0x2b3634 mov r3, r5
 *   @0x2b3638 mov r0, r4
 *   @0x2b363c mov r1, r6
 *   @0x2b3640 mov r2, #0
 *   @0x2b3644 str r2, [r12, #-0x4]!
 *   @0x2b3648 mov r2, r12
 *   @0x2b364c ldr r12, [lr, #0x4]
 *   @0x2b3650 blx r12
 *   @0x2b3654 ldr r3, [sp, #0x4]
 *   @0x2b3658 ldr r2, [r4, #0x78]
 *   @0x2b365c mov r0, r3
 *   @0x2b3660 add r3, r2, r3
 *   @0x2b3664 str r3, [r4, #0x78]
 *   @0x2b3668 add sp, sp, #8
 *   @0x2b366c pop {r4, r5, r6, pc}
 *   @0x2b3670 ldr r3, [r4]
 *   @0x2b3674 mov r0, r4
 *   @0x2b3678 mov r2, #123
 *   @0x2b367c mvn r1, #0
 *   @0x2b3680 str r2, [r3, #0x14]
 *   @0x2b3684 ldr r3, [r3, #0x4]
 *   @0x2b3688 blx r3
 *   @0x2b368c mov r0, #0
 *   @0x2b3690 add sp, sp, #8
 *   @0x2b3694 pop {r4, r5, r6, pc}
 *
 * ══ §7/146 DGifGetExtensionNext(GifFileType*, unsigned char**)  0x2c2270  size 216  54 条（0x2c2270..0x2c2348）
 * @func 0x2c2270 0x2c2348  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb68c8×2
 * 字段偏移 top8: 0x48×2 / 0x3c×2 / 0x7×2 / 0x38×2 / 0x44×1 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c2270 push {r4, r5, r6, lr}
 *   @0x2c2274 mov r4, r0
 *   @0x2c2278 ldr r5, [r0, #0x48]
 *   @0x2c227c sub sp, sp, #8
 *   @0x2c2280 mov r6, r1
 *   @0x2c2284 ldr r3, [r5, #0x3c]
 *   @0x2c2288 cmp r3, #0
 *   @0x2c228c beq 0x2c2310 <_Z20DGifGetExtensionNextP11GifFileTypePPh+0xa0>
 *   @0x2c2290 add r1, sp, #7
 *   @0x2c2294 mov r2, #1
 *   @0x2c2298 blx r3
 *   @0x2c229c subs r0, r0, #1
 *   @0x2c22a0 movne r0, #1
 *   @0x2c22a4 cmp r0, #0
 *   @0x2c22a8 bne 0x2c22fc <_Z20DGifGetExtensionNextP11GifFileTypePPh+0x8c>
 *   @0x2c22ac ldrb r2, [sp, #0x7]
 *   @0x2c22b0 cmp r2, #0
 *   @0x2c22b4 streq r0, [r6]
 *   @0x2c22b8 moveq r0, #1
 *   @0x2c22bc beq 0x2c2308 <_Z20DGifGetExtensionNextP11GifFileTypePPh+0x98>
 *   @0x2c22c0 add r3, r5, #68
 *   @0x2c22c4 str r3, [r6]
 *   @0x2c22c8 strb r2, [r5, #0x44]
 *   @0x2c22cc ldr r1, [r4, #0x48]
 *   @0x2c22d0 ldr r3, [r1, #0x3c]
 *   @0x2c22d4 cmp r3, #0
 *   @0x2c22d8 beq 0x2c2330 <_Z20DGifGetExtensionNextP11GifFileTypePPh+0xc0>
 *   @0x2c22dc ldr r1, [r6]
 *   @0x2c22e0 mov r0, r4
 *   @0x2c22e4 add r1, r1, #1
 *   @0x2c22e8 blx r3
 *   @0x2c22ec ldrb r3, [sp, #0x7]
 *   @0x2c22f0 cmp r0, r3
 *   @0x2c22f4 moveq r0, #1
 *   @0x2c22f8 beq 0x2c2308 <_Z20DGifGetExtensionNextP11GifFileTypePPh+0x98>
 *   @0x2c22fc mov r0, #0
 *   @0x2c2300 mov r3, #102
 *   @0x2c2304 str r3, [r4, #0x40]
 *   @0x2c2308 add sp, sp, #8
 *   @0x2c230c pop {r4, r5, r6, pc}
 *   @0x2c2310 mov r1, #1
 *   @0x2c2314 add r0, sp, #7
 *   @0x2c2318 mov r2, r1
 *   @0x2c231c ldr r3, [r5, #0x38]
 *   @0x2c2320 bl 0xb68c8 <fread@plt>
 *   @0x2c2324 subs r0, r0, #1
 *   @0x2c2328 movne r0, #1
 *   @0x2c232c b 0x2c22a4 <_Z20DGifGetExtensionNextP11GifFileTypePPh+0x34>
 *   @0x2c2330 ldr r0, [r6]
 *   @0x2c2334 ldr r3, [r1, #0x38]
 *   @0x2c2338 mov r1, #1
 *   @0x2c233c add r0, r0, r1
 *   @0x2c2340 bl 0xb68c8 <fread@plt>
 *   @0x2c2344 b 0x2c22ec <_Z20DGifGetExtensionNextP11GifFileTypePPh+0x7c>
 *
 * ══ §8/146 b2PolygonShape::Clone(b2BlockAllocator*) const  0x2c5bd0  size 216  54 条（0x2c5bd0..0x2c5ca8）
 * @func 0x2c5bd0 0x2c5ca8  size 216  54 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2BlockAllocator::Allocate(int)
 * 字段偏移 top8: 0x4×3 / 0x8×3 / 0x94×3 / 0xb0×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c5bd0 push {r4, r5, r6, r7, r8, lr}
 *   @0x2c5bd4 mov r8, r0
 *   @0x2c5bd8 mov r0, r1
 *   @0x2c5bdc mov r1, #152
 *   @0x2c5be0 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2c5be4 subs r7, r0, #0
 *   @0x2c5be8 beq 0x2c5c24 <_ZNK14b2PolygonShape5CloneEP16b2BlockAllocator+0x54>
 *   @0x2c5bec ldr r3, [pc, #0xb0]
 *   @0x2c5bf0 mov r2, #2
 *   @0x2c5bf4 movw r1, #0xd70a
 *   @0x2c5bf8 str r2, [r7, #0x4]
 *   @0x2c5bfc ldr r3, [pc, r3]
 *   @0x2c5c00 movt r1, #0x3c23
 *   @0x2c5c04 add r3, r3, #8
 *   @0x2c5c08 mov r2, #0
 *   @0x2c5c0c str r3, [r7]
 *   @0x2c5c10 mov r3, #0
 *   @0x2c5c14 str r1, [r7, #0x8]
 *   @0x2c5c18 str r2, [r7, #0x94]
 *   @0x2c5c1c str r3, [r7, #0xc]
 *   @0x2c5c20 str r3, [r7, #0x10]
 *   @0x2c5c24 add r2, r8, #12
 *   @0x2c5c28 ldr r12, [r8, #0x4]
 *   @0x2c5c2c add r3, r7, #12
 *   @0x2c5c30 add r6, r8, #20
 *   @0x2c5c34 ldm r2, {r0, r1}
 *   @0x2c5c38 add r5, r7, #20
 *   @0x2c5c3c ldr r2, [r8, #0x8]
 *   @0x2c5c40 add r4, r8, #84
 *   @0x2c5c44 str r12, [r7, #0x4]
 *   @0x2c5c48 add r12, r7, #84
 *   @0x2c5c4c str r2, [r7, #0x8]
 *   @0x2c5c50 stm r3, {r0, r1}
 *   @0x2c5c54 ldm r6!, {r0, r1, r2, r3}
 *   @0x2c5c58 stm r5!, {r0, r1, r2, r3}
 *   @0x2c5c5c ldm r6!, {r0, r1, r2, r3}
 *   @0x2c5c60 stm r5!, {r0, r1, r2, r3}
 *   @0x2c5c64 ldm r6!, {r0, r1, r2, r3}
 *   @0x2c5c68 stm r5!, {r0, r1, r2, r3}
 *   @0x2c5c6c ldm r6, {r0, r1, r2, r3}
 *   @0x2c5c70 stm r5, {r0, r1, r2, r3}
 *   @0x2c5c74 ldm r4!, {r0, r1, r2, r3}
 *   @0x2c5c78 stm r12!, {r0, r1, r2, r3}
 *   @0x2c5c7c ldm r4!, {r0, r1, r2, r3}
 *   @0x2c5c80 stm r12!, {r0, r1, r2, r3}
 *   @0x2c5c84 ldm r4!, {r0, r1, r2, r3}
 *   @0x2c5c88 stm r12!, {r0, r1, r2, r3}
 *   @0x2c5c8c ldm r4, {r0, r1, r2, r3}
 *   @0x2c5c90 stm r12, {r0, r1, r2, r3}
 *   @0x2c5c94 mov r0, r7
 *   @0x2c5c98 ldr r3, [r8, #0x94]
 *   @0x2c5c9c str r3, [r7, #0x94]
 *   @0x2c5ca0 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2c5ca4 ldrheq r11, [r2], -r4
 *
 * ══ §9/146 png_do_quantize  0x2aa854  size 214  54 条（0x2aa854..0x2aa92a）
 * @func 0x2aa854 0x2aa92c  size 216  54 条
 * 部分覆盖: 本节 54/101 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_do_quantize+0x54
 * 字段偏移 top8: 0x1×3 / 0x-3×1 / 0x8×1 / 0xa×1 / 0x-4×1 / 0x-2×1 / 0x9×1 / 0xb×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2aa854 push {r4, r5, r6, r7, lr}
 *   @0x2aa858 ldr r4, [r0]
 *   @0x2aa85c bne 0x2aa8b2 <png_do_quantize+0x5e>
 *   @0x2aa860 beq 0x2aa928 <png_do_quantize+0xd4>
 *   @0x2aa864 cmp r3, #0x8
 *   @0x2aa868 adds r5, r1, r4
 *   @0x2aa86c cmp r1, r5
 *   @0x2aa870 ldrb r6, [r3, #0x1]
 *   @0x2aa874 ldrb r7, [r3, #-3]
 *   @0x2aa878 asrs r6, r6, #0x3
 *   @0x2aa87c lsls r6, r6, #0x5
 *   @0x2aa880 .word 0xf8132687
 *   @0x2aa884 b 0x1449890 <b2_toiTime+0xcf03ec>
 *   @0x2aa888 ldcpl p6, c0, [r6, #860]
 *   @0x2aa88c strb r6, [r1], #1
 *   @0x2aa890 b 0x2aa86c <png_do_quantize+0x18>
 *   @0x2aa894 strb r3, [r0, #0x8]
 *   @0x2aa898 strb r3, [r0, #0xa]
 *   @0x2aa89c cmp r3, #0x7
 *   @0x2aa8a0 bls 0x2aa8a8 <png_do_quantize+0x54>
 *   @0x2aa8a4 muls r4, r3, r4
 *   @0x2aa8a8 muls r4, r3, r4
 *   @0x2aa8ac lsrs r4, r4, #0x3
 *   @0x2aa8b0 pop {r4, r5, r6, r7, pc}
 *   @0x2aa8b4 bne 0x2aa90c <png_do_quantize+0xb8>
 *   @0x2aa8b8 beq 0x2aa928 <png_do_quantize+0xd4>
 *   @0x2aa8bc cmp r3, #0x8
 *   @0x2aa8c0 mov r5, r1
 *   @0x2aa8c4 cmp r3, r4
 *   @0x2aa8c8 ldrb r6, [r5, #0x1]
 *   @0x2aa8cc ldrb r12, [r5, #-4]
 *   @0x2aa8d0 ldrb r7, [r5, #-2]
 *   @0x2aa8d4 asrs r6, r6, #0x3
 *   @0x2aa8d8 cmneq r6, r12, ror #25
 *   @0x2aa8dc orr.w r6, r6, r12, lsl #10
 *   @0x2aa8e0 orr.w r6, r6, r7, lsr #3
 *   @0x2aa8e4 ldrb r6, [r2, r6]
 *   @0x2aa8e8 adds r3, #0x1
 *   @0x2aa8ec movs r2, #0x3
 *   @0x2aa8f0 movs r2, #0x1
 *   @0x2aa8f4 ldrb r2, [r0, #0x9]
 *   @0x2aa8f8 strb r2, [r0, #0xb]
 *   @0x2aa8fc lsrs r2, r2, #0x3
 *   @0x2aa900 b 0x2aa908 <png_do_quantize+0xb4>
 *   @0x2aa904 adds r3, #0x7
 *   @0x2aa908 str r3, [r0, #0x4]
 *   @0x2aa90c cmp r5, #0x3
 *   @0x2aa910 cbz r3, 0x2aa928 <png_do_quantize+0xd4>
 *   @0x2aa914 cmp r2, #0x8
 *   @0x2aa918 add r4, r1
 *   @0x2aa91c beq 0x2aa928 <png_do_quantize+0xd4>
 *   @0x2aa920 ldrb r2, [r3, r2]
 *   @0x2aa924 ldrb r2, [r8, r1, lsl #22]!
 *   @0x2aa928 pop {r4, r5, r6, r7, pc}
 *
 * ══ §10/146 png_do_pack  0x2b09fe  size 214  54 条（0x2b09fe..0x2b0ad4）
 * @func 0x2b09fe 0x2b0ad6  size 216  54 条
 * 部分覆盖: 本节 54/97 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x5b3ad6 / png_do_pack+0xcc
 * 字段偏移 top8: 0x8×1 / 0x1×1 / 0x9×1 / 0xb×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b09fe ldr r3, [r0, #0x8]
 *   @0x2b0a02 bic r3, r3, #0xff000000
 *   @0x2b0a06 bic r3, r3, #0xff
 *   @0x2b0a0a cmp.w r3, #0x10800
 *   @0x2b0a0e bne 0x2b0ad2 <png_do_pack+0xd4>
 *   @0x2b0a12 ldr r6, [r0]
 *   @0x2b0a16 cmp r2, #0x4
 *   @0x2b0a1a cmp r2, #0x1
 *   @0x2b0a1e movs r5, #0x0
 *   @0x2b0a22 mov r4, r5
 *   @0x2b0a26 cmp r5, r6
 *   @0x2b0a2a ldrb.w r12, [r1, r5]
 *   @0x2b0a2e cmp.w r12, #0x0
 *   @0x2b0a32 beq 0x2b0a36 <png_do_pack+0x38>
 *   @0x2b0a36 cmp r3, #0x1
 *   @0x2b0a3a svclt #0xd70501
 *   @0x2b0a3e strble r4, [r7], #1
 *   @0x2b0a42 asrgt r3, r3, #0x1
 *   @0x2b0a46 movle r3, #0x80
 *   @0x2b0a4a cmp r3, #0x80
 *   @0x2b0a4e movs r5, #0x0
 *   @0x2b0a52 mov r4, r5
 *   @0x2b0a56 cmp r5, r6
 *   @0x2b0a5a ldrb.w r12, [r1, r5]
 *   @0x2b0a5e and r12, r12, #0x3
 *   @0x2b0a62 lsl.w r12, r12, r3
 *   @0x2b0a66 orr.w r4, r4, r12
 *   @0x2b0a6a cbnz r3, 0x2b0a76 <png_do_pack+0x78>
 *   @0x2b0a6e ldrmi r4, [r12], -r1, lsl #22
 *   @0x2b0a72 movs r3, #0x6
 *   @0x2b0a76 subs r3, #0x2
 *   @0x2b0a7a b 0x2b0a56 <png_do_pack+0x58>
 *   @0x2b0a7e b 0x2b0ab0 <png_do_pack+0xb2>
 *   @0x2b0a82 mov r7, r1
 *   @0x2b0a86 mov r3, r2
 *   @0x2b0a8a beq 0x2b0aae <png_do_pack+0xb0>
 *   @0x2b0a8e .word 0xf00cc005
 *   @0x2b0a92 blx 0x5b3ad6 <g_SWFlineaavertbuff+0x60a0e>
 *   @0x2b0a96 b 0x13efaaa <b2_toiTime+0xc96606>
 *   @0x2b0a9a stmdblt r3!, {r2, r3, r10}
 *   @0x2b0a9e strb r4, [r7], #1
 *   @0x2b0aa2 mov r4, r3
 *   @0x2b0aa6 b 0x2b0aaa <png_do_pack+0xac>
 *   @0x2b0aaa adds r5, #0x1
 *   @0x2b0aae cmp r3, #0x4
 *   @0x2b0ab2 strbne r4, [r7]
 *   @0x2b0ab6 strb r2, [r0, #0x9]
 *   @0x2b0aba ldr r3, [r0]
 *   @0x2b0abe strb r2, [r0, #0xb]
 *   @0x2b0ac2 bls 0x2b0aca <png_do_pack+0xcc>
 *   @0x2b0ac6 muls r2, r3, r2
 *   @0x2b0aca muls r2, r3, r2
 *   @0x2b0ace lsrs r2, r2, #0x3
 *   @0x2b0ad2 pop {r4, r5, r6, r7, pc}
 *
 * ══ §11/146 CSkeletonInstance::GetBoundingBoxAttachment(int, char const**, int*, float*)  0xbef04  size 212  53 条（0xbef04..0xbefd8）
 * @func 0xbef04 0xbefd8  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSkeletonInstance::GetBoundingBoxAttachment(int, char const**, int*, float*)+0xc4 / spSkeleton_updateWorldTransform / spSkeletonBounds_update / CSkeletonInstance::GetBoundingBoxAttachment(int, char const**, int*, float*)+0xbc
 * 字段偏移 top8: 0x4×4 / 0x20×3 / 0x1c×2 / 0x10×2 / 0x2×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbef04 push {r4, r5, r6, lr}
 *   @0xbef08 mov r4, r0
 *   @0xbef0c ldr r0, [r0, #0x20]
 *   @0xbef10 mov r5, r3
 *   @0xbef14 cmp r0, #0
 *   @0xbef18 popeq {r4, r5, r6, pc}
 *   @0xbef1c cmp r1, #0
 *   @0xbef20 blt 0xbefc8 <_ZN17CSkeletonInstance24GetBoundingBoxAttachmentEiPPKcPiPf+0xc4>
 *   @0xbef24 ldr r3, [r0]
 *   @0xbef28 cmp r1, r3
 *   @0xbef2c bge 0xbefc8 <_ZN17CSkeletonInstance24GetBoundingBoxAttachmentEiPPKcPiPf+0xc4>
 *   @0xbef30 cmp r2, #0
 *   @0xbef34 beq 0xbefd0 <_ZN17CSkeletonInstance24GetBoundingBoxAttachmentEiPPKcPiPf+0xcc>
 *   @0xbef38 ldr r3, [r0, #0x4]
 *   @0xbef3c cmp r3, #0
 *   @0xbef40 beq 0xbefd0 <_ZN17CSkeletonInstance24GetBoundingBoxAttachmentEiPPKcPiPf+0xcc>
 *   @0xbef44 ldr r3, [r3, r1, lsl #2]
 *   @0xbef48 lsl r6, r1, #2
 *   @0xbef4c ldr r3, [r3]
 *   @0xbef50 str r3, [r2]
 *   @0xbef54 ldr r0, [r4, #0x1c]
 *   @0xbef58 bl 0x289ee4 <spSkeleton_updateWorldTransform>
 *   @0xbef5c mov r2, #1
 *   @0xbef60 ldr r0, [r4, #0x20]
 *   @0xbef64 ldr r1, [r4, #0x1c]
 *   @0xbef68 bl 0x28a8b4 <spSkeletonBounds_update>
 *   @0xbef6c ldr r3, [r4, #0x20]
 *   @0xbef70 cmp r5, #0
 *   @0xbef74 ldr r3, [r3, #0x8]
 *   @0xbef78 ldr r3, [r3, r6]
 *   @0xbef7c ldrne r2, [r3, #0x4]
 *   @0xbef80 addne r2, r2, r2, lsr #31
 *   @0xbef84 asrne r2, r2, #1
 *   @0xbef88 strne r2, [r5]
 *   @0xbef8c ldr r2, [sp, #0x10]
 *   @0xbef90 cmp r2, #0
 *   @0xbef94 beq 0xbefc0 <_ZN17CSkeletonInstance24GetBoundingBoxAttachmentEiPPKcPiPf+0xbc>
 *   @0xbef98 ldr r0, [r3, #0x4]
 *   @0xbef9c cmp r0, #0
 *   @0xbefa0 ble 0xbefc0 <_ZN17CSkeletonInstance24GetBoundingBoxAttachmentEiPPKcPiPf+0xbc>
 *   @0xbefa4 ldr r3, [r3]
 *   @0xbefa8 ldr r2, [sp, #0x10]
 *   @0xbefac add r0, r3, r0, lsl #2
 *   @0xbefb0 ldr r1, [r3], #4
 *   @0xbefb4 cmp r3, r0
 *   @0xbefb8 str r1, [r2], #4
 *   @0xbefbc bne 0xbefb0 <_ZN17CSkeletonInstance24GetBoundingBoxAttachmentEiPPKcPiPf+0xac>
 *   @0xbefc0 mov r0, #1
 *   @0xbefc4 pop {r4, r5, r6, pc}
 *   @0xbefc8 mov r0, #0
 *   @0xbefcc pop {r4, r5, r6, pc}
 *   @0xbefd0 lsl r6, r1, #2
 *   @0xbefd4 b 0xbef54 <_ZN17CSkeletonInstance24GetBoundingBoxAttachmentEiPPKcPiPf+0x50>
 *
 * ══ §12/146 TRelConsole::Output(char const*, ...)  0xc4890  size 212  53 条（0xc4890..0xc4964）
 * @func 0xc4890 0xc4964  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6610 / Debug_BufferOutput(char const*) / 0xb661c / 0xb65d4
 * 字段偏移 top8: 0xac×2 / 0x-ffc×2 / 0x-fe4×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc4890 push {r1, r2, r3}
 *   @0xc4894 movw r1, #0xeff8
 *   @0xc4898 push {r4, r5, r6, lr}
 *   @0xc489c sub sp, sp, #4096
 *   @0xc48a0 sub sp, sp, #12
 *   @0xc48a4 ldr r2, [pc, #0xac]
 *   @0xc48a8 ldr r4, [pc, #0xac]
 *   @0xc48ac add r0, sp, #4096
 *   @0xc48b0 movt r1, #0xffff
 *   @0xc48b4 ldr r2, [pc, r2]
 *   @0xc48b8 add r0, r0, #8
 *   @0xc48bc add r3, sp, #4096
 *   @0xc48c0 ldr r4, [pc, r4]
 *   @0xc48c4 add r3, r3, #32
 *   @0xc48c8 str r3, [r0, r1]
 *   @0xc48cc ldrb r1, [r2]
 *   @0xc48d0 ldr r2, [r4]
 *   @0xc48d4 cmp r1, #0
 *   @0xc48d8 add r1, sp, #8192
 *   @0xc48dc ldr r5, [r1, #-0xfe4]
 *   @0xc48e0 str r2, [r1, #-0xffc]
 *   @0xc48e4 beq 0xc4904 <_ZN11TRelConsole6OutputEPKcz+0x74>
 *   @0xc48e8 add r6, sp, #4
 *   @0xc48ec mov r1, #4096
 *   @0xc48f0 mov r2, r5
 *   @0xc48f4 mov r0, r6
 *   @0xc48f8 bl 0xb6610 <vsnprintf@plt>
 *   @0xc48fc mov r0, r6
 *   @0xc4900 bl 0x29bfcc <_Z18Debug_BufferOutputPKc>
 *   @0xc4904 add r1, sp, #4096
 *   @0xc4908 movw r3, #0xeff8
 *   @0xc490c add r1, r1, #8
 *   @0xc4910 movt r3, #0xffff
 *   @0xc4914 mov r2, r5
 *   @0xc4918 mov r0, #4
 *   @0xc491c ldr r3, [r1, r3]
 *   @0xc4920 ldr r1, [pc, #0x38]
 *   @0xc4924 add r1, pc, r1
 *   @0xc4928 bl 0xb661c <__android_log_vprint@plt>
 *   @0xc492c add r3, sp, #8192
 *   @0xc4930 ldr r2, [r3, #-0xffc]
 *   @0xc4934 ldr r3, [r4]
 *   @0xc4938 cmp r2, r3
 *   @0xc493c bne 0xc4954 <_ZN11TRelConsole6OutputEPKcz+0xc4>
 *   @0xc4940 add sp, sp, #4096
 *   @0xc4944 add sp, sp, #12
 *   @0xc4948 pop {r4, r5, r6, lr}
 *   @0xc494c add sp, sp, #12
 *   @0xc4950 bx lr
 *   @0xc4954 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0xc4958 eorseq r9, r2, r8, asr #1
 *   @0xc495c mlaseq r2, r0, r0, r9
 *   @0xc4960 eoreq r12, r6, r0, lsl r2
 *
 * ══ §13/146 F_BUFFER_Read(RValue&, CInstance*, CInstance*, int, RValue*)  0xc53d8  size 212  53 条（0xc53d8..0xc54ac）
 * @func 0xc53d8 0xc54ac  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / F_BUFFER_Read(RValue&, CInstance*, CInstance*, int, RValue*)+0xb4 / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x4×3 / 0xc×2 / 0x18×1 / 0x90×1 / 0x2×1 / 0x2c×1 / 0x14×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc53d8 push {r3, r4, r5, r6, r7, lr}
 *   @0xc53dc mov r6, #0
 *   @0xc53e0 ldr r4, [sp, #0x18]
 *   @0xc53e4 mov r7, r0
 *   @0xc53e8 str r6, [r0, #0xc]
 *   @0xc53ec mov r1, r6
 *   @0xc53f0 str r6, [r0]
 *   @0xc53f4 str r6, [r0, #0x4]
 *   @0xc53f8 mov r0, r4
 *   @0xc53fc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc5400 cmp r0, #0
 *   @0xc5404 blt 0xc548c <_Z13F_BUFFER_ReadR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0xc5408 ldr r2, [pc, #0x90]
 *   @0xc540c add r2, pc, r2
 *   @0xc5410 ldr r1, [r2]
 *   @0xc5414 cmp r0, r1
 *   @0xc5418 bge 0xc548c <_Z13F_BUFFER_ReadR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0xc541c ldr r2, [r2, #0x4]
 *   @0xc5420 ldr r5, [r2, r0, lsl #2]
 *   @0xc5424 cmp r5, r6
 *   @0xc5428 beq 0xc548c <_Z13F_BUFFER_ReadR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0xc542c ldr r3, [r5]
 *   @0xc5430 mov r0, r4
 *   @0xc5434 mov r1, #1
 *   @0xc5438 ldr r4, [r3, #0xc]
 *   @0xc543c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc5440 mov r2, r7
 *   @0xc5444 mov r1, r0
 *   @0xc5448 mov r0, r5
 *   @0xc544c blx r4
 *   @0xc5450 cmp r0, #0
 *   @0xc5454 popge {r3, r4, r5, r6, r7, pc}
 *   @0xc5458 vmov.f64 d7, #-3.000000e+00
 *   @0xc545c ldm r7, {r4, r5}
 *   @0xc5460 vmov d6, r4, r5
 *   @0xc5464 vcmp.f64 d6, d7
 *   @0xc5468 vmrs APSR_nzcv, fpscr
 *   @0xc546c popne {r3, r4, r5, r6, r7, pc}
 *   @0xc5470 ldr r0, [pc, #0x2c]
 *   @0xc5474 mov r1, r6
 *   @0xc5478 add r0, pc, r0
 *   @0xc547c bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc5480 str r6, [r7]
 *   @0xc5484 str r6, [r7, #0x4]
 *   @0xc5488 pop {r3, r4, r5, r6, r7, pc}
 *   @0xc548c ldr r0, [pc, #0x14]
 *   @0xc5490 mov r1, #0
 *   @0xc5494 pop {r3, r4, r5, r6, r7, lr}
 *   @0xc5498 add r0, pc, r0
 *   @0xc549c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc54a0 eorseq r4, r11, r8, lsl #26
 *   @0xc54a4 eoreq r11, r6, r4, asr r7
 *   @0xc54a8 eoreq r11, r6, r12, lsl r7
 *
 * ══ §14/146 F_BUFFER_Async_Group_Begin(RValue&, CInstance*, CInstance*, int, RValue*)  0xc5e24  size 212  53 条（0xc5e24..0xc5ef8）
 * @func 0xc5e24 0xc5ef8  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6634×6 / YYGetString(RValue const*, int) / YYStrDup(char const*)
 * 字段偏移 top8: 0xbc×1 / 0x10×1 / 0xa8×1 / 0x84×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc5e24 push {r3, r4, r5, lr}
 *   @0xc5e28 ldr r4, [pc, #0xbc]
 *   @0xc5e2c ldr r0, [sp, #0x10]
 *   @0xc5e30 ldr r4, [pc, r4]
 *   @0xc5e34 ldr r1, [r4]
 *   @0xc5e38 cmp r1, #0
 *   @0xc5e3c beq 0xc5e50 <_Z26F_BUFFER_Async_Group_BeginR6RValueP9CInstanceS2_iPS_+0x2c>
 *   @0xc5e40 ldr r0, [pc, #0xa8]
 *   @0xc5e44 pop {r3, r4, r5, lr}
 *   @0xc5e48 add r0, pc, r0
 *   @0xc5e4c b 0xd547c <_Z7YYErrorPKcz>
 *   @0xc5e50 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0xc5e54 mov r1, #32
 *   @0xc5e58 mov r5, r0
 *   @0xc5e5c bl 0xb6634 <strchr@plt>
 *   @0xc5e60 cmp r0, #0
 *   @0xc5e64 beq 0xc5e78 <_Z26F_BUFFER_Async_Group_BeginR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0xc5e68 ldr r0, [pc, #0x84]
 *   @0xc5e6c pop {r3, r4, r5, lr}
 *   @0xc5e70 add r0, pc, r0
 *   @0xc5e74 b 0xd547c <_Z7YYErrorPKcz>
 *   @0xc5e78 mov r0, r5
 *   @0xc5e7c mov r1, #9
 *   @0xc5e80 bl 0xb6634 <strchr@plt>
 *   @0xc5e84 cmp r0, #0
 *   @0xc5e88 bne 0xc5e68 <_Z26F_BUFFER_Async_Group_BeginR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0xc5e8c mov r0, r5
 *   @0xc5e90 mov r1, #13
 *   @0xc5e94 bl 0xb6634 <strchr@plt>
 *   @0xc5e98 cmp r0, #0
 *   @0xc5e9c bne 0xc5e68 <_Z26F_BUFFER_Async_Group_BeginR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0xc5ea0 mov r0, r5
 *   @0xc5ea4 mov r1, #10
 *   @0xc5ea8 bl 0xb6634 <strchr@plt>
 *   @0xc5eac cmp r0, #0
 *   @0xc5eb0 bne 0xc5e68 <_Z26F_BUFFER_Async_Group_BeginR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0xc5eb4 mov r0, r5
 *   @0xc5eb8 mov r1, #92
 *   @0xc5ebc bl 0xb6634 <strchr@plt>
 *   @0xc5ec0 cmp r0, #0
 *   @0xc5ec4 bne 0xc5e68 <_Z26F_BUFFER_Async_Group_BeginR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0xc5ec8 mov r0, r5
 *   @0xc5ecc mov r1, #47
 *   @0xc5ed0 bl 0xb6634 <strchr@plt>
 *   @0xc5ed4 cmp r0, #0
 *   @0xc5ed8 bne 0xc5e68 <_Z26F_BUFFER_Async_Group_BeginR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0xc5edc mov r0, r5
 *   @0xc5ee0 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xc5ee4 str r0, [r4]
 *   @0xc5ee8 pop {r3, r4, r5, pc}
 *   @0xc5eec eorseq r7, r2, r8, lsl #23
 *   @0xc5ef0 eoreq r10, r6, r12, lsl #28
 *   @0xc5ef4 eoreq r10, r6, r4, lsl #28
 *
 * ══ §15/146 F_BUFFER_Load(RValue&, CInstance*, CInstance*, int, RValue*)  0xc6878  size 212  53 条（0xc6878..0xc694c）
 * @func 0xc6878 0xc694c  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int) / IBuffer::IBuffer() / YYGetString(RValue const*, int) / IBuffer::Load(char const*, int, int, int) / AllocBuffer()
 * 字段偏移 top8: 0x4×3 / 0xc×1 / 0x20×1 / 0x88×1 / 0x40×1 / 0x28×1 / 0x2×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc6878 push {r4, r5, r6, r7, lr}
 *   @0xc687c mov r3, #0
 *   @0xc6880 sub sp, sp, #12
 *   @0xc6884 mov r5, r0
 *   @0xc6888 mov r4, r3
 *   @0xc688c movt r3, #0xbff0
 *   @0xc6890 str r4, [r0, #0xc]
 *   @0xc6894 mov r0, #64
 *   @0xc6898 str r3, [r5, #0x4]
 *   @0xc689c str r4, [r5]
 *   @0xc68a0 ldr r7, [sp, #0x20]
 *   @0xc68a4 bl 0x27c524 <_Znwj>
 *   @0xc68a8 mov r6, r0
 *   @0xc68ac bl 0xcc900 <_ZN7IBufferC2Ev>
 *   @0xc68b0 ldr r3, [pc, #0x88]
 *   @0xc68b4 mov r1, r4
 *   @0xc68b8 mov r0, r7
 *   @0xc68bc ldr r3, [pc, r3]
 *   @0xc68c0 add r3, r3, #8
 *   @0xc68c4 str r3, [r6]
 *   @0xc68c8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0xc68cc str r4, [sp]
 *   @0xc68d0 mov r2, r4
 *   @0xc68d4 mvn r3, #0
 *   @0xc68d8 mov r1, r0
 *   @0xc68dc mov r0, r6
 *   @0xc68e0 bl 0xcd91c <_ZN7IBuffer4LoadEPKciii>
 *   @0xc68e4 subs r4, r0, #0
 *   @0xc68e8 bne 0xc6914 <_Z13F_BUFFER_LoadR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0xc68ec ldr r3, [r6]
 *   @0xc68f0 mov r0, r6
 *   @0xc68f4 ldr r3, [r3, #0x4]
 *   @0xc68f8 blx r3
 *   @0xc68fc ldr r0, [pc, #0x40]
 *   @0xc6900 mov r1, r4
 *   @0xc6904 add r0, pc, r0
 *   @0xc6908 add sp, sp, #12
 *   @0xc690c pop {r4, r5, r6, r7, lr}
 *   @0xc6910 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc6914 bl 0xc67b0 <_Z11AllocBufferv>
 *   @0xc6918 ldr r1, [pc, #0x28]
 *   @0xc691c add r1, pc, r1
 *   @0xc6920 ldr r1, [r1, #0x4]
 *   @0xc6924 vmov s15, r0
 *   @0xc6928 str r6, [r1, r0, lsl #2]
 *   @0xc692c vcvt.f64.s32 d7, s15
 *   @0xc6930 vmov r2, r3, d7
 *   @0xc6934 stm r5, {r2, r3}
 *   @0xc6938 add sp, sp, #12
 *   @0xc693c pop {r4, r5, r6, r7, pc}
 *   @0xc6940 ldrshteq r7, [r2], -r4
 *   @0xc6944 eoreq r10, r6, r0, ror #14
 *   @0xc6948 ldrshteq r3, [r11], -r8
 *
 * ══ §16/146 ResetObjectGCList()  0xd3b48  size 212  53 条（0xd3b48..0xd3c1c）
 * @func 0xd3b48 0xd3c1c  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xd3b4c→0x47f270, 0xd3b68→0x47f274, 0xd3b7c→0x536f1c, 0xd3b9c→0x47f258, 0xd3bb0→0x47f254, 0xd3bc4→0x536d84, 0xd3be4→0x47f26c
 * 调用序列: 无
 * 字段偏移 top8: 0xac×2 / 0x94×1 / 0x84×1 / 0x8×1 / 0x68×1 / 0x58×1 / 0x48×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd3b48 ldr r3, [pc, #0xac]
 *   @0xd3b4c ldr r2, [pc, #0xac]
 *   @0xd3b50 add r3, pc, r3
 *   @0xd3b54 push {r4, r5, r6}
 *   @0xd3b58 ldr r1, [r3, r2]
 *   @0xd3b5c ldr r2, [r1]
 *   @0xd3b60 cmp r2, #0
 *   @0xd3b64 beq 0xd3b9c <_Z17ResetObjectGCListv+0x54>
 *   @0xd3b68 ldr r0, [pc, #0x94]
 *   @0xd3b6c ldr r12, [r3, r0]
 *   @0xd3b70 ldr r0, [r12]
 *   @0xd3b74 cmp r0, #0
 *   @0xd3b78 beq 0xd3b9c <_Z17ResetObjectGCListv+0x54>
 *   @0xd3b7c ldr r4, [pc, #0x84]
 *   @0xd3b80 mov r5, #0
 *   @0xd3b84 ldr r4, [r3, r4]
 *   @0xd3b88 str r5, [r1]
 *   @0xd3b8c str r5, [r12]
 *   @0xd3b90 ldr r1, [r4]
 *   @0xd3b94 str r0, [r4]
 *   @0xd3b98 str r1, [r2, #0x8]
 *   @0xd3b9c ldr r2, [pc, #0x68]
 *   @0xd3ba0 ldr r2, [r3, r2]
 *   @0xd3ba4 ldr r1, [r2]
 *   @0xd3ba8 cmp r1, #0
 *   @0xd3bac beq 0xd3be4 <_Z17ResetObjectGCListv+0x9c>
 *   @0xd3bb0 ldr r0, [pc, #0x58]
 *   @0xd3bb4 ldr r0, [r3, r0]
 *   @0xd3bb8 ldr r12, [r0]
 *   @0xd3bbc cmp r12, #0
 *   @0xd3bc0 beq 0xd3be4 <_Z17ResetObjectGCListv+0x9c>
 *   @0xd3bc4 ldr r5, [pc, #0x48]
 *   @0xd3bc8 mov r4, #0
 *   @0xd3bcc ldr r5, [r3, r5]
 *   @0xd3bd0 ldr r6, [r5]
 *   @0xd3bd4 str r6, [r12]
 *   @0xd3bd8 str r1, [r5]
 *   @0xd3bdc str r4, [r2]
 *   @0xd3be0 str r4, [r0]
 *   @0xd3be4 ldr r1, [pc, #0x2c]
 *   @0xd3be8 mov r2, #0
 *   @0xd3bec pop {r4, r5, r6}
 *   @0xd3bf0 ldr r3, [r3, r1]
 *   @0xd3bf4 str r2, [r3]
 *   @0xd3bf8 bx lr
 *   @0xd3bfc eorseq lr, r1, r0, lsl #2
 *   @0xd3c00 .word 0xffffbfa0
 *   @0xd3c04 .word 0xffffbf9c
 *   @0xd3c08 .word 0xffffbfc0
 *   @0xd3c0c .word 0xffffbf90
 *   @0xd3c10 .word 0xffffbf88
 *   @0xd3c14 .word 0xffffbfc4
 *   @0xd3c18 .word 0xffffbf84
 *
 * ══ §17/146 VM::GetDSQueue(Buffer_Standard*, int, int)  0xdb2dc  size 212  53 条（0xdb2dc..0xdb3b0）
 * @func 0xdb2dc 0xdb3b0  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetTheQueues(int&) / VM::GetDSQueue(Buffer_Standard*, int, int)+0x94 / VM::WriteDSSizeCount(Buffer_Standard*, int, int&) / VM::GetDSQueue(Buffer_Standard*, int, int)+0x8c / VM::WriteRValueToBuffer(RValue*, Buffer_Standard*)
 * 字段偏移 top8: 0x4×3 / 0x8×3 / 0x2c×2 / 0xc×1 / 0x2×1 / 0x10×1 / 0x30×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xdb2dc push {r4, r5, r6, r7, lr}
 *   @0xdb2e0 sub sp, sp, #20
 *   @0xdb2e4 mov r6, r0
 *   @0xdb2e8 add r0, sp, #12
 *   @0xdb2ec mov r4, r1
 *   @0xdb2f0 str r2, [sp, #0x4]
 *   @0xdb2f4 bl 0xffee8 <_Z12GetTheQueuesRi>
 *   @0xdb2f8 cmp r4, #0
 *   @0xdb2fc blt 0xdb370 <_ZN2VM10GetDSQueueEP15Buffer_Standardii+0x94>
 *   @0xdb300 ldr r3, [sp, #0xc]
 *   @0xdb304 cmp r4, r3
 *   @0xdb308 bge 0xdb370 <_ZN2VM10GetDSQueueEP15Buffer_Standardii+0x94>
 *   @0xdb30c ldr r5, [r0, r4, lsl #2]
 *   @0xdb310 cmp r5, #0
 *   @0xdb314 beq 0xdb370 <_ZN2VM10GetDSQueueEP15Buffer_Standardii+0x94>
 *   @0xdb318 ldr r1, [r5, #0x4]
 *   @0xdb31c mov r0, r6
 *   @0xdb320 ldr r3, [r5, #0x8]
 *   @0xdb324 add r2, sp, #4
 *   @0xdb328 rsb r1, r3, r1
 *   @0xdb32c bl 0xdb080 <_ZN2VM16WriteDSSizeCountEP15Buffer_StandardiRi>
 *   @0xdb330 subs r7, r0, #0
 *   @0xdb334 ble 0xdb368 <_ZN2VM10GetDSQueueEP15Buffer_Standardii+0x8c>
 *   @0xdb338 mov r4, #0
 *   @0xdb33c ldr r3, [r5, #0x8]
 *   @0xdb340 mov r1, r6
 *   @0xdb344 ldr r2, [sp, #0x4]
 *   @0xdb348 ldr r0, [r5, #0x10]
 *   @0xdb34c add r2, r3, r2
 *   @0xdb350 add r2, r2, r4
 *   @0xdb354 add r4, r4, #1
 *   @0xdb358 add r0, r0, r2, lsl #4
 *   @0xdb35c bl 0xd8a88 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard>
 *   @0xdb360 cmp r4, r7
 *   @0xdb364 bne 0xdb33c <_ZN2VM10GetDSQueueEP15Buffer_Standardii+0x60>
 *   @0xdb368 add sp, sp, #20
 *   @0xdb36c pop {r4, r5, r6, r7, pc}
 *   @0xdb370 mov r2, r6
 *   @0xdb374 mov r1, #0
 *   @0xdb378 ldr r0, [r2], #44
 *   @0xdb37c movt r1, #0xffe0
 *   @0xdb380 movw r3, #0xffff
 *   @0xdb384 str r1, [r6, #0x2c]
 *   @0xdb388 movt r3, #0x41ef
 *   @0xdb38c mov r1, #0
 *   @0xdb390 str r3, [r6, #0x30]
 *   @0xdb394 ldr r3, [r0, #0x8]
 *   @0xdb398 mov r0, r6
 *   @0xdb39c str r1, [r6, #0x38]
 *   @0xdb3a0 mov r1, #5
 *   @0xdb3a4 blx r3
 *   @0xdb3a8 add sp, sp, #20
 *   @0xdb3ac pop {r4, r5, r6, r7, pc}
 *
 * ══ §18/146 F_DsGridGetDiskSum(RValue&, CInstance*, CInstance*, int, RValue*)  0xfe020  size 212  53 条（0xfe020..0xfe0f4）
 * @func 0xfe020 0xfe104  size 228  57 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×3 / YYGetInt32(RValue const*, int) / F_DsGridGetDiskSum(RValue&, CInstance*, CInstance*, int, RValue*)+0xb0 / CDS_Grid::Get_Disk_Sum(RValue&, double, double, double)
 * 字段偏移 top8: 0x30×1 / 0x5c×1 / 0x4c×1 / 0x4×1 / 0x2×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfe020 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xfe024 sub sp, sp, #16
 *   @0xfe028 mov r1, #0
 *   @0xfe02c mov r9, r0
 *   @0xfe030 ldr r8, [sp, #0x30]
 *   @0xfe034 mov r0, r8
 *   @0xfe038 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfe03c mov r1, #1
 *   @0xfe040 mov r10, r0
 *   @0xfe044 mov r0, r8
 *   @0xfe048 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0xfe04c mov r4, r0
 *   @0xfe050 mov r5, r1
 *   @0xfe054 mov r0, r8
 *   @0xfe058 mov r1, #2
 *   @0xfe05c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0xfe060 mov r6, r0
 *   @0xfe064 mov r7, r1
 *   @0xfe068 mov r0, r8
 *   @0xfe06c mov r1, #3
 *   @0xfe070 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0xfe074 cmp r10, #0
 *   @0xfe078 mov r2, r0
 *   @0xfe07c mov r3, r1
 *   @0xfe080 blt 0xfe0d0 <_Z18F_DsGridGetDiskSumR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0xfe084 ldr r1, [pc, #0x5c]
 *   @0xfe088 ldr r1, [pc, r1]
 *   @0xfe08c ldr r1, [r1]
 *   @0xfe090 cmp r10, r1
 *   @0xfe094 bge 0xfe0d0 <_Z18F_DsGridGetDiskSumR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0xfe098 ldr r1, [pc, #0x4c]
 *   @0xfe09c ldr r1, [pc, r1]
 *   @0xfe0a0 ldr r1, [r1, #0x4]
 *   @0xfe0a4 ldr r0, [r1, r10, lsl #2]
 *   @0xfe0a8 cmp r0, #0
 *   @0xfe0ac beq 0xfe0d0 <_Z18F_DsGridGetDiskSumR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0xfe0b0 strd r2, r3, [sp, #8]
 *   @0xfe0b4 mov r1, r9
 *   @0xfe0b8 strd r6, r7, [sp]
 *   @0xfe0bc mov r2, r4
 *   @0xfe0c0 mov r3, r5
 *   @0xfe0c4 bl 0x20441c <_ZN8CDS_Grid12Get_Disk_SumER6RValueddd>
 *   @0xfe0c8 add sp, sp, #16
 *   @0xfe0cc pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xfe0d0 ldr r0, [pc, #0x18]
 *   @0xfe0d4 mov r1, #0
 *   @0xfe0d8 add r0, pc, r0
 *   @0xfe0dc add sp, sp, #16
 *   @0xfe0e0 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xfe0e4 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfe0e8 .word 0x002efdfc
 *   @0xfe0ec eoreq pc, lr, r12, ror #27
 *   @0xfe0f0 eoreq r9, r3, r4, lsr #22
 *
 * ══ §19/146 F_DsGridGetDiskMin(RValue&, CInstance*, CInstance*, int, RValue*)  0xfe0f4  size 212  53 条（0xfe0f4..0xfe1c8）
 * @func 0xfe0f4 0xfe1d8  size 228  57 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×3 / YYGetInt32(RValue const*, int) / F_DsGridGetDiskMin(RValue&, CInstance*, CInstance*, int, RValue*)+0xb0 / CDS_Grid::Get_Disk_Min(RValue&, double, double, double)
 * 字段偏移 top8: 0x30×1 / 0x5c×1 / 0x4c×1 / 0x4×1 / 0x2×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfe0f4 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xfe0f8 sub sp, sp, #16
 *   @0xfe0fc mov r1, #0
 *   @0xfe100 mov r9, r0
 *   @0xfe104 ldr r8, [sp, #0x30]
 *   @0xfe108 mov r0, r8
 *   @0xfe10c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfe110 mov r1, #1
 *   @0xfe114 mov r10, r0
 *   @0xfe118 mov r0, r8
 *   @0xfe11c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0xfe120 mov r4, r0
 *   @0xfe124 mov r5, r1
 *   @0xfe128 mov r0, r8
 *   @0xfe12c mov r1, #2
 *   @0xfe130 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0xfe134 mov r6, r0
 *   @0xfe138 mov r7, r1
 *   @0xfe13c mov r0, r8
 *   @0xfe140 mov r1, #3
 *   @0xfe144 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0xfe148 cmp r10, #0
 *   @0xfe14c mov r2, r0
 *   @0xfe150 mov r3, r1
 *   @0xfe154 blt 0xfe1a4 <_Z18F_DsGridGetDiskMinR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0xfe158 ldr r1, [pc, #0x5c]
 *   @0xfe15c ldr r1, [pc, r1]
 *   @0xfe160 ldr r1, [r1]
 *   @0xfe164 cmp r10, r1
 *   @0xfe168 bge 0xfe1a4 <_Z18F_DsGridGetDiskMinR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0xfe16c ldr r1, [pc, #0x4c]
 *   @0xfe170 ldr r1, [pc, r1]
 *   @0xfe174 ldr r1, [r1, #0x4]
 *   @0xfe178 ldr r0, [r1, r10, lsl #2]
 *   @0xfe17c cmp r0, #0
 *   @0xfe180 beq 0xfe1a4 <_Z18F_DsGridGetDiskMinR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0xfe184 strd r2, r3, [sp, #8]
 *   @0xfe188 mov r1, r9
 *   @0xfe18c strd r6, r7, [sp]
 *   @0xfe190 mov r2, r4
 *   @0xfe194 mov r3, r5
 *   @0xfe198 bl 0x207588 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd>
 *   @0xfe19c add sp, sp, #16
 *   @0xfe1a0 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xfe1a4 ldr r0, [pc, #0x18]
 *   @0xfe1a8 mov r1, #0
 *   @0xfe1ac add r0, pc, r0
 *   @0xfe1b0 add sp, sp, #16
 *   @0xfe1b4 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xfe1b8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfe1bc eoreq pc, lr, r8, lsr #26
 *   @0xfe1c0 eoreq pc, lr, r8, lsl sp
 *   @0xfe1c4 eoreq r9, r3, r0, asr r10
 *
 * ══ §20/146 F_DsGridGetDiskMax(RValue&, CInstance*, CInstance*, int, RValue*)  0xfe1c8  size 212  53 条（0xfe1c8..0xfe29c）
 * @func 0xfe1c8 0xfe2ac  size 228  57 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×3 / YYGetInt32(RValue const*, int) / F_DsGridGetDiskMax(RValue&, CInstance*, CInstance*, int, RValue*)+0xb0 / CDS_Grid::Get_Disk_Max(RValue&, double, double, double)
 * 字段偏移 top8: 0x30×1 / 0x5c×1 / 0x4c×1 / 0x4×1 / 0x2×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfe1c8 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xfe1cc sub sp, sp, #16
 *   @0xfe1d0 mov r1, #0
 *   @0xfe1d4 mov r9, r0
 *   @0xfe1d8 ldr r8, [sp, #0x30]
 *   @0xfe1dc mov r0, r8
 *   @0xfe1e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfe1e4 mov r1, #1
 *   @0xfe1e8 mov r10, r0
 *   @0xfe1ec mov r0, r8
 *   @0xfe1f0 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0xfe1f4 mov r4, r0
 *   @0xfe1f8 mov r5, r1
 *   @0xfe1fc mov r0, r8
 *   @0xfe200 mov r1, #2
 *   @0xfe204 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0xfe208 mov r6, r0
 *   @0xfe20c mov r7, r1
 *   @0xfe210 mov r0, r8
 *   @0xfe214 mov r1, #3
 *   @0xfe218 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0xfe21c cmp r10, #0
 *   @0xfe220 mov r2, r0
 *   @0xfe224 mov r3, r1
 *   @0xfe228 blt 0xfe278 <_Z18F_DsGridGetDiskMaxR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0xfe22c ldr r1, [pc, #0x5c]
 *   @0xfe230 ldr r1, [pc, r1]
 *   @0xfe234 ldr r1, [r1]
 *   @0xfe238 cmp r10, r1
 *   @0xfe23c bge 0xfe278 <_Z18F_DsGridGetDiskMaxR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0xfe240 ldr r1, [pc, #0x4c]
 *   @0xfe244 ldr r1, [pc, r1]
 *   @0xfe248 ldr r1, [r1, #0x4]
 *   @0xfe24c ldr r0, [r1, r10, lsl #2]
 *   @0xfe250 cmp r0, #0
 *   @0xfe254 beq 0xfe278 <_Z18F_DsGridGetDiskMaxR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0xfe258 strd r2, r3, [sp, #8]
 *   @0xfe25c mov r1, r9
 *   @0xfe260 strd r6, r7, [sp]
 *   @0xfe264 mov r2, r4
 *   @0xfe268 mov r3, r5
 *   @0xfe26c bl 0x207104 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd>
 *   @0xfe270 add sp, sp, #16
 *   @0xfe274 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xfe278 ldr r0, [pc, #0x18]
 *   @0xfe27c mov r1, #0
 *   @0xfe280 add r0, pc, r0
 *   @0xfe284 add sp, sp, #16
 *   @0xfe288 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xfe28c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfe290 eoreq pc, lr, r4, asr r12
 *   @0xfe294 eoreq pc, lr, r4, asr #24
 *   @0xfe298 eoreq r9, r3, r12, ror r9
 *
 * ══ §21/146 F_DsGridGetDiskMean(RValue&, CInstance*, CInstance*, int, RValue*)  0xfe29c  size 212  53 条（0xfe29c..0xfe370）
 * @func 0xfe29c 0xfe370  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×3 / YYGetInt32(RValue const*, int) / F_DsGridGetDiskMean(RValue&, CInstance*, CInstance*, int, RValue*)+0xb0 / CDS_Grid::Get_Disk_Mean(RValue&, double, double, double)
 * 字段偏移 top8: 0x30×1 / 0x5c×1 / 0x4c×1 / 0x4×1 / 0x2×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfe29c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xfe2a0 sub sp, sp, #16
 *   @0xfe2a4 mov r1, #0
 *   @0xfe2a8 mov r9, r0
 *   @0xfe2ac ldr r8, [sp, #0x30]
 *   @0xfe2b0 mov r0, r8
 *   @0xfe2b4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xfe2b8 mov r1, #1
 *   @0xfe2bc mov r10, r0
 *   @0xfe2c0 mov r0, r8
 *   @0xfe2c4 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0xfe2c8 mov r4, r0
 *   @0xfe2cc mov r5, r1
 *   @0xfe2d0 mov r0, r8
 *   @0xfe2d4 mov r1, #2
 *   @0xfe2d8 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0xfe2dc mov r6, r0
 *   @0xfe2e0 mov r7, r1
 *   @0xfe2e4 mov r0, r8
 *   @0xfe2e8 mov r1, #3
 *   @0xfe2ec bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0xfe2f0 cmp r10, #0
 *   @0xfe2f4 mov r2, r0
 *   @0xfe2f8 mov r3, r1
 *   @0xfe2fc blt 0xfe34c <_Z19F_DsGridGetDiskMeanR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0xfe300 ldr r1, [pc, #0x5c]
 *   @0xfe304 ldr r1, [pc, r1]
 *   @0xfe308 ldr r1, [r1]
 *   @0xfe30c cmp r10, r1
 *   @0xfe310 bge 0xfe34c <_Z19F_DsGridGetDiskMeanR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0xfe314 ldr r1, [pc, #0x4c]
 *   @0xfe318 ldr r1, [pc, r1]
 *   @0xfe31c ldr r1, [r1, #0x4]
 *   @0xfe320 ldr r0, [r1, r10, lsl #2]
 *   @0xfe324 cmp r0, #0
 *   @0xfe328 beq 0xfe34c <_Z19F_DsGridGetDiskMeanR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0xfe32c strd r2, r3, [sp, #8]
 *   @0xfe330 mov r1, r9
 *   @0xfe334 strd r6, r7, [sp]
 *   @0xfe338 mov r2, r4
 *   @0xfe33c mov r3, r5
 *   @0xfe340 bl 0x2045bc <_ZN8CDS_Grid13Get_Disk_MeanER6RValueddd>
 *   @0xfe344 add sp, sp, #16
 *   @0xfe348 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xfe34c ldr r0, [pc, #0x18]
 *   @0xfe350 mov r1, #0
 *   @0xfe354 add r0, pc, r0
 *   @0xfe358 add sp, sp, #16
 *   @0xfe35c pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xfe360 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xfe364 eoreq pc, lr, r0, lsl #23
 *   @0xfe368 eoreq pc, lr, r0, ror r11
 *   @0xfe36c eoreq r9, r3, r8, lsr #17
 *
 * ══ §22/146 F_ArrayGet(RValue&, CInstance*, CInstance*, int, RValue*)  0x10f468  size 212  53 条（0x10f468..0x10f53c）
 * @func 0x10f468 0x10f53c  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x10f4c8→0x75505d, 0x10f4dc→0x75504c, 0x10f4e0→0x755058, 0x10f4e4→0x755054, 0x10f4ec→0x755050
 * 调用序列: YYGetInt32(RValue const*, int) / GET_RValue(RValue*, RValue*, int)
 * 字段偏移 top8: 0x44×3 / 0x10×2 / 0xc×2 / 0xa4×1 / 0x4×1 / 0x54×1 / 0x40×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10f468 push {r4, r5, r6, lr}
 *   @0x10f46c mov r4, r0
 *   @0x10f470 ldr r5, [sp, #0x10]
 *   @0x10f474 ldr r6, [pc, #0xa4]
 *   @0x10f478 ldr r3, [r5, #0xc]
 *   @0x10f47c add r6, pc, r6
 *   @0x10f480 cmp r3, #2
 *   @0x10f484 beq 0x10f4a0 <_Z10F_ArrayGetR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x10f488 mov r3, #0
 *   @0x10f48c mov r2, #5
 *   @0x10f490 str r3, [r4]
 *   @0x10f494 str r2, [r4, #0xc]
 *   @0x10f498 str r3, [r4, #0x4]
 *   @0x10f49c pop {r4, r5, r6, pc}
 *   @0x10f4a0 ldr r3, [r5]
 *   @0x10f4a4 cmp r3, #0
 *   @0x10f4a8 beq 0x10f488 <_Z10F_ArrayGetR6RValueP9CInstanceS2_iPS_+0x20>
 *   @0x10f4ac mov r1, #1
 *   @0x10f4b0 mov r0, r5
 *   @0x10f4b4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x10f4b8 mov r1, r5
 *   @0x10f4bc mov r2, r0
 *   @0x10f4c0 mov r0, r4
 *   @0x10f4c4 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i>
 *   @0x10f4c8 ldr r3, [pc, #0x54]
 *   @0x10f4cc ldr r3, [r6, r3]
 *   @0x10f4d0 ldrb r3, [r3]
 *   @0x10f4d4 cmp r3, #0
 *   @0x10f4d8 popeq {r4, r5, r6, pc}
 *   @0x10f4dc ldr r0, [pc, #0x44]
 *   @0x10f4e0 ldr r1, [pc, #0x44]
 *   @0x10f4e4 ldr r2, [pc, #0x44]
 *   @0x10f4e8 ldr r0, [r6, r0]
 *   @0x10f4ec ldr r3, [pc, #0x40]
 *   @0x10f4f0 ldr r1, [r6, r1]
 *   @0x10f4f4 ldr r2, [r6, r2]
 *   @0x10f4f8 ldr r3, [r6, r3]
 *   @0x10f4fc ldr r12, [r0]
 *   @0x10f500 ldr r0, [pc, #0x30]
 *   @0x10f504 ldr r1, [r1]
 *   @0x10f508 ldr r2, [r2]
 *   @0x10f50c add r0, pc, r0
 *   @0x10f510 ldr r3, [r3]
 *   @0x10f514 str r12, [sp, #0x10]
 *   @0x10f518 pop {r4, r5, r6, lr}
 *   @0x10f51c b 0xd547c <_Z7YYErrorPKcz>
 *   @0x10f520 .word 0x002e27d4
 *   @0x10f524 .word 0xffffbf24
 *   @0x10f528 .word 0xffffbf34
 *   @0x10f52c .word 0xffffbf28
 *   @0x10f530 .word 0xffffbf2c
 *   @0x10f534 .word 0xffffbf30
 *   @0x10f538 eoreq r9, r2, r4, lsr #19
 *
 * ══ §23/146 F_DateGetYear(RValue&, CInstance*, CInstance*, int, RValue*)  0x116c40  size 212  53 条（0x116c40..0x116d14）
 * @func 0x116c40 0x116d14  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / __fixdfdi / 0xb6820 / 0xb682c / 0x8279b4
 * 字段偏移 top8: 0xc×1 / 0x10×1 / 0x6c×1
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x116c40 push {r4, lr}
 *   @0x116c44 sub sp, sp, #8
 *   @0x116c48 mov r1, #0
 *   @0x116c4c mov r4, r0
 *   @0x116c50 mov r3, r1
 *   @0x116c54 str r1, [r0, #0xc]
 *   @0x116c58 movt r3, #0xbff0
 *   @0x116c5c stm r0, {r1, r3}
 *   @0x116c60 ldr r0, [sp, #0x10]
 *   @0x116c64 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x116c68 vldr d7, [pc, #128]
 *   @0x116c6c vldr d5, [pc, #132]
 *   @0x116c70 vmov d6, r0, r1
 *   @0x116c74 vsub.f64 d7, d6, d7
 *   @0x116c78 vabs.f64 d4, d7
 *   @0x116c7c vcmpe.f64 d4, d5
 *   @0x116c80 vmrs APSR_nzcv, fpscr
 *   @0x116c84 vldrls d7, [pc, #116]
 *   @0x116c88 vldrhi d6, [pc, #112]
 *   @0x116c8c vmul.f64 d5, d7, d6
 *   @0x116c90 vmov r0, r1, d5
 *   @0x116c94 bl 0x3194a0 <__fixdfdi>
 *   @0x116c98 mov r3, r1
 *   @0x116c9c ldr r1, [pc, #0x6c]
 *   @0x116ca0 mov r2, r0
 *   @0x116ca4 strd r2, r3, [sp]
 *   @0x116ca8 add r1, pc, r1
 *   @0x116cac mov r0, sp
 *   @0x116cb0 ldrb r3, [r1]
 *   @0x116cb4 cmp r3, #0
 *   @0x116cb8 bne 0x116ce8 <_Z13F_DateGetYearR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x116cbc bl 0xb6820 <gmtime64@plt>
 *   @0x116cc0 cmp r0, #0
 *   @0x116cc4 beq 0x116ce0 <_Z13F_DateGetYearR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x116cc8 vldr s12, [r0, #20]
 *   @0x116ccc vcvt.f64.s32 d6, s12
 *   @0x116cd0 vldr d7, [pc, #48]
 *   @0x116cd4 vadd.f64 d5, d6, d7
 *   @0x116cd8 vmov r2, r3, d5
 *   @0x116cdc stm r4, {r2, r3}
 *   @0x116ce0 add sp, sp, #8
 *   @0x116ce4 pop {r4, pc}
 *   @0x116ce8 bl 0xb682c <localtime64@plt>
 *   @0x116cec b 0x116cc0 <_Z13F_DateGetYearR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x116cf0 andeq r0, r0, r0
 *   @0x116cf4 sbcsmi pc, r8, r0, asr #16
 *   @0x116cf8 bl 0x8279b4 <b2_toiTime+0xce510>
 *   @0x116cfc svclo #0x1a36e2
 *   @0x116d00 andeq r0, r0, r0
 *   @0x116d04 rscsmi r1, r5, r0, lsl #16
 *   @0x116d08 andeq r0, r0, r0
 *   @0x116d0c addsmi r11, sp, r0
 *   @0x116d10 mlaeq sp, r0, r4, r11
 *
 * ══ §24/146 F_VariableInstanceExists(RValue&, CInstance*, CInstance*, int, RValue*)  0x11793c  size 212  53 条（0x11793c..0x117a10）
 * @func 0x11793c 0x117a10  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: WithObjIterator::operator*()×2 / YYGetInt32(RValue const*, int) / YYGetString(RValue const*, int) / WithObjIterator::WithObjIterator(int, CInstance*, CInstance*, bool) / DoVariableInstanceExists(CInstance*, char const*) / WithObjIterator::Next()
 * 字段偏移 top8: 0x4×2 / 0x50×1 / 0xc×1 / 0x68×1 / 0x69×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11793c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x117940 sub sp, sp, #48
 *   @0x117944 mov r6, r0
 *   @0x117948 mov r9, r1
 *   @0x11794c ldr r5, [sp, #0x50]
 *   @0x117950 mov r1, #0
 *   @0x117954 mov r8, r2
 *   @0x117958 add r4, sp, #12
 *   @0x11795c mov r0, r5
 *   @0x117960 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x117964 mov r1, #1
 *   @0x117968 mov r10, r0
 *   @0x11796c mov r0, r5
 *   @0x117970 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x117974 mov r12, #0
 *   @0x117978 mov r1, r10
 *   @0x11797c str r12, [r6]
 *   @0x117980 str r12, [r6, #0x4]
 *   @0x117984 mov r2, r9
 *   @0x117988 mov r3, r8
 *   @0x11798c mov r7, r0
 *   @0x117990 mov r0, #13
 *   @0x117994 str r0, [r6, #0xc]
 *   @0x117998 mov r0, r4
 *   @0x11799c str r12, [sp]
 *   @0x1179a0 bl 0x19d060 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b>
 *   @0x1179a4 b 0x1179dc <_Z24F_VariableInstanceExistsR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x1179a8 bl 0x19de4c <_ZN15WithObjIteratordeEv>
 *   @0x1179ac ldrb r2, [r0, #0x68]
 *   @0x1179b0 cmp r2, #0
 *   @0x1179b4 bne 0x1179d4 <_Z24F_VariableInstanceExistsR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x1179b8 ldrb r5, [r0, #0x69]
 *   @0x1179bc cmp r5, #0
 *   @0x1179c0 bne 0x1179d4 <_Z24F_VariableInstanceExistsR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x1179c4 mov r1, r7
 *   @0x1179c8 bl 0x1178b8 <_Z24DoVariableInstanceExistsP9CInstancePKc>
 *   @0x1179cc cmp r0, #0
 *   @0x1179d0 bne 0x1179f8 <_Z24F_VariableInstanceExistsR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x1179d4 mov r0, r4
 *   @0x1179d8 bl 0x19d1c8 <_ZN15WithObjIterator4NextEv>
 *   @0x1179dc mov r0, r4
 *   @0x1179e0 bl 0x19de4c <_ZN15WithObjIteratordeEv>
 *   @0x1179e4 cmp r0, #0
 *   @0x1179e8 mov r0, r4
 *   @0x1179ec bne 0x1179a8 <_Z24F_VariableInstanceExistsR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x1179f0 add sp, sp, #48
 *   @0x1179f4 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1179f8 str r5, [r6]
 *   @0x1179fc mov r3, #0
 *   @0x117a00 movt r3, #0x3ff0
 *   @0x117a04 str r3, [r6, #0x4]
 *   @0x117a08 add sp, sp, #48
 *   @0x117a0c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ §25/146 F_CheckKeyReleased(RValue&, CInstance*, CInstance*, int, RValue*)  0x127544  size 212  53 条（0x127544..0x127618）
 * @func 0x127544 0x127618  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IO_Key_Released(int)×3 / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x4×3 / 0xc×1 / 0x18×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x127544 push {r4, r5, r6, r7, r8, lr}
 *   @0x127548 mov r8, #0
 *   @0x12754c mov r5, r0
 *   @0x127550 str r8, [r0, #0xc]
 *   @0x127554 str r8, [r0]
 *   @0x127558 mov r1, r8
 *   @0x12755c str r8, [r0, #0x4]
 *   @0x127560 ldr r0, [sp, #0x18]
 *   @0x127564 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x127568 subs r3, r0, #0
 *   @0x12756c bne 0x1275ac <_Z18F_CheckKeyReleasedR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x127570 mov r4, r3
 *   @0x127574 str r3, [r5]
 *   @0x127578 mov r6, r3
 *   @0x12757c mov r3, r8
 *   @0x127580 movt r3, #0x3ff0
 *   @0x127584 str r3, [r5, #0x4]
 *   @0x127588 mov r0, r4
 *   @0x12758c add r4, r4, #1
 *   @0x127590 bl 0x18bf30 <_Z15IO_Key_Releasedi>
 *   @0x127594 cmp r0, #0
 *   @0x127598 strne r6, [r5]
 *   @0x12759c strne r6, [r5, #0x4]
 *   @0x1275a0 cmp r4, #256
 *   @0x1275a4 bne 0x127588 <_Z18F_CheckKeyReleasedR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x1275a8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1275ac cmp r3, #1
 *   @0x1275b0 beq 0x1275dc <_Z18F_CheckKeyReleasedR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x1275b4 cmp r3, #255
 *   @0x1275b8 pophi {r4, r5, r6, r7, r8, pc}
 *   @0x1275bc bl 0x18bf30 <_Z15IO_Key_Releasedi>
 *   @0x1275c0 vmov s15, r0
 *   @0x1275c4 vcvt.f64.u32 d7, s15
 *   @0x1275c8 vmov r0, r1, d7
 *   @0x1275cc vmov r2, s14
 *   @0x1275d0 mov r3, r1
 *   @0x1275d4 stm r5, {r2, r3}
 *   @0x1275d8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1275dc mov r6, #0
 *   @0x1275e0 movt r6, #0x3ff0
 *   @0x1275e4 mov r4, r8
 *   @0x1275e8 mov r7, r8
 *   @0x1275ec str r8, [r5]
 *   @0x1275f0 str r8, [r5, #0x4]
 *   @0x1275f4 mov r0, r4
 *   @0x1275f8 add r4, r4, #1
 *   @0x1275fc bl 0x18bf30 <_Z15IO_Key_Releasedi>
 *   @0x127600 cmp r0, #0
 *   @0x127604 strne r7, [r5]
 *   @0x127608 strne r6, [r5, #0x4]
 *   @0x12760c cmp r4, #256
 *   @0x127610 bne 0x1275f4 <_Z18F_CheckKeyReleasedR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x127614 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §26/146 F_AudioSetListenerOrientationN(RValue&, CInstance*, CInstance*, int, RValue*)  0x1348cc  size 212  53 条（0x1348cc..0x1349a0）
 * @func 0x1348cc 0x1349a0  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×6 / YYGetInt32(RValue const*, int) / Audio_SetListenerOrientation(int, double, double, double, double, double, double)
 * 字段偏移 top8: 0x2c×2 / 0x28×2 / 0xc8×1 / 0x60×1
 * VFP 指令 2 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1348cc ldr r3, [pc, #0xc8]
 *   @0x1348d0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1348d4 ldr r3, [pc, r3]
 *   @0x1348d8 sub sp, sp, #60
 *   @0x1348dc ldrb r1, [r3]
 *   @0x1348e0 ldr r10, [sp, #0x60]
 *   @0x1348e4 cmp r1, #0
 *   @0x1348e8 bne 0x134994 <_Z30F_AudioSetListenerOrientationNR6RValueP9CInstanceS2_iPS_+0xc8>
 *   @0x1348ec mov r0, r10
 *   @0x1348f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1348f4 mov r1, #1
 *   @0x1348f8 mov r11, r0
 *   @0x1348fc mov r0, r10
 *   @0x134900 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134904 mov r2, r0
 *   @0x134908 mov r3, r1
 *   @0x13490c mov r0, r10
 *   @0x134910 mov r1, #2
 *   @0x134914 str r2, [sp, #0x2c]
 *   @0x134918 str r3, [sp, #0x28]
 *   @0x13491c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134920 mov r8, r0
 *   @0x134924 mov r9, r1
 *   @0x134928 mov r0, r10
 *   @0x13492c mov r1, #3
 *   @0x134930 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134934 mov r6, r0
 *   @0x134938 mov r7, r1
 *   @0x13493c mov r0, r10
 *   @0x134940 mov r1, #4
 *   @0x134944 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134948 mov r4, r0
 *   @0x13494c mov r5, r1
 *   @0x134950 mov r0, r10
 *   @0x134954 mov r1, #5
 *   @0x134958 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x13495c strd r0, r1, [sp, #48]
 *   @0x134960 mov r0, r10
 *   @0x134964 mov r1, #6
 *   @0x134968 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x13496c vldr d7, [sp, #48]
 *   @0x134970 strd r8, r9, [sp]
 *   @0x134974 vstr d7, [sp, #24]
 *   @0x134978 strd r6, r7, [sp, #8]
 *   @0x13497c strd r4, r5, [sp, #16]
 *   @0x134980 ldr r2, [sp, #0x2c]
 *   @0x134984 ldr r3, [sp, #0x28]
 *   @0x134988 strd r0, r1, [sp, #32]
 *   @0x13498c mov r0, r11
 *   @0x134990 bl 0x216650 <_Z28Audio_SetListenerOrientationidddddd>
 *   @0x134994 add sp, sp, #60
 *   @0x134998 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x13499c eoreq r10, r11, r8, ror r7
 *
 * ══ §27/146 F_FileRename(RValue&, CInstance*, CInstance*, int, RValue*)  0x138508  size 212  53 条（0x138508..0x1385dc）
 * @func 0x138508 0x1385dc  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)×2 / LoadSave::_GetSaveFileName(char*, int, char const*)×2 / LoadSave::SaveFileExists(char const*) / 0xb685c / 0xb65d4
 * 字段偏移 top8: 0x-ffc×2 / 0xbc×1 / 0x-fe0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x138508 push {r4, r5, r6, r7, r8, lr}
 *   @0x13850c sub sp, sp, #4096
 *   @0x138510 sub sp, sp, #8
 *   @0x138514 ldr r4, [pc, #0xbc]
 *   @0x138518 add r2, sp, #8192
 *   @0x13851c mov r1, #0
 *   @0x138520 ldr r4, [pc, r4]
 *   @0x138524 mov r7, r0
 *   @0x138528 ldr r5, [r2, #-0xfe0]
 *   @0x13852c ldr r3, [r4]
 *   @0x138530 mov r0, r5
 *   @0x138534 str r3, [r2, #-0xffc]
 *   @0x138538 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x13853c mov r1, #1
 *   @0x138540 mov r6, r0
 *   @0x138544 mov r0, r5
 *   @0x138548 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x13854c mov r5, r0
 *   @0x138550 mov r0, r6
 *   @0x138554 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0x138558 cmp r0, #0
 *   @0x13855c beq 0x1385b4 <_Z12F_FileRenameR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x138560 mov r2, r6
 *   @0x138564 add r6, sp, #2048
 *   @0x138568 add r8, sp, #4
 *   @0x13856c add r6, r6, #8
 *   @0x138570 sub r6, r6, #4
 *   @0x138574 mov r1, #2048
 *   @0x138578 mov r0, r8
 *   @0x13857c bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x138580 mov r2, r5
 *   @0x138584 mov r1, #2048
 *   @0x138588 mov r0, r6
 *   @0x13858c bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x138590 mov r0, r8
 *   @0x138594 mov r1, r6
 *   @0x138598 bl 0xb685c <rename@plt>
 *   @0x13859c cmp r0, #0
 *   @0x1385a0 movne r0, #0
 *   @0x1385a4 moveq r3, #0
 *   @0x1385a8 movne r3, r0
 *   @0x1385ac movteq r3, #0x3ff0
 *   @0x1385b0 stm r7, {r0, r3}
 *   @0x1385b4 add r3, sp, #8192
 *   @0x1385b8 ldr r2, [r3, #-0xffc]
 *   @0x1385bc ldr r3, [r4]
 *   @0x1385c0 cmp r2, r3
 *   @0x1385c4 bne 0x1385d4 <_Z12F_FileRenameR6RValueP9CInstanceS2_iPS_+0xcc>
 *   @0x1385c8 add sp, sp, #4096
 *   @0x1385cc add sp, sp, #8
 *   @0x1385d0 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1385d4 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x1385d8 eoreq r5, r11, r0, lsr r4
 *
 * ══ §28/146 F_ActionDrawRectangle(RValue&, CInstance*, CInstance*, int, RValue*)  0x140388  size 212  53 条（0x140388..0x14045c）
 * @func 0x140388 0x14045c  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4 / YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x20×2 / 0x6c×1
 * VFP 指令 21 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x140388 push {r4, r5, r6, lr}
 *   @0x14038c vpush {d8, d9}
 *   @0x140390 mov r5, r1
 *   @0x140394 ldr r4, [sp, #0x20]
 *   @0x140398 mov r1, #0
 *   @0x14039c mov r0, r4
 *   @0x1403a0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1403a4 mov r1, #1
 *   @0x1403a8 vmov s19, r0
 *   @0x1403ac mov r0, r4
 *   @0x1403b0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1403b4 mov r1, #2
 *   @0x1403b8 vmov s18, r0
 *   @0x1403bc mov r0, r4
 *   @0x1403c0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1403c4 mov r1, #3
 *   @0x1403c8 vmov s17, r0
 *   @0x1403cc mov r0, r4
 *   @0x1403d0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1403d4 mov r1, #4
 *   @0x1403d8 vmov s16, r0
 *   @0x1403dc mov r0, r4
 *   @0x1403e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1403e4 ldr r3, [pc, #0x6c]
 *   @0x1403e8 ldr r3, [pc, r3]
 *   @0x1403ec ldrb r3, [r3]
 *   @0x1403f0 cmp r0, #0
 *   @0x1403f4 movle r0, #0
 *   @0x1403f8 movgt r0, #1
 *   @0x1403fc cmp r3, #0
 *   @0x140400 str r0, [sp, #0x20]
 *   @0x140404 bne 0x140424 <_Z21F_ActionDrawRectangleR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x140408 vmov r0, s19
 *   @0x14040c vmov r1, s18
 *   @0x140410 vmov r2, s17
 *   @0x140414 vmov r3, s16
 *   @0x140418 vpop {d8, d9}
 *   @0x14041c pop {r4, r5, r6, lr}
 *   @0x140420 b 0x16aa1c <_Z20YYGML_draw_rectangleffffb>
 *   @0x140424 vldr s14, [r5, #180]
 *   @0x140428 vldr s15, [r5, #184]
 *   @0x14042c vadd.f32 s19, s19, s14
 *   @0x140430 vadd.f32 s18, s18, s15
 *   @0x140434 vmov r0, s19
 *   @0x140438 vadd.f32 s14, s17, s14
 *   @0x14043c vmov r1, s18
 *   @0x140440 vadd.f32 s15, s16, s15
 *   @0x140444 vpop {d8, d9}
 *   @0x140448 vmov r2, s14
 *   @0x14044c pop {r4, r5, r6, lr}
 *   @0x140450 vmov r3, s15
 *   @0x140454 b 0x16aa1c <_Z20YYGML_draw_rectangleffffb>
 *   @0x140458 eoreq sp, r10, r4, asr r7
 *
 * ══ §29/146 FacebookGraphRequestM(char*, char*, int, int)  0x15fe9c  size 212  53 条（0x15fe9c..0x15ff70）
 * @func 0x15fe9c 0x15ff70  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×3 / BuildFacebookWallPost(int, _jobjectArray*&) / FacebookGraphRequestM(char*, char*, int, int)+0x5c / F_DsMapClear(RValue&, CInstance*, CInstance*, int, RValue*) / _JNIEnv::CallStaticVoidMethod(_jclass*, _jmethodID*, ...)
 * 字段偏移 top8: 0x29c×2 / 0x24×1 / 0x34×1 / 0x30×1 / 0x14×1 / 0x8×1 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15fe9c push {r4, r5, r6, r8, r9, lr}
 *   @0x15fea0 sub sp, sp, #40
 *   @0x15fea4 mov r6, r0
 *   @0x15fea8 mov r5, r1
 *   @0x15feac mov r0, r2
 *   @0x15feb0 add r1, sp, #20
 *   @0x15feb4 mov r4, r3
 *   @0x15feb8 bl 0x15faa8 <_Z21BuildFacebookWallPostiRP13_jobjectArray>
 *   @0x15febc cmp r4, #0
 *   @0x15fec0 blt 0x15fef8 <_Z21FacebookGraphRequestMPcS_ii+0x5c>
 *   @0x15fec4 vmov s13, r4
 *   @0x15fec8 add r12, sp, #40
 *   @0x15fecc mov r0, #0
 *   @0x15fed0 mov r3, #1
 *   @0x15fed4 vcvt.f64.s32 d7, s13
 *   @0x15fed8 mov r1, r0
 *   @0x15fedc mov r2, r0
 *   @0x15fee0 str r0, [sp, #0x24]
 *   @0x15fee4 vmov r8, r9, d7
 *   @0x15fee8 strd r8, r9, [r12, #-16]!
 *   @0x15feec mov r0, r12
 *   @0x15fef0 str r12, [sp]
 *   @0x15fef4 bl 0xfed40 <_Z12F_DsMapClearR6RValueP9CInstanceS2_iPS_>
 *   @0x15fef8 bl 0x290274 <getJNIEnv>
 *   @0x15fefc mov r1, r6
 *   @0x15ff00 ldr r3, [r0]
 *   @0x15ff04 ldr r3, [r3, #0x29c]
 *   @0x15ff08 blx r3
 *   @0x15ff0c mov r6, r0
 *   @0x15ff10 bl 0x290274 <getJNIEnv>
 *   @0x15ff14 mov r1, r5
 *   @0x15ff18 ldr r3, [r0]
 *   @0x15ff1c ldr r3, [r3, #0x29c]
 *   @0x15ff20 blx r3
 *   @0x15ff24 mov r5, r0
 *   @0x15ff28 bl 0x290274 <getJNIEnv>
 *   @0x15ff2c ldr r1, [pc, #0x34]
 *   @0x15ff30 mov r3, r6
 *   @0x15ff34 ldr r2, [pc, #0x30]
 *   @0x15ff38 ldr r12, [sp, #0x14]
 *   @0x15ff3c ldr r1, [pc, r1]
 *   @0x15ff40 ldr r2, [pc, r2]
 *   @0x15ff44 ldr r1, [r1]
 *   @0x15ff48 ldr r2, [r2]
 *   @0x15ff4c str r5, [sp]
 *   @0x15ff50 str r4, [sp, #0x8]
 *   @0x15ff54 str r12, [sp, #0x4]
 *   @0x15ff58 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x15ff5c mov r0, #1
 *   @0x15ff60 add sp, sp, #40
 *   @0x15ff64 pop {r4, r5, r6, r8, r9, pc}
 *   @0x15ff68 eoreq sp, r8, r8, ror #20
 *   @0x15ff6c eoreq pc, r8, r4, ror pc
 *
 * ══ §30/146 GR_D3D_Set_Region(int, int)  0x1698ec  size 212  53 条（0x1698ec..0x1699c0）
 * @func 0x1698ec 0x1699c0  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x16991c→0x3f238c, 0x16992c→0x3f2388
 * 调用序列: Graphics_DisplayWidth()×2 / Graphics_DisplayHeight()×2 / GR_D3D_Set_Region(int, int)+0xbc / GR_D3D_Set_Region(int, int)+0xb0 / GR_D3D_Set_View_Port(int, int, int, int) / GR_D3D_Set_View_Area(float, float, float, float, float)
 * 字段偏移 top8: 0xac×1 / 0x94×1 / 0x88×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1698ec push {r4, r5, r6, r7, lr}
 *   @0x1698f0 sub sp, sp, #12
 *   @0x1698f4 mov r4, r0
 *   @0x1698f8 mov r5, r1
 *   @0x1698fc bl 0x17db24 <_Z21Graphics_DisplayWidthv>
 *   @0x169900 ldr r6, [pc, #0xac]
 *   @0x169904 add r6, pc, r6
 *   @0x169908 cmp r0, r4
 *   @0x16990c blt 0x1699a8 <_Z17GR_D3D_Set_Regionii+0xbc>
 *   @0x169910 bl 0x17db38 <_Z22Graphics_DisplayHeightv>
 *   @0x169914 cmp r0, r5
 *   @0x169918 blt 0x16999c <_Z17GR_D3D_Set_Regionii+0xb0>
 *   @0x16991c ldr r3, [pc, #0x94]
 *   @0x169920 ldr r7, [r6, r3]
 *   @0x169924 ldr r3, [r7]
 *   @0x169928 cmp r4, r3
 *   @0x16992c ldr r3, [pc, #0x88]
 *   @0x169930 ldr r6, [r6, r3]
 *   @0x169934 beq 0x16998c <_Z17GR_D3D_Set_Regionii+0xa0>
 *   @0x169938 mov r0, #0
 *   @0x16993c mov r2, r4
 *   @0x169940 mov r1, r0
 *   @0x169944 mov r3, r5
 *   @0x169948 str r4, [r7]
 *   @0x16994c str r5, [r6]
 *   @0x169950 bl 0x168cd8 <_Z20GR_D3D_Set_View_Portiiii>
 *   @0x169954 ldr r2, [r7]
 *   @0x169958 mov r1, #0
 *   @0x16995c ldr r3, [r6]
 *   @0x169960 mov r0, r1
 *   @0x169964 str r1, [sp]
 *   @0x169968 vmov s15, r2
 *   @0x16996c vcvt.f32.s32 s15, s15
 *   @0x169970 vmov r2, s15
 *   @0x169974 vmov s15, r3
 *   @0x169978 vcvt.f32.s32 s15, s15
 *   @0x16997c vmov r3, s15
 *   @0x169980 bl 0x169408 <_Z20GR_D3D_Set_View_Areafffff>
 *   @0x169984 add sp, sp, #12
 *   @0x169988 pop {r4, r5, r6, r7, pc}
 *   @0x16998c ldr r3, [r6]
 *   @0x169990 cmp r5, r3
 *   @0x169994 bne 0x169938 <_Z17GR_D3D_Set_Regionii+0x4c>
 *   @0x169998 b 0x169984 <_Z17GR_D3D_Set_Regionii+0x98>
 *   @0x16999c bl 0x17db38 <_Z22Graphics_DisplayHeightv>
 *   @0x1699a0 mov r5, r0
 *   @0x1699a4 b 0x16991c <_Z17GR_D3D_Set_Regionii+0x30>
 *   @0x1699a8 bl 0x17db24 <_Z21Graphics_DisplayWidthv>
 *   @0x1699ac mov r4, r0
 *   @0x1699b0 b 0x169910 <_Z17GR_D3D_Set_Regionii+0x24>
 *   @0x1699b4 eoreq r8, r8, r12, asr #6
 *   @0x1699b8 .word 0xffffe4e4
 *   @0x1699bc .word 0xffffe4e8
 *
 * ══ §31/146 _PNG_setTexture(Texture*, int, int, int, int, int, unsigned char*)  0x181cdc  size 212  53 条（0x181cdc..0x181db0）
 * @func 0x181cdc 0x181db0  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: gluBuild2DMipmaps(unsigned int, int, int, int, unsigned int, unsigned int, void const*)
 * 字段偏移 top8: 0x14×3 / 0x70×2 / 0x4×2 / 0x8×2 / 0xbc×1 / 0x38×1 / 0x3c×1 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x181cdc ldr r12, [pc, #0xbc]
 *   @0x181ce0 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x181ce4 ldr r12, [pc, r12]
 *   @0x181ce8 sub sp, sp, #24
 *   @0x181cec mov r6, r1
 *   @0x181cf0 mov r4, r3
 *   @0x181cf4 mov r7, r0
 *   @0x181cf8 ldr r3, [r12]
 *   @0x181cfc add r1, sp, #20
 *   @0x181d00 mov r0, #1
 *   @0x181d04 mov r5, r2
 *   @0x181d08 ldr r10, [sp, #0x38]
 *   @0x181d0c ldr r9, [sp, #0x3c]
 *   @0x181d10 ldr r8, [sp, #0x40]
 *   @0x181d14 blx r3
 *   @0x181d18 ldr r3, [pc, #0x84]
 *   @0x181d1c movw r0, #0xde1
 *   @0x181d20 ldr r1, [sp, #0x14]
 *   @0x181d24 ldr r3, [pc, r3]
 *   @0x181d28 ldr r3, [r3]
 *   @0x181d2c blx r3
 *   @0x181d30 ldr r12, [pc, #0x70]
 *   @0x181d34 ldr r1, [pc, #0x70]
 *   @0x181d38 mov r2, r5
 *   @0x181d3c ldr r12, [pc, r12]
 *   @0x181d40 mov r3, r4
 *   @0x181d44 add r1, pc, r1
 *   @0x181d48 ldr r0, [r12]
 *   @0x181d4c ldr r12, [r0]
 *   @0x181d50 str r10, [sp]
 *   @0x181d54 str r9, [sp, #0x4]
 *   @0x181d58 str r6, [sp, #0x8]
 *   @0x181d5c ldr r12, [r12, #0xc]
 *   @0x181d60 blx r12
 *   @0x181d64 cmp r6, #2
 *   @0x181d68 mov r3, r4
 *   @0x181d6c movw r12, #0x1401
 *   @0x181d70 movwne r1, #0x1908
 *   @0x181d74 movweq r1, #0x1907
 *   @0x181d78 str r8, [sp, #0x8]
 *   @0x181d7c mov r2, r5
 *   @0x181d80 movw r0, #0xde1
 *   @0x181d84 str r12, [sp, #0x4]
 *   @0x181d88 str r1, [sp]
 *   @0x181d8c bl 0x181b58 <_Z17gluBuild2DMipmapsjiiijjPKv>
 *   @0x181d90 ldr r3, [sp, #0x14]
 *   @0x181d94 str r3, [r7, #0x14]
 *   @0x181d98 add sp, sp, #24
 *   @0x181d9c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x181da0 mlaeq r6, r4, r10, r11
 *   @0x181da4 eoreq r11, r6, r12, asr #20
 *   @0x181da8 .word 0x0026b9d8
 *   @0x181dac andseq r9, r12, r8, lsr sp
 *
 * ══ §32/146 CreateNativeVertexFormat(VertexFormat*)  0x18565c  size 212  53 条（0x18565c..0x185730）
 * @func 0x18565c 0x185730  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65b0 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / CreateNativeVertexFormat(VertexFormat*)+0xc0
 * 字段偏移 top8: 0x4×3 / 0x-8×2 / 0x-3c×2 / 0xa0×1 / 0x8×1 / 0x78×1 / 0x-10×1 / 0x-c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18565c push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x185660 subs r6, r0, #0
 *   @0x185664 sub sp, sp, #68
 *   @0x185668 beq 0x185720 <_Z24CreateNativeVertexFormatP12VertexFormat+0xc4>
 *   @0x18566c mov r1, #0
 *   @0x185670 mov r2, #60
 *   @0x185674 add r0, sp, #4
 *   @0x185678 bl 0xb65b0 <memset@plt>
 *   @0x18567c ldr r0, [r6, #0x4]
 *   @0x185680 ldr r1, [pc, #0xa0]
 *   @0x185684 mov r2, #70
 *   @0x185688 mov r3, #1
 *   @0x18568c add r1, pc, r1
 *   @0x185690 lsl r0, r0, #4
 *   @0x185694 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x185698 ldr r8, [r6, #0x4]
 *   @0x18569c cmp r8, #0
 *   @0x1856a0 ble 0x18571c <_Z24CreateNativeVertexFormatP12VertexFormat+0xc0>
 *   @0x1856a4 ldr r2, [r6, #0x8]
 *   @0x1856a8 mov r3, r0
 *   @0x1856ac ldr r7, [pc, #0x78]
 *   @0x1856b0 add r8, r2, r8, lsl #4
 *   @0x1856b4 add r7, pc, r7
 *   @0x1856b8 ldr r1, [r2, #0x4]
 *   @0x1856bc movw r12, #0x1406
 *   @0x1856c0 mov r5, #4
 *   @0x1856c4 mov r4, #0
 *   @0x1856c8 sub r1, r1, #1
 *   @0x1856cc add r2, r2, #16
 *   @0x1856d0 cmp r1, #5
 *   @0x1856d4 add r9, r7, r1
 *   @0x1856d8 add r1, r7, r1, lsl #2
 *   @0x1856dc add r3, r3, #16
 *   @0x1856e0 ldrbls r4, [r9, #0x78]
 *   @0x1856e4 ldrls r12, [r1, #0x48]
 *   @0x1856e8 ldrls r5, [r1, #0x60]
 *   @0x1856ec add r1, sp, #64
 *   @0x1856f0 str r12, [r3, #-0x10]
 *   @0x1856f4 ldr r12, [r2, #-0x8]
 *   @0x1856f8 cmp r2, r8
 *   @0x1856fc strb r4, [r3, #-0x8]
 *   @0x185700 str r5, [r3, #-0xc]
 *   @0x185704 add r12, r1, r12, lsl #2
 *   @0x185708 ldr r1, [r12, #-0x3c]
 *   @0x18570c add r4, r1, #1
 *   @0x185710 str r4, [r12, #-0x3c]
 *   @0x185714 str r1, [r3, #-0x4]
 *   @0x185718 bne 0x1856b8 <_Z24CreateNativeVertexFormatP12VertexFormat+0x5c>
 *   @0x18571c str r0, [r6, #0xc]
 *   @0x185720 add sp, sp, #68
 *   @0x185724 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x185728 andseq r11, r10, r4, lsr #19
 *   @0x18572c andseq r8, sp, r8, lsr #10
 *
 * ══ §33/146 Shader_Flush_All()  0x187ed4  size 212  53 条（0x187ed4..0x187fa8）
 * @func 0x187ed4 0x187fa8  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x187ee0→0x479b30, 0x187ef4→0x532fc0, 0x187f28→0x479b38, 0x187f48→0x479b34, 0x187f68→0x479b34
 * 调用序列: 无
 * 字段偏移 top8: 0x4×3 / 0xb0×2 / 0x8×2 / 0xa0×1 / 0x2×1 / 0x70×1 / 0x54×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x187ed4 push {r4, r5, r6, r7, r8, lr}
 *   @0x187ed8 mov r0, #0
 *   @0x187edc ldr r8, [pc, #0xb0]
 *   @0x187ee0 ldr r3, [pc, #0xb0]
 *   @0x187ee4 add r8, pc, r8
 *   @0x187ee8 ldr r3, [r8, r3]
 *   @0x187eec ldr r3, [r3]
 *   @0x187ef0 blx r3
 *   @0x187ef4 ldr r3, [pc, #0xa0]
 *   @0x187ef8 ldr r6, [r8, r3]
 *   @0x187efc ldr r3, [r6]
 *   @0x187f00 cmp r3, #0
 *   @0x187f04 pople {r4, r5, r6, r7, r8, pc}
 *   @0x187f08 mov r5, #0
 *   @0x187f0c mvn r7, #0
 *   @0x187f10 ldr r3, [r6, #0x4]
 *   @0x187f14 ldr r4, [r3, r5, lsl #2]
 *   @0x187f18 add r5, r5, #1
 *   @0x187f1c cmp r4, #0
 *   @0x187f20 beq 0x187f84 <_Z16Shader_Flush_Allv+0xb0>
 *   @0x187f24 ldr r0, [r4, #0x8]
 *   @0x187f28 ldr r3, [pc, #0x70]
 *   @0x187f2c cmn r0, #1
 *   @0x187f30 beq 0x187f44 <_Z16Shader_Flush_Allv+0x70>
 *   @0x187f34 ldr r3, [r8, r3]
 *   @0x187f38 ldr r3, [r3]
 *   @0x187f3c blx r3
 *   @0x187f40 str r7, [r4, #0x8]
 *   @0x187f44 ldr r0, [r4]
 *   @0x187f48 ldr r3, [pc, #0x54]
 *   @0x187f4c cmn r0, #1
 *   @0x187f50 beq 0x187f64 <_Z16Shader_Flush_Allv+0x90>
 *   @0x187f54 ldr r3, [r8, r3]
 *   @0x187f58 ldr r3, [r3]
 *   @0x187f5c blx r3
 *   @0x187f60 str r7, [r4]
 *   @0x187f64 ldr r0, [r4, #0x4]
 *   @0x187f68 ldr r3, [pc, #0x34]
 *   @0x187f6c cmn r0, #1
 *   @0x187f70 beq 0x187f84 <_Z16Shader_Flush_Allv+0xb0>
 *   @0x187f74 ldr r3, [r8, r3]
 *   @0x187f78 ldr r3, [r3]
 *   @0x187f7c blx r3
 *   @0x187f80 str r7, [r4, #0x4]
 *   @0x187f84 ldr r3, [r6]
 *   @0x187f88 cmp r3, r5
 *   @0x187f8c bgt 0x187f10 <_Z16Shader_Flush_Allv+0x3c>
 *   @0x187f90 pop {r4, r5, r6, r7, r8, pc}
 *   @0x187f94 eoreq r9, r6, r12, ror #26
 *   @0x187f98 .word 0xffffbb80
 *   @0x187f9c .word 0xffffe968
 *   @0x187fa0 .word 0xffffbb78
 *   @0x187fa4 .word 0xffffbb7c
 *
 * ══ §34/146 CLayerManager::RemoveSpriteElement(CLayer*, CLayerSpriteElement*)  0x1b7cf8  size 212  53 条（0x1b7cf8..0x1b7dcc）
 * @func 0x1b7cf8 0x1b7dcc  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×3 / 0x18×2 / 0x14×2 / 0x60×2 / 0x8c×1 / 0x24×1 / 0x4×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b7cf8 ldr r3, [r1, #0x18]
 *   @0x1b7cfc mov r12, #0
 *   @0x1b7d00 ldr r2, [r1, #0x14]
 *   @0x1b7d04 cmp r3, #0
 *   @0x1b7d08 push {r4, r5, r6, r7, r8, r9}
 *   @0x1b7d0c mov r4, #1065353216
 *   @0x1b7d10 strne r2, [r3, #0x14]
 *   @0x1b7d14 mvn r5, #0
 *   @0x1b7d18 ldrne r2, [r1, #0x14]
 *   @0x1b7d1c mov r7, #4
 *   @0x1b7d20 ldrne r3, [r1, #0x18]
 *   @0x1b7d24 streq r2, [r0, #0x58]
 *   @0x1b7d28 cmp r2, #0
 *   @0x1b7d2c ldr r9, [r0, #0x60]
 *   @0x1b7d30 strne r3, [r2, #0x18]
 *   @0x1b7d34 ldr r2, [pc, #0x8c]
 *   @0x1b7d38 add r9, r9, r5
 *   @0x1b7d3c streq r3, [r0, #0x5c]
 *   @0x1b7d40 mov r3, #0
 *   @0x1b7d44 ldr r2, [pc, r2]
 *   @0x1b7d48 str r9, [r0, #0x60]
 *   @0x1b7d4c str r4, [r1, #0x24]
 *   @0x1b7d50 ldr r6, [r2]
 *   @0x1b7d54 ldr r8, [r2, #0x8]
 *   @0x1b7d58 cmp r6, r3
 *   @0x1b7d5c str r5, [r1, #0x4]
 *   @0x1b7d60 str r7, [r1]
 *   @0x1b7d64 add r0, r8, #1
 *   @0x1b7d68 strb r3, [r1, #0x8]
 *   @0x1b7d6c str r4, [r1, #0x2c]
 *   @0x1b7d70 str r4, [r1, #0x30]
 *   @0x1b7d74 str r4, [r1, #0x3c]
 *   @0x1b7d78 str r5, [r1, #0x1c]
 *   @0x1b7d7c str r5, [r1, #0x38]
 *   @0x1b7d80 str r3, [r1, #0xc]
 *   @0x1b7d84 str r12, [r1, #0x20]
 *   @0x1b7d88 str r3, [r1, #0x10]
 *   @0x1b7d8c str r12, [r1, #0x34]
 *   @0x1b7d90 str r3, [r1, #0x14]
 *   @0x1b7d94 str r3, [r1, #0x18]
 *   @0x1b7d98 str r3, [r1, #0x28]
 *   @0x1b7d9c str r12, [r1, #0x40]
 *   @0x1b7da0 str r12, [r1, #0x44]
 *   @0x1b7da4 str r0, [r2, #0x8]
 *   @0x1b7da8 streq r1, [r2, #0x4]
 *   @0x1b7dac strne r1, [r6, #0x18]
 *   @0x1b7db0 streq r1, [r2]
 *   @0x1b7db4 strne r6, [r1, #0x14]
 *   @0x1b7db8 strne r1, [r2]
 *   @0x1b7dbc strne r3, [r1, #0x18]
 *   @0x1b7dc0 pop {r4, r5, r6, r7, r8, r9}
 *   @0x1b7dc4 bx lr
 *   @0x1b7dc8 eoreq r8, r3, r8, lsr #22
 *
 * ══ §35/146 F_LayerGetDepth(RValue&, CInstance*, CInstance*, int, RValue*)  0x1baad4  size 212  53 条（0x1baad4..0x1baba8）
 * @func 0x1baad4 0x1baba8  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetLayerFromID(CRoom*, int) / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0xc×3 / 0x4×2 / 0x20×2 / 0x18×1 / 0x94×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1baad4 cmp r3, #1
 *   @0x1baad8 push {r3, r4, r5, r6, r7, lr}
 *   @0x1baadc mov r3, #0
 *   @0x1baae0 mov r5, r3
 *   @0x1baae4 mov r4, r0
 *   @0x1baae8 movt r3, #0xbff0
 *   @0x1baaec str r5, [r0, #0xc]
 *   @0x1baaf0 str r3, [r0, #0x4]
 *   @0x1baaf4 str r5, [r0]
 *   @0x1baaf8 ldr r6, [sp, #0x18]
 *   @0x1baafc beq 0x1bab14 <_Z15F_LayerGetDepthR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bab00 ldr r0, [pc, #0x94]
 *   @0x1bab04 mov r1, r5
 *   @0x1bab08 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1bab0c add r0, pc, r0
 *   @0x1bab10 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bab14 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bab18 ldr r3, [r6, #0xc]
 *   @0x1bab1c mov r1, r5
 *   @0x1bab20 bic r3, r3, #-16777216
 *   @0x1bab24 cmp r3, #1
 *   @0x1bab28 mov r7, r0
 *   @0x1bab2c mov r0, r6
 *   @0x1bab30 beq 0x1bab64 <_Z15F_LayerGetDepthR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x1bab34 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bab38 mov r1, r0
 *   @0x1bab3c mov r0, r7
 *   @0x1bab40 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1bab44 cmp r0, #0
 *   @0x1bab48 beq 0x1bab78 <_Z15F_LayerGetDepthR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x1bab4c ldr r2, [r0, #0x4]
 *   @0x1bab50 vmov s15, r2
 *   @0x1bab54 vcvt.f64.s32 d7, s15
 *   @0x1bab58 vmov r2, r3, d7
 *   @0x1bab5c stm r4, {r2, r3}
 *   @0x1bab60 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bab64 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1bab68 mov r1, r0
 *   @0x1bab6c mov r0, r7
 *   @0x1bab70 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1bab74 b 0x1bab44 <_Z15F_LayerGetDepthR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x1bab78 ldr r3, [pc, #0x20]
 *   @0x1bab7c ldr r1, [pc, #0x20]
 *   @0x1bab80 ldr r3, [pc, r3]
 *   @0x1bab84 add r1, pc, r1
 *   @0x1bab88 ldr r0, [r3]
 *   @0x1bab8c ldr r3, [r0]
 *   @0x1bab90 ldr r3, [r3, #0xc]
 *   @0x1bab94 blx r3
 *   @0x1bab98 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1bab9c andseq r2, r9, r4, asr #25
 *   @0x1baba0 mlaeq r3, r4, r11, r2
 *   @0x1baba4 andseq r2, r9, r12, ror r12
 *
 * ══ §36/146 F_LayerDestroy(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bc0e0  size 212  53 条（0x1bc0e0..0x1bc1b4）
 * @func 0x1bc0e0 0x1bc1b4  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetLayerFromID(CRoom*, int) / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0xc×3 / 0x20×2 / 0x10×1 / 0x4×1 / 0x98×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bc0e0 cmp r3, #1
 *   @0x1bc0e4 mov r3, #0
 *   @0x1bc0e8 push {r4, r5, r6, lr}
 *   @0x1bc0ec mov r4, r3
 *   @0x1bc0f0 ldr r5, [sp, #0x10]
 *   @0x1bc0f4 movt r3, #0xbff0
 *   @0x1bc0f8 str r4, [r0, #0xc]
 *   @0x1bc0fc str r3, [r0, #0x4]
 *   @0x1bc100 str r4, [r0]
 *   @0x1bc104 beq 0x1bc11c <_Z14F_LayerDestroyR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1bc108 ldr r0, [pc, #0x98]
 *   @0x1bc10c mov r1, r4
 *   @0x1bc110 pop {r4, r5, r6, lr}
 *   @0x1bc114 add r0, pc, r0
 *   @0x1bc118 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bc11c bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bc120 ldr r3, [r5, #0xc]
 *   @0x1bc124 mov r1, r4
 *   @0x1bc128 bic r3, r3, #-16777216
 *   @0x1bc12c cmp r3, #1
 *   @0x1bc130 mov r6, r0
 *   @0x1bc134 mov r0, r5
 *   @0x1bc138 beq 0x1bc16c <_Z14F_LayerDestroyR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x1bc13c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bc140 mov r1, r0
 *   @0x1bc144 mov r0, r6
 *   @0x1bc148 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1bc14c mov r3, r0
 *   @0x1bc150 cmp r3, #0
 *   @0x1bc154 beq 0x1bc184 <_Z14F_LayerDestroyR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x1bc158 mov r0, r6
 *   @0x1bc15c ldr r1, [r3]
 *   @0x1bc160 mov r2, #1
 *   @0x1bc164 pop {r4, r5, r6, lr}
 *   @0x1bc168 b 0x1b95d8 <_ZN13CLayerManager11RemoveLayerEP5CRoomib>
 *   @0x1bc16c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1bc170 mov r1, r0
 *   @0x1bc174 mov r0, r6
 *   @0x1bc178 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1bc17c mov r3, r0
 *   @0x1bc180 b 0x1bc150 <_Z14F_LayerDestroyR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x1bc184 ldr r3, [pc, #0x20]
 *   @0x1bc188 ldr r1, [pc, #0x20]
 *   @0x1bc18c ldr r3, [pc, r3]
 *   @0x1bc190 add r1, pc, r1
 *   @0x1bc194 ldr r0, [r3]
 *   @0x1bc198 ldr r3, [r0]
 *   @0x1bc19c ldr r3, [r3, #0xc]
 *   @0x1bc1a0 blx r3
 *   @0x1bc1a4 pop {r4, r5, r6, pc}
 *   @0x1bc1a8 andseq r1, r9, r0, ror #25
 *   @0x1bc1ac eoreq r1, r3, r8, lsl #11
 *   @0x1bc1b0 mulseq r9, r0, r12
 *
 * ══ §37/146 F_LayerBackgroundExists(RValue&, CInstance*, CInstance*, int, RValue*)  0x1c0828  size 212  53 条（0x1c0828..0x1c08fc）
 * @func 0x1c0828 0x1c090c  size 228  57 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / CLayerManager::GetTargetRoomObj() / CLayerManager::GetLayerFromID(CRoom*, int) / CLayerManager::GetElementFromID(CLayer*, int) / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0xc×2 / 0x18×1 / 0x4×1 / 0xa4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c0828 cmp r3, #2
 *   @0x1c082c push {r3, r4, r5, r6, r7, lr}
 *   @0x1c0830 mov r4, #0
 *   @0x1c0834 mov r5, r0
 *   @0x1c0838 ldr r6, [sp, #0x18]
 *   @0x1c083c str r4, [r0, #0xc]
 *   @0x1c0840 str r4, [r0]
 *   @0x1c0844 str r4, [r0, #0x4]
 *   @0x1c0848 beq 0x1c0860 <_Z23F_LayerBackgroundExistsR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x1c084c ldr r0, [pc, #0xa4]
 *   @0x1c0850 mov r1, r4
 *   @0x1c0854 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1c0858 add r0, pc, r0
 *   @0x1c085c b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1c0860 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1c0864 ldr r3, [r6, #0xc]
 *   @0x1c0868 mov r1, r4
 *   @0x1c086c bic r3, r3, #-16777216
 *   @0x1c0870 cmp r3, #1
 *   @0x1c0874 mov r7, r0
 *   @0x1c0878 mov r0, r6
 *   @0x1c087c beq 0x1c08d8 <_Z23F_LayerBackgroundExistsR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x1c0880 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1c0884 mov r1, r0
 *   @0x1c0888 mov r0, r7
 *   @0x1c088c bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1c0890 mov r4, r0
 *   @0x1c0894 cmp r4, #0
 *   @0x1c0898 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1c089c mov r1, #1
 *   @0x1c08a0 mov r0, r6
 *   @0x1c08a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1c08a8 mov r1, r0
 *   @0x1c08ac mov r0, r4
 *   @0x1c08b0 bl 0x1c07e4 <_ZN13CLayerManager16GetElementFromIDEP6CLayeri>
 *   @0x1c08b4 cmp r0, #0
 *   @0x1c08b8 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1c08bc ldr r3, [r0]
 *   @0x1c08c0 cmp r3, #1
 *   @0x1c08c4 moveq r3, #0
 *   @0x1c08c8 moveq r2, r3
 *   @0x1c08cc movteq r3, #0x3ff0
 *   @0x1c08d0 stmeq r5, {r2, r3}
 *   @0x1c08d4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1c08d8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1c08dc mov r1, r0
 *   @0x1c08e0 mov r0, r7
 *   @0x1c08e4 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1c08e8 mov r4, r0
 *   @0x1c08ec cmp r4, #0
 *   @0x1c08f0 bne 0x1c089c <_Z23F_LayerBackgroundExistsR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x1c08f4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1c08f8 andseq pc, r8, r4, lsl #2
 *
 * ══ §38/146 F_LayerSpriteExists(RValue&, CInstance*, CInstance*, int, RValue*)  0x1c08fc  size 212  53 条（0x1c08fc..0x1c09d0）
 * @func 0x1c08fc 0x1c09d0  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / CLayerManager::GetTargetRoomObj() / CLayerManager::GetLayerFromID(CRoom*, int) / CLayerManager::GetElementFromID(CLayer*, int) / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0xc×2 / 0x18×1 / 0x4×1 / 0xa4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c08fc cmp r3, #2
 *   @0x1c0900 push {r3, r4, r5, r6, r7, lr}
 *   @0x1c0904 mov r4, #0
 *   @0x1c0908 mov r5, r0
 *   @0x1c090c ldr r6, [sp, #0x18]
 *   @0x1c0910 str r4, [r0, #0xc]
 *   @0x1c0914 str r4, [r0]
 *   @0x1c0918 str r4, [r0, #0x4]
 *   @0x1c091c beq 0x1c0934 <_Z19F_LayerSpriteExistsR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x1c0920 ldr r0, [pc, #0xa4]
 *   @0x1c0924 mov r1, r4
 *   @0x1c0928 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1c092c add r0, pc, r0
 *   @0x1c0930 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1c0934 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1c0938 ldr r3, [r6, #0xc]
 *   @0x1c093c mov r1, r4
 *   @0x1c0940 bic r3, r3, #-16777216
 *   @0x1c0944 cmp r3, #1
 *   @0x1c0948 mov r7, r0
 *   @0x1c094c mov r0, r6
 *   @0x1c0950 beq 0x1c09ac <_Z19F_LayerSpriteExistsR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x1c0954 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1c0958 mov r1, r0
 *   @0x1c095c mov r0, r7
 *   @0x1c0960 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1c0964 mov r4, r0
 *   @0x1c0968 cmp r4, #0
 *   @0x1c096c popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1c0970 mov r1, #1
 *   @0x1c0974 mov r0, r6
 *   @0x1c0978 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1c097c mov r1, r0
 *   @0x1c0980 mov r0, r4
 *   @0x1c0984 bl 0x1c07e4 <_ZN13CLayerManager16GetElementFromIDEP6CLayeri>
 *   @0x1c0988 cmp r0, #0
 *   @0x1c098c popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1c0990 ldr r3, [r0]
 *   @0x1c0994 cmp r3, #4
 *   @0x1c0998 moveq r3, #0
 *   @0x1c099c moveq r2, r3
 *   @0x1c09a0 movteq r3, #0x3ff0
 *   @0x1c09a4 stmeq r5, {r2, r3}
 *   @0x1c09a8 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1c09ac bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1c09b0 mov r1, r0
 *   @0x1c09b4 mov r0, r7
 *   @0x1c09b8 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1c09bc mov r4, r0
 *   @0x1c09c0 cmp r4, #0
 *   @0x1c09c4 bne 0x1c0970 <_Z19F_LayerSpriteExistsR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x1c09c8 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1c09cc andseq pc, r8, r8, rrx
 *
 * ══ §39/146 CScript::LoadFromChunk(YYScript*, unsigned char*)  0x1dfd3c  size 212  53 条（0x1dfd3c..0x1dfe10）
 * @func 0x1dfd3c 0x1dfe10  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1dfd58→0x544c44, 0x1dfd74→0x544c04, 0x1dfd88→0x544c48, 0x1dfda8→0x544c44
 * 调用序列: CScript::Clear() / 0xb6538 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65a4
 * 字段偏移 top8: 0x4×2 / 0x10×2 / 0xac×1 / 0x14×1 / 0x88×1 / 0x78×1 / 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dfd3c ldr r3, [r1]
 *   @0x1dfd40 push {r4, r5, r6, lr}
 *   @0x1dfd44 cmp r3, #0
 *   @0x1dfd48 ldr r4, [pc, #0xac]
 *   @0x1dfd4c mov r6, r1
 *   @0x1dfd50 mov r5, r0
 *   @0x1dfd54 add r4, pc, r4
 *   @0x1dfd58 ldrne r2, [pc, #0xa0]
 *   @0x1dfd5c ldrne r2, [r4, r2]
 *   @0x1dfd60 ldrne r2, [r2]
 *   @0x1dfd64 addne r3, r2, r3
 *   @0x1dfd68 str r3, [r5, #0x14]
 *   @0x1dfd6c mov r0, r5
 *   @0x1dfd70 bl 0x1dfbb0 <_ZN7CScript5ClearEv>
 *   @0x1dfd74 ldr r3, [pc, #0x88]
 *   @0x1dfd78 ldr r3, [r4, r3]
 *   @0x1dfd7c ldrb r3, [r3]
 *   @0x1dfd80 cmp r3, #0
 *   @0x1dfd84 bne 0x1dfdec <_ZN7CScript13LoadFromChunkEP8YYScriptPh+0xb0>
 *   @0x1dfd88 ldr r3, [pc, #0x78]
 *   @0x1dfd8c ldr r3, [r4, r3]
 *   @0x1dfd90 ldrb r3, [r3]
 *   @0x1dfd94 cmp r3, #0
 *   @0x1dfd98 bne 0x1dfdec <_ZN7CScript13LoadFromChunkEP8YYScriptPh+0xb0>
 *   @0x1dfd9c ldr r3, [r6, #0x4]
 *   @0x1dfda0 cmp r3, #0
 *   @0x1dfda4 moveq r4, r3
 *   @0x1dfda8 ldrne r2, [pc, #0x50]
 *   @0x1dfdac ldrne r2, [r4, r2]
 *   @0x1dfdb0 ldrne r4, [r2]
 *   @0x1dfdb4 addne r4, r4, r3
 *   @0x1dfdb8 mov r0, r4
 *   @0x1dfdbc bl 0xb6538 <strlen@plt>
 *   @0x1dfdc0 ldr r1, [pc, #0x44]
 *   @0x1dfdc4 mov r3, #1
 *   @0x1dfdc8 mov r2, #155
 *   @0x1dfdcc add r1, pc, r1
 *   @0x1dfdd0 add r0, r0, r3
 *   @0x1dfdd4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1dfdd8 mov r1, r4
 *   @0x1dfddc str r0, [r5, #0x10]
 *   @0x1dfde0 bl 0xb65a4 <strcpy@plt>
 *   @0x1dfde4 mov r0, #1
 *   @0x1dfde8 pop {r4, r5, r6, pc}
 *   @0x1dfdec ldr r3, [r6, #0x4]
 *   @0x1dfdf0 mov r0, #1
 *   @0x1dfdf4 str r3, [r5, #0x10]
 *   @0x1dfdf8 pop {r4, r5, r6, pc}
 *   @0x1dfdfc .word 0x00211efc
 *   @0x1dfe00 .word 0xffffbcf4
 *   @0x1dfe04 .word 0xffffbf10
 *   @0x1dfe08 .word 0xffffbecc
 *   @0x1dfe0c andseq r1, r7, r0, lsl #30
 *
 * ══ §40/146 CSprite::SetAlphaFromSprite(CSprite*)  0x1e5c90  size 212  53 条（0x1e5c90..0x1e5d64）
 * @func 0x1e5c90 0x1e5d74  size 228  57 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __aeabi_idivmod / CBitmap32::SetAlphaFromBitmap(CBitmap32*) / CSprite::InitTexture()
 * 字段偏移 top8: 0x18×4 / 0x54×2 / 0x36×2 / 0x48×2 / 0x2×2 / 0x20×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e5c90 push {r3, r4, r5, r6, r7, lr}
 *   @0x1e5c94 mov r6, r1
 *   @0x1e5c98 ldr r1, [r1, #0x18]
 *   @0x1e5c9c mov r5, r0
 *   @0x1e5ca0 cmp r1, #0
 *   @0x1e5ca4 pople {r3, r4, r5, r6, r7, pc}
 *   @0x1e5ca8 ldr r3, [r0, #0x54]
 *   @0x1e5cac cmp r3, #0
 *   @0x1e5cb0 beq 0x1e5cc0 <_ZN7CSprite18SetAlphaFromSpriteEPS_+0x30>
 *   @0x1e5cb4 ldrb r3, [r0, #0x36]
 *   @0x1e5cb8 cmp r3, #0
 *   @0x1e5cbc beq 0x1e5d48 <_ZN7CSprite18SetAlphaFromSpriteEPS_+0xb8>
 *   @0x1e5cc0 ldr r3, [r6, #0x54]
 *   @0x1e5cc4 cmp r3, #0
 *   @0x1e5cc8 beq 0x1e5cd8 <_ZN7CSprite18SetAlphaFromSpriteEPS_+0x48>
 *   @0x1e5ccc ldrb r3, [r6, #0x36]
 *   @0x1e5cd0 cmp r3, #0
 *   @0x1e5cd4 beq 0x1e5d34 <_ZN7CSprite18SetAlphaFromSpriteEPS_+0xa4>
 *   @0x1e5cd8 ldr r3, [r5, #0x18]
 *   @0x1e5cdc cmp r3, #0
 *   @0x1e5ce0 movgt r4, #0
 *   @0x1e5ce4 bgt 0x1e5cf0 <_ZN7CSprite18SetAlphaFromSpriteEPS_+0x60>
 *   @0x1e5ce8 b 0x1e5d20 <_ZN7CSprite18SetAlphaFromSpriteEPS_+0x90>
 *   @0x1e5cec ldr r1, [r6, #0x18]
 *   @0x1e5cf0 ldr r3, [r5, #0x48]
 *   @0x1e5cf4 mov r0, r4
 *   @0x1e5cf8 ldr r7, [r3, r4, lsl #2]
 *   @0x1e5cfc bl 0x318dec <__aeabi_idivmod>
 *   @0x1e5d00 ldr r3, [r6, #0x48]
 *   @0x1e5d04 add r4, r4, #1
 *   @0x1e5d08 mov r0, r7
 *   @0x1e5d0c ldr r1, [r3, r1, lsl #2]
 *   @0x1e5d10 bl 0x1672d0 <_ZN9CBitmap3218SetAlphaFromBitmapEPS_>
 *   @0x1e5d14 ldr r3, [r5, #0x18]
 *   @0x1e5d18 cmp r3, r4
 *   @0x1e5d1c bgt 0x1e5cec <_ZN7CSprite18SetAlphaFromSpriteEPS_+0x5c>
 *   @0x1e5d20 mov r0, r5
 *   @0x1e5d24 bl 0x1e5748 <_ZN7CSprite11InitTextureEv>
 *   @0x1e5d28 mov r0, r5
 *   @0x1e5d2c pop {r3, r4, r5, r6, r7, lr}
 *   @0x1e5d30 b 0x1e5854 <_ZN7CSprite12InitLocalTPEEv>
 *   @0x1e5d34 ldr r0, [pc, #0x20]
 *   @0x1e5d38 mov r1, r3
 *   @0x1e5d3c pop {r3, r4, r5, r6, r7, lr}
 *   @0x1e5d40 add r0, pc, r0
 *   @0x1e5d44 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1e5d48 ldr r0, [pc, #0x10]
 *   @0x1e5d4c mov r1, r3
 *   @0x1e5d50 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1e5d54 add r0, pc, r0
 *   @0x1e5d58 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1e5d5c andseq r12, r6, r0, lsl #16
 *   @0x1e5d60 mulseq r6, r4, r7
 *
 * ══ §41/146 INITIALIZE_Variable_BuiltIn()  0x1ffbd0  size 212  53 条（0x1ffbd0..0x1ffca4）
 * @func 0x1ffbd0 0x1ffca4  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65b0×2 / operator new(unsigned int) / MemoryManager::Alloc(unsigned int, char const*, int, bool) / INITIALIZE_Variable_BuiltIn()+0x98 / InitLocalVariables()
 * 字段偏移 top8: 0x10×3 / 0x8×2 / 0xb4×1 / 0x4×1 / 0x2c×1 / 0x28×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1ffbd0 push {r3, r4, r5, lr}
 *   @0x1ffbd4 mov r0, #20
 *   @0x1ffbd8 bl 0x27c524 <_Znwj>
 *   @0x1ffbdc ldr r1, [pc, #0xb4]
 *   @0x1ffbe0 mov r5, #0
 *   @0x1ffbe4 mov r2, #128
 *   @0x1ffbe8 mov r3, #127
 *   @0x1ffbec add r1, pc, r1
 *   @0x1ffbf0 mov r4, r0
 *   @0x1ffbf4 str r2, [r0]
 *   @0x1ffbf8 str r3, [r4, #0x8]
 *   @0x1ffbfc mov r2, #70
 *   @0x1ffc00 mov r3, #1
 *   @0x1ffc04 mov r0, #1536
 *   @0x1ffc08 str r5, [r4, #0x10]
 *   @0x1ffc0c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1ffc10 mov r2, #1536
 *   @0x1ffc14 mov r1, r5
 *   @0x1ffc18 str r0, [r4, #0x10]
 *   @0x1ffc1c bl 0xb65b0 <memset@plt>
 *   @0x1ffc20 ldr r2, [r4]
 *   @0x1ffc24 vldr s15, [pc, #104]
 *   @0x1ffc28 str r5, [r4, #0x4]
 *   @0x1ffc2c cmp r2, r5
 *   @0x1ffc30 vmov s13, r2
 *   @0x1ffc34 vcvt.f32.s32 s14, s13
 *   @0x1ffc38 vmul.f32 s15, s14, s15
 *   @0x1ffc3c vcvt.s32.f32 s15, s15
 *   @0x1ffc40 vstr s15, [r4, #12]
 *   @0x1ffc44 ble 0x1ffc68 <_Z27INITIALIZE_Variable_BuiltInv+0x98>
 *   @0x1ffc48 add r2, r2, r2, lsl #1
 *   @0x1ffc4c ldr r3, [r4, #0x10]
 *   @0x1ffc50 mov r1, r5
 *   @0x1ffc54 add r2, r3, r2, lsl #2
 *   @0x1ffc58 str r1, [r3, #0x8]
 *   @0x1ffc5c add r3, r3, #12
 *   @0x1ffc60 cmp r3, r2
 *   @0x1ffc64 bne 0x1ffc58 <_Z27INITIALIZE_Variable_BuiltInv+0x88>
 *   @0x1ffc68 ldr r3, [pc, #0x2c]
 *   @0x1ffc6c mov r1, #0
 *   @0x1ffc70 ldr r0, [pc, #0x28]
 *   @0x1ffc74 mov r2, #8000
 *   @0x1ffc78 ldr r3, [pc, r3]
 *   @0x1ffc7c ldr r0, [pc, r0]
 *   @0x1ffc80 str r4, [r3]
 *   @0x1ffc84 bl 0xb65b0 <memset@plt>
 *   @0x1ffc88 bl 0x1fed5c <_Z18InitLocalVariablesv>
 *   @0x1ffc8c pop {r3, r4, r5, lr}
 *   @0x1ffc90 b 0x1fd184 <_Z19InitGlobalVariablesv>
 *   @0x1ffc94 svclo #0x19999a
 *   @0x1ffc98 andseq r1, r3, r4, asr #8
 *   @0x1ffc9c ldrheq r1, [pc], -r4
 *   @0x1ffca0 ldrheq sp, [lr], -r12
 *
 * ══ §42/146 CPhysicsWorld::GetFreeParticleGroupSlot()  0x239c5c  size 212  53 条（0x239c5c..0x239d30）
 * @func 0x239c5c 0x239d30  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsWorld::GetFreeParticleGroupSlot()+0x4c / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x4c×3 / 0x48×3 / 0x4×1 / 0x78×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x239c5c push {r4, r5, r6, lr}
 *   @0x239c60 mov r5, r0
 *   @0x239c64 ldr r4, [r0, #0x4c]
 *   @0x239c68 sub sp, sp, #8
 *   @0x239c6c ldr r0, [r0, #0x48]
 *   @0x239c70 cmp r4, #0
 *   @0x239c74 ble 0x239ca8 <_ZN13CPhysicsWorld24GetFreeParticleGroupSlotEv+0x4c>
 *   @0x239c78 ldr r3, [r0]
 *   @0x239c7c cmp r3, #0
 *   @0x239c80 beq 0x239d20 <_ZN13CPhysicsWorld24GetFreeParticleGroupSlotEv+0xc4>
 *   @0x239c84 mov r2, r0
 *   @0x239c88 mov r3, #0
 *   @0x239c8c b 0x239c9c <_ZN13CPhysicsWorld24GetFreeParticleGroupSlotEv+0x40>
 *   @0x239c90 ldr r1, [r2, #0x4]!
 *   @0x239c94 cmp r1, #0
 *   @0x239c98 beq 0x239d20 <_ZN13CPhysicsWorld24GetFreeParticleGroupSlotEv+0xc4>
 *   @0x239c9c add r3, r3, #1
 *   @0x239ca0 cmp r3, r4
 *   @0x239ca4 bne 0x239c90 <_ZN13CPhysicsWorld24GetFreeParticleGroupSlotEv+0x34>
 *   @0x239ca8 add r1, r4, #1
 *   @0x239cac ldr r2, [pc, #0x78]
 *   @0x239cb0 mov r6, #0
 *   @0x239cb4 mov r3, #1344
 *   @0x239cb8 add r1, r1, r1, lsl #1
 *   @0x239cbc str r6, [sp]
 *   @0x239cc0 add r2, pc, r2
 *   @0x239cc4 add r1, r1, r1, lsr #31
 *   @0x239cc8 asr r1, r1, #1
 *   @0x239ccc str r1, [r5, #0x4c]
 *   @0x239cd0 lsl r1, r1, #2
 *   @0x239cd4 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x239cd8 ldr r12, [r5, #0x4c]
 *   @0x239cdc cmp r4, r12
 *   @0x239ce0 str r0, [r5, #0x48]
 *   @0x239ce4 bge 0x239d14 <_ZN13CPhysicsWorld24GetFreeParticleGroupSlotEv+0xb8>
 *   @0x239ce8 mov r3, r0
 *   @0x239cec lsl r1, r4, #2
 *   @0x239cf0 mov r0, r6
 *   @0x239cf4 mov r2, r4
 *   @0x239cf8 b 0x239d00 <_ZN13CPhysicsWorld24GetFreeParticleGroupSlotEv+0xa4>
 *   @0x239cfc ldr r3, [r5, #0x48]
 *   @0x239d00 add r2, r2, #1
 *   @0x239d04 str r0, [r3, r1]
 *   @0x239d08 cmp r2, r12
 *   @0x239d0c add r1, r1, #4
 *   @0x239d10 bne 0x239cfc <_ZN13CPhysicsWorld24GetFreeParticleGroupSlotEv+0xa0>
 *   @0x239d14 mov r0, r4
 *   @0x239d18 add sp, sp, #8
 *   @0x239d1c pop {r4, r5, r6, pc}
 *   @0x239d20 mov r0, r3
 *   @0x239d24 add sp, sp, #8
 *   @0x239d28 pop {r4, r5, r6, pc}
 *   @0x239d2c andseq r11, r1, r8, lsr #12
 *
 * ══ §43/146 CPhysicsWorld::DeleteParticlePolyRegion(float*, int)  0x23a08c  size 212  53 条（0x23a08c..0x23a160）
 * @func 0x23a08c 0x23a160  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsWorld::DeleteParticlePolyRegion(float*, int)+0x5c / b2PolygonShape::Set(b2Vec2 const*, int) / b2World::DestroyParticlesInShape(b2Shape const&, b2Transform const&, bool)
 * 字段偏移 top8: 0x68×1 / 0x54×1 / 0x50×1 / 0xe4×1 / 0x5c×1 / 0x58×1 / 0x60×1 / 0x10×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23a08c cmp r2, #8
 *   @0x23a090 movge r2, #8
 *   @0x23a094 mov r12, r1
 *   @0x23a098 cmp r2, #0
 *   @0x23a09c push {r4, r5, r6, r7, lr}
 *   @0x23a0a0 sub sp, sp, #236
 *   @0x23a0a4 mov r6, r0
 *   @0x23a0a8 add r1, sp, #16
 *   @0x23a0ac ble 0x23a0e8 <_ZN13CPhysicsWorld24DeleteParticlePolyRegionEPfi+0x5c>
 *   @0x23a0b0 add r12, r12, #4
 *   @0x23a0b4 add lr, r1, r2, lsl #3
 *   @0x23a0b8 mov r3, r1
 *   @0x23a0bc vldr s15, [r0, #96]
 *   @0x23a0c0 vldr s13, [r12]
 *   @0x23a0c4 vldr s14, [r12, #-4]
 *   @0x23a0c8 vmul.f32 s13, s15, s13
 *   @0x23a0cc add r3, r3, #8
 *   @0x23a0d0 add r12, r12, #8
 *   @0x23a0d4 vmul.f32 s14, s14, s15
 *   @0x23a0d8 vstr s13, [r3, #-4]
 *   @0x23a0dc vstr s14, [r3, #-8]
 *   @0x23a0e0 cmp r3, lr
 *   @0x23a0e4 bne 0x23a0c0 <_ZN13CPhysicsWorld24DeleteParticlePolyRegionEPfi+0x34>
 *   @0x23a0e8 add r7, sp, #80
 *   @0x23a0ec ldr r3, [pc, #0x68]
 *   @0x23a0f0 mov r5, #0
 *   @0x23a0f4 mov r4, #0
 *   @0x23a0f8 mov r0, r7
 *   @0x23a0fc ldr r3, [pc, r3]
 *   @0x23a100 mov r12, #2
 *   @0x23a104 add r3, r3, #8
 *   @0x23a108 str r12, [sp, #0x54]
 *   @0x23a10c str r3, [sp, #0x50]
 *   @0x23a110 movw r3, #0xd70a
 *   @0x23a114 str r5, [sp, #0xe4]
 *   @0x23a118 movt r3, #0x3c23
 *   @0x23a11c str r4, [sp, #0x5c]
 *   @0x23a120 str r3, [sp, #0x58]
 *   @0x23a124 str r4, [sp, #0x60]
 *   @0x23a128 bl 0x2c6028 <_ZN14b2PolygonShape3SetEPK6b2Vec2i>
 *   @0x23a12c mov r1, r7
 *   @0x23a130 mov r3, r5
 *   @0x23a134 ldr r0, [r6, #0x10]
 *   @0x23a138 mov r2, sp
 *   @0x23a13c mov r12, #1065353216
 *   @0x23a140 str r4, [sp]
 *   @0x23a144 str r4, [sp, #0x4]
 *   @0x23a148 str r4, [sp, #0x8]
 *   @0x23a14c str r12, [sp, #0xc]
 *   @0x23a150 bl 0x2cb4d8 <_ZN7b2World23DestroyParticlesInShapeERK7b2ShapeRK11b2Transformb>
 *   @0x23a154 add sp, sp, #236
 *   @0x23a158 pop {r4, r5, r6, r7, pc}
 *   @0x23a15c ldrheq r7, [r11], -r4
 *
 * ══ §44/146 JS_SameValue(RValue*, RValue*)  0x24089c  size 212  53 条（0x24089c..0x240970）
 * @func 0x24089c 0x240970  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6574
 * 字段偏移 top8: 0xc×2 / 0x4×2
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24089c push {r3, r4, r5, lr}
 *   @0x2408a0 ldr r2, [r1, #0xc]
 *   @0x2408a4 ldr r3, [r0, #0xc]
 *   @0x2408a8 eor r2, r3, r2
 *   @0x2408ac bic r2, r2, #-16777216
 *   @0x2408b0 cmp r2, #0
 *   @0x2408b4 bne 0x2408fc <_Z12JS_SameValueP6RValueS0_+0x60>
 *   @0x2408b8 bic r3, r3, #-16777216
 *   @0x2408bc cmp r3, #12
 *   @0x2408c0 addls pc, pc, r3, lsl #2
 *   @0x2408c4 b 0x2408fc <_Z12JS_SameValueP6RValueS0_+0x60>
 *   @0x2408c8 b 0x24091c <_Z12JS_SameValueP6RValueS0_+0x80>
 *   @0x2408cc b 0x240948 <_Z12JS_SameValueP6RValueS0_+0xac>
 *   @0x2408d0 b 0x2408fc <_Z12JS_SameValueP6RValueS0_+0x60>
 *   @0x2408d4 b 0x2408fc <_Z12JS_SameValueP6RValueS0_+0x60>
 *   @0x2408d8 b 0x2408fc <_Z12JS_SameValueP6RValueS0_+0x60>
 *   @0x2408dc b 0x240968 <_Z12JS_SameValueP6RValueS0_+0xcc>
 *   @0x2408e0 b 0x240904 <_Z12JS_SameValueP6RValueS0_+0x68>
 *   @0x2408e4 b 0x24091c <_Z12JS_SameValueP6RValueS0_+0x80>
 *   @0x2408e8 b 0x2408fc <_Z12JS_SameValueP6RValueS0_+0x60>
 *   @0x2408ec b 0x2408fc <_Z12JS_SameValueP6RValueS0_+0x60>
 *   @0x2408f0 b 0x24091c <_Z12JS_SameValueP6RValueS0_+0x80>
 *   @0x2408f4 b 0x2408fc <_Z12JS_SameValueP6RValueS0_+0x60>
 *   @0x2408f8 b 0x240968 <_Z12JS_SameValueP6RValueS0_+0xcc>
 *   @0x2408fc mov r0, #0
 *   @0x240900 pop {r3, r4, r5, pc}
 *   @0x240904 ldr r0, [r0]
 *   @0x240908 ldr r3, [r1]
 *   @0x24090c subs r3, r0, r3
 *   @0x240910 rsbs r0, r3, #0
 *   @0x240914 adcs r0, r0, r3
 *   @0x240918 pop {r3, r4, r5, pc}
 *   @0x24091c ldr r4, [r0]
 *   @0x240920 ldr r5, [r0, #0x4]
 *   @0x240924 ldr r2, [r1]
 *   @0x240928 ldr r3, [r1, #0x4]
 *   @0x24092c vmov d6, r4, r5
 *   @0x240930 vmov d7, r2, r3
 *   @0x240934 vcmp.f64 d6, d7
 *   @0x240938 vmrs APSR_nzcv, fpscr
 *   @0x24093c movne r0, #0
 *   @0x240940 moveq r0, #1
 *   @0x240944 pop {r3, r4, r5, pc}
 *   @0x240948 ldr r2, [r0]
 *   @0x24094c ldr r3, [r1]
 *   @0x240950 ldr r0, [r2]
 *   @0x240954 ldr r1, [r3]
 *   @0x240958 bl 0xb6574 <strcmp@plt>
 *   @0x24095c rsbs r0, r0, #1
 *   @0x240960 movlo r0, #0
 *   @0x240964 pop {r3, r4, r5, pc}
 *   @0x240968 mov r0, #1
 *   @0x24096c pop {r3, r4, r5, pc}
 *
 * ══ §45/146 F_JS_Object_defineProperty(RValue&, CInstance*, CInstance*, int, RValue*)  0x255170  size 212  53 条（0x255170..0x255244）
 * @func 0x255170 0x255244  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JSThrowTypeError(char const*) / F_JS_ToString(RValue&, RValue*) / F_JS_ToPropertyDescriptor(RValue*, RValue*) / JS_DefineOwnPropertyRV(YYObjectBase*, RValue*, RValue*, bool)
 * 字段偏移 top8: 0xc×4 / 0x8×3 / 0x4×2 / 0x48×1 / 0xa0×1 / 0x18×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x255170 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x255174 cmp r3, #0
 *   @0x255178 sub sp, sp, #36
 *   @0x25517c mov r7, r0
 *   @0x255180 ldr r6, [sp, #0x48]
 *   @0x255184 beq 0x255198 <_Z26F_JS_Object_definePropertyR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x255188 ldr r3, [r6, #0xc]
 *   @0x25518c bic r3, r3, #-16777216
 *   @0x255190 cmp r3, #6
 *   @0x255194 beq 0x2551ac <_Z26F_JS_Object_definePropertyR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x255198 ldr r0, [pc, #0xa0]
 *   @0x25519c add r0, pc, r0
 *   @0x2551a0 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x2551a4 add sp, sp, #36
 *   @0x2551a8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2551ac add r1, r6, #16
 *   @0x2551b0 mov r0, sp
 *   @0x2551b4 mov r4, #0
 *   @0x2551b8 mov r5, #0
 *   @0x2551bc mov r9, #0
 *   @0x2551c0 strd r4, r5, [sp]
 *   @0x2551c4 str r9, [sp, #0x8]
 *   @0x2551c8 mvn r8, #-16777216
 *   @0x2551cc str r8, [sp, #0xc]
 *   @0x2551d0 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x2551d4 cmp r0, #1
 *   @0x2551d8 beq 0x255198 <_Z26F_JS_Object_definePropertyR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x2551dc add r11, sp, #16
 *   @0x2551e0 add r1, r6, #32
 *   @0x2551e4 strd r4, r5, [sp, #16]
 *   @0x2551e8 mov r0, r11
 *   @0x2551ec str r9, [sp, #0x18]
 *   @0x2551f0 str r8, [sp, #0x1c]
 *   @0x2551f4 bl 0x24195c <_Z25F_JS_ToPropertyDescriptorP6RValueS0_>
 *   @0x2551f8 cmp r0, #1
 *   @0x2551fc beq 0x255198 <_Z26F_JS_Object_definePropertyR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x255200 mov r1, sp
 *   @0x255204 mov r2, r11
 *   @0x255208 ldr r0, [r6]
 *   @0x25520c mov r3, #1
 *   @0x255210 bl 0x248610 <_Z22JS_DefineOwnPropertyRVP12YYObjectBaseP6RValueS2_b>
 *   @0x255214 cmp r0, #2
 *   @0x255218 beq 0x255198 <_Z26F_JS_Object_definePropertyR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x25521c ldr r0, [r6]
 *   @0x255220 ldr r1, [r6, #0x4]
 *   @0x255224 ldr r2, [r6, #0x8]
 *   @0x255228 ldr r3, [r6, #0xc]
 *   @0x25522c str r0, [r7]
 *   @0x255230 str r1, [r7, #0x4]
 *   @0x255234 str r2, [r7, #0x8]
 *   @0x255238 str r3, [r7, #0xc]
 *   @0x25523c b 0x2551a4 <_Z26F_JS_Object_definePropertyR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x255240 andseq r0, r0, r12, lsr #27
 *
 * ══ §46/146 pcre_get_stringnumber  0x25f148  size 212  53 条（0x25f148..0x25f21c）
 * @func 0x25f148 0x25f21c  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: pcre_fullinfo×3 / pcre_get_stringnumber+0xbc / 0xb6574 / pcre_get_stringnumber+0x84
 * 字段偏移 top8: 0x8×2 / 0xc×1 / 0x4×1 / 0x1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x25f148 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x25f14c sub sp, sp, #16
 *   @0x25f150 mov r2, #8
 *   @0x25f154 mov r7, r1
 *   @0x25f158 add r3, sp, r2
 *   @0x25f15c mov r1, #0
 *   @0x25f160 mov r4, r0
 *   @0x25f164 bl 0x25ee20 <pcre_fullinfo>
 *   @0x25f168 subs r1, r0, #0
 *   @0x25f16c bne 0x25f194 <pcre_get_stringnumber+0x4c>
 *   @0x25f170 ldr r3, [sp, #0x8]
 *   @0x25f174 cmp r3, #0
 *   @0x25f178 ble 0x25f204 <pcre_get_stringnumber+0xbc>
 *   @0x25f17c mov r0, r4
 *   @0x25f180 mov r2, #7
 *   @0x25f184 add r3, sp, #4
 *   @0x25f188 bl 0x25ee20 <pcre_fullinfo>
 *   @0x25f18c subs r1, r0, #0
 *   @0x25f190 beq 0x25f1a0 <pcre_get_stringnumber+0x58>
 *   @0x25f194 mov r0, r1
 *   @0x25f198 add sp, sp, #16
 *   @0x25f19c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x25f1a0 mov r0, r4
 *   @0x25f1a4 mov r2, #9
 *   @0x25f1a8 add r3, sp, #12
 *   @0x25f1ac bl 0x25ee20 <pcre_fullinfo>
 *   @0x25f1b0 cmp r0, #0
 *   @0x25f1b4 bne 0x25f198 <pcre_get_stringnumber+0x50>
 *   @0x25f1b8 mov r5, r0
 *   @0x25f1bc ldr r6, [sp, #0x8]
 *   @0x25f1c0 ldr r9, [sp, #0xc]
 *   @0x25f1c4 ldr r8, [sp, #0x4]
 *   @0x25f1c8 b 0x25f1f0 <pcre_get_stringnumber+0xa8>
 *   @0x25f1cc asr r4, r4, #1
 *   @0x25f1d0 mla r10, r4, r8, r9
 *   @0x25f1d4 add r1, r10, #2
 *   @0x25f1d8 bl 0xb6574 <strcmp@plt>
 *   @0x25f1dc cmp r0, #0
 *   @0x25f1e0 beq 0x25f20c <pcre_get_stringnumber+0xc4>
 *   @0x25f1e4 addgt r5, r4, #1
 *   @0x25f1e8 movle r6, r4
 *   @0x25f1ec strle r4, [sp, #0x8]
 *   @0x25f1f0 add r4, r5, r6
 *   @0x25f1f4 cmp r5, r6
 *   @0x25f1f8 mov r0, r7
 *   @0x25f1fc add r4, r4, r4, lsr #31
 *   @0x25f200 blt 0x25f1cc <pcre_get_stringnumber+0x84>
 *   @0x25f204 mvn r0, #6
 *   @0x25f208 b 0x25f198 <pcre_get_stringnumber+0x50>
 *   @0x25f20c ldrb r0, [r10]
 *   @0x25f210 ldrb r3, [r10, #0x1]
 *   @0x25f214 orr r0, r3, r0, lsl #8
 *   @0x25f218 b 0x25f198 <pcre_get_stringnumber+0x50>
 *
 * ══ §47/146 CLangMan::SetActiveLanguage(char*, char*)  0x27a73c  size 212  53 条（0x27a73c..0x27a810）
 * @func 0x27a73c 0x27a810  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6574×2 / CLangMan::SetActiveLanguage(char*, char*)+0xc0
 * 字段偏移 top8: 0xa0×1 / 0x8c×1 / 0x4×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27a73c cmp r1, #0
 *   @0x27a740 cmpne r0, #0
 *   @0x27a744 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x27a748 mov r8, r0
 *   @0x27a74c mov r9, r1
 *   @0x27a750 movne r4, #0
 *   @0x27a754 moveq r4, #1
 *   @0x27a758 popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x27a75c ldr r3, [pc, #0xa0]
 *   @0x27a760 ldr r3, [pc, r3]
 *   @0x27a764 ldr r10, [r3]
 *   @0x27a768 cmp r10, #0
 *   @0x27a76c popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x27a770 ble 0x27a7fc <_ZN8CLangMan17SetActiveLanguageEPcS0_+0xc0>
 *   @0x27a774 ldr r3, [pc, #0x8c]
 *   @0x27a778 mov r5, r4
 *   @0x27a77c mvn r6, #0
 *   @0x27a780 ldr r3, [pc, r3]
 *   @0x27a784 ldr r7, [r3]
 *   @0x27a788 ldr r1, [r7, r4]
 *   @0x27a78c mov r0, r8
 *   @0x27a790 bl 0xb6574 <strcmp@plt>
 *   @0x27a794 add r3, r7, r4
 *   @0x27a798 add r4, r4, #12
 *   @0x27a79c cmp r0, #0
 *   @0x27a7a0 mov r0, r9
 *   @0x27a7a4 bne 0x27a7d0 <_ZN8CLangMan17SetActiveLanguageEPcS0_+0x94>
 *   @0x27a7a8 ldr r11, [r3, #0x4]
 *   @0x27a7ac cmn r6, #1
 *   @0x27a7b0 moveq r6, r5
 *   @0x27a7b4 mov r1, r11
 *   @0x27a7b8 bl 0xb6574 <strcmp@plt>
 *   @0x27a7bc cmp r0, #0
 *   @0x27a7c0 beq 0x27a7f4 <_ZN8CLangMan17SetActiveLanguageEPcS0_+0xb8>
 *   @0x27a7c4 ldrb r3, [r11]
 *   @0x27a7c8 cmp r3, #0
 *   @0x27a7cc moveq r6, r5
 *   @0x27a7d0 add r5, r5, #1
 *   @0x27a7d4 cmp r5, r10
 *   @0x27a7d8 bne 0x27a788 <_ZN8CLangMan17SetActiveLanguageEPcS0_+0x4c>
 *   @0x27a7dc cmn r6, #1
 *   @0x27a7e0 moveq r6, #0
 *   @0x27a7e4 ldr r3, [pc, #0x20]
 *   @0x27a7e8 ldr r3, [pc, r3]
 *   @0x27a7ec str r6, [r3]
 *   @0x27a7f0 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x27a7f4 mov r6, r5
 *   @0x27a7f8 b 0x27a7e4 <_ZN8CLangMan17SetActiveLanguageEPcS0_+0xa8>
 *   @0x27a7fc mov r6, r4
 *   @0x27a800 b 0x27a7e4 <_ZN8CLangMan17SetActiveLanguageEPcS0_+0xa8>
 *   @0x27a804 andseq r7, r7, r8, lsr #1
 *   @0x27a808 mulseq r7, r0, r0
 *   @0x27a80c andseq r7, r7, r0, lsr r0
 *
 * ══ §48/146 DbgServer::Init()  0x29cf64  size 212  53 条（0x29cf64..0x29d038）
 * @func 0x29cf64 0x29d038  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: yyServer::Init(eSocketType, int, int, bool)
 * 字段偏移 top8: 0xc×2 / 0xb0×1 / 0xac×1 / 0xa4×1 / 0x40×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29cf64 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x29cf68 sub sp, sp, #8
 *   @0x29cf6c ldr r7, [pc, #0xb0]
 *   @0x29cf70 mov r10, r0
 *   @0x29cf74 ldr r3, [pc, #0xac]
 *   @0x29cf78 mov r5, #5
 *   @0x29cf7c ldr r7, [pc, r7]
 *   @0x29cf80 ldr r9, [pc, #0xa4]
 *   @0x29cf84 ldr r3, [pc, r3]
 *   @0x29cf88 mov r8, #1
 *   @0x29cf8c ldr r4, [r7]
 *   @0x29cf90 add r9, pc, r9
 *   @0x29cf94 ldr r6, [r3]
 *   @0x29cf98 ldr r3, [r6]
 *   @0x29cf9c mov r0, r6
 *   @0x29cfa0 mov r1, r9
 *   @0x29cfa4 mov r2, r4
 *   @0x29cfa8 ldr r3, [r3, #0xc]
 *   @0x29cfac blx r3
 *   @0x29cfb0 ldr r0, [r10]
 *   @0x29cfb4 mov r1, #0
 *   @0x29cfb8 str r8, [sp]
 *   @0x29cfbc mov r2, r4
 *   @0x29cfc0 mov r3, #1
 *   @0x29cfc4 bl 0x2971e0 <_ZN8yyServer4InitE11eSocketTypeiib>
 *   @0x29cfc8 cmp r0, #0
 *   @0x29cfcc beq 0x29cfe8 <_ZN9DbgServer4InitEv+0x84>
 *   @0x29cfd0 subs r5, r5, #1
 *   @0x29cfd4 beq 0x29d018 <_ZN9DbgServer4InitEv+0xb4>
 *   @0x29cfd8 ldr r4, [r7]
 *   @0x29cfdc add r4, r4, #1
 *   @0x29cfe0 str r4, [r7]
 *   @0x29cfe4 b 0x29cf98 <_ZN9DbgServer4InitEv+0x34>
 *   @0x29cfe8 ldr r3, [pc, #0x40]
 *   @0x29cfec mov r2, r4
 *   @0x29cff0 ldr r1, [pc, #0x3c]
 *   @0x29cff4 ldr r3, [pc, r3]
 *   @0x29cff8 add r1, pc, r1
 *   @0x29cffc ldr r0, [r3]
 *   @0x29d000 ldr r3, [r0]
 *   @0x29d004 ldr r3, [r3, #0xc]
 *   @0x29d008 blx r3
 *   @0x29d00c mov r0, #1
 *   @0x29d010 add sp, sp, #8
 *   @0x29d014 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x29d018 mov r0, r5
 *   @0x29d01c add sp, sp, #8
 *   @0x29d020 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x29d024 andseq r3, r5, r8, asr sp
 *   @0x29d028 mulseq r5, r0, r7
 *   @0x29d02c muleq r11, r0, r11
 *   @0x29d030 andseq r0, r5, r12, asr #18
 *   @0x29d034 andeq r12, r11, r12, asr #22
 *
 * ══ §49/146 png_write_tRNS  0x2b1d80  size 212  53 条（0x2b1d80..0x2b1e54）
 * @func 0x2b1d80 0x2b1e64  size 228  57 条
 * 部分覆盖: 本节 57/102 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 56/101 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 55/99 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 54/97 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_save_uint_16×4 / png_write_tRNS+0x2e / png_write_tRNS+0x34 / png_write_chunk / png_warning
 * 字段偏移 top8: 0xb8×1 / 0x3a×1 / 0x78×1 / 0x2×1 / 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b1d80 push {r4, r5, r6, r7, lr}
 *   @0x2b1d84 ldr r2, [pc, #0xb8]
 *   @0x2b1d88 mov r4, r0
 *   @0x2b1d8c add r2, pc
 *   @0x2b1d90 ldr r0, [r2, #58]!
 *   @0x2b1d94 cmp r5, #0x3
 *   @0x2b1d98 str r0, [sp]
 *   @0x2b1d9c .word 0xd10c2004
 *   @0x2b1da0 cmp r3, #0x0
 *   @0x2b1da4 ble 0x2b1dae <png_write_tRNS+0x2e>
 *   @0x2b1da8 addsmi r2, r3, #220, #2
 *   @0x2b1dac ble 0x2b1db4 <png_write_tRNS+0x34>
 *   @0x2b1db0 add r1, pc
 *   @0x2b1db4 mov r1, sp
 *   @0x2b1db8 b 0x2b1e2c <png_write_tRNS+0xac>
 *   @0x2b1dbc ldrb.w r3, [r4, #0x1eb]
 *   @0x2b1dc0 movs r2, #0x1
 *   @0x2b1dc4 lsl.w r3, r2, r3
 *   @0x2b1dc8 cmp r1, r3
 *   @0x2b1dcc ldr r1, [pc, #0x78]
 *   @0x2b1dd0 add r1, pc
 *   @0x2b1dd4 add r5, sp, #0x8
 *   @0x2b1dd8 bl 0x2b1138 <png_save_uint_16>
 *   @0x2b1ddc mov r0, r4
 *   @0x2b1de0 mov r2, r5
 *   @0x2b1de4 b 0x2b1e2c <png_write_tRNS+0xac>
 *   @0x2b1de8 bne 0x2b1e32 <png_write_tRNS+0xb2>
 *   @0x2b1dec ldrh r1, [r6, #0x2]
 *   @0x2b1df0 bl 0x2b1138 <png_save_uint_16>
 *   @0x2b1df4 adds r0, r5, #0x2
 *   @0x2b1df8 bl 0x2b1138 <png_save_uint_16>
 *   @0x2b1dfc adds r0, r5, #0x4
 *   @0x2b1e00 bl 0x2b1138 <png_save_uint_16>
 *   @0x2b1e04 ldrb.w r3, [r4, #0x1eb]
 *   @0x2b1e08 mov r0, r4
 *   @0x2b1e0c bne 0x2b1e26 <png_write_tRNS+0xa6>
 *   @0x2b1e10 .word 0xf89d3008
 *   @0x2b1e14 tstmi r10, #10
 *   @0x2b1e18 ldrb.w r3, [sp, #0xc]
 *   @0x2b1e1c orrs r3, r2
 *   @0x2b1e20 ldr r1, [pc, #0x28]
 *   @0x2b1e24 b 0x2b1e38 <png_write_tRNS+0xb8>
 *   @0x2b1e28 mov r2, r5
 *   @0x2b1e2c bl 0x2b12bc <png_write_chunk>
 *   @0x2b1e30 b 0x2b1e3c <png_write_tRNS+0xbc>
 *   @0x2b1e34 mov r0, r4
 *   @0x2b1e38 bl 0x2a6474 <png_warning>
 *   @0x2b1e3c add sp, #0x14
 *   @0x2b1e40 svc #0xd4
 *   @0x2b1e44 stm r6!, {r0, r1, r2, r5, r6, r7}
 *   @0x2b1e48 stm r6!, {r1, r2, r4, r5, r6, r7}
 *   @0x2b1e4c stm r6!, {r2, r5, r6, r7}
 *   @0x2b1e50 stm r7!, {r4}
 *
 * ══ §50/146 png_write_bKGD  0x2b1e54  size 212  53 条（0x2b1e54..0x2b1f28）
 * @func 0x2b1e54 0x2b1f28  size 212  53 条
 * 部分覆盖: 本节 53/97 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_save_uint_16×3 / png_write_bKGD+0xaa / png_warning
 * 字段偏移 top8: 0xc0×1 / 0x3f×1 / 0x94×1 / 0x2×1 / 0x48×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b1e54 ldr r3, [pc, #0xc0]
 *   @0x2b1e58 push {r4, r5, r6, r7, lr}
 *   @0x2b1e5c mov r4, r0
 *   @0x2b1e60 ldr r0, [r3, #63]!
 *   @0x2b1e64 mov r5, r1
 *   @0x2b1e68 str r0, [sp]
 *   @0x2b1e6c tstle r4, r4
 *   @0x2b1e70 ldrh.w r2, [r4, #0x1dc]
 *   @0x2b1e74 ldrb r3, [r1]
 *   @0x2b1e78 ldr.w r1, [r4, #0x2dc]
 *   @0x2b1e7c lsls r1, r1, #0x1f
 *   @0x2b1e80 cmp r3, r2
 *   @0x2b1e84 ldr r1, [pc, #0x94]
 *   @0x2b1e88 add r1, pc
 *   @0x2b1e8c add r2, sp, #0x10
 *   @0x2b1e90 mov r1, sp
 *   @0x2b1e94 movwhs r3, #0x1d08
 *   @0x2b1e98 b 0x2b1f0e <png_write_bKGD+0xba>
 *   @0x2b1e9c bpl 0x2b1ee2 <png_write_bKGD+0x8e>
 *   @0x2b1ea0 ldrh r1, [r1, #0x2]
 *   @0x2b1ea4 bl 0x2b1138 <png_save_uint_16>
 *   @0x2b1ea8 adds r0, r6, #0x2
 *   @0x2b1eac bl 0x2b1138 <png_save_uint_16>
 *   @0x2b1eb0 adds r0, r6, #0x4
 *   @0x2b1eb4 bl 0x2b1138 <png_save_uint_16>
 *   @0x2b1eb8 ldrb.w r3, [r4, #0x1eb]
 *   @0x2b1ebc mov r0, r4
 *   @0x2b1ec0 bne 0x2b1eda <png_write_bKGD+0x86>
 *   @0x2b1ec4 .word 0xf89d3008
 *   @0x2b1ec8 tstmi r10, #10
 *   @0x2b1ecc ldrb.w r3, [sp, #0xc]
 *   @0x2b1ed0 orrs r3, r2
 *   @0x2b1ed4 ldr r1, [pc, #0x48]
 *   @0x2b1ed8 b 0x2b1ef8 <png_write_bKGD+0xa4>
 *   @0x2b1edc mov r2, r6
 *   @0x2b1ee0 b 0x2b1f0e <png_write_bKGD+0xba>
 *   @0x2b1ee4 andhs r3, r1, #-1073741766
 *   @0x2b1ee8 ldrh r1, [r1, #0x8]
 *   @0x2b1eec addsmi pc, r9, #201326592
 *   @0x2b1ef0 blt 0x2b1efe <png_write_bKGD+0xaa>
 *   @0x2b1ef4 mov r0, r4
 *   @0x2b1ef8 bl 0x2a6474 <png_warning>
 *   @0x2b1efc b 0x2b1f12 <png_write_bKGD+0xbe>
 *   @0x2b1f00 mov r0, r5
 *   @0x2b1f04 qadd16mi pc, r0, r9
 *   @0x2b1f08 mov r1, sp
 *   @0x2b1f0c movs r3, #0x2
 *   @0x2b1f10 .word 0xb005f9d5
 *   @0x2b1f14 pop {r4, r5, r6, r7, pc}
 *   @0x2b1f18 svc #0x6
 *   @0x2b1f1c stm r6!, {r0, r2, r5, r6, r7}
 *   @0x2b1f20 stm r6!, {r3, r4, r5, r7}
 *   @0x2b1f24 stm r6!, {r3, r4, r6, r7}
 *
 * ══ §51/146 DGifGetLZCodes(GifFileType*, int*)  0x2c2844  size 212  53 条（0x2c2844..0x2c2918）
 * @func 0x2c2844 0x2c2918  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2c143c+0x80 / DGifGetCodeNext(GifFileType*, unsigned char**)
 * 字段偏移 top8: 0x48×1 / 0x10×1 / 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c2844 push {r4, r5, r6, lr}
 *   @0x2c2848 mov r4, r0
 *   @0x2c284c ldr r5, [r0, #0x48]
 *   @0x2c2850 sub sp, sp, #8
 *   @0x2c2854 mov r6, r1
 *   @0x2c2858 ldr r3, [r5]
 *   @0x2c285c ands r3, r3, #8
 *   @0x2c2860 moveq r2, #111
 *   @0x2c2864 streq r2, [r0, #0x40]
 *   @0x2c2868 bne 0x2c2878 <_Z14DGifGetLZCodesP11GifFileTypePi+0x34>
 *   @0x2c286c mov r0, r3
 *   @0x2c2870 add sp, sp, #8
 *   @0x2c2874 pop {r4, r5, r6, pc}
 *   @0x2c2878 bl 0x2c14bc <jpeg_mem_term+0x84>
 *   @0x2c287c cmp r0, #0
 *   @0x2c2880 beq 0x2c28f8 <_Z14DGifGetLZCodesP11GifFileTypePi+0xb4>
 *   @0x2c2884 ldr r3, [r6]
 *   @0x2c2888 ldr r2, [r5, #0x10]
 *   @0x2c288c cmp r3, r2
 *   @0x2c2890 beq 0x2c28d0 <_Z14DGifGetLZCodesP11GifFileTypePi+0x8c>
 *   @0x2c2894 ldr r1, [r5, #0xc]
 *   @0x2c2898 cmp r3, r1
 *   @0x2c289c ldreq r1, [r5, #0x8]
 *   @0x2c28a0 moveq r0, #1
 *   @0x2c28a4 moveq r3, r0
 *   @0x2c28a8 movne r3, #1
 *   @0x2c28ac addeq r1, r1, r0
 *   @0x2c28b0 addeq r2, r2, r0
 *   @0x2c28b4 streq r1, [r5, #0x18]
 *   @0x2c28b8 lsleq r1, r0, r1
 *   @0x2c28bc streq r2, [r5, #0x14]
 *   @0x2c28c0 mov r0, r3
 *   @0x2c28c4 streq r1, [r5, #0x1c]
 *   @0x2c28c8 add sp, sp, #8
 *   @0x2c28cc pop {r4, r5, r6, pc}
 *   @0x2c28d0 add r5, sp, #4
 *   @0x2c28d4 b 0x2c28e4 <_Z14DGifGetLZCodesP11GifFileTypePi+0xa0>
 *   @0x2c28d8 ldr r3, [sp, #0x4]
 *   @0x2c28dc cmp r3, #0
 *   @0x2c28e0 beq 0x2c2908 <_Z14DGifGetLZCodesP11GifFileTypePi+0xc4>
 *   @0x2c28e4 mov r0, r4
 *   @0x2c28e8 mov r1, r5
 *   @0x2c28ec bl 0x2c25c0 <_Z15DGifGetCodeNextP11GifFileTypePPh>
 *   @0x2c28f0 cmp r0, #0
 *   @0x2c28f4 bne 0x2c28d8 <_Z14DGifGetLZCodesP11GifFileTypePi+0x94>
 *   @0x2c28f8 mov r3, #0
 *   @0x2c28fc mov r0, r3
 *   @0x2c2900 add sp, sp, #8
 *   @0x2c2904 pop {r4, r5, r6, pc}
 *   @0x2c2908 mvn r2, #0
 *   @0x2c290c mov r3, #1
 *   @0x2c2910 str r2, [r6]
 *   @0x2c2914 b 0x2c286c <_Z14DGifGetLZCodesP11GifFileTypePi+0x28>
 *
 * ══ §52/146 b2Body::SetActive(bool)  0x2c74ac  size 212  53 条（0x2c74ac..0x2c7580）
 * @func 0x2c74ac 0x2c7580  size 212  53 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Fixture::CreateProxies(b2BroadPhase*, b2Transform const&) / b2Fixture::DestroyProxies(b2BroadPhase*) / b2ContactManager::Destroy(b2Contact*)
 * 字段偏移 top8: 0x4×6 / 0x68×3 / 0x80×2 / 0x74×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c74ac ldrh r3, [r0, #4]
 *   @0x2c74b0 push {r4, r5, r6, lr}
 *   @0x2c74b4 ubfx r2, r3, #0x5, #0x1
 *   @0x2c74b8 cmp r1, r2
 *   @0x2c74bc mov r5, r0
 *   @0x2c74c0 popeq {r4, r5, r6, pc}
 *   @0x2c74c4 cmp r1, #0
 *   @0x2c74c8 ldr r4, [r0, #0x74]
 *   @0x2c74cc beq 0x2c7510 <_ZN6b2Body9SetActiveEb+0x64>
 *   @0x2c74d0 ldr r6, [r0, #0x68]
 *   @0x2c74d4 cmp r4, #0
 *   @0x2c74d8 orr r3, r3, #32
 *   @0x2c74dc strh r3, [r0, #4]
 *   @0x2c74e0 add r6, r6, #102400
 *   @0x2c74e4 add r6, r6, #472
 *   @0x2c74e8 popeq {r4, r5, r6, pc}
 *   @0x2c74ec add r5, r0, #12
 *   @0x2c74f0 mov r0, r4
 *   @0x2c74f4 mov r1, r6
 *   @0x2c74f8 mov r2, r5
 *   @0x2c74fc bl 0x2c86e4 <_ZN9b2Fixture13CreateProxiesEP12b2BroadPhaseRK11b2Transform>
 *   @0x2c7500 ldr r4, [r4, #0x4]
 *   @0x2c7504 cmp r4, #0
 *   @0x2c7508 bne 0x2c74f0 <_ZN6b2Body9SetActiveEb+0x44>
 *   @0x2c750c pop {r4, r5, r6, pc}
 *   @0x2c7510 ldr r6, [r0, #0x68]
 *   @0x2c7514 cmp r4, #0
 *   @0x2c7518 bic r3, r3, #32
 *   @0x2c751c strh r3, [r0, #4]
 *   @0x2c7520 add r6, r6, #102400
 *   @0x2c7524 add r6, r6, #472
 *   @0x2c7528 beq 0x2c7544 <_ZN6b2Body9SetActiveEb+0x98>
 *   @0x2c752c mov r0, r4
 *   @0x2c7530 mov r1, r6
 *   @0x2c7534 bl 0x2c8770 <_ZN9b2Fixture14DestroyProxiesEP12b2BroadPhase>
 *   @0x2c7538 ldr r4, [r4, #0x4]
 *   @0x2c753c cmp r4, #0
 *   @0x2c7540 bne 0x2c752c <_ZN6b2Body9SetActiveEb+0x80>
 *   @0x2c7544 ldr r3, [r5, #0x80]
 *   @0x2c7548 cmp r3, #0
 *   @0x2c754c beq 0x2c7574 <_ZN6b2Body9SetActiveEb+0xc8>
 *   @0x2c7550 ldr r0, [r5, #0x68]
 *   @0x2c7554 ldr r4, [r3, #0xc]
 *   @0x2c7558 add r0, r0, #102400
 *   @0x2c755c ldr r1, [r3, #0x4]
 *   @0x2c7560 add r0, r0, #472
 *   @0x2c7564 bl 0x2c7894 <_ZN16b2ContactManager7DestroyEP9b2Contact>
 *   @0x2c7568 cmp r4, #0
 *   @0x2c756c mov r3, r4
 *   @0x2c7570 bne 0x2c7550 <_ZN6b2Body9SetActiveEb+0xa4>
 *   @0x2c7574 mov r3, #0
 *   @0x2c7578 str r3, [r5, #0x80]
 *   @0x2c757c pop {r4, r5, r6, pc}
 *
 * ══ §53/146 F_BUFFER_SetSurface(RValue&, CInstance*, CInstance*, int, RValue*)  0xc6248  size 208  52 条（0xc6248..0xc6318）
 * @func 0xc6248 0xc6318  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×4 / F_BUFFER_SetSurface(RValue&, CInstance*, CInstance*, int, RValue*)+0xa0 / GR_Surface_Exists(int)
 * 字段偏移 top8: 0x4×2 / 0x2×2 / 0x18×1 / 0xa0×1 / 0x44×1 / 0x20×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc6248 push {r4, r5, r6, r7, r8, lr}
 *   @0xc624c mov r1, #0
 *   @0xc6250 ldr r4, [sp, #0x18]
 *   @0xc6254 mov r0, r4
 *   @0xc6258 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc625c subs r5, r0, #0
 *   @0xc6260 blt 0xc62e8 <_Z19F_BUFFER_SetSurfaceR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0xc6264 ldr r6, [pc, #0xa0]
 *   @0xc6268 add r6, pc, r6
 *   @0xc626c ldr r3, [r6]
 *   @0xc6270 cmp r5, r3
 *   @0xc6274 bge 0xc62e8 <_Z19F_BUFFER_SetSurfaceR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0xc6278 ldr r3, [r6, #0x4]
 *   @0xc627c ldr r3, [r3, r5, lsl #2]
 *   @0xc6280 cmp r3, #0
 *   @0xc6284 beq 0xc62e8 <_Z19F_BUFFER_SetSurfaceR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0xc6288 mov r1, #1
 *   @0xc628c mov r0, r4
 *   @0xc6290 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc6294 mov r7, r0
 *   @0xc6298 bl 0x1714c0 <_Z17GR_Surface_Existsi>
 *   @0xc629c subs r1, r0, #0
 *   @0xc62a0 beq 0xc62fc <_Z19F_BUFFER_SetSurfaceR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0xc62a4 ldr r3, [r6, #0x4]
 *   @0xc62a8 mov r0, r4
 *   @0xc62ac mov r1, #3
 *   @0xc62b0 ldr r5, [r3, r5, lsl #2]
 *   @0xc62b4 ldr r3, [r5]
 *   @0xc62b8 ldr r6, [r3, #0x44]
 *   @0xc62bc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc62c0 mov r1, #4
 *   @0xc62c4 mov r8, r0
 *   @0xc62c8 mov r0, r4
 *   @0xc62cc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc62d0 mov r1, r7
 *   @0xc62d4 mov r2, r8
 *   @0xc62d8 mov r3, r0
 *   @0xc62dc mov r0, r5
 *   @0xc62e0 blx r6
 *   @0xc62e4 pop {r4, r5, r6, r7, r8, pc}
 *   @0xc62e8 ldr r0, [pc, #0x20]
 *   @0xc62ec mov r1, #0
 *   @0xc62f0 pop {r4, r5, r6, r7, r8, lr}
 *   @0xc62f4 add r0, pc, r0
 *   @0xc62f8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc62fc ldr r0, [pc, #0x10]
 *   @0xc6300 pop {r4, r5, r6, r7, r8, lr}
 *   @0xc6304 add r0, pc, r0
 *   @0xc6308 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc630c eorseq r3, r11, r12, lsr #29
 *   @0xc6310 eoreq r10, r6, r12, asr #21
 *   @0xc6314 .word 0x0026aaf0
 *
 * ══ §54/146 F_BUFFER_Async_Group_End(RValue&, CInstance*, CInstance*, int, RValue*)  0xc752c  size 208  52 条（0xc752c..0xc75fc）
 * @func 0xc752c 0xc75fc  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: KickAsyncBuffer(bool, SAsyncBuffer*, char const*, bool) / MemoryManager::Free(void const*) / YYError(char const*, ...)
 * 字段偏移 top8: 0xac×1 / 0xc×1 / 0x4×1 / 0x84×1 / 0x40×1 / 0x24×1 / 0x18×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc752c push {r3, r4, r5, lr}
 *   @0xc7530 mov r5, r0
 *   @0xc7534 ldr r4, [pc, #0xac]
 *   @0xc7538 mov r0, #0
 *   @0xc753c str r0, [r5]
 *   @0xc7540 mov r3, r0
 *   @0xc7544 ldr r4, [pc, r4]
 *   @0xc7548 movt r3, #0xbff0
 *   @0xc754c str r0, [r5, #0xc]
 *   @0xc7550 ldr r2, [r4]
 *   @0xc7554 str r3, [r5, #0x4]
 *   @0xc7558 cmp r2, r0
 *   @0xc755c beq 0xc75c8 <_Z24F_BUFFER_Async_Group_EndR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0xc7560 ldr r3, [pc, #0x84]
 *   @0xc7564 ldr r3, [pc, r3]
 *   @0xc7568 ldr r1, [r3]
 *   @0xc756c cmp r1, #0
 *   @0xc7570 movne r3, #1
 *   @0xc7574 beq 0xc75a8 <_Z24F_BUFFER_Async_Group_EndR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0xc7578 bl 0xc70c4 <_Z15KickAsyncBufferbP12SAsyncBufferPKcb>
 *   @0xc757c vmov s15, r0
 *   @0xc7580 vcvt.f64.s32 d7, s15
 *   @0xc7584 vmov r0, r1, d7
 *   @0xc7588 vmov r2, s14
 *   @0xc758c mov r3, r1
 *   @0xc7590 stm r5, {r2, r3}
 *   @0xc7594 ldr r0, [r4]
 *   @0xc7598 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xc759c mov r3, #0
 *   @0xc75a0 str r3, [r4]
 *   @0xc75a4 pop {r3, r4, r5, pc}
 *   @0xc75a8 ldr r3, [pc, #0x40]
 *   @0xc75ac ldr r3, [pc, r3]
 *   @0xc75b0 ldr r1, [r3]
 *   @0xc75b4 cmp r1, #0
 *   @0xc75b8 beq 0xc75d8 <_Z24F_BUFFER_Async_Group_EndR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0xc75bc mov r0, #1
 *   @0xc75c0 mov r3, r0
 *   @0xc75c4 b 0xc7578 <_Z24F_BUFFER_Async_Group_EndR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0xc75c8 ldr r0, [pc, #0x24]
 *   @0xc75cc pop {r3, r4, r5, lr}
 *   @0xc75d0 add r0, pc, r0
 *   @0xc75d4 b 0xd547c <_Z7YYErrorPKcz>
 *   @0xc75d8 ldr r0, [pc, #0x18]
 *   @0xc75dc add r0, pc, r0
 *   @0xc75e0 bl 0xd547c <_Z7YYErrorPKcz>
 *   @0xc75e4 b 0xc7594 <_Z24F_BUFFER_Async_Group_EndR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0xc75e8 eorseq r6, r2, r4, ror r4
 *   @0xc75ec eorseq r6, r2, r8, ror r4
 *   @0xc75f0 eorseq r6, r2, r12, lsr #8
 *   @0xc75f4 .word 0x00269fd0
 *   @0xc75f8 eoreq r9, r6, r4, ror #31
 *
 * ══ §55/146 Variable_FindName(char const*)  0xd1bc4  size 208  52 条（0xd1bc4..0xd1c94）
 * @func 0xd1bc4 0xd1c94  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xd1bd0→0x47a1b4, 0xd1bdc→0x47a1b8
 * 调用序列: Variable_FindName(char const*)+0x70 / 0xb6574 / MemoryManager::SetLength(void**, unsigned int, char const*, int) / YYStrDup(char const*)
 * 字段偏移 top8: 0xb0×2 / 0xa8×1 / 0x4×1 / 0x50×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd1bc4 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0xd1bc8 mov r7, r0
 *   @0xd1bcc ldr r3, [pc, #0xb0]
 *   @0xd1bd0 ldr r2, [pc, #0xb0]
 *   @0xd1bd4 add r3, pc, r3
 *   @0xd1bd8 ldr r8, [r3, r2]
 *   @0xd1bdc ldr r2, [pc, #0xa8]
 *   @0xd1be0 ldr r6, [r8]
 *   @0xd1be4 cmp r6, #0
 *   @0xd1be8 ldrle r9, [r3, r2]
 *   @0xd1bec ble 0xd1c34 <_Z17Variable_FindNamePKc+0x70>
 *   @0xd1bf0 ldr r9, [r3, r2]
 *   @0xd1bf4 mov r4, #0
 *   @0xd1bf8 ldr r5, [r9]
 *   @0xd1bfc sub r5, r5, #4
 *   @0xd1c00 b 0xd1c10 <_Z17Variable_FindNamePKc+0x4c>
 *   @0xd1c04 add r4, r4, #1
 *   @0xd1c08 cmp r4, r6
 *   @0xd1c0c beq 0xd1c34 <_Z17Variable_FindNamePKc+0x70>
 *   @0xd1c10 ldr r0, [r5, #0x4]!
 *   @0xd1c14 mov r1, r7
 *   @0xd1c18 bl 0xb6574 <strcmp@plt>
 *   @0xd1c1c cmp r0, #0
 *   @0xd1c20 bne 0xd1c04 <_Z17Variable_FindNamePKc+0x40>
 *   @0xd1c24 add r4, r4, #99328
 *   @0xd1c28 add r4, r4, #672
 *   @0xd1c2c mov r0, r4
 *   @0xd1c30 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xd1c34 add r6, r6, #1
 *   @0xd1c38 ldr r2, [pc, #0x50]
 *   @0xd1c3c mov r0, r9
 *   @0xd1c40 mov r3, #76
 *   @0xd1c44 lsl r1, r6, #2
 *   @0xd1c48 add r2, pc, r2
 *   @0xd1c4c str r6, [r8]
 *   @0xd1c50 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xd1c54 mov r0, r7
 *   @0xd1c58 ldr r6, [r8]
 *   @0xd1c5c ldr r5, [r9]
 *   @0xd1c60 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xd1c64 ldr r3, [r8]
 *   @0xd1c68 movw r4, #0x869f
 *   @0xd1c6c movt r4, #0x1
 *   @0xd1c70 sub r6, r6, #-1073741823
 *   @0xd1c74 add r4, r3, r4
 *   @0xd1c78 str r0, [r5, r6, lsl #2]
 *   @0xd1c7c mov r0, r4
 *   @0xd1c80 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0xd1c84 eorseq r0, r2, r12, ror r0
 *   @0xd1c88 .word 0xffffbf44
 *   @0xd1c8c .word 0xffffbf48
 *   @0xd1c90 .word 0x00260ad8
 *
 * ══ §56/146 utf8_strncmp  0x110b34  size 208  52 条（0x110b34..0x110c04）
 * @func 0x110b34 0x110c04  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: utf8_extract_char×4 / utf8_strncmp+0xb4
 * 字段偏移 top8: 0x4×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x110b34 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x110b38 sub sp, sp, #12
 *   @0x110b3c mov r5, r0
 *   @0x110b40 mov r4, r2
 *   @0x110b44 str r0, [sp, #0x4]
 *   @0x110b48 str r1, [sp]
 *   @0x110b4c ldrb r3, [r0]
 *   @0x110b50 cmp r3, #0
 *   @0x110b54 beq 0x110be8 <utf8_strncmp+0xb4>
 *   @0x110b58 ldrb r3, [r1]
 *   @0x110b5c mov r6, r1
 *   @0x110b60 cmp r3, #0
 *   @0x110b64 beq 0x110be8 <utf8_strncmp+0xb4>
 *   @0x110b68 cmp r2, #0
 *   @0x110b6c ble 0x110be8 <utf8_strncmp+0xb4>
 *   @0x110b70 add r9, sp, #4
 *   @0x110b74 b 0x110ba0 <utf8_strncmp+0x6c>
 *   @0x110b78 ldr r5, [sp, #0x4]
 *   @0x110b7c ldrb r3, [r5]
 *   @0x110b80 cmp r3, #0
 *   @0x110b84 beq 0x110be8 <utf8_strncmp+0xb4>
 *   @0x110b88 ldr r6, [sp]
 *   @0x110b8c ldrb r3, [r6]
 *   @0x110b90 cmp r3, #0
 *   @0x110b94 beq 0x110be8 <utf8_strncmp+0xb4>
 *   @0x110b98 cmp r4, #0
 *   @0x110b9c beq 0x110bf0 <utf8_strncmp+0xbc>
 *   @0x110ba0 mov r0, r9
 *   @0x110ba4 sub r4, r4, #1
 *   @0x110ba8 bl 0x10fb38 <utf8_extract_char>
 *   @0x110bac mov r7, r0
 *   @0x110bb0 mov r0, sp
 *   @0x110bb4 bl 0x10fb38 <utf8_extract_char>
 *   @0x110bb8 cmp r7, r0
 *   @0x110bbc beq 0x110b78 <utf8_strncmp+0x44>
 *   @0x110bc0 str r5, [sp, #0x4]
 *   @0x110bc4 str r6, [sp]
 *   @0x110bc8 mov r0, r9
 *   @0x110bcc bl 0x10fb38 <utf8_extract_char>
 *   @0x110bd0 mov r4, r0
 *   @0x110bd4 mov r0, sp
 *   @0x110bd8 bl 0x10fb38 <utf8_extract_char>
 *   @0x110bdc rsb r0, r0, r4
 *   @0x110be0 add sp, sp, #12
 *   @0x110be4 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x110be8 cmp r4, #0
 *   @0x110bec bne 0x110bfc <utf8_strncmp+0xc8>
 *   @0x110bf0 mov r0, r4
 *   @0x110bf4 add sp, sp, #12
 *   @0x110bf8 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x110bfc add r9, sp, #4
 *   @0x110c00 b 0x110bc8 <utf8_strncmp+0x94>
 *
 * ══ §57/146 Delete(char const*&, int, int)  0x111378  size 208  52 条（0x111378..0x111448）
 * @func 0x111378 0x111448  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: utf8_extract_char×2 / Delete(char const*&, int, int)+0xc0 / utf8_strlen / Delete(char const*&, int, int)+0xc8 / Delete(char const*&, int, int)+0xb4 / utf8_add_char
 * 字段偏移 top8: 0x4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x111378 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x11137c mov r6, r0
 *   @0x111380 ldr r0, [r0]
 *   @0x111384 sub sp, sp, #12
 *   @0x111388 mov r9, r2
 *   @0x11138c cmp r0, #0
 *   @0x111390 beq 0x111438 <_Z6DeleteRPKcii+0xc0>
 *   @0x111394 cmp r2, #0
 *   @0x111398 ble 0x111438 <_Z6DeleteRPKcii+0xc0>
 *   @0x11139c sub r7, r1, #1
 *   @0x1113a0 bl 0x110648 <utf8_strlen>
 *   @0x1113a4 lsr r5, r7, #31
 *   @0x1113a8 cmp r0, r7
 *   @0x1113ac orrle r5, r5, #1
 *   @0x1113b0 mov r8, r0
 *   @0x1113b4 cmp r5, #0
 *   @0x1113b8 bne 0x111438 <_Z6DeleteRPKcii+0xc0>
 *   @0x1113bc rsb r4, r7, r0
 *   @0x1113c0 ldr r3, [r6]
 *   @0x1113c4 cmp r4, r9
 *   @0x1113c8 addle r4, r7, r4
 *   @0x1113cc addgt r4, r7, r9
 *   @0x1113d0 cmp r4, #0
 *   @0x1113d4 str r3, [sp]
 *   @0x1113d8 str r3, [sp, #0x4]
 *   @0x1113dc ble 0x111440 <_Z6DeleteRPKcii+0xc8>
 *   @0x1113e0 cmp r5, r7
 *   @0x1113e4 mov r0, sp
 *   @0x1113e8 add r5, r5, #1
 *   @0x1113ec ldreq r3, [sp]
 *   @0x1113f0 streq r3, [sp, #0x4]
 *   @0x1113f4 bl 0x10fb38 <utf8_extract_char>
 *   @0x1113f8 cmp r5, r4
 *   @0x1113fc bne 0x1113e0 <_Z6DeleteRPKcii+0x68>
 *   @0x111400 cmp r8, r4
 *   @0x111404 ble 0x11142c <_Z6DeleteRPKcii+0xb4>
 *   @0x111408 add r5, sp, #4
 *   @0x11140c mov r0, sp
 *   @0x111410 add r4, r4, #1
 *   @0x111414 bl 0x10fb38 <utf8_extract_char>
 *   @0x111418 mov r1, r0
 *   @0x11141c mov r0, r5
 *   @0x111420 bl 0x10fe28 <utf8_add_char>
 *   @0x111424 cmp r4, r8
 *   @0x111428 bne 0x11140c <_Z6DeleteRPKcii+0x94>
 *   @0x11142c ldr r3, [sp, #0x4]
 *   @0x111430 mov r2, #0
 *   @0x111434 strb r2, [r3]
 *   @0x111438 add sp, sp, #12
 *   @0x11143c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x111440 mov r4, r5
 *   @0x111444 b 0x111408 <_Z6DeleteRPKcii+0x90>
 *
 * ══ §58/146 GetSecondOfYear(int, int, int, int, int, int)  0x1180c0  size 208  52 条（0x1180c0..0x118190）
 * @func 0x1180c0 0x118190  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetSecondOfYear(int, int, int, int, int, int)+0xbc / is_leap_year(int) / GetSecondOfYear(int, int, int, int, int, int)+0xc4
 * 字段偏移 top8: 0xbc×1 / 0x58×1 / 0x4×1 / 0x5c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1180c0 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1180c4 mov r8, r0
 *   @0x1180c8 ldr r4, [pc, #0xbc]
 *   @0x1180cc mov r10, r1
 *   @0x1180d0 mov r7, r2
 *   @0x1180d4 mov r6, r3
 *   @0x1180d8 add r4, pc, r4
 *   @0x1180dc sub sp, sp, #56
 *   @0x1180e0 add r9, sp, #4
 *   @0x1180e4 cmp r8, #0
 *   @0x1180e8 ldm r4!, {r0, r1, r2, r3}
 *   @0x1180ec mov r12, r9
 *   @0x1180f0 ldr r5, [sp, #0x58]
 *   @0x1180f4 stm r12!, {r0, r1, r2, r3}
 *   @0x1180f8 ldm r4!, {r0, r1, r2, r3}
 *   @0x1180fc stm r12!, {r0, r1, r2, r3}
 *   @0x118100 ldm r4!, {r0, r1, r2, r3}
 *   @0x118104 ldr r4, [r4]
 *   @0x118108 stm r12!, {r0, r1, r2, r3}
 *   @0x11810c movlt r0, #0
 *   @0x118110 str r4, [r12]
 *   @0x118114 blt 0x11817c <_Z15GetSecondOfYeariiiiii+0xbc>
 *   @0x118118 mov r0, r8
 *   @0x11811c bl 0x117a5c <_Z12is_leap_yeari>
 *   @0x118120 cmp r0, #0
 *   @0x118124 movne r3, #29
 *   @0x118128 strne r3, [sp, #0xc]
 *   @0x11812c cmp r10, #1
 *   @0x118130 ble 0x118184 <_Z15GetSecondOfYeariiiiii+0xc4>
 *   @0x118134 add r1, sp, r10, lsl #2
 *   @0x118138 mov r0, r9
 *   @0x11813c mov r12, #0
 *   @0x118140 ldr r4, [r0, #0x4]!
 *   @0x118144 cmp r0, r1
 *   @0x118148 add r12, r12, r4
 *   @0x11814c bne 0x118140 <_Z15GetSecondOfYeariiiiii+0x80>
 *   @0x118150 add r12, r12, r7
 *   @0x118154 movw r3, #0x5180
 *   @0x118158 sub r0, r12, #1
 *   @0x11815c movt r3, #0x1
 *   @0x118160 mov r2, #3600
 *   @0x118164 rsb r5, r5, r5, lsl #4
 *   @0x118168 mul r6, r2, r6
 *   @0x11816c mla r3, r3, r0, r6
 *   @0x118170 add r0, r3, r5, lsl #2
 *   @0x118174 ldr r3, [sp, #0x5c]
 *   @0x118178 add r0, r0, r3
 *   @0x11817c add sp, sp, #56
 *   @0x118180 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x118184 mov r12, #0
 *   @0x118188 b 0x118150 <_Z15GetSecondOfYeariiiiii+0x90>
 *   @0x11818c eoreq r4, r4, r8, ror #16
 *
 * ══ §59/146 F_DrawRoundRectColour_EXT(RValue&, CInstance*, CInstance*, int, RValue*)  0x11b6d8  size 208  52 条（0x11b6d8..0x11b7a8）
 * @func 0x11b6d8 0x11b7a8  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×6 / YYGetInt32(RValue const*, int)×2 / YYGetBool(RValue const*, int) / GR_Draw_RoundRect_Ext(float, float, float, float, float, float, unsigned int, unsigned int, bool)
 * 字段偏移 top8: 0x1c×2 / 0x48×1 / 0x4×1 / 0x8×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11b6d8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x11b6dc sub sp, sp, #36
 *   @0x11b6e0 mov r1, #4
 *   @0x11b6e4 ldr r4, [sp, #0x48]
 *   @0x11b6e8 mov r0, r4
 *   @0x11b6ec bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b6f0 mov r1, #5
 *   @0x11b6f4 mov r3, r0
 *   @0x11b6f8 mov r0, r4
 *   @0x11b6fc str r3, [sp, #0x1c]
 *   @0x11b700 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b704 mov r1, #0
 *   @0x11b708 mov r11, r0
 *   @0x11b70c mov r0, r4
 *   @0x11b710 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b714 mov r1, #1
 *   @0x11b718 mov r5, r0
 *   @0x11b71c mov r0, r4
 *   @0x11b720 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b724 mov r1, #2
 *   @0x11b728 mov r8, r0
 *   @0x11b72c mov r0, r4
 *   @0x11b730 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b734 mov r1, #3
 *   @0x11b738 mov r7, r0
 *   @0x11b73c mov r0, r4
 *   @0x11b740 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b744 mov r1, #6
 *   @0x11b748 mov r6, r0
 *   @0x11b74c mov r0, r4
 *   @0x11b750 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11b754 mov r1, #7
 *   @0x11b758 mov r10, r0
 *   @0x11b75c mov r0, r4
 *   @0x11b760 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11b764 mov r1, #8
 *   @0x11b768 mov r9, r0
 *   @0x11b76c mov r0, r4
 *   @0x11b770 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x11b774 ldr r3, [sp, #0x1c]
 *   @0x11b778 str r11, [sp, #0x4]
 *   @0x11b77c mov r1, r8
 *   @0x11b780 str r10, [sp, #0x8]
 *   @0x11b784 mov r2, r7
 *   @0x11b788 str r3, [sp]
 *   @0x11b78c mov r3, r6
 *   @0x11b790 str r9, [sp, #0xc]
 *   @0x11b794 str r0, [sp, #0x10]
 *   @0x11b798 mov r0, r5
 *   @0x11b79c bl 0x16b864 <_Z21GR_Draw_RoundRect_Extffffffjjb>
 *   @0x11b7a0 add sp, sp, #36
 *   @0x11b7a4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §60/146 F_BackgroundCreateGradient(RValue&, CInstance*, CInstance*, int, RValue*)  0x12c75c  size 208  52 条（0x12c75c..0x12c82c）
 * @func 0x12c75c 0x12c82c  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×5 / Background_AddEmpty()×2 / Background_Data(int) / YYGetBool(RValue const*, int) / CBackground::CreateGradient(int, int, unsigned int, unsigned int, int, bool)
 * 字段偏移 top8: 0xc×1 / 0x38×1 / 0x8×1 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12c75c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x12c760 sub sp, sp, #20
 *   @0x12c764 mov r6, #0
 *   @0x12c768 str r6, [r0, #0xc]
 *   @0x12c76c ldr r4, [sp, #0x38]
 *   @0x12c770 mov r10, r3
 *   @0x12c774 mov r5, r0
 *   @0x12c778 bl 0xc41f0 <_Z19Background_AddEmptyv>
 *   @0x12c77c bl 0xc3794 <_Z15Background_Datai>
 *   @0x12c780 mov r7, r0
 *   @0x12c784 bl 0xc41f0 <_Z19Background_AddEmptyv>
 *   @0x12c788 mov r1, r6
 *   @0x12c78c vmov s15, r0
 *   @0x12c790 mov r0, r4
 *   @0x12c794 vcvt.f64.s32 d7, s15
 *   @0x12c798 vmov r2, r3, d7
 *   @0x12c79c stm r5, {r2, r3}
 *   @0x12c7a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c7a4 mov r1, #1
 *   @0x12c7a8 mov r8, r0
 *   @0x12c7ac mov r0, r4
 *   @0x12c7b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c7b4 mov r1, #2
 *   @0x12c7b8 mov r6, r0
 *   @0x12c7bc mov r0, r4
 *   @0x12c7c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c7c4 mov r1, #3
 *   @0x12c7c8 mov r5, r0
 *   @0x12c7cc mov r0, r4
 *   @0x12c7d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c7d4 mov r1, #4
 *   @0x12c7d8 mov r9, r0
 *   @0x12c7dc mov r0, r4
 *   @0x12c7e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12c7e4 cmp r10, #5
 *   @0x12c7e8 moveq r3, #1
 *   @0x12c7ec mov r11, r0
 *   @0x12c7f0 beq 0x12c804 <_Z26F_BackgroundCreateGradientR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x12c7f4 mov r0, r4
 *   @0x12c7f8 mov r1, #5
 *   @0x12c7fc bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x12c800 mov r3, r0
 *   @0x12c804 str r3, [sp, #0x8]
 *   @0x12c808 mov r0, r7
 *   @0x12c80c str r9, [sp]
 *   @0x12c810 mov r1, r8
 *   @0x12c814 str r11, [sp, #0x4]
 *   @0x12c818 mov r2, r6
 *   @0x12c81c mov r3, r5
 *   @0x12c820 bl 0xc2ac0 <_ZN11CBackground14CreateGradientEiijjib>
 *   @0x12c824 add sp, sp, #20
 *   @0x12c828 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §61/146 F_BackgroundFlush(RValue&, CInstance*, CInstance*, int, RValue*)  0x12eff4  size 208  52 条（0x12eff4..0x12f0c4）
 * @func 0x12eff4 0x12f0c4  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::FlushTexture(void*)×2 / YYGetInt32(RValue const*, int) / Background_Data(int) / Graphics::Flush() / CBackground::GetTexture()
 * 字段偏移 top8: 0x4×3 / 0xc×2 / 0x2×2 / 0x10×1 / 0x7c×1 / 0x24×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12eff4 push {r4, r5, r6, lr}
 *   @0x12eff8 mov r1, #0
 *   @0x12effc mov r3, r1
 *   @0x12f000 str r1, [r0, #0xc]
 *   @0x12f004 movt r3, #0xbff0
 *   @0x12f008 mov r4, r0
 *   @0x12f00c stm r0, {r1, r3}
 *   @0x12f010 ldr r0, [sp, #0x10]
 *   @0x12f014 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12f018 mov r6, r0
 *   @0x12f01c bl 0xc3794 <_Z15Background_Datai>
 *   @0x12f020 subs r5, r0, #0
 *   @0x12f024 beq 0x12f090 <_Z17F_BackgroundFlushR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x12f028 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x12f02c mov r0, r5
 *   @0x12f030 bl 0xc1e8c <_ZN11CBackground10GetTextureEv>
 *   @0x12f034 ldr r3, [pc, #0x7c]
 *   @0x12f038 ldr r3, [pc, r3]
 *   @0x12f03c ldr r2, [r3]
 *   @0x12f040 cmp r0, r2
 *   @0x12f044 bhi 0x12f070 <_Z17F_BackgroundFlushR6RValueP9CInstanceS2_iPS_+0x7c>
 *   @0x12f048 ldr r3, [r3, #0x4]
 *   @0x12f04c ldr r3, [r3, r0, lsl #2]
 *   @0x12f050 cmp r3, #0
 *   @0x12f054 beq 0x12f060 <_Z17F_BackgroundFlushR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x12f058 ldr r0, [r3]
 *   @0x12f05c bl 0x1811bc <_ZN8Graphics12FlushTextureEPv>
 *   @0x12f060 mov r3, #0
 *   @0x12f064 str r3, [r4]
 *   @0x12f068 str r3, [r4, #0x4]
 *   @0x12f06c pop {r4, r5, r6, pc}
 *   @0x12f070 cmn r0, #1
 *   @0x12f074 beq 0x12f048 <_Z17F_BackgroundFlushR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x12f078 ldrsh r2, [r0, #20]
 *   @0x12f07c ldr r3, [r3, #0x4]
 *   @0x12f080 ldr r3, [r3, r2, lsl #2]
 *   @0x12f084 ldr r0, [r3]
 *   @0x12f088 bl 0x1811bc <_ZN8Graphics12FlushTextureEPv>
 *   @0x12f08c b 0x12f060 <_Z17F_BackgroundFlushR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x12f090 ldr r3, [pc, #0x24]
 *   @0x12f094 mov r2, r6
 *   @0x12f098 ldr r1, [pc, #0x20]
 *   @0x12f09c ldr r3, [pc, r3]
 *   @0x12f0a0 add r1, pc, r1
 *   @0x12f0a4 ldr r0, [r3]
 *   @0x12f0a8 ldr r3, [r0]
 *   @0x12f0ac ldr r3, [r3, #0xc]
 *   @0x12f0b0 blx r3
 *   @0x12f0b4 b 0x12f060 <_Z17F_BackgroundFlushR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x12f0b8 eoreq lr, r11, r4, ror #17
 *   @0x12f0bc eoreq lr, r11, r8, ror r6
 *   @0x12f0c0 mlaeq r0, r0, r6, lr
 *
 * ══ §62/146 MyStrToFloat(char const*)  0x13b8b8  size 208  52 条（0x13b8b8..0x13b988）
 * @func 0x13b8b8 0x13b988  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6634×2 / 0xb6538 / MyStrToFloat(char const*)+0x58 / 0xb65b0 / 0xb65c8 / 0xb6658 / 0xb65d4
 * 字段偏移 top8: 0x44×2 / 0xb8×1 / 0x58×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13b8b8 push {r4, r5, r6, lr}
 *   @0x13b8bc subs r6, r0, #0
 *   @0x13b8c0 ldr r4, [pc, #0xb8]
 *   @0x13b8c4 sub sp, sp, #72
 *   @0x13b8c8 ldr r4, [pc, r4]
 *   @0x13b8cc ldr r3, [r4]
 *   @0x13b8d0 str r3, [sp, #0x44]
 *   @0x13b8d4 beq 0x13b8f0 <_Z12MyStrToFloatPKc+0x38>
 *   @0x13b8d8 ldrb r3, [r6]
 *   @0x13b8dc cmp r3, #0
 *   @0x13b8e0 beq 0x13b8f0 <_Z12MyStrToFloatPKc+0x38>
 *   @0x13b8e4 bl 0xb6538 <strlen@plt>
 *   @0x13b8e8 cmp r0, #63
 *   @0x13b8ec bls 0x13b910 <_Z12MyStrToFloatPKc+0x58>
 *   @0x13b8f0 mov r0, #0
 *   @0x13b8f4 mov r1, #0
 *   @0x13b8f8 ldr r2, [sp, #0x44]
 *   @0x13b8fc ldr r3, [r4]
 *   @0x13b900 cmp r2, r3
 *   @0x13b904 bne 0x13b97c <_Z12MyStrToFloatPKc+0xc4>
 *   @0x13b908 add sp, sp, #72
 *   @0x13b90c pop {r4, r5, r6, pc}
 *   @0x13b910 add r5, sp, #4
 *   @0x13b914 mov r1, #0
 *   @0x13b918 mov r2, #64
 *   @0x13b91c mov r0, r5
 *   @0x13b920 bl 0xb65b0 <memset@plt>
 *   @0x13b924 ldr r2, [pc, #0x58]
 *   @0x13b928 mov r3, r6
 *   @0x13b92c mov r1, #64
 *   @0x13b930 add r2, pc, r2
 *   @0x13b934 mov r0, r5
 *   @0x13b938 bl 0xb65c8 <snprintf@plt>
 *   @0x13b93c mov r0, r5
 *   @0x13b940 mov r1, #44
 *   @0x13b944 bl 0xb6634 <strchr@plt>
 *   @0x13b948 cmp r0, #0
 *   @0x13b94c movne r6, #46
 *   @0x13b950 beq 0x13b96c <_Z12MyStrToFloatPKc+0xb4>
 *   @0x13b954 strb r6, [r0]
 *   @0x13b958 mov r1, #44
 *   @0x13b95c mov r0, r5
 *   @0x13b960 bl 0xb6634 <strchr@plt>
 *   @0x13b964 cmp r0, #0
 *   @0x13b968 bne 0x13b954 <_Z12MyStrToFloatPKc+0x9c>
 *   @0x13b96c mov r0, r5
 *   @0x13b970 mov r1, #0
 *   @0x13b974 bl 0xb6658 <strtod@plt>
 *   @0x13b978 b 0x13b8f8 <_Z12MyStrToFloatPKc+0x40>
 *   @0x13b97c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x13b980 eoreq r2, r11, r8, lsl #1
 *   @0x13b984 ldrsbeq r9, [pc], -r8
 *
 * ══ §63/146 F_ActionPartTypeSecondary(RValue&, CInstance*, CInstance*, int, RValue*)  0x13fedc  size 208  52 条（0x13fedc..0x13ffac）
 * @func 0x13fedc 0x13ffac  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×5 / F_ActionPartTypeSecondary(RValue&, CInstance*, CInstance*, int, RValue*)+0xb4 / F_ActionPartTypeSecondary(RValue&, CInstance*, CInstance*, int, RValue*)+0xa4 / ParticleType_Step(int, int, int) / ParticleType_Create() / ParticleSystem_Create(int, bool)
 * 字段偏移 top8: 0x2×4 / 0x20×1 / 0xb4×1 / 0x58×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13fedc push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x13fee0 mov r1, #0
 *   @0x13fee4 ldr r4, [sp, #0x20]
 *   @0x13fee8 ldr r5, [pc, #0xb4]
 *   @0x13feec mov r0, r4
 *   @0x13fef0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13fef4 mov r1, #2
 *   @0x13fef8 mov r6, r0
 *   @0x13fefc mov r0, r4
 *   @0x13ff00 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13ff04 mov r1, #1
 *   @0x13ff08 mov r9, r0
 *   @0x13ff0c mov r0, r4
 *   @0x13ff10 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13ff14 mov r1, #4
 *   @0x13ff18 mov r8, r0
 *   @0x13ff1c mov r0, r4
 *   @0x13ff20 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13ff24 mov r1, #3
 *   @0x13ff28 mov r7, r0
 *   @0x13ff2c mov r0, r4
 *   @0x13ff30 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13ff34 ldr r5, [pc, r5]
 *   @0x13ff38 ldr r3, [r5]
 *   @0x13ff3c cmp r3, #0
 *   @0x13ff40 mov r10, r0
 *   @0x13ff44 blt 0x13ff90 <_Z25F_ActionPartTypeSecondaryR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x13ff48 ldr r4, [pc, #0x58]
 *   @0x13ff4c ldr r4, [pc, r4]
 *   @0x13ff50 ldr r5, [r4, r6, lsl #2]
 *   @0x13ff54 cmp r5, #0
 *   @0x13ff58 blt 0x13ff80 <_Z25F_ActionPartTypeSecondaryR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x13ff5c mov r1, r9
 *   @0x13ff60 ldr r2, [r4, r8, lsl #2]
 *   @0x13ff64 mov r0, r5
 *   @0x13ff68 bl 0x1a32f0 <_Z17ParticleType_Stepiii>
 *   @0x13ff6c mov r0, r5
 *   @0x13ff70 mov r1, r7
 *   @0x13ff74 ldr r2, [r4, r10, lsl #2]
 *   @0x13ff78 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x13ff7c b 0x1a332c <_Z18ParticleType_Deathiii>
 *   @0x13ff80 bl 0x1a3068 <_Z19ParticleType_Createv>
 *   @0x13ff84 mov r5, r0
 *   @0x13ff88 str r0, [r4, r6, lsl #2]
 *   @0x13ff8c b 0x13ff5c <_Z25F_ActionPartTypeSecondaryR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x13ff90 mvn r0, #0
 *   @0x13ff94 mov r1, #1
 *   @0x13ff98 bl 0x1a42dc <_Z21ParticleSystem_Createib>
 *   @0x13ff9c str r0, [r5]
 *   @0x13ffa0 b 0x13ff48 <_Z25F_ActionPartTypeSecondaryR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x13ffa4 eoreq pc, r10, r8, lsr #9
 *   @0x13ffa8 mlaeq r10, r4, r4, pc
 *
 * ══ §64/146 F_D3DDrawBlock(RValue&, CInstance*, CInstance*, int, RValue*)  0x144134  size 208  52 条（0x144134..0x144204）
 * @func 0x144134 0x144204  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×8 / YYGetPtrOrInt(RValue const*, int) / GR_3D_Draw_Block(float, float, float, float, float, float, int, float, float)
 * 字段偏移 top8: 0x1c×2 / 0x48×1 / 0x4×1 / 0x8×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x144134 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x144138 sub sp, sp, #36
 *   @0x14413c mov r1, #0
 *   @0x144140 ldr r4, [sp, #0x48]
 *   @0x144144 mov r0, r4
 *   @0x144148 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14414c mov r1, #1
 *   @0x144150 mov r5, r0
 *   @0x144154 mov r0, r4
 *   @0x144158 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14415c mov r1, #2
 *   @0x144160 mov r8, r0
 *   @0x144164 mov r0, r4
 *   @0x144168 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14416c mov r1, #3
 *   @0x144170 mov r7, r0
 *   @0x144174 mov r0, r4
 *   @0x144178 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14417c mov r1, #4
 *   @0x144180 mov r6, r0
 *   @0x144184 mov r0, r4
 *   @0x144188 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14418c mov r1, #5
 *   @0x144190 mov r3, r0
 *   @0x144194 mov r0, r4
 *   @0x144198 str r3, [sp, #0x1c]
 *   @0x14419c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1441a0 mov r1, #6
 *   @0x1441a4 mov r11, r0
 *   @0x1441a8 mov r0, r4
 *   @0x1441ac bl 0xce6c0 <_Z13YYGetPtrOrIntPK6RValuei>
 *   @0x1441b0 mov r1, #7
 *   @0x1441b4 mov r10, r0
 *   @0x1441b8 mov r0, r4
 *   @0x1441bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1441c0 mov r1, #8
 *   @0x1441c4 mov r9, r0
 *   @0x1441c8 mov r0, r4
 *   @0x1441cc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1441d0 ldr r3, [sp, #0x1c]
 *   @0x1441d4 str r11, [sp, #0x4]
 *   @0x1441d8 mov r1, r8
 *   @0x1441dc str r10, [sp, #0x8]
 *   @0x1441e0 mov r2, r7
 *   @0x1441e4 str r3, [sp]
 *   @0x1441e8 mov r3, r6
 *   @0x1441ec str r9, [sp, #0xc]
 *   @0x1441f0 str r0, [sp, #0x10]
 *   @0x1441f4 mov r0, r5
 *   @0x1441f8 bl 0x17763c <_Z16GR_3D_Draw_Blockffffffiff>
 *   @0x1441fc add sp, sp, #36
 *   @0x144200 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §65/146 F_D3DDrawWall(RValue&, CInstance*, CInstance*, int, RValue*)  0x144500  size 208  52 条（0x144500..0x1445d0）
 * @func 0x144500 0x1445e0  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×8 / YYGetPtrOrInt(RValue const*, int) / GR_3D_Draw_Wall(float, float, float, float, float, float, int, float, float)
 * 字段偏移 top8: 0x1c×2 / 0x48×1 / 0x4×1 / 0x8×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x144500 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x144504 sub sp, sp, #36
 *   @0x144508 mov r1, #0
 *   @0x14450c ldr r4, [sp, #0x48]
 *   @0x144510 mov r0, r4
 *   @0x144514 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144518 mov r1, #1
 *   @0x14451c mov r5, r0
 *   @0x144520 mov r0, r4
 *   @0x144524 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144528 mov r1, #2
 *   @0x14452c mov r8, r0
 *   @0x144530 mov r0, r4
 *   @0x144534 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144538 mov r1, #3
 *   @0x14453c mov r7, r0
 *   @0x144540 mov r0, r4
 *   @0x144544 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144548 mov r1, #4
 *   @0x14454c mov r6, r0
 *   @0x144550 mov r0, r4
 *   @0x144554 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144558 mov r1, #5
 *   @0x14455c mov r3, r0
 *   @0x144560 mov r0, r4
 *   @0x144564 str r3, [sp, #0x1c]
 *   @0x144568 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14456c mov r1, #6
 *   @0x144570 mov r11, r0
 *   @0x144574 mov r0, r4
 *   @0x144578 bl 0xce6c0 <_Z13YYGetPtrOrIntPK6RValuei>
 *   @0x14457c mov r1, #7
 *   @0x144580 mov r10, r0
 *   @0x144584 mov r0, r4
 *   @0x144588 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14458c mov r1, #8
 *   @0x144590 mov r9, r0
 *   @0x144594 mov r0, r4
 *   @0x144598 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14459c ldr r3, [sp, #0x1c]
 *   @0x1445a0 str r11, [sp, #0x4]
 *   @0x1445a4 mov r1, r8
 *   @0x1445a8 str r10, [sp, #0x8]
 *   @0x1445ac mov r2, r7
 *   @0x1445b0 str r3, [sp]
 *   @0x1445b4 mov r3, r6
 *   @0x1445b8 str r9, [sp, #0xc]
 *   @0x1445bc str r0, [sp, #0x10]
 *   @0x1445c0 mov r0, r5
 *   @0x1445c4 bl 0x1796e0 <_Z15GR_3D_Draw_Wallffffffiff>
 *   @0x1445c8 add sp, sp, #36
 *   @0x1445cc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §66/146 F_D3DDrawFloor(RValue&, CInstance*, CInstance*, int, RValue*)  0x1445d0  size 208  52 条（0x1445d0..0x1446a0）
 * @func 0x1445d0 0x1446b0  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×8 / YYGetPtrOrInt(RValue const*, int) / GR_3D_Draw_Floor(float, float, float, float, float, float, int, float, float)
 * 字段偏移 top8: 0x1c×2 / 0x48×1 / 0x4×1 / 0x8×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1445d0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1445d4 sub sp, sp, #36
 *   @0x1445d8 mov r1, #0
 *   @0x1445dc ldr r4, [sp, #0x48]
 *   @0x1445e0 mov r0, r4
 *   @0x1445e4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1445e8 mov r1, #1
 *   @0x1445ec mov r5, r0
 *   @0x1445f0 mov r0, r4
 *   @0x1445f4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1445f8 mov r1, #2
 *   @0x1445fc mov r8, r0
 *   @0x144600 mov r0, r4
 *   @0x144604 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144608 mov r1, #3
 *   @0x14460c mov r7, r0
 *   @0x144610 mov r0, r4
 *   @0x144614 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144618 mov r1, #4
 *   @0x14461c mov r6, r0
 *   @0x144620 mov r0, r4
 *   @0x144624 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144628 mov r1, #5
 *   @0x14462c mov r3, r0
 *   @0x144630 mov r0, r4
 *   @0x144634 str r3, [sp, #0x1c]
 *   @0x144638 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14463c mov r1, #6
 *   @0x144640 mov r11, r0
 *   @0x144644 mov r0, r4
 *   @0x144648 bl 0xce6c0 <_Z13YYGetPtrOrIntPK6RValuei>
 *   @0x14464c mov r1, #7
 *   @0x144650 mov r10, r0
 *   @0x144654 mov r0, r4
 *   @0x144658 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14465c mov r1, #8
 *   @0x144660 mov r9, r0
 *   @0x144664 mov r0, r4
 *   @0x144668 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14466c ldr r3, [sp, #0x1c]
 *   @0x144670 str r11, [sp, #0x4]
 *   @0x144674 mov r1, r8
 *   @0x144678 str r10, [sp, #0x8]
 *   @0x14467c mov r2, r7
 *   @0x144680 str r3, [sp]
 *   @0x144684 mov r3, r6
 *   @0x144688 str r9, [sp, #0xc]
 *   @0x14468c str r0, [sp, #0x10]
 *   @0x144690 mov r0, r5
 *   @0x144694 bl 0x179834 <_Z16GR_3D_Draw_Floorffffffiff>
 *   @0x144698 add sp, sp, #36
 *   @0x14469c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §67/146 F_D3DSetProjection(RValue&, CInstance*, CInstance*, int, RValue*)  0x1446a0  size 208  52 条（0x1446a0..0x144770）
 * @func 0x1446a0 0x144770  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×9 / GR_3D_Projection_LookAt(float, float, float, float, float, float, float, float, float)
 * 字段偏移 top8: 0x1c×2 / 0x48×1 / 0x4×1 / 0x8×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1446a0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1446a4 sub sp, sp, #36
 *   @0x1446a8 mov r1, #0
 *   @0x1446ac ldr r4, [sp, #0x48]
 *   @0x1446b0 mov r0, r4
 *   @0x1446b4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1446b8 mov r1, #1
 *   @0x1446bc mov r5, r0
 *   @0x1446c0 mov r0, r4
 *   @0x1446c4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1446c8 mov r1, #2
 *   @0x1446cc mov r8, r0
 *   @0x1446d0 mov r0, r4
 *   @0x1446d4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1446d8 mov r1, #3
 *   @0x1446dc mov r7, r0
 *   @0x1446e0 mov r0, r4
 *   @0x1446e4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1446e8 mov r1, #4
 *   @0x1446ec mov r6, r0
 *   @0x1446f0 mov r0, r4
 *   @0x1446f4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1446f8 mov r1, #5
 *   @0x1446fc mov r3, r0
 *   @0x144700 mov r0, r4
 *   @0x144704 str r3, [sp, #0x1c]
 *   @0x144708 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14470c mov r1, #6
 *   @0x144710 mov r11, r0
 *   @0x144714 mov r0, r4
 *   @0x144718 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14471c mov r1, #7
 *   @0x144720 mov r10, r0
 *   @0x144724 mov r0, r4
 *   @0x144728 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14472c mov r1, #8
 *   @0x144730 mov r9, r0
 *   @0x144734 mov r0, r4
 *   @0x144738 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14473c ldr r3, [sp, #0x1c]
 *   @0x144740 str r11, [sp, #0x4]
 *   @0x144744 mov r1, r8
 *   @0x144748 str r10, [sp, #0x8]
 *   @0x14474c mov r2, r7
 *   @0x144750 str r3, [sp]
 *   @0x144754 mov r3, r6
 *   @0x144758 str r9, [sp, #0xc]
 *   @0x14475c str r0, [sp, #0x10]
 *   @0x144760 mov r0, r5
 *   @0x144764 bl 0x163280 <_Z23GR_3D_Projection_LookAtfffffffff>
 *   @0x144768 add sp, sp, #36
 *   @0x14476c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §68/146 F_D3DModelVertexNormalColor(RValue&, CInstance*, CInstance*, int, RValue*)  0x1457c4  size 208  52 条（0x1457c4..0x145894）
 * @func 0x1457c4 0x1458a4  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×7 / YYGetInt32(RValue const*, int)×2 / GR_3DM_Vertex_N_Color(int, float, float, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0x1c×2 / 0x48×1 / 0x4×1 / 0x8×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1457c4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1457c8 sub sp, sp, #36
 *   @0x1457cc mov r1, #0
 *   @0x1457d0 ldr r4, [sp, #0x48]
 *   @0x1457d4 mov r0, r4
 *   @0x1457d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1457dc mov r1, #1
 *   @0x1457e0 mov r5, r0
 *   @0x1457e4 mov r0, r4
 *   @0x1457e8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1457ec mov r1, #2
 *   @0x1457f0 mov r8, r0
 *   @0x1457f4 mov r0, r4
 *   @0x1457f8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1457fc mov r1, #3
 *   @0x145800 mov r7, r0
 *   @0x145804 mov r0, r4
 *   @0x145808 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14580c mov r1, #4
 *   @0x145810 mov r6, r0
 *   @0x145814 mov r0, r4
 *   @0x145818 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14581c mov r1, #5
 *   @0x145820 mov r3, r0
 *   @0x145824 mov r0, r4
 *   @0x145828 str r3, [sp, #0x1c]
 *   @0x14582c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145830 mov r1, #6
 *   @0x145834 mov r11, r0
 *   @0x145838 mov r0, r4
 *   @0x14583c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145840 mov r1, #7
 *   @0x145844 mov r10, r0
 *   @0x145848 mov r0, r4
 *   @0x14584c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x145850 mov r1, #8
 *   @0x145854 mov r9, r0
 *   @0x145858 mov r0, r4
 *   @0x14585c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145860 ldr r3, [sp, #0x1c]
 *   @0x145864 str r11, [sp, #0x4]
 *   @0x145868 mov r1, r8
 *   @0x14586c str r10, [sp, #0x8]
 *   @0x145870 mov r2, r7
 *   @0x145874 str r3, [sp]
 *   @0x145878 mov r3, r6
 *   @0x14587c str r9, [sp, #0xc]
 *   @0x145880 str r0, [sp, #0x10]
 *   @0x145884 mov r0, r5
 *   @0x145888 bl 0x165704 <_Z21GR_3DM_Vertex_N_Coloriffffffjf>
 *   @0x14588c add sp, sp, #36
 *   @0x145890 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §69/146 F_D3DModelVertexNormalTexture(RValue&, CInstance*, CInstance*, int, RValue*)  0x145894  size 208  52 条（0x145894..0x145964）
 * @func 0x145894 0x145964  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×8 / YYGetInt32(RValue const*, int) / GR_3DM_Vertex_N_Texture(int, float, float, float, float, float, float, float, float)
 * 字段偏移 top8: 0x1c×2 / 0x48×1 / 0x4×1 / 0x8×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x145894 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x145898 sub sp, sp, #36
 *   @0x14589c mov r1, #0
 *   @0x1458a0 ldr r4, [sp, #0x48]
 *   @0x1458a4 mov r0, r4
 *   @0x1458a8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1458ac mov r1, #1
 *   @0x1458b0 mov r5, r0
 *   @0x1458b4 mov r0, r4
 *   @0x1458b8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1458bc mov r1, #2
 *   @0x1458c0 mov r8, r0
 *   @0x1458c4 mov r0, r4
 *   @0x1458c8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1458cc mov r1, #3
 *   @0x1458d0 mov r7, r0
 *   @0x1458d4 mov r0, r4
 *   @0x1458d8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1458dc mov r1, #4
 *   @0x1458e0 mov r6, r0
 *   @0x1458e4 mov r0, r4
 *   @0x1458e8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1458ec mov r1, #5
 *   @0x1458f0 mov r3, r0
 *   @0x1458f4 mov r0, r4
 *   @0x1458f8 str r3, [sp, #0x1c]
 *   @0x1458fc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145900 mov r1, #6
 *   @0x145904 mov r11, r0
 *   @0x145908 mov r0, r4
 *   @0x14590c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145910 mov r1, #7
 *   @0x145914 mov r10, r0
 *   @0x145918 mov r0, r4
 *   @0x14591c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145920 mov r1, #8
 *   @0x145924 mov r9, r0
 *   @0x145928 mov r0, r4
 *   @0x14592c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145930 ldr r3, [sp, #0x1c]
 *   @0x145934 str r11, [sp, #0x4]
 *   @0x145938 mov r1, r8
 *   @0x14593c str r10, [sp, #0x8]
 *   @0x145940 mov r2, r7
 *   @0x145944 str r3, [sp]
 *   @0x145948 mov r3, r6
 *   @0x14594c str r9, [sp, #0xc]
 *   @0x145950 str r0, [sp, #0x10]
 *   @0x145954 mov r0, r5
 *   @0x145958 bl 0x16579c <_Z23GR_3DM_Vertex_N_Textureiffffffff>
 *   @0x14595c add sp, sp, #36
 *   @0x145960 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §70/146 F_D3DModelBlock(RValue&, CInstance*, CInstance*, int, RValue*)  0x145a6c  size 208  52 条（0x145a6c..0x145b3c）
 * @func 0x145a6c 0x145b3c  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×8 / YYGetInt32(RValue const*, int) / GR_3DM_Block(int, float, float, float, float, float, float, float, float)
 * 字段偏移 top8: 0x1c×2 / 0x48×1 / 0x4×1 / 0x8×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x145a6c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x145a70 sub sp, sp, #36
 *   @0x145a74 mov r1, #0
 *   @0x145a78 ldr r4, [sp, #0x48]
 *   @0x145a7c mov r0, r4
 *   @0x145a80 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x145a84 mov r1, #1
 *   @0x145a88 mov r5, r0
 *   @0x145a8c mov r0, r4
 *   @0x145a90 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145a94 mov r1, #2
 *   @0x145a98 mov r8, r0
 *   @0x145a9c mov r0, r4
 *   @0x145aa0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145aa4 mov r1, #3
 *   @0x145aa8 mov r7, r0
 *   @0x145aac mov r0, r4
 *   @0x145ab0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145ab4 mov r1, #4
 *   @0x145ab8 mov r6, r0
 *   @0x145abc mov r0, r4
 *   @0x145ac0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145ac4 mov r1, #5
 *   @0x145ac8 mov r3, r0
 *   @0x145acc mov r0, r4
 *   @0x145ad0 str r3, [sp, #0x1c]
 *   @0x145ad4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145ad8 mov r1, #6
 *   @0x145adc mov r11, r0
 *   @0x145ae0 mov r0, r4
 *   @0x145ae4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145ae8 mov r1, #7
 *   @0x145aec mov r10, r0
 *   @0x145af0 mov r0, r4
 *   @0x145af4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145af8 mov r1, #8
 *   @0x145afc mov r9, r0
 *   @0x145b00 mov r0, r4
 *   @0x145b04 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145b08 ldr r3, [sp, #0x1c]
 *   @0x145b0c str r11, [sp, #0x4]
 *   @0x145b10 mov r1, r8
 *   @0x145b14 str r10, [sp, #0x8]
 *   @0x145b18 mov r2, r7
 *   @0x145b1c str r3, [sp]
 *   @0x145b20 mov r3, r6
 *   @0x145b24 str r9, [sp, #0xc]
 *   @0x145b28 str r0, [sp, #0x10]
 *   @0x145b2c mov r0, r5
 *   @0x145b30 bl 0x16594c <_Z12GR_3DM_Blockiffffffff>
 *   @0x145b34 add sp, sp, #36
 *   @0x145b38 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §71/146 F_D3DModelWall(RValue&, CInstance*, CInstance*, int, RValue*)  0x145e38  size 208  52 条（0x145e38..0x145f08）
 * @func 0x145e38 0x145f18  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×8 / YYGetInt32(RValue const*, int) / GR_3DM_Wall(int, float, float, float, float, float, float, float, float)
 * 字段偏移 top8: 0x1c×2 / 0x48×1 / 0x4×1 / 0x8×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x145e38 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x145e3c sub sp, sp, #36
 *   @0x145e40 mov r1, #0
 *   @0x145e44 ldr r4, [sp, #0x48]
 *   @0x145e48 mov r0, r4
 *   @0x145e4c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x145e50 mov r1, #1
 *   @0x145e54 mov r5, r0
 *   @0x145e58 mov r0, r4
 *   @0x145e5c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145e60 mov r1, #2
 *   @0x145e64 mov r8, r0
 *   @0x145e68 mov r0, r4
 *   @0x145e6c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145e70 mov r1, #3
 *   @0x145e74 mov r7, r0
 *   @0x145e78 mov r0, r4
 *   @0x145e7c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145e80 mov r1, #4
 *   @0x145e84 mov r6, r0
 *   @0x145e88 mov r0, r4
 *   @0x145e8c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145e90 mov r1, #5
 *   @0x145e94 mov r3, r0
 *   @0x145e98 mov r0, r4
 *   @0x145e9c str r3, [sp, #0x1c]
 *   @0x145ea0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145ea4 mov r1, #6
 *   @0x145ea8 mov r11, r0
 *   @0x145eac mov r0, r4
 *   @0x145eb0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145eb4 mov r1, #7
 *   @0x145eb8 mov r10, r0
 *   @0x145ebc mov r0, r4
 *   @0x145ec0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145ec4 mov r1, #8
 *   @0x145ec8 mov r9, r0
 *   @0x145ecc mov r0, r4
 *   @0x145ed0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145ed4 ldr r3, [sp, #0x1c]
 *   @0x145ed8 str r11, [sp, #0x4]
 *   @0x145edc mov r1, r8
 *   @0x145ee0 str r10, [sp, #0x8]
 *   @0x145ee4 mov r2, r7
 *   @0x145ee8 str r3, [sp]
 *   @0x145eec mov r3, r6
 *   @0x145ef0 str r9, [sp, #0xc]
 *   @0x145ef4 str r0, [sp, #0x10]
 *   @0x145ef8 mov r0, r5
 *   @0x145efc bl 0x165bb8 <_Z11GR_3DM_Walliffffffff>
 *   @0x145f00 add sp, sp, #36
 *   @0x145f04 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §72/146 F_D3DModelFloor(RValue&, CInstance*, CInstance*, int, RValue*)  0x145f08  size 208  52 条（0x145f08..0x145fd8）
 * @func 0x145f08 0x145fd8  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×8 / YYGetInt32(RValue const*, int) / GR_3DM_Floor(int, float, float, float, float, float, float, float, float)
 * 字段偏移 top8: 0x1c×2 / 0x48×1 / 0x4×1 / 0x8×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x145f08 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x145f0c sub sp, sp, #36
 *   @0x145f10 mov r1, #0
 *   @0x145f14 ldr r4, [sp, #0x48]
 *   @0x145f18 mov r0, r4
 *   @0x145f1c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x145f20 mov r1, #1
 *   @0x145f24 mov r5, r0
 *   @0x145f28 mov r0, r4
 *   @0x145f2c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145f30 mov r1, #2
 *   @0x145f34 mov r8, r0
 *   @0x145f38 mov r0, r4
 *   @0x145f3c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145f40 mov r1, #3
 *   @0x145f44 mov r7, r0
 *   @0x145f48 mov r0, r4
 *   @0x145f4c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145f50 mov r1, #4
 *   @0x145f54 mov r6, r0
 *   @0x145f58 mov r0, r4
 *   @0x145f5c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145f60 mov r1, #5
 *   @0x145f64 mov r3, r0
 *   @0x145f68 mov r0, r4
 *   @0x145f6c str r3, [sp, #0x1c]
 *   @0x145f70 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145f74 mov r1, #6
 *   @0x145f78 mov r11, r0
 *   @0x145f7c mov r0, r4
 *   @0x145f80 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145f84 mov r1, #7
 *   @0x145f88 mov r10, r0
 *   @0x145f8c mov r0, r4
 *   @0x145f90 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145f94 mov r1, #8
 *   @0x145f98 mov r9, r0
 *   @0x145f9c mov r0, r4
 *   @0x145fa0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145fa4 ldr r3, [sp, #0x1c]
 *   @0x145fa8 str r11, [sp, #0x4]
 *   @0x145fac mov r1, r8
 *   @0x145fb0 str r10, [sp, #0x8]
 *   @0x145fb4 mov r2, r7
 *   @0x145fb8 str r3, [sp]
 *   @0x145fbc mov r3, r6
 *   @0x145fc0 str r9, [sp, #0xc]
 *   @0x145fc4 str r0, [sp, #0x10]
 *   @0x145fc8 mov r0, r5
 *   @0x145fcc bl 0x165c50 <_Z12GR_3DM_Flooriffffffff>
 *   @0x145fd0 add sp, sp, #36
 *   @0x145fd4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §73/146 SGamepadMapping::FindFromGUID(unsigned char const*)  0x152bcc  size 208  52 条（0x152bcc..0x152c9c）
 * @func 0x152bcc 0x152c9c  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6550 / YoYo_GetPlatform_DoWork() / 0xb66d0 / 0xb65d4
 * 字段偏移 top8: 0x24×2 / 0xb4×1 / 0xb0×1 / 0x1×1 / 0x20×1 / 0x70×1 / 0xc×1 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x152bcc push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x152bd0 sub sp, sp, #44
 *   @0x152bd4 ldr r8, [pc, #0xb4]
 *   @0x152bd8 sub r5, r0, #1
 *   @0x152bdc ldr r9, [pc, #0xb0]
 *   @0x152be0 add r6, sp, #32
 *   @0x152be4 ldr r8, [pc, r8]
 *   @0x152be8 mov r4, sp
 *   @0x152bec add r9, pc, r9
 *   @0x152bf0 ldr r3, [r8]
 *   @0x152bf4 str r3, [sp, #0x24]
 *   @0x152bf8 mov r0, r4
 *   @0x152bfc mov r1, r9
 *   @0x152c00 add r4, r4, #2
 *   @0x152c04 ldrb r2, [r5, #0x1]!
 *   @0x152c08 bl 0xb6550 <sprintf@plt>
 *   @0x152c0c cmp r4, r6
 *   @0x152c10 bne 0x152bf8 <_ZN15SGamepadMapping12FindFromGUIDEPKh+0x2c>
 *   @0x152c14 mov r3, #0
 *   @0x152c18 strb r3, [sp, #0x20]
 *   @0x152c1c bl 0x159cf4 <_Z23YoYo_GetPlatform_DoWorkv>
 *   @0x152c20 ldr r3, [pc, #0x70]
 *   @0x152c24 ldr r3, [pc, r3]
 *   @0x152c28 ldr r4, [r3]
 *   @0x152c2c cmp r4, #0
 *   @0x152c30 vmov d7, r0, r1
 *   @0x152c34 vcvt.s32.f64 s15, d7
 *   @0x152c38 vmov r5, s15
 *   @0x152c3c bne 0x152c50 <_ZN15SGamepadMapping12FindFromGUIDEPKh+0x84>
 *   @0x152c40 b 0x152c70 <_ZN15SGamepadMapping12FindFromGUIDEPKh+0xa4>
 *   @0x152c44 ldr r4, [r4]
 *   @0x152c48 cmp r4, #0
 *   @0x152c4c beq 0x152c70 <_ZN15SGamepadMapping12FindFromGUIDEPKh+0xa4>
 *   @0x152c50 ldr r3, [r4, #0xc]
 *   @0x152c54 cmp r3, r5
 *   @0x152c58 bne 0x152c44 <_ZN15SGamepadMapping12FindFromGUIDEPKh+0x78>
 *   @0x152c5c ldr r0, [r4, #0x4]
 *   @0x152c60 mov r1, sp
 *   @0x152c64 bl 0xb66d0 <strcasecmp@plt>
 *   @0x152c68 cmp r0, #0
 *   @0x152c6c bne 0x152c44 <_ZN15SGamepadMapping12FindFromGUIDEPKh+0x78>
 *   @0x152c70 ldr r2, [sp, #0x24]
 *   @0x152c74 mov r0, r4
 *   @0x152c78 ldr r3, [r8]
 *   @0x152c7c cmp r2, r3
 *   @0x152c80 bne 0x152c8c <_ZN15SGamepadMapping12FindFromGUIDEPKh+0xc0>
 *   @0x152c84 add sp, sp, #44
 *   @0x152c88 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x152c8c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x152c90 eoreq r10, r9, r12, ror #26
 *   @0x152c94 ldrheq pc, [sp], -r8
 *   @0x152c98 eoreq r12, r9, r4, asr #28
 *
 * ══ §74/146 F_IO_AddVirtualKey(RValue&, CInstance*, CInstance*, int, RValue*)  0x1563bc  size 208  52 条（0x1563bc..0x15648c）
 * @func 0x1563bc 0x15648c  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×5 / AllocateVirtualKey()
 * 字段偏移 top8: 0x4×3 / 0xc×2 / 0x20×2 / 0x8×2 / 0x14×2 / 0x18×2 / 0x1c×1 / 0x28×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1563bc push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x1563c0 mov r3, #0
 *   @0x1563c4 mov r5, r3
 *   @0x1563c8 movt r3, #0xbff0
 *   @0x1563cc str r5, [r0]
 *   @0x1563d0 mov r6, r0
 *   @0x1563d4 str r3, [r0, #0x4]
 *   @0x1563d8 str r5, [r0, #0xc]
 *   @0x1563dc ldr r7, [sp, #0x20]
 *   @0x1563e0 bl 0x18c590 <_Z18AllocateVirtualKeyv>
 *   @0x1563e4 subs r4, r0, #0
 *   @0x1563e8 popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1563ec mov r0, r7
 *   @0x1563f0 mov r1, r5
 *   @0x1563f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1563f8 mov r1, #1
 *   @0x1563fc str r0, [r4, #0x4]
 *   @0x156400 mov r0, r7
 *   @0x156404 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x156408 mov r1, #2
 *   @0x15640c str r0, [r4, #0x8]
 *   @0x156410 mov r0, r7
 *   @0x156414 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x156418 mov r1, #3
 *   @0x15641c str r0, [r4, #0x14]
 *   @0x156420 mov r0, r7
 *   @0x156424 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x156428 mov r1, #4
 *   @0x15642c str r0, [r4, #0x18]
 *   @0x156430 mov r0, r7
 *   @0x156434 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x156438 ldrsh r2, [r4, #2]
 *   @0x15643c mov r1, #1
 *   @0x156440 ldr r9, [r4, #0x4]
 *   @0x156444 add r2, r2, r1
 *   @0x156448 ldr r7, [r4, #0x14]
 *   @0x15644c ldr r8, [r4, #0x8]
 *   @0x156450 vmov s15, r2
 *   @0x156454 ldr r12, [r4, #0x18]
 *   @0x156458 str r5, [r4, #0x20]
 *   @0x15645c add r7, r9, r7
 *   @0x156460 vcvt.f64.s32 d7, s15
 *   @0x156464 str r5, [r4, #0x1c]
 *   @0x156468 add r12, r8, r12
 *   @0x15646c str r5, [r4, #0x28]
 *   @0x156470 str r7, [r4, #0xc]
 *   @0x156474 str r12, [r4, #0x10]
 *   @0x156478 strh r1, [r4]
 *   @0x15647c vmov r2, r3, d7
 *   @0x156480 str r0, [r4, #0x24]
 *   @0x156484 stm r6, {r2, r3}
 *   @0x156488 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §75/146 GR_Draw_Line(float, float, float, float)  0x16a21c  size 208  52 条（0x16a21c..0x16a2ec）
 * @func 0x16a21c 0x16a2ec  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x16a230→0x4859c0, 0x16a25c→0x3f23d8, 0x16a260→0x3f23d4, 0x16a268→0x4859ac, 0x16a280→0x3f23d0
 * 调用序列: Graphics::AllocVerts(ePrimType, void*, int, int)
 * 字段偏移 top8: 0x78×2 / 0xa4×1 / 0xa0×1 / 0x74×1 / 0x60×1 / 0x8×1 / 0x18×1 / 0xc×1
 * VFP 指令 19 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16a21c push {r4, lr}
 *   @0x16a220 vpush {d8, d9}
 *   @0x16a224 vmov s18, r1
 *   @0x16a228 ldr r4, [pc, #0xa4]
 *   @0x16a22c vmov s19, r0
 *   @0x16a230 ldr r12, [pc, #0xa0]
 *   @0x16a234 mov r0, #2
 *   @0x16a238 add r4, pc, r4
 *   @0x16a23c vmov s16, r3
 *   @0x16a240 vmov s17, r2
 *   @0x16a244 mov r3, r0
 *   @0x16a248 ldr r1, [r4, r12]
 *   @0x16a24c mov r2, #16
 *   @0x16a250 ldr r1, [r1]
 *   @0x16a254 ldr r1, [r1]
 *   @0x16a258 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x16a25c ldr r1, [pc, #0x78]
 *   @0x16a260 ldr r2, [pc, #0x78]
 *   @0x16a264 vldr s13, [pc, #100]
 *   @0x16a268 ldr r3, [pc, #0x74]
 *   @0x16a26c ldr r1, [r4, r1]
 *   @0x16a270 vldr s14, [r1]
 *   @0x16a274 ldr r2, [r4, r2]
 *   @0x16a278 vmul.f32 s14, s14, s13
 *   @0x16a27c vldr s15, [r2]
 *   @0x16a280 ldr r2, [pc, #0x60]
 *   @0x16a284 vmul.f32 s15, s15, s13
 *   @0x16a288 vadd.f32 s19, s14, s19
 *   @0x16a28c vadd.f32 s18, s15, s18
 *   @0x16a290 vstr s19, [r0]
 *   @0x16a294 vstr s18, [r0, #4]
 *   @0x16a298 ldr r3, [r4, r3]
 *   @0x16a29c vadd.f32 s14, s14, s17
 *   @0x16a2a0 ldr r3, [r3]
 *   @0x16a2a4 str r3, [r0, #0x8]
 *   @0x16a2a8 ldr r2, [r4, r2]
 *   @0x16a2ac str r3, [r0, #0x18]
 *   @0x16a2b0 ldr r3, [r2]
 *   @0x16a2b4 vadd.f32 s15, s15, s16
 *   @0x16a2b8 vstr s14, [r0, #16]
 *   @0x16a2bc vpop {d8, d9}
 *   @0x16a2c0 str r3, [r0, #0xc]
 *   @0x16a2c4 str r3, [r0, #0x1c]
 *   @0x16a2c8 vstr s15, [r0, #20]
 *   @0x16a2cc pop {r4, pc}
 *   @0x16a2d0 stclo p7, c13, [r3], #-40
 *   @0x16a2d4 eoreq r7, r8, r8, lsl r10
 *   @0x16a2d8 .word 0xffffe4e0
 *   @0x16a2dc .word 0xffffe524
 *   @0x16a2e0 .word 0xffffe520
 *   @0x16a2e4 .word 0xffffbcd0
 *   @0x16a2e8 .word 0xffffc0ac
 *
 * ══ §76/146 GraphicsPerf::cprintf(float, float, unsigned int, char const*, ...)  0x17c508  size 208  52 条（0x17c508..0x17c5d8）
 * @func 0x17c508 0x17c5d8  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb667c / GraphicsPerf::strwidth(char const*, int) / GraphicsPerf::Print(float, float, float, float, unsigned int, char*, int) / 0xb65d4
 * 字段偏移 top8: 0x814×2 / 0x-4×1 / 0xb4×1 / 0x834×1 / 0x10×1 / 0x8×1 / 0x4×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17c508 str r3, [sp, #-0x4]!
 *   @0x17c50c push {r4, r5, r6, r7, lr}
 *   @0x17c510 vpush {d8}
 *   @0x17c514 sub sp, sp, #2064
 *   @0x17c518 ldr r4, [pc, #0xb4]
 *   @0x17c51c sub sp, sp, #8
 *   @0x17c520 add r3, sp, #2096
 *   @0x17c524 add r5, sp, #20
 *   @0x17c528 ldr r4, [pc, r4]
 *   @0x17c52c ldr lr, [sp, #0x834]
 *   @0x17c530 add r3, r3, #8
 *   @0x17c534 mov r6, r0
 *   @0x17c538 ldr r12, [r4]
 *   @0x17c53c mov r7, r2
 *   @0x17c540 vmov s16, r1
 *   @0x17c544 mov r2, r3
 *   @0x17c548 mov r1, lr
 *   @0x17c54c mov r0, r5
 *   @0x17c550 str r3, [sp, #0x10]
 *   @0x17c554 str r12, [sp, #0x814]
 *   @0x17c558 bl 0xb667c <vsprintf@plt>
 *   @0x17c55c mvn r1, #-2147483648
 *   @0x17c560 mov r0, r5
 *   @0x17c564 bl 0x17c49c <_ZN12GraphicsPerf8strwidthEPKci>
 *   @0x17c568 vmov.f32 s15, #1.000000e+00
 *   @0x17c56c mvn r3, #-2147483648
 *   @0x17c570 str r7, [sp]
 *   @0x17c574 str r3, [sp, #0x8]
 *   @0x17c578 mov r1, r6
 *   @0x17c57c str r5, [sp, #0x4]
 *   @0x17c580 vadd.f32 s16, s16, s15
 *   @0x17c584 vmov r2, s15
 *   @0x17c588 vmov.f32 s15, #5.000000e-01
 *   @0x17c58c mov r3, r2
 *   @0x17c590 vmov s13, r0
 *   @0x17c594 vcvt.f32.s32 s14, s13
 *   @0x17c598 vsub.f32 s16, s16, s14
 *   @0x17c59c vmul.f32 s15, s16, s15
 *   @0x17c5a0 vmov r0, s15
 *   @0x17c5a4 bl 0x17c030 <_ZN12GraphicsPerf5PrintEffffjPci>
 *   @0x17c5a8 ldr r2, [sp, #0x814]
 *   @0x17c5ac ldr r3, [r4]
 *   @0x17c5b0 cmp r2, r3
 *   @0x17c5b4 bne 0x17c5d0 <_ZN12GraphicsPerf7cprintfEffjPKcz+0xc8>
 *   @0x17c5b8 add sp, sp, #2064
 *   @0x17c5bc add sp, sp, #8
 *   @0x17c5c0 vpop {d8}
 *   @0x17c5c4 pop {r4, r5, r6, r7, lr}
 *   @0x17c5c8 add sp, sp, #4
 *   @0x17c5cc bx lr
 *   @0x17c5d0 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x17c5d4 eoreq r1, r7, r8, lsr #8
 *
 * ══ §77/146 ReadPNGFileHeader(void*, int, int*, int*, bool)  0x18a54c  size 208  52 条（0x18a54c..0x18a61c）
 * @func 0x18a54c 0x18a61c  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __divsi3×2 / FreePNGFile() / operator new(unsigned int) / ReadPNGHeader(yyPNGFile*) / operator delete(void*)
 * 字段偏移 top8: 0x4×3 / 0xb8×1 / 0xb4×1 / 0x28×1 / 0xc×1 / 0x10×1 / 0x20×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18a54c push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x18a550 sub sp, sp, #12
 *   @0x18a554 ldr r5, [pc, #0xb8]
 *   @0x18a558 mov r7, r0
 *   @0x18a55c ldr r12, [pc, #0xb4]
 *   @0x18a560 mov r9, r2
 *   @0x18a564 ldrb lr, [sp, #0x28]
 *   @0x18a568 ldr r5, [pc, r5]
 *   @0x18a56c ldr r12, [pc, r12]
 *   @0x18a570 mov r8, r3
 *   @0x18a574 cmp lr, #0
 *   @0x18a578 ldr r6, [r5]
 *   @0x18a57c ldr r4, [r12]
 *   @0x18a580 moveq r4, #1
 *   @0x18a584 cmp r6, #0
 *   @0x18a588 beq 0x18a5c0 <_Z17ReadPNGFileHeaderPviPiS0_b+0x74>
 *   @0x18a58c ldr r0, [r6, #0xc]
 *   @0x18a590 mov r1, r4
 *   @0x18a594 bl 0x318d10 <__divsi3>
 *   @0x18a598 mov r1, r4
 *   @0x18a59c mov r7, #1
 *   @0x18a5a0 str r0, [r9]
 *   @0x18a5a4 ldr r0, [r6, #0x10]
 *   @0x18a5a8 bl 0x318d10 <__divsi3>
 *   @0x18a5ac str r0, [r8]
 *   @0x18a5b0 bl 0x18a518 <_Z11FreePNGFilev>
 *   @0x18a5b4 mov r0, r7
 *   @0x18a5b8 add sp, sp, #12
 *   @0x18a5bc pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x18a5c0 mov r0, #40
 *   @0x18a5c4 str r1, [sp, #0x4]
 *   @0x18a5c8 bl 0x27c524 <_Znwj>
 *   @0x18a5cc ldr r1, [sp, #0x4]
 *   @0x18a5d0 strb r6, [r0]
 *   @0x18a5d4 str r7, [r0, #0x4]
 *   @0x18a5d8 str r6, [r0, #0x20]
 *   @0x18a5dc str r6, [r0, #0x24]
 *   @0x18a5e0 str r1, [r0, #0x8]
 *   @0x18a5e4 str r0, [r5]
 *   @0x18a5e8 bl 0x189b78 <_Z13ReadPNGHeaderP9yyPNGFile>
 *   @0x18a5ec subs r7, r0, #0
 *   @0x18a5f0 ldrne r6, [r5]
 *   @0x18a5f4 bne 0x18a58c <_Z17ReadPNGFileHeaderPviPiS0_b+0x40>
 *   @0x18a5f8 ldr r0, [r5]
 *   @0x18a5fc bl 0x27d1d0 <_ZdlPv>
 *   @0x18a600 str r7, [r5]
 *   @0x18a604 mvn r3, #0
 *   @0x18a608 str r3, [r9]
 *   @0x18a60c str r3, [r8]
 *   @0x18a610 b 0x18a5b4 <_Z17ReadPNGFileHeaderPviPiS0_b+0x68>
 *   @0x18a614 eoreq r6, r6, r8, asr r0
 *   @0x18a618 eoreq r4, r6, r8, rrx
 *
 * ══ §78/146 CPath::Rotate(float)  0x1a787c  size 208  52 条（0x1a787c..0x1a794c）
 * @func 0x1a787c 0x1a794c  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPath::Shift(float, float)×2 / CPath::Center(float&, float&) / CPath::Rotate(float)+0xa4 / 0xb658c / 0xb6580 / CPath::ComputeInternal()
 * 字段偏移 top8: 0x4×3 / 0x10×1
 * VFP 指令 19 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a787c push {r4, r5, lr}
 *   @0x1a7880 vpush {d8}
 *   @0x1a7884 sub sp, sp, #12
 *   @0x1a7888 add r2, sp, #4
 *   @0x1a788c vmov s16, r1
 *   @0x1a7890 mov r1, sp
 *   @0x1a7894 mov r4, r0
 *   @0x1a7898 bl 0x1a7610 <_ZN5CPath6CenterERfS0_>
 *   @0x1a789c ldr r1, [sp]
 *   @0x1a78a0 ldr r2, [sp, #0x4]
 *   @0x1a78a4 mov r0, r4
 *   @0x1a78a8 eor r1, r1, #-2147483648
 *   @0x1a78ac eor r2, r2, #-2147483648
 *   @0x1a78b0 bl 0x1a7734 <_ZN5CPath5ShiftEff>
 *   @0x1a78b4 ldr r5, [r4, #0x10]
 *   @0x1a78b8 cmp r5, #0
 *   @0x1a78bc ble 0x1a7920 <_ZN5CPath6RotateEf+0xa4>
 *   @0x1a78c0 vldr s17, [pc, #124]
 *   @0x1a78c4 vmul.f32 s17, s16, s17
 *   @0x1a78c8 vldr s15, [pc, #120]
 *   @0x1a78cc add r5, r5, r5, lsl #1
 *   @0x1a78d0 vdiv.f32 s17, s17, s15
 *   @0x1a78d4 vmov r0, s17
 *   @0x1a78d8 bl 0xb658c <cosf@plt>
 *   @0x1a78dc vmov s16, r0
 *   @0x1a78e0 vmov r0, s17
 *   @0x1a78e4 bl 0xb6580 <sinf@plt>
 *   @0x1a78e8 ldr r3, [r4, #0x4]
 *   @0x1a78ec add r2, r3, r5, lsl #2
 *   @0x1a78f0 vmov s11, r0
 *   @0x1a78f4 vldr s13, [r3]
 *   @0x1a78f8 vldr s12, [r3, #4]
 *   @0x1a78fc vmul.f32 s14, s13, s11
 *   @0x1a7900 add r3, r3, #12
 *   @0x1a7904 vmul.f32 s15, s12, s11
 *   @0x1a7908 vnmls.f32 s14, s12, s16
 *   @0x1a790c vmla.f32 s15, s13, s16
 *   @0x1a7910 vstr s14, [r3, #-8]
 *   @0x1a7914 vstr s15, [r3, #-12]
 *   @0x1a7918 cmp r3, r2
 *   @0x1a791c bne 0x1a78f4 <_ZN5CPath6RotateEf+0x78>
 *   @0x1a7920 mov r0, r4
 *   @0x1a7924 ldr r1, [sp]
 *   @0x1a7928 ldr r2, [sp, #0x4]
 *   @0x1a792c bl 0x1a7734 <_ZN5CPath5ShiftEff>
 *   @0x1a7930 mov r0, r4
 *   @0x1a7934 bl 0x1a6e30 <_ZN5CPath15ComputeInternalEv>
 *   @0x1a7938 add sp, sp, #12
 *   @0x1a793c vpop {d8}
 *   @0x1a7940 pop {r4, r5, pc}
 *   @0x1a7944 ldrdmi r0, r1, [r9], #-251
 *   @0x1a7948 teqmi r4, #0
 *
 * ══ §79/146 CPath::Append(CPath*)  0x1a79e8  size 208  52 条（0x1a79e8..0x1a7ab8）
 * @func 0x1a79e8 0x1a7ab8  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPath::Append(CPath*)+0x88 / MemoryManager::SetLength(void**, unsigned int, char const*, int)
 * 字段偏移 top8: 0x10×7 / 0x4×4 / 0x8×2 / 0x2×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a79e8 push {r4, r5, r6, r7, r8, lr}
 *   @0x1a79ec subs r8, r1, #0
 *   @0x1a79f0 mov r7, r0
 *   @0x1a79f4 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x1a79f8 ldr r2, [r8, #0x10]
 *   @0x1a79fc cmp r2, #0
 *   @0x1a7a00 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x1a7a04 ldr r6, [r0, #0x10]
 *   @0x1a7a08 ldr r1, [r0]
 *   @0x1a7a0c add r3, r2, r6
 *   @0x1a7a10 cmp r3, r1
 *   @0x1a7a14 bgt 0x1a7a84 <_ZN5CPath6AppendEPS_+0x9c>
 *   @0x1a7a18 cmp r2, #0
 *   @0x1a7a1c ble 0x1a7a70 <_ZN5CPath6AppendEPS_+0x88>
 *   @0x1a7a20 mov r12, #0
 *   @0x1a7a24 mov r3, r12
 *   @0x1a7a28 ldr r2, [r8, #0x4]
 *   @0x1a7a2c add r6, r3, r6
 *   @0x1a7a30 ldr r5, [r7, #0x4]
 *   @0x1a7a34 add r3, r3, #1
 *   @0x1a7a38 add r2, r2, r12
 *   @0x1a7a3c add r6, r6, r6, lsl #1
 *   @0x1a7a40 add r12, r12, #12
 *   @0x1a7a44 ldr r0, [r2]
 *   @0x1a7a48 add r4, r5, r6, lsl #2
 *   @0x1a7a4c ldr r1, [r2, #0x4]
 *   @0x1a7a50 ldr r2, [r2, #0x8]
 *   @0x1a7a54 str r0, [r5, r6, lsl #2]
 *   @0x1a7a58 str r1, [r4, #0x4]
 *   @0x1a7a5c str r2, [r4, #0x8]
 *   @0x1a7a60 ldr r2, [r8, #0x10]
 *   @0x1a7a64 ldr r6, [r7, #0x10]
 *   @0x1a7a68 cmp r2, r3
 *   @0x1a7a6c bgt 0x1a7a28 <_ZN5CPath6AppendEPS_+0x40>
 *   @0x1a7a70 add r6, r2, r6
 *   @0x1a7a74 mov r0, r7
 *   @0x1a7a78 str r6, [r7, #0x10]
 *   @0x1a7a7c pop {r4, r5, r6, r7, r8, lr}
 *   @0x1a7a80 b 0x1a6e30 <_ZN5CPath15ComputeInternalEv>
 *   @0x1a7a84 add r1, r3, r3, lsl #1
 *   @0x1a7a88 ldr r2, [pc, #0x24]
 *   @0x1a7a8c add r0, r0, #4
 *   @0x1a7a90 movw r3, #0x381
 *   @0x1a7a94 add r2, pc, r2
 *   @0x1a7a98 lsl r1, r1, #2
 *   @0x1a7a9c bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1a7aa0 ldr r2, [r8, #0x10]
 *   @0x1a7aa4 ldr r6, [r7, #0x10]
 *   @0x1a7aa8 cmp r2, #0
 *   @0x1a7aac bgt 0x1a7a20 <_ZN5CPath6AppendEPS_+0x38>
 *   @0x1a7ab0 b 0x1a7a70 <_ZN5CPath6AppendEPS_+0x88>
 *   @0x1a7ab4 andseq r5, r10, r4, asr #12
 *
 * ══ §80/146 TBitmap::Setup()  0x1a8d14  size 208  52 条（0x1a8d14..0x1a8de4）
 * @func 0x1a8d14 0x1a8de4  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetTPixelFormat(int)
 * 字段偏移 top8: 0x18×7 / 0x20×6 / 0x14×2 / 0x4×1 / 0x8×1 / 0x10×1 / 0x1a×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a8d14 ldr r3, [r0, #0x4]
 *   @0x1a8d18 push {r4, lr}
 *   @0x1a8d1c mov r4, r0
 *   @0x1a8d20 ldr r12, [r3, #0x8]
 *   @0x1a8d24 ldr r1, [r3, #0x10]
 *   @0x1a8d28 ldr r2, [r3, #0x14]
 *   @0x1a8d2c sub r12, r12, #2
 *   @0x1a8d30 ldrh r0, [r3, #26]
 *   @0x1a8d34 add r12, r3, r12
 *   @0x1a8d38 str r1, [r4, #0x18]
 *   @0x1a8d3c str r12, [r4, #0xc]
 *   @0x1a8d40 str r2, [r4, #0x1c]
 *   @0x1a8d44 bl 0x1a8b28 <_Z15GetTPixelFormati>
 *   @0x1a8d48 sub r3, r0, #1
 *   @0x1a8d4c str r0, [r4, #0x14]
 *   @0x1a8d50 cmp r3, #6
 *   @0x1a8d54 addls pc, pc, r3, lsl #2
 *   @0x1a8d58 b 0x1a8d84 <_ZN7TBitmap5SetupEv+0x70>
 *   @0x1a8d5c b 0x1a8da8 <_ZN7TBitmap5SetupEv+0x94>
 *   @0x1a8d60 b 0x1a8dc4 <_ZN7TBitmap5SetupEv+0xb0>
 *   @0x1a8d64 b 0x1a8dd8 <_ZN7TBitmap5SetupEv+0xc4>
 *   @0x1a8d68 b 0x1a8d88 <_ZN7TBitmap5SetupEv+0x74>
 *   @0x1a8d6c b 0x1a8d88 <_ZN7TBitmap5SetupEv+0x74>
 *   @0x1a8d70 b 0x1a8d98 <_ZN7TBitmap5SetupEv+0x84>
 *   @0x1a8d74 b 0x1a8d78 <_ZN7TBitmap5SetupEv+0x64>
 *   @0x1a8d78 ldr r3, [r4, #0x18]
 *   @0x1a8d7c lsl r3, r3, #2
 *   @0x1a8d80 str r3, [r4, #0x20]
 *   @0x1a8d84 pop {r4, pc}
 *   @0x1a8d88 ldr r3, [r4, #0x18]
 *   @0x1a8d8c lsl r3, r3, #1
 *   @0x1a8d90 str r3, [r4, #0x20]
 *   @0x1a8d94 pop {r4, pc}
 *   @0x1a8d98 ldr r3, [r4, #0x18]
 *   @0x1a8d9c add r3, r3, r3, lsl #1
 *   @0x1a8da0 str r3, [r4, #0x20]
 *   @0x1a8da4 pop {r4, pc}
 *   @0x1a8da8 ldr r3, [r4, #0x18]
 *   @0x1a8dac add r2, r3, #7
 *   @0x1a8db0 cmp r3, #0
 *   @0x1a8db4 movlt r3, r2
 *   @0x1a8db8 asr r3, r3, #3
 *   @0x1a8dbc str r3, [r4, #0x20]
 *   @0x1a8dc0 pop {r4, pc}
 *   @0x1a8dc4 ldr r3, [r4, #0x18]
 *   @0x1a8dc8 add r3, r3, r3, lsr #31
 *   @0x1a8dcc asr r3, r3, #1
 *   @0x1a8dd0 str r3, [r4, #0x20]
 *   @0x1a8dd4 pop {r4, pc}
 *   @0x1a8dd8 ldr r3, [r4, #0x18]
 *   @0x1a8ddc str r3, [r4, #0x20]
 *   @0x1a8de0 pop {r4, pc}
 *
 * ══ §81/146 F_LayerTileGetRegion(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bfec4  size 208  52 条（0x1bfec4..0x1bff94）
 * @func 0x1bfec4 0x1bff94  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / CreateArray(RValue*, int, ...)
 * 字段偏移 top8: 0xc×1 / 0x4×1 / 0x30×1 / 0x94×1 / 0x48×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bfec4 push {r4, r5, r6, r7, lr}
 *   @0x1bfec8 cmp r3, #1
 *   @0x1bfecc sub sp, sp, #28
 *   @0x1bfed0 mov r3, #0
 *   @0x1bfed4 mov r4, r3
 *   @0x1bfed8 mov r5, r0
 *   @0x1bfedc movt r3, #0xbff0
 *   @0x1bfee0 str r4, [r0, #0xc]
 *   @0x1bfee4 str r3, [r0, #0x4]
 *   @0x1bfee8 str r4, [r0]
 *   @0x1bfeec ldr r6, [sp, #0x30]
 *   @0x1bfef0 beq 0x1bff0c <_Z20F_LayerTileGetRegionR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x1bfef4 ldr r0, [pc, #0x94]
 *   @0x1bfef8 mov r1, r4
 *   @0x1bfefc add r0, pc, r0
 *   @0x1bff00 add sp, sp, #28
 *   @0x1bff04 pop {r4, r5, r6, r7, lr}
 *   @0x1bff08 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bff0c bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1bff10 mov r1, r4
 *   @0x1bff14 mov r7, r0
 *   @0x1bff18 mov r0, r6
 *   @0x1bff1c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1bff20 mov r2, r4
 *   @0x1bff24 mov r1, r0
 *   @0x1bff28 mov r0, r7
 *   @0x1bff2c bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1bff30 subs r12, r0, #0
 *   @0x1bff34 beq 0x1bff44 <_Z20F_LayerTileGetRegionR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x1bff38 ldr r3, [r12]
 *   @0x1bff3c cmp r3, #7
 *   @0x1bff40 beq 0x1bff4c <_Z20F_LayerTileGetRegionR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x1bff44 add sp, sp, #28
 *   @0x1bff48 pop {r4, r5, r6, r7, pc}
 *   @0x1bff4c vldr s13, [r12, #76]
 *   @0x1bff50 vcvt.f64.s32 d7, s13
 *   @0x1bff54 ldr r2, [r12, #0x48]
 *   @0x1bff58 mov r0, r5
 *   @0x1bff5c mov r1, #4
 *   @0x1bff60 vstr d7, [sp]
 *   @0x1bff64 vmov s15, r2
 *   @0x1bff68 vldr s13, [r12, #44]
 *   @0x1bff6c vcvt.f64.s32 d7, s15
 *   @0x1bff70 vmov r2, r3, d7
 *   @0x1bff74 vcvt.f64.s32 d7, s13
 *   @0x1bff78 vstr d7, [sp, #8]
 *   @0x1bff7c vldr s14, [r12, #48]
 *   @0x1bff80 vcvt.f64.s32 d7, s14
 *   @0x1bff84 vstr d7, [sp, #16]
 *   @0x1bff88 bl 0x120eb4 <_Z11CreateArrayP6RValueiz>
 *   @0x1bff8c b 0x1bff44 <_Z20F_LayerTileGetRegionR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x1bff90 andseq pc, r8, r0, lsr #14
 *
 * ══ §82/146 CSprite::DrawPos(int, float, float, float, float, float, float, float, float, unsigned int, float)  0x1e5d64  size 208  52 条（0x1e5d64..0x1e5e34）
 * @func 0x1e5d64 0x1e5e34  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSprite::DrawPos(int, float, float, float, float, float, float, float, float, unsigned int, float)+0x94 / __aeabi_idivmod / GR_Texture_Draw_Pos(YYTPageEntry*, float, float, float, float, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0x24×2 / 0x18×1 / 0x54×1 / 0x50×1 / 0x2×1 / 0x14×1 / 0x38×1 / 0x5c×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e5d64 push {r4, r5, r6, r7, lr}
 *   @0x1e5d68 mov r4, r0
 *   @0x1e5d6c ldr r5, [r0, #0x18]
 *   @0x1e5d70 sub sp, sp, #36
 *   @0x1e5d74 mov r6, r2
 *   @0x1e5d78 mov r7, r3
 *   @0x1e5d7c cmp r5, #0
 *   @0x1e5d80 ble 0x1e5df8 <_ZN7CSprite7DrawPosEiffffffffjf+0x94>
 *   @0x1e5d84 mov r0, r1
 *   @0x1e5d88 mov r1, r5
 *   @0x1e5d8c bl 0x318dec <__aeabi_idivmod>
 *   @0x1e5d90 ldr r0, [r4, #0x54]
 *   @0x1e5d94 cmp r1, #0
 *   @0x1e5d98 addlt r1, r1, r5
 *   @0x1e5d9c cmp r0, #0
 *   @0x1e5da0 beq 0x1e5df8 <_ZN7CSprite7DrawPosEiffffffffjf+0x94>
 *   @0x1e5da4 ldr r3, [sp, #0x50]
 *   @0x1e5da8 vldr s15, [sp, #60]
 *   @0x1e5dac ldr r0, [r0, r1, lsl #2]
 *   @0x1e5db0 mov r2, r7
 *   @0x1e5db4 vstr s15, [sp]
 *   @0x1e5db8 mov r1, r6
 *   @0x1e5dbc vldr s15, [sp, #64]
 *   @0x1e5dc0 str r3, [sp, #0x14]
 *   @0x1e5dc4 vstr s15, [sp, #4]
 *   @0x1e5dc8 ldr r3, [sp, #0x38]
 *   @0x1e5dcc vldr s15, [sp, #68]
 *   @0x1e5dd0 vstr s15, [sp, #8]
 *   @0x1e5dd4 vldr s15, [sp, #72]
 *   @0x1e5dd8 vstr s15, [sp, #12]
 *   @0x1e5ddc vldr s15, [sp, #76]
 *   @0x1e5de0 vstr s15, [sp, #16]
 *   @0x1e5de4 vldr s15, [sp, #84]
 *   @0x1e5de8 vstr s15, [sp, #24]
 *   @0x1e5dec bl 0x17467c <_Z19GR_Texture_Draw_PosP12YYTPageEntryffffffffjf>
 *   @0x1e5df0 cmp r0, #0
 *   @0x1e5df4 beq 0x1e5e00 <_ZN7CSprite7DrawPosEiffffffffjf+0x9c>
 *   @0x1e5df8 add sp, sp, #36
 *   @0x1e5dfc pop {r4, r5, r6, r7, pc}
 *   @0x1e5e00 ldr r3, [pc, #0x24]
 *   @0x1e5e04 ldr r1, [pc, #0x24]
 *   @0x1e5e08 ldr r3, [pc, r3]
 *   @0x1e5e0c ldr r2, [r4, #0x5c]
 *   @0x1e5e10 add r1, pc, r1
 *   @0x1e5e14 ldr r0, [r3]
 *   @0x1e5e18 ldr r3, [r0]
 *   @0x1e5e1c ldr r3, [r3, #0xc]
 *   @0x1e5e20 blx r3
 *   @0x1e5e24 add sp, sp, #36
 *   @0x1e5e28 pop {r4, r5, r6, r7, pc}
 *   @0x1e5e2c eoreq r7, r0, r12, lsl #18
 *   @0x1e5e30 andseq r12, r6, r4, lsl #15
 *
 * ══ §83/146 CDS_Map::MarkOnlyChildren4GC(unsigned int*, int)  0x203878  size 208  52 条（0x203878..0x203948）
 * @func 0x203878 0x203948  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RVALUE_GC_THISONLY(RValue const*, unsigned int*, int)×2
 * 字段偏移 top8: 0x4×3 / 0x3×1 / 0xc×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x203878 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x20387c mov r8, r2
 *   @0x203880 ldr r9, [r0]
 *   @0x203884 mov r7, r1
 *   @0x203888 mov r5, #0
 *   @0x20388c ldr r2, [r9]
 *   @0x203890 b 0x2038a4 <_ZN7CDS_Map19MarkOnlyChildren4GCEPji+0x2c>
 *   @0x203894 ldr r3, [r9, #0x4]
 *   @0x203898 add r5, r5, #1
 *   @0x20389c cmp r5, r3
 *   @0x2038a0 bgt 0x203938 <_ZN7CDS_Map19MarkOnlyChildren4GCEPji+0xc0>
 *   @0x2038a4 ldr r4, [r2, r5, lsl #3]
 *   @0x2038a8 cmp r4, #0
 *   @0x2038ac beq 0x203894 <_ZN7CDS_Map19MarkOnlyChildren4GCEPji+0x1c>
 *   @0x2038b0 cmp r4, #0
 *   @0x2038b4 popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2038b8 ldr r6, [r4, #0xc]
 *   @0x2038bc cmp r6, #0
 *   @0x2038c0 beq 0x203930 <_ZN7CDS_Map19MarkOnlyChildren4GCEPji+0xb8>
 *   @0x2038c4 mov r0, r6
 *   @0x2038c8 mov r1, r7
 *   @0x2038cc mov r2, r8
 *   @0x2038d0 bl 0x191f5c <_Z18RVALUE_GC_THISONLYPK6RValuePji>
 *   @0x2038d4 add r0, r6, #16
 *   @0x2038d8 mov r1, r7
 *   @0x2038dc mov r2, r8
 *   @0x2038e0 bl 0x191f5c <_Z18RVALUE_GC_THISONLYPK6RValuePji>
 *   @0x2038e4 ldr r4, [r4, #0x4]
 *   @0x2038e8 cmp r4, #0
 *   @0x2038ec bne 0x2038b0 <_ZN7CDS_Map19MarkOnlyChildren4GCEPji+0x38>
 *   @0x2038f0 ldr r12, [r9, #0x4]
 *   @0x2038f4 add r3, r5, #1
 *   @0x2038f8 cmp r3, r12
 *   @0x2038fc popgt {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x203900 ldr r0, [r9]
 *   @0x203904 add r0, r0, r5, lsl #3
 *   @0x203908 b 0x203914 <_ZN7CDS_Map19MarkOnlyChildren4GCEPji+0x9c>
 *   @0x20390c cmp r3, r12
 *   @0x203910 bgt 0x203934 <_ZN7CDS_Map19MarkOnlyChildren4GCEPji+0xbc>
 *   @0x203914 ldr r4, [r0, #0x8]
 *   @0x203918 mov r5, r3
 *   @0x20391c add r0, r0, #8
 *   @0x203920 add r3, r3, #1
 *   @0x203924 cmp r4, #0
 *   @0x203928 beq 0x20390c <_ZN7CDS_Map19MarkOnlyChildren4GCEPji+0x94>
 *   @0x20392c b 0x2038b0 <_ZN7CDS_Map19MarkOnlyChildren4GCEPji+0x38>
 *   @0x203930 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x203934 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x203938 cmp r4, #0
 *   @0x20393c mvn r5, #0
 *   @0x203940 bne 0x2038b8 <_ZN7CDS_Map19MarkOnlyChildren4GCEPji+0x40>
 *   @0x203944 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §84/146 CEmitter::~CEmitter()  0x21580c  size 208  52 条（0x21580c..0x2158dc）
 * @func 0x21580c 0x2158dc  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / CEmitter::Clear() / CEmitter::~CEmitter()+0xa0 / CNoise::~CNoise() / operator delete(void*) / CEmitter::~CEmitter()+0x34
 * 字段偏移 top8: 0x38×5 / 0x34×3 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21580c push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x215810 mov r7, r0
 *   @0x215814 bl 0x215808 <_ZN8CEmitter5ClearEv>
 *   @0x215818 ldr r12, [r7, #0x34]
 *   @0x21581c cmp r12, #0
 *   @0x215820 beq 0x2158c4 <_ZN8CEmitterD2Ev+0xb8>
 *   @0x215824 ldr r5, [r7, #0x38]
 *   @0x215828 cmp r5, #0
 *   @0x21582c beq 0x2158cc <_ZN8CEmitterD2Ev+0xc0>
 *   @0x215830 cmp r12, #0
 *   @0x215834 ble 0x2158ac <_ZN8CEmitterD2Ev+0xa0>
 *   @0x215838 mov r4, #0
 *   @0x21583c mov r9, r4
 *   @0x215840 ldr r1, [r5]
 *   @0x215844 movw r3, #0xfeee
 *   @0x215848 movt r3, #0xfeee
 *   @0x21584c movw r2, #0xfeee
 *   @0x215850 cmp r1, r3
 *   @0x215854 movt r2, #0xfeee
 *   @0x215858 lsl r8, r4, #2
 *   @0x21585c beq 0x2158a0 <_ZN8CEmitterD2Ev+0x94>
 *   @0x215860 ldr r6, [r5, r4, lsl #2]
 *   @0x215864 add r3, r5, r8
 *   @0x215868 cmp r6, #0
 *   @0x21586c mov r0, r6
 *   @0x215870 beq 0x2158a0 <_ZN8CEmitterD2Ev+0x94>
 *   @0x215874 ldr r1, [r6]
 *   @0x215878 cmp r1, r2
 *   @0x21587c beq 0x215898 <_ZN8CEmitterD2Ev+0x8c>
 *   @0x215880 bl 0x21db28 <_ZN6CNoiseD2Ev>
 *   @0x215884 mov r0, r6
 *   @0x215888 bl 0x27d1d0 <_ZdlPv>
 *   @0x21588c ldr r3, [r7, #0x38]
 *   @0x215890 ldr r12, [r7, #0x34]
 *   @0x215894 add r3, r3, r8
 *   @0x215898 str r9, [r3]
 *   @0x21589c ldr r5, [r7, #0x38]
 *   @0x2158a0 add r4, r4, #1
 *   @0x2158a4 cmp r4, r12
 *   @0x2158a8 blt 0x215840 <_ZN8CEmitterD2Ev+0x34>
 *   @0x2158ac mov r0, r5
 *   @0x2158b0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2158b4 mov r3, #0
 *   @0x2158b8 str r3, [r7, #0x38]
 *   @0x2158bc mov r3, #0
 *   @0x2158c0 str r3, [r7, #0x34]
 *   @0x2158c4 mov r0, r7
 *   @0x2158c8 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2158cc mov r0, r5
 *   @0x2158d0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2158d4 str r5, [r7, #0x38]
 *   @0x2158d8 b 0x2158bc <_ZN8CEmitterD2Ev+0xb0>
 *
 * ══ §85/146 setGainForSoundImmediate(int, float)  0x217688  size 208  52 条（0x217688..0x217758）
 * @func 0x217688 0x217758  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_GetGainFromSoundID(int) / setGainForSoundImmediate(int, float)+0xc0 / setGainForSoundImmediate(int, float)+0x30 / 0xb6a78
 * 字段偏移 top8: 0x38×3 / 0xb4×1 / 0x18×1 / 0x5×1 / 0x8×1 / 0x10×1 / 0x34×1 / 0x2×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x217688 push {r3, r4, r5, r6, r7, lr}
 *   @0x21768c vpush {d8}
 *   @0x217690 mov r7, r0
 *   @0x217694 ldr r5, [pc, #0xb4]
 *   @0x217698 add r5, pc, r5
 *   @0x21769c ldr r6, [r5, #0x38]
 *   @0x2176a0 bl 0x217060 <_Z24Audio_GetGainFromSoundIDi>
 *   @0x2176a4 cmp r6, #0
 *   @0x2176a8 vmov s16, r0
 *   @0x2176ac ble 0x217748 <_Z24setGainForSoundImmediateif+0xc0>
 *   @0x2176b0 mov r4, #0
 *   @0x2176b4 b 0x2176c4 <_Z24setGainForSoundImmediateif+0x3c>
 *   @0x2176b8 add r4, r4, #1
 *   @0x2176bc cmp r4, r6
 *   @0x2176c0 beq 0x217748 <_Z24setGainForSoundImmediateif+0xc0>
 *   @0x2176c4 ldr r3, [r5, #0x38]
 *   @0x2176c8 cmp r3, r4
 *   @0x2176cc ldrgt r3, [r5, #0x3c]
 *   @0x2176d0 movle r3, #0
 *   @0x2176d4 ldrgt r3, [r3, r4, lsl #2]
 *   @0x2176d8 ldr r2, [r3, #0x18]
 *   @0x2176dc cmp r2, r7
 *   @0x2176e0 bne 0x2176b8 <_Z24setGainForSoundImmediateif+0x30>
 *   @0x2176e4 ldrb r2, [r3, #0x5]
 *   @0x2176e8 cmp r2, #0
 *   @0x2176ec beq 0x2176b8 <_Z24setGainForSoundImmediateif+0x30>
 *   @0x2176f0 ldr r2, [r3, #0x8]
 *   @0x2176f4 cmp r2, #0
 *   @0x2176f8 bne 0x2176b8 <_Z24setGainForSoundImmediateif+0x30>
 *   @0x2176fc ldr r0, [r3, #0x10]
 *   @0x217700 cmp r0, #0
 *   @0x217704 blt 0x2176b8 <_Z24setGainForSoundImmediateif+0x30>
 *   @0x217708 vldr s15, [r3, #36]
 *   @0x21770c vmul.f32 s15, s16, s15
 *   @0x217710 ldr r2, [r3, #0x38]
 *   @0x217714 movw r1, #0x100a
 *   @0x217718 ldr r3, [pc, #0x34]
 *   @0x21771c add r4, r4, #1
 *   @0x217720 cmp r2, #0
 *   @0x217724 vldrne s14, [r2, #40]
 *   @0x217728 ldr r3, [pc, r3]
 *   @0x21772c ldr r3, [r3]
 *   @0x217730 ldr r0, [r3, r0, lsl #2]
 *   @0x217734 vmulne.f32 s15, s15, s14
 *   @0x217738 vmov r2, s15
 *   @0x21773c bl 0xb6a78 <alSourcef@plt>
 *   @0x217740 cmp r4, r6
 *   @0x217744 bne 0x2176c4 <_Z24setGainForSoundImmediateif+0x3c>
 *   @0x217748 vpop {d8}
 *   @0x21774c pop {r3, r4, r5, r6, r7, pc}
 *   @0x217750 ldrsheq sp, [r3], #-188
 *   @0x217754 andseq r9, sp, r4, lsr #25
 *
 * ══ §86/146 Audio_ResumeSound(int)  0x217e9c  size 208  52 条（0x217e9c..0x217f6c）
 * @func 0x217e9c 0x217f7c  size 224  56 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_ResumeSound(int)+0xac / Audio_ResumeSoundNoise(CNoise*) / Audio_GetNoiseFromID(int)
 * 字段偏移 top8: 0x38×2 / 0xb0×1 / 0x98×1 / 0x88×1 / 0x78×1 / 0x68×1 / 0x64×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x217e9c ldr r3, [pc, #0xb0]
 *   @0x217ea0 push {r4, r5, r6, r7, r8, lr}
 *   @0x217ea4 ldr r3, [pc, r3]
 *   @0x217ea8 mov r5, r0
 *   @0x217eac ldrb r4, [r3]
 *   @0x217eb0 cmp r4, #0
 *   @0x217eb4 popne {r4, r5, r6, r7, r8, pc}
 *   @0x217eb8 ldr r3, [pc, #0x98]
 *   @0x217ebc ldr r3, [pc, r3]
 *   @0x217ec0 ldrb r3, [r3]
 *   @0x217ec4 cmp r3, #0
 *   @0x217ec8 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x217ecc ldr r3, [pc, #0x88]
 *   @0x217ed0 ldr r3, [pc, r3]
 *   @0x217ed4 ldr r3, [r3]
 *   @0x217ed8 cmp r3, r0
 *   @0x217edc ble 0x217f48 <_Z17Audio_ResumeSoundi+0xac>
 *   @0x217ee0 ldr r3, [pc, #0x78]
 *   @0x217ee4 add r3, pc, r3
 *   @0x217ee8 ldr r6, [r3, #0x38]
 *   @0x217eec cmp r6, #0
 *   @0x217ef0 pople {r4, r5, r6, r7, r8, pc}
 *   @0x217ef4 ldr r8, [pc, #0x68]
 *   @0x217ef8 mov r3, r6
 *   @0x217efc ldr r7, [pc, #0x64]
 *   @0x217f00 add r8, pc, r8
 *   @0x217f04 add r7, pc, r7
 *   @0x217f08 b 0x217f1c <_Z17Audio_ResumeSoundi+0x80>
 *   @0x217f0c add r4, r4, #1
 *   @0x217f10 cmp r4, r6
 *   @0x217f14 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x217f18 ldr r3, [r7, #0x38]
 *   @0x217f1c cmp r4, r3
 *   @0x217f20 bge 0x217f0c <_Z17Audio_ResumeSoundi+0x70>
 *   @0x217f24 ldr r3, [r8, #0x3c]
 *   @0x217f28 ldr r0, [r3, r4, lsl #2]
 *   @0x217f2c cmp r0, #0
 *   @0x217f30 beq 0x217f0c <_Z17Audio_ResumeSoundi+0x70>
 *   @0x217f34 ldr r2, [r0, #0x18]
 *   @0x217f38 cmp r2, r5
 *   @0x217f3c bne 0x217f0c <_Z17Audio_ResumeSoundi+0x70>
 *   @0x217f40 bl 0x217cf0 <_Z22Audio_ResumeSoundNoiseP6CNoise>
 *   @0x217f44 b 0x217f0c <_Z17Audio_ResumeSoundi+0x70>
 *   @0x217f48 bl 0x216fbc <_Z20Audio_GetNoiseFromIDi>
 *   @0x217f4c pop {r4, r5, r6, r7, r8, lr}
 *   @0x217f50 b 0x217cf0 <_Z22Audio_ResumeSoundNoiseP6CNoise>
 *   @0x217f54 andseq r7, sp, r8, lsr #3
 *   @0x217f58 andseq r6, sp, r4, ror lr
 *   @0x217f5c andseq r9, sp, r4, lsl r5
 *   @0x217f60 ldrheq sp, [r3], #-48
 *   @0x217f64 .word 0x0053d394
 *   @0x217f68 .word 0x0053d390
 *
 * ══ §87/146 Audio_PauseSound(int)  0x217f6c  size 208  52 条（0x217f6c..0x21803c）
 * @func 0x217f6c 0x21803c  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_PauseSound(int)+0xac / Audio_PauseSoundNoise(CNoise*) / Audio_GetNoiseFromID(int)
 * 字段偏移 top8: 0x38×2 / 0xb0×1 / 0x98×1 / 0x88×1 / 0x78×1 / 0x68×1 / 0x64×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x217f6c ldr r3, [pc, #0xb0]
 *   @0x217f70 push {r4, r5, r6, r7, r8, lr}
 *   @0x217f74 ldr r3, [pc, r3]
 *   @0x217f78 mov r5, r0
 *   @0x217f7c ldrb r4, [r3]
 *   @0x217f80 cmp r4, #0
 *   @0x217f84 popne {r4, r5, r6, r7, r8, pc}
 *   @0x217f88 ldr r3, [pc, #0x98]
 *   @0x217f8c ldr r3, [pc, r3]
 *   @0x217f90 ldrb r3, [r3]
 *   @0x217f94 cmp r3, #0
 *   @0x217f98 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x217f9c ldr r3, [pc, #0x88]
 *   @0x217fa0 ldr r3, [pc, r3]
 *   @0x217fa4 ldr r3, [r3]
 *   @0x217fa8 cmp r3, r0
 *   @0x217fac ble 0x218018 <_Z16Audio_PauseSoundi+0xac>
 *   @0x217fb0 ldr r3, [pc, #0x78]
 *   @0x217fb4 add r3, pc, r3
 *   @0x217fb8 ldr r6, [r3, #0x38]
 *   @0x217fbc cmp r6, #0
 *   @0x217fc0 pople {r4, r5, r6, r7, r8, pc}
 *   @0x217fc4 ldr r8, [pc, #0x68]
 *   @0x217fc8 mov r3, r6
 *   @0x217fcc ldr r7, [pc, #0x64]
 *   @0x217fd0 add r8, pc, r8
 *   @0x217fd4 add r7, pc, r7
 *   @0x217fd8 b 0x217fec <_Z16Audio_PauseSoundi+0x80>
 *   @0x217fdc add r4, r4, #1
 *   @0x217fe0 cmp r4, r6
 *   @0x217fe4 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x217fe8 ldr r3, [r7, #0x38]
 *   @0x217fec cmp r4, r3
 *   @0x217ff0 bge 0x217fdc <_Z16Audio_PauseSoundi+0x70>
 *   @0x217ff4 ldr r3, [r8, #0x3c]
 *   @0x217ff8 ldr r0, [r3, r4, lsl #2]
 *   @0x217ffc cmp r0, #0
 *   @0x218000 beq 0x217fdc <_Z16Audio_PauseSoundi+0x70>
 *   @0x218004 ldr r2, [r0, #0x18]
 *   @0x218008 cmp r2, r5
 *   @0x21800c bne 0x217fdc <_Z16Audio_PauseSoundi+0x70>
 *   @0x218010 bl 0x217b44 <_Z21Audio_PauseSoundNoiseP6CNoise>
 *   @0x218014 b 0x217fdc <_Z16Audio_PauseSoundi+0x70>
 *   @0x218018 bl 0x216fbc <_Z20Audio_GetNoiseFromIDi>
 *   @0x21801c pop {r4, r5, r6, r7, r8, lr}
 *   @0x218020 b 0x217b44 <_Z21Audio_PauseSoundNoiseP6CNoise>
 *   @0x218024 ldrsbeq r7, [sp], -r8
 *   @0x218028 andseq r6, sp, r4, lsr #27
 *   @0x21802c andseq r9, sp, r4, asr #8
 *   @0x218030 subseq sp, r3, r0, ror #5
 *   @0x218034 subseq sp, r3, r4, asr #5
 *   @0x218038 subseq sp, r3, r0, asr #5
 *
 * ══ §88/146 AudioGroup_Load(unsigned char*, unsigned int, unsigned char*)  0x218c94  size 208  52 条（0x218c94..0x218d64）
 * @func 0x218c94 0x218d64  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x218ca0→0x3eb6b8, 0x218cd8→0x755324, 0x218cf8→0x544c44, 0x218d08→0x544c44
 * 调用序列: CAudioGroupMan::CreateGroups(int) / CAudioGroupMan::GetGroup(int) / CAudioGroup::SetName(char const*)
 * 字段偏移 top8: 0xac×2 / 0xa8×1 / 0xc×1 / 0x7c×1 / 0x4×1 / 0x60×1 / 0x50×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x218c94 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x218c98 mov r6, r0
 *   @0x218c9c ldr r9, [pc, #0xac]
 *   @0x218ca0 ldr r3, [pc, #0xac]
 *   @0x218ca4 add r9, pc, r9
 *   @0x218ca8 ldr r1, [pc, #0xa8]
 *   @0x218cac ldr r3, [r9, r3]
 *   @0x218cb0 add r1, pc, r1
 *   @0x218cb4 ldr r0, [r3]
 *   @0x218cb8 ldr r2, [r0]
 *   @0x218cbc ldr r3, [r2, #0xc]
 *   @0x218cc0 blx r3
 *   @0x218cc4 ldr r7, [r6]
 *   @0x218cc8 cmp r7, #0
 *   @0x218ccc bne 0x218cd8 <_Z15AudioGroup_LoadPhjS_+0x44>
 *   @0x218cd0 mov r0, #1
 *   @0x218cd4 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x218cd8 ldr r3, [pc, #0x7c]
 *   @0x218cdc mov r1, r7
 *   @0x218ce0 mov r4, #0
 *   @0x218ce4 ldr r8, [r9, r3]
 *   @0x218ce8 mov r0, r8
 *   @0x218cec bl 0x21de4c <_ZN14CAudioGroupMan12CreateGroupsEi>
 *   @0x218cf0 ldr r3, [r6, #0x4]!
 *   @0x218cf4 mov r0, r8
 *   @0x218cf8 ldr r1, [pc, #0x60]
 *   @0x218cfc cmp r3, #0
 *   @0x218d00 mov r2, r3
 *   @0x218d04 ldrne r2, [r9, r1]
 *   @0x218d08 ldr r1, [pc, #0x50]
 *   @0x218d0c ldrne r2, [r2]
 *   @0x218d10 addne r2, r2, r3
 *   @0x218d14 ldr r3, [r2]
 *   @0x218d18 cmp r3, #0
 *   @0x218d1c mov r5, r3
 *   @0x218d20 ldrne r2, [r9, r1]
 *   @0x218d24 mov r1, r4
 *   @0x218d28 add r4, r4, #1
 *   @0x218d2c ldrne r5, [r2]
 *   @0x218d30 addne r5, r5, r3
 *   @0x218d34 bl 0x21df0c <_ZN14CAudioGroupMan8GetGroupEi>
 *   @0x218d38 mov r1, r5
 *   @0x218d3c bl 0x21dbf4 <_ZN11CAudioGroup7SetNameEPKc>
 *   @0x218d40 cmp r4, r7
 *   @0x218d44 bne 0x218cf0 <_Z15AudioGroup_LoadPhjS_+0x5c>
 *   @0x218d48 mov r0, #1
 *   @0x218d4c pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x218d50 andseq r8, sp, r12, lsr #31
 *   @0x218d54 .word 0xffffdecc
 *   @0x218d58 andseq r11, r3, r0, lsl #1
 *   @0x218d5c .word 0xffffd400
 *   @0x218d60 .word 0xffffbcf4
 *
 * ══ §89/146 Audio_StopAllGroup(int)  0x21ad0c  size 208  52 条（0x21ad0c..0x21addc）
 * @func 0x21ad0c 0x21addc  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_StopAllGroup(int)+0x5c / Audio_GetSound(int) / Audio_StopSoundNoise(CNoise*, bool)
 * 字段偏移 top8: 0x38×2 / 0xac×1 / 0x9c×1 / 0x8c×1 / 0x7c×1 / 0x78×1 / 0x3c×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21ad0c push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x21ad10 mov r7, r0
 *   @0x21ad14 ldr r3, [pc, #0xac]
 *   @0x21ad18 ldr r3, [pc, r3]
 *   @0x21ad1c ldrb r4, [r3]
 *   @0x21ad20 cmp r4, #0
 *   @0x21ad24 popne {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x21ad28 ldr r3, [pc, #0x9c]
 *   @0x21ad2c ldr r3, [pc, r3]
 *   @0x21ad30 ldrb r3, [r3]
 *   @0x21ad34 cmp r3, #0
 *   @0x21ad38 popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x21ad3c ldr r3, [pc, #0x8c]
 *   @0x21ad40 add r3, pc, r3
 *   @0x21ad44 ldr r6, [r3, #0x38]
 *   @0x21ad48 cmp r6, #0
 *   @0x21ad4c pople {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x21ad50 ldr r9, [pc, #0x7c]
 *   @0x21ad54 mov r3, r6
 *   @0x21ad58 ldr r8, [pc, #0x78]
 *   @0x21ad5c add r9, pc, r9
 *   @0x21ad60 add r8, pc, r8
 *   @0x21ad64 b 0x21ad78 <_Z18Audio_StopAllGroupi+0x6c>
 *   @0x21ad68 add r4, r4, #1
 *   @0x21ad6c cmp r4, r6
 *   @0x21ad70 popeq {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x21ad74 ldr r3, [r8, #0x38]
 *   @0x21ad78 cmp r3, r4
 *   @0x21ad7c ble 0x21ad68 <_Z18Audio_StopAllGroupi+0x5c>
 *   @0x21ad80 ldr r3, [r9, #0x3c]
 *   @0x21ad84 ldr r5, [r3, r4, lsl #2]
 *   @0x21ad88 cmp r5, #0
 *   @0x21ad8c beq 0x21ad68 <_Z18Audio_StopAllGroupi+0x5c>
 *   @0x21ad90 ldrb r3, [r5, #0x5]
 *   @0x21ad94 cmp r3, #0
 *   @0x21ad98 beq 0x21ad68 <_Z18Audio_StopAllGroupi+0x5c>
 *   @0x21ad9c ldr r0, [r5, #0x18]
 *   @0x21ada0 bl 0x21632c <_Z14Audio_GetSoundi>
 *   @0x21ada4 cmp r0, #0
 *   @0x21ada8 beq 0x21ad68 <_Z18Audio_StopAllGroupi+0x5c>
 *   @0x21adac ldr r3, [r0, #0x4c]
 *   @0x21adb0 cmp r3, r7
 *   @0x21adb4 bne 0x21ad68 <_Z18Audio_StopAllGroupi+0x5c>
 *   @0x21adb8 mov r0, r5
 *   @0x21adbc mov r1, #0
 *   @0x21adc0 bl 0x21a0b0 <_Z20Audio_StopSoundNoiseP6CNoiseb>
 *   @0x21adc4 b 0x21ad68 <_Z18Audio_StopAllGroupi+0x5c>
 *   @0x21adc8 andseq r4, sp, r4, lsr r3
 *   @0x21adcc andseq r4, sp, r4
 *   @0x21add0 subseq r10, r3, r4, asr r5
 *   @0x21add4 subseq r10, r3, r8, lsr r5
 *   @0x21add8 subseq r10, r3, r4, lsr r5
 *
 * ══ §90/146 SND_IsPlaying(char const*, int)  0x21edc0  size 208  45 条（0x21edc0..0x21ee90）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x21edc0 0x21ee90  size 208  45 条
 * 部分覆盖: 本节 45/52 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x21edd0→0x755363, 0x21ede8→0x755330, 0x21ee1c→0x755334, 0x21ee38→0x755338
 * 调用序列: 0xb6574 / SND_IsPlaying(char const*, int)+0x70 / SND_IsPlaying(char const*, int)+0x78
 * 字段偏移 top8: 0xa4×1 / 0xa0×1 / 0x8c×1 / 0x5c×1 / 0x44×1 / 0x40×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21edc0 push {r3, r4, r5, lr}
 *   @0x21edc4 mov r2, r0
 *   @0x21ede4 bne 0x21ee30 <_Z13SND_IsPlayingPKci+0x70>
 *   @0x21ede8 ldr r3, [pc, #0x8c]
 *   @0x21edec ldr r3, [r4, r3]
 *   @0x21edf0 ldr r0, [r3]
 *   @0x21edf4 cmp r0, #0
 *   @0x21edf8 beq 0x21ee14 <_Z13SND_IsPlayingPKci+0x54>
 *   @0x21edfc cmp r2, #0
 *   @0x21ee00 beq 0x21ee14 <_Z13SND_IsPlayingPKci+0x54>
 *   @0x21ee04 mov r1, r2
 *   @0x21ee08 bl 0xb6574 <strcmp@plt>
 *   @0x21ee0c cmp r0, #0
 *   @0x21ee10 beq 0x21ee64 <_Z13SND_IsPlayingPKci+0xa4>
 *   @0x21ee14 cmp r5, #0
 *   @0x21ee18 blt 0x21ee30 <_Z13SND_IsPlayingPKci+0x70>
 *   @0x21ee1c ldr r3, [pc, #0x5c]
 *   @0x21ee20 ldr r3, [r4, r3]
 *   @0x21ee24 ldr r3, [r3]
 *   @0x21ee28 cmp r5, r3
 *   @0x21ee2c blt 0x21ee38 <_Z13SND_IsPlayingPKci+0x78>
 *   @0x21ee30 mov r0, #0
 *   @0x21ee34 pop {r3, r4, r5, pc}
 *   @0x21ee38 ldr r3, [pc, #0x44]
 *   @0x21ee3c add r5, r5, r5, lsl #2
 *   @0x21ee40 ldr r2, [pc, #0x40]
 *   @0x21ee44 ldr r3, [r4, r3]
 *   @0x21ee48 add r2, pc, r2
 *   @0x21ee4c ldr r0, [r2]
 *   @0x21ee50 ldr r3, [r3, #0x4]
 *   @0x21ee54 add r5, r3, r5, lsl #2
 *   @0x21ee58 ldr r1, [r5, #0x8]
 *   @0x21ee5c pop {r3, r4, r5, lr}
 *   @0x21ee60 b 0x220ee0 <_ZN13SoundHardware7PlayingEPv>
 *   @0x21ee64 ldr r3, [pc, #0x20]
 *   @0x21ee68 ldr r0, [pc, r3]
 *   @0x21ee6c pop {r3, r4, r5, lr}
 *   @0x21ee70 b 0x221078 <_ZN13SoundHardware10PlayingMP3Ev>
 *   @0x21ee74 andseq r2, sp, r12, ror lr
 *   @0x21ee78 .word 0xffffd3fc
 *   @0x21ee7c .word 0xfffff7cc
 *   @0x21ee80 .word 0xfffff7c4
 *   @0x21ee84 .word 0xfffff7c8
 *   @0x21ee88 ldrsbeq r6, [r3], #-76
 *   @0x21ee8c ldrheq r6, [r3], #-76
 *
 * ══ §91/146 alutExit  0x221b78  size 208  52 条（0x221b78..0x221c48）
 * @func 0x221b78 0x221c48  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _alutSetError×4 / _alutSanityCheck / 0xb6bc8 / 0xb6b98 / 0xb6bd4 / 0xb6ba4 / 0xb6be0
 * 字段偏移 top8: 0x4×2 / 0xc0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x221b78 push {r4, r5, r6, lr}
 *   @0x221b7c ldr r5, [pc, #0xc0]
 *   @0x221b80 add r5, pc, r5
 *   @0x221b84 ldr r4, [r5]
 *   @0x221b88 cmp r4, #0
 *   @0x221b8c beq 0x221c04 <alutExit+0x8c>
 *   @0x221b90 cmp r4, #2
 *   @0x221b94 beq 0x221bf4 <alutExit+0x7c>
 *   @0x221b98 bl 0x2219a8 <_alutSanityCheck>
 *   @0x221b9c cmp r0, #0
 *   @0x221ba0 popeq {r4, r5, r6, pc}
 *   @0x221ba4 mov r0, #0
 *   @0x221ba8 bl 0xb6bc8 <alcMakeContextCurrent@plt>
 *   @0x221bac subs r4, r0, #0
 *   @0x221bb0 beq 0x221c14 <alutExit+0x9c>
 *   @0x221bb4 ldr r0, [r5, #0x4]
 *   @0x221bb8 bl 0xb6b98 <alcGetContextsDevice@plt>
 *   @0x221bbc mov r4, r0
 *   @0x221bc0 ldr r0, [r5, #0x4]
 *   @0x221bc4 bl 0xb6bd4 <alcDestroyContext@plt>
 *   @0x221bc8 mov r0, r4
 *   @0x221bcc bl 0xb6ba4 <alcGetError@plt>
 *   @0x221bd0 subs r6, r0, #0
 *   @0x221bd4 bne 0x221c24 <alutExit+0xac>
 *   @0x221bd8 mov r0, r4
 *   @0x221bdc bl 0xb6be0 <alcCloseDevice@plt>
 *   @0x221be0 subs r4, r0, #0
 *   @0x221be4 beq 0x221c34 <alutExit+0xbc>
 *   @0x221be8 str r6, [r5]
 *   @0x221bec mov r0, #1
 *   @0x221bf0 pop {r4, r5, r6, pc}
 *   @0x221bf4 mov r3, #0
 *   @0x221bf8 mov r0, #1
 *   @0x221bfc str r3, [r5]
 *   @0x221c00 pop {r4, r5, r6, pc}
 *   @0x221c04 movw r0, #0x203
 *   @0x221c08 bl 0x221940 <_alutSetError>
 *   @0x221c0c mov r0, r4
 *   @0x221c10 pop {r4, r5, r6, pc}
 *   @0x221c14 movw r0, #0x20a
 *   @0x221c18 bl 0x221940 <_alutSetError>
 *   @0x221c1c mov r0, r4
 *   @0x221c20 pop {r4, r5, r6, pc}
 *   @0x221c24 movw r0, #0x20b
 *   @0x221c28 bl 0x221940 <_alutSetError>
 *   @0x221c2c mov r0, #0
 *   @0x221c30 pop {r4, r5, r6, pc}
 *   @0x221c34 mov r0, #520
 *   @0x221c38 bl 0x221940 <_alutSetError>
 *   @0x221c3c mov r0, r4
 *   @0x221c40 pop {r4, r5, r6, pc}
 *   @0x221c44 subseq r3, r3, r8, ror #17
 *
 * ══ §92/146 oggpackB_look  0x233958  size 208  52 条（0x233958..0x233a28）
 * @func 0x233958 0x233a28  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: oggpackB_look+0x60×3 / oggpackB_look+0x48
 * 字段偏移 top8: 0x10×1 / 0x4×1 / 0xc×1 / 0x1×1 / 0x2×1 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x233958 rsb r12, r1, #32
 *   @0x23395c cmp r12, #32
 *   @0x233960 push {r4, r5, r6}
 *   @0x233964 bhi 0x233a20 <oggpackB_look+0xc8>
 *   @0x233968 ldr r5, [r0, #0x10]
 *   @0x23396c ldr r4, [r0]
 *   @0x233970 sub r3, r5, #4
 *   @0x233974 ldr r2, [r0, #0x4]
 *   @0x233978 cmp r4, r3
 *   @0x23397c add r3, r2, r1
 *   @0x233980 blt 0x2339a0 <oggpackB_look+0x48>
 *   @0x233984 add r6, r3, #7
 *   @0x233988 sub r5, r5, r6, asr #3
 *   @0x23398c cmp r4, r5
 *   @0x233990 bgt 0x233a20 <oggpackB_look+0xc8>
 *   @0x233994 cmp r3, #0
 *   @0x233998 moveq r0, r3
 *   @0x23399c beq 0x2339cc <oggpackB_look+0x74>
 *   @0x2339a0 ldr r4, [r0, #0xc]
 *   @0x2339a4 cmp r3, #8
 *   @0x2339a8 add r0, r2, #24
 *   @0x2339ac ldrb r5, [r4]
 *   @0x2339b0 lsl r0, r5, r0
 *   @0x2339b4 bgt 0x2339d4 <oggpackB_look+0x7c>
 *   @0x2339b8 asr r12, r12, #1
 *   @0x2339bc rsb r1, r1, #33
 *   @0x2339c0 lsr r0, r0, r12
 *   @0x2339c4 asr r1, r1, #1
 *   @0x2339c8 lsr r0, r0, r1
 *   @0x2339cc pop {r4, r5, r6}
 *   @0x2339d0 bx lr
 *   @0x2339d4 ldrb r6, [r4, #0x1]
 *   @0x2339d8 cmp r3, #16
 *   @0x2339dc add r5, r2, #16
 *   @0x2339e0 orr r0, r0, r6, lsl r5
 *   @0x2339e4 ble 0x2339b8 <oggpackB_look+0x60>
 *   @0x2339e8 ldrb r6, [r4, #0x2]
 *   @0x2339ec cmp r3, #24
 *   @0x2339f0 add r5, r2, #8
 *   @0x2339f4 orr r0, r0, r6, lsl r5
 *   @0x2339f8 ble 0x2339b8 <oggpackB_look+0x60>
 *   @0x2339fc ldrb r5, [r4, #0x3]
 *   @0x233a00 cmp r3, #32
 *   @0x233a04 orr r0, r0, r5, lsl r2
 *   @0x233a08 ble 0x2339b8 <oggpackB_look+0x60>
 *   @0x233a0c cmp r2, #0
 *   @0x233a10 rsbne r2, r2, #8
 *   @0x233a14 ldrbne r3, [r4, #0x4]
 *   @0x233a18 orrne r0, r0, r3, asr r2
 *   @0x233a1c b 0x2339b8 <oggpackB_look+0x60>
 *   @0x233a20 mvn r0, #0
 *   @0x233a24 b 0x2339cc <oggpackB_look+0x74>
 *
 * ══ §93/146 CPhysicsObject::ApplyLocalImpulse(float, float, float, float)  0x237190  size 208  52 条（0x237190..0x237260）
 * @func 0x237190 0x237260  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0xa0×1
 * VFP 指令 38 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x237190 ldr r0, [r0]
 *   @0x237194 vmov s13, r1
 *   @0x237198 vpush {d8}
 *   @0x23719c vldr s15, [r0, #24]
 *   @0x2371a0 vldr s14, [r0, #20]
 *   @0x2371a4 vldr s9, [r0, #12]
 *   @0x2371a8 ldr r1, [r0]
 *   @0x2371ac vldr s8, [r0, #16]
 *   @0x2371b0 vmov s12, r2
 *   @0x2371b4 cmp r1, #2
 *   @0x2371b8 vmov s11, r3
 *   @0x2371bc beq 0x2371c8 <_ZN14CPhysicsObject17ApplyLocalImpulseEffff+0x38>
 *   @0x2371c0 vpop {d8}
 *   @0x2371c4 bx lr
 *   @0x2371c8 ldrh r3, [r0, #4]
 *   @0x2371cc tst r3, #2
 *   @0x2371d0 beq 0x23724c <_ZN14CPhysicsObject17ApplyLocalImpulseEffff+0xbc>
 *   @0x2371d4 vmul.f32 s4, s12, s15
 *   @0x2371d8 vldr s16, [sp, #8]
 *   @0x2371dc vldr s0, [r0, #64]
 *   @0x2371e0 vldr s1, [r0, #60]
 *   @0x2371e4 vldr s6, [r0, #88]
 *   @0x2371e8 vldr s3, [r0, #136]
 *   @0x2371ec vldr s5, [r0, #80]
 *   @0x2371f0 vldr s7, [r0, #84]
 *   @0x2371f4 vldr s2, [r0, #144]
 *   @0x2371f8 vmla.f32 s4, s13, s14
 *   @0x2371fc vmul.f32 s12, s12, s14
 *   @0x237200 vmul.f32 s10, s16, s14
 *   @0x237204 vnmls.f32 s12, s13, s15
 *   @0x237208 vnmls.f32 s10, s11, s15
 *   @0x23720c vmul.f32 s15, s16, s15
 *   @0x237210 vpop {d8}
 *   @0x237214 vadd.f32 s8, s4, s8
 *   @0x237218 vsub.f32 s8, s8, s0
 *   @0x23721c vmla.f32 s15, s11, s14
 *   @0x237220 vadd.f32 s12, s12, s9
 *   @0x237224 vmul.f32 s8, s10, s8
 *   @0x237228 vsub.f32 s12, s12, s1
 *   @0x23722c vnmls.f32 s8, s15, s12
 *   @0x237230 vmla.f32 s5, s10, s3
 *   @0x237234 vmla.f32 s6, s8, s2
 *   @0x237238 vstr s5, [r0, #80]
 *   @0x23723c vmla.f32 s7, s15, s3
 *   @0x237240 vstr s6, [r0, #88]
 *   @0x237244 vstr s7, [r0, #84]
 *   @0x237248 bx lr
 *   @0x23724c orr r3, r3, #2
 *   @0x237250 mov r2, #0
 *   @0x237254 strh r3, [r0, #4]
 *   @0x237258 str r2, [r0, #0xa0]
 *   @0x23725c b 0x2371d4 <_ZN14CPhysicsObject17ApplyLocalImpulseEffff+0x44>
 *
 * ══ §94/146 MemoryManager::IsAllocated(void const*)  0x27c454  size 208  52 条（0x27c454..0x27c524）
 * @func 0x27c454 0x27c524  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Mutex::Lock() / MemoryManager::IsAllocated(void const*)+0x7c / Mutex::Unlock() / anon_27b918
 * 字段偏移 top8: 0x-4×2 / 0xb8×1 / 0x-c×1 / 0x-8×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27c454 push {r3, r4, r5, lr}
 *   @0x27c458 subs r5, r0, #0
 *   @0x27c45c beq 0x27c4a4 <_ZN13MemoryManager11IsAllocatedEPKv+0x50>
 *   @0x27c460 ldr r4, [pc, #0xb8]
 *   @0x27c464 ldr r4, [pc, r4]
 *   @0x27c468 ldr r0, [r4]
 *   @0x27c46c cmp r0, #0
 *   @0x27c470 beq 0x27c514 <_ZN13MemoryManager11IsAllocatedEPKv+0xc0>
 *   @0x27c474 bl 0x27e084 <_ZN5Mutex4LockEv>
 *   @0x27c478 ldr r2, [r5, #-0xc]
 *   @0x27c47c movw r3, #0xc0de
 *   @0x27c480 movt r3, #0xdead
 *   @0x27c484 cmp r2, r3
 *   @0x27c488 beq 0x27c4ac <_ZN13MemoryManager11IsAllocatedEPKv+0x58>
 *   @0x27c48c ldr r3, [r5, #-0x4]
 *   @0x27c490 cmp r3, #0
 *   @0x27c494 blt 0x27c4d0 <_ZN13MemoryManager11IsAllocatedEPKv+0x7c>
 *   @0x27c498 mov r5, #0
 *   @0x27c49c ldr r0, [r4]
 *   @0x27c4a0 bl 0x27e09c <_ZN5Mutex6UnlockEv>
 *   @0x27c4a4 mov r0, r5
 *   @0x27c4a8 pop {r3, r4, r5, pc}
 *   @0x27c4ac ldr r2, [r5, #-0x8]
 *   @0x27c4b0 movw r3, #0xb00b
 *   @0x27c4b4 movt r3, #0xbaad
 *   @0x27c4b8 cmp r2, r3
 *   @0x27c4bc moveq r5, #1
 *   @0x27c4c0 beq 0x27c49c <_ZN13MemoryManager11IsAllocatedEPKv+0x48>
 *   @0x27c4c4 ldr r3, [r5, #-0x4]
 *   @0x27c4c8 cmp r3, #0
 *   @0x27c4cc bge 0x27c498 <_ZN13MemoryManager11IsAllocatedEPKv+0x44>
 *   @0x27c4d0 bic r3, r3, #-2147483648
 *   @0x27c4d4 cmp r3, #8192
 *   @0x27c4d8 bhs 0x27c498 <_ZN13MemoryManager11IsAllocatedEPKv+0x44>
 *   @0x27c4dc sub r5, r5, #16
 *   @0x27c4e0 movw r2, #0xc0de
 *   @0x27c4e4 rsb r3, r3, r5
 *   @0x27c4e8 movt r2, #0xdead
 *   @0x27c4ec ldr r1, [r3, #0x4]
 *   @0x27c4f0 cmp r1, r2
 *   @0x27c4f4 bne 0x27c498 <_ZN13MemoryManager11IsAllocatedEPKv+0x44>
 *   @0x27c4f8 ldr r5, [r3, #0x8]
 *   @0x27c4fc movw r3, #0xb00b
 *   @0x27c500 movt r3, #0xbaad
 *   @0x27c504 subs r3, r5, r3
 *   @0x27c508 rsbs r5, r3, #0
 *   @0x27c50c adcs r5, r5, r3
 *   @0x27c510 b 0x27c49c <_ZN13MemoryManager11IsAllocatedEPKv+0x48>
 *   @0x27c514 bl 0x27b918 <_ZN7CBucketILj8ELj131072ELb1EE4FreeEPKv+0x38>
 *   @0x27c518 ldr r0, [r4]
 *   @0x27c51c b 0x27c474 <_ZN13MemoryManager11IsAllocatedEPKv+0x20>
 *   @0x27c520 ldrheq r5, [r7], -r8
 *
 * ══ §95/146 spAnimationState_addAnimation  0x28399c  size 208  52 条（0x28399c..0x283a6c）
 * @func 0x28399c 0x283a6c  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _spAnimationState_expandToIndex / spAnimationState_addAnimation+0x80 / spAnimationStateData_getMix
 * 字段偏移 top8: 0x4×3 / 0x10×2 / 0xc×2 / 0x1c×1 / 0x20×1 / 0x2×1
 * VFP 指令 13 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28399c push {r4, r5, r6, r7, r8, lr}
 *   @0x2839a0 vpush {d8}
 *   @0x2839a4 mov r7, r1
 *   @0x2839a8 vldr s16, [sp, #32]
 *   @0x2839ac ldr r1, [r0, #0x1c]
 *   @0x2839b0 mov r6, r2
 *   @0x2839b4 mov r8, r3
 *   @0x2839b8 mov r5, r0
 *   @0x2839bc blx r1
 *   @0x2839c0 ldr r3, [r6, #0x4]
 *   @0x2839c4 mov r1, r7
 *   @0x2839c8 str r8, [r0, #0x10]
 *   @0x2839cc mov r4, r0
 *   @0x2839d0 str r6, [r0, #0xc]
 *   @0x2839d4 str r3, [r0, #0x20]
 *   @0x2839d8 mov r0, r5
 *   @0x2839dc bl 0x28362c <_spAnimationState_expandToIndex>
 *   @0x2839e0 subs r12, r0, #0
 *   @0x2839e4 bne 0x2839f0 <spAnimationState_addAnimation+0x54>
 *   @0x2839e8 b 0x283a54 <spAnimationState_addAnimation+0xb8>
 *   @0x2839ec mov r12, r3
 *   @0x2839f0 ldr r3, [r12, #0x4]
 *   @0x2839f4 cmp r3, #0
 *   @0x2839f8 bne 0x2839ec <spAnimationState_addAnimation+0x50>
 *   @0x2839fc str r4, [r12, #0x4]
 *   @0x283a00 vcmpe.f32 s16, #0
 *   @0x283a04 vmrs APSR_nzcv, fpscr
 *   @0x283a08 bls 0x283a1c <spAnimationState_addAnimation+0x80>
 *   @0x283a0c vstr s16, [r4, #20]
 *   @0x283a10 vpop {d8}
 *   @0x283a14 mov r0, r4
 *   @0x283a18 pop {r4, r5, r6, r7, r8, pc}
 *   @0x283a1c cmp r12, #0
 *   @0x283a20 beq 0x283a60 <spAnimationState_addAnimation+0xc4>
 *   @0x283a24 ldr r0, [r5]
 *   @0x283a28 mov r2, r6
 *   @0x283a2c ldr r1, [r12, #0xc]
 *   @0x283a30 vldr s17, [r12, #32]
 *   @0x283a34 bl 0x283ca8 <spAnimationStateData_getMix>
 *   @0x283a38 vmov s15, r0
 *   @0x283a3c mov r0, r4
 *   @0x283a40 vsub.f32 s17, s17, s15
 *   @0x283a44 vadd.f32 s16, s16, s17
 *   @0x283a48 vstr s16, [r4, #20]
 *   @0x283a4c vpop {d8}
 *   @0x283a50 pop {r4, r5, r6, r7, r8, pc}
 *   @0x283a54 ldr r3, [r5, #0x10]
 *   @0x283a58 str r4, [r3, r7, lsl #2]
 *   @0x283a5c b 0x283a00 <spAnimationState_addAnimation+0x64>
 *   @0x283a60 vldr s16, [pc]
 *   @0x283a64 b 0x283a0c <spAnimationState_addAnimation+0x70>
 *   @0x283a68 andeq r0, r0, r0
 *
 * ══ §96/146 zip_stat_index  0x2a5694  size 208  52 条（0x2a5694..0x2a5764）
 * @func 0x2a5694 0x2a5764  size 208  52 条
 * 部分覆盖: 本节 52/97 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×4 / 0x1a×2 / 0x2c×1 / 0x34×1 / 0x4×1 / 0xc×1 / 0x10×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a5694 push.w {r4, r5, r6, r7, r8, lr}
 *   @0x2a5698 subs r6, r1, #0x0
 *   @0x2a569c mov r8, r2
 *   @0x2a56a0 bge 0x2a56ac <zip_stat_index+0x18>
 *   @0x2a56a4 tsths r2, r12
 *   @0x2a56a8 movs r2, #0x0
 *   @0x2a56ac ldr r3, [r0, #0x2c]
 *   @0x2a56b0 bge 0x2a56a2 <zip_stat_index+0xe>
 *   @0x2a56b4 .word 0x4607f95d
 *   @0x2a56b8 cmp r0, #0x0
 *   @0x2a56bc ands r8, r8, #0x8
 *   @0x2a56c0 bne 0x2a56f4 <zip_stat_index+0x60>
 *   @0x2a56c4 ldr r1, [r5, #0x34]
 *   @0x2a56c8 adds r2, r1, r3
 *   @0x2a56cc subs r3, #0x2
 *   @0x2a56d0 bhi 0x2a56f4 <zip_stat_index+0x60>
 *   @0x2a56d4 mov r1, r4
 *   @0x2a56d8 ldr.w r12, [r3]
 *   @0x2a56dc ldr r0, [r3, #0x4]
 *   @0x2a56e0 blx r12
 *   @0x2a56e4 bge 0x2a5752 <zip_stat_index+0xbe>
 *   @0x2a56e8 mrshs r0, apsr
 *   @0x2a56ec mov r2, r8
 *   @0x2a56f0 eors pc, r3, r3, lsr lr
 *   @0x2a56f4 ldr r2, [r5, #0x20]
 *   @0x2a56f8 beq 0x2a56a2 <zip_stat_index+0xe>
 *   @0x2a56fc cmp r6, r3
 *   @0x2a5700 movs r3, #0x3c
 *   @0x2a5704 muls r3, r6, r3
 *   @0x2a5708 ldr r2, [r2, #0xc]
 *   @0x2a570c ldr r2, [r5, #0x20]
 *   @0x2a5710 add r2, r3
 *   @0x2a5714 str r2, [r4, #0x10]
 *   @0x2a5718 ldr r2, [r2]
 *   @0x2a571c ldr r2, [r2, #0x8]
 *   @0x2a5720 ldr r2, [r5, #0x20]
 *   @0x2a5724 add r2, r3
 *   @0x2a5728 str r2, [r4, #0x14]
 *   @0x2a572c ldr r2, [r2]
 *   @0x2a5730 ldrh r2, [r2, #0x6]
 *   @0x2a5734 ldr r2, [r5, #0x20]
 *   @0x2a5738 add r3, r2
 *   @0x2a573c ands r2, r3, #0x1
 *   @0x2a5740 beq 0x2a5750 <zip_stat_index+0xbc>
 *   @0x2a5744 ite mi
 *   @0x2a5748 movwhs r7, #0x13ff
 *   @0x2a574c strh r3, [r4, #0x1a]
 *   @0x2a5750 strh r2, [r4, #0x1a]
 *   @0x2a5754 movs r0, #0x0
 *   @0x2a5758 pop.w {r4, r5, r6, r7, r8, pc}
 *   @0x2a575c mov.w r0, #0xffffffff
 *   @0x2a5760 pop.w {r4, r5, r6, r7, r8, pc}
 *
 * ══ §97/146 png_write_PLTE  0x2b15d0  size 208  52 条（0x2b15d0..0x2b16a0）
 * @func 0x2b15d0 0x2b16a0  size 208  52 条
 * 部分覆盖: 本节 52/87 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x37dd9c / png_write_PLTE+0x54 / png_error / png_write_chunk_start / png_write_chunk_data / png_write_chunk_end
 * 字段偏移 top8: 0xbc×1 / 0x8×1 / 0x7c×1 / 0x6c×1 / 0x-3×1 / 0x-5×1 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b15d0 ldr r3, [pc, #0xbc]
 *   @0x2b15d4 add r3, pc
 *   @0x2b15d8 sub sp, #0x14
 *   @0x2b15dc ldrmi r0, [r6], -sp, lsl #30
 *   @0x2b15e0 mov r5, r1
 *   @0x2b15e4 str r0, [sp, #0x8]
 *   @0x2b15e8 .word 0xf894300c
 *   @0x2b15ec blhs 0x37dd9c <_ZTS13C_UTF16String+0x14e48>
 *   @0x2b15f0 ittet eq
 *   @0x2b15f4 smlatths r1, r11, r1, r2
 *   @0x2b15f8 movne.w r2, #0x100
 *   @0x2b15fc lsleq.w r2, r1, r2
 *   @0x2b1600 ldr.w r1, [r4, #0x2dc]
 *   @0x2b1604 lsls r1, r1, #0x1f
 *   @0x2b1608 cbz r6, 0x2b160e <png_write_PLTE+0x3e>
 *   @0x2b160c bls 0x2b1624 <png_write_PLTE+0x54>
 *   @0x2b1610 mov r0, r4
 *   @0x2b1614 ldr r1, [pc, #0x7c]
 *   @0x2b1618 bl 0x2a642c <png_error>
 *   @0x2b161c b 0x2b1624 <png_write_PLTE+0x54>
 *   @0x2b1620 add r1, pc
 *   @0x2b1624 ldrb.w r3, [r4, #0x1ea]
 *   @0x2b1628 lsls r3, r3, #0x1e
 *   @0x2b162c ldr r1, [pc, #0x6c]
 *   @0x2b1630 add r1, pc
 *   @0x2b1634 eor pc, r9, pc, lsl pc
 *   @0x2b1638 movs r3, #0x3
 *   @0x2b163c cmpmi lr, #220, #2
 *   @0x2b1640 mov r0, r4
 *   @0x2b1644 adds r5, #0x3
 *   @0x2b1648 mov r2, r6
 *   @0x2b164c bl 0x2b11a0 <png_write_chunk_start>
 *   @0x2b1650 cmp r5, r6
 *   @0x2b1654 ldrb r3, [r5, #-3]
 *   @0x2b1658 mov r0, r4
 *   @0x2b165c movs r2, #0x3
 *   @0x2b1660 strb.w r3, [sp, #0x4]
 *   @0x2b1664 ldrb r3, [r5, #-5]
 *   @0x2b1668 strb.w r3, [sp, #0x5]
 *   @0x2b166c ldrb r3, [r5, #-4]
 *   @0x2b1670 strb.w r3, [sp, #0x6]
 *   @0x2b1674 bl 0x2b1204 <png_write_chunk_data>
 *   @0x2b1678 b 0x2b1650 <png_write_PLTE+0x80>
 *   @0x2b167c bl 0x2b1296 <png_write_chunk_end>
 *   @0x2b1680 ldr.w r3, [r4, #0x12c]
 *   @0x2b1684 orr r3, r3, #0x2
 *   @0x2b1688 str.w r3, [r4, #0x12c]
 *   @0x2b168c add sp, #0x14
 *   @0x2b1690 b 0x2b15ac <png_write_IHDR+0x2c8>
 *   @0x2b1694 ldm r4, {r2, r4, r5, r6, r7}
 *   @0x2b1698 ldm r4!, {r1, r3, r5, r6, r7}
 *   @0x2b169c ldm r4, {r1, r2, r3, r4, r5, r6, r7}
 *
 * ══ §98/146 b2PulleyJoint::b2PulleyJoint(b2PulleyJointDef const*)  0x2d1084  size 208  52 条（0x2d1084..0x2d1154）
 * @func 0x2d1084 0x2d1154  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Joint::b2Joint(b2JointDef const*)
 * 字段偏移 top8: 0xa8×1 / 0x44×1 / 0x6c×1 / 0x34×1 / 0x38×1 / 0x3c×1 / 0x54×1 / 0x58×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d1084 push {r3, r4, r5, r6, r7, lr}
 *   @0x2d1088 mov r5, r1
 *   @0x2d108c mov r4, r0
 *   @0x2d1090 bl 0x2cdee0 <_ZN7b2JointC2EPK10b2JointDef>
 *   @0x2d1094 add r3, r5, #20
 *   @0x2d1098 ldr r2, [pc, #0xa8]
 *   @0x2d109c add r12, r5, #28
 *   @0x2d10a0 add r7, r4, #76
 *   @0x2d10a4 ldm r3, {r0, r1}
 *   @0x2d10a8 ldr r2, [pc, r2]
 *   @0x2d10ac mov r3, r4
 *   @0x2d10b0 add r2, r2, #8
 *   @0x2d10b4 str r2, [r3], #68
 *   @0x2d10b8 add r6, r5, #36
 *   @0x2d10bc stm r3, {r0, r1}
 *   @0x2d10c0 vldr s15, [r5, #60]
 *   @0x2d10c4 ldm r12, {r0, r1}
 *   @0x2d10c8 add lr, r4, #92
 *   @0x2d10cc add r12, r5, #44
 *   @0x2d10d0 vcmp.f32 s15, #0
 *   @0x2d10d4 add r2, r4, #100
 *   @0x2d10d8 ldr r3, [pc, #0x6c]
 *   @0x2d10dc stm r7, {r0, r1}
 *   @0x2d10e0 ldm r6, {r0, r1}
 *   @0x2d10e4 ldr r3, [pc, r3]
 *   @0x2d10e8 ldr r7, [r5, #0x34]
 *   @0x2d10ec vmrs APSR_nzcv, fpscr
 *   @0x2d10f0 ldr r6, [r5, #0x38]
 *   @0x2d10f4 stm lr, {r0, r1}
 *   @0x2d10f8 ldm r12, {r0, r1}
 *   @0x2d10fc ldr r3, [r3]
 *   @0x2d1100 stm r2, {r0, r1}
 *   @0x2d1104 moveq r0, #0
 *   @0x2d1108 movne r0, #1
 *   @0x2d110c ldr r1, [pc, #0x3c]
 *   @0x2d1110 str r7, [r4, #0x54]
 *   @0x2d1114 str r6, [r4, #0x58]
 *   @0x2d1118 add r1, pc, r1
 *   @0x2d111c blx r3
 *   @0x2d1120 vldr s14, [r5, #60]
 *   @0x2d1124 vldr s13, [r5, #56]
 *   @0x2d1128 vldr s15, [r5, #52]
 *   @0x2d112c vmla.f32 s15, s14, s13
 *   @0x2d1130 mov r3, #0
 *   @0x2d1134 vstr s14, [r4, #112]
 *   @0x2d1138 mov r0, r4
 *   @0x2d113c str r3, [r4, #0x74]
 *   @0x2d1140 vstr s15, [r4, #108]
 *   @0x2d1144 pop {r3, r4, r5, r6, r7, pc}
 *   @0x2d1148 andseq r0, r2, r4, asr #21
 *   @0x2d114c andseq r0, r2, r4, ror #7
 *   @0x2d1150 muleq r8, r4, r7
 *
 * ══ §99/146 b2GearJoint::Dump()  0x2e3b0c  size 208  52 条（0x2e3b0c..0x2e3bdc）
 * @func 0x2e3b0c 0x2e3bdc  size 208  52 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Log(char const*, ...)×7
 * 字段偏移 top8: 0x38×3 / 0x34×2 / 0x8×2 / 0x48×2 / 0x30×1 / 0x44×1 / 0x90×1 / 0x78×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e3b0c push {r4, r5, r6, r7, r8, lr}
 *   @0x2e3b10 mov r4, r0
 *   @0x2e3b14 ldr r3, [r4, #0x30]
 *   @0x2e3b18 ldr r2, [r4, #0x44]
 *   @0x2e3b1c ldr r1, [r4, #0x34]
 *   @0x2e3b20 ldr r8, [r3, #0x8]
 *   @0x2e3b24 ldr r0, [pc, #0x90]
 *   @0x2e3b28 ldr r3, [r4, #0x48]
 *   @0x2e3b2c add r0, pc, r0
 *   @0x2e3b30 ldr r6, [r2, #0x38]
 *   @0x2e3b34 ldr r7, [r1, #0x8]
 *   @0x2e3b38 ldr r5, [r3, #0x38]
 *   @0x2e3b3c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2e3b40 ldr r0, [pc, #0x78]
 *   @0x2e3b44 mov r1, r8
 *   @0x2e3b48 add r0, pc, r0
 *   @0x2e3b4c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2e3b50 ldr r0, [pc, #0x6c]
 *   @0x2e3b54 mov r1, r7
 *   @0x2e3b58 add r0, pc, r0
 *   @0x2e3b5c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2e3b60 ldr r0, [pc, #0x60]
 *   @0x2e3b64 ldrb r1, [r4, #0x3d]
 *   @0x2e3b68 add r0, pc, r0
 *   @0x2e3b6c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2e3b70 ldr r0, [pc, #0x54]
 *   @0x2e3b74 mov r1, r6
 *   @0x2e3b78 add r0, pc, r0
 *   @0x2e3b7c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2e3b80 ldr r0, [pc, #0x48]
 *   @0x2e3b84 mov r1, r5
 *   @0x2e3b88 add r0, pc, r0
 *   @0x2e3b8c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2e3b90 vldr s15, [r4, #152]
 *   @0x2e3b94 vcvt.f64.f32 d6, s15
 *   @0x2e3b98 ldr r0, [pc, #0x34]
 *   @0x2e3b9c add r0, pc, r0
 *   @0x2e3ba0 vmov r2, r3, d6
 *   @0x2e3ba4 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2e3ba8 ldr r0, [pc, #0x28]
 *   @0x2e3bac ldr r1, [r4, #0x38]
 *   @0x2e3bb0 add r0, pc, r0
 *   @0x2e3bb4 pop {r4, r5, r6, r7, r8, lr}
 *   @0x2e3bb8 b 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2e3bbc andeq r8, r7, r12, ror r8
 *   @0x2e3bc0 andeq r8, r7, r4, ror #6
 *   @0x2e3bc4 andeq r8, r7, r0, ror r3
 *   @0x2e3bc8 andeq r8, r7, r12, ror r3
 *   @0x2e3bcc andeq r8, r7, r8, asr #16
 *   @0x2e3bd0 andeq r8, r7, r4, asr r8
 *   @0x2e3bd4 andeq r8, r7, r12, lsl r7
 *   @0x2e3bd8 andeq r8, r7, r8, lsl #8
 *
 * ══ §100/146 VM::GetDSStack(Buffer_Standard*, int, int)  0xdb210  size 204  51 条（0xdb210..0xdb2dc）
 * @func 0xdb210 0xdb2ec  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetTheStacks(int&) / VM::GetDSStack(Buffer_Standard*, int, int)+0x8c / VM::WriteDSSizeCount(Buffer_Standard*, int, int&) / VM::GetDSStack(Buffer_Standard*, int, int)+0x84 / VM::WriteRValueToBuffer(RValue*, Buffer_Standard*)
 * 字段偏移 top8: 0x4×3 / 0xc×2 / 0x2c×2 / 0x2×1 / 0x30×1 / 0x8×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xdb210 push {r4, r5, r6, r7, r8, lr}
 *   @0xdb214 sub sp, sp, #16
 *   @0xdb218 mov r5, r0
 *   @0xdb21c add r0, sp, #12
 *   @0xdb220 mov r4, r1
 *   @0xdb224 str r2, [sp, #0x4]
 *   @0xdb228 bl 0xffc9c <_Z12GetTheStacksRi>
 *   @0xdb22c cmp r4, #0
 *   @0xdb230 blt 0xdb29c <_ZN2VM10GetDSStackEP15Buffer_Standardii+0x8c>
 *   @0xdb234 ldr r3, [sp, #0xc]
 *   @0xdb238 cmp r4, r3
 *   @0xdb23c bge 0xdb29c <_ZN2VM10GetDSStackEP15Buffer_Standardii+0x8c>
 *   @0xdb240 ldr r7, [r0, r4, lsl #2]
 *   @0xdb244 cmp r7, #0
 *   @0xdb248 beq 0xdb29c <_ZN2VM10GetDSStackEP15Buffer_Standardii+0x8c>
 *   @0xdb24c ldr r6, [r7, #0x4]
 *   @0xdb250 mov r0, r5
 *   @0xdb254 add r2, sp, #4
 *   @0xdb258 mov r1, r6
 *   @0xdb25c bl 0xdb080 <_ZN2VM16WriteDSSizeCountEP15Buffer_StandardiRi>
 *   @0xdb260 subs r8, r0, #0
 *   @0xdb264 ble 0xdb294 <_ZN2VM10GetDSStackEP15Buffer_Standardii+0x84>
 *   @0xdb268 mov r4, #1
 *   @0xdb26c ldr r2, [sp, #0x4]
 *   @0xdb270 mov r1, r5
 *   @0xdb274 ldr r0, [r7, #0xc]
 *   @0xdb278 rsb r2, r2, r6
 *   @0xdb27c rsb r2, r4, r2
 *   @0xdb280 add r4, r4, #1
 *   @0xdb284 add r0, r0, r2, lsl #4
 *   @0xdb288 bl 0xd8a88 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard>
 *   @0xdb28c cmp r8, r4
 *   @0xdb290 bge 0xdb26c <_ZN2VM10GetDSStackEP15Buffer_Standardii+0x5c>
 *   @0xdb294 add sp, sp, #16
 *   @0xdb298 pop {r4, r5, r6, r7, r8, pc}
 *   @0xdb29c mov r2, r5
 *   @0xdb2a0 mov r1, #0
 *   @0xdb2a4 ldr r0, [r2], #44
 *   @0xdb2a8 movt r1, #0xffe0
 *   @0xdb2ac movw r3, #0xffff
 *   @0xdb2b0 str r1, [r5, #0x2c]
 *   @0xdb2b4 movt r3, #0x41ef
 *   @0xdb2b8 mov r1, #0
 *   @0xdb2bc str r3, [r5, #0x30]
 *   @0xdb2c0 ldr r3, [r0, #0x8]
 *   @0xdb2c4 mov r0, r5
 *   @0xdb2c8 str r1, [r5, #0x38]
 *   @0xdb2cc mov r1, #5
 *   @0xdb2d0 blx r3
 *   @0xdb2d4 add sp, sp, #16
 *   @0xdb2d8 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §101/146 dsListAddMap  0x1028a0  size 204  51 条（0x1028a0..0x10296c）
 * @func 0x1028a0 0x10296c  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_DsListAdd(RValue&, CInstance*, CInstance*, int, RValue*) / dsListAddMap+0xbc / CDS_List::Size() / F_DsListMarkAsMap(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x8×1 / 0x20×1 / 0x30×1 / 0x24×1 / 0x34×1 / 0x58×1 / 0x48×1 / 0x4×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1028a0 vmov s11, r1
 *   @0x1028a4 mov r3, #2
 *   @0x1028a8 push {r4, r5, r6, r7, lr}
 *   @0x1028ac mov r5, r0
 *   @0x1028b0 vcvt.f64.s32 d6, s11
 *   @0x1028b4 sub sp, sp, #60
 *   @0x1028b8 vmov s11, r5
 *   @0x1028bc add r6, sp, #8
 *   @0x1028c0 mov r4, #0
 *   @0x1028c4 add r7, sp, #24
 *   @0x1028c8 mov r1, r4
 *   @0x1028cc mov r2, r4
 *   @0x1028d0 mov r0, r6
 *   @0x1028d4 str r7, [sp]
 *   @0x1028d8 str r4, [sp, #0x8]
 *   @0x1028dc str r4, [sp, #0x20]
 *   @0x1028e0 vcvt.f64.s32 d7, s11
 *   @0x1028e4 vstr d6, [sp, #40]
 *   @0x1028e8 str r4, [sp, #0x30]
 *   @0x1028ec str r4, [sp, #0x24]
 *   @0x1028f0 str r4, [sp, #0x34]
 *   @0x1028f4 vstr d7, [sp, #24]
 *   @0x1028f8 bl 0xfc474 <_Z11F_DsListAddR6RValueP9CInstanceS2_iPS_>
 *   @0x1028fc cmp r5, r4
 *   @0x102900 blt 0x10295c <dsListAddMap+0xbc>
 *   @0x102904 ldr r3, [pc, #0x58]
 *   @0x102908 ldr r3, [pc, r3]
 *   @0x10290c ldr r3, [r3]
 *   @0x102910 cmp r5, r3
 *   @0x102914 bge 0x10295c <dsListAddMap+0xbc>
 *   @0x102918 ldr r3, [pc, #0x48]
 *   @0x10291c ldr r3, [pc, r3]
 *   @0x102920 ldr r3, [r3, #0x4]
 *   @0x102924 ldr r0, [r3, r5, lsl #2]
 *   @0x102928 cmp r0, r4
 *   @0x10292c beq 0x10295c <dsListAddMap+0xbc>
 *   @0x102930 bl 0x2052b8 <_ZN8CDS_List4SizeEv>
 *   @0x102934 mov r1, r4
 *   @0x102938 str r7, [sp]
 *   @0x10293c mov r2, r4
 *   @0x102940 mov r3, #2
 *   @0x102944 sub r0, r0, #1
 *   @0x102948 vmov s14, r0
 *   @0x10294c mov r0, r6
 *   @0x102950 vcvt.f64.s32 d7, s14
 *   @0x102954 vstr d7, [sp, #40]
 *   @0x102958 bl 0x1025d0 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_>
 *   @0x10295c add sp, sp, #60
 *   @0x102960 pop {r4, r5, r6, r7, pc}
 *   @0x102964 eoreq r11, lr, r4, ror r3
 *   @0x102968 eoreq r11, lr, r4, ror #6
 *
 * ══ §102/146 F_StringCharAt(RValue&, CInstance*, CInstance*, int, RValue*)  0x1106e4  size 204  51 条（0x1106e4..0x1107b0）
 * @func 0x1106e4 0x1107b0  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: utf8_extract_char×2 / YYCreateString(RValue*, char const*)×2 / YYGetString(RValue const*, int) / YYGetInt32(RValue const*, int) / utf8_strlen / F_StringCharAt(RValue&, CInstance*, CInstance*, int, RValue*)+0xb0 / F_StringCharAt(RValue&, CInstance*, CInstance*, int, RValue*)+0x70 / utf8_add_char
 * 字段偏移 top8: 0x28×1 / 0x-c×1 / 0x4×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1106e4 push {r4, r5, r6, r7, lr}
 *   @0x1106e8 sub sp, sp, #20
 *   @0x1106ec mov r1, #0
 *   @0x1106f0 mov r7, r0
 *   @0x1106f4 ldr r5, [sp, #0x28]
 *   @0x1106f8 mov r0, r5
 *   @0x1106fc bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x110700 mov r1, #1
 *   @0x110704 mov r4, r0
 *   @0x110708 mov r0, r5
 *   @0x11070c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x110710 cmp r4, #0
 *   @0x110714 beq 0x110794 <_Z14F_StringCharAtR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x110718 sub r5, r0, #1
 *   @0x11071c mov r0, r4
 *   @0x110720 bl 0x110648 <utf8_strlen>
 *   @0x110724 bic r5, r5, r5, asr #31
 *   @0x110728 cmp r0, r5
 *   @0x11072c ble 0x110794 <_Z14F_StringCharAtR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x110730 cmp r5, #0
 *   @0x110734 str r4, [sp]
 *   @0x110738 ble 0x110754 <_Z14F_StringCharAtR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x11073c mov r4, #0
 *   @0x110740 add r4, r4, #1
 *   @0x110744 mov r0, sp
 *   @0x110748 bl 0x10fb38 <utf8_extract_char>
 *   @0x11074c cmp r4, r5
 *   @0x110750 bne 0x110740 <_Z14F_StringCharAtR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x110754 add r4, sp, #16
 *   @0x110758 mov r0, sp
 *   @0x11075c add r5, sp, #8
 *   @0x110760 str r5, [r4, #-0xc]!
 *   @0x110764 bl 0x10fb38 <utf8_extract_char>
 *   @0x110768 mov r1, r0
 *   @0x11076c mov r0, r4
 *   @0x110770 bl 0x10fe28 <utf8_add_char>
 *   @0x110774 ldr r3, [sp, #0x4]
 *   @0x110778 mov r2, #0
 *   @0x11077c mov r1, r5
 *   @0x110780 mov r0, r7
 *   @0x110784 strb r2, [r3]
 *   @0x110788 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x11078c add sp, sp, #20
 *   @0x110790 pop {r4, r5, r6, r7, pc}
 *   @0x110794 ldr r1, [pc, #0x10]
 *   @0x110798 mov r0, r7
 *   @0x11079c add r1, pc, r1
 *   @0x1107a0 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x1107a4 add sp, sp, #20
 *   @0x1107a8 pop {r4, r5, r6, r7, pc}
 *   @0x1107ac mlaeq r1, r10, r3, lr
 *
 * ══ §103/146 F_ExternalDefine5(RValue&, CInstance*, CInstance*, int, RValue*)  0x1163a8  size 204  51 条（0x1163a8..0x116474）
 * @func 0x1163a8 0x116474  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)×2 / YYGetInt32(RValue const*, int) / DLL_Define(char const*, char const*, int, int, int*, int) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x4×2 / 0x68×1 / 0xc×1 / 0x10×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1163a8 push {r4, r5, r6, r7, r8, lr}
 *   @0x1163ac sub sp, sp, #80
 *   @0x1163b0 mov r1, #0
 *   @0x1163b4 mov r7, r0
 *   @0x1163b8 ldr r4, [sp, #0x68]
 *   @0x1163bc mov r0, r4
 *   @0x1163c0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1163c4 mov r1, #1
 *   @0x1163c8 mov r8, r0
 *   @0x1163cc mov r0, r4
 *   @0x1163d0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1163d4 mov r1, #2
 *   @0x1163d8 mov r5, r0
 *   @0x1163dc mov r0, r4
 *   @0x1163e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1163e4 add r3, sp, #8
 *   @0x1163e8 add r12, sp, #76
 *   @0x1163ec mov r2, #0
 *   @0x1163f0 subs r0, r0, #1
 *   @0x1163f4 rsbs r1, r0, #0
 *   @0x1163f8 adcs r1, r1, r0
 *   @0x1163fc str r2, [r3, #0x4]!
 *   @0x116400 cmp r3, r12
 *   @0x116404 mov r6, #0
 *   @0x116408 bne 0x1163fc <_Z17F_ExternalDefine5R6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x11640c str r6, [r7, #0xc]
 *   @0x116410 mov r2, r6
 *   @0x116414 str r1, [sp, #0x4]
 *   @0x116418 add r3, sp, #12
 *   @0x11641c mov r1, r5
 *   @0x116420 str r3, [sp]
 *   @0x116424 mov r0, r8
 *   @0x116428 mov r3, #5
 *   @0x11642c bl 0x2148fc <_Z10DLL_DefinePKcS0_iiPii>
 *   @0x116430 vmov.f64 d7, #-1.000000e+00
 *   @0x116434 vmov s13, r0
 *   @0x116438 vcvt.f64.s32 d6, s13
 *   @0x11643c vmov r0, r1, d6
 *   @0x116440 vmov r2, s12
 *   @0x116444 vcmp.f64 d6, d7
 *   @0x116448 vmrs APSR_nzcv, fpscr
 *   @0x11644c mov r3, r1
 *   @0x116450 stm r7, {r2, r3}
 *   @0x116454 bne 0x116468 <_Z17F_ExternalDefine5R6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x116458 ldr r0, [pc, #0x10]
 *   @0x11645c mov r1, r6
 *   @0x116460 add r0, pc, r0
 *   @0x116464 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x116468 add sp, sp, #80
 *   @0x11646c pop {r4, r5, r6, r7, r8, pc}
 *   @0x116470 eoreq r3, r2, r0, asr #4
 *
 * ══ §104/146 F_DateGetMonth(RValue&, CInstance*, CInstance*, int, RValue*)  0x116d18  size 204  51 条（0x116d18..0x116de4）
 * @func 0x116d18 0x116de4  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int) / __fixdfdi / 0xb6820 / 0xb682c / 0x827a8c
 * 字段偏移 top8: 0xc×1 / 0x10×1 / 0x64×1
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x116d18 push {r4, lr}
 *   @0x116d1c sub sp, sp, #8
 *   @0x116d20 mov r1, #0
 *   @0x116d24 mov r4, r0
 *   @0x116d28 mov r3, r1
 *   @0x116d2c str r1, [r0, #0xc]
 *   @0x116d30 movt r3, #0xbff0
 *   @0x116d34 stm r0, {r1, r3}
 *   @0x116d38 ldr r0, [sp, #0x10]
 *   @0x116d3c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x116d40 vldr d7, [pc, #128]
 *   @0x116d44 vldr d5, [pc, #132]
 *   @0x116d48 vmov d6, r0, r1
 *   @0x116d4c vsub.f64 d7, d6, d7
 *   @0x116d50 vabs.f64 d4, d7
 *   @0x116d54 vcmpe.f64 d4, d5
 *   @0x116d58 vmrs APSR_nzcv, fpscr
 *   @0x116d5c vldrls d7, [pc, #116]
 *   @0x116d60 vldrhi d6, [pc, #112]
 *   @0x116d64 vmul.f64 d5, d7, d6
 *   @0x116d68 vmov r0, r1, d5
 *   @0x116d6c bl 0x3194a0 <__fixdfdi>
 *   @0x116d70 mov r3, r1
 *   @0x116d74 ldr r1, [pc, #0x64]
 *   @0x116d78 mov r2, r0
 *   @0x116d7c strd r2, r3, [sp]
 *   @0x116d80 add r1, pc, r1
 *   @0x116d84 mov r0, sp
 *   @0x116d88 ldrb r3, [r1]
 *   @0x116d8c cmp r3, #0
 *   @0x116d90 bne 0x116dc0 <_Z14F_DateGetMonthR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x116d94 bl 0xb6820 <gmtime64@plt>
 *   @0x116d98 cmp r0, #0
 *   @0x116d9c beq 0x116db8 <_Z14F_DateGetMonthR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x116da0 vmov.f64 d7, #1.000000e+00
 *   @0x116da4 vldr s12, [r0, #16]
 *   @0x116da8 vcvt.f64.s32 d6, s12
 *   @0x116dac vadd.f64 d5, d6, d7
 *   @0x116db0 vmov r2, r3, d5
 *   @0x116db4 stm r4, {r2, r3}
 *   @0x116db8 add sp, sp, #8
 *   @0x116dbc pop {r4, pc}
 *   @0x116dc0 bl 0xb682c <localtime64@plt>
 *   @0x116dc4 b 0x116d98 <_Z14F_DateGetMonthR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x116dc8 andeq r0, r0, r0
 *   @0x116dcc sbcsmi pc, r8, r0, asr #16
 *   @0x116dd0 bl 0x827a8c <b2_toiTime+0xce5e8>
 *   @0x116dd4 svclo #0x1a36e2
 *   @0x116dd8 andeq r0, r0, r0
 *   @0x116ddc rscsmi r1, r5, r0, lsl #16
 *   @0x116de0 .word 0x002db3b8
 *
 * ══ §105/146 F_DrawRectangleExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x11b55c  size 204  51 条（0x11b55c..0x11b628）
 * @func 0x11b55c 0x11b628  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×4 / YYGetInt32(RValue const*, int)×4 / YYGetBool(RValue const*, int) / GR_Draw_Rectangle_Ext(float, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, bool)
 * 字段偏移 top8: 0x1c×2 / 0x48×1 / 0x8×1 / 0xc×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11b55c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x11b560 sub sp, sp, #36
 *   @0x11b564 mov r1, #0
 *   @0x11b568 ldr r4, [sp, #0x48]
 *   @0x11b56c mov r0, r4
 *   @0x11b570 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b574 mov r1, #1
 *   @0x11b578 mov r5, r0
 *   @0x11b57c mov r0, r4
 *   @0x11b580 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b584 mov r1, #2
 *   @0x11b588 mov r8, r0
 *   @0x11b58c mov r0, r4
 *   @0x11b590 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b594 mov r1, #3
 *   @0x11b598 mov r7, r0
 *   @0x11b59c mov r0, r4
 *   @0x11b5a0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x11b5a4 mov r1, #4
 *   @0x11b5a8 mov r6, r0
 *   @0x11b5ac mov r0, r4
 *   @0x11b5b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11b5b4 mov r1, #5
 *   @0x11b5b8 mov r3, r0
 *   @0x11b5bc mov r0, r4
 *   @0x11b5c0 str r3, [sp, #0x1c]
 *   @0x11b5c4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11b5c8 mov r1, #6
 *   @0x11b5cc mov r11, r0
 *   @0x11b5d0 mov r0, r4
 *   @0x11b5d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11b5d8 mov r1, #7
 *   @0x11b5dc mov r10, r0
 *   @0x11b5e0 mov r0, r4
 *   @0x11b5e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11b5e8 mov r1, #8
 *   @0x11b5ec mov r9, r0
 *   @0x11b5f0 mov r0, r4
 *   @0x11b5f4 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x11b5f8 ldr r3, [sp, #0x1c]
 *   @0x11b5fc str r10, [sp, #0x8]
 *   @0x11b600 mov r1, r8
 *   @0x11b604 str r9, [sp, #0xc]
 *   @0x11b608 mov r2, r7
 *   @0x11b60c stm sp, {r3, r11}
 *   @0x11b610 mov r3, r6
 *   @0x11b614 str r0, [sp, #0x10]
 *   @0x11b618 mov r0, r5
 *   @0x11b61c bl 0x16ac60 <_Z21GR_Draw_Rectangle_Extffffjjjjb>
 *   @0x11b620 add sp, sp, #36
 *   @0x11b624 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §106/146 F_TileSetPosition(RValue&, CInstance*, CInstance*, int, RValue*)  0x120aa4  size 204  51 条（0x120aa4..0x120b70）
 * @func 0x120aa4 0x120b80  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / YYGetInt32(RValue const*, int) / CRoom::FindTile(int) / F_TileSetPosition(RValue&, CInstance*, CInstance*, int, RValue*)+0xb0
 * 字段偏移 top8: 0xb8×2 / 0x18×1 / 0xb0×1 / 0x4×1 / 0xc0×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x120aa4 push {r3, r4, r5, r6, r7, lr}
 *   @0x120aa8 mov r1, #0
 *   @0x120aac ldr r7, [sp, #0x18]
 *   @0x120ab0 ldr r5, [pc, #0xb0]
 *   @0x120ab4 ldr r5, [pc, r5]
 *   @0x120ab8 mov r0, r7
 *   @0x120abc ldr r4, [r5]
 *   @0x120ac0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x120ac4 mov r1, r0
 *   @0x120ac8 mov r0, r4
 *   @0x120acc bl 0x1af2bc <_ZN5CRoom8FindTileEi>
 *   @0x120ad0 subs r6, r0, #0
 *   @0x120ad4 blt 0x120b54 <_Z17F_TileSetPositionR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x120ad8 ldr r3, [r5]
 *   @0x120adc mov r1, #1
 *   @0x120ae0 mov r0, r7
 *   @0x120ae4 ldr r2, [r3, #0xb8]
 *   @0x120ae8 cmp r6, r2
 *   @0x120aec rsblt r4, r6, r6, lsl #3
 *   @0x120af0 ldrlt r3, [r3, #0xc0]
 *   @0x120af4 movge r4, #0
 *   @0x120af8 addlt r4, r3, r4, lsl #3
 *   @0x120afc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x120b00 mov r1, #2
 *   @0x120b04 str r0, [r4]
 *   @0x120b08 mov r0, r7
 *   @0x120b0c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x120b10 ldr r3, [r5]
 *   @0x120b14 ldr r2, [r3, #0xb8]
 *   @0x120b18 cmp r6, r2
 *   @0x120b1c str r0, [r4, #0x4]
 *   @0x120b20 popge {r3, r4, r5, r6, r7, pc}
 *   @0x120b24 ldr r5, [r3, #0xc0]
 *   @0x120b28 rsb r6, r6, r6, lsl #3
 *   @0x120b2c ldm r4!, {r0, r1, r2, r3}
 *   @0x120b30 add r12, r5, r6, lsl #3
 *   @0x120b34 stm r12!, {r0, r1, r2, r3}
 *   @0x120b38 ldm r4!, {r0, r1, r2, r3}
 *   @0x120b3c stm r12!, {r0, r1, r2, r3}
 *   @0x120b40 ldm r4!, {r0, r1, r2, r3}
 *   @0x120b44 stm r12!, {r0, r1, r2, r3}
 *   @0x120b48 ldm r4, {r0, r1}
 *   @0x120b4c stm r12, {r0, r1}
 *   @0x120b50 pop {r3, r4, r5, r6, r7, pc}
 *   @0x120b54 ldr r0, [pc, #0x10]
 *   @0x120b58 mov r1, #0
 *   @0x120b5c pop {r3, r4, r5, r6, r7, lr}
 *   @0x120b60 add r0, pc, r0
 *   @0x120b64 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x120b68 eoreq r12, r12, r4, ror lr
 *   @0x120b6c mlaeq r1, r12, r6, r9
 *
 * ══ §107/146 F_TileSetScale(RValue&, CInstance*, CInstance*, int, RValue*)  0x120b70  size 204  51 条（0x120b70..0x120c3c）
 * @func 0x120b70 0x120c3c  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / YYGetInt32(RValue const*, int) / CRoom::FindTile(int) / F_TileSetScale(RValue&, CInstance*, CInstance*, int, RValue*)+0xb0
 * 字段偏移 top8: 0xb8×2 / 0x18×1 / 0xb0×1 / 0x24×1 / 0x28×1 / 0xc0×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x120b70 push {r3, r4, r5, r6, r7, lr}
 *   @0x120b74 mov r1, #0
 *   @0x120b78 ldr r7, [sp, #0x18]
 *   @0x120b7c ldr r5, [pc, #0xb0]
 *   @0x120b80 ldr r5, [pc, r5]
 *   @0x120b84 mov r0, r7
 *   @0x120b88 ldr r4, [r5]
 *   @0x120b8c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x120b90 mov r1, r0
 *   @0x120b94 mov r0, r4
 *   @0x120b98 bl 0x1af2bc <_ZN5CRoom8FindTileEi>
 *   @0x120b9c subs r6, r0, #0
 *   @0x120ba0 blt 0x120c20 <_Z14F_TileSetScaleR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x120ba4 ldr r3, [r5]
 *   @0x120ba8 mov r1, #1
 *   @0x120bac mov r0, r7
 *   @0x120bb0 ldr r2, [r3, #0xb8]
 *   @0x120bb4 cmp r6, r2
 *   @0x120bb8 rsblt r4, r6, r6, lsl #3
 *   @0x120bbc ldrlt r3, [r3, #0xc0]
 *   @0x120bc0 movge r4, #0
 *   @0x120bc4 addlt r4, r3, r4, lsl #3
 *   @0x120bc8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x120bcc mov r1, #2
 *   @0x120bd0 str r0, [r4, #0x24]
 *   @0x120bd4 mov r0, r7
 *   @0x120bd8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x120bdc ldr r3, [r5]
 *   @0x120be0 ldr r2, [r3, #0xb8]
 *   @0x120be4 cmp r6, r2
 *   @0x120be8 str r0, [r4, #0x28]
 *   @0x120bec popge {r3, r4, r5, r6, r7, pc}
 *   @0x120bf0 ldr r5, [r3, #0xc0]
 *   @0x120bf4 rsb r6, r6, r6, lsl #3
 *   @0x120bf8 ldm r4!, {r0, r1, r2, r3}
 *   @0x120bfc add r12, r5, r6, lsl #3
 *   @0x120c00 stm r12!, {r0, r1, r2, r3}
 *   @0x120c04 ldm r4!, {r0, r1, r2, r3}
 *   @0x120c08 stm r12!, {r0, r1, r2, r3}
 *   @0x120c0c ldm r4!, {r0, r1, r2, r3}
 *   @0x120c10 stm r12!, {r0, r1, r2, r3}
 *   @0x120c14 ldm r4, {r0, r1}
 *   @0x120c18 stm r12, {r0, r1}
 *   @0x120c1c pop {r3, r4, r5, r6, r7, pc}
 *   @0x120c20 ldr r0, [pc, #0x10]
 *   @0x120c24 mov r1, #0
 *   @0x120c28 pop {r3, r4, r5, r6, r7, lr}
 *   @0x120c2c add r0, pc, r0
 *   @0x120c30 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x120c34 eoreq r12, r12, r8, lsr #27
 *   @0x120c38 .word 0x002195d0
 *
 * ══ §108/146 F_SoundEffectEqualizer(RValue&, CInstance*, CInstance*, int, RValue*)  0x134390  size 204  51 条（0x134390..0x13445c）
 * @func 0x134390 0x13445c  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×3 / YYGetInt32(RValue const*, int) / Sound_Data(int) / CSound::GetSoundId() / SND_Set_Effect_Equalizer(int, double, double, double)
 * 字段偏移 top8: 0xb8×1 / 0x30×1 / 0x9c×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x134390 ldr r3, [pc, #0xb8]
 *   @0x134394 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x134398 ldr r3, [pc, r3]
 *   @0x13439c sub sp, sp, #20
 *   @0x1343a0 ldrb r3, [r3]
 *   @0x1343a4 ldr r8, [sp, #0x30]
 *   @0x1343a8 cmp r3, #0
 *   @0x1343ac bne 0x1343c4 <_Z22F_SoundEffectEqualizerR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x1343b0 ldr r3, [pc, #0x9c]
 *   @0x1343b4 ldr r3, [pc, r3]
 *   @0x1343b8 ldrb r1, [r3]
 *   @0x1343bc cmp r1, #0
 *   @0x1343c0 beq 0x1343cc <_Z22F_SoundEffectEqualizerR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x1343c4 add sp, sp, #20
 *   @0x1343c8 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x1343cc mov r0, r8
 *   @0x1343d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1343d4 bl 0x21fcd4 <_Z10Sound_Datai>
 *   @0x1343d8 subs r1, r0, #0
 *   @0x1343dc beq 0x13443c <_Z22F_SoundEffectEqualizerR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x1343e0 bl 0x215748 <_ZN6CSound10GetSoundIdEv>
 *   @0x1343e4 mov r1, #1
 *   @0x1343e8 mov r9, r0
 *   @0x1343ec mov r0, r8
 *   @0x1343f0 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1343f4 mov r4, r0
 *   @0x1343f8 mov r5, r1
 *   @0x1343fc mov r0, r8
 *   @0x134400 mov r1, #2
 *   @0x134404 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x134408 mov r6, r0
 *   @0x13440c mov r7, r1
 *   @0x134410 mov r0, r8
 *   @0x134414 mov r1, #3
 *   @0x134418 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x13441c strd r6, r7, [sp]
 *   @0x134420 mov r2, r4
 *   @0x134424 mov r3, r5
 *   @0x134428 strd r0, r1, [sp, #8]
 *   @0x13442c mov r0, r9
 *   @0x134430 bl 0x21f14c <_Z24SND_Set_Effect_Equalizeriddd>
 *   @0x134434 add sp, sp, #20
 *   @0x134438 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x13443c ldr r0, [pc, #0x14]
 *   @0x134440 add r0, pc, r0
 *   @0x134444 add sp, sp, #20
 *   @0x134448 pop {r4, r5, r6, r7, r8, r9, lr}
 *   @0x13444c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x134450 mlaeq r11, r8, r9, r10
 *   @0x134454 mlaeq r11, r8, r12, r10
 *   @0x134458 eoreq r11, r0, r12, asr #32
 *
 * ══ §109/146 F_Sound3DSetSoundPosition(RValue&, CInstance*, CInstance*, int, RValue*)  0x134540  size 204  51 条（0x134540..0x13460c）
 * @func 0x134540 0x13460c  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetReal(RValue const*, int)×3 / YYGetInt32(RValue const*, int) / Sound_Data(int) / CSound::GetSoundId() / SND_3D_Set_Sound_Position(int, double, double, double)
 * 字段偏移 top8: 0xb8×1 / 0x30×1 / 0x9c×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x134540 ldr r3, [pc, #0xb8]
 *   @0x134544 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x134548 ldr r3, [pc, r3]
 *   @0x13454c sub sp, sp, #20
 *   @0x134550 ldrb r3, [r3]
 *   @0x134554 ldr r8, [sp, #0x30]
 *   @0x134558 cmp r3, #0
 *   @0x13455c bne 0x134574 <_Z25F_Sound3DSetSoundPositionR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x134560 ldr r3, [pc, #0x9c]
 *   @0x134564 ldr r3, [pc, r3]
 *   @0x134568 ldrb r1, [r3]
 *   @0x13456c cmp r1, #0
 *   @0x134570 beq 0x13457c <_Z25F_Sound3DSetSoundPositionR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x134574 add sp, sp, #20
 *   @0x134578 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x13457c mov r0, r8
 *   @0x134580 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x134584 bl 0x21fcd4 <_Z10Sound_Datai>
 *   @0x134588 subs r1, r0, #0
 *   @0x13458c beq 0x1345ec <_Z25F_Sound3DSetSoundPositionR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x134590 bl 0x215748 <_ZN6CSound10GetSoundIdEv>
 *   @0x134594 mov r1, #1
 *   @0x134598 mov r9, r0
 *   @0x13459c mov r0, r8
 *   @0x1345a0 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1345a4 mov r4, r0
 *   @0x1345a8 mov r5, r1
 *   @0x1345ac mov r0, r8
 *   @0x1345b0 mov r1, #2
 *   @0x1345b4 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1345b8 mov r6, r0
 *   @0x1345bc mov r7, r1
 *   @0x1345c0 mov r0, r8
 *   @0x1345c4 mov r1, #3
 *   @0x1345c8 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x1345cc strd r6, r7, [sp]
 *   @0x1345d0 mov r2, r4
 *   @0x1345d4 mov r3, r5
 *   @0x1345d8 strd r0, r1, [sp, #8]
 *   @0x1345dc mov r0, r9
 *   @0x1345e0 bl 0x21f16c <_Z25SND_3D_Set_Sound_Positioniddd>
 *   @0x1345e4 add sp, sp, #20
 *   @0x1345e8 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x1345ec ldr r0, [pc, #0x14]
 *   @0x1345f0 add r0, pc, r0
 *   @0x1345f4 add sp, sp, #20
 *   @0x1345f8 pop {r4, r5, r6, r7, r8, r9, lr}
 *   @0x1345fc b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x134600 eoreq r10, r11, r8, ror #15
 *   @0x134604 eoreq r10, r11, r8, ror #21
 *   @0x134608 mlaeq r0, r12, lr, r10
 *
 * ══ §110/146 F_ActionLinearStep(RValue&, CInstance*, CInstance*, int, RValue*)  0x13e18c  size 204  51 条（0x13e18c..0x13e258）
 * @func 0x13e18c 0x13e258  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×3 / Motion_Linear_Step(CInstance*, float, float, float, int, bool)×2 / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x20×1 / 0x70×1 / 0x4×1
 * VFP 指令 13 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13e18c push {r4, r5, r6, lr}
 *   @0x13e190 vpush {d8}
 *   @0x13e194 sub sp, sp, #8
 *   @0x13e198 mov r5, r1
 *   @0x13e19c mov r1, #0
 *   @0x13e1a0 ldr r4, [sp, #0x20]
 *   @0x13e1a4 mov r0, r4
 *   @0x13e1a8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13e1ac mov r1, #1
 *   @0x13e1b0 vmov s17, r0
 *   @0x13e1b4 mov r0, r4
 *   @0x13e1b8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13e1bc mov r1, #2
 *   @0x13e1c0 vmov s16, r0
 *   @0x13e1c4 mov r0, r4
 *   @0x13e1c8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13e1cc mov r1, #3
 *   @0x13e1d0 mov r6, r0
 *   @0x13e1d4 mov r0, r4
 *   @0x13e1d8 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x13e1dc ldr r2, [pc, #0x70]
 *   @0x13e1e0 ldr r2, [pc, r2]
 *   @0x13e1e4 ldrb r3, [r2]
 *   @0x13e1e8 cmp r3, #0
 *   @0x13e1ec str r0, [sp, #0x4]
 *   @0x13e1f0 bne 0x13e21c <_Z18F_ActionLinearStepR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x13e1f4 mov r0, r5
 *   @0x13e1f8 mov r3, r6
 *   @0x13e1fc mvn r2, #2
 *   @0x13e200 vmov r1, s17
 *   @0x13e204 str r2, [sp]
 *   @0x13e208 vmov r2, s16
 *   @0x13e20c bl 0x19c8a8 <_Z18Motion_Linear_StepP9CInstancefffib>
 *   @0x13e210 add sp, sp, #8
 *   @0x13e214 vpop {d8}
 *   @0x13e218 pop {r4, r5, r6, pc}
 *   @0x13e21c vldr s14, [r5, #180]
 *   @0x13e220 vldr s15, [r5, #184]
 *   @0x13e224 vadd.f32 s14, s17, s14
 *   @0x13e228 mov r3, r6
 *   @0x13e22c mov r0, r5
 *   @0x13e230 mvn r2, #2
 *   @0x13e234 str r2, [sp]
 *   @0x13e238 vadd.f32 s15, s16, s15
 *   @0x13e23c vmov r1, s14
 *   @0x13e240 vmov r2, s15
 *   @0x13e244 bl 0x19c8a8 <_Z18Motion_Linear_StepP9CInstancefffib>
 *   @0x13e248 add sp, sp, #8
 *   @0x13e24c vpop {d8}
 *   @0x13e250 pop {r4, r5, r6, pc}
 *   @0x13e254 eoreq pc, r10, r12, asr r9
 *
 * ══ §111/146 F_ActionIfCollision(RValue&, CInstance*, CInstance*, int, RValue*)  0x13ed30  size 204  51 条（0x13ed30..0x13edfc）
 * @func 0x13ed30 0x13ee0c  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×2 / YYGetInt32(RValue const*, int) / Command_IsFree(CInstance*, float, float) / Command_IsEmpty(CInstance*, float, float)
 * 字段偏移 top8: 0x18×1 / 0xc×1 / 0x78×1 / 0x4×1
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13ed30 push {r4, r5, r6, lr}
 *   @0x13ed34 vpush {d8}
 *   @0x13ed38 mov r3, #0
 *   @0x13ed3c ldr r4, [sp, #0x18]
 *   @0x13ed40 mov r6, r1
 *   @0x13ed44 str r3, [r0, #0xc]
 *   @0x13ed48 mov r1, r3
 *   @0x13ed4c mov r5, r0
 *   @0x13ed50 mov r0, r4
 *   @0x13ed54 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13ed58 mov r1, #1
 *   @0x13ed5c vmov s17, r0
 *   @0x13ed60 mov r0, r4
 *   @0x13ed64 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13ed68 mov r1, #2
 *   @0x13ed6c vmov s16, r0
 *   @0x13ed70 mov r0, r4
 *   @0x13ed74 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13ed78 ldr r3, [pc, #0x78]
 *   @0x13ed7c ldr r3, [pc, r3]
 *   @0x13ed80 ldrb r3, [r3]
 *   @0x13ed84 cmp r3, #0
 *   @0x13ed88 vldrne s14, [r6, #180]
 *   @0x13ed8c vldrne s15, [r6, #184]
 *   @0x13ed90 vaddne.f32 s17, s17, s14
 *   @0x13ed94 mov r4, r0
 *   @0x13ed98 mov r0, r6
 *   @0x13ed9c vaddne.f32 s16, s16, s15
 *   @0x13eda0 cmp r4, #0
 *   @0x13eda4 vmov r1, s17
 *   @0x13eda8 vmov r2, s16
 *   @0x13edac bne 0x13edd4 <_Z19F_ActionIfCollisionR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x13edb0 bl 0x1cab94 <_Z14Command_IsFreeP9CInstanceff>
 *   @0x13edb4 str r4, [r5]
 *   @0x13edb8 cmp r0, #0
 *   @0x13edbc moveq r3, #0
 *   @0x13edc0 movne r3, r4
 *   @0x13edc4 movteq r3, #0x3ff0
 *   @0x13edc8 str r3, [r5, #0x4]
 *   @0x13edcc vpop {d8}
 *   @0x13edd0 pop {r4, r5, r6, pc}
 *   @0x13edd4 bl 0x1caa1c <_Z15Command_IsEmptyP9CInstanceff>
 *   @0x13edd8 cmp r0, #0
 *   @0x13eddc movne r0, #0
 *   @0x13ede0 moveq r3, #0
 *   @0x13ede4 movne r3, r0
 *   @0x13ede8 movteq r3, #0x3ff0
 *   @0x13edec stm r5, {r0, r3}
 *   @0x13edf0 vpop {d8}
 *   @0x13edf4 pop {r4, r5, r6, pc}
 *   @0x13edf8 eoreq lr, r10, r0, asr #27
 *
 * ══ §112/146 F_ActionIfNumber(RValue&, CInstance*, CInstance*, int, RValue*)  0x13edfc  size 204  51 条（0x13edfc..0x13eec8）
 * @func 0x13edfc 0x13eec8  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / YYGetReal(RValue const*, int) / Command_InstanceNumber(int)
 * 字段偏移 top8: 0x4×3 / 0x20×1 / 0xc×1
 * VFP 指令 13 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13edfc push {r3, r4, r5, r6, r7, lr}
 *   @0x13ee00 vpush {d8}
 *   @0x13ee04 mov r1, #0
 *   @0x13ee08 ldr r4, [sp, #0x20]
 *   @0x13ee0c mov r5, r0
 *   @0x13ee10 mov r6, r1
 *   @0x13ee14 mov r0, r4
 *   @0x13ee18 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13ee1c mov r1, #1
 *   @0x13ee20 mov r7, r0
 *   @0x13ee24 mov r0, r4
 *   @0x13ee28 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x13ee2c vmov d8, r0, r1
 *   @0x13ee30 mov r0, r4
 *   @0x13ee34 mov r1, #2
 *   @0x13ee38 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13ee3c str r6, [r5, #0xc]
 *   @0x13ee40 mov r4, r0
 *   @0x13ee44 mov r0, r7
 *   @0x13ee48 bl 0x1c8ed0 <_Z22Command_InstanceNumberi>
 *   @0x13ee4c cmp r4, #1
 *   @0x13ee50 vmov s13, r0
 *   @0x13ee54 vcvt.f64.s32 d7, s13
 *   @0x13ee58 beq 0x13eea8 <_Z16F_ActionIfNumberR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x13ee5c cmp r4, #2
 *   @0x13ee60 beq 0x13ee88 <_Z16F_ActionIfNumberR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x13ee64 vcmp.f64 d7, d8
 *   @0x13ee68 vmrs APSR_nzcv, fpscr
 *   @0x13ee6c bne 0x13ee94 <_Z16F_ActionIfNumberR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x13ee70 mov r3, #0
 *   @0x13ee74 movt r3, #0x3ff0
 *   @0x13ee78 str r6, [r5]
 *   @0x13ee7c str r3, [r5, #0x4]
 *   @0x13ee80 vpop {d8}
 *   @0x13ee84 pop {r3, r4, r5, r6, r7, pc}
 *   @0x13ee88 vcmpe.f64 d8, d7
 *   @0x13ee8c vmrs APSR_nzcv, fpscr
 *   @0x13ee90 bmi 0x13ee70 <_Z16F_ActionIfNumberR6RValueP9CInstanceS2_iPS_+0x74>
 *   @0x13ee94 mov r3, r6
 *   @0x13ee98 str r6, [r5]
 *   @0x13ee9c str r3, [r5, #0x4]
 *   @0x13eea0 vpop {d8}
 *   @0x13eea4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x13eea8 vcmpe.f64 d8, d7
 *   @0x13eeac mov r3, r6
 *   @0x13eeb0 vmrs APSR_nzcv, fpscr
 *   @0x13eeb4 bgt 0x13ee74 <_Z16F_ActionIfNumberR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x13eeb8 str r6, [r5]
 *   @0x13eebc str r3, [r5, #0x4]
 *   @0x13eec0 vpop {d8}
 *   @0x13eec4 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §113/146 F_GPUGetBlendModeExtSepAlpha(RValue&, CInstance*, CInstance*, int, RValue*)  0x1480b4  size 204  51 条（0x1480b4..0x148180）
 * @func 0x1480b4 0x148180  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RenderStateManager::GetRenderState(eRenderState)×4 / CreateArray(RValue*, int, ...)
 * 字段偏移 top8: 0xc×1 / 0x94×1 / 0x10×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1480b4 cmp r3, #0
 *   @0x1480b8 mov r3, #0
 *   @0x1480bc push {r4, r5, r6, r7, r8, lr}
 *   @0x1480c0 mov r1, r3
 *   @0x1480c4 sub sp, sp, #24
 *   @0x1480c8 movt r3, #0xbff0
 *   @0x1480cc mov r4, r0
 *   @0x1480d0 str r1, [r0, #0xc]
 *   @0x1480d4 stm r0, {r1, r3}
 *   @0x1480d8 bne 0x148164 <_Z28F_GPUGetBlendModeExtSepAlphaR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x1480dc ldr r5, [pc, #0x94]
 *   @0x1480e0 mov r1, #6
 *   @0x1480e4 ldr r5, [pc, r5]
 *   @0x1480e8 mov r0, r5
 *   @0x1480ec bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState>
 *   @0x1480f0 mov r1, #7
 *   @0x1480f4 mov r6, r0
 *   @0x1480f8 mov r0, r5
 *   @0x1480fc bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState>
 *   @0x148100 mov r1, #34
 *   @0x148104 mov r8, r0
 *   @0x148108 mov r0, r5
 *   @0x14810c bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState>
 *   @0x148110 mov r1, #35
 *   @0x148114 mov r7, r0
 *   @0x148118 mov r0, r5
 *   @0x14811c bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState>
 *   @0x148120 vmov s11, r8
 *   @0x148124 mov r1, #4
 *   @0x148128 vcvt.f64.u32 d6, s11
 *   @0x14812c vmov s11, r7
 *   @0x148130 vcvt.f64.u32 d7, s11
 *   @0x148134 vstr d6, [sp]
 *   @0x148138 vstr d7, [sp, #8]
 *   @0x14813c vmov s15, r6
 *   @0x148140 vcvt.f64.u32 d7, s15
 *   @0x148144 vmov r2, r3, d7
 *   @0x148148 vmov s11, r0
 *   @0x14814c mov r0, r4
 *   @0x148150 vcvt.f64.u32 d7, s11
 *   @0x148154 vstr d7, [sp, #16]
 *   @0x148158 bl 0x120eb4 <_Z11CreateArrayP6RValueiz>
 *   @0x14815c add sp, sp, #24
 *   @0x148160 pop {r4, r5, r6, r7, r8, pc}
 *   @0x148164 ldr r0, [pc, #0x10]
 *   @0x148168 add r0, pc, r0
 *   @0x14816c add sp, sp, #24
 *   @0x148170 pop {r4, r5, r6, r7, r8, lr}
 *   @0x148174 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x148178 eoreq r5, r10, r4, lsl r12
 *   @0x14817c andseq r9, pc, r8, asr #29
 *
 * ══ §114/146 GraphicsPerf::Quit()  0x17b048  size 204  51 条（0x17b048..0x17b114）
 * @func 0x17b048 0x17b114  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x17b054→0x3eb70c, 0x17b098→0x3f26ac, 0x17b09c→0x3f26b4, 0x17b0a4→0x3f26b0
 * 调用序列: 无
 * 字段偏移 top8: 0xc×4 / 0x9c×2 / 0x64×2 / 0x98×1 / 0x74×1 / 0x60×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17b048 push {r4, r5, r6, lr}
 *   @0x17b04c sub sp, sp, #8
 *   @0x17b050 ldr r5, [pc, #0x9c]
 *   @0x17b054 ldr r3, [pc, #0x9c]
 *   @0x17b058 add r5, pc, r5
 *   @0x17b05c ldr r6, [pc, #0x98]
 *   @0x17b060 ldr r3, [r5, r3]
 *   @0x17b064 add r6, pc, r6
 *   @0x17b068 mov r1, r6
 *   @0x17b06c ldr r4, [r3]
 *   @0x17b070 ldr r3, [r4]
 *   @0x17b074 mov r0, r4
 *   @0x17b078 ldr r3, [r3, #0xc]
 *   @0x17b07c blx r3
 *   @0x17b080 ldr r3, [r4]
 *   @0x17b084 ldr r1, [pc, #0x74]
 *   @0x17b088 mov r0, r4
 *   @0x17b08c add r1, pc, r1
 *   @0x17b090 ldr r3, [r3, #0xc]
 *   @0x17b094 blx r3
 *   @0x17b098 ldr r1, [pc, #0x64]
 *   @0x17b09c ldr r2, [pc, #0x64]
 *   @0x17b0a0 mov r0, r4
 *   @0x17b0a4 ldr r3, [pc, #0x60]
 *   @0x17b0a8 ldr r12, [r5, r1]
 *   @0x17b0ac ldr r2, [r5, r2]
 *   @0x17b0b0 ldr r1, [r4]
 *   @0x17b0b4 ldr r3, [r5, r3]
 *   @0x17b0b8 ldr r12, [r12]
 *   @0x17b0bc ldr r2, [r2]
 *   @0x17b0c0 ldr r3, [r3]
 *   @0x17b0c4 str r12, [sp]
 *   @0x17b0c8 ldr r12, [r1, #0xc]
 *   @0x17b0cc ldr r1, [pc, #0x3c]
 *   @0x17b0d0 add r1, pc, r1
 *   @0x17b0d4 blx r12
 *   @0x17b0d8 ldr r3, [r4]
 *   @0x17b0dc mov r1, r6
 *   @0x17b0e0 mov r0, r4
 *   @0x17b0e4 ldr r3, [r3, #0xc]
 *   @0x17b0e8 blx r3
 *   @0x17b0ec add sp, sp, #8
 *   @0x17b0f0 pop {r4, r5, r6, pc}
 *   @0x17b0f4 .word 0x00276bf8
 *   @0x17b0f8 .word 0xffffbac4
 *   @0x17b0fc andseq r0, sp, r12, lsr #10
 *   @0x17b100 andseq r0, sp, r8, asr #10
 *   @0x17b104 .word 0xffffe6e8
 *   @0x17b108 .word 0xffffe6ec
 *   @0x17b10c .word 0xffffe6f0
 *   @0x17b110 andseq r0, sp, r12, lsl r5
 *
 * ══ §115/146 cARRAY_CLASS<CRoom*>::~cARRAY_CLASS()  0x1b4af8  size 204  51 条（0x1b4af8..0x1b4bc4）
 * @func 0x1b4af8 0x1b4bc4  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / cARRAY_CLASS<CRoom*>::~cARRAY_CLASS()+0x9c / CRoom::~CRoom() / operator delete(void*) / cARRAY_CLASS<CRoom*>::~cARRAY_CLASS()+0x30
 * 字段偏移 top8: 0x4×5 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b4af8 ldr r12, [r0]
 *   @0x1b4afc push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x1b4b00 cmp r12, #0
 *   @0x1b4b04 mov r7, r0
 *   @0x1b4b08 beq 0x1b4bac <_ZN12cARRAY_CLASSIP5CRoomED2Ev+0xb4>
 *   @0x1b4b0c ldr r5, [r0, #0x4]
 *   @0x1b4b10 cmp r5, #0
 *   @0x1b4b14 beq 0x1b4bb4 <_ZN12cARRAY_CLASSIP5CRoomED2Ev+0xbc>
 *   @0x1b4b18 cmp r12, #0
 *   @0x1b4b1c ble 0x1b4b94 <_ZN12cARRAY_CLASSIP5CRoomED2Ev+0x9c>
 *   @0x1b4b20 mov r4, #0
 *   @0x1b4b24 mov r9, r4
 *   @0x1b4b28 ldr r1, [r5]
 *   @0x1b4b2c movw r3, #0xfeee
 *   @0x1b4b30 movt r3, #0xfeee
 *   @0x1b4b34 movw r2, #0xfeee
 *   @0x1b4b38 cmp r1, r3
 *   @0x1b4b3c movt r2, #0xfeee
 *   @0x1b4b40 lsl r8, r4, #2
 *   @0x1b4b44 beq 0x1b4b88 <_ZN12cARRAY_CLASSIP5CRoomED2Ev+0x90>
 *   @0x1b4b48 ldr r6, [r5, r4, lsl #2]
 *   @0x1b4b4c add r3, r5, r8
 *   @0x1b4b50 cmp r6, #0
 *   @0x1b4b54 mov r0, r6
 *   @0x1b4b58 beq 0x1b4b88 <_ZN12cARRAY_CLASSIP5CRoomED2Ev+0x90>
 *   @0x1b4b5c ldr r1, [r6]
 *   @0x1b4b60 cmp r1, r2
 *   @0x1b4b64 beq 0x1b4b80 <_ZN12cARRAY_CLASSIP5CRoomED2Ev+0x88>
 *   @0x1b4b68 bl 0x1afa00 <_ZN5CRoomD2Ev>
 *   @0x1b4b6c mov r0, r6
 *   @0x1b4b70 bl 0x27d1d0 <_ZdlPv>
 *   @0x1b4b74 ldr r3, [r7, #0x4]
 *   @0x1b4b78 ldr r12, [r7]
 *   @0x1b4b7c add r3, r3, r8
 *   @0x1b4b80 str r9, [r3]
 *   @0x1b4b84 ldr r5, [r7, #0x4]
 *   @0x1b4b88 add r4, r4, #1
 *   @0x1b4b8c cmp r4, r12
 *   @0x1b4b90 blt 0x1b4b28 <_ZN12cARRAY_CLASSIP5CRoomED2Ev+0x30>
 *   @0x1b4b94 mov r0, r5
 *   @0x1b4b98 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b4b9c mov r3, #0
 *   @0x1b4ba0 str r3, [r7, #0x4]
 *   @0x1b4ba4 mov r3, #0
 *   @0x1b4ba8 str r3, [r7]
 *   @0x1b4bac mov r0, r7
 *   @0x1b4bb0 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1b4bb4 mov r0, r5
 *   @0x1b4bb8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1b4bbc str r5, [r7, #0x4]
 *   @0x1b4bc0 b 0x1b4ba4 <_ZN12cARRAY_CLASSIP5CRoomED2Ev+0xac>
 *
 * ══ §116/146 F_LayerBackgroundGetID(RValue&, CInstance*, CInstance*, int, RValue*)  0x1c0544  size 204  51 条（0x1c0544..0x1c0610）
 * @func 0x1c0544 0x1c0610  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetLayerFromID(CRoom*, int) / CLayerManager::GetElementFromName(CLayer*, char const*) / YYGetString(RValue const*, int) / CLayerManager::GetLayerFromName(CRoom*, char const*)
 * 字段偏移 top8: 0xc×2 / 0x4×2 / 0x18×1 / 0x94×1 / 0x1c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c0544 cmp r3, #1
 *   @0x1c0548 push {r3, r4, r5, r6, r7, lr}
 *   @0x1c054c mov r3, #0
 *   @0x1c0550 mov r5, r3
 *   @0x1c0554 mov r4, r0
 *   @0x1c0558 movt r3, #0xbff0
 *   @0x1c055c str r5, [r0, #0xc]
 *   @0x1c0560 str r3, [r0, #0x4]
 *   @0x1c0564 str r5, [r0]
 *   @0x1c0568 ldr r6, [sp, #0x18]
 *   @0x1c056c beq 0x1c0584 <_Z22F_LayerBackgroundGetIDR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1c0570 ldr r0, [pc, #0x94]
 *   @0x1c0574 mov r1, r5
 *   @0x1c0578 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1c057c add r0, pc, r0
 *   @0x1c0580 b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1c0584 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1c0588 ldr r3, [r6, #0xc]
 *   @0x1c058c mov r1, r5
 *   @0x1c0590 bic r3, r3, #-16777216
 *   @0x1c0594 cmp r3, #1
 *   @0x1c0598 mov r7, r0
 *   @0x1c059c mov r0, r6
 *   @0x1c05a0 beq 0x1c05f0 <_Z22F_LayerBackgroundGetIDR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x1c05a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1c05a8 mov r1, r0
 *   @0x1c05ac mov r0, r7
 *   @0x1c05b0 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1c05b4 cmp r0, #0
 *   @0x1c05b8 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1c05bc ldr r1, [r0, #0x1c]
 *   @0x1c05c0 bl 0x1c048c <_ZN13CLayerManager18GetElementFromNameEP6CLayerPKc>
 *   @0x1c05c4 cmp r0, #0
 *   @0x1c05c8 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1c05cc ldr r3, [r0]
 *   @0x1c05d0 cmp r3, #1
 *   @0x1c05d4 popne {r3, r4, r5, r6, r7, pc}
 *   @0x1c05d8 ldr r2, [r0, #0x4]
 *   @0x1c05dc vmov s15, r2
 *   @0x1c05e0 vcvt.f64.s32 d7, s15
 *   @0x1c05e4 vmov r2, r3, d7
 *   @0x1c05e8 stm r4, {r2, r3}
 *   @0x1c05ec pop {r3, r4, r5, r6, r7, pc}
 *   @0x1c05f0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1c05f4 mov r1, r0
 *   @0x1c05f8 mov r0, r7
 *   @0x1c05fc bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc>
 *   @0x1c0600 cmp r0, #0
 *   @0x1c0604 bne 0x1c05bc <_Z22F_LayerBackgroundGetIDR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x1c0608 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1c060c andseq pc, r8, r8, lsl #6
 *
 * ══ §117/146 SingleStep()  0x1d4dd8  size 204  51 条（0x1d4dd8..0x1d4ea4）
 * @func 0x1d4dd8 0x1d4ea4  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ProcessMessages() / DoAStep() / LoadGame() / SwitchRoom(int) / GR_D3D_Finish_Frame(bool) / GR_D3D_Start_Frame() / Run_EndGame() / GamePadRestart()
 * 字段偏移 top8: 0xb0×1 / 0x58×1 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d4dd8 push {r4, lr}
 *   @0x1d4ddc bl 0x28fe64 <_Z15ProcessMessagesv>
 *   @0x1d4de0 ldr r4, [pc, #0xb0]
 *   @0x1d4de4 bl 0x1d32c0 <_Z7DoAStepv>
 *   @0x1d4de8 ldr r4, [pc, r4]
 *   @0x1d4dec ldr r0, [r4]
 *   @0x1d4df0 cmn r0, #1
 *   @0x1d4df4 beq 0x1d4e50 <_Z10SingleStepv+0x78>
 *   @0x1d4df8 cmn r0, #200
 *   @0x1d4dfc beq 0x1d4e78 <_Z10SingleStepv+0xa0>
 *   @0x1d4e00 bgt 0x1d4e20 <_Z10SingleStepv+0x48>
 *   @0x1d4e04 cmn r0, #400
 *   @0x1d4e08 beq 0x1d4e3c <_Z10SingleStepv+0x64>
 *   @0x1d4e0c cmn r0, #300
 *   @0x1d4e10 bne 0x1d4e30 <_Z10SingleStepv+0x58>
 *   @0x1d4e14 bl 0x1d1cb4 <_Z8LoadGamev>
 *   @0x1d4e18 pop {r4, lr}
 *   @0x1d4e1c b 0x28fe64 <_Z15ProcessMessagesv>
 *   @0x1d4e20 cmn r0, #100
 *   @0x1d4e24 beq 0x1d4e3c <_Z10SingleStepv+0x64>
 *   @0x1d4e28 cmn r0, #1
 *   @0x1d4e2c beq 0x1d4e18 <_Z10SingleStepv+0x40>
 *   @0x1d4e30 bl 0x1d4450 <_Z10SwitchRoomi>
 *   @0x1d4e34 pop {r4, lr}
 *   @0x1d4e38 b 0x28fe64 <_Z15ProcessMessagesv>
 *   @0x1d4e3c ldr r3, [pc, #0x58]
 *   @0x1d4e40 mov r2, #0
 *   @0x1d4e44 ldr r3, [pc, r3]
 *   @0x1d4e48 strb r2, [r3]
 *   @0x1d4e4c pop {r4, pc}
 *   @0x1d4e50 ldr r3, [pc, #0x48]
 *   @0x1d4e54 ldr r3, [pc, r3]
 *   @0x1d4e58 ldrb r3, [r3]
 *   @0x1d4e5c cmp r3, #0
 *   @0x1d4e60 beq 0x1d4e18 <_Z10SingleStepv+0x40>
 *   @0x1d4e64 mov r0, #1
 *   @0x1d4e68 bl 0x169a58 <_Z19GR_D3D_Finish_Frameb>
 *   @0x1d4e6c bl 0x1699c0 <_Z18GR_D3D_Start_Framev>
 *   @0x1d4e70 ldr r0, [r4]
 *   @0x1d4e74 b 0x1d4df8 <_Z10SingleStepv+0x20>
 *   @0x1d4e78 bl 0x1d1b38 <_Z11Run_EndGamev>
 *   @0x1d4e7c bl 0x18e58c <_Z14GamePadRestartv>
 *   @0x1d4e80 bl 0x1d44fc <_Z9StartGamev>
 *   @0x1d4e84 movw r0, #0x12e4
 *   @0x1d4e88 movt r0, #0x20
 *   @0x1d4e8c bl 0xb69c4 <srand48@plt>
 *   @0x1d4e90 pop {r4, lr}
 *   @0x1d4e94 b 0x28fe64 <_Z15ProcessMessagesv>
 *   @0x1d4e98 .word 0x00218fbc
 *   @0x1d4e9c eoreq r11, r1, r8, asr #25
 *   @0x1d4ea0 eoreq r9, r1, r0, ror r7
 *
 * ══ §118/146 Script_Free()  0x1e0464  size 204  51 条（0x1e0464..0x1e0530）
 * @func 0x1e0464 0x1e0530  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1e046c→0x544c68, 0x1e0474→0x544c70, 0x1e0488→0x544c6c, 0x1e050c→0x544c6c
 * 调用序列: MemoryManager::Free(void const*)×3 / Script_Free()+0xa8 / CScript::Free()
 * 字段偏移 top8: 0x4×4 / 0xb0×2 / 0x2×2 / 0xac×1 / 0x9c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e0464 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x1e0468 ldr r3, [pc, #0xb0]
 *   @0x1e046c ldr r2, [pc, #0xb0]
 *   @0x1e0470 add r3, pc, r3
 *   @0x1e0474 ldr r1, [pc, #0xac]
 *   @0x1e0478 ldr r6, [r3, r2]
 *   @0x1e047c ldr r2, [r6]
 *   @0x1e0480 cmp r2, #0
 *   @0x1e0484 ble 0x1e050c <_Z11Script_Freev+0xa8>
 *   @0x1e0488 ldr r2, [pc, #0x9c]
 *   @0x1e048c mov r4, #0
 *   @0x1e0490 ldr r7, [r3, r1]
 *   @0x1e0494 mov r8, r4
 *   @0x1e0498 ldr r5, [r3, r2]
 *   @0x1e049c ldr r2, [r7, #0x4]
 *   @0x1e04a0 ldr r0, [r2, r4, lsl #2]
 *   @0x1e04a4 lsl r9, r4, #2
 *   @0x1e04a8 cmp r0, #0
 *   @0x1e04ac beq 0x1e04d4 <_Z11Script_Freev+0x70>
 *   @0x1e04b0 bl 0x1dfb8c <_ZN7CScript4FreeEv>
 *   @0x1e04b4 ldr r3, [r5]
 *   @0x1e04b8 ldr r0, [r3, r4, lsl #2]
 *   @0x1e04bc cmp r0, #0
 *   @0x1e04c0 beq 0x1e04d0 <_Z11Script_Freev+0x6c>
 *   @0x1e04c4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e04c8 ldr r3, [r5]
 *   @0x1e04cc str r8, [r3, r9]
 *   @0x1e04d0 ldr r2, [r7, #0x4]
 *   @0x1e04d4 ldr r3, [r6]
 *   @0x1e04d8 add r4, r4, #1
 *   @0x1e04dc cmp r3, r4
 *   @0x1e04e0 bgt 0x1e04a0 <_Z11Script_Freev+0x3c>
 *   @0x1e04e4 mov r0, r2
 *   @0x1e04e8 mov r4, #0
 *   @0x1e04ec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e04f0 ldr r0, [r5]
 *   @0x1e04f4 str r4, [r7, #0x4]
 *   @0x1e04f8 str r4, [r7]
 *   @0x1e04fc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e0500 str r4, [r6]
 *   @0x1e0504 str r4, [r5]
 *   @0x1e0508 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1e050c ldr r2, [pc, #0x18]
 *   @0x1e0510 ldr r7, [r3, r1]
 *   @0x1e0514 ldr r5, [r3, r2]
 *   @0x1e0518 ldr r2, [r7, #0x4]
 *   @0x1e051c b 0x1e04e4 <_Z11Script_Freev+0x80>
 *   @0x1e0520 eoreq r1, r1, r0, ror #15
 *   @0x1e0524 .word 0xfffff0dc
 *   @0x1e0528 .word 0xfffff0d8
 *   @0x1e052c .word 0xfffff0e0
 *
 * ══ §119/146 CVariableList::GetVar(int, int, RValue*)  0x1f5428  size 204  51 条（0x1f5428..0x1f54f4）
 * @func 0x1f5428 0x1f54f4  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2 / 0x8×2 / 0xc×2 / 0xac×1 / 0xa8×1 / 0x64×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f5428 and r12, r1, #3
 *   @0x1f542c push {r4, r5, r6}
 *   @0x1f5430 add r0, r0, r12, lsl #2
 *   @0x1f5434 ldr r4, [pc, #0xac]
 *   @0x1f5438 mov r6, #0
 *   @0x1f543c ldr r5, [pc, #0xa8]
 *   @0x1f5440 ldr r12, [r0, #0x4]
 *   @0x1f5444 ldr r4, [pc, r4]
 *   @0x1f5448 ldr r5, [pc, r5]
 *   @0x1f544c cmp r12, r6
 *   @0x1f5450 strb r6, [r4]
 *   @0x1f5454 strb r6, [r5]
 *   @0x1f5458 beq 0x1f5484 <_ZN13CVariableList6GetVarEiiP6RValue+0x5c>
 *   @0x1f545c ldr r0, [r12, #0x8]
 *   @0x1f5460 cmp r0, r1
 *   @0x1f5464 bne 0x1f5478 <_ZN13CVariableList6GetVarEiiP6RValue+0x50>
 *   @0x1f5468 b 0x1f54c0 <_ZN13CVariableList6GetVarEiiP6RValue+0x98>
 *   @0x1f546c ldr r4, [r12, #0x8]
 *   @0x1f5470 cmp r4, r1
 *   @0x1f5474 beq 0x1f54c0 <_ZN13CVariableList6GetVarEiiP6RValue+0x98>
 *   @0x1f5478 ldr r12, [r12]
 *   @0x1f547c cmp r12, #0
 *   @0x1f5480 bne 0x1f546c <_ZN13CVariableList6GetVarEiiP6RValue+0x44>
 *   @0x1f5484 ldr r2, [pc, #0x64]
 *   @0x1f5488 ldr r2, [pc, r2]
 *   @0x1f548c ldrb r2, [r2]
 *   @0x1f5490 cmp r2, #0
 *   @0x1f5494 beq 0x1f54d0 <_ZN13CVariableList6GetVarEiiP6RValue+0xa8>
 *   @0x1f5498 mov r2, #0
 *   @0x1f549c movw r0, #0xcccd
 *   @0x1f54a0 movw r1, #0x8c29
 *   @0x1f54a4 movt r0, #0xdccc
 *   @0x1f54a8 movt r1, #0x4167
 *   @0x1f54ac str r2, [r3, #0xc]
 *   @0x1f54b0 stm r3, {r0, r1}
 *   @0x1f54b4 mov r0, r2
 *   @0x1f54b8 pop {r4, r5, r6}
 *   @0x1f54bc bx lr
 *   @0x1f54c0 mov r0, r3
 *   @0x1f54c4 add r1, r12, #24
 *   @0x1f54c8 pop {r4, r5, r6}
 *   @0x1f54cc b 0xd13bc <_Z10GET_RValueP6RValueS0_i>
 *   @0x1f54d0 mov r0, #1
 *   @0x1f54d4 str r2, [r3, #0xc]
 *   @0x1f54d8 str r2, [r3]
 *   @0x1f54dc str r2, [r3, #0x4]
 *   @0x1f54e0 pop {r4, r5, r6}
 *   @0x1f54e4 bx lr
 *   @0x1f54e8 andseq r8, pc, r0, lsr r7
 *   @0x1f54ec andseq r8, pc, r8, lsl r9
 *   @0x1f54f0 andseq r11, pc, r8, asr #5
 *
 * ══ §120/146 cARRAY_CLASS<CEmitter*>::~cARRAY_CLASS()  0x215d50  size 204  51 条（0x215d50..0x215e1c）
 * @func 0x215d50 0x215e1c  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / cARRAY_CLASS<CEmitter*>::~cARRAY_CLASS()+0x9c / CEmitter::~CEmitter() / operator delete(void*) / cARRAY_CLASS<CEmitter*>::~cARRAY_CLASS()+0x30
 * 字段偏移 top8: 0x4×5 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x215d50 ldr r12, [r0]
 *   @0x215d54 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x215d58 cmp r12, #0
 *   @0x215d5c mov r7, r0
 *   @0x215d60 beq 0x215e04 <_ZN12cARRAY_CLASSIP8CEmitterED2Ev+0xb4>
 *   @0x215d64 ldr r5, [r0, #0x4]
 *   @0x215d68 cmp r5, #0
 *   @0x215d6c beq 0x215e0c <_ZN12cARRAY_CLASSIP8CEmitterED2Ev+0xbc>
 *   @0x215d70 cmp r12, #0
 *   @0x215d74 ble 0x215dec <_ZN12cARRAY_CLASSIP8CEmitterED2Ev+0x9c>
 *   @0x215d78 mov r4, #0
 *   @0x215d7c mov r9, r4
 *   @0x215d80 ldr r1, [r5]
 *   @0x215d84 movw r3, #0xfeee
 *   @0x215d88 movt r3, #0xfeee
 *   @0x215d8c movw r2, #0xfeee
 *   @0x215d90 cmp r1, r3
 *   @0x215d94 movt r2, #0xfeee
 *   @0x215d98 lsl r8, r4, #2
 *   @0x215d9c beq 0x215de0 <_ZN12cARRAY_CLASSIP8CEmitterED2Ev+0x90>
 *   @0x215da0 ldr r6, [r5, r4, lsl #2]
 *   @0x215da4 add r3, r5, r8
 *   @0x215da8 cmp r6, #0
 *   @0x215dac mov r0, r6
 *   @0x215db0 beq 0x215de0 <_ZN12cARRAY_CLASSIP8CEmitterED2Ev+0x90>
 *   @0x215db4 ldr r1, [r6]
 *   @0x215db8 cmp r1, r2
 *   @0x215dbc beq 0x215dd8 <_ZN12cARRAY_CLASSIP8CEmitterED2Ev+0x88>
 *   @0x215dc0 bl 0x21580c <_ZN8CEmitterD2Ev>
 *   @0x215dc4 mov r0, r6
 *   @0x215dc8 bl 0x27d1d0 <_ZdlPv>
 *   @0x215dcc ldr r3, [r7, #0x4]
 *   @0x215dd0 ldr r12, [r7]
 *   @0x215dd4 add r3, r3, r8
 *   @0x215dd8 str r9, [r3]
 *   @0x215ddc ldr r5, [r7, #0x4]
 *   @0x215de0 add r4, r4, #1
 *   @0x215de4 cmp r4, r12
 *   @0x215de8 blt 0x215d80 <_ZN12cARRAY_CLASSIP8CEmitterED2Ev+0x30>
 *   @0x215dec mov r0, r5
 *   @0x215df0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x215df4 mov r3, #0
 *   @0x215df8 str r3, [r7, #0x4]
 *   @0x215dfc mov r3, #0
 *   @0x215e00 str r3, [r7]
 *   @0x215e04 mov r0, r7
 *   @0x215e08 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x215e0c mov r0, r5
 *   @0x215e10 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x215e14 str r5, [r7, #0x4]
 *   @0x215e18 b 0x215dfc <_ZN12cARRAY_CLASSIP8CEmitterED2Ev+0xac>
 *
 * ══ §121/146 cARRAY_CLASS<CNoise*>::~cARRAY_CLASS()  0x215ef4  size 204  51 条（0x215ef4..0x215fc0）
 * @func 0x215ef4 0x215fc0  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / cARRAY_CLASS<CNoise*>::~cARRAY_CLASS()+0x9c / CNoise::~CNoise() / operator delete(void*) / cARRAY_CLASS<CNoise*>::~cARRAY_CLASS()+0x30
 * 字段偏移 top8: 0x4×5 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x215ef4 ldr r12, [r0]
 *   @0x215ef8 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x215efc cmp r12, #0
 *   @0x215f00 mov r7, r0
 *   @0x215f04 beq 0x215fa8 <_ZN12cARRAY_CLASSIP6CNoiseED2Ev+0xb4>
 *   @0x215f08 ldr r5, [r0, #0x4]
 *   @0x215f0c cmp r5, #0
 *   @0x215f10 beq 0x215fb0 <_ZN12cARRAY_CLASSIP6CNoiseED2Ev+0xbc>
 *   @0x215f14 cmp r12, #0
 *   @0x215f18 ble 0x215f90 <_ZN12cARRAY_CLASSIP6CNoiseED2Ev+0x9c>
 *   @0x215f1c mov r4, #0
 *   @0x215f20 mov r9, r4
 *   @0x215f24 ldr r1, [r5]
 *   @0x215f28 movw r3, #0xfeee
 *   @0x215f2c movt r3, #0xfeee
 *   @0x215f30 movw r2, #0xfeee
 *   @0x215f34 cmp r1, r3
 *   @0x215f38 movt r2, #0xfeee
 *   @0x215f3c lsl r8, r4, #2
 *   @0x215f40 beq 0x215f84 <_ZN12cARRAY_CLASSIP6CNoiseED2Ev+0x90>
 *   @0x215f44 ldr r6, [r5, r4, lsl #2]
 *   @0x215f48 add r3, r5, r8
 *   @0x215f4c cmp r6, #0
 *   @0x215f50 mov r0, r6
 *   @0x215f54 beq 0x215f84 <_ZN12cARRAY_CLASSIP6CNoiseED2Ev+0x90>
 *   @0x215f58 ldr r1, [r6]
 *   @0x215f5c cmp r1, r2
 *   @0x215f60 beq 0x215f7c <_ZN12cARRAY_CLASSIP6CNoiseED2Ev+0x88>
 *   @0x215f64 bl 0x21db28 <_ZN6CNoiseD2Ev>
 *   @0x215f68 mov r0, r6
 *   @0x215f6c bl 0x27d1d0 <_ZdlPv>
 *   @0x215f70 ldr r3, [r7, #0x4]
 *   @0x215f74 ldr r12, [r7]
 *   @0x215f78 add r3, r3, r8
 *   @0x215f7c str r9, [r3]
 *   @0x215f80 ldr r5, [r7, #0x4]
 *   @0x215f84 add r4, r4, #1
 *   @0x215f88 cmp r4, r12
 *   @0x215f8c blt 0x215f24 <_ZN12cARRAY_CLASSIP6CNoiseED2Ev+0x30>
 *   @0x215f90 mov r0, r5
 *   @0x215f94 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x215f98 mov r3, #0
 *   @0x215f9c str r3, [r7, #0x4]
 *   @0x215fa0 mov r3, #0
 *   @0x215fa4 str r3, [r7]
 *   @0x215fa8 mov r0, r7
 *   @0x215fac pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x215fb0 mov r0, r5
 *   @0x215fb4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x215fb8 str r5, [r7, #0x4]
 *   @0x215fbc b 0x215fa0 <_ZN12cARRAY_CLASSIP6CNoiseED2Ev+0xac>
 *
 * ══ §122/146 cARRAY_CLASS<cAudio_Sound*>::~cARRAY_CLASS()  0x218f7c  size 204  51 条（0x218f7c..0x219048）
 * @func 0x218f7c 0x219048  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / cARRAY_CLASS<cAudio_Sound*>::~cARRAY_CLASS()+0x9c / cAudio_Sound::~cAudio_Sound() / operator delete(void*) / cARRAY_CLASS<cAudio_Sound*>::~cARRAY_CLASS()+0x30
 * 字段偏移 top8: 0x4×5 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x218f7c ldr r12, [r0]
 *   @0x218f80 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x218f84 cmp r12, #0
 *   @0x218f88 mov r7, r0
 *   @0x218f8c beq 0x219030 <_ZN12cARRAY_CLASSIP12cAudio_SoundED2Ev+0xb4>
 *   @0x218f90 ldr r5, [r0, #0x4]
 *   @0x218f94 cmp r5, #0
 *   @0x218f98 beq 0x219038 <_ZN12cARRAY_CLASSIP12cAudio_SoundED2Ev+0xbc>
 *   @0x218f9c cmp r12, #0
 *   @0x218fa0 ble 0x219018 <_ZN12cARRAY_CLASSIP12cAudio_SoundED2Ev+0x9c>
 *   @0x218fa4 mov r4, #0
 *   @0x218fa8 mov r9, r4
 *   @0x218fac ldr r1, [r5]
 *   @0x218fb0 movw r3, #0xfeee
 *   @0x218fb4 movt r3, #0xfeee
 *   @0x218fb8 movw r2, #0xfeee
 *   @0x218fbc cmp r1, r3
 *   @0x218fc0 movt r2, #0xfeee
 *   @0x218fc4 lsl r8, r4, #2
 *   @0x218fc8 beq 0x21900c <_ZN12cARRAY_CLASSIP12cAudio_SoundED2Ev+0x90>
 *   @0x218fcc ldr r6, [r5, r4, lsl #2]
 *   @0x218fd0 add r3, r5, r8
 *   @0x218fd4 cmp r6, #0
 *   @0x218fd8 mov r0, r6
 *   @0x218fdc beq 0x21900c <_ZN12cARRAY_CLASSIP12cAudio_SoundED2Ev+0x90>
 *   @0x218fe0 ldr r1, [r6]
 *   @0x218fe4 cmp r1, r2
 *   @0x218fe8 beq 0x219004 <_ZN12cARRAY_CLASSIP12cAudio_SoundED2Ev+0x88>
 *   @0x218fec bl 0x218f24 <_ZN12cAudio_SoundD2Ev>
 *   @0x218ff0 mov r0, r6
 *   @0x218ff4 bl 0x27d1d0 <_ZdlPv>
 *   @0x218ff8 ldr r3, [r7, #0x4]
 *   @0x218ffc ldr r12, [r7]
 *   @0x219000 add r3, r3, r8
 *   @0x219004 str r9, [r3]
 *   @0x219008 ldr r5, [r7, #0x4]
 *   @0x21900c add r4, r4, #1
 *   @0x219010 cmp r4, r12
 *   @0x219014 blt 0x218fac <_ZN12cARRAY_CLASSIP12cAudio_SoundED2Ev+0x30>
 *   @0x219018 mov r0, r5
 *   @0x21901c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x219020 mov r3, #0
 *   @0x219024 str r3, [r7, #0x4]
 *   @0x219028 mov r3, #0
 *   @0x21902c str r3, [r7]
 *   @0x219030 mov r0, r7
 *   @0x219034 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x219038 mov r0, r5
 *   @0x21903c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x219040 str r5, [r7, #0x4]
 *   @0x219044 b 0x219028 <_ZN12cARRAY_CLASSIP12cAudio_SoundED2Ev+0xac>
 *
 * ══ §123/146 SND_Stop(char const*, int)  0x21ecf4  size 204  44 条（0x21ecf4..0x21edc0）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x21ecf4 0x21edc8  size 212  46 条
 * 部分覆盖: 本节 46/53 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 45/52 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x21ed04→0x755363, 0x21ed1c→0x755330, 0x21ed50→0x755334, 0x21ed64→0x755338
 * 调用序列: 0xb6574 / SoundHardware::StopMusic()
 * 字段偏移 top8: 0xa0×1 / 0x9c×1 / 0x88×1 / 0x58×1 / 0x48×1 / 0x44×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21ecf4 push {r3, r4, r5, r6, r7, lr}
 *   @0x21ecf8 mov r2, r0
 *   @0x21ed18 popne {r3, r4, r5, r6, r7, pc}
 *   @0x21ed1c ldr r3, [pc, #0x88]
 *   @0x21ed20 ldr r6, [r4, r3]
 *   @0x21ed24 ldr r0, [r6]
 *   @0x21ed28 cmp r0, #0
 *   @0x21ed2c beq 0x21ed48 <_Z8SND_StopPKci+0x54>
 *   @0x21ed30 cmp r2, #0
 *   @0x21ed34 beq 0x21ed48 <_Z8SND_StopPKci+0x54>
 *   @0x21ed38 mov r1, r2
 *   @0x21ed3c bl 0xb6574 <strcmp@plt>
 *   @0x21ed40 subs r7, r0, #0
 *   @0x21ed44 beq 0x21ed90 <_Z8SND_StopPKci+0x9c>
 *   @0x21ed48 cmp r5, #0
 *   @0x21ed4c poplt {r3, r4, r5, r6, r7, pc}
 *   @0x21ed50 ldr r3, [pc, #0x58]
 *   @0x21ed54 ldr r3, [r4, r3]
 *   @0x21ed58 ldr r3, [r3]
 *   @0x21ed5c cmp r5, r3
 *   @0x21ed60 popge {r3, r4, r5, r6, r7, pc}
 *   @0x21ed64 ldr r3, [pc, #0x48]
 *   @0x21ed68 add r5, r5, r5, lsl #2
 *   @0x21ed6c ldr r2, [pc, #0x44]
 *   @0x21ed70 ldr r3, [r4, r3]
 *   @0x21ed74 add r2, pc, r2
 *   @0x21ed78 ldr r0, [r2]
 *   @0x21ed7c ldr r3, [r3, #0x4]
 *   @0x21ed80 add r5, r3, r5, lsl #2
 *   @0x21ed84 ldr r1, [r5, #0x8]
 *   @0x21ed88 pop {r3, r4, r5, r6, r7, lr}
 *   @0x21ed8c b 0x220d90 <_ZN13SoundHardware4StopEPv>
 *   @0x21ed90 ldr r3, [pc, #0x24]
 *   @0x21ed94 ldr r0, [pc, r3]
 *   @0x21ed98 bl 0x220950 <_ZN13SoundHardware9StopMusicEv>
 *   @0x21ed9c str r7, [r6]
 *   @0x21eda0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x21eda4 andseq r2, sp, r8, asr #30
 *   @0x21eda8 .word 0xffffd3fc
 *   @0x21edac .word 0xfffff7cc
 *   @0x21edb0 .word 0xfffff7c4
 *   @0x21edb4 .word 0xfffff7c8
 *   @0x21edb8 ldrheq r6, [r3], #-80
 *   @0x21edbc .word 0x00536590
 *
 * ══ §124/146 cARRAY_CLASS<CSound*>::~cARRAY_CLASS()  0x21f218  size 204  51 条（0x21f218..0x21f2e4）
 * @func 0x21f218 0x21f2e4  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / cARRAY_CLASS<CSound*>::~cARRAY_CLASS()+0x9c / CSound::~CSound() / operator delete(void*) / cARRAY_CLASS<CSound*>::~cARRAY_CLASS()+0x30
 * 字段偏移 top8: 0x4×5 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21f218 ldr r12, [r0]
 *   @0x21f21c push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x21f220 cmp r12, #0
 *   @0x21f224 mov r7, r0
 *   @0x21f228 beq 0x21f2cc <_ZN12cARRAY_CLASSIP6CSoundED2Ev+0xb4>
 *   @0x21f22c ldr r5, [r0, #0x4]
 *   @0x21f230 cmp r5, #0
 *   @0x21f234 beq 0x21f2d4 <_ZN12cARRAY_CLASSIP6CSoundED2Ev+0xbc>
 *   @0x21f238 cmp r12, #0
 *   @0x21f23c ble 0x21f2b4 <_ZN12cARRAY_CLASSIP6CSoundED2Ev+0x9c>
 *   @0x21f240 mov r4, #0
 *   @0x21f244 mov r9, r4
 *   @0x21f248 ldr r1, [r5]
 *   @0x21f24c movw r3, #0xfeee
 *   @0x21f250 movt r3, #0xfeee
 *   @0x21f254 movw r2, #0xfeee
 *   @0x21f258 cmp r1, r3
 *   @0x21f25c movt r2, #0xfeee
 *   @0x21f260 lsl r8, r4, #2
 *   @0x21f264 beq 0x21f2a8 <_ZN12cARRAY_CLASSIP6CSoundED2Ev+0x90>
 *   @0x21f268 ldr r6, [r5, r4, lsl #2]
 *   @0x21f26c add r3, r5, r8
 *   @0x21f270 cmp r6, #0
 *   @0x21f274 mov r0, r6
 *   @0x21f278 beq 0x21f2a8 <_ZN12cARRAY_CLASSIP6CSoundED2Ev+0x90>
 *   @0x21f27c ldr r1, [r6]
 *   @0x21f280 cmp r1, r2
 *   @0x21f284 beq 0x21f2a0 <_ZN12cARRAY_CLASSIP6CSoundED2Ev+0x88>
 *   @0x21f288 bl 0x215384 <_ZN6CSoundD2Ev>
 *   @0x21f28c mov r0, r6
 *   @0x21f290 bl 0x27d1d0 <_ZdlPv>
 *   @0x21f294 ldr r3, [r7, #0x4]
 *   @0x21f298 ldr r12, [r7]
 *   @0x21f29c add r3, r3, r8
 *   @0x21f2a0 str r9, [r3]
 *   @0x21f2a4 ldr r5, [r7, #0x4]
 *   @0x21f2a8 add r4, r4, #1
 *   @0x21f2ac cmp r4, r12
 *   @0x21f2b0 blt 0x21f248 <_ZN12cARRAY_CLASSIP6CSoundED2Ev+0x30>
 *   @0x21f2b4 mov r0, r5
 *   @0x21f2b8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21f2bc mov r3, #0
 *   @0x21f2c0 str r3, [r7, #0x4]
 *   @0x21f2c4 mov r3, #0
 *   @0x21f2c8 str r3, [r7]
 *   @0x21f2cc mov r0, r7
 *   @0x21f2d0 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x21f2d4 mov r0, r5
 *   @0x21f2d8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21f2dc str r5, [r7, #0x4]
 *   @0x21f2e0 b 0x21f2c4 <_ZN12cARRAY_CLASSIP6CSoundED2Ev+0xac>
 *
 * ══ §125/146 _alutCodecULaw  0x22157c  size 204  51 条（0x22157c..0x221648）
 * @func 0x22157c 0x221658  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _alutMalloc / 0xb655c
 * 字段偏移 top8: 0x84×1 / 0x1×1 / 0x2×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22157c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x221580 vpush {d8}
 *   @0x221584 lsl r6, r1, #1
 *   @0x221588 sub sp, sp, #4
 *   @0x22158c mov r9, r0
 *   @0x221590 mov r0, r6
 *   @0x221594 mov r4, r1
 *   @0x221598 mov r7, r2
 *   @0x22159c mov r8, r3
 *   @0x2215a0 vldr s16, [sp, #48]
 *   @0x2215a4 bl 0x222a98 <_alutMalloc>
 *   @0x2215a8 subs r10, r0, #0
 *   @0x2215ac beq 0x221638 <_alutCodecULaw+0xbc>
 *   @0x2215b0 cmp r4, #0
 *   @0x2215b4 beq 0x22160c <_alutCodecULaw+0x90>
 *   @0x2215b8 ldr r3, [pc, #0x84]
 *   @0x2215bc add r1, r4, r9
 *   @0x2215c0 sub r5, r10, #2
 *   @0x2215c4 mov lr, r9
 *   @0x2215c8 add r3, pc, r3
 *   @0x2215cc ldrb r12, [lr], #1
 *   @0x2215d0 mvn r12, r12
 *   @0x2215d4 uxtb r12, r12
 *   @0x2215d8 ubfx r4, r12, #0x4, #0x3
 *   @0x2215dc and r11, r12, #15
 *   @0x2215e0 add r0, r4, #3
 *   @0x2215e4 tst r12, #128
 *   @0x2215e8 lsl r4, r4, #1
 *   @0x2215ec ldrh r2, [r3, r4]
 *   @0x2215f0 add r12, r2, r11, lsl r0
 *   @0x2215f4 uxth r12, r12
 *   @0x2215f8 rsbne r12, r12, #0
 *   @0x2215fc cmp lr, r1
 *   @0x221600 uxth r12, r12
 *   @0x221604 strh r12, [r5, #2]!
 *   @0x221608 bne 0x2215cc <_alutCodecULaw+0x50>
 *   @0x22160c mov r0, r9
 *   @0x221610 bl 0xb655c <free@plt>
 *   @0x221614 vstr s16, [sp, #48]
 *   @0x221618 mov r0, r10
 *   @0x22161c mov r1, r6
 *   @0x221620 mov r2, r7
 *   @0x221624 mov r3, r8
 *   @0x221628 add sp, sp, #4
 *   @0x22162c vpop {d8}
 *   @0x221630 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x221634 b 0x221378 <_alutBufferDataConstruct>
 *   @0x221638 add sp, sp, #4
 *   @0x22163c vpop {d8}
 *   @0x221640 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x221644 ldrheq r12, [r3], -r4
 *
 * ══ §126/146 _alutCodecALaw  0x221648  size 204  51 条（0x221648..0x221714）
 * @func 0x221648 0x221714  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _alutMalloc / 0xb655c
 * 字段偏移 top8: 0x28×2 / 0x1×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x221648 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x22164c lsl r6, r1, #1
 *   @0x221650 sub sp, sp, #4
 *   @0x221654 mov r9, r0
 *   @0x221658 mov r0, r6
 *   @0x22165c mov r4, r1
 *   @0x221660 mov r7, r2
 *   @0x221664 mov r8, r3
 *   @0x221668 ldr r11, [sp, #0x28]
 *   @0x22166c bl 0x222a98 <_alutMalloc>
 *   @0x221670 subs r10, r0, #0
 *   @0x221674 beq 0x22170c <_alutCodecALaw+0xc4>
 *   @0x221678 cmp r4, #0
 *   @0x22167c addne r1, r4, r9
 *   @0x221680 subne r2, r10, #2
 *   @0x221684 movne lr, r9
 *   @0x221688 beq 0x2216e4 <_alutCodecALaw+0x9c>
 *   @0x22168c ldrb r12, [lr], #1
 *   @0x221690 eor r12, r12, #85
 *   @0x221694 ubfx r5, r12, #0x4, #0x3
 *   @0x221698 lsl r3, r12, #4
 *   @0x22169c sxth r4, r5
 *   @0x2216a0 and r3, r3, #240
 *   @0x2216a4 cmp r4, #0
 *   @0x2216a8 addeq r4, r3, #8
 *   @0x2216ac beq 0x2216c8 <_alutCodecALaw+0x80>
 *   @0x2216b0 cmp r4, #1
 *   @0x2216b4 add r4, r3, #264
 *   @0x2216b8 addne r4, r3, #264
 *   @0x2216bc subne r5, r5, #1
 *   @0x2216c0 lslne r4, r4, r5
 *   @0x2216c4 uxthne r4, r4
 *   @0x2216c8 tst r12, #128
 *   @0x2216cc rsb r3, r4, #0
 *   @0x2216d0 uxth r3, r3
 *   @0x2216d4 movne r3, r4
 *   @0x2216d8 cmp lr, r1
 *   @0x2216dc strh r3, [r2, #2]!
 *   @0x2216e0 bne 0x22168c <_alutCodecALaw+0x44>
 *   @0x2216e4 mov r0, r9
 *   @0x2216e8 bl 0xb655c <free@plt>
 *   @0x2216ec str r11, [sp, #0x28]
 *   @0x2216f0 mov r0, r10
 *   @0x2216f4 mov r1, r6
 *   @0x2216f8 mov r2, r7
 *   @0x2216fc mov r3, r8
 *   @0x221700 add sp, sp, #4
 *   @0x221704 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x221708 b 0x221378 <_alutBufferDataConstruct>
 *   @0x22170c add sp, sp, #4
 *   @0x221710 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §127/146 vorbis_comment_query_count  0x22ab80  size 204  51 条（0x22ab80..0x22ac4c）
 * @func 0x22ab80 0x22ac4c  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538 / 0xb65bc / vorbis_comment_query_count+0xb8 / anon_229e24+0xbd4 / 0xb65d4
 * 字段偏移 top8: 0x-20×2 / 0xb4×1 / 0x6c×1 / 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22ab80 push {r4, r5, r6, r7, r8, r9, r11, lr}
 *   @0x22ab84 add r11, sp, #28
 *   @0x22ab88 ldr r9, [pc, #0xb4]
 *   @0x22ab8c sub sp, sp, #8
 *   @0x22ab90 mov r6, r0
 *   @0x22ab94 ldr r9, [pc, r9]
 *   @0x22ab98 mov r0, r1
 *   @0x22ab9c mov r5, r1
 *   @0x22aba0 ldr r3, [r9]
 *   @0x22aba4 str r3, [r11, #-0x20]
 *   @0x22aba8 bl 0xb6538 <strlen@plt>
 *   @0x22abac mov r1, r5
 *   @0x22abb0 add r3, r0, #16
 *   @0x22abb4 mov r4, r0
 *   @0x22abb8 bic r3, r3, #7
 *   @0x22abbc mov r2, r0
 *   @0x22abc0 sub sp, sp, r3
 *   @0x22abc4 add r7, r0, #1
 *   @0x22abc8 mov r0, sp
 *   @0x22abcc mov r5, sp
 *   @0x22abd0 bl 0xb65bc <memcpy@plt>
 *   @0x22abd4 ldr r3, [pc, #0x6c]
 *   @0x22abd8 ldr r8, [r6, #0x8]
 *   @0x22abdc add r3, pc, r3
 *   @0x22abe0 cmp r8, #0
 *   @0x22abe4 ldrh r3, [r3]
 *   @0x22abe8 strh r3, [sp, r4]
 *   @0x22abec ble 0x22ac38 <vorbis_comment_query_count+0xb8>
 *   @0x22abf0 ldr r4, [r6]
 *   @0x22abf4 mov r6, #0
 *   @0x22abf8 add r8, r4, r8, lsl #2
 *   @0x22abfc ldr r0, [r4], #4
 *   @0x22ac00 mov r1, r5
 *   @0x22ac04 mov r2, r7
 *   @0x22ac08 bl 0x22a9f8 <vorbis_lsp_to_curve+0x114c>
 *   @0x22ac0c cmp r0, #0
 *   @0x22ac10 addeq r6, r6, #1
 *   @0x22ac14 cmp r4, r8
 *   @0x22ac18 bne 0x22abfc <vorbis_comment_query_count+0x7c>
 *   @0x22ac1c ldr r2, [r11, #-0x20]
 *   @0x22ac20 mov r0, r6
 *   @0x22ac24 ldr r3, [r9]
 *   @0x22ac28 cmp r2, r3
 *   @0x22ac2c bne 0x22ac40 <vorbis_comment_query_count+0xc0>
 *   @0x22ac30 sub sp, r11, #28
 *   @0x22ac34 pop {r4, r5, r6, r7, r8, r9, r11, pc}
 *   @0x22ac38 mov r6, #0
 *   @0x22ac3c b 0x22ac1c <vorbis_comment_query_count+0x9c>
 *   @0x22ac40 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x22ac44 ldrheq r2, [r12], -r12
 *   @0x22ac48 ldrsheq r10, [r2], -r4
 *
 * ══ §128/146 oggpack_look  0x23388c  size 204  51 条（0x23388c..0x233958）
 * @func 0x23388c 0x233968  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: oggpack_look+0x64×3 / oggpack_look+0x50
 * 字段偏移 top8: 0x2×2 / 0x10×1 / 0xac×1 / 0x4×1 / 0xc×1 / 0x1×1 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23388c cmp r1, #32
 *   @0x233890 push {r4, r5}
 *   @0x233894 bhi 0x23394c <oggpack_look+0xc0>
 *   @0x233898 ldr r4, [r0, #0x10]
 *   @0x23389c ldr r12, [r0]
 *   @0x2338a0 ldr r2, [pc, #0xac]
 *   @0x2338a4 sub r3, r4, #4
 *   @0x2338a8 cmp r12, r3
 *   @0x2338ac ldr r3, [r0, #0x4]
 *   @0x2338b0 add r2, pc, r2
 *   @0x2338b4 ldr r5, [r2, r1, lsl #2]
 *   @0x2338b8 add r1, r3, r1
 *   @0x2338bc blt 0x2338dc <oggpack_look+0x50>
 *   @0x2338c0 add r2, r1, #7
 *   @0x2338c4 sub r4, r4, r2, asr #3
 *   @0x2338c8 cmp r12, r4
 *   @0x2338cc bgt 0x23394c <oggpack_look+0xc0>
 *   @0x2338d0 cmp r1, #0
 *   @0x2338d4 moveq r0, r1
 *   @0x2338d8 beq 0x2338f4 <oggpack_look+0x68>
 *   @0x2338dc ldr r12, [r0, #0xc]
 *   @0x2338e0 cmp r1, #8
 *   @0x2338e4 ldrb r2, [r12]
 *   @0x2338e8 asr r2, r2, r3
 *   @0x2338ec bgt 0x2338fc <oggpack_look+0x70>
 *   @0x2338f0 and r0, r2, r5
 *   @0x2338f4 pop {r4, r5}
 *   @0x2338f8 bx lr
 *   @0x2338fc ldrb r4, [r12, #0x1]
 *   @0x233900 cmp r1, #16
 *   @0x233904 rsb r0, r3, #8
 *   @0x233908 orr r2, r2, r4, lsl r0
 *   @0x23390c ble 0x2338f0 <oggpack_look+0x64>
 *   @0x233910 ldrb r4, [r12, #0x2]
 *   @0x233914 cmp r1, #24
 *   @0x233918 rsb r0, r3, #16
 *   @0x23391c orr r2, r2, r4, lsl r0
 *   @0x233920 ble 0x2338f0 <oggpack_look+0x64>
 *   @0x233924 ldrb r0, [r12, #0x3]
 *   @0x233928 cmp r1, #32
 *   @0x23392c rsb r1, r3, #24
 *   @0x233930 orr r2, r2, r0, lsl r1
 *   @0x233934 ble 0x2338f0 <oggpack_look+0x64>
 *   @0x233938 cmp r3, #0
 *   @0x23393c rsbne r3, r3, #32
 *   @0x233940 ldrbne r1, [r12, #0x4]
 *   @0x233944 orrne r2, r2, r1, lsl r3
 *   @0x233948 b 0x2338f0 <oggpack_look+0x64>
 *   @0x23394c mvn r0, #0
 *   @0x233950 b 0x2338f4 <oggpack_look+0x68>
 *   @0x233954 andseq r5, r3, r8, lsl #3
 *
 * ══ §129/146 CPhysicsWorld::CreateGearJoint(CPhysicsObject*, CPhysicsObject*, CPhysicsJoint*, CPhysicsJoint*, float)  0x23974c  size 204  51 条（0x23974c..0x239818）
 * @func 0x23974c 0x239828  size 220  55 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsWorld::CreateGearJoint(CPhysicsObject*, CPhysicsObject*, CPhysicsJoint*, CPhysicsJoint*, float)+0x44 / CPhysicsWorld::CreateGearJoint(CPhysicsObject*, CPhysicsObject*, CPhysicsJoint*, CPhysicsJoint*, float)+0x4c / CPhysicsJointFactory::CreateJoint(CPhysicsWorld*, b2JointDef const&)
 * 字段偏移 top8: 0x4×9 / 0x28×2 / 0x8×2 / 0xc×1 / 0x14×1 / 0x18×1 / 0x10×1 / 0xa0×1
 * VFP 指令 2 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23974c push {r4, lr}
 *   @0x239750 sub sp, sp, #32
 *   @0x239754 ldr r4, [r3, #0x4]
 *   @0x239758 ldr r3, [r4, #0x4]
 *   @0x23975c sub r3, r3, #1
 *   @0x239760 cmp r3, #1
 *   @0x239764 bls 0x239790 <_ZN13CPhysicsWorld15CreateGearJointEP14CPhysicsObjectS1_P13CPhysicsJointS3_f+0x44>
 *   @0x239768 ldr r12, [sp, #0x28]
 *   @0x23976c ldr r3, [r12, #0x4]
 *   @0x239770 ldr r12, [r3, #0x4]
 *   @0x239774 sub r12, r12, #1
 *   @0x239778 cmp r12, #1
 *   @0x23977c movls lr, r3
 *   @0x239780 bls 0x239798 <_ZN13CPhysicsWorld15CreateGearJointEP14CPhysicsObjectS1_P13CPhysicsJointS3_f+0x4c>
 *   @0x239784 mvn r0, #0
 *   @0x239788 add sp, sp, #32
 *   @0x23978c pop {r4, pc}
 *   @0x239790 ldr r3, [sp, #0x28]
 *   @0x239794 ldr lr, [r3, #0x4]
 *   @0x239798 ldr r12, [r1]
 *   @0x23979c ldrh r3, [r12, #4]
 *   @0x2397a0 tst r3, #2
 *   @0x2397a4 beq 0x239804 <_ZN13CPhysicsWorld15CreateGearJointEP14CPhysicsObjectS1_P13CPhysicsJointS3_f+0xb8>
 *   @0x2397a8 ldr r3, [r2]
 *   @0x2397ac vldr s15, [sp, #44]
 *   @0x2397b0 ldrh r2, [r3, #4]
 *   @0x2397b4 tst r2, #2
 *   @0x2397b8 orreq r2, r2, #2
 *   @0x2397bc strheq r2, [r3, #4]
 *   @0x2397c0 moveq r1, #0
 *   @0x2397c4 streq r1, [r3, #0xa0]
 *   @0x2397c8 mov r1, sp
 *   @0x2397cc mov r2, #0
 *   @0x2397d0 str r3, [sp, #0xc]
 *   @0x2397d4 vstr s15, [sp, #28]
 *   @0x2397d8 mov r3, #6
 *   @0x2397dc str r12, [sp, #0x8]
 *   @0x2397e0 str r4, [sp, #0x14]
 *   @0x2397e4 str lr, [sp, #0x18]
 *   @0x2397e8 str r2, [sp, #0x4]
 *   @0x2397ec strb r2, [sp, #0x10]
 *   @0x2397f0 str r3, [sp]
 *   @0x2397f4 bl 0x23b2a8 <_ZN20CPhysicsJointFactory11CreateJointEP13CPhysicsWorldRK10b2JointDef>
 *   @0x2397f8 ldr r0, [r0, #0x8]
 *   @0x2397fc add sp, sp, #32
 *   @0x239800 pop {r4, pc}
 *   @0x239804 orr r3, r3, #2
 *   @0x239808 mov r1, #0
 *   @0x23980c strh r3, [r12, #4]
 *   @0x239810 str r1, [r12, #0xa0]
 *   @0x239814 b 0x2397a8 <_ZN13CPhysicsWorld15CreateGearJointEP14CPhysicsObjectS1_P13CPhysicsJointS3_f+0x5c>
 *
 * ══ §130/146 CPhysicsWorld::TestOverlap(CInstance*, CInstance*, float, float, float)  0x239818  size 204  51 条（0x239818..0x2398e4）
 * @func 0x239818 0x2398e4  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6580 / 0xb658c / b2TestOverlap(b2Shape const*, int, b2Shape const*, int, b2Transform const&, b2Transform const&)
 * 字段偏移 top8: 0xc×3 / 0x84×2 / 0x74×2 / 0x4×2 / 0x34×1 / 0x30×1 / 0x8×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x239818 push {r4, r5, r6, r7, r8, lr}
 *   @0x23981c sub sp, sp, #24
 *   @0x239820 mov r5, r1
 *   @0x239824 mov r6, r2
 *   @0x239828 ldr r4, [sp, #0x34]
 *   @0x23982c ldr r1, [sp, #0x30]
 *   @0x239830 str r3, [sp, #0x8]
 *   @0x239834 mov r0, r4
 *   @0x239838 str r1, [sp, #0xc]
 *   @0x23983c bl 0xb6580 <sinf@plt>
 *   @0x239840 str r0, [sp, #0x10]
 *   @0x239844 mov r0, r4
 *   @0x239848 bl 0xb658c <cosf@plt>
 *   @0x23984c ldr r3, [r5, #0x84]
 *   @0x239850 cmp r3, #0
 *   @0x239854 str r0, [sp, #0x14]
 *   @0x239858 beq 0x2398d8 <_ZN13CPhysicsWorld11TestOverlapEP9CInstanceS1_fff+0xc0>
 *   @0x23985c ldr r2, [r6, #0x84]
 *   @0x239860 cmp r2, #0
 *   @0x239864 beq 0x2398d8 <_ZN13CPhysicsWorld11TestOverlapEP9CInstanceS1_fff+0xc0>
 *   @0x239868 ldr r3, [r3]
 *   @0x23986c ldr r8, [r2]
 *   @0x239870 ldr r5, [r3, #0x74]
 *   @0x239874 cmp r5, #0
 *   @0x239878 beq 0x2398d8 <_ZN13CPhysicsWorld11TestOverlapEP9CInstanceS1_fff+0xc0>
 *   @0x23987c add r7, r8, #12
 *   @0x239880 add r6, sp, #8
 *   @0x239884 ldr r4, [r8, #0x74]
 *   @0x239888 cmp r4, #0
 *   @0x23988c bne 0x2398a0 <_ZN13CPhysicsWorld11TestOverlapEP9CInstanceS1_fff+0x88>
 *   @0x239890 b 0x2398cc <_ZN13CPhysicsWorld11TestOverlapEP9CInstanceS1_fff+0xb4>
 *   @0x239894 ldr r4, [r4, #0x4]
 *   @0x239898 cmp r4, #0
 *   @0x23989c beq 0x2398cc <_ZN13CPhysicsWorld11TestOverlapEP9CInstanceS1_fff+0xb4>
 *   @0x2398a0 mov r1, #0
 *   @0x2398a4 ldr r0, [r5, #0xc]
 *   @0x2398a8 ldr r2, [r4, #0xc]
 *   @0x2398ac mov r3, r1
 *   @0x2398b0 stm sp, {r6, r7}
 *   @0x2398b4 bl 0x2c3abc <_Z13b2TestOverlapPK7b2ShapeiS1_iRK11b2TransformS4_>
 *   @0x2398b8 cmp r0, #0
 *   @0x2398bc beq 0x239894 <_ZN13CPhysicsWorld11TestOverlapEP9CInstanceS1_fff+0x7c>
 *   @0x2398c0 mov r0, #1
 *   @0x2398c4 add sp, sp, #24
 *   @0x2398c8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2398cc ldr r5, [r5, #0x4]
 *   @0x2398d0 cmp r5, #0
 *   @0x2398d4 bne 0x239884 <_ZN13CPhysicsWorld11TestOverlapEP9CInstanceS1_fff+0x6c>
 *   @0x2398d8 mov r0, #0
 *   @0x2398dc add sp, sp, #24
 *   @0x2398e0 pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §131/146 CPhysicsJointFactory::CreateJoint(CPhysicsWorld*, b2JointDef const&)  0x23b2a8  size 204  51 条（0x23b2a8..0x23b374）
 * @func 0x23b2a8 0x23b374  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2World::CreateJoint(b2JointDef const*) / operator new(unsigned int) / MemoryManager::Alloc(unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x8×4 / 0xa8×2 / 0x4×2 / 0x10×1 / 0x88×1 / 0x3×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23b2a8 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x23b2ac mov r7, r0
 *   @0x23b2b0 ldr r0, [r0, #0x10]
 *   @0x23b2b4 bl 0x2c90f8 <_ZN7b2World11CreateJointEPK10b2JointDef>
 *   @0x23b2b8 ldr r3, [pc, #0xa8]
 *   @0x23b2bc ldr r4, [pc, #0xa8]
 *   @0x23b2c0 ldr r3, [pc, r3]
 *   @0x23b2c4 ldr r6, [r3]
 *   @0x23b2c8 add r6, r6, #1
 *   @0x23b2cc str r6, [r3]
 *   @0x23b2d0 mov r9, r0
 *   @0x23b2d4 mov r0, #28
 *   @0x23b2d8 bl 0x27c524 <_Znwj>
 *   @0x23b2dc ldr r4, [pc, r4]
 *   @0x23b2e0 ldr r1, [pc, #0x88]
 *   @0x23b2e4 movw r2, #0x132
 *   @0x23b2e8 ldr r8, [r4, #0x4]
 *   @0x23b2ec mov r3, #1
 *   @0x23b2f0 add r1, pc, r1
 *   @0x23b2f4 and r8, r6, r8
 *   @0x23b2f8 mov r5, r0
 *   @0x23b2fc str r7, [r0]
 *   @0x23b300 str r6, [r0, #0x8]
 *   @0x23b304 mov r0, #16
 *   @0x23b308 str r9, [r5, #0x4]
 *   @0x23b30c ldr r7, [r4]
 *   @0x23b310 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x23b314 add r2, r7, r8, lsl #3
 *   @0x23b318 ldr r1, [r7, r8, lsl #3]
 *   @0x23b31c cmp r1, #0
 *   @0x23b320 ldrne r1, [r2, #0x4]
 *   @0x23b324 mov r3, r0
 *   @0x23b328 str r6, [r0, #0x8]
 *   @0x23b32c str r5, [r0, #0xc]
 *   @0x23b330 movne r0, #0
 *   @0x23b334 strne r1, [r3]
 *   @0x23b338 strne r3, [r1, #0x4]
 *   @0x23b33c strne r3, [r2, #0x4]
 *   @0x23b340 strne r0, [r3, #0x4]
 *   @0x23b344 ldr r3, [r4, #0x8]
 *   @0x23b348 streq r0, [r2, #0x4]
 *   @0x23b34c add r3, r3, #1
 *   @0x23b350 streq r0, [r7, r8, lsl #3]
 *   @0x23b354 streq r1, [r0, #0x4]
 *   @0x23b358 streq r1, [r0]
 *   @0x23b35c mov r0, r5
 *   @0x23b360 str r3, [r4, #0x8]
 *   @0x23b364 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x23b368 andseq r6, r11, r0, lsr #4
 *   @0x23b36c andseq r6, r11, r8, lsl #4
 *   @0x23b370 ldrheq r1, [r1], -r12
 *
 * ══ §132/146 JS_Math_max(RValue&, CInstance*, CInstance*, int, RValue*)  0x2525c0  size 204  51 条（0x2525c0..0x25268c）
 * @func 0x2525c0 0x25268c  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_Math_max(RValue&, CInstance*, CInstance*, int, RValue*)+0xb4 / F_JS_ToNumber(RValue&, RValue&) / YYGetReal(RValue const*, int)
 * 字段偏移 top8: 0x20×1 / 0xc×1 / 0x1c×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2525c0 push {r3, r4, r5, r6, r7, lr}
 *   @0x2525c4 vpush {d8}
 *   @0x2525c8 subs r7, r3, #0
 *   @0x2525cc mov r6, r0
 *   @0x2525d0 ldr r4, [sp, #0x20]
 *   @0x2525d4 ble 0x252674 <_Z11JS_Math_maxR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x2525d8 mov r5, #0
 *   @0x2525dc vldr d8, [pc, #156]
 *   @0x2525e0 b 0x252600 <_Z11JS_Math_maxR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x2525e4 vcmp.f64 d7, d8
 *   @0x2525e8 add r5, r5, #1
 *   @0x2525ec add r4, r4, #16
 *   @0x2525f0 vmrs APSR_nzcv, fpscr
 *   @0x2525f4 vmovgt.f64 d8, d7
 *   @0x2525f8 cmp r5, r7
 *   @0x2525fc beq 0x252644 <_Z11JS_Math_maxR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x252600 mov r1, r4
 *   @0x252604 mov r0, r6
 *   @0x252608 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_>
 *   @0x25260c mov r1, #0
 *   @0x252610 cmp r0, #1
 *   @0x252614 mov r0, r6
 *   @0x252618 beq 0x252660 <_Z11JS_Math_maxR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x25261c bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x252620 vmov d7, r0, r1
 *   @0x252624 vcmp.f64 d7, d7
 *   @0x252628 vmrs APSR_nzcv, fpscr
 *   @0x25262c bvc 0x2525e4 <_Z11JS_Math_maxR6RValueP9CInstanceS2_iPS_+0x24>
 *   @0x252630 add r5, r5, #1
 *   @0x252634 vmov d8, r0, r1
 *   @0x252638 cmp r5, r7
 *   @0x25263c add r4, r4, #16
 *   @0x252640 bne 0x252600 <_Z11JS_Math_maxR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x252644 mov r3, #0
 *   @0x252648 vmov r2, s16
 *   @0x25264c str r3, [r6, #0xc]
 *   @0x252650 vmov r3, s17
 *   @0x252654 stm r6, {r2, r3}
 *   @0x252658 vpop {d8}
 *   @0x25265c pop {r3, r4, r5, r6, r7, pc}
 *   @0x252660 vpop {d8}
 *   @0x252664 ldr r0, [pc, #0x1c]
 *   @0x252668 add r0, pc, r0
 *   @0x25266c pop {r3, r4, r5, r6, r7, lr}
 *   @0x252670 b 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x252674 vldr d8, [pc, #4]
 *   @0x252678 b 0x252644 <_Z11JS_Math_maxR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x25267c nop
 *   @0x252680 andeq r0, r0, r0
 *   @0x252684 .word 0xfff00000
 *   @0x252688 andseq r3, r0, r0, ror #17
 *
 * ══ §133/146 JS_Math_min(RValue&, CInstance*, CInstance*, int, RValue*)  0x252690  size 204  51 条（0x252690..0x25275c）
 * @func 0x252690 0x25275c  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_Math_min(RValue&, CInstance*, CInstance*, int, RValue*)+0xb4 / F_JS_ToNumber(RValue&, RValue&) / YYGetReal(RValue const*, int)
 * 字段偏移 top8: 0x20×1 / 0xc×1 / 0x1c×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x252690 push {r3, r4, r5, r6, r7, lr}
 *   @0x252694 vpush {d8}
 *   @0x252698 subs r7, r3, #0
 *   @0x25269c mov r6, r0
 *   @0x2526a0 ldr r4, [sp, #0x20]
 *   @0x2526a4 ble 0x252744 <_Z11JS_Math_minR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x2526a8 mov r5, #0
 *   @0x2526ac vldr d8, [pc, #156]
 *   @0x2526b0 b 0x2526d0 <_Z11JS_Math_minR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x2526b4 vcmp.f64 d7, d8
 *   @0x2526b8 add r5, r5, #1
 *   @0x2526bc add r4, r4, #16
 *   @0x2526c0 vmrs APSR_nzcv, fpscr
 *   @0x2526c4 vmovmi.f64 d8, d7
 *   @0x2526c8 cmp r5, r7
 *   @0x2526cc beq 0x252714 <_Z11JS_Math_minR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x2526d0 mov r1, r4
 *   @0x2526d4 mov r0, r6
 *   @0x2526d8 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_>
 *   @0x2526dc mov r1, #0
 *   @0x2526e0 cmp r0, #1
 *   @0x2526e4 mov r0, r6
 *   @0x2526e8 beq 0x252730 <_Z11JS_Math_minR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x2526ec bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x2526f0 vmov d7, r0, r1
 *   @0x2526f4 vcmp.f64 d7, d7
 *   @0x2526f8 vmrs APSR_nzcv, fpscr
 *   @0x2526fc bvc 0x2526b4 <_Z11JS_Math_minR6RValueP9CInstanceS2_iPS_+0x24>
 *   @0x252700 add r5, r5, #1
 *   @0x252704 vmov d8, r0, r1
 *   @0x252708 cmp r5, r7
 *   @0x25270c add r4, r4, #16
 *   @0x252710 bne 0x2526d0 <_Z11JS_Math_minR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x252714 mov r3, #0
 *   @0x252718 vmov r2, s16
 *   @0x25271c str r3, [r6, #0xc]
 *   @0x252720 vmov r3, s17
 *   @0x252724 stm r6, {r2, r3}
 *   @0x252728 vpop {d8}
 *   @0x25272c pop {r3, r4, r5, r6, r7, pc}
 *   @0x252730 vpop {d8}
 *   @0x252734 ldr r0, [pc, #0x1c]
 *   @0x252738 add r0, pc, r0
 *   @0x25273c pop {r3, r4, r5, r6, r7, lr}
 *   @0x252740 b 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x252744 vldr d8, [pc, #4]
 *   @0x252748 b 0x252714 <_Z11JS_Math_minR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x25274c nop
 *   @0x252750 andeq r0, r0, r0
 *   @0x252754 svcvc #0xf00000
 *   @0x252758 andseq r3, r0, r0, lsl r8
 *
 * ══ §134/146 F_JSNew(RValue&, CInstance*, CInstance*, int, RValue*)  0x254d4c  size 204  51 条（0x254d4c..0x254e18）
 * @func 0x254d4c 0x254e18  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_JSNew(RValue&, CInstance*, CInstance*, int, RValue*)+0x28 / PushContextStack(YYObjectBase*)
 * 字段偏移 top8: 0xc×3 / 0x10×2 / 0x28×1 / 0x88×1 / 0x70×1 / 0x48×1 / 0x94×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x254d4c push {r4, r5, r6, r7, lr}
 *   @0x254d50 sub sp, sp, #20
 *   @0x254d54 subs r5, r3, #0
 *   @0x254d58 mov r6, r0
 *   @0x254d5c ldr r4, [sp, #0x28]
 *   @0x254d60 ldr r1, [r4, #0xc]
 *   @0x254d64 bic r1, r1, #-16777216
 *   @0x254d68 ble 0x254d74 <_Z7F_JSNewR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x254d6c cmp r1, #6
 *   @0x254d70 beq 0x254da8 <_Z7F_JSNewR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x254d74 mvn r3, #-16777216
 *   @0x254d78 ldr r0, [pc, #0x88]
 *   @0x254d7c cmp r1, r3
 *   @0x254d80 add r0, pc, r0
 *   @0x254d84 beq 0x254d94 <_Z7F_JSNewR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x254d88 add sp, sp, #20
 *   @0x254d8c pop {r4, r5, r6, r7, lr}
 *   @0x254d90 b 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x254d94 ldr r0, [pc, #0x70]
 *   @0x254d98 add r0, pc, r0
 *   @0x254d9c add sp, sp, #20
 *   @0x254da0 pop {r4, r5, r6, r7, lr}
 *   @0x254da4 b 0x254b04 <_Z21JSThrowReferenceErrorPKc>
 *   @0x254da8 ldr r0, [r4]
 *   @0x254dac ldr r3, [r0, #0x48]
 *   @0x254db0 cmp r3, #3
 *   @0x254db4 bne 0x254df0 <_Z7F_JSNewR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x254db8 ldr r7, [r0, #0x94]
 *   @0x254dbc cmp r7, #0
 *   @0x254dc0 beq 0x254dfc <_Z7F_JSNewR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x254dc4 str r2, [sp, #0xc]
 *   @0x254dc8 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase>
 *   @0x254dcc ldr r1, [r4], #16
 *   @0x254dd0 mov r0, r6
 *   @0x254dd4 ldr r2, [sp, #0xc]
 *   @0x254dd8 sub r3, r5, #1
 *   @0x254ddc str r4, [sp]
 *   @0x254de0 blx r7
 *   @0x254de4 add sp, sp, #20
 *   @0x254de8 pop {r4, r5, r6, r7, lr}
 *   @0x254dec b 0xd3a34 <_Z15PopContextStackv>
 *   @0x254df0 ldr r0, [pc, #0x18]
 *   @0x254df4 add r0, pc, r0
 *   @0x254df8 b 0x254d88 <_Z7F_JSNewR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x254dfc ldr r0, [pc, #0x10]
 *   @0x254e00 add r0, pc, r0
 *   @0x254e04 b 0x254d88 <_Z7F_JSNewR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x254e08 andseq r1, r0, r12, lsl #22
 *   @0x254e0c andseq r1, r0, r0, asr #21
 *   @0x254e10 andseq r1, r0, r12, asr #21
 *   @0x254e14 ldrsheq r1, [r0], -r4
 *
 * ══ §135/146 Java_com_yoyogames_runner_RunnerJNILib_LoginResult  0x2949f4  size 204  51 条（0x2949f4..0x294ac0）
 * @func 0x2949f4 0x294ac0  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: setJNIEnv / 0xb6538 / 0xb6640 / InputQuery::SetUserNamePassword(int, int, char const*)
 * 字段偏移 top8: 0x2a4×2 / 0x2a8×2 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2949f4 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2949f8 mov r4, r0
 *   @0x2949fc mov r8, r2
 *   @0x294a00 mov r7, r3
 *   @0x294a04 bl 0x290614 <setJNIEnv>
 *   @0x294a08 ldr r3, [r4]
 *   @0x294a0c mov r1, r8
 *   @0x294a10 mov r2, #0
 *   @0x294a14 mov r0, r4
 *   @0x294a18 ldr r3, [r3, #0x2a4]
 *   @0x294a1c blx r3
 *   @0x294a20 ldr r3, [r4]
 *   @0x294a24 mov r1, r7
 *   @0x294a28 mov r2, #0
 *   @0x294a2c ldr r3, [r3, #0x2a4]
 *   @0x294a30 mov r6, r0
 *   @0x294a34 mov r0, r4
 *   @0x294a38 blx r3
 *   @0x294a3c adds r3, r6, #0
 *   @0x294a40 movne r3, #1
 *   @0x294a44 adds r5, r0, #0
 *   @0x294a48 mov r9, r0
 *   @0x294a4c movne r5, #1
 *   @0x294a50 tst r5, r3
 *   @0x294a54 bne 0x294a9c <Java_com_yoyogames_runner_RunnerJNILib_LoginResult+0xa8>
 *   @0x294a58 cmp r3, #0
 *   @0x294a5c beq 0x294a78 <Java_com_yoyogames_runner_RunnerJNILib_LoginResult+0x84>
 *   @0x294a60 ldr r3, [r4]
 *   @0x294a64 mov r1, r8
 *   @0x294a68 mov r2, r6
 *   @0x294a6c mov r0, r4
 *   @0x294a70 ldr r3, [r3, #0x2a8]
 *   @0x294a74 blx r3
 *   @0x294a78 cmp r5, #0
 *   @0x294a7c popeq {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x294a80 ldr r3, [r4]
 *   @0x294a84 mov r1, r7
 *   @0x294a88 mov r2, r9
 *   @0x294a8c mov r0, r4
 *   @0x294a90 ldr r3, [r3, #0x2a8]
 *   @0x294a94 blx r3
 *   @0x294a98 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x294a9c bl 0xb6538 <strlen@plt>
 *   @0x294aa0 mov r10, r0
 *   @0x294aa4 mov r0, r6
 *   @0x294aa8 bl 0xb6640 <strdup@plt>
 *   @0x294aac mov r1, r10
 *   @0x294ab0 mov r2, r0
 *   @0x294ab4 ldr r0, [sp, #0x20]
 *   @0x294ab8 bl 0xf27b4 <_ZN10InputQuery19SetUserNamePasswordEiiPKc>
 *   @0x294abc b 0x294a60 <Java_com_yoyogames_runner_RunnerJNILib_LoginResult+0x6c>
 *
 * ══ §136/146 png_set_rgb_to_gray_fixed  0x2a8824  size 204  51 条（0x2a8824..0x2a88f0）
 * @func 0x2a8824 0x2a88f0  size 204  51 条
 * 部分覆盖: 本节 51/88 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_set_rgb_to_gray_fixed+0x94×2 / 0x375018 / __udivsi3 / png_warning
 * 字段偏移 top8: 0x44×1 / 0x34×1
 * VFP 指令 2 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a8824 push {r3, r4, r5, r6, r7, lr}
 *   @0x2a8828 mov r7, r3
 *   @0x2a882c cmp r0, #0x0
 *   @0x2a8830 cmp r1, #0x2
 *   @0x2a8834 cmp r1, #0x3
 *   @0x2a8838 cmp r1, #0x1
 *   @0x2a883c ldr.w r3, [r0, #0x134]
 *   @0x2a8840 orr r3, r3, #0x600000
 *   @0x2a8844 b 0x2a884e <png_set_rgb_to_gray_fixed+0x2a>
 *   @0x2a8848 vst4.8 {d19, d21, d23, d25}, [r3:256], r4
 *   @0x2a884c .word 0xf8c40380
 *   @0x2a8850 and r3, r8, r4, lsr r1
 *   @0x2a8854 ldr.w r3, [r0, #0x134]
 *   @0x2a8858 orr r3, r3, #0x200000
 *   @0x2a885c b 0x2a884e <png_set_rgb_to_gray_fixed+0x2a>
 *   @0x2a8860 add r1, pc
 *   @0x2a8864 .word 0xf894fde3
 *   @0x2a8868 blhs 0x375018 <_ZTS13C_UTF16String+0xc0c4>
 *   @0x2a886c bne 0x2a887a <png_set_rgb_to_gray_fixed+0x56>
 *   @0x2a8870 vst4.8 {d19, d21, d23, d25}, [r3:256], r4
 *   @0x2a8874 .word 0xf8c45380
 *   @0x2a8878 stchs p1, c3, [r0, #-208]
 *   @0x2a887c blt 0x2a88b8 <png_set_rgb_to_gray_fixed+0x94>
 *   @0x2a8880 blt 0x2a88b8 <png_set_rgb_to_gray_fixed+0x94>
 *   @0x2a8884 adds r3, r5, r7
 *   @0x2a8888 bgt 0x2a88ae <png_set_rgb_to_gray_fixed+0x8a>
 *   @0x2a888c mov r1, r6
 *   @0x2a8890 .word 0x4631e9dc
 *   @0x2a8894 uxth r5, r0
 *   @0x2a8898 blx 0x318c48 <__udivsi3>
 *   @0x2a889c ldr r3, [pc, #0x44]
 *   @0x2a88a0 addlt r5, r0, #1610612749
 *   @0x2a88a4 strh.w r0, [r4, #0x2d8]
 *   @0x2a88a8 subs r3, r3, r0
 *   @0x2a88ac b 0x2a88d8 <png_set_rgb_to_gray_fixed+0xb4>
 *   @0x2a88b0 mov r0, r4
 *   @0x2a88b4 bl 0x2a6474 <png_warning>
 *   @0x2a88b8 ldrh.w r3, [r4, #0x2d6]
 *   @0x2a88bc cbnz r3, 0x2a88dc <png_set_rgb_to_gray_fixed+0xb8>
 *   @0x2a88c0 ldmdblt r11, {r3, r4, r6, r7, r9, r12, sp} ^
 *   @0x2a88c4 movw r3, #0x1b38
 *   @0x2a88c8 strh.w r3, [r4, #0x2d6]
 *   @0x2a88cc movw r3, #0x5b8a
 *   @0x2a88d0 strh.w r3, [r4, #0x2d8]
 *   @0x2a88d4 movw r3, #0x93e
 *   @0x2a88d8 strh.w r3, [r4, #0x2da]
 *   @0x2a88dc pop {r3, r4, r5, r6, r7, pc}
 *   @0x2a88e0 strh r0, [r4, #0x34]
 *   @0x2a88e4 strh r0, [r0]
 *   @0x2a88e8 andeq r4, lr, r8, lsl #3
 *   @0x2a88ec adcs r2, r4
 *
 * ══ §137/146 b2EdgeShape::Clone(b2BlockAllocator*) const  0x2c5280  size 204  51 条（0x2c5280..0x2c534c）
 * @func 0x2c5280 0x2c534c  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2BlockAllocator::Allocate(int)
 * 字段偏移 top8: 0x4×3 / 0x8×3 / 0x2c×3 / 0x2d×3 / 0xa4×1 / 0x1c×1 / 0x20×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c5280 push {r4, r5, r6, r7, r8, lr}
 *   @0x2c5284 mov r4, r0
 *   @0x2c5288 mov r0, r1
 *   @0x2c528c mov r1, #48
 *   @0x2c5290 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2c5294 subs r3, r0, #0
 *   @0x2c5298 beq 0x2c52e0 <_ZNK11b2EdgeShape5CloneEP16b2BlockAllocator+0x60>
 *   @0x2c529c ldr r2, [pc, #0xa4]
 *   @0x2c52a0 mov r1, #1
 *   @0x2c52a4 movw r0, #0xd70a
 *   @0x2c52a8 str r1, [r3, #0x4]
 *   @0x2c52ac ldr r2, [pc, r2]
 *   @0x2c52b0 movt r0, #0x3c23
 *   @0x2c52b4 add r1, r2, #8
 *   @0x2c52b8 str r0, [r3, #0x8]
 *   @0x2c52bc mov r2, #0
 *   @0x2c52c0 str r1, [r3]
 *   @0x2c52c4 str r2, [r3, #0x1c]
 *   @0x2c52c8 str r2, [r3, #0x20]
 *   @0x2c52cc str r2, [r3, #0x24]
 *   @0x2c52d0 str r2, [r3, #0x28]
 *   @0x2c52d4 mov r2, #0
 *   @0x2c52d8 strb r2, [r3, #0x2c]
 *   @0x2c52dc strb r2, [r3, #0x2d]
 *   @0x2c52e0 add r1, r4, #12
 *   @0x2c52e4 ldr r5, [r4, #0x4]
 *   @0x2c52e8 ldr r6, [r4, #0x8]
 *   @0x2c52ec add r12, r3, #12
 *   @0x2c52f0 ldm r1, {r0, r1}
 *   @0x2c52f4 add r2, r4, #20
 *   @0x2c52f8 str r5, [r3, #0x4]
 *   @0x2c52fc add r7, r3, #20
 *   @0x2c5300 str r6, [r3, #0x8]
 *   @0x2c5304 add r6, r4, #28
 *   @0x2c5308 stm r12, {r0, r1}
 *   @0x2c530c add r12, r4, #36
 *   @0x2c5310 ldm r2, {r0, r1}
 *   @0x2c5314 add r5, r3, #28
 *   @0x2c5318 ldrb r8, [r4, #0x2c]
 *   @0x2c531c add r2, r3, #36
 *   @0x2c5320 ldrb r4, [r4, #0x2d]
 *   @0x2c5324 stm r7, {r0, r1}
 *   @0x2c5328 ldm r6, {r0, r1}
 *   @0x2c532c stm r5, {r0, r1}
 *   @0x2c5330 ldm r12, {r0, r1}
 *   @0x2c5334 stm r2, {r0, r1}
 *   @0x2c5338 mov r0, r3
 *   @0x2c533c strb r8, [r3, #0x2c]
 *   @0x2c5340 strb r4, [r3, #0x2d]
 *   @0x2c5344 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2c5348 andseq r12, r2, r8, lsl #4
 *
 * ══ §138/146 b2Contact::b2Contact(b2Fixture*, int, b2Fixture*, int)  0x2cc120  size 204  51 条（0x2cc120..0x2cc1ec）
 * @func 0x2cc120 0x2cc1ec  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6700
 * 字段偏移 top8: 0x10×2 / 0x34×2 / 0x30×2 / 0xb4×1 / 0x38×1 / 0x4×1 / 0x3c×1 / 0x7c×1
 * VFP 指令 15 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cc120 vldr s15, [r3, #16]
 *   @0x2cc124 vldr s14, [r1, #16]
 *   @0x2cc128 vmul.f32 s14, s14, s15
 *   @0x2cc12c ldr r12, [pc, #0xb4]
 *   @0x2cc130 push {r3, r4, r5, lr}
 *   @0x2cc134 ldr r12, [pc, r12]
 *   @0x2cc138 ldr r5, [sp, #0x10]
 *   @0x2cc13c add r12, r12, #8
 *   @0x2cc140 str r3, [r0, #0x34]
 *   @0x2cc144 mov r4, r0
 *   @0x2cc148 mov r3, #0
 *   @0x2cc14c str r2, [r0, #0x38]
 *   @0x2cc150 str r1, [r0, #0x30]
 *   @0x2cc154 mov r2, #4
 *   @0x2cc158 str r12, [r0]
 *   @0x2cc15c str r2, [r0, #0x4]
 *   @0x2cc160 str r5, [r0, #0x3c]
 *   @0x2cc164 str r3, [r0, #0x7c]
 *   @0x2cc168 str r3, [r0, #0x8]
 *   @0x2cc16c vsqrt.f32 s15, s14
 *   @0x2cc170 str r3, [r0, #0xc]
 *   @0x2cc174 str r3, [r0, #0x14]
 *   @0x2cc178 str r3, [r0, #0x18]
 *   @0x2cc17c str r3, [r0, #0x1c]
 *   @0x2cc180 str r3, [r0, #0x10]
 *   @0x2cc184 str r3, [r0, #0x24]
 *   @0x2cc188 str r3, [r0, #0x28]
 *   @0x2cc18c str r3, [r0, #0x2c]
 *   @0x2cc190 str r3, [r0, #0x20]
 *   @0x2cc194 str r3, [r0, #0x80]
 *   @0x2cc198 vcmp.f32 s15, s15
 *   @0x2cc19c vmrs APSR_nzcv, fpscr
 *   @0x2cc1a0 bne 0x2cc1d8 <_ZN9b2ContactC2EP9b2FixtureiS1_i+0xb8>
 *   @0x2cc1a4 ldr r3, [r4, #0x30]
 *   @0x2cc1a8 vldr s13, [r3, #20]
 *   @0x2cc1ac ldr r3, [r4, #0x34]
 *   @0x2cc1b0 vldr s14, [r3, #20]
 *   @0x2cc1b4 vcmpe.f32 s13, s14
 *   @0x2cc1b8 mov r3, #0
 *   @0x2cc1bc vstr s15, [r4, #136]
 *   @0x2cc1c0 mov r0, r4
 *   @0x2cc1c4 str r3, [r4, #0x90]
 *   @0x2cc1c8 vmrs APSR_nzcv, fpscr
 *   @0x2cc1cc vmovgt.f32 s14, s13
 *   @0x2cc1d0 vstr s14, [r4, #140]
 *   @0x2cc1d4 pop {r3, r4, r5, pc}
 *   @0x2cc1d8 vmov r0, s14
 *   @0x2cc1dc bl 0xb6700 <sqrtf@plt>
 *   @0x2cc1e0 vmov s15, r0
 *   @0x2cc1e4 b 0x2cc1a4 <_ZN9b2ContactC2EP9b2FixtureiS1_i+0x84>
 *   @0x2cc1e8 andseq r5, r2, r12, asr #19
 *
 * ══ §139/146 b2DistanceJointDef::Initialize(b2Body*, b2Body*, b2Vec2 const&, b2Vec2 const&)  0x2cd1e0  size 204  51 条（0x2cd1e0..0x2cd2ac）
 * @func 0x2cd1e0 0x2cd2ac  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6700
 * 字段偏移 top8: 0x8×2 / 0xc×1
 * VFP 指令 42 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cd1e0 vldr s15, [r1, #16]
 *   @0x2cd1e4 vldr s14, [r3, #4]
 *   @0x2cd1e8 vsub.f32 s14, s14, s15
 *   @0x2cd1ec vldr s9, [r1, #20]
 *   @0x2cd1f0 vldr s8, [r1, #24]
 *   @0x2cd1f4 vldr s6, [r3]
 *   @0x2cd1f8 vldr s10, [r1, #12]
 *   @0x2cd1fc push {r4, lr}
 *   @0x2cd200 vldr s12, [r2, #20]
 *   @0x2cd204 vldr s11, [r2, #24]
 *   @0x2cd208 mov r4, r0
 *   @0x2cd20c vldr s15, [r2, #16]
 *   @0x2cd210 vldr s7, [r2, #12]
 *   @0x2cd214 ldr r0, [sp, #0x8]
 *   @0x2cd218 str r1, [r4, #0x8]
 *   @0x2cd21c str r2, [r4, #0xc]
 *   @0x2cd220 vmul.f32 s13, s14, s9
 *   @0x2cd224 vmul.f32 s14, s14, s8
 *   @0x2cd228 vsub.f32 s10, s6, s10
 *   @0x2cd22c vmla.f32 s13, s10, s8
 *   @0x2cd230 vmls.f32 s14, s9, s10
 *   @0x2cd234 vstr s13, [r4, #20]
 *   @0x2cd238 vstr s14, [r4, #24]
 *   @0x2cd23c vldr s14, [r0, #4]
 *   @0x2cd240 vsub.f32 s15, s14, s15
 *   @0x2cd244 vldr s13, [r0]
 *   @0x2cd248 vmul.f32 s14, s15, s12
 *   @0x2cd24c vmul.f32 s15, s15, s11
 *   @0x2cd250 vsub.f32 s13, s13, s7
 *   @0x2cd254 vmla.f32 s14, s13, s11
 *   @0x2cd258 vmls.f32 s15, s12, s13
 *   @0x2cd25c vstr s14, [r4, #28]
 *   @0x2cd260 vstr s15, [r4, #32]
 *   @0x2cd264 vldr s15, [r3, #4]
 *   @0x2cd268 vldr s14, [r0, #4]
 *   @0x2cd26c vsub.f32 s14, s14, s15
 *   @0x2cd270 vldr s13, [r0]
 *   @0x2cd274 vldr s15, [r3]
 *   @0x2cd278 vmul.f32 s14, s14, s14
 *   @0x2cd27c vsub.f32 s15, s13, s15
 *   @0x2cd280 vmla.f32 s14, s15, s15
 *   @0x2cd284 vsqrt.f32 s15, s14
 *   @0x2cd288 vcmp.f32 s15, s15
 *   @0x2cd28c vmrs APSR_nzcv, fpscr
 *   @0x2cd290 bne 0x2cd29c <_ZN18b2DistanceJointDef10InitializeEP6b2BodyS1_RK6b2Vec2S4_+0xbc>
 *   @0x2cd294 vstr s15, [r4, #36]
 *   @0x2cd298 pop {r4, pc}
 *   @0x2cd29c vmov r0, s14
 *   @0x2cd2a0 bl 0xb6700 <sqrtf@plt>
 *   @0x2cd2a4 vmov s15, r0
 *   @0x2cd2a8 b 0x2cd294 <_ZN18b2DistanceJointDef10InitializeEP6b2BodyS1_RK6b2Vec2S4_+0xb4>
 *
 * ══ §140/146 b2WheelJoint::b2WheelJoint(b2WheelJointDef const*)  0x2d4214  size 204  51 条（0x2d4214..0x2d42e0）
 * @func 0x2d4214 0x2d42e0  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Joint::b2Joint(b2JointDef const*)
 * 字段偏移 top8: 0xac×2 / 0x4c×1 / 0x30×1 / 0x2c×1 / 0x34×1 / 0x38×1 / 0x3c×1 / 0x5c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d4214 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2d4218 mov r4, r0
 *   @0x2d421c mov r5, r1
 *   @0x2d4220 bl 0x2cdee0 <_ZN7b2JointC2EPK10b2JointDef>
 *   @0x2d4224 add r3, r5, #20
 *   @0x2d4228 ldr r2, [pc, #0xac]
 *   @0x2d422c add r6, r5, #28
 *   @0x2d4230 add r12, r4, #84
 *   @0x2d4234 ldm r3, {r0, r1}
 *   @0x2d4238 ldr r2, [pc, r2]
 *   @0x2d423c mov r3, r4
 *   @0x2d4240 add r2, r2, #8
 *   @0x2d4244 str r2, [r3], #76
 *   @0x2d4248 add r2, r4, #92
 *   @0x2d424c stm r3, {r0, r1}
 *   @0x2d4250 add r3, r5, #36
 *   @0x2d4254 ldm r6, {r0, r1}
 *   @0x2d4258 ldr r9, [r5, #0x30]
 *   @0x2d425c ldrb r6, [r5, #0x2c]
 *   @0x2d4260 ldr r8, [r5, #0x34]
 *   @0x2d4264 ldr r7, [r5, #0x38]
 *   @0x2d4268 stm r12, {r0, r1}
 *   @0x2d426c ldm r3, {r0, r1}
 *   @0x2d4270 mov r3, #0
 *   @0x2d4274 ldr r12, [r5, #0x3c]
 *   @0x2d4278 stm r2, {r0, r1}
 *   @0x2d427c vldr s15, [r4, #96]
 *   @0x2d4280 vneg.f32 s15, s15
 *   @0x2d4284 ldr r2, [r4, #0x5c]
 *   @0x2d4288 str r9, [r4, #0x78]
 *   @0x2d428c mov r0, r4
 *   @0x2d4290 str r8, [r4, #0x7c]
 *   @0x2d4294 str r2, [r4, #0x68]
 *   @0x2d4298 strb r6, [r4, #0x80]
 *   @0x2d429c vstr s15, [r4, #100]
 *   @0x2d42a0 str r7, [r4, #0x44]
 *   @0x2d42a4 str r3, [r4, #0xcc]
 *   @0x2d42a8 str r3, [r4, #0x6c]
 *   @0x2d42ac str r3, [r4, #0xd0]
 *   @0x2d42b0 str r3, [r4, #0x70]
 *   @0x2d42b4 str r3, [r4, #0xd4]
 *   @0x2d42b8 str r3, [r4, #0x74]
 *   @0x2d42bc str r12, [r4, #0x48]
 *   @0x2d42c0 str r3, [r4, #0xd8]
 *   @0x2d42c4 str r3, [r4, #0xdc]
 *   @0x2d42c8 str r3, [r4, #0xac]
 *   @0x2d42cc str r3, [r4, #0xb0]
 *   @0x2d42d0 str r3, [r4, #0xb4]
 *   @0x2d42d4 str r3, [r4, #0xb8]
 *   @0x2d42d8 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2d42dc andseq sp, r1, r4, asr #18
 *
 * ══ §141/146 anon_2d48c0  0x2d48c0  size 204  51 条（0x2d48c0..0x2d498c）
 * @func 0x2d48c0 0x2d498c  size 204  51 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2d48c0+0x80×2
 * 字段偏移 top8: 0xc×3 / 0x8×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d48c0 mov r0, #0
 *   @0x2d48c4 bx lr
 *   @0x2d48c8 ldr r0, [r0, #0x8]
 *   @0x2d48cc ubfx r0, r0, #0x1, #0x1
 *   @0x2d48d0 bx lr
 *   @0x2d48d4 ldr r0, [r0]
 *   @0x2d48d8 lsr r0, r0, #31
 *   @0x2d48dc bx lr
 *   @0x2d48e0 ldr r3, [r0]
 *   @0x2d48e4 cmp r3, #0
 *   @0x2d48e8 ldrge r0, [r0, #0x4]
 *   @0x2d48ec lsrge r0, r0, #31
 *   @0x2d48f0 movlt r0, #1
 *   @0x2d48f4 bx lr
 *   @0x2d48f8 ldr r0, [r0]
 *   @0x2d48fc lsr r0, r0, #31
 *   @0x2d4900 bx lr
 *   @0x2d4904 ldr r3, [r0]
 *   @0x2d4908 cmp r3, #0
 *   @0x2d490c ldrge r0, [r0, #0x4]
 *   @0x2d4910 lsrge r0, r0, #31
 *   @0x2d4914 movlt r0, #1
 *   @0x2d4918 bx lr
 *   @0x2d491c ldr r3, [r0]
 *   @0x2d4920 cmp r3, #0
 *   @0x2d4924 blt 0x2d4940 <_ZN15b2QueryCallback14ReportParticleEi+0x88>
 *   @0x2d4928 ldr r3, [r0, #0x4]
 *   @0x2d492c cmp r3, #0
 *   @0x2d4930 blt 0x2d4940 <_ZN15b2QueryCallback14ReportParticleEi+0x88>
 *   @0x2d4934 ldr r0, [r0, #0x8]
 *   @0x2d4938 lsr r0, r0, #31
 *   @0x2d493c bx lr
 *   @0x2d4940 mov r0, #1
 *   @0x2d4944 bx lr
 *   @0x2d4948 ldr r3, [pc, #0xc]
 *   @0x2d494c ldr r3, [pc, r3]
 *   @0x2d4950 add r3, r3, #8
 *   @0x2d4954 str r3, [r0]
 *   @0x2d4958 bx lr
 *   @0x2d495c andseq sp, r1, r4, lsr r2
 *   @0x2d4960 ldr r3, [pc, #0xc]
 *   @0x2d4964 ldr r3, [pc, r3]
 *   @0x2d4968 add r3, r3, #8
 *   @0x2d496c str r3, [r0]
 *   @0x2d4970 bx lr
 *   @0x2d4974 andseq sp, r1, r12, lsl r2
 *   @0x2d4978 ldr r3, [pc, #0xc]
 *   @0x2d497c ldr r3, [pc, r3]
 *   @0x2d4980 add r3, r3, #8
 *   @0x2d4984 str r3, [r0]
 *   @0x2d4988 bx lr
 *
 * ══ §142/146 FT_Outline_Get_Orientation  0x2e65a4  size 204  51 条（0x2e65a4..0x2e6670）
 * @func 0x2e65a4 0x2e6670  size 204  51 条
 * 部分覆盖: 本节 51/90 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2f1de8+0x7dc / FT_Outline_Get_Orientation+0xa / FT_Outline_Get_CBox / 0xff1e95f0 / 0xff125820 / 0x4a4a50 / 0xff564270 / 0x568a72
 * 字段偏移 top8: 0x4×3 / 0x8×1 / 0xc×1 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e65a4 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2e65a8 mov r4, r0
 *   @0x2e65ac cbnz r0, 0x2e65b2 <FT_Outline_Get_Orientation+0xe>
 *   @0x2e65b0 b 0x2e666a <FT_Outline_Get_Orientation+0xc6>
 *   @0x2e65b4 blhs 0x2f25c4 <ps_hints_apply+0x11c4>
 *   @0x2e65b8 ble 0x2e65ae <FT_Outline_Get_Orientation+0xa>
 *   @0x2e65bc bl 0x2e63cc <FT_Outline_Get_CBox>
 *   @0x2e65c0 ldr r0, [sp, #0x8]
 *   @0x2e65c4 cmp r0, r1
 *   @0x2e65c8 ldr r3, [sp, #0xc]
 *   @0x2e65cc cmp r3, r2
 *   @0x2e65d0 eor.w r12, r0, r0, asr #31
 *   @0x2e65d4 sub.w r12, r12, r0, asr #31
 *   @0x2e65d8 cmp r1, #0x0
 *   @0x2e65dc rsblt r1, r1, #0
 *   @0x2e65e0 b 0x15e85f0 <b2_toiTime+0xe8f14c>
 *   @0x2e65e4 blx 0xff1e95f0 <b2_toiTime+0xfffffffffea9014c>
 *   @0x2e65e8 blx 0xff125820 <b2_toiTime+0xfffffffffe9cc37c>
 *   @0x2e65ec .word 0xf1ccf888
 *   @0x2e65f0 .word 0xf1c80c11
 *   @0x2e65f4 rfeib r4!
 *   @0x2e65f8 movwhs r0, #0x0
 *   @0x2e65fc ldr r6, [r4, #0x4]
 *   @0x2e6600 b 0xd059b8 <b2_toiTime+0x5ac514>
 *   @0x2e6604 ldrmi r7, [r10], -r8, ror #17
 *   @0x2e6608 mov r1, r3
 *   @0x2e660c ldr r0, [sp, #0x4]
 *   @0x2e6610 bge 0x2e665e <FT_Outline_Get_Orientation+0xba>
 *   @0x2e6614 ldrsh.w r0, [r0, r1, lsl #1]
 *   @0x2e6618 ldr.w r5, [r6, r0, lsl #3]
 *   @0x2e661c add.w r7, r6, r0, lsl #3
 *   @0x2e6620 asr.w r10, r5, r12
 *   @0x2e6624 ldr r5, [r7, #0x4]
 *   @0x2e6628 bl 0x4a4a50 <SrcVerts+0x1a94>
 *   @0x2e662c addmi r0, r2, #813694976
 *   @0x2e6630 add.w r5, r5, #0x8
 *   @0x2e6634 bgt 0x2e6658 <FT_Outline_Get_Orientation+0xb4>
 *   @0x2e6638 andlo r7, r1, #8, #24
 *   @0x2e663c asr.w r11, r7, r12
 *   @0x2e6640 ldr r7, [r5, #-4]
 *   @0x2e6644 add r10, r11
 *   @0x2e6648 bl 0xff564270 <b2_toiTime+0xfffffffffee0adcc>
 *   @0x2e664c blx 0x568a72 <g_SWFlineaavertbuff+0x159aa>
 *   @0x2e6650 ldrtmi r3, [r9], r9, lsl #6
 *   @0x2e6654 mov r10, r11
 *   @0x2e6658 adds r2, r0, #0x1
 *   @0x2e665c b 0x2e660c <FT_Outline_Get_Orientation+0x68>
 *   @0x2e6660 bgt 0x2e6668 <FT_Outline_Get_Orientation+0xc4>
 *   @0x2e6664 movs r0, #0x2
 *   @0x2e6668 movs r0, #0x1
 *   @0x2e666c pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §143/146 CSkeletonInstance::GetFrames(char*) const  0xc0930  size 200  43 条（0xc0930..0xc09f8）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0xc0930 0xc09f8  size 200  43 条
 * 部分覆盖: 本节 43/50 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xc0950→0x5428e8, 0xc0964→0x54298c, 0xc0998→0x5428c0, 0xc09b4→0x3eb70c
 * 调用序列: spSkeletonData_findAnimation / CTimingSource::GetFPS()
 * 字段偏移 top8: 0x30×2 / 0x98×1 / 0x8c×1 / 0x7c×1 / 0x4c×1 / 0x34×1 / 0xc×1
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc0930 push {r3, r4, r5, lr}
 *   @0xc0934 mov r5, r1
 *   @0xc0938 ldr r0, [r0, #0x30]
 *   @0xc093c bl 0x28b1dc <spSkeletonData_findAnimation>
 *   @0xc0940 ldr r3, [pc, #0x98]
 *   @0xc0944 add r3, pc, r3
 *   @0xc0964 ldr r2, [pc, #0x7c]
 *   @0xc0968 ldr r3, [r3, r2]
 *   @0xc096c ldr r3, [r3]
 *   @0xc0970 cmp r3, #0
 *   @0xc0974 vldrne s13, [r3, #12]
 *   @0xc0978 vmoveq.f32 s13, #3.000000e+01
 *   @0xc097c vcvtne.f32.s32 s13, s13
 *   @0xc0980 vldr s14, [r4, #4]
 *   @0xc0984 vmov.f32 s15, #5.000000e-01
 *   @0xc0988 vmla.f32 s15, s13, s14
 *   @0xc098c vcvt.s32.f32 s15, s15
 *   @0xc0990 vmov r0, s15
 *   @0xc0994 pop {r3, r4, r5, pc}
 *   @0xc0998 ldr r2, [pc, #0x4c]
 *   @0xc099c ldr r0, [r3, r2]
 *   @0xc09a0 bl 0x214808 <_ZN13CTimingSource6GetFPSEv>
 *   @0xc09a4 vmov d7, r0, r1
 *   @0xc09a8 vcvt.s32.f64 s13, d7
 *   @0xc09ac vcvt.f32.s32 s13, s13
 *   @0xc09b0 b 0xc0980 <_ZNK17CSkeletonInstance9GetFramesEPc+0x50>
 *   @0xc09b4 ldr r0, [pc, #0x34]
 *   @0xc09b8 mov r2, r5
 *   @0xc09bc ldr r1, [pc, #0x30]
 *   @0xc09c0 ldr r3, [r3, r0]
 *   @0xc09c4 add r1, pc, r1
 *   @0xc09c8 ldr r0, [r3]
 *   @0xc09cc ldr r3, [r0]
 *   @0xc09d0 ldr r3, [r3, #0xc]
 *   @0xc09d4 blx r3
 *   @0xc09d8 mov r0, r4
 *   @0xc09dc pop {r3, r4, r5, pc}
 *   @0xc09e0 eorseq r1, r3, r12, lsl #6
 *   @0xc09e4 .word 0xffffbcd4
 *   @0xc09e8 .word 0xffffbcd8
 *   @0xc09ec .word 0xffffbcdc
 *   @0xc09f0 .word 0xffffbac4
 *   @0xc09f4 eoreq pc, r6, r0, asr #30
 *
 * ══ §144/146 F_BUFFER_Fill(RValue&, CInstance*, CInstance*, int, RValue*)  0xc57c0  size 200  50 条（0xc57c0..0xc5888）
 * @func 0xc57c0 0xc5888  size 200  50 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×4 / F_BUFFER_Fill(RValue&, CInstance*, CInstance*, int, RValue*)+0xa8
 * 字段偏移 top8: 0x28×1 / 0x98×1 / 0x4×1 / 0x2×1 / 0x3c×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc57c0 push {r4, r5, r6, r7, r8, lr}
 *   @0xc57c4 sub sp, sp, #16
 *   @0xc57c8 mov r1, #0
 *   @0xc57cc ldr r4, [sp, #0x28]
 *   @0xc57d0 mov r0, r4
 *   @0xc57d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc57d8 cmp r0, #0
 *   @0xc57dc blt 0xc5868 <_Z13F_BUFFER_FillR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0xc57e0 ldr r3, [pc, #0x98]
 *   @0xc57e4 add r3, pc, r3
 *   @0xc57e8 ldr r2, [r3]
 *   @0xc57ec cmp r0, r2
 *   @0xc57f0 bge 0xc5868 <_Z13F_BUFFER_FillR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0xc57f4 ldr r3, [r3, #0x4]
 *   @0xc57f8 ldr r5, [r3, r0, lsl #2]
 *   @0xc57fc cmp r5, #0
 *   @0xc5800 beq 0xc5868 <_Z13F_BUFFER_FillR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0xc5804 ldr r3, [r5]
 *   @0xc5808 mov r0, r4
 *   @0xc580c mov r1, #1
 *   @0xc5810 ldr r6, [r3, #0x3c]
 *   @0xc5814 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc5818 mov r1, #4
 *   @0xc581c mov r8, r0
 *   @0xc5820 mov r0, r4
 *   @0xc5824 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc5828 mov r1, #2
 *   @0xc582c mov r7, r0
 *   @0xc5830 mov r0, r4
 *   @0xc5834 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc5838 add r4, r4, #48
 *   @0xc583c mvn r12, #0
 *   @0xc5840 mov lr, #1
 *   @0xc5844 mov r1, r8
 *   @0xc5848 mov r2, r7
 *   @0xc584c str r4, [sp]
 *   @0xc5850 stmib sp, {r12, lr}
 *   @0xc5854 mov r3, r0
 *   @0xc5858 mov r0, r5
 *   @0xc585c blx r6
 *   @0xc5860 add sp, sp, #16
 *   @0xc5864 pop {r4, r5, r6, r7, r8, pc}
 *   @0xc5868 ldr r0, [pc, #0x14]
 *   @0xc586c mov r1, #0
 *   @0xc5870 add r0, pc, r0
 *   @0xc5874 add sp, sp, #16
 *   @0xc5878 pop {r4, r5, r6, r7, r8, lr}
 *   @0xc587c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xc5880 eorseq r4, r11, r0, lsr r9
 *   @0xc5884 eoreq r11, r6, r4, asr #6
 *
 * ══ §145/146 CSkeletonInstance::GetDuration(char*) const  0xc08c8  size 104  24 条（0xc08c8..0xc0930）
 * @func 0xc08c8 0xc0940  size 120  28 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeletonData_findAnimation
 * 字段偏移 top8: 0x30×2 / 0x2c×1 / 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc08c8 push {r4, lr}
 *   @0xc08cc mov r4, r1
 *   @0xc08d0 ldr r0, [r0, #0x30]
 *   @0xc08d4 bl 0x28b1dc <spSkeletonData_findAnimation>
 *   @0xc08d8 cmp r0, #0
 *   @0xc08dc beq 0xc08f0 <_ZNK17CSkeletonInstance11GetDurationEPc+0x28>
 *   @0xc08e0 vldr s14, [r0, #4]
 *   @0xc08e4 vcvt.f64.f32 d7, s14
 *   @0xc08e8 vmov r0, r1, d7
 *   @0xc08ec pop {r4, pc}
 *   @0xc08f0 ldr r3, [pc, #0x30]
 *   @0xc08f4 mov r2, r4
 *   @0xc08f8 ldr r1, [pc, #0x2c]
 *   @0xc08fc ldr r3, [pc, r3]
 *   @0xc0900 add r1, pc, r1
 *   @0xc0904 ldr r0, [r3]
 *   @0xc0908 ldr r3, [r0]
 *   @0xc090c ldr r3, [r3, #0xc]
 *   @0xc0910 blx r3
 *   @0xc0914 vldr d7, [pc, #4]
 *   @0xc0918 b 0xc08e8 <_ZNK17CSkeletonInstance11GetDurationEPc+0x20>
 *   @0xc091c nop
 *   @0xc0928 eorseq r12, r2, r8, lsl lr
 *   @0xc092c eoreq r0, r7, r4
 *
 * ══ §146/146 FINALIZE_Code_Variable()  0xd2618  size 4  1 条（0xd2618..0xd261c）
 * @func 0xd2618 0xd261c  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd2618 bx lr
 */
