/* cally 逆向卡：All_33 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 36 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/36 Motion_Grid_to_dsGrid(int, int)  0x19c358  size 924  231 条（0x19c358..0x19c6f4）
 * @func 0x19c358 0x19c6f4  size 924  231 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / Motion_Grid_to_dsGrid(int, int)+0x34×2 / Error_Show_Action(char const*, bool)×2 / FREE_RValue__Pre(RValue*)×2 / GetTheGrids(int&)
 * 字段偏移 top8: 0x4×22 / 0x8×8 / 0x14×7 / 0xc×5 / 0x18×4 / 0x1c×4 / 0x2×3 / 0x364×1
 * VFP 指令 5 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19c358 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x19c35c sub sp, sp, #60
 *   @0x19c360 mov r4, r0
 *   @0x19c364 add r0, sp, #36
 *   @0x19c368 mov r5, r1
 *   @0x19c36c bl 0x10026c <_Z11GetTheGridsRi>
 *   @0x19c370 cmp r4, #0
 *   @0x19c374 blt 0x19c38c <_Z21Motion_Grid_to_dsGridii+0x34>
 *   @0x19c378 ldr r3, [pc, #0x364]
 *   @0x19c37c ldr r3, [pc, r3]
 *   @0x19c380 ldr r3, [r3]
 *   @0x19c384 cmp r4, r3
 *   @0x19c388 blt 0x19c3a4 <_Z21Motion_Grid_to_dsGridii+0x4c>
 *   @0x19c38c ldr r0, [pc, #0x354]
 *   @0x19c390 mov r1, #0
 *   @0x19c394 add r0, pc, r0
 *   @0x19c398 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x19c39c add sp, sp, #60
 *   @0x19c3a0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x19c3a4 cmp r5, #0
 *   @0x19c3a8 blt 0x19c38c <_Z21Motion_Grid_to_dsGridii+0x34>
 *   @0x19c3ac ldr r3, [sp, #0x24]
 *   @0x19c3b0 cmp r5, r3
 *   @0x19c3b4 bge 0x19c38c <_Z21Motion_Grid_to_dsGridii+0x34>
 *   @0x19c3b8 ldr r3, [pc, #0x32c]
 *   @0x19c3bc ldr r8, [r0, r5, lsl #2]
 *   @0x19c3c0 ldr r3, [pc, r3]
 *   @0x19c3c4 ldr r3, [r3]
 *   @0x19c3c8 ldr r12, [r3, r4, lsl #2]
 *   @0x19c3cc cmp r12, #0
 *   @0x19c3d0 cmpne r8, #0
 *   @0x19c3d4 movne r1, #0
 *   @0x19c3d8 moveq r1, #1
 *   @0x19c3dc beq 0x19c38c <_Z21Motion_Grid_to_dsGridii+0x34>
 *   @0x19c3e0 ldr r2, [r12, #0x14]
 *   @0x19c3e4 ldr r3, [r12, #0x18]
 *   @0x19c3e8 str r2, [sp, #0x14]
 *   @0x19c3ec str r3, [sp, #0x1c]
 *   @0x19c3f0 ldr r2, [r8, #0x8]
 *   @0x19c3f4 ldr r3, [r8, #0x4]
 *   @0x19c3f8 ldr r4, [sp, #0x1c]
 *   @0x19c3fc ldr r0, [sp, #0x14]
 *   @0x19c400 cmp r0, r3
 *   @0x19c404 cmpeq r4, r2
 *   @0x19c408 moveq r3, #0
 *   @0x19c40c movne r3, #1
 *   @0x19c410 bne 0x19c6d4 <_Z21Motion_Grid_to_dsGridii+0x37c>
 *   @0x19c414 cmp r4, #0
 *   @0x19c418 ble 0x19c39c <_Z21Motion_Grid_to_dsGridii+0x44>
 *   @0x19c41c mov r11, r3
 *   @0x19c420 ldr r2, [sp, #0x14]
 *   @0x19c424 cmp r2, #0
 *   @0x19c428 ble 0x19c5bc <_Z21Motion_Grid_to_dsGridii+0x264>
 *   @0x19c42c ldr r4, [sp, #0x30]
 *   @0x19c430 mov r6, #0
 *   @0x19c434 mov r10, r12
 *   @0x19c438 mov r9, r3
 *   @0x19c43c str r4, [sp, #0x18]
 *   @0x19c440 b 0x19c500 <_Z21Motion_Grid_to_dsGridii+0x1a8>
 *   @0x19c444 ldr r3, [r10, #0x18]
 *   @0x19c448 cmp r3, r9
 *   @0x19c44c ble 0x19c50c <_Z21Motion_Grid_to_dsGridii+0x1b4>
 *   @0x19c450 mla r3, r3, r6, r9
 *   @0x19c454 ldr r2, [r10, #0x1c]
 *   @0x19c458 ldr r3, [r2, r3, lsl #2]
 *   @0x19c45c vmov s15, r3
 *   @0x19c460 vcvt.f64.s32 d7, s15
 *   @0x19c464 vstr d7, [sp, #8]
 *   @0x19c468 ldm r8, {r5, r7}
 *   @0x19c46c mla r7, r7, r9, r6
 *   @0x19c470 add r4, r5, r7, lsl #4
 *   @0x19c474 ldr r3, [r4, #0xc]
 *   @0x19c478 sub r3, r3, #1
 *   @0x19c47c bic r3, r3, #-16777216
 *   @0x19c480 bic r3, r3, #3
 *   @0x19c484 cmp r3, #0
 *   @0x19c488 beq 0x19c550 <_Z21Motion_Grid_to_dsGridii+0x1f8>
 *   @0x19c48c str r11, [r4, #0x8]
 *   @0x19c490 mov r0, #5
 *   @0x19c494 str r0, [r4, #0xc]
 *   @0x19c498 str r11, [r5, r7, lsl #4]
 *   @0x19c49c ldm r8, {r5, r7}
 *   @0x19c4a0 mla r7, r7, r9, r6
 *   @0x19c4a4 add r4, r5, r7, lsl #4
 *   @0x19c4a8 ldr r2, [r4, #0xc]
 *   @0x19c4ac bic r3, r2, #-16777216
 *   @0x19c4b0 cmp r3, #1
 *   @0x19c4b4 beq 0x19c518 <_Z21Motion_Grid_to_dsGridii+0x1c0>
 *   @0x19c4b8 cmp r3, #2
 *   @0x19c4bc bne 0x19c4d4 <_Z21Motion_Grid_to_dsGridii+0x17c>
 *   @0x19c4c0 sub r2, r2, #1
 *   @0x19c4c4 bic r2, r2, #-16777216
 *   @0x19c4c8 bic r2, r2, #3
 *   @0x19c4cc cmp r2, #0
 *   @0x19c4d0 beq 0x19c5d0 <_Z21Motion_Grid_to_dsGridii+0x278>
 *   @0x19c4d4 ldr r3, [sp, #0x18]
 *   @0x19c4d8 add r6, r6, #1
 *   @0x19c4dc ldr r2, [sp, #0x14]
 *   @0x19c4e0 str r11, [r4, #0xc]
 *   @0x19c4e4 str r3, [r4, #0x8]
 *   @0x19c4e8 cmp r6, r2
 *   @0x19c4ec ldr r3, [sp, #0xc]
 *   @0x19c4f0 ldr r2, [sp, #0x8]
 *   @0x19c4f4 str r2, [r5, r7, lsl #4]
 *   @0x19c4f8 str r3, [r4, #0x4]
 *   @0x19c4fc beq 0x19c5b4 <_Z21Motion_Grid_to_dsGridii+0x25c>
 *   @0x19c500 ldr r3, [r10, #0x14]
 *   @0x19c504 cmp r3, r6
 *   @0x19c508 bgt 0x19c444 <_Z21Motion_Grid_to_dsGridii+0xec>
 *   @0x19c50c vmov.f64 d7, #-1.000000e+00
 *   @0x19c510 vstr d7, [sp, #8]
 *   @0x19c514 b 0x19c468 <_Z21Motion_Grid_to_dsGridii+0x110>
 *   @0x19c518 ldr r3, [r5, r7, lsl #4]
 *   @0x19c51c cmp r3, #0
 *   @0x19c520 beq 0x19c548 <_Z21Motion_Grid_to_dsGridii+0x1f0>
 *   @0x19c524 str r3, [sp]
 *   @0x19c528 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x19c52c ldr r3, [sp]
 *   @0x19c530 ldr r2, [r3, #0x4]
 *   @0x19c534 sub r2, r2, #1
 *   @0x19c538 str r2, [r3, #0x4]
 *   @0x19c53c cmp r2, #0
 *   @0x19c540 beq 0x19c55c <_Z21Motion_Grid_to_dsGridii+0x204>
 *   @0x19c544 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x19c548 str r11, [r5, r7, lsl #4]
 *   @0x19c54c b 0x19c4d4 <_Z21Motion_Grid_to_dsGridii+0x17c>
 *   @0x19c550 mov r0, r4
 *   @0x19c554 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x19c558 b 0x19c48c <_Z21Motion_Grid_to_dsGridii+0x134>
 *   @0x19c55c ldr r0, [r3]
 *   @0x19c560 str r2, [sp, #0x4]
 *   @0x19c564 str r3, [sp]
 *   @0x19c568 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x19c56c ldr r3, [sp]
 *   @0x19c570 ldr r2, [sp, #0x4]
 *   @0x19c574 str r2, [r3]
 *   @0x19c578 str r2, [r3, #0x8]
 *   @0x19c57c str r3, [sp]
 *   @0x19c580 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x19c584 ldr r3, [sp]
 *   @0x19c588 ldr r2, [r3, #0x4]
 *   @0x19c58c sub r2, r2, #1
 *   @0x19c590 str r2, [r3, #0x4]
 *   @0x19c594 cmp r2, #0
 *   @0x19c598 beq 0x19c5dc <_Z21Motion_Grid_to_dsGridii+0x284>
 *   @0x19c59c str r3, [sp]
 *   @0x19c5a0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x19c5a4 ldr r3, [sp]
 *   @0x19c5a8 mov r0, r3
 *   @0x19c5ac bl 0x27d1d0 <_ZdlPv>
 *   @0x19c5b0 b 0x19c544 <_Z21Motion_Grid_to_dsGridii+0x1ec>
 *   @0x19c5b4 mov r12, r10
 *   @0x19c5b8 mov r3, r9
 *   @0x19c5bc ldr r4, [sp, #0x1c]
 *   @0x19c5c0 add r3, r3, #1
 *   @0x19c5c4 cmp r3, r4
 *   @0x19c5c8 bne 0x19c420 <_Z21Motion_Grid_to_dsGridii+0xc8>
 *   @0x19c5cc b 0x19c39c <_Z21Motion_Grid_to_dsGridii+0x44>
 *   @0x19c5d0 mov r0, r4
 *   @0x19c5d4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x19c5d8 b 0x19c4d4 <_Z21Motion_Grid_to_dsGridii+0x17c>
 *   @0x19c5dc ldr r0, [r3]
 *   @0x19c5e0 str r2, [sp, #0x4]
 *   @0x19c5e4 str r3, [sp]
 *   @0x19c5e8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x19c5ec ldr r3, [sp]
 *   @0x19c5f0 ldr r2, [sp, #0x4]
 *   @0x19c5f4 str r2, [r3]
 *   @0x19c5f8 str r2, [r3, #0x8]
 *   @0x19c5fc str r3, [sp]
 *   @0x19c600 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x19c604 ldr r3, [sp]
 *   @0x19c608 ldr r2, [r3, #0x4]
 *   @0x19c60c sub r2, r2, #1
 *   @0x19c610 str r2, [r3, #0x4]
 *   @0x19c614 cmp r2, #0
 *   @0x19c618 beq 0x19c638 <_Z21Motion_Grid_to_dsGridii+0x2e0>
 *   @0x19c61c str r3, [sp]
 *   @0x19c620 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x19c624 ldr r3, [sp]
 *   @0x19c628 mov r0, r3
 *   @0x19c62c bl 0x27d1d0 <_ZdlPv>
 *   @0x19c630 ldr r3, [sp]
 *   @0x19c634 b 0x19c59c <_Z21Motion_Grid_to_dsGridii+0x244>
 *   @0x19c638 ldr r0, [r3]
 *   @0x19c63c str r2, [sp, #0x4]
 *   @0x19c640 str r3, [sp]
 *   @0x19c644 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x19c648 ldr r3, [sp]
 *   @0x19c64c ldr r2, [sp, #0x4]
 *   @0x19c650 str r2, [r3]
 *   @0x19c654 str r2, [r3, #0x8]
 *   @0x19c658 str r3, [sp]
 *   @0x19c65c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x19c660 ldr r3, [sp]
 *   @0x19c664 ldr r2, [r3, #0x4]
 *   @0x19c668 sub r2, r2, #1
 *   @0x19c66c str r2, [r3, #0x4]
 *   @0x19c670 cmp r2, #0
 *   @0x19c674 beq 0x19c694 <_Z21Motion_Grid_to_dsGridii+0x33c>
 *   @0x19c678 str r3, [sp]
 *   @0x19c67c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x19c680 ldr r3, [sp]
 *   @0x19c684 mov r0, r3
 *   @0x19c688 bl 0x27d1d0 <_ZdlPv>
 *   @0x19c68c ldr r3, [sp]
 *   @0x19c690 b 0x19c61c <_Z21Motion_Grid_to_dsGridii+0x2c4>
 *   @0x19c694 ldr r0, [r3]
 *   @0x19c698 str r2, [sp, #0x4]
 *   @0x19c69c str r3, [sp]
 *   @0x19c6a0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x19c6a4 ldr r3, [sp]
 *   @0x19c6a8 ldr r2, [sp, #0x4]
 *   @0x19c6ac mov r0, r3
 *   @0x19c6b0 str r2, [r3]
 *   @0x19c6b4 str r2, [r3, #0x8]
 *   @0x19c6b8 str r3, [sp]
 *   @0x19c6bc bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x19c6c0 ldr r3, [sp]
 *   @0x19c6c4 mov r0, r3
 *   @0x19c6c8 bl 0x27d1d0 <_ZdlPv>
 *   @0x19c6cc ldr r3, [sp]
 *   @0x19c6d0 b 0x19c678 <_Z21Motion_Grid_to_dsGridii+0x320>
 *   @0x19c6d4 ldr r0, [pc, #0x14]
 *   @0x19c6d8 add r0, pc, r0
 *   @0x19c6dc bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x19c6e0 b 0x19c39c <_Z21Motion_Grid_to_dsGridii+0x44>
 *   @0x19c6e4 eoreq r4, r5, r0, lsr r3
 *   @0x19c6e8 ldrsheq r0, [r11], -r0
 *   @0x19c6ec .word 0x002542f0
 *   @0x19c6f0 ldrsbeq r0, [r11], -r0
 *
 * ══ §2/36 b2ParticleSystem::RayCast(b2RayCastCallback*, b2Vec2 const&, b2Vec2 const&) const  0x2d9c4c  size 924  231 条（0x2d9c4c..0x2d9fe8）
 * @func 0x2d9c4c 0x2d9fe8  size 924  231 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ParticleSystem::RayCast(b2RayCastCallback*, b2Vec2 const&, b2Vec2 const&) const+0x320×2 / 0xb6700×2 / b2ParticleSystem::RayCast(b2RayCastCallback*, b2Vec2 const&, b2Vec2 const&) const+0xe0 / b2ParticleSystem::RayCast(b2RayCastCallback*, b2Vec2 const&, b2Vec2 const&) const+0xd0 / b2ParticleSystem::RayCast(b2RayCastCallback*, b2Vec2 const&, b2Vec2 const&) const+0x188 / b2ParticleSystem::RayCast(b2RayCastCallback*, b2Vec2 const&, b2Vec2 const&) const+0x178 / b2ParticleSystem::RayCast(b2RayCastCallback*, b2Vec2 const&, b2Vec2 const&) const+0x268 / b2ParticleSystem::RayCast(b2RayCastCallback*, b2Vec2 const&, b2Vec2 const&) const+0x1bc
 * 字段偏移 top8: 0xc×5 / 0x4×4 / 0x68×1 / 0x70×1 / 0x-8×1 / 0x38×1
 * VFP 指令 128 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d9c4c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2d9c50 vpush {d8, d9, d10, d11, d12, d13}
 *   @0x2d9c54 mov r8, r1
 *   @0x2d9c58 ldr r1, [r0, #0x68]
 *   @0x2d9c5c sub sp, sp, #32
 *   @0x2d9c60 mov r7, r0
 *   @0x2d9c64 mov r6, r2
 *   @0x2d9c68 cmp r1, #0
 *   @0x2d9c6c beq 0x2d9f6c <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x320>
 *   @0x2d9c70 vmov.f32 s13, #1.000000e+00
 *   @0x2d9c74 vldr s17, [r2]
 *   @0x2d9c78 vldr s21, [r3]
 *   @0x2d9c7c vldr s15, [r0, #28]
 *   @0x2d9c80 vldr s18, [r2, #4]
 *   @0x2d9c84 vldr s22, [r3, #4]
 *   @0x2d9c88 vldr s11, [pc, #840]
 *   @0x2d9c8c vldr s14, [pc, #840]
 *   @0x2d9c90 vldr s12, [pc, #840]
 *   @0x2d9c94 ldr r5, [r0, #0x70]
 *   @0x2d9c98 sbfx r4, r1, #0x0, #0x1d
 *   @0x2d9c9c add r9, r5, r1, lsl #3
 *   @0x2d9ca0 vcmpe.f32 s17, s21
 *   @0x2d9ca4 vmov.f32 s9, s13
 *   @0x2d9ca8 vmrs APSR_nzcv, fpscr
 *   @0x2d9cac vmovpl.f32 s10, s21
 *   @0x2d9cb0 vmovmi.f32 s10, s17
 *   @0x2d9cb4 vnmls.f32 s9, s15, s10
 *   @0x2d9cb8 vcmpe.f32 s18, s22
 *   @0x2d9cbc vmov.f32 s10, s9
 *   @0x2d9cc0 vmrs APSR_nzcv, fpscr
 *   @0x2d9cc4 vmovpl.f32 s9, s22
 *   @0x2d9cc8 vmovmi.f32 s9, s18
 *   @0x2d9ccc vnmls.f32 s13, s15, s9
 *   @0x2d9cd0 vmla.f32 s14, s10, s11
 *   @0x2d9cd4 vadd.f32 s13, s13, s12
 *   @0x2d9cd8 vcvt.u32.f32 s14, s14
 *   @0x2d9cdc vcvt.u32.f32 s13, s13
 *   @0x2d9ce0 vmov r3, s14
 *   @0x2d9ce4 vmov r2, s13
 *   @0x2d9ce8 add r0, r3, r2, lsl #20
 *   @0x2d9cec cmp r4, #0
 *   @0x2d9cf0 ble 0x2d9d2c <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0xe0>
 *   @0x2d9cf4 asr r3, r4, #1
 *   @0x2d9cf8 add r2, r5, r3, lsl #3
 *   @0x2d9cfc ldr r12, [r2, #0x4]
 *   @0x2d9d00 cmp r0, r12
 *   @0x2d9d04 bls 0x2d9d1c <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0xd0>
 *   @0x2d9d08 b 0x2d9f90 <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x344>
 *   @0x2d9d0c ldr r1, [r2, #0x4]
 *   @0x2d9d10 cmp r0, r1
 *   @0x2d9d14 bhi 0x2d9f98 <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x34c>
 *   @0x2d9d18 mov r3, r12
 *   @0x2d9d1c asr r12, r3, #1
 *   @0x2d9d20 cmp r3, #0
 *   @0x2d9d24 add r2, r5, r12, lsl #3
 *   @0x2d9d28 bne 0x2d9d0c <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0xc0>
 *   @0x2d9d2c vmov.f32 s13, #1.000000e+00
 *   @0x2d9d30 vldr s11, [pc, #672]
 *   @0x2d9d34 vldr s14, [pc, #672]
 *   @0x2d9d38 vldr s12, [pc, #672]
 *   @0x2d9d3c rsb r1, r5, r9
 *   @0x2d9d40 mov r4, r5
 *   @0x2d9d44 asr r1, r1, #3
 *   @0x2d9d48 vcmpe.f32 s17, s21
 *   @0x2d9d4c vmov.f32 s9, s13
 *   @0x2d9d50 vmrs APSR_nzcv, fpscr
 *   @0x2d9d54 vmovle.f32 s10, s21
 *   @0x2d9d58 vmovgt.f32 s10, s17
 *   @0x2d9d5c vmla.f32 s9, s15, s10
 *   @0x2d9d60 vcmpe.f32 s18, s22
 *   @0x2d9d64 vmov.f32 s10, s9
 *   @0x2d9d68 vmrs APSR_nzcv, fpscr
 *   @0x2d9d6c vmovle.f32 s9, s22
 *   @0x2d9d70 vmovgt.f32 s9, s18
 *   @0x2d9d74 vmla.f32 s13, s15, s9
 *   @0x2d9d78 vmla.f32 s14, s10, s11
 *   @0x2d9d7c vadd.f32 s13, s13, s12
 *   @0x2d9d80 vcvt.u32.f32 s14, s14
 *   @0x2d9d84 vcvt.u32.f32 s13, s13
 *   @0x2d9d88 vmov r3, s14
 *   @0x2d9d8c vmov r2, s13
 *   @0x2d9d90 add r0, r3, r2, lsl #20
 *   @0x2d9d94 cmp r1, #0
 *   @0x2d9d98 ble 0x2d9dd4 <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x188>
 *   @0x2d9d9c asr r3, r1, #1
 *   @0x2d9da0 add r2, r5, r3, lsl #3
 *   @0x2d9da4 ldr r12, [r2, #0x4]
 *   @0x2d9da8 cmp r0, r12
 *   @0x2d9dac blo 0x2d9dc4 <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x178>
 *   @0x2d9db0 b 0x2d9f78 <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x32c>
 *   @0x2d9db4 ldr r1, [r2, #0x4]
 *   @0x2d9db8 cmp r0, r1
 *   @0x2d9dbc bhs 0x2d9f80 <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x334>
 *   @0x2d9dc0 mov r3, r12
 *   @0x2d9dc4 asr r12, r3, #1
 *   @0x2d9dc8 cmp r3, #0
 *   @0x2d9dcc add r2, r5, r12, lsl #3
 *   @0x2d9dd0 bne 0x2d9db4 <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x168>
 *   @0x2d9dd4 vsub.f32 s22, s22, s18
 *   @0x2d9dd8 cmp r5, r4
 *   @0x2d9ddc vmul.f32 s20, s22, s22
 *   @0x2d9de0 vsub.f32 s21, s21, s17
 *   @0x2d9de4 vmla.f32 s20, s21, s21
 *   @0x2d9de8 bls 0x2d9f6c <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x320>
 *   @0x2d9dec add r4, r4, #8
 *   @0x2d9df0 add r10, sp, #24
 *   @0x2d9df4 add r9, sp, #16
 *   @0x2d9df8 vldr s24, [pc, #484]
 *   @0x2d9dfc vmov.f32 s23, #1.000000e+00
 *   @0x2d9e00 vmov.f32 s25, s23
 *   @0x2d9e04 b 0x2d9ec8 <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x27c>
 *   @0x2d9e08 vmul.f32 s26, s19, s22
 *   @0x2d9e0c vmul.f32 s16, s19, s21
 *   @0x2d9e10 vadd.f32 s18, s18, s26
 *   @0x2d9e14 vmul.f32 s14, s18, s18
 *   @0x2d9e18 vstr s18, [sp, #20]
 *   @0x2d9e1c vadd.f32 s17, s17, s16
 *   @0x2d9e20 vmla.f32 s14, s17, s17
 *   @0x2d9e24 vstr s17, [sp, #16]
 *   @0x2d9e28 vsqrt.f32 s15, s14
 *   @0x2d9e2c vcmp.f32 s15, s15
 *   @0x2d9e30 vmrs APSR_nzcv, fpscr
 *   @0x2d9e34 bne 0x2d9fc0 <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x374>
 *   @0x2d9e38 vcmpe.f32 s15, s24
 *   @0x2d9e3c vmrs APSR_nzcv, fpscr
 *   @0x2d9e40 bmi 0x2d9e60 <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x214>
 *   @0x2d9e44 vdiv.f32 s15, s25, s15
 *   @0x2d9e48 vldr s14, [sp, #16]
 *   @0x2d9e4c vldr s13, [sp, #20]
 *   @0x2d9e50 vmul.f32 s14, s14, s15
 *   @0x2d9e54 vmul.f32 s15, s13, s15
 *   @0x2d9e58 vstr s14, [sp, #16]
 *   @0x2d9e5c vstr s15, [sp, #20]
 *   @0x2d9e60 vldr s15, [r6]
 *   @0x2d9e64 vldr s14, [r6, #4]
 *   @0x2d9e68 vadd.f32 s16, s16, s15
 *   @0x2d9e6c ldr r12, [r8]
 *   @0x2d9e70 mov r0, r8
 *   @0x2d9e74 mov r2, r10
 *   @0x2d9e78 mov r3, r9
 *   @0x2d9e7c ldr r12, [r12, #0xc]
 *   @0x2d9e80 vstr s19, [sp]
 *   @0x2d9e84 vadd.f32 s26, s26, s14
 *   @0x2d9e88 vstr s16, [sp, #24]
 *   @0x2d9e8c vstr s26, [sp, #28]
 *   @0x2d9e90 blx r12
 *   @0x2d9e94 vmov s15, r0
 *   @0x2d9e98 vcmp.f32 s15, s23
 *   @0x2d9e9c vmrs APSR_nzcv, fpscr
 *   @0x2d9ea0 vmovgt.f32 s15, s23
 *   @0x2d9ea4 vcmpe.f32 s15, #0
 *   @0x2d9ea8 vmrs APSR_nzcv, fpscr
 *   @0x2d9eac bls 0x2d9f6c <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x320>
 *   @0x2d9eb0 vmov.f32 s23, s15
 *   @0x2d9eb4 cmp r4, r5
 *   @0x2d9eb8 bhs 0x2d9f6c <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x320>
 *   @0x2d9ebc add r4, r4, #8
 *   @0x2d9ec0 vldr s17, [r6]
 *   @0x2d9ec4 vldr s18, [r6, #4]
 *   @0x2d9ec8 ldr r1, [r4, #-0x8]
 *   @0x2d9ecc vldr s14, [r7, #32]
 *   @0x2d9ed0 ldr r0, [r7, #0x38]
 *   @0x2d9ed4 add r0, r0, r1, lsl #3
 *   @0x2d9ed8 vldr s15, [r0, #4]
 *   @0x2d9edc vsub.f32 s18, s18, s15
 *   @0x2d9ee0 vldr s13, [r0]
 *   @0x2d9ee4 vmul.f32 s15, s18, s18
 *   @0x2d9ee8 vsub.f32 s17, s17, s13
 *   @0x2d9eec vmla.f32 s15, s17, s17
 *   @0x2d9ef0 vmul.f32 s16, s22, s18
 *   @0x2d9ef4 vsub.f32 s15, s15, s14
 *   @0x2d9ef8 vmla.f32 s16, s21, s17
 *   @0x2d9efc vmul.f32 s15, s15, s20
 *   @0x2d9f00 vnmls.f32 s15, s16, s16
 *   @0x2d9f04 vcmpe.f32 s15, #0
 *   @0x2d9f08 vmrs APSR_nzcv, fpscr
 *   @0x2d9f0c blt 0x2d9eb4 <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x268>
 *   @0x2d9f10 vsqrt.f32 s14, s15
 *   @0x2d9f14 vcmp.f32 s14, s14
 *   @0x2d9f18 vmrs APSR_nzcv, fpscr
 *   @0x2d9f1c bne 0x2d9fa8 <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x35c>
 *   @0x2d9f20 vneg.f32 s19, s16
 *   @0x2d9f24 vsub.f32 s19, s19, s14
 *   @0x2d9f28 vdiv.f32 s19, s19, s20
 *   @0x2d9f2c vcmpe.f32 s19, s23
 *   @0x2d9f30 vmrs APSR_nzcv, fpscr
 *   @0x2d9f34 bgt 0x2d9eb4 <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x268>
 *   @0x2d9f38 vcmpe.f32 s19, #0
 *   @0x2d9f3c vmrs APSR_nzcv, fpscr
 *   @0x2d9f40 bpl 0x2d9e08 <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x1bc>
 *   @0x2d9f44 vsub.f32 s16, s14, s16
 *   @0x2d9f48 vdiv.f32 s19, s16, s20
 *   @0x2d9f4c vcmpe.f32 s19, #0
 *   @0x2d9f50 vmrs APSR_nzcv, fpscr
 *   @0x2d9f54 bmi 0x2d9eb4 <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x268>
 *   @0x2d9f58 vcmpe.f32 s19, s23
 *   @0x2d9f5c vmrs APSR_nzcv, fpscr
 *   @0x2d9f60 ble 0x2d9e08 <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x1bc>
 *   @0x2d9f64 cmp r4, r5
 *   @0x2d9f68 blo 0x2d9ebc <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x270>
 *   @0x2d9f6c add sp, sp, #32
 *   @0x2d9f70 vpop {d8, d9, d10, d11, d12, d13}
 *   @0x2d9f74 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2d9f78 mov r12, r3
 *   @0x2d9f7c mov r3, r1
 *   @0x2d9f80 rsb r3, r12, r3
 *   @0x2d9f84 add r5, r2, #8
 *   @0x2d9f88 sub r1, r3, #1
 *   @0x2d9f8c b 0x2d9d94 <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x148>
 *   @0x2d9f90 mov r12, r3
 *   @0x2d9f94 mov r3, r4
 *   @0x2d9f98 rsb r3, r12, r3
 *   @0x2d9f9c add r5, r2, #8
 *   @0x2d9fa0 sub r4, r3, #1
 *   @0x2d9fa4 b 0x2d9cec <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0xa0>
 *   @0x2d9fa8 vmov r0, s15
 *   @0x2d9fac str r1, [sp, #0xc]
 *   @0x2d9fb0 bl 0xb6700 <sqrtf@plt>
 *   @0x2d9fb4 ldr r1, [sp, #0xc]
 *   @0x2d9fb8 vmov s14, r0
 *   @0x2d9fbc b 0x2d9f20 <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x2d4>
 *   @0x2d9fc0 vmov r0, s14
 *   @0x2d9fc4 str r1, [sp, #0xc]
 *   @0x2d9fc8 bl 0xb6700 <sqrtf@plt>
 *   @0x2d9fcc ldr r1, [sp, #0xc]
 *   @0x2d9fd0 vmov s15, r0
 *   @0x2d9fd4 b 0x2d9e38 <_ZNK16b2ParticleSystem7RayCastEP17b2RayCastCallbackRK6b2Vec2S4_+0x1ec>
 *   @0x2d9fd8 orrmi r0, r0, #0
 *   @0x2d9fdc .word 0x49000000
 *   @0x2d9fe0 strmi r0, [r0, #-0x0]
 *   @0x2d9fe4 strlo r0, [r0], #-0
 *
 * ══ §3/36 CSprite::Collision(int, float, float, float, float, float, float, float)  0x1ed3d0  size 920  230 条（0x1ed3d0..0x1ed768）
 * @func 0x1ed3d0 0x1ed768  size 920  230 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: yyMatrix::Multiply(yyMatrix*, yyMatrix*, yyMatrix*)×3 / yyMatrix::SetZRotation(yyMatrix*, float) / CSprite::Collision(int, float, float, float, float, float, float, float)+0x1a0 / CSprite::Collision(int, float, float, float, float, float, float, float)+0x334 / Point_In_Triangle(float, float, float, float, float, float, float, float)
 * 字段偏移 top8: 0x4×7 / 0x1c×6 / 0x24×4 / 0x8×4 / 0x18×4 / 0x38×3 / 0x14×3 / 0x20×3
 * VFP 指令 30 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1ed3d0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1ed3d4 vpush {d8}
 *   @0x1ed3d8 sub sp, sp, #492
 *   @0x1ed3dc vldr s17, [sp, #540]
 *   @0x1ed3e0 add r9, sp, #104
 *   @0x1ed3e4 mov r7, r0
 *   @0x1ed3e8 mov r5, r1
 *   @0x1ed3ec ldr r1, [sp, #0x218]
 *   @0x1ed3f0 mov r0, r9
 *   @0x1ed3f4 mov r4, #0
 *   @0x1ed3f8 mov r6, #1065353216
 *   @0x1ed3fc str r2, [sp, #0x58]
 *   @0x1ed400 str r3, [sp, #0x5c]
 *   @0x1ed404 vldr s16, [sp, #544]
 *   @0x1ed408 str r4, [sp, #0x54]
 *   @0x1ed40c add r10, sp, #296
 *   @0x1ed410 str r4, [sp, #0x4c]
 *   @0x1ed414 str r4, [sp, #0x48]
 *   @0x1ed418 str r4, [sp, #0x44]
 *   @0x1ed41c str r4, [sp, #0x40]
 *   @0x1ed420 str r4, [sp, #0x38]
 *   @0x1ed424 str r4, [sp, #0x34]
 *   @0x1ed428 str r4, [sp, #0x30]
 *   @0x1ed42c str r4, [sp, #0x2c]
 *   @0x1ed430 str r4, [sp, #0x60]
 *   @0x1ed434 str r6, [sp, #0x64]
 *   @0x1ed438 str r6, [sp, #0x50]
 *   @0x1ed43c str r6, [sp, #0x3c]
 *   @0x1ed440 str r6, [sp, #0x28]
 *   @0x1ed444 ldr r11, [sp, #0x224]
 *   @0x1ed448 ldr r8, [sp, #0x228]
 *   @0x1ed44c bl 0x27aedc <_ZN8yyMatrix12SetZRotationEPS_f>
 *   @0x1ed450 ldr r12, [pc, #0x304]
 *   @0x1ed454 vldr s14, [pc, #764]
 *   @0x1ed458 ldr r3, [pc, #0x300]
 *   @0x1ed45c mov r0, r10
 *   @0x1ed460 add r12, pc, r12
 *   @0x1ed464 str r12, [sp, #0x14]
 *   @0x1ed468 add r1, sp, #168
 *   @0x1ed46c add r2, sp, #232
 *   @0x1ed470 ldr r3, [r12, r3]
 *   @0x1ed474 vldr s15, [r3]
 *   @0x1ed478 vdiv.f32 s14, s14, s15
 *   @0x1ed47c str r4, [sp, #0xd4]
 *   @0x1ed480 str r4, [sp, #0xcc]
 *   @0x1ed484 str r4, [sp, #0xc8]
 *   @0x1ed488 str r4, [sp, #0xc4]
 *   @0x1ed48c str r4, [sp, #0xc0]
 *   @0x1ed490 str r4, [sp, #0xb8]
 *   @0x1ed494 str r4, [sp, #0xb4]
 *   @0x1ed498 str r4, [sp, #0xb0]
 *   @0x1ed49c str r4, [sp, #0xac]
 *   @0x1ed4a0 str r4, [sp, #0xe0]
 *   @0x1ed4a4 str r4, [sp, #0x120]
 *   @0x1ed4a8 str r4, [sp, #0x11c]
 *   @0x1ed4ac str r4, [sp, #0x118]
 *   @0x1ed4b0 str r4, [sp, #0x114]
 *   @0x1ed4b4 str r4, [sp, #0x10c]
 *   @0x1ed4b8 str r4, [sp, #0x108]
 *   @0x1ed4bc str r4, [sp, #0x104]
 *   @0x1ed4c0 str r4, [sp, #0x100]
 *   @0x1ed4c4 str r4, [sp, #0xf8]
 *   @0x1ed4c8 str r4, [sp, #0xf4]
 *   @0x1ed4cc str r4, [sp, #0xf0]
 *   @0x1ed4d0 str r4, [sp, #0xec]
 *   @0x1ed4d4 add r4, sp, #360
 *   @0x1ed4d8 str r6, [sp, #0xe4]
 *   @0x1ed4dc str r6, [sp, #0xd0]
 *   @0x1ed4e0 str r6, [sp, #0xbc]
 *   @0x1ed4e4 str r6, [sp, #0xa8]
 *   @0x1ed4e8 str r6, [sp, #0x124]
 *   @0x1ed4ec str r6, [sp, #0x110]
 *   @0x1ed4f0 vmul.f32 s17, s15, s17
 *   @0x1ed4f4 vstr s14, [sp, #216]
 *   @0x1ed4f8 vstr s14, [sp, #220]
 *   @0x1ed4fc vmul.f32 s15, s15, s16
 *   @0x1ed500 vstr s17, [sp, #232]
 *   @0x1ed504 vstr s15, [sp, #252]
 *   @0x1ed508 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_>
 *   @0x1ed50c mov r1, r10
 *   @0x1ed510 mov r2, r9
 *   @0x1ed514 mov r0, r4
 *   @0x1ed518 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_>
 *   @0x1ed51c mov r1, r4
 *   @0x1ed520 add r2, sp, #40
 *   @0x1ed524 add r0, sp, #424
 *   @0x1ed528 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_>
 *   @0x1ed52c ldr r1, [r7, #0x80]
 *   @0x1ed530 ldr r2, [r7, #0x7c]
 *   @0x1ed534 cmp r1, #0
 *   @0x1ed538 ble 0x1ed570 <_ZN7CSprite9CollisionEifffffff+0x1a0>
 *   @0x1ed53c ldr r6, [r2]
 *   @0x1ed540 ldr r3, [r6, #0x4]
 *   @0x1ed544 cmp r5, r3
 *   @0x1ed548 beq 0x1ed574 <_ZN7CSprite9CollisionEifffffff+0x1a4>
 *   @0x1ed54c mov r3, #0
 *   @0x1ed550 b 0x1ed564 <_ZN7CSprite9CollisionEifffffff+0x194>
 *   @0x1ed554 ldr r6, [r2, #0x4]!
 *   @0x1ed558 ldr r0, [r6, #0x4]
 *   @0x1ed55c cmp r5, r0
 *   @0x1ed560 beq 0x1ed574 <_ZN7CSprite9CollisionEifffffff+0x1a4>
 *   @0x1ed564 add r3, r3, #1
 *   @0x1ed568 cmp r3, r1
 *   @0x1ed56c bne 0x1ed554 <_ZN7CSprite9CollisionEifffffff+0x184>
 *   @0x1ed570 mov r6, #0
 *   @0x1ed574 ldr r3, [r6]
 *   @0x1ed578 cmp r3, #1
 *   @0x1ed57c beq 0x1ed590 <_ZN7CSprite9CollisionEifffffff+0x1c0>
 *   @0x1ed580 mov r0, #0
 *   @0x1ed584 add sp, sp, #492
 *   @0x1ed588 vpop {d8}
 *   @0x1ed58c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1ed590 ldr r3, [r6, #0x1c]
 *   @0x1ed594 cmp r3, #0
 *   @0x1ed598 beq 0x1ed580 <_ZN7CSprite9CollisionEifffffff+0x1b0>
 *   @0x1ed59c mov r12, #0
 *   @0x1ed5a0 str r6, [sp, #0x20]
 *   @0x1ed5a4 str r12, [sp, #0x1c]
 *   @0x1ed5a8 str r12, [sp, #0x24]
 *   @0x1ed5ac ldr r12, [sp, #0x20]
 *   @0x1ed5b0 ldr r10, [r12, #0x8]
 *   @0x1ed5b4 ldr r12, [sp, #0x1c]
 *   @0x1ed5b8 add r10, r10, r12
 *   @0x1ed5bc str r10, [sp, #0x18]
 *   @0x1ed5c0 ldr r2, [r10, #0xc]
 *   @0x1ed5c4 cmp r2, #0
 *   @0x1ed5c8 movne r7, #0
 *   @0x1ed5cc movne r9, r7
 *   @0x1ed5d0 beq 0x1ed71c <_ZN7CSprite9CollisionEifffffff+0x34c>
 *   @0x1ed5d4 ldr r1, [sp, #0x18]
 *   @0x1ed5d8 ldr r12, [r1]
 *   @0x1ed5dc add r10, r12, r7
 *   @0x1ed5e0 ldr r3, [r10, #0x28]
 *   @0x1ed5e4 cmp r3, #0
 *   @0x1ed5e8 blt 0x1ed704 <_ZN7CSprite9CollisionEifffffff+0x334>
 *   @0x1ed5ec ldr r3, [r10, #0x38]
 *   @0x1ed5f0 cmp r3, #0
 *   @0x1ed5f4 beq 0x1ed704 <_ZN7CSprite9CollisionEifffffff+0x334>
 *   @0x1ed5f8 ldr r0, [r10, #0x30]
 *   @0x1ed5fc ldr r3, [r10]
 *   @0x1ed600 cmp r0, #65536
 *   @0x1ed604 movhs r0, #65536
 *   @0x1ed608 cmp r0, #0
 *   @0x1ed60c beq 0x1ed744 <_ZN7CSprite9CollisionEifffffff+0x374>
 *   @0x1ed610 ldr r2, [pc, #0x14c]
 *   @0x1ed614 mov r1, #0
 *   @0x1ed618 ldr r12, [sp, #0x14]
 *   @0x1ed61c ldr r5, [r12, r2]
 *   @0x1ed620 add r2, r5, #8
 *   @0x1ed624 vldr s12, [r3, #4]
 *   @0x1ed628 vldr s14, [sp, #444]
 *   @0x1ed62c vldr s15, [sp, #440]
 *   @0x1ed630 vmul.f32 s14, s12, s14
 *   @0x1ed634 vldr s13, [r3]
 *   @0x1ed638 vldr s8, [sp, #428]
 *   @0x1ed63c vldr s9, [sp, #424]
 *   @0x1ed640 vldr s10, [sp, #476]
 *   @0x1ed644 vldr s11, [sp, #472]
 *   @0x1ed648 add r1, r1, #1
 *   @0x1ed64c cmp r0, r1
 *   @0x1ed650 add r3, r3, #8
 *   @0x1ed654 add r2, r2, #8
 *   @0x1ed658 vmul.f32 s15, s12, s15
 *   @0x1ed65c vmla.f32 s14, s13, s8
 *   @0x1ed660 vmla.f32 s15, s13, s9
 *   @0x1ed664 vadd.f32 s14, s14, s10
 *   @0x1ed668 vadd.f32 s15, s15, s11
 *   @0x1ed66c vstr s14, [r2, #-12]
 *   @0x1ed670 vstr s15, [r2, #-16]
 *   @0x1ed674 bne 0x1ed624 <_ZN7CSprite9CollisionEifffffff+0x254>
 *   @0x1ed678 ldr r4, [r10, #0x8]
 *   @0x1ed67c mov r6, #0
 *   @0x1ed680 b 0x1ed690 <_ZN7CSprite9CollisionEifffffff+0x2c0>
 *   @0x1ed684 ldr r3, [r10, #0x38]
 *   @0x1ed688 cmp r6, r3
 *   @0x1ed68c bhs 0x1ed6fc <_ZN7CSprite9CollisionEifffffff+0x32c>
 *   @0x1ed690 ldrh r1, [r4, #2]
 *   @0x1ed694 add r6, r6, #1
 *   @0x1ed698 ldrh r3, [r4]
 *   @0x1ed69c add r4, r4, #6
 *   @0x1ed6a0 ldrh r12, [r4, #-2]
 *   @0x1ed6a4 add r1, r5, r1, lsl #3
 *   @0x1ed6a8 add r3, r5, r3, lsl #3
 *   @0x1ed6ac ldr r0, [r1]
 *   @0x1ed6b0 add r12, r5, r12, lsl #3
 *   @0x1ed6b4 ldr r2, [r3]
 *   @0x1ed6b8 ldr r3, [r3, #0x4]
 *   @0x1ed6bc str r0, [sp]
 *   @0x1ed6c0 mov r0, r11
 *   @0x1ed6c4 ldr r1, [r1, #0x4]
 *   @0x1ed6c8 str r1, [sp, #0x4]
 *   @0x1ed6cc ldr r1, [r12]
 *   @0x1ed6d0 str r1, [sp, #0x8]
 *   @0x1ed6d4 mov r1, r8
 *   @0x1ed6d8 ldr r12, [r12, #0x4]
 *   @0x1ed6dc str r12, [sp, #0xc]
 *   @0x1ed6e0 bl 0x10c328 <_Z17Point_In_Triangleffffffff>
 *   @0x1ed6e4 cmp r0, #0
 *   @0x1ed6e8 beq 0x1ed684 <_ZN7CSprite9CollisionEifffffff+0x2b4>
 *   @0x1ed6ec mov r0, #1
 *   @0x1ed6f0 add sp, sp, #492
 *   @0x1ed6f4 vpop {d8}
 *   @0x1ed6f8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1ed6fc ldr r12, [sp, #0x18]
 *   @0x1ed700 ldr r2, [r12, #0xc]
 *   @0x1ed704 add r9, r9, #1
 *   @0x1ed708 add r7, r7, #84
 *   @0x1ed70c cmp r2, r9
 *   @0x1ed710 bhi 0x1ed5d4 <_ZN7CSprite9CollisionEifffffff+0x204>
 *   @0x1ed714 ldr r12, [sp, #0x20]
 *   @0x1ed718 ldr r3, [r12, #0x1c]
 *   @0x1ed71c ldr r12, [sp, #0x24]
 *   @0x1ed720 add r12, r12, #1
 *   @0x1ed724 str r12, [sp, #0x24]
 *   @0x1ed728 ldr r12, [sp, #0x1c]
 *   @0x1ed72c add r12, r12, #24
 *   @0x1ed730 str r12, [sp, #0x1c]
 *   @0x1ed734 ldr r12, [sp, #0x24]
 *   @0x1ed738 cmp r3, r12
 *   @0x1ed73c bhi 0x1ed5ac <_ZN7CSprite9CollisionEifffffff+0x1dc>
 *   @0x1ed740 b 0x1ed580 <_ZN7CSprite9CollisionEifffffff+0x1b0>
 *   @0x1ed744 ldr r3, [pc, #0x18]
 *   @0x1ed748 ldr r12, [sp, #0x14]
 *   @0x1ed74c ldr r4, [r10, #0x8]
 *   @0x1ed750 ldr r5, [r12, r3]
 *   @0x1ed754 b 0x1ed67c <_ZN7CSprite9CollisionEifffffff+0x2ac>
 *   @0x1ed758 andhi r0, r0, r0
 *   @0x1ed75c .word 0x002047f0
 *   @0x1ed760 .word 0xfffff184
 *   @0x1ed764 .word 0xfffff190
 *
 * ══ §4/36 JS_String_prototype_indexOf(RValue&, CInstance*, CInstance*, int, RValue*)  0x257ae4  size 920  230 条（0x257ae4..0x257e7c）
 * @func 0x257ae4 0x257e8c  size 936  234 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CodepointToUTF16(int, unsigned short&, unsigned short&)×4 / CCodepointIterator_UTF8::GetNext()×4 / F_JS_ToString(RValue&, RValue*)×2 / CCodepointIterator_UTF8::CCodepointIterator_UTF8(char const*)×2 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / 0xb65b0×2 / CCodepointIterator_UTF8::Reset()×2 / MemoryManager::Free(void const*)×2
 * 字段偏移 top8: 0x4×4 / 0x44×3 / 0x54×3 / 0x8×3 / 0x14×3 / 0x10×2 / 0xc×2 / 0x40×2
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x257ae4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x257ae8 sub sp, sp, #92
 *   @0x257aec add r4, sp, #88
 *   @0x257af0 str r0, [sp, #0x4]
 *   @0x257af4 str r1, [r4, #-0x30]!
 *   @0x257af8 mov r0, r4
 *   @0x257afc str r3, [sp, #0x10]
 *   @0x257b00 mov r3, #6
 *   @0x257b04 str r3, [sp, #0x34]
 *   @0x257b08 bl 0x2423a4 <_Z23JS_CheckObjectCoercibleR6RValue>
 *   @0x257b0c cmp r0, #1
 *   @0x257b10 beq 0x257e5c <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x378>
 *   @0x257b14 add r1, sp, #56
 *   @0x257b18 add r0, sp, #56
 *   @0x257b1c str r1, [sp, #0xc]
 *   @0x257b20 mov r1, r4
 *   @0x257b24 mov r2, #0
 *   @0x257b28 mov r3, #0
 *   @0x257b2c mov r6, #0
 *   @0x257b30 strd r2, r3, [sp, #56]
 *   @0x257b34 str r6, [sp, #0x40]
 *   @0x257b38 mvn r3, #-16777216
 *   @0x257b3c str r3, [sp, #0x44]
 *   @0x257b40 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x257b44 ldr r3, [sp, #0x38]
 *   @0x257b48 add r7, sp, #72
 *   @0x257b4c add r4, sp, #28
 *   @0x257b50 add r8, sp, #26
 *   @0x257b54 mov r0, r7
 *   @0x257b58 ldr r1, [r3]
 *   @0x257b5c bl 0x2423d8 <_ZN23CCodepointIterator_UTF8C2EPKc>
 *   @0x257b60 b 0x257b6c <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x257b64 bl 0x2424c4 <_Z16CodepointToUTF16iRtS_>
 *   @0x257b68 add r6, r6, r0
 *   @0x257b6c mov r0, r7
 *   @0x257b70 bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv>
 *   @0x257b74 mov r1, r8
 *   @0x257b78 mov r2, r4
 *   @0x257b7c subs r5, r0, #0
 *   @0x257b80 bne 0x257b64 <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x257b84 lsl r8, r6, #1
 *   @0x257b88 ldr r1, [pc, #0x2e0]
 *   @0x257b8c mov r2, #70
 *   @0x257b90 mov r3, #1
 *   @0x257b94 add r1, pc, r1
 *   @0x257b98 mov r0, r8
 *   @0x257b9c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x257ba0 mov r1, r5
 *   @0x257ba4 mov r2, r8
 *   @0x257ba8 add r9, sp, #26
 *   @0x257bac mov r10, r0
 *   @0x257bb0 bl 0xb65b0 <memset@plt>
 *   @0x257bb4 mov r0, r7
 *   @0x257bb8 bl 0x2423fc <_ZN23CCodepointIterator_UTF85ResetEv>
 *   @0x257bbc mov r0, r7
 *   @0x257bc0 bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv>
 *   @0x257bc4 mov r1, r9
 *   @0x257bc8 mov r2, r4
 *   @0x257bcc subs r8, r0, #0
 *   @0x257bd0 beq 0x257bfc <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x257bd4 bl 0x2424c4 <_Z16CodepointToUTF16iRtS_>
 *   @0x257bd8 ldrh r2, [sp, #26]
 *   @0x257bdc lsl r3, r5, #1
 *   @0x257be0 strh r2, [r10, r3]
 *   @0x257be4 cmp r0, #2
 *   @0x257be8 add r5, r5, r0
 *   @0x257bec ldrheq r2, [sp, #28]
 *   @0x257bf0 addeq r3, r10, r3
 *   @0x257bf4 strheq r2, [r3, #2]
 *   @0x257bf8 b 0x257bbc <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x257bfc ldr r1, [sp, #0x80]
 *   @0x257c00 mov r0, r7
 *   @0x257c04 mov r2, #0
 *   @0x257c08 str r8, [sp, #0x50]
 *   @0x257c0c mov r3, #0
 *   @0x257c10 strd r2, r3, [sp, #72]
 *   @0x257c14 mvn r3, #-16777216
 *   @0x257c18 str r3, [sp, #0x54]
 *   @0x257c1c bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x257c20 ldr r3, [sp, #0x48]
 *   @0x257c24 mov r0, r4
 *   @0x257c28 add r11, sp, #24
 *   @0x257c2c add r9, sp, #26
 *   @0x257c30 ldr r1, [r3]
 *   @0x257c34 bl 0x2423d8 <_ZN23CCodepointIterator_UTF8C2EPKc>
 *   @0x257c38 b 0x257c44 <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x257c3c bl 0x2424c4 <_Z16CodepointToUTF16iRtS_>
 *   @0x257c40 add r8, r8, r0
 *   @0x257c44 mov r0, r4
 *   @0x257c48 bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv>
 *   @0x257c4c mov r1, r11
 *   @0x257c50 mov r2, r9
 *   @0x257c54 subs r5, r0, #0
 *   @0x257c58 bne 0x257c3c <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x158>
 *   @0x257c5c ldr r1, [pc, #0x210]
 *   @0x257c60 lsl r2, r8, #1
 *   @0x257c64 str r2, [sp, #0x8]
 *   @0x257c68 mov r3, #1
 *   @0x257c6c add r1, pc, r1
 *   @0x257c70 mov r2, #70
 *   @0x257c74 ldr r0, [sp, #0x8]
 *   @0x257c78 add r12, sp, #24
 *   @0x257c7c str r12, [sp]
 *   @0x257c80 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x257c84 mov r1, r5
 *   @0x257c88 ldr r2, [sp, #0x8]
 *   @0x257c8c add r11, sp, #26
 *   @0x257c90 mov r9, r0
 *   @0x257c94 bl 0xb65b0 <memset@plt>
 *   @0x257c98 mov r0, r4
 *   @0x257c9c bl 0x2423fc <_ZN23CCodepointIterator_UTF85ResetEv>
 *   @0x257ca0 ldr r12, [sp]
 *   @0x257ca4 str r6, [sp, #0x14]
 *   @0x257ca8 mov r6, r12
 *   @0x257cac mov r0, r4
 *   @0x257cb0 bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv>
 *   @0x257cb4 mov r1, r6
 *   @0x257cb8 mov r2, r11
 *   @0x257cbc subs r3, r0, #0
 *   @0x257cc0 beq 0x257cec <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x208>
 *   @0x257cc4 bl 0x2424c4 <_Z16CodepointToUTF16iRtS_>
 *   @0x257cc8 ldrh r2, [sp, #24]
 *   @0x257ccc lsl r3, r5, #1
 *   @0x257cd0 strh r2, [r9, r3]
 *   @0x257cd4 cmp r0, #2
 *   @0x257cd8 add r5, r5, r0
 *   @0x257cdc ldrheq r2, [sp, #26]
 *   @0x257ce0 addeq r3, r9, r3
 *   @0x257ce4 strheq r2, [r3, #2]
 *   @0x257ce8 b 0x257cac <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x1c8>
 *   @0x257cec ldr r1, [sp, #0x10]
 *   @0x257cf0 ldr r6, [sp, #0x14]
 *   @0x257cf4 cmp r1, #1
 *   @0x257cf8 movle r0, r3
 *   @0x257cfc ble 0x257d1c <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x238>
 *   @0x257d00 ldr r2, [sp, #0x80]
 *   @0x257d04 add r0, r2, #16
 *   @0x257d08 bl 0x24d730 <_Z14F_JS_ToIntegerR6RValue>
 *   @0x257d0c vmov d7, r0, r1
 *   @0x257d10 vcvt.s32.f64 s15, d7
 *   @0x257d14 vmov r0, s15
 *   @0x257d18 bic r0, r0, r0, asr #31
 *   @0x257d1c cmp r0, r6
 *   @0x257d20 movlt r4, r0
 *   @0x257d24 movge r4, r6
 *   @0x257d28 cmp r8, #0
 *   @0x257d2c bne 0x257de8 <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x304>
 *   @0x257d30 cmp r4, r6
 *   @0x257d34 movlt r2, r4
 *   @0x257d38 movge r2, r6
 *   @0x257d3c vmov s15, r2
 *   @0x257d40 vcvt.f64.s32 d7, s15
 *   @0x257d44 vmov r2, r3, d7
 *   @0x257d48 mov r0, r2
 *   @0x257d4c mov r2, r3
 *   @0x257d50 ldr r3, [sp, #0x4]
 *   @0x257d54 ldr r1, [sp, #0x44]
 *   @0x257d58 str r0, [r3]
 *   @0x257d5c sub r3, r1, #1
 *   @0x257d60 ldr r1, [sp, #0x4]
 *   @0x257d64 bic r3, r3, #-16777216
 *   @0x257d68 bic r3, r3, #3
 *   @0x257d6c str r2, [r1, #0x4]
 *   @0x257d70 mov r2, #0
 *   @0x257d74 cmp r3, r2
 *   @0x257d78 str r2, [r1, #0xc]
 *   @0x257d7c beq 0x257e40 <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x35c>
 *   @0x257d80 ldr r1, [sp, #0x54]
 *   @0x257d84 mov r3, #0
 *   @0x257d88 str r3, [sp, #0x40]
 *   @0x257d8c mov r2, #5
 *   @0x257d90 sub r1, r1, #1
 *   @0x257d94 str r3, [sp, #0x38]
 *   @0x257d98 bic r3, r1, #-16777216
 *   @0x257d9c str r2, [sp, #0x44]
 *   @0x257da0 bic r3, r3, #3
 *   @0x257da4 cmp r3, #0
 *   @0x257da8 beq 0x257e34 <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x350>
 *   @0x257dac cmp r9, #0
 *   @0x257db0 mov r3, #0
 *   @0x257db4 mov r2, #5
 *   @0x257db8 str r3, [sp, #0x50]
 *   @0x257dbc str r3, [sp, #0x48]
 *   @0x257dc0 str r2, [sp, #0x54]
 *   @0x257dc4 beq 0x257dd0 <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x2ec>
 *   @0x257dc8 mov r0, r9
 *   @0x257dcc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x257dd0 cmp r10, #0
 *   @0x257dd4 beq 0x257de0 <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x2fc>
 *   @0x257dd8 mov r0, r10
 *   @0x257ddc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x257de0 add sp, sp, #92
 *   @0x257de4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x257de8 cmp r4, r6
 *   @0x257dec addlt r5, r10, r4, lsl #1
 *   @0x257df0 ldrlt r8, [sp, #0x8]
 *   @0x257df4 blt 0x257e08 <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x324>
 *   @0x257df8 b 0x257e4c <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x368>
 *   @0x257dfc add r4, r4, #1
 *   @0x257e00 cmp r4, r6
 *   @0x257e04 beq 0x257e4c <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x368>
 *   @0x257e08 mov r0, r5
 *   @0x257e0c mov r1, r9
 *   @0x257e10 mov r2, r8
 *   @0x257e14 add r5, r5, #2
 *   @0x257e18 bl 0xb6c40 <memcmp@plt>
 *   @0x257e1c cmp r0, #0
 *   @0x257e20 bne 0x257dfc <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x318>
 *   @0x257e24 vmov s15, r4
 *   @0x257e28 vcvt.f64.s32 d7, s15
 *   @0x257e2c vmov r2, r3, d7
 *   @0x257e30 b 0x257d48 <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x264>
 *   @0x257e34 mov r0, r7
 *   @0x257e38 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x257e3c b 0x257dac <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x2c8>
 *   @0x257e40 add r0, sp, #56
 *   @0x257e44 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x257e48 b 0x257d80 <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x29c>
 *   @0x257e4c mov r3, #0
 *   @0x257e50 mov r2, #0
 *   @0x257e54 movt r3, #0xbff0
 *   @0x257e58 b 0x257d48 <_Z27JS_String_prototype_indexOfR6RValueP9CInstanceS2_iPS_+0x264>
 *   @0x257e5c ldr r0, [pc, #0x14]
 *   @0x257e60 add r0, pc, r0
 *   @0x257e64 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x257e68 add sp, sp, #92
 *   @0x257e6c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x257e70 muleq sp, r12, r4
 *   @0x257e74 andeq r9, sp, r4, asr #7
 *   @0x257e78 andeq lr, pc, r8, ror #1
 *
 * ══ §5/36 F_MoveRandom(RValue&, CInstance*, CInstance*, int, RValue*)  0x107508  size 916  229 条（0x107508..0x10789c）
 * @func 0x107508 0x10789c  size 916  229 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYRandom(int)×8 / 0xb66e8×4 / 0xb6598×4 / Command_IsFree(CInstance*, float, float)×4 / Sprite_Exists(int)×2 / YYGetInt32(RValue const*, int)×2 / F_MoveRandom(RValue&, CInstance*, CInstance*, int, RValue*)+0x210 / F_MoveRandom(RValue&, CInstance*, CInstance*, int, RValue*)+0x2f0
 * 字段偏移 top8: 0x4×3 / 0x388×1 / 0x8c×1 / 0x40×1 / 0x10×1 / 0x14×1 / 0x64×1 / 0xac×1
 * VFP 指令 99 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x107508 ldr r3, [pc, #0x388]
 *   @0x10750c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x107510 vpush {d8, d9}
 *   @0x107514 ldr r3, [pc, r3]
 *   @0x107518 sub sp, sp, #12
 *   @0x10751c ldr r0, [r1, #0x8c]
 *   @0x107520 ldr r3, [r3]
 *   @0x107524 mov r4, r1
 *   @0x107528 ldr r10, [sp, #0x40]
 *   @0x10752c ldr r8, [r3, #0x10]
 *   @0x107530 ldr r9, [r3, #0x14]
 *   @0x107534 bl 0x1eee98 <_Z13Sprite_Existsi>
 *   @0x107538 cmp r0, #0
 *   @0x10753c beq 0x1076f4 <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x1ec>
 *   @0x107540 ldrb r3, [r4, #0x64]
 *   @0x107544 cmp r3, #0
 *   @0x107548 bne 0x107888 <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x380>
 *   @0x10754c vldr s12, [r4, #232]
 *   @0x107550 vcvt.f32.s32 s15, s12
 *   @0x107554 vldr s14, [r4, #180]
 *   @0x107558 vsub.f32 s15, s14, s15
 *   @0x10755c vcvt.f64.f32 d6, s15
 *   @0x107560 vmov r0, r1, d6
 *   @0x107564 bl 0xb66e8 <lrint@plt>
 *   @0x107568 vldr s15, [r4, #180]
 *   @0x10756c vmov s13, r8
 *   @0x107570 vldr s12, [r4, #240]
 *   @0x107574 vcvt.f32.s32 s14, s13
 *   @0x107578 vadd.f32 s14, s14, s15
 *   @0x10757c vcvt.f32.s32 s15, s12
 *   @0x107580 vsub.f32 s15, s14, s15
 *   @0x107584 mov r11, r0
 *   @0x107588 mov r6, r0
 *   @0x10758c vcvt.f64.f32 d6, s15
 *   @0x107590 vmov r0, r1, d6
 *   @0x107594 bl 0xb66e8 <lrint@plt>
 *   @0x107598 vldr s13, [r4, #236]
 *   @0x10759c vcvt.f32.s32 s15, s13
 *   @0x1075a0 vldr s14, [r4, #184]
 *   @0x1075a4 vsub.f32 s15, s14, s15
 *   @0x1075a8 vcvt.f64.f32 d6, s15
 *   @0x1075ac mov r8, r0
 *   @0x1075b0 vmov r0, r1, d6
 *   @0x1075b4 bl 0xb66e8 <lrint@plt>
 *   @0x1075b8 vldr s15, [r4, #184]
 *   @0x1075bc vmov s13, r9
 *   @0x1075c0 vldr s12, [r4, #244]
 *   @0x1075c4 vcvt.f32.s32 s14, s13
 *   @0x1075c8 vadd.f32 s14, s14, s15
 *   @0x1075cc vcvt.f32.s32 s15, s12
 *   @0x1075d0 vsub.f32 s15, s14, s15
 *   @0x1075d4 str r0, [sp, #0x4]
 *   @0x1075d8 mov r5, r0
 *   @0x1075dc vcvt.f64.f32 d6, s15
 *   @0x1075e0 vmov r0, r1, d6
 *   @0x1075e4 bl 0xb66e8 <lrint@plt>
 *   @0x1075e8 mov r9, r0
 *   @0x1075ec mov r0, r10
 *   @0x1075f0 mov r1, #0
 *   @0x1075f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1075f8 mov r1, #1
 *   @0x1075fc rsb r8, r11, r8
 *   @0x107600 mov r7, r0
 *   @0x107604 mov r0, r10
 *   @0x107608 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x10760c ldr r3, [sp, #0x4]
 *   @0x107610 cmp r7, #0
 *   @0x107614 rsb r9, r3, r9
 *   @0x107618 mov r10, r0
 *   @0x10761c ble 0x107718 <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x210>
 *   @0x107620 cmp r0, #0
 *   @0x107624 ble 0x1077f8 <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x2f0>
 *   @0x107628 vmov s12, r0
 *   @0x10762c mov r11, #100
 *   @0x107630 vmov s13, r7
 *   @0x107634 vcvt.f32.s32 s19, s12
 *   @0x107638 vcvt.f32.s32 s18, s13
 *   @0x10763c b 0x107648 <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x107640 subs r11, r11, #1
 *   @0x107644 beq 0x10787c <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x374>
 *   @0x107648 mov r0, r8
 *   @0x10764c bl 0xc4600 <_Z8YYRandomi>
 *   @0x107650 add r0, r0, r6
 *   @0x107654 vmov s14, r0
 *   @0x107658 vcvt.f32.u32 s15, s14
 *   @0x10765c vdiv.f32 s15, s15, s18
 *   @0x107660 vcvt.f64.f32 d6, s15
 *   @0x107664 vmov r0, r1, d6
 *   @0x107668 bl 0xb6598 <floor@plt>
 *   @0x10766c vmov d7, r0, r1
 *   @0x107670 mov r0, r9
 *   @0x107674 vcvt.s32.f64 s17, d7
 *   @0x107678 vmov r3, s17
 *   @0x10767c mul r3, r7, r3
 *   @0x107680 vmov s17, r3
 *   @0x107684 bl 0xc4600 <_Z8YYRandomi>
 *   @0x107688 vcvt.f32.s32 s17, s17
 *   @0x10768c add r0, r0, r5
 *   @0x107690 vmov s12, r0
 *   @0x107694 vcvt.f32.u32 s15, s12
 *   @0x107698 vdiv.f32 s15, s15, s19
 *   @0x10769c vcvt.f64.f32 d6, s15
 *   @0x1076a0 vmov r0, r1, d6
 *   @0x1076a4 bl 0xb6598 <floor@plt>
 *   @0x1076a8 vmov d7, r0, r1
 *   @0x1076ac mov r0, r4
 *   @0x1076b0 vcvt.s32.f64 s16, d7
 *   @0x1076b4 vmov r1, s17
 *   @0x1076b8 vmov r3, s16
 *   @0x1076bc mul r3, r10, r3
 *   @0x1076c0 vmov s16, r3
 *   @0x1076c4 vcvt.f32.s32 s16, s16
 *   @0x1076c8 vmov r2, s16
 *   @0x1076cc bl 0x1cab94 <_Z14Command_IsFreeP9CInstanceff>
 *   @0x1076d0 cmp r0, #0
 *   @0x1076d4 beq 0x107640 <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x138>
 *   @0x1076d8 vmov r1, s17
 *   @0x1076dc mov r0, r4
 *   @0x1076e0 vmov r2, s16
 *   @0x1076e4 add sp, sp, #12
 *   @0x1076e8 vpop {d8, d9}
 *   @0x1076ec pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1076f0 b 0x193e7c <_ZN9CInstance11SetPositionEff>
 *   @0x1076f4 ldr r0, [r4, #0xac]
 *   @0x1076f8 bl 0x1eee98 <_Z13Sprite_Existsi>
 *   @0x1076fc cmp r0, #0
 *   @0x107700 bne 0x107540 <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x107704 mov r5, r0
 *   @0x107708 mov r6, r0
 *   @0x10770c str r0, [sp, #0x4]
 *   @0x107710 mov r11, r0
 *   @0x107714 b 0x1075ec <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x107718 cmp r0, #0
 *   @0x10771c ble 0x1077a4 <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x29c>
 *   @0x107720 vmov s12, r0
 *   @0x107724 mov r7, #100
 *   @0x107728 vcvt.f32.s32 s19, s12
 *   @0x10772c b 0x107738 <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x230>
 *   @0x107730 subs r7, r7, #1
 *   @0x107734 beq 0x10787c <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x374>
 *   @0x107738 mov r0, r8
 *   @0x10773c bl 0xc4600 <_Z8YYRandomi>
 *   @0x107740 add r0, r0, r6
 *   @0x107744 vmov s17, r0
 *   @0x107748 mov r0, r9
 *   @0x10774c bl 0xc4600 <_Z8YYRandomi>
 *   @0x107750 vcvt.f32.u32 s17, s17
 *   @0x107754 add r0, r0, r5
 *   @0x107758 vmov s13, r0
 *   @0x10775c vcvt.f32.u32 s15, s13
 *   @0x107760 vdiv.f32 s15, s15, s19
 *   @0x107764 vcvt.f64.f32 d6, s15
 *   @0x107768 vmov r0, r1, d6
 *   @0x10776c bl 0xb6598 <floor@plt>
 *   @0x107770 vmov d7, r0, r1
 *   @0x107774 mov r0, r4
 *   @0x107778 vcvt.s32.f64 s16, d7
 *   @0x10777c vmov r1, s17
 *   @0x107780 vmov r3, s16
 *   @0x107784 mul r3, r10, r3
 *   @0x107788 vmov s16, r3
 *   @0x10778c vcvt.f32.s32 s16, s16
 *   @0x107790 vmov r2, s16
 *   @0x107794 bl 0x1cab94 <_Z14Command_IsFreeP9CInstanceff>
 *   @0x107798 cmp r0, #0
 *   @0x10779c beq 0x107730 <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x228>
 *   @0x1077a0 b 0x1076d8 <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x1d0>
 *   @0x1077a4 mov r7, #100
 *   @0x1077a8 b 0x1077b4 <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x2ac>
 *   @0x1077ac subs r7, r7, #1
 *   @0x1077b0 beq 0x10787c <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x374>
 *   @0x1077b4 mov r0, r8
 *   @0x1077b8 bl 0xc4600 <_Z8YYRandomi>
 *   @0x1077bc add r0, r0, r6
 *   @0x1077c0 vmov s17, r0
 *   @0x1077c4 mov r0, r9
 *   @0x1077c8 bl 0xc4600 <_Z8YYRandomi>
 *   @0x1077cc vcvt.f32.u32 s17, s17
 *   @0x1077d0 vmov r1, s17
 *   @0x1077d4 add r0, r0, r5
 *   @0x1077d8 vmov s16, r0
 *   @0x1077dc mov r0, r4
 *   @0x1077e0 vcvt.f32.u32 s16, s16
 *   @0x1077e4 vmov r2, s16
 *   @0x1077e8 bl 0x1cab94 <_Z14Command_IsFreeP9CInstanceff>
 *   @0x1077ec cmp r0, #0
 *   @0x1077f0 beq 0x1077ac <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x2a4>
 *   @0x1077f4 b 0x1076d8 <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x1d0>
 *   @0x1077f8 vmov s12, r7
 *   @0x1077fc mov r10, #100
 *   @0x107800 vcvt.f32.s32 s18, s12
 *   @0x107804 b 0x107810 <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x308>
 *   @0x107808 subs r10, r10, #1
 *   @0x10780c beq 0x10787c <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x374>
 *   @0x107810 mov r0, r8
 *   @0x107814 bl 0xc4600 <_Z8YYRandomi>
 *   @0x107818 add r0, r0, r6
 *   @0x10781c vmov s13, r0
 *   @0x107820 vcvt.f32.u32 s15, s13
 *   @0x107824 vdiv.f32 s15, s15, s18
 *   @0x107828 vcvt.f64.f32 d6, s15
 *   @0x10782c vmov r0, r1, d6
 *   @0x107830 bl 0xb6598 <floor@plt>
 *   @0x107834 vmov d7, r0, r1
 *   @0x107838 mov r0, r9
 *   @0x10783c vcvt.s32.f64 s17, d7
 *   @0x107840 vmov r3, s17
 *   @0x107844 mul r3, r7, r3
 *   @0x107848 vmov s17, r3
 *   @0x10784c bl 0xc4600 <_Z8YYRandomi>
 *   @0x107850 vcvt.f32.s32 s17, s17
 *   @0x107854 vmov r1, s17
 *   @0x107858 add r0, r0, r5
 *   @0x10785c vmov s16, r0
 *   @0x107860 mov r0, r4
 *   @0x107864 vcvt.f32.u32 s16, s16
 *   @0x107868 vmov r2, s16
 *   @0x10786c bl 0x1cab94 <_Z14Command_IsFreeP9CInstanceff>
 *   @0x107870 cmp r0, #0
 *   @0x107874 beq 0x107808 <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x300>
 *   @0x107878 b 0x1076d8 <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x1d0>
 *   @0x10787c add sp, sp, #12
 *   @0x107880 vpop {d8, d9}
 *   @0x107884 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x107888 mov r0, r4
 *   @0x10788c mov r1, #1
 *   @0x107890 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb>
 *   @0x107894 b 0x10754c <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x107898 eoreq r6, lr, r4, lsl r4
 *
 * ══ §6/36 F_ActionMoveRandom(RValue&, CInstance*, CInstance*, int, RValue*)  0x13db90  size 916  229 条（0x13db90..0x13df24）
 * @func 0x13db90 0x13df24  size 916  229 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYRandom(int)×8 / 0xb66e8×4 / 0xb6598×4 / Command_IsFree(CInstance*, float, float)×4 / Sprite_Exists(int)×2 / YYGetInt32(RValue const*, int)×2 / F_ActionMoveRandom(RValue&, CInstance*, CInstance*, int, RValue*)+0x210 / F_ActionMoveRandom(RValue&, CInstance*, CInstance*, int, RValue*)+0x2f0
 * 字段偏移 top8: 0x4×3 / 0x388×1 / 0x8c×1 / 0x40×1 / 0x10×1 / 0x14×1 / 0x64×1 / 0xac×1
 * VFP 指令 99 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13db90 ldr r3, [pc, #0x388]
 *   @0x13db94 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x13db98 vpush {d8, d9}
 *   @0x13db9c ldr r3, [pc, r3]
 *   @0x13dba0 sub sp, sp, #12
 *   @0x13dba4 ldr r0, [r1, #0x8c]
 *   @0x13dba8 ldr r3, [r3]
 *   @0x13dbac mov r4, r1
 *   @0x13dbb0 ldr r10, [sp, #0x40]
 *   @0x13dbb4 ldr r8, [r3, #0x10]
 *   @0x13dbb8 ldr r9, [r3, #0x14]
 *   @0x13dbbc bl 0x1eee98 <_Z13Sprite_Existsi>
 *   @0x13dbc0 cmp r0, #0
 *   @0x13dbc4 beq 0x13dd7c <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x1ec>
 *   @0x13dbc8 ldrb r3, [r4, #0x64]
 *   @0x13dbcc cmp r3, #0
 *   @0x13dbd0 bne 0x13df10 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x380>
 *   @0x13dbd4 vldr s12, [r4, #232]
 *   @0x13dbd8 vcvt.f32.s32 s15, s12
 *   @0x13dbdc vldr s14, [r4, #180]
 *   @0x13dbe0 vsub.f32 s15, s14, s15
 *   @0x13dbe4 vcvt.f64.f32 d6, s15
 *   @0x13dbe8 vmov r0, r1, d6
 *   @0x13dbec bl 0xb66e8 <lrint@plt>
 *   @0x13dbf0 vldr s15, [r4, #180]
 *   @0x13dbf4 vmov s13, r8
 *   @0x13dbf8 vldr s12, [r4, #240]
 *   @0x13dbfc vcvt.f32.s32 s14, s13
 *   @0x13dc00 vadd.f32 s14, s14, s15
 *   @0x13dc04 vcvt.f32.s32 s15, s12
 *   @0x13dc08 vsub.f32 s15, s14, s15
 *   @0x13dc0c mov r11, r0
 *   @0x13dc10 mov r6, r0
 *   @0x13dc14 vcvt.f64.f32 d6, s15
 *   @0x13dc18 vmov r0, r1, d6
 *   @0x13dc1c bl 0xb66e8 <lrint@plt>
 *   @0x13dc20 vldr s13, [r4, #236]
 *   @0x13dc24 vcvt.f32.s32 s15, s13
 *   @0x13dc28 vldr s14, [r4, #184]
 *   @0x13dc2c vsub.f32 s15, s14, s15
 *   @0x13dc30 vcvt.f64.f32 d6, s15
 *   @0x13dc34 mov r8, r0
 *   @0x13dc38 vmov r0, r1, d6
 *   @0x13dc3c bl 0xb66e8 <lrint@plt>
 *   @0x13dc40 vldr s15, [r4, #184]
 *   @0x13dc44 vmov s13, r9
 *   @0x13dc48 vldr s12, [r4, #244]
 *   @0x13dc4c vcvt.f32.s32 s14, s13
 *   @0x13dc50 vadd.f32 s14, s14, s15
 *   @0x13dc54 vcvt.f32.s32 s15, s12
 *   @0x13dc58 vsub.f32 s15, s14, s15
 *   @0x13dc5c str r0, [sp, #0x4]
 *   @0x13dc60 mov r5, r0
 *   @0x13dc64 vcvt.f64.f32 d6, s15
 *   @0x13dc68 vmov r0, r1, d6
 *   @0x13dc6c bl 0xb66e8 <lrint@plt>
 *   @0x13dc70 mov r9, r0
 *   @0x13dc74 mov r0, r10
 *   @0x13dc78 mov r1, #0
 *   @0x13dc7c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13dc80 mov r1, #1
 *   @0x13dc84 rsb r8, r11, r8
 *   @0x13dc88 mov r7, r0
 *   @0x13dc8c mov r0, r10
 *   @0x13dc90 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13dc94 ldr r3, [sp, #0x4]
 *   @0x13dc98 cmp r7, #0
 *   @0x13dc9c rsb r9, r3, r9
 *   @0x13dca0 mov r10, r0
 *   @0x13dca4 ble 0x13dda0 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x210>
 *   @0x13dca8 cmp r0, #0
 *   @0x13dcac ble 0x13de80 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x2f0>
 *   @0x13dcb0 vmov s12, r0
 *   @0x13dcb4 mov r11, #99
 *   @0x13dcb8 vmov s13, r7
 *   @0x13dcbc vcvt.f32.s32 s19, s12
 *   @0x13dcc0 vcvt.f32.s32 s18, s13
 *   @0x13dcc4 b 0x13dcd0 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x13dcc8 subs r11, r11, #1
 *   @0x13dccc beq 0x13df04 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x374>
 *   @0x13dcd0 mov r0, r8
 *   @0x13dcd4 bl 0xc4600 <_Z8YYRandomi>
 *   @0x13dcd8 add r0, r0, r6
 *   @0x13dcdc vmov s14, r0
 *   @0x13dce0 vcvt.f32.u32 s15, s14
 *   @0x13dce4 vdiv.f32 s15, s15, s18
 *   @0x13dce8 vcvt.f64.f32 d6, s15
 *   @0x13dcec vmov r0, r1, d6
 *   @0x13dcf0 bl 0xb6598 <floor@plt>
 *   @0x13dcf4 vmov d7, r0, r1
 *   @0x13dcf8 mov r0, r9
 *   @0x13dcfc vcvt.s32.f64 s17, d7
 *   @0x13dd00 vmov r3, s17
 *   @0x13dd04 mul r3, r7, r3
 *   @0x13dd08 vmov s17, r3
 *   @0x13dd0c bl 0xc4600 <_Z8YYRandomi>
 *   @0x13dd10 vcvt.f32.s32 s17, s17
 *   @0x13dd14 add r0, r0, r5
 *   @0x13dd18 vmov s12, r0
 *   @0x13dd1c vcvt.f32.u32 s15, s12
 *   @0x13dd20 vdiv.f32 s15, s15, s19
 *   @0x13dd24 vcvt.f64.f32 d6, s15
 *   @0x13dd28 vmov r0, r1, d6
 *   @0x13dd2c bl 0xb6598 <floor@plt>
 *   @0x13dd30 vmov d7, r0, r1
 *   @0x13dd34 mov r0, r4
 *   @0x13dd38 vcvt.s32.f64 s16, d7
 *   @0x13dd3c vmov r1, s17
 *   @0x13dd40 vmov r3, s16
 *   @0x13dd44 mul r3, r10, r3
 *   @0x13dd48 vmov s16, r3
 *   @0x13dd4c vcvt.f32.s32 s16, s16
 *   @0x13dd50 vmov r2, s16
 *   @0x13dd54 bl 0x1cab94 <_Z14Command_IsFreeP9CInstanceff>
 *   @0x13dd58 cmp r0, #0
 *   @0x13dd5c beq 0x13dcc8 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x138>
 *   @0x13dd60 vmov r1, s17
 *   @0x13dd64 mov r0, r4
 *   @0x13dd68 vmov r2, s16
 *   @0x13dd6c add sp, sp, #12
 *   @0x13dd70 vpop {d8, d9}
 *   @0x13dd74 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x13dd78 b 0x193e7c <_ZN9CInstance11SetPositionEff>
 *   @0x13dd7c ldr r0, [r4, #0xac]
 *   @0x13dd80 bl 0x1eee98 <_Z13Sprite_Existsi>
 *   @0x13dd84 cmp r0, #0
 *   @0x13dd88 bne 0x13dbc8 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x13dd8c mov r5, r0
 *   @0x13dd90 mov r6, r0
 *   @0x13dd94 str r0, [sp, #0x4]
 *   @0x13dd98 mov r11, r0
 *   @0x13dd9c b 0x13dc74 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x13dda0 cmp r0, #0
 *   @0x13dda4 ble 0x13de2c <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x29c>
 *   @0x13dda8 vmov s12, r0
 *   @0x13ddac mov r7, #99
 *   @0x13ddb0 vcvt.f32.s32 s19, s12
 *   @0x13ddb4 b 0x13ddc0 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x230>
 *   @0x13ddb8 subs r7, r7, #1
 *   @0x13ddbc beq 0x13df04 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x374>
 *   @0x13ddc0 mov r0, r8
 *   @0x13ddc4 bl 0xc4600 <_Z8YYRandomi>
 *   @0x13ddc8 add r0, r0, r6
 *   @0x13ddcc vmov s17, r0
 *   @0x13ddd0 mov r0, r9
 *   @0x13ddd4 bl 0xc4600 <_Z8YYRandomi>
 *   @0x13ddd8 vcvt.f32.u32 s17, s17
 *   @0x13dddc add r0, r0, r5
 *   @0x13dde0 vmov s13, r0
 *   @0x13dde4 vcvt.f32.u32 s15, s13
 *   @0x13dde8 vdiv.f32 s15, s15, s19
 *   @0x13ddec vcvt.f64.f32 d6, s15
 *   @0x13ddf0 vmov r0, r1, d6
 *   @0x13ddf4 bl 0xb6598 <floor@plt>
 *   @0x13ddf8 vmov d7, r0, r1
 *   @0x13ddfc mov r0, r4
 *   @0x13de00 vcvt.s32.f64 s16, d7
 *   @0x13de04 vmov r1, s17
 *   @0x13de08 vmov r3, s16
 *   @0x13de0c mul r3, r10, r3
 *   @0x13de10 vmov s16, r3
 *   @0x13de14 vcvt.f32.s32 s16, s16
 *   @0x13de18 vmov r2, s16
 *   @0x13de1c bl 0x1cab94 <_Z14Command_IsFreeP9CInstanceff>
 *   @0x13de20 cmp r0, #0
 *   @0x13de24 beq 0x13ddb8 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x228>
 *   @0x13de28 b 0x13dd60 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x1d0>
 *   @0x13de2c mov r7, #99
 *   @0x13de30 b 0x13de3c <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x2ac>
 *   @0x13de34 subs r7, r7, #1
 *   @0x13de38 beq 0x13df04 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x374>
 *   @0x13de3c mov r0, r8
 *   @0x13de40 bl 0xc4600 <_Z8YYRandomi>
 *   @0x13de44 add r0, r0, r6
 *   @0x13de48 vmov s17, r0
 *   @0x13de4c mov r0, r9
 *   @0x13de50 bl 0xc4600 <_Z8YYRandomi>
 *   @0x13de54 vcvt.f32.u32 s17, s17
 *   @0x13de58 vmov r1, s17
 *   @0x13de5c add r0, r0, r5
 *   @0x13de60 vmov s16, r0
 *   @0x13de64 mov r0, r4
 *   @0x13de68 vcvt.f32.u32 s16, s16
 *   @0x13de6c vmov r2, s16
 *   @0x13de70 bl 0x1cab94 <_Z14Command_IsFreeP9CInstanceff>
 *   @0x13de74 cmp r0, #0
 *   @0x13de78 beq 0x13de34 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x2a4>
 *   @0x13de7c b 0x13dd60 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x1d0>
 *   @0x13de80 vmov s12, r7
 *   @0x13de84 mov r10, #99
 *   @0x13de88 vcvt.f32.s32 s18, s12
 *   @0x13de8c b 0x13de98 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x308>
 *   @0x13de90 subs r10, r10, #1
 *   @0x13de94 beq 0x13df04 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x374>
 *   @0x13de98 mov r0, r8
 *   @0x13de9c bl 0xc4600 <_Z8YYRandomi>
 *   @0x13dea0 add r0, r0, r6
 *   @0x13dea4 vmov s13, r0
 *   @0x13dea8 vcvt.f32.u32 s15, s13
 *   @0x13deac vdiv.f32 s15, s15, s18
 *   @0x13deb0 vcvt.f64.f32 d6, s15
 *   @0x13deb4 vmov r0, r1, d6
 *   @0x13deb8 bl 0xb6598 <floor@plt>
 *   @0x13debc vmov d7, r0, r1
 *   @0x13dec0 mov r0, r9
 *   @0x13dec4 vcvt.s32.f64 s17, d7
 *   @0x13dec8 vmov r3, s17
 *   @0x13decc mul r3, r7, r3
 *   @0x13ded0 vmov s17, r3
 *   @0x13ded4 bl 0xc4600 <_Z8YYRandomi>
 *   @0x13ded8 vcvt.f32.s32 s17, s17
 *   @0x13dedc vmov r1, s17
 *   @0x13dee0 add r0, r0, r5
 *   @0x13dee4 vmov s16, r0
 *   @0x13dee8 mov r0, r4
 *   @0x13deec vcvt.f32.u32 s16, s16
 *   @0x13def0 vmov r2, s16
 *   @0x13def4 bl 0x1cab94 <_Z14Command_IsFreeP9CInstanceff>
 *   @0x13def8 cmp r0, #0
 *   @0x13defc beq 0x13de90 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x300>
 *   @0x13df00 b 0x13dd60 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x1d0>
 *   @0x13df04 add sp, sp, #12
 *   @0x13df08 vpop {d8, d9}
 *   @0x13df0c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x13df10 mov r0, r4
 *   @0x13df14 mov r1, #1
 *   @0x13df18 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb>
 *   @0x13df1c b 0x13dbd4 <_Z18F_ActionMoveRandomR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x13df20 eoreq pc, r10, r12, lsl #27
 *
 * ══ §7/36 GR_3D_Draw_Ellipsoid(float, float, float, float, float, float, int, float, float, int)  0x17934c  size 916  229 条（0x17934c..0x1796e0）
 * @func 0x17934c 0x1796e0  size 916  229 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb658c×5 / 0xb6580×5 / Graphics::Flush()×2 / GR_3D_Vertex_N_Texture(float, float, float, float, float, float, float, float)×2 / GR_D3D_Get_Texture_Repeat() / GR_D3D_Set_Texture_Repeat(bool) / GR_3D_Draw_Ellipsoid(float, float, float, float, float, float, int, float, float, int)+0x2e4 / GR_3D_Draw_Ellipsoid(float, float, float, float, float, float, int, float, float, int)+0x348
 * 字段偏移 top8: 0x38×2 / 0x3c×2 / 0x4×2 / 0x-344×1 / 0x4b8×1 / 0x4c4×1 / 0x1c×1 / 0x-340×1
 * VFP 指令 140 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17934c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x179350 vpush {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x179354 sub sp, sp, #1088
 *   @0x179358 sub sp, sp, #12
 *   @0x17935c vmov s16, r2
 *   @0x179360 add r2, sp, #2048
 *   @0x179364 vldr s17, [r2, #-844]
 *   @0x179368 add r2, sp, #2048
 *   @0x17936c vmov s18, r1
 *   @0x179370 add r1, sp, #2048
 *   @0x179374 vldr s27, [r1, #-848]
 *   @0x179378 ldr r1, [r2, #-0x344]
 *   @0x17937c vmov s28, r3
 *   @0x179380 ldr r3, [sp, #0x4b8]
 *   @0x179384 vmov s21, r0
 *   @0x179388 ldr r6, [sp, #0x4c4]
 *   @0x17938c str r1, [sp, #0x1c]
 *   @0x179390 ldr r1, [r2, #-0x340]
 *   @0x179394 str r3, [sp, #0x38]
 *   @0x179398 str r1, [sp, #0x30]
 *   @0x17939c bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x1793a0 bl 0x1689e0 <_Z25GR_D3D_Get_Texture_Repeatv>
 *   @0x1793a4 str r0, [sp, #0x3c]
 *   @0x1793a8 mov r0, #1
 *   @0x1793ac bl 0x168870 <_Z25GR_D3D_Set_Texture_Repeatb>
 *   @0x1793b0 cmp r6, #2
 *   @0x1793b4 ble 0x179630 <_Z20GR_3D_Draw_Ellipsoidffffffiffi+0x2e4>
 *   @0x1793b8 cmp r6, #128
 *   @0x1793bc ble 0x179694 <_Z20GR_3D_Draw_Ellipsoidffffffiffi+0x348>
 *   @0x1793c0 mov r5, #1065353216
 *   @0x1793c4 mov r0, #0
 *   @0x1793c8 vmov s20, r0
 *   @0x1793cc mov r9, #64
 *   @0x1793d0 vmov s26, r5
 *   @0x1793d4 mov r6, #128
 *   @0x1793d8 vldr s19, [pc, #740]
 *   @0x1793dc vldr s24, [pc, #740]
 *   @0x1793e0 vldr s25, [pc, #740]
 *   @0x1793e4 vldr s23, [pc, #740]
 *   @0x1793e8 add r1, sp, #580
 *   @0x1793ec add r11, sp, #64
 *   @0x1793f0 str r1, [sp, #0x34]
 *   @0x1793f4 mov r4, #0
 *   @0x1793f8 mov r8, r1
 *   @0x1793fc vldr s29, [pc, #720]
 *   @0x179400 mov r7, r11
 *   @0x179404 b 0x179430 <_Z20GR_3D_Draw_Ellipsoidffffffiffi+0xe4>
 *   @0x179408 vmov s14, r4
 *   @0x17940c vcvt.f32.s32 s22, s14
 *   @0x179410 vadd.f32 s22, s22, s22
 *   @0x179414 vmul.f32 s22, s22, s29
 *   @0x179418 vdiv.f32 s22, s22, s23
 *   @0x17941c vmov r0, s22
 *   @0x179420 bl 0xb658c <cosf@plt>
 *   @0x179424 mov r5, r0
 *   @0x179428 vmov r0, s22
 *   @0x17942c bl 0xb6580 <sinf@plt>
 *   @0x179430 add r4, r4, #1
 *   @0x179434 str r5, [r7], #4
 *   @0x179438 cmp r6, r4
 *   @0x17943c str r0, [r8], #4
 *   @0x179440 bge 0x179408 <_Z20GR_3D_Draw_Ellipsoidffffffiffi+0xbc>
 *   @0x179444 vadd.f32 s22, s28, s21
 *   @0x179448 vldr s15, [pc, #648]
 *   @0x17944c vstr s15, [sp, #32]
 *   @0x179450 mov r8, #1
 *   @0x179454 vmov.f32 s15, #5.000000e-01
 *   @0x179458 vsub.f32 s21, s28, s21
 *   @0x17945c vmul.f32 s21, s21, s15
 *   @0x179460 vadd.f32 s13, s27, s18
 *   @0x179464 vstr s21, [sp, #36]
 *   @0x179468 vsub.f32 s18, s27, s18
 *   @0x17946c vadd.f32 s14, s17, s16
 *   @0x179470 vsub.f32 s16, s17, s16
 *   @0x179474 vmul.f32 s18, s18, s15
 *   @0x179478 vmul.f32 s16, s16, s15
 *   @0x17947c vstr s18, [sp, #40]
 *   @0x179480 vmul.f32 s22, s22, s15
 *   @0x179484 vstr s16, [sp, #44]
 *   @0x179488 vmul.f32 s21, s13, s15
 *   @0x17948c vmul.f32 s27, s14, s15
 *   @0x179490 mov r0, #5
 *   @0x179494 ldr r1, [sp, #0x38]
 *   @0x179498 vldr s16, [sp, #32]
 *   @0x17949c bl 0x1769dc <_Z21GR_3D_Primitive_Beginii>
 *   @0x1794a0 vldr s14, [sp, #48]
 *   @0x1794a4 add r5, sp, #580
 *   @0x1794a8 mov r10, r11
 *   @0x1794ac mov r4, #0
 *   @0x1794b0 vmov.f32 s15, s27
 *   @0x1794b4 vmul.f32 s16, s16, s14
 *   @0x1794b8 vldr s14, [sp, #44]
 *   @0x1794bc vmla.f32 s15, s14, s26
 *   @0x1794c0 vldr s14, [sp, #36]
 *   @0x1794c4 vdiv.f32 s31, s16, s25
 *   @0x1794c8 vmov r7, s15
 *   @0x1794cc vmov s15, r8
 *   @0x1794d0 vcvt.f32.s32 s15, s15
 *   @0x1794d4 vmul.f32 s30, s14, s20
 *   @0x1794d8 vldr s14, [sp, #48]
 *   @0x1794dc vstr s15, [sp, #32]
 *   @0x1794e0 vmul.f32 s29, s15, s14
 *   @0x1794e4 vldr s14, [sp, #36]
 *   @0x1794e8 vldr s15, [sp, #40]
 *   @0x1794ec vmul.f32 s14, s14, s19
 *   @0x1794f0 vmul.f32 s28, s15, s20
 *   @0x1794f4 vstr s14, [sp, #16]
 *   @0x1794f8 vldr s14, [sp, #44]
 *   @0x1794fc vmul.f32 s15, s15, s19
 *   @0x179500 vmul.f32 s14, s14, s24
 *   @0x179504 vstr s15, [sp, #20]
 *   @0x179508 vstr s14, [sp, #24]
 *   @0x17950c vmov s15, r4
 *   @0x179510 vldmia r5!, {s17}
 *   @0x179514 vldr s14, [sp, #28]
 *   @0x179518 vstr s26, [sp, #4]
 *   @0x17951c vcvt.f32.s32 s18, s15
 *   @0x179520 vstr s31, [sp, #12]
 *   @0x179524 vldmia r10!, {s16}
 *   @0x179528 mov r2, r7
 *   @0x17952c add r4, r4, #1
 *   @0x179530 vmul.f32 s18, s18, s14
 *   @0x179534 vmul.f32 s15, s17, s20
 *   @0x179538 vdiv.f32 s18, s18, s23
 *   @0x17953c vstr s15, [sp]
 *   @0x179540 vmov.f32 s15, s21
 *   @0x179544 vstr s18, [sp, #8]
 *   @0x179548 vmla.f32 s15, s17, s28
 *   @0x17954c vmov.f32 s14, s22
 *   @0x179550 vmov r1, s15
 *   @0x179554 vmla.f32 s14, s16, s30
 *   @0x179558 vmul.f32 s15, s16, s20
 *   @0x17955c vmov r0, s14
 *   @0x179560 vmov r3, s15
 *   @0x179564 bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff>
 *   @0x179568 vdiv.f32 s14, s29, s25
 *   @0x17956c vstr s18, [sp, #8]
 *   @0x179570 vstr s24, [sp, #4]
 *   @0x179574 vmul.f32 s15, s17, s19
 *   @0x179578 vstr s14, [sp, #12]
 *   @0x17957c vmov.f32 s14, s22
 *   @0x179580 vstr s15, [sp]
 *   @0x179584 vldr s15, [sp, #16]
 *   @0x179588 vmla.f32 s14, s16, s15
 *   @0x17958c vldr s15, [sp, #20]
 *   @0x179590 vmov r0, s14
 *   @0x179594 vmov.f32 s14, s21
 *   @0x179598 vmla.f32 s14, s17, s15
 *   @0x17959c vmul.f32 s16, s16, s19
 *   @0x1795a0 vmov r1, s14
 *   @0x1795a4 vldr s14, [sp, #24]
 *   @0x1795a8 vadd.f32 s14, s14, s27
 *   @0x1795ac vmov r3, s16
 *   @0x1795b0 vmov r2, s14
 *   @0x1795b4 bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff>
 *   @0x1795b8 cmp r6, r4
 *   @0x1795bc bge 0x17950c <_Z20GR_3D_Draw_Ellipsoidffffffiffi+0x1c0>
 *   @0x1795c0 bl 0x176ad0 <_Z19GR_3D_Primitive_Endv>
 *   @0x1795c4 cmp r8, r9
 *   @0x1795c8 bge 0x179614 <_Z20GR_3D_Draw_Ellipsoidffffffiffi+0x2c8>
 *   @0x1795cc add r8, r8, #1
 *   @0x1795d0 movw r1, #0xfdb
 *   @0x1795d4 movt r1, #0x4049
 *   @0x1795d8 vmov.f32 s26, s24
 *   @0x1795dc vmov s15, r8
 *   @0x1795e0 vmov s14, r1
 *   @0x1795e4 vcvt.f32.s32 s16, s15
 *   @0x1795e8 vmul.f32 s16, s16, s14
 *   @0x1795ec vdiv.f32 s16, s16, s25
 *   @0x1795f0 vmov r0, s16
 *   @0x1795f4 bl 0xb658c <cosf@plt>
 *   @0x1795f8 vmov.f32 s20, s19
 *   @0x1795fc mov r4, r0
 *   @0x179600 vmov r0, s16
 *   @0x179604 bl 0xb6580 <sinf@plt>
 *   @0x179608 vmov s24, r4
 *   @0x17960c vmov s19, r0
 *   @0x179610 b 0x179490 <_Z20GR_3D_Draw_Ellipsoidffffffiffi+0x144>
 *   @0x179614 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x179618 ldr r0, [sp, #0x3c]
 *   @0x17961c add sp, sp, #1088
 *   @0x179620 add sp, sp, #12
 *   @0x179624 vpop {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x179628 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x17962c b 0x168870 <_Z25GR_D3D_Set_Texture_Repeatb>
 *   @0x179630 vmov.f32 s25, #2.000000e+00
 *   @0x179634 vldr s22, [pc, #156]
 *   @0x179638 mov r9, #2
 *   @0x17963c mov r6, #3
 *   @0x179640 vldr s19, [pc, #148]
 *   @0x179644 vmov.f32 s23, #3.000000e+00
 *   @0x179648 vmov.f32 s20, s22
 *   @0x17964c vmov r0, s20
 *   @0x179650 bl 0xb658c <cosf@plt>
 *   @0x179654 vmov s26, r0
 *   @0x179658 vmov r0, s20
 *   @0x17965c bl 0xb6580 <sinf@plt>
 *   @0x179660 vmov s20, r0
 *   @0x179664 vmov r0, s19
 *   @0x179668 bl 0xb658c <cosf@plt>
 *   @0x17966c vmov s24, r0
 *   @0x179670 vmov r0, s19
 *   @0x179674 bl 0xb6580 <sinf@plt>
 *   @0x179678 vmov s19, r0
 *   @0x17967c vmov r0, s22
 *   @0x179680 bl 0xb658c <cosf@plt>
 *   @0x179684 mov r5, r0
 *   @0x179688 vmov r0, s22
 *   @0x17968c bl 0xb6580 <sinf@plt>
 *   @0x179690 b 0x1793e8 <_Z20GR_3D_Draw_Ellipsoidffffffiffi+0x9c>
 *   @0x179694 add r9, r6, #1
 *   @0x179698 vmov s15, r6
 *   @0x17969c vldr s20, [pc, #52]
 *   @0x1796a0 vldr s19, [pc, #44]
 *   @0x1796a4 asr r9, r9, #1
 *   @0x1796a8 vcvt.f32.s32 s23, s15
 *   @0x1796ac vmov s14, r9
 *   @0x1796b0 vcvt.f32.s32 s25, s14
 *   @0x1796b4 vdiv.f32 s22, s20, s23
 *   @0x1796b8 vdiv.f32 s19, s19, s25
 *   @0x1796bc vdiv.f32 s20, s20, s25
 *   @0x1796c0 b 0x17964c <_Z20GR_3D_Draw_Ellipsoidffffffiffi+0x300>
 *   @0x1796c4 vstrlo d31, [r8, #-192]
 *   @0x1796c8 svclo #0x7fb10f
 *   @0x1796cc addmi r0, r0, #0
 *   @0x1796d0 movwmi r0, #0x0
 *   @0x1796d4 ldrdmi r0, r1, [r9], #-251
 *   @0x1796d8 andeq r0, r0, r0
 *   @0x1796dc svclo #0xc90fdb
 *
 * ══ §8/36 JS_Error_prototype_toString(RValue&, CInstance*, CInstance*, int, RValue*)  0x256784  size 916  229 条（0x256784..0x256b18）
 * @func 0x256784 0x256b18  size 916  229 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYAlloc(int)×5 / 0xb65bc×5 / 0xb6538×4 / 0xb65a4×4 / YYFree(void const*)×3 / F_JS_Object_Get(YYObjectBase*, RValue*, char const*)×2 / F_JS_ToString(RValue&, RValue*)×2 / YYGetString(RValue const*, int)×2
 * 字段偏移 top8: 0x4×15 / 0xc×14 / 0x8×13 / 0x2×2 / 0x370×1 / 0x40×1 / 0x350×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x256784 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x256788 mov r5, r1
 *   @0x25678c ldr r1, [pc, #0x370]
 *   @0x256790 sub sp, sp, #84
 *   @0x256794 mov r8, r0
 *   @0x256798 ldr r0, [r5, #0x40]
 *   @0x25679c add r1, pc, r1
 *   @0x2567a0 bl 0xb6574 <strcmp@plt>
 *   @0x2567a4 subs r4, r0, #0
 *   @0x2567a8 bne 0x256960 <_Z27JS_Error_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x1dc>
 *   @0x2567ac add r7, sp, #16
 *   @0x2567b0 ldr r2, [pc, #0x350]
 *   @0x2567b4 mov r0, r5
 *   @0x2567b8 mov r6, #5
 *   @0x2567bc add r2, pc, r2
 *   @0x2567c0 mov r1, r7
 *   @0x2567c4 str r6, [sp, #0x1c]
 *   @0x2567c8 str r6, [sp, #0x2c]
 *   @0x2567cc bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x2567d0 mov r1, r7
 *   @0x2567d4 add r7, sp, #32
 *   @0x2567d8 mov r0, r7
 *   @0x2567dc bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x2567e0 mov r0, r7
 *   @0x2567e4 mov r1, r4
 *   @0x2567e8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x2567ec ldr r2, [pc, #0x318]
 *   @0x2567f0 str r6, [sp, #0x3c]
 *   @0x2567f4 add r2, pc, r2
 *   @0x2567f8 str r6, [sp, #0x4c]
 *   @0x2567fc mov r7, r0
 *   @0x256800 mov r0, r5
 *   @0x256804 add r5, sp, #48
 *   @0x256808 mov r1, r5
 *   @0x25680c bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x256810 mov r1, r5
 *   @0x256814 add r5, sp, #64
 *   @0x256818 mov r0, r5
 *   @0x25681c bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x256820 mov r0, r5
 *   @0x256824 mov r1, r4
 *   @0x256828 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x25682c cmp r7, #0
 *   @0x256830 str r4, [sp, #0x4]
 *   @0x256834 str r4, [sp, #0x8]
 *   @0x256838 str r4, [sp, #0xc]
 *   @0x25683c mov r5, r0
 *   @0x256840 beq 0x256850 <_Z27JS_Error_prototype_toStringR6RValueP9CInstanceS2_iPS_+0xcc>
 *   @0x256844 ldrb r3, [r7]
 *   @0x256848 cmp r3, #0
 *   @0x25684c bne 0x2568e4 <_Z27JS_Error_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x256850 cmp r5, #0
 *   @0x256854 beq 0x256958 <_Z27JS_Error_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x1d4>
 *   @0x256858 mov r0, r5
 *   @0x25685c bl 0xb6538 <strlen@plt>
 *   @0x256860 adds r3, r0, #1
 *   @0x256864 mov r4, r0
 *   @0x256868 movmi r0, #0
 *   @0x25686c bmi 0x2568a0 <_Z27JS_Error_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x256870 add r3, r3, r3, lsl #1
 *   @0x256874 asr r6, r3, #1
 *   @0x256878 mov r0, r6
 *   @0x25687c bl 0xcef4c <_Z7YYAlloci>
 *   @0x256880 mov r1, #0
 *   @0x256884 ldr r2, [sp, #0x8]
 *   @0x256888 str r0, [sp, #0x4]
 *   @0x25688c bl 0xb65bc <memcpy@plt>
 *   @0x256890 ldr r0, [sp, #0x4]
 *   @0x256894 ldr r3, [sp, #0xc]
 *   @0x256898 str r6, [sp, #0x8]
 *   @0x25689c add r0, r0, r3
 *   @0x2568a0 mov r1, r5
 *   @0x2568a4 bl 0xb65a4 <strcpy@plt>
 *   @0x2568a8 ldr r3, [sp, #0xc]
 *   @0x2568ac add r4, r4, r3
 *   @0x2568b0 cmp r4, #0
 *   @0x2568b4 beq 0x256958 <_Z27JS_Error_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x1d4>
 *   @0x2568b8 ldr r1, [sp, #0x4]
 *   @0x2568bc mov r0, r8
 *   @0x2568c0 mov r3, #0
 *   @0x2568c4 str r3, [sp, #0xc]
 *   @0x2568c8 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x2568cc ldr r0, [sp, #0x4]
 *   @0x2568d0 cmp r0, #0
 *   @0x2568d4 beq 0x2568dc <_Z27JS_Error_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x158>
 *   @0x2568d8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x2568dc add sp, sp, #84
 *   @0x2568e0 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x2568e4 cmp r5, #0
 *   @0x2568e8 mov r0, r7
 *   @0x2568ec beq 0x2568fc <_Z27JS_Error_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x178>
 *   @0x2568f0 ldrb r3, [r5]
 *   @0x2568f4 cmp r3, #0
 *   @0x2568f8 bne 0x256974 <_Z27JS_Error_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x1f0>
 *   @0x2568fc bl 0xb6538 <strlen@plt>
 *   @0x256900 adds r3, r0, #1
 *   @0x256904 mov r4, r0
 *   @0x256908 movmi r0, #0
 *   @0x25690c bmi 0x256940 <_Z27JS_Error_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x1bc>
 *   @0x256910 add r3, r3, r3, lsl #1
 *   @0x256914 asr r5, r3, #1
 *   @0x256918 mov r0, r5
 *   @0x25691c bl 0xcef4c <_Z7YYAlloci>
 *   @0x256920 mov r1, #0
 *   @0x256924 ldr r2, [sp, #0x8]
 *   @0x256928 str r0, [sp, #0x4]
 *   @0x25692c bl 0xb65bc <memcpy@plt>
 *   @0x256930 ldr r0, [sp, #0x4]
 *   @0x256934 ldr r3, [sp, #0xc]
 *   @0x256938 str r5, [sp, #0x8]
 *   @0x25693c add r0, r0, r3
 *   @0x256940 mov r1, r7
 *   @0x256944 bl 0xb65a4 <strcpy@plt>
 *   @0x256948 ldr r3, [sp, #0xc]
 *   @0x25694c add r4, r4, r3
 *   @0x256950 cmp r4, #0
 *   @0x256954 bne 0x2568b8 <_Z27JS_Error_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x256958 add r1, sp, #12
 *   @0x25695c b 0x2568bc <_Z27JS_Error_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x138>
 *   @0x256960 ldr r0, [pc, #0x1a8]
 *   @0x256964 add r0, pc, r0
 *   @0x256968 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x25696c add sp, sp, #84
 *   @0x256970 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x256974 bl 0xb6538 <strlen@plt>
 *   @0x256978 adds r3, r0, #1
 *   @0x25697c mov r6, r0
 *   @0x256980 movmi r0, r4
 *   @0x256984 bmi 0x2569b8 <_Z27JS_Error_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x234>
 *   @0x256988 add r3, r3, r3, lsl #1
 *   @0x25698c asr r9, r3, #1
 *   @0x256990 mov r0, r9
 *   @0x256994 bl 0xcef4c <_Z7YYAlloci>
 *   @0x256998 mov r1, r4
 *   @0x25699c ldr r2, [sp, #0x8]
 *   @0x2569a0 str r0, [sp, #0x4]
 *   @0x2569a4 bl 0xb65bc <memcpy@plt>
 *   @0x2569a8 ldr r0, [sp, #0x4]
 *   @0x2569ac ldr r3, [sp, #0xc]
 *   @0x2569b0 str r9, [sp, #0x8]
 *   @0x2569b4 add r0, r0, r3
 *   @0x2569b8 mov r1, r7
 *   @0x2569bc bl 0xb65a4 <strcpy@plt>
 *   @0x2569c0 ldr r3, [sp, #0xc]
 *   @0x2569c4 ldr r2, [sp, #0x8]
 *   @0x2569c8 add r3, r6, r3
 *   @0x2569cc str r3, [sp, #0xc]
 *   @0x2569d0 mvn r1, r3
 *   @0x2569d4 add r1, r2, r1
 *   @0x2569d8 cmp r1, #2
 *   @0x2569dc bgt 0x256a3c <_Z27JS_Error_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x2b8>
 *   @0x2569e0 cmp r2, #0
 *   @0x2569e4 add r3, r3, #3
 *   @0x2569e8 addne r2, r2, r2, lsl #1
 *   @0x2569ec ldr r6, [sp, #0x4]
 *   @0x2569f0 moveq r4, #4
 *   @0x2569f4 addne r2, r2, r2, lsr #31
 *   @0x2569f8 asrne r4, r2, #1
 *   @0x2569fc cmp r3, r4
 *   @0x256a00 addgt r3, r3, r3, lsl #1
 *   @0x256a04 addgt r3, r3, r3, lsr #31
 *   @0x256a08 asrgt r4, r3, #1
 *   @0x256a0c mov r0, r4
 *   @0x256a10 bl 0xcef4c <_Z7YYAlloci>
 *   @0x256a14 ldr r2, [sp, #0x8]
 *   @0x256a18 mov r1, r6
 *   @0x256a1c str r0, [sp, #0x4]
 *   @0x256a20 bl 0xb65bc <memcpy@plt>
 *   @0x256a24 cmp r6, #0
 *   @0x256a28 str r4, [sp, #0x8]
 *   @0x256a2c beq 0x256a38 <_Z27JS_Error_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x2b4>
 *   @0x256a30 mov r0, r6
 *   @0x256a34 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x256a38 ldr r3, [sp, #0xc]
 *   @0x256a3c ldr r1, [pc, #0xd0]
 *   @0x256a40 mov r0, r5
 *   @0x256a44 ldr r2, [sp, #0x4]
 *   @0x256a48 add r1, pc, r1
 *   @0x256a4c add r12, r2, r3
 *   @0x256a50 ldrh lr, [r1]
 *   @0x256a54 ldrb r1, [r1, #0x2]
 *   @0x256a58 strh lr, [r2, r3]
 *   @0x256a5c strb r1, [r12, #0x2]
 *   @0x256a60 ldr r6, [sp, #0xc]
 *   @0x256a64 add r6, r6, #2
 *   @0x256a68 str r6, [sp, #0xc]
 *   @0x256a6c bl 0xb6538 <strlen@plt>
 *   @0x256a70 ldr r3, [sp, #0x8]
 *   @0x256a74 mvn r1, r6
 *   @0x256a78 add r1, r3, r1
 *   @0x256a7c add r2, r0, #1
 *   @0x256a80 mov r4, r0
 *   @0x256a84 cmp r2, r1
 *   @0x256a88 ble 0x256ae8 <_Z27JS_Error_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x364>
 *   @0x256a8c cmp r3, #0
 *   @0x256a90 moveq r3, r2
 *   @0x256a94 add r2, r6, r2
 *   @0x256a98 add r3, r3, r3, lsl #1
 *   @0x256a9c ldr r6, [sp, #0x4]
 *   @0x256aa0 add r3, r3, r3, lsr #31
 *   @0x256aa4 asr r7, r3, #1
 *   @0x256aa8 cmp r7, r2
 *   @0x256aac addlt r2, r2, r2, lsl #1
 *   @0x256ab0 addlt r2, r2, r2, lsr #31
 *   @0x256ab4 asrlt r7, r2, #1
 *   @0x256ab8 mov r0, r7
 *   @0x256abc bl 0xcef4c <_Z7YYAlloci>
 *   @0x256ac0 ldr r2, [sp, #0x8]
 *   @0x256ac4 mov r1, r6
 *   @0x256ac8 str r0, [sp, #0x4]
 *   @0x256acc bl 0xb65bc <memcpy@plt>
 *   @0x256ad0 cmp r6, #0
 *   @0x256ad4 str r7, [sp, #0x8]
 *   @0x256ad8 beq 0x256ae4 <_Z27JS_Error_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x360>
 *   @0x256adc mov r0, r6
 *   @0x256ae0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x256ae4 ldr r6, [sp, #0xc]
 *   @0x256ae8 ldr r0, [sp, #0x4]
 *   @0x256aec mov r1, r5
 *   @0x256af0 add r0, r0, r6
 *   @0x256af4 bl 0xb65a4 <strcpy@plt>
 *   @0x256af8 ldr r3, [sp, #0xc]
 *   @0x256afc add r4, r4, r3
 *   @0x256b00 b 0x2568b0 <_Z27JS_Error_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x256b04 andeq pc, pc, r8, lsl #3
 *   @0x256b08 andeq r10, sp, r12, asr #32
 *   @0x256b0c muleq pc, r0, pc
 *   @0x256b10 andeq pc, pc, r4, ror #11
 *   @0x256b14 andeq r9, lr, r12, ror #17
 *
 * ══ §9/36 CSingleFingerGesture::GenerateMap(int, int, int, int, long long)  0x1d990c  size 912  228 条（0x1d990c..0x1d9c9c）
 * @func 0x1d990c 0x1d9c9c  size 912  228 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ConvertRawPos(float, float, int, float&, float&, float&, float&)×3 / CreateDsMap(int, ...)
 * 字段偏移 top8: 0x4×5 / 0x2c×3 / 0x8×3 / 0x40×2 / 0x44×2 / 0x22c×2 / 0x184×2 / 0x17c×2
 * VFP 指令 84 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d990c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1d9910 vpush {d8, d9, d10}
 *   @0x1d9914 mov r6, r1
 *   @0x1d9918 mov r5, r2
 *   @0x1d991c vmov s12, r6
 *   @0x1d9920 vmov s13, r5
 *   @0x1d9924 ldr r1, [r0, #0x2c]
 *   @0x1d9928 vcvt.f32.s32 s12, s12
 *   @0x1d992c sub sp, sp, #364
 *   @0x1d9930 mov r4, r0
 *   @0x1d9934 mov r7, r3
 *   @0x1d9938 mov r2, r1
 *   @0x1d993c add r3, sp, #332
 *   @0x1d9940 add r1, sp, #316
 *   @0x1d9944 str r3, [sp]
 *   @0x1d9948 str r1, [sp, #0x8]
 *   @0x1d994c add r3, sp, #312
 *   @0x1d9950 str r3, [sp, #0x4]
 *   @0x1d9954 add r3, sp, #328
 *   @0x1d9958 ldr r8, [pc, #0x2ec]
 *   @0x1d995c vcvt.f32.s32 s13, s13
 *   @0x1d9960 ldr r11, [pc, #0x2e8]
 *   @0x1d9964 vmov r0, s12
 *   @0x1d9968 add r8, pc, r8
 *   @0x1d996c ldr r10, [pc, #0x2e0]
 *   @0x1d9970 add r11, pc, r11
 *   @0x1d9974 ldr r9, [pc, #0x2dc]
 *   @0x1d9978 add r10, pc, r10
 *   @0x1d997c add r9, pc, r9
 *   @0x1d9980 vmov r1, s13
 *   @0x1d9984 bl 0x1d9864 <_Z13ConvertRawPosffiRfS_S_S_>
 *   @0x1d9988 vmov s15, r7
 *   @0x1d998c vldr s12, [sp, #424]
 *   @0x1d9990 vcvt.f32.s32 s12, s12
 *   @0x1d9994 ldr r2, [r4, #0x2c]
 *   @0x1d9998 add r3, sp, #340
 *   @0x1d999c str r3, [sp]
 *   @0x1d99a0 add r3, sp, #320
 *   @0x1d99a4 str r3, [sp, #0x4]
 *   @0x1d99a8 add r3, sp, #324
 *   @0x1d99ac str r3, [sp, #0x8]
 *   @0x1d99b0 add r3, sp, #336
 *   @0x1d99b4 rsb r7, r7, r6
 *   @0x1d99b8 vcvt.f32.s32 s15, s15
 *   @0x1d99bc vmov r1, s12
 *   @0x1d99c0 vmov r0, s15
 *   @0x1d99c4 bl 0x1d9864 <_Z13ConvertRawPosffiRfS_S_S_>
 *   @0x1d99c8 ldr r0, [r4, #0x40]
 *   @0x1d99cc ldr r1, [r4, #0x44]
 *   @0x1d99d0 add r12, sp, #348
 *   @0x1d99d4 ldr r2, [r4, #0x2c]
 *   @0x1d99d8 add r3, sp, #356
 *   @0x1d99dc vmov s13, r0
 *   @0x1d99e0 str r3, [sp]
 *   @0x1d99e4 vmov s15, r1
 *   @0x1d99e8 add r3, sp, #344
 *   @0x1d99ec vcvt.f32.s32 s13, s13
 *   @0x1d99f0 str r3, [sp, #0x4]
 *   @0x1d99f4 str r12, [sp, #0x8]
 *   @0x1d99f8 add r3, sp, #352
 *   @0x1d99fc vcvt.f32.s32 s15, s15
 *   @0x1d9a00 vmov r0, s13
 *   @0x1d9a04 vmov r1, s15
 *   @0x1d9a08 bl 0x1d9864 <_Z13ConvertRawPosffiRfS_S_S_>
 *   @0x1d9a0c vldr s16, [sp, #328]
 *   @0x1d9a10 vldr s18, [sp, #336]
 *   @0x1d9a14 vsub.f32 s18, s16, s18
 *   @0x1d9a18 vmov s15, r5
 *   @0x1d9a1c ldr r1, [sp, #0x1a8]
 *   @0x1d9a20 vmov s13, r6
 *   @0x1d9a24 ldr lr, [pc, #0x230]
 *   @0x1d9a28 rsb r1, r1, r5
 *   @0x1d9a2c ldr r3, [pc, #0x22c]
 *   @0x1d9a30 ldr r2, [pc, #0x22c]
 *   @0x1d9a34 vldr s20, [r4, #40]
 *   @0x1d9a38 vmov s0, r1
 *   @0x1d9a3c ldr r1, [pc, #0x224]
 *   @0x1d9a40 vldr s3, [sp, #312]
 *   @0x1d9a44 vldr s12, [sp, #332]
 *   @0x1d9a48 str r8, [sp, #0x4]
 *   @0x1d9a4c vldr s14, [sp, #340]
 *   @0x1d9a50 add lr, pc, lr
 *   @0x1d9a54 add r1, pc, r1
 *   @0x1d9a58 str lr, [sp, #0x14]
 *   @0x1d9a5c add r3, pc, r3
 *   @0x1d9a60 vcvt.f64.s32 d5, s15
 *   @0x1d9a64 str r1, [sp, #0x24]
 *   @0x1d9a68 str r3, [sp, #0x34]
 *   @0x1d9a6c add r2, pc, r2
 *   @0x1d9a70 str r2, [sp, #0x44]
 *   @0x1d9a74 mov r12, #0
 *   @0x1d9a78 ldr r2, [r4, #0x4]
 *   @0x1d9a7c vldr s5, [sp, #316]
 *   @0x1d9a80 ldr r8, [pc, #0x1e4]
 *   @0x1d9a84 vmov s8, r7
 *   @0x1d9a88 ldr lr, [pc, #0x1e0]
 *   @0x1d9a8c mov r0, #20
 *   @0x1d9a90 ldr r1, [pc, #0x1dc]
 *   @0x1d9a94 add r8, pc, r8
 *   @0x1d9a98 vcvt.f64.s32 d3, s13
 *   @0x1d9a9c vstr d5, [sp, #72]
 *   @0x1d9aa0 ldr r3, [pc, #0x1d0]
 *   @0x1d9aa4 add lr, pc, lr
 *   @0x1d9aa8 str r8, [sp, #0x54]
 *   @0x1d9aac add r1, pc, r1
 *   @0x1d9ab0 str lr, [sp, #0x64]
 *   @0x1d9ab4 add r3, pc, r3
 *   @0x1d9ab8 str r1, [sp, #0x74]
 *   @0x1d9abc str r3, [sp, #0x84]
 *   @0x1d9ac0 str r12, [sp]
 *   @0x1d9ac4 vcvt.f64.f32 d5, s3
 *   @0x1d9ac8 vstr d3, [sp, #56]
 *   @0x1d9acc str r12, [sp, #0x10]
 *   @0x1d9ad0 str r12, [sp, #0x20]
 *   @0x1d9ad4 str r12, [sp, #0x30]
 *   @0x1d9ad8 str r12, [sp, #0x40]
 *   @0x1d9adc str r12, [sp, #0x50]
 *   @0x1d9ae0 str r12, [sp, #0x60]
 *   @0x1d9ae4 vsub.f32 s14, s12, s14
 *   @0x1d9ae8 str r12, [sp, #0x70]
 *   @0x1d9aec str r12, [sp, #0x80]
 *   @0x1d9af0 ldr r7, [pc, #0x184]
 *   @0x1d9af4 ldr r3, [pc, #0x184]
 *   @0x1d9af8 add r7, pc, r7
 *   @0x1d9afc ldr r8, [pc, #0x180]
 *   @0x1d9b00 add r3, pc, r3
 *   @0x1d9b04 ldr lr, [pc, #0x17c]
 *   @0x1d9b08 ldr r1, [pc, #0x17c]
 *   @0x1d9b0c add r8, pc, r8
 *   @0x1d9b10 add lr, pc, lr
 *   @0x1d9b14 add r1, pc, r1
 *   @0x1d9b18 vcvt.f64.s32 d10, s20
 *   @0x1d9b1c vcvt.f64.f32 d9, s18
 *   @0x1d9b20 vstr d10, [sp, #8]
 *   @0x1d9b24 vcvt.f64.f32 d8, s16
 *   @0x1d9b28 vstr d9, [sp, #120]
 *   @0x1d9b2c vcvt.f64.f32 d6, s12
 *   @0x1d9b30 vstr d8, [sp, #24]
 *   @0x1d9b34 vstr d6, [sp, #40]
 *   @0x1d9b38 vstr d5, [sp, #88]
 *   @0x1d9b3c vldr s2, [sp, #320]
 *   @0x1d9b40 vldr s4, [sp, #324]
 *   @0x1d9b44 vsub.f32 s2, s3, s2
 *   @0x1d9b48 str r12, [sp, #0x90]
 *   @0x1d9b4c str r12, [sp, #0xa0]
 *   @0x1d9b50 vldr s10, [sp, #344]
 *   @0x1d9b54 str r12, [sp, #0xb0]
 *   @0x1d9b58 str r12, [sp, #0xc0]
 *   @0x1d9b5c str r12, [sp, #0xd0]
 *   @0x1d9b60 str r12, [sp, #0xe0]
 *   @0x1d9b64 str r12, [sp, #0xf0]
 *   @0x1d9b68 str r12, [sp, #0x100]
 *   @0x1d9b6c str r12, [sp, #0x110]
 *   @0x1d9b70 str r7, [sp, #0x94]
 *   @0x1d9b74 vsub.f32 s4, s5, s4
 *   @0x1d9b78 vcvt.f64.f32 d6, s5
 *   @0x1d9b7c vcvt.f64.f32 d7, s14
 *   @0x1d9b80 vstr d6, [sp, #104]
 *   @0x1d9b84 vldr s12, [sp, #348]
 *   @0x1d9b88 vcvt.f64.s32 d4, s8
 *   @0x1d9b8c vstr d7, [sp, #136]
 *   @0x1d9b90 vldr s14, [sp, #352]
 *   @0x1d9b94 vstr d4, [sp, #152]
 *   @0x1d9b98 vcvt.f64.s32 d0, s0
 *   @0x1d9b9c vldr s6, [r4, #64]
 *   @0x1d9ba0 vldr s8, [r4, #68]
 *   @0x1d9ba4 str r3, [sp, #0xa4]
 *   @0x1d9ba8 ldr r3, [pc, #0xe0]
 *   @0x1d9bac str lr, [sp, #0xf4]
 *   @0x1d9bb0 str r1, [sp, #0x104]
 *   @0x1d9bb4 add r3, pc, r3
 *   @0x1d9bb8 str r11, [sp, #0xb4]
 *   @0x1d9bbc vcvt.f64.f32 d1, s2
 *   @0x1d9bc0 str r3, [sp, #0x114]
 *   @0x1d9bc4 vstr d0, [sp, #168]
 *   @0x1d9bc8 str r10, [sp, #0xc4]
 *   @0x1d9bcc str r9, [sp, #0xd4]
 *   @0x1d9bd0 str r8, [sp, #0xe4]
 *   @0x1d9bd4 ldr lr, [pc, #0xb8]
 *   @0x1d9bd8 ldr r1, [pc, #0xb8]
 *   @0x1d9bdc add lr, pc, lr
 *   @0x1d9be0 vcvt.f64.f32 d2, s4
 *   @0x1d9be4 vstr d1, [sp, #184]
 *   @0x1d9be8 add r1, pc, r1
 *   @0x1d9bec vcvt.f64.s32 d3, s6
 *   @0x1d9bf0 vstr d2, [sp, #200]
 *   @0x1d9bf4 vcvt.f64.s32 d4, s8
 *   @0x1d9bf8 vstr d3, [sp, #216]
 *   @0x1d9bfc vcvt.f64.f32 d5, s10
 *   @0x1d9c00 vstr d4, [sp, #232]
 *   @0x1d9c04 vcvt.f64.f32 d6, s12
 *   @0x1d9c08 vstr d5, [sp, #248]
 *   @0x1d9c0c str r12, [sp, #0x120]
 *   @0x1d9c10 str r12, [sp, #0x130]
 *   @0x1d9c14 str lr, [sp, #0x124]
 *   @0x1d9c18 vcvt.f64.f32 d7, s14
 *   @0x1d9c1c vstr d6, [sp, #264]
 *   @0x1d9c20 vmov s13, r2
 *   @0x1d9c24 vstr d7, [sp, #280]
 *   @0x1d9c28 vcvt.f64.s32 d6, s13
 *   @0x1d9c2c vldr s14, [sp, #356]
 *   @0x1d9c30 vcvt.f64.f32 d7, s14
 *   @0x1d9c34 vmov r2, r3, d6
 *   @0x1d9c38 vstr d7, [sp, #296]
 *   @0x1d9c3c bl 0x20bdc0 <_Z11CreateDsMapiz>
 *   @0x1d9c40 add sp, sp, #364
 *   @0x1d9c44 vpop {d8, d9, d10}
 *   @0x1d9c48 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1d9c4c andseq r7, r7, r8, lsl r8
 *   @0x1d9c50 andseq r7, r7, r0, ror r8
 *   @0x1d9c54 andseq r7, r7, r4, ror r8
 *   @0x1d9c58 andseq r7, r7, r12, ror r8
 *   @0x1d9c5c andseq r7, r7, r8, lsr r7
 *   @0x1d9c60 andseq r7, r7, r12, lsr r7
 *   @0x1d9c64 andseq r7, r7, r4, lsr r7
 *   @0x1d9c68 andseq r7, r7, r12, lsr r7
 *   @0x1d9c6c andseq r7, r7, r4, lsl r7
 *   @0x1d9c70 andseq r7, r7, r12, lsl #14
 *   @0x1d9c74 andseq r7, r7, r12, lsl #14
 *   @0x1d9c78 andseq r7, r7, r12, lsl #14
 *   @0x1d9c7c ldrsbeq r7, [r7], -r0
 *   @0x1d9c80 ldrsbeq r7, [r7], -r4
 *   @0x1d9c84 ldrsheq r7, [r7], -r12
 *   @0x1d9c88 andseq r7, r7, r8, lsl #14
 *   @0x1d9c8c andseq r7, r7, r4, lsl r7
 *   @0x1d9c90 andseq r7, r7, r4, lsl #13
 *   @0x1d9c94 andseq r7, r7, r12, ror #12
 *   @0x1d9c98 mulseq r7, r0, r5
 *
 * ══ §10/36 b2PrismaticJoint::SolveVelocityConstraints(b2SolverData const&)  0x2cf384  size 912  228 条（0x2cf384..0x2cf714）
 * @func 0x2cf384 0x2cf714  size 912  228 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Mat33::Solve22(b2Vec2 const&) const×2 / b2Mat33::Solve33(b2Vec3 const&) const
 * 字段偏移 top8: 0x8c×3 / 0x90×2 / 0x94×2 / 0x1c×2 / 0x89×1 / 0x88×1
 * VFP 指令 174 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cf384 ldr r2, [r0, #0x90]
 *   @0x2cf388 ldr r3, [r0, #0x94]
 *   @0x2cf38c push {r4, r5, r6, r7, lr}
 *   @0x2cf390 vpush {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x2cf394 mov r4, r0
 *   @0x2cf398 vldr s23, [r0, #168]
 *   @0x2cf39c vldr s22, [r0, #172]
 *   @0x2cf3a0 ldrb r0, [r0, #0x89]
 *   @0x2cf3a4 mov r5, r1
 *   @0x2cf3a8 add r2, r2, r2, lsl #1
 *   @0x2cf3ac ldr r1, [r1, #0x1c]
 *   @0x2cf3b0 add r3, r3, r3, lsl #1
 *   @0x2cf3b4 cmp r0, #0
 *   @0x2cf3b8 sub sp, sp, #36
 *   @0x2cf3bc add r2, r1, r2, lsl #2
 *   @0x2cf3c0 add r3, r1, r3, lsl #2
 *   @0x2cf3c4 vldr s25, [r4, #176]
 *   @0x2cf3c8 vldr s24, [r4, #180]
 *   @0x2cf3cc vldr s21, [r2]
 *   @0x2cf3d0 vldr s19, [r2, #4]
 *   @0x2cf3d4 vldr s17, [r2, #8]
 *   @0x2cf3d8 vldr s20, [r3]
 *   @0x2cf3dc vldr s18, [r3, #4]
 *   @0x2cf3e0 vldr s16, [r3, #8]
 *   @0x2cf3e4 beq 0x2cf48c <_ZN16b2PrismaticJoint24SolveVelocityConstraintsERK12b2SolverData+0x108>
 *   @0x2cf3e8 ldr r3, [r4, #0x8c]
 *   @0x2cf3ec cmp r3, #3
 *   @0x2cf3f0 beq 0x2cf48c <_ZN16b2PrismaticJoint24SolveVelocityConstraintsERK12b2SolverData+0x108>
 *   @0x2cf3f4 vsub.f32 s15, s18, s19
 *   @0x2cf3f8 vldr s10, [r4, #188]
 *   @0x2cf3fc vldr s13, [r4, #184]
 *   @0x2cf400 vldr s12, [r4, #212]
 *   @0x2cf404 vldr s11, [r4, #208]
 *   @0x2cf408 vldr s6, [r4, #132]
 *   @0x2cf40c vldr s9, [r4, #116]
 *   @0x2cf410 vldr s8, [r4, #252]
 *   @0x2cf414 vldr s7, [r5]
 *   @0x2cf418 vldr s14, [r4, #128]
 *   @0x2cf41c vmul.f32 s15, s15, s10
 *   @0x2cf420 vsub.f32 s5, s20, s21
 *   @0x2cf424 vmla.f32 s15, s5, s13
 *   @0x2cf428 vmla.f32 s15, s12, s16
 *   @0x2cf42c vmls.f32 s15, s11, s17
 *   @0x2cf430 vsub.f32 s15, s6, s15
 *   @0x2cf434 vmov.f32 s6, s9
 *   @0x2cf438 vmla.f32 s6, s15, s8
 *   @0x2cf43c vmul.f32 s14, s7, s14
 *   @0x2cf440 vcmpe.f32 s14, s6
 *   @0x2cf444 vneg.f32 s15, s14
 *   @0x2cf448 vmrs APSR_nzcv, fpscr
 *   @0x2cf44c vmovgt.f32 s14, s6
 *   @0x2cf450 vcmpe.f32 s15, s14
 *   @0x2cf454 vmrs APSR_nzcv, fpscr
 *   @0x2cf458 vmovle.f32 s15, s14
 *   @0x2cf45c vstr s15, [r4, #116]
 *   @0x2cf460 vsub.f32 s15, s15, s9
 *   @0x2cf464 vmul.f32 s13, s15, s13
 *   @0x2cf468 vmul.f32 s14, s15, s10
 *   @0x2cf46c vmul.f32 s11, s11, s15
 *   @0x2cf470 vmul.f32 s15, s12, s15
 *   @0x2cf474 vmls.f32 s21, s23, s13
 *   @0x2cf478 vmla.f32 s20, s22, s13
 *   @0x2cf47c vmls.f32 s19, s23, s14
 *   @0x2cf480 vmla.f32 s18, s22, s14
 *   @0x2cf484 vmls.f32 s17, s25, s11
 *   @0x2cf488 vmla.f32 s16, s24, s15
 *   @0x2cf48c vldr s15, [r4, #196]
 *   @0x2cf490 vldr s10, [r4, #192]
 *   @0x2cf494 vldr s11, [r4, #204]
 *   @0x2cf498 ldrb r3, [r4, #0x88]
 *   @0x2cf49c vldr s12, [r4, #200]
 *   @0x2cf4a0 cmp r3, #0
 *   @0x2cf4a4 vsub.f32 s13, s18, s19
 *   @0x2cf4a8 vmul.f32 s15, s13, s15
 *   @0x2cf4ac vsub.f32 s14, s20, s21
 *   @0x2cf4b0 vmla.f32 s15, s14, s10
 *   @0x2cf4b4 vmla.f32 s15, s16, s11
 *   @0x2cf4b8 vsub.f32 s11, s16, s17
 *   @0x2cf4bc vmls.f32 s15, s17, s12
 *   @0x2cf4c0 beq 0x2cf4d0 <_ZN16b2PrismaticJoint24SolveVelocityConstraintsERK12b2SolverData+0x14c>
 *   @0x2cf4c4 ldr r3, [r4, #0x8c]
 *   @0x2cf4c8 cmp r3, #0
 *   @0x2cf4cc bne 0x2cf590 <_ZN16b2PrismaticJoint24SolveVelocityConstraintsERK12b2SolverData+0x20c>
 *   @0x2cf4d0 mov r0, sp
 *   @0x2cf4d4 add r1, r4, #216
 *   @0x2cf4d8 add r2, sp, #20
 *   @0x2cf4dc vneg.f32 s15, s15
 *   @0x2cf4e0 vneg.f32 s11, s11
 *   @0x2cf4e4 vstr s15, [sp, #20]
 *   @0x2cf4e8 vstr s11, [sp, #24]
 *   @0x2cf4ec bl 0x2c68e8 <_ZNK7b2Mat337Solve22ERK6b2Vec2>
 *   @0x2cf4f0 vldr s14, [sp, #4]
 *   @0x2cf4f4 vmov.f32 s7, s14
 *   @0x2cf4f8 vldr s15, [sp]
 *   @0x2cf4fc vldr s8, [r4, #200]
 *   @0x2cf500 vldr s9, [r4, #204]
 *   @0x2cf504 vldr s12, [r4, #192]
 *   @0x2cf508 vldr s13, [r4, #196]
 *   @0x2cf50c vldr s10, [r4, #108]
 *   @0x2cf510 vmov.f32 s6, s14
 *   @0x2cf514 vldr s11, [r4, #104]
 *   @0x2cf518 vmla.f32 s7, s15, s8
 *   @0x2cf51c vmla.f32 s6, s15, s9
 *   @0x2cf520 vmul.f32 s12, s15, s12
 *   @0x2cf524 vmul.f32 s13, s15, s13
 *   @0x2cf528 vmls.f32 s17, s25, s7
 *   @0x2cf52c vmla.f32 s16, s24, s6
 *   @0x2cf530 vmls.f32 s21, s23, s12
 *   @0x2cf534 vmla.f32 s20, s22, s12
 *   @0x2cf538 vmls.f32 s19, s23, s13
 *   @0x2cf53c vmla.f32 s18, s22, s13
 *   @0x2cf540 vadd.f32 s14, s10, s14
 *   @0x2cf544 vadd.f32 s15, s11, s15
 *   @0x2cf548 vstr s14, [r4, #108]
 *   @0x2cf54c vstr s15, [r4, #104]
 *   @0x2cf550 ldr r2, [r4, #0x90]
 *   @0x2cf554 ldr r3, [r4, #0x94]
 *   @0x2cf558 ldr r1, [r5, #0x1c]
 *   @0x2cf55c add r2, r2, r2, lsl #1
 *   @0x2cf560 add r3, r3, r3, lsl #1
 *   @0x2cf564 add r2, r1, r2, lsl #2
 *   @0x2cf568 vstr s21, [r2]
 *   @0x2cf56c vstr s19, [r2, #4]
 *   @0x2cf570 vstr s17, [r2, #8]
 *   @0x2cf574 add r3, r1, r3, lsl #2
 *   @0x2cf578 vstr s20, [r3]
 *   @0x2cf57c vstr s18, [r3, #4]
 *   @0x2cf580 vstr s16, [r3, #8]
 *   @0x2cf584 add sp, sp, #36
 *   @0x2cf588 vpop {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x2cf58c pop {r4, r5, r6, r7, pc}
 *   @0x2cf590 vldr s8, [r4, #188]
 *   @0x2cf594 vmul.f32 s13, s13, s8
 *   @0x2cf598 vldr s9, [r4, #184]
 *   @0x2cf59c vldr s10, [r4, #212]
 *   @0x2cf5a0 vldr s12, [r4, #208]
 *   @0x2cf5a4 add r6, r4, #216
 *   @0x2cf5a8 add r7, sp, #20
 *   @0x2cf5ac add r0, sp, #8
 *   @0x2cf5b0 mov r1, r6
 *   @0x2cf5b4 vldr s27, [r4, #104]
 *   @0x2cf5b8 mov r2, r7
 *   @0x2cf5bc vldr s26, [r4, #108]
 *   @0x2cf5c0 vldr s28, [r4, #112]
 *   @0x2cf5c4 vmla.f32 s13, s14, s9
 *   @0x2cf5c8 vmla.f32 s13, s16, s10
 *   @0x2cf5cc vmls.f32 s13, s17, s12
 *   @0x2cf5d0 vneg.f32 s29, s15
 *   @0x2cf5d4 vneg.f32 s30, s11
 *   @0x2cf5d8 vstr s29, [sp, #20]
 *   @0x2cf5dc vneg.f32 s13, s13
 *   @0x2cf5e0 vstr s30, [sp, #24]
 *   @0x2cf5e4 vstr s13, [sp, #28]
 *   @0x2cf5e8 bl 0x2c6808 <_ZNK7b2Mat337Solve33ERK6b2Vec3>
 *   @0x2cf5ec vldr s10, [r4, #104]
 *   @0x2cf5f0 vldr s11, [r4, #108]
 *   @0x2cf5f4 vldr s15, [r4, #112]
 *   @0x2cf5f8 vldr s12, [sp, #8]
 *   @0x2cf5fc vldr s14, [sp, #12]
 *   @0x2cf600 vldr s13, [sp, #16]
 *   @0x2cf604 vadd.f32 s12, s10, s12
 *   @0x2cf608 ldr r3, [r4, #0x8c]
 *   @0x2cf60c cmp r3, #1
 *   @0x2cf610 vadd.f32 s14, s11, s14
 *   @0x2cf614 vstr s12, [r4, #104]
 *   @0x2cf618 vadd.f32 s15, s13, s15
 *   @0x2cf61c vstr s14, [r4, #108]
 *   @0x2cf620 vstr s15, [r4, #112]
 *   @0x2cf624 beq 0x2cf6f8 <_ZN16b2PrismaticJoint24SolveVelocityConstraintsERK12b2SolverData+0x374>
 *   @0x2cf628 cmp r3, #2
 *   @0x2cf62c bne 0x2cf644 <_ZN16b2PrismaticJoint24SolveVelocityConstraintsERK12b2SolverData+0x2c0>
 *   @0x2cf630 vcmpe.f32 s15, #0
 *   @0x2cf634 vldr s14, [pc, #212]
 *   @0x2cf638 vmrs APSR_nzcv, fpscr
 *   @0x2cf63c vmovpl.f32 s15, s14
 *   @0x2cf640 vstr s15, [r4, #112]
 *   @0x2cf644 vldr s13, [r4, #244]
 *   @0x2cf648 vldr s14, [r4, #240]
 *   @0x2cf64c vsub.f32 s15, s15, s28
 *   @0x2cf650 mov r0, r7
 *   @0x2cf654 mov r1, r6
 *   @0x2cf658 mov r2, sp
 *   @0x2cf65c vmls.f32 s30, s15, s13
 *   @0x2cf660 vmls.f32 s29, s15, s14
 *   @0x2cf664 vstr s30, [sp, #4]
 *   @0x2cf668 vstr s29, [sp]
 *   @0x2cf66c bl 0x2c68e8 <_ZNK7b2Mat337Solve22ERK6b2Vec2>
 *   @0x2cf670 vldr s13, [sp, #24]
 *   @0x2cf674 vadd.f32 s13, s26, s13
 *   @0x2cf678 vldr s12, [sp, #20]
 *   @0x2cf67c vldr s15, [r4, #112]
 *   @0x2cf680 vldr s6, [r4, #200]
 *   @0x2cf684 vldr s7, [r4, #204]
 *   @0x2cf688 vldr s14, [r4, #184]
 *   @0x2cf68c vldr s8, [r4, #192]
 *   @0x2cf690 vldr s9, [r4, #196]
 *   @0x2cf694 vldr s10, [r4, #208]
 *   @0x2cf698 vldr s11, [r4, #212]
 *   @0x2cf69c vadd.f32 s12, s27, s12
 *   @0x2cf6a0 vstr s13, [r4, #108]
 *   @0x2cf6a4 vsub.f32 s26, s13, s26
 *   @0x2cf6a8 vstr s12, [r4, #104]
 *   @0x2cf6ac vsub.f32 s27, s12, s27
 *   @0x2cf6b0 vmov.f32 s13, s26
 *   @0x2cf6b4 vsub.f32 s28, s15, s28
 *   @0x2cf6b8 vldr s15, [r4, #188]
 *   @0x2cf6bc vmla.f32 s13, s27, s6
 *   @0x2cf6c0 vmla.f32 s26, s27, s7
 *   @0x2cf6c4 vmul.f32 s14, s28, s14
 *   @0x2cf6c8 vmul.f32 s15, s28, s15
 *   @0x2cf6cc vmla.f32 s14, s27, s8
 *   @0x2cf6d0 vmla.f32 s15, s27, s9
 *   @0x2cf6d4 vmla.f32 s13, s28, s10
 *   @0x2cf6d8 vmla.f32 s26, s28, s11
 *   @0x2cf6dc vmls.f32 s21, s23, s14
 *   @0x2cf6e0 vmla.f32 s20, s22, s14
 *   @0x2cf6e4 vmls.f32 s19, s23, s15
 *   @0x2cf6e8 vmla.f32 s18, s22, s15
 *   @0x2cf6ec vmls.f32 s17, s25, s13
 *   @0x2cf6f0 vmla.f32 s16, s24, s26
 *   @0x2cf6f4 b 0x2cf550 <_ZN16b2PrismaticJoint24SolveVelocityConstraintsERK12b2SolverData+0x1cc>
 *   @0x2cf6f8 vcmpe.f32 s15, #0
 *   @0x2cf6fc vldr s14, [pc, #12]
 *   @0x2cf700 vmrs APSR_nzcv, fpscr
 *   @0x2cf704 vmovle.f32 s15, s14
 *   @0x2cf708 vstr s15, [r4, #112]
 *   @0x2cf70c b 0x2cf644 <_ZN16b2PrismaticJoint24SolveVelocityConstraintsERK12b2SolverData+0x2c0>
 *   @0x2cf710 andeq r0, r0, r0
 *
 * ══ §11/36 b2PulleyJoint::InitVelocityConstraints(b2SolverData const&)  0x2d0b78  size 912  228 条（0x2d0b78..0x2d0f08）
 * @func 0x2d0b78 0x2d0f08  size 912  228 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6580×2 / 0xb658c×2 / 0xb6700×2 / b2PulleyJoint::InitVelocityConstraints(b2SolverData const&)+0x358 / b2PulleyJoint::InitVelocityConstraints(b2SolverData const&)+0x340
 * 字段偏移 top8: 0x8×4 / 0x90×2 / 0x78×2 / 0x1c×2 / 0x7c×2 / 0x30×1 / 0x34×1 / 0x18×1
 * VFP 指令 157 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d0b78 ldr r2, [r0, #0x30]
 *   @0x2d0b7c vldr s15, [r2, #136]
 *   @0x2d0b80 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2d0b84 vpush {d8, d9, d10, d11, d12, d13, d14}
 *   @0x2d0b88 mov r5, r1
 *   @0x2d0b8c ldr r3, [r0, #0x34]
 *   @0x2d0b90 add r1, r2, #44
 *   @0x2d0b94 ldr lr, [r2, #0x8]
 *   @0x2d0b98 mov r4, r0
 *   @0x2d0b9c ldr r7, [r5, #0x18]
 *   @0x2d0ba0 add r10, r0, #160
 *   @0x2d0ba4 ldr r12, [r3, #0x8]
 *   @0x2d0ba8 add r6, r0, #168
 *   @0x2d0bac ldr r11, [r2, #0x90]
 *   @0x2d0bb0 add r9, r3, #44
 *   @0x2d0bb4 ldm r1, {r0, r1}
 *   @0x2d0bb8 str lr, [r4, #0x78]
 *   @0x2d0bbc add lr, lr, lr, lsl #1
 *   @0x2d0bc0 ldr r8, [r5, #0x1c]
 *   @0x2d0bc4 lsl lr, lr, #2
 *   @0x2d0bc8 str r12, [r4, #0x7c]
 *   @0x2d0bcc add r12, r12, r12, lsl #1
 *   @0x2d0bd0 add r2, r7, lr
 *   @0x2d0bd4 stm r10, {r0, r1}
 *   @0x2d0bd8 add lr, r8, lr
 *   @0x2d0bdc lsl r12, r12, #2
 *   @0x2d0be0 ldm r9, {r0, r1}
 *   @0x2d0be4 ldr r10, [r3, #0x88]
 *   @0x2d0be8 vldr s27, [r2]
 *   @0x2d0bec ldr r9, [r3, #0x90]
 *   @0x2d0bf0 add r3, r7, r12
 *   @0x2d0bf4 ldr r7, [r2, #0x8]
 *   @0x2d0bf8 add r12, r8, r12
 *   @0x2d0bfc stm r6, {r0, r1}
 *   @0x2d0c00 vstr s15, [r4, #176]
 *   @0x2d0c04 str r11, [r4, #0xb8]
 *   @0x2d0c08 vldr s25, [r3]
 *   @0x2d0c0c str r10, [r4, #0xb4]
 *   @0x2d0c10 mov r0, r7
 *   @0x2d0c14 str r9, [r4, #0xbc]
 *   @0x2d0c18 vldr s28, [r2, #4]
 *   @0x2d0c1c ldr r6, [r3, #0x8]
 *   @0x2d0c20 vldr s24, [r3, #4]
 *   @0x2d0c24 vldr s22, [lr]
 *   @0x2d0c28 vldr s21, [lr, #4]
 *   @0x2d0c2c vldr s20, [lr, #8]
 *   @0x2d0c30 vldr s19, [r12]
 *   @0x2d0c34 vldr s18, [r12, #4]
 *   @0x2d0c38 vldr s17, [r12, #8]
 *   @0x2d0c3c bl 0xb6580 <sinf@plt>
 *   @0x2d0c40 vmov s26, r0
 *   @0x2d0c44 mov r0, r7
 *   @0x2d0c48 bl 0xb658c <cosf@plt>
 *   @0x2d0c4c vmov s16, r0
 *   @0x2d0c50 mov r0, r6
 *   @0x2d0c54 bl 0xb6580 <sinf@plt>
 *   @0x2d0c58 vmov s23, r0
 *   @0x2d0c5c mov r0, r6
 *   @0x2d0c60 bl 0xb658c <cosf@plt>
 *   @0x2d0c64 vldr s15, [r4, #164]
 *   @0x2d0c68 vldr s13, [r4, #96]
 *   @0x2d0c6c vsub.f32 s13, s13, s15
 *   @0x2d0c70 vldr s14, [r4, #92]
 *   @0x2d0c74 vldr s15, [r4, #160]
 *   @0x2d0c78 vmul.f32 s12, s13, s16
 *   @0x2d0c7c vsub.f32 s15, s14, s15
 *   @0x2d0c80 vmov s11, r0
 *   @0x2d0c84 vmul.f32 s13, s13, s26
 *   @0x2d0c88 vmla.f32 s12, s15, s26
 *   @0x2d0c8c vnmls.f32 s13, s15, s16
 *   @0x2d0c90 vadd.f32 s28, s28, s12
 *   @0x2d0c94 vstr s13, [r4, #144]
 *   @0x2d0c98 vldr s5, [r4, #72]
 *   @0x2d0c9c vstr s12, [r4, #148]
 *   @0x2d0ca0 vldr s6, [r4, #68]
 *   @0x2d0ca4 vldr s14, [r4, #104]
 *   @0x2d0ca8 vldr s15, [r4, #172]
 *   @0x2d0cac vldr s7, [r4, #100]
 *   @0x2d0cb0 vldr s8, [r4, #168]
 *   @0x2d0cb4 vldr s9, [r4, #76]
 *   @0x2d0cb8 vldr s10, [r4, #80]
 *   @0x2d0cbc vsub.f32 s12, s28, s5
 *   @0x2d0cc0 vadd.f32 s13, s27, s13
 *   @0x2d0cc4 vstr s12, [r4, #132]
 *   @0x2d0cc8 vmul.f32 s12, s12, s12
 *   @0x2d0ccc vsub.f32 s13, s13, s6
 *   @0x2d0cd0 vsub.f32 s15, s14, s15
 *   @0x2d0cd4 vstr s13, [r4, #128]
 *   @0x2d0cd8 vmla.f32 s12, s13, s13
 *   @0x2d0cdc vmul.f32 s14, s15, s23
 *   @0x2d0ce0 vmul.f32 s15, s15, s11
 *   @0x2d0ce4 vsub.f32 s13, s7, s8
 *   @0x2d0ce8 vsqrt.f32 s16, s12
 *   @0x2d0cec vnmls.f32 s14, s13, s11
 *   @0x2d0cf0 vmla.f32 s15, s13, s23
 *   @0x2d0cf4 vstr s14, [r4, #152]
 *   @0x2d0cf8 vstr s15, [r4, #156]
 *   @0x2d0cfc vadd.f32 s14, s14, s25
 *   @0x2d0d00 vadd.f32 s15, s15, s24
 *   @0x2d0d04 vsub.f32 s14, s14, s9
 *   @0x2d0d08 vsub.f32 s15, s15, s10
 *   @0x2d0d0c vstr s14, [r4, #136]
 *   @0x2d0d10 vcmp.f32 s16, s16
 *   @0x2d0d14 vstr s15, [r4, #140]
 *   @0x2d0d18 vmrs APSR_nzcv, fpscr
 *   @0x2d0d1c bne 0x2d0ef0 <_ZN13b2PulleyJoint23InitVelocityConstraintsERK12b2SolverData+0x378>
 *   @0x2d0d20 vldr s14, [r4, #140]
 *   @0x2d0d24 vmul.f32 s14, s14, s14
 *   @0x2d0d28 vldr s15, [r4, #136]
 *   @0x2d0d2c vmla.f32 s14, s15, s15
 *   @0x2d0d30 vsqrt.f32 s15, s14
 *   @0x2d0d34 vcmp.f32 s15, s15
 *   @0x2d0d38 vmrs APSR_nzcv, fpscr
 *   @0x2d0d3c bne 0x2d0ee0 <_ZN13b2PulleyJoint23InitVelocityConstraintsERK12b2SolverData+0x368>
 *   @0x2d0d40 vldr s14, [pc, #440]
 *   @0x2d0d44 vcmpe.f32 s16, s14
 *   @0x2d0d48 vmrs APSR_nzcv, fpscr
 *   @0x2d0d4c ble 0x2d0ed0 <_ZN13b2PulleyJoint23InitVelocityConstraintsERK12b2SolverData+0x358>
 *   @0x2d0d50 vmov.f32 s12, #1.000000e+00
 *   @0x2d0d54 vldr s14, [r4, #128]
 *   @0x2d0d58 vldr s13, [r4, #132]
 *   @0x2d0d5c vdiv.f32 s16, s12, s16
 *   @0x2d0d60 vmul.f32 s14, s14, s16
 *   @0x2d0d64 vmul.f32 s16, s13, s16
 *   @0x2d0d68 vstr s14, [r4, #128]
 *   @0x2d0d6c vstr s16, [r4, #132]
 *   @0x2d0d70 vldr s14, [pc, #392]
 *   @0x2d0d74 vcmpe.f32 s15, s14
 *   @0x2d0d78 vmrs APSR_nzcv, fpscr
 *   @0x2d0d7c ble 0x2d0eb8 <_ZN13b2PulleyJoint23InitVelocityConstraintsERK12b2SolverData+0x340>
 *   @0x2d0d80 vmov.f32 s14, #1.000000e+00
 *   @0x2d0d84 vldr s12, [r4, #136]
 *   @0x2d0d88 vldr s3, [r4, #140]
 *   @0x2d0d8c vdiv.f32 s15, s14, s15
 *   @0x2d0d90 vmul.f32 s12, s15, s12
 *   @0x2d0d94 vmul.f32 s3, s15, s3
 *   @0x2d0d98 vstr s12, [r4, #136]
 *   @0x2d0d9c vstr s3, [r4, #140]
 *   @0x2d0da0 vldr s4, [r4, #148]
 *   @0x2d0da4 vldr s1, [r4, #128]
 *   @0x2d0da8 vmul.f32 s15, s4, s1
 *   @0x2d0dac vldr s2, [r4, #156]
 *   @0x2d0db0 vldr s7, [r4, #144]
 *   @0x2d0db4 vldr s5, [r4, #132]
 *   @0x2d0db8 vldr s6, [r4, #152]
 *   @0x2d0dbc vldr s9, [r4, #184]
 *   @0x2d0dc0 vldr s8, [r4, #188]
 *   @0x2d0dc4 vldr s11, [r4, #176]
 *   @0x2d0dc8 vldr s10, [r4, #180]
 *   @0x2d0dcc vldr s13, [r4, #112]
 *   @0x2d0dd0 ldrb r3, [r5, #0x14]
 *   @0x2d0dd4 vmul.f32 s14, s2, s12
 *   @0x2d0dd8 vnmls.f32 s15, s7, s5
 *   @0x2d0ddc vnmls.f32 s14, s6, s3
 *   @0x2d0de0 vmul.f32 s16, s9, s15
 *   @0x2d0de4 vmul.f32 s0, s8, s14
 *   @0x2d0de8 vmov.f32 s23, s11
 *   @0x2d0dec vmla.f32 s23, s16, s15
 *   @0x2d0df0 vmov.f32 s16, s10
 *   @0x2d0df4 vmla.f32 s16, s0, s14
 *   @0x2d0df8 vmul.f32 s0, s13, s13
 *   @0x2d0dfc vmov.f32 s15, s23
 *   @0x2d0e00 vmla.f32 s15, s0, s16
 *   @0x2d0e04 vcmpe.f32 s15, #0
 *   @0x2d0e08 vmov.f32 s14, s16
 *   @0x2d0e0c vmrs APSR_nzcv, fpscr
 *   @0x2d0e10 vmovgt.f32 s14, #1.000000e+00
 *   @0x2d0e14 vdivgt.f32 s15, s14, s15
 *   @0x2d0e18 cmp r3, #0
 *   @0x2d0e1c moveq r3, #0
 *   @0x2d0e20 streq r3, [r4, #0x74]
 *   @0x2d0e24 vstr s15, [r4, #192]
 *   @0x2d0e28 beq 0x2d0e7c <_ZN13b2PulleyJoint23InitVelocityConstraintsERK12b2SolverData+0x304>
 *   @0x2d0e2c vldr s14, [r4, #116]
 *   @0x2d0e30 vldr s15, [r5, #8]
 *   @0x2d0e34 vmul.f32 s15, s14, s15
 *   @0x2d0e38 vnmul.f32 s13, s13, s15
 *   @0x2d0e3c vstr s15, [r4, #116]
 *   @0x2d0e40 vneg.f32 s15, s15
 *   @0x2d0e44 vmul.f32 s12, s13, s12
 *   @0x2d0e48 vmul.f32 s1, s15, s1
 *   @0x2d0e4c vmul.f32 s3, s13, s3
 *   @0x2d0e50 vmul.f32 s5, s15, s5
 *   @0x2d0e54 vmul.f32 s2, s2, s12
 *   @0x2d0e58 vmul.f32 s4, s4, s1
 *   @0x2d0e5c vnmls.f32 s2, s6, s3
 *   @0x2d0e60 vnmls.f32 s4, s7, s5
 *   @0x2d0e64 vmla.f32 s17, s8, s2
 *   @0x2d0e68 vmla.f32 s19, s10, s12
 *   @0x2d0e6c vmla.f32 s18, s10, s3
 *   @0x2d0e70 vmla.f32 s20, s9, s4
 *   @0x2d0e74 vmla.f32 s22, s11, s1
 *   @0x2d0e78 vmla.f32 s21, s11, s5
 *   @0x2d0e7c ldr r2, [r4, #0x78]
 *   @0x2d0e80 ldr r3, [r4, #0x7c]
 *   @0x2d0e84 ldr r1, [r5, #0x1c]
 *   @0x2d0e88 add r2, r2, r2, lsl #1
 *   @0x2d0e8c add r3, r3, r3, lsl #1
 *   @0x2d0e90 add r2, r1, r2, lsl #2
 *   @0x2d0e94 vstr s22, [r2]
 *   @0x2d0e98 vstr s21, [r2, #4]
 *   @0x2d0e9c vstr s20, [r2, #8]
 *   @0x2d0ea0 add r3, r1, r3, lsl #2
 *   @0x2d0ea4 vstr s19, [r3]
 *   @0x2d0ea8 vstr s18, [r3, #4]
 *   @0x2d0eac vstr s17, [r3, #8]
 *   @0x2d0eb0 vpop {d8, d9, d10, d11, d12, d13, d14}
 *   @0x2d0eb4 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2d0eb8 vldr s15, [pc, #68]
 *   @0x2d0ebc vmov.f32 s12, s15
 *   @0x2d0ec0 vstr s15, [r4, #136]
 *   @0x2d0ec4 vstr s15, [r4, #140]
 *   @0x2d0ec8 vmov.f32 s3, s15
 *   @0x2d0ecc b 0x2d0da0 <_ZN13b2PulleyJoint23InitVelocityConstraintsERK12b2SolverData+0x228>
 *   @0x2d0ed0 mov r3, #0
 *   @0x2d0ed4 str r3, [r4, #0x80]
 *   @0x2d0ed8 str r3, [r4, #0x84]
 *   @0x2d0edc b 0x2d0d70 <_ZN13b2PulleyJoint23InitVelocityConstraintsERK12b2SolverData+0x1f8>
 *   @0x2d0ee0 vmov r0, s14
 *   @0x2d0ee4 bl 0xb6700 <sqrtf@plt>
 *   @0x2d0ee8 vmov s15, r0
 *   @0x2d0eec b 0x2d0d40 <_ZN13b2PulleyJoint23InitVelocityConstraintsERK12b2SolverData+0x1c8>
 *   @0x2d0ef0 vmov r0, s12
 *   @0x2d0ef4 bl 0xb6700 <sqrtf@plt>
 *   @0x2d0ef8 vmov s16, r0
 *   @0x2d0efc b 0x2d0d20 <_ZN13b2PulleyJoint23InitVelocityConstraintsERK12b2SolverData+0x1a8>
 *   @0x2d0f00 stcllo p12, c12, [r12, #-816]
 *   @0x2d0f04 andeq r0, r0, r0
 *
 * ══ §12/36 GR_Window_Views_Convert(int, int, int&, int&)  0x17a6a0  size 908  220 条（0x17a6a0..0x17aa2c）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x17a6a0 0x17aa2c  size 908  220 条
 * 部分覆盖: 本节 220/227 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x17a6d0→0x54298c, 0x17a6e8→0x498cd8, 0x17a7d4→0x5428e8, 0x17a848→0x3f50a8, 0x17a850→0x3f50a4, 0x17a8e8→0x3f50a8, 0x17a8f4→0x3f510c, 0x17a910→0x3f50d8
 * 调用序列: GR_Window_Views_Convert(int, int, int&, int&)+0xd4×4 / Get_FullScreenOffset(int&, int&, int&, int&)×2 / GR_Window_View_Convert(int, int, int, int&, int&)
 * 字段偏移 top8: 0x8×4 / 0x3c×2 / 0x18×2 / 0x1c×2 / 0x334×1 / 0x330×1 / 0x31c×1 / 0x5d0×1
 * VFP 指令 79 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17a6a0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x17a6a4 sub sp, sp, #60
 *   @0x17a6a8 mov r9, r1
 *   @0x17a6ac mov r7, r2
 *   @0x17a6b0 str r0, [sp, #0x8]
 *   @0x17a6b4 add r1, sp, #28
 *   @0x17a6b8 mov r8, r3
 *   @0x17a6bc add r0, sp, #24
 *   @0x17a6c0 add r3, sp, #36
 *   @0x17a6c4 add r2, sp, #32
 *   @0x17a6c8 ldr r10, [pc, #0x334]
 *   @0x17a6cc bl 0x179a00 <_Z20Get_FullScreenOffsetRiS_S_S_>
 *   @0x17a6d0 ldr r3, [pc, #0x330]
 *   @0x17a6d4 add r10, pc, r10
 *   @0x17a6d8 ldr r6, [r10, r3]
 *   @0x17a6dc ldr r1, [r6]
 *   @0x17a6e0 cmp r1, #0
 *   @0x17a6e4 beq 0x17a9e0 <_Z23GR_Window_Views_ConvertiiRiS_+0x340>
 *   @0x17a6e8 ldr r3, [pc, #0x31c]
 *   @0x17a6ec mov r4, r1
 *   @0x17a6f0 mov r2, #0
 *   @0x17a6f4 mov r0, #31
 *   @0x17a6f8 ldr r11, [r10, r3]
 *   @0x17a6fc mov r12, r11
 *   @0x17a700 ldrb r3, [r12, #0x5d0]
 *   @0x17a704 cmp r3, #0
 *   @0x17a708 beq 0x17a730 <_Z23GR_Window_Views_ConvertiiRiS_+0x90>
 *   @0x17a70c cmp r0, #7
 *   @0x17a710 ldrls r3, [r4, #0xc4]
 *   @0x17a714 movhi r3, #0
 *   @0x17a718 ldrb r5, [r3]
 *   @0x17a71c cmp r5, #0
 *   @0x17a720 beq 0x17a730 <_Z23GR_Window_Views_ConvertiiRiS_+0x90>
 *   @0x17a724 ldr r3, [r3, #0x3c]
 *   @0x17a728 cmn r3, #1
 *   @0x17a72c addeq r2, r2, #1
 *   @0x17a730 sub r0, r0, #1
 *   @0x17a734 sub r12, r12, #48
 *   @0x17a738 cmn r0, #1
 *   @0x17a73c sub r4, r4, #4
 *   @0x17a740 bne 0x17a700 <_Z23GR_Window_Views_ConvertiiRiS_+0x60>
 *   @0x17a744 cmp r2, #0
 *   @0x17a748 beq 0x17a848 <_Z23GR_Window_Views_ConvertiiRiS_+0x1a8>
 *   @0x17a74c add r1, sp, #44
 *   @0x17a750 add r3, sp, #48
 *   @0x17a754 str r1, [sp, #0xc]
 *   @0x17a758 add r11, r11, #1520
 *   @0x17a75c add r1, sp, #52
 *   @0x17a760 add r5, sp, #40
 *   @0x17a764 str r3, [sp, #0x10]
 *   @0x17a768 mov r4, #31
 *   @0x17a76c str r1, [sp, #0x14]
 *   @0x17a770 b 0x17a784 <_Z23GR_Window_Views_ConvertiiRiS_+0xe4>
 *   @0x17a774 sub r4, r4, #1
 *   @0x17a778 sub r11, r11, #48
 *   @0x17a77c cmn r4, #1
 *   @0x17a780 beq 0x17a840 <_Z23GR_Window_Views_ConvertiiRiS_+0x1a0>
 *   @0x17a784 ldrb r1, [r11, #-0x20]
 *   @0x17a788 cmp r1, #0
 *   @0x17a78c beq 0x17a774 <_Z23GR_Window_Views_ConvertiiRiS_+0xd4>
 *   @0x17a790 cmp r4, #7
 *   @0x17a794 ldr r3, [r6]
 *   @0x17a798 addls r2, r4, #18
 *   @0x17a79c movhi r3, #0
 *   @0x17a7a0 ldrls r3, [r3, r2, lsl #2]
 *   @0x17a7a4 ldrb r2, [r3]
 *   @0x17a7a8 cmp r2, #0
 *   @0x17a7ac beq 0x17a774 <_Z23GR_Window_Views_ConvertiiRiS_+0xd4>
 *   @0x17a7b0 ldr r3, [r3, #0x3c]
 *   @0x17a7b4 cmn r3, #1
 *   @0x17a7b8 bne 0x17a774 <_Z23GR_Window_Views_ConvertiiRiS_+0xd4>
 *   @0x17a7bc mov r3, r7
 *   @0x17a7c0 str r8, [sp]
 *   @0x17a7c4 mov r0, r4
 *   @0x17a7c8 ldr r1, [sp, #0x8]
 *   @0x17a7e8 vldr s10, [r7]
 *   @0x17a7ec vcvt.f32.s32 s15, s10
 *   @0x17a7f0 vldr s14, [r11, #-28]
 *   @0x17a7f4 vcmpe.f32 s15, s14
 *   @0x17a7f8 vmrs APSR_nzcv, fpscr
 *   @0x17a7fc blt 0x17a774 <_Z23GR_Window_Views_ConvertiiRiS_+0xd4>
 *   @0x17a800 vldr s13, [r11, #-20]
 *   @0x17a804 vadd.f32 s14, s14, s13
 *   @0x17a808 vcmpe.f32 s15, s14
 *   @0x17a80c vmrs APSR_nzcv, fpscr
 *   @0x17a810 bpl 0x17a774 <_Z23GR_Window_Views_ConvertiiRiS_+0xd4>
 *   @0x17a814 vldr s11, [r8]
 *   @0x17a818 vcvt.f32.s32 s15, s11
 *   @0x17a81c vldr s14, [r11, #-24]
 *   @0x17a820 vcmpe.f32 s15, s14
 *   @0x17a824 vmrs APSR_nzcv, fpscr
 *   @0x17a828 blt 0x17a774 <_Z23GR_Window_Views_ConvertiiRiS_+0xd4>
 *   @0x17a82c vldr s13, [r11, #-16]
 *   @0x17a830 vadd.f32 s14, s14, s13
 *   @0x17a834 vcmpe.f32 s15, s14
 *   @0x17a838 vmrs APSR_nzcv, fpscr
 *   @0x17a83c bpl 0x17a774 <_Z23GR_Window_Views_ConvertiiRiS_+0xd4>
 *   @0x17a840 add sp, sp, #60
 *   @0x17a844 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x17a848 ldr r0, [pc, #0x1c4]
 *   @0x17a84c vldr s14, [r1, #16]
 *   @0x17a850 ldr r3, [pc, #0x1c0]
 *   @0x17a854 vldr s15, [r1, #20]
 *   @0x17a858 ldr r2, [sp, #0x18]
 *   @0x17a85c vcvt.f32.s32 s14, s14
 *   @0x17a860 ldr r12, [r10, r0]
 *   @0x17a864 ldr r0, [r10, r3]
 *   @0x17a868 ldr r3, [sp, #0x8]
 *   @0x17a86c ldr r12, [r12]
 *   @0x17a870 rsb r3, r2, r3
 *   @0x17a874 ldr r0, [r0]
 *   @0x17a878 vmov s12, r3
 *   @0x17a87c ldr r3, [sp, #0x1c]
 *   @0x17a880 sub r2, r12, r2, lsl #1
 *   @0x17a884 vcvt.f32.s32 s15, s15
 *   @0x17a888 rsb r9, r3, r9
 *   @0x17a88c vmov s10, r2
 *   @0x17a890 sub r3, r0, r3, lsl #1
 *   @0x17a894 vcvt.f32.s32 s11, s10
 *   @0x17a898 vmov s10, r3
 *   @0x17a89c vcvt.f32.s32 s13, s10
 *   @0x17a8a0 vdiv.f32 s14, s14, s11
 *   @0x17a8a4 vdiv.f32 s15, s15, s13
 *   @0x17a8a8 vmov s10, r9
 *   @0x17a8ac vcvt.f32.s32 s12, s12
 *   @0x17a8b0 vcvt.f32.s32 s13, s10
 *   @0x17a8b4 vmul.f32 s14, s12, s14
 *   @0x17a8b8 vmul.f32 s15, s13, s15
 *   @0x17a8bc vcvt.s32.f32 s14, s14
 *   @0x17a8c0 vcvt.s32.f32 s15, s15
 *   @0x17a8c4 vstr s14, [r7]
 *   @0x17a8c8 vstr s15, [r8]
 *   @0x17a8cc add sp, sp, #60
 *   @0x17a8d0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x17a8d4 mov r0, r5
 *   @0x17a8d8 add r1, sp, #44
 *   @0x17a8dc add r2, sp, #48
 *   @0x17a8e0 add r3, sp, #52
 *   @0x17a8e4 bl 0x179a00 <_Z20Get_FullScreenOffsetRiS_S_S_>
 *   @0x17a8e8 ldr r2, [pc, #0x124]
 *   @0x17a8ec ldr r3, [sp, #0x28]
 *   @0x17a8f0 vldr s10, [sp, #8]
 *   @0x17a8f4 ldr r1, [pc, #0x120]
 *   @0x17a8f8 vldr s14, [r11, #-12]
 *   @0x17a8fc ldr r2, [r10, r2]
 *   @0x17a900 ldr r0, [r10, r1]
 *   @0x17a904 vldr s12, [r0]
 *   @0x17a908 ldr r2, [r2]
 *   @0x17a90c vcvt.f32.s32 s12, s12
 *   @0x17a910 ldr r1, [pc, #0x108]
 *   @0x17a914 sub r2, r2, r3, lsl #1
 *   @0x17a918 ldr r3, [pc, #0xf8]
 *   @0x17a91c ldr r1, [r10, r1]
 *   @0x17a920 vldr s15, [r1]
 *   @0x17a924 vmov s13, r2
 *   @0x17a928 ldr r2, [pc, #0xf4]
 *   @0x17a92c ldr r3, [r10, r3]
 *   @0x17a930 vcvt.f32.s32 s13, s13
 *   @0x17a934 ldr r1, [pc, #0xec]
 *   @0x17a938 ldr r2, [r10, r2]
 *   @0x17a93c ldr r1, [r10, r1]
 *   @0x17a940 vldr s11, [r1]
 *   @0x17a944 ldr r2, [r2]
 *   @0x17a948 ldr r1, [r3]
 *   @0x17a94c ldr r3, [sp, #0x2c]
 *   @0x17a950 vdiv.f32 s13, s12, s13
 *   @0x17a954 vdiv.f32 s15, s13, s15
 *   @0x17a958 vcvt.f32.s32 s13, s10
 *   @0x17a95c vmul.f32 s15, s13, s15
 *   @0x17a960 vcvt.s32.f32 s15, s15
 *   @0x17a964 vcvt.f32.s32 s15, s15
 *   @0x17a968 vcmpe.f32 s15, s14
 *   @0x17a96c vmrs APSR_nzcv, fpscr
 *   @0x17a970 blt 0x17a774 <_Z23GR_Window_Views_ConvertiiRiS_+0xd4>
 *   @0x17a974 vldr s13, [r11, #-4]
 *   @0x17a978 vadd.f32 s14, s14, s13
 *   @0x17a97c vcmpe.f32 s15, s14
 *   @0x17a980 vmrs APSR_nzcv, fpscr
 *   @0x17a984 bpl 0x17a774 <_Z23GR_Window_Views_ConvertiiRiS_+0xd4>
 *   @0x17a988 sub r1, r1, r3, lsl #1
 *   @0x17a98c vmov s12, r2
 *   @0x17a990 vldr s14, [r11, #-8]
 *   @0x17a994 vmov s15, r1
 *   @0x17a998 vcvt.f32.s32 s13, s12
 *   @0x17a99c vcvt.f32.s32 s15, s15
 *   @0x17a9a0 vdiv.f32 s15, s13, s15
 *   @0x17a9a4 vmov s13, r9
 *   @0x17a9a8 vdiv.f32 s11, s15, s11
 *   @0x17a9ac vcvt.f32.s32 s15, s13
 *   @0x17a9b0 vmul.f32 s15, s15, s11
 *   @0x17a9b4 vcvt.s32.f32 s15, s15
 *   @0x17a9b8 vcvt.f32.s32 s15, s15
 *   @0x17a9bc vcmpe.f32 s15, s14
 *   @0x17a9c0 vmrs APSR_nzcv, fpscr
 *   @0x17a9c4 blt 0x17a774 <_Z23GR_Window_Views_ConvertiiRiS_+0xd4>
 *   @0x17a9c8 vldr s13, [r11]
 *   @0x17a9cc vadd.f32 s14, s14, s13
 *   @0x17a9d0 vcmpe.f32 s15, s14
 *   @0x17a9d4 vmrs APSR_nzcv, fpscr
 *   @0x17a9d8 bpl 0x17a774 <_Z23GR_Window_Views_ConvertiiRiS_+0xd4>
 *   @0x17a9dc b 0x17a840 <_Z23GR_Window_Views_ConvertiiRiS_+0x1a0>
 *   @0x17a9e0 vmov.f32 s15, #1.000000e+00
 *   @0x17a9e4 ldr r2, [sp, #0x18]
 *   @0x17a9e8 ldr r1, [sp, #0x8]
 *   @0x17a9ec ldr r3, [sp, #0x1c]
 *   @0x17a9f0 rsb r1, r2, r1
 *   @0x17a9f4 rsb r9, r3, r9
 *   @0x17a9f8 vmov s12, r1
 *   @0x17a9fc vmov.f32 s14, s15
 *   @0x17aa00 b 0x17a8a8 <_Z23GR_Window_Views_ConvertiiRiS_+0x208>
 *   @0x17aa04 eoreq r7, r7, r12, ror r5
 *   @0x17aa08 .word 0xffffbcd8
 *   @0x17aa0c .word 0xffffe6b0
 *   @0x17aa10 .word 0xffffbcd4
 *   @0x17aa14 .word 0xffffe6b8
 *   @0x17aa18 .word 0xffffe6c0
 *   @0x17aa1c .word 0xffffdf38
 *   @0x17aa20 .word 0xffffe6bc
 *   @0x17aa24 .word 0xffffdf40
 *   @0x17aa28 .word 0xffffe6c4
 *
 * ══ §13/36 Eff_Effect03(int, float, float, int, unsigned int)  0x1a0ab0  size 904  226 条（0x1a0ab0..0x1a0e38）
 * @func 0x1a0ab0 0x1a0e38  size 904  226 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1a0adc→0x542410
 * 调用序列: 0xb66e8×6 / ParticleType_Shape(int, int)×3 / ParticleType_Size(int, float, float, float, float)×3 / ParticleType_Speed(int, float, float, float, float)×3 / ParticleType_Direction(int, float, float, float, float)×3 / ParticleType_Alpha2(int, float, float)×3 / ParticleType_Life(int, int, int)×3 / ParticleType_Gravity(int, float, float)×3
 * 字段偏移 top8: 0x4×26 / 0x30×3 / 0x354×1 / 0x350×1
 * VFP 指令 57 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a0ab0 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x1a0ab4 vpush {d8}
 *   @0x1a0ab8 sub sp, sp, #12
 *   @0x1a0abc mov r4, r3
 *   @0x1a0ac0 mov r7, r1
 *   @0x1a0ac4 mov r8, r0
 *   @0x1a0ac8 mov r6, r2
 *   @0x1a0acc bl 0x19ff6c <_Z12Speed_Factorv>
 *   @0x1a0ad0 cmp r4, #0
 *   @0x1a0ad4 ldr r12, [pc, #0x354]
 *   @0x1a0ad8 mov r1, #8
 *   @0x1a0adc ldr r3, [pc, #0x350]
 *   @0x1a0ae0 add r12, pc, r12
 *   @0x1a0ae4 vmov s16, r0
 *   @0x1a0ae8 beq 0x1a0c08 <_Z12Eff_Effect03iffij+0x158>
 *   @0x1a0aec cmp r4, #2
 *   @0x1a0af0 ldr r4, [r12, r3]
 *   @0x1a0af4 mov r5, #0
 *   @0x1a0af8 ldr r0, [r4, #0x4]
 *   @0x1a0afc beq 0x1a0d18 <_Z12Eff_Effect03iffij+0x268>
 *   @0x1a0b00 bl 0x1a31a4 <_Z18ParticleType_Shapeii>
 *   @0x1a0b04 ldr r0, [r4, #0x4]
 *   @0x1a0b08 mov r3, r5
 *   @0x1a0b0c str r5, [sp]
 *   @0x1a0b10 movw r1, #0xcccd
 *   @0x1a0b14 movw r2, #0xcccd
 *   @0x1a0b18 movt r1, #0x3dcc
 *   @0x1a0b1c movt r2, #0x3e4c
 *   @0x1a0b20 bl 0x1a322c <_Z17ParticleType_Sizeiffff>
 *   @0x1a0b24 vmov.f32 s14, #5.000000e-01
 *   @0x1a0b28 ldr r0, [r4, #0x4]
 *   @0x1a0b2c mov r3, r5
 *   @0x1a0b30 str r5, [sp]
 *   @0x1a0b34 vmov.f32 s15, #6.000000e+00
 *   @0x1a0b38 vmul.f32 s14, s16, s14
 *   @0x1a0b3c vmul.f32 s15, s16, s15
 *   @0x1a0b40 vmov r1, s14
 *   @0x1a0b44 vmov r2, s15
 *   @0x1a0b48 bl 0x1a3368 <_Z18ParticleType_Speediffff>
 *   @0x1a0b4c mov r3, r5
 *   @0x1a0b50 ldr r0, [r4, #0x4]
 *   @0x1a0b54 mov r1, r5
 *   @0x1a0b58 str r5, [sp]
 *   @0x1a0b5c mov r2, #0
 *   @0x1a0b60 movt r2, #0x43b4
 *   @0x1a0b64 bl 0x1a33b4 <_Z22ParticleType_Directioniffff>
 *   @0x1a0b68 ldr r0, [r4, #0x4]
 *   @0x1a0b6c mov r1, #1065353216
 *   @0x1a0b70 movw r2, #0xcccd
 *   @0x1a0b74 movt r2, #0x3ecc
 *   @0x1a0b78 bl 0x1a36a4 <_Z19ParticleType_Alpha2iff>
 *   @0x1a0b7c vmov.f32 s15, #2.000000e+01
 *   @0x1a0b80 ldr r9, [r4, #0x4]
 *   @0x1a0b84 vdiv.f32 s15, s15, s16
 *   @0x1a0b88 vcvt.f64.f32 d6, s15
 *   @0x1a0b8c vmov r0, r1, d6
 *   @0x1a0b90 bl 0xb66e8 <lrint@plt>
 *   @0x1a0b94 vmov.f32 s15, #3.000000e+01
 *   @0x1a0b98 vdiv.f32 s15, s15, s16
 *   @0x1a0b9c mov r5, r0
 *   @0x1a0ba0 vcvt.f64.f32 d6, s15
 *   @0x1a0ba4 vmov r0, r1, d6
 *   @0x1a0ba8 bl 0xb66e8 <lrint@plt>
 *   @0x1a0bac mov r1, r5
 *   @0x1a0bb0 mov r2, r0
 *   @0x1a0bb4 mov r0, r9
 *   @0x1a0bb8 bl 0x1a32b4 <_Z17ParticleType_Lifeiii>
 *   @0x1a0bbc vldr s15, [pc, #604]
 *   @0x1a0bc0 vmul.f32 s15, s16, s15
 *   @0x1a0bc4 ldr r0, [r4, #0x4]
 *   @0x1a0bc8 mov r2, #0
 *   @0x1a0bcc movt r2, #0x4387
 *   @0x1a0bd0 vmov r1, s15
 *   @0x1a0bd4 bl 0x1a3454 <_Z20ParticleType_Gravityiff>
 *   @0x1a0bd8 ldr r2, [sp, #0x30]
 *   @0x1a0bdc ldr r3, [r4, #0x4]
 *   @0x1a0be0 mov r12, #150
 *   @0x1a0be4 mov r0, r8
 *   @0x1a0be8 mov r1, r7
 *   @0x1a0bec str r2, [sp]
 *   @0x1a0bf0 mov r2, r6
 *   @0x1a0bf4 str r12, [sp, #0x4]
 *   @0x1a0bf8 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji>
 *   @0x1a0bfc add sp, sp, #12
 *   @0x1a0c00 vpop {d8}
 *   @0x1a0c04 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x1a0c08 ldr r4, [r12, r3]
 *   @0x1a0c0c mov r5, #0
 *   @0x1a0c10 vldr s17, [pc, #524]
 *   @0x1a0c14 ldr r0, [r4, #0x4]
 *   @0x1a0c18 bl 0x1a31a4 <_Z18ParticleType_Shapeii>
 *   @0x1a0c1c ldr r0, [r4, #0x4]
 *   @0x1a0c20 vmov r1, s17
 *   @0x1a0c24 mov r3, r5
 *   @0x1a0c28 str r5, [sp]
 *   @0x1a0c2c movw r2, #0xcccd
 *   @0x1a0c30 movt r2, #0x3e4c
 *   @0x1a0c34 bl 0x1a322c <_Z17ParticleType_Sizeiffff>
 *   @0x1a0c38 vmov.f32 s14, #5.000000e-01
 *   @0x1a0c3c ldr r0, [r4, #0x4]
 *   @0x1a0c40 mov r3, r5
 *   @0x1a0c44 str r5, [sp]
 *   @0x1a0c48 vmov.f32 s15, #3.000000e+00
 *   @0x1a0c4c vmul.f32 s14, s16, s14
 *   @0x1a0c50 vmul.f32 s15, s16, s15
 *   @0x1a0c54 vmov r1, s14
 *   @0x1a0c58 vmov r2, s15
 *   @0x1a0c5c bl 0x1a3368 <_Z18ParticleType_Speediffff>
 *   @0x1a0c60 mov r3, r5
 *   @0x1a0c64 ldr r0, [r4, #0x4]
 *   @0x1a0c68 mov r1, r5
 *   @0x1a0c6c str r5, [sp]
 *   @0x1a0c70 mov r2, #0
 *   @0x1a0c74 movt r2, #0x43b4
 *   @0x1a0c78 bl 0x1a33b4 <_Z22ParticleType_Directioniffff>
 *   @0x1a0c7c ldr r0, [r4, #0x4]
 *   @0x1a0c80 mov r1, #1065353216
 *   @0x1a0c84 movw r2, #0xcccd
 *   @0x1a0c88 movt r2, #0x3ecc
 *   @0x1a0c8c bl 0x1a36a4 <_Z19ParticleType_Alpha2iff>
 *   @0x1a0c90 vmov.f32 s15, #1.500000e+01
 *   @0x1a0c94 ldr r9, [r4, #0x4]
 *   @0x1a0c98 vdiv.f32 s15, s15, s16
 *   @0x1a0c9c vcvt.f64.f32 d6, s15
 *   @0x1a0ca0 vmov r0, r1, d6
 *   @0x1a0ca4 bl 0xb66e8 <lrint@plt>
 *   @0x1a0ca8 vmov.f32 s15, #2.500000e+01
 *   @0x1a0cac vdiv.f32 s15, s15, s16
 *   @0x1a0cb0 mov r5, r0
 *   @0x1a0cb4 vcvt.f64.f32 d6, s15
 *   @0x1a0cb8 vmov r0, r1, d6
 *   @0x1a0cbc bl 0xb66e8 <lrint@plt>
 *   @0x1a0cc0 mov r1, r5
 *   @0x1a0cc4 mov r2, r0
 *   @0x1a0cc8 mov r0, r9
 *   @0x1a0ccc bl 0x1a32b4 <_Z17ParticleType_Lifeiii>
 *   @0x1a0cd0 vmul.f32 s17, s16, s17
 *   @0x1a0cd4 ldr r0, [r4, #0x4]
 *   @0x1a0cd8 mov r2, #0
 *   @0x1a0cdc movt r2, #0x4387
 *   @0x1a0ce0 vmov r1, s17
 *   @0x1a0ce4 bl 0x1a3454 <_Z20ParticleType_Gravityiff>
 *   @0x1a0ce8 ldr r2, [sp, #0x30]
 *   @0x1a0cec ldr r3, [r4, #0x4]
 *   @0x1a0cf0 mov r12, #75
 *   @0x1a0cf4 mov r0, r8
 *   @0x1a0cf8 mov r1, r7
 *   @0x1a0cfc str r2, [sp]
 *   @0x1a0d00 mov r2, r6
 *   @0x1a0d04 str r12, [sp, #0x4]
 *   @0x1a0d08 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji>
 *   @0x1a0d0c add sp, sp, #12
 *   @0x1a0d10 vpop {d8}
 *   @0x1a0d14 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x1a0d18 bl 0x1a31a4 <_Z18ParticleType_Shapeii>
 *   @0x1a0d1c ldr r0, [r4, #0x4]
 *   @0x1a0d20 mov r3, r5
 *   @0x1a0d24 str r5, [sp]
 *   @0x1a0d28 movw r1, #0xcccd
 *   @0x1a0d2c movw r2, #0xcccd
 *   @0x1a0d30 movt r1, #0x3dcc
 *   @0x1a0d34 movt r2, #0x3e4c
 *   @0x1a0d38 bl 0x1a322c <_Z17ParticleType_Sizeiffff>
 *   @0x1a0d3c vmov.f32 s14, #5.000000e-01
 *   @0x1a0d40 ldr r0, [r4, #0x4]
 *   @0x1a0d44 mov r3, r5
 *   @0x1a0d48 str r5, [sp]
 *   @0x1a0d4c vmov.f32 s15, #8.000000e+00
 *   @0x1a0d50 vmul.f32 s14, s16, s14
 *   @0x1a0d54 vmul.f32 s15, s16, s15
 *   @0x1a0d58 vmov r1, s14
 *   @0x1a0d5c vmov r2, s15
 *   @0x1a0d60 bl 0x1a3368 <_Z18ParticleType_Speediffff>
 *   @0x1a0d64 mov r3, r5
 *   @0x1a0d68 ldr r0, [r4, #0x4]
 *   @0x1a0d6c mov r1, r5
 *   @0x1a0d70 str r5, [sp]
 *   @0x1a0d74 mov r2, #0
 *   @0x1a0d78 movt r2, #0x43b4
 *   @0x1a0d7c bl 0x1a33b4 <_Z22ParticleType_Directioniffff>
 *   @0x1a0d80 ldr r0, [r4, #0x4]
 *   @0x1a0d84 mov r1, #1065353216
 *   @0x1a0d88 movw r2, #0xcccd
 *   @0x1a0d8c movt r2, #0x3ecc
 *   @0x1a0d90 bl 0x1a36a4 <_Z19ParticleType_Alpha2iff>
 *   @0x1a0d94 vmov.f32 s15, #3.000000e+01
 *   @0x1a0d98 ldr r9, [r4, #0x4]
 *   @0x1a0d9c vdiv.f32 s15, s15, s16
 *   @0x1a0da0 vcvt.f64.f32 d6, s15
 *   @0x1a0da4 vmov r0, r1, d6
 *   @0x1a0da8 bl 0xb66e8 <lrint@plt>
 *   @0x1a0dac vldr s15, [pc, #116]
 *   @0x1a0db0 vdiv.f32 s15, s15, s16
 *   @0x1a0db4 mov r5, r0
 *   @0x1a0db8 vcvt.f64.f32 d6, s15
 *   @0x1a0dbc vmov r0, r1, d6
 *   @0x1a0dc0 bl 0xb66e8 <lrint@plt>
 *   @0x1a0dc4 mov r1, r5
 *   @0x1a0dc8 mov r2, r0
 *   @0x1a0dcc mov r0, r9
 *   @0x1a0dd0 bl 0x1a32b4 <_Z17ParticleType_Lifeiii>
 *   @0x1a0dd4 vldr s15, [pc, #80]
 *   @0x1a0dd8 vmul.f32 s15, s16, s15
 *   @0x1a0ddc ldr r0, [r4, #0x4]
 *   @0x1a0de0 mov r2, #0
 *   @0x1a0de4 movt r2, #0x4387
 *   @0x1a0de8 vmov r1, s15
 *   @0x1a0dec bl 0x1a3454 <_Z20ParticleType_Gravityiff>
 *   @0x1a0df0 ldr r2, [sp, #0x30]
 *   @0x1a0df4 ldr r3, [r4, #0x4]
 *   @0x1a0df8 mov r12, #250
 *   @0x1a0dfc mov r0, r8
 *   @0x1a0e00 mov r1, r7
 *   @0x1a0e04 str r2, [sp]
 *   @0x1a0e08 mov r2, r6
 *   @0x1a0e0c str r12, [sp, #0x4]
 *   @0x1a0e10 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji>
 *   @0x1a0e14 add sp, sp, #12
 *   @0x1a0e18 vpop {d8}
 *   @0x1a0e1c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x1a0e20 mrclo p9, #0x0, r9, c9, c10, #0x4
 *   @0x1a0e24 stcllo p12, c12, [r12, #820]
 *   @0x1a0e28 eormi r0, r0, #0
 *   @0x1a0e2c mcrlo p4, #0x1, r1, c14, c11, #0x3
 *   @0x1a0e30 eoreq r1, r5, r0, ror r1
 *   @0x1a0e34 .word 0xffffeb2c
 *
 * ══ §14/36 GR_Surface_Screenshot_Part(int, int, int, int, int)  0x1720e4  size 900  225 条（0x1720e4..0x172468）
 * @func 0x1720e4 0x172468  size 900  225 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1720f4→0x4a22b1, 0x172150→0x3eb70c, 0x1721fc→0x3eb70c
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / 0xb65b0×2 / 0xb65bc×2 / MemoryManager::Free(void const*)×2 / Graphics::Surface_GrabRect(void*, int, int, int, int)×2 / Graphics::Flush() / GR_Surface_Get(int) / GR_Texture_Get_Surface(int)
 * 字段偏移 top8: 0xc×11 / 0x8×6 / 0x4×5 / 0x10×5 / 0x14×5 / 0x1c×4 / 0x18×2 / 0x358×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1720e4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1720e8 mov r5, r3
 *   @0x1720ec ldr r8, [pc, #0x358]
 *   @0x1720f0 sub sp, sp, #36
 *   @0x1720f4 ldr r12, [pc, #0x354]
 *   @0x1720f8 mov r9, r0
 *   @0x1720fc add r8, pc, r8
 *   @0x172100 mov r6, r1
 *   @0x172104 mov r7, r2
 *   @0x172108 ldr r4, [sp, #0x48]
 *   @0x17210c ldr r3, [r8, r12]
 *   @0x172110 ldrb r3, [r3]
 *   @0x172114 cmp r3, #0
 *   @0x172118 beq 0x172390 <_Z26GR_Surface_Screenshot_Partiiiii+0x2ac>
 *   @0x17211c bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x172120 mov r0, r9
 *   @0x172124 bl 0x170f48 <_Z14GR_Surface_Geti>
 *   @0x172128 cmp r0, #0
 *   @0x17212c beq 0x172390 <_Z26GR_Surface_Screenshot_Partiiiii+0x2ac>
 *   @0x172130 ldr r0, [r0, #0x4]
 *   @0x172134 bl 0x17435c <_Z22GR_Texture_Get_Surfacei>
 *   @0x172138 subs r9, r0, #0
 *   @0x17213c beq 0x172390 <_Z26GR_Surface_Screenshot_Partiiiii+0x2ac>
 *   @0x172140 lsr r10, r6, #31
 *   @0x172144 lsr r11, r7, #31
 *   @0x172148 orrs r2, r10, r11
 *   @0x17214c beq 0x1721e4 <_Z26GR_Surface_Screenshot_Partiiiii+0x100>
 *   @0x172150 ldr r0, [pc, #0x2fc]
 *   @0x172154 add r12, r6, r5
 *   @0x172158 str r12, [sp, #0xc]
 *   @0x17215c add r12, r7, r4
 *   @0x172160 str r12, [sp, #0x10]
 *   @0x172164 mov r2, r6
 *   @0x172168 ldr r0, [r8, r0]
 *   @0x17216c mov r3, r7
 *   @0x172170 ldr r1, [pc, #0x2e0]
 *   @0x172174 ldr r0, [r0]
 *   @0x172178 add r1, pc, r1
 *   @0x17217c ldr r12, [r0]
 *   @0x172180 str r5, [sp]
 *   @0x172184 str r4, [sp, #0x4]
 *   @0x172188 ldr r12, [r12, #0xc]
 *   @0x17218c blx r12
 *   @0x172190 mul r12, r4, r5
 *   @0x172194 ldr r1, [pc, #0x2c0]
 *   @0x172198 mov r2, #70
 *   @0x17219c mov r3, #1
 *   @0x1721a0 add r1, pc, r1
 *   @0x1721a4 lsl r12, r12, #2
 *   @0x1721a8 str r12, [sp, #0x8]
 *   @0x1721ac mov r0, r12
 *   @0x1721b0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1721b4 ldr r12, [sp, #0x8]
 *   @0x1721b8 mov r1, #0
 *   @0x1721bc mov r2, r12
 *   @0x1721c0 mov r8, r0
 *   @0x1721c4 bl 0xb65b0 <memset@plt>
 *   @0x1721c8 cmp r10, #0
 *   @0x1721cc bne 0x1723cc <_Z26GR_Surface_Screenshot_Partiiiii+0x2e8>
 *   @0x1721d0 ldr r12, [sp, #0xc]
 *   @0x1721d4 ldr r3, [sp, #0x10]
 *   @0x1721d8 str r10, [sp, #0x14]
 *   @0x1721dc str r5, [sp, #0xc]
 *   @0x1721e0 b 0x172274 <_Z26GR_Surface_Screenshot_Partiiiii+0x190>
 *   @0x1721e4 ldr r3, [r9, #0x4]
 *   @0x1721e8 add r12, r6, r5
 *   @0x1721ec cmp r12, r3
 *   @0x1721f0 addgt r3, r7, r4
 *   @0x1721f4 strgt r3, [sp, #0x10]
 *   @0x1721f8 ble 0x17239c <_Z26GR_Surface_Screenshot_Partiiiii+0x2b8>
 *   @0x1721fc ldr r0, [pc, #0x250]
 *   @0x172200 mov lr, #0
 *   @0x172204 str r5, [sp, #0xc]
 *   @0x172208 mov r2, r6
 *   @0x17220c mul r10, r4, r5
 *   @0x172210 ldr r0, [r8, r0]
 *   @0x172214 str lr, [sp, #0x14]
 *   @0x172218 mov r3, r7
 *   @0x17221c ldr r1, [pc, #0x23c]
 *   @0x172220 ldr r0, [r0]
 *   @0x172224 add r1, pc, r1
 *   @0x172228 lsl r10, r10, #2
 *   @0x17222c ldr lr, [r0]
 *   @0x172230 str r5, [sp]
 *   @0x172234 str r4, [sp, #0x4]
 *   @0x172238 ldr r8, [lr, #0xc]
 *   @0x17223c str r12, [sp, #0x8]
 *   @0x172240 blx r8
 *   @0x172244 ldr r1, [pc, #0x218]
 *   @0x172248 mov r3, #1
 *   @0x17224c mov r2, #70
 *   @0x172250 add r1, pc, r1
 *   @0x172254 mov r0, r10
 *   @0x172258 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x17225c mov r2, r10
 *   @0x172260 mov r1, #0
 *   @0x172264 mov r8, r0
 *   @0x172268 bl 0xb65b0 <memset@plt>
 *   @0x17226c ldr r3, [sp, #0x10]
 *   @0x172270 ldr r12, [sp, #0x8]
 *   @0x172274 cmp r11, #0
 *   @0x172278 ldr r2, [r9, #0x4]
 *   @0x17227c rsbne r11, r7, #0
 *   @0x172280 movne r10, r3
 *   @0x172284 moveq r10, r4
 *   @0x172288 movne r7, #0
 *   @0x17228c cmp r2, r12
 *   @0x172290 rsblt r2, r6, r2
 *   @0x172294 strlt r2, [sp, #0xc]
 *   @0x172298 ldr r2, [r9, #0x8]
 *   @0x17229c ldr r12, [sp, #0xc]
 *   @0x1722a0 cmp r2, r3
 *   @0x1722a4 rsblt r10, r7, r2
 *   @0x1722a8 cmp r10, #0
 *   @0x1722ac cmpgt r12, #0
 *   @0x1722b0 bgt 0x1723e4 <_Z26GR_Surface_Screenshot_Partiiiii+0x300>
 *   @0x1722b4 cmp r8, #0
 *   @0x1722b8 beq 0x172390 <_Z26GR_Surface_Screenshot_Partiiiii+0x2ac>
 *   @0x1722bc bl 0x1a912c <_ZN7IBitmap6CreateEv>
 *   @0x1722c0 mov r1, #7
 *   @0x1722c4 mov r7, #0
 *   @0x1722c8 ldr r3, [r0]
 *   @0x1722cc mov r9, r0
 *   @0x1722d0 ldr r3, [r3, #0x1c]
 *   @0x1722d4 blx r3
 *   @0x1722d8 ldr r3, [r9]
 *   @0x1722dc mov r0, r9
 *   @0x1722e0 mov r1, r5
 *   @0x1722e4 ldr r3, [r3, #0xc]
 *   @0x1722e8 blx r3
 *   @0x1722ec ldr r3, [r9]
 *   @0x1722f0 mov r0, r9
 *   @0x1722f4 mov r1, r4
 *   @0x1722f8 ldr r3, [r3, #0x14]
 *   @0x1722fc blx r3
 *   @0x172300 add r2, sp, #32
 *   @0x172304 mov r0, r9
 *   @0x172308 mov r1, r7
 *   @0x17230c str r7, [r2, #-0x4]!
 *   @0x172310 add r3, sp, #24
 *   @0x172314 ldr r12, [r9]
 *   @0x172318 str r7, [sp, #0x18]
 *   @0x17231c ldr r12, [r12, #0x24]
 *   @0x172320 blx r12
 *   @0x172324 cmp r4, r7
 *   @0x172328 mov r10, r0
 *   @0x17232c ble 0x172368 <_Z26GR_Surface_Screenshot_Partiiiii+0x284>
 *   @0x172330 ldr r0, [sp, #0x1c]
 *   @0x172334 lsl r5, r5, #2
 *   @0x172338 mov r6, r8
 *   @0x17233c mov r1, r6
 *   @0x172340 add r7, r7, #1
 *   @0x172344 mov r2, r5
 *   @0x172348 add r6, r6, r5
 *   @0x17234c bl 0xb65bc <memcpy@plt>
 *   @0x172350 ldr r0, [sp, #0x1c]
 *   @0x172354 ldr r3, [sp, #0x18]
 *   @0x172358 cmp r7, r4
 *   @0x17235c add r0, r0, r3
 *   @0x172360 str r0, [sp, #0x1c]
 *   @0x172364 bne 0x17233c <_Z26GR_Surface_Screenshot_Partiiiii+0x258>
 *   @0x172368 ldr r3, [r9]
 *   @0x17236c mov r1, r10
 *   @0x172370 mov r0, r9
 *   @0x172374 ldr r3, [r3, #0x28]
 *   @0x172378 blx r3
 *   @0x17237c mov r0, r8
 *   @0x172380 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x172384 mov r0, r9
 *   @0x172388 add sp, sp, #36
 *   @0x17238c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x172390 mov r0, #0
 *   @0x172394 add sp, sp, #36
 *   @0x172398 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x17239c ldr r3, [r9, #0x8]
 *   @0x1723a0 add lr, r7, r4
 *   @0x1723a4 str lr, [sp, #0x10]
 *   @0x1723a8 cmp lr, r3
 *   @0x1723ac bgt 0x1721fc <_Z26GR_Surface_Screenshot_Partiiiii+0x118>
 *   @0x1723b0 str r4, [sp]
 *   @0x1723b4 mov r1, r6
 *   @0x1723b8 mov r2, r7
 *   @0x1723bc mov r3, r5
 *   @0x1723c0 bl 0x17e594 <_ZN8Graphics16Surface_GrabRectEPviiii>
 *   @0x1723c4 mov r8, r0
 *   @0x1723c8 b 0x1722b4 <_Z26GR_Surface_Screenshot_Partiiiii+0x1d0>
 *   @0x1723cc rsb r6, r6, #0
 *   @0x1723d0 ldr r3, [sp, #0x10]
 *   @0x1723d4 str r6, [sp, #0x14]
 *   @0x1723d8 mov r6, #0
 *   @0x1723dc ldr r12, [sp, #0xc]
 *   @0x1723e0 b 0x172274 <_Z26GR_Surface_Screenshot_Partiiiii+0x190>
 *   @0x1723e4 mov r3, r12
 *   @0x1723e8 mov r0, r9
 *   @0x1723ec mov r1, r6
 *   @0x1723f0 mov r2, r7
 *   @0x1723f4 str r10, [sp]
 *   @0x1723f8 lsl r6, r12, #2
 *   @0x1723fc bl 0x17e594 <_ZN8Graphics16Surface_GrabRectEPviiii>
 *   @0x172400 ldr r12, [sp, #0x14]
 *   @0x172404 lsl r9, r5, #2
 *   @0x172408 mla r3, r5, r11, r12
 *   @0x17240c mov r11, #0
 *   @0x172410 add r3, r8, r3, lsl #2
 *   @0x172414 mov r7, r0
 *   @0x172418 str r0, [sp, #0xc]
 *   @0x17241c mov r0, r3
 *   @0x172420 mov r1, r7
 *   @0x172424 mov r2, r6
 *   @0x172428 add r11, r11, #1
 *   @0x17242c bl 0xb65bc <memcpy@plt>
 *   @0x172430 cmp r10, r11
 *   @0x172434 add r7, r7, r6
 *   @0x172438 add r3, r0, r9
 *   @0x17243c bgt 0x17241c <_Z26GR_Surface_Screenshot_Partiiiii+0x338>
 *   @0x172440 ldr r0, [sp, #0xc]
 *   @0x172444 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x172448 b 0x1722b4 <_Z26GR_Surface_Screenshot_Partiiiii+0x1d0>
 *   @0x17244c eoreq pc, r7, r4, asr r11
 *   @0x172450 .word 0xffffe4d0
 *   @0x172454 .word 0xffffbac4
 *   @0x172458 andseq r9, sp, r0, asr #5
 *   @0x17245c mulseq r11, r0, lr
 *   @0x172460 andseq r9, sp, r4, lsl r2
 *   @0x172464 andseq lr, r11, r0, ror #27
 *
 * ══ §15/36 ObjectBaseToString(YYObjectBase*)  0x24a48c  size 900  225 条（0x24a48c..0x24a810）
 * @func 0x24a48c 0x24a810  size 900  225 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYFree(void const*)×6 / YYAlloc(int)×5 / 0xb65bc×4 / 0xb65a4×2 / YYObject_PropertyNameIterator::YYObject_PropertyNameIterator(YYObjectBase*, int) / JS_GetOwnProperty(YYObjectBase*, RValue*, char const*) / 0xb6538 / ObjectBaseToString(YYObjectBase*)+0x118
 * 字段偏移 top8: 0x28×18 / 0x20×14 / 0x24×13 / 0x18×4 / 0x8×2 / 0xc×2 / 0x2c×2 / 0x4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24a48c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x24a490 sub sp, sp, #108
 *   @0x24a494 add r6, sp, #76
 *   @0x24a498 mov r1, r0
 *   @0x24a49c mov r2, #0
 *   @0x24a4a0 mov r8, r0
 *   @0x24a4a4 mov r0, r6
 *   @0x24a4a8 add r7, sp, #44
 *   @0x24a4ac bl 0x2400ec <_ZN29YYObject_PropertyNameIteratorC2EP12YYObjectBasei>
 *   @0x24a4b0 mov r2, #1
 *   @0x24a4b4 ldr r0, [pc, #0x34c]
 *   @0x24a4b8 mov r3, #0
 *   @0x24a4bc strb r2, [sp, #0x5d]
 *   @0x24a4c0 mov r10, #5
 *   @0x24a4c4 ldr r2, [pc, #0x340]
 *   @0x24a4c8 add r0, pc, r0
 *   @0x24a4cc add r5, sp, #60
 *   @0x24a4d0 str r3, [sp, #0x20]
 *   @0x24a4d4 add r2, pc, r2
 *   @0x24a4d8 str r3, [sp, #0x24]
 *   @0x24a4dc str r3, [sp, #0x28]
 *   @0x24a4e0 str r0, [sp, #0x8]
 *   @0x24a4e4 str r2, [sp, #0xc]
 *   @0x24a4e8 b 0x24a7b8 <_Z18ObjectBaseToStringP12YYObjectBase+0x32c>
 *   @0x24a4ec ldr r3, [sp, #0x2c]
 *   @0x24a4f0 mov r0, r8
 *   @0x24a4f4 mov r1, r5
 *   @0x24a4f8 str r10, [sp, #0x48]
 *   @0x24a4fc ldr r2, [r3]
 *   @0x24a500 bl 0x241890 <_Z17JS_GetOwnPropertyP12YYObjectBaseP6RValuePKc>
 *   @0x24a504 ldr r3, [sp, #0x2c]
 *   @0x24a508 ldr r9, [r3]
 *   @0x24a50c cmp r9, #0
 *   @0x24a510 ldreq r4, [sp, #0x28]
 *   @0x24a514 beq 0x24a5c0 <_Z18ObjectBaseToStringP12YYObjectBase+0x134>
 *   @0x24a518 mov r0, r9
 *   @0x24a51c bl 0xb6538 <strlen@plt>
 *   @0x24a520 ldr r2, [sp, #0x28]
 *   @0x24a524 ldr r3, [sp, #0x24]
 *   @0x24a528 add r1, r0, #1
 *   @0x24a52c mov r4, r0
 *   @0x24a530 mvn r0, r2
 *   @0x24a534 add r0, r3, r0
 *   @0x24a538 cmp r1, r0
 *   @0x24a53c ble 0x24a5a4 <_Z18ObjectBaseToStringP12YYObjectBase+0x118>
 *   @0x24a540 cmp r3, #0
 *   @0x24a544 add r2, r1, r2
 *   @0x24a548 ldr r11, [sp, #0x20]
 *   @0x24a54c moveq r3, r1
 *   @0x24a550 add r3, r3, r3, lsl #1
 *   @0x24a554 add r3, r3, r3, lsr #31
 *   @0x24a558 asr r3, r3, #1
 *   @0x24a55c cmp r3, r2
 *   @0x24a560 addlt r2, r2, r2, lsl #1
 *   @0x24a564 addlt r2, r2, r2, lsr #31
 *   @0x24a568 asrlt r3, r2, #1
 *   @0x24a56c str r3, [sp, #0x4]
 *   @0x24a570 mov r0, r3
 *   @0x24a574 bl 0xcef4c <_Z7YYAlloci>
 *   @0x24a578 ldr r2, [sp, #0x24]
 *   @0x24a57c mov r1, r11
 *   @0x24a580 str r0, [sp, #0x20]
 *   @0x24a584 bl 0xb65bc <memcpy@plt>
 *   @0x24a588 ldr r3, [sp, #0x4]
 *   @0x24a58c cmp r11, #0
 *   @0x24a590 str r3, [sp, #0x24]
 *   @0x24a594 beq 0x24a5a0 <_Z18ObjectBaseToStringP12YYObjectBase+0x114>
 *   @0x24a598 mov r0, r11
 *   @0x24a59c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24a5a0 ldr r2, [sp, #0x28]
 *   @0x24a5a4 ldr r0, [sp, #0x20]
 *   @0x24a5a8 mov r1, r9
 *   @0x24a5ac add r0, r0, r2
 *   @0x24a5b0 bl 0xb65a4 <strcpy@plt>
 *   @0x24a5b4 ldr r3, [sp, #0x28]
 *   @0x24a5b8 add r4, r4, r3
 *   @0x24a5bc str r4, [sp, #0x28]
 *   @0x24a5c0 ldr r3, [sp, #0x24]
 *   @0x24a5c4 mvn r2, r4
 *   @0x24a5c8 add r2, r3, r2
 *   @0x24a5cc cmp r2, #3
 *   @0x24a5d0 bgt 0x24a630 <_Z18ObjectBaseToStringP12YYObjectBase+0x1a4>
 *   @0x24a5d4 cmp r3, #0
 *   @0x24a5d8 add r4, r4, #4
 *   @0x24a5dc addne r3, r3, r3, lsl #1
 *   @0x24a5e0 ldr r11, [sp, #0x20]
 *   @0x24a5e4 moveq r9, #6
 *   @0x24a5e8 addne r3, r3, r3, lsr #31
 *   @0x24a5ec asrne r9, r3, #1
 *   @0x24a5f0 cmp r4, r9
 *   @0x24a5f4 addgt r4, r4, r4, lsl #1
 *   @0x24a5f8 addgt r4, r4, r4, lsr #31
 *   @0x24a5fc asrgt r9, r4, #1
 *   @0x24a600 mov r0, r9
 *   @0x24a604 bl 0xcef4c <_Z7YYAlloci>
 *   @0x24a608 ldr r2, [sp, #0x24]
 *   @0x24a60c mov r1, r11
 *   @0x24a610 str r0, [sp, #0x20]
 *   @0x24a614 bl 0xb65bc <memcpy@plt>
 *   @0x24a618 cmp r11, #0
 *   @0x24a61c str r9, [sp, #0x24]
 *   @0x24a620 beq 0x24a62c <_Z18ObjectBaseToStringP12YYObjectBase+0x1a0>
 *   @0x24a624 mov r0, r11
 *   @0x24a628 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24a62c ldr r4, [sp, #0x28]
 *   @0x24a630 ldr r2, [sp, #0x8]
 *   @0x24a634 ldr r3, [sp, #0x20]
 *   @0x24a638 ldr r0, [r2]
 *   @0x24a63c str r0, [r3, r4]
 *   @0x24a640 mov r0, #256
 *   @0x24a644 ldr r3, [sp, #0x28]
 *   @0x24a648 str r0, [sp, #0x14]
 *   @0x24a64c add r3, r3, #3
 *   @0x24a650 str r3, [sp, #0x28]
 *   @0x24a654 bl 0xcef4c <_Z7YYAlloci>
 *   @0x24a658 mov r2, #0
 *   @0x24a65c add r1, sp, #24
 *   @0x24a660 mov r3, r0
 *   @0x24a664 add r0, sp, #104
 *   @0x24a668 str r3, [sp, #0x18]
 *   @0x24a66c str r3, [r0, #-0x4c]!
 *   @0x24a670 strb r2, [r3]
 *   @0x24a674 add r2, sp, #20
 *   @0x24a678 mov r3, r5
 *   @0x24a67c bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue>
 *   @0x24a680 ldr r1, [sp, #0x18]
 *   @0x24a684 ldr r4, [sp, #0x1c]
 *   @0x24a688 ldr r2, [sp, #0x28]
 *   @0x24a68c ldr r3, [sp, #0x24]
 *   @0x24a690 rsb r4, r1, r4
 *   @0x24a694 add r0, r4, #1
 *   @0x24a698 mvn r12, r2
 *   @0x24a69c add r12, r3, r12
 *   @0x24a6a0 cmp r0, r12
 *   @0x24a6a4 ble 0x24a708 <_Z18ObjectBaseToStringP12YYObjectBase+0x27c>
 *   @0x24a6a8 cmp r3, #0
 *   @0x24a6ac add r2, r0, r2
 *   @0x24a6b0 ldr r11, [sp, #0x20]
 *   @0x24a6b4 moveq r3, r0
 *   @0x24a6b8 add r3, r3, r3, lsl #1
 *   @0x24a6bc add r3, r3, r3, lsr #31
 *   @0x24a6c0 asr r9, r3, #1
 *   @0x24a6c4 cmp r9, r2
 *   @0x24a6c8 addlt r2, r2, r2, lsl #1
 *   @0x24a6cc addlt r2, r2, r2, lsr #31
 *   @0x24a6d0 asrlt r9, r2, #1
 *   @0x24a6d4 mov r0, r9
 *   @0x24a6d8 bl 0xcef4c <_Z7YYAlloci>
 *   @0x24a6dc ldr r2, [sp, #0x24]
 *   @0x24a6e0 mov r1, r11
 *   @0x24a6e4 str r0, [sp, #0x20]
 *   @0x24a6e8 bl 0xb65bc <memcpy@plt>
 *   @0x24a6ec cmp r11, #0
 *   @0x24a6f0 str r9, [sp, #0x24]
 *   @0x24a6f4 beq 0x24a700 <_Z18ObjectBaseToStringP12YYObjectBase+0x274>
 *   @0x24a6f8 mov r0, r11
 *   @0x24a6fc bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24a700 ldr r1, [sp, #0x18]
 *   @0x24a704 ldr r2, [sp, #0x28]
 *   @0x24a708 ldr r0, [sp, #0x20]
 *   @0x24a70c add r0, r0, r2
 *   @0x24a710 bl 0xb65a4 <strcpy@plt>
 *   @0x24a714 ldr r3, [sp, #0x28]
 *   @0x24a718 ldr r0, [sp, #0x18]
 *   @0x24a71c add r4, r3, r4
 *   @0x24a720 str r4, [sp, #0x28]
 *   @0x24a724 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24a728 ldr r3, [sp, #0x28]
 *   @0x24a72c ldr r2, [sp, #0x24]
 *   @0x24a730 mvn r1, r3
 *   @0x24a734 add r1, r2, r1
 *   @0x24a738 cmp r1, #1
 *   @0x24a73c bgt 0x24a79c <_Z18ObjectBaseToStringP12YYObjectBase+0x310>
 *   @0x24a740 cmp r2, #0
 *   @0x24a744 add r3, r3, #2
 *   @0x24a748 addne r2, r2, r2, lsl #1
 *   @0x24a74c ldr r4, [sp, #0x20]
 *   @0x24a750 moveq r11, #3
 *   @0x24a754 addne r2, r2, r2, lsr #31
 *   @0x24a758 asrne r11, r2, #1
 *   @0x24a75c cmp r3, r11
 *   @0x24a760 addgt r3, r3, r3, lsl #1
 *   @0x24a764 addgt r3, r3, r3, lsr #31
 *   @0x24a768 asrgt r11, r3, #1
 *   @0x24a76c mov r0, r11
 *   @0x24a770 bl 0xcef4c <_Z7YYAlloci>
 *   @0x24a774 ldr r2, [sp, #0x24]
 *   @0x24a778 mov r1, r4
 *   @0x24a77c str r0, [sp, #0x20]
 *   @0x24a780 bl 0xb65bc <memcpy@plt>
 *   @0x24a784 cmp r4, #0
 *   @0x24a788 str r11, [sp, #0x24]
 *   @0x24a78c beq 0x24a798 <_Z18ObjectBaseToStringP12YYObjectBase+0x30c>
 *   @0x24a790 mov r0, r4
 *   @0x24a794 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24a798 ldr r3, [sp, #0x28]
 *   @0x24a79c ldr r0, [sp, #0xc]
 *   @0x24a7a0 ldr r2, [sp, #0x20]
 *   @0x24a7a4 ldrh r1, [r0]
 *   @0x24a7a8 strh r1, [r2, r3]
 *   @0x24a7ac ldr r3, [sp, #0x28]
 *   @0x24a7b0 add r3, r3, #1
 *   @0x24a7b4 str r3, [sp, #0x28]
 *   @0x24a7b8 mov r0, r6
 *   @0x24a7bc mov r1, r7
 *   @0x24a7c0 bl 0x24a1fc <_ZN29YYObject_PropertyNameIterator4NextEP6RValue>
 *   @0x24a7c4 cmp r0, #0
 *   @0x24a7c8 bne 0x24a4ec <_Z18ObjectBaseToStringP12YYObjectBase+0x60>
 *   @0x24a7cc ldr r3, [sp, #0x28]
 *   @0x24a7d0 cmp r3, #0
 *   @0x24a7d4 mov r3, #0
 *   @0x24a7d8 addeq r0, sp, #40
 *   @0x24a7dc str r3, [sp, #0x28]
 *   @0x24a7e0 ldrne r0, [sp, #0x20]
 *   @0x24a7e4 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x24a7e8 mov r4, r0
 *   @0x24a7ec ldr r0, [sp, #0x20]
 *   @0x24a7f0 cmp r0, #0
 *   @0x24a7f4 beq 0x24a7fc <_Z18ObjectBaseToStringP12YYObjectBase+0x370>
 *   @0x24a7f8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24a7fc mov r0, r4
 *   @0x24a800 add sp, sp, #108
 *   @0x24a804 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x24a808 mulseq r0, r0, r9
 *   @0x24a80c andeq r8, lr, r4, asr #15
 *
 * ══ §16/36 anon_2b8084  0x2b8084  size 900  225 条（0x2b8084..0x2b8408）
 * @func 0x2b8084 0x2b8408  size 900  225 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×15 / 0x14×9 / 0x18×9 / 0xc×9 / 0x10×8 / 0x8×6 / 0x18c×4 / 0x1c×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b8084 cmp r1, #2
 *   @0x2b8088 push {r4, lr}
 *   @0x2b808c sub sp, sp, #8
 *   @0x2b8090 ldr r4, [r0, #0x18c]
 *   @0x2b8094 beq 0x2b8134 <jinit_phuff_decoder+0x158>
 *   @0x2b8098 cmp r1, #3
 *   @0x2b809c beq 0x2b8118 <jinit_phuff_decoder+0x13c>
 *   @0x2b80a0 cmp r1, #0
 *   @0x2b80a4 beq 0x2b80d0 <jinit_phuff_decoder+0xf4>
 *   @0x2b80a8 ldr r3, [r0]
 *   @0x2b80ac mov r1, #4
 *   @0x2b80b0 ldr r2, [r3]
 *   @0x2b80b4 str r1, [r3, #0x14]
 *   @0x2b80b8 blx r2
 *   @0x2b80bc mov r3, #0
 *   @0x2b80c0 str r3, [r4, #0x18]
 *   @0x2b80c4 str r3, [r4, #0x14]
 *   @0x2b80c8 add sp, sp, #8
 *   @0x2b80cc pop {r4, pc}
 *   @0x2b80d0 ldrb r2, [r0, #0x4a]
 *   @0x2b80d4 cmp r2, #0
 *   @0x2b80d8 beq 0x2b8150 <jinit_phuff_decoder+0x174>
 *   @0x2b80dc ldr r2, [r4, #0xc]
 *   @0x2b80e0 ldr r1, [pc, #0xa8]
 *   @0x2b80e4 cmp r2, #0
 *   @0x2b80e8 add r1, pc, r1
 *   @0x2b80ec str r1, [r4, #0x4]
 *   @0x2b80f0 bne 0x2b80bc <jinit_phuff_decoder+0xe0>
 *   @0x2b80f4 ldr r12, [r0, #0x4]
 *   @0x2b80f8 mov lr, #1
 *   @0x2b80fc ldr r1, [r4, #0x8]
 *   @0x2b8100 ldr r3, [r4, #0x10]
 *   @0x2b8104 str lr, [sp]
 *   @0x2b8108 ldr r12, [r12, #0x1c]
 *   @0x2b810c blx r12
 *   @0x2b8110 str r0, [r4, #0xc]
 *   @0x2b8114 b 0x2b80bc <jinit_phuff_decoder+0xe0>
 *   @0x2b8118 ldr r2, [r4, #0x8]
 *   @0x2b811c cmp r2, #0
 *   @0x2b8120 beq 0x2b8160 <jinit_phuff_decoder+0x184>
 *   @0x2b8124 ldr r3, [pc, #0x68]
 *   @0x2b8128 add r3, pc, r3
 *   @0x2b812c str r3, [r4, #0x4]
 *   @0x2b8130 b 0x2b80bc <jinit_phuff_decoder+0xe0>
 *   @0x2b8134 ldr r2, [r4, #0x8]
 *   @0x2b8138 cmp r2, #0
 *   @0x2b813c beq 0x2b8178 <jinit_phuff_decoder+0x19c>
 *   @0x2b8140 ldr r3, [pc, #0x50]
 *   @0x2b8144 add r3, pc, r3
 *   @0x2b8148 str r3, [r4, #0x4]
 *   @0x2b814c b 0x2b80bc <jinit_phuff_decoder+0xe0>
 *   @0x2b8150 ldr r3, [r0, #0x1a0]
 *   @0x2b8154 ldr r3, [r3, #0x4]
 *   @0x2b8158 str r3, [r4, #0x4]
 *   @0x2b815c b 0x2b80bc <jinit_phuff_decoder+0xe0>
 *   @0x2b8160 ldr r3, [r0]
 *   @0x2b8164 mov r1, #4
 *   @0x2b8168 ldr r2, [r3]
 *   @0x2b816c str r1, [r3, #0x14]
 *   @0x2b8170 blx r2
 *   @0x2b8174 b 0x2b8124 <jinit_phuff_decoder+0x148>
 *   @0x2b8178 ldr r3, [r0]
 *   @0x2b817c mov r1, #4
 *   @0x2b8180 ldr r2, [r3]
 *   @0x2b8184 str r1, [r3, #0x14]
 *   @0x2b8188 blx r2
 *   @0x2b818c b 0x2b8140 <jinit_phuff_decoder+0x164>
 *   @0x2b8190 andeq r0, r0, r12, lsr #1
 *   @0x2b8194 strdeq r0, r1, [r0], -r12
 *   @0x2b8198 ldrdeq r0, r1, [r0], -r12
 *   @0x2b819c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2b81a0 sub sp, sp, #28
 *   @0x2b81a4 ldr r6, [r0, #0x18c]
 *   @0x2b81a8 add r12, sp, #24
 *   @0x2b81ac ldr r4, [sp, #0x44]
 *   @0x2b81b0 mov r5, r0
 *   @0x2b81b4 ldr lr, [r0, #0x1a0]
 *   @0x2b81b8 mov r11, #0
 *   @0x2b81bc ldr r7, [r6, #0x10]
 *   @0x2b81c0 ldr r10, [r6, #0xc]
 *   @0x2b81c4 ldr r8, [r4]
 *   @0x2b81c8 ldr r9, [sp, #0x48]
 *   @0x2b81cc str r11, [r12, #-0x4]!
 *   @0x2b81d0 rsb r8, r8, r9
 *   @0x2b81d4 str r10, [sp]
 *   @0x2b81d8 cmp r8, r7
 *   @0x2b81dc strls r8, [sp, #0x8]
 *   @0x2b81e0 strhi r7, [sp, #0x8]
 *   @0x2b81e4 str r12, [sp, #0x4]
 *   @0x2b81e8 ldr r12, [lr, #0x4]
 *   @0x2b81ec ldr r7, [sp, #0x40]
 *   @0x2b81f0 blx r12
 *   @0x2b81f4 ldr r2, [r4]
 *   @0x2b81f8 mov r0, r5
 *   @0x2b81fc ldr r12, [r5, #0x1a8]
 *   @0x2b8200 ldr r3, [sp, #0x14]
 *   @0x2b8204 add r2, r7, r2, lsl #2
 *   @0x2b8208 ldr r1, [r6, #0xc]
 *   @0x2b820c ldr r12, [r12, #0x4]
 *   @0x2b8210 blx r12
 *   @0x2b8214 ldr r2, [r4]
 *   @0x2b8218 ldr r3, [sp, #0x14]
 *   @0x2b821c add r3, r2, r3
 *   @0x2b8220 str r3, [r4]
 *   @0x2b8224 add sp, sp, #28
 *   @0x2b8228 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2b822c push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x2b8230 mov r5, r0
 *   @0x2b8234 ldr r4, [r0, #0x18c]
 *   @0x2b8238 sub sp, sp, #20
 *   @0x2b823c mov r9, r1
 *   @0x2b8240 mov r8, r2
 *   @0x2b8244 mov r7, r3
 *   @0x2b8248 ldr r12, [r4, #0x18]
 *   @0x2b824c cmp r12, #0
 *   @0x2b8250 beq 0x2b82bc <jinit_phuff_decoder+0x2e0>
 *   @0x2b8254 ldr r3, [r4, #0xc]
 *   @0x2b8258 mov r6, r12
 *   @0x2b825c str r3, [sp]
 *   @0x2b8260 add r3, r4, #24
 *   @0x2b8264 ldr r12, [r5, #0x1a0]
 *   @0x2b8268 mov r1, r9
 *   @0x2b826c str r3, [sp, #0x4]
 *   @0x2b8270 mov r2, r8
 *   @0x2b8274 ldr lr, [r4, #0x10]
 *   @0x2b8278 mov r3, r7
 *   @0x2b827c mov r0, r5
 *   @0x2b8280 str lr, [sp, #0x8]
 *   @0x2b8284 ldr r12, [r12, #0x4]
 *   @0x2b8288 blx r12
 *   @0x2b828c ldr r3, [r4, #0x18]
 *   @0x2b8290 cmp r3, r6
 *   @0x2b8294 bhi 0x2b82ec <jinit_phuff_decoder+0x310>
 *   @0x2b8298 ldr r2, [r4, #0x10]
 *   @0x2b829c cmp r2, r3
 *   @0x2b82a0 ldrls r3, [r4, #0x14]
 *   @0x2b82a4 movls r1, #0
 *   @0x2b82a8 strls r1, [r4, #0x18]
 *   @0x2b82ac addls r2, r3, r2
 *   @0x2b82b0 strls r2, [r4, #0x14]
 *   @0x2b82b4 add sp, sp, #20
 *   @0x2b82b8 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x2b82bc ldr r12, [r0, #0x4]
 *   @0x2b82c0 mov lr, #1
 *   @0x2b82c4 ldr r3, [r4, #0x10]
 *   @0x2b82c8 ldr r1, [r4, #0x8]
 *   @0x2b82cc ldr r2, [r4, #0x14]
 *   @0x2b82d0 str lr, [sp]
 *   @0x2b82d4 ldr r12, [r12, #0x1c]
 *   @0x2b82d8 blx r12
 *   @0x2b82dc ldr r6, [r4, #0x18]
 *   @0x2b82e0 mov r3, r0
 *   @0x2b82e4 str r0, [r4, #0xc]
 *   @0x2b82e8 b 0x2b825c <jinit_phuff_decoder+0x280>
 *   @0x2b82ec ldr r12, [r5, #0x1a8]
 *   @0x2b82f0 rsb r7, r6, r3
 *   @0x2b82f4 ldr r1, [r4, #0xc]
 *   @0x2b82f8 mov r2, #0
 *   @0x2b82fc mov r3, r7
 *   @0x2b8300 mov r0, r5
 *   @0x2b8304 ldr r12, [r12, #0x4]
 *   @0x2b8308 add r1, r1, r6, lsl #2
 *   @0x2b830c blx r12
 *   @0x2b8310 ldr r2, [sp, #0x34]
 *   @0x2b8314 ldr r3, [r2]
 *   @0x2b8318 add r7, r3, r7
 *   @0x2b831c str r7, [r2]
 *   @0x2b8320 ldr r3, [r4, #0x18]
 *   @0x2b8324 b 0x2b8298 <jinit_phuff_decoder+0x2bc>
 *   @0x2b8328 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x2b832c sub sp, sp, #12
 *   @0x2b8330 ldr r4, [r0, #0x18c]
 *   @0x2b8334 mov r5, r0
 *   @0x2b8338 ldr r7, [sp, #0x28]
 *   @0x2b833c ldr r6, [sp, #0x2c]
 *   @0x2b8340 ldr r3, [r4, #0x18]
 *   @0x2b8344 ldr r8, [sp, #0x30]
 *   @0x2b8348 cmp r3, #0
 *   @0x2b834c beq 0x2b83dc <jinit_phuff_decoder+0x400>
 *   @0x2b8350 ldr r1, [r4, #0xc]
 *   @0x2b8354 ldr r2, [r6]
 *   @0x2b8358 add r1, r1, r3, lsl #2
 *   @0x2b835c ldr r9, [r5, #0x60]
 *   @0x2b8360 mov r0, r5
 *   @0x2b8364 ldr r12, [r4, #0x14]
 *   @0x2b8368 rsb r8, r2, r8
 *   @0x2b836c ldr lr, [r4, #0x10]
 *   @0x2b8370 add r2, r7, r2, lsl #2
 *   @0x2b8374 rsb r7, r12, r9
 *   @0x2b8378 ldr r12, [r5, #0x1a8]
 *   @0x2b837c rsb r3, r3, lr
 *   @0x2b8380 cmp r8, r7
 *   @0x2b8384 movlo r5, r8
 *   @0x2b8388 movhs r5, r7
 *   @0x2b838c cmp r5, r3
 *   @0x2b8390 movhs r5, r3
 *   @0x2b8394 ldr r12, [r12, #0x4]
 *   @0x2b8398 mov r3, r5
 *   @0x2b839c blx r12
 *   @0x2b83a0 ldr r3, [r6]
 *   @0x2b83a4 add r3, r3, r5
 *   @0x2b83a8 str r3, [r6]
 *   @0x2b83ac ldr r2, [r4, #0x18]
 *   @0x2b83b0 ldr r3, [r4, #0x10]
 *   @0x2b83b4 add r5, r5, r2
 *   @0x2b83b8 str r5, [r4, #0x18]
 *   @0x2b83bc cmp r5, r3
 *   @0x2b83c0 ldrhs r2, [r4, #0x14]
 *   @0x2b83c4 movhs r1, #0
 *   @0x2b83c8 addhs r3, r2, r3
 *   @0x2b83cc strhs r3, [r4, #0x14]
 *   @0x2b83d0 strhs r1, [r4, #0x18]
 *   @0x2b83d4 add sp, sp, #12
 *   @0x2b83d8 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x2b83dc ldr lr, [r4, #0x10]
 *   @0x2b83e0 ldr r12, [r0, #0x4]
 *   @0x2b83e4 ldr r1, [r4, #0x8]
 *   @0x2b83e8 ldr r2, [r4, #0x14]
 *   @0x2b83ec str r3, [sp]
 *   @0x2b83f0 mov r3, lr
 *   @0x2b83f4 ldr r12, [r12, #0x1c]
 *   @0x2b83f8 blx r12
 *   @0x2b83fc ldr r3, [r4, #0x18]
 *   @0x2b8400 mov r1, r0
 *   @0x2b8404 str r0, [r4, #0xc]
 *
 * ══ §17/36 IniFile::GetKey()  0x235710  size 896  224 条（0x235710..0x235a90）
 * @func 0x235710 0x235a90  size 896  224 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)×3 / 0xb65bc×3 / IniFile::SkipWhiteSpace()×2 / IniFile::GetKey()+0x9c×2 / IniFile::IsWhiteSpace() / Key::~Key() / operator delete(void*) / operator new(unsigned int)
 * 字段偏移 top8: 0xc×11 / 0x4×9 / 0x10×8 / 0x8×5 / 0x1×3 / 0x14×2 / 0x2a8×1 / 0x120×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x235710 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x235714 mov r4, r0
 *   @0x235718 bl 0x235578 <_ZN7IniFile14SkipWhiteSpaceEv>
 *   @0x23571c ldr r6, [r4, #0xc]
 *   @0x235720 ldr r3, [r4, #0x4]
 *   @0x235724 cmp r6, r3
 *   @0x235728 bge 0x2357ac <_ZN7IniFile6GetKeyEv+0x9c>
 *   @0x23572c ldr r3, [r4, #0x10]
 *   @0x235730 ldrb r3, [r3, r6]
 *   @0x235734 cmp r3, #91
 *   @0x235738 beq 0x2357ac <_ZN7IniFile6GetKeyEv+0x9c>
 *   @0x23573c cmp r3, #61
 *   @0x235740 beq 0x235a18 <_ZN7IniFile6GetKeyEv+0x308>
 *   @0x235744 mvn r5, #0
 *   @0x235748 b 0x235778 <_ZN7IniFile6GetKeyEv+0x68>
 *   @0x23574c ldr r3, [r4, #0xc]
 *   @0x235750 mvn r5, #0
 *   @0x235754 ldr r0, [r4, #0x10]
 *   @0x235758 add r3, r3, #1
 *   @0x23575c str r3, [r4, #0xc]
 *   @0x235760 ldrb r0, [r0, r3]
 *   @0x235764 cmp r0, #61
 *   @0x235768 beq 0x2357b4 <_ZN7IniFile6GetKeyEv+0xa4>
 *   @0x23576c ldr r0, [r4, #0x4]
 *   @0x235770 cmp r0, r3
 *   @0x235774 ble 0x2357ac <_ZN7IniFile6GetKeyEv+0x9c>
 *   @0x235778 mov r0, r4
 *   @0x23577c bl 0x235518 <_ZN7IniFile12IsWhiteSpaceEv>
 *   @0x235780 cmp r0, #0
 *   @0x235784 beq 0x23574c <_ZN7IniFile6GetKeyEv+0x3c>
 *   @0x235788 cmp r5, #0
 *   @0x23578c ldrlt r5, [r4, #0xc]
 *   @0x235790 ldrge r3, [r4, #0xc]
 *   @0x235794 movlt r3, r5
 *   @0x235798 b 0x235754 <_ZN7IniFile6GetKeyEv+0x44>
 *   @0x23579c mov r0, r7
 *   @0x2357a0 bl 0x2353b0 <_ZN3KeyD2Ev>
 *   @0x2357a4 mov r0, r7
 *   @0x2357a8 bl 0x27d1d0 <_ZdlPv>
 *   @0x2357ac mov r0, #0
 *   @0x2357b0 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2357b4 ldr r2, [r4, #0x4]
 *   @0x2357b8 cmp r2, r3
 *   @0x2357bc ble 0x2357ac <_ZN7IniFile6GetKeyEv+0x9c>
 *   @0x2357c0 cmp r5, #0
 *   @0x2357c4 movlt r5, r3
 *   @0x2357c8 mov r0, #12
 *   @0x2357cc rsb r5, r6, r5
 *   @0x2357d0 bl 0x27c524 <_Znwj>
 *   @0x2357d4 ldr r1, [pc, #0x2a8]
 *   @0x2357d8 mov r8, #0
 *   @0x2357dc mov r3, #1
 *   @0x2357e0 movw r2, #0x129
 *   @0x2357e4 add r1, pc, r1
 *   @0x2357e8 mov r7, r0
 *   @0x2357ec add r0, r5, #1
 *   @0x2357f0 str r8, [r7, #0x4]
 *   @0x2357f4 str r8, [r7, #0x8]
 *   @0x2357f8 str r8, [r7]
 *   @0x2357fc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x235800 ldr r1, [r4, #0x10]
 *   @0x235804 mov r2, r5
 *   @0x235808 add r1, r1, r6
 *   @0x23580c str r0, [r7, #0x4]
 *   @0x235810 bl 0xb65bc <memcpy@plt>
 *   @0x235814 ldr r3, [r7, #0x4]
 *   @0x235818 strb r8, [r3, r5]
 *   @0x23581c ldr r12, [r4, #0x10]
 *   @0x235820 ldr r2, [r4, #0xc]
 *   @0x235824 ldr r0, [r4, #0x4]
 *   @0x235828 add r3, r12, r2
 *   @0x23582c ldrb r1, [r12, r2]
 *   @0x235830 cmp r1, #61
 *   @0x235834 beq 0x235868 <_ZN7IniFile6GetKeyEv+0x158>
 *   @0x235838 cmp r2, r0
 *   @0x23583c bge 0x23579c <_ZN7IniFile6GetKeyEv+0x8c>
 *   @0x235840 add lr, r12, r0
 *   @0x235844 rsb r12, r12, #1
 *   @0x235848 b 0x235854 <_ZN7IniFile6GetKeyEv+0x144>
 *   @0x23584c cmp r3, lr
 *   @0x235850 beq 0x23579c <_ZN7IniFile6GetKeyEv+0x8c>
 *   @0x235854 add r2, r12, r3
 *   @0x235858 str r2, [r4, #0xc]
 *   @0x23585c ldrb r1, [r3, #0x1]!
 *   @0x235860 cmp r1, #61
 *   @0x235864 bne 0x23584c <_ZN7IniFile6GetKeyEv+0x13c>
 *   @0x235868 cmp r2, r0
 *   @0x23586c bge 0x23579c <_ZN7IniFile6GetKeyEv+0x8c>
 *   @0x235870 add r2, r2, #1
 *   @0x235874 mov r0, r4
 *   @0x235878 str r2, [r4, #0xc]
 *   @0x23587c ldr r5, [r4, #0x14]
 *   @0x235880 bl 0x235578 <_ZN7IniFile14SkipWhiteSpaceEv>
 *   @0x235884 ldr r3, [r4, #0x14]
 *   @0x235888 cmp r3, r5
 *   @0x23588c bne 0x23579c <_ZN7IniFile6GetKeyEv+0x8c>
 *   @0x235890 ldr r9, [r4, #0xc]
 *   @0x235894 ldr r1, [r4, #0x10]
 *   @0x235898 ldrb r3, [r1, r9]
 *   @0x23589c cmp r3, #34
 *   @0x2358a0 addeq r9, r9, #1
 *   @0x2358a4 moveq r6, #34
 *   @0x2358a8 beq 0x235a28 <_ZN7IniFile6GetKeyEv+0x318>
 *   @0x2358ac cmp r3, #39
 *   @0x2358b0 beq 0x235a20 <_ZN7IniFile6GetKeyEv+0x310>
 *   @0x2358b4 mov lr, r9
 *   @0x2358b8 mov r8, #0
 *   @0x2358bc mov r6, #59
 *   @0x2358c0 mov r5, #35
 *   @0x2358c4 cmp r3, #10
 *   @0x2358c8 cmpne r3, #13
 *   @0x2358cc moveq r10, #0
 *   @0x2358d0 movne r10, #1
 *   @0x2358d4 beq 0x235a10 <_ZN7IniFile6GetKeyEv+0x300>
 *   @0x2358d8 cmp r5, r3
 *   @0x2358dc beq 0x235a0c <_ZN7IniFile6GetKeyEv+0x2fc>
 *   @0x2358e0 cmp r6, r3
 *   @0x2358e4 beq 0x235a0c <_ZN7IniFile6GetKeyEv+0x2fc>
 *   @0x2358e8 ldr r12, [r4, #0x4]
 *   @0x2358ec cmp r12, lr
 *   @0x2358f0 ble 0x235a0c <_ZN7IniFile6GetKeyEv+0x2fc>
 *   @0x2358f4 add r1, r1, lr
 *   @0x2358f8 mov r2, lr
 *   @0x2358fc mvn r0, #0
 *   @0x235900 cmp r3, #32
 *   @0x235904 cmpne r3, #9
 *   @0x235908 mvnne r0, #0
 *   @0x23590c bne 0x235918 <_ZN7IniFile6GetKeyEv+0x208>
 *   @0x235910 cmp r0, #0
 *   @0x235914 movlt r0, r2
 *   @0x235918 add r2, r2, #1
 *   @0x23591c str r2, [r4, #0xc]
 *   @0x235920 ldrb r3, [r1, #0x1]!
 *   @0x235924 cmp r3, #13
 *   @0x235928 cmpne r3, #10
 *   @0x23592c beq 0x235948 <_ZN7IniFile6GetKeyEv+0x238>
 *   @0x235930 cmp r5, r3
 *   @0x235934 beq 0x235948 <_ZN7IniFile6GetKeyEv+0x238>
 *   @0x235938 cmp r6, r3
 *   @0x23593c beq 0x235948 <_ZN7IniFile6GetKeyEv+0x238>
 *   @0x235940 cmp r2, r12
 *   @0x235944 bne 0x235900 <_ZN7IniFile6GetKeyEv+0x1f0>
 *   @0x235948 eor r3, r8, #1
 *   @0x23594c cmp r0, #0
 *   @0x235950 movlt r3, #0
 *   @0x235954 andge r3, r3, #1
 *   @0x235958 cmp r3, #0
 *   @0x23595c beq 0x2359a4 <_ZN7IniFile6GetKeyEv+0x294>
 *   @0x235960 ldr r1, [pc, #0x120]
 *   @0x235964 rsb r5, lr, r0
 *   @0x235968 mov r3, #1
 *   @0x23596c add r0, r5, #1
 *   @0x235970 add r1, pc, r1
 *   @0x235974 movw r2, #0x16a
 *   @0x235978 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x23597c ldr r1, [r4, #0x10]
 *   @0x235980 mov r2, r5
 *   @0x235984 add r1, r1, r9
 *   @0x235988 str r0, [r7, #0x8]
 *   @0x23598c bl 0xb65bc <memcpy@plt>
 *   @0x235990 ldr r3, [r7, #0x8]
 *   @0x235994 mov r2, #0
 *   @0x235998 mov r0, r7
 *   @0x23599c strb r2, [r3, r5]
 *   @0x2359a0 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2359a4 rsb r2, lr, r2
 *   @0x2359a8 add r0, r2, #1
 *   @0x2359ac mov r10, r2
 *   @0x2359b0 ldr r1, [pc, #0xd4]
 *   @0x2359b4 mov r3, #1
 *   @0x2359b8 movw r2, #0x16a
 *   @0x2359bc add r1, pc, r1
 *   @0x2359c0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x2359c4 ldr r1, [r4, #0x10]
 *   @0x2359c8 mov r2, r10
 *   @0x2359cc add r1, r1, r9
 *   @0x2359d0 str r0, [r7, #0x8]
 *   @0x2359d4 bl 0xb65bc <memcpy@plt>
 *   @0x2359d8 ldr r3, [r7, #0x8]
 *   @0x2359dc cmp r8, #0
 *   @0x2359e0 mov r2, #0
 *   @0x2359e4 strb r2, [r3, r10]
 *   @0x2359e8 beq 0x235a04 <_ZN7IniFile6GetKeyEv+0x2f4>
 *   @0x2359ec ldr r3, [r4, #0x10]
 *   @0x2359f0 ldr r2, [r4, #0xc]
 *   @0x2359f4 add r0, r3, r2
 *   @0x2359f8 ldrb r1, [r3, r2]
 *   @0x2359fc cmp r1, r5
 *   @0x235a00 beq 0x235a40 <_ZN7IniFile6GetKeyEv+0x330>
 *   @0x235a04 mov r0, r7
 *   @0x235a08 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x235a0c mov r10, #0
 *   @0x235a10 mov r0, #1
 *   @0x235a14 b 0x2359b0 <_ZN7IniFile6GetKeyEv+0x2a0>
 *   @0x235a18 mov r5, r6
 *   @0x235a1c b 0x2357c8 <_ZN7IniFile6GetKeyEv+0xb8>
 *   @0x235a20 add r9, r9, #1
 *   @0x235a24 mov r6, #39
 *   @0x235a28 str r9, [r4, #0xc]
 *   @0x235a2c mov r5, r6
 *   @0x235a30 mov r8, #1
 *   @0x235a34 ldrb r3, [r1, r9]
 *   @0x235a38 mov lr, r9
 *   @0x235a3c b 0x2358c4 <_ZN7IniFile6GetKeyEv+0x1b4>
 *   @0x235a40 cmp r6, r5
 *   @0x235a44 bne 0x235a04 <_ZN7IniFile6GetKeyEv+0x2f4>
 *   @0x235a48 ldr r1, [r4, #0x4]
 *   @0x235a4c cmp r1, r2
 *   @0x235a50 ble 0x235a04 <_ZN7IniFile6GetKeyEv+0x2f4>
 *   @0x235a54 add r1, r3, r1
 *   @0x235a58 rsb r3, r3, #1
 *   @0x235a5c mov r2, r0
 *   @0x235a60 add r0, r3, r2
 *   @0x235a64 str r0, [r4, #0xc]
 *   @0x235a68 ldrb r0, [r2, #0x1]!
 *   @0x235a6c cmp r0, #13
 *   @0x235a70 cmpne r0, #10
 *   @0x235a74 beq 0x235a04 <_ZN7IniFile6GetKeyEv+0x2f4>
 *   @0x235a78 cmp r2, r1
 *   @0x235a7c beq 0x235a04 <_ZN7IniFile6GetKeyEv+0x2f4>
 *   @0x235a80 b 0x235a60 <_ZN7IniFile6GetKeyEv+0x350>
 *   @0x235a84 andseq pc, r1, r0, lsl #18
 *   @0x235a88 andseq pc, r1, r4, ror r7
 *   @0x235a8c andseq pc, r1, r8, lsr #14
 *
 * ══ §18/36 CCamera::Serialize(IBuffer*)  0x16e4f8  size 892  223 条（0x16e4f8..0x16e874）
 * @func 0x16e4f8 0x16e874  size 892  223 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SerializeMatrix(yyMatrix*, IBuffer*)×6 / CCamera::GetID()
 * 字段偏移 top8: 0x38×16 / 0x30×16 / 0x8×16 / 0x1a8×1 / 0x1ac×1 / 0x1b0×1 / 0x1b4×1 / 0x1b8×1
 * VFP 指令 64 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16e4f8 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x16e4fc mov r6, r1
 *   @0x16e500 mov r7, r0
 *   @0x16e504 bl 0x16d12c <_ZN7CCamera5GetIDEv>
 *   @0x16e508 ldr r3, [r6]
 *   @0x16e50c add r9, r6, #44
 *   @0x16e510 mov r8, #0
 *   @0x16e514 mov r1, #6
 *   @0x16e518 mov r2, r9
 *   @0x16e51c str r8, [r6, #0x38]
 *   @0x16e520 vmov s13, r0
 *   @0x16e524 mov r0, r6
 *   @0x16e528 vcvt.f64.s32 d6, s13
 *   @0x16e52c vmov r4, r5, d6
 *   @0x16e530 vstr s12, [r6, #44]
 *   @0x16e534 str r5, [r6, #0x30]
 *   @0x16e538 ldr r3, [r3, #0x8]
 *   @0x16e53c blx r3
 *   @0x16e540 add r0, r7, #4
 *   @0x16e544 mov r1, r6
 *   @0x16e548 bl 0x16e45c <_Z15SerializeMatrixP8yyMatrixP7IBuffer>
 *   @0x16e54c add r0, r7, #68
 *   @0x16e550 mov r1, r6
 *   @0x16e554 bl 0x16e45c <_Z15SerializeMatrixP8yyMatrixP7IBuffer>
 *   @0x16e558 add r0, r7, #132
 *   @0x16e55c mov r1, r6
 *   @0x16e560 bl 0x16e45c <_Z15SerializeMatrixP8yyMatrixP7IBuffer>
 *   @0x16e564 add r0, r7, #196
 *   @0x16e568 mov r1, r6
 *   @0x16e56c bl 0x16e45c <_Z15SerializeMatrixP8yyMatrixP7IBuffer>
 *   @0x16e570 add r0, r7, #260
 *   @0x16e574 mov r1, r6
 *   @0x16e578 bl 0x16e45c <_Z15SerializeMatrixP8yyMatrixP7IBuffer>
 *   @0x16e57c add r0, r7, #324
 *   @0x16e580 mov r1, r6
 *   @0x16e584 bl 0x16e45c <_Z15SerializeMatrixP8yyMatrixP7IBuffer>
 *   @0x16e588 vldr s15, [r7, #388]
 *   @0x16e58c vcvt.f64.f32 d6, s15
 *   @0x16e590 ldr r3, [r6]
 *   @0x16e594 mov r2, r9
 *   @0x16e598 str r8, [r6, #0x38]
 *   @0x16e59c mov r0, r6
 *   @0x16e5a0 mov r1, #8
 *   @0x16e5a4 vmov r4, r5, d6
 *   @0x16e5a8 vstr s12, [r6, #44]
 *   @0x16e5ac str r5, [r6, #0x30]
 *   @0x16e5b0 ldr r3, [r3, #0x8]
 *   @0x16e5b4 blx r3
 *   @0x16e5b8 vldr s15, [r7, #392]
 *   @0x16e5bc vcvt.f64.f32 d6, s15
 *   @0x16e5c0 ldr r3, [r6]
 *   @0x16e5c4 mov r2, r9
 *   @0x16e5c8 str r8, [r6, #0x38]
 *   @0x16e5cc mov r0, r6
 *   @0x16e5d0 mov r1, #8
 *   @0x16e5d4 vmov r4, r5, d6
 *   @0x16e5d8 vstr s12, [r6, #44]
 *   @0x16e5dc str r5, [r6, #0x30]
 *   @0x16e5e0 ldr r3, [r3, #0x8]
 *   @0x16e5e4 blx r3
 *   @0x16e5e8 vldr s15, [r7, #396]
 *   @0x16e5ec vcvt.f64.f32 d6, s15
 *   @0x16e5f0 ldr r3, [r6]
 *   @0x16e5f4 mov r2, r9
 *   @0x16e5f8 str r8, [r6, #0x38]
 *   @0x16e5fc mov r0, r6
 *   @0x16e600 mov r1, #8
 *   @0x16e604 vmov r4, r5, d6
 *   @0x16e608 vstr s12, [r6, #44]
 *   @0x16e60c str r5, [r6, #0x30]
 *   @0x16e610 ldr r3, [r3, #0x8]
 *   @0x16e614 blx r3
 *   @0x16e618 vldr s15, [r7, #400]
 *   @0x16e61c vcvt.f64.f32 d6, s15
 *   @0x16e620 ldr r3, [r6]
 *   @0x16e624 mov r2, r9
 *   @0x16e628 str r8, [r6, #0x38]
 *   @0x16e62c mov r0, r6
 *   @0x16e630 mov r1, #8
 *   @0x16e634 vmov r4, r5, d6
 *   @0x16e638 vstr s12, [r6, #44]
 *   @0x16e63c str r5, [r6, #0x30]
 *   @0x16e640 ldr r3, [r3, #0x8]
 *   @0x16e644 blx r3
 *   @0x16e648 vldr s15, [r7, #404]
 *   @0x16e64c vcvt.f64.f32 d6, s15
 *   @0x16e650 ldr r3, [r6]
 *   @0x16e654 mov r2, r9
 *   @0x16e658 str r8, [r6, #0x38]
 *   @0x16e65c mov r0, r6
 *   @0x16e660 mov r1, #8
 *   @0x16e664 vmov r4, r5, d6
 *   @0x16e668 vstr s12, [r6, #44]
 *   @0x16e66c str r5, [r6, #0x30]
 *   @0x16e670 ldr r3, [r3, #0x8]
 *   @0x16e674 blx r3
 *   @0x16e678 vldr s15, [r7, #408]
 *   @0x16e67c vcvt.f64.f32 d6, s15
 *   @0x16e680 ldr r3, [r6]
 *   @0x16e684 mov r2, r9
 *   @0x16e688 str r8, [r6, #0x38]
 *   @0x16e68c mov r0, r6
 *   @0x16e690 mov r1, #8
 *   @0x16e694 vmov r4, r5, d6
 *   @0x16e698 vstr s12, [r6, #44]
 *   @0x16e69c str r5, [r6, #0x30]
 *   @0x16e6a0 ldr r3, [r3, #0x8]
 *   @0x16e6a4 blx r3
 *   @0x16e6a8 vldr s15, [r7, #412]
 *   @0x16e6ac vcvt.f64.f32 d6, s15
 *   @0x16e6b0 ldr r3, [r6]
 *   @0x16e6b4 mov r2, r9
 *   @0x16e6b8 str r8, [r6, #0x38]
 *   @0x16e6bc mov r0, r6
 *   @0x16e6c0 mov r1, #8
 *   @0x16e6c4 vmov r4, r5, d6
 *   @0x16e6c8 vstr s12, [r6, #44]
 *   @0x16e6cc str r5, [r6, #0x30]
 *   @0x16e6d0 ldr r3, [r3, #0x8]
 *   @0x16e6d4 blx r3
 *   @0x16e6d8 vldr s15, [r7, #416]
 *   @0x16e6dc vcvt.f64.f32 d6, s15
 *   @0x16e6e0 ldr r3, [r6]
 *   @0x16e6e4 mov r2, r9
 *   @0x16e6e8 str r8, [r6, #0x38]
 *   @0x16e6ec mov r0, r6
 *   @0x16e6f0 mov r1, #8
 *   @0x16e6f4 vmov r4, r5, d6
 *   @0x16e6f8 vstr s12, [r6, #44]
 *   @0x16e6fc str r5, [r6, #0x30]
 *   @0x16e700 ldr r3, [r3, #0x8]
 *   @0x16e704 blx r3
 *   @0x16e708 vldr s15, [r7, #420]
 *   @0x16e70c vcvt.f64.f32 d6, s15
 *   @0x16e710 ldr r3, [r6]
 *   @0x16e714 mov r2, r9
 *   @0x16e718 str r8, [r6, #0x38]
 *   @0x16e71c mov r0, r6
 *   @0x16e720 mov r1, #8
 *   @0x16e724 vmov r4, r5, d6
 *   @0x16e728 vstr s12, [r6, #44]
 *   @0x16e72c str r5, [r6, #0x30]
 *   @0x16e730 ldr r3, [r3, #0x8]
 *   @0x16e734 blx r3
 *   @0x16e738 ldr r4, [r7, #0x1a8]
 *   @0x16e73c ldr r3, [r6]
 *   @0x16e740 mov r2, r9
 *   @0x16e744 str r8, [r6, #0x38]
 *   @0x16e748 mov r0, r6
 *   @0x16e74c vmov s15, r4
 *   @0x16e750 mov r1, #6
 *   @0x16e754 vcvt.f64.s32 d7, s15
 *   @0x16e758 vmov r4, r5, d7
 *   @0x16e75c vstr s14, [r6, #44]
 *   @0x16e760 str r5, [r6, #0x30]
 *   @0x16e764 ldr r3, [r3, #0x8]
 *   @0x16e768 blx r3
 *   @0x16e76c ldr r4, [r7, #0x1ac]
 *   @0x16e770 ldr r3, [r6]
 *   @0x16e774 mov r2, r9
 *   @0x16e778 str r8, [r6, #0x38]
 *   @0x16e77c mov r0, r6
 *   @0x16e780 vmov s13, r4
 *   @0x16e784 mov r1, #6
 *   @0x16e788 vcvt.f64.s32 d6, s13
 *   @0x16e78c vmov r4, r5, d6
 *   @0x16e790 vstr s12, [r6, #44]
 *   @0x16e794 str r5, [r6, #0x30]
 *   @0x16e798 ldr r3, [r3, #0x8]
 *   @0x16e79c blx r3
 *   @0x16e7a0 ldr r4, [r7, #0x1b0]
 *   @0x16e7a4 ldr r3, [r6]
 *   @0x16e7a8 mov r2, r9
 *   @0x16e7ac str r8, [r6, #0x38]
 *   @0x16e7b0 mov r0, r6
 *   @0x16e7b4 vmov s15, r4
 *   @0x16e7b8 mov r1, #6
 *   @0x16e7bc vcvt.f64.s32 d7, s15
 *   @0x16e7c0 vmov r4, r5, d7
 *   @0x16e7c4 vstr s14, [r6, #44]
 *   @0x16e7c8 str r5, [r6, #0x30]
 *   @0x16e7cc ldr r3, [r3, #0x8]
 *   @0x16e7d0 blx r3
 *   @0x16e7d4 ldr r4, [r7, #0x1b4]
 *   @0x16e7d8 ldr r3, [r6]
 *   @0x16e7dc mov r2, r9
 *   @0x16e7e0 str r8, [r6, #0x38]
 *   @0x16e7e4 mov r0, r6
 *   @0x16e7e8 vmov s13, r4
 *   @0x16e7ec mov r1, #6
 *   @0x16e7f0 vcvt.f64.s32 d6, s13
 *   @0x16e7f4 vmov r4, r5, d6
 *   @0x16e7f8 vstr s12, [r6, #44]
 *   @0x16e7fc str r5, [r6, #0x30]
 *   @0x16e800 ldr r3, [r3, #0x8]
 *   @0x16e804 blx r3
 *   @0x16e808 ldrb r4, [r7, #0x1b8]
 *   @0x16e80c ldr r3, [r6]
 *   @0x16e810 mov r2, r9
 *   @0x16e814 str r8, [r6, #0x38]
 *   @0x16e818 mov r0, r6
 *   @0x16e81c vmov s15, r4
 *   @0x16e820 mov r1, #6
 *   @0x16e824 vcvt.f64.u32 d7, s15
 *   @0x16e828 vmov r4, r5, d7
 *   @0x16e82c vstr s14, [r6, #44]
 *   @0x16e830 str r5, [r6, #0x30]
 *   @0x16e834 ldr r3, [r3, #0x8]
 *   @0x16e838 blx r3
 *   @0x16e83c ldrb r4, [r7, #0x1b9]
 *   @0x16e840 ldr r3, [r6]
 *   @0x16e844 mov r2, r9
 *   @0x16e848 str r8, [r6, #0x38]
 *   @0x16e84c mov r0, r6
 *   @0x16e850 vmov s13, r4
 *   @0x16e854 mov r1, #6
 *   @0x16e858 vcvt.f64.u32 d6, s13
 *   @0x16e85c vmov r4, r5, d6
 *   @0x16e860 vstr s12, [r6, #44]
 *   @0x16e864 str r5, [r6, #0x30]
 *   @0x16e868 ldr r3, [r3, #0x8]
 *   @0x16e86c blx r3
 *   @0x16e870 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §19/36 loadTexture(Texture*)  0x1895ec  size 892  223 条（0x1895ec..0x189968）
 * @func 0x1895ec 0x189968  size 892  223 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1898c4→0x3eb70c, 0x18990c→0x3eb70c
 * 调用序列: png_destroy_read_struct×4 / png_create_info_struct×2 / operator new[](unsigned int)×2 / operator delete[](void*)×2 / _InvalidateTextureState() / png_sig_cmp / png_create_read_struct / png_set_longjmp_fn
 * 字段偏移 top8: 0x24×16 / 0x28×8 / 0x18×7 / 0x3c×5 / 0x1c×4 / 0x2c×3 / 0x34×3 / 0xc×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1895ec push {r4, r5, r6, lr}
 *   @0x1895f0 sub sp, sp, #72
 *   @0x1895f4 str r0, [sp, #0x18]
 *   @0x1895f8 bl 0x182598 <_Z23_InvalidateTextureStatev>
 *   @0x1895fc ldr r1, [sp, #0x18]
 *   @0x189600 mov r2, #8
 *   @0x189604 ldr r3, [pc, #0x340]
 *   @0x189608 ldr r0, [r1, #0x2c]
 *   @0x18960c mov r1, #0
 *   @0x189610 add r3, pc, r3
 *   @0x189614 str r3, [sp, #0x1c]
 *   @0x189618 blx 0x2a5a4c <png_sig_cmp>
 *   @0x18961c subs r1, r0, #0
 *   @0x189620 bne 0x189908 <_Z11loadTextureP7Texture+0x31c>
 *   @0x189624 ldr r0, [pc, #0x324]
 *   @0x189628 mov r2, r1
 *   @0x18962c mov r3, r1
 *   @0x189630 add r0, pc, r0
 *   @0x189634 blx 0x2a6fdc <png_create_read_struct>
 *   @0x189638 cmp r0, #0
 *   @0x18963c str r0, [sp, #0x24]
 *   @0x189640 beq 0x1898c4 <_Z11loadTextureP7Texture+0x2d8>
 *   @0x189644 blx 0x2a5b64 <png_create_info_struct>
 *   @0x189648 cmp r0, #0
 *   @0x18964c str r0, [sp, #0x28]
 *   @0x189650 beq 0x189938 <_Z11loadTextureP7Texture+0x34c>
 *   @0x189654 ldr r0, [sp, #0x24]
 *   @0x189658 blx 0x2a5b64 <png_create_info_struct>
 *   @0x18965c cmp r0, #0
 *   @0x189660 str r0, [sp, #0x2c]
 *   @0x189664 beq 0x1898b4 <_Z11loadTextureP7Texture+0x2c8>
 *   @0x189668 ldr r3, [pc, #0x2e4]
 *   @0x18966c mov r2, #256
 *   @0x189670 ldr r12, [sp, #0x1c]
 *   @0x189674 ldr r0, [sp, #0x24]
 *   @0x189678 ldr r1, [r12, r3]
 *   @0x18967c blx 0x2a653c <png_set_longjmp_fn>
 *   @0x189680 bl 0xb6904 <setjmp@plt>
 *   @0x189684 subs r4, r0, #0
 *   @0x189688 bne 0x1898f4 <_Z11loadTextureP7Texture+0x308>
 *   @0x18968c ldr r1, [sp, #0x18]
 *   @0x189690 ldr r12, [sp, #0x18]
 *   @0x189694 ldr r2, [pc, #0x2bc]
 *   @0x189698 ldr r3, [r1, #0x2c]
 *   @0x18969c add r1, sp, #64
 *   @0x1896a0 add r2, pc, r2
 *   @0x1896a4 ldr r0, [sp, #0x24]
 *   @0x1896a8 add r3, r3, #8
 *   @0x1896ac str r12, [sp, #0x40]
 *   @0x1896b0 str r3, [sp, #0x44]
 *   @0x1896b4 blx 0x2a804c <png_set_read_fn>
 *   @0x1896b8 ldr r0, [sp, #0x24]
 *   @0x1896bc mov r1, #8
 *   @0x1896c0 blx 0x2a5a24 <png_set_sig_bytes>
 *   @0x1896c4 ldr r0, [sp, #0x24]
 *   @0x1896c8 ldr r1, [sp, #0x28]
 *   @0x1896cc blx 0x2a6ff0 <png_read_info>
 *   @0x1896d0 ldr r1, [sp, #0x28]
 *   @0x1896d4 ldr r0, [sp, #0x24]
 *   @0x1896d8 blx 0x2a65a6 <png_get_bit_depth>
 *   @0x1896dc ldr r1, [sp, #0x28]
 *   @0x1896e0 str r0, [sp, #0x30]
 *   @0x1896e4 ldr r0, [sp, #0x24]
 *   @0x1896e8 blx 0x2a65b2 <png_get_color_type>
 *   @0x1896ec cmp r0, #3
 *   @0x1896f0 str r0, [sp, #0x34]
 *   @0x1896f4 movne r3, r0
 *   @0x1896f8 beq 0x189870 <_Z11loadTextureP7Texture+0x284>
 *   @0x1896fc bics r1, r3, #2
 *   @0x189700 beq 0x189848 <_Z11loadTextureP7Texture+0x25c>
 *   @0x189704 eor r4, r4, #1
 *   @0x189708 cmp r3, #3
 *   @0x18970c movne r4, #0
 *   @0x189710 andeq r4, r4, #1
 *   @0x189714 cmp r4, #0
 *   @0x189718 bne 0x189848 <_Z11loadTextureP7Texture+0x25c>
 *   @0x18971c bics r2, r3, #4
 *   @0x189720 beq 0x189864 <_Z11loadTextureP7Texture+0x278>
 *   @0x189724 ldr r1, [sp, #0x28]
 *   @0x189728 add r3, sp, #48
 *   @0x18972c add r2, sp, #52
 *   @0x189730 str r3, [sp]
 *   @0x189734 ldr r0, [sp, #0x24]
 *   @0x189738 mov r3, #0
 *   @0x18973c stmib sp, {r2, r3}
 *   @0x189740 add r2, sp, #56
 *   @0x189744 str r3, [sp, #0xc]
 *   @0x189748 str r3, [sp, #0x10]
 *   @0x18974c add r3, sp, #60
 *   @0x189750 blx 0x2a693e <png_get_IHDR>
 *   @0x189754 add r1, sp, #52
 *   @0x189758 ldr r12, [sp, #0x18]
 *   @0x18975c ldm r1, {r1, r2, r3}
 *   @0x189760 cmp r1, #3
 *   @0x189764 stmib r12, {r2, r3}
 *   @0x189768 beq 0x1898a8 <_Z11loadTextureP7Texture+0x2bc>
 *   @0x18976c ldr r0, [sp, #0x24]
 *   @0x189770 ldr r1, [sp, #0x28]
 *   @0x189774 blx 0x2a7448 <png_read_update_info>
 *   @0x189778 ldr r1, [sp, #0x28]
 *   @0x18977c ldr r0, [sp, #0x24]
 *   @0x189780 blx 0x2a6574 <png_get_rowbytes>
 *   @0x189784 mov r4, r0
 *   @0x189788 ldr r0, [sp, #0x3c]
 *   @0x18978c mul r0, r0, r4
 *   @0x189790 bl 0x27d14c <_Znaj>
 *   @0x189794 subs r6, r0, #0
 *   @0x189798 beq 0x1898f4 <_Z11loadTextureP7Texture+0x308>
 *   @0x18979c ldr r0, [sp, #0x3c]
 *   @0x1897a0 cmp r0, #532676608
 *   @0x1897a4 lslls r0, r0, #2
 *   @0x1897a8 mvnhi r0, #0
 *   @0x1897ac bl 0x27d14c <_Znaj>
 *   @0x1897b0 subs r5, r0, #0
 *   @0x1897b4 beq 0x1898f4 <_Z11loadTextureP7Texture+0x308>
 *   @0x1897b8 ldr r12, [sp, #0x3c]
 *   @0x1897bc cmp r12, #0
 *   @0x1897c0 addne r12, r5, r12, lsl #2
 *   @0x1897c4 movne r2, r6
 *   @0x1897c8 movne r3, r5
 *   @0x1897cc beq 0x1897e0 <_Z11loadTextureP7Texture+0x1f4>
 *   @0x1897d0 str r2, [r3], #4
 *   @0x1897d4 cmp r3, r12
 *   @0x1897d8 add r2, r2, r4
 *   @0x1897dc bne 0x1897d0 <_Z11loadTextureP7Texture+0x1e4>
 *   @0x1897e0 ldr r0, [sp, #0x24]
 *   @0x1897e4 mov r1, r5
 *   @0x1897e8 blx 0x2a7840 <png_read_image>
 *   @0x1897ec ldr r12, [sp, #0x30]
 *   @0x1897f0 ldr r3, [sp, #0x3c]
 *   @0x1897f4 mov r1, #6
 *   @0x1897f8 ldr r2, [sp, #0x38]
 *   @0x1897fc str r12, [sp, #0x4]
 *   @0x189800 ldr r0, [sp, #0x18]
 *   @0x189804 str r4, [sp]
 *   @0x189808 str r6, [sp, #0x8]
 *   @0x18980c bl 0x181cdc <_Z15_PNG_setTextureP7TextureiiiiiPh>
 *   @0x189810 add r1, sp, #40
 *   @0x189814 add r2, sp, #44
 *   @0x189818 add r0, sp, #36
 *   @0x18981c blx 0x2a7e2c <png_destroy_read_struct>
 *   @0x189820 mov r0, r6
 *   @0x189824 bl 0x27d1d4 <_ZdaPv>
 *   @0x189828 mov r0, r5
 *   @0x18982c bl 0x27d1d4 <_ZdaPv>
 *   @0x189830 ldr r1, [sp, #0x18]
 *   @0x189834 mov r3, #6
 *   @0x189838 ldr r0, [r1, #0x14]
 *   @0x18983c str r3, [r1]
 *   @0x189840 add sp, sp, #72
 *   @0x189844 pop {r4, r5, r6, pc}
 *   @0x189848 mov r2, #1
 *   @0x18984c ldr r0, [sp, #0x24]
 *   @0x189850 mov r1, #255
 *   @0x189854 blx 0x2af812 <png_set_add_alpha>
 *   @0x189858 ldr r3, [sp, #0x34]
 *   @0x18985c bics r2, r3, #4
 *   @0x189860 bne 0x189724 <_Z11loadTextureP7Texture+0x138>
 *   @0x189864 ldr r0, [sp, #0x24]
 *   @0x189868 blx 0x2a880a <png_set_gray_to_rgb>
 *   @0x18986c b 0x189724 <_Z11loadTextureP7Texture+0x138>
 *   @0x189870 mov r2, r4
 *   @0x189874 str r4, [sp]
 *   @0x189878 ldr r0, [sp, #0x24]
 *   @0x18987c add r3, sp, #60
 *   @0x189880 ldr r1, [sp, #0x28]
 *   @0x189884 blx 0x2a6b56 <png_get_tRNS>
 *   @0x189888 cmp r0, #0
 *   @0x18988c moveq r4, r0
 *   @0x189890 beq 0x1898a0 <_Z11loadTextureP7Texture+0x2b4>
 *   @0x189894 ldr r4, [sp, #0x3c]
 *   @0x189898 adds r4, r4, #0
 *   @0x18989c movne r4, #1
 *   @0x1898a0 ldr r3, [sp, #0x34]
 *   @0x1898a4 b 0x1896fc <_Z11loadTextureP7Texture+0x110>
 *   @0x1898a8 ldr r0, [sp, #0x24]
 *   @0x1898ac blx 0x2a87b0 <png_set_palette_to_rgb>
 *   @0x1898b0 b 0x18976c <_Z11loadTextureP7Texture+0x180>
 *   @0x1898b4 mov r2, r0
 *   @0x1898b8 add r1, sp, #40
 *   @0x1898bc add r0, sp, #36
 *   @0x1898c0 blx 0x2a7e2c <png_destroy_read_struct>
 *   @0x1898c4 ldr r3, [pc, #0x90]
 *   @0x1898c8 ldr r2, [sp, #0x1c]
 *   @0x1898cc ldr r3, [r2, r3]
 *   @0x1898d0 ldr r0, [r3]
 *   @0x1898d4 ldr r3, [r0]
 *   @0x1898d8 ldr r1, [pc, #0x80]
 *   @0x1898dc ldr r3, [r3, #0xc]
 *   @0x1898e0 add r1, pc, r1
 *   @0x1898e4 blx r3
 *   @0x1898e8 mvn r0, #0
 *   @0x1898ec add sp, sp, #72
 *   @0x1898f0 pop {r4, r5, r6, pc}
 *   @0x1898f4 add r0, sp, #36
 *   @0x1898f8 add r1, sp, #40
 *   @0x1898fc add r2, sp, #44
 *   @0x189900 blx 0x2a7e2c <png_destroy_read_struct>
 *   @0x189904 b 0x1898c4 <_Z11loadTextureP7Texture+0x2d8>
 *   @0x189908 ldr r12, [sp, #0x1c]
 *   @0x18990c ldr r3, [pc, #0x48]
 *   @0x189910 ldr r1, [pc, #0x4c]
 *   @0x189914 ldr r3, [r12, r3]
 *   @0x189918 add r1, pc, r1
 *   @0x18991c ldr r4, [r3]
 *   @0x189920 ldr r3, [r4]
 *   @0x189924 mov r0, r4
 *   @0x189928 ldr r3, [r3, #0xc]
 *   @0x18992c blx r3
 *   @0x189930 mov r0, r4
 *   @0x189934 b 0x1898d4 <_Z11loadTextureP7Texture+0x2e8>
 *   @0x189938 mov r1, r0
 *   @0x18993c add r0, sp, #36
 *   @0x189940 mov r2, r1
 *   @0x189944 blx 0x2a7e2c <png_destroy_read_struct>
 *   @0x189948 b 0x1898c4 <_Z11loadTextureP7Texture+0x2d8>
 *   @0x18994c eoreq r8, r6, r0, asr #12
 *   @0x189950 andseq r1, r12, r12
 *   @0x189954 .word 0xffffe4ac
 *   @0x189958 .word 0xfffffb2c
 *   @0x18995c .word 0xffffbac4
 *   @0x189960 ldrsheq r2, [r12], -r8
 *   @0x189964 ldrheq r2, [r12], -r4
 *
 * ══ §20/36 anon_2a4a60  0x2a4a60  size 892  223 条（0x2a4a60..0x2a4ddc）
 * @func 0x2a4a60 0x2a4ddc  size 892  223 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_30a7b2+0x670a / anon_2bec94+0x28 / 0x847508 / 0x398b04 / 0x33ed84 / 0x42eb24 / 0x47d1c0 / 0x375c10
 * 字段偏移 top8: 0x1e×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a4a60 .word 0x4604b51f
 *   @0x2a4a64 .word 0xb1699201
 *   @0x2a4a68 bge 0x376290 <_ZTS13C_UTF16String+0xd33c>
 *   @0x2a4a6c .word 0xf7ffa901
 *   @0x2a4a70 stmdals r1, {r1, r2, r3, r4, r6, r10, r11, r12, sp, lr, pc}
 *   @0x2a4a74 ldc2l p7, c15, [r4], #-1020
 *   @0x2a4a78 mrsle r2, apsr
 *   @0x2a4a7c ldm r12!, {r1, r4, r9, r10, r12, sp, lr, pc}
 *   @0x2a4a80 andvs r9, r3, r3, lsl #22
 *   @0x2a4a84 blls 0x310ebc <af_shaper_get_elem+0x672a>
 *   @0x2a4a88 andlt r6, r4, r3, lsr #32
 *   @0x2a4a8c andeq r11, r0, r0, lsl sp
 *   @0x2a4a90 ldrblt r4, [r0, #0xb2b]!
 *   @0x2a4a94 ldmdavs r11, {r0, r1, r3, r4, r5, r6, r10, lr}
 *   @0x2a4a98 strmi r11, [r4], -r9, lsl #1
 *   @0x2a4a9c sadd16mi r6, pc, r10
 *   @0x2a4aa0 stmdavs r2, {r0, r1, r2, r9, r12, pc} ^
 *   @0x2a4aa4 suble r2, r2, r0, lsl #20
 *   @0x2a4aa8 blhs 0x2becbc <jpeg_huff_decode+0x130>
 *   @0x2a4aac bvs 0x358bb0
 *   @0x2a4ab0 eorsle r2, r12, r0, lsl #20
 *   @0x2a4ab4 blhs 0x847508 <b2_toiTime+0xee064>
 *   @0x2a4ab8 ldmdbvs r6, {r0, r3, r4, r5, r8, r12, lr, pc}
 *   @0x2a4abc stmdbmi r1!, {r1, r2, r3, r9, sp}
 *   @0x2a4ac0 ldrbtmi r4, [r9], #-1584
 *   @0x2a4ac4 stc p6, c15, [r12, #68]
 *   @0x2a4ac8 stmdahs r0, {r0, r2, r9, r10, lr}
 *   @0x2a4acc ldrtmi sp, [r2], -pc, lsr #2
 *   @0x2a4ad0 .word 0xf852ae04
 *   @0x2a4ad4 ldrtmi r0, [r3], -lr, lsl #30
 *   @0x2a4ad8 movwgt r6, #0x3851
 *   @0x2a4adc andspl pc, r8, sp, lsl #17
 *   @0x2a4ae0 stm r10, {r1, r4, r9, r10, r12, sp, lr, pc}
 *   @0x2a4ae4 andshs r10, r0, #49152
 *   @0x2a4ae8 ldrtmi r6, [r0], -r5
 *   @0x2a4aec svc #0x46f611
 *   @0x2a4af0 strmi r1, [r5], -r3, asr #24
 *   @0x2a4af4 blls 0x398b04 <ft_adobe_glyph_list+0x81e0>
 *   @0x2a4af8 and r11, r6, r11, lsr #18
 *   @0x2a4afc ldmda r12!, {r1, r4, r9, r10, r12, sp, lr, pc} ^
 *   @0x2a4b00 stmiblt r3!, {r0, r1, r11, sp, lr}
 *   @0x2a4b04 ldmdavc r11, {r0, r1, r2, r4, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x2a4b08 bvs 0xb9313c <b2_toiTime+0x439c98>
 *   @0x2a4b0c stmdavs r0!, {r9, sp} ^
 *   @0x2a4b10 ldmvs r9, {r9, r12, pc} ^
 *   @0x2a4b14 blge 0x33ed84
 *   @0x2a4b18 stc2l p7, c15, [lr], #-1020
 *   @0x2a4b1c blle 0x42eb24 <g_RomDisk+0x37304>
 *   @0x2a4b20 adcmi r9, r11, #2048
 *   @0x2a4b24 stmibvs r3!, {r0, r1, r8, r12, lr, pc}
 *   @0x2a4b28 movweq pc, #0x1043
 *   @0x2a4b2c bls 0x47d1c0 <targetStr+0x1f80>
 *   @0x2a4b30 addsmi r6, r10, #3866624
 *   @0x2a4b34 .word 0xf611d001
 *   @0x2a4b38 andlt lr, r9, lr, asr #26
 *   @0x2a4b3c svclt #0xbdf0
 *   @0x2a4b40 andseq r8, r4, r0, asr #29
 *   @0x2a4b44 andeq r7, lr, r11, asr #10
 *   @0x2a4b48 ldrblt r2, [r8, #0x903]!
 *   @0x2a4b4c strmi r4, [sp], -r6, lsl #12
 *   @0x2a4b50 svcmi #0xcdd14
 *   @0x2a4b54 ldrbtmi r1, [pc], #-3652
 *   @0x2a4b58 stclne p7, c3, [r0], #-4
 *   @0x2a4b5c bne 0xf2d0a4 <b2_toiTime+0x7d3c00>
 *   @0x2a4b60 blo 0x375c10 <_ZTS13C_UTF16String+0xccbc>
 *   @0x2a4b64 ldc p6, c15, [r12, #68]
 *   @0x2a4b68 .word 0xb1484604
 *   @0x2a4b6c ldrtmi r1, [r9], -r0, ror #24
 *   @0x2a4b70 .word 0xf6122203
 *   @0x2a4b74 stmdahs r0, {r1, r2, r5, r6, r11, sp, lr, pc}
 *   @0x2a4b78 and sp, r1, pc, ror #3
 *   @0x2a4b7c ldcllt p0, c2, [r8, #0]!
 *   @0x2a4b80 ldcllt p6, c4, [r8, #128]!
 *   @0x2a4b84 strheq r7, [lr], -r2
 *   @0x2a4b88 .word 0x4605b538
 *   @0x2a4b8c strmi r6, [r12], -r0, lsl #19
 *   @0x2a4b90 stmibvs r9, {r8, r9, r12, sp, pc}
 *   @0x2a4b94 .word 0xf611b1f1
 *   @0x2a4b98 ldmiblt r8, {r1, r2, r3, r5, r6, r7, r10, r11, sp, lr, pc} ^
 *   @0x2a4b9c .word 0xf01388a3
 *   @0x2a4ba0 stmvs r3!, {r3, r8, r9, r10, r11} ^
 *   @0x2a4ba4 stmiblt r11!, {r3, r12, lr, pc}
 *   @0x2a4ba8 ldmiblt r11, {r0, r1, r5, r8, r11, sp, lr}
 *   @0x2a4bac stmdalo r0, {r5, r6, r8, r11, sp, lr}
 *   @0x2a4bb0 .word 0xf06fbf18
 *   @0x2a4bb4 ldclt p0, c0, [r8, #-0]!
 *   @0x2a4bb8 addsmi r6, r10, #15335424
 *   @0x2a4bbc stmdbvs r10!, {r1, r3, r8, r12, lr, pc}
 *   @0x2a4bc0 addsmi r6, r10, #573440
 *   @0x2a4bc4 stmdbvs r8!, {r1, r2, r8, r12, lr, pc} ^
 *   @0x2a4bc8 bne 0xff2bf15c <b2_toiTime+0xfffffffffeb65cb8>
 *   @0x2a4bcc .word 0xf06fbf18
 *   @0x2a4bd0 ldclt p0, c0, [r8, #-0]!
 *   @0x2a4bd4 rscslo pc, pc, pc, asr #32
 *   @0x2a4bd8 push {r3, r4, r5, r8, r10, r11, r12, sp, pc}
 *   @0x2a4bdc .word 0x46814ff0
 *   @0x2a4be0 addslt r6, r5, r12, asr #16
 *   @0x2a4be4 ldrmi r4, [r2], sp, lsl #12
 *   @0x2a4be8 stmdavs r11, {r2, r3, r8, r12, sp, pc}
 *   @0x2a4bec .word 0xf10d6b9c
 *   @0x2a4bf0 qadd16mi r0, r6, r4
 *   @0x2a4bf4 .word 0xf04f2700
 *   @0x2a4bf8 stmdavs r11!, {r2, r3, r4, r5, r8, r9, r11} ^
 *   @0x2a4bfc ble 0x18b5680 <b2_toiTime+0x115c1dc>
 *   @0x2a4c00 .word 0xfc07fb0b
 *   @0x2a4c04 stmvs r9!, {r0, r1, r3, r5, r11, sp, lr} ^
 *   @0x2a4c08 blvs 0xfe935d9c <b2_toiTime+0xfffffffffe1dc8f8>
 *   @0x2a4c0c svclt #0x284294
 *   @0x2a4c10 addmi r4, r12, #20, #12
 *   @0x2a4c14 ldrbmi sp, [r0], -r5, lsl #18
 *   @0x2a4c18 andhs r2, r0, #-1073741820
 *   @0x2a4c1c blx 0xfe9e2c22 <b2_toiTime+0xfffffffffe28977e>
 *   @0x2a4c20 ldmdbvs r8, {r0, r1, r2, r3, r4, r5, sp, lr, pc}
 *   @0x2a4c24 ldrmi r8, [r0], #-2971
 *   @0x2a4c28 ldrmi r3, [r8], #-30
 *   @0x2a4c2c svclt #0x384286
 *   @0x2a4c30 addmi r4, lr, #6291456
 *   @0x2a4c34 .word 0xf8d9d8ef
 *   @0x2a4c38 .word 0x21003000
 *   @0x2a4c3c ldmdbvs r11, {r3, r6, r9, r10, lr}
 *   @0x2a4c40 andgt pc, r12, sp, asr #17
 *   @0x2a4c44 andhs r4, r0, #152, #14
 *   @0x2a4c48 strbmi r2, [r0], -r1, lsl #6
 *   @0x2a4c4c streq lr, [r8], #-2189
 *   @0x2a4c50 ldrmi r4, [r3], -r9, asr #12
 *   @0x2a4c54 blx 0x18e2c58 <b2_toiTime+0x11897b4>
 *   @0x2a4c58 .word 0xc00cf8dd
 *   @0x2a4c5c eorle r1, r9, r3, asr #24
 *   @0x2a4c60 rfeia sp!
 *   @0x2a4c64 strbtmi r3, [r0], #-22
 *   @0x2a4c68 addsmi r8, r10, #4325376
 *   @0x2a4c6c stmhi r2, {r0, r4, r8, r12, lr, pc} ^
 *   @0x2a4c70 ldrhlo pc, [r10], -sp
 *   @0x2a4c74 swple r4, r10, [r12]
 *   @0x2a4c78 blls 0x47ee88 <targetStr+0x3c48>
 *   @0x2a4c7c swple r4, r10, [r8]
 *   @0x2a4c80 rfeia sp!
 *   @0x2a4c84 addsmi r3, r10, #48
 *   @0x2a4c88 strbmi sp, [r1], -r3, lsl #2
 *   @0x2a4c8c .word 0xff7cf7ff
 *   @0x2a4c90 usaxmi r11, r0, r0
 *   @0x2a4c94 andhs r2, r0, #1073741829
 *   @0x2a4c98 blx 0x1a62c9e <b2_toiTime+0x13097fa>
 *   @0x2a4c9c .word 0xf7fe4640
 *   @0x2a4ca0 .word 0xf04fff9a
 *   @0x2a4ca4 strd r3, r4, [r5], -pc
 *   @0x2a4ca8 strlo r4, [r1, -r0, asr #12]
 *   @0x2a4cac .word 0xff93f7fe
 *   @0x2a4cb0 blne 0xedeb44 <b2_toiTime+0x7856a0>
 *   @0x2a4cb4 pop {r0, r2, r4, r12, sp, pc}
 *   @0x2a4cb8 ldrblt r8, [r0, #0xff0]!
 *   @0x2a4cbc cdpge p0, #0x0, c11, c1, c5, #0x4
 *   @0x2a4cc0 strmi r4, [sp], -r7, lsl #12
 *   @0x2a4cc4 .word 0xf0004630
 *   @0x2a4cc8 .word 0x4604fe5a
 *   @0x2a4ccc qasxmi r11, r8, r0
 *   @0x2a4cd0 qasxmi r4, r2, r1
 *   @0x2a4cd4 mcr2 p7, #0x6, pc, c4, c15, #0x7
 *   @0x2a4cd8 and r4, lr, r0, lsr #12
 *   @0x2a4cdc .word 0xf6114638
 *   @0x2a4ce0 .word 0x4606ecb0
 *   @0x2a4ce4 strtmi r6, [r0], -r0, lsr #32
 *   @0x2a4ce8 .word 0xf7ffb93e
 *   @0x2a4cec tstlt sp, r11, asr #27
 *   @0x2a4cf0 ldrtmi r2, [r0], -lr, lsl #6
 *   @0x2a4cf4 and r6, r0, r11, lsr #32
 *   @0x2a4cf8 andlt r4, r5, r8, lsr #12
 *   @0x2a4cfc push {r4, r5, r6, r7, r8, r10, r11, r12, sp, pc}
 *   @0x2a4d00 .word 0x46814ff0
 *   @0x2a4d04 addslt r6, r3, r12, asr #16
 *   @0x2a4d08 ldrmi r4, [r7], -r11, lsl #13
 *   @0x2a4d0c stmdavs r11, {r2, r3, r8, r12, sp, pc}
 *   @0x2a4d10 .word 0xf10d6b9c
 *   @0x2a4d14 strtmi r0, [r5], -r12, lsl #16
 *   @0x2a4d18 .word 0xf8db2600
 *   @0x2a4d1c addsmi r3, lr, #4
 *   @0x2a4d20 teqhs r12, #368640
 *   @0x2a4d24 .word 0x200cf8db
 *   @0x2a4d28 blx 0x46393c <g_RomDisk+0x6c11c>
 *   @0x2a4d2c .word 0x3000f8db
 *   @0x2a4d30 blvs 0xfe8f5e84 <b2_toiTime+0xfffffffffe19c9e0>
 *   @0x2a4d34 svclt #0x28428c
 *   @0x2a4d38 addsmi r4, r4, #12, #12
 *   @0x2a4d3c ldrtmi sp, [r8], -r2, lsl #18
 *   @0x2a4d40 ands r2, r1, r3, lsl r1
 *   @0x2a4d44 blhi 0xfe97f1ac <b2_toiTime+0xfffffffffe225d08>
 *   @0x2a4d48 andslo r4, lr, r8, lsl #8
 *   @0x2a4d4c addmi r4, r5, #24, #8
 *   @0x2a4d50 .word 0x4605bf38
 *   @0x2a4d54 ldmle r2!, {r0, r2, r4, r7, r9, lr} ^
 *   @0x2a4d58 strbmi r2, [r8], -r0, lsl #4
 *   @0x2a4d5c ldm r10!, {r1, r4, r9, r10, r12, sp, lr, pc}
 *   @0x2a4d60 .word 0xb1284602
 *   @0x2a4d64 .word 0x21044638
 *   @0x2a4d68 .word 0xf7ff2200
 *   @0x2a4d6c .word 0xe02bfaf5
 *   @0x2a4d70 strbmi r2, [r0], -r1, lsl #6
 *   @0x2a4d74 addeq lr, r8, sp, lsl #17
 *   @0x2a4d78 ldrmi r4, [r3], -r9, asr #12
 *   @0x2a4d7c rfeia r8!
 *   @0x2a4d80 eorle r1, r10, r3, asr #24
 *   @0x2a4d84 .word 0x0000f8db
 *   @0x2a4d88 strhlo pc, [lr], -sp
 *   @0x2a4d8c stmdahi r2, {r4, r6, r10, lr} ^
 *   @0x2a4d90 .word 0xd111429a
 *   @0x2a4d94 rfeia sp!
 *   @0x2a4d98 addsmi r3, r10, #18
 *   @0x2a4d9c stmvs r2, {r2, r3, r8, r12, lr, pc}
 *   @0x2a4da0 addsmi r9, r10, #5120
 *   @0x2a4da4 blhi 0xfe3591cc <b2_toiTime+0xfffffffffdbffd28>
 *   @0x2a4da8 .word 0x3028f8bd
 *   @0x2a4dac swple r4, r10, [r3]
 *   @0x2a4db0 .word 0xf7ff4641
 *   @0x2a4db4 cmplt r0, r9, ror #29
 *   @0x2a4db8 tsths r5, r8, lsr r6
 *   @0x2a4dbc .word 0xf7ff2200
 *   @0x2a4dc0 strbmi pc, [r0], -r11, asr #21
 *   @0x2a4dc4 .word 0xff07f7fe
 *   @0x2a4dc8 rscslo pc, pc, pc, asr #32
 *   @0x2a4dcc strbmi lr, [r0], -r5
 *   @0x2a4dd0 .word 0xf7fe3601
 *   @0x2a4dd4 str pc, [r0, r0, lsl #30]!
 *   @0x2a4dd8 andslt r1, r3, r8, lsr #22
 *
 * ══ §21/36 b2DistanceJoint::InitVelocityConstraints(b2SolverData const&)  0x2cce64  size 892  223 条（0x2cce64..0x2cd1e0）
 * @func 0x2cce64 0x2cd1e0  size 892  223 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6580×2 / 0xb658c×2 / b2DistanceJoint::InitVelocityConstraints(b2SolverData const&)+0x338 / b2DistanceJoint::InitVelocityConstraints(b2SolverData const&)+0x350 / 0xb6700 / 0xfebc2e04
 * 字段偏移 top8: 0x8×4 / 0x90×2 / 0x6c×2 / 0x1c×2 / 0x70×2 / 0x30×1 / 0x34×1 / 0x18×1
 * VFP 指令 157 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cce64 ldr r2, [r0, #0x30]
 *   @0x2cce68 vldr s15, [r2, #136]
 *   @0x2cce6c push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2cce70 vpush {d8, d9, d10, d11, d12, d13, d14}
 *   @0x2cce74 mov r5, r1
 *   @0x2cce78 ldr r3, [r0, #0x34]
 *   @0x2cce7c add r1, r2, #44
 *   @0x2cce80 ldr lr, [r2, #0x8]
 *   @0x2cce84 mov r4, r0
 *   @0x2cce88 ldr r8, [r5, #0x18]
 *   @0x2cce8c add r10, r0, #140
 *   @0x2cce90 ldr r12, [r3, #0x8]
 *   @0x2cce94 add r7, r0, #148
 *   @0x2cce98 ldr r11, [r2, #0x90]
 *   @0x2cce9c add r9, r3, #44
 *   @0x2ccea0 ldm r1, {r0, r1}
 *   @0x2ccea4 str lr, [r4, #0x6c]
 *   @0x2ccea8 add lr, lr, lr, lsl #1
 *   @0x2cceac ldr r6, [r5, #0x1c]
 *   @0x2cceb0 lsl lr, lr, #2
 *   @0x2cceb4 str r12, [r4, #0x70]
 *   @0x2cceb8 add r12, r12, r12, lsl #1
 *   @0x2ccebc add r2, r8, lr
 *   @0x2ccec0 stm r10, {r0, r1}
 *   @0x2ccec4 add lr, r6, lr
 *   @0x2ccec8 lsl r12, r12, #2
 *   @0x2ccecc ldm r9, {r0, r1}
 *   @0x2cced0 ldr r10, [r3, #0x88]
 *   @0x2cced4 vldr s24, [r2]
 *   @0x2cced8 ldr r9, [r3, #0x90]
 *   @0x2ccedc add r3, r8, r12
 *   @0x2ccee0 ldr r8, [r2, #0x8]
 *   @0x2ccee4 add r12, r6, r12
 *   @0x2ccee8 stm r7, {r0, r1}
 *   @0x2cceec vstr s15, [r4, #156]
 *   @0x2ccef0 str r11, [r4, #0xa4]
 *   @0x2ccef4 vldr s26, [r2, #4]
 *   @0x2ccef8 str r10, [r4, #0xa0]
 *   @0x2ccefc mov r0, r8
 *   @0x2ccf00 str r9, [r4, #0xa8]
 *   @0x2ccf04 vldr s25, [r3]
 *   @0x2ccf08 ldr r7, [r3, #0x8]
 *   @0x2ccf0c vldr s27, [r3, #4]
 *   @0x2ccf10 vldr s21, [lr]
 *   @0x2ccf14 vldr s20, [lr, #4]
 *   @0x2ccf18 vldr s19, [lr, #8]
 *   @0x2ccf1c vldr s18, [r12]
 *   @0x2ccf20 vldr s17, [r12, #4]
 *   @0x2ccf24 vldr s16, [r12, #8]
 *   @0x2ccf28 bl 0xb6580 <sinf@plt>
 *   @0x2ccf2c vmov s22, r0
 *   @0x2ccf30 mov r0, r8
 *   @0x2ccf34 bl 0xb658c <cosf@plt>
 *   @0x2ccf38 vmov s23, r0
 *   @0x2ccf3c mov r0, r7
 *   @0x2ccf40 bl 0xb6580 <sinf@plt>
 *   @0x2ccf44 vmov s28, r0
 *   @0x2ccf48 mov r0, r7
 *   @0x2ccf4c bl 0xb658c <cosf@plt>
 *   @0x2ccf50 vldr s15, [r4, #144]
 *   @0x2ccf54 vldr s14, [r4, #84]
 *   @0x2ccf58 vsub.f32 s14, s14, s15
 *   @0x2ccf5c vldr s13, [r4, #140]
 *   @0x2ccf60 vldr s11, [r4, #80]
 *   @0x2ccf64 vmul.f32 s15, s14, s22
 *   @0x2ccf68 vsub.f32 s11, s11, s13
 *   @0x2ccf6c vmov s10, r0
 *   @0x2ccf70 vnmls.f32 s15, s11, s23
 *   @0x2ccf74 vstr s15, [r4, #124]
 *   @0x2ccf78 vldr s12, [r4, #92]
 *   @0x2ccf7c vldr s13, [r4, #152]
 *   @0x2ccf80 vsub.f32 s13, s12, s13
 *   @0x2ccf84 vldr s8, [r4, #88]
 *   @0x2ccf88 vldr s9, [r4, #148]
 *   @0x2ccf8c vmul.f32 s12, s13, s10
 *   @0x2ccf90 vsub.f32 s9, s8, s9
 *   @0x2ccf94 vmul.f32 s13, s13, s28
 *   @0x2ccf98 vmla.f32 s12, s9, s28
 *   @0x2ccf9c vmul.f32 s14, s14, s23
 *   @0x2ccfa0 vstr s12, [r4, #136]
 *   @0x2ccfa4 vnmls.f32 s13, s9, s10
 *   @0x2ccfa8 vmla.f32 s14, s11, s22
 *   @0x2ccfac vstr s13, [r4, #132]
 *   @0x2ccfb0 vadd.f32 s12, s12, s27
 *   @0x2ccfb4 vstr s14, [r4, #128]
 *   @0x2ccfb8 vsub.f32 s26, s12, s26
 *   @0x2ccfbc vadd.f32 s13, s13, s25
 *   @0x2ccfc0 vsub.f32 s14, s26, s14
 *   @0x2ccfc4 vsub.f32 s24, s13, s24
 *   @0x2ccfc8 vstr s14, [r4, #120]
 *   @0x2ccfcc vmul.f32 s14, s14, s14
 *   @0x2ccfd0 vsub.f32 s15, s24, s15
 *   @0x2ccfd4 vmla.f32 s14, s15, s15
 *   @0x2ccfd8 vstr s15, [r4, #116]
 *   @0x2ccfdc vsqrt.f32 s15, s14
 *   @0x2ccfe0 vcmp.f32 s15, s15
 *   @0x2ccfe4 vmrs APSR_nzcv, fpscr
 *   @0x2ccfe8 bne 0x2cd1c0 <_ZN15b2DistanceJoint23InitVelocityConstraintsERK12b2SolverData+0x35c>
 *   @0x2ccfec vldr s14, [pc, #480]
 *   @0x2ccff0 vcmpe.f32 s15, s14
 *   @0x2ccff4 vmrs APSR_nzcv, fpscr
 *   @0x2ccff8 ble 0x2cd19c <_ZN15b2DistanceJoint23InitVelocityConstraintsERK12b2SolverData+0x338>
 *   @0x2ccffc vmov.f32 s12, #1.000000e+00
 *   @0x2cd000 vldr s13, [r4, #116]
 *   @0x2cd004 vldr s14, [r4, #120]
 *   @0x2cd008 vdiv.f32 s12, s12, s15
 *   @0x2cd00c vmul.f32 s13, s12, s13
 *   @0x2cd010 vmul.f32 s12, s12, s14
 *   @0x2cd014 vstr s13, [r4, #116]
 *   @0x2cd018 vstr s12, [r4, #120]
 *   @0x2cd01c vldr s1, [r4, #128]
 *   @0x2cd020 vmul.f32 s14, s13, s1
 *   @0x2cd024 vldr s3, [r4, #124]
 *   @0x2cd028 vldr s2, [r4, #136]
 *   @0x2cd02c vldr s5, [r4, #164]
 *   @0x2cd030 vldr s4, [r4, #132]
 *   @0x2cd034 vldr s7, [r4, #156]
 *   @0x2cd038 vldr s6, [r4, #168]
 *   @0x2cd03c vldr s8, [r4, #160]
 *   @0x2cd040 vnmls.f32 s14, s12, s3
 *   @0x2cd044 vmul.f32 s13, s13, s2
 *   @0x2cd048 vmul.f32 s11, s14, s5
 *   @0x2cd04c vnmls.f32 s13, s12, s4
 *   @0x2cd050 vmov.f32 s12, s7
 *   @0x2cd054 vmla.f32 s12, s11, s14
 *   @0x2cd058 vldr s11, [r4, #68]
 *   @0x2cd05c vmov.f32 s14, s12
 *   @0x2cd060 vmul.f32 s12, s13, s6
 *   @0x2cd064 vadd.f32 s14, s14, s8
 *   @0x2cd068 vmla.f32 s14, s12, s13
 *   @0x2cd06c vldr s12, [pc, #356]
 *   @0x2cd070 vcmp.f32 s14, #0
 *   @0x2cd074 vmrs APSR_nzcv, fpscr
 *   @0x2cd078 vmovne.f32 s13, #1.000000e+00
 *   @0x2cd07c vldreq s13, [pc, #340]
 *   @0x2cd080 vdivne.f32 s13, s13, s14
 *   @0x2cd084 vcmpe.f32 s11, #0
 *   @0x2cd088 vstr s13, [r4, #172]
 *   @0x2cd08c vmrs APSR_nzcv, fpscr
 *   @0x2cd090 ble 0x2cd1b4 <_ZN15b2DistanceJoint23InitVelocityConstraintsERK12b2SolverData+0x350>
 *   @0x2cd094 vldr s9, [pc, #320]
 *   @0x2cd098 vmul.f32 s9, s11, s9
 *   @0x2cd09c vldr s10, [r4, #72]
 *   @0x2cd0a0 vldr s11, [r5]
 *   @0x2cd0a4 vldr s0, [r4, #104]
 *   @0x2cd0a8 vadd.f32 s22, s13, s13
 *   @0x2cd0ac vmul.f32 s13, s13, s9
 *   @0x2cd0b0 vmul.f32 s10, s22, s10
 *   @0x2cd0b4 vmul.f32 s13, s13, s9
 *   @0x2cd0b8 vmul.f32 s10, s10, s9
 *   @0x2cd0bc vmla.f32 s10, s11, s13
 *   @0x2cd0c0 vmul.f32 s10, s10, s11
 *   @0x2cd0c4 vcmp.f32 s10, s12
 *   @0x2cd0c8 vmrs APSR_nzcv, fpscr
 *   @0x2cd0cc vmovne.f32 s12, #1.000000e+00
 *   @0x2cd0d0 vdivne.f32 s12, s12, s10
 *   @0x2cd0d4 vadd.f32 s14, s12, s14
 *   @0x2cd0d8 vstr s12, [r4, #96]
 *   @0x2cd0dc vsub.f32 s15, s15, s0
 *   @0x2cd0e0 vcmp.f32 s14, #0
 *   @0x2cd0e4 vmul.f32 s11, s15, s11
 *   @0x2cd0e8 vmrs APSR_nzcv, fpscr
 *   @0x2cd0ec vldreq s14, [pc, #228]
 *   @0x2cd0f0 vmovne.f32 s15, #1.000000e+00
 *   @0x2cd0f4 vdivne.f32 s14, s15, s14
 *   @0x2cd0f8 vmul.f32 s13, s11, s13
 *   @0x2cd0fc vstr s14, [r4, #172]
 *   @0x2cd100 vmul.f32 s12, s12, s13
 *   @0x2cd104 vstr s12, [r4, #76]
 *   @0x2cd108 ldrb r3, [r5, #0x14]
 *   @0x2cd10c cmp r3, #0
 *   @0x2cd110 moveq r3, #0
 *   @0x2cd114 streq r3, [r4, #0x64]
 *   @0x2cd118 beq 0x2cd164 <_ZN15b2DistanceJoint23InitVelocityConstraintsERK12b2SolverData+0x300>
 *   @0x2cd11c vldr s14, [r4, #100]
 *   @0x2cd120 vldr s15, [r5, #8]
 *   @0x2cd124 vmul.f32 s15, s14, s15
 *   @0x2cd128 vldr s14, [r4, #116]
 *   @0x2cd12c vldr s13, [r4, #120]
 *   @0x2cd130 vmul.f32 s14, s15, s14
 *   @0x2cd134 vstr s15, [r4, #100]
 *   @0x2cd138 vmul.f32 s1, s14, s1
 *   @0x2cd13c vmul.f32 s15, s15, s13
 *   @0x2cd140 vmul.f32 s2, s14, s2
 *   @0x2cd144 vnmls.f32 s1, s15, s3
 *   @0x2cd148 vnmls.f32 s2, s15, s4
 *   @0x2cd14c vmls.f32 s21, s7, s14
 *   @0x2cd150 vmla.f32 s18, s8, s14
 *   @0x2cd154 vmls.f32 s19, s1, s5
 *   @0x2cd158 vmla.f32 s16, s2, s6
 *   @0x2cd15c vmls.f32 s20, s7, s15
 *   @0x2cd160 vmla.f32 s17, s8, s15
 *   @0x2cd164 ldr r3, [r4, #0x6c]
 *   @0x2cd168 ldr r2, [r4, #0x70]
 *   @0x2cd16c add r3, r3, r3, lsl #1
 *   @0x2cd170 add r2, r2, r2, lsl #1
 *   @0x2cd174 add r3, r6, r3, lsl #2
 *   @0x2cd178 vstr s21, [r3]
 *   @0x2cd17c vstr s20, [r3, #4]
 *   @0x2cd180 vstr s19, [r3, #8]
 *   @0x2cd184 add r6, r6, r2, lsl #2
 *   @0x2cd188 vstr s18, [r6]
 *   @0x2cd18c vstr s17, [r6, #4]
 *   @0x2cd190 vstr s16, [r6, #8]
 *   @0x2cd194 vpop {d8, d9, d10, d11, d12, d13, d14}
 *   @0x2cd198 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2cd19c vldr s14, [pc, #52]
 *   @0x2cd1a0 vmov.f32 s13, s14
 *   @0x2cd1a4 vstr s14, [r4, #116]
 *   @0x2cd1a8 vstr s14, [r4, #120]
 *   @0x2cd1ac vmov.f32 s12, s14
 *   @0x2cd1b0 b 0x2cd01c <_ZN15b2DistanceJoint23InitVelocityConstraintsERK12b2SolverData+0x1b8>
 *   @0x2cd1b4 vstr s12, [r4, #96]
 *   @0x2cd1b8 vstr s12, [r4, #76]
 *   @0x2cd1bc b 0x2cd108 <_ZN15b2DistanceJoint23InitVelocityConstraintsERK12b2SolverData+0x2a4>
 *   @0x2cd1c0 vmov r0, s14
 *   @0x2cd1c4 bl 0xb6700 <sqrtf@plt>
 *   @0x2cd1c8 ldr r6, [r5, #0x1c]
 *   @0x2cd1cc vmov s15, r0
 *   @0x2cd1d0 b 0x2ccfec <_ZN15b2DistanceJoint23InitVelocityConstraintsERK12b2SolverData+0x188>
 *   @0x2cd1d4 bllo 0xfebc2e04 <b2_toiTime+0xfffffffffe469960>
 *   @0x2cd1d8 andeq r0, r0, r0
 *   @0x2cd1dc ldrdmi r0, r1, [r9], #251
 *
 * ══ §22/36 __gnu_unwind_execute  0x31a73c  size 892  223 条（0x31a73c..0x31aab8）
 * @func 0x31a73c 0x31aab8  size 892  223 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_31a6b0×10 / _Unwind_VRS_Get×4 / _Unwind_VRS_Set×2 / _Unwind_VRS_Pop×2
 * 字段偏移 top8: 0xc×5
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31a73c push {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x31a740 add r8, sp, #12
 *   @0x31a744 mov r5, r0
 *   @0x31a748 mov r6, r1
 *   @0x31a74c mov r7, #0
 *   @0x31a750 mov r9, #4080
 *   @0x31a754 mov r0, r6
 *   @0x31a758 bl 0x31a6b0 <___Unwind_Backtrace+0x24>
 *   @0x31a75c cmp r0, #176
 *   @0x31a760 mov r4, r0
 *   @0x31a764 bne 0x31a7a8 <__gnu_unwind_execute+0x6c>
 *   @0x31a768 cmp r7, #0
 *   @0x31a76c bne 0x31aaac <__gnu_unwind_execute+0x370>
 *   @0x31a770 add r4, sp, #12
 *   @0x31a774 mov r1, r7
 *   @0x31a778 mov r3, r7
 *   @0x31a77c str r4, [sp]
 *   @0x31a780 mov r0, r5
 *   @0x31a784 mov r2, #14
 *   @0x31a788 bl 0x319be4 <_Unwind_VRS_Get>
 *   @0x31a78c str r4, [sp]
 *   @0x31a790 mov r0, r5
 *   @0x31a794 mov r1, r7
 *   @0x31a798 mov r2, #15
 *   @0x31a79c mov r3, r7
 *   @0x31a7a0 bl 0x319c68 <_Unwind_VRS_Set>
 *   @0x31a7a4 b 0x31aaac <__gnu_unwind_execute+0x370>
 *   @0x31a7a8 bic r1, r0, #127
 *   @0x31a7ac ands r1, r1, #255
 *   @0x31a7b0 bne 0x31a7ec <__gnu_unwind_execute+0xb0>
 *   @0x31a7b4 lsl r10, r0, #2
 *   @0x31a7b8 mov r3, r1
 *   @0x31a7bc str r8, [sp]
 *   @0x31a7c0 mov r0, r5
 *   @0x31a7c4 mov r2, #13
 *   @0x31a7c8 uxtb r10, r10
 *   @0x31a7cc bl 0x319be4 <_Unwind_VRS_Get>
 *   @0x31a7d0 ldr r3, [sp, #0xc]
 *   @0x31a7d4 add r10, r10, #4
 *   @0x31a7d8 tst r4, #64
 *   @0x31a7dc rsbne r10, r10, r3
 *   @0x31a7e0 addeq r10, r3, r10
 *   @0x31a7e4 str r10, [sp, #0xc]
 *   @0x31a7e8 b 0x31a870 <__gnu_unwind_execute+0x134>
 *   @0x31a7ec and r3, r0, #240
 *   @0x31a7f0 cmp r3, #128
 *   @0x31a7f4 bne 0x31a844 <__gnu_unwind_execute+0x108>
 *   @0x31a7f8 lsl r4, r0, #8
 *   @0x31a7fc mov r0, r6
 *   @0x31a800 bl 0x31a6b0 <___Unwind_Backtrace+0x24>
 *   @0x31a804 orr r0, r0, r4
 *   @0x31a808 cmp r0, #32768
 *   @0x31a80c bne 0x31a818 <__gnu_unwind_execute+0xdc>
 *   @0x31a810 mov r0, #9
 *   @0x31a814 b 0x31aab0 <__gnu_unwind_execute+0x374>
 *   @0x31a818 lsl r4, r0, #4
 *   @0x31a81c mov r1, #0
 *   @0x31a820 mov r0, r5
 *   @0x31a824 mov r3, r1
 *   @0x31a828 uxth r2, r4
 *   @0x31a82c bl 0x31a1bc <_Unwind_VRS_Pop>
 *   @0x31a830 cmp r0, #0
 *   @0x31a834 bne 0x31a810 <__gnu_unwind_execute+0xd4>
 *   @0x31a838 tst r4, #32768
 *   @0x31a83c movne r7, #1
 *   @0x31a840 b 0x31a754 <__gnu_unwind_execute+0x18>
 *   @0x31a844 cmp r3, #144
 *   @0x31a848 bne 0x31a88c <__gnu_unwind_execute+0x150>
 *   @0x31a84c and r3, r0, #13
 *   @0x31a850 cmp r3, #13
 *   @0x31a854 beq 0x31a810 <__gnu_unwind_execute+0xd4>
 *   @0x31a858 mov r1, #0
 *   @0x31a85c str r8, [sp]
 *   @0x31a860 mov r0, r5
 *   @0x31a864 and r2, r4, #15
 *   @0x31a868 mov r3, r1
 *   @0x31a86c bl 0x319be4 <_Unwind_VRS_Get>
 *   @0x31a870 mov r0, r5
 *   @0x31a874 mov r1, #0
 *   @0x31a878 str r8, [sp]
 *   @0x31a87c mov r2, #13
 *   @0x31a880 mov r3, r1
 *   @0x31a884 bl 0x319c68 <_Unwind_VRS_Set>
 *   @0x31a888 b 0x31a754 <__gnu_unwind_execute+0x18>
 *   @0x31a88c cmp r3, #160
 *   @0x31a890 bne 0x31a8b8 <__gnu_unwind_execute+0x17c>
 *   @0x31a894 mvn r2, r0
 *   @0x31a898 and r2, r2, #7
 *   @0x31a89c asr r2, r9, r2
 *   @0x31a8a0 tst r0, #8
 *   @0x31a8a4 and r2, r2, #4080
 *   @0x31a8a8 mov r0, r5
 *   @0x31a8ac orrne r2, r2, #16384
 *   @0x31a8b0 mov r1, #0
 *   @0x31a8b4 b 0x31a8e4 <__gnu_unwind_execute+0x1a8>
 *   @0x31a8b8 cmp r3, #176
 *   @0x31a8bc bne 0x31a9a4 <__gnu_unwind_execute+0x268>
 *   @0x31a8c0 cmp r0, #177
 *   @0x31a8c4 bne 0x31a8ec <__gnu_unwind_execute+0x1b0>
 *   @0x31a8c8 mov r0, r6
 *   @0x31a8cc bl 0x31a6b0 <___Unwind_Backtrace+0x24>
 *   @0x31a8d0 subs r2, r0, #0
 *   @0x31a8d4 beq 0x31a810 <__gnu_unwind_execute+0xd4>
 *   @0x31a8d8 ands r1, r2, #240
 *   @0x31a8dc bne 0x31a810 <__gnu_unwind_execute+0xd4>
 *   @0x31a8e0 mov r0, r5
 *   @0x31a8e4 mov r3, r1
 *   @0x31a8e8 b 0x31aa9c <__gnu_unwind_execute+0x360>
 *   @0x31a8ec cmp r0, #178
 *   @0x31a8f0 bne 0x31a958 <__gnu_unwind_execute+0x21c>
 *   @0x31a8f4 mov r1, #0
 *   @0x31a8f8 mov r2, #13
 *   @0x31a8fc mov r3, r1
 *   @0x31a900 str r8, [sp]
 *   @0x31a904 mov r0, r5
 *   @0x31a908 mov r4, #2
 *   @0x31a90c bl 0x319be4 <_Unwind_VRS_Get>
 *   @0x31a910 mov r0, r6
 *   @0x31a914 bl 0x31a6b0 <___Unwind_Backtrace+0x24>
 *   @0x31a918 ands r1, r0, #128
 *   @0x31a91c ldr r3, [sp, #0xc]
 *   @0x31a920 and r0, r0, #127
 *   @0x31a924 beq 0x31a940 <__gnu_unwind_execute+0x204>
 *   @0x31a928 add r0, r3, r0, lsl r4
 *   @0x31a92c str r0, [sp, #0xc]
 *   @0x31a930 mov r0, r6
 *   @0x31a934 add r4, r4, #7
 *   @0x31a938 bl 0x31a6b0 <___Unwind_Backtrace+0x24>
 *   @0x31a93c b 0x31a918 <__gnu_unwind_execute+0x1dc>
 *   @0x31a940 add r3, r3, #516
 *   @0x31a944 str r8, [sp]
 *   @0x31a948 add r0, r3, r0, lsl r4
 *   @0x31a94c str r0, [sp, #0xc]
 *   @0x31a950 mov r0, r5
 *   @0x31a954 b 0x31a87c <__gnu_unwind_execute+0x140>
 *   @0x31a958 cmp r0, #179
 *   @0x31a95c bne 0x31a980 <__gnu_unwind_execute+0x244>
 *   @0x31a960 mov r0, r6
 *   @0x31a964 bl 0x31a6b0 <___Unwind_Backtrace+0x24>
 *   @0x31a968 mov r1, #1
 *   @0x31a96c and r3, r0, #15
 *   @0x31a970 and r2, r0, #240
 *   @0x31a974 add r3, r3, #1
 *   @0x31a978 mov r0, r5
 *   @0x31a97c b 0x31a9d0 <__gnu_unwind_execute+0x294>
 *   @0x31a980 and r3, r0, #252
 *   @0x31a984 cmp r3, #180
 *   @0x31a988 beq 0x31a810 <__gnu_unwind_execute+0xd4>
 *   @0x31a98c and r4, r0, #7
 *   @0x31a990 mov r1, #1
 *   @0x31a994 add r2, r4, #1
 *   @0x31a998 mov r0, r5
 *   @0x31a99c orr r2, r2, #524288
 *   @0x31a9a0 b 0x31a8e4 <__gnu_unwind_execute+0x1a8>
 *   @0x31a9a4 cmp r3, #192
 *   @0x31a9a8 bne 0x31aa78 <__gnu_unwind_execute+0x33c>
 *   @0x31a9ac cmp r0, #198
 *   @0x31a9b0 bne 0x31a9d8 <__gnu_unwind_execute+0x29c>
 *   @0x31a9b4 mov r0, r6
 *   @0x31a9b8 bl 0x31a6b0 <___Unwind_Backtrace+0x24>
 *   @0x31a9bc mov r1, #3
 *   @0x31a9c0 and r3, r0, #15
 *   @0x31a9c4 and r2, r0, #240
 *   @0x31a9c8 add r3, r3, #1
 *   @0x31a9cc mov r0, r5
 *   @0x31a9d0 orr r2, r3, r2, lsl #12
 *   @0x31a9d4 b 0x31a8e4 <__gnu_unwind_execute+0x1a8>
 *   @0x31a9d8 cmp r0, #199
 *   @0x31a9dc bne 0x31aa04 <__gnu_unwind_execute+0x2c8>
 *   @0x31a9e0 mov r0, r6
 *   @0x31a9e4 bl 0x31a6b0 <___Unwind_Backtrace+0x24>
 *   @0x31a9e8 subs r2, r0, #0
 *   @0x31a9ec beq 0x31a810 <__gnu_unwind_execute+0xd4>
 *   @0x31a9f0 ands r3, r2, #240
 *   @0x31a9f4 bne 0x31a810 <__gnu_unwind_execute+0xd4>
 *   @0x31a9f8 mov r0, r5
 *   @0x31a9fc mov r1, #4
 *   @0x31aa00 b 0x31aa9c <__gnu_unwind_execute+0x360>
 *   @0x31aa04 and r3, r0, #248
 *   @0x31aa08 cmp r3, #192
 *   @0x31aa0c bne 0x31aa28 <__gnu_unwind_execute+0x2ec>
 *   @0x31aa10 and r4, r0, #15
 *   @0x31aa14 mov r1, #3
 *   @0x31aa18 add r2, r4, #1
 *   @0x31aa1c mov r0, r5
 *   @0x31aa20 orr r2, r2, #655360
 *   @0x31aa24 b 0x31a8e4 <__gnu_unwind_execute+0x1a8>
 *   @0x31aa28 cmp r0, #200
 *   @0x31aa2c bne 0x31aa4c <__gnu_unwind_execute+0x310>
 *   @0x31aa30 mov r0, r6
 *   @0x31aa34 bl 0x31a6b0 <___Unwind_Backtrace+0x24>
 *   @0x31aa38 and r2, r0, #240
 *   @0x31aa3c and r0, r0, #15
 *   @0x31aa40 add r2, r2, #16
 *   @0x31aa44 add r3, r0, #1
 *   @0x31aa48 b 0x31aa68 <__gnu_unwind_execute+0x32c>
 *   @0x31aa4c cmp r0, #201
 *   @0x31aa50 bne 0x31a810 <__gnu_unwind_execute+0xd4>
 *   @0x31aa54 mov r0, r6
 *   @0x31aa58 bl 0x31a6b0 <___Unwind_Backtrace+0x24>
 *   @0x31aa5c and r3, r0, #15
 *   @0x31aa60 and r2, r0, #240
 *   @0x31aa64 add r3, r3, #1
 *   @0x31aa68 mov r0, r5
 *   @0x31aa6c mov r1, #1
 *   @0x31aa70 orr r2, r3, r2, lsl #12
 *   @0x31aa74 b 0x31aa98 <__gnu_unwind_execute+0x35c>
 *   @0x31aa78 and r3, r0, #248
 *   @0x31aa7c cmp r3, #208
 *   @0x31aa80 bne 0x31a810 <__gnu_unwind_execute+0xd4>
 *   @0x31aa84 and r4, r0, #7
 *   @0x31aa88 mov r1, #1
 *   @0x31aa8c add r2, r4, #1
 *   @0x31aa90 mov r0, r5
 *   @0x31aa94 orr r2, r2, #524288
 *   @0x31aa98 mov r3, #5
 *   @0x31aa9c bl 0x31a1bc <_Unwind_VRS_Pop>
 *   @0x31aaa0 cmp r0, #0
 *   @0x31aaa4 bne 0x31a810 <__gnu_unwind_execute+0xd4>
 *   @0x31aaa8 b 0x31a754 <__gnu_unwind_execute+0x18>
 *   @0x31aaac mov r0, #0
 *   @0x31aab0 add sp, sp, #16
 *   @0x31aab4 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ §23/36 F_JS_Object_getOwnPropertyNames(RValue&, CInstance*, CInstance*, int, RValue*)  0x250b30  size 888  222 条（0x250b30..0x250ea8）
 * @func 0x250b30 0x250eb8  size 904  226 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / YYObject_PropertyNameIterator::YYObject_PropertyNameIterator(YYObjectBase*, int)×2 / YYObject_PropertyNameIterator::Next(RValue*)×2 / YYObjectBase::InternalGetYYVar(int)×2 / JSThrowTypeError(char const*)
 * 字段偏移 top8: 0xc×12 / 0x4×10 / 0x8×7 / 0x10×7 / 0x18×2 / 0x1c×2 / 0x80×1 / 0x33c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x250b30 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x250b34 cmp r3, #0
 *   @0x250b38 sub sp, sp, #92
 *   @0x250b3c mov r8, r0
 *   @0x250b40 mov r11, r1
 *   @0x250b44 mov r9, r2
 *   @0x250b48 ldr r5, [sp, #0x80]
 *   @0x250b4c beq 0x250b60 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x30>
 *   @0x250b50 ldr r3, [r5, #0xc]
 *   @0x250b54 bic r3, r3, #-16777216
 *   @0x250b58 cmp r3, #6
 *   @0x250b5c beq 0x250b74 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x250b60 ldr r0, [pc, #0x33c]
 *   @0x250b64 add r0, pc, r0
 *   @0x250b68 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x250b6c add sp, sp, #92
 *   @0x250b70 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x250b74 ldr r10, [r5]
 *   @0x250b78 add r7, sp, #32
 *   @0x250b7c mov r2, #0
 *   @0x250b80 add r6, sp, #16
 *   @0x250b84 mov r0, r7
 *   @0x250b88 mov r4, r2
 *   @0x250b8c mov r1, r10
 *   @0x250b90 bl 0x2400ec <_ZN29YYObject_PropertyNameIteratorC2EP12YYObjectBasei>
 *   @0x250b94 b 0x250b9c <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x250b98 add r4, r4, #1
 *   @0x250b9c mov r0, r7
 *   @0x250ba0 mov r1, r6
 *   @0x250ba4 bl 0x24a1fc <_ZN29YYObject_PropertyNameIterator4NextEP6RValue>
 *   @0x250ba8 cmp r0, #0
 *   @0x250bac bne 0x250b98 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x250bb0 mov r3, r4
 *   @0x250bb4 mov r0, r8
 *   @0x250bb8 str r5, [sp]
 *   @0x250bbc mov r1, r11
 *   @0x250bc0 mov r2, r9
 *   @0x250bc4 bl 0x242c84 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_>
 *   @0x250bc8 ldr r0, [r8]
 *   @0x250bcc ldr r3, [r0, #0x4]
 *   @0x250bd0 cmp r3, #0
 *   @0x250bd4 beq 0x250e98 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x368>
 *   @0x250bd8 add r0, r3, #16
 *   @0x250bdc ldr r9, [r0]
 *   @0x250be0 add r8, sp, #60
 *   @0x250be4 mov r1, r10
 *   @0x250be8 mov r2, #0
 *   @0x250bec mov r0, r8
 *   @0x250bf0 mov r5, r2
 *   @0x250bf4 bl 0x2400ec <_ZN29YYObject_PropertyNameIteratorC2EP12YYObjectBasei>
 *   @0x250bf8 mov r0, r9
 *   @0x250bfc bl 0xd3968 <_Z16PushContextStackP12YYObjectBase>
 *   @0x250c00 mov r7, r5
 *   @0x250c04 mov r10, #7
 *   @0x250c08 mov r0, r8
 *   @0x250c0c mov r1, r6
 *   @0x250c10 bl 0x24a1fc <_ZN29YYObject_PropertyNameIterator4NextEP6RValue>
 *   @0x250c14 cmp r0, #0
 *   @0x250c18 beq 0x250dc4 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x294>
 *   @0x250c1c ldr r4, [r9, #0x4]
 *   @0x250c20 str r10, [sp, #0x18]
 *   @0x250c24 cmp r4, #0
 *   @0x250c28 beq 0x250ddc <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x2ac>
 *   @0x250c2c add r4, r4, r5, lsl #4
 *   @0x250c30 ldr r2, [r4, #0xc]
 *   @0x250c34 bic r3, r2, #-16777216
 *   @0x250c38 cmp r3, #1
 *   @0x250c3c beq 0x250d54 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x224>
 *   @0x250c40 cmp r3, #2
 *   @0x250c44 bne 0x250c68 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x138>
 *   @0x250c48 sub r2, r2, #1
 *   @0x250c4c bic r2, r2, #-16777216
 *   @0x250c50 bic r2, r2, #3
 *   @0x250c54 cmp r2, #0
 *   @0x250c58 beq 0x250dd0 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x2a0>
 *   @0x250c5c mov r3, #5
 *   @0x250c60 str r7, [r4, #0x8]
 *   @0x250c64 str r3, [r4, #0xc]
 *   @0x250c68 ldr r3, [sp, #0x1c]
 *   @0x250c6c ldr r2, [sp, #0x18]
 *   @0x250c70 str r7, [r4]
 *   @0x250c74 str r3, [r4, #0xc]
 *   @0x250c78 ldr r3, [sp, #0x1c]
 *   @0x250c7c str r2, [r4, #0x8]
 *   @0x250c80 bic r3, r3, #-16777216
 *   @0x250c84 cmp r3, #14
 *   @0x250c88 addls pc, pc, r3, lsl #2
 *   @0x250c8c b 0x250cd4 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x250c90 b 0x250cdc <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x1ac>
 *   @0x250c94 b 0x250d3c <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x20c>
 *   @0x250c98 b 0x250d10 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x1e0>
 *   @0x250c9c b 0x250ccc <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x19c>
 *   @0x250ca0 b 0x250cd4 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x250ca4 b 0x250cd4 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x250ca8 b 0x250cec <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x1bc>
 *   @0x250cac b 0x250ccc <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x19c>
 *   @0x250cb0 b 0x250cd4 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x250cb4 b 0x250cd4 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x250cb8 b 0x250cdc <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x1ac>
 *   @0x250cbc b 0x250cd4 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x250cc0 b 0x250cd4 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x250cc4 b 0x250cdc <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x1ac>
 *   @0x250cc8 b 0x250ccc <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x19c>
 *   @0x250ccc ldr r3, [sp, #0x10]
 *   @0x250cd0 str r3, [r4]
 *   @0x250cd4 add r5, r5, #1
 *   @0x250cd8 b 0x250c08 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x250cdc ldr r2, [sp, #0x10]
 *   @0x250ce0 ldr r3, [sp, #0x14]
 *   @0x250ce4 stm r4, {r2, r3}
 *   @0x250ce8 b 0x250cd4 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x250cec ldr r3, [sp, #0x10]
 *   @0x250cf0 str r3, [r4]
 *   @0x250cf4 ldr r3, [sp, #0x10]
 *   @0x250cf8 cmp r3, #0
 *   @0x250cfc beq 0x250cd4 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x250d00 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x250d04 ldr r1, [sp, #0x10]
 *   @0x250d08 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x250d0c b 0x250cd4 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x250d10 ldr r3, [sp, #0x10]
 *   @0x250d14 cmp r3, #0
 *   @0x250d18 str r3, [r4]
 *   @0x250d1c beq 0x250cd4 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x250d20 ldr r1, [r3, #0x8]
 *   @0x250d24 ldr r2, [r3]
 *   @0x250d28 cmp r1, #0
 *   @0x250d2c streq r4, [r3, #0x8]
 *   @0x250d30 add r2, r2, #1
 *   @0x250d34 str r2, [r3]
 *   @0x250d38 b 0x250cd4 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x250d3c ldr r3, [sp, #0x10]
 *   @0x250d40 cmp r3, #0
 *   @0x250d44 ldrne r2, [r3, #0x4]
 *   @0x250d48 addne r2, r2, #1
 *   @0x250d4c strne r2, [r3, #0x4]
 *   @0x250d50 b 0x250cd0 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x1a0>
 *   @0x250d54 ldr r11, [r4]
 *   @0x250d58 cmp r11, #0
 *   @0x250d5c beq 0x250d7c <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x24c>
 *   @0x250d60 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x250d64 ldr r2, [r11, #0x4]
 *   @0x250d68 sub r2, r2, #1
 *   @0x250d6c str r2, [r11, #0x4]
 *   @0x250d70 cmp r2, #0
 *   @0x250d74 beq 0x250d84 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x254>
 *   @0x250d78 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x250d7c str r7, [r4]
 *   @0x250d80 b 0x250c68 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x138>
 *   @0x250d84 ldr r0, [r11]
 *   @0x250d88 str r2, [sp, #0xc]
 *   @0x250d8c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x250d90 ldr r2, [sp, #0xc]
 *   @0x250d94 str r2, [r11]
 *   @0x250d98 str r2, [r11, #0x8]
 *   @0x250d9c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x250da0 ldr r2, [r11, #0x4]
 *   @0x250da4 sub r2, r2, #1
 *   @0x250da8 str r2, [r11, #0x4]
 *   @0x250dac cmp r2, #0
 *   @0x250db0 beq 0x250df0 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x2c0>
 *   @0x250db4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x250db8 mov r0, r11
 *   @0x250dbc bl 0x27d1d0 <_ZdlPv>
 *   @0x250dc0 b 0x250d78 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x248>
 *   @0x250dc4 bl 0xd3a34 <_Z15PopContextStackv>
 *   @0x250dc8 add sp, sp, #92
 *   @0x250dcc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x250dd0 mov r0, r4
 *   @0x250dd4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x250dd8 b 0x250c5c <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x250ddc mov r0, r9
 *   @0x250de0 mov r1, r5
 *   @0x250de4 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x250de8 mov r4, r0
 *   @0x250dec b 0x250c30 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x100>
 *   @0x250df0 ldr r0, [r11]
 *   @0x250df4 str r2, [sp, #0xc]
 *   @0x250df8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x250dfc ldr r2, [sp, #0xc]
 *   @0x250e00 str r2, [r11]
 *   @0x250e04 str r2, [r11, #0x8]
 *   @0x250e08 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x250e0c ldr r2, [r11, #0x4]
 *   @0x250e10 sub r2, r2, #1
 *   @0x250e14 str r2, [r11, #0x4]
 *   @0x250e18 cmp r2, #0
 *   @0x250e1c beq 0x250e30 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x300>
 *   @0x250e20 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x250e24 mov r0, r11
 *   @0x250e28 bl 0x27d1d0 <_ZdlPv>
 *   @0x250e2c b 0x250db4 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x284>
 *   @0x250e30 ldr r0, [r11]
 *   @0x250e34 str r2, [sp, #0xc]
 *   @0x250e38 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x250e3c ldr r2, [sp, #0xc]
 *   @0x250e40 str r2, [r11]
 *   @0x250e44 str r2, [r11, #0x8]
 *   @0x250e48 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x250e4c ldr r2, [r11, #0x4]
 *   @0x250e50 sub r2, r2, #1
 *   @0x250e54 str r2, [r11, #0x4]
 *   @0x250e58 cmp r2, #0
 *   @0x250e5c bne 0x250e88 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x358>
 *   @0x250e60 ldr r0, [r11]
 *   @0x250e64 str r2, [sp, #0xc]
 *   @0x250e68 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x250e6c ldr r2, [sp, #0xc]
 *   @0x250e70 mov r0, r11
 *   @0x250e74 str r2, [r11]
 *   @0x250e78 str r2, [r11, #0x8]
 *   @0x250e7c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x250e80 mov r0, r11
 *   @0x250e84 bl 0x27d1d0 <_ZdlPv>
 *   @0x250e88 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x250e8c mov r0, r11
 *   @0x250e90 bl 0x27d1d0 <_ZdlPv>
 *   @0x250e94 b 0x250e20 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x2f0>
 *   @0x250e98 mov r1, #1
 *   @0x250e9c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x250ea0 b 0x250bdc <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x250ea4 andseq r5, r0, r4, ror #7
 *
 * ══ §24/36 F_JS_Object_keys(RValue&, CInstance*, CInstance*, int, RValue*)  0x250ea8  size 888  222 条（0x250ea8..0x251220）
 * @func 0x250ea8 0x251220  size 888  222 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / YYObject_PropertyNameIterator::YYObject_PropertyNameIterator(YYObjectBase*, int)×2 / YYObject_PropertyNameIterator::Next(RValue*)×2 / YYObjectBase::InternalGetYYVar(int)×2 / JSThrowTypeError(char const*)
 * 字段偏移 top8: 0xc×12 / 0x4×10 / 0x8×7 / 0x10×7 / 0x18×2 / 0x1c×2 / 0x80×1 / 0x33c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x250ea8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x250eac cmp r3, #0
 *   @0x250eb0 sub sp, sp, #92
 *   @0x250eb4 mov r8, r0
 *   @0x250eb8 mov r11, r1
 *   @0x250ebc mov r9, r2
 *   @0x250ec0 ldr r5, [sp, #0x80]
 *   @0x250ec4 beq 0x250ed8 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x30>
 *   @0x250ec8 ldr r3, [r5, #0xc]
 *   @0x250ecc bic r3, r3, #-16777216
 *   @0x250ed0 cmp r3, #6
 *   @0x250ed4 beq 0x250eec <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x250ed8 ldr r0, [pc, #0x33c]
 *   @0x250edc add r0, pc, r0
 *   @0x250ee0 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x250ee4 add sp, sp, #92
 *   @0x250ee8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x250eec ldr r10, [r5]
 *   @0x250ef0 add r7, sp, #32
 *   @0x250ef4 mov r2, #1
 *   @0x250ef8 mov r4, #0
 *   @0x250efc mov r0, r7
 *   @0x250f00 add r6, sp, #16
 *   @0x250f04 mov r1, r10
 *   @0x250f08 bl 0x2400ec <_ZN29YYObject_PropertyNameIteratorC2EP12YYObjectBasei>
 *   @0x250f0c b 0x250f14 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x250f10 add r4, r4, #1
 *   @0x250f14 mov r0, r7
 *   @0x250f18 mov r1, r6
 *   @0x250f1c bl 0x24a1fc <_ZN29YYObject_PropertyNameIterator4NextEP6RValue>
 *   @0x250f20 cmp r0, #0
 *   @0x250f24 bne 0x250f10 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x250f28 mov r3, r4
 *   @0x250f2c mov r0, r8
 *   @0x250f30 str r5, [sp]
 *   @0x250f34 mov r1, r11
 *   @0x250f38 mov r2, r9
 *   @0x250f3c bl 0x242c84 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_>
 *   @0x250f40 ldr r0, [r8]
 *   @0x250f44 ldr r3, [r0, #0x4]
 *   @0x250f48 cmp r3, #0
 *   @0x250f4c beq 0x251210 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x368>
 *   @0x250f50 add r0, r3, #16
 *   @0x250f54 ldr r9, [r0]
 *   @0x250f58 add r8, sp, #60
 *   @0x250f5c mov r1, r10
 *   @0x250f60 mov r2, #1
 *   @0x250f64 mov r0, r8
 *   @0x250f68 mov r5, #0
 *   @0x250f6c bl 0x2400ec <_ZN29YYObject_PropertyNameIteratorC2EP12YYObjectBasei>
 *   @0x250f70 mov r0, r9
 *   @0x250f74 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase>
 *   @0x250f78 mov r7, r5
 *   @0x250f7c mov r10, #7
 *   @0x250f80 mov r0, r8
 *   @0x250f84 mov r1, r6
 *   @0x250f88 bl 0x24a1fc <_ZN29YYObject_PropertyNameIterator4NextEP6RValue>
 *   @0x250f8c cmp r0, #0
 *   @0x250f90 beq 0x25113c <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x294>
 *   @0x250f94 ldr r4, [r9, #0x4]
 *   @0x250f98 str r10, [sp, #0x18]
 *   @0x250f9c cmp r4, #0
 *   @0x250fa0 beq 0x251154 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x2ac>
 *   @0x250fa4 add r4, r4, r5, lsl #4
 *   @0x250fa8 ldr r2, [r4, #0xc]
 *   @0x250fac bic r3, r2, #-16777216
 *   @0x250fb0 cmp r3, #1
 *   @0x250fb4 beq 0x2510cc <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x224>
 *   @0x250fb8 cmp r3, #2
 *   @0x250fbc bne 0x250fe0 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x138>
 *   @0x250fc0 sub r2, r2, #1
 *   @0x250fc4 bic r2, r2, #-16777216
 *   @0x250fc8 bic r2, r2, #3
 *   @0x250fcc cmp r2, #0
 *   @0x250fd0 beq 0x251148 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x2a0>
 *   @0x250fd4 mov r3, #5
 *   @0x250fd8 str r7, [r4, #0x8]
 *   @0x250fdc str r3, [r4, #0xc]
 *   @0x250fe0 ldr r3, [sp, #0x1c]
 *   @0x250fe4 ldr r2, [sp, #0x18]
 *   @0x250fe8 str r7, [r4]
 *   @0x250fec str r3, [r4, #0xc]
 *   @0x250ff0 ldr r3, [sp, #0x1c]
 *   @0x250ff4 str r2, [r4, #0x8]
 *   @0x250ff8 bic r3, r3, #-16777216
 *   @0x250ffc cmp r3, #14
 *   @0x251000 addls pc, pc, r3, lsl #2
 *   @0x251004 b 0x25104c <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x251008 b 0x251054 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x1ac>
 *   @0x25100c b 0x2510b4 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x20c>
 *   @0x251010 b 0x251088 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x1e0>
 *   @0x251014 b 0x251044 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x19c>
 *   @0x251018 b 0x25104c <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x25101c b 0x25104c <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x251020 b 0x251064 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x1bc>
 *   @0x251024 b 0x251044 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x19c>
 *   @0x251028 b 0x25104c <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x25102c b 0x25104c <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x251030 b 0x251054 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x1ac>
 *   @0x251034 b 0x25104c <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x251038 b 0x25104c <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x25103c b 0x251054 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x1ac>
 *   @0x251040 b 0x251044 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x19c>
 *   @0x251044 ldr r3, [sp, #0x10]
 *   @0x251048 str r3, [r4]
 *   @0x25104c add r5, r5, #1
 *   @0x251050 b 0x250f80 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x251054 ldr r2, [sp, #0x10]
 *   @0x251058 ldr r3, [sp, #0x14]
 *   @0x25105c stm r4, {r2, r3}
 *   @0x251060 b 0x25104c <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x251064 ldr r3, [sp, #0x10]
 *   @0x251068 str r3, [r4]
 *   @0x25106c ldr r3, [sp, #0x10]
 *   @0x251070 cmp r3, #0
 *   @0x251074 beq 0x25104c <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x251078 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x25107c ldr r1, [sp, #0x10]
 *   @0x251080 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x251084 b 0x25104c <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x251088 ldr r3, [sp, #0x10]
 *   @0x25108c cmp r3, #0
 *   @0x251090 str r3, [r4]
 *   @0x251094 beq 0x25104c <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x251098 ldr r1, [r3, #0x8]
 *   @0x25109c ldr r2, [r3]
 *   @0x2510a0 cmp r1, #0
 *   @0x2510a4 streq r4, [r3, #0x8]
 *   @0x2510a8 add r2, r2, #1
 *   @0x2510ac str r2, [r3]
 *   @0x2510b0 b 0x25104c <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x2510b4 ldr r3, [sp, #0x10]
 *   @0x2510b8 cmp r3, #0
 *   @0x2510bc ldrne r2, [r3, #0x4]
 *   @0x2510c0 addne r2, r2, #1
 *   @0x2510c4 strne r2, [r3, #0x4]
 *   @0x2510c8 b 0x251048 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x1a0>
 *   @0x2510cc ldr r11, [r4]
 *   @0x2510d0 cmp r11, #0
 *   @0x2510d4 beq 0x2510f4 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x24c>
 *   @0x2510d8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x2510dc ldr r2, [r11, #0x4]
 *   @0x2510e0 sub r2, r2, #1
 *   @0x2510e4 str r2, [r11, #0x4]
 *   @0x2510e8 cmp r2, #0
 *   @0x2510ec beq 0x2510fc <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x254>
 *   @0x2510f0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x2510f4 str r7, [r4]
 *   @0x2510f8 b 0x250fe0 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x138>
 *   @0x2510fc ldr r0, [r11]
 *   @0x251100 str r2, [sp, #0xc]
 *   @0x251104 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x251108 ldr r2, [sp, #0xc]
 *   @0x25110c str r2, [r11]
 *   @0x251110 str r2, [r11, #0x8]
 *   @0x251114 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x251118 ldr r2, [r11, #0x4]
 *   @0x25111c sub r2, r2, #1
 *   @0x251120 str r2, [r11, #0x4]
 *   @0x251124 cmp r2, #0
 *   @0x251128 beq 0x251168 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x2c0>
 *   @0x25112c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x251130 mov r0, r11
 *   @0x251134 bl 0x27d1d0 <_ZdlPv>
 *   @0x251138 b 0x2510f0 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x248>
 *   @0x25113c bl 0xd3a34 <_Z15PopContextStackv>
 *   @0x251140 add sp, sp, #92
 *   @0x251144 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x251148 mov r0, r4
 *   @0x25114c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x251150 b 0x250fd4 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x251154 mov r0, r9
 *   @0x251158 mov r1, r5
 *   @0x25115c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x251160 mov r4, r0
 *   @0x251164 b 0x250fa8 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x100>
 *   @0x251168 ldr r0, [r11]
 *   @0x25116c str r2, [sp, #0xc]
 *   @0x251170 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x251174 ldr r2, [sp, #0xc]
 *   @0x251178 str r2, [r11]
 *   @0x25117c str r2, [r11, #0x8]
 *   @0x251180 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x251184 ldr r2, [r11, #0x4]
 *   @0x251188 sub r2, r2, #1
 *   @0x25118c str r2, [r11, #0x4]
 *   @0x251190 cmp r2, #0
 *   @0x251194 beq 0x2511a8 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x300>
 *   @0x251198 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x25119c mov r0, r11
 *   @0x2511a0 bl 0x27d1d0 <_ZdlPv>
 *   @0x2511a4 b 0x25112c <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x284>
 *   @0x2511a8 ldr r0, [r11]
 *   @0x2511ac str r2, [sp, #0xc]
 *   @0x2511b0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x2511b4 ldr r2, [sp, #0xc]
 *   @0x2511b8 str r2, [r11]
 *   @0x2511bc str r2, [r11, #0x8]
 *   @0x2511c0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x2511c4 ldr r2, [r11, #0x4]
 *   @0x2511c8 sub r2, r2, #1
 *   @0x2511cc str r2, [r11, #0x4]
 *   @0x2511d0 cmp r2, #0
 *   @0x2511d4 bne 0x251200 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x358>
 *   @0x2511d8 ldr r0, [r11]
 *   @0x2511dc str r2, [sp, #0xc]
 *   @0x2511e0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x2511e4 ldr r2, [sp, #0xc]
 *   @0x2511e8 mov r0, r11
 *   @0x2511ec str r2, [r11]
 *   @0x2511f0 str r2, [r11, #0x8]
 *   @0x2511f4 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x2511f8 mov r0, r11
 *   @0x2511fc bl 0x27d1d0 <_ZdlPv>
 *   @0x251200 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x251204 mov r0, r11
 *   @0x251208 bl 0x27d1d0 <_ZdlPv>
 *   @0x25120c b 0x251198 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x2f0>
 *   @0x251210 mov r1, #1
 *   @0x251214 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x251218 b 0x250f54 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x25121c andseq r5, r0, r12, rrx
 *
 * ══ §25/36 JS_String_prototype_lastIndexOf(RValue&, CInstance*, CInstance*, int, RValue*)  0x257e7c  size 880  220 条（0x257e7c..0x2581ec）
 * @func 0x257e7c 0x2581ec  size 880  220 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CodepointToUTF16(int, unsigned short&, unsigned short&)×4 / CCodepointIterator_UTF8::GetNext()×4 / F_JS_ToString(RValue&, RValue*)×2 / CCodepointIterator_UTF8::CCodepointIterator_UTF8(char const*)×2 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / 0xb65b0×2 / CCodepointIterator_UTF8::Reset()×2 / MemoryManager::Free(void const*)×2
 * 字段偏移 top8: 0x4×5 / 0x44×3 / 0x54×3 / 0x8×2 / 0xc×2 / 0x40×2 / 0x38×2 / 0x10×2
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x257e7c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x257e80 sub sp, sp, #92
 *   @0x257e84 add r4, sp, #88
 *   @0x257e88 str r0, [sp, #0x4]
 *   @0x257e8c str r1, [r4, #-0x30]!
 *   @0x257e90 mov r0, r4
 *   @0x257e94 str r3, [sp, #0x8]
 *   @0x257e98 mov r3, #6
 *   @0x257e9c str r3, [sp, #0x34]
 *   @0x257ea0 bl 0x2423a4 <_Z23JS_CheckObjectCoercibleR6RValue>
 *   @0x257ea4 cmp r0, #1
 *   @0x257ea8 beq 0x2581b4 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x338>
 *   @0x257eac add r12, sp, #56
 *   @0x257eb0 ldr lr, [sp, #0x4]
 *   @0x257eb4 str r12, [sp, #0xc]
 *   @0x257eb8 mov r3, #0
 *   @0x257ebc mov r0, r12
 *   @0x257ec0 ldr r12, [sp, #0x4]
 *   @0x257ec4 mov r10, r3
 *   @0x257ec8 mov r1, r4
 *   @0x257ecc movt r3, #0xbff0
 *   @0x257ed0 mov r2, #0
 *   @0x257ed4 str r3, [r12, #0x4]
 *   @0x257ed8 mov r3, #0
 *   @0x257edc str r10, [r12, #0xc]
 *   @0x257ee0 mvn r12, #-16777216
 *   @0x257ee4 str r10, [lr]
 *   @0x257ee8 add r9, sp, #72
 *   @0x257eec strd r2, r3, [sp, #56]
 *   @0x257ef0 add r4, sp, #28
 *   @0x257ef4 str r10, [sp, #0x40]
 *   @0x257ef8 add r5, sp, #26
 *   @0x257efc str r12, [sp, #0x44]
 *   @0x257f00 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x257f04 ldr r3, [sp, #0x38]
 *   @0x257f08 mov r0, r9
 *   @0x257f0c ldr r1, [r3]
 *   @0x257f10 bl 0x2423d8 <_ZN23CCodepointIterator_UTF8C2EPKc>
 *   @0x257f14 b 0x257f20 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x257f18 bl 0x2424c4 <_Z16CodepointToUTF16iRtS_>
 *   @0x257f1c add r10, r10, r0
 *   @0x257f20 mov r0, r9
 *   @0x257f24 bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv>
 *   @0x257f28 mov r1, r5
 *   @0x257f2c mov r2, r4
 *   @0x257f30 subs r6, r0, #0
 *   @0x257f34 bne 0x257f18 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x257f38 lsl r5, r10, #1
 *   @0x257f3c ldr r1, [pc, #0x29c]
 *   @0x257f40 mov r3, #1
 *   @0x257f44 mov r2, #70
 *   @0x257f48 add r1, pc, r1
 *   @0x257f4c mov r0, r5
 *   @0x257f50 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x257f54 add r8, sp, #26
 *   @0x257f58 mov r1, r6
 *   @0x257f5c mov r2, r5
 *   @0x257f60 mov r7, r0
 *   @0x257f64 bl 0xb65b0 <memset@plt>
 *   @0x257f68 mov r0, r9
 *   @0x257f6c bl 0x2423fc <_ZN23CCodepointIterator_UTF85ResetEv>
 *   @0x257f70 str r10, [sp, #0x10]
 *   @0x257f74 mov r0, r9
 *   @0x257f78 bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv>
 *   @0x257f7c mov r1, r8
 *   @0x257f80 mov r2, r4
 *   @0x257f84 subs r5, r0, #0
 *   @0x257f88 beq 0x257fb4 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x138>
 *   @0x257f8c bl 0x2424c4 <_Z16CodepointToUTF16iRtS_>
 *   @0x257f90 ldrh r2, [sp, #26]
 *   @0x257f94 lsl r3, r6, #1
 *   @0x257f98 strh r2, [r7, r3]
 *   @0x257f9c cmp r0, #2
 *   @0x257fa0 add r6, r6, r0
 *   @0x257fa4 ldrheq r2, [sp, #28]
 *   @0x257fa8 addeq r3, r7, r3
 *   @0x257fac strheq r2, [r3, #2]
 *   @0x257fb0 b 0x257f74 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0xf8>
 *   @0x257fb4 ldr r1, [sp, #0x80]
 *   @0x257fb8 mov r0, r9
 *   @0x257fbc mov r2, #0
 *   @0x257fc0 str r5, [sp, #0x50]
 *   @0x257fc4 mov r3, #0
 *   @0x257fc8 strd r2, r3, [sp, #72]
 *   @0x257fcc mvn r3, #-16777216
 *   @0x257fd0 str r3, [sp, #0x54]
 *   @0x257fd4 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x257fd8 ldr r3, [sp, #0x48]
 *   @0x257fdc mov r0, r4
 *   @0x257fe0 add r11, sp, #24
 *   @0x257fe4 add r8, sp, #26
 *   @0x257fe8 ldr r1, [r3]
 *   @0x257fec bl 0x2423d8 <_ZN23CCodepointIterator_UTF8C2EPKc>
 *   @0x257ff0 b 0x257ffc <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x180>
 *   @0x257ff4 bl 0x2424c4 <_Z16CodepointToUTF16iRtS_>
 *   @0x257ff8 add r5, r5, r0
 *   @0x257ffc mov r0, r4
 *   @0x258000 bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv>
 *   @0x258004 mov r1, r11
 *   @0x258008 mov r2, r8
 *   @0x25800c subs r6, r0, #0
 *   @0x258010 bne 0x257ff4 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x178>
 *   @0x258014 lsl r11, r5, #1
 *   @0x258018 ldr r1, [pc, #0x1c4]
 *   @0x25801c mov r3, #1
 *   @0x258020 mov r2, #70
 *   @0x258024 add r1, pc, r1
 *   @0x258028 mov r0, r11
 *   @0x25802c add r12, sp, #24
 *   @0x258030 str r12, [sp]
 *   @0x258034 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x258038 mov r2, r11
 *   @0x25803c mov r1, r6
 *   @0x258040 add r11, sp, #26
 *   @0x258044 mov r8, r0
 *   @0x258048 bl 0xb65b0 <memset@plt>
 *   @0x25804c mov r0, r4
 *   @0x258050 bl 0x2423fc <_ZN23CCodepointIterator_UTF85ResetEv>
 *   @0x258054 ldr r12, [sp]
 *   @0x258058 str r10, [sp, #0x14]
 *   @0x25805c mov r10, r12
 *   @0x258060 mov r0, r4
 *   @0x258064 bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv>
 *   @0x258068 mov r1, r10
 *   @0x25806c mov r2, r11
 *   @0x258070 cmp r0, #0
 *   @0x258074 beq 0x2580a0 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x224>
 *   @0x258078 bl 0x2424c4 <_Z16CodepointToUTF16iRtS_>
 *   @0x25807c ldrh r2, [sp, #24]
 *   @0x258080 lsl r3, r6, #1
 *   @0x258084 strh r2, [r8, r3]
 *   @0x258088 cmp r0, #2
 *   @0x25808c add r6, r6, r0
 *   @0x258090 ldrheq r2, [sp, #26]
 *   @0x258094 addeq r3, r8, r3
 *   @0x258098 strheq r2, [r3, #2]
 *   @0x25809c b 0x258060 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x1e4>
 *   @0x2580a0 ldr r12, [sp, #0x8]
 *   @0x2580a4 ldr r10, [sp, #0x14]
 *   @0x2580a8 cmp r12, #1
 *   @0x2580ac ble 0x2580c8 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x24c>
 *   @0x2580b0 ldr r12, [sp, #0x80]
 *   @0x2580b4 add r0, r12, #16
 *   @0x2580b8 bl 0x24d730 <_Z14F_JS_ToIntegerR6RValue>
 *   @0x2580bc vmov d7, r0, r1
 *   @0x2580c0 vcvt.s32.f64 s15, d7
 *   @0x2580c4 vmov r10, s15
 *   @0x2580c8 ldr r12, [sp, #0x10]
 *   @0x2580cc rsb r3, r5, r12
 *   @0x2580d0 cmp r10, r3
 *   @0x2580d4 movge r10, r3
 *   @0x2580d8 add r10, r7, r10, lsl #1
 *   @0x2580dc cmp r10, r7
 *   @0x2580e0 bhs 0x2580f4 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x278>
 *   @0x2580e4 b 0x2581a8 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x32c>
 *   @0x2580e8 sub r10, r10, #2
 *   @0x2580ec cmp r10, r7
 *   @0x2580f0 blo 0x2581a8 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x32c>
 *   @0x2580f4 mov r0, r10
 *   @0x2580f8 mov r1, r8
 *   @0x2580fc mov r2, r5
 *   @0x258100 bl 0xb6c40 <memcmp@plt>
 *   @0x258104 cmp r0, #0
 *   @0x258108 bne 0x2580e8 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x26c>
 *   @0x25810c rsb r10, r7, r10
 *   @0x258110 ldr r1, [sp, #0x44]
 *   @0x258114 ldr r12, [sp, #0x4]
 *   @0x258118 asr r10, r10, #1
 *   @0x25811c sub r1, r1, #1
 *   @0x258120 bic r1, r1, #-16777216
 *   @0x258124 vmov s15, r10
 *   @0x258128 bic r1, r1, #3
 *   @0x25812c cmp r1, #0
 *   @0x258130 vcvt.f64.s32 d7, s15
 *   @0x258134 vmov r2, r3, d7
 *   @0x258138 stm r12, {r2, r3}
 *   @0x25813c beq 0x2581c8 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x34c>
 *   @0x258140 ldr r1, [sp, #0x54]
 *   @0x258144 mov r3, #0
 *   @0x258148 str r3, [sp, #0x40]
 *   @0x25814c mov r2, #5
 *   @0x258150 sub r1, r1, #1
 *   @0x258154 str r3, [sp, #0x38]
 *   @0x258158 bic r3, r1, #-16777216
 *   @0x25815c str r2, [sp, #0x44]
 *   @0x258160 bic r3, r3, #3
 *   @0x258164 cmp r3, #0
 *   @0x258168 beq 0x2581d4 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x358>
 *   @0x25816c cmp r8, #0
 *   @0x258170 mov r3, #0
 *   @0x258174 mov r2, #5
 *   @0x258178 str r3, [sp, #0x50]
 *   @0x25817c str r3, [sp, #0x48]
 *   @0x258180 str r2, [sp, #0x54]
 *   @0x258184 beq 0x258190 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x314>
 *   @0x258188 mov r0, r8
 *   @0x25818c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x258190 cmp r7, #0
 *   @0x258194 beq 0x2581a0 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x324>
 *   @0x258198 mov r0, r7
 *   @0x25819c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2581a0 add sp, sp, #92
 *   @0x2581a4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2581a8 cmp r8, #0
 *   @0x2581ac bne 0x258188 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x30c>
 *   @0x2581b0 b 0x258190 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x314>
 *   @0x2581b4 ldr r0, [pc, #0x2c]
 *   @0x2581b8 add r0, pc, r0
 *   @0x2581bc bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x2581c0 add sp, sp, #92
 *   @0x2581c4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2581c8 add r0, sp, #56
 *   @0x2581cc bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x2581d0 b 0x258140 <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x2c4>
 *   @0x2581d4 mov r0, r9
 *   @0x2581d8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x2581dc b 0x25816c <_Z31JS_String_prototype_lastIndexOfR6RValueP9CInstanceS2_iPS_+0x2f0>
 *   @0x2581e0 andeq r9, sp, r8, ror #1
 *   @0x2581e4 andeq r9, sp, r12
 *   @0x2581e8 muleq pc, r0, sp
 *
 * ══ §26/36 yySocket::Connect(char*, int)  0x295858  size 880  220 条（0x295858..0x295bc8）
 * @func 0x295858 0x295bd8  size 896  224 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6e5c×3 / 0xb6d78×3 / 0xb6bf8×3 / yySocket::Resolve(char*)×2 / 0xb6e50 / 0xb6e08 / 0xb6964 / 0xb6da8
 * 字段偏移 top8: 0xc×4 / 0xc4×2 / 0xac×2 / 0x2×2 / 0x334×1 / 0x308×1 / 0x18×1 / 0x2d4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x295858 ldrb r3, [r0, #0xc4]
 *   @0x29585c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x295860 cmp r3, #0
 *   @0x295864 ldr r6, [pc, #0x334]
 *   @0x295868 mov r4, r0
 *   @0x29586c sub sp, sp, #156
 *   @0x295870 str r2, [r4, #0xac]
 *   @0x295874 mov r7, r2
 *   @0x295878 mov r0, r1
 *   @0x29587c add r6, pc, r6
 *   @0x295880 beq 0x295914 <_ZN8yySocket7ConnectEPci+0xbc>
 *   @0x295884 bl 0x2954a8 <_ZN8yySocket7ResolveEPc>
 *   @0x295888 subs r5, r0, #0
 *   @0x29588c beq 0x295af0 <_ZN8yySocket7ConnectEPci+0x298>
 *   @0x295890 rev16 r7, r7
 *   @0x295894 ldr r0, [pc, #0x308]
 *   @0x295898 add r8, r4, #108
 *   @0x29589c strh r7, [r5, #2]
 *   @0x2958a0 add r0, pc, r0
 *   @0x2958a4 bl 0xb6e50 <if_nametoindex@plt>
 *   @0x2958a8 mov r2, r8
 *   @0x2958ac add r1, r5, #8
 *   @0x2958b0 mov r3, #64
 *   @0x2958b4 str r0, [r5, #0x18]
 *   @0x2958b8 mov r0, #10
 *   @0x2958bc bl 0xb6e08 <inet_ntop@plt>
 *   @0x2958c0 cmp r0, #0
 *   @0x2958c4 moveq r8, #28
 *   @0x2958c8 beq 0x295948 <_ZN8yySocket7ConnectEPci+0xf0>
 *   @0x2958cc ldr r0, [pc, #0x2d4]
 *   @0x2958d0 mov r1, r8
 *   @0x2958d4 mov r8, #28
 *   @0x2958d8 add r0, pc, r0
 *   @0x2958dc bl 0xb6964 <printf@plt>
 *   @0x2958e0 ldr r0, [r4]
 *   @0x2958e4 cmn r0, #1
 *   @0x2958e8 bne 0x295954 <_ZN8yySocket7ConnectEPci+0xfc>
 *   @0x2958ec ldrb r0, [r4, #0xc4]
 *   @0x2958f0 mov r1, #1
 *   @0x2958f4 mov r2, #6
 *   @0x2958f8 cmp r0, #0
 *   @0x2958fc moveq r0, #2
 *   @0x295900 movne r0, #10
 *   @0x295904 bl 0xb6da8 <socket@plt>
 *   @0x295908 mov r3, r0
 *   @0x29590c str r3, [r4]
 *   @0x295910 b 0x295954 <_ZN8yySocket7ConnectEPci+0xfc>
 *   @0x295914 bl 0x2954a8 <_ZN8yySocket7ResolveEPc>
 *   @0x295918 subs r5, r0, #0
 *   @0x29591c beq 0x295af0 <_ZN8yySocket7ConnectEPci+0x298>
 *   @0x295920 mov r3, r7
 *   @0x295924 rev16 r3, r3
 *   @0x295928 strh r3, [r5, #2]
 *   @0x29592c mov r8, #16
 *   @0x295930 ldr r0, [r5, #0x4]
 *   @0x295934 bl 0xb6e14 <inet_ntoa@plt>
 *   @0x295938 mov r1, r0
 *   @0x29593c add r0, r4, #108
 *   @0x295940 bl 0xb65a4 <strcpy@plt>
 *   @0x295944 str r7, [r4, #0xac]
 *   @0x295948 ldr r0, [r4]
 *   @0x29594c cmn r0, #1
 *   @0x295950 beq 0x2958ec <_ZN8yySocket7ConnectEPci+0x94>
 *   @0x295954 mov r1, #3
 *   @0x295958 mov r2, #0
 *   @0x29595c bl 0xb6e5c <fcntl@plt>
 *   @0x295960 mov r1, #4
 *   @0x295964 orr r2, r0, #2048
 *   @0x295968 mov r9, r0
 *   @0x29596c ldr r0, [r4]
 *   @0x295970 bl 0xb6e5c <fcntl@plt>
 *   @0x295974 mov r2, r8
 *   @0x295978 ldr r0, [r4]
 *   @0x29597c mov r1, r5
 *   @0x295980 bl 0xb6e68 <connect@plt>
 *   @0x295984 ldr r3, [pc, #0x220]
 *   @0x295988 ldr r7, [r6, r3]
 *   @0x29598c cmn r0, #1
 *   @0x295990 mov r8, r0
 *   @0x295994 str r0, [r7]
 *   @0x295998 beq 0x295b04 <_ZN8yySocket7ConnectEPci+0x2ac>
 *   @0x29599c ldr r3, [pc, #0x20c]
 *   @0x2959a0 ldr r3, [r6, r3]
 *   @0x2959a4 ldrb r8, [r3]
 *   @0x2959a8 cmp r8, #0
 *   @0x2959ac bne 0x295a84 <_ZN8yySocket7ConnectEPci+0x22c>
 *   @0x2959b0 add r10, sp, #24
 *   @0x2959b4 mov r1, r8
 *   @0x2959b8 mov r2, #128
 *   @0x2959bc mov r11, #1
 *   @0x2959c0 mov r0, r10
 *   @0x2959c4 bl 0xb65b0 <memset@plt>
 *   @0x2959c8 ldr r0, [r4]
 *   @0x2959cc mov r1, r8
 *   @0x2959d0 movw lr, #0x4dd3
 *   @0x2959d4 and r2, r0, #31
 *   @0x2959d8 movt lr, #0x1062
 *   @0x2959dc asr r3, r0, #5
 *   @0x2959e0 lsl r11, r11, r2
 *   @0x2959e4 add r2, sp, #152
 *   @0x2959e8 mov r12, #1000
 *   @0x2959ec add r3, r2, r3, lsl #2
 *   @0x2959f0 mov r2, r10
 *   @0x2959f4 add r10, sp, #16
 *   @0x2959f8 add r0, r0, #1
 *   @0x2959fc str r11, [r3, #-0x80]
 *   @0x295a00 mov r3, r8
 *   @0x295a04 ldr r8, [pc, #0x1a8]
 *   @0x295a08 ldr r8, [r6, r8]
 *   @0x295a0c str r10, [sp]
 *   @0x295a10 ldr r8, [r8]
 *   @0x295a14 smull r10, lr, lr, r8
 *   @0x295a18 asr r10, r8, #31
 *   @0x295a1c rsb lr, r10, lr, asr #6
 *   @0x295a20 str lr, [sp, #0x10]
 *   @0x295a24 mls lr, r12, lr, r8
 *   @0x295a28 mul r12, r12, lr
 *   @0x295a2c str r12, [sp, #0x14]
 *   @0x295a30 bl 0xb6d84 <select@plt>
 *   @0x295a34 cmp r0, #1
 *   @0x295a38 mov r12, r0
 *   @0x295a3c beq 0x295b60 <_ZN8yySocket7ConnectEPci+0x308>
 *   @0x295a40 cmp r0, #0
 *   @0x295a44 ldr r3, [pc, #0x16c]
 *   @0x295a48 bne 0x295aa8 <_ZN8yySocket7ConnectEPci+0x250>
 *   @0x295a4c ldr r3, [r6, r3]
 *   @0x295a50 ldr r1, [pc, #0x164]
 *   @0x295a54 ldr r0, [r3]
 *   @0x295a58 add r1, pc, r1
 *   @0x295a5c ldr r3, [r0]
 *   @0x295a60 ldr r3, [r3, #0xc]
 *   @0x295a64 blx r3
 *   @0x295a68 ldr r0, [r4]
 *   @0x295a6c bl 0xb6d78 <close@plt>
 *   @0x295a70 mvn r2, #0
 *   @0x295a74 mvn r3, #4
 *   @0x295a78 str r2, [r4]
 *   @0x295a7c str r3, [r7]
 *   @0x295a80 b 0x295a94 <_ZN8yySocket7ConnectEPci+0x23c>
 *   @0x295a84 mov r3, #1
 *   @0x295a88 strb r3, [r4, #0x2d]
 *   @0x295a8c bl 0x215148 <Timing_Time>
 *   @0x295a90 strd r0, r1, [r4, #64]
 *   @0x295a94 mov r0, r5
 *   @0x295a98 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x295a9c ldr r0, [r7]
 *   @0x295aa0 add sp, sp, #156
 *   @0x295aa4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x295aa8 ldr r3, [r6, r3]
 *   @0x295aac ldr r6, [r3]
 *   @0x295ab0 ldr r3, [r6]
 *   @0x295ab4 ldr r8, [r3, #0xc]
 *   @0x295ab8 bl 0xb6bf8 <__errno@plt>
 *   @0x295abc ldr r1, [pc, #0xfc]
 *   @0x295ac0 add r1, pc, r1
 *   @0x295ac4 mov r3, r0
 *   @0x295ac8 mov r0, r6
 *   @0x295acc ldr r2, [r3]
 *   @0x295ad0 blx r8
 *   @0x295ad4 ldr r0, [r4]
 *   @0x295ad8 bl 0xb6d78 <close@plt>
 *   @0x295adc mvn r2, #0
 *   @0x295ae0 mvn r3, #5
 *   @0x295ae4 str r2, [r4]
 *   @0x295ae8 str r3, [r7]
 *   @0x295aec b 0x295a94 <_ZN8yySocket7ConnectEPci+0x23c>
 *   @0x295af0 ldr r3, [pc, #0xb4]
 *   @0x295af4 ldr r3, [r6, r3]
 *   @0x295af8 ldr r0, [r3]
 *   @0x295afc add sp, sp, #156
 *   @0x295b00 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x295b04 bl 0xb6bf8 <__errno@plt>
 *   @0x295b08 ldr r3, [r0]
 *   @0x295b0c cmp r3, #115
 *   @0x295b10 beq 0x295b54 <_ZN8yySocket7ConnectEPci+0x2fc>
 *   @0x295b14 ldr r3, [pc, #0x9c]
 *   @0x295b18 ldr r3, [r6, r3]
 *   @0x295b1c ldr r6, [r3]
 *   @0x295b20 ldr r3, [r6]
 *   @0x295b24 ldr r9, [r3, #0xc]
 *   @0x295b28 bl 0xb6bf8 <__errno@plt>
 *   @0x295b2c ldr r1, [pc, #0x90]
 *   @0x295b30 add r1, pc, r1
 *   @0x295b34 mov r3, r0
 *   @0x295b38 mov r0, r6
 *   @0x295b3c ldr r2, [r3]
 *   @0x295b40 blx r9
 *   @0x295b44 ldr r0, [r4]
 *   @0x295b48 bl 0xb6d78 <close@plt>
 *   @0x295b4c str r8, [r4]
 *   @0x295b50 b 0x295a94 <_ZN8yySocket7ConnectEPci+0x23c>
 *   @0x295b54 mov r3, #0
 *   @0x295b58 str r3, [r7]
 *   @0x295b5c b 0x29599c <_ZN8yySocket7ConnectEPci+0x144>
 *   @0x295b60 ldr r0, [r4]
 *   @0x295b64 add r3, sp, #12
 *   @0x295b68 mov r1, r12
 *   @0x295b6c str r3, [sp]
 *   @0x295b70 mov r2, #4
 *   @0x295b74 add r3, sp, #11
 *   @0x295b78 str r12, [sp, #0xc]
 *   @0x295b7c bl 0xb6d90 <getsockopt@plt>
 *   @0x295b80 ldrb r3, [sp, #0xb]
 *   @0x295b84 cmp r3, #0
 *   @0x295b88 bne 0x295a94 <_ZN8yySocket7ConnectEPci+0x23c>
 *   @0x295b8c ldr r0, [r4]
 *   @0x295b90 mov r2, r9
 *   @0x295b94 mov r1, #4
 *   @0x295b98 bl 0xb6e5c <fcntl@plt>
 *   @0x295b9c b 0x295a94 <_ZN8yySocket7ConnectEPci+0x23c>
 *   @0x295ba0 ldrsbeq r12, [r5], -r4
 *   @0x295ba4 andeq r3, r12, r8, asr #20
 *   @0x295ba8 andeq r3, r12, r4, lsl r10
 *   @0x295bac .word 0xfffffd40
 *   @0x295bb0 .word 0xfffffd44
 *   @0x295bb4 .word 0xfffffd3c
 *   @0x295bb8 .word 0xffffbac4
 *   @0x295bbc andeq r3, r12, r8, asr #17
 *   @0x295bc0 andeq r3, r12, r12, ror r8
 *   @0x295bc4 ldrdeq r3, r4, [r12], -r4
 *
 * ══ §27/36 png_do_read_transformations  0x2aa92c  size 880  220 条（0x2aa92c..0x2aac9c）
 * @func 0x2aa92c 0x2aac9c  size 880  220 条
 * 部分覆盖: 本节 220/360 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_error×4 / 0xb65c8 / png_do_rgb_to_gray / png_warning / png_do_gamma / png_do_quantize / png_do_unshift / png_do_bgr
 * 字段偏移 top8: 0x54×2 / 0x354×1 / 0xc×1 / 0x14×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2aa92c ldr r3, [pc, #0x354]
 *   @0x2aa930 add r3, pc
 *   @0x2aa934 sub sp, #0x58
 *   @0x2aa938 ldr r2, [r3]
 *   @0x2aa93c str r2, [sp, #0x54]
 *   @0x2aa940 ldmdblt r10!, {r4, r5, r7, r8, sp} ^
 *   @0x2aa944 ldrb.w r3, [r0, #0x1e8]
 *   @0x2aa948 add r5, sp, #0x20
 *   @0x2aa94c movs r1, #0x32
 *   @0x2aa950 str r3, [sp]
 *   @0x2aa954 ldr.w r3, [r4, #0x1a8]
 *   @0x2aa958 blx 0xb65c8 <snprintf@plt>
 *   @0x2aa95c mov r0, r4
 *   @0x2aa960 bl 0x2a642c <png_error>
 *   @0x2aa964 ldr.w r3, [r4, #0x134]
 *   @0x2aa968 lsls r1, r3, #0x13
 *   @0x2aa96c ldrb.w r2, [r4, #0x1cc]
 *   @0x2aa970 add.w r5, r4, #0x1c4
 *   @0x2aa974 cmp r2, #0x3
 *   @0x2aa978 ldr.w r3, [r4, #0x1d8]
 *   @0x2aa97c cbnz r3, 0x2aa988 <png_do_read_transformations+0x5c>
 *   @0x2aa980 mov r0, r4
 *   @0x2aa984 bl 0x2a642c <png_error>
 *   @0x2aa988 ldrh.w r3, [r4, #0x1de]
 *   @0x2aa98c mov r0, r5
 *   @0x2aa990 .word 0xf8d411b0
 *   @0x2aa994 movwls r2, #0x1d8
 *   @0x2aa998 adds r1, #0x1
 *   @0x2aa99c .word 0xf7ff324c
 *   @0x2aa9a0 .word 0xe00efcfb
 *   @0x2aa9a4 ldr.w r1, [r4, #0x1b0]
 *   @0x2aa9a8 mov r0, r5
 *   @0x2aa9ac ldrdlo r2, r3, [r1, -lr]
 *   @0x2aa9b0 cbz r2, 0x2aa9bc <png_do_read_transformations+0x90>
 *   @0x2aa9b4 bpl 0x2aa9bc <png_do_read_transformations+0x90>
 *   @0x2aa9b8 and r7, r0, r4, lsl r2
 *   @0x2aa9bc movs r2, #0x0
 *   @0x2aa9c0 .word 0xf8d4fdbd
 *   @0x2aa9c4 .word 0xf4122130
 *   @0x2aa9c8 andle r0, r8, r0, lsl #5
 *   @0x2aa9cc ldr.w r1, [r4, #0x1b0]
 *   @0x2aa9d0 add.w r0, r4, #0x1c4
 *   @0x2aa9d4 orr r2, r2, #0x80
 *   @0x2aa9d8 adds r1, #0x1
 *   @0x2aa9dc .word 0xf8d4ffa9
 *   @0x2aa9e0 .word 0xf4133134
 *   @0x2aa9e4 eorle r0, r3, r0, asr #31
 *   @0x2aa9e8 ldr.w r2, [r4, #0x1b0]
 *   @0x2aa9ec mov r0, r4
 *   @0x2aa9f0 andlo r7, r1, #-2147483592
 *   @0x2aa9f4 bl 0x2a91ac <png_do_rgb_to_gray>
 *   @0x2aa9f8 cbz r0, 0x2aaa30 <png_do_read_transformations+0x104>
 *   @0x2aa9fc strb.w r3, [r4, #0x2d4]
 *   @0x2aaa00 ldr.w r3, [r4, #0x134]
 *   @0x2aaa04 and r3, r3, #0x600000
 *   @0x2aaa08 cmp.w r3, #0x400000
 *   @0x2aaa0c bne 0x2aaa18 <png_do_read_transformations+0xec>
 *   @0x2aaa10 mov r0, r4
 *   @0x2aaa14 bl 0x2a6474 <png_warning>
 *   @0x2aaa18 ldr.w r3, [r4, #0x134]
 *   @0x2aaa1c and r3, r3, #0x600000
 *   @0x2aaa20 cmp.w r3, #0x200000
 *   @0x2aaa24 bne 0x2aaa30 <png_do_read_transformations+0x104>
 *   @0x2aaa28 mov r0, r4
 *   @0x2aaa2c bl 0x2a642c <png_error>
 *   @0x2aaa30 ldr.w r3, [r4, #0x134]
 *   @0x2aaa34 lsls r3, r3, #0x11
 *   @0x2aaa38 ldr.w r3, [r4, #0x12c]
 *   @0x2aaa3c lsls r5, r3, #0x14
 *   @0x2aaa40 ldr.w r1, [r4, #0x1b0]
 *   @0x2aaa44 add.w r0, r4, #0x1c4
 *   @0x2aaa48 adds r1, #0x1
 *   @0x2aaa4c .word 0xf8d4fb2f
 *   @0x2aaa50 sasxeq r3, r8, r4
 *   @0x2aaa54 bpl 0x2aaaaa <png_do_read_transformations+0x17e>
 *   @0x2aaa58 ldmdblt r11, {r1, r2, r3, r4, r6, r7, r8, r12, sp}
 *   @0x2aaa5c ldrb.w r3, [r4, #0x1ea]
 *   @0x2aaa60 lsls r1, r3, #0x1d
 *   @0x2aaa64 addw r3, r4, #0x206
 *   @0x2aaa68 str r3, [sp]
 *   @0x2aaa6c .word 0xf5043228
 *   @0x2aaa70 .word 0xf8d470e2
 *   @0x2aaa74 .word 0xf50411b0
 *   @0x2aaa78 movwls r7, #0x1214
 *   @0x2aaa7c adds r1, #0x1
 *   @0x2aaa80 movwls r3, #0x222c
 *   @0x2aaa84 ldr.w r3, [r4, #0x230]
 *   @0x2aaa88 str r3, [sp, #0xc]
 *   @0x2aaa8c movwls r3, #0x4234
 *   @0x2aaa90 ldr.w r3, [r4, #0x238]
 *   @0x2aaa94 str r3, [sp, #0x14]
 *   @0x2aaa98 movwls r3, #0x623c
 *   @0x2aaa9c ldr.w r3, [r4, #0x21c]
 *   @0x2aaaa0 str r3, [sp, #0x1c]
 *   @0x2aaaa4 .word 0xf7fe73fe
 *   @0x2aaaa8 .word 0xf8d4fdeb
 *   @0x2aaaac ldreq r3, [r10], #308
 *   @0x2aaab0 bpl 0x2aaae8 <png_do_read_transformations+0x1bc>
 *   @0x2aaab4 bpl 0x2aaac4 <png_do_read_transformations+0x198>
 *   @0x2aaab8 stmiblt r11!, {r1, r2, r3, r4, r6, r7, r8, r12, sp}
 *   @0x2aaabc ldrb.w r3, [r4, #0x1ea]
 *   @0x2aaac0 lsls r5, r3, #0x1d
 *   @0x2aaac4 ldrb.w r3, [r4, #0x1ea]
 *   @0x2aaac8 cmp r3, #0x3
 *   @0x2aaacc ldr.w r3, [r4, #0x21c]
 *   @0x2aaad0 add.w r0, r4, #0x1c4
 *   @0x2aaad4 ldr.w r1, [r4, #0x1b0]
 *   @0x2aaad8 ldr.w r2, [r4, #0x228]
 *   @0x2aaadc str r3, [sp]
 *   @0x2aaae0 ldr.w r3, [r4, #0x234]
 *   @0x2aaae4 bl 0x2aa0d6 <png_do_gamma>
 *   @0x2aaae8 ldr.w r3, [r4, #0x134]
 *   @0x2aaaec lsls r0, r3, #0x15
 *   @0x2aaaf0 ldr.w r1, [r4, #0x1b0]
 *   @0x2aaaf4 add.w r0, r4, #0x1c4
 *   @0x2aaaf8 adds r1, #0x1
 *   @0x2aaafc .word 0xf8d4f915
 *   @0x2aab00 uasxeq r3, r9, r4
 *   @0x2aab04 bpl 0x2aab2c <png_do_read_transformations+0x200>
 *   @0x2aab08 .word 0xf50411b0
 *   @0x2aab0c .word 0xf8d470e2
 *   @0x2aab10 strhlo r3, [r1, -r4]
 *   @0x2aab14 ldr.w r2, [r4, #0x2b0]
 *   @0x2aab18 bl 0x2aa854 <png_do_quantize>
 *   @0x2aab1c ldr.w r3, [r4, #0x1c8]
 *   @0x2aab20 cbnz r3, 0x2aab2c <png_do_read_transformations+0x200>
 *   @0x2aab24 mov r0, r4
 *   @0x2aab28 bl 0x2a642c <png_error>
 *   @0x2aab2c ldr.w r3, [r4, #0x134]
 *   @0x2aab30 lsls r2, r3, #0x1a
 *   @0x2aab34 ldr.w r1, [r4, #0x1b0]
 *   @0x2aab38 add.w r0, r4, #0x1c4
 *   @0x2aab3c adds r1, #0x1
 *   @0x2aab40 .word 0xf8d4fe8c
 *   @0x2aab44 .word 0x071b3134
 *   @0x2aab48 bpl 0x2aab5c <png_do_read_transformations+0x230>
 *   @0x2aab4c .word 0xf50411b0
 *   @0x2aab50 .word 0xf20470e2
 *   @0x2aab54 .word 0x31012245
 *   @0x2aab58 bl 0x2a8bf2 <png_do_unshift>
 *   @0x2aab5c ldr.w r3, [r4, #0x134]
 *   @0x2aab60 lsls r5, r3, #0x1d
 *   @0x2aab64 ldr.w r1, [r4, #0x1b0]
 *   @0x2aab68 add.w r0, r4, #0x1c4
 *   @0x2aab6c adds r1, #0x1
 *   @0x2aab70 .word 0xf8d4ffde
 *   @0x2aab74 .word 0x07d83134
 *   @0x2aab78 bpl 0x2aab88 <png_do_read_transformations+0x25c>
 *   @0x2aab7c .word 0xf50411b0
 *   @0x2aab80 smlattlo r1, r2, r0, r7
 *   @0x2aab84 bl 0x2afae8 <png_do_bgr>
 *   @0x2aab88 ldr.w r3, [r4, #0x134]
 *   @0x2aab8c lsls r1, r3, #0xf
 *   @0x2aab90 ldr.w r1, [r4, #0x1b0]
 *   @0x2aab94 add.w r0, r4, #0x1c4
 *   @0x2aab98 adds r1, #0x1
 *   @0x2aab9c .word 0xf8d4fea3
 *   @0x2aaba0 ldrbeq r3, [r10], #-308
 *   @0x2aaba4 bpl 0x2aabbc <png_do_read_transformations+0x290>
 *   @0x2aaba8 ldreq r3, [r11, #-0x12c]
 *   @0x2aabac bpl 0x2aabbc <png_do_read_transformations+0x290>
 *   @0x2aabb0 .word 0xf50411b0
 *   @0x2aabb4 smlattlo r1, r2, r0, r7
 *   @0x2aabb8 bl 0x2a90ac <png_do_gray_to_rgb>
 *   @0x2aabbc ldr.w r3, [r4, #0x134]
 *   @0x2aabc0 lsls r5, r3, #0x10
 *   @0x2aabc4 ldr.w r1, [r4, #0x1b0]
 *   @0x2aabc8 add.w r0, r4, #0x1c4
 *   @0x2aabcc ldrh.w r2, [r4, #0x1f2]
 *   @0x2aabd0 adds r1, #0x1
 *   @0x2aabd4 .word 0xf7fe3130
 *   @0x2aabd8 .word 0xf8d4f972
 *   @0x2aabdc tsteq r8, #52, #2
 *   @0x2aabe0 bpl 0x2aabf0 <png_do_read_transformations+0x2c4>
 *   @0x2aabe4 .word 0xf50411b0
 *   @0x2aabe8 smlattlo r1, r2, r0, r7
 *   @0x2aabec bl 0x2a8e3a <png_do_read_invert_alpha>
 *   @0x2aabf0 ldr.w r3, [r4, #0x134]
 *   @0x2aabf4 lsls r1, r3, #0xe
 *   @0x2aabf8 ldr.w r1, [r4, #0x1b0]
 *   @0x2aabfc add.w r0, r4, #0x1c4
 *   @0x2aac00 adds r1, #0x1
 *   @0x2aac04 .word 0xf8d4f8a9
 *   @0x2aac08 .word 0x06da3134
 *   @0x2aac0c bpl 0x2aac1c <png_do_read_transformations+0x2f0>
 *   @0x2aac10 .word 0xf50411b0
 *   @0x2aac14 smlattlo r1, r2, r0, r7
 *   @0x2aac18 bl 0x2af8b6 <png_do_swap>
 *   @0x2aac1c ldr.w r3, [r4, #0x134]
 *   @0x2aac20 lsls r3, r3, #0xb
 *   @0x2aac24 ldr.w r5, [r4, #0x11c]
 *   @0x2aac28 cbz r5, 0x2aac38 <png_do_read_transformations+0x30c>
 *   @0x2aac2c .word 0x462021b0
 *   @0x2aac30 add.w r1, r4, #0x1c4
 *   @0x2aac34 adds r2, #0x1
 *   @0x2aac38 ldrb.w r3, [r4, #0x128]
 *   @0x2aac3c cbz r3, 0x2aac42 <png_do_read_transformations+0x316>
 *   @0x2aac40 .word 0xf89431cd
 *   @0x2aac44 .word 0xb10b3129
 *   @0x2aac48 strb.w r3, [r4, #0x1ce]
 *   @0x2aac4c ldrb.w r2, [r4, #0x1ce]
 *   @0x2aac50 ldrb.w r3, [r4, #0x1cd]
 *   @0x2aac54 muls r3, r2, r3
 *   @0x2aac58 sbcslt r2, r11, #196, #2
 *   @0x2aac5c strb.w r3, [r4, #0x1cf]
 *   @0x2aac60 cmp r3, #0x7
 *   @0x2aac64 lsrs r3, r3, #0x3
 *   @0x2aac68 b 0x2aac70 <png_do_read_transformations+0x344>
 *   @0x2aac6c adds r2, #0x7
 *   @0x2aac70 str.w r2, [r4, #0x1c8]
 *   @0x2aac74 ldr r2, [sp, #0x54]
 *   @0x2aac78 cmp r2, r3
 *   @0x2aac7c blx 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2aac80 add sp, #0x58
 *   @0x2aac84 adds r0, #0x24
 *   @0x2aac88 movs r0, #0xf1
 *   @0x2aac8c movs r0, #0xe6
 *   @0x2aac90 movs r0, #0x77
 *   @0x2aac94 movs r0, #0x5f
 *   @0x2aac98 subs r2, r1, #0x6
 *
 * ══ §28/36 CInstance::Collision_Line(float, float, float, float, bool)  0x194f28  size 876  219 条（0x194f28..0x195294）
 * @func 0x194f28 0x195294  size 876  219 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8×6 / CInstance::SkeletonAnimation() / CSkeletonInstance::ComputeBoundingBox(tagYYRECT*, int, float, float, float, float, float) / CInstance::Collision_Line(float, float, float, float, bool)+0x174 / CInstance::Collision_Line(float, float, float, float, bool)+0x1d0 / CInstance::Collision_Line(float, float, float, float, bool)+0x200 / Sprite_Data(int) / CSkeletonInstance::LineCollision(int, float, float, float, float, float, float, float, float, float)
 * 字段偏移 top8: 0xa0×2 / 0xb8×2 / 0x98×2 / 0x9c×2 / 0xb4×2 / 0x4×2 / 0x8×2 / 0x18×2
 * VFP 指令 108 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x194f28 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x194f2c vpush {d8, d9, d10, d11}
 *   @0x194f30 sub sp, sp, #36
 *   @0x194f34 vldr s19, [sp, #104]
 *   @0x194f38 mov r4, r0
 *   @0x194f3c vmov s17, r3
 *   @0x194f40 vmov s16, r1
 *   @0x194f44 ldrb r7, [sp, #0x6c]
 *   @0x194f48 vmov s18, r2
 *   @0x194f4c bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv>
 *   @0x194f50 subs r8, r0, #0
 *   @0x194f54 ldrbeq r3, [r4, #0x64]
 *   @0x194f58 beq 0x194fc4 <_ZN9CInstance14Collision_LineEffffb+0x9c>
 *   @0x194f5c vldr s15, [r4, #144]
 *   @0x194f60 vcvt.s32.f32 s15, s15
 *   @0x194f64 ldr r5, [pc, #0x324]
 *   @0x194f68 ldr r1, [r4, #0xa0]
 *   @0x194f6c ldr r9, [r4, #0xb8]
 *   @0x194f70 ldr r5, [pc, r5]
 *   @0x194f74 ldr lr, [r4, #0x98]
 *   @0x194f78 ldr r12, [r4, #0x9c]
 *   @0x194f7c ldr r3, [r4, #0xb4]
 *   @0x194f80 ldr r6, [r5]
 *   @0x194f84 vmov r2, s15
 *   @0x194f88 str r4, [r5]
 *   @0x194f8c str r1, [sp, #0xc]
 *   @0x194f90 add r1, r4, #232
 *   @0x194f94 str r9, [sp]
 *   @0x194f98 str lr, [sp, #0x4]
 *   @0x194f9c str r12, [sp, #0x8]
 *   @0x194fa0 bl 0xbeda8 <_ZN17CSkeletonInstance18ComputeBoundingBoxEP9tagYYRECTifffff>
 *   @0x194fa4 str r6, [r5]
 *   @0x194fa8 cmp r0, #0
 *   @0x194fac ldrbeq r3, [r4, #0x64]
 *   @0x194fb0 movne r2, #0
 *   @0x194fb4 movne r3, r2
 *   @0x194fb8 movne r1, #1
 *   @0x194fbc strbne r2, [r4, #0x64]
 *   @0x194fc0 strbne r1, [r4, #0xb0]
 *   @0x194fc4 cmp r3, #0
 *   @0x194fc8 bne 0x1951c4 <_ZN9CInstance14Collision_LineEffffb+0x29c>
 *   @0x194fcc ldr r3, [r4, #0xf0]
 *   @0x194fd0 vcmpe.f32 s16, s17
 *   @0x194fd4 add r2, r3, #1
 *   @0x194fd8 vmov s15, r2
 *   @0x194fdc vmrs APSR_nzcv, fpscr
 *   @0x194fe0 vmovpl.f32 s14, s17
 *   @0x194fe4 vmovmi.f32 s14, s16
 *   @0x194fe8 vcvt.f32.s32 s15, s15
 *   @0x194fec vcmpe.f32 s14, s15
 *   @0x194ff0 vmrs APSR_nzcv, fpscr
 *   @0x194ff4 bge 0x1951b4 <_ZN9CInstance14Collision_LineEffffb+0x28c>
 *   @0x194ff8 vcmpe.f32 s16, s17
 *   @0x194ffc vldr s11, [r4, #232]
 *   @0x195000 vcvt.f32.s32 s14, s11
 *   @0x195004 vmrs APSR_nzcv, fpscr
 *   @0x195008 vmovle.f32 s13, s17
 *   @0x19500c vmovgt.f32 s13, s16
 *   @0x195010 vcmpe.f32 s13, s14
 *   @0x195014 vmrs APSR_nzcv, fpscr
 *   @0x195018 bmi 0x1951b4 <_ZN9CInstance14Collision_LineEffffb+0x28c>
 *   @0x19501c ldr r2, [r4, #0xf4]
 *   @0x195020 vcmpe.f32 s18, s19
 *   @0x195024 add r2, r2, #1
 *   @0x195028 vmov s12, r2
 *   @0x19502c vmrs APSR_nzcv, fpscr
 *   @0x195030 vcvt.f32.s32 s13, s12
 *   @0x195034 vmovpl.f32 s12, s19
 *   @0x195038 vmovmi.f32 s12, s18
 *   @0x19503c vcmpe.f32 s12, s13
 *   @0x195040 vmrs APSR_nzcv, fpscr
 *   @0x195044 bge 0x1951b4 <_ZN9CInstance14Collision_LineEffffb+0x28c>
 *   @0x195048 vcmpe.f32 s18, s19
 *   @0x19504c vldr s11, [r4, #236]
 *   @0x195050 vcvt.f32.s32 s12, s11
 *   @0x195054 vmrs APSR_nzcv, fpscr
 *   @0x195058 vmovle.f32 s11, s19
 *   @0x19505c vmovgt.f32 s11, s18
 *   @0x195060 vcmpe.f32 s11, s12
 *   @0x195064 vmrs APSR_nzcv, fpscr
 *   @0x195068 bmi 0x1951b4 <_ZN9CInstance14Collision_LineEffffb+0x28c>
 *   @0x19506c ldrb r2, [r4, #0x68]
 *   @0x195070 cmp r2, #0
 *   @0x195074 bne 0x1951b4 <_ZN9CInstance14Collision_LineEffffb+0x28c>
 *   @0x195078 vcmpe.f32 s16, s17
 *   @0x19507c vmrs APSR_nzcv, fpscr
 *   @0x195080 ble 0x19509c <_ZN9CInstance14Collision_LineEffffb+0x174>
 *   @0x195084 vmov.f32 s10, s18
 *   @0x195088 vmov.f32 s11, s16
 *   @0x19508c vmov.f32 s18, s19
 *   @0x195090 vmov.f32 s16, s17
 *   @0x195094 vmov.f32 s19, s10
 *   @0x195098 vmov.f32 s17, s11
 *   @0x19509c vcmpe.f32 s16, s14
 *   @0x1950a0 vmrs APSR_nzcv, fpscr
 *   @0x1950a4 bpl 0x1950c4 <_ZN9CInstance14Collision_LineEffffb+0x19c>
 *   @0x1950a8 vsub.f32 s10, s14, s16
 *   @0x1950ac vsub.f32 s11, s19, s18
 *   @0x1950b0 vmul.f32 s10, s10, s11
 *   @0x1950b4 vsub.f32 s11, s17, s16
 *   @0x1950b8 vmov.f32 s16, s14
 *   @0x1950bc vdiv.f32 s14, s10, s11
 *   @0x1950c0 vadd.f32 s18, s18, s14
 *   @0x1950c4 vcmpe.f32 s17, s15
 *   @0x1950c8 vmrs APSR_nzcv, fpscr
 *   @0x1950cc ble 0x1950f8 <_ZN9CInstance14Collision_LineEffffb+0x1d0>
 *   @0x1950d0 vsub.f32 s15, s15, s17
 *   @0x1950d4 vmov s11, r3
 *   @0x1950d8 vsub.f32 s14, s19, s18
 *   @0x1950dc vmul.f32 s14, s15, s14
 *   @0x1950e0 vsub.f32 s17, s17, s16
 *   @0x1950e4 vdiv.f32 s14, s14, s17
 *   @0x1950e8 vmov.f32 s15, #1.000000e+00
 *   @0x1950ec vcvt.f32.s32 s17, s11
 *   @0x1950f0 vadd.f32 s19, s19, s14
 *   @0x1950f4 vadd.f32 s17, s17, s15
 *   @0x1950f8 vcmpe.f32 s18, s12
 *   @0x1950fc vmrs APSR_nzcv, fpscr
 *   @0x195100 bpl 0x195110 <_ZN9CInstance14Collision_LineEffffb+0x1e8>
 *   @0x195104 vcmpe.f32 s19, s12
 *   @0x195108 vmrs APSR_nzcv, fpscr
 *   @0x19510c bmi 0x1951b4 <_ZN9CInstance14Collision_LineEffffb+0x28c>
 *   @0x195110 vcmpe.f32 s18, s13
 *   @0x195114 vmrs APSR_nzcv, fpscr
 *   @0x195118 blt 0x195128 <_ZN9CInstance14Collision_LineEffffb+0x200>
 *   @0x19511c vcmpe.f32 s19, s13
 *   @0x195120 vmrs APSR_nzcv, fpscr
 *   @0x195124 bge 0x1951b4 <_ZN9CInstance14Collision_LineEffffb+0x28c>
 *   @0x195128 cmp r7, #0
 *   @0x19512c beq 0x1951d4 <_ZN9CInstance14Collision_LineEffffb+0x2ac>
 *   @0x195130 ldrb r3, [r4, #0xb0]
 *   @0x195134 cmp r3, #0
 *   @0x195138 beq 0x1951d4 <_ZN9CInstance14Collision_LineEffffb+0x2ac>
 *   @0x19513c ldr r0, [r4, #0xac]
 *   @0x195140 cmp r0, #0
 *   @0x195144 ldrlt r0, [r4, #0x8c]
 *   @0x195148 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x19514c cmp r0, #0
 *   @0x195150 mov r5, r0
 *   @0x195154 beq 0x1951b4 <_ZN9CInstance14Collision_LineEffffb+0x28c>
 *   @0x195158 ldr r3, [r0, #0x18]
 *   @0x19515c cmp r3, #0
 *   @0x195160 beq 0x1951b4 <_ZN9CInstance14Collision_LineEffffb+0x28c>
 *   @0x195164 cmp r8, #0
 *   @0x195168 beq 0x1951dc <_ZN9CInstance14Collision_LineEffffb+0x2b4>
 *   @0x19516c vstr s16, [sp, #12]
 *   @0x195170 vstr s18, [sp, #16]
 *   @0x195174 vstr s17, [sp, #20]
 *   @0x195178 vstr s19, [sp, #24]
 *   @0x19517c vldr s15, [r4, #144]
 *   @0x195180 vcvt.s32.f32 s15, s15
 *   @0x195184 ldr r12, [r4, #0x98]
 *   @0x195188 mov r0, r8
 *   @0x19518c ldr r2, [r4, #0xb4]
 *   @0x195190 ldr r3, [r4, #0xb8]
 *   @0x195194 str r12, [sp]
 *   @0x195198 ldr lr, [r4, #0x9c]
 *   @0x19519c ldr r12, [r4, #0xa0]
 *   @0x1951a0 vmov r1, s15
 *   @0x1951a4 str lr, [sp, #0x4]
 *   @0x1951a8 str r12, [sp, #0x8]
 *   @0x1951ac bl 0xbf3cc <_ZN17CSkeletonInstance13LineCollisionEifffffffff>
 *   @0x1951b0 b 0x1951b8 <_ZN9CInstance14Collision_LineEffffb+0x290>
 *   @0x1951b4 mov r0, #0
 *   @0x1951b8 add sp, sp, #36
 *   @0x1951bc vpop {d8, d9, d10, d11}
 *   @0x1951c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1951c4 mov r0, r4
 *   @0x1951c8 mov r1, #1
 *   @0x1951cc bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb>
 *   @0x1951d0 b 0x194fcc <_ZN9CInstance14Collision_LineEffffb+0xa4>
 *   @0x1951d4 mov r0, #1
 *   @0x1951d8 b 0x1951b8 <_ZN9CInstance14Collision_LineEffffb+0x290>
 *   @0x1951dc vldr s15, [r4, #180]
 *   @0x1951e0 vcvt.f64.f32 d6, s15
 *   @0x1951e4 vldr s15, [r4, #144]
 *   @0x1951e8 vcvt.s32.f32 s15, s15
 *   @0x1951ec vmov r0, r1, d6
 *   @0x1951f0 vmov r11, s15
 *   @0x1951f4 bl 0xb66e8 <lrint@plt>
 *   @0x1951f8 vldr s15, [r4, #184]
 *   @0x1951fc vcvt.f64.f32 d6, s15
 *   @0x195200 mov r8, r0
 *   @0x195204 vmov r0, r1, d6
 *   @0x195208 bl 0xb66e8 <lrint@plt>
 *   @0x19520c vldr s22, [r4, #152]
 *   @0x195210 vcvt.f64.f32 d7, s16
 *   @0x195214 vldr s21, [r4, #156]
 *   @0x195218 vldr s20, [r4, #160]
 *   @0x19521c mov r10, r0
 *   @0x195220 vmov r0, r1, d7
 *   @0x195224 bl 0xb66e8 <lrint@plt>
 *   @0x195228 vcvt.f64.f32 d6, s18
 *   @0x19522c mov r9, r0
 *   @0x195230 vmov r0, r1, d6
 *   @0x195234 bl 0xb66e8 <lrint@plt>
 *   @0x195238 vcvt.f64.f32 d7, s17
 *   @0x19523c mov r7, r0
 *   @0x195240 vmov r0, r1, d7
 *   @0x195244 bl 0xb66e8 <lrint@plt>
 *   @0x195248 vcvt.f64.f32 d6, s19
 *   @0x19524c mov r6, r0
 *   @0x195250 vmov r0, r1, d6
 *   @0x195254 bl 0xb66e8 <lrint@plt>
 *   @0x195258 str r10, [sp]
 *   @0x19525c mov r1, r11
 *   @0x195260 vstr s22, [sp, #4]
 *   @0x195264 vstr s21, [sp, #8]
 *   @0x195268 vstr s20, [sp, #12]
 *   @0x19526c str r9, [sp, #0x10]
 *   @0x195270 mov r3, r8
 *   @0x195274 str r7, [sp, #0x14]
 *   @0x195278 add r2, r4, #232
 *   @0x19527c str r6, [sp, #0x18]
 *   @0x195280 str r0, [sp, #0x1c]
 *   @0x195284 mov r0, r5
 *   @0x195288 bl 0x1e52bc <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii>
 *   @0x19528c b 0x1951b8 <_ZN9CInstance14Collision_LineEffffb+0x290>
 *   @0x195290 eoreq r8, r5, r4, asr #19
 *
 * ══ §29/36 CObjectGM::LoadFromChunk(YYObject*, unsigned char*)  0x19d688  size 876  219 条（0x19d688..0x19d9f4）
 * @func 0x19d688 0x19d9f4  size 876  219 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x19d6b8→0x536f60, 0x19d714→0x544bd0, 0x19d87c→0x544c44, 0x19d8dc→0x544c44
 * 调用序列: CObjectGM::LoadFromChunk(YYObject*, unsigned char*)+0x1a8×2 / CObjectGM::Clear() / 0xb6544 / CObjectGM::LoadFromChunk(YYObject*, unsigned char*)+0x318 / CEvent::LoadFromChunk(YYEvent*, unsigned char*) / CObjectGM::LoadFromChunk(YYObject*, unsigned char*)+0x2f8 / CObjectGM::LoadFromChunk(YYObject*, unsigned char*)+0x220 / MemoryManager::SetLength(void**, unsigned int, char const*, int)
 * 字段偏移 top8: 0x14×9 / 0x4×6 / 0x8×5 / 0x10×5 / 0x-4×5 / 0xc×4 / 0x2×4 / 0x1c×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19d688 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x19d68c sub sp, sp, #28
 *   @0x19d690 mov r4, r1
 *   @0x19d694 mov r5, r0
 *   @0x19d698 str r2, [sp, #0x4]
 *   @0x19d69c bl 0x19d3d8 <_ZN9CObjectGM5ClearEv>
 *   @0x19d6a0 ldr r3, [r4, #0x4]
 *   @0x19d6a4 ldr r11, [pc, #0x334]
 *   @0x19d6a8 tst r3, #1879048192
 *   @0x19d6ac add r11, pc, r11
 *   @0x19d6b0 strne r3, [r5, #0x4]
 *   @0x19d6b4 bne 0x19d6d8 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x50>
 *   @0x19d6b8 ldr r2, [pc, #0x324]
 *   @0x19d6bc and r1, r3, #-2147483648
 *   @0x19d6c0 bic r3, r3, #-2147483648
 *   @0x19d6c4 ldr r2, [r11, r2]
 *   @0x19d6c8 str r3, [r5, #0x4]
 *   @0x19d6cc ldr r3, [r2]
 *   @0x19d6d0 orr r3, r1, r3
 *   @0x19d6d4 str r3, [r2]
 *   @0x19d6d8 ldr r3, [r4, #0xc]
 *   @0x19d6dc ldr r2, [r5]
 *   @0x19d6e0 cmp r3, #0
 *   @0x19d6e4 orrne r2, r2, #1
 *   @0x19d6e8 biceq r2, r2, #1
 *   @0x19d6ec str r2, [r5]
 *   @0x19d6f0 ldr r3, [r4, #0x8]
 *   @0x19d6f4 cmp r3, #0
 *   @0x19d6f8 orrne r2, r2, #2
 *   @0x19d6fc biceq r2, r2, #2
 *   @0x19d700 str r2, [r5]
 *   @0x19d704 mov r1, r2
 *   @0x19d708 ldr r2, [r4, #0x14]
 *   @0x19d70c ldr r3, [r4, #0x10]
 *   @0x19d710 cmp r2, #0
 *   @0x19d714 ldr r2, [pc, #0x2cc]
 *   @0x19d718 orrne r1, r1, #4
 *   @0x19d71c biceq r1, r1, #4
 *   @0x19d720 str r1, [r5]
 *   @0x19d724 ldr r0, [r4, #0x18]
 *   @0x19d728 ldr r1, [r4, #0x1c]
 *   @0x19d72c str r3, [r5, #0x8]
 *   @0x19d730 mov r3, #0
 *   @0x19d734 str r0, [r5, #0xc]
 *   @0x19d738 str r1, [r5, #0x10]
 *   @0x19d73c strb r3, [r5, #0x1c]
 *   @0x19d740 str r3, [r5, #0x44]
 *   @0x19d744 str r3, [r5, #0x40]
 *   @0x19d748 ldr r2, [r11, r2]
 *   @0x19d74c ldr r2, [r2]
 *   @0x19d750 cmp r2, #5
 *   @0x19d754 addle r4, r4, #32
 *   @0x19d758 strle r4, [sp, #0x14]
 *   @0x19d75c ble 0x19d830 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x1a8>
 *   @0x19d760 ldr lr, [r4, #0x20]
 *   @0x19d764 ldr r12, [r4, #0x24]
 *   @0x19d768 adds lr, lr, #0
 *   @0x19d76c ldr r8, [r4, #0x2c]
 *   @0x19d770 ldr r7, [r4, #0x30]
 *   @0x19d774 movne lr, #1
 *   @0x19d778 adds r12, r12, #0
 *   @0x19d77c ldr r0, [r4, #0x28]
 *   @0x19d780 movne r12, #1
 *   @0x19d784 cmp r2, #8
 *   @0x19d788 ldr r2, [r4, #0x38]
 *   @0x19d78c ldr r1, [r4, #0x34]
 *   @0x19d790 ldr r6, [r4, #0x40]
 *   @0x19d794 str r2, [r5, #0x30]
 *   @0x19d798 ldr r2, [r4, #0x3c]
 *   @0x19d79c strb lr, [r5, #0x1c]
 *   @0x19d7a0 str r8, [r5, #0x28]
 *   @0x19d7a4 strb r12, [r5, #0x1d]
 *   @0x19d7a8 str r7, [r5, #0x2c]
 *   @0x19d7ac str r0, [r5, #0x20]
 *   @0x19d7b0 str r1, [r5, #0x24]
 *   @0x19d7b4 str r6, [r5, #0x40]
 *   @0x19d7b8 str r2, [r5, #0x34]
 *   @0x19d7bc bgt 0x19d9ac <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x324>
 *   @0x19d7c0 add r4, r4, #68
 *   @0x19d7c4 strb r3, [r5, #0x3d]
 *   @0x19d7c8 movw r2, #0xcccd
 *   @0x19d7cc mov r3, #1
 *   @0x19d7d0 movt r2, #0x3e4c
 *   @0x19d7d4 str r4, [sp, #0x14]
 *   @0x19d7d8 str r2, [r5, #0x38]
 *   @0x19d7dc strb r3, [r5, #0x3c]
 *   @0x19d7e0 lsl r4, r6, #3
 *   @0x19d7e4 mov r0, r4
 *   @0x19d7e8 bl 0xb6544 <malloc@plt>
 *   @0x19d7ec cmp r6, #0
 *   @0x19d7f0 str r0, [r5, #0x44]
 *   @0x19d7f4 ble 0x19d830 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x1a8>
 *   @0x19d7f8 ldr r2, [sp, #0x14]
 *   @0x19d7fc mov r1, #0
 *   @0x19d800 ldr r3, [r2]
 *   @0x19d804 add r1, r1, #1
 *   @0x19d808 cmp r1, r6
 *   @0x19d80c add r2, r2, #8
 *   @0x19d810 add r0, r0, #8
 *   @0x19d814 str r3, [r0, #-0x8]
 *   @0x19d818 ldr r3, [r2, #-0x4]
 *   @0x19d81c str r3, [r0, #-0x4]
 *   @0x19d820 bne 0x19d800 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x178>
 *   @0x19d824 ldr r2, [sp, #0x14]
 *   @0x19d828 add r2, r2, r4
 *   @0x19d82c str r2, [sp, #0x14]
 *   @0x19d830 ldr r2, [sp, #0x14]
 *   @0x19d834 ldr r3, [r2]
 *   @0x19d838 cmp r3, #0
 *   @0x19d83c ble 0x19d9a0 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x318>
 *   @0x19d840 ldr r2, [pc, #0x1a4]
 *   @0x19d844 add r5, r5, #80
 *   @0x19d848 mov r10, #0
 *   @0x19d84c add r2, pc, r2
 *   @0x19d850 str r2, [sp, #0xc]
 *   @0x19d854 mov r2, #0
 *   @0x19d858 str r2, [sp, #0x8]
 *   @0x19d85c ldr r2, [sp, #0x14]
 *   @0x19d860 str r2, [sp, #0x10]
 *   @0x19d864 ldr r2, [sp, #0x10]
 *   @0x19d868 ldr r8, [r2, #0x4]!
 *   @0x19d86c cmp r8, #0
 *   @0x19d870 str r2, [sp, #0x10]
 *   @0x19d874 moveq r7, #4
 *   @0x19d878 beq 0x19d890 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x208>
 *   @0x19d87c ldr r2, [pc, #0x16c]
 *   @0x19d880 ldr r2, [r11, r2]
 *   @0x19d884 ldr r2, [r2]
 *   @0x19d888 add r8, r2, r8
 *   @0x19d88c add r7, r8, #4
 *   @0x19d890 ldr r2, [r8]
 *   @0x19d894 cmp r2, #0
 *   @0x19d898 subgt r7, r7, #4
 *   @0x19d89c movgt r9, #0
 *   @0x19d8a0 bgt 0x19d8d4 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x24c>
 *   @0x19d8a4 b 0x19d988 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x300>
 *   @0x19d8a8 ldr r3, [r5]
 *   @0x19d8ac ldr r0, [r3, r1, lsl #2]
 *   @0x19d8b0 cmp r0, #0
 *   @0x19d8b4 beq 0x19d958 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x2d0>
 *   @0x19d8b8 add r1, r6, #4
 *   @0x19d8bc ldr r2, [sp, #0x4]
 *   @0x19d8c0 bl 0xf2d84 <_ZN6CEvent13LoadFromChunkEP7YYEventPh>
 *   @0x19d8c4 ldr r3, [r8]
 *   @0x19d8c8 add r9, r9, #1
 *   @0x19d8cc cmp r3, r9
 *   @0x19d8d0 ble 0x19d980 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x2f8>
 *   @0x19d8d4 ldr r6, [r7, #0x4]!
 *   @0x19d8d8 cmp r6, #0
 *   @0x19d8dc ldrne r3, [pc, #0x10c]
 *   @0x19d8e0 ldrne r3, [r11, r3]
 *   @0x19d8e4 ldrne r3, [r3]
 *   @0x19d8e8 addne r6, r3, r6
 *   @0x19d8ec ldr r1, [r6]
 *   @0x19d8f0 ldr r4, [r5, #-0x4]
 *   @0x19d8f4 cmp r1, r4
 *   @0x19d8f8 blt 0x19d8a8 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x220>
 *   @0x19d8fc add r1, r1, #1
 *   @0x19d900 movw r3, #0x1b6
 *   @0x19d904 mov r0, r5
 *   @0x19d908 ldr r2, [sp, #0xc]
 *   @0x19d90c lsl r1, r1, #2
 *   @0x19d910 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x19d914 ldr r1, [r6]
 *   @0x19d918 cmp r4, r1
 *   @0x19d91c add r3, r1, #1
 *   @0x19d920 str r3, [r5, #-0x4]
 *   @0x19d924 bge 0x19d8a8 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x220>
 *   @0x19d928 lsl r3, r4, #2
 *   @0x19d92c add r4, r4, #1
 *   @0x19d930 ldr r2, [r5]
 *   @0x19d934 cmp r4, r1
 *   @0x19d938 str r10, [r2, r3]
 *   @0x19d93c add r3, r3, #4
 *   @0x19d940 bne 0x19d92c <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x2a4>
 *   @0x19d944 ldr r3, [r5]
 *   @0x19d948 mov r1, r4
 *   @0x19d94c ldr r0, [r3, r1, lsl #2]
 *   @0x19d950 cmp r0, #0
 *   @0x19d954 bne 0x19d8b8 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x230>
 *   @0x19d958 mov r0, #12
 *   @0x19d95c bl 0x27c524 <_Znwj>
 *   @0x19d960 mov r4, r0
 *   @0x19d964 bl 0xf2d0c <_ZN6CEventC2Ev>
 *   @0x19d968 ldr r3, [r6]
 *   @0x19d96c ldr r2, [r5]
 *   @0x19d970 str r4, [r2, r3, lsl #2]
 *   @0x19d974 ldr r2, [r5]
 *   @0x19d978 ldr r0, [r2, r3, lsl #2]
 *   @0x19d97c b 0x19d8b8 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x230>
 *   @0x19d980 ldr r2, [sp, #0x14]
 *   @0x19d984 ldr r3, [r2]
 *   @0x19d988 ldr r2, [sp, #0x8]
 *   @0x19d98c add r5, r5, #8
 *   @0x19d990 add r2, r2, #1
 *   @0x19d994 str r2, [sp, #0x8]
 *   @0x19d998 cmp r3, r2
 *   @0x19d99c bgt 0x19d864 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x1dc>
 *   @0x19d9a0 mov r0, #1
 *   @0x19d9a4 add sp, sp, #28
 *   @0x19d9a8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x19d9ac ldr r2, [r4, #0x48]
 *   @0x19d9b0 add r4, r4, #80
 *   @0x19d9b4 ldr r3, [r4, #-0x4]
 *   @0x19d9b8 adds r2, r2, #0
 *   @0x19d9bc ldr r1, [r4, #-0xc]
 *   @0x19d9c0 str r4, [sp, #0x14]
 *   @0x19d9c4 movne r2, #1
 *   @0x19d9c8 adds r3, r3, #0
 *   @0x19d9cc str r1, [r5, #0x38]
 *   @0x19d9d0 movne r3, #1
 *   @0x19d9d4 strb r2, [r5, #0x3c]
 *   @0x19d9d8 strb r3, [r5, #0x3d]
 *   @0x19d9dc b 0x19d7e0 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh+0x158>
 *   @0x19d9e0 eoreq r4, r5, r4, lsr #11
 *   @0x19d9e4 .word 0xffffe798
 *   @0x19d9e8 .word 0xffffea88
 *   @0x19d9ec mulseq r10, r4, r5
 *   @0x19d9f0 .word 0xffffbcf4
 *
 * ══ §30/36 VertexFormat::EndianSwapBuffer(unsigned char*, int, int, int, bool)  0x1e251c  size 876  219 条（0x1e251c..0x1e2888）
 * @func 0x1e251c 0x1e2888  size 876  219 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __aeabi_uidivmod×3 / __udivsi3×2 / VertexFormat::EndianSwapBuffer(unsigned char*, int, int, int, bool)+0x1a0×2 / VertexFormat::GetNumElementsInType(yyVertexType)×2 / VertexFormat::GetElementSizeInType(yyVertexType)×2 / VertexFormat::EndianSwapBuffer(unsigned char*, int, int, int, bool)+0x1c8 / VertexFormat::EndianSwapBuffer(unsigned char*, int, int, int, bool)+0x1d0 / VertexFormat::EndianSwapBuffer(unsigned char*, int, int, int, bool)+0x174
 * 字段偏移 top8: 0x4×18 / 0xc×12 / 0x8×10 / 0x1c×8 / 0x14×5 / 0x-2×4 / 0x20×4 / 0x24×4
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e251c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1e2520 subs r11, r1, #0
 *   @0x1e2524 sub sp, sp, #44
 *   @0x1e2528 mov r4, r3
 *   @0x1e252c str r0, [sp, #0xc]
 *   @0x1e2530 str r2, [sp, #0x1c]
 *   @0x1e2534 ldr r10, [sp, #0x50]
 *   @0x1e2538 ldrb r3, [sp, #0x54]
 *   @0x1e253c beq 0x1e26bc <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x1a0>
 *   @0x1e2540 ands r1, r3, r10, lsr #31
 *   @0x1e2544 bne 0x1e26bc <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x1a0>
 *   @0x1e2548 cmp r10, #0
 *   @0x1e254c blt 0x1e26e4 <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x1c8>
 *   @0x1e2550 cmp r3, #0
 *   @0x1e2554 beq 0x1e26c4 <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x1a8>
 *   @0x1e2558 ldr r2, [sp, #0xc]
 *   @0x1e255c ldr r5, [r2, #0x14]
 *   @0x1e2560 ldr r2, [sp, #0x1c]
 *   @0x1e2564 mul r3, r2, r5
 *   @0x1e2568 cmp r10, r3
 *   @0x1e256c bge 0x1e2584 <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x68>
 *   @0x1e2570 mov r0, r10
 *   @0x1e2574 mov r1, r5
 *   @0x1e2578 bl 0x318c48 <__udivsi3>
 *   @0x1e257c mul r3, r0, r5
 *   @0x1e2580 str r0, [sp, #0x1c]
 *   @0x1e2584 add r3, r4, r3
 *   @0x1e2588 cmp r10, r3
 *   @0x1e258c blt 0x1e26ec <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x1d0>
 *   @0x1e2590 ldr r2, [sp, #0x1c]
 *   @0x1e2594 add r4, r11, r4
 *   @0x1e2598 str r4, [sp, #0x4]
 *   @0x1e259c cmp r2, #0
 *   @0x1e25a0 ble 0x1e26bc <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x1a0>
 *   @0x1e25a4 ldr r1, [sp, #0xc]
 *   @0x1e25a8 mov r3, #0
 *   @0x1e25ac str r3, [sp, #0x8]
 *   @0x1e25b0 ldr r4, [r1, #0x4]
 *   @0x1e25b4 cmp r4, #0
 *   @0x1e25b8 ble 0x1e2690 <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x174>
 *   @0x1e25bc mov r9, #0
 *   @0x1e25c0 ldr r2, [sp, #0xc]
 *   @0x1e25c4 lsl r5, r9, #4
 *   @0x1e25c8 ldr r1, [sp, #0x4]
 *   @0x1e25cc ldr r3, [r2, #0x8]
 *   @0x1e25d0 add r2, r3, r5
 *   @0x1e25d4 ldr r3, [r3, r9, lsl #4]
 *   @0x1e25d8 ldr r0, [r2, #0x4]
 *   @0x1e25dc add r4, r1, r3
 *   @0x1e25e0 bl 0x1e2400 <_ZN12VertexFormat20GetNumElementsInTypeE12yyVertexType>
 *   @0x1e25e4 ldr r2, [sp, #0xc]
 *   @0x1e25e8 ldr r3, [r2, #0x8]
 *   @0x1e25ec add r5, r3, r5
 *   @0x1e25f0 mov r7, r0
 *   @0x1e25f4 ldr r0, [r5, #0x4]
 *   @0x1e25f8 bl 0x1e242c <_ZN12VertexFormat20GetElementSizeInTypeE12yyVertexType>
 *   @0x1e25fc cmp r7, #0
 *   @0x1e2600 ble 0x1e267c <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x160>
 *   @0x1e2604 add r4, r4, #1
 *   @0x1e2608 and r8, r0, #1
 *   @0x1e260c asr r6, r0, #1
 *   @0x1e2610 sub r10, r0, #3
 *   @0x1e2614 mov r5, #0
 *   @0x1e2618 cmp r8, #0
 *   @0x1e261c bne 0x1e266c <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x150>
 *   @0x1e2620 cmp r6, #0
 *   @0x1e2624 ble 0x1e266c <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x150>
 *   @0x1e2628 add r12, r6, r4
 *   @0x1e262c add r2, r10, r4
 *   @0x1e2630 mov r3, r4
 *   @0x1e2634 ldrb r11, [r2, #0x1]
 *   @0x1e2638 add r3, r3, #1
 *   @0x1e263c ldrb r1, [r3, #-0x2]
 *   @0x1e2640 sub r2, r2, #1
 *   @0x1e2644 eor r1, r11, r1
 *   @0x1e2648 strb r1, [r3, #-0x2]
 *   @0x1e264c ldrb r11, [r2, #0x2]
 *   @0x1e2650 eor r1, r1, r11
 *   @0x1e2654 strb r1, [r2, #0x2]
 *   @0x1e2658 ldrb r11, [r3, #-0x2]
 *   @0x1e265c eor r1, r1, r11
 *   @0x1e2660 strb r1, [r3, #-0x2]
 *   @0x1e2664 cmp r3, r12
 *   @0x1e2668 bne 0x1e2634 <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x118>
 *   @0x1e266c add r5, r5, #1
 *   @0x1e2670 add r4, r4, r0
 *   @0x1e2674 cmp r5, r7
 *   @0x1e2678 bne 0x1e2618 <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0xfc>
 *   @0x1e267c ldr r3, [sp, #0xc]
 *   @0x1e2680 add r9, r9, #1
 *   @0x1e2684 ldr r4, [r3, #0x4]
 *   @0x1e2688 cmp r4, r9
 *   @0x1e268c bgt 0x1e25c0 <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0xa4>
 *   @0x1e2690 ldr r2, [sp, #0xc]
 *   @0x1e2694 ldr r1, [sp, #0x8]
 *   @0x1e2698 ldr r3, [r2, #0x14]
 *   @0x1e269c add r1, r1, #1
 *   @0x1e26a0 ldr r2, [sp, #0x1c]
 *   @0x1e26a4 str r1, [sp, #0x8]
 *   @0x1e26a8 cmp r1, r2
 *   @0x1e26ac ldr r1, [sp, #0x4]
 *   @0x1e26b0 add r1, r1, r3
 *   @0x1e26b4 str r1, [sp, #0x4]
 *   @0x1e26b8 bne 0x1e25b4 <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x98>
 *   @0x1e26bc add sp, sp, #44
 *   @0x1e26c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e26c4 ldr r1, [r0, #0x14]
 *   @0x1e26c8 mla r3, r2, r1, r4
 *   @0x1e26cc cmp r10, r3
 *   @0x1e26d0 bge 0x1e2590 <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x74>
 *   @0x1e26d4 rsb r0, r4, r10
 *   @0x1e26d8 bl 0x318c48 <__udivsi3>
 *   @0x1e26dc str r0, [sp, #0x1c]
 *   @0x1e26e0 b 0x1e2590 <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x74>
 *   @0x1e26e4 cmp r3, #0
 *   @0x1e26e8 beq 0x1e2590 <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x74>
 *   @0x1e26ec mov r0, r4
 *   @0x1e26f0 mov r1, r10
 *   @0x1e26f4 bl 0x318dec <__aeabi_idivmod>
 *   @0x1e26f8 ldr r2, [sp, #0x1c]
 *   @0x1e26fc cmp r2, #0
 *   @0x1e2700 str r1, [sp, #0x20]
 *   @0x1e2704 ble 0x1e26bc <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x1a0>
 *   @0x1e2708 ldr r1, [sp, #0xc]
 *   @0x1e270c mov r3, #0
 *   @0x1e2710 str r3, [sp, #0x24]
 *   @0x1e2714 ldr r4, [r1, #0x4]
 *   @0x1e2718 cmp r4, #0
 *   @0x1e271c ble 0x1e2848 <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x32c>
 *   @0x1e2720 mov r2, #0
 *   @0x1e2724 str r2, [sp, #0x18]
 *   @0x1e2728 ldr r3, [sp, #0xc]
 *   @0x1e272c ldr r2, [r3, #0x8]
 *   @0x1e2730 ldr r3, [sp, #0x18]
 *   @0x1e2734 lsl r5, r3, #4
 *   @0x1e2738 ldr r4, [r2, r3, lsl #4]
 *   @0x1e273c add r1, r2, r5
 *   @0x1e2740 ldr r0, [r1, #0x4]
 *   @0x1e2744 bl 0x1e2400 <_ZN12VertexFormat20GetNumElementsInTypeE12yyVertexType>
 *   @0x1e2748 ldr r1, [sp, #0xc]
 *   @0x1e274c ldr r2, [r1, #0x8]
 *   @0x1e2750 add r5, r2, r5
 *   @0x1e2754 str r0, [sp, #0x8]
 *   @0x1e2758 ldr r0, [r5, #0x4]
 *   @0x1e275c bl 0x1e242c <_ZN12VertexFormat20GetElementSizeInTypeE12yyVertexType>
 *   @0x1e2760 ands r7, r0, #1
 *   @0x1e2764 str r0, [sp, #0x4]
 *   @0x1e2768 bne 0x1e282c <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x310>
 *   @0x1e276c ldr r2, [sp, #0x8]
 *   @0x1e2770 cmp r2, #0
 *   @0x1e2774 ble 0x1e282c <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x310>
 *   @0x1e2778 ldr r2, [sp, #0x20]
 *   @0x1e277c ldr r3, [sp, #0x4]
 *   @0x1e2780 add r9, r2, r4
 *   @0x1e2784 ldr r2, [sp, #0x4]
 *   @0x1e2788 asr r3, r3, #1
 *   @0x1e278c mov r8, r9
 *   @0x1e2790 mov r9, r11
 *   @0x1e2794 str r3, [sp, #0x10]
 *   @0x1e2798 rsb r3, r2, r3
 *   @0x1e279c str r3, [sp, #0x14]
 *   @0x1e27a0 ldr r3, [sp, #0x10]
 *   @0x1e27a4 ldr r2, [sp, #0x4]
 *   @0x1e27a8 cmp r3, #0
 *   @0x1e27ac add r6, r8, r2
 *   @0x1e27b0 ldrgt r2, [sp, #0x14]
 *   @0x1e27b4 sub r4, r6, #1
 *   @0x1e27b8 addgt r5, r2, r6
 *   @0x1e27bc ble 0x1e2814 <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x2f8>
 *   @0x1e27c0 mov r0, r8
 *   @0x1e27c4 mov r1, r10
 *   @0x1e27c8 bl 0x318cf0 <__aeabi_uidivmod>
 *   @0x1e27cc mov r0, r4
 *   @0x1e27d0 add r8, r8, #1
 *   @0x1e27d4 sub r4, r4, #1
 *   @0x1e27d8 mov r11, r1
 *   @0x1e27dc mov r1, r10
 *   @0x1e27e0 bl 0x318cf0 <__aeabi_uidivmod>
 *   @0x1e27e4 ldrb r3, [r9, r11]
 *   @0x1e27e8 cmp r8, r5
 *   @0x1e27ec ldrb r2, [r9, r1]
 *   @0x1e27f0 eor r3, r2, r3
 *   @0x1e27f4 strb r3, [r9, r11]
 *   @0x1e27f8 ldrb r2, [r9, r1]
 *   @0x1e27fc eor r3, r3, r2
 *   @0x1e2800 strb r3, [r9, r1]
 *   @0x1e2804 ldrb r2, [r9, r11]
 *   @0x1e2808 eor r3, r3, r2
 *   @0x1e280c strb r3, [r9, r11]
 *   @0x1e2810 bne 0x1e27c0 <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x2a4>
 *   @0x1e2814 ldr r3, [sp, #0x8]
 *   @0x1e2818 add r7, r7, #1
 *   @0x1e281c cmp r7, r3
 *   @0x1e2820 movne r8, r6
 *   @0x1e2824 bne 0x1e27a0 <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x284>
 *   @0x1e2828 mov r11, r9
 *   @0x1e282c ldr r2, [sp, #0xc]
 *   @0x1e2830 ldr r3, [sp, #0x18]
 *   @0x1e2834 ldr r4, [r2, #0x4]
 *   @0x1e2838 add r3, r3, #1
 *   @0x1e283c str r3, [sp, #0x18]
 *   @0x1e2840 cmp r4, r3
 *   @0x1e2844 bgt 0x1e2728 <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x20c>
 *   @0x1e2848 ldr r3, [sp, #0xc]
 *   @0x1e284c mov r1, r10
 *   @0x1e2850 ldr r2, [sp, #0x24]
 *   @0x1e2854 ldr r0, [r3, #0x14]
 *   @0x1e2858 add r2, r2, #1
 *   @0x1e285c ldr r3, [sp, #0x20]
 *   @0x1e2860 str r2, [sp, #0x24]
 *   @0x1e2864 add r0, r3, r0
 *   @0x1e2868 bl 0x318cf0 <__aeabi_uidivmod>
 *   @0x1e286c ldr r2, [sp, #0x24]
 *   @0x1e2870 ldr r3, [sp, #0x1c]
 *   @0x1e2874 cmp r2, r3
 *   @0x1e2878 str r1, [sp, #0x20]
 *   @0x1e287c bne 0x1e2718 <_ZN12VertexFormat16EndianSwapBufferEPhiiib+0x1fc>
 *   @0x1e2880 add sp, sp, #44
 *   @0x1e2884 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §31/36 png_handle_cHRM  0x2ac328  size 876  219 条（0x2ac328..0x2ac694）
 * @func 0x2ac328 0x2ac694  size 876  219 条
 * 部分覆盖: 本节 219/373 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_warning / png_crc_finish / 0x49c520 / 0x490574 / 0x44ac48 / 0x5b8598 / 0x59ec8c / 0x5385f4
 * 字段偏移 top8: 0x340×1 / 0x44×1 / 0x314×1 / 0x2f4×1 / 0x8×1 / 0x110×1 / 0x108×1 / 0x14×1
 * VFP 指令 42 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ac328 ldr r3, [pc, #0x340]
 *   @0x2ac32c stc p15, c4, [sp, #-960]!
 *   @0x2ac330 ldrbtmi r8, [r11], #-2824
 *   @0x2ac334 ldr r3, [r3]
 *   @0x2ac338 sub sp, #0x74
 *   @0x2ac33c mov r4, r0
 *   @0x2ac340 str r3, [sp, #0x44]
 *   @0x2ac344 ldr.w r2, [r0, #0x12c]
 *   @0x2ac348 tst.w r2, #0x1
 *   @0x2ac34c bne 0x2ac358 <png_handle_cHRM+0x30>
 *   @0x2ac350 add r1, pc
 *   @0x2ac354 and pc, r10, r11, ror #16
 *   @0x2ac358 lsls r1, r2, #0x1d
 *   @0x2ac35c ldr r1, [pc, #0x314]
 *   @0x2ac360 b 0x2ac38c <png_handle_cHRM+0x64>
 *   @0x2ac364 bpl 0x2ac36e <png_handle_cHRM+0x46>
 *   @0x2ac368 add r1, pc
 *   @0x2ac36c strtmi pc, [r0], -r3, lsl #17
 *   @0x2ac370 cbz r5, 0x2ac384 <png_handle_cHRM+0x5c>
 *   @0x2ac374 movw r3, #0x804
 *   @0x2ac378 ands r3, r2
 *   @0x2ac37c bne 0x2ac384 <png_handle_cHRM+0x5c>
 *   @0x2ac380 add r1, pc
 *   @0x2ac384 cmp r6, #0x20
 *   @0x2ac388 ldr r1, [pc, #0x2f4]
 *   @0x2ac38c bl 0x2a6474 <png_warning>
 *   @0x2ac390 mov r0, r4
 *   @0x2ac394 bl 0x2abc94 <png_crc_finish>
 *   @0x2ac398 b 0x2ac64e <png_handle_cHRM+0x326>
 *   @0x2ac39c mov r2, r6
 *   @0x2ac3a0 qasxmi pc, r0, r5
 *   @0x2ac3a4 movs r1, #0x0
 *   @0x2ac3a8 stmdahs r0, {r0, r2, r4, r5, r6, r10, r11, r12, sp, lr, pc}
 *   @0x2ac3ac bne.w 0x2ac64e <png_handle_cHRM+0x326>
 *   @0x2ac3b0 ldrb.w r7, [sp, #0x4d]
 *   @0x2ac3b4 vldr s15, [pc, #688]
 *   @0x2ac3b8 ldrb.w r3, [sp, #0x4c]
 *   @0x2ac3bc ldrb.w r6, [sp, #0x51]
 *   @0x2ac3c0 lsls r7, r7, #0x10
 *   @0x2ac3c4 bl 0x49c520 <TimingData+0x2508>
 *   @0x2ac3c8 .word 0xf89d6703
 *   @0x2ac3cc ldrteq r3, [r6], #-79
 *   @0x2ac3d0 ldrb.w r11, [sp, #0x59]
 *   @0x2ac3d4 add r7, r3
 *   @0x2ac3d8 b 0x1678518 <b2_toiTime+0xf1f074>
 *   @0x2ac3dc .word 0xf89d4c0c
 *   @0x2ac3e0 b 0x169455c <b2_toiTime+0xf3b0b8>
 *   @0x2ac3e4 .word 0xf89d4b0b
 *   @0x2ac3e8 bl 0x490574 <g_prim_v+0x568>
 *   @0x2ac3ec .word 0xf89d2703
 *   @0x2ac3f0 b 0x1678538 <b2_toiTime+0xf1f094>
 *   @0x2ac3f4 .word 0xf89d4a0a
 *   @0x2ac3f8 b 0x168c594 <b2_toiTime+0xf330f0>
 *   @0x2ac3fc cdp p9, #0x0, c4, c7, c9, #0x0
 *   @0x2ac400 bl 0x44ac48 <g_RomDisk+0x53428>
 *   @0x2ac404 .word 0xf89d6603
 *   @0x2ac408 b 0x167855c <b2_toiTime+0xf1f0b8>
 *   @0x2ac40c cdp p8, #0xf, c4, c8, c8, #0x0
 *   @0x2ac410 ldrmi r8, [lr], #-2759
 *   @0x2ac414 ldrb.w r3, [sp, #0x52]
 *   @0x2ac418 ldrb.w r2, [sp, #0x68]
 *   @0x2ac41c add.w r6, r6, r3, lsl #8
 *   @0x2ac420 ldrb.w r3, [sp, #0x54]
 *   @0x2ac424 vmov s14, r6
 *   @0x2ac428 add.w r12, r12, r3, lsl #24
 *   @0x2ac42c ldrb.w r3, [sp, #0x57]
 *   @0x2ac430 vcvt.f32.s32 s23, s14
 *   @0x2ac434 add r12, r3
 *   @0x2ac438 bl 0x5b8598 <g_SWFlineaavertbuff+0x654d0>
 *   @0x2ac43c .word 0xf89d2c03
 *   @0x2ac440 mcr p0, #0x0, r3, c7, c8, #0x2
 *   @0x2ac444 bl 0x59ec8c <g_SWFlineaavertbuff+0x4bbc4>
 *   @0x2ac448 .word 0xf89d6b03
 *   @0x2ac44c mrc p0, #0x5, r3, c8, c11, #0x2
 *   @0x2ac450 ldrmi r11, [r11], #2759
 *   @0x2ac454 ldrb.w r3, [sp, #0x5a]
 *   @0x2ac458 add.w r11, r11, r3, lsl #8
 *   @0x2ac45c ldrb.w r3, [sp, #0x5c]
 *   @0x2ac460 vmov s14, r11
 *   @0x2ac464 add.w r10, r10, r3, lsl #24
 *   @0x2ac468 ldrb.w r3, [sp, #0x5f]
 *   @0x2ac46c vcvt.f32.s32 s21, s14
 *   @0x2ac470 add r10, r3
 *   @0x2ac474 bl 0x5385f4 <obj_numb_event+0x1684>
 *   @0x2ac478 .word 0xf89d2a03
 *   @0x2ac47c cdp p0, #0x0, c3, c7, c0, #0x3
 *   @0x2ac480 bl 0x516cc8 <SrcVerts+0x73d0c>
 *   @0x2ac484 .word 0xf89d6903
 *   @0x2ac488 cdp p0, #0xf, c3, c8, c3, #0x3
 *   @0x2ac48c ldrmi r9, [r9], #2759
 *   @0x2ac490 ldrb.w r3, [sp, #0x62]
 *   @0x2ac494 add.w r9, r9, r3, lsl #8
 *   @0x2ac498 ldrb.w r3, [sp, #0x64]
 *   @0x2ac49c vmov s14, r9
 *   @0x2ac4a0 add.w r8, r8, r3, lsl #24
 *   @0x2ac4a4 ldrb.w r3, [sp, #0x67]
 *   @0x2ac4a8 vcvt.f32.s32 s20, s14
 *   @0x2ac4ac add r8, r3
 *   @0x2ac4b0 bl 0x4b8650 <SrcVerts+0x15694>
 *   @0x2ac4b4 .word 0xf89d2803
 *   @0x2ac4b8 cdp p0, #0x0, c3, c7, c9, #0x3
 *   @0x2ac4bc ldreq r8, [r11], #-2576
 *   @0x2ac4c0 vdiv.f32 s17, s17, s15
 *   @0x2ac4c4 add.w r3, r3, r2, lsl #24
 *   @0x2ac4c8 ldrb.w r2, [sp, #0x6b]
 *   @0x2ac4cc add r3, r2
 *   @0x2ac4d0 bl 0x374680 <_ZTS13C_UTF16String+0xb72c>
 *   @0x2ac4d4 andsls r2, r0, #536870912
 *   @0x2ac4d8 vcvt.f32.s32 s18, s14
 *   @0x2ac4dc vmov s14, r2
 *   @0x2ac4e0 vcvt.f32.s32 s16, s14
 *   @0x2ac4e4 vdiv.f32 s23, s23, s15
 *   @0x2ac4e8 vdiv.f32 s22, s22, s15
 *   @0x2ac4ec vdiv.f32 s21, s21, s15
 *   @0x2ac4f0 vdiv.f32 s19, s19, s15
 *   @0x2ac4f4 vdiv.f32 s20, s20, s15
 *   @0x2ac4f8 vdiv.f32 s18, s18, s15
 *   @0x2ac4fc vdiv.f32 s16, s16, s15
 *   @0x2ac500 cmp r5, #0x0
 *   @0x2ac504 ldr r3, [r5, #0x8]
 *   @0x2ac508 bpl 0x2ac5da <png_handle_cHRM+0x2b2>
 *   @0x2ac50c svclo #0x3e47ec
 *   @0x2ac510 cmp.w r7, #0x7d0
 *   @0x2ac514 bhi 0x2ac570 <png_handle_cHRM+0x248>
 *   @0x2ac518 mrclo p6, #0x0, r4, c12, c9, #0x7
 *   @0x2ac51c cmp.w r6, #0x7d0
 *   @0x2ac520 bhi 0x2ac570 <png_handle_cHRM+0x248>
 *   @0x2ac524 .word 0xf1ac4c76
 *   @0x2ac528 .word 0xf5bc0c18
 *   @0x2ac52c ldmdale pc, {r1, r3, r4, r5, r6, r7, r8, r9, r10, r11, sp, lr}
 *   @0x2ac530 sub.w r11, r11, #0x7d00
 *   @0x2ac534 cmp.w r11, #0x7d0
 *   @0x2ac538 bhi 0x2ac570 <png_handle_cHRM+0x248>
 *   @0x2ac53c .word 0xf1aa4ae2
 *   @0x2ac540 .word 0xf5ba0a48
 *   @0x2ac544 ldmdale r3, {r1, r3, r4, r5, r6, r7, r8, r9, r10, r11, sp, lr}
 *   @0x2ac548 sub.w r9, r9, #0xe600
 *   @0x2ac54c sub.w r9, r9, #0x78
 *   @0x2ac550 cmp.w r9, #0x7d0
 *   @0x2ac554 bhi 0x2ac570 <png_handle_cHRM+0x248>
 *   @0x2ac558 .word 0xf1a8585a
 *   @0x2ac55c .word 0xf5b80830
 *   @0x2ac560 stmdale r5, {r1, r3, r4, r5, r6, r7, r8, r9, r10, r11, sp, lr}
 *   @0x2ac564 sub.w r3, r2, #0x1380
 *   @0x2ac568 subs r3, #0x8
 *   @0x2ac56c stmdble lr!, {r1, r3, r4, r5, r6, r7, r8, r9, r10, r11, sp, lr} ^
 *   @0x2ac570 ldr r1, [pc, #0x110]
 *   @0x2ac574 add r1, pc
 *   @0x2ac578 mrc p15, #0x5, apsr_nzcv, c7, c13, #0x3
 *   @0x2ac57c stmdami r2, {r3, r5, r6, r7, r9, r11, r12, sp, lr} ^
 *   @0x2ac580 ldr r1, [pc, #0x108]
 *   @0x2ac584 ldr r0, [r0]
 *   @0x2ac588 ldrbtmi r0, [r9], #-1192
 *   @0x2ac58c mov r0, r4
 *   @0x2ac590 .word 0xec531aeb
 *   @0x2ac594 .word 0xeeb72b17
 *   @0x2ac598 vstr s4, [sp, #812]
 *   @0x2ac59c vmov.f64 d1, #1.000000e+00
 *   @0x2ac5a0 vstr s6, [sp, #936]
 *   @0x2ac5a4 vstr d2, [sp, #8]
 *   @0x2ac5a8 .word 0xf60a3b04
 *   @0x2ac5ac mrc p9, #0x5, lr, c7, c12, #0x3
 *   @0x2ac5b0 ldmdbmi r7!, {r3, r6, r7, r9, r11, r12, sp, lr}
 *   @0x2ac5b4 mov r0, r4
 *   @0x2ac5b8 vcvt.f64.f32 d5, s20
 *   @0x2ac5bc vstr d7, [sp, #16]
 *   @0x2ac5c0 vcvt.f64.f32 d6, s18
 *   @0x2ac5c4 vstr d5, [sp]
 *   @0x2ac5c8 vcvt.f64.f32 d7, s19
 *   @0x2ac5cc vstr d6, [sp, #8]
 *   @0x2ac5d0 vmov r2, r3, d7
 *   @0x2ac5d4 blx 0xb68a4 <fprintf@plt>
 *   @0x2ac5d8 b 0x2ac64e <png_handle_cHRM+0x326>
 *   @0x2ac5dc strtmi r7, [r0], -r8, asr #21
 *   @0x2ac5e0 mov r1, r5
 *   @0x2ac5e4 mrc p0, #0x5, r12, c7, c12, #0x1
 *   @0x2ac5e8 vstr s2, [sp, #940]
 *   @0x2ac5ec vmov.f64 d7, #1.750000e+00
 *   @0x2ac5f0 vstr s4, [sp, #812]
 *   @0x2ac5f4 vmov.f64 d1, #1.000000e+00
 *   @0x2ac5f8 vstr s6, [sp, #936]
 *   @0x2ac5fc vmov.f64 d2, #1.125000e+00
 *   @0x2ac600 vstr s8, [sp, #932]
 *   @0x2ac604 vmov.f64 d3, #1.250000e+00
 *   @0x2ac608 vstr s10, [sp, #808]
 *   @0x2ac60c vmov.f64 d4, #1.375000e+00
 *   @0x2ac610 vstr s12, [sp, #804]
 *   @0x2ac614 vmov.f64 d5, #1.500000e+00
 *   @0x2ac618 vstr s14, [sp, #928]
 *   @0x2ac61c .word 0xec536b0a
 *   @0x2ac620 .word 0xf0022b17
 *   @0x2ac624 ldmdbls r0, {r0, r3, r4, r6, r11, r12, sp, lr, pc}
 *   @0x2ac628 ldr.w r12, [sp, #0x3c]
 *   @0x2ac62c mov r0, r4
 *   @0x2ac630 ldrtmi r11, [r10], -r4
 *   @0x2ac634 str r1, [sp, #0x14]
 *   @0x2ac638 str.w r12, [sp]
 *   @0x2ac63c mov r1, r5
 *   @0x2ac640 .word 0xf8cda008
 *   @0x2ac644 .word 0xf8cd900c
 *   @0x2ac648 .word 0xf0028010
 *   @0x2ac64c ldmdbls r1, {r0, r3, r6, r7, r11, r12, sp, lr, pc}
 *   @0x2ac650 ldr r2, [sp, #0x6c]
 *   @0x2ac654 cmp r2, r3
 *   @0x2ac658 blx 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2ac65c add sp, #0x74
 *   @0x2ac660 pop {r3, r8, r9, r11, pc}
 *   @0x2ac664 svclt #0x8ff0
 *   @0x2ac668 str r0, [r0, r0]
 *   @0x2ac66c asrs r2, r4, #0x18
 *   @0x2ac670 lsrs r5, r5, #0xe
 *   @0x2ac674 lsrs r0, r7, #0xe
 *   @0x2ac678 lsrs r6, r0, #0xf
 *   @0x2ac67c lsrs r7, r0, #0xf
 *   @0x2ac680 lsrs r2, r2, #0xf
 *   @0x2ac684 lsrs r4, r0, #0x8
 *   @0x2ac688 ldr r6, [pc, #0x318]
 *   @0x2ac68c lsrs r6, r4, #0x8
 *   @0x2ac690 lsrs r6, r2, #0x8
 *
 * ══ §32/36 b2World::DrawDebugData()  0x2cad9c  size 872  218 条（0x2cad9c..0x2cb104）
 * @func 0x2cad9c 0x2cb104  size 872  218 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2World::DrawShape(b2Fixture*, b2Transform const&, b2Color const&)×4 / b2Draw::GetFlags() const / b2World::DrawParticleSystem(b2ParticleSystem const&) / b2World::DrawJoint(b2Joint*) / b2World::DrawDebugData()+0x294
 * 字段偏移 top8: 0x4×10 / 0x18×5 / 0x1c×5 / 0xc×4 / 0x70×3 / 0x20×3 / 0x74×2 / 0x14×1
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cad9c movw r3, #0x9248
 *   @0x2cada0 movt r3, #0x1
 *   @0x2cada4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2cada8 vpush {d8}
 *   @0x2cadac mov r7, r0
 *   @0x2cadb0 ldr r0, [r0, r3]
 *   @0x2cadb4 sub sp, sp, #60
 *   @0x2cadb8 cmp r0, #0
 *   @0x2cadbc beq 0x2cb0b8 <_ZN7b2World13DrawDebugDataEv+0x31c>
 *   @0x2cadc0 bl 0x2c67e0 <_ZNK6b2Draw8GetFlagsEv>
 *   @0x2cadc4 tst r0, #1
 *   @0x2cadc8 str r0, [sp, #0x4]
 *   @0x2cadcc beq 0x2caecc <_ZN7b2World13DrawDebugDataEv+0x130>
 *   @0x2cadd0 movw r3, #0x9228
 *   @0x2cadd4 movt r3, #0x1
 *   @0x2cadd8 ldr r5, [r7, r3]
 *   @0x2caddc cmp r5, #0
 *   @0x2cade0 beq 0x2caebc <_ZN7b2World13DrawDebugDataEv+0x120>
 *   @0x2cade4 movw r11, #0x6666
 *   @0x2cade8 movw r10, #0x999a
 *   @0x2cadec add r8, sp, #24
 *   @0x2cadf0 movt r11, #0x3f66
 *   @0x2cadf4 movt r10, #0x3f19
 *   @0x2cadf8 mov r9, #1056964608
 *   @0x2cadfc vldr s16, [pc, #760]
 *   @0x2cae00 vldr s17, [pc, #760]
 *   @0x2cae04 ldr r4, [r5, #0x74]
 *   @0x2cae08 add r6, r5, #12
 *   @0x2cae0c cmp r4, #0
 *   @0x2cae10 bne 0x2cae78 <_ZN7b2World13DrawDebugDataEv+0xdc>
 *   @0x2cae14 b 0x2caeb0 <_ZN7b2World13DrawDebugDataEv+0x114>
 *   @0x2cae18 ldr lr, [r5]
 *   @0x2cae1c cmp lr, #0
 *   @0x2cae20 beq 0x2cb0c4 <_ZN7b2World13DrawDebugDataEv+0x328>
 *   @0x2cae24 cmp lr, #1
 *   @0x2cae28 mov r1, r4
 *   @0x2cae2c mov r0, r7
 *   @0x2cae30 mov r2, r6
 *   @0x2cae34 mov r3, r8
 *   @0x2cae38 beq 0x2cb0e8 <_ZN7b2World13DrawDebugDataEv+0x34c>
 *   @0x2cae3c tst r12, #2
 *   @0x2cae40 streq r10, [sp, #0x18]
 *   @0x2cae44 streq r10, [sp, #0x1c]
 *   @0x2cae48 vstrne s16, [sp, #28]
 *   @0x2cae4c moveq r0, r7
 *   @0x2cae50 moveq r1, r4
 *   @0x2cae54 moveq r2, r6
 *   @0x2cae58 moveq r3, r8
 *   @0x2cae5c streq r10, [sp, #0x20]
 *   @0x2cae60 vstrne s16, [sp, #32]
 *   @0x2cae64 strne r11, [sp, #0x18]
 *   @0x2cae68 bl 0x2ca864 <_ZN7b2World9DrawShapeEP9b2FixtureRK11b2TransformRK7b2Color>
 *   @0x2cae6c ldr r4, [r4, #0x4]
 *   @0x2cae70 cmp r4, #0
 *   @0x2cae74 beq 0x2caeb0 <_ZN7b2World13DrawDebugDataEv+0x114>
 *   @0x2cae78 ldrh r12, [r5, #4]
 *   @0x2cae7c tst r12, #32
 *   @0x2cae80 bne 0x2cae18 <_ZN7b2World13DrawDebugDataEv+0x7c>
 *   @0x2cae84 mov r1, r4
 *   @0x2cae88 mov r0, r7
 *   @0x2cae8c mov r2, r6
 *   @0x2cae90 mov r3, r8
 *   @0x2cae94 str r9, [sp, #0x18]
 *   @0x2cae98 vstr s17, [sp, #32]
 *   @0x2cae9c str r9, [sp, #0x1c]
 *   @0x2caea0 bl 0x2ca864 <_ZN7b2World9DrawShapeEP9b2FixtureRK11b2TransformRK7b2Color>
 *   @0x2caea4 ldr r4, [r4, #0x4]
 *   @0x2caea8 cmp r4, #0
 *   @0x2caeac bne 0x2cae78 <_ZN7b2World13DrawDebugDataEv+0xdc>
 *   @0x2caeb0 ldr r5, [r5, #0x70]
 *   @0x2caeb4 cmp r5, #0
 *   @0x2caeb8 bne 0x2cae04 <_ZN7b2World13DrawDebugDataEv+0x68>
 *   @0x2caebc add r1, r7, #102400
 *   @0x2caec0 mov r0, r7
 *   @0x2caec4 add r1, r1, #628
 *   @0x2caec8 bl 0x2cacf4 <_ZN7b2World18DrawParticleSystemERK16b2ParticleSystem>
 *   @0x2caecc ldr r2, [sp, #0x4]
 *   @0x2caed0 tst r2, #2
 *   @0x2caed4 beq 0x2caf04 <_ZN7b2World13DrawDebugDataEv+0x168>
 *   @0x2caed8 movw r3, #0x922c
 *   @0x2caedc movt r3, #0x1
 *   @0x2caee0 ldr r4, [r7, r3]
 *   @0x2caee4 cmp r4, #0
 *   @0x2caee8 beq 0x2caf04 <_ZN7b2World13DrawDebugDataEv+0x168>
 *   @0x2caeec mov r1, r4
 *   @0x2caef0 mov r0, r7
 *   @0x2caef4 bl 0x2cab3c <_ZN7b2World9DrawJointEP7b2Joint>
 *   @0x2caef8 ldr r4, [r4, #0xc]
 *   @0x2caefc cmp r4, #0
 *   @0x2caf00 bne 0x2caeec <_ZN7b2World13DrawDebugDataEv+0x150>
 *   @0x2caf04 ldr r3, [sp, #0x4]
 *   @0x2caf08 tst r3, #8
 *   @0x2caf0c beq 0x2caf30 <_ZN7b2World13DrawDebugDataEv+0x194>
 *   @0x2caf10 movw r3, #0x9214
 *   @0x2caf14 movt r3, #0x1
 *   @0x2caf18 ldr r3, [r7, r3]
 *   @0x2caf1c cmp r3, #0
 *   @0x2caf20 beq 0x2caf30 <_ZN7b2World13DrawDebugDataEv+0x194>
 *   @0x2caf24 ldr r3, [r3, #0xc]
 *   @0x2caf28 cmp r3, #0
 *   @0x2caf2c bne 0x2caf24 <_ZN7b2World13DrawDebugDataEv+0x188>
 *   @0x2caf30 ldr r2, [sp, #0x4]
 *   @0x2caf34 tst r2, #4
 *   @0x2caf38 beq 0x2cb050 <_ZN7b2World13DrawDebugDataEv+0x2b4>
 *   @0x2caf3c movw r3, #0x9228
 *   @0x2caf40 movt r3, #0x1
 *   @0x2caf44 movw r2, #0x6666
 *   @0x2caf48 movw r1, #0x999a
 *   @0x2caf4c ldr r3, [r7, r3]
 *   @0x2caf50 movt r2, #0x3f66
 *   @0x2caf54 movt r1, #0x3e99
 *   @0x2caf58 str r2, [sp, #0xc]
 *   @0x2caf5c cmp r3, #0
 *   @0x2caf60 str r2, [sp, #0x14]
 *   @0x2caf64 str r3, [sp]
 *   @0x2caf68 str r1, [sp, #0x10]
 *   @0x2caf6c beq 0x2cb050 <_ZN7b2World13DrawDebugDataEv+0x2b4>
 *   @0x2caf70 movw r11, #0x91dc
 *   @0x2caf74 movw r8, #0x9248
 *   @0x2caf78 movt r11, #0x1
 *   @0x2caf7c movt r8, #0x1
 *   @0x2caf80 add r10, sp, #24
 *   @0x2caf84 add r9, sp, #12
 *   @0x2caf88 ldr r2, [sp]
 *   @0x2caf8c ldrh r3, [r2, #4]
 *   @0x2caf90 tst r3, #32
 *   @0x2caf94 beq 0x2cb03c <_ZN7b2World13DrawDebugDataEv+0x2a0>
 *   @0x2caf98 ldr r6, [r2, #0x74]
 *   @0x2caf9c cmp r6, #0
 *   @0x2cafa0 beq 0x2cb03c <_ZN7b2World13DrawDebugDataEv+0x2a0>
 *   @0x2cafa4 ldr r3, [r6, #0x1c]
 *   @0x2cafa8 cmp r3, #0
 *   @0x2cafac ble 0x2cb030 <_ZN7b2World13DrawDebugDataEv+0x294>
 *   @0x2cafb0 mov r4, #0
 *   @0x2cafb4 mov r5, r4
 *   @0x2cafb8 ldr r3, [r6, #0x18]
 *   @0x2cafbc mov r1, r10
 *   @0x2cafc0 ldr lr, [r7, r11]
 *   @0x2cafc4 mov r2, #4
 *   @0x2cafc8 add r3, r3, r4
 *   @0x2cafcc ldr r0, [r7, r8]
 *   @0x2cafd0 add r5, r5, #1
 *   @0x2cafd4 add r4, r4, #28
 *   @0x2cafd8 ldr r3, [r3, #0x18]
 *   @0x2cafdc ldr r12, [r0]
 *   @0x2cafe0 add r3, r3, r3, lsl #3
 *   @0x2cafe4 ldr r12, [r12, #0x8]
 *   @0x2cafe8 add r3, lr, r3, lsl #2
 *   @0x2cafec vldr s15, [r3]
 *   @0x2caff0 vldr s13, [r3, #4]
 *   @0x2caff4 vldr s14, [r3, #8]
 *   @0x2caff8 ldr lr, [r3, #0xc]
 *   @0x2caffc mov r3, r9
 *   @0x2cb000 vstr s15, [sp, #24]
 *   @0x2cb004 vstr s13, [sp, #28]
 *   @0x2cb008 vstr s14, [sp, #32]
 *   @0x2cb00c vstr s13, [sp, #36]
 *   @0x2cb010 vstr s14, [sp, #40]
 *   @0x2cb014 str lr, [sp, #0x2c]
 *   @0x2cb018 vstr s15, [sp, #48]
 *   @0x2cb01c str lr, [sp, #0x34]
 *   @0x2cb020 blx r12
 *   @0x2cb024 ldr r3, [r6, #0x1c]
 *   @0x2cb028 cmp r3, r5
 *   @0x2cb02c bgt 0x2cafb8 <_ZN7b2World13DrawDebugDataEv+0x21c>
 *   @0x2cb030 ldr r6, [r6, #0x4]
 *   @0x2cb034 cmp r6, #0
 *   @0x2cb038 bne 0x2cafa4 <_ZN7b2World13DrawDebugDataEv+0x208>
 *   @0x2cb03c ldr r3, [sp]
 *   @0x2cb040 ldr r3, [r3, #0x70]
 *   @0x2cb044 cmp r3, #0
 *   @0x2cb048 str r3, [sp]
 *   @0x2cb04c bne 0x2caf88 <_ZN7b2World13DrawDebugDataEv+0x1ec>
 *   @0x2cb050 ldr r2, [sp, #0x4]
 *   @0x2cb054 tst r2, #16
 *   @0x2cb058 beq 0x2cb0b8 <_ZN7b2World13DrawDebugDataEv+0x31c>
 *   @0x2cb05c movw r3, #0x9228
 *   @0x2cb060 movt r3, #0x1
 *   @0x2cb064 ldr r5, [r7, r3]
 *   @0x2cb068 cmp r5, #0
 *   @0x2cb06c beq 0x2cb0b8 <_ZN7b2World13DrawDebugDataEv+0x31c>
 *   @0x2cb070 movw r8, #0x9248
 *   @0x2cb074 add r4, sp, #24
 *   @0x2cb078 movt r8, #0x1
 *   @0x2cb07c add r3, r5, #12
 *   @0x2cb080 ldr r12, [r7, r8]
 *   @0x2cb084 add lr, r5, #60
 *   @0x2cb088 ldm r3, {r0, r1, r2, r3}
 *   @0x2cb08c ldr r6, [r12]
 *   @0x2cb090 stm r4, {r0, r1, r2, r3}
 *   @0x2cb094 ldm lr, {r0, r1}
 *   @0x2cb098 ldr r3, [r6, #0x20]
 *   @0x2cb09c stm r4, {r0, r1}
 *   @0x2cb0a0 mov r0, r12
 *   @0x2cb0a4 mov r1, r4
 *   @0x2cb0a8 blx r3
 *   @0x2cb0ac ldr r5, [r5, #0x70]
 *   @0x2cb0b0 cmp r5, #0
 *   @0x2cb0b4 bne 0x2cb07c <_ZN7b2World13DrawDebugDataEv+0x2e0>
 *   @0x2cb0b8 add sp, sp, #60
 *   @0x2cb0bc vpop {d8}
 *   @0x2cb0c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2cb0c4 mov r0, r7
 *   @0x2cb0c8 mov r1, r4
 *   @0x2cb0cc mov r2, r6
 *   @0x2cb0d0 mov r3, r8
 *   @0x2cb0d4 str r9, [sp, #0x18]
 *   @0x2cb0d8 str r11, [sp, #0x1c]
 *   @0x2cb0dc str r9, [sp, #0x20]
 *   @0x2cb0e0 bl 0x2ca864 <_ZN7b2World9DrawShapeEP9b2FixtureRK11b2TransformRK7b2Color>
 *   @0x2cb0e4 b 0x2cae6c <_ZN7b2World13DrawDebugDataEv+0xd0>
 *   @0x2cb0e8 str r9, [sp, #0x18]
 *   @0x2cb0ec str r9, [sp, #0x1c]
 *   @0x2cb0f0 str r11, [sp, #0x20]
 *   @0x2cb0f4 bl 0x2ca864 <_ZN7b2World9DrawShapeEP9b2FixtureRK11b2TransformRK7b2Color>
 *   @0x2cb0f8 b 0x2cae6c <_ZN7b2World13DrawDebugDataEv+0xd0>
 *   @0x2cb0fc svclo #0x333333
 *   @0x2cb100 mrclo p9, #0x4, r9, c9, c10, #0x4
 *
 * ══ §33/36 yySocket::Broadcast(int, unsigned char*, int)  0x295bc8  size 864  216 条（0x295bc8..0x295f28）
 * @func 0x295bc8 0x295f28  size 864  216 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x295e34→0x3eb70c, 0x295e58→0x3eb70c, 0x295e8c→0x3eb70c, 0x295ec8→0x3eb70c
 * 调用序列: 0xb6d9c×4 / 0xb6bf8×3 / 0xb6e74×2 / yySocket::Broadcast(int, unsigned char*, int)+0xbc×2 / 0xb6dc0×2 / 0xb6da8×2 / 0xb6e50 / yySocket::Broadcast(int, unsigned char*, int)+0x26c
 * 字段偏移 top8: 0x4×10 / 0xc×6 / 0x20×3 / 0x24×3 / 0x18×3 / 0x1c×3 / 0x34×2 / 0x1a×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x295bc8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x295bcc mov r4, r0
 *   @0x295bd0 ldr r5, [pc, #0x328]
 *   @0x295bd4 mov r7, r3
 *   @0x295bd8 ldr r0, [pc, #0x324]
 *   @0x295bdc sub sp, sp, #60
 *   @0x295be0 add r5, pc, r5
 *   @0x295be4 ldrb lr, [r4, #0xc4]
 *   @0x295be8 mov r9, r1
 *   @0x295bec mov r8, r2
 *   @0x295bf0 ldr r6, [r5, r0]
 *   @0x295bf4 cmp lr, #0
 *   @0x295bf8 ldr r3, [r6]
 *   @0x295bfc str r3, [sp, #0x34]
 *   @0x295c00 bne 0x295c8c <_ZN8yySocket9BroadcastEiPhi+0xc4>
 *   @0x295c04 ldr r0, [r4, #0x4]
 *   @0x295c08 cmn r0, #1
 *   @0x295c0c beq 0x295d24 <_ZN8yySocket9BroadcastEiPhi+0x15c>
 *   @0x295c10 mov r3, #0
 *   @0x295c14 mov r2, #2
 *   @0x295c18 mov r12, r9
 *   @0x295c1c str r3, [sp, #0x20]
 *   @0x295c20 str r3, [sp, #0x24]
 *   @0x295c24 strh r2, [sp, #24]
 *   @0x295c28 rev16 r12, r12
 *   @0x295c2c mov r2, #16
 *   @0x295c30 add r1, sp, #24
 *   @0x295c34 str r2, [sp, #0x4]
 *   @0x295c38 mov r2, r7
 *   @0x295c3c str r1, [sp]
 *   @0x295c40 mov r1, r8
 *   @0x295c44 strh r12, [sp, #26]
 *   @0x295c48 mvn r12, #0
 *   @0x295c4c str r12, [sp, #0x1c]
 *   @0x295c50 bl 0xb6e74 <sendto@plt>
 *   @0x295c54 cmp r0, #0
 *   @0x295c58 blt 0x295c84 <_ZN8yySocket9BroadcastEiPhi+0xbc>
 *   @0x295c5c cmp r7, r0
 *   @0x295c60 mvngt r12, #2
 *   @0x295c64 movle r12, #0
 *   @0x295c68 ldr r2, [sp, #0x34]
 *   @0x295c6c mov r0, r12
 *   @0x295c70 ldr r3, [r6]
 *   @0x295c74 cmp r2, r3
 *   @0x295c78 bne 0x295efc <_ZN8yySocket9BroadcastEiPhi+0x334>
 *   @0x295c7c add sp, sp, #60
 *   @0x295c80 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x295c84 mvn r12, #1
 *   @0x295c88 b 0x295c68 <_ZN8yySocket9BroadcastEiPhi+0xa0>
 *   @0x295c8c ldr r0, [pc, #0x274]
 *   @0x295c90 add r0, pc, r0
 *   @0x295c94 bl 0xb6e50 <if_nametoindex@plt>
 *   @0x295c98 ldr r3, [r4, #0x4]
 *   @0x295c9c cmn r3, #1
 *   @0x295ca0 addne r10, sp, #24
 *   @0x295ca4 str r0, [sp, #0x10]
 *   @0x295ca8 movne r3, r0
 *   @0x295cac beq 0x295d70 <_ZN8yySocket9BroadcastEiPhi+0x1a8>
 *   @0x295cb0 mov r5, #0
 *   @0x295cb4 mov r0, #10
 *   @0x295cb8 str r5, [sp, #0x1c]
 *   @0x295cbc str r5, [sp, #0x20]
 *   @0x295cc0 str r5, [sp, #0x24]
 *   @0x295cc4 str r5, [sp, #0x28]
 *   @0x295cc8 str r5, [sp, #0x2c]
 *   @0x295ccc strh r0, [sp, #24]
 *   @0x295cd0 rev16 r9, r9
 *   @0x295cd4 ldr r1, [pc, #0x230]
 *   @0x295cd8 add r2, sp, #32
 *   @0x295cdc str r3, [sp, #0x30]
 *   @0x295ce0 add r1, pc, r1
 *   @0x295ce4 strh r9, [sp, #26]
 *   @0x295ce8 bl 0xb6dc0 <inet_pton@plt>
 *   @0x295cec ldr r0, [r4, #0x4]
 *   @0x295cf0 mov r12, #28
 *   @0x295cf4 mov r1, r8
 *   @0x295cf8 str r10, [sp]
 *   @0x295cfc mov r3, r5
 *   @0x295d00 mov r2, r7
 *   @0x295d04 str r12, [sp, #0x4]
 *   @0x295d08 bl 0xb6e74 <sendto@plt>
 *   @0x295d0c cmp r0, #0
 *   @0x295d10 blt 0x295c84 <_ZN8yySocket9BroadcastEiPhi+0xbc>
 *   @0x295d14 cmp r7, r0
 *   @0x295d18 mvngt r12, #2
 *   @0x295d1c movle r12, r5
 *   @0x295d20 b 0x295c68 <_ZN8yySocket9BroadcastEiPhi+0xa0>
 *   @0x295d24 mov r0, #2
 *   @0x295d28 mov r2, lr
 *   @0x295d2c mov r1, r0
 *   @0x295d30 bl 0xb6da8 <socket@plt>
 *   @0x295d34 cmn r0, #1
 *   @0x295d38 mov r12, r0
 *   @0x295d3c str r0, [r4, #0x4]
 *   @0x295d40 beq 0x295c68 <_ZN8yySocket9BroadcastEiPhi+0xa0>
 *   @0x295d44 add r3, sp, #56
 *   @0x295d48 mov r1, #1
 *   @0x295d4c mov r12, #4
 *   @0x295d50 mov r2, #6
 *   @0x295d54 str r1, [r3, #-0x24]!
 *   @0x295d58 str r12, [sp]
 *   @0x295d5c bl 0xb6d9c <setsockopt@plt>
 *   @0x295d60 cmp r0, #0
 *   @0x295d64 blt 0x295e34 <_ZN8yySocket9BroadcastEiPhi+0x26c>
 *   @0x295d68 ldr r0, [r4, #0x4]
 *   @0x295d6c b 0x295c10 <_ZN8yySocket9BroadcastEiPhi+0x48>
 *   @0x295d70 mov r0, #10
 *   @0x295d74 mov r1, #2
 *   @0x295d78 mov r2, #0
 *   @0x295d7c bl 0xb6da8 <socket@plt>
 *   @0x295d80 cmn r0, #1
 *   @0x295d84 mov r12, r0
 *   @0x295d88 str r0, [r4, #0x4]
 *   @0x295d8c beq 0x295c68 <_ZN8yySocket9BroadcastEiPhi+0xa0>
 *   @0x295d90 add r3, sp, #56
 *   @0x295d94 mov r1, #0
 *   @0x295d98 mov r2, #4
 *   @0x295d9c str r1, [r3, #-0x24]!
 *   @0x295da0 mov r1, #41
 *   @0x295da4 str r2, [sp]
 *   @0x295da8 mov r2, #26
 *   @0x295dac bl 0xb6d9c <setsockopt@plt>
 *   @0x295db0 cmp r0, #0
 *   @0x295db4 blt 0x295ec8 <_ZN8yySocket9BroadcastEiPhi+0x300>
 *   @0x295db8 add r10, sp, #24
 *   @0x295dbc ldr r1, [pc, #0x14c]
 *   @0x295dc0 mov r0, #10
 *   @0x295dc4 mov r3, #0
 *   @0x295dc8 add r1, pc, r1
 *   @0x295dcc mov r2, r10
 *   @0x295dd0 str r3, [sp, #0x18]
 *   @0x295dd4 str r3, [sp, #0x1c]
 *   @0x295dd8 str r3, [sp, #0x20]
 *   @0x295ddc str r3, [sp, #0x24]
 *   @0x295de0 str r3, [sp, #0x28]
 *   @0x295de4 bl 0xb6dc0 <inet_pton@plt>
 *   @0x295de8 ldr r0, [r4, #0x4]
 *   @0x295dec mov r2, #20
 *   @0x295df0 mov r3, r10
 *   @0x295df4 str r2, [sp]
 *   @0x295df8 mov r1, #41
 *   @0x295dfc bl 0xb6d9c <setsockopt@plt>
 *   @0x295e00 cmp r0, #0
 *   @0x295e04 blt 0x295e8c <_ZN8yySocket9BroadcastEiPhi+0x2c4>
 *   @0x295e08 ldr r0, [r4, #0x4]
 *   @0x295e0c mov r3, #4
 *   @0x295e10 mov r1, #41
 *   @0x295e14 str r3, [sp]
 *   @0x295e18 mov r2, #17
 *   @0x295e1c add r3, sp, #16
 *   @0x295e20 bl 0xb6d9c <setsockopt@plt>
 *   @0x295e24 cmp r0, #0
 *   @0x295e28 blt 0x295e58 <_ZN8yySocket9BroadcastEiPhi+0x290>
 *   @0x295e2c ldr r3, [sp, #0x10]
 *   @0x295e30 b 0x295cb0 <_ZN8yySocket9BroadcastEiPhi+0xe8>
 *   @0x295e34 ldr r3, [pc, #0xd8]
 *   @0x295e38 ldr r1, [pc, #0xd8]
 *   @0x295e3c ldr r3, [r5, r3]
 *   @0x295e40 add r1, pc, r1
 *   @0x295e44 ldr r0, [r3]
 *   @0x295e48 ldr r3, [r0]
 *   @0x295e4c ldr r3, [r3, #0xc]
 *   @0x295e50 blx r3
 *   @0x295e54 b 0x295d68 <_ZN8yySocket9BroadcastEiPhi+0x1a0>
 *   @0x295e58 ldr r3, [pc, #0xb4]
 *   @0x295e5c ldr r3, [r5, r3]
 *   @0x295e60 ldr r5, [r3]
 *   @0x295e64 ldr r3, [r5]
 *   @0x295e68 ldr r11, [r3, #0xc]
 *   @0x295e6c bl 0xb6bf8 <__errno@plt>
 *   @0x295e70 ldr r1, [pc, #0xa4]
 *   @0x295e74 add r1, pc, r1
 *   @0x295e78 mov r3, r0
 *   @0x295e7c mov r0, r5
 *   @0x295e80 ldr r2, [r3]
 *   @0x295e84 blx r11
 *   @0x295e88 b 0x295e2c <_ZN8yySocket9BroadcastEiPhi+0x264>
 *   @0x295e8c ldr r3, [pc, #0x80]
 *   @0x295e90 ldr r3, [r5, r3]
 *   @0x295e94 ldr r11, [r3]
 *   @0x295e98 ldr r3, [r11]
 *   @0x295e9c ldr r3, [r3, #0xc]
 *   @0x295ea0 str r3, [sp, #0xc]
 *   @0x295ea4 bl 0xb6bf8 <__errno@plt>
 *   @0x295ea8 ldr r1, [pc, #0x70]
 *   @0x295eac ldr r3, [sp, #0xc]
 *   @0x295eb0 add r1, pc, r1
 *   @0x295eb4 mov r2, r0
 *   @0x295eb8 mov r0, r11
 *   @0x295ebc ldr r2, [r2]
 *   @0x295ec0 blx r3
 *   @0x295ec4 b 0x295e08 <_ZN8yySocket9BroadcastEiPhi+0x240>
 *   @0x295ec8 ldr r3, [pc, #0x44]
 *   @0x295ecc ldr r3, [r5, r3]
 *   @0x295ed0 ldr r10, [r3]
 *   @0x295ed4 ldr r3, [r10]
 *   @0x295ed8 ldr r11, [r3, #0xc]
 *   @0x295edc bl 0xb6bf8 <__errno@plt>
 *   @0x295ee0 ldr r1, [pc, #0x3c]
 *   @0x295ee4 add r1, pc, r1
 *   @0x295ee8 mov r3, r0
 *   @0x295eec mov r0, r10
 *   @0x295ef0 ldr r2, [r3]
 *   @0x295ef4 blx r11
 *   @0x295ef8 b 0x295db8 <_ZN8yySocket9BroadcastEiPhi+0x1f0>
 *   @0x295efc bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x295f00 andseq r12, r5, r0, ror r0
 *   @0x295f04 .word 0xffffbd00
 *   @0x295f08 andeq r3, r12, r8, asr r6
 *   @0x295f0c andeq r3, r12, r8, ror #9
 *   @0x295f10 andeq r3, r12, r0, lsl #8
 *   @0x295f14 .word 0xffffbac4
 *   @0x295f18 andeq r3, r12, r4, lsl #11
 *   @0x295f1c andeq r3, r12, r8, lsr #10
 *   @0x295f20 andeq r3, r12, r8, asr #9
 *   @0x295f24 andeq r3, r12, r4, ror r4
 *
 * ══ §34/36 png_read_destroy  0x2a7c64  size 456  51 条（0x2a7c64..0x2a7e2c）｜其中 63 条已由别的卡落锚，本节不再重复
 * @func 0x2a7c7c 0x2a7e28  size 428  51 条
 * 部分覆盖: 本节 51/186 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_free×7 / png_info_destroy / 0xb69e8
 * 字段偏移 top8: 0x1f×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a7c7c strtmi pc, [r0], -r0, lsr #18
 *   @0x2a7c8c .word 0xf7ff12f4
 *   @0x2a7c90 qasxmi pc, r0, r5
 *   @0x2a7ca0 .word 0xf7ff1330
 *   @0x2a7ca4 strtmi pc, [r0], -r11, lsr #16
 *   @0x2a7cb4 .word 0xf7ff12b4
 *   @0x2a7cb8 strtmi pc, [r0], -r1, lsr #16
 *   @0x2a7cc8 .word 0xf7ff122c
 *   @0x2a7ccc .word 0xf8d4f817
 *   @0x2a7cd0 qasxmi r1, r0, r0
 *   @0x2a7ce4 .word 0xf7fd11d8
 *   @0x2a7ce8 .word 0xf8d4ff03
 *   @0x2a7cec vld1.64 {d3, d4, d5, d6}, [r3], r0
 *   @0x2a7cf0 .word 0xf8c45280
 *   @0x2a7cf4 ldreq r2, [r10], #704
 *   @0x2a7d10 strle r2, [r4, #-0x2c0]
 *   @0x2a7d18 .word 0xf7fe12b8
 *   @0x2a7d1c .word 0xf8d4ffef
 *   @0x2a7d20 .word 0xf02332c0
 *   @0x2a7d24 .word 0xf8c40308
 *   @0x2a7d28 .word 0xf8d432c0
 *   @0x2a7d2c .word 0xb1b33234
 *   @0x2a7d44 qasxmi r3, r0, r4
 *   @0x2a7d50 ubfx pc, r5, #0x1f, #0x15
 *   @0x2a7d58 .word 0xf7fe1234
 *   @0x2a7d5c .word 0xf8d4ffcf
 *   @0x2a7d60 .word 0xb1b33238
 *   @0x2a7d78 qasxmi r3, r0, r8
 *   @0x2a7d84 .word 0xe7f4ffbb
 *   @0x2a7d8c .word 0xf7fe1238
 *   @0x2a7d90 .word 0xf8d4ffb5
 *   @0x2a7d94 .word 0xb1b3323c
 *   @0x2a7dac qasxmi r3, r0, r12
 *   @0x2a7db8 ldrb pc, [r4, r1, lsr #31]!
 *   @0x2a7dc0 .word 0xf7fe123c
 *   @0x2a7dc4 .word 0xf8d4ff9b
 *   @0x2a7dc8 .word 0x462012bc
 *   @0x2a7ddc .word 0xf7fe1274
 *   @0x2a7de0 strtmi pc, [r1], -sp, lsl #31
 *   @0x2a7de8 .word 0xf60e7280
 *   @0x2a7dec .word 0xf8d4ebe8
 *   @0x2a7df0 .word 0xf8d49104
 *   @0x2a7df4 strtmi r8, [r0], -r8, lsl #2
 *   @0x2a7e00 vst1.64 {d22, d23, d24, d25}, [pc:256], r0
 *   @0x2a7e04 .word 0xf60e724e
 *   @0x2a7e08 .word 0xf8c4ebd4
 *   @0x2a7e0c .word 0xf8c49104
 *   @0x2a7e10 strtmi r8, [r0], -r8, lsl #2
 *   @0x2a7e1c vst1.64 {d22, d23, d24, d25}, [pc:256], r0
 *   @0x2a7e20 .word 0xf60e7280
 *   @0x2a7e24 sublt lr, r1, r12, asr #23
 *
 * ══ §35/36 Eff_Check_Systems()  0x1a24f4  size 220  41 条（0x1a24f4..0x1a25d0）｜其中 14 条已由别的卡落锚，本节不再重复
 * @func 0x1a24f4 0x1a25d0  size 220  41 条
 * 部分覆盖: 本节 41/55 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1a24fc→0x3f5088, 0x1a2518→0x3f5084, 0x1a2530→0x542458, 0x1a2558→0x5428e8, 0x1a2590→0x5428e8
 * 调用序列: ParticleSystem_Exists(int)×2 / ParticleSystem_Create(int, bool)×2 / ParticleSystem_Depth(int, float)×2
 * 字段偏移 top8: 0xbc×2 / 0xa4×1 / 0x90×1 / 0x6c×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a24f4 push {r3, r4, r5, lr}
 *   @0x1a24f8 ldr r4, [pc, #0xbc]
 *   @0x1a24fc ldr r3, [pc, #0xbc]
 *   @0x1a2500 add r4, pc, r4
 *   @0x1a2504 ldr r5, [r4, r3]
 *   @0x1a2508 ldr r0, [r5]
 *   @0x1a250c bl 0x1a3770 <_Z21ParticleSystem_Existsi>
 *   @0x1a2510 cmp r0, #0
 *   @0x1a2514 beq 0x1a2584 <_Z17Eff_Check_Systemsv+0x90>
 *   @0x1a2518 ldr r3, [pc, #0xa4]
 *   @0x1a251c ldr r5, [r4, r3]
 *   @0x1a2520 ldr r0, [r5]
 *   @0x1a2524 bl 0x1a3770 <_Z21ParticleSystem_Existsi>
 *   @0x1a2528 cmp r0, #0
 *   @0x1a252c beq 0x1a254c <_Z17Eff_Check_Systemsv+0x58>
 *   @0x1a2530 ldr r3, [pc, #0x90]
 *   @0x1a2534 ldr r3, [r4, r3]
 *   @0x1a2538 ldrb r3, [r3]
 *   @0x1a253c cmp r3, #0
 *   @0x1a2540 popne {r3, r4, r5, pc}
 *   @0x1a2544 pop {r3, r4, r5, lr}
 *   @0x1a2548 b 0x1a24a8 <_Z16Eff_Create_Typesv>
 *   @0x1a254c mov r1, #1
 *   @0x1a256c movne r1, #24576
 *   @0x1a2570 moveq r1, #20480
 *   @0x1a2574 movtne r1, #0xc66a
 *   @0x1a2578 movteq r1, #0xc7c3
 *   @0x1a257c bl 0x1a47d4 <_Z20ParticleSystem_Depthif>
 *   @0x1a2580 b 0x1a2530 <_Z17Eff_Check_Systemsv+0x3c>
 *   @0x1a2584 mov r1, #1
 *   @0x1a25a4 movne r1, #0
 *   @0x1a25a8 moveq r1, #20480
 *   @0x1a25ac movtne r1, #0x4248
 *   @0x1a25b0 movteq r1, #0x47c3
 *   @0x1a25b4 bl 0x1a47d4 <_Z20ParticleSystem_Depthif>
 *   @0x1a25b8 b 0x1a2518 <_Z17Eff_Check_Systemsv+0x24>
 *   @0x1a25bc eoreq pc, r4, r0, asr r7
 *   @0x1a25c0 .word 0xffffeb54
 *   @0x1a25c4 .word 0xffffeb58
 *   @0x1a25c8 .word 0xffffeb50
 *   @0x1a25cc .word 0xffffbcd4
 *
 * ══ §36/36 CSkeletonSprite::HasData()  0xbd96c  size 48  12 条（0xbd96c..0xbd99c）
 * @func 0xbd96c 0xbd99c  size 48  12 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbd96c ldr r3, [r0]
 *   @0xbd970 cmp r3, #0
 *   @0xbd974 beq 0xbd994 <_ZN15CSkeletonSprite7HasDataEv+0x28>
 *   @0xbd978 ldr r3, [r0, #0x4]
 *   @0xbd97c cmp r3, #0
 *   @0xbd980 beq 0xbd994 <_ZN15CSkeletonSprite7HasDataEv+0x28>
 *   @0xbd984 ldr r0, [r0, #0x8]
 *   @0xbd988 adds r0, r0, #0
 *   @0xbd98c movne r0, #1
 *   @0xbd990 bx lr
 *   @0xbd994 mov r0, r3
 *   @0xbd998 bx lr
 */
