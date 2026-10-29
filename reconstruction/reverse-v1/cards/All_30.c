/* cally 逆向卡：All_30 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 28 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/28 JS_String_prototype_replace(RValue&, CInstance*, CInstance*, int, RValue*)  0x25924c  size 1136  284 条（0x25924c..0x2596bc）
 * @func 0x25924c 0x2596d0  size 1156  289 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6628×8 / 0xb6538×5 / F_JS_ToString(RValue&, RValue*)×3 / YYCreateString(RValue*, char const*)×3 / JSThrowTypeError(char const*)×3 / JS_CheckObjectCoercible(RValue&) / utf8_strstr(char const*, char const*) / JS_IsCallable(RValue&)
 * 字段偏移 top8: 0x-68×8 / 0x-a4×7 / 0x-ac×6 / 0x-a0×5 / 0x-a8×4 / 0x4×3 / 0x-74×2 / 0x-28×2
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x25924c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x259250 add r11, sp, #32
 *   @0x259254 ldr r4, [pc, #0x43c]
 *   @0x259258 sub sp, sp, #164
 *   @0x25925c sub r10, r11, #36
 *   @0x259260 ldr r4, [pc, r4]
 *   @0x259264 str r0, [r11, #-0xa0]
 *   @0x259268 str r1, [r10, #-0x74]!
 *   @0x25926c mov r0, r10
 *   @0x259270 ldr r3, [r4]
 *   @0x259274 mov r7, r1
 *   @0x259278 mov r9, r2
 *   @0x25927c ldr r5, [r11, #0x4]
 *   @0x259280 mov r2, #6
 *   @0x259284 str r2, [r11, #-0x8c]
 *   @0x259288 str r3, [r11, #-0x28]
 *   @0x25928c bl 0x2423a4 <_Z23JS_CheckObjectCoercibleR6RValue>
 *   @0x259290 cmp r0, #1
 *   @0x259294 beq 0x259428 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x1dc>
 *   @0x259298 sub r8, r11, #136
 *   @0x25929c mov r1, r10
 *   @0x2592a0 mov r3, #0
 *   @0x2592a4 mvn r2, #-16777216
 *   @0x2592a8 mov r0, r8
 *   @0x2592ac str r3, [r11, #-0x88]
 *   @0x2592b0 str r3, [r11, #-0x84]
 *   @0x2592b4 str r3, [r11, #-0x80]
 *   @0x2592b8 str r2, [r11, #-0x7c]
 *   @0x2592bc bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x2592c0 cmp r0, #1
 *   @0x2592c4 beq 0x259428 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x1dc>
 *   @0x2592c8 ldr r2, [r5, #0xc]
 *   @0x2592cc ldr r3, [r11, #-0x88]
 *   @0x2592d0 bic r2, r2, #-16777216
 *   @0x2592d4 cmp r2, #6
 *   @0x2592d8 ldr r6, [r3]
 *   @0x2592dc beq 0x25944c <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x200>
 *   @0x2592e0 sub r9, r11, #120
 *   @0x2592e4 mov r1, r5
 *   @0x2592e8 mov r7, #0
 *   @0x2592ec mvn r10, #-16777216
 *   @0x2592f0 mov r0, r9
 *   @0x2592f4 str r7, [r11, #-0x78]
 *   @0x2592f8 str r7, [r11, #-0x74]
 *   @0x2592fc str r7, [r11, #-0x70]
 *   @0x259300 str r10, [r11, #-0x6c]
 *   @0x259304 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x259308 cmp r0, #1
 *   @0x25930c beq 0x25948c <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x240>
 *   @0x259310 ldr r3, [r11, #-0x78]
 *   @0x259314 mov r0, r6
 *   @0x259318 ldr r3, [r3]
 *   @0x25931c mov r1, r3
 *   @0x259320 str r3, [r11, #-0xa8]
 *   @0x259324 bl 0x110c04 <_Z11utf8_strstrPKcS0_>
 *   @0x259328 cmp r0, #0
 *   @0x25932c str r0, [r11, #-0xac]
 *   @0x259330 beq 0x2595e4 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x398>
 *   @0x259334 add r5, r5, #16
 *   @0x259338 mov r0, r5
 *   @0x25933c bl 0x24076c <_Z13JS_IsCallableR6RValue>
 *   @0x259340 cmp r0, #0
 *   @0x259344 str r0, [r11, #-0xa4]
 *   @0x259348 beq 0x25949c <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x250>
 *   @0x25934c ldr r12, [r11, #-0xac]
 *   @0x259350 sub lr, r11, #88
 *   @0x259354 ldm r9, {r0, r1, r2, r3}
 *   @0x259358 rsb r9, r6, r12
 *   @0x25935c ldr r12, [pc, #0x338]
 *   @0x259360 vmov s13, r9
 *   @0x259364 str r7, [r11, #-0x68]
 *   @0x259368 ldr r12, [pc, r12]
 *   @0x25936c str r7, [r11, #-0x64]
 *   @0x259370 vcvt.f64.s32 d7, s13
 *   @0x259374 str r7, [r11, #-0x60]
 *   @0x259378 stm lr, {r0, r1, r2, r3}
 *   @0x25937c ldm r8, {r0, r1, r2, r3}
 *   @0x259380 ldr r12, [r12]
 *   @0x259384 str lr, [sp]
 *   @0x259388 sub lr, r11, #56
 *   @0x25938c str r10, [r11, #-0x5c]
 *   @0x259390 stm lr, {r0, r1, r2, r3}
 *   @0x259394 vstr s14, [r11, #-72]
 *   @0x259398 mov r2, r5
 *   @0x25939c vstr s15, [r11, #-68]
 *   @0x2593a0 sub r1, r11, #104
 *   @0x2593a4 mov r0, r12
 *   @0x2593a8 mov r3, #3
 *   @0x2593ac str r7, [r11, #-0x3c]
 *   @0x2593b0 bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_>
 *   @0x2593b4 ldr r3, [r11, #-0x68]
 *   @0x2593b8 ldr r8, [r3]
 *   @0x2593bc mov r0, r8
 *   @0x2593c0 bl 0xb6538 <strlen@plt>
 *   @0x2593c4 mov r7, r0
 *   @0x2593c8 mov r0, r6
 *   @0x2593cc bl 0xb6538 <strlen@plt>
 *   @0x2593d0 add r7, r0, r7
 *   @0x2593d4 ldr r0, [r11, #-0xa8]
 *   @0x2593d8 add r3, r7, #14
 *   @0x2593dc bic r3, r3, #7
 *   @0x2593e0 sub sp, sp, r3
 *   @0x2593e4 bl 0xb6538 <strlen@plt>
 *   @0x2593e8 add r5, sp, #16
 *   @0x2593ec ldr lr, [r11, #-0xac]
 *   @0x2593f0 mov r1, r7
 *   @0x2593f4 ldr r2, [pc, #0x2a4]
 *   @0x2593f8 mov r3, r9
 *   @0x2593fc str r8, [sp, #0x4]
 *   @0x259400 str r6, [sp]
 *   @0x259404 add r2, pc, r2
 *   @0x259408 add r12, lr, r0
 *   @0x25940c mov r0, r5
 *   @0x259410 str r12, [sp, #0x8]
 *   @0x259414 bl 0xb65c8 <snprintf@plt>
 *   @0x259418 ldr r0, [r11, #-0xa0]
 *   @0x25941c mov r1, r5
 *   @0x259420 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x259424 b 0x259434 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x1e8>
 *   @0x259428 ldr r0, [pc, #0x274]
 *   @0x25942c add r0, pc, r0
 *   @0x259430 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x259434 ldr r2, [r11, #-0x28]
 *   @0x259438 ldr r3, [r4]
 *   @0x25943c cmp r2, r3
 *   @0x259440 bne 0x259694 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x448>
 *   @0x259444 sub sp, r11, #32
 *   @0x259448 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x25944c ldr r10, [r5]
 *   @0x259450 ldr r1, [pc, #0x250]
 *   @0x259454 ldr r0, [r10, #0x40]
 *   @0x259458 add r1, pc, r1
 *   @0x25945c bl 0xb6574 <strcmp@plt>
 *   @0x259460 cmp r0, #0
 *   @0x259464 bne 0x2592e0 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x259468 add r5, r5, #16
 *   @0x25946c str r8, [sp]
 *   @0x259470 str r5, [sp, #0x4]
 *   @0x259474 mov r1, r7
 *   @0x259478 ldr r0, [r11, #-0xa0]
 *   @0x25947c mov r2, r9
 *   @0x259480 mov r3, r10
 *   @0x259484 bl 0x258e3c <_Z33JS_String_prototype_replace_RegExR6RValueP9CInstanceS2_P12YYObjectBasePS_S5_>
 *   @0x259488 b 0x259434 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x1e8>
 *   @0x25948c ldr r0, [pc, #0x218]
 *   @0x259490 add r0, pc, r0
 *   @0x259494 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x259498 b 0x259434 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x1e8>
 *   @0x25949c ldr r12, [r11, #-0xa4]
 *   @0x2594a0 mov r1, r5
 *   @0x2594a4 sub r0, r11, #88
 *   @0x2594a8 str r10, [r11, #-0x4c]
 *   @0x2594ac str r12, [r11, #-0x58]
 *   @0x2594b0 str r12, [r11, #-0x54]
 *   @0x2594b4 str r12, [r11, #-0x50]
 *   @0x2594b8 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x2594bc cmp r0, #1
 *   @0x2594c0 beq 0x259684 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x438>
 *   @0x2594c4 cmp r0, #2
 *   @0x2594c8 beq 0x259434 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x1e8>
 *   @0x2594cc ldr r12, [r11, #-0xac]
 *   @0x2594d0 ldr r3, [r11, #-0x58]
 *   @0x2594d4 rsb r10, r6, r12
 *   @0x2594d8 ldr r1, [r11, #-0xa4]
 *   @0x2594dc add r0, r10, #15
 *   @0x2594e0 add r2, r10, #1
 *   @0x2594e4 bic r0, r0, #7
 *   @0x2594e8 ldr r12, [r3]
 *   @0x2594ec sub sp, sp, r0
 *   @0x2594f0 add r5, sp, #23
 *   @0x2594f4 str r12, [r11, #-0xb0]
 *   @0x2594f8 lsr r5, r5, #3
 *   @0x2594fc lsl r9, r5, #3
 *   @0x259500 mov r0, r9
 *   @0x259504 bl 0xb65b0 <memset@plt>
 *   @0x259508 mov r2, r10
 *   @0x25950c mov r1, r6
 *   @0x259510 mov r0, r9
 *   @0x259514 bl 0xb6568 <strncpy@plt>
 *   @0x259518 ldr lr, [r11, #-0xa4]
 *   @0x25951c ldr r0, [r11, #-0xa8]
 *   @0x259520 strb lr, [r10, r5, lsl #3]
 *   @0x259524 bl 0xb6538 <strlen@plt>
 *   @0x259528 ldr r1, [pc, #0x180]
 *   @0x25952c mov r3, #1
 *   @0x259530 mov r2, #242
 *   @0x259534 add r1, pc, r1
 *   @0x259538 add r10, r0, r10
 *   @0x25953c mov r0, #32768
 *   @0x259540 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x259544 mov r1, r9
 *   @0x259548 add r10, r6, r10
 *   @0x25954c mov r5, r0
 *   @0x259550 bl 0xb6628 <strcat@plt>
 *   @0x259554 ldr r12, [r11, #-0xb0]
 *   @0x259558 ldrb r3, [r12]
 *   @0x25955c cmp r3, #0
 *   @0x259560 beq 0x259618 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x3cc>
 *   @0x259564 ldr r2, [pc, #0x148]
 *   @0x259568 sub r8, r11, #104
 *   @0x25956c ldr r7, [r11, #-0xa4]
 *   @0x259570 add r2, pc, r2
 *   @0x259574 str r4, [r11, #-0xa4]
 *   @0x259578 str r2, [r11, #-0xac]
 *   @0x25957c b 0x2595a8 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x35c>
 *   @0x259580 mov r0, r5
 *   @0x259584 mov r1, r8
 *   @0x259588 strh r7, [r11, #-104]
 *   @0x25958c mov r6, r12
 *   @0x259590 strb r3, [r11, #-0x68]
 *   @0x259594 bl 0xb6628 <strcat@plt>
 *   @0x259598 ldrb r3, [r6, #0x1]
 *   @0x25959c add r12, r6, #1
 *   @0x2595a0 cmp r3, #0
 *   @0x2595a4 beq 0x259614 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x3c8>
 *   @0x2595a8 cmp r3, #36
 *   @0x2595ac bne 0x259580 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x334>
 *   @0x2595b0 mov r6, r12
 *   @0x2595b4 ldrb r4, [r6, #0x1]!
 *   @0x2595b8 cmp r4, #38
 *   @0x2595bc beq 0x259674 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x428>
 *   @0x2595c0 bls 0x2595f4 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x3a8>
 *   @0x2595c4 cmp r4, #39
 *   @0x2595c8 beq 0x259664 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x418>
 *   @0x2595cc cmp r4, #96
 *   @0x2595d0 bne 0x259634 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x3e8>
 *   @0x2595d4 mov r0, r5
 *   @0x2595d8 mov r1, r9
 *   @0x2595dc bl 0xb6628 <strcat@plt>
 *   @0x2595e0 b 0x259598 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x34c>
 *   @0x2595e4 ldr r0, [r11, #-0xa0]
 *   @0x2595e8 mov r1, r6
 *   @0x2595ec bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x2595f0 b 0x259434 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x1e8>
 *   @0x2595f4 cmp r4, #36
 *   @0x2595f8 bne 0x259634 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x3e8>
 *   @0x2595fc mov r0, r5
 *   @0x259600 bl 0xb6538 <strlen@plt>
 *   @0x259604 ldr r12, [r11, #-0xac]
 *   @0x259608 ldrh r3, [r12]
 *   @0x25960c strh r3, [r5, r0]
 *   @0x259610 b 0x259598 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x34c>
 *   @0x259614 ldr r4, [r11, #-0xa4]
 *   @0x259618 mov r1, r10
 *   @0x25961c mov r0, r5
 *   @0x259620 bl 0xb6628 <strcat@plt>
 *   @0x259624 ldr r0, [r11, #-0xa0]
 *   @0x259628 mov r1, r5
 *   @0x25962c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x259630 b 0x259434 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x1e8>
 *   @0x259634 mov r1, r8
 *   @0x259638 mov r0, r5
 *   @0x25963c strh r7, [r11, #-104]
 *   @0x259640 mov lr, #36
 *   @0x259644 strb lr, [r11, #-0x68]
 *   @0x259648 bl 0xb6628 <strcat@plt>
 *   @0x25964c mov r0, r5
 *   @0x259650 mov r1, r8
 *   @0x259654 strh r7, [r11, #-104]
 *   @0x259658 strb r4, [r11, #-0x68]
 *   @0x25965c bl 0xb6628 <strcat@plt>
 *   @0x259660 b 0x259598 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x34c>
 *   @0x259664 mov r0, r5
 *   @0x259668 mov r1, r10
 *   @0x25966c bl 0xb6628 <strcat@plt>
 *   @0x259670 b 0x259598 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x34c>
 *   @0x259674 mov r0, r5
 *   @0x259678 ldr r1, [r11, #-0xa8]
 *   @0x25967c bl 0xb6628 <strcat@plt>
 *   @0x259680 b 0x259598 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x34c>
 *   @0x259684 ldr r0, [pc, #0x2c]
 *   @0x259688 add r0, pc, r0
 *   @0x25968c bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x259690 b 0x259434 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x1e8>
 *   @0x259694 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x259698 ldrsheq r4, [r9], -r0
 *   @0x25969c andseq r4, r9, r0, asr #18
 *   @0x2596a0 muleq pc, r12, r7
 *   @0x2596a4 andeq r12, pc, r12, lsl r11
 *   @0x2596a8 ldrdeq r12, sp, [pc], -r4
 *   @0x2596ac strheq r12, [pc], -r8
 *   @0x2596b0 andeq sp, pc, r8, ror r6
 *   @0x2596b4 andeq r12, pc, r12, ror #17
 *   @0x2596b8 andeq r12, pc, r0, asr #17
 *
 * ══ §2/28 void b2DynamicTree::RayCast<b2WorldRayCastWrapper>(b2WorldRayCastWrapper*, b2RayCastInput const&) const  0x2cb8e0  size 1128  282 条（0x2cb8e0..0x2cbd48）
 * @func 0x2cb8e0 0x2cbd48  size 1128  282 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Free(void*)×3 / b2Alloc(int)×2 / 0xb65bc×2 / void b2DynamicTree::RayCast<b2WorldRayCastWrapper>(b2WorldRayCastWrapper*, b2RayCastInput const&) const+0x254 / void b2DynamicTree::RayCast<b2WorldRayCastWrapper>(b2WorldRayCastWrapper*, b2RayCastInput const&) const+0x278 / void b2DynamicTree::RayCast<b2WorldRayCastWrapper>(b2WorldRayCastWrapper*, b2RayCastInput const&) const+0x344 / 0xb6700
 * 字段偏移 top8: 0x448×10 / 0x44×9 / 0x10×5 / 0x44c×5 / 0xc×4 / 0x4×3 / 0x18×3 / 0x14×2
 * VFP 指令 129 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb8e0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2cb8e4 vpush {d8, d9, d10, d11, d12, d13, d14}
 *   @0x2cb8e8 vldr s18, [r2, #4]
 *   @0x2cb8ec vldr s24, [r2, #12]
 *   @0x2cb8f0 vsub.f32 s24, s24, s18
 *   @0x2cb8f4 vldr s19, [r2]
 *   @0x2cb8f8 vldr s25, [r2, #8]
 *   @0x2cb8fc sub sp, sp, #1104
 *   @0x2cb900 sub sp, sp, #4
 *   @0x2cb904 mov r6, r2
 *   @0x2cb908 mov r5, r0
 *   @0x2cb90c mov r10, r1
 *   @0x2cb910 vmul.f32 s14, s24, s24
 *   @0x2cb914 vsub.f32 s25, s25, s19
 *   @0x2cb918 vmla.f32 s14, s25, s25
 *   @0x2cb91c vsqrt.f32 s15, s14
 *   @0x2cb920 vcmp.f32 s15, s15
 *   @0x2cb924 vmrs APSR_nzcv, fpscr
 *   @0x2cb928 bne 0x2cbd38 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x458>
 *   @0x2cb92c vldr s14, [pc, #1004]
 *   @0x2cb930 vcmpe.f32 s15, s14
 *   @0x2cb934 vldr s26, [r6, #16]
 *   @0x2cb938 add r8, sp, #80
 *   @0x2cb93c ldr r1, [r5]
 *   @0x2cb940 sub r3, r8, #8
 *   @0x2cb944 add r9, sp, #48
 *   @0x2cb948 str r3, [sp, #0x10]
 *   @0x2cb94c vmrs APSR_nzcv, fpscr
 *   @0x2cb950 vmovpl.f32 s21, #1.000000e+00
 *   @0x2cb954 sub r2, r9, #12
 *   @0x2cb958 str r2, [sp, #0xc]
 *   @0x2cb95c add r2, sp, #28
 *   @0x2cb960 str r2, [sp, #0x14]
 *   @0x2cb964 mov r2, #1
 *   @0x2cb968 mov r11, r3
 *   @0x2cb96c str r3, [sp, #0x44]
 *   @0x2cb970 add r7, sp, #64
 *   @0x2cb974 mov r3, #256
 *   @0x2cb978 str r1, [sp, #0x48]
 *   @0x2cb97c str r3, [sp, #0x44c]
 *   @0x2cb980 mov r3, r2
 *   @0x2cb984 vdivpl.f32 s21, s21, s15
 *   @0x2cb988 vmov.f32 s17, s19
 *   @0x2cb98c vmulpl.f32 s28, s25, s21
 *   @0x2cb990 vmulpl.f32 s21, s24, s21
 *   @0x2cb994 vmla.f32 s17, s26, s25
 *   @0x2cb998 vmov.f32 s20, s18
 *   @0x2cb99c vmla.f32 s20, s26, s24
 *   @0x2cb9a0 vmovmi.f32 s21, s24
 *   @0x2cb9a4 vneg.f32 s27, s21
 *   @0x2cb9a8 vmovmi.f32 s28, s25
 *   @0x2cb9ac vcmpe.f32 s27, #0
 *   @0x2cb9b0 vmrs APSR_nzcv, fpscr
 *   @0x2cb9b4 vcmpe.f32 s28, #0
 *   @0x2cb9b8 vmovgt.f32 s21, s27
 *   @0x2cb9bc vmrs APSR_nzcv, fpscr
 *   @0x2cb9c0 vcmpe.f32 s19, s17
 *   @0x2cb9c4 vnegle.f32 s22, s28
 *   @0x2cb9c8 vmovgt.f32 s22, s28
 *   @0x2cb9cc vmrs APSR_nzcv, fpscr
 *   @0x2cb9d0 vcmpe.f32 s18, s20
 *   @0x2cb9d4 vmovpl.f32 s16, s17
 *   @0x2cb9d8 vmovmi.f32 s16, s19
 *   @0x2cb9dc vmrs APSR_nzcv, fpscr
 *   @0x2cb9e0 vcmp.f32 s19, s17
 *   @0x2cb9e4 vmovpl.f32 s23, s20
 *   @0x2cb9e8 vmovmi.f32 s23, s18
 *   @0x2cb9ec vmrs APSR_nzcv, fpscr
 *   @0x2cb9f0 vcmp.f32 s18, s20
 *   @0x2cb9f4 vmovgt.f32 s17, s19
 *   @0x2cb9f8 vmrs APSR_nzcv, fpscr
 *   @0x2cb9fc vmov.f32 s29, #5.000000e-01
 *   @0x2cba00 vmovgt.f32 s20, s18
 *   @0x2cba04 b 0x2cba10 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x130>
 *   @0x2cba08 cmp r3, #0
 *   @0x2cba0c ble 0x2cbb34 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x254>
 *   @0x2cba10 sub r3, r3, #1
 *   @0x2cba14 str r3, [sp, #0x448]
 *   @0x2cba18 ldr r12, [r11, r3, lsl #2]
 *   @0x2cba1c add r2, r11, r3, lsl #2
 *   @0x2cba20 cmn r12, #1
 *   @0x2cba24 beq 0x2cba08 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x128>
 *   @0x2cba28 add r12, r12, r12, lsl #3
 *   @0x2cba2c ldr r4, [r5, #0x4]
 *   @0x2cba30 lsl r12, r12, #2
 *   @0x2cba34 add r4, r4, r12
 *   @0x2cba38 vldr s15, [r4, #8]
 *   @0x2cba3c vsub.f32 s14, s16, s15
 *   @0x2cba40 vldr s13, [r4, #12]
 *   @0x2cba44 vldr s12, [r4]
 *   @0x2cba48 vldr s11, [r4, #4]
 *   @0x2cba4c vcmpe.f32 s14, #0
 *   @0x2cba50 vmrs APSR_nzcv, fpscr
 *   @0x2cba54 bgt 0x2cba08 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x128>
 *   @0x2cba58 vsub.f32 s14, s23, s13
 *   @0x2cba5c vcmpe.f32 s14, #0
 *   @0x2cba60 vmrs APSR_nzcv, fpscr
 *   @0x2cba64 bgt 0x2cba08 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x128>
 *   @0x2cba68 vsub.f32 s14, s12, s17
 *   @0x2cba6c vcmpe.f32 s14, #0
 *   @0x2cba70 vmrs APSR_nzcv, fpscr
 *   @0x2cba74 bgt 0x2cba08 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x128>
 *   @0x2cba78 vsub.f32 s14, s11, s20
 *   @0x2cba7c vcmpe.f32 s14, #0
 *   @0x2cba80 vmrs APSR_nzcv, fpscr
 *   @0x2cba84 bgt 0x2cba08 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x128>
 *   @0x2cba88 vadd.f32 s14, s13, s11
 *   @0x2cba8c vmov.f32 s9, s18
 *   @0x2cba90 vmls.f32 s9, s14, s29
 *   @0x2cba94 vadd.f32 s10, s15, s12
 *   @0x2cba98 vmov.f32 s14, s9
 *   @0x2cba9c vmov.f32 s9, s19
 *   @0x2cbaa0 vmls.f32 s9, s10, s29
 *   @0x2cbaa4 vmul.f32 s14, s28, s14
 *   @0x2cbaa8 vmla.f32 s14, s27, s9
 *   @0x2cbaac vsub.f32 s13, s13, s11
 *   @0x2cbab0 vsub.f32 s12, s15, s12
 *   @0x2cbab4 vcmpe.f32 s14, #0
 *   @0x2cbab8 vmul.f32 s15, s13, s29
 *   @0x2cbabc vmrs APSR_nzcv, fpscr
 *   @0x2cbac0 vmul.f32 s13, s12, s29
 *   @0x2cbac4 ble 0x2cbb58 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x278>
 *   @0x2cbac8 vmul.f32 s15, s22, s15
 *   @0x2cbacc vmla.f32 s15, s21, s13
 *   @0x2cbad0 vsub.f32 s15, s14, s15
 *   @0x2cbad4 vcmpe.f32 s15, #0
 *   @0x2cbad8 vmrs APSR_nzcv, fpscr
 *   @0x2cbadc bgt 0x2cba08 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x128>
 *   @0x2cbae0 ldr r1, [r4, #0x18]
 *   @0x2cbae4 cmn r1, #1
 *   @0x2cbae8 beq 0x2cbb60 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x280>
 *   @0x2cbaec ldr r0, [sp, #0x44c]
 *   @0x2cbaf0 cmp r3, r0
 *   @0x2cbaf4 beq 0x2cbc30 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x350>
 *   @0x2cbaf8 str r1, [r2]
 *   @0x2cbafc ldr r3, [sp, #0x448]
 *   @0x2cbb00 ldr r2, [sp, #0x44c]
 *   @0x2cbb04 add r3, r3, #1
 *   @0x2cbb08 str r3, [sp, #0x448]
 *   @0x2cbb0c cmp r3, r2
 *   @0x2cbb10 beq 0x2cbc80 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x3a0>
 *   @0x2cbb14 ldr r2, [r4, #0x1c]
 *   @0x2cbb18 str r2, [r11, r3, lsl #2]
 *   @0x2cbb1c ldr r3, [sp, #0x448]
 *   @0x2cbb20 ldr r11, [sp, #0x44]
 *   @0x2cbb24 add r3, r3, #1
 *   @0x2cbb28 str r3, [sp, #0x448]
 *   @0x2cbb2c cmp r3, #0
 *   @0x2cbb30 bgt 0x2cba10 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x130>
 *   @0x2cbb34 sub r8, r8, #8
 *   @0x2cbb38 cmp r11, r8
 *   @0x2cbb3c beq 0x2cbb48 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x268>
 *   @0x2cbb40 mov r0, r11
 *   @0x2cbb44 bl 0x2c6a70 <_Z6b2FreePv>
 *   @0x2cbb48 add sp, sp, #1104
 *   @0x2cbb4c add sp, sp, #4
 *   @0x2cbb50 vpop {d8, d9, d10, d11, d12, d13, d14}
 *   @0x2cbb54 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2cbb58 vneg.f32 s14, s14
 *   @0x2cbb5c b 0x2cbac8 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x1e8>
 *   @0x2cbb60 ldr r2, [r10]
 *   @0x2cbb64 add r3, r6, #8
 *   @0x2cbb68 ldm r6, {r0, r1}
 *   @0x2cbb6c vstr s26, [r7]
 *   @0x2cbb70 ldr lr, [r2, #0x4]
 *   @0x2cbb74 mov r2, r9
 *   @0x2cbb78 stm r9, {r0, r1}
 *   @0x2cbb7c add r12, lr, r12
 *   @0x2cbb80 ldm r3, {r0, r1}
 *   @0x2cbb84 ldr r3, [r12, #0x10]
 *   @0x2cbb88 stmdb r7, {r0, r1}
 *   @0x2cbb8c ldr r1, [sp, #0xc]
 *   @0x2cbb90 ldr r4, [r3, #0x10]
 *   @0x2cbb94 ldr lr, [r3, #0x14]
 *   @0x2cbb98 ldr r0, [r4, #0xc]
 *   @0x2cbb9c ldr r3, [r4, #0x8]
 *   @0x2cbba0 ldr r12, [r0]
 *   @0x2cbba4 add r3, r3, #12
 *   @0x2cbba8 str lr, [sp]
 *   @0x2cbbac ldr r12, [r12, #0x18]
 *   @0x2cbbb0 blx r12
 *   @0x2cbbb4 cmp r0, #0
 *   @0x2cbbb8 vldreq s15, [r7]
 *   @0x2cbbbc bne 0x2cbcc4 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x3e4>
 *   @0x2cbbc0 vcmp.f32 s15, #0
 *   @0x2cbbc4 vmrs APSR_nzcv, fpscr
 *   @0x2cbbc8 beq 0x2cbd24 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x444>
 *   @0x2cbbcc vcmpe.f32 s15, #0
 *   @0x2cbbd0 vmrs APSR_nzcv, fpscr
 *   @0x2cbbd4 ble 0x2cbc24 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x344>
 *   @0x2cbbd8 vmov.f32 s17, s19
 *   @0x2cbbdc vmov.f32 s20, s18
 *   @0x2cbbe0 vmla.f32 s17, s25, s15
 *   @0x2cbbe4 vmla.f32 s20, s24, s15
 *   @0x2cbbe8 vcmpe.f32 s19, s17
 *   @0x2cbbec vmrs APSR_nzcv, fpscr
 *   @0x2cbbf0 vcmpe.f32 s18, s20
 *   @0x2cbbf4 vmovpl.f32 s16, s17
 *   @0x2cbbf8 vmovmi.f32 s16, s19
 *   @0x2cbbfc vmrs APSR_nzcv, fpscr
 *   @0x2cbc00 vcmp.f32 s19, s17
 *   @0x2cbc04 vmovpl.f32 s23, s20
 *   @0x2cbc08 vmovmi.f32 s23, s18
 *   @0x2cbc0c vmrs APSR_nzcv, fpscr
 *   @0x2cbc10 vcmp.f32 s18, s20
 *   @0x2cbc14 vmovgt.f32 s17, s19
 *   @0x2cbc18 vmrs APSR_nzcv, fpscr
 *   @0x2cbc1c vmov.f32 s26, s15
 *   @0x2cbc20 vmovgt.f32 s20, s18
 *   @0x2cbc24 ldr r3, [sp, #0x448]
 *   @0x2cbc28 ldr r11, [sp, #0x44]
 *   @0x2cbc2c b 0x2cba08 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x128>
 *   @0x2cbc30 lsl r0, r3, #3
 *   @0x2cbc34 ldr r11, [sp, #0x44]
 *   @0x2cbc38 lsl r3, r3, #1
 *   @0x2cbc3c str r3, [sp, #0x44c]
 *   @0x2cbc40 bl 0x2c6a6c <_Z7b2Alloci>
 *   @0x2cbc44 ldr r2, [sp, #0x448]
 *   @0x2cbc48 mov r1, r11
 *   @0x2cbc4c lsl r2, r2, #2
 *   @0x2cbc50 str r0, [sp, #0x44]
 *   @0x2cbc54 bl 0xb65bc <memcpy@plt>
 *   @0x2cbc58 ldr r3, [sp, #0x10]
 *   @0x2cbc5c cmp r11, r3
 *   @0x2cbc60 beq 0x2cbc6c <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x38c>
 *   @0x2cbc64 mov r0, r11
 *   @0x2cbc68 bl 0x2c6a70 <_Z6b2FreePv>
 *   @0x2cbc6c ldr r2, [sp, #0x448]
 *   @0x2cbc70 ldr r11, [sp, #0x44]
 *   @0x2cbc74 ldr r1, [r4, #0x18]
 *   @0x2cbc78 add r2, r11, r2, lsl #2
 *   @0x2cbc7c b 0x2cbaf8 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x218>
 *   @0x2cbc80 lsl r0, r3, #3
 *   @0x2cbc84 lsl r3, r3, #1
 *   @0x2cbc88 str r3, [sp, #0x44c]
 *   @0x2cbc8c bl 0x2c6a6c <_Z7b2Alloci>
 *   @0x2cbc90 ldr r2, [sp, #0x448]
 *   @0x2cbc94 mov r1, r11
 *   @0x2cbc98 lsl r2, r2, #2
 *   @0x2cbc9c str r0, [sp, #0x44]
 *   @0x2cbca0 bl 0xb65bc <memcpy@plt>
 *   @0x2cbca4 ldr r2, [sp, #0x10]
 *   @0x2cbca8 cmp r11, r2
 *   @0x2cbcac beq 0x2cbcb8 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x3d8>
 *   @0x2cbcb0 mov r0, r11
 *   @0x2cbcb4 bl 0x2c6a70 <_Z6b2FreePv>
 *   @0x2cbcb8 ldr r11, [sp, #0x44]
 *   @0x2cbcbc ldr r3, [sp, #0x448]
 *   @0x2cbcc0 b 0x2cbb14 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x234>
 *   @0x2cbcc4 vmov.f32 s10, #1.000000e+00
 *   @0x2cbcc8 ldr r0, [r10, #0x4]
 *   @0x2cbccc vldr s15, [sp, #44]
 *   @0x2cbcd0 vldr s14, [r7, #-8]
 *   @0x2cbcd4 vldr s13, [sp, #60]
 *   @0x2cbcd8 vldr s12, [r9]
 *   @0x2cbcdc ldr r12, [r0]
 *   @0x2cbce0 vstr s15, [sp]
 *   @0x2cbce4 vldr s11, [sp, #52]
 *   @0x2cbce8 mov r1, r4
 *   @0x2cbcec add r2, sp, #28
 *   @0x2cbcf0 ldr r3, [sp, #0xc]
 *   @0x2cbcf4 ldr r12, [r12, #0x8]
 *   @0x2cbcf8 vmul.f32 s13, s15, s13
 *   @0x2cbcfc vmul.f32 s14, s15, s14
 *   @0x2cbd00 vsub.f32 s15, s10, s15
 *   @0x2cbd04 vmla.f32 s13, s15, s11
 *   @0x2cbd08 vmla.f32 s14, s15, s12
 *   @0x2cbd0c vstr s13, [sp, #32]
 *   @0x2cbd10 vstr s14, [sp, #28]
 *   @0x2cbd14 blx r12
 *   @0x2cbd18 vmov s15, r0
 *   @0x2cbd1c b 0x2cbbc0 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x2e0>
 *   @0x2cbd20 strlo r0, [r0], #-0
 *   @0x2cbd24 ldr r0, [sp, #0x44]
 *   @0x2cbd28 sub r8, r8, #8
 *   @0x2cbd2c cmp r0, r8
 *   @0x2cbd30 bne 0x2cbb44 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x264>
 *   @0x2cbd34 b 0x2cbb48 <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x268>
 *   @0x2cbd38 vmov r0, s14
 *   @0x2cbd3c bl 0xb6700 <sqrtf@plt>
 *   @0x2cbd40 vmov s15, r0
 *   @0x2cbd44 b 0x2cb92c <_ZNK13b2DynamicTree7RayCastI21b2WorldRayCastWrapperEEvPT_RK14b2RayCastInput+0x4c>
 *
 * ══ §3/28 _Draw_RoundRect(float, float, float, float, float, float, unsigned int, unsigned int, bool)  0x16b31c  size 1120  280 条（0x16b31c..0x16b77c）
 * @func 0x16b31c 0x16b77c  size 1120  280 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x16b328→0x4859c0, 0x16b3b0→0x4899a8, 0x16b3e0→0x4859ac, 0x16b428→0x4898a4, 0x16b42c→0x4897a0, 0x16b4b0→0x4898a4, 0x16b4b8→0x4897a0, 0x16b578→0x4897a0
 * 调用序列: Graphics::AllocVerts(ePrimType, void*, int, int)×2 / _Draw_RoundRect(float, float, float, float, float, float, unsigned int, unsigned int, bool)+0x244 / _Draw_RoundRect(float, float, float, float, float, float, unsigned int, unsigned int, bool)+0x2f0
 * 字段偏移 top8: 0x4×8 / 0xc×7 / 0x8×6 / 0x14×5 / 0x10×5 / 0x-24×4 / 0x-1c×4 / 0x-20×4
 * VFP 指令 87 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16b31c vmov s9, r0
 *   @0x16b320 vmov s10, r2
 *   @0x16b324 vmov s12, r3
 *   @0x16b328 ldr r3, [pc, #0x434]
 *   @0x16b32c vsub.f32 s13, s10, s9
 *   @0x16b330 vmov s11, r1
 *   @0x16b334 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x16b338 vpush {d8, d9, d10}
 *   @0x16b33c sub sp, sp, #20
 *   @0x16b340 vldr s16, [sp, #80]
 *   @0x16b344 vldr s17, [sp, #84]
 *   @0x16b348 ldr r5, [pc, #0x418]
 *   @0x16b34c ldrb r8, [sp, #0x60]
 *   @0x16b350 add r5, pc, r5
 *   @0x16b354 ldr r6, [sp, #0x58]
 *   @0x16b358 ldr r4, [sp, #0x5c]
 *   @0x16b35c str r8, [sp, #0x8]
 *   @0x16b360 vsub.f32 s14, s12, s11
 *   @0x16b364 vabs.f32 s13, s13
 *   @0x16b368 vabs.f32 s14, s14
 *   @0x16b36c vcmp.f32 s13, s16
 *   @0x16b370 vmov.f32 s15, #5.000000e-01
 *   @0x16b374 vmrs APSR_nzcv, fpscr
 *   @0x16b378 vcmp.f32 s14, s17
 *   @0x16b37c vmovmi.f32 s16, s13
 *   @0x16b380 vmrs APSR_nzcv, fpscr
 *   @0x16b384 vmovmi.f32 s17, s14
 *   @0x16b388 cmp r8, #0
 *   @0x16b38c vmul.f32 s19, s16, s15
 *   @0x16b390 vmul.f32 s18, s17, s15
 *   @0x16b394 vadd.f32 s10, s9, s10
 *   @0x16b398 vadd.f32 s12, s11, s12
 *   @0x16b39c vmul.f32 s21, s10, s15
 *   @0x16b3a0 vnmls.f32 s19, s13, s15
 *   @0x16b3a4 vmul.f32 s20, s12, s15
 *   @0x16b3a8 vnmls.f32 s18, s14, s15
 *   @0x16b3ac beq 0x16b728 <_Z15_Draw_RoundRectffffffjjb+0x40c>
 *   @0x16b3b0 ldr r1, [pc, #0x3b4]
 *   @0x16b3b4 mov r0, #3
 *   @0x16b3b8 ldr r3, [r5, r3]
 *   @0x16b3bc mov r2, #24
 *   @0x16b3c0 ldr r7, [r5, r1]
 *   @0x16b3c4 ldr r1, [r3]
 *   @0x16b3c8 ldr r3, [r7]
 *   @0x16b3cc ldr r1, [r1]
 *   @0x16b3d0 add r3, r3, #6
 *   @0x16b3d4 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x16b3d8 ldr r12, [r7]
 *   @0x16b3dc mov r10, #0
 *   @0x16b3e0 ldr r3, [pc, #0x388]
 *   @0x16b3e4 vstr s21, [r0]
 *   @0x16b3e8 cmp r12, #0
 *   @0x16b3ec add r7, r12, #3
 *   @0x16b3f0 vstr s20, [r0, #4]
 *   @0x16b3f4 add r1, r0, #24
 *   @0x16b3f8 movge r7, r12
 *   @0x16b3fc ldr r3, [r5, r3]
 *   @0x16b400 asrs r7, r7, #2
 *   @0x16b404 vldr s15, [r3]
 *   @0x16b408 str r10, [r0, #0x14]
 *   @0x16b40c vstr s15, [r0, #8]
 *   @0x16b410 str r6, [r0, #0xc]
 *   @0x16b414 str r10, [r0, #0x10]
 *   @0x16b418 bmi 0x16b754 <_Z15_Draw_RoundRectffffffjjb+0x438>
 *   @0x16b41c vadd.f32 s11, s21, s19
 *   @0x16b420 lsl r11, r7, #1
 *   @0x16b424 add r9, r11, r7
 *   @0x16b428 ldr r6, [pc, #0x344]
 *   @0x16b42c ldr r2, [pc, #0x344]
 *   @0x16b430 add r3, r0, #48
 *   @0x16b434 lsl r9, r9, #3
 *   @0x16b438 str r11, [sp, #0x4]
 *   @0x16b43c add r8, r9, #72
 *   @0x16b440 ldr r6, [r5, r6]
 *   @0x16b444 ldr r2, [r5, r2]
 *   @0x16b448 add r8, r0, r8
 *   @0x16b44c vadd.f32 s12, s20, s18
 *   @0x16b450 vmov.f32 s14, #5.000000e-01
 *   @0x16b454 vldmia r6!, {s13}
 *   @0x16b458 add r3, r3, #24
 *   @0x16b45c vmul.f32 s13, s13, s16
 *   @0x16b460 vmov.f32 s10, s11
 *   @0x16b464 vmla.f32 s10, s13, s14
 *   @0x16b468 vstr s10, [r3, #-48]
 *   @0x16b46c vldmia r2!, {s13}
 *   @0x16b470 vmul.f32 s13, s13, s17
 *   @0x16b474 vstr s15, [r3, #-40]
 *   @0x16b478 str r4, [r3, #-0x24]
 *   @0x16b47c str r10, [r3, #-0x1c]
 *   @0x16b480 str r10, [r3, #-0x20]
 *   @0x16b484 vmov.f32 s10, s12
 *   @0x16b488 vmla.f32 s10, s13, s14
 *   @0x16b48c vstr s10, [r3, #-44]
 *   @0x16b490 cmp r3, r8
 *   @0x16b494 bne 0x16b454 <_Z15_Draw_RoundRectffffffjjb+0x138>
 *   @0x16b498 add r2, r9, #24
 *   @0x16b49c add r2, r1, r2
 *   @0x16b4a0 add r6, r12, r12, lsr #31
 *   @0x16b4a4 asr r6, r6, #1
 *   @0x16b4a8 cmp r6, r7
 *   @0x16b4ac blt 0x16b560 <_Z15_Draw_RoundRectffffffjjb+0x244>
 *   @0x16b4b0 ldr r3, [pc, #0x2bc]
 *   @0x16b4b4 vadd.f32 s11, s20, s18
 *   @0x16b4b8 ldr r11, [pc, #0x2b8]
 *   @0x16b4bc add r9, r6, r6, lsl #1
 *   @0x16b4c0 ldr r8, [sp, #0x4]
 *   @0x16b4c4 ldr r3, [r5, r3]
 *   @0x16b4c8 lsl r9, r9, #3
 *   @0x16b4cc add r10, r8, r7
 *   @0x16b4d0 add r9, r9, #48
 *   @0x16b4d4 lsl r8, r7, #2
 *   @0x16b4d8 str r3, [sp, #0xc]
 *   @0x16b4dc sub r10, r9, r10, lsl #3
 *   @0x16b4e0 ldr r11, [r5, r11]
 *   @0x16b4e4 add r3, r2, #24
 *   @0x16b4e8 add r10, r2, r10
 *   @0x16b4ec vsub.f32 s12, s21, s19
 *   @0x16b4f0 str r11, [sp]
 *   @0x16b4f4 ldr r11, [sp, #0xc]
 *   @0x16b4f8 add r9, r8, r11
 *   @0x16b4fc ldr r11, [sp]
 *   @0x16b500 add r8, r8, r11
 *   @0x16b504 mov r11, #0
 *   @0x16b508 vmov.f32 s14, #5.000000e-01
 *   @0x16b50c vldmia r9!, {s13}
 *   @0x16b510 add r3, r3, #24
 *   @0x16b514 vmul.f32 s13, s13, s16
 *   @0x16b518 vmov.f32 s10, s12
 *   @0x16b51c vmla.f32 s10, s13, s14
 *   @0x16b520 vstr s10, [r3, #-48]
 *   @0x16b524 vldmia r8!, {s13}
 *   @0x16b528 vmul.f32 s13, s13, s17
 *   @0x16b52c vstr s15, [r3, #-40]
 *   @0x16b530 str r4, [r3, #-0x24]
 *   @0x16b534 str r11, [r3, #-0x1c]
 *   @0x16b538 str r11, [r3, #-0x20]
 *   @0x16b53c vmov.f32 s10, s11
 *   @0x16b540 vmla.f32 s10, s13, s14
 *   @0x16b544 vstr s10, [r3, #-44]
 *   @0x16b548 cmp r3, r10
 *   @0x16b54c bne 0x16b50c <_Z15_Draw_RoundRectffffffjjb+0x1f0>
 *   @0x16b550 add r3, r6, #1
 *   @0x16b554 rsb r3, r7, r3
 *   @0x16b558 add r3, r3, r3, lsl #1
 *   @0x16b55c add r2, r2, r3, lsl #3
 *   @0x16b560 ldr r3, [sp, #0x4]
 *   @0x16b564 add r7, r3, r7
 *   @0x16b568 cmp r7, r6
 *   @0x16b56c blt 0x16b60c <_Z15_Draw_RoundRectffffffjjb+0x2f0>
 *   @0x16b570 vsub.f32 s11, s21, s19
 *   @0x16b574 add r10, r6, r6, lsl #1
 *   @0x16b578 ldr r3, [pc, #0x1f8]
 *   @0x16b57c add r9, r7, r7, lsl #1
 *   @0x16b580 ldr r8, [pc, #0x1ec]
 *   @0x16b584 lsl r10, r10, #3
 *   @0x16b588 rsb r9, r10, r9, lsl #3
 *   @0x16b58c lsl r10, r6, #2
 *   @0x16b590 ldr r11, [r5, r3]
 *   @0x16b594 add r9, r9, #48
 *   @0x16b598 ldr r8, [r5, r8]
 *   @0x16b59c add r9, r2, r9
 *   @0x16b5a0 add r3, r2, #24
 *   @0x16b5a4 add r8, r10, r8
 *   @0x16b5a8 add r10, r10, r11
 *   @0x16b5ac mov r11, #0
 *   @0x16b5b0 vsub.f32 s12, s20, s18
 *   @0x16b5b4 vmov.f32 s14, #5.000000e-01
 *   @0x16b5b8 vldmia r8!, {s13}
 *   @0x16b5bc add r3, r3, #24
 *   @0x16b5c0 vmul.f32 s13, s13, s16
 *   @0x16b5c4 vmov.f32 s10, s11
 *   @0x16b5c8 vmla.f32 s10, s13, s14
 *   @0x16b5cc vstr s10, [r3, #-48]
 *   @0x16b5d0 vldmia r10!, {s13}
 *   @0x16b5d4 vmul.f32 s13, s13, s17
 *   @0x16b5d8 vstr s15, [r3, #-40]
 *   @0x16b5dc str r4, [r3, #-0x24]
 *   @0x16b5e0 str r11, [r3, #-0x1c]
 *   @0x16b5e4 str r11, [r3, #-0x20]
 *   @0x16b5e8 vmov.f32 s10, s12
 *   @0x16b5ec vmla.f32 s10, s13, s14
 *   @0x16b5f0 vstr s10, [r3, #-44]
 *   @0x16b5f4 cmp r3, r9
 *   @0x16b5f8 bne 0x16b5b8 <_Z15_Draw_RoundRectffffffjjb+0x29c>
 *   @0x16b5fc rsb r3, r6, r7
 *   @0x16b600 add r3, r3, #1
 *   @0x16b604 add r3, r3, r3, lsl #1
 *   @0x16b608 add r2, r2, r3, lsl #3
 *   @0x16b60c cmp r7, r12
 *   @0x16b610 bgt 0x16b6b0 <_Z15_Draw_RoundRectffffffjjb+0x394>
 *   @0x16b614 vadd.f32 s19, s21, s19
 *   @0x16b618 add r8, r12, r12, lsl #1
 *   @0x16b61c ldr r6, [pc, #0x150]
 *   @0x16b620 add r9, r7, r7, lsl #1
 *   @0x16b624 ldr r10, [pc, #0x14c]
 *   @0x16b628 lsl r8, r8, #3
 *   @0x16b62c add r8, r8, #48
 *   @0x16b630 lsl r3, r7, #2
 *   @0x16b634 ldr r6, [r5, r6]
 *   @0x16b638 ldr r5, [r5, r10]
 *   @0x16b63c sub r8, r8, r9, lsl #3
 *   @0x16b640 add r6, r3, r6
 *   @0x16b644 add r8, r2, r8
 *   @0x16b648 add r5, r3, r5
 *   @0x16b64c add r3, r2, #24
 *   @0x16b650 mov r9, #0
 *   @0x16b654 vsub.f32 s18, s20, s18
 *   @0x16b658 vmov.f32 s14, #5.000000e-01
 *   @0x16b65c vldmia r6!, {s13}
 *   @0x16b660 add r3, r3, #24
 *   @0x16b664 vmul.f32 s13, s13, s16
 *   @0x16b668 vmov.f32 s12, s19
 *   @0x16b66c vmla.f32 s12, s13, s14
 *   @0x16b670 vstr s12, [r3, #-48]
 *   @0x16b674 vldmia r5!, {s13}
 *   @0x16b678 vmul.f32 s13, s13, s17
 *   @0x16b67c vstr s15, [r3, #-40]
 *   @0x16b680 str r4, [r3, #-0x24]
 *   @0x16b684 str r9, [r3, #-0x1c]
 *   @0x16b688 str r9, [r3, #-0x20]
 *   @0x16b68c vmov.f32 s10, s18
 *   @0x16b690 vmla.f32 s10, s13, s14
 *   @0x16b694 vstr s10, [r3, #-44]
 *   @0x16b698 cmp r3, r8
 *   @0x16b69c bne 0x16b65c <_Z15_Draw_RoundRectffffffjjb+0x340>
 *   @0x16b6a0 add r12, r12, #1
 *   @0x16b6a4 rsb r7, r7, r12
 *   @0x16b6a8 add r7, r7, r7, lsl #1
 *   @0x16b6ac add r2, r2, r7, lsl #3
 *   @0x16b6b0 ldr r12, [r1]
 *   @0x16b6b4 ldr r3, [r1, #0x4]
 *   @0x16b6b8 ldr r5, [r1, #0x8]
 *   @0x16b6bc ldr r4, [r1, #0xc]
 *   @0x16b6c0 ldr r8, [sp, #0x8]
 *   @0x16b6c4 str r12, [r2]
 *   @0x16b6c8 str r3, [r2, #0x4]
 *   @0x16b6cc cmp r8, #0
 *   @0x16b6d0 str r5, [r2, #0x8]
 *   @0x16b6d4 str r4, [r2, #0xc]
 *   @0x16b6d8 ldr r12, [r1, #0x10]
 *   @0x16b6dc ldr r3, [r1, #0x14]
 *   @0x16b6e0 str r12, [r2, #0x10]
 *   @0x16b6e4 str r3, [r2, #0x14]
 *   @0x16b6e8 beq 0x16b71c <_Z15_Draw_RoundRectffffffjjb+0x400>
 *   @0x16b6ec ldr r2, [r1]
 *   @0x16b6f0 ldr r3, [r1, #0x4]
 *   @0x16b6f4 ldr r4, [r1, #0x8]
 *   @0x16b6f8 ldr r12, [r1, #0xc]
 *   @0x16b6fc str r2, [r0]
 *   @0x16b700 str r3, [r0, #0x4]
 *   @0x16b704 str r4, [r0, #0x8]
 *   @0x16b708 str r12, [r0, #0xc]
 *   @0x16b70c ldr r2, [r1, #0x10]
 *   @0x16b710 ldr r3, [r1, #0x14]
 *   @0x16b714 str r2, [r0, #0x10]
 *   @0x16b718 str r3, [r0, #0x14]
 *   @0x16b71c add sp, sp, #20
 *   @0x16b720 vpop {d8, d9, d10}
 *   @0x16b724 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x16b728 ldr r1, [pc, #0x3c]
 *   @0x16b72c mov r0, #6
 *   @0x16b730 ldr r3, [r5, r3]
 *   @0x16b734 mov r2, #24
 *   @0x16b738 ldr r7, [r5, r1]
 *   @0x16b73c ldr r1, [r3]
 *   @0x16b740 ldr r3, [r7]
 *   @0x16b744 ldr r1, [r1]
 *   @0x16b748 add r3, r3, r0
 *   @0x16b74c bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x16b750 b 0x16b3d8 <_Z15_Draw_RoundRectffffffjjb+0xbc>
 *   @0x16b754 lsl r2, r7, #1
 *   @0x16b758 str r2, [sp, #0x4]
 *   @0x16b75c mov r2, r1
 *   @0x16b760 b 0x16b4a0 <_Z15_Draw_RoundRectffffffjjb+0x184>
 *   @0x16b764 .word 0xffffe4e0
 *   @0x16b768 eoreq r6, r8, r0, lsl #18
 *   @0x16b76c .word 0xffffe528
 *   @0x16b770 .word 0xffffbcd0
 *   @0x16b774 .word 0xffffe52c
 *   @0x16b778 .word 0xffffe530
 *
 * ══ §4/28 b2GearJoint::SolvePositionConstraints(b2SolverData const&)  0x2e3c04  size 1120  280 条（0x2e3c04..0x2e4064）
 * @func 0x2e3c04 0x2e4064  size 1120  280 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6580×4 / 0xb658c×4
 * 字段偏移 top8: 0x50×2 / 0xa0×1 / 0xa4×1 / 0xa8×1 / 0xac×1 / 0x18×1 / 0x4c×1
 * VFP 指令 242 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e3c04 push {r4, r5, r6, r7, r8, lr}
 *   @0x2e3c08 vpush {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x2e3c0c mov r4, r0
 *   @0x2e3c10 ldr r8, [r0, #0xa0]
 *   @0x2e3c14 sub sp, sp, #32
 *   @0x2e3c18 ldr r7, [r0, #0xa4]
 *   @0x2e3c1c ldr r6, [r0, #0xa8]
 *   @0x2e3c20 ldr r5, [r0, #0xac]
 *   @0x2e3c24 add r8, r8, r8, lsl #1
 *   @0x2e3c28 ldr r3, [r1, #0x18]
 *   @0x2e3c2c add r7, r7, r7, lsl #1
 *   @0x2e3c30 add r6, r6, r6, lsl #1
 *   @0x2e3c34 add r5, r5, r5, lsl #1
 *   @0x2e3c38 add r8, r3, r8, lsl #2
 *   @0x2e3c3c vldr s22, [r8, #8]
 *   @0x2e3c40 vmov r0, s22
 *   @0x2e3c44 add r7, r3, r7, lsl #2
 *   @0x2e3c48 add r6, r3, r6, lsl #2
 *   @0x2e3c4c add r5, r3, r5, lsl #2
 *   @0x2e3c50 bl 0xb6580 <sinf@plt>
 *   @0x2e3c54 vldr s21, [r7, #8]
 *   @0x2e3c58 vmov s28, r0
 *   @0x2e3c5c vmov r0, s22
 *   @0x2e3c60 bl 0xb658c <cosf@plt>
 *   @0x2e3c64 vmov s27, r0
 *   @0x2e3c68 vmov r0, s21
 *   @0x2e3c6c bl 0xb6580 <sinf@plt>
 *   @0x2e3c70 vldr s20, [r6, #8]
 *   @0x2e3c74 vldr s19, [r5, #8]
 *   @0x2e3c78 vmov s24, r0
 *   @0x2e3c7c vmov r0, s21
 *   @0x2e3c80 bl 0xb658c <cosf@plt>
 *   @0x2e3c84 vmov s23, r0
 *   @0x2e3c88 vmov r0, s20
 *   @0x2e3c8c bl 0xb6580 <sinf@plt>
 *   @0x2e3c90 vmov s18, r0
 *   @0x2e3c94 vmov r0, s20
 *   @0x2e3c98 bl 0xb658c <cosf@plt>
 *   @0x2e3c9c vmov s17, r0
 *   @0x2e3ca0 vmov r0, s19
 *   @0x2e3ca4 bl 0xb6580 <sinf@plt>
 *   @0x2e3ca8 vmov s16, r0
 *   @0x2e3cac vmov r0, s19
 *   @0x2e3cb0 bl 0xb658c <cosf@plt>
 *   @0x2e3cb4 ldr r3, [r4, #0x4c]
 *   @0x2e3cb8 vldr s0, [r7, #4]
 *   @0x2e3cbc vldr s1, [r6]
 *   @0x2e3cc0 cmp r3, #1
 *   @0x2e3cc4 vldr s3, [r6, #4]
 *   @0x2e3cc8 vldr s4, [r5]
 *   @0x2e3ccc vldr s29, [r8]
 *   @0x2e3cd0 vldr s26, [r8, #4]
 *   @0x2e3cd4 vldr s25, [r7]
 *   @0x2e3cd8 vstr s0, [sp, #8]
 *   @0x2e3cdc vstr s1, [sp, #4]
 *   @0x2e3ce0 vstr s3, [sp]
 *   @0x2e3ce4 vstr s4, [sp, #12]
 *   @0x2e3ce8 vldr s31, [r5, #4]
 *   @0x2e3cec vmov s12, r0
 *   @0x2e3cf0 beq 0x2e3fc4 <_ZN11b2GearJoint24SolvePositionConstraintsERK12b2SolverData+0x3c0>
 *   @0x2e3cf4 vldr s15, [r4, #196]
 *   @0x2e3cf8 vldr s5, [r4, #112]
 *   @0x2e3cfc vsub.f32 s5, s5, s15
 *   @0x2e3d00 vldr s6, [r4, #128]
 *   @0x2e3d04 vldr s10, [r4, #192]
 *   @0x2e3d08 vldr s7, [r4, #108]
 *   @0x2e3d0c vldr s15, [r4, #180]
 *   @0x2e3d10 vldr s13, [r4, #96]
 *   @0x2e3d14 vldr s8, [r4, #124]
 *   @0x2e3d18 vldr s9, [r4, #176]
 *   @0x2e3d1c vldr s3, [r4, #92]
 *   @0x2e3d20 vldr s2, [r4, #232]
 *   @0x2e3d24 vstr s2, [sp, #16]
 *   @0x2e3d28 vldr s0, [r4, #216]
 *   @0x2e3d2c vldr s30, [r4, #208]
 *   @0x2e3d30 ldr r3, [r4, #0x50]
 *   @0x2e3d34 vstr s30, [sp, #24]
 *   @0x2e3d38 vstr s0, [sp, #20]
 *   @0x2e3d3c cmp r3, #1
 *   @0x2e3d40 vmul.f32 s11, s5, s17
 *   @0x2e3d44 vmul.f32 s14, s6, s18
 *   @0x2e3d48 vsub.f32 s7, s7, s10
 *   @0x2e3d4c vsub.f32 s13, s13, s15
 *   @0x2e3d50 vmul.f32 s4, s5, s18
 *   @0x2e3d54 vnmls.f32 s14, s8, s17
 *   @0x2e3d58 vmla.f32 s11, s7, s18
 *   @0x2e3d5c vmul.f32 s15, s6, s17
 *   @0x2e3d60 vmul.f32 s10, s13, s27
 *   @0x2e3d64 vsub.f32 s3, s3, s9
 *   @0x2e3d68 vldr s9, [pc, #752]
 *   @0x2e3d6c vmla.f32 s15, s8, s18
 *   @0x2e3d70 vnmls.f32 s4, s7, s17
 *   @0x2e3d74 vmul.f32 s13, s13, s28
 *   @0x2e3d78 vmla.f32 s10, s3, s28
 *   @0x2e3d7c vmul.f32 s11, s14, s11
 *   @0x2e3d80 vnmls.f32 s13, s3, s27
 *   @0x2e3d84 vldr s3, [sp]
 *   @0x2e3d88 vldr s27, [r4, #224]
 *   @0x2e3d8c vsub.f32 s1, s26, s3
 *   @0x2e3d90 vnmls.f32 s11, s15, s4
 *   @0x2e3d94 vldr s4, [sp, #4]
 *   @0x2e3d98 vadd.f32 s1, s10, s1
 *   @0x2e3d9c vmul.f32 s10, s14, s10
 *   @0x2e3da0 vsub.f32 s3, s29, s4
 *   @0x2e3da4 vmul.f32 s4, s1, s17
 *   @0x2e3da8 vnmls.f32 s10, s15, s13
 *   @0x2e3dac vmul.f32 s2, s2, s11
 *   @0x2e3db0 vadd.f32 s3, s13, s3
 *   @0x2e3db4 vadd.f32 s28, s0, s30
 *   @0x2e3db8 vmls.f32 s4, s18, s3
 *   @0x2e3dbc vmul.f32 s18, s1, s18
 *   @0x2e3dc0 vmla.f32 s28, s2, s11
 *   @0x2e3dc4 vmul.f32 s13, s27, s10
 *   @0x2e3dc8 vmla.f32 s18, s3, s17
 *   @0x2e3dcc vsub.f32 s5, s4, s5
 *   @0x2e3dd0 vmla.f32 s28, s13, s10
 *   @0x2e3dd4 vmul.f32 s5, s6, s5
 *   @0x2e3dd8 vsub.f32 s18, s18, s7
 *   @0x2e3ddc vadd.f32 s28, s28, s9
 *   @0x2e3de0 vmla.f32 s5, s8, s18
 *   @0x2e3de4 beq 0x2e4018 <_ZN11b2GearJoint24SolvePositionConstraintsERK12b2SolverData+0x414>
 *   @0x2e3de8 vldr s13, [r4, #204]
 *   @0x2e3dec vldr s2, [r4, #120]
 *   @0x2e3df0 vldr s3, [r4, #136]
 *   @0x2e3df4 vldr s4, [r4, #116]
 *   @0x2e3df8 vldr s17, [r4, #188]
 *   @0x2e3dfc vldr s9, [r4, #104]
 *   @0x2e3e00 vldr s1, [r4, #184]
 *   @0x2e3e04 vldr s0, [r4, #100]
 *   @0x2e3e08 vldr s30, [r4, #236]
 *   @0x2e3e0c vsub.f32 s2, s2, s13
 *   @0x2e3e10 vldr s13, [r4, #200]
 *   @0x2e3e14 vmul.f32 s6, s2, s12
 *   @0x2e3e18 vmul.f32 s7, s3, s16
 *   @0x2e3e1c vsub.f32 s4, s4, s13
 *   @0x2e3e20 vldr s13, [r4, #132]
 *   @0x2e3e24 vmul.f32 s18, s2, s16
 *   @0x2e3e28 vnmls.f32 s7, s13, s12
 *   @0x2e3e2c vldr s13, [r4, #152]
 *   @0x2e3e30 vmla.f32 s6, s4, s16
 *   @0x2e3e34 vmul.f32 s8, s3, s12
 *   @0x2e3e38 vsub.f32 s9, s9, s17
 *   @0x2e3e3c vldr s17, [r4, #132]
 *   @0x2e3e40 vnmls.f32 s18, s4, s12
 *   @0x2e3e44 vmla.f32 s8, s17, s16
 *   @0x2e3e48 vsub.f32 s0, s0, s1
 *   @0x2e3e4c vmul.f32 s6, s7, s6
 *   @0x2e3e50 vmul.f32 s1, s9, s23
 *   @0x2e3e54 vnmls.f32 s6, s8, s18
 *   @0x2e3e58 vldr s18, [r4, #220]
 *   @0x2e3e5c vmla.f32 s1, s0, s24
 *   @0x2e3e60 vmul.f32 s9, s9, s24
 *   @0x2e3e64 vnmls.f32 s9, s0, s23
 *   @0x2e3e68 vldr s0, [sp, #8]
 *   @0x2e3e6c vsub.f32 s24, s0, s31
 *   @0x2e3e70 vmul.f32 s6, s13, s6
 *   @0x2e3e74 vmul.f32 s0, s7, s1
 *   @0x2e3e78 vadd.f32 s24, s1, s24
 *   @0x2e3e7c vldr s1, [sp, #12]
 *   @0x2e3e80 vsub.f32 s17, s25, s1
 *   @0x2e3e84 vnmls.f32 s0, s8, s9
 *   @0x2e3e88 vadd.f32 s17, s9, s17
 *   @0x2e3e8c vmul.f32 s1, s24, s12
 *   @0x2e3e90 vmul.f32 s9, s30, s6
 *   @0x2e3e94 vmov.f32 s23, s30
 *   @0x2e3e98 vmul.f32 s30, s13, s13
 *   @0x2e3e9c vmls.f32 s1, s16, s17
 *   @0x2e3ea0 vstr s30, [sp, #28]
 *   @0x2e3ea4 vmul.f32 s16, s24, s16
 *   @0x2e3ea8 vldr s24, [r4, #212]
 *   @0x2e3eac vmul.f32 s9, s9, s6
 *   @0x2e3eb0 vadd.f32 s30, s18, s24
 *   @0x2e3eb4 vmul.f32 s0, s13, s0
 *   @0x2e3eb8 vmla.f32 s16, s17, s12
 *   @0x2e3ebc vldr s12, [sp, #28]
 *   @0x2e3ec0 vmla.f32 s9, s12, s30
 *   @0x2e3ec4 vldr s12, [r4, #228]
 *   @0x2e3ec8 vsub.f32 s2, s1, s2
 *   @0x2e3ecc vmul.f32 s30, s12, s0
 *   @0x2e3ed0 vmul.f32 s2, s3, s2
 *   @0x2e3ed4 vmla.f32 s9, s30, s0
 *   @0x2e3ed8 vldr s30, [r4, #132]
 *   @0x2e3edc vsub.f32 s16, s16, s4
 *   @0x2e3ee0 vmla.f32 s2, s30, s16
 *   @0x2e3ee4 vmov.f32 s17, s13
 *   @0x2e3ee8 vmul.f32 s7, s13, s7
 *   @0x2e3eec vmul.f32 s13, s13, s8
 *   @0x2e3ef0 vadd.f32 s28, s9, s28
 *   @0x2e3ef4 vldr s9, [r4, #148]
 *   @0x2e3ef8 vldr s1, [sp, #24]
 *   @0x2e3efc vldr s3, [sp, #20]
 *   @0x2e3f00 vldr s4, [sp, #16]
 *   @0x2e3f04 mov r0, #1
 *   @0x2e3f08 vmla.f32 s5, s2, s17
 *   @0x2e3f0c vldr s17, [sp]
 *   @0x2e3f10 vsub.f32 s5, s5, s9
 *   @0x2e3f14 vcmpe.f32 s28, #0
 *   @0x2e3f18 vmrs APSR_nzcv, fpscr
 *   @0x2e3f1c vneggt.f32 s5, s5
 *   @0x2e3f20 vldrle s28, [pc, #312]
 *   @0x2e3f24 vdivgt.f32 s28, s5, s28
 *   @0x2e3f28 vmul.f32 s5, s28, s1
 *   @0x2e3f2c vmul.f32 s8, s28, s3
 *   @0x2e3f30 vmul.f32 s24, s28, s24
 *   @0x2e3f34 vmul.f32 s18, s28, s18
 *   @0x2e3f38 vmul.f32 s27, s28, s27
 *   @0x2e3f3c vmul.f32 s12, s28, s12
 *   @0x2e3f40 vmul.f32 s9, s28, s4
 *   @0x2e3f44 vmul.f32 s28, s28, s23
 *   @0x2e3f48 vmla.f32 s26, s5, s15
 *   @0x2e3f4c vmls.f32 s17, s8, s15
 *   @0x2e3f50 vstr s26, [r8, #4]
 *   @0x2e3f54 vmov.f32 s15, s31
 *   @0x2e3f58 vmla.f32 s29, s5, s14
 *   @0x2e3f5c vmla.f32 s22, s27, s10
 *   @0x2e3f60 vldr s10, [sp, #8]
 *   @0x2e3f64 vstr s29, [r8]
 *   @0x2e3f68 vmla.f32 s21, s12, s0
 *   @0x2e3f6c vldr s12, [sp, #4]
 *   @0x2e3f70 vstr s22, [r8, #8]
 *   @0x2e3f74 vmls.f32 s12, s8, s14
 *   @0x2e3f78 vldr s14, [sp, #12]
 *   @0x2e3f7c vstr s21, [r7, #8]
 *   @0x2e3f80 vmla.f32 s25, s24, s7
 *   @0x2e3f84 vmla.f32 s10, s24, s13
 *   @0x2e3f88 vstr s25, [r7]
 *   @0x2e3f8c vmls.f32 s20, s9, s11
 *   @0x2e3f90 vstr s10, [r7, #4]
 *   @0x2e3f94 vstr s12, [r6]
 *   @0x2e3f98 vstr s17, [r6, #4]
 *   @0x2e3f9c vmls.f32 s14, s18, s7
 *   @0x2e3fa0 vstr s20, [r6, #8]
 *   @0x2e3fa4 vmls.f32 s15, s18, s13
 *   @0x2e3fa8 vstr s14, [r5]
 *   @0x2e3fac vmls.f32 s19, s28, s6
 *   @0x2e3fb0 vstr s15, [r5, #4]
 *   @0x2e3fb4 vstr s19, [r5, #8]
 *   @0x2e3fb8 add sp, sp, #32
 *   @0x2e3fbc vpop {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x2e3fc0 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2e3fc4 vldr s11, [r4, #232]
 *   @0x2e3fc8 vldr s28, [r4, #224]
 *   @0x2e3fcc vsub.f32 s5, s22, s20
 *   @0x2e3fd0 vstr s11, [sp, #16]
 *   @0x2e3fd4 ldr r3, [r4, #0x50]
 *   @0x2e3fd8 vldr s13, [pc, #128]
 *   @0x2e3fdc vldr s14, [r4, #208]
 *   @0x2e3fe0 vldr s8, [r4, #140]
 *   @0x2e3fe4 cmp r3, #1
 *   @0x2e3fe8 vldr s9, [r4, #216]
 *   @0x2e3fec vstr s14, [sp, #24]
 *   @0x2e3ff0 vstr s9, [sp, #20]
 *   @0x2e3ff4 vmov.f32 s27, s28
 *   @0x2e3ff8 vadd.f32 s28, s28, s11
 *   @0x2e3ffc vmov.f32 s11, #1.000000e+00
 *   @0x2e4000 vmov.f32 s15, s13
 *   @0x2e4004 vmov.f32 s14, s13
 *   @0x2e4008 vadd.f32 s28, s28, s13
 *   @0x2e400c vmov.f32 s10, s11
 *   @0x2e4010 vsub.f32 s5, s5, s8
 *   @0x2e4014 bne 0x2e3de8 <_ZN11b2GearJoint24SolvePositionConstraintsERK12b2SolverData+0x1e4>
 *   @0x2e4018 vldr s0, [r4, #152]
 *   @0x2e401c vldr s7, [r4, #228]
 *   @0x2e4020 vldr s9, [r4, #236]
 *   @0x2e4024 vldr s3, [r4, #144]
 *   @0x2e4028 vldr s13, [pc, #48]
 *   @0x2e402c vldr s18, [r4, #220]
 *   @0x2e4030 vldr s24, [r4, #212]
 *   @0x2e4034 vmul.f32 s8, s0, s0
 *   @0x2e4038 vmov.f32 s23, s9
 *   @0x2e403c vsub.f32 s2, s21, s19
 *   @0x2e4040 vadd.f32 s9, s7, s9
 *   @0x2e4044 vmov.f32 s12, s7
 *   @0x2e4048 vmov.f32 s17, s0
 *   @0x2e404c vmov.f32 s6, s0
 *   @0x2e4050 vmov.f32 s7, s13
 *   @0x2e4054 vmla.f32 s28, s8, s9
 *   @0x2e4058 vsub.f32 s2, s2, s3
 *   @0x2e405c b 0x2e3ef4 <_ZN11b2GearJoint24SolvePositionConstraintsERK12b2SolverData+0x2f0>
 *   @0x2e4060 andeq r0, r0, r0
 *
 * ══ §5/28 JS_Array_prototype_shift(RValue&, CInstance*, CInstance*, int, RValue*)  0x24fc08  size 1116  279 条（0x24fc08..0x250064）
 * @func 0x24fc08 0x250064  size 1116  279 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / F_JS_Object_Get(YYObjectBase*, RValue*, char const*)×3 / JS_Object_Put(YYObjectBase*, RValue*, char const*, bool)×3 / 0xb65c8×3 / JS_DeleteProperty(YYObjectBase*, RValue*, char const*, bool)×2
 * 字段偏移 top8: 0x4×9 / 0x2c×7 / 0x8×6 / 0xc×5 / 0x10×3 / 0x18×3 / 0x28×3 / 0x7c×2
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24fc08 ldr r2, [pc, #0x43c]
 *   @0x24fc0c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x24fc10 sub sp, sp, #132
 *   @0x24fc14 ldr r2, [pc, r2]
 *   @0x24fc18 add r3, sp, #12
 *   @0x24fc1c ldr r8, [pc, #0x42c]
 *   @0x24fc20 mov r5, r1
 *   @0x24fc24 str r3, [sp, #0x4]
 *   @0x24fc28 mov r1, r3
 *   @0x24fc2c add r8, pc, r8
 *   @0x24fc30 ldr r3, [r2]
 *   @0x24fc34 mov r4, #0
 *   @0x24fc38 str r2, [sp]
 *   @0x24fc3c mov r6, r0
 *   @0x24fc40 mov r2, r8
 *   @0x24fc44 mov r0, r5
 *   @0x24fc48 str r3, [sp, #0x7c]
 *   @0x24fc4c mvn r7, #-16777216
 *   @0x24fc50 str r4, [sp, #0xc]
 *   @0x24fc54 str r4, [sp, #0x10]
 *   @0x24fc58 str r4, [sp, #0x14]
 *   @0x24fc5c str r7, [sp, #0x18]
 *   @0x24fc60 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x24fc64 add r0, sp, #12
 *   @0x24fc68 mov r1, r4
 *   @0x24fc6c bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x24fc70 mov r3, #5
 *   @0x24fc74 str r3, [r6, #0xc]
 *   @0x24fc78 subs r11, r0, #0
 *   @0x24fc7c mov r0, r5
 *   @0x24fc80 beq 0x24fd44 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x24fc84 ldr r2, [pc, #0x3c8]
 *   @0x24fc88 add r1, sp, #44
 *   @0x24fc8c str r4, [sp, #0x1c]
 *   @0x24fc90 add r2, pc, r2
 *   @0x24fc94 str r4, [sp, #0x20]
 *   @0x24fc98 str r4, [sp, #0x24]
 *   @0x24fc9c str r7, [sp, #0x28]
 *   @0x24fca0 str r4, [sp, #0x2c]
 *   @0x24fca4 str r4, [sp, #0x30]
 *   @0x24fca8 str r4, [sp, #0x34]
 *   @0x24fcac str r7, [sp, #0x38]
 *   @0x24fcb0 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x24fcb4 ldr r2, [r6, #0xc]
 *   @0x24fcb8 and r3, r2, r7
 *   @0x24fcbc cmp r3, #1
 *   @0x24fcc0 beq 0x24fecc <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x2c4>
 *   @0x24fcc4 cmp r3, #2
 *   @0x24fcc8 bne 0x24fce0 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x24fccc sub r3, r2, #1
 *   @0x24fcd0 bic r3, r3, #-16777216
 *   @0x24fcd4 bic r3, r3, #3
 *   @0x24fcd8 cmp r3, #0
 *   @0x24fcdc beq 0x24ffac <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x3a4>
 *   @0x24fce0 ldr r2, [sp, #0x38]
 *   @0x24fce4 mov r0, #0
 *   @0x24fce8 ldr r1, [sp, #0x34]
 *   @0x24fcec bic r3, r2, #-16777216
 *   @0x24fcf0 str r0, [r6]
 *   @0x24fcf4 str r2, [r6, #0xc]
 *   @0x24fcf8 str r1, [r6, #0x8]
 *   @0x24fcfc cmp r3, #14
 *   @0x24fd00 addls pc, pc, r3, lsl #2
 *   @0x24fd04 b 0x24fd84 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x17c>
 *   @0x24fd08 b 0x24ff00 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x2f8>
 *   @0x24fd0c b 0x24ff5c <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x354>
 *   @0x24fd10 b 0x24ff30 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x328>
 *   @0x24fd14 b 0x24fd7c <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x174>
 *   @0x24fd18 b 0x24fd84 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x17c>
 *   @0x24fd1c b 0x24fd84 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x17c>
 *   @0x24fd20 b 0x24ff10 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x308>
 *   @0x24fd24 b 0x24fd7c <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x174>
 *   @0x24fd28 b 0x24fd84 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x17c>
 *   @0x24fd2c b 0x24fd84 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x17c>
 *   @0x24fd30 b 0x24ff00 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x2f8>
 *   @0x24fd34 b 0x24fd84 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x17c>
 *   @0x24fd38 b 0x24fd84 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x17c>
 *   @0x24fd3c b 0x24ff00 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x2f8>
 *   @0x24fd40 b 0x24fd7c <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x174>
 *   @0x24fd44 add r1, sp, #12
 *   @0x24fd48 mov r2, r8
 *   @0x24fd4c mov r3, r11
 *   @0x24fd50 str r11, [sp, #0x18]
 *   @0x24fd54 str r11, [sp, #0xc]
 *   @0x24fd58 str r11, [sp, #0x10]
 *   @0x24fd5c bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb>
 *   @0x24fd60 ldr r1, [sp]
 *   @0x24fd64 ldr r2, [sp, #0x7c]
 *   @0x24fd68 ldr r3, [r1]
 *   @0x24fd6c cmp r2, r3
 *   @0x24fd70 bne 0x250048 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x440>
 *   @0x24fd74 add sp, sp, #132
 *   @0x24fd78 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x24fd7c ldr r3, [sp, #0x2c]
 *   @0x24fd80 str r3, [r6]
 *   @0x24fd84 cmp r11, #1
 *   @0x24fd88 bls 0x24fe5c <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x254>
 *   @0x24fd8c ldr r9, [pc, #0x2c4]
 *   @0x24fd90 add r6, sp, #60
 *   @0x24fd94 add r10, sp, #28
 *   @0x24fd98 add r8, sp, #92
 *   @0x24fd9c add r9, pc, r9
 *   @0x24fda0 mov r4, #1
 *   @0x24fda4 mov r7, #0
 *   @0x24fda8 b 0x24fdfc <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x1f4>
 *   @0x24fdac mov r2, r6
 *   @0x24fdb0 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x24fdb4 mov r0, r5
 *   @0x24fdb8 mov r1, r10
 *   @0x24fdbc mov r2, r8
 *   @0x24fdc0 mov r3, #0
 *   @0x24fdc4 bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb>
 *   @0x24fdc8 ldr r3, [sp, #0x28]
 *   @0x24fdcc sub r3, r3, #1
 *   @0x24fdd0 bic r3, r3, #-16777216
 *   @0x24fdd4 bic r3, r3, #3
 *   @0x24fdd8 cmp r3, #0
 *   @0x24fddc beq 0x24fe50 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x248>
 *   @0x24fde0 add r4, r4, #1
 *   @0x24fde4 mov r1, #5
 *   @0x24fde8 cmp r4, r11
 *   @0x24fdec str r7, [sp, #0x24]
 *   @0x24fdf0 str r1, [sp, #0x28]
 *   @0x24fdf4 str r7, [sp, #0x1c]
 *   @0x24fdf8 beq 0x24fe64 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x25c>
 *   @0x24fdfc mov r1, #32
 *   @0x24fe00 mov r2, r9
 *   @0x24fe04 mov r3, r4
 *   @0x24fe08 mov r0, r6
 *   @0x24fe0c bl 0xb65c8 <snprintf@plt>
 *   @0x24fe10 mov r1, #32
 *   @0x24fe14 mov r2, r9
 *   @0x24fe18 sub r3, r4, #1
 *   @0x24fe1c mov r0, r8
 *   @0x24fe20 bl 0xb65c8 <snprintf@plt>
 *   @0x24fe24 mov r1, r6
 *   @0x24fe28 mov r0, r5
 *   @0x24fe2c bl 0x241924 <_Z14JS_HasPropertyP12YYObjectBasePKc>
 *   @0x24fe30 mov r1, r10
 *   @0x24fe34 cmp r0, #0
 *   @0x24fe38 mov r0, r5
 *   @0x24fe3c bne 0x24fdac <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x24fe40 mov r2, r8
 *   @0x24fe44 mov r3, #1
 *   @0x24fe48 bl 0x24edf4 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb>
 *   @0x24fe4c b 0x24fdc8 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x1c0>
 *   @0x24fe50 mov r0, r10
 *   @0x24fe54 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x24fe58 b 0x24fde0 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x1d8>
 *   @0x24fe5c add r6, sp, #60
 *   @0x24fe60 add r10, sp, #28
 *   @0x24fe64 sub r11, r11, #1
 *   @0x24fe68 ldr r2, [pc, #0x1ec]
 *   @0x24fe6c mov r0, r6
 *   @0x24fe70 mov r1, #32
 *   @0x24fe74 mov r3, r11
 *   @0x24fe78 add r2, pc, r2
 *   @0x24fe7c bl 0xb65c8 <snprintf@plt>
 *   @0x24fe80 mov r0, r5
 *   @0x24fe84 mov r1, r10
 *   @0x24fe88 mov r2, r6
 *   @0x24fe8c mov r3, #1
 *   @0x24fe90 bl 0x24edf4 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb>
 *   @0x24fe94 vmov s15, r11
 *   @0x24fe98 ldr r2, [pc, #0x1c0]
 *   @0x24fe9c mov r12, #0
 *   @0x24fea0 vcvt.f64.u32 d7, s15
 *   @0x24fea4 mov r0, r5
 *   @0x24fea8 add r1, sp, #12
 *   @0x24feac mov r3, r12
 *   @0x24feb0 add r2, pc, r2
 *   @0x24feb4 str r12, [sp, #0x18]
 *   @0x24feb8 vmov r6, r7, d7
 *   @0x24febc vstr s14, [sp, #12]
 *   @0x24fec0 str r7, [sp, #0x10]
 *   @0x24fec4 bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb>
 *   @0x24fec8 b 0x24fd60 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x158>
 *   @0x24fecc ldr r4, [r6]
 *   @0x24fed0 cmp r4, #0
 *   @0x24fed4 beq 0x24fef4 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x2ec>
 *   @0x24fed8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24fedc ldr r7, [r4, #0x4]
 *   @0x24fee0 sub r7, r7, #1
 *   @0x24fee4 str r7, [r4, #0x4]
 *   @0x24fee8 cmp r7, #0
 *   @0x24feec beq 0x24ff74 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x36c>
 *   @0x24fef0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x24fef4 mov r3, #0
 *   @0x24fef8 str r3, [r6]
 *   @0x24fefc b 0x24fce0 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x24ff00 ldr r2, [sp, #0x2c]
 *   @0x24ff04 ldr r3, [sp, #0x30]
 *   @0x24ff08 stm r6, {r2, r3}
 *   @0x24ff0c b 0x24fd84 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x17c>
 *   @0x24ff10 ldr r3, [sp, #0x2c]
 *   @0x24ff14 cmp r3, #0
 *   @0x24ff18 str r3, [r6]
 *   @0x24ff1c beq 0x24fd84 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x17c>
 *   @0x24ff20 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x24ff24 ldr r1, [sp, #0x2c]
 *   @0x24ff28 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x24ff2c b 0x24fd84 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x17c>
 *   @0x24ff30 ldr r3, [sp, #0x2c]
 *   @0x24ff34 cmp r3, #0
 *   @0x24ff38 str r3, [r6]
 *   @0x24ff3c beq 0x24fd84 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x17c>
 *   @0x24ff40 ldr r1, [r3, #0x8]
 *   @0x24ff44 ldr r2, [r3]
 *   @0x24ff48 cmp r1, #0
 *   @0x24ff4c streq r6, [r3, #0x8]
 *   @0x24ff50 add r2, r2, #1
 *   @0x24ff54 str r2, [r3]
 *   @0x24ff58 b 0x24fd84 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x17c>
 *   @0x24ff5c ldr r3, [sp, #0x2c]
 *   @0x24ff60 cmp r3, #0
 *   @0x24ff64 ldrne r2, [r3, #0x4]
 *   @0x24ff68 addne r2, r2, #1
 *   @0x24ff6c strne r2, [r3, #0x4]
 *   @0x24ff70 b 0x24fd80 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x178>
 *   @0x24ff74 ldr r0, [r4]
 *   @0x24ff78 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24ff7c str r7, [r4]
 *   @0x24ff80 str r7, [r4, #0x8]
 *   @0x24ff84 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24ff88 ldr r7, [r4, #0x4]
 *   @0x24ff8c sub r7, r7, #1
 *   @0x24ff90 str r7, [r4, #0x4]
 *   @0x24ff94 cmp r7, #0
 *   @0x24ff98 beq 0x24ffb8 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x3b0>
 *   @0x24ff9c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x24ffa0 mov r0, r4
 *   @0x24ffa4 bl 0x27d1d0 <_ZdlPv>
 *   @0x24ffa8 b 0x24fef0 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x2e8>
 *   @0x24ffac mov r0, r6
 *   @0x24ffb0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x24ffb4 b 0x24fce0 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0xd8>
 *   @0x24ffb8 ldr r0, [r4]
 *   @0x24ffbc bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24ffc0 str r7, [r4]
 *   @0x24ffc4 str r7, [r4, #0x8]
 *   @0x24ffc8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24ffcc ldr r7, [r4, #0x4]
 *   @0x24ffd0 sub r7, r7, #1
 *   @0x24ffd4 str r7, [r4, #0x4]
 *   @0x24ffd8 cmp r7, #0
 *   @0x24ffdc beq 0x24fff0 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x3e8>
 *   @0x24ffe0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x24ffe4 mov r0, r4
 *   @0x24ffe8 bl 0x27d1d0 <_ZdlPv>
 *   @0x24ffec b 0x24ff9c <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x394>
 *   @0x24fff0 ldr r0, [r4]
 *   @0x24fff4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24fff8 str r7, [r4]
 *   @0x24fffc str r7, [r4, #0x8]
 *   @0x250000 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x250004 ldr r7, [r4, #0x4]
 *   @0x250008 sub r7, r7, #1
 *   @0x25000c str r7, [r4, #0x4]
 *   @0x250010 cmp r7, #0
 *   @0x250014 bne 0x250038 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x430>
 *   @0x250018 ldr r0, [r4]
 *   @0x25001c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x250020 mov r0, r4
 *   @0x250024 str r7, [r4]
 *   @0x250028 str r7, [r4, #0x8]
 *   @0x25002c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x250030 mov r0, r4
 *   @0x250034 bl 0x27d1d0 <_ZdlPv>
 *   @0x250038 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x25003c mov r0, r4
 *   @0x250040 bl 0x27d1d0 <_ZdlPv>
 *   @0x250044 b 0x24ffe0 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x3d8>
 *   @0x250048 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x25004c andseq sp, r9, r12, lsr sp
 *   @0x250050 andeq r0, lr, r0, asr #24
 *   @0x250054 andeq r2, lr, r12, asr r8
 *   @0x250058 andseq r6, r0, r4, asr #1
 *   @0x25005c andseq r5, r0, r8, ror #31
 *   @0x250060 strheq r0, [lr], -r12
 *
 * ══ §6/28 Debug_GetPing(Buffer_Standard*, Buffer_Standard*)  0x29d078  size 1116  279 条（0x29d078..0x29d4d4）
 * @func 0x29d078 0x29d4d4  size 1116  279 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetUint32(RValue const*, int) / YYGetInt32(RValue const*, int) / Debug_QueryHeapMem(unsigned int&, unsigned long long&) / DbgServer::GetBufferSize() / Debug_WriteOutput(Buffer_Standard*) / CProfiler::Enable(bool) / Debug_WriteProfileData(Buffer_Standard*) / Debug_GetPing(Buffer_Standard*, Buffer_Standard*)+0x2d4
 * 字段偏移 top8: 0x8×15 / 0x38×11 / 0x30×11 / 0xc×5 / 0x4×4 / 0x22c×4 / 0x10×2 / 0x330×2
 * VFP 指令 44 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29d078 ldr r3, [r0]
 *   @0x29d07c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x29d080 add r5, r0, #44
 *   @0x29d084 sub sp, sp, #28
 *   @0x29d088 mov r6, r1
 *   @0x29d08c mov r10, #0
 *   @0x29d090 mov r2, r5
 *   @0x29d094 ldr r3, [r3, #0xc]
 *   @0x29d098 mov r1, #5
 *   @0x29d09c mov r9, r0
 *   @0x29d0a0 blx r3
 *   @0x29d0a4 mov r0, r5
 *   @0x29d0a8 mov r1, r10
 *   @0x29d0ac bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29d0b0 ldr r3, [r9]
 *   @0x29d0b4 mov r2, r5
 *   @0x29d0b8 mov r1, #6
 *   @0x29d0bc ldr r8, [pc, #0x3dc]
 *   @0x29d0c0 add r7, r6, #44
 *   @0x29d0c4 ldr r3, [r3, #0xc]
 *   @0x29d0c8 add r8, pc, r8
 *   @0x29d0cc mov r11, r0
 *   @0x29d0d0 mov r0, r9
 *   @0x29d0d4 blx r3
 *   @0x29d0d8 mov r0, r5
 *   @0x29d0dc mov r1, r10
 *   @0x29d0e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x29d0e4 ldr r12, [pc, #0x3b8]
 *   @0x29d0e8 ldr r3, [r6]
 *   @0x29d0ec mov r2, r7
 *   @0x29d0f0 mov r1, #5
 *   @0x29d0f4 str r0, [sp]
 *   @0x29d0f8 mov r0, r6
 *   @0x29d0fc ldr r12, [r8, r12]
 *   @0x29d100 str r10, [r6, #0x38]
 *   @0x29d104 ldrb r4, [r12]
 *   @0x29d108 vmov s13, r4
 *   @0x29d10c vcvt.f64.u32 d6, s13
 *   @0x29d110 vmov r4, r5, d6
 *   @0x29d114 vstr s12, [r6, #44]
 *   @0x29d118 str r5, [r6, #0x30]
 *   @0x29d11c ldr r3, [r3, #0x8]
 *   @0x29d120 blx r3
 *   @0x29d124 vmov s15, r11
 *   @0x29d128 ldr r3, [r6]
 *   @0x29d12c mov r2, r7
 *   @0x29d130 vcvt.f64.u32 d7, s15
 *   @0x29d134 mov r1, #5
 *   @0x29d138 str r10, [r6, #0x38]
 *   @0x29d13c mov r0, r6
 *   @0x29d140 vmov r4, r5, d7
 *   @0x29d144 vstr s14, [r6, #44]
 *   @0x29d148 str r5, [r6, #0x30]
 *   @0x29d14c ldr r3, [r3, #0x8]
 *   @0x29d150 blx r3
 *   @0x29d154 add r1, sp, #16
 *   @0x29d158 add r0, sp, #12
 *   @0x29d15c bl 0x29c3a8 <_Z18Debug_QueryHeapMemRjRy>
 *   @0x29d160 ldr r3, [pc, #0x340]
 *   @0x29d164 ldr r4, [r6, #0x10]
 *   @0x29d168 ldr r3, [r8, r3]
 *   @0x29d16c ldr r0, [r3]
 *   @0x29d170 bl 0x29d06c <_ZN9DbgServer13GetBufferSizeEv>
 *   @0x29d174 ldr r1, [pc, #0x330]
 *   @0x29d178 ldr r3, [pc, #0x330]
 *   @0x29d17c ldr r2, [sp, #0xc]
 *   @0x29d180 ldr r1, [r8, r1]
 *   @0x29d184 ldr r1, [r1]
 *   @0x29d188 add r0, r4, r0
 *   @0x29d18c add r1, r0, r1
 *   @0x29d190 rsb r2, r1, r2
 *   @0x29d194 str r2, [sp, #0xc]
 *   @0x29d198 ldr r3, [r8, r3]
 *   @0x29d19c str r3, [sp, #0x4]
 *   @0x29d1a0 ldrb r3, [r3]
 *   @0x29d1a4 cmp r3, r10
 *   @0x29d1a8 bne 0x29d2b8 <_Z13Debug_GetPingP15Buffer_StandardS0_+0x240>
 *   @0x29d1ac ldr r2, [pc, #0x300]
 *   @0x29d1b0 mov r1, #0
 *   @0x29d1b4 ldr r12, [r6]
 *   @0x29d1b8 mov r0, r6
 *   @0x29d1bc add r2, pc, r2
 *   @0x29d1c0 vldr s15, [r2, #556]
 *   @0x29d1c4 vcvt.f32.s32 s15, s15
 *   @0x29d1c8 vldr s14, [r2, #552]
 *   @0x29d1cc str r3, [r2, #0x22c]
 *   @0x29d1d0 str r1, [r2, #0x228]
 *   @0x29d1d4 mov r1, #6
 *   @0x29d1d8 str r3, [r6, #0x38]
 *   @0x29d1dc mov r2, r7
 *   @0x29d1e0 vdiv.f32 s15, s14, s15
 *   @0x29d1e4 vcvt.s32.f32 s15, s15
 *   @0x29d1e8 vcvt.f64.s32 d6, s15
 *   @0x29d1ec vmov r4, r5, d6
 *   @0x29d1f0 vstr s12, [r6, #44]
 *   @0x29d1f4 str r5, [r6, #0x30]
 *   @0x29d1f8 ldr r3, [r12, #0x8]
 *   @0x29d1fc blx r3
 *   @0x29d200 vldr s15, [sp, #12]
 *   @0x29d204 vcvt.f64.u32 d7, s15
 *   @0x29d208 ldr r3, [r6]
 *   @0x29d20c mov r10, #0
 *   @0x29d210 mov r1, #5
 *   @0x29d214 mov r2, r7
 *   @0x29d218 mov r0, r6
 *   @0x29d21c str r10, [r6, #0x38]
 *   @0x29d220 vmov r4, r5, d7
 *   @0x29d224 vstr s14, [r6, #44]
 *   @0x29d228 str r5, [r6, #0x30]
 *   @0x29d22c ldr r3, [r3, #0x8]
 *   @0x29d230 blx r3
 *   @0x29d234 ldr r1, [sp, #0x10]
 *   @0x29d238 ldr r2, [sp, #0x14]
 *   @0x29d23c mov r12, #10
 *   @0x29d240 ldr r3, [r6]
 *   @0x29d244 mov r0, r6
 *   @0x29d248 str r1, [r6, #0x2c]
 *   @0x29d24c mov r1, #12
 *   @0x29d250 str r2, [r6, #0x30]
 *   @0x29d254 mov r2, r7
 *   @0x29d258 ldr r3, [r3, #0x8]
 *   @0x29d25c str r12, [r6, #0x38]
 *   @0x29d260 blx r3
 *   @0x29d264 ldr r12, [sp, #0x4]
 *   @0x29d268 ldrb r3, [r12]
 *   @0x29d26c cmp r3, r10
 *   @0x29d270 bne 0x29d39c <_Z13Debug_GetPingP15Buffer_StandardS0_+0x324>
 *   @0x29d274 mov r0, r6
 *   @0x29d278 bl 0x29c080 <_Z17Debug_WriteOutputP15Buffer_Standard>
 *   @0x29d27c ldr r3, [pc, #0x234]
 *   @0x29d280 ldr r12, [sp]
 *   @0x29d284 ldr r0, [r8, r3]
 *   @0x29d288 and r1, r12, #1
 *   @0x29d28c bl 0x2a04d8 <_ZN9CProfiler6EnableEb>
 *   @0x29d290 ldr r3, [pc, #0x224]
 *   @0x29d294 ldr r12, [sp]
 *   @0x29d298 mov r0, r6
 *   @0x29d29c ldr r3, [r8, r3]
 *   @0x29d2a0 eor r9, r12, #2
 *   @0x29d2a4 ubfx r9, r9, #0x1, #0x1
 *   @0x29d2a8 strb r9, [r3]
 *   @0x29d2ac bl 0x29c148 <_Z22Debug_WriteProfileDataP15Buffer_Standard>
 *   @0x29d2b0 add sp, sp, #28
 *   @0x29d2b4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x29d2b8 ldr r11, [pc, #0x200]
 *   @0x29d2bc mov r0, r6
 *   @0x29d2c0 ldr r3, [r6]
 *   @0x29d2c4 mov r1, #5
 *   @0x29d2c8 add r11, pc, r11
 *   @0x29d2cc vldr s15, [r11, #556]
 *   @0x29d2d0 vcvt.f64.u32 d7, s15
 *   @0x29d2d4 str r10, [r6, #0x38]
 *   @0x29d2d8 mov r2, r7
 *   @0x29d2dc vmov r4, r5, d7
 *   @0x29d2e0 vstr s14, [r6, #44]
 *   @0x29d2e4 str r5, [r6, #0x30]
 *   @0x29d2e8 ldr r3, [r3, #0x8]
 *   @0x29d2ec blx r3
 *   @0x29d2f0 ldr r3, [r11, #0x22c]
 *   @0x29d2f4 cmp r3, #0
 *   @0x29d2f8 movgt r9, r10
 *   @0x29d2fc movgt r10, r9
 *   @0x29d300 ble 0x29d34c <_Z13Debug_GetPingP15Buffer_StandardS0_+0x2d4>
 *   @0x29d304 ldr r2, [r11, #0x230]
 *   @0x29d308 mov r0, r6
 *   @0x29d30c ldr lr, [r6]
 *   @0x29d310 mov r1, #8
 *   @0x29d314 add r2, r2, r9, lsl #2
 *   @0x29d318 vldr s15, [r2]
 *   @0x29d31c vcvt.f64.f32 d6, s15
 *   @0x29d320 mov r2, r7
 *   @0x29d324 str r10, [r6, #0x38]
 *   @0x29d328 add r9, r9, #1
 *   @0x29d32c vmov r4, r5, d6
 *   @0x29d330 vstr s12, [r6, #44]
 *   @0x29d334 str r5, [r6, #0x30]
 *   @0x29d338 ldr r4, [lr, #0x8]
 *   @0x29d33c blx r4
 *   @0x29d340 ldr r2, [r11, #0x22c]
 *   @0x29d344 cmp r2, r9
 *   @0x29d348 bgt 0x29d304 <_Z13Debug_GetPingP15Buffer_StandardS0_+0x28c>
 *   @0x29d34c ldr r12, [pc, #0x170]
 *   @0x29d350 mov r10, #0
 *   @0x29d354 ldr r3, [r6]
 *   @0x29d358 mov r0, r6
 *   @0x29d35c mov r1, #6
 *   @0x29d360 mov r2, r7
 *   @0x29d364 ldr r12, [r8, r12]
 *   @0x29d368 str r10, [r6, #0x38]
 *   @0x29d36c ldr r4, [r12]
 *   @0x29d370 vmov s13, r4
 *   @0x29d374 vcvt.f64.s32 d6, s13
 *   @0x29d378 vmov r4, r5, d6
 *   @0x29d37c vstr s12, [r6, #44]
 *   @0x29d380 str r5, [r6, #0x30]
 *   @0x29d384 ldr r3, [r3, #0x8]
 *   @0x29d388 blx r3
 *   @0x29d38c ldr r3, [pc, #0x134]
 *   @0x29d390 add r3, pc, r3
 *   @0x29d394 str r10, [r3, #0x22c]
 *   @0x29d398 b 0x29d200 <_Z13Debug_GetPingP15Buffer_StandardS0_+0x188>
 *   @0x29d39c ldr r11, [pc, #0x128]
 *   @0x29d3a0 mov r0, r6
 *   @0x29d3a4 ldr r3, [r6]
 *   @0x29d3a8 mov r1, #3
 *   @0x29d3ac add r11, pc, r11
 *   @0x29d3b0 str r10, [r6, #0x38]
 *   @0x29d3b4 mov r2, r7
 *   @0x29d3b8 ldrh r4, [r11, #8]
 *   @0x29d3bc vmov s13, r4
 *   @0x29d3c0 vcvt.f64.u32 d6, s13
 *   @0x29d3c4 vmov r4, r5, d6
 *   @0x29d3c8 vstr s12, [r6, #44]
 *   @0x29d3cc str r5, [r6, #0x30]
 *   @0x29d3d0 ldr r3, [r3, #0x8]
 *   @0x29d3d4 blx r3
 *   @0x29d3d8 ldrh r3, [r11, #8]
 *   @0x29d3dc cmp r3, r10
 *   @0x29d3e0 movne r9, r11
 *   @0x29d3e4 beq 0x29d484 <_Z13Debug_GetPingP15Buffer_StandardS0_+0x40c>
 *   @0x29d3e8 ldr r3, [r9, #0xc]
 *   @0x29d3ec mov r1, #3
 *   @0x29d3f0 ldr lr, [r6]
 *   @0x29d3f4 mov r2, r7
 *   @0x29d3f8 mov r0, r6
 *   @0x29d3fc ldr r11, [r3, r10, lsl #2]
 *   @0x29d400 mov r3, #0
 *   @0x29d404 add r10, r10, #1
 *   @0x29d408 ldrh r4, [r11]
 *   @0x29d40c str r3, [r6, #0x38]
 *   @0x29d410 vmov s13, r4
 *   @0x29d414 vcvt.f64.u32 d6, s13
 *   @0x29d418 vmov r4, r5, d6
 *   @0x29d41c vstr s12, [r6, #44]
 *   @0x29d420 str r5, [r6, #0x30]
 *   @0x29d424 ldr r4, [lr, #0x8]
 *   @0x29d428 blx r4
 *   @0x29d42c ldr r0, [r11, #0x4]
 *   @0x29d430 bl 0xb6538 <strlen@plt>
 *   @0x29d434 ldr lr, [r6]
 *   @0x29d438 mov r2, #0
 *   @0x29d43c mov r1, #5
 *   @0x29d440 str r2, [r6, #0x38]
 *   @0x29d444 mov r2, r7
 *   @0x29d448 add r4, r0, #1
 *   @0x29d44c mov r0, r6
 *   @0x29d450 vmov s13, r4
 *   @0x29d454 vcvt.f64.u32 d6, s13
 *   @0x29d458 vmov r4, r5, d6
 *   @0x29d45c vstr s12, [r6, #44]
 *   @0x29d460 str r5, [r6, #0x30]
 *   @0x29d464 ldr r4, [lr, #0x8]
 *   @0x29d468 blx r4
 *   @0x29d46c mov r0, r6
 *   @0x29d470 ldr r1, [r11, #0x4]
 *   @0x29d474 bl 0xcddb8 <_ZN7IBuffer5WriteEPKc>
 *   @0x29d478 ldrh r3, [r9, #8]
 *   @0x29d47c cmp r3, r10
 *   @0x29d480 bgt 0x29d3e8 <_Z13Debug_GetPingP15Buffer_StandardS0_+0x370>
 *   @0x29d484 bl 0x29c5c8 <_Z14Debug_FreeTagsv>
 *   @0x29d488 ldr r3, [pc, #0x40]
 *   @0x29d48c mov r2, #0
 *   @0x29d490 add r3, pc, r3
 *   @0x29d494 strh r2, [r3, #8]
 *   @0x29d498 strb r2, [r3, #0xa]
 *   @0x29d49c b 0x29d274 <_Z13Debug_GetPingP15Buffer_StandardS0_+0x1fc>
 *   @0x29d4a0 andseq r4, r5, r8, lsl #23
 *   @0x29d4a4 .word 0xffffdfa0
 *   @0x29d4a8 .word 0xffffc0a4
 *   @0x29d4ac .word 0xfffffdb8
 *   @0x29d4b0 .word 0xffffbcd4
 *   @0x29d4b4 subeq r10, r11, r12, asr #20
 *   @0x29d4b8 .word 0xffffbf1c
 *   @0x29d4bc .word 0xffffef50
 *   @0x29d4c0 subeq r10, r11, r0, asr #18
 *   @0x29d4c4 .word 0xffffeb1c
 *   @0x29d4c8 subeq r10, r11, r8, ror r8
 *   @0x29d4cc subeq r10, r11, r12, asr r8
 *   @0x29d4d0 subeq r10, r11, r8, ror r7
 *
 * ══ §7/28 F_JSNewObject(RValue&, CInstance*, CInstance*, int, RValue*)  0x25acd4  size 1108  277 条（0x25acd4..0x25b128）
 * @func 0x25acd4 0x25b128  size 1108  277 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×6 / UNLOCK_RVALUE_MUTEX()×6 / YYFree(void const*)×6 / operator delete(void*)×6 / YYObjectBase::InternalGetYYVar(int)×2 / JS_StandardBuiltInObjectConstructor(RValue&, CInstance*, CInstance*, int, RValue*) / PushContextStack(YYObjectBase*) / F_JSNewObject(RValue&, CInstance*, CInstance*, int, RValue*)+0x158
 * 字段偏移 top8: 0x8×51 / 0x4×15 / 0xc×15 / 0x-c×6 / 0x10×5 / 0x14×3 / 0x-4×2 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x25acd4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x25acd8 sub sp, sp, #28
 *   @0x25acdc mov r4, r0
 *   @0x25ace0 mov r6, r3
 *   @0x25ace4 ldr r12, [sp, #0x40]
 *   @0x25ace8 str r12, [sp]
 *   @0x25acec str r12, [sp, #0x10]
 *   @0x25acf0 bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_>
 *   @0x25acf4 ldr r5, [r4]
 *   @0x25acf8 mov r0, r5
 *   @0x25acfc bl 0xd3968 <_Z16PushContextStackP12YYObjectBase>
 *   @0x25ad00 cmp r6, #0
 *   @0x25ad04 ble 0x25ae2c <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x158>
 *   @0x25ad08 ldr r3, [sp, #0x10]
 *   @0x25ad0c mov r8, #0
 *   @0x25ad10 ldr r12, [sp, #0x10]
 *   @0x25ad14 add r3, r3, #16
 *   @0x25ad18 str r3, [sp, #0x14]
 *   @0x25ad1c add r7, r12, #28
 *   @0x25ad20 mov r10, r3
 *   @0x25ad24 ldr r2, [r10, #-0x10]
 *   @0x25ad28 mov r0, r5
 *   @0x25ad2c sub r9, r10, #16
 *   @0x25ad30 ldr r1, [r2]
 *   @0x25ad34 bl 0xd2c84 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc>
 *   @0x25ad38 ldr r4, [r5, #0x4]
 *   @0x25ad3c cmp r4, #0
 *   @0x25ad40 mov r11, r0
 *   @0x25ad44 beq 0x25af64 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x290>
 *   @0x25ad48 add r4, r4, r0, lsl #4
 *   @0x25ad4c ldr r1, [r4, #0xc]
 *   @0x25ad50 bic r2, r1, #-16777216
 *   @0x25ad54 cmp r2, #1
 *   @0x25ad58 beq 0x25aec8 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x1f4>
 *   @0x25ad5c cmp r2, #2
 *   @0x25ad60 bne 0x25ad84 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x25ad64 sub r1, r1, #1
 *   @0x25ad68 bic r1, r1, #-16777216
 *   @0x25ad6c bic r1, r1, #3
 *   @0x25ad70 cmp r1, #0
 *   @0x25ad74 beq 0x25af58 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x284>
 *   @0x25ad78 mov r3, #5
 *   @0x25ad7c str r8, [r4, #0x8]
 *   @0x25ad80 str r3, [r4, #0xc]
 *   @0x25ad84 ldr r12, [sp, #0x10]
 *   @0x25ad88 ldr r3, [sp, #0x14]
 *   @0x25ad8c rsb r2, r12, r10
 *   @0x25ad90 str r8, [r4]
 *   @0x25ad94 add r2, r3, r2
 *   @0x25ad98 ldr r1, [r2, #-0x4]
 *   @0x25ad9c str r1, [r4, #0xc]
 *   @0x25ada0 ldr r1, [r2, #-0x8]
 *   @0x25ada4 str r1, [r4, #0x8]
 *   @0x25ada8 ldr r2, [r2, #-0x4]
 *   @0x25adac bic r2, r2, #-16777216
 *   @0x25adb0 cmp r2, #14
 *   @0x25adb4 addls pc, pc, r2, lsl #2
 *   @0x25adb8 b 0x25ae00 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x25adbc b 0x25ae38 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x164>
 *   @0x25adc0 b 0x25ae8c <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x1b8>
 *   @0x25adc4 b 0x25ae60 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x18c>
 *   @0x25adc8 b 0x25adf8 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x25adcc b 0x25ae00 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x25add0 b 0x25ae00 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x25add4 b 0x25aea4 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x1d0>
 *   @0x25add8 b 0x25adf8 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x25addc b 0x25ae00 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x25ade0 b 0x25ae00 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x25ade4 b 0x25ae38 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x164>
 *   @0x25ade8 b 0x25ae00 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x25adec b 0x25ae00 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x25adf0 b 0x25ae38 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x164>
 *   @0x25adf4 b 0x25adf8 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x25adf8 ldr r2, [r7, #-0xc]
 *   @0x25adfc str r2, [r4]
 *   @0x25ae00 ldr r0, [r5, #0x4]
 *   @0x25ae04 cmp r0, #0
 *   @0x25ae08 beq 0x25ae50 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x17c>
 *   @0x25ae0c add r0, r0, r11, lsl #4
 *   @0x25ae10 sub r6, r6, #2
 *   @0x25ae14 mov r12, #7
 *   @0x25ae18 cmp r6, #0
 *   @0x25ae1c str r12, [r0, #0x8]
 *   @0x25ae20 add r7, r7, #32
 *   @0x25ae24 add r10, r10, #32
 *   @0x25ae28 bgt 0x25ad24 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x25ae2c add sp, sp, #28
 *   @0x25ae30 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x25ae34 b 0xd3a34 <_Z15PopContextStackv>
 *   @0x25ae38 ldr r1, [r9, #0x10]
 *   @0x25ae3c ldr r2, [r9, #0x14]
 *   @0x25ae40 stm r4, {r1, r2}
 *   @0x25ae44 ldr r0, [r5, #0x4]
 *   @0x25ae48 cmp r0, #0
 *   @0x25ae4c bne 0x25ae0c <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x138>
 *   @0x25ae50 mov r1, r11
 *   @0x25ae54 mov r0, r5
 *   @0x25ae58 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x25ae5c b 0x25ae10 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x25ae60 ldr r2, [r7, #-0xc]
 *   @0x25ae64 cmp r2, #0
 *   @0x25ae68 str r2, [r4]
 *   @0x25ae6c beq 0x25ae00 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x25ae70 ldr r0, [r2, #0x8]
 *   @0x25ae74 ldr r1, [r2]
 *   @0x25ae78 cmp r0, #0
 *   @0x25ae7c streq r4, [r2, #0x8]
 *   @0x25ae80 add r1, r1, #1
 *   @0x25ae84 str r1, [r2]
 *   @0x25ae88 b 0x25ae00 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x25ae8c ldr r2, [r7, #-0xc]
 *   @0x25ae90 cmp r2, #0
 *   @0x25ae94 ldrne r1, [r2, #0x4]
 *   @0x25ae98 addne r1, r1, #1
 *   @0x25ae9c strne r1, [r2, #0x4]
 *   @0x25aea0 b 0x25adfc <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x25aea4 ldr r2, [r7, #-0xc]
 *   @0x25aea8 str r2, [r4]
 *   @0x25aeac ldr r2, [r7, #-0xc]
 *   @0x25aeb0 cmp r2, #0
 *   @0x25aeb4 beq 0x25ae00 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x25aeb8 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x25aebc ldr r1, [r7, #-0xc]
 *   @0x25aec0 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x25aec4 b 0x25ae00 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x25aec8 ldr r2, [r4]
 *   @0x25aecc cmp r2, #0
 *   @0x25aed0 beq 0x25aef8 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x224>
 *   @0x25aed4 str r2, [sp, #0x8]
 *   @0x25aed8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x25aedc ldr r2, [sp, #0x8]
 *   @0x25aee0 ldr r1, [r2, #0x4]
 *   @0x25aee4 sub r1, r1, #1
 *   @0x25aee8 str r1, [r2, #0x4]
 *   @0x25aeec cmp r1, #0
 *   @0x25aef0 beq 0x25af00 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x22c>
 *   @0x25aef4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x25aef8 str r8, [r4]
 *   @0x25aefc b 0x25ad84 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x25af00 ldr r0, [r2]
 *   @0x25af04 str r1, [sp, #0xc]
 *   @0x25af08 str r2, [sp, #0x8]
 *   @0x25af0c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x25af10 ldr r2, [sp, #0x8]
 *   @0x25af14 ldr r1, [sp, #0xc]
 *   @0x25af18 str r1, [r2]
 *   @0x25af1c str r1, [r2, #0x8]
 *   @0x25af20 str r2, [sp, #0x8]
 *   @0x25af24 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x25af28 ldr r2, [sp, #0x8]
 *   @0x25af2c ldr r1, [r2, #0x4]
 *   @0x25af30 sub r1, r1, #1
 *   @0x25af34 str r1, [r2, #0x4]
 *   @0x25af38 cmp r1, #0
 *   @0x25af3c beq 0x25af78 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x2a4>
 *   @0x25af40 str r2, [sp, #0x8]
 *   @0x25af44 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x25af48 ldr r2, [sp, #0x8]
 *   @0x25af4c mov r0, r2
 *   @0x25af50 bl 0x27d1d0 <_ZdlPv>
 *   @0x25af54 b 0x25aef4 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x220>
 *   @0x25af58 mov r0, r4
 *   @0x25af5c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x25af60 b 0x25ad78 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x25af64 mov r0, r5
 *   @0x25af68 mov r1, r11
 *   @0x25af6c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x25af70 mov r4, r0
 *   @0x25af74 b 0x25ad4c <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x25af78 ldr r0, [r2]
 *   @0x25af7c str r1, [sp, #0xc]
 *   @0x25af80 str r2, [sp, #0x8]
 *   @0x25af84 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x25af88 ldr r2, [sp, #0x8]
 *   @0x25af8c ldr r1, [sp, #0xc]
 *   @0x25af90 str r1, [r2]
 *   @0x25af94 str r1, [r2, #0x8]
 *   @0x25af98 str r2, [sp, #0x8]
 *   @0x25af9c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x25afa0 ldr r2, [sp, #0x8]
 *   @0x25afa4 ldr r1, [r2, #0x4]
 *   @0x25afa8 sub r1, r1, #1
 *   @0x25afac str r1, [r2, #0x4]
 *   @0x25afb0 cmp r1, #0
 *   @0x25afb4 beq 0x25afd4 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x300>
 *   @0x25afb8 str r2, [sp, #0x8]
 *   @0x25afbc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x25afc0 ldr r2, [sp, #0x8]
 *   @0x25afc4 mov r0, r2
 *   @0x25afc8 bl 0x27d1d0 <_ZdlPv>
 *   @0x25afcc ldr r2, [sp, #0x8]
 *   @0x25afd0 b 0x25af40 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x26c>
 *   @0x25afd4 ldr r0, [r2]
 *   @0x25afd8 str r1, [sp, #0xc]
 *   @0x25afdc str r2, [sp, #0x8]
 *   @0x25afe0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x25afe4 ldr r2, [sp, #0x8]
 *   @0x25afe8 ldr r1, [sp, #0xc]
 *   @0x25afec str r1, [r2]
 *   @0x25aff0 str r1, [r2, #0x8]
 *   @0x25aff4 str r2, [sp, #0x8]
 *   @0x25aff8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x25affc ldr r2, [sp, #0x8]
 *   @0x25b000 ldr r1, [r2, #0x4]
 *   @0x25b004 sub r1, r1, #1
 *   @0x25b008 str r1, [r2, #0x4]
 *   @0x25b00c cmp r1, #0
 *   @0x25b010 beq 0x25b030 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x35c>
 *   @0x25b014 str r2, [sp, #0x8]
 *   @0x25b018 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x25b01c ldr r2, [sp, #0x8]
 *   @0x25b020 mov r0, r2
 *   @0x25b024 bl 0x27d1d0 <_ZdlPv>
 *   @0x25b028 ldr r2, [sp, #0x8]
 *   @0x25b02c b 0x25afb8 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x2e4>
 *   @0x25b030 ldr r0, [r2]
 *   @0x25b034 str r1, [sp, #0xc]
 *   @0x25b038 str r2, [sp, #0x8]
 *   @0x25b03c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x25b040 ldr r2, [sp, #0x8]
 *   @0x25b044 ldr r1, [sp, #0xc]
 *   @0x25b048 str r1, [r2]
 *   @0x25b04c str r1, [r2, #0x8]
 *   @0x25b050 str r2, [sp, #0x8]
 *   @0x25b054 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x25b058 ldr r2, [sp, #0x8]
 *   @0x25b05c ldr r1, [r2, #0x4]
 *   @0x25b060 sub r1, r1, #1
 *   @0x25b064 str r1, [r2, #0x4]
 *   @0x25b068 cmp r1, #0
 *   @0x25b06c beq 0x25b08c <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x3b8>
 *   @0x25b070 str r2, [sp, #0x8]
 *   @0x25b074 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x25b078 ldr r2, [sp, #0x8]
 *   @0x25b07c mov r0, r2
 *   @0x25b080 bl 0x27d1d0 <_ZdlPv>
 *   @0x25b084 ldr r2, [sp, #0x8]
 *   @0x25b088 b 0x25b014 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x340>
 *   @0x25b08c ldr r0, [r2]
 *   @0x25b090 str r1, [sp, #0xc]
 *   @0x25b094 str r2, [sp, #0x8]
 *   @0x25b098 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x25b09c ldr r2, [sp, #0x8]
 *   @0x25b0a0 ldr r1, [sp, #0xc]
 *   @0x25b0a4 str r1, [r2]
 *   @0x25b0a8 str r1, [r2, #0x8]
 *   @0x25b0ac str r2, [sp, #0x8]
 *   @0x25b0b0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x25b0b4 ldr r2, [sp, #0x8]
 *   @0x25b0b8 ldr r1, [r2, #0x4]
 *   @0x25b0bc sub r1, r1, #1
 *   @0x25b0c0 str r1, [r2, #0x4]
 *   @0x25b0c4 cmp r1, #0
 *   @0x25b0c8 beq 0x25b0e8 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x414>
 *   @0x25b0cc str r2, [sp, #0x8]
 *   @0x25b0d0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x25b0d4 ldr r2, [sp, #0x8]
 *   @0x25b0d8 mov r0, r2
 *   @0x25b0dc bl 0x27d1d0 <_ZdlPv>
 *   @0x25b0e0 ldr r2, [sp, #0x8]
 *   @0x25b0e4 b 0x25b070 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x39c>
 *   @0x25b0e8 ldr r0, [r2]
 *   @0x25b0ec str r1, [sp, #0xc]
 *   @0x25b0f0 str r2, [sp, #0x8]
 *   @0x25b0f4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x25b0f8 ldr r2, [sp, #0x8]
 *   @0x25b0fc ldr r1, [sp, #0xc]
 *   @0x25b100 mov r0, r2
 *   @0x25b104 str r1, [r2]
 *   @0x25b108 str r1, [r2, #0x8]
 *   @0x25b10c str r2, [sp, #0x8]
 *   @0x25b110 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x25b114 ldr r2, [sp, #0x8]
 *   @0x25b118 mov r0, r2
 *   @0x25b11c bl 0x27d1d0 <_ZdlPv>
 *   @0x25b120 ldr r2, [sp, #0x8]
 *   @0x25b124 b 0x25b0cc <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x3f8>
 *
 * ══ §8/28 CDS_List::Set(int, RValue*, RValue*)  0x2060c0  size 1104  276 条（0x2060c0..0x206510）
 * @func 0x2060c0 0x206510  size 1104  276 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / GetContextStackTop()×2 / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)×2 / _RefThing<char const*>::dec()×2 / FREE_RValue__Pre(RValue*)×2
 * 字段偏移 top8: 0x4×30 / 0x8×15 / 0xc×12 / 0x264×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2060c0 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2060c4 subs r6, r1, #0
 *   @0x2060c8 mov r5, r0
 *   @0x2060cc mov r8, r2
 *   @0x2060d0 mov r4, r3
 *   @0x2060d4 blt 0x2064f8 <_ZN8CDS_List3SetEiP6RValueS1_+0x438>
 *   @0x2060d8 ldr r1, [r0, #0x4]
 *   @0x2060dc ldr r3, [r0, #0x8]
 *   @0x2060e0 cmp r6, r1
 *   @0x2060e4 addge r1, r6, #1
 *   @0x2060e8 strge r1, [r0, #0x4]
 *   @0x2060ec cmp r3, r1
 *   @0x2060f0 ble 0x20629c <_ZN8CDS_List3SetEiP6RValueS1_+0x1dc>
 *   @0x2060f4 ldr r7, [r5, #0xc]
 *   @0x2060f8 cmp r4, #0
 *   @0x2060fc add r5, r7, r6, lsl #4
 *   @0x206100 beq 0x2062d4 <_ZN8CDS_List3SetEiP6RValueS1_+0x214>
 *   @0x206104 ldr r2, [r4, #0xc]
 *   @0x206108 bic r3, r2, #-16777216
 *   @0x20610c cmp r3, #1
 *   @0x206110 beq 0x2062f0 <_ZN8CDS_List3SetEiP6RValueS1_+0x230>
 *   @0x206114 cmp r3, #2
 *   @0x206118 bne 0x206140 <_ZN8CDS_List3SetEiP6RValueS1_+0x80>
 *   @0x20611c sub r2, r2, #1
 *   @0x206120 bic r2, r2, #-16777216
 *   @0x206124 bic r2, r2, #3
 *   @0x206128 cmp r2, #0
 *   @0x20612c beq 0x2064e0 <_ZN8CDS_List3SetEiP6RValueS1_+0x420>
 *   @0x206130 mov r2, #0
 *   @0x206134 mov r3, #5
 *   @0x206138 str r2, [r4, #0x8]
 *   @0x20613c str r3, [r4, #0xc]
 *   @0x206140 ldr r2, [r5, #0xc]
 *   @0x206144 mov r1, #0
 *   @0x206148 ldr r3, [r5, #0x8]
 *   @0x20614c str r1, [r4]
 *   @0x206150 str r2, [r4, #0xc]
 *   @0x206154 ldr r2, [r5, #0xc]
 *   @0x206158 str r3, [r4, #0x8]
 *   @0x20615c bic r3, r2, #-16777216
 *   @0x206160 cmp r3, #14
 *   @0x206164 addls pc, pc, r3, lsl #2
 *   @0x206168 b 0x206260 <_ZN8CDS_List3SetEiP6RValueS1_+0x1a0>
 *   @0x20616c b 0x206428 <_ZN8CDS_List3SetEiP6RValueS1_+0x368>
 *   @0x206170 b 0x206240 <_ZN8CDS_List3SetEiP6RValueS1_+0x180>
 *   @0x206174 b 0x206438 <_ZN8CDS_List3SetEiP6RValueS1_+0x378>
 *   @0x206178 b 0x2061a8 <_ZN8CDS_List3SetEiP6RValueS1_+0xe8>
 *   @0x20617c b 0x206260 <_ZN8CDS_List3SetEiP6RValueS1_+0x1a0>
 *   @0x206180 b 0x206260 <_ZN8CDS_List3SetEiP6RValueS1_+0x1a0>
 *   @0x206184 b 0x2063f4 <_ZN8CDS_List3SetEiP6RValueS1_+0x334>
 *   @0x206188 b 0x2061a8 <_ZN8CDS_List3SetEiP6RValueS1_+0xe8>
 *   @0x20618c b 0x206260 <_ZN8CDS_List3SetEiP6RValueS1_+0x1a0>
 *   @0x206190 b 0x206260 <_ZN8CDS_List3SetEiP6RValueS1_+0x1a0>
 *   @0x206194 b 0x206418 <_ZN8CDS_List3SetEiP6RValueS1_+0x358>
 *   @0x206198 b 0x206260 <_ZN8CDS_List3SetEiP6RValueS1_+0x1a0>
 *   @0x20619c b 0x206260 <_ZN8CDS_List3SetEiP6RValueS1_+0x1a0>
 *   @0x2061a0 b 0x206428 <_ZN8CDS_List3SetEiP6RValueS1_+0x368>
 *   @0x2061a4 b 0x2061a8 <_ZN8CDS_List3SetEiP6RValueS1_+0xe8>
 *   @0x2061a8 ldr r3, [r7, r6, lsl #4]
 *   @0x2061ac str r3, [r4]
 *   @0x2061b0 ldr r3, [r8, #0xc]
 *   @0x2061b4 mov r1, #0
 *   @0x2061b8 ldr r2, [r8, #0x8]
 *   @0x2061bc str r1, [r7, r6, lsl #4]
 *   @0x2061c0 str r3, [r5, #0xc]
 *   @0x2061c4 ldr r3, [r8, #0xc]
 *   @0x2061c8 str r2, [r5, #0x8]
 *   @0x2061cc bic r3, r3, #-16777216
 *   @0x2061d0 cmp r3, #14
 *   @0x2061d4 addls pc, pc, r3, lsl #2
 *   @0x2061d8 b 0x206374 <_ZN8CDS_List3SetEiP6RValueS1_+0x2b4>
 *   @0x2061dc b 0x206228 <_ZN8CDS_List3SetEiP6RValueS1_+0x168>
 *   @0x2061e0 b 0x20637c <_ZN8CDS_List3SetEiP6RValueS1_+0x2bc>
 *   @0x2061e4 b 0x20634c <_ZN8CDS_List3SetEiP6RValueS1_+0x28c>
 *   @0x2061e8 b 0x206218 <_ZN8CDS_List3SetEiP6RValueS1_+0x158>
 *   @0x2061ec b 0x206374 <_ZN8CDS_List3SetEiP6RValueS1_+0x2b4>
 *   @0x2061f0 b 0x206374 <_ZN8CDS_List3SetEiP6RValueS1_+0x2b4>
 *   @0x2061f4 b 0x206324 <_ZN8CDS_List3SetEiP6RValueS1_+0x264>
 *   @0x2061f8 b 0x206218 <_ZN8CDS_List3SetEiP6RValueS1_+0x158>
 *   @0x2061fc b 0x206374 <_ZN8CDS_List3SetEiP6RValueS1_+0x2b4>
 *   @0x206200 b 0x206374 <_ZN8CDS_List3SetEiP6RValueS1_+0x2b4>
 *   @0x206204 b 0x206228 <_ZN8CDS_List3SetEiP6RValueS1_+0x168>
 *   @0x206208 b 0x206374 <_ZN8CDS_List3SetEiP6RValueS1_+0x2b4>
 *   @0x20620c b 0x206374 <_ZN8CDS_List3SetEiP6RValueS1_+0x2b4>
 *   @0x206210 b 0x206228 <_ZN8CDS_List3SetEiP6RValueS1_+0x168>
 *   @0x206214 b 0x206218 <_ZN8CDS_List3SetEiP6RValueS1_+0x158>
 *   @0x206218 ldr r3, [r8]
 *   @0x20621c mov r0, r4
 *   @0x206220 str r3, [r7, r6, lsl #4]
 *   @0x206224 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x206228 ldr r2, [r8]
 *   @0x20622c mov r0, r4
 *   @0x206230 ldr r3, [r8, #0x4]
 *   @0x206234 str r2, [r7, r6, lsl #4]
 *   @0x206238 str r3, [r5, #0x4]
 *   @0x20623c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x206240 ldr r1, [r7, r6, lsl #4]
 *   @0x206244 cmp r1, #0
 *   @0x206248 ldrne r3, [r1, #0x4]
 *   @0x20624c addne r3, r3, #1
 *   @0x206250 strne r3, [r1, #0x4]
 *   @0x206254 ldrne r2, [r5, #0xc]
 *   @0x206258 str r1, [r4]
 *   @0x20625c bicne r3, r2, #-16777216
 *   @0x206260 cmp r3, #1
 *   @0x206264 bne 0x2062e4 <_ZN8CDS_List3SetEiP6RValueS1_+0x224>
 *   @0x206268 ldr r9, [r7, r6, lsl #4]
 *   @0x20626c cmp r9, #0
 *   @0x206270 beq 0x206290 <_ZN8CDS_List3SetEiP6RValueS1_+0x1d0>
 *   @0x206274 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x206278 ldr r10, [r9, #0x4]
 *   @0x20627c sub r10, r10, #1
 *   @0x206280 str r10, [r9, #0x4]
 *   @0x206284 cmp r10, #0
 *   @0x206288 beq 0x20639c <_ZN8CDS_List3SetEiP6RValueS1_+0x2dc>
 *   @0x20628c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x206290 mov r3, #0
 *   @0x206294 str r3, [r7, r6, lsl #4]
 *   @0x206298 b 0x2061b0 <_ZN8CDS_List3SetEiP6RValueS1_+0xf0>
 *   @0x20629c add r1, r1, #16
 *   @0x2062a0 ldr r2, [pc, #0x264]
 *   @0x2062a4 movw r3, #0x52b
 *   @0x2062a8 add r0, r0, #12
 *   @0x2062ac add r2, pc, r2
 *   @0x2062b0 lsl r1, r1, #4
 *   @0x2062b4 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x2062b8 ldr r3, [r5, #0x4]
 *   @0x2062bc ldr r7, [r5, #0xc]
 *   @0x2062c0 cmp r4, #0
 *   @0x2062c4 add r3, r3, #16
 *   @0x2062c8 str r3, [r5, #0x8]
 *   @0x2062cc add r5, r7, r6, lsl #4
 *   @0x2062d0 bne 0x206104 <_ZN8CDS_List3SetEiP6RValueS1_+0x44>
 *   @0x2062d4 ldr r2, [r5, #0xc]
 *   @0x2062d8 bic r3, r2, #-16777216
 *   @0x2062dc cmp r3, #1
 *   @0x2062e0 beq 0x206268 <_ZN8CDS_List3SetEiP6RValueS1_+0x1a8>
 *   @0x2062e4 cmp r3, #2
 *   @0x2062e8 beq 0x206460 <_ZN8CDS_List3SetEiP6RValueS1_+0x3a0>
 *   @0x2062ec b 0x2061b0 <_ZN8CDS_List3SetEiP6RValueS1_+0xf0>
 *   @0x2062f0 ldr r9, [r4]
 *   @0x2062f4 cmp r9, #0
 *   @0x2062f8 beq 0x206318 <_ZN8CDS_List3SetEiP6RValueS1_+0x258>
 *   @0x2062fc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x206300 ldr r10, [r9, #0x4]
 *   @0x206304 sub r10, r10, #1
 *   @0x206308 str r10, [r9, #0x4]
 *   @0x20630c cmp r10, #0
 *   @0x206310 beq 0x206488 <_ZN8CDS_List3SetEiP6RValueS1_+0x3c8>
 *   @0x206314 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x206318 mov r3, #0
 *   @0x20631c str r3, [r4]
 *   @0x206320 b 0x206140 <_ZN8CDS_List3SetEiP6RValueS1_+0x80>
 *   @0x206324 ldr r3, [r8]
 *   @0x206328 str r3, [r7, r6, lsl #4]
 *   @0x20632c ldr r3, [r8]
 *   @0x206330 cmp r3, #0
 *   @0x206334 beq 0x206374 <_ZN8CDS_List3SetEiP6RValueS1_+0x2b4>
 *   @0x206338 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x20633c ldr r1, [r8]
 *   @0x206340 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x206344 mov r0, r4
 *   @0x206348 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x20634c ldr r3, [r8]
 *   @0x206350 cmp r3, #0
 *   @0x206354 str r3, [r7, r6, lsl #4]
 *   @0x206358 beq 0x206374 <_ZN8CDS_List3SetEiP6RValueS1_+0x2b4>
 *   @0x20635c ldr r1, [r3, #0x8]
 *   @0x206360 ldr r2, [r3]
 *   @0x206364 cmp r1, #0
 *   @0x206368 add r2, r2, #1
 *   @0x20636c str r2, [r3]
 *   @0x206370 beq 0x206500 <_ZN8CDS_List3SetEiP6RValueS1_+0x440>
 *   @0x206374 mov r0, r4
 *   @0x206378 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x20637c ldr r3, [r8]
 *   @0x206380 mov r0, r4
 *   @0x206384 cmp r3, #0
 *   @0x206388 ldrne r2, [r3, #0x4]
 *   @0x20638c addne r2, r2, #1
 *   @0x206390 strne r2, [r3, #0x4]
 *   @0x206394 str r3, [r7, r6, lsl #4]
 *   @0x206398 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x20639c ldr r0, [r9]
 *   @0x2063a0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x2063a4 str r10, [r9]
 *   @0x2063a8 str r10, [r9, #0x8]
 *   @0x2063ac bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x2063b0 ldr r10, [r9, #0x4]
 *   @0x2063b4 sub r10, r10, #1
 *   @0x2063b8 str r10, [r9, #0x4]
 *   @0x2063bc cmp r10, #0
 *   @0x2063c0 bne 0x2063e4 <_ZN8CDS_List3SetEiP6RValueS1_+0x324>
 *   @0x2063c4 ldr r0, [r9]
 *   @0x2063c8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x2063cc mov r0, r9
 *   @0x2063d0 str r10, [r9]
 *   @0x2063d4 str r10, [r9, #0x8]
 *   @0x2063d8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x2063dc mov r0, r9
 *   @0x2063e0 bl 0x27d1d0 <_ZdlPv>
 *   @0x2063e4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x2063e8 mov r0, r9
 *   @0x2063ec bl 0x27d1d0 <_ZdlPv>
 *   @0x2063f0 b 0x20628c <_ZN8CDS_List3SetEiP6RValueS1_+0x1cc>
 *   @0x2063f4 ldr r3, [r7, r6, lsl #4]
 *   @0x2063f8 str r3, [r4]
 *   @0x2063fc ldr r3, [r7, r6, lsl #4]
 *   @0x206400 cmp r3, #0
 *   @0x206404 beq 0x2061b0 <_ZN8CDS_List3SetEiP6RValueS1_+0xf0>
 *   @0x206408 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x20640c ldr r1, [r7, r6, lsl #4]
 *   @0x206410 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x206414 b 0x2062d4 <_ZN8CDS_List3SetEiP6RValueS1_+0x214>
 *   @0x206418 ldr r2, [r7, r6, lsl #4]
 *   @0x20641c ldr r3, [r5, #0x4]
 *   @0x206420 stm r4, {r2, r3}
 *   @0x206424 b 0x2061b0 <_ZN8CDS_List3SetEiP6RValueS1_+0xf0>
 *   @0x206428 ldr r0, [r7, r6, lsl #4]
 *   @0x20642c ldr r1, [r5, #0x4]
 *   @0x206430 stm r4, {r0, r1}
 *   @0x206434 b 0x206260 <_ZN8CDS_List3SetEiP6RValueS1_+0x1a0>
 *   @0x206438 ldr r3, [r7, r6, lsl #4]
 *   @0x20643c cmp r3, #0
 *   @0x206440 str r3, [r4]
 *   @0x206444 beq 0x206460 <_ZN8CDS_List3SetEiP6RValueS1_+0x3a0>
 *   @0x206448 ldr r0, [r3, #0x8]
 *   @0x20644c ldr r1, [r3]
 *   @0x206450 cmp r0, #0
 *   @0x206454 streq r4, [r3, #0x8]
 *   @0x206458 add r1, r1, #1
 *   @0x20645c str r1, [r3]
 *   @0x206460 sub r2, r2, #1
 *   @0x206464 bic r2, r2, #-16777216
 *   @0x206468 bic r2, r2, #3
 *   @0x20646c cmp r2, #0
 *   @0x206470 beq 0x2064ec <_ZN8CDS_List3SetEiP6RValueS1_+0x42c>
 *   @0x206474 mov r2, #0
 *   @0x206478 mov r3, #5
 *   @0x20647c str r2, [r5, #0x8]
 *   @0x206480 str r3, [r5, #0xc]
 *   @0x206484 b 0x2061b0 <_ZN8CDS_List3SetEiP6RValueS1_+0xf0>
 *   @0x206488 ldr r0, [r9]
 *   @0x20648c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x206490 str r10, [r9]
 *   @0x206494 str r10, [r9, #0x8]
 *   @0x206498 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20649c ldr r10, [r9, #0x4]
 *   @0x2064a0 sub r10, r10, #1
 *   @0x2064a4 str r10, [r9, #0x4]
 *   @0x2064a8 cmp r10, #0
 *   @0x2064ac bne 0x2064d0 <_ZN8CDS_List3SetEiP6RValueS1_+0x410>
 *   @0x2064b0 ldr r0, [r9]
 *   @0x2064b4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x2064b8 mov r0, r9
 *   @0x2064bc str r10, [r9]
 *   @0x2064c0 str r10, [r9, #0x8]
 *   @0x2064c4 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x2064c8 mov r0, r9
 *   @0x2064cc bl 0x27d1d0 <_ZdlPv>
 *   @0x2064d0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x2064d4 mov r0, r9
 *   @0x2064d8 bl 0x27d1d0 <_ZdlPv>
 *   @0x2064dc b 0x206314 <_ZN8CDS_List3SetEiP6RValueS1_+0x254>
 *   @0x2064e0 mov r0, r4
 *   @0x2064e4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x2064e8 b 0x206130 <_ZN8CDS_List3SetEiP6RValueS1_+0x70>
 *   @0x2064ec mov r0, r5
 *   @0x2064f0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x2064f4 b 0x206474 <_ZN8CDS_List3SetEiP6RValueS1_+0x3b4>
 *   @0x2064f8 mov r0, #0
 *   @0x2064fc pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x206500 str r5, [r3, #0x8]
 *   @0x206504 mov r0, r4
 *   @0x206508 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x20650c andseq sp, r4, r0, asr #10
 *
 * ══ §9/28 CFontGM::Draw_String_Transformed_Color(float, float, unsigned short*, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, float)  0xf8f58  size 1100  275 条（0xf8f58..0xf93a4）
 * @func 0xf8f58 0xf93a4  size 1100  275 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Color_Merge(unsigned int, unsigned int, float)×8 / CFontGM::Draw_String_Transformed_Color(float, float, unsigned short*, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, float)+0x80×2 / CFontGM::GetGlyph(int)×2 / yywcslen(unsigned short const*) / CFontGM::TextWidth(unsigned short*) / 0xb6580 / 0xb658c / CFontGM::Draw_String_Transformed_Color(float, float, unsigned short*, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, float)+0x110
 * 字段偏移 top8: 0x20×5 / 0xa0×4 / 0xa4×4 / 0xa8×4 / 0x9c×3 / 0x1c×3 / 0x24×3 / 0x18×2
 * VFP 指令 138 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf8f58 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xf8f5c vpush {d8, d9, d10, d11, d12, d13}
 *   @0xf8f60 mov r6, r0
 *   @0xf8f64 vldr s20, [pc, #912]
 *   @0xf8f68 sub sp, sp, #60
 *   @0xf8f6c mov r0, r3
 *   @0xf8f70 mov r4, r3
 *   @0xf8f74 vmov s19, r2
 *   @0xf8f78 vldr s17, [sp, #152]
 *   @0xf8f7c vmov s18, r1
 *   @0xf8f80 vldr s16, [sp, #144]
 *   @0xf8f84 vldr s26, [sp, #148]
 *   @0xf8f88 vldr s27, [sp, #172]
 *   @0xf8f8c bl 0xf6c78 <_Z8yywcslenPKt>
 *   @0xf8f90 mov r1, r4
 *   @0xf8f94 mov r7, r0
 *   @0xf8f98 mov r0, r6
 *   @0xf8f9c bl 0xf8b04 <_ZN7CFontGM9TextWidthEPt>
 *   @0xf8fa0 vmul.f32 s20, s17, s20
 *   @0xf8fa4 vmov s25, r0
 *   @0xf8fa8 vmov r0, s20
 *   @0xf8fac bl 0xb6580 <sinf@plt>
 *   @0xf8fb0 vmov s22, r0
 *   @0xf8fb4 vmov r0, s20
 *   @0xf8fb8 bl 0xb658c <cosf@plt>
 *   @0xf8fbc vmov s23, r0
 *   @0xf8fc0 ldr r0, [r6, #0x20]
 *   @0xf8fc4 cmp r0, #0
 *   @0xf8fc8 blt 0xf9068 <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf+0x110>
 *   @0xf8fcc bl 0x1eee98 <_Z13Sprite_Existsi>
 *   @0xf8fd0 cmp r0, #0
 *   @0xf8fd4 bne 0xf8fe4 <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf+0x8c>
 *   @0xf8fd8 add sp, sp, #60
 *   @0xf8fdc vpop {d8, d9, d10, d11, d12, d13}
 *   @0xf8fe0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xf8fe4 ldr r0, [r6, #0x20]
 *   @0xf8fe8 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0xf8fec cmp r7, #0
 *   @0xf8ff0 mov r9, r0
 *   @0xf8ff4 ble 0xf8fd8 <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf+0x80>
 *   @0xf8ff8 vmul.f32 s22, s22, s16
 *   @0xf8ffc lsl r7, r7, #1
 *   @0xf9000 mov r5, #0
 *   @0xf9004 vldr s20, [pc, #756]
 *   @0xf9008 ldr r11, [sp, #0x9c]
 *   @0xf900c vmul.f32 s23, s23, s16
 *   @0xf9010 b 0xf9020 <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf+0xc8>
 *   @0xf9014 add r5, r5, #2
 *   @0xf9018 cmp r5, r7
 *   @0xf901c beq 0xf8fd8 <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf+0x80>
 *   @0xf9020 ldrh r10, [r4, r5]
 *   @0xf9024 cmp r10, #0
 *   @0xf9028 beq 0xf9014 <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf+0xbc>
 *   @0xf902c mov r1, r10
 *   @0xf9030 mov r0, r6
 *   @0xf9034 bl 0xf6d60 <_ZN7CFontGM8GetGlyphEi>
 *   @0xf9038 ldr r1, [sp, #0xa0]
 *   @0xf903c subs r8, r0, #0
 *   @0xf9040 mov r0, r11
 *   @0xf9044 beq 0xf9014 <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf+0xbc>
 *   @0xf9048 cmp r10, #32
 *   @0xf904c bne 0xf91f0 <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf+0x298>
 *   @0xf9050 ldrsh r8, [r8, #10]
 *   @0xf9054 vmov s15, r8
 *   @0xf9058 vcvt.f32.s32 s15, s15
 *   @0xf905c vmla.f32 s18, s15, s23
 *   @0xf9060 vmls.f32 s19, s22, s15
 *   @0xf9064 b 0xf9014 <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf+0xbc>
 *   @0xf9068 cmp r7, #0
 *   @0xf906c ble 0xf8fd8 <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf+0x80>
 *   @0xf9070 lsl r7, r7, #1
 *   @0xf9074 mov r5, #0
 *   @0xf9078 vldr s17, [pc, #640]
 *   @0xf907c b 0xf908c <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf+0x134>
 *   @0xf9080 add r5, r5, #2
 *   @0xf9084 cmp r5, r7
 *   @0xf9088 beq 0xf8fd8 <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf+0x80>
 *   @0xf908c ldrh r1, [r4, r5]
 *   @0xf9090 cmp r1, #0
 *   @0xf9094 beq 0xf9080 <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf+0x128>
 *   @0xf9098 mov r0, r6
 *   @0xf909c bl 0xf6d60 <_ZN7CFontGM8GetGlyphEi>
 *   @0xf90a0 ldr r1, [sp, #0xa0]
 *   @0xf90a4 subs r8, r0, #0
 *   @0xf90a8 ldr r0, [sp, #0x9c]
 *   @0xf90ac beq 0xf9080 <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf+0x128>
 *   @0xf90b0 vcvt.f32.s32 s21, s25
 *   @0xf90b4 vdiv.f32 s24, s17, s21
 *   @0xf90b8 vmov r2, s24
 *   @0xf90bc bl 0x20ffb8 <_Z11Color_Mergejjf>
 *   @0xf90c0 ldrsh r3, [r8, #10]
 *   @0xf90c4 ldr r1, [sp, #0xa0]
 *   @0xf90c8 vmov s15, r3
 *   @0xf90cc vcvt.f32.s32 s15, s15
 *   @0xf90d0 vadd.f32 s15, s15, s17
 *   @0xf90d4 vdiv.f32 s15, s15, s21
 *   @0xf90d8 mov r11, r0
 *   @0xf90dc ldr r0, [sp, #0x9c]
 *   @0xf90e0 vmov r2, s15
 *   @0xf90e4 bl 0x20ffb8 <_Z11Color_Mergejjf>
 *   @0xf90e8 ldr r1, [sp, #0xa4]
 *   @0xf90ec mov r10, r0
 *   @0xf90f0 ldrsh r0, [r8, #10]
 *   @0xf90f4 vmov s15, r0
 *   @0xf90f8 ldr r0, [sp, #0xa8]
 *   @0xf90fc vcvt.f32.s32 s15, s15
 *   @0xf9100 vadd.f32 s15, s15, s17
 *   @0xf9104 vdiv.f32 s15, s15, s21
 *   @0xf9108 vmov r2, s15
 *   @0xf910c bl 0x20ffb8 <_Z11Color_Mergejjf>
 *   @0xf9110 ldr r1, [sp, #0xa4]
 *   @0xf9114 vmov r2, s24
 *   @0xf9118 mov r9, r0
 *   @0xf911c ldr r0, [sp, #0xa8]
 *   @0xf9120 bl 0x20ffb8 <_Z11Color_Mergejjf>
 *   @0xf9124 mov lr, r0
 *   @0xf9128 ldr r0, [r6, #0x3c]
 *   @0xf912c cmp r0, #0
 *   @0xf9130 beq 0xf9304 <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf+0x3ac>
 *   @0xf9134 ldrsh r3, [r8, #12]
 *   @0xf9138 ldrsh r1, [r8, #2]
 *   @0xf913c ldrsh r2, [r8, #4]
 *   @0xf9140 vmov s15, r3
 *   @0xf9144 ldrsh r3, [r8, #8]
 *   @0xf9148 vcvt.f32.s32 s15, s15
 *   @0xf914c vmov s12, r3
 *   @0xf9150 ldrsh r3, [r8, #6]
 *   @0xf9154 vstr s16, [sp, #12]
 *   @0xf9158 vstr s26, [sp, #16]
 *   @0xf915c vstr s20, [sp, #20]
 *   @0xf9160 str r11, [sp, #0x18]
 *   @0xf9164 vstr s27, [sp, #40]
 *   @0xf9168 str r10, [sp, #0x1c]
 *   @0xf916c str r9, [sp, #0x20]
 *   @0xf9170 str lr, [sp, #0x24]
 *   @0xf9174 vmul.f32 s13, s15, s23
 *   @0xf9178 vmul.f32 s14, s22, s15
 *   @0xf917c vmov.f32 s15, s18
 *   @0xf9180 vmla.f32 s15, s13, s16
 *   @0xf9184 vmov.f32 s13, s15
 *   @0xf9188 vstr s13, [sp, #4]
 *   @0xf918c vmov.f32 s15, s19
 *   @0xf9190 vmls.f32 s15, s14, s16
 *   @0xf9194 vmov.f32 s14, s15
 *   @0xf9198 vstr s14, [sp, #8]
 *   @0xf919c vmov s14, r2
 *   @0xf91a0 vcvt.f32.s32 s15, s12
 *   @0xf91a4 vmov s12, r1
 *   @0xf91a8 vstr s15, [sp]
 *   @0xf91ac vmov s15, r3
 *   @0xf91b0 vcvt.f32.s32 s12, s12
 *   @0xf91b4 vcvt.f32.s32 s14, s14
 *   @0xf91b8 vmov r1, s12
 *   @0xf91bc vcvt.f32.s32 s15, s15
 *   @0xf91c0 vmov r2, s14
 *   @0xf91c4 vmov r3, s15
 *   @0xf91c8 bl 0x175a90 <_Z26GR_Texture_Draw_Part_ColorP12YYTPageEntryfffffffffjjjjf>
 *   @0xf91cc ldrsh r8, [r8, #10]
 *   @0xf91d0 vmov s15, r8
 *   @0xf91d4 vcvt.f32.s32 s15, s15
 *   @0xf91d8 vmul.f32 s13, s15, s23
 *   @0xf91dc vmul.f32 s14, s22, s15
 *   @0xf91e0 vmla.f32 s18, s13, s16
 *   @0xf91e4 vmls.f32 s19, s14, s16
 *   @0xf91e8 vadd.f32 s17, s17, s15
 *   @0xf91ec b 0xf9080 <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf+0x128>
 *   @0xf91f0 vcvt.f32.s32 s21, s25
 *   @0xf91f4 vdiv.f32 s24, s20, s21
 *   @0xf91f8 vmov r2, s24
 *   @0xf91fc bl 0x20ffb8 <_Z11Color_Mergejjf>
 *   @0xf9200 ldr r1, [sp, #0xa0]
 *   @0xf9204 mov r12, r0
 *   @0xf9208 ldrsh r0, [r8, #10]
 *   @0xf920c str r12, [sp, #0x30]
 *   @0xf9210 vmov s15, r0
 *   @0xf9214 mov r0, r11
 *   @0xf9218 vcvt.f32.s32 s15, s15
 *   @0xf921c vadd.f32 s15, s15, s20
 *   @0xf9220 vdiv.f32 s15, s15, s21
 *   @0xf9224 vmov r2, s15
 *   @0xf9228 bl 0x20ffb8 <_Z11Color_Mergejjf>
 *   @0xf922c ldrsh r3, [r8, #10]
 *   @0xf9230 ldr r1, [sp, #0xa4]
 *   @0xf9234 vmov s15, r3
 *   @0xf9238 vcvt.f32.s32 s15, s15
 *   @0xf923c vadd.f32 s15, s15, s20
 *   @0xf9240 vdiv.f32 s15, s15, s21
 *   @0xf9244 str r0, [sp, #0x34]
 *   @0xf9248 ldr r0, [sp, #0xa8]
 *   @0xf924c vmov r2, s15
 *   @0xf9250 bl 0x20ffb8 <_Z11Color_Mergejjf>
 *   @0xf9254 ldr r1, [sp, #0xa4]
 *   @0xf9258 vmov r2, s24
 *   @0xf925c mov r10, r0
 *   @0xf9260 ldr r0, [sp, #0xa8]
 *   @0xf9264 bl 0x20ffb8 <_Z11Color_Mergejjf>
 *   @0xf9268 ldrsh r3, [r8, #12]
 *   @0xf926c vmov.f32 s13, s18
 *   @0xf9270 vldr s12, [r9, #28]
 *   @0xf9274 ldrsh r1, [r8, #6]
 *   @0xf9278 mov r2, #0
 *   @0xf927c vmov s15, r3
 *   @0xf9280 ldr r12, [sp, #0x30]
 *   @0xf9284 mov r3, r2
 *   @0xf9288 vcvt.f32.s32 s15, s15
 *   @0xf928c vmov.f32 s14, s19
 *   @0xf9290 vmla.f32 s13, s15, s23
 *   @0xf9294 vmls.f32 s14, s22, s15
 *   @0xf9298 vcvt.f32.s32 s15, s12
 *   @0xf929c vstr s15, [sp]
 *   @0xf92a0 vldr s15, [r9, #32]
 *   @0xf92a4 vcvt.f32.s32 s15, s15
 *   @0xf92a8 str r0, [sp, #0x28]
 *   @0xf92ac ldr r0, [sp, #0x34]
 *   @0xf92b0 vstr s16, [sp, #16]
 *   @0xf92b4 str r12, [sp, #0x1c]
 *   @0xf92b8 vstr s26, [sp, #20]
 *   @0xf92bc str r10, [sp, #0x24]
 *   @0xf92c0 vstr s17, [sp, #24]
 *   @0xf92c4 str r0, [sp, #0x20]
 *   @0xf92c8 vstr s27, [sp, #44]
 *   @0xf92cc vstr s13, [sp, #8]
 *   @0xf92d0 vstr s14, [sp, #12]
 *   @0xf92d4 mov r0, r9
 *   @0xf92d8 vstr s15, [sp, #4]
 *   @0xf92dc bl 0x1e5fa8 <_ZN7CSprite11DrawGeneralEifffffffffjjjjf>
 *   @0xf92e0 ldrsh r8, [r8, #10]
 *   @0xf92e4 vmov s15, r8
 *   @0xf92e8 vcvt.f32.s32 s15, s15
 *   @0xf92ec vmla.f32 s18, s15, s23
 *   @0xf92f0 vmls.f32 s19, s22, s15
 *   @0xf92f4 vadd.f32 s20, s20, s15
 *   @0xf92f8 b 0xf9014 <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf+0xbc>
 *   @0xf92fc vstmialo lr, {s30, s31}
 *   @0xf9300 andeq r0, r0, r0
 *   @0xf9304 ldrsh r0, [r8, #12]
 *   @0xf9308 ldrsh r3, [r8, #8]
 *   @0xf930c ldrsh r1, [r8, #2]
 *   @0xf9310 vmov s15, r0
 *   @0xf9314 ldrsh r2, [r8, #4]
 *   @0xf9318 vmov s12, r3
 *   @0xf931c ldrsh r3, [r8, #6]
 *   @0xf9320 vcvt.f32.s32 s15, s15
 *   @0xf9324 vstr s16, [sp, #12]
 *   @0xf9328 vstr s26, [sp, #16]
 *   @0xf932c vstr s20, [sp, #20]
 *   @0xf9330 str r11, [sp, #0x18]
 *   @0xf9334 vstr s27, [sp, #40]
 *   @0xf9338 ldr r0, [r6, #0x38]
 *   @0xf933c str r10, [sp, #0x1c]
 *   @0xf9340 str r9, [sp, #0x20]
 *   @0xf9344 str lr, [sp, #0x24]
 *   @0xf9348 vmul.f32 s13, s15, s23
 *   @0xf934c vmul.f32 s14, s22, s15
 *   @0xf9350 vmov.f32 s15, s18
 *   @0xf9354 vmla.f32 s15, s13, s16
 *   @0xf9358 vmov.f32 s13, s15
 *   @0xf935c vstr s13, [sp, #4]
 *   @0xf9360 vmov.f32 s15, s19
 *   @0xf9364 vmls.f32 s15, s14, s16
 *   @0xf9368 vmov.f32 s14, s15
 *   @0xf936c vstr s14, [sp, #8]
 *   @0xf9370 vmov s14, r2
 *   @0xf9374 vcvt.f32.s32 s15, s12
 *   @0xf9378 vmov s12, r1
 *   @0xf937c vstr s15, [sp]
 *   @0xf9380 vmov s15, r3
 *   @0xf9384 vcvt.f32.s32 s12, s12
 *   @0xf9388 vcvt.f32.s32 s14, s14
 *   @0xf938c vmov r1, s12
 *   @0xf9390 vcvt.f32.s32 s15, s15
 *   @0xf9394 vmov r2, s14
 *   @0xf9398 vmov r3, s15
 *   @0xf939c bl 0x175834 <_Z26GR_Texture_Draw_Part_Colorifffffffffjjjjf>
 *   @0xf93a0 b 0xf91cc <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf+0x274>
 *
 * ══ §10/28 YYGML_CallExtensionFunction(CInstance*, CInstance*, YYRValue&, int, int, YYRValue**)  0xe9790  size 1096  274 条（0xe9790..0xe9bd8）
 * @func 0xe9790 0xe9bd8  size 1096  274 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×6 / UNLOCK_RVALUE_MUTEX()×6 / YYFree(void const*)×6 / operator delete(void*)×6 / FREE_RValue__Pre(RValue*)×2 / 0xb65b0 / YYGML_CallExtensionFunction(CInstance*, CInstance*, YYRValue&, int, int, YYRValue**)+0x12c / YYGML_CallExtensionFunction(CInstance*, CInstance*, YYRValue&, int, int, YYRValue**)+0x2a8
 * 字段偏移 top8: 0x4×14 / 0x8×12 / 0x-3c×12 / 0xc×7 / 0x-c×7 / 0x-30×5 / 0x-38×4 / 0x-34×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xe9790 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xe9794 add r11, sp, #32
 *   @0xe9798 ldr r0, [pc, #0x42c]
 *   @0xe979c sub sp, sp, #28
 *   @0xe97a0 mov r7, r3
 *   @0xe97a4 ldr r0, [pc, r0]
 *   @0xe97a8 lsl r3, r3, #4
 *   @0xe97ac str r2, [r11, #-0x38]
 *   @0xe97b0 add r2, r3, #8
 *   @0xe97b4 sub sp, sp, r2
 *   @0xe97b8 mov r2, r3
 *   @0xe97bc ldr r3, [r0]
 *   @0xe97c0 mov r1, #0
 *   @0xe97c4 str r0, [r11, #-0x34]
 *   @0xe97c8 mov r0, sp
 *   @0xe97cc str sp, [r11, #-0x30]
 *   @0xe97d0 ldr r4, [r11, #0x8]
 *   @0xe97d4 str r3, [r11, #-0x28]
 *   @0xe97d8 bl 0xb65b0 <memset@plt>
 *   @0xe97dc cmp r7, #0
 *   @0xe97e0 ble 0xe98bc <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x12c>
 *   @0xe97e4 ldr r2, [r11, #-0x30]
 *   @0xe97e8 sub r8, r4, #4
 *   @0xe97ec mov r10, #0
 *   @0xe97f0 add r9, r2, #12
 *   @0xe97f4 mov r6, r2
 *   @0xe97f8 ldr r2, [r6, #0xc]
 *   @0xe97fc ldr r4, [r8, #0x4]!
 *   @0xe9800 bic r3, r2, #-16777216
 *   @0xe9804 cmp r3, #1
 *   @0xe9808 beq 0xe99c4 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x234>
 *   @0xe980c cmp r3, #2
 *   @0xe9810 bne 0xe9838 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0xa8>
 *   @0xe9814 sub r2, r2, #1
 *   @0xe9818 bic r2, r2, #-16777216
 *   @0xe981c bic r2, r2, #3
 *   @0xe9820 cmp r2, #0
 *   @0xe9824 beq 0xe9a58 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x2c8>
 *   @0xe9828 mov r0, #0
 *   @0xe982c mov r1, #5
 *   @0xe9830 str r0, [r6, #0x8]
 *   @0xe9834 str r1, [r6, #0xc]
 *   @0xe9838 mov r2, #0
 *   @0xe983c str r2, [r9, #-0xc]
 *   @0xe9840 ldr r3, [r4, #0xc]
 *   @0xe9844 str r3, [r6, #0xc]
 *   @0xe9848 ldr r3, [r4, #0x8]
 *   @0xe984c str r3, [r6, #0x8]
 *   @0xe9850 ldr r3, [r4, #0xc]
 *   @0xe9854 bic r3, r3, #-16777216
 *   @0xe9858 cmp r3, #14
 *   @0xe985c addls pc, pc, r3, lsl #2
 *   @0xe9860 b 0xe98a8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x118>
 *   @0xe9864 b 0xe9984 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x1f4>
 *   @0xe9868 b 0xe996c <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x1dc>
 *   @0xe986c b 0xe9940 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x1b0>
 *   @0xe9870 b 0xe98a0 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x110>
 *   @0xe9874 b 0xe98a8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x118>
 *   @0xe9878 b 0xe98a8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x118>
 *   @0xe987c b 0xe99a0 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x210>
 *   @0xe9880 b 0xe98a0 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x110>
 *   @0xe9884 b 0xe98a8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x118>
 *   @0xe9888 b 0xe98a8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x118>
 *   @0xe988c b 0xe9990 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x200>
 *   @0xe9890 b 0xe98a8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x118>
 *   @0xe9894 b 0xe98a8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x118>
 *   @0xe9898 b 0xe9984 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x1f4>
 *   @0xe989c b 0xe98a0 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x110>
 *   @0xe98a0 ldr r3, [r4]
 *   @0xe98a4 str r3, [r9, #-0xc]
 *   @0xe98a8 add r10, r10, #1
 *   @0xe98ac add r9, r9, #16
 *   @0xe98b0 cmp r10, r7
 *   @0xe98b4 add r6, r6, #16
 *   @0xe98b8 bne 0xe97f8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x68>
 *   @0xe98bc ldr r3, [pc, #0x30c]
 *   @0xe98c0 ldr r1, [r11, #0x4]
 *   @0xe98c4 ldr r3, [pc, r3]
 *   @0xe98c8 sub r0, r1, #499712
 *   @0xe98cc ldr r3, [r3]
 *   @0xe98d0 sub r0, r0, #288
 *   @0xe98d4 ldr r3, [r3, r0, lsl #2]
 *   @0xe98d8 cmp r3, #0
 *   @0xe98dc beq 0xe9aa4 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x314>
 *   @0xe98e0 cmp r3, #2
 *   @0xe98e4 beq 0xe9b08 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x378>
 *   @0xe98e8 cmp r7, #0
 *   @0xe98ec ble 0xe9a38 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x2a8>
 *   @0xe98f0 mov r4, #0
 *   @0xe98f4 ldr r9, [r11, #-0x30]
 *   @0xe98f8 mov r5, r4
 *   @0xe98fc mov r6, #5
 *   @0xe9900 b 0xe991c <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x18c>
 *   @0xe9904 add r4, r4, #1
 *   @0xe9908 str r5, [r9, #0x8]
 *   @0xe990c cmp r4, r7
 *   @0xe9910 str r6, [r9, #0xc]
 *   @0xe9914 str r5, [r9], #16
 *   @0xe9918 beq 0xe9a38 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x2a8>
 *   @0xe991c ldr r3, [r9, #0xc]
 *   @0xe9920 sub r3, r3, #1
 *   @0xe9924 bic r3, r3, #-16777216
 *   @0xe9928 bic r3, r3, #3
 *   @0xe992c cmp r3, #0
 *   @0xe9930 bne 0xe9904 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x174>
 *   @0xe9934 mov r0, r9
 *   @0xe9938 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xe993c b 0xe9904 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x174>
 *   @0xe9940 ldr r3, [r4]
 *   @0xe9944 cmp r3, #0
 *   @0xe9948 str r3, [r9, #-0xc]
 *   @0xe994c beq 0xe98a8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x118>
 *   @0xe9950 ldr r1, [r3, #0x8]
 *   @0xe9954 ldr r2, [r3]
 *   @0xe9958 cmp r1, #0
 *   @0xe995c streq r6, [r3, #0x8]
 *   @0xe9960 add r2, r2, #1
 *   @0xe9964 str r2, [r3]
 *   @0xe9968 b 0xe98a8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x118>
 *   @0xe996c ldr r3, [r4]
 *   @0xe9970 cmp r3, #0
 *   @0xe9974 ldrne r2, [r3, #0x4]
 *   @0xe9978 addne r2, r2, #1
 *   @0xe997c strne r2, [r3, #0x4]
 *   @0xe9980 b 0xe98a4 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x114>
 *   @0xe9984 ldm r4, {r2, r3}
 *   @0xe9988 strd r2, r3, [r9, #-12]
 *   @0xe998c b 0xe98a8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x118>
 *   @0xe9990 ldm r4, {r2, r3}
 *   @0xe9994 str r2, [r9, #-0xc]
 *   @0xe9998 str r3, [r9, #-0x8]
 *   @0xe999c b 0xe98a8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x118>
 *   @0xe99a0 ldr r3, [r4]
 *   @0xe99a4 str r3, [r9, #-0xc]
 *   @0xe99a8 ldr r3, [r4]
 *   @0xe99ac cmp r3, #0
 *   @0xe99b0 beq 0xe98a8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x118>
 *   @0xe99b4 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0xe99b8 ldr r1, [r4]
 *   @0xe99bc bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0xe99c0 b 0xe98a8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x118>
 *   @0xe99c4 ldr r5, [r9, #-0xc]
 *   @0xe99c8 cmp r5, #0
 *   @0xe99cc beq 0xe99ec <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x25c>
 *   @0xe99d0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xe99d4 ldr r3, [r5, #0x4]
 *   @0xe99d8 sub r3, r3, #1
 *   @0xe99dc str r3, [r5, #0x4]
 *   @0xe99e0 cmp r3, #0
 *   @0xe99e4 beq 0xe99f8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x268>
 *   @0xe99e8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xe99ec mov r3, #0
 *   @0xe99f0 str r3, [r9, #-0xc]
 *   @0xe99f4 b 0xe9838 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0xa8>
 *   @0xe99f8 ldr r0, [r5]
 *   @0xe99fc str r3, [r11, #-0x3c]
 *   @0xe9a00 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xe9a04 ldr r3, [r11, #-0x3c]
 *   @0xe9a08 str r3, [r5]
 *   @0xe9a0c str r3, [r5, #0x8]
 *   @0xe9a10 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xe9a14 ldr r3, [r5, #0x4]
 *   @0xe9a18 sub r3, r3, #1
 *   @0xe9a1c str r3, [r5, #0x4]
 *   @0xe9a20 cmp r3, #0
 *   @0xe9a24 beq 0xe9a64 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x2d4>
 *   @0xe9a28 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xe9a2c mov r0, r5
 *   @0xe9a30 bl 0x27d1d0 <_ZdlPv>
 *   @0xe9a34 b 0xe99e8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x258>
 *   @0xe9a38 ldr r1, [r11, #-0x34]
 *   @0xe9a3c ldr r2, [r11, #-0x28]
 *   @0xe9a40 ldr r0, [r11, #-0x38]
 *   @0xe9a44 ldr r3, [r1]
 *   @0xe9a48 cmp r2, r3
 *   @0xe9a4c bne 0xe9bc8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x438>
 *   @0xe9a50 sub sp, r11, #32
 *   @0xe9a54 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xe9a58 mov r0, r6
 *   @0xe9a5c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xe9a60 b 0xe9828 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x98>
 *   @0xe9a64 ldr r0, [r5]
 *   @0xe9a68 str r3, [r11, #-0x3c]
 *   @0xe9a6c bl 0xcef90 <_Z6YYFreePKv>
 *   @0xe9a70 ldr r3, [r11, #-0x3c]
 *   @0xe9a74 str r3, [r5]
 *   @0xe9a78 str r3, [r5, #0x8]
 *   @0xe9a7c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xe9a80 ldr r3, [r5, #0x4]
 *   @0xe9a84 sub r3, r3, #1
 *   @0xe9a88 str r3, [r5, #0x4]
 *   @0xe9a8c cmp r3, #0
 *   @0xe9a90 beq 0xe9ac8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x338>
 *   @0xe9a94 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xe9a98 mov r0, r5
 *   @0xe9a9c bl 0x27d1d0 <_ZdlPv>
 *   @0xe9aa0 b 0xe9a28 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x298>
 *   @0xe9aa4 ldr r12, [pc, #0x128]
 *   @0xe9aa8 mov r1, r7
 *   @0xe9aac ldr r2, [r11, #-0x30]
 *   @0xe9ab0 ldr r12, [pc, r12]
 *   @0xe9ab4 ldr r3, [r11, #-0x38]
 *   @0xe9ab8 ldr r12, [r12]
 *   @0xe9abc ldr r0, [r12, r0, lsl #2]
 *   @0xe9ac0 bl 0x212b10 <_Z8DLL_CalliiP6RValueS0_>
 *   @0xe9ac4 b 0xe98e8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x158>
 *   @0xe9ac8 ldr r0, [r5]
 *   @0xe9acc str r3, [r11, #-0x3c]
 *   @0xe9ad0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xe9ad4 ldr r3, [r11, #-0x3c]
 *   @0xe9ad8 str r3, [r5]
 *   @0xe9adc str r3, [r5, #0x8]
 *   @0xe9ae0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xe9ae4 ldr r3, [r5, #0x4]
 *   @0xe9ae8 sub r3, r3, #1
 *   @0xe9aec str r3, [r5, #0x4]
 *   @0xe9af0 cmp r3, #0
 *   @0xe9af4 beq 0xe9b1c <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x38c>
 *   @0xe9af8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xe9afc mov r0, r5
 *   @0xe9b00 bl 0x27d1d0 <_ZdlPv>
 *   @0xe9b04 b 0xe9a94 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x304>
 *   @0xe9b08 mov r1, r7
 *   @0xe9b0c ldr r2, [r11, #-0x30]
 *   @0xe9b10 ldr r3, [r11, #-0x38]
 *   @0xe9b14 bl 0x214a18 <_Z8Ext_CalliiP6RValueS0_>
 *   @0xe9b18 b 0xe98e8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x158>
 *   @0xe9b1c ldr r0, [r5]
 *   @0xe9b20 str r3, [r11, #-0x3c]
 *   @0xe9b24 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xe9b28 ldr r3, [r11, #-0x3c]
 *   @0xe9b2c str r3, [r5]
 *   @0xe9b30 str r3, [r5, #0x8]
 *   @0xe9b34 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xe9b38 ldr r3, [r5, #0x4]
 *   @0xe9b3c sub r3, r3, #1
 *   @0xe9b40 str r3, [r5, #0x4]
 *   @0xe9b44 cmp r3, #0
 *   @0xe9b48 beq 0xe9b5c <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x3cc>
 *   @0xe9b4c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xe9b50 mov r0, r5
 *   @0xe9b54 bl 0x27d1d0 <_ZdlPv>
 *   @0xe9b58 b 0xe9af8 <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x368>
 *   @0xe9b5c ldr r0, [r5]
 *   @0xe9b60 str r3, [r11, #-0x3c]
 *   @0xe9b64 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xe9b68 ldr r3, [r11, #-0x3c]
 *   @0xe9b6c str r3, [r5]
 *   @0xe9b70 str r3, [r5, #0x8]
 *   @0xe9b74 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xe9b78 ldr r3, [r5, #0x4]
 *   @0xe9b7c sub r3, r3, #1
 *   @0xe9b80 str r3, [r5, #0x4]
 *   @0xe9b84 cmp r3, #0
 *   @0xe9b88 beq 0xe9b9c <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x40c>
 *   @0xe9b8c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xe9b90 mov r0, r5
 *   @0xe9b94 bl 0x27d1d0 <_ZdlPv>
 *   @0xe9b98 b 0xe9b4c <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x3bc>
 *   @0xe9b9c ldr r0, [r5]
 *   @0xe9ba0 str r3, [r11, #-0x3c]
 *   @0xe9ba4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xe9ba8 ldr r3, [r11, #-0x3c]
 *   @0xe9bac mov r0, r5
 *   @0xe9bb0 str r3, [r5]
 *   @0xe9bb4 str r3, [r5, #0x8]
 *   @0xe9bb8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0xe9bbc mov r0, r5
 *   @0xe9bc0 bl 0x27d1d0 <_ZdlPv>
 *   @0xe9bc4 b 0xe9b8c <_Z27YYGML_CallExtensionFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x3fc>
 *   @0xe9bc8 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0xe9bcc eorseq r4, r0, r12, lsr #3
 *   @0xe9bd0 mlaseq r0, r4, r4, r4
 *   @0xe9bd4 eorseq r4, r0, r12, lsr #5
 *
 * ══ §11/28 CSprite::SetupBitmapTexture(SWF_Bitmap*, int, int, int, int, int, int, unsigned char*, unsigned char*, unsigned char*, unsigned char*, unsigned int)  0x1e7e1c  size 1096  274 条（0x1e7e1c..0x1e8264）
 * @func 0x1e7e1c 0x1e8264  size 1096  274 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)×4 / ReadJPEGFile(void*, int, int*, int*, bool)×4 / 0xb65bc×2 / MemoryManager::Free(void const*)×2 / CSprite::SetupBitmapTexture(SWF_Bitmap*, int, int, int, int, int, int, unsigned char*, unsigned char*, unsigned char*, unsigned char*, unsigned int)+0x1b8×2 / CStream::GetSize()×2 / CStream::~CStream()×2 / GR_Texture_Create_And_Fill(int, int, unsigned char*, unsigned int)
 * 字段偏移 top8: 0x6c×9 / 0x18×7 / 0x1c×6 / 0x4×4 / 0x2×4 / 0x68×4 / 0x84×3 / 0x88×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e7e1c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1e7e20 subs r9, r1, #0
 *   @0x1e7e24 sub sp, sp, #68
 *   @0x1e7e28 mov r10, r3
 *   @0x1e7e2c ldr r4, [sp, #0x78]
 *   @0x1e7e30 ldr r5, [sp, #0x80]
 *   @0x1e7e34 beq 0x1e7f58 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x13c>
 *   @0x1e7e38 mov r3, #0
 *   @0x1e7e3c str r3, [sp, #0x18]
 *   @0x1e7e40 str r3, [sp, #0x1c]
 *   @0x1e7e44 cmp r2, #9
 *   @0x1e7e48 addls pc, pc, r2, lsl #2
 *   @0x1e7e4c b 0x1e7f58 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x13c>
 *   @0x1e7e50 b 0x1e7e78 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x5c>
 *   @0x1e7e54 b 0x1e7fe4 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x1c8>
 *   @0x1e7e58 b 0x1e8008 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x1ec>
 *   @0x1e7e5c b 0x1e8118 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x2fc>
 *   @0x1e7e60 b 0x1e813c <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x320>
 *   @0x1e7e64 b 0x1e8160 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x344>
 *   @0x1e7e68 b 0x1e7f60 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x144>
 *   @0x1e7e6c b 0x1e7f60 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x144>
 *   @0x1e7e70 b 0x1e8160 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x344>
 *   @0x1e7e74 b 0x1e7f60 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x144>
 *   @0x1e7e78 ldr r2, [sp, #0x84]
 *   @0x1e7e7c cmp r2, #0
 *   @0x1e7e80 beq 0x1e822c <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x410>
 *   @0x1e7e84 ldr r2, [sp, #0x6c]
 *   @0x1e7e88 ldr r3, [sp, #0x88]
 *   @0x1e7e8c ldr r1, [pc, #0x3bc]
 *   @0x1e7e90 add r6, r2, r3
 *   @0x1e7e94 mov r3, #1
 *   @0x1e7e98 add r1, pc, r1
 *   @0x1e7e9c movw r2, #0xec1
 *   @0x1e7ea0 mov r0, r6
 *   @0x1e7ea4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1e7ea8 ldr r1, [sp, #0x84]
 *   @0x1e7eac ldr r2, [sp, #0x88]
 *   @0x1e7eb0 mov r5, r0
 *   @0x1e7eb4 bl 0xb65bc <memcpy@plt>
 *   @0x1e7eb8 ldr r3, [sp, #0x88]
 *   @0x1e7ebc mov r1, r4
 *   @0x1e7ec0 ldr r2, [sp, #0x6c]
 *   @0x1e7ec4 add r0, r5, r3
 *   @0x1e7ec8 bl 0xb65bc <memcpy@plt>
 *   @0x1e7ecc mov r3, #0
 *   @0x1e7ed0 mov r0, r5
 *   @0x1e7ed4 str r3, [sp]
 *   @0x1e7ed8 mov r1, r6
 *   @0x1e7edc add r2, sp, #24
 *   @0x1e7ee0 add r3, sp, #28
 *   @0x1e7ee4 bl 0x18a728 <_Z12ReadJPEGFilePviPiS0_b>
 *   @0x1e7ee8 mov r11, r0
 *   @0x1e7eec cmp r11, #0
 *   @0x1e7ef0 beq 0x1e7f58 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x13c>
 *   @0x1e7ef4 ldr r3, [sp, #0x18]
 *   @0x1e7ef8 mov r2, r11
 *   @0x1e7efc ldr r1, [sp, #0x1c]
 *   @0x1e7f00 mov r0, r3
 *   @0x1e7f04 mul r3, r1, r3
 *   @0x1e7f08 lsl r3, r3, #2
 *   @0x1e7f0c bl 0x173c18 <_Z26GR_Texture_Create_And_FilliiPhj>
 *   @0x1e7f10 str r0, [r9, #0x8]
 *   @0x1e7f14 bl 0x173e2c <_Z17GR_Texture_Existsi>
 *   @0x1e7f18 cmp r0, #0
 *   @0x1e7f1c beq 0x1e7f40 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x124>
 *   @0x1e7f20 ldr r3, [pc, #0x32c]
 *   @0x1e7f24 ldr r2, [r9, #0x8]
 *   @0x1e7f28 ldr r3, [pc, r3]
 *   @0x1e7f2c ldr r3, [r3, #0x4]
 *   @0x1e7f30 ldr r3, [r3, r2, lsl #2]
 *   @0x1e7f34 cmp r3, #0
 *   @0x1e7f38 ldrne r3, [r3]
 *   @0x1e7f3c strne r3, [r9, #0xc]
 *   @0x1e7f40 ldr r2, [sp, #0x18]
 *   @0x1e7f44 mov r0, r11
 *   @0x1e7f48 ldr r3, [sp, #0x1c]
 *   @0x1e7f4c str r2, [r9, #0x14]
 *   @0x1e7f50 str r3, [r9, #0x18]
 *   @0x1e7f54 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e7f58 add sp, sp, #68
 *   @0x1e7f5c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e7f60 ldr r1, [pc, #0x2f0]
 *   @0x1e7f64 movw r2, #0xf2a
 *   @0x1e7f68 mov r3, #1
 *   @0x1e7f6c ldr r0, [sp, #0x6c]
 *   @0x1e7f70 add r1, pc, r1
 *   @0x1e7f74 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1e7f78 ldr r2, [sp, #0x6c]
 *   @0x1e7f7c cmp r2, #0
 *   @0x1e7f80 add r5, r2, #3
 *   @0x1e7f84 movge r5, r2
 *   @0x1e7f88 asr r5, r5, #2
 *   @0x1e7f8c cmp r5, #0
 *   @0x1e7f90 movgt r3, #0
 *   @0x1e7f94 mov r11, r0
 *   @0x1e7f98 movgt r2, r0
 *   @0x1e7f9c ble 0x1e7fd4 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x1b8>
 *   @0x1e7fa0 ldrb r1, [r4, #0x2]
 *   @0x1e7fa4 add r3, r3, #1
 *   @0x1e7fa8 ldrb r6, [r4, #0x3]
 *   @0x1e7fac cmp r3, r5
 *   @0x1e7fb0 ldrb r12, [r4]
 *   @0x1e7fb4 add r4, r4, #4
 *   @0x1e7fb8 ldrb r0, [r4, #-0x3]
 *   @0x1e7fbc lsl r1, r1, #16
 *   @0x1e7fc0 orr r1, r1, r6, lsl #24
 *   @0x1e7fc4 orr r1, r1, r12
 *   @0x1e7fc8 orr r1, r1, r0, lsl #8
 *   @0x1e7fcc str r1, [r2], #4
 *   @0x1e7fd0 bne 0x1e7fa0 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x184>
 *   @0x1e7fd4 ldr r3, [sp, #0x68]
 *   @0x1e7fd8 str r10, [sp, #0x18]
 *   @0x1e7fdc str r3, [sp, #0x1c]
 *   @0x1e7fe0 b 0x1e7eec <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0xd0>
 *   @0x1e7fe4 mov r3, #0
 *   @0x1e7fe8 mov r0, r4
 *   @0x1e7fec str r3, [sp]
 *   @0x1e7ff0 add r2, sp, #24
 *   @0x1e7ff4 ldr r1, [sp, #0x6c]
 *   @0x1e7ff8 add r3, sp, #28
 *   @0x1e7ffc bl 0x18a728 <_Z12ReadJPEGFilePviPiS0_b>
 *   @0x1e8000 mov r11, r0
 *   @0x1e8004 b 0x1e7eec <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0xd0>
 *   @0x1e8008 add r3, sp, #28
 *   @0x1e800c add r2, sp, #24
 *   @0x1e8010 mov r0, r4
 *   @0x1e8014 ldr r1, [sp, #0x6c]
 *   @0x1e8018 mov r4, #0
 *   @0x1e801c str r4, [sp]
 *   @0x1e8020 bl 0x18a728 <_Z12ReadJPEGFilePviPiS0_b>
 *   @0x1e8024 add r5, sp, #32
 *   @0x1e8028 ldr r1, [sp, #0x70]
 *   @0x1e802c mov r11, r0
 *   @0x1e8030 mov r0, r5
 *   @0x1e8034 bl 0x2010ec <_ZN7CStreamC2Ei>
 *   @0x1e8038 mov r0, r5
 *   @0x1e803c ldr r1, [sp, #0x70]
 *   @0x1e8040 bl 0x201a10 <_ZN7CStream12WriteIntegerEi>
 *   @0x1e8044 ldr r1, [sp, #0x7c]
 *   @0x1e8048 ldr r2, [sp, #0x70]
 *   @0x1e804c mov r0, r5
 *   @0x1e8050 bl 0x2014c8 <_ZN7CStream5WriteEPvi>
 *   @0x1e8054 mov r1, r4
 *   @0x1e8058 mov r2, r4
 *   @0x1e805c mov r0, r5
 *   @0x1e8060 bl 0x201284 <_ZN7CStream4SeekEis>
 *   @0x1e8064 mov r0, r5
 *   @0x1e8068 bl 0x201db0 <_ZN7CStream20ReadCompressedStreamEv>
 *   @0x1e806c mov r6, r0
 *   @0x1e8070 bl 0x201168 <_ZN7CStream7GetSizeEv>
 *   @0x1e8074 ldr r1, [pc, #0x1e0]
 *   @0x1e8078 movw r2, #0xee7
 *   @0x1e807c mov r3, #1
 *   @0x1e8080 add r1, pc, r1
 *   @0x1e8084 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1e8088 mov r4, r0
 *   @0x1e808c mov r0, r6
 *   @0x1e8090 bl 0x201168 <_ZN7CStream7GetSizeEv>
 *   @0x1e8094 mov r1, r4
 *   @0x1e8098 mov r2, r0
 *   @0x1e809c mov r0, r6
 *   @0x1e80a0 bl 0x2011e4 <_ZN7CStream10ReadBufferEPvi>
 *   @0x1e80a4 cmp r6, #0
 *   @0x1e80a8 beq 0x1e80bc <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x2a0>
 *   @0x1e80ac mov r0, r6
 *   @0x1e80b0 bl 0x201328 <_ZN7CStreamD2Ev>
 *   @0x1e80b4 mov r0, r6
 *   @0x1e80b8 bl 0x27d1d0 <_ZdlPv>
 *   @0x1e80bc ldr r2, [sp, #0x1c]
 *   @0x1e80c0 ldr r3, [sp, #0x18]
 *   @0x1e80c4 mul r3, r2, r3
 *   @0x1e80c8 cmp r3, #0
 *   @0x1e80cc movgt r2, r11
 *   @0x1e80d0 movgt r3, #0
 *   @0x1e80d4 ble 0x1e8104 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x2e8>
 *   @0x1e80d8 ldrb r0, [r4, r3]
 *   @0x1e80dc add r3, r3, #1
 *   @0x1e80e0 ldr r1, [r2]
 *   @0x1e80e4 bic r1, r1, #-16777216
 *   @0x1e80e8 orr r1, r1, r0, lsl #24
 *   @0x1e80ec str r1, [r2], #4
 *   @0x1e80f0 ldr r1, [sp, #0x18]
 *   @0x1e80f4 ldr r0, [sp, #0x1c]
 *   @0x1e80f8 mul r1, r0, r1
 *   @0x1e80fc cmp r1, r3
 *   @0x1e8100 bgt 0x1e80d8 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x2bc>
 *   @0x1e8104 mov r0, r4
 *   @0x1e8108 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e810c mov r0, r5
 *   @0x1e8110 bl 0x201328 <_ZN7CStreamD2Ev>
 *   @0x1e8114 b 0x1e7eec <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0xd0>
 *   @0x1e8118 mov r3, #0
 *   @0x1e811c mov r0, r4
 *   @0x1e8120 str r3, [sp]
 *   @0x1e8124 add r2, sp, #24
 *   @0x1e8128 ldr r1, [sp, #0x6c]
 *   @0x1e812c add r3, sp, #28
 *   @0x1e8130 bl 0x18a24c <_Z11ReadPNGFilePviPiS0_b>
 *   @0x1e8134 mov r11, r0
 *   @0x1e8138 b 0x1e7eec <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0xd0>
 *   @0x1e813c mov r3, #0
 *   @0x1e8140 mov r0, r4
 *   @0x1e8144 str r3, [sp]
 *   @0x1e8148 add r2, sp, #24
 *   @0x1e814c ldr r1, [sp, #0x6c]
 *   @0x1e8150 add r3, sp, #28
 *   @0x1e8154 bl 0x18a918 <_Z11ReadGIFFilePviPiS0_b>
 *   @0x1e8158 mov r11, r0
 *   @0x1e815c b 0x1e7eec <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0xd0>
 *   @0x1e8160 ldr r3, [sp, #0x68]
 *   @0x1e8164 movw r2, #0xf08
 *   @0x1e8168 ldr r1, [pc, #0xf0]
 *   @0x1e816c mul r0, r3, r10
 *   @0x1e8170 add r1, pc, r1
 *   @0x1e8174 mov r3, #1
 *   @0x1e8178 lsl r0, r0, #2
 *   @0x1e817c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1e8180 ldr r2, [sp, #0x68]
 *   @0x1e8184 add r3, r10, #3
 *   @0x1e8188 cmp r2, #0
 *   @0x1e818c bic r2, r3, #3
 *   @0x1e8190 mov r11, r0
 *   @0x1e8194 ble 0x1e7fd4 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x1b8>
 *   @0x1e8198 lsl r3, r10, #2
 *   @0x1e819c str r3, [sp, #0xc]
 *   @0x1e81a0 mov r3, r0
 *   @0x1e81a4 str r11, [sp, #0x10]
 *   @0x1e81a8 str r9, [sp, #0x14]
 *   @0x1e81ac mov r1, r4
 *   @0x1e81b0 mov r0, #0
 *   @0x1e81b4 mov r11, r2
 *   @0x1e81b8 mov r9, r3
 *   @0x1e81bc cmp r10, #0
 *   @0x1e81c0 ble 0x1e820c <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x3f0>
 *   @0x1e81c4 add r8, r1, r10
 *   @0x1e81c8 mov r2, r1
 *   @0x1e81cc mov r12, r9
 *   @0x1e81d0 ldrb r4, [r2], #1
 *   @0x1e81d4 cmp r2, r8
 *   @0x1e81d8 add r3, r5, r4, lsl #2
 *   @0x1e81dc ldrb r4, [r5, r4, lsl #2]
 *   @0x1e81e0 ldrb r7, [r3, #0x2]
 *   @0x1e81e4 ldrb r6, [r3, #0x3]
 *   @0x1e81e8 ldrb r3, [r3, #0x1]
 *   @0x1e81ec lsl r7, r7, #16
 *   @0x1e81f0 orr r6, r7, r6, lsl #24
 *   @0x1e81f4 orr r4, r6, r4
 *   @0x1e81f8 orr r3, r4, r3, lsl #8
 *   @0x1e81fc str r3, [r12], #4
 *   @0x1e8200 bne 0x1e81d0 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x3b4>
 *   @0x1e8204 ldr r2, [sp, #0xc]
 *   @0x1e8208 add r9, r9, r2
 *   @0x1e820c ldr r3, [sp, #0x68]
 *   @0x1e8210 add r0, r0, #1
 *   @0x1e8214 add r1, r1, r11
 *   @0x1e8218 cmp r0, r3
 *   @0x1e821c bne 0x1e81bc <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x3a0>
 *   @0x1e8220 ldr r11, [sp, #0x10]
 *   @0x1e8224 ldr r9, [sp, #0x14]
 *   @0x1e8228 b 0x1e7fd4 <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0x1b8>
 *   @0x1e822c ldr r2, [sp, #0x84]
 *   @0x1e8230 mov r0, r4
 *   @0x1e8234 ldr r1, [sp, #0x6c]
 *   @0x1e8238 add r3, sp, #28
 *   @0x1e823c str r2, [sp]
 *   @0x1e8240 add r2, sp, #24
 *   @0x1e8244 bl 0x18a728 <_Z12ReadJPEGFilePviPiS0_b>
 *   @0x1e8248 mov r11, r0
 *   @0x1e824c b 0x1e7eec <_ZN7CSprite18SetupBitmapTextureEP10SWF_BitmapiiiiiiPhS2_S2_S2_j+0xd0>
 *   @0x1e8250 andseq r10, r6, r12, lsl #11
 *   @0x1e8254 .word 0x002059f4
 *   @0x1e8258 ldrheq r10, [r6], -r4
 *   @0x1e825c andseq r10, r6, r4, lsr #7
 *   @0x1e8260 ldrheq r10, [r6], -r4
 *
 * ══ §12/28 TraverseObjects(Buffer_Standard*)  0x29e80c  size 1096  274 条（0x29e80c..0x29ec54）
 * @func 0x29e80c 0x29ec54  size 1096  274 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: WriteString(Buffer_Standard*, char const*)×2 / TraverseObjects(Buffer_Standard*)+0x318
 * 字段偏移 top8: 0x8×20 / 0x38×13 / 0x4×9 / 0xc×8 / 0x30×7 / 0x10×7 / 0x14×6 / 0x1c×4
 * VFP 指令 40 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29e80c ldr r12, [r0]
 *   @0x29e810 mov r3, #0
 *   @0x29e814 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x29e818 sub sp, sp, #36
 *   @0x29e81c str r3, [r0, #0x2c]
 *   @0x29e820 add r8, r0, #44
 *   @0x29e824 str r3, [r0, #0x30]
 *   @0x29e828 mov r1, #5
 *   @0x29e82c ldr r12, [r12, #0x8]
 *   @0x29e830 mov r2, r8
 *   @0x29e834 str r3, [sp, #0x14]
 *   @0x29e838 mov r6, r0
 *   @0x29e83c str r3, [r0, #0x38]
 *   @0x29e840 ldr r3, [r0, #0x1c]
 *   @0x29e844 str r3, [sp, #0x1c]
 *   @0x29e848 blx r12
 *   @0x29e84c ldr r3, [pc, #0x3fc]
 *   @0x29e850 ldr r3, [pc, r3]
 *   @0x29e854 ldr r3, [r3]
 *   @0x29e858 str r3, [sp, #0x18]
 *   @0x29e85c mov r12, r3
 *   @0x29e860 ldr r2, [r3]
 *   @0x29e864 ldr r3, [sp, #0x14]
 *   @0x29e868 b 0x29e87c <_Z15TraverseObjectsP15Buffer_Standard+0x70>
 *   @0x29e86c ldr r0, [r12, #0x4]
 *   @0x29e870 add r3, r3, #1
 *   @0x29e874 cmp r3, r0
 *   @0x29e878 bgt 0x29ec44 <_Z15TraverseObjectsP15Buffer_Standard+0x438>
 *   @0x29e87c ldr r1, [r2, r3, lsl #3]
 *   @0x29e880 cmp r1, #0
 *   @0x29e884 beq 0x29e86c <_Z15TraverseObjectsP15Buffer_Standard+0x60>
 *   @0x29e888 ldr r4, [r1, #0xc]
 *   @0x29e88c str r1, [sp, #0x8]
 *   @0x29e890 cmp r4, #0
 *   @0x29e894 str r3, [sp, #0x14]
 *   @0x29e898 streq r4, [sp, #0xc]
 *   @0x29e89c beq 0x29eb7c <_Z15TraverseObjectsP15Buffer_Standard+0x370>
 *   @0x29e8a0 mov r3, #0
 *   @0x29e8a4 str r3, [sp, #0xc]
 *   @0x29e8a8 mov r9, r3
 *   @0x29e8ac ldr r10, [r4, #0x18]
 *   @0x29e8b0 mov r1, #5
 *   @0x29e8b4 ldr r5, [r6]
 *   @0x29e8b8 mov r2, r8
 *   @0x29e8bc ldr r3, [sp, #0xc]
 *   @0x29e8c0 mov r0, r6
 *   @0x29e8c4 vmov s13, r10
 *   @0x29e8c8 str r9, [r6, #0x38]
 *   @0x29e8cc add r3, r3, #1
 *   @0x29e8d0 str r3, [sp, #0xc]
 *   @0x29e8d4 vcvt.f64.u32 d7, s13
 *   @0x29e8d8 mov r3, #15
 *   @0x29e8dc str r3, [sp, #0x10]
 *   @0x29e8e0 mov r10, r4
 *   @0x29e8e4 vstr s14, [r6, #44]
 *   @0x29e8e8 vstr s15, [r6, #48]
 *   @0x29e8ec ldr r12, [r5, #0x8]
 *   @0x29e8f0 blx r12
 *   @0x29e8f4 ldr r3, [r4]
 *   @0x29e8f8 ldr r5, [r6]
 *   @0x29e8fc mov r1, #5
 *   @0x29e900 mov r2, r8
 *   @0x29e904 str r9, [r6, #0x38]
 *   @0x29e908 vmov s13, r3
 *   @0x29e90c mov r0, r6
 *   @0x29e910 vcvt.f64.u32 d7, s13
 *   @0x29e914 vstr s14, [r6, #44]
 *   @0x29e918 vstr s15, [r6, #48]
 *   @0x29e91c ldr r12, [r5, #0x8]
 *   @0x29e920 blx r12
 *   @0x29e924 ldr r3, [r4, #0x4]
 *   @0x29e928 ldr r5, [r6]
 *   @0x29e92c mov r1, #5
 *   @0x29e930 mov r2, r8
 *   @0x29e934 str r9, [r6, #0x38]
 *   @0x29e938 vmov s13, r3
 *   @0x29e93c mov r0, r6
 *   @0x29e940 vcvt.f64.u32 d7, s13
 *   @0x29e944 vstr s14, [r6, #44]
 *   @0x29e948 vstr s15, [r6, #48]
 *   @0x29e94c ldr r12, [r5, #0x8]
 *   @0x29e950 blx r12
 *   @0x29e954 ldr r3, [r4, #0x10]
 *   @0x29e958 ldr r5, [r6]
 *   @0x29e95c mov r1, #5
 *   @0x29e960 mov r2, r8
 *   @0x29e964 str r9, [r6, #0x38]
 *   @0x29e968 vmov s13, r3
 *   @0x29e96c mov r0, r6
 *   @0x29e970 vcvt.f64.u32 d7, s13
 *   @0x29e974 vstr s14, [r6, #44]
 *   @0x29e978 vstr s15, [r6, #48]
 *   @0x29e97c ldr r12, [r5, #0x8]
 *   @0x29e980 blx r12
 *   @0x29e984 ldr r3, [r4, #0x8]
 *   @0x29e988 ldr r5, [r6]
 *   @0x29e98c mov r1, #5
 *   @0x29e990 mov r2, r8
 *   @0x29e994 str r9, [r6, #0x38]
 *   @0x29e998 vmov s13, r3
 *   @0x29e99c mov r0, r6
 *   @0x29e9a0 vcvt.f64.u32 d7, s13
 *   @0x29e9a4 vstr s14, [r6, #44]
 *   @0x29e9a8 vstr s15, [r6, #48]
 *   @0x29e9ac ldr r12, [r5, #0x8]
 *   @0x29e9b0 blx r12
 *   @0x29e9b4 ldr r3, [r4, #0xc]
 *   @0x29e9b8 ldr r5, [r6]
 *   @0x29e9bc mov r1, #5
 *   @0x29e9c0 str r9, [r6, #0x38]
 *   @0x29e9c4 mov r0, r6
 *   @0x29e9c8 vmov s13, r3
 *   @0x29e9cc mov r2, r8
 *   @0x29e9d0 vcvt.f64.u32 d7, s13
 *   @0x29e9d4 vstr s14, [r6, #44]
 *   @0x29e9d8 vstr s15, [r6, #48]
 *   @0x29e9dc ldr r12, [r5, #0x8]
 *   @0x29e9e0 blx r12
 *   @0x29e9e4 mov r0, r6
 *   @0x29e9e8 ldr r1, [r4, #0x14]
 *   @0x29e9ec bl 0x29e624 <_Z11WriteStringP15Buffer_StandardPKc>
 *   @0x29e9f0 ldr r3, [r10, #0x4c]
 *   @0x29e9f4 cmp r3, #0
 *   @0x29e9f8 str r3, [sp, #0x4]
 *   @0x29e9fc ble 0x29eb24 <_Z15TraverseObjectsP15Buffer_Standard+0x318>
 *   @0x29ea00 ldr lr, [sp, #0x4]
 *   @0x29ea04 mov r4, #0
 *   @0x29ea08 ldr r3, [r10, #0x50]
 *   @0x29ea0c add r1, r3, lr, lsl #2
 *   @0x29ea10 ldr r2, [r3], #4
 *   @0x29ea14 cmp r2, #0
 *   @0x29ea18 addne r4, r4, #1
 *   @0x29ea1c cmp r3, r1
 *   @0x29ea20 bne 0x29ea10 <_Z15TraverseObjectsP15Buffer_Standard+0x204>
 *   @0x29ea24 vmov s15, r4
 *   @0x29ea28 ldr r3, [r6]
 *   @0x29ea2c str r9, [r6, #0x38]
 *   @0x29ea30 mov r0, r6
 *   @0x29ea34 vcvt.f64.u32 d7, s15
 *   @0x29ea38 mov r1, #5
 *   @0x29ea3c mov r2, r8
 *   @0x29ea40 mov r11, #0
 *   @0x29ea44 vmov r4, r5, d7
 *   @0x29ea48 vstr s14, [r6, #44]
 *   @0x29ea4c str r5, [r6, #0x30]
 *   @0x29ea50 ldr r3, [r3, #0x8]
 *   @0x29ea54 blx r3
 *   @0x29ea58 ldr r3, [r10, #0x50]
 *   @0x29ea5c mov r1, #5
 *   @0x29ea60 mov r2, r8
 *   @0x29ea64 mov r0, r6
 *   @0x29ea68 ldr r3, [r3, r11, lsl #2]
 *   @0x29ea6c cmp r3, #0
 *   @0x29ea70 beq 0x29eb10 <_Z15TraverseObjectsP15Buffer_Standard+0x304>
 *   @0x29ea74 vmov s15, r11
 *   @0x29ea78 ldr r12, [r6]
 *   @0x29ea7c ldr r7, [r3, #0x4]
 *   @0x29ea80 vcvt.f64.s32 d7, s15
 *   @0x29ea84 str r9, [r6, #0x38]
 *   @0x29ea88 vmov r4, r5, d7
 *   @0x29ea8c vstr s14, [r6, #44]
 *   @0x29ea90 str r5, [r6, #0x30]
 *   @0x29ea94 ldr r3, [r12, #0x8]
 *   @0x29ea98 blx r3
 *   @0x29ea9c ldr r4, [r7, #0x60]
 *   @0x29eaa0 ldr r3, [r6]
 *   @0x29eaa4 mov r1, #5
 *   @0x29eaa8 mov r2, r8
 *   @0x29eaac mov r0, r6
 *   @0x29eab0 vmov s15, r4
 *   @0x29eab4 str r9, [r6, #0x38]
 *   @0x29eab8 vcvt.f64.u32 d7, s15
 *   @0x29eabc vmov r4, r5, d7
 *   @0x29eac0 vstr s14, [r6, #44]
 *   @0x29eac4 str r5, [r6, #0x30]
 *   @0x29eac8 ldr r3, [r3, #0x8]
 *   @0x29eacc blx r3
 *   @0x29ead0 ldr r3, [r7, #0x50]
 *   @0x29ead4 ldr r12, [r6]
 *   @0x29ead8 mov r1, #12
 *   @0x29eadc mov lr, #10
 *   @0x29eae0 mov r0, r6
 *   @0x29eae4 ldr r3, [r3, #0x10]
 *   @0x29eae8 mov r2, r8
 *   @0x29eaec str lr, [r6, #0x38]
 *   @0x29eaf0 asr r5, r3, #31
 *   @0x29eaf4 str r3, [r6, #0x2c]
 *   @0x29eaf8 str r5, [r6, #0x30]
 *   @0x29eafc ldr r3, [r12, #0x8]
 *   @0x29eb00 blx r3
 *   @0x29eb04 mov r0, r6
 *   @0x29eb08 ldr r1, [r7, #0x5c]
 *   @0x29eb0c bl 0x29e624 <_Z11WriteStringP15Buffer_StandardPKc>
 *   @0x29eb10 ldr r3, [sp, #0x4]
 *   @0x29eb14 add r11, r11, #1
 *   @0x29eb18 cmp r11, r3
 *   @0x29eb1c bne 0x29ea58 <_Z15TraverseObjectsP15Buffer_Standard+0x24c>
 *   @0x29eb20 b 0x29eb48 <_Z15TraverseObjectsP15Buffer_Standard+0x33c>
 *   @0x29eb24 ldr r3, [r6]
 *   @0x29eb28 mov r0, r6
 *   @0x29eb2c str r9, [r6, #0x2c]
 *   @0x29eb30 mov r1, #5
 *   @0x29eb34 str r9, [r6, #0x30]
 *   @0x29eb38 mov r2, r8
 *   @0x29eb3c str r9, [r6, #0x38]
 *   @0x29eb40 ldr r3, [r3, #0x8]
 *   @0x29eb44 blx r3
 *   @0x29eb48 ldr r3, [sp, #0x10]
 *   @0x29eb4c add r10, r10, #8
 *   @0x29eb50 subs r3, r3, #1
 *   @0x29eb54 str r3, [sp, #0x10]
 *   @0x29eb58 bne 0x29e9f0 <_Z15TraverseObjectsP15Buffer_Standard+0x1e4>
 *   @0x29eb5c ldr r3, [sp, #0x8]
 *   @0x29eb60 ldr r3, [r3, #0x4]
 *   @0x29eb64 cmp r3, #0
 *   @0x29eb68 str r3, [sp, #0x8]
 *   @0x29eb6c beq 0x29ebec <_Z15TraverseObjectsP15Buffer_Standard+0x3e0>
 *   @0x29eb70 ldr r4, [r3, #0xc]
 *   @0x29eb74 cmp r4, #0
 *   @0x29eb78 bne 0x29e8ac <_Z15TraverseObjectsP15Buffer_Standard+0xa0>
 *   @0x29eb7c ldr r3, [r6]
 *   @0x29eb80 mov r1, #0
 *   @0x29eb84 ldr r2, [sp, #0x1c]
 *   @0x29eb88 mov r0, r6
 *   @0x29eb8c mov r7, r1
 *   @0x29eb90 ldr r9, [r6, #0x1c]
 *   @0x29eb94 ldr r3, [r3, #0x10]
 *   @0x29eb98 blx r3
 *   @0x29eb9c vldr s15, [sp, #12]
 *   @0x29eba0 vcvt.f64.u32 d7, s15
 *   @0x29eba4 ldr r3, [r6]
 *   @0x29eba8 mov r2, r8
 *   @0x29ebac str r7, [r6, #0x38]
 *   @0x29ebb0 mov r0, r6
 *   @0x29ebb4 mov r1, #5
 *   @0x29ebb8 vmov r4, r5, d7
 *   @0x29ebbc vstr s14, [r6, #44]
 *   @0x29ebc0 str r5, [r6, #0x30]
 *   @0x29ebc4 ldr r3, [r3, #0x8]
 *   @0x29ebc8 blx r3
 *   @0x29ebcc ldr r3, [r6]
 *   @0x29ebd0 mov r1, r7
 *   @0x29ebd4 mov r2, r9
 *   @0x29ebd8 mov r0, r6
 *   @0x29ebdc ldr r3, [r3, #0x10]
 *   @0x29ebe0 blx r3
 *   @0x29ebe4 add sp, sp, #36
 *   @0x29ebe8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x29ebec ldr r3, [sp, #0x18]
 *   @0x29ebf0 ldr lr, [sp, #0x14]
 *   @0x29ebf4 ldr r1, [r3, #0x4]
 *   @0x29ebf8 add r3, lr, #1
 *   @0x29ebfc cmp r3, r1
 *   @0x29ec00 bgt 0x29eb7c <_Z15TraverseObjectsP15Buffer_Standard+0x370>
 *   @0x29ec04 ldr r0, [sp, #0x18]
 *   @0x29ec08 ldr r2, [r0]
 *   @0x29ec0c add r2, r2, lr, lsl #3
 *   @0x29ec10 b 0x29ec1c <_Z15TraverseObjectsP15Buffer_Standard+0x410>
 *   @0x29ec14 cmp r3, r1
 *   @0x29ec18 bgt 0x29eb7c <_Z15TraverseObjectsP15Buffer_Standard+0x370>
 *   @0x29ec1c ldr r0, [r2, #0x8]
 *   @0x29ec20 mov r12, r3
 *   @0x29ec24 add r2, r2, #8
 *   @0x29ec28 add r3, r3, #1
 *   @0x29ec2c cmp r0, #0
 *   @0x29ec30 beq 0x29ec14 <_Z15TraverseObjectsP15Buffer_Standard+0x408>
 *   @0x29ec34 str r0, [sp, #0x8]
 *   @0x29ec38 str r12, [sp, #0x14]
 *   @0x29ec3c ldr r4, [r0, #0xc]
 *   @0x29ec40 b 0x29eb74 <_Z15TraverseObjectsP15Buffer_Standard+0x368>
 *   @0x29ec44 str r1, [sp, #0x8]
 *   @0x29ec48 str r1, [sp, #0xc]
 *   @0x29ec4c b 0x29eb7c <_Z15TraverseObjectsP15Buffer_Standard+0x370>
 *   @0x29ec50 andseq pc, r4, r12, ror #7
 *
 * ══ §13/28 FacebookPostMessageM(char*, char*, char*, char*, char*, char*, char*)  0x15e8a0  size 1092  273 条（0x15e8a0..0x15ece4）
 * @func 0x15e8a0 0x15ece4  size 1092  273 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×30 / 0xb65c8 / _JNIEnv::CallStaticVoidMethod(_jclass*, _jmethodID*, ...) / 0xb65d4
 * 字段偏移 top8: 0x29c×15 / 0x2b8×12 / 0x14×4 / 0x18×3 / 0x1c×2 / 0x124×2 / 0x10×2 / 0x3fc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15e8a0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x15e8a4 sub sp, sp, #300
 *   @0x15e8a8 ldr r5, [pc, #0x3fc]
 *   @0x15e8ac mov r7, r3
 *   @0x15e8b0 ldr r6, [sp, #0x154]
 *   @0x15e8b4 mov r9, r1
 *   @0x15e8b8 ldr r5, [pc, r5]
 *   @0x15e8bc mov r8, r2
 *   @0x15e8c0 ldr r1, [sp, #0x158]
 *   @0x15e8c4 mov r11, r0
 *   @0x15e8c8 ldrb r3, [r6]
 *   @0x15e8cc ldr r2, [r5]
 *   @0x15e8d0 cmp r3, #0
 *   @0x15e8d4 ldr r10, [sp, #0x150]
 *   @0x15e8d8 str r1, [sp, #0x1c]
 *   @0x15e8dc str r2, [sp, #0x124]
 *   @0x15e8e0 moveq r12, #10
 *   @0x15e8e4 streq r3, [sp, #0x18]
 *   @0x15e8e8 beq 0x15e908 <_Z20FacebookPostMessageMPcS_S_S_S_S_S_+0x68>
 *   @0x15e8ec ldrb r3, [r1]
 *   @0x15e8f0 cmp r3, #0
 *   @0x15e8f4 movne r12, #12
 *   @0x15e8f8 moveq r12, #10
 *   @0x15e8fc moveq r2, #0
 *   @0x15e900 movne r2, #1
 *   @0x15e904 str r2, [sp, #0x18]
 *   @0x15e908 str r12, [sp, #0x10]
 *   @0x15e90c bl 0x290274 <getJNIEnv>
 *   @0x15e910 mov r4, r0
 *   @0x15e914 bl 0x290274 <getJNIEnv>
 *   @0x15e918 ldr r1, [pc, #0x390]
 *   @0x15e91c add r1, pc, r1
 *   @0x15e920 ldr r3, [r0]
 *   @0x15e924 ldr r3, [r3, #0x18]
 *   @0x15e928 blx r3
 *   @0x15e92c str r0, [sp, #0x14]
 *   @0x15e930 bl 0x290274 <getJNIEnv>
 *   @0x15e934 ldr r1, [pc, #0x378]
 *   @0x15e938 add r1, pc, r1
 *   @0x15e93c ldr r3, [r0]
 *   @0x15e940 ldr r3, [r3, #0x29c]
 *   @0x15e944 blx r3
 *   @0x15e948 ldr lr, [r4]
 *   @0x15e94c ldr r12, [sp, #0x10]
 *   @0x15e950 ldr r2, [sp, #0x14]
 *   @0x15e954 mov r1, r12
 *   @0x15e958 ldr r12, [lr, #0x2b0]
 *   @0x15e95c mov r3, r0
 *   @0x15e960 mov r0, r4
 *   @0x15e964 blx r12
 *   @0x15e968 mov r4, r0
 *   @0x15e96c bl 0x290274 <getJNIEnv>
 *   @0x15e970 ldr r1, [pc, #0x340]
 *   @0x15e974 add r1, pc, r1
 *   @0x15e978 ldr r3, [r0]
 *   @0x15e97c ldr r3, [r3, #0x29c]
 *   @0x15e980 blx r3
 *   @0x15e984 str r0, [sp, #0x14]
 *   @0x15e988 bl 0x290274 <getJNIEnv>
 *   @0x15e98c mov r2, #0
 *   @0x15e990 ldr r3, [sp, #0x14]
 *   @0x15e994 mov r1, r4
 *   @0x15e998 ldr r12, [r0]
 *   @0x15e99c ldr r12, [r12, #0x2b8]
 *   @0x15e9a0 blx r12
 *   @0x15e9a4 bl 0x290274 <getJNIEnv>
 *   @0x15e9a8 mov r1, r11
 *   @0x15e9ac ldr r3, [r0]
 *   @0x15e9b0 ldr r3, [r3, #0x29c]
 *   @0x15e9b4 blx r3
 *   @0x15e9b8 mov r11, r0
 *   @0x15e9bc bl 0x290274 <getJNIEnv>
 *   @0x15e9c0 mov r2, #1
 *   @0x15e9c4 mov r3, r11
 *   @0x15e9c8 mov r1, r4
 *   @0x15e9cc ldr r12, [r0]
 *   @0x15e9d0 ldr r12, [r12, #0x2b8]
 *   @0x15e9d4 blx r12
 *   @0x15e9d8 bl 0x290274 <getJNIEnv>
 *   @0x15e9dc ldr r1, [pc, #0x2d8]
 *   @0x15e9e0 add r1, pc, r1
 *   @0x15e9e4 ldr r3, [r0]
 *   @0x15e9e8 ldr r3, [r3, #0x29c]
 *   @0x15e9ec blx r3
 *   @0x15e9f0 mov r11, r0
 *   @0x15e9f4 bl 0x290274 <getJNIEnv>
 *   @0x15e9f8 mov r2, #2
 *   @0x15e9fc mov r3, r11
 *   @0x15ea00 mov r1, r4
 *   @0x15ea04 ldr r12, [r0]
 *   @0x15ea08 ldr r12, [r12, #0x2b8]
 *   @0x15ea0c blx r12
 *   @0x15ea10 bl 0x290274 <getJNIEnv>
 *   @0x15ea14 mov r1, r10
 *   @0x15ea18 ldr r3, [r0]
 *   @0x15ea1c ldr r3, [r3, #0x29c]
 *   @0x15ea20 blx r3
 *   @0x15ea24 mov r10, r0
 *   @0x15ea28 bl 0x290274 <getJNIEnv>
 *   @0x15ea2c mov r2, #3
 *   @0x15ea30 mov r3, r10
 *   @0x15ea34 mov r1, r4
 *   @0x15ea38 ldr r12, [r0]
 *   @0x15ea3c ldr r12, [r12, #0x2b8]
 *   @0x15ea40 blx r12
 *   @0x15ea44 bl 0x290274 <getJNIEnv>
 *   @0x15ea48 ldr r1, [pc, #0x270]
 *   @0x15ea4c add r1, pc, r1
 *   @0x15ea50 ldr r3, [r0]
 *   @0x15ea54 ldr r3, [r3, #0x29c]
 *   @0x15ea58 blx r3
 *   @0x15ea5c mov r10, r0
 *   @0x15ea60 bl 0x290274 <getJNIEnv>
 *   @0x15ea64 mov r2, #4
 *   @0x15ea68 mov r3, r10
 *   @0x15ea6c mov r1, r4
 *   @0x15ea70 ldr r12, [r0]
 *   @0x15ea74 ldr r12, [r12, #0x2b8]
 *   @0x15ea78 blx r12
 *   @0x15ea7c bl 0x290274 <getJNIEnv>
 *   @0x15ea80 mov r1, r9
 *   @0x15ea84 ldr r3, [r0]
 *   @0x15ea88 ldr r3, [r3, #0x29c]
 *   @0x15ea8c blx r3
 *   @0x15ea90 mov r9, r0
 *   @0x15ea94 bl 0x290274 <getJNIEnv>
 *   @0x15ea98 mov r2, #5
 *   @0x15ea9c mov r3, r9
 *   @0x15eaa0 mov r1, r4
 *   @0x15eaa4 ldr r12, [r0]
 *   @0x15eaa8 ldr r12, [r12, #0x2b8]
 *   @0x15eaac blx r12
 *   @0x15eab0 bl 0x290274 <getJNIEnv>
 *   @0x15eab4 ldr r1, [pc, #0x208]
 *   @0x15eab8 add r1, pc, r1
 *   @0x15eabc ldr r3, [r0]
 *   @0x15eac0 ldr r3, [r3, #0x29c]
 *   @0x15eac4 blx r3
 *   @0x15eac8 mov r9, r0
 *   @0x15eacc bl 0x290274 <getJNIEnv>
 *   @0x15ead0 mov r2, #6
 *   @0x15ead4 mov r3, r9
 *   @0x15ead8 mov r1, r4
 *   @0x15eadc ldr r12, [r0]
 *   @0x15eae0 ldr r12, [r12, #0x2b8]
 *   @0x15eae4 blx r12
 *   @0x15eae8 bl 0x290274 <getJNIEnv>
 *   @0x15eaec mov r1, r8
 *   @0x15eaf0 ldr r3, [r0]
 *   @0x15eaf4 ldr r3, [r3, #0x29c]
 *   @0x15eaf8 blx r3
 *   @0x15eafc mov r8, r0
 *   @0x15eb00 bl 0x290274 <getJNIEnv>
 *   @0x15eb04 mov r2, #7
 *   @0x15eb08 mov r3, r8
 *   @0x15eb0c mov r1, r4
 *   @0x15eb10 ldr r12, [r0]
 *   @0x15eb14 ldr r12, [r12, #0x2b8]
 *   @0x15eb18 blx r12
 *   @0x15eb1c bl 0x290274 <getJNIEnv>
 *   @0x15eb20 ldr r1, [pc, #0x1a0]
 *   @0x15eb24 add r1, pc, r1
 *   @0x15eb28 ldr r3, [r0]
 *   @0x15eb2c ldr r3, [r3, #0x29c]
 *   @0x15eb30 blx r3
 *   @0x15eb34 mov r8, r0
 *   @0x15eb38 bl 0x290274 <getJNIEnv>
 *   @0x15eb3c mov r2, #8
 *   @0x15eb40 mov r3, r8
 *   @0x15eb44 mov r1, r4
 *   @0x15eb48 ldr r12, [r0]
 *   @0x15eb4c ldr r12, [r12, #0x2b8]
 *   @0x15eb50 blx r12
 *   @0x15eb54 bl 0x290274 <getJNIEnv>
 *   @0x15eb58 mov r1, r7
 *   @0x15eb5c ldr r3, [r0]
 *   @0x15eb60 ldr r3, [r3, #0x29c]
 *   @0x15eb64 blx r3
 *   @0x15eb68 mov r7, r0
 *   @0x15eb6c bl 0x290274 <getJNIEnv>
 *   @0x15eb70 mov r3, r7
 *   @0x15eb74 mov r1, r4
 *   @0x15eb78 mov r2, #9
 *   @0x15eb7c ldr r12, [r0]
 *   @0x15eb80 ldr r12, [r12, #0x2b8]
 *   @0x15eb84 blx r12
 *   @0x15eb88 ldr r3, [sp, #0x18]
 *   @0x15eb8c cmp r3, #0
 *   @0x15eb90 beq 0x15ec24 <_Z20FacebookPostMessageMPcS_S_S_S_S_S_+0x384>
 *   @0x15eb94 bl 0x290274 <getJNIEnv>
 *   @0x15eb98 ldr r1, [pc, #0x12c]
 *   @0x15eb9c add r1, pc, r1
 *   @0x15eba0 ldr r3, [r0]
 *   @0x15eba4 ldr r3, [r3, #0x29c]
 *   @0x15eba8 blx r3
 *   @0x15ebac mov r7, r0
 *   @0x15ebb0 bl 0x290274 <getJNIEnv>
 *   @0x15ebb4 mov r3, r7
 *   @0x15ebb8 mov r1, r4
 *   @0x15ebbc mov r2, #10
 *   @0x15ebc0 ldr r12, [r0]
 *   @0x15ebc4 ldr r12, [r12, #0x2b8]
 *   @0x15ebc8 blx r12
 *   @0x15ebcc ldr r1, [sp, #0x1c]
 *   @0x15ebd0 mov r3, r6
 *   @0x15ebd4 ldr r2, [pc, #0xf4]
 *   @0x15ebd8 add r6, sp, #36
 *   @0x15ebdc add r2, pc, r2
 *   @0x15ebe0 str r1, [sp]
 *   @0x15ebe4 mov r0, r6
 *   @0x15ebe8 mov r1, #256
 *   @0x15ebec bl 0xb65c8 <snprintf@plt>
 *   @0x15ebf0 bl 0x290274 <getJNIEnv>
 *   @0x15ebf4 mov r1, r6
 *   @0x15ebf8 ldr r3, [r0]
 *   @0x15ebfc ldr r3, [r3, #0x29c]
 *   @0x15ec00 blx r3
 *   @0x15ec04 mov r6, r0
 *   @0x15ec08 bl 0x290274 <getJNIEnv>
 *   @0x15ec0c mov r3, r6
 *   @0x15ec10 mov r1, r4
 *   @0x15ec14 mov r2, #11
 *   @0x15ec18 ldr r12, [r0]
 *   @0x15ec1c ldr r12, [r12, #0x2b8]
 *   @0x15ec20 blx r12
 *   @0x15ec24 bl 0x290274 <getJNIEnv>
 *   @0x15ec28 ldr r1, [pc, #0xa4]
 *   @0x15ec2c add r1, pc, r1
 *   @0x15ec30 ldr r3, [r0]
 *   @0x15ec34 ldr r3, [r3, #0x29c]
 *   @0x15ec38 blx r3
 *   @0x15ec3c mov r7, r0
 *   @0x15ec40 bl 0x290274 <getJNIEnv>
 *   @0x15ec44 ldr r1, [pc, #0x8c]
 *   @0x15ec48 add r1, pc, r1
 *   @0x15ec4c ldr r3, [r0]
 *   @0x15ec50 ldr r3, [r3, #0x29c]
 *   @0x15ec54 blx r3
 *   @0x15ec58 mov r6, r0
 *   @0x15ec5c bl 0x290274 <getJNIEnv>
 *   @0x15ec60 ldr r1, [pc, #0x74]
 *   @0x15ec64 mov r3, r7
 *   @0x15ec68 ldr r2, [pc, #0x70]
 *   @0x15ec6c mvn r12, #0
 *   @0x15ec70 ldr r1, [pc, r1]
 *   @0x15ec74 ldr r2, [pc, r2]
 *   @0x15ec78 ldr r1, [r1]
 *   @0x15ec7c ldr r2, [r2]
 *   @0x15ec80 str r6, [sp]
 *   @0x15ec84 stmib sp, {r4, r12}
 *   @0x15ec88 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x15ec8c ldr r2, [sp, #0x124]
 *   @0x15ec90 ldr r3, [r5]
 *   @0x15ec94 mov r0, #1
 *   @0x15ec98 cmp r2, r3
 *   @0x15ec9c bne 0x15eca8 <_Z20FacebookPostMessageMPcS_S_S_S_S_S_+0x408>
 *   @0x15eca0 add sp, sp, #300
 *   @0x15eca4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x15eca8 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x15ecac mlaeq r8, r8, r0, pc
 *   @0x15ecb0 andseq r10, lr, r4, asr #28
 *   @0x15ecb4 ldrsheq r0, [sp], -lr
 *   @0x15ecb8 mulseq sp, r4, lr
 *   @0x15ecbc mulseq lr, r4, sp
 *   @0x15ecc0 andseq r10, lr, r0, lsr sp
 *   @0x15ecc4 andseq r10, lr, r12, asr #25
 *   @0x15ecc8 andseq r10, lr, r8, ror #24
 *   @0x15eccc ldrsheq r10, [lr], -r8
 *   @0x15ecd0 andseq r10, lr, r0, asr #23
 *   @0x15ecd4 mulseq lr, r0, r11
 *   @0x15ecd8 andseq r10, lr, r12, ror r11
 *   @0x15ecdc eoreq lr, r8, r4, lsr sp
 *   @0x15ece0 eoreq r1, r9, r0, asr #4
 *
 * ══ §14/28 anon_2d941c  0x2d941c  size 1092  273 条（0x2d941c..0x2d9860）
 * @func 0x2d941c 0x2d9860  size 1092  273 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2d941c+0x254×2 / anon_2d941c+0x270 / anon_2d941c+0x174 / anon_2d941c+0x164 / anon_2d941c+0x1e8 / anon_2d941c+0x1d8 / anon_2d941c+0x3c4 / b2BlockAllocator::Allocate(int)
 * 字段偏移 top8: 0x4×10 / 0x20×5 / 0xc×5 / 0x10×4 / 0x2c×3 / 0x18×3 / 0x80×3 / 0x88×3
 * VFP 指令 95 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d941c ldrb r3, [r1, #0x2c]
 *   @0x2d9420 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2d9424 vpush {d8, d9, d10, d11, d12, d13, d14}
 *   @0x2d9428 cmp r3, #0
 *   @0x2d942c sub sp, sp, #76
 *   @0x2d9430 mov r9, r1
 *   @0x2d9434 str r0, [sp, #0x20]
 *   @0x2d9438 bne 0x2d968c <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x5e8>
 *   @0x2d943c ldr r2, [r1, #0x8]
 *   @0x2d9440 vldr s15, [r2, #48]
 *   @0x2d9444 vmul.f32 s15, s15, s15
 *   @0x2d9448 vldr s13, [r2, #44]
 *   @0x2d944c vldr s14, [r2, #132]
 *   @0x2d9450 vldr s12, [r2, #140]
 *   @0x2d9454 ldr r0, [r1, #0xc]
 *   @0x2d9458 vldr s23, [r2, #60]
 *   @0x2d945c str r2, [sp, #0x1c]
 *   @0x2d9460 vldr s24, [r2, #64]
 *   @0x2d9464 ldr r3, [r0]
 *   @0x2d9468 ldr r3, [r3, #0xc]
 *   @0x2d946c vmla.f32 s15, s13, s13
 *   @0x2d9470 vmul.f32 s15, s14, s15
 *   @0x2d9474 vadd.f32 s13, s15, s12
 *   @0x2d9478 vcmpe.f32 s14, #0
 *   @0x2d947c vsub.f32 s15, s13, s15
 *   @0x2d9480 vmrs APSR_nzcv, fpscr
 *   @0x2d9484 vldrle s25, [pc, #968]
 *   @0x2d9488 vmovgt.f32 s25, #1.000000e+00
 *   @0x2d948c vcmpe.f32 s15, #0
 *   @0x2d9490 vdivgt.f32 s25, s25, s14
 *   @0x2d9494 vmrs APSR_nzcv, fpscr
 *   @0x2d9498 vldrle s26, [pc, #948]
 *   @0x2d949c vmovgt.f32 s26, #1.000000e+00
 *   @0x2d94a0 vdivgt.f32 s26, s26, s15
 *   @0x2d94a4 blx r3
 *   @0x2d94a8 cmp r0, #0
 *   @0x2d94ac str r0, [sp, #0x18]
 *   @0x2d94b0 ble 0x2d968c <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x5e8>
 *   @0x2d94b4 ldr r3, [sp, #0x20]
 *   @0x2d94b8 mov r11, #0
 *   @0x2d94bc add r6, sp, #56
 *   @0x2d94c0 mov r10, r11
 *   @0x2d94c4 add r2, sp, #52
 *   @0x2d94c8 vldr s22, [pc, #904]
 *   @0x2d94cc ldr r8, [r3, #0x4]
 *   @0x2d94d0 mov r3, r9
 *   @0x2d94d4 mov r9, r11
 *   @0x2d94d8 mov r11, r3
 *   @0x2d94dc str r2, [sp, #0x24]
 *   @0x2d94e0 vldr s21, [pc, #884]
 *   @0x2d94e4 vldr s20, [pc, #884]
 *   @0x2d94e8 ldr r3, [r11, #0x18]
 *   @0x2d94ec vldr s14, [r8, #24]
 *   @0x2d94f0 vldr s15, [r8, #28]
 *   @0x2d94f4 vmov.f32 s12, s21
 *   @0x2d94f8 add r3, r3, r9
 *   @0x2d94fc vldr s16, [r3]
 *   @0x2d9500 vldr s18, [r3, #4]
 *   @0x2d9504 vldr s17, [r3, #8]
 *   @0x2d9508 vldr s19, [r3, #12]
 *   @0x2d950c ldr r12, [r8, #0x68]
 *   @0x2d9510 vsub.f32 s16, s16, s14
 *   @0x2d9514 ldr r4, [r8, #0x70]
 *   @0x2d9518 sbfx r0, r12, #0x0, #0x1d
 *   @0x2d951c add r12, r4, r12, lsl #3
 *   @0x2d9520 vmul.f32 s13, s16, s15
 *   @0x2d9524 vsub.f32 s18, s18, s14
 *   @0x2d9528 vmla.f32 s12, s13, s22
 *   @0x2d952c vmov.f32 s13, s20
 *   @0x2d9530 vmla.f32 s13, s18, s15
 *   @0x2d9534 vcvt.u32.f32 s12, s12
 *   @0x2d9538 vcvt.u32.f32 s13, s13
 *   @0x2d953c vmov r3, s12
 *   @0x2d9540 vmov r5, s13
 *   @0x2d9544 vadd.f32 s17, s14, s17
 *   @0x2d9548 vadd.f32 s19, s14, s19
 *   @0x2d954c add r5, r3, r5, lsl #20
 *   @0x2d9550 cmp r0, #0
 *   @0x2d9554 ble 0x2d9590 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x4ec>
 *   @0x2d9558 asr r3, r0, #1
 *   @0x2d955c add r1, r4, r3, lsl #3
 *   @0x2d9560 ldr r2, [r1, #0x4]
 *   @0x2d9564 cmp r5, r2
 *   @0x2d9568 bls 0x2d9580 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x4dc>
 *   @0x2d956c b 0x2d969c <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x5f8>
 *   @0x2d9570 ldr r0, [r1, #0x4]
 *   @0x2d9574 cmp r5, r0
 *   @0x2d9578 bhi 0x2d96a4 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x600>
 *   @0x2d957c mov r3, r2
 *   @0x2d9580 asr r2, r3, #1
 *   @0x2d9584 cmp r3, #0
 *   @0x2d9588 add r1, r4, r2, lsl #3
 *   @0x2d958c bne 0x2d9570 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x4cc>
 *   @0x2d9590 vmul.f32 s14, s17, s15
 *   @0x2d9594 rsb r0, r4, r12
 *   @0x2d9598 mov r5, r4
 *   @0x2d959c asr r0, r0, #3
 *   @0x2d95a0 vmov.f32 s10, s21
 *   @0x2d95a4 vmov.f32 s13, s20
 *   @0x2d95a8 vmla.f32 s10, s14, s22
 *   @0x2d95ac vmla.f32 s13, s19, s15
 *   @0x2d95b0 vcvt.u32.f32 s14, s10
 *   @0x2d95b4 vcvt.u32.f32 s15, s13
 *   @0x2d95b8 vmov r2, s14
 *   @0x2d95bc vmov r12, s15
 *   @0x2d95c0 add r12, r2, r12, lsl #20
 *   @0x2d95c4 cmp r0, #0
 *   @0x2d95c8 ble 0x2d9604 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x560>
 *   @0x2d95cc asr r3, r0, #1
 *   @0x2d95d0 add r1, r4, r3, lsl #3
 *   @0x2d95d4 ldr r2, [r1, #0x4]
 *   @0x2d95d8 cmp r12, r2
 *   @0x2d95dc blo 0x2d95f4 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x550>
 *   @0x2d95e0 b 0x2d96b4 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x610>
 *   @0x2d95e4 ldr r0, [r1, #0x4]
 *   @0x2d95e8 cmp r12, r0
 *   @0x2d95ec bhs 0x2d96bc <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x618>
 *   @0x2d95f0 mov r3, r2
 *   @0x2d95f4 asr r2, r3, #1
 *   @0x2d95f8 cmp r3, #0
 *   @0x2d95fc add r1, r4, r2, lsl #3
 *   @0x2d9600 bne 0x2d95e4 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x540>
 *   @0x2d9604 cmp r4, r5
 *   @0x2d9608 addne r2, sp, #64
 *   @0x2d960c addne r5, r5, #8
 *   @0x2d9610 vmovne.f32 s27, #1.000000e+00
 *   @0x2d9614 strne r2, [sp, #0x14]
 *   @0x2d9618 bne 0x2d9624 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x580>
 *   @0x2d961c b 0x2d9678 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x5d4>
 *   @0x2d9620 add r5, r5, #8
 *   @0x2d9624 ldr r7, [r5, #-0x8]
 *   @0x2d9628 ldr r3, [r8, #0x38]
 *   @0x2d962c add r3, r3, r7, lsl #3
 *   @0x2d9630 ldm r3, {r0, r1}
 *   @0x2d9634 stm r6, {r0, r1}
 *   @0x2d9638 vldr s15, [sp, #56]
 *   @0x2d963c vcmpe.f32 s16, s15
 *   @0x2d9640 vmrs APSR_nzcv, fpscr
 *   @0x2d9644 bhi 0x2d9670 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x5cc>
 *   @0x2d9648 vcmpe.f32 s17, s15
 *   @0x2d964c vmrs APSR_nzcv, fpscr
 *   @0x2d9650 blt 0x2d9670 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x5cc>
 *   @0x2d9654 vldr s15, [sp, #60]
 *   @0x2d9658 vcmpe.f32 s18, s15
 *   @0x2d965c vmrs APSR_nzcv, fpscr
 *   @0x2d9660 bhi 0x2d9670 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x5cc>
 *   @0x2d9664 vcmpe.f32 s19, s15
 *   @0x2d9668 vmrs APSR_nzcv, fpscr
 *   @0x2d966c bge 0x2d96cc <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x628>
 *   @0x2d9670 cmp r5, r4
 *   @0x2d9674 bne 0x2d9620 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x57c>
 *   @0x2d9678 ldr r3, [sp, #0x18]
 *   @0x2d967c add r10, r10, #1
 *   @0x2d9680 add r9, r9, #28
 *   @0x2d9684 cmp r10, r3
 *   @0x2d9688 bne 0x2d94e8 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x444>
 *   @0x2d968c mov r0, #1
 *   @0x2d9690 add sp, sp, #76
 *   @0x2d9694 vpop {d8, d9, d10, d11, d12, d13, d14}
 *   @0x2d9698 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2d969c mov r2, r3
 *   @0x2d96a0 mov r3, r0
 *   @0x2d96a4 rsb r3, r2, r3
 *   @0x2d96a8 add r4, r1, #8
 *   @0x2d96ac sub r0, r3, #1
 *   @0x2d96b0 b 0x2d9550 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x4ac>
 *   @0x2d96b4 mov r2, r3
 *   @0x2d96b8 mov r3, r0
 *   @0x2d96bc rsb r3, r2, r3
 *   @0x2d96c0 add r4, r1, #8
 *   @0x2d96c4 sub r0, r3, #1
 *   @0x2d96c8 b 0x2d95c4 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x520>
 *   @0x2d96cc ldr r0, [r11, #0xc]
 *   @0x2d96d0 mov r2, r6
 *   @0x2d96d4 ldr r1, [r11, #0x8]
 *   @0x2d96d8 add lr, sp, #64
 *   @0x2d96dc add r3, sp, #52
 *   @0x2d96e0 ldr r12, [r0]
 *   @0x2d96e4 add r1, r1, #12
 *   @0x2d96e8 str lr, [sp]
 *   @0x2d96ec str r10, [sp, #0x4]
 *   @0x2d96f0 ldr r12, [r12, #0x14]
 *   @0x2d96f4 blx r12
 *   @0x2d96f8 ldr r2, [sp, #0x20]
 *   @0x2d96fc vldr s15, [sp, #52]
 *   @0x2d9700 ldr r8, [r2, #0x4]
 *   @0x2d9704 vldr s14, [r8, #24]
 *   @0x2d9708 vcmpe.f32 s14, s15
 *   @0x2d970c vmrs APSR_nzcv, fpscr
 *   @0x2d9710 ble 0x2d9670 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x5cc>
 *   @0x2d9714 ldr r3, [r8, #0x30]
 *   @0x2d9718 ldr r3, [r3, r7, lsl #2]
 *   @0x2d971c tst r3, #4
 *   @0x2d9720 beq 0x2d983c <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x798>
 *   @0x2d9724 vldr s29, [pc, #296]
 *   @0x2d9728 vldr s28, [sp, #60]
 *   @0x2d972c vsub.f32 s28, s28, s24
 *   @0x2d9730 vldr s14, [sp, #64]
 *   @0x2d9734 vldr s15, [sp, #56]
 *   @0x2d9738 ldr r3, [r8, #0x80]
 *   @0x2d973c vldr s13, [sp, #68]
 *   @0x2d9740 ldr r2, [r8, #0x84]
 *   @0x2d9744 cmp r3, r2
 *   @0x2d9748 vmul.f32 s28, s28, s14
 *   @0x2d974c vsub.f32 s15, s15, s23
 *   @0x2d9750 vnmls.f32 s28, s15, s13
 *   @0x2d9754 blt 0x2d97e0 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x73c>
 *   @0x2d9758 cmp r3, #0
 *   @0x2d975c ldr r0, [r8, #0xd4]
 *   @0x2d9760 lslne r12, r3, #1
 *   @0x2d9764 addne r3, r12, r3, lsl #2
 *   @0x2d9768 moveq r1, #6144
 *   @0x2d976c moveq r12, #256
 *   @0x2d9770 lslne r1, r3, #3
 *   @0x2d9774 ldr r3, [r8, #0x88]
 *   @0x2d9778 str r12, [sp, #0xc]
 *   @0x2d977c str r2, [sp, #0x10]
 *   @0x2d9780 str r3, [sp, #0x28]
 *   @0x2d9784 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2d9788 ldr r2, [sp, #0x10]
 *   @0x2d978c ldr r1, [sp, #0x28]
 *   @0x2d9790 add r2, r2, r2, lsl #1
 *   @0x2d9794 lsl r3, r2, #3
 *   @0x2d9798 str r3, [sp, #0x10]
 *   @0x2d979c mov r2, r3
 *   @0x2d97a0 str r0, [sp, #0x2c]
 *   @0x2d97a4 bl 0xb65bc <memcpy@plt>
 *   @0x2d97a8 ldr r3, [sp, #0x10]
 *   @0x2d97ac ldr r0, [r8, #0xd4]
 *   @0x2d97b0 ldr r1, [sp, #0x28]
 *   @0x2d97b4 mov r2, r3
 *   @0x2d97b8 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2d97bc ldr r3, [sp, #0x2c]
 *   @0x2d97c0 ldr r2, [sp, #0x20]
 *   @0x2d97c4 vldr s14, [sp, #64]
 *   @0x2d97c8 ldr r12, [sp, #0xc]
 *   @0x2d97cc vldr s13, [sp, #68]
 *   @0x2d97d0 str r3, [r8, #0x88]
 *   @0x2d97d4 ldr r8, [r2, #0x4]
 *   @0x2d97d8 ldr r3, [r8, #0x80]
 *   @0x2d97dc str r12, [r8, #0x84]
 *   @0x2d97e0 vmul.f32 s10, s28, s26
 *   @0x2d97e4 vldr s11, [r8, #28]
 *   @0x2d97e8 vldr s12, [sp, #52]
 *   @0x2d97ec ldr r2, [r8, #0x88]
 *   @0x2d97f0 add r1, r3, r3, lsl #1
 *   @0x2d97f4 add r0, r3, #1
 *   @0x2d97f8 str r7, [r2, r1, lsl #3]
 *   @0x2d97fc add r3, r2, r1, lsl #3
 *   @0x2d9800 ldr r2, [sp, #0x1c]
 *   @0x2d9804 str r2, [r3, #0x4]
 *   @0x2d9808 vadd.f32 s15, s25, s29
 *   @0x2d980c vmla.f32 s15, s28, s10
 *   @0x2d9810 vdiv.f32 s15, s27, s15
 *   @0x2d9814 vmov.f32 s10, s27
 *   @0x2d9818 vstr s15, [r3, #20]
 *   @0x2d981c vmls.f32 s10, s11, s12
 *   @0x2d9820 vneg.f32 s14, s14
 *   @0x2d9824 vstr s10, [r3, #8]
 *   @0x2d9828 vneg.f32 s15, s13
 *   @0x2d982c vstr s14, [r3, #12]
 *   @0x2d9830 vstr s15, [r3, #16]
 *   @0x2d9834 str r0, [r8, #0x80]
 *   @0x2d9838 b 0x2d9670 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x5cc>
 *   @0x2d983c mov r0, r8
 *   @0x2d9840 bl 0x2d8a20 <_ZNK16b2ParticleSystem18GetParticleInvMassEv>
 *   @0x2d9844 ldr r3, [sp, #0x20]
 *   @0x2d9848 ldr r8, [r3, #0x4]
 *   @0x2d984c vmov s29, r0
 *   @0x2d9850 b 0x2d9728 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x684>
 *   @0x2d9854 andeq r0, r0, r0
 *   @0x2d9858 orrmi r0, r0, #0
 *   @0x2d985c .word 0x49000000
 *
 * ══ §15/28 JS_RegExp_prototype_toString(RValue&, CInstance*, CInstance*, int, RValue*)  0x253948  size 1088  272 条（0x253948..0x253d88）
 * @func 0x253948 0x253d88  size 1088  272 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_JS_Object_Get(YYObjectBase*, RValue*, char const*)×4 / YYAlloc(int)×4 / 0xb65bc×4 / YYFree(void const*)×4 / YYGetBool(RValue const*, int)×3 / 0xb6538×2 / 0xb65a4×2 / 0xb6574
 * 字段偏移 top8: 0x-74×13 / 0x-6c×13 / 0x-70×12 / 0x-78×6 / 0x-5c×3 / 0x-28×2 / 0x-68×2 / 0x-60×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x253948 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x25394c add r11, sp, #32
 *   @0x253950 ldr r5, [pc, #0x40c]
 *   @0x253954 sub sp, sp, #92
 *   @0x253958 mov r6, r1
 *   @0x25395c ldr r5, [pc, r5]
 *   @0x253960 ldr r1, [pc, #0x400]
 *   @0x253964 mov r8, r0
 *   @0x253968 ldr r0, [r6, #0x40]
 *   @0x25396c ldr r3, [r5]
 *   @0x253970 add r1, pc, r1
 *   @0x253974 str r3, [r11, #-0x28]
 *   @0x253978 bl 0xb6574 <strcmp@plt>
 *   @0x25397c subs r4, r0, #0
 *   @0x253980 bne 0x253d50 <_Z28JS_RegExp_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x408>
 *   @0x253984 sub r7, r11, #104
 *   @0x253988 ldr r2, [pc, #0x3dc]
 *   @0x25398c mov r0, r6
 *   @0x253990 str r4, [r11, #-0x68]
 *   @0x253994 add r2, pc, r2
 *   @0x253998 mov r1, r7
 *   @0x25399c str r4, [r11, #-0x64]
 *   @0x2539a0 sub r10, r11, #72
 *   @0x2539a4 str r4, [r11, #-0x60]
 *   @0x2539a8 sub r9, r11, #56
 *   @0x2539ac str r4, [r11, #-0x5c]
 *   @0x2539b0 str r4, [r11, #-0x58]
 *   @0x2539b4 str r4, [r11, #-0x54]
 *   @0x2539b8 str r4, [r11, #-0x50]
 *   @0x2539bc str r4, [r11, #-0x4c]
 *   @0x2539c0 str r4, [r11, #-0x48]
 *   @0x2539c4 str r4, [r11, #-0x44]
 *   @0x2539c8 str r4, [r11, #-0x40]
 *   @0x2539cc str r4, [r11, #-0x3c]
 *   @0x2539d0 str r4, [r11, #-0x38]
 *   @0x2539d4 str r4, [r11, #-0x34]
 *   @0x2539d8 str r4, [r11, #-0x30]
 *   @0x2539dc str r4, [r11, #-0x2c]
 *   @0x2539e0 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x2539e4 sub r3, r11, #88
 *   @0x2539e8 ldr r2, [pc, #0x380]
 *   @0x2539ec mov r0, r6
 *   @0x2539f0 str r3, [r11, #-0x78]
 *   @0x2539f4 mov r1, r3
 *   @0x2539f8 add r2, pc, r2
 *   @0x2539fc bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x253a00 ldr r2, [pc, #0x36c]
 *   @0x253a04 mov r1, r10
 *   @0x253a08 mov r0, r6
 *   @0x253a0c add r2, pc, r2
 *   @0x253a10 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x253a14 ldr r2, [pc, #0x35c]
 *   @0x253a18 mov r0, r6
 *   @0x253a1c mov r1, r9
 *   @0x253a20 add r2, pc, r2
 *   @0x253a24 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x253a28 mov r1, r4
 *   @0x253a2c mov r0, r7
 *   @0x253a30 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x253a34 ldr r3, [r11, #-0x78]
 *   @0x253a38 mov r1, r4
 *   @0x253a3c mov r6, r0
 *   @0x253a40 mov r0, r3
 *   @0x253a44 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x253a48 mov r1, r4
 *   @0x253a4c mov r3, r0
 *   @0x253a50 mov r0, r10
 *   @0x253a54 str r3, [r11, #-0x78]
 *   @0x253a58 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x253a5c mov r1, r4
 *   @0x253a60 mov r4, #0
 *   @0x253a64 mov r10, r0
 *   @0x253a68 mov r0, r9
 *   @0x253a6c bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x253a70 ldr r3, [r11, #-0x78]
 *   @0x253a74 sub sp, sp, #16
 *   @0x253a78 str r4, [r11, #-0x74]
 *   @0x253a7c cmp r3, #0
 *   @0x253a80 str r4, [r11, #-0x70]
 *   @0x253a84 addne r3, sp, #1
 *   @0x253a88 str r4, [r11, #-0x6c]
 *   @0x253a8c movne r2, #103
 *   @0x253a90 moveq r3, sp
 *   @0x253a94 mov r9, sp
 *   @0x253a98 strbne r2, [sp]
 *   @0x253a9c cmp r10, #0
 *   @0x253aa0 movne r2, #105
 *   @0x253aa4 strbne r2, [r3]
 *   @0x253aa8 addne r3, r3, #1
 *   @0x253aac cmp r0, #0
 *   @0x253ab0 mov r0, #3
 *   @0x253ab4 movne r2, #109
 *   @0x253ab8 strbne r2, [r3]
 *   @0x253abc addne r3, r3, #1
 *   @0x253ac0 strb r4, [r3]
 *   @0x253ac4 bl 0xcef4c <_Z7YYAlloci>
 *   @0x253ac8 mov r1, r4
 *   @0x253acc ldr r2, [r11, #-0x70]
 *   @0x253ad0 str r0, [r11, #-0x74]
 *   @0x253ad4 bl 0xb65bc <memcpy@plt>
 *   @0x253ad8 ldr r1, [pc, #0x29c]
 *   @0x253adc mov r0, #3
 *   @0x253ae0 ldr r3, [r11, #-0x6c]
 *   @0x253ae4 cmp r6, r4
 *   @0x253ae8 add r1, pc, r1
 *   @0x253aec ldr r2, [r11, #-0x74]
 *   @0x253af0 str r0, [r11, #-0x70]
 *   @0x253af4 ldrh r1, [r1]
 *   @0x253af8 strh r1, [r2, r3]
 *   @0x253afc ldr r4, [r11, #-0x6c]
 *   @0x253b00 add r4, r4, #1
 *   @0x253b04 str r4, [r11, #-0x6c]
 *   @0x253b08 beq 0x253bb0 <_Z28JS_RegExp_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x268>
 *   @0x253b0c mov r0, r6
 *   @0x253b10 bl 0xb6538 <strlen@plt>
 *   @0x253b14 ldr r3, [r11, #-0x70]
 *   @0x253b18 mvn r1, r4
 *   @0x253b1c add r1, r3, r1
 *   @0x253b20 add r2, r0, #1
 *   @0x253b24 mov r10, r0
 *   @0x253b28 cmp r2, r1
 *   @0x253b2c ble 0x253b94 <_Z28JS_RegExp_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x24c>
 *   @0x253b30 cmp r3, #0
 *   @0x253b34 add r4, r4, r2
 *   @0x253b38 moveq r3, r2
 *   @0x253b3c add r3, r3, r3, lsl #1
 *   @0x253b40 add r3, r3, r3, lsr #31
 *   @0x253b44 asr r3, r3, #1
 *   @0x253b48 cmp r3, r4
 *   @0x253b4c addlt r4, r4, r4, lsl #1
 *   @0x253b50 addlt r4, r4, r4, lsr #31
 *   @0x253b54 asrlt r3, r4, #1
 *   @0x253b58 ldr r4, [r11, #-0x74]
 *   @0x253b5c str r3, [r11, #-0x78]
 *   @0x253b60 mov r0, r3
 *   @0x253b64 bl 0xcef4c <_Z7YYAlloci>
 *   @0x253b68 ldr r2, [r11, #-0x70]
 *   @0x253b6c mov r1, r4
 *   @0x253b70 str r0, [r11, #-0x74]
 *   @0x253b74 bl 0xb65bc <memcpy@plt>
 *   @0x253b78 ldr r3, [r11, #-0x78]
 *   @0x253b7c cmp r4, #0
 *   @0x253b80 str r3, [r11, #-0x70]
 *   @0x253b84 beq 0x253b90 <_Z28JS_RegExp_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x248>
 *   @0x253b88 mov r0, r4
 *   @0x253b8c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x253b90 ldr r4, [r11, #-0x6c]
 *   @0x253b94 ldr r0, [r11, #-0x74]
 *   @0x253b98 mov r1, r6
 *   @0x253b9c add r0, r0, r4
 *   @0x253ba0 bl 0xb65a4 <strcpy@plt>
 *   @0x253ba4 ldr r4, [r11, #-0x6c]
 *   @0x253ba8 add r4, r10, r4
 *   @0x253bac str r4, [r11, #-0x6c]
 *   @0x253bb0 ldr r3, [r11, #-0x70]
 *   @0x253bb4 mvn r2, r4
 *   @0x253bb8 add r2, r3, r2
 *   @0x253bbc cmp r2, #1
 *   @0x253bc0 bgt 0x253c20 <_Z28JS_RegExp_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x2d8>
 *   @0x253bc4 cmp r3, #0
 *   @0x253bc8 add r4, r4, #2
 *   @0x253bcc addne r3, r3, r3, lsl #1
 *   @0x253bd0 moveq r6, #3
 *   @0x253bd4 addne r3, r3, r3, lsr #31
 *   @0x253bd8 asrne r6, r3, #1
 *   @0x253bdc cmp r4, r6
 *   @0x253be0 addgt r4, r4, r4, lsl #1
 *   @0x253be4 addgt r4, r4, r4, lsr #31
 *   @0x253be8 asrgt r6, r4, #1
 *   @0x253bec ldr r4, [r11, #-0x74]
 *   @0x253bf0 mov r0, r6
 *   @0x253bf4 bl 0xcef4c <_Z7YYAlloci>
 *   @0x253bf8 ldr r2, [r11, #-0x70]
 *   @0x253bfc mov r1, r4
 *   @0x253c00 str r0, [r11, #-0x74]
 *   @0x253c04 bl 0xb65bc <memcpy@plt>
 *   @0x253c08 cmp r4, #0
 *   @0x253c0c str r6, [r11, #-0x70]
 *   @0x253c10 beq 0x253c1c <_Z28JS_RegExp_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x2d4>
 *   @0x253c14 mov r0, r4
 *   @0x253c18 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x253c1c ldr r4, [r11, #-0x6c]
 *   @0x253c20 ldr r2, [pc, #0x158]
 *   @0x253c24 mov r0, r9
 *   @0x253c28 ldr r3, [r11, #-0x74]
 *   @0x253c2c add r2, pc, r2
 *   @0x253c30 ldrh r2, [r2]
 *   @0x253c34 strh r2, [r3, r4]
 *   @0x253c38 ldr r4, [r11, #-0x6c]
 *   @0x253c3c add r4, r4, #1
 *   @0x253c40 str r4, [r11, #-0x6c]
 *   @0x253c44 bl 0xb6538 <strlen@plt>
 *   @0x253c48 ldr r3, [r11, #-0x70]
 *   @0x253c4c mvn r1, r4
 *   @0x253c50 add r1, r3, r1
 *   @0x253c54 add r2, r0, #1
 *   @0x253c58 mov r6, r0
 *   @0x253c5c cmp r2, r1
 *   @0x253c60 ble 0x253cc0 <_Z28JS_RegExp_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x378>
 *   @0x253c64 cmp r3, #0
 *   @0x253c68 add r4, r4, r2
 *   @0x253c6c moveq r3, r2
 *   @0x253c70 add r3, r3, r3, lsl #1
 *   @0x253c74 add r3, r3, r3, lsr #31
 *   @0x253c78 asr r10, r3, #1
 *   @0x253c7c cmp r10, r4
 *   @0x253c80 addlt r4, r4, r4, lsl #1
 *   @0x253c84 addlt r4, r4, r4, lsr #31
 *   @0x253c88 asrlt r10, r4, #1
 *   @0x253c8c ldr r4, [r11, #-0x74]
 *   @0x253c90 mov r0, r10
 *   @0x253c94 bl 0xcef4c <_Z7YYAlloci>
 *   @0x253c98 ldr r2, [r11, #-0x70]
 *   @0x253c9c mov r1, r4
 *   @0x253ca0 str r0, [r11, #-0x74]
 *   @0x253ca4 bl 0xb65bc <memcpy@plt>
 *   @0x253ca8 cmp r4, #0
 *   @0x253cac str r10, [r11, #-0x70]
 *   @0x253cb0 beq 0x253cbc <_Z28JS_RegExp_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x374>
 *   @0x253cb4 mov r0, r4
 *   @0x253cb8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x253cbc ldr r4, [r11, #-0x6c]
 *   @0x253cc0 ldr r0, [r11, #-0x74]
 *   @0x253cc4 mov r1, r9
 *   @0x253cc8 add r0, r0, r4
 *   @0x253ccc bl 0xb65a4 <strcpy@plt>
 *   @0x253cd0 ldr r3, [r11, #-0x6c]
 *   @0x253cd4 mov r0, r8
 *   @0x253cd8 add r6, r6, r3
 *   @0x253cdc mov r3, #0
 *   @0x253ce0 cmp r6, #0
 *   @0x253ce4 str r3, [r11, #-0x6c]
 *   @0x253ce8 subeq r1, r11, #108
 *   @0x253cec ldrne r1, [r11, #-0x74]
 *   @0x253cf0 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x253cf4 ldr r3, [r11, #-0x5c]
 *   @0x253cf8 sub r3, r3, #1
 *   @0x253cfc bic r3, r3, #-16777216
 *   @0x253d00 bic r3, r3, #3
 *   @0x253d04 cmp r3, #0
 *   @0x253d08 bne 0x253d14 <_Z28JS_RegExp_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x3cc>
 *   @0x253d0c mov r0, r7
 *   @0x253d10 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x253d14 ldr r0, [r11, #-0x74]
 *   @0x253d18 mov r3, #0
 *   @0x253d1c mov r2, #5
 *   @0x253d20 str r3, [r11, #-0x60]
 *   @0x253d24 cmp r0, r3
 *   @0x253d28 str r3, [r11, #-0x68]
 *   @0x253d2c str r2, [r11, #-0x5c]
 *   @0x253d30 beq 0x253d38 <_Z28JS_RegExp_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x3f0>
 *   @0x253d34 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x253d38 ldr r2, [r11, #-0x28]
 *   @0x253d3c ldr r3, [r5]
 *   @0x253d40 cmp r2, r3
 *   @0x253d44 bne 0x253d60 <_Z28JS_RegExp_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x418>
 *   @0x253d48 sub sp, r11, #32
 *   @0x253d4c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x253d50 ldr r0, [pc, #0x2c]
 *   @0x253d54 add r0, pc, r0
 *   @0x253d58 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x253d5c b 0x253d38 <_Z28JS_RegExp_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x3f0>
 *   @0x253d60 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x253d64 ldrsheq r9, [r9], -r4
 *   @0x253d68 ldrheq r2, [r0], -r12
 *   @0x253d6c mulseq r0, r8, r12
 *   @0x253d70 andeq r1, lr, r0, ror #9
 *   @0x253d74 andseq r2, r0, r8, lsr #24
 *   @0x253d78 andseq r2, r0, r0, lsr #24
 *   @0x253d7c andeq sp, sp, r4, lsr #1
 *   @0x253d80 andeq r12, sp, r0, ror #30
 *   @0x253d84 ldrsheq r2, [r0], -r4
 *
 * ══ §16/28 anon_2d9420  0x2d9420  size 1088  272 条（0x2d9420..0x2d9860）
 * @func 0x2d9420 0x2d9860  size 1088  272 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2d941c+0x254×2 / anon_2d941c+0x270 / anon_2d941c+0x174 / anon_2d941c+0x164 / anon_2d941c+0x1e8 / anon_2d941c+0x1d8 / anon_2d941c+0x3c4 / b2BlockAllocator::Allocate(int)
 * 字段偏移 top8: 0x4×10 / 0x20×5 / 0xc×5 / 0x10×4 / 0x18×3 / 0x80×3 / 0x88×3 / 0x28×3
 * VFP 指令 95 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d9420 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2d9424 vpush {d8, d9, d10, d11, d12, d13, d14}
 *   @0x2d9428 cmp r3, #0
 *   @0x2d942c sub sp, sp, #76
 *   @0x2d9430 mov r9, r1
 *   @0x2d9434 str r0, [sp, #0x20]
 *   @0x2d9438 bne 0x2d968c <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x5e8>
 *   @0x2d943c ldr r2, [r1, #0x8]
 *   @0x2d9440 vldr s15, [r2, #48]
 *   @0x2d9444 vmul.f32 s15, s15, s15
 *   @0x2d9448 vldr s13, [r2, #44]
 *   @0x2d944c vldr s14, [r2, #132]
 *   @0x2d9450 vldr s12, [r2, #140]
 *   @0x2d9454 ldr r0, [r1, #0xc]
 *   @0x2d9458 vldr s23, [r2, #60]
 *   @0x2d945c str r2, [sp, #0x1c]
 *   @0x2d9460 vldr s24, [r2, #64]
 *   @0x2d9464 ldr r3, [r0]
 *   @0x2d9468 ldr r3, [r3, #0xc]
 *   @0x2d946c vmla.f32 s15, s13, s13
 *   @0x2d9470 vmul.f32 s15, s14, s15
 *   @0x2d9474 vadd.f32 s13, s15, s12
 *   @0x2d9478 vcmpe.f32 s14, #0
 *   @0x2d947c vsub.f32 s15, s13, s15
 *   @0x2d9480 vmrs APSR_nzcv, fpscr
 *   @0x2d9484 vldrle s25, [pc, #968]
 *   @0x2d9488 vmovgt.f32 s25, #1.000000e+00
 *   @0x2d948c vcmpe.f32 s15, #0
 *   @0x2d9490 vdivgt.f32 s25, s25, s14
 *   @0x2d9494 vmrs APSR_nzcv, fpscr
 *   @0x2d9498 vldrle s26, [pc, #948]
 *   @0x2d949c vmovgt.f32 s26, #1.000000e+00
 *   @0x2d94a0 vdivgt.f32 s26, s26, s15
 *   @0x2d94a4 blx r3
 *   @0x2d94a8 cmp r0, #0
 *   @0x2d94ac str r0, [sp, #0x18]
 *   @0x2d94b0 ble 0x2d968c <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x5e8>
 *   @0x2d94b4 ldr r3, [sp, #0x20]
 *   @0x2d94b8 mov r11, #0
 *   @0x2d94bc add r6, sp, #56
 *   @0x2d94c0 mov r10, r11
 *   @0x2d94c4 add r2, sp, #52
 *   @0x2d94c8 vldr s22, [pc, #904]
 *   @0x2d94cc ldr r8, [r3, #0x4]
 *   @0x2d94d0 mov r3, r9
 *   @0x2d94d4 mov r9, r11
 *   @0x2d94d8 mov r11, r3
 *   @0x2d94dc str r2, [sp, #0x24]
 *   @0x2d94e0 vldr s21, [pc, #884]
 *   @0x2d94e4 vldr s20, [pc, #884]
 *   @0x2d94e8 ldr r3, [r11, #0x18]
 *   @0x2d94ec vldr s14, [r8, #24]
 *   @0x2d94f0 vldr s15, [r8, #28]
 *   @0x2d94f4 vmov.f32 s12, s21
 *   @0x2d94f8 add r3, r3, r9
 *   @0x2d94fc vldr s16, [r3]
 *   @0x2d9500 vldr s18, [r3, #4]
 *   @0x2d9504 vldr s17, [r3, #8]
 *   @0x2d9508 vldr s19, [r3, #12]
 *   @0x2d950c ldr r12, [r8, #0x68]
 *   @0x2d9510 vsub.f32 s16, s16, s14
 *   @0x2d9514 ldr r4, [r8, #0x70]
 *   @0x2d9518 sbfx r0, r12, #0x0, #0x1d
 *   @0x2d951c add r12, r4, r12, lsl #3
 *   @0x2d9520 vmul.f32 s13, s16, s15
 *   @0x2d9524 vsub.f32 s18, s18, s14
 *   @0x2d9528 vmla.f32 s12, s13, s22
 *   @0x2d952c vmov.f32 s13, s20
 *   @0x2d9530 vmla.f32 s13, s18, s15
 *   @0x2d9534 vcvt.u32.f32 s12, s12
 *   @0x2d9538 vcvt.u32.f32 s13, s13
 *   @0x2d953c vmov r3, s12
 *   @0x2d9540 vmov r5, s13
 *   @0x2d9544 vadd.f32 s17, s14, s17
 *   @0x2d9548 vadd.f32 s19, s14, s19
 *   @0x2d954c add r5, r3, r5, lsl #20
 *   @0x2d9550 cmp r0, #0
 *   @0x2d9554 ble 0x2d9590 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x4ec>
 *   @0x2d9558 asr r3, r0, #1
 *   @0x2d955c add r1, r4, r3, lsl #3
 *   @0x2d9560 ldr r2, [r1, #0x4]
 *   @0x2d9564 cmp r5, r2
 *   @0x2d9568 bls 0x2d9580 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x4dc>
 *   @0x2d956c b 0x2d969c <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x5f8>
 *   @0x2d9570 ldr r0, [r1, #0x4]
 *   @0x2d9574 cmp r5, r0
 *   @0x2d9578 bhi 0x2d96a4 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x600>
 *   @0x2d957c mov r3, r2
 *   @0x2d9580 asr r2, r3, #1
 *   @0x2d9584 cmp r3, #0
 *   @0x2d9588 add r1, r4, r2, lsl #3
 *   @0x2d958c bne 0x2d9570 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x4cc>
 *   @0x2d9590 vmul.f32 s14, s17, s15
 *   @0x2d9594 rsb r0, r4, r12
 *   @0x2d9598 mov r5, r4
 *   @0x2d959c asr r0, r0, #3
 *   @0x2d95a0 vmov.f32 s10, s21
 *   @0x2d95a4 vmov.f32 s13, s20
 *   @0x2d95a8 vmla.f32 s10, s14, s22
 *   @0x2d95ac vmla.f32 s13, s19, s15
 *   @0x2d95b0 vcvt.u32.f32 s14, s10
 *   @0x2d95b4 vcvt.u32.f32 s15, s13
 *   @0x2d95b8 vmov r2, s14
 *   @0x2d95bc vmov r12, s15
 *   @0x2d95c0 add r12, r2, r12, lsl #20
 *   @0x2d95c4 cmp r0, #0
 *   @0x2d95c8 ble 0x2d9604 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x560>
 *   @0x2d95cc asr r3, r0, #1
 *   @0x2d95d0 add r1, r4, r3, lsl #3
 *   @0x2d95d4 ldr r2, [r1, #0x4]
 *   @0x2d95d8 cmp r12, r2
 *   @0x2d95dc blo 0x2d95f4 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x550>
 *   @0x2d95e0 b 0x2d96b4 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x610>
 *   @0x2d95e4 ldr r0, [r1, #0x4]
 *   @0x2d95e8 cmp r12, r0
 *   @0x2d95ec bhs 0x2d96bc <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x618>
 *   @0x2d95f0 mov r3, r2
 *   @0x2d95f4 asr r2, r3, #1
 *   @0x2d95f8 cmp r3, #0
 *   @0x2d95fc add r1, r4, r2, lsl #3
 *   @0x2d9600 bne 0x2d95e4 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x540>
 *   @0x2d9604 cmp r4, r5
 *   @0x2d9608 addne r2, sp, #64
 *   @0x2d960c addne r5, r5, #8
 *   @0x2d9610 vmovne.f32 s27, #1.000000e+00
 *   @0x2d9614 strne r2, [sp, #0x14]
 *   @0x2d9618 bne 0x2d9624 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x580>
 *   @0x2d961c b 0x2d9678 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x5d4>
 *   @0x2d9620 add r5, r5, #8
 *   @0x2d9624 ldr r7, [r5, #-0x8]
 *   @0x2d9628 ldr r3, [r8, #0x38]
 *   @0x2d962c add r3, r3, r7, lsl #3
 *   @0x2d9630 ldm r3, {r0, r1}
 *   @0x2d9634 stm r6, {r0, r1}
 *   @0x2d9638 vldr s15, [sp, #56]
 *   @0x2d963c vcmpe.f32 s16, s15
 *   @0x2d9640 vmrs APSR_nzcv, fpscr
 *   @0x2d9644 bhi 0x2d9670 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x5cc>
 *   @0x2d9648 vcmpe.f32 s17, s15
 *   @0x2d964c vmrs APSR_nzcv, fpscr
 *   @0x2d9650 blt 0x2d9670 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x5cc>
 *   @0x2d9654 vldr s15, [sp, #60]
 *   @0x2d9658 vcmpe.f32 s18, s15
 *   @0x2d965c vmrs APSR_nzcv, fpscr
 *   @0x2d9660 bhi 0x2d9670 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x5cc>
 *   @0x2d9664 vcmpe.f32 s19, s15
 *   @0x2d9668 vmrs APSR_nzcv, fpscr
 *   @0x2d966c bge 0x2d96cc <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x628>
 *   @0x2d9670 cmp r5, r4
 *   @0x2d9674 bne 0x2d9620 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x57c>
 *   @0x2d9678 ldr r3, [sp, #0x18]
 *   @0x2d967c add r10, r10, #1
 *   @0x2d9680 add r9, r9, #28
 *   @0x2d9684 cmp r10, r3
 *   @0x2d9688 bne 0x2d94e8 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x444>
 *   @0x2d968c mov r0, #1
 *   @0x2d9690 add sp, sp, #76
 *   @0x2d9694 vpop {d8, d9, d10, d11, d12, d13, d14}
 *   @0x2d9698 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2d969c mov r2, r3
 *   @0x2d96a0 mov r3, r0
 *   @0x2d96a4 rsb r3, r2, r3
 *   @0x2d96a8 add r4, r1, #8
 *   @0x2d96ac sub r0, r3, #1
 *   @0x2d96b0 b 0x2d9550 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x4ac>
 *   @0x2d96b4 mov r2, r3
 *   @0x2d96b8 mov r3, r0
 *   @0x2d96bc rsb r3, r2, r3
 *   @0x2d96c0 add r4, r1, #8
 *   @0x2d96c4 sub r0, r3, #1
 *   @0x2d96c8 b 0x2d95c4 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x520>
 *   @0x2d96cc ldr r0, [r11, #0xc]
 *   @0x2d96d0 mov r2, r6
 *   @0x2d96d4 ldr r1, [r11, #0x8]
 *   @0x2d96d8 add lr, sp, #64
 *   @0x2d96dc add r3, sp, #52
 *   @0x2d96e0 ldr r12, [r0]
 *   @0x2d96e4 add r1, r1, #12
 *   @0x2d96e8 str lr, [sp]
 *   @0x2d96ec str r10, [sp, #0x4]
 *   @0x2d96f0 ldr r12, [r12, #0x14]
 *   @0x2d96f4 blx r12
 *   @0x2d96f8 ldr r2, [sp, #0x20]
 *   @0x2d96fc vldr s15, [sp, #52]
 *   @0x2d9700 ldr r8, [r2, #0x4]
 *   @0x2d9704 vldr s14, [r8, #24]
 *   @0x2d9708 vcmpe.f32 s14, s15
 *   @0x2d970c vmrs APSR_nzcv, fpscr
 *   @0x2d9710 ble 0x2d9670 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x5cc>
 *   @0x2d9714 ldr r3, [r8, #0x30]
 *   @0x2d9718 ldr r3, [r3, r7, lsl #2]
 *   @0x2d971c tst r3, #4
 *   @0x2d9720 beq 0x2d983c <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x798>
 *   @0x2d9724 vldr s29, [pc, #296]
 *   @0x2d9728 vldr s28, [sp, #60]
 *   @0x2d972c vsub.f32 s28, s28, s24
 *   @0x2d9730 vldr s14, [sp, #64]
 *   @0x2d9734 vldr s15, [sp, #56]
 *   @0x2d9738 ldr r3, [r8, #0x80]
 *   @0x2d973c vldr s13, [sp, #68]
 *   @0x2d9740 ldr r2, [r8, #0x84]
 *   @0x2d9744 cmp r3, r2
 *   @0x2d9748 vmul.f32 s28, s28, s14
 *   @0x2d974c vsub.f32 s15, s15, s23
 *   @0x2d9750 vnmls.f32 s28, s15, s13
 *   @0x2d9754 blt 0x2d97e0 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x73c>
 *   @0x2d9758 cmp r3, #0
 *   @0x2d975c ldr r0, [r8, #0xd4]
 *   @0x2d9760 lslne r12, r3, #1
 *   @0x2d9764 addne r3, r12, r3, lsl #2
 *   @0x2d9768 moveq r1, #6144
 *   @0x2d976c moveq r12, #256
 *   @0x2d9770 lslne r1, r3, #3
 *   @0x2d9774 ldr r3, [r8, #0x88]
 *   @0x2d9778 str r12, [sp, #0xc]
 *   @0x2d977c str r2, [sp, #0x10]
 *   @0x2d9780 str r3, [sp, #0x28]
 *   @0x2d9784 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2d9788 ldr r2, [sp, #0x10]
 *   @0x2d978c ldr r1, [sp, #0x28]
 *   @0x2d9790 add r2, r2, r2, lsl #1
 *   @0x2d9794 lsl r3, r2, #3
 *   @0x2d9798 str r3, [sp, #0x10]
 *   @0x2d979c mov r2, r3
 *   @0x2d97a0 str r0, [sp, #0x2c]
 *   @0x2d97a4 bl 0xb65bc <memcpy@plt>
 *   @0x2d97a8 ldr r3, [sp, #0x10]
 *   @0x2d97ac ldr r0, [r8, #0xd4]
 *   @0x2d97b0 ldr r1, [sp, #0x28]
 *   @0x2d97b4 mov r2, r3
 *   @0x2d97b8 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2d97bc ldr r3, [sp, #0x2c]
 *   @0x2d97c0 ldr r2, [sp, #0x20]
 *   @0x2d97c4 vldr s14, [sp, #64]
 *   @0x2d97c8 ldr r12, [sp, #0xc]
 *   @0x2d97cc vldr s13, [sp, #68]
 *   @0x2d97d0 str r3, [r8, #0x88]
 *   @0x2d97d4 ldr r8, [r2, #0x4]
 *   @0x2d97d8 ldr r3, [r8, #0x80]
 *   @0x2d97dc str r12, [r8, #0x84]
 *   @0x2d97e0 vmul.f32 s10, s28, s26
 *   @0x2d97e4 vldr s11, [r8, #28]
 *   @0x2d97e8 vldr s12, [sp, #52]
 *   @0x2d97ec ldr r2, [r8, #0x88]
 *   @0x2d97f0 add r1, r3, r3, lsl #1
 *   @0x2d97f4 add r0, r3, #1
 *   @0x2d97f8 str r7, [r2, r1, lsl #3]
 *   @0x2d97fc add r3, r2, r1, lsl #3
 *   @0x2d9800 ldr r2, [sp, #0x1c]
 *   @0x2d9804 str r2, [r3, #0x4]
 *   @0x2d9808 vadd.f32 s15, s25, s29
 *   @0x2d980c vmla.f32 s15, s28, s10
 *   @0x2d9810 vdiv.f32 s15, s27, s15
 *   @0x2d9814 vmov.f32 s10, s27
 *   @0x2d9818 vstr s15, [r3, #20]
 *   @0x2d981c vmls.f32 s10, s11, s12
 *   @0x2d9820 vneg.f32 s14, s14
 *   @0x2d9824 vstr s10, [r3, #8]
 *   @0x2d9828 vneg.f32 s15, s13
 *   @0x2d982c vstr s14, [r3, #12]
 *   @0x2d9830 vstr s15, [r3, #16]
 *   @0x2d9834 str r0, [r8, #0x80]
 *   @0x2d9838 b 0x2d9670 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x5cc>
 *   @0x2d983c mov r0, r8
 *   @0x2d9840 bl 0x2d8a20 <_ZNK16b2ParticleSystem18GetParticleInvMassEv>
 *   @0x2d9844 ldr r3, [sp, #0x20]
 *   @0x2d9848 ldr r8, [r3, #0x4]
 *   @0x2d984c vmov s29, r0
 *   @0x2d9850 b 0x2d9728 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x684>
 *   @0x2d9854 andeq r0, r0, r0
 *   @0x2d9858 orrmi r0, r0, #0
 *   @0x2d985c .word 0x49000000
 *
 * ══ §17/28 CSprite::PreciseCollisionLine(int, tagYYRECT*, int, int, float, float, float, int, int, int, int)  0x1e52bc  size 1084  271 条（0x1e52bc..0x1e56f8）
 * @func 0x1e52bc 0x1e56f8  size 1084  271 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6910×4 / CSprite::PreciseCollisionLine(int, tagYYRECT*, int, int, float, float, float, int, int, int, int)+0xd4×2 / CSprite::PreciseCollisionLine(int, tagYYRECT*, int, int, float, float, float, int, int, int, int)+0x290×2 / CSprite::PreciseCollisionLine(int, tagYYRECT*, int, int, float, float, float, int, int, int, int)+0x3ec×2 / CSprite::UnpackWADMask(int) / CSprite::PreciseCollisionLine(int, tagYYRECT*, int, int, float, float, float, int, int, int, int)+0x418 / __aeabi_idivmod / CSprite::PreciseCollisionRectangle(int, tagYYRECT*, int, int, float, float, float, tagYYRECT*)
 * 字段偏移 top8: 0xa0×9 / 0xa4×9 / 0x1c×4 / 0x20×3 / 0x4×3 / 0x24×2 / 0x28×2 / 0x40×2
 * VFP 指令 95 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e52bc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1e52c0 vpush {d8, d9, d10, d11, d12, d13}
 *   @0x1e52c4 sub sp, sp, #52
 *   @0x1e52c8 vldr s20, [sp, #140]
 *   @0x1e52cc mov r4, r0
 *   @0x1e52d0 mov r7, r3
 *   @0x1e52d4 mov r10, r1
 *   @0x1e52d8 mov r11, r2
 *   @0x1e52dc ldr r8, [sp, #0x88]
 *   @0x1e52e0 vldr s21, [sp, #144]
 *   @0x1e52e4 ldr r6, [sp, #0x98]
 *   @0x1e52e8 ldr r5, [sp, #0x9c]
 *   @0x1e52ec bl 0x1e3994 <_ZN7CSprite13UnpackWADMaskEi>
 *   @0x1e52f0 ldrb r3, [r4, #0x31]
 *   @0x1e52f4 cmp r3, #0
 *   @0x1e52f8 moveq r10, #1
 *   @0x1e52fc beq 0x1e5390 <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0xd4>
 *   @0x1e5300 ldr r3, [r4, #0x18]
 *   @0x1e5304 cmp r3, #0
 *   @0x1e5308 ble 0x1e56d4 <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0x418>
 *   @0x1e530c ldr r9, [r4, #0x3c]
 *   @0x1e5310 mov r0, r10
 *   @0x1e5314 mov r1, r9
 *   @0x1e5318 bl 0x318dec <__aeabi_idivmod>
 *   @0x1e531c ldr r2, [sp, #0xa0]
 *   @0x1e5320 ldr r3, [sp, #0xa4]
 *   @0x1e5324 cmp r1, #0
 *   @0x1e5328 addlt r1, r1, r9
 *   @0x1e532c cmp r5, r3
 *   @0x1e5330 cmpne r6, r2
 *   @0x1e5334 movne r10, #0
 *   @0x1e5338 moveq r10, #1
 *   @0x1e533c bne 0x1e53a0 <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0xe4>
 *   @0x1e5340 cmp r5, r3
 *   @0x1e5344 str r6, [sp, #0x20]
 *   @0x1e5348 bge 0x1e56c0 <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0x404>
 *   @0x1e534c str r5, [sp, #0x24]
 *   @0x1e5350 ldr r2, [sp, #0xa0]
 *   @0x1e5354 ldr r5, [sp, #0xa4]
 *   @0x1e5358 str r2, [sp, #0x28]
 *   @0x1e535c vldr s14, [sp, #148]
 *   @0x1e5360 add r12, sp, #32
 *   @0x1e5364 str r8, [sp]
 *   @0x1e5368 vstr s20, [sp, #4]
 *   @0x1e536c vstr s21, [sp, #8]
 *   @0x1e5370 vstr s14, [sp, #12]
 *   @0x1e5374 mov r0, r4
 *   @0x1e5378 mov r2, r11
 *   @0x1e537c mov r3, r7
 *   @0x1e5380 str r12, [sp, #0x10]
 *   @0x1e5384 str r5, [sp, #0x2c]
 *   @0x1e5388 bl 0x1e4c24 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_>
 *   @0x1e538c mov r10, r0
 *   @0x1e5390 mov r0, r10
 *   @0x1e5394 add sp, sp, #52
 *   @0x1e5398 vpop {d8, d9, d10, d11, d12, d13}
 *   @0x1e539c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e53a0 vldr s14, [sp, #148]
 *   @0x1e53a4 vldr s18, [pc, #836]
 *   @0x1e53a8 vnmul.f32 s15, s14, s18
 *   @0x1e53ac vldr s17, [pc, #832]
 *   @0x1e53b0 str r1, [sp, #0x1c]
 *   @0x1e53b4 vdiv.f32 s15, s15, s17
 *   @0x1e53b8 vmov r0, s15
 *   @0x1e53bc bl 0xb6580 <sinf@plt>
 *   @0x1e53c0 vldr s15, [sp, #148]
 *   @0x1e53c4 vmul.f32 s18, s15, s18
 *   @0x1e53c8 vdiv.f32 s18, s18, s17
 *   @0x1e53cc vmov s16, r0
 *   @0x1e53d0 vmov r0, s18
 *   @0x1e53d4 bl 0xb658c <cosf@plt>
 *   @0x1e53d8 ldr r2, [sp, #0xa0]
 *   @0x1e53dc ldr r3, [sp, #0xa4]
 *   @0x1e53e0 ldr r1, [sp, #0x1c]
 *   @0x1e53e4 vmov s17, r0
 *   @0x1e53e8 rsb r0, r6, r2
 *   @0x1e53ec rsb r2, r5, r3
 *   @0x1e53f0 eor r12, r0, r0, asr #31
 *   @0x1e53f4 sub r12, r12, r0, asr #31
 *   @0x1e53f8 eor r3, r2, r2, asr #31
 *   @0x1e53fc sub r3, r3, r2, asr #31
 *   @0x1e5400 cmp r12, r3
 *   @0x1e5404 blt 0x1e5564 <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0x2a8>
 *   @0x1e5408 ldr r12, [sp, #0xa0]
 *   @0x1e540c cmp r6, r12
 *   @0x1e5410 ble 0x1e5434 <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0x178>
 *   @0x1e5414 ldr r12, [sp, #0xa4]
 *   @0x1e5418 mov r3, r6
 *   @0x1e541c rsb r2, r12, r5
 *   @0x1e5420 ldr r12, [sp, #0xa0]
 *   @0x1e5424 ldr r5, [sp, #0xa4]
 *   @0x1e5428 rsb r0, r12, r6
 *   @0x1e542c str r3, [sp, #0xa0]
 *   @0x1e5430 mov r6, r12
 *   @0x1e5434 vmov s14, r2
 *   @0x1e5438 ldr r3, [r11]
 *   @0x1e543c ldr r9, [r11, #0x8]
 *   @0x1e5440 vcvt.f32.s32 s22, s14
 *   @0x1e5444 cmp r6, r3
 *   @0x1e5448 movge r11, r6
 *   @0x1e544c movlt r11, r3
 *   @0x1e5450 vmov s14, r0
 *   @0x1e5454 ldr r3, [sp, #0xa0]
 *   @0x1e5458 cmp r9, r3
 *   @0x1e545c movge r9, r3
 *   @0x1e5460 cmp r9, r11
 *   @0x1e5464 vcvt.f32.s32 s15, s14
 *   @0x1e5468 vdiv.f32 s22, s22, s15
 *   @0x1e546c blt 0x1e5390 <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0xd4>
 *   @0x1e5470 vldr s15, [r4, #36]
 *   @0x1e5474 vldr s14, [r4, #40]
 *   @0x1e5478 lsl r1, r1, #3
 *   @0x1e547c vcvt.f32.s32 s26, s15
 *   @0x1e5480 vmov s15, r5
 *   @0x1e5484 vcvt.f32.s32 s25, s14
 *   @0x1e5488 vmov s14, r8
 *   @0x1e548c mov r8, r1
 *   @0x1e5490 vcvt.f32.s32 s24, s15
 *   @0x1e5494 vcvt.f32.s32 s23, s14
 *   @0x1e5498 rsb r0, r6, r11
 *   @0x1e549c rsb r3, r7, r11
 *   @0x1e54a0 add r11, r11, #1
 *   @0x1e54a4 vmov s15, r0
 *   @0x1e54a8 vcvt.f32.s32 s15, s15
 *   @0x1e54ac vmov.f32 s18, s24
 *   @0x1e54b0 vmla.f32 s18, s15, s22
 *   @0x1e54b4 vmov s15, r3
 *   @0x1e54b8 vsub.f32 s18, s18, s23
 *   @0x1e54bc vmul.f32 s14, s18, s16
 *   @0x1e54c0 vcvt.f32.s32 s19, s15
 *   @0x1e54c4 vmla.f32 s14, s19, s17
 *   @0x1e54c8 vdiv.f32 s14, s14, s20
 *   @0x1e54cc vadd.f32 s14, s14, s26
 *   @0x1e54d0 vmov r0, s14
 *   @0x1e54d4 bl 0xb6910 <floorf@plt>
 *   @0x1e54d8 vmul.f32 s15, s16, s19
 *   @0x1e54dc vnmls.f32 s15, s17, s18
 *   @0x1e54e0 vmov s14, r0
 *   @0x1e54e4 vdiv.f32 s15, s15, s21
 *   @0x1e54e8 vadd.f32 s15, s15, s25
 *   @0x1e54ec vcvt.s32.f32 s14, s14
 *   @0x1e54f0 vmov r0, s15
 *   @0x1e54f4 vmov r5, s14
 *   @0x1e54f8 bl 0xb6910 <floorf@plt>
 *   @0x1e54fc cmp r5, #0
 *   @0x1e5500 vmov s15, r0
 *   @0x1e5504 blt 0x1e554c <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0x290>
 *   @0x1e5508 ldr r3, [r4, #0x1c]
 *   @0x1e550c cmp r5, r3
 *   @0x1e5510 bge 0x1e554c <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0x290>
 *   @0x1e5514 vcvt.s32.f32 s15, s15
 *   @0x1e5518 vmov r2, s15
 *   @0x1e551c cmp r2, #0
 *   @0x1e5520 blt 0x1e554c <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0x290>
 *   @0x1e5524 ldr r1, [r4, #0x20]
 *   @0x1e5528 cmp r2, r1
 *   @0x1e552c bge 0x1e554c <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0x290>
 *   @0x1e5530 ldr r1, [r4, #0x40]
 *   @0x1e5534 add r1, r1, r8
 *   @0x1e5538 ldr r1, [r1, #0x4]
 *   @0x1e553c mla r3, r3, r2, r1
 *   @0x1e5540 ldrb r2, [r3, r5]
 *   @0x1e5544 cmp r2, #0
 *   @0x1e5548 bne 0x1e56e8 <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0x42c>
 *   @0x1e554c cmp r9, r11
 *   @0x1e5550 bge 0x1e5498 <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0x1dc>
 *   @0x1e5554 mov r0, r10
 *   @0x1e5558 add sp, sp, #52
 *   @0x1e555c vpop {d8, d9, d10, d11, d12, d13}
 *   @0x1e5560 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e5564 ldr r3, [sp, #0xa4]
 *   @0x1e5568 cmp r5, r3
 *   @0x1e556c ble 0x1e5590 <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0x2d4>
 *   @0x1e5570 ldr r12, [sp, #0xa0]
 *   @0x1e5574 mov r3, r5
 *   @0x1e5578 rsb r0, r12, r6
 *   @0x1e557c ldr r12, [sp, #0xa4]
 *   @0x1e5580 ldr r6, [sp, #0xa0]
 *   @0x1e5584 rsb r2, r12, r5
 *   @0x1e5588 str r3, [sp, #0xa4]
 *   @0x1e558c mov r5, r12
 *   @0x1e5590 vmov s14, r0
 *   @0x1e5594 ldr r3, [r11, #0x4]
 *   @0x1e5598 ldr r0, [r11, #0xc]
 *   @0x1e559c vcvt.f32.s32 s22, s14
 *   @0x1e55a0 ldr r9, [sp, #0xa4]
 *   @0x1e55a4 vmov s14, r2
 *   @0x1e55a8 cmp r5, r3
 *   @0x1e55ac movge r11, r5
 *   @0x1e55b0 movlt r11, r3
 *   @0x1e55b4 cmp r9, r0
 *   @0x1e55b8 movge r9, r0
 *   @0x1e55bc cmp r9, r11
 *   @0x1e55c0 vcvt.f32.s32 s15, s14
 *   @0x1e55c4 vdiv.f32 s22, s22, s15
 *   @0x1e55c8 blt 0x1e5390 <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0xd4>
 *   @0x1e55cc vldr s15, [r4, #36]
 *   @0x1e55d0 vldr s14, [r4, #40]
 *   @0x1e55d4 lsl r1, r1, #3
 *   @0x1e55d8 vcvt.f32.s32 s26, s15
 *   @0x1e55dc vmov s15, r6
 *   @0x1e55e0 vcvt.f32.s32 s25, s14
 *   @0x1e55e4 vmov s14, r7
 *   @0x1e55e8 mov r7, r1
 *   @0x1e55ec vcvt.f32.s32 s24, s15
 *   @0x1e55f0 vcvt.f32.s32 s23, s14
 *   @0x1e55f4 rsb r3, r5, r11
 *   @0x1e55f8 rsb r0, r8, r11
 *   @0x1e55fc add r11, r11, #1
 *   @0x1e5600 vmov s14, r3
 *   @0x1e5604 vmov s18, r0
 *   @0x1e5608 vcvt.f32.s32 s15, s14
 *   @0x1e560c vmov.f32 s19, s24
 *   @0x1e5610 vmla.f32 s19, s15, s22
 *   @0x1e5614 vcvt.f32.s32 s18, s18
 *   @0x1e5618 vmul.f32 s14, s18, s16
 *   @0x1e561c vsub.f32 s19, s19, s23
 *   @0x1e5620 vmla.f32 s14, s19, s17
 *   @0x1e5624 vdiv.f32 s14, s14, s20
 *   @0x1e5628 vadd.f32 s14, s14, s26
 *   @0x1e562c vmov r0, s14
 *   @0x1e5630 bl 0xb6910 <floorf@plt>
 *   @0x1e5634 vmul.f32 s15, s16, s19
 *   @0x1e5638 vnmls.f32 s15, s17, s18
 *   @0x1e563c vmov s14, r0
 *   @0x1e5640 vdiv.f32 s15, s15, s21
 *   @0x1e5644 vadd.f32 s15, s15, s25
 *   @0x1e5648 vcvt.s32.f32 s14, s14
 *   @0x1e564c vmov r0, s15
 *   @0x1e5650 vmov r6, s14
 *   @0x1e5654 bl 0xb6910 <floorf@plt>
 *   @0x1e5658 cmp r6, #0
 *   @0x1e565c vmov s15, r0
 *   @0x1e5660 blt 0x1e56a8 <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0x3ec>
 *   @0x1e5664 ldr r3, [r4, #0x1c]
 *   @0x1e5668 cmp r6, r3
 *   @0x1e566c bge 0x1e56a8 <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0x3ec>
 *   @0x1e5670 vcvt.s32.f32 s15, s15
 *   @0x1e5674 vmov r2, s15
 *   @0x1e5678 cmp r2, #0
 *   @0x1e567c blt 0x1e56a8 <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0x3ec>
 *   @0x1e5680 ldr r1, [r4, #0x20]
 *   @0x1e5684 cmp r2, r1
 *   @0x1e5688 bge 0x1e56a8 <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0x3ec>
 *   @0x1e568c ldr r1, [r4, #0x40]
 *   @0x1e5690 add r1, r1, r7
 *   @0x1e5694 ldr r1, [r1, #0x4]
 *   @0x1e5698 mla r3, r3, r2, r1
 *   @0x1e569c ldrb r2, [r3, r6]
 *   @0x1e56a0 cmp r2, #0
 *   @0x1e56a4 bne 0x1e56e8 <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0x42c>
 *   @0x1e56a8 cmp r11, r9
 *   @0x1e56ac ble 0x1e55f4 <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0x338>
 *   @0x1e56b0 mov r0, r10
 *   @0x1e56b4 add sp, sp, #52
 *   @0x1e56b8 vpop {d8, d9, d10, d11, d12, d13}
 *   @0x1e56bc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e56c0 cmp r5, r3
 *   @0x1e56c4 movlt r5, r3
 *   @0x1e56c8 str r3, [sp, #0x24]
 *   @0x1e56cc str r2, [sp, #0x28]
 *   @0x1e56d0 b 0x1e535c <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0xa0>
 *   @0x1e56d4 mov r10, #0
 *   @0x1e56d8 mov r0, r10
 *   @0x1e56dc add sp, sp, #52
 *   @0x1e56e0 vpop {d8, d9, d10, d11, d12, d13}
 *   @0x1e56e4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e56e8 mov r10, r2
 *   @0x1e56ec b 0x1e5390 <_ZN7CSprite20PreciseCollisionLineEiP9tagYYRECTiifffiiii+0xd4>
 *   @0x1e56f0 ldrdmi r0, r1, [r9], #-251
 *   @0x1e56f4 teqmi r4, #0
 *
 * ══ §18/28 CSprite::LoadFromChunk(YYSprite*, unsigned char*)  0x1e972c  size 1084  271 条（0x1e972c..0x1e9b68）
 * @func 0x1e972c 0x1e9b68  size 1084  271 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6994×4 / 0xb6700×4 / operator new[](unsigned int)×2 / CSprite::Clear() / CSprite::LoadFromChunk(YYSprite*, unsigned char*)+0x32c / operator new(unsigned int) / CSkeletonSprite::CSkeletonSprite(char*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int) / CSprite::LoadFromChunk(YYSprite*, unsigned char*)+0x3bc
 * 字段偏移 top8: 0x18×6 / 0x4×6 / 0x54×6 / 0x24×4 / 0x8×4 / 0x28×4 / 0x1c×3 / 0x20×3
 * VFP 指令 51 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e972c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1e9730 vpush {d8, d9, d10}
 *   @0x1e9734 mov r5, r1
 *   @0x1e9738 sub sp, sp, #20
 *   @0x1e973c mov r4, r0
 *   @0x1e9740 bl 0x1e6b4c <_ZN7CSprite5ClearEv>
 *   @0x1e9744 ldr r7, [r5, #0x1c]
 *   @0x1e9748 ldr r6, [r5, #0x20]
 *   @0x1e974c adds r7, r7, #0
 *   @0x1e9750 ldr r2, [r5, #0x18]
 *   @0x1e9754 ldr r12, [r5, #0x24]
 *   @0x1e9758 movne r7, #1
 *   @0x1e975c adds r6, r6, #0
 *   @0x1e9760 ldr r1, [r5, #0x2c]
 *   @0x1e9764 ldr r0, [r5, #0x38]
 *   @0x1e9768 movne r6, #1
 *   @0x1e976c ldr r3, [r5, #0x4]
 *   @0x1e9770 adds r12, r12, #0
 *   @0x1e9774 ldr r11, [r5, #0x8]
 *   @0x1e9778 ldr r10, [r5, #0xc]
 *   @0x1e977c movne r12, #1
 *   @0x1e9780 ldr r9, [r5, #0x10]
 *   @0x1e9784 adds r1, r1, #0
 *   @0x1e9788 ldr r8, [r5, #0x14]
 *   @0x1e978c str r2, [r4, #0xc]
 *   @0x1e9790 movne r1, #1
 *   @0x1e9794 ldr r2, [r5, #0x28]
 *   @0x1e9798 cmn r0, #1
 *   @0x1e979c str r2, [r4, #0x4]
 *   @0x1e97a0 ldr r2, [r5, #0x30]
 *   @0x1e97a4 str r3, [r4, #0x1c]
 *   @0x1e97a8 ldr r3, [r5, #0x34]
 *   @0x1e97ac strb r7, [r4, #0x32]
 *   @0x1e97b0 ldr r7, [pc, #0x3a4]
 *   @0x1e97b4 str r11, [r4, #0x20]
 *   @0x1e97b8 str r10, [r4, #0x8]
 *   @0x1e97bc add r7, pc, r7
 *   @0x1e97c0 str r9, [r4, #0x10]
 *   @0x1e97c4 str r8, [r4, #0x14]
 *   @0x1e97c8 strb r6, [r4, #0x33]
 *   @0x1e97cc strb r12, [r4, #0x34]
 *   @0x1e97d0 strb r1, [r4, #0x30]
 *   @0x1e97d4 str r2, [r4, #0x24]
 *   @0x1e97d8 str r0, [r4, #0x18]
 *   @0x1e97dc str r3, [r4, #0x28]
 *   @0x1e97e0 beq 0x1e99b8 <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x28c>
 *   @0x1e97e4 ldr r3, [pc, #0x374]
 *   @0x1e97e8 mov r2, #0
 *   @0x1e97ec str r2, [r4, #0x74]
 *   @0x1e97f0 add r6, r5, #60
 *   @0x1e97f4 ldr r3, [r7, r3]
 *   @0x1e97f8 ldrb r3, [r3]
 *   @0x1e97fc cmp r3, r2
 *   @0x1e9800 beq 0x1e9814 <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0xe8>
 *   @0x1e9804 cmp r0, r2
 *   @0x1e9808 bne 0x1e9814 <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0xe8>
 *   @0x1e980c ldr r0, [r6], #4
 *   @0x1e9810 str r0, [r4, #0x18]
 *   @0x1e9814 cmp r0, #532676608
 *   @0x1e9818 mvnhi r0, #0
 *   @0x1e981c bhi 0x1e9824 <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0xf8>
 *   @0x1e9820 lsl r0, r0, #2
 *   @0x1e9824 bl 0x27d14c <_Znaj>
 *   @0x1e9828 ldr r5, [r4, #0x18]
 *   @0x1e982c cmp r5, #0
 *   @0x1e9830 lsl lr, r5, #2
 *   @0x1e9834 movgt r3, #0
 *   @0x1e9838 str r0, [r4, #0x54]
 *   @0x1e983c bgt 0x1e9984 <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x258>
 *   @0x1e9840 ldr r3, [r6, r5, lsl #2]
 *   @0x1e9844 add r6, r6, lr
 *   @0x1e9848 cmp r3, #0
 *   @0x1e984c str r3, [r4, #0x64]
 *   @0x1e9850 ble 0x1e9a58 <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x32c>
 *   @0x1e9854 subs r3, r3, r5
 *   @0x1e9858 add r6, r6, #4
 *   @0x1e985c rsbs r5, r3, #0
 *   @0x1e9860 str r6, [r4, #0x68]
 *   @0x1e9864 adcs r5, r5, r3
 *   @0x1e9868 strb r5, [r4, #0x35]
 *   @0x1e986c ldr r2, [r4, #0x28]
 *   @0x1e9870 ldr r3, [r4, #0x24]
 *   @0x1e9874 ldr r1, [r4, #0x1c]
 *   @0x1e9878 mul r8, r2, r2
 *   @0x1e987c ldr r0, [r4, #0x20]
 *   @0x1e9880 mul r12, r3, r3
 *   @0x1e9884 rsb r3, r3, r1
 *   @0x1e9888 rsb r2, r2, r0
 *   @0x1e988c mul r3, r3, r3
 *   @0x1e9890 vmov s19, r8
 *   @0x1e9894 mul r2, r2, r2
 *   @0x1e9898 vmov s18, r12
 *   @0x1e989c vcvt.f32.s32 s19, s19
 *   @0x1e98a0 vmov s13, r3
 *   @0x1e98a4 vcvt.f32.s32 s18, s18
 *   @0x1e98a8 vadd.f32 s14, s18, s19
 *   @0x1e98ac vsqrt.f32 s15, s14
 *   @0x1e98b0 vcmp.f32 s15, s15
 *   @0x1e98b4 vcvt.f32.s32 s17, s13
 *   @0x1e98b8 vmrs APSR_nzcv, fpscr
 *   @0x1e98bc vmov s13, r2
 *   @0x1e98c0 vcvt.f32.s32 s16, s13
 *   @0x1e98c4 bne 0x1e9b1c <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x3f0>
 *   @0x1e98c8 vmov r0, s15
 *   @0x1e98cc bl 0xb6994 <ceilf@plt>
 *   @0x1e98d0 vadd.f32 s19, s17, s19
 *   @0x1e98d4 vsqrt.f32 s15, s19
 *   @0x1e98d8 vmov s20, r0
 *   @0x1e98dc vcmp.f32 s15, s15
 *   @0x1e98e0 vmrs APSR_nzcv, fpscr
 *   @0x1e98e4 bne 0x1e9b3c <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x410>
 *   @0x1e98e8 vadd.f32 s18, s18, s16
 *   @0x1e98ec vmov r0, s15
 *   @0x1e98f0 bl 0xb6994 <ceilf@plt>
 *   @0x1e98f4 vsqrt.f32 s15, s18
 *   @0x1e98f8 vmov s19, r0
 *   @0x1e98fc vcmp.f32 s15, s15
 *   @0x1e9900 vmrs APSR_nzcv, fpscr
 *   @0x1e9904 bne 0x1e9b4c <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x420>
 *   @0x1e9908 vadd.f32 s16, s17, s16
 *   @0x1e990c vmov r0, s15
 *   @0x1e9910 bl 0xb6994 <ceilf@plt>
 *   @0x1e9914 vsqrt.f32 s15, s16
 *   @0x1e9918 vmov s18, r0
 *   @0x1e991c vcmp.f32 s15, s15
 *   @0x1e9920 vmrs APSR_nzcv, fpscr
 *   @0x1e9924 bne 0x1e9b2c <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x400>
 *   @0x1e9928 vmov r0, s15
 *   @0x1e992c bl 0xb6994 <ceilf@plt>
 *   @0x1e9930 vcvt.s32.f32 s18, s18
 *   @0x1e9934 vcvt.s32.f32 s19, s19
 *   @0x1e9938 vmov r3, s18
 *   @0x1e993c vmov r1, s19
 *   @0x1e9940 vcvt.s32.f32 s20, s20
 *   @0x1e9944 vmov s13, r0
 *   @0x1e9948 vcvt.s32.f32 s13, s13
 *   @0x1e994c cmp r3, r1
 *   @0x1e9950 movlt r3, r1
 *   @0x1e9954 vmov r1, s20
 *   @0x1e9958 vmov r0, s13
 *   @0x1e995c cmp r3, r0
 *   @0x1e9960 movlt r3, r0
 *   @0x1e9964 cmp r1, r3
 *   @0x1e9968 strge r1, [r4, #0x2c]
 *   @0x1e996c strlt r3, [r4, #0x2c]
 *   @0x1e9970 mov r0, #1
 *   @0x1e9974 add sp, sp, #20
 *   @0x1e9978 vpop {d8, d9, d10}
 *   @0x1e997c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e9980 ldr r0, [r4, #0x54]
 *   @0x1e9984 ldr r2, [r6, r3]
 *   @0x1e9988 add r0, r0, r3
 *   @0x1e998c ldr r12, [pc, #0x1d0]
 *   @0x1e9990 add r3, r3, #4
 *   @0x1e9994 cmp r2, #0
 *   @0x1e9998 mov r1, r2
 *   @0x1e999c ldrne r1, [r7, r12]
 *   @0x1e99a0 ldrne r1, [r1]
 *   @0x1e99a4 addne r1, r1, r2
 *   @0x1e99a8 cmp r3, lr
 *   @0x1e99ac str r1, [r0]
 *   @0x1e99b0 bne 0x1e9980 <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x254>
 *   @0x1e99b4 b 0x1e9840 <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x114>
 *   @0x1e99b8 ldr r1, [r5, #0x40]
 *   @0x1e99bc ldr r0, [pc, #0x19c]
 *   @0x1e99c0 str r1, [r4, #0x74]
 *   @0x1e99c4 ldr r0, [r7, r0]
 *   @0x1e99c8 ldrb r12, [r0]
 *   @0x1e99cc cmp r12, #0
 *   @0x1e99d0 addne r6, r5, #76
 *   @0x1e99d4 addeq r6, r5, #68
 *   @0x1e99d8 ldrne r12, [r5, #0x48]
 *   @0x1e99dc ldrne r5, [r5, #0x44]
 *   @0x1e99e0 strne r12, [r4, #0x70]
 *   @0x1e99e4 mov r12, #0
 *   @0x1e99e8 strne r5, [r4, #0x6c]
 *   @0x1e99ec cmp r1, #0
 *   @0x1e99f0 str r12, [r4, #0x18]
 *   @0x1e99f4 beq 0x1e9b08 <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x3dc>
 *   @0x1e99f8 cmp r1, #1
 *   @0x1e99fc beq 0x1e9a64 <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x338>
 *   @0x1e9a00 cmp r1, #2
 *   @0x1e9a04 bne 0x1e9970 <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x244>
 *   @0x1e9a08 ldr r10, [r6, #0x4]
 *   @0x1e9a0c mov r0, #12
 *   @0x1e9a10 ldr r8, [r6, #0x8]
 *   @0x1e9a14 ldr r11, [r6, #0xc]
 *   @0x1e9a18 ldr r9, [r6, #0x10]
 *   @0x1e9a1c ldr r7, [r6, #0x14]
 *   @0x1e9a20 str r12, [r4, #0x54]
 *   @0x1e9a24 bl 0x27c524 <_Znwj>
 *   @0x1e9a28 mov r3, r8
 *   @0x1e9a2c str r11, [sp]
 *   @0x1e9a30 mov r2, r10
 *   @0x1e9a34 str r9, [sp, #0x4]
 *   @0x1e9a38 add r1, r6, #24
 *   @0x1e9a3c str r7, [sp, #0x8]
 *   @0x1e9a40 mov r5, r0
 *   @0x1e9a44 bl 0xbd86c <_ZN15CSkeletonSpriteC2EPcjjjjj>
 *   @0x1e9a48 mvn r3, #-2147483648
 *   @0x1e9a4c str r5, [r4, #0x58]
 *   @0x1e9a50 str r3, [r4, #0x18]
 *   @0x1e9a54 b 0x1e9970 <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x244>
 *   @0x1e9a58 mov r3, #0
 *   @0x1e9a5c str r3, [r4, #0x68]
 *   @0x1e9a60 b 0x1e986c <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x140>
 *   @0x1e9a64 ldr r1, [r6]
 *   @0x1e9a68 str r12, [r4, #0x54]
 *   @0x1e9a6c cmp r1, #7
 *   @0x1e9a70 addle r1, r6, #4
 *   @0x1e9a74 ble 0x1e9ae8 <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x3bc>
 *   @0x1e9a78 ldr r8, [r6, #0x4]
 *   @0x1e9a7c add r6, r6, #8
 *   @0x1e9a80 cmp r8, #532676608
 *   @0x1e9a84 lsl r5, r8, #2
 *   @0x1e9a88 mvnhi r0, #0
 *   @0x1e9a8c movls r0, r5
 *   @0x1e9a90 bl 0x27d14c <_Znaj>
 *   @0x1e9a94 cmp r8, #0
 *   @0x1e9a98 movgt r3, #0
 *   @0x1e9a9c str r0, [r4, #0x54]
 *   @0x1e9aa0 bgt 0x1e9aac <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x380>
 *   @0x1e9aa4 b 0x1e9adc <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x3b0>
 *   @0x1e9aa8 ldr r0, [r4, #0x54]
 *   @0x1e9aac ldr r2, [r6, r3]
 *   @0x1e9ab0 add r0, r0, r3
 *   @0x1e9ab4 ldr r12, [pc, #0xa8]
 *   @0x1e9ab8 add r3, r3, #4
 *   @0x1e9abc cmp r2, #0
 *   @0x1e9ac0 mov r1, r2
 *   @0x1e9ac4 ldrne r1, [r7, r12]
 *   @0x1e9ac8 ldrne r1, [r1]
 *   @0x1e9acc addne r1, r1, r2
 *   @0x1e9ad0 cmp r3, r5
 *   @0x1e9ad4 str r1, [r0]
 *   @0x1e9ad8 bne 0x1e9aa8 <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x37c>
 *   @0x1e9adc ldr r2, [r4, #0x24]
 *   @0x1e9ae0 add r1, r6, r5
 *   @0x1e9ae4 ldr r3, [r4, #0x28]
 *   @0x1e9ae8 mov r12, #1
 *   @0x1e9aec mov r0, r4
 *   @0x1e9af0 strb r12, [r4, #0x78]
 *   @0x1e9af4 bl 0x1e838c <_ZN7CSprite12BuildSWFDataEPcii>
 *   @0x1e9af8 mov r0, #1
 *   @0x1e9afc add sp, sp, #20
 *   @0x1e9b00 vpop {d8, d9, d10}
 *   @0x1e9b04 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e9b08 ldrb r3, [r0]
 *   @0x1e9b0c cmp r3, #0
 *   @0x1e9b10 moveq r0, r1
 *   @0x1e9b14 beq 0x1e9820 <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0xf4>
 *   @0x1e9b18 b 0x1e980c <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0xe0>
 *   @0x1e9b1c vmov r0, s14
 *   @0x1e9b20 bl 0xb6700 <sqrtf@plt>
 *   @0x1e9b24 vmov s15, r0
 *   @0x1e9b28 b 0x1e98c8 <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x19c>
 *   @0x1e9b2c vmov r0, s16
 *   @0x1e9b30 bl 0xb6700 <sqrtf@plt>
 *   @0x1e9b34 vmov s15, r0
 *   @0x1e9b38 b 0x1e9928 <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x1fc>
 *   @0x1e9b3c vmov r0, s19
 *   @0x1e9b40 bl 0xb6700 <sqrtf@plt>
 *   @0x1e9b44 vmov s15, r0
 *   @0x1e9b48 b 0x1e98e8 <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x1bc>
 *   @0x1e9b4c vmov r0, s18
 *   @0x1e9b50 bl 0xb6700 <sqrtf@plt>
 *   @0x1e9b54 vmov s15, r0
 *   @0x1e9b58 b 0x1e9908 <_ZN7CSprite13LoadFromChunkEP8YYSpritePh+0x1dc>
 *   @0x1e9b5c mlaeq r0, r4, r4, r8
 *   @0x1e9b60 .word 0xffffbcd4
 *   @0x1e9b64 .word 0xffffbcf4
 *
 * ══ §19/28 JS_Array_prototype_join(RValue&, CInstance*, CInstance*, int, RValue*)  0x2596bc  size 1084  271 条（0x2596bc..0x259af8）
 * @func 0x2596bc 0x259af8  size 1084  271 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FREE_RValue__Pre(RValue*)×4 / YYFree(void const*)×3 / F_JS_ToString(RValue&, RValue*)×2 / YYGetString(RValue const*, int)×2 / F_JS_Object_Get(YYObjectBase*, RValue*, char const*)×2 / 0xb6538×2 / YYAlloc(int)×2 / 0xb65bc×2
 * 字段偏移 top8: 0x28×11 / 0x20×10 / 0x24×7 / 0xc×4 / 0x14×3 / 0x38×3 / 0x48×3 / 0x8×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2596bc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2596c0 sub sp, sp, #148
 *   @0x2596c4 ldr r2, [pc, #0x414]
 *   @0x2596c8 cmp r3, #0
 *   @0x2596cc str r0, [sp, #0x1c]
 *   @0x2596d0 mov r11, r1
 *   @0x2596d4 ldr r2, [pc, r2]
 *   @0x2596d8 str r2, [sp, #0x14]
 *   @0x2596dc ldr r0, [sp, #0x14]
 *   @0x2596e0 mov r2, #5
 *   @0x2596e4 ldr r1, [sp, #0xb8]
 *   @0x2596e8 str r2, [sp, #0x38]
 *   @0x2596ec ldr r3, [r0]
 *   @0x2596f0 str r3, [sp, #0x8c]
 *   @0x2596f4 ble 0x259a88 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x3cc>
 *   @0x2596f8 add r4, sp, #44
 *   @0x2596fc mov r0, r4
 *   @0x259700 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x259704 cmp r0, #1
 *   @0x259708 beq 0x259a98 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x3dc>
 *   @0x25970c mov r0, r4
 *   @0x259710 mov r1, #0
 *   @0x259714 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x259718 str r0, [sp, #0xc]
 *   @0x25971c add r2, sp, #60
 *   @0x259720 str r2, [sp, #0x18]
 *   @0x259724 ldr r2, [pc, #0x3b8]
 *   @0x259728 mov r0, r11
 *   @0x25972c add r1, sp, #60
 *   @0x259730 mov r7, #5
 *   @0x259734 add r2, pc, r2
 *   @0x259738 str r7, [sp, #0x48]
 *   @0x25973c bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x259740 add r0, sp, #60
 *   @0x259744 mov r1, #0
 *   @0x259748 mov r4, #0
 *   @0x25974c bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x259750 str r4, [sp, #0x20]
 *   @0x259754 str r4, [sp, #0x24]
 *   @0x259758 str r4, [sp, #0x28]
 *   @0x25975c cmp r0, #0
 *   @0x259760 str r0, [sp, #0x8]
 *   @0x259764 beq 0x259a80 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x3c4>
 *   @0x259768 ldr r3, [pc, #0x378]
 *   @0x25976c add r5, sp, #108
 *   @0x259770 add r6, sp, #76
 *   @0x259774 add r3, pc, r3
 *   @0x259778 str r3, [sp, #0x4]
 *   @0x25977c mov r3, r4
 *   @0x259780 mov r1, #32
 *   @0x259784 ldr r2, [sp, #0x4]
 *   @0x259788 mov r0, r5
 *   @0x25978c bl 0xb65c8 <snprintf@plt>
 *   @0x259790 mov r2, r5
 *   @0x259794 mov r0, r11
 *   @0x259798 mov r1, r6
 *   @0x25979c str r7, [sp, #0x58]
 *   @0x2597a0 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x2597a4 ldr r2, [sp, #0x58]
 *   @0x2597a8 bic r3, r2, #-16777216
 *   @0x2597ac cmp r3, #12
 *   @0x2597b0 beq 0x2599b0 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x2f4>
 *   @0x2597b4 mvn r1, #-16777216
 *   @0x2597b8 cmp r3, r1
 *   @0x2597bc beq 0x2599a8 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x2ec>
 *   @0x2597c0 cmp r3, #5
 *   @0x2597c4 beq 0x2599b0 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x2f4>
 *   @0x2597c8 add r8, sp, #92
 *   @0x2597cc mov r1, r6
 *   @0x2597d0 str r7, [sp, #0x68]
 *   @0x2597d4 mov r0, r8
 *   @0x2597d8 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x2597dc cmp r0, #1
 *   @0x2597e0 beq 0x259aa8 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x3ec>
 *   @0x2597e4 mov r0, r8
 *   @0x2597e8 mov r1, #0
 *   @0x2597ec bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x2597f0 subs r3, r0, #0
 *   @0x2597f4 str r3, [sp, #0x10]
 *   @0x2597f8 beq 0x2598a0 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x1e4>
 *   @0x2597fc bl 0xb6538 <strlen@plt>
 *   @0x259800 ldr r2, [sp, #0x28]
 *   @0x259804 ldr r3, [sp, #0x24]
 *   @0x259808 add r1, r0, #1
 *   @0x25980c mov r9, r0
 *   @0x259810 mvn r0, r2
 *   @0x259814 add r0, r3, r0
 *   @0x259818 cmp r1, r0
 *   @0x25981c ble 0x259884 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x1c8>
 *   @0x259820 cmp r3, #0
 *   @0x259824 add r2, r1, r2
 *   @0x259828 ldr r10, [sp, #0x20]
 *   @0x25982c moveq r3, r1
 *   @0x259830 add r3, r3, r3, lsl #1
 *   @0x259834 add r3, r3, r3, lsr #31
 *   @0x259838 asr r3, r3, #1
 *   @0x25983c cmp r3, r2
 *   @0x259840 addlt r2, r2, r2, lsl #1
 *   @0x259844 addlt r2, r2, r2, lsr #31
 *   @0x259848 asrlt r3, r2, #1
 *   @0x25984c str r3, [sp]
 *   @0x259850 mov r0, r3
 *   @0x259854 bl 0xcef4c <_Z7YYAlloci>
 *   @0x259858 ldr r2, [sp, #0x24]
 *   @0x25985c mov r1, r10
 *   @0x259860 str r0, [sp, #0x20]
 *   @0x259864 bl 0xb65bc <memcpy@plt>
 *   @0x259868 ldr r3, [sp]
 *   @0x25986c cmp r10, #0
 *   @0x259870 str r3, [sp, #0x24]
 *   @0x259874 beq 0x259880 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x1c4>
 *   @0x259878 mov r0, r10
 *   @0x25987c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x259880 ldr r2, [sp, #0x28]
 *   @0x259884 ldr r0, [sp, #0x20]
 *   @0x259888 ldr r1, [sp, #0x10]
 *   @0x25988c add r0, r0, r2
 *   @0x259890 bl 0xb65a4 <strcpy@plt>
 *   @0x259894 ldr r3, [sp, #0x28]
 *   @0x259898 add r9, r3, r9
 *   @0x25989c str r9, [sp, #0x28]
 *   @0x2598a0 ldr r3, [sp, #0x68]
 *   @0x2598a4 sub r3, r3, #1
 *   @0x2598a8 bic r3, r3, #-16777216
 *   @0x2598ac bic r3, r3, #3
 *   @0x2598b0 cmp r3, #0
 *   @0x2598b4 beq 0x259a74 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x3b8>
 *   @0x2598b8 ldr r2, [sp, #0x58]
 *   @0x2598bc mov r8, #0
 *   @0x2598c0 sub r2, r2, #1
 *   @0x2598c4 bic r2, r2, #-16777216
 *   @0x2598c8 bic r2, r2, #3
 *   @0x2598cc cmp r2, #0
 *   @0x2598d0 beq 0x2599b8 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x2fc>
 *   @0x2598d4 ldr r0, [sp, #0x8]
 *   @0x2598d8 add r4, r4, #1
 *   @0x2598dc cmp r4, r0
 *   @0x2598e0 beq 0x2599d0 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x314>
 *   @0x2598e4 eor r8, r8, #1
 *   @0x2598e8 cmp r4, #0
 *   @0x2598ec moveq r8, #0
 *   @0x2598f0 andne r8, r8, #1
 *   @0x2598f4 cmp r8, #0
 *   @0x2598f8 beq 0x25977c <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x2598fc ldr r0, [sp, #0xc]
 *   @0x259900 cmp r0, #0
 *   @0x259904 beq 0x25977c <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x259908 bl 0xb6538 <strlen@plt>
 *   @0x25990c ldr r2, [sp, #0x28]
 *   @0x259910 ldr r3, [sp, #0x24]
 *   @0x259914 add r1, r0, #1
 *   @0x259918 mov r8, r0
 *   @0x25991c mvn r0, r2
 *   @0x259920 add r0, r3, r0
 *   @0x259924 cmp r1, r0
 *   @0x259928 ble 0x259988 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x2cc>
 *   @0x25992c cmp r3, #0
 *   @0x259930 add r2, r1, r2
 *   @0x259934 ldr r10, [sp, #0x20]
 *   @0x259938 moveq r3, r1
 *   @0x25993c add r3, r3, r3, lsl #1
 *   @0x259940 add r3, r3, r3, lsr #31
 *   @0x259944 asr r9, r3, #1
 *   @0x259948 cmp r9, r2
 *   @0x25994c addlt r2, r2, r2, lsl #1
 *   @0x259950 addlt r2, r2, r2, lsr #31
 *   @0x259954 asrlt r9, r2, #1
 *   @0x259958 mov r0, r9
 *   @0x25995c bl 0xcef4c <_Z7YYAlloci>
 *   @0x259960 ldr r2, [sp, #0x24]
 *   @0x259964 mov r1, r10
 *   @0x259968 str r0, [sp, #0x20]
 *   @0x25996c bl 0xb65bc <memcpy@plt>
 *   @0x259970 cmp r10, #0
 *   @0x259974 str r9, [sp, #0x24]
 *   @0x259978 beq 0x259984 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x2c8>
 *   @0x25997c mov r0, r10
 *   @0x259980 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x259984 ldr r2, [sp, #0x28]
 *   @0x259988 ldr r0, [sp, #0x20]
 *   @0x25998c ldr r1, [sp, #0xc]
 *   @0x259990 add r0, r0, r2
 *   @0x259994 bl 0xb65a4 <strcpy@plt>
 *   @0x259998 ldr r3, [sp, #0x28]
 *   @0x25999c add r8, r3, r8
 *   @0x2599a0 str r8, [sp, #0x28]
 *   @0x2599a4 b 0x25977c <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x2599a8 mov r8, #1
 *   @0x2599ac b 0x2598c0 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x204>
 *   @0x2599b0 mov r8, #0
 *   @0x2599b4 b 0x2598c0 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x204>
 *   @0x2599b8 mov r0, r6
 *   @0x2599bc add r4, r4, #1
 *   @0x2599c0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x2599c4 ldr r0, [sp, #0x8]
 *   @0x2599c8 cmp r4, r0
 *   @0x2599cc bne 0x2598e4 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x228>
 *   @0x2599d0 ldr r3, [sp, #0x28]
 *   @0x2599d4 cmp r3, #0
 *   @0x2599d8 beq 0x259a80 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x3c4>
 *   @0x2599dc ldr r1, [sp, #0x20]
 *   @0x2599e0 ldr r0, [sp, #0x1c]
 *   @0x2599e4 mov r3, #0
 *   @0x2599e8 str r3, [sp, #0x28]
 *   @0x2599ec bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x2599f0 ldr r3, [sp, #0x38]
 *   @0x2599f4 sub r3, r3, #1
 *   @0x2599f8 bic r3, r3, #-16777216
 *   @0x2599fc bic r3, r3, #3
 *   @0x259a00 cmp r3, #0
 *   @0x259a04 beq 0x259ad0 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x414>
 *   @0x259a08 ldr r1, [sp, #0x48]
 *   @0x259a0c mov r3, #0
 *   @0x259a10 str r3, [sp, #0x34]
 *   @0x259a14 mov r2, #5
 *   @0x259a18 sub r1, r1, #1
 *   @0x259a1c str r3, [sp, #0x2c]
 *   @0x259a20 bic r3, r1, #-16777216
 *   @0x259a24 str r2, [sp, #0x38]
 *   @0x259a28 bic r3, r3, #3
 *   @0x259a2c cmp r3, #0
 *   @0x259a30 beq 0x259ac4 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x408>
 *   @0x259a34 ldr r0, [sp, #0x20]
 *   @0x259a38 mov r3, #0
 *   @0x259a3c mov r2, #5
 *   @0x259a40 str r3, [sp, #0x44]
 *   @0x259a44 cmp r0, r3
 *   @0x259a48 str r3, [sp, #0x3c]
 *   @0x259a4c str r2, [sp, #0x48]
 *   @0x259a50 beq 0x259a58 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x39c>
 *   @0x259a54 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x259a58 ldr r1, [sp, #0x14]
 *   @0x259a5c ldr r2, [sp, #0x8c]
 *   @0x259a60 ldr r3, [r1]
 *   @0x259a64 cmp r2, r3
 *   @0x259a68 bne 0x259adc <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x420>
 *   @0x259a6c add sp, sp, #148
 *   @0x259a70 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x259a74 mov r0, r8
 *   @0x259a78 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x259a7c b 0x2598b8 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x1fc>
 *   @0x259a80 add r1, sp, #40
 *   @0x259a84 b 0x2599e0 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x324>
 *   @0x259a88 ldr r1, [pc, #0x5c]
 *   @0x259a8c add r1, pc, r1
 *   @0x259a90 str r1, [sp, #0xc]
 *   @0x259a94 b 0x25971c <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x60>
 *   @0x259a98 ldr r0, [pc, #0x50]
 *   @0x259a9c add r0, pc, r0
 *   @0x259aa0 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x259aa4 b 0x259a58 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x39c>
 *   @0x259aa8 ldr r0, [pc, #0x44]
 *   @0x259aac add r0, pc, r0
 *   @0x259ab0 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x259ab4 ldr r0, [sp, #0x20]
 *   @0x259ab8 cmp r0, #0
 *   @0x259abc bne 0x259a54 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x398>
 *   @0x259ac0 b 0x259a58 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x39c>
 *   @0x259ac4 add r0, sp, #60
 *   @0x259ac8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x259acc b 0x259a34 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x378>
 *   @0x259ad0 add r0, sp, #44
 *   @0x259ad4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x259ad8 b 0x259a08 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x34c>
 *   @0x259adc bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x259ae0 andseq r4, r9, r12, ror r2
 *   @0x259ae4 andeq r7, sp, r8, lsr r1
 *   @0x259ae8 andeq r12, pc, r12, ror #13
 *   @0x259aec muleq sp, r8, r10
 *   @0x259af0 andeq sp, pc, r4, asr r1
 *   @0x259af4 andeq sp, pc, r8, ror r1
 *
 * ══ §20/28 anon_2d85e0  0x2d85e0  size 1084  271 条（0x2d85e0..0x2d8a1c）
 * @func 0x2d85e0 0x2d8a1c  size 1084  271 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2d85e0+0x20 / anon_2d85e0+0x140 / anon_2d85e0+0x130 / anon_2d85e0+0x1c4 / anon_2d85e0+0x1b4 / anon_2d85e0+0x230 / b2ParticleSystem::GetParticleMass() const / 0xfebce648
 * 字段偏移 top8: 0x4×9 / 0xc×7 / 0x18×4 / 0x14×3 / 0x8×2 / 0x1c×2 / 0x40×2 / 0x2c×1
 * VFP 指令 130 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d85e0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2d85e4 vpush {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x2d85e8 mov r10, r1
 *   @0x2d85ec ldrb r8, [r1, #0x2c]
 *   @0x2d85f0 sub sp, sp, #68
 *   @0x2d85f4 mov r7, r0
 *   @0x2d85f8 cmp r8, #0
 *   @0x2d85fc beq 0x2d8610 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x54>
 *   @0x2d8600 mov r0, #1
 *   @0x2d8604 add sp, sp, #68
 *   @0x2d8608 vpop {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x2d860c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2d8610 ldr r3, [r7, #0x4]
 *   @0x2d8614 ldr r0, [r1, #0xc]
 *   @0x2d8618 ldr r9, [r1, #0x8]
 *   @0x2d861c ldr r2, [r3, #0x68]
 *   @0x2d8620 ldr r3, [r3, #0x70]
 *   @0x2d8624 ldr r1, [r0]
 *   @0x2d8628 str r3, [sp, #0xc]
 *   @0x2d862c ldr r3, [r1, #0xc]
 *   @0x2d8630 ldr r1, [sp, #0xc]
 *   @0x2d8634 add r2, r1, r2, lsl #3
 *   @0x2d8638 str r2, [sp, #0x14]
 *   @0x2d863c blx r3
 *   @0x2d8640 cmp r0, #0
 *   @0x2d8644 str r0, [sp, #0x18]
 *   @0x2d8648 ble 0x2d8600 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x44>
 *   @0x2d864c vmov.f32 s25, #1.000000e+00
 *   @0x2d8650 ldr r2, [sp, #0x14]
 *   @0x2d8654 ldr r1, [sp, #0xc]
 *   @0x2d8658 vldr s24, [pc, #940]
 *   @0x2d865c vldr s23, [pc, #940]
 *   @0x2d8660 vldr s22, [pc, #940]
 *   @0x2d8664 rsb r3, r1, r2
 *   @0x2d8668 vldr s26, [pc, #936]
 *   @0x2d866c vldr s27, [pc, #936]
 *   @0x2d8670 asr r3, r3, #3
 *   @0x2d8674 str r3, [sp, #0x1c]
 *   @0x2d8678 ldr r2, [r10, #0x18]
 *   @0x2d867c rsb r3, r8, r8, lsl #3
 *   @0x2d8680 ldr r0, [r7, #0x4]
 *   @0x2d8684 vldr s14, [r0, #24]
 *   @0x2d8688 add r3, r2, r3, lsl #2
 *   @0x2d868c vldr s18, [r3]
 *   @0x2d8690 vsub.f32 s18, s18, s14
 *   @0x2d8694 vldr s15, [r0, #28]
 *   @0x2d8698 vldr s20, [r3, #4]
 *   @0x2d869c vldr s19, [r3, #8]
 *   @0x2d86a0 vldr s21, [r3, #12]
 *   @0x2d86a4 ldr r12, [sp, #0x1c]
 *   @0x2d86a8 ldr r4, [sp, #0xc]
 *   @0x2d86ac vmul.f32 s13, s18, s15
 *   @0x2d86b0 vsub.f32 s20, s20, s14
 *   @0x2d86b4 vmov.f32 s12, s23
 *   @0x2d86b8 vmla.f32 s12, s13, s24
 *   @0x2d86bc vmov.f32 s13, s22
 *   @0x2d86c0 vmla.f32 s13, s20, s15
 *   @0x2d86c4 vcvt.u32.f32 s12, s12
 *   @0x2d86c8 vcvt.u32.f32 s13, s13
 *   @0x2d86cc vmov r2, s12
 *   @0x2d86d0 vmov r5, s13
 *   @0x2d86d4 vadd.f32 s19, s14, s19
 *   @0x2d86d8 vadd.f32 s21, s14, s21
 *   @0x2d86dc add r5, r2, r5, lsl #20
 *   @0x2d86e0 cmp r12, #0
 *   @0x2d86e4 ble 0x2d8720 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x164>
 *   @0x2d86e8 asr r3, r12, #1
 *   @0x2d86ec add r1, r4, r3, lsl #3
 *   @0x2d86f0 ldr r2, [r1, #0x4]
 *   @0x2d86f4 cmp r5, r2
 *   @0x2d86f8 bls 0x2d8710 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x154>
 *   @0x2d86fc b 0x2d8838 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x27c>
 *   @0x2d8700 ldr r12, [r1, #0x4]
 *   @0x2d8704 cmp r5, r12
 *   @0x2d8708 bhi 0x2d8840 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x284>
 *   @0x2d870c mov r3, r2
 *   @0x2d8710 asr r2, r3, #1
 *   @0x2d8714 cmp r3, #0
 *   @0x2d8718 add r1, r4, r2, lsl #3
 *   @0x2d871c bne 0x2d8700 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x144>
 *   @0x2d8720 vmul.f32 s14, s19, s15
 *   @0x2d8724 ldr r3, [sp, #0x14]
 *   @0x2d8728 mov r5, r4
 *   @0x2d872c rsb r12, r4, r3
 *   @0x2d8730 asr r12, r12, #3
 *   @0x2d8734 vmov.f32 s13, s23
 *   @0x2d8738 vmla.f32 s13, s14, s24
 *   @0x2d873c vmov.f32 s14, s13
 *   @0x2d8740 vmov.f32 s13, s22
 *   @0x2d8744 vmla.f32 s13, s21, s15
 *   @0x2d8748 vcvt.u32.f32 s14, s14
 *   @0x2d874c vcvt.u32.f32 s15, s13
 *   @0x2d8750 vmov r1, s14
 *   @0x2d8754 vmov r6, s15
 *   @0x2d8758 add r6, r1, r6, lsl #20
 *   @0x2d875c cmp r12, #0
 *   @0x2d8760 ble 0x2d87a4 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x1e8>
 *   @0x2d8764 asr r3, r12, #1
 *   @0x2d8768 add r1, r4, r3, lsl #3
 *   @0x2d876c ldr r2, [r1, #0x4]
 *   @0x2d8770 cmp r6, r2
 *   @0x2d8774 movhs r2, r3
 *   @0x2d8778 movhs r3, r12
 *   @0x2d877c blo 0x2d8794 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x1d8>
 *   @0x2d8780 b 0x2d8850 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x294>
 *   @0x2d8784 ldr r12, [r1, #0x4]
 *   @0x2d8788 cmp r6, r12
 *   @0x2d878c bhs 0x2d8850 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x294>
 *   @0x2d8790 mov r3, r2
 *   @0x2d8794 asr r2, r3, #1
 *   @0x2d8798 cmp r3, #0
 *   @0x2d879c add r1, r4, r2, lsl #3
 *   @0x2d87a0 bne 0x2d8784 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x1c8>
 *   @0x2d87a4 cmp r4, r5
 *   @0x2d87a8 beq 0x2d8818 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x25c>
 *   @0x2d87ac add r2, sp, #44
 *   @0x2d87b0 add r5, r5, #8
 *   @0x2d87b4 add r11, sp, #32
 *   @0x2d87b8 str r2, [sp, #0x10]
 *   @0x2d87bc b 0x2d87c8 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x20c>
 *   @0x2d87c0 ldr r0, [r7, #0x4]
 *   @0x2d87c4 add r5, r5, #8
 *   @0x2d87c8 ldr r6, [r5, #-0x8]
 *   @0x2d87cc ldr r3, [r0, #0x38]
 *   @0x2d87d0 lsl r6, r6, #3
 *   @0x2d87d4 add r3, r3, r6
 *   @0x2d87d8 vldr s16, [r3]
 *   @0x2d87dc vcmpe.f32 s18, s16
 *   @0x2d87e0 vldr s17, [r3, #4]
 *   @0x2d87e4 vmrs APSR_nzcv, fpscr
 *   @0x2d87e8 bhi 0x2d8810 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x254>
 *   @0x2d87ec vcmpe.f32 s19, s16
 *   @0x2d87f0 vmrs APSR_nzcv, fpscr
 *   @0x2d87f4 blt 0x2d8810 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x254>
 *   @0x2d87f8 vcmpe.f32 s20, s17
 *   @0x2d87fc vmrs APSR_nzcv, fpscr
 *   @0x2d8800 bhi 0x2d8810 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x254>
 *   @0x2d8804 vcmpe.f32 s21, s17
 *   @0x2d8808 vmrs APSR_nzcv, fpscr
 *   @0x2d880c bge 0x2d8860 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x2a4>
 *   @0x2d8810 cmp r5, r4
 *   @0x2d8814 bne 0x2d87c0 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x204>
 *   @0x2d8818 ldr r3, [sp, #0x18]
 *   @0x2d881c add r8, r8, #1
 *   @0x2d8820 cmp r8, r3
 *   @0x2d8824 bne 0x2d8678 <_ZNK16b2ParticleSystem15GetParticleMassEv+0xbc>
 *   @0x2d8828 mov r0, #1
 *   @0x2d882c add sp, sp, #68
 *   @0x2d8830 vpop {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x2d8834 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2d8838 mov r2, r3
 *   @0x2d883c mov r3, r12
 *   @0x2d8840 rsb r3, r2, r3
 *   @0x2d8844 add r4, r1, #8
 *   @0x2d8848 sub r12, r3, #1
 *   @0x2d884c b 0x2d86e0 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x124>
 *   @0x2d8850 rsb r3, r2, r3
 *   @0x2d8854 add r4, r1, #8
 *   @0x2d8858 sub r12, r3, #1
 *   @0x2d885c b 0x2d875c <_ZNK16b2ParticleSystem15GetParticleMassEv+0x1a0>
 *   @0x2d8860 vldr s15, [r9, #32]
 *   @0x2d8864 vsub.f32 s15, s17, s15
 *   @0x2d8868 vldr s9, [r9, #40]
 *   @0x2d886c vldr s8, [r9, #28]
 *   @0x2d8870 vldr s7, [r9, #36]
 *   @0x2d8874 vldr s11, [r9, #24]
 *   @0x2d8878 vldr s10, [r9, #20]
 *   @0x2d887c ldr r3, [r0, #0x40]
 *   @0x2d8880 vldr s12, [r7, #8]
 *   @0x2d8884 vldr s6, [r9, #12]
 *   @0x2d8888 add r3, r3, r6
 *   @0x2d888c vldr s28, [r3]
 *   @0x2d8890 vldr s29, [r3, #4]
 *   @0x2d8894 vldr s5, [r9, #16]
 *   @0x2d8898 ldr r0, [r10, #0xc]
 *   @0x2d889c mov r1, r11
 *   @0x2d88a0 ldr r3, [r10, #0x8]
 *   @0x2d88a4 add r2, sp, #44
 *   @0x2d88a8 vstr s25, [sp, #60]
 *   @0x2d88ac vmul.f32 s14, s15, s9
 *   @0x2d88b0 ldr r12, [r0]
 *   @0x2d88b4 add r3, r3, #12
 *   @0x2d88b8 str r8, [sp]
 *   @0x2d88bc ldr r12, [r12, #0x18]
 *   @0x2d88c0 vsub.f32 s8, s16, s8
 *   @0x2d88c4 vmul.f32 s15, s15, s7
 *   @0x2d88c8 vmls.f32 s14, s7, s8
 *   @0x2d88cc vmla.f32 s15, s8, s9
 *   @0x2d88d0 vmul.f32 s13, s14, s11
 *   @0x2d88d4 vmul.f32 s14, s14, s10
 *   @0x2d88d8 vmla.f32 s13, s15, s10
 *   @0x2d88dc vnmls.f32 s14, s15, s11
 *   @0x2d88e0 vmov.f32 s11, s16
 *   @0x2d88e4 vmov.f32 s15, s17
 *   @0x2d88e8 vmla.f32 s11, s28, s12
 *   @0x2d88ec vmla.f32 s15, s29, s12
 *   @0x2d88f0 vstr s11, [sp, #52]
 *   @0x2d88f4 vadd.f32 s13, s13, s5
 *   @0x2d88f8 vstr s15, [sp, #56]
 *   @0x2d88fc vadd.f32 s14, s14, s6
 *   @0x2d8900 vstr s13, [sp, #48]
 *   @0x2d8904 vstr s14, [sp, #44]
 *   @0x2d8908 blx r12
 *   @0x2d890c cmp r0, #0
 *   @0x2d8910 beq 0x2d8810 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x254>
 *   @0x2d8914 vldr s15, [sp, #40]
 *   @0x2d8918 vldr s30, [sp, #52]
 *   @0x2d891c vldr s31, [sp, #56]
 *   @0x2d8920 vmul.f32 s30, s15, s30
 *   @0x2d8924 vldr s10, [sp, #48]
 *   @0x2d8928 vldr s9, [sp, #44]
 *   @0x2d892c vldr s12, [sp, #36]
 *   @0x2d8930 vldr s11, [sp, #32]
 *   @0x2d8934 vldr s14, [r7, #12]
 *   @0x2d8938 ldr r0, [r7, #0x4]
 *   @0x2d893c ldr r3, [r0, #0x40]
 *   @0x2d8940 add r6, r3, r6
 *   @0x2d8944 vmul.f32 s31, s15, s31
 *   @0x2d8948 vsub.f32 s13, s25, s15
 *   @0x2d894c vmla.f32 s30, s13, s9
 *   @0x2d8950 vmla.f32 s31, s13, s10
 *   @0x2d8954 vmla.f32 s30, s11, s26
 *   @0x2d8958 vmla.f32 s31, s12, s26
 *   @0x2d895c vsub.f32 s16, s30, s16
 *   @0x2d8960 vsub.f32 s17, s31, s17
 *   @0x2d8964 vmul.f32 s16, s14, s16
 *   @0x2d8968 vmul.f32 s17, s14, s17
 *   @0x2d896c vstr s16, [r6]
 *   @0x2d8970 vstr s17, [r6, #4]
 *   @0x2d8974 bl 0x2d85bc <_ZNK16b2ParticleSystem15GetParticleMassEv>
 *   @0x2d8978 ldr r3, [r9]
 *   @0x2d897c vldr s14, [sp, #32]
 *   @0x2d8980 vldr s13, [sp, #36]
 *   @0x2d8984 cmp r3, #2
 *   @0x2d8988 vmov s15, r0
 *   @0x2d898c bne 0x2d8810 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x254>
 *   @0x2d8990 ldrh r3, [r9, #4]
 *   @0x2d8994 tst r3, #2
 *   @0x2d8998 orreq r3, r3, #2
 *   @0x2d899c vstreq s27, [r9, #160]
 *   @0x2d89a0 strheq r3, [r9, #4]
 *   @0x2d89a4 vsub.f32 s12, s29, s17
 *   @0x2d89a8 vldr s5, [r9, #64]
 *   @0x2d89ac vldr s6, [r9, #60]
 *   @0x2d89b0 vldr s10, [r9, #88]
 *   @0x2d89b4 vldr s8, [r9, #136]
 *   @0x2d89b8 vldr s9, [r9, #80]
 *   @0x2d89bc vldr s11, [r9, #84]
 *   @0x2d89c0 vldr s7, [r9, #144]
 *   @0x2d89c4 vmul.f32 s12, s15, s12
 *   @0x2d89c8 vsub.f32 s16, s28, s16
 *   @0x2d89cc vmul.f32 s12, s12, s13
 *   @0x2d89d0 vmul.f32 s15, s15, s16
 *   @0x2d89d4 vmla.f32 s12, s15, s14
 *   @0x2d89d8 vmul.f32 s14, s14, s12
 *   @0x2d89dc vsub.f32 s15, s31, s5
 *   @0x2d89e0 vmul.f32 s13, s13, s12
 *   @0x2d89e4 vmul.f32 s15, s14, s15
 *   @0x2d89e8 vsub.f32 s30, s30, s6
 *   @0x2d89ec vnmls.f32 s15, s13, s30
 *   @0x2d89f0 vmla.f32 s9, s14, s8
 *   @0x2d89f4 vmla.f32 s10, s15, s7
 *   @0x2d89f8 vstr s9, [r9, #80]
 *   @0x2d89fc vmla.f32 s11, s13, s8
 *   @0x2d8a00 vstr s10, [r9, #88]
 *   @0x2d8a04 vstr s11, [r9, #84]
 *   @0x2d8a08 b 0x2d8810 <_ZNK16b2ParticleSystem15GetParticleMassEv+0x254>
 *   @0x2d8a0c orrmi r0, r0, #0
 *   @0x2d8a10 .word 0x49000000
 *   @0x2d8a14 strmi r0, [r0, #-0x0]
 *   @0x2d8a18 bllo 0xfebce648 <b2_toiTime+0xfffffffffe4751a4>
 *
 * ══ §21/28 GraphicsPerf::oprintf_wrap_decode(int, int, unsigned int, unsigned int, char const*, ...)  0x17cdfc  size 1076  269 条（0x17cdfc..0x17d230）
 * @func 0x17cdfc 0x17d230  size 1076  269 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x17cec0→0x3f26c0, 0x17cf34→0x3f2484, 0x17d078→0x4a20f4, 0x17d07c→0x3f2484
 * 调用序列: GraphicsPerf::Print(float, float, float, float, unsigned int, char*, int)×5 / 0xb667c / GraphicsPerf::oprintf_wrap_decode(int, int, unsigned int, unsigned int, char const*, ...)+0x2c8 / GraphicsPerf::oprintf_wrap_decode(int, int, unsigned int, unsigned int, char const*, ...)+0x2d4 / 0xb65d4
 * 字段偏移 top8: 0x1c×6 / 0x4×5 / 0x8×5 / 0x14×4 / 0x1×4 / 0x18×3 / 0x10×3 / 0x20×2
 * VFP 指令 28 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17cdfc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x17ce00 vpush {d8, d9}
 *   @0x17ce04 sub sp, sp, #4096
 *   @0x17ce08 ldr r10, [pc, #0x40c]
 *   @0x17ce0c sub sp, sp, #60
 *   @0x17ce10 ldr r12, [pc, #0x408]
 *   @0x17ce14 add r10, pc, r10
 *   @0x17ce18 str r0, [sp, #0x20]
 *   @0x17ce1c str r10, [sp, #0x14]
 *   @0x17ce20 str r1, [sp, #0x18]
 *   @0x17ce24 add r1, sp, #8192
 *   @0x17ce28 str r3, [sp, #0x28]
 *   @0x17ce2c str r2, [sp, #0x1c]
 *   @0x17ce30 ldr r12, [r10, r12]
 *   @0x17ce34 ldr r0, [r1, #-0xf90]
 *   @0x17ce38 ldr r3, [r12]
 *   @0x17ce3c cmp r0, #0
 *   @0x17ce40 str r12, [sp, #0x2c]
 *   @0x17ce44 str r3, [r1, #-0xfcc]
 *   @0x17ce48 beq 0x17d0e0 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x2e4>
 *   @0x17ce4c ldrb r3, [r0]
 *   @0x17ce50 add lr, sp, #56
 *   @0x17ce54 cmp r3, #0
 *   @0x17ce58 beq 0x17d210 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x414>
 *   @0x17ce5c sub r8, lr, #4
 *   @0x17ce60 mov r1, #0
 *   @0x17ce64 add r2, r8, #2032
 *   @0x17ce68 add r2, r2, #15
 *   @0x17ce6c eor r12, r3, #26
 *   @0x17ce70 ldrb r3, [r0, #0x1]!
 *   @0x17ce74 strb r12, [r2, #0x1]!
 *   @0x17ce78 add r1, r1, #1
 *   @0x17ce7c cmp r3, #0
 *   @0x17ce80 bne 0x17ce6c <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x70>
 *   @0x17ce84 add r1, r1, #2048
 *   @0x17ce88 add r12, sp, #4160
 *   @0x17ce8c add r10, sp, #4096
 *   @0x17ce90 add r12, r12, #52
 *   @0x17ce94 mov r4, #0
 *   @0x17ce98 movw r3, #0xeff8
 *   @0x17ce9c strb r4, [r8, r1]
 *   @0x17cea0 movt r3, #0xffff
 *   @0x17cea4 sub r8, lr, #4
 *   @0x17cea8 add r10, r10, #56
 *   @0x17ceac mov r2, r12
 *   @0x17ceb0 mov r0, r8
 *   @0x17ceb4 add r1, r8, #2048
 *   @0x17ceb8 str r12, [r10, r3]
 *   @0x17cebc bl 0xb667c <vsprintf@plt>
 *   @0x17cec0 ldr r2, [pc, #0x35c]
 *   @0x17cec4 ldr r12, [sp, #0x14]
 *   @0x17cec8 add r0, sp, #4096
 *   @0x17cecc movw r3, #0xeffc
 *   @0x17ced0 add r0, r0, #56
 *   @0x17ced4 movt r3, #0xffff
 *   @0x17ced8 ldr r2, [r12, r2]
 *   @0x17cedc ldrb r3, [r0, r3]
 *   @0x17cee0 ldr r7, [r2]
 *   @0x17cee4 cmp r3, r4
 *   @0x17cee8 sub r7, r7, #4
 *   @0x17ceec beq 0x17d0e0 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x2e4>
 *   @0x17cef0 vmov.f32 s19, #1.000000e+00
 *   @0x17cef4 mvn r6, #0
 *   @0x17cef8 movw r10, #0x4567
 *   @0x17cefc str r6, [sp, #0x10]
 *   @0x17cf00 movt r10, #0x8123
 *   @0x17cf04 str r10, [sp, #0x24]
 *   @0x17cf08 vmov.f32 s18, #2.000000e+00
 *   @0x17cf0c cmp r3, #32
 *   @0x17cf10 cmpne r3, #10
 *   @0x17cf14 mov r0, r4
 *   @0x17cf18 beq 0x17cfa4 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x1a8>
 *   @0x17cf1c cmp r3, #0
 *   @0x17cf20 beq 0x17d1f8 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x3fc>
 *   @0x17cf24 cmp r7, #0
 *   @0x17cf28 blt 0x17d0c4 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x2c8>
 *   @0x17cf2c cmp r3, #10
 *   @0x17cf30 beq 0x17d10c <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x310>
 *   @0x17cf34 ldr r9, [pc, #0x2ec]
 *   @0x17cf38 add r12, r8, r4
 *   @0x17cf3c ldr r10, [sp, #0x14]
 *   @0x17cf40 mov r2, r4
 *   @0x17cf44 mov r5, #0
 *   @0x17cf48 mvn r1, #0
 *   @0x17cf4c ldr r11, [r10, r9]
 *   @0x17cf50 b 0x17cf84 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x188>
 *   @0x17cf54 add r9, r11, r3, lsl #2
 *   @0x17cf58 ldrb r3, [r12, #0x1]!
 *   @0x17cf5c add r10, r2, #1
 *   @0x17cf60 ldrb r9, [r9, #-0x7e]
 *   @0x17cf64 cmp r3, #0
 *   @0x17cf68 add r5, r5, r9
 *   @0x17cf6c beq 0x17d12c <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x330>
 *   @0x17cf70 cmp r7, r5
 *   @0x17cf74 blt 0x17d0d0 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x2d4>
 *   @0x17cf78 cmp r3, #10
 *   @0x17cf7c beq 0x17d114 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x318>
 *   @0x17cf80 mov r2, r10
 *   @0x17cf84 cmp r3, #32
 *   @0x17cf88 movne r6, r2
 *   @0x17cf8c bne 0x17cf54 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x158>
 *   @0x17cf90 cmp r6, #0
 *   @0x17cf94 strgt r2, [sp, #0x10]
 *   @0x17cf98 movgt r1, r5
 *   @0x17cf9c mvngt r6, #0
 *   @0x17cfa0 b 0x17cf54 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x158>
 *   @0x17cfa4 cmp r3, #0
 *   @0x17cfa8 beq 0x17cfd0 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x1d4>
 *   @0x17cfac add r2, r8, r4
 *   @0x17cfb0 ldrb r3, [r2, #0x1]!
 *   @0x17cfb4 add r4, r4, #1
 *   @0x17cfb8 cmp r3, #32
 *   @0x17cfbc cmpne r3, #10
 *   @0x17cfc0 mov r0, r4
 *   @0x17cfc4 bne 0x17cf1c <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x120>
 *   @0x17cfc8 cmp r3, #0
 *   @0x17cfcc bne 0x17cfb0 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x1b4>
 *   @0x17cfd0 mvn r2, #0
 *   @0x17cfd4 mov r3, r4
 *   @0x17cfd8 mov r1, r2
 *   @0x17cfdc mov r5, #0
 *   @0x17cfe0 cmp r7, r5
 *   @0x17cfe4 movlt r4, r2
 *   @0x17cfe8 cmp r5, #0
 *   @0x17cfec beq 0x17d0e0 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x2e4>
 *   @0x17cff0 ldrb r2, [r8, r4]
 *   @0x17cff4 tst r2, #223
 *   @0x17cff8 beq 0x17d0bc <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x2c0>
 *   @0x17cffc cmp r2, #10
 *   @0x17d000 beq 0x17d0bc <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x2c0>
 *   @0x17d004 ldr r9, [sp, #0x10]
 *   @0x17d008 mov r5, r1
 *   @0x17d00c mov r4, r9
 *   @0x17d010 ldr r12, [sp, #0x20]
 *   @0x17d014 vldr s15, [sp, #24]
 *   @0x17d018 ldr r10, [sp, #0x24]
 *   @0x17d01c add r11, r8, r0
 *   @0x17d020 vcvt.f32.s32 s16, s15
 *   @0x17d024 cmp r12, r10
 *   @0x17d028 rsb r10, r3, r4
 *   @0x17d02c rsbeq r3, r5, r7
 *   @0x17d030 ldr r12, [sp, #0x1c]
 *   @0x17d034 vldrne s17, [sp, #32]
 *   @0x17d038 addeq r3, r3, r3, lsr #31
 *   @0x17d03c asreq r3, r3, #1
 *   @0x17d040 vmoveq s17, r3
 *   @0x17d044 cmp r12, #0
 *   @0x17d048 bne 0x17d138 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x33c>
 *   @0x17d04c vcvt.f32.s32 s17, s17
 *   @0x17d050 ldr r12, [sp, #0x28]
 *   @0x17d054 mov r2, #1065353216
 *   @0x17d058 mov r3, r2
 *   @0x17d05c str r11, [sp, #0x4]
 *   @0x17d060 str r10, [sp, #0x8]
 *   @0x17d064 str r12, [sp]
 *   @0x17d068 vmov r1, s16
 *   @0x17d06c vmov r0, s17
 *   @0x17d070 bl 0x17c030 <_ZN12GraphicsPerf5PrintEffffjPci>
 *   @0x17d074 ldr r10, [sp, #0x14]
 *   @0x17d078 ldr r2, [pc, #0x1ac]
 *   @0x17d07c ldr r1, [pc, #0x1a4]
 *   @0x17d080 ldrb r3, [r8, r9]
 *   @0x17d084 ldr r2, [r10, r2]
 *   @0x17d088 ldr r12, [sp, #0x18]
 *   @0x17d08c cmp r3, #0
 *   @0x17d090 ldr r0, [r2]
 *   @0x17d094 add r0, r0, #1
 *   @0x17d098 str r0, [r2]
 *   @0x17d09c ldr r11, [r10, r1]
 *   @0x17d0a0 ldrb r2, [r11, #0x83]
 *   @0x17d0a4 add r2, r2, #2
 *   @0x17d0a8 add r12, r12, r2
 *   @0x17d0ac str r12, [sp, #0x18]
 *   @0x17d0b0 bne 0x17cf0c <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x110>
 *   @0x17d0b4 mov r0, r5
 *   @0x17d0b8 b 0x17d0e4 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x2e8>
 *   @0x17d0bc mov r9, r4
 *   @0x17d0c0 b 0x17d010 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x214>
 *   @0x17d0c4 mvn r2, #0
 *   @0x17d0c8 mov r5, #0
 *   @0x17d0cc mov r1, r2
 *   @0x17d0d0 cmp r5, #0
 *   @0x17d0d4 mov r3, r4
 *   @0x17d0d8 mov r4, r2
 *   @0x17d0dc bne 0x17cff0 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x1f4>
 *   @0x17d0e0 mov r0, #0
 *   @0x17d0e4 ldr r10, [sp, #0x2c]
 *   @0x17d0e8 add r1, sp, #8192
 *   @0x17d0ec ldr r2, [r1, #-0xfcc]
 *   @0x17d0f0 ldr r3, [r10]
 *   @0x17d0f4 cmp r2, r3
 *   @0x17d0f8 bne 0x17d20c <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x410>
 *   @0x17d0fc add sp, sp, #4096
 *   @0x17d100 add sp, sp, #60
 *   @0x17d104 vpop {d8, d9}
 *   @0x17d108 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x17d10c mov r10, r4
 *   @0x17d110 mov r5, #0
 *   @0x17d114 mov r3, r4
 *   @0x17d118 str r10, [sp, #0x10]
 *   @0x17d11c mov r4, r10
 *   @0x17d120 mov r1, r5
 *   @0x17d124 mvn r6, #0
 *   @0x17d128 b 0x17cfe8 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x1ec>
 *   @0x17d12c mov r3, r4
 *   @0x17d130 mov r4, r10
 *   @0x17d134 b 0x17cfe0 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x1e4>
 *   @0x17d138 vmov r1, s17
 *   @0x17d13c mov r2, #1065353216
 *   @0x17d140 ldr r12, [sp, #0x1c]
 *   @0x17d144 mov r3, r2
 *   @0x17d148 str r11, [sp, #0x4]
 *   @0x17d14c str r10, [sp, #0x8]
 *   @0x17d150 str r12, [sp]
 *   @0x17d154 sub r0, r1, #1
 *   @0x17d158 vmov r1, s16
 *   @0x17d15c vmov s15, r0
 *   @0x17d160 vcvt.f32.s32 s15, s15
 *   @0x17d164 vmov r0, s15
 *   @0x17d168 bl 0x17c030 <_ZN12GraphicsPerf5PrintEffffjPci>
 *   @0x17d16c vmov r1, s17
 *   @0x17d170 ldr r12, [sp, #0x1c]
 *   @0x17d174 mov r2, #1065353216
 *   @0x17d178 mov r3, r2
 *   @0x17d17c str r11, [sp, #0x4]
 *   @0x17d180 str r10, [sp, #0x8]
 *   @0x17d184 str r12, [sp]
 *   @0x17d188 add r0, r1, #1
 *   @0x17d18c vmov r1, s16
 *   @0x17d190 vmov s15, r0
 *   @0x17d194 vcvt.f32.s32 s15, s15
 *   @0x17d198 vmov r0, s15
 *   @0x17d19c bl 0x17c030 <_ZN12GraphicsPerf5PrintEffffjPci>
 *   @0x17d1a0 vsub.f32 s15, s16, s19
 *   @0x17d1a4 ldr r12, [sp, #0x1c]
 *   @0x17d1a8 mov r2, #1065353216
 *   @0x17d1ac mov r3, r2
 *   @0x17d1b0 str r11, [sp, #0x4]
 *   @0x17d1b4 str r10, [sp, #0x8]
 *   @0x17d1b8 str r12, [sp]
 *   @0x17d1bc vcvt.f32.s32 s17, s17
 *   @0x17d1c0 vmov r1, s15
 *   @0x17d1c4 vmov r0, s17
 *   @0x17d1c8 bl 0x17c030 <_ZN12GraphicsPerf5PrintEffffjPci>
 *   @0x17d1cc vadd.f32 s15, s16, s18
 *   @0x17d1d0 ldr r12, [sp, #0x1c]
 *   @0x17d1d4 mov r2, #1065353216
 *   @0x17d1d8 str r11, [sp, #0x4]
 *   @0x17d1dc mov r3, r2
 *   @0x17d1e0 str r10, [sp, #0x8]
 *   @0x17d1e4 str r12, [sp]
 *   @0x17d1e8 vmov r0, s17
 *   @0x17d1ec vmov r1, s15
 *   @0x17d1f0 bl 0x17c030 <_ZN12GraphicsPerf5PrintEffffjPci>
 *   @0x17d1f4 b 0x17d050 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x254>
 *   @0x17d1f8 mvn r2, #0
 *   @0x17d1fc mov r5, r3
 *   @0x17d200 mov r1, r2
 *   @0x17d204 mov r3, r4
 *   @0x17d208 b 0x17cfe0 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x1e4>
 *   @0x17d20c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x17d210 add r8, sp, #52
 *   @0x17d214 mov r1, #2048
 *   @0x17d218 b 0x17ce88 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x8c>
 *   @0x17d21c eoreq r4, r7, r12, lsr lr
 *   @0x17d220 .word 0xffffbd00
 *   @0x17d224 .word 0xffffe24c
 *   @0x17d228 .word 0xffffe64c
 *   @0x17d22c .word 0xffffe7ac
 *
 * ══ §22/28 YYAudioDrawDebug()  0x21e384  size 1076  269 条（0x21e384..0x21e7b8）
 * @func 0x21e384 0x21e7b8  size 1076  269 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GraphicsPerf::oprintf(float, float, unsigned int, unsigned int, char const*, ...)×7 / 0xb6a9c×5 / GraphicsPerf::strwidth(char const*, int)×3 / 0xb6ac0×3 / YYAudioDrawDebug()+0x3ec×2 / GraphicsPerf::RenderRectangle(float, float, float, float, unsigned int)×2 / 0xb6acc / YYAudioDrawDebug()+0x3f8
 * 字段偏移 top8: 0x2×7 / 0xc×6 / 0x4×6 / 0x28×4 / 0x10×4 / 0x20×4 / 0x1c×2 / 0x38×2
 * VFP 指令 57 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21e384 ldr r0, [pc, #0x408]
 *   @0x21e388 mvn r1, #-2147483648
 *   @0x21e38c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x21e390 vpush {d8, d9, d10, d11, d12, d13}
 *   @0x21e394 add r0, pc, r0
 *   @0x21e398 sub sp, sp, #68
 *   @0x21e39c ldr r10, [pc, #0x3f4]
 *   @0x21e3a0 bl 0x17c49c <_ZN12GraphicsPerf8strwidthEPKci>
 *   @0x21e3a4 mvn r1, #-2147483648
 *   @0x21e3a8 vmov s22, r0
 *   @0x21e3ac ldr r0, [pc, #0x3e8]
 *   @0x21e3b0 add r0, pc, r0
 *   @0x21e3b4 bl 0x17c49c <_ZN12GraphicsPerf8strwidthEPKci>
 *   @0x21e3b8 mvn r1, #-2147483648
 *   @0x21e3bc vmov s23, r0
 *   @0x21e3c0 ldr r0, [pc, #0x3d8]
 *   @0x21e3c4 add r0, pc, r0
 *   @0x21e3c8 bl 0x17c49c <_ZN12GraphicsPerf8strwidthEPKci>
 *   @0x21e3cc ldr r10, [pc, r10]
 *   @0x21e3d0 ldr r3, [r10]
 *   @0x21e3d4 cmp r3, #0
 *   @0x21e3d8 vmov s24, r0
 *   @0x21e3dc ble 0x21e770 <_Z16YYAudioDrawDebugv+0x3ec>
 *   @0x21e3e0 ldr r11, [pc, #0x3bc]
 *   @0x21e3e4 mov r5, #0
 *   @0x21e3e8 ldr r0, [pc, #0x3b8]
 *   @0x21e3ec movt r5, #0x42c8
 *   @0x21e3f0 add r2, sp, #28
 *   @0x21e3f4 ldr r11, [pc, r11]
 *   @0x21e3f8 add r0, pc, r0
 *   @0x21e3fc vmov s21, r5
 *   @0x21e400 str r0, [sp, #0xc]
 *   @0x21e404 mov r4, #0
 *   @0x21e408 str r2, [sp, #0x8]
 *   @0x21e40c vldr s19, [pc, #880]
 *   @0x21e410 vldr s25, [pc, #880]
 *   @0x21e414 vldr s18, [pc, #880]
 *   @0x21e418 vldr s17, [pc, #880]
 *   @0x21e41c b 0x21e430 <_Z16YYAudioDrawDebugv+0xac>
 *   @0x21e420 ldr r3, [r10]
 *   @0x21e424 add r4, r4, #1
 *   @0x21e428 cmp r3, r4
 *   @0x21e42c ble 0x21e770 <_Z16YYAudioDrawDebugv+0x3ec>
 *   @0x21e430 ldr r3, [r11]
 *   @0x21e434 add r2, sp, #28
 *   @0x21e438 mvn r6, #0
 *   @0x21e43c movw r1, #0x1010
 *   @0x21e440 str r6, [sp, #0x1c]
 *   @0x21e444 ldr r0, [r3, r4, lsl #2]
 *   @0x21e448 bl 0xb6a9c <alGetSourcei@plt>
 *   @0x21e44c ldr r2, [sp, #0x1c]
 *   @0x21e450 movw r3, #0x1012
 *   @0x21e454 cmp r2, r3
 *   @0x21e458 bne 0x21e420 <_Z16YYAudioDrawDebugv+0x9c>
 *   @0x21e45c ldr r3, [r11]
 *   @0x21e460 add r2, sp, #64
 *   @0x21e464 mov r9, #0
 *   @0x21e468 movw r1, #0x1015
 *   @0x21e46c str r9, [r2, #-0x20]!
 *   @0x21e470 vmov.f32 s16, #1.000000e+01
 *   @0x21e474 ldr r0, [r3, r4, lsl #2]
 *   @0x21e478 bl 0xb6a9c <alGetSourcei@plt>
 *   @0x21e47c ldr r3, [r11]
 *   @0x21e480 add r2, sp, #64
 *   @0x21e484 movw r1, #0x1016
 *   @0x21e488 str r9, [r2, #-0x1c]!
 *   @0x21e48c ldr r0, [r3, r4, lsl #2]
 *   @0x21e490 bl 0xb6a9c <alGetSourcei@plt>
 *   @0x21e494 ldr r3, [r11]
 *   @0x21e498 add r2, sp, #64
 *   @0x21e49c movw r1, #0x1009
 *   @0x21e4a0 str r6, [r2, #-0x18]!
 *   @0x21e4a4 ldr r0, [r3, r4, lsl #2]
 *   @0x21e4a8 bl 0xb6a9c <alGetSourcei@plt>
 *   @0x21e4ac ldr r0, [sp, #0x28]
 *   @0x21e4b0 movw r1, #0x2004
 *   @0x21e4b4 add r2, sp, #44
 *   @0x21e4b8 str r9, [sp, #0x2c]
 *   @0x21e4bc bl 0xb6ac0 <alGetBufferi@plt>
 *   @0x21e4c0 ldr r3, [sp, #0xc]
 *   @0x21e4c4 mov r2, #267386880
 *   @0x21e4c8 ldr lr, [pc, #0x2dc]
 *   @0x21e4cc mov r1, r5
 *   @0x21e4d0 mov r0, #0
 *   @0x21e4d4 movt r0, #0x4120
 *   @0x21e4d8 str r3, [sp]
 *   @0x21e4dc mov r3, r6
 *   @0x21e4e0 ldr r12, [r11]
 *   @0x21e4e4 str lr, [sp, #0x10]
 *   @0x21e4e8 ldr r12, [r12, r4, lsl #2]
 *   @0x21e4ec str r12, [sp, #0x4]
 *   @0x21e4f0 bl 0x17c2f8 <_ZN12GraphicsPerf7oprintfEffjjPKcz>
 *   @0x21e4f4 vcvt.f32.s32 s26, s24
 *   @0x21e4f8 ldr r0, [sp, #0x28]
 *   @0x21e4fc mov r2, #267386880
 *   @0x21e500 ldr r3, [sp, #0xc]
 *   @0x21e504 mov r1, r5
 *   @0x21e508 str r0, [sp, #0x4]
 *   @0x21e50c str r3, [sp]
 *   @0x21e510 mov r3, r6
 *   @0x21e514 vadd.f32 s26, s26, s19
 *   @0x21e518 vadd.f32 s16, s26, s16
 *   @0x21e51c vmov r0, s16
 *   @0x21e520 bl 0x17c2f8 <_ZN12GraphicsPerf7oprintfEffjjPKcz>
 *   @0x21e524 vadd.f32 s16, s26, s16
 *   @0x21e528 ldr lr, [sp, #0xc]
 *   @0x21e52c mov r2, #267386880
 *   @0x21e530 ldr r0, [sp, #0x24]
 *   @0x21e534 mov r3, r6
 *   @0x21e538 mov r1, r5
 *   @0x21e53c str lr, [sp]
 *   @0x21e540 str r0, [sp, #0x4]
 *   @0x21e544 vmov r0, s16
 *   @0x21e548 bl 0x17c2f8 <_ZN12GraphicsPerf7oprintfEffjjPKcz>
 *   @0x21e54c vcvt.f32.s32 s20, s22
 *   @0x21e550 ldr r0, [sp, #0x20]
 *   @0x21e554 mov r2, #267386880
 *   @0x21e558 ldr r3, [sp, #0xc]
 *   @0x21e55c mov r1, r5
 *   @0x21e560 str r0, [sp, #0x4]
 *   @0x21e564 str r3, [sp]
 *   @0x21e568 mov r3, r6
 *   @0x21e56c vadd.f32 s20, s20, s19
 *   @0x21e570 vadd.f32 s16, s20, s16
 *   @0x21e574 vmov r0, s16
 *   @0x21e578 bl 0x17c2f8 <_ZN12GraphicsPerf7oprintfEffjjPKcz>
 *   @0x21e57c vmov lr, s19
 *   @0x21e580 ldr r3, [r11]
 *   @0x21e584 add r2, sp, #64
 *   @0x21e588 movw r1, #0x100a
 *   @0x21e58c vadd.f32 s20, s20, s16
 *   @0x21e590 ldr r0, [r3, r4, lsl #2]
 *   @0x21e594 str lr, [r2, #-0x10]!
 *   @0x21e598 bl 0xb6acc <alGetSourcef@plt>
 *   @0x21e59c vldr s15, [sp, #48]
 *   @0x21e5a0 vmul.f32 s15, s15, s25
 *   @0x21e5a4 ldr r0, [sp, #0xc]
 *   @0x21e5a8 mov r2, #267386880
 *   @0x21e5ac mov r1, r5
 *   @0x21e5b0 mov r3, r6
 *   @0x21e5b4 str r0, [sp]
 *   @0x21e5b8 vmov r0, s20
 *   @0x21e5bc vcvt.s32.f32 s15, s15
 *   @0x21e5c0 vstr s15, [sp, #4]
 *   @0x21e5c4 bl 0x17c2f8 <_ZN12GraphicsPerf7oprintfEffjjPKcz>
 *   @0x21e5c8 vcvt.f32.s32 s16, s23
 *   @0x21e5cc ldr r3, [r11]
 *   @0x21e5d0 add r2, sp, #64
 *   @0x21e5d4 movw r1, #0x1025
 *   @0x21e5d8 str r9, [r2, #-0xc]!
 *   @0x21e5dc ldr r0, [r3, r4, lsl #2]
 *   @0x21e5e0 bl 0xb6a9c <alGetSourcei@plt>
 *   @0x21e5e4 ldr r0, [sp, #0x28]
 *   @0x21e5e8 movw r1, #0x2002
 *   @0x21e5ec add r2, sp, #56
 *   @0x21e5f0 vadd.f32 s16, s16, s19
 *   @0x21e5f4 str r9, [sp, #0x38]
 *   @0x21e5f8 bl 0xb6ac0 <alGetBufferi@plt>
 *   @0x21e5fc ldr r3, [sp, #0x38]
 *   @0x21e600 ldr r0, [sp, #0x28]
 *   @0x21e604 movw r1, #0x2003
 *   @0x21e608 cmp r3, r9
 *   @0x21e60c add r2, r3, #7
 *   @0x21e610 str r9, [sp, #0x3c]
 *   @0x21e614 movlt r3, r2
 *   @0x21e618 add r2, sp, #60
 *   @0x21e61c asr r3, r3, #3
 *   @0x21e620 vadd.f32 s16, s16, s20
 *   @0x21e624 vmov s20, r3
 *   @0x21e628 bl 0xb6ac0 <alGetBufferi@plt>
 *   @0x21e62c ldr r1, [sp, #0x34]
 *   @0x21e630 mov r2, #267386880
 *   @0x21e634 ldr r12, [pc, #0x174]
 *   @0x21e638 mov r3, r6
 *   @0x21e63c add r12, pc, r12
 *   @0x21e640 str r1, [sp, #0x4]
 *   @0x21e644 str r12, [sp]
 *   @0x21e648 mov r1, r5
 *   @0x21e64c vmov r0, s16
 *   @0x21e650 bl 0x17c2f8 <_ZN12GraphicsPerf7oprintfEffjjPKcz>
 *   @0x21e654 ldr r2, [sp, #0x10]
 *   @0x21e658 ldr r3, [sp, #0x20]
 *   @0x21e65c vadd.f32 s16, s26, s16
 *   @0x21e660 ldr r2, [pc, r2]
 *   @0x21e664 str r2, [sp, #0x10]
 *   @0x21e668 cmp r3, r9
 *   @0x21e66c ldr r7, [r2]
 *   @0x21e670 ble 0x21e77c <_Z16YYAudioDrawDebugv+0x3f8>
 *   @0x21e674 ldr r8, [pc, #0x138]
 *   @0x21e678 mov r12, #255
 *   @0x21e67c movt r12, #0xff00
 *   @0x21e680 str r4, [sp, #0x14]
 *   @0x21e684 add r8, pc, r8
 *   @0x21e688 mov r4, r9
 *   @0x21e68c mov r9, r12
 *   @0x21e690 b 0x21e6a4 <_Z16YYAudioDrawDebugv+0x320>
 *   @0x21e694 ldr r3, [sp, #0x20]
 *   @0x21e698 vadd.f32 s16, s16, s17
 *   @0x21e69c cmp r3, r4
 *   @0x21e6a0 ble 0x21e748 <_Z16YYAudioDrawDebugv+0x3c4>
 *   @0x21e6a4 vmov r0, s16
 *   @0x21e6a8 mov r1, r5
 *   @0x21e6ac mov r3, r7
 *   @0x21e6b0 str r6, [sp]
 *   @0x21e6b4 mov r2, #0
 *   @0x21e6b8 movt r2, #0x42c8
 *   @0x21e6bc bl 0x17b83c <_ZN12GraphicsPerf15RenderRectangleEffffj>
 *   @0x21e6c0 str r4, [sp, #0x4]
 *   @0x21e6c4 vadd.f32 s13, s16, s18
 *   @0x21e6c8 str r8, [sp]
 *   @0x21e6cc mov r3, #255
 *   @0x21e6d0 mov r1, r5
 *   @0x21e6d4 movt r3, #0xff00
 *   @0x21e6d8 mov r2, #267386880
 *   @0x21e6dc vmov r0, s13
 *   @0x21e6e0 bl 0x17c2f8 <_ZN12GraphicsPerf7oprintfEffjjPKcz>
 *   @0x21e6e4 cmp r4, #0
 *   @0x21e6e8 add r4, r4, #1
 *   @0x21e6ec bne 0x21e694 <_Z16YYAudioDrawDebugv+0x310>
 *   @0x21e6f0 vldr s14, [sp, #52]
 *   @0x21e6f4 vcvt.f32.s32 s15, s14
 *   @0x21e6f8 vldr s13, [sp, #60]
 *   @0x21e6fc mov r3, r7
 *   @0x21e700 str r9, [sp]
 *   @0x21e704 mov r2, #1065353216
 *   @0x21e708 mov r1, r5
 *   @0x21e70c vmul.f32 s15, s15, s21
 *   @0x21e710 vcvt.f32.s32 s14, s20
 *   @0x21e714 vmul.f32 s15, s15, s14
 *   @0x21e718 vcvt.f32.s32 s14, s13
 *   @0x21e71c vldr s13, [sp, #44]
 *   @0x21e720 vmul.f32 s15, s15, s14
 *   @0x21e724 vcvt.f32.s32 s14, s13
 *   @0x21e728 vdiv.f32 s15, s15, s14
 *   @0x21e72c vadd.f32 s15, s15, s16
 *   @0x21e730 vmov r0, s15
 *   @0x21e734 bl 0x17b83c <_ZN12GraphicsPerf15RenderRectangleEffffj>
 *   @0x21e738 ldr r3, [sp, #0x20]
 *   @0x21e73c vadd.f32 s16, s16, s17
 *   @0x21e740 cmp r3, r4
 *   @0x21e744 bgt 0x21e6a4 <_Z16YYAudioDrawDebugv+0x320>
 *   @0x21e748 ldr r4, [sp, #0x14]
 *   @0x21e74c ldr r0, [sp, #0x10]
 *   @0x21e750 vldr s15, [r0]
 *   @0x21e754 vmov s13, r5
 *   @0x21e758 ldr r3, [r10]
 *   @0x21e75c add r4, r4, #1
 *   @0x21e760 vadd.f32 s13, s13, s15
 *   @0x21e764 cmp r3, r4
 *   @0x21e768 vmov r5, s13
 *   @0x21e76c bgt 0x21e430 <_Z16YYAudioDrawDebugv+0xac>
 *   @0x21e770 add sp, sp, #68
 *   @0x21e774 vpop {d8, d9, d10, d11, d12, d13}
 *   @0x21e778 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x21e77c vmov s15, r7
 *   @0x21e780 b 0x21e754 <_Z16YYAudioDrawDebugv+0x3d0>
 *   @0x21e784 andeq r0, r0, r0
 *   @0x21e788 strmi r0, [r0, r0]
 *   @0x21e78c eormi r0, r0, #0
 *   @0x21e790 sbcsmi r0, r2, #0
 *   @0x21e794 andseq r6, r3, r12, lsl #7
 *   @0x21e798 andseq r3, sp, r4
 *   @0x21e79c andseq r6, r3, r4, ror r3
 *   @0x21e7a0 andseq r6, r3, r8, ror #6
 *   @0x21e7a4 ldrsbeq r2, [sp], -r8
 *   @0x21e7a8 andseq r4, r1, r4, lsl r1
 *   @0x21e7ac ldrsbeq r1, [sp], -r4
 *   @0x21e7b0 andseq r3, r1, r0, ror r11
 *   @0x21e7b4 andseq r3, r1, r8, lsl #29
 *
 * ══ §23/28 CPhysicsWorld::DrawParticles(unsigned int, int, CSprite*, int)  0x23a8c0  size 1076  269 条（0x23a8c0..0x23acf4）
 * @func 0x23a8c0 0x23acf4  size 1076  269 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::GetMaxDynamicVertexCount()×3 / CPhysicsWorld::DrawParticles(unsigned int, int, CSprite*, int)+0x54×2 / __aeabi_idivmod / GR_Texture_Exists(int) / b2World::GetParticlePositionBuffer() / b2World::GetParticleColorBuffer() / b2World::GetParticleFlagsBuffer() / b2World::GetParticleUserDataBuffer()
 * 字段偏移 top8: 0x10×7 / 0x14×7 / 0x4×6 / 0x18×5 / 0xc×5 / 0x8×4 / 0x2×3 / 0x24×3
 * VFP 指令 71 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23a8c0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x23a8c4 vpush {d8, d9, d10}
 *   @0x23a8c8 sub sp, sp, #44
 *   @0x23a8cc ldr r5, [r3, #0x18]
 *   @0x23a8d0 mov r6, r0
 *   @0x23a8d4 str r1, [sp, #0xc]
 *   @0x23a8d8 mov r4, r3
 *   @0x23a8dc ldr r0, [sp, #0x68]
 *   @0x23a8e0 mov r8, r2
 *   @0x23a8e4 mov r1, r5
 *   @0x23a8e8 bl 0x318dec <__aeabi_idivmod>
 *   @0x23a8ec ldr r3, [r4, #0x54]
 *   @0x23a8f0 cmp r1, #0
 *   @0x23a8f4 addlt r1, r1, r5
 *   @0x23a8f8 cmp r3, #0
 *   @0x23a8fc beq 0x23a914 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x54>
 *   @0x23a900 ldr r5, [r3, r1, lsl #2]
 *   @0x23a904 ldrsh r0, [r5, #20]
 *   @0x23a908 bl 0x173e2c <_Z17GR_Texture_Existsi>
 *   @0x23a90c cmp r0, #0
 *   @0x23a910 bne 0x23a920 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x60>
 *   @0x23a914 add sp, sp, #44
 *   @0x23a918 vpop {d8, d9, d10}
 *   @0x23a91c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x23a920 ldr r3, [pc, #0x3c8]
 *   @0x23a924 ldrsh r2, [r5, #20]
 *   @0x23a928 ldr r3, [pc, r3]
 *   @0x23a92c ldr r0, [r6, #0x10]
 *   @0x23a930 ldr r3, [r3, #0x4]
 *   @0x23a934 ldr r3, [r3, r2, lsl #2]
 *   @0x23a938 str r3, [sp, #0x4]
 *   @0x23a93c bl 0x2cb574 <_ZN7b2World25GetParticlePositionBufferEv>
 *   @0x23a940 str r0, [sp, #0x20]
 *   @0x23a944 ldr r0, [r6, #0x10]
 *   @0x23a948 bl 0x2cb58c <_ZN7b2World22GetParticleColorBufferEv>
 *   @0x23a94c str r0, [sp, #0x24]
 *   @0x23a950 ldr r0, [r6, #0x10]
 *   @0x23a954 bl 0x2cb568 <_ZN7b2World22GetParticleFlagsBufferEv>
 *   @0x23a958 str r0, [sp, #0x18]
 *   @0x23a95c ldr r0, [r6, #0x10]
 *   @0x23a960 bl 0x2cb598 <_ZN7b2World25GetParticleUserDataBufferEv>
 *   @0x23a964 ldr r2, [r6, #0x10]
 *   @0x23a968 movw r3, #0x9298
 *   @0x23a96c movt r3, #0x1
 *   @0x23a970 vldr s15, [r6, #96]
 *   @0x23a974 ldr r11, [r2, r3]
 *   @0x23a978 cmp r11, #0
 *   @0x23a97c str r0, [sp, #0x1c]
 *   @0x23a980 ble 0x23a914 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x54>
 *   @0x23a984 cmp r8, #0
 *   @0x23a988 beq 0x23acb4 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x3f4>
 *   @0x23a98c mov r3, #0
 *   @0x23a990 lsl r0, r11, #2
 *   @0x23a994 mov r1, r3
 *   @0x23a998 ldr r12, [sp, #0x18]
 *   @0x23a99c ldr r7, [sp, #0x1c]
 *   @0x23a9a0 ldr r6, [sp, #0xc]
 *   @0x23a9a4 b 0x23a9c0 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x100>
 *   @0x23a9a8 ldr r2, [r7, r3]
 *   @0x23a9ac cmp r2, r8
 *   @0x23a9b0 addeq r1, r1, #1
 *   @0x23a9b4 add r3, r3, #4
 *   @0x23a9b8 cmp r3, r0
 *   @0x23a9bc beq 0x23a9e0 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x120>
 *   @0x23a9c0 ldr r2, [r12, r3]
 *   @0x23a9c4 cmp r2, #0
 *   @0x23a9c8 beq 0x23a9a8 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0xe8>
 *   @0x23a9cc tst r2, r6
 *   @0x23a9d0 bne 0x23a9a8 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0xe8>
 *   @0x23a9d4 add r3, r3, #4
 *   @0x23a9d8 cmp r3, r0
 *   @0x23a9dc bne 0x23a9c0 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x100>
 *   @0x23a9e0 cmp r1, #0
 *   @0x23a9e4 beq 0x23a914 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x54>
 *   @0x23a9e8 ldr r3, [r4, #0x24]
 *   @0x23a9ec vmov.f32 s16, #1.000000e+00
 *   @0x23a9f0 ldrsh r12, [r5, #8]
 *   @0x23a9f4 add r1, r1, r1, lsl #1
 *   @0x23a9f8 ldr r2, [r4, #0x28]
 *   @0x23a9fc vldr s17, [pc, #744]
 *   @0x23aa00 rsb r12, r3, r12
 *   @0x23aa04 ldrh r3, [r5, #12]
 *   @0x23aa08 ldrsh r0, [r5, #10]
 *   @0x23aa0c lsl r1, r1, #1
 *   @0x23aa10 cmp r3, #0
 *   @0x23aa14 vmov s14, r12
 *   @0x23aa18 sxthne r3, r3
 *   @0x23aa1c rsb r2, r2, r0
 *   @0x23aa20 moveq r3, #1
 *   @0x23aa24 strheq r3, [r5, #12]
 *   @0x23aa28 vmovne s21, r3
 *   @0x23aa2c ldrh r3, [r5, #14]
 *   @0x23aa30 str r1, [sp, #0x14]
 *   @0x23aa34 mov r4, #0
 *   @0x23aa38 vcvtne.f32.s32 s21, s21
 *   @0x23aa3c vmoveq.f32 s21, #1.000000e+00
 *   @0x23aa40 cmp r3, #0
 *   @0x23aa44 sxthne r3, r3
 *   @0x23aa48 moveq r3, #1
 *   @0x23aa4c strheq r3, [r5, #14]
 *   @0x23aa50 vmovne s20, r3
 *   @0x23aa54 vcvt.f32.s32 s19, s14
 *   @0x23aa58 vmov s14, r2
 *   @0x23aa5c vcvtne.f32.s32 s20, s20
 *   @0x23aa60 vmoveq.f32 s20, #1.000000e+00
 *   @0x23aa64 vcvt.f32.s32 s18, s14
 *   @0x23aa68 vdiv.f32 s16, s16, s15
 *   @0x23aa6c bl 0x18561c <_ZN8Graphics24GetMaxDynamicVertexCountEv>
 *   @0x23aa70 ldr r9, [sp, #0x14]
 *   @0x23aa74 cmp r0, r9
 *   @0x23aa78 vadd.f32 s21, s19, s21
 *   @0x23aa7c vadd.f32 s20, s18, s20
 *   @0x23aa80 blt 0x23aca8 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x3e8>
 *   @0x23aa84 ldr r10, [sp, #0x14]
 *   @0x23aa88 str r10, [sp, #0x8]
 *   @0x23aa8c ldr r9, [sp, #0x4]
 *   @0x23aa90 mov r0, #4
 *   @0x23aa94 mov r2, #24
 *   @0x23aa98 ldr r3, [sp, #0x8]
 *   @0x23aa9c ldr r1, [r9]
 *   @0x23aaa0 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x23aaa4 cmp r11, r4
 *   @0x23aaa8 ble 0x23ac8c <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x3cc>
 *   @0x23aaac ldr r10, [sp, #0x18]
 *   @0x23aab0 lsl r7, r4, #2
 *   @0x23aab4 ldr r1, [sp, #0x1c]
 *   @0x23aab8 mov r3, #0
 *   @0x23aabc add r6, r10, r7
 *   @0x23aac0 ldr r9, [sp, #0x24]
 *   @0x23aac4 ldr r10, [sp, #0x20]
 *   @0x23aac8 add r1, r1, r7
 *   @0x23aacc mov r12, r3
 *   @0x23aad0 str r1, [sp, #0x10]
 *   @0x23aad4 add r7, r9, r7
 *   @0x23aad8 add r2, r10, r4, lsl #3
 *   @0x23aadc b 0x23ab04 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x244>
 *   @0x23aae0 ldr r10, [sp, #0x10]
 *   @0x23aae4 ldr r1, [r10, r3]
 *   @0x23aae8 cmp r1, r8
 *   @0x23aaec beq 0x23ab24 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x264>
 *   @0x23aaf0 add r4, r4, #1
 *   @0x23aaf4 add r3, r3, #4
 *   @0x23aaf8 cmp r4, r11
 *   @0x23aafc add r2, r2, #8
 *   @0x23ab00 beq 0x23ac8c <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x3cc>
 *   @0x23ab04 ldr r1, [r6, r3]
 *   @0x23ab08 cmp r1, #0
 *   @0x23ab0c beq 0x23ab1c <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x25c>
 *   @0x23ab10 ldr r9, [sp, #0xc]
 *   @0x23ab14 tst r1, r9
 *   @0x23ab18 beq 0x23aaf0 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x230>
 *   @0x23ab1c cmp r8, #0
 *   @0x23ab20 bne 0x23aae0 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x220>
 *   @0x23ab24 add r1, r7, r3
 *   @0x23ab28 ldrb r9, [r7, r3]
 *   @0x23ab2c ldrb r10, [r1, #0x3]
 *   @0x23ab30 vmov s15, r10
 *   @0x23ab34 ldrb r10, [r1, #0x1]
 *   @0x23ab38 ldrb r1, [r1, #0x2]
 *   @0x23ab3c vcvt.f32.s32 s15, s15
 *   @0x23ab40 orr r9, r9, r10, lsl #8
 *   @0x23ab44 orr r1, r9, r1, lsl #16
 *   @0x23ab48 vdiv.f32 s15, s15, s17
 *   @0x23ab4c vmul.f32 s15, s15, s17
 *   @0x23ab50 vcvt.s32.f32 s15, s15
 *   @0x23ab54 vmov r9, s15
 *   @0x23ab58 cmp r9, #255
 *   @0x23ab5c movgt r9, #-16777216
 *   @0x23ab60 bgt 0x23ab70 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x2b0>
 *   @0x23ab64 cmp r9, #0
 *   @0x23ab68 lslge r9, r9, #24
 *   @0x23ab6c movlt r9, #0
 *   @0x23ab70 ldrsh r10, [r5]
 *   @0x23ab74 orr r1, r9, r1
 *   @0x23ab78 add r9, r12, #11
 *   @0x23ab7c vldr s11, [r2]
 *   @0x23ab80 vldr s13, [r2, #4]
 *   @0x23ab84 vmul.f32 s11, s16, s11
 *   @0x23ab88 vmov s14, r10
 *   @0x23ab8c ldr r10, [sp, #0x4]
 *   @0x23ab90 vldr s9, [r10, #8]
 *   @0x23ab94 ldr r10, [sp, #0x8]
 *   @0x23ab98 str r1, [r0, #0x84]
 *   @0x23ab9c add r12, r12, #6
 *   @0x23aba0 cmp r10, r9
 *   @0x23aba4 str r1, [r0, #0x6c]
 *   @0x23aba8 str r1, [r0, #0x54]
 *   @0x23abac add r0, r0, #144
 *   @0x23abb0 str r1, [r0, #-0x54]
 *   @0x23abb4 str r1, [r0, #-0x6c]
 *   @0x23abb8 str r1, [r0, #-0x84]
 *   @0x23abbc vmov r1, s14
 *   @0x23abc0 ldr r9, [sp, #0x4]
 *   @0x23abc4 vcvt.f32.s32 s15, s14
 *   @0x23abc8 vmul.f32 s15, s15, s9
 *   @0x23abcc vstr s15, [r0, #-32]
 *   @0x23abd0 vstr s15, [r0, #-128]
 *   @0x23abd4 vstr s15, [r0, #-8]
 *   @0x23abd8 ldrsh r10, [r5, #2]
 *   @0x23abdc vldr s10, [r9, #12]
 *   @0x23abe0 vmul.f32 s13, s16, s13
 *   @0x23abe4 vmov s15, r10
 *   @0x23abe8 vcvt.f32.s32 s12, s15
 *   @0x23abec vmul.f32 s12, s12, s10
 *   @0x23abf0 vstr s12, [r0, #-100]
 *   @0x23abf4 vstr s12, [r0, #-124]
 *   @0x23abf8 vstr s12, [r0, #-4]
 *   @0x23abfc ldrsh r9, [r5, #4]
 *   @0x23ac00 vadd.f32 s12, s11, s19
 *   @0x23ac04 add r1, r1, r9
 *   @0x23ac08 vmov s14, r1
 *   @0x23ac0c vcvt.f32.s32 s14, s14
 *   @0x23ac10 vstr s12, [r0, #-144]
 *   @0x23ac14 vstr s12, [r0, #-24]
 *   @0x23ac18 vstr s12, [r0, #-48]
 *   @0x23ac1c vmul.f32 s14, s9, s14
 *   @0x23ac20 vadd.f32 s12, s13, s18
 *   @0x23ac24 vstr s14, [r0, #-80]
 *   @0x23ac28 vstr s14, [r0, #-56]
 *   @0x23ac2c vadd.f32 s11, s11, s21
 *   @0x23ac30 vstr s12, [r0, #-116]
 *   @0x23ac34 vstr s12, [r0, #-140]
 *   @0x23ac38 vstr s12, [r0, #-20]
 *   @0x23ac3c vadd.f32 s13, s13, s20
 *   @0x23ac40 vstr s11, [r0, #-96]
 *   @0x23ac44 vstr s11, [r0, #-72]
 *   @0x23ac48 vstr s11, [r0, #-120]
 *   @0x23ac4c vstr s13, [r0, #-44]
 *   @0x23ac50 vstr s14, [r0, #-104]
 *   @0x23ac54 ldrsh r1, [r5, #6]
 *   @0x23ac58 vstr s13, [r0, #-92]
 *   @0x23ac5c vstr s13, [r0, #-68]
 *   @0x23ac60 add r1, r10, r1
 *   @0x23ac64 vmov s15, r1
 *   @0x23ac68 vcvt.f32.s32 s15, s15
 *   @0x23ac6c vmul.f32 s15, s10, s15
 *   @0x23ac70 vstr s15, [r0, #-28]
 *   @0x23ac74 vstr s15, [r0, #-76]
 *   @0x23ac78 vstr s15, [r0, #-52]
 *   @0x23ac7c bgt 0x23aaf0 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x230>
 *   @0x23ac80 ldr r9, [sp, #0x14]
 *   @0x23ac84 rsb r9, r12, r9
 *   @0x23ac88 str r9, [sp, #0x14]
 *   @0x23ac8c ldr r10, [sp, #0x14]
 *   @0x23ac90 cmp r10, #0
 *   @0x23ac94 ble 0x23a914 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x54>
 *   @0x23ac98 bl 0x18561c <_ZN8Graphics24GetMaxDynamicVertexCountEv>
 *   @0x23ac9c ldr r9, [sp, #0x14]
 *   @0x23aca0 cmp r0, r9
 *   @0x23aca4 bge 0x23aa84 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x1c4>
 *   @0x23aca8 bl 0x18561c <_ZN8Graphics24GetMaxDynamicVertexCountEv>
 *   @0x23acac str r0, [sp, #0x8]
 *   @0x23acb0 b 0x23aa8c <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x1cc>
 *   @0x23acb4 ldr r9, [sp, #0x18]
 *   @0x23acb8 mov r1, r8
 *   @0x23acbc ldr r12, [sp, #0xc]
 *   @0x23acc0 add r0, r9, r11, lsl #2
 *   @0x23acc4 mov r3, r9
 *   @0x23acc8 ldr r2, [r3], #4
 *   @0x23accc cmp r2, #0
 *   @0x23acd0 beq 0x23acdc <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x41c>
 *   @0x23acd4 tst r2, r12
 *   @0x23acd8 beq 0x23ace0 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x420>
 *   @0x23acdc add r1, r1, #1
 *   @0x23ace0 cmp r3, r0
 *   @0x23ace4 bne 0x23acc8 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x408>
 *   @0x23ace8 b 0x23a9e0 <_ZN13CPhysicsWorld13DrawParticlesEjiP7CSpritei+0x120>
 *   @0x23acec cmnmi pc, #0
 *   @0x23acf0 ldrsheq r2, [r11], -r4
 *
 * ══ §24/28 anon_319630  0x319630  size 1072  268 条（0x319630..0x319a60）
 * @func 0x319630 0x319a60  size 1072  268 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_319630×5 / anon_319630+0x114×2 / anon_319630+0x2a8×2 / restore_core_regs×2 / 0xb65bc×2 / anon_319630+0xb8 / anon_319630+0x7c / 0xb6fc4
 * 字段偏移 top8: 0x4×6 / 0x10×5 / 0x48×4 / 0x14×3 / 0x4c×3 / 0x40×3 / 0xc0×2 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x319630 ldr r3, [r0]
 *   @0x319634 tst r3, #1073741824
 *   @0x319638 orrne r3, r3, #-2147483648
 *   @0x31963c biceq r3, r3, #-2147483648
 *   @0x319640 add r0, r0, r3
 *   @0x319644 bx lr
 *   @0x319648 push {r0, r1, r2, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x31964c cmp r1, #0
 *   @0x319650 mov r9, r0
 *   @0x319654 mov r6, r2
 *   @0x319658 beq 0x3196d0 <__gnu_uldivmod_helper+0xdc>
 *   @0x31965c sub r8, r1, #1
 *   @0x319660 mov r7, #0
 *   @0x319664 mov r10, r8
 *   @0x319668 add r4, r7, r10
 *   @0x31966c add r4, r4, r4, lsr #31
 *   @0x319670 asr r4, r4, #1
 *   @0x319674 lsl r3, r4, #3
 *   @0x319678 str r3, [sp, #0x4]
 *   @0x31967c add r5, r9, r3
 *   @0x319680 mov r0, r5
 *   @0x319684 bl 0x319630 <__gnu_uldivmod_helper+0x3c>
 *   @0x319688 cmp r4, r8
 *   @0x31968c ldr r3, [sp, #0x4]
 *   @0x319690 mov r11, r0
 *   @0x319694 beq 0x3196e0 <__gnu_uldivmod_helper+0xec>
 *   @0x319698 add r0, r3, #8
 *   @0x31969c add r0, r9, r0
 *   @0x3196a0 bl 0x319630 <__gnu_uldivmod_helper+0x3c>
 *   @0x3196a4 cmp r6, r11
 *   @0x3196a8 bhs 0x3196bc <__gnu_uldivmod_helper+0xc8>
 *   @0x3196ac cmp r4, r7
 *   @0x3196b0 beq 0x3196d8 <__gnu_uldivmod_helper+0xe4>
 *   @0x3196b4 sub r10, r4, #1
 *   @0x3196b8 b 0x319668 <__gnu_uldivmod_helper+0x74>
 *   @0x3196bc sub r0, r0, #1
 *   @0x3196c0 cmp r6, r0
 *   @0x3196c4 bls 0x3196e8 <__gnu_uldivmod_helper+0xf4>
 *   @0x3196c8 add r7, r4, #1
 *   @0x3196cc b 0x319668 <__gnu_uldivmod_helper+0x74>
 *   @0x3196d0 mov r5, r1
 *   @0x3196d4 b 0x3196e8 <__gnu_uldivmod_helper+0xf4>
 *   @0x3196d8 mov r5, #0
 *   @0x3196dc b 0x3196e8 <__gnu_uldivmod_helper+0xf4>
 *   @0x3196e0 cmp r6, r0
 *   @0x3196e4 blo 0x3196ac <__gnu_uldivmod_helper+0xb8>
 *   @0x3196e8 mov r0, r5
 *   @0x3196ec add sp, sp, #12
 *   @0x3196f0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x3196f4 cmp r0, #1
 *   @0x3196f8 beq 0x319718 <__gnu_uldivmod_helper+0x124>
 *   @0x3196fc cmp r0, #2
 *   @0x319700 beq 0x319724 <__gnu_uldivmod_helper+0x130>
 *   @0x319704 cmp r0, #0
 *   @0x319708 bne 0x319730 <__gnu_uldivmod_helper+0x13c>
 *   @0x31970c ldr r0, [pc, #0x24]
 *   @0x319710 ldr r0, [pc, r0]
 *   @0x319714 bx lr
 *   @0x319718 ldr r0, [pc, #0x1c]
 *   @0x31971c ldr r0, [pc, r0]
 *   @0x319720 bx lr
 *   @0x319724 ldr r0, [pc, #0x14]
 *   @0x319728 ldr r0, [pc, r0]
 *   @0x31972c bx lr
 *   @0x319730 mov r0, #0
 *   @0x319734 bx lr
 *   @0x319738 andeq r8, sp, r4, lsr #10
 *   @0x31973c andeq r8, sp, r12, lsl r5
 *   @0x319740 andeq r8, sp, r4, lsl r5
 *   @0x319744 ldr r3, [pc, #0xf8]
 *   @0x319748 push {r0, r1, r2, r4, r5, lr}
 *   @0x31974c ldr r3, [pc, r3]
 *   @0x319750 cmp r3, #0
 *   @0x319754 mov r4, r0
 *   @0x319758 sub r5, r1, #2
 *   @0x31975c beq 0x319780 <__gnu_uldivmod_helper+0x18c>
 *   @0x319760 mov r0, r5
 *   @0x319764 add r1, sp, #4
 *   @0x319768 bl 0xb6fc4 <raise@plt+0xc>
 *   @0x31976c mov r12, r0
 *   @0x319770 cmp r0, #0
 *   @0x319774 streq r12, [r4, #0x10]
 *   @0x319778 bne 0x3197a0 <__gnu_uldivmod_helper+0x1ac>
 *   @0x31977c b 0x3197b8 <__gnu_uldivmod_helper+0x1c4>
 *   @0x319780 ldr r12, [pc, #0xc0]
 *   @0x319784 ldr r3, [pc, #0xc0]
 *   @0x319788 ldr r12, [pc, r12]
 *   @0x31978c ldr r3, [pc, r3]
 *   @0x319790 rsb r12, r3, r12
 *   @0x319794 mov r0, r3
 *   @0x319798 asr r12, r12, #3
 *   @0x31979c str r12, [sp, #0x4]
 *   @0x3197a0 mov r2, r5
 *   @0x3197a4 ldr r1, [sp, #0x4]
 *   @0x3197a8 bl 0x319648 <__gnu_uldivmod_helper+0x54>
 *   @0x3197ac subs r5, r0, #0
 *   @0x3197b0 bne 0x3197c0 <__gnu_uldivmod_helper+0x1cc>
 *   @0x3197b4 str r5, [r4, #0x10]
 *   @0x3197b8 mov r0, #9
 *   @0x3197bc b 0x31983c <__gnu_uldivmod_helper+0x248>
 *   @0x3197c0 bl 0x319630 <__gnu_uldivmod_helper+0x3c>
 *   @0x3197c4 ldr r3, [r5, #0x4]
 *   @0x3197c8 cmp r3, #1
 *   @0x3197cc str r0, [r4, #0x48]
 *   @0x3197d0 moveq r3, #0
 *   @0x3197d4 moveq r0, #5
 *   @0x3197d8 streq r3, [r4, #0x10]
 *   @0x3197dc beq 0x31983c <__gnu_uldivmod_helper+0x248>
 *   @0x3197e0 cmp r3, #0
 *   @0x3197e4 add r0, r5, #4
 *   @0x3197e8 strlt r0, [r4, #0x4c]
 *   @0x3197ec movlt r3, #1
 *   @0x3197f0 blt 0x319800 <__gnu_uldivmod_helper+0x20c>
 *   @0x3197f4 bl 0x319630 <__gnu_uldivmod_helper+0x3c>
 *   @0x3197f8 mov r3, #0
 *   @0x3197fc str r0, [r4, #0x4c]
 *   @0x319800 ldr r0, [r4, #0x4c]
 *   @0x319804 str r3, [r4, #0x50]
 *   @0x319808 ldr r3, [r0]
 *   @0x31980c cmp r3, #0
 *   @0x319810 bge 0x319830 <__gnu_uldivmod_helper+0x23c>
 *   @0x319814 ubfx r0, r3, #0x18, #0x4
 *   @0x319818 bl 0x3196f4 <__gnu_uldivmod_helper+0x100>
 *   @0x31981c cmp r0, #0
 *   @0x319820 str r0, [r4, #0x10]
 *   @0x319824 moveq r0, #9
 *   @0x319828 movne r0, #0
 *   @0x31982c b 0x31983c <__gnu_uldivmod_helper+0x248>
 *   @0x319830 bl 0x319630 <__gnu_uldivmod_helper+0x3c>
 *   @0x319834 str r0, [r4, #0x10]
 *   @0x319838 mov r0, #0
 *   @0x31983c add sp, sp, #12
 *   @0x319840 pop {r4, r5, pc}
 *   @0x319844 strdeq r8, r9, [sp], -r4
 *   @0x319848 strheq r8, [sp], -r12
 *   @0x31984c strheq r8, [sp], -r12
 *   @0x319850 ldr r3, [r0]
 *   @0x319854 push {r4, lr}
 *   @0x319858 tst r3, #1
 *   @0x31985c mov r4, r0
 *   @0x319860 bne 0x31987c <__gnu_uldivmod_helper+0x288>
 *   @0x319864 tst r3, #2
 *   @0x319868 add r0, r0, #72
 *   @0x31986c beq 0x319878 <__gnu_uldivmod_helper+0x284>
 *   @0x319870 bl 0x31a52c <__gnu_Unwind_Restore_VFP_D>
 *   @0x319874 b 0x31987c <__gnu_uldivmod_helper+0x288>
 *   @0x319878 bl 0x31a51c <__gnu_Unwind_Restore_VFP>
 *   @0x31987c ldr r3, [r4]
 *   @0x319880 tst r3, #4
 *   @0x319884 bne 0x319890 <__gnu_uldivmod_helper+0x29c>
 *   @0x319888 add r0, r4, #208
 *   @0x31988c bl 0x31a53c <__gnu_Unwind_Restore_VFP_D_16_to_31>
 *   @0x319890 ldr r3, [r4]
 *   @0x319894 tst r3, #8
 *   @0x319898 bne 0x3198a4 <__gnu_uldivmod_helper+0x2b0>
 *   @0x31989c add r0, r4, #336
 *   @0x3198a0 bl 0x31a54c <__gnu_Unwind_Restore_WMMXD>
 *   @0x3198a4 ldr r3, [r4]
 *   @0x3198a8 tst r3, #16
 *   @0x3198ac popne {r4, pc}
 *   @0x3198b0 add r0, r4, #464
 *   @0x3198b4 pop {r4, lr}
 *   @0x3198b8 b 0x31a5d4 <__gnu_Unwind_Restore_WMMXC>
 *   @0x3198bc ldr r3, [r0]
 *   @0x3198c0 cmp r3, #0
 *   @0x3198c4 ldrne r0, [r3, r0]
 *   @0x3198c8 moveq r0, r3
 *   @0x3198cc bx lr
 *   @0x3198d0 mov r0, #9
 *   @0x3198d4 bx lr
 *   @0x3198d8 bx lr
 *   @0x3198dc push {r4, r5, r6, lr}
 *   @0x3198e0 mov r5, r0
 *   @0x3198e4 mov r4, r1
 *   @0x3198e8 mov r0, r5
 *   @0x3198ec ldr r1, [r4, #0x40]
 *   @0x3198f0 bl 0x319744 <__gnu_uldivmod_helper+0x150>
 *   @0x3198f4 subs r6, r0, #0
 *   @0x3198f8 beq 0x319900 <__gnu_uldivmod_helper+0x30c>
 *   @0x3198fc bl 0xb6c88 <abort@plt>
 *   @0x319900 ldr r3, [r4, #0x40]
 *   @0x319904 mov r0, #1
 *   @0x319908 mov r1, r5
 *   @0x31990c mov r2, r4
 *   @0x319910 str r3, [r5, #0x14]
 *   @0x319914 ldr r3, [r5, #0x10]
 *   @0x319918 blx r3
 *   @0x31991c cmp r0, #8
 *   @0x319920 beq 0x3198e8 <__gnu_uldivmod_helper+0x2f4>
 *   @0x319924 cmp r0, #7
 *   @0x319928 bne 0x3198fc <__gnu_uldivmod_helper+0x308>
 *   @0x31992c mov r0, r6
 *   @0x319930 ldr r1, [r4, #0x40]
 *   @0x319934 bl 0x3198d8 <__gnu_uldivmod_helper+0x2e4>
 *   @0x319938 add r0, r4, #4
 *   @0x31993c bl 0x31a508 <restore_core_regs>
 *   @0x319940 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x319944 add lr, r1, #4
 *   @0x319948 ldr r8, [r0, #0xc]
 *   @0x31994c mov r4, r0
 *   @0x319950 ldr r9, [r0, #0x18]
 *   @0x319954 mov r5, r2
 *   @0x319958 ldm lr!, {r0, r1, r2, r3}
 *   @0x31995c sub sp, sp, #972
 *   @0x319960 add r12, sp, #12
 *   @0x319964 add r10, sp, #8
 *   @0x319968 add r11, sp, #488
 *   @0x31996c mov r7, #0
 *   @0x319970 stm r12!, {r0, r1, r2, r3}
 *   @0x319974 ldm lr!, {r0, r1, r2, r3}
 *   @0x319978 stm r12!, {r0, r1, r2, r3}
 *   @0x31997c ldm lr!, {r0, r1, r2, r3}
 *   @0x319980 stm r12!, {r0, r1, r2, r3}
 *   @0x319984 ldm lr, {r0, r1, r2, r3}
 *   @0x319988 stm r12, {r0, r1, r2, r3}
 *   @0x31998c str r7, [sp, #0x8]
 *   @0x319990 mov r0, r4
 *   @0x319994 ldr r1, [sp, #0x48]
 *   @0x319998 bl 0x319744 <__gnu_uldivmod_helper+0x150>
 *   @0x31999c cmp r5, #0
 *   @0x3199a0 movne r6, #10
 *   @0x3199a4 moveq r6, #9
 *   @0x3199a8 subs r5, r0, #0
 *   @0x3199ac orrne r6, r6, #16
 *   @0x3199b0 ldrne r3, [sp, #0x40]
 *   @0x3199b4 bne 0x3199ec <__gnu_uldivmod_helper+0x3f8>
 *   @0x3199b8 ldr r3, [sp, #0x48]
 *   @0x3199bc mov r1, r10
 *   @0x3199c0 mov r2, #480
 *   @0x3199c4 mov r0, r11
 *   @0x3199c8 str r3, [r4, #0x14]
 *   @0x3199cc bl 0xb65bc <memcpy@plt>
 *   @0x3199d0 ldr r3, [r4, #0x10]
 *   @0x3199d4 mov r0, r6
 *   @0x3199d8 mov r1, r4
 *   @0x3199dc mov r2, r11
 *   @0x3199e0 blx r3
 *   @0x3199e4 ldr r3, [sp, #0x220]
 *   @0x3199e8 mov r7, r0
 *   @0x3199ec str r3, [sp, #0x4c]
 *   @0x3199f0 mov r0, #1
 *   @0x3199f4 str r10, [sp]
 *   @0x3199f8 mov r1, r6
 *   @0x3199fc str r9, [sp, #0x4]
 *   @0x319a00 mov r2, r4
 *   @0x319a04 mov r3, r4
 *   @0x319a08 blx r8
 *   @0x319a0c cmp r0, #0
 *   @0x319a10 bne 0x319a50 <__gnu_uldivmod_helper+0x45c>
 *   @0x319a14 cmp r5, #0
 *   @0x319a18 bne 0x319a58 <__gnu_uldivmod_helper+0x464>
 *   @0x319a1c mov r0, r10
 *   @0x319a20 mov r1, r11
 *   @0x319a24 mov r2, #480
 *   @0x319a28 bl 0xb65bc <memcpy@plt>
 *   @0x319a2c cmp r7, #8
 *   @0x319a30 beq 0x319990 <__gnu_uldivmod_helper+0x39c>
 *   @0x319a34 cmp r7, #7
 *   @0x319a38 bne 0x319a50 <__gnu_uldivmod_helper+0x45c>
 *   @0x319a3c mov r0, r5
 *   @0x319a40 ldr r1, [sp, #0x48]
 *   @0x319a44 bl 0x3198d8 <__gnu_uldivmod_helper+0x2e4>
 *   @0x319a48 add r0, sp, #12
 *   @0x319a4c bl 0x31a508 <restore_core_regs>
 *   @0x319a50 mov r0, #9
 *   @0x319a54 b 0x319a5c <__gnu_uldivmod_helper+0x468>
 *   @0x319a58 mov r0, r5
 *   @0x319a5c add sp, sp, #972
 *
 * ══ §25/28 F_Rectangle_In_Rectangle(RValue&, CInstance*, CInstance*, int, RValue*)  0x1079c4  size 1060  265 条（0x1079c4..0x107de8）
 * @func 0x1079c4 0x107de8  size 1060  265 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×8 / F_Rectangle_In_Rectangle(RValue&, CInstance*, CInstance*, int, RValue*)+0x16c×2 / F_Rectangle_In_Rectangle(RValue&, CInstance*, CInstance*, int, RValue*)+0x1a8×2 / F_Rectangle_In_Rectangle(RValue&, CInstance*, CInstance*, int, RValue*)+0x1f0×2 / F_Rectangle_In_Rectangle(RValue&, CInstance*, CInstance*, int, RValue*)+0x374×2 / F_Rectangle_In_Rectangle(RValue&, CInstance*, CInstance*, int, RValue*)+0x3bc×2 / F_Rectangle_In_Rectangle(RValue&, CInstance*, CInstance*, int, RValue*)+0x3ec×2 / F_Rectangle_In_Rectangle(RValue&, CInstance*, CInstance*, int, RValue*)+0x21c×2
 * 字段偏移 top8: 0x30×1 / 0xc×1
 * VFP 指令 143 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1079c4 push {r3, r4, r5, lr}
 *   @0x1079c8 vpush {d8, d9, d10, d11}
 *   @0x1079cc mov r1, #0
 *   @0x1079d0 ldr r4, [sp, #0x30]
 *   @0x1079d4 mov r5, r0
 *   @0x1079d8 str r1, [r0, #0xc]
 *   @0x1079dc mov r0, r4
 *   @0x1079e0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1079e4 mov r1, #1
 *   @0x1079e8 vmov s18, r0
 *   @0x1079ec mov r0, r4
 *   @0x1079f0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1079f4 mov r1, #2
 *   @0x1079f8 vmov s21, r0
 *   @0x1079fc mov r0, r4
 *   @0x107a00 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x107a04 mov r1, #3
 *   @0x107a08 vmov s17, r0
 *   @0x107a0c mov r0, r4
 *   @0x107a10 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x107a14 mov r1, #4
 *   @0x107a18 vmov s20, r0
 *   @0x107a1c mov r0, r4
 *   @0x107a20 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x107a24 mov r1, #5
 *   @0x107a28 vmov s19, r0
 *   @0x107a2c mov r0, r4
 *   @0x107a30 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x107a34 mov r1, #6
 *   @0x107a38 vmov s22, r0
 *   @0x107a3c mov r0, r4
 *   @0x107a40 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x107a44 mov r1, #7
 *   @0x107a48 vmov s16, r0
 *   @0x107a4c mov r0, r4
 *   @0x107a50 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x107a54 vcmpe.f32 s18, s17
 *   @0x107a58 vmrs APSR_nzcv, fpscr
 *   @0x107a5c vcmpe.f32 s21, s20
 *   @0x107a60 vmovle.f32 s14, s17
 *   @0x107a64 vmovle.f32 s17, s18
 *   @0x107a68 vmovle.f32 s18, s14
 *   @0x107a6c vmrs APSR_nzcv, fpscr
 *   @0x107a70 vmov s15, r0
 *   @0x107a74 vmovle.f32 s14, s20
 *   @0x107a78 vcmpe.f32 s19, s16
 *   @0x107a7c vmovle.f32 s20, s21
 *   @0x107a80 vmovle.f32 s21, s14
 *   @0x107a84 vmrs APSR_nzcv, fpscr
 *   @0x107a88 vcmpe.f32 s22, s15
 *   @0x107a8c vmovle.f32 s14, s16
 *   @0x107a90 vmovle.f32 s16, s19
 *   @0x107a94 vmovle.f32 s19, s14
 *   @0x107a98 vmrs APSR_nzcv, fpscr
 *   @0x107a9c vcmpe.f32 s16, s17
 *   @0x107aa0 vmovle.f32 s14, s15
 *   @0x107aa4 vmovle.f32 s15, s22
 *   @0x107aa8 vmovle.f32 s22, s14
 *   @0x107aac vmrs APSR_nzcv, fpscr
 *   @0x107ab0 bhi 0x107ac0 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x107ab4 vcmpe.f32 s19, s17
 *   @0x107ab8 vmrs APSR_nzcv, fpscr
 *   @0x107abc bge 0x107c28 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x264>
 *   @0x107ac0 mov r3, #0
 *   @0x107ac4 vcmpe.f32 s16, s18
 *   @0x107ac8 vmrs APSR_nzcv, fpscr
 *   @0x107acc bhi 0x107adc <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x107ad0 vcmpe.f32 s19, s18
 *   @0x107ad4 vmrs APSR_nzcv, fpscr
 *   @0x107ad8 bge 0x107bf4 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x230>
 *   @0x107adc vcmpe.f32 s16, s17
 *   @0x107ae0 vmrs APSR_nzcv, fpscr
 *   @0x107ae4 bhi 0x107b30 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x107ae8 vcmpe.f32 s19, s17
 *   @0x107aec vmrs APSR_nzcv, fpscr
 *   @0x107af0 blt 0x107b30 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x107af4 vcmpe.f32 s15, s21
 *   @0x107af8 vmrs APSR_nzcv, fpscr
 *   @0x107afc bhi 0x107b30 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x107b00 vcmpe.f32 s22, s21
 *   @0x107b04 vmrs APSR_nzcv, fpscr
 *   @0x107b08 blt 0x107b30 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x107b0c orr r3, r3, #8
 *   @0x107b10 cmp r3, #15
 *   @0x107b14 bne 0x107be0 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x21c>
 *   @0x107b18 mov r3, #0
 *   @0x107b1c mov r2, r3
 *   @0x107b20 movt r3, #0x3ff0
 *   @0x107b24 stm r5, {r2, r3}
 *   @0x107b28 vpop {d8, d9, d10, d11}
 *   @0x107b2c pop {r3, r4, r5, pc}
 *   @0x107b30 cmp r3, #0
 *   @0x107b34 bne 0x107be0 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x21c>
 *   @0x107b38 vcmpe.f32 s16, s17
 *   @0x107b3c vmrs APSR_nzcv, fpscr
 *   @0x107b40 blt 0x107b6c <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x1a8>
 *   @0x107b44 vcmpe.f32 s16, s18
 *   @0x107b48 vmrs APSR_nzcv, fpscr
 *   @0x107b4c bhi 0x107b6c <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x1a8>
 *   @0x107b50 vcmpe.f32 s15, s20
 *   @0x107b54 vmrs APSR_nzcv, fpscr
 *   @0x107b58 blt 0x107b6c <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x1a8>
 *   @0x107b5c vcmpe.f32 s15, s21
 *   @0x107b60 vmrs APSR_nzcv, fpscr
 *   @0x107b64 movhi r3, #0
 *   @0x107b68 movls r3, #1
 *   @0x107b6c vcmpe.f32 s19, s17
 *   @0x107b70 vmrs APSR_nzcv, fpscr
 *   @0x107b74 blt 0x107bb4 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x1f0>
 *   @0x107b78 vcmpe.f32 s19, s18
 *   @0x107b7c vmrs APSR_nzcv, fpscr
 *   @0x107b80 bhi 0x107bb4 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x1f0>
 *   @0x107b84 vcmpe.f32 s15, s20
 *   @0x107b88 vmrs APSR_nzcv, fpscr
 *   @0x107b8c blt 0x107b9c <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x1d8>
 *   @0x107b90 vcmpe.f32 s15, s21
 *   @0x107b94 vmrs APSR_nzcv, fpscr
 *   @0x107b98 orrls r3, r3, #2
 *   @0x107b9c vcmpe.f32 s22, s20
 *   @0x107ba0 vmrs APSR_nzcv, fpscr
 *   @0x107ba4 blt 0x107bb4 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x1f0>
 *   @0x107ba8 vcmpe.f32 s22, s21
 *   @0x107bac vmrs APSR_nzcv, fpscr
 *   @0x107bb0 orrls r3, r3, #4
 *   @0x107bb4 vcmpe.f32 s16, s17
 *   @0x107bb8 vmrs APSR_nzcv, fpscr
 *   @0x107bbc blt 0x107c48 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x284>
 *   @0x107bc0 vcmpe.f32 s16, s18
 *   @0x107bc4 vmrs APSR_nzcv, fpscr
 *   @0x107bc8 bhi 0x107ddc <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x418>
 *   @0x107bcc vcmpe.f32 s22, s20
 *   @0x107bd0 vmrs APSR_nzcv, fpscr
 *   @0x107bd4 bge 0x107dcc <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x408>
 *   @0x107bd8 cmp r3, #0
 *   @0x107bdc beq 0x107c68 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x2a4>
 *   @0x107be0 mov r2, #0
 *   @0x107be4 mov r3, #1073741824
 *   @0x107be8 stm r5, {r2, r3}
 *   @0x107bec vpop {d8, d9, d10, d11}
 *   @0x107bf0 pop {r3, r4, r5, pc}
 *   @0x107bf4 vcmpe.f32 s15, s20
 *   @0x107bf8 vmrs APSR_nzcv, fpscr
 *   @0x107bfc bhi 0x107c0c <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x248>
 *   @0x107c00 vcmpe.f32 s22, s20
 *   @0x107c04 vmrs APSR_nzcv, fpscr
 *   @0x107c08 orrge r3, r3, #2
 *   @0x107c0c vcmpe.f32 s15, s21
 *   @0x107c10 vmrs APSR_nzcv, fpscr
 *   @0x107c14 bhi 0x107adc <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x107c18 vcmpe.f32 s22, s21
 *   @0x107c1c vmrs APSR_nzcv, fpscr
 *   @0x107c20 orrge r3, r3, #4
 *   @0x107c24 b 0x107adc <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x107c28 vcmpe.f32 s15, s20
 *   @0x107c2c vmrs APSR_nzcv, fpscr
 *   @0x107c30 bhi 0x107ac0 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x107c34 vcmpe.f32 s22, s20
 *   @0x107c38 vmrs APSR_nzcv, fpscr
 *   @0x107c3c movlt r3, #0
 *   @0x107c40 movge r3, #1
 *   @0x107c44 b 0x107ac4 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x100>
 *   @0x107c48 cmp r3, #0
 *   @0x107c4c bne 0x107be0 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x21c>
 *   @0x107c50 vcmpe.f32 s16, s17
 *   @0x107c54 vmrs APSR_nzcv, fpscr
 *   @0x107c58 blt 0x107c84 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x2c0>
 *   @0x107c5c vcmpe.f32 s16, s18
 *   @0x107c60 vmrs APSR_nzcv, fpscr
 *   @0x107c64 bhi 0x107dc4 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x400>
 *   @0x107c68 vcmpe.f32 s15, s20
 *   @0x107c6c vmrs APSR_nzcv, fpscr
 *   @0x107c70 bhi 0x107dc4 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x400>
 *   @0x107c74 vcmpe.f32 s22, s20
 *   @0x107c78 vmrs APSR_nzcv, fpscr
 *   @0x107c7c movlt r3, #0
 *   @0x107c80 movge r3, #1
 *   @0x107c84 vcmpe.f32 s19, s17
 *   @0x107c88 vmrs APSR_nzcv, fpscr
 *   @0x107c8c blt 0x107ccc <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x308>
 *   @0x107c90 vcmpe.f32 s19, s18
 *   @0x107c94 vmrs APSR_nzcv, fpscr
 *   @0x107c98 bhi 0x107ccc <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x308>
 *   @0x107c9c vcmpe.f32 s15, s20
 *   @0x107ca0 vmrs APSR_nzcv, fpscr
 *   @0x107ca4 bhi 0x107cb4 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x2f0>
 *   @0x107ca8 vcmpe.f32 s22, s20
 *   @0x107cac vmrs APSR_nzcv, fpscr
 *   @0x107cb0 orrge r3, r3, #2
 *   @0x107cb4 vcmpe.f32 s15, s21
 *   @0x107cb8 vmrs APSR_nzcv, fpscr
 *   @0x107cbc bhi 0x107ccc <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x308>
 *   @0x107cc0 vcmpe.f32 s22, s21
 *   @0x107cc4 vmrs APSR_nzcv, fpscr
 *   @0x107cc8 orrge r3, r3, #4
 *   @0x107ccc vcmpe.f32 s16, s17
 *   @0x107cd0 vmrs APSR_nzcv, fpscr
 *   @0x107cd4 blt 0x107cfc <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x338>
 *   @0x107cd8 vcmpe.f32 s16, s18
 *   @0x107cdc vmrs APSR_nzcv, fpscr
 *   @0x107ce0 bhi 0x107cfc <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x338>
 *   @0x107ce4 vcmpe.f32 s15, s21
 *   @0x107ce8 vmrs APSR_nzcv, fpscr
 *   @0x107cec bhi 0x107cfc <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x338>
 *   @0x107cf0 vcmpe.f32 s22, s21
 *   @0x107cf4 vmrs APSR_nzcv, fpscr
 *   @0x107cf8 bge 0x107be0 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x21c>
 *   @0x107cfc cmp r3, #0
 *   @0x107d00 bne 0x107be0 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x21c>
 *   @0x107d04 vcmpe.f32 s16, s17
 *   @0x107d08 vmrs APSR_nzcv, fpscr
 *   @0x107d0c bhi 0x107d38 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x374>
 *   @0x107d10 vcmpe.f32 s19, s17
 *   @0x107d14 vmrs APSR_nzcv, fpscr
 *   @0x107d18 blt 0x107d38 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x374>
 *   @0x107d1c vcmpe.f32 s15, s20
 *   @0x107d20 vmrs APSR_nzcv, fpscr
 *   @0x107d24 blt 0x107d38 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x374>
 *   @0x107d28 vcmpe.f32 s15, s21
 *   @0x107d2c vmrs APSR_nzcv, fpscr
 *   @0x107d30 movhi r3, #0
 *   @0x107d34 movls r3, #1
 *   @0x107d38 vcmpe.f32 s16, s18
 *   @0x107d3c vmrs APSR_nzcv, fpscr
 *   @0x107d40 bhi 0x107d80 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x3bc>
 *   @0x107d44 vcmpe.f32 s19, s18
 *   @0x107d48 vmrs APSR_nzcv, fpscr
 *   @0x107d4c blt 0x107d80 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x3bc>
 *   @0x107d50 vcmpe.f32 s15, s20
 *   @0x107d54 vmrs APSR_nzcv, fpscr
 *   @0x107d58 blt 0x107d68 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x3a4>
 *   @0x107d5c vcmpe.f32 s15, s21
 *   @0x107d60 vmrs APSR_nzcv, fpscr
 *   @0x107d64 orrls r3, r3, #2
 *   @0x107d68 vcmpe.f32 s22, s20
 *   @0x107d6c vmrs APSR_nzcv, fpscr
 *   @0x107d70 blt 0x107d80 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x3bc>
 *   @0x107d74 vcmpe.f32 s22, s21
 *   @0x107d78 vmrs APSR_nzcv, fpscr
 *   @0x107d7c orrls r3, r3, #4
 *   @0x107d80 vcmpe.f32 s16, s17
 *   @0x107d84 vmrs APSR_nzcv, fpscr
 *   @0x107d88 bhi 0x107db0 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x3ec>
 *   @0x107d8c vcmpe.f32 s19, s17
 *   @0x107d90 vmrs APSR_nzcv, fpscr
 *   @0x107d94 blt 0x107db0 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x3ec>
 *   @0x107d98 vcmpe.f32 s22, s20
 *   @0x107d9c vmrs APSR_nzcv, fpscr
 *   @0x107da0 blt 0x107db0 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x3ec>
 *   @0x107da4 vcmpe.f32 s22, s21
 *   @0x107da8 vmrs APSR_nzcv, fpscr
 *   @0x107dac bls 0x107be0 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x21c>
 *   @0x107db0 cmp r3, #0
 *   @0x107db4 streq r3, [r5]
 *   @0x107db8 streq r3, [r5, #0x4]
 *   @0x107dbc beq 0x107bec <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x228>
 *   @0x107dc0 b 0x107be0 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x21c>
 *   @0x107dc4 mov r3, #0
 *   @0x107dc8 b 0x107c84 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x2c0>
 *   @0x107dcc vcmpe.f32 s22, s21
 *   @0x107dd0 vmrs APSR_nzcv, fpscr
 *   @0x107dd4 bls 0x107be0 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x21c>
 *   @0x107dd8 b 0x107bd8 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x214>
 *   @0x107ddc cmp r3, #0
 *   @0x107de0 beq 0x107c5c <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x298>
 *   @0x107de4 b 0x107be0 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x21c>
 *
 * ══ §26/28 Sprite_Add_Alpha(char const*, int, bool, bool, int, int)  0x1f03cc  size 1060  265 条（0x1f03cc..0x1f07f0）
 * @func 0x1f03cc 0x1f07f0  size 1060  265 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1f0428→0x7530d8, 0x1f0430→0x7530d0, 0x1f046c→0x7530dc, 0x1f04c0→0x7530e0
 * 调用序列: MemoryManager::SetLength(void**, unsigned int, char const*, int)×2 / LoadSave::SaveFileExists(char const*) / LoadSave::_GetSaveFileName(char*, int, char const*) / 0xb65c8 / YYStrDup(char const*) / unsigned int CHashMapCalculateHash<char const*>(char const*) / Sprite_Add_Alpha(char const*, int, bool, bool, int, int)+0x16c / operator new(unsigned int)
 * 字段偏移 top8: 0x4×12 / 0x8×10 / 0x2×6 / 0x10×5 / 0x1c×4 / 0x20×4 / 0x28×3 / 0x2c×2
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f03cc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1f03d0 sub sp, sp, #1344
 *   @0x1f03d4 sub sp, sp, #4
 *   @0x1f03d8 ldr r4, [pc, #0x3ec]
 *   @0x1f03dc mov r5, r0
 *   @0x1f03e0 str r1, [sp, #0x2c]
 *   @0x1f03e4 add r4, pc, r4
 *   @0x1f03e8 ldr r1, [pc, #0x3e0]
 *   @0x1f03ec str r3, [sp, #0x34]
 *   @0x1f03f0 str r2, [sp, #0x30]
 *   @0x1f03f4 ldr r1, [r4, r1]
 *   @0x1f03f8 ldr r3, [r1]
 *   @0x1f03fc str r1, [sp, #0x24]
 *   @0x1f0400 str r3, [sp, #0x53c]
 *   @0x1f0404 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0x1f0408 cmp r0, #0
 *   @0x1f040c beq 0x1f068c <_Z16Sprite_Add_AlphaPKcibbii+0x2c0>
 *   @0x1f0410 add r3, sp, #316
 *   @0x1f0414 mov r2, r5
 *   @0x1f0418 mov r1, #1024
 *   @0x1f041c str r3, [sp, #0x28]
 *   @0x1f0420 mov r0, r3
 *   @0x1f0424 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x1f0428 ldr r2, [pc, #0x3a4]
 *   @0x1f042c movw r3, #0x2d7
 *   @0x1f0430 ldr r0, [pc, #0x3a0]
 *   @0x1f0434 ldr r5, [pc, #0x3a0]
 *   @0x1f0438 ldr r6, [r4, r2]
 *   @0x1f043c add r5, pc, r5
 *   @0x1f0440 ldr r1, [r6]
 *   @0x1f0444 mov r2, r5
 *   @0x1f0448 add r1, r1, #1
 *   @0x1f044c str r1, [r6]
 *   @0x1f0450 ldr r0, [r4, r0]
 *   @0x1f0454 lsl r1, r1, #2
 *   @0x1f0458 str r0, [sp, #0x1c]
 *   @0x1f045c add r0, r0, #4
 *   @0x1f0460 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1f0464 ldr r1, [r6]
 *   @0x1f0468 mov r2, r5
 *   @0x1f046c ldr r0, [pc, #0x36c]
 *   @0x1f0470 ldr r5, [sp, #0x1c]
 *   @0x1f0474 movw r3, #0x2d9
 *   @0x1f0478 str r1, [r5]
 *   @0x1f047c lsl r1, r1, #2
 *   @0x1f0480 ldr r0, [r4, r0]
 *   @0x1f0484 add r5, sp, #60
 *   @0x1f0488 str r0, [sp, #0x20]
 *   @0x1f048c bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1f0490 ldr r3, [r6]
 *   @0x1f0494 mov r1, #256
 *   @0x1f0498 ldr r2, [pc, #0x344]
 *   @0x1f049c mov r0, r5
 *   @0x1f04a0 sub r3, r3, #1
 *   @0x1f04a4 add r2, pc, r2
 *   @0x1f04a8 bl 0xb65c8 <snprintf@plt>
 *   @0x1f04ac ldr r12, [sp, #0x20]
 *   @0x1f04b0 mov r0, r5
 *   @0x1f04b4 ldr r8, [r6]
 *   @0x1f04b8 ldr r7, [r12]
 *   @0x1f04bc bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1f04c0 ldr r2, [pc, #0x320]
 *   @0x1f04c4 sub r8, r8, #-1073741823
 *   @0x1f04c8 ldr r5, [r6]
 *   @0x1f04cc ldr r12, [sp, #0x20]
 *   @0x1f04d0 sub r3, r5, #-1073741823
 *   @0x1f04d4 sub r5, r5, #1
 *   @0x1f04d8 str r0, [r7, r8, lsl #2]
 *   @0x1f04dc ldr r7, [r4, r2]
 *   @0x1f04e0 ldr r0, [r12]
 *   @0x1f04e4 ldr r2, [r7, #0x4]
 *   @0x1f04e8 ldr r1, [r7, #0xc]
 *   @0x1f04ec ldr r4, [r0, r3, lsl #2]
 *   @0x1f04f0 cmp r2, r1
 *   @0x1f04f4 bgt 0x1f06b8 <_Z16Sprite_Add_AlphaPKcibbii+0x2ec>
 *   @0x1f04f8 mov r0, r4
 *   @0x1f04fc add r2, r2, #1
 *   @0x1f0500 str r2, [r7, #0x4]
 *   @0x1f0504 bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_>
 *   @0x1f0508 ldr lr, [r7, #0x8]
 *   @0x1f050c ldr r10, [r7, #0x10]
 *   @0x1f0510 bic r0, r0, #-2147483648
 *   @0x1f0514 and r3, r0, lr
 *   @0x1f0518 add r2, r3, r3, lsl #1
 *   @0x1f051c add r2, r10, r2, lsl #2
 *   @0x1f0520 ldr r1, [r2, #0x8]
 *   @0x1f0524 cmp r1, #0
 *   @0x1f0528 ldrne r11, [r7]
 *   @0x1f052c movne r8, #0
 *   @0x1f0530 bne 0x1f0578 <_Z16Sprite_Add_AlphaPKcibbii+0x1ac>
 *   @0x1f0534 b 0x1f05c4 <_Z16Sprite_Add_AlphaPKcibbii+0x1f8>
 *   @0x1f0538 ldr r9, [r2]
 *   @0x1f053c ldr r8, [r2, #0x4]
 *   @0x1f0540 str r0, [r2, #0x8]
 *   @0x1f0544 mov r0, r1
 *   @0x1f0548 str r4, [r2]
 *   @0x1f054c mov r4, r9
 *   @0x1f0550 str r5, [r2, #0x4]
 *   @0x1f0554 mov r5, r8
 *   @0x1f0558 add r3, r3, #1
 *   @0x1f055c add r8, r12, #1
 *   @0x1f0560 and r3, r3, lr
 *   @0x1f0564 add r2, r3, r3, lsl #1
 *   @0x1f0568 add r2, r10, r2, lsl #2
 *   @0x1f056c ldr r1, [r2, #0x8]
 *   @0x1f0570 cmp r1, #0
 *   @0x1f0574 beq 0x1f05c4 <_Z16Sprite_Add_AlphaPKcibbii+0x1f8>
 *   @0x1f0578 add r12, r3, r11
 *   @0x1f057c and r9, r1, lr
 *   @0x1f0580 rsb r12, r9, r12
 *   @0x1f0584 and r12, r12, lr
 *   @0x1f0588 cmp r12, r8
 *   @0x1f058c blt 0x1f0538 <_Z16Sprite_Add_AlphaPKcibbii+0x16c>
 *   @0x1f0590 movne r12, r8
 *   @0x1f0594 bne 0x1f0558 <_Z16Sprite_Add_AlphaPKcibbii+0x18c>
 *   @0x1f0598 cmp r1, r0
 *   @0x1f059c bne 0x1f0558 <_Z16Sprite_Add_AlphaPKcibbii+0x18c>
 *   @0x1f05a0 ldr r8, [r2]
 *   @0x1f05a4 cmp r4, r8
 *   @0x1f05a8 bne 0x1f0558 <_Z16Sprite_Add_AlphaPKcibbii+0x18c>
 *   @0x1f05ac ldr r3, [r7, #0x4]
 *   @0x1f05b0 str r1, [r2, #0x8]
 *   @0x1f05b4 stm r2, {r4, r5}
 *   @0x1f05b8 sub r3, r3, #1
 *   @0x1f05bc str r3, [r7, #0x4]
 *   @0x1f05c0 b 0x1f05cc <_Z16Sprite_Add_AlphaPKcibbii+0x200>
 *   @0x1f05c4 stm r2, {r4, r5}
 *   @0x1f05c8 str r0, [r2, #0x8]
 *   @0x1f05cc mov r0, #136
 *   @0x1f05d0 bl 0x27c524 <_Znwj>
 *   @0x1f05d4 mov r4, r0
 *   @0x1f05d8 bl 0x1e761c <_ZN7CSpriteC2Ev>
 *   @0x1f05dc ldr r5, [sp, #0x1c]
 *   @0x1f05e0 mov r12, #1
 *   @0x1f05e4 ldr lr, [r6]
 *   @0x1f05e8 ldr r1, [sp, #0x28]
 *   @0x1f05ec ldr r0, [r5, #0x4]
 *   @0x1f05f0 sub lr, lr, #-1073741823
 *   @0x1f05f4 ldr r2, [sp, #0x2c]
 *   @0x1f05f8 ldr r3, [sp, #0x30]
 *   @0x1f05fc str r4, [r0, lr, lsl #2]
 *   @0x1f0600 mov r4, #0
 *   @0x1f0604 ldr r0, [r5, #0x4]
 *   @0x1f0608 ldr r5, [sp, #0x34]
 *   @0x1f060c ldr r0, [r0, lr, lsl #2]
 *   @0x1f0610 str r5, [sp, #0x8]
 *   @0x1f0614 ldr lr, [sp, #0x568]
 *   @0x1f0618 ldr r5, [sp, #0x56c]
 *   @0x1f061c str r12, [sp]
 *   @0x1f0620 str lr, [sp, #0xc]
 *   @0x1f0624 str r5, [sp, #0x10]
 *   @0x1f0628 str r12, [sp, #0x14]
 *   @0x1f062c str r4, [sp, #0x4]
 *   @0x1f0630 bl 0x1e7270 <_ZN7CSprite12LoadFromFileEPKcibbbbiib>
 *   @0x1f0634 cmp r0, r4
 *   @0x1f0638 beq 0x1f07b0 <_Z16Sprite_Add_AlphaPKcibbii+0x3e4>
 *   @0x1f063c ldr r12, [sp, #0x1c]
 *   @0x1f0640 ldr r5, [sp, #0x20]
 *   @0x1f0644 ldr r2, [r6]
 *   @0x1f0648 ldr r3, [r12, #0x4]
 *   @0x1f064c ldr r0, [r5]
 *   @0x1f0650 sub r1, r2, #-1073741823
 *   @0x1f0654 sub r2, r2, #1
 *   @0x1f0658 ldr r3, [r3, r1, lsl #2]
 *   @0x1f065c ldr r1, [r0, r1, lsl #2]
 *   @0x1f0660 mov r0, r2
 *   @0x1f0664 str r2, [r3, #0x60]
 *   @0x1f0668 str r1, [r3, #0x5c]
 *   @0x1f066c ldr r12, [sp, #0x24]
 *   @0x1f0670 ldr r2, [sp, #0x53c]
 *   @0x1f0674 ldr r3, [r12]
 *   @0x1f0678 cmp r2, r3
 *   @0x1f067c bne 0x1f07c4 <_Z16Sprite_Add_AlphaPKcibbii+0x3f8>
 *   @0x1f0680 add sp, sp, #1344
 *   @0x1f0684 add sp, sp, #4
 *   @0x1f0688 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1f068c mov r0, r5
 *   @0x1f0690 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0x1f0694 cmp r0, #0
 *   @0x1f0698 beq 0x1f07a8 <_Z16Sprite_Add_AlphaPKcibbii+0x3dc>
 *   @0x1f069c add r3, sp, #316
 *   @0x1f06a0 mov r2, r5
 *   @0x1f06a4 mov r1, #1024
 *   @0x1f06a8 str r3, [sp, #0x28]
 *   @0x1f06ac mov r0, r3
 *   @0x1f06b0 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc>
 *   @0x1f06b4 b 0x1f0428 <_Z16Sprite_Add_AlphaPKcibbii+0x5c>
 *   @0x1f06b8 ldr r9, [r7]
 *   @0x1f06bc mov r3, #1
 *   @0x1f06c0 ldr r1, [pc, #0x124]
 *   @0x1f06c4 mov r2, #70
 *   @0x1f06c8 ldr r11, [r7, #0x10]
 *   @0x1f06cc lsl r0, r9, r3
 *   @0x1f06d0 add r1, pc, r1
 *   @0x1f06d4 add r8, r0, r9, lsl #2
 *   @0x1f06d8 str r0, [r7]
 *   @0x1f06dc sub r0, r0, #1
 *   @0x1f06e0 str r0, [r7, #0x8]
 *   @0x1f06e4 lsl r8, r8, #2
 *   @0x1f06e8 mov r0, r8
 *   @0x1f06ec bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1f06f0 mov r2, r8
 *   @0x1f06f4 mov r1, #0
 *   @0x1f06f8 str r0, [r7, #0x10]
 *   @0x1f06fc bl 0xb65b0 <memset@plt>
 *   @0x1f0700 ldr r2, [r7]
 *   @0x1f0704 vldr s15, [pc, #188]
 *   @0x1f0708 mov r1, #0
 *   @0x1f070c str r1, [r7, #0x4]
 *   @0x1f0710 cmp r2, r1
 *   @0x1f0714 vmov s13, r2
 *   @0x1f0718 vcvt.f32.s32 s14, s13
 *   @0x1f071c vmul.f32 s15, s14, s15
 *   @0x1f0720 vcvt.s32.f32 s15, s15
 *   @0x1f0724 vstr s15, [r7, #12]
 *   @0x1f0728 ble 0x1f0748 <_Z16Sprite_Add_AlphaPKcibbii+0x37c>
 *   @0x1f072c add r2, r2, r2, lsl #1
 *   @0x1f0730 ldr r3, [r7, #0x10]
 *   @0x1f0734 add r2, r3, r2, lsl #2
 *   @0x1f0738 str r1, [r3, #0x8]
 *   @0x1f073c add r3, r3, #12
 *   @0x1f0740 cmp r3, r2
 *   @0x1f0744 bne 0x1f0738 <_Z16Sprite_Add_AlphaPKcibbii+0x36c>
 *   @0x1f0748 cmp r9, #0
 *   @0x1f074c movgt r8, r11
 *   @0x1f0750 movgt r10, #0
 *   @0x1f0754 ble 0x1f0780 <_Z16Sprite_Add_AlphaPKcibbii+0x3b4>
 *   @0x1f0758 ldr r3, [r8, #0x8]
 *   @0x1f075c cmp r3, #0
 *   @0x1f0760 ble 0x1f0770 <_Z16Sprite_Add_AlphaPKcibbii+0x3a4>
 *   @0x1f0764 mov r0, r7
 *   @0x1f0768 ldm r8, {r1, r2}
 *   @0x1f076c bl 0xd261c <_ZN8CHashMapIPKciLi7EE6InsertES1_i>
 *   @0x1f0770 add r10, r10, #1
 *   @0x1f0774 add r8, r8, #12
 *   @0x1f0778 cmp r10, r9
 *   @0x1f077c bne 0x1f0758 <_Z16Sprite_Add_AlphaPKcibbii+0x38c>
 *   @0x1f0780 mov r0, r11
 *   @0x1f0784 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f0788 vldr s13, [r7]
 *   @0x1f078c vcvt.f32.s32 s14, s13
 *   @0x1f0790 vldr s15, [pc, #48]
 *   @0x1f0794 ldr r2, [r7, #0x4]
 *   @0x1f0798 vmul.f32 s15, s14, s15
 *   @0x1f079c vcvt.s32.f32 s15, s15
 *   @0x1f07a0 vstr s15, [r7, #12]
 *   @0x1f07a4 b 0x1f04f8 <_Z16Sprite_Add_AlphaPKcibbii+0x12c>
 *   @0x1f07a8 mvn r0, #0
 *   @0x1f07ac b 0x1f066c <_Z16Sprite_Add_AlphaPKcibbii+0x2a0>
 *   @0x1f07b0 ldr r3, [r6]
 *   @0x1f07b4 mvn r0, #0
 *   @0x1f07b8 add r3, r3, r0
 *   @0x1f07bc str r3, [r6]
 *   @0x1f07c0 b 0x1f066c <_Z16Sprite_Add_AlphaPKcibbii+0x2a0>
 *   @0x1f07c4 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x1f07c8 svclo #0x19999a
 *   @0x1f07cc eoreq r1, r0, r12, ror #16
 *   @0x1f07d0 .word 0xffffbd00
 *   @0x1f07d4 .word 0xfffff1c0
 *   @0x1f07d8 .word 0xfffff1b8
 *   @0x1f07dc andseq r2, r6, r4, lsl #4
 *   @0x1f07e0 .word 0xfffff1bc
 *   @0x1f07e4 ldrsbeq r2, [r6], -r4
 *   @0x1f07e8 .word 0xfffff1c4
 *   @0x1f07ec andseq r0, r4, r0, ror #18
 *
 * ══ §27/28 Sprite_Load(CStream*)  0x1f0d28  size 1060  265 条（0x1f0d28..0x1f114c）
 * @func 0x1f0d28 0x1f114c  size 1060  265 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1f0d84→0x7530d8, 0x1f0d8c→0x7530d0, 0x1f0dbc→0x7530dc, 0x1f0e98→0x7530e0
 * 调用序列: CStream::ReadInteger()×2 / MemoryManager::SetLength(void**, unsigned int, char const*, int)×2 / Sprite_Load(CStream*)+0x3f4×2 / Sprite_Init() / CStream::ReadBoolean() / CStream::ReadString(char const*&) / operator new(unsigned int) / CSprite::CSprite()
 * 字段偏移 top8: 0x4×19 / 0x8×19 / 0x10×7 / 0x2×6 / 0x18×5 / 0xc×4 / 0x1c×4 / 0x20×3
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f0d28 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1f0d2c vpush {d8}
 *   @0x1f0d30 sub sp, sp, #44
 *   @0x1f0d34 ldr r6, [pc, #0x3f4]
 *   @0x1f0d38 str r0, [sp, #0x18]
 *   @0x1f0d3c add r6, pc, r6
 *   @0x1f0d40 str r6, [sp, #0x20]
 *   @0x1f0d44 bl 0x1eebbc <_Z11Sprite_Initv>
 *   @0x1f0d48 ldr r0, [sp, #0x18]
 *   @0x1f0d4c bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x1f0d50 cmp r0, #800
 *   @0x1f0d54 cmpne r0, #400
 *   @0x1f0d58 str r0, [sp, #0xc]
 *   @0x1f0d5c moveq r4, #0
 *   @0x1f0d60 movne r4, #1
 *   @0x1f0d64 beq 0x1f0d78 <_Z11Sprite_LoadP7CStream+0x50>
 *   @0x1f0d68 mov r0, #0
 *   @0x1f0d6c add sp, sp, #44
 *   @0x1f0d70 vpop {d8}
 *   @0x1f0d74 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1f0d78 ldr r0, [sp, #0x18]
 *   @0x1f0d7c bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x1f0d80 ldr r6, [sp, #0x20]
 *   @0x1f0d84 ldr lr, [pc, #0x3a8]
 *   @0x1f0d88 mov r3, #184
 *   @0x1f0d8c ldr r12, [pc, #0x3a4]
 *   @0x1f0d90 ldr r5, [pc, #0x3a4]
 *   @0x1f0d94 ldr lr, [r6, lr]
 *   @0x1f0d98 add r5, pc, r5
 *   @0x1f0d9c str lr, [sp, #0x1c]
 *   @0x1f0da0 mov r2, r5
 *   @0x1f0da4 str r0, [lr]
 *   @0x1f0da8 lsl r1, r0, #2
 *   @0x1f0dac ldr r8, [r6, r12]
 *   @0x1f0db0 add r0, r8, #4
 *   @0x1f0db4 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1f0db8 ldr r12, [sp, #0x1c]
 *   @0x1f0dbc ldr r0, [pc, #0x37c]
 *   @0x1f0dc0 mov r3, #186
 *   @0x1f0dc4 mov r2, r5
 *   @0x1f0dc8 ldr r1, [r12]
 *   @0x1f0dcc str r1, [r8]
 *   @0x1f0dd0 lsl r1, r1, #2
 *   @0x1f0dd4 ldr r0, [r6, r0]
 *   @0x1f0dd8 str r0, [sp, #0x10]
 *   @0x1f0ddc bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1f0de0 ldr r6, [sp, #0x1c]
 *   @0x1f0de4 ldr r3, [r6]
 *   @0x1f0de8 cmp r3, #0
 *   @0x1f0dec ble 0x1f111c <_Z11Sprite_LoadP7CStream+0x3f4>
 *   @0x1f0df0 ldr r12, [pc, #0x34c]
 *   @0x1f0df4 mov r7, r4
 *   @0x1f0df8 vldr s16, [pc, #812]
 *   @0x1f0dfc add r12, pc, r12
 *   @0x1f0e00 str r12, [sp, #0x24]
 *   @0x1f0e04 b 0x1f0e28 <_Z11Sprite_LoadP7CStream+0x100>
 *   @0x1f0e08 ldr r12, [sp, #0xc]
 *   @0x1f0e0c cmp r12, #800
 *   @0x1f0e10 beq 0x1f0fb4 <_Z11Sprite_LoadP7CStream+0x28c>
 *   @0x1f0e14 ldr r6, [sp, #0x1c]
 *   @0x1f0e18 add r7, r7, #1
 *   @0x1f0e1c ldr r3, [r6]
 *   @0x1f0e20 cmp r3, r7
 *   @0x1f0e24 ble 0x1f111c <_Z11Sprite_LoadP7CStream+0x3f4>
 *   @0x1f0e28 ldr r6, [sp, #0xc]
 *   @0x1f0e2c cmp r6, #800
 *   @0x1f0e30 beq 0x1f1000 <_Z11Sprite_LoadP7CStream+0x2d8>
 *   @0x1f0e34 ldr r12, [sp, #0x18]
 *   @0x1f0e38 str r12, [sp, #0x4]
 *   @0x1f0e3c ldr r0, [sp, #0x4]
 *   @0x1f0e40 lsl r6, r7, #2
 *   @0x1f0e44 str r6, [sp, #0x14]
 *   @0x1f0e48 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv>
 *   @0x1f0e4c ldr r3, [r8, #0x4]
 *   @0x1f0e50 mov r12, #0
 *   @0x1f0e54 ldr r6, [sp, #0x10]
 *   @0x1f0e58 str r12, [r3, r7, lsl #2]
 *   @0x1f0e5c ldr r3, [r6]
 *   @0x1f0e60 str r12, [r3, r7, lsl #2]
 *   @0x1f0e64 cmp r0, r12
 *   @0x1f0e68 beq 0x1f0e08 <_Z11Sprite_LoadP7CStream+0xe0>
 *   @0x1f0e6c ldr r6, [sp, #0x10]
 *   @0x1f0e70 ldr r12, [sp, #0x14]
 *   @0x1f0e74 ldr r0, [sp, #0x4]
 *   @0x1f0e78 ldr r1, [r6]
 *   @0x1f0e7c add r1, r1, r12
 *   @0x1f0e80 bl 0x2018e8 <_ZN7CStream10ReadStringERPKc>
 *   @0x1f0e84 mov r0, #136
 *   @0x1f0e88 bl 0x27c524 <_Znwj>
 *   @0x1f0e8c mov r4, r0
 *   @0x1f0e90 bl 0x1e761c <_ZN7CSpriteC2Ev>
 *   @0x1f0e94 ldr r3, [r8, #0x4]
 *   @0x1f0e98 ldr r1, [pc, #0x2a8]
 *   @0x1f0e9c str r4, [r3, r7, lsl #2]
 *   @0x1f0ea0 ldr r3, [r6]
 *   @0x1f0ea4 ldr r2, [r8, #0x4]
 *   @0x1f0ea8 ldr r6, [sp, #0x20]
 *   @0x1f0eac ldr r0, [r3, r7, lsl #2]
 *   @0x1f0eb0 ldr r2, [r2, r7, lsl #2]
 *   @0x1f0eb4 str r0, [r2, #0x5c]
 *   @0x1f0eb8 str r7, [r2, #0x60]
 *   @0x1f0ebc ldr r2, [r6, r1]
 *   @0x1f0ec0 ldr r5, [r3, r7, lsl #2]
 *   @0x1f0ec4 str r2, [sp, #0x8]
 *   @0x1f0ec8 ldr r3, [r2, #0x4]
 *   @0x1f0ecc ldr r2, [r2, #0xc]
 *   @0x1f0ed0 cmp r3, r2
 *   @0x1f0ed4 bgt 0x1f1010 <_Z11Sprite_LoadP7CStream+0x2e8>
 *   @0x1f0ed8 ldr r6, [sp, #0x8]
 *   @0x1f0edc mov r0, r5
 *   @0x1f0ee0 add r3, r3, #1
 *   @0x1f0ee4 str r3, [r6, #0x4]
 *   @0x1f0ee8 bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_>
 *   @0x1f0eec ldr lr, [r6, #0x8]
 *   @0x1f0ef0 ldr r10, [r6, #0x10]
 *   @0x1f0ef4 bic r0, r0, #-2147483648
 *   @0x1f0ef8 and r3, r0, lr
 *   @0x1f0efc add r2, r3, r3, lsl #1
 *   @0x1f0f00 add r2, r10, r2, lsl #2
 *   @0x1f0f04 ldr r1, [r2, #0x8]
 *   @0x1f0f08 cmp r1, #0
 *   @0x1f0f0c beq 0x1f0fd4 <_Z11Sprite_LoadP7CStream+0x2ac>
 *   @0x1f0f10 ldr r12, [sp, #0x8]
 *   @0x1f0f14 mov r9, r7
 *   @0x1f0f18 mov r4, #0
 *   @0x1f0f1c ldr r11, [r12]
 *   @0x1f0f20 b 0x1f0f64 <_Z11Sprite_LoadP7CStream+0x23c>
 *   @0x1f0f24 ldr r6, [r2]
 *   @0x1f0f28 ldr r4, [r2, #0x4]
 *   @0x1f0f2c str r0, [r2, #0x8]
 *   @0x1f0f30 mov r0, r1
 *   @0x1f0f34 str r5, [r2]
 *   @0x1f0f38 mov r5, r6
 *   @0x1f0f3c str r9, [r2, #0x4]
 *   @0x1f0f40 mov r9, r4
 *   @0x1f0f44 add r3, r3, #1
 *   @0x1f0f48 add r4, r12, #1
 *   @0x1f0f4c and r3, r3, lr
 *   @0x1f0f50 add r2, r3, r3, lsl #1
 *   @0x1f0f54 add r2, r10, r2, lsl #2
 *   @0x1f0f58 ldr r1, [r2, #0x8]
 *   @0x1f0f5c cmp r1, #0
 *   @0x1f0f60 beq 0x1f0fd8 <_Z11Sprite_LoadP7CStream+0x2b0>
 *   @0x1f0f64 add r12, r11, r3
 *   @0x1f0f68 and r6, r1, lr
 *   @0x1f0f6c rsb r12, r6, r12
 *   @0x1f0f70 and r12, r12, lr
 *   @0x1f0f74 cmp r12, r4
 *   @0x1f0f78 blt 0x1f0f24 <_Z11Sprite_LoadP7CStream+0x1fc>
 *   @0x1f0f7c movne r12, r4
 *   @0x1f0f80 bne 0x1f0f44 <_Z11Sprite_LoadP7CStream+0x21c>
 *   @0x1f0f84 cmp r1, r0
 *   @0x1f0f88 bne 0x1f0f44 <_Z11Sprite_LoadP7CStream+0x21c>
 *   @0x1f0f8c ldr r4, [r2]
 *   @0x1f0f90 cmp r5, r4
 *   @0x1f0f94 bne 0x1f0f44 <_Z11Sprite_LoadP7CStream+0x21c>
 *   @0x1f0f98 ldr r12, [sp, #0x8]
 *   @0x1f0f9c str r1, [r2, #0x8]
 *   @0x1f0fa0 ldr r3, [r12, #0x4]
 *   @0x1f0fa4 stm r2, {r5, r9}
 *   @0x1f0fa8 sub r3, r3, #1
 *   @0x1f0fac str r3, [r12, #0x4]
 *   @0x1f0fb0 b 0x1f0fe0 <_Z11Sprite_LoadP7CStream+0x2b8>
 *   @0x1f0fb4 ldr r12, [sp, #0x4]
 *   @0x1f0fb8 cmp r12, #0
 *   @0x1f0fbc beq 0x1f0e14 <_Z11Sprite_LoadP7CStream+0xec>
 *   @0x1f0fc0 mov r0, r12
 *   @0x1f0fc4 bl 0x201328 <_ZN7CStreamD2Ev>
 *   @0x1f0fc8 ldr r0, [sp, #0x4]
 *   @0x1f0fcc bl 0x27d1d0 <_ZdlPv>
 *   @0x1f0fd0 b 0x1f0e14 <_Z11Sprite_LoadP7CStream+0xec>
 *   @0x1f0fd4 mov r9, r7
 *   @0x1f0fd8 stm r2, {r5, r9}
 *   @0x1f0fdc str r0, [r2, #0x8]
 *   @0x1f0fe0 ldr r3, [r8, #0x4]
 *   @0x1f0fe4 ldr r6, [sp, #0x14]
 *   @0x1f0fe8 ldr r1, [sp, #0x4]
 *   @0x1f0fec ldr r0, [r3, r6]
 *   @0x1f0ff0 bl 0x1e7854 <_ZN7CSprite14LoadFromStreamEP7CStream>
 *   @0x1f0ff4 cmp r0, #0
 *   @0x1f0ff8 bne 0x1f0e08 <_Z11Sprite_LoadP7CStream+0xe0>
 *   @0x1f0ffc b 0x1f0d68 <_Z11Sprite_LoadP7CStream+0x40>
 *   @0x1f1000 ldr r0, [sp, #0x18]
 *   @0x1f1004 bl 0x201db0 <_ZN7CStream20ReadCompressedStreamEv>
 *   @0x1f1008 str r0, [sp, #0x4]
 *   @0x1f100c b 0x1f0e3c <_Z11Sprite_LoadP7CStream+0x114>
 *   @0x1f1010 ldr r12, [sp, #0x8]
 *   @0x1f1014 mov r3, #1
 *   @0x1f1018 ldr r1, [sp, #0x24]
 *   @0x1f101c mov r2, #70
 *   @0x1f1020 ldr r6, [r12]
 *   @0x1f1024 ldr r10, [r12, #0x10]
 *   @0x1f1028 lsl r0, r6, r3
 *   @0x1f102c str r0, [r12]
 *   @0x1f1030 add r4, r0, r6, lsl #2
 *   @0x1f1034 sub r0, r0, #1
 *   @0x1f1038 str r0, [r12, #0x8]
 *   @0x1f103c lsl r4, r4, #2
 *   @0x1f1040 mov r0, r4
 *   @0x1f1044 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1f1048 ldr r12, [sp, #0x8]
 *   @0x1f104c mov r2, r4
 *   @0x1f1050 mov r1, #0
 *   @0x1f1054 str r0, [r12, #0x10]
 *   @0x1f1058 bl 0xb65b0 <memset@plt>
 *   @0x1f105c ldr r12, [sp, #0x8]
 *   @0x1f1060 mov lr, #0
 *   @0x1f1064 ldr r2, [r12]
 *   @0x1f1068 str lr, [r12, #0x4]
 *   @0x1f106c cmp r2, lr
 *   @0x1f1070 vmov s14, r2
 *   @0x1f1074 vcvt.f32.s32 s15, s14
 *   @0x1f1078 vmul.f32 s15, s15, s16
 *   @0x1f107c vcvt.s32.f32 s15, s15
 *   @0x1f1080 vstr s15, [r12, #12]
 *   @0x1f1084 ble 0x1f10ac <_Z11Sprite_LoadP7CStream+0x384>
 *   @0x1f1088 ldr r12, [sp, #0x8]
 *   @0x1f108c add r2, r2, r2, lsl #1
 *   @0x1f1090 ldr r3, [r12, #0x10]
 *   @0x1f1094 add r2, r3, r2, lsl #2
 *   @0x1f1098 mov lr, #0
 *   @0x1f109c add r3, r3, #12
 *   @0x1f10a0 str lr, [r3, #-0x4]
 *   @0x1f10a4 cmp r3, r2
 *   @0x1f10a8 bne 0x1f1098 <_Z11Sprite_LoadP7CStream+0x370>
 *   @0x1f10ac cmp r6, #0
 *   @0x1f10b0 ble 0x1f10e8 <_Z11Sprite_LoadP7CStream+0x3c0>
 *   @0x1f10b4 ldr r11, [sp, #0x8]
 *   @0x1f10b8 mov r4, r10
 *   @0x1f10bc mov r9, #0
 *   @0x1f10c0 ldr r3, [r4, #0x8]
 *   @0x1f10c4 mov r0, r11
 *   @0x1f10c8 add r9, r9, #1
 *   @0x1f10cc cmp r3, #0
 *   @0x1f10d0 ble 0x1f10dc <_Z11Sprite_LoadP7CStream+0x3b4>
 *   @0x1f10d4 ldm r4, {r1, r2}
 *   @0x1f10d8 bl 0xd261c <_ZN8CHashMapIPKciLi7EE6InsertES1_i>
 *   @0x1f10dc cmp r9, r6
 *   @0x1f10e0 add r4, r4, #12
 *   @0x1f10e4 bne 0x1f10c0 <_Z11Sprite_LoadP7CStream+0x398>
 *   @0x1f10e8 mov r0, r10
 *   @0x1f10ec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f10f0 ldr r6, [sp, #0x8]
 *   @0x1f10f4 ldr r12, [sp, #0x8]
 *   @0x1f10f8 ldr r6, [r6]
 *   @0x1f10fc ldr r3, [r12, #0x4]
 *   @0x1f1100 vmov s14, r6
 *   @0x1f1104 str r6, [sp]
 *   @0x1f1108 vcvt.f32.s32 s15, s14
 *   @0x1f110c vmul.f32 s15, s15, s16
 *   @0x1f1110 vcvt.s32.f32 s15, s15
 *   @0x1f1114 vstr s15, [r12, #12]
 *   @0x1f1118 b 0x1f0ed8 <_Z11Sprite_LoadP7CStream+0x1b0>
 *   @0x1f111c mov r0, #1
 *   @0x1f1120 add sp, sp, #44
 *   @0x1f1124 vpop {d8}
 *   @0x1f1128 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1f112c svclo #0x19999a
 *   @0x1f1130 eoreq r0, r0, r4, lsl pc
 *   @0x1f1134 .word 0xfffff1c0
 *   @0x1f1138 .word 0xfffff1b8
 *   @0x1f113c andseq r1, r6, r8, lsr #17
 *   @0x1f1140 .word 0xfffff1bc
 *   @0x1f1144 andseq r0, r4, r4, lsr r2
 *   @0x1f1148 .word 0xfffff1c4
 *
 * ══ §28/28 CIAPProduct::PopulateMap(int)  0x18b348  size 496  122 条（0x18b348..0x18b538）
 * @func 0x18b348 0x18b538  size 496  122 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYCreateString(RValue*, char const*)×9 / F_DsMapAdd(RValue&, CInstance*, CInstance*, int, RValue*)×6 / YYSetString(RValue*, char const*)×2 / F_DsMapClear(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x4×2 / 0x8×2 / 0xc×2 / 0x10×2 / 0x24×1 / 0x188×1 / 0x14c×1 / 0x110×1
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18b348 vmov s13, r1
 *   @0x18b34c mov r3, #1
 *   @0x18b350 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x18b354 vcvt.f64.s32 d7, s13
 *   @0x18b358 sub sp, sp, #76
 *   @0x18b35c mov r7, #0
 *   @0x18b360 add r5, sp, #8
 *   @0x18b364 mov r2, r7
 *   @0x18b368 mov r4, r0
 *   @0x18b36c mov r1, r7
 *   @0x18b370 mov r0, r5
 *   @0x18b374 add r6, sp, #24
 *   @0x18b378 str r6, [sp]
 *   @0x18b37c add r8, sp, #40
 *   @0x18b380 str r7, [sp, #0x24]
 *   @0x18b384 add r9, sp, #56
 *   @0x18b388 vstr d7, [sp, #24]
 *   @0x18b38c bl 0xfed40 <_Z12F_DsMapClearR6RValueP9CInstanceS2_iPS_>
 *   @0x18b390 ldr r1, [pc, #0x188]
 *   @0x18b394 mov r0, r8
 *   @0x18b398 add r1, pc, r1
 *   @0x18b39c bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x18b3a0 ldr r1, [r4]
 *   @0x18b3a4 mov r0, r9
 *   @0x18b3a8 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x18b3ac mov r3, #3
 *   @0x18b3b0 str r6, [sp]
 *   @0x18b3b4 mov r0, r5
 *   @0x18b3b8 mov r1, r7
 *   @0x18b3bc mov r2, r7
 *   @0x18b3c0 bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_>
 *   @0x18b3c4 ldr r3, [r4, #0x4]
 *   @0x18b3c8 cmp r3, r7
 *   @0x18b3cc beq 0x18b404 <_ZN11CIAPProduct11PopulateMapEi+0xbc>
 *   @0x18b3d0 ldr r1, [pc, #0x14c]
 *   @0x18b3d4 mov r0, r8
 *   @0x18b3d8 add r1, pc, r1
 *   @0x18b3dc bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x18b3e0 mov r0, r9
 *   @0x18b3e4 ldr r1, [r4, #0x4]
 *   @0x18b3e8 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x18b3ec mov r1, r7
 *   @0x18b3f0 str r6, [sp]
 *   @0x18b3f4 mov r2, r7
 *   @0x18b3f8 mov r0, r5
 *   @0x18b3fc mov r3, #3
 *   @0x18b400 bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_>
 *   @0x18b404 ldr r3, [r4, #0x8]
 *   @0x18b408 cmp r3, #0
 *   @0x18b40c beq 0x18b444 <_ZN11CIAPProduct11PopulateMapEi+0xfc>
 *   @0x18b410 ldr r1, [pc, #0x110]
 *   @0x18b414 mov r0, r8
 *   @0x18b418 add r1, pc, r1
 *   @0x18b41c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x18b420 mov r0, r9
 *   @0x18b424 ldr r1, [r4, #0x8]
 *   @0x18b428 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x18b42c mov r1, #0
 *   @0x18b430 str r6, [sp]
 *   @0x18b434 mov r2, r1
 *   @0x18b438 mov r0, r5
 *   @0x18b43c mov r3, #3
 *   @0x18b440 bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_>
 *   @0x18b444 ldr r3, [r4, #0xc]
 *   @0x18b448 cmp r3, #0
 *   @0x18b44c beq 0x18b484 <_ZN11CIAPProduct11PopulateMapEi+0x13c>
 *   @0x18b450 ldr r1, [pc, #0xd4]
 *   @0x18b454 mov r0, r8
 *   @0x18b458 add r1, pc, r1
 *   @0x18b45c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x18b460 mov r0, r9
 *   @0x18b464 ldr r1, [r4, #0xc]
 *   @0x18b468 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x18b46c mov r1, #0
 *   @0x18b470 str r6, [sp]
 *   @0x18b474 mov r2, r1
 *   @0x18b478 mov r0, r5
 *   @0x18b47c mov r3, #3
 *   @0x18b480 bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_>
 *   @0x18b484 ldr r3, [r4, #0x10]
 *   @0x18b488 cmp r3, #0
 *   @0x18b48c beq 0x18b4c4 <_ZN11CIAPProduct11PopulateMapEi+0x17c>
 *   @0x18b490 ldr r1, [pc, #0x98]
 *   @0x18b494 mov r0, r8
 *   @0x18b498 add r1, pc, r1
 *   @0x18b49c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x18b4a0 mov r0, r9
 *   @0x18b4a4 ldr r1, [r4, #0x10]
 *   @0x18b4a8 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x18b4ac mov r1, #0
 *   @0x18b4b0 str r6, [sp]
 *   @0x18b4b4 mov r2, r1
 *   @0x18b4b8 mov r0, r5
 *   @0x18b4bc mov r3, #3
 *   @0x18b4c0 bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_>
 *   @0x18b4c4 ldr r1, [pc, #0x68]
 *   @0x18b4c8 mov r0, r8
 *   @0x18b4cc add r1, pc, r1
 *   @0x18b4d0 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x18b4d4 vmov.f64 d7, #1.000000e+00
 *   @0x18b4d8 ldrb r3, [r4, #0x14]
 *   @0x18b4dc mov r12, #0
 *   @0x18b4e0 str r6, [sp]
 *   @0x18b4e4 mov r1, r12
 *   @0x18b4e8 cmp r3, r12
 *   @0x18b4ec mov r0, r5
 *   @0x18b4f0 mov r2, r12
 *   @0x18b4f4 mov r3, #3
 *   @0x18b4f8 vldr d6, [pc, #24]
 *   @0x18b4fc str r12, [sp, #0x44]
 *   @0x18b500 vmoveq.f64 d7, d6
 *   @0x18b504 vstr d7, [sp, #56]
 *   @0x18b508 bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_>
 *   @0x18b50c add sp, sp, #76
 *   @0x18b510 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x18b514 nop
 *   @0x18b520 andseq r5, r10, r8, lsr #13
 *   @0x18b524 ldrsheq lr, [r11], -r4
 *   @0x18b528 andseq r11, r11, r4, lsr #3
 *   @0x18b52c mulseq r12, r8, sp
 *   @0x18b530 mulseq r11, r0, r12
 *   @0x18b534 andseq r0, r12, r12, lsr #26
 */
