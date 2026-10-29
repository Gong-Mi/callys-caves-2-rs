/* cally 逆向卡：All_27 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 21 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/21 anon_1c8380  0x1c8380  size 1568  392 条（0x1c8380..0x1c89a0）
 * @func 0x1c8380 0x1c89a0  size 1568  392 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CObjectGM::IsDecendentOf(int)×3 / CInstance::Collision_Instance(CInstance*, bool)×3 / CollisionIsRemoved(CInstance*)×2 / 0xb65a4 / 0xb6538 / _itoa(int, char*, int) / anon_1c8380+0x14c / CInstance::Collision_Rectangle(float, float, float, float, bool)
 * 字段偏移 top8: 0x78×7 / 0x28×6 / 0x68×5 / 0x69×5 / 0x48×5 / 0xc×4 / 0x80×3 / 0x18×3
 * VFP 指令 81 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1c8380 push {r3, r4, r5, lr}
 *   @0x1c8384 mov r5, r1
 *   @0x1c8388 ldr r4, [pc, #0x2c]
 *   @0x1c838c mov r1, r0
 *   @0x1c8390 add r4, pc, r4
 *   @0x1c8394 mov r0, r4
 *   @0x1c8398 bl 0xb65a4 <strcpy@plt>
 *   @0x1c839c mov r0, r4
 *   @0x1c83a0 bl 0xb6538 <strlen@plt>
 *   @0x1c83a4 mov r2, #10
 *   @0x1c83a8 add r1, r4, r0
 *   @0x1c83ac mov r0, r5
 *   @0x1c83b0 bl 0xc4964 <_Z5_itoaiPci>
 *   @0x1c83b4 mov r0, r4
 *   @0x1c83b8 pop {r3, r4, r5, pc}
 *   @0x1c83bc eorseq r10, r7, r12, lsl r3
 *   @0x1c83c0 ldrb r3, [r0, #0x68]
 *   @0x1c83c4 push {r4, r5, r6, r7, lr}
 *   @0x1c83c8 cmp r3, #0
 *   @0x1c83cc sub sp, sp, #12
 *   @0x1c83d0 mov r5, r0
 *   @0x1c83d4 mov r6, r1
 *   @0x1c83d8 bne 0x1c83e8 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xf18>
 *   @0x1c83dc ldrb r4, [r0, #0x69]
 *   @0x1c83e0 cmp r4, #0
 *   @0x1c83e4 beq 0x1c83f8 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xf28>
 *   @0x1c83e8 mov r4, #1
 *   @0x1c83ec mov r0, r4
 *   @0x1c83f0 add sp, sp, #12
 *   @0x1c83f4 pop {r4, r5, r6, r7, pc}
 *   @0x1c83f8 ldr r3, [r0, #0x48]
 *   @0x1c83fc cmp r3, #1
 *   @0x1c8400 bne 0x1c83e8 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xf18>
 *   @0x1c8404 ldr r7, [pc, #0xe8]
 *   @0x1c8408 add r7, pc, r7
 *   @0x1c840c ldr r1, [r7]
 *   @0x1c8410 cmn r1, #3
 *   @0x1c8414 beq 0x1c844c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xf7c>
 *   @0x1c8418 movw r3, #0x869f
 *   @0x1c841c movt r3, #0x1
 *   @0x1c8420 cmp r1, r3
 *   @0x1c8424 bgt 0x1c84bc <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xfec>
 *   @0x1c8428 cmp r1, #0
 *   @0x1c842c blt 0x1c84cc <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xffc>
 *   @0x1c8430 ldr r0, [r5, #0x80]
 *   @0x1c8434 ldr r3, [r0, #0x18]
 *   @0x1c8438 cmp r3, r1
 *   @0x1c843c beq 0x1c844c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xf7c>
 *   @0x1c8440 bl 0x19ddb0 <_ZN9CObjectGM13IsDecendentOfEi>
 *   @0x1c8444 cmp r0, #0
 *   @0x1c8448 beq 0x1c83e8 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xf18>
 *   @0x1c844c ldrb r3, [r6, #0x21]
 *   @0x1c8450 cmp r3, #0
 *   @0x1c8454 beq 0x1c8464 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xf94>
 *   @0x1c8458 ldr r3, [r6, #0x24]
 *   @0x1c845c cmp r3, r5
 *   @0x1c8460 beq 0x1c83e8 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xf18>
 *   @0x1c8464 vldr d7, [r6, #24]
 *   @0x1c8468 vldr d4, [r6]
 *   @0x1c846c vcvt.f32.f64 s14, d7
 *   @0x1c8470 vldr d5, [r6, #8]
 *   @0x1c8474 vldr d6, [r6, #16]
 *   @0x1c8478 ldrb r3, [r6, #0x20]
 *   @0x1c847c mov r0, r5
 *   @0x1c8480 str r3, [sp, #0x4]
 *   @0x1c8484 vcvt.f32.f64 s15, d4
 *   @0x1c8488 vstr s14, [sp]
 *   @0x1c848c vmov r1, s15
 *   @0x1c8490 vcvt.f32.f64 s15, d5
 *   @0x1c8494 vmov r2, s15
 *   @0x1c8498 vcvt.f32.f64 s15, d6
 *   @0x1c849c vmov r3, s15
 *   @0x1c84a0 bl 0x1946f4 <_ZN9CInstance19Collision_RectangleEffffb>
 *   @0x1c84a4 cmp r0, #0
 *   @0x1c84a8 beq 0x1c83e8 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xf18>
 *   @0x1c84ac ldr r3, [pc, #0x44]
 *   @0x1c84b0 ldr r3, [pc, r3]
 *   @0x1c84b4 str r5, [r3]
 *   @0x1c84b8 b 0x1c83ec <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xf1c>
 *   @0x1c84bc ldr r3, [r5, #0x78]
 *   @0x1c84c0 cmp r1, r3
 *   @0x1c84c4 bne 0x1c83e8 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xf18>
 *   @0x1c84c8 b 0x1c844c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xf7c>
 *   @0x1c84cc ldr r3, [pc, #0x28]
 *   @0x1c84d0 ldr r1, [pc, #0x28]
 *   @0x1c84d4 ldr r3, [pc, r3]
 *   @0x1c84d8 add r1, pc, r1
 *   @0x1c84dc ldr r0, [r3]
 *   @0x1c84e0 ldr r3, [r0]
 *   @0x1c84e4 ldr r3, [r3, #0xc]
 *   @0x1c84e8 blx r3
 *   @0x1c84ec ldr r1, [r7]
 *   @0x1c84f0 b 0x1c8430 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xf60>
 *   @0x1c84f4 .word 0x0022ccd8
 *   @0x1c84f8 eoreq r8, r2, r8, asr r6
 *   @0x1c84fc eoreq r5, r2, r0, asr #4
 *   @0x1c8500 andseq r8, r8, r12, ror #12
 *   @0x1c8504 ldrb r3, [r0, #0x68]
 *   @0x1c8508 push {r4, r5, r6, r7, lr}
 *   @0x1c850c cmp r3, #0
 *   @0x1c8510 sub sp, sp, #12
 *   @0x1c8514 mov r5, r0
 *   @0x1c8518 mov r6, r1
 *   @0x1c851c bne 0x1c852c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x105c>
 *   @0x1c8520 ldrb r4, [r0, #0x69]
 *   @0x1c8524 cmp r4, #0
 *   @0x1c8528 beq 0x1c853c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x106c>
 *   @0x1c852c mov r4, #1
 *   @0x1c8530 mov r0, r4
 *   @0x1c8534 add sp, sp, #12
 *   @0x1c8538 pop {r4, r5, r6, r7, pc}
 *   @0x1c853c ldr r3, [r0, #0x48]
 *   @0x1c8540 cmp r3, #1
 *   @0x1c8544 bne 0x1c852c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x105c>
 *   @0x1c8548 ldr r7, [pc, #0xe8]
 *   @0x1c854c add r7, pc, r7
 *   @0x1c8550 ldr r1, [r7]
 *   @0x1c8554 cmn r1, #3
 *   @0x1c8558 beq 0x1c8590 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x10c0>
 *   @0x1c855c movw r3, #0x869f
 *   @0x1c8560 movt r3, #0x1
 *   @0x1c8564 cmp r1, r3
 *   @0x1c8568 bgt 0x1c8600 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x1130>
 *   @0x1c856c cmp r1, #0
 *   @0x1c8570 blt 0x1c8610 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x1140>
 *   @0x1c8574 ldr r0, [r5, #0x80]
 *   @0x1c8578 ldr r3, [r0, #0x18]
 *   @0x1c857c cmp r3, r1
 *   @0x1c8580 beq 0x1c8590 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x10c0>
 *   @0x1c8584 bl 0x19ddb0 <_ZN9CObjectGM13IsDecendentOfEi>
 *   @0x1c8588 cmp r0, #0
 *   @0x1c858c beq 0x1c852c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x105c>
 *   @0x1c8590 ldrb r3, [r6, #0x21]
 *   @0x1c8594 cmp r3, #0
 *   @0x1c8598 beq 0x1c85a8 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x10d8>
 *   @0x1c859c ldr r3, [r6, #0x24]
 *   @0x1c85a0 cmp r3, r5
 *   @0x1c85a4 beq 0x1c852c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x105c>
 *   @0x1c85a8 vldr d7, [r6, #24]
 *   @0x1c85ac vldr d4, [r6]
 *   @0x1c85b0 vcvt.f32.f64 s14, d7
 *   @0x1c85b4 vldr d5, [r6, #8]
 *   @0x1c85b8 vldr d6, [r6, #16]
 *   @0x1c85bc ldrb r3, [r6, #0x20]
 *   @0x1c85c0 mov r0, r5
 *   @0x1c85c4 str r3, [sp, #0x4]
 *   @0x1c85c8 vcvt.f32.f64 s15, d4
 *   @0x1c85cc vstr s14, [sp]
 *   @0x1c85d0 vmov r1, s15
 *   @0x1c85d4 vcvt.f32.f64 s15, d5
 *   @0x1c85d8 vmov r2, s15
 *   @0x1c85dc vcvt.f32.f64 s15, d6
 *   @0x1c85e0 vmov r3, s15
 *   @0x1c85e4 bl 0x194f28 <_ZN9CInstance14Collision_LineEffffb>
 *   @0x1c85e8 cmp r0, #0
 *   @0x1c85ec beq 0x1c852c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x105c>
 *   @0x1c85f0 ldr r3, [pc, #0x44]
 *   @0x1c85f4 ldr r3, [pc, r3]
 *   @0x1c85f8 str r5, [r3]
 *   @0x1c85fc b 0x1c8530 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x1060>
 *   @0x1c8600 ldr r3, [r5, #0x78]
 *   @0x1c8604 cmp r1, r3
 *   @0x1c8608 bne 0x1c852c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x105c>
 *   @0x1c860c b 0x1c8590 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x10c0>
 *   @0x1c8610 ldr r3, [pc, #0x28]
 *   @0x1c8614 ldr r1, [pc, #0x28]
 *   @0x1c8618 ldr r3, [pc, r3]
 *   @0x1c861c add r1, pc, r1
 *   @0x1c8620 ldr r0, [r3]
 *   @0x1c8624 ldr r3, [r0]
 *   @0x1c8628 ldr r3, [r3, #0xc]
 *   @0x1c862c blx r3
 *   @0x1c8630 ldr r1, [r7]
 *   @0x1c8634 b 0x1c8574 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x10a4>
 *   @0x1c8638 mlaeq r2, r4, r11, r12
 *   @0x1c863c eoreq r8, r2, r4, lsl r5
 *   @0x1c8640 .word 0x002250fc
 *   @0x1c8644 andseq r8, r8, r8, lsr #10
 *   @0x1c8648 cmp r1, r0
 *   @0x1c864c push {r3, r4, r5, r6, r7, lr}
 *   @0x1c8650 mov r5, r0
 *   @0x1c8654 mov r6, r1
 *   @0x1c8658 beq 0x1c8668 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x1198>
 *   @0x1c865c ldrb r3, [r0, #0x68]
 *   @0x1c8660 cmp r3, #0
 *   @0x1c8664 beq 0x1c8674 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x11a4>
 *   @0x1c8668 mov r4, #1
 *   @0x1c866c mov r0, r4
 *   @0x1c8670 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1c8674 ldrb r4, [r0, #0x69]
 *   @0x1c8678 cmp r4, #0
 *   @0x1c867c bne 0x1c8668 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x1198>
 *   @0x1c8680 ldr r3, [r0, #0x48]
 *   @0x1c8684 cmp r3, #1
 *   @0x1c8688 bne 0x1c8668 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x1198>
 *   @0x1c868c ldr r7, [pc, #0xa0]
 *   @0x1c8690 add r7, pc, r7
 *   @0x1c8694 ldr r1, [r7]
 *   @0x1c8698 cmn r1, #3
 *   @0x1c869c beq 0x1c86d4 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x1204>
 *   @0x1c86a0 movw r3, #0x869f
 *   @0x1c86a4 movt r3, #0x1
 *   @0x1c86a8 cmp r1, r3
 *   @0x1c86ac bgt 0x1c86fc <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x122c>
 *   @0x1c86b0 cmp r1, #0
 *   @0x1c86b4 blt 0x1c870c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x123c>
 *   @0x1c86b8 ldr r0, [r5, #0x80]
 *   @0x1c86bc ldr r3, [r0, #0x18]
 *   @0x1c86c0 cmp r3, r1
 *   @0x1c86c4 beq 0x1c86d4 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x1204>
 *   @0x1c86c8 bl 0x19ddb0 <_ZN9CObjectGM13IsDecendentOfEi>
 *   @0x1c86cc cmp r0, #0
 *   @0x1c86d0 beq 0x1c8668 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x1198>
 *   @0x1c86d4 mov r1, r6
 *   @0x1c86d8 mov r0, r5
 *   @0x1c86dc mov r2, #1
 *   @0x1c86e0 bl 0x195558 <_ZN9CInstance18Collision_InstanceEPS_b>
 *   @0x1c86e4 cmp r0, #0
 *   @0x1c86e8 beq 0x1c8668 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x1198>
 *   @0x1c86ec ldr r3, [pc, #0x44]
 *   @0x1c86f0 ldr r3, [pc, r3]
 *   @0x1c86f4 str r5, [r3]
 *   @0x1c86f8 b 0x1c866c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x119c>
 *   @0x1c86fc ldr r3, [r5, #0x78]
 *   @0x1c8700 cmp r1, r3
 *   @0x1c8704 bne 0x1c8668 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x1198>
 *   @0x1c8708 b 0x1c86d4 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x1204>
 *   @0x1c870c ldr r3, [pc, #0x28]
 *   @0x1c8710 ldr r1, [pc, #0x28]
 *   @0x1c8714 ldr r3, [pc, r3]
 *   @0x1c8718 add r1, pc, r1
 *   @0x1c871c ldr r0, [r3]
 *   @0x1c8720 ldr r3, [r0]
 *   @0x1c8724 ldr r3, [r3, #0xc]
 *   @0x1c8728 blx r3
 *   @0x1c872c ldr r1, [r7]
 *   @0x1c8730 b 0x1c86b8 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x11e8>
 *   @0x1c8734 eoreq r12, r2, r0, asr r10
 *   @0x1c8738 eoreq r8, r2, r8, lsl r4
 *   @0x1c873c eoreq r5, r2, r0
 *   @0x1c8740 andseq r8, r8, r12, asr #8
 *   @0x1c8744 push {r3, r4, r5, r6, r7, lr}
 *   @0x1c8748 mov r6, r1
 *   @0x1c874c mov r5, r0
 *   @0x1c8750 bl 0x1cc244 <_Z18CollisionIsRemovedP9CInstance>
 *   @0x1c8754 cmp r0, #0
 *   @0x1c8758 bne 0x1c87c0 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x12f0>
 *   @0x1c875c ldrb r4, [r5, #0x68]
 *   @0x1c8760 cmp r4, #0
 *   @0x1c8764 beq 0x1c8770 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x12a0>
 *   @0x1c8768 mov r0, r4
 *   @0x1c876c pop {r3, r4, r5, r6, r7, pc}
 *   @0x1c8770 ldrb r4, [r5, #0x69]
 *   @0x1c8774 cmp r4, #0
 *   @0x1c8778 bne 0x1c8768 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x1298>
 *   @0x1c877c ldr r7, [r5, #0x48]
 *   @0x1c8780 cmp r7, #1
 *   @0x1c8784 bne 0x1c87c0 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x12f0>
 *   @0x1c8788 ldr r2, [r5, #0x78]
 *   @0x1c878c ldr r3, [r6, #0x78]
 *   @0x1c8790 cmp r2, r3
 *   @0x1c8794 beq 0x1c87cc <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x12fc>
 *   @0x1c8798 mov r0, r5
 *   @0x1c879c mov r1, r6
 *   @0x1c87a0 mov r2, r7
 *   @0x1c87a4 bl 0x195558 <_ZN9CInstance18Collision_InstanceEPS_b>
 *   @0x1c87a8 cmp r0, #0
 *   @0x1c87ac beq 0x1c87cc <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x12fc>
 *   @0x1c87b0 ldr r3, [pc, #0x1c]
 *   @0x1c87b4 add r3, pc, r3
 *   @0x1c87b8 strb r4, [r3, #0x200]
 *   @0x1c87bc b 0x1c8768 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x1298>
 *   @0x1c87c0 mov r4, #1
 *   @0x1c87c4 mov r0, r4
 *   @0x1c87c8 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1c87cc mov r4, r7
 *   @0x1c87d0 b 0x1c8768 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x1298>
 *   @0x1c87d4 ldrshteq r9, [r7], -r8
 *   @0x1c87d8 push {r4, r5, r6, lr}
 *   @0x1c87dc mov r6, r1
 *   @0x1c87e0 mov r5, r0
 *   @0x1c87e4 bl 0x1cc244 <_Z18CollisionIsRemovedP9CInstance>
 *   @0x1c87e8 cmp r0, #0
 *   @0x1c87ec bne 0x1c883c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x136c>
 *   @0x1c87f0 ldrb r4, [r5, #0x68]
 *   @0x1c87f4 cmp r4, #0
 *   @0x1c87f8 beq 0x1c8804 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x1334>
 *   @0x1c87fc mov r0, r4
 *   @0x1c8800 pop {r4, r5, r6, pc}
 *   @0x1c8804 ldrb r4, [r5, #0x69]
 *   @0x1c8808 cmp r4, #0
 *   @0x1c880c bne 0x1c87fc <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x132c>
 *   @0x1c8810 ldr r2, [r5, #0x48]
 *   @0x1c8814 cmp r2, #1
 *   @0x1c8818 bne 0x1c883c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x136c>
 *   @0x1c881c ldr r1, [r5, #0x78]
 *   @0x1c8820 ldr r3, [r6, #0x78]
 *   @0x1c8824 cmp r1, r3
 *   @0x1c8828 moveq r4, r2
 *   @0x1c882c beq 0x1c87fc <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x132c>
 *   @0x1c8830 ldrb r3, [r5, #0x66]
 *   @0x1c8834 cmp r3, #0
 *   @0x1c8838 bne 0x1c8848 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x1378>
 *   @0x1c883c mov r4, #1
 *   @0x1c8840 mov r0, r4
 *   @0x1c8844 pop {r4, r5, r6, pc}
 *   @0x1c8848 mov r0, r5
 *   @0x1c884c mov r1, r6
 *   @0x1c8850 bl 0x195558 <_ZN9CInstance18Collision_InstanceEPS_b>
 *   @0x1c8854 cmp r0, #0
 *   @0x1c8858 beq 0x1c883c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x136c>
 *   @0x1c885c ldr r3, [pc, #0x8]
 *   @0x1c8860 add r3, pc, r3
 *   @0x1c8864 strb r4, [r3, #0x200]
 *   @0x1c8868 b 0x1c87fc <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x132c>
 *   @0x1c886c eorseq r9, r7, r12, asr #28
 *   @0x1c8870 ldr r3, [r1, #0x8]
 *   @0x1c8874 vldr s14, [r0]
 *   @0x1c8878 vldr s15, [r0, #4]
 *   @0x1c887c vldr s10, [r0, #12]
 *   @0x1c8880 add r2, r3, #1
 *   @0x1c8884 vldr s12, [r0, #8]
 *   @0x1c8888 vmov s13, r2
 *   @0x1c888c vcvt.f32.s32 s13, s13
 *   @0x1c8890 vcmpe.f32 s14, s13
 *   @0x1c8894 vmrs APSR_nzcv, fpscr
 *   @0x1c8898 bge 0x1c8994 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x14c4>
 *   @0x1c889c vadd.f32 s12, s14, s12
 *   @0x1c88a0 vldr s8, [r1]
 *   @0x1c88a4 vcvt.f32.s32 s11, s8
 *   @0x1c88a8 vcmpe.f32 s12, s11
 *   @0x1c88ac vmrs APSR_nzcv, fpscr
 *   @0x1c88b0 bmi 0x1c8994 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x14c4>
 *   @0x1c88b4 vadd.f32 s13, s15, s10
 *   @0x1c88b8 ldr r2, [r1, #0xc]
 *   @0x1c88bc add r2, r2, #1
 *   @0x1c88c0 vmov s9, r2
 *   @0x1c88c4 vcmpe.f32 s15, s13
 *   @0x1c88c8 vcvt.f32.s32 s10, s9
 *   @0x1c88cc vmrs APSR_nzcv, fpscr
 *   @0x1c88d0 vmovpl.f32 s9, s13
 *   @0x1c88d4 vmovmi.f32 s9, s15
 *   @0x1c88d8 vcmpe.f32 s10, s9
 *   @0x1c88dc vmrs APSR_nzcv, fpscr
 *   @0x1c88e0 bls 0x1c8994 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x14c4>
 *   @0x1c88e4 vcmpe.f32 s15, s13
 *   @0x1c88e8 vldr s9, [r1, #4]
 *   @0x1c88ec vcvt.f32.s32 s9, s9
 *   @0x1c88f0 vmrs APSR_nzcv, fpscr
 *   @0x1c88f4 vmovle.f32 s8, s13
 *   @0x1c88f8 vmovgt.f32 s8, s15
 *   @0x1c88fc vcmpe.f32 s9, s8
 *   @0x1c8900 vmrs APSR_nzcv, fpscr
 *   @0x1c8904 bgt 0x1c8994 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x14c4>
 *   @0x1c8908 vcmpe.f32 s14, s11
 *   @0x1c890c vmrs APSR_nzcv, fpscr
 *   @0x1c8910 bpl 0x1c8930 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x1460>
 *   @0x1c8914 vsub.f32 s7, s11, s14
 *   @0x1c8918 vsub.f32 s8, s13, s15
 *   @0x1c891c vmul.f32 s7, s7, s8
 *   @0x1c8920 vsub.f32 s8, s12, s14
 *   @0x1c8924 vmov.f32 s14, s11
 *   @0x1c8928 vdiv.f32 s11, s7, s8
 *   @0x1c892c vadd.f32 s15, s15, s11
 *   @0x1c8930 vmov s8, r3
 *   @0x1c8934 vcvt.f32.s32 s11, s8
 *   @0x1c8938 vcmpe.f32 s12, s11
 *   @0x1c893c vmrs APSR_nzcv, fpscr
 *   @0x1c8940 ble 0x1c895c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x148c>
 *   @0x1c8944 vsub.f32 s11, s11, s12
 *   @0x1c8948 vsub.f32 s8, s13, s15
 *   @0x1c894c vmul.f32 s11, s11, s8
 *   @0x1c8950 vsub.f32 s12, s12, s14
 *   @0x1c8954 vdiv.f32 s12, s11, s12
 *   @0x1c8958 vadd.f32 s13, s13, s12
 *   @0x1c895c vcmpe.f32 s9, s15
 *   @0x1c8960 vmrs APSR_nzcv, fpscr
 *   @0x1c8964 ble 0x1c8974 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x14a4>
 *   @0x1c8968 vcmpe.f32 s9, s13
 *   @0x1c896c vmrs APSR_nzcv, fpscr
 *   @0x1c8970 bgt 0x1c8994 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x14c4>
 *   @0x1c8974 vcmpe.f32 s10, s15
 *   @0x1c8978 vmrs APSR_nzcv, fpscr
 *   @0x1c897c bhi 0x1c899c <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0x14cc>
 *   @0x1c8980 vcmpe.f32 s10, s13
 *   @0x1c8984 vmrs APSR_nzcv, fpscr
 *   @0x1c8988 movls r0, #0
 *   @0x1c898c movhi r0, #1
 *   @0x1c8990 bx lr
 *   @0x1c8994 mov r0, #0
 *   @0x1c8998 bx lr
 *   @0x1c899c mov r0, #1
 *
 * ══ §2/21 Debug_GetWatches(Buffer_Standard*, Buffer_Standard*)  0x29dafc  size 1568  392 条（0x29dafc..0x29e11c）
 * @func 0x29dafc 0x29e11c  size 1568  392 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x29dba0→0x47f298, 0x29dbc0→0x3eb8a8, 0x29dbc8→0x757e50
 * 调用序列: YYGetUint32(RValue const*, int)×13 / MemoryManager::Free(void const*)×6 / ReadString(Buffer_Standard*)×4 / Debug_GetWatches(Buffer_Standard*, Buffer_Standard*)+0x5d0 / operator new[](unsigned int) / YYGetInt32(RValue const*, int) / New_Code_Variable_Find(char const*, EVariableType) / Code_Function_Find(char const*, int*)
 * 字段偏移 top8: 0xc×14 / 0x-68×6 / 0x-78×5 / 0x-3c×4 / 0x-9c×3 / 0x-90×3 / 0x-94×3 / 0x-98×3
 * VFP 指令 10 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29dafc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x29db00 vpush {d8}
 *   @0x29db04 add r11, sp, #40
 *   @0x29db08 ldr r5, [pc, #0x5f8]
 *   @0x29db0c sub sp, sp, #132
 *   @0x29db10 ldr r12, [pc, #0x5f4]
 *   @0x29db14 add r5, pc, r5
 *   @0x29db18 str r1, [r11, #-0x78]
 *   @0x29db1c ldr r3, [r0]
 *   @0x29db20 add r10, r0, #44
 *   @0x29db24 ldr r12, [r5, r12]
 *   @0x29db28 mov r1, #5
 *   @0x29db2c ldr r4, [r11, #-0x78]
 *   @0x29db30 mov r2, r10
 *   @0x29db34 ldr r3, [r3, #0xc]
 *   @0x29db38 mov r8, r0
 *   @0x29db3c str r12, [r11, #-0xa8]
 *   @0x29db40 add r4, r4, #44
 *   @0x29db44 ldr r12, [r12]
 *   @0x29db48 str r4, [r11, #-0x9c]
 *   @0x29db4c mov r4, #0
 *   @0x29db50 str r12, [r11, #-0x30]
 *   @0x29db54 blx r3
 *   @0x29db58 mov r1, r4
 *   @0x29db5c mov r0, r10
 *   @0x29db60 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29db64 ldr r3, [r11, #-0x78]
 *   @0x29db68 ldr r2, [r11, #-0x9c]
 *   @0x29db6c mov r1, #5
 *   @0x29db70 ldr lr, [r3]
 *   @0x29db74 str r4, [r3, #0x38]
 *   @0x29db78 vmov s15, r0
 *   @0x29db7c str r0, [r11, #-0x90]
 *   @0x29db80 mov r0, r3
 *   @0x29db84 vcvt.f64.u32 d7, s15
 *   @0x29db88 vmov r6, r7, d7
 *   @0x29db8c mov r6, r0
 *   @0x29db90 vstr s14, [r0, #44]
 *   @0x29db94 str r7, [r6, #0x30]
 *   @0x29db98 ldr r3, [lr, #0x8]
 *   @0x29db9c blx r3
 *   @0x29dba0 ldr r3, [pc, #0x568]
 *   @0x29dba4 ldr r12, [r11, #-0x90]
 *   @0x29dba8 ldr r3, [r5, r3]
 *   @0x29dbac cmp r12, r4
 *   @0x29dbb0 str r3, [r11, #-0x94]
 *   @0x29dbb4 ldr r3, [r3]
 *   @0x29dbb8 str r3, [r11, #-0x98]
 *   @0x29dbbc ble 0x29e0cc <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x5d0>
 *   @0x29dbc0 ldr r3, [pc, #0x54c]
 *   @0x29dbc4 sub r6, r11, #76
 *   @0x29dbc8 ldr r2, [pc, #0x548]
 *   @0x29dbcc sub r12, r11, #92
 *   @0x29dbd0 str r4, [r11, #-0x7c]
 *   @0x29dbd4 mov r4, #0
 *   @0x29dbd8 str r6, [r11, #-0xa4]
 *   @0x29dbdc movt r4, #0xc007
 *   @0x29dbe0 str r4, [r11, #-0xa0]
 *   @0x29dbe4 sub r4, r11, #96
 *   @0x29dbe8 ldr r3, [r5, r3]
 *   @0x29dbec str r12, [r11, #-0x84]
 *   @0x29dbf0 ldr r2, [r5, r2]
 *   @0x29dbf4 add r3, r3, #8
 *   @0x29dbf8 str r4, [r11, #-0x74]
 *   @0x29dbfc str r3, [r11, #-0x8c]
 *   @0x29dc00 str r2, [r11, #-0x88]
 *   @0x29dc04 ldr r3, [r8]
 *   @0x29dc08 mov r2, r10
 *   @0x29dc0c mov r1, #5
 *   @0x29dc10 mov r0, r8
 *   @0x29dc14 ldr r3, [r3, #0xc]
 *   @0x29dc18 blx r3
 *   @0x29dc1c mov r1, #0
 *   @0x29dc20 mov r0, r10
 *   @0x29dc24 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29dc28 vmov s16, r0
 *   @0x29dc2c mov r0, r8
 *   @0x29dc30 bl 0x29e69c <_Z10ReadStringP15Buffer_Standard>
 *   @0x29dc34 ldr r3, [r8]
 *   @0x29dc38 mov r2, r10
 *   @0x29dc3c mov r1, #5
 *   @0x29dc40 ldr r3, [r3, #0xc]
 *   @0x29dc44 str r0, [r11, #-0x80]
 *   @0x29dc48 mov r0, r8
 *   @0x29dc4c blx r3
 *   @0x29dc50 mov r1, #0
 *   @0x29dc54 mov r0, r10
 *   @0x29dc58 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29dc5c ldr r6, [r11, #-0x8c]
 *   @0x29dc60 mov r12, #0
 *   @0x29dc64 str r12, [r11, #-0x3c]
 *   @0x29dc68 str r12, [r11, #-0x38]
 *   @0x29dc6c str r6, [r11, #-0x4c]
 *   @0x29dc70 str r12, [r11, #-0x34]
 *   @0x29dc74 mov r5, r0
 *   @0x29dc78 str r0, [r11, #-0x48]
 *   @0x29dc7c bl 0x27d14c <_Znaj>
 *   @0x29dc80 cmp r5, #0
 *   @0x29dc84 mov r4, r0
 *   @0x29dc88 str r0, [r11, #-0x3c]
 *   @0x29dc8c addne r5, r0, r5
 *   @0x29dc90 movne r6, r0
 *   @0x29dc94 beq 0x29dcc8 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x1cc>
 *   @0x29dc98 ldr r3, [r8]
 *   @0x29dc9c mov r1, #1
 *   @0x29dca0 mov r2, r10
 *   @0x29dca4 mov r0, r8
 *   @0x29dca8 ldr r3, [r3, #0xc]
 *   @0x29dcac blx r3
 *   @0x29dcb0 mov r0, r10
 *   @0x29dcb4 mov r1, #0
 *   @0x29dcb8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x29dcbc strb r0, [r6], #1
 *   @0x29dcc0 cmp r6, r5
 *   @0x29dcc4 bne 0x29dc98 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x19c>
 *   @0x29dcc8 ldr r3, [r8]
 *   @0x29dccc mov r1, #5
 *   @0x29dcd0 mov r2, r10
 *   @0x29dcd4 mov r0, r8
 *   @0x29dcd8 ldr r3, [r3, #0xc]
 *   @0x29dcdc blx r3
 *   @0x29dce0 mov r0, r10
 *   @0x29dce4 mov r1, #0
 *   @0x29dce8 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29dcec cmp r0, #0
 *   @0x29dcf0 str r0, [r11, #-0x70]
 *   @0x29dcf4 movne r3, #0
 *   @0x29dcf8 strne r3, [r11, #-0x6c]
 *   @0x29dcfc beq 0x29dde4 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x2e8>
 *   @0x29dd00 mov r0, r8
 *   @0x29dd04 bl 0x29e69c <_Z10ReadStringP15Buffer_Standard>
 *   @0x29dd08 ldr r3, [r8]
 *   @0x29dd0c mov r1, #5
 *   @0x29dd10 mov r2, r10
 *   @0x29dd14 ldr r3, [r3, #0xc]
 *   @0x29dd18 mov r6, r0
 *   @0x29dd1c mov r0, r8
 *   @0x29dd20 blx r3
 *   @0x29dd24 mov r0, r10
 *   @0x29dd28 mov r1, #0
 *   @0x29dd2c bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29dd30 cmp r0, #0
 *   @0x29dd34 str r0, [r11, #-0x68]
 *   @0x29dd38 movne r5, #0
 *   @0x29dd3c beq 0x29ddc4 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x2c8>
 *   @0x29dd40 ldr r3, [r8]
 *   @0x29dd44 mov r2, r10
 *   @0x29dd48 mov r1, #5
 *   @0x29dd4c mov r0, r8
 *   @0x29dd50 add r5, r5, #1
 *   @0x29dd54 ldr r3, [r3, #0xc]
 *   @0x29dd58 blx r3
 *   @0x29dd5c mov r1, #0
 *   @0x29dd60 mov r0, r10
 *   @0x29dd64 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29dd68 ldr r3, [r8]
 *   @0x29dd6c mov r2, r10
 *   @0x29dd70 mov r1, #5
 *   @0x29dd74 ldr r3, [r3, #0xc]
 *   @0x29dd78 mov r9, r0
 *   @0x29dd7c mov r0, r8
 *   @0x29dd80 blx r3
 *   @0x29dd84 mov r1, #0
 *   @0x29dd88 mov r0, r10
 *   @0x29dd8c bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29dd90 mov r1, r9
 *   @0x29dd94 mov r7, r0
 *   @0x29dd98 mov r0, r6
 *   @0x29dd9c bl 0xd20c0 <_Z22New_Code_Variable_FindPKc13EVariableType>
 *   @0x29dda0 add r3, r7, #4
 *   @0x29dda4 ldr r12, [r11, #-0x68]
 *   @0x29dda8 ldr r2, [r4, r3]
 *   @0x29ddac cmp r5, r12
 *   @0x29ddb0 and r2, r2, #-268435456
 *   @0x29ddb4 bic r0, r0, #-268435456
 *   @0x29ddb8 orr r2, r2, r0
 *   @0x29ddbc str r2, [r4, r3]
 *   @0x29ddc0 bne 0x29dd40 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x244>
 *   @0x29ddc4 mov r0, r6
 *   @0x29ddc8 ldr r6, [r11, #-0x6c]
 *   @0x29ddcc add r6, r6, #1
 *   @0x29ddd0 str r6, [r11, #-0x6c]
 *   @0x29ddd4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x29ddd8 ldr r12, [r11, #-0x70]
 *   @0x29dddc cmp r6, r12
 *   @0x29dde0 bne 0x29dd00 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x204>
 *   @0x29dde4 ldr r3, [r8]
 *   @0x29dde8 mov r1, #5
 *   @0x29ddec mov r2, r10
 *   @0x29ddf0 mov r0, r8
 *   @0x29ddf4 ldr r3, [r3, #0xc]
 *   @0x29ddf8 blx r3
 *   @0x29ddfc mov r0, r10
 *   @0x29de00 mov r1, #0
 *   @0x29de04 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29de08 cmp r0, #0
 *   @0x29de0c str r0, [r11, #-0x68]
 *   @0x29de10 movne r6, #0
 *   @0x29de14 beq 0x29deb0 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x3b4>
 *   @0x29de18 mov r0, r8
 *   @0x29de1c bl 0x29e69c <_Z10ReadStringP15Buffer_Standard>
 *   @0x29de20 sub r1, r11, #96
 *   @0x29de24 mov r9, r0
 *   @0x29de28 bl 0xce158 <_Z18Code_Function_FindPKcPi>
 *   @0x29de2c ldr r12, [r8]
 *   @0x29de30 mov r1, #5
 *   @0x29de34 mov r2, r10
 *   @0x29de38 mov r0, r8
 *   @0x29de3c ldr r12, [r12, #0xc]
 *   @0x29de40 blx r12
 *   @0x29de44 mov r0, r10
 *   @0x29de48 mov r1, #0
 *   @0x29de4c bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29de50 subs r7, r0, #0
 *   @0x29de54 movne r5, #0
 *   @0x29de58 beq 0x29de98 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x39c>
 *   @0x29de5c ldr r3, [r8]
 *   @0x29de60 mov r1, #5
 *   @0x29de64 mov r2, r10
 *   @0x29de68 mov r0, r8
 *   @0x29de6c add r5, r5, #1
 *   @0x29de70 ldr r3, [r3, #0xc]
 *   @0x29de74 blx r3
 *   @0x29de78 mov r0, r10
 *   @0x29de7c mov r1, #0
 *   @0x29de80 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29de84 ldr r3, [r11, #-0x60]
 *   @0x29de88 cmp r5, r7
 *   @0x29de8c add r0, r4, r0
 *   @0x29de90 str r3, [r0, #0x4]
 *   @0x29de94 bne 0x29de5c <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x360>
 *   @0x29de98 mov r0, r9
 *   @0x29de9c add r6, r6, #1
 *   @0x29dea0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x29dea4 ldr r12, [r11, #-0x68]
 *   @0x29dea8 cmp r6, r12
 *   @0x29deac bne 0x29de18 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x31c>
 *   @0x29deb0 ldr r3, [r8]
 *   @0x29deb4 mov r1, #5
 *   @0x29deb8 mov r2, r10
 *   @0x29debc mov r0, r8
 *   @0x29dec0 ldr r3, [r3, #0xc]
 *   @0x29dec4 blx r3
 *   @0x29dec8 mov r0, r10
 *   @0x29decc mov r1, #0
 *   @0x29ded0 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29ded4 lsl r3, r0, #2
 *   @0x29ded8 cmp r0, #0
 *   @0x29dedc add r3, r3, #14
 *   @0x29dee0 mov r5, r0
 *   @0x29dee4 bic r3, r3, #7
 *   @0x29dee8 movne r7, #0
 *   @0x29deec sub sp, sp, r3
 *   @0x29def0 ldr r3, [r11, #-0x88]
 *   @0x29def4 subne r6, sp, #4
 *   @0x29def8 mov r9, sp
 *   @0x29defc str sp, [r3]
 *   @0x29df00 beq 0x29df1c <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x420>
 *   @0x29df04 mov r0, r8
 *   @0x29df08 add r7, r7, #1
 *   @0x29df0c bl 0x29e69c <_Z10ReadStringP15Buffer_Standard>
 *   @0x29df10 cmp r7, r5
 *   @0x29df14 str r0, [r6, #0x4]!
 *   @0x29df18 bne 0x29df04 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x408>
 *   @0x29df1c ldr r3, [r8]
 *   @0x29df20 mov r1, #5
 *   @0x29df24 mov r2, r10
 *   @0x29df28 mov r0, r8
 *   @0x29df2c ldr r3, [r3, #0xc]
 *   @0x29df30 blx r3
 *   @0x29df34 mov r0, r10
 *   @0x29df38 mov r1, #0
 *   @0x29df3c bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29df40 subs r6, r0, #0
 *   @0x29df44 beq 0x29df90 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x494>
 *   @0x29df48 str r5, [r11, #-0x68]
 *   @0x29df4c mov r7, #0
 *   @0x29df50 ldr r5, [r11, #-0xa0]
 *   @0x29df54 ldr r12, [r8]
 *   @0x29df58 mov r1, #5
 *   @0x29df5c mov r2, r10
 *   @0x29df60 mov r0, r8
 *   @0x29df64 add r7, r7, #1
 *   @0x29df68 ldr r12, [r12, #0xc]
 *   @0x29df6c blx r12
 *   @0x29df70 mov r0, r10
 *   @0x29df74 mov r1, #0
 *   @0x29df78 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29df7c cmp r7, r6
 *   @0x29df80 add r0, r4, r0
 *   @0x29df84 str r5, [r0, #-0x4]
 *   @0x29df88 bne 0x29df54 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x458>
 *   @0x29df8c ldr r5, [r11, #-0x68]
 *   @0x29df90 ldr r3, [r11, #-0x98]
 *   @0x29df94 sub r1, r11, #76
 *   @0x29df98 ldr r4, [r11, #-0x94]
 *   @0x29df9c sub r2, r11, #92
 *   @0x29dfa0 ldr r0, [r11, #-0x80]
 *   @0x29dfa4 str r3, [r4]
 *   @0x29dfa8 bl 0x29a83c <_Z18ExecuteDebugScriptPcP8VMBufferP6RValue>
 *   @0x29dfac vcvt.f64.u32 d7, s16
 *   @0x29dfb0 ldr r3, [r11, #-0x78]
 *   @0x29dfb4 ldr r2, [r11, #-0x9c]
 *   @0x29dfb8 mov r4, #0
 *   @0x29dfbc mov r1, #5
 *   @0x29dfc0 ldr lr, [r3]
 *   @0x29dfc4 mov r0, r3
 *   @0x29dfc8 str r4, [r3, #0x38]
 *   @0x29dfcc vmov r6, r7, d7
 *   @0x29dfd0 mov r6, r0
 *   @0x29dfd4 vstr s14, [r6, #44]
 *   @0x29dfd8 str r7, [r6, #0x30]
 *   @0x29dfdc ldr r3, [lr, #0x8]
 *   @0x29dfe0 blx r3
 *   @0x29dfe4 sub r0, r11, #92
 *   @0x29dfe8 ldr r1, [r11, #-0x78]
 *   @0x29dfec bl 0xd8a88 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard>
 *   @0x29dff0 ldr r0, [r11, #-0x80]
 *   @0x29dff4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x29dff8 ldr r3, [r11, #-0x50]
 *   @0x29dffc sub r3, r3, #1
 *   @0x29e000 bic r3, r3, #-16777216
 *   @0x29e004 bic r3, r3, #3
 *   @0x29e008 cmp r3, r4
 *   @0x29e00c beq 0x29e0f8 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x5fc>
 *   @0x29e010 cmp r5, #0
 *   @0x29e014 mov r12, #0
 *   @0x29e018 mov r0, #5
 *   @0x29e01c str r12, [r11, #-0x54]
 *   @0x29e020 str r0, [r11, #-0x50]
 *   @0x29e024 subne r9, r9, #4
 *   @0x29e028 str r12, [r11, #-0x5c]
 *   @0x29e02c movne r4, #0
 *   @0x29e030 beq 0x29e048 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x54c>
 *   @0x29e034 add r4, r4, #1
 *   @0x29e038 ldr r0, [r9, #0x4]!
 *   @0x29e03c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x29e040 cmp r4, r5
 *   @0x29e044 bne 0x29e034 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x538>
 *   @0x29e048 ldr r0, [r11, #-0x38]
 *   @0x29e04c mov r4, #0
 *   @0x29e050 ldr r3, [r11, #-0x88]
 *   @0x29e054 ldr r6, [r11, #-0x8c]
 *   @0x29e058 cmp r0, r4
 *   @0x29e05c str r4, [r3]
 *   @0x29e060 str r6, [r11, #-0x4c]
 *   @0x29e064 beq 0x29e074 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x578>
 *   @0x29e068 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x29e06c mov r12, #0
 *   @0x29e070 str r12, [r11, #-0x38]
 *   @0x29e074 ldr r0, [r11, #-0x34]
 *   @0x29e078 cmp r0, #0
 *   @0x29e07c beq 0x29e08c <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x590>
 *   @0x29e080 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x29e084 mov r0, #0
 *   @0x29e088 str r0, [r11, #-0x34]
 *   @0x29e08c ldr r0, [r11, #-0x3c]
 *   @0x29e090 cmp r0, #0
 *   @0x29e094 beq 0x29e0b4 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x5b8>
 *   @0x29e098 bl 0x1aad50 <_Z11MemoryInWadPv>
 *   @0x29e09c cmp r0, #0
 *   @0x29e0a0 bne 0x29e0b4 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x5b8>
 *   @0x29e0a4 ldr r0, [r11, #-0x3c]
 *   @0x29e0a8 cmp r0, #0
 *   @0x29e0ac beq 0x29e0b4 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x5b8>
 *   @0x29e0b0 bl 0x27d1d4 <_ZdaPv>
 *   @0x29e0b4 ldr r3, [r11, #-0x7c]
 *   @0x29e0b8 ldr r4, [r11, #-0x90]
 *   @0x29e0bc add r3, r3, #1
 *   @0x29e0c0 str r3, [r11, #-0x7c]
 *   @0x29e0c4 cmp r4, r3
 *   @0x29e0c8 bne 0x29dc04 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x108>
 *   @0x29e0cc ldr r4, [r11, #-0xa8]
 *   @0x29e0d0 ldr r2, [r11, #-0x30]
 *   @0x29e0d4 ldr r6, [r11, #-0x98]
 *   @0x29e0d8 ldr r3, [r4]
 *   @0x29e0dc ldr r12, [r11, #-0x94]
 *   @0x29e0e0 cmp r2, r3
 *   @0x29e0e4 str r6, [r12]
 *   @0x29e0e8 bne 0x29e104 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x608>
 *   @0x29e0ec sub sp, r11, #40
 *   @0x29e0f0 vpop {d8}
 *   @0x29e0f4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x29e0f8 sub r0, r11, #92
 *   @0x29e0fc bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x29e100 b 0x29e010 <_Z16Debug_GetWatchesP15Buffer_StandardS0_+0x514>
 *   @0x29e104 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x29e108 andseq r4, r5, r12, lsr r1
 *   @0x29e10c .word 0xffffbd00
 *   @0x29e110 .word 0xffffbf58
 *   @0x29e114 .word 0xffffbedc
 *   @0x29e118 .word 0xffffc118
 *
 * ══ §3/21 DrawParticles(RParticleSystem*, int, int, int)  0x1a5094  size 1560  390 条（0x1a5094..0x1a56ac）
 * @func 0x1a5094 0x1a56ac  size 1560  390 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1a50e0→0x54246c, 0x1a51f8→0x542474, 0x1a53c8→0x4859ac, 0x1a561c→0x5424ac
 * 调用序列: DrawParticles(RParticleSystem*, int, int, int)+0x5ac×3 / GR_D3D_Set_Blend(int)×2 / GR_Texture_Draw(YYTPageEntry*, float, float, float, float, float, float, float, unsigned int, float) / Sprite_Exists(int) / Graphics::AllocVerts(ePrimType, void*, int, int) / Sprite_Data(int) / __divsi3 / 0xb6580
 * 字段偏移 top8: 0x4×18 / 0x2×10 / 0x18×7 / 0x30×6 / 0x8×6 / 0x1c×6 / 0xc×5 / 0x2c×5
 * VFP 指令 150 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a5094 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1a5098 vpush {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x1a509c cmp r1, r2
 *   @0x1a50a0 vldr s19, [r0, #32]
 *   @0x1a50a4 sub sp, sp, #60
 *   @0x1a50a8 ldr r11, [pc, #0x43c]
 *   @0x1a50ac mov r10, r0
 *   @0x1a50b0 vldr s20, [r0, #36]
 *   @0x1a50b4 str r2, [sp, #0x28]
 *   @0x1a50b8 add r11, pc, r11
 *   @0x1a50bc str r3, [sp, #0x24]
 *   @0x1a50c0 beq 0x1a5470 <_Z13DrawParticlesP15RParticleSystemiii+0x3dc>
 *   @0x1a50c4 ldr r3, [r0, #0x4]
 *   @0x1a50c8 ldr r4, [r3, r1, lsl #2]
 *   @0x1a50cc ldr r3, [r4, #0xc]
 *   @0x1a50d0 cmp r3, #0
 *   @0x1a50d4 ble 0x1a5640 <_Z13DrawParticlesP15RParticleSystemiii+0x5ac>
 *   @0x1a50d8 ldr r2, [sp, #0x24]
 *   @0x1a50dc vldr s23, [pc, #1008]
 *   @0x1a50e0 ldr r3, [pc, #0x408]
 *   @0x1a50e4 vldr s22, [pc, #1004]
 *   @0x1a50e8 add r6, r1, r2
 *   @0x1a50ec vldr s25, [pc, #1000]
 *   @0x1a50f0 lsl r1, r2, #2
 *   @0x1a50f4 mov r2, #0
 *   @0x1a50f8 str r1, [sp, #0x2c]
 *   @0x1a50fc lsl r7, r6, #2
 *   @0x1a5100 str r2, [sp, #0x30]
 *   @0x1a5104 vldr s24, [pc, #980]
 *   @0x1a5108 ldr r9, [r11, r3]
 *   @0x1a510c vldr s18, [pc, #976]
 *   @0x1a5110 vldr s21, [pc, #976]
 *   @0x1a5114 b 0x1a51bc <_Z13DrawParticlesP15RParticleSystemiii+0x128>
 *   @0x1a5118 cmp r1, #0
 *   @0x1a511c bne 0x1a55e8 <_Z13DrawParticlesP15RParticleSystemiii+0x554>
 *   @0x1a5120 cmp r8, #0
 *   @0x1a5124 beq 0x1a52fc <_Z13DrawParticlesP15RParticleSystemiii+0x268>
 *   @0x1a5128 vldr s14, [r4, #20]
 *   @0x1a512c vadd.f32 s14, s20, s14
 *   @0x1a5130 ldr r2, [r4, #0x4]
 *   @0x1a5134 vldr s15, [r4, #16]
 *   @0x1a5138 ldr r3, [r9, #0x4]
 *   @0x1a513c mov r1, #1107296256
 *   @0x1a5140 ldr r0, [r8, #0x4]
 *   @0x1a5144 ldr r3, [r3, r2, lsl #2]
 *   @0x1a5148 mov r2, r1
 *   @0x1a514c vstr s14, [sp]
 *   @0x1a5150 vldr s14, [r3, #28]
 *   @0x1a5154 vmul.f32 s14, s16, s14
 *   @0x1a5158 vmul.f32 s17, s17, s21
 *   @0x1a515c vstr s14, [sp, #4]
 *   @0x1a5160 vldr s14, [r3, #32]
 *   @0x1a5164 vmul.f32 s16, s16, s14
 *   @0x1a5168 vstr s17, [sp, #12]
 *   @0x1a516c vadd.f32 s15, s19, s15
 *   @0x1a5170 vstr s16, [sp, #8]
 *   @0x1a5174 ldr r12, [r4, #0x2c]
 *   @0x1a5178 str r12, [sp, #0x10]
 *   @0x1a517c ldr r12, [r4, #0x30]
 *   @0x1a5180 str r12, [sp, #0x14]
 *   @0x1a5184 vmov r3, s15
 *   @0x1a5188 bl 0x174ee0 <_Z15GR_Texture_DrawP12YYTPageEntryfffffffjf>
 *   @0x1a518c ldr r2, [sp, #0x28]
 *   @0x1a5190 cmp r2, r6
 *   @0x1a5194 beq 0x1a5470 <_Z13DrawParticlesP15RParticleSystemiii+0x3dc>
 *   @0x1a5198 ldr r3, [r10, #0x4]
 *   @0x1a519c ldr r1, [sp, #0x24]
 *   @0x1a51a0 ldr r2, [sp, #0x2c]
 *   @0x1a51a4 ldr r4, [r3, r7]
 *   @0x1a51a8 add r6, r6, r1
 *   @0x1a51ac add r7, r7, r2
 *   @0x1a51b0 ldr r3, [r4, #0xc]
 *   @0x1a51b4 cmp r3, #0
 *   @0x1a51b8 ble 0x1a5640 <_Z13DrawParticlesP15RParticleSystemiii+0x5ac>
 *   @0x1a51bc ldr r2, [r4, #0x4]
 *   @0x1a51c0 ldr r3, [r9, #0x4]
 *   @0x1a51c4 ldr r3, [r3, r2, lsl #2]
 *   @0x1a51c8 cmp r3, #0
 *   @0x1a51cc beq 0x1a518c <_Z13DrawParticlesP15RParticleSystemiii+0xf8>
 *   @0x1a51d0 ldr r0, [r3]
 *   @0x1a51d4 bl 0x1eee98 <_Z13Sprite_Existsi>
 *   @0x1a51d8 cmp r0, #0
 *   @0x1a51dc bne 0x1a5484 <_Z13DrawParticlesP15RParticleSystemiii+0x3f0>
 *   @0x1a51e0 ldr r3, [r9, #0x4]
 *   @0x1a51e4 ldr r1, [r4, #0x4]
 *   @0x1a51e8 ldr r5, [r3, r1, lsl #2]
 *   @0x1a51ec ldr r3, [r5, #0x8]
 *   @0x1a51f0 cmp r3, #13
 *   @0x1a51f4 bhi 0x1a5640 <_Z13DrawParticlesP15RParticleSystemiii+0x5ac>
 *   @0x1a51f8 ldr r1, [pc, #0x2f4]
 *   @0x1a51fc ldr r1, [r11, r1]
 *   @0x1a5200 ldr r8, [r1, r3, lsl #2]
 *   @0x1a5204 cmp r8, #0
 *   @0x1a5208 beq 0x1a561c <_Z13DrawParticlesP15RParticleSystemiii+0x588>
 *   @0x1a520c ldr r3, [r4, #0x8]
 *   @0x1a5210 mov r2, r0
 *   @0x1a5214 mov r12, r0
 *   @0x1a5218 ldr r1, [r4, #0x3c]
 *   @0x1a521c vmov.f32 s14, #2.000000e+00
 *   @0x1a5220 vldr s13, [r5, #112]
 *   @0x1a5224 vldr s16, [r4, #52]
 *   @0x1a5228 add r3, r3, r1, lsl #1
 *   @0x1a522c asr r0, r3, #31
 *   @0x1a5230 lsr r0, r0, #28
 *   @0x1a5234 add lr, r3, r0
 *   @0x1a5238 rsb r3, r1, r3
 *   @0x1a523c and lr, lr, #15
 *   @0x1a5240 ldr r1, [sp, #0x30]
 *   @0x1a5244 rsb lr, r0, lr
 *   @0x1a5248 vmov.f32 s12, #1.000000e+00
 *   @0x1a524c ldrb r0, [r5, #0x74]
 *   @0x1a5250 vmov s15, lr
 *   @0x1a5254 vcvt.f32.s32 s15, s15, #2
 *   @0x1a5258 vcmpe.f32 s15, s14
 *   @0x1a525c vmrs APSR_nzcv, fpscr
 *   @0x1a5260 vmovgt.f32 s14, #4.000000e+00
 *   @0x1a5264 vsubgt.f32 s15, s14, s15
 *   @0x1a5268 cmp r0, #0
 *   @0x1a526c asr r0, r3, #31
 *   @0x1a5270 vldr s14, [r4, #40]
 *   @0x1a5274 lsr r0, r0, #28
 *   @0x1a5278 add r3, r3, r0
 *   @0x1a527c and r3, r3, #15
 *   @0x1a5280 rsb r3, r0, r3
 *   @0x1a5284 vmov.f32 s11, #2.000000e+00
 *   @0x1a5288 vsub.f32 s12, s15, s12
 *   @0x1a528c vldrne s15, [r4, #36]
 *   @0x1a5290 vaddne.f32 s14, s14, s15
 *   @0x1a5294 vmov s15, r3
 *   @0x1a5298 ldrb r3, [r5, #0xa0]
 *   @0x1a529c vcvt.f32.s32 s15, s15, #2
 *   @0x1a52a0 vcmpe.f32 s15, s11
 *   @0x1a52a4 vmov.f32 s17, s14
 *   @0x1a52a8 vmrs APSR_nzcv, fpscr
 *   @0x1a52ac vmovgt.f32 s14, #4.000000e+00
 *   @0x1a52b0 vmla.f32 s17, s12, s13
 *   @0x1a52b4 vsubgt.f32 s15, s14, s15
 *   @0x1a52b8 cmp r3, #0
 *   @0x1a52bc vldr s14, [r5, #24]
 *   @0x1a52c0 vmov.f32 s13, #1.000000e+00
 *   @0x1a52c4 vsub.f32 s15, s15, s13
 *   @0x1a52c8 vmla.f32 s16, s15, s14
 *   @0x1a52cc beq 0x1a5118 <_Z13DrawParticlesP15RParticleSystemiii+0x84>
 *   @0x1a52d0 cmp r1, #0
 *   @0x1a52d4 bne 0x1a5120 <_Z13DrawParticlesP15RParticleSystemiii+0x8c>
 *   @0x1a52d8 mov r0, #1
 *   @0x1a52dc str r2, [sp, #0x1c]
 *   @0x1a52e0 str r12, [sp, #0x18]
 *   @0x1a52e4 str r0, [sp, #0x30]
 *   @0x1a52e8 bl 0x168360 <_Z16GR_D3D_Set_Blendi>
 *   @0x1a52ec cmp r8, #0
 *   @0x1a52f0 ldr r2, [sp, #0x1c]
 *   @0x1a52f4 ldr r12, [sp, #0x18]
 *   @0x1a52f8 bne 0x1a5128 <_Z13DrawParticlesP15RParticleSystemiii+0x94>
 *   @0x1a52fc cmp r2, #0
 *   @0x1a5300 beq 0x1a564c <_Z13DrawParticlesP15RParticleSystemiii+0x5b8>
 *   @0x1a5304 mov r1, r2
 *   @0x1a5308 mov r3, #6
 *   @0x1a530c mov r2, #24
 *   @0x1a5310 mov r0, #4
 *   @0x1a5314 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x1a5318 ldr r2, [r4, #0x4]
 *   @0x1a531c ldr r3, [r9, #0x4]
 *   @0x1a5320 vldr s31, [r4, #16]
 *   @0x1a5324 vldr s30, [r4, #20]
 *   @0x1a5328 vadd.f32 s31, s19, s31
 *   @0x1a532c ldr r3, [r3, r2, lsl #2]
 *   @0x1a5330 vldr s14, [r3, #32]
 *   @0x1a5334 vldr s15, [r3, #28]
 *   @0x1a5338 vmul.f32 s15, s16, s15
 *   @0x1a533c vmul.f32 s16, s16, s14
 *   @0x1a5340 mov r5, r0
 *   @0x1a5344 vnmul.f32 s27, s15, s23
 *   @0x1a5348 vnmul.f32 s26, s16, s23
 *   @0x1a534c vadd.f32 s30, s20, s30
 *   @0x1a5350 vabs.f32 s14, s17
 *   @0x1a5354 vmov.f32 s29, s27
 *   @0x1a5358 vcmpe.f32 s14, s25
 *   @0x1a535c vmov.f32 s28, s26
 *   @0x1a5360 vmrs APSR_nzcv, fpscr
 *   @0x1a5364 vmla.f32 s29, s15, s22
 *   @0x1a5368 vmla.f32 s28, s16, s22
 *   @0x1a536c vcvt.s32.f32 s31, s31
 *   @0x1a5370 vcvt.s32.f32 s30, s30
 *   @0x1a5374 bpl 0x1a5548 <_Z13DrawParticlesP15RParticleSystemiii+0x4b4>
 *   @0x1a5378 vcvt.f32.s32 s31, s31
 *   @0x1a537c vcvt.f32.s32 s30, s30
 *   @0x1a5380 vadd.f32 s27, s31, s27
 *   @0x1a5384 vadd.f32 s29, s29, s31
 *   @0x1a5388 vstr s27, [r0, #120]
 *   @0x1a538c vstr s27, [r0, #96]
 *   @0x1a5390 vstr s27, [r0]
 *   @0x1a5394 vadd.f32 s26, s30, s26
 *   @0x1a5398 vstr s29, [r0, #72]
 *   @0x1a539c vstr s29, [r0, #48]
 *   @0x1a53a0 vstr s29, [r0, #24]
 *   @0x1a53a4 vadd.f32 s28, s28, s30
 *   @0x1a53a8 vstr s26, [r0, #124]
 *   @0x1a53ac vstr s26, [r0, #28]
 *   @0x1a53b0 vstr s26, [r0, #4]
 *   @0x1a53b4 vstr s28, [r0, #100]
 *   @0x1a53b8 vstr s28, [r0, #52]
 *   @0x1a53bc vstr s28, [r0, #76]
 *   @0x1a53c0 vldr s15, [r4, #48]
 *   @0x1a53c4 vmul.f32 s15, s15, s24
 *   @0x1a53c8 ldr r3, [pc, #0x128]
 *   @0x1a53cc ldr r1, [r4, #0x2c]
 *   @0x1a53d0 ldr r3, [r11, r3]
 *   @0x1a53d4 ldr r2, [r3]
 *   @0x1a53d8 str r2, [r5, #0x80]
 *   @0x1a53dc str r2, [r5, #0x68]
 *   @0x1a53e0 vcvt.s32.f32 s15, s15
 *   @0x1a53e4 str r2, [r5, #0x50]
 *   @0x1a53e8 str r2, [r5, #0x38]
 *   @0x1a53ec str r2, [r5, #0x20]
 *   @0x1a53f0 str r2, [r5, #0x8]
 *   @0x1a53f4 vmov r3, s15
 *   @0x1a53f8 cmp r3, #255
 *   @0x1a53fc movgt r3, #-16777216
 *   @0x1a5400 bgt 0x1a5410 <_Z13DrawParticlesP15RParticleSystemiii+0x37c>
 *   @0x1a5404 cmp r3, #0
 *   @0x1a5408 lslge r3, r3, #24
 *   @0x1a540c movlt r3, #0
 *   @0x1a5410 mov r2, #1065353216
 *   @0x1a5414 str r2, [r5, #0x74]
 *   @0x1a5418 str r2, [r5, #0x5c]
 *   @0x1a541c bic r1, r1, #-16777216
 *   @0x1a5420 str r2, [r5, #0x58]
 *   @0x1a5424 orr r3, r3, r1
 *   @0x1a5428 str r2, [r5, #0x44]
 *   @0x1a542c vstr s18, [r5, #140]
 *   @0x1a5430 str r2, [r5, #0x40]
 *   @0x1a5434 vstr s18, [r5, #136]
 *   @0x1a5438 str r2, [r5, #0x28]
 *   @0x1a543c vstr s18, [r5, #112]
 *   @0x1a5440 ldr r2, [sp, #0x28]
 *   @0x1a5444 vstr s18, [r5, #44]
 *   @0x1a5448 str r3, [r5, #0x84]
 *   @0x1a544c vstr s18, [r5, #20]
 *   @0x1a5450 cmp r2, r6
 *   @0x1a5454 str r3, [r5, #0x6c]
 *   @0x1a5458 str r3, [r5, #0x54]
 *   @0x1a545c vstr s18, [r5, #16]
 *   @0x1a5460 str r3, [r5, #0x3c]
 *   @0x1a5464 str r3, [r5, #0x24]
 *   @0x1a5468 str r3, [r5, #0xc]
 *   @0x1a546c bne 0x1a5198 <_Z13DrawParticlesP15RParticleSystemiii+0x104>
 *   @0x1a5470 mov r0, #0
 *   @0x1a5474 add sp, sp, #60
 *   @0x1a5478 vpop {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x1a547c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1a5480 b 0x168360 <_Z16GR_D3D_Set_Blendi>
 *   @0x1a5484 ldr r2, [r4, #0x4]
 *   @0x1a5488 ldr r3, [r9, #0x4]
 *   @0x1a548c ldr r3, [r3, r2, lsl #2]
 *   @0x1a5490 ldr r0, [r3]
 *   @0x1a5494 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x1a5498 mov r12, r0
 *   @0x1a549c ldr r0, [r12, #0x18]
 *   @0x1a54a0 cmp r0, #0
 *   @0x1a54a4 ble 0x1a5640 <_Z13DrawParticlesP15RParticleSystemiii+0x5ac>
 *   @0x1a54a8 ldr r2, [r4, #0x4]
 *   @0x1a54ac ldr r3, [r9, #0x4]
 *   @0x1a54b0 ldr r5, [r3, r2, lsl #2]
 *   @0x1a54b4 ldrb r8, [r5, #0x4]
 *   @0x1a54b8 cmp r8, #0
 *   @0x1a54bc bne 0x1a5500 <_Z13DrawParticlesP15RParticleSystemiii+0x46c>
 *   @0x1a54c0 ldr r3, [r4, #0x38]
 *   @0x1a54c4 mov r2, r8
 *   @0x1a54c8 str r3, [sp, #0x34]
 *   @0x1a54cc ldr r3, [r4, #0x8]
 *   @0x1a54d0 b 0x1a5218 <_Z13DrawParticlesP15RParticleSystemiii+0x184>
 *   @0x1a54d4 andmi r0, r0, #0
 *   @0x1a54d8 addmi r0, r0, #0
 *   @0x1a54dc ldmlo r1, {r0, r1, r2, r4, r8, r9, r10, r12, sp, pc} ^
 *   @0x1a54e0 cmnmi pc, #0
 *   @0x1a54e4 andeq r0, r0, r0
 *   @0x1a54e8 vstmialo lr, {s30, s31}
 *   @0x1a54ec mlaeq r4, r8, r11, r12
 *   @0x1a54f0 .word 0xffffeb5c
 *   @0x1a54f4 .word 0xffffeb6c
 *   @0x1a54f8 .word 0xffffbcd0
 *   @0x1a54fc .word 0xffffeb70
 *   @0x1a5500 ldrb r8, [r5, #0x5]
 *   @0x1a5504 ldr r3, [r4, #0x8]
 *   @0x1a5508 cmp r8, #0
 *   @0x1a550c beq 0x1a5608 <_Z13DrawParticlesP15RParticleSystemiii+0x574>
 *   @0x1a5510 ldr r1, [r4, #0xc]
 *   @0x1a5514 mov r8, #0
 *   @0x1a5518 mul r0, r3, r0
 *   @0x1a551c str r3, [sp, #0x20]
 *   @0x1a5520 str r12, [sp, #0x18]
 *   @0x1a5524 str r8, [sp, #0x1c]
 *   @0x1a5528 bl 0x318d10 <__divsi3>
 *   @0x1a552c ldr r1, [r4, #0x38]
 *   @0x1a5530 ldr r2, [sp, #0x1c]
 *   @0x1a5534 ldr r3, [sp, #0x20]
 *   @0x1a5538 ldr r12, [sp, #0x18]
 *   @0x1a553c add r1, r0, r1
 *   @0x1a5540 str r1, [sp, #0x34]
 *   @0x1a5544 b 0x1a5218 <_Z13DrawParticlesP15RParticleSystemiii+0x184>
 *   @0x1a5548 vmul.f32 s17, s17, s21
 *   @0x1a554c vmov r0, s17
 *   @0x1a5550 bl 0xb6580 <sinf@plt>
 *   @0x1a5554 vcvt.f32.s32 s31, s31
 *   @0x1a5558 vcvt.f32.s32 s30, s30
 *   @0x1a555c vmov s16, r0
 *   @0x1a5560 vmov r0, s17
 *   @0x1a5564 bl 0xb658c <cosf@plt>
 *   @0x1a5568 vmov.f32 s13, s31
 *   @0x1a556c vmov.f32 s14, s30
 *   @0x1a5570 vmls.f32 s30, s29, s16
 *   @0x1a5574 vmls.f32 s14, s27, s16
 *   @0x1a5578 vmov s15, r0
 *   @0x1a557c vmla.f32 s13, s27, s15
 *   @0x1a5580 vmla.f32 s31, s29, s15
 *   @0x1a5584 vmul.f32 s11, s26, s16
 *   @0x1a5588 vmul.f32 s26, s26, s15
 *   @0x1a558c vmul.f32 s16, s28, s16
 *   @0x1a5590 vmul.f32 s15, s28, s15
 *   @0x1a5594 vadd.f32 s12, s13, s11
 *   @0x1a5598 vadd.f32 s11, s31, s11
 *   @0x1a559c vstr s12, [r5, #120]
 *   @0x1a55a0 vstr s12, [r5]
 *   @0x1a55a4 vadd.f32 s31, s16, s31
 *   @0x1a55a8 vstr s11, [r5, #24]
 *   @0x1a55ac vadd.f32 s16, s16, s13
 *   @0x1a55b0 vstr s31, [r5, #72]
 *   @0x1a55b4 vstr s31, [r5, #48]
 *   @0x1a55b8 vadd.f32 s13, s14, s26
 *   @0x1a55bc vstr s16, [r5, #96]
 *   @0x1a55c0 vadd.f32 s26, s30, s26
 *   @0x1a55c4 vstr s13, [r5, #4]
 *   @0x1a55c8 vstr s13, [r5, #124]
 *   @0x1a55cc vadd.f32 s30, s15, s30
 *   @0x1a55d0 vstr s26, [r5, #28]
 *   @0x1a55d4 vadd.f32 s15, s15, s14
 *   @0x1a55d8 vstr s30, [r5, #76]
 *   @0x1a55dc vstr s30, [r5, #52]
 *   @0x1a55e0 vstr s15, [r5, #100]
 *   @0x1a55e4 b 0x1a53c0 <_Z13DrawParticlesP15RParticleSystemiii+0x32c>
 *   @0x1a55e8 mov r0, r3
 *   @0x1a55ec str r2, [sp, #0x1c]
 *   @0x1a55f0 str r12, [sp, #0x18]
 *   @0x1a55f4 str r3, [sp, #0x30]
 *   @0x1a55f8 bl 0x168360 <_Z16GR_D3D_Set_Blendi>
 *   @0x1a55fc ldr r12, [sp, #0x18]
 *   @0x1a5600 ldr r2, [sp, #0x1c]
 *   @0x1a5604 b 0x1a5120 <_Z13DrawParticlesP15RParticleSystemiii+0x8c>
 *   @0x1a5608 ldr r1, [r4, #0x38]
 *   @0x1a560c mov r2, r8
 *   @0x1a5610 add r1, r3, r1
 *   @0x1a5614 str r1, [sp, #0x34]
 *   @0x1a5618 b 0x1a5218 <_Z13DrawParticlesP15RParticleSystemiii+0x184>
 *   @0x1a561c ldr r2, [pc, #-0x128]
 *   @0x1a5620 ldr r2, [r11, r2]
 *   @0x1a5624 ldr r2, [r2, r3, lsl #2]
 *   @0x1a5628 cmp r2, #0
 *   @0x1a562c moveq r12, r2
 *   @0x1a5630 beq 0x1a549c <_Z13DrawParticlesP15RParticleSystemiii+0x408>
 *   @0x1a5634 ldr r3, [r4, #0x8]
 *   @0x1a5638 mov r12, r8
 *   @0x1a563c b 0x1a5218 <_Z13DrawParticlesP15RParticleSystemiii+0x184>
 *   @0x1a5640 add sp, sp, #60
 *   @0x1a5644 vpop {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x1a5648 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1a564c vldr s14, [r4, #16]
 *   @0x1a5650 vadd.f32 s14, s19, s14
 *   @0x1a5654 ldr r1, [r4, #0x4]
 *   @0x1a5658 vldr s15, [r4, #20]
 *   @0x1a565c ldr r3, [r9, #0x4]
 *   @0x1a5660 mov r0, r12
 *   @0x1a5664 ldr r3, [r3, r1, lsl #2]
 *   @0x1a5668 ldr r1, [sp, #0x34]
 *   @0x1a566c vmov r2, s14
 *   @0x1a5670 vldr s14, [r3, #28]
 *   @0x1a5674 vmul.f32 s14, s16, s14
 *   @0x1a5678 vstr s14, [sp]
 *   @0x1a567c vldr s14, [r3, #32]
 *   @0x1a5680 vmul.f32 s16, s16, s14
 *   @0x1a5684 vstr s17, [sp, #8]
 *   @0x1a5688 vadd.f32 s15, s20, s15
 *   @0x1a568c vstr s16, [sp, #4]
 *   @0x1a5690 ldr r12, [r4, #0x2c]
 *   @0x1a5694 str r12, [sp, #0xc]
 *   @0x1a5698 ldr r12, [r4, #0x30]
 *   @0x1a569c str r12, [sp, #0x10]
 *   @0x1a56a0 vmov r3, s15
 *   @0x1a56a4 bl 0x1ec720 <_ZN7CSprite4DrawEifffffjf>
 *   @0x1a56a8 b 0x1a518c <_Z13DrawParticlesP15RParticleSystemiii+0xf8>
 *
 * ══ §4/21 anon_2bf200  0x2bf200  size 1552  388 条（0x2bf200..0x2bf810）
 * @func 0x2bf200 0x2bf810  size 1552  388 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __divsi3×4 / anon_2bf200+0xd8×2 / anon_2bf200+0x214 / anon_2bf200+0x31c / anon_2bf200+0x1c0 / __aeabi_uidivmod / anon_2bf200+0x404 / anon_2bf200+0x5f4
 * 字段偏移 top8: 0x4×16 / 0x24×10 / 0x14×8 / 0x48×8 / 0xc×7 / 0x40×7 / 0x2×7 / 0x8×7
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2bf200 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x2bf204 mov r5, r0
 *   @0x2bf208 ldr r4, [r0, #0x184]
 *   @0x2bf20c sub sp, sp, #20
 *   @0x2bf210 mov r8, r1
 *   @0x2bf214 mov r7, r2
 *   @0x2bf218 mov r9, r3
 *   @0x2bf21c ldrb r12, [r4, #0x30]
 *   @0x2bf220 cmp r12, #0
 *   @0x2bf224 addne r6, r4, #8
 *   @0x2bf228 bne 0x2bf250 <jinit_huff_decoder+0xb4>
 *   @0x2bf22c ldr r3, [r0, #0x188]
 *   @0x2bf230 add r6, r4, #8
 *   @0x2bf234 mov r1, r6
 *   @0x2bf238 ldr r3, [r3, #0xc]
 *   @0x2bf23c blx r3
 *   @0x2bf240 cmp r0, #0
 *   @0x2bf244 beq 0x2bf28c <jinit_huff_decoder+0xf0>
 *   @0x2bf248 mov r3, #1
 *   @0x2bf24c strb r3, [r4, #0x30]
 *   @0x2bf250 ldr r12, [r5, #0x18c]
 *   @0x2bf254 mov r1, r6
 *   @0x2bf258 ldr r6, [r5, #0x118]
 *   @0x2bf25c mov r0, r5
 *   @0x2bf260 str r8, [sp]
 *   @0x2bf264 add r2, r4, #52
 *   @0x2bf268 stmib sp, {r7, r9}
 *   @0x2bf26c mov r3, r6
 *   @0x2bf270 ldr r12, [r12, #0x4]
 *   @0x2bf274 blx r12
 *   @0x2bf278 ldr r3, [r4, #0x34]
 *   @0x2bf27c cmp r6, r3
 *   @0x2bf280 movls r3, #0
 *   @0x2bf284 strbls r3, [r4, #0x30]
 *   @0x2bf288 strls r3, [r4, #0x34]
 *   @0x2bf28c add sp, sp, #20
 *   @0x2bf290 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x2bf294 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2bf298 mov r6, r3
 *   @0x2bf29c ldr r4, [r0, #0x184]
 *   @0x2bf2a0 sub sp, sp, #44
 *   @0x2bf2a4 mov r5, r0
 *   @0x2bf2a8 mov r7, r2
 *   @0x2bf2ac str r1, [sp, #0x10]
 *   @0x2bf2b0 ldrb r3, [r4, #0x30]
 *   @0x2bf2b4 cmp r3, #0
 *   @0x2bf2b8 beq 0x2bf344 <jinit_huff_decoder+0x1a8>
 *   @0x2bf2bc ldr r3, [r4, #0x44]
 *   @0x2bf2c0 cmp r3, #1
 *   @0x2bf2c4 beq 0x2bf384 <jinit_huff_decoder+0x1e8>
 *   @0x2bf2c8 cmp r3, #2
 *   @0x2bf2cc beq 0x2bf2e0 <jinit_huff_decoder+0x144>
 *   @0x2bf2d0 cmp r3, #0
 *   @0x2bf2d4 beq 0x2bf394 <jinit_huff_decoder+0x1f8>
 *   @0x2bf2d8 add sp, sp, #44
 *   @0x2bf2dc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2bf2e0 ldr r1, [r4, #0x40]
 *   @0x2bf2e4 add r3, r4, #52
 *   @0x2bf2e8 ldr r12, [r5, #0x18c]
 *   @0x2bf2ec mov r0, r5
 *   @0x2bf2f0 ldr lr, [sp, #0x10]
 *   @0x2bf2f4 add r1, r1, #14
 *   @0x2bf2f8 str r3, [sp, #0x14]
 *   @0x2bf2fc ldr r1, [r4, r1, lsl #2]
 *   @0x2bf300 ldr r3, [r4, #0x48]
 *   @0x2bf304 ldr r2, [sp, #0x14]
 *   @0x2bf308 str lr, [sp]
 *   @0x2bf30c str r7, [sp, #0x4]
 *   @0x2bf310 str r6, [sp, #0x8]
 *   @0x2bf314 ldr r12, [r12, #0x4]
 *   @0x2bf318 blx r12
 *   @0x2bf31c ldr r2, [r4, #0x34]
 *   @0x2bf320 ldr r3, [r4, #0x48]
 *   @0x2bf324 cmp r2, r3
 *   @0x2bf328 blo 0x2bf2d8 <jinit_huff_decoder+0x13c>
 *   @0x2bf32c mov r3, #0
 *   @0x2bf330 str r3, [r4, #0x44]
 *   @0x2bf334 ldr r3, [r7]
 *   @0x2bf338 cmp r6, r3
 *   @0x2bf33c bhi 0x2bf39c <jinit_huff_decoder+0x200>
 *   @0x2bf340 b 0x2bf2d8 <jinit_huff_decoder+0x13c>
 *   @0x2bf344 ldr r2, [r4, #0x40]
 *   @0x2bf348 ldr r3, [r0, #0x188]
 *   @0x2bf34c add r2, r2, #14
 *   @0x2bf350 ldr r3, [r3, #0xc]
 *   @0x2bf354 ldr r1, [r4, r2, lsl #2]
 *   @0x2bf358 blx r3
 *   @0x2bf35c cmp r0, #0
 *   @0x2bf360 beq 0x2bf2d8 <jinit_huff_decoder+0x13c>
 *   @0x2bf364 ldr r3, [r4, #0x4c]
 *   @0x2bf368 mov r2, #1
 *   @0x2bf36c strb r2, [r4, #0x30]
 *   @0x2bf370 add r3, r3, r2
 *   @0x2bf374 str r3, [r4, #0x4c]
 *   @0x2bf378 ldr r3, [r4, #0x44]
 *   @0x2bf37c cmp r3, #1
 *   @0x2bf380 bne 0x2bf2c8 <jinit_huff_decoder+0x12c>
 *   @0x2bf384 add r3, r4, #52
 *   @0x2bf388 str r3, [sp, #0x14]
 *   @0x2bf38c ldr r3, [r4, #0x48]
 *   @0x2bf390 b 0x2bf3c8 <jinit_huff_decoder+0x22c>
 *   @0x2bf394 add lr, r4, #52
 *   @0x2bf398 str lr, [sp, #0x14]
 *   @0x2bf39c ldr r3, [r5, #0x11c]
 *   @0x2bf3a0 mov r12, #0
 *   @0x2bf3a4 ldr r2, [r4, #0x4c]
 *   @0x2bf3a8 ldr r10, [r5, #0x118]
 *   @0x2bf3ac cmp r2, r3
 *   @0x2bf3b0 str r12, [r4, #0x34]
 *   @0x2bf3b4 sub r3, r10, #1
 *   @0x2bf3b8 str r3, [r4, #0x48]
 *   @0x2bf3bc beq 0x2bf53c <jinit_huff_decoder+0x3a0>
 *   @0x2bf3c0 mov r2, #1
 *   @0x2bf3c4 str r2, [r4, #0x44]
 *   @0x2bf3c8 ldr r1, [r4, #0x40]
 *   @0x2bf3cc mov r0, r5
 *   @0x2bf3d0 ldr r12, [r5, #0x18c]
 *   @0x2bf3d4 ldr lr, [sp, #0x10]
 *   @0x2bf3d8 add r1, r1, #14
 *   @0x2bf3dc ldr r2, [sp, #0x14]
 *   @0x2bf3e0 ldr r1, [r4, r1, lsl #2]
 *   @0x2bf3e4 str lr, [sp]
 *   @0x2bf3e8 str r7, [sp, #0x4]
 *   @0x2bf3ec str r6, [sp, #0x8]
 *   @0x2bf3f0 ldr r12, [r12, #0x4]
 *   @0x2bf3f4 blx r12
 *   @0x2bf3f8 ldr r2, [r4, #0x34]
 *   @0x2bf3fc ldr r3, [r4, #0x48]
 *   @0x2bf400 cmp r2, r3
 *   @0x2bf404 blo 0x2bf2d8 <jinit_huff_decoder+0x13c>
 *   @0x2bf408 ldr r3, [r4, #0x4c]
 *   @0x2bf40c cmp r3, #1
 *   @0x2bf410 beq 0x2bf44c <jinit_huff_decoder+0x2b0>
 *   @0x2bf414 ldr r2, [r4, #0x40]
 *   @0x2bf418 mov r3, #0
 *   @0x2bf41c strb r3, [r4, #0x30]
 *   @0x2bf420 mov r1, #2
 *   @0x2bf424 ldr r3, [r5, #0x118]
 *   @0x2bf428 eor r2, r2, #1
 *   @0x2bf42c str r1, [r4, #0x44]
 *   @0x2bf430 str r2, [r4, #0x40]
 *   @0x2bf434 add r1, r3, #1
 *   @0x2bf438 add r3, r3, #2
 *   @0x2bf43c str r1, [r4, #0x34]
 *   @0x2bf440 str r3, [r4, #0x48]
 *   @0x2bf444 add sp, sp, #44
 *   @0x2bf448 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2bf44c ldr r3, [r5, #0x24]
 *   @0x2bf450 ldr r7, [r5, #0x118]
 *   @0x2bf454 cmp r3, #0
 *   @0x2bf458 ldr r8, [r5, #0x184]
 *   @0x2bf45c str r3, [sp, #0x18]
 *   @0x2bf460 str r7, [sp, #0x14]
 *   @0x2bf464 ldr r9, [r5, #0xc4]
 *   @0x2bf468 ble 0x2bf414 <jinit_huff_decoder+0x278>
 *   @0x2bf46c add r3, r7, #1
 *   @0x2bf470 mov r7, #0
 *   @0x2bf474 str r3, [sp, #0x1c]
 *   @0x2bf478 str r4, [sp, #0x20]
 *   @0x2bf47c str r5, [sp, #0x24]
 *   @0x2bf480 ldr r3, [r9, #0xc]
 *   @0x2bf484 ldr r0, [r9, #0x24]
 *   @0x2bf488 ldr r1, [sp, #0x14]
 *   @0x2bf48c mul r0, r0, r3
 *   @0x2bf490 bl 0x318d10 <__divsi3>
 *   @0x2bf494 ldr r2, [r8, #0x38]
 *   @0x2bf498 ldr r3, [r8, #0x3c]
 *   @0x2bf49c ldr r1, [r2, r7, lsl #2]
 *   @0x2bf4a0 ldr r2, [r3, r7, lsl #2]
 *   @0x2bf4a4 subs r4, r0, #0
 *   @0x2bf4a8 ble 0x2bf51c <jinit_huff_decoder+0x380>
 *   @0x2bf4ac ldr r3, [sp, #0x1c]
 *   @0x2bf4b0 rsb r6, r4, r4, lsl #30
 *   @0x2bf4b4 lsl r11, r4, #2
 *   @0x2bf4b8 str r7, [sp, #0x10]
 *   @0x2bf4bc lsl r6, r6, #2
 *   @0x2bf4c0 mul r0, r3, r4
 *   @0x2bf4c4 add r10, r1, r6
 *   @0x2bf4c8 add r6, r2, r6
 *   @0x2bf4cc mov r3, #0
 *   @0x2bf4d0 add r4, r0, r4
 *   @0x2bf4d4 lsl r0, r0, #2
 *   @0x2bf4d8 lsl r4, r4, #2
 *   @0x2bf4dc add r5, r1, r4
 *   @0x2bf4e0 add r12, r1, r0
 *   @0x2bf4e4 add r4, r2, r4
 *   @0x2bf4e8 add r0, r2, r0
 *   @0x2bf4ec ldr r7, [r12, r3]
 *   @0x2bf4f0 str r7, [r10, r3]
 *   @0x2bf4f4 ldr r7, [r0, r3]
 *   @0x2bf4f8 str r7, [r6, r3]
 *   @0x2bf4fc ldr r7, [r1, r3]
 *   @0x2bf500 str r7, [r5, r3]
 *   @0x2bf504 ldr r7, [r2, r3]
 *   @0x2bf508 str r7, [r4, r3]
 *   @0x2bf50c add r3, r3, #4
 *   @0x2bf510 cmp r3, r11
 *   @0x2bf514 bne 0x2bf4ec <jinit_huff_decoder+0x350>
 *   @0x2bf518 ldr r7, [sp, #0x10]
 *   @0x2bf51c ldr r3, [sp, #0x18]
 *   @0x2bf520 add r7, r7, #1
 *   @0x2bf524 add r9, r9, #84
 *   @0x2bf528 cmp r7, r3
 *   @0x2bf52c bne 0x2bf480 <jinit_huff_decoder+0x2e4>
 *   @0x2bf530 ldr r4, [sp, #0x20]
 *   @0x2bf534 ldr r5, [sp, #0x24]
 *   @0x2bf538 b 0x2bf414 <jinit_huff_decoder+0x278>
 *   @0x2bf53c ldr r2, [r5, #0x24]
 *   @0x2bf540 ldr r8, [r5, #0x184]
 *   @0x2bf544 cmp r2, r12
 *   @0x2bf548 ldr r9, [r5, #0xc4]
 *   @0x2bf54c ble 0x2bf3c0 <jinit_huff_decoder+0x224>
 *   @0x2bf550 ldr r3, [r8, #0x40]
 *   @0x2bf554 str r5, [sp, #0x1c]
 *   @0x2bf558 mov r5, r12
 *   @0x2bf55c add r3, r3, #14
 *   @0x2bf560 str r6, [sp, #0x24]
 *   @0x2bf564 mov r6, r9
 *   @0x2bf568 mov r9, r2
 *   @0x2bf56c mov r11, r3
 *   @0x2bf570 str r4, [sp, #0x18]
 *   @0x2bf574 str r7, [sp, #0x20]
 *   @0x2bf578 ldr r3, [r6, #0xc]
 *   @0x2bf57c mov r1, r10
 *   @0x2bf580 ldr r4, [r6, #0x24]
 *   @0x2bf584 mul r7, r4, r3
 *   @0x2bf588 mov r0, r7
 *   @0x2bf58c bl 0x318d10 <__divsi3>
 *   @0x2bf590 mov r1, r7
 *   @0x2bf594 mov r4, r0
 *   @0x2bf598 ldr r0, [r6, #0x2c]
 *   @0x2bf59c bl 0x318cf0 <__aeabi_uidivmod>
 *   @0x2bf5a0 cmp r1, #0
 *   @0x2bf5a4 movne r7, r1
 *   @0x2bf5a8 cmp r5, #0
 *   @0x2bf5ac bne 0x2bf5c4 <jinit_huff_decoder+0x428>
 *   @0x2bf5b0 sub r0, r7, #1
 *   @0x2bf5b4 mov r1, r4
 *   @0x2bf5b8 bl 0x318d10 <__divsi3>
 *   @0x2bf5bc add r0, r0, #1
 *   @0x2bf5c0 str r0, [r8, #0x48]
 *   @0x2bf5c4 lsl r4, r4, #1
 *   @0x2bf5c8 ldr r1, [r8, r11, lsl #2]
 *   @0x2bf5cc cmp r4, #0
 *   @0x2bf5d0 ldr r1, [r1, r5, lsl #2]
 *   @0x2bf5d4 ble 0x2bf604 <jinit_huff_decoder+0x468>
 *   @0x2bf5d8 sub r0, r7, #-1073741823
 *   @0x2bf5dc add r4, r4, r7
 *   @0x2bf5e0 lsl r0, r0, #2
 *   @0x2bf5e4 add r4, r1, r4, lsl #2
 *   @0x2bf5e8 add r3, r0, #4
 *   @0x2bf5ec add r0, r1, r0
 *   @0x2bf5f0 add r3, r1, r3
 *   @0x2bf5f4 ldr r2, [r0]
 *   @0x2bf5f8 str r2, [r3], #4
 *   @0x2bf5fc cmp r3, r4
 *   @0x2bf600 bne 0x2bf5f4 <jinit_huff_decoder+0x458>
 *   @0x2bf604 add r5, r5, #1
 *   @0x2bf608 add r6, r6, #84
 *   @0x2bf60c cmp r5, r9
 *   @0x2bf610 bne 0x2bf578 <jinit_huff_decoder+0x3dc>
 *   @0x2bf614 add r4, sp, #24
 *   @0x2bf618 ldr r6, [sp, #0x24]
 *   @0x2bf61c ldm r4, {r4, r5, r7}
 *   @0x2bf620 ldr r3, [r4, #0x48]
 *   @0x2bf624 b 0x2bf3c0 <jinit_huff_decoder+0x224>
 *   @0x2bf628 str lr, [sp, #-0x4]!
 *   @0x2bf62c sub sp, sp, #20
 *   @0x2bf630 ldr r12, [r0, #0x18c]
 *   @0x2bf634 str r1, [sp]
 *   @0x2bf638 mov r1, #0
 *   @0x2bf63c str r2, [sp, #0x4]
 *   @0x2bf640 mov r2, r1
 *   @0x2bf644 str r3, [sp, #0x8]
 *   @0x2bf648 mov r3, r1
 *   @0x2bf64c ldr r12, [r12, #0x4]
 *   @0x2bf650 blx r12
 *   @0x2bf654 add sp, sp, #20
 *   @0x2bf658 ldr pc, [sp], #4
 *   @0x2bf65c cmp r1, #0
 *   @0x2bf660 mov r3, r0
 *   @0x2bf664 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2bf668 sub sp, sp, #20
 *   @0x2bf66c ldr r7, [r0, #0x184]
 *   @0x2bf670 beq 0x2bf6ac <jinit_huff_decoder+0x510>
 *   @0x2bf674 cmp r1, #2
 *   @0x2bf678 beq 0x2bf698 <jinit_huff_decoder+0x4fc>
 *   @0x2bf67c ldr r3, [r0]
 *   @0x2bf680 mov r1, #4
 *   @0x2bf684 ldr r2, [r3]
 *   @0x2bf688 str r1, [r3, #0x14]
 *   @0x2bf68c blx r2
 *   @0x2bf690 add sp, sp, #20
 *   @0x2bf694 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2bf698 ldr r3, [pc, #0x168]
 *   @0x2bf69c add r3, pc, r3
 *   @0x2bf6a0 str r3, [r7, #0x4]
 *   @0x2bf6a4 add sp, sp, #20
 *   @0x2bf6a8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2bf6ac ldr r2, [r0, #0x1a0]
 *   @0x2bf6b0 ldrb r2, [r2, #0x8]
 *   @0x2bf6b4 cmp r2, #0
 *   @0x2bf6b8 bne 0x2bf6dc <jinit_huff_decoder+0x540>
 *   @0x2bf6bc ldr r3, [pc, #0x148]
 *   @0x2bf6c0 add r3, pc, r3
 *   @0x2bf6c4 str r3, [r7, #0x4]
 *   @0x2bf6c8 mov r3, #0
 *   @0x2bf6cc strb r3, [r7, #0x30]
 *   @0x2bf6d0 str r3, [r7, #0x34]
 *   @0x2bf6d4 add sp, sp, #20
 *   @0x2bf6d8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2bf6dc ldr r2, [r0, #0x24]
 *   @0x2bf6e0 ldr r0, [r0, #0x118]
 *   @0x2bf6e4 ldr r1, [pc, #0x124]
 *   @0x2bf6e8 cmp r2, #0
 *   @0x2bf6ec ldr r9, [r3, #0xc4]
 *   @0x2bf6f0 add r1, pc, r1
 *   @0x2bf6f4 str r0, [sp, #0x4]
 *   @0x2bf6f8 str r1, [r7, #0x4]
 *   @0x2bf6fc ble 0x2bf7f4 <jinit_huff_decoder+0x658>
 *   @0x2bf700 ldr r3, [sp, #0x4]
 *   @0x2bf704 mov r8, r7
 *   @0x2bf708 add r2, r7, r2, lsl #2
 *   @0x2bf70c str r2, [sp, #0x8]
 *   @0x2bf710 add r3, r3, #2
 *   @0x2bf714 str r3, [sp, #0xc]
 *   @0x2bf718 ldr r3, [r9, #0xc]
 *   @0x2bf71c ldr r0, [r9, #0x24]
 *   @0x2bf720 ldr r1, [sp, #0x4]
 *   @0x2bf724 mul r0, r0, r3
 *   @0x2bf728 bl 0x318d10 <__divsi3>
 *   @0x2bf72c ldr r3, [sp, #0xc]
 *   @0x2bf730 ldr r2, [r7, #0x38]
 *   @0x2bf734 ldr r12, [r7, #0x3c]
 *   @0x2bf738 ldr r1, [r8, #0x8]
 *   @0x2bf73c mul r10, r3, r0
 *   @0x2bf740 rsb r3, r7, r8
 *   @0x2bf744 ldr r2, [r2, r3]
 *   @0x2bf748 cmp r10, #0
 *   @0x2bf74c ldr r12, [r12, r3]
 *   @0x2bf750 lslgt r5, r10, #2
 *   @0x2bf754 movgt r3, #0
 *   @0x2bf758 ble 0x2bf774 <jinit_huff_decoder+0x5d8>
 *   @0x2bf75c ldr r4, [r1, r3]
 *   @0x2bf760 str r4, [r12, r3]
 *   @0x2bf764 str r4, [r2, r3]
 *   @0x2bf768 add r3, r3, #4
 *   @0x2bf76c cmp r3, r5
 *   @0x2bf770 bne 0x2bf75c <jinit_huff_decoder+0x5c0>
 *   @0x2bf774 lsl r11, r0, #1
 *   @0x2bf778 cmp r11, #0
 *   @0x2bf77c ble 0x2bf7c4 <jinit_huff_decoder+0x628>
 *   @0x2bf780 sub r10, r10, r0, lsl #2
 *   @0x2bf784 lsl r6, r0, #3
 *   @0x2bf788 add r11, r11, r10
 *   @0x2bf78c mov r3, #0
 *   @0x2bf790 lsl r10, r10, #2
 *   @0x2bf794 lsl r11, r11, #2
 *   @0x2bf798 add r5, r12, r10
 *   @0x2bf79c add r4, r1, r11
 *   @0x2bf7a0 add r12, r12, r11
 *   @0x2bf7a4 add r1, r1, r10
 *   @0x2bf7a8 ldr r10, [r4, r3]
 *   @0x2bf7ac str r10, [r5, r3]
 *   @0x2bf7b0 ldr r10, [r1, r3]
 *   @0x2bf7b4 str r10, [r12, r3]
 *   @0x2bf7b8 add r3, r3, #4
 *   @0x2bf7bc cmp r3, r6
 *   @0x2bf7c0 bne 0x2bf7a8 <jinit_huff_decoder+0x60c>
 *   @0x2bf7c4 cmp r0, #0
 *   @0x2bf7c8 subgt r0, r2, r0, lsl #2
 *   @0x2bf7cc ble 0x2bf7e0 <jinit_huff_decoder+0x644>
 *   @0x2bf7d0 ldr r3, [r2]
 *   @0x2bf7d4 str r3, [r0], #4
 *   @0x2bf7d8 cmp r0, r2
 *   @0x2bf7dc bne 0x2bf7d0 <jinit_huff_decoder+0x634>
 *   @0x2bf7e0 ldr r3, [sp, #0x8]
 *   @0x2bf7e4 add r8, r8, #4
 *   @0x2bf7e8 add r9, r9, #84
 *   @0x2bf7ec cmp r8, r3
 *   @0x2bf7f0 bne 0x2bf718 <jinit_huff_decoder+0x57c>
 *   @0x2bf7f4 mov r3, #0
 *   @0x2bf7f8 str r3, [r7, #0x40]
 *   @0x2bf7fc str r3, [r7, #0x44]
 *   @0x2bf800 str r3, [r7, #0x4c]
 *   @0x2bf804 b 0x2bf6c8 <jinit_huff_decoder+0x52c>
 *   @0x2bf808 .word 0xffffff84
 *   @0x2bf80c .word 0xfffffb38
 *
 * ══ §5/21 CGestureDrag::Update(long long)  0x1d6b90  size 1548  387 条（0x1d6b90..0x1d719c）
 * @func 0x1d6b90 0x1d719c  size 1548  387 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1d6d54→0x544a9c, 0x1d6e50→0x544a9c, 0x1d6f94→0x3f5160, 0x1d6fdc→0x544a9c
 * 调用序列: ConvertGestureEventToGMEvent(int, bool)×5 / GetInstanceListWithEventType(int, int, float, float, int**, int*, bool)×5 / operator new(unsigned int)×4 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×4 / AddToDsMap(int, char*, double)×2 / IO_Button_Down(int, int) / __floatdisf / CalcVelocity(float, float, float, float, float, float&, float&)
 * 字段偏移 top8: 0x8×25 / 0x4×17 / 0xc×12 / 0x14×7 / 0x40×5 / 0x44×5 / 0x30×5 / 0x34×5
 * VFP 指令 59 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d6b90 ldr r1, [r0]
 *   @0x1d6b94 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1d6b98 vpush {d8, d9}
 *   @0x1d6b9c mov r4, r0
 *   @0x1d6ba0 sub sp, sp, #36
 *   @0x1d6ba4 ldr r1, [r1, #0x18]
 *   @0x1d6ba8 mov r10, r2
 *   @0x1d6bac mov r11, r3
 *   @0x1d6bb0 blx r1
 *   @0x1d6bb4 ldr r5, [r4, #0x14]
 *   @0x1d6bb8 ldr r6, [pc, #0x5b8]
 *   @0x1d6bbc cmp r5, #0
 *   @0x1d6bc0 add r6, pc, r6
 *   @0x1d6bc4 beq 0x1d6bdc <_ZN12CGestureDrag6UpdateEx+0x4c>
 *   @0x1d6bc8 cmp r5, #1
 *   @0x1d6bcc beq 0x1d6dc4 <_ZN12CGestureDrag6UpdateEx+0x234>
 *   @0x1d6bd0 add sp, sp, #36
 *   @0x1d6bd4 vpop {d8, d9}
 *   @0x1d6bd8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1d6bdc mov r0, #16
 *   @0x1d6be0 mov r9, #2
 *   @0x1d6be4 bl 0x27c524 <_Znwj>
 *   @0x1d6be8 ldr lr, [r4]
 *   @0x1d6bec ldr r1, [r4, #0x40]
 *   @0x1d6bf0 mvn r3, #0
 *   @0x1d6bf4 ldr r12, [r4, #0x44]
 *   @0x1d6bf8 mov r8, #1
 *   @0x1d6bfc mov r2, r12
 *   @0x1d6c00 mov r7, r0
 *   @0x1d6c04 mov r0, r4
 *   @0x1d6c08 str r5, [r7, #0x8]
 *   @0x1d6c0c str r3, [r7, #0x4]
 *   @0x1d6c10 mov r3, r1
 *   @0x1d6c14 str r5, [r7, #0xc]
 *   @0x1d6c18 str r9, [r7]
 *   @0x1d6c1c strd r10, r11, [sp, #8]
 *   @0x1d6c20 add r10, r4, #16
 *   @0x1d6c24 str r12, [sp]
 *   @0x1d6c28 add r11, r4, #12
 *   @0x1d6c2c ldr r12, [lr, #0x1c]
 *   @0x1d6c30 blx r12
 *   @0x1d6c34 mov r1, r5
 *   @0x1d6c38 str r0, [r7, #0x4]
 *   @0x1d6c3c mov r0, r9
 *   @0x1d6c40 bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib>
 *   @0x1d6c44 ldr r2, [r4, #0x40]
 *   @0x1d6c48 ldr r3, [r4, #0x44]
 *   @0x1d6c4c str r5, [sp, #0x8]
 *   @0x1d6c50 vmov s14, r2
 *   @0x1d6c54 str r11, [sp]
 *   @0x1d6c58 vmov s15, r3
 *   @0x1d6c5c str r10, [sp, #0x4]
 *   @0x1d6c60 vcvt.f32.s32 s14, s14
 *   @0x1d6c64 vcvt.f32.s32 s15, s15
 *   @0x1d6c68 vmov r2, s14
 *   @0x1d6c6c vmov r3, s15
 *   @0x1d6c70 mov r1, r0
 *   @0x1d6c74 mov r0, #13
 *   @0x1d6c78 bl 0x1d68a0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b>
 *   @0x1d6c7c mov r1, r5
 *   @0x1d6c80 mov r0, #3
 *   @0x1d6c84 bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib>
 *   @0x1d6c88 ldr r2, [r4, #0x40]
 *   @0x1d6c8c ldr r3, [r4, #0x44]
 *   @0x1d6c90 str r11, [sp]
 *   @0x1d6c94 vmov s14, r2
 *   @0x1d6c98 str r10, [sp, #0x4]
 *   @0x1d6c9c vmov s15, r3
 *   @0x1d6ca0 str r8, [sp, #0x8]
 *   @0x1d6ca4 vcvt.f32.s32 s14, s14
 *   @0x1d6ca8 vcvt.f32.s32 s15, s15
 *   @0x1d6cac vmov r2, s14
 *   @0x1d6cb0 vmov r3, s15
 *   @0x1d6cb4 mov r1, r0
 *   @0x1d6cb8 mov r0, #13
 *   @0x1d6cbc bl 0x1d68a0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b>
 *   @0x1d6cc0 mov r1, r5
 *   @0x1d6cc4 mov r0, #4
 *   @0x1d6cc8 bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib>
 *   @0x1d6ccc ldr r2, [r4, #0x40]
 *   @0x1d6cd0 ldr r3, [r4, #0x44]
 *   @0x1d6cd4 str r11, [sp]
 *   @0x1d6cd8 vmov s14, r2
 *   @0x1d6cdc str r10, [sp, #0x4]
 *   @0x1d6ce0 vmov s15, r3
 *   @0x1d6ce4 str r8, [sp, #0x8]
 *   @0x1d6ce8 vcvt.f32.s32 s14, s14
 *   @0x1d6cec vcvt.f32.s32 s15, s15
 *   @0x1d6cf0 vmov r2, s14
 *   @0x1d6cf4 vmov r3, s15
 *   @0x1d6cf8 mov r1, r0
 *   @0x1d6cfc mov r0, #13
 *   @0x1d6d00 bl 0x1d68a0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b>
 *   @0x1d6d04 mov r1, r5
 *   @0x1d6d08 mov r0, #5
 *   @0x1d6d0c bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib>
 *   @0x1d6d10 ldr r2, [r4, #0x40]
 *   @0x1d6d14 ldr r3, [r4, #0x44]
 *   @0x1d6d18 str r11, [sp]
 *   @0x1d6d1c vmov s14, r2
 *   @0x1d6d20 str r10, [sp, #0x4]
 *   @0x1d6d24 vmov s15, r3
 *   @0x1d6d28 str r8, [sp, #0x8]
 *   @0x1d6d2c vcvt.f32.s32 s14, s14
 *   @0x1d6d30 vcvt.f32.s32 s15, s15
 *   @0x1d6d34 vmov r2, s14
 *   @0x1d6d38 vmov r3, s15
 *   @0x1d6d3c mov r1, r0
 *   @0x1d6d40 mov r0, #13
 *   @0x1d6d44 bl 0x1d68a0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b>
 *   @0x1d6d48 ldr r2, [r4, #0xc]
 *   @0x1d6d4c ldr r12, [r4, #0x10]
 *   @0x1d6d50 mov r3, r8
 *   @0x1d6d54 ldr r1, [pc, #0x420]
 *   @0x1d6d58 mov r0, #12
 *   @0x1d6d5c str r2, [r7, #0x8]
 *   @0x1d6d60 mov r2, #143
 *   @0x1d6d64 str r12, [r7, #0xc]
 *   @0x1d6d68 ldr r6, [r6, r1]
 *   @0x1d6d6c ldr r1, [pc, #0x40c]
 *   @0x1d6d70 ldr r12, [r6, #0x8]
 *   @0x1d6d74 add r1, pc, r1
 *   @0x1d6d78 add r12, r12, r8
 *   @0x1d6d7c str r12, [r6, #0x8]
 *   @0x1d6d80 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1d6d84 ldr r3, [r6, #0x4]
 *   @0x1d6d88 cmp r3, #0
 *   @0x1d6d8c str r7, [r0, #0x8]
 *   @0x1d6d90 streq r0, [r6, #0x4]
 *   @0x1d6d94 strne r0, [r3]
 *   @0x1d6d98 streq r3, [r0, #0x4]
 *   @0x1d6d9c strne r3, [r0, #0x4]
 *   @0x1d6da0 streq r0, [r6]
 *   @0x1d6da4 strne r0, [r6, #0x4]
 *   @0x1d6da8 streq r3, [r0]
 *   @0x1d6dac mov r3, #1
 *   @0x1d6db0 strne r5, [r0]
 *   @0x1d6db4 str r3, [r4, #0x14]
 *   @0x1d6db8 add sp, sp, #36
 *   @0x1d6dbc vpop {d8, d9}
 *   @0x1d6dc0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1d6dc4 mov r0, r5
 *   @0x1d6dc8 ldr r1, [r4, #0x28]
 *   @0x1d6dcc bl 0x18c0b4 <_Z14IO_Button_Downii>
 *   @0x1d6dd0 subs r8, r0, #0
 *   @0x1d6dd4 beq 0x1d6eb4 <_ZN12CGestureDrag6UpdateEx+0x324>
 *   @0x1d6dd8 ldr r2, [r4, #0x30]
 *   @0x1d6ddc ldr r3, [r4, #0x38]
 *   @0x1d6de0 cmp r2, r3
 *   @0x1d6de4 bne 0x1d6df8 <_ZN12CGestureDrag6UpdateEx+0x268>
 *   @0x1d6de8 ldr r2, [r4, #0x34]
 *   @0x1d6dec ldr r3, [r4, #0x3c]
 *   @0x1d6df0 cmp r2, r3
 *   @0x1d6df4 beq 0x1d6bd0 <_ZN12CGestureDrag6UpdateEx+0x40>
 *   @0x1d6df8 mov r0, #16
 *   @0x1d6dfc mov r7, #0
 *   @0x1d6e00 bl 0x27c524 <_Znwj>
 *   @0x1d6e04 ldr lr, [r4, #0x3c]
 *   @0x1d6e08 ldr r12, [r4]
 *   @0x1d6e0c mvn r9, #0
 *   @0x1d6e10 ldr r1, [r4, #0x30]
 *   @0x1d6e14 mov r8, #3
 *   @0x1d6e18 ldr r2, [r4, #0x34]
 *   @0x1d6e1c ldr r3, [r4, #0x38]
 *   @0x1d6e20 mov r5, r0
 *   @0x1d6e24 mov r0, r4
 *   @0x1d6e28 str r7, [r5, #0x8]
 *   @0x1d6e2c stm r5, {r8, r9}
 *   @0x1d6e30 str r7, [r5, #0xc]
 *   @0x1d6e34 str lr, [sp]
 *   @0x1d6e38 strd r10, r11, [sp, #8]
 *   @0x1d6e3c ldr r12, [r12, #0x1c]
 *   @0x1d6e40 blx r12
 *   @0x1d6e44 ldr r1, [r4, #0x10]
 *   @0x1d6e48 ldr lr, [r4, #0xc]
 *   @0x1d6e4c mov r3, #1
 *   @0x1d6e50 ldr r12, [pc, #0x324]
 *   @0x1d6e54 mov r2, #143
 *   @0x1d6e58 str r1, [r5, #0xc]
 *   @0x1d6e5c str lr, [r5, #0x8]
 *   @0x1d6e60 ldr r1, [pc, #0x31c]
 *   @0x1d6e64 add r1, pc, r1
 *   @0x1d6e68 str r0, [r5, #0x4]
 *   @0x1d6e6c mov r0, #12
 *   @0x1d6e70 ldr r4, [r6, r12]
 *   @0x1d6e74 ldr r12, [r4, #0x8]
 *   @0x1d6e78 add r12, r12, r3
 *   @0x1d6e7c str r12, [r4, #0x8]
 *   @0x1d6e80 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1d6e84 ldr r3, [r4, #0x4]
 *   @0x1d6e88 cmp r3, r7
 *   @0x1d6e8c str r5, [r0, #0x8]
 *   @0x1d6e90 streq r0, [r4, #0x4]
 *   @0x1d6e94 strne r0, [r3]
 *   @0x1d6e98 streq r0, [r4]
 *   @0x1d6e9c strne r3, [r0, #0x4]
 *   @0x1d6ea0 streq r3, [r0, #0x4]
 *   @0x1d6ea4 strne r0, [r4, #0x4]
 *   @0x1d6ea8 streq r3, [r0]
 *   @0x1d6eac strne r7, [r0]
 *   @0x1d6eb0 b 0x1d6bd0 <_ZN12CGestureDrag6UpdateEx+0x40>
 *   @0x1d6eb4 mov r0, #16
 *   @0x1d6eb8 mvn r9, #0
 *   @0x1d6ebc bl 0x27c524 <_Znwj>
 *   @0x1d6ec0 ldr lr, [r4, #0x3c]
 *   @0x1d6ec4 ldr r12, [r4]
 *   @0x1d6ec8 ldr r1, [r4, #0x30]
 *   @0x1d6ecc str lr, [sp, #0x14]
 *   @0x1d6ed0 mov lr, #4
 *   @0x1d6ed4 ldr r2, [r4, #0x34]
 *   @0x1d6ed8 ldr r3, [r4, #0x38]
 *   @0x1d6edc mov r7, r0
 *   @0x1d6ee0 mov r0, r4
 *   @0x1d6ee4 str lr, [r7]
 *   @0x1d6ee8 ldr lr, [sp, #0x14]
 *   @0x1d6eec str r8, [r7, #0x8]
 *   @0x1d6ef0 str r8, [r7, #0xc]
 *   @0x1d6ef4 str r9, [r7, #0x4]
 *   @0x1d6ef8 str lr, [sp]
 *   @0x1d6efc strd r10, r11, [sp, #8]
 *   @0x1d6f00 ldr r12, [r12, #0x1c]
 *   @0x1d6f04 blx r12
 *   @0x1d6f08 ldrd r2, r3, [r4, #32]
 *   @0x1d6f0c vldr s14, [r4, #56]
 *   @0x1d6f10 vldr s15, [r4, #60]
 *   @0x1d6f14 vcvt.f32.s32 s16, s14
 *   @0x1d6f18 mov r1, r11
 *   @0x1d6f1c vldr s14, [r4, #48]
 *   @0x1d6f20 vcvt.f32.s32 s19, s15
 *   @0x1d6f24 vldr s15, [r4, #52]
 *   @0x1d6f28 vcvt.f32.s32 s18, s14
 *   @0x1d6f2c vcvt.f32.s32 s17, s15
 *   @0x1d6f30 str r0, [r7, #0x4]
 *   @0x1d6f34 mov r0, r10
 *   @0x1d6f38 subs r0, r0, r2
 *   @0x1d6f3c sbc r1, r1, r3
 *   @0x1d6f40 bl 0x319398 <__floatdisf>
 *   @0x1d6f44 vldr s15, [pc, #552]
 *   @0x1d6f48 vmov r3, s17
 *   @0x1d6f4c add r12, sp, #24
 *   @0x1d6f50 vmov r1, s19
 *   @0x1d6f54 vmov r2, s18
 *   @0x1d6f58 str r12, [sp, #0x4]
 *   @0x1d6f5c add r12, sp, #28
 *   @0x1d6f60 str r12, [sp, #0x8]
 *   @0x1d6f64 vmov s14, r0
 *   @0x1d6f68 vmov r0, s16
 *   @0x1d6f6c vdiv.f32 s15, s14, s15
 *   @0x1d6f70 vstr s15, [sp]
 *   @0x1d6f74 bl 0x1d6854 <_Z12CalcVelocityfffffRfS_>
 *   @0x1d6f78 vldr s14, [sp, #24]
 *   @0x1d6f7c vldr s15, [sp, #28]
 *   @0x1d6f80 vcvt.s32.f32 s14, s14
 *   @0x1d6f84 vcvt.s32.f32 s15, s15
 *   @0x1d6f88 vmov r0, s14
 *   @0x1d6f8c vmov r1, s15
 *   @0x1d6f90 bl 0x1d6708 <_Z14CalcDistInchesii>
 *   @0x1d6f94 ldr r3, [pc, #0x1ec]
 *   @0x1d6f98 ldr r3, [r6, r3]
 *   @0x1d6f9c vldr s15, [r3]
 *   @0x1d6fa0 vmov s14, r0
 *   @0x1d6fa4 ldr r0, [r7, #0x4]
 *   @0x1d6fa8 vcmpe.f32 s14, s15
 *   @0x1d6fac vmrs APSR_nzcv, fpscr
 *   @0x1d6fb0 ble 0x1d704c <_ZN12CGestureDrag6UpdateEx+0x4bc>
 *   @0x1d6fb4 ldr r1, [pc, #0x1d0]
 *   @0x1d6fb8 mov r3, #0
 *   @0x1d6fbc mov r2, #0
 *   @0x1d6fc0 movt r3, #0x3ff0
 *   @0x1d6fc4 add r1, pc, r1
 *   @0x1d6fc8 bl 0x20bf40 <_Z10AddToDsMapiPcd>
 *   @0x1d6fcc ldr r12, [r4, #0x10]
 *   @0x1d6fd0 mov r2, #143
 *   @0x1d6fd4 ldr lr, [r4, #0xc]
 *   @0x1d6fd8 mov r3, #1
 *   @0x1d6fdc ldr r1, [pc, #0x198]
 *   @0x1d6fe0 mov r0, #12
 *   @0x1d6fe4 str r12, [r7, #0xc]
 *   @0x1d6fe8 str lr, [r7, #0x8]
 *   @0x1d6fec ldr r6, [r6, r1]
 *   @0x1d6ff0 ldr r1, [pc, #0x198]
 *   @0x1d6ff4 ldr r12, [r6, #0x8]
 *   @0x1d6ff8 add r1, pc, r1
 *   @0x1d6ffc add r12, r12, r3
 *   @0x1d7000 str r12, [r6, #0x8]
 *   @0x1d7004 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1d7008 ldr r3, [r6, #0x4]
 *   @0x1d700c cmp r3, #0
 *   @0x1d7010 movne r2, #0
 *   @0x1d7014 streq r0, [r6, #0x4]
 *   @0x1d7018 streq r0, [r6]
 *   @0x1d701c str r7, [r0, #0x8]
 *   @0x1d7020 streq r3, [r0, #0x4]
 *   @0x1d7024 strne r0, [r3]
 *   @0x1d7028 streq r3, [r0]
 *   @0x1d702c strne r3, [r0, #0x4]
 *   @0x1d7030 strne r0, [r6, #0x4]
 *   @0x1d7034 strne r2, [r0]
 *   @0x1d7038 cmp r5, #0
 *   @0x1d703c bne 0x1d7068 <_ZN12CGestureDrag6UpdateEx+0x4d8>
 *   @0x1d7040 mvn r3, #0
 *   @0x1d7044 str r3, [r4, #0x14]
 *   @0x1d7048 b 0x1d6bd0 <_ZN12CGestureDrag6UpdateEx+0x40>
 *   @0x1d704c ldr r1, [pc, #0x140]
 *   @0x1d7050 mov r2, #0
 *   @0x1d7054 mov r3, #0
 *   @0x1d7058 mov r5, r8
 *   @0x1d705c add r1, pc, r1
 *   @0x1d7060 bl 0x20bf40 <_Z10AddToDsMapiPcd>
 *   @0x1d7064 b 0x1d6fcc <_ZN12CGestureDrag6UpdateEx+0x43c>
 *   @0x1d7068 mov r0, #16
 *   @0x1d706c mov r7, #0
 *   @0x1d7070 bl 0x27c524 <_Znwj>
 *   @0x1d7074 ldr lr, [r4, #0x3c]
 *   @0x1d7078 ldr r2, [r4, #0x34]
 *   @0x1d707c mvn r9, #0
 *   @0x1d7080 ldr r3, [r4, #0x38]
 *   @0x1d7084 mov r8, #1
 *   @0x1d7088 str lr, [sp, #0x14]
 *   @0x1d708c mov lr, #5
 *   @0x1d7090 ldr r12, [r4]
 *   @0x1d7094 ldr r1, [r4, #0x30]
 *   @0x1d7098 mov r5, r0
 *   @0x1d709c mov r0, r4
 *   @0x1d70a0 str lr, [r5]
 *   @0x1d70a4 ldr lr, [sp, #0x14]
 *   @0x1d70a8 str r7, [r5, #0x8]
 *   @0x1d70ac str r9, [r5, #0x4]
 *   @0x1d70b0 str r7, [r5, #0xc]
 *   @0x1d70b4 str lr, [sp]
 *   @0x1d70b8 strd r10, r11, [sp, #8]
 *   @0x1d70bc ldr r12, [r12, #0x1c]
 *   @0x1d70c0 blx r12
 *   @0x1d70c4 mov r1, r7
 *   @0x1d70c8 str r0, [r5, #0x4]
 *   @0x1d70cc ldr r0, [r5]
 *   @0x1d70d0 bl 0x1d6b44 <_Z28ConvertGestureEventToGMEventib>
 *   @0x1d70d4 ldr r2, [r4, #0x30]
 *   @0x1d70d8 ldr r3, [r4, #0x34]
 *   @0x1d70dc add r12, r4, #12
 *   @0x1d70e0 str r12, [sp]
 *   @0x1d70e4 vmov s14, r2
 *   @0x1d70e8 vmov s15, r3
 *   @0x1d70ec vcvt.f32.s32 s14, s14
 *   @0x1d70f0 vcvt.f32.s32 s15, s15
 *   @0x1d70f4 vmov r2, s14
 *   @0x1d70f8 vmov r3, s15
 *   @0x1d70fc mov r1, r0
 *   @0x1d7100 add r0, r4, #16
 *   @0x1d7104 stmib sp, {r0, r8}
 *   @0x1d7108 mov r0, #13
 *   @0x1d710c bl 0x1d68a0 <_Z28GetInstanceListWithEventTypeiiffPPiS_b>
 *   @0x1d7110 ldr r1, [r4, #0x10]
 *   @0x1d7114 ldr r2, [r4, #0xc]
 *   @0x1d7118 mov r3, r8
 *   @0x1d711c ldr r12, [r6, #0x8]
 *   @0x1d7120 mov r0, #12
 *   @0x1d7124 str r1, [r5, #0xc]
 *   @0x1d7128 ldr r1, [pc, #0x68]
 *   @0x1d712c add r12, r12, r8
 *   @0x1d7130 str r2, [r5, #0x8]
 *   @0x1d7134 mov r2, #143
 *   @0x1d7138 add r1, pc, r1
 *   @0x1d713c str r12, [r6, #0x8]
 *   @0x1d7140 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1d7144 ldr r3, [r6, #0x4]
 *   @0x1d7148 cmp r3, r7
 *   @0x1d714c str r5, [r0, #0x8]
 *   @0x1d7150 streq r0, [r6, #0x4]
 *   @0x1d7154 strne r0, [r3]
 *   @0x1d7158 streq r0, [r6]
 *   @0x1d715c strne r3, [r0, #0x4]
 *   @0x1d7160 streq r3, [r0, #0x4]
 *   @0x1d7164 strne r0, [r6, #0x4]
 *   @0x1d7168 streq r3, [r0]
 *   @0x1d716c strne r7, [r0]
 *   @0x1d7170 b 0x1d7040 <_ZN12CGestureDrag6UpdateEx+0x4b0>
 *   @0x1d7174 ldmdbmi r4!, {r10, sp} ^
 *   @0x1d7178 mlaeq r1, r0, r0, r11
 *   @0x1d717c .word 0xffffefb0
 *   @0x1d7180 ldrheq r6, [r7], -r12
 *   @0x1d7184 andseq r5, r7, r12, asr #31
 *   @0x1d7188 .word 0xffffef7c
 *   @0x1d718c andseq r10, r7, r0, lsr #3
 *   @0x1d7190 andseq r5, r7, r8, lsr lr
 *   @0x1d7194 andseq r10, r7, r8, lsl #2
 *   @0x1d7198 ldrsheq r5, [r7], -r8
 *
 * ══ §6/21 JS_String_prototype_split(RValue&, CInstance*, CInstance*, int, RValue*)  0x25883c  size 1536  384 条（0x25883c..0x258e3c）
 * @func 0x25883c 0x258e3c  size 1536  384 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FREE_RValue__Pre(RValue*)×6 / JS_Array_Put(YYObjectBase*, RValue*, char const*)×4 / operator delete(void*)×3 / F_JS_ToString(RValue&, RValue*)×2 / 0xb6538×2 / JSThrowTypeError(char const*)×2 / 0xb65b0×2 / 0xb6568×2
 * 字段偏移 top8: 0x-e8×8 / 0x-100×7 / 0x-d8×6 / 0x-cc×6 / 0x-dc×5 / 0x-b8×5 / 0x-b4×5 / 0x-110×5
 * VFP 指令 10 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x25883c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x258840 add r11, sp, #32
 *   @0x258844 ldr r4, [pc, #0x5d8]
 *   @0x258848 sub sp, sp, #268
 *   @0x25884c sub r8, r11, #36
 *   @0x258850 ldr r4, [pc, r4]
 *   @0x258854 str r2, [r11, #-0x100]
 *   @0x258858 str r1, [r8, #-0xd4]!
 *   @0x25885c mov r7, r0
 *   @0x258860 ldr r2, [r4]
 *   @0x258864 mov r0, r8
 *   @0x258868 mov r5, r1
 *   @0x25886c mov r9, r3
 *   @0x258870 ldr r6, [r11, #0x4]
 *   @0x258874 mov r3, #6
 *   @0x258878 str r2, [r11, #-0x28]
 *   @0x25887c str r3, [r11, #-0xec]
 *   @0x258880 bl 0x2423a4 <_Z23JS_CheckObjectCoercibleR6RValue>
 *   @0x258884 cmp r0, #1
 *   @0x258888 beq 0x258a08 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x1cc>
 *   @0x25888c sub r12, r11, #232
 *   @0x258890 mov r1, r8
 *   @0x258894 mov r10, #0
 *   @0x258898 str r12, [r11, #-0x104]
 *   @0x25889c mov r0, r12
 *   @0x2588a0 mvn r8, #-16777216
 *   @0x2588a4 str r10, [r11, #-0xe8]
 *   @0x2588a8 str r10, [r11, #-0xe4]
 *   @0x2588ac str r10, [r11, #-0xe0]
 *   @0x2588b0 str r8, [r11, #-0xdc]
 *   @0x2588b4 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x2588b8 cmp r0, #2
 *   @0x2588bc beq 0x2589f0 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x1b4>
 *   @0x2588c0 cmp r0, #1
 *   @0x2588c4 beq 0x258a08 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x1cc>
 *   @0x2588c8 str r6, [sp]
 *   @0x2588cc mov r1, r5
 *   @0x2588d0 ldr r2, [r11, #-0x100]
 *   @0x2588d4 mov r0, r7
 *   @0x2588d8 mov r3, r10
 *   @0x2588dc bl 0x242c84 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_>
 *   @0x2588e0 cmp r9, #1
 *   @0x2588e4 ble 0x258a18 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x1dc>
 *   @0x2588e8 ldr r3, [r6, #0x1c]
 *   @0x2588ec cmp r3, #5
 *   @0x2588f0 mvneq r12, #0
 *   @0x2588f4 streq r12, [r11, #-0x110]
 *   @0x2588f8 beq 0x25892c <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0xf0>
 *   @0x2588fc sub r0, r11, #184
 *   @0x258900 add r1, r6, #16
 *   @0x258904 str r10, [r11, #-0xb8]
 *   @0x258908 str r10, [r11, #-0xb4]
 *   @0x25890c str r10, [r11, #-0xb0]
 *   @0x258910 str r8, [r11, #-0xac]
 *   @0x258914 bl 0x24d4f4 <_Z13F_JS_ToUint32R6RValueS0_>
 *   @0x258918 ldr r2, [r11, #-0xb8]
 *   @0x25891c ldr r3, [r11, #-0xb4]
 *   @0x258920 vmov d7, r2, r3
 *   @0x258924 vcvt.s32.f64 s15, d7
 *   @0x258928 vstr s15, [r11, #-272]
 *   @0x25892c ldr r5, [r11, #-0xe8]
 *   @0x258930 ldr r0, [r5]
 *   @0x258934 bl 0xb6538 <strlen@plt>
 *   @0x258938 mov r3, #0
 *   @0x25893c mvn r2, #-16777216
 *   @0x258940 str r3, [r11, #-0xd8]
 *   @0x258944 str r3, [r11, #-0xd4]
 *   @0x258948 str r3, [r11, #-0xd0]
 *   @0x25894c str r2, [r11, #-0xcc]
 *   @0x258950 str r0, [r11, #-0x100]
 *   @0x258954 ldr r3, [r6, #0xc]
 *   @0x258958 cmp r3, #5
 *   @0x25895c beq 0x258a40 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x204>
 *   @0x258960 bic r3, r3, #-16777216
 *   @0x258964 cmp r3, #6
 *   @0x258968 beq 0x258a58 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x21c>
 *   @0x25896c sub r12, r11, #216
 *   @0x258970 mov r1, r6
 *   @0x258974 str r12, [r11, #-0x118]
 *   @0x258978 mov r0, r12
 *   @0x25897c bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x258980 cmp r0, #2
 *   @0x258984 beq 0x2589f0 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x1b4>
 *   @0x258988 cmp r0, #1
 *   @0x25898c beq 0x258aa8 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x26c>
 *   @0x258990 ldr r12, [r11, #-0x110]
 *   @0x258994 cmp r12, #0
 *   @0x258998 bne 0x258ad0 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x294>
 *   @0x25899c ldr r3, [r11, #-0xcc]
 *   @0x2589a0 sub r3, r3, #1
 *   @0x2589a4 bic r3, r3, #-16777216
 *   @0x2589a8 bic r3, r3, #3
 *   @0x2589ac cmp r3, #0
 *   @0x2589b0 bne 0x2589bc <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x180>
 *   @0x2589b4 sub r0, r11, #216
 *   @0x2589b8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x2589bc ldr r1, [r11, #-0xdc]
 *   @0x2589c0 mov r3, #0
 *   @0x2589c4 str r3, [r11, #-0xd0]
 *   @0x2589c8 mov r2, #5
 *   @0x2589cc sub r1, r1, #1
 *   @0x2589d0 str r3, [r11, #-0xd8]
 *   @0x2589d4 bic r3, r1, #-16777216
 *   @0x2589d8 str r2, [r11, #-0xcc]
 *   @0x2589dc bic r3, r3, #3
 *   @0x2589e0 cmp r3, #0
 *   @0x2589e4 bne 0x2589f0 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x1b4>
 *   @0x2589e8 sub r0, r11, #232
 *   @0x2589ec bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x2589f0 ldr r2, [r11, #-0x28]
 *   @0x2589f4 ldr r3, [r4]
 *   @0x2589f8 cmp r2, r3
 *   @0x2589fc bne 0x258e14 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x5d8>
 *   @0x258a00 sub sp, r11, #32
 *   @0x258a04 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x258a08 ldr r0, [pc, #0x418]
 *   @0x258a0c add r0, pc, r0
 *   @0x258a10 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x258a14 b 0x2589f0 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x1b4>
 *   @0x258a18 ldr r5, [r11, #-0xe8]
 *   @0x258a1c ldr r0, [r5]
 *   @0x258a20 bl 0xb6538 <strlen@plt>
 *   @0x258a24 cmp r9, #0
 *   @0x258a28 str r10, [r11, #-0xd8]
 *   @0x258a2c str r10, [r11, #-0xd4]
 *   @0x258a30 str r10, [r11, #-0xd0]
 *   @0x258a34 str r8, [r11, #-0xcc]
 *   @0x258a38 str r0, [r11, #-0x100]
 *   @0x258a3c bne 0x258e18 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x5dc>
 *   @0x258a40 ldr r2, [pc, #0x3e4]
 *   @0x258a44 sub r1, r11, #232
 *   @0x258a48 ldr r0, [r7]
 *   @0x258a4c add r2, pc, r2
 *   @0x258a50 bl 0x24861c <_Z12JS_Array_PutP12YYObjectBaseP6RValuePKc>
 *   @0x258a54 b 0x2589f0 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x1b4>
 *   @0x258a58 ldr r8, [r6]
 *   @0x258a5c ldr r1, [pc, #0x3cc]
 *   @0x258a60 ldr r0, [r8, #0x40]
 *   @0x258a64 add r1, pc, r1
 *   @0x258a68 bl 0xb6574 <strcmp@plt>
 *   @0x258a6c cmp r0, #0
 *   @0x258a70 bne 0x25896c <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x258a74 ldr r12, [r11, #-0x110]
 *   @0x258a78 cmp r12, #0
 *   @0x258a7c beq 0x25899c <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x258a80 ldr r12, [r11, #-0x100]
 *   @0x258a84 sub r3, r11, #232
 *   @0x258a88 ldr r2, [r5]
 *   @0x258a8c mov r0, r7
 *   @0x258a90 str r3, [sp, #0x4]
 *   @0x258a94 mov r1, r8
 *   @0x258a98 str r12, [sp]
 *   @0x258a9c ldr r3, [r11, #-0x110]
 *   @0x258aa0 bl 0x2486b8 <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_>
 *   @0x258aa4 b 0x25899c <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x258aa8 ldr r0, [pc, #0x384]
 *   @0x258aac add r0, pc, r0
 *   @0x258ab0 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x258ab4 ldr r3, [r11, #-0xdc]
 *   @0x258ab8 sub r3, r3, #1
 *   @0x258abc bic r3, r3, #-16777216
 *   @0x258ac0 bic r3, r3, #3
 *   @0x258ac4 cmp r3, #0
 *   @0x258ac8 bne 0x2589f0 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x1b4>
 *   @0x258acc b 0x2589e8 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x1ac>
 *   @0x258ad0 ldr r12, [r11, #-0x100]
 *   @0x258ad4 cmp r12, #0
 *   @0x258ad8 beq 0x258dac <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x570>
 *   @0x258adc mov r10, #0
 *   @0x258ae0 mov r3, r7
 *   @0x258ae4 sub r12, r11, #184
 *   @0x258ae8 mov r8, r10
 *   @0x258aec str r12, [r11, #-0x114]
 *   @0x258af0 mov r9, r10
 *   @0x258af4 sub r12, r11, #200
 *   @0x258af8 mov r5, r10
 *   @0x258afc str r12, [r11, #-0x108]
 *   @0x258b00 mov r7, r10
 *   @0x258b04 sub r12, r11, #168
 *   @0x258b08 str r4, [r11, #-0x11c]
 *   @0x258b0c str r12, [r11, #-0x10c]
 *   @0x258b10 mov r10, r3
 *   @0x258b14 b 0x258c28 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x3ec>
 *   @0x258b18 rsb r12, r8, r7
 *   @0x258b1c mov r1, #0
 *   @0x258b20 add r3, r12, #15
 *   @0x258b24 add r2, r12, #1
 *   @0x258b28 bic r3, r3, #7
 *   @0x258b2c str r12, [r11, #-0x120]
 *   @0x258b30 sub sp, sp, r3
 *   @0x258b34 add r7, sp, #8
 *   @0x258b38 mov r0, r7
 *   @0x258b3c bl 0xb65b0 <memset@plt>
 *   @0x258b40 ldr r1, [r11, #-0xe8]
 *   @0x258b44 ldr r12, [r11, #-0x120]
 *   @0x258b48 mov r0, r7
 *   @0x258b4c ldr r1, [r1]
 *   @0x258b50 mov r2, r12
 *   @0x258b54 add r1, r1, r8
 *   @0x258b58 bl 0xb6568 <strncpy@plt>
 *   @0x258b5c mov r1, r7
 *   @0x258b60 sub r0, r11, #200
 *   @0x258b64 mvn r3, #-16777216
 *   @0x258b68 str r5, [r11, #-0xc8]
 *   @0x258b6c str r3, [r11, #-0xbc]
 *   @0x258b70 str r5, [r11, #-0xc4]
 *   @0x258b74 str r5, [r11, #-0xc0]
 *   @0x258b78 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x258b7c mov r2, #0
 *   @0x258b80 ldr r1, [r10]
 *   @0x258b84 mov r3, r2
 *   @0x258b88 sub r0, r11, #184
 *   @0x258b8c str r5, [sp]
 *   @0x258b90 mvn r12, #-16777216
 *   @0x258b94 str r5, [r11, #-0xb8]
 *   @0x258b98 str r12, [r11, #-0xac]
 *   @0x258b9c str r5, [r11, #-0xb4]
 *   @0x258ba0 str r5, [r11, #-0xb0]
 *   @0x258ba4 bl 0x23ce24 <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_>
 *   @0x258ba8 vldr s14, [r11, #-184]
 *   @0x258bac vldr s15, [r11, #-180]
 *   @0x258bb0 vcvt.s32.f64 s13, d7
 *   @0x258bb4 sub r1, r11, #168
 *   @0x258bb8 mov r2, #10
 *   @0x258bbc vmov r0, s13
 *   @0x258bc0 bl 0xc4964 <_Z5_itoaiPci>
 *   @0x258bc4 ldr r0, [r10]
 *   @0x258bc8 sub r1, r11, #200
 *   @0x258bcc sub r2, r11, #168
 *   @0x258bd0 bl 0x24861c <_Z12JS_Array_PutP12YYObjectBaseP6RValuePKc>
 *   @0x258bd4 ldr r3, [r11, #-0xbc]
 *   @0x258bd8 sub r3, r3, #1
 *   @0x258bdc bic r3, r3, #-16777216
 *   @0x258be0 bic r3, r3, #3
 *   @0x258be4 cmp r3, #0
 *   @0x258be8 beq 0x258c5c <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x420>
 *   @0x258bec ldr r12, [r11, #-0x110]
 *   @0x258bf0 add r9, r9, #1
 *   @0x258bf4 mov r3, #5
 *   @0x258bf8 str r5, [r11, #-0xc0]
 *   @0x258bfc cmp r9, r12
 *   @0x258c00 str r3, [r11, #-0xbc]
 *   @0x258c04 str r5, [r11, #-0xc8]
 *   @0x258c08 beq 0x258dd4 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x598>
 *   @0x258c0c mov r7, r4
 *   @0x258c10 mov r8, r4
 *   @0x258c14 mov r0, r6
 *   @0x258c18 bl 0x27d1d0 <_ZdlPv>
 *   @0x258c1c ldr r12, [r11, #-0x100]
 *   @0x258c20 cmp r7, r12
 *   @0x258c24 beq 0x258c68 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x42c>
 *   @0x258c28 ldr r2, [r11, #-0xe8]
 *   @0x258c2c mov r1, r7
 *   @0x258c30 ldr r3, [r11, #-0xd8]
 *   @0x258c34 ldr r0, [r2]
 *   @0x258c38 ldr r2, [r3]
 *   @0x258c3c bl 0x242604 <_Z13JS_SplitMatchPKciS0_>
 *   @0x258c40 subs r6, r0, #0
 *   @0x258c44 beq 0x258c54 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x418>
 *   @0x258c48 ldr r4, [r6]
 *   @0x258c4c cmp r4, r8
 *   @0x258c50 bne 0x258b18 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x2dc>
 *   @0x258c54 add r7, r7, #1
 *   @0x258c58 b 0x258c14 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x3d8>
 *   @0x258c5c sub r0, r11, #200
 *   @0x258c60 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x258c64 b 0x258bec <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x3b0>
 *   @0x258c68 mov r3, r10
 *   @0x258c6c mov r10, r7
 *   @0x258c70 rsb r10, r8, r10
 *   @0x258c74 mov r7, r3
 *   @0x258c78 add r3, r10, #15
 *   @0x258c7c mov r1, #0
 *   @0x258c80 bic r3, r3, #7
 *   @0x258c84 add r2, r10, #1
 *   @0x258c88 sub sp, sp, r3
 *   @0x258c8c mov r5, r1
 *   @0x258c90 add r9, sp, #8
 *   @0x258c94 ldr r4, [r11, #-0x11c]
 *   @0x258c98 mvn r6, #-16777216
 *   @0x258c9c mov r0, r9
 *   @0x258ca0 bl 0xb65b0 <memset@plt>
 *   @0x258ca4 ldr r3, [r11, #-0xe8]
 *   @0x258ca8 mov r2, r10
 *   @0x258cac mov r0, r9
 *   @0x258cb0 ldr r1, [r3]
 *   @0x258cb4 add r1, r1, r8
 *   @0x258cb8 bl 0xb6568 <strncpy@plt>
 *   @0x258cbc mov r1, r9
 *   @0x258cc0 sub r0, r11, #200
 *   @0x258cc4 str r5, [r11, #-0xc8]
 *   @0x258cc8 str r5, [r11, #-0xc4]
 *   @0x258ccc str r5, [r11, #-0xc0]
 *   @0x258cd0 str r6, [r11, #-0xbc]
 *   @0x258cd4 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x258cd8 mov r3, r5
 *   @0x258cdc ldr r1, [r7]
 *   @0x258ce0 mov r2, r5
 *   @0x258ce4 sub r0, r11, #184
 *   @0x258ce8 str r5, [sp]
 *   @0x258cec str r5, [r11, #-0xb8]
 *   @0x258cf0 str r5, [r11, #-0xb4]
 *   @0x258cf4 str r5, [r11, #-0xb0]
 *   @0x258cf8 str r6, [r11, #-0xac]
 *   @0x258cfc bl 0x23ce24 <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_>
 *   @0x258d00 ldr r8, [r11, #-0xb8]
 *   @0x258d04 sub r1, r11, #168
 *   @0x258d08 ldr r9, [r11, #-0xb4]
 *   @0x258d0c mov r2, #10
 *   @0x258d10 vmov d7, r8, r9
 *   @0x258d14 vcvt.s32.f64 s15, d7
 *   @0x258d18 vmov r0, s15
 *   @0x258d1c bl 0xc4964 <_Z5_itoaiPci>
 *   @0x258d20 ldr r0, [r7]
 *   @0x258d24 sub r2, r11, #168
 *   @0x258d28 sub r1, r11, #200
 *   @0x258d2c bl 0x24861c <_Z12JS_Array_PutP12YYObjectBaseP6RValuePKc>
 *   @0x258d30 ldr r3, [r11, #-0xcc]
 *   @0x258d34 sub r3, r3, #1
 *   @0x258d38 and r3, r3, r6
 *   @0x258d3c bic r3, r3, #3
 *   @0x258d40 cmp r3, r5
 *   @0x258d44 beq 0x258dec <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x5b0>
 *   @0x258d48 ldr r1, [r11, #-0xdc]
 *   @0x258d4c mov r3, #0
 *   @0x258d50 str r3, [r11, #-0xd0]
 *   @0x258d54 mov r2, #5
 *   @0x258d58 sub r1, r1, #1
 *   @0x258d5c str r3, [r11, #-0xd8]
 *   @0x258d60 bic r3, r1, #-16777216
 *   @0x258d64 str r2, [r11, #-0xcc]
 *   @0x258d68 bic r3, r3, #3
 *   @0x258d6c cmp r3, #0
 *   @0x258d70 beq 0x258de0 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x5a4>
 *   @0x258d74 ldr r1, [r11, #-0xbc]
 *   @0x258d78 mov r3, #0
 *   @0x258d7c str r3, [r11, #-0xe0]
 *   @0x258d80 mov r2, #5
 *   @0x258d84 sub r1, r1, #1
 *   @0x258d88 str r3, [r11, #-0xe8]
 *   @0x258d8c bic r3, r1, #-16777216
 *   @0x258d90 str r2, [r11, #-0xdc]
 *   @0x258d94 bic r3, r3, #3
 *   @0x258d98 cmp r3, #0
 *   @0x258d9c bne 0x2589f0 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x1b4>
 *   @0x258da0 sub r0, r11, #200
 *   @0x258da4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x258da8 b 0x2589f0 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x1b4>
 *   @0x258dac ldr r2, [r11, #-0xe8]
 *   @0x258db0 mov r1, r12
 *   @0x258db4 ldr r3, [r11, #-0xd8]
 *   @0x258db8 ldr r0, [r2]
 *   @0x258dbc ldr r2, [r3]
 *   @0x258dc0 bl 0x242604 <_Z13JS_SplitMatchPKciS0_>
 *   @0x258dc4 cmp r0, #0
 *   @0x258dc8 beq 0x258df8 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x5bc>
 *   @0x258dcc bl 0x27d1d0 <_ZdlPv>
 *   @0x258dd0 b 0x25899c <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x258dd4 ldr r4, [r11, #-0x11c]
 *   @0x258dd8 mov r0, r6
 *   @0x258ddc b 0x258dcc <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x590>
 *   @0x258de0 sub r0, r11, #232
 *   @0x258de4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x258de8 b 0x258d74 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x538>
 *   @0x258dec sub r0, r11, #216
 *   @0x258df0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x258df4 b 0x258d48 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x50c>
 *   @0x258df8 bl 0x27d1d0 <_ZdlPv>
 *   @0x258dfc ldr r2, [pc, #0x34]
 *   @0x258e00 ldr r0, [r7]
 *   @0x258e04 sub r1, r11, #232
 *   @0x258e08 add r2, pc, r2
 *   @0x258e0c bl 0x24861c <_Z12JS_Array_PutP12YYObjectBaseP6RValuePKc>
 *   @0x258e10 b 0x25899c <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x258e14 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x258e18 mvn r12, #0
 *   @0x258e1c str r12, [r11, #-0x110]
 *   @0x258e20 b 0x258954 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x258e24 andseq r5, r9, r0, lsl #2
 *   @0x258e28 andeq sp, pc, r12, lsr r5
 *   @0x258e2c andeq r9, sp, r0, lsr #21
 *   @0x258e30 andeq sp, pc, r8, asr #3
 *   @0x258e34 muleq pc, r12, r4
 *   @0x258e38 andeq r9, sp, r4, ror #13
 *
 * ══ §7/21 anon_2c143c  0x2c143c  size 1520  380 条（0x2c143c..0x2c1a2c）
 * @func 0x2c143c 0x2c1a2c  size 1520  380 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb68c8×3 / anon_2c143c+0x480×2 / anon_2c143c+0x23c / anon_2c143c+0x1e8 / anon_2c143c+0x47c / anon_2c143c+0x80 / anon_2c143c+0x368 / anon_2c143c+0x2dc
 * 字段偏移 top8: 0x14×10 / 0x18×7 / 0x2×7 / 0x40×6 / 0x8×6 / 0x48×5 / 0x2c×5 / 0x44×5
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c143c ldr r2, [r0, #0x48]
 *   @0x2c1440 push {r4, r5, lr}
 *   @0x2c1444 mov r4, r0
 *   @0x2c1448 ldr r3, [r2, #0x3c]
 *   @0x2c144c sub sp, sp, #12
 *   @0x2c1450 mov r5, r1
 *   @0x2c1454 cmp r3, #0
 *   @0x2c1458 beq 0x2c149c <jpeg_mem_term+0x64>
 *   @0x2c145c add r1, sp, #4
 *   @0x2c1460 mov r2, #2
 *   @0x2c1464 blx r3
 *   @0x2c1468 subs r0, r0, #2
 *   @0x2c146c movne r0, #1
 *   @0x2c1470 cmp r0, #0
 *   @0x2c1474 ldrbeq r3, [sp, #0x4]
 *   @0x2c1478 movne r3, #102
 *   @0x2c147c ldrbeq r2, [sp, #0x5]
 *   @0x2c1480 movne r0, #0
 *   @0x2c1484 moveq r0, #1
 *   @0x2c1488 strne r3, [r4, #0x40]
 *   @0x2c148c orreq r3, r3, r2, lsl #8
 *   @0x2c1490 streq r3, [r5]
 *   @0x2c1494 add sp, sp, #12
 *   @0x2c1498 pop {r4, r5, pc}
 *   @0x2c149c ldr r3, [r2, #0x38]
 *   @0x2c14a0 add r0, sp, #4
 *   @0x2c14a4 mov r1, #1
 *   @0x2c14a8 mov r2, #2
 *   @0x2c14ac bl 0xb68c8 <fread@plt>
 *   @0x2c14b0 subs r0, r0, #2
 *   @0x2c14b4 movne r0, #1
 *   @0x2c14b8 b 0x2c1470 <jpeg_mem_term+0x38>
 *   @0x2c14bc push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2c14c0 mov r8, r1
 *   @0x2c14c4 ldr r4, [r0, #0x48]
 *   @0x2c14c8 mov r5, r0
 *   @0x2c14cc ldr r1, [r4, #0x18]
 *   @0x2c14d0 cmp r1, #12
 *   @0x2c14d4 bgt 0x2c164c <jpeg_mem_term+0x214>
 *   @0x2c14d8 ldr r3, [r4, #0x2c]
 *   @0x2c14dc cmp r1, r3
 *   @0x2c14e0 addgt r9, r4, #68
 *   @0x2c14e4 addgt r6, r4, #69
 *   @0x2c14e8 movgt r7, #2
 *   @0x2c14ec ble 0x2c1678 <jpeg_mem_term+0x240>
 *   @0x2c14f0 ldrb r2, [r4, #0x44]
 *   @0x2c14f4 cmp r2, #0
 *   @0x2c14f8 bne 0x2c1570 <jpeg_mem_term+0x138>
 *   @0x2c14fc ldr r2, [r5, #0x48]
 *   @0x2c1500 ldr r3, [r2, #0x3c]
 *   @0x2c1504 cmp r3, #0
 *   @0x2c1508 beq 0x2c162c <jpeg_mem_term+0x1f4>
 *   @0x2c150c mov r0, r5
 *   @0x2c1510 mov r1, r9
 *   @0x2c1514 mov r2, #1
 *   @0x2c1518 blx r3
 *   @0x2c151c subs r0, r0, #1
 *   @0x2c1520 movne r0, #1
 *   @0x2c1524 cmp r0, #0
 *   @0x2c1528 bne 0x2c1560 <jpeg_mem_term+0x128>
 *   @0x2c152c ldrb r2, [r4, #0x44]
 *   @0x2c1530 cmp r2, #0
 *   @0x2c1534 beq 0x2c1614 <jpeg_mem_term+0x1dc>
 *   @0x2c1538 ldr r1, [r5, #0x48]
 *   @0x2c153c ldr r3, [r1, #0x3c]
 *   @0x2c1540 cmp r3, #0
 *   @0x2c1544 beq 0x2c1680 <jpeg_mem_term+0x248>
 *   @0x2c1548 mov r0, r5
 *   @0x2c154c mov r1, r6
 *   @0x2c1550 blx r3
 *   @0x2c1554 ldrb r3, [r4, #0x44]
 *   @0x2c1558 cmp r3, r0
 *   @0x2c155c beq 0x2c165c <jpeg_mem_term+0x224>
 *   @0x2c1560 mov r3, #102
 *   @0x2c1564 mov r0, #0
 *   @0x2c1568 str r3, [r5, #0x40]
 *   @0x2c156c pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2c1570 ldrb r12, [r4, #0x45]
 *   @0x2c1574 sub r2, r2, #1
 *   @0x2c1578 add r0, r12, #1
 *   @0x2c157c strb r0, [r4, #0x45]
 *   @0x2c1580 ldrb r12, [r9, r12]
 *   @0x2c1584 strb r2, [r4, #0x44]
 *   @0x2c1588 ldr r2, [r4, #0x30]
 *   @0x2c158c orr r2, r2, r12, lsl r3
 *   @0x2c1590 add r3, r3, #8
 *   @0x2c1594 cmp r1, r3
 *   @0x2c1598 str r2, [r4, #0x30]
 *   @0x2c159c str r3, [r4, #0x2c]
 *   @0x2c15a0 bgt 0x2c14f0 <jpeg_mem_term+0xb8>
 *   @0x2c15a4 ldr r3, [pc, #0xe8]
 *   @0x2c15a8 lsl r1, r1, #1
 *   @0x2c15ac add r3, pc, r3
 *   @0x2c15b0 ldrh r3, [r3, r1]
 *   @0x2c15b4 and r3, r3, r2
 *   @0x2c15b8 str r3, [r8]
 *   @0x2c15bc ldr r1, [r4, #0x14]
 *   @0x2c15c0 ldr r3, [r4, #0x18]
 *   @0x2c15c4 ldr r0, [r4, #0x2c]
 *   @0x2c15c8 cmp r1, #4096
 *   @0x2c15cc lsr r2, r2, r3
 *   @0x2c15d0 str r2, [r4, #0x30]
 *   @0x2c15d4 rsb r2, r3, r0
 *   @0x2c15d8 str r2, [r4, #0x2c]
 *   @0x2c15dc bgt 0x2c1624 <jpeg_mem_term+0x1ec>
 *   @0x2c15e0 ldr r2, [r4, #0x1c]
 *   @0x2c15e4 add r1, r1, #1
 *   @0x2c15e8 str r1, [r4, #0x14]
 *   @0x2c15ec cmp r1, r2
 *   @0x2c15f0 ble 0x2c1624 <jpeg_mem_term+0x1ec>
 *   @0x2c15f4 cmp r3, #11
 *   @0x2c15f8 bgt 0x2c1624 <jpeg_mem_term+0x1ec>
 *   @0x2c15fc lsl r2, r2, #1
 *   @0x2c1600 add r3, r3, #1
 *   @0x2c1604 str r2, [r4, #0x1c]
 *   @0x2c1608 mov r0, #1
 *   @0x2c160c str r3, [r4, #0x18]
 *   @0x2c1610 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2c1614 mov r3, #112
 *   @0x2c1618 mov r0, #0
 *   @0x2c161c str r3, [r5, #0x40]
 *   @0x2c1620 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2c1624 mov r0, #1
 *   @0x2c1628 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2c162c mov r1, #1
 *   @0x2c1630 ldr r3, [r2, #0x38]
 *   @0x2c1634 mov r0, r9
 *   @0x2c1638 mov r2, r1
 *   @0x2c163c bl 0xb68c8 <fread@plt>
 *   @0x2c1640 subs r0, r0, #1
 *   @0x2c1644 movne r0, #1
 *   @0x2c1648 b 0x2c1524 <jpeg_mem_term+0xec>
 *   @0x2c164c mov r3, #112
 *   @0x2c1650 mov r0, #0
 *   @0x2c1654 str r3, [r5, #0x40]
 *   @0x2c1658 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2c165c sub r0, r0, #1
 *   @0x2c1660 ldrb r12, [r4, #0x45]
 *   @0x2c1664 strb r0, [r4, #0x44]
 *   @0x2c1668 strb r7, [r4, #0x45]
 *   @0x2c166c ldr r1, [r4, #0x18]
 *   @0x2c1670 ldr r3, [r4, #0x2c]
 *   @0x2c1674 b 0x2c1588 <jpeg_mem_term+0x150>
 *   @0x2c1678 ldr r2, [r4, #0x30]
 *   @0x2c167c b 0x2c15a4 <jpeg_mem_term+0x16c>
 *   @0x2c1680 ldr r3, [r1, #0x38]
 *   @0x2c1684 mov r0, r6
 *   @0x2c1688 mov r1, #1
 *   @0x2c168c bl 0xb68c8 <fread@plt>
 *   @0x2c1690 b 0x2c1554 <jpeg_mem_term+0x11c>
 *   @0x2c1694 strheq lr, [r12], -r4
 *   @0x2c1698 ldr r12, [r0, #0x48]
 *   @0x2c169c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2c16a0 mov r9, r2
 *   @0x2c16a4 ldr r6, [r12, #0x28]
 *   @0x2c16a8 sub sp, sp, #44
 *   @0x2c16ac ldr r2, [r12, #0x10]
 *   @0x2c16b0 cmp r6, #4096
 *   @0x2c16b4 str r0, [sp, #0x8]
 *   @0x2c16b8 str r1, [sp, #0x14]
 *   @0x2c16bc str r2, [sp, #0xc]
 *   @0x2c16c0 ldr r8, [r12, #0xc]
 *   @0x2c16c4 ldr r11, [r12, #0x20]
 *   @0x2c16c8 bge 0x2c181c <jpeg_mem_term+0x3e4>
 *   @0x2c16cc cmp r6, #0
 *   @0x2c16d0 add r10, r12, #324
 *   @0x2c16d4 bne 0x2c1828 <jpeg_mem_term+0x3f0>
 *   @0x2c16d8 mov r7, r6
 *   @0x2c16dc cmp r9, r7
 *   @0x2c16e0 ble 0x2c18bc <jpeg_mem_term+0x484>
 *   @0x2c16e4 add r3, r12, #4416
 *   @0x2c16e8 add r4, r12, #8512
 *   @0x2c16ec add r3, r3, #3
 *   @0x2c16f0 add r2, sp, #36
 *   @0x2c16f4 add r4, r4, #4
 *   @0x2c16f8 str r2, [sp, #0x10]
 *   @0x2c16fc movw r5, #0x1002
 *   @0x2c1700 mov r2, r11
 *   @0x2c1704 mov r11, r3
 *   @0x2c1708 b 0x2c1740 <jpeg_mem_term+0x308>
 *   @0x2c170c ldr r0, [sp, #0x14]
 *   @0x2c1710 strb r3, [r0, r7]
 *   @0x2c1714 add r7, r7, #1
 *   @0x2c1718 cmp r2, r5
 *   @0x2c171c beq 0x2c1734 <jpeg_mem_term+0x2fc>
 *   @0x2c1720 ldr r3, [r12, #0x14]
 *   @0x2c1724 sub r3, r3, #-1073741822
 *   @0x2c1728 ldr r1, [r4, r3, lsl #2]
 *   @0x2c172c cmp r1, r5
 *   @0x2c1730 beq 0x2c18d0 <jpeg_mem_term+0x498>
 *   @0x2c1734 cmp r9, r7
 *   @0x2c1738 ldr r2, [sp, #0x24]
 *   @0x2c173c ble 0x2c18b8 <jpeg_mem_term+0x480>
 *   @0x2c1740 ldr r0, [sp, #0x8]
 *   @0x2c1744 add r1, sp, #36
 *   @0x2c1748 stm sp, {r2, r12}
 *   @0x2c174c bl 0x2c14bc <jpeg_mem_term+0x84>
 *   @0x2c1750 ldm sp, {r2, r12}
 *   @0x2c1754 cmp r0, #0
 *   @0x2c1758 beq 0x2c181c <jpeg_mem_term+0x3e4>
 *   @0x2c175c ldr r3, [sp, #0x24]
 *   @0x2c1760 ldr r0, [sp, #0xc]
 *   @0x2c1764 cmp r3, r0
 *   @0x2c1768 beq 0x2c19f0 <jpeg_mem_term+0x5b8>
 *   @0x2c176c cmp r8, r3
 *   @0x2c1770 beq 0x2c1870 <jpeg_mem_term+0x438>
 *   @0x2c1774 bgt 0x2c170c <jpeg_mem_term+0x2d4>
 *   @0x2c1778 ldr r1, [r4, r3, lsl #2]
 *   @0x2c177c cmp r1, r5
 *   @0x2c1780 beq 0x2c192c <jpeg_mem_term+0x4f4>
 *   @0x2c1784 movw r1, #0xffe
 *   @0x2c1788 cmp r6, r1
 *   @0x2c178c cmple r8, r3
 *   @0x2c1790 bge 0x2c17cc <jpeg_mem_term+0x394>
 *   @0x2c1794 cmp r3, #4096
 *   @0x2c1798 bge 0x2c1a08 <jpeg_mem_term+0x5d0>
 *   @0x2c179c add r1, r10, r6
 *   @0x2c17a0 b 0x2c17ac <jpeg_mem_term+0x374>
 *   @0x2c17a4 cmp r3, #4096
 *   @0x2c17a8 bge 0x2c1a08 <jpeg_mem_term+0x5d0>
 *   @0x2c17ac ldrb r0, [r11, r3]
 *   @0x2c17b0 add r6, r6, #1
 *   @0x2c17b4 strb r0, [r1], #1
 *   @0x2c17b8 movw r0, #0xffe
 *   @0x2c17bc ldr r3, [r4, r3, lsl #2]
 *   @0x2c17c0 cmp r6, r0
 *   @0x2c17c4 cmple r8, r3
 *   @0x2c17c8 blt 0x2c17a4 <jpeg_mem_term+0x36c>
 *   @0x2c17cc movw r1, #0xfff
 *   @0x2c17d0 movw r0, #0xffe
 *   @0x2c17d4 cmp r6, r0
 *   @0x2c17d8 cmple r3, r1
 *   @0x2c17dc bgt 0x2c1a08 <jpeg_mem_term+0x5d0>
 *   @0x2c17e0 cmn r6, #1
 *   @0x2c17e4 cmpne r9, r7
 *   @0x2c17e8 strb r3, [r10, r6]
 *   @0x2c17ec add r6, r6, #1
 *   @0x2c17f0 ble 0x2c1718 <jpeg_mem_term+0x2e0>
 *   @0x2c17f4 ldr r0, [sp, #0x14]
 *   @0x2c17f8 add r3, r0, r7
 *   @0x2c17fc sub r6, r6, #1
 *   @0x2c1800 add r7, r7, #1
 *   @0x2c1804 cmp r6, #0
 *   @0x2c1808 cmpne r9, r7
 *   @0x2c180c ldrb r1, [r10, r6]
 *   @0x2c1810 strb r1, [r3], #1
 *   @0x2c1814 bgt 0x2c17fc <jpeg_mem_term+0x3c4>
 *   @0x2c1818 b 0x2c1718 <jpeg_mem_term+0x2e0>
 *   @0x2c181c mov r0, #0
 *   @0x2c1820 add sp, sp, #44
 *   @0x2c1824 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2c1828 cmp r9, #0
 *   @0x2c182c ble 0x2c18bc <jpeg_mem_term+0x484>
 *   @0x2c1830 ldr r0, [sp, #0x14]
 *   @0x2c1834 add r2, r10, r6
 *   @0x2c1838 mov r7, #0
 *   @0x2c183c sub r3, r0, #1
 *   @0x2c1840 subs r6, r6, #1
 *   @0x2c1844 add r7, r7, #1
 *   @0x2c1848 ldrb r1, [r2, #-0x1]!
 *   @0x2c184c moveq r0, #0
 *   @0x2c1850 movne r0, #1
 *   @0x2c1854 cmp r9, r7
 *   @0x2c1858 movle r0, #0
 *   @0x2c185c andgt r0, r0, #1
 *   @0x2c1860 cmp r0, #0
 *   @0x2c1864 strb r1, [r3, #0x1]!
 *   @0x2c1868 bne 0x2c1840 <jpeg_mem_term+0x408>
 *   @0x2c186c b 0x2c16dc <jpeg_mem_term+0x2a4>
 *   @0x2c1870 mov r3, #0
 *   @0x2c1874 str r5, [r4, r3]
 *   @0x2c1878 add r3, r3, #4
 *   @0x2c187c cmp r3, #16384
 *   @0x2c1880 movw r2, #0x1002
 *   @0x2c1884 bne 0x2c1874 <jpeg_mem_term+0x43c>
 *   @0x2c1888 ldr r3, [r12, #0x8]
 *   @0x2c188c cmp r9, r7
 *   @0x2c1890 ldr r0, [r12, #0x10]
 *   @0x2c1894 mov r1, #1
 *   @0x2c1898 add r3, r3, r1
 *   @0x2c189c str r2, [r12, #0x20]
 *   @0x2c18a0 str r3, [r12, #0x18]
 *   @0x2c18a4 add r0, r0, r1
 *   @0x2c18a8 lsl r3, r1, r3
 *   @0x2c18ac str r0, [r12, #0x14]
 *   @0x2c18b0 str r3, [r12, #0x1c]
 *   @0x2c18b4 bgt 0x2c1740 <jpeg_mem_term+0x308>
 *   @0x2c18b8 mov r11, r2
 *   @0x2c18bc mov r0, #1
 *   @0x2c18c0 str r11, [r12, #0x20]
 *   @0x2c18c4 str r6, [r12, #0x28]
 *   @0x2c18c8 add sp, sp, #44
 *   @0x2c18cc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2c18d0 str r2, [r4, r3, lsl #2]
 *   @0x2c18d4 ldr r1, [r12, #0x14]
 *   @0x2c18d8 ldr r3, [sp, #0x24]
 *   @0x2c18dc sub r1, r1, #2
 *   @0x2c18e0 cmp r1, r3
 *   @0x2c18e4 beq 0x2c19ac <jpeg_mem_term+0x574>
 *   @0x2c18e8 cmp r8, r3
 *   @0x2c18ec bge 0x2c1920 <jpeg_mem_term+0x4e8>
 *   @0x2c18f0 cmp r3, #4096
 *   @0x2c18f4 bge 0x2c1918 <jpeg_mem_term+0x4e0>
 *   @0x2c18f8 mov r2, #4096
 *   @0x2c18fc ldr r3, [r4, r3, lsl #2]
 *   @0x2c1900 cmp r8, r3
 *   @0x2c1904 bge 0x2c1920 <jpeg_mem_term+0x4e8>
 *   @0x2c1908 subs r2, r2, #1
 *   @0x2c190c beq 0x2c1920 <jpeg_mem_term+0x4e8>
 *   @0x2c1910 cmp r3, #4096
 *   @0x2c1914 blt 0x2c18fc <jpeg_mem_term+0x4c4>
 *   @0x2c1918 mov r3, #2
 *   @0x2c191c b 0x2c1924 <jpeg_mem_term+0x4ec>
 *   @0x2c1920 uxtb r3, r3
 *   @0x2c1924 strb r3, [r11, r1]
 *   @0x2c1928 b 0x2c1734 <jpeg_mem_term+0x2fc>
 *   @0x2c192c ldr r1, [r12, #0x14]
 *   @0x2c1930 sub r1, r1, #2
 *   @0x2c1934 cmp r3, r1
 *   @0x2c1938 bne 0x2c1a1c <jpeg_mem_term+0x5e4>
 *   @0x2c193c cmp r8, r2
 *   @0x2c1940 add r1, r6, #1
 *   @0x2c1944 add r3, r11, r3
 *   @0x2c1948 str r1, [sp, #0x1c]
 *   @0x2c194c str r3, [sp, #0x18]
 *   @0x2c1950 add r0, r10, r6
 *   @0x2c1954 uxtbge r1, r2
 *   @0x2c1958 bge 0x2c1994 <jpeg_mem_term+0x55c>
 *   @0x2c195c cmp r2, #4096
 *   @0x2c1960 bge 0x2c1988 <jpeg_mem_term+0x550>
 *   @0x2c1964 mov r3, r2
 *   @0x2c1968 mov r1, #4096
 *   @0x2c196c ldr r3, [r4, r3, lsl #2]
 *   @0x2c1970 cmp r8, r3
 *   @0x2c1974 bge 0x2c1990 <jpeg_mem_term+0x558>
 *   @0x2c1978 subs r1, r1, #1
 *   @0x2c197c beq 0x2c1990 <jpeg_mem_term+0x558>
 *   @0x2c1980 cmp r3, #4096
 *   @0x2c1984 blt 0x2c196c <jpeg_mem_term+0x534>
 *   @0x2c1988 mov r1, #2
 *   @0x2c198c b 0x2c1994 <jpeg_mem_term+0x55c>
 *   @0x2c1990 uxtb r1, r3
 *   @0x2c1994 strb r1, [r0]
 *   @0x2c1998 mov r3, r2
 *   @0x2c199c ldr r0, [sp, #0x18]
 *   @0x2c19a0 ldr r6, [sp, #0x1c]
 *   @0x2c19a4 strb r1, [r0]
 *   @0x2c19a8 b 0x2c1784 <jpeg_mem_term+0x34c>
 *   @0x2c19ac cmp r8, r2
 *   @0x2c19b0 bge 0x2c19e4 <jpeg_mem_term+0x5ac>
 *   @0x2c19b4 cmp r2, #4096
 *   @0x2c19b8 bge 0x2c19dc <jpeg_mem_term+0x5a4>
 *   @0x2c19bc mov r3, #4096
 *   @0x2c19c0 ldr r2, [r4, r2, lsl #2]
 *   @0x2c19c4 cmp r8, r2
 *   @0x2c19c8 bge 0x2c19e4 <jpeg_mem_term+0x5ac>
 *   @0x2c19cc subs r3, r3, #1
 *   @0x2c19d0 beq 0x2c19e4 <jpeg_mem_term+0x5ac>
 *   @0x2c19d4 cmp r2, #4096
 *   @0x2c19d8 blt 0x2c19c0 <jpeg_mem_term+0x588>
 *   @0x2c19dc mov r2, #2
 *   @0x2c19e0 b 0x2c19e8 <jpeg_mem_term+0x5b0>
 *   @0x2c19e4 uxtb r2, r2
 *   @0x2c19e8 strb r2, [r11, r1]
 *   @0x2c19ec b 0x2c1734 <jpeg_mem_term+0x2fc>
 *   @0x2c19f0 ldr r1, [sp, #0x8]
 *   @0x2c19f4 mov r3, #113
 *   @0x2c19f8 mov r0, #0
 *   @0x2c19fc str r3, [r1, #0x40]
 *   @0x2c1a00 add sp, sp, #44
 *   @0x2c1a04 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2c1a08 ldr r1, [sp, #0x8]
 *   @0x2c1a0c mov r3, #112
 *   @0x2c1a10 mov r0, #0
 *   @0x2c1a14 str r3, [r1, #0x40]
 *   @0x2c1a18 b 0x2c1820 <jpeg_mem_term+0x3e8>
 *   @0x2c1a1c ldr r2, [sp, #0x8]
 *   @0x2c1a20 mov r3, #112
 *   @0x2c1a24 mov r0, #0
 *   @0x2c1a28 str r3, [r2, #0x40]
 *
 * ══ §8/21 JS_Array_prototype_splice(RValue&, CInstance*, CInstance*, int, RValue*)  0x250064  size 1516  379 条（0x250064..0x250650）
 * @func 0x250064 0x250650  size 1516  379 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65c8×8 / YYGetInt32(RValue const*, int)×5 / F_JS_Object_Get(YYObjectBase*, RValue*, char const*)×4 / JS_Object_Put(YYObjectBase*, RValue*, char const*, bool)×4 / JS_HasProperty(YYObjectBase*, char const*)×3 / FREE_RValue__Pre(RValue*)×3 / JS_DeleteProperty(YYObjectBase*, RValue*, char const*, bool)×3 / JS_Array_prototype_splice(RValue&, CInstance*, CInstance*, int, RValue*)+0x374×2
 * 字段偏移 top8: 0x10×9 / 0x18×9 / 0x14×7 / 0x20×7 / 0xc×7 / 0x60×6 / 0x5c×5 / 0x1c×4
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x250064 ldr r12, [pc, #0x5c4]
 *   @0x250068 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x25006c sub sp, sp, #172
 *   @0x250070 mov r4, #0
 *   @0x250074 mov r5, r1
 *   @0x250078 str r12, [sp, #0x1c]
 *   @0x25007c add r12, sp, #52
 *   @0x250080 str r12, [sp, #0x24]
 *   @0x250084 ldr r12, [sp, #0x1c]
 *   @0x250088 ldr lr, [sp, #0xd0]
 *   @0x25008c ldr r12, [pc, r12]
 *   @0x250090 str r12, [sp, #0x1c]
 *   @0x250094 str r3, [sp, #0x14]
 *   @0x250098 mov r3, r4
 *   @0x25009c ldr r12, [r12]
 *   @0x2500a0 str r4, [sp]
 *   @0x2500a4 str lr, [sp, #0x20]
 *   @0x2500a8 str r12, [sp, #0xa4]
 *   @0x2500ac str r0, [sp, #0x10]
 *   @0x2500b0 bl 0x242c84 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_>
 *   @0x2500b4 ldr r2, [pc, #0x578]
 *   @0x2500b8 mov r0, r5
 *   @0x2500bc add r1, sp, #52
 *   @0x2500c0 mvn r3, #-16777216
 *   @0x2500c4 add r2, pc, r2
 *   @0x2500c8 str r3, [sp, #0x40]
 *   @0x2500cc str r4, [sp, #0x34]
 *   @0x2500d0 str r4, [sp, #0x38]
 *   @0x2500d4 str r4, [sp, #0x3c]
 *   @0x2500d8 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x2500dc mov r1, r4
 *   @0x2500e0 add r0, sp, #52
 *   @0x2500e4 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x2500e8 mov r1, r4
 *   @0x2500ec str r0, [sp, #0x18]
 *   @0x2500f0 ldr r0, [sp, #0x20]
 *   @0x2500f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x2500f8 cmp r0, #0
 *   @0x2500fc blt 0x250608 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x5a4>
 *   @0x250100 ldr r2, [sp, #0x18]
 *   @0x250104 mov r3, #0
 *   @0x250108 mov r7, r3
 *   @0x25010c asr r3, r0, #31
 *   @0x250110 mov r6, r2
 *   @0x250114 mov r2, r0
 *   @0x250118 cmp r6, r2
 *   @0x25011c sbcs r12, r7, r3
 *   @0x250120 movlt r2, r6
 *   @0x250124 mov r4, r2
 *   @0x250128 ldr r0, [sp, #0x20]
 *   @0x25012c mov r1, #1
 *   @0x250130 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x250134 cmp r0, #0
 *   @0x250138 movle r0, #0
 *   @0x25013c ble 0x25014c <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0xe8>
 *   @0x250140 ldr r0, [sp, #0x20]
 *   @0x250144 mov r1, #1
 *   @0x250148 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x25014c ldr r12, [sp, #0x18]
 *   @0x250150 rsb r11, r4, r12
 *   @0x250154 cmp r0, r11
 *   @0x250158 blt 0x250498 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x434>
 *   @0x25015c cmp r11, #0
 *   @0x250160 beq 0x2504ac <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x448>
 *   @0x250164 ldr r6, [pc, #0x4cc]
 *   @0x250168 mov r10, #0
 *   @0x25016c add r12, sp, #132
 *   @0x250170 add r7, sp, #100
 *   @0x250174 add r6, pc, r6
 *   @0x250178 str r12, [sp, #0xc]
 *   @0x25017c add r9, sp, #84
 *   @0x250180 mov r8, r10
 *   @0x250184 b 0x250194 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x250188 add r10, r10, #1
 *   @0x25018c cmp r10, r11
 *   @0x250190 beq 0x250244 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x1e0>
 *   @0x250194 mov r1, #32
 *   @0x250198 mov r2, r6
 *   @0x25019c add r3, r10, r4
 *   @0x2501a0 mov r0, r7
 *   @0x2501a4 bl 0xb65c8 <snprintf@plt>
 *   @0x2501a8 mov r0, r5
 *   @0x2501ac mov r1, r7
 *   @0x2501b0 bl 0x241924 <_Z14JS_HasPropertyP12YYObjectBasePKc>
 *   @0x2501b4 cmp r0, #0
 *   @0x2501b8 beq 0x250188 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x2501bc mov r3, r10
 *   @0x2501c0 mov r1, #32
 *   @0x2501c4 mov r2, r6
 *   @0x2501c8 add r0, sp, #132
 *   @0x2501cc bl 0xb65c8 <snprintf@plt>
 *   @0x2501d0 mov r0, r5
 *   @0x2501d4 mov r1, r9
 *   @0x2501d8 mov r2, r7
 *   @0x2501dc mvn lr, #-16777216
 *   @0x2501e0 str r8, [sp, #0x54]
 *   @0x2501e4 str lr, [sp, #0x60]
 *   @0x2501e8 str r8, [sp, #0x58]
 *   @0x2501ec str r8, [sp, #0x5c]
 *   @0x2501f0 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x2501f4 ldr r12, [sp, #0x10]
 *   @0x2501f8 mov r3, #0
 *   @0x2501fc ldr lr, [sp, #0x5c]
 *   @0x250200 add r1, sp, #132
 *   @0x250204 mov r2, r9
 *   @0x250208 ldr r0, [r12]
 *   @0x25020c orr lr, lr, #7
 *   @0x250210 str lr, [sp, #0x5c]
 *   @0x250214 bl 0x248394 <_Z20JS_DefineOwnPropertyP12YYObjectBasePKcP6RValueb>
 *   @0x250218 ldr r3, [sp, #0x60]
 *   @0x25021c sub r3, r3, #1
 *   @0x250220 bic r3, r3, #-16777216
 *   @0x250224 bic r3, r3, #3
 *   @0x250228 cmp r3, #0
 *   @0x25022c bne 0x250188 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x250230 mov r0, r9
 *   @0x250234 add r10, r10, #1
 *   @0x250238 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x25023c cmp r10, r11
 *   @0x250240 bne 0x250194 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x250244 ldr r12, [sp, #0x14]
 *   @0x250248 mov r2, #0
 *   @0x25024c mvn r3, #-16777216
 *   @0x250250 str r2, [sp, #0x44]
 *   @0x250254 sub r12, r12, #2
 *   @0x250258 str r2, [sp, #0x48]
 *   @0x25025c cmp r11, r12
 *   @0x250260 str r12, [sp, #0x14]
 *   @0x250264 str r12, [sp, #0x10]
 *   @0x250268 str r2, [sp, #0x4c]
 *   @0x25026c str r3, [sp, #0x50]
 *   @0x250270 bls 0x2504d4 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x470>
 *   @0x250274 ldr r12, [sp, #0x18]
 *   @0x250278 rsb r12, r11, r12
 *   @0x25027c str r12, [sp, #0xc]
 *   @0x250280 cmp r4, r12
 *   @0x250284 bhs 0x250378 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x314>
 *   @0x250288 ldr r9, [pc, #0x3ac]
 *   @0x25028c add r12, sp, #68
 *   @0x250290 add r6, sp, #132
 *   @0x250294 str r12, [sp, #0x28]
 *   @0x250298 add r9, pc, r9
 *   @0x25029c mov r8, r4
 *   @0x2502a0 str r4, [sp, #0x2c]
 *   @0x2502a4 ldr r10, [sp, #0x14]
 *   @0x2502a8 b 0x250314 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x2b0>
 *   @0x2502ac add r4, sp, #84
 *   @0x2502b0 mov r0, r5
 *   @0x2502b4 mov r2, r7
 *   @0x2502b8 mov lr, #0
 *   @0x2502bc mov r1, r4
 *   @0x2502c0 mvn r3, #-16777216
 *   @0x2502c4 str lr, [sp, #0x54]
 *   @0x2502c8 str lr, [sp, #0x58]
 *   @0x2502cc str lr, [sp, #0x5c]
 *   @0x2502d0 str r3, [sp, #0x60]
 *   @0x2502d4 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x2502d8 mov r3, #0
 *   @0x2502dc mov r0, r5
 *   @0x2502e0 mov r1, r4
 *   @0x2502e4 mov r2, r6
 *   @0x2502e8 bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb>
 *   @0x2502ec ldr r3, [sp, #0x60]
 *   @0x2502f0 sub r3, r3, #1
 *   @0x2502f4 bic r3, r3, #-16777216
 *   @0x2502f8 bic r3, r3, #3
 *   @0x2502fc cmp r3, #0
 *   @0x250300 beq 0x2505f0 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x58c>
 *   @0x250304 ldr r12, [sp, #0xc]
 *   @0x250308 add r8, r8, #1
 *   @0x25030c cmp r8, r12
 *   @0x250310 bhs 0x250374 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x310>
 *   @0x250314 mov r1, #32
 *   @0x250318 mov r2, r9
 *   @0x25031c add r3, r8, r11
 *   @0x250320 mov r0, r7
 *   @0x250324 bl 0xb65c8 <snprintf@plt>
 *   @0x250328 mov r1, #32
 *   @0x25032c mov r2, r9
 *   @0x250330 add r3, r10, r8
 *   @0x250334 mov r0, r6
 *   @0x250338 bl 0xb65c8 <snprintf@plt>
 *   @0x25033c mov r0, r5
 *   @0x250340 mov r1, r7
 *   @0x250344 bl 0x241924 <_Z14JS_HasPropertyP12YYObjectBasePKc>
 *   @0x250348 cmp r0, #0
 *   @0x25034c bne 0x2502ac <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x248>
 *   @0x250350 mov r0, r5
 *   @0x250354 add r1, sp, #68
 *   @0x250358 mov r2, r6
 *   @0x25035c mov r3, #1
 *   @0x250360 bl 0x24edf4 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb>
 *   @0x250364 ldr r12, [sp, #0xc]
 *   @0x250368 add r8, r8, #1
 *   @0x25036c cmp r8, r12
 *   @0x250370 blo 0x250314 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x2b0>
 *   @0x250374 ldr r4, [sp, #0x2c]
 *   @0x250378 ldr r12, [sp, #0xc]
 *   @0x25037c ldr lr, [sp, #0x14]
 *   @0x250380 add r7, r12, lr
 *   @0x250384 ldr r12, [sp, #0x18]
 *   @0x250388 cmp r12, r7
 *   @0x25038c bls 0x2503d8 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x374>
 *   @0x250390 ldr r9, [pc, #0x2a8]
 *   @0x250394 add r6, sp, #132
 *   @0x250398 ldr r10, [sp, #0x18]
 *   @0x25039c add r8, sp, #68
 *   @0x2503a0 add r9, pc, r9
 *   @0x2503a4 sub r10, r10, #1
 *   @0x2503a8 mov r1, #32
 *   @0x2503ac mov r2, r9
 *   @0x2503b0 mov r0, r6
 *   @0x2503b4 mov r3, r10
 *   @0x2503b8 bl 0xb65c8 <snprintf@plt>
 *   @0x2503bc mov r0, r5
 *   @0x2503c0 mov r1, r8
 *   @0x2503c4 mov r2, r6
 *   @0x2503c8 mov r3, #1
 *   @0x2503cc bl 0x24edf4 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb>
 *   @0x2503d0 cmp r10, r7
 *   @0x2503d4 bhi 0x2503a4 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x340>
 *   @0x2503d8 ldr r12, [sp, #0x10]
 *   @0x2503dc cmp r12, #0
 *   @0x2503e0 beq 0x250438 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x3d4>
 *   @0x2503e4 ldr r12, [sp, #0x20]
 *   @0x2503e8 add r6, sp, #132
 *   @0x2503ec ldr r9, [pc, #0x250]
 *   @0x2503f0 add r7, r12, #32
 *   @0x2503f4 ldr r12, [sp, #0x10]
 *   @0x2503f8 add r9, pc, r9
 *   @0x2503fc add r8, r12, r4
 *   @0x250400 mov r3, r4
 *   @0x250404 mov r1, #32
 *   @0x250408 mov r2, r9
 *   @0x25040c mov r0, r6
 *   @0x250410 bl 0xb65c8 <snprintf@plt>
 *   @0x250414 add r4, r4, #1
 *   @0x250418 mov r1, r7
 *   @0x25041c mov r0, r5
 *   @0x250420 mov r2, r6
 *   @0x250424 mov r3, #0
 *   @0x250428 bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb>
 *   @0x25042c cmp r4, r8
 *   @0x250430 add r7, r7, #16
 *   @0x250434 bne 0x250400 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x39c>
 *   @0x250438 ldr r12, [sp, #0x10]
 *   @0x25043c mov r0, r5
 *   @0x250440 ldr lr, [sp, #0x18]
 *   @0x250444 add r1, sp, #52
 *   @0x250448 ldr r2, [pc, #0x1f8]
 *   @0x25044c add r4, r12, lr
 *   @0x250450 mov r12, #0
 *   @0x250454 rsb r4, r11, r4
 *   @0x250458 mov r3, r12
 *   @0x25045c add r2, pc, r2
 *   @0x250460 str r12, [sp, #0x40]
 *   @0x250464 vmov s15, r4
 *   @0x250468 vcvt.f64.u32 d7, s15
 *   @0x25046c vmov r4, r5, d7
 *   @0x250470 vstr s14, [sp, #52]
 *   @0x250474 str r5, [sp, #0x38]
 *   @0x250478 bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb>
 *   @0x25047c ldr r12, [sp, #0x1c]
 *   @0x250480 ldr r2, [sp, #0xa4]
 *   @0x250484 ldr r3, [r12]
 *   @0x250488 cmp r2, r3
 *   @0x25048c bne 0x25062c <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x5c8>
 *   @0x250490 add sp, sp, #172
 *   @0x250494 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x250498 ldr r0, [sp, #0x20]
 *   @0x25049c mov r1, #1
 *   @0x2504a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x2504a4 cmp r0, #0
 *   @0x2504a8 bgt 0x250618 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x5b4>
 *   @0x2504ac mov r3, #0
 *   @0x2504b0 ldr r12, [sp, #0x14]
 *   @0x2504b4 mov r11, r3
 *   @0x2504b8 mvn r2, #-16777216
 *   @0x2504bc sub r12, r12, #2
 *   @0x2504c0 str r3, [sp, #0x44]
 *   @0x2504c4 str r12, [sp, #0x10]
 *   @0x2504c8 str r3, [sp, #0x48]
 *   @0x2504cc str r3, [sp, #0x4c]
 *   @0x2504d0 str r2, [sp, #0x50]
 *   @0x2504d4 ldr r12, [sp, #0x10]
 *   @0x2504d8 cmp r12, r11
 *   @0x2504dc bls 0x2503d8 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x374>
 *   @0x2504e0 ldr r12, [sp, #0x18]
 *   @0x2504e4 rsb r8, r11, r12
 *   @0x2504e8 cmp r4, r8
 *   @0x2504ec bhs 0x2503d8 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x374>
 *   @0x2504f0 ldr r9, [pc, #0x154]
 *   @0x2504f4 sub r12, r11, #1
 *   @0x2504f8 ldr lr, [sp, #0x10]
 *   @0x2504fc add r1, sp, #68
 *   @0x250500 str r11, [sp, #0x28]
 *   @0x250504 add r9, pc, r9
 *   @0x250508 sub lr, lr, #1
 *   @0x25050c add r7, sp, #100
 *   @0x250510 str lr, [sp, #0xc]
 *   @0x250514 add r6, sp, #132
 *   @0x250518 str r1, [sp, #0x14]
 *   @0x25051c mov r11, r12
 *   @0x250520 b 0x250588 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x524>
 *   @0x250524 add r10, sp, #84
 *   @0x250528 mov r0, r5
 *   @0x25052c mov r2, r7
 *   @0x250530 mov lr, #0
 *   @0x250534 mov r1, r10
 *   @0x250538 mvn r3, #-16777216
 *   @0x25053c str lr, [sp, #0x54]
 *   @0x250540 str lr, [sp, #0x58]
 *   @0x250544 str lr, [sp, #0x5c]
 *   @0x250548 str r3, [sp, #0x60]
 *   @0x25054c bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x250550 mov r3, #0
 *   @0x250554 mov r0, r5
 *   @0x250558 mov r1, r10
 *   @0x25055c mov r2, r6
 *   @0x250560 bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb>
 *   @0x250564 ldr r3, [sp, #0x60]
 *   @0x250568 sub r3, r3, #1
 *   @0x25056c bic r3, r3, #-16777216
 *   @0x250570 bic r3, r3, #3
 *   @0x250574 cmp r3, #0
 *   @0x250578 beq 0x2505fc <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x598>
 *   @0x25057c sub r8, r8, #1
 *   @0x250580 cmp r4, r8
 *   @0x250584 bhs 0x2505e8 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x584>
 *   @0x250588 mov r1, #32
 *   @0x25058c mov r2, r9
 *   @0x250590 add r3, r11, r8
 *   @0x250594 mov r0, r7
 *   @0x250598 bl 0xb65c8 <snprintf@plt>
 *   @0x25059c ldr r12, [sp, #0xc]
 *   @0x2505a0 mov r1, #32
 *   @0x2505a4 mov r2, r9
 *   @0x2505a8 add r3, r12, r8
 *   @0x2505ac mov r0, r6
 *   @0x2505b0 bl 0xb65c8 <snprintf@plt>
 *   @0x2505b4 mov r0, r5
 *   @0x2505b8 mov r1, r7
 *   @0x2505bc bl 0x241924 <_Z14JS_HasPropertyP12YYObjectBasePKc>
 *   @0x2505c0 cmp r0, #0
 *   @0x2505c4 bne 0x250524 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x4c0>
 *   @0x2505c8 mov r0, r5
 *   @0x2505cc add r1, sp, #68
 *   @0x2505d0 mov r2, r6
 *   @0x2505d4 mov r3, #1
 *   @0x2505d8 sub r8, r8, #1
 *   @0x2505dc bl 0x24edf4 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb>
 *   @0x2505e0 cmp r4, r8
 *   @0x2505e4 blo 0x250588 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x524>
 *   @0x2505e8 ldr r11, [sp, #0x28]
 *   @0x2505ec b 0x2503d8 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x374>
 *   @0x2505f0 mov r0, r4
 *   @0x2505f4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x2505f8 b 0x250304 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x2a0>
 *   @0x2505fc mov r0, r10
 *   @0x250600 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x250604 b 0x25057c <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x518>
 *   @0x250608 ldr r12, [sp, #0x18]
 *   @0x25060c add r0, r0, r12
 *   @0x250610 bic r4, r0, r0, asr #31
 *   @0x250614 b 0x250128 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0xc4>
 *   @0x250618 ldr r0, [sp, #0x20]
 *   @0x25061c mov r1, #1
 *   @0x250620 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x250624 mov r11, r0
 *   @0x250628 b 0x25015c <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0xf8>
 *   @0x25062c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x250630 andseq sp, r9, r4, asr #17
 *   @0x250634 andeq r0, lr, r8, lsr #15
 *   @0x250638 andseq r5, r0, r12, ror #25
 *   @0x25063c andseq r5, r0, r8, asr #23
 *   @0x250640 andseq r5, r0, r0, asr #21
 *   @0x250644 andseq r5, r0, r8, ror #20
 *   @0x250648 andeq r0, lr, r0, lsl r4
 *   @0x25064c andseq r5, r0, r12, asr r9
 *
 * ══ §9/21 JS_StringSetup()  0x24269c  size 1512  378 条（0x24269c..0x242c84）
 * @func 0x24269c 0x242c84  size 1512  378 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYObjectBase::Add(char const*, YYObjectBase*, int)×22 / JS_SetupFunction(void (*)(RValue&, CInstance*, CInstance*, int, RValue*), int, bool)×21 / YYObjectBase::InternalGetYYVar(int)×3 / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)×2 / JS_StandardBuiltInObjectConstructor(RValue&, CInstance*, CInstance*, int, RValue*) / YYObjectBase::Add(char const*, int, int) / YYCreateString(RValue*, char const*) / YYObjectBase::Add(char const*, void*, int)
 * 字段偏移 top8: 0x4×3 / 0x8×2 / 0x18×2 / 0x28×2 / 0x170×2 / 0x4e8×1 / 0x14×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24269c push {r4, r5, r6, r7, r8, lr}
 *   @0x2426a0 sub sp, sp, #40
 *   @0x2426a4 mov r6, #0
 *   @0x2426a8 add r0, sp, #8
 *   @0x2426ac mov r1, r6
 *   @0x2426b0 mov r2, r6
 *   @0x2426b4 mov r3, r6
 *   @0x2426b8 mov r4, #0
 *   @0x2426bc mov r5, #0
 *   @0x2426c0 str r6, [sp]
 *   @0x2426c4 strd r4, r5, [sp, #8]
 *   @0x2426c8 mvn r12, #-16777216
 *   @0x2426cc ldr r5, [pc, #0x4e8]
 *   @0x2426d0 str r12, [sp, #0x14]
 *   @0x2426d4 str r6, [sp, #0x10]
 *   @0x2426d8 bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_>
 *   @0x2426dc ldr r3, [pc, #0x4dc]
 *   @0x2426e0 add r5, pc, r5
 *   @0x2426e4 ldr r4, [sp, #0x8]
 *   @0x2426e8 ldr r2, [pc, #0x4d4]
 *   @0x2426ec ldr r8, [r5, r3]
 *   @0x2426f0 ldr r3, [pc, #0x4d0]
 *   @0x2426f4 add r2, pc, r2
 *   @0x2426f8 str r2, [r4, #0x40]
 *   @0x2426fc mov r0, r4
 *   @0x242700 str r4, [r8]
 *   @0x242704 ldr r3, [r5, r3]
 *   @0x242708 ldr r1, [r3]
 *   @0x24270c str r1, [r4, #0x18]
 *   @0x242710 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x242714 ldr r3, [pc, #0x4b0]
 *   @0x242718 ldr r0, [r4, #0x28]
 *   @0x24271c mov r1, r6
 *   @0x242720 mov r2, r6
 *   @0x242724 orr r0, r0, #1
 *   @0x242728 str r0, [r4, #0x28]
 *   @0x24272c ldr r7, [r5, r3]
 *   @0x242730 mov r0, r7
 *   @0x242734 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x242738 ldr r1, [pc, #0x490]
 *   @0x24273c mov r3, #6
 *   @0x242740 add r1, pc, r1
 *   @0x242744 mov r2, r0
 *   @0x242748 mov r0, r4
 *   @0x24274c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x242750 mov r0, r7
 *   @0x242754 mov r1, r6
 *   @0x242758 mov r2, r6
 *   @0x24275c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x242760 ldr r1, [pc, #0x46c]
 *   @0x242764 mov r3, #6
 *   @0x242768 add r1, pc, r1
 *   @0x24276c mov r2, r0
 *   @0x242770 mov r0, r4
 *   @0x242774 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x242778 ldr r3, [pc, #0x458]
 *   @0x24277c mov r2, r6
 *   @0x242780 mov r1, #1
 *   @0x242784 ldr r0, [r5, r3]
 *   @0x242788 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x24278c ldr r1, [pc, #0x448]
 *   @0x242790 mov r3, #6
 *   @0x242794 add r1, pc, r1
 *   @0x242798 mov r2, r0
 *   @0x24279c mov r0, r4
 *   @0x2427a0 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2427a4 ldr r3, [pc, #0x434]
 *   @0x2427a8 mov r2, r6
 *   @0x2427ac mov r1, #1
 *   @0x2427b0 ldr r0, [r5, r3]
 *   @0x2427b4 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2427b8 ldr r1, [pc, #0x424]
 *   @0x2427bc mov r3, #6
 *   @0x2427c0 add r1, pc, r1
 *   @0x2427c4 mov r2, r0
 *   @0x2427c8 mov r0, r4
 *   @0x2427cc bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2427d0 ldr r3, [pc, #0x410]
 *   @0x2427d4 mov r2, r6
 *   @0x2427d8 mov r1, #1
 *   @0x2427dc ldr r0, [r5, r3]
 *   @0x2427e0 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2427e4 ldr r1, [pc, #0x400]
 *   @0x2427e8 mov r3, #6
 *   @0x2427ec add r1, pc, r1
 *   @0x2427f0 mov r2, r0
 *   @0x2427f4 mov r0, r4
 *   @0x2427f8 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2427fc ldr r3, [pc, #0x3ec]
 *   @0x242800 mov r2, r6
 *   @0x242804 mov r1, #1
 *   @0x242808 ldr r0, [r5, r3]
 *   @0x24280c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x242810 ldr r1, [pc, #0x3dc]
 *   @0x242814 mov r3, #6
 *   @0x242818 add r1, pc, r1
 *   @0x24281c mov r2, r0
 *   @0x242820 mov r0, r4
 *   @0x242824 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x242828 ldr r3, [pc, #0x3c8]
 *   @0x24282c mov r2, r6
 *   @0x242830 mov r1, #1
 *   @0x242834 ldr r0, [r5, r3]
 *   @0x242838 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x24283c ldr r1, [pc, #0x3b8]
 *   @0x242840 mov r3, #6
 *   @0x242844 add r1, pc, r1
 *   @0x242848 mov r2, r0
 *   @0x24284c mov r0, r4
 *   @0x242850 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x242854 ldr r3, [pc, #0x3a4]
 *   @0x242858 mov r2, r6
 *   @0x24285c mov r1, #1
 *   @0x242860 ldr r0, [r5, r3]
 *   @0x242864 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x242868 ldr r1, [pc, #0x394]
 *   @0x24286c mov r3, #6
 *   @0x242870 add r1, pc, r1
 *   @0x242874 mov r2, r0
 *   @0x242878 mov r0, r4
 *   @0x24287c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x242880 ldr r3, [pc, #0x380]
 *   @0x242884 mov r2, r6
 *   @0x242888 mov r1, #1
 *   @0x24288c ldr r0, [r5, r3]
 *   @0x242890 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x242894 ldr r1, [pc, #0x370]
 *   @0x242898 mov r3, #6
 *   @0x24289c add r1, pc, r1
 *   @0x2428a0 mov r2, r0
 *   @0x2428a4 mov r0, r4
 *   @0x2428a8 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2428ac ldr r3, [pc, #0x35c]
 *   @0x2428b0 mov r2, r6
 *   @0x2428b4 mov r1, #2
 *   @0x2428b8 ldr r0, [r5, r3]
 *   @0x2428bc bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2428c0 ldr r1, [pc, #0x34c]
 *   @0x2428c4 mov r3, #6
 *   @0x2428c8 add r1, pc, r1
 *   @0x2428cc mov r2, r0
 *   @0x2428d0 mov r0, r4
 *   @0x2428d4 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2428d8 ldr r3, [pc, #0x338]
 *   @0x2428dc mov r2, r6
 *   @0x2428e0 mov r1, #1
 *   @0x2428e4 ldr r0, [r5, r3]
 *   @0x2428e8 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2428ec ldr r1, [pc, #0x328]
 *   @0x2428f0 mov r3, #6
 *   @0x2428f4 add r1, pc, r1
 *   @0x2428f8 mov r2, r0
 *   @0x2428fc mov r0, r4
 *   @0x242900 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x242904 ldr r3, [pc, #0x314]
 *   @0x242908 mov r2, r6
 *   @0x24290c mov r1, #2
 *   @0x242910 ldr r0, [r5, r3]
 *   @0x242914 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x242918 ldr r1, [pc, #0x304]
 *   @0x24291c mov r3, #6
 *   @0x242920 add r1, pc, r1
 *   @0x242924 mov r2, r0
 *   @0x242928 mov r0, r4
 *   @0x24292c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x242930 ldr r3, [pc, #0x2f0]
 *   @0x242934 mov r2, r6
 *   @0x242938 mov r1, #2
 *   @0x24293c ldr r0, [r5, r3]
 *   @0x242940 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x242944 ldr r1, [pc, #0x2e0]
 *   @0x242948 mov r3, #6
 *   @0x24294c add r1, pc, r1
 *   @0x242950 mov r2, r0
 *   @0x242954 mov r0, r4
 *   @0x242958 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x24295c ldr r3, [pc, #0x2cc]
 *   @0x242960 mov r2, r6
 *   @0x242964 mov r1, #2
 *   @0x242968 ldr r0, [r5, r3]
 *   @0x24296c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x242970 ldr r1, [pc, #0x2bc]
 *   @0x242974 mov r3, #6
 *   @0x242978 add r1, pc, r1
 *   @0x24297c mov r2, r0
 *   @0x242980 mov r0, r4
 *   @0x242984 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x242988 ldr r3, [pc, #0x2a8]
 *   @0x24298c mov r1, r6
 *   @0x242990 mov r2, r6
 *   @0x242994 ldr r0, [r5, r3]
 *   @0x242998 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x24299c ldr r1, [pc, #0x298]
 *   @0x2429a0 mov r3, #6
 *   @0x2429a4 add r1, pc, r1
 *   @0x2429a8 mov r2, r0
 *   @0x2429ac mov r0, r4
 *   @0x2429b0 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2429b4 ldr r3, [pc, #0x284]
 *   @0x2429b8 mov r1, r6
 *   @0x2429bc mov r2, r6
 *   @0x2429c0 ldr r7, [r5, r3]
 *   @0x2429c4 mov r0, r7
 *   @0x2429c8 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2429cc ldr r1, [pc, #0x270]
 *   @0x2429d0 mov r3, #6
 *   @0x2429d4 add r1, pc, r1
 *   @0x2429d8 mov r2, r0
 *   @0x2429dc mov r0, r4
 *   @0x2429e0 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2429e4 ldr r3, [pc, #0x25c]
 *   @0x2429e8 mov r1, r6
 *   @0x2429ec mov r2, r6
 *   @0x2429f0 ldr r0, [r5, r3]
 *   @0x2429f4 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2429f8 ldr r1, [pc, #0x24c]
 *   @0x2429fc mov r3, #6
 *   @0x242a00 add r1, pc, r1
 *   @0x242a04 mov r2, r0
 *   @0x242a08 mov r0, r4
 *   @0x242a0c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x242a10 mov r0, r7
 *   @0x242a14 mov r1, r6
 *   @0x242a18 mov r2, r6
 *   @0x242a1c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x242a20 ldr r1, [pc, #0x228]
 *   @0x242a24 mov r3, #6
 *   @0x242a28 add r7, sp, #24
 *   @0x242a2c add r1, pc, r1
 *   @0x242a30 mov r2, r0
 *   @0x242a34 mov r0, r4
 *   @0x242a38 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x242a3c ldr r3, [pc, #0x210]
 *   @0x242a40 mov r1, r6
 *   @0x242a44 mov r2, r6
 *   @0x242a48 ldr r0, [r5, r3]
 *   @0x242a4c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x242a50 ldr r1, [pc, #0x200]
 *   @0x242a54 mov r3, #6
 *   @0x242a58 add r1, pc, r1
 *   @0x242a5c mov r2, r0
 *   @0x242a60 mov r0, r4
 *   @0x242a64 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x242a68 ldr r1, [pc, #0x1ec]
 *   @0x242a6c mov r2, r6
 *   @0x242a70 mov r3, r6
 *   @0x242a74 mov r0, r4
 *   @0x242a78 add r1, pc, r1
 *   @0x242a7c bl 0x199960 <_ZN12YYObjectBase3AddEPKcii>
 *   @0x242a80 ldr r1, [pc, #0x1d8]
 *   @0x242a84 mov r0, r7
 *   @0x242a88 str r6, [sp, #0x18]
 *   @0x242a8c add r1, pc, r1
 *   @0x242a90 str r6, [sp, #0x1c]
 *   @0x242a94 str r6, [sp, #0x20]
 *   @0x242a98 str r6, [sp, #0x24]
 *   @0x242a9c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x242aa0 ldr r1, [pc, #0x1bc]
 *   @0x242aa4 mov r2, r7
 *   @0x242aa8 mov r0, r4
 *   @0x242aac mov r3, r6
 *   @0x242ab0 add r1, pc, r1
 *   @0x242ab4 bl 0x199b20 <_ZN12YYObjectBase3AddEPKcPvi>
 *   @0x242ab8 ldr r3, [pc, #0x1a8]
 *   @0x242abc mov r2, r6
 *   @0x242ac0 mov r1, #1
 *   @0x242ac4 ldr r0, [r5, r3]
 *   @0x242ac8 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x242acc ldr r3, [pc, #0x198]
 *   @0x242ad0 mov r2, r6
 *   @0x242ad4 mov r1, #1
 *   @0x242ad8 mov r7, r0
 *   @0x242adc ldr r0, [r5, r3]
 *   @0x242ae0 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x242ae4 ldr r1, [pc, #0x184]
 *   @0x242ae8 mov r3, r6
 *   @0x242aec add r1, pc, r1
 *   @0x242af0 mov r2, r0
 *   @0x242af4 mov r0, r7
 *   @0x242af8 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x242afc ldr r12, [pc, #0x170]
 *   @0x242b00 ldr r1, [pc, #0x170]
 *   @0x242b04 mov r3, r6
 *   @0x242b08 mov r0, r4
 *   @0x242b0c mov r2, r7
 *   @0x242b10 ldr r12, [r5, r12]
 *   @0x242b14 add r1, pc, r1
 *   @0x242b18 str r12, [r7, #0x94]
 *   @0x242b1c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x242b20 ldr r3, [r7, #0x4]
 *   @0x242b24 cmp r3, r6
 *   @0x242b28 beq 0x242b7c <_Z14JS_StringSetupv+0x4e0>
 *   @0x242b2c ldr r1, [r8]
 *   @0x242b30 mov r0, r7
 *   @0x242b34 str r1, [r3]
 *   @0x242b38 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x242b3c ldr r1, [r7, #0x4]
 *   @0x242b40 cmp r1, #0
 *   @0x242b44 movne r3, #6
 *   @0x242b48 strne r3, [r1, #0xc]
 *   @0x242b4c beq 0x242b90 <_Z14JS_StringSetupv+0x4f4>
 *   @0x242b50 ldr r0, [pc, #0x124]
 *   @0x242b54 mov r3, #0
 *   @0x242b58 str r3, [r1, #0x8]
 *   @0x242b5c mov r2, r7
 *   @0x242b60 ldr r1, [pc, #0x118]
 *   @0x242b64 ldr r0, [r5, r0]
 *   @0x242b68 add r1, pc, r1
 *   @0x242b6c ldr r0, [r0]
 *   @0x242b70 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x242b74 add sp, sp, #40
 *   @0x242b78 pop {r4, r5, r6, r7, r8, pc}
 *   @0x242b7c mov r1, r3
 *   @0x242b80 mov r0, r7
 *   @0x242b84 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x242b88 mov r3, r0
 *   @0x242b8c b 0x242b2c <_Z14JS_StringSetupv+0x490>
 *   @0x242b90 mov r0, r7
 *   @0x242b94 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x242b98 ldr r1, [r7, #0x4]
 *   @0x242b9c mov r3, #6
 *   @0x242ba0 cmp r1, #0
 *   @0x242ba4 str r3, [r0, #0xc]
 *   @0x242ba8 bne 0x242b50 <_Z14JS_StringSetupv+0x4b4>
 *   @0x242bac mov r0, r7
 *   @0x242bb0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x242bb4 mov r1, r0
 *   @0x242bb8 b 0x242b50 <_Z14JS_StringSetupv+0x4b4>
 *   @0x242bbc andseq pc, r10, r0, ror r5
 *   @0x242bc0 .word 0xfffff960
 *   @0x242bc4 andseq r3, r1, r4, rrx
 *   @0x242bc8 .word 0xffffc050
 *   @0x242bcc .word 0xfffff964
 *   @0x242bd0 .word 0x000efdd0
 *   @0x242bd4 ldrsheq r2, [r1], -r0
 *   @0x242bd8 .word 0xfffff968
 *   @0x242bdc ldrsbeq r2, [r1], -r0
 *   @0x242be0 .word 0xfffff96c
 *   @0x242be4 andseq r2, r1, r12, lsr #31
 *   @0x242be8 .word 0xfffff970
 *   @0x242bec andseq r2, r1, r12, lsl #31
 *   @0x242bf0 .word 0xfffff974
 *   @0x242bf4 andseq r2, r1, r8, ror #30
 *   @0x242bf8 .word 0xfffff978
 *   @0x242bfc andseq r2, r1, r4, asr #30
 *   @0x242c00 .word 0xfffff97c
 *   @0x242c04 andseq r2, r1, r4, lsr #30
 *   @0x242c08 .word 0xfffff980
 *   @0x242c0c andseq r2, r1, r8, lsl #30
 *   @0x242c10 .word 0xfffff984
 *   @0x242c14 andseq r2, r1, r4, ror #29
 *   @0x242c18 .word 0xfffff988
 *   @0x242c1c andseq r2, r1, r0, asr #29
 *   @0x242c20 .word 0xfffff98c
 *   @0x242c24 mulseq r1, r12, lr
 *   @0x242c28 .word 0xfffff990
 *   @0x242c2c andseq r2, r1, r8, ror lr
 *   @0x242c30 .word 0xfffff994
 *   @0x242c34 andseq r2, r1, r4, asr lr
 *   @0x242c38 .word 0xfffff998
 *   @0x242c3c andseq r2, r1, r4, lsr lr
 *   @0x242c40 .word 0xfffff8ec
 *   @0x242c44 andseq r2, r1, r0, lsl lr
 *   @0x242c48 .word 0xfffff99c
 *   @0x242c4c ldrsheq r2, [r1], -r8
 *   @0x242c50 ldrsbeq r2, [r1], -r8
 *   @0x242c54 .word 0xfffff9a0
 *   @0x242c58 andseq r2, r1, r0, asr #27
 *   @0x242c5c strdeq sp, lr, [lr], -r4
 *   @0x242c60 andeq r12, lr, r10, lsr #1
 *   @0x242c64 andseq r2, r1, r0, ror #20
 *   @0x242c68 .word 0xfffff9a4
 *   @0x242c6c .word 0xfffff9a8
 *   @0x242c70 andseq r2, r1, r4, lsr sp
 *   @0x242c74 .word 0xfffff9ac
 *   @0x242c78 andseq r2, r1, r0, lsl r10
 *   @0x242c7c .word 0xffffbf64
 *   @0x242c80 andseq r2, r1, r8, asr #25
 *
 * ══ §10/21 TestForNewRotates(long long)  0x1d81dc  size 1504  376 条（0x1d81dc..0x1d87bc）
 * @func 0x1d81dc 0x1d87bc  size 1504  376 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1d81f0→0x544a90, 0x1d8204→0x3f5134, 0x1d8290→0x544aa8, 0x1d841c→0x3f5138, 0x1d8654→0x3ebe20
 * 调用序列: TestForNewRotates(long long)+0x124 / TestForNewRotates(long long)+0x430 / TestForNewRotates(long long)+0x374 / 0xb6760 / TestForNewRotates(long long)+0x184 / operator new(unsigned int) / CGesture::CGesture() / MemoryManager::Alloc(unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x8×18 / 0x28×8 / 0x4×7 / 0x828×6 / 0x82c×6 / 0xc×6 / 0x18×5 / 0x38×4
 * VFP 指令 55 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d81dc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1d81e0 vpush {d8, d9, d10, d11, d12}
 *   @0x1d81e4 sub sp, sp, #68
 *   @0x1d81e8 vldr s15, [pc, #448]
 *   @0x1d81ec ldr r6, [pc, #0x1c8]
 *   @0x1d81f0 ldr r3, [pc, #0x1c8]
 *   @0x1d81f4 add r6, pc, r6
 *   @0x1d81f8 strd r0, r1, [sp, #48]
 *   @0x1d81fc str r6, [sp, #0x38]
 *   @0x1d8200 ldr r3, [r6, r3]
 *   @0x1d8204 ldr r2, [pc, #0x1b8]
 *   @0x1d8208 ldr r3, [r3]
 *   @0x1d820c ldr r2, [r6, r2]
 *   @0x1d8210 vldr s23, [r2]
 *   @0x1d8214 cmp r3, #0
 *   @0x1d8218 vmul.f32 s23, s23, s15
 *   @0x1d821c str r3, [sp, #0x28]
 *   @0x1d8220 beq 0x1d83a4 <_Z17TestForNewRotatesx+0x1c8>
 *   @0x1d8224 ldr r3, [r3, #0x8]
 *   @0x1d8228 cmp r3, #0
 *   @0x1d822c beq 0x1d83a4 <_Z17TestForNewRotatesx+0x1c8>
 *   @0x1d8230 ldr r7, [pc, #0x190]
 *   @0x1d8234 vldr s22, [pc, #412]
 *   @0x1d8238 vldr s20, [pc, #372]
 *   @0x1d823c vldr s21, [pc, #372]
 *   @0x1d8240 add r7, pc, r7
 *   @0x1d8244 str r7, [sp, #0x3c]
 *   @0x1d8248 ldr r8, [sp, #0x28]
 *   @0x1d824c ldr r11, [r8, #0x8]
 *   @0x1d8250 ldrb r3, [r11, #0x830]
 *   @0x1d8254 cmp r3, #0
 *   @0x1d8258 bne 0x1d8380 <_Z17TestForNewRotatesx+0x1a4>
 *   @0x1d825c ldr r12, [sp, #0x28]
 *   @0x1d8260 ldr r12, [r12]
 *   @0x1d8264 cmp r12, #0
 *   @0x1d8268 str r12, [sp, #0x18]
 *   @0x1d826c beq 0x1d83a4 <_Z17TestForNewRotatesx+0x1c8>
 *   @0x1d8270 ldr r3, [r12, #0x8]
 *   @0x1d8274 cmp r3, #0
 *   @0x1d8278 beq 0x1d87b0 <_Z17TestForNewRotatesx+0x5d4>
 *   @0x1d827c ldr r6, [sp, #0x18]
 *   @0x1d8280 ldr r8, [r6, #0x8]
 *   @0x1d8284 ldrb r3, [r8, #0x830]
 *   @0x1d8288 cmp r3, #0
 *   @0x1d828c bne 0x1d8360 <_Z17TestForNewRotatesx+0x184>
 *   @0x1d8290 ldr r3, [pc, #0x134]
 *   @0x1d8294 ldr r7, [sp, #0x38]
 *   @0x1d8298 ldr r3, [r7, r3]
 *   @0x1d829c ldr r5, [r3]
 *   @0x1d82a0 str r3, [sp, #0x2c]
 *   @0x1d82a4 cmp r5, #0
 *   @0x1d82a8 bne 0x1d830c <_Z17TestForNewRotatesx+0x130>
 *   @0x1d82ac b 0x1d83dc <_Z17TestForNewRotatesx+0x200>
 *   @0x1d82b0 ldr r3, [r4]
 *   @0x1d82b4 mov r0, r4
 *   @0x1d82b8 ldr r3, [r3, #0x14]
 *   @0x1d82bc blx r3
 *   @0x1d82c0 cmp r0, #1
 *   @0x1d82c4 mov r0, r4
 *   @0x1d82c8 ble 0x1d8300 <_Z17TestForNewRotatesx+0x124>
 *   @0x1d82cc ldr r3, [r4]
 *   @0x1d82d0 ldr r1, [r11, #0x4]
 *   @0x1d82d4 ldr r3, [r3, #0x10]
 *   @0x1d82d8 blx r3
 *   @0x1d82dc ldr r3, [r4]
 *   @0x1d82e0 ldr r1, [r8, #0x4]
 *   @0x1d82e4 ldr r3, [r3, #0x10]
 *   @0x1d82e8 mov r6, r0
 *   @0x1d82ec mov r0, r4
 *   @0x1d82f0 blx r3
 *   @0x1d82f4 eor r0, r0, r6
 *   @0x1d82f8 tst r0, #255
 *   @0x1d82fc bne 0x1d8360 <_Z17TestForNewRotatesx+0x184>
 *   @0x1d8300 ldr r5, [r5]
 *   @0x1d8304 cmp r5, #0
 *   @0x1d8308 beq 0x1d83dc <_Z17TestForNewRotatesx+0x200>
 *   @0x1d830c ldr r3, [r5, #0x8]
 *   @0x1d8310 cmp r3, #0
 *   @0x1d8314 beq 0x1d83dc <_Z17TestForNewRotatesx+0x200>
 *   @0x1d8318 ldr r4, [r5, #0x8]
 *   @0x1d831c ldr r3, [r4, #0x8]
 *   @0x1d8320 cmp r3, #5
 *   @0x1d8324 bne 0x1d82b0 <_Z17TestForNewRotatesx+0xd4>
 *   @0x1d8328 ldr r3, [r4]
 *   @0x1d832c mov r0, r4
 *   @0x1d8330 ldr r1, [r11, #0x4]
 *   @0x1d8334 ldr r3, [r3, #0x10]
 *   @0x1d8338 blx r3
 *   @0x1d833c cmp r0, #0
 *   @0x1d8340 beq 0x1d82b0 <_Z17TestForNewRotatesx+0xd4>
 *   @0x1d8344 ldr r3, [r4]
 *   @0x1d8348 mov r0, r4
 *   @0x1d834c ldr r1, [r8, #0x4]
 *   @0x1d8350 ldr r3, [r3, #0x10]
 *   @0x1d8354 blx r3
 *   @0x1d8358 cmp r0, #0
 *   @0x1d835c beq 0x1d82b0 <_Z17TestForNewRotatesx+0xd4>
 *   @0x1d8360 ldr r9, [sp, #0x18]
 *   @0x1d8364 ldr r9, [r9]
 *   @0x1d8368 cmp r9, #0
 *   @0x1d836c str r9, [sp, #0x18]
 *   @0x1d8370 beq 0x1d8380 <_Z17TestForNewRotatesx+0x1a4>
 *   @0x1d8374 ldr r3, [r9, #0x8]
 *   @0x1d8378 cmp r3, #0
 *   @0x1d837c bne 0x1d827c <_Z17TestForNewRotatesx+0xa0>
 *   @0x1d8380 ldr r9, [sp, #0x28]
 *   @0x1d8384 ldr r9, [r9]
 *   @0x1d8388 cmp r9, #0
 *   @0x1d838c str r9, [sp, #0x28]
 *   @0x1d8390 beq 0x1d83a4 <_Z17TestForNewRotatesx+0x1c8>
 *   @0x1d8394 ldr r12, [sp, #0x28]
 *   @0x1d8398 ldr r3, [r12, #0x8]
 *   @0x1d839c cmp r3, #0
 *   @0x1d83a0 bne 0x1d8248 <_Z17TestForNewRotatesx+0x6c>
 *   @0x1d83a4 add sp, sp, #68
 *   @0x1d83a8 vpop {d8, d9, d10, d11, d12}
 *   @0x1d83ac pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1d83b0 vstmialo lr, {s30, s31}
 *   @0x1d83b4 ldrdmi r0, r1, [r9], #-251
 *   @0x1d83b8 ldrdmi r0, r1, [r9], #251
 *   @0x1d83bc eoreq r9, r1, r12, asr r10
 *   @0x1d83c0 .word 0xffffefb4
 *   @0x1d83c4 .word 0xffffef98
 *   @0x1d83c8 ldrsheq r4, [r7], -r0
 *   @0x1d83cc .word 0xffffefc4
 *   @0x1d83d0 .word 0xffffef94
 *   @0x1d83d4 .word 0xffffefac
 *   @0x1d83d8 andeq r0, r0, r0
 *   @0x1d83dc ldr r12, [r11, #0x828]
 *   @0x1d83e0 ldr r6, [r11, #0x82c]
 *   @0x1d83e4 cmp r12, r6
 *   @0x1d83e8 beq 0x1d8798 <_Z17TestForNewRotatesx+0x5bc>
 *   @0x1d83ec add r4, r12, #63
 *   @0x1d83f0 and r4, r4, #63
 *   @0x1d83f4 add r4, r11, r4, lsl #5
 *   @0x1d83f8 add r4, r4, #40
 *   @0x1d83fc ldr r9, [r8, #0x82c]
 *   @0x1d8400 add r2, r11, #40
 *   @0x1d8404 ldr r7, [r8, #0x828]
 *   @0x1d8408 vldr s19, [pc, #-56]
 *   @0x1d840c ldrd r0, r1, [sp, #48]
 *   @0x1d8410 vmov.f32 s24, s19
 *   @0x1d8414 cmp r7, r9
 *   @0x1d8418 str r9, [sp, #0xc]
 *   @0x1d841c ldr r3, [pc, #-0x54]
 *   @0x1d8420 addne r5, r7, #63
 *   @0x1d8424 ldr r9, [sp, #0x38]
 *   @0x1d8428 andne r5, r5, #63
 *   @0x1d842c strd r0, r1, [sp]
 *   @0x1d8430 mov r1, #1
 *   @0x1d8434 str r2, [sp, #0x1c]
 *   @0x1d8438 addne r5, r8, r5, lsl #5
 *   @0x1d843c str r1, [sp, #0x24]
 *   @0x1d8440 add r1, r8, #40
 *   @0x1d8444 ldr r3, [r9, r3]
 *   @0x1d8448 addne r5, r5, #40
 *   @0x1d844c str r1, [sp, #0x20]
 *   @0x1d8450 moveq r5, #0
 *   @0x1d8454 ldrd r0, r1, [sp, #48]
 *   @0x1d8458 ldrd r2, r3, [r3]
 *   @0x1d845c str r8, [sp, #0x8]
 *   @0x1d8460 subs r0, r0, r2
 *   @0x1d8464 sbc r1, r1, r3
 *   @0x1d8468 strd r0, r1, [sp, #16]
 *   @0x1d846c cmp r5, #0
 *   @0x1d8470 cmpne r4, #0
 *   @0x1d8474 beq 0x1d860c <_Z17TestForNewRotatesx+0x430>
 *   @0x1d8478 ldrd r8, r9, [r5]
 *   @0x1d847c ldrd r2, r3, [r4]
 *   @0x1d8480 strd r8, r9, [sp]
 *   @0x1d8484 cmp r2, r8
 *   @0x1d8488 sbcs r9, r3, r9
 *   @0x1d848c ldrd r8, r9, [sp, #16]
 *   @0x1d8490 ldrd r0, r1, [sp]
 *   @0x1d8494 strdlt r2, r3, [sp]
 *   @0x1d8498 cmp r2, r8
 *   @0x1d849c sbcs r9, r3, r9
 *   @0x1d84a0 bge 0x1d84b4 <_Z17TestForNewRotatesx+0x2d8>
 *   @0x1d84a4 ldrd r8, r9, [sp, #16]
 *   @0x1d84a8 cmp r0, r8
 *   @0x1d84ac sbcs r9, r1, r9
 *   @0x1d84b0 blt 0x1d860c <_Z17TestForNewRotatesx+0x430>
 *   @0x1d84b4 vldr s15, [r4, #20]
 *   @0x1d84b8 vldr s17, [r5, #20]
 *   @0x1d84bc vsub.f32 s17, s17, s15
 *   @0x1d84c0 vldr s16, [r5, #16]
 *   @0x1d84c4 vldr s14, [r4, #16]
 *   @0x1d84c8 vmul.f32 s15, s17, s17
 *   @0x1d84cc vsub.f32 s16, s16, s14
 *   @0x1d84d0 vmla.f32 s15, s16, s16
 *   @0x1d84d4 vcmpe.f32 s15, #0
 *   @0x1d84d8 vmrs APSR_nzcv, fpscr
 *   @0x1d84dc ble 0x1d8550 <_Z17TestForNewRotatesx+0x374>
 *   @0x1d84e0 vsqrt.f32 s18, s15
 *   @0x1d84e4 vcmp.f32 s18, s18
 *   @0x1d84e8 vmrs APSR_nzcv, fpscr
 *   @0x1d84ec bne 0x1d87a0 <_Z17TestForNewRotatesx+0x5c4>
 *   @0x1d84f0 vdiv.f32 s17, s17, s18
 *   @0x1d84f4 vmov r0, s17
 *   @0x1d84f8 bl 0xb6760 <acosf@plt>
 *   @0x1d84fc vdiv.f32 s16, s16, s18
 *   @0x1d8500 ldr r12, [sp, #0x24]
 *   @0x1d8504 vmov s15, r0
 *   @0x1d8508 vcmpe.f32 s16, #0
 *   @0x1d850c vmrs APSR_nzcv, fpscr
 *   @0x1d8510 vsubmi.f32 s15, s20, s15
 *   @0x1d8514 vaddmi.f32 s15, s15, s20
 *   @0x1d8518 cmp r12, #0
 *   @0x1d851c beq 0x1d8744 <_Z17TestForNewRotatesx+0x568>
 *   @0x1d8520 ldr r8, [sp, #0x8]
 *   @0x1d8524 mov r6, #0
 *   @0x1d8528 ldrd r2, r3, [r4]
 *   @0x1d852c vldr s19, [pc, #-348]
 *   @0x1d8530 str r6, [sp, #0x24]
 *   @0x1d8534 ldr r9, [r8, #0x82c]
 *   @0x1d8538 ldrd r0, r1, [r5]
 *   @0x1d853c ldr r7, [r8, #0x828]
 *   @0x1d8540 vmov.f32 s24, s15
 *   @0x1d8544 ldr r12, [r11, #0x828]
 *   @0x1d8548 ldr r6, [r11, #0x82c]
 *   @0x1d854c str r9, [sp, #0xc]
 *   @0x1d8550 cmp r12, r6
 *   @0x1d8554 beq 0x1d873c <_Z17TestForNewRotatesx+0x560>
 *   @0x1d8558 ldr r8, [sp, #0x1c]
 *   @0x1d855c rsb r10, r8, r4
 *   @0x1d8560 lsr r10, r10, #5
 *   @0x1d8564 cmp r10, #63
 *   @0x1d8568 bhi 0x1d873c <_Z17TestForNewRotatesx+0x560>
 *   @0x1d856c cmp r12, r6
 *   @0x1d8570 add r10, r10, #63
 *   @0x1d8574 and r10, r10, #63
 *   @0x1d8578 bge 0x1d872c <_Z17TestForNewRotatesx+0x550>
 *   @0x1d857c cmp r12, r10
 *   @0x1d8580 bgt 0x1d858c <_Z17TestForNewRotatesx+0x3b0>
 *   @0x1d8584 cmp r6, r10
 *   @0x1d8588 bgt 0x1d873c <_Z17TestForNewRotatesx+0x560>
 *   @0x1d858c add r10, r11, r10, lsl #5
 *   @0x1d8590 add r10, r10, #40
 *   @0x1d8594 ldr r9, [sp, #0xc]
 *   @0x1d8598 cmp r7, r9
 *   @0x1d859c beq 0x1d8710 <_Z17TestForNewRotatesx+0x534>
 *   @0x1d85a0 ldr r8, [sp, #0x20]
 *   @0x1d85a4 rsb r9, r8, r5
 *   @0x1d85a8 lsr r9, r9, #5
 *   @0x1d85ac cmp r9, #63
 *   @0x1d85b0 bhi 0x1d8710 <_Z17TestForNewRotatesx+0x534>
 *   @0x1d85b4 ldr r8, [sp, #0xc]
 *   @0x1d85b8 add r9, r9, #63
 *   @0x1d85bc and r9, r9, #63
 *   @0x1d85c0 cmp r7, r8
 *   @0x1d85c4 bge 0x1d86fc <_Z17TestForNewRotatesx+0x520>
 *   @0x1d85c8 cmp r7, r9
 *   @0x1d85cc bgt 0x1d85d8 <_Z17TestForNewRotatesx+0x3fc>
 *   @0x1d85d0 cmp r8, r9
 *   @0x1d85d4 bgt 0x1d8710 <_Z17TestForNewRotatesx+0x534>
 *   @0x1d85d8 ldr r8, [sp, #0x8]
 *   @0x1d85dc cmp r3, r1
 *   @0x1d85e0 cmpeq r2, r0
 *   @0x1d85e4 add r9, r8, r9, lsl #5
 *   @0x1d85e8 add r9, r9, #40
 *   @0x1d85ec beq 0x1d8720 <_Z17TestForNewRotatesx+0x544>
 *   @0x1d85f0 cmp r0, r2
 *   @0x1d85f4 sbcs r8, r1, r3
 *   @0x1d85f8 movge r5, r9
 *   @0x1d85fc movlt r4, r10
 *   @0x1d8600 cmp r5, #0
 *   @0x1d8604 cmpne r4, #0
 *   @0x1d8608 bne 0x1d8478 <_Z17TestForNewRotatesx+0x29c>
 *   @0x1d860c ldrd r2, r3, [sp, #16]
 *   @0x1d8610 ldrd r6, r7, [sp]
 *   @0x1d8614 ldr r8, [sp, #0x8]
 *   @0x1d8618 cmp r2, r6
 *   @0x1d861c sbcs r7, r3, r7
 *   @0x1d8620 blt 0x1d8360 <_Z17TestForNewRotatesx+0x184>
 *   @0x1d8624 vabs.f32 s19, s19
 *   @0x1d8628 vcmpe.f32 s23, s19
 *   @0x1d862c vmrs APSR_nzcv, fpscr
 *   @0x1d8630 bpl 0x1d8360 <_Z17TestForNewRotatesx+0x184>
 *   @0x1d8634 mov r0, #72
 *   @0x1d8638 bl 0x27c524 <_Znwj>
 *   @0x1d863c mov r4, r0
 *   @0x1d8640 bl 0x1d7c0c <_ZN8CGestureC2Ev>
 *   @0x1d8644 ldr r3, [r8, #0x4]
 *   @0x1d8648 mov r0, #5
 *   @0x1d864c ldr r8, [sp, #0x38]
 *   @0x1d8650 mvn r1, #0
 *   @0x1d8654 ldr r12, [pc, #-0x288]
 *   @0x1d8658 mov lr, #0
 *   @0x1d865c ldr r9, [sp, #0x2c]
 *   @0x1d8660 ldr r2, [r11, #0x4]
 *   @0x1d8664 ldr r12, [r8, r12]
 *   @0x1d8668 vstr s22, [r4, #52]
 *   @0x1d866c ldrd r6, r7, [sp, #48]
 *   @0x1d8670 vstr s22, [r4, #48]
 *   @0x1d8674 add r12, r12, #8
 *   @0x1d8678 str r12, [r4]
 *   @0x1d867c ldr r12, [r9, #0x8]
 *   @0x1d8680 vstr s22, [r4, #56]
 *   @0x1d8684 str r0, [r4, #0x8]
 *   @0x1d8688 vstr s22, [r4, #60]
 *   @0x1d868c str r1, [r4, #0x44]
 *   @0x1d8690 vstr s22, [r4, #64]
 *   @0x1d8694 str r2, [r4, #0x28]
 *   @0x1d8698 mov r0, #12
 *   @0x1d869c str r3, [r4, #0x2c]
 *   @0x1d86a0 mov r2, #143
 *   @0x1d86a4 mov r3, #1
 *   @0x1d86a8 strd r6, r7, [r4, #24]
 *   @0x1d86ac strd r6, r7, [r4, #32]
 *   @0x1d86b0 add r12, r12, r3
 *   @0x1d86b4 ldr r1, [sp, #0x3c]
 *   @0x1d86b8 str lr, [r4, #0x14]
 *   @0x1d86bc str r12, [r9, #0x8]
 *   @0x1d86c0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1d86c4 ldr r3, [r9, #0x4]
 *   @0x1d86c8 cmp r3, #0
 *   @0x1d86cc ldrne r7, [sp, #0x2c]
 *   @0x1d86d0 movne r8, #0
 *   @0x1d86d4 streq r0, [r9, #0x4]
 *   @0x1d86d8 str r4, [r0, #0x8]
 *   @0x1d86dc streq r0, [r9]
 *   @0x1d86e0 strne r0, [r3]
 *   @0x1d86e4 streq r3, [r0, #0x4]
 *   @0x1d86e8 strne r3, [r0, #0x4]
 *   @0x1d86ec streq r3, [r0]
 *   @0x1d86f0 strne r0, [r7, #0x4]
 *   @0x1d86f4 strne r8, [r0]
 *   @0x1d86f8 b 0x1d8360 <_Z17TestForNewRotatesx+0x184>
 *   @0x1d86fc ldr r8, [sp, #0xc]
 *   @0x1d8700 cmp r8, r9
 *   @0x1d8704 bgt 0x1d8710 <_Z17TestForNewRotatesx+0x534>
 *   @0x1d8708 cmp r7, r9
 *   @0x1d870c bgt 0x1d85d8 <_Z17TestForNewRotatesx+0x3fc>
 *   @0x1d8710 cmp r3, r1
 *   @0x1d8714 cmpeq r2, r0
 *   @0x1d8718 mov r9, #0
 *   @0x1d871c bne 0x1d85f0 <_Z17TestForNewRotatesx+0x414>
 *   @0x1d8720 mov r5, r9
 *   @0x1d8724 mov r4, r10
 *   @0x1d8728 b 0x1d846c <_Z17TestForNewRotatesx+0x290>
 *   @0x1d872c cmp r6, r10
 *   @0x1d8730 bgt 0x1d873c <_Z17TestForNewRotatesx+0x560>
 *   @0x1d8734 cmp r12, r10
 *   @0x1d8738 bgt 0x1d858c <_Z17TestForNewRotatesx+0x3b0>
 *   @0x1d873c mov r10, #0
 *   @0x1d8740 b 0x1d8594 <_Z17TestForNewRotatesx+0x3b8>
 *   @0x1d8744 vsub.f32 s14, s15, s24
 *   @0x1d8748 vcmpe.f32 s14, s20
 *   @0x1d874c vmrs APSR_nzcv, fpscr
 *   @0x1d8750 vsubgt.f32 s14, s21, s14
 *   @0x1d8754 vneggt.f32 s14, s14
 *   @0x1d8758 vadd.f32 s14, s19, s14
 *   @0x1d875c vmul.f32 s13, s14, s19
 *   @0x1d8760 vcmpe.f32 s13, #0
 *   @0x1d8764 vmrs APSR_nzcv, fpscr
 *   @0x1d8768 bmi 0x1d860c <_Z17TestForNewRotatesx+0x430>
 *   @0x1d876c ldr r12, [sp, #0x8]
 *   @0x1d8770 vmov.f32 s19, s14
 *   @0x1d8774 ldrd r2, r3, [r4]
 *   @0x1d8778 ldrd r0, r1, [r5]
 *   @0x1d877c ldr r6, [r12, #0x82c]
 *   @0x1d8780 ldr r7, [r12, #0x828]
 *   @0x1d8784 vmov.f32 s24, s15
 *   @0x1d8788 ldr r12, [r11, #0x828]
 *   @0x1d878c str r6, [sp, #0xc]
 *   @0x1d8790 ldr r6, [r11, #0x82c]
 *   @0x1d8794 b 0x1d8550 <_Z17TestForNewRotatesx+0x374>
 *   @0x1d8798 mov r4, #0
 *   @0x1d879c b 0x1d83fc <_Z17TestForNewRotatesx+0x220>
 *   @0x1d87a0 vmov r0, s15
 *   @0x1d87a4 bl 0xb6700 <sqrtf@plt>
 *   @0x1d87a8 vmov s18, r0
 *   @0x1d87ac b 0x1d84f0 <_Z17TestForNewRotatesx+0x314>
 *   @0x1d87b0 ldr r6, [sp, #0x18]
 *   @0x1d87b4 str r6, [sp, #0x28]
 *   @0x1d87b8 b 0x1d8394 <_Z17TestForNewRotatesx+0x1b8>
 *
 * ══ §11/21 JS_ArrayObjectSetup()  0x243074  size 1496  374 条（0x243074..0x24364c）
 * @func 0x243074 0x24364c  size 1496  374 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x24309c→0x756448, 0x2430b0→0x756450, 0x243510→0x544be0
 * 调用序列: YYObjectBase::Add(char const*, YYObjectBase*, int)×24 / JS_SetupFunction(void (*)(RValue&, CInstance*, CInstance*, int, RValue*), int, bool)×23 / YYObjectBase::InternalGetYYVar(int)×3 / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)×2 / JS_StandardBuiltInObjectConstructor(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x4×3 / 0x8×2 / 0x28×2 / 0x4e0×1 / 0x4dc×1 / 0x4d4×1 / 0x4d0×1 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x243074 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x243078 sub sp, sp, #28
 *   @0x24307c mov r4, #0
 *   @0x243080 add r0, sp, #8
 *   @0x243084 mov r1, r4
 *   @0x243088 mov r2, r4
 *   @0x24308c mov r3, r4
 *   @0x243090 str r4, [sp]
 *   @0x243094 ldr r6, [pc, #0x4e0]
 *   @0x243098 bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_>
 *   @0x24309c ldr r3, [pc, #0x4dc]
 *   @0x2430a0 add r6, pc, r6
 *   @0x2430a4 ldr r5, [sp, #0x8]
 *   @0x2430a8 ldr r2, [pc, #0x4d4]
 *   @0x2430ac ldr r8, [r6, r3]
 *   @0x2430b0 ldr r3, [pc, #0x4d0]
 *   @0x2430b4 add r2, pc, r2
 *   @0x2430b8 str r2, [r5, #0x40]
 *   @0x2430bc mov r0, r5
 *   @0x2430c0 str r5, [r8]
 *   @0x2430c4 ldr r3, [r6, r3]
 *   @0x2430c8 ldr r1, [r3]
 *   @0x2430cc str r1, [r5, #0x18]
 *   @0x2430d0 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x2430d4 ldr r3, [pc, #0x4b0]
 *   @0x2430d8 ldr r0, [r5, #0x28]
 *   @0x2430dc mov r1, r4
 *   @0x2430e0 mov r2, r4
 *   @0x2430e4 orr r0, r0, #1
 *   @0x2430e8 str r0, [r5, #0x28]
 *   @0x2430ec ldr r0, [r6, r3]
 *   @0x2430f0 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2430f4 ldr r1, [pc, #0x494]
 *   @0x2430f8 mov r3, #6
 *   @0x2430fc add r1, pc, r1
 *   @0x243100 mov r2, r0
 *   @0x243104 mov r0, r5
 *   @0x243108 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x24310c ldr r3, [pc, #0x480]
 *   @0x243110 mov r1, r4
 *   @0x243114 mov r2, r4
 *   @0x243118 ldr r0, [r6, r3]
 *   @0x24311c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x243120 ldr r1, [pc, #0x470]
 *   @0x243124 mov r3, #6
 *   @0x243128 add r1, pc, r1
 *   @0x24312c mov r2, r0
 *   @0x243130 mov r0, r5
 *   @0x243134 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x243138 ldr r3, [pc, #0x45c]
 *   @0x24313c mov r2, r4
 *   @0x243140 mov r1, #1
 *   @0x243144 ldr r0, [r6, r3]
 *   @0x243148 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x24314c ldr r1, [pc, #0x44c]
 *   @0x243150 mov r3, #6
 *   @0x243154 add r1, pc, r1
 *   @0x243158 mov r2, r0
 *   @0x24315c mov r0, r5
 *   @0x243160 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x243164 ldr r3, [pc, #0x438]
 *   @0x243168 mov r1, r4
 *   @0x24316c mov r2, r4
 *   @0x243170 ldr r0, [r6, r3]
 *   @0x243174 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x243178 ldr r1, [pc, #0x428]
 *   @0x24317c mov r3, #6
 *   @0x243180 add r1, pc, r1
 *   @0x243184 mov r2, r0
 *   @0x243188 mov r0, r5
 *   @0x24318c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x243190 ldr r3, [pc, #0x414]
 *   @0x243194 mov r1, r4
 *   @0x243198 mov r2, r4
 *   @0x24319c ldr r0, [r6, r3]
 *   @0x2431a0 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2431a4 ldr r1, [pc, #0x404]
 *   @0x2431a8 mov r3, #6
 *   @0x2431ac add r1, pc, r1
 *   @0x2431b0 mov r2, r0
 *   @0x2431b4 mov r0, r5
 *   @0x2431b8 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2431bc ldr r3, [pc, #0x3f0]
 *   @0x2431c0 mov r2, r4
 *   @0x2431c4 mov r1, #1
 *   @0x2431c8 ldr r0, [r6, r3]
 *   @0x2431cc bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2431d0 ldr r1, [pc, #0x3e0]
 *   @0x2431d4 mov r3, #6
 *   @0x2431d8 add r1, pc, r1
 *   @0x2431dc mov r2, r0
 *   @0x2431e0 mov r0, r5
 *   @0x2431e4 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2431e8 ldr r3, [pc, #0x3cc]
 *   @0x2431ec mov r1, r4
 *   @0x2431f0 mov r2, r4
 *   @0x2431f4 ldr r0, [r6, r3]
 *   @0x2431f8 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2431fc ldr r1, [pc, #0x3bc]
 *   @0x243200 mov r3, #6
 *   @0x243204 add r1, pc, r1
 *   @0x243208 mov r2, r0
 *   @0x24320c mov r0, r5
 *   @0x243210 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x243214 ldr r3, [pc, #0x3a8]
 *   @0x243218 mov r1, r4
 *   @0x24321c mov r2, r4
 *   @0x243220 ldr r0, [r6, r3]
 *   @0x243224 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x243228 ldr r1, [pc, #0x398]
 *   @0x24322c mov r3, #6
 *   @0x243230 add r1, pc, r1
 *   @0x243234 mov r2, r0
 *   @0x243238 mov r0, r5
 *   @0x24323c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x243240 ldr r3, [pc, #0x384]
 *   @0x243244 mov r2, r4
 *   @0x243248 mov r1, #2
 *   @0x24324c ldr r0, [r6, r3]
 *   @0x243250 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x243254 ldr r1, [pc, #0x374]
 *   @0x243258 mov r3, #6
 *   @0x24325c add r1, pc, r1
 *   @0x243260 mov r2, r0
 *   @0x243264 mov r0, r5
 *   @0x243268 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x24326c ldr r3, [pc, #0x360]
 *   @0x243270 mov r2, r4
 *   @0x243274 mov r1, #1
 *   @0x243278 ldr r0, [r6, r3]
 *   @0x24327c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x243280 ldr r1, [pc, #0x350]
 *   @0x243284 mov r3, #6
 *   @0x243288 add r1, pc, r1
 *   @0x24328c mov r2, r0
 *   @0x243290 mov r0, r5
 *   @0x243294 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x243298 ldr r3, [pc, #0x33c]
 *   @0x24329c mov r2, r4
 *   @0x2432a0 mov r1, #2
 *   @0x2432a4 ldr r0, [r6, r3]
 *   @0x2432a8 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2432ac ldr r1, [pc, #0x32c]
 *   @0x2432b0 mov r3, #6
 *   @0x2432b4 add r1, pc, r1
 *   @0x2432b8 mov r2, r0
 *   @0x2432bc mov r0, r5
 *   @0x2432c0 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2432c4 ldr r3, [pc, #0x318]
 *   @0x2432c8 mov r2, r4
 *   @0x2432cc mov r1, #1
 *   @0x2432d0 ldr r0, [r6, r3]
 *   @0x2432d4 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2432d8 ldr r1, [pc, #0x308]
 *   @0x2432dc mov r3, #6
 *   @0x2432e0 add r1, pc, r1
 *   @0x2432e4 mov r2, r0
 *   @0x2432e8 mov r0, r5
 *   @0x2432ec bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2432f0 ldr r3, [pc, #0x2f4]
 *   @0x2432f4 mov r2, r4
 *   @0x2432f8 mov r1, #1
 *   @0x2432fc ldr r0, [r6, r3]
 *   @0x243300 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x243304 ldr r1, [pc, #0x2e4]
 *   @0x243308 mov r3, #6
 *   @0x24330c add r1, pc, r1
 *   @0x243310 mov r2, r0
 *   @0x243314 mov r0, r5
 *   @0x243318 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x24331c ldr r3, [pc, #0x2d0]
 *   @0x243320 mov r2, r4
 *   @0x243324 mov r1, #1
 *   @0x243328 ldr r0, [r6, r3]
 *   @0x24332c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x243330 ldr r1, [pc, #0x2c0]
 *   @0x243334 mov r3, #6
 *   @0x243338 add r1, pc, r1
 *   @0x24333c mov r2, r0
 *   @0x243340 mov r0, r5
 *   @0x243344 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x243348 ldr r3, [pc, #0x2ac]
 *   @0x24334c mov r2, r4
 *   @0x243350 mov r1, #1
 *   @0x243354 ldr r0, [r6, r3]
 *   @0x243358 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x24335c ldr r1, [pc, #0x29c]
 *   @0x243360 mov r3, #6
 *   @0x243364 add r1, pc, r1
 *   @0x243368 mov r2, r0
 *   @0x24336c mov r0, r5
 *   @0x243370 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x243374 ldr r3, [pc, #0x288]
 *   @0x243378 mov r2, r4
 *   @0x24337c mov r1, #1
 *   @0x243380 ldr r0, [r6, r3]
 *   @0x243384 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x243388 ldr r1, [pc, #0x278]
 *   @0x24338c mov r3, #6
 *   @0x243390 add r1, pc, r1
 *   @0x243394 mov r2, r0
 *   @0x243398 mov r0, r5
 *   @0x24339c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2433a0 ldr r3, [pc, #0x264]
 *   @0x2433a4 mov r2, r4
 *   @0x2433a8 mov r1, #1
 *   @0x2433ac ldr r0, [r6, r3]
 *   @0x2433b0 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2433b4 ldr r1, [pc, #0x254]
 *   @0x2433b8 mov r3, #6
 *   @0x2433bc add r1, pc, r1
 *   @0x2433c0 mov r2, r0
 *   @0x2433c4 mov r0, r5
 *   @0x2433c8 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2433cc ldr r3, [pc, #0x240]
 *   @0x2433d0 mov r2, r4
 *   @0x2433d4 mov r1, #1
 *   @0x2433d8 ldr r0, [r6, r3]
 *   @0x2433dc bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2433e0 ldr r1, [pc, #0x230]
 *   @0x2433e4 mov r3, #6
 *   @0x2433e8 add r1, pc, r1
 *   @0x2433ec mov r2, r0
 *   @0x2433f0 mov r0, r5
 *   @0x2433f4 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2433f8 ldr r3, [pc, #0x21c]
 *   @0x2433fc mov r2, r4
 *   @0x243400 mov r1, #1
 *   @0x243404 ldr r0, [r6, r3]
 *   @0x243408 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x24340c ldr r1, [pc, #0x20c]
 *   @0x243410 mov r3, #6
 *   @0x243414 add r1, pc, r1
 *   @0x243418 mov r2, r0
 *   @0x24341c mov r0, r5
 *   @0x243420 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x243424 ldr r3, [pc, #0x1f8]
 *   @0x243428 mov r2, r4
 *   @0x24342c mov r1, #1
 *   @0x243430 ldr r0, [r6, r3]
 *   @0x243434 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x243438 ldr r1, [pc, #0x1e8]
 *   @0x24343c mov r3, #6
 *   @0x243440 add r1, pc, r1
 *   @0x243444 mov r2, r0
 *   @0x243448 mov r0, r5
 *   @0x24344c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x243450 ldr r3, [pc, #0x1d4]
 *   @0x243454 mov r2, r4
 *   @0x243458 mov r1, #1
 *   @0x24345c ldr r0, [r6, r3]
 *   @0x243460 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x243464 ldr r1, [pc, #0x1c4]
 *   @0x243468 mov r3, #6
 *   @0x24346c add r1, pc, r1
 *   @0x243470 mov r2, r0
 *   @0x243474 mov r0, r5
 *   @0x243478 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x24347c ldr r3, [pc, #0x1b0]
 *   @0x243480 mov r1, r4
 *   @0x243484 mov r2, r4
 *   @0x243488 ldr r9, [r6, r3]
 *   @0x24348c mov r0, r9
 *   @0x243490 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x243494 ldr r3, [pc, #0x19c]
 *   @0x243498 mov r1, r4
 *   @0x24349c mov r2, r4
 *   @0x2434a0 mov r7, r0
 *   @0x2434a4 ldr r0, [r6, r3]
 *   @0x2434a8 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2434ac ldr r1, [pc, #0x188]
 *   @0x2434b0 mov r3, r4
 *   @0x2434b4 add r1, pc, r1
 *   @0x2434b8 mov r2, r0
 *   @0x2434bc mov r0, r7
 *   @0x2434c0 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2434c4 ldr r1, [pc, #0x174]
 *   @0x2434c8 mov r3, r4
 *   @0x2434cc str r9, [r7, #0x94]
 *   @0x2434d0 mov r0, r5
 *   @0x2434d4 mov r2, r7
 *   @0x2434d8 add r1, pc, r1
 *   @0x2434dc bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2434e0 ldr r3, [r7, #0x4]
 *   @0x2434e4 cmp r3, r4
 *   @0x2434e8 beq 0x24353c <_Z19JS_ArrayObjectSetupv+0x4c8>
 *   @0x2434ec ldr r1, [r8]
 *   @0x2434f0 mov r0, r7
 *   @0x2434f4 str r1, [r3]
 *   @0x2434f8 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x2434fc ldr r1, [r7, #0x4]
 *   @0x243500 cmp r1, #0
 *   @0x243504 movne r3, #6
 *   @0x243508 strne r3, [r1, #0xc]
 *   @0x24350c beq 0x243550 <_Z19JS_ArrayObjectSetupv+0x4dc>
 *   @0x243510 ldr r0, [pc, #0x12c]
 *   @0x243514 mov r3, #0
 *   @0x243518 str r3, [r1, #0x8]
 *   @0x24351c mov r2, r7
 *   @0x243520 ldr r1, [pc, #0x120]
 *   @0x243524 ldr r0, [r6, r0]
 *   @0x243528 add r1, pc, r1
 *   @0x24352c ldr r0, [r0]
 *   @0x243530 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x243534 add sp, sp, #28
 *   @0x243538 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x24353c mov r1, r3
 *   @0x243540 mov r0, r7
 *   @0x243544 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x243548 mov r3, r0
 *   @0x24354c b 0x2434ec <_Z19JS_ArrayObjectSetupv+0x478>
 *   @0x243550 mov r0, r7
 *   @0x243554 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x243558 ldr r1, [r7, #0x4]
 *   @0x24355c mov r3, #6
 *   @0x243560 cmp r1, #0
 *   @0x243564 str r3, [r0, #0xc]
 *   @0x243568 bne 0x243510 <_Z19JS_ArrayObjectSetupv+0x49c>
 *   @0x24356c mov r0, r7
 *   @0x243570 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x243574 mov r1, r0
 *   @0x243578 b 0x243510 <_Z19JS_ArrayObjectSetupv+0x49c>
 *   @0x24357c ldrheq lr, [r10], -r0
 *   @0x243580 .word 0xfffff9b0
 *   @0x243584 andseq r2, r1, r4, lsl #15
 *   @0x243588 .word 0xffffc050
 *   @0x24358c .word 0xfffff9c4
 *   @0x243590 andeq pc, lr, r4, lsl r4
 *   @0x243594 .word 0xfffff9c8
 *   @0x243598 andseq r2, r1, r0, lsr #10
 *   @0x24359c .word 0xfffff9cc
 *   @0x2435a0 andseq r2, r1, r4, lsr #12
 *   @0x2435a4 .word 0xfffff9d0
 *   @0x2435a8 andseq r2, r1, r4, asr #13
 *   @0x2435ac .word 0xfffff9d4
 *   @0x2435b0 andseq r2, r1, r0, lsr #13
 *   @0x2435b4 .word 0xfffff9d8
 *   @0x2435b8 andseq r2, r1, r8, ror r6
 *   @0x2435bc .word 0xfffff9dc
 *   @0x2435c0 andseq r2, r1, r4, asr r6
 *   @0x2435c4 .word 0xfffff9e0
 *   @0x2435c8 andseq r2, r1, r0, lsr r6
 *   @0x2435cc .word 0xfffff9e4
 *   @0x2435d0 andseq r2, r1, r0, ror #10
 *   @0x2435d4 .word 0xfffff9e8
 *   @0x2435d8 andseq r2, r1, r0, ror #11
 *   @0x2435dc .word 0xfffff9ec
 *   @0x2435e0 ldrheq r2, [r1], -r12
 *   @0x2435e4 .word 0xfffff9f0
 *   @0x2435e8 mulseq r1, r8, r5
 *   @0x2435ec .word 0xfffff9f4
 *   @0x2435f0 andseq r2, r1, r4, ror r4
 *   @0x2435f4 .word 0xfffff9f8
 *   @0x2435f8 andseq r2, r1, r0, asr r4
 *   @0x2435fc .word 0xfffff9fc
 *   @0x243600 andseq r2, r1, r12, lsl r5
 *   @0x243604 .word 0xfffffa00
 *   @0x243608 ldrsheq r2, [r1], -r8
 *   @0x24360c .word 0xfffffa04
 *   @0x243610 ldrsbeq r2, [r1], -r4
 *   @0x243614 .word 0xfffffa08
 *   @0x243618 ldrheq r2, [r1], -r0
 *   @0x24361c .word 0xfffffa0c
 *   @0x243620 andseq r2, r1, r8, lsl #9
 *   @0x243624 .word 0xfffffa10
 *   @0x243628 andseq r2, r1, r4, ror #8
 *   @0x24362c .word 0xfffffa14
 *   @0x243630 andseq r2, r1, r0, asr #8
 *   @0x243634 .word 0xfffffa18
 *   @0x243638 .word 0xfffffa1c
 *   @0x24363c andseq r2, r1, r4, lsl #8
 *   @0x243640 andseq r2, r1, r12, asr #32
 *   @0x243644 .word 0xffffbf64
 *   @0x243648 strdeq r1, r2, [pc], -r0
 *
 * ══ §12/21 CProfiler::DumpProfileData()  0x2a0ea0  size 1488  372 条（0x2a0ea0..0x2a1470）
 * @func 0x2a0ea0 0x2a1470  size 1488  372 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x2a0edc→0x3eb70c, 0x2a108c→0x542984, 0x2a11b0→0x47a148, 0x2a11c4→0x47a14c, 0x2a1268→0x47a16c, 0x2a13e4→0x47a16c, 0x2a1408→0x47a168
 * 调用序列: anon_29ffec×8 / __floatundidf×4 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / 0xb6844 / CProfiler::DumpProfileData()+0x1b8 / 0xb66dc / YoYo_GetPlatform_DoWork() / CProfiler::DumpProfileData()+0x534
 * 字段偏移 top8: 0x3×5 / 0x18×4 / 0x10×4 / 0xc×4 / 0x28×3 / 0x2a0×3 / 0x14×2 / 0x12c×2
 * VFP 指令 43 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a0ea0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2a0ea4 vpush {d8, d9, d10}
 *   @0x2a0ea8 sub sp, sp, #308
 *   @0x2a0eac ldr r9, [pc, #0x45c]
 *   @0x2a0eb0 mov r11, r0
 *   @0x2a0eb4 ldr r3, [pc, #0x458]
 *   @0x2a0eb8 add r9, pc, r9
 *   @0x2a0ebc ldr r1, [pc, #0x454]
 *   @0x2a0ec0 ldr r0, [r0, #0x18]
 *   @0x2a0ec4 ldr r3, [r9, r3]
 *   @0x2a0ec8 add r1, pc, r1
 *   @0x2a0ecc str r3, [sp, #0x14]
 *   @0x2a0ed0 ldr r3, [r3]
 *   @0x2a0ed4 str r3, [sp, #0x12c]
 *   @0x2a0ed8 bl 0xb6844 <fopen@plt>
 *   @0x2a0edc ldr r3, [pc, #0x438]
 *   @0x2a0ee0 ldr r1, [pc, #0x438]
 *   @0x2a0ee4 ldr r2, [r11, #0x18]
 *   @0x2a0ee8 add r1, pc, r1
 *   @0x2a0eec str r0, [sp, #0x10]
 *   @0x2a0ef0 ldr r3, [r9, r3]
 *   @0x2a0ef4 ldr r4, [r3]
 *   @0x2a0ef8 ldr r3, [r4]
 *   @0x2a0efc mov r0, r4
 *   @0x2a0f00 ldr r3, [r3, #0xc]
 *   @0x2a0f04 blx r3
 *   @0x2a0f08 ldr r1, [sp, #0x10]
 *   @0x2a0f0c cmp r1, #0
 *   @0x2a0f10 beq 0x2a1450 <_ZN9CProfiler15DumpProfileDataEv+0x5b0>
 *   @0x2a0f14 ldr r2, [r11, #0x28]
 *   @0x2a0f18 ldr r3, [pc, #0x404]
 *   @0x2a0f1c cmp r2, #0
 *   @0x2a0f20 ldr r2, [sp, #0x10]
 *   @0x2a0f24 add r3, pc, r3
 *   @0x2a0f28 str r2, [r3]
 *   @0x2a0f2c beq 0x2a13e4 <_ZN9CProfiler15DumpProfileDataEv+0x544>
 *   @0x2a0f30 ldrd r0, r1, [r11, #72]
 *   @0x2a0f34 vldr d8, [pc, #964]
 *   @0x2a0f38 bl 0x319150 <__floatundidf>
 *   @0x2a0f3c ldr r7, [r11, #0x30]
 *   @0x2a0f40 vmov s12, r7
 *   @0x2a0f44 vcvt.f32.s32 s19, s12
 *   @0x2a0f48 vmov d6, r0, r1
 *   @0x2a0f4c ldrd r0, r1, [r11, #96]
 *   @0x2a0f50 vdiv.f64 d7, d6, d8
 *   @0x2a0f54 vcvt.f32.f64 s18, d7
 *   @0x2a0f58 bl 0x319150 <__floatundidf>
 *   @0x2a0f5c ldr r12, [r11, #0xc]
 *   @0x2a0f60 mov r2, #656
 *   @0x2a0f64 mov r3, #1
 *   @0x2a0f68 ldr r4, [r12, #0x4]
 *   @0x2a0f6c add r12, r4, r4, lsl #1
 *   @0x2a0f70 vdiv.f32 s21, s18, s19
 *   @0x2a0f74 vmov d7, r0, r1
 *   @0x2a0f78 ldr r1, [pc, #0x3a8]
 *   @0x2a0f7c lsl r0, r12, #3
 *   @0x2a0f80 add r1, pc, r1
 *   @0x2a0f84 vdiv.f64 d8, d7, d8
 *   @0x2a0f88 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x2a0f8c cmp r4, #1
 *   @0x2a0f90 movle r1, #0
 *   @0x2a0f94 mov r10, r0
 *   @0x2a0f98 movle r8, r1
 *   @0x2a0f9c vcvt.f32.f64 s16, d8
 *   @0x2a0fa0 vdiv.f32 s19, s16, s19
 *   @0x2a0fa4 ble 0x2a1058 <_ZN9CProfiler15DumpProfileDataEv+0x1b8>
 *   @0x2a0fa8 ldr r3, [r11, #0xc]
 *   @0x2a0fac add r4, r4, r4, lsl #2
 *   @0x2a0fb0 vmov s15, r7
 *   @0x2a0fb4 mov r8, #0
 *   @0x2a0fb8 ldr r1, [r3, #0x8]
 *   @0x2a0fbc add r0, r1, r4, lsl #3
 *   @0x2a0fc0 add r1, r1, #40
 *   @0x2a0fc4 cmp r8, #0
 *   @0x2a0fc8 ldr r4, [r1]
 *   @0x2a0fcc beq 0x2a1008 <_ZN9CProfiler15DumpProfileDataEv+0x168>
 *   @0x2a0fd0 ldr r3, [r10]
 *   @0x2a0fd4 cmp r3, r4
 *   @0x2a0fd8 addne r2, r10, #24
 *   @0x2a0fdc movne r3, #0
 *   @0x2a0fe0 bne 0x2a0ffc <_ZN9CProfiler15DumpProfileDataEv+0x15c>
 *   @0x2a0fe4 b 0x2a1294 <_ZN9CProfiler15DumpProfileDataEv+0x3f4>
 *   @0x2a0fe8 mov r12, r2
 *   @0x2a0fec add r2, r2, #24
 *   @0x2a0ff0 ldr lr, [r12]
 *   @0x2a0ff4 cmp lr, r4
 *   @0x2a0ff8 beq 0x2a1298 <_ZN9CProfiler15DumpProfileDataEv+0x3f8>
 *   @0x2a0ffc add r3, r3, #1
 *   @0x2a1000 cmp r3, r8
 *   @0x2a1004 bne 0x2a0fe8 <_ZN9CProfiler15DumpProfileDataEv+0x148>
 *   @0x2a1008 add r5, r8, r8, lsl #1
 *   @0x2a100c ldrb r6, [r1, #0x3]
 *   @0x2a1010 ldrd r2, r3, [r1, #8]
 *   @0x2a1014 add r8, r8, #1
 *   @0x2a1018 ldr lr, [r10, r5, lsl #3]
 *   @0x2a101c add r12, r10, r5, lsl #3
 *   @0x2a1020 lsr r6, r6, #4
 *   @0x2a1024 bfi lr, r4, #0, #28
 *   @0x2a1028 str lr, [r10, r5, lsl #3]
 *   @0x2a102c ldrd r4, r5, [r1, #16]
 *   @0x2a1030 lsr lr, lr, #24
 *   @0x2a1034 strd r2, r3, [r12, #8]
 *   @0x2a1038 bfi lr, r6, #4, #4
 *   @0x2a103c strb lr, [r12, #0x3]
 *   @0x2a1040 strd r4, r5, [r12, #16]
 *   @0x2a1044 add r1, r1, #40
 *   @0x2a1048 cmp r1, r0
 *   @0x2a104c bne 0x2a0fc4 <_ZN9CProfiler15DumpProfileDataEv+0x124>
 *   @0x2a1050 vmov r7, s15
 *   @0x2a1054 mov r1, r8
 *   @0x2a1058 ldr r3, [pc, #0x2cc]
 *   @0x2a105c mov r2, #24
 *   @0x2a1060 mov r0, r10
 *   @0x2a1064 ldr r3, [r9, r3]
 *   @0x2a1068 bl 0xb66dc <qsort@plt>
 *   @0x2a106c bl 0x159cf4 <_Z23YoYo_GetPlatform_DoWorkv>
 *   @0x2a1070 ldr r2, [pc, #0x2b8]
 *   @0x2a1074 add r2, pc, r2
 *   @0x2a1078 vmov d6, r0, r1
 *   @0x2a107c vcvt.u32.f64 s13, d6
 *   @0x2a1080 vmov r0, s13
 *   @0x2a1084 cmp r0, #18
 *   @0x2a1088 bls 0x2a13d4 <_ZN9CProfiler15DumpProfileDataEv+0x534>
 *   @0x2a108c ldr r3, [pc, #0x2a0]
 *   @0x2a1090 ldr r0, [pc, #0x2a0]
 *   @0x2a1094 ldr r5, [pc, #0x2a0]
 *   @0x2a1098 ldr r3, [r9, r3]
 *   @0x2a109c add r0, pc, r0
 *   @0x2a10a0 add r5, pc, r5
 *   @0x2a10a4 ldr r4, [pc, #0x294]
 *   @0x2a10a8 ldr r1, [r3]
 *   @0x2a10ac add r4, pc, r4
 *   @0x2a10b0 bl 0x29ffec <_Z11cmpDumpNodePKvS0_+0x28>
 *   @0x2a10b4 ldr r1, [pc, #0x288]
 *   @0x2a10b8 mov r0, r5
 *   @0x2a10bc mov r2, r7
 *   @0x2a10c0 add r1, pc, r1
 *   @0x2a10c4 bl 0x29ffec <_Z11cmpDumpNodePKvS0_+0x28>
 *   @0x2a10c8 vcvt.s32.f32 s18, s18
 *   @0x2a10cc ldr r1, [pc, #0x274]
 *   @0x2a10d0 mov r0, r5
 *   @0x2a10d4 add r1, pc, r1
 *   @0x2a10d8 vmov r2, s18
 *   @0x2a10dc bl 0x29ffec <_Z11cmpDumpNodePKvS0_+0x28>
 *   @0x2a10e0 vcvt.f64.f32 d7, s21
 *   @0x2a10e4 ldr r1, [pc, #0x260]
 *   @0x2a10e8 mov r0, r4
 *   @0x2a10ec add r1, pc, r1
 *   @0x2a10f0 vmov r2, r3, d7
 *   @0x2a10f4 bl 0x29ffec <_Z11cmpDumpNodePKvS0_+0x28>
 *   @0x2a10f8 ldr r1, [pc, #0x250]
 *   @0x2a10fc vcvt.f64.f32 d6, s19
 *   @0x2a1100 mov r0, r4
 *   @0x2a1104 add r1, pc, r1
 *   @0x2a1108 vmov r2, r3, d6
 *   @0x2a110c bl 0x29ffec <_Z11cmpDumpNodePKvS0_+0x28>
 *   @0x2a1110 ldr r0, [pc, #0x23c]
 *   @0x2a1114 add r0, pc, r0
 *   @0x2a1118 bl 0x29ffec <_Z11cmpDumpNodePKvS0_+0x28>
 *   @0x2a111c ldr r3, [pc, #0x234]
 *   @0x2a1120 ldr r0, [pc, #0x234]
 *   @0x2a1124 add r3, pc, r3
 *   @0x2a1128 ldr r1, [pc, #0x230]
 *   @0x2a112c str r3, [sp]
 *   @0x2a1130 add r0, pc, r0
 *   @0x2a1134 ldr r2, [pc, #0x228]
 *   @0x2a1138 add r1, pc, r1
 *   @0x2a113c ldr r3, [pc, #0x224]
 *   @0x2a1140 add r2, pc, r2
 *   @0x2a1144 add r3, pc, r3
 *   @0x2a1148 bl 0x29ffec <_Z11cmpDumpNodePKvS0_+0x28>
 *   @0x2a114c cmp r8, #0
 *   @0x2a1150 beq 0x2a13a4 <_ZN9CProfiler15DumpProfileDataEv+0x504>
 *   @0x2a1154 ldr r1, [pc, #0x210]
 *   @0x2a1158 vmov s13, r7
 *   @0x2a115c ldr r6, [pc, #0x20c]
 *   @0x2a1160 mov r4, r10
 *   @0x2a1164 add r1, pc, r1
 *   @0x2a1168 ldr r2, [pc, #0x204]
 *   @0x2a116c str r1, [sp, #0x18]
 *   @0x2a1170 vcvt.f64.s32 d10, s13
 *   @0x2a1174 ldr r3, [pc, #0x1fc]
 *   @0x2a1178 add r2, pc, r2
 *   @0x2a117c ldr r1, [pc, #0x1f8]
 *   @0x2a1180 add r6, pc, r6
 *   @0x2a1184 add r3, pc, r3
 *   @0x2a1188 str r2, [sp, #0x20]
 *   @0x2a118c add r1, pc, r1
 *   @0x2a1190 mov r5, #0
 *   @0x2a1194 str r3, [sp, #0x24]
 *   @0x2a1198 vldr d9, [pc, #360]
 *   @0x2a119c str r1, [sp, #0x1c]
 *   @0x2a11a0 b 0x2a1248 <_ZN9CProfiler15DumpProfileDataEv+0x3a8>
 *   @0x2a11a4 cmp r3, #0
 *   @0x2a11a8 movne r7, r6
 *   @0x2a11ac bne 0x2a11d8 <_ZN9CProfiler15DumpProfileDataEv+0x338>
 *   @0x2a11b0 ldr r3, [pc, #0x1c8]
 *   @0x2a11b4 ldr r3, [r9, r3]
 *   @0x2a11b8 ldr r3, [r3]
 *   @0x2a11bc cmp r12, r3
 *   @0x2a11c0 bge 0x2a12c4 <_ZN9CProfiler15DumpProfileDataEv+0x424>
 *   @0x2a11c4 ldr r3, [pc, #0x1b8]
 *   @0x2a11c8 add r12, r12, r12, lsl #2
 *   @0x2a11cc ldr r3, [r9, r3]
 *   @0x2a11d0 ldr r3, [r3]
 *   @0x2a11d4 add r7, r3, r12, lsl #4
 *   @0x2a11d8 ldrd r0, r1, [r4, #16]
 *   @0x2a11dc add r5, r5, #1
 *   @0x2a11e0 bl 0x319150 <__floatundidf>
 *   @0x2a11e4 add r4, r4, #24
 *   @0x2a11e8 vmov d8, r0, r1
 *   @0x2a11ec ldrd r0, r1, [r4, #-16]
 *   @0x2a11f0 bl 0x319150 <__floatundidf>
 *   @0x2a11f4 vmov d7, r0, r1
 *   @0x2a11f8 ldr r0, [pc, #0x188]
 *   @0x2a11fc mov r1, r7
 *   @0x2a1200 vdiv.f64 d6, d8, d7
 *   @0x2a1204 add r0, pc, r0
 *   @0x2a1208 vdiv.f64 d8, d8, d10
 *   @0x2a120c vdiv.f64 d7, d7, d10
 *   @0x2a1210 vmul.f64 d6, d6, d9
 *   @0x2a1214 vmul.f64 d8, d8, d9
 *   @0x2a1218 vcvt.f32.f64 s12, d6
 *   @0x2a121c vcvt.f32.f64 s14, d7
 *   @0x2a1220 vcvt.f64.f32 d6, s12
 *   @0x2a1224 vcvt.f32.f64 s16, d8
 *   @0x2a1228 vstr d6, [sp]
 *   @0x2a122c vcvt.f64.f32 d7, s14
 *   @0x2a1230 vcvt.f64.f32 d6, s16
 *   @0x2a1234 vstr d7, [sp, #8]
 *   @0x2a1238 vmov r2, r3, d6
 *   @0x2a123c bl 0x29ffec <_Z11cmpDumpNodePKvS0_+0x28>
 *   @0x2a1240 cmp r5, r8
 *   @0x2a1244 beq 0x2a13a4 <_ZN9CProfiler15DumpProfileDataEv+0x504>
 *   @0x2a1248 ldrb r3, [r4, #0x3]
 *   @0x2a124c ldr r12, [r4]
 *   @0x2a1250 lsr r3, r3, #4
 *   @0x2a1254 ubfx r12, r12, #0x0, #0x1c
 *   @0x2a1258 cmp r3, #6
 *   @0x2a125c beq 0x2a12cc <_ZN9CProfiler15DumpProfileDataEv+0x42c>
 *   @0x2a1260 cmp r3, #1
 *   @0x2a1264 bne 0x2a11a4 <_ZN9CProfiler15DumpProfileDataEv+0x304>
 *   @0x2a1268 ldr r3, [pc, #0x124]
 *   @0x2a126c ldr r3, [r9, r3]
 *   @0x2a1270 ldr r3, [r3]
 *   @0x2a1274 cmp r12, r3
 *   @0x2a1278 bge 0x2a12f8 <_ZN9CProfiler15DumpProfileDataEv+0x458>
 *   @0x2a127c ldr r3, [r11, #0x28]
 *   @0x2a1280 ldr r2, [sp, #0x24]
 *   @0x2a1284 ldr r7, [r3, r12, lsl #2]
 *   @0x2a1288 cmp r7, #0
 *   @0x2a128c moveq r7, r2
 *   @0x2a1290 b 0x2a11d8 <_ZN9CProfiler15DumpProfileDataEv+0x338>
 *   @0x2a1294 mov r12, r10
 *   @0x2a1298 ldrd r2, r3, [r1, #8]
 *   @0x2a129c ldrd r4, r5, [r12, #8]
 *   @0x2a12a0 ldrd r6, r7, [r12, #16]
 *   @0x2a12a4 adds r2, r2, r4
 *   @0x2a12a8 adc r3, r3, r5
 *   @0x2a12ac strd r2, r3, [r12, #8]
 *   @0x2a12b0 ldrd r2, r3, [r1, #16]
 *   @0x2a12b4 adds r2, r2, r6
 *   @0x2a12b8 adc r3, r3, r7
 *   @0x2a12bc strd r2, r3, [r12, #16]
 *   @0x2a12c0 b 0x2a1044 <_ZN9CProfiler15DumpProfileDataEv+0x1a4>
 *   @0x2a12c4 ldr r7, [sp, #0x18]
 *   @0x2a12c8 b 0x2a11d8 <_ZN9CProfiler15DumpProfileDataEv+0x338>
 *   @0x2a12cc ldr r3, [pc, #0xb8]
 *   @0x2a12d0 mov r1, #256
 *   @0x2a12d4 ldr r2, [sp, #0x1c]
 *   @0x2a12d8 add r3, pc, r3
 *   @0x2a12dc add r3, r3, r12, lsl #2
 *   @0x2a12e0 add r12, sp, #44
 *   @0x2a12e4 ldr r3, [r3, #0x4c]
 *   @0x2a12e8 mov r0, r12
 *   @0x2a12ec mov r7, r12
 *   @0x2a12f0 bl 0xb65c8 <snprintf@plt>
 *   @0x2a12f4 b 0x2a11d8 <_ZN9CProfiler15DumpProfileDataEv+0x338>
 *   @0x2a12f8 ldr r7, [sp, #0x20]
 *   @0x2a12fc b 0x2a11d8 <_ZN9CProfiler15DumpProfileDataEv+0x338>
 *   @0x2a1300 andeq r0, r0, r0
 *   @0x2a1304 addmi r4, pc, r0
 *   @0x2a1308 and r0, r0, r0
 *   @0x2a130c svclo #0x50624d
 *   @0x2a1310 mulseq r5, r8, sp
 *   @0x2a1314 .word 0xffffbd00
 *   @0x2a1318 andeq pc, r9, r4, lsr #9
 *   @0x2a131c .word 0xffffbac4
 *   @0x2a1320 strdeq r8, r9, [r11], -r8
 *   @0x2a1324 subeq r6, r11, r12, asr #30
 *   @0x2a1328 andeq r8, r11, r4, lsr #26
 *   @0x2a132c .word 0xfffffdc8
 *   @0x2a1330 andeq r8, r11, r4, ror #24
 *   @0x2a1334 .word 0xffffeed0
 *   @0x2a1338 andeq r8, r11, r8, ror r12
 *   @0x2a133c andeq r8, r11, r0, lsl #25
 *   @0x2a1340 andeq r8, r11, r0, lsr #25
 *   @0x2a1344 andeq r8, r11, r12, ror #24
 *   @0x2a1348 andeq r8, r11, r8, ror #24
 *   @0x2a134c andeq r8, r11, r12, ror #24
 *   @0x2a1350 andeq r8, r11, r12, ror #24
 *   @0x2a1354 andeq sp, r8, r2, lsr #20
 *   @0x2a1358 muleq r11, r8, r12
 *   @0x2a135c andeq r8, r11, r8, asr r12
 *   @0x2a1360 andeq r8, r11, r8, ror #24
 *   @0x2a1364 andeq r8, r11, r8, ror #24
 *   @0x2a1368 andeq r8, r11, r0, ror r12
 *   @0x2a136c andeq r8, r11, r8, ror r11
 *   @0x2a1370 andeq r8, r11, r12, asr r11
 *   @0x2a1374 andeq r8, r11, r4, ror #22
 *   @0x2a1378 andeq r8, r11, r8, asr r11
 *   @0x2a137c andeq r8, r11, r12, lsr r12
 *   @0x2a1380 .word 0xffffbec4
 *   @0x2a1384 .word 0xffffbec8
 *   @0x2a1388 andeq r8, r11, r12, asr #23
 *   @0x2a138c andseq r7, r4, r0, ror #6
 *   @0x2a1390 andseq r7, r4, r0, ror #4
 *   @0x2a1394 .word 0xffffbed8
 *   @0x2a1398 andeq r8, r11, r12, lsr #17
 *   @0x2a139c .word 0xffffbed0
 *   @0x2a13a0 muleq r11, r12, r8
 *   @0x2a13a4 ldr r0, [sp, #0x10]
 *   @0x2a13a8 bl 0xb6850 <fclose@plt>
 *   @0x2a13ac mov r0, r10
 *   @0x2a13b0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2a13b4 ldr r1, [sp, #0x14]
 *   @0x2a13b8 ldr r2, [sp, #0x12c]
 *   @0x2a13bc ldr r3, [r1]
 *   @0x2a13c0 cmp r2, r3
 *   @0x2a13c4 bne 0x2a146c <_ZN9CProfiler15DumpProfileDataEv+0x5cc>
 *   @0x2a13c8 add sp, sp, #308
 *   @0x2a13cc vpop {d8, d9, d10}
 *   @0x2a13d0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2a13d4 ldr r3, [pc, #-0x4c]
 *   @0x2a13d8 add r3, pc, r3
 *   @0x2a13dc ldr r2, [r3, r0, lsl #2]
 *   @0x2a13e0 b 0x2a108c <_ZN9CProfiler15DumpProfileDataEv+0x1ec>
 *   @0x2a13e4 ldr r0, [pc, #-0x58]
 *   @0x2a13e8 mov r3, #1
 *   @0x2a13ec ldr r1, [pc, #-0x5c]
 *   @0x2a13f0 movw r2, #0x27b
 *   @0x2a13f4 ldr r4, [r9, r0]
 *   @0x2a13f8 add r1, pc, r1
 *   @0x2a13fc ldr r0, [r4]
 *   @0x2a1400 lsl r0, r0, #2
 *   @0x2a1404 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x2a1408 ldr r3, [pc, #-0x74]
 *   @0x2a140c str r0, [r11, #0x28]
 *   @0x2a1410 ldr r3, [r9, r3]
 *   @0x2a1414 ldr r3, [r3]
 *   @0x2a1418 cmp r3, #0
 *   @0x2a141c beq 0x2a0f30 <_ZN9CProfiler15DumpProfileDataEv+0x90>
 *   @0x2a1420 ldr r1, [r4]
 *   @0x2a1424 ldr r2, [r3, #0x60]
 *   @0x2a1428 cmp r2, #0
 *   @0x2a142c blt 0x2a1440 <_ZN9CProfiler15DumpProfileDataEv+0x5a0>
 *   @0x2a1430 cmp r2, r1
 *   @0x2a1434 ldrlt r12, [r3, #0x5c]
 *   @0x2a1438 ldrlt r0, [r11, #0x28]
 *   @0x2a143c strlt r12, [r0, r2, lsl #2]
 *   @0x2a1440 ldr r3, [r3, #0x4]
 *   @0x2a1444 cmp r3, #0
 *   @0x2a1448 bne 0x2a1424 <_ZN9CProfiler15DumpProfileDataEv+0x584>
 *   @0x2a144c b 0x2a0f30 <_ZN9CProfiler15DumpProfileDataEv+0x90>
 *   @0x2a1450 ldr r3, [r4]
 *   @0x2a1454 mov r0, r4
 *   @0x2a1458 ldr r1, [pc, #-0xc0]
 *   @0x2a145c ldr r3, [r3, #0xc]
 *   @0x2a1460 add r1, pc, r1
 *   @0x2a1464 blx r3
 *   @0x2a1468 b 0x2a13b4 <_ZN9CProfiler15DumpProfileDataEv+0x514>
 *   @0x2a146c bl 0xb65d4 <__stack_chk_fail@plt>
 *
 * ══ §13/21 F_JS_Object_defineProperties(RValue&, CInstance*, CInstance*, int, RValue*)  0x252db4  size 1480  370 条（0x252db4..0x25337c）
 * @func 0x252db4 0x25337c  size 1480  370 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator delete(void*)×7 / FREE_RValue__Pre(RValue*)×7 / LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / JSThrowTypeError(char const*)×3 / F_JS_ToObject(RValue*, RValue*) / YYObject_PropertyNameIterator::YYObject_PropertyNameIterator(YYObjectBase*, int)
 * 字段偏移 top8: 0x4×37 / 0x8×20 / 0xc×14 / 0x24×9 / 0x1c×6 / 0x20×4 / 0x30×3 / 0x18×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x252db4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x252db8 cmp r3, #0
 *   @0x252dbc sub sp, sp, #100
 *   @0x252dc0 str r0, [sp, #0xc]
 *   @0x252dc4 ldr r5, [sp, #0x88]
 *   @0x252dc8 beq 0x252ddc <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x252dcc ldr r3, [r5, #0xc]
 *   @0x252dd0 bic r3, r3, #-16777216
 *   @0x252dd4 cmp r3, #6
 *   @0x252dd8 beq 0x252df0 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x252ddc ldr r0, [pc, #0x58c]
 *   @0x252de0 add r0, pc, r0
 *   @0x252de4 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x252de8 add sp, sp, #100
 *   @0x252dec pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x252df0 add r0, sp, #20
 *   @0x252df4 add r1, r5, #16
 *   @0x252df8 bl 0x2403cc <_Z13F_JS_ToObjectP6RValueS0_>
 *   @0x252dfc cmp r0, #1
 *   @0x252e00 beq 0x252ddc <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x252e04 add r9, sp, #68
 *   @0x252e08 mov r2, #1
 *   @0x252e0c ldr r1, [sp, #0x14]
 *   @0x252e10 add r10, sp, #36
 *   @0x252e14 mov r0, r9
 *   @0x252e18 add r7, sp, #52
 *   @0x252e1c bl 0x2400ec <_ZN29YYObject_PropertyNameIteratorC2EP12YYObjectBasei>
 *   @0x252e20 mov r3, #0
 *   @0x252e24 mov r6, r3
 *   @0x252e28 mov r4, r3
 *   @0x252e2c mov r8, r3
 *   @0x252e30 mvn r2, #-16777216
 *   @0x252e34 str r3, [sp, #0x24]
 *   @0x252e38 str r3, [sp, #0x28]
 *   @0x252e3c str r3, [sp, #0x2c]
 *   @0x252e40 str r2, [sp, #0x30]
 *   @0x252e44 mov r0, r9
 *   @0x252e48 mov r1, r10
 *   @0x252e4c bl 0x24a1fc <_ZN29YYObject_PropertyNameIterator4NextEP6RValue>
 *   @0x252e50 cmp r0, #0
 *   @0x252e54 beq 0x2530d4 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x320>
 *   @0x252e58 ldr r3, [sp, #0x24]
 *   @0x252e5c mov r1, r7
 *   @0x252e60 ldr r0, [sp, #0x14]
 *   @0x252e64 ldr r2, [r3]
 *   @0x252e68 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x252e6c ldr r3, [sp, #0x40]
 *   @0x252e70 mvn r0, #-16777216
 *   @0x252e74 cmp r3, r0
 *   @0x252e78 beq 0x252e44 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x252e7c mov r0, #40
 *   @0x252e80 bl 0x27c524 <_Znwj>
 *   @0x252e84 ldr r2, [r0, #0xc]
 *   @0x252e88 mov r11, r0
 *   @0x252e8c bic r3, r2, #-16777216
 *   @0x252e90 cmp r3, #1
 *   @0x252e94 beq 0x252fe0 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x22c>
 *   @0x252e98 cmp r3, #2
 *   @0x252e9c bne 0x252ec0 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x10c>
 *   @0x252ea0 sub r2, r2, #1
 *   @0x252ea4 bic r2, r2, #-16777216
 *   @0x252ea8 bic r2, r2, #3
 *   @0x252eac cmp r2, #0
 *   @0x252eb0 beq 0x2530cc <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x318>
 *   @0x252eb4 mov r1, #5
 *   @0x252eb8 str r8, [r11, #0x8]
 *   @0x252ebc str r1, [r11, #0xc]
 *   @0x252ec0 ldr r3, [sp, #0x30]
 *   @0x252ec4 ldr r2, [sp, #0x2c]
 *   @0x252ec8 str r8, [r11]
 *   @0x252ecc str r3, [r11, #0xc]
 *   @0x252ed0 ldr r3, [sp, #0x30]
 *   @0x252ed4 str r2, [r11, #0x8]
 *   @0x252ed8 bic r3, r3, #-16777216
 *   @0x252edc cmp r3, #14
 *   @0x252ee0 addls pc, pc, r3, lsl #2
 *   @0x252ee4 b 0x252f2c <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x178>
 *   @0x252ee8 b 0x252f68 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x1b4>
 *   @0x252eec b 0x252fc8 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x214>
 *   @0x252ef0 b 0x252f9c <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x1e8>
 *   @0x252ef4 b 0x252f24 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x170>
 *   @0x252ef8 b 0x252f2c <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x178>
 *   @0x252efc b 0x252f2c <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x178>
 *   @0x252f00 b 0x252f78 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x1c4>
 *   @0x252f04 b 0x252f24 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x170>
 *   @0x252f08 b 0x252f2c <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x178>
 *   @0x252f0c b 0x252f2c <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x178>
 *   @0x252f10 b 0x252f68 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x1b4>
 *   @0x252f14 b 0x252f2c <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x178>
 *   @0x252f18 b 0x252f2c <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x178>
 *   @0x252f1c b 0x252f68 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x1b4>
 *   @0x252f20 b 0x252f24 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x170>
 *   @0x252f24 ldr r3, [sp, #0x24]
 *   @0x252f28 str r3, [r11]
 *   @0x252f2c add r0, r11, #16
 *   @0x252f30 mov r1, r7
 *   @0x252f34 bl 0x24195c <_Z25F_JS_ToPropertyDescriptorP6RValueS0_>
 *   @0x252f38 cmp r0, #1
 *   @0x252f3c beq 0x25322c <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x478>
 *   @0x252f40 cmp r6, #0
 *   @0x252f44 streq r6, [r11, #0x24]
 *   @0x252f48 streq r6, [r11, #0x20]
 *   @0x252f4c moveq r6, r11
 *   @0x252f50 strne r11, [r6, #0x20]
 *   @0x252f54 moveq r4, r6
 *   @0x252f58 strne r6, [r11, #0x24]
 *   @0x252f5c strne r8, [r11, #0x20]
 *   @0x252f60 movne r6, r11
 *   @0x252f64 b 0x252e44 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x252f68 ldr r2, [sp, #0x24]
 *   @0x252f6c ldr r3, [sp, #0x28]
 *   @0x252f70 stm r11, {r2, r3}
 *   @0x252f74 b 0x252f2c <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x178>
 *   @0x252f78 ldr r3, [sp, #0x24]
 *   @0x252f7c str r3, [r11]
 *   @0x252f80 ldr r3, [sp, #0x24]
 *   @0x252f84 cmp r3, #0
 *   @0x252f88 beq 0x252f2c <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x178>
 *   @0x252f8c bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x252f90 ldr r1, [sp, #0x24]
 *   @0x252f94 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x252f98 b 0x252f2c <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x178>
 *   @0x252f9c ldr r3, [sp, #0x24]
 *   @0x252fa0 cmp r3, #0
 *   @0x252fa4 str r3, [r11]
 *   @0x252fa8 beq 0x252f2c <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x178>
 *   @0x252fac ldr r1, [r3, #0x8]
 *   @0x252fb0 ldr r2, [r3]
 *   @0x252fb4 cmp r1, #0
 *   @0x252fb8 streq r11, [r3, #0x8]
 *   @0x252fbc add r2, r2, #1
 *   @0x252fc0 str r2, [r3]
 *   @0x252fc4 b 0x252f2c <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x178>
 *   @0x252fc8 ldr r3, [sp, #0x24]
 *   @0x252fcc cmp r3, #0
 *   @0x252fd0 ldrne r2, [r3, #0x4]
 *   @0x252fd4 addne r2, r2, #1
 *   @0x252fd8 strne r2, [r3, #0x4]
 *   @0x252fdc b 0x252f28 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x174>
 *   @0x252fe0 ldr r3, [r0]
 *   @0x252fe4 cmp r3, #0
 *   @0x252fe8 beq 0x253010 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x25c>
 *   @0x252fec str r3, [sp, #0x4]
 *   @0x252ff0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x252ff4 ldr r3, [sp, #0x4]
 *   @0x252ff8 ldr r2, [r3, #0x4]
 *   @0x252ffc sub r2, r2, #1
 *   @0x253000 str r2, [r3, #0x4]
 *   @0x253004 cmp r2, #0
 *   @0x253008 beq 0x253018 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x264>
 *   @0x25300c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x253010 str r8, [r11]
 *   @0x253014 b 0x252ec0 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x10c>
 *   @0x253018 ldr r0, [r3]
 *   @0x25301c str r2, [sp, #0x8]
 *   @0x253020 str r3, [sp, #0x4]
 *   @0x253024 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x253028 ldr r3, [sp, #0x4]
 *   @0x25302c ldr r2, [sp, #0x8]
 *   @0x253030 str r2, [r3]
 *   @0x253034 str r2, [r3, #0x8]
 *   @0x253038 str r3, [sp, #0x4]
 *   @0x25303c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x253040 ldr r3, [sp, #0x4]
 *   @0x253044 ldr r2, [r3, #0x4]
 *   @0x253048 sub r2, r2, #1
 *   @0x25304c str r2, [r3, #0x4]
 *   @0x253050 cmp r2, #0
 *   @0x253054 beq 0x253070 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x2bc>
 *   @0x253058 str r3, [sp, #0x4]
 *   @0x25305c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x253060 ldr r3, [sp, #0x4]
 *   @0x253064 mov r0, r3
 *   @0x253068 bl 0x27d1d0 <_ZdlPv>
 *   @0x25306c b 0x25300c <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x258>
 *   @0x253070 ldr r0, [r3]
 *   @0x253074 str r2, [sp, #0x8]
 *   @0x253078 str r3, [sp, #0x4]
 *   @0x25307c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x253080 ldr r3, [sp, #0x4]
 *   @0x253084 ldr r2, [sp, #0x8]
 *   @0x253088 str r2, [r3]
 *   @0x25308c str r2, [r3, #0x8]
 *   @0x253090 str r3, [sp, #0x4]
 *   @0x253094 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x253098 ldr r3, [sp, #0x4]
 *   @0x25309c ldr r2, [r3, #0x4]
 *   @0x2530a0 sub r2, r2, #1
 *   @0x2530a4 str r2, [r3, #0x4]
 *   @0x2530a8 cmp r2, #0
 *   @0x2530ac beq 0x2532d8 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x524>
 *   @0x2530b0 str r3, [sp, #0x4]
 *   @0x2530b4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x2530b8 ldr r3, [sp, #0x4]
 *   @0x2530bc mov r0, r3
 *   @0x2530c0 bl 0x27d1d0 <_ZdlPv>
 *   @0x2530c4 ldr r3, [sp, #0x4]
 *   @0x2530c8 b 0x253058 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x2a4>
 *   @0x2530cc bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x2530d0 b 0x252eb4 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x100>
 *   @0x2530d4 cmp r4, #0
 *   @0x2530d8 beq 0x253184 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x3d0>
 *   @0x2530dc mov r6, r4
 *   @0x2530e0 b 0x2530f0 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x33c>
 *   @0x2530e4 ldr r6, [r6, #0x20]
 *   @0x2530e8 cmp r6, #0
 *   @0x2530ec beq 0x253114 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x360>
 *   @0x2530f0 ldr r0, [r5]
 *   @0x2530f4 mov r1, r6
 *   @0x2530f8 add r2, r6, #16
 *   @0x2530fc mov r3, #1
 *   @0x253100 bl 0x248610 <_Z22JS_DefineOwnPropertyRVP12YYObjectBaseP6RValueS2_b>
 *   @0x253104 cmp r0, #2
 *   @0x253108 beq 0x2531ac <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x3f8>
 *   @0x25310c cmp r6, #0
 *   @0x253110 bne 0x2530e4 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x330>
 *   @0x253114 mov r7, #0
 *   @0x253118 mov r8, #5
 *   @0x25311c ldr r3, [r4, #0xc]
 *   @0x253120 ldr r6, [r4, #0x20]
 *   @0x253124 sub r3, r3, #1
 *   @0x253128 bic r3, r3, #-16777216
 *   @0x25312c bic r3, r3, #3
 *   @0x253130 cmp r3, #0
 *   @0x253134 beq 0x2532b4 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x500>
 *   @0x253138 ldr r3, [r4, #0x1c]
 *   @0x25313c str r7, [r4, #0x8]
 *   @0x253140 sub r3, r3, #1
 *   @0x253144 str r8, [r4, #0xc]
 *   @0x253148 bic r3, r3, #-16777216
 *   @0x25314c str r7, [r4]
 *   @0x253150 bic r3, r3, #3
 *   @0x253154 cmp r3, #0
 *   @0x253158 bne 0x253164 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x3b0>
 *   @0x25315c add r0, r4, #16
 *   @0x253160 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x253164 str r7, [r4, #0x18]
 *   @0x253168 mov r0, r4
 *   @0x25316c str r8, [r4, #0x1c]
 *   @0x253170 str r7, [r4, #0x10]
 *   @0x253174 mov r4, r6
 *   @0x253178 bl 0x27d1d0 <_ZdlPv>
 *   @0x25317c cmp r6, #0
 *   @0x253180 bne 0x25311c <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x368>
 *   @0x253184 ldr r0, [r5]
 *   @0x253188 ldr r1, [r5, #0x4]
 *   @0x25318c ldr r2, [r5, #0x8]
 *   @0x253190 ldr r3, [r5, #0xc]
 *   @0x253194 ldr r12, [sp, #0xc]
 *   @0x253198 str r0, [r12]
 *   @0x25319c str r1, [r12, #0x4]
 *   @0x2531a0 str r2, [r12, #0x8]
 *   @0x2531a4 str r3, [r12, #0xc]
 *   @0x2531a8 b 0x252de8 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x2531ac mov r5, #0
 *   @0x2531b0 mov r7, #5
 *   @0x2531b4 ldr r3, [r4, #0xc]
 *   @0x2531b8 ldr r6, [r4, #0x20]
 *   @0x2531bc sub r3, r3, #1
 *   @0x2531c0 bic r3, r3, #-16777216
 *   @0x2531c4 bic r3, r3, #3
 *   @0x2531c8 cmp r3, #0
 *   @0x2531cc beq 0x2532c0 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x50c>
 *   @0x2531d0 ldr r3, [r4, #0x1c]
 *   @0x2531d4 str r5, [r4, #0x8]
 *   @0x2531d8 sub r3, r3, #1
 *   @0x2531dc str r7, [r4, #0xc]
 *   @0x2531e0 bic r3, r3, #-16777216
 *   @0x2531e4 str r5, [r4]
 *   @0x2531e8 bic r3, r3, #3
 *   @0x2531ec cmp r3, #0
 *   @0x2531f0 bne 0x2531fc <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x448>
 *   @0x2531f4 add r0, r4, #16
 *   @0x2531f8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x2531fc str r5, [r4, #0x18]
 *   @0x253200 mov r0, r4
 *   @0x253204 str r7, [r4, #0x1c]
 *   @0x253208 str r5, [r4, #0x10]
 *   @0x25320c mov r4, r6
 *   @0x253210 bl 0x27d1d0 <_ZdlPv>
 *   @0x253214 cmp r6, #0
 *   @0x253218 bne 0x2531b4 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x400>
 *   @0x25321c ldr r0, [pc, #0x150]
 *   @0x253220 add r0, pc, r0
 *   @0x253224 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x253228 b 0x252de8 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x25322c cmp r4, #0
 *   @0x253230 movne r6, #0
 *   @0x253234 movne r7, #5
 *   @0x253238 beq 0x2532a4 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x4f0>
 *   @0x25323c ldr r3, [r4, #0xc]
 *   @0x253240 ldr r5, [r4, #0x20]
 *   @0x253244 sub r3, r3, #1
 *   @0x253248 bic r3, r3, #-16777216
 *   @0x25324c bic r3, r3, #3
 *   @0x253250 cmp r3, #0
 *   @0x253254 beq 0x2532cc <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x518>
 *   @0x253258 ldr r3, [r4, #0x1c]
 *   @0x25325c str r6, [r4, #0x8]
 *   @0x253260 sub r3, r3, #1
 *   @0x253264 str r7, [r4, #0xc]
 *   @0x253268 bic r3, r3, #-16777216
 *   @0x25326c str r6, [r4]
 *   @0x253270 bic r3, r3, #3
 *   @0x253274 cmp r3, #0
 *   @0x253278 bne 0x253284 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x4d0>
 *   @0x25327c add r0, r4, #16
 *   @0x253280 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x253284 str r6, [r4, #0x18]
 *   @0x253288 mov r0, r4
 *   @0x25328c str r7, [r4, #0x1c]
 *   @0x253290 str r6, [r4, #0x10]
 *   @0x253294 mov r4, r5
 *   @0x253298 bl 0x27d1d0 <_ZdlPv>
 *   @0x25329c cmp r5, #0
 *   @0x2532a0 bne 0x25323c <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x488>
 *   @0x2532a4 ldr r0, [pc, #0xcc]
 *   @0x2532a8 add r0, pc, r0
 *   @0x2532ac bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x2532b0 b 0x252de8 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x34>
 *   @0x2532b4 mov r0, r4
 *   @0x2532b8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x2532bc b 0x253138 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x384>
 *   @0x2532c0 mov r0, r4
 *   @0x2532c4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x2532c8 b 0x2531d0 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x41c>
 *   @0x2532cc mov r0, r4
 *   @0x2532d0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x2532d4 b 0x253258 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x4a4>
 *   @0x2532d8 ldr r0, [r3]
 *   @0x2532dc str r2, [sp, #0x8]
 *   @0x2532e0 str r3, [sp, #0x4]
 *   @0x2532e4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x2532e8 ldr r3, [sp, #0x4]
 *   @0x2532ec ldr r2, [sp, #0x8]
 *   @0x2532f0 str r2, [r3]
 *   @0x2532f4 str r2, [r3, #0x8]
 *   @0x2532f8 str r3, [sp, #0x4]
 *   @0x2532fc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x253300 ldr r3, [sp, #0x4]
 *   @0x253304 ldr r2, [r3, #0x4]
 *   @0x253308 sub r2, r2, #1
 *   @0x25330c str r2, [r3, #0x4]
 *   @0x253310 cmp r2, #0
 *   @0x253314 bne 0x253354 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x5a0>
 *   @0x253318 ldr r0, [r3]
 *   @0x25331c str r2, [sp, #0x8]
 *   @0x253320 str r3, [sp, #0x4]
 *   @0x253324 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x253328 ldr r3, [sp, #0x4]
 *   @0x25332c ldr r2, [sp, #0x8]
 *   @0x253330 mov r0, r3
 *   @0x253334 str r2, [r3]
 *   @0x253338 str r2, [r3, #0x8]
 *   @0x25333c str r3, [sp, #0x4]
 *   @0x253340 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x253344 ldr r3, [sp, #0x4]
 *   @0x253348 mov r0, r3
 *   @0x25334c bl 0x27d1d0 <_ZdlPv>
 *   @0x253350 ldr r3, [sp, #0x4]
 *   @0x253354 str r3, [sp, #0x4]
 *   @0x253358 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x25335c ldr r3, [sp, #0x4]
 *   @0x253360 mov r0, r3
 *   @0x253364 bl 0x27d1d0 <_ZdlPv>
 *   @0x253368 ldr r3, [sp, #0x4]
 *   @0x25336c b 0x2530b0 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x2fc>
 *   @0x253370 andseq r3, r0, r8, ror #2
 *   @0x253374 andseq r2, r0, r8, lsr #26
 *   @0x253378 andseq r2, r0, r0, lsr #25
 *
 * ══ §14/21 InitialisePreParsedAttribs(GLSLShader*, int, char**)  0x186eac  size 1468  367 条（0x186eac..0x187468）
 * @func 0x186eac 0x187468  size 1468  367 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6574×39 / operator new[](unsigned int)×6 / 0xb65b0×2 / operator delete[](void*)
 * 字段偏移 top8: 0x2c×4 / 0x34×3 / 0x38×3 / 0x4×3 / 0x8×3 / 0x30×2 / 0x484×2 / 0xc×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x186eac push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x186eb0 subs r5, r0, #0
 *   @0x186eb4 sub sp, sp, #92
 *   @0x186eb8 mov r9, r1
 *   @0x186ebc mov r6, r2
 *   @0x186ec0 beq 0x187050 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x1a4>
 *   @0x186ec4 cmp r2, #0
 *   @0x186ec8 cmpne r1, #0
 *   @0x186ecc beq 0x187050 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x1a4>
 *   @0x186ed0 ldr r0, [r5, #0x2c]
 *   @0x186ed4 cmp r0, #0
 *   @0x186ed8 beq 0x186ee0 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x34>
 *   @0x186edc bl 0x27d1d4 <_ZdaPv>
 *   @0x186ee0 cmp r9, #532676608
 *   @0x186ee4 bhi 0x187058 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x1ac>
 *   @0x186ee8 lsl r4, r9, #2
 *   @0x186eec mov r0, r4
 *   @0x186ef0 bl 0x27d14c <_Znaj>
 *   @0x186ef4 str r9, [r5, #0x30]
 *   @0x186ef8 str r0, [r5, #0x2c]
 *   @0x186efc mov r0, r4
 *   @0x186f00 bl 0x27d14c <_Znaj>
 *   @0x186f04 str r0, [r5, #0x34]
 *   @0x186f08 mov r0, r4
 *   @0x186f0c bl 0x27d14c <_Znaj>
 *   @0x186f10 mov r1, #0
 *   @0x186f14 mov r2, #60
 *   @0x186f18 str r0, [r5, #0x38]
 *   @0x186f1c add r0, sp, #28
 *   @0x186f20 bl 0xb65b0 <memset@plt>
 *   @0x186f24 ldr r2, [pc, #0x49c]
 *   @0x186f28 mov r4, #0
 *   @0x186f2c ldr r3, [pc, #0x498]
 *   @0x186f30 add r2, pc, r2
 *   @0x186f34 ldr r10, [pc, #0x494]
 *   @0x186f38 add r3, pc, r3
 *   @0x186f3c str r2, [sp]
 *   @0x186f40 str r3, [sp, #0x4]
 *   @0x186f44 ldr r10, [pc, r10]
 *   @0x186f48 ldr r2, [pc, #0x484]
 *   @0x186f4c ldr r3, [pc, #0x484]
 *   @0x186f50 add r2, pc, r2
 *   @0x186f54 str r2, [sp, #0x8]
 *   @0x186f58 add r3, pc, r3
 *   @0x186f5c ldr r2, [pc, #0x478]
 *   @0x186f60 str r3, [sp, #0xc]
 *   @0x186f64 ldr r3, [pc, #0x474]
 *   @0x186f68 add r2, pc, r2
 *   @0x186f6c str r2, [sp, #0x10]
 *   @0x186f70 add r3, pc, r3
 *   @0x186f74 str r3, [sp, #0x14]
 *   @0x186f78 ldr r3, [r10]
 *   @0x186f7c lsl r8, r4, #2
 *   @0x186f80 ldr r1, [r6]
 *   @0x186f84 ldr r0, [r5, #0x8]
 *   @0x186f88 ldr r11, [r5, #0x2c]
 *   @0x186f8c blx r3
 *   @0x186f90 ldr r7, [r6], #4
 *   @0x186f94 ldr r1, [pc, #0x448]
 *   @0x186f98 add r1, pc, r1
 *   @0x186f9c str r0, [r11, r4, lsl #2]
 *   @0x186fa0 mov r0, r7
 *   @0x186fa4 bl 0xb6574 <strcmp@plt>
 *   @0x186fa8 cmp r0, #0
 *   @0x186fac moveq r3, #1
 *   @0x186fb0 moveq r1, r3
 *   @0x186fb4 beq 0x187020 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x174>
 *   @0x186fb8 ldr r1, [pc, #0x428]
 *   @0x186fbc mov r0, r7
 *   @0x186fc0 add r1, pc, r1
 *   @0x186fc4 bl 0xb6574 <strcmp@plt>
 *   @0x186fc8 cmp r0, #0
 *   @0x186fcc beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c>
 *   @0x186fd0 ldr r1, [pc, #0x414]
 *   @0x186fd4 mov r0, r7
 *   @0x186fd8 add r1, pc, r1
 *   @0x186fdc bl 0xb6574 <strcmp@plt>
 *   @0x186fe0 cmp r0, #0
 *   @0x186fe4 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c>
 *   @0x186fe8 ldr r1, [pc, #0x400]
 *   @0x186fec mov r0, r7
 *   @0x186ff0 add r1, pc, r1
 *   @0x186ff4 bl 0xb6574 <strcmp@plt>
 *   @0x186ff8 cmp r0, #0
 *   @0x186ffc beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c>
 *   @0x187000 ldr r1, [pc, #0x3ec]
 *   @0x187004 mov r0, r7
 *   @0x187008 add r1, pc, r1
 *   @0x18700c bl 0xb6574 <strcmp@plt>
 *   @0x187010 cmp r0, #0
 *   @0x187014 bne 0x18709c <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x1f0>
 *   @0x187018 mov r3, #2
 *   @0x18701c mov r1, r3
 *   @0x187020 add r2, sp, #88
 *   @0x187024 ldr r7, [r5, #0x34]
 *   @0x187028 add r3, r2, r3, lsl #2
 *   @0x18702c ldr r0, [r5, #0x38]
 *   @0x187030 add r4, r4, #1
 *   @0x187034 ldr r2, [r3, #-0x3c]
 *   @0x187038 cmp r4, r9
 *   @0x18703c str r1, [r7, r8]
 *   @0x187040 add r12, r2, #1
 *   @0x187044 str r12, [r3, #-0x3c]
 *   @0x187048 str r2, [r0, r8]
 *   @0x18704c bne 0x186f78 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0xcc>
 *   @0x187050 add sp, sp, #92
 *   @0x187054 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x187058 mvn r0, #0
 *   @0x18705c bl 0x27d14c <_Znaj>
 *   @0x187060 str r9, [r5, #0x30]
 *   @0x187064 str r0, [r5, #0x2c]
 *   @0x187068 mvn r0, #0
 *   @0x18706c bl 0x27d14c <_Znaj>
 *   @0x187070 str r0, [r5, #0x34]
 *   @0x187074 mvn r0, #0
 *   @0x187078 bl 0x27d14c <_Znaj>
 *   @0x18707c mov r1, #0
 *   @0x187080 mov r2, #60
 *   @0x187084 str r0, [r5, #0x38]
 *   @0x187088 add r0, sp, #28
 *   @0x18708c bl 0xb65b0 <memset@plt>
 *   @0x187090 cmp r9, #0
 *   @0x187094 bgt 0x186f24 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x78>
 *   @0x187098 b 0x187050 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x1a4>
 *   @0x18709c ldr r1, [pc, #0x354]
 *   @0x1870a0 mov r0, r7
 *   @0x1870a4 add r1, pc, r1
 *   @0x1870a8 bl 0xb6574 <strcmp@plt>
 *   @0x1870ac cmp r0, #0
 *   @0x1870b0 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c>
 *   @0x1870b4 ldr r1, [pc, #0x340]
 *   @0x1870b8 mov r0, r7
 *   @0x1870bc add r1, pc, r1
 *   @0x1870c0 bl 0xb6574 <strcmp@plt>
 *   @0x1870c4 cmp r0, #0
 *   @0x1870c8 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c>
 *   @0x1870cc ldr r1, [pc, #0x32c]
 *   @0x1870d0 mov r0, r7
 *   @0x1870d4 add r1, pc, r1
 *   @0x1870d8 bl 0xb6574 <strcmp@plt>
 *   @0x1870dc cmp r0, #0
 *   @0x1870e0 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c>
 *   @0x1870e4 ldr r1, [pc, #0x318]
 *   @0x1870e8 mov r0, r7
 *   @0x1870ec add r1, pc, r1
 *   @0x1870f0 bl 0xb6574 <strcmp@plt>
 *   @0x1870f4 cmp r0, #0
 *   @0x1870f8 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c>
 *   @0x1870fc ldr r1, [pc, #0x304]
 *   @0x187100 mov r0, r7
 *   @0x187104 add r1, pc, r1
 *   @0x187108 bl 0xb6574 <strcmp@plt>
 *   @0x18710c cmp r0, #0
 *   @0x187110 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c>
 *   @0x187114 ldr r1, [pc, #0x2f0]
 *   @0x187118 mov r0, r7
 *   @0x18711c add r1, pc, r1
 *   @0x187120 bl 0xb6574 <strcmp@plt>
 *   @0x187124 cmp r0, #0
 *   @0x187128 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c>
 *   @0x18712c ldr r1, [pc, #0x2dc]
 *   @0x187130 mov r0, r7
 *   @0x187134 add r1, pc, r1
 *   @0x187138 bl 0xb6574 <strcmp@plt>
 *   @0x18713c cmp r0, #0
 *   @0x187140 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c>
 *   @0x187144 ldr r1, [pc, #0x2c8]
 *   @0x187148 mov r0, r7
 *   @0x18714c add r1, pc, r1
 *   @0x187150 bl 0xb6574 <strcmp@plt>
 *   @0x187154 cmp r0, #0
 *   @0x187158 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c>
 *   @0x18715c mov r0, r7
 *   @0x187160 ldr r1, [sp]
 *   @0x187164 bl 0xb6574 <strcmp@plt>
 *   @0x187168 cmp r0, #0
 *   @0x18716c beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c>
 *   @0x187170 mov r0, r7
 *   @0x187174 ldr r1, [sp, #0x4]
 *   @0x187178 bl 0xb6574 <strcmp@plt>
 *   @0x18717c cmp r0, #0
 *   @0x187180 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c>
 *   @0x187184 mov r0, r7
 *   @0x187188 ldr r1, [sp, #0x8]
 *   @0x18718c bl 0xb6574 <strcmp@plt>
 *   @0x187190 cmp r0, #0
 *   @0x187194 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c>
 *   @0x187198 mov r0, r7
 *   @0x18719c ldr r1, [sp, #0xc]
 *   @0x1871a0 bl 0xb6574 <strcmp@plt>
 *   @0x1871a4 cmp r0, #0
 *   @0x1871a8 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c>
 *   @0x1871ac mov r0, r7
 *   @0x1871b0 ldr r1, [sp, #0x10]
 *   @0x1871b4 bl 0xb6574 <strcmp@plt>
 *   @0x1871b8 cmp r0, #0
 *   @0x1871bc beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c>
 *   @0x1871c0 mov r0, r7
 *   @0x1871c4 ldr r1, [sp, #0x14]
 *   @0x1871c8 bl 0xb6574 <strcmp@plt>
 *   @0x1871cc cmp r0, #0
 *   @0x1871d0 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c>
 *   @0x1871d4 ldr r1, [pc, #0x23c]
 *   @0x1871d8 mov r0, r7
 *   @0x1871dc add r1, pc, r1
 *   @0x1871e0 bl 0xb6574 <strcmp@plt>
 *   @0x1871e4 cmp r0, #0
 *   @0x1871e8 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c>
 *   @0x1871ec ldr r1, [pc, #0x228]
 *   @0x1871f0 mov r0, r7
 *   @0x1871f4 add r1, pc, r1
 *   @0x1871f8 bl 0xb6574 <strcmp@plt>
 *   @0x1871fc cmp r0, #0
 *   @0x187200 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c>
 *   @0x187204 ldr r1, [pc, #0x214]
 *   @0x187208 mov r0, r7
 *   @0x18720c add r1, pc, r1
 *   @0x187210 bl 0xb6574 <strcmp@plt>
 *   @0x187214 cmp r0, #0
 *   @0x187218 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c>
 *   @0x18721c ldr r1, [pc, #0x200]
 *   @0x187220 mov r0, r7
 *   @0x187224 add r1, pc, r1
 *   @0x187228 bl 0xb6574 <strcmp@plt>
 *   @0x18722c cmp r0, #0
 *   @0x187230 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c>
 *   @0x187234 ldr r1, [pc, #0x1ec]
 *   @0x187238 mov r0, r7
 *   @0x18723c add r1, pc, r1
 *   @0x187240 bl 0xb6574 <strcmp@plt>
 *   @0x187244 cmp r0, #0
 *   @0x187248 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c>
 *   @0x18724c ldr r1, [pc, #0x1d8]
 *   @0x187250 mov r0, r7
 *   @0x187254 add r1, pc, r1
 *   @0x187258 bl 0xb6574 <strcmp@plt>
 *   @0x18725c cmp r0, #0
 *   @0x187260 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c>
 *   @0x187264 ldr r1, [pc, #0x1c4]
 *   @0x187268 mov r0, r7
 *   @0x18726c add r1, pc, r1
 *   @0x187270 bl 0xb6574 <strcmp@plt>
 *   @0x187274 cmp r0, #0
 *   @0x187278 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c>
 *   @0x18727c ldr r1, [pc, #0x1b0]
 *   @0x187280 mov r0, r7
 *   @0x187284 add r1, pc, r1
 *   @0x187288 bl 0xb6574 <strcmp@plt>
 *   @0x18728c cmp r0, #0
 *   @0x187290 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c>
 *   @0x187294 ldr r1, [pc, #0x19c]
 *   @0x187298 mov r0, r7
 *   @0x18729c add r1, pc, r1
 *   @0x1872a0 bl 0xb6574 <strcmp@plt>
 *   @0x1872a4 cmp r0, #0
 *   @0x1872a8 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c>
 *   @0x1872ac ldr r1, [pc, #0x188]
 *   @0x1872b0 mov r0, r7
 *   @0x1872b4 add r1, pc, r1
 *   @0x1872b8 bl 0xb6574 <strcmp@plt>
 *   @0x1872bc cmp r0, #0
 *   @0x1872c0 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c>
 *   @0x1872c4 ldr r1, [pc, #0x174]
 *   @0x1872c8 mov r0, r7
 *   @0x1872cc add r1, pc, r1
 *   @0x1872d0 bl 0xb6574 <strcmp@plt>
 *   @0x1872d4 cmp r0, #0
 *   @0x1872d8 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c>
 *   @0x1872dc ldr r1, [pc, #0x160]
 *   @0x1872e0 mov r0, r7
 *   @0x1872e4 add r1, pc, r1
 *   @0x1872e8 bl 0xb6574 <strcmp@plt>
 *   @0x1872ec cmp r0, #0
 *   @0x1872f0 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c>
 *   @0x1872f4 ldr r1, [pc, #0x14c]
 *   @0x1872f8 mov r0, r7
 *   @0x1872fc add r1, pc, r1
 *   @0x187300 bl 0xb6574 <strcmp@plt>
 *   @0x187304 cmp r0, #0
 *   @0x187308 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c>
 *   @0x18730c ldr r1, [pc, #0x138]
 *   @0x187310 mov r0, r7
 *   @0x187314 add r1, pc, r1
 *   @0x187318 bl 0xb6574 <strcmp@plt>
 *   @0x18731c cmp r0, #0
 *   @0x187320 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c>
 *   @0x187324 ldr r1, [pc, #0x124]
 *   @0x187328 mov r0, r7
 *   @0x18732c add r1, pc, r1
 *   @0x187330 bl 0xb6574 <strcmp@plt>
 *   @0x187334 cmp r0, #0
 *   @0x187338 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c>
 *   @0x18733c ldr r1, [pc, #0x110]
 *   @0x187340 mov r0, r7
 *   @0x187344 add r1, pc, r1
 *   @0x187348 bl 0xb6574 <strcmp@plt>
 *   @0x18734c cmp r0, #0
 *   @0x187350 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c>
 *   @0x187354 ldr r1, [pc, #0xfc]
 *   @0x187358 mov r0, r7
 *   @0x18735c add r1, pc, r1
 *   @0x187360 bl 0xb6574 <strcmp@plt>
 *   @0x187364 cmp r0, #0
 *   @0x187368 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c>
 *   @0x18736c ldr r1, [pc, #0xe8]
 *   @0x187370 mov r0, r7
 *   @0x187374 add r1, pc, r1
 *   @0x187378 bl 0xb6574 <strcmp@plt>
 *   @0x18737c cmp r0, #0
 *   @0x187380 beq 0x187018 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x16c>
 *   @0x187384 ldr r1, [pc, #0xd4]
 *   @0x187388 mov r0, r7
 *   @0x18738c add r1, pc, r1
 *   @0x187390 bl 0xb6574 <strcmp@plt>
 *   @0x187394 cmp r0, #0
 *   @0x187398 beq 0x1873bc <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x510>
 *   @0x18739c ldr r1, [pc, #0xc0]
 *   @0x1873a0 mov r0, r7
 *   @0x1873a4 add r1, pc, r1
 *   @0x1873a8 bl 0xb6574 <strcmp@plt>
 *   @0x1873ac cmp r0, #0
 *   @0x1873b0 moveq r3, #3
 *   @0x1873b4 moveq r1, r3
 *   @0x1873b8 beq 0x187020 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x174>
 *   @0x1873bc mov r3, #4
 *   @0x1873c0 mov r1, r3
 *   @0x1873c4 b 0x187020 <_Z26InitialisePreParsedAttribsP10GLSLShaderiPPc+0x174>
 *   @0x1873c8 andseq r4, r12, r0, asr #27
 *   @0x1873cc andseq r4, r12, r4, asr #27
 *   @0x1873d0 eoreq r6, r6, r8, asr #17
 *   @0x1873d4 ldrheq r4, [r12], -r8
 *   @0x1873d8 ldrheq r4, [r12], -r12
 *   @0x1873dc ldrheq r4, [r12], -r8
 *   @0x1873e0 ldrheq r4, [r12], -r12
 *   @0x1873e4 ldrheq r4, [r12], -r12
 *   @0x1873e8 andseq r4, r12, r0, lsr #25
 *   @0x1873ec mulseq r12, r4, r12
 *   @0x1873f0 andseq r4, r12, r8, lsl #25
 *   @0x1873f4 andseq r4, r12, r12, ror r12
 *   @0x1873f8 andseq r4, r12, r12, ror #23
 *   @0x1873fc andseq r4, r12, r0, ror #23
 *   @0x187400 ldrsbeq r4, [r12], -r4
 *   @0x187404 andseq r4, r12, r8, asr #23
 *   @0x187408 ldrheq r4, [r12], -r12
 *   @0x18740c ldrheq r4, [r12], -r0
 *   @0x187410 andseq r4, r12, r4, lsr #23
 *   @0x187414 mulseq r12, r8, r11
 *   @0x187418 andseq r4, r12, r12, asr r11
 *   @0x18741c andseq r4, r12, r0, asr r11
 *   @0x187420 andseq r4, r12, r4, asr #22
 *   @0x187424 andseq r4, r12, r8, lsr r11
 *   @0x187428 andseq r4, r12, r12, lsr #22
 *   @0x18742c andseq r4, r12, r0, lsr #22
 *   @0x187430 andseq r4, r12, r4, lsl r11
 *   @0x187434 andseq r4, r12, r8, lsl #22
 *   @0x187438 ldrsheq r4, [r12], -r12
 *   @0x18743c ldrsheq r4, [r12], -r0
 *   @0x187440 andseq r4, r12, r4, ror #21
 *   @0x187444 ldrsbeq r4, [r12], -r8
 *   @0x187448 andseq r4, r12, r12, asr #21
 *   @0x18744c andseq r4, r12, r0, asr #21
 *   @0x187450 ldrheq r4, [r12], -r4
 *   @0x187454 andseq r4, r12, r8, lsr #21
 *   @0x187458 mulseq r12, r12, r10
 *   @0x18745c mulseq r12, r0, r10
 *   @0x187460 andseq r4, r12, r4, lsl #21
 *   @0x187464 andseq r4, r12, r12, ror r10
 *
 * ══ §15/21 GetResolution(unsigned char*, int)  0x1dd46c  size 1468  360 条（0x1dd46c..0x1dda28）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x1dd46c 0x1dda28  size 1468  360 条
 * 部分覆盖: 本节 360/367 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1dd47c→0x544c44, 0x1dd488→0x544c3c, 0x1dd538→0x3eb6b8, 0x1dd560→0x544b6c, 0x1dd564→0x544b68, 0x1dd5c8→0x3eb6b8, 0x1dd5f4→0x544bcc, 0x1dd5f8→0x544c34
 * 调用序列: 0xb6640×3 / GetResolution(unsigned char*, int)+0x48×2 / GetResolution(unsigned char*, int)+0x4a8 / GetResolution(unsigned char*, int)+0x4f4 / InitGMLFunctions() / Code_Load(unsigned char*, unsigned int, unsigned char*) / VARI_Load(unsigned char*, unsigned int, unsigned char*) / GetResolution(unsigned char*, int)+0x398
 * 字段偏移 top8: 0xc×7 / 0x4×4 / 0x8×4 / 0x14×3 / 0x10×2 / 0x18×2 / 0x1c×2 / 0x43c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dd46c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1dd470 mov r10, r1
 *   @0x1dd474 ldr r4, [pc, #0x514]
 *   @0x1dd478 sub sp, sp, #52
 *   @0x1dd47c ldr r3, [pc, #0x510]
 *   @0x1dd480 mov r6, r0
 *   @0x1dd484 add r4, pc, r4
 *   @0x1dd488 ldr r1, [pc, #0x508]
 *   @0x1dd48c ldr r0, [r0, #0x4]
 *   @0x1dd490 sub r12, r10, #8
 *   @0x1dd494 ldr r3, [r4, r3]
 *   @0x1dd498 add r2, r6, r10
 *   @0x1dd49c cmp r12, r0
 *   @0x1dd4a0 str r6, [r3]
 *   @0x1dd4a4 str r3, [sp]
 *   @0x1dd4a8 ldr r3, [r4, r1]
 *   @0x1dd4ac str r2, [r3]
 *   @0x1dd4b0 beq 0x1dd4bc <_Z13GetResolutionPhi+0x50>
 *   @0x1dd4b4 add sp, sp, #52
 *   @0x1dd4b8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1dd4bc cmp r10, #8
 *   @0x1dd4c0 bls 0x1dd4b4 <_Z13GetResolutionPhi+0x48>
 *   @0x1dd4c4 movw r11, #0x4f43
 *   @0x1dd4c8 movw r3, #0x4156
 *   @0x1dd4cc movt r11, #0x4544
 *   @0x1dd4d0 movt r3, #0x4952
 *   @0x1dd4d4 mov r8, #8
 *   @0x1dd4d8 str r3, [sp, #0xc]
 *   @0x1dd4dc str r11, [sp, #0x4]
 *   @0x1dd4e0 movw r3, #0x4547
 *   @0x1dd4e4 movt r3, #0x4c4e
 *   @0x1dd4e8 str r3, [sp, #0x10]
 *   @0x1dd4ec movw r3, #0x5453
 *   @0x1dd4f0 movt r3, #0x4752
 *   @0x1dd4f4 str r3, [sp, #0x14]
 *   @0x1dd4f8 movw r3, #0x4547
 *   @0x1dd4fc movt r3, #0x374e
 *   @0x1dd500 str r3, [sp, #0x18]
 *   @0x1dd504 movw r3, #0x4547
 *   @0x1dd508 movt r3, #0x384e
 *   @0x1dd50c str r3, [sp, #0x1c]
 *   @0x1dd510 b 0x1dd588 <_Z13GetResolutionPhi+0x11c>
 *   @0x1dd514 ldr r3, [sp, #0xc]
 *   @0x1dd518 cmp r2, r3
 *   @0x1dd51c beq 0x1dd8ac <_Z13GetResolutionPhi+0x440>
 *   @0x1dd520 ldr r3, [sp, #0x10]
 *   @0x1dd524 cmp r2, r3
 *   @0x1dd528 beq 0x1dd5c8 <_Z13GetResolutionPhi+0x15c>
 *   @0x1dd52c ldr r3, [sp, #0x14]
 *   @0x1dd530 cmp r2, r3
 *   @0x1dd534 bne 0x1dd57c <_Z13GetResolutionPhi+0x110>
 *   @0x1dd538 ldr r3, [pc, #0x45c]
 *   @0x1dd53c add r8, r8, #12
 *   @0x1dd540 ldr r1, [pc, #0x458]
 *   @0x1dd544 add r8, r6, r8
 *   @0x1dd548 ldr r3, [r4, r3]
 *   @0x1dd54c add r1, pc, r1
 *   @0x1dd550 ldr r0, [r3]
 *   @0x1dd554 ldr r3, [r0]
 *   @0x1dd558 ldr r3, [r3, #0xc]
 *   @0x1dd55c blx r3
 *   @0x1dd560 ldr r1, [pc, #0x43c]
 *   @0x1dd564 ldr r2, [pc, #0x43c]
 *   @0x1dd568 ldr r3, [r6, r7]
 *   @0x1dd56c ldr r1, [r4, r1]
 *   @0x1dd570 str r8, [r1]
 *   @0x1dd574 ldr r2, [r4, r2]
 *   @0x1dd578 str r3, [r2]
 *   @0x1dd57c add r8, r5, r7
 *   @0x1dd580 cmp r10, r8
 *   @0x1dd584 bls 0x1dd4b4 <_Z13GetResolutionPhi+0x48>
 *   @0x1dd588 mov r3, r6
 *   @0x1dd58c add r7, r8, #8
 *   @0x1dd590 ldr r2, [r3, r8]!
 *   @0x1dd594 ldr r5, [r3, #0x4]
 *   @0x1dd598 cmp r5, #0
 *   @0x1dd59c beq 0x1dd57c <_Z13GetResolutionPhi+0x110>
 *   @0x1dd5a0 ldr r3, [sp, #0x4]
 *   @0x1dd5a4 cmp r2, r3
 *   @0x1dd5a8 beq 0x1dd868 <_Z13GetResolutionPhi+0x3fc>
 *   @0x1dd5ac bhi 0x1dd514 <_Z13GetResolutionPhi+0xa8>
 *   @0x1dd5b0 ldr r3, [sp, #0x18]
 *   @0x1dd5b4 cmp r2, r3
 *   @0x1dd5b8 beq 0x1dd5c8 <_Z13GetResolutionPhi+0x15c>
 *   @0x1dd5bc ldr r3, [sp, #0x1c]
 *   @0x1dd5c0 cmp r2, r3
 *   @0x1dd5c4 bne 0x1dd57c <_Z13GetResolutionPhi+0x110>
 *   @0x1dd5c8 ldr r3, [pc, #0x3cc]
 *   @0x1dd5cc add r8, r6, r7
 *   @0x1dd5d0 ldr r1, [pc, #0x3d4]
 *   @0x1dd5d4 ldr r3, [r4, r3]
 *   @0x1dd5d8 add r1, pc, r1
 *   @0x1dd5dc ldr r3, [r3]
 *   @0x1dd5e0 str r3, [sp, #0x8]
 *   @0x1dd5e4 ldr r3, [r3]
 *   @0x1dd5e8 ldr r0, [sp, #0x8]
 *   @0x1dd5ec ldr r3, [r3, #0xc]
 *   @0x1dd5f0 blx r3
 *   @0x1dd5f4 ldr r2, [pc, #0x3b4]
 *   @0x1dd5f8 ldr r1, [pc, #0x3b4]
 *   @0x1dd5fc ldr r3, [r6, r7]
 *   @0x1dd600 ldr r0, [r4, r2]
 *   @0x1dd604 ldr r2, [pc, #0x3ac]
 *   @0x1dd608 ubfx r9, r3, #0x8, #0x8
 *   @0x1dd60c uxtb r3, r3
 *   @0x1dd610 str r8, [r0]
 *   @0x1dd614 ldr r0, [r8, #0x8]
 *   @0x1dd618 ldr r1, [r4, r1]
 *   @0x1dd61c cmp r0, #0
 *   @0x1dd620 str r3, [r1]
 *   @0x1dd624 ldrne lr, [sp]
 *   @0x1dd628 ldr r2, [r4, r2]
 *   @0x1dd62c str r3, [r2]
 *   @0x1dd630 ldrne r3, [lr]
 *   @0x1dd634 addne r0, r3, r0
 *   @0x1dd638 bl 0xb6640 <strdup@plt>
 *   @0x1dd63c ldr r3, [r8, #0x28]
 *   @0x1dd640 ldr r2, [pc, #0x374]
 *   @0x1dd644 cmp r3, #0
 *   @0x1dd648 ldr r2, [r4, r2]
 *   @0x1dd64c ldrne r1, [sp]
 *   @0x1dd650 str r0, [r2]
 *   @0x1dd654 moveq r0, r3
 *   @0x1dd658 ldrne r0, [r1]
 *   @0x1dd65c addne r0, r0, r3
 *   @0x1dd660 bl 0xb6640 <strdup@plt>
 *   @0x1dd664 ldr r2, [pc, #0x354]
 *   @0x1dd668 ldr r3, [pc, #0x354]
 *   @0x1dd66c ldr r11, [r8, #0x44]
 *   @0x1dd670 ldr r2, [r4, r2]
 *   @0x1dd674 ldr r12, [r8, #0x14]
 *   @0x1dd678 and r1, r11, #1536
 *   @0x1dd67c cmp r1, #1536
 *   @0x1dd680 str r0, [r2]
 *   @0x1dd684 ldr r3, [r4, r3]
 *   @0x1dd688 str r12, [r3]
 *   @0x1dd68c beq 0x1dd934 <_Z13GetResolutionPhi+0x4c8>
 *   @0x1dd690 tst r11, #512
 *   @0x1dd694 bne 0x1dd900 <_Z13GetResolutionPhi+0x494>
 *   @0x1dd698 tst r11, #1024
 *   @0x1dd69c beq 0x1dd948 <_Z13GetResolutionPhi+0x4dc>
 *   @0x1dd6a0 ldr r3, [pc, #0x320]
 *   @0x1dd6a4 mov r2, #2
 *   @0x1dd6a8 ldr r3, [r4, r3]
 *   @0x1dd6ac str r2, [r3]
 *   @0x1dd6b0 tst r11, #4096
 *   @0x1dd6b4 ldrne r3, [pc, #0x310]
 *   @0x1dd6b8 movne r2, #1
 *   @0x1dd6bc ldrne r3, [r4, r3]
 *   @0x1dd6c0 strbne r2, [r3]
 *   @0x1dd6c4 ldr r3, [pc, #0x304]
 *   @0x1dd6c8 ldr r3, [r4, r3]
 *   @0x1dd6cc ldrb r3, [r3]
 *   @0x1dd6d0 cmp r3, #0
 *   @0x1dd6d4 ldrne r3, [pc, #0x2f0]
 *   @0x1dd6d8 movne r2, #1
 *   @0x1dd6dc ldrne r3, [r4, r3]
 *   @0x1dd6e0 strbne r2, [r3]
 *   @0x1dd6e4 cmp r9, #9
 *   @0x1dd6e8 ble 0x1dd914 <_Z13GetResolutionPhi+0x4a8>
 *   @0x1dd6ec ldr r3, [pc, #0x2d4]
 *   @0x1dd6f0 ldr r3, [r4, r3]
 *   @0x1dd6f4 ldr r3, [r3]
 *   @0x1dd6f8 sub r3, r3, #2
 *   @0x1dd6fc cmp r3, #1
 *   @0x1dd700 bls 0x1dd960 <_Z13GetResolutionPhi+0x4f4>
 *   @0x1dd704 cmp r9, #10
 *   @0x1dd708 beq 0x1dd914 <_Z13GetResolutionPhi+0x4a8>
 *   @0x1dd70c ldr r3, [pc, #0x2c0]
 *   @0x1dd710 mov r2, #0
 *   @0x1dd714 ldr r1, [r8, #0x6c]
 *   @0x1dd718 cmp r9, #11
 *   @0x1dd71c str r1, [sp, #0x24]
 *   @0x1dd720 ldr r1, [r8, #0x68]
 *   @0x1dd724 ldr r0, [r4, r3]
 *   @0x1dd728 str r2, [sp, #0x20]
 *   @0x1dd72c ldrd r2, r3, [sp, #32]
 *   @0x1dd730 orr r2, r2, r1
 *   @0x1dd734 orr r3, r3, r1, asr #31
 *   @0x1dd738 strd r2, r3, [r0]
 *   @0x1dd73c beq 0x1dd914 <_Z13GetResolutionPhi+0x4a8>
 *   @0x1dd740 ldr r3, [pc, #0x290]
 *   @0x1dd744 mov r2, #0
 *   @0x1dd748 ldr lr, [r8, #0x74]
 *   @0x1dd74c cmp r9, #12
 *   @0x1dd750 ldr r1, [r8, #0x70]
 *   @0x1dd754 str lr, [sp, #0x2c]
 *   @0x1dd758 ldr r0, [r4, r3]
 *   @0x1dd75c str r2, [sp, #0x28]
 *   @0x1dd760 ldrd r2, r3, [sp, #40]
 *   @0x1dd764 orr r2, r2, r1
 *   @0x1dd768 orr r3, r3, r1, asr #31
 *   @0x1dd76c strd r2, r3, [r0]
 *   @0x1dd770 beq 0x1dd798 <_Z13GetResolutionPhi+0x32c>
 *   @0x1dd774 ldr r3, [pc, #0x260]
 *   @0x1dd778 cmp r9, #13
 *   @0x1dd77c ldr r2, [r8, #0x78]
 *   @0x1dd780 ldr r3, [r4, r3]
 *   @0x1dd784 str r2, [r3]
 *   @0x1dd788 ldrne r3, [pc, #0x250]
 *   @0x1dd78c ldrne r2, [r8, #0x7c]
 *   @0x1dd790 ldrne r3, [r4, r3]
 *   @0x1dd794 strne r2, [r3]
 *   @0x1dd798 ldr r3, [pc, #0x244]
 *   @0x1dd79c ubfx r1, r11, #0xf, #0x1
 *   @0x1dd7a0 ldr r2, [r8, #0x3c]
 *   @0x1dd7a4 ldr r0, [pc, #0x23c]
 *   @0x1dd7a8 ldr r12, [r4, r3]
 *   @0x1dd7ac ldr r3, [r8, #0x40]
 *   @0x1dd7b0 str r2, [r12]
 *   @0x1dd7b4 ldr r12, [pc, #0x230]
 *   @0x1dd7b8 ldr lr, [r4, r0]
 *   @0x1dd7bc ldr r0, [pc, #0x22c]
 *   @0x1dd7c0 str r3, [lr]
 *   @0x1dd7c4 ldr lr, [r4, r12]
 *   @0x1dd7c8 ldr r12, [pc, #0x224]
 *   @0x1dd7cc str r11, [lr]
 *   @0x1dd7d0 ldr r0, [r4, r0]
 *   @0x1dd7d4 str r2, [r0]
 *   @0x1dd7d8 ldr r2, [pc, #0x218]
 *   @0x1dd7dc ldr r0, [r4, r12]
 *   @0x1dd7e0 str r3, [r0]
 *   @0x1dd7e4 ldr r3, [pc, #0x210]
 *   @0x1dd7e8 ldr r2, [r4, r2]
 *   @0x1dd7ec strb r1, [r2]
 *   @0x1dd7f0 ldr r3, [r4, r3]
 *   @0x1dd7f4 ldrb r3, [r3]
 *   @0x1dd7f8 cmp r3, #0
 *   @0x1dd7fc bicne r11, r11, #1
 *   @0x1dd800 strne r11, [lr]
 *   @0x1dd804 ldr r1, [pc, #0x1f4]
 *   @0x1dd808 cmp r9, #14
 *   @0x1dd80c ldr r0, [sp, #0x8]
 *   @0x1dd810 mov r3, #800
 *   @0x1dd814 ldr r2, [pc, #0x1e8]
 *   @0x1dd818 movle r9, #0
 *   @0x1dd81c ldr r12, [r4, r1]
 *   @0x1dd820 movgt r9, #1
 *   @0x1dd824 ldr r1, [r0]
 *   @0x1dd828 strb r9, [r12]
 *   @0x1dd82c ldr r12, [r4, r2]
 *   @0x1dd830 ldr r2, [r1, #0xc]
 *   @0x1dd834 ldr r1, [pc, #0x1cc]
 *   @0x1dd838 str r3, [r12]
 *   @0x1dd858 movgt r2, #1
 *   @0x1dd85c strb r2, [r3]
 *   @0x1dd860 bl 0x2a297c <_Z16InitGMLFunctionsv>
 *   @0x1dd864 b 0x1dd57c <_Z13GetResolutionPhi+0x110>
 *   @0x1dd868 ldr r3, [pc, #0x12c]
 *   @0x1dd86c ldr r1, [pc, #0x19c]
 *   @0x1dd870 ldr r3, [r4, r3]
 *   @0x1dd874 add r1, pc, r1
 *   @0x1dd878 ldr r0, [r3]
 *   @0x1dd87c ldr r3, [r0]
 *   @0x1dd880 ldr r3, [r3, #0xc]
 *   @0x1dd884 blx r3
 *   @0x1dd888 ldr r3, [pc, #0x184]
 *   @0x1dd88c add r0, r6, r7
 *   @0x1dd890 mov r1, r5
 *   @0x1dd894 mov r2, r6
 *   @0x1dd898 mov r12, #1
 *   @0x1dd89c ldr r3, [r4, r3]
 *   @0x1dd8a0 strb r12, [r3]
 *   @0x1dd8a4 bl 0x1dc800 <_Z9Code_LoadPhjS_>
 *   @0x1dd8a8 b 0x1dd57c <_Z13GetResolutionPhi+0x110>
 *   @0x1dd8ac ldr r3, [pc, #0xe8]
 *   @0x1dd8b0 add r8, r6, r7
 *   @0x1dd8b4 ldr r1, [pc, #0x15c]
 *   @0x1dd8b8 ldr r3, [r4, r3]
 *   @0x1dd8bc add r1, pc, r1
 *   @0x1dd8c0 ldr r0, [r3]
 *   @0x1dd8c4 ldr r3, [r0]
 *   @0x1dd8c8 ldr r3, [r3, #0xc]
 *   @0x1dd8cc blx r3
 *   @0x1dd8d0 mov r1, r5
 *   @0x1dd8d4 mov r2, r6
 *   @0x1dd8d8 mov r0, r8
 *   @0x1dd8dc bl 0x1dca8c <_Z9VARI_LoadPhjS_>
 *   @0x1dd8e0 ldr r1, [pc, #0x134]
 *   @0x1dd8e4 ldr r3, [pc, #0x134]
 *   @0x1dd8e8 lsr r2, r5, #2
 *   @0x1dd8ec ldr r1, [r4, r1]
 *   @0x1dd8f0 str r8, [r1]
 *   @0x1dd8f4 ldr r3, [r4, r3]
 *   @0x1dd8f8 str r2, [r3]
 *   @0x1dd8fc b 0x1dd57c <_Z13GetResolutionPhi+0x110>
 *   @0x1dd900 ldr r3, [pc, #0xc0]
 *   @0x1dd904 mov r2, #1
 *   @0x1dd908 ldr r3, [r4, r3]
 *   @0x1dd90c str r2, [r3]
 *   @0x1dd910 b 0x1dd6b0 <_Z13GetResolutionPhi+0x244>
 *   @0x1dd914 ldr r1, [pc, #0xbc]
 *   @0x1dd918 cmp r9, #7
 *   @0x1dd91c mvn r2, #0
 *   @0x1dd920 mvn r3, #0
 *   @0x1dd924 ldr r1, [r4, r1]
 *   @0x1dd928 strd r2, r3, [r1]
 *   @0x1dd92c ble 0x1dd804 <_Z13GetResolutionPhi+0x398>
 *   @0x1dd930 b 0x1dd798 <_Z13GetResolutionPhi+0x32c>
 *   @0x1dd934 ldr r3, [pc, #0x8c]
 *   @0x1dd938 mov r2, #4
 *   @0x1dd93c ldr r3, [r4, r3]
 *   @0x1dd940 str r2, [r3]
 *   @0x1dd944 b 0x1dd6b0 <_Z13GetResolutionPhi+0x244>
 *   @0x1dd948 tst r11, #2048
 *   @0x1dd94c ldrne r3, [pc, #0x74]
 *   @0x1dd950 movne r2, #3
 *   @0x1dd954 ldrne r3, [r4, r3]
 *   @0x1dd958 strne r2, [r3]
 *   @0x1dd95c b 0x1dd6b0 <_Z13GetResolutionPhi+0x244>
 *   @0x1dd960 ldr r3, [r8, #0x64]
 *   @0x1dd964 cmp r3, #0
 *   @0x1dd968 beq 0x1dd704 <_Z13GetResolutionPhi+0x298>
 *   @0x1dd96c ldr lr, [sp]
 *   @0x1dd970 ldr r2, [lr]
 *   @0x1dd974 adds r0, r2, r3
 *   @0x1dd978 beq 0x1dd704 <_Z13GetResolutionPhi+0x298>
 *   @0x1dd97c bl 0xb6640 <strdup@plt>
 *   @0x1dd980 ldr r3, [pc, #0x9c]
 *   @0x1dd984 ldr r3, [r4, r3]
 *   @0x1dd988 str r0, [r3]
 *   @0x1dd98c b 0x1dd704 <_Z13GetResolutionPhi+0x298>
 *   @0x1dd990 eoreq r4, r1, r12, asr #15
 *   @0x1dd994 .word 0xffffbcf4
 *   @0x1dd998 .word 0xffffebb8
 *   @0x1dd99c .word 0xffffdecc
 *   @0x1dd9a0 andseq r4, r7, r8, asr #4
 *   @0x1dd9a4 .word 0xffffc114
 *   @0x1dd9a8 .word 0xfffff070
 *   @0x1dd9ac andseq r4, r7, r0, ror r1
 *   @0x1dd9b0 .word 0xffffe79c
 *   @0x1dd9b4 .word 0xfffff074
 *   @0x1dd9b8 .word 0xffffc7d0
 *   @0x1dd9bc .word 0xffffdf0c
 *   @0x1dd9c0 .word 0xffffef18
 *   @0x1dd9c4 .word 0xffffeec4
 *   @0x1dd9c8 .word 0xffffe6d0
 *   @0x1dd9cc .word 0xffffc180
 *   @0x1dd9d0 .word 0xffffbfe0
 *   @0x1dd9d4 .word 0xfffff078
 *   @0x1dd9d8 .word 0xfffff07c
 *   @0x1dd9dc .word 0xfffff080
 *   @0x1dd9e0 .word 0xfffff084
 *   @0x1dd9e4 .word 0xfffff05c
 *   @0x1dd9e8 .word 0xfffff060
 *   @0x1dd9ec .word 0xfffff064
 *   @0x1dd9f0 .word 0xffffdf38
 *   @0x1dd9f4 .word 0xffffdf40
 *   @0x1dd9f8 .word 0xffffbf68
 *   @0x1dd9fc .word 0xffffeb04
 *   @0x1dda00 .word 0xffffbf04
 *   @0x1dda04 .word 0xffffd14c
 *   @0x1dda08 andseq r3, r7, r4, lsr #30
 *   @0x1dda0c .word 0xffffbcd4
 *   @0x1dda10 andseq r3, r7, r0, lsl #30
 *   @0x1dda14 .word 0xffffbf10
 *   @0x1dda18 andseq r3, r7, r8, asr #29
 *   @0x1dda1c .word 0xfffff088
 *   @0x1dda20 .word 0xfffff08c
 *   @0x1dda24 .word 0xffffce44
 *
 * ══ §16/21 JS_ObjectSetup()  0x241df4  size 1456  364 条（0x241df4..0x2423a4）
 * @func 0x241df4 0x2423a4  size 1456  364 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_SetupFunction(void (*)(RValue&, CInstance*, CInstance*, int, RValue*), int, bool)×20 / YYObjectBase::Add(char const*, YYObjectBase*, int)×20 / YYObjectBase::InternalGetYYVar(int)×3 / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)×2 / YYSetInstance(RValue*) / YYObjectBase::Add(char const*, int, int) / YYObjectBase::Add(char const*, RValue&, int)
 * 字段偏移 top8: 0x4×3 / 0x28×2 / 0x18×2 / 0x390×2 / 0x388×2 / 0x4cc×1 / 0x4c0×1 / 0x4a4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x241df4 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x241df8 sub sp, sp, #20
 *   @0x241dfc ldr r4, [pc, #0x4cc]
 *   @0x241e00 mov r6, #6
 *   @0x241e04 mov r0, sp
 *   @0x241e08 bl 0xdc37c <_Z13YYSetInstanceP6RValue>
 *   @0x241e0c ldr r3, [pc, #0x4c0]
 *   @0x241e10 add r4, pc, r4
 *   @0x241e14 mov r1, #0
 *   @0x241e18 mov r2, r1
 *   @0x241e1c mov r5, r1
 *   @0x241e20 ldr r0, [r4, r3]
 *   @0x241e24 ldr r8, [sp]
 *   @0x241e28 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x241e2c ldr r12, [pc, #0x4a4]
 *   @0x241e30 mov r3, r6
 *   @0x241e34 ldr lr, [pc, #0x4a0]
 *   @0x241e38 ldr r1, [r8, #0x28]
 *   @0x241e3c add r12, pc, r12
 *   @0x241e40 add lr, pc, lr
 *   @0x241e44 str r5, [r8, #0x18]
 *   @0x241e48 orr r1, r1, #1
 *   @0x241e4c str r1, [r8, #0x28]
 *   @0x241e50 ldr r1, [pc, #0x488]
 *   @0x241e54 str lr, [r8, #0x40]
 *   @0x241e58 add r1, pc, r1
 *   @0x241e5c str r6, [r12, #0x968]
 *   @0x241e60 mov r7, r0
 *   @0x241e64 mov r0, r8
 *   @0x241e68 mov r2, r7
 *   @0x241e6c str r7, [r12, #0x95c]
 *   @0x241e70 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x241e74 ldr r3, [pc, #0x468]
 *   @0x241e78 mov r1, r5
 *   @0x241e7c mov r2, r5
 *   @0x241e80 ldr r0, [r4, r3]
 *   @0x241e84 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x241e88 ldr r1, [pc, #0x458]
 *   @0x241e8c mov r3, r6
 *   @0x241e90 add r1, pc, r1
 *   @0x241e94 mov r2, r0
 *   @0x241e98 mov r0, r8
 *   @0x241e9c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x241ea0 ldr r3, [pc, #0x444]
 *   @0x241ea4 mov r1, r5
 *   @0x241ea8 mov r2, r5
 *   @0x241eac ldr r0, [r4, r3]
 *   @0x241eb0 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x241eb4 ldr r1, [pc, #0x434]
 *   @0x241eb8 mov r3, r6
 *   @0x241ebc add r1, pc, r1
 *   @0x241ec0 mov r2, r0
 *   @0x241ec4 mov r0, r8
 *   @0x241ec8 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x241ecc ldr r3, [pc, #0x420]
 *   @0x241ed0 mov r1, r5
 *   @0x241ed4 mov r2, r5
 *   @0x241ed8 ldr r0, [r4, r3]
 *   @0x241edc bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x241ee0 ldr r1, [pc, #0x410]
 *   @0x241ee4 mov r3, r6
 *   @0x241ee8 add r1, pc, r1
 *   @0x241eec mov r2, r0
 *   @0x241ef0 mov r0, r8
 *   @0x241ef4 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x241ef8 ldr r3, [pc, #0x3fc]
 *   @0x241efc mov r1, r5
 *   @0x241f00 mov r2, r5
 *   @0x241f04 ldr r0, [r4, r3]
 *   @0x241f08 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x241f0c ldr r1, [pc, #0x3ec]
 *   @0x241f10 mov r3, r6
 *   @0x241f14 add r1, pc, r1
 *   @0x241f18 mov r2, r0
 *   @0x241f1c mov r0, r8
 *   @0x241f20 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x241f24 ldr r3, [pc, #0x3d8]
 *   @0x241f28 mov r1, r5
 *   @0x241f2c mov r2, r5
 *   @0x241f30 ldr r0, [r4, r3]
 *   @0x241f34 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x241f38 ldr r1, [pc, #0x3c8]
 *   @0x241f3c mov r3, r6
 *   @0x241f40 add r1, pc, r1
 *   @0x241f44 mov r2, r0
 *   @0x241f48 mov r0, r8
 *   @0x241f4c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x241f50 ldr r3, [pc, #0x3b4]
 *   @0x241f54 mov r1, r5
 *   @0x241f58 mov r2, r5
 *   @0x241f5c ldr r0, [r4, r3]
 *   @0x241f60 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x241f64 ldr r1, [pc, #0x3a4]
 *   @0x241f68 mov r3, r6
 *   @0x241f6c add r1, pc, r1
 *   @0x241f70 mov r2, r0
 *   @0x241f74 mov r0, r8
 *   @0x241f78 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x241f7c ldr r3, [pc, #0x390]
 *   @0x241f80 ldr r12, [pc, #0x390]
 *   @0x241f84 mov r1, r8
 *   @0x241f88 ldr r0, [pc, #0x38c]
 *   @0x241f8c ldr lr, [r4, r3]
 *   @0x241f90 ldr r2, [pc, #0x388]
 *   @0x241f94 ldr r3, [pc, #0x388]
 *   @0x241f98 str lr, [r8, #0x4c]
 *   @0x241f9c ldr r12, [r4, r12]
 *   @0x241fa0 str r12, [r8, #0x50]
 *   @0x241fa4 ldr r0, [r4, r0]
 *   @0x241fa8 str r0, [r8, #0x54]
 *   @0x241fac ldr r9, [r4, r2]
 *   @0x241fb0 str r8, [r9]
 *   @0x241fb4 ldr r3, [r4, r3]
 *   @0x241fb8 ldr r0, [r3]
 *   @0x241fbc str r8, [r0, #0x18]
 *   @0x241fc0 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x241fc4 ldr r1, [pc, #0x35c]
 *   @0x241fc8 mov r0, r7
 *   @0x241fcc mov r3, r5
 *   @0x241fd0 add r1, pc, r1
 *   @0x241fd4 mov r2, #1
 *   @0x241fd8 bl 0x199960 <_ZN12YYObjectBase3AddEPKcii>
 *   @0x241fdc ldr r3, [pc, #0x348]
 *   @0x241fe0 mov r2, r5
 *   @0x241fe4 mov r1, #1
 *   @0x241fe8 ldr r0, [r4, r3]
 *   @0x241fec bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x241ff0 ldr r1, [pc, #0x338]
 *   @0x241ff4 mov r3, r6
 *   @0x241ff8 add r1, pc, r1
 *   @0x241ffc mov r2, r0
 *   @0x242000 mov r0, r7
 *   @0x242004 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x242008 ldr r3, [pc, #0x324]
 *   @0x24200c mov r2, r5
 *   @0x242010 mov r1, #2
 *   @0x242014 ldr r0, [r4, r3]
 *   @0x242018 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x24201c ldr r1, [pc, #0x314]
 *   @0x242020 mov r3, r6
 *   @0x242024 add r1, pc, r1
 *   @0x242028 mov r2, r0
 *   @0x24202c mov r0, r7
 *   @0x242030 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x242034 ldr r3, [pc, #0x300]
 *   @0x242038 mov r2, r5
 *   @0x24203c mov r1, #1
 *   @0x242040 ldr r0, [r4, r3]
 *   @0x242044 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x242048 ldr r1, [pc, #0x2f0]
 *   @0x24204c mov r3, r6
 *   @0x242050 add r1, pc, r1
 *   @0x242054 mov r2, r0
 *   @0x242058 mov r0, r7
 *   @0x24205c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x242060 ldr r3, [pc, #0x2dc]
 *   @0x242064 mov r2, r5
 *   @0x242068 mov r1, #2
 *   @0x24206c ldr r0, [r4, r3]
 *   @0x242070 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x242074 ldr r1, [pc, #0x2cc]
 *   @0x242078 mov r3, r6
 *   @0x24207c add r1, pc, r1
 *   @0x242080 mov r2, r0
 *   @0x242084 mov r0, r7
 *   @0x242088 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x24208c ldr r3, [pc, #0x2b8]
 *   @0x242090 mov r2, r5
 *   @0x242094 mov r1, #3
 *   @0x242098 ldr r0, [r4, r3]
 *   @0x24209c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2420a0 ldr r1, [pc, #0x2a8]
 *   @0x2420a4 mov r3, r6
 *   @0x2420a8 add r1, pc, r1
 *   @0x2420ac mov r2, r0
 *   @0x2420b0 mov r0, r7
 *   @0x2420b4 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2420b8 ldr r3, [pc, #0x294]
 *   @0x2420bc mov r2, r5
 *   @0x2420c0 mov r1, #2
 *   @0x2420c4 ldr r0, [r4, r3]
 *   @0x2420c8 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2420cc ldr r1, [pc, #0x284]
 *   @0x2420d0 mov r3, r6
 *   @0x2420d4 add r1, pc, r1
 *   @0x2420d8 mov r2, r0
 *   @0x2420dc mov r0, r7
 *   @0x2420e0 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2420e4 ldr r3, [pc, #0x270]
 *   @0x2420e8 mov r2, r5
 *   @0x2420ec mov r1, #1
 *   @0x2420f0 ldr r0, [r4, r3]
 *   @0x2420f4 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2420f8 ldr r1, [pc, #0x260]
 *   @0x2420fc mov r3, r6
 *   @0x242100 add r1, pc, r1
 *   @0x242104 mov r2, r0
 *   @0x242108 mov r0, r7
 *   @0x24210c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x242110 ldr r3, [pc, #0x24c]
 *   @0x242114 mov r2, r5
 *   @0x242118 mov r1, #1
 *   @0x24211c ldr r0, [r4, r3]
 *   @0x242120 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x242124 ldr r1, [pc, #0x23c]
 *   @0x242128 mov r3, r6
 *   @0x24212c add r1, pc, r1
 *   @0x242130 mov r2, r0
 *   @0x242134 mov r0, r7
 *   @0x242138 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x24213c ldr r3, [pc, #0x228]
 *   @0x242140 mov r2, r5
 *   @0x242144 mov r1, #1
 *   @0x242148 ldr r0, [r4, r3]
 *   @0x24214c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x242150 ldr r1, [pc, #0x218]
 *   @0x242154 mov r3, r6
 *   @0x242158 add r1, pc, r1
 *   @0x24215c mov r2, r0
 *   @0x242160 mov r0, r7
 *   @0x242164 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x242168 ldr r3, [pc, #0x204]
 *   @0x24216c mov r2, r5
 *   @0x242170 mov r1, #1
 *   @0x242174 ldr r0, [r4, r3]
 *   @0x242178 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x24217c ldr r1, [pc, #0x1f4]
 *   @0x242180 mov r3, r6
 *   @0x242184 add r1, pc, r1
 *   @0x242188 mov r2, r0
 *   @0x24218c mov r0, r7
 *   @0x242190 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x242194 ldr r3, [pc, #0x1e0]
 *   @0x242198 mov r2, r5
 *   @0x24219c mov r1, #1
 *   @0x2421a0 ldr r0, [r4, r3]
 *   @0x2421a4 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2421a8 ldr r1, [pc, #0x1d0]
 *   @0x2421ac mov r3, r6
 *   @0x2421b0 add r1, pc, r1
 *   @0x2421b4 mov r2, r0
 *   @0x2421b8 mov r0, r7
 *   @0x2421bc bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2421c0 ldr r3, [pc, #0x1bc]
 *   @0x2421c4 mov r2, r5
 *   @0x2421c8 mov r1, #1
 *   @0x2421cc ldr r0, [r4, r3]
 *   @0x2421d0 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2421d4 ldr r1, [pc, #0x1ac]
 *   @0x2421d8 mov r3, r6
 *   @0x2421dc add r1, pc, r1
 *   @0x2421e0 mov r2, r0
 *   @0x2421e4 mov r0, r7
 *   @0x2421e8 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2421ec ldr r3, [pc, #0x198]
 *   @0x2421f0 mov r2, r5
 *   @0x2421f4 mov r1, #1
 *   @0x2421f8 ldr r0, [r4, r3]
 *   @0x2421fc bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x242200 ldr r1, [pc, #0x188]
 *   @0x242204 mov r3, r6
 *   @0x242208 add r1, pc, r1
 *   @0x24220c mov r2, r0
 *   @0x242210 mov r0, r7
 *   @0x242214 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x242218 ldr r2, [pc, #0x174]
 *   @0x24221c ldr r3, [r7, #0x4]
 *   @0x242220 ldr r2, [r4, r2]
 *   @0x242224 cmp r3, r5
 *   @0x242228 str r2, [r7, #0x94]
 *   @0x24222c beq 0x242290 <_Z14JS_ObjectSetupv+0x49c>
 *   @0x242230 ldr r1, [r9]
 *   @0x242234 mov r0, r7
 *   @0x242238 str r1, [r3]
 *   @0x24223c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x242240 ldr r1, [r7, #0x4]
 *   @0x242244 cmp r1, #0
 *   @0x242248 movne r3, #6
 *   @0x24224c strne r3, [r1, #0xc]
 *   @0x242250 beq 0x2422a4 <_Z14JS_ObjectSetupv+0x4b0>
 *   @0x242254 ldr r0, [pc, #0x13c]
 *   @0x242258 mov r12, #6
 *   @0x24225c ldr r2, [pc, #0x138]
 *   @0x242260 mov r3, #0
 *   @0x242264 str r12, [r1, #0x8]
 *   @0x242268 ldr r0, [r4, r0]
 *   @0x24226c add r2, pc, r2
 *   @0x242270 ldr r1, [pc, #0x128]
 *   @0x242274 add r2, r2, #2384
 *   @0x242278 add r2, r2, #12
 *   @0x24227c add r1, pc, r1
 *   @0x242280 ldr r0, [r0]
 *   @0x242284 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei>
 *   @0x242288 add sp, sp, #20
 *   @0x24228c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x242290 mov r1, r3
 *   @0x242294 mov r0, r7
 *   @0x242298 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x24229c mov r3, r0
 *   @0x2422a0 b 0x242230 <_Z14JS_ObjectSetupv+0x43c>
 *   @0x2422a4 mov r0, r7
 *   @0x2422a8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x2422ac ldr r1, [r7, #0x4]
 *   @0x2422b0 mov r3, #6
 *   @0x2422b4 cmp r1, #0
 *   @0x2422b8 str r3, [r0, #0xc]
 *   @0x2422bc bne 0x242254 <_Z14JS_ObjectSetupv+0x460>
 *   @0x2422c0 mov r0, r7
 *   @0x2422c4 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x2422c8 mov r1, r0
 *   @0x2422cc b 0x242254 <_Z14JS_ObjectSetupv+0x460>
 *   @0x2422d0 andseq pc, r10, r0, asr #28
 *   @0x2422d4 .word 0xfffff90c
 *   @0x2422d8 subseq r3, r1, r4, ror #24
 *   @0x2422dc ldrsheq r3, [r1], -r12
 *   @0x2422e0 andseq r3, r1, r12, asr #13
 *   @0x2422e4 .word 0xfffff910
 *   @0x2422e8 andeq r0, pc, r0, lsl #13
 *   @0x2422ec .word 0xfffff914
 *   @0x2422f0 andseq r3, r1, r12, lsl #15
 *   @0x2422f4 .word 0xfffff918
 *   @0x2422f8 andseq r3, r1, r0, ror r7
 *   @0x2422fc .word 0xfffff91c
 *   @0x242300 andseq r3, r1, r12, asr #14
 *   @0x242304 .word 0xfffff920
 *   @0x242308 andseq r3, r1, r0, lsr r7
 *   @0x24230c .word 0xfffff924
 *   @0x242310 andseq r3, r1, r4, lsl r7
 *   @0x242314 .word 0xfffff8ac
 *   @0x242318 .word 0xfffff8b0
 *   @0x24231c .word 0xfffff8b4
 *   @0x242320 .word 0xffffc050
 *   @0x242324 .word 0xffffc054
 *   @0x242328 muleq lr, r12, r8
 *   @0x24232c .word 0xfffff928
 *   @0x242330 andseq r3, r1, r0, lsr #13
 *   @0x242334 .word 0xfffff92c
 *   @0x242338 andseq r3, r1, r4, lsl #13
 *   @0x24233c .word 0xfffff930
 *   @0x242340 andseq r3, r1, r4, ror r6
 *   @0x242344 .word 0xfffff934
 *   @0x242348 andseq r3, r1, r12, asr r6
 *   @0x24234c .word 0xfffff938
 *   @0x242350 andseq r3, r1, r8, lsr r6
 *   @0x242354 .word 0xfffff93c
 *   @0x242358 andseq r3, r1, r12, lsl r6
 *   @0x24235c .word 0xfffff940
 *   @0x242360 andseq r3, r1, r4, lsl #12
 *   @0x242364 .word 0xfffff944
 *   @0x242368 andseq r3, r1, r0, ror #11
 *   @0x24236c .word 0xfffff948
 *   @0x242370 ldrheq r3, [r1], -r12
 *   @0x242374 .word 0xfffff94c
 *   @0x242378 andseq r3, r1, r4, lsr #11
 *   @0x24237c .word 0xfffff950
 *   @0x242380 andseq r3, r1, r4, lsl #11
 *   @0x242384 .word 0xfffff954
 *   @0x242388 andseq r3, r1, r4, ror #10
 *   @0x24238c .word 0xfffff958
 *   @0x242390 andseq r3, r1, r8, asr #10
 *   @0x242394 .word 0xfffff95c
 *   @0x242398 .word 0xffffbf64
 *   @0x24239c subseq r3, r1, r4, lsr r8
 *   @0x2423a0 andseq r3, r1, r8, asr r1
 *
 * ══ §17/21 Sprite_Add(char const*, int, bool, bool, bool, bool, int, int)  0x1f114c  size 1448  362 条（0x1f114c..0x1f16f4）
 * @func 0x1f114c 0x1f16f4  size 1448  362 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1f1198→0x7530d8, 0x1f11a0→0x7530d0, 0x1f11d4→0x7530dc, 0x1f12a4→0x533c54, 0x1f1338→0x7530e0
 * 调用序列: MemoryManager::Free(void const*)×3 / MemoryManager::SetLength(void**, unsigned int, char const*, int)×2 / operator new(unsigned int)×2 / 0xb65e0×2 / 0xb65c8 / YYStrDup(char const*) / CSprite::CSprite() / LoadSave::HTTP_Get(char const*, int, int (*)(HTTP_REQ_CONTEXT*, void*, int*), void (*)(HTTP_REQ_CONTEXT*), void*)
 * 字段偏移 top8: 0x4×14 / 0x20×12 / 0x8×11 / 0x2×6 / 0x10×6 / 0x28×3 / 0x2c×3 / 0x30×3
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f114c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1f1150 subs r10, r0, #0
 *   @0x1f1154 ldr r4, [pc, #0x55c]
 *   @0x1f1158 sub sp, sp, #1344
 *   @0x1f115c ldr r0, [pc, #0x558]
 *   @0x1f1160 sub sp, sp, #4
 *   @0x1f1164 add r4, pc, r4
 *   @0x1f1168 mov r6, r3
 *   @0x1f116c ldrb r12, [sp, #0x568]
 *   @0x1f1170 str r1, [sp, #0x28]
 *   @0x1f1174 str r2, [sp, #0x2c]
 *   @0x1f1178 ldr r0, [r4, r0]
 *   @0x1f117c str r12, [sp, #0x30]
 *   @0x1f1180 ldrb r12, [sp, #0x56c]
 *   @0x1f1184 ldr r3, [r0]
 *   @0x1f1188 str r0, [sp, #0x24]
 *   @0x1f118c str r12, [sp, #0x34]
 *   @0x1f1190 str r3, [sp, #0x53c]
 *   @0x1f1194 beq 0x1f16a8 <_Z10Sprite_AddPKcibbbbii+0x55c>
 *   @0x1f1198 ldr r2, [pc, #0x520]
 *   @0x1f119c movw r3, #0x1fe
 *   @0x1f11a0 ldr r0, [pc, #0x51c]
 *   @0x1f11a4 ldr r9, [pc, #0x51c]
 *   @0x1f11a8 ldr r8, [r4, r2]
 *   @0x1f11ac add r9, pc, r9
 *   @0x1f11b0 ldr r1, [r8]
 *   @0x1f11b4 mov r2, r9
 *   @0x1f11b8 add r1, r1, #1
 *   @0x1f11bc str r1, [r8]
 *   @0x1f11c0 ldr r5, [r4, r0]
 *   @0x1f11c4 lsl r1, r1, #2
 *   @0x1f11c8 add r0, r5, #4
 *   @0x1f11cc bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1f11d0 ldr r1, [r8]
 *   @0x1f11d4 ldr r0, [pc, #0x4f0]
 *   @0x1f11d8 mov r2, r9
 *   @0x1f11dc mov r3, #512
 *   @0x1f11e0 add r9, sp, #60
 *   @0x1f11e4 str r1, [r5]
 *   @0x1f11e8 lsl r1, r1, #2
 *   @0x1f11ec ldr r11, [r4, r0]
 *   @0x1f11f0 mov r0, r11
 *   @0x1f11f4 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1f11f8 ldr r3, [r8]
 *   @0x1f11fc ldr r2, [pc, #0x4cc]
 *   @0x1f1200 mov r1, #256
 *   @0x1f1204 sub r3, r3, #1
 *   @0x1f1208 mov r0, r9
 *   @0x1f120c add r2, pc, r2
 *   @0x1f1210 bl 0xb65c8 <snprintf@plt>
 *   @0x1f1214 ldr r3, [r8]
 *   @0x1f1218 mov r0, r9
 *   @0x1f121c ldr r9, [r11]
 *   @0x1f1220 sub r7, r3, #-1073741823
 *   @0x1f1224 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1f1228 str r0, [r9, r7, lsl #2]
 *   @0x1f122c mov r0, #136
 *   @0x1f1230 bl 0x27c524 <_Znwj>
 *   @0x1f1234 mov r9, r0
 *   @0x1f1238 bl 0x1e761c <_ZN7CSpriteC2Ev>
 *   @0x1f123c ldr r3, [r8]
 *   @0x1f1240 mov r1, r10
 *   @0x1f1244 ldr r12, [r5, #0x4]
 *   @0x1f1248 mov r2, #7
 *   @0x1f124c sub r3, r3, #-1073741823
 *   @0x1f1250 ldr r0, [pc, #0x47c]
 *   @0x1f1254 str r9, [r12, r3, lsl #2]
 *   @0x1f1258 add r0, pc, r0
 *   @0x1f125c bl 0xb65e0 <strncmp@plt>
 *   @0x1f1260 cmp r0, #0
 *   @0x1f1264 beq 0x1f1284 <_Z10Sprite_AddPKcibbbbii+0x138>
 *   @0x1f1268 ldr r0, [pc, #0x468]
 *   @0x1f126c mov r1, r10
 *   @0x1f1270 mov r2, #8
 *   @0x1f1274 add r0, pc, r0
 *   @0x1f1278 bl 0xb65e0 <strncmp@plt>
 *   @0x1f127c cmp r0, #0
 *   @0x1f1280 bne 0x1f1468 <_Z10Sprite_AddPKcibbbbii+0x31c>
 *   @0x1f1284 mov r0, #20
 *   @0x1f1288 mov r5, #1
 *   @0x1f128c bl 0x27c524 <_Znwj>
 *   @0x1f1290 cmp r6, #0
 *   @0x1f1294 ldr r2, [sp, #0x30]
 *   @0x1f1298 movne r6, #2
 *   @0x1f129c moveq r6, #0
 *   @0x1f12a0 cmp r2, #0
 *   @0x1f12a4 ldr r3, [pc, #0x430]
 *   @0x1f12a8 ldr r2, [r8]
 *   @0x1f12ac movne r1, #4
 *   @0x1f12b0 moveq r1, #0
 *   @0x1f12b4 sub r2, r2, #1
 *   @0x1f12b8 mov r12, r0
 *   @0x1f12bc ldr r0, [sp, #0x2c]
 *   @0x1f12c0 str r2, [r12]
 *   @0x1f12c4 orr r7, r6, r0
 *   @0x1f12c8 ldr r0, [sp, #0x34]
 *   @0x1f12cc orr r7, r7, r1
 *   @0x1f12d0 ldr r2, [pc, #0x408]
 *   @0x1f12d4 cmp r0, #0
 *   @0x1f12d8 ldr r0, [sp, #0x28]
 *   @0x1f12dc movne r1, #8
 *   @0x1f12e0 moveq r1, #0
 *   @0x1f12e4 str r0, [r12, #0x4]
 *   @0x1f12e8 orr r1, r7, r1
 *   @0x1f12ec ldr r0, [sp, #0x570]
 *   @0x1f12f0 str r1, [r12, #0x10]
 *   @0x1f12f4 ldr r1, [sp, #0x574]
 *   @0x1f12f8 str r0, [r12, #0x8]
 *   @0x1f12fc mov r0, r10
 *   @0x1f1300 str r1, [r12, #0xc]
 *   @0x1f1304 mov r1, #5
 *   @0x1f1308 ldr lr, [r4, r3]
 *   @0x1f130c ldr r3, [pc, #0x3d0]
 *   @0x1f1310 strb r5, [lr]
 *   @0x1f1314 ldr r2, [r4, r2]
 *   @0x1f1318 ldr r3, [r4, r3]
 *   @0x1f131c str r12, [sp]
 *   @0x1f1320 bl 0x18fc68 <_ZN8LoadSave8HTTP_GetEPKciPFiP16HTTP_REQ_CONTEXTPvPiEPFvS3_ES4_>
 *   @0x1f1324 ldr r7, [r8]
 *   @0x1f1328 ldr r3, [r11]
 *   @0x1f132c sub r2, r7, #-1073741823
 *   @0x1f1330 sub r7, r7, #1
 *   @0x1f1334 add r2, r3, r2, lsl #2
 *   @0x1f1338 ldr r3, [pc, #0x3a8]
 *   @0x1f133c ldr r6, [r2]
 *   @0x1f1340 ldr r3, [r4, r3]
 *   @0x1f1344 str r3, [sp, #0x20]
 *   @0x1f1348 ldr r12, [sp, #0x20]
 *   @0x1f134c ldr r3, [r3, #0x4]
 *   @0x1f1350 ldr r2, [r12, #0xc]
 *   @0x1f1354 cmp r3, r2
 *   @0x1f1358 bgt 0x1f151c <_Z10Sprite_AddPKcibbbbii+0x3d0>
 *   @0x1f135c ldr r12, [sp, #0x20]
 *   @0x1f1360 mov r0, r6
 *   @0x1f1364 add r3, r3, #1
 *   @0x1f1368 str r3, [r12, #0x4]
 *   @0x1f136c bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_>
 *   @0x1f1370 ldr r12, [sp, #0x20]
 *   @0x1f1374 ldr r4, [r12, #0x8]
 *   @0x1f1378 ldr r10, [r12, #0x10]
 *   @0x1f137c bic r0, r0, #-2147483648
 *   @0x1f1380 and r3, r0, r4
 *   @0x1f1384 add r2, r3, r3, lsl #1
 *   @0x1f1388 add r2, r10, r2, lsl #2
 *   @0x1f138c ldr r1, [r2, #0x8]
 *   @0x1f1390 cmp r1, #0
 *   @0x1f1394 beq 0x1f1438 <_Z10Sprite_AddPKcibbbbii+0x2ec>
 *   @0x1f1398 ldr r12, [sp, #0x20]
 *   @0x1f139c mov r5, #0
 *   @0x1f13a0 ldr r11, [r12]
 *   @0x1f13a4 b 0x1f13e8 <_Z10Sprite_AddPKcibbbbii+0x29c>
 *   @0x1f13a8 ldr r9, [r2]
 *   @0x1f13ac ldr r5, [r2, #0x4]
 *   @0x1f13b0 str r0, [r2, #0x8]
 *   @0x1f13b4 mov r0, r1
 *   @0x1f13b8 str r6, [r2]
 *   @0x1f13bc mov r6, r9
 *   @0x1f13c0 str r7, [r2, #0x4]
 *   @0x1f13c4 mov r7, r5
 *   @0x1f13c8 add r3, r3, #1
 *   @0x1f13cc add r5, r12, #1
 *   @0x1f13d0 and r3, r3, r4
 *   @0x1f13d4 add r2, r3, r3, lsl #1
 *   @0x1f13d8 add r2, r10, r2, lsl #2
 *   @0x1f13dc ldr r1, [r2, #0x8]
 *   @0x1f13e0 cmp r1, #0
 *   @0x1f13e4 beq 0x1f1438 <_Z10Sprite_AddPKcibbbbii+0x2ec>
 *   @0x1f13e8 add r12, r3, r11
 *   @0x1f13ec and r9, r1, r4
 *   @0x1f13f0 rsb r12, r9, r12
 *   @0x1f13f4 and r12, r12, r4
 *   @0x1f13f8 cmp r12, r5
 *   @0x1f13fc blt 0x1f13a8 <_Z10Sprite_AddPKcibbbbii+0x25c>
 *   @0x1f1400 movne r12, r5
 *   @0x1f1404 bne 0x1f13c8 <_Z10Sprite_AddPKcibbbbii+0x27c>
 *   @0x1f1408 cmp r1, r0
 *   @0x1f140c bne 0x1f13c8 <_Z10Sprite_AddPKcibbbbii+0x27c>
 *   @0x1f1410 ldr r5, [r2]
 *   @0x1f1414 cmp r6, r5
 *   @0x1f1418 bne 0x1f13c8 <_Z10Sprite_AddPKcibbbbii+0x27c>
 *   @0x1f141c ldr r12, [sp, #0x20]
 *   @0x1f1420 str r1, [r2, #0x8]
 *   @0x1f1424 ldr r3, [r12, #0x4]
 *   @0x1f1428 stm r2, {r6, r7}
 *   @0x1f142c sub r3, r3, #1
 *   @0x1f1430 str r3, [r12, #0x4]
 *   @0x1f1434 b 0x1f1440 <_Z10Sprite_AddPKcibbbbii+0x2f4>
 *   @0x1f1438 stm r2, {r6, r7}
 *   @0x1f143c str r0, [r2, #0x8]
 *   @0x1f1440 ldr r0, [r8]
 *   @0x1f1444 sub r0, r0, #1
 *   @0x1f1448 ldr r12, [sp, #0x24]
 *   @0x1f144c ldr r2, [sp, #0x53c]
 *   @0x1f1450 ldr r3, [r12]
 *   @0x1f1454 cmp r2, r3
 *   @0x1f1458 bne 0x1f16b0 <_Z10Sprite_AddPKcibbbbii+0x564>
 *   @0x1f145c add sp, sp, #1344
 *   @0x1f1460 add sp, sp, #4
 *   @0x1f1464 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1f1468 mov r0, r10
 *   @0x1f146c bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0x1f1470 cmp r0, #0
 *   @0x1f1474 bne 0x1f162c <_Z10Sprite_AddPKcibbbbii+0x4e0>
 *   @0x1f1478 mov r0, r10
 *   @0x1f147c bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0x1f1480 cmp r0, #0
 *   @0x1f1484 beq 0x1f169c <_Z10Sprite_AddPKcibbbbii+0x550>
 *   @0x1f1488 add r9, sp, #316
 *   @0x1f148c mov r2, r10
 *   @0x1f1490 mov r1, #1024
 *   @0x1f1494 mov r0, r9
 *   @0x1f1498 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc>
 *   @0x1f149c mov r0, r9
 *   @0x1f14a0 bl 0x215008 <_Z14ExtractFileExtPKc>
 *   @0x1f14a4 ldr r1, [pc, #0x240]
 *   @0x1f14a8 add r1, pc, r1
 *   @0x1f14ac mov r10, r0
 *   @0x1f14b0 bl 0xb66d0 <strcasecmp@plt>
 *   @0x1f14b4 cmp r0, #0
 *   @0x1f14b8 mov r0, r10
 *   @0x1f14bc bne 0x1f1644 <_Z10Sprite_AddPKcibbbbii+0x4f8>
 *   @0x1f14c0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f14c4 ldr r12, [r8]
 *   @0x1f14c8 ldr r0, [r5, #0x4]
 *   @0x1f14cc mov r1, r9
 *   @0x1f14d0 sub r12, r12, #-1073741823
 *   @0x1f14d4 ldr r2, [sp, #0x570]
 *   @0x1f14d8 ldr r3, [sp, #0x574]
 *   @0x1f14dc ldr r0, [r0, r12, lsl #2]
 *   @0x1f14e0 bl 0x1e9b68 <_ZN7CSprite15LoadFromYYSFileEPKcii>
 *   @0x1f14e4 cmp r0, #0
 *   @0x1f14e8 beq 0x1f169c <_Z10Sprite_AddPKcibbbbii+0x550>
 *   @0x1f14ec ldr r0, [r8]
 *   @0x1f14f0 ldr r2, [r5, #0x4]
 *   @0x1f14f4 ldr r12, [r11]
 *   @0x1f14f8 sub r3, r0, #-1073741823
 *   @0x1f14fc sub r0, r0, #1
 *   @0x1f1500 ldr r1, [r2, r3, lsl #2]
 *   @0x1f1504 add r2, r12, r3, lsl #2
 *   @0x1f1508 ldr r3, [r12, r3, lsl #2]
 *   @0x1f150c mov r7, r0
 *   @0x1f1510 str r0, [r1, #0x60]
 *   @0x1f1514 str r3, [r1, #0x5c]
 *   @0x1f1518 b 0x1f1338 <_Z10Sprite_AddPKcibbbbii+0x1ec>
 *   @0x1f151c ldr r9, [r12]
 *   @0x1f1520 mov r3, #1
 *   @0x1f1524 ldr r1, [pc, #0x1c4]
 *   @0x1f1528 mov r2, #70
 *   @0x1f152c ldr r5, [r12, #0x10]
 *   @0x1f1530 lsl r0, r9, r3
 *   @0x1f1534 add r1, pc, r1
 *   @0x1f1538 add r4, r0, r9, lsl #2
 *   @0x1f153c str r0, [r12]
 *   @0x1f1540 sub r0, r0, #1
 *   @0x1f1544 str r0, [r12, #0x8]
 *   @0x1f1548 lsl r4, r4, #2
 *   @0x1f154c mov r0, r4
 *   @0x1f1550 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1f1554 ldr r12, [sp, #0x20]
 *   @0x1f1558 mov r2, r4
 *   @0x1f155c mov r1, #0
 *   @0x1f1560 str r0, [r12, #0x10]
 *   @0x1f1564 bl 0xb65b0 <memset@plt>
 *   @0x1f1568 ldr r12, [sp, #0x20]
 *   @0x1f156c vldr s15, [pc, #320]
 *   @0x1f1570 mov r1, #0
 *   @0x1f1574 ldr r2, [r12]
 *   @0x1f1578 str r1, [r12, #0x4]
 *   @0x1f157c cmp r2, r1
 *   @0x1f1580 vmov s13, r2
 *   @0x1f1584 vcvt.f32.s32 s14, s13
 *   @0x1f1588 vmul.f32 s15, s14, s15
 *   @0x1f158c vcvt.s32.f32 s15, s15
 *   @0x1f1590 vstr s15, [r12, #12]
 *   @0x1f1594 ble 0x1f15b8 <_Z10Sprite_AddPKcibbbbii+0x46c>
 *   @0x1f1598 ldr r12, [sp, #0x20]
 *   @0x1f159c add r2, r2, r2, lsl #1
 *   @0x1f15a0 ldr r3, [r12, #0x10]
 *   @0x1f15a4 add r2, r3, r2, lsl #2
 *   @0x1f15a8 str r1, [r3, #0x8]
 *   @0x1f15ac add r3, r3, #12
 *   @0x1f15b0 cmp r3, r2
 *   @0x1f15b4 bne 0x1f15a8 <_Z10Sprite_AddPKcibbbbii+0x45c>
 *   @0x1f15b8 cmp r9, #0
 *   @0x1f15bc ble 0x1f15f4 <_Z10Sprite_AddPKcibbbbii+0x4a8>
 *   @0x1f15c0 ldr r11, [sp, #0x20]
 *   @0x1f15c4 mov r4, r5
 *   @0x1f15c8 mov r10, #0
 *   @0x1f15cc ldr r3, [r4, #0x8]
 *   @0x1f15d0 cmp r3, #0
 *   @0x1f15d4 ble 0x1f15e4 <_Z10Sprite_AddPKcibbbbii+0x498>
 *   @0x1f15d8 mov r0, r11
 *   @0x1f15dc ldm r4, {r1, r2}
 *   @0x1f15e0 bl 0xd261c <_ZN8CHashMapIPKciLi7EE6InsertES1_i>
 *   @0x1f15e4 add r10, r10, #1
 *   @0x1f15e8 add r4, r4, #12
 *   @0x1f15ec cmp r10, r9
 *   @0x1f15f0 bne 0x1f15cc <_Z10Sprite_AddPKcibbbbii+0x480>
 *   @0x1f15f4 mov r0, r5
 *   @0x1f15f8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f15fc ldr r12, [sp, #0x20]
 *   @0x1f1600 vldr s15, [pc, #172]
 *   @0x1f1604 ldr r12, [r12]
 *   @0x1f1608 str r12, [sp, #0x1c]
 *   @0x1f160c vldr s13, [sp, #28]
 *   @0x1f1610 vcvt.f32.s32 s14, s13
 *   @0x1f1614 ldr r12, [sp, #0x20]
 *   @0x1f1618 ldr r3, [r12, #0x4]
 *   @0x1f161c vmul.f32 s15, s14, s15
 *   @0x1f1620 vcvt.s32.f32 s15, s15
 *   @0x1f1624 vstr s15, [r12, #12]
 *   @0x1f1628 b 0x1f135c <_Z10Sprite_AddPKcibbbbii+0x210>
 *   @0x1f162c add r9, sp, #316
 *   @0x1f1630 mov r2, r10
 *   @0x1f1634 mov r1, #1024
 *   @0x1f1638 mov r0, r9
 *   @0x1f163c bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x1f1640 b 0x1f149c <_Z10Sprite_AddPKcibbbbii+0x350>
 *   @0x1f1644 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f1648 ldr r12, [r8]
 *   @0x1f164c ldr r0, [r5, #0x4]
 *   @0x1f1650 eor lr, r6, #1
 *   @0x1f1654 sub r12, r12, #-1073741823
 *   @0x1f1658 mov r1, r9
 *   @0x1f165c ldr r2, [sp, #0x28]
 *   @0x1f1660 ldr r0, [r0, r12, lsl #2]
 *   @0x1f1664 ldr r12, [sp, #0x30]
 *   @0x1f1668 ldr r3, [sp, #0x2c]
 *   @0x1f166c str r6, [sp]
 *   @0x1f1670 str r12, [sp, #0x4]
 *   @0x1f1674 ldr r12, [sp, #0x34]
 *   @0x1f1678 str lr, [sp, #0x14]
 *   @0x1f167c str r12, [sp, #0x8]
 *   @0x1f1680 ldr r12, [sp, #0x570]
 *   @0x1f1684 str r12, [sp, #0xc]
 *   @0x1f1688 ldr r12, [sp, #0x574]
 *   @0x1f168c str r12, [sp, #0x10]
 *   @0x1f1690 bl 0x1e7270 <_ZN7CSprite12LoadFromFileEPKcibbbbiib>
 *   @0x1f1694 cmp r0, #0
 *   @0x1f1698 bne 0x1f14ec <_Z10Sprite_AddPKcibbbbii+0x3a0>
 *   @0x1f169c ldr r3, [r8]
 *   @0x1f16a0 sub r3, r3, #1
 *   @0x1f16a4 str r3, [r8]
 *   @0x1f16a8 mvn r0, #0
 *   @0x1f16ac b 0x1f1448 <_Z10Sprite_AddPKcibbbbii+0x2fc>
 *   @0x1f16b0 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x1f16b4 svclo #0x19999a
 *   @0x1f16b8 eoreq r0, r0, r12, ror #21
 *   @0x1f16bc .word 0xffffbd00
 *   @0x1f16c0 .word 0xfffff1c0
 *   @0x1f16c4 .word 0xfffff1b8
 *   @0x1f16c8 mulseq r6, r4, r4
 *   @0x1f16cc .word 0xfffff1bc
 *   @0x1f16d0 andseq r1, r6, r12, ror #8
 *   @0x1f16d4 andseq pc, r3, r8, lsl #17
 *   @0x1f16d8 andseq pc, r3, r4, ror r8
 *   @0x1f16dc .word 0xffffbd04
 *   @0x1f16e0 .word 0xfffff1c8
 *   @0x1f16e4 .word 0xfffff1cc
 *   @0x1f16e8 .word 0xfffff1c4
 *   @0x1f16ec andseq r1, r6, r0, ror #3
 *   @0x1f16f0 ldrsheq pc, [r3], -r12
 *
 * ══ §18/21 png_set_quantize  0x2a81a4  size 1426  357 条（0x2a81a4..0x2a8736）
 * @func 0x2a81a4 0x2a8738  size 1428  357 条
 * 部分覆盖: 本节 357/628 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_free×2 / 0x46776c / png_malloc / png_set_quantize+0x17c / 0xff348360 / 0xff59038c / 0xff52afc4 / png_malloc_warn
 * 字段偏移 top8: 0x14×3 / 0x2×3 / 0x10×3 / 0x18×3 / 0x1c×2 / 0x20×2 / 0x58×1 / 0x24×1
 * VFP 指令 1 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a81a4 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2a81a8 sub sp, #0x34
 *   @0x2a81ac mov r6, r1
 *   @0x2a81b0 mov r4, r0
 *   @0x2a81b4 ldr r7, [sp, #0x58]
 *   @0x2a81b8 cmp r0, #0x0
 *   @0x2a81bc .word 0xf8d082b9
 *   @0x2a81c0 .word 0xf0433134
 *   @0x2a81c4 .word 0xf8c00340
 *   @0x2a81c8 tstlt r10, r4, lsr r1
 *   @0x2a81cc ldr r3, [sp, #0x14]
 *   @0x2a81d0 bgt 0x2a81ee <png_set_quantize+0x4a>
 *   @0x2a81d4 mov r1, r5
 *   @0x2a81d8 blls 0x46776c <g_RomDisk+0x6ff4c>
 *   @0x2a81dc str.w r0, [r4, #0x2b4]
 *   @0x2a81e0 cmp r3, r5
 *   @0x2a81e4 ldr.w r2, [r4, #0x2b4]
 *   @0x2a81e8 strb r3, [r2, r3]
 *   @0x2a81ec b 0x2a81e0 <png_set_quantize+0x3c>
 *   @0x2a81f0 mov r1, r5
 *   @0x2a81f4 beq.w 0x2a83ca <png_set_quantize+0x226>
 *   @0x2a81f8 bl 0x2a6ca0 <png_malloc>
 *   @0x2a81fc movs r3, #0x0
 *   @0x2a8200 adcmi r0, r11, #248, #4
 *   @0x2a8204 bge 0x2a8210 <png_set_quantize+0x6c>
 *   @0x2a8208 ldrbpl r2, [r3], #760
 *   @0x2a820c adds r3, #0x1
 *   @0x2a8210 subs r2, r5, #0x1
 *   @0x2a8214 ldrbmi r10, [r2, #-0x14]
 *   @0x2a8218 bge 0x2a822a <png_set_quantize+0x86>
 *   @0x2a821c cbnz r7, 0x2a826c <png_set_quantize+0xc8>
 *   @0x2a8220 mov r1, r5
 *   @0x2a8224 mov.w lr, #0x3
 *   @0x2a8228 b 0x2a82bc <png_set_quantize+0x118>
 *   @0x2a822c mov.w lr, #0x1
 *   @0x2a8230 cmp r3, r2
 *   @0x2a8234 ldr.w r0, [r4, #0x2f8]
 *   @0x2a8238 adds r1, r3, #0x1
 *   @0x2a823c .word 0xf810c003
 *   @0x2a8240 rfeda r7!
 *   @0x2a8244 rfeda r7!
 *   @0x2a8248 strbmi r9, [r10, #0x18]
 *   @0x2a824c bhs 0x2a825e <png_set_quantize+0xba>
 *   @0x2a8250 .word 0xf04f8003
 *   @0x2a8254 .word 0xf8d40e00
 *   @0x2a8258 .word 0xf80332f8
 *   @0x2a825c strmi r12, [r11], -r1
 *   @0x2a8260 b 0x2a8230 <png_set_quantize+0x8c>
 *   @0x2a8264 bicsle r0, r8, r0, lsl #30
 *   @0x2a8268 subs r2, #0x1
 *   @0x2a826c movs r3, #0x0
 *   @0x2a8270 ldr r7, [sp, #0x14]
 *   @0x2a8274 bge 0x2a82ca <png_set_quantize+0x126>
 *   @0x2a8278 .word 0xf8dd12f8
 *   @0x2a827c stclpl p0, c11, [r8], {20}
 *   @0x2a8280 cmp r0, r11
 *   @0x2a8284 subs r5, #0x1
 *   @0x2a8288 stclpl p0, c12, [r8, #-80]
 *   @0x2a828c cmp r0, r12
 *   @0x2a8290 mla r1, r2, r5, r6
 *   @0x2a8294 mul r0, r2, r3
 *   @0x2a8298 ldrh.w lr, [r1]
 *   @0x2a829c adds r7, r6, r0
 *   @0x2a82a0 stmvc r9, {sp, lr, pc}
 *   @0x2a82a4 strb r1, [r7, #0x2]
 *   @0x2a82a8 b 0x2a8270 <png_set_quantize+0xcc>
 *   @0x2a82ac .word 0xf8dd02f8
 *   @0x2a82b0 stcpl p0, c10, [r7], {20}
 *   @0x2a82b4 cmp r7, r10
 *   @0x2a82b8 adds r2, #0x1
 *   @0x2a82bc ldr.w r12, [sp, #0x14]
 *   @0x2a82c0 cmp r2, r12
 *   @0x2a82c4 movs r3, #0x0
 *   @0x2a82c8 blt 0x2a8320 <png_set_quantize+0x17c>
 *   @0x2a82cc ldr.w r1, [r4, #0x2f8]
 *   @0x2a82d0 bl 0x2a6cfc <png_free>
 *   @0x2a82d4 movs r3, #0x0
 *   @0x2a82d8 ldrsh r3, [r8, r8]
 *   @0x2a82dc subs r1, #0x1
 *   @0x2a82e0 mcrrpl p0, #0x1, r11, r7, c4
 *   @0x2a82e4 cmp r7, r11
 *   @0x2a82e8 mul r7, lr, r1
 *   @0x2a82ec ldrh.w r10, [r3]
 *   @0x2a82f0 adds r0, r6, r7
 *   @0x2a82f4 .word 0xf8909007
 *   @0x2a82f8 .word 0xf890c002
 *   @0x2a82fc .word 0xf8268001
 *   @0x2a8300 ldmvc pc, {r0, r1, r2, sp, pc}
 *   @0x2a8304 strb r7, [r0, #0x2]
 *   @0x2a8308 .word 0xf8839000
 *   @0x2a830c .word 0xf8838001
 *   @0x2a8310 .word 0xf8d4c002
 *   @0x2a8314 strbpl r0, [r2], #-692
 *   @0x2a8318 ldr.w r0, [r4, #0x2b4]
 *   @0x2a831c strb r1, [r0, r2]
 *   @0x2a8320 ldr.w r2, [r4, #0x2b4]
 *   @0x2a8324 ldr r7, [sp, #0x14]
 *   @0x2a8328 ldclpl p9, c0, [r2], {3}
 *   @0x2a832c cmp r2, r7
 *   @0x2a8330 add.w r2, r2, r2, lsl #1
 *   @0x2a8334 ldrb r0, [r6]
 *   @0x2a8338 movs r7, #0x0
 *   @0x2a833c .word 0xf891e002
 *   @0x2a8340 ldmdavc r2!, {r0, lr, pc} ^
 *   @0x2a8344 rsb r0, r0, lr
 *   @0x2a8348 cmp r0, #0x0
 *   @0x2a834c rsblt r0, r0, #0
 *   @0x2a8350 bl 0xff348360 <b2_toiTime+0xfffffffffebeeebc>
 *   @0x2a8354 .word 0x2101020c
 *   @0x2a8358 cmp r2, #0x0
 *   @0x2a835c rsblt r2, r2, #0
 *   @0x2a8360 ldrb r2, [r6, #0x2]
 *   @0x2a8364 bhs 0x2a8b8c <png_do_unpack+0x5e>
 *   @0x2a8368 it lt
 *   @0x2a836c add r0, r2
 *   @0x2a8370 ldr.w r10, [sp, #0x14]
 *   @0x2a8374 cmp r1, r10
 *   @0x2a8378 ldrb.w r11, [r2, #0x3]
 *   @0x2a837c adds r2, #0x3
 *   @0x2a8380 bl 0xff59038c <b2_toiTime+0xfffffffffee36ee8>
 *   @0x2a8384 bl 0xff52afc4 <b2_toiTime+0xfffffffffedd1b20>
 *   @0x2a8388 .word 0xf1bb0a0c
 *   @0x2a838c svclt #0xb80f00
 *   @0x2a8390 rsblt.w r11, r11, #0x0
 *   @0x2a8394 cmp.w r10, #0x0
 *   @0x2a8398 it lt
 *   @0x2a839c ldrbmi r0, [r3], #2560
 *   @0x2a83a0 ldrb.w r10, [r2, #0x2]
 *   @0x2a83a4 rsb r10, r10, r8
 *   @0x2a83a8 cmp.w r10, #0x0
 *   @0x2a83ac it lt
 *   @0x2a83b0 ldrbmi r0, [r10], #2560
 *   @0x2a83b4 cmp r10, r0
 *   @0x2a83b8 movge r10, r0
 *   @0x2a83bc mov r0, r10
 *   @0x2a83c0 b 0x2a8370 <png_set_quantize+0x1cc>
 *   @0x2a83c4 movwlo r7, #0x1000
 *   @0x2a83c8 b 0x2a82c6 <png_set_quantize+0x122>
 *   @0x2a83cc strtmi pc, [r9], -r9, ror #24
 *   @0x2a83d0 str.w r0, [r4, #0x2fc]
 *   @0x2a83d4 mov r0, r4
 *   @0x2a83d8 .word 0xf8c4fc63
 *   @0x2a83dc adcmi r0, pc, #0, #6
 *   @0x2a83e0 bge 0x2a83f4 <png_set_quantize+0x250>
 *   @0x2a83e4 rscslt r2, r11, #252, #4
 *   @0x2a83e8 strb r3, [r2, r7]
 *   @0x2a83ec ldrbpl r2, [r3, #0x300]
 *   @0x2a83f0 adds r7, #0x1
 *   @0x2a83f4 mov r0, r4
 *   @0x2a83f8 .word 0xf7fe4104
 *   @0x2a83fc strtmi pc, [pc], -sp, ror #24
 *   @0x2a8400 mov.w r8, #0x0
 *   @0x2a8404 mov.w r11, #0x60
 *   @0x2a8408 str.w r11, [sp, #0x20]
 *   @0x2a840c str r0, [sp, #0x1c]
 *   @0x2a8410 mov.w r10, #0x0
 *   @0x2a8414 subs r2, r7, #0x1
 *   @0x2a8418 ldr r3, [sp, #0x24]
 *   @0x2a841c bge 0x2a84b2 <png_set_quantize+0x30e>
 *   @0x2a8420 strbmi r0, [r11], r1, lsl #20
 *   @0x2a8424 add.w r12, r10, #0xffffffff
 *   @0x2a8428 mov r3, r10
 *   @0x2a842c beq 0x2a84a6 <png_set_quantize+0x302>
 *   @0x2a8430 .word 0xf8992003
 *   @0x2a8434 .word 0xf8991000
 *   @0x2a8438 bne 0xfe4e8444 <b2_toiTime+0xfffffffffdd8efa0>
 *   @0x2a843c ldrb.w r2, [r11, #0x4]
 *   @0x2a8440 cmp r1, #0x0
 *   @0x2a8444 rsblt r1, r1, #0
 *   @0x2a8448 ldrb.w r0, [r9, #0x2]
 *   @0x2a844c cmp r2, #0x0
 *   @0x2a8450 rsblt r2, r2, #0
 *   @0x2a8454 ldrb.w r1, [r11, #0x5]
 *   @0x2a8458 subs r1, r0, r1
 *   @0x2a845c cmp r1, #0x0
 *   @0x2a8460 rsblt r1, r1, #0
 *   @0x2a8464 cmp r2, r0
 *   @0x2a8468 mov r0, r4
 *   @0x2a846c str r2, [sp, #0x10]
 *   @0x2a8470 str.w r12, [sp, #0xc]
 *   @0x2a8474 bl 0x2a6d16 <png_malloc_warn>
 *   @0x2a8478 ldr r2, [sp, #0x10]
 *   @0x2a847c ldr.w r12, [sp, #0xc]
 *   @0x2a8480 mov r8, r0
 *   @0x2a8484 beq.w 0x2a872a <png_set_quantize+0x586>
 *   @0x2a8488 ldr r0, [sp, #0x1c]
 *   @0x2a848c .word 0xf8881022
 *   @0x2a8490 .word 0xf888c004
 *   @0x2a8494 .word 0xf8c83005
 *   @0x2a8498 .word 0xf8401000
 *   @0x2a849c movwlo r8, #0x1022
 *   @0x2a84a0 add.w r11, r11, #0x3
 *   @0x2a84a4 b 0x2a842a <png_set_quantize+0x286>
 *   @0x2a84a8 .word 0xf1b80903
 *   @0x2a84ac .word 0xd1b30f00
 *   @0x2a84b0 b 0x2a872a <png_set_quantize+0x586>
 *   @0x2a84b4 rsbsle r0, r0, r0, lsl #30
 *   @0x2a84b8 movs r0, #0x0
 *   @0x2a84bc ldr.w r1, [r2, r0, lsl #2]
 *   @0x2a84c0 cmp r1, #0x0
 *   @0x2a84c4 ldr.w r2, [r4, #0x2fc]
 *   @0x2a84c8 ldrb.w lr, [r1, #0x4]
 *   @0x2a84cc ldrb.w r3, [r2, lr]
 *   @0x2a84d0 cmp r3, r7
 *   @0x2a84d4 ldrb.w r11, [r1, #0x5]
 *   @0x2a84d8 ldrb.w r3, [r2, r11]
 *   @0x2a84dc cmp r3, r7
 *   @0x2a84e0 lsls r3, r7, #0x1f
 *   @0x2a84e4 .word 0xf04f37ff
 *   @0x2a84e8 svclt #0x560a03
 *   @0x2a84ec movpl r3, r11
 *   @0x2a84f0 movpl r11, lr
 *   @0x2a84f4 blx 0x56050a <g_SWFlineaavertbuff+0xd442>
 *   @0x2a84f8 bl 0x640d1c <g_SWFaavertbuff+0x6dc54>
 *   @0x2a84fc bl 0x42be3c <g_RomDisk+0x3461c>
 *   @0x2a8500 rfeia r2!
 *   @0x2a8504 .word 0xf8269000
 *   @0x2a8508 ldmvc r2, {r1, r2, r3, r12, pc}
 *   @0x2a850c strb.w r2, [r12, #0x2]
 *   @0x2a8510 ldr r2, [sp, #0x18]
 *   @0x2a8514 ldr.w lr, [r4, #0x2fc]
 *   @0x2a8518 ldr.w r2, [r4, #0x300]
 *   @0x2a851c ldrb.w r12, [lr, r3]
 *   @0x2a8520 ldrb r2, [r2, r7]
 *   @0x2a8524 .word 0xf8d4c002
 *   @0x2a8528 .word 0xf8d4e300
 *   @0x2a852c .word 0xf81e22fc
 *   @0x2a8530 ldclpl p0, c12, [r2], {7}
 *   @0x2a8534 strb.w r12, [lr, r2]
 *   @0x2a8538 ldr.w r2, [r4, #0x2fc]
 *   @0x2a853c strb r7, [r2, r3]
 *   @0x2a8540 ldrbpl r2, [r3, #0x300]
 *   @0x2a8544 b 0x2a8586 <png_set_quantize+0x3e2>
 *   @0x2a8548 strmi lr, [lr, #0x18]!
 *   @0x2a854c bge 0x2a8514 <png_set_quantize+0x370>
 *   @0x2a8550 .word 0xf8d4c2fc
 *   @0x2a8554 .word 0xf81c22b4
 *   @0x2a8558 .word 0xf8129003
 *   @0x2a855c strbmi r10, [r10, #0xe]
 *   @0x2a8560 itt eq
 *   @0x2a8564 .word 0xf802c00b
 *   @0x2a8568 .word 0xf8d4c00e
 *   @0x2a856c .word 0xf81cc2b4
 *   @0x2a8570 adcsmi r2, r10, #14
 *   @0x2a8574 bne 0x2a8580 <png_set_quantize+0x3dc>
 *   @0x2a8578 ldclpl p2, c2, [r2], {252}
 *   @0x2a857c strb.w r2, [r12, lr]
 *   @0x2a8580 add.w lr, lr, #0x1
 *   @0x2a8584 b 0x2a854a <png_set_quantize+0x3a6>
 *   @0x2a8588 cmp r7, r3
 *   @0x2a858c ldr r1, [r1]
 *   @0x2a8590 ldr.w r10, [sp, #0x20]
 *   @0x2a8594 adds r0, #0x1
 *   @0x2a8598 ble 0x2a84ba <png_set_quantize+0x316>
 *   @0x2a859c .word 0xf6400900
 *   @0x2a85a0 strbmi r4, [r11], -r4, lsl #22
 *   @0x2a85a4 ldr.w r12, [sp, #0x1c]
 *   @0x2a85a8 ldr.w r1, [r12, r9]
 *   @0x2a85ac cbz r1, 0x2a85c6 <png_set_quantize+0x422>
 *   @0x2a85b0 strtmi r8, [r0], -r0
 *   @0x2a85b4 str r3, [sp, #0x8]
 *   @0x2a85b8 blls 0x367444 <_ZTS12CDS_Priority+0x949c>
 *   @0x2a85bc cmp.w r8, #0x0
 *   @0x2a85c0 beq 0x2a85c6 <png_set_quantize+0x422>
 *   @0x2a85c4 b 0x2a85ae <png_set_quantize+0x40a>
 *   @0x2a85c8 mov.w r10, #0x0
 *   @0x2a85cc str.w r3, [r2, r9]
 *   @0x2a85d0 add.w r9, r9, #0x4
 *   @0x2a85d4 cmp r9, r11
 *   @0x2a85d8 ldr.w r11, [sp, #0x14]
 *   @0x2a85dc ldr r3, [sp, #0x20]
 *   @0x2a85e0 add.w r3, r3, #0x60
 *   @0x2a85e4 str r3, [sp, #0x20]
 *   @0x2a85e8 sadd16mi r10, r1, r2
 *   @0x2a85ec mov r0, r4
 *   @0x2a85f0 strtmi pc, [r0], -r5, lsl #23
 *   @0x2a85f4 ldr.w r1, [r4, #0x300]
 *   @0x2a85f8 bl 0x2a6cfc <png_free>
 *   @0x2a85fc mov r0, r4
 *   @0x2a8600 .word 0xf7fe12fc
 *   @0x2a8604 .word 0xf8c4fb7b
 *   @0x2a8608 .word 0xf8c4a300
 *   @0x2a860c stcls p2, c10, [r5, #-1008]
 *   @0x2a8610 ldr.w r3, [r4, #0x1d8]
 *   @0x2a8614 cbnz r3, 0x2a861a <png_set_quantize+0x476>
 *   @0x2a8618 bls 0x440d80 <g_RomDisk+0x49560>
 *   @0x2a861c strh.w r5, [r4, #0x1dc]
 *   @0x2a8620 cmp r2, #0x0
 *   @0x2a8624 vst4.32 {d24, d25, d26, d27}, [pc], r5
 *   @0x2a8628 strtmi r4, [r0], -r0, lsl #2
 *   @0x2a862c bl 0x2a6cd8 <png_calloc>
 *   @0x2a8630 mov.w r1, #0x8000
 *   @0x2a8634 str.w r0, [r4, #0x2b0]
 *   @0x2a8638 mov r0, r4
 *   @0x2a863c mvnshs pc, r1, lsr r11
 *   @0x2a8640 mov.w r2, #0x8000
 *   @0x2a8644 mov r9, r0
 *   @0x2a8648 .word 0xf04fefb4
 *   @0x2a864c strbtmi r0, [r0], r0, lsl #24
 *   @0x2a8650 cmp r8, r5
 *   @0x2a8654 ldrb.w r3, [r6, r12]
 *   @0x2a8658 lsrs r3, r3, #0x3
 *   @0x2a865c add.w r3, r6, r12
 *   @0x2a8660 ldrb r2, [r3, #0x1]
 *   @0x2a8664 lsrs r2, r2, #0x3
 *   @0x2a8668 lsrs r3, r3, #0x3
 *   @0x2a866c movs r3, #0x0
 *   @0x2a8670 cmp r3, r7
 *   @0x2a8674 rsb r10, r7, r3
 *   @0x2a8678 str.w r10, [sp, #0x4]
 *   @0x2a867c b 0x2a868a <png_set_quantize+0x4e6>
 *   @0x2a8680 bl 0xff3946d8 <b2_toiTime+0xfffffffffec3b234>
 *   @0x2a8684 .word 0xf8cd0b0b
 *   @0x2a8688 andhs r11, r0, #4
 *   @0x2a868c lsls r0, r3, #0xa
 *   @0x2a8690 ldr r1, [sp, #0x18]
 *   @0x2a8694 addmi r10, r10, #4
 *   @0x2a8698 ldr.w r11, [sp, #0x4]
 *   @0x2a869c itee gt
 *   @0x2a86a0 svcls #0x60002
 *   @0x2a86a4 rsble r0, r2, r7
 *   @0x2a86a8 movs r7, #0x0
 *   @0x2a86ac cmp r0, r11
 *   @0x2a86b0 movge r11, r0
 *   @0x2a86b4 str.w r10, [sp, #0x24]
 *   @0x2a86b8 orr.w r0, r0, r2, lsl #5
 *   @0x2a86bc str.w r11, [sp, #0x28]
 *   @0x2a86c0 str r0, [sp, #0x2c]
 *   @0x2a86c4 stmdbls r11, {r2, r3, r4, sp, pc}
 *   @0x2a86c8 cmp r7, r10
 *   @0x2a86cc stmdbls r10, {r0}
 *   @0x2a86d0 itet le
 *   @0x2a86d4 bl 0xff55474c <b2_toiTime+0xfffffffffedfb2a8>
 *   @0x2a86d8 bl 0xff46aefc <b2_toiTime+0xfffffffffed11a58>
 *   @0x2a86dc .word 0xf8dd0a0b
 *   @0x2a86e0 strmi r11, [r10, #0x24]
 *   @0x2a86e4 ite ge
 *   @0x2a86e8 addlt r11, r1
 *   @0x2a86ec ldrb.w r11, [r9, r0]
 *   @0x2a86f0 cmp r10, r11
 *   @0x2a86f4 strb.w r10, [r9, r0]
 *   @0x2a86f8 ldr.w r1, [r4, #0x2b0]
 *   @0x2a86fc strb.w r8, [r1, r0]
 *   @0x2a8700 adds r7, #0x1
 *   @0x2a8704 bne 0x2a86c2 <png_set_quantize+0x51e>
 *   @0x2a8708 cmp r2, #0x20
 *   @0x2a870c adds r3, #0x1
 *   @0x2a8710 bne 0x2a866e <png_set_quantize+0x4ca>
 *   @0x2a8714 .word 0xf10c0801
 *   @0x2a8718 ldr r0, [r9, r3, lsl #24]
 *   @0x2a871c mov r0, r4
 *   @0x2a8720 add sp, #0x34
 *   @0x2a8724 .word 0xf7fe4ff0
 *   @0x2a8728 .word 0xf04fbae9
 *   @0x2a872c ldr r0, [r4, -r0, lsl #16]!
 *   @0x2a8730 add sp, #0x34
 *   @0x2a8734 strdeq r8, r9, [r0], -r0
 *
 * ══ §19/21 Eff_Effect00(int, float, float, int, unsigned int)  0x1a005c  size 1420  355 条（0x1a005c..0x1a05e8）
 * @func 0x1a005c 0x1a05e8  size 1420  355 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1a0080→0x542428
 * 调用序列: 0xb66e8×12 / ParticleType_Shape(int, int)×6 / ParticleType_Size(int, float, float, float, float)×6 / ParticleType_Orientation(int, float, float, float, float, bool)×6 / ParticleType_Alpha2(int, float, float)×6 / ParticleType_Life(int, int, int)×6 / ParticleSystem_Particles_Create_Color(int, float, float, int, unsigned int, int)×4 / ParticleType_Direction(int, float, float, float, float)×3
 * 字段偏移 top8: 0x4×16 / 0xc×10 / 0x8×8 / 0x10×8 / 0x14×6 / 0x48×3 / 0x3a0×1 / 0x398×1
 * VFP 指令 71 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a005c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1a0060 vpush {d8, d9}
 *   @0x1a0064 sub sp, sp, #20
 *   @0x1a0068 mov r4, r3
 *   @0x1a006c mov r8, r1
 *   @0x1a0070 mov r9, r0
 *   @0x1a0074 mov r7, r2
 *   @0x1a0078 bl 0x19ff6c <_Z12Speed_Factorv>
 *   @0x1a007c cmp r4, #0
 *   @0x1a0080 ldr r3, [pc, #0x3a0]
 *   @0x1a0084 mov r1, #10
 *   @0x1a0088 vmov s18, r0
 *   @0x1a008c ldr r0, [pc, #0x398]
 *   @0x1a0090 add r0, pc, r0
 *   @0x1a0094 beq 0x1a026c <_Z12Eff_Effect00iffij+0x210>
 *   @0x1a0098 cmp r4, #2
 *   @0x1a009c beq 0x1a0438 <_Z12Eff_Effect00iffij+0x3dc>
 *   @0x1a00a0 ldr r4, [r0, r3]
 *   @0x1a00a4 mov r5, #0
 *   @0x1a00a8 mov r6, #0
 *   @0x1a00ac vmov.f32 s16, #1.700000e+01
 *   @0x1a00b0 ldr r0, [r4, #0x8]
 *   @0x1a00b4 bl 0x1a31a4 <_Z18ParticleType_Shapeii>
 *   @0x1a00b8 vldr s15, [pc, #856]
 *   @0x1a00bc movw r1, #0x999a
 *   @0x1a00c0 movt r1, #0x3e99
 *   @0x1a00c4 ldr r0, [r4, #0x8]
 *   @0x1a00c8 mov r2, r1
 *   @0x1a00cc str r5, [sp]
 *   @0x1a00d0 vmul.f32 s15, s18, s15
 *   @0x1a00d4 vmov r3, s15
 *   @0x1a00d8 bl 0x1a322c <_Z17ParticleType_Sizeiffff>
 *   @0x1a00dc ldr r0, [r4, #0x8]
 *   @0x1a00e0 mov r1, r5
 *   @0x1a00e4 mov r3, r5
 *   @0x1a00e8 str r5, [sp]
 *   @0x1a00ec mov r2, #0
 *   @0x1a00f0 str r6, [sp, #0x4]
 *   @0x1a00f4 movt r2, #0x43b4
 *   @0x1a00f8 bl 0x1a3400 <_Z24ParticleType_Orientationiffffb>
 *   @0x1a00fc ldr r0, [r4, #0x8]
 *   @0x1a0100 mov r1, r5
 *   @0x1a0104 mov r3, r5
 *   @0x1a0108 str r5, [sp]
 *   @0x1a010c mov r2, #0
 *   @0x1a0110 movt r2, #0x43b4
 *   @0x1a0114 bl 0x1a33b4 <_Z22ParticleType_Directioniffff>
 *   @0x1a0118 vmov.f32 s14, #4.000000e+00
 *   @0x1a011c vldr s15, [pc, #760]
 *   @0x1a0120 ldr r0, [r4, #0x8]
 *   @0x1a0124 str r5, [sp]
 *   @0x1a0128 vmul.f32 s14, s18, s14
 *   @0x1a012c vmul.f32 s15, s18, s15
 *   @0x1a0130 vmov r1, s14
 *   @0x1a0134 vmov r2, s14
 *   @0x1a0138 vmov r3, s15
 *   @0x1a013c bl 0x1a3368 <_Z18ParticleType_Speediffff>
 *   @0x1a0140 mov r2, r5
 *   @0x1a0144 ldr r0, [r4, #0x8]
 *   @0x1a0148 movw r1, #0x999a
 *   @0x1a014c movt r1, #0x3f19
 *   @0x1a0150 bl 0x1a36a4 <_Z19ParticleType_Alpha2iff>
 *   @0x1a0154 vmov.f32 s15, #1.200000e+01
 *   @0x1a0158 ldr r11, [r4, #0x8]
 *   @0x1a015c vdiv.f32 s15, s15, s18
 *   @0x1a0160 vcvt.f64.f32 d6, s15
 *   @0x1a0164 vmov r0, r1, d6
 *   @0x1a0168 bl 0xb66e8 <lrint@plt>
 *   @0x1a016c vdiv.f32 s16, s16, s18
 *   @0x1a0170 mov r10, r0
 *   @0x1a0174 vcvt.f64.f32 d8, s16
 *   @0x1a0178 vmov r0, r1, d8
 *   @0x1a017c bl 0xb66e8 <lrint@plt>
 *   @0x1a0180 mov r1, r10
 *   @0x1a0184 mov r2, r0
 *   @0x1a0188 mov r0, r11
 *   @0x1a018c bl 0x1a32b4 <_Z17ParticleType_Lifeiii>
 *   @0x1a0190 ldr r2, [sp, #0x48]
 *   @0x1a0194 ldr r3, [r4, #0x8]
 *   @0x1a0198 mov r0, r9
 *   @0x1a019c mov r1, r8
 *   @0x1a01a0 str r2, [sp]
 *   @0x1a01a4 mov r2, #20
 *   @0x1a01a8 str r2, [sp, #0x4]
 *   @0x1a01ac mov r2, r7
 *   @0x1a01b0 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji>
 *   @0x1a01b4 ldr r0, [r4, #0xc]
 *   @0x1a01b8 mov r1, #10
 *   @0x1a01bc bl 0x1a31a4 <_Z18ParticleType_Shapeii>
 *   @0x1a01c0 vldr s15, [pc, #616]
 *   @0x1a01c4 vmul.f32 s15, s18, s15
 *   @0x1a01c8 movw r1, #0x999a
 *   @0x1a01cc movt r1, #0x3e99
 *   @0x1a01d0 ldr r0, [r4, #0xc]
 *   @0x1a01d4 str r5, [sp]
 *   @0x1a01d8 mov r2, r1
 *   @0x1a01dc vmov r3, s15
 *   @0x1a01e0 bl 0x1a322c <_Z17ParticleType_Sizeiffff>
 *   @0x1a01e4 mov r3, r5
 *   @0x1a01e8 ldr r0, [r4, #0xc]
 *   @0x1a01ec mov r1, r5
 *   @0x1a01f0 str r5, [sp]
 *   @0x1a01f4 mov r2, #0
 *   @0x1a01f8 str r6, [sp, #0x4]
 *   @0x1a01fc movt r2, #0x43b4
 *   @0x1a0200 bl 0x1a3400 <_Z24ParticleType_Orientationiffffb>
 *   @0x1a0204 mov r2, r5
 *   @0x1a0208 ldr r0, [r4, #0xc]
 *   @0x1a020c movw r1, #0xcccd
 *   @0x1a0210 movt r1, #0x3f4c
 *   @0x1a0214 bl 0x1a36a4 <_Z19ParticleType_Alpha2iff>
 *   @0x1a0218 vmov r0, r1, d8
 *   @0x1a021c ldr r10, [r4, #0xc]
 *   @0x1a0220 bl 0xb66e8 <lrint@plt>
 *   @0x1a0224 mov r5, r0
 *   @0x1a0228 vmov r0, r1, d8
 *   @0x1a022c bl 0xb66e8 <lrint@plt>
 *   @0x1a0230 mov r1, r5
 *   @0x1a0234 mov r2, r0
 *   @0x1a0238 mov r0, r10
 *   @0x1a023c bl 0x1a32b4 <_Z17ParticleType_Lifeiii>
 *   @0x1a0240 ldr r3, [r4, #0xc]
 *   @0x1a0244 str r6, [sp]
 *   @0x1a0248 mov r12, #1
 *   @0x1a024c mov r0, r9
 *   @0x1a0250 mov r1, r8
 *   @0x1a0254 mov r2, r7
 *   @0x1a0258 str r12, [sp, #0x4]
 *   @0x1a025c bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji>
 *   @0x1a0260 add sp, sp, #20
 *   @0x1a0264 vpop {d8, d9}
 *   @0x1a0268 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1a026c ldr r5, [r0, r3]
 *   @0x1a0270 movw r10, #0xcccd
 *   @0x1a0274 movt r10, #0x3dcc
 *   @0x1a0278 mov r6, #0
 *   @0x1a027c vmov.f32 s16, #1.500000e+01
 *   @0x1a0280 ldr r0, [r5]
 *   @0x1a0284 bl 0x1a31a4 <_Z18ParticleType_Shapeii>
 *   @0x1a0288 vldr s15, [pc, #400]
 *   @0x1a028c ldr r0, [r5]
 *   @0x1a0290 mov r1, r10
 *   @0x1a0294 mov r2, r10
 *   @0x1a0298 str r6, [sp]
 *   @0x1a029c vmul.f32 s15, s18, s15
 *   @0x1a02a0 vmov r3, s15
 *   @0x1a02a4 bl 0x1a322c <_Z17ParticleType_Sizeiffff>
 *   @0x1a02a8 ldr r0, [r5]
 *   @0x1a02ac mov r1, r6
 *   @0x1a02b0 mov r3, r6
 *   @0x1a02b4 str r6, [sp]
 *   @0x1a02b8 mov r2, #0
 *   @0x1a02bc str r4, [sp, #0x4]
 *   @0x1a02c0 movt r2, #0x43b4
 *   @0x1a02c4 bl 0x1a3400 <_Z24ParticleType_Orientationiffffb>
 *   @0x1a02c8 ldr r0, [r5]
 *   @0x1a02cc mov r1, r6
 *   @0x1a02d0 mov r3, r6
 *   @0x1a02d4 str r6, [sp]
 *   @0x1a02d8 mov r2, #0
 *   @0x1a02dc movt r2, #0x43b4
 *   @0x1a02e0 bl 0x1a33b4 <_Z22ParticleType_Directioniffff>
 *   @0x1a02e4 vldr s15, [pc, #312]
 *   @0x1a02e8 vmul.f32 s15, s18, s15
 *   @0x1a02ec ldr r0, [r5]
 *   @0x1a02f0 str r6, [sp]
 *   @0x1a02f4 vadd.f32 s14, s18, s18
 *   @0x1a02f8 vmov r3, s15
 *   @0x1a02fc vmov r1, s14
 *   @0x1a0300 vmov r2, s14
 *   @0x1a0304 bl 0x1a3368 <_Z18ParticleType_Speediffff>
 *   @0x1a0308 mov r2, r6
 *   @0x1a030c ldr r0, [r5]
 *   @0x1a0310 movw r1, #0x999a
 *   @0x1a0314 movt r1, #0x3f19
 *   @0x1a0318 bl 0x1a36a4 <_Z19ParticleType_Alpha2iff>
 *   @0x1a031c vmov.f32 s15, #1.000000e+01
 *   @0x1a0320 ldr r3, [r5]
 *   @0x1a0324 str r3, [sp, #0xc]
 *   @0x1a0328 vdiv.f32 s15, s15, s18
 *   @0x1a032c vcvt.f64.f32 d6, s15
 *   @0x1a0330 vmov r0, r1, d6
 *   @0x1a0334 bl 0xb66e8 <lrint@plt>
 *   @0x1a0338 vdiv.f32 s16, s16, s18
 *   @0x1a033c mov r11, r0
 *   @0x1a0340 vcvt.f64.f32 d8, s16
 *   @0x1a0344 vmov r0, r1, d8
 *   @0x1a0348 bl 0xb66e8 <lrint@plt>
 *   @0x1a034c ldr r3, [sp, #0xc]
 *   @0x1a0350 mov r1, r11
 *   @0x1a0354 mov r2, r0
 *   @0x1a0358 mov r0, r3
 *   @0x1a035c bl 0x1a32b4 <_Z17ParticleType_Lifeiii>
 *   @0x1a0360 ldr r2, [sp, #0x48]
 *   @0x1a0364 ldr r3, [r5]
 *   @0x1a0368 mov r0, r9
 *   @0x1a036c mov r1, r8
 *   @0x1a0370 str r2, [sp]
 *   @0x1a0374 mov r2, #20
 *   @0x1a0378 str r2, [sp, #0x4]
 *   @0x1a037c mov r2, r7
 *   @0x1a0380 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji>
 *   @0x1a0384 ldr r0, [r5, #0x4]
 *   @0x1a0388 mov r1, #10
 *   @0x1a038c bl 0x1a31a4 <_Z18ParticleType_Shapeii>
 *   @0x1a0390 vmov s12, r10
 *   @0x1a0394 mov r1, r10
 *   @0x1a0398 ldr r0, [r5, #0x4]
 *   @0x1a039c vmul.f32 s12, s18, s12
 *   @0x1a03a0 mov r2, r10
 *   @0x1a03a4 str r6, [sp]
 *   @0x1a03a8 vmov r3, s12
 *   @0x1a03ac bl 0x1a322c <_Z17ParticleType_Sizeiffff>
 *   @0x1a03b0 mov r3, r6
 *   @0x1a03b4 ldr r0, [r5, #0x4]
 *   @0x1a03b8 mov r1, r6
 *   @0x1a03bc str r6, [sp]
 *   @0x1a03c0 mov r2, #0
 *   @0x1a03c4 str r4, [sp, #0x4]
 *   @0x1a03c8 movt r2, #0x43b4
 *   @0x1a03cc bl 0x1a3400 <_Z24ParticleType_Orientationiffffb>
 *   @0x1a03d0 mov r2, r6
 *   @0x1a03d4 ldr r0, [r5, #0x4]
 *   @0x1a03d8 movw r1, #0xcccd
 *   @0x1a03dc movt r1, #0x3f4c
 *   @0x1a03e0 bl 0x1a36a4 <_Z19ParticleType_Alpha2iff>
 *   @0x1a03e4 vmov r0, r1, d8
 *   @0x1a03e8 ldr r10, [r5, #0x4]
 *   @0x1a03ec bl 0xb66e8 <lrint@plt>
 *   @0x1a03f0 mov r6, r0
 *   @0x1a03f4 vmov r0, r1, d8
 *   @0x1a03f8 bl 0xb66e8 <lrint@plt>
 *   @0x1a03fc mov r1, r6
 *   @0x1a0400 mov r2, r0
 *   @0x1a0404 mov r0, r10
 *   @0x1a0408 bl 0x1a32b4 <_Z17ParticleType_Lifeiii>
 *   @0x1a040c ldr r3, [r5, #0x4]
 *   @0x1a0410 str r4, [sp]
 *   @0x1a0414 b 0x1a0248 <_Z12Eff_Effect00iffij+0x1ec>
 *   @0x1a0418 stcllo p12, c12, [r12, #820]
 *   @0x1a041c cdplt p1, #0x3, c5, c8, c12, #0x7
 *   @0x1a0420 stcllo p12, c12, [r12, #-820]
 *   @0x1a0424 stcllt p12, c12, [r12, #820]
 *   @0x1a0428 .word 0xffffeb20
 *   @0x1a042c eoreq r1, r5, r0, asr #23
 *   @0x1a0430 cdplo p12, #0x4, c12, c12, c13, #0x6
 *   @0x1a0434 cdplt p12, #0x4, c12, c12, c13, #0x6
 *   @0x1a0438 ldr r4, [r0, r3]
 *   @0x1a043c movw r10, #0xcccd
 *   @0x1a0440 movt r10, #0x3ecc
 *   @0x1a0444 mov r5, #0
 *   @0x1a0448 mov r6, #0
 *   @0x1a044c vmov.f32 s16, #2.000000e+01
 *   @0x1a0450 ldr r0, [r4, #0x10]
 *   @0x1a0454 bl 0x1a31a4 <_Z18ParticleType_Shapeii>
 *   @0x1a0458 vldr s15, [pc, #-48]
 *   @0x1a045c ldr r0, [r4, #0x10]
 *   @0x1a0460 mov r1, r10
 *   @0x1a0464 mov r2, r10
 *   @0x1a0468 str r5, [sp]
 *   @0x1a046c vmul.f32 s15, s18, s15
 *   @0x1a0470 vmov r3, s15
 *   @0x1a0474 bl 0x1a322c <_Z17ParticleType_Sizeiffff>
 *   @0x1a0478 ldr r0, [r4, #0x10]
 *   @0x1a047c mov r1, r5
 *   @0x1a0480 mov r3, r5
 *   @0x1a0484 str r5, [sp]
 *   @0x1a0488 mov r2, #0
 *   @0x1a048c str r6, [sp, #0x4]
 *   @0x1a0490 movt r2, #0x43b4
 *   @0x1a0494 bl 0x1a3400 <_Z24ParticleType_Orientationiffffb>
 *   @0x1a0498 ldr r0, [r4, #0x10]
 *   @0x1a049c mov r1, r5
 *   @0x1a04a0 mov r3, r5
 *   @0x1a04a4 str r5, [sp]
 *   @0x1a04a8 mov r2, #0
 *   @0x1a04ac movt r2, #0x43b4
 *   @0x1a04b0 bl 0x1a33b4 <_Z22ParticleType_Directioniffff>
 *   @0x1a04b4 vmov.f32 s14, #7.000000e+00
 *   @0x1a04b8 vldr s15, [pc, #-140]
 *   @0x1a04bc ldr r0, [r4, #0x10]
 *   @0x1a04c0 str r5, [sp]
 *   @0x1a04c4 vmul.f32 s14, s18, s14
 *   @0x1a04c8 vmul.f32 s15, s18, s15
 *   @0x1a04cc vmov r1, s14
 *   @0x1a04d0 vmov r2, s14
 *   @0x1a04d4 vmov r3, s15
 *   @0x1a04d8 bl 0x1a3368 <_Z18ParticleType_Speediffff>
 *   @0x1a04dc mov r2, r5
 *   @0x1a04e0 ldr r0, [r4, #0x10]
 *   @0x1a04e4 movw r1, #0x999a
 *   @0x1a04e8 movt r1, #0x3f19
 *   @0x1a04ec bl 0x1a36a4 <_Z19ParticleType_Alpha2iff>
 *   @0x1a04f0 vmov.f32 s15, #1.500000e+01
 *   @0x1a04f4 ldr r3, [r4, #0x10]
 *   @0x1a04f8 str r3, [sp, #0xc]
 *   @0x1a04fc vdiv.f32 s15, s15, s18
 *   @0x1a0500 vcvt.f64.f32 d6, s15
 *   @0x1a0504 vmov r0, r1, d6
 *   @0x1a0508 bl 0xb66e8 <lrint@plt>
 *   @0x1a050c vdiv.f32 s16, s16, s18
 *   @0x1a0510 mov r11, r0
 *   @0x1a0514 vcvt.f64.f32 d8, s16
 *   @0x1a0518 vmov r0, r1, d8
 *   @0x1a051c bl 0xb66e8 <lrint@plt>
 *   @0x1a0520 ldr r3, [sp, #0xc]
 *   @0x1a0524 mov r1, r11
 *   @0x1a0528 mov r2, r0
 *   @0x1a052c mov r0, r3
 *   @0x1a0530 bl 0x1a32b4 <_Z17ParticleType_Lifeiii>
 *   @0x1a0534 ldr r2, [sp, #0x48]
 *   @0x1a0538 ldr r3, [r4, #0x10]
 *   @0x1a053c mov r0, r9
 *   @0x1a0540 mov r1, r8
 *   @0x1a0544 str r2, [sp]
 *   @0x1a0548 mov r2, #20
 *   @0x1a054c str r2, [sp, #0x4]
 *   @0x1a0550 mov r2, r7
 *   @0x1a0554 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji>
 *   @0x1a0558 ldr r0, [r4, #0x14]
 *   @0x1a055c mov r1, #10
 *   @0x1a0560 bl 0x1a31a4 <_Z18ParticleType_Shapeii>
 *   @0x1a0564 vmov s12, r10
 *   @0x1a0568 mov r1, r10
 *   @0x1a056c ldr r0, [r4, #0x14]
 *   @0x1a0570 vmul.f32 s12, s18, s12
 *   @0x1a0574 mov r2, r10
 *   @0x1a0578 str r5, [sp]
 *   @0x1a057c vmov r3, s12
 *   @0x1a0580 bl 0x1a322c <_Z17ParticleType_Sizeiffff>
 *   @0x1a0584 mov r3, r5
 *   @0x1a0588 ldr r0, [r4, #0x14]
 *   @0x1a058c mov r1, r5
 *   @0x1a0590 str r5, [sp]
 *   @0x1a0594 mov r2, #0
 *   @0x1a0598 str r6, [sp, #0x4]
 *   @0x1a059c movt r2, #0x43b4
 *   @0x1a05a0 bl 0x1a3400 <_Z24ParticleType_Orientationiffffb>
 *   @0x1a05a4 mov r2, r5
 *   @0x1a05a8 ldr r0, [r4, #0x14]
 *   @0x1a05ac movw r1, #0xcccd
 *   @0x1a05b0 movt r1, #0x3f4c
 *   @0x1a05b4 bl 0x1a36a4 <_Z19ParticleType_Alpha2iff>
 *   @0x1a05b8 vmov r0, r1, d8
 *   @0x1a05bc ldr r10, [r4, #0x14]
 *   @0x1a05c0 bl 0xb66e8 <lrint@plt>
 *   @0x1a05c4 mov r5, r0
 *   @0x1a05c8 vmov r0, r1, d8
 *   @0x1a05cc bl 0xb66e8 <lrint@plt>
 *   @0x1a05d0 mov r1, r5
 *   @0x1a05d4 mov r2, r0
 *   @0x1a05d8 mov r0, r10
 *   @0x1a05dc bl 0x1a32b4 <_Z17ParticleType_Lifeiii>
 *   @0x1a05e0 ldr r3, [r4, #0x14]
 *   @0x1a05e4 b 0x1a0244 <_Z12Eff_Effect00iffij+0x1e8>
 *
 * ══ §20/21 anon_317210  0x317210  size 1412  353 条（0x317210..0x317794）
 * @func 0x317210 0x317794  size 1412  353 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xf1518a / FT_Bitmap_Convert+0xc8 / 0x11533da / 0x407028 / 0xfe853448 / 0x3318f4 / 0xe92490 / 0x8556cc
 * 字段偏移 top8: 0x18×1 / 0x10×1 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x317210 .word 0x46984ff7
 *   @0x317214 strmi r6, [pc], -r5, asr #17
 *   @0x317218 .word 0xf5059201
 *   @0x31721c .word 0xf1045485
 *   @0x317220 stmibvs r3!, {r3, r4, r9, r10}
 *   @0x317224 andsle r4, lr, #-1879048183
 *   @0x317228 bne 0x19319b8 <b2_toiTime+0x11d8514>
 *   @0x31722c .word 0x01b8f105
 *   @0x317230 addmi r1, r8, #331776
 *   @0x317234 bne 0x20d24c <_ZN8CDS_Grid7ShuffleEv+0x4b4>
 *   @0x317238 ldrmi r6, [r10], #-423
 *   @0x31723c ands r6, r2, r2, ror #3
 *   @0x317240 .word 0x21006828
 *   @0x317244 blx 0xf1518a <b2_toiTime+0x7bbce6>
 *   @0x317248 tstlt r0, r1, lsl #13
 *   @0x31724c beq 0x353390
 *   @0x317250 .word 0xf105e060
 *   @0x317254 .word 0xf7ff000c
 *   @0x317258 .word 0xf505fdf4
 *   @0x31725c andsvs r5, lr, r6, lsl #7
 *   @0x317260 .word 0xf8c461e6
 *   @0x317264 stmibvs r2!, {r3, r4, r12, pc}
 *   @0x317268 stmdale r10, {r0, r1, r2, r4, r7, r9, lr}
 *   @0x31726c svceq #0xf1b8
 *   @0x317270 .word 0xf505d0ec
 *   @0x317274 .word 0xf1055b86
 *   @0x317278 .word 0xf04f09b8
 *   @0x31727c strlo r0, [r12, #-0xa00]
 *   @0x317280 .word 0xf505e032
 *   @0x317284 stmibvs r1!, {r1, r2, r7, r8, r9, r12, lr} ^
 *   @0x317288 .word 0xf1051abf
 *   @0x31728c ldmdavs r11, {r2, r3, r9, r11}
 *   @0x317290 blvc 0x314b98 <FT_Bitmap_Convert+0xc8>
 *   @0x317294 addsmi r1, pc, #372736
 *   @0x317298 shasxmi r11, r11, r8
 *   @0x31729c ldrmi r1, [r9], #-2815
 *   @0x3172a0 mvnvs r4, r10, lsl r4
 *   @0x3172a4 svchs #0x61a2
 *   @0x3172a8 ldrbmi sp, [pc, #-0xe0]
 *   @0x3172ac ssatmi r11, #0x1a, r4, lsl #31
 *   @0x3172b0 stmibpl r0, {r0, r1, r2, r3, r6, r10, r12, sp, lr, pc}
 *   @0x3172b4 qaddhs r4, r0, r0
 *   @0x3172b8 .word 0xf7ff464a
 *   @0x3172bc strbmi pc, [r8, #-0xe7b]
 *   @0x3172c0 ldmdavs r3!, {r2, r6, r7, r8, r9, r12, lr, pc}
 *   @0x3172c4 streq lr, [r7, -r9, asr #23]
 *   @0x3172c8 eorsvs r4, r3, r11, asr #8
 *   @0x3172cc .word 0xf44fe7eb
 *   @0x3172d0 .word 0xf8c45280
 *   @0x3172d4 qadd16mi r9, r8, r12
 *   @0x3172d8 .word 0xf7ff4649
 *   @0x3172dc stmibvs r2!, {r0, r1, r3, r5, r6, r9, r10, r11, r12, sp, lr, pc} ^
 *   @0x3172e0 .word 0xf8cb4402
 *   @0x3172e4 movlt r2, r0
 *   @0x3172e8 .word 0xf8db69e1
 *   @0x3172ec stmdals r1, {r12, sp, lr}
 *   @0x3172f0 ldrmi r1, [r8, #0xa7f]!
 *   @0x3172f4 .word 0x4647bf38
 *   @0x3172f8 ldrtmi r4, [r10], #1104
 *   @0x3172fc .word 0xf59f463a
 *   @0x317300 stmibvs r2!, {r1, r2, r3, r4, r6, r8, r11, sp, lr, pc} ^
 *   @0x317304 stmdaeq r7, {r3, r4, r5, r7, r8, r9, r11, sp, lr, pc}
 *   @0x317308 mvnvs r4, r10, lsr r4
 *   @0x31730c ldrtmi r6, [r10], #-2098
 *   @0x317310 bicsle r6, r12, r2, lsr r0
 *   @0x317314 andlt r4, r3, r0, asr r6
 *   @0x317318 svchi #0xf0e8bd
 *   @0x31731c ldrbmi r2, [r0, -r0]!
 *   @0x317320 ldrlt r4, [r0, #-0xb04]
 *   @0x317324 .word 0x4604447b
 *   @0x317328 andvs r3, r3, r8, lsl #6
 *   @0x31732c rfeia r2!
 *   @0x317330 ldclt p6, c4, [r0, #-128]
 *   @0x317334 andeq r5, sp, r8, lsr sp
 *   @0x317338 .word 0x4604b510
 *   @0x31733c .word 0xfff0f7ff
 *   @0x317340 .word 0xf7654620
 *   @0x317344 strtmi lr, [r0], -r6, asr #30
 *   @0x317348 svclt #0xbd10
 *   @0x31734c .word 0x460cb570
 *   @0x317350 sadd16mi r4, lr, r5
 *   @0x317354 .word 0xf808f001
 *   @0x317358 movwhs r11, #0x1130
 *   @0x31735c stmdavs r10!, {r2, r4, r5, r6, sp, lr}
 *   @0x317360 eorsvs r4, r3, r8, lsl r6
 *   @0x317364 adcsvs r7, r2, r3, lsr r4
 *   @0x317368 svclt #0xbd70
 *   @0x31736c svclt #0xeef7ff
 *   @0x317370 andhs r11, r1, #56, #10
 *   @0x317374 strmi r2, [r4], -r0, lsl #6
 *   @0x317378 subvs r6, r3, r3
 *   @0x31737c sbcvs r6, r3, r3, lsl #1
 *   @0x317380 cmplt r9, r2, lsl #8
 *   @0x317384 strmi r4, [r8], -r6, lsl #26
 *   @0x317388 ldrbtmi r4, [sp], #-2566
 *   @0x31738c ldmdavs r2, {r1, r3, r4, r5, r6, r10, lr}
 *   @0x317390 .word 0xf0004629
 *   @0x317394 qaddlt pc, r7, r8
 *   @0x317398 rscvs r6, r3, r3, lsl #17
 *   @0x31739c ldclt p6, c4, [r8, #-128]!
 *   @0x3173a0 strdeq r5, r6, [sp], -r2
 *   @0x3173a4 andeq r10, sp, r4, ror r8
 *   @0x3173a8 mvnsmi lr, sp, lsr #18
 *   @0x3173ac strmi r11, [r4], -r6, lsl #1
 *   @0x3173b0 ldrmi r4, [r6], -pc, lsl #12
 *   @0x3173b4 .word 0xffd8f000
 *   @0x3173b8 andhs r4, r1, r5, lsl #12
 *   @0x3173bc ldrtmi r11, [r8], -r5, lsl #22
 *   @0x3173c0 ldmdbmi r1, {r0, r1, r2, r4, r5, r6, r7, r8, r12, sp, pc}
 *   @0x3173c4 bmi 0x768cac <b2_toiTime+0xf808>
 *   @0x3173c8 ldrbtmi r4, [r9], #-1579
 *   @0x3173cc ldrbtmi r6, [r10], #-2057
 *   @0x3173d0 blx 0x11533da <b2_toiTime+0x9f9f36>
 *   @0x3173d4 .word 0xf1b84680
 *   @0x3173d8 andsle r0, r1, r0, lsl #30
 *   @0x3173dc stmdage r1, {r0, r5, r9, r10, lr}
 *   @0x3173e0 .word 0xffc6f7ff
 *   @0x3173e4 .word 0x7000f8d8
 *   @0x3173e8 strtmi r10, [r1], -r1, lsl #22
 *   @0x3173ec ldrtmi r4, [r2], -r0, asr #12
 *   @0x3173f0 .word 0x47a0693c
 *   @0x3173f4 stmdahs r1, {r0, r11, r12, pc}
 *   @0x3173f8 blls 0x407028 <g_RomDisk+0xf808>
 *   @0x3173fc eorsvs r4, r3, r8, lsr #12
 *   @0x317400 pop {r1, r2, r12, sp, pc}
 *   @0x317404 svclt #0x81f0
 *   @0x317408 andeq r10, sp, r10, lsr r8
 *   @0x31740c andeq r5, sp, lr, lsr #25
 *   @0x317410 .word 0x4605b570
 *   @0x317414 .word 0x4c08b170
 *   @0x317418 .word 0xf104447c
 *   @0x31741c ldrtmi r0, [r0], -r12, lsl #12
 *   @0x317420 mrrc p5, #0x9, pc, r0, c15
 *   @0x317424 ldrtmi r6, [r0], -r3, ror #18
 *   @0x317428 .word 0x6165602b
 *   @0x31742c ldrhtmi lr, [r0], #-141
 *   @0x317430 bllt 0xfe853448 <b2_toiTime+0xfffffffffe0f9fa4>
 *   @0x317434 svclt #0xbd70
 *   @0x317438 umaaleq r2, r4, r0, r0
 *   @0x31743c .word 0x4605b538
 *   @0x317440 ldrbtmi r4, [r12], #-3089
 *   @0x317444 andeq pc, r12, r4, lsl #2
 *   @0x317448 ldc p5, c15, [r12], #-636
 *   @0x31744c cmplt r3, r3, lsr #18
 *   @0x317450 ldrmi r6, [r8], -r2, lsr #17
 *   @0x317454 orrpl pc, r0, pc, asr #8
 *   @0x317458 .word 0x6123589b
 *   @0x31745c ldc p5, c15, [r4, #636]
 *   @0x317460 blhs 0x3318f4
 *   @0x317464 .word 0x4c09d1f4
 *   @0x317468 strlo r4, [r12], #-1148
 *   @0x31746c .word 0xf59f4620
 *   @0x317470 qasxmi lr, r0, r0
 *   @0x317474 .word 0xec0ef59f
 *   @0x317478 ldrbtmi r4, [r8], #-2053
 *   @0x31747c .word 0xf59f6800
 *   @0x317480 strtmi lr, [r8], -r10, lsl #27
 *   @0x317484 svclt #0xbd38
 *   @0x317488 subeq r2, r4, r6, rrx
 *   @0x31748c subeq r2, r4, r0, asr #32
 *   @0x317490 subeq r2, r4, r6, asr #32
 *   @0x317494 ldrlt r4, [r0, #-0xb04]
 *   @0x317498 .word 0x4604447b
 *   @0x31749c andvs r3, r3, r8, lsl #6
 *   @0x3174a0 .word 0xff16f000
 *   @0x3174a4 ldclt p6, c4, [r0, #-128]
 *   @0x3174a8 strdeq r5, r6, [sp], -r4
 *   @0x3174ac .word 0x4604b510
 *   @0x3174b0 .word 0xfff0f7ff
 *   @0x3174b4 .word 0xf7654620
 *   @0x3174b8 strtmi lr, [r0], -r12, lsl #29
 *   @0x3174bc svclt #0xbd10
 *   @0x3174c0 strlt r4, [r8, #-0x802]
 *   @0x3174c4 .word 0xf0004478
 *   @0x3174c8 svclt #0xfb09
 *   @0x3174cc andeq r4, r4, r8, lsr pc
 *   @0x3174d0 strlt r4, [r8, #-0x802]
 *   @0x3174d4 .word 0xf0004478
 *   @0x3174d8 svclt #0xfb01
 *   @0x3174dc andeq r4, r4, r8, asr #30
 *   @0x3174e0 ldrlt r4, [r0, #-0x833]!
 *   @0x3174e4 stmdavs r0, {r3, r4, r5, r6, r10, lr}
 *   @0x3174e8 .word 0xf59fb083
 *   @0x3174ec strmi lr, [r4], -r2, lsr #24
 *   @0x3174f0 qadd16mi r11, r0, r0
 *   @0x3174f4 ldclt p0, c11, [r0, #-12]!
 *   @0x3174f8 ldrbtmi r4, [r8], #-2094
 *   @0x3174fc .word 0xf59f300c
 *   @0x317500 blmi 0xe92490 <b2_toiTime+0x738fec>
 *   @0x317504 ldmdbvs r12, {r0, r1, r3, r4, r5, r6, r10, lr} ^
 *   @0x317508 ldmdavs r10, {r2, r4, r5, r7, r8, r12, sp, pc}
 *   @0x31750c strtmi r4, [r0], -r11, lsr #22
 *   @0x317510 ldrbtmi r6, [r11], #-2081
 *   @0x317514 qaddhs r6, r9, r0
 *   @0x317518 stmda r10, {r0, r1, r2, r3, r4, r7, r8, r10, r12, sp, lr, pc} ^
 *   @0x31751c ldrbtmi r4, [r8], #-2088
 *   @0x317520 .word 0xf59f300c
 *   @0x317524 .word 0x2c00ebd6
 *   @0x317528 stmdami r6!, {r2, r3, r4, r5, r12, lr, pc}
 *   @0x31752c ldrbtmi r4, [r8], #-1569
 *   @0x317530 .word 0xf59f6800
 *   @0x317534 ldrb lr, [r12, r4, lsl #24]
 *   @0x317538 .word 0x33fff04f
 *   @0x31753c movwls r4, #0x620
 *   @0x317540 orrpl pc, r0, pc, asr #8
 *   @0x317544 .word 0x23222203
 *   @0x317548 .word 0xf59f9401
 *   @0x31754c mcrrne p13, #0x2, lr, r3, c10
 *   @0x317550 ldmdbmi sp, {r2, r5, r6, r7, r12, lr, pc}
 *   @0x317554 stmdbvs r10, {r0, r3, r4, r5, r6, r10, lr}
 *   @0x317558 stmdavs r12, {r0, r1, r3, r7, r11, sp, lr} ^
 *   @0x31755c smlabtvs r8, r2, r0, r5
 *   @0x317560 .word 0xf851b174
 *   @0x317564 movwhs r2, #0xb14
 *   @0x317568 andvs r3, r8, r1, lsl #6
 *   @0x31756c strmi r4, [r1], -r3, lsr #5
 *   @0x317570 mvnsle r4, r0, lsl r4
 *   @0x317574 andhs r4, r0, r5, lsl r11
 *   @0x317578 ldrbtmi r6, [r11], #-8
 *   @0x31757c .word 0xe7c5695c
 *   @0x317580 blhs 0x8556cc <b2_toiTime+0xfc228>
 *   @0x317584 blmi 0x7d1564 <b2_toiTime+0x780c0>
 *   @0x317588 strmi r4, [sp], -r4, lsl #12
 *   @0x31758c .word 0xf103447b
 *   @0x317590 .word 0xf59f000c
 *   @0x317594 qadd8mi lr, r0, lr
 *   @0x317598 .word 0x31014629
 *   @0x31759c .word 0xf001d006
 *   @0x3175a0 ldrb pc, [r10, r1, lsl #16]!
 *   @0x3175a4 ldrbtmi r4, [r8], #-2059
 *   @0x3175a8 blx 0xfe9535b0 <b2_toiTime+0xfffffffffe1fa10c>
 *   @0x3175ac .word 0xf88cf001
 *   @0x3175b0 ldrdeq r1, r2, [r4], #-252
 *   @0x3175b4 subeq r1, r4, lr, lsr #31
 *   @0x3175b8 subeq r1, r4, r4, lsr #31
 *   @0x3175bc umaaleq r1, r4, r6, pc
 *   @0x3175c0 subeq r1, r4, r10, lsl #31
 *   @0x3175c4 umaaleq r1, r4, r2, pc
 *   @0x3175c8 subeq r1, r4, r4, asr pc
 *   @0x3175cc subeq r1, r4, lr, lsr #30
 *   @0x3175d0 subeq r1, r4, r12, lsl pc
 *   @0x3175d4 muleq r4, r10, lr
 *   @0x3175d8 .word 0x4604b570
 *   @0x3175dc .word 0xff80f7ff
 *   @0x3175e0 ldreq pc, [r8, #-0x104]!
 *   @0x3175e4 .word 0xf0004606
 *   @0x3175e8 rscvs pc, r0, sp, lsr lr
 *   @0x3175ec cdp2 p0, #0x0, c15, c2, c0, #0x0
 *   @0x3175f0 movwlo r6, #0x1873
 *   @0x3175f4 strtmi r6, [r8], -r0, lsr #2
 *   @0x3175f8 .word 0xf0036073
 *   @0x3175fc strtmi lr, [r8], -r0, lsl #16
 *   @0x317600 blx 0xfe9d3608 <b2_toiTime+0xfffffffffe27a164>
 *   @0x317604 strlt r4, [r8, #-0x806]
 *   @0x317608 stmdavs r0, {r3, r4, r5, r6, r10, lr}
 *   @0x31760c bl 0xfe754c90 <b2_toiTime+0xfffffffffdffb7ec>
 *   @0x317610 mrslo r11, apsr
 *   @0x317614 .word 0xf000d001
 *   @0x317618 .word 0xf001ffc5
 *   @0x31761c svclt #0xf855
 *   @0x317620 strheq r1, [r4], #-232
 *   @0x317624 addslo r11, r0, r0, lsl r5
 *   @0x317628 svc #0x8cf59e
 *   @0x31762c teqlt r0, r4, lsl #12
 *   @0x317630 addshs r2, r0, #0, #2
 *   @0x317634 svc #0xbcf59e
 *   @0x317638 addseq pc, r0, r4, lsl #2
 *   @0x31763c stmdami r5, {r4, r8, r10, r11, r12, sp, pc}
 *   @0x317640 .word 0xf0004478
 *   @0x317644 .word 0x3101fa4b
 *   @0x317648 .word 0xf000d001
 *   @0x31764c .word 0xf001ffab
 *   @0x317650 svclt #0xf83b
 *   @0x317654 andeq r4, r4, r8, lsr lr
 *   @0x317658 .word 0x4604b538
 *   @0x31765c stclo p8, c15, [r8], {80}
 *   @0x317660 ldrmi r11, [r8, r3, lsl #2]
 *   @0x317664 addseq pc, r0, r4, lsr #3
 *   @0x317668 ldrhtmi lr, [r8], -sp
 *   @0x31766c blt 0xcd3684 <b2_toiTime+0x57a1e0>
 *   @0x317670 .word 0xf856f000
 *   @0x317674 ldrbtmi r4, [r8], #-2055
 *   @0x317678 blx 0xf53680 <b2_toiTime+0x7fa1dc>
 *   @0x31767c strmi r4, [r5], -r12, lsl #12
 *   @0x317680 .word 0xf88af000
 *   @0x317684 andle r3, r1, r1, lsl #8
 *   @0x317688 .word 0xff8cf000
 *   @0x31768c .word 0xf0014628
 *   @0x317690 svclt #0xf81b
 *   @0x317694 andeq r4, r4, lr, lsr #28
 *   @0x317698 subseq pc, r8, r1, lsl #2
 *   @0x31769c svclt #0xdcf7ff
 *   @0x3176a0 .word 0x4603b5d0
 *   @0x3176a4 ldmib r7, {r3, r8, r9, r10, sp, pc} ^
 *   @0x3176a8 .word 0xf1a06700
 *   @0x3176ac .word 0x4c080090
 *   @0x3176b0 stcne p8, c15, [r12], {67}
 *   @0x3176b4 stmdb r3, {r2, r3, r4, r5, r6, r10, lr} ^
 *   @0x3176b8 .word 0xf8436716
 *   @0x3176bc .word 0xf8432c88
 *   @0x3176c0 .word 0xf7ff4c50
 *   @0x3176c4 svclt #0xff89
 *   @0x3176c8 .word 0x432b2b00
 *   @0x3176cc strbmi r5, [lr, -r3, asr #10]
 *   @0x3176d0 .word 0xffffffe1
 *   @0x3176d4 andhi pc, r0, pc, lsr #7
 *   @0x3176d8 .word 0xf7ffb538
 *   @0x3176dc stmdavs r1, {r0, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x3176e0 strge r11, [r11, #-0x191]
 *   @0x3176e4 strmi lr, [r0, #-0x9d5]
 *   @0x3176e8 movwhs lr, #0xe9d1
 *   @0x3176ec rsbmi r4, r11, r2, rrx
 *   @0x3176f0 streq lr, [r3], #-2642
 *   @0x3176f4 movwhs sp, #0x4
 *   @0x3176f8 strmi r6, [r8], -r3
 *   @0x3176fc .word 0xff6cf7ff
 *   @0x317700 subsmi r6, r11, #2277376
 *   @0x317704 ldrb r6, [r8, r11, lsl #3]!
 *   @0x317708 ldrbtmi r4, [r8], #-2051
 *   @0x31770c .word 0xf9e6f000
 *   @0x317710 .word 0x432b2b00
 *   @0x317714 strbmi r5, [lr, -r3, asr #10]
 *   @0x317718 strheq r4, [r4], -lr
 *   @0x31771c andhi pc, r0, pc, lsr #7
 *   @0x317720 .word 0x4606b570
 *   @0x317724 mrc2 p7, #0x6, apsr_nzcv, c12, c15, #0x7
 *   @0x317728 strmi lr, [r0, #-0x9d6]
 *   @0x31772c ldmib r3, {r1, r2, r4, r8, r9, sp, pc} ^
 *   @0x317730 rsbmi r2, r2, r0, lsl #6
 *   @0x317734 b 0x17a78e8 <b2_toiTime+0x104e444>
 *   @0x317738 stmdavs r1, {r0, r1, r8}
 *   @0x31773c ldmiblt r1!, {r12, lr, pc}
 *   @0x317740 stclo p8, c15, [r0], #-344
 *   @0x317744 eorseq pc, r8, #-2147483607
 *   @0x317748 svclt #0xb42b00
 *   @0x31774c movweq pc, #0x11c3
 *   @0x317750 .word 0xf8463301
 *   @0x317754 .word 0xf8563c20
 *   @0x317758 addmi r3, r10, #4, #24
 *   @0x31775c .word 0xf846bf1c
 *   @0x317760 andvs r1, r2, r4, lsr #24
 *   @0x317764 blo 0x371874 <_ZTS13C_UTF16String+0x8920>
 *   @0x317768 ldrmi r6, [r8], -r2, asr #32
 *   @0x31776c stmdami r8, {r4, r5, r6, r8, r10, r11, r12, sp, pc}
 *   @0x317770 .word 0xf0004478
 *   @0x317774 strhlo pc, [r1, -r3]
 *   @0x317778 .word 0xf000d001
 *   @0x31777c .word 0xf000ff13
 *   @0x317780 svclt #0xffa3
 *   @0x317784 andhi pc, r0, pc, lsr #7
 *   @0x317788 .word 0x432b2b00
 *   @0x31778c strbmi r5, [lr, -r3, asr #10]
 *   @0x317790 muleq r4, r0, sp
 *
 * ══ §21/21 cARRAY_OF_POINTERS::~cARRAY_OF_POINTERS()  0xd1aec  size 80  20 条（0xd1aec..0xd1b3c）
 * @func 0xd1aec 0xd1b3c  size 80  20 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2
 * 字段偏移 top8: 0xc×3 / 0x4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd1aec push {r3, r4, r5, lr}
 *   @0xd1af0 mov r4, r0
 *   @0xd1af4 ldr r3, [r0]
 *   @0xd1af8 cmp r3, #0
 *   @0xd1afc beq 0xd1b24 <_ZN18cARRAY_OF_POINTERSD2Ev+0x38>
 *   @0xd1b00 ldr r5, [r0, #0xc]
 *   @0xd1b04 subs r0, r5, #0
 *   @0xd1b08 beq 0xd1b2c <_ZN18cARRAY_OF_POINTERSD2Ev+0x40>
 *   @0xd1b0c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xd1b10 mov r3, #0
 *   @0xd1b14 str r3, [r4, #0xc]
 *   @0xd1b18 str r3, [r4, #0x4]
 *   @0xd1b1c mov r3, #0
 *   @0xd1b20 str r3, [r4]
 *   @0xd1b24 mov r0, r4
 *   @0xd1b28 pop {r3, r4, r5, pc}
 *   @0xd1b2c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xd1b30 str r5, [r4, #0xc]
 *   @0xd1b34 str r5, [r4, #0x4]
 *   @0xd1b38 b 0xd1b1c <_ZN18cARRAY_OF_POINTERSD2Ev+0x30>
 */
