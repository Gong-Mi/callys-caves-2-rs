/* cally 逆向卡：All_37 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 43 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/43 F_PhysicsCreateRevoluteJoint(RValue&, CInstance*, CInstance*, int, RValue*)  0x14f1d0  size 728  182 条（0x14f1d0..0x14f4a8）
 * @func 0x14f1d0 0x14f4a8  size 728  182 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x14f274→0x54298c, 0x14f3b0→0x54298c
 * 调用序列: YYGetFloat(RValue const*, int)×6 / YYGetInt32(RValue const*, int)×4 / Error_Show_Action(char const*, bool)×4 / YYGetBool(RValue const*, int)×3 / Object_GetInstance(int, CInstance*, CInstance*)×2 / 0xb65b0×2 / 0xb65c8×2 / CPhysicsWorld::CreateRevoluteJoint(CPhysicsObject*, CPhysicsObject*, float, float, float, float, bool, float, float, bool, bool)
 * 字段偏移 top8: 0xc×2 / 0x134×2 / 0x84×2 / 0xb4×2 / 0x20×2 / 0x24×2 / 0x28×2 / 0x2c×2
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14f1d0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x14f1d4 vpush {d8}
 *   @0x14f1d8 sub sp, sp, #316
 *   @0x14f1dc ldr r9, [pc, #0x2a8]
 *   @0x14f1e0 mov r7, r2
 *   @0x14f1e4 ldr r12, [pc, #0x2a4]
 *   @0x14f1e8 mov r3, #0
 *   @0x14f1ec add r9, pc, r9
 *   @0x14f1f0 ldr r4, [sp, #0x168]
 *   @0x14f1f4 mov r5, r0
 *   @0x14f1f8 mov r8, r1
 *   @0x14f1fc ldr r6, [r9, r12]
 *   @0x14f200 mov r0, r3
 *   @0x14f204 mov r1, r3
 *   @0x14f208 movt r0, #0xbff0
 *   @0x14f20c str r3, [r5, #0xc]
 *   @0x14f210 ldr r2, [r6]
 *   @0x14f214 str r0, [r5, #0x4]
 *   @0x14f218 mov r0, r4
 *   @0x14f21c str r3, [r5]
 *   @0x14f220 str r2, [sp, #0x134]
 *   @0x14f224 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14f228 mov r1, r8
 *   @0x14f22c mov r2, r7
 *   @0x14f230 bl 0x14ec2c <_Z18Object_GetInstanceiP9CInstanceS0_>
 *   @0x14f234 subs r10, r0, #0
 *   @0x14f238 beq 0x14f3f0 <_Z28F_PhysicsCreateRevoluteJointR6RValueP9CInstanceS2_iPS_+0x220>
 *   @0x14f23c mov r1, #1
 *   @0x14f240 mov r0, r4
 *   @0x14f244 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14f248 mov r1, r8
 *   @0x14f24c mov r2, r7
 *   @0x14f250 bl 0x14ec2c <_Z18Object_GetInstanceiP9CInstanceS0_>
 *   @0x14f254 subs r8, r0, #0
 *   @0x14f258 beq 0x14f438 <_Z28F_PhysicsCreateRevoluteJointR6RValueP9CInstanceS2_iPS_+0x268>
 *   @0x14f25c ldr r7, [r10, #0x84]
 *   @0x14f260 cmp r7, #0
 *   @0x14f264 beq 0x14f3b0 <_Z28F_PhysicsCreateRevoluteJointR6RValueP9CInstanceS2_iPS_+0x1e0>
 *   @0x14f268 ldr r8, [r8, #0x84]
 *   @0x14f26c cmp r8, #0
 *   @0x14f270 beq 0x14f3b0 <_Z28F_PhysicsCreateRevoluteJointR6RValueP9CInstanceS2_iPS_+0x1e0>
 *   @0x14f274 ldr r3, [pc, #0x218]
 *   @0x14f278 ldr r3, [r9, r3]
 *   @0x14f27c ldr r3, [r3]
 *   @0x14f280 ldr r9, [r3, #0xb4]
 *   @0x14f284 cmp r9, #0
 *   @0x14f288 beq 0x14f3dc <_Z28F_PhysicsCreateRevoluteJointR6RValueP9CInstanceS2_iPS_+0x20c>
 *   @0x14f28c mov r1, #2
 *   @0x14f290 mov r0, r4
 *   @0x14f294 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14f298 mov r1, #3
 *   @0x14f29c mov r3, r0
 *   @0x14f2a0 mov r0, r4
 *   @0x14f2a4 str r3, [sp, #0x20]
 *   @0x14f2a8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14f2ac mov r1, #4
 *   @0x14f2b0 mov r12, r0
 *   @0x14f2b4 mov r0, r4
 *   @0x14f2b8 str r12, [sp, #0x24]
 *   @0x14f2bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14f2c0 mov r1, #5
 *   @0x14f2c4 vmov s17, r0
 *   @0x14f2c8 mov r0, r4
 *   @0x14f2cc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14f2d0 mov r1, #6
 *   @0x14f2d4 vmov s16, r0
 *   @0x14f2d8 mov r0, r4
 *   @0x14f2dc bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x14f2e0 mov r1, #7
 *   @0x14f2e4 mov r2, r0
 *   @0x14f2e8 mov r0, r4
 *   @0x14f2ec str r2, [sp, #0x28]
 *   @0x14f2f0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14f2f4 mov r1, #8
 *   @0x14f2f8 str r0, [sp, #0x2c]
 *   @0x14f2fc mov r0, r4
 *   @0x14f300 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14f304 mov r1, #9
 *   @0x14f308 mov r11, r0
 *   @0x14f30c mov r0, r4
 *   @0x14f310 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x14f314 mov r1, #10
 *   @0x14f318 mov r10, r0
 *   @0x14f31c mov r0, r4
 *   @0x14f320 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x14f324 vldr s14, [pc, #344]
 *   @0x14f328 vmul.f32 s17, s17, s14
 *   @0x14f32c vldr s15, [pc, #340]
 *   @0x14f330 ldr r2, [sp, #0x28]
 *   @0x14f334 mov r1, r7
 *   @0x14f338 ldr r12, [sp, #0x24]
 *   @0x14f33c ldr r3, [sp, #0x20]
 *   @0x14f340 str r2, [sp, #0xc]
 *   @0x14f344 ldr r2, [sp, #0x2c]
 *   @0x14f348 str r12, [sp]
 *   @0x14f34c str r11, [sp, #0x14]
 *   @0x14f350 str r2, [sp, #0x10]
 *   @0x14f354 mov r2, r8
 *   @0x14f358 str r10, [sp, #0x18]
 *   @0x14f35c vmul.f32 s14, s16, s14
 *   @0x14f360 vdiv.f32 s17, s17, s15
 *   @0x14f364 str r0, [sp, #0x1c]
 *   @0x14f368 mov r0, r9
 *   @0x14f36c vdiv.f32 s15, s14, s15
 *   @0x14f370 vstr s17, [sp, #4]
 *   @0x14f374 vstr s15, [sp, #8]
 *   @0x14f378 bl 0x239050 <_ZN13CPhysicsWorld19CreateRevoluteJointEP14CPhysicsObjectS1_ffffbffbb>
 *   @0x14f37c vmov s15, r0
 *   @0x14f380 vcvt.f64.s32 d7, s15
 *   @0x14f384 vmov r0, r1, d7
 *   @0x14f388 vmov r2, s14
 *   @0x14f38c mov r3, r1
 *   @0x14f390 stm r5, {r2, r3}
 *   @0x14f394 ldr r2, [sp, #0x134]
 *   @0x14f398 ldr r3, [r6]
 *   @0x14f39c cmp r2, r3
 *   @0x14f3a0 bne 0x14f480 <_Z28F_PhysicsCreateRevoluteJointR6RValueP9CInstanceS2_iPS_+0x2b0>
 *   @0x14f3a4 add sp, sp, #316
 *   @0x14f3a8 vpop {d8}
 *   @0x14f3ac pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x14f3b0 ldr r3, [pc, #0xdc]
 *   @0x14f3b4 ldr r3, [r9, r3]
 *   @0x14f3b8 ldr r3, [r3]
 *   @0x14f3bc ldr r3, [r3, #0xb4]
 *   @0x14f3c0 cmp r3, #0
 *   @0x14f3c4 beq 0x14f3dc <_Z28F_PhysicsCreateRevoluteJointR6RValueP9CInstanceS2_iPS_+0x20c>
 *   @0x14f3c8 ldr r0, [pc, #0xc8]
 *   @0x14f3cc mov r1, #0
 *   @0x14f3d0 add r0, pc, r0
 *   @0x14f3d4 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14f3d8 b 0x14f394 <_Z28F_PhysicsCreateRevoluteJointR6RValueP9CInstanceS2_iPS_+0x1c4>
 *   @0x14f3dc ldr r0, [pc, #0xb8]
 *   @0x14f3e0 mov r1, #0
 *   @0x14f3e4 add r0, pc, r0
 *   @0x14f3e8 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14f3ec b 0x14f394 <_Z28F_PhysicsCreateRevoluteJointR6RValueP9CInstanceS2_iPS_+0x1c4>
 *   @0x14f3f0 add r5, sp, #52
 *   @0x14f3f4 mov r1, r10
 *   @0x14f3f8 mov r2, #256
 *   @0x14f3fc mov r0, r5
 *   @0x14f400 bl 0xb65b0 <memset@plt>
 *   @0x14f404 mov r1, r10
 *   @0x14f408 mov r0, r4
 *   @0x14f40c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14f410 ldr r2, [pc, #0x88]
 *   @0x14f414 mov r1, #256
 *   @0x14f418 add r2, pc, r2
 *   @0x14f41c mov r3, r0
 *   @0x14f420 mov r0, r5
 *   @0x14f424 bl 0xb65c8 <snprintf@plt>
 *   @0x14f428 mov r0, r5
 *   @0x14f42c mov r1, r10
 *   @0x14f430 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14f434 b 0x14f394 <_Z28F_PhysicsCreateRevoluteJointR6RValueP9CInstanceS2_iPS_+0x1c4>
 *   @0x14f438 add r5, sp, #52
 *   @0x14f43c mov r1, r8
 *   @0x14f440 mov r2, #256
 *   @0x14f444 mov r0, r5
 *   @0x14f448 bl 0xb65b0 <memset@plt>
 *   @0x14f44c mov r0, r4
 *   @0x14f450 mov r1, #1
 *   @0x14f454 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14f458 ldr r2, [pc, #0x44]
 *   @0x14f45c mov r1, #256
 *   @0x14f460 add r2, pc, r2
 *   @0x14f464 mov r3, r0
 *   @0x14f468 mov r0, r5
 *   @0x14f46c bl 0xb65c8 <snprintf@plt>
 *   @0x14f470 mov r0, r5
 *   @0x14f474 mov r1, r8
 *   @0x14f478 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14f47c b 0x14f394 <_Z28F_PhysicsCreateRevoluteJointR6RValueP9CInstanceS2_iPS_+0x1c4>
 *   @0x14f480 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x14f484 ldrdmi r0, r1, [r9], #-251
 *   @0x14f488 teqmi r4, #0
 *   @0x14f48c eoreq r2, r10, r4, ror #20
 *   @0x14f490 .word 0xffffbd00
 *   @0x14f494 .word 0xffffbcd8
 *   @0x14f498 andseq r5, pc, r12, lsr #21
 *   @0x14f49c andseq r4, pc, r0, asr #20
 *   @0x14f4a0 andseq r5, pc, r8, lsl #19
 *   @0x14f4a4 andseq r5, pc, r0, asr #18
 *
 * ══ §2/43 CSprite::GenerateBitmapData()  0x1e65d8  size 728  182 条（0x1e65d8..0x1e68b0）
 * @func 0x1e65d8 0x1e68b0  size 728  182 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __divsi3×4 / MemoryManager::SetLength(void**, unsigned int, char const*, int) / CSprite::GenerateBitmapData()+0x2c4 / Graphics::Texture_GrabRect(void*, int, int, int, int) / IBitmap::Create() / 0xb65b0 / CSprite::GenerateBitmapData()+0x25c / 0xb65bc
 * 字段偏移 top8: 0x18×8 / 0x2×8 / 0x1c×8 / 0x54×6 / 0x4×5 / 0x48×3 / 0xc×3 / 0x14×2
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e65d8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1e65dc mov r11, r0
 *   @0x1e65e0 ldr r4, [r0, #0x74]
 *   @0x1e65e4 sub sp, sp, #36
 *   @0x1e65e8 cmp r4, #0
 *   @0x1e65ec beq 0x1e65fc <_ZN7CSprite18GenerateBitmapDataEv+0x24>
 *   @0x1e65f0 mov r0, #0
 *   @0x1e65f4 add sp, sp, #36
 *   @0x1e65f8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e65fc ldr r1, [r0, #0x18]
 *   @0x1e6600 movw r3, #0xc3d
 *   @0x1e6604 ldr r2, [pc, #0x29c]
 *   @0x1e6608 add r0, r0, #72
 *   @0x1e660c add r2, pc, r2
 *   @0x1e6610 lsl r1, r1, #2
 *   @0x1e6614 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1e6618 ldr r3, [r11, #0x48]
 *   @0x1e661c cmp r3, #0
 *   @0x1e6620 beq 0x1e6644 <_ZN7CSprite18GenerateBitmapDataEv+0x6c>
 *   @0x1e6624 ldr r0, [r3]
 *   @0x1e6628 cmp r0, #0
 *   @0x1e662c beq 0x1e6644 <_ZN7CSprite18GenerateBitmapDataEv+0x6c>
 *   @0x1e6630 ldr r3, [r0]
 *   @0x1e6634 ldr r3, [r3, #0x4]
 *   @0x1e6638 blx r3
 *   @0x1e663c ldr r3, [r11, #0x48]
 *   @0x1e6640 str r4, [r3]
 *   @0x1e6644 ldr r3, [r11, #0x18]
 *   @0x1e6648 cmp r3, #0
 *   @0x1e664c ble 0x1e689c <_ZN7CSprite18GenerateBitmapDataEv+0x2c4>
 *   @0x1e6650 ldr r1, [pc, #0x254]
 *   @0x1e6654 mov r5, #0
 *   @0x1e6658 mov r8, r5
 *   @0x1e665c add r2, sp, #28
 *   @0x1e6660 add r3, sp, #24
 *   @0x1e6664 ldr r1, [pc, r1]
 *   @0x1e6668 str r2, [sp, #0x10]
 *   @0x1e666c str r3, [sp, #0x14]
 *   @0x1e6670 str r1, [sp, #0xc]
 *   @0x1e6674 ldr r2, [r11, #0x54]
 *   @0x1e6678 lsl r6, r5, #2
 *   @0x1e667c ldr r1, [sp, #0xc]
 *   @0x1e6680 ldr r0, [r2, r5, lsl #2]
 *   @0x1e6684 ldr r3, [r1, #0x4]
 *   @0x1e6688 ldrsh lr, [r0, #20]
 *   @0x1e668c ldrsh r1, [r0]
 *   @0x1e6690 ldrsh r2, [r0, #2]
 *   @0x1e6694 ldr r4, [r3, lr, lsl #2]
 *   @0x1e6698 ldrsh lr, [r0, #6]
 *   @0x1e669c ldrsh r3, [r0, #4]
 *   @0x1e66a0 ldr r0, [r4]
 *   @0x1e66a4 str lr, [sp]
 *   @0x1e66a8 bl 0x17e2a8 <_ZN8Graphics16Texture_GrabRectEPviiii>
 *   @0x1e66ac subs r9, r0, #0
 *   @0x1e66b0 beq 0x1e65f0 <_ZN7CSprite18GenerateBitmapDataEv+0x18>
 *   @0x1e66b4 ldr r3, [r11, #0x54]
 *   @0x1e66b8 ldr r3, [r3, r5, lsl #2]
 *   @0x1e66bc ldrsh r2, [r3, #12]
 *   @0x1e66c0 ldrsh r3, [r3, #4]
 *   @0x1e66c4 vmov s14, r2
 *   @0x1e66c8 vmov s15, r3
 *   @0x1e66cc vcvt.f32.s32 s14, s14
 *   @0x1e66d0 vcvt.f32.s32 s15, s15
 *   @0x1e66d4 vdiv.f32 s15, s14, s15
 *   @0x1e66d8 vcvt.s32.f32 s15, s15
 *   @0x1e66dc vmov r7, s15
 *   @0x1e66e0 bl 0x1a912c <_ZN7IBitmap6CreateEv>
 *   @0x1e66e4 mov r1, #7
 *   @0x1e66e8 ldr r3, [r0]
 *   @0x1e66ec mov r4, r0
 *   @0x1e66f0 ldr r3, [r3, #0x1c]
 *   @0x1e66f4 blx r3
 *   @0x1e66f8 ldr r3, [r11, #0x54]
 *   @0x1e66fc mov r1, r7
 *   @0x1e6700 ldr r10, [r4]
 *   @0x1e6704 ldr r3, [r3, r5, lsl #2]
 *   @0x1e6708 ldrsh r0, [r3, #16]
 *   @0x1e670c bl 0x318d10 <__divsi3>
 *   @0x1e6710 ldr r3, [r10, #0xc]
 *   @0x1e6714 mov r1, r0
 *   @0x1e6718 mov r0, r4
 *   @0x1e671c blx r3
 *   @0x1e6720 ldr r3, [r11, #0x54]
 *   @0x1e6724 mov r1, r7
 *   @0x1e6728 ldr r10, [r4]
 *   @0x1e672c ldr r3, [r3, r5, lsl #2]
 *   @0x1e6730 ldrsh r0, [r3, #18]
 *   @0x1e6734 bl 0x318d10 <__divsi3>
 *   @0x1e6738 ldr r3, [r10, #0x14]
 *   @0x1e673c mov r1, r0
 *   @0x1e6740 mov r0, r4
 *   @0x1e6744 blx r3
 *   @0x1e6748 str r8, [sp, #0x1c]
 *   @0x1e674c ldr lr, [r4]
 *   @0x1e6750 add r3, sp, #24
 *   @0x1e6754 mov r1, #0
 *   @0x1e6758 add r2, sp, #28
 *   @0x1e675c mov r0, r4
 *   @0x1e6760 str r8, [sp, #0x18]
 *   @0x1e6764 ldr r10, [lr, #0x24]
 *   @0x1e6768 blx r10
 *   @0x1e676c ldr r2, [r4]
 *   @0x1e6770 ldr r10, [sp, #0x1c]
 *   @0x1e6774 ldr r2, [r2, #0x18]
 *   @0x1e6778 str r0, [sp, #0x8]
 *   @0x1e677c mov r0, r4
 *   @0x1e6780 blx r2
 *   @0x1e6784 ldr r2, [sp, #0x18]
 *   @0x1e6788 mov r1, #0
 *   @0x1e678c mul r2, r2, r0
 *   @0x1e6790 mov r0, r10
 *   @0x1e6794 bl 0xb65b0 <memset@plt>
 *   @0x1e6798 ldr r10, [r11, #0x54]
 *   @0x1e679c mov r1, r7
 *   @0x1e67a0 ldr r2, [r10, r5, lsl #2]
 *   @0x1e67a4 ldrsh r0, [r2, #10]
 *   @0x1e67a8 bl 0x318d10 <__divsi3>
 *   @0x1e67ac ldr r2, [sp, #0x1c]
 *   @0x1e67b0 ldr lr, [sp, #0x18]
 *   @0x1e67b4 mov r1, r7
 *   @0x1e67b8 mla r7, lr, r0, r2
 *   @0x1e67bc str r7, [sp, #0x1c]
 *   @0x1e67c0 ldr r2, [r10, r5, lsl #2]
 *   @0x1e67c4 ldrsh r0, [r2, #8]
 *   @0x1e67c8 bl 0x318d10 <__divsi3>
 *   @0x1e67cc add r0, r7, r0, lsl #2
 *   @0x1e67d0 str r0, [sp, #0x1c]
 *   @0x1e67d4 ldr r3, [r10, r5, lsl #2]
 *   @0x1e67d8 ldrsh r2, [r3, #6]
 *   @0x1e67dc cmp r2, #0
 *   @0x1e67e0 ble 0x1e6834 <_ZN7CSprite18GenerateBitmapDataEv+0x25c>
 *   @0x1e67e4 ldrh r2, [r3, #4]
 *   @0x1e67e8 mov r10, r9
 *   @0x1e67ec mov r7, #0
 *   @0x1e67f0 sxth r2, r2
 *   @0x1e67f4 mov r1, r10
 *   @0x1e67f8 add r7, r7, #1
 *   @0x1e67fc lsl r2, r2, #2
 *   @0x1e6800 bl 0xb65bc <memcpy@plt>
 *   @0x1e6804 ldr r3, [r11, #0x54]
 *   @0x1e6808 ldr r0, [sp, #0x1c]
 *   @0x1e680c ldr r2, [sp, #0x18]
 *   @0x1e6810 add r0, r0, r2
 *   @0x1e6814 str r0, [sp, #0x1c]
 *   @0x1e6818 ldr r3, [r3, r6]
 *   @0x1e681c ldrh r2, [r3, #4]
 *   @0x1e6820 ldrsh r3, [r3, #6]
 *   @0x1e6824 cmp r3, r7
 *   @0x1e6828 sxth r3, r2
 *   @0x1e682c add r10, r10, r3, lsl #2
 *   @0x1e6830 bgt 0x1e67f0 <_ZN7CSprite18GenerateBitmapDataEv+0x218>
 *   @0x1e6834 ldr r3, [r4]
 *   @0x1e6838 mov r0, r4
 *   @0x1e683c ldr r1, [sp, #0x8]
 *   @0x1e6840 add r5, r5, #1
 *   @0x1e6844 ldr r3, [r3, #0x28]
 *   @0x1e6848 blx r3
 *   @0x1e684c mov r0, r9
 *   @0x1e6850 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e6854 mov r0, #24
 *   @0x1e6858 bl 0x27c524 <_Znwj>
 *   @0x1e685c mov r2, #0
 *   @0x1e6860 mov r3, r2
 *   @0x1e6864 mov r1, r4
 *   @0x1e6868 str r8, [sp]
 *   @0x1e686c mov r7, r0
 *   @0x1e6870 bl 0x166fd0 <_ZN9CBitmap32C2EP7IBitmapbbi>
 *   @0x1e6874 ldr r3, [r11, #0x48]
 *   @0x1e6878 mov r0, r4
 *   @0x1e687c str r7, [r3, r6]
 *   @0x1e6880 ldr r3, [r4]
 *   @0x1e6884 str r5, [r11, #0x44]
 *   @0x1e6888 ldr r3, [r3, #0x4]
 *   @0x1e688c blx r3
 *   @0x1e6890 ldr r3, [r11, #0x18]
 *   @0x1e6894 cmp r3, r5
 *   @0x1e6898 bgt 0x1e6674 <_ZN7CSprite18GenerateBitmapDataEv+0x9c>
 *   @0x1e689c mov r0, #1
 *   @0x1e68a0 add sp, sp, #36
 *   @0x1e68a4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e68a8 andseq r11, r6, r8, lsl lr
 *   @0x1e68ac .word 0x002072b8
 *
 * ══ §3/43 zip_open_buff  0x2a51a0  size 728  182 条（0x2a51a0..0x2a5478）
 * @func 0x2a51a0 0x2a5478  size 728  182 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2a4a60+0x17a×3 / _zip_error_set(zip_error*, int, int)×2 / 0xb655c×2 / IBuffer::Read(void const*, unsigned int, unsigned int) / 0x485590 / _zip_cdir_new(int, zip_error*) / _zip_read4(unsigned char**) / _zip_read2(unsigned char**)
 * 字段偏移 top8: 0x14×4 / 0x24×3 / 0x18×2 / 0x4×2 / 0xc×1 / 0x2a0×1 / 0x8×1 / 0x284×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a51a0 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2a51a4 sub sp, #0x4c
 *   @0x2a51a8 str r2, [sp, #0xc]
 *   @0x2a51ac str r1, [sp, #0x24]
 *   @0x2a51b0 ldr r0, [pc, #0x2a0]
 *   @0x2a51b4 add r0, pc
 *   @0x2a51b8 stmdahs r0, {r7, r8, r10, r11, r12, sp, lr, pc}
 *   @0x2a51bc beq.w 0x2a5472 <zip_open_buff+0x2d2>
 *   @0x2a51c0 str r6, [r0, #0x8]
 *   @0x2a51c4 ldr r3, [r0]
 *   @0x2a51c8 ldr r4, [pc, #0x284]
 *   @0x2a51cc cmp r2, r4
 *   @0x2a51d0 movge r2, r4
 *   @0x2a51d4 mov r0, r4
 *   @0x2a51d8 selmi lr, r1, r6
 *   @0x2a51dc cbnz r0, 0x2a51ec <zip_open_buff+0x4c>
 *   @0x2a51e0 cmp r2, #0x0
 *   @0x2a51e4 movwhs r8, #0xe145
 *   @0x2a51e8 str r3, [r2]
 *   @0x2a51ec mov r3, r4
 *   @0x2a51f0 movs r2, #0x1
 *   @0x2a51f4 blx 0xcdc9c <_ZN7IBuffer4ReadEPKvjj>
 *   @0x2a51f8 add r5, sp, #0x3c
 *   @0x2a51fc movs r1, #0x13
 *   @0x2a5200 strhs r3, [r0], #-2303
 *   @0x2a5204 str r0, [sp, #0x1c]
 *   @0x2a5208 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii>
 *   @0x2a520c ldr r3, [pc, #0x248]
 *   @0x2a5210 add r3, pc
 *   @0x2a5214 movwls r9, #0xa018
 *   @0x2a5218 add r2, pc
 *   @0x2a521c str r2, [sp, #0x2c]
 *   @0x2a5220 ldr r3, [sp, #0x18]
 *   @0x2a5224 rsb r1, r3, r9
 *   @0x2a5228 add r1, r2
 *   @0x2a522c subs r1, #0x12
 *   @0x2a5230 strmi pc, [r7], -r11, lsl #25
 *   @0x2a5234 cmp r0, #0x0
 *   @0x2a5238 blls 0x485590 <mstack+0x8a4>
 *   @0x2a523c adds r2, r7, #0x1
 *   @0x2a5240 add r3, r9
 *   @0x2a5244 subs r3, #0x16
 *   @0x2a5248 bpl 0x2a5252 <zip_open_buff+0xb2>
 *   @0x2a524c movs r1, #0x13
 *   @0x2a5250 b 0x2a5274 <zip_open_buff+0xd4>
 *   @0x2a5254 movs r2, #0x4
 *   @0x2a5258 .word 0x4683ecf4
 *   @0x2a525c cmp r0, #0x0
 *   @0x2a5260 adds r0, r7, #0x4
 *   @0x2a5264 movs r2, #0x4
 *   @0x2a5268 andls lr, r5, r12, ror #25
 *   @0x2a526c cbz r0, 0x2a527a <zip_open_buff+0xda>
 *   @0x2a5270 movs r1, #0x1
 *   @0x2a5274 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii>
 *   @0x2a5278 b 0x2a53d8 <zip_open_buff+0x238>
 *   @0x2a527c add.w r3, r7, #0x8
 *   @0x2a5280 str r3, [sp, #0x34]
 *   @0x2a5284 pkhbtmi pc, r3, sp, lsl #28
 *   @0x2a5288 add r0, sp, #0x34
 *   @0x2a528c qadd16mi pc, r9, r9
 *   @0x2a5290 bl 0x2a3b88 <_Z13_zip_cdir_newiP9zip_error>
 *   @0x2a5294 mov r10, r0
 *   @0x2a5298 beq.w 0x2a53d8 <zip_open_buff+0x238>
 *   @0x2a529c add r0, sp, #0x34
 *   @0x2a52a0 .word 0xf8cafe18
 *   @0x2a52a4 stmdage sp, {r3}
 *   @0x2a52a8 bl 0x2a3ed2 <_Z10_zip_read4PPh>
 *   @0x2a52ac ldr r3, [sp, #0x14]
 *   @0x2a52b0 .word 0xf8ca3010
 *   @0x2a52b4 stmdage sp, {r2, r3}
 *   @0x2a52b8 bl 0x2a3ec0 <_Z10_zip_read2PPh>
 *   @0x2a52bc ldr r3, [sp, #0x20]
 *   @0x2a52c0 mov r1, r0
 *   @0x2a52c4 blle 0x36531c <_ZTS12CDS_Priority+0x7374>
 *   @0x2a52c8 ldr.w r3, [r10, #0x4]
 *   @0x2a52cc cmp r3, r11
 *   @0x2a52d0 mov r0, r5
 *   @0x2a52d4 movs r2, #0x0
 *   @0x2a52d8 ldr r2, [sp, #0x24]
 *   @0x2a52dc bpl 0x2a52f0 <zip_open_buff+0x150>
 *   @0x2a52e0 cmp r3, r0
 *   @0x2a52e4 ldr r2, [sp, #0x14]
 *   @0x2a52e8 movs r1, #0x15
 *   @0x2a52ec and pc, r8, r5, lsr r8
 *   @0x2a52f0 cbz r1, 0x2a530a <zip_open_buff+0x16a>
 *   @0x2a52f4 qadd16mi r0, r10, r6
 *   @0x2a52f8 bl 0x2a4978 <_Z11_zip_memdupPKvjP9zip_error>
 *   @0x2a52fc str.w r0, [r10, #0x10]
 *   @0x2a5300 cbnz r0, 0x2a530a <zip_open_buff+0x16a>
 *   @0x2a5304 blx 0xb655c <free@plt>
 *   @0x2a5308 b 0x2a53d8 <zip_open_buff+0x238>
 *   @0x2a530c bl 0xff4f1334 <b2_toiTime+0xfffffffffed97e90>
 *   @0x2a5310 addsmi r0, r3, #1879048192
 *   @0x2a5314 bhs 0x2a5320 <zip_open_buff+0x180>
 *   @0x2a5318 add r2, sp, #0x34
 *   @0x2a531c str r2, [sp, #0x14]
 *   @0x2a5320 ldr r3, [r6]
 *   @0x2a5324 movs r1, #0x0
 *   @0x2a5328 ldmdbvs r11, {r2, r3, sp}
 *   @0x2a532c blx r3
 *   @0x2a5330 str r3, [sp, #0x14]
 *   @0x2a5334 svcge #0x123008
 *   @0x2a5338 mov.w r11, #0x0
 *   @0x2a533c str r3, [r7, #-16]!
 *   @0x2a5340 ldr.w r3, [r10, #0x4]
 *   @0x2a5344 cmp r11, r3
 *   @0x2a5348 ldr r3, [sp, #0x38]
 *   @0x2a534c mov r0, r10
 *   @0x2a5350 strtmi r3, [r10], -r0, lsl #3
 *   @0x2a5354 bl 0x2a3b4e <_Z14_zip_cdir_growP8zip_cdiriP9zip_error>
 *   @0x2a5358 ldr.w r0, [r10]
 *   @0x2a535c movs r3, #0x3c
 *   @0x2a5360 mov r1, r6
 *   @0x2a5364 blx 0x3653fe <_ZTS12CDS_Priority+0x7456>
 *   @0x2a5368 bls 0x3e539c <error_g0017+0x3e040>
 *   @0x2a536c mov r3, r7
 *   @0x2a5370 stmdahs r0, {r0, r1, r3, r6, r7, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2a5374 bge 0x2a537c <zip_open_buff+0x1dc>
 *   @0x2a5378 ands r11, pc, r4
 *   @0x2a537c ldr.w r3, [r10, #0x4]
 *   @0x2a5380 add.w r11, r11, #0x1
 *   @0x2a5384 cmp r11, r3
 *   @0x2a5388 cmp.w r10, #0x0
 *   @0x2a538c beq 0x2a53d8 <zip_open_buff+0x238>
 *   @0x2a5390 cmp.w r8, #0x0
 *   @0x2a5394 bgt 0x2a53a2 <zip_open_buff+0x202>
 *   @0x2a5398 mov r1, r4
 *   @0x2a539c bl 0x2a4bda <zip_name_locate+0x182>
 *   @0x2a53a0 mov r8, r0
 *   @0x2a53a4 mov r1, r10
 *   @0x2a53a8 bl 0x2a4bda <zip_name_locate+0x182>
 *   @0x2a53ac cmp r8, r0
 *   @0x2a53b0 bge 0x2a53bc <zip_open_buff+0x21c>
 *   @0x2a53b4 mov r8, r7
 *   @0x2a53b8 ands pc, r0, lr, lsl r12
 *   @0x2a53bc mov r0, r10
 *   @0x2a53c0 and pc, r9, r10, lsl r12
 *   @0x2a53c4 ldr r2, [sp, #0x24]
 *   @0x2a53c8 bpl 0x2a53dc <zip_open_buff+0x23c>
 *   @0x2a53cc mov r1, r10
 *   @0x2a53d0 bl 0x2a4bda <zip_name_locate+0x182>
 *   @0x2a53d4 mov r8, r0
 *   @0x2a53d8 mov r10, r4
 *   @0x2a53dc mov r8, r4
 *   @0x2a53e0 b 0x2a5220 <zip_open_buff+0x80>
 *   @0x2a53e4 blx 0xb655c <free@plt>
 *   @0x2a53e8 cmp.w r8, #0x0
 *   @0x2a53ec bge 0x2a5400 <zip_open_buff+0x260>
 *   @0x2a53f0 mov r1, r5
 *   @0x2a53f4 bl 0x2a4a60 <zip_name_locate+0x8>
 *   @0x2a53f8 mov r0, r4
 *   @0x2a53fc ldrsht pc, [r7], -r12
 *   @0x2a5400 cmp r4, #0x0
 *   @0x2a5404 ldr r0, [pc, #0x58]
 *   @0x2a5408 add r0, pc
 *   @0x2a540c .word 0x4605fc56
 *   @0x2a5410 cbnz r0, 0x2a541a <zip_open_buff+0x27a>
 *   @0x2a5414 bl 0x2a3bf6 <_Z14_zip_cdir_freeP8zip_cdir>
 *   @0x2a5418 b 0x2a546c <zip_open_buff+0x2cc>
 *   @0x2a541c str r7, [r0, #0x4]
 *   @0x2a5420 movs r0, #0x14
 *   @0x2a5424 muls r0, r3, r0
 *   @0x2a5428 .word 0x6368e88e
 *   @0x2a542c cbnz r0, 0x2a5440 <zip_open_buff+0x2a0>
 *   @0x2a5430 cbz r3, 0x2a5438 <zip_open_buff+0x298>
 *   @0x2a5434 movs r3, #0xe
 *   @0x2a5438 mov r0, r5
 *   @0x2a543c ands pc, r7, r3, lsr #20
 *   @0x2a5440 ldr r3, [r4, #0x4]
 *   @0x2a5444 cmp r7, r3
 *   @0x2a5448 bl 0x2a5790 <_Z14_zip_entry_newP3zip>
 *   @0x2a544c adds r7, #0x1
 *   @0x2a5450 movs r6, r2
 *   @0x2a5454 ldr r0, [r5, #0x64]
 *   @0x2a5458 ldr r0, [r7, #0x5c]
 *   @0x2a545c adr r6, #248 <zip_open_buff+0x2fe>
 *   @0x2a5460 ldr r4, [r2, #0x40]
 *   @0x2a5464 bl 0x2a4a90 <zip_name_locate+0x38>
 *   @0x2a5468 ldr r3, [r5, #0x18]
 *   @0x2a546c mov r0, r5
 *   @0x2a5470 movs r0, #0x0
 *   @0x2a5474 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §4/43 b2World::DrawShape(b2Fixture*, b2Transform const&, b2Color const&)  0x2ca864  size 728  182 条（0x2ca864..0x2cab3c）
 * @func 0x2ca864 0x2cab3c  size 728  182 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2World::DrawShape(b2Fixture*, b2Transform const&, b2Color const&)+0xbc / b2World::DrawShape(b2Fixture*, b2Transform const&, b2Color const&)+0x22c
 * 字段偏移 top8: 0xc×5 / 0x1c×2 / 0x10×2 / 0x4×1 / 0x94×1 / 0x8×1 / 0x14×1
 * VFP 指令 86 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ca864 ldr r12, [r1, #0xc]
 *   @0x2ca868 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2ca86c mov r9, r3
 *   @0x2ca870 ldr r3, [r12, #0x4]
 *   @0x2ca874 sub sp, sp, #92
 *   @0x2ca878 mov r10, r0
 *   @0x2ca87c mov r4, r2
 *   @0x2ca880 cmp r3, #3
 *   @0x2ca884 addls pc, pc, r3, lsl #2
 *   @0x2ca888 b 0x2ca920 <_ZN7b2World9DrawShapeEP9b2FixtureRK11b2TransformRK7b2Color+0xbc>
 *   @0x2ca88c b 0x2caab8 <_ZN7b2World9DrawShapeEP9b2FixtureRK11b2TransformRK7b2Color+0x254>
 *   @0x2ca890 b 0x2ca89c <_ZN7b2World9DrawShapeEP9b2FixtureRK11b2TransformRK7b2Color+0x38>
 *   @0x2ca894 b 0x2caa28 <_ZN7b2World9DrawShapeEP9b2FixtureRK11b2TransformRK7b2Color+0x1c4>
 *   @0x2ca898 b 0x2ca928 <_ZN7b2World9DrawShapeEP9b2FixtureRK11b2TransformRK7b2Color+0xc4>
 *   @0x2ca89c vldr s11, [r12, #16]
 *   @0x2ca8a0 vldr s15, [r2, #12]
 *   @0x2ca8a4 vmul.f32 s10, s15, s11
 *   @0x2ca8a8 vldr s13, [r12, #12]
 *   @0x2ca8ac vldr s14, [r2, #8]
 *   @0x2ca8b0 vldr s8, [r2, #4]
 *   @0x2ca8b4 movw r0, #0x9248
 *   @0x2ca8b8 movt r0, #0x1
 *   @0x2ca8bc vldr s9, [r2]
 *   @0x2ca8c0 mov r3, r9
 *   @0x2ca8c4 ldr r0, [r10, r0]
 *   @0x2ca8c8 add r1, sp, #16
 *   @0x2ca8cc add r2, sp, #24
 *   @0x2ca8d0 ldr lr, [r0]
 *   @0x2ca8d4 ldr r4, [lr, #0x1c]
 *   @0x2ca8d8 vmla.f32 s10, s13, s14
 *   @0x2ca8dc vmul.f32 s11, s14, s11
 *   @0x2ca8e0 vnmls.f32 s11, s15, s13
 *   @0x2ca8e4 vadd.f32 s10, s10, s8
 *   @0x2ca8e8 vstr s10, [sp, #20]
 *   @0x2ca8ec vldr s13, [r12, #24]
 *   @0x2ca8f0 vmul.f32 s12, s15, s13
 *   @0x2ca8f4 vmul.f32 s13, s14, s13
 *   @0x2ca8f8 vadd.f32 s11, s11, s9
 *   @0x2ca8fc vstr s11, [sp, #16]
 *   @0x2ca900 vldr s11, [r12, #20]
 *   @0x2ca904 vmla.f32 s12, s14, s11
 *   @0x2ca908 vnmls.f32 s13, s15, s11
 *   @0x2ca90c vadd.f32 s12, s8, s12
 *   @0x2ca910 vadd.f32 s13, s9, s13
 *   @0x2ca914 vstr s12, [sp, #28]
 *   @0x2ca918 vstr s13, [sp, #24]
 *   @0x2ca91c blx r4
 *   @0x2ca920 add sp, sp, #92
 *   @0x2ca924 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2ca928 ldr r6, [r12, #0xc]
 *   @0x2ca92c vldr s11, [r2, #8]
 *   @0x2ca930 vldr s13, [r6, #4]
 *   @0x2ca934 vldr s12, [r2, #12]
 *   @0x2ca938 vmul.f32 s8, s11, s13
 *   @0x2ca93c vldr s7, [r6]
 *   @0x2ca940 vldr s10, [r2]
 *   @0x2ca944 vldr s9, [r2, #4]
 *   @0x2ca948 ldr r12, [r12, #0x10]
 *   @0x2ca94c cmp r12, #1
 *   @0x2ca950 str r12, [sp, #0xc]
 *   @0x2ca954 vmul.f32 s13, s12, s13
 *   @0x2ca958 vnmls.f32 s8, s12, s7
 *   @0x2ca95c vmla.f32 s13, s7, s11
 *   @0x2ca960 vadd.f32 s8, s8, s10
 *   @0x2ca964 vadd.f32 s13, s13, s9
 *   @0x2ca968 vstr s8, [sp, #16]
 *   @0x2ca96c vstr s13, [sp, #20]
 *   @0x2ca970 ble 0x2ca920 <_ZN7b2World9DrawShapeEP9b2FixtureRK11b2TransformRK7b2Color+0xbc>
 *   @0x2ca974 movw r11, #0x9248
 *   @0x2ca978 add r6, r6, #8
 *   @0x2ca97c movt r11, #0x1
 *   @0x2ca980 add r5, sp, #16
 *   @0x2ca984 add r7, sp, #24
 *   @0x2ca988 mov r8, #1
 *   @0x2ca98c b 0x2ca9a0 <_ZN7b2World9DrawShapeEP9b2FixtureRK11b2TransformRK7b2Color+0x13c>
 *   @0x2ca990 vldr s12, [r4, #12]
 *   @0x2ca994 vldr s11, [r4, #8]
 *   @0x2ca998 vldr s10, [r4]
 *   @0x2ca99c vldr s9, [r4, #4]
 *   @0x2ca9a0 vldr s15, [r6, #4]
 *   @0x2ca9a4 vmul.f32 s14, s15, s11
 *   @0x2ca9a8 vldr s13, [r6]
 *   @0x2ca9ac ldr r0, [r10, r11]
 *   @0x2ca9b0 mov r1, r5
 *   @0x2ca9b4 mov r2, r7
 *   @0x2ca9b8 mov r3, r9
 *   @0x2ca9bc add r8, r8, #1
 *   @0x2ca9c0 ldr r12, [r0]
 *   @0x2ca9c4 add r6, r6, #8
 *   @0x2ca9c8 ldr r12, [r12, #0x1c]
 *   @0x2ca9cc vmul.f32 s15, s15, s12
 *   @0x2ca9d0 vnmls.f32 s14, s13, s12
 *   @0x2ca9d4 vmla.f32 s15, s13, s11
 *   @0x2ca9d8 vadd.f32 s14, s14, s10
 *   @0x2ca9dc vadd.f32 s15, s15, s9
 *   @0x2ca9e0 vstr s14, [sp, #24]
 *   @0x2ca9e4 vstr s15, [sp, #28]
 *   @0x2ca9e8 blx r12
 *   @0x2ca9ec ldr r0, [r10, r11]
 *   @0x2ca9f0 mov r1, r5
 *   @0x2ca9f4 mov r3, r9
 *   @0x2ca9f8 movw r2, #0xcccd
 *   @0x2ca9fc movt r2, #0x3d4c
 *   @0x2caa00 ldr r12, [r0]
 *   @0x2caa04 ldr r12, [r12, #0x10]
 *   @0x2caa08 blx r12
 *   @0x2caa0c ldr r3, [sp, #0xc]
 *   @0x2caa10 ldm r7, {r0, r1}
 *   @0x2caa14 cmp r8, r3
 *   @0x2caa18 stm r5, {r0, r1}
 *   @0x2caa1c bne 0x2ca990 <_ZN7b2World9DrawShapeEP9b2FixtureRK11b2TransformRK7b2Color+0x12c>
 *   @0x2caa20 add sp, sp, #92
 *   @0x2caa24 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2caa28 ldr r2, [r12, #0x94]
 *   @0x2caa2c add r7, sp, #24
 *   @0x2caa30 cmp r2, #0
 *   @0x2caa34 ble 0x2caa90 <_ZN7b2World9DrawShapeEP9b2FixtureRK11b2TransformRK7b2Color+0x22c>
 *   @0x2caa38 add r1, r12, #20
 *   @0x2caa3c mov r0, #0
 *   @0x2caa40 mov r3, r7
 *   @0x2caa44 vldr s11, [r4, #12]
 *   @0x2caa48 vldr s12, [r4, #8]
 *   @0x2caa4c vldr s9, [r4]
 *   @0x2caa50 vldr s10, [r4, #4]
 *   @0x2caa54 vldr s15, [r1, #4]
 *   @0x2caa58 vmul.f32 s14, s15, s12
 *   @0x2caa5c vldr s13, [r1]
 *   @0x2caa60 add r0, r0, #1
 *   @0x2caa64 cmp r0, r2
 *   @0x2caa68 add r1, r1, #8
 *   @0x2caa6c add r3, r3, #8
 *   @0x2caa70 vmul.f32 s15, s15, s11
 *   @0x2caa74 vnmls.f32 s14, s13, s11
 *   @0x2caa78 vmla.f32 s15, s13, s12
 *   @0x2caa7c vadd.f32 s14, s14, s9
 *   @0x2caa80 vadd.f32 s15, s15, s10
 *   @0x2caa84 vstr s14, [r3, #-8]
 *   @0x2caa88 vstr s15, [r3, #-4]
 *   @0x2caa8c bne 0x2caa54 <_ZN7b2World9DrawShapeEP9b2FixtureRK11b2TransformRK7b2Color+0x1f0>
 *   @0x2caa90 movw r3, #0x9248
 *   @0x2caa94 movt r3, #0x1
 *   @0x2caa98 mov r1, r7
 *   @0x2caa9c ldr r0, [r10, r3]
 *   @0x2caaa0 mov r3, r9
 *   @0x2caaa4 ldr r12, [r0]
 *   @0x2caaa8 ldr r12, [r12, #0xc]
 *   @0x2caaac blx r12
 *   @0x2caab0 add sp, sp, #92
 *   @0x2caab4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2caab8 vldr s13, [r12, #16]
 *   @0x2caabc vldr s14, [r2, #12]
 *   @0x2caac0 vldr s15, [r2, #8]
 *   @0x2caac4 vmul.f32 s12, s14, s13
 *   @0x2caac8 vldr s10, [r12, #12]
 *   @0x2caacc vldr s11, [pc, #100]
 *   @0x2caad0 vldr s8, [r2, #4]
 *   @0x2caad4 vldr s9, [r2]
 *   @0x2caad8 movw r2, #0x9248
 *   @0x2caadc movt r2, #0x1
 *   @0x2caae0 add r1, sp, #16
 *   @0x2caae4 add r3, sp, #24
 *   @0x2caae8 ldr r0, [r0, r2]
 *   @0x2caaec ldr lr, [r0]
 *   @0x2caaf0 vmul.f32 s13, s15, s13
 *   @0x2caaf4 vmla.f32 s12, s10, s15
 *   @0x2caaf8 vnmls.f32 s13, s14, s10
 *   @0x2caafc vmov.f32 s10, s14
 *   @0x2cab00 vmls.f32 s10, s15, s11
 *   @0x2cab04 vmla.f32 s15, s14, s11
 *   @0x2cab08 vadd.f32 s12, s12, s8
 *   @0x2cab0c vadd.f32 s13, s13, s9
 *   @0x2cab10 vstr s12, [sp, #20]
 *   @0x2cab14 vstr s13, [sp, #16]
 *   @0x2cab18 ldr r2, [r12, #0x8]
 *   @0x2cab1c str r9, [sp]
 *   @0x2cab20 ldr r12, [lr, #0x14]
 *   @0x2cab24 vstr s10, [sp, #24]
 *   @0x2cab28 vstr s15, [sp, #28]
 *   @0x2cab2c blx r12
 *   @0x2cab30 add sp, sp, #92
 *   @0x2cab34 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2cab38 andeq r0, r0, r0
 *
 * ══ §5/43 F_DsListMarkAsList(RValue&, CInstance*, CInstance*, int, RValue*)  0x102300  size 720  180 条（0x102300..0x1025d0）
 * @func 0x102300 0x1025d0  size 720  180 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / YYGetInt32(RValue const*, int)×2 / F_DsListMarkAsList(RValue&, CInstance*, CInstance*, int, RValue*)+0x118 / CDS_List::GetValue(int) / GetContextStackTop()
 * 字段偏移 top8: 0x4×9 / 0x8×8 / 0xc×7 / 0x18×1 / 0x29c×1 / 0x28c×1 / 0x2×1 / 0x1ac×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x102300 push {r3, r4, r5, r6, r7, lr}
 *   @0x102304 mov r1, #0
 *   @0x102308 ldr r5, [sp, #0x18]
 *   @0x10230c mov r4, r0
 *   @0x102310 mov r0, r5
 *   @0x102314 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x102318 cmp r0, #0
 *   @0x10231c blt 0x102418 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x102320 ldr r3, [pc, #0x29c]
 *   @0x102324 ldr r3, [pc, r3]
 *   @0x102328 ldr r3, [r3]
 *   @0x10232c cmp r0, r3
 *   @0x102330 bge 0x102418 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x102334 ldr r3, [pc, #0x28c]
 *   @0x102338 ldr r3, [pc, r3]
 *   @0x10233c ldr r3, [r3, #0x4]
 *   @0x102340 ldr r6, [r3, r0, lsl #2]
 *   @0x102344 cmp r6, #0
 *   @0x102348 beq 0x102418 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x10234c mov r0, r5
 *   @0x102350 mov r1, #1
 *   @0x102354 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x102358 mov r1, r0
 *   @0x10235c mov r0, r6
 *   @0x102360 bl 0x2031f4 <_ZN8CDS_List8GetValueEi>
 *   @0x102364 subs r5, r0, #0
 *   @0x102368 ldrne r3, [r5, #0xc]
 *   @0x10236c orrne r3, r3, #1073741824
 *   @0x102370 strne r3, [r5, #0xc]
 *   @0x102374 ldr r2, [r4, #0xc]
 *   @0x102378 bic r3, r2, #-16777216
 *   @0x10237c cmp r3, #1
 *   @0x102380 beq 0x10244c <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x14c>
 *   @0x102384 cmp r3, #2
 *   @0x102388 bne 0x1023b0 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x10238c sub r2, r2, #1
 *   @0x102390 bic r2, r2, #-16777216
 *   @0x102394 bic r2, r2, #3
 *   @0x102398 cmp r2, #0
 *   @0x10239c beq 0x102528 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x228>
 *   @0x1023a0 mov r2, #0
 *   @0x1023a4 mov r3, #5
 *   @0x1023a8 str r2, [r4, #0x8]
 *   @0x1023ac str r3, [r4, #0xc]
 *   @0x1023b0 ldr r3, [r5, #0xc]
 *   @0x1023b4 mov r2, #0
 *   @0x1023b8 ldr r1, [r5, #0x8]
 *   @0x1023bc str r2, [r4]
 *   @0x1023c0 str r3, [r4, #0xc]
 *   @0x1023c4 ldr r2, [r5, #0xc]
 *   @0x1023c8 str r1, [r4, #0x8]
 *   @0x1023cc bic r2, r2, #-16777216
 *   @0x1023d0 cmp r2, #14
 *   @0x1023d4 addls pc, pc, r2, lsl #2
 *   @0x1023d8 b 0x102434 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x1023dc b 0x102440 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x1023e0 b 0x1024a8 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x1a8>
 *   @0x1023e4 b 0x1024c4 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x1c4>
 *   @0x1023e8 b 0x10242c <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x1023ec b 0x102434 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x1023f0 b 0x102434 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x1023f4 b 0x102480 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x180>
 *   @0x1023f8 b 0x10242c <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x1023fc b 0x102434 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x102400 b 0x102434 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x102404 b 0x102440 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x102408 b 0x102434 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x10240c b 0x102434 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x102410 b 0x102440 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x102414 b 0x10242c <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x102418 ldr r0, [pc, #0x1ac]
 *   @0x10241c mov r1, #0
 *   @0x102420 pop {r3, r4, r5, r6, r7, lr}
 *   @0x102424 add r0, pc, r0
 *   @0x102428 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x10242c ldr r2, [r5]
 *   @0x102430 str r2, [r4]
 *   @0x102434 bic r3, r3, #-16777216
 *   @0x102438 str r3, [r4, #0xc]
 *   @0x10243c pop {r3, r4, r5, r6, r7, pc}
 *   @0x102440 ldm r5, {r1, r2}
 *   @0x102444 stm r4, {r1, r2}
 *   @0x102448 b 0x102434 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x10244c ldr r6, [r4]
 *   @0x102450 cmp r6, #0
 *   @0x102454 beq 0x102474 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x174>
 *   @0x102458 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x10245c ldr r7, [r6, #0x4]
 *   @0x102460 sub r7, r7, #1
 *   @0x102464 str r7, [r6, #0x4]
 *   @0x102468 cmp r7, #0
 *   @0x10246c beq 0x1024f0 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x1f0>
 *   @0x102470 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x102474 mov r3, #0
 *   @0x102478 str r3, [r4]
 *   @0x10247c b 0x1023b0 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x102480 ldr r2, [r5]
 *   @0x102484 str r2, [r4]
 *   @0x102488 ldr r2, [r5]
 *   @0x10248c cmp r2, #0
 *   @0x102490 beq 0x102434 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x102494 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x102498 ldr r1, [r5]
 *   @0x10249c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x1024a0 ldr r3, [r4, #0xc]
 *   @0x1024a4 b 0x102434 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x1024a8 ldr r2, [r5]
 *   @0x1024ac cmp r2, #0
 *   @0x1024b0 ldrne r3, [r2, #0x4]
 *   @0x1024b4 addne r3, r3, #1
 *   @0x1024b8 strne r3, [r2, #0x4]
 *   @0x1024bc ldrne r3, [r4, #0xc]
 *   @0x1024c0 b 0x102430 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x1024c4 ldr r2, [r5]
 *   @0x1024c8 cmp r2, #0
 *   @0x1024cc str r2, [r4]
 *   @0x1024d0 beq 0x102434 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x1024d4 ldr r0, [r2, #0x8]
 *   @0x1024d8 ldr r1, [r2]
 *   @0x1024dc cmp r0, #0
 *   @0x1024e0 streq r4, [r2, #0x8]
 *   @0x1024e4 add r1, r1, #1
 *   @0x1024e8 str r1, [r2]
 *   @0x1024ec b 0x102434 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x1024f0 ldr r0, [r6]
 *   @0x1024f4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1024f8 str r7, [r6]
 *   @0x1024fc str r7, [r6, #0x8]
 *   @0x102500 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x102504 ldr r7, [r6, #0x4]
 *   @0x102508 sub r7, r7, #1
 *   @0x10250c str r7, [r6, #0x4]
 *   @0x102510 cmp r7, #0
 *   @0x102514 beq 0x102534 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x234>
 *   @0x102518 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x10251c mov r0, r6
 *   @0x102520 bl 0x27d1d0 <_ZdlPv>
 *   @0x102524 b 0x102470 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x170>
 *   @0x102528 mov r0, r4
 *   @0x10252c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x102530 b 0x1023a0 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x102534 ldr r0, [r6]
 *   @0x102538 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x10253c str r7, [r6]
 *   @0x102540 str r7, [r6, #0x8]
 *   @0x102544 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x102548 ldr r7, [r6, #0x4]
 *   @0x10254c sub r7, r7, #1
 *   @0x102550 str r7, [r6, #0x4]
 *   @0x102554 cmp r7, #0
 *   @0x102558 beq 0x10256c <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x26c>
 *   @0x10255c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x102560 mov r0, r6
 *   @0x102564 bl 0x27d1d0 <_ZdlPv>
 *   @0x102568 b 0x102518 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x218>
 *   @0x10256c ldr r0, [r6]
 *   @0x102570 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x102574 str r7, [r6]
 *   @0x102578 str r7, [r6, #0x8]
 *   @0x10257c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x102580 ldr r7, [r6, #0x4]
 *   @0x102584 sub r7, r7, #1
 *   @0x102588 str r7, [r6, #0x4]
 *   @0x10258c cmp r7, #0
 *   @0x102590 bne 0x1025b4 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x2b4>
 *   @0x102594 ldr r0, [r6]
 *   @0x102598 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x10259c mov r0, r6
 *   @0x1025a0 str r7, [r6]
 *   @0x1025a4 str r7, [r6, #0x8]
 *   @0x1025a8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x1025ac mov r0, r6
 *   @0x1025b0 bl 0x27d1d0 <_ZdlPv>
 *   @0x1025b4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1025b8 mov r0, r6
 *   @0x1025bc bl 0x27d1d0 <_ZdlPv>
 *   @0x1025c0 b 0x10255c <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x25c>
 *   @0x1025c4 eoreq r11, lr, r8, asr r9
 *   @0x1025c8 eoreq r11, lr, r8, asr #18
 *   @0x1025cc .word 0x002357d8
 *
 * ══ §6/43 F_DsListMarkAsMap(RValue&, CInstance*, CInstance*, int, RValue*)  0x1025d0  size 720  180 条（0x1025d0..0x1028a0）
 * @func 0x1025d0 0x1028a0  size 720  180 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / YYGetInt32(RValue const*, int)×2 / F_DsListMarkAsMap(RValue&, CInstance*, CInstance*, int, RValue*)+0x118 / CDS_List::GetValue(int) / GetContextStackTop()
 * 字段偏移 top8: 0x4×9 / 0x8×8 / 0xc×7 / 0x18×1 / 0x29c×1 / 0x28c×1 / 0x2×1 / 0x1ac×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1025d0 push {r3, r4, r5, r6, r7, lr}
 *   @0x1025d4 mov r1, #0
 *   @0x1025d8 ldr r5, [sp, #0x18]
 *   @0x1025dc mov r4, r0
 *   @0x1025e0 mov r0, r5
 *   @0x1025e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1025e8 cmp r0, #0
 *   @0x1025ec blt 0x1026e8 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x1025f0 ldr r3, [pc, #0x29c]
 *   @0x1025f4 ldr r3, [pc, r3]
 *   @0x1025f8 ldr r3, [r3]
 *   @0x1025fc cmp r0, r3
 *   @0x102600 bge 0x1026e8 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x102604 ldr r3, [pc, #0x28c]
 *   @0x102608 ldr r3, [pc, r3]
 *   @0x10260c ldr r3, [r3, #0x4]
 *   @0x102610 ldr r6, [r3, r0, lsl #2]
 *   @0x102614 cmp r6, #0
 *   @0x102618 beq 0x1026e8 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x10261c mov r0, r5
 *   @0x102620 mov r1, #1
 *   @0x102624 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x102628 mov r1, r0
 *   @0x10262c mov r0, r6
 *   @0x102630 bl 0x2031f4 <_ZN8CDS_List8GetValueEi>
 *   @0x102634 subs r5, r0, #0
 *   @0x102638 ldrne r3, [r5, #0xc]
 *   @0x10263c orrne r3, r3, #-2147483648
 *   @0x102640 strne r3, [r5, #0xc]
 *   @0x102644 ldr r2, [r4, #0xc]
 *   @0x102648 bic r3, r2, #-16777216
 *   @0x10264c cmp r3, #1
 *   @0x102650 beq 0x10271c <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x14c>
 *   @0x102654 cmp r3, #2
 *   @0x102658 bne 0x102680 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x10265c sub r2, r2, #1
 *   @0x102660 bic r2, r2, #-16777216
 *   @0x102664 bic r2, r2, #3
 *   @0x102668 cmp r2, #0
 *   @0x10266c beq 0x1027f8 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x228>
 *   @0x102670 mov r2, #0
 *   @0x102674 mov r3, #5
 *   @0x102678 str r2, [r4, #0x8]
 *   @0x10267c str r3, [r4, #0xc]
 *   @0x102680 ldr r3, [r5, #0xc]
 *   @0x102684 mov r2, #0
 *   @0x102688 ldr r1, [r5, #0x8]
 *   @0x10268c str r2, [r4]
 *   @0x102690 str r3, [r4, #0xc]
 *   @0x102694 ldr r2, [r5, #0xc]
 *   @0x102698 str r1, [r4, #0x8]
 *   @0x10269c bic r2, r2, #-16777216
 *   @0x1026a0 cmp r2, #14
 *   @0x1026a4 addls pc, pc, r2, lsl #2
 *   @0x1026a8 b 0x102704 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x1026ac b 0x102710 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x1026b0 b 0x102778 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x1a8>
 *   @0x1026b4 b 0x102794 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x1c4>
 *   @0x1026b8 b 0x1026fc <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x1026bc b 0x102704 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x1026c0 b 0x102704 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x1026c4 b 0x102750 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x180>
 *   @0x1026c8 b 0x1026fc <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x1026cc b 0x102704 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x1026d0 b 0x102704 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x1026d4 b 0x102710 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x1026d8 b 0x102704 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x1026dc b 0x102704 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x1026e0 b 0x102710 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x1026e4 b 0x1026fc <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x1026e8 ldr r0, [pc, #0x1ac]
 *   @0x1026ec mov r1, #0
 *   @0x1026f0 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1026f4 add r0, pc, r0
 *   @0x1026f8 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1026fc ldr r2, [r5]
 *   @0x102700 str r2, [r4]
 *   @0x102704 bic r3, r3, #-16777216
 *   @0x102708 str r3, [r4, #0xc]
 *   @0x10270c pop {r3, r4, r5, r6, r7, pc}
 *   @0x102710 ldm r5, {r1, r2}
 *   @0x102714 stm r4, {r1, r2}
 *   @0x102718 b 0x102704 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x10271c ldr r6, [r4]
 *   @0x102720 cmp r6, #0
 *   @0x102724 beq 0x102744 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x174>
 *   @0x102728 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x10272c ldr r7, [r6, #0x4]
 *   @0x102730 sub r7, r7, #1
 *   @0x102734 str r7, [r6, #0x4]
 *   @0x102738 cmp r7, #0
 *   @0x10273c beq 0x1027c0 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x1f0>
 *   @0x102740 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x102744 mov r3, #0
 *   @0x102748 str r3, [r4]
 *   @0x10274c b 0x102680 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x102750 ldr r2, [r5]
 *   @0x102754 str r2, [r4]
 *   @0x102758 ldr r2, [r5]
 *   @0x10275c cmp r2, #0
 *   @0x102760 beq 0x102704 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x102764 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x102768 ldr r1, [r5]
 *   @0x10276c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x102770 ldr r3, [r4, #0xc]
 *   @0x102774 b 0x102704 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x102778 ldr r2, [r5]
 *   @0x10277c cmp r2, #0
 *   @0x102780 ldrne r3, [r2, #0x4]
 *   @0x102784 addne r3, r3, #1
 *   @0x102788 strne r3, [r2, #0x4]
 *   @0x10278c ldrne r3, [r4, #0xc]
 *   @0x102790 b 0x102700 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x102794 ldr r2, [r5]
 *   @0x102798 cmp r2, #0
 *   @0x10279c str r2, [r4]
 *   @0x1027a0 beq 0x102704 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x1027a4 ldr r0, [r2, #0x8]
 *   @0x1027a8 ldr r1, [r2]
 *   @0x1027ac cmp r0, #0
 *   @0x1027b0 streq r4, [r2, #0x8]
 *   @0x1027b4 add r1, r1, #1
 *   @0x1027b8 str r1, [r2]
 *   @0x1027bc b 0x102704 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x1027c0 ldr r0, [r6]
 *   @0x1027c4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1027c8 str r7, [r6]
 *   @0x1027cc str r7, [r6, #0x8]
 *   @0x1027d0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1027d4 ldr r7, [r6, #0x4]
 *   @0x1027d8 sub r7, r7, #1
 *   @0x1027dc str r7, [r6, #0x4]
 *   @0x1027e0 cmp r7, #0
 *   @0x1027e4 beq 0x102804 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x234>
 *   @0x1027e8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1027ec mov r0, r6
 *   @0x1027f0 bl 0x27d1d0 <_ZdlPv>
 *   @0x1027f4 b 0x102740 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x170>
 *   @0x1027f8 mov r0, r4
 *   @0x1027fc bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x102800 b 0x102670 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x102804 ldr r0, [r6]
 *   @0x102808 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x10280c str r7, [r6]
 *   @0x102810 str r7, [r6, #0x8]
 *   @0x102814 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x102818 ldr r7, [r6, #0x4]
 *   @0x10281c sub r7, r7, #1
 *   @0x102820 str r7, [r6, #0x4]
 *   @0x102824 cmp r7, #0
 *   @0x102828 beq 0x10283c <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x26c>
 *   @0x10282c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x102830 mov r0, r6
 *   @0x102834 bl 0x27d1d0 <_ZdlPv>
 *   @0x102838 b 0x1027e8 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x218>
 *   @0x10283c ldr r0, [r6]
 *   @0x102840 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x102844 str r7, [r6]
 *   @0x102848 str r7, [r6, #0x8]
 *   @0x10284c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x102850 ldr r7, [r6, #0x4]
 *   @0x102854 sub r7, r7, #1
 *   @0x102858 str r7, [r6, #0x4]
 *   @0x10285c cmp r7, #0
 *   @0x102860 bne 0x102884 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x2b4>
 *   @0x102864 ldr r0, [r6]
 *   @0x102868 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x10286c mov r0, r6
 *   @0x102870 str r7, [r6]
 *   @0x102874 str r7, [r6, #0x8]
 *   @0x102878 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x10287c mov r0, r6
 *   @0x102880 bl 0x27d1d0 <_ZdlPv>
 *   @0x102884 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x102888 mov r0, r6
 *   @0x10288c bl 0x27d1d0 <_ZdlPv>
 *   @0x102890 b 0x10282c <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x25c>
 *   @0x102894 eoreq r11, lr, r8, lsl #13
 *   @0x102898 eoreq r11, lr, r8, ror r6
 *   @0x10289c eoreq r5, r3, r8, lsl #10
 *
 * ══ §7/43 F_PhysicsCreatePulleyJoint(RValue&, CInstance*, CInstance*, int, RValue*)  0x14f790  size 720  180 条（0x14f790..0x14fa60）
 * @func 0x14f790 0x14fa60  size 720  180 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x14f830→0x54298c, 0x14f970→0x54298c
 * 调用序列: YYGetFloat(RValue const*, int)×9 / YYGetInt32(RValue const*, int)×4 / Error_Show_Action(char const*, bool)×4 / Object_GetInstance(int, CInstance*, CInstance*)×2 / 0xb65b0×2 / 0xb65c8×2 / YYGetBool(RValue const*, int) / CPhysicsWorld::CreatePulleyJoint(CPhysicsObject*, CPhysicsObject*, float, float, float, float, float, float, float, float, float, bool)
 * 字段偏移 top8: 0x3c×3 / 0xc×2 / 0x4×2 / 0x14c×2 / 0x84×2 / 0xb4×2 / 0x2c×2 / 0x30×2
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14f790 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x14f794 sub sp, sp, #340
 *   @0x14f798 ldr r9, [pc, #0x2a4]
 *   @0x14f79c mov r7, r2
 *   @0x14f7a0 ldr r12, [pc, #0x2a0]
 *   @0x14f7a4 mov r3, #0
 *   @0x14f7a8 add r9, pc, r9
 *   @0x14f7ac ldr r4, [sp, #0x178]
 *   @0x14f7b0 mov r5, r0
 *   @0x14f7b4 mov r8, r1
 *   @0x14f7b8 ldr r6, [r9, r12]
 *   @0x14f7bc mov r0, r3
 *   @0x14f7c0 mov r1, r3
 *   @0x14f7c4 movt r0, #0xbff0
 *   @0x14f7c8 str r3, [r5, #0xc]
 *   @0x14f7cc ldr r2, [r6]
 *   @0x14f7d0 str r0, [r5, #0x4]
 *   @0x14f7d4 mov r0, r4
 *   @0x14f7d8 str r3, [r5]
 *   @0x14f7dc str r2, [sp, #0x14c]
 *   @0x14f7e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14f7e4 mov r1, r8
 *   @0x14f7e8 mov r2, r7
 *   @0x14f7ec bl 0x14ec2c <_Z18Object_GetInstanceiP9CInstanceS0_>
 *   @0x14f7f0 subs r10, r0, #0
 *   @0x14f7f4 beq 0x14f9b0 <_Z26F_PhysicsCreatePulleyJointR6RValueP9CInstanceS2_iPS_+0x220>
 *   @0x14f7f8 mov r1, #1
 *   @0x14f7fc mov r0, r4
 *   @0x14f800 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14f804 mov r1, r8
 *   @0x14f808 mov r2, r7
 *   @0x14f80c bl 0x14ec2c <_Z18Object_GetInstanceiP9CInstanceS0_>
 *   @0x14f810 subs r8, r0, #0
 *   @0x14f814 beq 0x14f9f8 <_Z26F_PhysicsCreatePulleyJointR6RValueP9CInstanceS2_iPS_+0x268>
 *   @0x14f818 ldr r7, [r10, #0x84]
 *   @0x14f81c cmp r7, #0
 *   @0x14f820 beq 0x14f970 <_Z26F_PhysicsCreatePulleyJointR6RValueP9CInstanceS2_iPS_+0x1e0>
 *   @0x14f824 ldr r8, [r8, #0x84]
 *   @0x14f828 cmp r8, #0
 *   @0x14f82c beq 0x14f970 <_Z26F_PhysicsCreatePulleyJointR6RValueP9CInstanceS2_iPS_+0x1e0>
 *   @0x14f830 ldr r3, [pc, #0x214]
 *   @0x14f834 ldr r3, [r9, r3]
 *   @0x14f838 ldr r3, [r3]
 *   @0x14f83c ldr r9, [r3, #0xb4]
 *   @0x14f840 cmp r9, #0
 *   @0x14f844 beq 0x14f99c <_Z26F_PhysicsCreatePulleyJointR6RValueP9CInstanceS2_iPS_+0x20c>
 *   @0x14f848 mov r1, #2
 *   @0x14f84c mov r0, r4
 *   @0x14f850 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14f854 mov r1, #3
 *   @0x14f858 mov r3, r0
 *   @0x14f85c mov r0, r4
 *   @0x14f860 str r3, [sp, #0x2c]
 *   @0x14f864 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14f868 mov r1, #4
 *   @0x14f86c mov r12, r0
 *   @0x14f870 mov r0, r4
 *   @0x14f874 str r12, [sp, #0x30]
 *   @0x14f878 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14f87c mov r1, #5
 *   @0x14f880 mov r2, r0
 *   @0x14f884 mov r0, r4
 *   @0x14f888 str r2, [sp, #0x34]
 *   @0x14f88c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14f890 mov r1, #6
 *   @0x14f894 str r0, [sp, #0x38]
 *   @0x14f898 mov r0, r4
 *   @0x14f89c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14f8a0 mov r1, #7
 *   @0x14f8a4 str r0, [sp, #0x3c]
 *   @0x14f8a8 mov r0, r4
 *   @0x14f8ac bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14f8b0 mov r1, #8
 *   @0x14f8b4 str r0, [sp, #0x40]
 *   @0x14f8b8 mov r0, r4
 *   @0x14f8bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14f8c0 mov r1, #9
 *   @0x14f8c4 str r0, [sp, #0x44]
 *   @0x14f8c8 mov r0, r4
 *   @0x14f8cc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14f8d0 mov r1, #10
 *   @0x14f8d4 mov r11, r0
 *   @0x14f8d8 mov r0, r4
 *   @0x14f8dc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14f8e0 mov r1, #11
 *   @0x14f8e4 mov r10, r0
 *   @0x14f8e8 mov r0, r4
 *   @0x14f8ec bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x14f8f0 ldr r2, [sp, #0x34]
 *   @0x14f8f4 ldr r12, [sp, #0x30]
 *   @0x14f8f8 mov r1, r7
 *   @0x14f8fc ldr r3, [sp, #0x2c]
 *   @0x14f900 str r2, [sp, #0x4]
 *   @0x14f904 ldr r2, [sp, #0x38]
 *   @0x14f908 str r12, [sp]
 *   @0x14f90c str r11, [sp, #0x18]
 *   @0x14f910 str r2, [sp, #0x8]
 *   @0x14f914 ldr r2, [sp, #0x3c]
 *   @0x14f918 str r10, [sp, #0x1c]
 *   @0x14f91c str r2, [sp, #0xc]
 *   @0x14f920 ldr r2, [sp, #0x40]
 *   @0x14f924 str r2, [sp, #0x10]
 *   @0x14f928 ldr r2, [sp, #0x44]
 *   @0x14f92c str r2, [sp, #0x14]
 *   @0x14f930 mov r2, r8
 *   @0x14f934 str r0, [sp, #0x20]
 *   @0x14f938 mov r0, r9
 *   @0x14f93c bl 0x2392a8 <_ZN13CPhysicsWorld17CreatePulleyJointEP14CPhysicsObjectS1_fffffffffb>
 *   @0x14f940 vmov s15, r0
 *   @0x14f944 vcvt.f64.s32 d7, s15
 *   @0x14f948 vmov r0, r1, d7
 *   @0x14f94c vmov r2, s14
 *   @0x14f950 mov r3, r1
 *   @0x14f954 stm r5, {r2, r3}
 *   @0x14f958 ldr r2, [sp, #0x14c]
 *   @0x14f95c ldr r3, [r6]
 *   @0x14f960 cmp r2, r3
 *   @0x14f964 bne 0x14fa40 <_Z26F_PhysicsCreatePulleyJointR6RValueP9CInstanceS2_iPS_+0x2b0>
 *   @0x14f968 add sp, sp, #340
 *   @0x14f96c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x14f970 ldr r3, [pc, #0xd4]
 *   @0x14f974 ldr r3, [r9, r3]
 *   @0x14f978 ldr r3, [r3]
 *   @0x14f97c ldr r3, [r3, #0xb4]
 *   @0x14f980 cmp r3, #0
 *   @0x14f984 beq 0x14f99c <_Z26F_PhysicsCreatePulleyJointR6RValueP9CInstanceS2_iPS_+0x20c>
 *   @0x14f988 ldr r0, [pc, #0xc0]
 *   @0x14f98c mov r1, #0
 *   @0x14f990 add r0, pc, r0
 *   @0x14f994 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14f998 b 0x14f958 <_Z26F_PhysicsCreatePulleyJointR6RValueP9CInstanceS2_iPS_+0x1c8>
 *   @0x14f99c ldr r0, [pc, #0xb0]
 *   @0x14f9a0 mov r1, #0
 *   @0x14f9a4 add r0, pc, r0
 *   @0x14f9a8 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14f9ac b 0x14f958 <_Z26F_PhysicsCreatePulleyJointR6RValueP9CInstanceS2_iPS_+0x1c8>
 *   @0x14f9b0 add r5, sp, #76
 *   @0x14f9b4 mov r1, r10
 *   @0x14f9b8 mov r2, #256
 *   @0x14f9bc mov r0, r5
 *   @0x14f9c0 bl 0xb65b0 <memset@plt>
 *   @0x14f9c4 mov r1, r10
 *   @0x14f9c8 mov r0, r4
 *   @0x14f9cc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14f9d0 ldr r2, [pc, #0x80]
 *   @0x14f9d4 mov r1, #256
 *   @0x14f9d8 add r2, pc, r2
 *   @0x14f9dc mov r3, r0
 *   @0x14f9e0 mov r0, r5
 *   @0x14f9e4 bl 0xb65c8 <snprintf@plt>
 *   @0x14f9e8 mov r0, r5
 *   @0x14f9ec mov r1, r10
 *   @0x14f9f0 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14f9f4 b 0x14f958 <_Z26F_PhysicsCreatePulleyJointR6RValueP9CInstanceS2_iPS_+0x1c8>
 *   @0x14f9f8 add r5, sp, #76
 *   @0x14f9fc mov r1, r8
 *   @0x14fa00 mov r2, #256
 *   @0x14fa04 mov r0, r5
 *   @0x14fa08 bl 0xb65b0 <memset@plt>
 *   @0x14fa0c mov r0, r4
 *   @0x14fa10 mov r1, #1
 *   @0x14fa14 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14fa18 ldr r2, [pc, #0x3c]
 *   @0x14fa1c mov r1, #256
 *   @0x14fa20 add r2, pc, r2
 *   @0x14fa24 mov r3, r0
 *   @0x14fa28 mov r0, r5
 *   @0x14fa2c bl 0xb65c8 <snprintf@plt>
 *   @0x14fa30 mov r0, r5
 *   @0x14fa34 mov r1, r8
 *   @0x14fa38 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14fa3c b 0x14f958 <_Z26F_PhysicsCreatePulleyJointR6RValueP9CInstanceS2_iPS_+0x1c8>
 *   @0x14fa40 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x14fa44 eoreq r2, r10, r8, lsr #9
 *   @0x14fa48 .word 0xffffbd00
 *   @0x14fa4c .word 0xffffbcd8
 *   @0x14fa50 andseq r5, pc, r12, lsr #11
 *   @0x14fa54 andseq r4, pc, r0, lsl #9
 *   @0x14fa58 andseq r5, pc, r8, asr #7
 *   @0x14fa5c andseq r5, pc, r0, lsl #7
 *
 * ══ §8/43 F_PhysicsCreateWheelJoint(RValue&, CInstance*, CInstance*, int, RValue*)  0x14fa60  size 720  180 条（0x14fa60..0x14fd30）
 * @func 0x14fa60 0x14fd30  size 720  180 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x14fb00→0x54298c, 0x14fc40→0x54298c
 * 调用序列: YYGetFloat(RValue const*, int)×8 / YYGetInt32(RValue const*, int)×4 / Error_Show_Action(char const*, bool)×4 / Object_GetInstance(int, CInstance*, CInstance*)×2 / YYGetBool(RValue const*, int)×2 / 0xb65b0×2 / 0xb65c8×2 / CPhysicsWorld::CreateWheelJoint(CPhysicsObject*, CPhysicsObject*, float, float, float, float, bool, float, float, float, float, bool)
 * 字段偏移 top8: 0x3c×3 / 0xc×2 / 0x4×2 / 0x14c×2 / 0x84×2 / 0xb4×2 / 0x2c×2 / 0x30×2
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14fa60 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x14fa64 sub sp, sp, #340
 *   @0x14fa68 ldr r9, [pc, #0x2a4]
 *   @0x14fa6c mov r7, r2
 *   @0x14fa70 ldr r12, [pc, #0x2a0]
 *   @0x14fa74 mov r3, #0
 *   @0x14fa78 add r9, pc, r9
 *   @0x14fa7c ldr r4, [sp, #0x178]
 *   @0x14fa80 mov r5, r0
 *   @0x14fa84 mov r8, r1
 *   @0x14fa88 ldr r6, [r9, r12]
 *   @0x14fa8c mov r0, r3
 *   @0x14fa90 mov r1, r3
 *   @0x14fa94 movt r0, #0xbff0
 *   @0x14fa98 str r3, [r5, #0xc]
 *   @0x14fa9c ldr r2, [r6]
 *   @0x14faa0 str r0, [r5, #0x4]
 *   @0x14faa4 mov r0, r4
 *   @0x14faa8 str r3, [r5]
 *   @0x14faac str r2, [sp, #0x14c]
 *   @0x14fab0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14fab4 mov r1, r8
 *   @0x14fab8 mov r2, r7
 *   @0x14fabc bl 0x14ec2c <_Z18Object_GetInstanceiP9CInstanceS0_>
 *   @0x14fac0 subs r10, r0, #0
 *   @0x14fac4 beq 0x14fc80 <_Z25F_PhysicsCreateWheelJointR6RValueP9CInstanceS2_iPS_+0x220>
 *   @0x14fac8 mov r1, #1
 *   @0x14facc mov r0, r4
 *   @0x14fad0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14fad4 mov r1, r8
 *   @0x14fad8 mov r2, r7
 *   @0x14fadc bl 0x14ec2c <_Z18Object_GetInstanceiP9CInstanceS0_>
 *   @0x14fae0 subs r8, r0, #0
 *   @0x14fae4 beq 0x14fcc8 <_Z25F_PhysicsCreateWheelJointR6RValueP9CInstanceS2_iPS_+0x268>
 *   @0x14fae8 ldr r7, [r10, #0x84]
 *   @0x14faec cmp r7, #0
 *   @0x14faf0 beq 0x14fc40 <_Z25F_PhysicsCreateWheelJointR6RValueP9CInstanceS2_iPS_+0x1e0>
 *   @0x14faf4 ldr r8, [r8, #0x84]
 *   @0x14faf8 cmp r8, #0
 *   @0x14fafc beq 0x14fc40 <_Z25F_PhysicsCreateWheelJointR6RValueP9CInstanceS2_iPS_+0x1e0>
 *   @0x14fb00 ldr r3, [pc, #0x214]
 *   @0x14fb04 ldr r3, [r9, r3]
 *   @0x14fb08 ldr r3, [r3]
 *   @0x14fb0c ldr r9, [r3, #0xb4]
 *   @0x14fb10 cmp r9, #0
 *   @0x14fb14 beq 0x14fc6c <_Z25F_PhysicsCreateWheelJointR6RValueP9CInstanceS2_iPS_+0x20c>
 *   @0x14fb18 mov r1, #2
 *   @0x14fb1c mov r0, r4
 *   @0x14fb20 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14fb24 mov r1, #3
 *   @0x14fb28 mov r3, r0
 *   @0x14fb2c mov r0, r4
 *   @0x14fb30 str r3, [sp, #0x2c]
 *   @0x14fb34 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14fb38 mov r1, #4
 *   @0x14fb3c mov r12, r0
 *   @0x14fb40 mov r0, r4
 *   @0x14fb44 str r12, [sp, #0x30]
 *   @0x14fb48 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14fb4c mov r1, #5
 *   @0x14fb50 mov r2, r0
 *   @0x14fb54 mov r0, r4
 *   @0x14fb58 str r2, [sp, #0x34]
 *   @0x14fb5c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14fb60 mov r1, #6
 *   @0x14fb64 str r0, [sp, #0x38]
 *   @0x14fb68 mov r0, r4
 *   @0x14fb6c bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x14fb70 mov r1, #7
 *   @0x14fb74 str r0, [sp, #0x44]
 *   @0x14fb78 mov r0, r4
 *   @0x14fb7c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14fb80 mov r1, #8
 *   @0x14fb84 str r0, [sp, #0x3c]
 *   @0x14fb88 mov r0, r4
 *   @0x14fb8c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14fb90 mov r1, #9
 *   @0x14fb94 str r0, [sp, #0x40]
 *   @0x14fb98 mov r0, r4
 *   @0x14fb9c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14fba0 mov r1, #10
 *   @0x14fba4 mov r11, r0
 *   @0x14fba8 mov r0, r4
 *   @0x14fbac bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14fbb0 mov r1, #11
 *   @0x14fbb4 mov r10, r0
 *   @0x14fbb8 mov r0, r4
 *   @0x14fbbc bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x14fbc0 ldr r2, [sp, #0x34]
 *   @0x14fbc4 ldr r12, [sp, #0x30]
 *   @0x14fbc8 mov r1, r7
 *   @0x14fbcc ldr r3, [sp, #0x2c]
 *   @0x14fbd0 str r2, [sp, #0x4]
 *   @0x14fbd4 ldr r2, [sp, #0x38]
 *   @0x14fbd8 str r12, [sp]
 *   @0x14fbdc str r11, [sp, #0x18]
 *   @0x14fbe0 str r2, [sp, #0x8]
 *   @0x14fbe4 ldr r2, [sp, #0x44]
 *   @0x14fbe8 str r10, [sp, #0x1c]
 *   @0x14fbec str r2, [sp, #0xc]
 *   @0x14fbf0 ldr r2, [sp, #0x3c]
 *   @0x14fbf4 str r2, [sp, #0x10]
 *   @0x14fbf8 ldr r2, [sp, #0x40]
 *   @0x14fbfc str r2, [sp, #0x14]
 *   @0x14fc00 mov r2, r8
 *   @0x14fc04 str r0, [sp, #0x20]
 *   @0x14fc08 mov r0, r9
 *   @0x14fc0c bl 0x239444 <_ZN13CPhysicsWorld16CreateWheelJointEP14CPhysicsObjectS1_ffffbffffb>
 *   @0x14fc10 vmov s15, r0
 *   @0x14fc14 vcvt.f64.s32 d7, s15
 *   @0x14fc18 vmov r0, r1, d7
 *   @0x14fc1c vmov r2, s14
 *   @0x14fc20 mov r3, r1
 *   @0x14fc24 stm r5, {r2, r3}
 *   @0x14fc28 ldr r2, [sp, #0x14c]
 *   @0x14fc2c ldr r3, [r6]
 *   @0x14fc30 cmp r2, r3
 *   @0x14fc34 bne 0x14fd10 <_Z25F_PhysicsCreateWheelJointR6RValueP9CInstanceS2_iPS_+0x2b0>
 *   @0x14fc38 add sp, sp, #340
 *   @0x14fc3c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x14fc40 ldr r3, [pc, #0xd4]
 *   @0x14fc44 ldr r3, [r9, r3]
 *   @0x14fc48 ldr r3, [r3]
 *   @0x14fc4c ldr r3, [r3, #0xb4]
 *   @0x14fc50 cmp r3, #0
 *   @0x14fc54 beq 0x14fc6c <_Z25F_PhysicsCreateWheelJointR6RValueP9CInstanceS2_iPS_+0x20c>
 *   @0x14fc58 ldr r0, [pc, #0xc0]
 *   @0x14fc5c mov r1, #0
 *   @0x14fc60 add r0, pc, r0
 *   @0x14fc64 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14fc68 b 0x14fc28 <_Z25F_PhysicsCreateWheelJointR6RValueP9CInstanceS2_iPS_+0x1c8>
 *   @0x14fc6c ldr r0, [pc, #0xb0]
 *   @0x14fc70 mov r1, #0
 *   @0x14fc74 add r0, pc, r0
 *   @0x14fc78 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14fc7c b 0x14fc28 <_Z25F_PhysicsCreateWheelJointR6RValueP9CInstanceS2_iPS_+0x1c8>
 *   @0x14fc80 add r5, sp, #76
 *   @0x14fc84 mov r1, r10
 *   @0x14fc88 mov r2, #256
 *   @0x14fc8c mov r0, r5
 *   @0x14fc90 bl 0xb65b0 <memset@plt>
 *   @0x14fc94 mov r1, r10
 *   @0x14fc98 mov r0, r4
 *   @0x14fc9c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14fca0 ldr r2, [pc, #0x80]
 *   @0x14fca4 mov r1, #256
 *   @0x14fca8 add r2, pc, r2
 *   @0x14fcac mov r3, r0
 *   @0x14fcb0 mov r0, r5
 *   @0x14fcb4 bl 0xb65c8 <snprintf@plt>
 *   @0x14fcb8 mov r0, r5
 *   @0x14fcbc mov r1, r10
 *   @0x14fcc0 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14fcc4 b 0x14fc28 <_Z25F_PhysicsCreateWheelJointR6RValueP9CInstanceS2_iPS_+0x1c8>
 *   @0x14fcc8 add r5, sp, #76
 *   @0x14fccc mov r1, r8
 *   @0x14fcd0 mov r2, #256
 *   @0x14fcd4 mov r0, r5
 *   @0x14fcd8 bl 0xb65b0 <memset@plt>
 *   @0x14fcdc mov r0, r4
 *   @0x14fce0 mov r1, #1
 *   @0x14fce4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14fce8 ldr r2, [pc, #0x3c]
 *   @0x14fcec mov r1, #256
 *   @0x14fcf0 add r2, pc, r2
 *   @0x14fcf4 mov r3, r0
 *   @0x14fcf8 mov r0, r5
 *   @0x14fcfc bl 0xb65c8 <snprintf@plt>
 *   @0x14fd00 mov r0, r5
 *   @0x14fd04 mov r1, r8
 *   @0x14fd08 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14fd0c b 0x14fc28 <_Z25F_PhysicsCreateWheelJointR6RValueP9CInstanceS2_iPS_+0x1c8>
 *   @0x14fd10 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x14fd14 .word 0x002a21d8
 *   @0x14fd18 .word 0xffffbd00
 *   @0x14fd1c .word 0xffffbcd8
 *   @0x14fd20 ldrsbeq r5, [pc], -r12
 *   @0x14fd24 ldrheq r4, [pc], -r0
 *   @0x14fd28 ldrsheq r5, [pc], -r8
 *   @0x14fd2c ldrheq r5, [pc], -r0
 *
 * ══ §9/43 GR_Text_Draw_Transformed(float, float, char const*, int, int, float, float, float)  0x173068  size 720  180 条（0x173068..0x173338）
 * @func 0x173068 0x173338  size 720  180 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / CFontGM::TextWidth(unsigned short*)×2 / GraphicsPerf::Push(unsigned int, char const*) / SetFont() / Split_TextBlock(char const*, int, TStringList*) / 0xb6580 / 0xb658c / GR_Text_Draw_Transformed(float, float, char const*, int, int, float, float, float)+0x28c
 * 字段偏移 top8: 0x18×4 / 0x20×4 / 0x24×2 / 0x34×2 / 0x29c×1 / 0x78×1 / 0x1c×1 / 0x240×1
 * VFP 指令 55 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x173068 push {r4, r5, r6, r7, r8, lr}
 *   @0x17306c vpush {d8, d9, d10, d11, d12, d13, d14}
 *   @0x173070 sub sp, sp, #40
 *   @0x173074 vldr s27, [sp, #132]
 *   @0x173078 vmov s17, r1
 *   @0x17307c ldr r1, [pc, #0x29c]
 *   @0x173080 ldr r5, [sp, #0x78]
 *   @0x173084 mov r6, r2
 *   @0x173088 add r1, pc, r1
 *   @0x17308c vmov s16, r0
 *   @0x173090 mov r0, #65280
 *   @0x173094 movt r0, #0xff
 *   @0x173098 mov r12, #0
 *   @0x17309c mov r4, r3
 *   @0x1730a0 str r12, [sp, #0x1c]
 *   @0x1730a4 vldr s26, [sp, #124]
 *   @0x1730a8 str r12, [sp, #0x18]
 *   @0x1730ac vldr s25, [sp, #128]
 *   @0x1730b0 str r12, [sp, #0x24]
 *   @0x1730b4 vldr s18, [pc, #600]
 *   @0x1730b8 str r12, [sp, #0x20]
 *   @0x1730bc bl 0x17b8f0 <_ZN12GraphicsPerf4PushEjPKc>
 *   @0x1730c0 bl 0x1724e4 <_Z7SetFontv>
 *   @0x1730c4 mov r0, r6
 *   @0x1730c8 mov r1, r5
 *   @0x1730cc add r2, sp, #24
 *   @0x1730d0 bl 0x172560 <_Z15Split_TextBlockPKciP11TStringList>
 *   @0x1730d4 vmul.f32 s18, s27, s18
 *   @0x1730d8 vldr s15, [pc, #568]
 *   @0x1730dc ldr r6, [pc, #0x240]
 *   @0x1730e0 add r6, pc, r6
 *   @0x1730e4 vdiv.f32 s18, s18, s15
 *   @0x1730e8 vmov r0, s18
 *   @0x1730ec bl 0xb6580 <sinf@plt>
 *   @0x1730f0 vmov s22, r0
 *   @0x1730f4 vmov r0, s18
 *   @0x1730f8 bl 0xb658c <cosf@plt>
 *   @0x1730fc cmp r4, #0
 *   @0x173100 vmov s23, r0
 *   @0x173104 blt 0x1732f4 <_Z24GR_Text_Draw_TransformedffPKciifff+0x28c>
 *   @0x173108 vmul.f32 s20, s22, s25
 *   @0x17310c ldr r3, [pc, #0x214]
 *   @0x173110 vmov s14, r4
 *   @0x173114 ldr r1, [sp, #0x20]
 *   @0x173118 ldr r3, [r6, r3]
 *   @0x17311c ldr r3, [r3]
 *   @0x173120 cmp r3, #1
 *   @0x173124 vmul.f32 s21, s23, s25
 *   @0x173128 vcvt.f32.s32 s15, s14
 *   @0x17312c vmul.f32 s20, s20, s15
 *   @0x173130 vmul.f32 s21, s15, s21
 *   @0x173134 beq 0x1732d4 <_Z24GR_Text_Draw_TransformedffPKciifff+0x26c>
 *   @0x173138 cmp r3, #2
 *   @0x17313c vmoveq s14, r1
 *   @0x173140 vcvteq.f32.s32 s15, s14
 *   @0x173144 vmlseq.f32 s17, s15, s21
 *   @0x173148 vmlseq.f32 s16, s20, s15
 *   @0x17314c cmp r1, #0
 *   @0x173150 ble 0x1731a4 <_Z24GR_Text_Draw_TransformedffPKciifff+0x13c>
 *   @0x173154 mov r4, #0
 *   @0x173158 vldr s24, [pc, #444]
 *   @0x17315c vmov.f32 s28, #5.000000e-01
 *   @0x173160 ldr r3, [sp, #0x18]
 *   @0x173164 cmp r3, #0
 *   @0x173168 beq 0x173190 <_Z24GR_Text_Draw_TransformedffPKciifff+0x128>
 *   @0x17316c cmp r4, #0
 *   @0x173170 movne r2, r4
 *   @0x173174 bne 0x173184 <_Z24GR_Text_Draw_TransformedffPKciifff+0x11c>
 *   @0x173178 b 0x1731f0 <_Z24GR_Text_Draw_TransformedffPKciifff+0x188>
 *   @0x17317c subs r2, r2, #1
 *   @0x173180 beq 0x1731f0 <_Z24GR_Text_Draw_TransformedffPKciifff+0x188>
 *   @0x173184 ldr r3, [r3]
 *   @0x173188 cmp r3, #0
 *   @0x17318c bne 0x17317c <_Z24GR_Text_Draw_TransformedffPKciifff+0x114>
 *   @0x173190 add r4, r4, #1
 *   @0x173194 vadd.f32 s16, s16, s20
 *   @0x173198 cmp r1, r4
 *   @0x17319c vadd.f32 s17, s17, s21
 *   @0x1731a0 bgt 0x173160 <_Z24GR_Text_Draw_TransformedffPKciifff+0xf8>
 *   @0x1731a4 bl 0x17bb10 <_ZN12GraphicsPerf3PopEv>
 *   @0x1731a8 ldr r0, [sp, #0x18]
 *   @0x1731ac cmp r0, #0
 *   @0x1731b0 beq 0x1731c8 <_Z24GR_Text_Draw_TransformedffPKciifff+0x160>
 *   @0x1731b4 ldr r4, [r0]
 *   @0x1731b8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1731bc cmp r4, #0
 *   @0x1731c0 mov r0, r4
 *   @0x1731c4 bne 0x1731b4 <_Z24GR_Text_Draw_TransformedffPKciifff+0x14c>
 *   @0x1731c8 ldr r0, [sp, #0x24]
 *   @0x1731cc mov r3, #0
 *   @0x1731d0 str r3, [sp, #0x20]
 *   @0x1731d4 cmp r0, r3
 *   @0x1731d8 str r3, [sp, #0x18]
 *   @0x1731dc beq 0x1731e4 <_Z24GR_Text_Draw_TransformedffPKciifff+0x17c>
 *   @0x1731e0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1731e4 add sp, sp, #40
 *   @0x1731e8 vpop {d8, d9, d10, d11, d12, d13, d14}
 *   @0x1731ec pop {r4, r5, r6, r7, r8, pc}
 *   @0x1731f0 ldr r5, [r3, #0x4]
 *   @0x1731f4 cmp r5, #0
 *   @0x1731f8 beq 0x173190 <_Z24GR_Text_Draw_TransformedffPKciifff+0x128>
 *   @0x1731fc ldrh r3, [r5]
 *   @0x173200 cmp r3, #0
 *   @0x173204 beq 0x173190 <_Z24GR_Text_Draw_TransformedffPKciifff+0x128>
 *   @0x173208 ldr r3, [pc, #0x11c]
 *   @0x17320c ldr r8, [r6, r3]
 *   @0x173210 ldr r3, [r8]
 *   @0x173214 cmp r3, #1
 *   @0x173218 beq 0x173288 <_Z24GR_Text_Draw_TransformedffPKciifff+0x220>
 *   @0x17321c ldr r2, [pc, #0x10c]
 *   @0x173220 cmp r3, #2
 *   @0x173224 vldr s15, [pc, #240]
 *   @0x173228 ldr r7, [r6, r2]
 *   @0x17322c beq 0x1732b8 <_Z24GR_Text_Draw_TransformedffPKciifff+0x250>
 *   @0x173230 vmov.f32 s19, s16
 *   @0x173234 ldr r7, [r7]
 *   @0x173238 vmov.f32 s18, s17
 *   @0x17323c vmla.f32 s19, s23, s15
 *   @0x173240 vmls.f32 s18, s22, s15
 *   @0x173244 bl 0x169ecc <_Z17GR_Draw_Get_Colorv>
 *   @0x173248 mov r8, r0
 *   @0x17324c bl 0x169f1c <_Z17GR_Draw_Get_Alphav>
 *   @0x173250 vmla.f32 s19, s22, s24
 *   @0x173254 str r8, [sp, #0xc]
 *   @0x173258 vstr s26, [sp]
 *   @0x17325c vstr s25, [sp, #4]
 *   @0x173260 vstr s27, [sp, #8]
 *   @0x173264 mov r3, r5
 *   @0x173268 vmla.f32 s18, s23, s24
 *   @0x17326c vmov r1, s19
 *   @0x173270 str r0, [sp, #0x10]
 *   @0x173274 mov r0, r7
 *   @0x173278 vmov r2, s18
 *   @0x17327c bl 0xf830c <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf>
 *   @0x173280 ldr r1, [sp, #0x20]
 *   @0x173284 b 0x173190 <_Z24GR_Text_Draw_TransformedffPKciifff+0x128>
 *   @0x173288 ldr r3, [pc, #0xa0]
 *   @0x17328c mov r1, r5
 *   @0x173290 ldr r7, [r6, r3]
 *   @0x173294 ldr r0, [r7]
 *   @0x173298 bl 0xf8b04 <_ZN7CFontGM9TextWidthEPt>
 *   @0x17329c ldr r3, [r8]
 *   @0x1732a0 cmp r3, #2
 *   @0x1732a4 vmov s14, r0
 *   @0x1732a8 vcvt.f32.s32 s15, s14
 *   @0x1732ac vmul.f32 s15, s15, s26
 *   @0x1732b0 vnmul.f32 s15, s28, s15
 *   @0x1732b4 bne 0x173230 <_Z24GR_Text_Draw_TransformedffPKciifff+0x1c8>
 *   @0x1732b8 ldr r0, [r7]
 *   @0x1732bc mov r1, r5
 *   @0x1732c0 bl 0xf8b04 <_ZN7CFontGM9TextWidthEPt>
 *   @0x1732c4 vmov s14, r0
 *   @0x1732c8 vcvt.f32.s32 s15, s14
 *   @0x1732cc vnmul.f32 s15, s26, s15
 *   @0x1732d0 b 0x173230 <_Z24GR_Text_Draw_TransformedffPKciifff+0x1c8>
 *   @0x1732d4 vmov s14, r1
 *   @0x1732d8 vcvt.f32.s32 s15, s14
 *   @0x1732dc vmul.f32 s13, s15, s21
 *   @0x1732e0 vmul.f32 s14, s20, s15
 *   @0x1732e4 vmov.f32 s15, #5.000000e-01
 *   @0x1732e8 vmls.f32 s17, s13, s15
 *   @0x1732ec vmls.f32 s16, s14, s15
 *   @0x1732f0 b 0x17314c <_Z24GR_Text_Draw_TransformedffPKciifff+0xe4>
 *   @0x1732f4 ldr r3, [pc, #0x34]
 *   @0x1732f8 ldr r1, [pc, #0x34]
 *   @0x1732fc ldr r7, [r6, r3]
 *   @0x173300 add r1, pc, r1
 *   @0x173304 ldr r0, [r7]
 *   @0x173308 bl 0xf93a4 <_ZN7CFontGM10TextHeightEPt>
 *   @0x17330c mov r4, r0
 *   @0x173310 b 0x173108 <_Z24GR_Text_Draw_TransformedffPKciifff+0xa0>
 *   @0x173314 ldrdmi r0, r1, [r9], #-251
 *   @0x173318 teqmi r4, #0
 *   @0x17331c andeq r0, r0, r0
 *   @0x173320 andseq r8, sp, r4, lsl #9
 *   @0x173324 eoreq lr, r7, r0, ror r11
 *   @0x173328 .word 0xffffe65c
 *   @0x17332c .word 0xffffe658
 *   @0x173330 .word 0xffffe654
 *   @0x173334 andseq r8, sp, r8, lsl #4
 *
 * ══ §10/43 Call_ScriptRef(YYObjectBase*, RValue*, CScriptRef*, int, RValue*)  0x249590  size 720  180 条（0x249590..0x249860）
 * @func 0x249590 0x249860  size 720  180 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CScript::GetCode()×3 / YYAllocLocalStackNew(int) / VM::Exec(CCode*, YYObjectBase*, YYObjectBase*, RValue*, YYObjectBase*, int, RValue*, int, YYObjectBase*) / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65bc / PushContextStack(YYObjectBase*) / PopContextStack() / YYObjectBase::Free(YYObjectBase*)
 * 字段偏移 top8: 0x58×6 / 0x78×4 / 0x1c×3 / 0x8×3 / 0x4×2 / 0x20×2 / 0x88×1 / 0x64×1
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x249590 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x249594 mov r8, r2
 *   @0x249598 ldr r2, [r2, #0x88]
 *   @0x24959c mov r7, r0
 *   @0x2495a0 ldr r5, [r8, #0x64]
 *   @0x2495a4 sub sp, sp, #52
 *   @0x2495a8 cmp r2, #6
 *   @0x2495ac ldr r4, [pc, #0x28c]
 *   @0x2495b0 mov r9, r1
 *   @0x2495b4 mov r6, r3
 *   @0x2495b8 ldreq r7, [r8, #0x7c]
 *   @0x2495bc cmp r5, #0
 *   @0x2495c0 add r4, pc, r4
 *   @0x2495c4 beq 0x24976c <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0x1dc>
 *   @0x2495c8 ldr r3, [pc, #0x274]
 *   @0x2495cc ldr r3, [r4, r3]
 *   @0x2495d0 ldr r0, [r3]
 *   @0x2495d4 bl 0xd41e4 <_Z20YYAllocLocalStackNewi>
 *   @0x2495d8 ldr r3, [r8, #0x78]
 *   @0x2495dc cmp r3, #6
 *   @0x2495e0 ldreq r3, [r8, #0x6c]
 *   @0x2495e4 streq r3, [r0, #0xc]
 *   @0x2495e8 mov r10, r0
 *   @0x2495ec ldr r3, [pc, #0x254]
 *   @0x2495f0 ldr r11, [r4, r3]
 *   @0x2495f4 ldr r0, [r11]
 *   @0x2495f8 cmn r0, #1
 *   @0x2495fc movne r1, r0
 *   @0x249600 beq 0x249818 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0x288>
 *   @0x249604 ldr r3, [r8, #0x4]
 *   @0x249608 cmp r3, #0
 *   @0x24960c beq 0x249834 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0x2a4>
 *   @0x249610 add r0, r3, r1, lsl #4
 *   @0x249614 vmov s12, r6
 *   @0x249618 ldm r0, {r2, r3}
 *   @0x24961c vcvt.f64.s32 d7, s12
 *   @0x249620 vmov d6, r2, r3
 *   @0x249624 vcmpe.f64 d6, d7
 *   @0x249628 vmrs APSR_nzcv, fpscr
 *   @0x24962c bgt 0x2496e8 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0x158>
 *   @0x249630 mov r11, #0
 *   @0x249634 mov r0, r5
 *   @0x249638 mov r3, #0
 *   @0x24963c str r3, [sp, #0x20]
 *   @0x249640 str r3, [sp, #0x1c]
 *   @0x249644 bl 0x1dfba8 <_ZN7CScript7GetCodeEv>
 *   @0x249648 ldr r3, [sp, #0x1c]
 *   @0x24964c ldr r2, [r0, #0x78]
 *   @0x249650 tst r2, #1
 *   @0x249654 bne 0x2497fc <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0x26c>
 *   @0x249658 ldr r3, [pc, #0x1ec]
 *   @0x24965c ldr r8, [r4, r3]
 *   @0x249660 ldrb r3, [r8]
 *   @0x249664 cmp r3, #0
 *   @0x249668 bne 0x2497e0 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0x250>
 *   @0x24966c ldr r12, [sp, #0x58]
 *   @0x249670 mov r3, r9
 *   @0x249674 ldr lr, [sp, #0x20]
 *   @0x249678 mov r1, r7
 *   @0x24967c ldr r0, [r5, #0x8]
 *   @0x249680 mov r2, r7
 *   @0x249684 str r12, [sp, #0x8]
 *   @0x249688 mov r12, #0
 *   @0x24968c str r10, [sp]
 *   @0x249690 str r6, [sp, #0x4]
 *   @0x249694 str lr, [sp, #0x10]
 *   @0x249698 str r12, [sp, #0xc]
 *   @0x24969c bl 0xe7fd0 <_ZN2VM4ExecEP5CCodeP12YYObjectBaseS3_P6RValueS3_iS5_iS3_>
 *   @0x2496a0 ldrb r3, [r8]
 *   @0x2496a4 cmp r3, #0
 *   @0x2496a8 bne 0x2497d0 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0x240>
 *   @0x2496ac cmp r11, #0
 *   @0x2496b0 bne 0x2497c4 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0x234>
 *   @0x2496b4 mov r0, r5
 *   @0x2496b8 bl 0x1dfba8 <_ZN7CScript7GetCodeEv>
 *   @0x2496bc ldr r3, [r0, #0x78]
 *   @0x2496c0 tst r3, #2
 *   @0x2496c4 beq 0x2497a4 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0x214>
 *   @0x2496c8 ldr r3, [pc, #0x180]
 *   @0x2496cc ldr r3, [r4, r3]
 *   @0x2496d0 ldrb r0, [r3]
 *   @0x2496d4 cmp r0, #0
 *   @0x2496d8 movne r0, #2
 *   @0x2496dc moveq r0, #0
 *   @0x2496e0 add sp, sp, #52
 *   @0x2496e4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2496e8 vcvt.s32.f64 s13, d6
 *   @0x2496ec vmov r12, s13
 *   @0x2496f0 cmp r6, r12
 *   @0x2496f4 bge 0x249630 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0xa0>
 *   @0x2496f8 lsl r11, r12, #4
 *   @0x2496fc ldr r1, [pc, #0x150]
 *   @0x249700 lsl r6, r6, #4
 *   @0x249704 mov r3, #1
 *   @0x249708 add r1, pc, r1
 *   @0x24970c mov r2, #70
 *   @0x249710 mov r0, r11
 *   @0x249714 vstr s13, [sp, #28]
 *   @0x249718 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x24971c mov r2, r6
 *   @0x249720 ldr r1, [sp, #0x58]
 *   @0x249724 bl 0xb65bc <memcpy@plt>
 *   @0x249728 ldr r12, [sp, #0x1c]
 *   @0x24972c mov r2, #0
 *   @0x249730 mov r1, #5
 *   @0x249734 add r6, r0, r6
 *   @0x249738 add r11, r0, r11
 *   @0x24973c mov r3, r0
 *   @0x249740 str r2, [r6]
 *   @0x249744 add r6, r6, #16
 *   @0x249748 str r2, [r6, #-0xc]
 *   @0x24974c str r2, [r6, #-0x8]
 *   @0x249750 str r1, [r6, #-0x4]
 *   @0x249754 cmp r6, r11
 *   @0x249758 bne 0x249740 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0x1b0>
 *   @0x24975c str r3, [sp, #0x58]
 *   @0x249760 mov r6, r12
 *   @0x249764 mov r11, #1
 *   @0x249768 b 0x249634 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0xa4>
 *   @0x24976c ldr r5, [r8, #0x68]
 *   @0x249770 cmp r5, #0
 *   @0x249774 beq 0x2496c8 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0x138>
 *   @0x249778 mov r0, r7
 *   @0x24977c bl 0xd3968 <_Z16PushContextStackP12YYObjectBase>
 *   @0x249780 ldr r12, [sp, #0x58]
 *   @0x249784 mov r1, r7
 *   @0x249788 mov r0, r9
 *   @0x24978c mov r3, r6
 *   @0x249790 mov r2, r7
 *   @0x249794 str r12, [sp]
 *   @0x249798 blx r5
 *   @0x24979c bl 0xd3a34 <_Z15PopContextStackv>
 *   @0x2497a0 b 0x2496c8 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0x138>
 *   @0x2497a4 mov r0, r5
 *   @0x2497a8 bl 0x1dfba8 <_ZN7CScript7GetCodeEv>
 *   @0x2497ac ldr r3, [r0, #0x78]
 *   @0x2497b0 tst r3, #1
 *   @0x2497b4 bne 0x2496c8 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0x138>
 *   @0x2497b8 mov r0, r10
 *   @0x2497bc bl 0x198f88 <_ZN12YYObjectBase4FreeEPS_>
 *   @0x2497c0 b 0x2496c8 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0x138>
 *   @0x2497c4 ldr r0, [sp, #0x58]
 *   @0x2497c8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2497cc b 0x2496b4 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0x124>
 *   @0x2497d0 ldr r3, [pc, #0x80]
 *   @0x2497d4 ldr r0, [r4, r3]
 *   @0x2497d8 bl 0x2a08ac <_ZN9CProfiler3PopEv>
 *   @0x2497dc b 0x2496ac <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0x11c>
 *   @0x2497e0 ldr r2, [pc, #0x70]
 *   @0x2497e4 mov r1, #1
 *   @0x2497e8 ldr r3, [r5, #0x8]
 *   @0x2497ec ldr r0, [r4, r2]
 *   @0x2497f0 ldr r2, [r3, #0x60]
 *   @0x2497f4 bl 0x2a0738 <_ZN9CProfiler4PushEii>
 *   @0x2497f8 b 0x24966c <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0xdc>
 *   @0x2497fc str r3, [sp]
 *   @0x249800 mov r1, r8
 *   @0x249804 add r0, sp, #32
 *   @0x249808 mov r2, r6
 *   @0x24980c ldr r3, [sp, #0x58]
 *   @0x249810 bl 0x248b58 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b>
 *   @0x249814 b 0x249658 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0xc8>
 *   @0x249818 ldr r1, [pc, #0x3c]
 *   @0x24981c mov r0, r8
 *   @0x249820 add r1, pc, r1
 *   @0x249824 bl 0xd21ec <_Z33Code_Variable_Find_Slot_From_NameP12YYObjectBasePKc>
 *   @0x249828 mov r1, r0
 *   @0x24982c str r0, [r11]
 *   @0x249830 b 0x249604 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0x74>
 *   @0x249834 mov r0, r8
 *   @0x249838 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x24983c b 0x249614 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_+0x84>
 *   @0x249840 mulseq r10, r0, r6
 *   @0x249844 .word 0xffffc104
 *   @0x249848 .word 0xffffc05c
 *   @0x24984c .word 0xffffbf18
 *   @0x249850 .word 0xffffc0cc
 *   @0x249854 andeq r7, lr, r8, lsr #18
 *   @0x249858 .word 0xffffbf1c
 *   @0x24985c andeq r7, lr, r12, asr #32
 *
 * ══ §11/43 Audio_CreateStream(char const*)  0x21d6dc  size 716  179 条（0x21d6dc..0x21d9a8）
 * @func 0x21d6dc 0x21d9a8  size 716  179 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x21d724→0x755304, 0x21d8d4→0x3eb70c, 0x21d91c→0x3eb70c
 * 调用序列: operator new(unsigned int)×2 / cAudio_Sound::cAudio_Sound()×2 / YYStrDup(char const*)×2 / LoadSave::SaveFileExists(char const*) / LoadSave::_GetSaveFileName(char*, int, char const*) / Audio_CreateStream(char const*)+0x90 / Audio_CreateStream(char const*)+0x14c / cAudio_Sound::~cAudio_Sound()
 * 字段偏移 top8: 0x4×10 / 0xc×4 / 0x81c×2 / 0x2×2 / 0x10×2 / 0x14×2 / 0xc0×2 / 0x78×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21d6dc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x21d6e0 sub sp, sp, #2080
 *   @0x21d6e4 ldr r5, [pc, #0x2a0]
 *   @0x21d6e8 sub sp, sp, #4
 *   @0x21d6ec ldr r3, [pc, #0x29c]
 *   @0x21d6f0 mov r4, r0
 *   @0x21d6f4 add r5, pc, r5
 *   @0x21d6f8 ldr r6, [r5, r3]
 *   @0x21d6fc ldr r3, [r6]
 *   @0x21d700 str r3, [sp, #0x81c]
 *   @0x21d704 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0x21d708 cmp r0, #0
 *   @0x21d70c beq 0x21d840 <_Z18Audio_CreateStreamPKc+0x164>
 *   @0x21d710 add r7, sp, #28
 *   @0x21d714 mov r2, r4
 *   @0x21d718 mov r1, #2048
 *   @0x21d71c mov r0, r7
 *   @0x21d720 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x21d724 ldr r3, [pc, #0x268]
 *   @0x21d728 ldr r8, [r5, r3]
 *   @0x21d72c ldr r12, [r8]
 *   @0x21d730 cmp r12, #0
 *   @0x21d734 ble 0x21d76c <_Z18Audio_CreateStreamPKc+0x90>
 *   @0x21d738 ldr r2, [r8, #0x4]
 *   @0x21d73c ldr r4, [r2]
 *   @0x21d740 cmp r4, #0
 *   @0x21d744 movne r3, #0
 *   @0x21d748 bne 0x21d760 <_Z18Audio_CreateStreamPKc+0x84>
 *   @0x21d74c b 0x21d980 <_Z18Audio_CreateStreamPKc+0x2a4>
 *   @0x21d750 ldr r1, [r2, #0x4]!
 *   @0x21d754 lsl r4, r3, #2
 *   @0x21d758 cmp r1, #0
 *   @0x21d75c beq 0x21d954 <_Z18Audio_CreateStreamPKc+0x278>
 *   @0x21d760 add r3, r3, #1
 *   @0x21d764 cmp r3, r12
 *   @0x21d768 bne 0x21d750 <_Z18Audio_CreateStreamPKc+0x74>
 *   @0x21d76c mov r0, #96
 *   @0x21d770 bl 0x27c524 <_Znwj>
 *   @0x21d774 mov r9, r0
 *   @0x21d778 bl 0x218ea4 <_ZN12cAudio_SoundC2Ev>
 *   @0x21d77c ldr r4, [r8]
 *   @0x21d780 adds r11, r4, #1
 *   @0x21d784 bne 0x21d868 <_Z18Audio_CreateStreamPKc+0x18c>
 *   @0x21d788 ldr r3, [r8, #0x4]
 *   @0x21d78c cmp r3, #0
 *   @0x21d790 beq 0x21d828 <_Z18Audio_CreateStreamPKc+0x14c>
 *   @0x21d794 cmp r4, #0
 *   @0x21d798 ble 0x21d828 <_Z18Audio_CreateStreamPKc+0x14c>
 *   @0x21d79c mov r10, r11
 *   @0x21d7a0 mov r1, r11
 *   @0x21d7a4 ldr r0, [r3]
 *   @0x21d7a8 movw r2, #0xfeee
 *   @0x21d7ac movt r2, #0xfeee
 *   @0x21d7b0 cmp r0, r2
 *   @0x21d7b4 beq 0x21d818 <_Z18Audio_CreateStreamPKc+0x13c>
 *   @0x21d7b8 ldr r2, [r3, r10, lsl #2]
 *   @0x21d7bc lsl r12, r10, #2
 *   @0x21d7c0 add r0, r3, r12
 *   @0x21d7c4 cmp r2, #0
 *   @0x21d7c8 beq 0x21d818 <_Z18Audio_CreateStreamPKc+0x13c>
 *   @0x21d7cc ldr lr, [r2]
 *   @0x21d7d0 movw r3, #0xfeee
 *   @0x21d7d4 movt r3, #0xfeee
 *   @0x21d7d8 cmp lr, r3
 *   @0x21d7dc beq 0x21d810 <_Z18Audio_CreateStreamPKc+0x134>
 *   @0x21d7e0 mov r0, r2
 *   @0x21d7e4 str r1, [sp, #0xc]
 *   @0x21d7e8 str r12, [sp, #0x10]
 *   @0x21d7ec str r2, [sp, #0x14]
 *   @0x21d7f0 bl 0x218f24 <_ZN12cAudio_SoundD2Ev>
 *   @0x21d7f4 ldr r2, [sp, #0x14]
 *   @0x21d7f8 mov r0, r2
 *   @0x21d7fc bl 0x27d1d0 <_ZdlPv>
 *   @0x21d800 ldr r0, [r8, #0x4]
 *   @0x21d804 ldr r12, [sp, #0x10]
 *   @0x21d808 ldr r1, [sp, #0xc]
 *   @0x21d80c add r0, r0, r12
 *   @0x21d810 str r1, [r0]
 *   @0x21d814 ldr r3, [r8, #0x4]
 *   @0x21d818 ldr r2, [r8]
 *   @0x21d81c add r10, r10, #1
 *   @0x21d820 cmp r10, r2
 *   @0x21d824 blt 0x21d7a4 <_Z18Audio_CreateStreamPKc+0xc8>
 *   @0x21d828 mov r0, r3
 *   @0x21d82c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21d830 mov r2, #0
 *   @0x21d834 mov r3, r2
 *   @0x21d838 str r2, [r8, #0x4]
 *   @0x21d83c b 0x21d894 <_Z18Audio_CreateStreamPKc+0x1b8>
 *   @0x21d840 mov r0, r4
 *   @0x21d844 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0x21d848 cmp r0, #0
 *   @0x21d84c beq 0x21d91c <_Z18Audio_CreateStreamPKc+0x240>
 *   @0x21d850 add r7, sp, #28
 *   @0x21d854 mov r2, r4
 *   @0x21d858 mov r1, #2048
 *   @0x21d85c mov r0, r7
 *   @0x21d860 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc>
 *   @0x21d864 b 0x21d724 <_Z18Audio_CreateStreamPKc+0x48>
 *   @0x21d868 lsls r1, r11, #2
 *   @0x21d86c beq 0x21d948 <_Z18Audio_CreateStreamPKc+0x26c>
 *   @0x21d870 ldr r2, [pc, #0x120]
 *   @0x21d874 mov r3, #0
 *   @0x21d878 ldr r0, [r8, #0x4]
 *   @0x21d87c add r2, pc, r2
 *   @0x21d880 str r3, [sp]
 *   @0x21d884 mov r3, #135
 *   @0x21d888 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x21d88c mov r3, r0
 *   @0x21d890 str r0, [r8, #0x4]
 *   @0x21d894 add r10, r4, #299008
 *   @0x21d898 str r11, [r8]
 *   @0x21d89c add r10, r10, #992
 *   @0x21d8a0 str r9, [r3, r4, lsl #2]
 *   @0x21d8a4 mov r3, #1
 *   @0x21d8a8 mov r2, #0
 *   @0x21d8ac str r3, [r9, #0x3c]
 *   @0x21d8b0 mov r0, r7
 *   @0x21d8b4 strb r3, [r9, #0x24]
 *   @0x21d8b8 strb r3, [r9, #0x25]
 *   @0x21d8bc str r2, [r9, #0x18]
 *   @0x21d8c0 mov r2, #0
 *   @0x21d8c4 str r2, [r9, #0x34]
 *   @0x21d8c8 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x21d8cc str r0, [r9]
 *   @0x21d8d0 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x21d8d4 ldr r3, [pc, #0xc0]
 *   @0x21d8d8 ldr r1, [pc, #0xc0]
 *   @0x21d8dc mov r2, r10
 *   @0x21d8e0 add r1, pc, r1
 *   @0x21d8e4 str r0, [r9, #0x30]
 *   @0x21d8e8 ldr r3, [r5, r3]
 *   @0x21d8ec ldr r0, [r3]
 *   @0x21d8f0 ldr r3, [r0]
 *   @0x21d8f4 ldr r3, [r3, #0xc]
 *   @0x21d8f8 blx r3
 *   @0x21d8fc mov r0, r10
 *   @0x21d900 ldr r2, [sp, #0x81c]
 *   @0x21d904 ldr r3, [r6]
 *   @0x21d908 cmp r2, r3
 *   @0x21d90c bne 0x21d950 <_Z18Audio_CreateStreamPKc+0x274>
 *   @0x21d910 add sp, sp, #2080
 *   @0x21d914 add sp, sp, #4
 *   @0x21d918 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x21d91c ldr r3, [pc, #0x78]
 *   @0x21d920 mov r2, r4
 *   @0x21d924 ldr r1, [pc, #0x78]
 *   @0x21d928 ldr r3, [r5, r3]
 *   @0x21d92c add r1, pc, r1
 *   @0x21d930 ldr r0, [r3]
 *   @0x21d934 ldr r3, [r0]
 *   @0x21d938 ldr r3, [r3, #0xc]
 *   @0x21d93c blx r3
 *   @0x21d940 mvn r0, #0
 *   @0x21d944 b 0x21d900 <_Z18Audio_CreateStreamPKc+0x224>
 *   @0x21d948 ldr r3, [r8, #0x4]
 *   @0x21d94c b 0x21d828 <_Z18Audio_CreateStreamPKc+0x14c>
 *   @0x21d950 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x21d954 add r3, r3, #299008
 *   @0x21d958 add r10, r3, #992
 *   @0x21d95c mov r0, #96
 *   @0x21d960 bl 0x27c524 <_Znwj>
 *   @0x21d964 mov r9, r0
 *   @0x21d968 bl 0x218ea4 <_ZN12cAudio_SoundC2Ev>
 *   @0x21d96c ldr r3, [r8, #0x4]
 *   @0x21d970 cmp r9, #0
 *   @0x21d974 str r9, [r3, r4]
 *   @0x21d978 bne 0x21d8a4 <_Z18Audio_CreateStreamPKc+0x1c8>
 *   @0x21d97c b 0x21d76c <_Z18Audio_CreateStreamPKc+0x90>
 *   @0x21d980 movw r10, #0x93e0
 *   @0x21d984 movt r10, #0x4
 *   @0x21d988 b 0x21d95c <_Z18Audio_CreateStreamPKc+0x280>
 *   @0x21d98c andseq r4, sp, r12, asr r5
 *   @0x21d990 .word 0xffffbd00
 *   @0x21d994 .word 0xfffff788
 *   @0x21d998 andseq pc, r2, r4, ror r10
 *   @0x21d99c .word 0xffffbac4
 *   @0x21d9a0 andseq r6, r3, r12, lsl sp
 *   @0x21d9a4 andseq r6, r3, r0, lsr #25
 *
 * ══ §12/43 CSkeletonInstance::GetBoneState(char const*, int)  0xbfea8  size 712  178 条（0xbfea8..0xc0170）
 * @func 0xbfea8 0xc0170  size 712  178 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CDS_Map::Add(char const*, double, char const*)×15 / DS_AutoMutex::~DS_AutoMutex()×2 / spSkeleton_findBone / DS_AutoMutex::DS_AutoMutex() / spBone_getWorldRotationX / spBone_getWorldRotationY / spBone_getWorldScaleX / spBone_getWorldScaleY
 * 字段偏移 top8: 0x4×2 / 0x1c×1 / 0x254×1 / 0x2×1 / 0x238×1 / 0x218×1 / 0x1fc×1 / 0x1e0×1
 * VFP 指令 42 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbfea8 push {r4, r5, r6, r7, lr}
 *   @0xbfeac sub sp, sp, #20
 *   @0xbfeb0 ldr r0, [r0, #0x1c]
 *   @0xbfeb4 mov r4, r2
 *   @0xbfeb8 bl 0x28a0c8 <spSkeleton_findBone>
 *   @0xbfebc subs r5, r0, #0
 *   @0xbfec0 moveq r0, r5
 *   @0xbfec4 beq 0xc0114 <_ZN17CSkeletonInstance12GetBoneStateEPKci+0x26c>
 *   @0xbfec8 add r7, sp, #12
 *   @0xbfecc mov r0, r7
 *   @0xbfed0 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0xbfed4 ldr r3, [pc, #0x254]
 *   @0xbfed8 ldr r3, [pc, r3]
 *   @0xbfedc ldr r3, [r3, #0x4]
 *   @0xbfee0 ldr r4, [r3, r4, lsl #2]
 *   @0xbfee4 cmp r4, #0
 *   @0xbfee8 beq 0xc011c <_ZN17CSkeletonInstance12GetBoneStateEPKci+0x274>
 *   @0xbfeec vldr s15, [r5, #20]
 *   @0xbfef0 vcvt.f64.f32 d6, s15
 *   @0xbfef4 ldr r1, [pc, #0x238]
 *   @0xbfef8 mov r6, #0
 *   @0xbfefc mov r0, r4
 *   @0xbff00 str r6, [sp]
 *   @0xbff04 add r1, pc, r1
 *   @0xbff08 vmov r2, r3, d6
 *   @0xbff0c bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0xbff10 vldr s15, [r5, #24]
 *   @0xbff14 vcvt.f64.f32 d6, s15
 *   @0xbff18 ldr r1, [pc, #0x218]
 *   @0xbff1c mov r0, r4
 *   @0xbff20 str r6, [sp]
 *   @0xbff24 add r1, pc, r1
 *   @0xbff28 vmov r2, r3, d6
 *   @0xbff2c bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0xbff30 vldr s15, [r5, #28]
 *   @0xbff34 vcvt.f64.f32 d6, s15
 *   @0xbff38 ldr r1, [pc, #0x1fc]
 *   @0xbff3c mov r0, r4
 *   @0xbff40 str r6, [sp]
 *   @0xbff44 add r1, pc, r1
 *   @0xbff48 vmov r2, r3, d6
 *   @0xbff4c bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0xbff50 vldr s15, [r5, #32]
 *   @0xbff54 vcvt.f64.f32 d6, s15
 *   @0xbff58 ldr r1, [pc, #0x1e0]
 *   @0xbff5c mov r0, r4
 *   @0xbff60 str r6, [sp]
 *   @0xbff64 add r1, pc, r1
 *   @0xbff68 vmov r2, r3, d6
 *   @0xbff6c bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0xbff70 vldr s15, [r5, #36]
 *   @0xbff74 vcvt.f64.f32 d6, s15
 *   @0xbff78 ldr r1, [pc, #0x1c4]
 *   @0xbff7c mov r0, r4
 *   @0xbff80 str r6, [sp]
 *   @0xbff84 add r1, pc, r1
 *   @0xbff88 vmov r2, r3, d6
 *   @0xbff8c bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0xbff90 vldr s15, [r5, #60]
 *   @0xbff94 vcvt.f64.f32 d6, s15
 *   @0xbff98 ldr r1, [pc, #0x1a8]
 *   @0xbff9c mov r0, r4
 *   @0xbffa0 str r6, [sp]
 *   @0xbffa4 add r1, pc, r1
 *   @0xbffa8 vmov r2, r3, d6
 *   @0xbffac bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0xbffb0 vldr s15, [r5, #72]
 *   @0xbffb4 vcvt.f64.f32 d6, s15
 *   @0xbffb8 ldr r1, [pc, #0x18c]
 *   @0xbffbc mov r0, r4
 *   @0xbffc0 str r6, [sp]
 *   @0xbffc4 add r1, pc, r1
 *   @0xbffc8 vmov r2, r3, d6
 *   @0xbffcc bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0xbffd0 mov r0, r5
 *   @0xbffd4 bl 0x285410 <spBone_getWorldRotationX>
 *   @0xbffd8 ldr r1, [pc, #0x170]
 *   @0xbffdc str r6, [sp]
 *   @0xbffe0 add r1, pc, r1
 *   @0xbffe4 vmov s13, r0
 *   @0xbffe8 mov r0, r4
 *   @0xbffec vcvt.f64.f32 d7, s13
 *   @0xbfff0 vmov r2, r3, d7
 *   @0xbfff4 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0xbfff8 mov r0, r5
 *   @0xbfffc bl 0x28544c <spBone_getWorldRotationY>
 *   @0xc0000 ldr r1, [pc, #0x14c]
 *   @0xc0004 str r6, [sp]
 *   @0xc0008 add r1, pc, r1
 *   @0xc000c vmov s12, r0
 *   @0xc0010 mov r0, r4
 *   @0xc0014 vcvt.f64.f32 d7, s12
 *   @0xc0018 vmov r2, r3, d7
 *   @0xc001c bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0xc0020 mov r0, r5
 *   @0xc0024 bl 0x285488 <spBone_getWorldScaleX>
 *   @0xc0028 ldr r1, [pc, #0x128]
 *   @0xc002c str r6, [sp]
 *   @0xc0030 add r1, pc, r1
 *   @0xc0034 vmov s13, r0
 *   @0xc0038 mov r0, r4
 *   @0xc003c vcvt.f64.f32 d7, s13
 *   @0xc0040 vmov r2, r3, d7
 *   @0xc0044 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0xc0048 mov r0, r5
 *   @0xc004c bl 0x2854d8 <spBone_getWorldScaleY>
 *   @0xc0050 ldr r1, [pc, #0x104]
 *   @0xc0054 str r6, [sp]
 *   @0xc0058 add r1, pc, r1
 *   @0xc005c vmov s12, r0
 *   @0xc0060 mov r0, r4
 *   @0xc0064 vcvt.f64.f32 d7, s12
 *   @0xc0068 vmov r2, r3, d7
 *   @0xc006c bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0xc0070 vldr s15, [r5, #48]
 *   @0xc0074 vcvt.f64.f32 d6, s15
 *   @0xc0078 ldr r1, [pc, #0xe0]
 *   @0xc007c mov r0, r4
 *   @0xc0080 str r6, [sp]
 *   @0xc0084 add r1, pc, r1
 *   @0xc0088 vmov r2, r3, d6
 *   @0xc008c bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0xc0090 vldr s15, [r5, #76]
 *   @0xc0094 vcvt.f64.f32 d6, s15
 *   @0xc0098 ldr r1, [pc, #0xc4]
 *   @0xc009c mov r0, r4
 *   @0xc00a0 str r6, [sp]
 *   @0xc00a4 add r1, pc, r1
 *   @0xc00a8 vmov r2, r3, d6
 *   @0xc00ac bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0xc00b0 vldr s15, [r5, #80]
 *   @0xc00b4 vcvt.f64.f32 d6, s15
 *   @0xc00b8 ldr r1, [pc, #0xa8]
 *   @0xc00bc mov r0, r4
 *   @0xc00c0 str r6, [sp]
 *   @0xc00c4 add r1, pc, r1
 *   @0xc00c8 vmov r2, r3, d6
 *   @0xc00cc bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0xc00d0 ldr r3, [r5, #0x8]
 *   @0xc00d4 cmp r3, r6
 *   @0xc00d8 beq 0xc0108 <_ZN17CSkeletonInstance12GetBoneStateEPKci+0x260>
 *   @0xc00dc ldr r3, [r3]
 *   @0xc00e0 cmp r3, r6
 *   @0xc00e4 beq 0xc0108 <_ZN17CSkeletonInstance12GetBoneStateEPKci+0x260>
 *   @0xc00e8 ldr r12, [r3, #0x4]
 *   @0xc00ec mov r0, r4
 *   @0xc00f0 ldr r1, [pc, #0x74]
 *   @0xc00f4 mov r2, #0
 *   @0xc00f8 mov r3, #0
 *   @0xc00fc add r1, pc, r1
 *   @0xc0100 str r12, [sp]
 *   @0xc0104 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0xc0108 mov r0, r7
 *   @0xc010c bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xc0110 mov r0, #1
 *   @0xc0114 add sp, sp, #20
 *   @0xc0118 pop {r4, r5, r6, r7, pc}
 *   @0xc011c mov r0, r7
 *   @0xc0120 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xc0124 mov r0, r4
 *   @0xc0128 add sp, sp, #20
 *   @0xc012c pop {r4, r5, r6, r7, pc}
 *   @0xc0130 eorseq sp, r2, r4, ror #20
 *   @0xc0134 eoreq r0, r7, r0, ror r9
 *   @0xc0138 eoreq r0, r7, r4, asr r9
 *   @0xc013c eoreq r0, r7, r8, lsr r9
 *   @0xc0140 eoreq r0, r7, r0, lsr #18
 *   @0xc0144 eoreq r0, r7, r8, lsl #18
 *   @0xc0148 .word 0x002708f8
 *   @0xc014c eoreq r0, r7, r0, ror #17
 *   @0xc0150 eoreq r0, r7, r12, asr #17
 *   @0xc0154 .word 0x002708b0
 *   @0xc0158 mlaeq r7, r4, r8, r0
 *   @0xc015c eoreq r0, r7, r8, ror r8
 *   @0xc0160 eoreq r0, r7, r8, asr r8
 *   @0xc0164 eoreq r0, r7, r8, asr #16
 *   @0xc0168 eoreq r0, r7, r4, lsr r8
 *   @0xc016c mlaeq r7, r8, r7, r0
 *
 * ══ §13/43 F_TilemapSetAtPixel(RValue&, CInstance*, CInstance*, int, RValue*)  0x1bdff0  size 712  178 条（0x1bdff0..0x1be2b8）
 * @func 0x1bdff0 0x1be2b8  size 712  178 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Error_Show(char const*, bool)×3 / YYGetInt32(RValue const*, int)×2 / YYGetFloat(RValue const*, int)×2 / F_TilemapSetAtPixel(RValue&, CInstance*, CInstance*, int, RValue*)+0x44×2 / 0xb6910×2 / CLayerManager::GetTargetRoomObj() / CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / Background_Data(int)
 * 字段偏移 top8: 0xc×4 / 0x48×4 / 0x34×3 / 0x4×2 / 0x218×2 / 0x1c×2 / 0x28×2 / 0x2c×2
 * VFP 指令 42 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1bdff0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1bdff4 vpush {d8, d9}
 *   @0x1bdff8 cmp r3, #4
 *   @0x1bdffc ldr r6, [pc, #0x294]
 *   @0x1be000 mov r4, #0
 *   @0x1be004 sub sp, sp, #20
 *   @0x1be008 mov r3, #13
 *   @0x1be00c str r4, [r0]
 *   @0x1be010 mov r5, r0
 *   @0x1be014 str r3, [r0, #0xc]
 *   @0x1be018 add r6, pc, r6
 *   @0x1be01c str r4, [r0, #0x4]
 *   @0x1be020 beq 0x1be040 <_Z19F_TilemapSetAtPixelR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x1be024 ldr r0, [pc, #0x270]
 *   @0x1be028 mov r1, r4
 *   @0x1be02c add r0, pc, r0
 *   @0x1be030 bl 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1be034 add sp, sp, #20
 *   @0x1be038 vpop {d8, d9}
 *   @0x1be03c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1be040 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1be044 add r7, sp, #16
 *   @0x1be048 mov r1, r4
 *   @0x1be04c str r4, [r7, #-0x4]!
 *   @0x1be050 mov r8, r0
 *   @0x1be054 ldr r0, [sp, #0x48]
 *   @0x1be058 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1be05c mov r2, r7
 *   @0x1be060 mov r1, r0
 *   @0x1be064 mov r0, r8
 *   @0x1be068 bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1be06c subs r10, r0, #0
 *   @0x1be070 beq 0x1be080 <_Z19F_TilemapSetAtPixelR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x1be074 ldr r2, [r10]
 *   @0x1be078 cmp r2, #5
 *   @0x1be07c beq 0x1be0ac <_Z19F_TilemapSetAtPixelR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x1be080 ldr r1, [pc, #0x218]
 *   @0x1be084 ldr r3, [pc, #0x218]
 *   @0x1be088 add r1, pc, r1
 *   @0x1be08c ldr r3, [r6, r3]
 *   @0x1be090 ldr r0, [r3]
 *   @0x1be094 ldr r3, [r0]
 *   @0x1be098 ldr r3, [r3, #0xc]
 *   @0x1be09c blx r3
 *   @0x1be0a0 add sp, sp, #20
 *   @0x1be0a4 vpop {d8, d9}
 *   @0x1be0a8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1be0ac ldr r2, [sp, #0xc]
 *   @0x1be0b0 cmp r2, #0
 *   @0x1be0b4 beq 0x1be080 <_Z19F_TilemapSetAtPixelR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x1be0b8 ldr r1, [r10, #0x34]
 *   @0x1be0bc cmp r1, #0
 *   @0x1be0c0 beq 0x1be268 <_Z19F_TilemapSetAtPixelR6RValueP9CInstanceS2_iPS_+0x278>
 *   @0x1be0c4 ldr r0, [r10, #0x1c]
 *   @0x1be0c8 bl 0xc3794 <_Z15Background_Datai>
 *   @0x1be0cc subs r11, r0, #0
 *   @0x1be0d0 beq 0x1be254 <_Z19F_TilemapSetAtPixelR6RValueP9CInstanceS2_iPS_+0x264>
 *   @0x1be0d4 ldr lr, [pc, #0x1cc]
 *   @0x1be0d8 mov r1, #2
 *   @0x1be0dc ldr r2, [r10, #0x38]
 *   @0x1be0e0 vldr s16, [r10, #32]
 *   @0x1be0e4 ldr r12, [sp, #0xc]
 *   @0x1be0e8 vldr s15, [r12, #8]
 *   @0x1be0ec vldr s18, [r12, #12]
 *   @0x1be0f0 ldr r0, [sp, #0x48]
 *   @0x1be0f4 str r2, [sp]
 *   @0x1be0f8 vadd.f32 s16, s16, s15
 *   @0x1be0fc ldr r12, [r6, lr]
 *   @0x1be100 vldr s19, [r10, #36]
 *   @0x1be104 ldr r4, [r11, #0x1c]
 *   @0x1be108 ldr r8, [r11, #0x20]
 *   @0x1be10c ldr r12, [r12]
 *   @0x1be110 ldr r7, [r10, #0x28]
 *   @0x1be114 ldr r9, [r10, #0x2c]
 *   @0x1be118 str r12, [sp, #0x4]
 *   @0x1be11c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1be120 mov r1, #3
 *   @0x1be124 vmov s17, r0
 *   @0x1be128 ldr r0, [sp, #0x48]
 *   @0x1be12c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1be130 vsub.f32 s15, s17, s16
 *   @0x1be134 vcmpe.f32 s15, #0
 *   @0x1be138 vmrs APSR_nzcv, fpscr
 *   @0x1be13c vmov s13, r0
 *   @0x1be140 bmi 0x1be034 <_Z19F_TilemapSetAtPixelR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x1be144 mul r7, r7, r4
 *   @0x1be148 vmov s12, r7
 *   @0x1be14c vcvt.f32.s32 s14, s12
 *   @0x1be150 vcmpe.f32 s14, s15
 *   @0x1be154 vmrs APSR_nzcv, fpscr
 *   @0x1be158 bls 0x1be034 <_Z19F_TilemapSetAtPixelR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x1be15c vadd.f32 s18, s19, s18
 *   @0x1be160 vsub.f32 s18, s13, s18
 *   @0x1be164 vcmpe.f32 s18, #0
 *   @0x1be168 vmrs APSR_nzcv, fpscr
 *   @0x1be16c bmi 0x1be034 <_Z19F_TilemapSetAtPixelR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x1be170 mul r9, r9, r8
 *   @0x1be174 vmov s13, r9
 *   @0x1be178 vcvt.f32.s32 s14, s13
 *   @0x1be17c vcmpe.f32 s14, s18
 *   @0x1be180 vmrs APSR_nzcv, fpscr
 *   @0x1be184 bls 0x1be034 <_Z19F_TilemapSetAtPixelR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x1be188 vmov.f32 s16, #1.000000e+00
 *   @0x1be18c vmov s12, r4
 *   @0x1be190 vcvt.f32.s32 s14, s12
 *   @0x1be194 vdiv.f32 s14, s16, s14
 *   @0x1be198 vmul.f32 s14, s15, s14
 *   @0x1be19c vmov r0, s14
 *   @0x1be1a0 bl 0xb6910 <floorf@plt>
 *   @0x1be1a4 vmov s13, r8
 *   @0x1be1a8 vcvt.f32.s32 s15, s13
 *   @0x1be1ac vdiv.f32 s16, s16, s15
 *   @0x1be1b0 vmov s14, r0
 *   @0x1be1b4 vmul.f32 s16, s18, s16
 *   @0x1be1b8 vcvt.s32.f32 s14, s14
 *   @0x1be1bc vmov r0, s16
 *   @0x1be1c0 vmov r4, s14
 *   @0x1be1c4 bl 0xb6910 <floorf@plt>
 *   @0x1be1c8 ldr r1, [r10, #0x28]
 *   @0x1be1cc cmp r4, r1
 *   @0x1be1d0 lsrge r12, r1, #31
 *   @0x1be1d4 lsrlt r12, r4, #31
 *   @0x1be1d8 cmp r4, r1
 *   @0x1be1dc movge r4, r1
 *   @0x1be1e0 vmov s15, r0
 *   @0x1be1e4 cmp r12, #0
 *   @0x1be1e8 ldr r12, [r10, #0x2c]
 *   @0x1be1ec vcvt.s32.f32 s15, s15
 *   @0x1be1f0 movne r4, #0
 *   @0x1be1f4 vmov r0, s15
 *   @0x1be1f8 cmp r0, r12
 *   @0x1be1fc lsrge lr, r12, #31
 *   @0x1be200 lsrlt lr, r0, #31
 *   @0x1be204 cmp lr, #0
 *   @0x1be208 movne r7, #0
 *   @0x1be20c bne 0x1be21c <_Z19F_TilemapSetAtPixelR6RValueP9CInstanceS2_iPS_+0x22c>
 *   @0x1be210 cmp r0, r12
 *   @0x1be214 movge r0, r12
 *   @0x1be218 mul r7, r0, r1
 *   @0x1be21c mov r1, #1
 *   @0x1be220 ldr r0, [sp, #0x48]
 *   @0x1be224 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1be228 ldm sp, {r2, r3}
 *   @0x1be22c and r1, r2, r3
 *   @0x1be230 ldr r2, [r11, #0x34]
 *   @0x1be234 and r1, r1, r0
 *   @0x1be238 ubfx r1, r1, #0x0, #0x13
 *   @0x1be23c cmp r1, r2
 *   @0x1be240 blt 0x1be278 <_Z19F_TilemapSetAtPixelR6RValueP9CInstanceS2_iPS_+0x288>
 *   @0x1be244 ldr r1, [pc, #0x60]
 *   @0x1be248 ldr r3, [pc, #0x54]
 *   @0x1be24c add r1, pc, r1
 *   @0x1be250 b 0x1be08c <_Z19F_TilemapSetAtPixelR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x1be254 ldr r0, [pc, #0x54]
 *   @0x1be258 mov r1, r11
 *   @0x1be25c add r0, pc, r0
 *   @0x1be260 bl 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1be264 b 0x1be034 <_Z19F_TilemapSetAtPixelR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x1be268 ldr r0, [pc, #0x44]
 *   @0x1be26c add r0, pc, r0
 *   @0x1be270 bl 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1be274 b 0x1be034 <_Z19F_TilemapSetAtPixelR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x1be278 mov r2, #0
 *   @0x1be27c add r4, r4, r7
 *   @0x1be280 mov r1, r2
 *   @0x1be284 movt r2, #0x3ff0
 *   @0x1be288 stm r5, {r1, r2}
 *   @0x1be28c ldr r3, [r10, #0x34]
 *   @0x1be290 str r0, [r3, r4, lsl #2]
 *   @0x1be294 b 0x1be034 <_Z19F_TilemapSetAtPixelR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x1be298 eoreq r3, r3, r8, lsr r12
 *   @0x1be29c mulseq r9, r12, r8
 *   @0x1be2a0 andseq r0, r9, r8, ror #17
 *   @0x1be2a4 .word 0xffffbac4
 *   @0x1be2a8 .word 0xffffebc8
 *   @0x1be2ac andseq r0, r9, r0, ror #14
 *   @0x1be2b0 ldrsbeq r0, [r9], -r4
 *   @0x1be2b4 mulseq r9, r0, r6
 *
 * ══ §14/43 JS_String_prototype_search(RValue&, CInstance*, CInstance*, int, RValue*)  0x2560cc  size 712  178 条（0x2560cc..0x256394）
 * @func 0x2560cc 0x256394  size 712  178 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x2562b8→0x3eb70c, 0x2562d8→0x3eb70c, 0x2562e4→0x3eb70c, 0x2562f0→0x3eb70c, 0x2562fc→0x3eb70c, 0x25631c→0x3eb70c
 * 调用序列: JS_CheckObjectCoercible(RValue&) / F_JS_ToString(RValue&, RValue*) / JS_String_prototype_search(RValue&, CInstance*, CInstance*, int, RValue*)+0x25c / JS_RegExp(RValue&, CInstance*, CInstance*, int, RValue*) / 0xb6538 / JS_String_prototype_search(RValue&, CInstance*, CInstance*, int, RValue*)+0x1b4 / pcre_exec / JS_String_prototype_search(RValue&, CInstance*, CInstance*, int, RValue*)+0x1bc
 * 字段偏移 top8: 0xc×5 / 0x64×3 / 0x4×3 / 0x1c×3 / 0x20×3 / 0x40×2 / 0x54×2 / 0x14×2
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2560cc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2560d0 sub sp, sp, #212
 *   @0x2560d4 add r8, sp, #208
 *   @0x2560d8 mov r7, r0
 *   @0x2560dc mov r4, r1
 *   @0x2560e0 mov r10, r2
 *   @0x2560e4 str r1, [r8, #-0xa8]!
 *   @0x2560e8 mov r0, r8
 *   @0x2560ec mov r6, r3
 *   @0x2560f0 ldr r5, [sp, #0xf8]
 *   @0x2560f4 mov r3, #6
 *   @0x2560f8 str r3, [sp, #0x34]
 *   @0x2560fc bl 0x2423a4 <_Z23JS_CheckObjectCoercibleR6RValue>
 *   @0x256100 ldr r9, [pc, #0x264]
 *   @0x256104 add r9, pc, r9
 *   @0x256108 cmp r0, #1
 *   @0x25610c beq 0x256308 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x23c>
 *   @0x256110 mov r1, r8
 *   @0x256114 add r0, sp, #56
 *   @0x256118 mov r2, #0
 *   @0x25611c mov r3, #0
 *   @0x256120 mov r11, #0
 *   @0x256124 strd r2, r3, [sp, #56]
 *   @0x256128 str r11, [sp, #0x40]
 *   @0x25612c mvn r3, #-16777216
 *   @0x256130 str r3, [sp, #0x44]
 *   @0x256134 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x256138 cmp r0, #1
 *   @0x25613c beq 0x256308 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x23c>
 *   @0x256140 ldr r2, [sp, #0x38]
 *   @0x256144 cmp r6, r11
 *   @0x256148 mov r3, #5
 *   @0x25614c ldr r8, [r2]
 *   @0x256150 str r11, [sp, #0x48]
 *   @0x256154 str r11, [sp, #0x4c]
 *   @0x256158 str r11, [sp, #0x50]
 *   @0x25615c str r3, [sp, #0x54]
 *   @0x256160 ble 0x256328 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x25c>
 *   @0x256164 ldr r3, [r5, #0xc]
 *   @0x256168 bic r3, r3, #-16777216
 *   @0x25616c cmp r3, #6
 *   @0x256170 beq 0x256330 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x264>
 *   @0x256174 str r5, [sp]
 *   @0x256178 mov r1, r4
 *   @0x25617c mov r3, #1
 *   @0x256180 mov r2, r10
 *   @0x256184 add r0, sp, #88
 *   @0x256188 mvn r12, #-16777216
 *   @0x25618c mov r4, #0
 *   @0x256190 mov r5, #0
 *   @0x256194 mov r6, #0
 *   @0x256198 strd r4, r5, [sp, #88]
 *   @0x25619c str r6, [sp, #0x60]
 *   @0x2561a0 str r12, [sp, #0x64]
 *   @0x2561a4 bl 0x259ea8 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_>
 *   @0x2561a8 ldr r3, [sp, #0x64]
 *   @0x2561ac bic r3, r3, #-16777216
 *   @0x2561b0 cmp r3, #6
 *   @0x2561b4 beq 0x256364 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x298>
 *   @0x2561b8 cmp r6, #0
 *   @0x2561bc mov r2, #0
 *   @0x2561c0 mov r3, r2
 *   @0x2561c4 movt r2, #0xbff0
 *   @0x2561c8 str r3, [r7, #0xc]
 *   @0x2561cc str r2, [r7, #0x4]
 *   @0x2561d0 str r3, [r7]
 *   @0x2561d4 beq 0x256280 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x1b4>
 *   @0x2561d8 ldr r3, [pc, #0x190]
 *   @0x2561dc mov r0, r8
 *   @0x2561e0 ldr r10, [pc, #0x18c]
 *   @0x2561e4 mov r4, #0
 *   @0x2561e8 add r3, pc, r3
 *   @0x2561ec str r3, [sp, #0x14]
 *   @0x2561f0 bl 0xb6538 <strlen@plt>
 *   @0x2561f4 ldr r3, [pc, #0x17c]
 *   @0x2561f8 add r10, pc, r10
 *   @0x2561fc add r3, pc, r3
 *   @0x256200 str r3, [sp, #0x18]
 *   @0x256204 ldr r3, [pc, #0x170]
 *   @0x256208 add r3, pc, r3
 *   @0x25620c str r3, [sp, #0x1c]
 *   @0x256210 ldr r3, [pc, #0x168]
 *   @0x256214 add r3, pc, r3
 *   @0x256218 str r3, [sp, #0x20]
 *   @0x25621c ldr r3, [pc, #0x160]
 *   @0x256220 add r3, pc, r3
 *   @0x256224 str r3, [sp, #0x24]
 *   @0x256228 mov r5, r0
 *   @0x25622c cmp r5, r4
 *   @0x256230 mov r2, r8
 *   @0x256234 mov r3, r5
 *   @0x256238 mov r1, #0
 *   @0x25623c add r11, sp, #88
 *   @0x256240 mov r12, #30
 *   @0x256244 blt 0x256280 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x1b4>
 *   @0x256248 ldr lr, [r6, #0x20]
 *   @0x25624c ldr r0, [r6, #0x1c]
 *   @0x256250 str r1, [sp, #0x4]
 *   @0x256254 str r4, [sp]
 *   @0x256258 mov r1, lr
 *   @0x25625c str r11, [sp, #0x8]
 *   @0x256260 str r12, [sp, #0xc]
 *   @0x256264 bl 0x279390 <pcre_exec>
 *   @0x256268 cmp r0, #0
 *   @0x25626c blt 0x256288 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x1bc>
 *   @0x256270 vldr s15, [sp, #88]
 *   @0x256274 vcvt.f64.s32 d7, s15
 *   @0x256278 vmov r2, r3, d7
 *   @0x25627c stm r7, {r2, r3}
 *   @0x256280 add sp, sp, #212
 *   @0x256284 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x256288 add r0, r0, #6
 *   @0x25628c cmp r0, #5
 *   @0x256290 addls pc, pc, r0, lsl #2
 *   @0x256294 b 0x25631c <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x250>
 *   @0x256298 b 0x2562fc <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x230>
 *   @0x25629c b 0x2562f0 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x224>
 *   @0x2562a0 b 0x2562e4 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x218>
 *   @0x2562a4 b 0x2562d8 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x20c>
 *   @0x2562a8 b 0x2562b8 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x1ec>
 *   @0x2562ac b 0x2562b0 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x1e4>
 *   @0x2562b0 add r4, r4, #1
 *   @0x2562b4 b 0x25622c <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x2562b8 ldr r3, [pc, #0xc8]
 *   @0x2562bc ldr r1, [sp, #0x24]
 *   @0x2562c0 ldr r3, [r9, r3]
 *   @0x2562c4 ldr r0, [r3]
 *   @0x2562c8 ldr r3, [r0]
 *   @0x2562cc ldr r3, [r3, #0xc]
 *   @0x2562d0 blx r3
 *   @0x2562d4 b 0x25622c <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x2562d8 ldr r3, [pc, #0xa8]
 *   @0x2562dc ldr r1, [sp, #0x20]
 *   @0x2562e0 b 0x2562c0 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x1f4>
 *   @0x2562e4 ldr r3, [pc, #0x9c]
 *   @0x2562e8 ldr r1, [sp, #0x1c]
 *   @0x2562ec b 0x2562c0 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x1f4>
 *   @0x2562f0 ldr r3, [pc, #0x90]
 *   @0x2562f4 ldr r1, [sp, #0x18]
 *   @0x2562f8 b 0x2562c0 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x1f4>
 *   @0x2562fc ldr r3, [pc, #0x84]
 *   @0x256300 ldr r1, [sp, #0x14]
 *   @0x256304 b 0x2562c0 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x1f4>
 *   @0x256308 ldr r0, [pc, #0x7c]
 *   @0x25630c add r0, pc, r0
 *   @0x256310 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x256314 add sp, sp, #212
 *   @0x256318 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x25631c ldr r3, [pc, #0x64]
 *   @0x256320 mov r1, r10
 *   @0x256324 b 0x2562c0 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x1f4>
 *   @0x256328 add r5, sp, #72
 *   @0x25632c b 0x256174 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x256330 ldr r6, [r5]
 *   @0x256334 ldr r1, [pc, #0x54]
 *   @0x256338 ldr r0, [r6, #0x40]
 *   @0x25633c add r1, pc, r1
 *   @0x256340 bl 0xb6574 <strcmp@plt>
 *   @0x256344 cmp r0, #0
 *   @0x256348 bne 0x256174 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x25634c mov r3, #0
 *   @0x256350 str r0, [r7, #0xc]
 *   @0x256354 movt r3, #0xbff0
 *   @0x256358 str r0, [r7]
 *   @0x25635c str r3, [r7, #0x4]
 *   @0x256360 b 0x2561d8 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0x10c>
 *   @0x256364 ldr r6, [sp, #0x58]
 *   @0x256368 b 0x2561b8 <_Z26JS_String_prototype_searchR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x25636c andseq r11, r9, r12, asr #22
 *   @0x256370 andeq pc, pc, r4, lsr pc
 *   @0x256374 andseq r0, r0, r12, asr #15
 *   @0x256378 andeq pc, pc, r0, lsl #30
 *   @0x25637c .word 0x000ffed8
 *   @0x256380 strheq pc, [pc], -r0
 *   @0x256384 andeq pc, pc, r12, lsl #29
 *   @0x256388 .word 0xffffbac4
 *   @0x25638c andeq pc, pc, r12, lsr r12
 *   @0x256390 .word 0x000ff8f0
 *
 * ══ §15/43 SET_RValue_Array(RValue*, RValue*, int)  0xcfcb4  size 708  177 条（0xcfcb4..0xcff78）
 * @func 0xcfcb4 0xcff78  size 708  177 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::SetLength(void**, unsigned int, char const*, int)×2 / memLogPushContext(char const*) / 0xb664c / SET_RValue_Array(RValue*, RValue*, int)+0x178 / SET_RValue_Array(RValue*, RValue*, int)+0x1a0 / SET_RValue_Array(RValue*, RValue*, int)+0x108 / SET_RValue_Array(RValue*, RValue*, int)+0x1b0 / GetContextStackTop()
 * 字段偏移 top8: 0x4×10 / 0xc×5 / 0x10×4 / 0x8×4 / 0xb0×2 / 0x290×1 / 0x280×1 / 0x190×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcfcb4 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0xcfcb8 mov r4, r0
 *   @0xcfcbc ldr r0, [pc, #0x290]
 *   @0xcfcc0 sub sp, sp, #12
 *   @0xcfcc4 mov r5, r2
 *   @0xcfcc8 mov r6, r1
 *   @0xcfccc add r0, pc, r0
 *   @0xcfcd0 ldr r8, [pc, #0x280]
 *   @0xcfcd4 bl 0x27b948 <_Z17memLogPushContextPKc>
 *   @0xcfcd8 ldr r7, [r4]
 *   @0xcfcdc mov r1, r5
 *   @0xcfce0 mov r0, sp
 *   @0xcfce4 mov r2, #32000
 *   @0xcfce8 add r8, pc, r8
 *   @0xcfcec bl 0xb664c <ldiv@plt>
 *   @0xcfcf0 ldr r3, [r7, #0x10]
 *   @0xcfcf4 ldr r5, [sp]
 *   @0xcfcf8 ldr r4, [sp, #0x4]
 *   @0xcfcfc cmp r3, r5
 *   @0xcfd00 ble 0xcfe2c <_Z16SET_RValue_ArrayP6RValueS0_i+0x178>
 *   @0xcfd04 cmp r5, #0
 *   @0xcfd08 blt 0xcfe54 <_Z16SET_RValue_ArrayP6RValueS0_i+0x1a0>
 *   @0xcfd0c ldr r3, [r7, #0x4]
 *   @0xcfd10 cmp r4, #0
 *   @0xcfd14 add r9, r3, r5, lsl #3
 *   @0xcfd18 blt 0xcfdbc <_Z16SET_RValue_ArrayP6RValueS0_i+0x108>
 *   @0xcfd1c ldr r3, [r9]
 *   @0xcfd20 cmp r3, r4
 *   @0xcfd24 ble 0xcfe64 <_Z16SET_RValue_ArrayP6RValueS0_i+0x1b0>
 *   @0xcfd28 ldr r7, [r9, #0x4]
 *   @0xcfd2c add r5, r7, r4, lsl #4
 *   @0xcfd30 ldr r3, [r5, #0xc]
 *   @0xcfd34 sub r3, r3, #1
 *   @0xcfd38 bic r3, r3, #-16777216
 *   @0xcfd3c bic r3, r3, #3
 *   @0xcfd40 cmp r3, #0
 *   @0xcfd44 beq 0xcff48 <_Z16SET_RValue_ArrayP6RValueS0_i+0x294>
 *   @0xcfd48 mov r3, #5
 *   @0xcfd4c str r3, [r5, #0xc]
 *   @0xcfd50 ldr r1, [r6, #0xc]
 *   @0xcfd54 mov r3, #0
 *   @0xcfd58 str r3, [r5, #0x8]
 *   @0xcfd5c str r3, [r7, r4, lsl #4]
 *   @0xcfd60 ldr r2, [r6, #0x8]
 *   @0xcfd64 str r1, [r5, #0xc]
 *   @0xcfd68 ldr r3, [r6, #0xc]
 *   @0xcfd6c str r2, [r5, #0x8]
 *   @0xcfd70 bic r3, r3, #-16777216
 *   @0xcfd74 cmp r3, #14
 *   @0xcfd78 addls pc, pc, r3, lsl #2
 *   @0xcfd7c b 0xcfe0c <_Z16SET_RValue_ArrayP6RValueS0_i+0x158>
 *   @0xcfd80 b 0xcfe88 <_Z16SET_RValue_ArrayP6RValueS0_i+0x1d4>
 *   @0xcfd84 b 0xcff04 <_Z16SET_RValue_ArrayP6RValueS0_i+0x250>
 *   @0xcfd88 b 0xcff1c <_Z16SET_RValue_ArrayP6RValueS0_i+0x268>
 *   @0xcfd8c b 0xcfe18 <_Z16SET_RValue_ArrayP6RValueS0_i+0x164>
 *   @0xcfd90 b 0xcfe0c <_Z16SET_RValue_ArrayP6RValueS0_i+0x158>
 *   @0xcfd94 b 0xcfe0c <_Z16SET_RValue_ArrayP6RValueS0_i+0x158>
 *   @0xcfd98 b 0xcfee0 <_Z16SET_RValue_ArrayP6RValueS0_i+0x22c>
 *   @0xcfd9c b 0xcfe18 <_Z16SET_RValue_ArrayP6RValueS0_i+0x164>
 *   @0xcfda0 b 0xcfe0c <_Z16SET_RValue_ArrayP6RValueS0_i+0x158>
 *   @0xcfda4 b 0xcfe0c <_Z16SET_RValue_ArrayP6RValueS0_i+0x158>
 *   @0xcfda8 b 0xcfe88 <_Z16SET_RValue_ArrayP6RValueS0_i+0x1d4>
 *   @0xcfdac b 0xcfe0c <_Z16SET_RValue_ArrayP6RValueS0_i+0x158>
 *   @0xcfdb0 b 0xcfe0c <_Z16SET_RValue_ArrayP6RValueS0_i+0x158>
 *   @0xcfdb4 b 0xcfe88 <_Z16SET_RValue_ArrayP6RValueS0_i+0x1d4>
 *   @0xcfdb8 b 0xcfe18 <_Z16SET_RValue_ArrayP6RValueS0_i+0x164>
 *   @0xcfdbc cmp r9, #0
 *   @0xcfdc0 bne 0xcfea0 <_Z16SET_RValue_ArrayP6RValueS0_i+0x1ec>
 *   @0xcfdc4 ldr r3, [pc, #0x190]
 *   @0xcfdc8 mov r9, #1
 *   @0xcfdcc ldr r12, [pc, #0x18c]
 *   @0xcfdd0 mvn r2, #0
 *   @0xcfdd4 ldr r0, [pc, #0x188]
 *   @0xcfdd8 ldr r6, [r8, r3]
 *   @0xcfddc ldr r3, [pc, #0x184]
 *   @0xcfde0 ldr r1, [r7, #0x10]
 *   @0xcfde4 strb r9, [r6]
 *   @0xcfde8 ldr r12, [r8, r12]
 *   @0xcfdec str r5, [r12]
 *   @0xcfdf0 ldr r0, [r8, r0]
 *   @0xcfdf4 str r4, [r0]
 *   @0xcfdf8 ldr r3, [r8, r3]
 *   @0xcfdfc str r1, [r3]
 *   @0xcfe00 ldr r3, [pc, #0x164]
 *   @0xcfe04 ldr r3, [r8, r3]
 *   @0xcfe08 str r2, [r3]
 *   @0xcfe0c add sp, sp, #12
 *   @0xcfe10 pop {r4, r5, r6, r7, r8, r9, lr}
 *   @0xcfe14 b 0x27b94c <_Z16memLogPopContextv>
 *   @0xcfe18 ldr r3, [r6]
 *   @0xcfe1c str r3, [r7, r4, lsl #4]
 *   @0xcfe20 add sp, sp, #12
 *   @0xcfe24 pop {r4, r5, r6, r7, r8, r9, lr}
 *   @0xcfe28 b 0x27b94c <_Z16memLogPopContextv>
 *   @0xcfe2c add r1, r5, #1
 *   @0xcfe30 ldr r2, [pc, #0x138]
 *   @0xcfe34 str r1, [r7, #0x10]
 *   @0xcfe38 add r0, r7, #4
 *   @0xcfe3c mov r3, #744
 *   @0xcfe40 lsl r1, r1, #3
 *   @0xcfe44 add r2, pc, r2
 *   @0xcfe48 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xcfe4c cmp r5, #0
 *   @0xcfe50 bge 0xcfd0c <_Z16SET_RValue_ArrayP6RValueS0_i+0x58>
 *   @0xcfe54 cmp r4, #0
 *   @0xcfe58 movge r9, #0
 *   @0xcfe5c bge 0xcfd1c <_Z16SET_RValue_ArrayP6RValueS0_i+0x68>
 *   @0xcfe60 b 0xcfdc4 <_Z16SET_RValue_ArrayP6RValueS0_i+0x110>
 *   @0xcfe64 add r1, r4, #1
 *   @0xcfe68 ldr r2, [pc, #0x104]
 *   @0xcfe6c mov r0, r9
 *   @0xcfe70 movw r3, #0x2f5
 *   @0xcfe74 str r1, [r0], #4
 *   @0xcfe78 add r2, pc, r2
 *   @0xcfe7c lsl r1, r1, #4
 *   @0xcfe80 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xcfe84 b 0xcfd28 <_Z16SET_RValue_ArrayP6RValueS0_i+0x74>
 *   @0xcfe88 ldm r6, {r2, r3}
 *   @0xcfe8c str r2, [r7, r4, lsl #4]
 *   @0xcfe90 str r3, [r5, #0x4]
 *   @0xcfe94 add sp, sp, #12
 *   @0xcfe98 pop {r4, r5, r6, r7, r8, r9, lr}
 *   @0xcfe9c b 0x27b94c <_Z16memLogPopContextv>
 *   @0xcfea0 ldr r1, [pc, #0xb4]
 *   @0xcfea4 mov r9, #1
 *   @0xcfea8 ldr r2, [pc, #0xb0]
 *   @0xcfeac ldr r12, [pc, #0xb0]
 *   @0xcfeb0 ldr r6, [r8, r1]
 *   @0xcfeb4 ldr r0, [pc, #0xac]
 *   @0xcfeb8 ldr r1, [r7, #0x10]
 *   @0xcfebc strb r9, [r6]
 *   @0xcfec0 ldr r6, [r8, r2]
 *   @0xcfec4 ldr r2, [r3, r5, lsl #3]
 *   @0xcfec8 str r5, [r6]
 *   @0xcfecc ldr r3, [r8, r12]
 *   @0xcfed0 str r4, [r3]
 *   @0xcfed4 ldr r3, [r8, r0]
 *   @0xcfed8 str r1, [r3]
 *   @0xcfedc b 0xcfe00 <_Z16SET_RValue_ArrayP6RValueS0_i+0x14c>
 *   @0xcfee0 ldr r3, [r6]
 *   @0xcfee4 str r3, [r7, r4, lsl #4]
 *   @0xcfee8 ldr r3, [r6]
 *   @0xcfeec cmp r3, #0
 *   @0xcfef0 beq 0xcfe0c <_Z16SET_RValue_ArrayP6RValueS0_i+0x158>
 *   @0xcfef4 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0xcfef8 ldr r1, [r6]
 *   @0xcfefc bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0xcff00 b 0xcfe0c <_Z16SET_RValue_ArrayP6RValueS0_i+0x158>
 *   @0xcff04 ldr r3, [r6]
 *   @0xcff08 cmp r3, #0
 *   @0xcff0c ldrne r2, [r3, #0x4]
 *   @0xcff10 addne r2, r2, #1
 *   @0xcff14 strne r2, [r3, #0x4]
 *   @0xcff18 b 0xcfe1c <_Z16SET_RValue_ArrayP6RValueS0_i+0x168>
 *   @0xcff1c ldr r3, [r6]
 *   @0xcff20 cmp r3, #0
 *   @0xcff24 str r3, [r7, r4, lsl #4]
 *   @0xcff28 beq 0xcfe0c <_Z16SET_RValue_ArrayP6RValueS0_i+0x158>
 *   @0xcff2c ldr r1, [r3, #0x8]
 *   @0xcff30 ldr r2, [r3]
 *   @0xcff34 cmp r1, #0
 *   @0xcff38 streq r5, [r3, #0x8]
 *   @0xcff3c add r2, r2, #1
 *   @0xcff40 str r2, [r3]
 *   @0xcff44 b 0xcfe0c <_Z16SET_RValue_ArrayP6RValueS0_i+0x158>
 *   @0xcff48 mov r0, r5
 *   @0xcff4c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xcff50 b 0xcfd48 <_Z16SET_RValue_ArrayP6RValueS0_i+0x94>
 *   @0xcff54 eoreq r2, r6, r0, lsl r8
 *   @0xcff58 eorseq r1, r2, r8, ror #30
 *   @0xcff5c .word 0xffffbf24
 *   @0xcff60 .word 0xffffbf28
 *   @0xcff64 .word 0xffffbf2c
 *   @0xcff68 .word 0xffffbf30
 *   @0xcff6c .word 0xffffbf34
 *   @0xcff70 .word 0x002623b8
 *   @0xcff74 eoreq r2, r6, r4, lsl #7
 *
 * ══ §16/43 Eff_Effect10(int, float, float, int, unsigned int)  0x1a1ed0  size 708  177 条（0x1a1ed0..0x1a2194）
 * @func 0x1a1ed0 0x1a2194  size 708  177 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: fYYRandom(double)×6 / ParticleSystem_Particles_Create_Color(int, float, float, int, unsigned int, int)×3 / 0xb66e8×2 / Speed_Factor() / ParticleType_Shape(int, int) / ParticleType_Size(int, float, float, float, float) / ParticleType_Orientation(int, float, float, float, float, bool) / ParticleType_Speed(int, float, float, float, float)
 * 字段偏移 top8: 0x48×1 / 0x294×1 / 0x284×1 / 0x4×1
 * VFP 指令 60 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a1ed0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1a1ed4 vpush {d8, d9, d10}
 *   @0x1a1ed8 sub sp, sp, #12
 *   @0x1a1edc vldr s17, [pc, #676]
 *   @0x1a1ee0 mov r10, r3
 *   @0x1a1ee4 mov r7, r0
 *   @0x1a1ee8 ldr r8, [sp, #0x48]
 *   @0x1a1eec bl 0x19ff6c <_Z12Speed_Factorv>
 *   @0x1a1ef0 ldr r4, [pc, #0x294]
 *   @0x1a1ef4 mov r5, #0
 *   @0x1a1ef8 mov r1, #3
 *   @0x1a1efc mov r9, #1
 *   @0x1a1f00 ldr r4, [pc, r4]
 *   @0x1a1f04 ldr r6, [pc, #0x284]
 *   @0x1a1f08 vmov.f64 d9, #3.000000e+01
 *   @0x1a1f0c vmov s16, r0
 *   @0x1a1f10 ldr r0, [r4]
 *   @0x1a1f14 bl 0x1a31a4 <_Z18ParticleType_Shapeii>
 *   @0x1a1f18 ldr r0, [r4]
 *   @0x1a1f1c vmov r1, s17
 *   @0x1a1f20 mov r3, r5
 *   @0x1a1f24 str r5, [sp]
 *   @0x1a1f28 movw r2, #0x999a
 *   @0x1a1f2c movt r2, #0x3e99
 *   @0x1a1f30 bl 0x1a322c <_Z17ParticleType_Sizeiffff>
 *   @0x1a1f34 ldr r0, [r4]
 *   @0x1a1f38 mov r1, r5
 *   @0x1a1f3c mov r2, r5
 *   @0x1a1f40 mov r3, r5
 *   @0x1a1f44 str r5, [sp]
 *   @0x1a1f48 str r9, [sp, #0x4]
 *   @0x1a1f4c bl 0x1a3400 <_Z24ParticleType_Orientationiffffb>
 *   @0x1a1f50 vmov.f32 s15, #7.000000e+00
 *   @0x1a1f54 ldr r0, [r4]
 *   @0x1a1f58 mov r3, r5
 *   @0x1a1f5c str r5, [sp]
 *   @0x1a1f60 vmul.f32 s15, s16, s15
 *   @0x1a1f64 vmov r1, s15
 *   @0x1a1f68 vmov r2, s15
 *   @0x1a1f6c bl 0x1a3368 <_Z18ParticleType_Speediffff>
 *   @0x1a1f70 mov r1, #0
 *   @0x1a1f74 movt r1, #0x4382
 *   @0x1a1f78 mov r3, r5
 *   @0x1a1f7c ldr r0, [r4]
 *   @0x1a1f80 mov r2, r1
 *   @0x1a1f84 str r5, [sp]
 *   @0x1a1f88 bl 0x1a33b4 <_Z22ParticleType_Directioniffff>
 *   @0x1a1f8c ldr r0, [r4]
 *   @0x1a1f90 movw r1, #0xcccd
 *   @0x1a1f94 movt r1, #0x3ecc
 *   @0x1a1f98 bl 0x1a3668 <_Z19ParticleType_Alpha1if>
 *   @0x1a1f9c ldr r6, [pc, r6]
 *   @0x1a1fa0 ldr r11, [r4]
 *   @0x1a1fa4 ldr r3, [r6]
 *   @0x1a1fa8 vldr s15, [r3, #20]
 *   @0x1a1fac vcvt.f32.s32 s15, s15
 *   @0x1a1fb0 vmul.f32 s15, s15, s17
 *   @0x1a1fb4 vdiv.f32 s15, s15, s16
 *   @0x1a1fb8 vcvt.f64.f32 d5, s15
 *   @0x1a1fbc vmov r0, r1, d5
 *   @0x1a1fc0 bl 0xb66e8 <lrint@plt>
 *   @0x1a1fc4 ldr r3, [r6]
 *   @0x1a1fc8 vldr s15, [r3, #20]
 *   @0x1a1fcc vcvt.f32.s32 s15, s15
 *   @0x1a1fd0 vmul.f32 s17, s15, s17
 *   @0x1a1fd4 vdiv.f32 s16, s17, s16
 *   @0x1a1fd8 mov r5, r0
 *   @0x1a1fdc vcvt.f64.f32 d6, s16
 *   @0x1a1fe0 vmov r0, r1, d6
 *   @0x1a1fe4 bl 0xb66e8 <lrint@plt>
 *   @0x1a1fe8 mov r1, r5
 *   @0x1a1fec mov r2, r0
 *   @0x1a1ff0 mov r0, r11
 *   @0x1a1ff4 bl 0x1a32b4 <_Z17ParticleType_Lifeiii>
 *   @0x1a1ff8 cmp r10, #0
 *   @0x1a1ffc bne 0x1a207c <_Z12Eff_Effect10iffij+0x1ac>
 *   @0x1a2000 mov r5, #2
 *   @0x1a2004 vldr d8, [pc, #372]
 *   @0x1a2008 mov r0, #0
 *   @0x1a200c mov r1, #0
 *   @0x1a2010 movt r1, #0x3ff0
 *   @0x1a2014 bl 0xc4598 <_Z9fYYRandomd>
 *   @0x1a2018 ldr r3, [r6]
 *   @0x1a201c vldr s14, [r3, #16]
 *   @0x1a2020 vcvt.f64.s32 d7, s14
 *   @0x1a2024 vmov d5, r0, r1
 *   @0x1a2028 mov r0, #0
 *   @0x1a202c mov r1, #0
 *   @0x1a2030 movt r1, #0x4034
 *   @0x1a2034 vmul.f64 d6, d5, d8
 *   @0x1a2038 vmul.f64 d7, d6, d7
 *   @0x1a203c vcvt.f32.f64 s20, d7
 *   @0x1a2040 bl 0xc4598 <_Z9fYYRandomd>
 *   @0x1a2044 ldr r3, [r4]
 *   @0x1a2048 stm sp, {r8, r9}
 *   @0x1a204c vmov d6, r0, r1
 *   @0x1a2050 mov r0, r7
 *   @0x1a2054 vsub.f64 d7, d6, d9
 *   @0x1a2058 vmov r1, s20
 *   @0x1a205c vcvt.f32.f64 s13, d7
 *   @0x1a2060 vmov r2, s13
 *   @0x1a2064 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji>
 *   @0x1a2068 subs r5, r5, #1
 *   @0x1a206c bne 0x1a2008 <_Z12Eff_Effect10iffij+0x138>
 *   @0x1a2070 add sp, sp, #12
 *   @0x1a2074 vpop {d8, d9, d10}
 *   @0x1a2078 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1a207c cmp r10, #2
 *   @0x1a2080 beq 0x1a2100 <_Z12Eff_Effect10iffij+0x230>
 *   @0x1a2084 mov r5, #5
 *   @0x1a2088 vldr d8, [pc, #240]
 *   @0x1a208c mov r0, #0
 *   @0x1a2090 mov r1, #0
 *   @0x1a2094 movt r1, #0x3ff0
 *   @0x1a2098 bl 0xc4598 <_Z9fYYRandomd>
 *   @0x1a209c ldr r3, [r6]
 *   @0x1a20a0 vldr s14, [r3, #16]
 *   @0x1a20a4 vcvt.f64.s32 d7, s14
 *   @0x1a20a8 vmov d5, r0, r1
 *   @0x1a20ac mov r0, #0
 *   @0x1a20b0 mov r1, #0
 *   @0x1a20b4 movt r1, #0x4034
 *   @0x1a20b8 vmul.f64 d6, d5, d8
 *   @0x1a20bc vmul.f64 d7, d6, d7
 *   @0x1a20c0 vcvt.f32.f64 s20, d7
 *   @0x1a20c4 bl 0xc4598 <_Z9fYYRandomd>
 *   @0x1a20c8 ldr r3, [r4]
 *   @0x1a20cc stm sp, {r8, r9}
 *   @0x1a20d0 vmov d6, r0, r1
 *   @0x1a20d4 mov r0, r7
 *   @0x1a20d8 vsub.f64 d7, d6, d9
 *   @0x1a20dc vmov r1, s20
 *   @0x1a20e0 vcvt.f32.f64 s13, d7
 *   @0x1a20e4 vmov r2, s13
 *   @0x1a20e8 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji>
 *   @0x1a20ec subs r5, r5, #1
 *   @0x1a20f0 bne 0x1a208c <_Z12Eff_Effect10iffij+0x1bc>
 *   @0x1a20f4 add sp, sp, #12
 *   @0x1a20f8 vpop {d8, d9, d10}
 *   @0x1a20fc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1a2100 mov r5, #9
 *   @0x1a2104 vldr d8, [pc, #116]
 *   @0x1a2108 mov r0, #0
 *   @0x1a210c mov r1, #0
 *   @0x1a2110 movt r1, #0x3ff0
 *   @0x1a2114 bl 0xc4598 <_Z9fYYRandomd>
 *   @0x1a2118 ldr r3, [r6]
 *   @0x1a211c vldr s14, [r3, #16]
 *   @0x1a2120 vcvt.f64.s32 d7, s14
 *   @0x1a2124 vmov d5, r0, r1
 *   @0x1a2128 mov r0, #0
 *   @0x1a212c mov r1, #0
 *   @0x1a2130 movt r1, #0x4034
 *   @0x1a2134 vmul.f64 d6, d5, d8
 *   @0x1a2138 vmul.f64 d7, d6, d7
 *   @0x1a213c vcvt.f32.f64 s20, d7
 *   @0x1a2140 bl 0xc4598 <_Z9fYYRandomd>
 *   @0x1a2144 ldr r3, [r4]
 *   @0x1a2148 stm sp, {r8, r9}
 *   @0x1a214c vmov d6, r0, r1
 *   @0x1a2150 mov r0, r7
 *   @0x1a2154 vsub.f64 d7, d6, d9
 *   @0x1a2158 vmov r1, s20
 *   @0x1a215c vcvt.f32.f64 s13, d7
 *   @0x1a2160 vmov r2, s13
 *   @0x1a2164 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji>
 *   @0x1a2168 subs r5, r5, #1
 *   @0x1a216c bne 0x1a2108 <_Z12Eff_Effect10iffij+0x238>
 *   @0x1a2170 add sp, sp, #12
 *   @0x1a2174 vpop {d8, d9, d10}
 *   @0x1a2178 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1a217c nop
 *   @0x1a2180 andmi r0, r0, r0
 *   @0x1a2184 svclo #0xf33333
 *   @0x1a2188 cdplo p12, #0x4, c12, c12, c13, #0x6
 *   @0x1a218c mlaeq r4, r8, r8, lr
 *   @0x1a2190 eoreq r11, r4, r12, lsl #19
 *
 * ══ §17/43 png_do_gamma  0x2aa0d6  size 706  177 条（0x2aa0d6..0x2aa398）
 * @func 0x2aa0d6 0x2aa398  size 706  177 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2World::SolveTOI(b2TimeStep const&)+0xb8a
 * 字段偏移 top8: 0x-2×6 / 0x-1×4 / 0x18×4 / 0x-3×3 / 0x-4×3 / 0x9×2 / 0x1×2 / 0x16×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2aa0d6 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2aa0da ldrb r6, [r0, #0x9]
 *   @0x2aa0de cmp r6, #0x8
 *   @0x2aa0e2 bhi 0x2aa0ea <png_do_gamma+0x14>
 *   @0x2aa0e6 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2aa0ea cmp r6, #0x10
 *   @0x2aa0ee blhs 0x2ca63e <_ZN7b2World8SolveTOIERK10b2TimeStep+0xb8a>
 *   @0x2aa0f2 beq.w 0x2aa394 <png_do_gamma+0x2be>
 *   @0x2aa0f6 ldrb r7, [r0, #0x8]
 *   @0x2aa0fa bhi.w 0x2aa394 <png_do_gamma+0x2be>
 *   @0x2aa0fe tbh [pc, r7, lsl #1]
 *   @0x2aa102 lsls r2, r0, #0x3
 *   @0x2aa106 movs r7, r0
 *   @0x2aa10a lsls r2, r3, #0x2
 *   @0x2aa10e lsls r1, r2, #0x1
 *   @0x2aa112 beq 0x2aa118 <png_do_gamma+0x42>
 *   @0x2aa116 b 0x2aa146 <png_do_gamma+0x70>
 *   @0x2aa11a mla r4, r3, r4, r1
 *   @0x2aa11e cmp r1, r4
 *   @0x2aa122 ldrb r3, [r1]
 *   @0x2aa126 ldrb r3, [r2, r3]
 *   @0x2aa12a .word 0xf8113c03
 *   @0x2aa12e ldclpl p12, c3, [r3], {2}
 *   @0x2aa132 strb r3, [r1, #-2]
 *   @0x2aa136 ldrb r3, [r1, #-1]
 *   @0x2aa13a ldrb r3, [r2, r3]
 *   @0x2aa13e strb r3, [sp, r1, lsl #24]!
 *   @0x2aa142 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2aa146 cmp r2, r4
 *   @0x2aa14a ldrb r0, [r1, #0x1]
 *   @0x2aa14e ldrb r6, [r1]
 *   @0x2aa152 asrs r0, r5
 *   @0x2aa156 rfeda r0!
 *   @0x2aa15a .word 0xf8010016
 *   @0x2aa15e beq 0x42d17a <g_RomDisk+0x3595a>
 *   @0x2aa162 ldrb r0, [r1, #-3]
 *   @0x2aa166 strb r6, [r1, #-6]
 *   @0x2aa16a ldrb r6, [r1, #-4]
 *   @0x2aa16e asrs r0, r5
 *   @0x2aa172 rfeda r0!
 *   @0x2aa176 .word 0xf8010016
 *   @0x2aa17a beq 0x42d18e <g_RomDisk+0x3596e>
 *   @0x2aa17e ldrb r0, [r1, #-1]
 *   @0x2aa182 strb r6, [r1, #-4]
 *   @0x2aa186 ldrb r6, [r1, #-2]
 *   @0x2aa18a asrs r0, r5
 *   @0x2aa18e rfeda r0!
 *   @0x2aa192 beq 0x42a1f2 <g_RomDisk+0x329d2>
 *   @0x2aa196 strb r0, [r1, #-1]
 *   @0x2aa19a strb r6, [r1, #-2]
 *   @0x2aa19e b 0x2aa146 <png_do_gamma+0x70>
 *   @0x2aa1a2 mcrhs p15, #0x0, r8, c8, c0, #0x7
 *   @0x2aa1a6 beq 0x2aa1ac <png_do_gamma+0xd6>
 *   @0x2aa1aa b 0x2aa1d8 <png_do_gamma+0x102>
 *   @0x2aa1ae cmp r3, r4
 *   @0x2aa1b2 ldrb r0, [r1]
 *   @0x2aa1b6 adds r1, #0x4
 *   @0x2aa1ba strb r0, [r1, #-4]
 *   @0x2aa1be ldrb r0, [r1, #-3]
 *   @0x2aa1c2 ldrb r0, [r2, r0]
 *   @0x2aa1c6 .word 0xf8110c03
 *   @0x2aa1ca .word 0x5c100c02
 *   @0x2aa1ce strb r0, [r1, #-2]
 *   @0x2aa1d2 b 0x2aa1ae <png_do_gamma+0xd8>
 *   @0x2aa1d6 adcmi r8, r2, #240, #30
 *   @0x2aa1da beq 0x2aa232 <png_do_gamma+0x15c>
 *   @0x2aa1de adds r2, #0x1
 *   @0x2aa1e2 adds r1, #0x8
 *   @0x2aa1e6 ldr.w r0, [r3, r0, lsl #2]
 *   @0x2aa1ea ldrh.w r0, [r0, r6, lsl #1]
 *   @0x2aa1ee strb r0, [r1, #-7]
 *   @0x2aa1f2 lsrs r6, r0, #0x8
 *   @0x2aa1f6 .word 0xf8010c05
 *   @0x2aa1fa .word 0xf8116c08
 *   @0x2aa1fe .word 0x41286c06
 *   @0x2aa202 ldr.w r0, [r3, r0, lsl #2]
 *   @0x2aa206 ldrh.w r0, [r0, r6, lsl #1]
 *   @0x2aa20a strb r0, [r1, #-5]
 *   @0x2aa20e lsrs r6, r0, #0x8
 *   @0x2aa212 .word 0xf8010c03
 *   @0x2aa216 .word 0xf8116c06
 *   @0x2aa21a .word 0x41286c04
 *   @0x2aa21e ldr.w r0, [r3, r0, lsl #2]
 *   @0x2aa222 ldrh.w r0, [r0, r6, lsl #1]
 *   @0x2aa226 lsrs r6, r0, #0x8
 *   @0x2aa22a .word 0xf8010c03
 *   @0x2aa22e ldrb r6, [r2, r4, lsl #24]
 *   @0x2aa232 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2aa236 cmp r6, #0x8
 *   @0x2aa23a movs r2, #0x0
 *   @0x2aa23e movs r3, #0x0
 *   @0x2aa242 add.w r1, r1, #0x2
 *   @0x2aa246 beq 0x2aa256 <png_do_gamma+0x180>
 *   @0x2aa24a movwlo r0, #0x1c02
 *   @0x2aa24e ldrb r0, [r2, r0]
 *   @0x2aa252 ldrb r0, [r4, r2, lsl #24]!
 *   @0x2aa256 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2aa25a cmp r2, r4
 *   @0x2aa25e andle r0, pc, r4, lsl #2
 *   @0x2aa262 ldrb r0, [r1, #-3]
 *   @0x2aa266 adds r2, #0x1
 *   @0x2aa26a .word 0x41286c04
 *   @0x2aa26e ldr.w r0, [r3, r0, lsl #2]
 *   @0x2aa272 ldrh.w r0, [r0, r6, lsl #1]
 *   @0x2aa276 lsrs r6, r0, #0x8
 *   @0x2aa27a .word 0xf8010c03
 *   @0x2aa27e strb r6, [r11, r4, lsl #24]!
 *   @0x2aa282 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2aa286 cmp r6, #0x2
 *   @0x2aa28a ldrb r0, [r0, #0x9]
 *   @0x2aa28e bne 0x2aa34e <png_do_gamma+0x278>
 *   @0x2aa292 b 0x2aa320 <png_do_gamma+0x24a>
 *   @0x2aa296 mov.w r9, #0x0
 *   @0x2aa29a cmp r9, r4
 *   @0x2aa29e ldrb.w r8, [r10]
 *   @0x2aa2a2 add.w r9, r9, #0x4
 *   @0x2aa2a6 and r12, r8, #0xc0
 *   @0x2aa2aa and r7, r8, #0x30
 *   @0x2aa2ae and r6, r8, #0xc
 *   @0x2aa2b2 and r8, r8, #0x3
 *   @0x2aa2b6 lsl.w r11, r8, #0x4
 *   @0x2aa2ba orr.w r11, r11, r8, lsl #6
 *   @0x2aa2be orr.w r11, r11, r8
 *   @0x2aa2c2 orr.w r8, r11, r8, lsl #2
 *   @0x2aa2c6 asr.w r11, r12, #0x4
 *   @0x2aa2ca orr.w r11, r11, r12, lsr #2
 *   @0x2aa2ce orr.w r11, r11, r12
 *   @0x2aa2d2 ldrb.w r8, [r2, r8]
 *   @0x2aa2d6 orr.w r12, r11, r12, lsr #6
 *   @0x2aa2da ldrb.w r12, [r2, r12]
 *   @0x2aa2de bic r12, r12, #0x3f
 *   @0x2aa2e2 orr.w r12, r12, r8, lsr #6
 *   @0x2aa2e6 asr.w r8, r7, #0x2
 *   @0x2aa2ea orr.w r8, r8, r7, lsl #2
 *   @0x2aa2ee orr.w r8, r8, r7
 *   @0x2aa2f2 orr.w r7, r8, r7, lsr #4
 *   @0x2aa2f6 ldrb r7, [r2, r7]
 *   @0x2aa2fa and r7, r7, #0x30
 *   @0x2aa2fe orr.w r12, r12, r7
 *   @0x2aa302 lsls r7, r6, #0x2
 *   @0x2aa306 teqmi r7, #1572864
 *   @0x2aa30a orr.w r6, r7, r6, lsr #2
 *   @0x2aa30e ldrb r7, [r2, r6]
 *   @0x2aa312 and r7, r7, #0xc
 *   @0x2aa316 orr.w r6, r12, r7
 *   @0x2aa31a strb r6, [r10], #1
 *   @0x2aa31e b 0x2aa29a <png_do_gamma+0x1c4>
 *   @0x2aa322 bhs 0x2aa34a <png_do_gamma+0x274>
 *   @0x2aa326 adds r3, #0x2
 *   @0x2aa32a .word 0xf00500f0
 *   @0x2aa32e b 0x12ab772 <b2_toiTime+0xb522ce>
 *   @0x2aa332 b 0x13ee37a <b2_toiTime+0xc94ed6>
 *   @0x2aa336 .word 0x5c101505
 *   @0x2aa33a ldrb r5, [r2, r5]
 *   @0x2aa33e b 0x12aa382 <b2_toiTime+0xb50ede>
 *   @0x2aa342 .word 0xf8011015
 *   @0x2aa346 strb r0, [r10, r1, lsl #22]!
 *   @0x2aa34a pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2aa34e cmp r0, #0x8
 *   @0x2aa352 add r4, r1
 *   @0x2aa356 beq 0x2aa362 <png_do_gamma+0x28c>
 *   @0x2aa35a ldrb r3, [r2, r3]
 *   @0x2aa35e ldrb r3, [r8, r1, lsl #22]!
 *   @0x2aa362 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2aa366 cmp r0, #0x10
 *   @0x2aa36a movs r2, #0x0
 *   @0x2aa36e add.w r1, r1, #0x2
 *   @0x2aa372 beq 0x2aa394 <png_do_gamma+0x2be>
 *   @0x2aa376 andlo r0, r1, #256
 *   @0x2aa37a ldrb r6, [r1, #-2]
 *   @0x2aa37e asrs r0, r5
 *   @0x2aa382 rfeda r0!
 *   @0x2aa386 beq 0x42a3e6 <g_RomDisk+0x32bc6>
 *   @0x2aa38a strb r0, [r1, #-1]
 *   @0x2aa38e strb r6, [r1, #-2]
 *   @0x2aa392 b 0x2aa36c <png_do_gamma+0x296>
 *   @0x2aa396 push {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §18/43 F_DsPriorityFindPriority(RValue&, CInstance*, CInstance*, int, RValue*)  0x10296c  size 704  176 条（0x10296c..0x102c2c）
 * @func 0x10296c 0x102c2c  size 704  176 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / YYGetInt32(RValue const*, int) / F_DsPriorityFindPriority(RValue&, CInstance*, CInstance*, int, RValue*)+0x110 / CDS_Priority::Find(RValue*) / GetContextStackTop()
 * 字段偏移 top8: 0x4×9 / 0x8×8 / 0xc×5 / 0x18×1 / 0x28c×1 / 0x27c×1 / 0x2×1 / 0x1a4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10296c push {r3, r4, r5, r6, r7, lr}
 *   @0x102970 mov r1, #0
 *   @0x102974 ldr r5, [sp, #0x18]
 *   @0x102978 mov r4, r0
 *   @0x10297c mov r0, r5
 *   @0x102980 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x102984 cmp r0, #0
 *   @0x102988 blt 0x102a7c <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x110>
 *   @0x10298c ldr r3, [pc, #0x28c]
 *   @0x102990 ldr r3, [pc, r3]
 *   @0x102994 ldr r3, [r3]
 *   @0x102998 cmp r0, r3
 *   @0x10299c bge 0x102a7c <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x110>
 *   @0x1029a0 ldr r3, [pc, #0x27c]
 *   @0x1029a4 ldr r3, [pc, r3]
 *   @0x1029a8 ldr r3, [r3, #0x4]
 *   @0x1029ac ldr r0, [r3, r0, lsl #2]
 *   @0x1029b0 cmp r0, #0
 *   @0x1029b4 beq 0x102a7c <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x110>
 *   @0x1029b8 add r1, r5, #16
 *   @0x1029bc bl 0x203f90 <_ZN12CDS_Priority4FindEP6RValue>
 *   @0x1029c0 subs r5, r0, #0
 *   @0x1029c4 streq r5, [r4]
 *   @0x1029c8 streq r5, [r4, #0x4]
 *   @0x1029cc moveq r3, #5
 *   @0x1029d0 streq r3, [r4, #0xc]
 *   @0x1029d4 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1029d8 ldr r2, [r4, #0xc]
 *   @0x1029dc bic r3, r2, #-16777216
 *   @0x1029e0 cmp r3, #1
 *   @0x1029e4 beq 0x102aa8 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x1029e8 cmp r3, #2
 *   @0x1029ec bne 0x102a14 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x1029f0 sub r2, r2, #1
 *   @0x1029f4 bic r2, r2, #-16777216
 *   @0x1029f8 bic r2, r2, #3
 *   @0x1029fc cmp r2, #0
 *   @0x102a00 beq 0x102b7c <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x210>
 *   @0x102a04 mov r2, #0
 *   @0x102a08 mov r3, #5
 *   @0x102a0c str r2, [r4, #0x8]
 *   @0x102a10 str r3, [r4, #0xc]
 *   @0x102a14 ldr r3, [r5, #0xc]
 *   @0x102a18 mov r1, #0
 *   @0x102a1c ldr r2, [r5, #0x8]
 *   @0x102a20 str r1, [r4]
 *   @0x102a24 str r3, [r4, #0xc]
 *   @0x102a28 ldr r3, [r5, #0xc]
 *   @0x102a2c str r2, [r4, #0x8]
 *   @0x102a30 bic r3, r3, #-16777216
 *   @0x102a34 cmp r3, #14
 *   @0x102a38 addls pc, pc, r3, lsl #2
 *   @0x102a3c b 0x102a98 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x102a40 b 0x102a9c <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x102a44 b 0x102b00 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0x102a48 b 0x102b18 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x1ac>
 *   @0x102a4c b 0x102a90 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x102a50 b 0x102a98 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x102a54 b 0x102a98 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x102a58 b 0x102adc <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x170>
 *   @0x102a5c b 0x102a90 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x102a60 b 0x102a98 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x102a64 b 0x102a98 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x102a68 b 0x102a9c <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x102a6c b 0x102a98 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x102a70 b 0x102a98 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x102a74 b 0x102a9c <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x102a78 b 0x102a90 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x102a7c ldr r0, [pc, #0x1a4]
 *   @0x102a80 mov r1, #0
 *   @0x102a84 pop {r3, r4, r5, r6, r7, lr}
 *   @0x102a88 add r0, pc, r0
 *   @0x102a8c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x102a90 ldr r3, [r5]
 *   @0x102a94 str r3, [r4]
 *   @0x102a98 pop {r3, r4, r5, r6, r7, pc}
 *   @0x102a9c ldm r5, {r2, r3}
 *   @0x102aa0 stm r4, {r2, r3}
 *   @0x102aa4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x102aa8 ldr r6, [r4]
 *   @0x102aac cmp r6, #0
 *   @0x102ab0 beq 0x102ad0 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x164>
 *   @0x102ab4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x102ab8 ldr r7, [r6, #0x4]
 *   @0x102abc sub r7, r7, #1
 *   @0x102ac0 str r7, [r6, #0x4]
 *   @0x102ac4 cmp r7, #0
 *   @0x102ac8 beq 0x102b44 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x1d8>
 *   @0x102acc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x102ad0 mov r3, #0
 *   @0x102ad4 str r3, [r4]
 *   @0x102ad8 b 0x102a14 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x102adc ldr r3, [r5]
 *   @0x102ae0 str r3, [r4]
 *   @0x102ae4 ldr r3, [r5]
 *   @0x102ae8 cmp r3, #0
 *   @0x102aec popeq {r3, r4, r5, r6, r7, pc}
 *   @0x102af0 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x102af4 ldr r1, [r5]
 *   @0x102af8 pop {r3, r4, r5, r6, r7, lr}
 *   @0x102afc b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x102b00 ldr r3, [r5]
 *   @0x102b04 cmp r3, #0
 *   @0x102b08 ldrne r2, [r3, #0x4]
 *   @0x102b0c addne r2, r2, #1
 *   @0x102b10 strne r2, [r3, #0x4]
 *   @0x102b14 b 0x102a94 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x102b18 ldr r3, [r5]
 *   @0x102b1c cmp r3, #0
 *   @0x102b20 str r3, [r4]
 *   @0x102b24 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x102b28 ldr r1, [r3, #0x8]
 *   @0x102b2c ldr r2, [r3]
 *   @0x102b30 cmp r1, #0
 *   @0x102b34 streq r4, [r3, #0x8]
 *   @0x102b38 add r2, r2, #1
 *   @0x102b3c str r2, [r3]
 *   @0x102b40 pop {r3, r4, r5, r6, r7, pc}
 *   @0x102b44 ldr r0, [r6]
 *   @0x102b48 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x102b4c str r7, [r6]
 *   @0x102b50 str r7, [r6, #0x8]
 *   @0x102b54 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x102b58 ldr r7, [r6, #0x4]
 *   @0x102b5c sub r7, r7, #1
 *   @0x102b60 str r7, [r6, #0x4]
 *   @0x102b64 cmp r7, #0
 *   @0x102b68 beq 0x102b88 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x21c>
 *   @0x102b6c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x102b70 mov r0, r6
 *   @0x102b74 bl 0x27d1d0 <_ZdlPv>
 *   @0x102b78 b 0x102acc <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x102b7c mov r0, r4
 *   @0x102b80 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x102b84 b 0x102a04 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x102b88 ldr r0, [r6]
 *   @0x102b8c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x102b90 str r7, [r6]
 *   @0x102b94 str r7, [r6, #0x8]
 *   @0x102b98 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x102b9c ldr r7, [r6, #0x4]
 *   @0x102ba0 sub r7, r7, #1
 *   @0x102ba4 str r7, [r6, #0x4]
 *   @0x102ba8 cmp r7, #0
 *   @0x102bac beq 0x102bc0 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x254>
 *   @0x102bb0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x102bb4 mov r0, r6
 *   @0x102bb8 bl 0x27d1d0 <_ZdlPv>
 *   @0x102bbc b 0x102b6c <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x200>
 *   @0x102bc0 ldr r0, [r6]
 *   @0x102bc4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x102bc8 str r7, [r6]
 *   @0x102bcc str r7, [r6, #0x8]
 *   @0x102bd0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x102bd4 ldr r3, [r6, #0x4]
 *   @0x102bd8 sub r3, r3, #1
 *   @0x102bdc str r3, [r6, #0x4]
 *   @0x102be0 cmp r3, #0
 *   @0x102be4 beq 0x102bf8 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x28c>
 *   @0x102be8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x102bec mov r0, r6
 *   @0x102bf0 bl 0x27d1d0 <_ZdlPv>
 *   @0x102bf4 b 0x102bb0 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x244>
 *   @0x102bf8 ldr r0, [r6]
 *   @0x102bfc bl 0xcef90 <_Z6YYFreePKv>
 *   @0x102c00 mov r3, #0
 *   @0x102c04 mov r0, r6
 *   @0x102c08 str r3, [r6]
 *   @0x102c0c str r3, [r6, #0x8]
 *   @0x102c10 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x102c14 mov r0, r6
 *   @0x102c18 bl 0x27d1d0 <_ZdlPv>
 *   @0x102c1c b 0x102be8 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x27c>
 *   @0x102c20 eoreq r11, lr, r4, ror #9
 *   @0x102c24 .word 0x002eb4d4
 *   @0x102c28 eoreq r5, r3, r4, ror r1
 *
 * ══ §19/43 CreateFindData(yyFindData*, char const*, char const*, double)  0x160818  size 704  176 条（0x160818..0x160ad8）
 * @func 0x160818 0x160ad8  size 704  176 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x160920→0x757768, 0x1609d0→0x3f2370, 0x160a78→0x3eb70c
 * 调用序列: CompareFileNames(char const*, char const*)×2 / yyFindData::AddFile(char const*)×2 / 0xb655c×2 / 0xb6868 / 0xb68ec / CreateFindData(yyFindData*, char const*, char const*, double)+0x108 / zip_get_num_files / CreateFindData(yyFindData*, char const*, char const*, double)+0x20c
 * 字段偏移 top8: 0x14×4 / 0x1×4 / 0x4×3 / 0xc×3 / 0x8×2 / 0x81c×2 / 0x-1×2 / 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160818 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x16081c sub sp, sp, #2080
 *   @0x160820 ldr r6, [pc, #0x298]
 *   @0x160824 sub sp, sp, #4
 *   @0x160828 ldr r3, [pc, #0x294]
 *   @0x16082c mov r4, r1
 *   @0x160830 add r6, pc, r6
 *   @0x160834 str r0, [sp, #0x4]
 *   @0x160838 mov r1, #47
 *   @0x16083c mov r0, r4
 *   @0x160840 ldr r3, [r6, r3]
 *   @0x160844 mov r10, r2
 *   @0x160848 add r9, sp, #32
 *   @0x16084c str r3, [sp, #0x8]
 *   @0x160850 ldr r3, [r3]
 *   @0x160854 str r3, [sp, #0x81c]
 *   @0x160858 bl 0xb6868 <strrchr@plt>
 *   @0x16085c mov r3, #0
 *   @0x160860 sub r1, r9, #12
 *   @0x160864 mov r2, r3
 *   @0x160868 mov r7, r0
 *   @0x16086c mov r0, r4
 *   @0x160870 strb r3, [r7]
 *   @0x160874 bl 0xb68ec <scandir@plt>
 *   @0x160878 cmp r0, #0
 *   @0x16087c blt 0x160920 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x108>
 *   @0x160880 sub r4, r0, #1
 *   @0x160884 beq 0x160918 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x100>
 *   @0x160888 ldr r11, [sp, #0x4]
 *   @0x16088c lsl r4, r4, #2
 *   @0x160890 add r7, r7, #1
 *   @0x160894 sub r8, r9, #4
 *   @0x160898 mov r5, r0
 *   @0x16089c ldr r3, [sp, #0x14]
 *   @0x1608a0 mov r1, r7
 *   @0x1608a4 ldr r0, [r3, r4]
 *   @0x1608a8 add r0, r0, #19
 *   @0x1608ac bl 0x16068c <_Z16CompareFileNamesPKcS0_>
 *   @0x1608b0 cmp r0, #0
 *   @0x1608b4 beq 0x160900 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0xe8>
 *   @0x1608b8 ldr r3, [sp, #0x14]
 *   @0x1608bc mov r2, r8
 *   @0x1608c0 ldr r1, [r3, r4]
 *   @0x1608c4 add r1, r1, #19
 *   @0x1608c8 ldrb r3, [r1], #1
 *   @0x1608cc cmp r3, #0
 *   @0x1608d0 beq 0x1608f0 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0xd8>
 *   @0x1608d4 tst r3, #128
 *   @0x1608d8 bne 0x160a44 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x22c>
 *   @0x1608dc strb r3, [r2]
 *   @0x1608e0 add r2, r2, #1
 *   @0x1608e4 ldrb r3, [r1], #1
 *   @0x1608e8 cmp r3, #0
 *   @0x1608ec bne 0x1608d4 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0xbc>
 *   @0x1608f0 strb r3, [r2]
 *   @0x1608f4 mov r0, r11
 *   @0x1608f8 mov r1, r8
 *   @0x1608fc bl 0x13ac60 <_ZN10yyFindData7AddFileEPKc>
 *   @0x160900 ldr r3, [sp, #0x14]
 *   @0x160904 ldr r0, [r3, r4]
 *   @0x160908 sub r4, r4, #4
 *   @0x16090c bl 0xb655c <free@plt>
 *   @0x160910 subs r5, r5, #1
 *   @0x160914 bne 0x16089c <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x84>
 *   @0x160918 ldr r0, [sp, #0x14]
 *   @0x16091c bl 0xb655c <free@plt>
 *   @0x160920 ldr r3, [pc, #0x1a0]
 *   @0x160924 ldr r7, [r6, r3]
 *   @0x160928 ldr r0, [r7]
 *   @0x16092c blx 0x2a490e <zip_get_num_files>
 *   @0x160930 subs r8, r0, #0
 *   @0x160934 ble 0x160a24 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x20c>
 *   @0x160938 ldr r1, [pc, #0x18c]
 *   @0x16093c sub r9, r9, #4
 *   @0x160940 add r4, sp, #24
 *   @0x160944 mov r5, #0
 *   @0x160948 add r1, pc, r1
 *   @0x16094c str r1, [sp, #0xc]
 *   @0x160950 ldr r0, [r7]
 *   @0x160954 mov r1, r5
 *   @0x160958 mov r2, #0
 *   @0x16095c blx 0x2a4970 <zip_get_name>
 *   @0x160960 subs r11, r0, #0
 *   @0x160964 beq 0x160a78 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x260>
 *   @0x160968 mov r1, r10
 *   @0x16096c bl 0x16068c <_Z16CompareFileNamesPKcS0_>
 *   @0x160970 cmp r0, #0
 *   @0x160974 beq 0x160a18 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x200>
 *   @0x160978 mov r0, r11
 *   @0x16097c bl 0xb6538 <strlen@plt>
 *   @0x160980 cmp r0, #0
 *   @0x160984 blt 0x1609b0 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x198>
 *   @0x160988 ldrb r1, [r11, r0]
 *   @0x16098c add r2, r11, r0
 *   @0x160990 cmp r1, #47
 *   @0x160994 bne 0x1609a8 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x190>
 *   @0x160998 b 0x160a70 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x258>
 *   @0x16099c ldrb r3, [r2, #-0x1]!
 *   @0x1609a0 cmp r3, #47
 *   @0x1609a4 beq 0x160a70 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x258>
 *   @0x1609a8 subs r0, r0, #1
 *   @0x1609ac bhs 0x16099c <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x184>
 *   @0x1609b0 str r9, [sp, #0x18]
 *   @0x1609b4 add r2, r11, r0
 *   @0x1609b8 ldrb r1, [r11, r0]
 *   @0x1609bc cmp r1, #0
 *   @0x1609c0 beq 0x160ab4 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x29c>
 *   @0x1609c4 mov r11, r2
 *   @0x1609c8 cmp r1, #127
 *   @0x1609cc ble 0x1609e8 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x1d0>
 *   @0x1609d0 ldr r3, [pc, #0xf8]
 *   @0x1609d4 add r1, r1, #1073741824
 *   @0x1609d8 sub r1, r1, #128
 *   @0x1609dc ldr r3, [r6, r3]
 *   @0x1609e0 ldr r3, [r3]
 *   @0x1609e4 ldr r1, [r3, r1, lsl #2]
 *   @0x1609e8 uxth r1, r1
 *   @0x1609ec mov r0, r4
 *   @0x1609f0 bl 0x10fe28 <utf8_add_char>
 *   @0x1609f4 ldrb r1, [r11, #0x1]!
 *   @0x1609f8 cmp r1, #0
 *   @0x1609fc bne 0x1609c8 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x1b0>
 *   @0x160a00 ldr r3, [sp, #0x18]
 *   @0x160a04 mov r2, #0
 *   @0x160a08 ldr r0, [sp, #0x4]
 *   @0x160a0c strb r2, [r3]
 *   @0x160a10 mov r1, r9
 *   @0x160a14 bl 0x13ac60 <_ZN10yyFindData7AddFileEPKc>
 *   @0x160a18 add r5, r5, #1
 *   @0x160a1c cmp r5, r8
 *   @0x160a20 bne 0x160950 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x138>
 *   @0x160a24 ldr r1, [sp, #0x8]
 *   @0x160a28 ldr r2, [sp, #0x81c]
 *   @0x160a2c ldr r3, [r1]
 *   @0x160a30 cmp r2, r3
 *   @0x160a34 bne 0x160abc <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x2a4>
 *   @0x160a38 add sp, sp, #2080
 *   @0x160a3c add sp, sp, #4
 *   @0x160a40 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x160a44 cmp r3, #191
 *   @0x160a48 mov r0, r2
 *   @0x160a4c movls r3, #194
 *   @0x160a50 movhi r3, #195
 *   @0x160a54 strb r3, [r0], #2
 *   @0x160a58 ldrb r3, [r1, #-0x1]
 *   @0x160a5c and r3, r3, #63
 *   @0x160a60 sub r3, r3, #128
 *   @0x160a64 strb r3, [r2, #0x1]
 *   @0x160a68 mov r2, r0
 *   @0x160a6c b 0x1608c8 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0xb0>
 *   @0x160a70 add r0, r0, #1
 *   @0x160a74 b 0x1609b0 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x198>
 *   @0x160a78 ldr r3, [pc, #0x54]
 *   @0x160a7c ldr r0, [r7]
 *   @0x160a80 ldr r3, [r6, r3]
 *   @0x160a84 ldr r2, [r3]
 *   @0x160a88 ldr r3, [r2]
 *   @0x160a8c ldr r11, [r3, #0xc]
 *   @0x160a90 str r2, [sp]
 *   @0x160a94 blx 0x2a5764 <zip_strerror>
 *   @0x160a98 ldr r2, [sp]
 *   @0x160a9c ldr r1, [sp, #0xc]
 *   @0x160aa0 mov r3, r0
 *   @0x160aa4 mov r0, r2
 *   @0x160aa8 mov r2, r5
 *   @0x160aac blx r11
 *   @0x160ab0 b 0x160a18 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x200>
 *   @0x160ab4 mov r3, r9
 *   @0x160ab8 b 0x160a04 <_Z14CreateFindDataP10yyFindDataPKcS2_d+0x1ec>
 *   @0x160abc bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x160ac0 eoreq r1, r9, r0, lsr #8
 *   @0x160ac4 .word 0xffffbd00
 *   @0x160ac8 .word 0xffffe2c4
 *   @0x160acc andseq r9, lr, r4, ror #2
 *   @0x160ad0 .word 0xffffe2c8
 *   @0x160ad4 .word 0xffffbac4
 *
 * ══ §20/43 JS_Math_pow(RValue&, CInstance*, CInstance*, int, RValue*)  0x252760  size 704  176 条（0x252760..0x252a20）
 * @func 0x252760 0x252a20  size 704  176 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: myispos(double)×6 / F_JS_ToNumber(RValue&, RValue&)×2 / YYGetReal(RValue const*, int)×2 / myisinf(double)×2 / JS_Math_pow(RValue&, CInstance*, CInstance*, int, RValue*)+0xfc / JS_Math_pow(RValue&, CInstance*, CInstance*, int, RValue*)+0x198 / JSThrowTypeError(char const*) / 0xb6784
 * 字段偏移 top8: 0xc×2 / 0x48×2 / 0x4×2 / 0x1c×1 / 0x1a0×1
 * VFP 指令 50 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x252760 cmp r3, #1
 *   @0x252764 push {r4, r5, r6, r7, lr}
 *   @0x252768 vpush {d8, d9}
 *   @0x25276c mov r5, #0
 *   @0x252770 sub sp, sp, #36
 *   @0x252774 mov r4, r0
 *   @0x252778 str r5, [r0, #0xc]
 *   @0x25277c ble 0x25285c <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x252780 ldr r3, [sp, #0x48]
 *   @0x252784 mov r0, sp
 *   @0x252788 add r1, r3, #16
 *   @0x25278c mov r3, #5
 *   @0x252790 str r3, [sp, #0xc]
 *   @0x252794 str r3, [sp, #0x1c]
 *   @0x252798 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_>
 *   @0x25279c cmp r0, #1
 *   @0x2527a0 beq 0x252874 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x114>
 *   @0x2527a4 add r7, sp, #16
 *   @0x2527a8 ldr r1, [sp, #0x48]
 *   @0x2527ac mov r0, r7
 *   @0x2527b0 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_>
 *   @0x2527b4 cmp r0, #1
 *   @0x2527b8 beq 0x252874 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x114>
 *   @0x2527bc mov r0, sp
 *   @0x2527c0 mov r1, r5
 *   @0x2527c4 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x2527c8 vmov d8, r0, r1
 *   @0x2527cc mov r0, r7
 *   @0x2527d0 mov r1, r5
 *   @0x2527d4 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x2527d8 vmov d9, r0, r1
 *   @0x2527dc vmov r0, r1, d8
 *   @0x2527e0 bl 0x24364c <_Z7myisinfd>
 *   @0x2527e4 mov r6, r0
 *   @0x2527e8 vmov r0, r1, d9
 *   @0x2527ec bl 0x24364c <_Z7myisinfd>
 *   @0x2527f0 vcmp.f64 d8, d8
 *   @0x2527f4 vmrs APSR_nzcv, fpscr
 *   @0x2527f8 bvs 0x25285c <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x2527fc vcmp.f64 d8, #0
 *   @0x252800 vmrs APSR_nzcv, fpscr
 *   @0x252804 beq 0x25288c <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x252808 vcmp.f64 d9, d9
 *   @0x25280c vmrs APSR_nzcv, fpscr
 *   @0x252810 bvs 0x25285c <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x252814 cmp r6, #0
 *   @0x252818 bne 0x25290c <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x1ac>
 *   @0x25281c cmp r0, #0
 *   @0x252820 bne 0x2528dc <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x17c>
 *   @0x252824 vcmp.f64 d9, #0
 *   @0x252828 vmov r0, r1, d9
 *   @0x25282c vmrs APSR_nzcv, fpscr
 *   @0x252830 bne 0x2528a8 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x148>
 *   @0x252834 bl 0x243674 <_Z7myisposd>
 *   @0x252838 cmp r0, #0
 *   @0x25283c beq 0x252980 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x220>
 *   @0x252840 vcmpe.f64 d8, #0
 *   @0x252844 vmrs APSR_nzcv, fpscr
 *   @0x252848 ble 0x2528f8 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x25284c mov r3, #0
 *   @0x252850 str r3, [r4]
 *   @0x252854 str r3, [r4, #0x4]
 *   @0x252858 b 0x252868 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x25285c mvn r2, #0
 *   @0x252860 mvn r3, #-2147483648
 *   @0x252864 stm r4, {r2, r3}
 *   @0x252868 add sp, sp, #36
 *   @0x25286c vpop {d8, d9}
 *   @0x252870 pop {r4, r5, r6, r7, pc}
 *   @0x252874 ldr r0, [pc, #0x1a0]
 *   @0x252878 add r0, pc, r0
 *   @0x25287c bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x252880 add sp, sp, #36
 *   @0x252884 vpop {d8, d9}
 *   @0x252888 pop {r4, r5, r6, r7, pc}
 *   @0x25288c str r5, [r4]
 *   @0x252890 mov r3, #0
 *   @0x252894 movt r3, #0x3ff0
 *   @0x252898 str r3, [r4, #0x4]
 *   @0x25289c add sp, sp, #36
 *   @0x2528a0 vpop {d8, d9}
 *   @0x2528a4 pop {r4, r5, r6, r7, pc}
 *   @0x2528a8 bl 0x243674 <_Z7myisposd>
 *   @0x2528ac cmp r0, #0
 *   @0x2528b0 bne 0x2528c8 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x2528b4 vcvt.s32.f64 s14, d8
 *   @0x2528b8 vcvt.f64.s32 d7, s14
 *   @0x2528bc vcmp.f64 d8, d7
 *   @0x2528c0 vmrs APSR_nzcv, fpscr
 *   @0x2528c4 bne 0x25285c <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x2528c8 vmov r0, r1, d9
 *   @0x2528cc vmov r2, r3, d8
 *   @0x2528d0 bl 0xb6784 <pow@plt>
 *   @0x2528d4 stm r4, {r0, r1}
 *   @0x2528d8 b 0x252868 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x2528dc vmov r0, r1, d9
 *   @0x2528e0 bl 0x243674 <_Z7myisposd>
 *   @0x2528e4 cmp r0, #0
 *   @0x2528e8 beq 0x2529cc <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x26c>
 *   @0x2528ec vcmpe.f64 d8, #0
 *   @0x2528f0 vmrs APSR_nzcv, fpscr
 *   @0x2528f4 ble 0x25284c <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x2528f8 mov r3, #0
 *   @0x2528fc mov r2, r3
 *   @0x252900 movt r3, #0x7ff0
 *   @0x252904 stm r4, {r2, r3}
 *   @0x252908 b 0x252868 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x25290c vmov r0, r1, d8
 *   @0x252910 bl 0x243674 <_Z7myisposd>
 *   @0x252914 vmov.f64 d7, #1.000000e+00
 *   @0x252918 vabs.f64 d9, d9
 *   @0x25291c vcmpe.f64 d9, d7
 *   @0x252920 vmrs APSR_nzcv, fpscr
 *   @0x252924 ble 0x252934 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x1d4>
 *   @0x252928 cmp r0, #0
 *   @0x25292c beq 0x25284c <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x252930 b 0x2528f8 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x252934 ble 0x252940 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x1e0>
 *   @0x252938 cmp r0, #0
 *   @0x25293c beq 0x25284c <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x252940 vmov.f64 d7, #1.000000e+00
 *   @0x252944 vcmp.f64 d9, d7
 *   @0x252948 vmrs APSR_nzcv, fpscr
 *   @0x25294c movne r3, #0
 *   @0x252950 moveq r3, #1
 *   @0x252954 tst r0, r3
 *   @0x252958 bne 0x25285c <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x25295c eor r2, r0, #1
 *   @0x252960 tst r3, r2
 *   @0x252964 bne 0x25285c <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x252968 vcmpe.f64 d9, d7
 *   @0x25296c vmrs APSR_nzcv, fpscr
 *   @0x252970 bpl 0x2528f8 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x252974 cmp r0, #0
 *   @0x252978 bne 0x25284c <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x25297c b 0x2528f8 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x252980 vcvt.s32.f64 s18, d8
 *   @0x252984 vmov r0, r1, d8
 *   @0x252988 vcvt.f64.s32 d7, s18
 *   @0x25298c vcmp.f64 d8, d7
 *   @0x252990 vmrs APSR_nzcv, fpscr
 *   @0x252994 movne r5, #0
 *   @0x252998 moveq r5, #1
 *   @0x25299c bl 0x243674 <_Z7myisposd>
 *   @0x2529a0 cmp r0, #0
 *   @0x2529a4 beq 0x2529f4 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x294>
 *   @0x2529a8 cmp r5, #0
 *   @0x2529ac beq 0x25284c <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x2529b0 vmov r3, s18
 *   @0x2529b4 tst r3, #1
 *   @0x2529b8 beq 0x25284c <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x2529bc mov r2, #0
 *   @0x2529c0 mov r3, #-2147483648
 *   @0x2529c4 stm r4, {r2, r3}
 *   @0x2529c8 b 0x252868 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x2529cc vcvt.s32.f64 s18, d8
 *   @0x2529d0 vmov r0, r1, d8
 *   @0x2529d4 vcvt.f64.s32 d7, s18
 *   @0x2529d8 vcmp.f64 d8, d7
 *   @0x2529dc vmrs APSR_nzcv, fpscr
 *   @0x2529e0 movne r5, #0
 *   @0x2529e4 moveq r5, #1
 *   @0x2529e8 bl 0x243674 <_Z7myisposd>
 *   @0x2529ec cmp r0, #0
 *   @0x2529f0 beq 0x2529a8 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x248>
 *   @0x2529f4 cmp r5, #0
 *   @0x2529f8 beq 0x2528f8 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x2529fc vmov r3, s18
 *   @0x252a00 tst r3, #1
 *   @0x252a04 beq 0x2528f8 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x252a08 mov r3, #0
 *   @0x252a0c mov r2, r3
 *   @0x252a10 movt r3, #0xfff0
 *   @0x252a14 stm r4, {r2, r3}
 *   @0x252a18 b 0x252868 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x252a1c ldrsbeq r3, [r0], -r0
 *
 * ══ §21/43 F_DsListSetPre(RValue&, CInstance*, CInstance*, int, RValue*)  0x102044  size 700  175 条（0x102044..0x102300）
 * @func 0x102044 0x102300  size 700  175 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / YYGetInt32(RValue const*, int)×2 / F_DsListSetPre(RValue&, CInstance*, CInstance*, int, RValue*)+0x110 / CDS_List::Set(int, RValue*, RValue*) / GetContextStackTop()
 * 字段偏移 top8: 0x4×9 / 0x8×7 / 0x20×7 / 0xc×3 / 0x2c×2 / 0x18×1 / 0x288×1 / 0x278×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x102044 push {r3, r4, r5, r6, r7, lr}
 *   @0x102048 mov r1, #0
 *   @0x10204c ldr r4, [sp, #0x18]
 *   @0x102050 mov r5, r0
 *   @0x102054 mov r0, r4
 *   @0x102058 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x10205c cmp r0, #0
 *   @0x102060 blt 0x102154 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x110>
 *   @0x102064 ldr r3, [pc, #0x288]
 *   @0x102068 ldr r3, [pc, r3]
 *   @0x10206c ldr r3, [r3]
 *   @0x102070 cmp r0, r3
 *   @0x102074 bge 0x102154 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x110>
 *   @0x102078 ldr r3, [pc, #0x278]
 *   @0x10207c ldr r3, [pc, r3]
 *   @0x102080 ldr r3, [r3, #0x4]
 *   @0x102084 ldr r6, [r3, r0, lsl #2]
 *   @0x102088 cmp r6, #0
 *   @0x10208c beq 0x102154 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x110>
 *   @0x102090 mov r1, #1
 *   @0x102094 mov r0, r4
 *   @0x102098 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x10209c add r2, r4, #32
 *   @0x1020a0 mov r3, #0
 *   @0x1020a4 mov r1, r0
 *   @0x1020a8 mov r0, r6
 *   @0x1020ac bl 0x2060c0 <_ZN8CDS_List3SetEiP6RValueS1_>
 *   @0x1020b0 ldr r2, [r5, #0xc]
 *   @0x1020b4 bic r3, r2, #-16777216
 *   @0x1020b8 cmp r3, #1
 *   @0x1020bc beq 0x102184 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x1020c0 cmp r3, #2
 *   @0x1020c4 bne 0x1020ec <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x1020c8 sub r2, r2, #1
 *   @0x1020cc bic r2, r2, #-16777216
 *   @0x1020d0 bic r2, r2, #3
 *   @0x1020d4 cmp r2, #0
 *   @0x1020d8 beq 0x102258 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x214>
 *   @0x1020dc mov r2, #0
 *   @0x1020e0 mov r3, #5
 *   @0x1020e4 str r2, [r5, #0x8]
 *   @0x1020e8 str r3, [r5, #0xc]
 *   @0x1020ec ldr r3, [r4, #0x2c]
 *   @0x1020f0 mov r1, #0
 *   @0x1020f4 ldr r2, [r4, #0x28]
 *   @0x1020f8 str r1, [r5]
 *   @0x1020fc str r3, [r5, #0xc]
 *   @0x102100 ldr r3, [r4, #0x2c]
 *   @0x102104 str r2, [r5, #0x8]
 *   @0x102108 bic r3, r3, #-16777216
 *   @0x10210c cmp r3, #14
 *   @0x102110 addls pc, pc, r3, lsl #2
 *   @0x102114 b 0x102170 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x102118 b 0x102174 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x10211c b 0x1021dc <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x102120 b 0x1021f4 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x1b0>
 *   @0x102124 b 0x102168 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x102128 b 0x102170 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x10212c b 0x102170 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x102130 b 0x1021b8 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x174>
 *   @0x102134 b 0x102168 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x102138 b 0x102170 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x10213c b 0x102170 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x102140 b 0x102174 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x102144 b 0x102170 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x102148 b 0x102170 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x10214c b 0x102174 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x102150 b 0x102168 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x102154 ldr r0, [pc, #0x1a0]
 *   @0x102158 mov r1, #0
 *   @0x10215c pop {r3, r4, r5, r6, r7, lr}
 *   @0x102160 add r0, pc, r0
 *   @0x102164 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x102168 ldr r3, [r4, #0x20]
 *   @0x10216c str r3, [r5]
 *   @0x102170 pop {r3, r4, r5, r6, r7, pc}
 *   @0x102174 ldr r2, [r4, #0x20]
 *   @0x102178 ldr r3, [r4, #0x24]
 *   @0x10217c stm r5, {r2, r3}
 *   @0x102180 pop {r3, r4, r5, r6, r7, pc}
 *   @0x102184 ldr r6, [r5]
 *   @0x102188 cmp r6, #0
 *   @0x10218c beq 0x1021ac <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x102190 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x102194 ldr r7, [r6, #0x4]
 *   @0x102198 sub r7, r7, #1
 *   @0x10219c str r7, [r6, #0x4]
 *   @0x1021a0 cmp r7, #0
 *   @0x1021a4 beq 0x102220 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x1dc>
 *   @0x1021a8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1021ac mov r3, #0
 *   @0x1021b0 str r3, [r5]
 *   @0x1021b4 b 0x1020ec <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x1021b8 ldr r3, [r4, #0x20]
 *   @0x1021bc str r3, [r5]
 *   @0x1021c0 ldr r3, [r4, #0x20]
 *   @0x1021c4 cmp r3, #0
 *   @0x1021c8 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1021cc bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x1021d0 ldr r1, [r4, #0x20]
 *   @0x1021d4 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1021d8 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x1021dc ldr r3, [r4, #0x20]
 *   @0x1021e0 cmp r3, #0
 *   @0x1021e4 ldrne r2, [r3, #0x4]
 *   @0x1021e8 addne r2, r2, #1
 *   @0x1021ec strne r2, [r3, #0x4]
 *   @0x1021f0 b 0x10216c <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x1021f4 ldr r3, [r4, #0x20]
 *   @0x1021f8 cmp r3, #0
 *   @0x1021fc str r3, [r5]
 *   @0x102200 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x102204 ldr r1, [r3, #0x8]
 *   @0x102208 ldr r2, [r3]
 *   @0x10220c cmp r1, #0
 *   @0x102210 streq r5, [r3, #0x8]
 *   @0x102214 add r2, r2, #1
 *   @0x102218 str r2, [r3]
 *   @0x10221c pop {r3, r4, r5, r6, r7, pc}
 *   @0x102220 ldr r0, [r6]
 *   @0x102224 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x102228 str r7, [r6]
 *   @0x10222c str r7, [r6, #0x8]
 *   @0x102230 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x102234 ldr r7, [r6, #0x4]
 *   @0x102238 sub r7, r7, #1
 *   @0x10223c str r7, [r6, #0x4]
 *   @0x102240 cmp r7, #0
 *   @0x102244 beq 0x102264 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x220>
 *   @0x102248 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x10224c mov r0, r6
 *   @0x102250 bl 0x27d1d0 <_ZdlPv>
 *   @0x102254 b 0x1021a8 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x164>
 *   @0x102258 mov r0, r5
 *   @0x10225c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x102260 b 0x1020dc <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x102264 ldr r0, [r6]
 *   @0x102268 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x10226c str r7, [r6]
 *   @0x102270 str r7, [r6, #0x8]
 *   @0x102274 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x102278 ldr r7, [r6, #0x4]
 *   @0x10227c sub r7, r7, #1
 *   @0x102280 str r7, [r6, #0x4]
 *   @0x102284 cmp r7, #0
 *   @0x102288 beq 0x10229c <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x258>
 *   @0x10228c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x102290 mov r0, r6
 *   @0x102294 bl 0x27d1d0 <_ZdlPv>
 *   @0x102298 b 0x102248 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x204>
 *   @0x10229c ldr r0, [r6]
 *   @0x1022a0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1022a4 str r7, [r6]
 *   @0x1022a8 str r7, [r6, #0x8]
 *   @0x1022ac bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1022b0 ldr r7, [r6, #0x4]
 *   @0x1022b4 sub r7, r7, #1
 *   @0x1022b8 str r7, [r6, #0x4]
 *   @0x1022bc cmp r7, #0
 *   @0x1022c0 bne 0x1022e4 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x2a0>
 *   @0x1022c4 ldr r0, [r6]
 *   @0x1022c8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1022cc mov r0, r6
 *   @0x1022d0 str r7, [r6]
 *   @0x1022d4 str r7, [r6, #0x8]
 *   @0x1022d8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x1022dc mov r0, r6
 *   @0x1022e0 bl 0x27d1d0 <_ZdlPv>
 *   @0x1022e4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1022e8 mov r0, r6
 *   @0x1022ec bl 0x27d1d0 <_ZdlPv>
 *   @0x1022f0 b 0x10228c <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x248>
 *   @0x1022f4 eoreq r11, lr, r4, lsl r12
 *   @0x1022f8 eoreq r11, lr, r4, lsl #24
 *   @0x1022fc mlaeq r3, r12, r10, r5
 *
 * ══ §22/43 dsMapAddRValue  0x105130  size 700  175 条（0x105130..0x1053ec）
 * @func 0x105130 0x1053ec  size 700  175 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / FREE_RValue__Pre(RValue*)×2 / YYSetString(RValue*, char const*) / F_DsMapAdd(RValue&, CInstance*, CInstance*, int, RValue*) / GetContextStackTop()
 * 字段偏移 top8: 0x4×8 / 0x8×6 / 0x38×6 / 0x44×4 / 0x40×2 / 0x10×1 / 0x20×1 / 0x30×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x105130 vmov s13, r0
 *   @0x105134 mov r3, #0
 *   @0x105138 push {r4, r5, r6, lr}
 *   @0x10513c vcvt.f64.s32 d7, s13
 *   @0x105140 sub sp, sp, #72
 *   @0x105144 mov r4, #0
 *   @0x105148 add r0, sp, #40
 *   @0x10514c mov r5, #0
 *   @0x105150 str r3, [sp, #0x10]
 *   @0x105154 mov r6, r2
 *   @0x105158 str r3, [sp, #0x20]
 *   @0x10515c mvn r2, #-16777216
 *   @0x105160 str r3, [sp, #0x30]
 *   @0x105164 str r3, [sp, #0x40]
 *   @0x105168 str r3, [sp, #0x24]
 *   @0x10516c vstr d7, [sp, #24]
 *   @0x105170 str r2, [sp, #0x14]
 *   @0x105174 str r2, [sp, #0x34]
 *   @0x105178 str r2, [sp, #0x44]
 *   @0x10517c strd r4, r5, [sp, #8]
 *   @0x105180 strd r4, r5, [sp, #40]
 *   @0x105184 strd r4, r5, [sp, #56]
 *   @0x105188 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x10518c ldr r2, [sp, #0x44]
 *   @0x105190 bic r3, r2, #-16777216
 *   @0x105194 cmp r3, #1
 *   @0x105198 beq 0x105268 <dsMapAddRValue+0x138>
 *   @0x10519c cmp r3, #2
 *   @0x1051a0 bne 0x1051b8 <dsMapAddRValue+0x88>
 *   @0x1051a4 sub r2, r2, #1
 *   @0x1051a8 bic r2, r2, #-16777216
 *   @0x1051ac bic r2, r2, #3
 *   @0x1051b0 cmp r2, #0
 *   @0x1051b4 beq 0x105350 <dsMapAddRValue+0x220>
 *   @0x1051b8 ldr r2, [r6, #0xc]
 *   @0x1051bc mov r0, #0
 *   @0x1051c0 ldr r1, [r6, #0x8]
 *   @0x1051c4 bic r3, r2, #-16777216
 *   @0x1051c8 str r0, [sp, #0x38]
 *   @0x1051cc str r2, [sp, #0x44]
 *   @0x1051d0 str r1, [sp, #0x40]
 *   @0x1051d4 cmp r3, #14
 *   @0x1051d8 addls pc, pc, r3, lsl #2
 *   @0x1051dc b 0x105224 <dsMapAddRValue+0xf4>
 *   @0x1051e0 b 0x1052a4 <dsMapAddRValue+0x174>
 *   @0x1051e4 b 0x1052b0 <dsMapAddRValue+0x180>
 *   @0x1051e8 b 0x1052c8 <dsMapAddRValue+0x198>
 *   @0x1051ec b 0x10521c <dsMapAddRValue+0xec>
 *   @0x1051f0 b 0x105224 <dsMapAddRValue+0xf4>
 *   @0x1051f4 b 0x105224 <dsMapAddRValue+0xf4>
 *   @0x1051f8 b 0x1052f8 <dsMapAddRValue+0x1c8>
 *   @0x1051fc b 0x10521c <dsMapAddRValue+0xec>
 *   @0x105200 b 0x105224 <dsMapAddRValue+0xf4>
 *   @0x105204 b 0x105224 <dsMapAddRValue+0xf4>
 *   @0x105208 b 0x105294 <dsMapAddRValue+0x164>
 *   @0x10520c b 0x105224 <dsMapAddRValue+0xf4>
 *   @0x105210 b 0x105224 <dsMapAddRValue+0xf4>
 *   @0x105214 b 0x1052a4 <dsMapAddRValue+0x174>
 *   @0x105218 b 0x10521c <dsMapAddRValue+0xec>
 *   @0x10521c ldr r3, [r6]
 *   @0x105220 str r3, [sp, #0x38]
 *   @0x105224 mov r1, #0
 *   @0x105228 add r3, sp, #24
 *   @0x10522c mov r2, r1
 *   @0x105230 str r3, [sp]
 *   @0x105234 add r0, sp, #8
 *   @0x105238 mov r3, #3
 *   @0x10523c bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_>
 *   @0x105240 ldr r3, [sp, #0x44]
 *   @0x105244 sub r3, r3, #1
 *   @0x105248 bic r3, r3, #-16777216
 *   @0x10524c bic r3, r3, #3
 *   @0x105250 cmp r3, #0
 *   @0x105254 bne 0x105260 <dsMapAddRValue+0x130>
 *   @0x105258 add r0, sp, #56
 *   @0x10525c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x105260 add sp, sp, #72
 *   @0x105264 pop {r4, r5, r6, pc}
 *   @0x105268 ldr r4, [sp, #0x38]
 *   @0x10526c cmp r4, #0
 *   @0x105270 beq 0x1051b8 <dsMapAddRValue+0x88>
 *   @0x105274 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x105278 ldr r5, [r4, #0x4]
 *   @0x10527c sub r5, r5, #1
 *   @0x105280 str r5, [r4, #0x4]
 *   @0x105284 cmp r5, #0
 *   @0x105288 beq 0x105318 <dsMapAddRValue+0x1e8>
 *   @0x10528c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x105290 b 0x1051b8 <dsMapAddRValue+0x88>
 *   @0x105294 ldm r6, {r2, r3}
 *   @0x105298 str r2, [sp, #0x38]
 *   @0x10529c str r3, [sp, #0x3c]
 *   @0x1052a0 b 0x105224 <dsMapAddRValue+0xf4>
 *   @0x1052a4 ldm r6, {r0, r1}
 *   @0x1052a8 strd r0, r1, [sp, #56]
 *   @0x1052ac b 0x105224 <dsMapAddRValue+0xf4>
 *   @0x1052b0 ldr r3, [r6]
 *   @0x1052b4 cmp r3, #0
 *   @0x1052b8 ldrne r2, [r3, #0x4]
 *   @0x1052bc addne r2, r2, #1
 *   @0x1052c0 strne r2, [r3, #0x4]
 *   @0x1052c4 b 0x105220 <dsMapAddRValue+0xf0>
 *   @0x1052c8 ldr r3, [r6]
 *   @0x1052cc cmp r3, #0
 *   @0x1052d0 str r3, [sp, #0x38]
 *   @0x1052d4 beq 0x105224 <dsMapAddRValue+0xf4>
 *   @0x1052d8 ldr r1, [r3, #0x8]
 *   @0x1052dc ldr r2, [r3]
 *   @0x1052e0 cmp r1, #0
 *   @0x1052e4 add r2, r2, #1
 *   @0x1052e8 str r2, [r3]
 *   @0x1052ec addeq r2, sp, #56
 *   @0x1052f0 streq r2, [r3, #0x8]
 *   @0x1052f4 b 0x105224 <dsMapAddRValue+0xf4>
 *   @0x1052f8 ldr r3, [r6]
 *   @0x1052fc cmp r3, #0
 *   @0x105300 str r3, [sp, #0x38]
 *   @0x105304 beq 0x105224 <dsMapAddRValue+0xf4>
 *   @0x105308 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x10530c ldr r1, [r6]
 *   @0x105310 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x105314 b 0x105224 <dsMapAddRValue+0xf4>
 *   @0x105318 ldr r0, [r4]
 *   @0x10531c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x105320 str r5, [r4]
 *   @0x105324 str r5, [r4, #0x8]
 *   @0x105328 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x10532c ldr r5, [r4, #0x4]
 *   @0x105330 sub r5, r5, #1
 *   @0x105334 str r5, [r4, #0x4]
 *   @0x105338 cmp r5, #0
 *   @0x10533c beq 0x10535c <dsMapAddRValue+0x22c>
 *   @0x105340 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x105344 mov r0, r4
 *   @0x105348 bl 0x27d1d0 <_ZdlPv>
 *   @0x10534c b 0x10528c <dsMapAddRValue+0x15c>
 *   @0x105350 add r0, sp, #56
 *   @0x105354 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x105358 b 0x1051b8 <dsMapAddRValue+0x88>
 *   @0x10535c ldr r0, [r4]
 *   @0x105360 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x105364 str r5, [r4]
 *   @0x105368 str r5, [r4, #0x8]
 *   @0x10536c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x105370 ldr r5, [r4, #0x4]
 *   @0x105374 sub r5, r5, #1
 *   @0x105378 str r5, [r4, #0x4]
 *   @0x10537c cmp r5, #0
 *   @0x105380 beq 0x105394 <dsMapAddRValue+0x264>
 *   @0x105384 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x105388 mov r0, r4
 *   @0x10538c bl 0x27d1d0 <_ZdlPv>
 *   @0x105390 b 0x105340 <dsMapAddRValue+0x210>
 *   @0x105394 ldr r0, [r4]
 *   @0x105398 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x10539c str r5, [r4]
 *   @0x1053a0 str r5, [r4, #0x8]
 *   @0x1053a4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1053a8 ldr r5, [r4, #0x4]
 *   @0x1053ac sub r5, r5, #1
 *   @0x1053b0 str r5, [r4, #0x4]
 *   @0x1053b4 cmp r5, #0
 *   @0x1053b8 bne 0x1053dc <dsMapAddRValue+0x2ac>
 *   @0x1053bc ldr r0, [r4]
 *   @0x1053c0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1053c4 mov r0, r4
 *   @0x1053c8 str r5, [r4]
 *   @0x1053cc str r5, [r4, #0x8]
 *   @0x1053d0 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x1053d4 mov r0, r4
 *   @0x1053d8 bl 0x27d1d0 <_ZdlPv>
 *   @0x1053dc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1053e0 mov r0, r4
 *   @0x1053e4 bl 0x27d1d0 <_ZdlPv>
 *   @0x1053e8 b 0x105384 <dsMapAddRValue+0x254>
 *
 * ══ §23/43 CBitmap32::SaveToFile(char const*)  0x167978  size 700  175 条（0x167978..0x167c34）
 * @func 0x167978 0x167c34  size 700  175 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x167b4c→0x3eb70c, 0x167b7c→0x3eb70c, 0x167b8c→0x3eb70c, 0x167ba0→0x3eb70c, 0x167bcc→0x3eb70c, 0x167be8→0x3eb70c, 0x167bf8→0x3eb70c
 * 调用序列: png_set_longjmp_fn×4 / 0xb6904×4 / CBitmap32::GetHeight()×3 / CBitmap32::GetWidth()×2 / 0xb6844 / png_create_write_struct / png_create_info_struct / png_init_io
 * 字段偏移 top8: 0x20×10 / 0x18×8 / 0x1c×8 / 0x24×4 / 0x28×4 / 0xc×3 / 0x2c×3 / 0x4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x167978 push {r4, r5, r6, lr}
 *   @0x16797c mov r4, r1
 *   @0x167980 sub sp, sp, #48
 *   @0x167984 ldr r1, [pc, #0x278]
 *   @0x167988 str r0, [sp, #0x18]
 *   @0x16798c add r1, pc, r1
 *   @0x167990 mov r0, r4
 *   @0x167994 bl 0xb6844 <fopen@plt>
 *   @0x167998 ldr r2, [pc, #0x268]
 *   @0x16799c add r2, pc, r2
 *   @0x1679a0 str r2, [sp, #0x1c]
 *   @0x1679a4 cmp r0, #0
 *   @0x1679a8 str r0, [sp, #0x24]
 *   @0x1679ac beq 0x167b98 <_ZN9CBitmap3210SaveToFileEPKc+0x220>
 *   @0x1679b0 ldr r0, [pc, #0x254]
 *   @0x1679b4 mov r1, #0
 *   @0x1679b8 mov r2, r1
 *   @0x1679bc mov r3, r1
 *   @0x1679c0 add r0, pc, r0
 *   @0x1679c4 blx 0x2b0364 <png_create_write_struct>
 *   @0x1679c8 subs r2, r0, #0
 *   @0x1679cc str r2, [sp, #0x20]
 *   @0x1679d0 beq 0x167bcc <_ZN9CBitmap3210SaveToFileEPKc+0x254>
 *   @0x1679d4 blx 0x2a5b64 <png_create_info_struct>
 *   @0x1679d8 cmp r0, #0
 *   @0x1679dc str r0, [sp, #0x28]
 *   @0x1679e0 beq 0x167be4 <_ZN9CBitmap3210SaveToFileEPKc+0x26c>
 *   @0x1679e4 ldr r3, [pc, #0x224]
 *   @0x1679e8 mov r2, #256
 *   @0x1679ec ldr r12, [sp, #0x1c]
 *   @0x1679f0 ldr r0, [sp, #0x20]
 *   @0x1679f4 ldr r1, [r12, r3]
 *   @0x1679f8 blx 0x2a653c <png_set_longjmp_fn>
 *   @0x1679fc bl 0xb6904 <setjmp@plt>
 *   @0x167a00 cmp r0, #0
 *   @0x167a04 bne 0x167b48 <_ZN9CBitmap3210SaveToFileEPKc+0x1d0>
 *   @0x167a08 ldr r0, [sp, #0x20]
 *   @0x167a0c ldr r1, [sp, #0x24]
 *   @0x167a10 blx 0x2a5f28 <png_init_io>
 *   @0x167a14 ldr r3, [pc, #0x1f4]
 *   @0x167a18 ldr r12, [sp, #0x1c]
 *   @0x167a1c mov r2, #256
 *   @0x167a20 ldr r0, [sp, #0x20]
 *   @0x167a24 ldr r1, [r12, r3]
 *   @0x167a28 blx 0x2a653c <png_set_longjmp_fn>
 *   @0x167a2c bl 0xb6904 <setjmp@plt>
 *   @0x167a30 subs r4, r0, #0
 *   @0x167a34 bne 0x167b88 <_ZN9CBitmap3210SaveToFileEPKc+0x210>
 *   @0x167a38 ldr r0, [sp, #0x18]
 *   @0x167a3c bl 0x167960 <_ZN9CBitmap328GetWidthEv>
 *   @0x167a40 mov r5, r0
 *   @0x167a44 ldr r0, [sp, #0x18]
 *   @0x167a48 bl 0x167968 <_ZN9CBitmap329GetHeightEv>
 *   @0x167a4c mov r2, r5
 *   @0x167a50 mov r12, #6
 *   @0x167a54 str r4, [sp, #0x8]
 *   @0x167a58 str r12, [sp, #0x4]
 *   @0x167a5c mov r1, #8
 *   @0x167a60 str r4, [sp, #0xc]
 *   @0x167a64 str r1, [sp]
 *   @0x167a68 str r4, [sp, #0x10]
 *   @0x167a6c ldr r1, [sp, #0x28]
 *   @0x167a70 mov r3, r0
 *   @0x167a74 ldr r0, [sp, #0x20]
 *   @0x167a78 blx 0x2aea84 <png_set_IHDR>
 *   @0x167a7c ldr r0, [sp, #0x20]
 *   @0x167a80 ldr r1, [sp, #0x28]
 *   @0x167a84 blx 0x2afe14 <png_write_info>
 *   @0x167a88 ldr r3, [pc, #0x180]
 *   @0x167a8c ldr r12, [sp, #0x1c]
 *   @0x167a90 mov r2, #256
 *   @0x167a94 ldr r0, [sp, #0x20]
 *   @0x167a98 ldr r1, [r12, r3]
 *   @0x167a9c blx 0x2a653c <png_set_longjmp_fn>
 *   @0x167aa0 bl 0xb6904 <setjmp@plt>
 *   @0x167aa4 subs r4, r0, #0
 *   @0x167aa8 bne 0x167b78 <_ZN9CBitmap3210SaveToFileEPKc+0x200>
 *   @0x167aac ldr r0, [sp, #0x18]
 *   @0x167ab0 bl 0x167968 <_ZN9CBitmap329GetHeightEv>
 *   @0x167ab4 lsl r0, r0, #2
 *   @0x167ab8 bl 0xb6544 <malloc@plt>
 *   @0x167abc ldr r2, [sp, #0x18]
 *   @0x167ac0 ldr r5, [r2, #0x14]
 *   @0x167ac4 str r0, [sp, #0x2c]
 *   @0x167ac8 sub r6, r0, #4
 *   @0x167acc b 0x167adc <_ZN9CBitmap3210SaveToFileEPKc+0x164>
 *   @0x167ad0 str r5, [r6, #0x4]!
 *   @0x167ad4 bl 0x167960 <_ZN9CBitmap328GetWidthEv>
 *   @0x167ad8 add r5, r5, r0, lsl #2
 *   @0x167adc ldr r0, [sp, #0x18]
 *   @0x167ae0 bl 0x167968 <_ZN9CBitmap329GetHeightEv>
 *   @0x167ae4 cmp r4, r0
 *   @0x167ae8 ldr r0, [sp, #0x18]
 *   @0x167aec add r4, r4, #1
 *   @0x167af0 blt 0x167ad0 <_ZN9CBitmap3210SaveToFileEPKc+0x158>
 *   @0x167af4 ldr r0, [sp, #0x20]
 *   @0x167af8 ldr r1, [sp, #0x2c]
 *   @0x167afc blx 0x2b0510 <png_write_image>
 *   @0x167b00 ldr r3, [pc, #0x108]
 *   @0x167b04 ldr r12, [sp, #0x1c]
 *   @0x167b08 mov r2, #256
 *   @0x167b0c ldr r0, [sp, #0x20]
 *   @0x167b10 ldr r1, [r12, r3]
 *   @0x167b14 blx 0x2a653c <png_set_longjmp_fn>
 *   @0x167b18 bl 0xb6904 <setjmp@plt>
 *   @0x167b1c subs r1, r0, #0
 *   @0x167b20 bne 0x167bf4 <_ZN9CBitmap3210SaveToFileEPKc+0x27c>
 *   @0x167b24 ldr r0, [sp, #0x20]
 *   @0x167b28 blx 0x2b002c <png_write_end>
 *   @0x167b2c ldr r0, [sp, #0x2c]
 *   @0x167b30 bl 0xb655c <free@plt>
 *   @0x167b34 ldr r0, [sp, #0x24]
 *   @0x167b38 bl 0xb6850 <fclose@plt>
 *   @0x167b3c mov r0, #1
 *   @0x167b40 add sp, sp, #48
 *   @0x167b44 pop {r4, r5, r6, pc}
 *   @0x167b48 ldr r1, [pc, #0xc4]
 *   @0x167b4c ldr r3, [pc, #0xc4]
 *   @0x167b50 add r1, pc, r1
 *   @0x167b54 ldr r0, [sp, #0x1c]
 *   @0x167b58 ldr r3, [r0, r3]
 *   @0x167b5c ldr r0, [r3]
 *   @0x167b60 ldr r3, [r0]
 *   @0x167b64 ldr r3, [r3, #0xc]
 *   @0x167b68 blx r3
 *   @0x167b6c mov r0, #0
 *   @0x167b70 add sp, sp, #48
 *   @0x167b74 pop {r4, r5, r6, pc}
 *   @0x167b78 ldr r1, [pc, #0x9c]
 *   @0x167b7c ldr r3, [pc, #0x94]
 *   @0x167b80 add r1, pc, r1
 *   @0x167b84 b 0x167b54 <_ZN9CBitmap3210SaveToFileEPKc+0x1dc>
 *   @0x167b88 ldr r1, [pc, #0x90]
 *   @0x167b8c ldr r3, [pc, #0x84]
 *   @0x167b90 add r1, pc, r1
 *   @0x167b94 b 0x167b54 <_ZN9CBitmap3210SaveToFileEPKc+0x1dc>
 *   @0x167b98 ldr r12, [sp, #0x1c]
 *   @0x167b9c mov r2, r4
 *   @0x167ba0 ldr r3, [pc, #0x70]
 *   @0x167ba4 ldr r1, [pc, #0x78]
 *   @0x167ba8 ldr r3, [r12, r3]
 *   @0x167bac add r1, pc, r1
 *   @0x167bb0 ldr r0, [r3]
 *   @0x167bb4 ldr r3, [r0]
 *   @0x167bb8 ldr r3, [r3, #0xc]
 *   @0x167bbc blx r3
 *   @0x167bc0 ldr r0, [sp, #0x24]
 *   @0x167bc4 add sp, sp, #48
 *   @0x167bc8 pop {r4, r5, r6, pc}
 *   @0x167bcc ldr r3, [pc, #0x44]
 *   @0x167bd0 ldr r12, [sp, #0x1c]
 *   @0x167bd4 ldr r1, [pc, #0x4c]
 *   @0x167bd8 ldr r3, [r12, r3]
 *   @0x167bdc add r1, pc, r1
 *   @0x167be0 b 0x167b5c <_ZN9CBitmap3210SaveToFileEPKc+0x1e4>
 *   @0x167be4 ldr r1, [pc, #0x40]
 *   @0x167be8 ldr r3, [pc, #0x28]
 *   @0x167bec add r1, pc, r1
 *   @0x167bf0 b 0x167b54 <_ZN9CBitmap3210SaveToFileEPKc+0x1dc>
 *   @0x167bf4 ldr r1, [pc, #0x34]
 *   @0x167bf8 ldr r3, [pc, #0x18]
 *   @0x167bfc add r1, pc, r1
 *   @0x167c00 b 0x167b54 <_ZN9CBitmap3210SaveToFileEPKc+0x1dc>
 *   @0x167c04 ldrheq r8, [sp], -r8
 *   @0x167c08 .word 0x0028a2b4
 *   @0x167c0c andseq r2, lr, r12, ror r12
 *   @0x167c10 .word 0xffffe4ac
 *   @0x167c14 andseq r2, lr, r8, asr r11
 *   @0x167c18 .word 0xffffbac4
 *   @0x167c1c andseq r2, lr, r0, lsl #23
 *   @0x167c20 andseq r2, lr, r0, asr #22
 *   @0x167c24 andseq r2, lr, r4, asr r10
 *   @0x167c28 andseq r2, lr, r8, ror #20
 *   @0x167c2c andseq r2, lr, r12, lsl #21
 *   @0x167c30 andseq r2, lr, r4, lsr r11
 *
 * ══ §24/43 SetupGMLMappings(int)  0x1901d4  size 700  175 条（0x1901d4..0x190490）
 * @func 0x1901d4 0x190490  size 700  175 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×20 / _JNIEnv::CallStaticIntMethod(_jclass*, _jmethodID*, ...)×20
 * 字段偏移 top8: 0x18×20 / 0x298×1 / 0x294×1 / 0x20×1 / 0x24×1 / 0x28×1 / 0x2c×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1901d4 cmp r0, #63
 *   @0x1901d8 push {r4, r5, r6, r7, lr}
 *   @0x1901dc mov r4, r0
 *   @0x1901e0 sub sp, sp, #12
 *   @0x1901e4 bgt 0x190480 <_Z16SetupGMLMappingsi+0x2ac>
 *   @0x1901e8 ldr r5, [pc, #0x298]
 *   @0x1901ec bl 0x290274 <getJNIEnv>
 *   @0x1901f0 ldr r6, [pc, #0x294]
 *   @0x1901f4 movw r12, #0x8001
 *   @0x1901f8 ldr r5, [pc, r5]
 *   @0x1901fc mov r3, r4
 *   @0x190200 add r6, pc, r6
 *   @0x190204 mov r7, #84
 *   @0x190208 ldr r1, [r5]
 *   @0x19020c ldr r2, [r6, #0x18]
 *   @0x190210 str r12, [sp]
 *   @0x190214 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz>
 *   @0x190218 mla r7, r7, r4, r6
 *   @0x19021c str r0, [r7, #0x20]
 *   @0x190220 bl 0x290274 <getJNIEnv>
 *   @0x190224 ldr r1, [r5]
 *   @0x190228 movw r12, #0x8002
 *   @0x19022c ldr r2, [r6, #0x18]
 *   @0x190230 mov r3, r4
 *   @0x190234 str r12, [sp]
 *   @0x190238 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz>
 *   @0x19023c str r0, [r7, #0x24]
 *   @0x190240 bl 0x290274 <getJNIEnv>
 *   @0x190244 ldr r1, [r5]
 *   @0x190248 movw r12, #0x8003
 *   @0x19024c ldr r2, [r6, #0x18]
 *   @0x190250 mov r3, r4
 *   @0x190254 str r12, [sp]
 *   @0x190258 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz>
 *   @0x19025c str r0, [r7, #0x28]
 *   @0x190260 bl 0x290274 <getJNIEnv>
 *   @0x190264 ldr r1, [r5]
 *   @0x190268 movw r12, #0x8004
 *   @0x19026c ldr r2, [r6, #0x18]
 *   @0x190270 mov r3, r4
 *   @0x190274 str r12, [sp]
 *   @0x190278 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz>
 *   @0x19027c str r0, [r7, #0x2c]
 *   @0x190280 bl 0x290274 <getJNIEnv>
 *   @0x190284 ldr r1, [r5]
 *   @0x190288 movw r12, #0x8005
 *   @0x19028c ldr r2, [r6, #0x18]
 *   @0x190290 mov r3, r4
 *   @0x190294 str r12, [sp]
 *   @0x190298 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz>
 *   @0x19029c str r0, [r7, #0x30]
 *   @0x1902a0 bl 0x290274 <getJNIEnv>
 *   @0x1902a4 ldr r1, [r5]
 *   @0x1902a8 movw r12, #0x8006
 *   @0x1902ac ldr r2, [r6, #0x18]
 *   @0x1902b0 mov r3, r4
 *   @0x1902b4 str r12, [sp]
 *   @0x1902b8 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz>
 *   @0x1902bc str r0, [r7, #0x34]
 *   @0x1902c0 bl 0x290274 <getJNIEnv>
 *   @0x1902c4 ldr r1, [r5]
 *   @0x1902c8 movw r12, #0x8007
 *   @0x1902cc ldr r2, [r6, #0x18]
 *   @0x1902d0 mov r3, r4
 *   @0x1902d4 str r12, [sp]
 *   @0x1902d8 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz>
 *   @0x1902dc str r0, [r7, #0x38]
 *   @0x1902e0 bl 0x290274 <getJNIEnv>
 *   @0x1902e4 ldr r1, [r5]
 *   @0x1902e8 movw r12, #0x8008
 *   @0x1902ec ldr r2, [r6, #0x18]
 *   @0x1902f0 mov r3, r4
 *   @0x1902f4 str r12, [sp]
 *   @0x1902f8 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz>
 *   @0x1902fc str r0, [r7, #0x3c]
 *   @0x190300 bl 0x290274 <getJNIEnv>
 *   @0x190304 ldr r1, [r5]
 *   @0x190308 movw r12, #0x8009
 *   @0x19030c ldr r2, [r6, #0x18]
 *   @0x190310 mov r3, r4
 *   @0x190314 str r12, [sp]
 *   @0x190318 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz>
 *   @0x19031c str r0, [r7, #0x40]
 *   @0x190320 bl 0x290274 <getJNIEnv>
 *   @0x190324 ldr r1, [r5]
 *   @0x190328 movw r12, #0x800a
 *   @0x19032c ldr r2, [r6, #0x18]
 *   @0x190330 mov r3, r4
 *   @0x190334 str r12, [sp]
 *   @0x190338 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz>
 *   @0x19033c str r0, [r7, #0x44]
 *   @0x190340 bl 0x290274 <getJNIEnv>
 *   @0x190344 ldr r1, [r5]
 *   @0x190348 movw r12, #0x800b
 *   @0x19034c ldr r2, [r6, #0x18]
 *   @0x190350 mov r3, r4
 *   @0x190354 str r12, [sp]
 *   @0x190358 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz>
 *   @0x19035c str r0, [r7, #0x48]
 *   @0x190360 bl 0x290274 <getJNIEnv>
 *   @0x190364 ldr r1, [r5]
 *   @0x190368 movw r12, #0x800c
 *   @0x19036c ldr r2, [r6, #0x18]
 *   @0x190370 mov r3, r4
 *   @0x190374 str r12, [sp]
 *   @0x190378 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz>
 *   @0x19037c str r0, [r7, #0x4c]
 *   @0x190380 bl 0x290274 <getJNIEnv>
 *   @0x190384 ldr r1, [r5]
 *   @0x190388 movw r12, #0x800d
 *   @0x19038c ldr r2, [r6, #0x18]
 *   @0x190390 mov r3, r4
 *   @0x190394 str r12, [sp]
 *   @0x190398 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz>
 *   @0x19039c str r0, [r7, #0x50]
 *   @0x1903a0 bl 0x290274 <getJNIEnv>
 *   @0x1903a4 ldr r1, [r5]
 *   @0x1903a8 movw r12, #0x800e
 *   @0x1903ac ldr r2, [r6, #0x18]
 *   @0x1903b0 mov r3, r4
 *   @0x1903b4 str r12, [sp]
 *   @0x1903b8 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz>
 *   @0x1903bc str r0, [r7, #0x54]
 *   @0x1903c0 bl 0x290274 <getJNIEnv>
 *   @0x1903c4 ldr r1, [r5]
 *   @0x1903c8 movw r12, #0x800f
 *   @0x1903cc ldr r2, [r6, #0x18]
 *   @0x1903d0 mov r3, r4
 *   @0x1903d4 str r12, [sp]
 *   @0x1903d8 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz>
 *   @0x1903dc str r0, [r7, #0x58]
 *   @0x1903e0 bl 0x290274 <getJNIEnv>
 *   @0x1903e4 ldr r1, [r5]
 *   @0x1903e8 movw r12, #0x8010
 *   @0x1903ec ldr r2, [r6, #0x18]
 *   @0x1903f0 mov r3, r4
 *   @0x1903f4 str r12, [sp]
 *   @0x1903f8 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz>
 *   @0x1903fc str r0, [r7, #0x5c]
 *   @0x190400 bl 0x290274 <getJNIEnv>
 *   @0x190404 ldr r1, [r5]
 *   @0x190408 movw r12, #0x8011
 *   @0x19040c ldr r2, [r6, #0x18]
 *   @0x190410 mov r3, r4
 *   @0x190414 str r12, [sp]
 *   @0x190418 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz>
 *   @0x19041c str r0, [r7, #0x60]
 *   @0x190420 bl 0x290274 <getJNIEnv>
 *   @0x190424 ldr r1, [r5]
 *   @0x190428 movw r12, #0x8012
 *   @0x19042c ldr r2, [r6, #0x18]
 *   @0x190430 mov r3, r4
 *   @0x190434 str r12, [sp]
 *   @0x190438 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz>
 *   @0x19043c str r0, [r7, #0x64]
 *   @0x190440 bl 0x290274 <getJNIEnv>
 *   @0x190444 ldr r1, [r5]
 *   @0x190448 movw r12, #0x8013
 *   @0x19044c ldr r2, [r6, #0x18]
 *   @0x190450 mov r3, r4
 *   @0x190454 str r12, [sp]
 *   @0x190458 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz>
 *   @0x19045c str r0, [r7, #0x68]
 *   @0x190460 bl 0x290274 <getJNIEnv>
 *   @0x190464 ldr r1, [r5]
 *   @0x190468 movw r12, #0x8014
 *   @0x19046c ldr r2, [r6, #0x18]
 *   @0x190470 mov r3, r4
 *   @0x190474 str r12, [sp]
 *   @0x190478 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz>
 *   @0x19047c str r0, [r7, #0x6c]
 *   @0x190480 add sp, sp, #12
 *   @0x190484 pop {r4, r5, r6, r7, pc}
 *   @0x190488 eoreq sp, r5, r12, lsr #15
 *   @0x19048c eorseq r5, r10, r8, lsr #12
 *
 * ══ §25/43 YYGML_Variable_SetValue(int, int, int, RValue*)  0x1f476c  size 700  175 条（0x1f476c..0x1f4a28）
 * @func 0x1f476c 0x1f4a28  size 700  175 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SET_RValue(RValue*, RValue*, int)×4 / YYObjectBase::InternalGetYYVar(int)×4 / YYGML_Variable_SetValue(int, int, int, RValue*)+0x274 / YYGML_Variable_SetValue(int, int, int, RValue*)+0x18c
 * 字段偏移 top8: 0x4×8 / 0x8×8 / 0x68×4 / 0x69×3 / 0x3×2 / 0xc×2 / 0x298×1 / 0x268×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f476c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1f4770 cmn r0, #3
 *   @0x1f4774 ldr r9, [pc, #0x298]
 *   @0x1f4778 mov r5, r0
 *   @0x1f477c mov r8, r1
 *   @0x1f4780 mov r6, r2
 *   @0x1f4784 mov r7, r3
 *   @0x1f4788 add r9, pc, r9
 *   @0x1f478c beq 0x1f4900 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x194>
 *   @0x1f4790 cmp r0, #0
 *   @0x1f4794 blt 0x1f49e0 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x274>
 *   @0x1f4798 movw r3, #0x869f
 *   @0x1f479c movt r3, #0x1
 *   @0x1f47a0 cmp r0, r3
 *   @0x1f47a4 bgt 0x1f4968 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x1fc>
 *   @0x1f47a8 ldr r3, [pc, #0x268]
 *   @0x1f47ac ldr r3, [r9, r3]
 *   @0x1f47b0 ldr r3, [r3]
 *   @0x1f47b4 ldr r2, [r3, #0x4]
 *   @0x1f47b8 ldr r3, [r3]
 *   @0x1f47bc and r2, r0, r2
 *   @0x1f47c0 ldr r12, [r3, r2, lsl #3]
 *   @0x1f47c4 cmp r12, #0
 *   @0x1f47c8 bne 0x1f47dc <_Z23YYGML_Variable_SetValueiiiP6RValue+0x70>
 *   @0x1f47cc b 0x1f4864 <_Z23YYGML_Variable_SetValueiiiP6RValue+0xf8>
 *   @0x1f47d0 ldr r12, [r12, #0x4]
 *   @0x1f47d4 cmp r12, #0
 *   @0x1f47d8 beq 0x1f4864 <_Z23YYGML_Variable_SetValueiiiP6RValue+0xf8>
 *   @0x1f47dc ldr r3, [r12, #0x8]
 *   @0x1f47e0 cmp r5, r3
 *   @0x1f47e4 bne 0x1f47d0 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x64>
 *   @0x1f47e8 ldr r3, [r12, #0xc]
 *   @0x1f47ec cmp r3, #0
 *   @0x1f47f0 beq 0x1f4864 <_Z23YYGML_Variable_SetValueiiiP6RValue+0xf8>
 *   @0x1f47f4 ldr r4, [r3, #0xd0]
 *   @0x1f47f8 cmp r4, #0
 *   @0x1f47fc beq 0x1f4864 <_Z23YYGML_Variable_SetValueiiiP6RValue+0xf8>
 *   @0x1f4800 ldr r3, [r4, #0x8]
 *   @0x1f4804 cmp r3, #0
 *   @0x1f4808 beq 0x1f4864 <_Z23YYGML_Variable_SetValueiiiP6RValue+0xf8>
 *   @0x1f480c lsl r10, r8, #4
 *   @0x1f4810 b 0x1f4820 <_Z23YYGML_Variable_SetValueiiiP6RValue+0xb4>
 *   @0x1f4814 ldr r3, [r4, #0x8]
 *   @0x1f4818 cmp r3, #0
 *   @0x1f481c beq 0x1f4864 <_Z23YYGML_Variable_SetValueiiiP6RValue+0xf8>
 *   @0x1f4820 ldr r3, [r4, #0x8]
 *   @0x1f4824 ldr r4, [r4]
 *   @0x1f4828 ldrb r2, [r3, #0x68]
 *   @0x1f482c cmp r2, #0
 *   @0x1f4830 bne 0x1f485c <_Z23YYGML_Variable_SetValueiiiP6RValue+0xf0>
 *   @0x1f4834 ldrb r2, [r3, #0x69]
 *   @0x1f4838 cmp r2, #0
 *   @0x1f483c bne 0x1f485c <_Z23YYGML_Variable_SetValueiiiP6RValue+0xf0>
 *   @0x1f4840 ldr r0, [r3, #0x4]
 *   @0x1f4844 cmp r0, #0
 *   @0x1f4848 add r0, r0, r10
 *   @0x1f484c beq 0x1f49e8 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x27c>
 *   @0x1f4850 mov r1, r7
 *   @0x1f4854 mov r2, r6
 *   @0x1f4858 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i>
 *   @0x1f485c cmp r4, #0
 *   @0x1f4860 bne 0x1f4814 <_Z23YYGML_Variable_SetValueiiiP6RValue+0xa8>
 *   @0x1f4864 ldr r3, [pc, #0x1b0]
 *   @0x1f4868 ldr r9, [r9, r3]
 *   @0x1f486c ldr r3, [r9, #0x8]
 *   @0x1f4870 cmp r3, #0
 *   @0x1f4874 lslgt r10, r8, #4
 *   @0x1f4878 movgt r4, #0
 *   @0x1f487c bgt 0x1f4894 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x128>
 *   @0x1f4880 b 0x1f48f8 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x18c>
 *   @0x1f4884 ldr r3, [r9, #0x8]
 *   @0x1f4888 add r4, r4, #1
 *   @0x1f488c cmp r3, r4
 *   @0x1f4890 ble 0x1f48f8 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x18c>
 *   @0x1f4894 ldr r3, [r9]
 *   @0x1f4898 ldr r12, [r3, r4, lsl #2]
 *   @0x1f489c ldr r3, [r12, #0x7c]
 *   @0x1f48a0 cmp r5, r3
 *   @0x1f48a4 bne 0x1f4884 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x118>
 *   @0x1f48a8 ldrb r3, [r12, #0x68]
 *   @0x1f48ac cmp r3, #0
 *   @0x1f48b0 bne 0x1f4884 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x118>
 *   @0x1f48b4 ldrb r3, [r12, #0x69]
 *   @0x1f48b8 cmp r3, #0
 *   @0x1f48bc bne 0x1f4884 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x118>
 *   @0x1f48c0 ldr r0, [r12, #0x4]
 *   @0x1f48c4 cmp r0, #0
 *   @0x1f48c8 add r0, r0, r10
 *   @0x1f48cc bne 0x1f48dc <_Z23YYGML_Variable_SetValueiiiP6RValue+0x170>
 *   @0x1f48d0 mov r0, r12
 *   @0x1f48d4 mov r1, r8
 *   @0x1f48d8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x1f48dc mov r1, r7
 *   @0x1f48e0 mov r2, r6
 *   @0x1f48e4 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i>
 *   @0x1f48e8 ldr r3, [r9, #0x8]
 *   @0x1f48ec add r4, r4, #1
 *   @0x1f48f0 cmp r3, r4
 *   @0x1f48f4 bgt 0x1f4894 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x128>
 *   @0x1f48f8 mov r0, #1
 *   @0x1f48fc pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1f4900 ldr r3, [pc, #0x118]
 *   @0x1f4904 ldr r3, [r9, r3]
 *   @0x1f4908 ldr r3, [r3]
 *   @0x1f490c ldr r3, [r3, #0x80]
 *   @0x1f4910 cmp r3, #0
 *   @0x1f4914 lslne r5, r1, #4
 *   @0x1f4918 beq 0x1f48f8 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x18c>
 *   @0x1f491c ldrb r2, [r3, #0x68]
 *   @0x1f4920 ldr r4, [r3, #0x178]
 *   @0x1f4924 cmp r2, #0
 *   @0x1f4928 bne 0x1f4954 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x1e8>
 *   @0x1f492c ldrb r2, [r3, #0x69]
 *   @0x1f4930 cmp r2, #0
 *   @0x1f4934 bne 0x1f4954 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x1e8>
 *   @0x1f4938 ldr r0, [r3, #0x4]
 *   @0x1f493c cmp r0, #0
 *   @0x1f4940 add r0, r0, r5
 *   @0x1f4944 beq 0x1f49f8 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x28c>
 *   @0x1f4948 mov r1, r7
 *   @0x1f494c mov r2, r6
 *   @0x1f4950 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i>
 *   @0x1f4954 cmp r4, #0
 *   @0x1f4958 mov r3, r4
 *   @0x1f495c bne 0x1f491c <_Z23YYGML_Variable_SetValueiiiP6RValue+0x1b0>
 *   @0x1f4960 mov r0, #1
 *   @0x1f4964 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1f4968 ldr r3, [pc, #0xb4]
 *   @0x1f496c ldr r3, [r9, r3]
 *   @0x1f4970 ldr r2, [r3, #0x4]
 *   @0x1f4974 ldr r3, [r3]
 *   @0x1f4978 and r2, r0, r2
 *   @0x1f497c ldr r3, [r3, r2, lsl #3]
 *   @0x1f4980 cmp r3, #0
 *   @0x1f4984 bne 0x1f4998 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x22c>
 *   @0x1f4988 b 0x1f48f8 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x18c>
 *   @0x1f498c ldr r3, [r3, #0x4]
 *   @0x1f4990 cmp r3, #0
 *   @0x1f4994 beq 0x1f48f8 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x18c>
 *   @0x1f4998 ldr r2, [r3, #0x8]
 *   @0x1f499c cmp r5, r2
 *   @0x1f49a0 bne 0x1f498c <_Z23YYGML_Variable_SetValueiiiP6RValue+0x220>
 *   @0x1f49a4 ldr r0, [r3, #0xc]
 *   @0x1f49a8 cmp r0, #0
 *   @0x1f49ac beq 0x1f48f8 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x18c>
 *   @0x1f49b0 ldrb r3, [r0, #0x68]
 *   @0x1f49b4 cmp r3, #0
 *   @0x1f49b8 bne 0x1f48f8 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x18c>
 *   @0x1f49bc ldr r3, [r0, #0x4]
 *   @0x1f49c0 cmp r3, #0
 *   @0x1f49c4 addne r0, r3, r8, lsl #4
 *   @0x1f49c8 beq 0x1f4a08 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x29c>
 *   @0x1f49cc mov r1, r7
 *   @0x1f49d0 mov r2, r6
 *   @0x1f49d4 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i>
 *   @0x1f49d8 mov r0, #1
 *   @0x1f49dc pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1f49e0 mov r0, #0
 *   @0x1f49e4 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1f49e8 mov r0, r3
 *   @0x1f49ec mov r1, r8
 *   @0x1f49f0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x1f49f4 b 0x1f4850 <_Z23YYGML_Variable_SetValueiiiP6RValue+0xe4>
 *   @0x1f49f8 mov r0, r3
 *   @0x1f49fc mov r1, r8
 *   @0x1f4a00 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x1f4a04 b 0x1f4948 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x1dc>
 *   @0x1f4a08 mov r1, r8
 *   @0x1f4a0c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x1f4a10 b 0x1f49cc <_Z23YYGML_Variable_SetValueiiiP6RValue+0x260>
 *   @0x1f4a14 andseq sp, pc, r8, asr #9
 *   @0x1f4a18 .word 0xffffbfec
 *   @0x1f4a1c .word 0xffffbff0
 *   @0x1f4a20 .word 0xffffbcd8
 *   @0x1f4a24 .word 0xffffbff4
 *
 * ══ §26/43 AddStringToGrid(CDS_Grid*, int, int, char*)  0x2130a4  size 700  175 条（0x2130a4..0x213360）
 * @func 0x2130a4 0x213360  size 700  175 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FREE_RValue__Pre(RValue*)×3 / AddStringToGrid(CDS_Grid*, int, int, char*)+0x184×2 / LOCK_RVALUE_MUTEX()×2 / UNLOCK_RVALUE_MUTEX()×2 / YYFree(void const*)×2 / operator delete(void*)×2 / YYSetString(RValue*, char const*) / GetContextStackTop()
 * 字段偏移 top8: 0x4×18 / 0x8×15 / 0xc×7 / 0x14×4 / 0x10×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2130a4 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x2130a8 subs r5, r0, #0
 *   @0x2130ac sub sp, sp, #28
 *   @0x2130b0 mov r4, r1
 *   @0x2130b4 beq 0x213228 <_Z15AddStringToGridP8CDS_GridiiPc+0x184>
 *   @0x2130b8 cmp r3, #0
 *   @0x2130bc beq 0x213228 <_Z15AddStringToGridP8CDS_GridiiPc+0x184>
 *   @0x2130c0 cmp r1, #0
 *   @0x2130c4 blt 0x213228 <_Z15AddStringToGridP8CDS_GridiiPc+0x184>
 *   @0x2130c8 cmp r2, #0
 *   @0x2130cc blt 0x213228 <_Z15AddStringToGridP8CDS_GridiiPc+0x184>
 *   @0x2130d0 ldr r1, [r5, #0x4]
 *   @0x2130d4 cmp r4, r1
 *   @0x2130d8 bge 0x213228 <_Z15AddStringToGridP8CDS_GridiiPc+0x184>
 *   @0x2130dc ldr r1, [r5, #0x8]
 *   @0x2130e0 cmp r2, r1
 *   @0x2130e4 bge 0x213228 <_Z15AddStringToGridP8CDS_GridiiPc+0x184>
 *   @0x2130e8 add r7, sp, #8
 *   @0x2130ec mov r1, r3
 *   @0x2130f0 mov r12, #1
 *   @0x2130f4 mov r3, #0
 *   @0x2130f8 mov r0, r7
 *   @0x2130fc str r3, [sp, #0x8]
 *   @0x213100 str r3, [sp, #0xc]
 *   @0x213104 str r3, [sp, #0x10]
 *   @0x213108 str r2, [sp, #0x4]
 *   @0x21310c str r12, [sp, #0x14]
 *   @0x213110 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x213114 ldm r5, {r8, r9}
 *   @0x213118 ldr r2, [sp, #0x4]
 *   @0x21311c mla r9, r9, r2, r4
 *   @0x213120 add r6, r8, r9, lsl #4
 *   @0x213124 ldr r3, [r6, #0xc]
 *   @0x213128 sub r3, r3, #1
 *   @0x21312c bic r3, r3, #-16777216
 *   @0x213130 bic r3, r3, #3
 *   @0x213134 cmp r3, #0
 *   @0x213138 beq 0x213264 <_Z15AddStringToGridP8CDS_GridiiPc+0x1c0>
 *   @0x21313c mov r3, #0
 *   @0x213140 mov r1, #5
 *   @0x213144 str r3, [r6, #0x8]
 *   @0x213148 str r1, [r6, #0xc]
 *   @0x21314c str r3, [r8, r9, lsl #4]
 *   @0x213150 ldr r3, [r5, #0x4]
 *   @0x213154 ldr r6, [r5]
 *   @0x213158 mla r4, r3, r2, r4
 *   @0x21315c add r5, r6, r4, lsl #4
 *   @0x213160 ldr r2, [r5, #0xc]
 *   @0x213164 bic r3, r2, #-16777216
 *   @0x213168 cmp r3, #1
 *   @0x21316c beq 0x213230 <_Z15AddStringToGridP8CDS_GridiiPc+0x18c>
 *   @0x213170 cmp r3, #2
 *   @0x213174 bne 0x21319c <_Z15AddStringToGridP8CDS_GridiiPc+0xf8>
 *   @0x213178 sub r3, r2, #1
 *   @0x21317c bic r3, r3, #-16777216
 *   @0x213180 bic r3, r3, #3
 *   @0x213184 cmp r3, #0
 *   @0x213188 beq 0x213330 <_Z15AddStringToGridP8CDS_GridiiPc+0x28c>
 *   @0x21318c mov r2, #0
 *   @0x213190 mov r3, #5
 *   @0x213194 str r2, [r5, #0x8]
 *   @0x213198 str r3, [r5, #0xc]
 *   @0x21319c ldr r3, [sp, #0x14]
 *   @0x2131a0 mov r2, #0
 *   @0x2131a4 str r2, [r6, r4, lsl #4]
 *   @0x2131a8 ldr r2, [sp, #0x10]
 *   @0x2131ac str r3, [r5, #0xc]
 *   @0x2131b0 ldr r3, [sp, #0x14]
 *   @0x2131b4 str r2, [r5, #0x8]
 *   @0x2131b8 bic r2, r3, #-16777216
 *   @0x2131bc cmp r2, #14
 *   @0x2131c0 addls pc, pc, r2, lsl #2
 *   @0x2131c4 b 0x21320c <_Z15AddStringToGridP8CDS_GridiiPc+0x168>
 *   @0x2131c8 b 0x213274 <_Z15AddStringToGridP8CDS_GridiiPc+0x1d0>
 *   @0x2131cc b 0x2132dc <_Z15AddStringToGridP8CDS_GridiiPc+0x238>
 *   @0x2131d0 b 0x2132b0 <_Z15AddStringToGridP8CDS_GridiiPc+0x20c>
 *   @0x2131d4 b 0x213204 <_Z15AddStringToGridP8CDS_GridiiPc+0x160>
 *   @0x2131d8 b 0x21320c <_Z15AddStringToGridP8CDS_GridiiPc+0x168>
 *   @0x2131dc b 0x21320c <_Z15AddStringToGridP8CDS_GridiiPc+0x168>
 *   @0x2131e0 b 0x213288 <_Z15AddStringToGridP8CDS_GridiiPc+0x1e4>
 *   @0x2131e4 b 0x213204 <_Z15AddStringToGridP8CDS_GridiiPc+0x160>
 *   @0x2131e8 b 0x21320c <_Z15AddStringToGridP8CDS_GridiiPc+0x168>
 *   @0x2131ec b 0x21320c <_Z15AddStringToGridP8CDS_GridiiPc+0x168>
 *   @0x2131f0 b 0x213274 <_Z15AddStringToGridP8CDS_GridiiPc+0x1d0>
 *   @0x2131f4 b 0x21320c <_Z15AddStringToGridP8CDS_GridiiPc+0x168>
 *   @0x2131f8 b 0x21320c <_Z15AddStringToGridP8CDS_GridiiPc+0x168>
 *   @0x2131fc b 0x213274 <_Z15AddStringToGridP8CDS_GridiiPc+0x1d0>
 *   @0x213200 b 0x213204 <_Z15AddStringToGridP8CDS_GridiiPc+0x160>
 *   @0x213204 ldr r2, [sp, #0x8]
 *   @0x213208 str r2, [r6, r4, lsl #4]
 *   @0x21320c sub r3, r3, #1
 *   @0x213210 bic r3, r3, #-16777216
 *   @0x213214 bic r3, r3, #3
 *   @0x213218 cmp r3, #0
 *   @0x21321c bne 0x213228 <_Z15AddStringToGridP8CDS_GridiiPc+0x184>
 *   @0x213220 mov r0, r7
 *   @0x213224 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x213228 add sp, sp, #28
 *   @0x21322c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x213230 ldr r8, [r6, r4, lsl #4]
 *   @0x213234 cmp r8, #0
 *   @0x213238 beq 0x213258 <_Z15AddStringToGridP8CDS_GridiiPc+0x1b4>
 *   @0x21323c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x213240 ldr r9, [r8, #0x4]
 *   @0x213244 sub r9, r9, #1
 *   @0x213248 str r9, [r8, #0x4]
 *   @0x21324c cmp r9, #0
 *   @0x213250 beq 0x2132f8 <_Z15AddStringToGridP8CDS_GridiiPc+0x254>
 *   @0x213254 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x213258 mov r3, #0
 *   @0x21325c str r3, [r6, r4, lsl #4]
 *   @0x213260 b 0x21319c <_Z15AddStringToGridP8CDS_GridiiPc+0xf8>
 *   @0x213264 mov r0, r6
 *   @0x213268 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x21326c ldr r2, [sp, #0x4]
 *   @0x213270 b 0x21313c <_Z15AddStringToGridP8CDS_GridiiPc+0x98>
 *   @0x213274 ldr r1, [sp, #0x8]
 *   @0x213278 ldr r2, [sp, #0xc]
 *   @0x21327c str r1, [r6, r4, lsl #4]
 *   @0x213280 str r2, [r5, #0x4]
 *   @0x213284 b 0x21320c <_Z15AddStringToGridP8CDS_GridiiPc+0x168>
 *   @0x213288 ldr r2, [sp, #0x8]
 *   @0x21328c str r2, [r6, r4, lsl #4]
 *   @0x213290 ldr r2, [sp, #0x8]
 *   @0x213294 cmp r2, #0
 *   @0x213298 beq 0x21320c <_Z15AddStringToGridP8CDS_GridiiPc+0x168>
 *   @0x21329c bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x2132a0 ldr r1, [sp, #0x8]
 *   @0x2132a4 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x2132a8 ldr r3, [sp, #0x14]
 *   @0x2132ac b 0x21320c <_Z15AddStringToGridP8CDS_GridiiPc+0x168>
 *   @0x2132b0 ldr r2, [sp, #0x8]
 *   @0x2132b4 cmp r2, #0
 *   @0x2132b8 str r2, [r6, r4, lsl #4]
 *   @0x2132bc beq 0x21320c <_Z15AddStringToGridP8CDS_GridiiPc+0x168>
 *   @0x2132c0 ldr r0, [r2, #0x8]
 *   @0x2132c4 ldr r1, [r2]
 *   @0x2132c8 cmp r0, #0
 *   @0x2132cc streq r5, [r2, #0x8]
 *   @0x2132d0 add r1, r1, #1
 *   @0x2132d4 str r1, [r2]
 *   @0x2132d8 b 0x21320c <_Z15AddStringToGridP8CDS_GridiiPc+0x168>
 *   @0x2132dc ldr r2, [sp, #0x8]
 *   @0x2132e0 cmp r2, #0
 *   @0x2132e4 ldrne r3, [r2, #0x4]
 *   @0x2132e8 addne r3, r3, #1
 *   @0x2132ec strne r3, [r2, #0x4]
 *   @0x2132f0 ldrne r3, [sp, #0x14]
 *   @0x2132f4 b 0x213208 <_Z15AddStringToGridP8CDS_GridiiPc+0x164>
 *   @0x2132f8 ldr r0, [r8]
 *   @0x2132fc bl 0xcef90 <_Z6YYFreePKv>
 *   @0x213300 str r9, [r8]
 *   @0x213304 str r9, [r8, #0x8]
 *   @0x213308 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x21330c ldr r9, [r8, #0x4]
 *   @0x213310 sub r9, r9, #1
 *   @0x213314 str r9, [r8, #0x4]
 *   @0x213318 cmp r9, #0
 *   @0x21331c beq 0x21333c <_Z15AddStringToGridP8CDS_GridiiPc+0x298>
 *   @0x213320 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x213324 mov r0, r8
 *   @0x213328 bl 0x27d1d0 <_ZdlPv>
 *   @0x21332c b 0x213254 <_Z15AddStringToGridP8CDS_GridiiPc+0x1b0>
 *   @0x213330 mov r0, r5
 *   @0x213334 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x213338 b 0x21318c <_Z15AddStringToGridP8CDS_GridiiPc+0xe8>
 *   @0x21333c ldr r0, [r8]
 *   @0x213340 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x213344 mov r0, r8
 *   @0x213348 str r9, [r8]
 *   @0x21334c str r9, [r8, #0x8]
 *   @0x213350 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x213354 mov r0, r8
 *   @0x213358 bl 0x27d1d0 <_ZdlPv>
 *   @0x21335c b 0x213320 <_Z15AddStringToGridP8CDS_GridiiPc+0x27c>
 *
 * ══ §27/43 F_JSToObject(RValue&, CInstance*, CInstance*, int, RValue*)  0x247648  size 700  175 条（0x247648..0x247904）
 * @func 0x247648 0x247904  size 700  175 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×2 / UNLOCK_RVALUE_MUTEX()×2 / YYFree(void const*)×2 / operator delete(void*)×2 / F_JSBooleanConstruct(RValue&, CInstance*, CInstance*, int, RValue*) / JS_Number_Constructor(RValue&, CInstance*, CInstance*, int, RValue*) / JS_String(RValue&, CInstance*, CInstance*, int, RValue*) / YYError(char const*, ...)
 * 字段偏移 top8: 0xc×7 / 0x8×6 / 0x4×5 / 0x20×1 / 0x154×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x247648 push {r4, r5, r6, r7, lr}
 *   @0x24764c sub sp, sp, #12
 *   @0x247650 mov r5, r0
 *   @0x247654 ldr r4, [sp, #0x20]
 *   @0x247658 ldr r1, [r4, #0xc]
 *   @0x24765c cmp r1, #13
 *   @0x247660 addls pc, pc, r1, lsl #2
 *   @0x247664 b 0x2477a4 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x15c>
 *   @0x247668 b 0x24776c <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x24766c b 0x247788 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x247670 b 0x2477a4 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x15c>
 *   @0x247674 b 0x2477a4 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x15c>
 *   @0x247678 b 0x2477a4 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x15c>
 *   @0x24767c b 0x2476a0 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x247680 b 0x2476ac <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x247684 b 0x24776c <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x247688 b 0x2477a4 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x15c>
 *   @0x24768c b 0x2477a4 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x15c>
 *   @0x247690 b 0x2477a4 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x15c>
 *   @0x247694 b 0x2477a4 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x15c>
 *   @0x247698 b 0x2476a0 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x24769c b 0x247750 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x2476a0 mov r0, #1
 *   @0x2476a4 add sp, sp, #12
 *   @0x2476a8 pop {r4, r5, r6, r7, pc}
 *   @0x2476ac ldr r2, [r0, #0xc]
 *   @0x2476b0 bic r3, r2, #-16777216
 *   @0x2476b4 cmp r3, #1
 *   @0x2476b8 beq 0x2477d4 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x18c>
 *   @0x2476bc cmp r3, #2
 *   @0x2476c0 bne 0x2477cc <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x184>
 *   @0x2476c4 sub r3, r2, #1
 *   @0x2476c8 bic r3, r3, #-16777216
 *   @0x2476cc bic r3, r3, #3
 *   @0x2476d0 cmp r3, #0
 *   @0x2476d4 beq 0x2478a0 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x258>
 *   @0x2476d8 mov r3, #0
 *   @0x2476dc mov r2, #5
 *   @0x2476e0 str r3, [r5, #0x8]
 *   @0x2476e4 str r2, [r5, #0xc]
 *   @0x2476e8 ldr r3, [r4, #0xc]
 *   @0x2476ec ldr r2, [r4, #0x8]
 *   @0x2476f0 mov r1, #0
 *   @0x2476f4 str r3, [r5, #0xc]
 *   @0x2476f8 ldr r3, [r4, #0xc]
 *   @0x2476fc str r1, [r5]
 *   @0x247700 bic r3, r3, #-16777216
 *   @0x247704 str r2, [r5, #0x8]
 *   @0x247708 cmp r3, #14
 *   @0x24770c addls pc, pc, r3, lsl #2
 *   @0x247710 b 0x247878 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x230>
 *   @0x247714 b 0x247810 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x1c8>
 *   @0x247718 b 0x247880 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x238>
 *   @0x24771c b 0x24784c <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x204>
 *   @0x247720 b 0x2477bc <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x174>
 *   @0x247724 b 0x247878 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x230>
 *   @0x247728 b 0x247878 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x230>
 *   @0x24772c b 0x247824 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x1dc>
 *   @0x247730 b 0x2477bc <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x174>
 *   @0x247734 b 0x247878 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x230>
 *   @0x247738 b 0x247878 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x230>
 *   @0x24773c b 0x247810 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x1c8>
 *   @0x247740 b 0x247878 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x230>
 *   @0x247744 b 0x247878 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x230>
 *   @0x247748 b 0x247810 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x1c8>
 *   @0x24774c b 0x2477bc <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x174>
 *   @0x247750 mov r1, #0
 *   @0x247754 str r4, [sp]
 *   @0x247758 mov r2, r1
 *   @0x24775c bl 0x2405dc <_Z20F_JSBooleanConstructR6RValueP9CInstanceS2_iPS_>
 *   @0x247760 mov r0, #0
 *   @0x247764 add sp, sp, #12
 *   @0x247768 pop {r4, r5, r6, r7, pc}
 *   @0x24776c mov r1, #0
 *   @0x247770 str r4, [sp]
 *   @0x247774 mov r2, r1
 *   @0x247778 bl 0x24dc90 <_Z21JS_Number_ConstructorR6RValueP9CInstanceS2_iPS_>
 *   @0x24777c mov r0, #0
 *   @0x247780 add sp, sp, #12
 *   @0x247784 pop {r4, r5, r6, r7, pc}
 *   @0x247788 mov r1, #0
 *   @0x24778c str r4, [sp]
 *   @0x247790 mov r2, r1
 *   @0x247794 bl 0x2583e4 <_Z9JS_StringR6RValueP9CInstanceS2_iPS_>
 *   @0x247798 mov r0, #0
 *   @0x24779c add sp, sp, #12
 *   @0x2477a0 pop {r4, r5, r6, r7, pc}
 *   @0x2477a4 ldr r0, [pc, #0x154]
 *   @0x2477a8 add r0, pc, r0
 *   @0x2477ac bl 0xd547c <_Z7YYErrorPKcz>
 *   @0x2477b0 mov r0, #0
 *   @0x2477b4 add sp, sp, #12
 *   @0x2477b8 pop {r4, r5, r6, r7, pc}
 *   @0x2477bc ldr r3, [r4]
 *   @0x2477c0 mov r0, #0
 *   @0x2477c4 str r3, [r5]
 *   @0x2477c8 b 0x2476a4 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x2477cc mov r3, #6
 *   @0x2477d0 b 0x2476ec <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x2477d4 ldr r6, [r0]
 *   @0x2477d8 cmp r6, #0
 *   @0x2477dc moveq r3, #6
 *   @0x2477e0 beq 0x247804 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x1bc>
 *   @0x2477e4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x2477e8 ldr r7, [r6, #0x4]
 *   @0x2477ec sub r7, r7, #1
 *   @0x2477f0 str r7, [r6, #0x4]
 *   @0x2477f4 cmp r7, #0
 *   @0x2477f8 beq 0x2478a8 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x260>
 *   @0x2477fc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x247800 ldr r3, [r4, #0xc]
 *   @0x247804 mov r2, #0
 *   @0x247808 str r2, [r5]
 *   @0x24780c b 0x2476ec <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x247810 ldr r2, [r4]
 *   @0x247814 mov r0, #0
 *   @0x247818 ldr r3, [r4, #0x4]
 *   @0x24781c stm r5, {r2, r3}
 *   @0x247820 b 0x2476a4 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x247824 ldr r3, [r4]
 *   @0x247828 str r3, [r5]
 *   @0x24782c ldr r3, [r4]
 *   @0x247830 cmp r3, #0
 *   @0x247834 beq 0x247878 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x230>
 *   @0x247838 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x24783c ldr r1, [r4]
 *   @0x247840 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x247844 mov r0, #0
 *   @0x247848 b 0x2476a4 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x24784c ldr r3, [r4]
 *   @0x247850 cmp r3, #0
 *   @0x247854 str r3, [r5]
 *   @0x247858 beq 0x247878 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x230>
 *   @0x24785c ldr r0, [r3, #0x8]
 *   @0x247860 ldr r2, [r3]
 *   @0x247864 cmp r0, #0
 *   @0x247868 streq r5, [r3, #0x8]
 *   @0x24786c add r2, r2, #1
 *   @0x247870 str r2, [r3]
 *   @0x247874 beq 0x2476a4 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x247878 mov r0, #0
 *   @0x24787c b 0x2476a4 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x247880 ldr r3, [r4]
 *   @0x247884 mov r0, #0
 *   @0x247888 cmp r3, #0
 *   @0x24788c ldrne r2, [r3, #0x4]
 *   @0x247890 addne r2, r2, #1
 *   @0x247894 strne r2, [r3, #0x4]
 *   @0x247898 str r3, [r5]
 *   @0x24789c b 0x2476a4 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x2478a0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x2478a4 b 0x2476d8 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x2478a8 ldr r0, [r6]
 *   @0x2478ac bl 0xcef90 <_Z6YYFreePKv>
 *   @0x2478b0 str r7, [r6]
 *   @0x2478b4 str r7, [r6, #0x8]
 *   @0x2478b8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x2478bc ldr r7, [r6, #0x4]
 *   @0x2478c0 sub r7, r7, #1
 *   @0x2478c4 str r7, [r6, #0x4]
 *   @0x2478c8 cmp r7, #0
 *   @0x2478cc bne 0x2478f0 <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x2a8>
 *   @0x2478d0 ldr r0, [r6]
 *   @0x2478d4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x2478d8 mov r0, r6
 *   @0x2478dc str r7, [r6]
 *   @0x2478e0 str r7, [r6, #0x8]
 *   @0x2478e4 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x2478e8 mov r0, r6
 *   @0x2478ec bl 0x27d1d0 <_ZdlPv>
 *   @0x2478f0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x2478f4 mov r0, r6
 *   @0x2478f8 bl 0x27d1d0 <_ZdlPv>
 *   @0x2478fc b 0x2477fc <_Z12F_JSToObjectR6RValueP9CInstanceS2_iPS_+0x1b4>
 *   @0x247900 andseq lr, r0, r12, asr #12
 *
 * ══ §28/43 Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap  0x293d60  size 700  175 条（0x293d60..0x29401c）
 * @func 0x293d60 0x29401c  size 700  175 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CreateDsMap(int, ...)×2 / setJNIEnv / Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x258 / F_DsMapAdd_Internal(int, char*, double) / F_DsMapAdd_Internal(int, char*, char*)
 * 字段偏移 top8: 0x58×7 / 0x1c×6 / 0x4×5 / 0x8×4 / 0x10×4 / 0x24×3 / 0x2ac×3 / 0xc×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x293d60 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x293d64 sub sp, sp, #52
 *   @0x293d68 mov r11, r0
 *   @0x293d6c str r3, [sp, #0x1c]
 *   @0x293d70 str r2, [sp, #0x8]
 *   @0x293d74 bl 0x290614 <setJNIEnv>
 *   @0x293d78 ldr r3, [sp, #0x8]
 *   @0x293d7c cmp r3, #0
 *   @0x293d80 beq 0x294010 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x2b0>
 *   @0x293d84 ldr r3, [sp, #0x58]
 *   @0x293d88 cmp r3, #0
 *   @0x293d8c beq 0x293dac <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x4c>
 *   @0x293d90 ldr r3, [r11]
 *   @0x293d94 mov r0, r11
 *   @0x293d98 ldr r1, [sp, #0x58]
 *   @0x293d9c add r2, sp, #47
 *   @0x293da0 ldr r3, [r3, #0x2f8]
 *   @0x293da4 blx r3
 *   @0x293da8 str r0, [sp, #0x24]
 *   @0x293dac ldr r3, [r11]
 *   @0x293db0 mov r0, r11
 *   @0x293db4 ldr r1, [sp, #0x8]
 *   @0x293db8 ldr r3, [r3, #0x2ac]
 *   @0x293dbc blx r3
 *   @0x293dc0 ldr r3, [sp, #0x1c]
 *   @0x293dc4 cmp r3, #0
 *   @0x293dc8 str r0, [sp, #0xc]
 *   @0x293dcc beq 0x293fd0 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x270>
 *   @0x293dd0 ldr r3, [r11]
 *   @0x293dd4 mov r0, r11
 *   @0x293dd8 ldr r1, [sp, #0x1c]
 *   @0x293ddc ldr r3, [r3, #0x2ac]
 *   @0x293de0 blx r3
 *   @0x293de4 ldr r3, [sp, #0x58]
 *   @0x293de8 cmp r3, #0
 *   @0x293dec str r0, [sp, #0x14]
 *   @0x293df0 beq 0x293fe4 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x284>
 *   @0x293df4 ldr r3, [r11]
 *   @0x293df8 mov r0, r11
 *   @0x293dfc ldr r1, [sp, #0x58]
 *   @0x293e00 ldr r3, [r3, #0x2ac]
 *   @0x293e04 blx r3
 *   @0x293e08 str r0, [sp, #0x20]
 *   @0x293e0c mov r0, #0
 *   @0x293e10 bl 0x20bdc0 <_Z11CreateDsMapiz>
 *   @0x293e14 ldr r3, [sp, #0xc]
 *   @0x293e18 cmp r3, #0
 *   @0x293e1c str r0, [sp, #0x10]
 *   @0x293e20 ble 0x293fb8 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x258>
 *   @0x293e24 ldr r3, [sp, #0x1c]
 *   @0x293e28 mov r4, #0
 *   @0x293e2c ldr r8, [sp, #0x24]
 *   @0x293e30 adds r3, r3, #0
 *   @0x293e34 movne r3, #1
 *   @0x293e38 str r3, [sp, #0x18]
 *   @0x293e3c b 0x293ed4 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x174>
 *   @0x293e40 ldr r3, [r11]
 *   @0x293e44 mov r0, r11
 *   @0x293e48 mov r1, r7
 *   @0x293e4c mov r2, #0
 *   @0x293e50 ldr r3, [r3, #0x2a4]
 *   @0x293e54 blx r3
 *   @0x293e58 adds r9, r0, #0
 *   @0x293e5c mov r6, r0
 *   @0x293e60 movne r9, #1
 *   @0x293e64 ldr r5, [sp, #0x18]
 *   @0x293e68 ldr r3, [sp, #0x14]
 *   @0x293e6c cmp r4, r3
 *   @0x293e70 movge r5, #0
 *   @0x293e74 andlt r5, r5, #1
 *   @0x293e78 cmp r5, #0
 *   @0x293e7c bne 0x293f60 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x200>
 *   @0x293e80 mov r3, #0
 *   @0x293e84 str r3, [sp, #0x4]
 *   @0x293e88 ldr r3, [sp, #0x20]
 *   @0x293e8c mov r1, r6
 *   @0x293e90 ldr r0, [sp, #0x10]
 *   @0x293e94 mov r5, #0
 *   @0x293e98 cmp r3, r4
 *   @0x293e9c mov r10, r5
 *   @0x293ea0 ldrdgt r2, r3, [r8]
 *   @0x293ea4 movle r2, #0
 *   @0x293ea8 movle r3, #0
 *   @0x293eac bl 0x104d94 <_Z19F_DsMapAdd_InternaliPcd>
 *   @0x293eb0 cmp r9, #0
 *   @0x293eb4 bne 0x293f30 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x1d0>
 *   @0x293eb8 cmp r5, #0
 *   @0x293ebc bne 0x293f00 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x1a0>
 *   @0x293ec0 ldr r3, [sp, #0xc]
 *   @0x293ec4 add r4, r4, #1
 *   @0x293ec8 add r8, r8, #8
 *   @0x293ecc cmp r4, r3
 *   @0x293ed0 beq 0x293fb8 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x258>
 *   @0x293ed4 ldr r3, [r11]
 *   @0x293ed8 mov r0, r11
 *   @0x293edc ldr r1, [sp, #0x8]
 *   @0x293ee0 mov r2, r4
 *   @0x293ee4 ldr r3, [r3, #0x2b4]
 *   @0x293ee8 blx r3
 *   @0x293eec subs r7, r0, #0
 *   @0x293ef0 bne 0x293e40 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0xe0>
 *   @0x293ef4 mov r9, r7
 *   @0x293ef8 mov r6, r7
 *   @0x293efc b 0x293e64 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x104>
 *   @0x293f00 ldr lr, [r11]
 *   @0x293f04 mov r0, r11
 *   @0x293f08 ldr r1, [sp, #0x4]
 *   @0x293f0c mov r2, r10
 *   @0x293f10 ldr r3, [lr, #0x2a8]
 *   @0x293f14 blx r3
 *   @0x293f18 ldr r3, [r11]
 *   @0x293f1c ldr r1, [sp, #0x4]
 *   @0x293f20 mov r0, r11
 *   @0x293f24 ldr r3, [r3, #0x5c]
 *   @0x293f28 blx r3
 *   @0x293f2c b 0x293ec0 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x160>
 *   @0x293f30 ldr lr, [r11]
 *   @0x293f34 mov r2, r6
 *   @0x293f38 mov r0, r11
 *   @0x293f3c mov r1, r7
 *   @0x293f40 ldr r6, [lr, #0x2a8]
 *   @0x293f44 blx r6
 *   @0x293f48 ldr r2, [r11]
 *   @0x293f4c mov r1, r7
 *   @0x293f50 mov r0, r11
 *   @0x293f54 ldr r2, [r2, #0x5c]
 *   @0x293f58 blx r2
 *   @0x293f5c b 0x293eb8 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x158>
 *   @0x293f60 ldr r3, [r11]
 *   @0x293f64 mov r0, r11
 *   @0x293f68 ldr r1, [sp, #0x1c]
 *   @0x293f6c mov r2, r4
 *   @0x293f70 ldr r3, [r3, #0x2b4]
 *   @0x293f74 blx r3
 *   @0x293f78 cmp r0, #0
 *   @0x293f7c str r0, [sp, #0x4]
 *   @0x293f80 beq 0x293e80 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x120>
 *   @0x293f84 ldr r3, [r11]
 *   @0x293f88 mov r0, r11
 *   @0x293f8c ldr r1, [sp, #0x4]
 *   @0x293f90 mov r2, #0
 *   @0x293f94 ldr r3, [r3, #0x2a4]
 *   @0x293f98 blx r3
 *   @0x293f9c subs r10, r0, #0
 *   @0x293fa0 beq 0x293e88 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x128>
 *   @0x293fa4 ldr r0, [sp, #0x10]
 *   @0x293fa8 mov r1, r6
 *   @0x293fac mov r2, r10
 *   @0x293fb0 bl 0x104f64 <_Z19F_DsMapAdd_InternaliPcS_>
 *   @0x293fb4 b 0x293eb0 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x150>
 *   @0x293fb8 ldrb r3, [sp, #0x2f]
 *   @0x293fbc cmp r3, #1
 *   @0x293fc0 beq 0x293ff0 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x290>
 *   @0x293fc4 ldr r0, [sp, #0x10]
 *   @0x293fc8 add sp, sp, #52
 *   @0x293fcc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x293fd0 ldr r3, [sp, #0x1c]
 *   @0x293fd4 str r3, [sp, #0x14]
 *   @0x293fd8 ldr r3, [sp, #0x58]
 *   @0x293fdc cmp r3, #0
 *   @0x293fe0 bne 0x293df4 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x94>
 *   @0x293fe4 ldr r3, [sp, #0x58]
 *   @0x293fe8 str r3, [sp, #0x20]
 *   @0x293fec b 0x293e0c <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0xac>
 *   @0x293ff0 ldr lr, [r11]
 *   @0x293ff4 mov r0, r11
 *   @0x293ff8 ldr r1, [sp, #0x58]
 *   @0x293ffc mov r3, #2
 *   @0x294000 ldr r2, [sp, #0x24]
 *   @0x294004 ldr r12, [lr, #0x318]
 *   @0x294008 blx r12
 *   @0x29400c b 0x293fc4 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x264>
 *   @0x294010 mov r0, r3
 *   @0x294014 bl 0x20bdc0 <_Z11CreateDsMapiz>
 *   @0x294018 b 0x293fc8 <Java_com_yoyogames_runner_RunnerJNILib_jCreateDsMap+0x268>
 *
 * ══ §29/43 VM::GetRuntimeState(Buffer_Standard*, int)  0xdadc8  size 696  174 条（0xdadc8..0xdb080）
 * @func 0xdadc8 0xdb080  size 696  174 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: VM::WriteRValueToBuffer(RValue*, Buffer_Standard*)×2 / VM::GetLocalVariables(Buffer_Standard*, YYObjectBase*, bool, int) / VM::WriteCallStack(Buffer_Standard*, VMExec*, bool) / VM::GetGlobalVariables(Buffer_Standard*, bool) / Debug_WriteOutput(Buffer_Standard*) / VM::GetStructureCounts(Buffer_Standard*) / VM::GetAllInstanceIDs(Buffer_Standard*, bool) / VM::WriteRenderStates(Buffer_Standard*, bool)
 * 字段偏移 top8: 0x2c×7 / 0x30×7 / 0x38×7 / 0x8×7 / 0x14×4 / 0x18×2 / 0x2a0×1 / 0x24×1
 * VFP 指令 10 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xdadc8 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0xdadcc mov r8, r1
 *   @0xdadd0 ldr r7, [pc, #0x2a0]
 *   @0xdadd4 sub sp, sp, #20
 *   @0xdadd8 mov r6, r0
 *   @0xdaddc ldr r7, [pc, r7]
 *   @0xdade0 ldr r3, [r7]
 *   @0xdade4 cmp r3, #0
 *   @0xdade8 beq 0xdb04c <_ZN2VM15GetRuntimeStateEP15Buffer_Standardi+0x284>
 *   @0xdadec ldr r3, [r3, #0x24]
 *   @0xdadf0 add r9, r0, #44
 *   @0xdadf4 ldr r12, [r0]
 *   @0xdadf8 mov lr, #10
 *   @0xdadfc mov r2, r9
 *   @0xdae00 mov r1, #12
 *   @0xdae04 asr r5, r3, #31
 *   @0xdae08 str r3, [r0, #0x2c]
 *   @0xdae0c str r5, [r0, #0x30]
 *   @0xdae10 str lr, [r0, #0x38]
 *   @0xdae14 ldr r3, [r12, #0x8]
 *   @0xdae18 blx r3
 *   @0xdae1c ldr r1, [r7]
 *   @0xdae20 ldr r3, [r6]
 *   @0xdae24 mov r12, #0
 *   @0xdae28 mov r2, r9
 *   @0xdae2c mov r0, r6
 *   @0xdae30 ldr r4, [r1, #0x44]
 *   @0xdae34 mov r1, #5
 *   @0xdae38 str r12, [r6, #0x38]
 *   @0xdae3c vmov s15, r4
 *   @0xdae40 vcvt.f64.u32 d7, s15
 *   @0xdae44 vmov r4, r5, d7
 *   @0xdae48 vstr s14, [r6, #44]
 *   @0xdae4c str r5, [r6, #0x30]
 *   @0xdae50 ldr r3, [r3, #0x8]
 *   @0xdae54 blx r3
 *   @0xdae58 ldr r3, [pc, #0x21c]
 *   @0xdae5c ldr r3, [pc, r3]
 *   @0xdae60 ldrb r3, [r3]
 *   @0xdae64 cmp r3, #0
 *   @0xdae68 ldr r3, [r7]
 *   @0xdae6c bne 0xdafcc <_ZN2VM15GetRuntimeStateEP15Buffer_Standardi+0x204>
 *   @0xdae70 ldr r3, [r3, #0x14]
 *   @0xdae74 mov r0, r6
 *   @0xdae78 ldr r1, [r6]
 *   @0xdae7c cmp r3, #0
 *   @0xdae80 ldrne r2, [r3, #0x78]
 *   @0xdae84 moveq r2, #0
 *   @0xdae88 moveq r3, #0
 *   @0xdae8c vmovne s15, r2
 *   @0xdae90 vcvtne.f64.u32 d7, s15
 *   @0xdae94 vmovne r2, r3, d7
 *   @0xdae98 str r2, [r6, #0x2c]
 *   @0xdae9c mov r2, #0
 *   @0xdaea0 str r3, [r6, #0x30]
 *   @0xdaea4 ldr r3, [r1, #0x8]
 *   @0xdaea8 mov r1, #5
 *   @0xdaeac str r2, [r6, #0x38]
 *   @0xdaeb0 mov r2, r9
 *   @0xdaeb4 blx r3
 *   @0xdaeb8 ldr r3, [r7]
 *   @0xdaebc mov r2, #0
 *   @0xdaec0 mov r0, r6
 *   @0xdaec4 mov r1, #5
 *   @0xdaec8 ldr r3, [r3, #0x18]
 *   @0xdaecc cmp r3, #0
 *   @0xdaed0 ldrne r4, [r3, #0x78]
 *   @0xdaed4 moveq r4, #0
 *   @0xdaed8 ldr r3, [r6]
 *   @0xdaedc moveq r5, #0
 *   @0xdaee0 vmovne s15, r4
 *   @0xdaee4 vcvtne.f64.u32 d7, s15
 *   @0xdaee8 vmovne r4, r5, d7
 *   @0xdaeec str r4, [r6, #0x2c]
 *   @0xdaef0 str r5, [r6, #0x30]
 *   @0xdaef4 ldr r3, [r3, #0x8]
 *   @0xdaef8 str r2, [r6, #0x38]
 *   @0xdaefc mov r2, r9
 *   @0xdaf00 blx r3
 *   @0xdaf04 ldr r1, [r7]
 *   @0xdaf08 mov r3, #3392
 *   @0xdaf0c mov r0, r6
 *   @0xdaf10 movt r3, #0x3
 *   @0xdaf14 ubfx r2, r8, #0x4, #0x1
 *   @0xdaf18 ldr r1, [r1, #0x10]
 *   @0xdaf1c bl 0xd8f48 <_ZN2VM17GetLocalVariablesEP15Buffer_StandardP12YYObjectBasebi>
 *   @0xdaf20 tst r8, #32
 *   @0xdaf24 beq 0xdaf44 <_ZN2VM15GetRuntimeStateEP15Buffer_Standardi+0x17c>
 *   @0xdaf28 ldr r3, [r7]
 *   @0xdaf2c ldr r3, [r3, #0x14]
 *   @0xdaf30 cmp r3, #0
 *   @0xdaf34 beq 0xdaf44 <_ZN2VM15GetRuntimeStateEP15Buffer_Standardi+0x17c>
 *   @0xdaf38 ldr r3, [r3, #0x48]
 *   @0xdaf3c cmp r3, #1
 *   @0xdaf40 beq 0xdb008 <_ZN2VM15GetRuntimeStateEP15Buffer_Standardi+0x240>
 *   @0xdaf44 ldr r12, [r6]
 *   @0xdaf48 mov r3, #0
 *   @0xdaf4c mov r2, r9
 *   @0xdaf50 str r3, [r6, #0x2c]
 *   @0xdaf54 str r3, [r6, #0x30]
 *   @0xdaf58 mov r0, r6
 *   @0xdaf5c str r3, [r6, #0x38]
 *   @0xdaf60 mov r1, #5
 *   @0xdaf64 ldr r3, [r12, #0x8]
 *   @0xdaf68 blx r3
 *   @0xdaf6c ldr r1, [r7]
 *   @0xdaf70 mov r0, r6
 *   @0xdaf74 ubfx r2, r8, #0x6, #0x1
 *   @0xdaf78 bl 0xd90a8 <_ZN2VM14WriteCallStackEP15Buffer_StandardP6VMExecb>
 *   @0xdaf7c ubfx r1, r8, #0x3, #0x1
 *   @0xdaf80 mov r0, r6
 *   @0xdaf84 bl 0xd8c20 <_ZN2VM18GetGlobalVariablesEP15Buffer_Standardb>
 *   @0xdaf88 mov r0, r6
 *   @0xdaf8c bl 0x29c080 <_Z17Debug_WriteOutputP15Buffer_Standard>
 *   @0xdaf90 mov r0, r6
 *   @0xdaf94 bl 0xd890c <_ZN2VM18GetStructureCountsEP15Buffer_Standard>
 *   @0xdaf98 mov r0, r6
 *   @0xdaf9c and r1, r8, #1
 *   @0xdafa0 bl 0xd87ac <_ZN2VM17GetAllInstanceIDsEP15Buffer_Standardb>
 *   @0xdafa4 mov r0, r6
 *   @0xdafa8 ubfx r1, r8, #0x1, #0x1
 *   @0xdafac bl 0xd8664 <_ZN2VM17WriteRenderStatesEP15Buffer_Standardb>
 *   @0xdafb0 mov r0, r6
 *   @0xdafb4 ubfx r1, r8, #0x2, #0x1
 *   @0xdafb8 bl 0x29c15c <_Z21Debug_WriteSurfaceIdsP15Buffer_Standardb>
 *   @0xdafbc mov r0, r6
 *   @0xdafc0 bl 0x29c108 <_Z23Debug_WriteErrorMessageP15Buffer_Standard>
 *   @0xdafc4 add sp, sp, #20
 *   @0xdafc8 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0xdafcc ldr r3, [r3, #0x14]
 *   @0xdafd0 add r4, sp, #16
 *   @0xdafd4 mov r1, r6
 *   @0xdafd8 mov r0, sp
 *   @0xdafdc mov r2, #6
 *   @0xdafe0 str r2, [sp, #0xc]
 *   @0xdafe4 str r3, [r4, #-0x10]!
 *   @0xdafe8 bl 0xd8a88 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard>
 *   @0xdafec ldr r3, [r7]
 *   @0xdaff0 mov r0, sp
 *   @0xdaff4 mov r1, r6
 *   @0xdaff8 ldr r3, [r3, #0x18]
 *   @0xdaffc str r3, [sp]
 *   @0xdb000 bl 0xd8a88 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard>
 *   @0xdb004 b 0xdaf04 <_ZN2VM15GetRuntimeStateEP15Buffer_Standardi+0x13c>
 *   @0xdb008 ldr r12, [r6]
 *   @0xdb00c mov r1, #0
 *   @0xdb010 mov r3, r1
 *   @0xdb014 mov r2, r9
 *   @0xdb018 str r3, [r6, #0x2c]
 *   @0xdb01c movt r1, #0x3ff0
 *   @0xdb020 str r3, [r6, #0x38]
 *   @0xdb024 mov r0, r6
 *   @0xdb028 str r1, [r6, #0x30]
 *   @0xdb02c mov r1, #5
 *   @0xdb030 ldr r3, [r12, #0x8]
 *   @0xdb034 blx r3
 *   @0xdb038 ldr r3, [r7]
 *   @0xdb03c mov r0, r6
 *   @0xdb040 ldr r1, [r3, #0x14]
 *   @0xdb044 bl 0xd96f0 <_ZN2VM29WriteInstanceBuiltInVariablesEP15Buffer_StandardP9CInstance>
 *   @0xdb048 b 0xdaf6c <_ZN2VM15GetRuntimeStateEP15Buffer_Standardi+0x1a4>
 *   @0xdb04c mov r2, r0
 *   @0xdb050 mvn r3, #0
 *   @0xdb054 ldr lr, [r2], #44
 *   @0xdb058 mov r12, #10
 *   @0xdb05c str r3, [r0, #0x2c]
 *   @0xdb060 mov r1, #12
 *   @0xdb064 str r3, [r0, #0x30]
 *   @0xdb068 ldr r3, [lr, #0x8]
 *   @0xdb06c str r12, [r0, #0x38]
 *   @0xdb070 blx r3
 *   @0xdb074 b 0xdaf7c <_ZN2VM15GetRuntimeStateEP15Buffer_Standardi+0x1b4>
 *   @0xdb078 eorseq r2, r1, r12, asr #27
 *   @0xdb07c eorseq r2, r1, r12, asr sp
 *
 * ══ §30/43 F_DsPriorityFindMax(RValue&, CInstance*, CInstance*, int, RValue*)  0x102c2c  size 696  174 条（0x102c2c..0x102ee4）
 * @func 0x102c2c 0x102ee4  size 696  174 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / YYGetInt32(RValue const*, int) / F_DsPriorityFindMax(RValue&, CInstance*, CInstance*, int, RValue*)+0x108 / CDS_Priority::FindMax() / GetContextStackTop()
 * 字段偏移 top8: 0x4×9 / 0x8×8 / 0xc×5 / 0x18×1 / 0x288×1 / 0x278×1 / 0x2×1 / 0x1a4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x102c2c push {r3, r4, r5, r6, r7, lr}
 *   @0x102c30 mov r1, #0
 *   @0x102c34 mov r4, r0
 *   @0x102c38 ldr r0, [sp, #0x18]
 *   @0x102c3c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x102c40 cmp r0, #0
 *   @0x102c44 blt 0x102d34 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x102c48 ldr r3, [pc, #0x288]
 *   @0x102c4c ldr r3, [pc, r3]
 *   @0x102c50 ldr r3, [r3]
 *   @0x102c54 cmp r0, r3
 *   @0x102c58 bge 0x102d34 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x102c5c ldr r3, [pc, #0x278]
 *   @0x102c60 ldr r3, [pc, r3]
 *   @0x102c64 ldr r3, [r3, #0x4]
 *   @0x102c68 ldr r0, [r3, r0, lsl #2]
 *   @0x102c6c cmp r0, #0
 *   @0x102c70 beq 0x102d34 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x102c74 bl 0x20407c <_ZN12CDS_Priority7FindMaxEv>
 *   @0x102c78 subs r5, r0, #0
 *   @0x102c7c streq r5, [r4]
 *   @0x102c80 streq r5, [r4, #0x4]
 *   @0x102c84 moveq r3, #5
 *   @0x102c88 streq r3, [r4, #0xc]
 *   @0x102c8c popeq {r3, r4, r5, r6, r7, pc}
 *   @0x102c90 ldr r2, [r4, #0xc]
 *   @0x102c94 bic r3, r2, #-16777216
 *   @0x102c98 cmp r3, #1
 *   @0x102c9c beq 0x102d60 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x102ca0 cmp r3, #2
 *   @0x102ca4 bne 0x102ccc <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x102ca8 sub r2, r2, #1
 *   @0x102cac bic r2, r2, #-16777216
 *   @0x102cb0 bic r2, r2, #3
 *   @0x102cb4 cmp r2, #0
 *   @0x102cb8 beq 0x102e34 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x208>
 *   @0x102cbc mov r2, #0
 *   @0x102cc0 mov r3, #5
 *   @0x102cc4 str r2, [r4, #0x8]
 *   @0x102cc8 str r3, [r4, #0xc]
 *   @0x102ccc ldr r3, [r5, #0xc]
 *   @0x102cd0 mov r1, #0
 *   @0x102cd4 ldr r2, [r5, #0x8]
 *   @0x102cd8 str r1, [r4]
 *   @0x102cdc str r3, [r4, #0xc]
 *   @0x102ce0 ldr r3, [r5, #0xc]
 *   @0x102ce4 str r2, [r4, #0x8]
 *   @0x102ce8 bic r3, r3, #-16777216
 *   @0x102cec cmp r3, #14
 *   @0x102cf0 addls pc, pc, r3, lsl #2
 *   @0x102cf4 b 0x102d50 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x102cf8 b 0x102d54 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x102cfc b 0x102db8 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x18c>
 *   @0x102d00 b 0x102dd0 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x102d04 b 0x102d48 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x102d08 b 0x102d50 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x102d0c b 0x102d50 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x102d10 b 0x102d94 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x102d14 b 0x102d48 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x102d18 b 0x102d50 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x102d1c b 0x102d50 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x102d20 b 0x102d54 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x102d24 b 0x102d50 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x102d28 b 0x102d50 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x102d2c b 0x102d54 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x102d30 b 0x102d48 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x102d34 ldr r0, [pc, #0x1a4]
 *   @0x102d38 mov r1, #0
 *   @0x102d3c pop {r3, r4, r5, r6, r7, lr}
 *   @0x102d40 add r0, pc, r0
 *   @0x102d44 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x102d48 ldr r3, [r5]
 *   @0x102d4c str r3, [r4]
 *   @0x102d50 pop {r3, r4, r5, r6, r7, pc}
 *   @0x102d54 ldm r5, {r2, r3}
 *   @0x102d58 stm r4, {r2, r3}
 *   @0x102d5c pop {r3, r4, r5, r6, r7, pc}
 *   @0x102d60 ldr r6, [r4]
 *   @0x102d64 cmp r6, #0
 *   @0x102d68 beq 0x102d88 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x15c>
 *   @0x102d6c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x102d70 ldr r7, [r6, #0x4]
 *   @0x102d74 sub r7, r7, #1
 *   @0x102d78 str r7, [r6, #0x4]
 *   @0x102d7c cmp r7, #0
 *   @0x102d80 beq 0x102dfc <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x1d0>
 *   @0x102d84 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x102d88 mov r3, #0
 *   @0x102d8c str r3, [r4]
 *   @0x102d90 b 0x102ccc <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x102d94 ldr r3, [r5]
 *   @0x102d98 str r3, [r4]
 *   @0x102d9c ldr r3, [r5]
 *   @0x102da0 cmp r3, #0
 *   @0x102da4 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x102da8 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x102dac ldr r1, [r5]
 *   @0x102db0 pop {r3, r4, r5, r6, r7, lr}
 *   @0x102db4 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x102db8 ldr r3, [r5]
 *   @0x102dbc cmp r3, #0
 *   @0x102dc0 ldrne r2, [r3, #0x4]
 *   @0x102dc4 addne r2, r2, #1
 *   @0x102dc8 strne r2, [r3, #0x4]
 *   @0x102dcc b 0x102d4c <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x120>
 *   @0x102dd0 ldr r3, [r5]
 *   @0x102dd4 cmp r3, #0
 *   @0x102dd8 str r3, [r4]
 *   @0x102ddc popeq {r3, r4, r5, r6, r7, pc}
 *   @0x102de0 ldr r1, [r3, #0x8]
 *   @0x102de4 ldr r2, [r3]
 *   @0x102de8 cmp r1, #0
 *   @0x102dec streq r4, [r3, #0x8]
 *   @0x102df0 add r2, r2, #1
 *   @0x102df4 str r2, [r3]
 *   @0x102df8 pop {r3, r4, r5, r6, r7, pc}
 *   @0x102dfc ldr r0, [r6]
 *   @0x102e00 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x102e04 str r7, [r6]
 *   @0x102e08 str r7, [r6, #0x8]
 *   @0x102e0c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x102e10 ldr r7, [r6, #0x4]
 *   @0x102e14 sub r7, r7, #1
 *   @0x102e18 str r7, [r6, #0x4]
 *   @0x102e1c cmp r7, #0
 *   @0x102e20 beq 0x102e40 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x214>
 *   @0x102e24 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x102e28 mov r0, r6
 *   @0x102e2c bl 0x27d1d0 <_ZdlPv>
 *   @0x102e30 b 0x102d84 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x158>
 *   @0x102e34 mov r0, r4
 *   @0x102e38 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x102e3c b 0x102cbc <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x102e40 ldr r0, [r6]
 *   @0x102e44 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x102e48 str r7, [r6]
 *   @0x102e4c str r7, [r6, #0x8]
 *   @0x102e50 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x102e54 ldr r7, [r6, #0x4]
 *   @0x102e58 sub r7, r7, #1
 *   @0x102e5c str r7, [r6, #0x4]
 *   @0x102e60 cmp r7, #0
 *   @0x102e64 beq 0x102e78 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x24c>
 *   @0x102e68 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x102e6c mov r0, r6
 *   @0x102e70 bl 0x27d1d0 <_ZdlPv>
 *   @0x102e74 b 0x102e24 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x1f8>
 *   @0x102e78 ldr r0, [r6]
 *   @0x102e7c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x102e80 str r7, [r6]
 *   @0x102e84 str r7, [r6, #0x8]
 *   @0x102e88 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x102e8c ldr r3, [r6, #0x4]
 *   @0x102e90 sub r3, r3, #1
 *   @0x102e94 str r3, [r6, #0x4]
 *   @0x102e98 cmp r3, #0
 *   @0x102e9c beq 0x102eb0 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x284>
 *   @0x102ea0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x102ea4 mov r0, r6
 *   @0x102ea8 bl 0x27d1d0 <_ZdlPv>
 *   @0x102eac b 0x102e68 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x23c>
 *   @0x102eb0 ldr r0, [r6]
 *   @0x102eb4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x102eb8 mov r3, #0
 *   @0x102ebc mov r0, r6
 *   @0x102ec0 str r3, [r6]
 *   @0x102ec4 str r3, [r6, #0x8]
 *   @0x102ec8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x102ecc mov r0, r6
 *   @0x102ed0 bl 0x27d1d0 <_ZdlPv>
 *   @0x102ed4 b 0x102ea0 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x274>
 *   @0x102ed8 eoreq r11, lr, r8, lsr #4
 *   @0x102edc eoreq r11, lr, r8, lsl r2
 *   @0x102ee0 .word 0x00234ebc
 *
 * ══ §31/43 F_DsQueueTail(RValue&, CInstance*, CInstance*, int, RValue*)  0x105b54  size 696  174 条（0x105b54..0x105e0c）
 * @func 0x105b54 0x105e0c  size 696  174 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / YYGetInt32(RValue const*, int) / F_DsQueueTail(RValue&, CInstance*, CInstance*, int, RValue*)+0x108 / CDS_Queue::Tail() / GetContextStackTop()
 * 字段偏移 top8: 0x4×9 / 0x8×8 / 0xc×5 / 0x18×1 / 0x288×1 / 0x278×1 / 0x2×1 / 0x1a4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x105b54 push {r3, r4, r5, r6, r7, lr}
 *   @0x105b58 mov r1, #0
 *   @0x105b5c mov r4, r0
 *   @0x105b60 ldr r0, [sp, #0x18]
 *   @0x105b64 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x105b68 cmp r0, #0
 *   @0x105b6c blt 0x105c5c <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x105b70 ldr r3, [pc, #0x288]
 *   @0x105b74 ldr r3, [pc, r3]
 *   @0x105b78 ldr r3, [r3]
 *   @0x105b7c cmp r0, r3
 *   @0x105b80 bge 0x105c5c <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x105b84 ldr r3, [pc, #0x278]
 *   @0x105b88 ldr r3, [pc, r3]
 *   @0x105b8c ldr r3, [r3, #0x4]
 *   @0x105b90 ldr r0, [r3, r0, lsl #2]
 *   @0x105b94 cmp r0, #0
 *   @0x105b98 beq 0x105c5c <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x105b9c bl 0x202fc0 <_ZN9CDS_Queue4TailEv>
 *   @0x105ba0 subs r5, r0, #0
 *   @0x105ba4 streq r5, [r4]
 *   @0x105ba8 streq r5, [r4, #0x4]
 *   @0x105bac moveq r3, #5
 *   @0x105bb0 streq r3, [r4, #0xc]
 *   @0x105bb4 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x105bb8 ldr r2, [r4, #0xc]
 *   @0x105bbc bic r3, r2, #-16777216
 *   @0x105bc0 cmp r3, #1
 *   @0x105bc4 beq 0x105c88 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x105bc8 cmp r3, #2
 *   @0x105bcc bne 0x105bf4 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x105bd0 sub r2, r2, #1
 *   @0x105bd4 bic r2, r2, #-16777216
 *   @0x105bd8 bic r2, r2, #3
 *   @0x105bdc cmp r2, #0
 *   @0x105be0 beq 0x105d5c <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x208>
 *   @0x105be4 mov r2, #0
 *   @0x105be8 mov r3, #5
 *   @0x105bec str r2, [r4, #0x8]
 *   @0x105bf0 str r3, [r4, #0xc]
 *   @0x105bf4 ldr r3, [r5, #0xc]
 *   @0x105bf8 mov r1, #0
 *   @0x105bfc ldr r2, [r5, #0x8]
 *   @0x105c00 str r1, [r4]
 *   @0x105c04 str r3, [r4, #0xc]
 *   @0x105c08 ldr r3, [r5, #0xc]
 *   @0x105c0c str r2, [r4, #0x8]
 *   @0x105c10 bic r3, r3, #-16777216
 *   @0x105c14 cmp r3, #14
 *   @0x105c18 addls pc, pc, r3, lsl #2
 *   @0x105c1c b 0x105c78 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x105c20 b 0x105c7c <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x105c24 b 0x105ce0 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x18c>
 *   @0x105c28 b 0x105cf8 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x105c2c b 0x105c70 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x105c30 b 0x105c78 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x105c34 b 0x105c78 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x105c38 b 0x105cbc <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x105c3c b 0x105c70 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x105c40 b 0x105c78 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x105c44 b 0x105c78 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x105c48 b 0x105c7c <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x105c4c b 0x105c78 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x105c50 b 0x105c78 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x105c54 b 0x105c7c <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x105c58 b 0x105c70 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x105c5c ldr r0, [pc, #0x1a4]
 *   @0x105c60 mov r1, #0
 *   @0x105c64 pop {r3, r4, r5, r6, r7, lr}
 *   @0x105c68 add r0, pc, r0
 *   @0x105c6c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x105c70 ldr r3, [r5]
 *   @0x105c74 str r3, [r4]
 *   @0x105c78 pop {r3, r4, r5, r6, r7, pc}
 *   @0x105c7c ldm r5, {r2, r3}
 *   @0x105c80 stm r4, {r2, r3}
 *   @0x105c84 pop {r3, r4, r5, r6, r7, pc}
 *   @0x105c88 ldr r6, [r4]
 *   @0x105c8c cmp r6, #0
 *   @0x105c90 beq 0x105cb0 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x15c>
 *   @0x105c94 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x105c98 ldr r7, [r6, #0x4]
 *   @0x105c9c sub r7, r7, #1
 *   @0x105ca0 str r7, [r6, #0x4]
 *   @0x105ca4 cmp r7, #0
 *   @0x105ca8 beq 0x105d24 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x1d0>
 *   @0x105cac bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x105cb0 mov r3, #0
 *   @0x105cb4 str r3, [r4]
 *   @0x105cb8 b 0x105bf4 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x105cbc ldr r3, [r5]
 *   @0x105cc0 str r3, [r4]
 *   @0x105cc4 ldr r3, [r5]
 *   @0x105cc8 cmp r3, #0
 *   @0x105ccc popeq {r3, r4, r5, r6, r7, pc}
 *   @0x105cd0 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x105cd4 ldr r1, [r5]
 *   @0x105cd8 pop {r3, r4, r5, r6, r7, lr}
 *   @0x105cdc b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x105ce0 ldr r3, [r5]
 *   @0x105ce4 cmp r3, #0
 *   @0x105ce8 ldrne r2, [r3, #0x4]
 *   @0x105cec addne r2, r2, #1
 *   @0x105cf0 strne r2, [r3, #0x4]
 *   @0x105cf4 b 0x105c74 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x120>
 *   @0x105cf8 ldr r3, [r5]
 *   @0x105cfc cmp r3, #0
 *   @0x105d00 str r3, [r4]
 *   @0x105d04 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x105d08 ldr r1, [r3, #0x8]
 *   @0x105d0c ldr r2, [r3]
 *   @0x105d10 cmp r1, #0
 *   @0x105d14 streq r4, [r3, #0x8]
 *   @0x105d18 add r2, r2, #1
 *   @0x105d1c str r2, [r3]
 *   @0x105d20 pop {r3, r4, r5, r6, r7, pc}
 *   @0x105d24 ldr r0, [r6]
 *   @0x105d28 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x105d2c str r7, [r6]
 *   @0x105d30 str r7, [r6, #0x8]
 *   @0x105d34 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x105d38 ldr r7, [r6, #0x4]
 *   @0x105d3c sub r7, r7, #1
 *   @0x105d40 str r7, [r6, #0x4]
 *   @0x105d44 cmp r7, #0
 *   @0x105d48 beq 0x105d68 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x214>
 *   @0x105d4c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x105d50 mov r0, r6
 *   @0x105d54 bl 0x27d1d0 <_ZdlPv>
 *   @0x105d58 b 0x105cac <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x158>
 *   @0x105d5c mov r0, r4
 *   @0x105d60 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x105d64 b 0x105be4 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x105d68 ldr r0, [r6]
 *   @0x105d6c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x105d70 str r7, [r6]
 *   @0x105d74 str r7, [r6, #0x8]
 *   @0x105d78 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x105d7c ldr r7, [r6, #0x4]
 *   @0x105d80 sub r7, r7, #1
 *   @0x105d84 str r7, [r6, #0x4]
 *   @0x105d88 cmp r7, #0
 *   @0x105d8c beq 0x105da0 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x24c>
 *   @0x105d90 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x105d94 mov r0, r6
 *   @0x105d98 bl 0x27d1d0 <_ZdlPv>
 *   @0x105d9c b 0x105d4c <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x1f8>
 *   @0x105da0 ldr r0, [r6]
 *   @0x105da4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x105da8 str r7, [r6]
 *   @0x105dac str r7, [r6, #0x8]
 *   @0x105db0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x105db4 ldr r3, [r6, #0x4]
 *   @0x105db8 sub r3, r3, #1
 *   @0x105dbc str r3, [r6, #0x4]
 *   @0x105dc0 cmp r3, #0
 *   @0x105dc4 beq 0x105dd8 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x284>
 *   @0x105dc8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x105dcc mov r0, r6
 *   @0x105dd0 bl 0x27d1d0 <_ZdlPv>
 *   @0x105dd4 b 0x105d90 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x23c>
 *   @0x105dd8 ldr r0, [r6]
 *   @0x105ddc bl 0xcef90 <_Z6YYFreePKv>
 *   @0x105de0 mov r3, #0
 *   @0x105de4 mov r0, r6
 *   @0x105de8 str r3, [r6]
 *   @0x105dec str r3, [r6, #0x8]
 *   @0x105df0 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x105df4 mov r0, r6
 *   @0x105df8 bl 0x27d1d0 <_ZdlPv>
 *   @0x105dfc b 0x105dc8 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x274>
 *   @0x105e00 .word 0x002e82f8
 *   @0x105e04 eoreq r8, lr, r8, ror #5
 *   @0x105e08 mlaeq r3, r4, pc, r1
 *
 * ══ §32/43 F_DsQueueHead(RValue&, CInstance*, CInstance*, int, RValue*)  0x105e0c  size 696  174 条（0x105e0c..0x1060c4）
 * @func 0x105e0c 0x1060c4  size 696  174 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / YYGetInt32(RValue const*, int) / F_DsQueueHead(RValue&, CInstance*, CInstance*, int, RValue*)+0x108 / CDS_Queue::Head() / GetContextStackTop()
 * 字段偏移 top8: 0x4×9 / 0x8×8 / 0xc×5 / 0x18×1 / 0x288×1 / 0x278×1 / 0x2×1 / 0x1a4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x105e0c push {r3, r4, r5, r6, r7, lr}
 *   @0x105e10 mov r1, #0
 *   @0x105e14 mov r4, r0
 *   @0x105e18 ldr r0, [sp, #0x18]
 *   @0x105e1c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x105e20 cmp r0, #0
 *   @0x105e24 blt 0x105f14 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x105e28 ldr r3, [pc, #0x288]
 *   @0x105e2c ldr r3, [pc, r3]
 *   @0x105e30 ldr r3, [r3]
 *   @0x105e34 cmp r0, r3
 *   @0x105e38 bge 0x105f14 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x105e3c ldr r3, [pc, #0x278]
 *   @0x105e40 ldr r3, [pc, r3]
 *   @0x105e44 ldr r3, [r3, #0x4]
 *   @0x105e48 ldr r0, [r3, r0, lsl #2]
 *   @0x105e4c cmp r0, #0
 *   @0x105e50 beq 0x105f14 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x105e54 bl 0x202fa8 <_ZN9CDS_Queue4HeadEv>
 *   @0x105e58 subs r5, r0, #0
 *   @0x105e5c streq r5, [r4]
 *   @0x105e60 streq r5, [r4, #0x4]
 *   @0x105e64 moveq r3, #5
 *   @0x105e68 streq r3, [r4, #0xc]
 *   @0x105e6c popeq {r3, r4, r5, r6, r7, pc}
 *   @0x105e70 ldr r2, [r4, #0xc]
 *   @0x105e74 bic r3, r2, #-16777216
 *   @0x105e78 cmp r3, #1
 *   @0x105e7c beq 0x105f40 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x105e80 cmp r3, #2
 *   @0x105e84 bne 0x105eac <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x105e88 sub r2, r2, #1
 *   @0x105e8c bic r2, r2, #-16777216
 *   @0x105e90 bic r2, r2, #3
 *   @0x105e94 cmp r2, #0
 *   @0x105e98 beq 0x106014 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x208>
 *   @0x105e9c mov r2, #0
 *   @0x105ea0 mov r3, #5
 *   @0x105ea4 str r2, [r4, #0x8]
 *   @0x105ea8 str r3, [r4, #0xc]
 *   @0x105eac ldr r3, [r5, #0xc]
 *   @0x105eb0 mov r1, #0
 *   @0x105eb4 ldr r2, [r5, #0x8]
 *   @0x105eb8 str r1, [r4]
 *   @0x105ebc str r3, [r4, #0xc]
 *   @0x105ec0 ldr r3, [r5, #0xc]
 *   @0x105ec4 str r2, [r4, #0x8]
 *   @0x105ec8 bic r3, r3, #-16777216
 *   @0x105ecc cmp r3, #14
 *   @0x105ed0 addls pc, pc, r3, lsl #2
 *   @0x105ed4 b 0x105f30 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x105ed8 b 0x105f34 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x105edc b 0x105f98 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x18c>
 *   @0x105ee0 b 0x105fb0 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x105ee4 b 0x105f28 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x105ee8 b 0x105f30 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x105eec b 0x105f30 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x105ef0 b 0x105f74 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x105ef4 b 0x105f28 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x105ef8 b 0x105f30 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x105efc b 0x105f30 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x105f00 b 0x105f34 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x105f04 b 0x105f30 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x105f08 b 0x105f30 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x105f0c b 0x105f34 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x105f10 b 0x105f28 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x105f14 ldr r0, [pc, #0x1a4]
 *   @0x105f18 mov r1, #0
 *   @0x105f1c pop {r3, r4, r5, r6, r7, lr}
 *   @0x105f20 add r0, pc, r0
 *   @0x105f24 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x105f28 ldr r3, [r5]
 *   @0x105f2c str r3, [r4]
 *   @0x105f30 pop {r3, r4, r5, r6, r7, pc}
 *   @0x105f34 ldm r5, {r2, r3}
 *   @0x105f38 stm r4, {r2, r3}
 *   @0x105f3c pop {r3, r4, r5, r6, r7, pc}
 *   @0x105f40 ldr r6, [r4]
 *   @0x105f44 cmp r6, #0
 *   @0x105f48 beq 0x105f68 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x15c>
 *   @0x105f4c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x105f50 ldr r7, [r6, #0x4]
 *   @0x105f54 sub r7, r7, #1
 *   @0x105f58 str r7, [r6, #0x4]
 *   @0x105f5c cmp r7, #0
 *   @0x105f60 beq 0x105fdc <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x1d0>
 *   @0x105f64 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x105f68 mov r3, #0
 *   @0x105f6c str r3, [r4]
 *   @0x105f70 b 0x105eac <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x105f74 ldr r3, [r5]
 *   @0x105f78 str r3, [r4]
 *   @0x105f7c ldr r3, [r5]
 *   @0x105f80 cmp r3, #0
 *   @0x105f84 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x105f88 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x105f8c ldr r1, [r5]
 *   @0x105f90 pop {r3, r4, r5, r6, r7, lr}
 *   @0x105f94 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x105f98 ldr r3, [r5]
 *   @0x105f9c cmp r3, #0
 *   @0x105fa0 ldrne r2, [r3, #0x4]
 *   @0x105fa4 addne r2, r2, #1
 *   @0x105fa8 strne r2, [r3, #0x4]
 *   @0x105fac b 0x105f2c <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x120>
 *   @0x105fb0 ldr r3, [r5]
 *   @0x105fb4 cmp r3, #0
 *   @0x105fb8 str r3, [r4]
 *   @0x105fbc popeq {r3, r4, r5, r6, r7, pc}
 *   @0x105fc0 ldr r1, [r3, #0x8]
 *   @0x105fc4 ldr r2, [r3]
 *   @0x105fc8 cmp r1, #0
 *   @0x105fcc streq r4, [r3, #0x8]
 *   @0x105fd0 add r2, r2, #1
 *   @0x105fd4 str r2, [r3]
 *   @0x105fd8 pop {r3, r4, r5, r6, r7, pc}
 *   @0x105fdc ldr r0, [r6]
 *   @0x105fe0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x105fe4 str r7, [r6]
 *   @0x105fe8 str r7, [r6, #0x8]
 *   @0x105fec bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x105ff0 ldr r7, [r6, #0x4]
 *   @0x105ff4 sub r7, r7, #1
 *   @0x105ff8 str r7, [r6, #0x4]
 *   @0x105ffc cmp r7, #0
 *   @0x106000 beq 0x106020 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x214>
 *   @0x106004 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x106008 mov r0, r6
 *   @0x10600c bl 0x27d1d0 <_ZdlPv>
 *   @0x106010 b 0x105f64 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x158>
 *   @0x106014 mov r0, r4
 *   @0x106018 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x10601c b 0x105e9c <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x106020 ldr r0, [r6]
 *   @0x106024 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x106028 str r7, [r6]
 *   @0x10602c str r7, [r6, #0x8]
 *   @0x106030 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x106034 ldr r7, [r6, #0x4]
 *   @0x106038 sub r7, r7, #1
 *   @0x10603c str r7, [r6, #0x4]
 *   @0x106040 cmp r7, #0
 *   @0x106044 beq 0x106058 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x24c>
 *   @0x106048 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x10604c mov r0, r6
 *   @0x106050 bl 0x27d1d0 <_ZdlPv>
 *   @0x106054 b 0x106004 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x1f8>
 *   @0x106058 ldr r0, [r6]
 *   @0x10605c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x106060 str r7, [r6]
 *   @0x106064 str r7, [r6, #0x8]
 *   @0x106068 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x10606c ldr r3, [r6, #0x4]
 *   @0x106070 sub r3, r3, #1
 *   @0x106074 str r3, [r6, #0x4]
 *   @0x106078 cmp r3, #0
 *   @0x10607c beq 0x106090 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x284>
 *   @0x106080 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x106084 mov r0, r6
 *   @0x106088 bl 0x27d1d0 <_ZdlPv>
 *   @0x10608c b 0x106048 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x23c>
 *   @0x106090 ldr r0, [r6]
 *   @0x106094 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x106098 mov r3, #0
 *   @0x10609c mov r0, r6
 *   @0x1060a0 str r3, [r6]
 *   @0x1060a4 str r3, [r6, #0x8]
 *   @0x1060a8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x1060ac mov r0, r6
 *   @0x1060b0 bl 0x27d1d0 <_ZdlPv>
 *   @0x1060b4 b 0x106080 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x274>
 *   @0x1060b8 eoreq r8, lr, r0, asr #32
 *   @0x1060bc eoreq r8, lr, r0, lsr r0
 *   @0x1060c0 .word 0x00231cdc
 *
 * ══ §33/43 F_DsPriorityFindMin(RValue&, CInstance*, CInstance*, int, RValue*)  0x1060c4  size 696  174 条（0x1060c4..0x10637c）
 * @func 0x1060c4 0x10637c  size 696  174 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / YYGetInt32(RValue const*, int) / F_DsPriorityFindMin(RValue&, CInstance*, CInstance*, int, RValue*)+0x108 / CDS_Priority::FindMin() / GetContextStackTop()
 * 字段偏移 top8: 0x4×9 / 0x8×8 / 0xc×5 / 0x18×1 / 0x288×1 / 0x278×1 / 0x2×1 / 0x1a4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1060c4 push {r3, r4, r5, r6, r7, lr}
 *   @0x1060c8 mov r1, #0
 *   @0x1060cc mov r4, r0
 *   @0x1060d0 ldr r0, [sp, #0x18]
 *   @0x1060d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1060d8 cmp r0, #0
 *   @0x1060dc blt 0x1061cc <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x1060e0 ldr r3, [pc, #0x288]
 *   @0x1060e4 ldr r3, [pc, r3]
 *   @0x1060e8 ldr r3, [r3]
 *   @0x1060ec cmp r0, r3
 *   @0x1060f0 bge 0x1061cc <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x1060f4 ldr r3, [pc, #0x278]
 *   @0x1060f8 ldr r3, [pc, r3]
 *   @0x1060fc ldr r3, [r3, #0x4]
 *   @0x106100 ldr r0, [r3, r0, lsl #2]
 *   @0x106104 cmp r0, #0
 *   @0x106108 beq 0x1061cc <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x10610c bl 0x204000 <_ZN12CDS_Priority7FindMinEv>
 *   @0x106110 subs r5, r0, #0
 *   @0x106114 streq r5, [r4]
 *   @0x106118 streq r5, [r4, #0x4]
 *   @0x10611c moveq r3, #5
 *   @0x106120 streq r3, [r4, #0xc]
 *   @0x106124 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x106128 ldr r2, [r4, #0xc]
 *   @0x10612c bic r3, r2, #-16777216
 *   @0x106130 cmp r3, #1
 *   @0x106134 beq 0x1061f8 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x106138 cmp r3, #2
 *   @0x10613c bne 0x106164 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x106140 sub r2, r2, #1
 *   @0x106144 bic r2, r2, #-16777216
 *   @0x106148 bic r2, r2, #3
 *   @0x10614c cmp r2, #0
 *   @0x106150 beq 0x1062cc <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x208>
 *   @0x106154 mov r2, #0
 *   @0x106158 mov r3, #5
 *   @0x10615c str r2, [r4, #0x8]
 *   @0x106160 str r3, [r4, #0xc]
 *   @0x106164 ldr r3, [r5, #0xc]
 *   @0x106168 mov r1, #0
 *   @0x10616c ldr r2, [r5, #0x8]
 *   @0x106170 str r1, [r4]
 *   @0x106174 str r3, [r4, #0xc]
 *   @0x106178 ldr r3, [r5, #0xc]
 *   @0x10617c str r2, [r4, #0x8]
 *   @0x106180 bic r3, r3, #-16777216
 *   @0x106184 cmp r3, #14
 *   @0x106188 addls pc, pc, r3, lsl #2
 *   @0x10618c b 0x1061e8 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x106190 b 0x1061ec <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x106194 b 0x106250 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x18c>
 *   @0x106198 b 0x106268 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x10619c b 0x1061e0 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x1061a0 b 0x1061e8 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x1061a4 b 0x1061e8 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x1061a8 b 0x10622c <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x1061ac b 0x1061e0 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x1061b0 b 0x1061e8 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x1061b4 b 0x1061e8 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x1061b8 b 0x1061ec <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x1061bc b 0x1061e8 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x1061c0 b 0x1061e8 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x1061c4 b 0x1061ec <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x1061c8 b 0x1061e0 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x1061cc ldr r0, [pc, #0x1a4]
 *   @0x1061d0 mov r1, #0
 *   @0x1061d4 pop {r3, r4, r5, r6, r7, lr}
 *   @0x1061d8 add r0, pc, r0
 *   @0x1061dc b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1061e0 ldr r3, [r5]
 *   @0x1061e4 str r3, [r4]
 *   @0x1061e8 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1061ec ldm r5, {r2, r3}
 *   @0x1061f0 stm r4, {r2, r3}
 *   @0x1061f4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1061f8 ldr r6, [r4]
 *   @0x1061fc cmp r6, #0
 *   @0x106200 beq 0x106220 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x15c>
 *   @0x106204 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x106208 ldr r7, [r6, #0x4]
 *   @0x10620c sub r7, r7, #1
 *   @0x106210 str r7, [r6, #0x4]
 *   @0x106214 cmp r7, #0
 *   @0x106218 beq 0x106294 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x1d0>
 *   @0x10621c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x106220 mov r3, #0
 *   @0x106224 str r3, [r4]
 *   @0x106228 b 0x106164 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x10622c ldr r3, [r5]
 *   @0x106230 str r3, [r4]
 *   @0x106234 ldr r3, [r5]
 *   @0x106238 cmp r3, #0
 *   @0x10623c popeq {r3, r4, r5, r6, r7, pc}
 *   @0x106240 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x106244 ldr r1, [r5]
 *   @0x106248 pop {r3, r4, r5, r6, r7, lr}
 *   @0x10624c b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x106250 ldr r3, [r5]
 *   @0x106254 cmp r3, #0
 *   @0x106258 ldrne r2, [r3, #0x4]
 *   @0x10625c addne r2, r2, #1
 *   @0x106260 strne r2, [r3, #0x4]
 *   @0x106264 b 0x1061e4 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x120>
 *   @0x106268 ldr r3, [r5]
 *   @0x10626c cmp r3, #0
 *   @0x106270 str r3, [r4]
 *   @0x106274 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x106278 ldr r1, [r3, #0x8]
 *   @0x10627c ldr r2, [r3]
 *   @0x106280 cmp r1, #0
 *   @0x106284 streq r4, [r3, #0x8]
 *   @0x106288 add r2, r2, #1
 *   @0x10628c str r2, [r3]
 *   @0x106290 pop {r3, r4, r5, r6, r7, pc}
 *   @0x106294 ldr r0, [r6]
 *   @0x106298 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x10629c str r7, [r6]
 *   @0x1062a0 str r7, [r6, #0x8]
 *   @0x1062a4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1062a8 ldr r7, [r6, #0x4]
 *   @0x1062ac sub r7, r7, #1
 *   @0x1062b0 str r7, [r6, #0x4]
 *   @0x1062b4 cmp r7, #0
 *   @0x1062b8 beq 0x1062d8 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x214>
 *   @0x1062bc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1062c0 mov r0, r6
 *   @0x1062c4 bl 0x27d1d0 <_ZdlPv>
 *   @0x1062c8 b 0x10621c <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x158>
 *   @0x1062cc mov r0, r4
 *   @0x1062d0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x1062d4 b 0x106154 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x1062d8 ldr r0, [r6]
 *   @0x1062dc bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1062e0 str r7, [r6]
 *   @0x1062e4 str r7, [r6, #0x8]
 *   @0x1062e8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1062ec ldr r7, [r6, #0x4]
 *   @0x1062f0 sub r7, r7, #1
 *   @0x1062f4 str r7, [r6, #0x4]
 *   @0x1062f8 cmp r7, #0
 *   @0x1062fc beq 0x106310 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x24c>
 *   @0x106300 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x106304 mov r0, r6
 *   @0x106308 bl 0x27d1d0 <_ZdlPv>
 *   @0x10630c b 0x1062bc <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x1f8>
 *   @0x106310 ldr r0, [r6]
 *   @0x106314 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x106318 str r7, [r6]
 *   @0x10631c str r7, [r6, #0x8]
 *   @0x106320 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x106324 ldr r3, [r6, #0x4]
 *   @0x106328 sub r3, r3, #1
 *   @0x10632c str r3, [r6, #0x4]
 *   @0x106330 cmp r3, #0
 *   @0x106334 beq 0x106348 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x284>
 *   @0x106338 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x10633c mov r0, r6
 *   @0x106340 bl 0x27d1d0 <_ZdlPv>
 *   @0x106344 b 0x106300 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x23c>
 *   @0x106348 ldr r0, [r6]
 *   @0x10634c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x106350 mov r3, #0
 *   @0x106354 mov r0, r6
 *   @0x106358 str r3, [r6]
 *   @0x10635c str r3, [r6, #0x8]
 *   @0x106360 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x106364 mov r0, r6
 *   @0x106368 bl 0x27d1d0 <_ZdlPv>
 *   @0x10636c b 0x106338 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x274>
 *   @0x106370 mlaeq lr, r0, sp, r7
 *   @0x106374 eoreq r7, lr, r0, lsl #27
 *   @0x106378 eoreq r1, r3, r4, lsr #20
 *
 * ══ §34/43 F_DsStackTop(RValue&, CInstance*, CInstance*, int, RValue*)  0x10637c  size 696  174 条（0x10637c..0x106634）
 * @func 0x10637c 0x106634  size 696  174 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / YYGetInt32(RValue const*, int) / F_DsStackTop(RValue&, CInstance*, CInstance*, int, RValue*)+0x108 / CDS_Stack::Top() / GetContextStackTop()
 * 字段偏移 top8: 0x4×9 / 0x8×8 / 0xc×5 / 0x18×1 / 0x288×1 / 0x278×1 / 0x2×1 / 0x1a4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10637c push {r3, r4, r5, r6, r7, lr}
 *   @0x106380 mov r1, #0
 *   @0x106384 mov r4, r0
 *   @0x106388 ldr r0, [sp, #0x18]
 *   @0x10638c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x106390 cmp r0, #0
 *   @0x106394 blt 0x106484 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x106398 ldr r3, [pc, #0x288]
 *   @0x10639c ldr r3, [pc, r3]
 *   @0x1063a0 ldr r3, [r3]
 *   @0x1063a4 cmp r0, r3
 *   @0x1063a8 bge 0x106484 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x1063ac ldr r3, [pc, #0x278]
 *   @0x1063b0 ldr r3, [pc, r3]
 *   @0x1063b4 ldr r3, [r3, #0x4]
 *   @0x1063b8 ldr r0, [r3, r0, lsl #2]
 *   @0x1063bc cmp r0, #0
 *   @0x1063c0 beq 0x106484 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x1063c4 bl 0x202d24 <_ZN9CDS_Stack3TopEv>
 *   @0x1063c8 subs r5, r0, #0
 *   @0x1063cc streq r5, [r4]
 *   @0x1063d0 streq r5, [r4, #0x4]
 *   @0x1063d4 moveq r3, #5
 *   @0x1063d8 streq r3, [r4, #0xc]
 *   @0x1063dc popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1063e0 ldr r2, [r4, #0xc]
 *   @0x1063e4 bic r3, r2, #-16777216
 *   @0x1063e8 cmp r3, #1
 *   @0x1063ec beq 0x1064b0 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x1063f0 cmp r3, #2
 *   @0x1063f4 bne 0x10641c <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x1063f8 sub r2, r2, #1
 *   @0x1063fc bic r2, r2, #-16777216
 *   @0x106400 bic r2, r2, #3
 *   @0x106404 cmp r2, #0
 *   @0x106408 beq 0x106584 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x208>
 *   @0x10640c mov r2, #0
 *   @0x106410 mov r3, #5
 *   @0x106414 str r2, [r4, #0x8]
 *   @0x106418 str r3, [r4, #0xc]
 *   @0x10641c ldr r3, [r5, #0xc]
 *   @0x106420 mov r1, #0
 *   @0x106424 ldr r2, [r5, #0x8]
 *   @0x106428 str r1, [r4]
 *   @0x10642c str r3, [r4, #0xc]
 *   @0x106430 ldr r3, [r5, #0xc]
 *   @0x106434 str r2, [r4, #0x8]
 *   @0x106438 bic r3, r3, #-16777216
 *   @0x10643c cmp r3, #14
 *   @0x106440 addls pc, pc, r3, lsl #2
 *   @0x106444 b 0x1064a0 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x106448 b 0x1064a4 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x10644c b 0x106508 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x18c>
 *   @0x106450 b 0x106520 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x106454 b 0x106498 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x106458 b 0x1064a0 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x10645c b 0x1064a0 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x106460 b 0x1064e4 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x106464 b 0x106498 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x106468 b 0x1064a0 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x10646c b 0x1064a0 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x106470 b 0x1064a4 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x106474 b 0x1064a0 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x106478 b 0x1064a0 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x10647c b 0x1064a4 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x106480 b 0x106498 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x106484 ldr r0, [pc, #0x1a4]
 *   @0x106488 mov r1, #0
 *   @0x10648c pop {r3, r4, r5, r6, r7, lr}
 *   @0x106490 add r0, pc, r0
 *   @0x106494 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x106498 ldr r3, [r5]
 *   @0x10649c str r3, [r4]
 *   @0x1064a0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1064a4 ldm r5, {r2, r3}
 *   @0x1064a8 stm r4, {r2, r3}
 *   @0x1064ac pop {r3, r4, r5, r6, r7, pc}
 *   @0x1064b0 ldr r6, [r4]
 *   @0x1064b4 cmp r6, #0
 *   @0x1064b8 beq 0x1064d8 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x15c>
 *   @0x1064bc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1064c0 ldr r7, [r6, #0x4]
 *   @0x1064c4 sub r7, r7, #1
 *   @0x1064c8 str r7, [r6, #0x4]
 *   @0x1064cc cmp r7, #0
 *   @0x1064d0 beq 0x10654c <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x1d0>
 *   @0x1064d4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1064d8 mov r3, #0
 *   @0x1064dc str r3, [r4]
 *   @0x1064e0 b 0x10641c <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x1064e4 ldr r3, [r5]
 *   @0x1064e8 str r3, [r4]
 *   @0x1064ec ldr r3, [r5]
 *   @0x1064f0 cmp r3, #0
 *   @0x1064f4 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1064f8 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x1064fc ldr r1, [r5]
 *   @0x106500 pop {r3, r4, r5, r6, r7, lr}
 *   @0x106504 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x106508 ldr r3, [r5]
 *   @0x10650c cmp r3, #0
 *   @0x106510 ldrne r2, [r3, #0x4]
 *   @0x106514 addne r2, r2, #1
 *   @0x106518 strne r2, [r3, #0x4]
 *   @0x10651c b 0x10649c <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x120>
 *   @0x106520 ldr r3, [r5]
 *   @0x106524 cmp r3, #0
 *   @0x106528 str r3, [r4]
 *   @0x10652c popeq {r3, r4, r5, r6, r7, pc}
 *   @0x106530 ldr r1, [r3, #0x8]
 *   @0x106534 ldr r2, [r3]
 *   @0x106538 cmp r1, #0
 *   @0x10653c streq r4, [r3, #0x8]
 *   @0x106540 add r2, r2, #1
 *   @0x106544 str r2, [r3]
 *   @0x106548 pop {r3, r4, r5, r6, r7, pc}
 *   @0x10654c ldr r0, [r6]
 *   @0x106550 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x106554 str r7, [r6]
 *   @0x106558 str r7, [r6, #0x8]
 *   @0x10655c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x106560 ldr r7, [r6, #0x4]
 *   @0x106564 sub r7, r7, #1
 *   @0x106568 str r7, [r6, #0x4]
 *   @0x10656c cmp r7, #0
 *   @0x106570 beq 0x106590 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x214>
 *   @0x106574 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x106578 mov r0, r6
 *   @0x10657c bl 0x27d1d0 <_ZdlPv>
 *   @0x106580 b 0x1064d4 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x158>
 *   @0x106584 mov r0, r4
 *   @0x106588 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x10658c b 0x10640c <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x106590 ldr r0, [r6]
 *   @0x106594 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x106598 str r7, [r6]
 *   @0x10659c str r7, [r6, #0x8]
 *   @0x1065a0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1065a4 ldr r7, [r6, #0x4]
 *   @0x1065a8 sub r7, r7, #1
 *   @0x1065ac str r7, [r6, #0x4]
 *   @0x1065b0 cmp r7, #0
 *   @0x1065b4 beq 0x1065c8 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x24c>
 *   @0x1065b8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1065bc mov r0, r6
 *   @0x1065c0 bl 0x27d1d0 <_ZdlPv>
 *   @0x1065c4 b 0x106574 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x1f8>
 *   @0x1065c8 ldr r0, [r6]
 *   @0x1065cc bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1065d0 str r7, [r6]
 *   @0x1065d4 str r7, [r6, #0x8]
 *   @0x1065d8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1065dc ldr r3, [r6, #0x4]
 *   @0x1065e0 sub r3, r3, #1
 *   @0x1065e4 str r3, [r6, #0x4]
 *   @0x1065e8 cmp r3, #0
 *   @0x1065ec beq 0x106600 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x284>
 *   @0x1065f0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1065f4 mov r0, r6
 *   @0x1065f8 bl 0x27d1d0 <_ZdlPv>
 *   @0x1065fc b 0x1065b8 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x23c>
 *   @0x106600 ldr r0, [r6]
 *   @0x106604 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x106608 mov r3, #0
 *   @0x10660c mov r0, r6
 *   @0x106610 str r3, [r6]
 *   @0x106614 str r3, [r6, #0x8]
 *   @0x106618 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x10661c mov r0, r6
 *   @0x106620 bl 0x27d1d0 <_ZdlPv>
 *   @0x106624 b 0x1065f0 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x274>
 *   @0x106628 eoreq r7, lr, r0, ror #21
 *   @0x10662c .word 0x002e7ad0
 *   @0x106630 eoreq r1, r3, r12, ror #14
 *
 * ══ §35/43 F_DsStackPop(RValue&, CInstance*, CInstance*, int, RValue*)  0x106914  size 696  174 条（0x106914..0x106bcc）
 * @func 0x106914 0x106bcc  size 696  174 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / YYGetInt32(RValue const*, int) / F_DsStackPop(RValue&, CInstance*, CInstance*, int, RValue*)+0x108 / CDS_Stack::Pop() / GetContextStackTop()
 * 字段偏移 top8: 0x4×9 / 0x8×8 / 0xc×5 / 0x18×1 / 0x288×1 / 0x278×1 / 0x2×1 / 0x1a4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x106914 push {r3, r4, r5, r6, r7, lr}
 *   @0x106918 mov r1, #0
 *   @0x10691c mov r4, r0
 *   @0x106920 ldr r0, [sp, #0x18]
 *   @0x106924 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x106928 cmp r0, #0
 *   @0x10692c blt 0x106a1c <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x106930 ldr r3, [pc, #0x288]
 *   @0x106934 ldr r3, [pc, r3]
 *   @0x106938 ldr r3, [r3]
 *   @0x10693c cmp r0, r3
 *   @0x106940 bge 0x106a1c <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x106944 ldr r3, [pc, #0x278]
 *   @0x106948 ldr r3, [pc, r3]
 *   @0x10694c ldr r3, [r3, #0x4]
 *   @0x106950 ldr r0, [r3, r0, lsl #2]
 *   @0x106954 cmp r0, #0
 *   @0x106958 beq 0x106a1c <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x10695c bl 0x202d00 <_ZN9CDS_Stack3PopEv>
 *   @0x106960 subs r5, r0, #0
 *   @0x106964 streq r5, [r4]
 *   @0x106968 streq r5, [r4, #0x4]
 *   @0x10696c moveq r3, #5
 *   @0x106970 streq r3, [r4, #0xc]
 *   @0x106974 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x106978 ldr r2, [r4, #0xc]
 *   @0x10697c bic r3, r2, #-16777216
 *   @0x106980 cmp r3, #1
 *   @0x106984 beq 0x106a48 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x106988 cmp r3, #2
 *   @0x10698c bne 0x1069b4 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x106990 sub r2, r2, #1
 *   @0x106994 bic r2, r2, #-16777216
 *   @0x106998 bic r2, r2, #3
 *   @0x10699c cmp r2, #0
 *   @0x1069a0 beq 0x106b1c <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x208>
 *   @0x1069a4 mov r2, #0
 *   @0x1069a8 mov r3, #5
 *   @0x1069ac str r2, [r4, #0x8]
 *   @0x1069b0 str r3, [r4, #0xc]
 *   @0x1069b4 ldr r3, [r5, #0xc]
 *   @0x1069b8 mov r1, #0
 *   @0x1069bc ldr r2, [r5, #0x8]
 *   @0x1069c0 str r1, [r4]
 *   @0x1069c4 str r3, [r4, #0xc]
 *   @0x1069c8 ldr r3, [r5, #0xc]
 *   @0x1069cc str r2, [r4, #0x8]
 *   @0x1069d0 bic r3, r3, #-16777216
 *   @0x1069d4 cmp r3, #14
 *   @0x1069d8 addls pc, pc, r3, lsl #2
 *   @0x1069dc b 0x106a38 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x1069e0 b 0x106a3c <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x1069e4 b 0x106aa0 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x18c>
 *   @0x1069e8 b 0x106ab8 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x1069ec b 0x106a30 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x1069f0 b 0x106a38 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x1069f4 b 0x106a38 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x1069f8 b 0x106a7c <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x1069fc b 0x106a30 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x106a00 b 0x106a38 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x106a04 b 0x106a38 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x106a08 b 0x106a3c <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x106a0c b 0x106a38 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x106a10 b 0x106a38 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x106a14 b 0x106a3c <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x106a18 b 0x106a30 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x106a1c ldr r0, [pc, #0x1a4]
 *   @0x106a20 mov r1, #0
 *   @0x106a24 pop {r3, r4, r5, r6, r7, lr}
 *   @0x106a28 add r0, pc, r0
 *   @0x106a2c b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x106a30 ldr r3, [r5]
 *   @0x106a34 str r3, [r4]
 *   @0x106a38 pop {r3, r4, r5, r6, r7, pc}
 *   @0x106a3c ldm r5, {r2, r3}
 *   @0x106a40 stm r4, {r2, r3}
 *   @0x106a44 pop {r3, r4, r5, r6, r7, pc}
 *   @0x106a48 ldr r6, [r4]
 *   @0x106a4c cmp r6, #0
 *   @0x106a50 beq 0x106a70 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x15c>
 *   @0x106a54 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x106a58 ldr r7, [r6, #0x4]
 *   @0x106a5c sub r7, r7, #1
 *   @0x106a60 str r7, [r6, #0x4]
 *   @0x106a64 cmp r7, #0
 *   @0x106a68 beq 0x106ae4 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x1d0>
 *   @0x106a6c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x106a70 mov r3, #0
 *   @0x106a74 str r3, [r4]
 *   @0x106a78 b 0x1069b4 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x106a7c ldr r3, [r5]
 *   @0x106a80 str r3, [r4]
 *   @0x106a84 ldr r3, [r5]
 *   @0x106a88 cmp r3, #0
 *   @0x106a8c popeq {r3, r4, r5, r6, r7, pc}
 *   @0x106a90 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x106a94 ldr r1, [r5]
 *   @0x106a98 pop {r3, r4, r5, r6, r7, lr}
 *   @0x106a9c b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x106aa0 ldr r3, [r5]
 *   @0x106aa4 cmp r3, #0
 *   @0x106aa8 ldrne r2, [r3, #0x4]
 *   @0x106aac addne r2, r2, #1
 *   @0x106ab0 strne r2, [r3, #0x4]
 *   @0x106ab4 b 0x106a34 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x120>
 *   @0x106ab8 ldr r3, [r5]
 *   @0x106abc cmp r3, #0
 *   @0x106ac0 str r3, [r4]
 *   @0x106ac4 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x106ac8 ldr r1, [r3, #0x8]
 *   @0x106acc ldr r2, [r3]
 *   @0x106ad0 cmp r1, #0
 *   @0x106ad4 streq r4, [r3, #0x8]
 *   @0x106ad8 add r2, r2, #1
 *   @0x106adc str r2, [r3]
 *   @0x106ae0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x106ae4 ldr r0, [r6]
 *   @0x106ae8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x106aec str r7, [r6]
 *   @0x106af0 str r7, [r6, #0x8]
 *   @0x106af4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x106af8 ldr r7, [r6, #0x4]
 *   @0x106afc sub r7, r7, #1
 *   @0x106b00 str r7, [r6, #0x4]
 *   @0x106b04 cmp r7, #0
 *   @0x106b08 beq 0x106b28 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x214>
 *   @0x106b0c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x106b10 mov r0, r6
 *   @0x106b14 bl 0x27d1d0 <_ZdlPv>
 *   @0x106b18 b 0x106a6c <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x158>
 *   @0x106b1c mov r0, r4
 *   @0x106b20 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x106b24 b 0x1069a4 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x106b28 ldr r0, [r6]
 *   @0x106b2c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x106b30 str r7, [r6]
 *   @0x106b34 str r7, [r6, #0x8]
 *   @0x106b38 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x106b3c ldr r7, [r6, #0x4]
 *   @0x106b40 sub r7, r7, #1
 *   @0x106b44 str r7, [r6, #0x4]
 *   @0x106b48 cmp r7, #0
 *   @0x106b4c beq 0x106b60 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x24c>
 *   @0x106b50 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x106b54 mov r0, r6
 *   @0x106b58 bl 0x27d1d0 <_ZdlPv>
 *   @0x106b5c b 0x106b0c <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x1f8>
 *   @0x106b60 ldr r0, [r6]
 *   @0x106b64 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x106b68 str r7, [r6]
 *   @0x106b6c str r7, [r6, #0x8]
 *   @0x106b70 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x106b74 ldr r3, [r6, #0x4]
 *   @0x106b78 sub r3, r3, #1
 *   @0x106b7c str r3, [r6, #0x4]
 *   @0x106b80 cmp r3, #0
 *   @0x106b84 beq 0x106b98 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x284>
 *   @0x106b88 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x106b8c mov r0, r6
 *   @0x106b90 bl 0x27d1d0 <_ZdlPv>
 *   @0x106b94 b 0x106b50 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x23c>
 *   @0x106b98 ldr r0, [r6]
 *   @0x106b9c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x106ba0 mov r3, #0
 *   @0x106ba4 mov r0, r6
 *   @0x106ba8 str r3, [r6]
 *   @0x106bac str r3, [r6, #0x8]
 *   @0x106bb0 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x106bb4 mov r0, r6
 *   @0x106bb8 bl 0x27d1d0 <_ZdlPv>
 *   @0x106bbc b 0x106b88 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x274>
 *   @0x106bc0 eoreq r7, lr, r8, asr #10
 *   @0x106bc4 eoreq r7, lr, r8, lsr r5
 *   @0x106bc8 .word 0x002311d4
 *
 * ══ §36/43 GR_3D_Draw_Cone(float, float, float, float, float, float, int, float, float, bool, int)  0x179094  size 696  174 条（0x179094..0x17934c）
 * @func 0x179094 0x17934c  size 696  174 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3D_Vertex_N_Texture(float, float, float, float, float, float, float, float)×4 / Graphics::Flush()×2 / 0xb658c×2 / 0xb6580×2 / GR_3D_Primitive_Begin(int, int)×2 / GR_3D_Primitive_End()×2 / GR_D3D_Get_Texture_Repeat() / GR_D3D_Set_Texture_Repeat(bool)
 * 字段偏移 top8: 0x4×4 / 0x14×3 / 0x1c×2 / 0x18×2 / 0x8×2 / 0xc×2 / 0x480×1 / 0x-384×1
 * VFP 指令 67 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x179094 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x179098 vpush {d8, d9, d10, d11, d12}
 *   @0x17909c sub sp, sp, #1056
 *   @0x1790a0 sub sp, sp, #12
 *   @0x1790a4 mov r8, r2
 *   @0x1790a8 add r2, sp, #2048
 *   @0x1790ac vldr s25, [r2, #-904]
 *   @0x1790b0 add r2, sp, #2048
 *   @0x1790b4 vmov s21, r3
 *   @0x1790b8 vldr s22, [r2, #-892]
 *   @0x1790bc ldr r3, [sp, #0x480]
 *   @0x1790c0 ldr r9, [r2, #-0x384]
 *   @0x1790c4 vmov s24, r1
 *   @0x1790c8 ldrb r2, [sp, #0x48c]
 *   @0x1790cc vmov s18, r0
 *   @0x1790d0 ldr r4, [sp, #0x490]
 *   @0x1790d4 str r3, [sp, #0x14]
 *   @0x1790d8 add r3, sp, #2048
 *   @0x1790dc str r2, [sp, #0x1c]
 *   @0x1790e0 vldr s23, [r3, #-888]
 *   @0x1790e4 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x1790e8 bl 0x1689e0 <_Z25GR_D3D_Get_Texture_Repeatv>
 *   @0x1790ec str r0, [sp, #0x18]
 *   @0x1790f0 mov r0, #1
 *   @0x1790f4 bl 0x168870 <_Z25GR_D3D_Set_Texture_Repeatb>
 *   @0x1790f8 cmp r4, #2
 *   @0x1790fc ble 0x179264 <_Z15GR_3D_Draw_Coneffffffiffbi+0x1d0>
 *   @0x179100 cmp r4, #128
 *   @0x179104 ble 0x179328 <_Z15GR_3D_Draw_Coneffffffiffbi+0x294>
 *   @0x179108 mov r10, #1065353216
 *   @0x17910c mov r4, #128
 *   @0x179110 mov r0, #0
 *   @0x179114 vldr s20, [pc, #548]
 *   @0x179118 add r2, sp, #548
 *   @0x17911c add r11, sp, #32
 *   @0x179120 str r2, [sp, #0x10]
 *   @0x179124 mov r5, #0
 *   @0x179128 mov r7, r2
 *   @0x17912c vldr s17, [pc, #528]
 *   @0x179130 mov r6, r11
 *   @0x179134 b 0x179160 <_Z15GR_3D_Draw_Coneffffffiffbi+0xcc>
 *   @0x179138 vmov s13, r5
 *   @0x17913c vcvt.f32.s32 s16, s13
 *   @0x179140 vadd.f32 s16, s16, s16
 *   @0x179144 vmul.f32 s16, s16, s17
 *   @0x179148 vdiv.f32 s16, s16, s20
 *   @0x17914c vmov r0, s16
 *   @0x179150 bl 0xb658c <cosf@plt>
 *   @0x179154 mov r10, r0
 *   @0x179158 vmov r0, s16
 *   @0x17915c bl 0xb6580 <sinf@plt>
 *   @0x179160 add r5, r5, #1
 *   @0x179164 str r10, [r6], #4
 *   @0x179168 cmp r4, r5
 *   @0x17916c str r0, [r7], #4
 *   @0x179170 bge 0x179138 <_Z15GR_3D_Draw_Coneffffffiffbi+0xa4>
 *   @0x179174 vmov.f32 s15, #5.000000e-01
 *   @0x179178 mov r0, #5
 *   @0x17917c ldr r1, [sp, #0x14]
 *   @0x179180 add r7, sp, #548
 *   @0x179184 mov r6, r11
 *   @0x179188 mov r10, #0
 *   @0x17918c vldr s16, [pc, #436]
 *   @0x179190 vadd.f32 s14, s25, s24
 *   @0x179194 vadd.f32 s19, s21, s18
 *   @0x179198 vsub.f32 s24, s25, s24
 *   @0x17919c vsub.f32 s21, s21, s18
 *   @0x1791a0 vmul.f32 s19, s19, s15
 *   @0x1791a4 vmul.f32 s21, s21, s15
 *   @0x1791a8 vmul.f32 s18, s14, s15
 *   @0x1791ac vmul.f32 s24, s24, s15
 *   @0x1791b0 bl 0x1769dc <_Z21GR_3D_Primitive_Beginii>
 *   @0x1791b4 vmov.f32 s25, #1.000000e+00
 *   @0x1791b8 vmov s14, r10
 *   @0x1791bc mov r5, #0
 *   @0x1791c0 vmov r0, s19
 *   @0x1791c4 mov r3, r5
 *   @0x1791c8 vmov r1, s18
 *   @0x1791cc mov r2, r9
 *   @0x1791d0 vstr s16, [sp]
 *   @0x1791d4 vstr s25, [sp, #4]
 *   @0x1791d8 vstr s23, [sp, #12]
 *   @0x1791dc add r10, r10, #1
 *   @0x1791e0 vcvt.f32.s32 s17, s14
 *   @0x1791e4 vmul.f32 s17, s17, s22
 *   @0x1791e8 vdiv.f32 s17, s17, s20
 *   @0x1791ec vstr s17, [sp, #8]
 *   @0x1791f0 bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff>
 *   @0x1791f4 vmov.f32 s13, s19
 *   @0x1791f8 vstr s17, [sp, #8]
 *   @0x1791fc vstr s16, [sp, #4]
 *   @0x179200 vstr s16, [sp, #12]
 *   @0x179204 vldmia r6!, {s14}
 *   @0x179208 vmov r3, s14
 *   @0x17920c vldmia r7!, {s15}
 *   @0x179210 vmla.f32 s13, s14, s21
 *   @0x179214 vstr s15, [sp]
 *   @0x179218 mov r2, r8
 *   @0x17921c vmov.f32 s14, s18
 *   @0x179220 vmov r0, s13
 *   @0x179224 vmla.f32 s14, s15, s24
 *   @0x179228 vmov r1, s14
 *   @0x17922c bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff>
 *   @0x179230 cmp r4, r10
 *   @0x179234 bge 0x1791b8 <_Z15GR_3D_Draw_Coneffffffiffbi+0x124>
 *   @0x179238 bl 0x176ad0 <_Z19GR_3D_Primitive_Endv>
 *   @0x17923c ldr r2, [sp, #0x1c]
 *   @0x179240 cmp r2, #0
 *   @0x179244 bne 0x179288 <_Z15GR_3D_Draw_Coneffffffiffbi+0x1f4>
 *   @0x179248 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x17924c ldr r0, [sp, #0x18]
 *   @0x179250 add sp, sp, #1056
 *   @0x179254 add sp, sp, #12
 *   @0x179258 vpop {d8, d9, d10, d11, d12}
 *   @0x17925c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x179260 b 0x168870 <_Z25GR_D3D_Set_Texture_Repeatb>
 *   @0x179264 vmov.f32 s20, #3.000000e+00
 *   @0x179268 mov r4, #3
 *   @0x17926c mov r5, #0
 *   @0x179270 mov r0, r5
 *   @0x179274 bl 0xb658c <cosf@plt>
 *   @0x179278 mov r10, r0
 *   @0x17927c mov r0, r5
 *   @0x179280 bl 0xb6580 <sinf@plt>
 *   @0x179284 b 0x179118 <_Z15GR_3D_Draw_Coneffffffiffbi+0x84>
 *   @0x179288 ldr r1, [sp, #0x14]
 *   @0x17928c mov r0, #6
 *   @0x179290 bl 0x1769dc <_Z21GR_3D_Primitive_Beginii>
 *   @0x179294 mov r7, #0
 *   @0x179298 mov r3, r5
 *   @0x17929c movt r7, #0xbf80
 *   @0x1792a0 str r5, [sp]
 *   @0x1792a4 mov r2, r8
 *   @0x1792a8 str r5, [sp, #0x8]
 *   @0x1792ac mov r6, r5
 *   @0x1792b0 str r5, [sp, #0xc]
 *   @0x1792b4 mov r5, r7
 *   @0x1792b8 vmov r0, s19
 *   @0x1792bc vmov r1, s18
 *   @0x1792c0 str r7, [sp, #0x4]
 *   @0x1792c4 bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff>
 *   @0x1792c8 add r3, r4, #1
 *   @0x1792cc add r2, sp, #548
 *   @0x1792d0 lsl r3, r3, #2
 *   @0x1792d4 add r11, r11, r3
 *   @0x1792d8 add r10, r2, r3
 *   @0x1792dc vmov.f32 s13, s19
 *   @0x1792e0 str r6, [sp]
 *   @0x1792e4 str r5, [sp, #0x4]
 *   @0x1792e8 mov r3, #0
 *   @0x1792ec str r6, [sp, #0x8]
 *   @0x1792f0 mov r2, r8
 *   @0x1792f4 str r6, [sp, #0xc]
 *   @0x1792f8 vldmdb r10!, {s15}
 *   @0x1792fc vldmdb r11!, {s14}
 *   @0x179300 vmla.f32 s13, s21, s14
 *   @0x179304 vmov.f32 s14, s18
 *   @0x179308 vmov r0, s13
 *   @0x17930c vmla.f32 s14, s24, s15
 *   @0x179310 vmov r1, s14
 *   @0x179314 bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff>
 *   @0x179318 subs r4, r4, #1
 *   @0x17931c bpl 0x1792dc <_Z15GR_3D_Draw_Coneffffffiffbi+0x248>
 *   @0x179320 bl 0x176ad0 <_Z19GR_3D_Primitive_Endv>
 *   @0x179324 b 0x179248 <_Z15GR_3D_Draw_Coneffffffiffbi+0x1b4>
 *   @0x179328 vmov s13, r4
 *   @0x17932c vldr s15, [pc, #20]
 *   @0x179330 vcvt.f32.s32 s20, s13
 *   @0x179334 vdiv.f32 s15, s15, s20
 *   @0x179338 vmov r5, s15
 *   @0x17933c b 0x179270 <_Z15GR_3D_Draw_Coneffffffiffbi+0x1dc>
 *   @0x179340 movwmi r0, #0x0
 *   @0x179344 ldrdmi r0, r1, [r9], #-251
 *   @0x179348 andeq r0, r0, r0
 *
 * ══ §37/43 TimeLine_Add()  0x1f2cfc  size 696  174 条（0x1f2cfc..0x1f2fb4）
 * @func 0x1f2cfc 0x1f2fb4  size 696  174 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×3 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)×2 / 0xb6550 / YYStrDup(char const*) / TimeLine_Add()+0xb4 / MemoryManager::IsAllocated(void const*) / TimeLine_Add()+0x78 / operator new(unsigned int)
 * 字段偏移 top8: 0x4×17 / 0x2×5 / 0xc×3 / 0x8×3 / 0x94×2 / 0x-4×2 / 0x28c×1 / 0x288×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f2cfc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1f2d00 sub sp, sp, #156
 *   @0x1f2d04 ldr r5, [pc, #0x28c]
 *   @0x1f2d08 add r4, sp, #20
 *   @0x1f2d0c ldr r6, [pc, #0x288]
 *   @0x1f2d10 add r5, pc, r5
 *   @0x1f2d14 ldr r1, [pc, #0x284]
 *   @0x1f2d18 ldr r6, [pc, r6]
 *   @0x1f2d1c mov r0, r4
 *   @0x1f2d20 ldr r2, [r5]
 *   @0x1f2d24 add r1, pc, r1
 *   @0x1f2d28 ldr r3, [r6]
 *   @0x1f2d2c ldr r7, [r2]
 *   @0x1f2d30 str r3, [sp, #0x94]
 *   @0x1f2d34 mov r2, r7
 *   @0x1f2d38 bl 0xb6550 <sprintf@plt>
 *   @0x1f2d3c mov r0, r4
 *   @0x1f2d40 ldr r5, [r5, #0x4]
 *   @0x1f2d44 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1f2d48 ldr r4, [r5]
 *   @0x1f2d4c adds r10, r4, #1
 *   @0x1f2d50 str r0, [sp, #0xc]
 *   @0x1f2d54 ldr r0, [r5, #0x4]
 *   @0x1f2d58 bne 0x1f2f34 <_Z12TimeLine_Addv+0x238>
 *   @0x1f2d5c cmp r0, #0
 *   @0x1f2d60 beq 0x1f2db0 <_Z12TimeLine_Addv+0xb4>
 *   @0x1f2d64 cmp r4, #0
 *   @0x1f2d68 ble 0x1f2db0 <_Z12TimeLine_Addv+0xb4>
 *   @0x1f2d6c mov r9, r10
 *   @0x1f2d70 mov r11, r10
 *   @0x1f2d74 ldr r0, [r0, r9, lsl #2]
 *   @0x1f2d78 lsl r8, r9, #2
 *   @0x1f2d7c bl 0x27c454 <_ZN13MemoryManager11IsAllocatedEPKv>
 *   @0x1f2d80 cmp r0, #0
 *   @0x1f2d84 beq 0x1f2d94 <_Z12TimeLine_Addv+0x98>
 *   @0x1f2d88 ldr r2, [r5, #0x4]
 *   @0x1f2d8c ldr r0, [r2, r9, lsl #2]
 *   @0x1f2d90 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f2d94 ldr r1, [r5]
 *   @0x1f2d98 add r9, r9, #1
 *   @0x1f2d9c ldr r2, [r5, #0x4]
 *   @0x1f2da0 cmp r9, r1
 *   @0x1f2da4 str r11, [r2, r8]
 *   @0x1f2da8 ldr r0, [r5, #0x4]
 *   @0x1f2dac blt 0x1f2d74 <_Z12TimeLine_Addv+0x78>
 *   @0x1f2db0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f2db4 mov r3, #0
 *   @0x1f2db8 mov r1, r3
 *   @0x1f2dbc str r3, [r5, #0x4]
 *   @0x1f2dc0 cmp r7, r4
 *   @0x1f2dc4 str r10, [r5]
 *   @0x1f2dc8 bge 0x1f2df0 <_Z12TimeLine_Addv+0xf4>
 *   @0x1f2dcc lsl r3, r4, #2
 *   @0x1f2dd0 add r2, r1, r3
 *   @0x1f2dd4 sub r4, r4, #1
 *   @0x1f2dd8 cmp r4, r7
 *   @0x1f2ddc ldr r2, [r2, #-0x4]
 *   @0x1f2de0 str r2, [r1, r3]
 *   @0x1f2de4 sub r3, r3, #4
 *   @0x1f2de8 ldr r1, [r5, #0x4]
 *   @0x1f2dec bne 0x1f2dd0 <_Z12TimeLine_Addv+0xd4>
 *   @0x1f2df0 ldr r2, [sp, #0xc]
 *   @0x1f2df4 mov r0, #24
 *   @0x1f2df8 ldr r3, [pc, #0x1a4]
 *   @0x1f2dfc mov r9, #0
 *   @0x1f2e00 add r3, pc, r3
 *   @0x1f2e04 str r2, [r1, r7, lsl #2]
 *   @0x1f2e08 ldr r5, [r3]
 *   @0x1f2e0c bl 0x27c524 <_Znwj>
 *   @0x1f2e10 ldr r3, [pc, #0x190]
 *   @0x1f2e14 ldr r3, [pc, r3]
 *   @0x1f2e18 add r3, r3, #8
 *   @0x1f2e1c str r9, [r0, #0x8]
 *   @0x1f2e20 mov r8, r0
 *   @0x1f2e24 str r9, [r0, #0xc]
 *   @0x1f2e28 str r9, [r0, #0x10]
 *   @0x1f2e2c str r3, [r0]
 *   @0x1f2e30 str r9, [r0, #0x14]
 *   @0x1f2e34 bl 0x1f1768 <_ZN9CTimeLine5ClearEv>
 *   @0x1f2e38 ldr r4, [r5]
 *   @0x1f2e3c str r8, [r8, #0x4]
 *   @0x1f2e40 adds r10, r4, #1
 *   @0x1f2e44 mov r1, r4
 *   @0x1f2e48 bne 0x1f2f60 <_Z12TimeLine_Addv+0x264>
 *   @0x1f2e4c ldr r3, [r5, #0x4]
 *   @0x1f2e50 cmp r3, r9
 *   @0x1f2e54 beq 0x1f2ed0 <_Z12TimeLine_Addv+0x1d4>
 *   @0x1f2e58 cmp r4, r9
 *   @0x1f2e5c ble 0x1f2ed0 <_Z12TimeLine_Addv+0x1d4>
 *   @0x1f2e60 mov r9, r10
 *   @0x1f2e64 mov r11, r10
 *   @0x1f2e68 ldr r0, [r3]
 *   @0x1f2e6c movw r2, #0xfeee
 *   @0x1f2e70 movt r2, #0xfeee
 *   @0x1f2e74 cmp r0, r2
 *   @0x1f2e78 beq 0x1f2ec4 <_Z12TimeLine_Addv+0x1c8>
 *   @0x1f2e7c ldr r0, [r3, r9, lsl #2]
 *   @0x1f2e80 lsl r2, r9, #2
 *   @0x1f2e84 add r12, r3, r2
 *   @0x1f2e88 cmp r0, #0
 *   @0x1f2e8c beq 0x1f2ec4 <_Z12TimeLine_Addv+0x1c8>
 *   @0x1f2e90 ldr lr, [r0]
 *   @0x1f2e94 movw r3, #0xfeee
 *   @0x1f2e98 movt r3, #0xfeee
 *   @0x1f2e9c cmp lr, r3
 *   @0x1f2ea0 beq 0x1f2ebc <_Z12TimeLine_Addv+0x1c0>
 *   @0x1f2ea4 ldr r3, [lr, #0x4]
 *   @0x1f2ea8 str r2, [sp, #0x8]
 *   @0x1f2eac blx r3
 *   @0x1f2eb0 ldm r5, {r1, r12}
 *   @0x1f2eb4 ldr r2, [sp, #0x8]
 *   @0x1f2eb8 add r12, r12, r2
 *   @0x1f2ebc str r11, [r12]
 *   @0x1f2ec0 ldr r3, [r5, #0x4]
 *   @0x1f2ec4 add r9, r9, #1
 *   @0x1f2ec8 cmp r9, r1
 *   @0x1f2ecc blt 0x1f2e68 <_Z12TimeLine_Addv+0x16c>
 *   @0x1f2ed0 mov r0, r3
 *   @0x1f2ed4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f2ed8 mov r3, #0
 *   @0x1f2edc mov r1, r3
 *   @0x1f2ee0 str r3, [r5, #0x4]
 *   @0x1f2ee4 cmp r7, r4
 *   @0x1f2ee8 str r10, [r5]
 *   @0x1f2eec bge 0x1f2f14 <_Z12TimeLine_Addv+0x218>
 *   @0x1f2ef0 lsl r3, r4, #2
 *   @0x1f2ef4 add r2, r1, r3
 *   @0x1f2ef8 sub r4, r4, #1
 *   @0x1f2efc cmp r4, r7
 *   @0x1f2f00 ldr r2, [r2, #-0x4]
 *   @0x1f2f04 str r2, [r1, r3]
 *   @0x1f2f08 sub r3, r3, #4
 *   @0x1f2f0c ldr r1, [r5, #0x4]
 *   @0x1f2f10 bne 0x1f2ef4 <_Z12TimeLine_Addv+0x1f8>
 *   @0x1f2f14 ldr r2, [sp, #0x94]
 *   @0x1f2f18 mov r0, r7
 *   @0x1f2f1c str r8, [r1, r7, lsl #2]
 *   @0x1f2f20 ldr r3, [r6]
 *   @0x1f2f24 cmp r2, r3
 *   @0x1f2f28 bne 0x1f2f94 <_Z12TimeLine_Addv+0x298>
 *   @0x1f2f2c add sp, sp, #156
 *   @0x1f2f30 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1f2f34 lsls r1, r10, #2
 *   @0x1f2f38 beq 0x1f2db0 <_Z12TimeLine_Addv+0xb4>
 *   @0x1f2f3c ldr r2, [pc, #0x68]
 *   @0x1f2f40 mov r3, #0
 *   @0x1f2f44 str r3, [sp]
 *   @0x1f2f48 mov r3, #92
 *   @0x1f2f4c add r2, pc, r2
 *   @0x1f2f50 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x1f2f54 mov r1, r0
 *   @0x1f2f58 str r0, [r5, #0x4]
 *   @0x1f2f5c b 0x1f2dc0 <_Z12TimeLine_Addv+0xc4>
 *   @0x1f2f60 lsls r1, r10, #2
 *   @0x1f2f64 beq 0x1f2f8c <_Z12TimeLine_Addv+0x290>
 *   @0x1f2f68 ldr r2, [pc, #0x40]
 *   @0x1f2f6c mov r3, #135
 *   @0x1f2f70 ldr r0, [r5, #0x4]
 *   @0x1f2f74 add r2, pc, r2
 *   @0x1f2f78 str r9, [sp]
 *   @0x1f2f7c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x1f2f80 mov r1, r0
 *   @0x1f2f84 str r0, [r5, #0x4]
 *   @0x1f2f88 b 0x1f2ee4 <_Z12TimeLine_Addv+0x1e8>
 *   @0x1f2f8c ldr r3, [r5, #0x4]
 *   @0x1f2f90 b 0x1f2ed0 <_Z12TimeLine_Addv+0x1d4>
 *   @0x1f2f94 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x1f2f98 ldrsbeq r0, [r6], #-60
 *   @0x1f2f9c andseq r10, pc, r8, lsr r12
 *   @0x1f2fa0 andseq pc, r5, r12, lsl #21
 *   @0x1f2fa4 subseq r0, r6, r12, ror #5
 *   @0x1f2fa8 andseq lr, pc, r0, lsl r0
 *   @0x1f2fac ldrsbeq pc, [r5], -r0
 *   @0x1f2fb0 andseq r10, r5, r12, ror r3
 *
 * ══ §38/43 CSkeletonInstance::SetBoneData(char const*, int)  0xc16c0  size 692  173 条（0xc16c0..0xc1974）
 * @func 0xc16c0 0xc1974  size 692  173 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYSetString(RValue*, char const*)×6 / CDS_Map::Find(RValue*)×6 / FREE_RValue__Pre(RValue*)×6 / DS_AutoMutex::~DS_AutoMutex()×2 / spSkeleton_findBone / DS_AutoMutex::DS_AutoMutex()
 * 字段偏移 top8: 0x14×6 / 0x1c×1 / 0x264×1 / 0x4×1 / 0x2×1 / 0x24c×1 / 0x200×1 / 0x1b4×1
 * VFP 指令 18 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc16c0 push {r4, r5, r6, r7, r8, lr}
 *   @0xc16c4 sub sp, sp, #24
 *   @0xc16c8 ldr r0, [r0, #0x1c]
 *   @0xc16cc mov r4, r2
 *   @0xc16d0 bl 0x28a0c8 <spSkeleton_findBone>
 *   @0xc16d4 subs r7, r0, #0
 *   @0xc16d8 moveq r0, r7
 *   @0xc16dc beq 0xc18f4 <_ZN17CSkeletonInstance11SetBoneDataEPKci+0x234>
 *   @0xc16e0 add r5, sp, #4
 *   @0xc16e4 mov r0, r5
 *   @0xc16e8 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0xc16ec ldr r3, [pc, #0x264]
 *   @0xc16f0 ldr r3, [pc, r3]
 *   @0xc16f4 ldr r3, [r3, #0x4]
 *   @0xc16f8 ldr r6, [r3, r4, lsl #2]
 *   @0xc16fc cmp r6, #0
 *   @0xc1700 beq 0xc1944 <_ZN17CSkeletonInstance11SetBoneDataEPKci+0x284>
 *   @0xc1704 add r4, sp, #8
 *   @0xc1708 ldr r1, [pc, #0x24c]
 *   @0xc170c ldr r8, [r7]
 *   @0xc1710 add r1, pc, r1
 *   @0xc1714 mov r0, r4
 *   @0xc1718 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0xc171c mov r0, r6
 *   @0xc1720 mov r1, r4
 *   @0xc1724 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue>
 *   @0xc1728 cmp r0, #0
 *   @0xc172c ldrne r3, [r0, #0x14]
 *   @0xc1730 ldrne r2, [r0, #0x10]
 *   @0xc1734 vmovne d6, r2, r3
 *   @0xc1738 ldr r3, [sp, #0x14]
 *   @0xc173c vcvtne.f32.f64 s15, d6
 *   @0xc1740 sub r3, r3, #1
 *   @0xc1744 bic r3, r3, #-16777216
 *   @0xc1748 bic r3, r3, #3
 *   @0xc174c vstrne s15, [r8, #12]
 *   @0xc1750 cmp r3, #0
 *   @0xc1754 beq 0xc1938 <_ZN17CSkeletonInstance11SetBoneDataEPKci+0x278>
 *   @0xc1758 ldr r1, [pc, #0x200]
 *   @0xc175c mov r0, r4
 *   @0xc1760 ldr r8, [r7]
 *   @0xc1764 add r1, pc, r1
 *   @0xc1768 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0xc176c mov r0, r6
 *   @0xc1770 mov r1, r4
 *   @0xc1774 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue>
 *   @0xc1778 cmp r0, #0
 *   @0xc177c ldrne r3, [r0, #0x14]
 *   @0xc1780 ldrne r2, [r0, #0x10]
 *   @0xc1784 vmovne d6, r2, r3
 *   @0xc1788 ldr r3, [sp, #0x14]
 *   @0xc178c vcvtne.f32.f64 s15, d6
 *   @0xc1790 sub r3, r3, #1
 *   @0xc1794 bic r3, r3, #-16777216
 *   @0xc1798 bic r3, r3, #3
 *   @0xc179c vstrne s15, [r8, #16]
 *   @0xc17a0 cmp r3, #0
 *   @0xc17a4 beq 0xc192c <_ZN17CSkeletonInstance11SetBoneDataEPKci+0x26c>
 *   @0xc17a8 ldr r1, [pc, #0x1b4]
 *   @0xc17ac mov r0, r4
 *   @0xc17b0 ldr r8, [r7]
 *   @0xc17b4 add r1, pc, r1
 *   @0xc17b8 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0xc17bc mov r0, r6
 *   @0xc17c0 mov r1, r4
 *   @0xc17c4 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue>
 *   @0xc17c8 cmp r0, #0
 *   @0xc17cc ldrne r3, [r0, #0x14]
 *   @0xc17d0 ldrne r2, [r0, #0x10]
 *   @0xc17d4 vmovne d6, r2, r3
 *   @0xc17d8 ldr r3, [sp, #0x14]
 *   @0xc17dc vcvtne.f32.f64 s15, d6
 *   @0xc17e0 sub r3, r3, #1
 *   @0xc17e4 bic r3, r3, #-16777216
 *   @0xc17e8 bic r3, r3, #3
 *   @0xc17ec vstrne s15, [r8, #20]
 *   @0xc17f0 cmp r3, #0
 *   @0xc17f4 beq 0xc1920 <_ZN17CSkeletonInstance11SetBoneDataEPKci+0x260>
 *   @0xc17f8 ldr r1, [pc, #0x168]
 *   @0xc17fc mov r0, r4
 *   @0xc1800 ldr r8, [r7]
 *   @0xc1804 add r1, pc, r1
 *   @0xc1808 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0xc180c mov r0, r6
 *   @0xc1810 mov r1, r4
 *   @0xc1814 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue>
 *   @0xc1818 cmp r0, #0
 *   @0xc181c ldrne r3, [r0, #0x14]
 *   @0xc1820 ldrne r2, [r0, #0x10]
 *   @0xc1824 vmovne d6, r2, r3
 *   @0xc1828 ldr r3, [sp, #0x14]
 *   @0xc182c vcvtne.f32.f64 s15, d6
 *   @0xc1830 sub r3, r3, #1
 *   @0xc1834 bic r3, r3, #-16777216
 *   @0xc1838 bic r3, r3, #3
 *   @0xc183c vstrne s15, [r8, #24]
 *   @0xc1840 cmp r3, #0
 *   @0xc1844 beq 0xc1914 <_ZN17CSkeletonInstance11SetBoneDataEPKci+0x254>
 *   @0xc1848 ldr r1, [pc, #0x11c]
 *   @0xc184c mov r0, r4
 *   @0xc1850 ldr r8, [r7]
 *   @0xc1854 add r1, pc, r1
 *   @0xc1858 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0xc185c mov r0, r6
 *   @0xc1860 mov r1, r4
 *   @0xc1864 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue>
 *   @0xc1868 cmp r0, #0
 *   @0xc186c ldrne r3, [r0, #0x14]
 *   @0xc1870 ldrne r2, [r0, #0x10]
 *   @0xc1874 vmovne d6, r2, r3
 *   @0xc1878 ldr r3, [sp, #0x14]
 *   @0xc187c vcvtne.f32.f64 s15, d6
 *   @0xc1880 sub r3, r3, #1
 *   @0xc1884 bic r3, r3, #-16777216
 *   @0xc1888 bic r3, r3, #3
 *   @0xc188c vstrne s15, [r8, #28]
 *   @0xc1890 cmp r3, #0
 *   @0xc1894 beq 0xc1908 <_ZN17CSkeletonInstance11SetBoneDataEPKci+0x248>
 *   @0xc1898 ldr r1, [pc, #0xd0]
 *   @0xc189c mov r0, r4
 *   @0xc18a0 ldr r7, [r7]
 *   @0xc18a4 add r1, pc, r1
 *   @0xc18a8 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0xc18ac mov r0, r6
 *   @0xc18b0 mov r1, r4
 *   @0xc18b4 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue>
 *   @0xc18b8 cmp r0, #0
 *   @0xc18bc ldrne r3, [r0, #0x14]
 *   @0xc18c0 ldrne r2, [r0, #0x10]
 *   @0xc18c4 vmovne d6, r2, r3
 *   @0xc18c8 ldr r3, [sp, #0x14]
 *   @0xc18cc vcvtne.f32.f64 s15, d6
 *   @0xc18d0 sub r3, r3, #1
 *   @0xc18d4 bic r3, r3, #-16777216
 *   @0xc18d8 bic r3, r3, #3
 *   @0xc18dc vstrne s15, [r7, #32]
 *   @0xc18e0 cmp r3, #0
 *   @0xc18e4 beq 0xc18fc <_ZN17CSkeletonInstance11SetBoneDataEPKci+0x23c>
 *   @0xc18e8 mov r0, r5
 *   @0xc18ec bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xc18f0 mov r0, #1
 *   @0xc18f4 add sp, sp, #24
 *   @0xc18f8 pop {r4, r5, r6, r7, r8, pc}
 *   @0xc18fc mov r0, r4
 *   @0xc1900 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xc1904 b 0xc18e8 <_ZN17CSkeletonInstance11SetBoneDataEPKci+0x228>
 *   @0xc1908 mov r0, r4
 *   @0xc190c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xc1910 b 0xc1898 <_ZN17CSkeletonInstance11SetBoneDataEPKci+0x1d8>
 *   @0xc1914 mov r0, r4
 *   @0xc1918 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xc191c b 0xc1848 <_ZN17CSkeletonInstance11SetBoneDataEPKci+0x188>
 *   @0xc1920 mov r0, r4
 *   @0xc1924 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xc1928 b 0xc17f8 <_ZN17CSkeletonInstance11SetBoneDataEPKci+0x138>
 *   @0xc192c mov r0, r4
 *   @0xc1930 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xc1934 b 0xc17a8 <_ZN17CSkeletonInstance11SetBoneDataEPKci+0xe8>
 *   @0xc1938 mov r0, r4
 *   @0xc193c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xc1940 b 0xc1758 <_ZN17CSkeletonInstance11SetBoneDataEPKci+0x98>
 *   @0xc1944 mov r0, r5
 *   @0xc1948 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xc194c mov r0, r6
 *   @0xc1950 add sp, sp, #24
 *   @0xc1954 pop {r4, r5, r6, r7, r8, pc}
 *   @0xc1958 eorseq r12, r2, r12, asr #4
 *   @0xc195c eoreq pc, r6, r12, asr r1
 *   @0xc1960 eoreq pc, r6, r0, lsl r1
 *   @0xc1964 eoreq pc, r6, r4, asr #1
 *   @0xc1968 eoreq pc, r6, r8, ror r0
 *   @0xc196c eoreq pc, r6, r0, lsr r0
 *   @0xc1970 eoreq lr, r6, r8, ror #31
 *
 * ══ §39/43 VM::PokeDSGrid(int, int, int, RValue&)  0xe9bd8  size 688  172 条（0xe9bd8..0xe9e88）
 * @func 0xe9bd8 0xe9e88  size 688  172 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: VM::PokeDSGrid(int, int, int, RValue&)+0x154×3 / LOCK_RVALUE_MUTEX()×2 / UNLOCK_RVALUE_MUTEX()×2 / FREE_RValue__Pre(RValue*)×2 / YYFree(void const*)×2 / operator delete(void*)×2 / GetTheGrids(int&) / GetContextStackTop()
 * 字段偏移 top8: 0x4×18 / 0x8×8 / 0xc×7 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xe9bd8 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xe9bdc sub sp, sp, #8
 *   @0xe9be0 mov r4, r0
 *   @0xe9be4 add r0, sp, #4
 *   @0xe9be8 mov r5, r1
 *   @0xe9bec mov r6, r2
 *   @0xe9bf0 mov r7, r3
 *   @0xe9bf4 bl 0x10026c <_Z11GetTheGridsRi>
 *   @0xe9bf8 cmp r4, #0
 *   @0xe9bfc blt 0xe9d2c <_ZN2VM10PokeDSGridEiiiR6RValue+0x154>
 *   @0xe9c00 ldr r1, [sp, #0x4]
 *   @0xe9c04 cmp r4, r1
 *   @0xe9c08 bge 0xe9d2c <_ZN2VM10PokeDSGridEiiiR6RValue+0x154>
 *   @0xe9c0c ldr r4, [r0, r4, lsl #2]
 *   @0xe9c10 cmp r4, #0
 *   @0xe9c14 beq 0xe9d2c <_ZN2VM10PokeDSGridEiiiR6RValue+0x154>
 *   @0xe9c18 cmp r5, #0
 *   @0xe9c1c blt 0xe9d2c <_ZN2VM10PokeDSGridEiiiR6RValue+0x154>
 *   @0xe9c20 ldr r3, [r4, #0x4]
 *   @0xe9c24 cmp r5, r3
 *   @0xe9c28 bge 0xe9d2c <_ZN2VM10PokeDSGridEiiiR6RValue+0x154>
 *   @0xe9c2c cmp r6, #0
 *   @0xe9c30 blt 0xe9d2c <_ZN2VM10PokeDSGridEiiiR6RValue+0x154>
 *   @0xe9c34 ldr r2, [r4, #0x8]
 *   @0xe9c38 cmp r6, r2
 *   @0xe9c3c bge 0xe9d2c <_ZN2VM10PokeDSGridEiiiR6RValue+0x154>
 *   @0xe9c40 mla r10, r6, r3, r5
 *   @0xe9c44 ldr r9, [r4]
 *   @0xe9c48 add r8, r9, r10, lsl #4
 *   @0xe9c4c ldr r3, [r8, #0xc]
 *   @0xe9c50 sub r3, r3, #1
 *   @0xe9c54 bic r3, r3, #-16777216
 *   @0xe9c58 bic r3, r3, #3
 *   @0xe9c5c cmp r3, #0
 *   @0xe9c60 beq 0xe9d7c <_ZN2VM10PokeDSGridEiiiR6RValue+0x1a4>
 *   @0xe9c64 mov r3, #0
 *   @0xe9c68 mov r2, #5
 *   @0xe9c6c str r3, [r8, #0x8]
 *   @0xe9c70 str r2, [r8, #0xc]
 *   @0xe9c74 str r3, [r9, r10, lsl #4]
 *   @0xe9c78 ldr r3, [r4, #0x4]
 *   @0xe9c7c ldr r8, [r4]
 *   @0xe9c80 mla r5, r3, r6, r5
 *   @0xe9c84 add r4, r8, r5, lsl #4
 *   @0xe9c88 ldr r2, [r4, #0xc]
 *   @0xe9c8c bic r3, r2, #-16777216
 *   @0xe9c90 cmp r3, #1
 *   @0xe9c94 beq 0xe9d48 <_ZN2VM10PokeDSGridEiiiR6RValue+0x170>
 *   @0xe9c98 cmp r3, #2
 *   @0xe9c9c bne 0xe9cc4 <_ZN2VM10PokeDSGridEiiiR6RValue+0xec>
 *   @0xe9ca0 sub r3, r2, #1
 *   @0xe9ca4 bic r3, r3, #-16777216
 *   @0xe9ca8 bic r3, r3, #3
 *   @0xe9cac cmp r3, #0
 *   @0xe9cb0 beq 0xe9e58 <_ZN2VM10PokeDSGridEiiiR6RValue+0x280>
 *   @0xe9cb4 mov r2, #0
 *   @0xe9cb8 mov r3, #5
 *   @0xe9cbc str r2, [r4, #0x8]
 *   @0xe9cc0 str r3, [r4, #0xc]
 *   @0xe9cc4 ldr r3, [r7, #0xc]
 *   @0xe9cc8 mov r1, #0
 *   @0xe9ccc ldr r2, [r7, #0x8]
 *   @0xe9cd0 str r1, [r8, r5, lsl #4]
 *   @0xe9cd4 str r3, [r4, #0xc]
 *   @0xe9cd8 ldr r3, [r7, #0xc]
 *   @0xe9cdc str r2, [r4, #0x8]
 *   @0xe9ce0 bic r3, r3, #-16777216
 *   @0xe9ce4 cmp r3, #14
 *   @0xe9ce8 addls pc, pc, r3, lsl #2
 *   @0xe9cec b 0xe9df8 <_ZN2VM10PokeDSGridEiiiR6RValue+0x220>
 *   @0xe9cf0 b 0xe9d88 <_ZN2VM10PokeDSGridEiiiR6RValue+0x1b0>
 *   @0xe9cf4 b 0xe9e00 <_ZN2VM10PokeDSGridEiiiR6RValue+0x228>
 *   @0xe9cf8 b 0xe9dc8 <_ZN2VM10PokeDSGridEiiiR6RValue+0x1f0>
 *   @0xe9cfc b 0xe9d38 <_ZN2VM10PokeDSGridEiiiR6RValue+0x160>
 *   @0xe9d00 b 0xe9df8 <_ZN2VM10PokeDSGridEiiiR6RValue+0x220>
 *   @0xe9d04 b 0xe9df8 <_ZN2VM10PokeDSGridEiiiR6RValue+0x220>
 *   @0xe9d08 b 0xe9da0 <_ZN2VM10PokeDSGridEiiiR6RValue+0x1c8>
 *   @0xe9d0c b 0xe9d38 <_ZN2VM10PokeDSGridEiiiR6RValue+0x160>
 *   @0xe9d10 b 0xe9df8 <_ZN2VM10PokeDSGridEiiiR6RValue+0x220>
 *   @0xe9d14 b 0xe9df8 <_ZN2VM10PokeDSGridEiiiR6RValue+0x220>
 *   @0xe9d18 b 0xe9d88 <_ZN2VM10PokeDSGridEiiiR6RValue+0x1b0>
 *   @0xe9d1c b 0xe9df8 <_ZN2VM10PokeDSGridEiiiR6RValue+0x220>
 *   @0xe9d20 b 0xe9df8 <_ZN2VM10PokeDSGridEiiiR6RValue+0x220>
 *   @0xe9d24 b 0xe9d88 <_ZN2VM10PokeDSGridEiiiR6RValue+0x1b0>
 *   @0xe9d28 b 0xe9d38 <_ZN2VM10PokeDSGridEiiiR6RValue+0x160>
 *   @0xe9d2c mov r0, #0
 *   @0xe9d30 add sp, sp, #8
 *   @0xe9d34 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xe9d38 ldr r3, [r7]
 *   @0xe9d3c mov r0, #1
 *   @0xe9d40 str r3, [r8, r5, lsl #4]
 *   @0xe9d44 b 0xe9d30 <_ZN2VM10PokeDSGridEiiiR6RValue+0x158>
 *   @0xe9d48 ldr r6, [r8, r5, lsl #4]
 *   @0xe9d4c cmp r6, #0
 *   @0xe9d50 beq 0xe9d70 <_ZN2VM10PokeDSGridEiiiR6RValue+0x198>
 *   @0xe9d54 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xe9d58 ldr r9, [r6, #0x4]
 *   @0xe9d5c sub r9, r9, #1
 *   @0xe9d60 str r9, [r6, #0x4]
 *   @0xe9d64 cmp r9, #0
 *   @0xe9d68 beq 0xe9e20 <_ZN2VM10PokeDSGridEiiiR6RValue+0x248>
 *   @0xe9d6c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xe9d70 mov r3, #0
 *   @0xe9d74 str r3, [r8, r5, lsl #4]
 *   @0xe9d78 b 0xe9cc4 <_ZN2VM10PokeDSGridEiiiR6RValue+0xec>
 *   @0xe9d7c mov r0, r8
 *   @0xe9d80 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xe9d84 b 0xe9c64 <_ZN2VM10PokeDSGridEiiiR6RValue+0x8c>
 *   @0xe9d88 ldr r2, [r7]
 *   @0xe9d8c mov r0, #1
 *   @0xe9d90 ldr r3, [r7, #0x4]
 *   @0xe9d94 str r2, [r8, r5, lsl #4]
 *   @0xe9d98 str r3, [r4, #0x4]
 *   @0xe9d9c b 0xe9d30 <_ZN2VM10PokeDSGridEiiiR6RValue+0x158>
 *   @0xe9da0 ldr r3, [r7]
 *   @0xe9da4 str r3, [r8, r5, lsl #4]
 *   @0xe9da8 ldr r3, [r7]
 *   @0xe9dac cmp r3, #0
 *   @0xe9db0 beq 0xe9df8 <_ZN2VM10PokeDSGridEiiiR6RValue+0x220>
 *   @0xe9db4 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0xe9db8 ldr r1, [r7]
 *   @0xe9dbc bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0xe9dc0 mov r0, #1
 *   @0xe9dc4 b 0xe9d30 <_ZN2VM10PokeDSGridEiiiR6RValue+0x158>
 *   @0xe9dc8 ldr r3, [r7]
 *   @0xe9dcc cmp r3, #0
 *   @0xe9dd0 str r3, [r8, r5, lsl #4]
 *   @0xe9dd4 beq 0xe9df8 <_ZN2VM10PokeDSGridEiiiR6RValue+0x220>
 *   @0xe9dd8 ldr r1, [r3, #0x8]
 *   @0xe9ddc ldr r2, [r3]
 *   @0xe9de0 cmp r1, #0
 *   @0xe9de4 streq r4, [r3, #0x8]
 *   @0xe9de8 add r2, r2, #1
 *   @0xe9dec str r2, [r3]
 *   @0xe9df0 moveq r0, #1
 *   @0xe9df4 beq 0xe9d30 <_ZN2VM10PokeDSGridEiiiR6RValue+0x158>
 *   @0xe9df8 mov r0, #1
 *   @0xe9dfc b 0xe9d30 <_ZN2VM10PokeDSGridEiiiR6RValue+0x158>
 *   @0xe9e00 ldr r3, [r7]
 *   @0xe9e04 mov r0, #1
 *   @0xe9e08 cmp r3, #0
 *   @0xe9e0c ldrne r2, [r3, #0x4]
 *   @0xe9e10 addne r2, r2, #1
 *   @0xe9e14 strne r2, [r3, #0x4]
 *   @0xe9e18 str r3, [r8, r5, lsl #4]
 *   @0xe9e1c b 0xe9d30 <_ZN2VM10PokeDSGridEiiiR6RValue+0x158>
 *   @0xe9e20 ldr r0, [r6]
 *   @0xe9e24 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xe9e28 str r9, [r6]
 *   @0xe9e2c str r9, [r6, #0x8]
 *   @0xe9e30 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xe9e34 ldr r9, [r6, #0x4]
 *   @0xe9e38 sub r9, r9, #1
 *   @0xe9e3c str r9, [r6, #0x4]
 *   @0xe9e40 cmp r9, #0
 *   @0xe9e44 beq 0xe9e64 <_ZN2VM10PokeDSGridEiiiR6RValue+0x28c>
 *   @0xe9e48 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xe9e4c mov r0, r6
 *   @0xe9e50 bl 0x27d1d0 <_ZdlPv>
 *   @0xe9e54 b 0xe9d6c <_ZN2VM10PokeDSGridEiiiR6RValue+0x194>
 *   @0xe9e58 mov r0, r4
 *   @0xe9e5c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xe9e60 b 0xe9cb4 <_ZN2VM10PokeDSGridEiiiR6RValue+0xdc>
 *   @0xe9e64 ldr r0, [r6]
 *   @0xe9e68 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xe9e6c mov r0, r6
 *   @0xe9e70 str r9, [r6]
 *   @0xe9e74 str r9, [r6, #0x8]
 *   @0xe9e78 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0xe9e7c mov r0, r6
 *   @0xe9e80 bl 0x27d1d0 <_ZdlPv>
 *   @0xe9e84 b 0xe9e48 <_ZN2VM10PokeDSGridEiiiR6RValue+0x270>
 *
 * ══ §40/43 JS_DeleteProperty(YYObjectBase*, RValue*, char const*, bool)  0x24edf4  size 688  172 条（0x24edf4..0x24f0a4）
 * @func 0x24edf4 0x24f0a4  size 688  172 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYObjectBase::InternalGetYYVar(int)×5 / 0xb6574×2 / 0xb66b8 / JS_DeleteProperty(YYObjectBase*, RValue*, char const*, bool)+0x210 / Code_Variable_Find_Slot_From_Name(YYObjectBase*, char const*) / JSThrowTypeError(char const*) / FREE_RValue__Pre(RValue*)
 * 字段偏移 top8: 0xc×9 / 0x4×9 / 0x8×5 / 0x1×3 / 0x258×1 / 0x40×1 / 0x224×1 / 0x20c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24edf4 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x24edf8 mov r7, r0
 *   @0x24edfc ldrb r0, [r2]
 *   @0x24ee00 sub sp, sp, #20
 *   @0x24ee04 mov r9, r2
 *   @0x24ee08 mov r8, r3
 *   @0x24ee0c cmp r0, #0
 *   @0x24ee10 mov r4, #0
 *   @0x24ee14 mov r5, #0
 *   @0x24ee18 mov r2, #0
 *   @0x24ee1c mvn r3, #-16777216
 *   @0x24ee20 mov r6, r1
 *   @0x24ee24 strd r4, r5, [sp]
 *   @0x24ee28 str r2, [sp, #0x8]
 *   @0x24ee2c str r3, [sp, #0xc]
 *   @0x24ee30 beq 0x24ef1c <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x128>
 *   @0x24ee34 ldr r3, [pc, #0x258]
 *   @0x24ee38 ldr r3, [pc, r3]
 *   @0x24ee3c ldr r2, [r3]
 *   @0x24ee40 add r0, r2, r0
 *   @0x24ee44 ldrb r3, [r0, #0x1]
 *   @0x24ee48 tst r3, #4
 *   @0x24ee4c movne r3, r9
 *   @0x24ee50 beq 0x24ef1c <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x128>
 *   @0x24ee54 ldrb r12, [r3, #0x1]!
 *   @0x24ee58 cmp r12, #0
 *   @0x24ee5c add lr, r2, r12
 *   @0x24ee60 bne 0x24ef10 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x11c>
 *   @0x24ee64 ldr r4, [r7, #0x40]
 *   @0x24ee68 mov r3, #13
 *   @0x24ee6c ldr r1, [pc, #0x224]
 *   @0x24ee70 str r3, [r6, #0xc]
 *   @0x24ee74 add r1, pc, r1
 *   @0x24ee78 mov r0, r4
 *   @0x24ee7c bl 0xb6574 <strcmp@plt>
 *   @0x24ee80 cmp r0, #0
 *   @0x24ee84 beq 0x24eea0 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0xac>
 *   @0x24ee88 ldr r1, [pc, #0x20c]
 *   @0x24ee8c mov r0, r4
 *   @0x24ee90 add r1, pc, r1
 *   @0x24ee94 bl 0xb6574 <strcmp@plt>
 *   @0x24ee98 cmp r0, #0
 *   @0x24ee9c bne 0x24ef24 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x130>
 *   @0x24eea0 ldr r3, [r7, #0x4]
 *   @0x24eea4 cmp r3, #0
 *   @0x24eea8 beq 0x24f030 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x23c>
 *   @0x24eeac add r3, r3, #16
 *   @0x24eeb0 mov r0, r9
 *   @0x24eeb4 ldr r4, [r3]
 *   @0x24eeb8 bl 0xb66b8 <atoi@plt>
 *   @0x24eebc subs r1, r0, #0
 *   @0x24eec0 blt 0x24f004 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x210>
 *   @0x24eec4 ldr r3, [r4, #0x24]
 *   @0x24eec8 cmp r1, r3
 *   @0x24eecc bhs 0x24f004 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x210>
 *   @0x24eed0 ldr r3, [r4, #0x4]
 *   @0x24eed4 cmp r3, #0
 *   @0x24eed8 beq 0x24f064 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x270>
 *   @0x24eedc add r0, r3, r1, lsl #4
 *   @0x24eee0 mov r3, #0
 *   @0x24eee4 mov r2, #5
 *   @0x24eee8 str r3, [r0]
 *   @0x24eeec str r2, [r0, #0xc]
 *   @0x24eef0 mov r2, r3
 *   @0x24eef4 str r3, [r0, #0x4]
 *   @0x24eef8 movt r2, #0x3ff0
 *   @0x24eefc str r3, [r0, #0x8]
 *   @0x24ef00 str r3, [r6]
 *   @0x24ef04 str r2, [r6, #0x4]
 *   @0x24ef08 add sp, sp, #20
 *   @0x24ef0c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x24ef10 ldrb r12, [lr, #0x1]
 *   @0x24ef14 tst r12, #4
 *   @0x24ef18 bne 0x24ee54 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x60>
 *   @0x24ef1c mov r3, #13
 *   @0x24ef20 str r3, [r6, #0xc]
 *   @0x24ef24 mov r1, r9
 *   @0x24ef28 mov r0, r7
 *   @0x24ef2c bl 0xd21ec <_Z33Code_Variable_Find_Slot_From_NameP12YYObjectBasePKc>
 *   @0x24ef30 cmn r0, #1
 *   @0x24ef34 mov r4, r0
 *   @0x24ef38 beq 0x24ef64 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x170>
 *   @0x24ef3c ldr r3, [r7, #0x4]
 *   @0x24ef40 cmp r3, #0
 *   @0x24ef44 beq 0x24f050 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x25c>
 *   @0x24ef48 add r3, r3, r0, lsl #4
 *   @0x24ef4c ldr r0, [r3]
 *   @0x24ef50 mov r12, sp
 *   @0x24ef54 ldr r1, [r3, #0x4]
 *   @0x24ef58 ldr r2, [r3, #0x8]
 *   @0x24ef5c ldr r3, [r3, #0xc]
 *   @0x24ef60 stm r12!, {r0, r1, r2, r3}
 *   @0x24ef64 ldr r2, [sp, #0xc]
 *   @0x24ef68 mvn r3, #-16777216
 *   @0x24ef6c and r2, r2, r3
 *   @0x24ef70 cmp r2, r3
 *   @0x24ef74 beq 0x24f018 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x224>
 *   @0x24ef78 ldr r3, [sp, #0x8]
 *   @0x24ef7c tst r3, #2
 *   @0x24ef80 beq 0x24eff0 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x1fc>
 *   @0x24ef84 ldr r5, [r7, #0x4]
 *   @0x24ef88 cmp r5, #0
 *   @0x24ef8c beq 0x24f080 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x28c>
 *   @0x24ef90 add r5, r5, r4, lsl #4
 *   @0x24ef94 ldr r3, [r5, #0xc]
 *   @0x24ef98 sub r3, r3, #1
 *   @0x24ef9c bic r3, r3, #-16777216
 *   @0x24efa0 bic r3, r3, #3
 *   @0x24efa4 cmp r3, #0
 *   @0x24efa8 beq 0x24f044 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x250>
 *   @0x24efac mov r3, #0
 *   @0x24efb0 str r3, [r5]
 *   @0x24efb4 ldr r2, [r7, #0x4]
 *   @0x24efb8 mov r1, #5
 *   @0x24efbc str r3, [r5, #0x8]
 *   @0x24efc0 cmp r2, r3
 *   @0x24efc4 str r1, [r5, #0xc]
 *   @0x24efc8 beq 0x24f070 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x27c>
 *   @0x24efcc add r0, r2, r4, lsl #4
 *   @0x24efd0 mvn r2, #-16777216
 *   @0x24efd4 mov r3, #0
 *   @0x24efd8 str r2, [r0, #0xc]
 *   @0x24efdc movt r3, #0x3ff0
 *   @0x24efe0 mov r2, #0
 *   @0x24efe4 stm r6, {r2, r3}
 *   @0x24efe8 add sp, sp, #20
 *   @0x24efec pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x24eff0 cmp r8, #0
 *   @0x24eff4 beq 0x24f004 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x210>
 *   @0x24eff8 ldr r0, [pc, #0xa0]
 *   @0x24effc add r0, pc, r0
 *   @0x24f000 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x24f004 mov r3, #0
 *   @0x24f008 str r3, [r6]
 *   @0x24f00c str r3, [r6, #0x4]
 *   @0x24f010 add sp, sp, #20
 *   @0x24f014 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x24f018 mov r3, #0
 *   @0x24f01c mov r2, r3
 *   @0x24f020 movt r3, #0x3ff0
 *   @0x24f024 stm r6, {r2, r3}
 *   @0x24f028 add sp, sp, #20
 *   @0x24f02c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x24f030 mov r0, r7
 *   @0x24f034 mov r1, #1
 *   @0x24f038 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x24f03c mov r3, r0
 *   @0x24f040 b 0x24eeb0 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0xbc>
 *   @0x24f044 mov r0, r5
 *   @0x24f048 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x24f04c b 0x24efac <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x1b8>
 *   @0x24f050 mov r0, r7
 *   @0x24f054 mov r1, r4
 *   @0x24f058 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x24f05c mov r3, r0
 *   @0x24f060 b 0x24ef4c <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x158>
 *   @0x24f064 mov r0, r4
 *   @0x24f068 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x24f06c b 0x24eee0 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0xec>
 *   @0x24f070 mov r0, r7
 *   @0x24f074 mov r1, r4
 *   @0x24f078 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x24f07c b 0x24efd0 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x1dc>
 *   @0x24f080 mov r0, r7
 *   @0x24f084 mov r1, r4
 *   @0x24f088 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x24f08c mov r5, r0
 *   @0x24f090 b 0x24ef94 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb+0x1a0>
 *   @0x24f094 andseq lr, r9, r8, asr #22
 *   @0x24f098 andeq r5, lr, r4, lsr #21
 *   @0x24f09c ldrheq r6, [r0], -r4
 *   @0x24f0a0 andseq r7, r0, r12, asr r0
 *
 * ══ §41/43 jpeg_consume_input  0x2b2f08  size 688  172 条（0x2b2f08..0x2b31b8）
 * @func 0x2b2f08 0x2b31b8  size 688  172 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×7 / 0x18×5 / 0x28×5 / 0x4×4 / 0x109×4 / 0x190×3 / 0x54×2 / 0x108×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b2f08 ldr r2, [r0, #0x14]
 *   @0x2b2f0c push {r3, r4, r5, r6, r7, lr}
 *   @0x2b2f10 sub r3, r2, #200
 *   @0x2b2f14 mov r4, r0
 *   @0x2b2f18 cmp r3, #10
 *   @0x2b2f1c addls pc, pc, r3, lsl #2
 *   @0x2b2f20 b 0x2b2fbc <jpeg_consume_input+0xb4>
 *   @0x2b2f24 b 0x2b2f50 <jpeg_consume_input+0x48>
 *   @0x2b2f28 b 0x2b2f74 <jpeg_consume_input+0x6c>
 *   @0x2b2f2c b 0x2b2f98 <jpeg_consume_input+0x90>
 *   @0x2b2f30 b 0x2b2fa4 <jpeg_consume_input+0x9c>
 *   @0x2b2f34 b 0x2b2fa4 <jpeg_consume_input+0x9c>
 *   @0x2b2f38 b 0x2b2fa4 <jpeg_consume_input+0x9c>
 *   @0x2b2f3c b 0x2b2fa4 <jpeg_consume_input+0x9c>
 *   @0x2b2f40 b 0x2b2fa4 <jpeg_consume_input+0x9c>
 *   @0x2b2f44 b 0x2b2fa4 <jpeg_consume_input+0x9c>
 *   @0x2b2f48 b 0x2b2fbc <jpeg_consume_input+0xb4>
 *   @0x2b2f4c b 0x2b2fa4 <jpeg_consume_input+0x9c>
 *   @0x2b2f50 ldr r3, [r0, #0x190]
 *   @0x2b2f54 ldr r3, [r3, #0x4]
 *   @0x2b2f58 blx r3
 *   @0x2b2f5c ldr r3, [r4, #0x18]
 *   @0x2b2f60 mov r0, r4
 *   @0x2b2f64 ldr r3, [r3, #0x8]
 *   @0x2b2f68 blx r3
 *   @0x2b2f6c mov r3, #201
 *   @0x2b2f70 str r3, [r4, #0x14]
 *   @0x2b2f74 ldr r3, [r4, #0x190]
 *   @0x2b2f78 mov r0, r4
 *   @0x2b2f7c ldr r3, [r3]
 *   @0x2b2f80 blx r3
 *   @0x2b2f84 cmp r0, #1
 *   @0x2b2f88 mov r5, r0
 *   @0x2b2f8c beq 0x2b2fe4 <jpeg_consume_input+0xdc>
 *   @0x2b2f90 mov r0, r5
 *   @0x2b2f94 pop {r3, r4, r5, r6, r7, pc}
 *   @0x2b2f98 mov r5, #1
 *   @0x2b2f9c mov r0, r5
 *   @0x2b2fa0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x2b2fa4 ldr r3, [r0, #0x190]
 *   @0x2b2fa8 ldr r3, [r3]
 *   @0x2b2fac blx r3
 *   @0x2b2fb0 mov r5, r0
 *   @0x2b2fb4 mov r0, r5
 *   @0x2b2fb8 pop {r3, r4, r5, r6, r7, pc}
 *   @0x2b2fbc ldr r3, [r0]
 *   @0x2b2fc0 mov r1, #20
 *   @0x2b2fc4 mov r5, #0
 *   @0x2b2fc8 str r2, [r3, #0x18]
 *   @0x2b2fcc ldr r2, [r4]
 *   @0x2b2fd0 str r1, [r3, #0x14]
 *   @0x2b2fd4 ldr r3, [r2]
 *   @0x2b2fd8 blx r3
 *   @0x2b2fdc mov r0, r5
 *   @0x2b2fe0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x2b2fe4 ldr r6, [r4, #0x24]
 *   @0x2b2fe8 cmp r6, #3
 *   @0x2b2fec beq 0x2b3078 <jpeg_consume_input+0x170>
 *   @0x2b2ff0 cmp r6, #4
 *   @0x2b2ff4 beq 0x2b30dc <jpeg_consume_input+0x1d4>
 *   @0x2b2ff8 cmp r6, #1
 *   @0x2b2ffc streq r0, [r4, #0x28]
 *   @0x2b3000 streq r0, [r4, #0x2c]
 *   @0x2b3004 movne r3, #0
 *   @0x2b3008 strne r3, [r4, #0x28]
 *   @0x2b300c strne r3, [r4, #0x2c]
 *   @0x2b3010 mov r1, #0
 *   @0x2b3014 mov r0, #1
 *   @0x2b3018 mov r2, #0
 *   @0x2b301c mov r3, #0
 *   @0x2b3020 mov r7, #2
 *   @0x2b3024 movt r3, #0x3ff0
 *   @0x2b3028 mov r6, #256
 *   @0x2b302c mov r12, #202
 *   @0x2b3030 str r0, [r4, #0x30]
 *   @0x2b3034 str r0, [r4, #0x34]
 *   @0x2b3038 strb r0, [r4, #0x48]
 *   @0x2b303c strb r0, [r4, #0x49]
 *   @0x2b3040 strb r0, [r4, #0x50]
 *   @0x2b3044 strb r1, [r4, #0x40]
 *   @0x2b3048 strb r1, [r4, #0x41]
 *   @0x2b304c str r1, [r4, #0x44]
 *   @0x2b3050 strb r1, [r4, #0x4a]
 *   @0x2b3054 strd r2, r3, [r4, #56]
 *   @0x2b3058 str r1, [r4, #0x74]
 *   @0x2b305c strb r1, [r4, #0x58]
 *   @0x2b3060 strb r1, [r4, #0x59]
 *   @0x2b3064 strb r1, [r4, #0x5a]
 *   @0x2b3068 str r7, [r4, #0x4c]
 *   @0x2b306c str r6, [r4, #0x54]
 *   @0x2b3070 str r12, [r4, #0x14]
 *   @0x2b3074 b 0x2b2f90 <jpeg_consume_input+0x88>
 *   @0x2b3078 ldrb r3, [r4, #0x100]
 *   @0x2b307c cmp r3, #0
 *   @0x2b3080 bne 0x2b3198 <jpeg_consume_input+0x290>
 *   @0x2b3084 ldrb r3, [r4, #0x108]
 *   @0x2b3088 cmp r3, #0
 *   @0x2b308c beq 0x2b3138 <jpeg_consume_input+0x230>
 *   @0x2b3090 ldrb r3, [r4, #0x109]
 *   @0x2b3094 cmp r3, #0
 *   @0x2b3098 beq 0x2b31ac <jpeg_consume_input+0x2a4>
 *   @0x2b309c cmp r3, #1
 *   @0x2b30a0 beq 0x2b30cc <jpeg_consume_input+0x1c4>
 *   @0x2b30a4 ldr r3, [r4]
 *   @0x2b30a8 mov r2, #114
 *   @0x2b30ac mov r0, r4
 *   @0x2b30b0 mvn r1, #0
 *   @0x2b30b4 str r2, [r3, #0x14]
 *   @0x2b30b8 ldrb r2, [r4, #0x109]
 *   @0x2b30bc str r2, [r3, #0x18]
 *   @0x2b30c0 ldr r3, [r4]
 *   @0x2b30c4 ldr r3, [r3, #0x4]
 *   @0x2b30c8 blx r3
 *   @0x2b30cc str r6, [r4, #0x28]
 *   @0x2b30d0 mov r3, #2
 *   @0x2b30d4 str r3, [r4, #0x2c]
 *   @0x2b30d8 b 0x2b3010 <jpeg_consume_input+0x108>
 *   @0x2b30dc ldrb r3, [r4, #0x108]
 *   @0x2b30e0 cmp r3, #0
 *   @0x2b30e4 beq 0x2b31a4 <jpeg_consume_input+0x29c>
 *   @0x2b30e8 ldrb r3, [r4, #0x109]
 *   @0x2b30ec cmp r3, #0
 *   @0x2b30f0 beq 0x2b31a4 <jpeg_consume_input+0x29c>
 *   @0x2b30f4 cmp r3, #2
 *   @0x2b30f8 beq 0x2b3124 <jpeg_consume_input+0x21c>
 *   @0x2b30fc ldr r3, [r4]
 *   @0x2b3100 mov r2, #114
 *   @0x2b3104 mov r0, r4
 *   @0x2b3108 mvn r1, #0
 *   @0x2b310c str r2, [r3, #0x14]
 *   @0x2b3110 ldrb r2, [r4, #0x109]
 *   @0x2b3114 str r2, [r3, #0x18]
 *   @0x2b3118 ldr r3, [r4]
 *   @0x2b311c ldr r3, [r3, #0x4]
 *   @0x2b3120 blx r3
 *   @0x2b3124 mov r3, #5
 *   @0x2b3128 str r3, [r4, #0x28]
 *   @0x2b312c mov r3, #4
 *   @0x2b3130 str r3, [r4, #0x2c]
 *   @0x2b3134 b 0x2b3010 <jpeg_consume_input+0x108>
 *   @0x2b3138 ldr r3, [r4, #0xc4]
 *   @0x2b313c ldr r12, [r3]
 *   @0x2b3140 ldr r2, [r3, #0x54]
 *   @0x2b3144 ldr r6, [r3, #0xa8]
 *   @0x2b3148 cmp r12, #1
 *   @0x2b314c cmpeq r2, #2
 *   @0x2b3150 bne 0x2b315c <jpeg_consume_input+0x254>
 *   @0x2b3154 cmp r6, #3
 *   @0x2b3158 beq 0x2b3198 <jpeg_consume_input+0x290>
 *   @0x2b315c cmp r12, #82
 *   @0x2b3160 cmpeq r2, #71
 *   @0x2b3164 bne 0x2b3170 <jpeg_consume_input+0x268>
 *   @0x2b3168 cmp r6, #66
 *   @0x2b316c beq 0x2b31ac <jpeg_consume_input+0x2a4>
 *   @0x2b3170 ldr r3, [r4]
 *   @0x2b3174 mov lr, #111
 *   @0x2b3178 mov r0, r4
 *   @0x2b317c mov r1, #1
 *   @0x2b3180 str r12, [r3, #0x18]
 *   @0x2b3184 str r2, [r3, #0x1c]
 *   @0x2b3188 str r6, [r3, #0x20]
 *   @0x2b318c str lr, [r3, #0x14]
 *   @0x2b3190 ldr r3, [r3, #0x4]
 *   @0x2b3194 blx r3
 *   @0x2b3198 mov r3, #3
 *   @0x2b319c str r3, [r4, #0x28]
 *   @0x2b31a0 b 0x2b30d0 <jpeg_consume_input+0x1c8>
 *   @0x2b31a4 str r6, [r4, #0x28]
 *   @0x2b31a8 b 0x2b312c <jpeg_consume_input+0x224>
 *   @0x2b31ac mov r3, #2
 *   @0x2b31b0 str r3, [r4, #0x28]
 *   @0x2b31b4 b 0x2b30d0 <jpeg_consume_input+0x1c8>
 *
 * ══ §42/43 GraphicsPerf::BeginDebugDraw()  0x17b114  size 684  171 条（0x17b114..0x17b3c0）
 * @func 0x17b114 0x17b3c0  size 684  171 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x17b128→0x4859c8, 0x17b14c→0x49932a, 0x17b16c→0x499324, 0x17b184→0x499329, 0x17b1a4→0x499328, 0x17b1a8→0x3f26c0, 0x17b1ac→0x4a2088, 0x17b1b4→0x3f26bc
 * 调用序列: RenderStateManager::SetRenderState(eRenderState, unsigned int)×5 / RenderStateManager::GetRenderState(eRenderState)×4 / Graphics::SetMatrix(eMatrix, float*)×3 / Graphics::GetMatrix(eMatrix, float*)×2 / RenderStateManager::SaveStates() / yyMatrix::OrthoLH(yyMatrix*, float, float, float, float) / Graphics::SetTexture(int, void*)
 * 字段偏移 top8: 0x1e4×3 / 0x5c×2 / 0x254×1 / 0x250×1 / 0x230×1 / 0x214×1 / 0x200×1 / 0x1e0×1
 * VFP 指令 27 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17b114 push {r4, r5, r6, r7, r8, lr}
 *   @0x17b118 vpush {d8}
 *   @0x17b11c mov r6, #1
 *   @0x17b120 ldr r4, [pc, #0x254]
 *   @0x17b124 sub sp, sp, #72
 *   @0x17b128 ldr r3, [pc, #0x250]
 *   @0x17b12c vmov.f32 s16, #1.000000e+00
 *   @0x17b130 add r4, pc, r4
 *   @0x17b134 ldr r5, [r4, r3]
 *   @0x17b138 mov r0, r5
 *   @0x17b13c bl 0x167fcc <_ZN18RenderStateManager10SaveStatesEv>
 *   @0x17b140 mov r1, r6
 *   @0x17b144 mov r0, r5
 *   @0x17b148 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState>
 *   @0x17b14c ldr r3, [pc, #0x230]
 *   @0x17b150 mov r1, #8
 *   @0x17b154 ldr r3, [r4, r3]
 *   @0x17b158 adds r2, r0, #0
 *   @0x17b15c mov r0, r5
 *   @0x17b160 movne r2, #1
 *   @0x17b164 strb r2, [r3]
 *   @0x17b168 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState>
 *   @0x17b16c ldr r3, [pc, #0x214]
 *   @0x17b170 mov r1, #21
 *   @0x17b174 ldr r3, [r4, r3]
 *   @0x17b178 str r0, [r3]
 *   @0x17b17c mov r0, r5
 *   @0x17b180 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState>
 *   @0x17b184 ldr r3, [pc, #0x200]
 *   @0x17b188 mov r1, #13
 *   @0x17b18c ldr r3, [r4, r3]
 *   @0x17b190 adds r2, r0, #0
 *   @0x17b194 mov r0, r5
 *   @0x17b198 movne r2, #1
 *   @0x17b19c strb r2, [r3]
 *   @0x17b1a0 bl 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState>
 *   @0x17b1a4 ldr r3, [pc, #0x1e4]
 *   @0x17b1a8 ldr r2, [pc, #0x1e4]
 *   @0x17b1ac ldr r1, [pc, #0x1e4]
 *   @0x17b1b0 ldr r12, [r4, r3]
 *   @0x17b1b4 ldr r3, [pc, #0x1e0]
 *   @0x17b1b8 adds r0, r0, #0
 *   @0x17b1bc movne r0, #1
 *   @0x17b1c0 strb r0, [r12]
 *   @0x17b1c4 ldr r2, [r4, r2]
 *   @0x17b1c8 mov r0, r6
 *   @0x17b1cc ldr r3, [r4, r3]
 *   @0x17b1d0 ldr r1, [r4, r1]
 *   @0x17b1d4 ldr r8, [r2]
 *   @0x17b1d8 ldr r7, [r3]
 *   @0x17b1dc bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf>
 *   @0x17b1e0 ldr r3, [pc, #0x1b8]
 *   @0x17b1e4 mov r0, #0
 *   @0x17b1e8 ldr r1, [r4, r3]
 *   @0x17b1ec bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf>
 *   @0x17b1f0 vmov s11, r8
 *   @0x17b1f4 vmov s13, r7
 *   @0x17b1f8 add r8, r8, r8, lsr #31
 *   @0x17b1fc vcvt.f32.s32 s17, s11
 *   @0x17b200 add r2, r7, r7, lsr #31
 *   @0x17b204 asr r8, r8, r6
 *   @0x17b208 add r1, sp, #8
 *   @0x17b20c rsb r8, r8, #0
 *   @0x17b210 asr r2, r2, r6
 *   @0x17b214 rsb r2, r2, #0
 *   @0x17b218 mov r0, #0
 *   @0x17b21c vmov s11, r8
 *   @0x17b220 mov r3, #0
 *   @0x17b224 vstr s16, [sp, #68]
 *   @0x17b228 str r3, [sp, #0x34]
 *   @0x17b22c str r3, [sp, #0x2c]
 *   @0x17b230 vstr s16, [sp, #48]
 *   @0x17b234 vcvt.f32.s32 s15, s13
 *   @0x17b238 str r3, [sp, #0x28]
 *   @0x17b23c str r3, [sp, #0x24]
 *   @0x17b240 vstr s16, [sp, #28]
 *   @0x17b244 str r3, [sp, #0x20]
 *   @0x17b248 vstr s16, [sp, #8]
 *   @0x17b24c str r3, [sp, #0x18]
 *   @0x17b250 mov r12, #0
 *   @0x17b254 str r3, [sp, #0x14]
 *   @0x17b258 movt r12, #0x467a
 *   @0x17b25c str r3, [sp, #0x10]
 *   @0x17b260 str r3, [sp, #0xc]
 *   @0x17b264 vdiv.f32 s14, s16, s17
 *   @0x17b268 str r12, [sp, #0x40]
 *   @0x17b26c vdiv.f32 s15, s16, s15
 *   @0x17b270 vcvt.f32.s32 s12, s11
 *   @0x17b274 vmov s11, r2
 *   @0x17b278 vcvt.f32.s32 s13, s11
 *   @0x17b27c vsub.f32 s14, s12, s14
 *   @0x17b280 vadd.f32 s15, s13, s15
 *   @0x17b284 vstr s14, [sp, #56]
 *   @0x17b288 vstr s15, [sp, #60]
 *   @0x17b28c bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf>
 *   @0x17b290 ldr r1, [pc, #0x10c]
 *   @0x17b294 rsb r2, r7, #0
 *   @0x17b298 ldr lr, [pc, #0x108]
 *   @0x17b29c mov r3, #0
 *   @0x17b2a0 vmov s13, r2
 *   @0x17b2a4 ldr r12, [pc, #0x100]
 *   @0x17b2a8 ldr r8, [r4, r1]
 *   @0x17b2ac movt r3, #0x46fa
 *   @0x17b2b0 vcvt.f32.s32 s13, s13
 *   @0x17b2b4 ldr r0, [pc, #0xf4]
 *   @0x17b2b8 vmov r1, s17
 *   @0x17b2bc strb r6, [r8]
 *   @0x17b2c0 ldr lr, [r4, lr]
 *   @0x17b2c4 vstr s16, [lr]
 *   @0x17b2c8 ldr r12, [r4, r12]
 *   @0x17b2cc str r3, [r12]
 *   @0x17b2d0 ldr r7, [r4, r0]
 *   @0x17b2d4 vmov r2, s13
 *   @0x17b2d8 str r3, [sp]
 *   @0x17b2dc mov r0, r7
 *   @0x17b2e0 vmov r3, s16
 *   @0x17b2e4 bl 0x27b274 <_ZN8yyMatrix7OrthoLHEPS_ffff>
 *   @0x17b2e8 mov r0, r6
 *   @0x17b2ec mov r1, r7
 *   @0x17b2f0 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf>
 *   @0x17b2f4 mov r0, r5
 *   @0x17b2f8 mov r1, #8
 *   @0x17b2fc mov r2, #0
 *   @0x17b300 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x17b304 mov r0, r5
 *   @0x17b308 mov r1, r6
 *   @0x17b30c mov r2, #0
 *   @0x17b310 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x17b314 mov r0, r5
 *   @0x17b318 mov r1, #21
 *   @0x17b31c mov r2, #0
 *   @0x17b320 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x17b324 mov r0, r5
 *   @0x17b328 mov r1, #13
 *   @0x17b32c mov r2, #0
 *   @0x17b330 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x17b334 mov r2, r6
 *   @0x17b338 mov r0, r5
 *   @0x17b33c mov r1, #12
 *   @0x17b340 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x17b344 ldr r3, [pc, #0x68]
 *   @0x17b348 mov r0, #2
 *   @0x17b34c ldr r1, [r4, r3]
 *   @0x17b350 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf>
 *   @0x17b354 ldr r2, [pc, #0x5c]
 *   @0x17b358 ldr r3, [pc, #0x5c]
 *   @0x17b35c ldr r2, [r4, r2]
 *   @0x17b360 ldr r3, [r4, r3]
 *   @0x17b364 ldr r0, [r2]
 *   @0x17b368 ldr r1, [r3]
 *   @0x17b36c bl 0x182a28 <_ZN8Graphics10SetTextureEiPv>
 *   @0x17b370 add sp, sp, #72
 *   @0x17b374 vpop {d8}
 *   @0x17b378 pop {r4, r5, r6, r7, r8, pc}
 *   @0x17b37c eoreq r6, r7, r0, lsr #22
 *   @0x17b380 .word 0xffffc0a8
 *   @0x17b384 .word 0xffffe6f4
 *   @0x17b388 .word 0xffffe6f8
 *   @0x17b38c .word 0xffffe6fc
 *   @0x17b390 .word 0xffffe700
 *   @0x17b394 .word 0xffffe24c
 *   @0x17b398 .word 0xffffe704
 *   @0x17b39c .word 0xffffe250
 *   @0x17b3a0 .word 0xffffe708
 *   @0x17b3a4 .word 0xffffe480
 *   @0x17b3a8 .word 0xffffe484
 *   @0x17b3ac .word 0xffffe488
 *   @0x17b3b0 .word 0xffffe70c
 *   @0x17b3b4 .word 0xffffe710
 *   @0x17b3b8 .word 0xffffe4d4
 *   @0x17b3bc .word 0xffffe648
 *
 * ══ §43/43 SoundHardware::SetVolume(void*, float, int)  0x220be0  size 432  94 条（0x220be0..0x220d90）｜其中 14 条已由别的卡落锚，本节不再重复
 * @func 0x220be0 0x220d90  size 432  94 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x220bf4→0x755361, 0x220c10→0x755363, 0x220c24→0x755362, 0x220c40→0x5428e8, 0x220c54→0x54298c, 0x220c9c→0x755360, 0x220cd4→0x3eb70c, 0x220d04→0x5428c0
 * 调用序列: __divsi3×2 / CTimingSource::GetFPS()
 * 字段偏移 top8: 0x98×3 / 0xc×2 / 0x164×1 / 0x160×1 / 0x148×1 / 0x138×1 / 0x120×1 / 0x110×1
 * VFP 指令 18 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x220be0 push {r4, r5, r6, lr}
 *   @0x220be4 vpush {d8}
 *   @0x220be8 mov r5, r1
 *   @0x220bec ldr r4, [pc, #0x164]
 *   @0x220bf0 vmov s16, r2
 *   @0x220bf4 ldr r1, [pc, #0x160]
 *   @0x220bf8 mov r6, r3
 *   @0x220bfc add r4, pc, r4
 *   @0x220c00 ldr r2, [r4, r1]
 *   @0x220c04 ldrb r2, [r2]
 *   @0x220c24 ldr r3, [pc, #0x138]
 *   @0x220c28 ldr r3, [r4, r3]
 *   @0x220c2c ldrb r3, [r3]
 *   @0x220c30 cmp r3, #0
 *   @0x220c34 bne 0x220ccc <_ZN13SoundHardware9SetVolumeEPvfi+0xec>
 *   @0x220c54 ldr r3, [pc, #0x110]
 *   @0x220c58 ldr r3, [r4, r3]
 *   @0x220c5c ldr r3, [r3]
 *   @0x220c60 cmp r3, #0
 *   @0x220c64 moveq r1, #33
 *   @0x220c68 beq 0x220c84 <_ZN13SoundHardware9SetVolumeEPvfi+0xa4>
 *   @0x220c6c ldr r1, [r3, #0xc]
 *   @0x220c70 mov r0, #1000
 *   @0x220c74 bl 0x318d10 <__divsi3>
 *   @0x220c78 cmp r0, #1
 *   @0x220c7c movge r1, r0
 *   @0x220c80 movlt r1, #1
 *   @0x220c84 mov r0, r6
 *   @0x220c88 bl 0x318d10 <__divsi3>
 *   @0x220c8c cmp r0, #1
 *   @0x220c90 movlt r0, #1
 *   @0x220c94 cmp r5, #1
 *   @0x220c98 beq 0x220d20 <_ZN13SoundHardware9SetVolumeEPvfi+0x140>
 *   @0x220c9c ldr r3, [pc, #0xcc]
 *   @0x220ca0 ldr r3, [r4, r3]
 *   @0x220ca4 ldrb r3, [r3]
 *   @0x220ca8 cmp r3, #0
 *   @0x220cac bne 0x220ccc <_ZN13SoundHardware9SetVolumeEPvfi+0xec>
 *   @0x220cb0 vldr s15, [r5, #24]
 *   @0x220cb4 vsub.f32 s16, s16, s15
 *   @0x220cb8 vmov s14, r0
 *   @0x220cbc str r0, [r5, #0x20]
 *   @0x220cc0 vcvt.f32.s32 s15, s14
 *   @0x220cc4 vdiv.f32 s16, s16, s15
 *   @0x220cc8 vstr s16, [r5, #28]
 *   @0x220ccc vpop {d8}
 *   @0x220cd0 pop {r4, r5, r6, pc}
 *   @0x220cd4 ldr r3, [pc, #0x98]
 *   @0x220cd8 ldr r2, [pc, #0x98]
 *   @0x220cdc ldr r1, [pc, #0x98]
 *   @0x220ce0 ldr r3, [r4, r3]
 *   @0x220ce4 add r2, pc, r2
 *   @0x220ce8 add r1, pc, r1
 *   @0x220cec add r2, r2, #132
 *   @0x220cf0 ldr r0, [r3]
 *   @0x220cf4 ldr r3, [r0]
 *   @0x220cf8 ldr r3, [r3, #0xc]
 *   @0x220cfc blx r3
 *   @0x220d00 b 0x220c10 <_ZN13SoundHardware9SetVolumeEPvfi+0x30>
 *   @0x220d04 ldr r3, [pc, #0x74]
 *   @0x220d08 ldr r0, [r4, r3]
 *   @0x220d0c bl 0x214808 <_ZN13CTimingSource6GetFPSEv>
 *   @0x220d10 vmov d7, r0, r1
 *   @0x220d14 vcvt.s32.f64 s15, d7
 *   @0x220d18 vmov r1, s15
 *   @0x220d1c b 0x220c70 <_ZN13SoundHardware9SetVolumeEPvfi+0x90>
 *   @0x220d20 ldr r1, [pc, #0x5c]
 *   @0x220d24 vmov s14, r0
 *   @0x220d28 ldr r2, [pc, #0x58]
 *   @0x220d2c vcvt.f32.s32 s15, s14
 *   @0x220d30 ldr r3, [pc, #0x54]
 *   @0x220d34 ldr r1, [r4, r1]
 *   @0x220d38 vldr s14, [r1]
 *   @0x220d3c ldr r2, [r4, r2]
 *   @0x220d40 vsub.f32 s16, s16, s14
 *   @0x220d44 vdiv.f32 s16, s16, s15
 *   @0x220d48 vstr s16, [r2]
 *   @0x220d4c ldr r3, [r4, r3]
 *   @0x220d50 str r0, [r3]
 *   @0x220d54 b 0x220ccc <_ZN13SoundHardware9SetVolumeEPvfi+0xec>
 *   @0x220d58 andseq r1, sp, r4, asr r0
 *   @0x220d5c .word 0xfffff7d8
 *   @0x220d60 .word 0xffffd3fc
 *   @0x220d64 .word 0xfffff7e0
 *   @0x220d68 .word 0xffffbcd4
 *   @0x220d6c .word 0xffffbcd8
 *   @0x220d70 .word 0xfffff7e4
 *   @0x220d74 .word 0xffffbac4
 *   @0x220d78 andseq sp, r3, r4, ror #5
 *   @0x220d7c andseq r3, r3, r4, asr r11
 *   @0x220d80 .word 0xffffbcdc
 *   @0x220d84 .word 0xfffff7e8
 *   @0x220d88 .word 0xfffff7ec
 *   @0x220d8c .word 0xfffff7f0
 */
