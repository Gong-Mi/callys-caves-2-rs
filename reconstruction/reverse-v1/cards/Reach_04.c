/* cally 逆向卡：Reach_04 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 25 个函数｜锚点 7495 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/25 STRING_RValue  0xcff78  size 1368  342 条（0xcff78..0xd04d0）
 * @func 0xcff78 0xd04d0  size 1368  342 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xcff98→0x47a158, 0xcffa8→0x47a154, 0xcffd4→0x47a150, 0xd00d8→0x47a150, 0xd01dc→0x47a150
 * 调用序列: anon_ce388×11 / 0xb65c8×4 / STRING_RValue(char**, char**, int*, RValue const*)+0x378×2 / STRING_RValue(char**, char**, int*, RValue const*)+0xb4 / STRING_RValue(char**, char**, int*, RValue const*)+0x3cc / YYError(char const*, ...) / JS_GetProperty(YYObjectBase*, RValue*, char const*) / JS_IsCallable(RValue&)
 * 字段偏移 top8: 0xc×5 / 0x10×5 / 0x4×4 / 0x30×3 / 0x40×3 / 0x8×2 / 0x244×2 / 0x34×2
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcff78 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xcff7c vpush {d8}
 *   @0xcff80 mov r6, r0
 *   @0xcff84 ldr r10, [pc, #0x4ec]
 *   @0xcff88 mov r7, r1
 *   @0xcff8c ldr r0, [pc, #0x4e8]
 *   @0xcff90 mov r4, r3
 *   @0xcff94 add r10, pc, r10
 *   @0xcff98 ldr r1, [pc, #0x4e0]
 *   @0xcff9c sub sp, sp, #588
 *   @0xcffa0 mov r8, r2
 *   @0xcffa4 ldr r0, [r10, r0]
 *   @0xcffa8 ldr r2, [pc, #0x4d4]
 *   @0xcffac ldr r3, [r0]
 *   @0xcffb0 str r0, [sp, #0x8]
 *   @0xcffb4 str r3, [sp, #0x244]
 *   @0xcffb8 ldr r5, [r10, r1]
 *   @0xcffbc ldr r12, [r5]
 *   @0xcffc0 add r12, r12, #1
 *   @0xcffc4 str r12, [r5]
 *   @0xcffc8 ldr r9, [r10, r2]
 *   @0xcffcc ldr r2, [r9]
 *   @0xcffd0 cmp r2, #0
 *   @0xcffd4 ldreq r3, [pc, #0x4ac]
 *   @0xcffd8 ldreq r3, [r10, r3]
 *   @0xcffdc streq r12, [r3]
 *   @0xcffe0 ldr r3, [r4, #0xc]
 *   @0xcffe4 add r2, r2, #1
 *   @0xcffe8 str r2, [r9]
 *   @0xcffec bic r3, r3, #-16777216
 *   @0xcfff0 cmp r3, #5
 *   @0xcfff4 beq 0xd03a4 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x42c>
 *   @0xcfff8 ble 0xd002c <_Z13STRING_RValuePPcS0_PiPK6RValue+0xb4>
 *   @0xcfffc cmp r3, #10
 *   @0xd0000 beq 0xd02c4 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x34c>
 *   @0xd0004 bgt 0xd0080 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x108>
 *   @0xd0008 cmp r3, #6
 *   @0xd000c beq 0xd00cc <_Z13STRING_RValuePPcS0_PiPK6RValue+0x154>
 *   @0xd0010 cmp r3, #7
 *   @0xd0014 bne 0xd00a4 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x12c>
 *   @0xd0018 ldr r2, [pc, #0x46c]
 *   @0xd001c mov r1, #256
 *   @0xd0020 ldr r3, [r4]
 *   @0xd0024 add r2, pc, r2
 *   @0xd0028 b 0xd0058 <_Z13STRING_RValuePPcS0_PiPK6RValue+0xe0>
 *   @0xd002c cmp r3, #1
 *   @0xd0030 beq 0xd03f0 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x478>
 *   @0xd0034 ble 0xd0344 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x3cc>
 *   @0xd0038 cmp r3, #2
 *   @0xd003c beq 0xd01b8 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x240>
 *   @0xd0040 cmp r3, #3
 *   @0xd0044 bne 0xd00a4 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x12c>
 *   @0xd0048 ldr r2, [pc, #0x440]
 *   @0xd004c mov r1, #256
 *   @0xd0050 ldr r3, [r4]
 *   @0xd0054 add r2, pc, r2
 *   @0xd0058 add r4, sp, #68
 *   @0xd005c mov r0, r4
 *   @0xd0060 bl 0xb65c8 <snprintf@plt>
 *   @0xd0064 mov r2, r8
 *   @0xd0068 mov r0, r6
 *   @0xd006c mov r1, r7
 *   @0xd0070 mov r3, r4
 *   @0xd0074 bl 0xce388 <_ZN5CCodeD0Ev+0x1c>
 *   @0xd0078 ldr r2, [r9]
 *   @0xd007c b 0xd00a4 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x12c>
 *   @0xd0080 cmp r3, #13
 *   @0xd0084 beq 0xd0184 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x20c>
 *   @0xd0088 mvn r1, #-16777216
 *   @0xd008c cmp r3, r1
 *   @0xd0090 bne 0xd00a4 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x12c>
 *   @0xd0094 ldr r0, [pc, #0x3f8]
 *   @0xd0098 add r0, pc, r0
 *   @0xd009c bl 0xd547c <_Z7YYErrorPKcz>
 *   @0xd00a0 ldr r2, [r9]
 *   @0xd00a4 ldr r0, [sp, #0x8]
 *   @0xd00a8 sub r2, r2, #1
 *   @0xd00ac ldr r1, [sp, #0x244]
 *   @0xd00b0 str r2, [r9]
 *   @0xd00b4 ldr r3, [r0]
 *   @0xd00b8 cmp r1, r3
 *   @0xd00bc bne 0xd0474 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x4fc>
 *   @0xd00c0 add sp, sp, #588
 *   @0xd00c4 vpop {d8}
 *   @0xd00c8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xd00cc ldr r4, [r4]
 *   @0xd00d0 cmp r4, #0
 *   @0xd00d4 beq 0xd0454 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x4dc>
 *   @0xd00d8 ldr r3, [pc, #0x3a8]
 *   @0xd00dc ldr r1, [r4, #0x30]
 *   @0xd00e0 ldr r3, [r10, r3]
 *   @0xd00e4 ldr r3, [r3]
 *   @0xd00e8 cmp r1, r3
 *   @0xd00ec bhs 0xd00a4 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x12c>
 *   @0xd00f0 add r5, sp, #36
 *   @0xd00f4 ldr r2, [pc, #0x39c]
 *   @0xd00f8 str r12, [r4, #0x30]
 *   @0xd00fc mov r0, r4
 *   @0xd0100 add r2, pc, r2
 *   @0xd0104 mov r1, r5
 *   @0xd0108 mov r3, #5
 *   @0xd010c str r3, [sp, #0x30]
 *   @0xd0110 bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc>
 *   @0xd0114 mov r0, r5
 *   @0xd0118 bl 0x24076c <_Z13JS_IsCallableR6RValue>
 *   @0xd011c cmp r0, #0
 *   @0xd0120 beq 0xd00a0 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x128>
 *   @0xd0124 add r10, sp, #52
 *   @0xd0128 mov r12, #0
 *   @0xd012c mov r3, r12
 *   @0xd0130 mov r0, r4
 *   @0xd0134 mov r2, r5
 *   @0xd0138 mov r1, r10
 *   @0xd013c str r12, [sp]
 *   @0xd0140 mvn lr, #-16777216
 *   @0xd0144 str r12, [sp, #0x34]
 *   @0xd0148 str r12, [sp, #0x38]
 *   @0xd014c str r12, [sp, #0x3c]
 *   @0xd0150 str lr, [sp, #0x40]
 *   @0xd0154 bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_>
 *   @0xd0158 ldr r3, [sp, #0x40]
 *   @0xd015c cmp r3, #1
 *   @0xd0160 beq 0xd042c <_Z13STRING_RValuePPcS0_PiPK6RValue+0x4b4>
 *   @0xd0164 sub r3, r3, #1
 *   @0xd0168 bic r3, r3, #-16777216
 *   @0xd016c bic r3, r3, #3
 *   @0xd0170 cmp r3, #0
 *   @0xd0174 bne 0xd00a0 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x128>
 *   @0xd0178 mov r0, r10
 *   @0xd017c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xd0180 b 0xd00a0 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x128>
 *   @0xd0184 ldm r4, {r2, r3}
 *   @0xd0188 vmov d7, r2, r3
 *   @0xd018c vcmp.f64 d7, #0
 *   @0xd0190 vmrs APSR_nzcv, fpscr
 *   @0xd0194 beq 0xd03e4 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x46c>
 *   @0xd0198 ldr r3, [pc, #0x2fc]
 *   @0xd019c add r3, pc, r3
 *   @0xd01a0 mov r2, r8
 *   @0xd01a4 mov r0, r6
 *   @0xd01a8 mov r1, r7
 *   @0xd01ac bl 0xce388 <_ZN5CCodeD0Ev+0x1c>
 *   @0xd01b0 ldr r2, [r9]
 *   @0xd01b4 b 0xd00a4 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x12c>
 *   @0xd01b8 ldr r3, [pc, #0x2e0]
 *   @0xd01bc mov r0, r6
 *   @0xd01c0 mov r1, r7
 *   @0xd01c4 mov r2, r8
 *   @0xd01c8 add r3, pc, r3
 *   @0xd01cc bl 0xce388 <_ZN5CCodeD0Ev+0x1c>
 *   @0xd01d0 ldr r11, [r4]
 *   @0xd01d4 cmp r11, #0
 *   @0xd01d8 beq 0xd0324 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x3ac>
 *   @0xd01dc ldr r3, [pc, #0x2a4]
 *   @0xd01e0 ldr r2, [r11, #0xc]
 *   @0xd01e4 ldr r3, [r10, r3]
 *   @0xd01e8 str r3, [sp, #0xc]
 *   @0xd01ec ldr r3, [r3]
 *   @0xd01f0 cmp r2, r3
 *   @0xd01f4 bhs 0xd0324 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x3ac>
 *   @0xd01f8 ldr r3, [r11, #0x10]
 *   @0xd01fc ldr r2, [r5]
 *   @0xd0200 cmp r3, #0
 *   @0xd0204 str r2, [r11, #0xc]
 *   @0xd0208 ble 0xd0324 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x3ac>
 *   @0xd020c ldr r0, [pc, #0x290]
 *   @0xd0210 mov r12, #0
 *   @0xd0214 ldr r1, [pc, #0x28c]
 *   @0xd0218 ldr r2, [pc, #0x28c]
 *   @0xd021c add r0, pc, r0
 *   @0xd0220 str r9, [sp, #0x1c]
 *   @0xd0224 mov r9, r12
 *   @0xd0228 add r1, pc, r1
 *   @0xd022c add r2, pc, r2
 *   @0xd0230 str r0, [sp, #0x14]
 *   @0xd0234 str r1, [sp, #0x10]
 *   @0xd0238 str r2, [sp, #0x18]
 *   @0xd023c cmp r3, #0
 *   @0xd0240 ble 0xd0258 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x2e0>
 *   @0xd0244 mov r0, r6
 *   @0xd0248 mov r1, r7
 *   @0xd024c mov r2, r8
 *   @0xd0250 ldr r3, [sp, #0x14]
 *   @0xd0254 bl 0xce388 <_ZN5CCodeD0Ev+0x1c>
 *   @0xd0258 ldr r3, [r11, #0x4]
 *   @0xd025c add r10, r3, r9, lsl #3
 *   @0xd0260 ldr r3, [r3, r9, lsl #3]
 *   @0xd0264 cmp r3, #0
 *   @0xd0268 movgt r4, #0
 *   @0xd026c ble 0xd02f0 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x378>
 *   @0xd0270 ldr r3, [r10, #0x4]
 *   @0xd0274 mov r0, r6
 *   @0xd0278 mov r1, r7
 *   @0xd027c mov r2, r8
 *   @0xd0280 add r3, r3, r4, lsl #4
 *   @0xd0284 add r4, r4, #1
 *   @0xd0288 bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue>
 *   @0xd028c ldr r3, [r10]
 *   @0xd0290 cmp r3, r4
 *   @0xd0294 ble 0xd02f0 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x378>
 *   @0xd0298 cmp r4, #0
 *   @0xd029c beq 0xd0270 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x2f8>
 *   @0xd02a0 mov r0, r6
 *   @0xd02a4 ldr r3, [sp, #0x10]
 *   @0xd02a8 mov r1, r7
 *   @0xd02ac mov r2, r8
 *   @0xd02b0 bl 0xce388 <_ZN5CCodeD0Ev+0x1c>
 *   @0xd02b4 ldr r3, [r5]
 *   @0xd02b8 ldr r0, [sp, #0xc]
 *   @0xd02bc str r3, [r0]
 *   @0xd02c0 b 0xd0270 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x2f8>
 *   @0xd02c4 ldr r12, [r4]
 *   @0xd02c8 mov r1, #256
 *   @0xd02cc ldr r3, [r4, #0x4]
 *   @0xd02d0 add r4, sp, #68
 *   @0xd02d4 ldr r2, [pc, #0x1d4]
 *   @0xd02d8 mov r0, r4
 *   @0xd02dc str r12, [sp]
 *   @0xd02e0 add r2, pc, r2
 *   @0xd02e4 str r3, [sp, #0x4]
 *   @0xd02e8 bl 0xb65c8 <snprintf@plt>
 *   @0xd02ec b 0xd0064 <_Z13STRING_RValuePPcS0_PiPK6RValue+0xec>
 *   @0xd02f0 ldr r3, [r11, #0x10]
 *   @0xd02f4 cmp r3, #0
 *   @0xd02f8 ble 0xd0320 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x3a8>
 *   @0xd02fc ldr r3, [sp, #0x18]
 *   @0xd0300 mov r0, r6
 *   @0xd0304 mov r1, r7
 *   @0xd0308 mov r2, r8
 *   @0xd030c bl 0xce388 <_ZN5CCodeD0Ev+0x1c>
 *   @0xd0310 ldr r3, [r11, #0x10]
 *   @0xd0314 add r9, r9, #1
 *   @0xd0318 cmp r9, r3
 *   @0xd031c blt 0xd023c <_Z13STRING_RValuePPcS0_PiPK6RValue+0x2c4>
 *   @0xd0320 ldr r9, [sp, #0x1c]
 *   @0xd0324 ldr r3, [pc, #0x188]
 *   @0xd0328 mov r2, r8
 *   @0xd032c mov r0, r6
 *   @0xd0330 mov r1, r7
 *   @0xd0334 add r3, pc, r3
 *   @0xd0338 bl 0xce388 <_ZN5CCodeD0Ev+0x1c>
 *   @0xd033c ldr r2, [r9]
 *   @0xd0340 b 0xd00a4 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x12c>
 *   @0xd0344 cmp r3, #0
 *   @0xd0348 bne 0xd00a4 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x12c>
 *   @0xd034c vldr s16, [r4]
 *   @0xd0350 vldr s17, [r4, #4]
 *   @0xd0354 vcmp.f64 d8, d8
 *   @0xd0358 vmrs APSR_nzcv, fpscr
 *   @0xd035c bne 0xd040c <_Z13STRING_RValuePPcS0_PiPK6RValue+0x494>
 *   @0xd0360 vmov r0, r1, d8
 *   @0xd0364 bl 0x3194a0 <__fixdfdi>
 *   @0xd0368 mov r4, r0
 *   @0xd036c mov r5, r1
 *   @0xd0370 bl 0x319164 <__floatdidf>
 *   @0xd0374 vmov d7, r0, r1
 *   @0xd0378 vcmp.f64 d8, d7
 *   @0xd037c vmrs APSR_nzcv, fpscr
 *   @0xd0380 bne 0xd03c4 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x44c>
 *   @0xd0384 strd r4, r5, [sp]
 *   @0xd0388 add r4, sp, #68
 *   @0xd038c ldr r2, [pc, #0x124]
 *   @0xd0390 mov r1, #256
 *   @0xd0394 mov r0, r4
 *   @0xd0398 add r2, pc, r2
 *   @0xd039c bl 0xb65c8 <snprintf@plt>
 *   @0xd03a0 b 0xd0064 <_Z13STRING_RValuePPcS0_PiPK6RValue+0xec>
 *   @0xd03a4 ldr r3, [pc, #0x110]
 *   @0xd03a8 mov r2, r8
 *   @0xd03ac mov r0, r6
 *   @0xd03b0 mov r1, r7
 *   @0xd03b4 add r3, pc, r3
 *   @0xd03b8 bl 0xce388 <_ZN5CCodeD0Ev+0x1c>
 *   @0xd03bc ldr r2, [r9]
 *   @0xd03c0 b 0xd00a4 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x12c>
 *   @0xd03c4 add r4, sp, #68
 *   @0xd03c8 ldr r2, [pc, #0xf0]
 *   @0xd03cc vstr d8, [sp]
 *   @0xd03d0 mov r1, #512
 *   @0xd03d4 add r2, pc, r2
 *   @0xd03d8 mov r0, r4
 *   @0xd03dc bl 0xb65c8 <snprintf@plt>
 *   @0xd03e0 b 0xd0064 <_Z13STRING_RValuePPcS0_PiPK6RValue+0xec>
 *   @0xd03e4 ldr r3, [pc, #0xd8]
 *   @0xd03e8 add r3, pc, r3
 *   @0xd03ec b 0xd01a0 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x228>
 *   @0xd03f0 ldr r3, [r4]
 *   @0xd03f4 cmp r3, #0
 *   @0xd03f8 beq 0xd00a4 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x12c>
 *   @0xd03fc ldr r3, [r3]
 *   @0xd0400 cmp r3, #0
 *   @0xd0404 bne 0xd01a0 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x228>
 *   @0xd0408 b 0xd00a4 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x12c>
 *   @0xd040c ldr r3, [pc, #0xb4]
 *   @0xd0410 mov r2, r8
 *   @0xd0414 mov r0, r6
 *   @0xd0418 mov r1, r7
 *   @0xd041c add r3, pc, r3
 *   @0xd0420 bl 0xce388 <_ZN5CCodeD0Ev+0x1c>
 *   @0xd0424 ldr r2, [r9]
 *   @0xd0428 b 0xd00a4 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x12c>
 *   @0xd042c ldr r3, [sp, #0x34]
 *   @0xd0430 ldr r3, [r3]
 *   @0xd0434 cmp r3, #0
 *   @0xd0438 beq 0xd0178 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x200>
 *   @0xd043c mov r0, r6
 *   @0xd0440 mov r1, r7
 *   @0xd0444 mov r2, r8
 *   @0xd0448 bl 0xce388 <_ZN5CCodeD0Ev+0x1c>
 *   @0xd044c ldr r3, [sp, #0x40]
 *   @0xd0450 b 0xd0164 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x1ec>
 *   @0xd0454 ldr r3, [pc, #0x70]
 *   @0xd0458 mov r2, r8
 *   @0xd045c mov r0, r6
 *   @0xd0460 mov r1, r7
 *   @0xd0464 add r3, pc, r3
 *   @0xd0468 bl 0xce388 <_ZN5CCodeD0Ev+0x1c>
 *   @0xd046c ldr r2, [r9]
 *   @0xd0470 b 0xd00a4 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x12c>
 *   @0xd0474 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0xd0478 ldrhteq r1, [r2], -r12
 *   @0xd047c .word 0xffffbd00
 *   @0xd0480 .word 0xffffbf38
 *   @0xd0484 .word 0xffffbf3c
 *   @0xd0488 .word 0xffffbf40
 *   @0xd048c eoreq r2, r6, r8, ror #9
 *   @0xd0490 .word 0x002624b4
 *   @0xd0494 mlaeq r6, r8, r4, r2
 *   @0xd0498 eoreq r2, r6, r0, lsl r4
 *   @0xd049c eoreq r2, r6, r4, asr r3
 *   @0xd04a0 eoreq r2, r6, r4, asr r3
 *   @0xd04a4 eoreq r2, r6, r0, lsl #6
 *   @0xd04a8 .word 0x002622fc
 *   @0xd04ac .word 0x002622fc
 *   @0xd04b0 eoreq r2, r6, r8, lsl r2
 *   @0xd04b4 eoreq r2, r6, r12, ror #3
 *   @0xd04b8 eoreq r2, r6, r0, ror #2
 *   @0xd04bc eoreq r1, r6, r12, lsr #29
 *   @0xd04c0 eoreq r2, r6, r12, lsr #2
 *   @0xd04c4 eoreq r2, r6, r4, lsl #2
 *   @0xd04c8 .word 0x002620d8
 *   @0xd04cc eoreq r1, r6, r0, asr #28
 *
 * ══ §2/25 UpdateTransRoomExtents  0x168d94  size 1360  340 条（0x168d94..0x1692e4）
 * @func 0x168d94 0x1692e4  size 1360  340 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::GetMatrix(eMatrix, float*)
 * 字段偏移 top8: 0x8×2 / 0x530×1 / 0x110×1 / 0x2c×1 / 0xc×1
 * VFP 指令 277 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x168d94 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x168d98 vpush {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x168d9c sub sp, sp, #188
 *   @0x168da0 ldr r4, [pc, #0x530]
 *   @0x168da4 ldr r4, [pc, r4]
 *   @0x168da8 ldrb r3, [r4]
 *   @0x168dac cmp r3, #0
 *   @0x168db0 bne 0x168dc0 <_Z22UpdateTransRoomExtentsv+0x2c>
 *   @0x168db4 add sp, sp, #188
 *   @0x168db8 vpop {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x168dbc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x168dc0 add r5, sp, #56
 *   @0x168dc4 mov r0, #2
 *   @0x168dc8 mov r1, r5
 *   @0x168dcc bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf>
 *   @0x168dd0 vldr s8, [sp, #100]
 *   @0x168dd4 vldr s2, [sp, #72]
 *   @0x168dd8 vmul.f32 s0, s8, s2
 *   @0x168ddc vldr s10, [sp, #76]
 *   @0x168de0 vldr s13, [sp, #112]
 *   @0x168de4 vldr s11, [sp, #96]
 *   @0x168de8 vldr s12, [sp, #116]
 *   @0x168dec vldr s9, [sp, #92]
 *   @0x168df0 vldr s14, [sp, #108]
 *   @0x168df4 vldr s7, [sp, #80]
 *   @0x168df8 vldr s4, [sp, #84]
 *   @0x168dfc vldr s6, [sp, #60]
 *   @0x168e00 vldr s5, [sp, #56]
 *   @0x168e04 vldr s19, [sp, #88]
 *   @0x168e08 vldr s20, [sp, #104]
 *   @0x168e0c vmul.f32 s15, s10, s8
 *   @0x168e10 vneg.f32 s1, s2
 *   @0x168e14 vmul.f32 s3, s13, s0
 *   @0x168e18 vmul.f32 s17, s11, s1
 *   @0x168e1c vmul.f32 s15, s15, s13
 *   @0x168e20 vmul.f32 s16, s10, s11
 *   @0x168e24 vmla.f32 s3, s12, s17
 *   @0x168e28 vldr s17, [sp, #88]
 *   @0x168e2c vnmls.f32 s15, s16, s12
 *   @0x168e30 vmul.f32 s22, s14, s0
 *   @0x168e34 vmul.f32 s0, s9, s2
 *   @0x168e38 vmul.f32 s17, s7, s17
 *   @0x168e3c vmul.f32 s28, s4, s6
 *   @0x168e40 vstr s17, [sp, #12]
 *   @0x168e44 vmul.f32 s18, s9, s7
 *   @0x168e48 vmul.f32 s16, s11, s2
 *   @0x168e4c vnmls.f32 s22, s12, s0
 *   @0x168e50 vmul.f32 s25, s11, s5
 *   @0x168e54 vmla.f32 s3, s12, s17
 *   @0x168e58 vstr s25, [sp, #20]
 *   @0x168e5c vmul.f32 s21, s13, s28
 *   @0x168e60 vmul.f32 s24, s11, s28
 *   @0x168e64 vmul.f32 s28, s7, s6
 *   @0x168e68 vmls.f32 s15, s12, s18
 *   @0x168e6c vstr s28, [sp, #28]
 *   @0x168e70 vmul.f32 s18, s10, s19
 *   @0x168e74 vmul.f32 s1, s9, s1
 *   @0x168e78 vmul.f32 s27, s14, s16
 *   @0x168e7c vmul.f32 s17, s4, s19
 *   @0x168e80 vneg.f32 s25, s5
 *   @0x168e84 vmul.f32 s26, s8, s5
 *   @0x168e88 vmul.f32 s28, s9, s25
 *   @0x168e8c vmul.f32 s23, s7, s20
 *   @0x168e90 vstr s28, [sp, #16]
 *   @0x168e94 vmla.f32 s27, s13, s1
 *   @0x168e98 vstr s23, [sp, #32]
 *   @0x168e9c vldr s16, [sp, #32]
 *   @0x168ea0 vmls.f32 s22, s12, s18
 *   @0x168ea4 vmls.f32 s3, s13, s17
 *   @0x168ea8 vmul.f32 s1, s4, s5
 *   @0x168eac vmul.f32 s23, s7, s5
 *   @0x168eb0 vmul.f32 s0, s9, s4
 *   @0x168eb4 vmul.f32 s30, s13, s26
 *   @0x168eb8 vmul.f32 s28, s14, s26
 *   @0x168ebc vmul.f32 s26, s9, s5
 *   @0x168ec0 vmla.f32 s15, s13, s0
 *   @0x168ec4 vstr s26, [sp, #24]
 *   @0x168ec8 vmla.f32 s27, s13, s18
 *   @0x168ecc vldr s18, [sp, #20]
 *   @0x168ed0 vmul.f32 s26, s10, s5
 *   @0x168ed4 vmul.f32 s31, s14, s18
 *   @0x168ed8 vmla.f32 s22, s14, s17
 *   @0x168edc vmul.f32 s18, s14, s1
 *   @0x168ee0 vmul.f32 s17, s9, s23
 *   @0x168ee4 vmls.f32 s3, s8, s16
 *   @0x168ee8 vmul.f32 s29, s8, s6
 *   @0x168eec vmul.f32 s19, s7, s14
 *   @0x168ef0 vnmls.f32 s18, s12, s26
 *   @0x168ef4 vnmls.f32 s17, s11, s26
 *   @0x168ef8 vmul.f32 s26, s4, s20
 *   @0x168efc vneg.f32 s0, s6
 *   @0x168f00 vmla.f32 s15, s8, s19
 *   @0x168f04 vmul.f32 s16, s11, s0
 *   @0x168f08 vmul.f32 s19, s7, s25
 *   @0x168f0c vmul.f32 s0, s7, s0
 *   @0x168f10 vstr s19, [sp, #36]
 *   @0x168f14 vmul.f32 s29, s13, s29
 *   @0x168f18 vmul.f32 s25, s10, s25
 *   @0x168f1c vmla.f32 s3, s11, s26
 *   @0x168f20 vstr s25, [sp, #4]
 *   @0x168f24 vldr s25, [sp, #28]
 *   @0x168f28 vmul.f32 s19, s13, s1
 *   @0x168f2c vmla.f32 s29, s12, s16
 *   @0x168f30 vmla.f32 s24, s8, s0
 *   @0x168f34 vnmls.f32 s21, s12, s25
 *   @0x168f38 vldr s25, [sp, #16]
 *   @0x168f3c vmul.f32 s16, s14, s23
 *   @0x168f40 vmla.f32 s28, s12, s25
 *   @0x168f44 vldr s25, [sp, #20]
 *   @0x168f48 vstr s26, [sp, #20]
 *   @0x168f4c vmul.f32 s0, s9, s1
 *   @0x168f50 vmul.f32 s26, s10, s20
 *   @0x168f54 vmul.f32 s1, s11, s1
 *   @0x168f58 vstr s26, [sp, #16]
 *   @0x168f5c vnmls.f32 s30, s12, s25
 *   @0x168f60 vldr s25, [sp, #24]
 *   @0x168f64 vnmls.f32 s1, s8, s23
 *   @0x168f68 vnmls.f32 s31, s13, s25
 *   @0x168f6c vldr s25, [sp, #36]
 *   @0x168f70 vmul.f32 s23, s4, s14
 *   @0x168f74 vmla.f32 s19, s12, s25
 *   @0x168f78 vldr s25, [sp, #4]
 *   @0x168f7c vstr s3, [sp, #136]
 *   @0x168f80 vldr s26, [sp, #64]
 *   @0x168f84 vmla.f32 s16, s13, s25
 *   @0x168f88 vmla.f32 s0, s8, s25
 *   @0x168f8c vldr s25, [sp, #64]
 *   @0x168f90 vmul.f32 s25, s9, s25
 *   @0x168f94 vmls.f32 s15, s11, s23
 *   @0x168f98 vstr s25, [sp, #24]
 *   @0x168f9c vldr s23, [sp, #88]
 *   @0x168fa0 vldr s25, [sp, #64]
 *   @0x168fa4 vmul.f32 s23, s23, s25
 *   @0x168fa8 vstr s15, [sp, #120]
 *   @0x168fac vmul.f32 s26, s10, s26
 *   @0x168fb0 vstr s23, [sp, #8]
 *   @0x168fb4 vldr s23, [sp, #88]
 *   @0x168fb8 vmul.f32 s23, s23, s6
 *   @0x168fbc vstr s26, [sp, #28]
 *   @0x168fc0 vldr s26, [sp, #12]
 *   @0x168fc4 vmul.f32 s25, s2, s25
 *   @0x168fc8 vstr s23, [sp, #12]
 *   @0x168fcc vldr s23, [sp, #16]
 *   @0x168fd0 vmls.f32 s27, s14, s26
 *   @0x168fd4 vmul.f32 s26, s2, s6
 *   @0x168fd8 vmla.f32 s22, s8, s23
 *   @0x168fdc vldr s23, [sp, #24]
 *   @0x168fe0 vmla.f32 s29, s12, s23
 *   @0x168fe4 vldr s23, [sp, #28]
 *   @0x168fe8 vmla.f32 s24, s8, s23
 *   @0x168fec vmls.f32 s21, s12, s23
 *   @0x168ff0 vldr s23, [sp, #8]
 *   @0x168ff4 vmla.f32 s19, s12, s25
 *   @0x168ff8 vmls.f32 s30, s12, s23
 *   @0x168ffc vldr s23, [sp, #12]
 *   @0x169000 vmls.f32 s18, s12, s26
 *   @0x169004 vmla.f32 s28, s12, s23
 *   @0x169008 vldr s12, [sp, #68]
 *   @0x16900c vmla.f32 s16, s13, s26
 *   @0x169010 vmla.f32 s0, s8, s26
 *   @0x169014 vmls.f32 s17, s11, s26
 *   @0x169018 vldr s26, [sp, #88]
 *   @0x16901c vmul.f32 s26, s26, s12
 *   @0x169020 vmul.f32 s3, s3, s6
 *   @0x169024 vstr s26, [sp, #4]
 *   @0x169028 vldr s26, [sp, #68]
 *   @0x16902c vmul.f32 s12, s10, s12
 *   @0x169030 vmul.f32 s26, s9, s26
 *   @0x169034 vmls.f32 s31, s13, s23
 *   @0x169038 vldr s23, [sp, #16]
 *   @0x16903c vstr s26, [sp, #16]
 *   @0x169040 vmls.f32 s1, s8, s25
 *   @0x169044 vmls.f32 s27, s11, s23
 *   @0x169048 vldr s23, [sp, #20]
 *   @0x16904c vmls.f32 s24, s11, s12
 *   @0x169050 vmls.f32 s22, s9, s23
 *   @0x169054 vldr s23, [sp, #68]
 *   @0x169058 vmla.f32 s3, s15, s5
 *   @0x16905c vstr s22, [sp, #152]
 *   @0x169060 vmul.f32 s26, s2, s23
 *   @0x169064 vldr s23, [sp, #4]
 *   @0x169068 vmla.f32 s21, s13, s12
 *   @0x16906c vldr s12, [sp, #16]
 *   @0x169070 vmla.f32 s30, s13, s23
 *   @0x169074 vmls.f32 s29, s13, s12
 *   @0x169078 vldr s12, [sp, #8]
 *   @0x16907c vmls.f32 s19, s13, s26
 *   @0x169080 vldr s13, [sp, #64]
 *   @0x169084 vmls.f32 s28, s14, s23
 *   @0x169088 vldr s23, [sp, #32]
 *   @0x16908c vmla.f32 s31, s14, s12
 *   @0x169090 vmla.f32 s18, s14, s26
 *   @0x169094 vmla.f32 s17, s9, s25
 *   @0x169098 vmls.f32 s16, s14, s25
 *   @0x16909c vmls.f32 s0, s9, s26
 *   @0x1690a0 vmla.f32 s1, s11, s26
 *   @0x1690a4 vldr s26, [sp, #64]
 *   @0x1690a8 vmla.f32 s3, s22, s26
 *   @0x1690ac vldr s22, [sp, #24]
 *   @0x1690b0 vldr s26, [sp, #68]
 *   @0x1690b4 vmls.f32 s24, s4, s22
 *   @0x1690b8 vmul.f32 s12, s20, s6
 *   @0x1690bc vmul.f32 s25, s14, s13
 *   @0x1690c0 vmul.f32 s13, s20, s13
 *   @0x1690c4 vmla.f32 s27, s9, s23
 *   @0x1690c8 vldr s23, [sp, #12]
 *   @0x1690cc vmls.f32 s29, s8, s25
 *   @0x1690d0 vstr s27, [sp, #168]
 *   @0x1690d4 vmla.f32 s21, s4, s25
 *   @0x1690d8 vldr s25, [sp, #8]
 *   @0x1690dc vmls.f32 s28, s8, s12
 *   @0x1690e0 vmla.f32 s18, s4, s12
 *   @0x1690e4 vmla.f32 s30, s8, s13
 *   @0x1690e8 vmls.f32 s19, s4, s13
 *   @0x1690ec vmla.f32 s31, s11, s12
 *   @0x1690f0 vmls.f32 s16, s7, s12
 *   @0x1690f4 vmls.f32 s0, s4, s23
 *   @0x1690f8 vmla.f32 s1, s4, s25
 *   @0x1690fc vldr s4, [sp, #16]
 *   @0x169100 vmla.f32 s17, s7, s23
 *   @0x169104 vmla.f32 s24, s7, s4
 *   @0x169108 vmul.f32 s12, s20, s26
 *   @0x16910c vstr s24, [sp, #132]
 *   @0x169110 vmul.f32 s8, s14, s26
 *   @0x169114 vmla.f32 s3, s27, s26
 *   @0x169118 vmla.f32 s29, s11, s8
 *   @0x16911c vmls.f32 s21, s7, s8
 *   @0x169120 vldr s8, [sp, #4]
 *   @0x169124 vstr s29, [sp, #124]
 *   @0x169128 vmls.f32 s30, s11, s12
 *   @0x16912c vstr s21, [sp, #128]
 *   @0x169130 vmla.f32 s19, s7, s12
 *   @0x169134 vstr s30, [sp, #140]
 *   @0x169138 vmla.f32 s28, s9, s12
 *   @0x16913c vstr s19, [sp, #144]
 *   @0x169140 vmls.f32 s31, s9, s13
 *   @0x169144 vstr s28, [sp, #156]
 *   @0x169148 vmls.f32 s18, s10, s12
 *   @0x16914c vstr s31, [sp, #172]
 *   @0x169150 vmls.f32 s17, s10, s25
 *   @0x169154 vstr s18, [sp, #160]
 *   @0x169158 vmla.f32 s16, s10, s13
 *   @0x16915c vstr s17, [sp, #180]
 *   @0x169160 vmla.f32 s0, s10, s8
 *   @0x169164 vstr s16, [sp, #176]
 *   @0x169168 vmls.f32 s1, s7, s8
 *   @0x16916c vstr s0, [sp, #164]
 *   @0x169170 vcmp.f32 s3, #0
 *   @0x169174 vstr s1, [sp, #148]
 *   @0x169178 vmrs APSR_nzcv, fpscr
 *   @0x16917c beq 0x1691c4 <_Z22UpdateTransRoomExtentsv+0x430>
 *   @0x169180 vmov.f32 s14, #1.000000e+00
 *   @0x169184 add r3, sp, #124
 *   @0x169188 add r2, sp, #120
 *   @0x16918c mov r1, r5
 *   @0x169190 vdiv.f32 s3, s14, s3
 *   @0x169194 b 0x16919c <_Z22UpdateTransRoomExtentsv+0x408>
 *   @0x169198 vldmia r3!, {s15}
 *   @0x16919c vmul.f32 s15, s3, s15
 *   @0x1691a0 vstmia r1!, {s15}
 *   @0x1691a4 cmp r1, r2
 *   @0x1691a8 bne 0x169198 <_Z22UpdateTransRoomExtentsv+0x404>
 *   @0x1691ac vldr s5, [sp, #56]
 *   @0x1691b0 vldr s2, [sp, #72]
 *   @0x1691b4 vldr s20, [sp, #104]
 *   @0x1691b8 vldr s6, [sp, #60]
 *   @0x1691bc vldr s10, [sp, #76]
 *   @0x1691c0 vldr s14, [sp, #108]
 *   @0x1691c4 ldr r0, [pc, #0x110]
 *   @0x1691c8 add r12, sp, #120
 *   @0x1691cc mov r1, #-2147483648
 *   @0x1691d0 mvn r2, #-2147483648
 *   @0x1691d4 ldr r0, [pc, r0]
 *   @0x1691d8 vldr s12, [r0]
 *   @0x1691dc vldr s11, [r0, #8]
 *   @0x1691e0 vcvt.f32.s32 s12, s12
 *   @0x1691e4 vldr s15, [r0, #4]
 *   @0x1691e8 vldr s13, [r0, #12]
 *   @0x1691ec add r11, sp, #40
 *   @0x1691f0 str r4, [sp, #0x8]
 *   @0x1691f4 mov r8, r1
 *   @0x1691f8 mov r7, r2
 *   @0x1691fc mov r3, #0
 *   @0x169200 mov r4, r12
 *   @0x169204 vcvt.f32.s32 s11, s11
 *   @0x169208 vstr s12, [sp, #40]
 *   @0x16920c vstr s12, [sp, #52]
 *   @0x169210 vcvt.f32.s32 s15, s15
 *   @0x169214 vstr s11, [sp, #44]
 *   @0x169218 vstr s11, [sp, #48]
 *   @0x16921c vcvt.f32.s32 s13, s13
 *   @0x169220 vstr s15, [sp, #120]
 *   @0x169224 vstr s15, [sp, #124]
 *   @0x169228 vstr s13, [sp, #128]
 *   @0x16922c vstr s13, [sp, #132]
 *   @0x169230 vmul.f32 s13, s2, s15
 *   @0x169234 add r3, r3, #4
 *   @0x169238 add r10, r11, r3
 *   @0x16923c add r9, r4, r3
 *   @0x169240 vmul.f32 s15, s10, s15
 *   @0x169244 vmla.f32 s13, s5, s12
 *   @0x169248 vmla.f32 s15, s6, s12
 *   @0x16924c vadd.f32 s13, s13, s20
 *   @0x169250 vadd.f32 s15, s15, s14
 *   @0x169254 vcvt.s32.f32 s13, s13
 *   @0x169258 vcvt.s32.f32 s15, s15
 *   @0x16925c vmov r12, s13
 *   @0x169260 vmov r0, s15
 *   @0x169264 cmp r7, r12
 *   @0x169268 movlt r6, r7
 *   @0x16926c movge r6, r12
 *   @0x169270 cmp r12, r8
 *   @0x169274 movlt r12, r8
 *   @0x169278 mov r7, r6
 *   @0x16927c mov r8, r12
 *   @0x169280 cmp r2, r0
 *   @0x169284 movlt r5, r2
 *   @0x169288 movge r5, r0
 *   @0x16928c cmp r0, r1
 *   @0x169290 movlt r0, r1
 *   @0x169294 cmp r3, #16
 *   @0x169298 mov r2, r5
 *   @0x16929c mov r1, r0
 *   @0x1692a0 vldrne s12, [r10]
 *   @0x1692a4 vldrne s15, [r9]
 *   @0x1692a8 bne 0x169230 <_Z22UpdateTransRoomExtentsv+0x49c>
 *   @0x1692ac ldr r3, [pc, #0x2c]
 *   @0x1692b0 mov r2, #0
 *   @0x1692b4 ldr r4, [sp, #0x8]
 *   @0x1692b8 ldr r3, [pc, r3]
 *   @0x1692bc strb r2, [r4]
 *   @0x1692c0 str r6, [r3]
 *   @0x1692c4 stmib r3, {r5, r12}
 *   @0x1692c8 str r0, [r3, #0xc]
 *   @0x1692cc add sp, sp, #188
 *   @0x1692d0 vpop {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x1692d4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1692d8 eoreq r6, r8, r12, lsl #17
 *   @0x1692dc eoreq r6, r8, r8, ror pc
 *   @0x1692e0 mlaeq r8, r8, lr, r6
 *
 * ══ §3/25 spSkeleton_updateCache  0x2895fc  size 1348  337 条（0x2895fc..0x289b40）
 * @func 0x2895fc 0x289b40  size 1348  337 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_289294+0xc4×6 / anon_289294+0x58×4 / anon_289294+0x1e0×3 / anon_289294×3 / _free×2 / _malloc×2 / spSkeleton_updateCache+0x194×2 / spSkeleton_updateCache+0x3f8×2
 * 字段偏移 top8: 0x4×28 / 0x8×10 / 0x54×10 / 0xc×8 / 0x18×6 / 0x2×5 / 0x1c×4 / 0x28×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2895fc ldr r3, [r0, #0x1c]
 *   @0x289600 ldr r1, [r0, #0x4]
 *   @0x289604 ldr r2, [r0, #0x28]
 *   @0x289608 add r1, r1, r3
 *   @0x28960c ldr r3, [r0, #0x30]
 *   @0x289610 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x289614 add r2, r1, r2
 *   @0x289618 mov r4, r0
 *   @0x28961c add r3, r2, r3
 *   @0x289620 ldr r0, [r0, #0x68]
 *   @0x289624 sub sp, sp, #20
 *   @0x289628 str r3, [r4, #0x64]
 *   @0x28962c bl 0x285c80 <_free>
 *   @0x289630 ldr r0, [r4, #0x64]
 *   @0x289634 ldr r1, [pc, #0x4fc]
 *   @0x289638 mov r2, #225
 *   @0x28963c add r1, pc, r1
 *   @0x289640 lsl r0, r0, #3
 *   @0x289644 bl 0x285c10 <_malloc>
 *   @0x289648 ldr r2, [r4, #0x4]
 *   @0x28964c mov r1, #0
 *   @0x289650 ldr r3, [r4, #0x8]
 *   @0x289654 cmp r2, r1
 *   @0x289658 str r1, [r4, #0x60]
 *   @0x28965c str r0, [r4, #0x68]
 *   @0x289660 addgt r0, r3, r2, lsl #2
 *   @0x289664 ble 0x289678 <spSkeleton_updateCache+0x7c>
 *   @0x289668 ldr r2, [r3], #4
 *   @0x28966c cmp r3, r0
 *   @0x289670 str r1, [r2, #0x54]
 *   @0x289674 bne 0x289668 <spSkeleton_updateCache+0x6c>
 *   @0x289678 ldr r0, [r4, #0x24]
 *   @0x28967c cmp r0, #0
 *   @0x289680 beq 0x289688 <spSkeleton_updateCache+0x8c>
 *   @0x289684 bl 0x285c80 <_free>
 *   @0x289688 ldr r0, [r4, #0x1c]
 *   @0x28968c mov r2, #234
 *   @0x289690 ldr r1, [pc, #0x4a4]
 *   @0x289694 lsl r0, r0, #2
 *   @0x289698 add r1, pc, r1
 *   @0x28969c bl 0x285c10 <_malloc>
 *   @0x2896a0 ldr r9, [r4, #0x1c]
 *   @0x2896a4 cmp r9, #0
 *   @0x2896a8 str r0, [r4, #0x24]
 *   @0x2896ac ble 0x289790 <spSkeleton_updateCache+0x194>
 *   @0x2896b0 lsl r1, r9, #2
 *   @0x2896b4 mov r3, #0
 *   @0x2896b8 ldr r2, [r4, #0x20]
 *   @0x2896bc ldr r2, [r2, r3]
 *   @0x2896c0 str r2, [r0, r3]
 *   @0x2896c4 add r3, r3, #4
 *   @0x2896c8 cmp r3, r1
 *   @0x2896cc bne 0x2896b8 <spSkeleton_updateCache+0xbc>
 *   @0x2896d0 add lr, r3, r0
 *   @0x2896d4 mov r1, r0
 *   @0x2896d8 ldr r12, [r1], #4
 *   @0x2896dc ldr r3, [r12, #0x8]
 *   @0x2896e0 ldr r3, [r3]
 *   @0x2896e4 ldr r3, [r3, #0x8]
 *   @0x2896e8 cmp r3, #0
 *   @0x2896ec beq 0x289b1c <spSkeleton_updateCache+0x520>
 *   @0x2896f0 mov r2, #0
 *   @0x2896f4 ldr r3, [r3, #0x8]
 *   @0x2896f8 add r2, r2, #1
 *   @0x2896fc cmp r3, #0
 *   @0x289700 bne 0x2896f4 <spSkeleton_updateCache+0xf8>
 *   @0x289704 cmp r1, lr
 *   @0x289708 str r2, [r12, #0x18]
 *   @0x28970c bne 0x2896d8 <spSkeleton_updateCache+0xdc>
 *   @0x289710 cmp r9, #1
 *   @0x289714 ble 0x289a8c <spSkeleton_updateCache+0x490>
 *   @0x289718 sub r9, r9, #1
 *   @0x28971c mov r12, r0
 *   @0x289720 mov r6, #0
 *   @0x289724 mov r7, r12
 *   @0x289728 ldr r8, [r12, #0x4]
 *   @0x28972c ldr r2, [r7], #4
 *   @0x289730 mov r3, r6
 *   @0x289734 mov r1, r6
 *   @0x289738 ldr r5, [r8, #0x18]
 *   @0x28973c ldr lr, [r2, #0x18]
 *   @0x289740 cmp r5, lr
 *   @0x289744 ble 0x28975c <spSkeleton_updateCache+0x160>
 *   @0x289748 b 0x289b30 <spSkeleton_updateCache+0x534>
 *   @0x28974c ldr r2, [r12, #-0x4]!
 *   @0x289750 ldr lr, [r2, #0x18]
 *   @0x289754 cmp r5, lr
 *   @0x289758 bgt 0x289774 <spSkeleton_updateCache+0x178>
 *   @0x28975c sub r3, r3, #1
 *   @0x289760 add r1, r1, #1
 *   @0x289764 cmn r3, #1
 *   @0x289768 str r2, [r0, r1, lsl #2]
 *   @0x28976c mov r1, r3
 *   @0x289770 bne 0x28974c <spSkeleton_updateCache+0x150>
 *   @0x289774 add r6, r6, #1
 *   @0x289778 add r3, r3, #1
 *   @0x28977c cmp r6, r9
 *   @0x289780 str r8, [r0, r3, lsl #2]
 *   @0x289784 beq 0x289a8c <spSkeleton_updateCache+0x490>
 *   @0x289788 mov r12, r7
 *   @0x28978c b 0x289724 <spSkeleton_updateCache+0x128>
 *   @0x289790 ldr r2, [r4, #0x30]
 *   @0x289794 ldr r3, [r4, #0x34]
 *   @0x289798 cmp r2, #0
 *   @0x28979c str r2, [sp, #0xc]
 *   @0x2897a0 ble 0x289910 <spSkeleton_updateCache+0x314>
 *   @0x2897a4 mov r8, #1
 *   @0x2897a8 sub r3, r3, #4
 *   @0x2897ac mov r2, #0
 *   @0x2897b0 str r3, [sp, #0x8]
 *   @0x2897b4 str r2, [sp, #0x4]
 *   @0x2897b8 ldr r3, [sp, #0x8]
 *   @0x2897bc ldr r1, [r4, #0x38]
 *   @0x2897c0 ldr r9, [r3, #0x4]!
 *   @0x2897c4 cmp r1, #0
 *   @0x2897c8 ldr r10, [r9, #0xc]
 *   @0x2897cc str r3, [sp, #0x8]
 *   @0x2897d0 ldm r10, {r3, r5}
 *   @0x2897d4 ldr r6, [r3]
 *   @0x2897d8 beq 0x2897ec <spSkeleton_updateCache+0x1f0>
 *   @0x2897dc mov r0, r4
 *   @0x2897e0 mov r2, r6
 *   @0x2897e4 mov r3, r5
 *   @0x2897e8 bl 0x289474 <spRegionAttachment_computeWorldVertices+0x300>
 *   @0x2897ec ldr r3, [r4]
 *   @0x2897f0 ldr r1, [r3, #0x28]
 *   @0x2897f4 cmp r1, #0
 *   @0x2897f8 beq 0x28981c <spSkeleton_updateCache+0x220>
 *   @0x2897fc ldr r2, [r4, #0x38]
 *   @0x289800 cmp r1, r2
 *   @0x289804 beq 0x28981c <spSkeleton_updateCache+0x220>
 *   @0x289808 mov r3, r5
 *   @0x28980c mov r0, r4
 *   @0x289810 mov r2, r6
 *   @0x289814 bl 0x289474 <spRegionAttachment_computeWorldVertices+0x300>
 *   @0x289818 ldr r3, [r4]
 *   @0x28981c ldr r7, [r3, #0x20]
 *   @0x289820 cmp r7, #0
 *   @0x289824 movgt r11, #0
 *   @0x289828 bgt 0x289834 <spSkeleton_updateCache+0x238>
 *   @0x28982c b 0x289858 <spSkeleton_updateCache+0x25c>
 *   @0x289830 ldr r3, [r4]
 *   @0x289834 ldr r1, [r3, #0x24]
 *   @0x289838 mov r0, r4
 *   @0x28983c mov r2, r6
 *   @0x289840 mov r3, r5
 *   @0x289844 ldr r1, [r1, r11, lsl #2]
 *   @0x289848 add r11, r11, #1
 *   @0x28984c bl 0x289474 <spRegionAttachment_computeWorldVertices+0x300>
 *   @0x289850 cmp r11, r7
 *   @0x289854 bne 0x289830 <spSkeleton_updateCache+0x234>
 *   @0x289858 ldr r1, [r10, #0x18]
 *   @0x28985c ldr r3, [r1, #0x4]
 *   @0x289860 cmp r3, #4
 *   @0x289864 beq 0x289a60 <spSkeleton_updateCache+0x464>
 *   @0x289868 ldmib r9, {r5, r6}
 *   @0x28986c cmp r5, #0
 *   @0x289870 ble 0x289a78 <spSkeleton_updateCache+0x47c>
 *   @0x289874 sub r11, r6, #4
 *   @0x289878 mov r10, #0
 *   @0x28987c mov r7, r11
 *   @0x289880 b 0x28988c <spSkeleton_updateCache+0x290>
 *   @0x289884 cmp r10, r5
 *   @0x289888 beq 0x2898b0 <spSkeleton_updateCache+0x2b4>
 *   @0x28988c ldr r1, [r7, #0x4]!
 *   @0x289890 add r10, r10, #1
 *   @0x289894 ldr r3, [r1, #0x54]
 *   @0x289898 cmp r3, #0
 *   @0x28989c bne 0x289884 <spSkeleton_updateCache+0x288>
 *   @0x2898a0 mov r0, r4
 *   @0x2898a4 bl 0x289358 <spRegionAttachment_computeWorldVertices+0x1e4>
 *   @0x2898a8 cmp r10, r5
 *   @0x2898ac bne 0x28988c <spSkeleton_updateCache+0x290>
 *   @0x2898b0 mov r2, r9
 *   @0x2898b4 mov r0, r4
 *   @0x2898b8 mov r1, #2
 *   @0x2898bc mov r7, r11
 *   @0x2898c0 bl 0x2892ec <spRegionAttachment_computeWorldVertices+0x178>
 *   @0x2898c4 mov r9, #0
 *   @0x2898c8 ldr r3, [r7, #0x4]!
 *   @0x2898cc add r9, r9, #1
 *   @0x2898d0 ldr r0, [r3, #0x10]
 *   @0x2898d4 ldr r1, [r3, #0xc]
 *   @0x2898d8 bl 0x289294 <spRegionAttachment_computeWorldVertices+0x120>
 *   @0x2898dc cmp r9, r5
 *   @0x2898e0 bne 0x2898c8 <spSkeleton_updateCache+0x2cc>
 *   @0x2898e4 add r9, r6, r9, lsl #2
 *   @0x2898e8 ldr r3, [r6], #4
 *   @0x2898ec cmp r6, r9
 *   @0x2898f0 str r8, [r3, #0x54]
 *   @0x2898f4 bne 0x2898e8 <spSkeleton_updateCache+0x2ec>
 *   @0x2898f8 ldr r2, [sp, #0x4]
 *   @0x2898fc ldr r3, [sp, #0xc]
 *   @0x289900 add r2, r2, #1
 *   @0x289904 str r2, [sp, #0x4]
 *   @0x289908 cmp r2, r3
 *   @0x28990c bne 0x2897b8 <spSkeleton_updateCache+0x1bc>
 *   @0x289910 ldr r3, [r4, #0x28]
 *   @0x289914 ldr r9, [r4, #0x2c]
 *   @0x289918 cmp r3, #0
 *   @0x28991c str r3, [sp, #0x4]
 *   @0x289920 subgt r9, r9, #4
 *   @0x289924 movgt r8, #0
 *   @0x289928 movgt r7, #1
 *   @0x28992c ble 0x289a04 <spSkeleton_updateCache+0x408>
 *   @0x289930 ldr r6, [r9, #0x4]!
 *   @0x289934 ldr r1, [r6, #0xc]
 *   @0x289938 ldr r11, [r6, #0x8]
 *   @0x28993c ldr r3, [r1, #0x54]
 *   @0x289940 cmp r3, #0
 *   @0x289944 beq 0x289a54 <spSkeleton_updateCache+0x458>
 *   @0x289948 ldr r0, [r6, #0x4]
 *   @0x28994c cmp r0, #0
 *   @0x289950 subgt r10, r11, #4
 *   @0x289954 movgt r5, #0
 *   @0x289958 bgt 0x289968 <spSkeleton_updateCache+0x36c>
 *   @0x28995c b 0x289990 <spSkeleton_updateCache+0x394>
 *   @0x289960 cmp r0, r5
 *   @0x289964 ble 0x289990 <spSkeleton_updateCache+0x394>
 *   @0x289968 ldr r1, [r10, #0x4]!
 *   @0x28996c add r5, r5, #1
 *   @0x289970 ldr r2, [r1, #0x54]
 *   @0x289974 cmp r2, #0
 *   @0x289978 bne 0x289960 <spSkeleton_updateCache+0x364>
 *   @0x28997c mov r0, r4
 *   @0x289980 bl 0x289358 <spRegionAttachment_computeWorldVertices+0x1e4>
 *   @0x289984 ldr r0, [r6, #0x4]
 *   @0x289988 cmp r0, r5
 *   @0x28998c bgt 0x289968 <spSkeleton_updateCache+0x36c>
 *   @0x289990 mov r0, r4
 *   @0x289994 mov r1, #3
 *   @0x289998 mov r2, r6
 *   @0x28999c bl 0x2892ec <spRegionAttachment_computeWorldVertices+0x178>
 *   @0x2899a0 ldr r3, [r6, #0x4]
 *   @0x2899a4 cmp r3, #0
 *   @0x2899a8 subgt r10, r11, #4
 *   @0x2899ac movgt r5, #0
 *   @0x2899b0 ble 0x2899f4 <spSkeleton_updateCache+0x3f8>
 *   @0x2899b4 ldr r3, [r10, #0x4]!
 *   @0x2899b8 add r5, r5, #1
 *   @0x2899bc ldr r0, [r3, #0x10]
 *   @0x2899c0 ldr r1, [r3, #0xc]
 *   @0x2899c4 bl 0x289294 <spRegionAttachment_computeWorldVertices+0x120>
 *   @0x2899c8 ldr r2, [r6, #0x4]
 *   @0x2899cc cmp r2, r5
 *   @0x2899d0 bgt 0x2899b4 <spSkeleton_updateCache+0x3b8>
 *   @0x2899d4 cmp r2, #0
 *   @0x2899d8 ble 0x2899f4 <spSkeleton_updateCache+0x3f8>
 *   @0x2899dc add r2, r11, r2, lsl #2
 *   @0x2899e0 mov r3, r11
 *   @0x2899e4 ldr r1, [r3], #4
 *   @0x2899e8 cmp r3, r2
 *   @0x2899ec str r7, [r1, #0x54]
 *   @0x2899f0 bne 0x2899e4 <spSkeleton_updateCache+0x3e8>
 *   @0x2899f4 ldr r3, [sp, #0x4]
 *   @0x2899f8 add r8, r8, #1
 *   @0x2899fc cmp r8, r3
 *   @0x289a00 bne 0x289930 <spSkeleton_updateCache+0x334>
 *   @0x289a04 ldr r2, [r4, #0x4]
 *   @0x289a08 cmp r2, #0
 *   @0x289a0c movgt r5, #0
 *   @0x289a10 bgt 0x289a20 <spSkeleton_updateCache+0x424>
 *   @0x289a14 b 0x289a4c <spSkeleton_updateCache+0x450>
 *   @0x289a18 cmp r2, r5
 *   @0x289a1c ble 0x289a4c <spSkeleton_updateCache+0x450>
 *   @0x289a20 ldr r3, [r4, #0x8]
 *   @0x289a24 ldr r1, [r3, r5, lsl #2]
 *   @0x289a28 add r5, r5, #1
 *   @0x289a2c ldr r3, [r1, #0x54]
 *   @0x289a30 cmp r3, #0
 *   @0x289a34 bne 0x289a18 <spSkeleton_updateCache+0x41c>
 *   @0x289a38 mov r0, r4
 *   @0x289a3c bl 0x289358 <spRegionAttachment_computeWorldVertices+0x1e4>
 *   @0x289a40 ldr r2, [r4, #0x4]
 *   @0x289a44 cmp r2, r5
 *   @0x289a48 bgt 0x289a20 <spSkeleton_updateCache+0x424>
 *   @0x289a4c add sp, sp, #20
 *   @0x289a50 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x289a54 mov r0, r4
 *   @0x289a58 bl 0x289358 <spRegionAttachment_computeWorldVertices+0x1e4>
 *   @0x289a5c b 0x289948 <spSkeleton_updateCache+0x34c>
 *   @0x289a60 mov r2, r5
 *   @0x289a64 mov r0, r4
 *   @0x289a68 bl 0x28939c <spRegionAttachment_computeWorldVertices+0x228>
 *   @0x289a6c ldmib r9, {r5, r6}
 *   @0x289a70 cmp r5, #0
 *   @0x289a74 bgt 0x289874 <spSkeleton_updateCache+0x278>
 *   @0x289a78 mov r2, r9
 *   @0x289a7c mov r0, r4
 *   @0x289a80 mov r1, #2
 *   @0x289a84 bl 0x2892ec <spRegionAttachment_computeWorldVertices+0x178>
 *   @0x289a88 b 0x2898f8 <spSkeleton_updateCache+0x2fc>
 *   @0x289a8c sub r9, r0, #4
 *   @0x289a90 mov r7, #0
 *   @0x289a94 mov r10, #1
 *   @0x289a98 b 0x289ae8 <spSkeleton_updateCache+0x4ec>
 *   @0x289a9c ldr r8, [r5, #0x8]
 *   @0x289aa0 ldr r6, [r8]
 *   @0x289aa4 ldr r3, [r6, #0x54]
 *   @0x289aa8 cmp r3, #0
 *   @0x289aac beq 0x289b0c <spSkeleton_updateCache+0x510>
 *   @0x289ab0 mov r2, r5
 *   @0x289ab4 mov r0, r4
 *   @0x289ab8 mov r1, #1
 *   @0x289abc bl 0x2892ec <spRegionAttachment_computeWorldVertices+0x178>
 *   @0x289ac0 ldr r0, [r6, #0x10]
 *   @0x289ac4 ldr r1, [r6, #0xc]
 *   @0x289ac8 bl 0x289294 <spRegionAttachment_computeWorldVertices+0x120>
 *   @0x289acc ldr r3, [r5, #0x4]
 *   @0x289ad0 ldr r2, [r4, #0x1c]
 *   @0x289ad4 sub r3, r3, #-1073741823
 *   @0x289ad8 cmp r2, r7
 *   @0x289adc ldr r3, [r8, r3, lsl #2]
 *   @0x289ae0 str r10, [r3, #0x54]
 *   @0x289ae4 ble 0x289790 <spSkeleton_updateCache+0x194>
 *   @0x289ae8 ldr r5, [r9, #0x4]!
 *   @0x289aec add r7, r7, #1
 *   @0x289af0 ldr r1, [r5, #0xc]
 *   @0x289af4 ldr r3, [r1, #0x54]
 *   @0x289af8 cmp r3, #0
 *   @0x289afc bne 0x289a9c <spSkeleton_updateCache+0x4a0>
 *   @0x289b00 mov r0, r4
 *   @0x289b04 bl 0x289358 <spRegionAttachment_computeWorldVertices+0x1e4>
 *   @0x289b08 b 0x289a9c <spSkeleton_updateCache+0x4a0>
 *   @0x289b0c mov r0, r4
 *   @0x289b10 mov r1, r6
 *   @0x289b14 bl 0x289358 <spRegionAttachment_computeWorldVertices+0x1e4>
 *   @0x289b18 b 0x289ab0 <spSkeleton_updateCache+0x4b4>
 *   @0x289b1c cmp r1, lr
 *   @0x289b20 mov r2, r3
 *   @0x289b24 str r2, [r12, #0x18]
 *   @0x289b28 bne 0x2896d8 <spSkeleton_updateCache+0xdc>
 *   @0x289b2c b 0x289710 <spSkeleton_updateCache+0x114>
 *   @0x289b30 mov r3, r6
 *   @0x289b34 b 0x289774 <spSkeleton_updateCache+0x178>
 *   @0x289b38 strdeq lr, pc, [r12], -r8
 *   @0x289b3c muleq r12, r12, r3
 *
 * ══ §4/25 MarkAndSweep  0xd6aac  size 1344  336 条（0xd6aac..0xd6fec）
 * @func 0xd6aac 0xd6fec  size 1344  336 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xd6abc→0x47f295, 0xd6ae0→0x536f08, 0xd6ae8→0x536f0c, 0xd6b30→0x544be0, 0xd6b4c→0x54298c, 0xd6bb4→0x542610, 0xd6bd4→0x48f78c, 0xd6c00→0x4836ac
 * 调用序列: YYObjectBase::Mark4GC(unsigned int*, int)×5 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / DS_AutoMutex::DS_AutoMutex() / MarkAndSweep(YYObjectBase*)+0x1a0 / CDS_Map::Mark4GC(unsigned int*, int) / MarkAndSweep(YYObjectBase*)+0x1ec / CDS_List::Mark4GC(unsigned int*, int) / GetTheStacks(int&)
 * 字段偏移 top8: 0x4×11 / 0x8×3 / 0x2×3 / 0x14×3 / 0x10×3 / 0xc×3 / 0x178×2 / 0x8c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd6aac push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xd6ab0 mov r8, r0
 *   @0xd6ab4 ldr r7, [pc, #0x4f0]
 *   @0xd6ab8 sub sp, sp, #52
 *   @0xd6abc ldr r3, [pc, #0x4ec]
 *   @0xd6ac0 add r7, pc, r7
 *   @0xd6ac4 ldr r3, [r7, r3]
 *   @0xd6ac8 ldrb r4, [r3]
 *   @0xd6acc cmp r4, #0
 *   @0xd6ad0 bne 0xd6ae0 <_Z12MarkAndSweepP12YYObjectBase+0x34>
 *   @0xd6ad4 mov r0, r4
 *   @0xd6ad8 add sp, sp, #52
 *   @0xd6adc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xd6ae0 ldr r0, [pc, #0x4cc]
 *   @0xd6ae4 mov r3, #1
 *   @0xd6ae8 ldr r12, [pc, #0x4c8]
 *   @0xd6aec movw r2, #0x777
 *   @0xd6af0 ldr r1, [pc, #0x4c4]
 *   @0xd6af4 ldr r0, [r7, r0]
 *   @0xd6af8 add r1, pc, r1
 *   @0xd6afc ldr lr, [r0]
 *   @0xd6b00 add lr, lr, r3
 *   @0xd6b04 str lr, [r0]
 *   @0xd6b08 ldr r0, [r7, r12]
 *   @0xd6b0c ldr r4, [r0, #0x4]
 *   @0xd6b10 str r0, [sp]
 *   @0xd6b14 adds r11, r4, #31
 *   @0xd6b18 addmi r11, r4, #62
 *   @0xd6b1c asr r11, r11, #5
 *   @0xd6b20 lsl r11, r11, #2
 *   @0xd6b24 str r11, [sp, #0x4]
 *   @0xd6b28 mov r0, r11
 *   @0xd6b2c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xd6b30 ldr r3, [pc, #0x488]
 *   @0xd6b34 mov r2, r4
 *   @0xd6b38 ldr r3, [r7, r3]
 *   @0xd6b3c mov r1, r0
 *   @0xd6b40 mov r5, r0
 *   @0xd6b44 ldr r0, [r3]
 *   @0xd6b48 bl 0x191bdc <_ZN12YYObjectBase7Mark4GCEPji>
 *   @0xd6b4c ldr r3, [pc, #0x470]
 *   @0xd6b50 ldr r6, [r7, r3]
 *   @0xd6b54 ldr r3, [r6]
 *   @0xd6b58 cmp r3, #0
 *   @0xd6b5c beq 0xd6db0 <_Z12MarkAndSweepP12YYObjectBase+0x304>
 *   @0xd6b60 ldr r0, [r3, #0x80]
 *   @0xd6b64 cmp r0, #0
 *   @0xd6b68 beq 0xd6b8c <_Z12MarkAndSweepP12YYObjectBase+0xe0>
 *   @0xd6b6c ldr r9, [r0, #0x178]
 *   @0xd6b70 mov r1, r5
 *   @0xd6b74 mov r2, r4
 *   @0xd6b78 bl 0x191bdc <_ZN12YYObjectBase7Mark4GCEPji>
 *   @0xd6b7c cmp r9, #0
 *   @0xd6b80 mov r0, r9
 *   @0xd6b84 bne 0xd6b6c <_Z12MarkAndSweepP12YYObjectBase+0xc0>
 *   @0xd6b88 ldr r3, [r6]
 *   @0xd6b8c ldr r0, [r3, #0x8c]
 *   @0xd6b90 cmp r0, #0
 *   @0xd6b94 beq 0xd6bb4 <_Z12MarkAndSweepP12YYObjectBase+0x108>
 *   @0xd6b98 ldr r6, [r0, #0x178]
 *   @0xd6b9c mov r1, r5
 *   @0xd6ba0 mov r2, r4
 *   @0xd6ba4 bl 0x191bdc <_ZN12YYObjectBase7Mark4GCEPji>
 *   @0xd6ba8 cmp r6, #0
 *   @0xd6bac mov r0, r6
 *   @0xd6bb0 bne 0xd6b98 <_Z12MarkAndSweepP12YYObjectBase+0xec>
 *   @0xd6bb4 ldr r3, [pc, #0x40c]
 *   @0xd6bb8 ldr r3, [r7, r3]
 *   @0xd6bbc ldr r0, [r3]
 *   @0xd6bc0 cmp r0, #0
 *   @0xd6bc4 beq 0xd6bd4 <_Z12MarkAndSweepP12YYObjectBase+0x128>
 *   @0xd6bc8 mov r1, r5
 *   @0xd6bcc mov r2, r4
 *   @0xd6bd0 bl 0x191bdc <_ZN12YYObjectBase7Mark4GCEPji>
 *   @0xd6bd4 ldr r3, [pc, #0x3f0]
 *   @0xd6bd8 ldr r3, [r7, r3]
 *   @0xd6bdc ldr r0, [r3, #0x8]
 *   @0xd6be0 cmp r0, #0
 *   @0xd6be4 beq 0xd6bf4 <_Z12MarkAndSweepP12YYObjectBase+0x148>
 *   @0xd6be8 mov r1, r5
 *   @0xd6bec mov r2, r4
 *   @0xd6bf0 bl 0x191bdc <_ZN12YYObjectBase7Mark4GCEPji>
 *   @0xd6bf4 add r10, sp, #28
 *   @0xd6bf8 mov r0, r10
 *   @0xd6bfc bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0xd6c00 ldr r3, [pc, #0x3c8]
 *   @0xd6c04 ldr r11, [r7, r3]
 *   @0xd6c08 ldr r2, [r11]
 *   @0xd6c0c cmp r2, #0
 *   @0xd6c10 ble 0xd6c4c <_Z12MarkAndSweepP12YYObjectBase+0x1a0>
 *   @0xd6c14 ldr r2, [pc, #0x3b8]
 *   @0xd6c18 mov r6, #0
 *   @0xd6c1c ldr r9, [r7, r2]
 *   @0xd6c20 ldr r3, [r9, #0x4]
 *   @0xd6c24 mov r1, r5
 *   @0xd6c28 mov r2, r4
 *   @0xd6c2c ldr r0, [r3, r6, lsl #2]
 *   @0xd6c30 add r6, r6, #1
 *   @0xd6c34 cmp r0, #0
 *   @0xd6c38 beq 0xd6c40 <_Z12MarkAndSweepP12YYObjectBase+0x194>
 *   @0xd6c3c bl 0x2036e4 <_ZN7CDS_Map7Mark4GCEPji>
 *   @0xd6c40 ldr r3, [r11]
 *   @0xd6c44 cmp r3, r6
 *   @0xd6c48 bgt 0xd6c20 <_Z12MarkAndSweepP12YYObjectBase+0x174>
 *   @0xd6c4c ldr r3, [pc, #0x384]
 *   @0xd6c50 ldr r11, [r7, r3]
 *   @0xd6c54 ldr r2, [r11]
 *   @0xd6c58 cmp r2, #0
 *   @0xd6c5c ble 0xd6c98 <_Z12MarkAndSweepP12YYObjectBase+0x1ec>
 *   @0xd6c60 ldr r2, [pc, #0x374]
 *   @0xd6c64 mov r6, #0
 *   @0xd6c68 ldr r9, [r7, r2]
 *   @0xd6c6c ldr r3, [r9, #0x4]
 *   @0xd6c70 mov r1, r5
 *   @0xd6c74 mov r2, r4
 *   @0xd6c78 ldr r0, [r3, r6, lsl #2]
 *   @0xd6c7c add r6, r6, #1
 *   @0xd6c80 cmp r0, #0
 *   @0xd6c84 beq 0xd6c8c <_Z12MarkAndSweepP12YYObjectBase+0x1e0>
 *   @0xd6c88 bl 0x2030ac <_ZN8CDS_List7Mark4GCEPji>
 *   @0xd6c8c ldr r3, [r11]
 *   @0xd6c90 cmp r3, r6
 *   @0xd6c94 bgt 0xd6c6c <_Z12MarkAndSweepP12YYObjectBase+0x1c0>
 *   @0xd6c98 add r0, sp, #32
 *   @0xd6c9c bl 0xffc9c <_Z12GetTheStacksRi>
 *   @0xd6ca0 ldr r12, [sp, #0x20]
 *   @0xd6ca4 cmp r12, #0
 *   @0xd6ca8 movgt r6, #0
 *   @0xd6cac subgt r9, r0, #4
 *   @0xd6cb0 ble 0xd6cdc <_Z12MarkAndSweepP12YYObjectBase+0x230>
 *   @0xd6cb4 ldr r0, [r9, #0x4]!
 *   @0xd6cb8 mov r1, r5
 *   @0xd6cbc mov r2, r4
 *   @0xd6cc0 add r6, r6, #1
 *   @0xd6cc4 cmp r0, #0
 *   @0xd6cc8 beq 0xd6cd4 <_Z12MarkAndSweepP12YYObjectBase+0x228>
 *   @0xd6ccc bl 0x202d50 <_ZN9CDS_Stack7Mark4GCEPji>
 *   @0xd6cd0 ldr r12, [sp, #0x20]
 *   @0xd6cd4 cmp r12, r6
 *   @0xd6cd8 bgt 0xd6cb4 <_Z12MarkAndSweepP12YYObjectBase+0x208>
 *   @0xd6cdc add r0, sp, #36
 *   @0xd6ce0 bl 0xffee8 <_Z12GetTheQueuesRi>
 *   @0xd6ce4 ldr r12, [sp, #0x24]
 *   @0xd6ce8 cmp r12, #0
 *   @0xd6cec movgt r6, #0
 *   @0xd6cf0 subgt r9, r0, #4
 *   @0xd6cf4 ble 0xd6d20 <_Z12MarkAndSweepP12YYObjectBase+0x274>
 *   @0xd6cf8 ldr r0, [r9, #0x4]!
 *   @0xd6cfc mov r1, r5
 *   @0xd6d00 mov r2, r4
 *   @0xd6d04 add r6, r6, #1
 *   @0xd6d08 cmp r0, #0
 *   @0xd6d0c beq 0xd6d18 <_Z12MarkAndSweepP12YYObjectBase+0x26c>
 *   @0xd6d10 bl 0x202ed8 <_ZN9CDS_Queue7Mark4GCEPji>
 *   @0xd6d14 ldr r12, [sp, #0x24]
 *   @0xd6d18 cmp r12, r6
 *   @0xd6d1c bgt 0xd6cf8 <_Z12MarkAndSweepP12YYObjectBase+0x24c>
 *   @0xd6d20 add r0, sp, #40
 *   @0xd6d24 bl 0x10026c <_Z11GetTheGridsRi>
 *   @0xd6d28 ldr r12, [sp, #0x28]
 *   @0xd6d2c cmp r12, #0
 *   @0xd6d30 movgt r6, #0
 *   @0xd6d34 subgt r9, r0, #4
 *   @0xd6d38 ble 0xd6d64 <_Z12MarkAndSweepP12YYObjectBase+0x2b8>
 *   @0xd6d3c ldr r0, [r9, #0x4]!
 *   @0xd6d40 mov r1, r5
 *   @0xd6d44 mov r2, r4
 *   @0xd6d48 add r6, r6, #1
 *   @0xd6d4c cmp r0, #0
 *   @0xd6d50 beq 0xd6d5c <_Z12MarkAndSweepP12YYObjectBase+0x2b0>
 *   @0xd6d54 bl 0x205170 <_ZN8CDS_Grid7Mark4GCEPji>
 *   @0xd6d58 ldr r12, [sp, #0x28]
 *   @0xd6d5c cmp r12, r6
 *   @0xd6d60 bgt 0xd6d3c <_Z12MarkAndSweepP12YYObjectBase+0x290>
 *   @0xd6d64 add r0, sp, #44
 *   @0xd6d68 bl 0x100244 <_Z20GetThePriorityQueuesRi>
 *   @0xd6d6c ldr r12, [sp, #0x2c]
 *   @0xd6d70 cmp r12, #0
 *   @0xd6d74 movgt r6, #0
 *   @0xd6d78 subgt r9, r0, #4
 *   @0xd6d7c ble 0xd6da8 <_Z12MarkAndSweepP12YYObjectBase+0x2fc>
 *   @0xd6d80 ldr r0, [r9, #0x4]!
 *   @0xd6d84 mov r1, r5
 *   @0xd6d88 mov r2, r4
 *   @0xd6d8c add r6, r6, #1
 *   @0xd6d90 cmp r0, #0
 *   @0xd6d94 beq 0xd6da0 <_Z12MarkAndSweepP12YYObjectBase+0x2f4>
 *   @0xd6d98 bl 0x203e28 <_ZN12CDS_Priority7Mark4GCEPji>
 *   @0xd6d9c ldr r12, [sp, #0x2c]
 *   @0xd6da0 cmp r12, r6
 *   @0xd6da4 bgt 0xd6d80 <_Z12MarkAndSweepP12YYObjectBase+0x2d4>
 *   @0xd6da8 mov r0, r10
 *   @0xd6dac bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xd6db0 cmp r8, #0
 *   @0xd6db4 beq 0xd6e08 <_Z12MarkAndSweepP12YYObjectBase+0x35c>
 *   @0xd6db8 ldr r3, [r8, #0x44]
 *   @0xd6dbc mov r0, #1
 *   @0xd6dc0 cmp r3, #0
 *   @0xd6dc4 add r1, r3, #31
 *   @0xd6dc8 asr r2, r3, #31
 *   @0xd6dcc movge r1, r3
 *   @0xd6dd0 lsr r2, r2, #27
 *   @0xd6dd4 asr r1, r1, #5
 *   @0xd6dd8 add r3, r3, r2
 *   @0xd6ddc and r3, r3, #31
 *   @0xd6de0 ldr r1, [r5, r1, lsl #2]
 *   @0xd6de4 rsb r2, r2, r3
 *   @0xd6de8 ands r1, r1, r0, lsl r2
 *   @0xd6dec movne r4, #0
 *   @0xd6df0 moveq r4, #1
 *   @0xd6df4 mov r0, r5
 *   @0xd6df8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xd6dfc mov r0, r4
 *   @0xd6e00 add sp, sp, #52
 *   @0xd6e04 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xd6e08 ldr r3, [pc, #0x1d0]
 *   @0xd6e0c ldr r3, [r7, r3]
 *   @0xd6e10 str r3, [sp, #0x14]
 *   @0xd6e14 ldr r3, [r3]
 *   @0xd6e18 cmp r3, #0
 *   @0xd6e1c beq 0xd6f48 <_Z12MarkAndSweepP12YYObjectBase+0x49c>
 *   @0xd6e20 ldr r2, [pc, #0x1bc]
 *   @0xd6e24 ldr r1, [pc, #0x1bc]
 *   @0xd6e28 ldr r2, [r7, r2]
 *   @0xd6e2c ldr r1, [r7, r1]
 *   @0xd6e30 ldr r10, [r2]
 *   @0xd6e34 str r1, [sp, #0x10]
 *   @0xd6e38 ldr r1, [r1]
 *   @0xd6e3c add r10, r10, r3
 *   @0xd6e40 asr r2, r3, #31
 *   @0xd6e44 cmp r10, r1
 *   @0xd6e48 movge r10, r1
 *   @0xd6e4c ldr r1, [sp]
 *   @0xd6e50 cmp r3, #0
 *   @0xd6e54 add r7, r3, #31
 *   @0xd6e58 lsr r2, r2, #27
 *   @0xd6e5c str r10, [sp, #0xc]
 *   @0xd6e60 movge r7, r3
 *   @0xd6e64 ldr r1, [r1]
 *   @0xd6e68 adds r8, r10, #31
 *   @0xd6e6c add r3, r3, r2
 *   @0xd6e70 addmi r8, r10, #62
 *   @0xd6e74 asr r7, r7, #5
 *   @0xd6e78 tst r4, #31
 *   @0xd6e7c and r6, r3, #31
 *   @0xd6e80 asr r8, r8, #5
 *   @0xd6e84 str r1, [sp, #0x8]
 *   @0xd6e88 str r8, [sp]
 *   @0xd6e8c rsb r6, r2, r6
 *   @0xd6e90 add r3, r5, r7, lsl #2
 *   @0xd6e94 beq 0xd6ec4 <_Z12MarkAndSweepP12YYObjectBase+0x418>
 *   @0xd6e98 ldr r0, [sp, #0x4]
 *   @0xd6e9c asr r2, r4, #31
 *   @0xd6ea0 sub r11, r0, #4
 *   @0xd6ea4 lsr r2, r2, #27
 *   @0xd6ea8 add r12, r4, r2
 *   @0xd6eac mvn r0, #0
 *   @0xd6eb0 ldr r1, [r5, r11]
 *   @0xd6eb4 and r12, r12, #31
 *   @0xd6eb8 rsb r2, r2, r12
 *   @0xd6ebc orr r2, r1, r0, lsl r2
 *   @0xd6ec0 str r2, [r5, r11]
 *   @0xd6ec4 ldr r1, [sp]
 *   @0xd6ec8 cmp r7, r1
 *   @0xd6ecc strlt r5, [sp, #0x4]
 *   @0xd6ed0 sublt r8, r3, #4
 *   @0xd6ed4 lsllt r4, r7, #5
 *   @0xd6ed8 movlt r10, #1
 *   @0xd6edc bge 0xd6f74 <_Z12MarkAndSweepP12YYObjectBase+0x4c8>
 *   @0xd6ee0 ldr r9, [r8, #0x4]!
 *   @0xd6ee4 cmn r9, #1
 *   @0xd6ee8 beq 0xd6f2c <_Z12MarkAndSweepP12YYObjectBase+0x480>
 *   @0xd6eec cmp r6, #31
 *   @0xd6ef0 bhi 0xd6f2c <_Z12MarkAndSweepP12YYObjectBase+0x480>
 *   @0xd6ef4 add r1, r6, r4
 *   @0xd6ef8 ldr r3, [sp, #0x8]
 *   @0xd6efc mov r11, #0
 *   @0xd6f00 add r5, r3, r1, lsl #2
 *   @0xd6f04 ands r0, r9, r10, lsl r6
 *   @0xd6f08 bne 0xd6f1c <_Z12MarkAndSweepP12YYObjectBase+0x470>
 *   @0xd6f0c ldr r0, [r5, r11]
 *   @0xd6f10 cmp r0, #0
 *   @0xd6f14 beq 0xd6f1c <_Z12MarkAndSweepP12YYObjectBase+0x470>
 *   @0xd6f18 bl 0x198f88 <_ZN12YYObjectBase4FreeEPS_>
 *   @0xd6f1c add r6, r6, #1
 *   @0xd6f20 add r11, r11, #4
 *   @0xd6f24 cmp r6, #32
 *   @0xd6f28 bne 0xd6f04 <_Z12MarkAndSweepP12YYObjectBase+0x458>
 *   @0xd6f2c ldr r2, [sp]
 *   @0xd6f30 add r7, r7, #1
 *   @0xd6f34 add r4, r4, #32
 *   @0xd6f38 cmp r7, r2
 *   @0xd6f3c beq 0xd6f70 <_Z12MarkAndSweepP12YYObjectBase+0x4c4>
 *   @0xd6f40 mov r6, #0
 *   @0xd6f44 b 0xd6ee0 <_Z12MarkAndSweepP12YYObjectBase+0x434>
 *   @0xd6f48 ldr r0, [pc, #0x98]
 *   @0xd6f4c mov r1, r4
 *   @0xd6f50 ldr r2, [pc, #0x8c]
 *   @0xd6f54 mov r10, r4
 *   @0xd6f58 ldr r0, [r7, r0]
 *   @0xd6f5c str r0, [sp, #0x10]
 *   @0xd6f60 str r4, [r0]
 *   @0xd6f64 ldr r2, [r7, r2]
 *   @0xd6f68 str r4, [r2]
 *   @0xd6f6c b 0xd6e3c <_Z12MarkAndSweepP12YYObjectBase+0x390>
 *   @0xd6f70 ldr r5, [sp, #0x4]
 *   @0xd6f74 ldr r2, [sp, #0x10]
 *   @0xd6f78 ldr r1, [sp, #0xc]
 *   @0xd6f7c ldr r3, [r2]
 *   @0xd6f80 cmp r3, r1
 *   @0xd6f84 beq 0xd6f9c <_Z12MarkAndSweepP12YYObjectBase+0x4f0>
 *   @0xd6f88 ldr r2, [sp, #0xc]
 *   @0xd6f8c mov r4, #0
 *   @0xd6f90 ldr r3, [sp, #0x14]
 *   @0xd6f94 str r2, [r3]
 *   @0xd6f98 b 0xd6df4 <_Z12MarkAndSweepP12YYObjectBase+0x348>
 *   @0xd6f9c ldr r1, [sp, #0x14]
 *   @0xd6fa0 mov r4, #0
 *   @0xd6fa4 str r4, [r1]
 *   @0xd6fa8 b 0xd6df4 <_Z12MarkAndSweepP12YYObjectBase+0x348>
 *   @0xd6fac mlaseq r1, r0, r1, r11
 *   @0xd6fb0 .word 0xffffbf68
 *   @0xd6fb4 .word 0xffffbffc
 *   @0xd6fb8 .word 0xffffc014
 *   @0xd6fbc eoreq r11, r5, r4, lsl #25
 *   @0xd6fc0 .word 0xffffbf64
 *   @0xd6fc4 .word 0xffffbcd8
 *   @0xd6fc8 .word 0xffffc020
 *   @0xd6fcc .word 0xffffc024
 *   @0xd6fd0 .word 0xffffc028
 *   @0xd6fd4 .word 0xffffbcec
 *   @0xd6fd8 .word 0xffffc02c
 *   @0xd6fdc .word 0xffffc030
 *   @0xd6fe0 .word 0xffffc078
 *   @0xd6fe4 .word 0xffffc07c
 *   @0xd6fe8 .word 0xffffc080
 *
 * ══ §5/25 b2DynamicTree::Balance  0x2deae4  size 1260  315 条（0x2deae4..0x2defd0）
 * @func 0x2deae4 0x2defe4  size 1280  320 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2DynamicTree::Balance(int)+0x1a4 / b2DynamicTree::Balance(int)+0x2a4 / b2DynamicTree::Balance(int)+0x1b0 / b2DynamicTree::Balance(int)+0x3fc
 * 字段偏移 top8: 0x20×19 / 0x14×12 / 0x18×9 / 0x1c×9 / 0x4×1
 * VFP 指令 184 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2deae4 ldr r12, [r0, #0x4]
 *   @0x2deae8 add r3, r1, r1, lsl #3
 *   @0x2deaec push {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x2deaf0 add r3, r12, r3, lsl #2
 *   @0x2deaf4 ldr r5, [r3, #0x18]
 *   @0x2deaf8 cmn r5, #1
 *   @0x2deafc beq 0x2dec88 <_ZN13b2DynamicTree7BalanceEi+0x1a4>
 *   @0x2deb00 ldr r2, [r3, #0x20]
 *   @0x2deb04 cmp r2, #1
 *   @0x2deb08 ble 0x2dec88 <_ZN13b2DynamicTree7BalanceEi+0x1a4>
 *   @0x2deb0c ldr r8, [r3, #0x1c]
 *   @0x2deb10 add r4, r5, r5, lsl #3
 *   @0x2deb14 add r4, r12, r4, lsl #2
 *   @0x2deb18 add r2, r8, r8, lsl #3
 *   @0x2deb1c ldr r9, [r4, #0x20]
 *   @0x2deb20 add r2, r12, r2, lsl #2
 *   @0x2deb24 ldr r7, [r2, #0x20]
 *   @0x2deb28 rsb r6, r9, r7
 *   @0x2deb2c cmp r6, #1
 *   @0x2deb30 ble 0x2ded88 <_ZN13b2DynamicTree7BalanceEi+0x2a4>
 *   @0x2deb34 ldr r6, [r3, #0x14]
 *   @0x2deb38 ldr r5, [r2, #0x18]
 *   @0x2deb3c ldr r10, [r2, #0x1c]
 *   @0x2deb40 str r6, [r2, #0x14]
 *   @0x2deb44 str r1, [r2, #0x18]
 *   @0x2deb48 add r7, r5, r5, lsl #3
 *   @0x2deb4c str r8, [r3, #0x14]
 *   @0x2deb50 add r6, r10, r10, lsl #3
 *   @0x2deb54 ldr r11, [r2, #0x14]
 *   @0x2deb58 add r7, r12, r7, lsl #2
 *   @0x2deb5c add r6, r12, r6, lsl #2
 *   @0x2deb60 cmn r11, #1
 *   @0x2deb64 streq r8, [r0]
 *   @0x2deb68 beq 0x2deb84 <_ZN13b2DynamicTree7BalanceEi+0xa0>
 *   @0x2deb6c add r11, r11, r11, lsl #3
 *   @0x2deb70 add r12, r12, r11, lsl #2
 *   @0x2deb74 ldr r0, [r12, #0x18]
 *   @0x2deb78 cmp r0, r1
 *   @0x2deb7c streq r8, [r12, #0x18]
 *   @0x2deb80 strne r8, [r12, #0x1c]
 *   @0x2deb84 ldr r12, [r7, #0x20]
 *   @0x2deb88 ldr r11, [r6, #0x20]
 *   @0x2deb8c cmp r12, r11
 *   @0x2deb90 ble 0x2dec94 <_ZN13b2DynamicTree7BalanceEi+0x1b0>
 *   @0x2deb94 vldr s14, [r6]
 *   @0x2deb98 str r5, [r2, #0x1c]
 *   @0x2deb9c str r10, [r3, #0x1c]
 *   @0x2deba0 vldr s15, [r6, #4]
 *   @0x2deba4 str r1, [r6, #0x14]
 *   @0x2deba8 vldr s12, [r4]
 *   @0x2debac vcmpe.f32 s12, s14
 *   @0x2debb0 vldr s13, [r4, #4]
 *   @0x2debb4 mov r0, r8
 *   @0x2debb8 vmrs APSR_nzcv, fpscr
 *   @0x2debbc vcmpe.f32 s13, s15
 *   @0x2debc0 vmovmi.f32 s14, s12
 *   @0x2debc4 vmrs APSR_nzcv, fpscr
 *   @0x2debc8 vstr s14, [r3]
 *   @0x2debcc vmovmi.f32 s15, s13
 *   @0x2debd0 vstr s15, [r3, #4]
 *   @0x2debd4 vldr s10, [r4, #8]
 *   @0x2debd8 vldr s11, [r6, #8]
 *   @0x2debdc vldr s12, [r4, #12]
 *   @0x2debe0 vldr s13, [r6, #12]
 *   @0x2debe4 vcmpe.f32 s10, s11
 *   @0x2debe8 vmrs APSR_nzcv, fpscr
 *   @0x2debec vcmpe.f32 s12, s13
 *   @0x2debf0 vmovgt.f32 s11, s10
 *   @0x2debf4 vmrs APSR_nzcv, fpscr
 *   @0x2debf8 vstr s11, [r3, #8]
 *   @0x2debfc vmovgt.f32 s13, s12
 *   @0x2dec00 vstr s13, [r3, #12]
 *   @0x2dec04 vldr s12, [r7]
 *   @0x2dec08 vldr s13, [r7, #4]
 *   @0x2dec0c vcmpe.f32 s14, s12
 *   @0x2dec10 vmrs APSR_nzcv, fpscr
 *   @0x2dec14 vcmpe.f32 s15, s13
 *   @0x2dec18 vmovpl.f32 s14, s12
 *   @0x2dec1c vmrs APSR_nzcv, fpscr
 *   @0x2dec20 vstr s14, [r2]
 *   @0x2dec24 vmovpl.f32 s15, s13
 *   @0x2dec28 vstr s15, [r2, #4]
 *   @0x2dec2c vldr s13, [r7, #8]
 *   @0x2dec30 vldr s12, [r3, #8]
 *   @0x2dec34 vldr s15, [r7, #12]
 *   @0x2dec38 vldr s14, [r3, #12]
 *   @0x2dec3c vcmpe.f32 s12, s13
 *   @0x2dec40 vmrs APSR_nzcv, fpscr
 *   @0x2dec44 vcmpe.f32 s14, s15
 *   @0x2dec48 vmovgt.f32 s13, s12
 *   @0x2dec4c vmrs APSR_nzcv, fpscr
 *   @0x2dec50 vstr s13, [r2, #8]
 *   @0x2dec54 vmovgt.f32 s15, s14
 *   @0x2dec58 cmp r9, r11
 *   @0x2dec5c movlt r9, r11
 *   @0x2dec60 add r9, r9, #1
 *   @0x2dec64 vstr s15, [r2, #12]
 *   @0x2dec68 str r9, [r3, #0x20]
 *   @0x2dec6c ldr r3, [r7, #0x20]
 *   @0x2dec70 cmp r9, r3
 *   @0x2dec74 movlt r9, r3
 *   @0x2dec78 add r9, r9, #1
 *   @0x2dec7c str r9, [r2, #0x20]
 *   @0x2dec80 pop {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x2dec84 bx lr
 *   @0x2dec88 mov r0, r1
 *   @0x2dec8c pop {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x2dec90 bx lr
 *   @0x2dec94 vldr s14, [r7]
 *   @0x2dec98 str r10, [r2, #0x1c]
 *   @0x2dec9c str r5, [r3, #0x1c]
 *   @0x2deca0 vldr s15, [r7, #4]
 *   @0x2deca4 str r1, [r7, #0x14]
 *   @0x2deca8 vldr s12, [r4]
 *   @0x2decac vcmpe.f32 s12, s14
 *   @0x2decb0 vldr s13, [r4, #4]
 *   @0x2decb4 mov r0, r8
 *   @0x2decb8 vmrs APSR_nzcv, fpscr
 *   @0x2decbc vcmpe.f32 s13, s15
 *   @0x2decc0 vmovmi.f32 s14, s12
 *   @0x2decc4 vmrs APSR_nzcv, fpscr
 *   @0x2decc8 vstr s14, [r3]
 *   @0x2deccc vmovmi.f32 s15, s13
 *   @0x2decd0 vstr s15, [r3, #4]
 *   @0x2decd4 vldr s10, [r4, #8]
 *   @0x2decd8 vldr s11, [r7, #8]
 *   @0x2decdc vldr s12, [r4, #12]
 *   @0x2dece0 vldr s13, [r7, #12]
 *   @0x2dece4 vcmpe.f32 s10, s11
 *   @0x2dece8 vmrs APSR_nzcv, fpscr
 *   @0x2decec vcmpe.f32 s12, s13
 *   @0x2decf0 vmovgt.f32 s11, s10
 *   @0x2decf4 vmrs APSR_nzcv, fpscr
 *   @0x2decf8 vstr s11, [r3, #8]
 *   @0x2decfc vmovgt.f32 s13, s12
 *   @0x2ded00 vstr s13, [r3, #12]
 *   @0x2ded04 vldr s12, [r6]
 *   @0x2ded08 vldr s13, [r6, #4]
 *   @0x2ded0c vcmpe.f32 s14, s12
 *   @0x2ded10 vmrs APSR_nzcv, fpscr
 *   @0x2ded14 vcmpe.f32 s15, s13
 *   @0x2ded18 vmovpl.f32 s14, s12
 *   @0x2ded1c vmrs APSR_nzcv, fpscr
 *   @0x2ded20 vstr s14, [r2]
 *   @0x2ded24 vmovpl.f32 s15, s13
 *   @0x2ded28 vstr s15, [r2, #4]
 *   @0x2ded2c vldr s13, [r6, #8]
 *   @0x2ded30 vldr s12, [r3, #8]
 *   @0x2ded34 vldr s15, [r6, #12]
 *   @0x2ded38 vldr s14, [r3, #12]
 *   @0x2ded3c vcmpe.f32 s12, s13
 *   @0x2ded40 vmrs APSR_nzcv, fpscr
 *   @0x2ded44 vcmpe.f32 s14, s15
 *   @0x2ded48 vmovgt.f32 s13, s12
 *   @0x2ded4c vmrs APSR_nzcv, fpscr
 *   @0x2ded50 vstr s13, [r2, #8]
 *   @0x2ded54 vmovgt.f32 s15, s14
 *   @0x2ded58 cmp r12, r9
 *   @0x2ded5c movlt r12, r9
 *   @0x2ded60 add r12, r12, #1
 *   @0x2ded64 vstr s15, [r2, #12]
 *   @0x2ded68 str r12, [r3, #0x20]
 *   @0x2ded6c ldr r3, [r6, #0x20]
 *   @0x2ded70 pop {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x2ded74 cmp r12, r3
 *   @0x2ded78 movlt r12, r3
 *   @0x2ded7c add r12, r12, #1
 *   @0x2ded80 str r12, [r2, #0x20]
 *   @0x2ded84 bx lr
 *   @0x2ded88 cmn r6, #1
 *   @0x2ded8c bge 0x2dec88 <_ZN13b2DynamicTree7BalanceEi+0x1a4>
 *   @0x2ded90 ldr r6, [r3, #0x14]
 *   @0x2ded94 ldr r9, [r4, #0x18]
 *   @0x2ded98 ldr r10, [r4, #0x1c]
 *   @0x2ded9c str r6, [r4, #0x14]
 *   @0x2deda0 str r1, [r4, #0x18]
 *   @0x2deda4 add r8, r9, r9, lsl #3
 *   @0x2deda8 str r5, [r3, #0x14]
 *   @0x2dedac add r6, r10, r10, lsl #3
 *   @0x2dedb0 ldr r11, [r4, #0x14]
 *   @0x2dedb4 add r8, r12, r8, lsl #2
 *   @0x2dedb8 add r6, r12, r6, lsl #2
 *   @0x2dedbc cmn r11, #1
 *   @0x2dedc0 streq r5, [r0]
 *   @0x2dedc4 beq 0x2dede0 <_ZN13b2DynamicTree7BalanceEi+0x2fc>
 *   @0x2dedc8 add r11, r11, r11, lsl #3
 *   @0x2dedcc add r12, r12, r11, lsl #2
 *   @0x2dedd0 ldr r0, [r12, #0x18]
 *   @0x2dedd4 cmp r0, r1
 *   @0x2dedd8 streq r5, [r12, #0x18]
 *   @0x2deddc strne r5, [r12, #0x1c]
 *   @0x2dede0 ldr r12, [r8, #0x20]
 *   @0x2dede4 ldr r11, [r6, #0x20]
 *   @0x2dede8 cmp r12, r11
 *   @0x2dedec ble 0x2deee0 <_ZN13b2DynamicTree7BalanceEi+0x3fc>
 *   @0x2dedf0 vldr s14, [r6]
 *   @0x2dedf4 str r9, [r4, #0x1c]
 *   @0x2dedf8 str r10, [r3, #0x18]
 *   @0x2dedfc vldr s15, [r6, #4]
 *   @0x2dee00 str r1, [r6, #0x14]
 *   @0x2dee04 vldr s12, [r2]
 *   @0x2dee08 vcmpe.f32 s12, s14
 *   @0x2dee0c vldr s13, [r2, #4]
 *   @0x2dee10 mov r0, r5
 *   @0x2dee14 vmrs APSR_nzcv, fpscr
 *   @0x2dee18 vcmpe.f32 s13, s15
 *   @0x2dee1c vmovmi.f32 s14, s12
 *   @0x2dee20 vmrs APSR_nzcv, fpscr
 *   @0x2dee24 vstr s14, [r3]
 *   @0x2dee28 vmovmi.f32 s15, s13
 *   @0x2dee2c vstr s15, [r3, #4]
 *   @0x2dee30 vldr s10, [r2, #8]
 *   @0x2dee34 vldr s11, [r6, #8]
 *   @0x2dee38 vldr s12, [r2, #12]
 *   @0x2dee3c vldr s13, [r6, #12]
 *   @0x2dee40 vcmpe.f32 s10, s11
 *   @0x2dee44 vmrs APSR_nzcv, fpscr
 *   @0x2dee48 vcmpe.f32 s12, s13
 *   @0x2dee4c vmovgt.f32 s11, s10
 *   @0x2dee50 vmrs APSR_nzcv, fpscr
 *   @0x2dee54 vstr s11, [r3, #8]
 *   @0x2dee58 vmovgt.f32 s13, s12
 *   @0x2dee5c vstr s13, [r3, #12]
 *   @0x2dee60 vldr s12, [r8]
 *   @0x2dee64 vldr s13, [r8, #4]
 *   @0x2dee68 vcmpe.f32 s14, s12
 *   @0x2dee6c vmrs APSR_nzcv, fpscr
 *   @0x2dee70 vcmpe.f32 s15, s13
 *   @0x2dee74 vmovpl.f32 s14, s12
 *   @0x2dee78 vmrs APSR_nzcv, fpscr
 *   @0x2dee7c vstr s14, [r4]
 *   @0x2dee80 vmovpl.f32 s15, s13
 *   @0x2dee84 vstr s15, [r4, #4]
 *   @0x2dee88 vldr s12, [r3, #8]
 *   @0x2dee8c vldr s13, [r8, #8]
 *   @0x2dee90 vldr s14, [r3, #12]
 *   @0x2dee94 vldr s15, [r8, #12]
 *   @0x2dee98 vcmpe.f32 s12, s13
 *   @0x2dee9c vmrs APSR_nzcv, fpscr
 *   @0x2deea0 vcmpe.f32 s14, s15
 *   @0x2deea4 vmovgt.f32 s13, s12
 *   @0x2deea8 vmrs APSR_nzcv, fpscr
 *   @0x2deeac vstr s13, [r4, #8]
 *   @0x2deeb0 vmovgt.f32 s15, s14
 *   @0x2deeb4 cmp r7, r11
 *   @0x2deeb8 movlt r7, r11
 *   @0x2deebc add r7, r7, #1
 *   @0x2deec0 vstr s15, [r4, #12]
 *   @0x2deec4 str r7, [r3, #0x20]
 *   @0x2deec8 ldr r3, [r8, #0x20]
 *   @0x2deecc cmp r7, r3
 *   @0x2deed0 movlt r7, r3
 *   @0x2deed4 add r7, r7, #1
 *   @0x2deed8 str r7, [r4, #0x20]
 *   @0x2deedc b 0x2dec8c <_ZN13b2DynamicTree7BalanceEi+0x1a8>
 *   @0x2deee0 vldr s14, [r8]
 *   @0x2deee4 str r10, [r4, #0x1c]
 *   @0x2deee8 str r9, [r3, #0x18]
 *   @0x2deeec vldr s15, [r8, #4]
 *   @0x2deef0 str r1, [r8, #0x14]
 *   @0x2deef4 vldr s12, [r2]
 *   @0x2deef8 vcmpe.f32 s12, s14
 *   @0x2deefc vldr s13, [r2, #4]
 *   @0x2def00 mov r0, r5
 *   @0x2def04 vmrs APSR_nzcv, fpscr
 *   @0x2def08 vcmpe.f32 s13, s15
 *   @0x2def0c vmovmi.f32 s14, s12
 *   @0x2def10 vmrs APSR_nzcv, fpscr
 *   @0x2def14 vstr s14, [r3]
 *   @0x2def18 vmovmi.f32 s15, s13
 *   @0x2def1c vstr s15, [r3, #4]
 *   @0x2def20 vldr s10, [r2, #8]
 *   @0x2def24 vldr s11, [r8, #8]
 *   @0x2def28 vldr s12, [r2, #12]
 *   @0x2def2c vldr s13, [r8, #12]
 *   @0x2def30 vcmpe.f32 s10, s11
 *   @0x2def34 vmrs APSR_nzcv, fpscr
 *   @0x2def38 vcmpe.f32 s12, s13
 *   @0x2def3c vmovgt.f32 s11, s10
 *   @0x2def40 vmrs APSR_nzcv, fpscr
 *   @0x2def44 vstr s11, [r3, #8]
 *   @0x2def48 vmovgt.f32 s13, s12
 *   @0x2def4c vstr s13, [r3, #12]
 *   @0x2def50 vldr s12, [r6]
 *   @0x2def54 vldr s13, [r6, #4]
 *   @0x2def58 vcmpe.f32 s14, s12
 *   @0x2def5c vmrs APSR_nzcv, fpscr
 *   @0x2def60 vcmpe.f32 s15, s13
 *   @0x2def64 vmovpl.f32 s14, s12
 *   @0x2def68 vmrs APSR_nzcv, fpscr
 *   @0x2def6c vstr s14, [r4]
 *   @0x2def70 vmovpl.f32 s15, s13
 *   @0x2def74 vstr s15, [r4, #4]
 *   @0x2def78 vldr s12, [r3, #8]
 *   @0x2def7c vldr s13, [r6, #8]
 *   @0x2def80 vldr s14, [r3, #12]
 *   @0x2def84 vldr s15, [r6, #12]
 *   @0x2def88 vcmpe.f32 s12, s13
 *   @0x2def8c vmrs APSR_nzcv, fpscr
 *   @0x2def90 vcmpe.f32 s14, s15
 *   @0x2def94 vmovgt.f32 s13, s12
 *   @0x2def98 vmrs APSR_nzcv, fpscr
 *   @0x2def9c vstr s13, [r4, #8]
 *   @0x2defa0 vmovgt.f32 s15, s14
 *   @0x2defa4 cmp r12, r7
 *   @0x2defa8 movlt r12, r7
 *   @0x2defac add r12, r12, #1
 *   @0x2defb0 vstr s15, [r4, #12]
 *   @0x2defb4 str r12, [r3, #0x20]
 *   @0x2defb8 ldr r3, [r6, #0x20]
 *   @0x2defbc cmp r12, r3
 *   @0x2defc0 movlt r12, r3
 *   @0x2defc4 add r12, r12, #1
 *   @0x2defc8 str r12, [r4, #0x20]
 *   @0x2defcc b 0x2dec8c <_ZN13b2DynamicTree7BalanceEi+0x1a8>
 *
 * ══ §6/25 b2SeparationFunction::Initialize  0x2dfcf4  size 1236  309 条（0x2dfcf4..0x2e01c8）
 * @func 0x2dfcf4 0x2e01dc  size 1256  314 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6700×3 / 0xb6580×2 / 0xb658c×2
 * 字段偏移 top8: 0x10×6 / 0x50×4 / 0x6×4 / 0x4×3 / 0x9×3 / 0x7×2 / 0x54×1 / 0xa×1
 * VFP 指令 227 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2dfcf4 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2dfcf8 vpush {d8, d9, d10, d11, d12, d13}
 *   @0x2dfcfc mov r6, r3
 *   @0x2dfd00 vldr s16, [sp, #88]
 *   @0x2dfd04 mov r4, r0
 *   @0x2dfd08 mov r7, r1
 *   @0x2dfd0c mov r8, r2
 *   @0x2dfd10 ldr r9, [sp, #0x50]
 *   @0x2dfd14 ldm r6!, {r0, r1, r2, r3}
 *   @0x2dfd18 add r5, r4, #8
 *   @0x2dfd1c ldrh r10, [r7, #4]
 *   @0x2dfd20 vmov.f32 s17, #1.000000e+00
 *   @0x2dfd24 str r8, [r4]
 *   @0x2dfd28 add r12, r4, #44
 *   @0x2dfd2c str r9, [r4, #0x4]
 *   @0x2dfd30 stm r5!, {r0, r1, r2, r3}
 *   @0x2dfd34 ldm r6!, {r0, r1, r2, r3}
 *   @0x2dfd38 ldr lr, [sp, #0x54]
 *   @0x2dfd3c stm r5!, {r0, r1, r2, r3}
 *   @0x2dfd40 vsub.f32 s17, s17, s16
 *   @0x2dfd44 ldr r3, [r6]
 *   @0x2dfd48 str r3, [r5]
 *   @0x2dfd4c ldm lr!, {r0, r1, r2, r3}
 *   @0x2dfd50 stm r12!, {r0, r1, r2, r3}
 *   @0x2dfd54 ldm lr!, {r0, r1, r2, r3}
 *   @0x2dfd58 stm r12!, {r0, r1, r2, r3}
 *   @0x2dfd5c vldr s18, [r4, #36]
 *   @0x2dfd60 vmul.f32 s18, s16, s18
 *   @0x2dfd64 vldr s15, [r4, #32]
 *   @0x2dfd68 ldr r3, [lr]
 *   @0x2dfd6c str r3, [r12]
 *   @0x2dfd70 vmla.f32 s18, s17, s15
 *   @0x2dfd74 vmov r0, s18
 *   @0x2dfd78 bl 0xb6580 <sinf@plt>
 *   @0x2dfd7c vmov s19, r0
 *   @0x2dfd80 vmov r0, s18
 *   @0x2dfd84 bl 0xb658c <cosf@plt>
 *   @0x2dfd88 vldr s20, [r4, #72]
 *   @0x2dfd8c vmul.f32 s20, s16, s20
 *   @0x2dfd90 vldr s15, [r4, #12]
 *   @0x2dfd94 vldr s12, [r4, #24]
 *   @0x2dfd98 vldr s14, [r4, #28]
 *   @0x2dfd9c vldr s8, [r4, #68]
 *   @0x2dfda0 vldr s11, [r4, #8]
 *   @0x2dfda4 vldr s9, [r4, #16]
 *   @0x2dfda8 vldr s10, [r4, #20]
 *   @0x2dfdac vmul.f32 s12, s16, s12
 *   @0x2dfdb0 vmul.f32 s13, s15, s19
 *   @0x2dfdb4 vmov s18, r0
 *   @0x2dfdb8 vmul.f32 s14, s16, s14
 *   @0x2dfdbc vmul.f32 s15, s15, s18
 *   @0x2dfdc0 vmla.f32 s20, s17, s8
 *   @0x2dfdc4 vmla.f32 s12, s17, s9
 *   @0x2dfdc8 vmov r0, s20
 *   @0x2dfdcc vmla.f32 s14, s17, s10
 *   @0x2dfdd0 vnmls.f32 s13, s11, s18
 *   @0x2dfdd4 vmla.f32 s15, s11, s19
 *   @0x2dfdd8 vsub.f32 s22, s12, s13
 *   @0x2dfddc vsub.f32 s23, s14, s15
 *   @0x2dfde0 bl 0xb6580 <sinf@plt>
 *   @0x2dfde4 vmov s21, r0
 *   @0x2dfde8 vmov r0, s20
 *   @0x2dfdec bl 0xb658c <cosf@plt>
 *   @0x2dfdf0 vldr s12, [r4, #48]
 *   @0x2dfdf4 vldr s13, [r4, #60]
 *   @0x2dfdf8 vldr s8, [r4, #64]
 *   @0x2dfdfc vmul.f32 s13, s16, s13
 *   @0x2dfe00 vldr s11, [r4, #44]
 *   @0x2dfe04 vldr s9, [r4, #52]
 *   @0x2dfe08 vldr s10, [r4, #56]
 *   @0x2dfe0c cmp r10, #1
 *   @0x2dfe10 vmul.f32 s14, s12, s21
 *   @0x2dfe14 vmul.f32 s16, s16, s8
 *   @0x2dfe18 vmov s20, r0
 *   @0x2dfe1c vmul.f32 s15, s12, s20
 *   @0x2dfe20 vmla.f32 s16, s17, s10
 *   @0x2dfe24 vmla.f32 s13, s17, s9
 *   @0x2dfe28 vnmls.f32 s14, s11, s20
 *   @0x2dfe2c vmla.f32 s15, s11, s21
 *   @0x2dfe30 vsub.f32 s17, s13, s14
 *   @0x2dfe34 vsub.f32 s16, s16, s15
 *   @0x2dfe38 beq 0x2e00d4 <_ZN20b2SeparationFunction10InitializeEPK14b2SimplexCachePK15b2DistanceProxyRK7b2SweepS5_S8_f+0x3e0>
 *   @0x2dfe3c ldrb r2, [r7, #0x6]
 *   @0x2dfe40 ldrb r3, [r7, #0x7]
 *   @0x2dfe44 cmp r2, r3
 *   @0x2dfe48 beq 0x2dff90 <_ZN20b2SeparationFunction10InitializeEPK14b2SimplexCachePK15b2DistanceProxyRK7b2SweepS5_S8_f+0x29c>
 *   @0x2dfe4c mov r3, #1
 *   @0x2dfe50 str r3, [r4, #0x50]
 *   @0x2dfe54 ldrb r2, [r7, #0x6]
 *   @0x2dfe58 ldrb r1, [r7, #0x7]
 *   @0x2dfe5c ldr r3, [r8, #0x10]
 *   @0x2dfe60 add r2, r3, r2, lsl #3
 *   @0x2dfe64 add r3, r3, r1, lsl #3
 *   @0x2dfe68 vldr s26, [r2]
 *   @0x2dfe6c vldr s27, [r3]
 *   @0x2dfe70 vsub.f32 s14, s27, s26
 *   @0x2dfe74 vldr s24, [r2, #4]
 *   @0x2dfe78 vldr s25, [r3, #4]
 *   @0x2dfe7c vneg.f32 s14, s14
 *   @0x2dfe80 vmul.f32 s12, s14, s14
 *   @0x2dfe84 vstr s14, [r4, #96]
 *   @0x2dfe88 vsub.f32 s14, s25, s24
 *   @0x2dfe8c vmla.f32 s12, s14, s14
 *   @0x2dfe90 vstr s14, [r4, #92]
 *   @0x2dfe94 vsqrt.f32 s11, s12
 *   @0x2dfe98 vcmp.f32 s11, s11
 *   @0x2dfe9c vmrs APSR_nzcv, fpscr
 *   @0x2dfea0 bne 0x2e0194 <_ZN20b2SeparationFunction10InitializeEPK14b2SimplexCachePK15b2DistanceProxyRK7b2SweepS5_S8_f+0x4a0>
 *   @0x2dfea4 vldr s15, [pc, #792]
 *   @0x2dfea8 vcmpe.f32 s11, s15
 *   @0x2dfeac vmrs APSR_nzcv, fpscr
 *   @0x2dfeb0 bmi 0x2dff84 <_ZN20b2SeparationFunction10InitializeEPK14b2SimplexCachePK15b2DistanceProxyRK7b2SweepS5_S8_f+0x290>
 *   @0x2dfeb4 vmov.f32 s14, #1.000000e+00
 *   @0x2dfeb8 vldr s6, [r4, #92]
 *   @0x2dfebc vldr s15, [r4, #96]
 *   @0x2dfec0 vdiv.f32 s11, s14, s11
 *   @0x2dfec4 vmul.f32 s6, s11, s6
 *   @0x2dfec8 vmul.f32 s11, s11, s15
 *   @0x2dfecc vstr s6, [r4, #92]
 *   @0x2dfed0 vmov.f32 s7, s11
 *   @0x2dfed4 vstr s11, [r4, #96]
 *   @0x2dfed8 ldr r3, [r4, #0x4]
 *   @0x2dfedc vmov.f32 s14, #5.000000e-01
 *   @0x2dfee0 ldr r3, [r3, #0x10]
 *   @0x2dfee4 vadd.f32 s15, s27, s26
 *   @0x2dfee8 vadd.f32 s12, s25, s24
 *   @0x2dfeec vmul.f32 s15, s15, s14
 *   @0x2dfef0 vmul.f32 s12, s12, s14
 *   @0x2dfef4 vstr s15, [r4, #84]
 *   @0x2dfef8 vstr s12, [r4, #88]
 *   @0x2dfefc ldrb r2, [r7, #0x9]
 *   @0x2dff00 vmul.f32 s9, s12, s18
 *   @0x2dff04 add r3, r3, r2, lsl #3
 *   @0x2dff08 vldr s10, [r3, #4]
 *   @0x2dff0c vldr s5, [r3]
 *   @0x2dff10 vmul.f32 s8, s10, s20
 *   @0x2dff14 vmla.f32 s9, s15, s19
 *   @0x2dff18 vmul.f32 s12, s12, s19
 *   @0x2dff1c vmul.f32 s10, s10, s21
 *   @0x2dff20 vmla.f32 s8, s5, s21
 *   @0x2dff24 vmul.f32 s11, s7, s18
 *   @0x2dff28 vnmls.f32 s12, s15, s18
 *   @0x2dff2c vnmls.f32 s10, s5, s20
 *   @0x2dff30 vmla.f32 s11, s19, s6
 *   @0x2dff34 vmul.f32 s19, s7, s19
 *   @0x2dff38 vadd.f32 s15, s8, s16
 *   @0x2dff3c vadd.f32 s23, s9, s23
 *   @0x2dff40 vsub.f32 s15, s15, s23
 *   @0x2dff44 vnmls.f32 s19, s18, s6
 *   @0x2dff48 vadd.f32 s10, s10, s17
 *   @0x2dff4c vadd.f32 s12, s12, s22
 *   @0x2dff50 vmul.f32 s15, s11, s15
 *   @0x2dff54 vsub.f32 s12, s10, s12
 *   @0x2dff58 vmla.f32 s15, s19, s12
 *   @0x2dff5c vcmpe.f32 s15, #0
 *   @0x2dff60 vmrs APSR_nzcv, fpscr
 *   @0x2dff64 vnegmi.f32 s15, s15
 *   @0x2dff68 vmov r0, s15
 *   @0x2dff6c vnegmi.f32 s6, s6
 *   @0x2dff70 vnegmi.f32 s7, s7
 *   @0x2dff74 vstrmi s6, [r4, #92]
 *   @0x2dff78 vstrmi s7, [r4, #96]
 *   @0x2dff7c vpop {d8, d9, d10, d11, d12, d13}
 *   @0x2dff80 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2dff84 vldr s6, [r4, #92]
 *   @0x2dff88 vldr s7, [r4, #96]
 *   @0x2dff8c b 0x2dfed8 <_ZN20b2SeparationFunction10InitializeEPK14b2SimplexCachePK15b2DistanceProxyRK7b2SweepS5_S8_f+0x1e4>
 *   @0x2dff90 mov r3, #2
 *   @0x2dff94 str r3, [r4, #0x50]
 *   @0x2dff98 ldrb r2, [r7, #0x9]
 *   @0x2dff9c ldrb r1, [r7, #0xa]
 *   @0x2dffa0 ldr r3, [r9, #0x10]
 *   @0x2dffa4 add r2, r3, r2, lsl #3
 *   @0x2dffa8 add r3, r3, r1, lsl #3
 *   @0x2dffac vldr s26, [r2]
 *   @0x2dffb0 vldr s27, [r3]
 *   @0x2dffb4 vsub.f32 s15, s27, s26
 *   @0x2dffb8 vldr s24, [r2, #4]
 *   @0x2dffbc vldr s25, [r3, #4]
 *   @0x2dffc0 vneg.f32 s15, s15
 *   @0x2dffc4 vmul.f32 s14, s15, s15
 *   @0x2dffc8 vstr s15, [r4, #96]
 *   @0x2dffcc vsub.f32 s15, s25, s24
 *   @0x2dffd0 vmla.f32 s14, s15, s15
 *   @0x2dffd4 vstr s15, [r4, #92]
 *   @0x2dffd8 vsqrt.f32 s15, s14
 *   @0x2dffdc vcmp.f32 s15, s15
 *   @0x2dffe0 vmrs APSR_nzcv, fpscr
 *   @0x2dffe4 bne 0x2e01a4 <_ZN20b2SeparationFunction10InitializeEPK14b2SimplexCachePK15b2DistanceProxyRK7b2SweepS5_S8_f+0x4b0>
 *   @0x2dffe8 vldr s14, [pc, #468]
 *   @0x2dffec vcmpe.f32 s15, s14
 *   @0x2dfff0 vmrs APSR_nzcv, fpscr
 *   @0x2dfff4 bmi 0x2e00c8 <_ZN20b2SeparationFunction10InitializeEPK14b2SimplexCachePK15b2DistanceProxyRK7b2SweepS5_S8_f+0x3d4>
 *   @0x2dfff8 vmov.f32 s13, #1.000000e+00
 *   @0x2dfffc vldr s7, [r4, #92]
 *   @0x2e0000 vldr s14, [r4, #96]
 *   @0x2e0004 vdiv.f32 s15, s13, s15
 *   @0x2e0008 vmul.f32 s7, s15, s7
 *   @0x2e000c vmul.f32 s15, s15, s14
 *   @0x2e0010 vstr s7, [r4, #92]
 *   @0x2e0014 vmov.f32 s9, s15
 *   @0x2e0018 vstr s15, [r4, #96]
 *   @0x2e001c ldr r3, [r8, #0x10]
 *   @0x2e0020 vmov.f32 s15, #5.000000e-01
 *   @0x2e0024 vadd.f32 s14, s27, s26
 *   @0x2e0028 vadd.f32 s10, s25, s24
 *   @0x2e002c vmul.f32 s14, s14, s15
 *   @0x2e0030 vmul.f32 s10, s10, s15
 *   @0x2e0034 vstr s14, [r4, #84]
 *   @0x2e0038 vstr s10, [r4, #88]
 *   @0x2e003c ldrb r2, [r7, #0x6]
 *   @0x2e0040 vmul.f32 s12, s10, s20
 *   @0x2e0044 add r3, r3, r2, lsl #3
 *   @0x2e0048 vldr s13, [r3, #4]
 *   @0x2e004c vldr s8, [r3]
 *   @0x2e0050 vmul.f32 s15, s13, s18
 *   @0x2e0054 vmla.f32 s12, s14, s21
 *   @0x2e0058 vmul.f32 s10, s10, s21
 *   @0x2e005c vmul.f32 s13, s13, s19
 *   @0x2e0060 vmla.f32 s15, s8, s19
 *   @0x2e0064 vmul.f32 s11, s9, s20
 *   @0x2e0068 vnmls.f32 s13, s8, s18
 *   @0x2e006c vnmls.f32 s10, s14, s20
 *   @0x2e0070 vmla.f32 s11, s7, s21
 *   @0x2e0074 vmul.f32 s21, s9, s21
 *   @0x2e0078 vadd.f32 s15, s15, s23
 *   @0x2e007c vadd.f32 s16, s12, s16
 *   @0x2e0080 vsub.f32 s16, s15, s16
 *   @0x2e0084 vnmls.f32 s21, s7, s20
 *   @0x2e0088 vadd.f32 s13, s13, s22
 *   @0x2e008c vadd.f32 s10, s10, s17
 *   @0x2e0090 vmul.f32 s16, s11, s16
 *   @0x2e0094 vsub.f32 s13, s13, s10
 *   @0x2e0098 vmla.f32 s16, s21, s13
 *   @0x2e009c vcmpe.f32 s16, #0
 *   @0x2e00a0 vmrs APSR_nzcv, fpscr
 *   @0x2e00a4 vmovpl r0, s16
 *   @0x2e00a8 bpl 0x2dff7c <_ZN20b2SeparationFunction10InitializeEPK14b2SimplexCachePK15b2DistanceProxyRK7b2SweepS5_S8_f+0x288>
 *   @0x2e00ac vneg.f32 s7, s7
 *   @0x2e00b0 vneg.f32 s9, s9
 *   @0x2e00b4 vstr s7, [r4, #92]
 *   @0x2e00b8 vneg.f32 s16, s16
 *   @0x2e00bc vstr s9, [r4, #96]
 *   @0x2e00c0 vmov r0, s16
 *   @0x2e00c4 b 0x2dff7c <_ZN20b2SeparationFunction10InitializeEPK14b2SimplexCachePK15b2DistanceProxyRK7b2SweepS5_S8_f+0x288>
 *   @0x2e00c8 vldr s7, [r4, #92]
 *   @0x2e00cc vldr s9, [r4, #96]
 *   @0x2e00d0 b 0x2e001c <_ZN20b2SeparationFunction10InitializeEPK14b2SimplexCachePK15b2DistanceProxyRK7b2SweepS5_S8_f+0x328>
 *   @0x2e00d4 mov r3, #0
 *   @0x2e00d8 str r3, [r4, #0x50]
 *   @0x2e00dc ldrb r0, [r7, #0x6]
 *   @0x2e00e0 ldrb r1, [r7, #0x9]
 *   @0x2e00e4 ldr r2, [r8, #0x10]
 *   @0x2e00e8 ldr r3, [r9, #0x10]
 *   @0x2e00ec add r2, r2, r0, lsl #3
 *   @0x2e00f0 vldr s13, [r2, #4]
 *   @0x2e00f4 add r3, r3, r1, lsl #3
 *   @0x2e00f8 vmul.f32 s15, s13, s18
 *   @0x2e00fc vldr s11, [r3, #4]
 *   @0x2e0100 vldr s10, [r2]
 *   @0x2e0104 vldr s14, [r3]
 *   @0x2e0108 vmul.f32 s12, s11, s20
 *   @0x2e010c vmla.f32 s15, s10, s19
 *   @0x2e0110 vmul.f32 s13, s13, s19
 *   @0x2e0114 vmul.f32 s11, s11, s21
 *   @0x2e0118 vmla.f32 s12, s14, s21
 *   @0x2e011c vnmls.f32 s13, s10, s18
 *   @0x2e0120 vnmls.f32 s11, s14, s20
 *   @0x2e0124 vadd.f32 s23, s15, s23
 *   @0x2e0128 vadd.f32 s16, s12, s16
 *   @0x2e012c vsub.f32 s16, s16, s23
 *   @0x2e0130 vadd.f32 s22, s13, s22
 *   @0x2e0134 vstr s16, [r4, #96]
 *   @0x2e0138 vadd.f32 s17, s11, s17
 *   @0x2e013c vmul.f32 s16, s16, s16
 *   @0x2e0140 vsub.f32 s17, s17, s22
 *   @0x2e0144 vmla.f32 s16, s17, s17
 *   @0x2e0148 vstr s17, [r4, #92]
 *   @0x2e014c vsqrt.f32 s15, s16
 *   @0x2e0150 vcmp.f32 s15, s15
 *   @0x2e0154 vmrs APSR_nzcv, fpscr
 *   @0x2e0158 bne 0x2e01b4 <_ZN20b2SeparationFunction10InitializeEPK14b2SimplexCachePK15b2DistanceProxyRK7b2SweepS5_S8_f+0x4c0>
 *   @0x2e015c vldr s14, [pc, #96]
 *   @0x2e0160 vcmpe.f32 s15, s14
 *   @0x2e0164 vmrs APSR_nzcv, fpscr
 *   @0x2e0168 vmovpl.f32 s12, #1.000000e+00
 *   @0x2e016c vmovpl r0, s15
 *   @0x2e0170 vldrpl s14, [r4, #92]
 *   @0x2e0174 vldrpl s13, [r4, #96]
 *   @0x2e0178 movmi r0, #0
 *   @0x2e017c vdivpl.f32 s15, s12, s15
 *   @0x2e0180 vmulpl.f32 s14, s14, s15
 *   @0x2e0184 vmulpl.f32 s15, s13, s15
 *   @0x2e0188 vstrpl s14, [r4, #92]
 *   @0x2e018c vstrpl s15, [r4, #96]
 *   @0x2e0190 b 0x2dff7c <_ZN20b2SeparationFunction10InitializeEPK14b2SimplexCachePK15b2DistanceProxyRK7b2SweepS5_S8_f+0x288>
 *   @0x2e0194 vmov r0, s12
 *   @0x2e0198 bl 0xb6700 <sqrtf@plt>
 *   @0x2e019c vmov s11, r0
 *   @0x2e01a0 b 0x2dfea4 <_ZN20b2SeparationFunction10InitializeEPK14b2SimplexCachePK15b2DistanceProxyRK7b2SweepS5_S8_f+0x1b0>
 *   @0x2e01a4 vmov r0, s14
 *   @0x2e01a8 bl 0xb6700 <sqrtf@plt>
 *   @0x2e01ac vmov s15, r0
 *   @0x2e01b0 b 0x2dffe8 <_ZN20b2SeparationFunction10InitializeEPK14b2SimplexCachePK15b2DistanceProxyRK7b2SweepS5_S8_f+0x2f4>
 *   @0x2e01b4 vmov r0, s16
 *   @0x2e01b8 bl 0xb6700 <sqrtf@plt>
 *   @0x2e01bc vmov s15, r0
 *   @0x2e01c0 b 0x2e015c <_ZN20b2SeparationFunction10InitializeEPK14b2SimplexCachePK15b2DistanceProxyRK7b2SweepS5_S8_f+0x468>
 *   @0x2e01c4 strlo r0, [r0], #-0
 *
 * ══ §7/25 Debug_ExecuteBreakCondition  0x29b6a8  size 1232  308 条（0x29b6a8..0x29bb78）
 * @func 0x29b6a8 0x29bb78  size 1232  308 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x29b6d4→0x47f298, 0x29b72c→0x3eb8a8, 0x29b9bc→0x757e50
 * 调用序列: YYGetUint32(RValue const*, int)×11 / MemoryManager::Free(void const*)×5 / ReadString(Buffer_Standard*)×4 / operator new[](unsigned int) / YYGetInt32(RValue const*, int) / New_Code_Variable_Find(char const*, EVariableType) / Code_Function_Find(char const*, int*) / ExecuteDebugScript(char*, VMBuffer*, RValue*)
 * 字段偏移 top8: 0xc×12 / 0x-50×7 / 0x-54×5 / 0x-5c×4 / 0x-34×4 / 0x-60×3 / 0x-68×3 / 0x-6c×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29b6a8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x29b6ac add r11, sp, #32
 *   @0x29b6b0 ldr r3, [pc, #0x4ac]
 *   @0x29b6b4 sub sp, sp, #84
 *   @0x29b6b8 ldr r2, [pc, #0x4a8]
 *   @0x29b6bc add r3, pc, r3
 *   @0x29b6c0 str r3, [r11, #-0x5c]
 *   @0x29b6c4 ldr r12, [r11, #-0x5c]
 *   @0x29b6c8 mov r4, r1
 *   @0x29b6cc str r0, [r11, #-0x60]
 *   @0x29b6d0 mov r0, r1
 *   @0x29b6d4 ldr r3, [pc, #0x490]
 *   @0x29b6d8 add r5, r1, #44
 *   @0x29b6dc ldr r2, [r12, r2]
 *   @0x29b6e0 str r2, [r11, #-0x64]
 *   @0x29b6e4 ldr r2, [r2]
 *   @0x29b6e8 str r2, [r11, #-0x28]
 *   @0x29b6ec ldr r3, [r12, r3]
 *   @0x29b6f0 str r3, [r11, #-0x68]
 *   @0x29b6f4 ldr r3, [r3]
 *   @0x29b6f8 str r3, [r11, #-0x6c]
 *   @0x29b6fc bl 0x29e69c <_Z10ReadStringP15Buffer_Standard>
 *   @0x29b700 ldr r3, [r4]
 *   @0x29b704 mov r2, r5
 *   @0x29b708 mov r1, #5
 *   @0x29b70c ldr r3, [r3, #0xc]
 *   @0x29b710 str r0, [r11, #-0x74]
 *   @0x29b714 mov r0, r4
 *   @0x29b718 blx r3
 *   @0x29b71c mov r1, #0
 *   @0x29b720 mov r0, r5
 *   @0x29b724 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29b728 ldr r12, [r11, #-0x5c]
 *   @0x29b72c ldr r2, [pc, #0x43c]
 *   @0x29b730 mov r3, #0
 *   @0x29b734 ldr r2, [r12, r2]
 *   @0x29b738 str r3, [r11, #-0x34]
 *   @0x29b73c str r3, [r11, #-0x30]
 *   @0x29b740 str r2, [r11, #-0x70]
 *   @0x29b744 add r2, r2, #8
 *   @0x29b748 str r3, [r11, #-0x2c]
 *   @0x29b74c str r2, [r11, #-0x44]
 *   @0x29b750 mov r7, r0
 *   @0x29b754 str r0, [r11, #-0x40]
 *   @0x29b758 bl 0x27d14c <_Znaj>
 *   @0x29b75c cmp r7, #0
 *   @0x29b760 mov r6, r0
 *   @0x29b764 str r0, [r11, #-0x34]
 *   @0x29b768 addne r7, r0, r7
 *   @0x29b76c movne r8, r0
 *   @0x29b770 beq 0x29b7a4 <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0xfc>
 *   @0x29b774 ldr r3, [r4]
 *   @0x29b778 mov r1, #1
 *   @0x29b77c mov r2, r5
 *   @0x29b780 mov r0, r4
 *   @0x29b784 ldr r3, [r3, #0xc]
 *   @0x29b788 blx r3
 *   @0x29b78c mov r0, r5
 *   @0x29b790 mov r1, #0
 *   @0x29b794 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x29b798 strb r0, [r8], #1
 *   @0x29b79c cmp r8, r7
 *   @0x29b7a0 bne 0x29b774 <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0xcc>
 *   @0x29b7a4 ldr r3, [r4]
 *   @0x29b7a8 mov r1, #5
 *   @0x29b7ac mov r2, r5
 *   @0x29b7b0 mov r0, r4
 *   @0x29b7b4 ldr r3, [r3, #0xc]
 *   @0x29b7b8 blx r3
 *   @0x29b7bc mov r0, r5
 *   @0x29b7c0 mov r1, #0
 *   @0x29b7c4 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29b7c8 cmp r0, #0
 *   @0x29b7cc str r0, [r11, #-0x58]
 *   @0x29b7d0 movne r3, #0
 *   @0x29b7d4 strne r3, [r11, #-0x54]
 *   @0x29b7d8 beq 0x29b8c4 <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x21c>
 *   @0x29b7dc mov r0, r4
 *   @0x29b7e0 bl 0x29e69c <_Z10ReadStringP15Buffer_Standard>
 *   @0x29b7e4 ldr r3, [r4]
 *   @0x29b7e8 mov r1, #5
 *   @0x29b7ec mov r2, r5
 *   @0x29b7f0 ldr r3, [r3, #0xc]
 *   @0x29b7f4 mov r8, r0
 *   @0x29b7f8 mov r0, r4
 *   @0x29b7fc blx r3
 *   @0x29b800 mov r0, r5
 *   @0x29b804 mov r1, #0
 *   @0x29b808 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29b80c cmp r0, #0
 *   @0x29b810 str r0, [r11, #-0x50]
 *   @0x29b814 movne r7, #0
 *   @0x29b818 beq 0x29b8a0 <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x1f8>
 *   @0x29b81c ldr r3, [r4]
 *   @0x29b820 mov r2, r5
 *   @0x29b824 mov r1, #5
 *   @0x29b828 mov r0, r4
 *   @0x29b82c add r7, r7, #1
 *   @0x29b830 ldr r3, [r3, #0xc]
 *   @0x29b834 blx r3
 *   @0x29b838 mov r1, #0
 *   @0x29b83c mov r0, r5
 *   @0x29b840 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29b844 ldr r3, [r4]
 *   @0x29b848 mov r2, r5
 *   @0x29b84c mov r1, #5
 *   @0x29b850 ldr r3, [r3, #0xc]
 *   @0x29b854 mov r10, r0
 *   @0x29b858 mov r0, r4
 *   @0x29b85c blx r3
 *   @0x29b860 mov r1, #0
 *   @0x29b864 mov r0, r5
 *   @0x29b868 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29b86c mov r1, r10
 *   @0x29b870 mov r9, r0
 *   @0x29b874 mov r0, r8
 *   @0x29b878 bl 0xd20c0 <_Z22New_Code_Variable_FindPKc13EVariableType>
 *   @0x29b87c add r3, r9, #4
 *   @0x29b880 ldr r12, [r11, #-0x50]
 *   @0x29b884 ldr r2, [r6, r3]
 *   @0x29b888 cmp r7, r12
 *   @0x29b88c and r2, r2, #-268435456
 *   @0x29b890 bic r0, r0, #-268435456
 *   @0x29b894 orr r2, r2, r0
 *   @0x29b898 str r2, [r6, r3]
 *   @0x29b89c bne 0x29b81c <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x174>
 *   @0x29b8a0 ldr r12, [r11, #-0x54]
 *   @0x29b8a4 mov r0, r8
 *   @0x29b8a8 add r12, r12, #1
 *   @0x29b8ac str r12, [r11, #-0x54]
 *   @0x29b8b0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x29b8b4 ldr r3, [r11, #-0x54]
 *   @0x29b8b8 ldr r12, [r11, #-0x58]
 *   @0x29b8bc cmp r3, r12
 *   @0x29b8c0 bne 0x29b7dc <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x134>
 *   @0x29b8c4 ldr r3, [r4]
 *   @0x29b8c8 mov r1, #5
 *   @0x29b8cc mov r2, r5
 *   @0x29b8d0 mov r0, r4
 *   @0x29b8d4 ldr r3, [r3, #0xc]
 *   @0x29b8d8 blx r3
 *   @0x29b8dc mov r0, r5
 *   @0x29b8e0 mov r1, #0
 *   @0x29b8e4 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29b8e8 cmp r0, #0
 *   @0x29b8ec str r0, [r11, #-0x50]
 *   @0x29b8f0 subne r12, r11, #72
 *   @0x29b8f4 strne r12, [r11, #-0x54]
 *   @0x29b8f8 movne r8, #0
 *   @0x29b8fc beq 0x29b998 <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x2f0>
 *   @0x29b900 mov r0, r4
 *   @0x29b904 bl 0x29e69c <_Z10ReadStringP15Buffer_Standard>
 *   @0x29b908 sub r1, r11, #72
 *   @0x29b90c mov r10, r0
 *   @0x29b910 bl 0xce158 <_Z18Code_Function_FindPKcPi>
 *   @0x29b914 ldr r12, [r4]
 *   @0x29b918 mov r1, #5
 *   @0x29b91c mov r2, r5
 *   @0x29b920 mov r0, r4
 *   @0x29b924 ldr r12, [r12, #0xc]
 *   @0x29b928 blx r12
 *   @0x29b92c mov r0, r5
 *   @0x29b930 mov r1, #0
 *   @0x29b934 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29b938 subs r9, r0, #0
 *   @0x29b93c movne r7, #0
 *   @0x29b940 beq 0x29b980 <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x2d8>
 *   @0x29b944 ldr r3, [r4]
 *   @0x29b948 mov r1, #5
 *   @0x29b94c mov r2, r5
 *   @0x29b950 mov r0, r4
 *   @0x29b954 add r7, r7, #1
 *   @0x29b958 ldr r3, [r3, #0xc]
 *   @0x29b95c blx r3
 *   @0x29b960 mov r0, r5
 *   @0x29b964 mov r1, #0
 *   @0x29b968 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29b96c ldr r3, [r11, #-0x48]
 *   @0x29b970 cmp r7, r9
 *   @0x29b974 add r0, r6, r0
 *   @0x29b978 str r3, [r0, #0x4]
 *   @0x29b97c bne 0x29b944 <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x29c>
 *   @0x29b980 mov r0, r10
 *   @0x29b984 add r8, r8, #1
 *   @0x29b988 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x29b98c ldr r3, [r11, #-0x50]
 *   @0x29b990 cmp r8, r3
 *   @0x29b994 bne 0x29b900 <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x258>
 *   @0x29b998 ldr r3, [r4]
 *   @0x29b99c mov r2, r5
 *   @0x29b9a0 mov r1, #5
 *   @0x29b9a4 mov r0, r4
 *   @0x29b9a8 ldr r3, [r3, #0xc]
 *   @0x29b9ac blx r3
 *   @0x29b9b0 mov r0, r5
 *   @0x29b9b4 mov r1, #0
 *   @0x29b9b8 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29b9bc ldr r2, [pc, #0x1b0]
 *   @0x29b9c0 ldr r12, [r11, #-0x5c]
 *   @0x29b9c4 ldr r2, [r12, r2]
 *   @0x29b9c8 str r2, [r11, #-0x54]
 *   @0x29b9cc lsl r3, r0, #2
 *   @0x29b9d0 cmp r0, #0
 *   @0x29b9d4 add r3, r3, #14
 *   @0x29b9d8 mov r7, r0
 *   @0x29b9dc bic r3, r3, #7
 *   @0x29b9e0 sub sp, sp, r3
 *   @0x29b9e4 str sp, [r11, #-0x50]
 *   @0x29b9e8 str sp, [r2]
 *   @0x29b9ec beq 0x29ba14 <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x36c>
 *   @0x29b9f0 ldr r12, [r11, #-0x50]
 *   @0x29b9f4 mov r8, #0
 *   @0x29b9f8 sub r9, r12, #4
 *   @0x29b9fc mov r0, r4
 *   @0x29ba00 add r8, r8, #1
 *   @0x29ba04 bl 0x29e69c <_Z10ReadStringP15Buffer_Standard>
 *   @0x29ba08 cmp r8, r7
 *   @0x29ba0c str r0, [r9, #0x4]!
 *   @0x29ba10 bne 0x29b9fc <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x354>
 *   @0x29ba14 ldr r3, [r4]
 *   @0x29ba18 mov r1, #5
 *   @0x29ba1c mov r2, r5
 *   @0x29ba20 mov r0, r4
 *   @0x29ba24 ldr r3, [r3, #0xc]
 *   @0x29ba28 blx r3
 *   @0x29ba2c mov r0, r5
 *   @0x29ba30 mov r1, #0
 *   @0x29ba34 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29ba38 subs r9, r0, #0
 *   @0x29ba3c movne r8, #0
 *   @0x29ba40 movne r10, #0
 *   @0x29ba44 movtne r8, #0xc007
 *   @0x29ba48 beq 0x29ba84 <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x3dc>
 *   @0x29ba4c ldr r3, [r4]
 *   @0x29ba50 mov r1, #5
 *   @0x29ba54 mov r2, r5
 *   @0x29ba58 mov r0, r4
 *   @0x29ba5c add r10, r10, #1
 *   @0x29ba60 ldr r3, [r3, #0xc]
 *   @0x29ba64 blx r3
 *   @0x29ba68 mov r0, r5
 *   @0x29ba6c mov r1, #0
 *   @0x29ba70 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29ba74 cmp r10, r9
 *   @0x29ba78 add r0, r6, r0
 *   @0x29ba7c str r8, [r0, #-0x4]
 *   @0x29ba80 bne 0x29ba4c <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x3a4>
 *   @0x29ba84 ldr r3, [r11, #-0x6c]
 *   @0x29ba88 sub r1, r11, #68
 *   @0x29ba8c ldr r12, [r11, #-0x68]
 *   @0x29ba90 ldr r0, [r11, #-0x74]
 *   @0x29ba94 ldr r2, [r11, #-0x60]
 *   @0x29ba98 str r3, [r12]
 *   @0x29ba9c bl 0x29a83c <_Z18ExecuteDebugScriptPcP8VMBufferP6RValue>
 *   @0x29baa0 cmp r7, #0
 *   @0x29baa4 beq 0x29bac8 <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x420>
 *   @0x29baa8 ldr r12, [r11, #-0x50]
 *   @0x29baac mov r4, #0
 *   @0x29bab0 sub r10, r12, #4
 *   @0x29bab4 add r4, r4, #1
 *   @0x29bab8 ldr r0, [r10, #0x4]!
 *   @0x29babc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x29bac0 cmp r4, r7
 *   @0x29bac4 bne 0x29bab4 <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x40c>
 *   @0x29bac8 ldr r12, [r11, #-0x70]
 *   @0x29bacc mov r4, #0
 *   @0x29bad0 ldr r0, [r11, #-0x30]
 *   @0x29bad4 add r3, r12, #8
 *   @0x29bad8 ldr r1, [r11, #-0x68]
 *   @0x29badc ldr r12, [r11, #-0x6c]
 *   @0x29bae0 cmp r0, r4
 *   @0x29bae4 str r3, [r11, #-0x44]
 *   @0x29bae8 ldr r3, [r11, #-0x54]
 *   @0x29baec str r12, [r1]
 *   @0x29baf0 str r4, [r3]
 *   @0x29baf4 beq 0x29bb00 <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x458>
 *   @0x29baf8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x29bafc str r4, [r11, #-0x30]
 *   @0x29bb00 ldr r0, [r11, #-0x2c]
 *   @0x29bb04 cmp r0, #0
 *   @0x29bb08 beq 0x29bb18 <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x470>
 *   @0x29bb0c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x29bb10 mov r3, #0
 *   @0x29bb14 str r3, [r11, #-0x2c]
 *   @0x29bb18 ldr r0, [r11, #-0x34]
 *   @0x29bb1c cmp r0, #0
 *   @0x29bb20 beq 0x29bb40 <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x498>
 *   @0x29bb24 bl 0x1aad50 <_Z11MemoryInWadPv>
 *   @0x29bb28 cmp r0, #0
 *   @0x29bb2c bne 0x29bb40 <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x498>
 *   @0x29bb30 ldr r0, [r11, #-0x34]
 *   @0x29bb34 cmp r0, #0
 *   @0x29bb38 beq 0x29bb40 <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x498>
 *   @0x29bb3c bl 0x27d1d4 <_ZdaPv>
 *   @0x29bb40 ldr r12, [r11, #-0x64]
 *   @0x29bb44 ldr r2, [r11, #-0x28]
 *   @0x29bb48 ldr r0, [r11, #-0x60]
 *   @0x29bb4c ldr r3, [r12]
 *   @0x29bb50 cmp r2, r3
 *   @0x29bb54 bne 0x29bb60 <_Z27Debug_ExecuteBreakConditionP15Buffer_Standard+0x4b8>
 *   @0x29bb58 sub sp, r11, #32
 *   @0x29bb5c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x29bb60 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x29bb64 mulseq r5, r4, r5
 *   @0x29bb68 .word 0xffffbd00
 *   @0x29bb6c .word 0xffffbf58
 *   @0x29bb70 .word 0xffffbedc
 *   @0x29bb74 .word 0xffffc118
 *
 * ══ §8/25 b2SeparationFunction::FindMinSeparation  0x2e01c8  size 1228  307 条（0x2e01c8..0x2e0694）
 * @func 0x2e01c8 0x2e0694  size 1228  307 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6580×2 / 0xb658c×2 / b2SeparationFunction::FindMinSeparation(int*, int*, float) const+0x49c / b2SeparationFunction::FindMinSeparation(int*, int*, float) const+0x4a4 / b2SeparationFunction::FindMinSeparation(int*, int*, float) const+0x4b0 / b2SeparationFunction::FindMinSeparation(int*, int*, float) const+0x4bc
 * 字段偏移 top8: 0x10×8 / 0x14×4 / 0x4×2 / 0x50×1
 * VFP 指令 201 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e01c8 push {r3, r4, r5, r6, r7, lr}
 *   @0x2e01cc vpush {d8, d9, d10, d11}
 *   @0x2e01d0 vmov.f32 s17, #1.000000e+00
 *   @0x2e01d4 vldr s18, [r0, #36]
 *   @0x2e01d8 vmov s16, r3
 *   @0x2e01dc vldr s15, [r0, #32]
 *   @0x2e01e0 mov r4, r0
 *   @0x2e01e4 mov r5, r1
 *   @0x2e01e8 mov r6, r2
 *   @0x2e01ec vmul.f32 s18, s16, s18
 *   @0x2e01f0 vsub.f32 s17, s17, s16
 *   @0x2e01f4 vmla.f32 s18, s17, s15
 *   @0x2e01f8 vmov r0, s18
 *   @0x2e01fc bl 0xb6580 <sinf@plt>
 *   @0x2e0200 vmov s19, r0
 *   @0x2e0204 vmov r0, s18
 *   @0x2e0208 bl 0xb658c <cosf@plt>
 *   @0x2e020c vldr s23, [r4, #72]
 *   @0x2e0210 vmul.f32 s23, s16, s23
 *   @0x2e0214 vldr s15, [r4, #12]
 *   @0x2e0218 vldr s21, [r4, #24]
 *   @0x2e021c vldr s22, [r4, #28]
 *   @0x2e0220 vldr s10, [r4, #68]
 *   @0x2e0224 vldr s13, [r4, #8]
 *   @0x2e0228 vldr s11, [r4, #16]
 *   @0x2e022c vldr s12, [r4, #20]
 *   @0x2e0230 vmul.f32 s21, s16, s21
 *   @0x2e0234 vmul.f32 s14, s15, s19
 *   @0x2e0238 vmov s18, r0
 *   @0x2e023c vmul.f32 s22, s16, s22
 *   @0x2e0240 vmul.f32 s15, s15, s18
 *   @0x2e0244 vmla.f32 s23, s17, s10
 *   @0x2e0248 vnmls.f32 s14, s13, s18
 *   @0x2e024c vmov r0, s23
 *   @0x2e0250 vmla.f32 s15, s13, s19
 *   @0x2e0254 vmla.f32 s21, s17, s11
 *   @0x2e0258 vmla.f32 s22, s17, s12
 *   @0x2e025c vsub.f32 s21, s21, s14
 *   @0x2e0260 vsub.f32 s22, s22, s15
 *   @0x2e0264 bl 0xb6580 <sinf@plt>
 *   @0x2e0268 vmov s20, r0
 *   @0x2e026c vmov r0, s23
 *   @0x2e0270 bl 0xb658c <cosf@plt>
 *   @0x2e0274 vldr s15, [r4, #48]
 *   @0x2e0278 vldr s12, [r4, #60]
 *   @0x2e027c vmul.f32 s13, s15, s20
 *   @0x2e0280 vldr s8, [r4, #64]
 *   @0x2e0284 vldr s11, [r4, #44]
 *   @0x2e0288 vldr s9, [r4, #52]
 *   @0x2e028c vldr s10, [r4, #56]
 *   @0x2e0290 vmul.f32 s12, s16, s12
 *   @0x2e0294 vmul.f32 s16, s16, s8
 *   @0x2e0298 vmov s14, r0
 *   @0x2e029c ldr r0, [r4, #0x50]
 *   @0x2e02a0 cmp r0, #1
 *   @0x2e02a4 vmul.f32 s15, s15, s14
 *   @0x2e02a8 vmla.f32 s12, s17, s9
 *   @0x2e02ac vnmls.f32 s13, s11, s14
 *   @0x2e02b0 vmla.f32 s15, s11, s20
 *   @0x2e02b4 vmla.f32 s16, s17, s10
 *   @0x2e02b8 vsub.f32 s7, s12, s13
 *   @0x2e02bc vsub.f32 s16, s16, s15
 *   @0x2e02c0 beq 0x2e0560 <_ZNK20b2SeparationFunction17FindMinSeparationEPiS0_f+0x398>
 *   @0x2e02c4 cmp r0, #2
 *   @0x2e02c8 beq 0x2e045c <_ZNK20b2SeparationFunction17FindMinSeparationEPiS0_f+0x294>
 *   @0x2e02cc cmp r0, #0
 *   @0x2e02d0 beq 0x2e02f0 <_ZNK20b2SeparationFunction17FindMinSeparationEPiS0_f+0x128>
 *   @0x2e02d4 vldr s22, [pc, #948]
 *   @0x2e02d8 vmov r0, s22
 *   @0x2e02dc vpop {d8, d9, d10, d11}
 *   @0x2e02e0 mvn r3, #0
 *   @0x2e02e4 str r3, [r5]
 *   @0x2e02e8 str r3, [r6]
 *   @0x2e02ec pop {r3, r4, r5, r6, r7, pc}
 *   @0x2e02f0 vldr s5, [r4, #96]
 *   @0x2e02f4 vmul.f32 s8, s5, s18
 *   @0x2e02f8 vldr s6, [r4, #92]
 *   @0x2e02fc ldr r7, [r4]
 *   @0x2e0300 ldr r3, [r7, #0x10]
 *   @0x2e0304 vldr s12, [r3, #4]
 *   @0x2e0308 ldr r2, [r7, #0x14]
 *   @0x2e030c vldr s13, [r3]
 *   @0x2e0310 cmp r2, #1
 *   @0x2e0314 vmls.f32 s8, s19, s6
 *   @0x2e0318 vmul.f32 s9, s5, s19
 *   @0x2e031c vmla.f32 s9, s6, s18
 *   @0x2e0320 vneg.f32 s10, s5
 *   @0x2e0324 vmul.f32 s12, s8, s12
 *   @0x2e0328 vmul.f32 s11, s10, s20
 *   @0x2e032c vmul.f32 s10, s10, s14
 *   @0x2e0330 vneg.f32 s15, s6
 *   @0x2e0334 vmla.f32 s12, s9, s13
 *   @0x2e0338 vmla.f32 s11, s15, s14
 *   @0x2e033c vmls.f32 s10, s20, s15
 *   @0x2e0340 ble 0x2e0664 <_ZNK20b2SeparationFunction17FindMinSeparationEPiS0_f+0x49c>
 *   @0x2e0344 add r3, r3, #8
 *   @0x2e0348 mov r1, r0
 *   @0x2e034c mov r0, #1
 *   @0x2e0350 vldr s15, [r3, #4]
 *   @0x2e0354 vldr s13, [r3]
 *   @0x2e0358 add r3, r3, #8
 *   @0x2e035c vmul.f32 s15, s8, s15
 *   @0x2e0360 vmla.f32 s15, s9, s13
 *   @0x2e0364 vcmpe.f32 s12, s15
 *   @0x2e0368 vmrs APSR_nzcv, fpscr
 *   @0x2e036c movmi r1, r0
 *   @0x2e0370 add r0, r0, #1
 *   @0x2e0374 vmovmi.f32 s12, s15
 *   @0x2e0378 cmp r0, r2
 *   @0x2e037c bne 0x2e0350 <_ZNK20b2SeparationFunction17FindMinSeparationEPiS0_f+0x188>
 *   @0x2e0380 ldr r4, [r4, #0x4]
 *   @0x2e0384 str r1, [r5]
 *   @0x2e0388 ldr r3, [r4, #0x10]
 *   @0x2e038c vldr s12, [r3, #4]
 *   @0x2e0390 vmul.f32 s12, s10, s12
 *   @0x2e0394 ldr r12, [r4, #0x14]
 *   @0x2e0398 vldr s15, [r3]
 *   @0x2e039c cmp r12, #1
 *   @0x2e03a0 vmla.f32 s12, s11, s15
 *   @0x2e03a4 ble 0x2e066c <_ZNK20b2SeparationFunction17FindMinSeparationEPiS0_f+0x4a4>
 *   @0x2e03a8 add r3, r3, #8
 *   @0x2e03ac mov r2, #0
 *   @0x2e03b0 mov r0, #1
 *   @0x2e03b4 vldr s15, [r3, #4]
 *   @0x2e03b8 vldr s13, [r3]
 *   @0x2e03bc add r3, r3, #8
 *   @0x2e03c0 vmul.f32 s15, s10, s15
 *   @0x2e03c4 vmla.f32 s15, s11, s13
 *   @0x2e03c8 vcmpe.f32 s15, s12
 *   @0x2e03cc vmrs APSR_nzcv, fpscr
 *   @0x2e03d0 movgt r2, r0
 *   @0x2e03d4 add r0, r0, #1
 *   @0x2e03d8 vmovgt.f32 s12, s15
 *   @0x2e03dc cmp r0, r12
 *   @0x2e03e0 bne 0x2e03b4 <_ZNK20b2SeparationFunction17FindMinSeparationEPiS0_f+0x1ec>
 *   @0x2e03e4 lsl r3, r2, #3
 *   @0x2e03e8 str r2, [r6]
 *   @0x2e03ec ldr r0, [r5]
 *   @0x2e03f0 ldr r2, [r7, #0x10]
 *   @0x2e03f4 ldr r1, [r4, #0x10]
 *   @0x2e03f8 add r2, r2, r0, lsl #3
 *   @0x2e03fc vldr s12, [r2, #4]
 *   @0x2e0400 add r3, r1, r3
 *   @0x2e0404 vmul.f32 s11, s12, s18
 *   @0x2e0408 vldr s13, [r3, #4]
 *   @0x2e040c vldr s9, [r2]
 *   @0x2e0410 vldr s10, [r3]
 *   @0x2e0414 vmul.f32 s15, s13, s14
 *   @0x2e0418 vmul.f32 s12, s12, s19
 *   @0x2e041c vmla.f32 s11, s9, s19
 *   @0x2e0420 vmul.f32 s13, s13, s20
 *   @0x2e0424 vmla.f32 s15, s10, s20
 *   @0x2e0428 vnmls.f32 s12, s9, s18
 *   @0x2e042c vnmls.f32 s13, s10, s14
 *   @0x2e0430 vadd.f32 s16, s15, s16
 *   @0x2e0434 vadd.f32 s22, s11, s22
 *   @0x2e0438 vsub.f32 s22, s16, s22
 *   @0x2e043c vadd.f32 s21, s12, s21
 *   @0x2e0440 vadd.f32 s13, s13, s7
 *   @0x2e0444 vmul.f32 s22, s5, s22
 *   @0x2e0448 vsub.f32 s13, s13, s21
 *   @0x2e044c vmla.f32 s22, s6, s13
 *   @0x2e0450 vmov r0, s22
 *   @0x2e0454 vpop {d8, d9, d10, d11}
 *   @0x2e0458 pop {r3, r4, r5, r6, r7, pc}
 *   @0x2e045c vldr s9, [r4, #96]
 *   @0x2e0460 vmul.f32 s8, s9, s14
 *   @0x2e0464 vldr s12, [r4, #92]
 *   @0x2e0468 vldr s15, [r4, #88]
 *   @0x2e046c vldr s6, [r4, #84]
 *   @0x2e0470 ldr r12, [r4]
 *   @0x2e0474 mvn r3, #0
 *   @0x2e0478 str r3, [r6]
 *   @0x2e047c ldr r3, [r12, #0x10]
 *   @0x2e0480 vldr s13, [r3, #4]
 *   @0x2e0484 ldr r0, [r12, #0x14]
 *   @0x2e0488 vldr s4, [r3]
 *   @0x2e048c cmp r0, #1
 *   @0x2e0490 vmla.f32 s8, s12, s20
 *   @0x2e0494 vmul.f32 s9, s9, s20
 *   @0x2e0498 vnmls.f32 s9, s12, s14
 *   @0x2e049c vneg.f32 s11, s8
 *   @0x2e04a0 vmul.f32 s10, s11, s18
 *   @0x2e04a4 vneg.f32 s5, s9
 *   @0x2e04a8 vmul.f32 s12, s15, s20
 *   @0x2e04ac vmul.f32 s11, s11, s19
 *   @0x2e04b0 vmls.f32 s10, s19, s5
 *   @0x2e04b4 vmul.f32 s15, s15, s14
 *   @0x2e04b8 vmla.f32 s11, s5, s18
 *   @0x2e04bc vnmls.f32 s12, s6, s14
 *   @0x2e04c0 vmla.f32 s15, s6, s20
 *   @0x2e04c4 vmul.f32 s13, s10, s13
 *   @0x2e04c8 vadd.f32 s12, s12, s7
 *   @0x2e04cc vmla.f32 s13, s11, s4
 *   @0x2e04d0 vadd.f32 s16, s15, s16
 *   @0x2e04d4 ble 0x2e0678 <_ZNK20b2SeparationFunction17FindMinSeparationEPiS0_f+0x4b0>
 *   @0x2e04d8 add r3, r3, #8
 *   @0x2e04dc mov r1, #0
 *   @0x2e04e0 mov r2, #1
 *   @0x2e04e4 vldr s15, [r3, #4]
 *   @0x2e04e8 vldr s14, [r3]
 *   @0x2e04ec add r3, r3, #8
 *   @0x2e04f0 vmul.f32 s15, s10, s15
 *   @0x2e04f4 vmla.f32 s15, s11, s14
 *   @0x2e04f8 vcmpe.f32 s13, s15
 *   @0x2e04fc vmrs APSR_nzcv, fpscr
 *   @0x2e0500 movmi r1, r2
 *   @0x2e0504 add r2, r2, #1
 *   @0x2e0508 vmovmi.f32 s13, s15
 *   @0x2e050c cmp r2, r0
 *   @0x2e0510 bne 0x2e04e4 <_ZNK20b2SeparationFunction17FindMinSeparationEPiS0_f+0x31c>
 *   @0x2e0514 lsl r3, r1, #3
 *   @0x2e0518 str r1, [r5]
 *   @0x2e051c ldr r2, [r12, #0x10]
 *   @0x2e0520 add r3, r2, r3
 *   @0x2e0524 vldr s14, [r3, #4]
 *   @0x2e0528 vmul.f32 s11, s14, s18
 *   @0x2e052c vldr s10, [r3]
 *   @0x2e0530 vmul.f32 s14, s14, s19
 *   @0x2e0534 vmla.f32 s11, s10, s19
 *   @0x2e0538 vnmls.f32 s14, s10, s18
 *   @0x2e053c vadd.f32 s22, s11, s22
 *   @0x2e0540 vsub.f32 s22, s22, s16
 *   @0x2e0544 vadd.f32 s21, s14, s21
 *   @0x2e0548 vmul.f32 s22, s8, s22
 *   @0x2e054c vsub.f32 s12, s21, s12
 *   @0x2e0550 vmla.f32 s22, s9, s12
 *   @0x2e0554 vmov r0, s22
 *   @0x2e0558 vpop {d8, d9, d10, d11}
 *   @0x2e055c pop {r3, r4, r5, r6, r7, pc}
 *   @0x2e0560 vldr s9, [r4, #96]
 *   @0x2e0564 vmul.f32 s8, s9, s18
 *   @0x2e0568 vldr s13, [r4, #92]
 *   @0x2e056c vldr s15, [r4, #88]
 *   @0x2e0570 vldr s6, [r4, #84]
 *   @0x2e0574 ldr r4, [r4, #0x4]
 *   @0x2e0578 mvn r3, #0
 *   @0x2e057c str r3, [r5]
 *   @0x2e0580 ldr r3, [r4, #0x10]
 *   @0x2e0584 vldr s12, [r3, #4]
 *   @0x2e0588 ldr r12, [r4, #0x14]
 *   @0x2e058c vldr s4, [r3]
 *   @0x2e0590 cmp r12, #1
 *   @0x2e0594 vmla.f32 s8, s13, s19
 *   @0x2e0598 vmul.f32 s9, s9, s19
 *   @0x2e059c vnmls.f32 s9, s13, s18
 *   @0x2e05a0 vneg.f32 s11, s8
 *   @0x2e05a4 vmul.f32 s10, s11, s14
 *   @0x2e05a8 vneg.f32 s5, s9
 *   @0x2e05ac vmul.f32 s13, s15, s19
 *   @0x2e05b0 vmul.f32 s11, s11, s20
 *   @0x2e05b4 vmls.f32 s10, s20, s5
 *   @0x2e05b8 vmul.f32 s15, s15, s18
 *   @0x2e05bc vmla.f32 s11, s5, s14
 *   @0x2e05c0 vnmls.f32 s13, s6, s18
 *   @0x2e05c4 vmla.f32 s15, s6, s19
 *   @0x2e05c8 vmul.f32 s12, s10, s12
 *   @0x2e05cc vadd.f32 s21, s13, s21
 *   @0x2e05d0 vmla.f32 s12, s11, s4
 *   @0x2e05d4 vadd.f32 s22, s15, s22
 *   @0x2e05d8 ble 0x2e0684 <_ZNK20b2SeparationFunction17FindMinSeparationEPiS0_f+0x4bc>
 *   @0x2e05dc add r3, r3, #8
 *   @0x2e05e0 mov r1, r0
 *   @0x2e05e4 mov r2, #0
 *   @0x2e05e8 vldr s15, [r3, #4]
 *   @0x2e05ec vldr s13, [r3]
 *   @0x2e05f0 add r3, r3, #8
 *   @0x2e05f4 vmul.f32 s15, s10, s15
 *   @0x2e05f8 vmla.f32 s15, s11, s13
 *   @0x2e05fc vcmpe.f32 s12, s15
 *   @0x2e0600 vmrs APSR_nzcv, fpscr
 *   @0x2e0604 movmi r2, r1
 *   @0x2e0608 add r1, r1, #1
 *   @0x2e060c vmovmi.f32 s12, s15
 *   @0x2e0610 cmp r1, r12
 *   @0x2e0614 bne 0x2e05e8 <_ZNK20b2SeparationFunction17FindMinSeparationEPiS0_f+0x420>
 *   @0x2e0618 lsl r3, r2, #3
 *   @0x2e061c str r2, [r6]
 *   @0x2e0620 ldr r2, [r4, #0x10]
 *   @0x2e0624 add r3, r2, r3
 *   @0x2e0628 vldr s11, [r3, #4]
 *   @0x2e062c vmul.f32 s15, s11, s14
 *   @0x2e0630 vldr s12, [r3]
 *   @0x2e0634 vmul.f32 s13, s11, s20
 *   @0x2e0638 vmla.f32 s15, s12, s20
 *   @0x2e063c vnmls.f32 s13, s12, s14
 *   @0x2e0640 vadd.f32 s16, s15, s16
 *   @0x2e0644 vsub.f32 s22, s16, s22
 *   @0x2e0648 vadd.f32 s13, s13, s7
 *   @0x2e064c vmul.f32 s22, s8, s22
 *   @0x2e0650 vsub.f32 s13, s13, s21
 *   @0x2e0654 vmla.f32 s22, s9, s13
 *   @0x2e0658 vmov r0, s22
 *   @0x2e065c vpop {d8, d9, d10, d11}
 *   @0x2e0660 pop {r3, r4, r5, r6, r7, pc}
 *   @0x2e0664 mov r1, r0
 *   @0x2e0668 b 0x2e0380 <_ZNK20b2SeparationFunction17FindMinSeparationEPiS0_f+0x1b8>
 *   @0x2e066c mov r3, #0
 *   @0x2e0670 mov r2, r3
 *   @0x2e0674 b 0x2e03e8 <_ZNK20b2SeparationFunction17FindMinSeparationEPiS0_f+0x220>
 *   @0x2e0678 mov r3, #0
 *   @0x2e067c mov r1, r3
 *   @0x2e0680 b 0x2e0518 <_ZNK20b2SeparationFunction17FindMinSeparationEPiS0_f+0x350>
 *   @0x2e0684 mov r3, #0
 *   @0x2e0688 mov r2, r3
 *   @0x2e068c b 0x2e061c <_ZNK20b2SeparationFunction17FindMinSeparationEPiS0_f+0x454>
 *   @0x2e0690 andeq r0, r0, r0
 *
 * ══ §9/25 b2ContactSolver::SolveTOIPositionConstraints  0x2e33d8  size 1228  307 条（0x2e33d8..0x2e38a4）
 * @func 0x2e33d8 0x2e38a4  size 1228  307 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6580×2 / 0xb658c×2 / b2ContactSolver::SolveTOIPositionConstraints(int, int)+0x4ac / b2ContactSolver::SolveTOIPositionConstraints(int, int)+0x468 / 0x541f4 / 0xb6700
 * 字段偏移 top8: 0x24×5 / 0x20×4 / 0x30×2 / 0x18×2 / 0x54×1 / 0x48×1
 * VFP 指令 224 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e33d8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2e33dc vpush {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x2e33e0 mov r6, r0
 *   @0x2e33e4 ldr r0, [r0, #0x30]
 *   @0x2e33e8 sub sp, sp, #44
 *   @0x2e33ec cmp r0, #0
 *   @0x2e33f0 str r1, [sp, #0x20]
 *   @0x2e33f4 str r2, [sp, #0x24]
 *   @0x2e33f8 ble 0x2e3884 <_ZN15b2ContactSolver27SolveTOIPositionConstraintsEii+0x4ac>
 *   @0x2e33fc ldr r12, [r6, #0x18]
 *   @0x2e3400 mov r5, #0
 *   @0x2e3404 vldr s29, [pc, #924]
 *   @0x2e3408 ldr r3, [r6, #0x24]
 *   @0x2e340c mov r2, #88
 *   @0x2e3410 mla r10, r2, r5, r3
 *   @0x2e3414 vldr s10, [r10, #52]
 *   @0x2e3418 ldr r3, [sp, #0x20]
 *   @0x2e341c vldr s7, [r10, #48]
 *   @0x2e3420 ldr r2, [sp, #0x24]
 *   @0x2e3424 vstr s7, [sp, #24]
 *   @0x2e3428 vstr s10, [sp, #20]
 *   @0x2e342c vldr s13, [r10, #56]
 *   @0x2e3430 vstr s13, [sp, #16]
 *   @0x2e3434 vldr s14, [r10, #60]
 *   @0x2e3438 vstr s14, [sp, #12]
 *   @0x2e343c ldr r8, [r10, #0x20]
 *   @0x2e3440 ldr r7, [r10, #0x24]
 *   @0x2e3444 cmp r8, r2
 *   @0x2e3448 cmpne r8, r3
 *   @0x2e344c ldr r2, [sp, #0x24]
 *   @0x2e3450 ldr r3, [sp, #0x20]
 *   @0x2e3454 vldreq s7, [r10, #64]
 *   @0x2e3458 ldr r4, [r10, #0x54]
 *   @0x2e345c vldrne s10, [pc, #836]
 *   @0x2e3460 vstreq s7, [sp, #4]
 *   @0x2e3464 vldreq s26, [r10, #40]
 *   @0x2e3468 vstrne s10, [sp, #4]
 *   @0x2e346c vmovne.f32 s26, s10
 *   @0x2e3470 add r8, r8, r8, lsl #1
 *   @0x2e3474 cmp r7, r2
 *   @0x2e3478 cmpne r7, r3
 *   @0x2e347c add r7, r7, r7, lsl #1
 *   @0x2e3480 vldrne s13, [pc, #800]
 *   @0x2e3484 vldreq s7, [r10, #44]
 *   @0x2e3488 vldreq s10, [r10, #68]
 *   @0x2e348c vstreq s7, [sp]
 *   @0x2e3490 vstreq s10, [sp, #8]
 *   @0x2e3494 vstrne s13, [sp, #8]
 *   @0x2e3498 vstrne s13, [sp]
 *   @0x2e349c cmp r4, #0
 *   @0x2e34a0 lsl r8, r8, #2
 *   @0x2e34a4 lsl r7, r7, #2
 *   @0x2e34a8 add r1, r12, r8
 *   @0x2e34ac add r2, r12, r7
 *   @0x2e34b0 vldr s24, [r1]
 *   @0x2e34b4 vldr s23, [r1, #4]
 *   @0x2e34b8 vldr s22, [r1, #8]
 *   @0x2e34bc vldr s21, [r2]
 *   @0x2e34c0 vldr s20, [r2, #4]
 *   @0x2e34c4 vldr s19, [r2, #8]
 *   @0x2e34c8 ble 0x2e3840 <_ZN15b2ContactSolver27SolveTOIPositionConstraintsEii+0x468>
 *   @0x2e34cc vldr s14, [sp]
 *   @0x2e34d0 vadd.f32 s14, s26, s14
 *   @0x2e34d4 mov r9, r10
 *   @0x2e34d8 mov r11, #0
 *   @0x2e34dc vstr s14, [sp, #28]
 *   @0x2e34e0 b 0x2e3578 <_ZN15b2ContactSolver27SolveTOIPositionConstraintsEii+0x1a0>
 *   @0x2e34e4 vldr s15, [pc, #700]
 *   @0x2e34e8 vmul.f32 s13, s11, s27
 *   @0x2e34ec vldr s7, [sp, #4]
 *   @0x2e34f0 add r11, r11, #1
 *   @0x2e34f4 add r9, r9, #8
 *   @0x2e34f8 vnmls.f32 s13, s9, s31
 *   @0x2e34fc vmul.f32 s14, s12, s27
 *   @0x2e3500 vmul.f32 s8, s7, s13
 *   @0x2e3504 vldr s7, [sp, #28]
 *   @0x2e3508 vnmls.f32 s14, s10, s31
 *   @0x2e350c vmla.f32 s7, s8, s13
 *   @0x2e3510 vmov.f32 s13, s7
 *   @0x2e3514 vldr s7, [sp, #8]
 *   @0x2e3518 vmul.f32 s8, s7, s14
 *   @0x2e351c vldr s7, [sp]
 *   @0x2e3520 vmla.f32 s13, s8, s14
 *   @0x2e3524 vcmpe.f32 s13, #0
 *   @0x2e3528 vmrs APSR_nzcv, fpscr
 *   @0x2e352c vneggt.f32 s15, s15
 *   @0x2e3530 vldrle s15, [pc, #624]
 *   @0x2e3534 vdivgt.f32 s15, s15, s13
 *   @0x2e3538 cmp r11, r4
 *   @0x2e353c vldr s13, [sp, #8]
 *   @0x2e3540 vmul.f32 s14, s15, s27
 *   @0x2e3544 vmul.f32 s15, s15, s31
 *   @0x2e3548 vmul.f32 s11, s11, s14
 *   @0x2e354c vmul.f32 s12, s12, s14
 *   @0x2e3550 vnmls.f32 s11, s9, s15
 *   @0x2e3554 vnmls.f32 s12, s10, s15
 *   @0x2e3558 vldr s10, [sp, #4]
 *   @0x2e355c vmla.f32 s19, s13, s12
 *   @0x2e3560 vmls.f32 s22, s10, s11
 *   @0x2e3564 vmls.f32 s24, s26, s14
 *   @0x2e3568 vmls.f32 s23, s26, s15
 *   @0x2e356c vmla.f32 s21, s7, s14
 *   @0x2e3570 vmla.f32 s20, s7, s15
 *   @0x2e3574 beq 0x2e3830 <_ZN15b2ContactSolver27SolveTOIPositionConstraintsEii+0x458>
 *   @0x2e3578 vmov r0, s22
 *   @0x2e357c bl 0xb6580 <sinf@plt>
 *   @0x2e3580 vmov s18, r0
 *   @0x2e3584 vmov r0, s22
 *   @0x2e3588 bl 0xb658c <cosf@plt>
 *   @0x2e358c vmov s17, r0
 *   @0x2e3590 vmov r0, s19
 *   @0x2e3594 bl 0xb6580 <sinf@plt>
 *   @0x2e3598 vmov s16, r0
 *   @0x2e359c vmov r0, s19
 *   @0x2e35a0 bl 0xb658c <cosf@plt>
 *   @0x2e35a4 vldr s7, [sp, #20]
 *   @0x2e35a8 vldr s10, [sp, #12]
 *   @0x2e35ac vmul.f32 s11, s7, s18
 *   @0x2e35b0 ldr r2, [r10, #0x48]
 *   @0x2e35b4 cmp r2, #1
 *   @0x2e35b8 vmul.f32 s12, s7, s17
 *   @0x2e35bc vldr s7, [sp, #24]
 *   @0x2e35c0 vmul.f32 s13, s10, s16
 *   @0x2e35c4 vmov s15, r0
 *   @0x2e35c8 vmul.f32 s14, s10, s15
 *   @0x2e35cc vldr s10, [sp, #16]
 *   @0x2e35d0 vnmls.f32 s11, s7, s17
 *   @0x2e35d4 vmla.f32 s12, s7, s18
 *   @0x2e35d8 vnmls.f32 s13, s10, s15
 *   @0x2e35dc vmla.f32 s14, s10, s16
 *   @0x2e35e0 vsub.f32 s11, s24, s11
 *   @0x2e35e4 vsub.f32 s12, s23, s12
 *   @0x2e35e8 vsub.f32 s13, s21, s13
 *   @0x2e35ec vsub.f32 s14, s20, s14
 *   @0x2e35f0 beq 0x2e37b4 <_ZN15b2ContactSolver27SolveTOIPositionConstraintsEii+0x3dc>
 *   @0x2e35f4 cmp r2, #2
 *   @0x2e35f8 beq 0x2e3724 <_ZN15b2ContactSolver27SolveTOIPositionConstraintsEii+0x34c>
 *   @0x2e35fc cmp r2, #0
 *   @0x2e3600 beq 0x2e3660 <_ZN15b2ContactSolver27SolveTOIPositionConstraintsEii+0x288>
 *   @0x2e3604 movw r3, #0xd70a
 *   @0x2e3608 movt r3, #0x3ba3
 *   @0x2e360c vmov.f32 s15, #7.500000e-01
 *   @0x2e3610 vmov s7, r3
 *   @0x2e3614 vadd.f32 s14, s30, s7
 *   @0x2e3618 vmul.f32 s15, s14, s15
 *   @0x2e361c vcmpe.f32 s30, s29
 *   @0x2e3620 vmrs APSR_nzcv, fpscr
 *   @0x2e3624 vcmpe.f32 s15, #0
 *   @0x2e3628 vmovle.f32 s29, s30
 *   @0x2e362c vmrs APSR_nzcv, fpscr
 *   @0x2e3630 vsub.f32 s9, s25, s24
 *   @0x2e3634 vsub.f32 s11, s28, s23
 *   @0x2e3638 vsub.f32 s10, s25, s21
 *   @0x2e363c vsub.f32 s12, s28, s20
 *   @0x2e3640 bpl 0x2e34e4 <_ZN15b2ContactSolver27SolveTOIPositionConstraintsEii+0x10c>
 *   @0x2e3644 movw r2, #0xcccd
 *   @0x2e3648 movt r2, #0xbe4c
 *   @0x2e364c vmov s7, r2
 *   @0x2e3650 vcmpe.f32 s15, s7
 *   @0x2e3654 vmrs APSR_nzcv, fpscr
 *   @0x2e3658 vldrmi s15, [pc, #332]
 *   @0x2e365c b 0x2e34e8 <_ZN15b2ContactSolver27SolveTOIPositionConstraintsEii+0x110>
 *   @0x2e3660 vldr s25, [r10, #28]
 *   @0x2e3664 vldr s10, [r10, #4]
 *   @0x2e3668 vmul.f32 s28, s17, s25
 *   @0x2e366c vldr s7, [r10, #24]
 *   @0x2e3670 vldr s8, [r10]
 *   @0x2e3674 vmul.f32 s9, s15, s10
 *   @0x2e3678 vmul.f32 s25, s18, s25
 *   @0x2e367c vmul.f32 s10, s16, s10
 *   @0x2e3680 vmla.f32 s28, s18, s7
 *   @0x2e3684 vmla.f32 s9, s16, s8
 *   @0x2e3688 vnmls.f32 s25, s17, s7
 *   @0x2e368c vnmls.f32 s10, s15, s8
 *   @0x2e3690 vadd.f32 s28, s12, s28
 *   @0x2e3694 vadd.f32 s16, s14, s9
 *   @0x2e3698 vsub.f32 s31, s16, s28
 *   @0x2e369c vadd.f32 s25, s11, s25
 *   @0x2e36a0 vadd.f32 s17, s13, s10
 *   @0x2e36a4 vmul.f32 s30, s31, s31
 *   @0x2e36a8 vsub.f32 s27, s17, s25
 *   @0x2e36ac vmla.f32 s30, s27, s27
 *   @0x2e36b0 vsqrt.f32 s15, s30
 *   @0x2e36b4 vcmp.f32 s15, s15
 *   @0x2e36b8 vmrs APSR_nzcv, fpscr
 *   @0x2e36bc bne 0x2e3894 <_ZN15b2ContactSolver27SolveTOIPositionConstraintsEii+0x4bc>
 *   @0x2e36c0 mov r2, #872415232
 *   @0x2e36c4 vmov s7, r2
 *   @0x2e36c8 vcmpe.f32 s15, s7
 *   @0x2e36cc vmrs APSR_nzcv, fpscr
 *   @0x2e36d0 bmi 0x2e36f8 <_ZN15b2ContactSolver27SolveTOIPositionConstraintsEii+0x320>
 *   @0x2e36d4 mov r2, #1065353216
 *   @0x2e36d8 vmov s7, r2
 *   @0x2e36dc vdiv.f32 s15, s7, s15
 *   @0x2e36e0 vmul.f32 s14, s31, s15
 *   @0x2e36e4 vmul.f32 s15, s27, s15
 *   @0x2e36e8 vmul.f32 s30, s31, s14
 *   @0x2e36ec vmov.f32 s31, s14
 *   @0x2e36f0 vmla.f32 s30, s27, s15
 *   @0x2e36f4 vmov.f32 s27, s15
 *   @0x2e36f8 vldr s14, [r10, #76]
 *   @0x2e36fc mov r2, #1056964608
 *   @0x2e3700 vmov s7, r2
 *   @0x2e3704 vldr s15, [r10, #80]
 *   @0x2e3708 vadd.f32 s25, s25, s17
 *   @0x2e370c vadd.f32 s28, s28, s16
 *   @0x2e3710 vsub.f32 s30, s30, s14
 *   @0x2e3714 vmul.f32 s25, s25, s7
 *   @0x2e3718 vmul.f32 s28, s28, s7
 *   @0x2e371c vsub.f32 s30, s30, s15
 *   @0x2e3720 b 0x2e3604 <_ZN15b2ContactSolver27SolveTOIPositionConstraintsEii+0x22c>
 *   @0x2e3724 vldr s10, [r10, #28]
 *   @0x2e3728 vldr s25, [r9, #4]
 *   @0x2e372c vmul.f32 s9, s15, s10
 *   @0x2e3730 vldr s8, [r9]
 *   @0x2e3734 vldr s7, [r10, #24]
 *   @0x2e3738 vldr s27, [r10, #20]
 *   @0x2e373c vldr s30, [r10, #76]
 *   @0x2e3740 vmul.f32 s28, s17, s25
 *   @0x2e3744 vmul.f32 s10, s16, s10
 *   @0x2e3748 vmla.f32 s28, s18, s8
 *   @0x2e374c vmla.f32 s9, s16, s7
 *   @0x2e3750 vmul.f32 s25, s18, s25
 *   @0x2e3754 vmul.f32 s31, s15, s27
 *   @0x2e3758 vnmls.f32 s25, s17, s8
 *   @0x2e375c vldr s8, [r10, #16]
 *   @0x2e3760 vnmls.f32 s10, s15, s7
 *   @0x2e3764 vmla.f32 s31, s16, s8
 *   @0x2e3768 vmul.f32 s27, s16, s27
 *   @0x2e376c vadd.f32 s28, s12, s28
 *   @0x2e3770 vldr s12, [r10, #80]
 *   @0x2e3774 vadd.f32 s14, s14, s9
 *   @0x2e3778 vsub.f32 s14, s28, s14
 *   @0x2e377c vnmls.f32 s27, s15, s8
 *   @0x2e3780 vadd.f32 s13, s13, s10
 *   @0x2e3784 vadd.f32 s25, s11, s25
 *   @0x2e3788 vmul.f32 s14, s31, s14
 *   @0x2e378c vsub.f32 s13, s25, s13
 *   @0x2e3790 vmla.f32 s14, s27, s13
 *   @0x2e3794 vsub.f32 s30, s14, s30
 *   @0x2e3798 vneg.f32 s27, s27
 *   @0x2e379c vsub.f32 s30, s30, s12
 *   @0x2e37a0 vneg.f32 s31, s31
 *   @0x2e37a4 b 0x2e3604 <_ZN15b2ContactSolver27SolveTOIPositionConstraintsEii+0x22c>
 *   @0x2e37a8 andeq r0, r0, r0
 *   @0x2e37ac cdplt p12, #0x4, c12, c12, c13, #0x6
 *   @0x2e37b0 bllt 0x541f4
 *   @0x2e37b4 vldr s10, [r10, #28]
 *   @0x2e37b8 vldr s25, [r9, #4]
 *   @0x2e37bc vmul.f32 s9, s17, s10
 *   @0x2e37c0 vldr s7, [r10, #24]
 *   @0x2e37c4 vldr s8, [r9]
 *   @0x2e37c8 vldr s27, [r10, #20]
 *   @0x2e37cc vldr s30, [r10, #76]
 *   @0x2e37d0 vmul.f32 s28, s15, s25
 *   @0x2e37d4 vmul.f32 s10, s18, s10
 *   @0x2e37d8 vmla.f32 s9, s18, s7
 *   @0x2e37dc vmul.f32 s25, s16, s25
 *   @0x2e37e0 vmla.f32 s28, s16, s8
 *   @0x2e37e4 vmul.f32 s31, s17, s27
 *   @0x2e37e8 vnmls.f32 s25, s15, s8
 *   @0x2e37ec vldr s15, [r10, #16]
 *   @0x2e37f0 vnmls.f32 s10, s17, s7
 *   @0x2e37f4 vmul.f32 s27, s18, s27
 *   @0x2e37f8 vmla.f32 s31, s18, s15
 *   @0x2e37fc vadd.f32 s28, s14, s28
 *   @0x2e3800 vldr s14, [r10, #80]
 *   @0x2e3804 vadd.f32 s12, s12, s9
 *   @0x2e3808 vsub.f32 s12, s28, s12
 *   @0x2e380c vnmls.f32 s27, s17, s15
 *   @0x2e3810 vadd.f32 s11, s11, s10
 *   @0x2e3814 vadd.f32 s25, s13, s25
 *   @0x2e3818 vmul.f32 s12, s31, s12
 *   @0x2e381c vsub.f32 s11, s25, s11
 *   @0x2e3820 vmla.f32 s12, s27, s11
 *   @0x2e3824 vsub.f32 s30, s12, s30
 *   @0x2e3828 vsub.f32 s30, s30, s14
 *   @0x2e382c b 0x2e3604 <_ZN15b2ContactSolver27SolveTOIPositionConstraintsEii+0x22c>
 *   @0x2e3830 ldr r12, [r6, #0x18]
 *   @0x2e3834 ldr r0, [r6, #0x30]
 *   @0x2e3838 add r1, r12, r8
 *   @0x2e383c add r2, r12, r7
 *   @0x2e3840 add r5, r5, #1
 *   @0x2e3844 vstr s24, [r1]
 *   @0x2e3848 cmp r0, r5
 *   @0x2e384c vstr s23, [r1, #4]
 *   @0x2e3850 vstr s22, [r1, #8]
 *   @0x2e3854 vstr s21, [r2]
 *   @0x2e3858 vstr s20, [r2, #4]
 *   @0x2e385c vstr s19, [r2, #8]
 *   @0x2e3860 bgt 0x2e3408 <_ZN15b2ContactSolver27SolveTOIPositionConstraintsEii+0x30>
 *   @0x2e3864 vldr s15, [pc, #-188]
 *   @0x2e3868 vcmpe.f32 s29, s15
 *   @0x2e386c vmrs APSR_nzcv, fpscr
 *   @0x2e3870 movlt r0, #0
 *   @0x2e3874 movge r0, #1
 *   @0x2e3878 add sp, sp, #44
 *   @0x2e387c vpop {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x2e3880 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2e3884 mov r0, #1
 *   @0x2e3888 add sp, sp, #44
 *   @0x2e388c vpop {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x2e3890 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2e3894 vmov r0, s30
 *   @0x2e3898 bl 0xb6700 <sqrtf@plt>
 *   @0x2e389c vmov s15, r0
 *   @0x2e38a0 b 0x2e36c0 <_ZN15b2ContactSolver27SolveTOIPositionConstraintsEii+0x2e8>
 *
 * ══ §10/25 ProcessGMLCallbacks  0x15dbe8  size 1224  306 条（0x15dbe8..0x15e0b0）
 * @func 0x15dbe8 0x15e0b0  size 1224  306 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: UNLOCK_RVALUE_MUTEX()×7 / operator delete(void*)×7 / LOCK_RVALUE_MUTEX()×6 / YYFree(void const*)×6 / DsQueueDequeue(int, RValue&)×3 / DsQueueSize(int)×2 / Mutex::Lock() / ProcessGMLCallbacks()+0x220
 * 字段偏移 top8: 0x4×13 / 0x-38×12 / 0x-60×12 / 0x8×9 / 0x-c×7 / 0x-34×4 / 0x-54×3 / 0xc×3
 * VFP 指令 10 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15dbe8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x15dbec add r11, sp, #32
 *   @0x15dbf0 ldr r1, [pc, #0x494]
 *   @0x15dbf4 sub sp, sp, #76
 *   @0x15dbf8 ldr r2, [pc, #0x490]
 *   @0x15dbfc ldr r1, [pc, r1]
 *   @0x15dc00 str r1, [r11, #-0x5c]
 *   @0x15dc04 add r2, pc, r2
 *   @0x15dc08 ldr r3, [r1]
 *   @0x15dc0c ldr r0, [r2]
 *   @0x15dc10 str r3, [r11, #-0x28]
 *   @0x15dc14 bl 0x27e084 <_ZN5Mutex4LockEv>
 *   @0x15dc18 ldr r3, [pc, #0x474]
 *   @0x15dc1c ldr r0, [pc, r3]
 *   @0x15dc20 cmn r0, #1
 *   @0x15dc24 beq 0x15de08 <_Z19ProcessGMLCallbacksv+0x220>
 *   @0x15dc28 ldr r3, [pc, #0x468]
 *   @0x15dc2c mov r7, #0
 *   @0x15dc30 ldr r1, [pc, #0x464]
 *   @0x15dc34 sub r8, r11, #56
 *   @0x15dc38 add r3, pc, r3
 *   @0x15dc3c str r3, [r11, #-0x54]
 *   @0x15dc40 ldr r3, [pc, #0x458]
 *   @0x15dc44 add r1, pc, r1
 *   @0x15dc48 str r1, [r11, #-0x50]
 *   @0x15dc4c add r3, pc, r3
 *   @0x15dc50 str r3, [r11, #-0x58]
 *   @0x15dc54 bl 0x2055c8 <_Z11DsQueueSizei>
 *   @0x15dc58 cmp r0, #0
 *   @0x15dc5c ble 0x15de08 <_Z19ProcessGMLCallbacksv+0x220>
 *   @0x15dc60 ldr r1, [r11, #-0x54]
 *   @0x15dc64 str r7, [r11, #-0x38]
 *   @0x15dc68 ldr r0, [r1]
 *   @0x15dc6c mov r1, r8
 *   @0x15dc70 bl 0x20557c <_Z14DsQueueDequeueiR6RValue>
 *   @0x15dc74 ldr r4, [r11, #-0x2c]
 *   @0x15dc78 ldr r3, [r11, #-0x38]
 *   @0x15dc7c ldr r1, [r11, #-0x34]
 *   @0x15dc80 cmp r4, #0
 *   @0x15dc84 str r3, [r11, #-0x4c]
 *   @0x15dc88 str r1, [r11, #-0x48]
 *   @0x15dc8c bne 0x15ddf4 <_Z19ProcessGMLCallbacksv+0x20c>
 *   @0x15dc90 vldr d7, [r11, #-76]
 *   @0x15dc94 vcmpe.f64 d7, #0
 *   @0x15dc98 vmrs APSR_nzcv, fpscr
 *   @0x15dc9c blt 0x15ddf4 <_Z19ProcessGMLCallbacksv+0x20c>
 *   @0x15dca0 ldr r1, [r11, #-0x54]
 *   @0x15dca4 str r4, [r11, #-0x38]
 *   @0x15dca8 ldr r0, [r1]
 *   @0x15dcac mov r1, r8
 *   @0x15dcb0 bl 0x20557c <_Z14DsQueueDequeueiR6RValue>
 *   @0x15dcb4 ldr r3, [r11, #-0x34]
 *   @0x15dcb8 ldr r2, [r11, #-0x38]
 *   @0x15dcbc vmov d7, r2, r3
 *   @0x15dcc0 vcvt.s32.f64 s15, d7
 *   @0x15dcc4 vmov r5, s15
 *   @0x15dcc8 vstr s15, [r11, #-64]
 *   @0x15dccc lsl r3, r5, #4
 *   @0x15dcd0 cmp r5, #0
 *   @0x15dcd4 add r3, r3, #8
 *   @0x15dcd8 sub sp, sp, r3
 *   @0x15dcdc add r3, sp, #8
 *   @0x15dce0 str r3, [r11, #-0x3c]
 *   @0x15dce4 addgt r9, r3, #12
 *   @0x15dce8 movgt r10, r3
 *   @0x15dcec ble 0x15ddb8 <_Z19ProcessGMLCallbacksv+0x1d0>
 *   @0x15dcf0 ldr r1, [r11, #-0x50]
 *   @0x15dcf4 str r7, [r11, #-0x38]
 *   @0x15dcf8 ldr r0, [r1]
 *   @0x15dcfc mov r1, r8
 *   @0x15dd00 bl 0x20557c <_Z14DsQueueDequeueiR6RValue>
 *   @0x15dd04 ldr r2, [r10, #0xc]
 *   @0x15dd08 bic r3, r2, #-16777216
 *   @0x15dd0c cmp r3, #1
 *   @0x15dd10 beq 0x15deb8 <_Z19ProcessGMLCallbacksv+0x2d0>
 *   @0x15dd14 cmp r3, #2
 *   @0x15dd18 bne 0x15dd3c <_Z19ProcessGMLCallbacksv+0x154>
 *   @0x15dd1c sub r2, r2, #1
 *   @0x15dd20 bic r2, r2, #-16777216
 *   @0x15dd24 bic r2, r2, #3
 *   @0x15dd28 cmp r2, #0
 *   @0x15dd2c beq 0x15df28 <_Z19ProcessGMLCallbacksv+0x340>
 *   @0x15dd30 mov r3, #5
 *   @0x15dd34 str r7, [r10, #0x8]
 *   @0x15dd38 str r3, [r10, #0xc]
 *   @0x15dd3c ldr r1, [r11, #-0x2c]
 *   @0x15dd40 ldr r2, [r11, #-0x30]
 *   @0x15dd44 bic r3, r1, #-16777216
 *   @0x15dd48 str r7, [r9, #-0xc]
 *   @0x15dd4c str r1, [r10, #0xc]
 *   @0x15dd50 str r2, [r10, #0x8]
 *   @0x15dd54 cmp r3, #14
 *   @0x15dd58 addls pc, pc, r3, lsl #2
 *   @0x15dd5c b 0x15dda4 <_Z19ProcessGMLCallbacksv+0x1bc>
 *   @0x15dd60 b 0x15de5c <_Z19ProcessGMLCallbacksv+0x274>
 *   @0x15dd64 b 0x15de44 <_Z19ProcessGMLCallbacksv+0x25c>
 *   @0x15dd68 b 0x15de6c <_Z19ProcessGMLCallbacksv+0x284>
 *   @0x15dd6c b 0x15dd9c <_Z19ProcessGMLCallbacksv+0x1b4>
 *   @0x15dd70 b 0x15dda4 <_Z19ProcessGMLCallbacksv+0x1bc>
 *   @0x15dd74 b 0x15dda4 <_Z19ProcessGMLCallbacksv+0x1bc>
 *   @0x15dd78 b 0x15de98 <_Z19ProcessGMLCallbacksv+0x2b0>
 *   @0x15dd7c b 0x15dd9c <_Z19ProcessGMLCallbacksv+0x1b4>
 *   @0x15dd80 b 0x15dda4 <_Z19ProcessGMLCallbacksv+0x1bc>
 *   @0x15dd84 b 0x15dda4 <_Z19ProcessGMLCallbacksv+0x1bc>
 *   @0x15dd88 b 0x15de30 <_Z19ProcessGMLCallbacksv+0x248>
 *   @0x15dd8c b 0x15dda4 <_Z19ProcessGMLCallbacksv+0x1bc>
 *   @0x15dd90 b 0x15dda4 <_Z19ProcessGMLCallbacksv+0x1bc>
 *   @0x15dd94 b 0x15de5c <_Z19ProcessGMLCallbacksv+0x274>
 *   @0x15dd98 b 0x15dd9c <_Z19ProcessGMLCallbacksv+0x1b4>
 *   @0x15dd9c ldr r3, [r11, #-0x38]
 *   @0x15dda0 str r3, [r9, #-0xc]
 *   @0x15dda4 add r4, r4, #1
 *   @0x15dda8 add r9, r9, #16
 *   @0x15ddac cmp r4, r5
 *   @0x15ddb0 add r10, r10, #16
 *   @0x15ddb4 bne 0x15dcf0 <_Z19ProcessGMLCallbacksv+0x108>
 *   @0x15ddb8 vldr d7, [r11, #-76]
 *   @0x15ddbc vcvt.s32.f64 s15, d7
 *   @0x15ddc0 mov r1, #0
 *   @0x15ddc4 mov r3, r5
 *   @0x15ddc8 sub r12, r11, #64
 *   @0x15ddcc str r8, [sp]
 *   @0x15ddd0 mov r2, r1
 *   @0x15ddd4 str r12, [sp, #0x4]
 *   @0x15ddd8 vmov r0, s15
 *   @0x15dddc bl 0x1e0774 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue>
 *   @0x15dde0 ldr r3, [pc, #0x2bc]
 *   @0x15dde4 ldr r3, [pc, r3]
 *   @0x15dde8 ldrb r3, [r3]
 *   @0x15ddec cmp r3, #0
 *   @0x15ddf0 bne 0x15df74 <_Z19ProcessGMLCallbacksv+0x38c>
 *   @0x15ddf4 ldr r1, [r11, #-0x58]
 *   @0x15ddf8 ldr r0, [r1]
 *   @0x15ddfc bl 0x2055c8 <_Z11DsQueueSizei>
 *   @0x15de00 cmp r0, #0
 *   @0x15de04 bgt 0x15dc60 <_Z19ProcessGMLCallbacksv+0x78>
 *   @0x15de08 ldr r3, [pc, #0x298]
 *   @0x15de0c ldr r0, [pc, r3]
 *   @0x15de10 bl 0x27e09c <_ZN5Mutex6UnlockEv>
 *   @0x15de14 ldr r1, [r11, #-0x5c]
 *   @0x15de18 ldr r2, [r11, #-0x28]
 *   @0x15de1c ldr r3, [r1]
 *   @0x15de20 cmp r2, r3
 *   @0x15de24 bne 0x15e088 <_Z19ProcessGMLCallbacksv+0x4a0>
 *   @0x15de28 sub sp, r11, #32
 *   @0x15de2c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x15de30 ldr r2, [r11, #-0x38]
 *   @0x15de34 ldr r3, [r11, #-0x34]
 *   @0x15de38 str r2, [r9, #-0xc]
 *   @0x15de3c str r3, [r9, #-0x8]
 *   @0x15de40 b 0x15dda4 <_Z19ProcessGMLCallbacksv+0x1bc>
 *   @0x15de44 ldr r3, [r11, #-0x38]
 *   @0x15de48 cmp r3, #0
 *   @0x15de4c ldrne r2, [r3, #0x4]
 *   @0x15de50 addne r2, r2, #1
 *   @0x15de54 strne r2, [r3, #0x4]
 *   @0x15de58 b 0x15dda0 <_Z19ProcessGMLCallbacksv+0x1b8>
 *   @0x15de5c ldr r2, [r11, #-0x38]
 *   @0x15de60 ldr r3, [r11, #-0x34]
 *   @0x15de64 strd r2, r3, [r9, #-12]
 *   @0x15de68 b 0x15dda4 <_Z19ProcessGMLCallbacksv+0x1bc>
 *   @0x15de6c ldr r3, [r11, #-0x38]
 *   @0x15de70 cmp r3, #0
 *   @0x15de74 str r3, [r9, #-0xc]
 *   @0x15de78 beq 0x15dda4 <_Z19ProcessGMLCallbacksv+0x1bc>
 *   @0x15de7c ldr r1, [r3, #0x8]
 *   @0x15de80 ldr r2, [r3]
 *   @0x15de84 cmp r1, #0
 *   @0x15de88 streq r10, [r3, #0x8]
 *   @0x15de8c add r2, r2, #1
 *   @0x15de90 str r2, [r3]
 *   @0x15de94 b 0x15dda4 <_Z19ProcessGMLCallbacksv+0x1bc>
 *   @0x15de98 ldr r2, [r11, #-0x38]
 *   @0x15de9c subs r3, r2, #0
 *   @0x15dea0 str r3, [r9, #-0xc]
 *   @0x15dea4 beq 0x15dda4 <_Z19ProcessGMLCallbacksv+0x1bc>
 *   @0x15dea8 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x15deac ldr r1, [r11, #-0x38]
 *   @0x15deb0 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x15deb4 b 0x15dda4 <_Z19ProcessGMLCallbacksv+0x1bc>
 *   @0x15deb8 ldr r6, [r9, #-0xc]
 *   @0x15debc cmp r6, #0
 *   @0x15dec0 beq 0x15dee0 <_Z19ProcessGMLCallbacksv+0x2f8>
 *   @0x15dec4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x15dec8 ldr r2, [r6, #0x4]
 *   @0x15decc sub r2, r2, #1
 *   @0x15ded0 str r2, [r6, #0x4]
 *   @0x15ded4 cmp r2, #0
 *   @0x15ded8 beq 0x15dee8 <_Z19ProcessGMLCallbacksv+0x300>
 *   @0x15dedc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x15dee0 str r7, [r9, #-0xc]
 *   @0x15dee4 b 0x15dd3c <_Z19ProcessGMLCallbacksv+0x154>
 *   @0x15dee8 ldr r0, [r6]
 *   @0x15deec str r2, [r11, #-0x60]
 *   @0x15def0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x15def4 ldr r2, [r11, #-0x60]
 *   @0x15def8 str r2, [r6]
 *   @0x15defc str r2, [r6, #0x8]
 *   @0x15df00 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x15df04 ldr r2, [r6, #0x4]
 *   @0x15df08 sub r2, r2, #1
 *   @0x15df0c str r2, [r6, #0x4]
 *   @0x15df10 cmp r2, #0
 *   @0x15df14 beq 0x15df34 <_Z19ProcessGMLCallbacksv+0x34c>
 *   @0x15df18 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x15df1c mov r0, r6
 *   @0x15df20 bl 0x27d1d0 <_ZdlPv>
 *   @0x15df24 b 0x15dedc <_Z19ProcessGMLCallbacksv+0x2f4>
 *   @0x15df28 mov r0, r10
 *   @0x15df2c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x15df30 b 0x15dd30 <_Z19ProcessGMLCallbacksv+0x148>
 *   @0x15df34 ldr r0, [r6]
 *   @0x15df38 str r2, [r11, #-0x60]
 *   @0x15df3c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x15df40 ldr r2, [r11, #-0x60]
 *   @0x15df44 str r2, [r6]
 *   @0x15df48 str r2, [r6, #0x8]
 *   @0x15df4c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x15df50 ldr r2, [r6, #0x4]
 *   @0x15df54 sub r2, r2, #1
 *   @0x15df58 str r2, [r6, #0x4]
 *   @0x15df5c cmp r2, #0
 *   @0x15df60 beq 0x15df90 <_Z19ProcessGMLCallbacksv+0x3a8>
 *   @0x15df64 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x15df68 mov r0, r6
 *   @0x15df6c bl 0x27d1d0 <_ZdlPv>
 *   @0x15df70 b 0x15df18 <_Z19ProcessGMLCallbacksv+0x330>
 *   @0x15df74 ldr r3, [pc, #0x130]
 *   @0x15df78 mov r1, #0
 *   @0x15df7c ldr r3, [pc, r3]
 *   @0x15df80 ldr r3, [r3]
 *   @0x15df84 ldr r0, [r3]
 *   @0x15df88 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x15df8c b 0x15ddf4 <_Z19ProcessGMLCallbacksv+0x20c>
 *   @0x15df90 ldr r0, [r6]
 *   @0x15df94 str r2, [r11, #-0x60]
 *   @0x15df98 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x15df9c ldr r2, [r11, #-0x60]
 *   @0x15dfa0 str r2, [r6]
 *   @0x15dfa4 str r2, [r6, #0x8]
 *   @0x15dfa8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x15dfac ldr r2, [r6, #0x4]
 *   @0x15dfb0 sub r2, r2, #1
 *   @0x15dfb4 str r2, [r6, #0x4]
 *   @0x15dfb8 cmp r2, #0
 *   @0x15dfbc beq 0x15dfdc <_Z19ProcessGMLCallbacksv+0x3f4>
 *   @0x15dfc0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x15dfc4 mov r0, r6
 *   @0x15dfc8 bl 0x27d1d0 <_ZdlPv>
 *   @0x15dfcc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x15dfd0 mov r0, r6
 *   @0x15dfd4 bl 0x27d1d0 <_ZdlPv>
 *   @0x15dfd8 b 0x15df18 <_Z19ProcessGMLCallbacksv+0x330>
 *   @0x15dfdc ldr r0, [r6]
 *   @0x15dfe0 str r2, [r11, #-0x60]
 *   @0x15dfe4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x15dfe8 ldr r2, [r11, #-0x60]
 *   @0x15dfec str r2, [r6]
 *   @0x15dff0 str r2, [r6, #0x8]
 *   @0x15dff4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x15dff8 ldr r2, [r6, #0x4]
 *   @0x15dffc sub r2, r2, #1
 *   @0x15e000 str r2, [r6, #0x4]
 *   @0x15e004 cmp r2, #0
 *   @0x15e008 beq 0x15e01c <_Z19ProcessGMLCallbacksv+0x434>
 *   @0x15e00c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x15e010 mov r0, r6
 *   @0x15e014 bl 0x27d1d0 <_ZdlPv>
 *   @0x15e018 b 0x15dfc0 <_Z19ProcessGMLCallbacksv+0x3d8>
 *   @0x15e01c ldr r0, [r6]
 *   @0x15e020 str r2, [r11, #-0x60]
 *   @0x15e024 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x15e028 ldr r2, [r11, #-0x60]
 *   @0x15e02c str r2, [r6]
 *   @0x15e030 str r2, [r6, #0x8]
 *   @0x15e034 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x15e038 ldr r2, [r6, #0x4]
 *   @0x15e03c sub r2, r2, #1
 *   @0x15e040 str r2, [r6, #0x4]
 *   @0x15e044 cmp r2, #0
 *   @0x15e048 beq 0x15e05c <_Z19ProcessGMLCallbacksv+0x474>
 *   @0x15e04c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x15e050 mov r0, r6
 *   @0x15e054 bl 0x27d1d0 <_ZdlPv>
 *   @0x15e058 b 0x15e00c <_Z19ProcessGMLCallbacksv+0x424>
 *   @0x15e05c ldr r0, [r6]
 *   @0x15e060 str r2, [r11, #-0x60]
 *   @0x15e064 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x15e068 ldr r2, [r11, #-0x60]
 *   @0x15e06c mov r0, r6
 *   @0x15e070 str r2, [r6]
 *   @0x15e074 str r2, [r6, #0x8]
 *   @0x15e078 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x15e07c mov r0, r6
 *   @0x15e080 bl 0x27d1d0 <_ZdlPv>
 *   @0x15e084 b 0x15e04c <_Z19ProcessGMLCallbacksv+0x464>
 *   @0x15e088 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x15e08c eoreq pc, r8, r4, asr sp
 *   @0x15e090 eorseq r6, r2, r4, ror #28
 *   @0x15e094 eoreq r4, r9, r12, lsr r7
 *   @0x15e098 eoreq r4, r9, r0, lsr #14
 *   @0x15e09c eoreq r4, r9, r4, lsl r7
 *   @0x15e0a0 eoreq r4, r9, r12, lsl #14
 *   @0x15e0a4 eoreq pc, r8, r0, lsl #27
 *   @0x15e0a8 eorseq r6, r2, r12, asr r12
 *   @0x15e0ac .word 0x0028fbf4
 *
 * ══ §11/25 JS_Global_abstractEqualityComparison  0x25a814  size 1216  304 条（0x25a814..0x25acd4）
 * @func 0x25a814 0x25acd4  size 1216  304 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JSThrowTypeError(char const*)×6 / F_JS_ToNumber(RValue&, RValue&)×4 / JS_Global_abstractEqualityComparison(RValue&, RValue&, RValue&)×4 / FREE_RValue__Pre(RValue*)×3 / F_JS_ToPrimitive(RValue&, RValue&, int)×3 / 0xb6574
 * 字段偏移 top8: 0xc×13 / 0x8×6 / 0x4×4 / 0x1d8×1 / 0x188×1 / 0x78×1 / 0x44×1 / 0x38×1
 * VFP 指令 18 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x25a814 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x25a818 mov r10, r2
 *   @0x25a81c ldr r3, [r1, #0xc]
 *   @0x25a820 mov r8, r0
 *   @0x25a824 ldr r2, [r2, #0xc]
 *   @0x25a828 sub sp, sp, #16
 *   @0x25a82c bic r3, r3, #-16777216
 *   @0x25a830 mov r9, r1
 *   @0x25a834 bic r0, r2, #-16777216
 *   @0x25a838 cmp r3, r0
 *   @0x25a83c beq 0x25a8d0 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0xbc>
 *   @0x25a840 cmp r3, #5
 *   @0x25a844 cmpeq r0, #12
 *   @0x25a848 beq 0x25a91c <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x108>
 *   @0x25a84c cmp r3, #12
 *   @0x25a850 cmpeq r0, #5
 *   @0x25a854 movne r2, #0
 *   @0x25a858 moveq r2, #1
 *   @0x25a85c beq 0x25a91c <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x108>
 *   @0x25a860 cmp r3, #0
 *   @0x25a864 cmpeq r0, #1
 *   @0x25a868 movne r12, #0
 *   @0x25a86c moveq r12, #1
 *   @0x25a870 beq 0x25a938 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x124>
 *   @0x25a874 cmp r3, #1
 *   @0x25a878 cmpeq r0, #0
 *   @0x25a87c movne r4, #0
 *   @0x25a880 moveq r4, #1
 *   @0x25a884 beq 0x25a9c0 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x1ac>
 *   @0x25a888 cmp r3, #13
 *   @0x25a88c beq 0x25abd8 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x3c4>
 *   @0x25a890 cmp r0, #13
 *   @0x25a894 beq 0x25aa30 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x21c>
 *   @0x25a898 cmp r3, #1
 *   @0x25a89c cmpls r0, #6
 *   @0x25a8a0 movne r12, #0
 *   @0x25a8a4 moveq r12, #1
 *   @0x25a8a8 beq 0x25aafc <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x2e8>
 *   @0x25a8ac cmp r0, #1
 *   @0x25a8b0 cmpls r3, #6
 *   @0x25a8b4 beq 0x25ab68 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x354>
 *   @0x25a8b8 mov r3, #0
 *   @0x25a8bc str r3, [r8]
 *   @0x25a8c0 mov r0, r3
 *   @0x25a8c4 str r3, [r8, #0x4]
 *   @0x25a8c8 add sp, sp, #16
 *   @0x25a8cc pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x25a8d0 cmp r3, #5
 *   @0x25a8d4 beq 0x25a91c <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x108>
 *   @0x25a8d8 cmp r3, #12
 *   @0x25a8dc beq 0x25a91c <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x108>
 *   @0x25a8e0 cmp r3, #0
 *   @0x25a8e4 bne 0x25a994 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x180>
 *   @0x25a8e8 vldr s14, [r1]
 *   @0x25a8ec vldr s15, [r1, #4]
 *   @0x25a8f0 vcmp.f64 d7, d7
 *   @0x25a8f4 vmrs APSR_nzcv, fpscr
 *   @0x25a8f8 bvs 0x25a8b8 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0xa4>
 *   @0x25a8fc vldr s12, [r10]
 *   @0x25a900 vldr s13, [r10, #4]
 *   @0x25a904 vcmp.f64 d6, d6
 *   @0x25a908 vmrs APSR_nzcv, fpscr
 *   @0x25a90c bvs 0x25a8b8 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0xa4>
 *   @0x25a910 vcmp.f64 d7, d6
 *   @0x25a914 vmrs APSR_nzcv, fpscr
 *   @0x25a918 bne 0x25aaa0 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x28c>
 *   @0x25a91c mov r0, #0
 *   @0x25a920 str r0, [r8]
 *   @0x25a924 mov r3, r0
 *   @0x25a928 movt r3, #0x3ff0
 *   @0x25a92c str r3, [r8, #0x4]
 *   @0x25a930 add sp, sp, #16
 *   @0x25a934 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x25a938 mov r1, r10
 *   @0x25a93c mov r0, sp
 *   @0x25a940 mov r4, #0
 *   @0x25a944 mvn r3, #-16777216
 *   @0x25a948 str r2, [sp, #0x8]
 *   @0x25a94c mov r5, #0
 *   @0x25a950 str r3, [sp, #0xc]
 *   @0x25a954 strd r4, r5, [sp]
 *   @0x25a958 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_>
 *   @0x25a95c cmp r0, #1
 *   @0x25a960 mov r4, r0
 *   @0x25a964 beq 0x25ac44 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x430>
 *   @0x25a968 cmp r4, #0
 *   @0x25a96c beq 0x25aaec <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x2d8>
 *   @0x25a970 ldr r3, [sp, #0xc]
 *   @0x25a974 sub r3, r3, #1
 *   @0x25a978 bic r3, r3, #-16777216
 *   @0x25a97c bic r3, r3, #3
 *   @0x25a980 cmp r3, #0
 *   @0x25a984 beq 0x25aa94 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x280>
 *   @0x25a988 mov r0, r4
 *   @0x25a98c add sp, sp, #16
 *   @0x25a990 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x25a994 cmp r3, #13
 *   @0x25a998 beq 0x25ab40 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x32c>
 *   @0x25a99c cmp r3, #1
 *   @0x25a9a0 beq 0x25aabc <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x2a8>
 *   @0x25a9a4 cmp r3, #6
 *   @0x25a9a8 bne 0x25a8b8 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0xa4>
 *   @0x25a9ac ldr r2, [r1]
 *   @0x25a9b0 ldr r3, [r10]
 *   @0x25a9b4 cmp r2, r3
 *   @0x25a9b8 bne 0x25a8b8 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0xa4>
 *   @0x25a9bc b 0x25a91c <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x108>
 *   @0x25a9c0 mov r0, sp
 *   @0x25a9c4 mov r4, #0
 *   @0x25a9c8 mvn r3, #-16777216
 *   @0x25a9cc str r12, [sp, #0x8]
 *   @0x25a9d0 mov r5, #0
 *   @0x25a9d4 str r3, [sp, #0xc]
 *   @0x25a9d8 strd r4, r5, [sp]
 *   @0x25a9dc bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_>
 *   @0x25a9e0 cmp r0, #1
 *   @0x25a9e4 mov r4, r0
 *   @0x25a9e8 beq 0x25aadc <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x2c8>
 *   @0x25a9ec cmp r0, #0
 *   @0x25a9f0 bne 0x25a970 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x15c>
 *   @0x25a9f4 mov r0, r8
 *   @0x25a9f8 mov r2, r10
 *   @0x25a9fc mov r1, sp
 *   @0x25aa00 bl 0x25a814 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_>
 *   @0x25aa04 ldr r3, [sp, #0xc]
 *   @0x25aa08 sub r3, r3, #1
 *   @0x25aa0c bic r3, r3, #-16777216
 *   @0x25aa10 subs r4, r0, #0
 *   @0x25aa14 bne 0x25a97c <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x168>
 *   @0x25aa18 bics r5, r3, #3
 *   @0x25aa1c bne 0x25a988 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x174>
 *   @0x25aa20 mov r0, sp
 *   @0x25aa24 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x25aa28 mov r0, r5
 *   @0x25aa2c b 0x25a930 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x11c>
 *   @0x25aa30 mov r1, r10
 *   @0x25aa34 mov r0, sp
 *   @0x25aa38 str r4, [sp, #0x8]
 *   @0x25aa3c mov r2, #0
 *   @0x25aa40 mov r3, #0
 *   @0x25aa44 strd r2, r3, [sp]
 *   @0x25aa48 mvn r3, #-16777216
 *   @0x25aa4c str r3, [sp, #0xc]
 *   @0x25aa50 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_>
 *   @0x25aa54 cmp r0, #1
 *   @0x25aa58 mov r4, r0
 *   @0x25aa5c beq 0x25ac9c <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x488>
 *   @0x25aa60 cmp r0, #0
 *   @0x25aa64 bne 0x25a970 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x15c>
 *   @0x25aa68 mov r0, r8
 *   @0x25aa6c mov r1, r9
 *   @0x25aa70 mov r2, sp
 *   @0x25aa74 bl 0x25a814 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_>
 *   @0x25aa78 ldr r3, [sp, #0xc]
 *   @0x25aa7c sub r3, r3, #1
 *   @0x25aa80 bic r3, r3, #-16777216
 *   @0x25aa84 subs r4, r0, #0
 *   @0x25aa88 bne 0x25a97c <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x168>
 *   @0x25aa8c bics r4, r3, #3
 *   @0x25aa90 bne 0x25ac3c <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x428>
 *   @0x25aa94 mov r0, sp
 *   @0x25aa98 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x25aa9c b 0x25a988 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x174>
 *   @0x25aaa0 vcmp.f64 d7, #0
 *   @0x25aaa4 vmrs APSR_nzcv, fpscr
 *   @0x25aaa8 bne 0x25a8b8 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0xa4>
 *   @0x25aaac vcmp.f64 d6, #0
 *   @0x25aab0 vmrs APSR_nzcv, fpscr
 *   @0x25aab4 bne 0x25a8b8 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0xa4>
 *   @0x25aab8 b 0x25a91c <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x108>
 *   @0x25aabc ldr r2, [r1]
 *   @0x25aac0 ldr r3, [r10]
 *   @0x25aac4 ldr r0, [r2]
 *   @0x25aac8 ldr r1, [r3]
 *   @0x25aacc bl 0xb6574 <strcmp@plt>
 *   @0x25aad0 cmp r0, #0
 *   @0x25aad4 bne 0x25a8b8 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0xa4>
 *   @0x25aad8 b 0x25a91c <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x108>
 *   @0x25aadc ldr r0, [pc, #0x1d8]
 *   @0x25aae0 add r0, pc, r0
 *   @0x25aae4 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x25aae8 b 0x25a970 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x15c>
 *   @0x25aaec mov r0, r8
 *   @0x25aaf0 mov r1, r9
 *   @0x25aaf4 mov r2, sp
 *   @0x25aaf8 b 0x25aa00 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x1ec>
 *   @0x25aafc mov r2, r4
 *   @0x25ab00 mov r1, r10
 *   @0x25ab04 mov r0, sp
 *   @0x25ab08 str r4, [sp, #0x8]
 *   @0x25ab0c mvn r3, #-16777216
 *   @0x25ab10 mov r4, #0
 *   @0x25ab14 mov r5, #0
 *   @0x25ab18 str r3, [sp, #0xc]
 *   @0x25ab1c strd r4, r5, [sp]
 *   @0x25ab20 bl 0x24cd64 <_Z16F_JS_ToPrimitiveR6RValueS0_i>
 *   @0x25ab24 cmp r0, #1
 *   @0x25ab28 mov r4, r0
 *   @0x25ab2c bne 0x25a968 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x154>
 *   @0x25ab30 ldr r0, [pc, #0x188]
 *   @0x25ab34 add r0, pc, r0
 *   @0x25ab38 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x25ab3c b 0x25a970 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x15c>
 *   @0x25ab40 ldr r6, [r1]
 *   @0x25ab44 ldr r4, [r10]
 *   @0x25ab48 ldr r7, [r1, #0x4]
 *   @0x25ab4c ldr r5, [r10, #0x4]
 *   @0x25ab50 vmov d6, r6, r7
 *   @0x25ab54 vmov d7, r4, r5
 *   @0x25ab58 vcmp.f64 d6, d7
 *   @0x25ab5c vmrs APSR_nzcv, fpscr
 *   @0x25ab60 bne 0x25a8b8 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0xa4>
 *   @0x25ab64 b 0x25a91c <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x108>
 *   @0x25ab68 mov r2, r12
 *   @0x25ab6c mov r0, sp
 *   @0x25ab70 mov r4, #0
 *   @0x25ab74 mvn r3, #-16777216
 *   @0x25ab78 str r12, [sp, #0x8]
 *   @0x25ab7c mov r5, #0
 *   @0x25ab80 str r3, [sp, #0xc]
 *   @0x25ab84 strd r4, r5, [sp]
 *   @0x25ab88 bl 0x24cd64 <_Z16F_JS_ToPrimitiveR6RValueS0_i>
 *   @0x25ab8c cmp r0, #1
 *   @0x25ab90 mov r4, r0
 *   @0x25ab94 beq 0x25ac60 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x44c>
 *   @0x25ab98 cmp r4, #0
 *   @0x25ab9c bne 0x25a970 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x15c>
 *   @0x25aba0 mov r0, r8
 *   @0x25aba4 mov r2, r10
 *   @0x25aba8 mov r1, sp
 *   @0x25abac bl 0x25a814 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_>
 *   @0x25abb0 ldr r3, [sp, #0xc]
 *   @0x25abb4 sub r3, r3, #1
 *   @0x25abb8 bic r3, r3, #-16777216
 *   @0x25abbc bic r3, r3, #3
 *   @0x25abc0 subs r5, r0, #0
 *   @0x25abc4 beq 0x25ac54 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x440>
 *   @0x25abc8 cmp r3, #0
 *   @0x25abcc movne r0, r5
 *   @0x25abd0 bne 0x25a930 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x11c>
 *   @0x25abd4 b 0x25aa20 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x20c>
 *   @0x25abd8 mov r0, sp
 *   @0x25abdc str r4, [sp, #0x8]
 *   @0x25abe0 mov r2, #0
 *   @0x25abe4 mov r3, #0
 *   @0x25abe8 mvn r12, #-16777216
 *   @0x25abec strd r2, r3, [sp]
 *   @0x25abf0 str r12, [sp, #0xc]
 *   @0x25abf4 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_>
 *   @0x25abf8 cmp r0, #1
 *   @0x25abfc mov r4, r0
 *   @0x25ac00 beq 0x25ac8c <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x478>
 *   @0x25ac04 cmp r0, #0
 *   @0x25ac08 bne 0x25a970 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x15c>
 *   @0x25ac0c mov r0, r8
 *   @0x25ac10 mov r2, r10
 *   @0x25ac14 mov r1, sp
 *   @0x25ac18 bl 0x25a814 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_>
 *   @0x25ac1c ldr r3, [sp, #0xc]
 *   @0x25ac20 sub r3, r3, #1
 *   @0x25ac24 bic r3, r3, #-16777216
 *   @0x25ac28 bic r3, r3, #3
 *   @0x25ac2c subs r4, r0, #0
 *   @0x25ac30 bne 0x25ac54 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x440>
 *   @0x25ac34 cmp r3, #0
 *   @0x25ac38 beq 0x25acac <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x498>
 *   @0x25ac3c mov r0, #0
 *   @0x25ac40 b 0x25a930 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x11c>
 *   @0x25ac44 ldr r0, [pc, #0x78]
 *   @0x25ac48 add r0, pc, r0
 *   @0x25ac4c bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x25ac50 b 0x25a970 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x15c>
 *   @0x25ac54 cmp r3, #0
 *   @0x25ac58 bne 0x25a988 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x174>
 *   @0x25ac5c b 0x25aa94 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x280>
 *   @0x25ac60 mov r1, r9
 *   @0x25ac64 mov r0, sp
 *   @0x25ac68 mov r2, #0
 *   @0x25ac6c bl 0x24cd64 <_Z16F_JS_ToPrimitiveR6RValueS0_i>
 *   @0x25ac70 cmp r0, #1
 *   @0x25ac74 mov r4, r0
 *   @0x25ac78 bne 0x25ab98 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x384>
 *   @0x25ac7c ldr r0, [pc, #0x44]
 *   @0x25ac80 add r0, pc, r0
 *   @0x25ac84 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x25ac88 b 0x25a970 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x15c>
 *   @0x25ac8c ldr r0, [pc, #0x38]
 *   @0x25ac90 add r0, pc, r0
 *   @0x25ac94 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x25ac98 b 0x25a970 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x15c>
 *   @0x25ac9c ldr r0, [pc, #0x2c]
 *   @0x25aca0 add r0, pc, r0
 *   @0x25aca4 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x25aca8 b 0x25a970 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x15c>
 *   @0x25acac mov r0, sp
 *   @0x25acb0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x25acb4 mov r0, #0
 *   @0x25acb8 b 0x25a930 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x11c>
 *   @0x25acbc andeq r12, pc, r12, ror r3
 *   @0x25acc0 andeq r12, pc, r12, asr r3
 *   @0x25acc4 ldrdeq r12, sp, [pc], -r12
 *   @0x25acc8 andeq r12, pc, r8, asr #4
 *   @0x25accc andeq r12, pc, r12, asr #3
 *   @0x25acd0 andeq r12, pc, r4, lsl #3
 *
 * ══ §12/25 ov_raw_seek  0x231618  size 1196  299 条（0x231618..0x231ac4）
 * @func 0x231618 0x231ac4  size 1196  299 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ogg_stream_packetout×4 / ov_raw_seek+0x464×3 / ogg_stream_reset_serialno×3 / ogg_stream_clear×3 / vorbis_dsp_clear×3 / vorbis_block_clear×3 / ogg_page_serialno×2 / ogg_stream_pagein×2
 * 字段偏移 top8: 0x58×10 / 0x4×6 / 0x1c×6 / 0x5c×4 / 0x18×4 / 0x60×4 / 0xc×3 / 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x231618 ldr r12, [pc, #0x4a0]
 *   @0x23161c ldr r1, [r0, #0x58]
 *   @0x231620 ldr r12, [pc, r12]
 *   @0x231624 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x231628 mov r7, r3
 *   @0x23162c ldr r3, [r12]
 *   @0x231630 sub sp, sp, #460
 *   @0x231634 cmp r1, #1
 *   @0x231638 mov r11, r0
 *   @0x23163c mov r6, r2
 *   @0x231640 str r12, [sp, #0x8]
 *   @0x231644 str r3, [sp, #0x1c4]
 *   @0x231648 ble 0x231a7c <ov_raw_seek+0x464>
 *   @0x23164c ldr r3, [r0, #0x4]
 *   @0x231650 cmp r3, #0
 *   @0x231654 beq 0x231a84 <ov_raw_seek+0x46c>
 *   @0x231658 cmp r6, #0
 *   @0x23165c sbcs r0, r7, #0
 *   @0x231660 blt 0x231a7c <ov_raw_seek+0x464>
 *   @0x231664 ldrd r2, r3, [r11, #16]
 *   @0x231668 cmp r2, r6
 *   @0x23166c sbcs r12, r3, r7
 *   @0x231670 blt 0x231a7c <ov_raw_seek+0x464>
 *   @0x231674 cmp r1, #2
 *   @0x231678 bne 0x231988 <ov_raw_seek+0x370>
 *   @0x23167c add r12, r11, #480
 *   @0x231680 str r12, [sp, #0x1c]
 *   @0x231684 add r8, r11, #120
 *   @0x231688 ldr r1, [r11, #0x5c]
 *   @0x23168c mvn r5, #0
 *   @0x231690 str r5, [r11, #0x50]
 *   @0x231694 mov r0, r8
 *   @0x231698 str r5, [r11, #0x54]
 *   @0x23169c bl 0x2352f4 <ogg_stream_reset_serialno>
 *   @0x2316a0 ldr r0, [sp, #0x1c]
 *   @0x2316a4 bl 0x22723c <vorbis_synthesis_restart>
 *   @0x2316a8 mov r0, r11
 *   @0x2316ac mov r2, r6
 *   @0x2316b0 mov r3, r7
 *   @0x2316b4 bl 0x22ffe0 <vorbis_packet_blocksize+0x364>
 *   @0x2316b8 cmp r0, #0
 *   @0x2316bc bne 0x231a8c <ov_raw_seek+0x474>
 *   @0x2316c0 add r7, sp, #88
 *   @0x2316c4 mov r10, r0
 *   @0x2316c8 ldr r1, [r11, #0x5c]
 *   @0x2316cc movw r12, #0xfe80
 *   @0x2316d0 mov r0, r7
 *   @0x2316d4 str r12, [sp, #0x18]
 *   @0x2316d8 str r10, [sp, #0xc]
 *   @0x2316dc bl 0x2341a4 <ogg_stream_init>
 *   @0x2316e0 mov r0, r7
 *   @0x2316e4 add r6, sp, #40
 *   @0x2316e8 bl 0x235294 <ogg_stream_reset>
 *   @0x2316ec ldr r12, [sp, #0x18]
 *   @0x2316f0 mov r9, r10
 *   @0x2316f4 str r5, [sp, #0x10]
 *   @0x2316f8 movt r12, #0xffff
 *   @0x2316fc str r5, [sp, #0x14]
 *   @0x231700 str r12, [sp, #0x18]
 *   @0x231704 add r12, r11, #560
 *   @0x231708 str r10, [sp, #0x20]
 *   @0x23170c str r12, [sp, #0x24]
 *   @0x231710 ldr r3, [r11, #0x58]
 *   @0x231714 cmp r3, #2
 *   @0x231718 bgt 0x231818 <ov_raw_seek+0x200>
 *   @0x23171c cmp r9, #0
 *   @0x231720 bne 0x231a34 <ov_raw_seek+0x41c>
 *   @0x231724 mvn r3, #0
 *   @0x231728 mov r0, r11
 *   @0x23172c mov r1, r6
 *   @0x231730 mvn r2, #0
 *   @0x231734 bl 0x22fd0c <vorbis_packet_blocksize+0x90>
 *   @0x231738 mov r4, r0
 *   @0x23173c mov r5, r1
 *   @0x231740 cmp r4, #0
 *   @0x231744 sbcs r3, r5, #0
 *   @0x231748 blt 0x231a54 <ov_raw_seek+0x43c>
 *   @0x23174c ldr r3, [r11, #0x58]
 *   @0x231750 cmp r3, #2
 *   @0x231754 bgt 0x23194c <ov_raw_seek+0x334>
 *   @0x231758 mov r0, r6
 *   @0x23175c bl 0x23409c <ogg_page_serialno>
 *   @0x231760 mov r12, r0
 *   @0x231764 ldr r0, [r11, #0x34]
 *   @0x231768 cmp r0, #0
 *   @0x23176c ble 0x231a44 <ov_raw_seek+0x42c>
 *   @0x231770 ldr r2, [r11, #0x40]
 *   @0x231774 ldr r3, [r2]
 *   @0x231778 cmp r3, r12
 *   @0x23177c beq 0x231a48 <ov_raw_seek+0x430>
 *   @0x231780 mov r3, #0
 *   @0x231784 add r3, r3, #1
 *   @0x231788 cmp r3, r0
 *   @0x23178c beq 0x231710 <ov_raw_seek+0xf8>
 *   @0x231790 ldr r1, [r2, #0x4]!
 *   @0x231794 cmp r1, r12
 *   @0x231798 bne 0x231784 <ov_raw_seek+0x16c>
 *   @0x23179c lsl r10, r3, #3
 *   @0x2317a0 str r3, [r11, #0x60]
 *   @0x2317a4 mov r1, r12
 *   @0x2317a8 str r12, [r11, #0x5c]
 *   @0x2317ac mov r0, r8
 *   @0x2317b0 str r12, [sp, #0x4]
 *   @0x2317b4 bl 0x2352f4 <ogg_stream_reset_serialno>
 *   @0x2317b8 ldr r12, [sp, #0x4]
 *   @0x2317bc mov r0, r7
 *   @0x2317c0 mov r1, r12
 *   @0x2317c4 bl 0x2352f4 <ogg_stream_reset_serialno>
 *   @0x2317c8 ldr r3, [r11, #0x3c]
 *   @0x2317cc mov r0, #3
 *   @0x2317d0 str r0, [r11, #0x58]
 *   @0x2317d4 ldrd r2, r3, [r3, r10]
 *   @0x2317d8 cmp r2, r4
 *   @0x2317dc sbcs r1, r3, r5
 *   @0x2317e0 movlt r10, #0
 *   @0x2317e4 movge r10, #1
 *   @0x2317e8 mov r1, r6
 *   @0x2317ec mov r0, r8
 *   @0x2317f0 bl 0x234eac <ogg_stream_pagein>
 *   @0x2317f4 mov r1, r6
 *   @0x2317f8 mov r0, r7
 *   @0x2317fc bl 0x234eac <ogg_stream_pagein>
 *   @0x231800 mov r0, r6
 *   @0x231804 bl 0x233fa0 <ogg_page_eos>
 *   @0x231808 ldr r3, [r11, #0x58]
 *   @0x23180c cmp r3, #2
 *   @0x231810 str r0, [sp, #0xc]
 *   @0x231814 ble 0x23171c <ov_raw_seek+0x104>
 *   @0x231818 add r4, sp, #56
 *   @0x23181c mov r0, r7
 *   @0x231820 mov r1, r4
 *   @0x231824 bl 0x235328 <ogg_stream_packetout>
 *   @0x231828 cmp r0, #0
 *   @0x23182c ble 0x23171c <ov_raw_seek+0x104>
 *   @0x231830 ldr r0, [r11, #0x60]
 *   @0x231834 ldr r3, [r11, #0x48]
 *   @0x231838 add r0, r3, r0, lsl #5
 *   @0x23183c ldr r1, [r0, #0x1c]
 *   @0x231840 cmp r1, #0
 *   @0x231844 beq 0x231a24 <ov_raw_seek+0x40c>
 *   @0x231848 mov r1, r4
 *   @0x23184c bl 0x22fc7c <vorbis_packet_blocksize>
 *   @0x231850 subs r4, r0, #0
 *   @0x231854 blt 0x231a68 <ov_raw_seek+0x450>
 *   @0x231858 rsbs r3, r10, #1
 *   @0x23185c ldr r12, [sp, #0xc]
 *   @0x231860 movlo r3, #0
 *   @0x231864 cmp r12, #0
 *   @0x231868 moveq r3, #0
 *   @0x23186c cmp r3, #0
 *   @0x231870 bne 0x2319e4 <ov_raw_seek+0x3cc>
 *   @0x231874 cmp r9, #0
 *   @0x231878 addne r9, r9, r4
 *   @0x23187c ldrne r12, [sp, #0x20]
 *   @0x231880 addne r12, r12, r9, asr #2
 *   @0x231884 strne r12, [sp, #0x20]
 *   @0x231888 ldr r12, [sp, #0x18]
 *   @0x23188c add r2, sp, #456
 *   @0x231890 ldrd r0, r1, [r2, r12]
 *   @0x231894 ldrd r2, r3, [sp, #16]
 *   @0x231898 cmp r1, r3
 *   @0x23189c cmpeq r0, r2
 *   @0x2318a0 beq 0x2319dc <ov_raw_seek+0x3c4>
 *   @0x2318a4 ldr r5, [r11, #0x60]
 *   @0x2318a8 ldr lr, [r11, #0x44]
 *   @0x2318ac lsl r4, r5, #4
 *   @0x2318b0 ldrd r2, r3, [lr, r4]
 *   @0x2318b4 subs r0, r0, r2
 *   @0x2318b8 sbc r1, r1, r3
 *   @0x2318bc cmp r0, #0
 *   @0x2318c0 sbcs r3, r1, #0
 *   @0x2318c4 movlt r0, #0
 *   @0x2318c8 movlt r1, #0
 *   @0x2318cc cmp r5, #0
 *   @0x2318d0 ble 0x2318f0 <ov_raw_seek+0x2d8>
 *   @0x2318d4 add r4, lr, r4
 *   @0x2318d8 ldrd r2, r3, [lr, #8]
 *   @0x2318dc add lr, lr, #16
 *   @0x2318e0 adds r0, r0, r2
 *   @0x2318e4 adc r1, r1, r3
 *   @0x2318e8 cmp lr, r4
 *   @0x2318ec bne 0x2318d8 <ov_raw_seek+0x2c0>
 *   @0x2318f0 ldr r12, [sp, #0x20]
 *   @0x2318f4 subs r0, r0, r12
 *   @0x2318f8 sbc r1, r1, r12, asr #31
 *   @0x2318fc cmp r0, #0
 *   @0x231900 sbcs r2, r1, #0
 *   @0x231904 movlt r2, #0
 *   @0x231908 movlt r3, #0
 *   @0x23190c strdlt r2, r3, [r11, #80]
 *   @0x231910 strdge r0, r1, [r11, #80]
 *   @0x231914 mov r0, r7
 *   @0x231918 bl 0x234150 <ogg_stream_clear>
 *   @0x23191c mov r0, #0
 *   @0x231920 mov r2, #0
 *   @0x231924 mov r3, #0
 *   @0x231928 strd r2, r3, [r11, #104]
 *   @0x23192c strd r2, r3, [r11, #112]
 *   @0x231930 ldr r12, [sp, #0x8]
 *   @0x231934 ldr r2, [sp, #0x1c4]
 *   @0x231938 ldr r3, [r12]
 *   @0x23193c cmp r2, r3
 *   @0x231940 bne 0x231abc <ov_raw_seek+0x4a4>
 *   @0x231944 add sp, sp, #460
 *   @0x231948 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x23194c ldr r3, [r11, #0x5c]
 *   @0x231950 mov r0, r6
 *   @0x231954 str r3, [sp, #0x4]
 *   @0x231958 bl 0x23409c <ogg_page_serialno>
 *   @0x23195c ldr r3, [sp, #0x4]
 *   @0x231960 cmp r3, r0
 *   @0x231964 beq 0x231978 <ov_raw_seek+0x360>
 *   @0x231968 mov r0, r6
 *   @0x23196c bl 0x233f90 <ogg_page_bos>
 *   @0x231970 cmp r0, #0
 *   @0x231974 bne 0x2319f4 <ov_raw_seek+0x3dc>
 *   @0x231978 ldr r3, [r11, #0x58]
 *   @0x23197c cmp r3, #2
 *   @0x231980 bgt 0x2317e8 <ov_raw_seek+0x1d0>
 *   @0x231984 b 0x231758 <ov_raw_seek+0x140>
 *   @0x231988 ldr r1, [r11, #0x60]
 *   @0x23198c ldr r0, [r11, #0x38]
 *   @0x231990 lsl r1, r1, #3
 *   @0x231994 ldrd r2, r3, [r0, r1]
 *   @0x231998 cmp r6, r2
 *   @0x23199c sbcs r12, r7, r3
 *   @0x2319a0 blt 0x2319b8 <ov_raw_seek+0x3a0>
 *   @0x2319a4 add r1, r0, r1
 *   @0x2319a8 ldrd r2, r3, [r1, #8]
 *   @0x2319ac cmp r6, r2
 *   @0x2319b0 sbcs r0, r7, r3
 *   @0x2319b4 blt 0x23167c <ov_raw_seek+0x64>
 *   @0x2319b8 add r12, r11, #480
 *   @0x2319bc str r12, [sp, #0x1c]
 *   @0x2319c0 mov r0, r12
 *   @0x2319c4 bl 0x2272ac <vorbis_dsp_clear>
 *   @0x2319c8 add r0, r11, #560
 *   @0x2319cc bl 0x227208 <vorbis_block_clear>
 *   @0x2319d0 mov r3, #2
 *   @0x2319d4 str r3, [r11, #0x58]
 *   @0x2319d8 b 0x231684 <ov_raw_seek+0x6c>
 *   @0x2319dc mov r9, r4
 *   @0x2319e0 b 0x231710 <ov_raw_seek+0xf8>
 *   @0x2319e4 mov r0, r8
 *   @0x2319e8 mov r1, #0
 *   @0x2319ec bl 0x235328 <ogg_stream_packetout>
 *   @0x2319f0 b 0x231888 <ov_raw_seek+0x270>
 *   @0x2319f4 ldr r0, [sp, #0x1c]
 *   @0x2319f8 bl 0x2272ac <vorbis_dsp_clear>
 *   @0x2319fc ldr r0, [sp, #0x24]
 *   @0x231a00 bl 0x227208 <vorbis_block_clear>
 *   @0x231a04 mov r12, #2
 *   @0x231a08 mov r0, r7
 *   @0x231a0c str r12, [r11, #0x58]
 *   @0x231a10 bl 0x234150 <ogg_stream_clear>
 *   @0x231a14 ldr r3, [r11, #0x58]
 *   @0x231a18 cmp r3, #2
 *   @0x231a1c bgt 0x2317e8 <ov_raw_seek+0x1d0>
 *   @0x231a20 b 0x231758 <ov_raw_seek+0x140>
 *   @0x231a24 mov r0, r8
 *   @0x231a28 bl 0x235328 <ogg_stream_packetout>
 *   @0x231a2c cmp r9, #0
 *   @0x231a30 beq 0x231724 <ov_raw_seek+0x10c>
 *   @0x231a34 mvn r2, #0
 *   @0x231a38 mvn r3, #0
 *   @0x231a3c strd r2, r3, [r11, #80]
 *   @0x231a40 b 0x231914 <ov_raw_seek+0x2fc>
 *   @0x231a44 beq 0x231710 <ov_raw_seek+0xf8>
 *   @0x231a48 mov r10, #0
 *   @0x231a4c mov r3, r10
 *   @0x231a50 b 0x2317a0 <ov_raw_seek+0x188>
 *   @0x231a54 mov r0, r11
 *   @0x231a58 mvn r1, #0
 *   @0x231a5c bl 0x23138c <ov_pcm_total>
 *   @0x231a60 strd r0, r1, [r11, #80]
 *   @0x231a64 b 0x231914 <ov_raw_seek+0x2fc>
 *   @0x231a68 mov r0, r8
 *   @0x231a6c mov r1, #0
 *   @0x231a70 bl 0x235328 <ogg_stream_packetout>
 *   @0x231a74 mov r4, #0
 *   @0x231a78 b 0x231888 <ov_raw_seek+0x270>
 *   @0x231a7c mvn r0, #130
 *   @0x231a80 b 0x231930 <ov_raw_seek+0x318>
 *   @0x231a84 mvn r0, #137
 *   @0x231a88 b 0x231930 <ov_raw_seek+0x318>
 *   @0x231a8c str r5, [r11, #0x50]
 *   @0x231a90 add r0, sp, #88
 *   @0x231a94 str r5, [r11, #0x54]
 *   @0x231a98 bl 0x234150 <ogg_stream_clear>
 *   @0x231a9c ldr r0, [sp, #0x1c]
 *   @0x231aa0 bl 0x2272ac <vorbis_dsp_clear>
 *   @0x231aa4 add r0, r11, #560
 *   @0x231aa8 bl 0x227208 <vorbis_block_clear>
 *   @0x231aac mov r3, #2
 *   @0x231ab0 mvn r0, #136
 *   @0x231ab4 str r3, [r11, #0x58]
 *   @0x231ab8 b 0x231930 <ov_raw_seek+0x318>
 *   @0x231abc bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x231ac0 andseq r12, r11, r0, lsr r3
 *
 * ══ §13/25 spTransformConstraint_apply  0x28f110  size 1184  296 条（0x28f110..0x28f5b0）
 * @func 0x28f110 0x28f5b0  size 1184  296 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6c70×6 / 0xb66f4×5 / spTransformConstraint_apply+0x444×2 / 0xb67e4×2 / 0xb67d8×2 / spTransformConstraint_apply+0x104 / spBone_localToWorld / spTransformConstraint_apply+0x238
 * 字段偏移 top8: 0x4×2 / 0xc×1 / 0x24×1 / 0x28×1 / 0x8×1 / 0x2×1
 * VFP 指令 215 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28f110 ldr r3, [r0, #0x4]
 *   @0x28f114 push {r4, r5, r6, r7, lr}
 *   @0x28f118 vpush {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x28f11c cmp r3, #0
 *   @0x28f120 vldr s26, [r0, #16]
 *   @0x28f124 ldr r7, [r0, #0xc]
 *   @0x28f128 sub sp, sp, #20
 *   @0x28f12c mov r5, r0
 *   @0x28f130 vldr s21, [r0, #20]
 *   @0x28f134 vldr s28, [r0, #24]
 *   @0x28f138 vldr s19, [r7, #52]
 *   @0x28f13c vldr s24, [r7, #56]
 *   @0x28f140 vldr s20, [r7, #64]
 *   @0x28f144 vldr s25, [r7, #68]
 *   @0x28f148 vldr s27, [r0, #28]
 *   @0x28f14c ble 0x28f554 <spTransformConstraint_apply+0x444>
 *   @0x28f150 mov r6, #0
 *   @0x28f154 vldr s29, [pc, #1008]
 *   @0x28f158 b 0x28f47c <spTransformConstraint_apply+0x36c>
 *   @0x28f15c movt r3, #0x40c9
 *   @0x28f160 vmov s8, r3
 *   @0x28f164 vsub.f32 s16, s16, s8
 *   @0x28f168 vmul.f32 s16, s16, s26
 *   @0x28f16c vcvt.f64.f32 d8, s16
 *   @0x28f170 vmov r0, r1, d8
 *   @0x28f174 bl 0xb67e4 <cos@plt>
 *   @0x28f178 vmov d5, r0, r1
 *   @0x28f17c vmov r0, r1, d8
 *   @0x28f180 vcvt.f32.f64 s18, d5
 *   @0x28f184 bl 0xb67d8 <sin@plt>
 *   @0x28f188 vmul.f32 s13, s18, s23
 *   @0x28f18c vmul.f32 s14, s18, s31
 *   @0x28f190 vmov d4, r0, r1
 *   @0x28f194 vcvt.f32.f64 s15, d4
 *   @0x28f198 vmul.f32 s23, s15, s23
 *   @0x28f19c vmul.f32 s31, s15, s31
 *   @0x28f1a0 vmla.f32 s13, s15, s22
 *   @0x28f1a4 vnmls.f32 s23, s18, s22
 *   @0x28f1a8 vstr s13, [r4, #64]
 *   @0x28f1ac vnmls.f32 s31, s18, s30
 *   @0x28f1b0 vstr s23, [r4, #52]
 *   @0x28f1b4 vmla.f32 s14, s15, s30
 *   @0x28f1b8 vstr s31, [r4, #56]
 *   @0x28f1bc vstr s14, [r4, #68]
 *   @0x28f1c0 vcmpe.f32 s21, #0
 *   @0x28f1c4 vmrs APSR_nzcv, fpscr
 *   @0x28f1c8 ble 0x28f214 <spTransformConstraint_apply+0x104>
 *   @0x28f1cc ldr r3, [r5]
 *   @0x28f1d0 add r12, sp, #12
 *   @0x28f1d4 mov r0, r7
 *   @0x28f1d8 ldr r1, [r3, #0x24]
 *   @0x28f1dc ldr r2, [r3, #0x28]
 *   @0x28f1e0 add r3, sp, #8
 *   @0x28f1e4 str r12, [sp]
 *   @0x28f1e8 bl 0x2859fc <spBone_localToWorld>
 *   @0x28f1ec vldr s14, [r4, #60]
 *   @0x28f1f0 vldr s15, [r4, #72]
 *   @0x28f1f4 vldr s12, [sp, #8]
 *   @0x28f1f8 vldr s13, [sp, #12]
 *   @0x28f1fc vsub.f32 s12, s12, s14
 *   @0x28f200 vsub.f32 s13, s13, s15
 *   @0x28f204 vmla.f32 s14, s12, s21
 *   @0x28f208 vmla.f32 s15, s13, s21
 *   @0x28f20c vstr s14, [r4, #60]
 *   @0x28f210 vstr s15, [r4, #72]
 *   @0x28f214 vcmpe.f32 s28, #0
 *   @0x28f218 vmrs APSR_nzcv, fpscr
 *   @0x28f21c ble 0x28f348 <spTransformConstraint_apply+0x238>
 *   @0x28f220 vldr s12, [r4, #64]
 *   @0x28f224 vmul.f32 s12, s12, s12
 *   @0x28f228 vldr s15, [r4, #52]
 *   @0x28f22c vmla.f32 s12, s15, s15
 *   @0x28f230 vcvt.f64.f32 d6, s12
 *   @0x28f234 vsqrt.f64 d7, d6
 *   @0x28f238 vcmp.f64 d7, d7
 *   @0x28f23c vmrs APSR_nzcv, fpscr
 *   @0x28f240 bne 0x28f560 <spTransformConstraint_apply+0x450>
 *   @0x28f244 vmul.f32 s10, s20, s20
 *   @0x28f248 vmla.f32 s10, s19, s19
 *   @0x28f24c vcvt.f64.f32 d5, s10
 *   @0x28f250 vsqrt.f64 d6, d5
 *   @0x28f254 vcmp.f64 d6, d6
 *   @0x28f258 vcvt.f32.f64 s16, d7
 *   @0x28f25c vmrs APSR_nzcv, fpscr
 *   @0x28f260 bne 0x28f5a0 <spTransformConstraint_apply+0x490>
 *   @0x28f264 movw r3, #0xc5ac
 *   @0x28f268 movt r3, #0x3727
 *   @0x28f26c vldr s11, [r4, #52]
 *   @0x28f270 vldr s10, [r4, #64]
 *   @0x28f274 vmov s8, r3
 *   @0x28f278 vcmpe.f32 s16, s8
 *   @0x28f27c vmrs APSR_nzcv, fpscr
 *   @0x28f280 vcvtgt.f32.f64 s12, d6
 *   @0x28f284 ldrgt r3, [r5]
 *   @0x28f288 vldrgt s15, [r3, #44]
 *   @0x28f28c vldrle s16, [pc, #700]
 *   @0x28f290 vsubgt.f32 s12, s12, s16
 *   @0x28f294 vaddgt.f32 s12, s12, s15
 *   @0x28f298 vldr s15, [r4, #56]
 *   @0x28f29c vmovgt.f32 s14, s16
 *   @0x28f2a0 vmlagt.f32 s14, s12, s28
 *   @0x28f2a4 vldr s12, [r4, #68]
 *   @0x28f2a8 vmul.f32 s12, s12, s12
 *   @0x28f2ac vmla.f32 s12, s15, s15
 *   @0x28f2b0 vcvt.f64.f32 d6, s12
 *   @0x28f2b4 vdivgt.f32 s16, s14, s16
 *   @0x28f2b8 vsqrt.f64 d7, d6
 *   @0x28f2bc vmul.f32 s11, s11, s16
 *   @0x28f2c0 vmul.f32 s16, s10, s16
 *   @0x28f2c4 vstr s11, [r4, #52]
 *   @0x28f2c8 vcmp.f64 d7, d7
 *   @0x28f2cc vstr s16, [r4, #64]
 *   @0x28f2d0 vmrs APSR_nzcv, fpscr
 *   @0x28f2d4 bne 0x28f590 <spTransformConstraint_apply+0x480>
 *   @0x28f2d8 vmul.f32 s10, s25, s25
 *   @0x28f2dc vmla.f32 s10, s24, s24
 *   @0x28f2e0 vcvt.f64.f32 d5, s10
 *   @0x28f2e4 vsqrt.f64 d6, d5
 *   @0x28f2e8 vcmp.f64 d6, d6
 *   @0x28f2ec vcvt.f32.f64 s16, d7
 *   @0x28f2f0 vmrs APSR_nzcv, fpscr
 *   @0x28f2f4 bne 0x28f580 <spTransformConstraint_apply+0x470>
 *   @0x28f2f8 movw r3, #0xc5ac
 *   @0x28f2fc movt r3, #0x3727
 *   @0x28f300 vmov s8, r3
 *   @0x28f304 vcmpe.f32 s16, s8
 *   @0x28f308 vmrs APSR_nzcv, fpscr
 *   @0x28f30c vcvtgt.f32.f64 s12, d6
 *   @0x28f310 ldrgt r3, [r5]
 *   @0x28f314 vldrgt s15, [r3, #48]
 *   @0x28f318 vldrle s16, [pc, #560]
 *   @0x28f31c vsubgt.f32 s12, s12, s16
 *   @0x28f320 vaddgt.f32 s12, s12, s15
 *   @0x28f324 vldr s15, [r4, #56]
 *   @0x28f328 vmovgt.f32 s14, s16
 *   @0x28f32c vmlagt.f32 s14, s12, s28
 *   @0x28f330 vdivgt.f32 s16, s14, s16
 *   @0x28f334 vldr s14, [r4, #68]
 *   @0x28f338 vmul.f32 s15, s15, s16
 *   @0x28f33c vmul.f32 s16, s14, s16
 *   @0x28f340 vstr s15, [r4, #56]
 *   @0x28f344 vstr s16, [r4, #68]
 *   @0x28f348 vcmpe.f32 s27, #0
 *   @0x28f34c vmrs APSR_nzcv, fpscr
 *   @0x28f350 ble 0x28f46c <spTransformConstraint_apply+0x35c>
 *   @0x28f354 vldr s17, [r4, #56]
 *   @0x28f358 vldr s18, [r4, #68]
 *   @0x28f35c vcvt.f64.f32 d5, s17
 *   @0x28f360 vcvt.f64.f32 d6, s18
 *   @0x28f364 vmov r2, r3, d5
 *   @0x28f368 vmov r0, r1, d6
 *   @0x28f36c bl 0xb6c70 <atan2@plt>
 *   @0x28f370 vcvt.f64.f32 d5, s25
 *   @0x28f374 vcvt.f64.f32 d7, s24
 *   @0x28f378 vmov r2, r3, d7
 *   @0x28f37c vmov d4, r0, r1
 *   @0x28f380 vmov r0, r1, d5
 *   @0x28f384 vcvt.f32.f64 s16, d4
 *   @0x28f388 bl 0xb6c70 <atan2@plt>
 *   @0x28f38c vcvt.f64.f32 d6, s19
 *   @0x28f390 vcvt.f64.f32 d7, s20
 *   @0x28f394 vmov r2, r3, d6
 *   @0x28f398 vmov d11, r0, r1
 *   @0x28f39c vmov r0, r1, d7
 *   @0x28f3a0 bl 0xb6c70 <atan2@plt>
 *   @0x28f3a4 vldr s14, [r4, #64]
 *   @0x28f3a8 vldr s15, [r4, #52]
 *   @0x28f3ac vcvt.f64.f32 d4, s14
 *   @0x28f3b0 vcvt.f64.f32 d5, s15
 *   @0x28f3b4 vmov r2, r3, d5
 *   @0x28f3b8 vmov d15, r0, r1
 *   @0x28f3bc vmov r0, r1, d4
 *   @0x28f3c0 bl 0xb6c70 <atan2@plt>
 *   @0x28f3c4 vmul.f32 s18, s18, s18
 *   @0x28f3c8 vmla.f32 s18, s17, s17
 *   @0x28f3cc vmov d4, r0, r1
 *   @0x28f3d0 vcvt.f64.f32 d6, s18
 *   @0x28f3d4 vsqrt.f64 d7, d6
 *   @0x28f3d8 vcvt.f32.f64 s22, d11
 *   @0x28f3dc vcvt.f32.f64 s30, d15
 *   @0x28f3e0 vcvt.f32.f64 s11, d4
 *   @0x28f3e4 vsub.f32 s22, s22, s30
 *   @0x28f3e8 vsub.f32 s11, s16, s11
 *   @0x28f3ec vcmp.f64 d7, d7
 *   @0x28f3f0 vsub.f32 s22, s22, s11
 *   @0x28f3f4 vmrs APSR_nzcv, fpscr
 *   @0x28f3f8 bne 0x28f570 <spTransformConstraint_apply+0x460>
 *   @0x28f3fc movw r3, #0xfdb
 *   @0x28f400 movt r3, #0x4049
 *   @0x28f404 vmov s8, r3
 *   @0x28f408 movw r3, #0xfdb
 *   @0x28f40c vcmpe.f32 s22, s8
 *   @0x28f410 vcvt.f32.f64 s18, d7
 *   @0x28f414 vmrs APSR_nzcv, fpscr
 *   @0x28f418 ble 0x28f528 <spTransformConstraint_apply+0x418>
 *   @0x28f41c movt r3, #0x40c9
 *   @0x28f420 vmov s8, r3
 *   @0x28f424 vsub.f32 s22, s22, s8
 *   @0x28f428 ldr r3, [r5]
 *   @0x28f42c vldr s15, [r3, #52]
 *   @0x28f430 vmla.f32 s22, s15, s29
 *   @0x28f434 vmla.f32 s16, s22, s27
 *   @0x28f438 vcvt.f64.f32 d8, s16
 *   @0x28f43c vmov r0, r1, d8
 *   @0x28f440 bl 0xb67e4 <cos@plt>
 *   @0x28f444 vmov d5, r0, r1
 *   @0x28f448 vcvt.f32.f64 s15, d5
 *   @0x28f44c vmov r0, r1, d8
 *   @0x28f450 vmul.f32 s15, s15, s18
 *   @0x28f454 vstr s15, [r4, #56]
 *   @0x28f458 bl 0xb67d8 <sin@plt>
 *   @0x28f45c vmov d6, r0, r1
 *   @0x28f460 vcvt.f32.f64 s15, d6
 *   @0x28f464 vmul.f32 s18, s15, s18
 *   @0x28f468 vstr s18, [r4, #68]
 *   @0x28f46c ldr r3, [r5, #0x4]
 *   @0x28f470 add r6, r6, #1
 *   @0x28f474 cmp r3, r6
 *   @0x28f478 ble 0x28f554 <spTransformConstraint_apply+0x444>
 *   @0x28f47c vcmpe.f32 s26, #0
 *   @0x28f480 ldr r3, [r5, #0x8]
 *   @0x28f484 ldr r4, [r3, r6, lsl #2]
 *   @0x28f488 vmrs APSR_nzcv, fpscr
 *   @0x28f48c ble 0x28f1c0 <spTransformConstraint_apply+0xb0>
 *   @0x28f490 vcvt.f64.f32 d4, s20
 *   @0x28f494 vldr s22, [r4, #52]
 *   @0x28f498 vldr s23, [r4, #64]
 *   @0x28f49c vldr s30, [r4, #56]
 *   @0x28f4a0 vldr s31, [r4, #68]
 *   @0x28f4a4 vcvt.f64.f32 d5, s19
 *   @0x28f4a8 vmov r0, r1, d4
 *   @0x28f4ac vmov r2, r3, d5
 *   @0x28f4b0 bl 0xb6c70 <atan2@plt>
 *   @0x28f4b4 vcvt.f64.f32 d7, s23
 *   @0x28f4b8 vcvt.f64.f32 d6, s22
 *   @0x28f4bc vmov r2, r3, d6
 *   @0x28f4c0 vmov d8, r0, r1
 *   @0x28f4c4 vmov r0, r1, d7
 *   @0x28f4c8 bl 0xb6c70 <atan2@plt>
 *   @0x28f4cc ldr r3, [r5]
 *   @0x28f4d0 vcvt.f32.f64 s16, d8
 *   @0x28f4d4 vldr s15, [r3, #32]
 *   @0x28f4d8 movw r3, #0xfdb
 *   @0x28f4dc movt r3, #0x4049
 *   @0x28f4e0 vmov d4, r0, r1
 *   @0x28f4e4 vcvt.f32.f64 s14, d4
 *   @0x28f4e8 vmov s8, r3
 *   @0x28f4ec movw r3, #0xfdb
 *   @0x28f4f0 vsub.f32 s16, s16, s14
 *   @0x28f4f4 vmla.f32 s16, s15, s29
 *   @0x28f4f8 vcmpe.f32 s16, s8
 *   @0x28f4fc vmrs APSR_nzcv, fpscr
 *   @0x28f500 bgt 0x28f15c <spTransformConstraint_apply+0x4c>
 *   @0x28f504 movt r3, #0xc049
 *   @0x28f508 vmov s8, r3
 *   @0x28f50c vcmpe.f32 s16, s8
 *   @0x28f510 vmrs APSR_nzcv, fpscr
 *   @0x28f514 movwmi r3, #0xfdb
 *   @0x28f518 movtmi r3, #0x40c9
 *   @0x28f51c vmovmi s8, r3
 *   @0x28f520 vaddmi.f32 s16, s16, s8
 *   @0x28f524 b 0x28f168 <spTransformConstraint_apply+0x58>
 *   @0x28f528 movt r3, #0xc049
 *   @0x28f52c vmov s8, r3
 *   @0x28f530 vcmpe.f32 s22, s8
 *   @0x28f534 vmrs APSR_nzcv, fpscr
 *   @0x28f538 movwmi r3, #0xfdb
 *   @0x28f53c movtmi r3, #0x40c9
 *   @0x28f540 vmovmi s8, r3
 *   @0x28f544 vaddmi.f32 s22, s22, s8
 *   @0x28f548 b 0x28f428 <spTransformConstraint_apply+0x318>
 *   @0x28f54c vstmialo lr, {s30, s31}
 *   @0x28f550 andeq r0, r0, r0
 *   @0x28f554 add sp, sp, #20
 *   @0x28f558 vpop {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x28f55c pop {r4, r5, r6, r7, pc}
 *   @0x28f560 vmov r0, r1, d6
 *   @0x28f564 bl 0xb66f4 <sqrt@plt>
 *   @0x28f568 vmov d7, r0, r1
 *   @0x28f56c b 0x28f244 <spTransformConstraint_apply+0x134>
 *   @0x28f570 vmov r0, r1, d6
 *   @0x28f574 bl 0xb66f4 <sqrt@plt>
 *   @0x28f578 vmov d7, r0, r1
 *   @0x28f57c b 0x28f3fc <spTransformConstraint_apply+0x2ec>
 *   @0x28f580 vmov r0, r1, d5
 *   @0x28f584 bl 0xb66f4 <sqrt@plt>
 *   @0x28f588 vmov d6, r0, r1
 *   @0x28f58c b 0x28f2f8 <spTransformConstraint_apply+0x1e8>
 *   @0x28f590 vmov r0, r1, d6
 *   @0x28f594 bl 0xb66f4 <sqrt@plt>
 *   @0x28f598 vmov d7, r0, r1
 *   @0x28f59c b 0x28f2d8 <spTransformConstraint_apply+0x1c8>
 *   @0x28f5a0 vmov r0, r1, d5
 *   @0x28f5a4 bl 0xb66f4 <sqrt@plt>
 *   @0x28f5a8 vmov d6, r0, r1
 *   @0x28f5ac b 0x28f264 <spTransformConstraint_apply+0x154>
 *
 * ══ §14/25 b2DynamicTree::InsertLeaf  0x2defd0  size 1180  295 条（0x2defd0..0x2df46c）
 * @func 0x2defd0 0x2df46c  size 1180  295 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2DynamicTree::InsertLeaf(int)+0x174 / b2DynamicTree::AllocateNode() / b2DynamicTree::Balance(int)
 * 字段偏移 top8: 0x18×9 / 0x14×8 / 0x20×5 / 0x4×4 / 0x1c×4 / 0x10×1
 * VFP 指令 189 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2defd0 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2defd4 vpush {d8, d9}
 *   @0x2defd8 mov r6, r0
 *   @0x2defdc ldr r4, [r0]
 *   @0x2defe0 mov r8, r1
 *   @0x2defe4 ldr r3, [r0, #0x18]
 *   @0x2defe8 cmn r4, #1
 *   @0x2defec add r3, r3, #1
 *   @0x2deff0 str r3, [r0, #0x18]
 *   @0x2deff4 beq 0x2df450 <_ZN13b2DynamicTree10InsertLeafEi+0x480>
 *   @0x2deff8 lsl r7, r4, #3
 *   @0x2deffc ldr r5, [r0, #0x4]
 *   @0x2df000 add r2, r7, r4
 *   @0x2df004 add r9, r1, r1, lsl #3
 *   @0x2df008 add r2, r5, r2, lsl #2
 *   @0x2df00c lsl r9, r9, #2
 *   @0x2df010 add r3, r5, r9
 *   @0x2df014 vldr s16, [r3]
 *   @0x2df018 ldr r12, [r2, #0x18]
 *   @0x2df01c vldr s19, [r3, #4]
 *   @0x2df020 vldr s18, [r3, #8]
 *   @0x2df024 vldr s17, [r3, #12]
 *   @0x2df028 b 0x2df160 <_ZN13b2DynamicTree10InsertLeafEi+0x190>
 *   @0x2df02c vcmpe.f32 s16, s13
 *   @0x2df030 vldr s12, [r2, #4]
 *   @0x2df034 vldr s10, [r2, #8]
 *   @0x2df038 vldr s11, [r2, #12]
 *   @0x2df03c vmrs APSR_nzcv, fpscr
 *   @0x2df040 vcmpe.f32 s12, s19
 *   @0x2df044 vmovpl.f32 s8, s13
 *   @0x2df048 vmovmi.f32 s8, s16
 *   @0x2df04c vmrs APSR_nzcv, fpscr
 *   @0x2df050 vcmpe.f32 s10, s18
 *   @0x2df054 vmovle.f32 s7, s12
 *   @0x2df058 vmovgt.f32 s7, s19
 *   @0x2df05c vmrs APSR_nzcv, fpscr
 *   @0x2df060 vcmpe.f32 s11, s17
 *   @0x2df064 vmovpl.f32 s6, s10
 *   @0x2df068 vmovmi.f32 s6, s18
 *   @0x2df06c vmrs APSR_nzcv, fpscr
 *   @0x2df070 vmovpl.f32 s9, s11
 *   @0x2df074 vmovmi.f32 s9, s17
 *   @0x2df078 vsub.f32 s13, s10, s13
 *   @0x2df07c vsub.f32 s8, s6, s8
 *   @0x2df080 vsub.f32 s12, s11, s12
 *   @0x2df084 vsub.f32 s9, s9, s7
 *   @0x2df088 vadd.f32 s13, s13, s12
 *   @0x2df08c vadd.f32 s9, s8, s9
 *   @0x2df090 vadd.f32 s13, s13, s13
 *   @0x2df094 vadd.f32 s9, s9, s9
 *   @0x2df098 vsub.f32 s13, s9, s13
 *   @0x2df09c vadd.f32 s13, s13, s14
 *   @0x2df0a0 add r2, lr, lr, lsl #3
 *   @0x2df0a4 add r2, r5, r2, lsl #2
 *   @0x2df0a8 ldr r1, [r2, #0x18]
 *   @0x2df0ac cmn r1, #1
 *   @0x2df0b0 beq 0x2df260 <_ZN13b2DynamicTree10InsertLeafEi+0x290>
 *   @0x2df0b4 vldr s10, [r2]
 *   @0x2df0b8 vcmpe.f32 s16, s10
 *   @0x2df0bc vldr s12, [r2, #4]
 *   @0x2df0c0 vldr s9, [r2, #8]
 *   @0x2df0c4 vldr s11, [r2, #12]
 *   @0x2df0c8 vmrs APSR_nzcv, fpscr
 *   @0x2df0cc vcmpe.f32 s12, s19
 *   @0x2df0d0 vmovpl.f32 s7, s10
 *   @0x2df0d4 vmovmi.f32 s7, s16
 *   @0x2df0d8 vmrs APSR_nzcv, fpscr
 *   @0x2df0dc vcmpe.f32 s9, s18
 *   @0x2df0e0 vmovle.f32 s6, s12
 *   @0x2df0e4 vmovgt.f32 s6, s19
 *   @0x2df0e8 vmrs APSR_nzcv, fpscr
 *   @0x2df0ec vcmpe.f32 s11, s17
 *   @0x2df0f0 vmovpl.f32 s5, s9
 *   @0x2df0f4 vmovmi.f32 s5, s18
 *   @0x2df0f8 vmrs APSR_nzcv, fpscr
 *   @0x2df0fc vmovpl.f32 s8, s11
 *   @0x2df100 vmovmi.f32 s8, s17
 *   @0x2df104 vsub.f32 s10, s9, s10
 *   @0x2df108 vsub.f32 s7, s5, s7
 *   @0x2df10c vsub.f32 s12, s11, s12
 *   @0x2df110 vsub.f32 s8, s8, s6
 *   @0x2df114 vadd.f32 s12, s10, s12
 *   @0x2df118 vadd.f32 s8, s7, s8
 *   @0x2df11c vadd.f32 s12, s12, s12
 *   @0x2df120 vadd.f32 s8, s8, s8
 *   @0x2df124 vsub.f32 s12, s8, s12
 *   @0x2df128 vadd.f32 s14, s12, s14
 *   @0x2df12c vcmpe.f32 s13, s15
 *   @0x2df130 vmrs APSR_nzcv, fpscr
 *   @0x2df134 ble 0x2df144 <_ZN13b2DynamicTree10InsertLeafEi+0x174>
 *   @0x2df138 vcmpe.f32 s14, s15
 *   @0x2df13c vmrs APSR_nzcv, fpscr
 *   @0x2df140 bgt 0x2df2b8 <_ZN13b2DynamicTree10InsertLeafEi+0x2e8>
 *   @0x2df144 vcmpe.f32 s13, s14
 *   @0x2df148 vmrs APSR_nzcv, fpscr
 *   @0x2df14c movmi lr, r12
 *   @0x2df150 movmi r1, r0
 *   @0x2df154 lsl r7, lr, #3
 *   @0x2df158 mov r4, lr
 *   @0x2df15c mov r12, r1
 *   @0x2df160 add r7, r7, r4
 *   @0x2df164 cmn r12, #1
 *   @0x2df168 lsl r7, r7, #2
 *   @0x2df16c add r3, r5, r7
 *   @0x2df170 beq 0x2df2b8 <_ZN13b2DynamicTree10InsertLeafEi+0x2e8>
 *   @0x2df174 vldr s12, [r3]
 *   @0x2df178 vcmpe.f32 s16, s12
 *   @0x2df17c vldr s14, [r3, #4]
 *   @0x2df180 vldr s11, [r3, #8]
 *   @0x2df184 vldr s13, [r3, #12]
 *   @0x2df188 add r2, r12, r12, lsl #3
 *   @0x2df18c ldr lr, [r3, #0x1c]
 *   @0x2df190 vmrs APSR_nzcv, fpscr
 *   @0x2df194 vcmpe.f32 s14, s19
 *   @0x2df198 add r2, r5, r2, lsl #2
 *   @0x2df19c ldr r0, [r2, #0x18]
 *   @0x2df1a0 vmovle.f32 s10, s16
 *   @0x2df1a4 vmovgt.f32 s10, s12
 *   @0x2df1a8 vmrs APSR_nzcv, fpscr
 *   @0x2df1ac vcmpe.f32 s11, s18
 *   @0x2df1b0 vmovpl.f32 s9, s19
 *   @0x2df1b4 vmovmi.f32 s9, s14
 *   @0x2df1b8 vmrs APSR_nzcv, fpscr
 *   @0x2df1bc vcmpe.f32 s13, s17
 *   @0x2df1c0 vmovle.f32 s8, s18
 *   @0x2df1c4 vmovgt.f32 s8, s11
 *   @0x2df1c8 vmrs APSR_nzcv, fpscr
 *   @0x2df1cc vmovle.f32 s15, s17
 *   @0x2df1d0 vmovgt.f32 s15, s13
 *   @0x2df1d4 cmn r0, #1
 *   @0x2df1d8 vsub.f32 s14, s13, s14
 *   @0x2df1dc vldr s13, [r2]
 *   @0x2df1e0 vsub.f32 s12, s11, s12
 *   @0x2df1e4 vsub.f32 s10, s8, s10
 *   @0x2df1e8 vsub.f32 s15, s15, s9
 *   @0x2df1ec vadd.f32 s14, s12, s14
 *   @0x2df1f0 vadd.f32 s15, s10, s15
 *   @0x2df1f4 vadd.f32 s14, s14, s14
 *   @0x2df1f8 vadd.f32 s15, s15, s15
 *   @0x2df1fc vsub.f32 s14, s15, s14
 *   @0x2df200 vadd.f32 s15, s15, s15
 *   @0x2df204 vadd.f32 s14, s14, s14
 *   @0x2df208 bne 0x2df02c <_ZN13b2DynamicTree10InsertLeafEi+0x5c>
 *   @0x2df20c vldr s10, [r2, #4]
 *   @0x2df210 vldr s11, [r2, #8]
 *   @0x2df214 vldr s12, [r2, #12]
 *   @0x2df218 vcmpe.f32 s16, s13
 *   @0x2df21c vmrs APSR_nzcv, fpscr
 *   @0x2df220 vcmpe.f32 s10, s19
 *   @0x2df224 vmovmi.f32 s13, s16
 *   @0x2df228 vmrs APSR_nzcv, fpscr
 *   @0x2df22c vcmpe.f32 s11, s18
 *   @0x2df230 vmovgt.f32 s10, s19
 *   @0x2df234 vmrs APSR_nzcv, fpscr
 *   @0x2df238 vcmpe.f32 s12, s17
 *   @0x2df23c vmovmi.f32 s11, s18
 *   @0x2df240 vmrs APSR_nzcv, fpscr
 *   @0x2df244 vmovmi.f32 s12, s17
 *   @0x2df248 vsub.f32 s13, s11, s13
 *   @0x2df24c vsub.f32 s12, s12, s10
 *   @0x2df250 vadd.f32 s13, s13, s12
 *   @0x2df254 vadd.f32 s13, s13, s13
 *   @0x2df258 vadd.f32 s13, s14, s13
 *   @0x2df25c b 0x2df0a0 <_ZN13b2DynamicTree10InsertLeafEi+0xd0>
 *   @0x2df260 vldr s12, [r2]
 *   @0x2df264 vcmpe.f32 s16, s12
 *   @0x2df268 vldr s9, [r2, #4]
 *   @0x2df26c vldr s10, [r2, #8]
 *   @0x2df270 vldr s11, [r2, #12]
 *   @0x2df274 vmrs APSR_nzcv, fpscr
 *   @0x2df278 vcmpe.f32 s9, s19
 *   @0x2df27c vmovmi.f32 s12, s16
 *   @0x2df280 vmrs APSR_nzcv, fpscr
 *   @0x2df284 vcmpe.f32 s10, s18
 *   @0x2df288 vmovgt.f32 s9, s19
 *   @0x2df28c vmrs APSR_nzcv, fpscr
 *   @0x2df290 vcmpe.f32 s11, s17
 *   @0x2df294 vmovmi.f32 s10, s18
 *   @0x2df298 vmrs APSR_nzcv, fpscr
 *   @0x2df29c vmovmi.f32 s11, s17
 *   @0x2df2a0 vsub.f32 s12, s10, s12
 *   @0x2df2a4 vsub.f32 s11, s11, s9
 *   @0x2df2a8 vadd.f32 s12, s12, s11
 *   @0x2df2ac vadd.f32 s12, s12, s12
 *   @0x2df2b0 vadd.f32 s14, s14, s12
 *   @0x2df2b4 b 0x2df12c <_ZN13b2DynamicTree10InsertLeafEi+0x15c>
 *   @0x2df2b8 mov r0, r6
 *   @0x2df2bc ldr r5, [r3, #0x14]
 *   @0x2df2c0 bl 0x2de9bc <_ZN13b2DynamicTree12AllocateNodeEv>
 *   @0x2df2c4 ldr r2, [r6, #0x4]
 *   @0x2df2c8 mov r12, #0
 *   @0x2df2cc add r7, r2, r7
 *   @0x2df2d0 add r3, r0, r0, lsl #3
 *   @0x2df2d4 mov r1, r0
 *   @0x2df2d8 ldr r0, [r7, #0x20]
 *   @0x2df2dc add r3, r2, r3, lsl #2
 *   @0x2df2e0 add r0, r0, #1
 *   @0x2df2e4 str r5, [r3, #0x14]
 *   @0x2df2e8 vldr s14, [r7]
 *   @0x2df2ec vcmpe.f32 s16, s14
 *   @0x2df2f0 vldr s15, [r7, #4]
 *   @0x2df2f4 str r12, [r3, #0x10]
 *   @0x2df2f8 vmrs APSR_nzcv, fpscr
 *   @0x2df2fc vcmpe.f32 s15, s19
 *   @0x2df300 vmovpl.f32 s16, s14
 *   @0x2df304 vmrs APSR_nzcv, fpscr
 *   @0x2df308 vstr s16, [r3]
 *   @0x2df30c vmovle.f32 s19, s15
 *   @0x2df310 vstr s19, [r3, #4]
 *   @0x2df314 vldr s14, [r7, #8]
 *   @0x2df318 vldr s15, [r7, #12]
 *   @0x2df31c str r0, [r3, #0x20]
 *   @0x2df320 vcmpe.f32 s14, s18
 *   @0x2df324 vmrs APSR_nzcv, fpscr
 *   @0x2df328 vcmpe.f32 s15, s17
 *   @0x2df32c vmovpl.f32 s18, s14
 *   @0x2df330 vmrs APSR_nzcv, fpscr
 *   @0x2df334 vstr s18, [r3, #8]
 *   @0x2df338 vmovpl.f32 s17, s15
 *   @0x2df33c cmn r5, #1
 *   @0x2df340 vstr s17, [r3, #12]
 *   @0x2df344 beq 0x2df434 <_ZN13b2DynamicTree10InsertLeafEi+0x464>
 *   @0x2df348 add r5, r5, r5, lsl #3
 *   @0x2df34c add r5, r2, r5, lsl #2
 *   @0x2df350 add r2, r2, r9
 *   @0x2df354 ldr r0, [r5, #0x18]
 *   @0x2df358 cmp r4, r0
 *   @0x2df35c streq r1, [r5, #0x18]
 *   @0x2df360 strne r1, [r5, #0x1c]
 *   @0x2df364 str r4, [r3, #0x18]
 *   @0x2df368 str r8, [r3, #0x1c]
 *   @0x2df36c str r1, [r7, #0x14]
 *   @0x2df370 str r1, [r2, #0x14]
 *   @0x2df374 cmn r1, #1
 *   @0x2df378 beq 0x2df42c <_ZN13b2DynamicTree10InsertLeafEi+0x45c>
 *   @0x2df37c mov r0, r6
 *   @0x2df380 bl 0x2deae4 <_ZN13b2DynamicTree7BalanceEi>
 *   @0x2df384 ldr r4, [r6, #0x4]
 *   @0x2df388 add r0, r0, r0, lsl #3
 *   @0x2df38c add r3, r4, r0, lsl #2
 *   @0x2df390 ldr r12, [r3, #0x18]
 *   @0x2df394 ldr r2, [r3, #0x1c]
 *   @0x2df398 ldr r1, [r3, #0x14]
 *   @0x2df39c add r12, r12, r12, lsl #3
 *   @0x2df3a0 add r2, r2, r2, lsl #3
 *   @0x2df3a4 add r12, r4, r12, lsl #2
 *   @0x2df3a8 vldr s12, [r12]
 *   @0x2df3ac add r2, r4, r2, lsl #2
 *   @0x2df3b0 vldr s13, [r2]
 *   @0x2df3b4 vcmpe.f32 s12, s13
 *   @0x2df3b8 ldr r0, [r12, #0x20]
 *   @0x2df3bc ldr r4, [r2, #0x20]
 *   @0x2df3c0 vldr s14, [r12, #4]
 *   @0x2df3c4 vldr s15, [r2, #4]
 *   @0x2df3c8 cmp r0, r4
 *   @0x2df3cc movlt r0, r4
 *   @0x2df3d0 vmrs APSR_nzcv, fpscr
 *   @0x2df3d4 vcmpe.f32 s14, s15
 *   @0x2df3d8 add r0, r0, #1
 *   @0x2df3dc str r0, [r3, #0x20]
 *   @0x2df3e0 vmovmi.f32 s13, s12
 *   @0x2df3e4 vmrs APSR_nzcv, fpscr
 *   @0x2df3e8 vstr s13, [r3]
 *   @0x2df3ec vmovmi.f32 s15, s14
 *   @0x2df3f0 vstr s15, [r3, #4]
 *   @0x2df3f4 vldr s12, [r12, #8]
 *   @0x2df3f8 vldr s13, [r2, #8]
 *   @0x2df3fc vldr s14, [r12, #12]
 *   @0x2df400 vldr s15, [r2, #12]
 *   @0x2df404 vcmpe.f32 s12, s13
 *   @0x2df408 vmrs APSR_nzcv, fpscr
 *   @0x2df40c vcmpe.f32 s14, s15
 *   @0x2df410 vmovgt.f32 s13, s12
 *   @0x2df414 vmrs APSR_nzcv, fpscr
 *   @0x2df418 vstr s13, [r3, #8]
 *   @0x2df41c vmovgt.f32 s15, s14
 *   @0x2df420 cmn r1, #1
 *   @0x2df424 vstr s15, [r3, #12]
 *   @0x2df428 bne 0x2df37c <_ZN13b2DynamicTree10InsertLeafEi+0x3ac>
 *   @0x2df42c vpop {d8, d9}
 *   @0x2df430 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2df434 add r2, r2, r9
 *   @0x2df438 str r4, [r3, #0x18]
 *   @0x2df43c str r8, [r3, #0x1c]
 *   @0x2df440 str r1, [r7, #0x14]
 *   @0x2df444 str r1, [r2, #0x14]
 *   @0x2df448 str r1, [r6]
 *   @0x2df44c b 0x2df374 <_ZN13b2DynamicTree10InsertLeafEi+0x3a4>
 *   @0x2df450 ldr r3, [r0, #0x4]
 *   @0x2df454 add r2, r1, r1, lsl #3
 *   @0x2df458 str r1, [r6]
 *   @0x2df45c add r3, r3, r2, lsl #2
 *   @0x2df460 str r4, [r3, #0x14]
 *   @0x2df464 vpop {d8, d9}
 *   @0x2df468 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §15/25 CreateArgumentsObject  0x248b58  size 1172  293 条（0x248b58..0x248fec）
 * @func 0x248b58 0x248fec  size 1172  293 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×6 / UNLOCK_RVALUE_MUTEX()×6 / YYFree(void const*)×6 / operator delete(void*)×6 / PushContextStack(YYObjectBase*)×2 / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)×2 / PopContextStack()×2 / YYObjectBase::InternalGetYYVar(int)×2
 * 字段偏移 top8: 0x8×22 / 0x4×14 / 0xc×11 / 0x-10×6 / 0x10×3 / 0x14×3 / 0x28×3 / 0x-4×2
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x248b58 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x248b5c sub sp, sp, #60
 *   @0x248b60 mov r12, #0
 *   @0x248b64 mov r7, r2
 *   @0x248b68 str r1, [sp, #0x10]
 *   @0x248b6c mov r2, r12
 *   @0x248b70 mov r1, r12
 *   @0x248b74 str r12, [sp]
 *   @0x248b78 mov r5, r3
 *   @0x248b7c mov r3, r12
 *   @0x248b80 ldrb r12, [sp, #0x60]
 *   @0x248b84 mov r4, r0
 *   @0x248b88 str r12, [sp, #0x14]
 *   @0x248b8c bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_>
 *   @0x248b90 ldr r4, [r4]
 *   @0x248b94 str r4, [sp, #0xc]
 *   @0x248b98 ldr r0, [sp, #0xc]
 *   @0x248b9c bl 0xd3968 <_Z16PushContextStackP12YYObjectBase>
 *   @0x248ba0 ldr lr, [sp, #0xc]
 *   @0x248ba4 ldr r4, [pc, #0x430]
 *   @0x248ba8 mov r2, r7
 *   @0x248bac ldr r12, [pc, #0x42c]
 *   @0x248bb0 ldr r1, [lr, #0x28]
 *   @0x248bb4 add r4, pc, r4
 *   @0x248bb8 ldr r3, [pc, #0x424]
 *   @0x248bbc add r12, pc, r12
 *   @0x248bc0 mov r0, lr
 *   @0x248bc4 str r12, [lr, #0x40]
 *   @0x248bc8 ldr r3, [pc, r3]
 *   @0x248bcc orr r1, r1, #1
 *   @0x248bd0 str r3, [lr, #0x4c]
 *   @0x248bd4 mov r3, #6
 *   @0x248bd8 str r1, [lr, #0x28]
 *   @0x248bdc mov r1, r4
 *   @0x248be0 bl 0x199960 <_ZN12YYObjectBase3AddEPKcii>
 *   @0x248be4 ldr r0, [sp, #0x10]
 *   @0x248be8 mov r2, r4
 *   @0x248bec add r1, sp, #24
 *   @0x248bf0 mov r3, #5
 *   @0x248bf4 str r3, [sp, #0x24]
 *   @0x248bf8 bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc>
 *   @0x248bfc vmov s15, r7
 *   @0x248c00 mov r1, #5
 *   @0x248c04 mov r2, #0
 *   @0x248c08 vcvt.f64.s32 d6, s15
 *   @0x248c0c vldr d7, [sp, #24]
 *   @0x248c10 vcmpe.f64 d7, d6
 *   @0x248c14 vmrs APSR_nzcv, fpscr
 *   @0x248c18 vcvtgt.s32.f64 s13, d7
 *   @0x248c1c movle r0, r7
 *   @0x248c20 vmovgt r0, s13
 *   @0x248c24 bl 0x19198c <_ZN12YYObjectBase5AllocEjib>
 *   @0x248c28 ldr r12, [sp, #0xc]
 *   @0x248c2c ldr r3, [r12, #0x4]
 *   @0x248c30 cmp r3, #0
 *   @0x248c34 mov r6, r0
 *   @0x248c38 beq 0x248f1c <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x3c4>
 *   @0x248c3c add r3, r3, #16
 *   @0x248c40 mov r2, #6
 *   @0x248c44 str r6, [r3]
 *   @0x248c48 ldr r0, [sp, #0xc]
 *   @0x248c4c mov r1, r6
 *   @0x248c50 str r2, [r3, #0xc]
 *   @0x248c54 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x248c58 subs r4, r7, #1
 *   @0x248c5c bmi 0x248d54 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x1fc>
 *   @0x248c60 movw r8, #0xfff0
 *   @0x248c64 movt r8, #0xffff
 *   @0x248c68 rsb r8, r5, r8
 *   @0x248c6c add r11, r5, r7, lsl #4
 *   @0x248c70 mov r7, #0
 *   @0x248c74 ldr r3, [r6, #0x4]
 *   @0x248c78 add r5, r8, r11
 *   @0x248c7c sub r9, r11, #16
 *   @0x248c80 cmp r3, #0
 *   @0x248c84 beq 0x248e88 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x330>
 *   @0x248c88 add r5, r3, r5
 *   @0x248c8c mov r0, r6
 *   @0x248c90 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase>
 *   @0x248c94 ldr r2, [r5, #0xc]
 *   @0x248c98 bic r3, r2, #-16777216
 *   @0x248c9c cmp r3, #1
 *   @0x248ca0 beq 0x248e0c <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x2b4>
 *   @0x248ca4 cmp r3, #2
 *   @0x248ca8 bne 0x248ccc <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x174>
 *   @0x248cac sub r2, r2, #1
 *   @0x248cb0 bic r2, r2, #-16777216
 *   @0x248cb4 bic r2, r2, #3
 *   @0x248cb8 cmp r2, #0
 *   @0x248cbc beq 0x248e7c <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x324>
 *   @0x248cc0 mov lr, #5
 *   @0x248cc4 str r7, [r5, #0x8]
 *   @0x248cc8 str lr, [r5, #0xc]
 *   @0x248ccc str r7, [r5]
 *   @0x248cd0 ldr r3, [r11, #-0x4]
 *   @0x248cd4 str r3, [r5, #0xc]
 *   @0x248cd8 ldr r3, [r11, #-0x8]
 *   @0x248cdc str r3, [r5, #0x8]
 *   @0x248ce0 ldr r3, [r11, #-0x4]
 *   @0x248ce4 bic r3, r3, #-16777216
 *   @0x248ce8 cmp r3, #14
 *   @0x248cec addls pc, pc, r3, lsl #2
 *   @0x248cf0 b 0x248d38 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x1e0>
 *   @0x248cf4 b 0x248d98 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x240>
 *   @0x248cf8 b 0x248df4 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x29c>
 *   @0x248cfc b 0x248dc8 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x270>
 *   @0x248d00 b 0x248d30 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x1d8>
 *   @0x248d04 b 0x248d38 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x1e0>
 *   @0x248d08 b 0x248d38 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x1e0>
 *   @0x248d0c b 0x248da4 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x24c>
 *   @0x248d10 b 0x248d30 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x1d8>
 *   @0x248d14 b 0x248d38 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x1e0>
 *   @0x248d18 b 0x248d38 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x1e0>
 *   @0x248d1c b 0x248d98 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x240>
 *   @0x248d20 b 0x248d38 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x1e0>
 *   @0x248d24 b 0x248d38 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x1e0>
 *   @0x248d28 b 0x248d98 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x240>
 *   @0x248d2c b 0x248d30 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x1d8>
 *   @0x248d30 ldr r3, [r11, #-0x10]
 *   @0x248d34 str r3, [r5]
 *   @0x248d38 sub r4, r4, #1
 *   @0x248d3c bl 0xd3a34 <_Z15PopContextStackv>
 *   @0x248d40 cmn r4, #1
 *   @0x248d44 mov r2, #7
 *   @0x248d48 mov r11, r9
 *   @0x248d4c str r2, [r5, #0x8]
 *   @0x248d50 bne 0x248c74 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x11c>
 *   @0x248d54 ldr r12, [sp, #0x14]
 *   @0x248d58 cmp r12, #0
 *   @0x248d5c bne 0x248d8c <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x234>
 *   @0x248d60 ldr r12, [sp, #0x10]
 *   @0x248d64 add r2, sp, #40
 *   @0x248d68 ldr r1, [pc, #0x278]
 *   @0x248d6c ldr r0, [sp, #0xc]
 *   @0x248d70 ldr r3, [sp, #0x14]
 *   @0x248d74 add r1, pc, r1
 *   @0x248d78 str r12, [sp, #0x28]
 *   @0x248d7c mov r12, #6
 *   @0x248d80 str r12, [sp, #0x34]
 *   @0x248d84 str r12, [sp, #0x30]
 *   @0x248d88 bl 0x248394 <_Z20JS_DefineOwnPropertyP12YYObjectBasePKcP6RValueb>
 *   @0x248d8c bl 0xd3a34 <_Z15PopContextStackv>
 *   @0x248d90 add sp, sp, #60
 *   @0x248d94 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x248d98 ldm r9, {r2, r3}
 *   @0x248d9c stm r5, {r2, r3}
 *   @0x248da0 b 0x248d38 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x1e0>
 *   @0x248da4 ldr r3, [r11, #-0x10]
 *   @0x248da8 str r3, [r5]
 *   @0x248dac ldr r3, [r11, #-0x10]
 *   @0x248db0 cmp r3, #0
 *   @0x248db4 beq 0x248d38 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x1e0>
 *   @0x248db8 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x248dbc ldr r1, [r11, #-0x10]
 *   @0x248dc0 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x248dc4 b 0x248d38 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x1e0>
 *   @0x248dc8 ldr r3, [r11, #-0x10]
 *   @0x248dcc cmp r3, #0
 *   @0x248dd0 str r3, [r5]
 *   @0x248dd4 beq 0x248d38 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x1e0>
 *   @0x248dd8 ldr r1, [r3, #0x8]
 *   @0x248ddc ldr r2, [r3]
 *   @0x248de0 cmp r1, #0
 *   @0x248de4 streq r5, [r3, #0x8]
 *   @0x248de8 add r2, r2, #1
 *   @0x248dec str r2, [r3]
 *   @0x248df0 b 0x248d38 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x1e0>
 *   @0x248df4 ldr r3, [r11, #-0x10]
 *   @0x248df8 cmp r3, #0
 *   @0x248dfc ldrne r2, [r3, #0x4]
 *   @0x248e00 addne r2, r2, #1
 *   @0x248e04 strne r2, [r3, #0x4]
 *   @0x248e08 b 0x248d34 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x1dc>
 *   @0x248e0c ldr r10, [r5]
 *   @0x248e10 cmp r10, #0
 *   @0x248e14 beq 0x248e34 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x2dc>
 *   @0x248e18 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x248e1c ldr r3, [r10, #0x4]
 *   @0x248e20 sub r3, r3, #1
 *   @0x248e24 str r3, [r10, #0x4]
 *   @0x248e28 cmp r3, #0
 *   @0x248e2c beq 0x248e3c <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x2e4>
 *   @0x248e30 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x248e34 str r7, [r5]
 *   @0x248e38 b 0x248ccc <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x174>
 *   @0x248e3c ldr r0, [r10]
 *   @0x248e40 str r3, [sp, #0x8]
 *   @0x248e44 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x248e48 ldr r3, [sp, #0x8]
 *   @0x248e4c str r3, [r10]
 *   @0x248e50 str r3, [r10, #0x8]
 *   @0x248e54 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x248e58 ldr r3, [r10, #0x4]
 *   @0x248e5c sub r3, r3, #1
 *   @0x248e60 str r3, [r10, #0x4]
 *   @0x248e64 cmp r3, #0
 *   @0x248e68 beq 0x248e9c <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x344>
 *   @0x248e6c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x248e70 mov r0, r10
 *   @0x248e74 bl 0x27d1d0 <_ZdlPv>
 *   @0x248e78 b 0x248e30 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x2d8>
 *   @0x248e7c mov r0, r5
 *   @0x248e80 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x248e84 b 0x248cc0 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x168>
 *   @0x248e88 mov r0, r6
 *   @0x248e8c mov r1, r4
 *   @0x248e90 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x248e94 mov r5, r0
 *   @0x248e98 b 0x248c8c <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x134>
 *   @0x248e9c ldr r0, [r10]
 *   @0x248ea0 str r3, [sp, #0x8]
 *   @0x248ea4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x248ea8 ldr r3, [sp, #0x8]
 *   @0x248eac str r3, [r10]
 *   @0x248eb0 str r3, [r10, #0x8]
 *   @0x248eb4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x248eb8 ldr r3, [r10, #0x4]
 *   @0x248ebc sub r3, r3, #1
 *   @0x248ec0 str r3, [r10, #0x4]
 *   @0x248ec4 cmp r3, #0
 *   @0x248ec8 beq 0x248edc <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x384>
 *   @0x248ecc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x248ed0 mov r0, r10
 *   @0x248ed4 bl 0x27d1d0 <_ZdlPv>
 *   @0x248ed8 b 0x248e6c <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x314>
 *   @0x248edc ldr r0, [r10]
 *   @0x248ee0 str r3, [sp, #0x8]
 *   @0x248ee4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x248ee8 ldr r3, [sp, #0x8]
 *   @0x248eec str r3, [r10]
 *   @0x248ef0 str r3, [r10, #0x8]
 *   @0x248ef4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x248ef8 ldr r3, [r10, #0x4]
 *   @0x248efc sub r3, r3, #1
 *   @0x248f00 str r3, [r10, #0x4]
 *   @0x248f04 cmp r3, #0
 *   @0x248f08 beq 0x248f30 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x3d8>
 *   @0x248f0c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x248f10 mov r0, r10
 *   @0x248f14 bl 0x27d1d0 <_ZdlPv>
 *   @0x248f18 b 0x248ecc <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x374>
 *   @0x248f1c ldr r0, [sp, #0xc]
 *   @0x248f20 mov r1, #1
 *   @0x248f24 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x248f28 mov r3, r0
 *   @0x248f2c b 0x248c40 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0xe8>
 *   @0x248f30 ldr r0, [r10]
 *   @0x248f34 str r3, [sp, #0x8]
 *   @0x248f38 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x248f3c ldr r3, [sp, #0x8]
 *   @0x248f40 str r3, [r10]
 *   @0x248f44 str r3, [r10, #0x8]
 *   @0x248f48 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x248f4c ldr r3, [r10, #0x4]
 *   @0x248f50 sub r3, r3, #1
 *   @0x248f54 str r3, [r10, #0x4]
 *   @0x248f58 cmp r3, #0
 *   @0x248f5c beq 0x248f70 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x418>
 *   @0x248f60 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x248f64 mov r0, r10
 *   @0x248f68 bl 0x27d1d0 <_ZdlPv>
 *   @0x248f6c b 0x248f0c <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x3b4>
 *   @0x248f70 ldr r0, [r10]
 *   @0x248f74 str r3, [sp, #0x8]
 *   @0x248f78 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x248f7c ldr r3, [sp, #0x8]
 *   @0x248f80 str r3, [r10]
 *   @0x248f84 str r3, [r10, #0x8]
 *   @0x248f88 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x248f8c ldr r3, [r10, #0x4]
 *   @0x248f90 sub r3, r3, #1
 *   @0x248f94 str r3, [r10, #0x4]
 *   @0x248f98 cmp r3, #0
 *   @0x248f9c beq 0x248fb0 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x458>
 *   @0x248fa0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x248fa4 mov r0, r10
 *   @0x248fa8 bl 0x27d1d0 <_ZdlPv>
 *   @0x248fac b 0x248f60 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x408>
 *   @0x248fb0 ldr r0, [r10]
 *   @0x248fb4 str r3, [sp, #0x8]
 *   @0x248fb8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x248fbc ldr r3, [sp, #0x8]
 *   @0x248fc0 mov r0, r10
 *   @0x248fc4 str r3, [r10]
 *   @0x248fc8 str r3, [r10, #0x8]
 *   @0x248fcc bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x248fd0 mov r0, r10
 *   @0x248fd4 bl 0x27d1d0 <_ZdlPv>
 *   @0x248fd8 b 0x248fa0 <_Z21CreateArgumentsObjectR6RValueP12YYObjectBaseiPS_b+0x448>
 *   @0x248fdc strheq r7, [lr], -r8
 *   @0x248fe0 andseq sp, r0, r8, lsl #5
 *   @0x248fe4 andseq r8, r10, r0, lsl #24
 *   @0x248fe8 ldrsbeq sp, [r0], -r12
 *
 * ══ §16/25 JSArrayGet  0x249cdc  size 1164  291 条（0x249cdc..0x24a168）
 * @func 0x249cdc 0x24a168  size 1164  291 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / GetContextStackTop()×2 / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)×2 / _RefThing<char const*>::dec()×2 / FREE_RValue__Pre(RValue*)×2
 * 字段偏移 top8: 0xc×13 / 0x8×13 / 0x4×11 / 0x454×1 / 0x40×1 / 0x24×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x249cdc cmp r0, #0
 *   @0x249ce0 push {r4, r5, r6, r7, r8, lr}
 *   @0x249ce4 mov r7, r1
 *   @0x249ce8 mov r6, r2
 *   @0x249cec beq 0x249cfc <_Z10JSArrayGetP6RValueS0_S0_+0x20>
 *   @0x249cf0 ldr r3, [r0, #0xc]
 *   @0x249cf4 cmp r3, #6
 *   @0x249cf8 beq 0x249d04 <_Z10JSArrayGetP6RValueS0_S0_+0x28>
 *   @0x249cfc mov r0, #0
 *   @0x249d00 pop {r4, r5, r6, r7, r8, pc}
 *   @0x249d04 ldr r4, [r0]
 *   @0x249d08 ldr r1, [pc, #0x454]
 *   @0x249d0c ldr r0, [r4, #0x40]
 *   @0x249d10 add r1, pc, r1
 *   @0x249d14 bl 0xb6574 <strcmp@plt>
 *   @0x249d18 cmp r0, #0
 *   @0x249d1c bne 0x249e34 <_Z10JSArrayGetP6RValueS0_S0_+0x158>
 *   @0x249d20 ldr r3, [r4, #0x4]
 *   @0x249d24 cmp r3, #0
 *   @0x249d28 beq 0x24a0e0 <_Z10JSArrayGetP6RValueS0_S0_+0x404>
 *   @0x249d2c add r0, r3, #16
 *   @0x249d30 ldr r2, [r7, #0xc]
 *   @0x249d34 ldr r8, [r0]
 *   @0x249d38 cmp r2, #5
 *   @0x249d3c streq r2, [r6, #0xc]
 *   @0x249d40 beq 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c>
 *   @0x249d44 mov r1, #0
 *   @0x249d48 mov r0, r7
 *   @0x249d4c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x249d50 ldr r3, [r7, #0xc]
 *   @0x249d54 cmp r3, #0
 *   @0x249d58 ldr r3, [r8, #0x24]
 *   @0x249d5c ldmeq r7, {r4, r5}
 *   @0x249d60 vmoveq d7, r4, r5
 *   @0x249d64 vcvteq.s32.f64 s15, d7
 *   @0x249d68 movne r1, r0
 *   @0x249d6c vmoveq r1, s15
 *   @0x249d70 cmp r1, r3
 *   @0x249d74 movhs r3, #5
 *   @0x249d78 strhs r3, [r6, #0xc]
 *   @0x249d7c bhs 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c>
 *   @0x249d80 ldr r3, [r8, #0x4]
 *   @0x249d84 cmp r3, #0
 *   @0x249d88 beq 0x24a154 <_Z10JSArrayGetP6RValueS0_S0_+0x478>
 *   @0x249d8c add r4, r3, r1, lsl #4
 *   @0x249d90 ldr r2, [r6, #0xc]
 *   @0x249d94 bic r3, r2, #-16777216
 *   @0x249d98 cmp r3, #1
 *   @0x249d9c beq 0x24a048 <_Z10JSArrayGetP6RValueS0_S0_+0x36c>
 *   @0x249da0 cmp r3, #2
 *   @0x249da4 bne 0x249dcc <_Z10JSArrayGetP6RValueS0_S0_+0xf0>
 *   @0x249da8 sub r3, r2, #1
 *   @0x249dac bic r3, r3, #-16777216
 *   @0x249db0 bic r3, r3, #3
 *   @0x249db4 cmp r3, #0
 *   @0x249db8 beq 0x24a148 <_Z10JSArrayGetP6RValueS0_S0_+0x46c>
 *   @0x249dbc mov r2, #0
 *   @0x249dc0 mov r3, #5
 *   @0x249dc4 str r2, [r6, #0x8]
 *   @0x249dc8 str r3, [r6, #0xc]
 *   @0x249dcc ldr r3, [r4, #0xc]
 *   @0x249dd0 mov r1, #0
 *   @0x249dd4 ldr r2, [r4, #0x8]
 *   @0x249dd8 str r1, [r6]
 *   @0x249ddc str r3, [r6, #0xc]
 *   @0x249de0 ldr r3, [r4, #0xc]
 *   @0x249de4 str r2, [r6, #0x8]
 *   @0x249de8 bic r3, r3, #-16777216
 *   @0x249dec cmp r3, #14
 *   @0x249df0 addls pc, pc, r3, lsl #2
 *   @0x249df4 b 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c>
 *   @0x249df8 b 0x249fa0 <_Z10JSArrayGetP6RValueS0_S0_+0x2c4>
 *   @0x249dfc b 0x249ffc <_Z10JSArrayGetP6RValueS0_S0_+0x320>
 *   @0x249e00 b 0x249fac <_Z10JSArrayGetP6RValueS0_S0_+0x2d0>
 *   @0x249e04 b 0x249ef0 <_Z10JSArrayGetP6RValueS0_S0_+0x214>
 *   @0x249e08 b 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c>
 *   @0x249e0c b 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c>
 *   @0x249e10 b 0x249fd8 <_Z10JSArrayGetP6RValueS0_S0_+0x2fc>
 *   @0x249e14 b 0x249ef0 <_Z10JSArrayGetP6RValueS0_S0_+0x214>
 *   @0x249e18 b 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c>
 *   @0x249e1c b 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c>
 *   @0x249e20 b 0x249fa0 <_Z10JSArrayGetP6RValueS0_S0_+0x2c4>
 *   @0x249e24 b 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c>
 *   @0x249e28 b 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c>
 *   @0x249e2c b 0x249fa0 <_Z10JSArrayGetP6RValueS0_S0_+0x2c4>
 *   @0x249e30 b 0x249ef0 <_Z10JSArrayGetP6RValueS0_S0_+0x214>
 *   @0x249e34 ldr r3, [r7]
 *   @0x249e38 mov r0, r4
 *   @0x249e3c ldr r1, [r3]
 *   @0x249e40 bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc>
 *   @0x249e44 subs r4, r0, #0
 *   @0x249e48 beq 0x249cfc <_Z10JSArrayGetP6RValueS0_S0_+0x20>
 *   @0x249e4c ldr r2, [r6, #0xc]
 *   @0x249e50 bic r3, r2, #-16777216
 *   @0x249e54 cmp r3, #1
 *   @0x249e58 beq 0x24a014 <_Z10JSArrayGetP6RValueS0_S0_+0x338>
 *   @0x249e5c cmp r3, #2
 *   @0x249e60 bne 0x249e88 <_Z10JSArrayGetP6RValueS0_S0_+0x1ac>
 *   @0x249e64 sub r3, r2, #1
 *   @0x249e68 bic r3, r3, #-16777216
 *   @0x249e6c bic r3, r3, #3
 *   @0x249e70 cmp r3, #0
 *   @0x249e74 beq 0x24a0d4 <_Z10JSArrayGetP6RValueS0_S0_+0x3f8>
 *   @0x249e78 mov r2, #0
 *   @0x249e7c mov r3, #5
 *   @0x249e80 str r2, [r6, #0x8]
 *   @0x249e84 str r3, [r6, #0xc]
 *   @0x249e88 ldr r3, [r4, #0xc]
 *   @0x249e8c mov r1, #0
 *   @0x249e90 ldr r2, [r4, #0x8]
 *   @0x249e94 str r1, [r6]
 *   @0x249e98 str r3, [r6, #0xc]
 *   @0x249e9c ldr r3, [r4, #0xc]
 *   @0x249ea0 str r2, [r6, #0x8]
 *   @0x249ea4 bic r3, r3, #-16777216
 *   @0x249ea8 cmp r3, #14
 *   @0x249eac addls pc, pc, r3, lsl #2
 *   @0x249eb0 b 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c>
 *   @0x249eb4 b 0x249f10 <_Z10JSArrayGetP6RValueS0_S0_+0x234>
 *   @0x249eb8 b 0x249f4c <_Z10JSArrayGetP6RValueS0_S0_+0x270>
 *   @0x249ebc b 0x249f6c <_Z10JSArrayGetP6RValueS0_S0_+0x290>
 *   @0x249ec0 b 0x249f00 <_Z10JSArrayGetP6RValueS0_S0_+0x224>
 *   @0x249ec4 b 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c>
 *   @0x249ec8 b 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c>
 *   @0x249ecc b 0x249f24 <_Z10JSArrayGetP6RValueS0_S0_+0x248>
 *   @0x249ed0 b 0x249f00 <_Z10JSArrayGetP6RValueS0_S0_+0x224>
 *   @0x249ed4 b 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c>
 *   @0x249ed8 b 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c>
 *   @0x249edc b 0x249f10 <_Z10JSArrayGetP6RValueS0_S0_+0x234>
 *   @0x249ee0 b 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c>
 *   @0x249ee4 b 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c>
 *   @0x249ee8 b 0x249f10 <_Z10JSArrayGetP6RValueS0_S0_+0x234>
 *   @0x249eec b 0x249f00 <_Z10JSArrayGetP6RValueS0_S0_+0x224>
 *   @0x249ef0 ldr r3, [r4]
 *   @0x249ef4 str r3, [r6]
 *   @0x249ef8 mov r0, #1
 *   @0x249efc pop {r4, r5, r6, r7, r8, pc}
 *   @0x249f00 ldr r3, [r4]
 *   @0x249f04 mov r0, #1
 *   @0x249f08 str r3, [r6]
 *   @0x249f0c pop {r4, r5, r6, r7, r8, pc}
 *   @0x249f10 ldr r2, [r4]
 *   @0x249f14 mov r0, #1
 *   @0x249f18 ldr r3, [r4, #0x4]
 *   @0x249f1c stm r6, {r2, r3}
 *   @0x249f20 pop {r4, r5, r6, r7, r8, pc}
 *   @0x249f24 ldr r3, [r4]
 *   @0x249f28 str r3, [r6]
 *   @0x249f2c ldr r3, [r4]
 *   @0x249f30 cmp r3, #0
 *   @0x249f34 beq 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c>
 *   @0x249f38 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x249f3c ldr r1, [r4]
 *   @0x249f40 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x249f44 mov r0, #1
 *   @0x249f48 pop {r4, r5, r6, r7, r8, pc}
 *   @0x249f4c ldr r3, [r4]
 *   @0x249f50 mov r0, #1
 *   @0x249f54 cmp r3, #0
 *   @0x249f58 ldrne r2, [r3, #0x4]
 *   @0x249f5c addne r2, r2, #1
 *   @0x249f60 strne r2, [r3, #0x4]
 *   @0x249f64 str r3, [r6]
 *   @0x249f68 pop {r4, r5, r6, r7, r8, pc}
 *   @0x249f6c ldr r3, [r4]
 *   @0x249f70 cmp r3, #0
 *   @0x249f74 str r3, [r6]
 *   @0x249f78 beq 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c>
 *   @0x249f7c ldr r1, [r3, #0x8]
 *   @0x249f80 ldr r2, [r3]
 *   @0x249f84 cmp r1, #0
 *   @0x249f88 add r2, r2, #1
 *   @0x249f8c str r2, [r3]
 *   @0x249f90 bne 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c>
 *   @0x249f94 str r6, [r3, #0x8]
 *   @0x249f98 mov r0, #1
 *   @0x249f9c pop {r4, r5, r6, r7, r8, pc}
 *   @0x249fa0 ldm r4, {r2, r3}
 *   @0x249fa4 stm r6, {r2, r3}
 *   @0x249fa8 b 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c>
 *   @0x249fac ldr r3, [r4]
 *   @0x249fb0 cmp r3, #0
 *   @0x249fb4 str r3, [r6]
 *   @0x249fb8 beq 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c>
 *   @0x249fbc ldr r1, [r3, #0x8]
 *   @0x249fc0 ldr r2, [r3]
 *   @0x249fc4 cmp r1, #0
 *   @0x249fc8 streq r6, [r3, #0x8]
 *   @0x249fcc add r2, r2, #1
 *   @0x249fd0 str r2, [r3]
 *   @0x249fd4 b 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c>
 *   @0x249fd8 ldr r3, [r4]
 *   @0x249fdc str r3, [r6]
 *   @0x249fe0 ldr r3, [r4]
 *   @0x249fe4 cmp r3, #0
 *   @0x249fe8 beq 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c>
 *   @0x249fec bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x249ff0 ldr r1, [r4]
 *   @0x249ff4 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x249ff8 b 0x249ef8 <_Z10JSArrayGetP6RValueS0_S0_+0x21c>
 *   @0x249ffc ldr r3, [r4]
 *   @0x24a000 cmp r3, #0
 *   @0x24a004 ldrne r2, [r3, #0x4]
 *   @0x24a008 addne r2, r2, #1
 *   @0x24a00c strne r2, [r3, #0x4]
 *   @0x24a010 b 0x249ef4 <_Z10JSArrayGetP6RValueS0_S0_+0x218>
 *   @0x24a014 ldr r5, [r6]
 *   @0x24a018 cmp r5, #0
 *   @0x24a01c beq 0x24a03c <_Z10JSArrayGetP6RValueS0_S0_+0x360>
 *   @0x24a020 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24a024 ldr r7, [r5, #0x4]
 *   @0x24a028 sub r7, r7, #1
 *   @0x24a02c str r7, [r5, #0x4]
 *   @0x24a030 cmp r7, #0
 *   @0x24a034 beq 0x24a07c <_Z10JSArrayGetP6RValueS0_S0_+0x3a0>
 *   @0x24a038 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x24a03c mov r3, #0
 *   @0x24a040 str r3, [r6]
 *   @0x24a044 b 0x249e88 <_Z10JSArrayGetP6RValueS0_S0_+0x1ac>
 *   @0x24a048 ldr r5, [r6]
 *   @0x24a04c cmp r5, #0
 *   @0x24a050 beq 0x24a070 <_Z10JSArrayGetP6RValueS0_S0_+0x394>
 *   @0x24a054 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24a058 ldr r7, [r5, #0x4]
 *   @0x24a05c sub r7, r7, #1
 *   @0x24a060 str r7, [r5, #0x4]
 *   @0x24a064 cmp r7, #0
 *   @0x24a068 beq 0x24a0f0 <_Z10JSArrayGetP6RValueS0_S0_+0x414>
 *   @0x24a06c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x24a070 mov r3, #0
 *   @0x24a074 str r3, [r6]
 *   @0x24a078 b 0x249dcc <_Z10JSArrayGetP6RValueS0_S0_+0xf0>
 *   @0x24a07c ldr r0, [r5]
 *   @0x24a080 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24a084 str r7, [r5]
 *   @0x24a088 str r7, [r5, #0x8]
 *   @0x24a08c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24a090 ldr r7, [r5, #0x4]
 *   @0x24a094 sub r7, r7, #1
 *   @0x24a098 str r7, [r5, #0x4]
 *   @0x24a09c cmp r7, #0
 *   @0x24a0a0 bne 0x24a0c4 <_Z10JSArrayGetP6RValueS0_S0_+0x3e8>
 *   @0x24a0a4 ldr r0, [r5]
 *   @0x24a0a8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24a0ac mov r0, r5
 *   @0x24a0b0 str r7, [r5]
 *   @0x24a0b4 str r7, [r5, #0x8]
 *   @0x24a0b8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x24a0bc mov r0, r5
 *   @0x24a0c0 bl 0x27d1d0 <_ZdlPv>
 *   @0x24a0c4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x24a0c8 mov r0, r5
 *   @0x24a0cc bl 0x27d1d0 <_ZdlPv>
 *   @0x24a0d0 b 0x24a038 <_Z10JSArrayGetP6RValueS0_S0_+0x35c>
 *   @0x24a0d4 mov r0, r6
 *   @0x24a0d8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x24a0dc b 0x249e78 <_Z10JSArrayGetP6RValueS0_S0_+0x19c>
 *   @0x24a0e0 mov r0, r4
 *   @0x24a0e4 mov r1, #1
 *   @0x24a0e8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x24a0ec b 0x249d30 <_Z10JSArrayGetP6RValueS0_S0_+0x54>
 *   @0x24a0f0 ldr r0, [r5]
 *   @0x24a0f4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24a0f8 str r7, [r5]
 *   @0x24a0fc str r7, [r5, #0x8]
 *   @0x24a100 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24a104 ldr r7, [r5, #0x4]
 *   @0x24a108 sub r7, r7, #1
 *   @0x24a10c str r7, [r5, #0x4]
 *   @0x24a110 cmp r7, #0
 *   @0x24a114 bne 0x24a138 <_Z10JSArrayGetP6RValueS0_S0_+0x45c>
 *   @0x24a118 ldr r0, [r5]
 *   @0x24a11c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24a120 mov r0, r5
 *   @0x24a124 str r7, [r5]
 *   @0x24a128 str r7, [r5, #0x8]
 *   @0x24a12c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x24a130 mov r0, r5
 *   @0x24a134 bl 0x27d1d0 <_ZdlPv>
 *   @0x24a138 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x24a13c mov r0, r5
 *   @0x24a140 bl 0x27d1d0 <_ZdlPv>
 *   @0x24a144 b 0x24a06c <_Z10JSArrayGetP6RValueS0_S0_+0x390>
 *   @0x24a148 mov r0, r6
 *   @0x24a14c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x24a150 b 0x249dbc <_Z10JSArrayGetP6RValueS0_S0_+0xe0>
 *   @0x24a154 mov r0, r8
 *   @0x24a158 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x24a15c mov r4, r0
 *   @0x24a160 b 0x249d90 <_Z10JSArrayGetP6RValueS0_S0_+0xb4>
 *   @0x24a164 andeq r10, lr, r8, lsl #24
 *
 * ══ §17/25 b2ContactSolver::SolvePositionConstraints  0x2e2f4c  size 1164  291 条（0x2e2f4c..0x2e33d8）
 * @func 0x2e2f4c 0x2e33ec  size 1184  296 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6580×2 / 0xb658c×2 / b2ContactSolver::SolvePositionConstraints()+0x46c / b2ContactSolver::SolvePositionConstraints()+0x428 / 0xb6700
 * 字段偏移 top8: 0x30×2 / 0x18×2 / 0x24×2 / 0x20×1 / 0x54×1 / 0x48×1
 * VFP 指令 217 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e2f4c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2e2f50 vpush {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x2e2f54 mov r7, r0
 *   @0x2e2f58 ldr r0, [r0, #0x30]
 *   @0x2e2f5c sub sp, sp, #36
 *   @0x2e2f60 cmp r0, #0
 *   @0x2e2f64 ble 0x2e33b8 <_ZN15b2ContactSolver24SolvePositionConstraintsEv+0x46c>
 *   @0x2e2f68 ldr r1, [r7, #0x18]
 *   @0x2e2f6c mov r6, #0
 *   @0x2e2f70 vldr s27, [pc, #992]
 *   @0x2e2f74 ldr r4, [r7, #0x24]
 *   @0x2e2f78 mov r3, #88
 *   @0x2e2f7c mla r4, r3, r6, r4
 *   @0x2e2f80 vldr s7, [r4, #48]
 *   @0x2e2f84 vldr s10, [r4, #52]
 *   @0x2e2f88 vstr s7, [sp, #24]
 *   @0x2e2f8c vstr s10, [sp, #20]
 *   @0x2e2f90 vldr s13, [r4, #64]
 *   @0x2e2f94 vldr s14, [r4, #56]
 *   @0x2e2f98 vldr s15, [r4, #60]
 *   @0x2e2f9c vldr s7, [r4, #44]
 *   @0x2e2fa0 vldr s10, [r4, #68]
 *   @0x2e2fa4 vldr s26, [r4, #40]
 *   @0x2e2fa8 vstr s13, [sp, #4]
 *   @0x2e2fac ldr r9, [r4, #0x20]
 *   @0x2e2fb0 vstr s14, [sp, #16]
 *   @0x2e2fb4 ldr r8, [r4, #0x24]
 *   @0x2e2fb8 vstr s15, [sp, #12]
 *   @0x2e2fbc ldr r5, [r4, #0x54]
 *   @0x2e2fc0 vstr s7, [sp]
 *   @0x2e2fc4 add r9, r9, r9, lsl #1
 *   @0x2e2fc8 vstr s10, [sp, #8]
 *   @0x2e2fcc add r8, r8, r8, lsl #1
 *   @0x2e2fd0 cmp r5, #0
 *   @0x2e2fd4 lsl r9, r9, #2
 *   @0x2e2fd8 lsl r8, r8, #2
 *   @0x2e2fdc add r2, r1, r9
 *   @0x2e2fe0 add r3, r1, r8
 *   @0x2e2fe4 vldr s24, [r2]
 *   @0x2e2fe8 vldr s23, [r2, #4]
 *   @0x2e2fec vldr s22, [r2, #8]
 *   @0x2e2ff0 vldr s21, [r3]
 *   @0x2e2ff4 vldr s20, [r3, #4]
 *   @0x2e2ff8 vldr s19, [r3, #8]
 *   @0x2e2ffc ble 0x2e3374 <_ZN15b2ContactSolver24SolvePositionConstraintsEv+0x428>
 *   @0x2e3000 vadd.f32 s13, s26, s7
 *   @0x2e3004 mov r10, r4
 *   @0x2e3008 mov r11, #0
 *   @0x2e300c vstr s13, [sp, #28]
 *   @0x2e3010 b 0x2e30a8 <_ZN15b2ContactSolver24SolvePositionConstraintsEv+0x15c>
 *   @0x2e3014 vldr s15, [pc, #828]
 *   @0x2e3018 vmul.f32 s13, s11, s30
 *   @0x2e301c vldr s7, [sp, #4]
 *   @0x2e3020 add r11, r11, #1
 *   @0x2e3024 add r10, r10, #8
 *   @0x2e3028 vnmls.f32 s13, s9, s29
 *   @0x2e302c vmul.f32 s14, s12, s30
 *   @0x2e3030 vmul.f32 s8, s7, s13
 *   @0x2e3034 vldr s7, [sp, #28]
 *   @0x2e3038 vnmls.f32 s14, s10, s29
 *   @0x2e303c vmla.f32 s7, s8, s13
 *   @0x2e3040 vmov.f32 s13, s7
 *   @0x2e3044 vldr s7, [sp, #8]
 *   @0x2e3048 vmul.f32 s8, s7, s14
 *   @0x2e304c vldr s7, [sp]
 *   @0x2e3050 vmla.f32 s13, s8, s14
 *   @0x2e3054 vcmpe.f32 s13, #0
 *   @0x2e3058 vmrs APSR_nzcv, fpscr
 *   @0x2e305c vneggt.f32 s15, s15
 *   @0x2e3060 vldrle s15, [pc, #752]
 *   @0x2e3064 vdivgt.f32 s15, s15, s13
 *   @0x2e3068 cmp r11, r5
 *   @0x2e306c vldr s13, [sp, #8]
 *   @0x2e3070 vmul.f32 s14, s15, s30
 *   @0x2e3074 vmul.f32 s15, s15, s29
 *   @0x2e3078 vmul.f32 s11, s11, s14
 *   @0x2e307c vmul.f32 s12, s12, s14
 *   @0x2e3080 vnmls.f32 s11, s9, s15
 *   @0x2e3084 vnmls.f32 s12, s10, s15
 *   @0x2e3088 vldr s10, [sp, #4]
 *   @0x2e308c vmla.f32 s19, s13, s12
 *   @0x2e3090 vmls.f32 s22, s10, s11
 *   @0x2e3094 vmls.f32 s24, s26, s14
 *   @0x2e3098 vmls.f32 s23, s26, s15
 *   @0x2e309c vmla.f32 s21, s7, s14
 *   @0x2e30a0 vmla.f32 s20, s7, s15
 *   @0x2e30a4 beq 0x2e3364 <_ZN15b2ContactSolver24SolvePositionConstraintsEv+0x418>
 *   @0x2e30a8 vmov r0, s22
 *   @0x2e30ac bl 0xb6580 <sinf@plt>
 *   @0x2e30b0 vmov s18, r0
 *   @0x2e30b4 vmov r0, s22
 *   @0x2e30b8 bl 0xb658c <cosf@plt>
 *   @0x2e30bc vmov s17, r0
 *   @0x2e30c0 vmov r0, s19
 *   @0x2e30c4 bl 0xb6580 <sinf@plt>
 *   @0x2e30c8 vmov s16, r0
 *   @0x2e30cc vmov r0, s19
 *   @0x2e30d0 bl 0xb658c <cosf@plt>
 *   @0x2e30d4 vldr s14, [sp, #20]
 *   @0x2e30d8 vldr s7, [sp, #12]
 *   @0x2e30dc vmul.f32 s11, s14, s18
 *   @0x2e30e0 vldr s10, [sp, #24]
 *   @0x2e30e4 ldr r3, [r4, #0x48]
 *   @0x2e30e8 cmp r3, #1
 *   @0x2e30ec vmul.f32 s12, s14, s17
 *   @0x2e30f0 vmul.f32 s13, s7, s16
 *   @0x2e30f4 vmov s15, r0
 *   @0x2e30f8 vmul.f32 s14, s7, s15
 *   @0x2e30fc vldr s7, [sp, #16]
 *   @0x2e3100 vnmls.f32 s11, s10, s17
 *   @0x2e3104 vmla.f32 s12, s10, s18
 *   @0x2e3108 vnmls.f32 s13, s7, s15
 *   @0x2e310c vmla.f32 s14, s7, s16
 *   @0x2e3110 vsub.f32 s11, s24, s11
 *   @0x2e3114 vsub.f32 s12, s23, s12
 *   @0x2e3118 vsub.f32 s13, s21, s13
 *   @0x2e311c vsub.f32 s14, s20, s14
 *   @0x2e3120 beq 0x2e32dc <_ZN15b2ContactSolver24SolvePositionConstraintsEv+0x390>
 *   @0x2e3124 cmp r3, #2
 *   @0x2e3128 beq 0x2e3258 <_ZN15b2ContactSolver24SolvePositionConstraintsEv+0x30c>
 *   @0x2e312c cmp r3, #0
 *   @0x2e3130 beq 0x2e3198 <_ZN15b2ContactSolver24SolvePositionConstraintsEv+0x24c>
 *   @0x2e3134 movw r3, #0xd70a
 *   @0x2e3138 movt r3, #0x3ba3
 *   @0x2e313c vcmpe.f32 s28, s27
 *   @0x2e3140 vmov s7, r3
 *   @0x2e3144 movw r3, #0xcccd
 *   @0x2e3148 movt r3, #0x3e4c
 *   @0x2e314c vadd.f32 s15, s28, s7
 *   @0x2e3150 vmrs APSR_nzcv, fpscr
 *   @0x2e3154 vmov s7, r3
 *   @0x2e3158 vmul.f32 s15, s15, s7
 *   @0x2e315c vcmpe.f32 s15, #0
 *   @0x2e3160 vmovle.f32 s27, s28
 *   @0x2e3164 vmrs APSR_nzcv, fpscr
 *   @0x2e3168 vsub.f32 s9, s25, s24
 *   @0x2e316c vsub.f32 s11, s31, s23
 *   @0x2e3170 vsub.f32 s10, s25, s21
 *   @0x2e3174 vsub.f32 s12, s31, s20
 *   @0x2e3178 bpl 0x2e3014 <_ZN15b2ContactSolver24SolvePositionConstraintsEv+0xc8>
 *   @0x2e317c movw r3, #0xcccd
 *   @0x2e3180 movt r3, #0xbe4c
 *   @0x2e3184 vmov s7, r3
 *   @0x2e3188 vcmpe.f32 s15, s7
 *   @0x2e318c vmrs APSR_nzcv, fpscr
 *   @0x2e3190 vldrmi s15, [pc, #452]
 *   @0x2e3194 b 0x2e3018 <_ZN15b2ContactSolver24SolvePositionConstraintsEv+0xcc>
 *   @0x2e3198 vldr s25, [r4, #28]
 *   @0x2e319c vldr s10, [r4, #4]
 *   @0x2e31a0 vmul.f32 s31, s17, s25
 *   @0x2e31a4 vldr s7, [r4, #24]
 *   @0x2e31a8 vldr s8, [r4]
 *   @0x2e31ac vmul.f32 s9, s15, s10
 *   @0x2e31b0 vmul.f32 s25, s18, s25
 *   @0x2e31b4 vmul.f32 s10, s16, s10
 *   @0x2e31b8 vmla.f32 s31, s18, s7
 *   @0x2e31bc vmla.f32 s9, s16, s8
 *   @0x2e31c0 vnmls.f32 s25, s17, s7
 *   @0x2e31c4 vnmls.f32 s10, s15, s8
 *   @0x2e31c8 vadd.f32 s31, s12, s31
 *   @0x2e31cc vadd.f32 s16, s14, s9
 *   @0x2e31d0 vsub.f32 s29, s16, s31
 *   @0x2e31d4 vadd.f32 s25, s11, s25
 *   @0x2e31d8 vadd.f32 s17, s13, s10
 *   @0x2e31dc vmul.f32 s28, s29, s29
 *   @0x2e31e0 vsub.f32 s30, s17, s25
 *   @0x2e31e4 vmla.f32 s28, s30, s30
 *   @0x2e31e8 vsqrt.f32 s15, s28
 *   @0x2e31ec vcmp.f32 s15, s15
 *   @0x2e31f0 vmrs APSR_nzcv, fpscr
 *   @0x2e31f4 bne 0x2e33c8 <_ZN15b2ContactSolver24SolvePositionConstraintsEv+0x47c>
 *   @0x2e31f8 mov r3, #872415232
 *   @0x2e31fc vmov s7, r3
 *   @0x2e3200 vcmpe.f32 s15, s7
 *   @0x2e3204 vmrs APSR_nzcv, fpscr
 *   @0x2e3208 bmi 0x2e322c <_ZN15b2ContactSolver24SolvePositionConstraintsEv+0x2e0>
 *   @0x2e320c vmov.f32 s14, #1.000000e+00
 *   @0x2e3210 vdiv.f32 s15, s14, s15
 *   @0x2e3214 vmul.f32 s14, s29, s15
 *   @0x2e3218 vmul.f32 s15, s30, s15
 *   @0x2e321c vmul.f32 s28, s29, s14
 *   @0x2e3220 vmov.f32 s29, s14
 *   @0x2e3224 vmla.f32 s28, s30, s15
 *   @0x2e3228 vmov.f32 s30, s15
 *   @0x2e322c vldr s14, [r4, #76]
 *   @0x2e3230 mov r3, #1056964608
 *   @0x2e3234 vmov s7, r3
 *   @0x2e3238 vldr s15, [r4, #80]
 *   @0x2e323c vadd.f32 s25, s25, s17
 *   @0x2e3240 vadd.f32 s31, s31, s16
 *   @0x2e3244 vsub.f32 s28, s28, s14
 *   @0x2e3248 vmul.f32 s25, s25, s7
 *   @0x2e324c vmul.f32 s31, s31, s7
 *   @0x2e3250 vsub.f32 s28, s28, s15
 *   @0x2e3254 b 0x2e3134 <_ZN15b2ContactSolver24SolvePositionConstraintsEv+0x1e8>
 *   @0x2e3258 vldr s10, [r4, #28]
 *   @0x2e325c vldr s25, [r10, #4]
 *   @0x2e3260 vmul.f32 s9, s15, s10
 *   @0x2e3264 vldr s8, [r10]
 *   @0x2e3268 vldr s7, [r4, #24]
 *   @0x2e326c vldr s30, [r4, #20]
 *   @0x2e3270 vldr s28, [r4, #76]
 *   @0x2e3274 vmul.f32 s31, s17, s25
 *   @0x2e3278 vmul.f32 s10, s16, s10
 *   @0x2e327c vmla.f32 s31, s18, s8
 *   @0x2e3280 vmla.f32 s9, s16, s7
 *   @0x2e3284 vmul.f32 s25, s18, s25
 *   @0x2e3288 vmul.f32 s29, s15, s30
 *   @0x2e328c vnmls.f32 s25, s17, s8
 *   @0x2e3290 vldr s8, [r4, #16]
 *   @0x2e3294 vnmls.f32 s10, s15, s7
 *   @0x2e3298 vmla.f32 s29, s16, s8
 *   @0x2e329c vmul.f32 s30, s16, s30
 *   @0x2e32a0 vadd.f32 s31, s12, s31
 *   @0x2e32a4 vldr s12, [r4, #80]
 *   @0x2e32a8 vadd.f32 s14, s14, s9
 *   @0x2e32ac vsub.f32 s14, s31, s14
 *   @0x2e32b0 vnmls.f32 s30, s15, s8
 *   @0x2e32b4 vadd.f32 s13, s13, s10
 *   @0x2e32b8 vadd.f32 s25, s11, s25
 *   @0x2e32bc vmul.f32 s14, s29, s14
 *   @0x2e32c0 vsub.f32 s13, s25, s13
 *   @0x2e32c4 vmla.f32 s14, s30, s13
 *   @0x2e32c8 vsub.f32 s28, s14, s28
 *   @0x2e32cc vneg.f32 s30, s30
 *   @0x2e32d0 vsub.f32 s28, s28, s12
 *   @0x2e32d4 vneg.f32 s29, s29
 *   @0x2e32d8 b 0x2e3134 <_ZN15b2ContactSolver24SolvePositionConstraintsEv+0x1e8>
 *   @0x2e32dc vldr s10, [r4, #28]
 *   @0x2e32e0 vldr s25, [r10, #4]
 *   @0x2e32e4 vmul.f32 s9, s17, s10
 *   @0x2e32e8 vldr s7, [r4, #24]
 *   @0x2e32ec vldr s8, [r10]
 *   @0x2e32f0 vldr s30, [r4, #20]
 *   @0x2e32f4 vldr s28, [r4, #76]
 *   @0x2e32f8 vmul.f32 s31, s15, s25
 *   @0x2e32fc vmul.f32 s10, s18, s10
 *   @0x2e3300 vmla.f32 s9, s18, s7
 *   @0x2e3304 vmul.f32 s25, s16, s25
 *   @0x2e3308 vmla.f32 s31, s16, s8
 *   @0x2e330c vmul.f32 s29, s17, s30
 *   @0x2e3310 vnmls.f32 s25, s15, s8
 *   @0x2e3314 vldr s15, [r4, #16]
 *   @0x2e3318 vnmls.f32 s10, s17, s7
 *   @0x2e331c vmul.f32 s30, s18, s30
 *   @0x2e3320 vmla.f32 s29, s18, s15
 *   @0x2e3324 vadd.f32 s31, s14, s31
 *   @0x2e3328 vldr s14, [r4, #80]
 *   @0x2e332c vadd.f32 s12, s12, s9
 *   @0x2e3330 vsub.f32 s12, s31, s12
 *   @0x2e3334 vnmls.f32 s30, s17, s15
 *   @0x2e3338 vadd.f32 s11, s11, s10
 *   @0x2e333c vadd.f32 s25, s13, s25
 *   @0x2e3340 vmul.f32 s12, s29, s12
 *   @0x2e3344 vsub.f32 s11, s25, s11
 *   @0x2e3348 vmla.f32 s12, s30, s11
 *   @0x2e334c vsub.f32 s28, s12, s28
 *   @0x2e3350 vsub.f32 s28, s28, s14
 *   @0x2e3354 b 0x2e3134 <_ZN15b2ContactSolver24SolvePositionConstraintsEv+0x1e8>
 *   @0x2e3358 andeq r0, r0, r0
 *   @0x2e335c cdplt p12, #0x4, c12, c12, c13, #0x6
 *   @0x2e3360 ldcllt p2, c12, [r5], #-572
 *   @0x2e3364 ldr r1, [r7, #0x18]
 *   @0x2e3368 ldr r0, [r7, #0x30]
 *   @0x2e336c add r2, r1, r9
 *   @0x2e3370 add r3, r1, r8
 *   @0x2e3374 add r6, r6, #1
 *   @0x2e3378 vstr s24, [r2]
 *   @0x2e337c cmp r0, r6
 *   @0x2e3380 vstr s23, [r2, #4]
 *   @0x2e3384 vstr s22, [r2, #8]
 *   @0x2e3388 vstr s21, [r3]
 *   @0x2e338c vstr s20, [r3, #4]
 *   @0x2e3390 vstr s19, [r3, #8]
 *   @0x2e3394 bgt 0x2e2f74 <_ZN15b2ContactSolver24SolvePositionConstraintsEv+0x28>
 *   @0x2e3398 vldr s15, [pc, #-64]
 *   @0x2e339c vcmpe.f32 s27, s15
 *   @0x2e33a0 vmrs APSR_nzcv, fpscr
 *   @0x2e33a4 movlt r0, #0
 *   @0x2e33a8 movge r0, #1
 *   @0x2e33ac add sp, sp, #36
 *   @0x2e33b0 vpop {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x2e33b4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2e33b8 mov r0, #1
 *   @0x2e33bc add sp, sp, #36
 *   @0x2e33c0 vpop {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x2e33c4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2e33c8 vmov r0, s28
 *   @0x2e33cc bl 0xb6700 <sqrtf@plt>
 *   @0x2e33d0 vmov s15, r0
 *   @0x2e33d4 b 0x2e31f8 <_ZN15b2ContactSolver24SolvePositionConstraintsEv+0x2ac>
 *
 * ══ §18/25 b2World::Solve  0x2c963c  size 1144  286 条（0x2c963c..0x2c9ab4）
 * @func 0x2c963c 0x2c9ab4  size 1144  286 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Island::b2Island(int, int, int, b2StackAllocator*, b2ContactListener*) / b2StackAllocator::Allocate(int) / b2Island::Solve(b2Profile*, b2TimeStep const&, b2Vec2 const&, bool) / b2World::Solve(b2TimeStep const&)+0x2dc / b2StackAllocator::Free(void*) / b2Timer::b2Timer() / b2Body::SynchronizeFixtures() / b2ContactManager::FindNewContacts()
 * 字段偏移 top8: 0x4×17 / 0x70×8 / 0xc×8 / 0x2c×4 / 0x10×4 / 0x2×4 / 0x18×3 / 0x3c×3
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c963c movw r3, #0x9228
 *   @0x2c9640 movt r3, #0x1
 *   @0x2c9644 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2c9648 vpush {d8}
 *   @0x2c964c sub sp, sp, #140
 *   @0x2c9650 ldr r12, [r0, r3]
 *   @0x2c9654 mov r7, r0
 *   @0x2c9658 str r1, [sp, #0x28]
 *   @0x2c965c cmp r12, #0
 *   @0x2c9660 beq 0x2c9680 <_ZN7b2World5SolveERK10b2TimeStep+0x44>
 *   @0x2c9664 add r3, r12, #12
 *   @0x2c9668 add lr, r12, #28
 *   @0x2c966c ldr r12, [r12, #0x70]
 *   @0x2c9670 ldm r3, {r0, r1, r2, r3}
 *   @0x2c9674 cmp r12, #0
 *   @0x2c9678 stm lr, {r0, r1, r2, r3}
 *   @0x2c967c bne 0x2c9664 <_ZN7b2World5SolveERK10b2TimeStep+0x28>
 *   @0x2c9680 add r11, r7, #102400
 *   @0x2c9684 movw r0, #0x9220
 *   @0x2c9688 str r11, [sp, #0xc]
 *   @0x2c968c movt r0, #0x1
 *   @0x2c9690 add r10, sp, #84
 *   @0x2c9694 str r10, [sp, #0x14]
 *   @0x2c9698 ldr r10, [sp, #0xc]
 *   @0x2c969c mov r8, r11
 *   @0x2c96a0 ldr r0, [r7, r0]
 *   @0x2c96a4 movw r1, #0x9230
 *   @0x2c96a8 add r10, r10, #616
 *   @0x2c96ac movw r2, #0x9218
 *   @0x2c96b0 movt r1, #0x1
 *   @0x2c96b4 movt r2, #0x1
 *   @0x2c96b8 movw r3, #0x9234
 *   @0x2c96bc add r11, r11, #608
 *   @0x2c96c0 movt r3, #0x1
 *   @0x2c96c4 add r8, r8, #612
 *   @0x2c96c8 ldr r1, [r7, r1]
 *   @0x2c96cc mov r12, #0
 *   @0x2c96d0 ldr r3, [r7, r3]
 *   @0x2c96d4 ldr r2, [r7, r2]
 *   @0x2c96d8 str r12, [r11]
 *   @0x2c96dc str r0, [sp, #0x4]
 *   @0x2c96e0 add r0, sp, #84
 *   @0x2c96e4 str r12, [r8]
 *   @0x2c96e8 str r12, [r10]
 *   @0x2c96ec add r12, r7, #68
 *   @0x2c96f0 str r12, [sp]
 *   @0x2c96f4 str r10, [sp, #0xc]
 *   @0x2c96f8 str r12, [sp, #0x18]
 *   @0x2c96fc bl 0x2e1130 <_ZN8b2IslandC2EiiiP16b2StackAllocatorP17b2ContactListener>
 *   @0x2c9700 movw r3, #0x9228
 *   @0x2c9704 movt r3, #0x1
 *   @0x2c9708 ldr r3, [r7, r3]
 *   @0x2c970c cmp r3, #0
 *   @0x2c9710 beq 0x2c972c <_ZN7b2World5SolveERK10b2TimeStep+0xf0>
 *   @0x2c9714 ldrh r2, [r3, #4]
 *   @0x2c9718 bic r2, r2, #1
 *   @0x2c971c strh r2, [r3, #4]
 *   @0x2c9720 ldr r3, [r3, #0x70]
 *   @0x2c9724 cmp r3, #0
 *   @0x2c9728 bne 0x2c9714 <_ZN7b2World5SolveERK10b2TimeStep+0xd8>
 *   @0x2c972c movw r3, #0x9214
 *   @0x2c9730 movt r3, #0x1
 *   @0x2c9734 ldr r3, [r7, r3]
 *   @0x2c9738 cmp r3, #0
 *   @0x2c973c beq 0x2c9758 <_ZN7b2World5SolveERK10b2TimeStep+0x11c>
 *   @0x2c9740 ldr r2, [r3, #0x4]
 *   @0x2c9744 bic r2, r2, #1
 *   @0x2c9748 str r2, [r3, #0x4]
 *   @0x2c974c ldr r3, [r3, #0xc]
 *   @0x2c9750 cmp r3, #0
 *   @0x2c9754 bne 0x2c9740 <_ZN7b2World5SolveERK10b2TimeStep+0x104>
 *   @0x2c9758 movw r3, #0x922c
 *   @0x2c975c movt r3, #0x1
 *   @0x2c9760 ldr r3, [r7, r3]
 *   @0x2c9764 cmp r3, #0
 *   @0x2c9768 movne r2, #0
 *   @0x2c976c beq 0x2c9780 <_ZN7b2World5SolveERK10b2TimeStep+0x144>
 *   @0x2c9770 strb r2, [r3, #0x3c]
 *   @0x2c9774 ldr r3, [r3, #0xc]
 *   @0x2c9778 cmp r3, #0
 *   @0x2c977c bne 0x2c9770 <_ZN7b2World5SolveERK10b2TimeStep+0x134>
 *   @0x2c9780 movw r3, #0x9230
 *   @0x2c9784 movt r3, #0x1
 *   @0x2c9788 ldr r0, [sp, #0x18]
 *   @0x2c978c ldr r1, [r7, r3]
 *   @0x2c9790 lsl r1, r1, #2
 *   @0x2c9794 bl 0x2e0f44 <_ZN16b2StackAllocator8AllocateEi>
 *   @0x2c9798 movw r3, #0x9228
 *   @0x2c979c movt r3, #0x1
 *   @0x2c97a0 ldr r4, [r7, r3]
 *   @0x2c97a4 cmp r4, #0
 *   @0x2c97a8 addeq r10, sp, #52
 *   @0x2c97ac addeq r12, r7, #102400
 *   @0x2c97b0 streq r10, [sp, #0x10]
 *   @0x2c97b4 mov r6, r0
 *   @0x2c97b8 streq r12, [sp, #0x24]
 *   @0x2c97bc beq 0x2c9928 <_ZN7b2World5SolveERK10b2TimeStep+0x2ec>
 *   @0x2c97c0 add r10, r7, #102400
 *   @0x2c97c4 movw r12, #0x9240
 *   @0x2c97c8 str r10, [sp, #0x24]
 *   @0x2c97cc movt r12, #0x1
 *   @0x2c97d0 add r10, r10, #568
 *   @0x2c97d4 str r12, [sp, #0x1c]
 *   @0x2c97d8 str r10, [sp, #0x2c]
 *   @0x2c97dc add r12, sp, #52
 *   @0x2c97e0 vldr s16, [pc, #712]
 *   @0x2c97e4 str r12, [sp, #0x10]
 *   @0x2c97e8 str r7, [sp, #0x20]
 *   @0x2c97ec ldrh r3, [r4, #4]
 *   @0x2c97f0 ands r2, r3, #1
 *   @0x2c97f4 bne 0x2c9918 <_ZN7b2World5SolveERK10b2TimeStep+0x2dc>
 *   @0x2c97f8 and r1, r3, #34
 *   @0x2c97fc cmp r1, #34
 *   @0x2c9800 bne 0x2c9918 <_ZN7b2World5SolveERK10b2TimeStep+0x2dc>
 *   @0x2c9804 ldr r1, [r4]
 *   @0x2c9808 cmp r1, #0
 *   @0x2c980c beq 0x2c9918 <_ZN7b2World5SolveERK10b2TimeStep+0x2dc>
 *   @0x2c9810 str r2, [sp, #0x70]
 *   @0x2c9814 mov r7, r2
 *   @0x2c9818 str r2, [sp, #0x78]
 *   @0x2c981c orr r3, r3, #1
 *   @0x2c9820 str r2, [sp, #0x74]
 *   @0x2c9824 mov r5, r2
 *   @0x2c9828 str r4, [r6]
 *   @0x2c982c mov r0, r2
 *   @0x2c9830 strh r3, [r4, #4]
 *   @0x2c9834 mov r2, #1
 *   @0x2c9838 b 0x2c9840 <_ZN7b2World5SolveERK10b2TimeStep+0x204>
 *   @0x2c983c mov r0, r1
 *   @0x2c9840 sub r2, r2, #1
 *   @0x2c9844 ldr lr, [sp, #0x5c]
 *   @0x2c9848 add r1, r0, #1
 *   @0x2c984c ldr r3, [r6, r2, lsl #2]
 *   @0x2c9850 ldrh r12, [r3, #4]
 *   @0x2c9854 str r0, [r3, #0x8]
 *   @0x2c9858 str r3, [lr, r0, lsl #2]
 *   @0x2c985c tst r12, #2
 *   @0x2c9860 ldr r0, [r3]
 *   @0x2c9864 orreq r12, r12, #2
 *   @0x2c9868 vstreq s16, [r3, #160]
 *   @0x2c986c strheq r12, [r3, #4]
 *   @0x2c9870 cmp r0, #0
 *   @0x2c9874 bne 0x2c99bc <_ZN7b2World5SolveERK10b2TimeStep+0x380>
 *   @0x2c9878 cmp r2, #0
 *   @0x2c987c bne 0x2c983c <_ZN7b2World5SolveERK10b2TimeStep+0x200>
 *   @0x2c9880 ldr r10, [sp, #0x1c]
 *   @0x2c9884 add r0, sp, #84
 *   @0x2c9888 ldr lr, [sp, #0x20]
 *   @0x2c988c ldr r3, [sp, #0x2c]
 *   @0x2c9890 str r1, [sp, #0x70]
 *   @0x2c9894 ldrb r12, [lr, r10]
 *   @0x2c9898 ldr r1, [sp, #0x10]
 *   @0x2c989c ldr r2, [sp, #0x28]
 *   @0x2c98a0 str r12, [sp]
 *   @0x2c98a4 str r7, [sp, #0x78]
 *   @0x2c98a8 str r5, [sp, #0x74]
 *   @0x2c98ac bl 0x2e15e8 <_ZN8b2Island5SolveEP9b2ProfileRK10b2TimeStepRK6b2Vec2b>
 *   @0x2c98b0 vldr s12, [r11]
 *   @0x2c98b4 vldr s11, [r8]
 *   @0x2c98b8 vldr s13, [sp, #64]
 *   @0x2c98bc ldr r10, [sp, #0xc]
 *   @0x2c98c0 vadd.f32 s12, s12, s13
 *   @0x2c98c4 vldr s14, [sp, #68]
 *   @0x2c98c8 vldr s13, [r10]
 *   @0x2c98cc vldr s15, [sp, #72]
 *   @0x2c98d0 ldr r0, [sp, #0x70]
 *   @0x2c98d4 cmp r0, #0
 *   @0x2c98d8 ldrgt r3, [sp, #0x5c]
 *   @0x2c98dc vadd.f32 s14, s11, s14
 *   @0x2c98e0 vstr s12, [r11]
 *   @0x2c98e4 vadd.f32 s15, s13, s15
 *   @0x2c98e8 vstr s14, [r8]
 *   @0x2c98ec addgt r0, r3, r0, lsl #2
 *   @0x2c98f0 vstr s15, [r10]
 *   @0x2c98f4 ble 0x2c9918 <_ZN7b2World5SolveERK10b2TimeStep+0x2dc>
 *   @0x2c98f8 ldr r2, [r3], #4
 *   @0x2c98fc ldr r1, [r2]
 *   @0x2c9900 cmp r1, #0
 *   @0x2c9904 ldrheq r1, [r2, #4]
 *   @0x2c9908 biceq r1, r1, #1
 *   @0x2c990c strheq r1, [r2, #4]
 *   @0x2c9910 cmp r3, r0
 *   @0x2c9914 bne 0x2c98f8 <_ZN7b2World5SolveERK10b2TimeStep+0x2bc>
 *   @0x2c9918 ldr r4, [r4, #0x70]
 *   @0x2c991c cmp r4, #0
 *   @0x2c9920 bne 0x2c97ec <_ZN7b2World5SolveERK10b2TimeStep+0x1b0>
 *   @0x2c9924 ldr r7, [sp, #0x20]
 *   @0x2c9928 ldr r0, [sp, #0x18]
 *   @0x2c992c mov r1, r6
 *   @0x2c9930 bl 0x2e0ffc <_ZN16b2StackAllocator4FreeEPv>
 *   @0x2c9934 ldr r0, [sp, #0x10]
 *   @0x2c9938 bl 0x2e10b8 <_ZN7b2TimerC2Ev>
 *   @0x2c993c movw r3, #0x9228
 *   @0x2c9940 movt r3, #0x1
 *   @0x2c9944 ldr r4, [r7, r3]
 *   @0x2c9948 cmp r4, #0
 *   @0x2c994c bne 0x2c9960 <_ZN7b2World5SolveERK10b2TimeStep+0x324>
 *   @0x2c9950 b 0x2c998c <_ZN7b2World5SolveERK10b2TimeStep+0x350>
 *   @0x2c9954 ldr r4, [r4, #0x70]
 *   @0x2c9958 cmp r4, #0
 *   @0x2c995c beq 0x2c998c <_ZN7b2World5SolveERK10b2TimeStep+0x350>
 *   @0x2c9960 ldrh r3, [r4, #4]
 *   @0x2c9964 tst r3, #1
 *   @0x2c9968 beq 0x2c9954 <_ZN7b2World5SolveERK10b2TimeStep+0x318>
 *   @0x2c996c ldr r3, [r4]
 *   @0x2c9970 cmp r3, #0
 *   @0x2c9974 beq 0x2c9954 <_ZN7b2World5SolveERK10b2TimeStep+0x318>
 *   @0x2c9978 mov r0, r4
 *   @0x2c997c bl 0x2c72cc <_ZN6b2Body19SynchronizeFixturesEv>
 *   @0x2c9980 ldr r4, [r4, #0x70]
 *   @0x2c9984 cmp r4, #0
 *   @0x2c9988 bne 0x2c9960 <_ZN7b2World5SolveERK10b2TimeStep+0x324>
 *   @0x2c998c ldr r12, [sp, #0x24]
 *   @0x2c9990 add r7, r7, #102400
 *   @0x2c9994 add r0, r12, #472
 *   @0x2c9998 bl 0x2c84d8 <_ZN16b2ContactManager15FindNewContactsEv>
 *   @0x2c999c ldr r0, [sp, #0x10]
 *   @0x2c99a0 bl 0x2e10cc <_ZNK7b2Timer15GetMillisecondsEv>
 *   @0x2c99a4 str r0, [r7, #0x26c]
 *   @0x2c99a8 add r0, sp, #84
 *   @0x2c99ac bl 0x2e11d8 <_ZN8b2IslandD2Ev>
 *   @0x2c99b0 add sp, sp, #140
 *   @0x2c99b4 vpop {d8}
 *   @0x2c99b8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2c99bc ldr r0, [r3, #0x80]
 *   @0x2c99c0 cmp r0, #0
 *   @0x2c99c4 beq 0x2c9a40 <_ZN7b2World5SolveERK10b2TimeStep+0x404>
 *   @0x2c99c8 ldr lr, [r0, #0x4]
 *   @0x2c99cc ldr r12, [lr, #0x4]
 *   @0x2c99d0 tst r12, #1
 *   @0x2c99d4 and r9, r12, #6
 *   @0x2c99d8 bne 0x2c9a34 <_ZN7b2World5SolveERK10b2TimeStep+0x3f8>
 *   @0x2c99dc cmp r9, #6
 *   @0x2c99e0 bne 0x2c9a34 <_ZN7b2World5SolveERK10b2TimeStep+0x3f8>
 *   @0x2c99e4 ldr r10, [lr, #0x34]
 *   @0x2c99e8 ldr r9, [lr, #0x30]
 *   @0x2c99ec ldrb r10, [r10, #0x2c]
 *   @0x2c99f0 ldrb r9, [r9, #0x2c]
 *   @0x2c99f4 orrs r9, r10, r9
 *   @0x2c99f8 bne 0x2c9a34 <_ZN7b2World5SolveERK10b2TimeStep+0x3f8>
 *   @0x2c99fc ldr r9, [sp, #0x60]
 *   @0x2c9a00 orr r12, r12, #1
 *   @0x2c9a04 add r10, r7, #1
 *   @0x2c9a08 str lr, [r9, r7, lsl #2]
 *   @0x2c9a0c mov r7, r10
 *   @0x2c9a10 ldr r9, [r0]
 *   @0x2c9a14 str r12, [lr, #0x4]
 *   @0x2c9a18 ldrh r12, [r9, #4]
 *   @0x2c9a1c tst r12, #1
 *   @0x2c9a20 streq r9, [r6, r2, lsl #2]
 *   @0x2c9a24 addeq r2, r2, #1
 *   @0x2c9a28 orr r12, r12, #1
 *   @0x2c9a2c movne r7, r10
 *   @0x2c9a30 strheq r12, [r9, #4]
 *   @0x2c9a34 ldr r0, [r0, #0xc]
 *   @0x2c9a38 cmp r0, #0
 *   @0x2c9a3c bne 0x2c99c8 <_ZN7b2World5SolveERK10b2TimeStep+0x38c>
 *   @0x2c9a40 ldr r3, [r3, #0x7c]
 *   @0x2c9a44 cmp r3, #0
 *   @0x2c9a48 beq 0x2c9878 <_ZN7b2World5SolveERK10b2TimeStep+0x23c>
 *   @0x2c9a4c ldr r0, [r3, #0x4]
 *   @0x2c9a50 ldrb r12, [r0, #0x3c]
 *   @0x2c9a54 cmp r12, #0
 *   @0x2c9a58 bne 0x2c9aa0 <_ZN7b2World5SolveERK10b2TimeStep+0x464>
 *   @0x2c9a5c ldr lr, [r3]
 *   @0x2c9a60 add r9, r5, #1
 *   @0x2c9a64 ldrh r12, [lr, #4]
 *   @0x2c9a68 tst r12, #32
 *   @0x2c9a6c beq 0x2c9aa0 <_ZN7b2World5SolveERK10b2TimeStep+0x464>
 *   @0x2c9a70 ldr r10, [sp, #0x64]
 *   @0x2c9a74 tst r12, #1
 *   @0x2c9a78 orr r12, r12, #1
 *   @0x2c9a7c str r0, [r10, r5, lsl #2]
 *   @0x2c9a80 mov r10, #1
 *   @0x2c9a84 ldr r0, [r3, #0x4]
 *   @0x2c9a88 mov r5, r9
 *   @0x2c9a8c movne r5, r9
 *   @0x2c9a90 strb r10, [r0, #0x3c]
 *   @0x2c9a94 streq lr, [r6, r2, lsl #2]
 *   @0x2c9a98 addeq r2, r2, #1
 *   @0x2c9a9c strheq r12, [lr, #4]
 *   @0x2c9aa0 ldr r3, [r3, #0xc]
 *   @0x2c9aa4 cmp r3, #0
 *   @0x2c9aa8 bne 0x2c9a4c <_ZN7b2World5SolveERK10b2TimeStep+0x410>
 *   @0x2c9aac b 0x2c9878 <_ZN7b2World5SolveERK10b2TimeStep+0x23c>
 *   @0x2c9ab0 andeq r0, r0, r0
 *
 * ══ §19/25 __divdi3  0x31b220  size 1144  286 条（0x31b220..0x31b698）
 * @func 0x31b220 0x31b698  size 1144  286 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __udivsi3×9 / __aeabi_uidivmod×8 / __divdi3+0x134
 * 字段偏移 top8: 0x4×7 / 0x8×7 / 0xc×6
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31b220 cmp r1, #0
 *   @0x31b224 mov r12, r2
 *   @0x31b228 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x31b22c mov r5, r0
 *   @0x31b230 sub sp, sp, #20
 *   @0x31b234 mov r7, r1
 *   @0x31b238 mov r8, r3
 *   @0x31b23c movge r4, #0
 *   @0x31b240 bge 0x31b258 <__divdi3+0x38>
 *   @0x31b244 rsbs r0, r0, #0
 *   @0x31b248 rsc r1, r1, #0
 *   @0x31b24c mvn r4, #0
 *   @0x31b250 mov r5, r0
 *   @0x31b254 mov r7, r1
 *   @0x31b258 cmp r3, #0
 *   @0x31b25c bge 0x31b274 <__divdi3+0x54>
 *   @0x31b260 rsbs r2, r2, #0
 *   @0x31b264 rsc r3, r3, #0
 *   @0x31b268 mvn r4, r4
 *   @0x31b26c mov r12, r2
 *   @0x31b270 mov r8, r3
 *   @0x31b274 cmp r8, #0
 *   @0x31b278 mov r6, r12
 *   @0x31b27c mov r9, r5
 *   @0x31b280 mov r10, r7
 *   @0x31b284 bne 0x31b514 <__divdi3+0x2f4>
 *   @0x31b288 cmp r12, r7
 *   @0x31b28c bls 0x31b354 <__divdi3+0x134>
 *   @0x31b290 clz r3, r12
 *   @0x31b294 cmp r3, #0
 *   @0x31b298 lslne r6, r12, r3
 *   @0x31b29c rsbne r2, r3, #32
 *   @0x31b2a0 lsrne r2, r5, r2
 *   @0x31b2a4 lslne r9, r5, r3
 *   @0x31b2a8 orrne r10, r2, r7, lsl r3
 *   @0x31b2ac lsr r5, r6, #16
 *   @0x31b2b0 uxth r8, r6
 *   @0x31b2b4 mov r0, r10
 *   @0x31b2b8 mov r1, r5
 *   @0x31b2bc bl 0x318c48 <__udivsi3>
 *   @0x31b2c0 mov r1, r5
 *   @0x31b2c4 mov r7, r0
 *   @0x31b2c8 mul r11, r8, r0
 *   @0x31b2cc mov r0, r10
 *   @0x31b2d0 bl 0x318cf0 <__aeabi_uidivmod>
 *   @0x31b2d4 lsr r3, r9, #16
 *   @0x31b2d8 orr r1, r3, r1, lsl #16
 *   @0x31b2dc cmp r1, r11
 *   @0x31b2e0 movhs r10, r7
 *   @0x31b2e4 bhs 0x31b300 <__divdi3+0xe0>
 *   @0x31b2e8 adds r1, r1, r6
 *   @0x31b2ec sub r10, r7, #1
 *   @0x31b2f0 bhs 0x31b300 <__divdi3+0xe0>
 *   @0x31b2f4 cmp r1, r11
 *   @0x31b2f8 sublo r10, r7, #2
 *   @0x31b2fc addlo r1, r1, r6
 *   @0x31b300 rsb r11, r11, r1
 *   @0x31b304 mov r1, r5
 *   @0x31b308 uxth r9, r9
 *   @0x31b30c mov r0, r11
 *   @0x31b310 bl 0x318c48 <__udivsi3>
 *   @0x31b314 mov r1, r5
 *   @0x31b318 mov r7, r0
 *   @0x31b31c mul r8, r8, r0
 *   @0x31b320 mov r0, r11
 *   @0x31b324 bl 0x318cf0 <__aeabi_uidivmod>
 *   @0x31b328 orr r1, r9, r1, lsl #16
 *   @0x31b32c cmp r1, r8
 *   @0x31b330 movhs r12, r7
 *   @0x31b334 bhs 0x31b34c <__divdi3+0x12c>
 *   @0x31b338 adds r6, r1, r6
 *   @0x31b33c sub r12, r7, #1
 *   @0x31b340 bhs 0x31b34c <__divdi3+0x12c>
 *   @0x31b344 cmp r6, r8
 *   @0x31b348 sublo r12, r7, #2
 *   @0x31b34c orr r12, r12, r10, lsl #16
 *   @0x31b350 b 0x31b668 <__divdi3+0x448>
 *   @0x31b354 cmp r12, #0
 *   @0x31b358 bne 0x31b36c <__divdi3+0x14c>
 *   @0x31b35c mov r0, #1
 *   @0x31b360 mov r1, r8
 *   @0x31b364 bl 0x318c48 <__udivsi3>
 *   @0x31b368 mov r6, r0
 *   @0x31b36c clz r3, r6
 *   @0x31b370 cmp r3, #0
 *   @0x31b374 rsbeq r3, r6, r7
 *   @0x31b378 moveq r5, #1
 *   @0x31b37c beq 0x31b45c <__divdi3+0x23c>
 *   @0x31b380 lsl r6, r6, r3
 *   @0x31b384 rsb r1, r3, #32
 *   @0x31b388 lsr r2, r7, r1
 *   @0x31b38c lsr r1, r5, r1
 *   @0x31b390 lsr r8, r6, #16
 *   @0x31b394 orr r7, r1, r7, lsl r3
 *   @0x31b398 mov r0, r2
 *   @0x31b39c lsl r9, r5, r3
 *   @0x31b3a0 mov r1, r8
 *   @0x31b3a4 str r2, [sp, #0x4]
 *   @0x31b3a8 bl 0x318c48 <__udivsi3>
 *   @0x31b3ac uxth r11, r6
 *   @0x31b3b0 ldr r2, [sp, #0x4]
 *   @0x31b3b4 mov r1, r8
 *   @0x31b3b8 mul r12, r11, r0
 *   @0x31b3bc mov r10, r0
 *   @0x31b3c0 mov r0, r2
 *   @0x31b3c4 str r12, [sp, #0xc]
 *   @0x31b3c8 bl 0x318cf0 <__aeabi_uidivmod>
 *   @0x31b3cc lsr r3, r7, #16
 *   @0x31b3d0 ldr r12, [sp, #0xc]
 *   @0x31b3d4 orr r1, r3, r1, lsl #16
 *   @0x31b3d8 cmp r1, r12
 *   @0x31b3dc movhs r5, r10
 *   @0x31b3e0 bhs 0x31b3fc <__divdi3+0x1dc>
 *   @0x31b3e4 adds r1, r1, r6
 *   @0x31b3e8 sub r5, r10, #1
 *   @0x31b3ec bhs 0x31b3fc <__divdi3+0x1dc>
 *   @0x31b3f0 cmp r1, r12
 *   @0x31b3f4 sublo r5, r10, #2
 *   @0x31b3f8 addlo r1, r1, r6
 *   @0x31b3fc rsb r3, r12, r1
 *   @0x31b400 mov r1, r8
 *   @0x31b404 str r3, [sp, #0x8]
 *   @0x31b408 uxth r7, r7
 *   @0x31b40c mov r0, r3
 *   @0x31b410 bl 0x318c48 <__udivsi3>
 *   @0x31b414 ldr r3, [sp, #0x8]
 *   @0x31b418 mov r1, r8
 *   @0x31b41c mov r10, r0
 *   @0x31b420 mul r11, r11, r0
 *   @0x31b424 mov r0, r3
 *   @0x31b428 bl 0x318cf0 <__aeabi_uidivmod>
 *   @0x31b42c orr r1, r7, r1, lsl #16
 *   @0x31b430 cmp r1, r11
 *   @0x31b434 movhs r2, r10
 *   @0x31b438 bhs 0x31b454 <__divdi3+0x234>
 *   @0x31b43c adds r1, r1, r6
 *   @0x31b440 sub r2, r10, #1
 *   @0x31b444 bhs 0x31b454 <__divdi3+0x234>
 *   @0x31b448 cmp r1, r11
 *   @0x31b44c sublo r2, r10, #2
 *   @0x31b450 addlo r1, r1, r6
 *   @0x31b454 rsb r3, r11, r1
 *   @0x31b458 orr r5, r2, r5, lsl #16
 *   @0x31b45c lsr r8, r6, #16
 *   @0x31b460 mov r0, r3
 *   @0x31b464 str r3, [sp, #0x8]
 *   @0x31b468 uxth r10, r6
 *   @0x31b46c mov r1, r8
 *   @0x31b470 bl 0x318c48 <__udivsi3>
 *   @0x31b474 ldr r3, [sp, #0x8]
 *   @0x31b478 mov r1, r8
 *   @0x31b47c mov r11, r0
 *   @0x31b480 mul r7, r10, r0
 *   @0x31b484 mov r0, r3
 *   @0x31b488 bl 0x318cf0 <__aeabi_uidivmod>
 *   @0x31b48c lsr r3, r9, #16
 *   @0x31b490 orr r1, r3, r1, lsl #16
 *   @0x31b494 cmp r1, r7
 *   @0x31b498 movhs r2, r11
 *   @0x31b49c bhs 0x31b4b8 <__divdi3+0x298>
 *   @0x31b4a0 adds r1, r1, r6
 *   @0x31b4a4 sub r2, r11, #1
 *   @0x31b4a8 bhs 0x31b4b8 <__divdi3+0x298>
 *   @0x31b4ac cmp r1, r7
 *   @0x31b4b0 sublo r2, r11, #2
 *   @0x31b4b4 addlo r1, r1, r6
 *   @0x31b4b8 rsb r11, r7, r1
 *   @0x31b4bc mov r1, r8
 *   @0x31b4c0 str r2, [sp, #0x4]
 *   @0x31b4c4 uxth r9, r9
 *   @0x31b4c8 mov r0, r11
 *   @0x31b4cc bl 0x318c48 <__udivsi3>
 *   @0x31b4d0 mov r1, r8
 *   @0x31b4d4 mov r7, r0
 *   @0x31b4d8 mul r10, r10, r0
 *   @0x31b4dc mov r0, r11
 *   @0x31b4e0 bl 0x318cf0 <__aeabi_uidivmod>
 *   @0x31b4e4 ldr r2, [sp, #0x4]
 *   @0x31b4e8 orr r1, r9, r1, lsl #16
 *   @0x31b4ec cmp r1, r10
 *   @0x31b4f0 movhs r12, r7
 *   @0x31b4f4 bhs 0x31b50c <__divdi3+0x2ec>
 *   @0x31b4f8 adds r6, r1, r6
 *   @0x31b4fc sub r12, r7, #1
 *   @0x31b500 bhs 0x31b50c <__divdi3+0x2ec>
 *   @0x31b504 cmp r6, r10
 *   @0x31b508 sublo r12, r7, #2
 *   @0x31b50c orr r12, r12, r2, lsl #16
 *   @0x31b510 b 0x31b678 <__divdi3+0x458>
 *   @0x31b514 cmp r8, r7
 *   @0x31b518 bhi 0x31b670 <__divdi3+0x450>
 *   @0x31b51c clz r9, r8
 *   @0x31b520 cmp r9, #0
 *   @0x31b524 bne 0x31b548 <__divdi3+0x328>
 *   @0x31b528 cmp r7, r8
 *   @0x31b52c cmpls r5, r12
 *   @0x31b530 movlo r5, #0
 *   @0x31b534 movhs r5, #1
 *   @0x31b538 movhs r12, #1
 *   @0x31b53c movhs r5, r9
 *   @0x31b540 bhs 0x31b678 <__divdi3+0x458>
 *   @0x31b544 b 0x31b674 <__divdi3+0x454>
 *   @0x31b548 rsb r3, r9, #32
 *   @0x31b54c lsl r10, r12, r9
 *   @0x31b550 lsr r6, r12, r3
 *   @0x31b554 lsr r2, r7, r3
 *   @0x31b558 orr r6, r6, r8, lsl r9
 *   @0x31b55c lsr r3, r5, r3
 *   @0x31b560 mov r0, r2
 *   @0x31b564 orr r7, r3, r7, lsl r9
 *   @0x31b568 lsr r8, r6, #16
 *   @0x31b56c str r2, [sp, #0x4]
 *   @0x31b570 uxth r11, r6
 *   @0x31b574 mov r1, r8
 *   @0x31b578 bl 0x318c48 <__udivsi3>
 *   @0x31b57c ldr r2, [sp, #0x4]
 *   @0x31b580 mov r1, r8
 *   @0x31b584 mul r12, r11, r0
 *   @0x31b588 mov r3, r0
 *   @0x31b58c mov r0, r2
 *   @0x31b590 str r3, [sp, #0x8]
 *   @0x31b594 str r12, [sp, #0xc]
 *   @0x31b598 bl 0x318cf0 <__aeabi_uidivmod>
 *   @0x31b59c lsr r2, r7, #16
 *   @0x31b5a0 ldr r12, [sp, #0xc]
 *   @0x31b5a4 ldr r3, [sp, #0x8]
 *   @0x31b5a8 orr r1, r2, r1, lsl #16
 *   @0x31b5ac cmp r1, r12
 *   @0x31b5b0 movhs r2, r3
 *   @0x31b5b4 bhs 0x31b5d0 <__divdi3+0x3b0>
 *   @0x31b5b8 adds r1, r1, r6
 *   @0x31b5bc sub r2, r3, #1
 *   @0x31b5c0 bhs 0x31b5d0 <__divdi3+0x3b0>
 *   @0x31b5c4 cmp r1, r12
 *   @0x31b5c8 sublo r2, r3, #2
 *   @0x31b5cc addlo r1, r1, r6
 *   @0x31b5d0 rsb r12, r12, r1
 *   @0x31b5d4 mov r1, r8
 *   @0x31b5d8 str r2, [sp, #0x4]
 *   @0x31b5dc uxth r7, r7
 *   @0x31b5e0 mov r0, r12
 *   @0x31b5e4 str r12, [sp, #0xc]
 *   @0x31b5e8 bl 0x318c48 <__udivsi3>
 *   @0x31b5ec ldr r12, [sp, #0xc]
 *   @0x31b5f0 mov r1, r8
 *   @0x31b5f4 mov r3, r0
 *   @0x31b5f8 str r3, [sp, #0x8]
 *   @0x31b5fc mul r11, r11, r0
 *   @0x31b600 mov r0, r12
 *   @0x31b604 bl 0x318cf0 <__aeabi_uidivmod>
 *   @0x31b608 ldmib sp, {r2, r3}
 *   @0x31b60c orr r1, r7, r1, lsl #16
 *   @0x31b610 cmp r1, r11
 *   @0x31b614 movhs r12, r3
 *   @0x31b618 bhs 0x31b634 <__divdi3+0x414>
 *   @0x31b61c adds r1, r1, r6
 *   @0x31b620 sub r12, r3, #1
 *   @0x31b624 bhs 0x31b634 <__divdi3+0x414>
 *   @0x31b628 cmp r1, r11
 *   @0x31b62c sublo r12, r3, #2
 *   @0x31b630 addlo r1, r1, r6
 *   @0x31b634 orr r12, r12, r2, lsl #16
 *   @0x31b638 rsb r11, r11, r1
 *   @0x31b63c umull r2, r3, r12, r10
 *   @0x31b640 cmp r3, r11
 *   @0x31b644 bhi 0x31b664 <__divdi3+0x444>
 *   @0x31b648 movne r3, #0
 *   @0x31b64c moveq r3, #1
 *   @0x31b650 cmp r2, r5, lsl r9
 *   @0x31b654 movls r5, #0
 *   @0x31b658 andhi r5, r3, #1
 *   @0x31b65c cmp r5, #0
 *   @0x31b660 beq 0x31b678 <__divdi3+0x458>
 *   @0x31b664 sub r12, r12, #1
 *   @0x31b668 mov r5, #0
 *   @0x31b66c b 0x31b678 <__divdi3+0x458>
 *   @0x31b670 mov r5, #0
 *   @0x31b674 mov r12, r5
 *   @0x31b678 cmp r4, #0
 *   @0x31b67c mov r0, r12
 *   @0x31b680 mov r1, r5
 *   @0x31b684 beq 0x31b690 <__divdi3+0x470>
 *   @0x31b688 rsbs r0, r0, #0
 *   @0x31b68c rsc r1, r1, #0
 *   @0x31b690 add sp, sp, #20
 *   @0x31b694 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §20/25 vorbis_book_init_decode  0x22f604  size 1140  285 条（0x22f604..0x22fa78）
 * @func 0x22f604 0x22fa78  size 1140  285 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6544×4 / anon_22ea70×3 / vorbis_book_init_decode+0x324×2 / vorbis_book_init_decode+0x3e4×2 / 0xb65b0 / vorbis_book_init_decode+0x428 / _make_words / vorbis_book_init_decode+0xc0
 * 字段偏移 top8: 0x4×10 / 0x2×8 / 0x-30×6 / 0x8×5 / 0x14×4 / 0x-48×4 / 0x1c×3 / 0x24×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22f604 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x22f608 add r11, sp, #32
 *   @0x22f60c ldr r12, [pc, #0x45c]
 *   @0x22f610 sub sp, sp, #44
 *   @0x22f614 mov r7, r1
 *   @0x22f618 ldr r12, [pc, r12]
 *   @0x22f61c mov r1, #0
 *   @0x22f620 mov r2, #52
 *   @0x22f624 str r12, [r11, #-0x34]
 *   @0x22f628 ldr r3, [r12]
 *   @0x22f62c mov r4, r0
 *   @0x22f630 str r3, [r11, #-0x28]
 *   @0x22f634 bl 0xb65b0 <memset@plt>
 *   @0x22f638 ldr r1, [r7, #0x4]
 *   @0x22f63c cmp r1, #0
 *   @0x22f640 ble 0x22fa2c <vorbis_book_init_decode+0x428>
 *   @0x22f644 ldr r0, [r7, #0x8]
 *   @0x22f648 mov r5, #0
 *   @0x22f64c add r12, r0, r1, lsl #2
 *   @0x22f650 mov r3, r0
 *   @0x22f654 ldr r2, [r3], #4
 *   @0x22f658 cmp r2, #0
 *   @0x22f65c addgt r5, r5, #1
 *   @0x22f660 cmp r3, r12
 *   @0x22f664 bne 0x22f654 <vorbis_book_init_decode+0x50>
 *   @0x22f668 ldr r3, [r7]
 *   @0x22f66c cmp r5, #0
 *   @0x22f670 stmib r4, {r1, r5}
 *   @0x22f674 str r3, [r4]
 *   @0x22f678 beq 0x22f8f4 <vorbis_book_init_decode+0x2f0>
 *   @0x22f67c mov r2, r5
 *   @0x22f680 lsl r12, r5, #2
 *   @0x22f684 str r12, [r11, #-0x30]
 *   @0x22f688 bl 0x22eb14 <_make_words>
 *   @0x22f68c ldr r12, [r11, #-0x30]
 *   @0x22f690 add r12, r12, #14
 *   @0x22f694 str r12, [r11, #-0x40]
 *   @0x22f698 bic r3, r12, #7
 *   @0x22f69c sub sp, sp, r3
 *   @0x22f6a0 str sp, [r11, #-0x38]
 *   @0x22f6a4 subs r10, r0, #0
 *   @0x22f6a8 beq 0x22fa5c <vorbis_book_init_decode+0x458>
 *   @0x22f6ac sub r12, sp, #4
 *   @0x22f6b0 str r4, [r11, #-0x44]
 *   @0x22f6b4 mov r8, r10
 *   @0x22f6b8 mov r6, #0
 *   @0x22f6bc mov r4, r12
 *   @0x22f6c0 str r12, [r11, #-0x3c]
 *   @0x22f6c4 ldr r0, [r8]
 *   @0x22f6c8 add r6, r6, #1
 *   @0x22f6cc bl 0x22ea70 <res2_inverse+0x25c>
 *   @0x22f6d0 cmp r6, r5
 *   @0x22f6d4 mov r9, r8
 *   @0x22f6d8 str r0, [r8], #4
 *   @0x22f6dc str r9, [r4, #0x4]!
 *   @0x22f6e0 blt 0x22f6c4 <vorbis_book_init_decode+0xc0>
 *   @0x22f6e4 ldr r3, [pc, #0x388]
 *   @0x22f6e8 mov r2, #4
 *   @0x22f6ec ldr r0, [r11, #-0x38]
 *   @0x22f6f0 mov r1, r5
 *   @0x22f6f4 add r3, pc, r3
 *   @0x22f6f8 ldr r4, [r11, #-0x44]
 *   @0x22f6fc bl 0xb66dc <qsort@plt>
 *   @0x22f700 ldr r12, [r11, #-0x40]
 *   @0x22f704 ldr r0, [r11, #-0x30]
 *   @0x22f708 bic r9, r12, #7
 *   @0x22f70c sub sp, sp, r9
 *   @0x22f710 bl 0xb6544 <malloc@plt>
 *   @0x22f714 ldr r2, [r11, #-0x3c]
 *   @0x22f718 mov r9, sp
 *   @0x22f71c mov r3, #0
 *   @0x22f720 str r0, [r4, #0x14]
 *   @0x22f724 ldr r1, [r2, #0x4]!
 *   @0x22f728 rsb r1, r10, r1
 *   @0x22f72c asr r1, r1, #2
 *   @0x22f730 str r3, [r9, r1, lsl #2]
 *   @0x22f734 add r3, r3, #1
 *   @0x22f738 cmp r3, r5
 *   @0x22f73c blt 0x22f724 <vorbis_book_init_decode+0x120>
 *   @0x22f740 mov r3, #0
 *   @0x22f744 mov r2, r3
 *   @0x22f748 ldr r12, [r10, r3]
 *   @0x22f74c add r2, r2, #1
 *   @0x22f750 ldr r1, [r9, r3]
 *   @0x22f754 cmp r2, r5
 *   @0x22f758 add r3, r3, #4
 *   @0x22f75c str r12, [r0, r1, lsl #2]
 *   @0x22f760 blt 0x22f748 <vorbis_book_init_decode+0x144>
 *   @0x22f764 mov r0, r10
 *   @0x22f768 bl 0xb655c <free@plt>
 *   @0x22f76c mov r1, r5
 *   @0x22f770 mov r2, r9
 *   @0x22f774 add r3, r4, #12
 *   @0x22f778 mov r0, r7
 *   @0x22f77c bl 0x22ee18 <_book_unquantize>
 *   @0x22f780 str r0, [r4, #0x10]
 *   @0x22f784 ldr r0, [r11, #-0x30]
 *   @0x22f788 bl 0xb6544 <malloc@plt>
 *   @0x22f78c ldr lr, [r7, #0x4]
 *   @0x22f790 cmp lr, #0
 *   @0x22f794 str r0, [r4, #0x18]
 *   @0x22f798 ble 0x22fa48 <vorbis_book_init_decode+0x444>
 *   @0x22f79c ldr r1, [r7, #0x8]
 *   @0x22f7a0 mov r2, #0
 *   @0x22f7a4 mov r3, r2
 *   @0x22f7a8 sub r1, r1, #4
 *   @0x22f7ac ldr r12, [r1, #0x4]!
 *   @0x22f7b0 cmp r12, #0
 *   @0x22f7b4 ldrgt r12, [r9, r2, lsl #2]
 *   @0x22f7b8 addgt r2, r2, #1
 *   @0x22f7bc strgt r3, [r0, r12, lsl #2]
 *   @0x22f7c0 add r3, r3, #1
 *   @0x22f7c4 cmp r3, lr
 *   @0x22f7c8 bne 0x22f7ac <vorbis_book_init_decode+0x1a8>
 *   @0x22f7cc mov r0, r2
 *   @0x22f7d0 mov r6, #0
 *   @0x22f7d4 bl 0xb6544 <malloc@plt>
 *   @0x22f7d8 mov r3, r6
 *   @0x22f7dc str r0, [r4, #0x1c]
 *   @0x22f7e0 ldr r2, [r7, #0x8]
 *   @0x22f7e4 ldr r2, [r2, r3, lsl #2]
 *   @0x22f7e8 add r3, r3, #1
 *   @0x22f7ec cmp r2, #0
 *   @0x22f7f0 ldrgt r1, [r9, r6, lsl #2]
 *   @0x22f7f4 addgt r6, r6, #1
 *   @0x22f7f8 ldrgt r0, [r4, #0x1c]
 *   @0x22f7fc strbgt r2, [r0, r1]
 *   @0x22f800 ldr r2, [r7, #0x4]
 *   @0x22f804 cmp r2, r3
 *   @0x22f808 bgt 0x22f7e0 <vorbis_book_init_decode+0x1dc>
 *   @0x22f80c ldr r0, [r4, #0x8]
 *   @0x22f810 bl 0x22eaf0 <_ilog>
 *   @0x22f814 sub r7, r0, #4
 *   @0x22f818 cmp r7, #4
 *   @0x22f81c ble 0x22f914 <vorbis_book_init_decode+0x310>
 *   @0x22f820 cmp r7, #8
 *   @0x22f824 strle r7, [r4, #0x24]
 *   @0x22f828 movle r3, #1
 *   @0x22f82c movgt r3, #8
 *   @0x22f830 lslle r3, r3, r7
 *   @0x22f834 movgt r7, r3
 *   @0x22f838 movgt r0, #256
 *   @0x22f83c strle r3, [r11, #-0x30]
 *   @0x22f840 movle r0, r3
 *   @0x22f844 strgt r0, [r11, #-0x30]
 *   @0x22f848 strgt r3, [r4, #0x24]
 *   @0x22f84c mov r1, #4
 *   @0x22f850 mov r9, #0
 *   @0x22f854 bl 0xb6c34 <calloc@plt>
 *   @0x22f858 cmp r6, #0
 *   @0x22f85c str r9, [r4, #0x28]
 *   @0x22f860 mov r8, r0
 *   @0x22f864 str r0, [r4, #0x20]
 *   @0x22f868 beq 0x22f938 <vorbis_book_init_decode+0x334>
 *   @0x22f86c ldr r10, [r4, #0x1c]
 *   @0x22f870 mov r3, r9
 *   @0x22f874 mov r12, #1
 *   @0x22f878 ldrb r5, [r10, r9]
 *   @0x22f87c cmp r5, r3
 *   @0x22f880 strgt r5, [r4, #0x28]
 *   @0x22f884 ldrbgt r5, [r10, r9]
 *   @0x22f888 cmp r7, r5
 *   @0x22f88c blt 0x22f928 <vorbis_book_init_decode+0x324>
 *   @0x22f890 ldr r3, [r4, #0x14]
 *   @0x22f894 ldr r0, [r3, r9, lsl #2]
 *   @0x22f898 str r12, [r11, #-0x48]
 *   @0x22f89c bl 0x22ea70 <res2_inverse+0x25c>
 *   @0x22f8a0 ldr r12, [r11, #-0x48]
 *   @0x22f8a4 rsb r3, r5, r7
 *   @0x22f8a8 lsl r3, r12, r3
 *   @0x22f8ac cmp r3, #0
 *   @0x22f8b0 ble 0x22f928 <vorbis_book_init_decode+0x324>
 *   @0x22f8b4 ldr r2, [r4, #0x24]
 *   @0x22f8b8 add lr, r9, #1
 *   @0x22f8bc mov r3, #0
 *   @0x22f8c0 orr r5, r0, r3, lsl r5
 *   @0x22f8c4 add r3, r3, #1
 *   @0x22f8c8 mov r7, r2
 *   @0x22f8cc str lr, [r8, r5, lsl #2]
 *   @0x22f8d0 ldrb r5, [r10, r9]
 *   @0x22f8d4 rsb r1, r5, r2
 *   @0x22f8d8 cmp r3, r12, lsl r1
 *   @0x22f8dc blt 0x22f8c0 <vorbis_book_init_decode+0x2bc>
 *   @0x22f8e0 cmp r6, lr
 *   @0x22f8e4 mov r9, lr
 *   @0x22f8e8 ble 0x22f938 <vorbis_book_init_decode+0x334>
 *   @0x22f8ec ldr r3, [r4, #0x28]
 *   @0x22f8f0 b 0x22f878 <vorbis_book_init_decode+0x274>
 *   @0x22f8f4 mov r0, #0
 *   @0x22f8f8 ldr r12, [r11, #-0x34]
 *   @0x22f8fc ldr r2, [r11, #-0x28]
 *   @0x22f900 ldr r3, [r12]
 *   @0x22f904 cmp r2, r3
 *   @0x22f908 bne 0x22fa6c <vorbis_book_init_decode+0x468>
 *   @0x22f90c sub sp, r11, #32
 *   @0x22f910 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x22f914 mov r7, #5
 *   @0x22f918 mov r0, #32
 *   @0x22f91c str r7, [r4, #0x24]
 *   @0x22f920 str r0, [r11, #-0x30]
 *   @0x22f924 b 0x22f84c <vorbis_book_init_decode+0x248>
 *   @0x22f928 add lr, r9, #1
 *   @0x22f92c cmp r6, lr
 *   @0x22f930 mov r9, lr
 *   @0x22f934 bgt 0x22f8ec <vorbis_book_init_decode+0x2e8>
 *   @0x22f938 rsb r3, r7, #31
 *   @0x22f93c mvn r10, #1
 *   @0x22f940 mov r5, #0
 *   @0x22f944 lsl r10, r10, r3
 *   @0x22f948 mov r12, r8
 *   @0x22f94c mov r9, r5
 *   @0x22f950 mov r8, r5
 *   @0x22f954 rsb r7, r7, #32
 *   @0x22f958 str r12, [r11, #-0x48]
 *   @0x22f95c lsl r7, r8, r7
 *   @0x22f960 mov r0, r7
 *   @0x22f964 bl 0x22ea70 <res2_inverse+0x25c>
 *   @0x22f968 ldr r12, [r11, #-0x48]
 *   @0x22f96c ldr r3, [r12, r0, lsl #2]
 *   @0x22f970 cmp r3, #0
 *   @0x22f974 bne 0x22fa14 <vorbis_book_init_decode+0x410>
 *   @0x22f978 add r3, r9, #1
 *   @0x22f97c lsl r2, r3, #2
 *   @0x22f980 b 0x22f9a0 <vorbis_book_init_decode+0x39c>
 *   @0x22f984 ldr r1, [r4, #0x14]
 *   @0x22f988 ldr r1, [r1, r2]
 *   @0x22f98c add r2, r2, #4
 *   @0x22f990 cmp r7, r1
 *   @0x22f994 blo 0x22f9a8 <vorbis_book_init_decode+0x3a4>
 *   @0x22f998 mov r9, r3
 *   @0x22f99c add r3, r3, #1
 *   @0x22f9a0 cmp r3, r6
 *   @0x22f9a4 blt 0x22f984 <vorbis_book_init_decode+0x380>
 *   @0x22f9a8 cmp r6, r5
 *   @0x22f9ac ble 0x22f9e8 <vorbis_book_init_decode+0x3e4>
 *   @0x22f9b0 ldr r2, [r4, #0x14]
 *   @0x22f9b4 add r3, r2, r5, lsl #2
 *   @0x22f9b8 ldr r2, [r2, r5, lsl #2]
 *   @0x22f9bc and r2, r10, r2
 *   @0x22f9c0 cmp r7, r2
 *   @0x22f9c4 bhs 0x22f9dc <vorbis_book_init_decode+0x3d8>
 *   @0x22f9c8 b 0x22f9e8 <vorbis_book_init_decode+0x3e4>
 *   @0x22f9cc ldr r2, [r3, #0x4]!
 *   @0x22f9d0 and r2, r2, r10
 *   @0x22f9d4 cmp r7, r2
 *   @0x22f9d8 blo 0x22f9e8 <vorbis_book_init_decode+0x3e4>
 *   @0x22f9dc add r5, r5, #1
 *   @0x22f9e0 cmp r5, r6
 *   @0x22f9e4 bne 0x22f9cc <vorbis_book_init_decode+0x3c8>
 *   @0x22f9e8 movw r2, #0x7fff
 *   @0x22f9ec cmp r9, r2
 *   @0x22f9f0 movlo r2, r9
 *   @0x22f9f4 rsb r3, r5, r6
 *   @0x22f9f8 movw r1, #0x7fff
 *   @0x22f9fc lsl r2, r2, #15
 *   @0x22fa00 orr r2, r2, #-2147483648
 *   @0x22fa04 cmp r3, r1
 *   @0x22fa08 orrls r3, r2, r3
 *   @0x22fa0c orrhi r3, r2, r1
 *   @0x22fa10 str r3, [r12, r0, lsl #2]
 *   @0x22fa14 ldr r2, [r11, #-0x30]
 *   @0x22fa18 add r8, r8, #1
 *   @0x22fa1c cmp r8, r2
 *   @0x22fa20 beq 0x22f8f4 <vorbis_book_init_decode+0x2f0>
 *   @0x22fa24 ldr r7, [r4, #0x24]
 *   @0x22fa28 b 0x22f954 <vorbis_book_init_decode+0x350>
 *   @0x22fa2c ldr r2, [r7]
 *   @0x22fa30 mov r3, #0
 *   @0x22fa34 str r1, [r4, #0x4]
 *   @0x22fa38 mov r0, r3
 *   @0x22fa3c str r3, [r4, #0x8]
 *   @0x22fa40 str r2, [r4]
 *   @0x22fa44 b 0x22f8f8 <vorbis_book_init_decode+0x2f4>
 *   @0x22fa48 mov r0, #0
 *   @0x22fa4c mov r6, r0
 *   @0x22fa50 bl 0xb6544 <malloc@plt>
 *   @0x22fa54 str r0, [r4, #0x1c]
 *   @0x22fa58 b 0x22f80c <vorbis_book_init_decode+0x208>
 *   @0x22fa5c mov r0, r4
 *   @0x22fa60 bl 0x22f598 <vorbis_book_clear>
 *   @0x22fa64 mvn r0, #0
 *   @0x22fa68 b 0x22f8f8 <vorbis_book_init_decode+0x2f4>
 *   @0x22fa6c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x22fa70 andseq lr, r11, r8, lsr r3
 *   @0x22fa74 .word 0xfffff3d0
 *
 * ══ §21/25 DrawLayerBackgroundElement  0x1b11a0  size 1120  280 条（0x1b11a0..0x1b1600）
 * @func 0x1b11a0 0x1b1600  size 1120  280 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1b11f4→0x54298c, 0x1b12f4→0x544c80, 0x1b1308→0x4859c0, 0x1b1450→0x4859c8, 0x1b1544→0x4859c0
 * 调用序列: Graphics::SetMatrix(eMatrix, float*)×6 / DirtyRoomExtents()×6 / Graphics::GetMatrix(eMatrix, float*)×3 / Sprite_Data(int)×2 / Graphics::AllocVerts(ePrimType, void*, int, int)×2 / CSprite::DrawTiled(int, float, float, float, float, bool, bool, float, float, float, float, unsigned int, float) / RenderStateManager::SaveStates() / RenderStateManager::SetRenderState(eRenderState, unsigned int)
 * 字段偏移 top8: 0x24×6 / 0x8×6 / 0x4×5 / 0x28×5 / 0xc×5 / 0x1c×4 / 0x18×4 / 0x14×3
 * VFP 指令 37 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b11a0 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1b11a4 vpush {d8}
 *   @0x1b11a8 mov r7, r0
 *   @0x1b11ac ldr r4, [r2, #0x1c]
 *   @0x1b11b0 sub sp, sp, #424
 *   @0x1b11b4 ldr r6, [pc, #0x430]
 *   @0x1b11b8 mov r8, r1
 *   @0x1b11bc ldrb r3, [r4]
 *   @0x1b11c0 add r6, pc, r6
 *   @0x1b11c4 cmp r3, #0
 *   @0x1b11c8 bne 0x1b11d8 <_Z26DrawLayerBackgroundElementP9tagYYRECTP6CLayerP23CLayerBackgroundElement+0x38>
 *   @0x1b11cc add sp, sp, #424
 *   @0x1b11d0 vpop {d8}
 *   @0x1b11d4 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1b11d8 ldr r0, [r4, #0x4]
 *   @0x1b11dc bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x1b11e0 subs r5, r0, #0
 *   @0x1b11e4 beq 0x1b12f4 <_Z26DrawLayerBackgroundElementP9tagYYRECTP6CLayerP23CLayerBackgroundElement+0x154>
 *   @0x1b11e8 ldrb r3, [r4, #0x14]
 *   @0x1b11ec cmp r3, #0
 *   @0x1b11f0 beq 0x1b1234 <_Z26DrawLayerBackgroundElementP9tagYYRECTP6CLayerP23CLayerBackgroundElement+0x94>
 *   @0x1b11f4 ldr r3, [pc, #0x3f4]
 *   @0x1b11f8 ldr r3, [r6, r3]
 *   @0x1b11fc ldr r3, [r3]
 *   @0x1b1200 cmp r3, #0
 *   @0x1b1204 beq 0x1b1234 <_Z26DrawLayerBackgroundElementP9tagYYRECTP6CLayerP23CLayerBackgroundElement+0x94>
 *   @0x1b1208 vldr s17, [r3, #16]
 *   @0x1b120c vldr s16, [r3, #20]
 *   @0x1b1210 vcvt.f32.s32 s17, s17
 *   @0x1b1214 vldr s12, [r5, #28]
 *   @0x1b1218 vldr s13, [r5, #32]
 *   @0x1b121c vcvt.f32.s32 s14, s12
 *   @0x1b1220 vcvt.f32.s32 s16, s16
 *   @0x1b1224 vcvt.f32.s32 s15, s13
 *   @0x1b1228 vdiv.f32 s17, s17, s14
 *   @0x1b122c vdiv.f32 s16, s16, s15
 *   @0x1b1230 b 0x1b123c <_Z26DrawLayerBackgroundElementP9tagYYRECTP6CLayerP23CLayerBackgroundElement+0x9c>
 *   @0x1b1234 vldr s17, [r4, #12]
 *   @0x1b1238 vldr s16, [r4, #16]
 *   @0x1b123c ldr r9, [r5, #0x24]
 *   @0x1b1240 mov r3, #0
 *   @0x1b1244 ldr r6, [r5, #0x28]
 *   @0x1b1248 str r3, [r5, #0x24]
 *   @0x1b124c str r3, [r5, #0x28]
 *   @0x1b1250 ldr r0, [r4, #0x4]
 *   @0x1b1254 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x1b1258 ldr r3, [r7]
 *   @0x1b125c ldr r12, [r7, #0x8]
 *   @0x1b1260 vldr s15, [r4, #32]
 *   @0x1b1264 ldr r1, [r7, #0x4]
 *   @0x1b1268 vstr s17, [sp]
 *   @0x1b126c rsb r12, r3, r12
 *   @0x1b1270 vmov s13, r3
 *   @0x1b1274 ldr r2, [r7, #0xc]
 *   @0x1b1278 vstr s16, [sp, #4]
 *   @0x1b127c vcvt.f32.s32 s12, s13
 *   @0x1b1280 ldr r3, [r8, #0xc]
 *   @0x1b1284 vmov s14, r12
 *   @0x1b1288 ldrb r12, [r4, #0x8]
 *   @0x1b128c rsb r2, r1, r2
 *   @0x1b1290 vmov s13, r2
 *   @0x1b1294 ldr r2, [r8, #0x8]
 *   @0x1b1298 str r12, [sp, #0x8]
 *   @0x1b129c ldrb r12, [r4, #0x9]
 *   @0x1b12a0 vcvt.f32.s32 s14, s14
 *   @0x1b12a4 vstr s12, [sp, #16]
 *   @0x1b12a8 vmov s12, r1
 *   @0x1b12ac str r12, [sp, #0xc]
 *   @0x1b12b0 vstr s14, [sp, #24]
 *   @0x1b12b4 vcvt.f32.s32 s13, s13
 *   @0x1b12b8 vcvt.f32.s32 s14, s12
 *   @0x1b12bc vstr s13, [sp, #28]
 *   @0x1b12c0 vcvt.s32.f32 s15, s15
 *   @0x1b12c4 vstr s14, [sp, #20]
 *   @0x1b12c8 ldr r12, [r4, #0x18]
 *   @0x1b12cc str r12, [sp, #0x20]
 *   @0x1b12d0 ldr r12, [r4, #0x1c]
 *   @0x1b12d4 vmov r1, s15
 *   @0x1b12d8 str r12, [sp, #0x24]
 *   @0x1b12dc bl 0x1ed1dc <_ZN7CSprite9DrawTiledEiffffbbffffjf>
 *   @0x1b12e0 str r9, [r5, #0x24]
 *   @0x1b12e4 str r6, [r5, #0x28]
 *   @0x1b12e8 add sp, sp, #424
 *   @0x1b12ec vpop {d8}
 *   @0x1b12f0 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1b12f4 ldr r3, [pc, #0x2f8]
 *   @0x1b12f8 ldr r3, [r6, r3]
 *   @0x1b12fc ldr r10, [r3]
 *   @0x1b1300 cmp r10, #0
 *   @0x1b1304 beq 0x1b1328 <_Z26DrawLayerBackgroundElementP9tagYYRECTP6CLayerP23CLayerBackgroundElement+0x188>
 *   @0x1b1308 ldr r3, [pc, #0x2e8]
 *   @0x1b130c ldr r3, [r6, r3]
 *   @0x1b1310 ldr r10, [r3]
 *   @0x1b1314 cmp r10, #0
 *   @0x1b1318 beq 0x1b1328 <_Z26DrawLayerBackgroundElementP9tagYYRECTP6CLayerP23CLayerBackgroundElement+0x188>
 *   @0x1b131c ldr r10, [r10]
 *   @0x1b1320 adds r10, r10, #0
 *   @0x1b1324 movne r10, #1
 *   @0x1b1328 add r8, sp, #40
 *   @0x1b132c add r7, sp, #104
 *   @0x1b1330 mov r0, #2
 *   @0x1b1334 add r5, sp, #168
 *   @0x1b1338 mov r1, r8
 *   @0x1b133c bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf>
 *   @0x1b1340 mov r1, r7
 *   @0x1b1344 mov r0, #0
 *   @0x1b1348 bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf>
 *   @0x1b134c mov r1, r5
 *   @0x1b1350 mov r0, #1
 *   @0x1b1354 bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf>
 *   @0x1b1358 mov r0, #2
 *   @0x1b135c add r1, sp, #232
 *   @0x1b1360 mov r3, #0
 *   @0x1b1364 mov r2, #1065353216
 *   @0x1b1368 str r3, [sp, #0x120]
 *   @0x1b136c str r2, [sp, #0x124]
 *   @0x1b1370 str r2, [sp, #0x110]
 *   @0x1b1374 str r2, [sp, #0xfc]
 *   @0x1b1378 str r2, [sp, #0xe8]
 *   @0x1b137c str r2, [sp, #0x164]
 *   @0x1b1380 str r2, [sp, #0x150]
 *   @0x1b1384 str r2, [sp, #0x13c]
 *   @0x1b1388 str r2, [sp, #0x128]
 *   @0x1b138c str r2, [sp, #0x1a4]
 *   @0x1b1390 str r3, [sp, #0x11c]
 *   @0x1b1394 str r3, [sp, #0x118]
 *   @0x1b1398 str r3, [sp, #0x114]
 *   @0x1b139c str r3, [sp, #0x10c]
 *   @0x1b13a0 str r3, [sp, #0x108]
 *   @0x1b13a4 str r3, [sp, #0x104]
 *   @0x1b13a8 str r3, [sp, #0x100]
 *   @0x1b13ac str r3, [sp, #0xf8]
 *   @0x1b13b0 str r3, [sp, #0xf4]
 *   @0x1b13b4 str r3, [sp, #0xf0]
 *   @0x1b13b8 str r3, [sp, #0xec]
 *   @0x1b13bc str r3, [sp, #0x160]
 *   @0x1b13c0 str r3, [sp, #0x15c]
 *   @0x1b13c4 str r3, [sp, #0x158]
 *   @0x1b13c8 str r3, [sp, #0x154]
 *   @0x1b13cc str r3, [sp, #0x14c]
 *   @0x1b13d0 str r3, [sp, #0x148]
 *   @0x1b13d4 str r3, [sp, #0x144]
 *   @0x1b13d8 str r3, [sp, #0x140]
 *   @0x1b13dc str r3, [sp, #0x138]
 *   @0x1b13e0 str r3, [sp, #0x134]
 *   @0x1b13e4 str r3, [sp, #0x130]
 *   @0x1b13e8 str r3, [sp, #0x12c]
 *   @0x1b13ec str r2, [sp, #0x190]
 *   @0x1b13f0 str r2, [sp, #0x17c]
 *   @0x1b13f4 str r2, [sp, #0x168]
 *   @0x1b13f8 str r3, [sp, #0x1a0]
 *   @0x1b13fc str r3, [sp, #0x19c]
 *   @0x1b1400 str r3, [sp, #0x198]
 *   @0x1b1404 str r3, [sp, #0x194]
 *   @0x1b1408 str r3, [sp, #0x18c]
 *   @0x1b140c str r3, [sp, #0x188]
 *   @0x1b1410 str r3, [sp, #0x184]
 *   @0x1b1414 str r3, [sp, #0x180]
 *   @0x1b1418 str r3, [sp, #0x178]
 *   @0x1b141c str r3, [sp, #0x174]
 *   @0x1b1420 str r3, [sp, #0x170]
 *   @0x1b1424 str r3, [sp, #0x16c]
 *   @0x1b1428 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf>
 *   @0x1b142c bl 0x168d7c <_Z16DirtyRoomExtentsv>
 *   @0x1b1430 mov r0, #0
 *   @0x1b1434 add r1, sp, #296
 *   @0x1b1438 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf>
 *   @0x1b143c bl 0x168d7c <_Z16DirtyRoomExtentsv>
 *   @0x1b1440 add r1, sp, #360
 *   @0x1b1444 mov r0, #1
 *   @0x1b1448 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf>
 *   @0x1b144c bl 0x168d7c <_Z16DirtyRoomExtentsv>
 *   @0x1b1450 ldr r3, [pc, #0x1a4]
 *   @0x1b1454 ldr r9, [r6, r3]
 *   @0x1b1458 mov r0, r9
 *   @0x1b145c bl 0x167fcc <_ZN18RenderStateManager10SaveStatesEv>
 *   @0x1b1460 mov r0, r9
 *   @0x1b1464 mov r1, #8
 *   @0x1b1468 mov r2, #0
 *   @0x1b146c bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x1b1470 vldr s14, [r4, #28]
 *   @0x1b1474 vldr s15, [pc, #364]
 *   @0x1b1478 vmul.f32 s15, s14, s15
 *   @0x1b147c ldr r3, [r4, #0x18]
 *   @0x1b1480 vcvt.s32.f32 s15, s15
 *   @0x1b1484 vmov r4, s15
 *   @0x1b1488 cmp r4, #255
 *   @0x1b148c movgt r4, #-16777216
 *   @0x1b1490 ble 0x1b15d8 <_Z26DrawLayerBackgroundElementP9tagYYRECTP6CLayerP23CLayerBackgroundElement+0x438>
 *   @0x1b1494 cmp r10, #0
 *   @0x1b1498 bic r3, r3, #-16777216
 *   @0x1b149c orr r4, r4, r3
 *   @0x1b14a0 bne 0x1b1544 <_Z26DrawLayerBackgroundElementP9tagYYRECTP6CLayerP23CLayerBackgroundElement+0x3a4>
 *   @0x1b14a4 mov r1, r10
 *   @0x1b14a8 mov r2, #16
 *   @0x1b14ac mov r0, #5
 *   @0x1b14b0 mov r3, #4
 *   @0x1b14b4 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x1b14b8 mov r2, #1065353216
 *   @0x1b14bc mov r1, #0
 *   @0x1b14c0 movt r1, #0xbf80
 *   @0x1b14c4 str r4, [r0, #0x3c]
 *   @0x1b14c8 str r4, [r0, #0x2c]
 *   @0x1b14cc str r4, [r0, #0x1c]
 *   @0x1b14d0 str r4, [r0, #0xc]
 *   @0x1b14d4 str r1, [r0]
 *   @0x1b14d8 str r1, [r0, #0x4]
 *   @0x1b14dc str r1, [r0, #0x10]
 *   @0x1b14e0 str r1, [r0, #0x24]
 *   @0x1b14e4 str r2, [r0, #0x14]
 *   @0x1b14e8 str r2, [r0, #0x20]
 *   @0x1b14ec str r2, [r0, #0x30]
 *   @0x1b14f0 str r2, [r0, #0x34]
 *   @0x1b14f4 str r2, [r0, #0x38]
 *   @0x1b14f8 str r2, [r0, #0x28]
 *   @0x1b14fc str r2, [r0, #0x18]
 *   @0x1b1500 str r2, [r0, #0x8]
 *   @0x1b1504 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x1b1508 mov r1, r8
 *   @0x1b150c mov r0, #2
 *   @0x1b1510 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf>
 *   @0x1b1514 bl 0x168d7c <_Z16DirtyRoomExtentsv>
 *   @0x1b1518 mov r1, r7
 *   @0x1b151c mov r0, #0
 *   @0x1b1520 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf>
 *   @0x1b1524 bl 0x168d7c <_Z16DirtyRoomExtentsv>
 *   @0x1b1528 mov r1, r5
 *   @0x1b152c mov r0, #1
 *   @0x1b1530 bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf>
 *   @0x1b1534 bl 0x168d7c <_Z16DirtyRoomExtentsv>
 *   @0x1b1538 mov r0, r9
 *   @0x1b153c bl 0x168050 <_ZN18RenderStateManager13RestoreStatesEv>
 *   @0x1b1540 b 0x1b11cc <_Z26DrawLayerBackgroundElementP9tagYYRECTP6CLayerP23CLayerBackgroundElement+0x2c>
 *   @0x1b1544 ldr r1, [pc, #0xac]
 *   @0x1b1548 mov r2, #24
 *   @0x1b154c mov r0, #5
 *   @0x1b1550 mov r3, #4
 *   @0x1b1554 ldr r1, [r6, r1]
 *   @0x1b1558 ldr r1, [r1]
 *   @0x1b155c ldr r1, [r1]
 *   @0x1b1560 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x1b1564 mov r2, #0
 *   @0x1b1568 mov r1, #0
 *   @0x1b156c movt r1, #0xbf80
 *   @0x1b1570 str r2, [r0, #0x10]
 *   @0x1b1574 str r2, [r0, #0x14]
 *   @0x1b1578 str r2, [r0, #0x28]
 *   @0x1b157c str r2, [r0, #0x44]
 *   @0x1b1580 mov r2, #1065353216
 *   @0x1b1584 str r4, [r0, #0x54]
 *   @0x1b1588 str r4, [r0, #0x3c]
 *   @0x1b158c str r4, [r0, #0x24]
 *   @0x1b1590 str r4, [r0, #0xc]
 *   @0x1b1594 str r1, [r0]
 *   @0x1b1598 str r1, [r0, #0x4]
 *   @0x1b159c str r1, [r0, #0x18]
 *   @0x1b15a0 str r1, [r0, #0x34]
 *   @0x1b15a4 str r2, [r0, #0x1c]
 *   @0x1b15a8 str r2, [r0, #0x2c]
 *   @0x1b15ac str r2, [r0, #0x30]
 *   @0x1b15b0 str r2, [r0, #0x40]
 *   @0x1b15b4 str r2, [r0, #0x48]
 *   @0x1b15b8 str r2, [r0, #0x4c]
 *   @0x1b15bc str r2, [r0, #0x58]
 *   @0x1b15c0 str r2, [r0, #0x5c]
 *   @0x1b15c4 str r2, [r0, #0x50]
 *   @0x1b15c8 str r2, [r0, #0x38]
 *   @0x1b15cc str r2, [r0, #0x20]
 *   @0x1b15d0 str r2, [r0, #0x8]
 *   @0x1b15d4 b 0x1b1504 <_Z26DrawLayerBackgroundElementP9tagYYRECTP6CLayerP23CLayerBackgroundElement+0x364>
 *   @0x1b15d8 cmp r4, #0
 *   @0x1b15dc lslge r4, r4, #24
 *   @0x1b15e0 movlt r4, #0
 *   @0x1b15e4 b 0x1b1494 <_Z26DrawLayerBackgroundElementP9tagYYRECTP6CLayerP23CLayerBackgroundElement+0x2f4>
 *   @0x1b15e8 cmnmi pc, #0
 *   @0x1b15ec mlaeq r4, r0, r10, r0
 *   @0x1b15f0 .word 0xffffbcd8
 *   @0x1b15f4 .word 0xffffe828
 *   @0x1b15f8 .word 0xffffe4e0
 *   @0x1b15fc .word 0xffffc0a8
 *
 * ══ §22/25 JS_String  0x2583e4  size 1112  278 条（0x2583e4..0x25883c）
 * @func 0x2583e4 0x25883c  size 1112  278 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x258424→0x75644c, 0x2584c4→0x3ec040, 0x258668→0x3ec040
 * 调用序列: CodepointToUTF16(int, unsigned short&, unsigned short&)×4 / CCodepointIterator_UTF8::GetNext()×4 / YYObjectBase::Add(char const*, RValue&, int)×2 / operator new(unsigned int)×2 / CCodepointIterator_UTF8::CCodepointIterator_UTF8(char const*)×2 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / 0xb65b0×2 / CCodepointIterator_UTF8::Reset()×2
 * 字段偏移 top8: 0x8×8 / 0x4×4 / 0x28×3 / 0x30×3 / 0x14×3 / 0xc×2 / 0x74×2 / 0x3d8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2583e4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2583e8 sub sp, sp, #124
 *   @0x2583ec ldr r11, [pc, #0x404]
 *   @0x2583f0 mov r5, r0
 *   @0x2583f4 ldr lr, [pc, #0x400]
 *   @0x2583f8 mov r9, r3
 *   @0x2583fc add r11, pc, r11
 *   @0x258400 ldr r4, [sp, #0xa0]
 *   @0x258404 ldr lr, [r11, lr]
 *   @0x258408 str r4, [sp]
 *   @0x25840c str lr, [sp, #0xc]
 *   @0x258410 ldr lr, [lr]
 *   @0x258414 str lr, [sp, #0x74]
 *   @0x258418 bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_>
 *   @0x25841c ldr r6, [r5]
 *   @0x258420 ldr r2, [pc, #0x3d8]
 *   @0x258424 ldr r3, [pc, #0x3d8]
 *   @0x258428 add r2, pc, r2
 *   @0x25842c str r2, [r6, #0x40]
 *   @0x258430 mov r0, r6
 *   @0x258434 ldr r3, [r11, r3]
 *   @0x258438 ldr r1, [r3]
 *   @0x25843c str r1, [r6, #0x18]
 *   @0x258440 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x258444 ldr r2, [r6, #0x28]
 *   @0x258448 ldr r3, [pc, #0x3b8]
 *   @0x25844c cmp r9, #0
 *   @0x258450 orr r2, r2, #1
 *   @0x258454 str r2, [r6, #0x28]
 *   @0x258458 ldr r3, [r11, r3]
 *   @0x25845c str r3, [r6, #0x4c]
 *   @0x258460 bne 0x2585f4 <_Z9JS_StringR6RValueP9CInstanceS2_iPS_+0x210>
 *   @0x258464 add r7, sp, #36
 *   @0x258468 ldr r1, [pc, #0x39c]
 *   @0x25846c mvn r3, #-16777216
 *   @0x258470 str r9, [sp, #0x24]
 *   @0x258474 mov r0, r7
 *   @0x258478 add r1, pc, r1
 *   @0x25847c str r3, [sp, #0x30]
 *   @0x258480 add r5, sp, #20
 *   @0x258484 str r9, [sp, #0x28]
 *   @0x258488 add r4, sp, #16
 *   @0x25848c str r9, [sp, #0x2c]
 *   @0x258490 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x258494 ldr r1, [pc, #0x374]
 *   @0x258498 mov r0, r6
 *   @0x25849c mov r2, r7
 *   @0x2584a0 mov r3, r9
 *   @0x2584a4 add r1, pc, r1
 *   @0x2584a8 add r10, sp, #18
 *   @0x2584ac bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei>
 *   @0x2584b0 ldr r3, [sp, #0x24]
 *   @0x2584b4 mov r0, #12
 *   @0x2584b8 ldr r1, [r3]
 *   @0x2584bc str r1, [sp, #0x8]
 *   @0x2584c0 bl 0x27c524 <_Znwj>
 *   @0x2584c4 ldr r3, [pc, #0x348]
 *   @0x2584c8 ldr r1, [sp, #0x8]
 *   @0x2584cc ldr r3, [r11, r3]
 *   @0x2584d0 add r3, r3, #8
 *   @0x2584d4 mov r8, r0
 *   @0x2584d8 mov r0, r5
 *   @0x2584dc str r3, [r8]
 *   @0x2584e0 bl 0x2423d8 <_ZN23CCodepointIterator_UTF8C2EPKc>
 *   @0x2584e4 b 0x2584f8 <_Z9JS_StringR6RValueP9CInstanceS2_iPS_+0x114>
 *   @0x2584e8 mov r1, r4
 *   @0x2584ec mov r2, r10
 *   @0x2584f0 bl 0x2424c4 <_Z16CodepointToUTF16iRtS_>
 *   @0x2584f4 add r9, r9, r0
 *   @0x2584f8 mov r0, r5
 *   @0x2584fc bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv>
 *   @0x258500 subs r11, r0, #0
 *   @0x258504 bne 0x2584e8 <_Z9JS_StringR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0x258508 lsl r4, r9, #1
 *   @0x25850c ldr r1, [pc, #0x304]
 *   @0x258510 str r9, [r8, #0x8]
 *   @0x258514 mov r3, #1
 *   @0x258518 add r1, pc, r1
 *   @0x25851c mov r2, #70
 *   @0x258520 mov r0, r4
 *   @0x258524 add r10, sp, #16
 *   @0x258528 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x25852c mov r2, r4
 *   @0x258530 mov r1, r11
 *   @0x258534 add r9, sp, #18
 *   @0x258538 mov r4, r11
 *   @0x25853c str r0, [r8, #0x4]
 *   @0x258540 bl 0xb65b0 <memset@plt>
 *   @0x258544 mov r0, r5
 *   @0x258548 bl 0x2423fc <_ZN23CCodepointIterator_UTF85ResetEv>
 *   @0x25854c b 0x258580 <_Z9JS_StringR6RValueP9CInstanceS2_iPS_+0x19c>
 *   @0x258550 mov r1, r10
 *   @0x258554 mov r2, r9
 *   @0x258558 bl 0x2424c4 <_Z16CodepointToUTF16iRtS_>
 *   @0x25855c ldr r2, [r8, #0x4]
 *   @0x258560 ldrh r1, [sp, #16]
 *   @0x258564 lsl r3, r4, #1
 *   @0x258568 strh r1, [r2, r3]
 *   @0x25856c cmp r0, #2
 *   @0x258570 add r4, r4, r0
 *   @0x258574 addeq r3, r2, r3
 *   @0x258578 ldrheq r1, [sp, #18]
 *   @0x25857c strheq r1, [r3, #2]
 *   @0x258580 mov r0, r5
 *   @0x258584 bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv>
 *   @0x258588 subs r11, r0, #0
 *   @0x25858c bne 0x258550 <_Z9JS_StringR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x258590 ldr r1, [pc, #0x284]
 *   @0x258594 mov r2, r8
 *   @0x258598 mov r0, r6
 *   @0x25859c mov r3, #8
 *   @0x2585a0 add r1, pc, r1
 *   @0x2585a4 bl 0x199b20 <_ZN12YYObjectBase3AddEPKcPvi>
 *   @0x2585a8 ldr r1, [pc, #0x270]
 *   @0x2585ac mov r3, r11
 *   @0x2585b0 mov r0, r6
 *   @0x2585b4 mov r2, r11
 *   @0x2585b8 add r1, pc, r1
 *   @0x2585bc bl 0x199960 <_ZN12YYObjectBase3AddEPKcii>
 *   @0x2585c0 ldr r3, [sp, #0x30]
 *   @0x2585c4 sub r3, r3, #1
 *   @0x2585c8 bic r3, r3, #-16777216
 *   @0x2585cc bic r3, r3, #3
 *   @0x2585d0 cmp r3, #0
 *   @0x2585d4 beq 0x2587d8 <_Z9JS_StringR6RValueP9CInstanceS2_iPS_+0x3f4>
 *   @0x2585d8 ldr r12, [sp, #0xc]
 *   @0x2585dc ldr r2, [sp, #0x74]
 *   @0x2585e0 ldr r3, [r12]
 *   @0x2585e4 cmp r2, r3
 *   @0x2585e8 bne 0x2587f4 <_Z9JS_StringR6RValueP9CInstanceS2_iPS_+0x410>
 *   @0x2585ec add sp, sp, #124
 *   @0x2585f0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2585f4 add r5, sp, #20
 *   @0x2585f8 mov r1, r4
 *   @0x2585fc mov r9, #0
 *   @0x258600 mvn r3, #-16777216
 *   @0x258604 mov r0, r5
 *   @0x258608 str r9, [sp, #0x14]
 *   @0x25860c str r9, [sp, #0x18]
 *   @0x258610 str r9, [sp, #0x1c]
 *   @0x258614 str r3, [sp, #0x20]
 *   @0x258618 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x25861c cmp r0, #2
 *   @0x258620 beq 0x2585d8 <_Z9JS_StringR6RValueP9CInstanceS2_iPS_+0x1f4>
 *   @0x258624 cmp r0, #1
 *   @0x258628 beq 0x2587e4 <_Z9JS_StringR6RValueP9CInstanceS2_iPS_+0x400>
 *   @0x25862c ldr r2, [sp, #0x14]
 *   @0x258630 mov r0, r6
 *   @0x258634 ldr r1, [pc, #0x1e8]
 *   @0x258638 mov r3, r9
 *   @0x25863c add r7, sp, #36
 *   @0x258640 add r8, sp, #16
 *   @0x258644 ldr r2, [r2]
 *   @0x258648 add r1, pc, r1
 *   @0x25864c bl 0x199aa8 <_ZN12YYObjectBase3AddEPKcS1_i>
 *   @0x258650 ldr r3, [sp, #0x14]
 *   @0x258654 mov r0, #12
 *   @0x258658 add r10, sp, #18
 *   @0x25865c ldr r1, [r3]
 *   @0x258660 str r1, [sp, #0x8]
 *   @0x258664 bl 0x27c524 <_Znwj>
 *   @0x258668 ldr r3, [pc, #0x1a4]
 *   @0x25866c ldr r1, [sp, #0x8]
 *   @0x258670 ldr r3, [r11, r3]
 *   @0x258674 add r3, r3, #8
 *   @0x258678 mov r4, r0
 *   @0x25867c mov r0, r7
 *   @0x258680 str r3, [r4]
 *   @0x258684 bl 0x2423d8 <_ZN23CCodepointIterator_UTF8C2EPKc>
 *   @0x258688 b 0x25869c <_Z9JS_StringR6RValueP9CInstanceS2_iPS_+0x2b8>
 *   @0x25868c mov r1, r8
 *   @0x258690 mov r2, r10
 *   @0x258694 bl 0x2424c4 <_Z16CodepointToUTF16iRtS_>
 *   @0x258698 add r9, r9, r0
 *   @0x25869c mov r0, r7
 *   @0x2586a0 bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv>
 *   @0x2586a4 subs r11, r0, #0
 *   @0x2586a8 bne 0x25868c <_Z9JS_StringR6RValueP9CInstanceS2_iPS_+0x2a8>
 *   @0x2586ac lsl r8, r9, #1
 *   @0x2586b0 ldr r1, [pc, #0x170]
 *   @0x2586b4 str r9, [r4, #0x8]
 *   @0x2586b8 mov r3, #1
 *   @0x2586bc add r1, pc, r1
 *   @0x2586c0 mov r2, #70
 *   @0x2586c4 mov r0, r8
 *   @0x2586c8 add r10, sp, #16
 *   @0x2586cc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x2586d0 mov r2, r8
 *   @0x2586d4 mov r1, r11
 *   @0x2586d8 add r9, sp, #18
 *   @0x2586dc mov r8, r11
 *   @0x2586e0 str r0, [r4, #0x4]
 *   @0x2586e4 bl 0xb65b0 <memset@plt>
 *   @0x2586e8 mov r0, r7
 *   @0x2586ec bl 0x2423fc <_ZN23CCodepointIterator_UTF85ResetEv>
 *   @0x2586f0 b 0x258724 <_Z9JS_StringR6RValueP9CInstanceS2_iPS_+0x340>
 *   @0x2586f4 mov r1, r10
 *   @0x2586f8 mov r2, r9
 *   @0x2586fc bl 0x2424c4 <_Z16CodepointToUTF16iRtS_>
 *   @0x258700 ldr r2, [r4, #0x4]
 *   @0x258704 ldrh r1, [sp, #16]
 *   @0x258708 lsl r3, r8, #1
 *   @0x25870c strh r1, [r2, r3]
 *   @0x258710 cmp r0, #2
 *   @0x258714 add r8, r8, r0
 *   @0x258718 addeq r3, r2, r3
 *   @0x25871c ldrheq r1, [sp, #18]
 *   @0x258720 strheq r1, [r3, #2]
 *   @0x258724 mov r0, r7
 *   @0x258728 bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv>
 *   @0x25872c subs r11, r0, #0
 *   @0x258730 bne 0x2586f4 <_Z9JS_StringR6RValueP9CInstanceS2_iPS_+0x310>
 *   @0x258734 ldr r1, [pc, #0xf0]
 *   @0x258738 mov r2, r4
 *   @0x25873c mov r0, r6
 *   @0x258740 mov r3, #8
 *   @0x258744 add r1, pc, r1
 *   @0x258748 bl 0x199b20 <_ZN12YYObjectBase3AddEPKcPvi>
 *   @0x25874c ldr r2, [r4, #0x8]
 *   @0x258750 cmp r2, #0
 *   @0x258754 ble 0x2587a0 <_Z9JS_StringR6RValueP9CInstanceS2_iPS_+0x3bc>
 *   @0x258758 ldr r10, [pc, #0xd0]
 *   @0x25875c add r8, sp, #52
 *   @0x258760 mov r9, #5
 *   @0x258764 add r10, pc, r10
 *   @0x258768 mov r2, r11
 *   @0x25876c mov r1, r10
 *   @0x258770 mov r0, r8
 *   @0x258774 add r11, r11, #1
 *   @0x258778 bl 0xb6550 <sprintf@plt>
 *   @0x25877c mov r2, r7
 *   @0x258780 mov r0, r6
 *   @0x258784 mov r1, r8
 *   @0x258788 mov r3, #7
 *   @0x25878c str r9, [sp, #0x30]
 *   @0x258790 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei>
 *   @0x258794 ldr r2, [r4, #0x8]
 *   @0x258798 cmp r2, r11
 *   @0x25879c bgt 0x258768 <_Z9JS_StringR6RValueP9CInstanceS2_iPS_+0x384>
 *   @0x2587a0 ldr r1, [pc, #0x8c]
 *   @0x2587a4 mov r3, #0
 *   @0x2587a8 mov r0, r6
 *   @0x2587ac add r1, pc, r1
 *   @0x2587b0 bl 0x199960 <_ZN12YYObjectBase3AddEPKcii>
 *   @0x2587b4 ldr r3, [sp, #0x20]
 *   @0x2587b8 sub r3, r3, #1
 *   @0x2587bc bic r3, r3, #-16777216
 *   @0x2587c0 bic r3, r3, #3
 *   @0x2587c4 cmp r3, #0
 *   @0x2587c8 bne 0x2585d8 <_Z9JS_StringR6RValueP9CInstanceS2_iPS_+0x1f4>
 *   @0x2587cc mov r0, r5
 *   @0x2587d0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x2587d4 b 0x2585d8 <_Z9JS_StringR6RValueP9CInstanceS2_iPS_+0x1f4>
 *   @0x2587d8 mov r0, r7
 *   @0x2587dc bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x2587e0 b 0x2585d8 <_Z9JS_StringR6RValueP9CInstanceS2_iPS_+0x1f4>
 *   @0x2587e4 ldr r0, [pc, #0x4c]
 *   @0x2587e8 add r0, pc, r0
 *   @0x2587ec bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x2587f0 b 0x2585d8 <_Z9JS_StringR6RValueP9CInstanceS2_iPS_+0x1f4>
 *   @0x2587f4 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2587f8 andseq r9, r9, r4, asr r8
 *   @0x2587fc .word 0xffffbd00
 *   @0x258800 andeq sp, pc, r8, lsl #8
 *   @0x258804 .word 0xfffff960
 *   @0x258808 .word 0xfffffb88
 *   @0x25880c strheq r6, [sp], -lr
 *   @0x258810 andeq sp, pc, r12, rrx
 *   @0x258814 .word 0xfffff8a8
 *   @0x258818 andeq r8, sp, r8, lsl r11
 *   @0x25881c andeq lr, pc, r12, lsr #11
 *   @0x258820 strheq r8, [sp], -r4
 *   @0x258824 andeq r12, pc, r8, asr #29
 *   @0x258828 andeq r8, sp, r4, ror r9
 *   @0x25882c andeq lr, pc, r8, lsl #8
 *   @0x258830 andeq r9, sp, r8, lsr #27
 *   @0x258834 andeq r8, sp, r0, asr #1
 *   @0x258838 andeq lr, pc, r0, lsl #7
 *
 * ══ §23/25 GetOSSpecificJSON  0x160240  size 1092  273 条（0x160240..0x160684）
 * @func 0x160240 0x160684  size 1092  273 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYStrBuilderYY::AddFormat(char const*, ...)×18 / FindDSMap(CDS_Map*, char const*)×17 / YYGetString(RValue const*, int)×15 / YYGetInt32(RValue const*, int)×2 / 0xb6544 / getJNIEnv / _JNIEnv::CallStaticIntMethod(_jclass*, _jmethodID*, ...) / DS_AutoMutex::DS_AutoMutex()
 * 字段偏移 top8: 0x4×3 / 0xc×2 / 0x374×2 / 0x8×1 / 0x344×1 / 0x340×1 / 0x330×1 / 0x31c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160240 push {r4, r5, r6, r7, r8, lr}
 *   @0x160244 sub sp, sp, #16
 *   @0x160248 mov r0, #1
 *   @0x16024c mov r4, #0
 *   @0x160250 str r4, [sp, #0xc]
 *   @0x160254 bl 0xb6544 <malloc@plt>
 *   @0x160258 mov r3, #1
 *   @0x16025c str r3, [sp, #0x8]
 *   @0x160260 add r5, sp, #4
 *   @0x160264 strb r4, [r0]
 *   @0x160268 str r0, [sp, #0x4]
 *   @0x16026c bl 0x290274 <getJNIEnv>
 *   @0x160270 ldr r2, [pc, #0x374]
 *   @0x160274 ldr r3, [pc, #0x374]
 *   @0x160278 ldr r2, [pc, r2]
 *   @0x16027c ldr r3, [pc, r3]
 *   @0x160280 ldr r1, [r2]
 *   @0x160284 ldr r2, [r3]
 *   @0x160288 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz>
 *   @0x16028c mov r7, r0
 *   @0x160290 mov r0, sp
 *   @0x160294 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0x160298 mov r0, r7
 *   @0x16029c bl 0x2052d4 <_Z8GetDsMapi>
 *   @0x1602a0 mov r6, r0
 *   @0x1602a4 bl 0x17d284 <_Z15AddGraphicsInfoP7CDS_Map>
 *   @0x1602a8 ldr r3, [pc, #0x344]
 *   @0x1602ac mov r0, r5
 *   @0x1602b0 ldr r1, [pc, #0x340]
 *   @0x1602b4 ldr r3, [pc, r3]
 *   @0x1602b8 add r1, pc, r1
 *   @0x1602bc ldr r2, [r3]
 *   @0x1602c0 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz>
 *   @0x1602c4 ldr r1, [pc, #0x330]
 *   @0x1602c8 mov r0, r6
 *   @0x1602cc add r1, pc, r1
 *   @0x1602d0 bl 0x160024 <_Z9FindDSMapP7CDS_MapPKc>
 *   @0x1602d4 mov r1, r4
 *   @0x1602d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1602dc ldr r1, [pc, #0x31c]
 *   @0x1602e0 add r1, pc, r1
 *   @0x1602e4 mov r2, r0
 *   @0x1602e8 mov r0, r5
 *   @0x1602ec bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz>
 *   @0x1602f0 ldr r1, [pc, #0x30c]
 *   @0x1602f4 mov r0, r6
 *   @0x1602f8 add r1, pc, r1
 *   @0x1602fc bl 0x160024 <_Z9FindDSMapP7CDS_MapPKc>
 *   @0x160300 mov r1, r4
 *   @0x160304 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x160308 ldr r1, [pc, #0x2f8]
 *   @0x16030c add r1, pc, r1
 *   @0x160310 mov r2, r0
 *   @0x160314 mov r0, r5
 *   @0x160318 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz>
 *   @0x16031c ldr r1, [pc, #0x2e8]
 *   @0x160320 mov r0, r6
 *   @0x160324 add r1, pc, r1
 *   @0x160328 bl 0x160024 <_Z9FindDSMapP7CDS_MapPKc>
 *   @0x16032c mov r1, r4
 *   @0x160330 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x160334 ldr r1, [pc, #0x2d4]
 *   @0x160338 add r1, pc, r1
 *   @0x16033c mov r2, r0
 *   @0x160340 mov r0, r5
 *   @0x160344 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz>
 *   @0x160348 ldr r1, [pc, #0x2c4]
 *   @0x16034c mov r0, r6
 *   @0x160350 add r1, pc, r1
 *   @0x160354 bl 0x160024 <_Z9FindDSMapP7CDS_MapPKc>
 *   @0x160358 mov r1, r4
 *   @0x16035c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x160360 ldr r1, [pc, #0x2b0]
 *   @0x160364 add r1, pc, r1
 *   @0x160368 mov r2, r0
 *   @0x16036c mov r0, r5
 *   @0x160370 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz>
 *   @0x160374 ldr r1, [pc, #0x2a0]
 *   @0x160378 mov r0, r6
 *   @0x16037c add r1, pc, r1
 *   @0x160380 bl 0x160024 <_Z9FindDSMapP7CDS_MapPKc>
 *   @0x160384 mov r1, r4
 *   @0x160388 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x16038c ldr r1, [pc, #0x28c]
 *   @0x160390 add r1, pc, r1
 *   @0x160394 mov r2, r0
 *   @0x160398 mov r0, r5
 *   @0x16039c bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz>
 *   @0x1603a0 ldr r1, [pc, #0x27c]
 *   @0x1603a4 mov r0, r6
 *   @0x1603a8 add r1, pc, r1
 *   @0x1603ac bl 0x160024 <_Z9FindDSMapP7CDS_MapPKc>
 *   @0x1603b0 mov r1, r4
 *   @0x1603b4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1603b8 ldr r1, [pc, #0x268]
 *   @0x1603bc add r1, pc, r1
 *   @0x1603c0 mov r2, r0
 *   @0x1603c4 mov r0, r5
 *   @0x1603c8 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz>
 *   @0x1603cc ldr r1, [pc, #0x258]
 *   @0x1603d0 mov r0, r6
 *   @0x1603d4 add r1, pc, r1
 *   @0x1603d8 bl 0x160024 <_Z9FindDSMapP7CDS_MapPKc>
 *   @0x1603dc mov r1, r4
 *   @0x1603e0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1603e4 ldr r1, [pc, #0x244]
 *   @0x1603e8 add r1, pc, r1
 *   @0x1603ec mov r2, r0
 *   @0x1603f0 mov r0, r5
 *   @0x1603f4 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz>
 *   @0x1603f8 ldr r1, [pc, #0x234]
 *   @0x1603fc mov r0, r6
 *   @0x160400 add r1, pc, r1
 *   @0x160404 bl 0x160024 <_Z9FindDSMapP7CDS_MapPKc>
 *   @0x160408 mov r1, r4
 *   @0x16040c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x160410 ldr r1, [pc, #0x220]
 *   @0x160414 add r1, pc, r1
 *   @0x160418 mov r2, r0
 *   @0x16041c mov r0, r5
 *   @0x160420 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz>
 *   @0x160424 ldr r1, [pc, #0x210]
 *   @0x160428 mov r0, r6
 *   @0x16042c add r1, pc, r1
 *   @0x160430 bl 0x160024 <_Z9FindDSMapP7CDS_MapPKc>
 *   @0x160434 mov r1, r4
 *   @0x160438 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x16043c ldr r1, [pc, #0x1fc]
 *   @0x160440 add r1, pc, r1
 *   @0x160444 mov r2, r0
 *   @0x160448 mov r0, r5
 *   @0x16044c bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz>
 *   @0x160450 ldr r1, [pc, #0x1ec]
 *   @0x160454 mov r0, r6
 *   @0x160458 add r1, pc, r1
 *   @0x16045c bl 0x160024 <_Z9FindDSMapP7CDS_MapPKc>
 *   @0x160460 mov r1, r4
 *   @0x160464 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x160468 ldr r1, [pc, #0x1d8]
 *   @0x16046c add r1, pc, r1
 *   @0x160470 mov r2, r0
 *   @0x160474 mov r0, r5
 *   @0x160478 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz>
 *   @0x16047c ldr r1, [pc, #0x1c8]
 *   @0x160480 mov r0, r6
 *   @0x160484 add r1, pc, r1
 *   @0x160488 bl 0x160024 <_Z9FindDSMapP7CDS_MapPKc>
 *   @0x16048c mov r1, r4
 *   @0x160490 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x160494 ldr r1, [pc, #0x1b4]
 *   @0x160498 add r1, pc, r1
 *   @0x16049c mov r2, r0
 *   @0x1604a0 mov r0, r5
 *   @0x1604a4 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz>
 *   @0x1604a8 ldr r1, [pc, #0x1a4]
 *   @0x1604ac mov r0, r6
 *   @0x1604b0 add r1, pc, r1
 *   @0x1604b4 bl 0x160024 <_Z9FindDSMapP7CDS_MapPKc>
 *   @0x1604b8 mov r1, r4
 *   @0x1604bc bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1604c0 ldr r1, [pc, #0x190]
 *   @0x1604c4 add r1, pc, r1
 *   @0x1604c8 mov r2, r0
 *   @0x1604cc mov r0, r5
 *   @0x1604d0 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz>
 *   @0x1604d4 ldr r1, [pc, #0x180]
 *   @0x1604d8 mov r0, r6
 *   @0x1604dc add r1, pc, r1
 *   @0x1604e0 bl 0x160024 <_Z9FindDSMapP7CDS_MapPKc>
 *   @0x1604e4 mov r1, r4
 *   @0x1604e8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1604ec ldr r1, [pc, #0x16c]
 *   @0x1604f0 add r1, pc, r1
 *   @0x1604f4 mov r2, r0
 *   @0x1604f8 mov r0, r5
 *   @0x1604fc bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz>
 *   @0x160500 ldr r1, [pc, #0x15c]
 *   @0x160504 mov r0, r6
 *   @0x160508 add r1, pc, r1
 *   @0x16050c bl 0x160024 <_Z9FindDSMapP7CDS_MapPKc>
 *   @0x160510 mov r1, r4
 *   @0x160514 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x160518 ldr r1, [pc, #0x148]
 *   @0x16051c add r1, pc, r1
 *   @0x160520 mov r2, r0
 *   @0x160524 mov r0, r5
 *   @0x160528 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz>
 *   @0x16052c ldr r1, [pc, #0x138]
 *   @0x160530 mov r0, r6
 *   @0x160534 add r1, pc, r1
 *   @0x160538 bl 0x160024 <_Z9FindDSMapP7CDS_MapPKc>
 *   @0x16053c mov r1, r4
 *   @0x160540 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x160544 ldr r1, [pc, #0x124]
 *   @0x160548 add r1, pc, r1
 *   @0x16054c mov r2, r0
 *   @0x160550 mov r0, r5
 *   @0x160554 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz>
 *   @0x160558 ldr r1, [pc, #0x114]
 *   @0x16055c mov r0, r6
 *   @0x160560 add r1, pc, r1
 *   @0x160564 bl 0x160024 <_Z9FindDSMapP7CDS_MapPKc>
 *   @0x160568 mov r1, r4
 *   @0x16056c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x160570 ldr r1, [pc, #0x100]
 *   @0x160574 add r1, pc, r1
 *   @0x160578 mov r2, r0
 *   @0x16057c mov r0, r5
 *   @0x160580 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz>
 *   @0x160584 ldr r1, [pc, #0xf0]
 *   @0x160588 mov r0, r6
 *   @0x16058c add r1, pc, r1
 *   @0x160590 bl 0x160024 <_Z9FindDSMapP7CDS_MapPKc>
 *   @0x160594 mov r1, r4
 *   @0x160598 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x16059c ldr r1, [pc, #0xdc]
 *   @0x1605a0 add r1, pc, r1
 *   @0x1605a4 mov r2, r0
 *   @0x1605a8 mov r0, r5
 *   @0x1605ac bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz>
 *   @0x1605b0 mov r0, r7
 *   @0x1605b4 bl 0x205334 <_Z12DestroyDsMapi>
 *   @0x1605b8 ldr r0, [sp, #0x4]
 *   @0x1605bc str r4, [sp, #0xc]
 *   @0x1605c0 bl 0xb6640 <strdup@plt>
 *   @0x1605c4 mov r4, r0
 *   @0x1605c8 mov r0, sp
 *   @0x1605cc bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x1605d0 ldr r0, [sp, #0x4]
 *   @0x1605d4 cmp r0, #0
 *   @0x1605d8 beq 0x1605e0 <_Z17GetOSSpecificJSONv+0x3a0>
 *   @0x1605dc bl 0xb655c <free@plt>
 *   @0x1605e0 mov r0, r4
 *   @0x1605e4 add sp, sp, #16
 *   @0x1605e8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1605ec eoreq sp, r8, r12, lsr #14
 *   @0x1605f0 mlaeq r8, r0, r12, pc
 *   @0x1605f4 eoreq pc, r8, r12, asr r12
 *   @0x1605f8 andseq r9, lr, r8, lsl r6
 *   @0x1605fc andseq r9, lr, r0, lsl r6
 *   @0x160600 andseq r9, lr, r4, lsl #12
 *   @0x160604 ldrsheq r9, [lr], -r12
 *   @0x160608 ldrsheq r9, [lr], -r0
 *   @0x16060c andseq r9, lr, r8, ror #11
 *   @0x160610 ldrsbeq r9, [lr], -r12
 *   @0x160614 ldrsbeq r9, [lr], -r4
 *   @0x160618 andseq r9, lr, r8, asr #11
 *   @0x16061c andseq r9, lr, r0, asr #11
 *   @0x160620 ldrheq r9, [lr], -r12
 *   @0x160624 ldrheq r9, [lr], -r4
 *   @0x160628 andseq r9, lr, r8, lsr #11
 *   @0x16062c andseq r9, lr, r0, lsr #11
 *   @0x160630 mulseq lr, r8, r5
 *   @0x160634 mulseq lr, r0, r5
 *   @0x160638 andseq r9, lr, r8, lsl #11
 *   @0x16063c andseq r9, lr, r0, lsl #11
 *   @0x160640 andseq r9, lr, r4, ror r5
 *   @0x160644 andseq r9, lr, r12, ror #10
 *   @0x160648 andseq r9, lr, r0, ror #10
 *   @0x16064c andseq r9, lr, r8, asr r5
 *   @0x160650 andseq r9, lr, r4, asr r5
 *   @0x160654 andseq r9, lr, r8, asr #10
 *   @0x160658 andseq r9, lr, r12, lsr r5
 *   @0x16065c andseq r9, lr, r4, lsr r5
 *   @0x160660 andseq r9, lr, r12, lsr #10
 *   @0x160664 andseq r9, lr, r4, lsr #10
 *   @0x160668 andseq r9, lr, r12, lsl r5
 *   @0x16066c andseq r9, lr, r0, lsl r5
 *   @0x160670 andseq r9, lr, r8, lsl #10
 *   @0x160674 ldrsheq r9, [lr], -r12
 *   @0x160678 andseq r9, lr, r4, lsl #10
 *   @0x16067c ldrsheq r9, [lr], -r12
 *   @0x160680 ldrsheq r9, [lr], -r12
 *
 * ══ §24/25 CopyRefArrayAndUnref  0xd064c  size 1084  271 条（0xd064c..0xd0a88）
 * @func 0xd064c 0xd0a88  size 1084  271 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×6 / UNLOCK_RVALUE_MUTEX()×6 / YYFree(void const*)×6 / operator delete(void*)×6 / MemoryManager::SetLength(void**, unsigned int, char const*, int)×2 / ARRAY_RefAlloc(void*) / CopyRefArrayAndUnref(RefDynamicArrayOfRValue*, void*)+0x360 / CopyRefArrayAndUnref(RefDynamicArrayOfRValue*, void*)+0x1c8
 * 字段偏移 top8: 0x4×31 / 0x8×14 / 0x-10×11 / 0x10×10 / 0xc×9 / 0x-4×5 / 0x3×4 / 0x-8×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd064c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xd0650 cmp r0, #0
 *   @0xd0654 sub sp, sp, #28
 *   @0xd0658 str r0, [sp, #0x10]
 *   @0xd065c beq 0xd0a08 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x3bc>
 *   @0xd0660 mov r0, r1
 *   @0xd0664 bl 0xced9c <_Z14ARRAY_RefAllocPv>
 *   @0xd0668 str r0, [sp, #0xc]
 *   @0xd066c ldr r0, [sp, #0x10]
 *   @0xd0670 ldr r2, [sp, #0xc]
 *   @0xd0674 ldr r1, [r0, #0x10]
 *   @0xd0678 cmp r1, #0
 *   @0xd067c str r1, [r2, #0x10]
 *   @0xd0680 ble 0xd09ac <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x360>
 *   @0xd0684 mov r0, r2
 *   @0xd0688 ldr r2, [pc, #0x3f0]
 *   @0xd068c mov r9, #0
 *   @0xd0690 movw r3, #0x226
 *   @0xd0694 add r2, pc, r2
 *   @0xd0698 lsl r1, r1, #3
 *   @0xd069c str r9, [r0, #0x4]!
 *   @0xd06a0 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xd06a4 ldr r3, [sp, #0xc]
 *   @0xd06a8 ldr r2, [r3, #0x10]
 *   @0xd06ac cmp r2, r9
 *   @0xd06b0 ble 0xd0814 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x1c8>
 *   @0xd06b4 ldr r3, [pc, #0x3c8]
 *   @0xd06b8 mov r7, r9
 *   @0xd06bc str r9, [sp, #0x8]
 *   @0xd06c0 add r3, pc, r3
 *   @0xd06c4 str r3, [sp, #0x14]
 *   @0xd06c8 ldr r0, [sp, #0x10]
 *   @0xd06cc ldr r1, [sp, #0x8]
 *   @0xd06d0 ldr r4, [r0, #0x4]
 *   @0xd06d4 ldr r0, [sp, #0xc]
 *   @0xd06d8 lsl r6, r1, #3
 *   @0xd06dc add r10, r4, r6
 *   @0xd06e0 ldr r1, [r4, r1, lsl #3]
 *   @0xd06e4 ldr r3, [r0, #0x4]
 *   @0xd06e8 cmp r1, #0
 *   @0xd06ec ldr r5, [r10, #0x4]
 *   @0xd06f0 add r6, r3, r6
 *   @0xd06f4 ble 0xd091c <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x2d0>
 *   @0xd06f8 ldr r2, [sp, #0x8]
 *   @0xd06fc add r0, r6, #4
 *   @0xd0700 str r1, [r3, r2, lsl #3]
 *   @0xd0704 movw r3, #0x235
 *   @0xd0708 lsl r1, r1, #4
 *   @0xd070c ldr r2, [sp, #0x14]
 *   @0xd0710 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xd0714 ldr r0, [sp, #0x8]
 *   @0xd0718 ldr r3, [r4, r0, lsl #3]
 *   @0xd071c ldr r4, [r6, #0x4]
 *   @0xd0720 cmp r3, #0
 *   @0xd0724 addgt r4, r4, #16
 *   @0xd0728 addgt r5, r5, #16
 *   @0xd072c movgt r11, #0
 *   @0xd0730 ble 0xd09bc <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x370>
 *   @0xd0734 ldr r2, [r4, #-0x4]
 *   @0xd0738 sub r8, r5, #16
 *   @0xd073c sub r6, r4, #16
 *   @0xd0740 bic r3, r2, #-16777216
 *   @0xd0744 cmp r3, #1
 *   @0xd0748 beq 0xd08a4 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x258>
 *   @0xd074c cmp r3, #2
 *   @0xd0750 bne 0xd0774 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x128>
 *   @0xd0754 sub r2, r2, #1
 *   @0xd0758 bic r2, r2, #-16777216
 *   @0xd075c bic r2, r2, #3
 *   @0xd0760 cmp r2, #0
 *   @0xd0764 beq 0xd0910 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x2c4>
 *   @0xd0768 mov r2, #5
 *   @0xd076c str r7, [r4, #-0x8]
 *   @0xd0770 str r2, [r4, #-0x4]
 *   @0xd0774 str r7, [r4, #-0x10]
 *   @0xd0778 ldr r3, [r5, #-0x4]
 *   @0xd077c str r3, [r4, #-0x4]
 *   @0xd0780 ldr r3, [r5, #-0x8]
 *   @0xd0784 str r3, [r4, #-0x8]
 *   @0xd0788 ldr r3, [r5, #-0x4]
 *   @0xd078c bic r3, r3, #-16777216
 *   @0xd0790 cmp r3, #14
 *   @0xd0794 addls pc, pc, r3, lsl #2
 *   @0xd0798 b 0xd07e0 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x194>
 *   @0xd079c b 0xd0830 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x1e4>
 *   @0xd07a0 b 0xd0868 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x21c>
 *   @0xd07a4 b 0xd083c <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x1f0>
 *   @0xd07a8 b 0xd07d8 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x18c>
 *   @0xd07ac b 0xd07e0 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x194>
 *   @0xd07b0 b 0xd07e0 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x194>
 *   @0xd07b4 b 0xd0880 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x234>
 *   @0xd07b8 b 0xd07d8 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x18c>
 *   @0xd07bc b 0xd07e0 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x194>
 *   @0xd07c0 b 0xd07e0 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x194>
 *   @0xd07c4 b 0xd0830 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x1e4>
 *   @0xd07c8 b 0xd07e0 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x194>
 *   @0xd07cc b 0xd07e0 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x194>
 *   @0xd07d0 b 0xd0830 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x1e4>
 *   @0xd07d4 b 0xd07d8 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x18c>
 *   @0xd07d8 ldr r3, [r5, #-0x10]
 *   @0xd07dc str r3, [r4, #-0x10]
 *   @0xd07e0 ldr r3, [r10]
 *   @0xd07e4 add r11, r11, #1
 *   @0xd07e8 add r4, r4, #16
 *   @0xd07ec add r5, r5, #16
 *   @0xd07f0 cmp r3, r11
 *   @0xd07f4 bgt 0xd0734 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0xe8>
 *   @0xd07f8 ldr r3, [sp, #0xc]
 *   @0xd07fc ldr r2, [r3, #0x10]
 *   @0xd0800 ldr r1, [sp, #0x8]
 *   @0xd0804 add r1, r1, #1
 *   @0xd0808 str r1, [sp, #0x8]
 *   @0xd080c cmp r2, r1
 *   @0xd0810 bgt 0xd06c8 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x7c>
 *   @0xd0814 ldr r1, [sp, #0x10]
 *   @0xd0818 ldr r3, [r1]
 *   @0xd081c sub r3, r3, #1
 *   @0xd0820 str r3, [r1]
 *   @0xd0824 ldr r0, [sp, #0xc]
 *   @0xd0828 add sp, sp, #28
 *   @0xd082c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xd0830 ldm r8, {r2, r3}
 *   @0xd0834 stm r6, {r2, r3}
 *   @0xd0838 b 0xd07e0 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x194>
 *   @0xd083c ldr r3, [r5, #-0x10]
 *   @0xd0840 cmp r3, #0
 *   @0xd0844 str r3, [r4, #-0x10]
 *   @0xd0848 beq 0xd07e0 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x194>
 *   @0xd084c ldr r1, [r3, #0x8]
 *   @0xd0850 ldr r2, [r3]
 *   @0xd0854 cmp r1, #0
 *   @0xd0858 streq r6, [r3, #0x8]
 *   @0xd085c add r2, r2, #1
 *   @0xd0860 str r2, [r3]
 *   @0xd0864 b 0xd07e0 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x194>
 *   @0xd0868 ldr r3, [r5, #-0x10]
 *   @0xd086c cmp r3, #0
 *   @0xd0870 ldrne r2, [r3, #0x4]
 *   @0xd0874 addne r2, r2, #1
 *   @0xd0878 strne r2, [r3, #0x4]
 *   @0xd087c b 0xd07dc <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x190>
 *   @0xd0880 ldr r3, [r5, #-0x10]
 *   @0xd0884 str r3, [r4, #-0x10]
 *   @0xd0888 ldr r3, [r5, #-0x10]
 *   @0xd088c cmp r3, #0
 *   @0xd0890 beq 0xd07e0 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x194>
 *   @0xd0894 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0xd0898 ldr r1, [r5, #-0x10]
 *   @0xd089c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0xd08a0 b 0xd07e0 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x194>
 *   @0xd08a4 ldr r9, [r4, #-0x10]
 *   @0xd08a8 cmp r9, #0
 *   @0xd08ac beq 0xd0774 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x128>
 *   @0xd08b0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xd08b4 ldr r3, [r9, #0x4]
 *   @0xd08b8 sub r3, r3, #1
 *   @0xd08bc str r3, [r9, #0x4]
 *   @0xd08c0 cmp r3, #0
 *   @0xd08c4 beq 0xd08d0 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x284>
 *   @0xd08c8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xd08cc b 0xd0774 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x128>
 *   @0xd08d0 ldr r0, [r9]
 *   @0xd08d4 str r3, [sp, #0x4]
 *   @0xd08d8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xd08dc ldr r3, [sp, #0x4]
 *   @0xd08e0 str r3, [r9]
 *   @0xd08e4 str r3, [r9, #0x8]
 *   @0xd08e8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xd08ec ldr r3, [r9, #0x4]
 *   @0xd08f0 sub r3, r3, #1
 *   @0xd08f4 str r3, [r9, #0x4]
 *   @0xd08f8 cmp r3, #0
 *   @0xd08fc beq 0xd092c <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x2e0>
 *   @0xd0900 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xd0904 mov r0, r9
 *   @0xd0908 bl 0x27d1d0 <_ZdlPv>
 *   @0xd090c b 0xd08c8 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x27c>
 *   @0xd0910 mov r0, r6
 *   @0xd0914 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xd0918 b 0xd0768 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x11c>
 *   @0xd091c ldr r0, [sp, #0x8]
 *   @0xd0920 str r7, [r3, r0, lsl #3]
 *   @0xd0924 str r7, [r6, #0x4]
 *   @0xd0928 b 0xd0800 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x1b4>
 *   @0xd092c ldr r0, [r9]
 *   @0xd0930 str r3, [sp, #0x4]
 *   @0xd0934 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xd0938 ldr r3, [sp, #0x4]
 *   @0xd093c str r3, [r9]
 *   @0xd0940 str r3, [r9, #0x8]
 *   @0xd0944 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xd0948 ldr r3, [r9, #0x4]
 *   @0xd094c sub r3, r3, #1
 *   @0xd0950 str r3, [r9, #0x4]
 *   @0xd0954 cmp r3, #0
 *   @0xd0958 beq 0xd096c <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x320>
 *   @0xd095c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xd0960 mov r0, r9
 *   @0xd0964 bl 0x27d1d0 <_ZdlPv>
 *   @0xd0968 b 0xd0900 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x2b4>
 *   @0xd096c ldr r0, [r9]
 *   @0xd0970 str r3, [sp, #0x4]
 *   @0xd0974 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xd0978 ldr r3, [sp, #0x4]
 *   @0xd097c str r3, [r9]
 *   @0xd0980 str r3, [r9, #0x8]
 *   @0xd0984 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xd0988 ldr r3, [r9, #0x4]
 *   @0xd098c sub r3, r3, #1
 *   @0xd0990 str r3, [r9, #0x4]
 *   @0xd0994 cmp r3, #0
 *   @0xd0998 beq 0xd09c8 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x37c>
 *   @0xd099c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xd09a0 mov r0, r9
 *   @0xd09a4 bl 0x27d1d0 <_ZdlPv>
 *   @0xd09a8 b 0xd095c <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x310>
 *   @0xd09ac ldr r0, [sp, #0xc]
 *   @0xd09b0 mov r3, #0
 *   @0xd09b4 str r3, [r0, #0x4]
 *   @0xd09b8 b 0xd0814 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x1c8>
 *   @0xd09bc ldr r1, [sp, #0xc]
 *   @0xd09c0 ldr r2, [r1, #0x10]
 *   @0xd09c4 b 0xd0800 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x1b4>
 *   @0xd09c8 ldr r0, [r9]
 *   @0xd09cc str r3, [sp, #0x4]
 *   @0xd09d0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xd09d4 ldr r3, [sp, #0x4]
 *   @0xd09d8 str r3, [r9]
 *   @0xd09dc str r3, [r9, #0x8]
 *   @0xd09e0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xd09e4 ldr r3, [r9, #0x4]
 *   @0xd09e8 sub r3, r3, #1
 *   @0xd09ec str r3, [r9, #0x4]
 *   @0xd09f0 cmp r3, #0
 *   @0xd09f4 beq 0xd0a14 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x3c8>
 *   @0xd09f8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xd09fc mov r0, r9
 *   @0xd0a00 bl 0x27d1d0 <_ZdlPv>
 *   @0xd0a04 b 0xd099c <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x350>
 *   @0xd0a08 ldr r2, [sp, #0x10]
 *   @0xd0a0c str r2, [sp, #0xc]
 *   @0xd0a10 b 0xd0824 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x1d8>
 *   @0xd0a14 ldr r0, [r9]
 *   @0xd0a18 str r3, [sp, #0x4]
 *   @0xd0a1c bl 0xcef90 <_Z6YYFreePKv>
 *   @0xd0a20 ldr r3, [sp, #0x4]
 *   @0xd0a24 str r3, [r9]
 *   @0xd0a28 str r3, [r9, #0x8]
 *   @0xd0a2c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xd0a30 ldr r3, [r9, #0x4]
 *   @0xd0a34 sub r3, r3, #1
 *   @0xd0a38 str r3, [r9, #0x4]
 *   @0xd0a3c cmp r3, #0
 *   @0xd0a40 beq 0xd0a54 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x408>
 *   @0xd0a44 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xd0a48 mov r0, r9
 *   @0xd0a4c bl 0x27d1d0 <_ZdlPv>
 *   @0xd0a50 b 0xd09f8 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x3ac>
 *   @0xd0a54 ldr r0, [r9]
 *   @0xd0a58 str r3, [sp, #0x4]
 *   @0xd0a5c bl 0xcef90 <_Z6YYFreePKv>
 *   @0xd0a60 ldr r3, [sp, #0x4]
 *   @0xd0a64 mov r0, r9
 *   @0xd0a68 str r3, [r9]
 *   @0xd0a6c str r3, [r9, #0x8]
 *   @0xd0a70 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0xd0a74 mov r0, r9
 *   @0xd0a78 bl 0x27d1d0 <_ZdlPv>
 *   @0xd0a7c b 0xd0a44 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x3f8>
 *   @0xd0a80 eoreq r1, r6, r8, ror #22
 *   @0xd0a84 eoreq r1, r6, r12, lsr r11
 *
 * ══ §25/25 _pcre_xclass  0x266cac  size 1040  260 条（0x266cac..0x2670bc）
 * @func 0x266cac 0x2670bc  size 1040  260 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _pcre_xclass+0xa8 / _pcre_xclass+0xe4 / _pcre_xclass+0x110
 * 字段偏移 top8: 0x2×14 / 0x1×9 / 0x3×8 / 0x4×6 / 0x5×4 / 0x-2×3 / 0x-3×2 / 0x6×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x266cac push {r4, r5, r6, r7, r8}
 *   @0x266cb0 cmp r0, #255
 *   @0x266cb4 ldrb r3, [r1]
 *   @0x266cb8 and r4, r3, #1
 *   @0x266cbc bhi 0x266ea4 <_pcre_xclass+0x1f8>
 *   @0x266cc0 tst r3, #4
 *   @0x266cc4 bne 0x266cdc <_pcre_xclass+0x30>
 *   @0x266cc8 tst r3, #2
 *   @0x266ccc bne 0x267038 <_pcre_xclass+0x38c>
 *   @0x266cd0 mov r0, r4
 *   @0x266cd4 pop {r4, r5, r6, r7, r8}
 *   @0x266cd8 bx lr
 *   @0x266cdc tst r3, #2
 *   @0x266ce0 beq 0x266d10 <_pcre_xclass+0x64>
 *   @0x266ce4 add r2, r1, r0, lsr #3
 *   @0x266ce8 and r3, r0, #7
 *   @0x266cec ldrb r2, [r2, #0x1]
 *   @0x266cf0 asr r3, r2, r3
 *   @0x266cf4 tst r3, #1
 *   @0x266cf8 beq 0x266eac <_pcre_xclass+0x200>
 *   @0x266cfc eor r0, r4, #1
 *   @0x266d00 pop {r4, r5, r6, r7, r8}
 *   @0x266d04 bx lr
 *   @0x266d08 cmp r3, #2
 *   @0x266d0c beq 0x266d64 <_pcre_xclass+0xb8>
 *   @0x266d10 add r1, r1, #1
 *   @0x266d14 ldrb r3, [r1]
 *   @0x266d18 cmp r3, #0
 *   @0x266d1c beq 0x266cd0 <_pcre_xclass+0x24>
 *   @0x266d20 cmp r3, #1
 *   @0x266d24 bne 0x266d08 <_pcre_xclass+0x5c>
 *   @0x266d28 ldrb r3, [r1, #0x1]
 *   @0x266d2c cmp r3, #191
 *   @0x266d30 addls r1, r1, #2
 *   @0x266d34 bls 0x266d54 <_pcre_xclass+0xa8>
 *   @0x266d38 tst r3, #32
 *   @0x266d3c bne 0x266ddc <_pcre_xclass+0x130>
 *   @0x266d40 ldrb r2, [r1, #0x2]
 *   @0x266d44 and r3, r3, #31
 *   @0x266d48 add r1, r1, #3
 *   @0x266d4c and r2, r2, #63
 *   @0x266d50 orr r3, r2, r3, lsl #6
 *   @0x266d54 cmp r0, r3
 *   @0x266d58 bne 0x266d14 <_pcre_xclass+0x68>
 *   @0x266d5c eor r0, r4, #1
 *   @0x266d60 b 0x266d00 <_pcre_xclass+0x54>
 *   @0x266d64 ldrb r3, [r1, #0x1]
 *   @0x266d68 cmp r3, #191
 *   @0x266d6c addls r12, r1, #2
 *   @0x266d70 bls 0x266d90 <_pcre_xclass+0xe4>
 *   @0x266d74 tst r3, #32
 *   @0x266d78 bne 0x266e0c <_pcre_xclass+0x160>
 *   @0x266d7c ldrb r2, [r1, #0x2]
 *   @0x266d80 and r3, r3, #31
 *   @0x266d84 add r12, r1, #3
 *   @0x266d88 and r2, r2, #63
 *   @0x266d8c orr r3, r2, r3, lsl #6
 *   @0x266d90 ldrb r2, [r12]
 *   @0x266d94 cmp r2, #191
 *   @0x266d98 addls r1, r12, #1
 *   @0x266d9c bls 0x266dbc <_pcre_xclass+0x110>
 *   @0x266da0 tst r2, #32
 *   @0x266da4 bne 0x266e3c <_pcre_xclass+0x190>
 *   @0x266da8 ldrb r5, [r12, #0x1]
 *   @0x266dac and r2, r2, #31
 *   @0x266db0 add r1, r12, #2
 *   @0x266db4 and r12, r5, #63
 *   @0x266db8 orr r2, r12, r2, lsl #6
 *   @0x266dbc cmp r0, r2
 *   @0x266dc0 movhi r2, #0
 *   @0x266dc4 movls r2, #1
 *   @0x266dc8 cmp r0, r3
 *   @0x266dcc movlo r2, #0
 *   @0x266dd0 cmp r2, #0
 *   @0x266dd4 beq 0x266d14 <_pcre_xclass+0x68>
 *   @0x266dd8 b 0x266cfc <_pcre_xclass+0x50>
 *   @0x266ddc tst r3, #16
 *   @0x266de0 bne 0x266e6c <_pcre_xclass+0x1c0>
 *   @0x266de4 ldrb r12, [r1, #0x3]
 *   @0x266de8 lsl r3, r3, #12
 *   @0x266dec ldrb r2, [r1, #0x2]
 *   @0x266df0 add r1, r1, #4
 *   @0x266df4 uxth r3, r3
 *   @0x266df8 and r12, r12, #63
 *   @0x266dfc and r2, r2, #63
 *   @0x266e00 orr r3, r3, r12
 *   @0x266e04 orr r3, r3, r2, lsl #6
 *   @0x266e08 b 0x266d54 <_pcre_xclass+0xa8>
 *   @0x266e0c tst r3, #16
 *   @0x266e10 bne 0x266eb4 <_pcre_xclass+0x208>
 *   @0x266e14 ldrb r2, [r1, #0x2]
 *   @0x266e18 lsl r3, r3, #12
 *   @0x266e1c ldrb r5, [r1, #0x3]
 *   @0x266e20 add r12, r1, #4
 *   @0x266e24 uxth r3, r3
 *   @0x266e28 and r2, r2, #63
 *   @0x266e2c and r1, r5, #63
 *   @0x266e30 orr r3, r3, r1
 *   @0x266e34 orr r3, r3, r2, lsl #6
 *   @0x266e38 b 0x266d90 <_pcre_xclass+0xe4>
 *   @0x266e3c tst r2, #16
 *   @0x266e40 bne 0x266f00 <_pcre_xclass+0x254>
 *   @0x266e44 ldrb r5, [r12, #0x2]
 *   @0x266e48 lsl r2, r2, #12
 *   @0x266e4c ldrb r6, [r12, #0x1]
 *   @0x266e50 add r1, r12, #3
 *   @0x266e54 uxth r2, r2
 *   @0x266e58 and r5, r5, #63
 *   @0x266e5c and r12, r6, #63
 *   @0x266e60 orr r2, r2, r5
 *   @0x266e64 orr r2, r2, r12, lsl #6
 *   @0x266e68 b 0x266dbc <_pcre_xclass+0x110>
 *   @0x266e6c tst r3, #8
 *   @0x266e70 bne 0x266f4c <_pcre_xclass+0x2a0>
 *   @0x266e74 ldrb r5, [r1, #0x4]
 *   @0x266e78 and r3, r3, #7
 *   @0x266e7c ldrb r12, [r1, #0x2]
 *   @0x266e80 add r1, r1, #5
 *   @0x266e84 ldrb r2, [r1, #-0x2]
 *   @0x266e88 and r5, r5, #63
 *   @0x266e8c and r12, r12, #63
 *   @0x266e90 orr r3, r5, r3, lsl #18
 *   @0x266e94 and r2, r2, #63
 *   @0x266e98 orr r3, r3, r12, lsl #12
 *   @0x266e9c orr r3, r3, r2, lsl #6
 *   @0x266ea0 b 0x266d54 <_pcre_xclass+0xa8>
 *   @0x266ea4 tst r3, #2
 *   @0x266ea8 beq 0x266d10 <_pcre_xclass+0x64>
 *   @0x266eac add r1, r1, #33
 *   @0x266eb0 b 0x266d14 <_pcre_xclass+0x68>
 *   @0x266eb4 tst r3, #8
 *   @0x266eb8 beq 0x266fc0 <_pcre_xclass+0x314>
 *   @0x266ebc tst r3, #4
 *   @0x266ec0 bne 0x267088 <_pcre_xclass+0x3dc>
 *   @0x266ec4 ldrb r7, [r1, #0x5]
 *   @0x266ec8 and r3, r3, #3
 *   @0x266ecc ldrb r5, [r1, #0x2]
 *   @0x266ed0 add r12, r1, #6
 *   @0x266ed4 and r7, r7, #63
 *   @0x266ed8 ldrb r6, [r1, #0x3]
 *   @0x266edc ldrb r2, [r1, #0x4]
 *   @0x266ee0 and r5, r5, #63
 *   @0x266ee4 orr r3, r7, r3, lsl #24
 *   @0x266ee8 and r1, r6, #63
 *   @0x266eec orr r3, r3, r5, lsl #18
 *   @0x266ef0 and r2, r2, #63
 *   @0x266ef4 orr r3, r3, r1, lsl #12
 *   @0x266ef8 orr r3, r3, r2, lsl #6
 *   @0x266efc b 0x266d90 <_pcre_xclass+0xe4>
 *   @0x266f00 tst r2, #8
 *   @0x266f04 beq 0x266f90 <_pcre_xclass+0x2e4>
 *   @0x266f08 tst r2, #4
 *   @0x266f0c bne 0x267054 <_pcre_xclass+0x3a8>
 *   @0x266f10 ldrb r7, [r12, #0x4]
 *   @0x266f14 and r2, r2, #3
 *   @0x266f18 ldrb r6, [r12, #0x1]
 *   @0x266f1c add r1, r12, #5
 *   @0x266f20 ldrb r5, [r12, #0x2]
 *   @0x266f24 and r7, r7, #63
 *   @0x266f28 ldrb r12, [r12, #0x3]
 *   @0x266f2c and r6, r6, #63
 *   @0x266f30 orr r2, r7, r2, lsl #24
 *   @0x266f34 and r5, r5, #63
 *   @0x266f38 orr r2, r2, r6, lsl #18
 *   @0x266f3c and r12, r12, #63
 *   @0x266f40 orr r2, r2, r5, lsl #12
 *   @0x266f44 orr r2, r2, r12, lsl #6
 *   @0x266f48 b 0x266dbc <_pcre_xclass+0x110>
 *   @0x266f4c tst r3, #4
 *   @0x266f50 bne 0x266ff0 <_pcre_xclass+0x344>
 *   @0x266f54 ldrb r6, [r1, #0x5]
 *   @0x266f58 and r3, r3, #3
 *   @0x266f5c ldrb r5, [r1, #0x2]
 *   @0x266f60 add r1, r1, #6
 *   @0x266f64 ldrb r12, [r1, #-0x3]
 *   @0x266f68 and r6, r6, #63
 *   @0x266f6c ldrb r2, [r1, #-0x2]
 *   @0x266f70 and r5, r5, #63
 *   @0x266f74 orr r3, r6, r3, lsl #24
 *   @0x266f78 and r12, r12, #63
 *   @0x266f7c orr r3, r3, r5, lsl #18
 *   @0x266f80 and r2, r2, #63
 *   @0x266f84 orr r3, r3, r12, lsl #12
 *   @0x266f88 orr r3, r3, r2, lsl #6
 *   @0x266f8c b 0x266d54 <_pcre_xclass+0xa8>
 *   @0x266f90 ldrb r6, [r12, #0x3]
 *   @0x266f94 and r2, r2, #7
 *   @0x266f98 ldrb r5, [r12, #0x1]
 *   @0x266f9c add r1, r12, #4
 *   @0x266fa0 ldrb r12, [r12, #0x2]
 *   @0x266fa4 and r6, r6, #63
 *   @0x266fa8 and r5, r5, #63
 *   @0x266fac orr r2, r6, r2, lsl #18
 *   @0x266fb0 and r12, r12, #63
 *   @0x266fb4 orr r2, r2, r5, lsl #12
 *   @0x266fb8 orr r2, r2, r12, lsl #6
 *   @0x266fbc b 0x266dbc <_pcre_xclass+0x110>
 *   @0x266fc0 ldrb r5, [r1, #0x4]
 *   @0x266fc4 and r3, r3, #7
 *   @0x266fc8 ldrb r6, [r1, #0x2]
 *   @0x266fcc add r12, r1, #5
 *   @0x266fd0 ldrb r2, [r1, #0x3]
 *   @0x266fd4 and r5, r5, #63
 *   @0x266fd8 and r1, r6, #63
 *   @0x266fdc orr r3, r5, r3, lsl #18
 *   @0x266fe0 and r2, r2, #63
 *   @0x266fe4 orr r3, r3, r1, lsl #12
 *   @0x266fe8 orr r3, r3, r2, lsl #6
 *   @0x266fec b 0x266d90 <_pcre_xclass+0xe4>
 *   @0x266ff0 ldrb r2, [r1, #0x6]
 *   @0x266ff4 and r3, r3, #1
 *   @0x266ff8 ldrb r6, [r1, #0x2]
 *   @0x266ffc add r1, r1, #7
 *   @0x267000 ldrb r5, [r1, #-0x4]
 *   @0x267004 and r2, r2, #63
 *   @0x267008 ldrb r12, [r1, #-0x3]
 *   @0x26700c and r6, r6, #63
 *   @0x267010 orr r3, r2, r3, lsl #30
 *   @0x267014 and r5, r5, #63
 *   @0x267018 ldrb r2, [r1, #-0x2]
 *   @0x26701c orr r3, r3, r6, lsl #24
 *   @0x267020 and r12, r12, #63
 *   @0x267024 orr r3, r3, r5, lsl #18
 *   @0x267028 and r2, r2, #63
 *   @0x26702c orr r3, r3, r12, lsl #12
 *   @0x267030 orr r3, r3, r2, lsl #6
 *   @0x267034 b 0x266d54 <_pcre_xclass+0xa8>
 *   @0x267038 add r1, r1, r0, lsr #3
 *   @0x26703c and r0, r0, #7
 *   @0x267040 pop {r4, r5, r6, r7, r8}
 *   @0x267044 ldrb r3, [r1, #0x1]
 *   @0x267048 asr r0, r3, r0
 *   @0x26704c and r0, r0, #1
 *   @0x267050 bx lr
 *   @0x267054 ldrb r8, [r12, #0x5]
 *   @0x267058 and r2, r2, #1
 *   @0x26705c ldrb r7, [r12, #0x1]
 *   @0x267060 add r1, r12, #6
 *   @0x267064 ldrb r6, [r12, #0x2]
 *   @0x267068 and r8, r8, #63
 *   @0x26706c and r7, r7, #63
 *   @0x267070 orr r2, r8, r2, lsl #30
 *   @0x267074 ldrb r5, [r12, #0x3]
 *   @0x267078 and r6, r6, #63
 *   @0x26707c ldrb r12, [r12, #0x4]
 *   @0x267080 orr r2, r2, r7, lsl #24
 *   @0x267084 b 0x266f34 <_pcre_xclass+0x288>
 *   @0x267088 ldrb r2, [r1, #0x6]
 *   @0x26708c and r3, r3, #1
 *   @0x267090 ldrb r7, [r1, #0x2]
 *   @0x267094 add r12, r1, #7
 *   @0x267098 and r2, r2, #63
 *   @0x26709c ldrb r5, [r1, #0x3]
 *   @0x2670a0 and r7, r7, #63
 *   @0x2670a4 orr r3, r2, r3, lsl #30
 *   @0x2670a8 ldrb r6, [r1, #0x4]
 *   @0x2670ac and r5, r5, #63
 *   @0x2670b0 ldrb r2, [r1, #0x5]
 *   @0x2670b4 orr r3, r3, r7, lsl #24
 *   @0x2670b8 b 0x266ee8 <_pcre_xclass+0x23c>
 */
