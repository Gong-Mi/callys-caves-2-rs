/* cally 逆向卡：All_35 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 39 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/39 pcre_fullinfo  0x25ee20  size 808  202 条（0x25ee20..0x25f148）
 * @func 0x25ee20 0x25f148  size 808  202 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×3 / 0x1c×2 / 0xc×1 / 0x8×1 / 0x1e×1 / 0x20×1 / 0x18×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x25ee20 cmp r3, #0
 *   @0x25ee24 cmpne r0, #0
 *   @0x25ee28 push {r4, r5}
 *   @0x25ee2c beq 0x25f10c <pcre_fullinfo+0x2ec>
 *   @0x25ee30 cmp r1, #0
 *   @0x25ee34 moveq r5, r1
 *   @0x25ee38 beq 0x25ee4c <pcre_fullinfo+0x2c>
 *   @0x25ee3c ldr r12, [r1]
 *   @0x25ee40 ands r12, r12, #1
 *   @0x25ee44 ldrne r5, [r1, #0x4]
 *   @0x25ee48 moveq r5, r12
 *   @0x25ee4c ldr r4, [r0]
 *   @0x25ee50 movw r12, #0x5245
 *   @0x25ee54 movt r12, #0x5043
 *   @0x25ee58 cmp r4, r12
 *   @0x25ee5c beq 0x25ee80 <pcre_fullinfo+0x60>
 *   @0x25ee60 movw r3, #0x4350
 *   @0x25ee64 movt r3, #0x4552
 *   @0x25ee68 cmp r4, r3
 *   @0x25ee6c mvnne r2, #3
 *   @0x25ee70 mvneq r2, #28
 *   @0x25ee74 mov r0, r2
 *   @0x25ee78 pop {r4, r5}
 *   @0x25ee7c bx lr
 *   @0x25ee80 ldr r12, [r0, #0xc]
 *   @0x25ee84 tst r12, #1
 *   @0x25ee88 beq 0x25f114 <pcre_fullinfo+0x2f4>
 *   @0x25ee8c cmp r2, #25
 *   @0x25ee90 addls pc, pc, r2, lsl #2
 *   @0x25ee94 b 0x25f13c <pcre_fullinfo+0x31c>
 *   @0x25ee98 b 0x25ef10 <pcre_fullinfo+0xf0>
 *   @0x25ee9c b 0x25ef2c <pcre_fullinfo+0x10c>
 *   @0x25eea0 b 0x25ef3c <pcre_fullinfo+0x11c>
 *   @0x25eea4 b 0x25ef4c <pcre_fullinfo+0x12c>
 *   @0x25eea8 b 0x25ef5c <pcre_fullinfo+0x13c>
 *   @0x25eeac b 0x25ef74 <pcre_fullinfo+0x154>
 *   @0x25eeb0 b 0x25efb8 <pcre_fullinfo+0x198>
 *   @0x25eeb4 b 0x25ef98 <pcre_fullinfo+0x178>
 *   @0x25eeb8 b 0x25efa8 <pcre_fullinfo+0x188>
 *   @0x25eebc b 0x25efc8 <pcre_fullinfo+0x1a8>
 *   @0x25eec0 b 0x25f100 <pcre_fullinfo+0x2e0>
 *   @0x25eec4 b 0x25f0d8 <pcre_fullinfo+0x2b8>
 *   @0x25eec8 b 0x25f0ec <pcre_fullinfo+0x2cc>
 *   @0x25eecc b 0x25f074 <pcre_fullinfo+0x254>
 *   @0x25eed0 b 0x25f084 <pcre_fullinfo+0x264>
 *   @0x25eed4 b 0x25f094 <pcre_fullinfo+0x274>
 *   @0x25eed8 b 0x25f0b0 <pcre_fullinfo+0x290>
 *   @0x25eedc b 0x25efdc <pcre_fullinfo+0x1bc>
 *   @0x25eee0 b 0x25efe8 <pcre_fullinfo+0x1c8>
 *   @0x25eee4 b 0x25eff8 <pcre_fullinfo+0x1d8>
 *   @0x25eee8 b 0x25f00c <pcre_fullinfo+0x1ec>
 *   @0x25eeec b 0x25f028 <pcre_fullinfo+0x208>
 *   @0x25eef0 b 0x25f034 <pcre_fullinfo+0x214>
 *   @0x25eef4 b 0x25f044 <pcre_fullinfo+0x224>
 *   @0x25eef8 b 0x25f05c <pcre_fullinfo+0x23c>
 *   @0x25eefc b 0x25ef00 <pcre_fullinfo+0xe0>
 *   @0x25ef00 ubfx r12, r12, #0xf, #0x1
 *   @0x25ef04 mov r2, #0
 *   @0x25ef08 str r12, [r3]
 *   @0x25ef0c b 0x25ee74 <pcre_fullinfo+0x54>
 *   @0x25ef10 ldr r0, [r0, #0x8]
 *   @0x25ef14 movw r1, #0x7a7f
 *   @0x25ef18 movt r1, #0x27ff
 *   @0x25ef1c mov r2, #0
 *   @0x25ef20 and r1, r0, r1
 *   @0x25ef24 str r1, [r3]
 *   @0x25ef28 b 0x25ee74 <pcre_fullinfo+0x54>
 *   @0x25ef2c ldr r1, [r0, #0x4]
 *   @0x25ef30 mov r2, #0
 *   @0x25ef34 str r1, [r3]
 *   @0x25ef38 b 0x25ee74 <pcre_fullinfo+0x54>
 *   @0x25ef3c ldrh r1, [r0, #30]
 *   @0x25ef40 mov r2, #0
 *   @0x25ef44 str r1, [r3]
 *   @0x25ef48 b 0x25ee74 <pcre_fullinfo+0x54>
 *   @0x25ef4c ldrh r1, [r0, #32]
 *   @0x25ef50 mov r2, #0
 *   @0x25ef54 str r1, [r3]
 *   @0x25ef58 b 0x25ee74 <pcre_fullinfo+0x54>
 *   @0x25ef5c tst r12, #16
 *   @0x25ef60 beq 0x25f124 <pcre_fullinfo+0x304>
 *   @0x25ef64 ldrh r2, [r0, #24]
 *   @0x25ef68 str r2, [r3]
 *   @0x25ef6c mov r2, #0
 *   @0x25ef70 b 0x25ee74 <pcre_fullinfo+0x54>
 *   @0x25ef74 cmp r5, #0
 *   @0x25ef78 beq 0x25ef8c <pcre_fullinfo+0x16c>
 *   @0x25ef7c ldr r2, [r5, #0x4]
 *   @0x25ef80 ands r5, r2, #1
 *   @0x25ef84 ldrne r5, [r1, #0x4]
 *   @0x25ef88 addne r5, r5, #8
 *   @0x25ef8c str r5, [r3]
 *   @0x25ef90 mov r2, #0
 *   @0x25ef94 b 0x25ee74 <pcre_fullinfo+0x54>
 *   @0x25ef98 ldrh r1, [r0, #36]
 *   @0x25ef9c mov r2, #0
 *   @0x25efa0 str r1, [r3]
 *   @0x25efa4 b 0x25ee74 <pcre_fullinfo+0x54>
 *   @0x25efa8 ldrh r1, [r0, #38]
 *   @0x25efac mov r2, #0
 *   @0x25efb0 str r1, [r3]
 *   @0x25efb4 b 0x25ee74 <pcre_fullinfo+0x54>
 *   @0x25efb8 tst r12, #64
 *   @0x25efbc beq 0x25f11c <pcre_fullinfo+0x2fc>
 *   @0x25efc0 ldrh r2, [r0, #26]
 *   @0x25efc4 b 0x25ef68 <pcre_fullinfo+0x148>
 *   @0x25efc8 ldrh r1, [r0, #34]
 *   @0x25efcc mov r2, #0
 *   @0x25efd0 add r0, r0, r1
 *   @0x25efd4 str r0, [r3]
 *   @0x25efd8 b 0x25ee74 <pcre_fullinfo+0x54>
 *   @0x25efdc mov r2, #0
 *   @0x25efe0 str r2, [r3]
 *   @0x25efe4 b 0x25ee74 <pcre_fullinfo+0x54>
 *   @0x25efe8 ldrh r1, [r0, #28]
 *   @0x25efec mov r2, #0
 *   @0x25eff0 str r1, [r3]
 *   @0x25eff4 b 0x25ee74 <pcre_fullinfo+0x54>
 *   @0x25eff8 ands r12, r12, #16
 *   @0x25effc ldrhne r12, [r0, #24]
 *   @0x25f000 str r12, [r3]
 *   @0x25f004 mov r2, #0
 *   @0x25f008 b 0x25ee74 <pcre_fullinfo+0x54>
 *   @0x25f00c tst r12, #16
 *   @0x25f010 movne r2, #1
 *   @0x25f014 bne 0x25ef68 <pcre_fullinfo+0x148>
 *   @0x25f018 tst r12, #256
 *   @0x25f01c moveq r2, #0
 *   @0x25f020 movne r2, #2
 *   @0x25f024 b 0x25ef68 <pcre_fullinfo+0x148>
 *   @0x25f028 ands r12, r12, #64
 *   @0x25f02c ldrhne r12, [r0, #26]
 *   @0x25f030 b 0x25f000 <pcre_fullinfo+0x1e0>
 *   @0x25f034 ubfx r12, r12, #0x6, #0x1
 *   @0x25f038 mov r2, #0
 *   @0x25f03c str r12, [r3]
 *   @0x25f040 b 0x25ee74 <pcre_fullinfo+0x54>
 *   @0x25f044 tst r12, #8192
 *   @0x25f048 beq 0x25f134 <pcre_fullinfo+0x314>
 *   @0x25f04c ldr r1, [r0, #0x10]
 *   @0x25f050 mov r2, #0
 *   @0x25f054 str r1, [r3]
 *   @0x25f058 b 0x25ee74 <pcre_fullinfo+0x54>
 *   @0x25f05c tst r12, #16384
 *   @0x25f060 beq 0x25f134 <pcre_fullinfo+0x314>
 *   @0x25f064 ldr r1, [r0, #0x14]
 *   @0x25f068 mov r2, #0
 *   @0x25f06c str r1, [r3]
 *   @0x25f070 b 0x25ee74 <pcre_fullinfo+0x54>
 *   @0x25f074 ubfx r12, r12, #0xa, #0x1
 *   @0x25f078 mov r2, #0
 *   @0x25f07c str r12, [r3]
 *   @0x25f080 b 0x25ee74 <pcre_fullinfo+0x54>
 *   @0x25f084 ubfx r12, r12, #0xb, #0x1
 *   @0x25f088 mov r2, #0
 *   @0x25f08c str r12, [r3]
 *   @0x25f090 b 0x25ee74 <pcre_fullinfo+0x54>
 *   @0x25f094 cmp r5, #0
 *   @0x25f098 beq 0x25f11c <pcre_fullinfo+0x2fc>
 *   @0x25f09c ldr r2, [r5, #0x4]
 *   @0x25f0a0 tst r2, #2
 *   @0x25f0a4 beq 0x25f11c <pcre_fullinfo+0x2fc>
 *   @0x25f0a8 ldr r2, [r5, #0x28]
 *   @0x25f0ac b 0x25ef68 <pcre_fullinfo+0x148>
 *   @0x25f0b0 cmp r1, #0
 *   @0x25f0b4 moveq r2, r1
 *   @0x25f0b8 beq 0x25ef68 <pcre_fullinfo+0x148>
 *   @0x25f0bc ldr r2, [r1]
 *   @0x25f0c0 ands r2, r2, #64
 *   @0x25f0c4 beq 0x25ef68 <pcre_fullinfo+0x148>
 *   @0x25f0c8 ldr r2, [r1, #0x1c]
 *   @0x25f0cc adds r2, r2, #0
 *   @0x25f0d0 movne r2, #1
 *   @0x25f0d4 b 0x25ef68 <pcre_fullinfo+0x148>
 *   @0x25f0d8 ldr r1, [pc, #0x64]
 *   @0x25f0dc mov r2, #0
 *   @0x25f0e0 ldr r1, [pc, r1]
 *   @0x25f0e4 str r1, [r3]
 *   @0x25f0e8 b 0x25ee74 <pcre_fullinfo+0x54>
 *   @0x25f0ec eor r1, r12, #512
 *   @0x25f0f0 mov r2, #0
 *   @0x25f0f4 ubfx r1, r1, #0x9, #0x1
 *   @0x25f0f8 str r1, [r3]
 *   @0x25f0fc b 0x25ee74 <pcre_fullinfo+0x54>
 *   @0x25f100 cmp r5, #0
 *   @0x25f104 ldrne r5, [r5]
 *   @0x25f108 b 0x25ef8c <pcre_fullinfo+0x16c>
 *   @0x25f10c mvn r2, #1
 *   @0x25f110 b 0x25ee74 <pcre_fullinfo+0x54>
 *   @0x25f114 mvn r2, #27
 *   @0x25f118 b 0x25ee74 <pcre_fullinfo+0x54>
 *   @0x25f11c mvn r2, #0
 *   @0x25f120 b 0x25ef68 <pcre_fullinfo+0x148>
 *   @0x25f124 tst r12, #256
 *   @0x25f128 mvneq r2, #1
 *   @0x25f12c mvnne r2, #0
 *   @0x25f130 b 0x25ef68 <pcre_fullinfo+0x148>
 *   @0x25f134 mvn r2, #32
 *   @0x25f138 b 0x25ee74 <pcre_fullinfo+0x54>
 *   @0x25f13c mvn r2, #2
 *   @0x25f140 b 0x25ee74 <pcre_fullinfo+0x54>
 *   @0x25f144 andseq r2, r9, r8, lsl #14
 *
 * ══ §2/39 Debug_GetBuffers(Buffer_Standard*, Buffer_Standard*)  0x29b098  size 808  202 条（0x29b098..0x29b3c0）
 * @func 0x29b098 0x29b3c0  size 808  202 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / Debug_GetBuffers(Buffer_Standard*, Buffer_Standard*)+0x320 / YYGetUint32(RValue const*, int) / GetIBuffer(int) / Debug_GetBuffers(Buffer_Standard*, Buffer_Standard*)+0x25c
 * 字段偏移 top8: 0x8×13 / 0x38×10 / 0xc×7 / 0x10×4 / 0x30×2 / 0x14×2 / 0x2c×1 / 0x1c×1
 * VFP 指令 32 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29b098 ldr r3, [r0]
 *   @0x29b09c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x29b0a0 add r8, r0, #44
 *   @0x29b0a4 mov r4, r1
 *   @0x29b0a8 sub sp, sp, #28
 *   @0x29b0ac mov r2, r8
 *   @0x29b0b0 mov r9, #0
 *   @0x29b0b4 ldr r3, [r3, #0xc]
 *   @0x29b0b8 mov r1, #6
 *   @0x29b0bc mov r6, r0
 *   @0x29b0c0 blx r3
 *   @0x29b0c4 mov r1, r9
 *   @0x29b0c8 mov r0, r8
 *   @0x29b0cc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x29b0d0 ldr r3, [r4]
 *   @0x29b0d4 add r7, r4, #44
 *   @0x29b0d8 str r9, [r4, #0x38]
 *   @0x29b0dc mov r1, #5
 *   @0x29b0e0 mov r2, r7
 *   @0x29b0e4 vmov s15, r0
 *   @0x29b0e8 str r0, [sp, #0xc]
 *   @0x29b0ec mov r0, r4
 *   @0x29b0f0 vcvt.f64.u32 d7, s15
 *   @0x29b0f4 vmov r10, r11, d7
 *   @0x29b0f8 vstr s14, [r4, #44]
 *   @0x29b0fc str r11, [r4, #0x30]
 *   @0x29b100 ldr r3, [r3, #0x8]
 *   @0x29b104 blx r3
 *   @0x29b108 ldr r12, [sp, #0xc]
 *   @0x29b10c cmp r12, r9
 *   @0x29b110 ble 0x29b3b8 <_Z16Debug_GetBuffersP15Buffer_StandardS0_+0x320>
 *   @0x29b114 mov r12, r9
 *   @0x29b118 movt r12, #0xffe0
 *   @0x29b11c str r12, [sp, #0x10]
 *   @0x29b120 movw r12, #0xffff
 *   @0x29b124 movt r12, #0x41ef
 *   @0x29b128 str r12, [sp, #0x14]
 *   @0x29b12c b 0x29b170 <_Z16Debug_GetBuffersP15Buffer_StandardS0_+0xd8>
 *   @0x29b130 ldr r12, [sp, #0x10]
 *   @0x29b134 mov lr, #0
 *   @0x29b138 ldr r3, [r4]
 *   @0x29b13c mov r0, r4
 *   @0x29b140 mov r1, #5
 *   @0x29b144 mov r2, r7
 *   @0x29b148 str r12, [r4, #0x2c]
 *   @0x29b14c add r9, r9, #1
 *   @0x29b150 ldr r12, [sp, #0x14]
 *   @0x29b154 str lr, [r4, #0x38]
 *   @0x29b158 str r12, [r4, #0x30]
 *   @0x29b15c ldr r3, [r3, #0x8]
 *   @0x29b160 blx r3
 *   @0x29b164 ldr r12, [sp, #0xc]
 *   @0x29b168 cmp r9, r12
 *   @0x29b16c beq 0x29b3b8 <_Z16Debug_GetBuffersP15Buffer_StandardS0_+0x320>
 *   @0x29b170 ldr r3, [r6]
 *   @0x29b174 mov r2, r8
 *   @0x29b178 mov r1, #6
 *   @0x29b17c mov r0, r6
 *   @0x29b180 ldr r3, [r3, #0xc]
 *   @0x29b184 blx r3
 *   @0x29b188 mov r1, #0
 *   @0x29b18c mov r0, r8
 *   @0x29b190 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x29b194 ldr r3, [r6]
 *   @0x29b198 mov r2, r8
 *   @0x29b19c mov r1, #5
 *   @0x29b1a0 ldr r3, [r3, #0xc]
 *   @0x29b1a4 mov r10, r0
 *   @0x29b1a8 mov r0, r6
 *   @0x29b1ac blx r3
 *   @0x29b1b0 mov r1, #0
 *   @0x29b1b4 mov r0, r8
 *   @0x29b1b8 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29b1bc mov r11, r0
 *   @0x29b1c0 mov r0, r10
 *   @0x29b1c4 bl 0xc6720 <_Z10GetIBufferi>
 *   @0x29b1c8 vmov s13, r10
 *   @0x29b1cc ldr lr, [r4]
 *   @0x29b1d0 mov r2, #0
 *   @0x29b1d4 vcvt.f64.u32 d7, s13
 *   @0x29b1d8 str r2, [r4, #0x38]
 *   @0x29b1dc mov r1, #5
 *   @0x29b1e0 mov r2, r7
 *   @0x29b1e4 vstr s14, [r4, #44]
 *   @0x29b1e8 vstr s15, [r4, #48]
 *   @0x29b1ec ldr r3, [lr, #0x8]
 *   @0x29b1f0 mov r5, r0
 *   @0x29b1f4 mov r0, r4
 *   @0x29b1f8 blx r3
 *   @0x29b1fc cmp r5, #0
 *   @0x29b200 cmpne r5, r6
 *   @0x29b204 movne r10, #0
 *   @0x29b208 moveq r10, #1
 *   @0x29b20c beq 0x29b130 <_Z16Debug_GetBuffersP15Buffer_StandardS0_+0x98>
 *   @0x29b210 ldr r3, [r5, #0x10]
 *   @0x29b214 mov r1, #5
 *   @0x29b218 ldr lr, [r4]
 *   @0x29b21c mov r2, r7
 *   @0x29b220 str r10, [r4, #0x38]
 *   @0x29b224 mov r0, r4
 *   @0x29b228 vmov s13, r3
 *   @0x29b22c lsl r11, r11, #10
 *   @0x29b230 vcvt.f64.u32 d7, s13
 *   @0x29b234 vstr s14, [r4, #44]
 *   @0x29b238 vstr s15, [r4, #48]
 *   @0x29b23c ldr r12, [lr, #0x8]
 *   @0x29b240 str r3, [sp, #0x8]
 *   @0x29b244 blx r12
 *   @0x29b248 vldr s14, [r5, #24]
 *   @0x29b24c vcvt.f64.u32 d7, s14
 *   @0x29b250 ldr lr, [r4]
 *   @0x29b254 mov r1, #5
 *   @0x29b258 mov r2, r7
 *   @0x29b25c mov r0, r4
 *   @0x29b260 str r10, [r4, #0x38]
 *   @0x29b264 vstr s14, [r4, #44]
 *   @0x29b268 vstr s15, [r4, #48]
 *   @0x29b26c ldr r12, [lr, #0x8]
 *   @0x29b270 blx r12
 *   @0x29b274 vldr s14, [r5, #20]
 *   @0x29b278 vcvt.f64.u32 d7, s14
 *   @0x29b27c ldr lr, [r4]
 *   @0x29b280 mov r1, #5
 *   @0x29b284 mov r2, r7
 *   @0x29b288 mov r0, r4
 *   @0x29b28c str r10, [r4, #0x38]
 *   @0x29b290 vstr s14, [r4, #44]
 *   @0x29b294 vstr s15, [r4, #48]
 *   @0x29b298 ldr r12, [lr, #0x8]
 *   @0x29b29c blx r12
 *   @0x29b2a0 vldr s14, [r5, #28]
 *   @0x29b2a4 vcvt.f64.u32 d7, s14
 *   @0x29b2a8 ldr lr, [r4]
 *   @0x29b2ac mov r0, r4
 *   @0x29b2b0 str r10, [r4, #0x38]
 *   @0x29b2b4 mov r1, #5
 *   @0x29b2b8 mov r2, r7
 *   @0x29b2bc vstr s14, [r4, #44]
 *   @0x29b2c0 vstr s15, [r4, #48]
 *   @0x29b2c4 ldr r12, [lr, #0x8]
 *   @0x29b2c8 blx r12
 *   @0x29b2cc ldr r3, [sp, #0x8]
 *   @0x29b2d0 cmp r11, r3
 *   @0x29b2d4 blt 0x29b2f4 <_Z16Debug_GetBuffersP15Buffer_StandardS0_+0x25c>
 *   @0x29b2d8 sub r11, r3, #1
 *   @0x29b2dc add r2, r11, #1020
 *   @0x29b2e0 cmp r11, #0
 *   @0x29b2e4 add r2, r2, #3
 *   @0x29b2e8 movlt r11, r2
 *   @0x29b2ec asr r11, r11, #10
 *   @0x29b2f0 lsl r11, r11, #10
 *   @0x29b2f4 vmov s13, r11
 *   @0x29b2f8 ldr lr, [r4]
 *   @0x29b2fc rsb r3, r11, r3
 *   @0x29b300 mov r2, #0
 *   @0x29b304 vcvt.f64.u32 d7, s13
 *   @0x29b308 cmp r3, #1024
 *   @0x29b30c movge r3, #1024
 *   @0x29b310 bic r10, r3, r3, asr #31
 *   @0x29b314 str r2, [r4, #0x38]
 *   @0x29b318 mov r1, #5
 *   @0x29b31c mov r2, r7
 *   @0x29b320 mov r0, r4
 *   @0x29b324 add r9, r9, #1
 *   @0x29b328 vstr s14, [r4, #44]
 *   @0x29b32c vstr s15, [r4, #48]
 *   @0x29b330 ldr r3, [lr, #0x8]
 *   @0x29b334 blx r3
 *   @0x29b338 vmov s13, r10
 *   @0x29b33c ldr lr, [r4]
 *   @0x29b340 mov r2, #0
 *   @0x29b344 vcvt.f64.s32 d7, s13
 *   @0x29b348 str r2, [r4, #0x38]
 *   @0x29b34c mov r1, #5
 *   @0x29b350 mov r2, r7
 *   @0x29b354 mov r0, r4
 *   @0x29b358 vstr s14, [r4, #44]
 *   @0x29b35c vstr s15, [r4, #48]
 *   @0x29b360 ldr r3, [lr, #0x8]
 *   @0x29b364 blx r3
 *   @0x29b368 ldr lr, [r5]
 *   @0x29b36c ldr r12, [r4, #0x1c]
 *   @0x29b370 mov r0, r5
 *   @0x29b374 mov r1, r11
 *   @0x29b378 mov r2, r10
 *   @0x29b37c mov r3, r4
 *   @0x29b380 str r12, [sp]
 *   @0x29b384 ldr r5, [lr, #0x38]
 *   @0x29b388 str r12, [sp, #0x8]
 *   @0x29b38c blx r5
 *   @0x29b390 ldr r3, [r4]
 *   @0x29b394 ldr r12, [sp, #0x8]
 *   @0x29b398 mov r0, r4
 *   @0x29b39c mov r1, #0
 *   @0x29b3a0 add r2, r10, r12
 *   @0x29b3a4 ldr r3, [r3, #0x10]
 *   @0x29b3a8 blx r3
 *   @0x29b3ac ldr r12, [sp, #0xc]
 *   @0x29b3b0 cmp r9, r12
 *   @0x29b3b4 bne 0x29b170 <_Z16Debug_GetBuffersP15Buffer_StandardS0_+0xd8>
 *   @0x29b3b8 add sp, sp, #28
 *   @0x29b3bc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §3/39 FT_Load_Glyph  0x2e7564  size 808  202 条（0x2e7564..0x2e788c）
 * @func 0x2e7564 0x2e788c  size 808  202 条
 * 部分覆盖: 本节 202/369 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65b0 / FT_Outline_Check / 0xb5771c / FT_MulDiv / FT_Lookup_Renderer / FT_Vector_Transform
 * 字段偏移 top8: 0x38×3 / 0x1c×3 / 0x34×3 / 0xc×3 / 0x58×2 / 0x8×2 / 0x20×2 / 0x2c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e7564 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2e7568 mov r10, r1
 *   @0x2e756c mov r5, r2
 *   @0x2e7570 cmp r0, #0x0
 *   @0x2e7574 ldr r3, [r0, #0x58]
 *   @0x2e7578 beq 0x2e7672 <FT_Load_Glyph+0x10e>
 *   @0x2e757c cmp r4, #0x0
 *   @0x2e7580 mov r0, r4
 *   @0x2e7584 .word 0xf7ff086c
 *   @0x2e7588 smlabths r0, r12, pc, pc
 *   @0x2e758c movs r2, #0x20
 *   @0x2e7590 .word 0xf5cf0018
 *   @0x2e7594 andshs lr, r4, #917504
 *   @0x2e7598 mov r0, r8
 *   @0x2e759c blx 0xb65b0 <memset@plt>
 *   @0x2e75a0 movs r7, #0x0
 *   @0x2e75a4 lsls r2, r5, #0x15
 *   @0x2e75a8 it mi
 *   @0x2e75ac strbvs r6, [r7, #-0x500]!
 *   @0x2e75b0 it mi
 *   @0x2e75b4 .word 0xf8840501
 *   @0x2e75b8 uqsaxvs r7, r7, lr
 *   @0x2e75bc str r7, [r4, #0x68]
 *   @0x2e75c0 .word 0xf8c47080
 *   @0x2e75c4 .word 0xf8c47084
 *   @0x2e75c8 .word 0xf8c47088
 *   @0x2e75cc .word 0xf8c4708c
 *   @0x2e75d0 strtvs r7, [r7], #152
 *   @0x2e75d4 str r7, [r4, #0x38]
 *   @0x2e75d8 str.w r7, [r4, #0x90]
 *   @0x2e75dc str.w r7, [r4, #0x94]
 *   @0x2e75e0 ldr r7, [r6, #0x60]
 *   @0x2e75e4 ldr.w r9, [r3, #0xa0]
 *   @0x2e75e8 lsls r3, r5, #0x1f
 *   @0x2e75ec bicmi r5, r5, #0x4
 *   @0x2e75f0 orrmi r5, r5, #0xa
 *   @0x2e75f4 lsls r0, r5, #0x9
 *   @0x2e75f8 bicmi r5, r5, #0x4
 *   @0x2e75fc cmp.w r9, #0x0
 *   @0x2e7600 beq 0x2e7676 <FT_Load_Glyph+0x112>
 *   @0x2e7604 eormi r0, r11, r2, lsl #6
 *   @0x2e7608 cmp r3, #0x0
 *   @0x2e760c ldr r2, [r7]
 *   @0x2e7610 and r3, r3, #0x300
 *   @0x2e7614 cmp.w r3, #0x100
 *   @0x2e7618 bne 0x2e7676 <FT_Load_Glyph+0x112>
 *   @0x2e761c lsls r1, r3, #0x12
 *   @0x2e7620 lsls r0, r5, #0x14
 *   @0x2e7624 ldr.w r1, [r6, #0x80]
 *   @0x2e7628 ldr r0, [r1, #0x8]
 *   @0x2e762c cbnz r0, 0x2e7632 <FT_Load_Glyph+0xce>
 *   @0x2e7630 b 0x2e7676 <FT_Load_Glyph+0x112>
 *   @0x2e7634 lsls r1, r5, #0x1a
 *   @0x2e7638 ldmdavs r2, {r0, r2, r4, r5, r6, r7, pc}
 *   @0x2e763c lsls r0, r2, #0x15
 *   @0x2e7640 .word 0xf3c580f1
 *   @0x2e7644 stmdbhs r1, {r0, r1, r8, lr}
 *   @0x2e7648 bne 0x2e7650 <FT_Load_Glyph+0xec>
 *   @0x2e764c bpl.w 0x2e7824 <FT_Load_Glyph+0x2c0>
 *   @0x2e7650 lsls r2, r3, #0x1c
 *   @0x2e7654 ldr.w r2, [r6, #0x2d4]
 *   @0x2e7658 cbz r2, 0x2e7676 <FT_Load_Glyph+0x112>
 *   @0x2e765c ldmdblt r2, {r1, r2, r3, r4, r8, sp} ^
 *   @0x2e7660 ldr.w r2, [r6, #0x284]
 *   @0x2e7664 cbnz r2, 0x2e7676 <FT_Load_Glyph+0x112>
 *   @0x2e7668 bhs 0x2f00a0 <FT_Done_Memory+0x642c>
 *   @0x2e766c beq.w 0x2e7824 <FT_Load_Glyph+0x2c0>
 *   @0x2e7670 b 0x2e7676 <FT_Load_Glyph+0x112>
 *   @0x2e7674 b 0x2e7878 <FT_Load_Glyph+0x314>
 *   @0x2e7678 mov r0, r4
 *   @0x2e767c mov r2, r10
 *   @0x2e7680 mov r3, r5
 *   @0x2e7684 cmp r0, #0x0
 *   @0x2e7688 stcvs p0, c8, [r3], #988
 *   @0x2e768c ldr r2, [pc, #0x1f0]
 *   @0x2e7690 beq 0x2e7696 <FT_Load_Glyph+0x132>
 *   @0x2e7694 b 0x2e773e <FT_Load_Glyph+0x1da>
 *   @0x2e7698 bl 0x2e631e <FT_Outline_Check>
 *   @0x2e769c mov r7, r0
 *   @0x2e76a0 bne.w 0x2e7820 <FT_Load_Glyph+0x2bc>
 *   @0x2e76a4 lsls r0, r5, #0x1e
 *   @0x2e76a8 tst.w r5, #0x10
 *   @0x2e76ac ldr r2, [r4, #0x20]
 *   @0x2e76b0 ldr r0, [r4, #0x2c]
 *   @0x2e76b4 blvs 0xb5771c <b2_toiTime+0x3fe278>
 *   @0x2e76b8 beq 0x2e76f4 <FT_Load_Glyph+0x190>
 *   @0x2e76bc add r12, r0
 *   @0x2e76c0 rsbvs r0, r3, #-67108864
 *   @0x2e76c4 ldr r3, [r4, #0x1c]
 *   @0x2e76c8 .word 0xf0200c3f
 *   @0x2e76cc .word 0xf02c003f
 *   @0x2e76d0 strmi r0, [r11], #-3135
 *   @0x2e76d4 bic r1, r1, #0x3f
 *   @0x2e76d8 adds r3, #0x3f
 *   @0x2e76dc .word 0xf023023f
 *   @0x2e76e0 rscvs r0, r0, #-67108864
 *   @0x2e76e4 str r1, [r4, #0x30]
 *   @0x2e76e8 bne 0x1927720 <b2_toiTime+0x11ce27c>
 *   @0x2e76ec str r2, [r4, #0x20]
 *   @0x2e76f0 str r1, [r4, #0x1c]
 *   @0x2e76f4 bic r1, r1, #0x3f
 *   @0x2e76f8 str r1, [r4, #0x30]
 *   @0x2e76fc add r12, r2
 *   @0x2e7700 .word 0xf0220c3f
 *   @0x2e7704 bne 0x1928008 <b2_toiTime+0x11ceb64>
 *   @0x2e7708 adds r3, #0x3f
 *   @0x2e770c .word 0xf02c033f
 *   @0x2e7710 .word 0xf0210c3f
 *   @0x2e7714 .word 0xf020013f
 *   @0x2e7718 eorvs r0, r2, #63
 *   @0x2e771c rsb r2, r2, r12
 *   @0x2e7720 str r3, [r4, #0x24]
 *   @0x2e7724 str r0, [r4, #0x2c]
 *   @0x2e7728 str r3, [r4, #0x1c]
 *   @0x2e772c adds r3, #0x20
 *   @0x2e7730 adcvs r0, r3, #-67108864
 *   @0x2e7734 ldr r3, [r4, #0x34]
 *   @0x2e7738 bic r3, r3, #0x3f
 *   @0x2e773c str r3, [r4, #0x34]
 *   @0x2e7740 andle r0, r4, r0, lsl r2
 *   @0x2e7744 movs r3, #0x0
 *   @0x2e7748 ldr r3, [r4, #0x34]
 *   @0x2e774c b 0x2e7754 <FT_Load_Glyph+0x1f0>
 *   @0x2e7750 str r2, [r4, #0x44]
 *   @0x2e7754 lsls r1, r5, #0x12
 *   @0x2e7758 ldr r3, [r6, #0x8]
 *   @0x2e775c bpl 0x2e777e <FT_Load_Glyph+0x21a>
 *   @0x2e7760 subhs r9, r0, #88
 *   @0x2e7764 ldr r0, [r4, #0x38]
 *   @0x2e7768 .word 0xf7fd1010
 *   @0x2e776c subhs pc, r0, #946176
 *   @0x2e7770 str r0, [r4, #0x38]
 *   @0x2e7774 ldr.w r1, [r9, #0x14]
 *   @0x2e7778 bl 0x2e4d3c <FT_MulDiv>
 *   @0x2e777c str r0, [r4, #0x3c]
 *   @0x2e7780 bmi 0x2e77f0 <FT_Load_Glyph+0x28c>
 *   @0x2e7784 ldmibvs r3!, {r7, sp, lr}
 *   @0x2e7788 cmp r3, #0x0
 *   @0x2e778c ldr r3, [r4, #0x4]
 *   @0x2e7790 ldr r0, [r3, #0x4]
 *   @0x2e7794 .word 0xb11b309c
 *   @0x2e7798 ldr r1, [r3, #0x10]
 *   @0x2e779c cmp r1, r2
 *   @0x2e77a0 ldr r1, [r4, #0x48]
 *   @0x2e77a4 bl 0x2e5e36 <FT_Lookup_Renderer>
 *   @0x2e77a8 mov r3, r0
 *   @0x2e77ac ldr r2, [r3, #0xc]
 *   @0x2e77b0 mov r1, r4
 *   @0x2e77b4 bvs 0xff8a83fc <b2_toiTime+0xffffffffff14ef58>
 *   @0x2e77b8 mov r2, r6
 *   @0x2e77bc mov r7, r0
 *   @0x2e77c0 ldr r3, [r4, #0x48]
 *   @0x2e77c4 cmp r3, r2
 *   @0x2e77c8 ldr r3, [r6, #0x18]
 *   @0x2e77cc bpl 0x2e77d6 <FT_Load_Glyph+0x272>
 *   @0x2e77d0 mov r1, r6
 *   @0x2e77d4 ldmibvs r3!, {r0, r2, r4, r6, r7, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2e77d8 lsls r1, r3, #0x1e
 *   @0x2e77dc mov r0, r8
 *   @0x2e77e0 ldr r2, [r6, #0x14]
 *   @0x2e77e4 .word 0xf104fe1f
 *   @0x2e77e8 ldrtmi r0, [r1], -r0, asr #32
 *   @0x2e77ec bl 0x2e6548 <FT_Vector_Transform>
 *   @0x2e77f0 cbnz r7, 0x2e7820 <FT_Load_Glyph+0x2bc>
 *   @0x2e77f4 ldr r2, [pc, #0x8c]
 *   @0x2e77f8 beq 0x2e7820 <FT_Load_Glyph+0x2bc>
 *   @0x2e77fc cmp r3, r2
 *   @0x2e7800 lsls r2, r5, #0x1d
 *   @0x2e7804 ubfx r1, r5, #0x10, #0x4
 *   @0x2e7808 cbnz r1, 0x2e7814 <FT_Load_Glyph+0x2b0>
 *   @0x2e780c svclt #0xc5f80
 *   @0x2e7810 moveq r1, #0x0
 *   @0x2e7814 mov r0, r4
 *   @0x2e7818 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2e781c b.w 0x2e5ed8 <FT_Render_Glyph>
 *   @0x2e7820 mov r0, r7
 *   @0x2e7824 lsls r3, r3, #0x1e
 *   @0x2e7828 lsls r3, r5, #0x1c
 *   @0x2e782c ldr.w r11, [r6, #0x80]
 *   @0x2e7830 mov r0, r9
 *   @0x2e7834 ldr.w r3, [r11, #0x18]
 *   @0x2e7838 str r3, [sp, #0xc]
 *   @0x2e783c str.w r3, [r11, #0x18]
 *   @0x2e7840 ldr.w r3, [r9]
 *   @0x2e7844 ldr r3, [r3, #0x14]
 *   @0x2e7848 ldr r2, [r6, #0x58]
 *   @0x2e784c mov r3, r10
 *   @0x2e7850 ldr r3, [sp, #0xc]
 *   @0x2e7854 .word 0x46073018
 *   @0x2e7858 b 0x2e773e <FT_Load_Glyph+0x1da>
 *   @0x2e785c mov r0, r4
 *   @0x2e7860 mov r2, r10
 *   @0x2e7864 orr r3, r5, #0x4000
 *   @0x2e7868 blx r7
 *   @0x2e786c bne 0x2e782c <FT_Load_Glyph+0x2c8>
 *   @0x2e7870 ldr r2, [pc, #0x10]
 *   @0x2e7874 bne 0x2e782c <FT_Load_Glyph+0x2c8>
 *   @0x2e7878 add sp, #0x14
 *   @0x2e787c svclt #0x8ff0
 *   @0x2e7880 strb r4, [r5, #0x11]
 *   @0x2e7884 strb r3, [r6, #0x11]
 *   @0x2e7888 ldr r0, [r6, #0x54]
 *
 * ══ §4/39 JS_Argument_Get(YYObjectBase*, RValue*, char const*)  0x24bfb8  size 800  200 条（0x24bfb8..0x24c2d8）
 * @func 0x24bfb8 0x24c2d8  size 800  200 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / YYObjectBase::InternalGetYYVar(int)×3 / PushContextStack(YYObjectBase*) / 0xb66c4 / JS_DefaultGetOwnProperty(YYObjectBase*, RValue*, char const*)
 * 字段偏移 top8: 0x4×11 / 0x8×8 / 0xc×5 / 0x1×2 / 0x2fc×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24bfb8 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x24bfbc mov r8, r0
 *   @0x24bfc0 mov r0, #0
 *   @0x24bfc4 mov r10, r2
 *   @0x24bfc8 mov r9, r1
 *   @0x24bfcc bl 0xd3968 <_Z16PushContextStackP12YYObjectBase>
 *   @0x24bfd0 ldr r3, [pc, #0x2fc]
 *   @0x24bfd4 mov r12, r10
 *   @0x24bfd8 ldr r3, [pc, r3]
 *   @0x24bfdc ldr r4, [r3]
 *   @0x24bfe0 ldrb r3, [r12], #1
 *   @0x24bfe4 cmp r3, #0
 *   @0x24bfe8 add lr, r4, r3
 *   @0x24bfec bne 0x24c0f4 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x13c>
 *   @0x24bff0 mov r0, r10
 *   @0x24bff4 bl 0xb66c4 <atol@plt>
 *   @0x24bff8 ldr r3, [r8, #0x4]
 *   @0x24bffc cmp r3, #0
 *   @0x24c000 mov r11, r0
 *   @0x24c004 mov r4, r0
 *   @0x24c008 asr r5, r0, #31
 *   @0x24c00c beq 0x24c1d0 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x218>
 *   @0x24c010 add r0, r3, #16
 *   @0x24c014 ldr r3, [r0]
 *   @0x24c018 mov r7, #0
 *   @0x24c01c ldr r6, [r3, #0x24]
 *   @0x24c020 cmp r4, r6
 *   @0x24c024 sbcs r3, r5, r7
 *   @0x24c028 bge 0x24c100 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x148>
 *   @0x24c02c ldr r3, [r8, #0x4]
 *   @0x24c030 cmp r3, #0
 *   @0x24c034 beq 0x24c234 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x27c>
 *   @0x24c038 add r0, r3, #16
 *   @0x24c03c ldr r0, [r0]
 *   @0x24c040 ldr r4, [r0, #0x4]
 *   @0x24c044 cmp r4, #0
 *   @0x24c048 beq 0x24c224 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x26c>
 *   @0x24c04c add r4, r4, r11, lsl #4
 *   @0x24c050 ldr r2, [r9, #0xc]
 *   @0x24c054 bic r3, r2, #-16777216
 *   @0x24c058 cmp r3, #1
 *   @0x24c05c beq 0x24c134 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x17c>
 *   @0x24c060 cmp r3, #2
 *   @0x24c064 bne 0x24c08c <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0xd4>
 *   @0x24c068 sub r3, r2, #1
 *   @0x24c06c bic r3, r3, #-16777216
 *   @0x24c070 bic r3, r3, #3
 *   @0x24c074 cmp r3, #0
 *   @0x24c078 beq 0x24c218 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x260>
 *   @0x24c07c mov r2, #0
 *   @0x24c080 mov r3, #5
 *   @0x24c084 str r2, [r9, #0x8]
 *   @0x24c088 str r3, [r9, #0xc]
 *   @0x24c08c ldr r3, [r4, #0xc]
 *   @0x24c090 mov r1, #0
 *   @0x24c094 ldr r2, [r4, #0x8]
 *   @0x24c098 str r1, [r9]
 *   @0x24c09c str r3, [r9, #0xc]
 *   @0x24c0a0 ldr r3, [r4, #0xc]
 *   @0x24c0a4 str r2, [r9, #0x8]
 *   @0x24c0a8 bic r3, r3, #-16777216
 *   @0x24c0ac cmp r3, #14
 *   @0x24c0b0 addls pc, pc, r3, lsl #2
 *   @0x24c0b4 b 0x24c110 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x158>
 *   @0x24c0b8 b 0x24c128 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x170>
 *   @0x24c0bc b 0x24c18c <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x1d4>
 *   @0x24c0c0 b 0x24c1a4 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x1ec>
 *   @0x24c0c4 b 0x24c118 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x160>
 *   @0x24c0c8 b 0x24c110 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x158>
 *   @0x24c0cc b 0x24c110 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x158>
 *   @0x24c0d0 b 0x24c168 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x1b0>
 *   @0x24c0d4 b 0x24c118 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x160>
 *   @0x24c0d8 b 0x24c110 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x158>
 *   @0x24c0dc b 0x24c110 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x158>
 *   @0x24c0e0 b 0x24c128 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x170>
 *   @0x24c0e4 b 0x24c110 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x158>
 *   @0x24c0e8 b 0x24c110 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x158>
 *   @0x24c0ec b 0x24c128 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x170>
 *   @0x24c0f0 b 0x24c118 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x160>
 *   @0x24c0f4 ldrb r3, [lr, #0x1]
 *   @0x24c0f8 tst r3, #4
 *   @0x24c0fc bne 0x24bfe0 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x28>
 *   @0x24c100 mov r0, r8
 *   @0x24c104 mov r1, r9
 *   @0x24c108 mov r2, r10
 *   @0x24c10c bl 0x23d0f0 <_Z24JS_DefaultGetOwnPropertyP12YYObjectBaseP6RValuePKc>
 *   @0x24c110 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x24c114 b 0xd3a34 <_Z15PopContextStackv>
 *   @0x24c118 ldr r3, [r4]
 *   @0x24c11c str r3, [r9]
 *   @0x24c120 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x24c124 b 0xd3a34 <_Z15PopContextStackv>
 *   @0x24c128 ldm r4, {r2, r3}
 *   @0x24c12c stm r9, {r2, r3}
 *   @0x24c130 b 0x24c110 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x158>
 *   @0x24c134 ldr r5, [r9]
 *   @0x24c138 cmp r5, #0
 *   @0x24c13c beq 0x24c15c <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x1a4>
 *   @0x24c140 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24c144 ldr r6, [r5, #0x4]
 *   @0x24c148 sub r6, r6, #1
 *   @0x24c14c str r6, [r5, #0x4]
 *   @0x24c150 cmp r6, #0
 *   @0x24c154 beq 0x24c1e0 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x228>
 *   @0x24c158 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x24c15c mov r3, #0
 *   @0x24c160 str r3, [r9]
 *   @0x24c164 b 0x24c08c <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0xd4>
 *   @0x24c168 ldr r3, [r4]
 *   @0x24c16c str r3, [r9]
 *   @0x24c170 ldr r3, [r4]
 *   @0x24c174 cmp r3, #0
 *   @0x24c178 beq 0x24c110 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x158>
 *   @0x24c17c bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x24c180 ldr r1, [r4]
 *   @0x24c184 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x24c188 b 0x24c110 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x158>
 *   @0x24c18c ldr r3, [r4]
 *   @0x24c190 cmp r3, #0
 *   @0x24c194 ldrne r2, [r3, #0x4]
 *   @0x24c198 addne r2, r2, #1
 *   @0x24c19c strne r2, [r3, #0x4]
 *   @0x24c1a0 b 0x24c11c <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x164>
 *   @0x24c1a4 ldr r3, [r4]
 *   @0x24c1a8 cmp r3, #0
 *   @0x24c1ac str r3, [r9]
 *   @0x24c1b0 beq 0x24c110 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x158>
 *   @0x24c1b4 ldr r1, [r3, #0x8]
 *   @0x24c1b8 ldr r2, [r3]
 *   @0x24c1bc cmp r1, #0
 *   @0x24c1c0 streq r9, [r3, #0x8]
 *   @0x24c1c4 add r2, r2, #1
 *   @0x24c1c8 str r2, [r3]
 *   @0x24c1cc b 0x24c110 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x158>
 *   @0x24c1d0 mov r0, r8
 *   @0x24c1d4 mov r1, #1
 *   @0x24c1d8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x24c1dc b 0x24c014 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x5c>
 *   @0x24c1e0 ldr r0, [r5]
 *   @0x24c1e4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24c1e8 str r6, [r5]
 *   @0x24c1ec str r6, [r5, #0x8]
 *   @0x24c1f0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24c1f4 ldr r6, [r5, #0x4]
 *   @0x24c1f8 sub r6, r6, #1
 *   @0x24c1fc str r6, [r5, #0x4]
 *   @0x24c200 cmp r6, #0
 *   @0x24c204 beq 0x24c244 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x28c>
 *   @0x24c208 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x24c20c mov r0, r5
 *   @0x24c210 bl 0x27d1d0 <_ZdlPv>
 *   @0x24c214 b 0x24c158 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x1a0>
 *   @0x24c218 mov r0, r9
 *   @0x24c21c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x24c220 b 0x24c07c <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0xc4>
 *   @0x24c224 mov r1, r11
 *   @0x24c228 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x24c22c mov r4, r0
 *   @0x24c230 b 0x24c050 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x98>
 *   @0x24c234 mov r0, r8
 *   @0x24c238 mov r1, #1
 *   @0x24c23c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x24c240 b 0x24c03c <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x84>
 *   @0x24c244 ldr r0, [r5]
 *   @0x24c248 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24c24c str r6, [r5]
 *   @0x24c250 str r6, [r5, #0x8]
 *   @0x24c254 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24c258 ldr r6, [r5, #0x4]
 *   @0x24c25c sub r6, r6, #1
 *   @0x24c260 str r6, [r5, #0x4]
 *   @0x24c264 cmp r6, #0
 *   @0x24c268 beq 0x24c27c <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x2c4>
 *   @0x24c26c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x24c270 mov r0, r5
 *   @0x24c274 bl 0x27d1d0 <_ZdlPv>
 *   @0x24c278 b 0x24c208 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x250>
 *   @0x24c27c ldr r0, [r5]
 *   @0x24c280 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24c284 str r6, [r5]
 *   @0x24c288 str r6, [r5, #0x8]
 *   @0x24c28c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24c290 ldr r6, [r5, #0x4]
 *   @0x24c294 sub r6, r6, #1
 *   @0x24c298 str r6, [r5, #0x4]
 *   @0x24c29c cmp r6, #0
 *   @0x24c2a0 bne 0x24c2c4 <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x30c>
 *   @0x24c2a4 ldr r0, [r5]
 *   @0x24c2a8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24c2ac mov r0, r5
 *   @0x24c2b0 str r6, [r5]
 *   @0x24c2b4 str r6, [r5, #0x8]
 *   @0x24c2b8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x24c2bc mov r0, r5
 *   @0x24c2c0 bl 0x27d1d0 <_ZdlPv>
 *   @0x24c2c4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x24c2c8 mov r0, r5
 *   @0x24c2cc bl 0x27d1d0 <_ZdlPv>
 *   @0x24c2d0 b 0x24c26c <_Z15JS_Argument_GetP12YYObjectBaseP6RValuePKc+0x2b4>
 *   @0x24c2d4 andseq r1, r10, r8, lsr #19
 *
 * ══ §5/39 pcre_maketables  0x25f6dc  size 800  200 条（0x25f6dc..0x25f9fc）
 * @func 0x25f6dc 0x25f9fc  size 800  200 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x25f6e8→0x3f76e0
 * 调用序列: 0xb65b0 / pcre_maketables+0x2ec / 0xb6634
 * 字段偏移 top8: 0x1×3 / 0x2f8×2 / 0x3×2 / 0x2e0×1 / 0x2b8×1 / 0x29c×1 / 0x-1×1 / 0xac×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x25f6dc push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x25f6e0 mov r0, #1088
 *   @0x25f6e4 ldr r6, [pc, #0x2f8]
 *   @0x25f6e8 ldr r3, [pc, #0x2f8]
 *   @0x25f6ec add r6, pc, r6
 *   @0x25f6f0 ldr r3, [r6, r3]
 *   @0x25f6f4 ldr r3, [r3]
 *   @0x25f6f8 blx r3
 *   @0x25f6fc subs r7, r0, #0
 *   @0x25f700 beq 0x25f9c0 <pcre_maketables+0x2e4>
 *   @0x25f704 ldr r1, [pc, #0x2e0]
 *   @0x25f708 mov r2, r7
 *   @0x25f70c mov r3, #2
 *   @0x25f710 movw r0, #0x202
 *   @0x25f714 ldr r12, [r6, r1]
 *   @0x25f718 ldr r1, [r12]
 *   @0x25f71c ldrh r1, [r1, r3]
 *   @0x25f720 add r3, r3, #2
 *   @0x25f724 cmp r3, r0
 *   @0x25f728 strb r1, [r2], #1
 *   @0x25f72c bne 0x25f718 <pcre_maketables+0x3c>
 *   @0x25f730 ldr r1, [pc, #0x2b8]
 *   @0x25f734 add r3, r7, #256
 *   @0x25f738 add r4, r7, #512
 *   @0x25f73c mov r2, #2
 *   @0x25f740 ldr r5, [r6, r1]
 *   @0x25f744 add r3, r3, #1
 *   @0x25f748 ldr r0, [r5]
 *   @0x25f74c sub r1, r3, #256
 *   @0x25f750 ldr lr, [pc, #0x29c]
 *   @0x25f754 rsb r1, r7, r1
 *   @0x25f758 ldrb r1, [r0, r1]
 *   @0x25f75c tst r1, #2
 *   @0x25f760 ldrne r1, [r6, lr]
 *   @0x25f764 ldreq r1, [r12]
 *   @0x25f768 ldrne r1, [r1]
 *   @0x25f76c cmp r3, r4
 *   @0x25f770 ldrb r1, [r1, r2]
 *   @0x25f774 add r2, r2, #2
 *   @0x25f778 strb r1, [r3, #-0x1]
 *   @0x25f77c bne 0x25f744 <pcre_maketables+0x68>
 *   @0x25f780 mov r2, #320
 *   @0x25f784 mov r0, r4
 *   @0x25f788 mov r1, #0
 *   @0x25f78c bl 0xb65b0 <memset@plt>
 *   @0x25f790 mov r3, #0
 *   @0x25f794 mov r2, r3
 *   @0x25f798 mov r0, #1
 *   @0x25f79c b 0x25f7b0 <pcre_maketables+0xd4>
 *   @0x25f7a0 sub r1, r3, #48
 *   @0x25f7a4 mov r2, r3
 *   @0x25f7a8 cmp r1, #9
 *   @0x25f7ac bls 0x25f9c8 <pcre_maketables+0x2ec>
 *   @0x25f7b0 ldr r12, [r5]
 *   @0x25f7b4 add r2, r2, #1
 *   @0x25f7b8 add r1, r12, r2
 *   @0x25f7bc ldrb r12, [r12, r2]
 *   @0x25f7c0 tst r12, #1
 *   @0x25f7c4 beq 0x25f7ec <pcre_maketables+0x110>
 *   @0x25f7c8 asr r1, r3, #3
 *   @0x25f7cc and r12, r3, #7
 *   @0x25f7d0 add r1, r1, #96
 *   @0x25f7d4 ldrb lr, [r4, r1]
 *   @0x25f7d8 orr r12, lr, r0, lsl r12
 *   @0x25f7dc strb r12, [r4, r1]
 *   @0x25f7e0 ldr r12, [r5]
 *   @0x25f7e4 add r1, r12, r2
 *   @0x25f7e8 ldrb r12, [r12, r2]
 *   @0x25f7ec tst r12, #2
 *   @0x25f7f0 beq 0x25f818 <pcre_maketables+0x13c>
 *   @0x25f7f4 asr r1, r3, #3
 *   @0x25f7f8 and r12, r3, #7
 *   @0x25f7fc add r1, r1, #128
 *   @0x25f800 ldrb lr, [r4, r1]
 *   @0x25f804 orr r12, lr, r0, lsl r12
 *   @0x25f808 strb r12, [r4, r1]
 *   @0x25f80c ldr r12, [r5]
 *   @0x25f810 add r1, r12, r2
 *   @0x25f814 ldrb r12, [r12, r2]
 *   @0x25f818 tst r12, #7
 *   @0x25f81c beq 0x25f840 <pcre_maketables+0x164>
 *   @0x25f820 asr r1, r3, #3
 *   @0x25f824 and r12, r3, #7
 *   @0x25f828 add r1, r1, #160
 *   @0x25f82c ldrb lr, [r4, r1]
 *   @0x25f830 orr r12, lr, r0, lsl r12
 *   @0x25f834 strb r12, [r4, r1]
 *   @0x25f838 ldr r1, [r5]
 *   @0x25f83c add r1, r1, r2
 *   @0x25f840 cmp r3, #95
 *   @0x25f844 ldrbeq r12, [r4, #0xab]
 *   @0x25f848 mvneq r12, r12, lsl #25
 *   @0x25f84c mvneq r12, r12, lsr #25
 *   @0x25f850 strbeq r12, [r4, #0xab]
 *   @0x25f854 ldrb r1, [r1]
 *   @0x25f858 tst r1, #8
 *   @0x25f85c beq 0x25f878 <pcre_maketables+0x19c>
 *   @0x25f860 ldrb r1, [r4, r3, asr #3]
 *   @0x25f864 and r12, r3, #7
 *   @0x25f868 orr r1, r1, r0, lsl r12
 *   @0x25f86c strb r1, [r4, r3, asr #3]
 *   @0x25f870 ldr r1, [r5]
 *   @0x25f874 ldrb r1, [r1, r2]
 *   @0x25f878 tst r1, #68
 *   @0x25f87c beq 0x25f8a0 <pcre_maketables+0x1c4>
 *   @0x25f880 asr r1, r3, #3
 *   @0x25f884 and r12, r3, #7
 *   @0x25f888 add r1, r1, #32
 *   @0x25f88c ldrb lr, [r4, r1]
 *   @0x25f890 orr r12, lr, r0, lsl r12
 *   @0x25f894 strb r12, [r4, r1]
 *   @0x25f898 ldr r1, [r5]
 *   @0x25f89c ldrb r1, [r1, r2]
 *   @0x25f8a0 tst r1, #23
 *   @0x25f8a4 beq 0x25f8c8 <pcre_maketables+0x1ec>
 *   @0x25f8a8 asr r1, r3, #3
 *   @0x25f8ac and r12, r3, #7
 *   @0x25f8b0 add r1, r1, #192
 *   @0x25f8b4 ldrb lr, [r4, r1]
 *   @0x25f8b8 orr r12, lr, r0, lsl r12
 *   @0x25f8bc strb r12, [r4, r1]
 *   @0x25f8c0 ldr r1, [r5]
 *   @0x25f8c4 ldrb r1, [r1, r2]
 *   @0x25f8c8 tst r1, #151
 *   @0x25f8cc beq 0x25f8f0 <pcre_maketables+0x214>
 *   @0x25f8d0 asr r1, r3, #3
 *   @0x25f8d4 and r12, r3, #7
 *   @0x25f8d8 add r1, r1, #224
 *   @0x25f8dc ldrb lr, [r4, r1]
 *   @0x25f8e0 orr r12, lr, r0, lsl r12
 *   @0x25f8e4 strb r12, [r4, r1]
 *   @0x25f8e8 ldr r1, [r5]
 *   @0x25f8ec ldrb r1, [r1, r2]
 *   @0x25f8f0 tst r1, #16
 *   @0x25f8f4 beq 0x25f918 <pcre_maketables+0x23c>
 *   @0x25f8f8 asr r1, r3, #3
 *   @0x25f8fc and r12, r3, #7
 *   @0x25f900 add r1, r1, #256
 *   @0x25f904 ldrb lr, [r4, r1]
 *   @0x25f908 orr r12, lr, r0, lsl r12
 *   @0x25f90c strb r12, [r4, r1]
 *   @0x25f910 ldr r1, [r5]
 *   @0x25f914 ldrb r1, [r1, r2]
 *   @0x25f918 tst r1, #32
 *   @0x25f91c beq 0x25f938 <pcre_maketables+0x25c>
 *   @0x25f920 asr r2, r3, #3
 *   @0x25f924 and r1, r3, #7
 *   @0x25f928 add r2, r2, #288
 *   @0x25f92c ldrb r12, [r4, r2]
 *   @0x25f930 orr r1, r12, r0, lsl r1
 *   @0x25f934 strb r1, [r4, r2]
 *   @0x25f938 add r3, r3, #1
 *   @0x25f93c cmp r3, #256
 *   @0x25f940 bne 0x25f7a0 <pcre_maketables+0xc4>
 *   @0x25f944 ldr r9, [pc, #0xac]
 *   @0x25f948 add r8, r7, #832
 *   @0x25f94c mov r6, #0
 *   @0x25f950 add r9, pc, r9
 *   @0x25f954 b 0x25f984 <pcre_maketables+0x2a8>
 *   @0x25f958 cmp r6, #95
 *   @0x25f95c beq 0x25f9b8 <pcre_maketables+0x2dc>
 *   @0x25f960 mov r1, r6
 *   @0x25f964 mov r0, r9
 *   @0x25f968 bl 0xb6634 <strchr@plt>
 *   @0x25f96c add r6, r6, #1
 *   @0x25f970 cmp r0, #0
 *   @0x25f974 addne r4, r4, #128
 *   @0x25f978 cmp r6, #256
 *   @0x25f97c strb r4, [r8], #1
 *   @0x25f980 beq 0x25f9c0 <pcre_maketables+0x2e4>
 *   @0x25f984 ldr r3, [r5]
 *   @0x25f988 sub r2, r6, #48
 *   @0x25f98c add r3, r3, r6
 *   @0x25f990 ldrb r3, [r3, #0x1]
 *   @0x25f994 ubfx r4, r3, #0x3, #0x1
 *   @0x25f998 tst r3, #3
 *   @0x25f99c addne r4, r4, #2
 *   @0x25f9a0 cmp r2, #9
 *   @0x25f9a4 addls r4, r4, #4
 *   @0x25f9a8 tst r3, #68
 *   @0x25f9ac addne r4, r4, #8
 *   @0x25f9b0 tst r3, #7
 *   @0x25f9b4 beq 0x25f958 <pcre_maketables+0x27c>
 *   @0x25f9b8 add r4, r4, #16
 *   @0x25f9bc b 0x25f960 <pcre_maketables+0x284>
 *   @0x25f9c0 mov r0, r7
 *   @0x25f9c4 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x25f9c8 asr r1, r3, #3
 *   @0x25f9cc and lr, r3, #7
 *   @0x25f9d0 add r1, r1, #64
 *   @0x25f9d4 ldrb r12, [r4, r1]
 *   @0x25f9d8 orr r12, r12, r0, lsl lr
 *   @0x25f9dc strb r12, [r4, r1]
 *   @0x25f9e0 b 0x25f7b0 <pcre_maketables+0xd4>
 *   @0x25f9e4 andseq r2, r9, r4, ror #10
 *   @0x25f9e8 .word 0xfffffb94
 *   @0x25f9ec .word 0xffffbd34
 *   @0x25f9f0 .word 0xffffbd30
 *   @0x25f9f4 .word 0xffffbd38
 *   @0x25f9f8 andeq r7, pc, r4, lsl #12
 *
 * ══ §6/39 Code_Variable_Find_Set(char const*, int, int)  0xd2f20  size 796  199 条（0xd2f20..0xd323c）
 * @func 0xd2f20 0xd323c  size 796  199 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYStrDup(char const*)×3 / Code_Variable_Find_Set(char const*, int, int)+0x2c8 / unsigned int CHashMapCalculateHash<char const*>(char const*) / Code_Variable_Find_Set(char const*, int, int)+0xcc / Code_Variable_Find_Slot_From_Global_Name(char const*) / Code_Variable_Find_Set(char const*, int, int)+0x2e8 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65b0
 * 字段偏移 top8: 0x4×26 / 0x8×9 / 0x10×4 / 0xc×3 / 0x2×2 / 0x2cc×1 / 0x2b4×1 / 0x18c×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd2f20 cmn r1, #6
 *   @0xd2f24 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xd2f28 mov r9, r2
 *   @0xd2f2c sub sp, sp, #12
 *   @0xd2f30 mov r4, r0
 *   @0xd2f34 beq 0xd3080 <_Z22Code_Variable_Find_SetPKcii+0x160>
 *   @0xd2f38 cmn r1, #5
 *   @0xd2f3c beq 0xd309c <_Z22Code_Variable_Find_SetPKcii+0x17c>
 *   @0xd2f40 cmn r1, #1
 *   @0xd2f44 beq 0xd2f58 <_Z22Code_Variable_Find_SetPKcii+0x38>
 *   @0xd2f48 add r9, r9, #99328
 *   @0xd2f4c add r0, r9, #672
 *   @0xd2f50 add sp, sp, #12
 *   @0xd2f54 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xd2f58 ldr r5, [pc, #0x2cc]
 *   @0xd2f5c ldr r5, [pc, r5]
 *   @0xd2f60 ldr r3, [r5]
 *   @0xd2f64 cmp r2, r3
 *   @0xd2f68 blt 0xd31e8 <_Z22Code_Variable_Find_SetPKcii+0x2c8>
 *   @0xd2f6c mov r0, r4
 *   @0xd2f70 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xd2f74 ldr r3, [pc, #0x2b4]
 *   @0xd2f78 ldr r3, [pc, r3]
 *   @0xd2f7c ldr r3, [r3]
 *   @0xd2f80 str r3, [sp, #0x4]
 *   @0xd2f84 ldr r12, [sp, #0x4]
 *   @0xd2f88 ldr r3, [r3, #0x4]
 *   @0xd2f8c ldr r2, [r12, #0xc]
 *   @0xd2f90 cmp r3, r2
 *   @0xd2f94 mov r8, r0
 *   @0xd2f98 bgt 0xd30d8 <_Z22Code_Variable_Find_SetPKcii+0x1b8>
 *   @0xd2f9c ldr r12, [sp, #0x4]
 *   @0xd2fa0 add r3, r3, #1
 *   @0xd2fa4 mov r0, r8
 *   @0xd2fa8 str r3, [r12, #0x4]
 *   @0xd2fac bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_>
 *   @0xd2fb0 ldr r12, [sp, #0x4]
 *   @0xd2fb4 ldr r5, [r12, #0x8]
 *   @0xd2fb8 ldr r10, [r12, #0x10]
 *   @0xd2fbc bic r0, r0, #-2147483648
 *   @0xd2fc0 and r3, r0, r5
 *   @0xd2fc4 add r1, r3, r3, lsl #1
 *   @0xd2fc8 add r1, r10, r1, lsl #2
 *   @0xd2fcc ldr r12, [r1, #0x8]
 *   @0xd2fd0 cmp r12, #0
 *   @0xd2fd4 beq 0xd30c4 <_Z22Code_Variable_Find_SetPKcii+0x1a4>
 *   @0xd2fd8 ldr r2, [sp, #0x4]
 *   @0xd2fdc mov r6, #0
 *   @0xd2fe0 ldr r11, [r2]
 *   @0xd2fe4 mov r2, r9
 *   @0xd2fe8 b 0xd302c <_Z22Code_Variable_Find_SetPKcii+0x10c>
 *   @0xd2fec ldr r7, [r1]
 *   @0xd2ff0 ldr r6, [r1, #0x4]
 *   @0xd2ff4 str r0, [r1, #0x8]
 *   @0xd2ff8 mov r0, r12
 *   @0xd2ffc str r8, [r1]
 *   @0xd3000 mov r8, r7
 *   @0xd3004 str r2, [r1, #0x4]
 *   @0xd3008 mov r2, r6
 *   @0xd300c add r3, r3, #1
 *   @0xd3010 add r6, r4, #1
 *   @0xd3014 and r3, r3, r5
 *   @0xd3018 add r1, r3, r3, lsl #1
 *   @0xd301c add r1, r10, r1, lsl #2
 *   @0xd3020 ldr r12, [r1, #0x8]
 *   @0xd3024 cmp r12, #0
 *   @0xd3028 beq 0xd30c8 <_Z22Code_Variable_Find_SetPKcii+0x1a8>
 *   @0xd302c add r4, r11, r3
 *   @0xd3030 and r7, r12, r5
 *   @0xd3034 rsb r4, r7, r4
 *   @0xd3038 and r4, r4, r5
 *   @0xd303c cmp r4, r6
 *   @0xd3040 blt 0xd2fec <_Z22Code_Variable_Find_SetPKcii+0xcc>
 *   @0xd3044 movne r4, r6
 *   @0xd3048 bne 0xd300c <_Z22Code_Variable_Find_SetPKcii+0xec>
 *   @0xd304c cmp r12, r0
 *   @0xd3050 bne 0xd300c <_Z22Code_Variable_Find_SetPKcii+0xec>
 *   @0xd3054 ldr r6, [r1]
 *   @0xd3058 cmp r8, r6
 *   @0xd305c bne 0xd300c <_Z22Code_Variable_Find_SetPKcii+0xec>
 *   @0xd3060 ldr r0, [sp, #0x4]
 *   @0xd3064 ldr r3, [r0, #0x4]
 *   @0xd3068 str r8, [r1]
 *   @0xd306c str r2, [r1, #0x4]
 *   @0xd3070 sub r3, r3, #1
 *   @0xd3074 str r12, [r1, #0x8]
 *   @0xd3078 str r3, [r0, #0x4]
 *   @0xd307c b 0xd2f48 <_Z22Code_Variable_Find_SetPKcii+0x28>
 *   @0xd3080 bl 0xd2054 <_Z40Code_Variable_Find_Slot_From_Global_NamePKc>
 *   @0xd3084 cmp r0, #0
 *   @0xd3088 blt 0xd3208 <_Z22Code_Variable_Find_SetPKcii+0x2e8>
 *   @0xd308c add r0, r0, #99328
 *   @0xd3090 add r0, r0, #672
 *   @0xd3094 add sp, sp, #12
 *   @0xd3098 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xd309c bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xd30a0 ldr r3, [pc, #0x18c]
 *   @0xd30a4 ldr r3, [pc, r3]
 *   @0xd30a8 ldr r2, [r3, #0x4]
 *   @0xd30ac ldr r1, [r3, #0xc]
 *   @0xd30b0 cmp r9, r2
 *   @0xd30b4 addge r2, r9, #1
 *   @0xd30b8 str r0, [r1, r9, lsl #2]
 *   @0xd30bc str r2, [r3, #0x4]
 *   @0xd30c0 b 0xd2f48 <_Z22Code_Variable_Find_SetPKcii+0x28>
 *   @0xd30c4 mov r2, r9
 *   @0xd30c8 str r8, [r1]
 *   @0xd30cc str r2, [r1, #0x4]
 *   @0xd30d0 str r0, [r1, #0x8]
 *   @0xd30d4 b 0xd2f48 <_Z22Code_Variable_Find_SetPKcii+0x28>
 *   @0xd30d8 ldr r7, [r12]
 *   @0xd30dc mov r3, #1
 *   @0xd30e0 ldr r1, [pc, #0x150]
 *   @0xd30e4 mov r2, #70
 *   @0xd30e8 ldr r6, [r12, #0x10]
 *   @0xd30ec lsl r0, r7, r3
 *   @0xd30f0 add r1, pc, r1
 *   @0xd30f4 add r4, r0, r7, lsl #2
 *   @0xd30f8 str r0, [r12]
 *   @0xd30fc sub r0, r0, #1
 *   @0xd3100 str r0, [r12, #0x8]
 *   @0xd3104 lsl r4, r4, #2
 *   @0xd3108 mov r0, r4
 *   @0xd310c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xd3110 ldr r12, [sp, #0x4]
 *   @0xd3114 mov r2, r4
 *   @0xd3118 mov r1, #0
 *   @0xd311c str r0, [r12, #0x10]
 *   @0xd3120 bl 0xb65b0 <memset@plt>
 *   @0xd3124 ldr r12, [sp, #0x4]
 *   @0xd3128 vldr s15, [pc, #248]
 *   @0xd312c mov r1, #0
 *   @0xd3130 ldr r2, [r12]
 *   @0xd3134 str r1, [r12, #0x4]
 *   @0xd3138 cmp r2, r1
 *   @0xd313c vmov s13, r2
 *   @0xd3140 vcvt.f32.s32 s14, s13
 *   @0xd3144 vmul.f32 s15, s14, s15
 *   @0xd3148 vcvt.s32.f32 s15, s15
 *   @0xd314c vstr s15, [r12, #12]
 *   @0xd3150 ble 0xd3174 <_Z22Code_Variable_Find_SetPKcii+0x254>
 *   @0xd3154 ldr r12, [sp, #0x4]
 *   @0xd3158 add r2, r2, r2, lsl #1
 *   @0xd315c ldr r3, [r12, #0x10]
 *   @0xd3160 add r2, r3, r2, lsl #2
 *   @0xd3164 str r1, [r3, #0x8]
 *   @0xd3168 add r3, r3, #12
 *   @0xd316c cmp r3, r2
 *   @0xd3170 bne 0xd3164 <_Z22Code_Variable_Find_SetPKcii+0x244>
 *   @0xd3174 cmp r7, #0
 *   @0xd3178 ble 0xd31b0 <_Z22Code_Variable_Find_SetPKcii+0x290>
 *   @0xd317c ldr r10, [sp, #0x4]
 *   @0xd3180 mov r4, r6
 *   @0xd3184 mov r5, #0
 *   @0xd3188 ldr r3, [r4, #0x8]
 *   @0xd318c mov r0, r10
 *   @0xd3190 add r5, r5, #1
 *   @0xd3194 cmp r3, #0
 *   @0xd3198 ble 0xd31a4 <_Z22Code_Variable_Find_SetPKcii+0x284>
 *   @0xd319c ldm r4, {r1, r2}
 *   @0xd31a0 bl 0xd261c <_ZN8CHashMapIPKciLi7EE6InsertES1_i>
 *   @0xd31a4 cmp r5, r7
 *   @0xd31a8 add r4, r4, #12
 *   @0xd31ac bne 0xd3188 <_Z22Code_Variable_Find_SetPKcii+0x268>
 *   @0xd31b0 mov r0, r6
 *   @0xd31b4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xd31b8 ldr r12, [sp, #0x4]
 *   @0xd31bc vldr s15, [pc, #100]
 *   @0xd31c0 ldr r12, [r12]
 *   @0xd31c4 str r12, [sp]
 *   @0xd31c8 vldr s13, [sp]
 *   @0xd31cc vcvt.f32.s32 s14, s13
 *   @0xd31d0 ldr r12, [sp, #0x4]
 *   @0xd31d4 ldr r3, [r12, #0x4]
 *   @0xd31d8 vmul.f32 s15, s14, s15
 *   @0xd31dc vcvt.s32.f32 s15, s15
 *   @0xd31e0 vstr s15, [r12, #12]
 *   @0xd31e4 b 0xd2f9c <_Z22Code_Variable_Find_SetPKcii+0x7c>
 *   @0xd31e8 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xd31ec ldr r3, [r5, #0x4]
 *   @0xd31f0 ldr r2, [r5, #0xc]
 *   @0xd31f4 cmp r9, r3
 *   @0xd31f8 addge r3, r9, #1
 *   @0xd31fc str r0, [r2, r9, lsl #2]
 *   @0xd3200 str r3, [r5, #0x4]
 *   @0xd3204 b 0xd2f6c <_Z22Code_Variable_Find_SetPKcii+0x4c>
 *   @0xd3208 mov r0, r4
 *   @0xd320c bl 0xd1f74 <_Z39Code_Variable_Find_Slot_From_Local_NamePKc>
 *   @0xd3210 cmp r0, #0
 *   @0xd3214 bge 0xd308c <_Z22Code_Variable_Find_SetPKcii+0x16c>
 *   @0xd3218 mov r0, r4
 *   @0xd321c add sp, sp, #12
 *   @0xd3220 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xd3224 b 0x1f3a5c <_Z21Variable_BuiltIn_FindPKc>
 *   @0xd3228 svclo #0x19999a
 *   @0xd322c eorseq r10, r1, r4, asr #24
 *   @0xd3230 eorseq r10, r1, r12, lsr #24
 *   @0xd3234 ldrshteq r10, [r1], -r8
 *   @0xd3238 eoreq sp, r5, r0, asr #30
 *
 * ══ §7/39 Debug_SendGameStructure(DbgSocket*, Buffer_Standard*)  0x29fb30  size 796  199 条（0x29fb30..0x29fe4c）
 * @func 0x29fb30 0x29fe4c  size 796  199 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YoYo_GetPlatform_DoWork() / AddVMCodeBuffers(Buffer_Standard*) / TraverseObjects(Buffer_Standard*) / AddScripts(Buffer_Standard*) / AddFunctionNames(Buffer_Standard*) / AddCreationCode(Buffer_Standard*) / AddTimelineCode(Buffer_Standard*)
 * 字段偏移 top8: 0x30×15 / 0x8×13 / 0x38×13 / 0x2c×11 / 0x10×2 / 0xc×2 / 0x1c×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29fb30 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x29fb34 mov r6, r1
 *   @0x29fb38 add r8, r1, #44
 *   @0x29fb3c ldr r1, [r1]
 *   @0x29fb40 mov r7, #0
 *   @0x29fb44 mov r10, r0
 *   @0x29fb48 mov r2, #465567744
 *   @0x29fb4c mov r0, r6
 *   @0x29fb50 str r2, [r6, #0x2c]
 *   @0x29fb54 movw r3, #0xc238
 *   @0x29fb58 mov r2, r8
 *   @0x29fb5c movt r3, #0x41e7
 *   @0x29fb60 str r3, [r6, #0x30]
 *   @0x29fb64 mov r9, r7
 *   @0x29fb68 ldr r3, [r1, #0x8]
 *   @0x29fb6c mov r1, #5
 *   @0x29fb70 str r7, [r6, #0x38]
 *   @0x29fb74 movt r9, #0x97c0
 *   @0x29fb78 blx r3
 *   @0x29fb7c ldr r3, [r6]
 *   @0x29fb80 str r7, [r6, #0x2c]
 *   @0x29fb84 mov r2, r8
 *   @0x29fb88 str r7, [r6, #0x30]
 *   @0x29fb8c mov r0, r6
 *   @0x29fb90 str r7, [r6, #0x38]
 *   @0x29fb94 mov r1, #5
 *   @0x29fb98 ldr r3, [r3, #0x8]
 *   @0x29fb9c blx r3
 *   @0x29fba0 ldr r3, [r6]
 *   @0x29fba4 str r7, [r6, #0x2c]
 *   @0x29fba8 mov r2, r8
 *   @0x29fbac mov r1, #1073741824
 *   @0x29fbb0 str r7, [r6, #0x38]
 *   @0x29fbb4 str r1, [r6, #0x30]
 *   @0x29fbb8 mov r0, r6
 *   @0x29fbbc ldr r3, [r3, #0x8]
 *   @0x29fbc0 mov r1, #5
 *   @0x29fbc4 blx r3
 *   @0x29fbc8 ldr r1, [r6]
 *   @0x29fbcc str r9, [r6, #0x2c]
 *   @0x29fbd0 mov r2, r8
 *   @0x29fbd4 str r7, [r6, #0x38]
 *   @0x29fbd8 mov r0, r6
 *   @0x29fbdc movw r3, #0x9154
 *   @0x29fbe0 movt r3, #0x41d5
 *   @0x29fbe4 str r3, [r6, #0x30]
 *   @0x29fbe8 ldr r3, [r1, #0x8]
 *   @0x29fbec mov r1, #5
 *   @0x29fbf0 blx r3
 *   @0x29fbf4 ldr r1, [r6]
 *   @0x29fbf8 mov r2, r8
 *   @0x29fbfc str r7, [r6, #0x2c]
 *   @0x29fc00 mov r3, r7
 *   @0x29fc04 str r7, [r6, #0x38]
 *   @0x29fc08 movt r3, #0x4020
 *   @0x29fc0c mov r0, r6
 *   @0x29fc10 str r3, [r6, #0x30]
 *   @0x29fc14 ldr r3, [r1, #0x8]
 *   @0x29fc18 mov r1, #5
 *   @0x29fc1c blx r3
 *   @0x29fc20 bl 0x159cf4 <_Z23YoYo_GetPlatform_DoWorkv>
 *   @0x29fc24 ldr r3, [r6]
 *   @0x29fc28 mov r2, r8
 *   @0x29fc2c str r7, [r6, #0x38]
 *   @0x29fc30 vmov d6, r0, r1
 *   @0x29fc34 mov r0, r6
 *   @0x29fc38 mov r1, #5
 *   @0x29fc3c vcvt.u32.f64 s15, d6
 *   @0x29fc40 vcvt.f64.u32 d6, s15
 *   @0x29fc44 vmov r4, r5, d6
 *   @0x29fc48 vstr s12, [r6, #44]
 *   @0x29fc4c str r5, [r6, #0x30]
 *   @0x29fc50 ldr r3, [r3, #0x8]
 *   @0x29fc54 blx r3
 *   @0x29fc58 ldr r1, [r6]
 *   @0x29fc5c str r7, [r6, #0x38]
 *   @0x29fc60 mov r2, #289406976
 *   @0x29fc64 mov r0, r6
 *   @0x29fc68 str r2, [r6, #0x2c]
 *   @0x29fc6c movw r3, #0xd3d1
 *   @0x29fc70 mov r2, r8
 *   @0x29fc74 movt r3, #0x41d0
 *   @0x29fc78 str r3, [r6, #0x30]
 *   @0x29fc7c ldr r3, [r1, #0x8]
 *   @0x29fc80 mov r1, #5
 *   @0x29fc84 blx r3
 *   @0x29fc88 mov r0, r6
 *   @0x29fc8c bl 0x29f380 <_Z16AddVMCodeBuffersP15Buffer_Standard>
 *   @0x29fc90 ldr r1, [r6]
 *   @0x29fc94 str r9, [r6, #0x2c]
 *   @0x29fc98 mov r2, r8
 *   @0x29fc9c str r7, [r6, #0x38]
 *   @0x29fca0 mov r0, r6
 *   @0x29fca4 movw r3, #0xd092
 *   @0x29fca8 movt r3, #0x41d3
 *   @0x29fcac str r3, [r6, #0x30]
 *   @0x29fcb0 ldr r3, [r1, #0x8]
 *   @0x29fcb4 mov r1, #5
 *   @0x29fcb8 blx r3
 *   @0x29fcbc mov r0, r6
 *   @0x29fcc0 bl 0x29e80c <_Z15TraverseObjectsP15Buffer_Standard>
 *   @0x29fcc4 ldr r1, [r6]
 *   @0x29fcc8 str r7, [r6, #0x38]
 *   @0x29fccc mov r2, #-1795162112
 *   @0x29fcd0 mov r0, r6
 *   @0x29fcd4 str r2, [r6, #0x2c]
 *   @0x29fcd8 movw r3, #0xd0d4
 *   @0x29fcdc mov r2, r8
 *   @0x29fce0 movt r3, #0x41d4
 *   @0x29fce4 str r3, [r6, #0x30]
 *   @0x29fce8 ldr r3, [r1, #0x8]
 *   @0x29fcec mov r1, #5
 *   @0x29fcf0 blx r3
 *   @0x29fcf4 mov r0, r6
 *   @0x29fcf8 bl 0x29ec54 <_Z10AddScriptsP15Buffer_Standard>
 *   @0x29fcfc ldr r1, [r6]
 *   @0x29fd00 str r7, [r6, #0x38]
 *   @0x29fd04 mov r2, r7
 *   @0x29fd08 mov r0, r6
 *   @0x29fd0c movt r2, #0x90c0
 *   @0x29fd10 movw r3, #0x9553
 *   @0x29fd14 str r2, [r6, #0x2c]
 *   @0x29fd18 movt r3, #0x41d1
 *   @0x29fd1c mov r2, r8
 *   @0x29fd20 str r3, [r6, #0x30]
 *   @0x29fd24 ldr r3, [r1, #0x8]
 *   @0x29fd28 mov r1, #5
 *   @0x29fd2c blx r3
 *   @0x29fd30 mov r0, r6
 *   @0x29fd34 bl 0x29f4e4 <_Z16AddFunctionNamesP15Buffer_Standard>
 *   @0x29fd38 ldr r1, [r6]
 *   @0x29fd3c str r7, [r6, #0x38]
 *   @0x29fd40 mov r2, #-788529152
 *   @0x29fd44 mov r0, r6
 *   @0x29fd48 str r2, [r6, #0x2c]
 *   @0x29fd4c movw r3, #0xd0d3
 *   @0x29fd50 mov r2, r8
 *   @0x29fd54 movt r3, #0x41d0
 *   @0x29fd58 str r3, [r6, #0x30]
 *   @0x29fd5c ldr r3, [r1, #0x8]
 *   @0x29fd60 mov r1, #5
 *   @0x29fd64 blx r3
 *   @0x29fd68 mov r0, r6
 *   @0x29fd6c bl 0x29edf0 <_Z15AddCreationCodeP15Buffer_Standard>
 *   @0x29fd70 ldr r1, [r6]
 *   @0x29fd74 str r7, [r6, #0x38]
 *   @0x29fd78 mov r2, #327155712
 *   @0x29fd7c mov r0, r6
 *   @0x29fd80 str r2, [r6, #0x2c]
 *   @0x29fd84 movw r3, #0x1353
 *   @0x29fd88 mov r2, r8
 *   @0x29fd8c movt r3, #0x41d5
 *   @0x29fd90 str r3, [r6, #0x30]
 *   @0x29fd94 ldr r3, [r1, #0x8]
 *   @0x29fd98 mov r1, #5
 *   @0x29fd9c blx r3
 *   @0x29fda0 mov r0, r6
 *   @0x29fda4 bl 0x29f1b8 <_Z15AddTimelineCodeP15Buffer_Standard>
 *   @0x29fda8 ldr r3, [r6]
 *   @0x29fdac ldr r9, [r6, #0x1c]
 *   @0x29fdb0 mov r1, r7
 *   @0x29fdb4 mov r0, r6
 *   @0x29fdb8 mov r2, #4
 *   @0x29fdbc ldr r3, [r3, #0x10]
 *   @0x29fdc0 blx r3
 *   @0x29fdc4 vmov s15, r9
 *   @0x29fdc8 ldr r3, [r6]
 *   @0x29fdcc mov r2, r8
 *   @0x29fdd0 vcvt.f64.u32 d7, s15
 *   @0x29fdd4 str r7, [r6, #0x38]
 *   @0x29fdd8 mov r0, r6
 *   @0x29fddc mov r1, #5
 *   @0x29fde0 vmov r4, r5, d7
 *   @0x29fde4 vstr s14, [r6, #44]
 *   @0x29fde8 str r5, [r6, #0x30]
 *   @0x29fdec ldr r3, [r3, #0x8]
 *   @0x29fdf0 blx r3
 *   @0x29fdf4 ldr r3, [r6]
 *   @0x29fdf8 mov r1, r7
 *   @0x29fdfc mov r2, r9
 *   @0x29fe00 mov r0, r6
 *   @0x29fe04 ldr r3, [r3, #0x10]
 *   @0x29fe08 blx r3
 *   @0x29fe0c ldr r3, [pc, #0x30]
 *   @0x29fe10 ldr r1, [pc, #0x30]
 *   @0x29fe14 mov r2, r9
 *   @0x29fe18 ldr r3, [pc, r3]
 *   @0x29fe1c add r1, pc, r1
 *   @0x29fe20 ldr r0, [r3]
 *   @0x29fe24 ldr r3, [r0]
 *   @0x29fe28 ldr r3, [r3, #0xc]
 *   @0x29fe2c blx r3
 *   @0x29fe30 mov r0, r10
 *   @0x29fe34 mov r2, r9
 *   @0x29fe38 ldr r1, [r6, #0xc]
 *   @0x29fe3c pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x29fe40 b 0x29d9a8 <_ZN9DbgSocket5WriteEPvj>
 *   @0x29fe44 ldrsheq sp, [r4], -r12
 *   @0x29fe48 andeq r9, r11, r8, lsl #28
 *
 * ══ §8/39 png_do_expand  0x2aa53c  size 792  198 条（0x2aa53c..0x2aa854）
 * @func 0x2aa53c 0x2aa854  size 792  198 条
 * 部分覆盖: 本节 198/345 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x14799ec / 0x3ee226 / 0x15da640 / 0x1aa89c4 / 0x1aa8dcc / png_do_expand+0x30a
 * 字段偏移 top8: 0x4×4 / 0x8×3 / 0x9×3 / 0x1×3 / 0x12×2 / 0xb×2 / 0x2×2 / 0x6×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2aa53c push.w {r0, r1, r2, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2aa540 ldrb r4, [r0, #0x8]
 *   @0x2aa544 cmp r4, #0x0
 *   @0x2aa548 ldrdlt r8, r9, [r10, -r7]
 *   @0x2aa54c ldrh r4, [r2, #0x8]
 *   @0x2aa550 mov r4, r2
 *   @0x2aa554 cmp r5, #0x7
 *   @0x2aa558 stchs p0, c8, [r2, #-520]
 *   @0x2aa55c beq 0x2aa5bc <png_do_expand+0x80>
 *   @0x2aa560 beq 0x2aa610 <png_do_expand+0xd4>
 *   @0x2aa564 bne 0x2aa656 <png_do_expand+0x11a>
 *   @0x2aa568 .word 0xf04f0401
 *   @0x2aa56c .word 0xf1030cff
 *   @0x2aa570 ldclne p8, c3, [lr, #1020]
 *   @0x2aa574 mul r4, r12, r4
 *   @0x2aa578 add.w r7, r1, r8, lsr #3
 *   @0x2aa57c mvns r6, r6
 *   @0x2aa580 and r6, r6, #0x7
 *   @0x2aa584 mvn.w r9, r3
 *   @0x2aa588 add.w r5, r8, #0xffffffff
 *   @0x2aa58c add r8, r9
 *   @0x2aa590 uxth r4, r4
 *   @0x2aa594 beq 0x2aa656 <png_do_expand+0x11a>
 *   @0x2aa598 stclo p0, c12, [r1, #-0]
 *   @0x2aa59c asr.w r12, r12, r6
 *   @0x2aa5a0 ands r12, r12, #0x1
 *   @0x2aa5a4 ite ne
 *   @0x2aa5a8 .word 0xf8859002
 *   @0x2aa5ac cdphs p0, #0x0, c12, c7, c2, #0x0
 *   @0x2aa5b0 itet eq
 *   @0x2aa5b4 .word 0x360137ff
 *   @0x2aa5b8 moveq r6, #0x0
 *   @0x2aa5bc and r4, r4, #0x3
 *   @0x2aa5c0 movs r5, #0x55
 *   @0x2aa5c4 muls r4, r5, r4
 *   @0x2aa5c8 add.w r12, r1, r6, lsr #2
 *   @0x2aa5cc add r6, r1
 *   @0x2aa5d0 and r5, r5, #0x3
 *   @0x2aa5d4 rsb r8, r3, r6
 *   @0x2aa5d8 lsls r5, r5, #0x1
 *   @0x2aa5dc beq 0x2aa656 <png_do_expand+0x11a>
 *   @0x2aa5e0 stchs p0, c7, [r6, #-0]
 *   @0x2aa5e4 it eq
 *   @0x2aa5e8 blx 0x14799ec <b2_toiTime+0xd20548>
 *   @0x2aa5ec svclt #0x8f705
 *   @0x2aa5f0 moveq r5, #0x0
 *   @0x2aa5f4 svclt #0x180703
 *   @0x2aa5f8 addne r5, #0x2
 *   @0x2aa5fc b 0x14f0a20 <b2_toiTime+0xd9757c>
 *   @0x2aa600 b 0x14ecc24 <b2_toiTime+0xd93780>
 *   @0x2aa604 b 0x14eca28 <b2_toiTime+0xd93584>
 *   @0x2aa608 .word 0xf8061787
 *   @0x2aa60c strb r7, [r4, r1, lsl #18]!
 *   @0x2aa610 and r4, r4, #0xf
 *   @0x2aa614 movs r5, #0x11
 *   @0x2aa618 blx 0x3ee226
 *   @0x2aa61c .word 0xf103f404
 *   @0x2aa620 svclt #0xc35ff
 *   @0x2aa624 moveq r6, #0x0
 *   @0x2aa628 add.w r7, r1, r5, lsr #1
 *   @0x2aa62c add r5, r1
 *   @0x2aa630 strbmi r0, [r5, #-0x805]
 *   @0x2aa634 beq 0x2aa656 <png_do_expand+0x11a>
 *   @0x2aa638 blx 0x15da640 <b2_toiTime+0xe8119c>
 *   @0x2aa63c .word 0xf00cfc06
 *   @0x2aa640 b 0x15ad684 <b2_toiTime+0xe541e0>
 *   @0x2aa644 .word 0xf8051c0c
 *   @0x2aa648 tstlt r6, r1, lsl #18
 *   @0x2aa64c subs r7, #0x1
 *   @0x2aa650 b 0x2aa632 <png_do_expand+0xf6>
 *   @0x2aa654 b 0x2aa632 <png_do_expand+0xf6>
 *   @0x2aa658 str r3, [r0, #0x4]
 *   @0x2aa65c strb r5, [r0, #0xb]
 *   @0x2aa660 beq.w 0x2aa84e <png_do_expand+0x312>
 *   @0x2aa664 ldrb r2, [r0, #0x9]
 *   @0x2aa668 bne 0x2aa698 <png_do_expand+0x15c>
 *   @0x2aa66c add.w r2, r1, r3, lsl #1
 *   @0x2aa670 add r1, r5
 *   @0x2aa674 subs r2, #0x2
 *   @0x2aa678 movs r7, #0xff
 *   @0x2aa67c adcsmi r0, r1, #0, #24
 *   @0x2aa680 beq 0x2aa6b8 <png_do_expand+0x17c>
 *   @0x2aa684 adcmi r5, r5, #16384
 *   @0x2aa688 ite ne
 *   @0x2aa68c moveq r5, r12
 *   @0x2aa690 ldrb r5, [r1, #0x1]
 *   @0x2aa694 ldrb r5, [r2, r2, lsl #18]!
 *   @0x2aa698 cmp r2, #0x10
 *   @0x2aa69c ldr r5, [r0, #0x4]
 *   @0x2aa6a0 rsclt r2, r4, #1792
 *   @0x2aa6a4 movs r6, #0xff
 *   @0x2aa6a8 add.w r1, r1, r5, lsl #1
 *   @0x2aa6ac subs r2, #0x3
 *   @0x2aa6b0 subs r1, #0x3
 *   @0x2aa6b4 cmp r5, r3
 *   @0x2aa6b8 movs r2, #0x4
 *   @0x2aa6bc movs r2, #0x2
 *   @0x2aa6c0 ldrb r2, [r0, #0x9]
 *   @0x2aa6c4 b 0x2aa7be <png_do_expand+0x282>
 *   @0x2aa6c8 strbmi r8, [r0, #0x1]!
 *   @0x2aa6cc bne 0x2aa6dc <png_do_expand+0x1a0>
 *   @0x2aa6d0 strmi r8, [r0, #0x2]!
 *   @0x2aa6d4 bne 0x2aa6dc <png_do_expand+0x1a0>
 *   @0x2aa6d8 strb r7, [r1, #0x1]
 *   @0x2aa6dc strb r6, [r1, #0x2]
 *   @0x2aa6e0 ldrb.w r8, [r2, #0x2]
 *   @0x2aa6e4 adds r5, #0x1
 *   @0x2aa6e8 subs r1, #0x4
 *   @0x2aa6ec .word 0xf8928004
 *   @0x2aa6f0 .word 0xf8818003
 *   @0x2aa6f4 ldrb r8, [sp, r3]
 *   @0x2aa6f8 cmp r4, #0x2
 *   @0x2aa6fc bhs 0x2ca9a4 <_ZN7b2World9DrawShapeEP9b2FixtureRK11b2TransformRK7b2Color+0x140>
 *   @0x2aa700 beq.w 0x2aa84e <png_do_expand+0x312>
 *   @0x2aa704 ldrb r4, [r0, #0x9]
 *   @0x2aa708 bne 0x2aa76e <png_do_expand+0x232>
 *   @0x2aa70c movs r4, #0x3
 *   @0x2aa710 mov.w r12, #0xff
 *   @0x2aa714 ldrb r7, [r2, #0x6]
 *   @0x2aa718 stmdavs r2, {r11} ^
 *   @0x2aa71c subs r2, #0x1
 *   @0x2aa720 add.w r1, r1, r3, lsl #2
 *   @0x2aa724 subs r1, #0x2
 *   @0x2aa728 adcmi r2, r2, #318767104
 *   @0x2aa72c beq 0x2aa7b2 <png_do_expand+0x276>
 *   @0x2aa730 strmi r9, [r9, #0xc02]!
 *   @0x2aa734 bne 0x2aa74c <png_do_expand+0x210>
 *   @0x2aa738 ldrmi r9, [r1, #0xc01]!
 *   @0x2aa73c bne 0x2aa74c <png_do_expand+0x210>
 *   @0x2aa740 ldrmi r9, [r9, #0x0]!
 *   @0x2aa744 bne 0x2aa74c <png_do_expand+0x210>
 *   @0x2aa748 and r8, r1, r1
 *   @0x2aa74c strb.w r12, [r1, #0x1]
 *   @0x2aa750 ldrb.w r9, [r2]
 *   @0x2aa754 subs r1, #0x4
 *   @0x2aa758 strb.w r9, [r1, #0x4]
 *   @0x2aa75c ldrb.w r9, [r2, #0x2]
 *   @0x2aa760 strb.w r9, [r1, #0x3]
 *   @0x2aa764 ldrb.w r9, [r2, #0x1]
 *   @0x2aa768 strb.w r9, [r1, #0x2]
 *   @0x2aa76c b 0x2aa72a <png_do_expand+0x1ee>
 *   @0x2aa770 bne 0x2aa7b2 <png_do_expand+0x276>
 *   @0x2aa774 ldrbhs r8, [pc, #0x2]!
 *   @0x2aa778 ldrh.w r9, [r2, #0x4]
 *   @0x2aa77c ldrh.w r10, [r2, #0x6]
 *   @0x2aa780 ldr r2, [r0, #0x4]
 *   @0x2aa784 b 0x16737ec <b2_toiTime+0xf1a348>
 *   @0x2aa788 strls r2, [r1], #-1817
 *   @0x2aa78c subs r2, #0x1
 *   @0x2aa790 strmi r2, [r10], #-3098
 *   @0x2aa794 add.w r1, r1, r3, lsl #3
 *   @0x2aa798 movs r4, #0x0
 *   @0x2aa79c blx 0x1aa89c4 <b2_toiTime+0x134f520>
 *   @0x2aa7a0 blx 0x1aa8dcc <b2_toiTime+0x134f928>
 *   @0x2aa7a4 stmdblo r3, {r1, r3, r7, r9, r11, r12, sp, lr, pc}
 *   @0x2aa7a8 mov r6, r4
 *   @0x2aa7ac addsmi r12, r12, #0
 *   @0x2aa7b0 bne 0x2aa7cc <png_do_expand+0x290>
 *   @0x2aa7b4 strb r2, [r0, #0x8]
 *   @0x2aa7b8 strb r2, [r0, #0xa]
 *   @0x2aa7bc lsls r2, r2, #0x2
 *   @0x2aa7c0 strb r2, [r0, #0xb]
 *   @0x2aa7c4 bls 0x2aa846 <png_do_expand+0x30a>
 *   @0x2aa7c8 muls r3, r2, r3
 *   @0x2aa7cc ldrb r11, [r2, #-5]
 *   @0x2aa7d0 ldr.w r12, [sp, #0x4]
 *   @0x2aa7d4 cmp r11, r12
 *   @0x2aa7d8 ldrb r11, [r2, #-4]
 *   @0x2aa7dc cmp r11, r8
 *   @0x2aa7e0 ldrb r11, [r2, #-3]
 *   @0x2aa7e4 cmp r11, r7
 *   @0x2aa7e8 ldrb r11, [r2, #-2]
 *   @0x2aa7ec cmp r11, r9
 *   @0x2aa7f0 ldrb r11, [r2, #-1]
 *   @0x2aa7f4 ldr.w r12, [sp]
 *   @0x2aa7f8 cmp r11, r12
 *   @0x2aa7fc ldrb.w r11, [r2]
 *   @0x2aa800 cmp r11, r10
 *   @0x2aa804 strb r6, [r1, #0x2]
 *   @0x2aa808 b 0x2aa80e <png_do_expand+0x2d2>
 *   @0x2aa80c strb r5, [r1, #0x1]
 *   @0x2aa810 strlo r11, [r1], #-0
 *   @0x2aa814 subs r2, #0x6
 *   @0x2aa818 strb.w r11, [r1, #0x8]
 *   @0x2aa81c ldrb.w r11, [r2, #0x5]
 *   @0x2aa820 strb.w r11, [r1, #0x7]
 *   @0x2aa824 ldrb.w r11, [r2, #0x4]
 *   @0x2aa828 strb.w r11, [r1, #0x6]
 *   @0x2aa82c ldrb.w r11, [r2, #0x3]
 *   @0x2aa830 strb.w r11, [r1, #0x5]
 *   @0x2aa834 ldrb.w r11, [r2, #0x2]
 *   @0x2aa838 strb.w r11, [r1, #0x4]
 *   @0x2aa83c ldrb.w r11, [r2, #0x1]
 *   @0x2aa840 strb.w r11, [r1, #0x3]
 *   @0x2aa844 b 0x2aa7ae <png_do_expand+0x272>
 *   @0x2aa848 adds r3, #0x7
 *   @0x2aa84c str r3, [r0, #0x4]
 *   @0x2aa850 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §9/39 CFontGM::CFontGM(YYEmbeddedFont*)  0xf768c  size 788  197 条（0xf768c..0xf79a0）
 * @func 0xf768c 0xf79a0  size 788  197 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / CFontGM::Clear() / 0xb65bc / GR_Texture_Create_From_File(unsigned char*, unsigned int) / 0xb6544 / CFontGM::CFontGM(YYEmbeddedFont*)+0x2b4 / CFontGM::CFontGM(YYEmbeddedFont*)+0x2fc / YYStrDup(char const*)
 * 字段偏移 top8: 0x4×12 / 0x8×6 / 0xc×6 / 0x24×5 / 0x2×5 / 0x18×4 / 0x2c×4 / 0x30×4
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf768c ldr r3, [pc, #0x2fc]
 *   @0xf7690 mov r12, #1056964608
 *   @0xf7694 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xf7698 ldr r3, [pc, r3]
 *   @0xf769c mov r5, #0
 *   @0xf76a0 str r12, [r0, #0x50]
 *   @0xf76a4 sub sp, sp, #12
 *   @0xf76a8 mvn r2, #0
 *   @0xf76ac str r5, [r0, #0x4]
 *   @0xf76b0 add r3, r3, #8
 *   @0xf76b4 str r2, [r0, #0x20]
 *   @0xf76b8 mov r4, r0
 *   @0xf76bc str r3, [r0]
 *   @0xf76c0 mov r3, #1065353216
 *   @0xf76c4 str r2, [r0, #0x38]
 *   @0xf76c8 mov r6, r1
 *   @0xf76cc str r5, [r0, #0x8]
 *   @0xf76d0 strb r5, [r0, #0xc]
 *   @0xf76d4 strb r5, [r0, #0xd]
 *   @0xf76d8 str r5, [r0, #0x18]
 *   @0xf76dc str r5, [r0, #0x1c]
 *   @0xf76e0 str r5, [r0, #0x24]
 *   @0xf76e4 str r5, [r0, #0x28]
 *   @0xf76e8 str r5, [r0, #0x2c]
 *   @0xf76ec str r5, [r0, #0x40]
 *   @0xf76f0 str r5, [r0, #0x44]
 *   @0xf76f4 str r5, [r0, #0x5c]
 *   @0xf76f8 str r5, [r0, #0x60]
 *   @0xf76fc str r3, [r0, #0x48]
 *   @0xf7700 str r3, [r0, #0x4c]
 *   @0xf7704 str r5, [r0, #0x64]
 *   @0xf7708 str r5, [r0, #0x6c]
 *   @0xf770c str r5, [r0, #0x70]
 *   @0xf7710 str r5, [r0, #0x74]
 *   @0xf7714 str r5, [r0, #0x78]
 *   @0xf7718 str r5, [r0, #0x7c]
 *   @0xf771c str r5, [r0, #0x80]
 *   @0xf7720 str r5, [r0, #0x84]
 *   @0xf7724 str r5, [r0, #0x88]
 *   @0xf7728 str r5, [r0, #0x3c]
 *   @0xf772c str r5, [r0, #0x34]
 *   @0xf7730 str r5, [r0, #0x30]
 *   @0xf7734 str r5, [r0, #0x54]
 *   @0xf7738 str r5, [r0, #0x8c]
 *   @0xf773c bl 0xf70a0 <_ZN7CFontGM5ClearEv>
 *   @0xf7740 ldr r1, [pc, #0x24c]
 *   @0xf7744 mov r3, #1
 *   @0xf7748 mov r2, #70
 *   @0xf774c add r1, pc, r1
 *   @0xf7750 ldr r0, [r6, #0x30]
 *   @0xf7754 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xf7758 ldr r2, [r6, #0x30]
 *   @0xf775c ldr r1, [r6, #0x34]
 *   @0xf7760 bl 0xb65bc <memcpy@plt>
 *   @0xf7764 ldr r1, [r6, #0x30]
 *   @0xf7768 bl 0x173b20 <_Z27GR_Texture_Create_From_FilePhj>
 *   @0xf776c ldr r3, [pc, #0x224]
 *   @0xf7770 ldr r3, [pc, r3]
 *   @0xf7774 ldr r3, [r3, #0x4]
 *   @0xf7778 mov r7, r0
 *   @0xf777c mov r0, #22
 *   @0xf7780 ldr r8, [r3, r7, lsl #2]
 *   @0xf7784 bl 0xb6544 <malloc@plt>
 *   @0xf7788 ldr r9, [r6, #0xc]
 *   @0xf778c ldr lr, [r6, #0x10]
 *   @0xf7790 subs r9, r9, r5
 *   @0xf7794 ldr r2, [r6, #0x14]
 *   @0xf7798 ldrh r12, [r8, #4]
 *   @0xf779c ldrh r1, [r8, #6]
 *   @0xf77a0 movne r9, #1
 *   @0xf77a4 subs lr, lr, r5
 *   @0xf77a8 ldr r8, [r6, #0x8]
 *   @0xf77ac movne lr, #1
 *   @0xf77b0 mov r3, r0
 *   @0xf77b4 str r0, [r4, #0x3c]
 *   @0xf77b8 ubfx r0, r2, #0x10, #0x8
 *   @0xf77bc strh r5, [r3]
 *   @0xf77c0 strh r5, [r3, #2]
 *   @0xf77c4 cmp r0, r5
 *   @0xf77c8 strh r12, [r3, #4]
 *   @0xf77cc strh r1, [r3, #6]
 *   @0xf77d0 strh r12, [r3, #12]
 *   @0xf77d4 strh r1, [r3, #14]
 *   @0xf77d8 strh r12, [r3, #16]
 *   @0xf77dc sxth r12, r12
 *   @0xf77e0 strh r1, [r3, #18]
 *   @0xf77e4 sxth r1, r1
 *   @0xf77e8 strh r5, [r3, #8]
 *   @0xf77ec strh r5, [r3, #10]
 *   @0xf77f0 uxth r5, r2
 *   @0xf77f4 strh r7, [r3, #20]
 *   @0xf77f8 strne r0, [r4, #0x10]
 *   @0xf77fc lsrs r3, r2, #24
 *   @0xf7800 subne r3, r3, #1
 *   @0xf7804 strne r3, [r4, #0x14]
 *   @0xf7808 ldr r3, [r6, #0x24]
 *   @0xf780c ldr r0, [r6, #0x2c]
 *   @0xf7810 str r2, [r4, #0x18]
 *   @0xf7814 add r2, r3, r3, lsl #2
 *   @0xf7818 strb lr, [r4, #0xd]
 *   @0xf781c ldr lr, [r6, #0x18]
 *   @0xf7820 lsl r2, r2, #2
 *   @0xf7824 str r12, [r4, #0x24]
 *   @0xf7828 add r0, r2, r0, lsl #2
 *   @0xf782c ldr r12, [r6, #0x1c]
 *   @0xf7830 ldr r2, [r6, #0x20]
 *   @0xf7834 str r1, [r4, #0x28]
 *   @0xf7838 ldr r1, [pc, #0x15c]
 *   @0xf783c str r5, [r4, #0x18]
 *   @0xf7840 mov r5, #0
 *   @0xf7844 str lr, [r4, #0x1c]
 *   @0xf7848 add r1, pc, r1
 *   @0xf784c str r12, [r4, #0x48]
 *   @0xf7850 str r8, [r4, #0x8]
 *   @0xf7854 strb r9, [r4, #0xc]
 *   @0xf7858 str r3, [r4, #0x40]
 *   @0xf785c mov r3, #1
 *   @0xf7860 str r2, [r4, #0x4c]
 *   @0xf7864 mov r2, #70
 *   @0xf7868 str r5, [r4, #0x2c]
 *   @0xf786c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xf7870 ldr r2, [r6, #0x24]
 *   @0xf7874 cmp r2, r5
 *   @0xf7878 str r0, [r4, #0x44]
 *   @0xf787c add r3, r0, r2, lsl #2
 *   @0xf7880 ble 0xf7940 <_ZN7CFontGMC2EP14YYEmbeddedFont+0x2b4>
 *   @0xf7884 sub r1, r0, #4
 *   @0xf7888 mov r12, r5
 *   @0xf788c mov r0, r5
 *   @0xf7890 mov r11, r2
 *   @0xf7894 str r4, [sp, #0x4]
 *   @0xf7898 str r3, [r1, #0x4]!
 *   @0xf789c add r10, r3, #16
 *   @0xf78a0 ldr lr, [r6, #0x28]
 *   @0xf78a4 add r2, lr, r12
 *   @0xf78a8 ldrh r8, [lr, r12]
 *   @0xf78ac ldrh r7, [r2, #2]
 *   @0xf78b0 ldrh lr, [r2, #14]
 *   @0xf78b4 ldrh r5, [r2, #4]
 *   @0xf78b8 ldrh r9, [r2, #6]
 *   @0xf78bc sxth r4, lr
 *   @0xf78c0 strh r8, [r3]
 *   @0xf78c4 ldrh r8, [r2, #8]
 *   @0xf78c8 cmp r4, #0
 *   @0xf78cc strh r7, [r3, #2]
 *   @0xf78d0 ldrh r7, [r2, #10]
 *   @0xf78d4 strh r5, [r3, #4]
 *   @0xf78d8 ldrh r5, [r2, #12]
 *   @0xf78dc strh r9, [r3, #6]
 *   @0xf78e0 strh r8, [r3, #8]
 *   @0xf78e4 strh r7, [r3, #10]
 *   @0xf78e8 strh lr, [r3, #14]
 *   @0xf78ec strh r5, [r3, #12]
 *   @0xf78f0 ble 0xf7988 <_ZN7CFontGMC2EP14YYEmbeddedFont+0x2fc>
 *   @0xf78f4 ldr r5, [r2, #0x10]
 *   @0xf78f8 add r3, r3, #20
 *   @0xf78fc lsl r4, r4, #2
 *   @0xf7900 mov lr, #0
 *   @0xf7904 mov r2, r5
 *   @0xf7908 add r3, r3, #4
 *   @0xf790c ldrh r7, [r2, lr]!
 *   @0xf7910 add lr, lr, #4
 *   @0xf7914 cmp lr, r4
 *   @0xf7918 strh r7, [r3, #-8]
 *   @0xf791c ldrh r2, [r2, #2]
 *   @0xf7920 strh r2, [r3, #-6]
 *   @0xf7924 bne 0xf7904 <_ZN7CFontGMC2EP14YYEmbeddedFont+0x278>
 *   @0xf7928 add r3, r10, lr
 *   @0xf792c add r0, r0, #1
 *   @0xf7930 add r12, r12, #20
 *   @0xf7934 cmp r0, r11
 *   @0xf7938 bne 0xf7898 <_ZN7CFontGMC2EP14YYEmbeddedFont+0x20c>
 *   @0xf793c ldr r4, [sp, #0x4]
 *   @0xf7940 ldr r0, [r6, #0x4]
 *   @0xf7944 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xf7948 ldr r2, [r6, #0x24]
 *   @0xf794c cmp r2, #0
 *   @0xf7950 ldrgt r3, [r4, #0x44]
 *   @0xf7954 str r0, [r4, #0x4]
 *   @0xf7958 addgt r0, r3, r2, lsl #2
 *   @0xf795c ble 0xf797c <_ZN7CFontGMC2EP14YYEmbeddedFont+0x2f0>
 *   @0xf7960 ldr r2, [r3], #4
 *   @0xf7964 ldr r1, [r4, #0x2c]
 *   @0xf7968 ldrsh r2, [r2, #8]
 *   @0xf796c cmp r1, r2
 *   @0xf7970 strlt r2, [r4, #0x2c]
 *   @0xf7974 cmp r3, r0
 *   @0xf7978 bne 0xf7960 <_ZN7CFontGMC2EP14YYEmbeddedFont+0x2d4>
 *   @0xf797c mov r0, r4
 *   @0xf7980 add sp, sp, #12
 *   @0xf7984 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xf7988 mov r3, r10
 *   @0xf798c b 0xf792c <_ZN7CFontGMC2EP14YYEmbeddedFont+0x2a0>
 *   @0xf7990 .word 0x002f67b0
 *   @0xf7994 eoreq r9, r3, r4, ror #17
 *   @0xf7998 eoreq r6, pc, r12, lsr #3
 *   @0xf799c eoreq r9, r3, r8, ror #15
 *
 * ══ §10/39 F_DsMapFindNext(RValue&, CInstance*, CInstance*, int, RValue*)  0x104080  size 788  197 条（0x104080..0x104394）
 * @func 0x104080 0x1043a4  size 804  201 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / DS_AutoMutex::~DS_AutoMutex()×2 / DS_AutoMutex::DS_AutoMutex() / YYGetInt32(RValue const*, int) / F_DsMapFindNext(RValue&, CInstance*, CInstance*, int, RValue*)+0x11c
 * 字段偏移 top8: 0x4×13 / 0x8×13 / 0xc×8 / 0x14×4 / 0x30×1 / 0x2d0×1 / 0x2c0×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x104080 push {r4, r5, r6, r7, lr}
 *   @0x104084 sub sp, sp, #28
 *   @0x104088 add r5, sp, #4
 *   @0x10408c mov r4, r0
 *   @0x104090 ldr r6, [sp, #0x30]
 *   @0x104094 mov r0, r5
 *   @0x104098 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0x10409c mov r1, #0
 *   @0x1040a0 mov r0, r6
 *   @0x1040a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1040a8 cmp r0, #0
 *   @0x1040ac blt 0x10419c <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x1040b0 ldr r3, [pc, #0x2d0]
 *   @0x1040b4 ldr r3, [pc, r3]
 *   @0x1040b8 ldr r3, [r3]
 *   @0x1040bc cmp r0, r3
 *   @0x1040c0 bge 0x10419c <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x1040c4 ldr r3, [pc, #0x2c0]
 *   @0x1040c8 ldr r3, [pc, r3]
 *   @0x1040cc ldr r3, [r3, #0x4]
 *   @0x1040d0 ldr r0, [r3, r0, lsl #2]
 *   @0x1040d4 cmp r0, #0
 *   @0x1040d8 beq 0x10419c <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x1040dc add r1, r6, #16
 *   @0x1040e0 bl 0x203b94 <_ZN7CDS_Map8FindNextEP6RValue>
 *   @0x1040e4 subs r3, r0, #0
 *   @0x1040e8 beq 0x1041e8 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x1040ec ldr r2, [r3, #0x8]
 *   @0x1040f0 add r12, sp, #8
 *   @0x1040f4 ldr r0, [r3]
 *   @0x1040f8 ldr r1, [r3, #0x4]
 *   @0x1040fc ldr r6, [r4, #0xc]
 *   @0x104100 ldr r3, [r3, #0xc]
 *   @0x104104 bic lr, r6, #-16777216
 *   @0x104108 cmp lr, #1
 *   @0x10410c stm r12!, {r0, r1, r2, r3}
 *   @0x104110 ldr r2, [sp, #0x14]
 *   @0x104114 bic r2, r2, #-16777216
 *   @0x104118 str r2, [sp, #0x14]
 *   @0x10411c beq 0x1041fc <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x17c>
 *   @0x104120 cmp lr, #2
 *   @0x104124 bne 0x10413c <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x104128 sub r6, r6, #1
 *   @0x10412c bic r6, r6, #-16777216
 *   @0x104130 bic r6, r6, #3
 *   @0x104134 cmp r6, #0
 *   @0x104138 beq 0x1042e4 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x264>
 *   @0x10413c ldr r1, [sp, #0x10]
 *   @0x104140 bic r3, r2, #-16777216
 *   @0x104144 str r2, [r4, #0xc]
 *   @0x104148 mov r2, #0
 *   @0x10414c str r2, [r4]
 *   @0x104150 str r1, [r4, #0x8]
 *   @0x104154 cmp r3, #14
 *   @0x104158 addls pc, pc, r3, lsl #2
 *   @0x10415c b 0x1041c4 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x104160 b 0x1041d8 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x158>
 *   @0x104164 b 0x10425c <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x1dc>
 *   @0x104168 b 0x104280 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x200>
 *   @0x10416c b 0x1041bc <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x104170 b 0x1041c4 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x104174 b 0x1041c4 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x104178 b 0x104234 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x1b4>
 *   @0x10417c b 0x1041bc <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x104180 b 0x1041c4 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x104184 b 0x1041c4 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x104188 b 0x1041d8 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x158>
 *   @0x10418c b 0x1041c4 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x104190 b 0x1041c4 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x104194 b 0x1041d8 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x158>
 *   @0x104198 b 0x1041bc <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x10419c ldr r0, [pc, #0x1ec]
 *   @0x1041a0 mov r1, #0
 *   @0x1041a4 add r0, pc, r0
 *   @0x1041a8 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1041ac mov r0, r5
 *   @0x1041b0 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x1041b4 add sp, sp, #28
 *   @0x1041b8 pop {r4, r5, r6, r7, pc}
 *   @0x1041bc ldr r2, [sp, #0x8]
 *   @0x1041c0 str r2, [r4]
 *   @0x1041c4 str r3, [r4, #0xc]
 *   @0x1041c8 mov r0, r5
 *   @0x1041cc bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x1041d0 add sp, sp, #28
 *   @0x1041d4 pop {r4, r5, r6, r7, pc}
 *   @0x1041d8 ldr r1, [sp, #0x8]
 *   @0x1041dc ldr r2, [sp, #0xc]
 *   @0x1041e0 stm r4, {r1, r2}
 *   @0x1041e4 b 0x1041c4 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x1041e8 mov r2, #5
 *   @0x1041ec str r3, [r4]
 *   @0x1041f0 str r3, [r4, #0x4]
 *   @0x1041f4 str r2, [r4, #0xc]
 *   @0x1041f8 b 0x1041c8 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x148>
 *   @0x1041fc ldr r6, [r4]
 *   @0x104200 cmp r6, #0
 *   @0x104204 beq 0x104228 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x1a8>
 *   @0x104208 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x10420c ldr r7, [r6, #0x4]
 *   @0x104210 sub r7, r7, #1
 *   @0x104214 str r7, [r6, #0x4]
 *   @0x104218 cmp r7, #0
 *   @0x10421c beq 0x1042ac <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x22c>
 *   @0x104220 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x104224 ldr r2, [sp, #0x14]
 *   @0x104228 mov r3, #0
 *   @0x10422c str r3, [r4]
 *   @0x104230 b 0x10413c <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x104234 ldr r2, [sp, #0x8]
 *   @0x104238 cmp r2, #0
 *   @0x10423c str r2, [r4]
 *   @0x104240 beq 0x1041c4 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x104244 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x104248 ldr r1, [sp, #0x8]
 *   @0x10424c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x104250 ldr r3, [r4, #0xc]
 *   @0x104254 bic r3, r3, #-16777216
 *   @0x104258 b 0x1041c4 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x10425c ldr r2, [sp, #0x8]
 *   @0x104260 cmp r2, #0
 *   @0x104264 beq 0x1041c0 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x104268 ldr r3, [r2, #0x4]
 *   @0x10426c add r3, r3, #1
 *   @0x104270 str r3, [r2, #0x4]
 *   @0x104274 ldr r3, [r4, #0xc]
 *   @0x104278 bic r3, r3, #-16777216
 *   @0x10427c b 0x1041c0 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x104280 ldr r2, [sp, #0x8]
 *   @0x104284 cmp r2, #0
 *   @0x104288 str r2, [r4]
 *   @0x10428c beq 0x1041c4 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x104290 ldr r0, [r2, #0x8]
 *   @0x104294 ldr r1, [r2]
 *   @0x104298 cmp r0, #0
 *   @0x10429c streq r4, [r2, #0x8]
 *   @0x1042a0 add r1, r1, #1
 *   @0x1042a4 str r1, [r2]
 *   @0x1042a8 b 0x1041c4 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x1042ac ldr r0, [r6]
 *   @0x1042b0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1042b4 str r7, [r6]
 *   @0x1042b8 str r7, [r6, #0x8]
 *   @0x1042bc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1042c0 ldr r7, [r6, #0x4]
 *   @0x1042c4 sub r7, r7, #1
 *   @0x1042c8 str r7, [r6, #0x4]
 *   @0x1042cc cmp r7, #0
 *   @0x1042d0 beq 0x1042f4 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x274>
 *   @0x1042d4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1042d8 mov r0, r6
 *   @0x1042dc bl 0x27d1d0 <_ZdlPv>
 *   @0x1042e0 b 0x104220 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x1a0>
 *   @0x1042e4 mov r0, r4
 *   @0x1042e8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x1042ec ldr r2, [sp, #0x14]
 *   @0x1042f0 b 0x10413c <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x1042f4 ldr r0, [r6]
 *   @0x1042f8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1042fc str r7, [r6]
 *   @0x104300 str r7, [r6, #0x8]
 *   @0x104304 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x104308 ldr r7, [r6, #0x4]
 *   @0x10430c sub r7, r7, #1
 *   @0x104310 str r7, [r6, #0x4]
 *   @0x104314 cmp r7, #0
 *   @0x104318 beq 0x10432c <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x2ac>
 *   @0x10431c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x104320 mov r0, r6
 *   @0x104324 bl 0x27d1d0 <_ZdlPv>
 *   @0x104328 b 0x1042d4 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x254>
 *   @0x10432c ldr r0, [r6]
 *   @0x104330 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x104334 str r7, [r6]
 *   @0x104338 str r7, [r6, #0x8]
 *   @0x10433c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x104340 ldr r3, [r6, #0x4]
 *   @0x104344 sub r3, r3, #1
 *   @0x104348 str r3, [r6, #0x4]
 *   @0x10434c cmp r3, #0
 *   @0x104350 bne 0x104378 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x2f8>
 *   @0x104354 ldr r0, [r6]
 *   @0x104358 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x10435c mov r3, #0
 *   @0x104360 mov r0, r6
 *   @0x104364 str r3, [r6]
 *   @0x104368 str r3, [r6, #0x8]
 *   @0x10436c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x104370 mov r0, r6
 *   @0x104374 bl 0x27d1d0 <_ZdlPv>
 *   @0x104378 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x10437c mov r0, r6
 *   @0x104380 bl 0x27d1d0 <_ZdlPv>
 *   @0x104384 b 0x10431c <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x29c>
 *   @0x104388 eoreq r9, lr, r4, asr #23
 *   @0x10438c eoreq r9, lr, r4, ror r8
 *   @0x104390 eoreq r3, r3, r8, asr r10
 *
 * ══ §11/39 F_DsMapFindPrevious(RValue&, CInstance*, CInstance*, int, RValue*)  0x1071bc  size 788  197 条（0x1071bc..0x1074d0）
 * @func 0x1071bc 0x1074d0  size 788  197 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / DS_AutoMutex::~DS_AutoMutex()×2 / DS_AutoMutex::DS_AutoMutex() / YYGetInt32(RValue const*, int) / F_DsMapFindPrevious(RValue&, CInstance*, CInstance*, int, RValue*)+0x11c
 * 字段偏移 top8: 0x4×13 / 0x8×13 / 0xc×8 / 0x14×4 / 0x30×1 / 0x2d0×1 / 0x2c0×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1071bc push {r4, r5, r6, r7, lr}
 *   @0x1071c0 sub sp, sp, #28
 *   @0x1071c4 add r5, sp, #4
 *   @0x1071c8 mov r4, r0
 *   @0x1071cc ldr r6, [sp, #0x30]
 *   @0x1071d0 mov r0, r5
 *   @0x1071d4 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0x1071d8 mov r1, #0
 *   @0x1071dc mov r0, r6
 *   @0x1071e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1071e4 cmp r0, #0
 *   @0x1071e8 blt 0x1072d8 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x1071ec ldr r3, [pc, #0x2d0]
 *   @0x1071f0 ldr r3, [pc, r3]
 *   @0x1071f4 ldr r3, [r3]
 *   @0x1071f8 cmp r0, r3
 *   @0x1071fc bge 0x1072d8 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x107200 ldr r3, [pc, #0x2c0]
 *   @0x107204 ldr r3, [pc, r3]
 *   @0x107208 ldr r3, [r3, #0x4]
 *   @0x10720c ldr r0, [r3, r0, lsl #2]
 *   @0x107210 cmp r0, #0
 *   @0x107214 beq 0x1072d8 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x107218 add r1, r6, #16
 *   @0x10721c bl 0x203a80 <_ZN7CDS_Map12FindPreviousEP6RValue>
 *   @0x107220 subs r3, r0, #0
 *   @0x107224 beq 0x107324 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x107228 ldr r2, [r3, #0x8]
 *   @0x10722c add r12, sp, #8
 *   @0x107230 ldr r0, [r3]
 *   @0x107234 ldr r1, [r3, #0x4]
 *   @0x107238 ldr r6, [r4, #0xc]
 *   @0x10723c ldr r3, [r3, #0xc]
 *   @0x107240 bic lr, r6, #-16777216
 *   @0x107244 cmp lr, #1
 *   @0x107248 stm r12!, {r0, r1, r2, r3}
 *   @0x10724c ldr r2, [sp, #0x14]
 *   @0x107250 bic r2, r2, #-16777216
 *   @0x107254 str r2, [sp, #0x14]
 *   @0x107258 beq 0x107338 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x17c>
 *   @0x10725c cmp lr, #2
 *   @0x107260 bne 0x107278 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x107264 sub r6, r6, #1
 *   @0x107268 bic r6, r6, #-16777216
 *   @0x10726c bic r6, r6, #3
 *   @0x107270 cmp r6, #0
 *   @0x107274 beq 0x107420 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x264>
 *   @0x107278 ldr r1, [sp, #0x10]
 *   @0x10727c bic r3, r2, #-16777216
 *   @0x107280 str r2, [r4, #0xc]
 *   @0x107284 mov r2, #0
 *   @0x107288 str r2, [r4]
 *   @0x10728c str r1, [r4, #0x8]
 *   @0x107290 cmp r3, #14
 *   @0x107294 addls pc, pc, r3, lsl #2
 *   @0x107298 b 0x107300 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x10729c b 0x107314 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x158>
 *   @0x1072a0 b 0x107398 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x1dc>
 *   @0x1072a4 b 0x1073bc <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x200>
 *   @0x1072a8 b 0x1072f8 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x1072ac b 0x107300 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x1072b0 b 0x107300 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x1072b4 b 0x107370 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x1b4>
 *   @0x1072b8 b 0x1072f8 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x1072bc b 0x107300 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x1072c0 b 0x107300 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x1072c4 b 0x107314 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x158>
 *   @0x1072c8 b 0x107300 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x1072cc b 0x107300 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x1072d0 b 0x107314 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x158>
 *   @0x1072d4 b 0x1072f8 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x1072d8 ldr r0, [pc, #0x1ec]
 *   @0x1072dc mov r1, #0
 *   @0x1072e0 add r0, pc, r0
 *   @0x1072e4 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1072e8 mov r0, r5
 *   @0x1072ec bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x1072f0 add sp, sp, #28
 *   @0x1072f4 pop {r4, r5, r6, r7, pc}
 *   @0x1072f8 ldr r2, [sp, #0x8]
 *   @0x1072fc str r2, [r4]
 *   @0x107300 str r3, [r4, #0xc]
 *   @0x107304 mov r0, r5
 *   @0x107308 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x10730c add sp, sp, #28
 *   @0x107310 pop {r4, r5, r6, r7, pc}
 *   @0x107314 ldr r1, [sp, #0x8]
 *   @0x107318 ldr r2, [sp, #0xc]
 *   @0x10731c stm r4, {r1, r2}
 *   @0x107320 b 0x107300 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x107324 mov r2, #5
 *   @0x107328 str r3, [r4]
 *   @0x10732c str r3, [r4, #0x4]
 *   @0x107330 str r2, [r4, #0xc]
 *   @0x107334 b 0x107304 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x148>
 *   @0x107338 ldr r6, [r4]
 *   @0x10733c cmp r6, #0
 *   @0x107340 beq 0x107364 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x1a8>
 *   @0x107344 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x107348 ldr r7, [r6, #0x4]
 *   @0x10734c sub r7, r7, #1
 *   @0x107350 str r7, [r6, #0x4]
 *   @0x107354 cmp r7, #0
 *   @0x107358 beq 0x1073e8 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x22c>
 *   @0x10735c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x107360 ldr r2, [sp, #0x14]
 *   @0x107364 mov r3, #0
 *   @0x107368 str r3, [r4]
 *   @0x10736c b 0x107278 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x107370 ldr r2, [sp, #0x8]
 *   @0x107374 cmp r2, #0
 *   @0x107378 str r2, [r4]
 *   @0x10737c beq 0x107300 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x107380 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x107384 ldr r1, [sp, #0x8]
 *   @0x107388 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x10738c ldr r3, [r4, #0xc]
 *   @0x107390 bic r3, r3, #-16777216
 *   @0x107394 b 0x107300 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x107398 ldr r2, [sp, #0x8]
 *   @0x10739c cmp r2, #0
 *   @0x1073a0 beq 0x1072fc <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x1073a4 ldr r3, [r2, #0x4]
 *   @0x1073a8 add r3, r3, #1
 *   @0x1073ac str r3, [r2, #0x4]
 *   @0x1073b0 ldr r3, [r4, #0xc]
 *   @0x1073b4 bic r3, r3, #-16777216
 *   @0x1073b8 b 0x1072fc <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x1073bc ldr r2, [sp, #0x8]
 *   @0x1073c0 cmp r2, #0
 *   @0x1073c4 str r2, [r4]
 *   @0x1073c8 beq 0x107300 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x1073cc ldr r0, [r2, #0x8]
 *   @0x1073d0 ldr r1, [r2]
 *   @0x1073d4 cmp r0, #0
 *   @0x1073d8 streq r4, [r2, #0x8]
 *   @0x1073dc add r1, r1, #1
 *   @0x1073e0 str r1, [r2]
 *   @0x1073e4 b 0x107300 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x1073e8 ldr r0, [r6]
 *   @0x1073ec bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1073f0 str r7, [r6]
 *   @0x1073f4 str r7, [r6, #0x8]
 *   @0x1073f8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1073fc ldr r7, [r6, #0x4]
 *   @0x107400 sub r7, r7, #1
 *   @0x107404 str r7, [r6, #0x4]
 *   @0x107408 cmp r7, #0
 *   @0x10740c beq 0x107430 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x274>
 *   @0x107410 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x107414 mov r0, r6
 *   @0x107418 bl 0x27d1d0 <_ZdlPv>
 *   @0x10741c b 0x10735c <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x1a0>
 *   @0x107420 mov r0, r4
 *   @0x107424 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x107428 ldr r2, [sp, #0x14]
 *   @0x10742c b 0x107278 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x107430 ldr r0, [r6]
 *   @0x107434 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x107438 str r7, [r6]
 *   @0x10743c str r7, [r6, #0x8]
 *   @0x107440 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x107444 ldr r7, [r6, #0x4]
 *   @0x107448 sub r7, r7, #1
 *   @0x10744c str r7, [r6, #0x4]
 *   @0x107450 cmp r7, #0
 *   @0x107454 beq 0x107468 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x2ac>
 *   @0x107458 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x10745c mov r0, r6
 *   @0x107460 bl 0x27d1d0 <_ZdlPv>
 *   @0x107464 b 0x107410 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x254>
 *   @0x107468 ldr r0, [r6]
 *   @0x10746c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x107470 str r7, [r6]
 *   @0x107474 str r7, [r6, #0x8]
 *   @0x107478 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x10747c ldr r3, [r6, #0x4]
 *   @0x107480 sub r3, r3, #1
 *   @0x107484 str r3, [r6, #0x4]
 *   @0x107488 cmp r3, #0
 *   @0x10748c bne 0x1074b4 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x2f8>
 *   @0x107490 ldr r0, [r6]
 *   @0x107494 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x107498 mov r3, #0
 *   @0x10749c mov r0, r6
 *   @0x1074a0 str r3, [r6]
 *   @0x1074a4 str r3, [r6, #0x8]
 *   @0x1074a8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x1074ac mov r0, r6
 *   @0x1074b0 bl 0x27d1d0 <_ZdlPv>
 *   @0x1074b4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1074b8 mov r0, r6
 *   @0x1074bc bl 0x27d1d0 <_ZdlPv>
 *   @0x1074c0 b 0x107458 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x29c>
 *   @0x1074c4 eoreq r6, lr, r8, lsl #21
 *   @0x1074c8 eoreq r6, lr, r8, lsr r7
 *   @0x1074cc eoreq r0, r3, r12, lsl r9
 *
 * ══ §12/39 F_DsMapFindFirst(RValue&, CInstance*, CInstance*, int, RValue*)  0x104394  size 784  196 条（0x104394..0x1046a4）
 * @func 0x104394 0x1046b4  size 800  200 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / DS_AutoMutex::~DS_AutoMutex()×2 / DS_AutoMutex::DS_AutoMutex() / YYGetInt32(RValue const*, int) / F_DsMapFindFirst(RValue&, CInstance*, CInstance*, int, RValue*)+0x118
 * 字段偏移 top8: 0x4×13 / 0x8×13 / 0xc×8 / 0x14×4 / 0x30×1 / 0x2cc×1 / 0x2bc×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x104394 push {r4, r5, r6, r7, lr}
 *   @0x104398 sub sp, sp, #28
 *   @0x10439c add r5, sp, #4
 *   @0x1043a0 mov r4, r0
 *   @0x1043a4 ldr r6, [sp, #0x30]
 *   @0x1043a8 mov r0, r5
 *   @0x1043ac bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0x1043b0 mov r1, #0
 *   @0x1043b4 mov r0, r6
 *   @0x1043b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1043bc cmp r0, #0
 *   @0x1043c0 blt 0x1044ac <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x1043c4 ldr r3, [pc, #0x2cc]
 *   @0x1043c8 ldr r3, [pc, r3]
 *   @0x1043cc ldr r3, [r3]
 *   @0x1043d0 cmp r0, r3
 *   @0x1043d4 bge 0x1044ac <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x1043d8 ldr r3, [pc, #0x2bc]
 *   @0x1043dc ldr r3, [pc, r3]
 *   @0x1043e0 ldr r3, [r3, #0x4]
 *   @0x1043e4 ldr r0, [r3, r0, lsl #2]
 *   @0x1043e8 cmp r0, #0
 *   @0x1043ec beq 0x1044ac <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x1043f0 bl 0x203c8c <_ZN7CDS_Map9FindFirstEv>
 *   @0x1043f4 subs r3, r0, #0
 *   @0x1043f8 beq 0x1044f8 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x164>
 *   @0x1043fc ldr r2, [r3, #0x8]
 *   @0x104400 add r12, sp, #8
 *   @0x104404 ldr r0, [r3]
 *   @0x104408 ldr r1, [r3, #0x4]
 *   @0x10440c ldr r6, [r4, #0xc]
 *   @0x104410 ldr r3, [r3, #0xc]
 *   @0x104414 bic lr, r6, #-16777216
 *   @0x104418 cmp lr, #1
 *   @0x10441c stm r12!, {r0, r1, r2, r3}
 *   @0x104420 ldr r2, [sp, #0x14]
 *   @0x104424 bic r2, r2, #-16777216
 *   @0x104428 str r2, [sp, #0x14]
 *   @0x10442c beq 0x10450c <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x178>
 *   @0x104430 cmp lr, #2
 *   @0x104434 bne 0x10444c <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x104438 sub r6, r6, #1
 *   @0x10443c bic r6, r6, #-16777216
 *   @0x104440 bic r6, r6, #3
 *   @0x104444 cmp r6, #0
 *   @0x104448 beq 0x1045f4 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x260>
 *   @0x10444c ldr r1, [sp, #0x10]
 *   @0x104450 bic r3, r2, #-16777216
 *   @0x104454 str r2, [r4, #0xc]
 *   @0x104458 mov r2, #0
 *   @0x10445c str r2, [r4]
 *   @0x104460 str r1, [r4, #0x8]
 *   @0x104464 cmp r3, #14
 *   @0x104468 addls pc, pc, r3, lsl #2
 *   @0x10446c b 0x1044d4 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x104470 b 0x1044e8 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x154>
 *   @0x104474 b 0x10456c <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x1d8>
 *   @0x104478 b 0x104590 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x1fc>
 *   @0x10447c b 0x1044cc <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x138>
 *   @0x104480 b 0x1044d4 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x104484 b 0x1044d4 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x104488 b 0x104544 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x1b0>
 *   @0x10448c b 0x1044cc <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x138>
 *   @0x104490 b 0x1044d4 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x104494 b 0x1044d4 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x104498 b 0x1044e8 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x154>
 *   @0x10449c b 0x1044d4 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x1044a0 b 0x1044d4 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x1044a4 b 0x1044e8 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x154>
 *   @0x1044a8 b 0x1044cc <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x138>
 *   @0x1044ac ldr r0, [pc, #0x1ec]
 *   @0x1044b0 mov r1, #0
 *   @0x1044b4 add r0, pc, r0
 *   @0x1044b8 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1044bc mov r0, r5
 *   @0x1044c0 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x1044c4 add sp, sp, #28
 *   @0x1044c8 pop {r4, r5, r6, r7, pc}
 *   @0x1044cc ldr r2, [sp, #0x8]
 *   @0x1044d0 str r2, [r4]
 *   @0x1044d4 str r3, [r4, #0xc]
 *   @0x1044d8 mov r0, r5
 *   @0x1044dc bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x1044e0 add sp, sp, #28
 *   @0x1044e4 pop {r4, r5, r6, r7, pc}
 *   @0x1044e8 ldr r1, [sp, #0x8]
 *   @0x1044ec ldr r2, [sp, #0xc]
 *   @0x1044f0 stm r4, {r1, r2}
 *   @0x1044f4 b 0x1044d4 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x1044f8 mov r2, #5
 *   @0x1044fc str r3, [r4]
 *   @0x104500 str r3, [r4, #0x4]
 *   @0x104504 str r2, [r4, #0xc]
 *   @0x104508 b 0x1044d8 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x10450c ldr r6, [r4]
 *   @0x104510 cmp r6, #0
 *   @0x104514 beq 0x104538 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x104518 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x10451c ldr r7, [r6, #0x4]
 *   @0x104520 sub r7, r7, #1
 *   @0x104524 str r7, [r6, #0x4]
 *   @0x104528 cmp r7, #0
 *   @0x10452c beq 0x1045bc <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x228>
 *   @0x104530 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x104534 ldr r2, [sp, #0x14]
 *   @0x104538 mov r3, #0
 *   @0x10453c str r3, [r4]
 *   @0x104540 b 0x10444c <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x104544 ldr r2, [sp, #0x8]
 *   @0x104548 cmp r2, #0
 *   @0x10454c str r2, [r4]
 *   @0x104550 beq 0x1044d4 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x104554 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x104558 ldr r1, [sp, #0x8]
 *   @0x10455c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x104560 ldr r3, [r4, #0xc]
 *   @0x104564 bic r3, r3, #-16777216
 *   @0x104568 b 0x1044d4 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x10456c ldr r2, [sp, #0x8]
 *   @0x104570 cmp r2, #0
 *   @0x104574 beq 0x1044d0 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x104578 ldr r3, [r2, #0x4]
 *   @0x10457c add r3, r3, #1
 *   @0x104580 str r3, [r2, #0x4]
 *   @0x104584 ldr r3, [r4, #0xc]
 *   @0x104588 bic r3, r3, #-16777216
 *   @0x10458c b 0x1044d0 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x104590 ldr r2, [sp, #0x8]
 *   @0x104594 cmp r2, #0
 *   @0x104598 str r2, [r4]
 *   @0x10459c beq 0x1044d4 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x1045a0 ldr r0, [r2, #0x8]
 *   @0x1045a4 ldr r1, [r2]
 *   @0x1045a8 cmp r0, #0
 *   @0x1045ac streq r4, [r2, #0x8]
 *   @0x1045b0 add r1, r1, #1
 *   @0x1045b4 str r1, [r2]
 *   @0x1045b8 b 0x1044d4 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x1045bc ldr r0, [r6]
 *   @0x1045c0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1045c4 str r7, [r6]
 *   @0x1045c8 str r7, [r6, #0x8]
 *   @0x1045cc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1045d0 ldr r7, [r6, #0x4]
 *   @0x1045d4 sub r7, r7, #1
 *   @0x1045d8 str r7, [r6, #0x4]
 *   @0x1045dc cmp r7, #0
 *   @0x1045e0 beq 0x104604 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x270>
 *   @0x1045e4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1045e8 mov r0, r6
 *   @0x1045ec bl 0x27d1d0 <_ZdlPv>
 *   @0x1045f0 b 0x104530 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x19c>
 *   @0x1045f4 mov r0, r4
 *   @0x1045f8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x1045fc ldr r2, [sp, #0x14]
 *   @0x104600 b 0x10444c <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x104604 ldr r0, [r6]
 *   @0x104608 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x10460c str r7, [r6]
 *   @0x104610 str r7, [r6, #0x8]
 *   @0x104614 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x104618 ldr r7, [r6, #0x4]
 *   @0x10461c sub r7, r7, #1
 *   @0x104620 str r7, [r6, #0x4]
 *   @0x104624 cmp r7, #0
 *   @0x104628 beq 0x10463c <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x2a8>
 *   @0x10462c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x104630 mov r0, r6
 *   @0x104634 bl 0x27d1d0 <_ZdlPv>
 *   @0x104638 b 0x1045e4 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x250>
 *   @0x10463c ldr r0, [r6]
 *   @0x104640 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x104644 str r7, [r6]
 *   @0x104648 str r7, [r6, #0x8]
 *   @0x10464c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x104650 ldr r3, [r6, #0x4]
 *   @0x104654 sub r3, r3, #1
 *   @0x104658 str r3, [r6, #0x4]
 *   @0x10465c cmp r3, #0
 *   @0x104660 bne 0x104688 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x2f4>
 *   @0x104664 ldr r0, [r6]
 *   @0x104668 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x10466c mov r3, #0
 *   @0x104670 mov r0, r6
 *   @0x104674 str r3, [r6]
 *   @0x104678 str r3, [r6, #0x8]
 *   @0x10467c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x104680 mov r0, r6
 *   @0x104684 bl 0x27d1d0 <_ZdlPv>
 *   @0x104688 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x10468c mov r0, r6
 *   @0x104690 bl 0x27d1d0 <_ZdlPv>
 *   @0x104694 b 0x10462c <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x298>
 *   @0x104698 .word 0x002e98b0
 *   @0x10469c eoreq r9, lr, r0, ror #10
 *   @0x1046a0 eoreq r3, r3, r8, asr #14
 *
 * ══ §13/39 F_DsMapFindLast(RValue&, CInstance*, CInstance*, int, RValue*)  0x1046a4  size 784  196 条（0x1046a4..0x1049b4）
 * @func 0x1046a4 0x1049b4  size 784  196 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / DS_AutoMutex::~DS_AutoMutex()×2 / DS_AutoMutex::DS_AutoMutex() / YYGetInt32(RValue const*, int) / F_DsMapFindLast(RValue&, CInstance*, CInstance*, int, RValue*)+0x118
 * 字段偏移 top8: 0x4×13 / 0x8×13 / 0xc×8 / 0x14×4 / 0x30×1 / 0x2cc×1 / 0x2bc×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1046a4 push {r4, r5, r6, r7, lr}
 *   @0x1046a8 sub sp, sp, #28
 *   @0x1046ac add r5, sp, #4
 *   @0x1046b0 mov r4, r0
 *   @0x1046b4 ldr r6, [sp, #0x30]
 *   @0x1046b8 mov r0, r5
 *   @0x1046bc bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0x1046c0 mov r1, #0
 *   @0x1046c4 mov r0, r6
 *   @0x1046c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1046cc cmp r0, #0
 *   @0x1046d0 blt 0x1047bc <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x1046d4 ldr r3, [pc, #0x2cc]
 *   @0x1046d8 ldr r3, [pc, r3]
 *   @0x1046dc ldr r3, [r3]
 *   @0x1046e0 cmp r0, r3
 *   @0x1046e4 bge 0x1047bc <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x1046e8 ldr r3, [pc, #0x2bc]
 *   @0x1046ec ldr r3, [pc, r3]
 *   @0x1046f0 ldr r3, [r3, #0x4]
 *   @0x1046f4 ldr r0, [r3, r0, lsl #2]
 *   @0x1046f8 cmp r0, #0
 *   @0x1046fc beq 0x1047bc <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x104700 bl 0x203cc4 <_ZN7CDS_Map8FindLastEv>
 *   @0x104704 subs r3, r0, #0
 *   @0x104708 beq 0x104808 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x164>
 *   @0x10470c ldr r2, [r3, #0x8]
 *   @0x104710 add r12, sp, #8
 *   @0x104714 ldr r0, [r3]
 *   @0x104718 ldr r1, [r3, #0x4]
 *   @0x10471c ldr r6, [r4, #0xc]
 *   @0x104720 ldr r3, [r3, #0xc]
 *   @0x104724 bic lr, r6, #-16777216
 *   @0x104728 cmp lr, #1
 *   @0x10472c stm r12!, {r0, r1, r2, r3}
 *   @0x104730 ldr r2, [sp, #0x14]
 *   @0x104734 bic r2, r2, #-16777216
 *   @0x104738 str r2, [sp, #0x14]
 *   @0x10473c beq 0x10481c <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x178>
 *   @0x104740 cmp lr, #2
 *   @0x104744 bne 0x10475c <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x104748 sub r6, r6, #1
 *   @0x10474c bic r6, r6, #-16777216
 *   @0x104750 bic r6, r6, #3
 *   @0x104754 cmp r6, #0
 *   @0x104758 beq 0x104904 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x260>
 *   @0x10475c ldr r1, [sp, #0x10]
 *   @0x104760 bic r3, r2, #-16777216
 *   @0x104764 str r2, [r4, #0xc]
 *   @0x104768 mov r2, #0
 *   @0x10476c str r2, [r4]
 *   @0x104770 str r1, [r4, #0x8]
 *   @0x104774 cmp r3, #14
 *   @0x104778 addls pc, pc, r3, lsl #2
 *   @0x10477c b 0x1047e4 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x104780 b 0x1047f8 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x154>
 *   @0x104784 b 0x10487c <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x1d8>
 *   @0x104788 b 0x1048a0 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x1fc>
 *   @0x10478c b 0x1047dc <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x138>
 *   @0x104790 b 0x1047e4 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x104794 b 0x1047e4 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x104798 b 0x104854 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x1b0>
 *   @0x10479c b 0x1047dc <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x138>
 *   @0x1047a0 b 0x1047e4 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x1047a4 b 0x1047e4 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x1047a8 b 0x1047f8 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x154>
 *   @0x1047ac b 0x1047e4 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x1047b0 b 0x1047e4 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x1047b4 b 0x1047f8 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x154>
 *   @0x1047b8 b 0x1047dc <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x138>
 *   @0x1047bc ldr r0, [pc, #0x1ec]
 *   @0x1047c0 mov r1, #0
 *   @0x1047c4 add r0, pc, r0
 *   @0x1047c8 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1047cc mov r0, r5
 *   @0x1047d0 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x1047d4 add sp, sp, #28
 *   @0x1047d8 pop {r4, r5, r6, r7, pc}
 *   @0x1047dc ldr r2, [sp, #0x8]
 *   @0x1047e0 str r2, [r4]
 *   @0x1047e4 str r3, [r4, #0xc]
 *   @0x1047e8 mov r0, r5
 *   @0x1047ec bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x1047f0 add sp, sp, #28
 *   @0x1047f4 pop {r4, r5, r6, r7, pc}
 *   @0x1047f8 ldr r1, [sp, #0x8]
 *   @0x1047fc ldr r2, [sp, #0xc]
 *   @0x104800 stm r4, {r1, r2}
 *   @0x104804 b 0x1047e4 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x104808 mov r2, #5
 *   @0x10480c str r3, [r4]
 *   @0x104810 str r3, [r4, #0x4]
 *   @0x104814 str r2, [r4, #0xc]
 *   @0x104818 b 0x1047e8 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x10481c ldr r6, [r4]
 *   @0x104820 cmp r6, #0
 *   @0x104824 beq 0x104848 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x104828 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x10482c ldr r7, [r6, #0x4]
 *   @0x104830 sub r7, r7, #1
 *   @0x104834 str r7, [r6, #0x4]
 *   @0x104838 cmp r7, #0
 *   @0x10483c beq 0x1048cc <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x228>
 *   @0x104840 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x104844 ldr r2, [sp, #0x14]
 *   @0x104848 mov r3, #0
 *   @0x10484c str r3, [r4]
 *   @0x104850 b 0x10475c <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x104854 ldr r2, [sp, #0x8]
 *   @0x104858 cmp r2, #0
 *   @0x10485c str r2, [r4]
 *   @0x104860 beq 0x1047e4 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x104864 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x104868 ldr r1, [sp, #0x8]
 *   @0x10486c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x104870 ldr r3, [r4, #0xc]
 *   @0x104874 bic r3, r3, #-16777216
 *   @0x104878 b 0x1047e4 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x10487c ldr r2, [sp, #0x8]
 *   @0x104880 cmp r2, #0
 *   @0x104884 beq 0x1047e0 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x104888 ldr r3, [r2, #0x4]
 *   @0x10488c add r3, r3, #1
 *   @0x104890 str r3, [r2, #0x4]
 *   @0x104894 ldr r3, [r4, #0xc]
 *   @0x104898 bic r3, r3, #-16777216
 *   @0x10489c b 0x1047e0 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x1048a0 ldr r2, [sp, #0x8]
 *   @0x1048a4 cmp r2, #0
 *   @0x1048a8 str r2, [r4]
 *   @0x1048ac beq 0x1047e4 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x1048b0 ldr r0, [r2, #0x8]
 *   @0x1048b4 ldr r1, [r2]
 *   @0x1048b8 cmp r0, #0
 *   @0x1048bc streq r4, [r2, #0x8]
 *   @0x1048c0 add r1, r1, #1
 *   @0x1048c4 str r1, [r2]
 *   @0x1048c8 b 0x1047e4 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x1048cc ldr r0, [r6]
 *   @0x1048d0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1048d4 str r7, [r6]
 *   @0x1048d8 str r7, [r6, #0x8]
 *   @0x1048dc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1048e0 ldr r7, [r6, #0x4]
 *   @0x1048e4 sub r7, r7, #1
 *   @0x1048e8 str r7, [r6, #0x4]
 *   @0x1048ec cmp r7, #0
 *   @0x1048f0 beq 0x104914 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x270>
 *   @0x1048f4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1048f8 mov r0, r6
 *   @0x1048fc bl 0x27d1d0 <_ZdlPv>
 *   @0x104900 b 0x104840 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x19c>
 *   @0x104904 mov r0, r4
 *   @0x104908 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x10490c ldr r2, [sp, #0x14]
 *   @0x104910 b 0x10475c <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x104914 ldr r0, [r6]
 *   @0x104918 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x10491c str r7, [r6]
 *   @0x104920 str r7, [r6, #0x8]
 *   @0x104924 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x104928 ldr r7, [r6, #0x4]
 *   @0x10492c sub r7, r7, #1
 *   @0x104930 str r7, [r6, #0x4]
 *   @0x104934 cmp r7, #0
 *   @0x104938 beq 0x10494c <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x2a8>
 *   @0x10493c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x104940 mov r0, r6
 *   @0x104944 bl 0x27d1d0 <_ZdlPv>
 *   @0x104948 b 0x1048f4 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x250>
 *   @0x10494c ldr r0, [r6]
 *   @0x104950 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x104954 str r7, [r6]
 *   @0x104958 str r7, [r6, #0x8]
 *   @0x10495c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x104960 ldr r3, [r6, #0x4]
 *   @0x104964 sub r3, r3, #1
 *   @0x104968 str r3, [r6, #0x4]
 *   @0x10496c cmp r3, #0
 *   @0x104970 bne 0x104998 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x2f4>
 *   @0x104974 ldr r0, [r6]
 *   @0x104978 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x10497c mov r3, #0
 *   @0x104980 mov r0, r6
 *   @0x104984 str r3, [r6]
 *   @0x104988 str r3, [r6, #0x8]
 *   @0x10498c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x104990 mov r0, r6
 *   @0x104994 bl 0x27d1d0 <_ZdlPv>
 *   @0x104998 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x10499c mov r0, r6
 *   @0x1049a0 bl 0x27d1d0 <_ZdlPv>
 *   @0x1049a4 b 0x10493c <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x298>
 *   @0x1049a8 eoreq r9, lr, r0, lsr #11
 *   @0x1049ac eoreq r9, lr, r0, asr r2
 *   @0x1049b0 eoreq r3, r3, r8, lsr r4
 *
 * ══ §14/39 spBone_updateLocalTransform  0x285688  size 780  195 条（0x285688..0x285994）
 * @func 0x285688 0x285994  size 780  195 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6c70×5 / 0xb66f4×4
 * 字段偏移 top8: 0x28×2 / 0x8×1 / 0x20×1 / 0x2c×1 / 0x3c×1 / 0x48×1 / 0x14×1 / 0x18×1
 * VFP 指令 154 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x285688 ldr r3, [r0, #0x8]
 *   @0x28568c push {r4, lr}
 *   @0x285690 vpush {d8, d9, d10}
 *   @0x285694 cmp r3, #0
 *   @0x285698 mov r4, r0
 *   @0x28569c beq 0x285850 <spBone_updateLocalTransform+0x1c8>
 *   @0x2856a0 vldr s9, [r3, #56]
 *   @0x2856a4 vldr s10, [r3, #64]
 *   @0x2856a8 vmul.f32 s15, s9, s10
 *   @0x2856ac vldr s7, [r3, #52]
 *   @0x2856b0 vldr s8, [r3, #68]
 *   @0x2856b4 vldr s14, [r0, #52]
 *   @0x2856b8 vldr s17, [r0, #64]
 *   @0x2856bc vldr s1, [r3, #72]
 *   @0x2856c0 vldr s2, [r3, #60]
 *   @0x2856c4 vldr s20, [r0, #72]
 *   @0x2856c8 vldr s0, [r0, #60]
 *   @0x2856cc vldr s6, [r0, #68]
 *   @0x2856d0 vldr s3, [r0, #56]
 *   @0x2856d4 mov r3, #0
 *   @0x2856d8 str r3, [r0, #0x28]
 *   @0x2856dc vnmls.f32 s15, s7, s8
 *   @0x2856e0 vmov.f32 s11, #1.000000e+00
 *   @0x2856e4 vdiv.f32 s11, s11, s15
 *   @0x2856e8 vmul.f32 s19, s11, s10
 *   @0x2856ec vmul.f32 s18, s11, s9
 *   @0x2856f0 vmul.f32 s5, s11, s7
 *   @0x2856f4 vmul.f32 s16, s19, s14
 *   @0x2856f8 vmul.f32 s4, s11, s8
 *   @0x2856fc vnmls.f32 s16, s5, s17
 *   @0x285700 vmul.f32 s17, s17, s18
 *   @0x285704 vnmls.f32 s17, s14, s4
 *   @0x285708 vmul.f32 s12, s16, s16
 *   @0x28570c vmla.f32 s12, s17, s17
 *   @0x285710 vcvt.f64.f32 d6, s12
 *   @0x285714 vsqrt.f64 d7, d6
 *   @0x285718 vsub.f32 s1, s20, s1
 *   @0x28571c vsub.f32 s2, s0, s2
 *   @0x285720 vmul.f32 s9, s1, s9
 *   @0x285724 vmul.f32 s10, s2, s10
 *   @0x285728 vmul.f32 s9, s9, s11
 *   @0x28572c vmul.f32 s7, s1, s7
 *   @0x285730 vmul.f32 s8, s2, s8
 *   @0x285734 vmul.f32 s10, s10, s11
 *   @0x285738 vnmls.f32 s9, s8, s11
 *   @0x28573c vnmls.f32 s10, s7, s11
 *   @0x285740 vstr s9, [r0, #20]
 *   @0x285744 vmul.f32 s18, s6, s18
 *   @0x285748 vstr s10, [r0, #24]
 *   @0x28574c vmul.f32 s19, s19, s3
 *   @0x285750 vcmp.f64 d7, d7
 *   @0x285754 vnmls.f32 s18, s3, s4
 *   @0x285758 vmrs APSR_nzcv, fpscr
 *   @0x28575c vnmls.f32 s19, s5, s6
 *   @0x285760 bne 0x285940 <spBone_updateLocalTransform+0x2b8>
 *   @0x285764 vcvt.f32.f64 s14, d7
 *   @0x285768 vldr s15, [pc, #536]
 *   @0x28576c vcmpe.f32 s14, s15
 *   @0x285770 vstr s14, [r4, #32]
 *   @0x285774 vmrs APSR_nzcv, fpscr
 *   @0x285778 bgt 0x2857e8 <spBone_updateLocalTransform+0x160>
 *   @0x28577c vmul.f32 s12, s19, s19
 *   @0x285780 mov r3, #0
 *   @0x285784 str r3, [r4, #0x20]
 *   @0x285788 vmla.f32 s12, s18, s18
 *   @0x28578c vcvt.f64.f32 d6, s12
 *   @0x285790 vsqrt.f64 d7, d6
 *   @0x285794 vcmp.f64 d7, d7
 *   @0x285798 vmrs APSR_nzcv, fpscr
 *   @0x28579c bne 0x285950 <spBone_updateLocalTransform+0x2c8>
 *   @0x2857a0 vcvt.f32.f64 s14, d7
 *   @0x2857a4 mov r3, #0
 *   @0x2857a8 str r3, [r4, #0x2c]
 *   @0x2857ac vstr s14, [r4, #36]
 *   @0x2857b0 vcvt.f64.f32 d4, s18
 *   @0x2857b4 vcvt.f64.f32 d7, s19
 *   @0x2857b8 vmov r2, r3, d4
 *   @0x2857bc vmov r0, r1, d7
 *   @0x2857c0 bl 0xb6c70 <atan2@plt>
 *   @0x2857c4 vldr s14, [pc, #448]
 *   @0x2857c8 vldr s15, [pc, #448]
 *   @0x2857cc vmov d5, r0, r1
 *   @0x2857d0 vcvt.f32.f64 s13, d5
 *   @0x2857d4 vmls.f32 s15, s13, s14
 *   @0x2857d8 vstr s15, [r4, #28]
 *   @0x2857dc vpop {d8, d9, d10}
 *   @0x2857e0 vstr s15, [r4, #48]
 *   @0x2857e4 pop {r4, pc}
 *   @0x2857e8 vmul.f32 s13, s18, s16
 *   @0x2857ec vldr s20, [pc, #408]
 *   @0x2857f0 vnmls.f32 s13, s17, s19
 *   @0x2857f4 vmul.f32 s19, s16, s19
 *   @0x2857f8 vdiv.f32 s14, s13, s14
 *   @0x2857fc vmla.f32 s19, s17, s18
 *   @0x285800 vstr s14, [r4, #36]
 *   @0x285804 vcvt.f64.f32 d5, s13
 *   @0x285808 vcvt.f64.f32 d6, s19
 *   @0x28580c vmov r2, r3, d5
 *   @0x285810 vmov r0, r1, d6
 *   @0x285814 bl 0xb6c70 <atan2@plt>
 *   @0x285818 vcvt.f64.f32 d7, s17
 *   @0x28581c vmov r2, r3, d7
 *   @0x285820 vcvt.f64.f32 d5, s16
 *   @0x285824 vmov d4, r0, r1
 *   @0x285828 vcvt.f32.f64 s15, d4
 *   @0x28582c vmov r0, r1, d5
 *   @0x285830 vmul.f32 s15, s15, s20
 *   @0x285834 vstr s15, [r4, #44]
 *   @0x285838 bl 0xb6c70 <atan2@plt>
 *   @0x28583c vmov d6, r0, r1
 *   @0x285840 vcvt.f32.f64 s15, d6
 *   @0x285844 vmul.f32 s15, s15, s20
 *   @0x285848 vstr s15, [r4, #28]
 *   @0x28584c b 0x2857dc <spBone_updateLocalTransform+0x154>
 *   @0x285850 vldr s14, [r0, #64]
 *   @0x285854 vldr s16, [r0, #56]
 *   @0x285858 vmul.f32 s16, s14, s16
 *   @0x28585c vldr s15, [r0, #52]
 *   @0x285860 ldr r2, [r0, #0x3c]
 *   @0x285864 vldr s13, [r0, #68]
 *   @0x285868 ldr r3, [r0, #0x48]
 *   @0x28586c str r2, [r0, #0x14]
 *   @0x285870 str r3, [r0, #0x18]
 *   @0x285874 vcvt.f64.f32 d5, s15
 *   @0x285878 vcvt.f64.f32 d4, s14
 *   @0x28587c vmov r2, r3, d5
 *   @0x285880 vmov r0, r1, d4
 *   @0x285884 vnmls.f32 s16, s15, s13
 *   @0x285888 bl 0xb6c70 <atan2@plt>
 *   @0x28588c vldr s14, [r4, #64]
 *   @0x285890 vldr s15, [r4, #52]
 *   @0x285894 vldr s11, [pc, #240]
 *   @0x285898 vmul.f32 s14, s14, s14
 *   @0x28589c vmov d4, r0, r1
 *   @0x2858a0 vmla.f32 s14, s15, s15
 *   @0x2858a4 vcvt.f64.f32 d7, s14
 *   @0x2858a8 vsqrt.f64 d6, d7
 *   @0x2858ac vcvt.f32.f64 s10, d4
 *   @0x2858b0 vmul.f32 s11, s10, s11
 *   @0x2858b4 vcmp.f64 d6, d6
 *   @0x2858b8 vstr s11, [r4, #28]
 *   @0x2858bc vmrs APSR_nzcv, fpscr
 *   @0x2858c0 bne 0x285978 <spBone_updateLocalTransform+0x2f0>
 *   @0x2858c4 vldr s8, [r4, #68]
 *   @0x2858c8 vmul.f32 s10, s8, s8
 *   @0x2858cc vldr s9, [r4, #56]
 *   @0x2858d0 vmla.f32 s10, s9, s9
 *   @0x2858d4 vcvt.f64.f32 d5, s10
 *   @0x2858d8 vsqrt.f64 d7, d5
 *   @0x2858dc vcvt.f32.f64 s12, d6
 *   @0x2858e0 vcmp.f64 d7, d7
 *   @0x2858e4 vstr s12, [r4, #32]
 *   @0x2858e8 vmrs APSR_nzcv, fpscr
 *   @0x2858ec bne 0x285960 <spBone_updateLocalTransform+0x2d8>
 *   @0x2858f0 vldr s13, [r4, #64]
 *   @0x2858f4 vmul.f32 s8, s13, s8
 *   @0x2858f8 vldr s13, [r4, #52]
 *   @0x2858fc mov r3, #0
 *   @0x285900 str r3, [r4, #0x28]
 *   @0x285904 vmla.f32 s8, s13, s9
 *   @0x285908 vcvt.f32.f64 s14, d7
 *   @0x28590c vcvt.f64.f32 d5, s8
 *   @0x285910 vstr s14, [r4, #36]
 *   @0x285914 vcvt.f64.f32 d6, s16
 *   @0x285918 vmov r0, r1, d5
 *   @0x28591c vmov r2, r3, d6
 *   @0x285920 bl 0xb6c70 <atan2@plt>
 *   @0x285924 vldr s15, [pc, #96]
 *   @0x285928 vpop {d8, d9, d10}
 *   @0x28592c vmov d4, r0, r1
 *   @0x285930 vcvt.f32.f64 s14, d4
 *   @0x285934 vmul.f32 s15, s14, s15
 *   @0x285938 vstr s15, [r4, #44]
 *   @0x28593c pop {r4, pc}
 *   @0x285940 vmov r0, r1, d6
 *   @0x285944 bl 0xb66f4 <sqrt@plt>
 *   @0x285948 vmov d7, r0, r1
 *   @0x28594c b 0x285764 <spBone_updateLocalTransform+0xdc>
 *   @0x285950 vmov r0, r1, d6
 *   @0x285954 bl 0xb66f4 <sqrt@plt>
 *   @0x285958 vmov d7, r0, r1
 *   @0x28595c b 0x2857a0 <spBone_updateLocalTransform+0x118>
 *   @0x285960 vmov r0, r1, d5
 *   @0x285964 bl 0xb66f4 <sqrt@plt>
 *   @0x285968 vldr s8, [r4, #68]
 *   @0x28596c vldr s9, [r4, #56]
 *   @0x285970 vmov d7, r0, r1
 *   @0x285974 b 0x2858f0 <spBone_updateLocalTransform+0x268>
 *   @0x285978 vmov r0, r1, d7
 *   @0x28597c bl 0xb66f4 <sqrt@plt>
 *   @0x285980 vmov d6, r0, r1
 *   @0x285984 b 0x2858c4 <spBone_updateLocalTransform+0x23c>
 *   @0x285988 ldmlo r1, {r0, r1, r2, r4, r8, r9, r10, r12, sp, pc} ^
 *   @0x28598c rsbmi r2, r5, #224, #28
 *   @0x285990 adcsmi r0, r4, #0
 *
 * ══ §15/39 Extension_Load(unsigned char*, unsigned int, unsigned char*)  0xf5eb8  size 776  194 条（0xf5eb8..0xf61c0）
 * @func 0xf5eb8 0xf61c0  size 776  194 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::SetLength(void**, unsigned int, char const*, int) / operator new(unsigned int) / CExtensionPackage::CExtensionPackage() / CExtensionPackage::SetFolder(char const*) / CExtensionPackage::SetName(char const*) / CExtensionPackage::SetClassName(char const*) / CExtensionPackage::SetIncludesCount(int) / Extension_Load(unsigned char*, unsigned int, unsigned char*)+0x2d0
 * 字段偏移 top8: 0x4×13 / 0x14×9 / 0x8×7 / 0xc×6 / 0x18×5 / 0x10×5 / 0x1c×4 / 0x20×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf5eb8 ldr r1, [r0]
 *   @0xf5ebc mov r3, #246
 *   @0xf5ec0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xf5ec4 sub sp, sp, #44
 *   @0xf5ec8 mov r4, r0
 *   @0xf5ecc ldr r0, [pc, #0x2d8]
 *   @0xf5ed0 str r1, [sp, #0x1c]
 *   @0xf5ed4 lsl r1, r1, #2
 *   @0xf5ed8 ldr lr, [sp, #0x1c]
 *   @0xf5edc add r0, pc, r0
 *   @0xf5ee0 ldr r12, [pc, #0x2c8]
 *   @0xf5ee4 ldr r2, [pc, #0x2c8]
 *   @0xf5ee8 ldr r12, [pc, r12]
 *   @0xf5eec str lr, [r0], #4
 *   @0xf5ef0 add r2, pc, r2
 *   @0xf5ef4 str lr, [r12]
 *   @0xf5ef8 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xf5efc ldr r12, [sp, #0x1c]
 *   @0xf5f00 cmp r12, #0
 *   @0xf5f04 beq 0xf61a0 <_Z14Extension_LoadPhjS_+0x2e8>
 *   @0xf5f08 ldr r3, [pc, #0x2a8]
 *   @0xf5f0c mov r12, #0
 *   @0xf5f10 str r4, [sp, #0x20]
 *   @0xf5f14 add r3, pc, r3
 *   @0xf5f18 str r12, [sp, #0x18]
 *   @0xf5f1c str r3, [sp, #0x24]
 *   @0xf5f20 ldr r3, [sp, #0x20]
 *   @0xf5f24 ldr r5, [r3, #0x4]!
 *   @0xf5f28 cmp r5, #0
 *   @0xf5f2c str r3, [sp, #0x20]
 *   @0xf5f30 beq 0xf6188 <_Z14Extension_LoadPhjS_+0x2d0>
 *   @0xf5f34 ldr r9, [pc, #0x280]
 *   @0xf5f38 ldr r9, [pc, r9]
 *   @0xf5f3c ldr r6, [r9]
 *   @0xf5f40 adds r4, r6, r5
 *   @0xf5f44 beq 0xf6188 <_Z14Extension_LoadPhjS_+0x2d0>
 *   @0xf5f48 mov r0, #28
 *   @0xf5f4c bl 0x27c524 <_Znwj>
 *   @0xf5f50 mov r7, r0
 *   @0xf5f54 bl 0xf56c8 <_ZN17CExtensionPackageC2Ev>
 *   @0xf5f58 ldr r3, [sp, #0x24]
 *   @0xf5f5c ldr r12, [sp, #0x18]
 *   @0xf5f60 ldr r2, [r3, #0x4]
 *   @0xf5f64 ldr r3, [r6, r5]
 *   @0xf5f68 str r7, [r2, r12, lsl #2]
 *   @0xf5f6c cmp r3, #0
 *   @0xf5f70 ldr r12, [sp, #0x24]
 *   @0xf5f74 moveq r1, r3
 *   @0xf5f78 ldr r2, [r12, #0x4]
 *   @0xf5f7c ldr r12, [sp, #0x18]
 *   @0xf5f80 ldr r2, [r2, r12, lsl #2]
 *   @0xf5f84 str r2, [sp, #0x14]
 *   @0xf5f88 ldrne r2, [r9]
 *   @0xf5f8c ldr r0, [sp, #0x14]
 *   @0xf5f90 addne r1, r2, r3
 *   @0xf5f94 bl 0xf5604 <_ZN17CExtensionPackage9SetFolderEPKc>
 *   @0xf5f98 ldr r3, [r4, #0x4]
 *   @0xf5f9c ldr r0, [sp, #0x14]
 *   @0xf5fa0 cmp r3, #0
 *   @0xf5fa4 ldrne r2, [r9]
 *   @0xf5fa8 moveq r1, r3
 *   @0xf5fac addne r1, r2, r3
 *   @0xf5fb0 bl 0xf559c <_ZN17CExtensionPackage7SetNameEPKc>
 *   @0xf5fb4 ldr r3, [r4, #0x8]
 *   @0xf5fb8 ldr r0, [sp, #0x14]
 *   @0xf5fbc cmp r3, #0
 *   @0xf5fc0 ldrne r2, [r9]
 *   @0xf5fc4 moveq r1, r3
 *   @0xf5fc8 addne r1, r2, r3
 *   @0xf5fcc bl 0xf55d0 <_ZN17CExtensionPackage12SetClassNameEPKc>
 *   @0xf5fd0 ldr r3, [r4, #0xc]
 *   @0xf5fd4 ldr r0, [sp, #0x14]
 *   @0xf5fd8 mov r1, r3
 *   @0xf5fdc str r3, [sp, #0x10]
 *   @0xf5fe0 bl 0xf5638 <_ZN17CExtensionPackage16SetIncludesCountEi>
 *   @0xf5fe4 ldr r12, [sp, #0x10]
 *   @0xf5fe8 cmp r12, #0
 *   @0xf5fec ble 0xf6188 <_Z14Extension_LoadPhjS_+0x2d0>
 *   @0xf5ff0 add r4, r4, #12
 *   @0xf5ff4 mov r3, #0
 *   @0xf5ff8 str r4, [sp, #0xc]
 *   @0xf5ffc str r3, [sp, #0x8]
 *   @0xf6000 ldr r12, [sp, #0xc]
 *   @0xf6004 ldr r4, [r12, #0x4]!
 *   @0xf6008 cmp r4, #0
 *   @0xf600c str r12, [sp, #0xc]
 *   @0xf6010 beq 0xf6170 <_Z14Extension_LoadPhjS_+0x2b8>
 *   @0xf6014 ldr r5, [r9]
 *   @0xf6018 adds r7, r5, r4
 *   @0xf601c beq 0xf6170 <_Z14Extension_LoadPhjS_+0x2b8>
 *   @0xf6020 ldr r1, [sp, #0x8]
 *   @0xf6024 ldr r0, [sp, #0x14]
 *   @0xf6028 bl 0xf5800 <_ZN17CExtensionPackage15GetIncludesFileEi>
 *   @0xf602c ldr r1, [r5, r4]
 *   @0xf6030 cmp r1, #0
 *   @0xf6034 ldrne r3, [r9]
 *   @0xf6038 addne r1, r3, r1
 *   @0xf603c mov r10, r0
 *   @0xf6040 bl 0xf4fb4 <_ZN14CExtensionFile11SetFileNameEPKc>
 *   @0xf6044 ldr r1, [r7, #0x4]
 *   @0xf6048 mov r0, r10
 *   @0xf604c cmp r1, #0
 *   @0xf6050 ldrne r3, [r9]
 *   @0xf6054 addne r1, r3, r1
 *   @0xf6058 bl 0xf5018 <_ZN14CExtensionFile17SetFunction_FinalEPKc>
 *   @0xf605c ldr r1, [r7, #0x8]
 *   @0xf6060 mov r0, r10
 *   @0xf6064 cmp r1, #0
 *   @0xf6068 ldrne r3, [r9]
 *   @0xf606c addne r1, r3, r1
 *   @0xf6070 bl 0xf4ff8 <_ZN14CExtensionFile16SetFunction_InitEPKc>
 *   @0xf6074 mov r0, r10
 *   @0xf6078 ldr r1, [r7, #0xc]
 *   @0xf607c bl 0xf4fe8 <_ZN14CExtensionFile7SetKindEi>
 *   @0xf6080 ldr r3, [r7, #0x10]
 *   @0xf6084 mov r0, r10
 *   @0xf6088 mov r1, r3
 *   @0xf608c str r3, [sp, #0x4]
 *   @0xf6090 bl 0xf504c <_ZN14CExtensionFile17SetFunctionsCountEi>
 *   @0xf6094 ldr r12, [sp, #0x4]
 *   @0xf6098 cmp r12, #0
 *   @0xf609c ble 0xf6170 <_Z14Extension_LoadPhjS_+0x2b8>
 *   @0xf60a0 add r7, r7, #16
 *   @0xf60a4 mov r6, #0
 *   @0xf60a8 mov r1, r6
 *   @0xf60ac mov r0, r10
 *   @0xf60b0 bl 0xf5050 <_ZN14CExtensionFile16GetFunctionsDataEi>
 *   @0xf60b4 ldr r5, [r7, #0x4]!
 *   @0xf60b8 cmp r5, #0
 *   @0xf60bc ldrne r3, [r9]
 *   @0xf60c0 moveq r4, #24
 *   @0xf60c4 addne r5, r3, r5
 *   @0xf60c8 mov r8, r0
 *   @0xf60cc addne r4, r5, #24
 *   @0xf60d0 ldr r1, [r5]
 *   @0xf60d4 cmp r1, #0
 *   @0xf60d8 ldrne r3, [r9]
 *   @0xf60dc addne r1, r3, r1
 *   @0xf60e0 bl 0xf4bb8 <_ZN18CExtensionFunction7SetNameEPKc>
 *   @0xf60e4 mov r0, r8
 *   @0xf60e8 ldr r1, [r5, #0x4]
 *   @0xf60ec bl 0xf4c30 <_ZN18CExtensionFunction5SetIdEi>
 *   @0xf60f0 mov r0, r8
 *   @0xf60f4 ldr r1, [r5, #0x8]
 *   @0xf60f8 bl 0xf4c20 <_ZN18CExtensionFunction7SetKindEi>
 *   @0xf60fc mov r0, r8
 *   @0xf6100 ldr r1, [r5, #0xc]
 *   @0xf6104 bl 0xf4c50 <_ZN18CExtensionFunction13SetReturnTypeEi>
 *   @0xf6108 ldr r1, [r5, #0x10]
 *   @0xf610c mov r0, r8
 *   @0xf6110 cmp r1, #0
 *   @0xf6114 ldrne r3, [r9]
 *   @0xf6118 addne r1, r3, r1
 *   @0xf611c bl 0xf4bec <_ZN18CExtensionFunction15SetExternalNameEPKc>
 *   @0xf6120 mov r0, r8
 *   @0xf6124 ldr r1, [r5, #0x14]
 *   @0xf6128 bl 0xf4c40 <_ZN18CExtensionFunction11SetArgCountEi>
 *   @0xf612c ldr r3, [r5, #0x14]
 *   @0xf6130 cmp r3, #0
 *   @0xf6134 subgt r11, r4, #4
 *   @0xf6138 movgt r4, #0
 *   @0xf613c ble 0xf6160 <_Z14Extension_LoadPhjS_+0x2a8>
 *   @0xf6140 mov r1, r4
 *   @0xf6144 mov r0, r8
 *   @0xf6148 ldr r2, [r11, #0x4]!
 *   @0xf614c add r4, r4, #1
 *   @0xf6150 bl 0xf4988 <_ZN18CExtensionFunction10SetArgTypeEii>
 *   @0xf6154 ldr r3, [r5, #0x14]
 *   @0xf6158 cmp r3, r4
 *   @0xf615c bgt 0xf6140 <_Z14Extension_LoadPhjS_+0x288>
 *   @0xf6160 ldr r3, [sp, #0x4]
 *   @0xf6164 add r6, r6, #1
 *   @0xf6168 cmp r3, r6
 *   @0xf616c bne 0xf60a8 <_Z14Extension_LoadPhjS_+0x1f0>
 *   @0xf6170 ldr r3, [sp, #0x8]
 *   @0xf6174 ldr r12, [sp, #0x10]
 *   @0xf6178 add r3, r3, #1
 *   @0xf617c str r3, [sp, #0x8]
 *   @0xf6180 cmp r12, r3
 *   @0xf6184 bne 0xf6000 <_Z14Extension_LoadPhjS_+0x148>
 *   @0xf6188 ldr r12, [sp, #0x18]
 *   @0xf618c ldr r1, [sp, #0x1c]
 *   @0xf6190 add r12, r12, #1
 *   @0xf6194 str r12, [sp, #0x18]
 *   @0xf6198 cmp r12, r1
 *   @0xf619c bne 0xf5f20 <_Z14Extension_LoadPhjS_+0x68>
 *   @0xf61a0 mov r0, #0
 *   @0xf61a4 add sp, sp, #44
 *   @0xf61a8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xf61ac eorseq sp, r8, r12, ror #14
 *   @0xf61b0 eoreq r7, pc, r12, asr #30
 *   @0xf61b4 eoreq r1, r4, r8, ror r10
 *   @0xf61b8 eorseq sp, r8, r4, lsr r7
 *   @0xf61bc eoreq r7, pc, r12, lsl #20
 *
 * ══ §16/39 F_ActionSetCaption(RValue&, CInstance*, CInstance*, int, RValue*)  0x14319c  size 776  194 条（0x14319c..0x1434a4）
 * @func 0x14319c 0x1434a4  size 776  194 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1431ac→0x542948, 0x1431c8→0x542949, 0x1431cc→0x542944, 0x143258→0x54293c, 0x14325c→0x542938, 0x1432e8→0x542928, 0x1432ec→0x542924
 * 调用序列: operator delete(void*)×9 / LOCK_RVALUE_MUTEX()×6 / UNLOCK_RVALUE_MUTEX()×6 / YYFree(void const*)×6 / YYGetBool(RValue const*, int)×3 / YYGetString(RValue const*, int)×3 / operator new(unsigned int)×3 / 0xb6538×3
 * 字段偏移 top8: 0x4×12 / 0x8×9 / 0x2bc×2 / 0x234×2 / 0x1ac×2 / 0x2d8×1 / 0x2d4×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14319c push {r4, r5, r6, r7, r8, lr}
 *   @0x1431a0 mov r1, #0
 *   @0x1431a4 ldr r4, [pc, #0x2d8]
 *   @0x1431a8 mov r2, #1
 *   @0x1431ac ldr r3, [pc, #0x2d4]
 *   @0x1431b0 add r4, pc, r4
 *   @0x1431b4 ldr r5, [sp, #0x18]
 *   @0x1431b8 ldr r3, [r4, r3]
 *   @0x1431bc mov r0, r5
 *   @0x1431c0 strb r2, [r3]
 *   @0x1431c4 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x1431c8 ldr r2, [pc, #0x2bc]
 *   @0x1431cc ldr r3, [pc, #0x2bc]
 *   @0x1431d0 ldr r2, [r4, r2]
 *   @0x1431d4 strb r0, [r2]
 *   @0x1431d8 ldr r8, [r4, r3]
 *   @0x1431dc ldr r6, [r8]
 *   @0x1431e0 cmp r6, #0
 *   @0x1431e4 beq 0x14320c <_Z18F_ActionSetCaptionR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x1431e8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1431ec ldr r7, [r6, #0x4]
 *   @0x1431f0 sub r7, r7, #1
 *   @0x1431f4 str r7, [r6, #0x4]
 *   @0x1431f8 cmp r7, #0
 *   @0x1431fc beq 0x1433e0 <_Z18F_ActionSetCaptionR6RValueP9CInstanceS2_iPS_+0x244>
 *   @0x143200 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x143204 mov r0, r6
 *   @0x143208 bl 0x27d1d0 <_ZdlPv>
 *   @0x14320c mov r1, #1
 *   @0x143210 mov r0, r5
 *   @0x143214 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x143218 mov r7, r0
 *   @0x14321c mov r0, #12
 *   @0x143220 bl 0x27c524 <_Znwj>
 *   @0x143224 mov r6, r0
 *   @0x143228 subs r0, r7, #0
 *   @0x14322c beq 0x143234 <_Z18F_ActionSetCaptionR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x143230 bl 0xb6538 <strlen@plt>
 *   @0x143234 str r0, [r6, #0x8]
 *   @0x143238 mov r0, r7
 *   @0x14323c bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x143240 mov r3, #1
 *   @0x143244 mov r1, #2
 *   @0x143248 stm r6, {r0, r3}
 *   @0x14324c mov r0, r5
 *   @0x143250 str r6, [r8]
 *   @0x143254 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x143258 ldr r2, [pc, #0x234]
 *   @0x14325c ldr r3, [pc, #0x234]
 *   @0x143260 ldr r2, [r4, r2]
 *   @0x143264 strb r0, [r2]
 *   @0x143268 ldr r8, [r4, r3]
 *   @0x14326c ldr r6, [r8]
 *   @0x143270 cmp r6, #0
 *   @0x143274 beq 0x14329c <_Z18F_ActionSetCaptionR6RValueP9CInstanceS2_iPS_+0x100>
 *   @0x143278 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x14327c ldr r7, [r6, #0x4]
 *   @0x143280 sub r7, r7, #1
 *   @0x143284 str r7, [r6, #0x4]
 *   @0x143288 cmp r7, #0
 *   @0x14328c beq 0x1433a8 <_Z18F_ActionSetCaptionR6RValueP9CInstanceS2_iPS_+0x20c>
 *   @0x143290 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x143294 mov r0, r6
 *   @0x143298 bl 0x27d1d0 <_ZdlPv>
 *   @0x14329c mov r1, #3
 *   @0x1432a0 mov r0, r5
 *   @0x1432a4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x1432a8 mov r7, r0
 *   @0x1432ac mov r0, #12
 *   @0x1432b0 bl 0x27c524 <_Znwj>
 *   @0x1432b4 mov r6, r0
 *   @0x1432b8 subs r0, r7, #0
 *   @0x1432bc beq 0x1432c4 <_Z18F_ActionSetCaptionR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x1432c0 bl 0xb6538 <strlen@plt>
 *   @0x1432c4 str r0, [r6, #0x8]
 *   @0x1432c8 mov r0, r7
 *   @0x1432cc bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1432d0 mov r3, #1
 *   @0x1432d4 mov r1, #4
 *   @0x1432d8 stm r6, {r0, r3}
 *   @0x1432dc mov r0, r5
 *   @0x1432e0 str r6, [r8]
 *   @0x1432e4 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x1432e8 ldr r2, [pc, #0x1ac]
 *   @0x1432ec ldr r3, [pc, #0x1ac]
 *   @0x1432f0 ldr r2, [r4, r2]
 *   @0x1432f4 strb r0, [r2]
 *   @0x1432f8 ldr r6, [r4, r3]
 *   @0x1432fc ldr r4, [r6]
 *   @0x143300 cmp r4, #0
 *   @0x143304 beq 0x14332c <_Z18F_ActionSetCaptionR6RValueP9CInstanceS2_iPS_+0x190>
 *   @0x143308 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x14330c ldr r7, [r4, #0x4]
 *   @0x143310 sub r7, r7, #1
 *   @0x143314 str r7, [r4, #0x4]
 *   @0x143318 cmp r7, #0
 *   @0x14331c beq 0x143370 <_Z18F_ActionSetCaptionR6RValueP9CInstanceS2_iPS_+0x1d4>
 *   @0x143320 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x143324 mov r0, r4
 *   @0x143328 bl 0x27d1d0 <_ZdlPv>
 *   @0x14332c mov r0, r5
 *   @0x143330 mov r1, #5
 *   @0x143334 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x143338 mov r5, r0
 *   @0x14333c mov r0, #12
 *   @0x143340 bl 0x27c524 <_Znwj>
 *   @0x143344 mov r4, r0
 *   @0x143348 subs r0, r5, #0
 *   @0x14334c beq 0x143354 <_Z18F_ActionSetCaptionR6RValueP9CInstanceS2_iPS_+0x1b8>
 *   @0x143350 bl 0xb6538 <strlen@plt>
 *   @0x143354 str r0, [r4, #0x8]
 *   @0x143358 mov r0, r5
 *   @0x14335c bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x143360 mov r3, #1
 *   @0x143364 stm r4, {r0, r3}
 *   @0x143368 str r4, [r6]
 *   @0x14336c pop {r4, r5, r6, r7, r8, pc}
 *   @0x143370 ldr r0, [r4]
 *   @0x143374 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x143378 str r7, [r4]
 *   @0x14337c str r7, [r4, #0x8]
 *   @0x143380 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x143384 ldr r7, [r4, #0x4]
 *   @0x143388 sub r7, r7, #1
 *   @0x14338c str r7, [r4, #0x4]
 *   @0x143390 cmp r7, #0
 *   @0x143394 beq 0x143418 <_Z18F_ActionSetCaptionR6RValueP9CInstanceS2_iPS_+0x27c>
 *   @0x143398 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x14339c mov r0, r4
 *   @0x1433a0 bl 0x27d1d0 <_ZdlPv>
 *   @0x1433a4 b 0x143320 <_Z18F_ActionSetCaptionR6RValueP9CInstanceS2_iPS_+0x184>
 *   @0x1433a8 ldr r0, [r6]
 *   @0x1433ac bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1433b0 str r7, [r6]
 *   @0x1433b4 str r7, [r6, #0x8]
 *   @0x1433b8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1433bc ldr r7, [r6, #0x4]
 *   @0x1433c0 sub r7, r7, #1
 *   @0x1433c4 str r7, [r6, #0x4]
 *   @0x1433c8 cmp r7, #0
 *   @0x1433cc beq 0x143460 <_Z18F_ActionSetCaptionR6RValueP9CInstanceS2_iPS_+0x2c4>
 *   @0x1433d0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1433d4 mov r0, r6
 *   @0x1433d8 bl 0x27d1d0 <_ZdlPv>
 *   @0x1433dc b 0x143290 <_Z18F_ActionSetCaptionR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0x1433e0 ldr r0, [r6]
 *   @0x1433e4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1433e8 str r7, [r6]
 *   @0x1433ec str r7, [r6, #0x8]
 *   @0x1433f0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1433f4 ldr r7, [r6, #0x4]
 *   @0x1433f8 sub r7, r7, #1
 *   @0x1433fc str r7, [r6, #0x4]
 *   @0x143400 cmp r7, #0
 *   @0x143404 beq 0x14343c <_Z18F_ActionSetCaptionR6RValueP9CInstanceS2_iPS_+0x2a0>
 *   @0x143408 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x14340c mov r0, r6
 *   @0x143410 bl 0x27d1d0 <_ZdlPv>
 *   @0x143414 b 0x143200 <_Z18F_ActionSetCaptionR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x143418 ldr r0, [r4]
 *   @0x14341c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x143420 mov r0, r4
 *   @0x143424 str r7, [r4]
 *   @0x143428 str r7, [r4, #0x8]
 *   @0x14342c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x143430 mov r0, r4
 *   @0x143434 bl 0x27d1d0 <_ZdlPv>
 *   @0x143438 b 0x143398 <_Z18F_ActionSetCaptionR6RValueP9CInstanceS2_iPS_+0x1fc>
 *   @0x14343c ldr r0, [r6]
 *   @0x143440 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x143444 mov r0, r6
 *   @0x143448 str r7, [r6]
 *   @0x14344c str r7, [r6, #0x8]
 *   @0x143450 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x143454 mov r0, r6
 *   @0x143458 bl 0x27d1d0 <_ZdlPv>
 *   @0x14345c b 0x143408 <_Z18F_ActionSetCaptionR6RValueP9CInstanceS2_iPS_+0x26c>
 *   @0x143460 ldr r0, [r6]
 *   @0x143464 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x143468 mov r0, r6
 *   @0x14346c str r7, [r6]
 *   @0x143470 str r7, [r6, #0x8]
 *   @0x143474 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x143478 mov r0, r6
 *   @0x14347c bl 0x27d1d0 <_ZdlPv>
 *   @0x143480 b 0x1433d0 <_Z18F_ActionSetCaptionR6RValueP9CInstanceS2_iPS_+0x234>
 *   @0x143484 eoreq lr, r10, r0, lsr #21
 *   @0x143488 .word 0xffffd998
 *   @0x14348c .word 0xffffd99c
 *   @0x143490 .word 0xffffd9a0
 *   @0x143494 .word 0xffffd9a4
 *   @0x143498 .word 0xffffd9a8
 *   @0x14349c .word 0xffffd9ac
 *   @0x1434a0 .word 0xffffd9b0
 *
 * ══ §17/39 C3D_Model::LoadFromBuffer(int)  0x1641f0  size 776  194 条（0x1641f0..0x1644f8）
 * @func 0x1641f0 0x1644f8  size 776  194 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ReadLn(CStream*, char const*&)×3 / CStream::~CStream()×3 / operator delete(void*)×3 / operator new(unsigned int)×2 / C3D_Model::LoadFromBuffer(int)+0x2bc×2 / C3D_Model::Clear() / CStream::CStream(int) / GetIBuffer(int)
 * 字段偏移 top8: 0x8×5 / 0x4×4 / 0x48×3 / 0x20×3 / 0x4c×3 / 0x2×3 / 0x28×2 / 0xc×2
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1641f0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1641f4 sub sp, sp, #124
 *   @0x1641f8 mov r7, r1
 *   @0x1641fc mov r6, #0
 *   @0x164200 mov r5, r0
 *   @0x164204 str r6, [sp, #0x48]
 *   @0x164208 bl 0x163ce0 <_ZN9C3D_Model5ClearEv>
 *   @0x16420c mov r0, #32
 *   @0x164210 bl 0x27c524 <_Znwj>
 *   @0x164214 mov r1, r6
 *   @0x164218 mov r4, r0
 *   @0x16421c bl 0x2010ec <_ZN7CStreamC2Ei>
 *   @0x164220 mov r0, r7
 *   @0x164224 bl 0xc6720 <_Z10GetIBufferi>
 *   @0x164228 subs r7, r0, #0
 *   @0x16422c beq 0x1642c4 <_ZN9C3D_Model14LoadFromBufferEi+0xd4>
 *   @0x164230 ldr r2, [r7, #0x20]
 *   @0x164234 mov r0, r4
 *   @0x164238 ldr r1, [r7, #0x4]
 *   @0x16423c asr r3, r2, #31
 *   @0x164240 bl 0x201170 <_ZN7CStream14LoadFromMemoryEPvx>
 *   @0x164244 mov r0, r4
 *   @0x164248 bl 0x201158 <_ZN7CStream9GetMemoryEv>
 *   @0x16424c subs r7, r0, #0
 *   @0x164250 beq 0x1642a0 <_ZN9C3D_Model14LoadFromBufferEi+0xb0>
 *   @0x164254 add r7, sp, #72
 *   @0x164258 mov r3, #1
 *   @0x16425c mov r0, r4
 *   @0x164260 strb r3, [r4]
 *   @0x164264 mov r1, r7
 *   @0x164268 bl 0x163dbc <_Z6ReadLnP7CStreamRPKc>
 *   @0x16426c ldr r1, [pc, #0x278]
 *   @0x164270 ldr r0, [sp, #0x48]
 *   @0x164274 add r1, pc, r1
 *   @0x164278 bl 0xb6574 <strcmp@plt>
 *   @0x16427c cmp r0, #0
 *   @0x164280 beq 0x1642d8 <_ZN9C3D_Model14LoadFromBufferEi+0xe8>
 *   @0x164284 mov r0, r4
 *   @0x164288 bl 0x201328 <_ZN7CStreamD2Ev>
 *   @0x16428c mov r0, r4
 *   @0x164290 bl 0x27d1d0 <_ZdlPv>
 *   @0x164294 mov r0, r6
 *   @0x164298 add sp, sp, #124
 *   @0x16429c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1642a0 cmp r4, #0
 *   @0x1642a4 beq 0x1642cc <_ZN9C3D_Model14LoadFromBufferEi+0xdc>
 *   @0x1642a8 mov r0, r4
 *   @0x1642ac bl 0x201328 <_ZN7CStreamD2Ev>
 *   @0x1642b0 mov r0, r4
 *   @0x1642b4 bl 0x27d1d0 <_ZdlPv>
 *   @0x1642b8 mov r0, r7
 *   @0x1642bc add sp, sp, #124
 *   @0x1642c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1642c4 cmp r4, r6
 *   @0x1642c8 bne 0x1642a8 <_ZN9C3D_Model14LoadFromBufferEi+0xb8>
 *   @0x1642cc mov r0, #0
 *   @0x1642d0 add sp, sp, #124
 *   @0x1642d4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1642d8 mov r0, r4
 *   @0x1642dc mov r1, r7
 *   @0x1642e0 bl 0x163dbc <_Z6ReadLnP7CStreamRPKc>
 *   @0x1642e4 ldr r0, [sp, #0x48]
 *   @0x1642e8 cmp r0, #0
 *   @0x1642ec ldreq r0, [r5]
 *   @0x1642f0 beq 0x1642fc <_ZN9C3D_Model14LoadFromBufferEi+0x10c>
 *   @0x1642f4 bl 0xb66b8 <atoi@plt>
 *   @0x1642f8 str r0, [r5]
 *   @0x1642fc cmp r0, #0
 *   @0x164300 ble 0x1644ac <_ZN9C3D_Model14LoadFromBufferEi+0x2bc>
 *   @0x164304 ldr r2, [pc, #0x1e4]
 *   @0x164308 lsl r1, r0, #2
 *   @0x16430c mov r3, #247
 *   @0x164310 add r0, r5, #8
 *   @0x164314 add r2, pc, r2
 *   @0x164318 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x16431c ldr r3, [r5]
 *   @0x164320 cmp r3, #0
 *   @0x164324 str r3, [r5, #0x4]
 *   @0x164328 ble 0x1644ac <_ZN9C3D_Model14LoadFromBufferEi+0x2bc>
 *   @0x16432c ldr r11, [pc, #0x1c0]
 *   @0x164330 add r10, sp, #76
 *   @0x164334 add r9, sp, #80
 *   @0x164338 add r8, sp, #84
 *   @0x16433c add r11, pc, r11
 *   @0x164340 mov r6, #0
 *   @0x164344 add r12, sp, #88
 *   @0x164348 str r12, [sp, #0x44]
 *   @0x16434c add r12, sp, #92
 *   @0x164350 str r12, [sp, #0x28]
 *   @0x164354 add r12, sp, #96
 *   @0x164358 str r12, [sp, #0x2c]
 *   @0x16435c add r12, sp, #100
 *   @0x164360 str r12, [sp, #0x30]
 *   @0x164364 add r12, sp, #104
 *   @0x164368 str r12, [sp, #0x34]
 *   @0x16436c add r12, sp, #108
 *   @0x164370 str r12, [sp, #0x38]
 *   @0x164374 add r12, sp, #112
 *   @0x164378 str r12, [sp, #0x3c]
 *   @0x16437c add r12, sp, #116
 *   @0x164380 str r12, [sp, #0x40]
 *   @0x164384 mov r1, r10
 *   @0x164388 mov r0, r4
 *   @0x16438c mov r3, #0
 *   @0x164390 str r3, [sp, #0x4c]
 *   @0x164394 bl 0x163dbc <_Z6ReadLnP7CStreamRPKc>
 *   @0x164398 mov r0, #44
 *   @0x16439c ldr r7, [r5, #0x8]
 *   @0x1643a0 bl 0x27c524 <_Znwj>
 *   @0x1643a4 mov r1, r11
 *   @0x1643a8 mov r3, r9
 *   @0x1643ac add r12, sp, #88
 *   @0x1643b0 str r0, [r7, r6, lsl #2]
 *   @0x1643b4 ldr r2, [r5, #0x8]
 *   @0x1643b8 ldr r0, [sp, #0x4c]
 *   @0x1643bc ldr r2, [r2, r6, lsl #2]
 *   @0x1643c0 str r12, [sp, #0x4]
 *   @0x1643c4 add r12, sp, #92
 *   @0x1643c8 str r8, [sp]
 *   @0x1643cc str r12, [sp, #0x8]
 *   @0x1643d0 add r12, sp, #96
 *   @0x1643d4 str r12, [sp, #0xc]
 *   @0x1643d8 add r12, sp, #100
 *   @0x1643dc str r12, [sp, #0x10]
 *   @0x1643e0 add r12, sp, #104
 *   @0x1643e4 str r12, [sp, #0x14]
 *   @0x1643e8 add r12, sp, #108
 *   @0x1643ec str r12, [sp, #0x18]
 *   @0x1643f0 add r12, sp, #112
 *   @0x1643f4 str r12, [sp, #0x1c]
 *   @0x1643f8 add r12, sp, #116
 *   @0x1643fc str r12, [sp, #0x20]
 *   @0x164400 bl 0xb68f8 <sscanf@plt>
 *   @0x164404 ldr r3, [r5, #0x8]
 *   @0x164408 ldr r2, [sp, #0x50]
 *   @0x16440c ldr r3, [r3, r6, lsl #2]
 *   @0x164410 str r2, [r3, #0x4]
 *   @0x164414 ldr r2, [sp, #0x54]
 *   @0x164418 str r2, [r3, #0x8]
 *   @0x16441c ldr r2, [sp, #0x58]
 *   @0x164420 str r2, [r3, #0xc]
 *   @0x164424 vldr s12, [sp, #92]
 *   @0x164428 vstr s12, [r3, #16]
 *   @0x16442c ldr r2, [sp, #0x60]
 *   @0x164430 str r2, [r3, #0x14]
 *   @0x164434 vldr s13, [sp, #100]
 *   @0x164438 vstr s13, [r3, #24]
 *   @0x16443c vldr s14, [sp, #104]
 *   @0x164440 vstr s14, [r3, #28]
 *   @0x164444 ldr r1, [sp, #0x6c]
 *   @0x164448 ldr r2, [r3]
 *   @0x16444c str r1, [r3, #0x20]
 *   @0x164450 sub r2, r2, #3
 *   @0x164454 vldr s15, [sp, #112]
 *   @0x164458 vstr s15, [r3, #36]
 *   @0x16445c ldr r1, [sp, #0x74]
 *   @0x164460 str r1, [r3, #0x28]
 *   @0x164464 cmp r2, #6
 *   @0x164468 addls pc, pc, r2, lsl #2
 *   @0x16446c b 0x164494 <_ZN9C3D_Model14LoadFromBufferEi+0x2a4>
 *   @0x164470 b 0x1644d4 <_ZN9C3D_Model14LoadFromBufferEi+0x2e4>
 *   @0x164474 b 0x164494 <_ZN9C3D_Model14LoadFromBufferEi+0x2a4>
 *   @0x164478 b 0x1644c8 <_ZN9C3D_Model14LoadFromBufferEi+0x2d8>
 *   @0x16447c b 0x164494 <_ZN9C3D_Model14LoadFromBufferEi+0x2a4>
 *   @0x164480 b 0x1644e0 <_ZN9C3D_Model14LoadFromBufferEi+0x2f0>
 *   @0x164484 b 0x164494 <_ZN9C3D_Model14LoadFromBufferEi+0x2a4>
 *   @0x164488 b 0x16448c <_ZN9C3D_Model14LoadFromBufferEi+0x29c>
 *   @0x16448c vcvt.s32.f32 s15, s15
 *   @0x164490 vstr s15, [r3, #36]
 *   @0x164494 ldr r0, [sp, #0x4c]
 *   @0x164498 add r6, r6, #1
 *   @0x16449c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1644a0 ldr r3, [r5]
 *   @0x1644a4 cmp r3, r6
 *   @0x1644a8 bgt 0x164384 <_ZN9C3D_Model14LoadFromBufferEi+0x194>
 *   @0x1644ac mov r0, r4
 *   @0x1644b0 bl 0x201328 <_ZN7CStreamD2Ev>
 *   @0x1644b4 mov r0, r4
 *   @0x1644b8 bl 0x27d1d0 <_ZdlPv>
 *   @0x1644bc mov r0, #1
 *   @0x1644c0 add sp, sp, #124
 *   @0x1644c4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1644c8 vcvt.s32.f32 s13, s13
 *   @0x1644cc vstr s13, [r3, #24]
 *   @0x1644d0 b 0x164494 <_ZN9C3D_Model14LoadFromBufferEi+0x2a4>
 *   @0x1644d4 vcvt.s32.f32 s12, s12
 *   @0x1644d8 vstr s12, [r3, #16]
 *   @0x1644dc b 0x164494 <_ZN9C3D_Model14LoadFromBufferEi+0x2a4>
 *   @0x1644e0 vcvt.s32.f32 s14, s14
 *   @0x1644e4 vstr s14, [r3, #28]
 *   @0x1644e8 b 0x164494 <_ZN9C3D_Model14LoadFromBufferEi+0x2a4>
 *   @0x1644ec andseq r6, lr, r0, ror #5
 *   @0x1644f0 andseq r6, lr, r0, lsl #4
 *   @0x1644f4 andseq r6, lr, r12, lsl r2
 *
 * ══ §18/39 ReadPNGHeader(yyPNGFile*)  0x189b78  size 776  194 条（0x189b78..0x189e80）
 * @func 0x189b78 0x189e80  size 776  194 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x189d38→0x3eb70c, 0x189d9c→0x3eb70c, 0x189dc8→0x3eb70c
 * 调用序列: png_destroy_read_struct×3 / png_create_info_struct×2 / png_sig_cmp / png_create_read_struct / png_set_longjmp_fn / 0xb6904 / png_set_read_fn / png_set_sig_bytes
 * 字段偏移 top8: 0x18×27 / 0x14×14 / 0x1c×6 / 0xc×4 / 0x24×3 / 0x4×2 / 0x10×2 / 0x134×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x189b78 push {r4, lr}
 *   @0x189b7c sub sp, sp, #56
 *   @0x189b80 mov r1, #0
 *   @0x189b84 mov r2, #8
 *   @0x189b88 str r0, [sp, #0x18]
 *   @0x189b8c ldr r0, [r0, #0x4]
 *   @0x189b90 blx 0x2a5a4c <png_sig_cmp>
 *   @0x189b94 ldr r1, [pc, #0x2c8]
 *   @0x189b98 add r1, pc, r1
 *   @0x189b9c str r1, [sp, #0x1c]
 *   @0x189ba0 subs r1, r0, #0
 *   @0x189ba4 bne 0x189d34 <_Z13ReadPNGHeaderP9yyPNGFile+0x1bc>
 *   @0x189ba8 ldr r0, [pc, #0x2b8]
 *   @0x189bac mov r2, r1
 *   @0x189bb0 mov r3, r1
 *   @0x189bb4 add r0, pc, r0
 *   @0x189bb8 blx 0x2a6fdc <png_create_read_struct>
 *   @0x189bbc ldr r2, [sp, #0x18]
 *   @0x189bc0 cmp r0, #0
 *   @0x189bc4 str r0, [r2, #0x14]
 *   @0x189bc8 beq 0x189d9c <_Z13ReadPNGHeaderP9yyPNGFile+0x224>
 *   @0x189bcc blx 0x2a5b64 <png_create_info_struct>
 *   @0x189bd0 ldr r3, [sp, #0x18]
 *   @0x189bd4 cmp r0, #0
 *   @0x189bd8 str r0, [r3, #0x18]
 *   @0x189bdc beq 0x189df4 <_Z13ReadPNGHeaderP9yyPNGFile+0x27c>
 *   @0x189be0 ldr r12, [sp, #0x18]
 *   @0x189be4 ldr r0, [r12, #0x14]
 *   @0x189be8 blx 0x2a5b64 <png_create_info_struct>
 *   @0x189bec ldr r1, [sp, #0x18]
 *   @0x189bf0 cmp r0, #0
 *   @0x189bf4 str r0, [r1, #0x1c]
 *   @0x189bf8 beq 0x189d8c <_Z13ReadPNGHeaderP9yyPNGFile+0x214>
 *   @0x189bfc ldr r12, [sp, #0x18]
 *   @0x189c00 mov r2, #256
 *   @0x189c04 ldr r3, [pc, #0x260]
 *   @0x189c08 ldr r0, [r12, #0x14]
 *   @0x189c0c ldr r12, [sp, #0x1c]
 *   @0x189c10 ldr r1, [r12, r3]
 *   @0x189c14 blx 0x2a653c <png_set_longjmp_fn>
 *   @0x189c18 bl 0xb6904 <setjmp@plt>
 *   @0x189c1c subs r4, r0, #0
 *   @0x189c20 bne 0x189db0 <_Z13ReadPNGHeaderP9yyPNGFile+0x238>
 *   @0x189c24 ldr r12, [sp, #0x18]
 *   @0x189c28 add r1, sp, #48
 *   @0x189c2c ldr r2, [pc, #0x23c]
 *   @0x189c30 ldr r3, [r12, #0x4]
 *   @0x189c34 add r2, pc, r2
 *   @0x189c38 ldr r0, [r12, #0x14]
 *   @0x189c3c add r3, r3, #8
 *   @0x189c40 str r12, [sp, #0x30]
 *   @0x189c44 str r3, [sp, #0x34]
 *   @0x189c48 blx 0x2a804c <png_set_read_fn>
 *   @0x189c4c ldr r1, [sp, #0x18]
 *   @0x189c50 ldr r0, [r1, #0x14]
 *   @0x189c54 mov r1, #8
 *   @0x189c58 blx 0x2a5a24 <png_set_sig_bytes>
 *   @0x189c5c ldr r2, [sp, #0x18]
 *   @0x189c60 ldr r0, [r2, #0x14]
 *   @0x189c64 ldr r1, [r2, #0x18]
 *   @0x189c68 blx 0x2a6ff0 <png_read_info>
 *   @0x189c6c ldr r3, [sp, #0x18]
 *   @0x189c70 ldr r1, [r3, #0x18]
 *   @0x189c74 ldr r0, [r3, #0x14]
 *   @0x189c78 blx 0x2a65a6 <png_get_bit_depth>
 *   @0x189c7c ldr r12, [sp, #0x18]
 *   @0x189c80 ldr r1, [r12, #0x18]
 *   @0x189c84 str r0, [sp, #0x20]
 *   @0x189c88 ldr r0, [r12, #0x14]
 *   @0x189c8c blx 0x2a65b2 <png_get_color_type>
 *   @0x189c90 cmp r0, #3
 *   @0x189c94 str r0, [sp, #0x24]
 *   @0x189c98 movne r3, r0
 *   @0x189c9c beq 0x189e28 <_Z13ReadPNGHeaderP9yyPNGFile+0x2b0>
 *   @0x189ca0 bics r2, r3, #4
 *   @0x189ca4 beq 0x189e08 <_Z13ReadPNGHeaderP9yyPNGFile+0x290>
 *   @0x189ca8 bics r12, r3, #2
 *   @0x189cac beq 0x189ddc <_Z13ReadPNGHeaderP9yyPNGFile+0x264>
 *   @0x189cb0 eor r4, r4, #1
 *   @0x189cb4 cmp r3, #3
 *   @0x189cb8 movne r3, #0
 *   @0x189cbc andeq r3, r4, #1
 *   @0x189cc0 cmp r3, #0
 *   @0x189cc4 bne 0x189ddc <_Z13ReadPNGHeaderP9yyPNGFile+0x264>
 *   @0x189cc8 ldr r2, [sp, #0x18]
 *   @0x189ccc add r3, sp, #32
 *   @0x189cd0 ldr r1, [r2, #0x18]
 *   @0x189cd4 ldr r0, [r2, #0x14]
 *   @0x189cd8 add r2, sp, #36
 *   @0x189cdc str r3, [sp]
 *   @0x189ce0 mov r3, #0
 *   @0x189ce4 stmib sp, {r2, r3}
 *   @0x189ce8 add r2, sp, #40
 *   @0x189cec str r3, [sp, #0xc]
 *   @0x189cf0 str r3, [sp, #0x10]
 *   @0x189cf4 add r3, sp, #44
 *   @0x189cf8 blx 0x2a693e <png_get_IHDR>
 *   @0x189cfc add r1, sp, #36
 *   @0x189d00 ldr r12, [sp, #0x18]
 *   @0x189d04 ldm r1, {r1, r2, r3}
 *   @0x189d08 cmp r1, #3
 *   @0x189d0c str r2, [r12, #0xc]
 *   @0x189d10 str r3, [r12, #0x10]
 *   @0x189d14 beq 0x189e1c <_Z13ReadPNGHeaderP9yyPNGFile+0x2a4>
 *   @0x189d18 ldr r1, [sp, #0x18]
 *   @0x189d1c ldr r0, [r1, #0x14]
 *   @0x189d20 ldr r1, [r1, #0x18]
 *   @0x189d24 blx 0x2a7448 <png_read_update_info>
 *   @0x189d28 mov r0, #1
 *   @0x189d2c add sp, sp, #56
 *   @0x189d30 pop {r4, pc}
 *   @0x189d34 ldr r12, [sp, #0x1c]
 *   @0x189d38 ldr r3, [pc, #0x134]
 *   @0x189d3c ldr r1, [pc, #0x134]
 *   @0x189d40 ldr r3, [r12, r3]
 *   @0x189d44 add r1, pc, r1
 *   @0x189d48 ldr r4, [r3]
 *   @0x189d4c ldr r3, [r4]
 *   @0x189d50 mov r0, r4
 *   @0x189d54 ldr r3, [r3, #0xc]
 *   @0x189d58 blx r3
 *   @0x189d5c mov r0, r4
 *   @0x189d60 ldr r3, [r0]
 *   @0x189d64 mov r2, #1
 *   @0x189d68 ldr r12, [sp, #0x18]
 *   @0x189d6c ldr r1, [pc, #0x108]
 *   @0x189d70 ldr r3, [r3, #0xc]
 *   @0x189d74 add r1, pc, r1
 *   @0x189d78 strb r2, [r12]
 *   @0x189d7c blx r3
 *   @0x189d80 mov r0, #0
 *   @0x189d84 add sp, sp, #56
 *   @0x189d88 pop {r4, pc}
 *   @0x189d8c mov r2, r0
 *   @0x189d90 add r0, r1, #20
 *   @0x189d94 add r1, r1, #24
 *   @0x189d98 blx 0x2a7e2c <png_destroy_read_struct>
 *   @0x189d9c ldr r3, [pc, #0xd0]
 *   @0x189da0 ldr r2, [sp, #0x1c]
 *   @0x189da4 ldr r3, [r2, r3]
 *   @0x189da8 ldr r0, [r3]
 *   @0x189dac b 0x189d60 <_Z13ReadPNGHeaderP9yyPNGFile+0x1e8>
 *   @0x189db0 ldr r1, [sp, #0x18]
 *   @0x189db4 ldr r3, [sp, #0x18]
 *   @0x189db8 add r0, r1, #20
 *   @0x189dbc add r1, r1, #24
 *   @0x189dc0 add r2, r3, #28
 *   @0x189dc4 blx 0x2a7e2c <png_destroy_read_struct>
 *   @0x189dc8 ldr r3, [pc, #0xa4]
 *   @0x189dcc ldr r2, [sp, #0x1c]
 *   @0x189dd0 ldr r3, [r2, r3]
 *   @0x189dd4 ldr r0, [r3]
 *   @0x189dd8 b 0x189d60 <_Z13ReadPNGHeaderP9yyPNGFile+0x1e8>
 *   @0x189ddc ldr r1, [sp, #0x18]
 *   @0x189de0 mov r2, #1
 *   @0x189de4 ldr r0, [r1, #0x14]
 *   @0x189de8 mov r1, #255
 *   @0x189dec blx 0x2af812 <png_set_add_alpha>
 *   @0x189df0 b 0x189cc8 <_Z13ReadPNGHeaderP9yyPNGFile+0x150>
 *   @0x189df4 mov r1, r0
 *   @0x189df8 add r0, r3, #20
 *   @0x189dfc mov r2, r1
 *   @0x189e00 blx 0x2a7e2c <png_destroy_read_struct>
 *   @0x189e04 b 0x189d9c <_Z13ReadPNGHeaderP9yyPNGFile+0x224>
 *   @0x189e08 ldr r3, [sp, #0x18]
 *   @0x189e0c ldr r0, [r3, #0x14]
 *   @0x189e10 blx 0x2a880a <png_set_gray_to_rgb>
 *   @0x189e14 ldr r3, [sp, #0x24]
 *   @0x189e18 b 0x189ca8 <_Z13ReadPNGHeaderP9yyPNGFile+0x130>
 *   @0x189e1c ldr r0, [r12, #0x14]
 *   @0x189e20 blx 0x2a87b0 <png_set_palette_to_rgb>
 *   @0x189e24 b 0x189d18 <_Z13ReadPNGHeaderP9yyPNGFile+0x1a0>
 *   @0x189e28 ldr r1, [sp, #0x18]
 *   @0x189e2c mov r2, r4
 *   @0x189e30 add r3, sp, #44
 *   @0x189e34 ldr r0, [r1, #0x14]
 *   @0x189e38 ldr r1, [r1, #0x18]
 *   @0x189e3c str r4, [sp]
 *   @0x189e40 blx 0x2a6b56 <png_get_tRNS>
 *   @0x189e44 cmp r0, #0
 *   @0x189e48 moveq r4, r0
 *   @0x189e4c beq 0x189e5c <_Z13ReadPNGHeaderP9yyPNGFile+0x2e4>
 *   @0x189e50 ldr r4, [sp, #0x2c]
 *   @0x189e54 adds r4, r4, #0
 *   @0x189e58 movne r4, #1
 *   @0x189e5c ldr r3, [sp, #0x24]
 *   @0x189e60 b 0x189ca0 <_Z13ReadPNGHeaderP9yyPNGFile+0x128>
 *   @0x189e64 strhteq r8, [r6], -r8
 *   @0x189e68 andseq r0, r12, r8, lsl #21
 *   @0x189e6c .word 0xffffe4ac
 *   @0x189e70 .word 0xfffff5cc
 *   @0x189e74 .word 0xffffbac4
 *   @0x189e78 andseq r2, r12, r8, lsl #7
 *   @0x189e7c andseq r2, r12, r0, lsr #7
 *
 * ══ §19/39 anon_22e430  0x22e430  size 776  194 条（0x22e430..0x22e738）
 * @func 0x22e430 0x22e738  size 776  194 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_22e430+0x280×2 / __divsi3×2 / anon_22e430+0xe0 / _vorbis_block_alloc / anon_22e430+0x26c / anon_22e430+0x254 / anon_22e430+0x210 / anon_22e430+0x134
 * 字段偏移 top8: 0x-50×6 / 0x4×5 / 0x-34×5 / 0x-58×5 / 0x-60×5 / 0x-48×5 / 0x-54×4 / 0x-5c×4
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22e430 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x22e434 add r11, sp, #32
 *   @0x22e438 sub sp, sp, #84
 *   @0x22e43c ldr r7, [pc, #0x2f4]
 *   @0x22e440 str r2, [r11, #-0x3c]
 *   @0x22e444 ldr r7, [pc, r7]
 *   @0x22e448 mov r4, r0
 *   @0x22e44c ldr r9, [r1]
 *   @0x22e450 mov r10, r3
 *   @0x22e454 ldr r2, [r0, #0x24]
 *   @0x22e458 mov r8, r1
 *   @0x22e45c str r7, [r11, #-0x4c]
 *   @0x22e460 ldr r3, [r9]
 *   @0x22e464 ldr r0, [r9, #0x4]
 *   @0x22e468 asr r2, r2, #1
 *   @0x22e46c ldr r1, [r1, #0x14]
 *   @0x22e470 cmp r2, r0
 *   @0x22e474 rsble r0, r3, r2
 *   @0x22e478 rsbgt r0, r3, r0
 *   @0x22e47c ldr r3, [r7]
 *   @0x22e480 ldr r7, [r9, #0x8]
 *   @0x22e484 cmp r0, #0
 *   @0x22e488 ldr r1, [r1]
 *   @0x22e48c str r3, [r11, #-0x28]
 *   @0x22e490 str r7, [r11, #-0x34]
 *   @0x22e494 ldr r7, [r11, #0x4]
 *   @0x22e498 str r1, [r11, #-0x54]
 *   @0x22e49c str r7, [r11, #-0x40]
 *   @0x22e4a0 ble 0x22e6b0 <res0_look+0x4d8>
 *   @0x22e4a4 ldr r1, [r11, #-0x34]
 *   @0x22e4a8 bl 0x318d10 <__divsi3>
 *   @0x22e4ac ldr r7, [r11, #-0x54]
 *   @0x22e4b0 mov r1, r7
 *   @0x22e4b4 str r0, [r11, #-0x58]
 *   @0x22e4b8 add r0, r0, r7
 *   @0x22e4bc sub r0, r0, #1
 *   @0x22e4c0 bl 0x318d10 <__divsi3>
 *   @0x22e4c4 lsl r3, r10, #2
 *   @0x22e4c8 add r3, r3, #14
 *   @0x22e4cc cmp r10, #0
 *   @0x22e4d0 bic r3, r3, #7
 *   @0x22e4d4 sub sp, sp, r3
 *   @0x22e4d8 add r7, sp, #8
 *   @0x22e4dc str r7, [r11, #-0x5c]
 *   @0x22e4e0 ble 0x22e510 <res0_look+0x338>
 *   @0x22e4e4 lsl r5, r0, #2
 *   @0x22e4e8 ldr r0, [r11, #-0x5c]
 *   @0x22e4ec mov r6, #0
 *   @0x22e4f0 sub r7, r0, #4
 *   @0x22e4f4 mov r0, r4
 *   @0x22e4f8 mov r1, r5
 *   @0x22e4fc bl 0x2270e4 <_vorbis_block_alloc>
 *   @0x22e500 add r6, r6, #1
 *   @0x22e504 cmp r6, r10
 *   @0x22e508 str r0, [r7, #0x4]!
 *   @0x22e50c bne 0x22e4f4 <res0_look+0x31c>
 *   @0x22e510 ldr r3, [r8, #0xc]
 *   @0x22e514 cmp r3, #0
 *   @0x22e518 addgt r4, r4, #4
 *   @0x22e51c strgt r4, [r11, #-0x44]
 *   @0x22e520 movgt r7, #0
 *   @0x22e524 strgt r7, [r11, #-0x60]
 *   @0x22e528 ble 0x22e6b0 <res0_look+0x4d8>
 *   @0x22e52c ldr r7, [r11, #-0x58]
 *   @0x22e530 cmp r7, #0
 *   @0x22e534 ble 0x22e69c <res0_look+0x4c4>
 *   @0x22e538 ldr r0, [r11, #-0x60]
 *   @0x22e53c mov r7, #1
 *   @0x22e540 mov r6, #0
 *   @0x22e544 str r6, [r11, #-0x50]
 *   @0x22e548 lsl r7, r7, r0
 *   @0x22e54c str r7, [r11, #-0x64]
 *   @0x22e550 lsl r7, r0, #2
 *   @0x22e554 str r7, [r11, #-0x30]
 *   @0x22e558 ldr r7, [r11, #-0x60]
 *   @0x22e55c cmp r7, #0
 *   @0x22e560 beq 0x22e6d0 <res0_look+0x4f8>
 *   @0x22e564 ldr r7, [r11, #-0x58]
 *   @0x22e568 ldr r0, [r11, #-0x50]
 *   @0x22e56c ldr r1, [r11, #-0x54]
 *   @0x22e570 cmp r7, r0
 *   @0x22e574 cmpgt r1, #0
 *   @0x22e578 ble 0x22e684 <res0_look+0x4ac>
 *   @0x22e57c ldr r7, [r11, #-0x50]
 *   @0x22e580 mov r12, r8
 *   @0x22e584 ldr r0, [r11, #-0x34]
 *   @0x22e588 ldr r8, [r11, #-0x64]
 *   @0x22e58c mul r7, r7, r0
 *   @0x22e590 str r7, [r11, #-0x38]
 *   @0x22e594 mov r7, #0
 *   @0x22e598 str r7, [r11, #-0x48]
 *   @0x22e59c cmp r10, #0
 *   @0x22e5a0 ble 0x22e640 <res0_look+0x468>
 *   @0x22e5a4 ldr r2, [r11, #-0x5c]
 *   @0x22e5a8 mov r4, #0
 *   @0x22e5ac ldr r1, [r11, #-0x48]
 *   @0x22e5b0 sub r5, r2, #4
 *   @0x22e5b4 lsl r7, r1, #2
 *   @0x22e5b8 str r7, [r11, #-0x6c]
 *   @0x22e5bc ldr r3, [r5, #0x4]!
 *   @0x22e5c0 ldr r7, [r11, #-0x6c]
 *   @0x22e5c4 ldr r1, [r9]
 *   @0x22e5c8 ldr r3, [r3, r6]
 *   @0x22e5cc ldr r3, [r3, r7]
 *   @0x22e5d0 add r2, r3, #6
 *   @0x22e5d4 ldr r2, [r9, r2, lsl #2]
 *   @0x22e5d8 tst r8, r2
 *   @0x22e5dc beq 0x22e634 <res0_look+0x45c>
 *   @0x22e5e0 ldr r2, [r12, #0x18]
 *   @0x22e5e4 ldr r7, [r11, #-0x30]
 *   @0x22e5e8 ldr r3, [r2, r3, lsl #2]
 *   @0x22e5ec ldr r0, [r3, r7]
 *   @0x22e5f0 cmp r0, #0
 *   @0x22e5f4 beq 0x22e634 <res0_look+0x45c>
 *   @0x22e5f8 ldr r7, [r11, #-0x38]
 *   @0x22e5fc mvn r2, #7
 *   @0x22e600 add r1, r7, r1
 *   @0x22e604 ldr r7, [r11, #-0x3c]
 *   @0x22e608 ldr r3, [r7, r4, lsl #2]
 *   @0x22e60c str r2, [sp]
 *   @0x22e610 add r1, r3, r1, lsl #2
 *   @0x22e614 str r12, [r11, #-0x68]
 *   @0x22e618 ldr r2, [r11, #-0x44]
 *   @0x22e61c ldr r3, [r11, #-0x34]
 *   @0x22e620 ldr r7, [r11, #-0x40]
 *   @0x22e624 blx r7
 *   @0x22e628 ldr r12, [r11, #-0x68]
 *   @0x22e62c cmn r0, #1
 *   @0x22e630 beq 0x22e6b0 <res0_look+0x4d8>
 *   @0x22e634 add r4, r4, #1
 *   @0x22e638 cmp r4, r10
 *   @0x22e63c bne 0x22e5bc <res0_look+0x3e4>
 *   @0x22e640 ldr r7, [r11, #-0x48]
 *   @0x22e644 ldr r0, [r11, #-0x58]
 *   @0x22e648 add r7, r7, #1
 *   @0x22e64c str r7, [r11, #-0x48]
 *   @0x22e650 ldr r7, [r11, #-0x50]
 *   @0x22e654 ldr r1, [r11, #-0x54]
 *   @0x22e658 ldr r2, [r11, #-0x48]
 *   @0x22e65c add r7, r7, #1
 *   @0x22e660 str r7, [r11, #-0x50]
 *   @0x22e664 cmp r0, r7
 *   @0x22e668 cmpgt r1, r2
 *   @0x22e66c ldr r7, [r11, #-0x38]
 *   @0x22e670 ldr r0, [r11, #-0x34]
 *   @0x22e674 add r7, r7, r0
 *   @0x22e678 str r7, [r11, #-0x38]
 *   @0x22e67c bgt 0x22e59c <res0_look+0x3c4>
 *   @0x22e680 mov r8, r12
 *   @0x22e684 ldr r7, [r11, #-0x58]
 *   @0x22e688 add r6, r6, #4
 *   @0x22e68c ldr r0, [r11, #-0x50]
 *   @0x22e690 cmp r7, r0
 *   @0x22e694 bgt 0x22e558 <res0_look+0x380>
 *   @0x22e698 ldr r3, [r8, #0xc]
 *   @0x22e69c ldr r7, [r11, #-0x60]
 *   @0x22e6a0 add r7, r7, #1
 *   @0x22e6a4 str r7, [r11, #-0x60]
 *   @0x22e6a8 cmp r3, r7
 *   @0x22e6ac bgt 0x22e52c <res0_look+0x354>
 *   @0x22e6b0 ldr r7, [r11, #-0x4c]
 *   @0x22e6b4 mov r0, #0
 *   @0x22e6b8 ldr r2, [r11, #-0x28]
 *   @0x22e6bc ldr r3, [r7]
 *   @0x22e6c0 cmp r2, r3
 *   @0x22e6c4 bne 0x22e734 <res0_look+0x55c>
 *   @0x22e6c8 sub sp, r11, #32
 *   @0x22e6cc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x22e6d0 cmp r10, #0
 *   @0x22e6d4 ble 0x22e564 <res0_look+0x38c>
 *   @0x22e6d8 ldr r7, [r11, #-0x5c]
 *   @0x22e6dc ldr r5, [r11, #-0x60]
 *   @0x22e6e0 sub r4, r7, #4
 *   @0x22e6e4 ldr r7, [r11, #-0x44]
 *   @0x22e6e8 b 0x22e71c <res0_look+0x544>
 *   @0x22e6ec ldr r3, [r9, #0x10]
 *   @0x22e6f0 cmp r0, r3
 *   @0x22e6f4 bge 0x22e6b0 <res0_look+0x4d8>
 *   @0x22e6f8 ldr r3, [r8, #0x20]
 *   @0x22e6fc ldr r2, [r4, #0x4]!
 *   @0x22e700 ldr r3, [r3, r0, lsl #2]
 *   @0x22e704 cmp r3, #0
 *   @0x22e708 str r3, [r2, r6]
 *   @0x22e70c beq 0x22e6b0 <res0_look+0x4d8>
 *   @0x22e710 add r5, r5, #1
 *   @0x22e714 cmp r5, r10
 *   @0x22e718 beq 0x22e564 <res0_look+0x38c>
 *   @0x22e71c ldr r0, [r8, #0x14]
 *   @0x22e720 mov r1, r7
 *   @0x22e724 bl 0x2280d0 <vorbis_book_decode>
 *   @0x22e728 cmn r0, #1
 *   @0x22e72c bne 0x22e6ec <res0_look+0x514>
 *   @0x22e730 b 0x22e6b0 <res0_look+0x4d8>
 *   @0x22e734 bl 0xb65d4 <__stack_chk_fail@plt>
 *
 * ══ §20/39 Java_com_yoyogames_runner_RunnerJNILib_SetKeyValue  0x292660  size 776  194 条（0x292660..0x292968）
 * @func 0x292660 0x292968  size 776  194 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x2926c8→0x3eb70c, 0x2926f8→0x3f77f8, 0x29272c→0x3eb70c, 0x292750→0x756bf0, 0x292780→0x3eb70c, 0x2927b0→0x755288, 0x2927e4→0x3eb70c, 0x292814→0x3f77fc
 * 调用序列: 0xb6640×4 / setJNIEnv
 * 字段偏移 top8: 0xc×7 / 0x2a4×4 / 0x258×2 / 0xf0×2 / 0x2b4×1 / 0x18×1 / 0x230×1 / 0x2a8×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x292660 push {r4, r5, r6, r7, r8, lr}
 *   @0x292664 mov r5, r2
 *   @0x292668 ldr r4, [pc, #0x2b4]
 *   @0x29266c mov r8, r3
 *   @0x292670 mov r6, r0
 *   @0x292674 ldr r7, [sp, #0x18]
 *   @0x292678 add r4, pc, r4
 *   @0x29267c bl 0x290614 <setJNIEnv>
 *   @0x292680 cmp r5, #8
 *   @0x292684 addls pc, pc, r5, lsl #2
 *   @0x292688 b 0x292728 <Java_com_yoyogames_runner_RunnerJNILib_SetKeyValue+0xc8>
 *   @0x29268c b 0x29272c <Java_com_yoyogames_runner_RunnerJNILib_SetKeyValue+0xcc>
 *   @0x292690 b 0x292768 <Java_com_yoyogames_runner_RunnerJNILib_SetKeyValue+0x108>
 *   @0x292694 b 0x2927cc <Java_com_yoyogames_runner_RunnerJNILib_SetKeyValue+0x16c>
 *   @0x292698 b 0x292830 <Java_com_yoyogames_runner_RunnerJNILib_SetKeyValue+0x1d0>
 *   @0x29269c b 0x29286c <Java_com_yoyogames_runner_RunnerJNILib_SetKeyValue+0x20c>
 *   @0x2926a0 b 0x2928a8 <Java_com_yoyogames_runner_RunnerJNILib_SetKeyValue+0x248>
 *   @0x2926a4 b 0x292728 <Java_com_yoyogames_runner_RunnerJNILib_SetKeyValue+0xc8>
 *   @0x2926a8 b 0x292728 <Java_com_yoyogames_runner_RunnerJNILib_SetKeyValue+0xc8>
 *   @0x2926ac b 0x2926b0 <Java_com_yoyogames_runner_RunnerJNILib_SetKeyValue+0x50>
 *   @0x2926b0 ldr r3, [r6]
 *   @0x2926b4 mov r1, r7
 *   @0x2926b8 mov r2, #0
 *   @0x2926bc mov r0, r6
 *   @0x2926c0 ldr r3, [r3, #0x2a4]
 *   @0x2926c4 blx r3
 *   @0x2926c8 ldr r3, [pc, #0x258]
 *   @0x2926cc ldr r1, [pc, #0x258]
 *   @0x2926d0 ldr r3, [r4, r3]
 *   @0x2926d4 add r1, pc, r1
 *   @0x2926d8 mov r5, r0
 *   @0x2926dc mov r2, r0
 *   @0x2926e0 ldr r0, [r3]
 *   @0x2926e4 ldr r3, [r0]
 *   @0x2926e8 ldr r3, [r3, #0xc]
 *   @0x2926ec blx r3
 *   @0x2926f0 mov r0, r5
 *   @0x2926f4 bl 0xb6640 <strdup@plt>
 *   @0x2926f8 ldr r3, [pc, #0x230]
 *   @0x2926fc cmp r5, #0
 *   @0x292700 cmpne r7, #0
 *   @0x292704 ldr r3, [r4, r3]
 *   @0x292708 str r0, [r3]
 *   @0x29270c popeq {r4, r5, r6, r7, r8, pc}
 *   @0x292710 ldr r3, [r6]
 *   @0x292714 mov r1, r7
 *   @0x292718 mov r2, r5
 *   @0x29271c mov r0, r6
 *   @0x292720 ldr r3, [r3, #0x2a8]
 *   @0x292724 blx r3
 *   @0x292728 pop {r4, r5, r6, r7, r8, pc}
 *   @0x29272c ldr r3, [pc, #0x1f4]
 *   @0x292730 mov r2, r8
 *   @0x292734 ldr r1, [pc, #0x1f8]
 *   @0x292738 ldr r3, [r4, r3]
 *   @0x29273c add r1, pc, r1
 *   @0x292740 ldr r0, [r3]
 *   @0x292744 ldr r3, [r0]
 *   @0x292748 ldr r3, [r3, #0xc]
 *   @0x29274c blx r3
 *   @0x292750 ldr r3, [pc, #0x1e0]
 *   @0x292754 adds r8, r8, #0
 *   @0x292758 ldr r3, [r4, r3]
 *   @0x29275c movne r8, #1
 *   @0x292760 strb r8, [r3]
 *   @0x292764 pop {r4, r5, r6, r7, r8, pc}
 *   @0x292768 ldr r3, [r6]
 *   @0x29276c mov r1, r7
 *   @0x292770 mov r2, #0
 *   @0x292774 mov r0, r6
 *   @0x292778 ldr r3, [r3, #0x2a4]
 *   @0x29277c blx r3
 *   @0x292780 ldr r3, [pc, #0x1a0]
 *   @0x292784 ldr r1, [pc, #0x1b0]
 *   @0x292788 ldr r3, [r4, r3]
 *   @0x29278c add r1, pc, r1
 *   @0x292790 mov r5, r0
 *   @0x292794 mov r2, r0
 *   @0x292798 ldr r0, [r3]
 *   @0x29279c ldr r3, [r0]
 *   @0x2927a0 ldr r3, [r3, #0xc]
 *   @0x2927a4 blx r3
 *   @0x2927a8 mov r0, r5
 *   @0x2927ac bl 0xb6640 <strdup@plt>
 *   @0x2927b0 ldr r3, [pc, #0x188]
 *   @0x2927b4 cmp r5, #0
 *   @0x2927b8 cmpne r7, #0
 *   @0x2927bc ldr r3, [r4, r3]
 *   @0x2927c0 str r0, [r3]
 *   @0x2927c4 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x2927c8 b 0x292710 <Java_com_yoyogames_runner_RunnerJNILib_SetKeyValue+0xb0>
 *   @0x2927cc ldr r3, [r6]
 *   @0x2927d0 mov r1, r7
 *   @0x2927d4 mov r2, #0
 *   @0x2927d8 mov r0, r6
 *   @0x2927dc ldr r3, [r3, #0x2a4]
 *   @0x2927e0 blx r3
 *   @0x2927e4 ldr r3, [pc, #0x13c]
 *   @0x2927e8 ldr r1, [pc, #0x154]
 *   @0x2927ec ldr r3, [r4, r3]
 *   @0x2927f0 add r1, pc, r1
 *   @0x2927f4 mov r5, r0
 *   @0x2927f8 mov r2, r0
 *   @0x2927fc ldr r0, [r3]
 *   @0x292800 ldr r3, [r0]
 *   @0x292804 ldr r3, [r3, #0xc]
 *   @0x292808 blx r3
 *   @0x29280c mov r0, r5
 *   @0x292810 bl 0xb6640 <strdup@plt>
 *   @0x292814 ldr r3, [pc, #0x12c]
 *   @0x292818 cmp r5, #0
 *   @0x29281c cmpne r7, #0
 *   @0x292820 ldr r3, [r4, r3]
 *   @0x292824 str r0, [r3]
 *   @0x292828 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x29282c b 0x292710 <Java_com_yoyogames_runner_RunnerJNILib_SetKeyValue+0xb0>
 *   @0x292830 ldr r3, [pc, #0xf0]
 *   @0x292834 mov r2, r8
 *   @0x292838 ldr r1, [pc, #0x10c]
 *   @0x29283c ldr r3, [r4, r3]
 *   @0x292840 add r1, pc, r1
 *   @0x292844 ldr r0, [r3]
 *   @0x292848 ldr r3, [r0]
 *   @0x29284c ldr r3, [r3, #0xc]
 *   @0x292850 blx r3
 *   @0x292854 vmov s13, r8
 *   @0x292858 ldr r3, [pc, #0xf0]
 *   @0x29285c vcvt.f32.s32 s15, s13
 *   @0x292860 ldr r3, [r4, r3]
 *   @0x292864 vstr s15, [r3]
 *   @0x292868 pop {r4, r5, r6, r7, r8, pc}
 *   @0x29286c ldr r3, [pc, #0xb4]
 *   @0x292870 mov r2, r8
 *   @0x292874 ldr r1, [pc, #0xd8]
 *   @0x292878 ldr r3, [r4, r3]
 *   @0x29287c add r1, pc, r1
 *   @0x292880 ldr r0, [r3]
 *   @0x292884 ldr r3, [r0]
 *   @0x292888 ldr r3, [r3, #0xc]
 *   @0x29288c blx r3
 *   @0x292890 vmov s14, r8
 *   @0x292894 ldr r3, [pc, #0xbc]
 *   @0x292898 vcvt.f32.s32 s15, s14
 *   @0x29289c ldr r3, [r4, r3]
 *   @0x2928a0 vstr s15, [r3]
 *   @0x2928a4 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2928a8 ldr r3, [r6]
 *   @0x2928ac mov r1, r7
 *   @0x2928b0 mov r2, #0
 *   @0x2928b4 mov r0, r6
 *   @0x2928b8 ldr r3, [r3, #0x2a4]
 *   @0x2928bc blx r3
 *   @0x2928c0 ldr r1, [pc, #0x94]
 *   @0x2928c4 mov r2, r8
 *   @0x2928c8 add r1, pc, r1
 *   @0x2928cc mov r5, r0
 *   @0x2928d0 ldr r0, [pc, #0x50]
 *   @0x2928d4 mov r3, r5
 *   @0x2928d8 ldr r0, [r4, r0]
 *   @0x2928dc ldr r0, [r0]
 *   @0x2928e0 ldr r12, [r0]
 *   @0x2928e4 ldr r12, [r12, #0xc]
 *   @0x2928e8 blx r12
 *   @0x2928ec vmov s13, r8
 *   @0x2928f0 ldr r3, [pc, #0x68]
 *   @0x2928f4 mov r0, r5
 *   @0x2928f8 vcvt.f64.s32 d7, s13
 *   @0x2928fc ldr r3, [r4, r3]
 *   @0x292900 vstr d7, [r3]
 *   @0x292904 bl 0xb6640 <strdup@plt>
 *   @0x292908 ldr r3, [pc, #0x54]
 *   @0x29290c cmp r5, #0
 *   @0x292910 cmpne r7, #0
 *   @0x292914 ldr r3, [r4, r3]
 *   @0x292918 str r0, [r3]
 *   @0x29291c popeq {r4, r5, r6, r7, r8, pc}
 *   @0x292920 b 0x292710 <Java_com_yoyogames_runner_RunnerJNILib_SetKeyValue+0xb0>
 *   @0x292924 ldrsbeq pc, [r5], -r8
 *   @0x292928 .word 0xffffbac4
 *   @0x29292c andeq r6, r12, r0, ror r9
 *   @0x292930 .word 0xffffe284
 *   @0x292934 andeq r6, r12, r4, asr #16
 *   @0x292938 .word 0xffffe254
 *   @0x29293c andeq r6, r12, r4, lsl r8
 *   @0x292940 .word 0xfffff770
 *   @0x292944 ldrdeq r6, r7, [r12], -r8
 *   @0x292948 .word 0xffffe280
 *   @0x29294c andeq r6, r12, r8, lsr #15
 *   @0x292950 .word 0xffffe288
 *   @0x292954 andeq r6, r12, r8, lsl #15
 *   @0x292958 .word 0xffffe28c
 *   @0x29295c andeq r6, r12, r8, asr r7
 *   @0x292960 .word 0xffffe248
 *   @0x292964 .word 0xfffffd18
 *
 * ══ §21/39 Buffer_Network::Write(eBuffer_Type, RValue*)  0xcad44  size 772  193 条（0xcad44..0xcb048）
 * @func 0xcad44 0xcb048  size 772  193 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538×2 / Buffer_Network::Write(eBuffer_Type, RValue*)+0xd0 / __fixunsdfdi
 * 字段偏移 top8: 0x-10×7 / 0x1c×5 / 0xc×5 / 0x4×4 / 0x10×3 / 0x1×2 / 0x8×2 / 0x24×1
 * VFP 指令 29 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcad44 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0xcad48 mov r6, r0
 *   @0xcad4c ldr r3, [r0, #0x24]
 *   @0xcad50 sub r1, r1, #1
 *   @0xcad54 ldr r7, [r0, #0x1c]
 *   @0xcad58 sub sp, sp, #20
 *   @0xcad5c ldr r0, [r0, #0x14]
 *   @0xcad60 add r7, r3, r7
 *   @0xcad64 sub r12, r0, #1
 *   @0xcad68 rsb r0, r0, #0
 *   @0xcad6c add r7, r7, r12
 *   @0xcad70 and r7, r7, r0
 *   @0xcad74 rsb r7, r3, r7
 *   @0xcad78 str r7, [r6, #0x1c]
 *   @0xcad7c cmp r1, #12
 *   @0xcad80 addls pc, pc, r1, lsl #2
 *   @0xcad84 b 0xcb020 <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x2dc>
 *   @0xcad88 b 0xcae44 <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x100>
 *   @0xcad8c b 0xcae68 <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x124>
 *   @0xcad90 b 0xcae8c <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x148>
 *   @0xcad94 b 0xcaeb0 <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x16c>
 *   @0xcad98 b 0xcaed4 <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x190>
 *   @0xcad9c b 0xcaef8 <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x1b4>
 *   @0xcada0 b 0xcb020 <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x2dc>
 *   @0xcada4 b 0xcaf1c <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x1d8>
 *   @0xcada8 b 0xcaf40 <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x1fc>
 *   @0xcadac b 0xcaf78 <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x234>
 *   @0xcadb0 b 0xcafac <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x268>
 *   @0xcadb4 b 0xcafd0 <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x28c>
 *   @0xcadb8 b 0xcadbc <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x78>
 *   @0xcadbc ldr r3, [r2, #0xc]
 *   @0xcadc0 bic r3, r3, #-16777216
 *   @0xcadc4 cmp r3, #1
 *   @0xcadc8 movne r8, #0
 *   @0xcadcc beq 0xcb038 <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x2f4>
 *   @0xcadd0 mov r0, r8
 *   @0xcadd4 bl 0xb6538 <strlen@plt>
 *   @0xcadd8 mov r9, r0
 *   @0xcaddc ldr r1, [r6, #0x10]
 *   @0xcade0 add r3, r9, r7
 *   @0xcade4 cmp r3, r1
 *   @0xcade8 bge 0xcb000 <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x2bc>
 *   @0xcadec ldr r3, [r6, #0xc]
 *   @0xcadf0 cmp r9, #0
 *   @0xcadf4 add r3, r3, r7
 *   @0xcadf8 ble 0xcae14 <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0xd0>
 *   @0xcadfc add r1, r3, r9
 *   @0xcae00 ldrb r2, [r8], #1
 *   @0xcae04 strb r2, [r3], #1
 *   @0xcae08 cmp r3, r1
 *   @0xcae0c bne 0xcae00 <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0xbc>
 *   @0xcae10 ldr r7, [r6, #0x1c]
 *   @0xcae14 ldr r3, [r6, #0x10]
 *   @0xcae18 add r7, r9, r7
 *   @0xcae1c ldr r9, [r6, #0x20]
 *   @0xcae20 mov r0, #0
 *   @0xcae24 str r7, [r6, #0x1c]
 *   @0xcae28 cmp r7, r9
 *   @0xcae2c movlt r7, r9
 *   @0xcae30 cmp r7, r3
 *   @0xcae34 strle r7, [r6, #0x20]
 *   @0xcae38 strgt r3, [r6, #0x20]
 *   @0xcae3c add sp, sp, #20
 *   @0xcae40 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0xcae44 ldr r4, [r2]
 *   @0xcae48 add r8, sp, #16
 *   @0xcae4c ldr r5, [r2, #0x4]
 *   @0xcae50 mov r9, #1
 *   @0xcae54 vmov d6, r4, r5
 *   @0xcae58 vcvt.u32.f64 s13, d6
 *   @0xcae5c vmov r4, s13
 *   @0xcae60 strb r4, [r8, #-0x10]!
 *   @0xcae64 b 0xcaddc <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x98>
 *   @0xcae68 ldr r4, [r2]
 *   @0xcae6c add r8, sp, #16
 *   @0xcae70 ldr r5, [r2, #0x4]
 *   @0xcae74 mov r9, #1
 *   @0xcae78 vmov d7, r4, r5
 *   @0xcae7c vcvt.s32.f64 s15, d7
 *   @0xcae80 vmov r4, s15
 *   @0xcae84 strb r4, [r8, #-0x10]!
 *   @0xcae88 b 0xcaddc <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x98>
 *   @0xcae8c ldm r2, {r0, r1}
 *   @0xcae90 vmov d7, r0, r1
 *   @0xcae94 vcvt.u32.f64 s15, d7
 *   @0xcae98 vmov r0, s15
 *   @0xcae9c rev16 r0, r0
 *   @0xcaea0 add r8, sp, #16
 *   @0xcaea4 mov r9, #2
 *   @0xcaea8 strh r0, [r8, #-16]!
 *   @0xcaeac b 0xcaddc <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x98>
 *   @0xcaeb0 ldm r2, {r0, r1}
 *   @0xcaeb4 vmov d6, r0, r1
 *   @0xcaeb8 vcvt.s32.f64 s13, d6
 *   @0xcaebc vmov r0, s13
 *   @0xcaec0 rev16 r0, r0
 *   @0xcaec4 add r8, sp, #16
 *   @0xcaec8 mov r9, #2
 *   @0xcaecc strh r0, [r8, #-16]!
 *   @0xcaed0 b 0xcaddc <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x98>
 *   @0xcaed4 ldm r2, {r0, r1}
 *   @0xcaed8 vmov d7, r0, r1
 *   @0xcaedc vcvt.u32.f64 s15, d7
 *   @0xcaee0 vmov r0, s15
 *   @0xcaee4 rev r0, r0
 *   @0xcaee8 add r8, sp, #16
 *   @0xcaeec mov r9, #4
 *   @0xcaef0 str r0, [r8, #-0x10]!
 *   @0xcaef4 b 0xcaddc <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x98>
 *   @0xcaef8 ldm r2, {r4, r5}
 *   @0xcaefc vmov d6, r4, r5
 *   @0xcaf00 vcvt.s32.f64 s13, d6
 *   @0xcaf04 vmov r4, s13
 *   @0xcaf08 rev r4, r4
 *   @0xcaf0c add r8, sp, #16
 *   @0xcaf10 mov r9, #4
 *   @0xcaf14 str r4, [r8, #-0x10]!
 *   @0xcaf18 b 0xcaddc <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x98>
 *   @0xcaf1c ldm r2, {r4, r5}
 *   @0xcaf20 vmov d7, r4, r5
 *   @0xcaf24 vcvt.f32.f64 s15, d7
 *   @0xcaf28 vmov r4, s15
 *   @0xcaf2c rev r4, r4
 *   @0xcaf30 add r8, sp, #16
 *   @0xcaf34 mov r9, #4
 *   @0xcaf38 str r4, [r8, #-0x10]!
 *   @0xcaf3c b 0xcaddc <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x98>
 *   @0xcaf40 ldm r2, {r4, r5}
 *   @0xcaf44 vmov d6, r4, r5
 *   @0xcaf48 vcvt.f32.f64 s14, d6
 *   @0xcaf4c vcvt.f64.f32 d7, s14
 *   @0xcaf50 vstr d7, [sp, #8]
 *   @0xcaf54 ldr r3, [sp, #0x8]
 *   @0xcaf58 rev r3, r3
 *   @0xcaf5c str r3, [sp]
 *   @0xcaf60 ldr r3, [sp, #0xc]
 *   @0xcaf64 rev r3, r3
 *   @0xcaf68 mov r9, #8
 *   @0xcaf6c str r3, [sp, #0x4]
 *   @0xcaf70 mov r8, sp
 *   @0xcaf74 b 0xcaddc <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x98>
 *   @0xcaf78 vmov.f64 d7, #5.000000e-01
 *   @0xcaf7c ldm r2, {r0, r1}
 *   @0xcaf80 vmov d6, r0, r1
 *   @0xcaf84 vcmpe.f64 d6, d7
 *   @0xcaf88 vmrs APSR_nzcv, fpscr
 *   @0xcaf8c addgt r8, sp, #16
 *   @0xcaf90 addle r8, sp, #16
 *   @0xcaf94 movgt r9, #1
 *   @0xcaf98 movle r3, #0
 *   @0xcaf9c strbgt r9, [r8, #-0x10]!
 *   @0xcafa0 movle r9, #1
 *   @0xcafa4 strble r3, [r8, #-0x10]!
 *   @0xcafa8 b 0xcaddc <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x98>
 *   @0xcafac ldr r3, [r2, #0xc]
 *   @0xcafb0 bic r3, r3, #-16777216
 *   @0xcafb4 cmp r3, #1
 *   @0xcafb8 movne r8, #0
 *   @0xcafbc beq 0xcb028 <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x2e4>
 *   @0xcafc0 mov r0, r8
 *   @0xcafc4 bl 0xb6538 <strlen@plt>
 *   @0xcafc8 add r9, r0, #1
 *   @0xcafcc b 0xcaddc <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x98>
 *   @0xcafd0 ldm r2, {r0, r1}
 *   @0xcafd4 bl 0x319550 <__fixunsdfdi>
 *   @0xcafd8 str r1, [sp, #0xc]
 *   @0xcafdc str r0, [sp, #0x8]
 *   @0xcafe0 rev r0, r0
 *   @0xcafe4 str r0, [sp]
 *   @0xcafe8 mov r3, r1
 *   @0xcafec rev r3, r3
 *   @0xcaff0 mov r9, #8
 *   @0xcaff4 str r3, [sp, #0x4]
 *   @0xcaff8 mov r8, sp
 *   @0xcaffc b 0xcaddc <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x98>
 *   @0xcb000 ldr r3, [r6]
 *   @0xcb004 lsl r1, r1, #1
 *   @0xcb008 str r7, [r6, #0x10]
 *   @0xcb00c mov r0, r6
 *   @0xcb010 ldr r3, [r3, #0x34]
 *   @0xcb014 blx r3
 *   @0xcb018 ldr r7, [r6, #0x1c]
 *   @0xcb01c b 0xcadec <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0xa8>
 *   @0xcb020 mvn r0, #0
 *   @0xcb024 b 0xcae3c <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0xf8>
 *   @0xcb028 ldr r8, [r2]
 *   @0xcb02c cmp r8, #0
 *   @0xcb030 ldrne r8, [r8]
 *   @0xcb034 b 0xcafc0 <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x27c>
 *   @0xcb038 ldr r8, [r2]
 *   @0xcb03c cmp r8, #0
 *   @0xcb040 ldrne r8, [r8]
 *   @0xcb044 b 0xcadd0 <_ZN14Buffer_Network5WriteE12eBuffer_TypeP6RValue+0x8c>
 *
 * ══ §22/39 Eff_Effect04(int, float, float, int, unsigned int)  0x1a0e64  size 772  193 条（0x1a0e64..0x1a1168）
 * @func 0x1a0e64 0x1a1168  size 772  193 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1a0e8c→0x542440
 * 调用序列: 0xb66e8×6 / YYRandom(int)×6 / ParticleType_Shape(int, int)×3 / ParticleType_Size(int, float, float, float, float)×3 / ParticleType_Alpha2(int, float, float)×3 / ParticleType_Life(int, int, int)×3 / ParticleSystem_Particles_Create_Color(int, float, float, int, unsigned int, int)×3 / Speed_Factor()
 * 字段偏移 top8: 0x4×5 / 0x8×5 / 0x38×1 / 0x2cc×1 / 0x2c0×1
 * VFP 指令 64 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a0e64 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1a0e68 vpush {d8, d9}
 *   @0x1a0e6c sub sp, sp, #8
 *   @0x1a0e70 mov r4, r3
 *   @0x1a0e74 vmov s19, r1
 *   @0x1a0e78 mov r6, r0
 *   @0x1a0e7c ldr r7, [sp, #0x38]
 *   @0x1a0e80 vmov s18, r2
 *   @0x1a0e84 bl 0x19ff6c <_Z12Speed_Factorv>
 *   @0x1a0e88 cmp r4, #0
 *   @0x1a0e8c ldr r3, [pc, #0x2cc]
 *   @0x1a0e90 mov r1, #10
 *   @0x1a0e94 mov r9, #0
 *   @0x1a0e98 vmov s16, r0
 *   @0x1a0e9c ldr r0, [pc, #0x2c0]
 *   @0x1a0ea0 add r0, pc, r0
 *   @0x1a0ea4 beq 0x1a0f94 <_Z12Eff_Effect04iffij+0x130>
 *   @0x1a0ea8 cmp r4, #2
 *   @0x1a0eac beq 0x1a1078 <_Z12Eff_Effect04iffij+0x214>
 *   @0x1a0eb0 ldr r5, [r0, r3]
 *   @0x1a0eb4 mov r4, #11
 *   @0x1a0eb8 mov r8, #1
 *   @0x1a0ebc ldr r0, [r5, #0x4]
 *   @0x1a0ec0 bl 0x1a31a4 <_Z18ParticleType_Shapeii>
 *   @0x1a0ec4 vldr s15, [pc, #652]
 *   @0x1a0ec8 vmul.f32 s15, s16, s15
 *   @0x1a0ecc ldr r0, [r5, #0x4]
 *   @0x1a0ed0 movw r1, #0xcccd
 *   @0x1a0ed4 str r9, [sp]
 *   @0x1a0ed8 movt r1, #0x3ecc
 *   @0x1a0edc movw r2, #0x3333
 *   @0x1a0ee0 movt r2, #0x3f33
 *   @0x1a0ee4 vmov r3, s15
 *   @0x1a0ee8 bl 0x1a322c <_Z17ParticleType_Sizeiffff>
 *   @0x1a0eec mov r2, r9
 *   @0x1a0ef0 ldr r0, [r5, #0x4]
 *   @0x1a0ef4 movw r1, #0xcccd
 *   @0x1a0ef8 movt r1, #0x3ecc
 *   @0x1a0efc bl 0x1a36a4 <_Z19ParticleType_Alpha2iff>
 *   @0x1a0f00 vmov.f32 s15, #3.000000e+01
 *   @0x1a0f04 ldr r10, [r5, #0x4]
 *   @0x1a0f08 vdiv.f32 s16, s15, s16
 *   @0x1a0f0c vcvt.f64.f32 d8, s16
 *   @0x1a0f10 vmov r0, r1, d8
 *   @0x1a0f14 bl 0xb66e8 <lrint@plt>
 *   @0x1a0f18 mov r9, r0
 *   @0x1a0f1c vmov r0, r1, d8
 *   @0x1a0f20 bl 0xb66e8 <lrint@plt>
 *   @0x1a0f24 mov r1, r9
 *   @0x1a0f28 vmov.f32 s17, #1.500000e+01
 *   @0x1a0f2c mov r2, r0
 *   @0x1a0f30 mov r0, r10
 *   @0x1a0f34 bl 0x1a32b4 <_Z17ParticleType_Lifeiii>
 *   @0x1a0f38 vsub.f32 s19, s19, s17
 *   @0x1a0f3c mov r0, #30
 *   @0x1a0f40 bl 0xc4600 <_Z8YYRandomi>
 *   @0x1a0f44 vmov s15, r0
 *   @0x1a0f48 mov r0, #30
 *   @0x1a0f4c vcvt.f32.u32 s16, s15
 *   @0x1a0f50 bl 0xc4600 <_Z8YYRandomi>
 *   @0x1a0f54 ldr r3, [r5, #0x4]
 *   @0x1a0f58 stm sp, {r7, r8}
 *   @0x1a0f5c vsub.f32 s14, s18, s17
 *   @0x1a0f60 vadd.f32 s16, s19, s16
 *   @0x1a0f64 vmov r1, s16
 *   @0x1a0f68 vmov s13, r0
 *   @0x1a0f6c mov r0, r6
 *   @0x1a0f70 vcvt.f32.u32 s15, s13
 *   @0x1a0f74 vadd.f32 s15, s14, s15
 *   @0x1a0f78 vmov r2, s15
 *   @0x1a0f7c bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji>
 *   @0x1a0f80 subs r4, r4, #1
 *   @0x1a0f84 bne 0x1a0f3c <_Z12Eff_Effect04iffij+0xd8>
 *   @0x1a0f88 add sp, sp, #8
 *   @0x1a0f8c vpop {d8, d9}
 *   @0x1a0f90 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1a0f94 ldr r5, [r0, r3]
 *   @0x1a0f98 mov r4, #6
 *   @0x1a0f9c mov r8, #1
 *   @0x1a0fa0 ldr r0, [r5]
 *   @0x1a0fa4 bl 0x1a31a4 <_Z18ParticleType_Shapeii>
 *   @0x1a0fa8 vldr s15, [pc, #424]
 *   @0x1a0fac vmul.f32 s15, s16, s15
 *   @0x1a0fb0 ldr r0, [r5]
 *   @0x1a0fb4 movw r1, #0xcccd
 *   @0x1a0fb8 str r9, [sp]
 *   @0x1a0fbc movt r1, #0x3e4c
 *   @0x1a0fc0 movw r2, #0xcccd
 *   @0x1a0fc4 movt r2, #0x3ecc
 *   @0x1a0fc8 vmov r3, s15
 *   @0x1a0fcc bl 0x1a322c <_Z17ParticleType_Sizeiffff>
 *   @0x1a0fd0 mov r2, r9
 *   @0x1a0fd4 ldr r0, [r5]
 *   @0x1a0fd8 movw r1, #0xcccd
 *   @0x1a0fdc movt r1, #0x3ecc
 *   @0x1a0fe0 bl 0x1a36a4 <_Z19ParticleType_Alpha2iff>
 *   @0x1a0fe4 vmov.f32 s15, #2.500000e+01
 *   @0x1a0fe8 ldr r10, [r5]
 *   @0x1a0fec vdiv.f32 s16, s15, s16
 *   @0x1a0ff0 vcvt.f64.f32 d8, s16
 *   @0x1a0ff4 vmov r0, r1, d8
 *   @0x1a0ff8 bl 0xb66e8 <lrint@plt>
 *   @0x1a0ffc mov r9, r0
 *   @0x1a1000 vmov r0, r1, d8
 *   @0x1a1004 bl 0xb66e8 <lrint@plt>
 *   @0x1a1008 mov r1, r9
 *   @0x1a100c vmov.f32 s17, #5.000000e+00
 *   @0x1a1010 mov r2, r0
 *   @0x1a1014 mov r0, r10
 *   @0x1a1018 bl 0x1a32b4 <_Z17ParticleType_Lifeiii>
 *   @0x1a101c vsub.f32 s19, s19, s17
 *   @0x1a1020 mov r0, #10
 *   @0x1a1024 bl 0xc4600 <_Z8YYRandomi>
 *   @0x1a1028 vmov s13, r0
 *   @0x1a102c mov r0, #10
 *   @0x1a1030 vcvt.f32.u32 s16, s13
 *   @0x1a1034 bl 0xc4600 <_Z8YYRandomi>
 *   @0x1a1038 ldr r3, [r5]
 *   @0x1a103c stm sp, {r7, r8}
 *   @0x1a1040 vsub.f32 s14, s18, s17
 *   @0x1a1044 vadd.f32 s16, s19, s16
 *   @0x1a1048 vmov r1, s16
 *   @0x1a104c vmov s13, r0
 *   @0x1a1050 mov r0, r6
 *   @0x1a1054 vcvt.f32.u32 s15, s13
 *   @0x1a1058 vadd.f32 s15, s14, s15
 *   @0x1a105c vmov r2, s15
 *   @0x1a1060 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji>
 *   @0x1a1064 subs r4, r4, #1
 *   @0x1a1068 bne 0x1a1020 <_Z12Eff_Effect04iffij+0x1bc>
 *   @0x1a106c add sp, sp, #8
 *   @0x1a1070 vpop {d8, d9}
 *   @0x1a1074 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1a1078 ldr r5, [r0, r3]
 *   @0x1a107c mov r4, #16
 *   @0x1a1080 mov r8, #1
 *   @0x1a1084 ldr r0, [r5, #0x8]
 *   @0x1a1088 bl 0x1a31a4 <_Z18ParticleType_Shapeii>
 *   @0x1a108c vldr s15, [pc, #196]
 *   @0x1a1090 vmul.f32 s15, s16, s15
 *   @0x1a1094 ldr r0, [r5, #0x8]
 *   @0x1a1098 mov r2, #1065353216
 *   @0x1a109c str r9, [sp]
 *   @0x1a10a0 movw r1, #0xcccd
 *   @0x1a10a4 movt r1, #0x3ecc
 *   @0x1a10a8 vmov r3, s15
 *   @0x1a10ac bl 0x1a322c <_Z17ParticleType_Sizeiffff>
 *   @0x1a10b0 mov r2, r9
 *   @0x1a10b4 ldr r0, [r5, #0x8]
 *   @0x1a10b8 movw r1, #0xcccd
 *   @0x1a10bc movt r1, #0x3ecc
 *   @0x1a10c0 bl 0x1a36a4 <_Z19ParticleType_Alpha2iff>
 *   @0x1a10c4 vldr s15, [pc, #144]
 *   @0x1a10c8 vdiv.f32 s16, s15, s16
 *   @0x1a10cc ldr r10, [r5, #0x8]
 *   @0x1a10d0 vcvt.f64.f32 d8, s16
 *   @0x1a10d4 vmov r0, r1, d8
 *   @0x1a10d8 bl 0xb66e8 <lrint@plt>
 *   @0x1a10dc mov r9, r0
 *   @0x1a10e0 vmov r0, r1, d8
 *   @0x1a10e4 bl 0xb66e8 <lrint@plt>
 *   @0x1a10e8 mov r1, r9
 *   @0x1a10ec vmov.f32 s17, #3.000000e+01
 *   @0x1a10f0 mov r2, r0
 *   @0x1a10f4 mov r0, r10
 *   @0x1a10f8 bl 0x1a32b4 <_Z17ParticleType_Lifeiii>
 *   @0x1a10fc vsub.f32 s19, s19, s17
 *   @0x1a1100 mov r0, #60
 *   @0x1a1104 bl 0xc4600 <_Z8YYRandomi>
 *   @0x1a1108 vmov s15, r0
 *   @0x1a110c mov r0, #60
 *   @0x1a1110 vcvt.f32.u32 s16, s15
 *   @0x1a1114 bl 0xc4600 <_Z8YYRandomi>
 *   @0x1a1118 ldr r3, [r5, #0x8]
 *   @0x1a111c stm sp, {r7, r8}
 *   @0x1a1120 vsub.f32 s14, s18, s17
 *   @0x1a1124 vadd.f32 s16, s19, s16
 *   @0x1a1128 vmov r1, s16
 *   @0x1a112c vmov s13, r0
 *   @0x1a1130 mov r0, r6
 *   @0x1a1134 vcvt.f32.u32 s15, s13
 *   @0x1a1138 vadd.f32 s15, s14, s15
 *   @0x1a113c vmov r2, s15
 *   @0x1a1140 bl 0x1a3f48 <_Z37ParticleSystem_Particles_Create_Coloriffiji>
 *   @0x1a1144 subs r4, r4, #1
 *   @0x1a1148 bne 0x1a1100 <_Z12Eff_Effect04iffij+0x29c>
 *   @0x1a114c add sp, sp, #8
 *   @0x1a1150 vpop {d8, d9}
 *   @0x1a1154 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1a1158 stclt p7, c13, [r3], #-40
 *   @0x1a115c submi r0, r8, #0
 *   @0x1a1160 .word 0xffffeb30
 *   @0x1a1164 .word 0x00250db0
 *
 * ══ §23/39 Audio_CreatePlayQueue(int, int, int)  0x21cb8c  size 772  193 条（0x21cb8c..0x21ce90）
 * @func 0x21cb8c 0x21ce90  size 772  193 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int)×2 / cAudio_Sound::cAudio_Sound()×2 / MemoryManager::Free(void const*)×2 / Error_Show(char const*, bool)×2 / Audio_CreatePlayQueue(int, int, int)+0x80 / Audio_CreatePlayQueue(int, int, int)+0x168 / cAudio_Sound::~cAudio_Sound() / operator delete(void*)
 * 字段偏移 top8: 0x34×11 / 0x30×4 / 0xc×3 / 0x10×2 / 0x8×2 / 0x14×2 / 0x2×2 / 0x50×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21cb8c cmp r2, #2
 *   @0x21cb90 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x21cb94 mov r7, r2
 *   @0x21cb98 sub sp, sp, #28
 *   @0x21cb9c mov r5, r0
 *   @0x21cba0 mov r6, r1
 *   @0x21cba4 bhi 0x21cdec <_Z21Audio_CreatePlayQueueiii+0x260>
 *   @0x21cba8 cmp r1, #1000
 *   @0x21cbac movlt r6, #1000
 *   @0x21cbb0 bge 0x21cd88 <_Z21Audio_CreatePlayQueueiii+0x1fc>
 *   @0x21cbb4 cmp r5, #4
 *   @0x21cbb8 cmpne r5, #1
 *   @0x21cbbc moveq r3, #0
 *   @0x21cbc0 movne r3, #1
 *   @0x21cbc4 bne 0x21ce04 <_Z21Audio_CreatePlayQueueiii+0x278>
 *   @0x21cbc8 ldr r2, [pc, #0x28c]
 *   @0x21cbcc add r2, pc, r2
 *   @0x21cbd0 ldr r0, [r2, #0x30]
 *   @0x21cbd4 cmp r0, #0
 *   @0x21cbd8 ble 0x21cc0c <_Z21Audio_CreatePlayQueueiii+0x80>
 *   @0x21cbdc ldr r2, [r2, #0x34]
 *   @0x21cbe0 ldr r8, [r2]
 *   @0x21cbe4 cmp r8, #0
 *   @0x21cbe8 bne 0x21cbfc <_Z21Audio_CreatePlayQueueiii+0x70>
 *   @0x21cbec b 0x21ce50 <_Z21Audio_CreatePlayQueueiii+0x2c4>
 *   @0x21cbf0 ldr r1, [r2, #0x4]!
 *   @0x21cbf4 cmp r1, #0
 *   @0x21cbf8 beq 0x21ce1c <_Z21Audio_CreatePlayQueueiii+0x290>
 *   @0x21cbfc add r3, r3, #1
 *   @0x21cc00 cmp r3, r0
 *   @0x21cc04 lsl r8, r3, #2
 *   @0x21cc08 bne 0x21cbf0 <_Z21Audio_CreatePlayQueueiii+0x64>
 *   @0x21cc0c mov r0, #96
 *   @0x21cc10 ldr r9, [pc, #0x248]
 *   @0x21cc14 bl 0x27c524 <_Znwj>
 *   @0x21cc18 add r9, pc, r9
 *   @0x21cc1c mov r4, r0
 *   @0x21cc20 bl 0x218ea4 <_ZN12cAudio_SoundC2Ev>
 *   @0x21cc24 ldr r8, [r9, #0x30]
 *   @0x21cc28 adds r11, r8, #1
 *   @0x21cc2c bne 0x21cdbc <_Z21Audio_CreatePlayQueueiii+0x230>
 *   @0x21cc30 ldr r3, [r9, #0x34]
 *   @0x21cc34 cmp r3, #0
 *   @0x21cc38 beq 0x21cd9c <_Z21Audio_CreatePlayQueueiii+0x210>
 *   @0x21cc3c cmp r8, #0
 *   @0x21cc40 ble 0x21ccf4 <_Z21Audio_CreatePlayQueueiii+0x168>
 *   @0x21cc44 ldr r2, [pc, #0x218]
 *   @0x21cc48 mov r12, r9
 *   @0x21cc4c ldr r10, [pc, #0x214]
 *   @0x21cc50 mov r9, r11
 *   @0x21cc54 add r2, pc, r2
 *   @0x21cc58 str r8, [sp, #0xc]
 *   @0x21cc5c add r10, pc, r10
 *   @0x21cc60 str r5, [sp, #0x10]
 *   @0x21cc64 mov r8, r2
 *   @0x21cc68 mov r5, r12
 *   @0x21cc6c str r4, [sp, #0x8]
 *   @0x21cc70 str r6, [sp, #0x14]
 *   @0x21cc74 ldr r0, [r3]
 *   @0x21cc78 movw r1, #0xfeee
 *   @0x21cc7c movt r1, #0xfeee
 *   @0x21cc80 movw r2, #0xfeee
 *   @0x21cc84 cmp r0, r1
 *   @0x21cc88 movt r2, #0xfeee
 *   @0x21cc8c lsl r6, r9, #2
 *   @0x21cc90 beq 0x21ccd4 <_Z21Audio_CreatePlayQueueiii+0x148>
 *   @0x21cc94 ldr r4, [r3, r9, lsl #2]
 *   @0x21cc98 add lr, r3, r6
 *   @0x21cc9c cmp r4, #0
 *   @0x21cca0 mov r0, r4
 *   @0x21cca4 beq 0x21ccd4 <_Z21Audio_CreatePlayQueueiii+0x148>
 *   @0x21cca8 ldr r3, [r4]
 *   @0x21ccac cmp r3, r2
 *   @0x21ccb0 beq 0x21ccc8 <_Z21Audio_CreatePlayQueueiii+0x13c>
 *   @0x21ccb4 bl 0x218f24 <_ZN12cAudio_SoundD2Ev>
 *   @0x21ccb8 mov r0, r4
 *   @0x21ccbc bl 0x27d1d0 <_ZdlPv>
 *   @0x21ccc0 ldr lr, [r10, #0x34]
 *   @0x21ccc4 add lr, lr, r6
 *   @0x21ccc8 mov r3, #0
 *   @0x21cccc str r3, [lr]
 *   @0x21ccd0 ldr r3, [r8, #0x34]
 *   @0x21ccd4 ldr r2, [r5, #0x30]
 *   @0x21ccd8 add r9, r9, #1
 *   @0x21ccdc cmp r9, r2
 *   @0x21cce0 blt 0x21cc74 <_Z21Audio_CreatePlayQueueiii+0xe8>
 *   @0x21cce4 ldr r4, [sp, #0x8]
 *   @0x21cce8 ldr r8, [sp, #0xc]
 *   @0x21ccec ldr r5, [sp, #0x10]
 *   @0x21ccf0 ldr r6, [sp, #0x14]
 *   @0x21ccf4 mov r0, r3
 *   @0x21ccf8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21ccfc ldr r1, [pc, #0x168]
 *   @0x21cd00 mov r2, #0
 *   @0x21cd04 add r1, pc, r1
 *   @0x21cd08 mov r3, r2
 *   @0x21cd0c str r2, [r1, #0x34]
 *   @0x21cd10 ldr r2, [pc, #0x158]
 *   @0x21cd14 add r9, r8, #199680
 *   @0x21cd18 add r9, r9, #320
 *   @0x21cd1c add r2, pc, r2
 *   @0x21cd20 str r11, [r2, #0x30]
 *   @0x21cd24 str r4, [r3, r8, lsl #2]
 *   @0x21cd28 ldr r3, [pc, #0x144]
 *   @0x21cd2c mov r1, #1
 *   @0x21cd30 mov r12, #0
 *   @0x21cd34 mvn r2, #0
 *   @0x21cd38 ldr r3, [pc, r3]
 *   @0x21cd3c str r12, [r4, #0x58]
 *   @0x21cd40 str r2, [r4, #0x18]
 *   @0x21cd44 mov r2, r9
 *   @0x21cd48 ldr r0, [r3]
 *   @0x21cd4c mov r3, #0
 *   @0x21cd50 str r3, [r4, #0x34]
 *   @0x21cd54 str r6, [r4, #0x38]
 *   @0x21cd58 ldr r3, [r0]
 *   @0x21cd5c str r1, [r4, #0x3c]
 *   @0x21cd60 strb r1, [r4, #0x5c]
 *   @0x21cd64 ldr r1, [pc, #0x10c]
 *   @0x21cd68 str r5, [r4, #0x50]
 *   @0x21cd6c str r7, [r4, #0x54]
 *   @0x21cd70 add r1, pc, r1
 *   @0x21cd74 ldr r3, [r3, #0xc]
 *   @0x21cd78 blx r3
 *   @0x21cd7c mov r0, r9
 *   @0x21cd80 add sp, sp, #28
 *   @0x21cd84 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x21cd88 movw r3, #0xbb80
 *   @0x21cd8c cmp r6, r3
 *   @0x21cd90 movge r6, r3
 *   @0x21cd94 b 0x21cbb4 <_Z21Audio_CreatePlayQueueiii+0x28>
 *   @0x21cd98 ldr r3, [r9, #0x34]
 *   @0x21cd9c mov r0, r3
 *   @0x21cda0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21cda4 ldr r1, [pc, #0xd0]
 *   @0x21cda8 mov r2, #0
 *   @0x21cdac add r1, pc, r1
 *   @0x21cdb0 mov r3, r2
 *   @0x21cdb4 str r2, [r1, #0x34]
 *   @0x21cdb8 b 0x21cd10 <_Z21Audio_CreatePlayQueueiii+0x184>
 *   @0x21cdbc lsls r1, r11, #2
 *   @0x21cdc0 beq 0x21cd98 <_Z21Audio_CreatePlayQueueiii+0x20c>
 *   @0x21cdc4 ldr r2, [pc, #0xb4]
 *   @0x21cdc8 mov r3, #0
 *   @0x21cdcc ldr r0, [r9, #0x34]
 *   @0x21cdd0 add r2, pc, r2
 *   @0x21cdd4 str r3, [sp]
 *   @0x21cdd8 mov r3, #135
 *   @0x21cddc bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x21cde0 mov r3, r0
 *   @0x21cde4 str r0, [r9, #0x34]
 *   @0x21cde8 b 0x21cd10 <_Z21Audio_CreatePlayQueueiii+0x184>
 *   @0x21cdec ldr r0, [pc, #0x90]
 *   @0x21cdf0 mov r1, #0
 *   @0x21cdf4 add r0, pc, r0
 *   @0x21cdf8 bl 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x21cdfc mvn r0, #0
 *   @0x21ce00 b 0x21cd80 <_Z21Audio_CreatePlayQueueiii+0x1f4>
 *   @0x21ce04 ldr r0, [pc, #0x7c]
 *   @0x21ce08 mov r1, #0
 *   @0x21ce0c add r0, pc, r0
 *   @0x21ce10 bl 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x21ce14 mvn r0, #0
 *   @0x21ce18 b 0x21cd80 <_Z21Audio_CreatePlayQueueiii+0x1f4>
 *   @0x21ce1c add r3, r3, #199680
 *   @0x21ce20 add r9, r3, #320
 *   @0x21ce24 mov r0, #96
 *   @0x21ce28 bl 0x27c524 <_Znwj>
 *   @0x21ce2c mov r4, r0
 *   @0x21ce30 bl 0x218ea4 <_ZN12cAudio_SoundC2Ev>
 *   @0x21ce34 ldr r3, [pc, #0x50]
 *   @0x21ce38 cmp r4, #0
 *   @0x21ce3c add r3, pc, r3
 *   @0x21ce40 ldr r3, [r3, #0x34]
 *   @0x21ce44 str r4, [r3, r8]
 *   @0x21ce48 bne 0x21cd28 <_Z21Audio_CreatePlayQueueiii+0x19c>
 *   @0x21ce4c b 0x21cc0c <_Z21Audio_CreatePlayQueueiii+0x80>
 *   @0x21ce50 mov r9, #3392
 *   @0x21ce54 movt r9, #0x3
 *   @0x21ce58 b 0x21ce24 <_Z21Audio_CreatePlayQueueiii+0x298>
 *   @0x21ce5c subseq r8, r3, r8, asr #13
 *   @0x21ce60 subseq r8, r3, r12, ror r6
 *   @0x21ce64 subseq r8, r3, r0, asr #12
 *   @0x21ce68 subseq r8, r3, r8, lsr r6
 *   @0x21ce6c .word 0x00538590
 *   @0x21ce70 subseq r8, r3, r8, ror r5
 *   @0x21ce74 ldrsbeq r0, [sp], -r12
 *   @0x21ce78 andseq r7, r3, r8, lsr #14
 *   @0x21ce7c subseq r8, r3, r8, ror #9
 *   @0x21ce80 andseq r0, r3, r0, lsr #10
 *   @0x21ce84 andseq r7, r3, r8, lsl #12
 *   @0x21ce88 andseq r7, r3, r4, asr #12
 *   @0x21ce8c subseq r8, r3, r8, asr r4
 *
 * ══ §24/39 Sound_Add(char const*, int, bool)  0x21fd14  size 772  193 条（0x21fd14..0x220018）
 * @func 0x21fd14 0x220018  size 772  193 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×5 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)×2 / Sound_Add(char const*, int, bool)+0xe4 / CSound::~CSound() / operator delete(void*) / Sound_Add(char const*, int, bool)+0x74 / Sound_Add(char const*, int, bool)+0x1ac / MemoryManager::IsAllocated(void const*)
 * 字段偏移 top8: 0xc×12 / 0x10×8 / 0x4×8 / 0x2×5 / 0x8×3 / 0x14×2 / 0x2b4×1 / 0x270×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21fd14 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x21fd18 sub sp, sp, #28
 *   @0x21fd1c ldr r10, [pc, #0x2b4]
 *   @0x21fd20 mov r8, r0
 *   @0x21fd24 str r2, [sp, #0x10]
 *   @0x21fd28 add r10, pc, r10
 *   @0x21fd2c str r1, [sp, #0xc]
 *   @0x21fd30 ldr r7, [r10, #0x10]
 *   @0x21fd34 ldr r2, [r10]
 *   @0x21fd38 add r7, r7, #1
 *   @0x21fd3c str r7, [r10, #0x10]
 *   @0x21fd40 cmp r7, r2
 *   @0x21fd44 beq 0x21fe4c <_Z9Sound_AddPKcib+0x138>
 *   @0x21fd48 cmp r7, #0
 *   @0x21fd4c bne 0x21fe14 <_Z9Sound_AddPKcib+0x100>
 *   @0x21fd50 ldr r3, [r10, #0x4]
 *   @0x21fd54 cmp r3, #0
 *   @0x21fd58 beq 0x21ffb4 <_Z9Sound_AddPKcib+0x2a0>
 *   @0x21fd5c cmp r2, #0
 *   @0x21fd60 ble 0x21fdf8 <_Z9Sound_AddPKcib+0xe4>
 *   @0x21fd64 ldr r2, [pc, #0x270]
 *   @0x21fd68 mov r4, r7
 *   @0x21fd6c ldr r9, [pc, #0x26c]
 *   @0x21fd70 mov r11, r7
 *   @0x21fd74 add r2, pc, r2
 *   @0x21fd78 str r7, [sp, #0x14]
 *   @0x21fd7c add r9, pc, r9
 *   @0x21fd80 mov r7, r9
 *   @0x21fd84 mov r9, r2
 *   @0x21fd88 ldr r0, [r3]
 *   @0x21fd8c movw r1, #0xfeee
 *   @0x21fd90 movt r1, #0xfeee
 *   @0x21fd94 movw r12, #0xfeee
 *   @0x21fd98 cmp r0, r1
 *   @0x21fd9c movt r12, #0xfeee
 *   @0x21fda0 lsl r6, r4, #2
 *   @0x21fda4 beq 0x21fde4 <_Z9Sound_AddPKcib+0xd0>
 *   @0x21fda8 ldr r5, [r3, r4, lsl #2]
 *   @0x21fdac add r1, r3, r6
 *   @0x21fdb0 cmp r5, #0
 *   @0x21fdb4 mov r0, r5
 *   @0x21fdb8 beq 0x21fde4 <_Z9Sound_AddPKcib+0xd0>
 *   @0x21fdbc ldr r3, [r5]
 *   @0x21fdc0 cmp r3, r12
 *   @0x21fdc4 beq 0x21fddc <_Z9Sound_AddPKcib+0xc8>
 *   @0x21fdc8 bl 0x215384 <_ZN6CSoundD2Ev>
 *   @0x21fdcc mov r0, r5
 *   @0x21fdd0 bl 0x27d1d0 <_ZdlPv>
 *   @0x21fdd4 ldr r1, [r7, #0x4]
 *   @0x21fdd8 add r1, r1, r6
 *   @0x21fddc str r11, [r1]
 *   @0x21fde0 ldr r3, [r9, #0x4]
 *   @0x21fde4 ldr r1, [r10]
 *   @0x21fde8 add r4, r4, #1
 *   @0x21fdec cmp r4, r1
 *   @0x21fdf0 blt 0x21fd88 <_Z9Sound_AddPKcib+0x74>
 *   @0x21fdf4 ldr r7, [sp, #0x14]
 *   @0x21fdf8 mov r0, r3
 *   @0x21fdfc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21fe00 ldr r3, [pc, #0x1dc]
 *   @0x21fe04 mov r2, #0
 *   @0x21fe08 add r3, pc, r3
 *   @0x21fe0c str r2, [r3, #0x4]
 *   @0x21fe10 b 0x21fe3c <_Z9Sound_AddPKcib+0x128>
 *   @0x21fe14 lsls r1, r7, #2
 *   @0x21fe18 beq 0x21ffb0 <_Z9Sound_AddPKcib+0x29c>
 *   @0x21fe1c ldr r2, [pc, #0x1c4]
 *   @0x21fe20 mov r3, #0
 *   @0x21fe24 ldr r0, [r10, #0x4]
 *   @0x21fe28 add r2, pc, r2
 *   @0x21fe2c str r3, [sp]
 *   @0x21fe30 mov r3, #135
 *   @0x21fe34 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x21fe38 str r0, [r10, #0x4]
 *   @0x21fe3c ldr r3, [pc, #0x1a8]
 *   @0x21fe40 add r3, pc, r3
 *   @0x21fe44 str r7, [r3]
 *   @0x21fe48 ldr r7, [r3, #0x10]
 *   @0x21fe4c cmp r7, #0
 *   @0x21fe50 bne 0x21ff58 <_Z9Sound_AddPKcib+0x244>
 *   @0x21fe54 ldr r11, [pc, #0x194]
 *   @0x21fe58 add r11, pc, r11
 *   @0x21fe5c ldr r0, [r11, #0xc]
 *   @0x21fe60 cmp r0, #0
 *   @0x21fe64 beq 0x21ff98 <_Z9Sound_AddPKcib+0x284>
 *   @0x21fe68 ldr r3, [r11, #0x8]
 *   @0x21fe6c cmp r3, #0
 *   @0x21fe70 ble 0x21fec0 <_Z9Sound_AddPKcib+0x1ac>
 *   @0x21fe74 ldr r10, [pc, #0x178]
 *   @0x21fe78 mov r4, r7
 *   @0x21fe7c mov r6, r7
 *   @0x21fe80 add r10, pc, r10
 *   @0x21fe84 ldr r0, [r0, r4, lsl #2]
 *   @0x21fe88 lsl r5, r4, #2
 *   @0x21fe8c bl 0x27c454 <_ZN13MemoryManager11IsAllocatedEPKv>
 *   @0x21fe90 cmp r0, #0
 *   @0x21fe94 beq 0x21fea4 <_Z9Sound_AddPKcib+0x190>
 *   @0x21fe98 ldr r3, [r10, #0xc]
 *   @0x21fe9c ldr r0, [r3, r4, lsl #2]
 *   @0x21fea0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21fea4 ldr r2, [r11, #0x8]
 *   @0x21fea8 add r4, r4, #1
 *   @0x21feac ldr r3, [r11, #0xc]
 *   @0x21feb0 cmp r4, r2
 *   @0x21feb4 str r6, [r3, r5]
 *   @0x21feb8 ldr r0, [r11, #0xc]
 *   @0x21febc blt 0x21fe84 <_Z9Sound_AddPKcib+0x170>
 *   @0x21fec0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21fec4 ldr r3, [pc, #0x12c]
 *   @0x21fec8 mov r2, #0
 *   @0x21fecc add r3, pc, r3
 *   @0x21fed0 str r2, [r3, #0xc]
 *   @0x21fed4 ldr r4, [pc, #0x120]
 *   @0x21fed8 mov r0, r8
 *   @0x21fedc add r4, pc, r4
 *   @0x21fee0 str r7, [r4, #0x8]
 *   @0x21fee4 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x21fee8 ldr r5, [r4, #0x10]
 *   @0x21feec ldr r3, [r4, #0xc]
 *   @0x21fef0 sub r5, r5, #1
 *   @0x21fef4 str r0, [r3, r5, lsl #2]
 *   @0x21fef8 mov r0, #64
 *   @0x21fefc bl 0x27c524 <_Znwj>
 *   @0x21ff00 mov r6, r0
 *   @0x21ff04 bl 0x215354 <_ZN6CSoundC2Ev>
 *   @0x21ff08 ldr r3, [r4, #0x10]
 *   @0x21ff0c ldm r4, {r1, r2}
 *   @0x21ff10 sub r3, r3, #1
 *   @0x21ff14 cmp r3, r1
 *   @0x21ff18 mov r1, r8
 *   @0x21ff1c str r6, [r2, r5, lsl #2]
 *   @0x21ff20 ldrlt r2, [r4, #0x4]
 *   @0x21ff24 movge r0, #0
 *   @0x21ff28 ldrlt r0, [r2, r3, lsl #2]
 *   @0x21ff2c ldr r2, [sp, #0xc]
 *   @0x21ff30 ldr r3, [sp, #0x10]
 *   @0x21ff34 bl 0x21569c <_ZN6CSound12LoadFromFileEPKcib>
 *   @0x21ff38 cmp r0, #0
 *   @0x21ff3c beq 0x21ffd0 <_Z9Sound_AddPKcib+0x2bc>
 *   @0x21ff40 ldr r3, [pc, #0xb8]
 *   @0x21ff44 add r3, pc, r3
 *   @0x21ff48 ldr r0, [r3, #0x10]
 *   @0x21ff4c sub r0, r0, #1
 *   @0x21ff50 add sp, sp, #28
 *   @0x21ff54 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x21ff58 lsls r1, r7, #2
 *   @0x21ff5c beq 0x21ff8c <_Z9Sound_AddPKcib+0x278>
 *   @0x21ff60 ldr r4, [pc, #0x9c]
 *   @0x21ff64 mov r3, #0
 *   @0x21ff68 ldr r2, [pc, #0x98]
 *   @0x21ff6c add r4, pc, r4
 *   @0x21ff70 str r3, [sp]
 *   @0x21ff74 add r2, pc, r2
 *   @0x21ff78 mov r3, #92
 *   @0x21ff7c ldr r0, [r4, #0xc]
 *   @0x21ff80 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x21ff84 str r0, [r4, #0xc]
 *   @0x21ff88 b 0x21fed4 <_Z9Sound_AddPKcib+0x1c0>
 *   @0x21ff8c ldr r3, [pc, #0x78]
 *   @0x21ff90 add r3, pc, r3
 *   @0x21ff94 ldr r0, [r3, #0xc]
 *   @0x21ff98 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21ff9c ldr r3, [pc, #0x6c]
 *   @0x21ffa0 mov r2, #0
 *   @0x21ffa4 add r3, pc, r3
 *   @0x21ffa8 str r2, [r3, #0xc]
 *   @0x21ffac b 0x21fed4 <_Z9Sound_AddPKcib+0x1c0>
 *   @0x21ffb0 ldr r3, [r10, #0x4]
 *   @0x21ffb4 mov r0, r3
 *   @0x21ffb8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x21ffbc ldr r3, [pc, #0x50]
 *   @0x21ffc0 mov r2, #0
 *   @0x21ffc4 add r3, pc, r3
 *   @0x21ffc8 str r2, [r3, #0x4]
 *   @0x21ffcc b 0x21fe3c <_Z9Sound_AddPKcib+0x128>
 *   @0x21ffd0 mvn r0, #0
 *   @0x21ffd4 b 0x21ff50 <_Z9Sound_AddPKcib+0x23c>
 *   @0x21ffd8 subseq r5, r3, r0, lsl r6
 *   @0x21ffdc subseq r5, r3, r4, asr #11
 *   @0x21ffe0 ldrheq r5, [r3], #-92
 *   @0x21ffe4 subseq r5, r3, r0, lsr r5
 *   @0x21ffe8 andseq r4, r3, r4, ror #18
 *   @0x21ffec ldrsheq r5, [r3], #-72
 *   @0x21fff0 subseq r5, r3, r0, ror #9
 *   @0x21fff4 ldrheq r5, [r3], #-72
 *   @0x21fff8 subseq r5, r3, r12, ror #8
 *   @0x21fffc subseq r5, r3, r12, asr r4
 *   @0x220000 ldrsheq r5, [r3], #-52
 *   @0x220004 subseq r5, r3, r12, asr #7
 *   @0x220008 andseq r3, r3, r0, ror #27
 *   @0x22000c subseq r5, r3, r8, lsr #7
 *   @0x220010 .word 0x00535394
 *   @0x220014 subseq r5, r3, r4, ror r3
 *
 * ══ §25/39 JS_String_fromCharCode(RValue&, CInstance*, CInstance*, int, RValue*)  0x24d988  size 772  193 条（0x24d988..0x24dc8c）
 * @func 0x24d988 0x24dc8c  size 772  193 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_String_fromCharCode(RValue&, CInstance*, CInstance*, int, RValue*)+0x1e0×2 / 0xb65b0 / JS_String_fromCharCode(RValue&, CInstance*, CInstance*, int, RValue*)+0x170 / JS_ToUint16(RValue&, RValue&) / JS_String_fromCharCode(RValue&, CInstance*, CInstance*, int, RValue*)+0x110 / YYCreateString(RValue*, char const*) / 0xb65d4
 * 字段偏移 top8: 0x-5c×11 / 0x-60×8 / 0x-68×3 / 0x-6c×2 / 0x-40×2 / 0x-64×2 / 0x-70×2 / 0x1×2
 * VFP 指令 18 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24d988 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x24d98c vpush {d8, d9, d10}
 *   @0x24d990 mov r4, r3
 *   @0x24d994 add r11, sp, #56
 *   @0x24d998 ldr r3, [pc, #0x2e8]
 *   @0x24d99c sub sp, sp, #60
 *   @0x24d9a0 add r2, r4, r4, lsl #1
 *   @0x24d9a4 str r0, [r11, #-0x6c]
 *   @0x24d9a8 ldr r3, [pc, r3]
 *   @0x24d9ac str r3, [r11, #-0x68]
 *   @0x24d9b0 mov r3, #1
 *   @0x24d9b4 str r3, [r0, #0xc]
 *   @0x24d9b8 ldr r0, [r11, #-0x68]
 *   @0x24d9bc lsl r2, r2, r3
 *   @0x24d9c0 add r1, r2, #15
 *   @0x24d9c4 add r2, r2, #1
 *   @0x24d9c8 bic r1, r1, #7
 *   @0x24d9cc ldr r3, [r0]
 *   @0x24d9d0 sub sp, sp, r1
 *   @0x24d9d4 mov r1, #0
 *   @0x24d9d8 str sp, [r11, #-0x60]
 *   @0x24d9dc mov r0, sp
 *   @0x24d9e0 str r3, [r11, #-0x40]
 *   @0x24d9e4 ldr r3, [r11, #0x4]
 *   @0x24d9e8 str r3, [r11, #-0x64]
 *   @0x24d9ec bl 0xb65b0 <memset@plt>
 *   @0x24d9f0 cmp r4, #0
 *   @0x24d9f4 ble 0x24daf8 <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0x170>
 *   @0x24d9f8 mov r2, #0
 *   @0x24d9fc movw r3, #0xfffe
 *   @0x24da00 str r2, [r11, #-0x5c]
 *   @0x24da04 mov r9, r2
 *   @0x24da08 mov r10, r2
 *   @0x24da0c movt r3, #0x1f
 *   @0x24da10 sub r2, r11, #80
 *   @0x24da14 str r3, [r11, #-0x70]
 *   @0x24da18 str r2, [r11, #-0x58]
 *   @0x24da1c vldr d8, [pc, #588]
 *   @0x24da20 vldr d9, [pc, #592]
 *   @0x24da24 vldr d10, [pc, #596]
 *   @0x24da28 ldr r3, [r11, #-0x64]
 *   @0x24da2c mov r7, #1
 *   @0x24da30 mov r5, #0
 *   @0x24da34 mvn r6, #-16777216
 *   @0x24da38 add r8, r3, r9, lsl #4
 *   @0x24da3c mov r3, r4
 *   @0x24da40 mov r4, r8
 *   @0x24da44 mov r8, r3
 *   @0x24da48 b 0x24da50 <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0xc8>
 *   @0x24da4c mov r7, r1
 *   @0x24da50 sub r0, r11, #80
 *   @0x24da54 mov r1, r4
 *   @0x24da58 str r10, [r11, #-0x50]
 *   @0x24da5c str r10, [r11, #-0x4c]
 *   @0x24da60 str r10, [r11, #-0x48]
 *   @0x24da64 str r6, [r11, #-0x44]
 *   @0x24da68 bl 0x24d8ec <_Z11JS_ToUint16R6RValueS0_>
 *   @0x24da6c vldr s14, [r11, #-80]
 *   @0x24da70 vldr s15, [r11, #-76]
 *   @0x24da74 vcmpe.f64 d7, d8
 *   @0x24da78 vmrs APSR_nzcv, fpscr
 *   @0x24da7c bls 0x24db68 <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0x1e0>
 *   @0x24da80 vcmpe.f64 d7, d9
 *   @0x24da84 vmrs APSR_nzcv, fpscr
 *   @0x24da88 ble 0x24da98 <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0x110>
 *   @0x24da8c vcmpe.f64 d7, d10
 *   @0x24da90 vmrs APSR_nzcv, fpscr
 *   @0x24da94 bls 0x24db68 <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0x1e0>
 *   @0x24da98 vcvt.s32.f64 s13, d7
 *   @0x24da9c vmov r2, s13
 *   @0x24daa0 ands r1, r2, #1024
 *   @0x24daa4 bne 0x24db78 <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0x1f0>
 *   @0x24daa8 add r9, r9, #1
 *   @0x24daac cmp r9, r8
 *   @0x24dab0 beq 0x24dc5c <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0x2d4>
 *   @0x24dab4 sub r5, r2, #55296
 *   @0x24dab8 cmp r8, r9
 *   @0x24dabc add r4, r4, #16
 *   @0x24dac0 lsl r5, r5, #10
 *   @0x24dac4 add r5, r5, #65536
 *   @0x24dac8 bgt 0x24da4c <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0xc4>
 *   @0x24dacc mov r4, r8
 *   @0x24dad0 cmp r5, #126
 *   @0x24dad4 bgt 0x24db24 <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0x19c>
 *   @0x24dad8 ldr r2, [r11, #-0x5c]
 *   @0x24dadc ldr r3, [r11, #-0x60]
 *   @0x24dae0 strb r5, [r3, r2]
 *   @0x24dae4 add r2, r2, #1
 *   @0x24dae8 str r2, [r11, #-0x5c]
 *   @0x24daec add r9, r9, #1
 *   @0x24daf0 cmp r4, r9
 *   @0x24daf4 bgt 0x24da28 <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x24daf8 ldr r0, [r11, #-0x6c]
 *   @0x24dafc ldr r1, [r11, #-0x60]
 *   @0x24db00 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x24db04 ldr r0, [r11, #-0x68]
 *   @0x24db08 ldr r2, [r11, #-0x40]
 *   @0x24db0c ldr r3, [r0]
 *   @0x24db10 cmp r2, r3
 *   @0x24db14 bne 0x24dc68 <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0x2e0>
 *   @0x24db18 sub sp, r11, #56
 *   @0x24db1c vpop {d8, d9, d10}
 *   @0x24db20 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x24db24 movw r2, #0x7fe
 *   @0x24db28 cmp r5, r2
 *   @0x24db2c bgt 0x24db90 <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0x208>
 *   @0x24db30 ldr r3, [r11, #-0x5c]
 *   @0x24db34 ubfx r2, r5, #0x6, #0x5
 *   @0x24db38 ldr r0, [r11, #-0x60]
 *   @0x24db3c and r5, r5, #63
 *   @0x24db40 add r1, r3, #1
 *   @0x24db44 mvn r2, r2, lsl #26
 *   @0x24db48 mvn r5, r5, lsl #25
 *   @0x24db4c mvn r2, r2, lsr #26
 *   @0x24db50 mvn r5, r5, lsr #25
 *   @0x24db54 strb r2, [r0, r3]
 *   @0x24db58 add r3, r3, #2
 *   @0x24db5c strb r5, [r0, r1]
 *   @0x24db60 str r3, [r11, #-0x5c]
 *   @0x24db64 b 0x24daec <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0x164>
 *   @0x24db68 vcvt.s32.f64 s13, d7
 *   @0x24db6c mov r4, r8
 *   @0x24db70 vmov r5, s13
 *   @0x24db74 b 0x24dad0 <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0x148>
 *   @0x24db78 cmp r7, #0
 *   @0x24db7c mov r4, r8
 *   @0x24db80 subeq r2, r2, #56320
 *   @0x24db84 orreq r5, r5, r2
 *   @0x24db88 movne r5, r2
 *   @0x24db8c b 0x24dad0 <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0x148>
 *   @0x24db90 movw r2, #0xfffe
 *   @0x24db94 cmp r5, r2
 *   @0x24db98 bgt 0x24dbec <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0x264>
 *   @0x24db9c ldr r3, [r11, #-0x5c]
 *   @0x24dba0 ubfx r12, r5, #0xc, #0x4
 *   @0x24dba4 ldr r1, [r11, #-0x60]
 *   @0x24dba8 ubfx r0, r5, #0x6, #0x6
 *   @0x24dbac mvn r12, r12, lsl #27
 *   @0x24dbb0 add lr, r3, #2
 *   @0x24dbb4 and r2, r5, #63
 *   @0x24dbb8 mvn r12, r12, lsr #27
 *   @0x24dbbc strb r12, [r1, r3]!
 *   @0x24dbc0 mvn r0, r0, lsl #25
 *   @0x24dbc4 ldr r3, [r11, #-0x60]
 *   @0x24dbc8 mvn r2, r2, lsl #25
 *   @0x24dbcc mvn r2, r2, lsr #25
 *   @0x24dbd0 mvn r0, r0, lsr #25
 *   @0x24dbd4 strb r0, [r1, #0x1]
 *   @0x24dbd8 strb r2, [r3, lr]
 *   @0x24dbdc ldr r2, [r11, #-0x5c]
 *   @0x24dbe0 add r2, r2, #3
 *   @0x24dbe4 str r2, [r11, #-0x5c]
 *   @0x24dbe8 b 0x24daec <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0x164>
 *   @0x24dbec ldr r3, [r11, #-0x70]
 *   @0x24dbf0 cmp r5, r3
 *   @0x24dbf4 bgt 0x24daec <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0x164>
 *   @0x24dbf8 and lr, r5, #3670016
 *   @0x24dbfc ldr r2, [r11, #-0x60]
 *   @0x24dc00 ldr r3, [r11, #-0x5c]
 *   @0x24dc04 ubfx r12, r5, #0xc, #0x6
 *   @0x24dc08 asr lr, lr, #18
 *   @0x24dc0c ubfx r0, r5, #0x6, #0x6
 *   @0x24dc10 and r1, r5, #63
 *   @0x24dc14 mvn r12, r12, lsl #25
 *   @0x24dc18 mvn lr, lr, lsl #28
 *   @0x24dc1c mvn r0, r0, lsl #25
 *   @0x24dc20 mvn lr, lr, lsr #28
 *   @0x24dc24 strb lr, [r2, r3]!
 *   @0x24dc28 add lr, r3, #3
 *   @0x24dc2c ldr r3, [r11, #-0x60]
 *   @0x24dc30 mvn r12, r12, lsr #25
 *   @0x24dc34 mvn r0, r0, lsr #25
 *   @0x24dc38 strb r12, [r2, #0x1]
 *   @0x24dc3c mvn r1, r1, lsl #25
 *   @0x24dc40 strb r0, [r2, #0x2]
 *   @0x24dc44 mvn r1, r1, lsr #25
 *   @0x24dc48 ldr r2, [r11, #-0x5c]
 *   @0x24dc4c strb r1, [r3, lr]
 *   @0x24dc50 add r2, r2, #4
 *   @0x24dc54 str r2, [r11, #-0x5c]
 *   @0x24dc58 b 0x24daec <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0x164>
 *   @0x24dc5c mov r4, r8
 *   @0x24dc60 vmov r5, s13
 *   @0x24dc64 b 0x24dad0 <_Z22JS_String_fromCharCodeR6RValueP9CInstanceS2_iPS_+0x148>
 *   @0x24dc68 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x24dc6c nop
 *   @0x24dc70 andeq r0, r0, r0
 *   @0x24dc74 rscmi pc, r10, r0, ror #31
 *   @0x24dc78 andeq r0, r0, r0
 *   @0x24dc7c rscmi r0, r12, r0
 *   @0x24dc80 andeq r0, r0, r0
 *   @0x24dc84 rscmi pc, pc, r0, ror #31
 *   @0x24dc88 andseq pc, r9, r8, lsr #31
 *
 * ══ §26/39 bucketCheck(char*)  0x27bee0  size 772  193 条（0x27bee0..0x27c1e4）
 * @func 0x27bee0 0x27c1e4  size 772  193 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x27bee8→0x7566ac, 0x27bef0→0x7566a8, 0x27bf00→0x756728, 0x27bf74→0x756714, 0x27bfe8→0x756700, 0x27c05c→0x7566ec, 0x27c0d0→0x7566d8, 0x27c144→0x7566c4
 * 调用序列: bucketCheck(char*)+0x6c / bucketCheck(char*)+0xe0 / bucketCheck(char*)+0x154 / bucketCheck(char*)+0x1c8 / bucketCheck(char*)+0x23c / bucketCheck(char*)+0x2b0
 * 字段偏移 top8: 0x8×6 / 0x4×6 / 0x2d8×1 / 0x2d4×1 / 0x2d0×1 / 0x2c4×1 / 0x254×1 / 0x1e4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27bee0 ldr r0, [pc, #0x2d8]
 *   @0x27bee4 mov r2, #8
 *   @0x27bee8 ldr r1, [pc, #0x2d4]
 *   @0x27beec add r0, pc, r0
 *   @0x27bef0 ldr r12, [pc, #0x2d0]
 *   @0x27bef4 push {r4, r5, r6, r7, r8}
 *   @0x27bef8 mov r8, #0
 *   @0x27befc ldr r1, [r0, r1]
 *   @0x27bf00 ldr r3, [pc, #0x2c4]
 *   @0x27bf04 str r8, [r1]
 *   @0x27bf08 ldr r12, [r0, r12]
 *   @0x27bf0c str r2, [r12]
 *   @0x27bf10 ldr r6, [r0, r3]
 *   @0x27bf14 ldr r5, [r6, #0x8]
 *   @0x27bf18 cmp r5, r8
 *   @0x27bf1c movne r7, #42
 *   @0x27bf20 beq 0x27bf74 <_Z11bucketCheckPc+0x94>
 *   @0x27bf24 ldr r3, [r6, #0x4]
 *   @0x27bf28 cmp r3, #0
 *   @0x27bf2c beq 0x27bf58 <_Z11bucketCheckPc+0x78>
 *   @0x27bf30 add r4, r3, #8
 *   @0x27bf34 add r2, r3, #131072
 *   @0x27bf38 cmp r5, r4
 *   @0x27bf3c add r2, r2, #8
 *   @0x27bf40 blo 0x27bf4c <_Z11bucketCheckPc+0x6c>
 *   @0x27bf44 cmp r2, r5
 *   @0x27bf48 bhi 0x27bf5c <_Z11bucketCheckPc+0x7c>
 *   @0x27bf4c ldr r3, [r3]
 *   @0x27bf50 cmp r3, #0
 *   @0x27bf54 bne 0x27bf30 <_Z11bucketCheckPc+0x50>
 *   @0x27bf58 str r7, [r8]
 *   @0x27bf5c ldr r5, [r5]
 *   @0x27bf60 ldr r3, [r1]
 *   @0x27bf64 cmp r5, #0
 *   @0x27bf68 add r3, r3, #1
 *   @0x27bf6c str r3, [r1]
 *   @0x27bf70 bne 0x27bf24 <_Z11bucketCheckPc+0x44>
 *   @0x27bf74 ldr r3, [pc, #0x254]
 *   @0x27bf78 mov r2, #16
 *   @0x27bf7c str r2, [r12]
 *   @0x27bf80 ldr r6, [r0, r3]
 *   @0x27bf84 ldr r5, [r6, #0x8]
 *   @0x27bf88 cmp r5, #0
 *   @0x27bf8c movne r8, #0
 *   @0x27bf90 movne r7, #42
 *   @0x27bf94 beq 0x27bfe8 <_Z11bucketCheckPc+0x108>
 *   @0x27bf98 ldr r3, [r6, #0x4]
 *   @0x27bf9c cmp r3, #0
 *   @0x27bfa0 beq 0x27bfcc <_Z11bucketCheckPc+0xec>
 *   @0x27bfa4 add r4, r3, #8
 *   @0x27bfa8 add r2, r3, #262144
 *   @0x27bfac cmp r5, r4
 *   @0x27bfb0 add r2, r2, #8
 *   @0x27bfb4 blo 0x27bfc0 <_Z11bucketCheckPc+0xe0>
 *   @0x27bfb8 cmp r2, r5
 *   @0x27bfbc bhi 0x27bfd0 <_Z11bucketCheckPc+0xf0>
 *   @0x27bfc0 ldr r3, [r3]
 *   @0x27bfc4 cmp r3, #0
 *   @0x27bfc8 bne 0x27bfa4 <_Z11bucketCheckPc+0xc4>
 *   @0x27bfcc str r7, [r8]
 *   @0x27bfd0 ldr r5, [r5]
 *   @0x27bfd4 ldr r3, [r1]
 *   @0x27bfd8 cmp r5, #0
 *   @0x27bfdc add r3, r3, #1
 *   @0x27bfe0 str r3, [r1]
 *   @0x27bfe4 bne 0x27bf98 <_Z11bucketCheckPc+0xb8>
 *   @0x27bfe8 ldr r3, [pc, #0x1e4]
 *   @0x27bfec mov r2, #32
 *   @0x27bff0 str r2, [r12]
 *   @0x27bff4 ldr r6, [r0, r3]
 *   @0x27bff8 ldr r5, [r6, #0x8]
 *   @0x27bffc cmp r5, #0
 *   @0x27c000 movne r8, #0
 *   @0x27c004 movne r7, #42
 *   @0x27c008 beq 0x27c05c <_Z11bucketCheckPc+0x17c>
 *   @0x27c00c ldr r3, [r6, #0x4]
 *   @0x27c010 cmp r3, #0
 *   @0x27c014 beq 0x27c040 <_Z11bucketCheckPc+0x160>
 *   @0x27c018 add r4, r3, #8
 *   @0x27c01c add r2, r3, #262144
 *   @0x27c020 cmp r5, r4
 *   @0x27c024 add r2, r2, #8
 *   @0x27c028 blo 0x27c034 <_Z11bucketCheckPc+0x154>
 *   @0x27c02c cmp r2, r5
 *   @0x27c030 bhi 0x27c044 <_Z11bucketCheckPc+0x164>
 *   @0x27c034 ldr r3, [r3]
 *   @0x27c038 cmp r3, #0
 *   @0x27c03c bne 0x27c018 <_Z11bucketCheckPc+0x138>
 *   @0x27c040 str r7, [r8]
 *   @0x27c044 ldr r5, [r5]
 *   @0x27c048 ldr r3, [r1]
 *   @0x27c04c cmp r5, #0
 *   @0x27c050 add r3, r3, #1
 *   @0x27c054 str r3, [r1]
 *   @0x27c058 bne 0x27c00c <_Z11bucketCheckPc+0x12c>
 *   @0x27c05c ldr r3, [pc, #0x174]
 *   @0x27c060 mov r2, #64
 *   @0x27c064 str r2, [r12]
 *   @0x27c068 ldr r6, [r0, r3]
 *   @0x27c06c ldr r5, [r6, #0x8]
 *   @0x27c070 cmp r5, #0
 *   @0x27c074 movne r8, #0
 *   @0x27c078 movne r7, #42
 *   @0x27c07c beq 0x27c0d0 <_Z11bucketCheckPc+0x1f0>
 *   @0x27c080 ldr r3, [r6, #0x4]
 *   @0x27c084 cmp r3, #0
 *   @0x27c088 beq 0x27c0b4 <_Z11bucketCheckPc+0x1d4>
 *   @0x27c08c add r4, r3, #8
 *   @0x27c090 add r2, r3, #524288
 *   @0x27c094 cmp r5, r4
 *   @0x27c098 add r2, r2, #8
 *   @0x27c09c blo 0x27c0a8 <_Z11bucketCheckPc+0x1c8>
 *   @0x27c0a0 cmp r2, r5
 *   @0x27c0a4 bhi 0x27c0b8 <_Z11bucketCheckPc+0x1d8>
 *   @0x27c0a8 ldr r3, [r3]
 *   @0x27c0ac cmp r3, #0
 *   @0x27c0b0 bne 0x27c08c <_Z11bucketCheckPc+0x1ac>
 *   @0x27c0b4 str r7, [r8]
 *   @0x27c0b8 ldr r5, [r5]
 *   @0x27c0bc ldr r3, [r1]
 *   @0x27c0c0 cmp r5, #0
 *   @0x27c0c4 add r3, r3, #1
 *   @0x27c0c8 str r3, [r1]
 *   @0x27c0cc bne 0x27c080 <_Z11bucketCheckPc+0x1a0>
 *   @0x27c0d0 ldr r3, [pc, #0x104]
 *   @0x27c0d4 mov r2, #128
 *   @0x27c0d8 str r2, [r12]
 *   @0x27c0dc ldr r6, [r0, r3]
 *   @0x27c0e0 ldr r5, [r6, #0x8]
 *   @0x27c0e4 cmp r5, #0
 *   @0x27c0e8 movne r8, #0
 *   @0x27c0ec movne r7, #42
 *   @0x27c0f0 beq 0x27c144 <_Z11bucketCheckPc+0x264>
 *   @0x27c0f4 ldr r3, [r6, #0x4]
 *   @0x27c0f8 cmp r3, #0
 *   @0x27c0fc beq 0x27c128 <_Z11bucketCheckPc+0x248>
 *   @0x27c100 add r4, r3, #8
 *   @0x27c104 add r2, r3, #524288
 *   @0x27c108 cmp r5, r4
 *   @0x27c10c add r2, r2, #8
 *   @0x27c110 blo 0x27c11c <_Z11bucketCheckPc+0x23c>
 *   @0x27c114 cmp r2, r5
 *   @0x27c118 bhi 0x27c12c <_Z11bucketCheckPc+0x24c>
 *   @0x27c11c ldr r3, [r3]
 *   @0x27c120 cmp r3, #0
 *   @0x27c124 bne 0x27c100 <_Z11bucketCheckPc+0x220>
 *   @0x27c128 str r7, [r8]
 *   @0x27c12c ldr r5, [r5]
 *   @0x27c130 ldr r3, [r1]
 *   @0x27c134 cmp r5, #0
 *   @0x27c138 add r3, r3, #1
 *   @0x27c13c str r3, [r1]
 *   @0x27c140 bne 0x27c0f4 <_Z11bucketCheckPc+0x214>
 *   @0x27c144 ldr r3, [pc, #0x94]
 *   @0x27c148 mov r2, #256
 *   @0x27c14c str r2, [r12]
 *   @0x27c150 ldr r4, [r0, r3]
 *   @0x27c154 ldr r12, [r4, #0x8]
 *   @0x27c158 cmp r12, #0
 *   @0x27c15c movne r6, #0
 *   @0x27c160 movne r5, #42
 *   @0x27c164 beq 0x27c1b8 <_Z11bucketCheckPc+0x2d8>
 *   @0x27c168 ldr r3, [r4, #0x4]
 *   @0x27c16c cmp r3, #0
 *   @0x27c170 beq 0x27c19c <_Z11bucketCheckPc+0x2bc>
 *   @0x27c174 add r0, r3, #8
 *   @0x27c178 add r2, r3, #1048576
 *   @0x27c17c cmp r12, r0
 *   @0x27c180 add r2, r2, #8
 *   @0x27c184 blo 0x27c190 <_Z11bucketCheckPc+0x2b0>
 *   @0x27c188 cmp r2, r12
 *   @0x27c18c bhi 0x27c1a0 <_Z11bucketCheckPc+0x2c0>
 *   @0x27c190 ldr r3, [r3]
 *   @0x27c194 cmp r3, #0
 *   @0x27c198 bne 0x27c174 <_Z11bucketCheckPc+0x294>
 *   @0x27c19c str r5, [r6]
 *   @0x27c1a0 ldr r12, [r12]
 *   @0x27c1a4 ldr r3, [r1]
 *   @0x27c1a8 cmp r12, #0
 *   @0x27c1ac add r3, r3, #1
 *   @0x27c1b0 str r3, [r1]
 *   @0x27c1b4 bne 0x27c168 <_Z11bucketCheckPc+0x288>
 *   @0x27c1b8 pop {r4, r5, r6, r7, r8}
 *   @0x27c1bc bx lr
 *   @0x27c1c0 andseq r5, r7, r4, ror #26
 *   @0x27c1c4 .word 0xffffbf74
 *   @0x27c1c8 .word 0xfffffbe4
 *   @0x27c1cc .word 0xfffffbe8
 *   @0x27c1d0 .word 0xfffffbec
 *   @0x27c1d4 .word 0xfffffbf0
 *   @0x27c1d8 .word 0xfffffbf4
 *   @0x27c1dc .word 0xfffffbf8
 *   @0x27c1e0 .word 0xfffffbfc
 *
 * ══ §27/39 b2RopeJoint::InitVelocityConstraints(b2SolverData const&)  0x2d2844  size 772  193 条（0x2d2844..0x2d2b48）
 * @func 0x2d2844 0x2d2b48  size 772  193 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6580×2 / 0xb658c×2 / b2RopeJoint::InitVelocityConstraints(b2SolverData const&)+0x2d0 / 0xb6700 / 0xfebc8770
 * 字段偏移 top8: 0x8×4 / 0x90×2 / 0x60×2 / 0x1c×2 / 0x64×2 / 0x30×1 / 0x34×1 / 0x18×1
 * VFP 指令 119 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d2844 ldr r2, [r0, #0x30]
 *   @0x2d2848 vldr s15, [r2, #136]
 *   @0x2d284c push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2d2850 vpush {d8, d9, d10, d11, d12, d13, d14}
 *   @0x2d2854 mov r5, r1
 *   @0x2d2858 ldr r3, [r0, #0x34]
 *   @0x2d285c add r1, r2, #44
 *   @0x2d2860 ldr lr, [r2, #0x8]
 *   @0x2d2864 mov r4, r0
 *   @0x2d2868 ldr r7, [r5, #0x18]
 *   @0x2d286c add r10, r0, #128
 *   @0x2d2870 ldr r12, [r3, #0x8]
 *   @0x2d2874 add r6, r0, #136
 *   @0x2d2878 ldr r11, [r2, #0x90]
 *   @0x2d287c add r9, r3, #44
 *   @0x2d2880 ldm r1, {r0, r1}
 *   @0x2d2884 str lr, [r4, #0x60]
 *   @0x2d2888 add lr, lr, lr, lsl #1
 *   @0x2d288c ldr r8, [r5, #0x1c]
 *   @0x2d2890 lsl lr, lr, #2
 *   @0x2d2894 str r12, [r4, #0x64]
 *   @0x2d2898 add r12, r12, r12, lsl #1
 *   @0x2d289c add r2, r7, lr
 *   @0x2d28a0 stm r10, {r0, r1}
 *   @0x2d28a4 add lr, r8, lr
 *   @0x2d28a8 lsl r12, r12, #2
 *   @0x2d28ac ldm r9, {r0, r1}
 *   @0x2d28b0 ldr r10, [r3, #0x88]
 *   @0x2d28b4 vldr s24, [r2]
 *   @0x2d28b8 ldr r9, [r3, #0x90]
 *   @0x2d28bc add r3, r7, r12
 *   @0x2d28c0 ldr r7, [r2, #0x8]
 *   @0x2d28c4 add r12, r8, r12
 *   @0x2d28c8 stm r6, {r0, r1}
 *   @0x2d28cc vstr s15, [r4, #144]
 *   @0x2d28d0 str r11, [r4, #0x98]
 *   @0x2d28d4 vldr s26, [r2, #4]
 *   @0x2d28d8 str r10, [r4, #0x94]
 *   @0x2d28dc mov r0, r7
 *   @0x2d28e0 str r9, [r4, #0x9c]
 *   @0x2d28e4 vldr s25, [r3]
 *   @0x2d28e8 ldr r6, [r3, #0x8]
 *   @0x2d28ec vldr s27, [r3, #4]
 *   @0x2d28f0 vldr s21, [lr]
 *   @0x2d28f4 vldr s20, [lr, #4]
 *   @0x2d28f8 vldr s19, [lr, #8]
 *   @0x2d28fc vldr s18, [r12]
 *   @0x2d2900 vldr s17, [r12, #4]
 *   @0x2d2904 vldr s16, [r12, #8]
 *   @0x2d2908 bl 0xb6580 <sinf@plt>
 *   @0x2d290c vmov s22, r0
 *   @0x2d2910 mov r0, r7
 *   @0x2d2914 bl 0xb658c <cosf@plt>
 *   @0x2d2918 vmov s23, r0
 *   @0x2d291c mov r0, r6
 *   @0x2d2920 bl 0xb6580 <sinf@plt>
 *   @0x2d2924 vmov s28, r0
 *   @0x2d2928 mov r0, r6
 *   @0x2d292c bl 0xb658c <cosf@plt>
 *   @0x2d2930 vldr s15, [r4, #132]
 *   @0x2d2934 vldr s14, [r4, #72]
 *   @0x2d2938 vsub.f32 s14, s14, s15
 *   @0x2d293c vldr s13, [r4, #128]
 *   @0x2d2940 vldr s11, [r4, #68]
 *   @0x2d2944 vmul.f32 s15, s14, s22
 *   @0x2d2948 vsub.f32 s11, s11, s13
 *   @0x2d294c vmov s10, r0
 *   @0x2d2950 vnmls.f32 s15, s11, s23
 *   @0x2d2954 vstr s15, [r4, #112]
 *   @0x2d2958 vldr s12, [r4, #80]
 *   @0x2d295c vldr s13, [r4, #140]
 *   @0x2d2960 vsub.f32 s13, s12, s13
 *   @0x2d2964 vldr s8, [r4, #76]
 *   @0x2d2968 vldr s9, [r4, #136]
 *   @0x2d296c vmul.f32 s12, s13, s10
 *   @0x2d2970 vsub.f32 s9, s8, s9
 *   @0x2d2974 vmul.f32 s13, s13, s28
 *   @0x2d2978 vmla.f32 s12, s9, s28
 *   @0x2d297c vmul.f32 s14, s14, s23
 *   @0x2d2980 vstr s12, [r4, #124]
 *   @0x2d2984 vnmls.f32 s13, s9, s10
 *   @0x2d2988 vmla.f32 s14, s11, s22
 *   @0x2d298c vstr s13, [r4, #120]
 *   @0x2d2990 vadd.f32 s12, s12, s27
 *   @0x2d2994 vstr s14, [r4, #116]
 *   @0x2d2998 vsub.f32 s26, s12, s26
 *   @0x2d299c vadd.f32 s13, s13, s25
 *   @0x2d29a0 vsub.f32 s14, s26, s14
 *   @0x2d29a4 vsub.f32 s24, s13, s24
 *   @0x2d29a8 vstr s14, [r4, #108]
 *   @0x2d29ac vmul.f32 s14, s14, s14
 *   @0x2d29b0 vsub.f32 s15, s24, s15
 *   @0x2d29b4 vmla.f32 s14, s15, s15
 *   @0x2d29b8 vstr s15, [r4, #104]
 *   @0x2d29bc vsqrt.f32 s15, s14
 *   @0x2d29c0 vcmp.f32 s15, s15
 *   @0x2d29c4 vmrs APSR_nzcv, fpscr
 *   @0x2d29c8 bne 0x2d2b30 <_ZN11b2RopeJoint23InitVelocityConstraintsERK12b2SolverData+0x2ec>
 *   @0x2d29cc vldr s14, [r4, #84]
 *   @0x2d29d0 vsub.f32 s14, s15, s14
 *   @0x2d29d4 vstr s15, [r4, #88]
 *   @0x2d29d8 vcmpe.f32 s14, #0
 *   @0x2d29dc vldr s14, [pc, #348]
 *   @0x2d29e0 vmrs APSR_nzcv, fpscr
 *   @0x2d29e4 vcmpe.f32 s15, s14
 *   @0x2d29e8 movgt r3, #2
 *   @0x2d29ec movle r3, #0
 *   @0x2d29f0 str r3, [r4, #0xa4]
 *   @0x2d29f4 vmrs APSR_nzcv, fpscr
 *   @0x2d29f8 ble 0x2d2b14 <_ZN11b2RopeJoint23InitVelocityConstraintsERK12b2SolverData+0x2d0>
 *   @0x2d29fc vmov.f32 s3, #1.000000e+00
 *   @0x2d2a00 vldr s12, [r4, #104]
 *   @0x2d2a04 vldr s14, [r4, #108]
 *   @0x2d2a08 vldr s4, [r4, #116]
 *   @0x2d2a0c vldr s6, [r4, #112]
 *   @0x2d2a10 vldr s5, [r4, #124]
 *   @0x2d2a14 vldr s8, [r4, #152]
 *   @0x2d2a18 vldr s10, [r4, #144]
 *   @0x2d2a1c vldr s7, [r4, #120]
 *   @0x2d2a20 vldr s9, [r4, #156]
 *   @0x2d2a24 vldr s11, [r4, #148]
 *   @0x2d2a28 vdiv.f32 s15, s3, s15
 *   @0x2d2a2c vmul.f32 s12, s15, s12
 *   @0x2d2a30 vmul.f32 s15, s15, s14
 *   @0x2d2a34 vstr s12, [r4, #104]
 *   @0x2d2a38 vmul.f32 s13, s12, s4
 *   @0x2d2a3c vstr s15, [r4, #108]
 *   @0x2d2a40 vnmls.f32 s13, s15, s6
 *   @0x2d2a44 vmul.f32 s14, s12, s5
 *   @0x2d2a48 vmul.f32 s2, s8, s13
 *   @0x2d2a4c vmov.f32 s1, s10
 *   @0x2d2a50 vnmls.f32 s14, s15, s7
 *   @0x2d2a54 vmla.f32 s1, s2, s13
 *   @0x2d2a58 vmul.f32 s2, s9, s14
 *   @0x2d2a5c vadd.f32 s13, s1, s11
 *   @0x2d2a60 vmla.f32 s13, s2, s14
 *   @0x2d2a64 vcmp.f32 s13, #0
 *   @0x2d2a68 vmrs APSR_nzcv, fpscr
 *   @0x2d2a6c vdivne.f32 s13, s3, s13
 *   @0x2d2a70 beq 0x2d2b0c <_ZN11b2RopeJoint23InitVelocityConstraintsERK12b2SolverData+0x2c8>
 *   @0x2d2a74 ldrb r3, [r5, #0x14]
 *   @0x2d2a78 vstr s13, [r4, #160]
 *   @0x2d2a7c cmp r3, #0
 *   @0x2d2a80 moveq r3, #0
 *   @0x2d2a84 streq r3, [r4, #0x5c]
 *   @0x2d2a88 bne 0x2d2ac8 <_ZN11b2RopeJoint23InitVelocityConstraintsERK12b2SolverData+0x284>
 *   @0x2d2a8c ldr r2, [r4, #0x60]
 *   @0x2d2a90 ldr r3, [r4, #0x64]
 *   @0x2d2a94 ldr r1, [r5, #0x1c]
 *   @0x2d2a98 add r2, r2, r2, lsl #1
 *   @0x2d2a9c add r3, r3, r3, lsl #1
 *   @0x2d2aa0 add r2, r1, r2, lsl #2
 *   @0x2d2aa4 vstr s21, [r2]
 *   @0x2d2aa8 vstr s20, [r2, #4]
 *   @0x2d2aac vstr s19, [r2, #8]
 *   @0x2d2ab0 add r3, r1, r3, lsl #2
 *   @0x2d2ab4 vstr s18, [r3]
 *   @0x2d2ab8 vstr s17, [r3, #4]
 *   @0x2d2abc vstr s16, [r3, #8]
 *   @0x2d2ac0 vpop {d8, d9, d10, d11, d12, d13, d14}
 *   @0x2d2ac4 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2d2ac8 vldr s13, [r4, #92]
 *   @0x2d2acc vldr s14, [r5, #8]
 *   @0x2d2ad0 vmul.f32 s14, s13, s14
 *   @0x2d2ad4 vmul.f32 s12, s14, s12
 *   @0x2d2ad8 vstr s14, [r4, #92]
 *   @0x2d2adc vmul.f32 s15, s14, s15
 *   @0x2d2ae0 vmul.f32 s4, s4, s12
 *   @0x2d2ae4 vmul.f32 s5, s5, s12
 *   @0x2d2ae8 vnmls.f32 s4, s6, s15
 *   @0x2d2aec vnmls.f32 s5, s7, s15
 *   @0x2d2af0 vmls.f32 s19, s8, s4
 *   @0x2d2af4 vmla.f32 s16, s9, s5
 *   @0x2d2af8 vmls.f32 s21, s10, s12
 *   @0x2d2afc vmls.f32 s20, s10, s15
 *   @0x2d2b00 vmla.f32 s18, s11, s12
 *   @0x2d2b04 vmla.f32 s17, s11, s15
 *   @0x2d2b08 b 0x2d2a8c <_ZN11b2RopeJoint23InitVelocityConstraintsERK12b2SolverData+0x248>
 *   @0x2d2b0c vldr s13, [pc, #48]
 *   @0x2d2b10 b 0x2d2a74 <_ZN11b2RopeJoint23InitVelocityConstraintsERK12b2SolverData+0x230>
 *   @0x2d2b14 vpop {d8, d9, d10, d11, d12, d13, d14}
 *   @0x2d2b18 mov r3, #0
 *   @0x2d2b1c str r3, [r4, #0x68]
 *   @0x2d2b20 str r3, [r4, #0x6c]
 *   @0x2d2b24 str r3, [r4, #0xa0]
 *   @0x2d2b28 str r3, [r4, #0x5c]
 *   @0x2d2b2c pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2d2b30 vmov r0, s14
 *   @0x2d2b34 bl 0xb6700 <sqrtf@plt>
 *   @0x2d2b38 vmov s15, r0
 *   @0x2d2b3c b 0x2d29cc <_ZN11b2RopeJoint23InitVelocityConstraintsERK12b2SolverData+0x188>
 *   @0x2d2b40 bllo 0xfebc8770 <b2_toiTime+0xfffffffffe46f2cc>
 *   @0x2d2b44 andeq r0, r0, r0
 *
 * ══ §28/39 anon_2a2ee8  0x2a2ee8  size 768  192 条（0x2a2ee8..0x2a31e8）
 * @func 0x2a2ee8 0x2a31e8  size 768  192 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x4ea7e8 / 0x4ab448 / 0x31f9d8 / 0xffde0940 / 0x3ea914 / 0xfe6e09ec
 * 字段偏移 top8: 无
 * VFP 指令 1 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a2ee8 movwhs r11, #0x4537
 *   @0x2a2eec strmi r4, [r4], -sp, lsl #12
 *   @0x2a2ef0 ldrmi r4, [r0], -r9, ror #12
 *   @0x2a2ef4 strmi r2, [r8, r8, lsl #4]!
 *   @0x2a2ef8 .word 0xdc032807
 *   @0x2a2efc eorvs r2, r3, r4, lsl r3
 *   @0x2a2f00 and r2, r2, r0, lsl #6
 *   @0x2a2f04 eorvs r9, r3, r0, lsl #22
 *   @0x2a2f08 rsbvs r9, r3, r1, lsl #22
 *   @0x2a2f0c ldclt p0, c11, [r0, #-12]!
 *   @0x2a2f10 stmdavs r9, {r6, r11, sp, lr} ^
 *   @0x2a2f14 stcllt p0, c15, [r2, #480]
 *   @0x2a2f18 svcmi #0xf0e92d
 *   @0x2a2f1c stcmi p5, c15, [r0, #692]
 *   @0x2a2f20 mrrcmi p0, #0x9, r11, lr, c11
 *   @0x2a2f24 strmi pc, [r1, sp, lsl #10]
 *   @0x2a2f28 .word 0x3710461d
 *   @0x2a2f2c stmdavs r4!, {r2, r3, r4, r5, r6, r10, lr}
 *   @0x2a2f30 .word 0xf50d9107
 *   @0x2a2f34 ldmdavs pc!, {r7, r8, lr}
 *   @0x2a2f38 stmdavs r3!, {r2, r5, r6, r8, r12, sp}
 *   @0x2a2f3c stmdaeq r8, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x2a2f40 .word 0xf8a54606
 *   @0x2a2f44 smladls r8, r8, r0, r8
 *   @0x2a2f48 andvs r2, r11, r0, lsl #14
 *   @0x2a2f4c shadd8mi r4, r9, r3
 *   @0x2a2f50 .word 0x612f463a
 *   @0x2a2f54 .word 0x616f4638
 *   @0x2a2f58 stmdbeq r8!, {r0, r2, r3, r8, r12, sp, lr, pc} ^
 *   @0x2a2f5c svc #0xa2f613
 *   @0x2a2f60 ldrtmi r2, [r10], -r1, lsl #2
 *   @0x2a2f64 .word 0x97149713
 *   @0x2a2f68 smladls r12, r5, r7, r9
 *   @0x2a2f6c adcvs r9, r8, pc, lsl #14
 *   @0x2a2f70 .word 0xf0014630
 *   @0x2a2f74 strls pc, [r9], #-3267
 *   @0x2a2f78 .word 0xf1a94b49
 *   @0x2a2f7c .word 0x4642043c
 *   @0x2a2f80 ldrbtmi r2, [r11], #-265
 *   @0x2a2f84 teqhs r8, #134217728
 *   @0x2a2f88 .word 0xf06f9303
 *   @0x2a2f8c adcsmi r0, r8, #939524096
 *   @0x2a2f90 andhs r11, r9, r12, lsl #30
 *   @0x2a2f94 .word 0xf50d4640
 *   @0x2a2f98 stm sp, {r0, r11, r12, lr}
 *   @0x2a2f9c strtmi r0, [r0], -r1, lsl #1
 *   @0x2a2fa0 svc #0x86f613
 *   @0x2a2fa4 stmdaeq r4!, {r3, r8, r12, sp, lr, pc}
 *   @0x2a2fa8 movwpl pc, #0x44f
 *   @0x2a2fac ldchi p8, c15, [r0], #-292
 *   @0x2a2fb0 stclo p8, c15, [r12], #-292
 *   @0x2a2fb4 ldcvc p8, c15, [r12], #-292
 *   @0x2a2fb8 ldcvc p8, c15, [r8], #-292
 *   @0x2a2fbc stmdbeq r4, {r0, r3, r5, r7, r8, r12, sp, lr, pc}
 *   @0x2a2fc0 stmdavs r3!, {r0, r2, r8, r9, r10, r12, pc} ^
 *   @0x2a2fc4 svcls #0x5bb1b
 *   @0x2a2fc8 .word 0xf44fbb0f
 *   @0x2a2fcc ldrbmi r5, [r8], -r0, lsl #4
 *   @0x2a2fd0 movwhs r4, #0x1649
 *   @0x2a2fd4 ldrmi r9, [r8, r7, lsl #30]!
 *   @0x2a2fd8 ble 0x4ea7e8 <SrcVerts+0x4782c>
 *   @0x2a2fdc andeq pc, r12, r6, lsl #2
 *   @0x2a2fe0 ldrbmi r9, [r10], -r7, lsl #18
 *   @0x2a2fe4 .word 0xff80f7ff
 *   @0x2a2fe8 .word 0xf6134620
 *   @0x2a2fec ands lr, r11, r6, ror #25
 *   @0x2a2ff0 stmdbvs r11!, {r0, r1, r3, r12, lr, pc}
 *   @0x2a2ff4 stmvs r8!, {r0, r3, r6, r9, r10, lr}
 *   @0x2a2ff8 .word 0x612b4413
 *   @0x2a2ffc .word 0xf8c46062
 *   @0x2a3000 .word 0xf6139000
 *   @0x2a3004 adcvs lr, r8, r0, asr pc
 *   @0x2a3008 strhs lr, [r4, -r1]
 *   @0x2a300c strtmi r9, [r0], -r5, lsl #14
 *   @0x2a3010 .word 0xf6139905
 *   @0x2a3014 stmdahs r1, {r2, r3, r6, r7, r10, r11, sp, lr, pc}
 *   @0x2a3018 stmdble r8, {r1, r7, r9, r10, lr}
 *   @0x2a301c andeq pc, r12, r6, lsl #2
 *   @0x2a3020 ldrbmi r2, [r2], -sp, lsl #2
 *   @0x2a3024 .word 0xf998f001
 *   @0x2a3028 rscslo pc, pc, pc, asr #32
 *   @0x2a302c stmdbvs r3!, {r0, r1, r2, r5, sp, lr, pc}
 *   @0x2a3030 svcpl #0xf5b3
 *   @0x2a3034 .word 0xf5c3d01c
 *   @0x2a3038 strbmi r5, [r0], -r0, lsl #24
 *   @0x2a303c blls 0x4ab448 <SrcVerts+0x848c>
 *   @0x2a3040 .word 0xf8cd4662
 *   @0x2a3044 .word 0xf613c018
 *   @0x2a3048 .word 0xf8ddec3a
 *   @0x2a304c strbmi r12, [r0, #-0x18]!
 *   @0x2a3050 .word 0xf613d006
 *   @0x2a3054 ldrdhs lr, pc, [r6, -r2]
 *   @0x2a3058 .word 0xf1066802
 *   @0x2a305c strb r0, [r1, r12]!
 *   @0x2a3060 vst2.16 {d22, d24}, [pc:128], r11
 *   @0x2a3064 .word 0xf8c45100
 *   @0x2a3068 ldrmi r8, [r8], #-12
 *   @0x2a306c .word 0x61686121
 *   @0x2a3070 svceq #0x1f1ba
 *   @0x2a3074 strtmi sp, [r0], -r5, lsr #3
 *   @0x2a3078 ldc p6, c15, [lr], {19}
 *   @0x2a307c .word 0xf50d2000
 *   @0x2a3080 svcls #0x94380
 *   @0x2a3084 ldmdavs r10, {r2, r5, r6, r8, r9, r12, sp}
 *   @0x2a3088 addsmi r6, r10, #3866624
 *   @0x2a308c .word 0xf613d001
 *   @0x2a3090 .word 0xf50deaa2
 *   @0x2a3094 andslt r4, r11, r0, lsl #27
 *   @0x2a3098 svchi #0xf0e8bd
 *   @0x2a309c andseq r10, r4, r8, lsr #20
 *   @0x2a30a0 andeq r9, lr, r6, asr #32
 *   @0x2a30a4 svcmi #0xf0e92d
 *   @0x2a30a8 stcpl p5, c15, [r0, #-692]
 *   @0x2a30ac addlt r4, r3, r6, lsr #26
 *   @0x2a30b0 sadd8mi r4, lr, r2
 *   @0x2a30b4 stmdavs sp!, {r0, r2, r3, r4, r5, r6, r10, lr}
 *   @0x2a30b8 andpl pc, r0, #54525952
 *   @0x2a30bc strmi r3, [r1], r4, lsl #4
 *   @0x2a30c0 strmi r6, [r12], -r11, lsr #16
 *   @0x2a30c4 teqlt r9, r3, lsl r0
 *   @0x2a30c8 bleq 0x31f9d8
 *   @0x2a30cc stmdaeq r4, {r0, r2, r3, r8, r12, sp, lr, pc}
 *   @0x2a30d0 bne 0xbdb0d8 <b2_toiTime+0x481c34>
 *   @0x2a30d4 .word 0xdc012c00
 *   @0x2a30d8 eor r2, r7, r0
 *   @0x2a30dc svclt #0x34455c
 *   @0x2a30e0 .word 0xf44f4622
 *   @0x2a30e4 strbmi r5, [r0], -r0, lsl #4
 *   @0x2a30e8 strbmi r2, [r11], -r1, lsl #2
 *   @0x2a30ec bl 0xffde0940 <b2_toiTime+0xffffffffff68749c>
 *   @0x2a30f0 ble 0x3ea914 <af_cjk_writing_system_class+0x31c>
 *   @0x2a30f4 stc p6, c15, [r0, #76]
 *   @0x2a30f8 stmdavs r2, {r0, r2, r8, sp}
 *   @0x2a30fc ands r4, r1, r0, lsr r6
 *   @0x2a3100 ldrtmi sp, [r0], -r3, lsl #2
 *   @0x2a3104 shadd16mi r2, r10, r1
 *   @0x2a3108 strbmi lr, [r0], -r12
 *   @0x2a310c ldrtmi r2, [r10], -r1, lsl #2
 *   @0x2a3110 .word 0xf6134653
 *   @0x2a3114 adcsmi lr, r8, #212, #22
 *   @0x2a3118 .word 0xf613d0db
 *   @0x2a311c .word 0x2106ed6e
 *   @0x2a3120 ldrtmi r6, [r0], -r2, lsl #16
 *   @0x2a3124 .word 0xf918f001
 *   @0x2a3128 rscslo pc, pc, pc, asr #32
 *   @0x2a312c movwpl pc, #0x50d
 *   @0x2a3130 ldmdavs r10, {r2, r8, r9, r12, sp}
 *   @0x2a3134 addsmi r6, r10, #2818048
 *   @0x2a3138 .word 0xf613d001
 *   @0x2a313c .word 0xf50dea4c
 *   @0x2a3140 andlt r5, r3, r0, lsl #26
 *   @0x2a3144 svchi #0xf0e8bd
 *   @0x2a3148 andseq r10, r4, r0, lsr #17
 *   @0x2a314c svcmi #0xf0e92d
 *   @0x2a3150 stcpl p5, c15, [r0, #-692]
 *   @0x2a3154 stcmi p0, c11, [r4], #-524
 *   @0x2a3158 .word 0xf50d4616
 *   @0x2a315c eorslo r5, r0, #0, #4
 *   @0x2a3160 stmdavs r4!, {r2, r3, r4, r5, r6, r10, lr}
 *   @0x2a3164 .word 0x9000f8d2
 *   @0x2a3168 .word 0xf50d469a
 *   @0x2a316c stmdavs r3!, {r9, r12, lr}
 *   @0x2a3170 .word 0xf10d3204
 *   @0x2a3174 strmi r0, [r0], r4, lsl #22
 *   @0x2a3178 andsvs r4, r3, pc, lsl #12
 *   @0x2a317c eorsvs r2, r3, r0, lsl #6
 *   @0x2a3180 uasxmi r4, r9, r8
 *   @0x2a3184 andpl pc, r0, #1325400064
 *   @0x2a3188 strbmi r2, [r0, r1, lsl #6]
 *   @0x2a318c ldcle p14, c1, [r3, #-20]
 *   @0x2a3190 qaddhs r4, r8, r1
 *   @0x2a3194 ldrbmi r4, [r3], -r10, lsr #12
 *   @0x2a3198 bl 0xfe6e09ec <b2_toiTime+0xfffffffffdf87548>
 *   @0x2a319c andle r4, r7, r8, lsr #5
 *   @0x2a31a0 stc p6, c15, [r10, #-76]!
 *   @0x2a31a4 stmdavs r2, {r1, r2, r8, sp}
 *   @0x2a31a8 .word 0xf0014648
 *   @0x2a31ac .word 0xe00bf8d5
 *   @0x2a31b0 ldrmi r6, [r8], #-2099
 *   @0x2a31b4 .word 0xe7e36030
 *   @0x2a31b8 strtmi r11, [r8], -r8, lsl #30
 *   @0x2a31bc strbmi sp, [r8], -r6
 *   @0x2a31c0 ldrtmi r4, [r10], -r1, asr #12
 *   @0x2a31c4 mrc2 p7, #0x4, apsr_nzcv, c0, c15, #0x7
 *   @0x2a31c8 rscslo pc, pc, pc, asr #32
 *   @0x2a31cc movwpl pc, #0x50d
 *   @0x2a31d0 ldmdavs r10, {r2, r8, r9, r12, sp}
 *   @0x2a31d4 addsmi r6, r10, #2293760
 *   @0x2a31d8 .word 0xf613d001
 *   @0x2a31dc .word 0xf50de9fc
 *   @0x2a31e0 andlt r5, r3, r0, lsl #26
 *   @0x2a31e4 svchi #0xf0e8bd
 *
 * ══ §29/39 png_free_data  0x2a5bc0  size 766  192 条（0x2a5bc0..0x2a5ebe）
 * @func 0x2a5bc0 0x2a5ec0  size 768  192 条
 * 部分覆盖: 本节 192/322 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_free×11 / 0x4a7c6e / png_free_data
 * 字段偏移 top8: 0x8×9 / 0x38×3 / 0x4×2 / 0x7c×2 / 0x1f×1 / 0x1d×1 / 0x10×1 / 0x14×1
 * VFP 指令 2 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a5bc0 push.w {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2a5bc4 mov r4, r1
 *   @0x2a5bc8 mov r7, r3
 *   @0x2a5bcc cmp r0, #0x0
 *   @0x2a5bd0 stmdbhs r0, {r2, r4, r5, r6, r8, pc}
 *   @0x2a5bd4 beq.w 0x2a5eba <png_free_data+0x2fa>
 *   @0x2a5bd8 ldr.w r3, [r1, #0xb8]
 *   @0x2a5bdc and r3, r3, #0x4000
 *   @0x2a5be0 tst r3, r2
 *   @0x2a5be4 adds r3, r7, #0x1
 *   @0x2a5be8 mov.w r8, #0x0
 *   @0x2a5bec b 0x2a5c0e <png_free_data+0x4e>
 *   @0x2a5bf0 cbz r3, 0x2a5c34 <png_free_data+0x74>
 *   @0x2a5bf4 blx 0x4a7c6e <SrcVerts+0x4cb2>
 *   @0x2a5bf8 strbmi pc, [r3], #-2055
 *   @0x2a5bfc ldr r1, [r3, #0x4]
 *   @0x2a5c00 bl 0x2a6cfc <png_free>
 *   @0x2a5c04 ldr r3, [r4, #0x38]
 *   @0x2a5c08 add r3, r8
 *   @0x2a5c0c b 0x2a5c34 <png_free_data+0x74>
 *   @0x2a5c10 mov r0, r5
 *   @0x2a5c14 bge 0x2a5c28 <png_free_data+0x68>
 *   @0x2a5c18 mov r1, r4
 *   @0x2a5c1c cpsie i
 *   @0x2a5c20 .word 0xf7ff0801
 *   @0x2a5c24 ldrb pc, [r2, sp, asr #31]!
 *   @0x2a5c28 ldr r1, [r4, #0x38]
 *   @0x2a5c2c movwhs pc, #0x867
 *   @0x2a5c30 str r3, [r4, #0x38]
 *   @0x2a5c34 ldr.w r3, [r4, #0xb8]
 *   @0x2a5c38 and r3, r3, #0x2000
 *   @0x2a5c3c tst r3, r6
 *   @0x2a5c40 mov r0, r5
 *   @0x2a5c44 bl 0x2a6cfc <png_free>
 *   @0x2a5c48 movs r3, #0x0
 *   @0x2a5c4c ldr r3, [r4, #0x8]
 *   @0x2a5c50 adcvs r0, r3, r0, lsl r3
 *   @0x2a5c54 ldr.w r3, [r4, #0xb8]
 *   @0x2a5c58 ands r3, r6
 *   @0x2a5c5c bpl 0x2a5c66 <png_free_data+0xa6>
 *   @0x2a5c60 bic r2, r2, #0x4000
 *   @0x2a5c64 str r2, [r4, #0x8]
 *   @0x2a5c68 bpl 0x2a5cce <png_free_data+0x10e>
 *   @0x2a5c6c ldr.w r1, [r4, #0xa0]
 *   @0x2a5c70 bl 0x2a6cfc <png_free>
 *   @0x2a5c74 mov r0, r5
 *   @0x2a5c78 .word 0xf00110ac
 *   @0x2a5c7c .word 0xf8d4f83f
 *   @0x2a5c80 movwhs r2, #0xb0
 *   @0x2a5c84 str.w r3, [r4, #0xa0]
 *   @0x2a5c88 str.w r3, [r4, #0xac]
 *   @0x2a5c8c cbz r2, 0x2a5cc6 <png_free_data+0x106>
 *   @0x2a5c90 mov r9, r3
 *   @0x2a5c94 ldrmi r3, [r8, #0xb5]
 *   @0x2a5c98 bge 0x2a5cb6 <png_free_data+0xf6>
 *   @0x2a5c9c .word 0x462830b0
 *   @0x2a5ca0 ldr.w r1, [r3, r8, lsl #2]
 *   @0x2a5ca4 bl 0x2a6cfc <png_free>
 *   @0x2a5ca8 ldr.w r3, [r4, #0xb0]
 *   @0x2a5cac str.w r9, [r3, r8, lsl #2]
 *   @0x2a5cb0 add.w r8, r8, #0x1
 *   @0x2a5cb4 b 0x2a5c92 <png_free_data+0xd2>
 *   @0x2a5cb8 ldr.w r1, [r4, #0xb0]
 *   @0x2a5cbc bl 0x2a6cfc <png_free>
 *   @0x2a5cc0 movs r3, #0x0
 *   @0x2a5cc4 stmvs r3!, {r4, r5, r7, r12, sp}
 *   @0x2a5cc8 bic r3, r3, #0x400
 *   @0x2a5ccc str r3, [r4, #0x8]
 *   @0x2a5cd0 .word 0xf00330b8
 *   @0x2a5cd4 eorsmi r0, r3, #16, #6
 *   @0x2a5cd8 beq 0x2a5d00 <png_free_data+0x140>
 *   @0x2a5cdc ldr.w r1, [r4, #0xc4]
 *   @0x2a5ce0 bl 0x2a6cfc <png_free>
 *   @0x2a5ce4 mov r0, r5
 *   @0x2a5ce8 .word 0xf00110c8
 *   @0x2a5cec movwhs pc, #0x807
 *   @0x2a5cf0 str.w r3, [r4, #0xc4]
 *   @0x2a5cf4 str.w r3, [r4, #0xc8]
 *   @0x2a5cf8 ldr r3, [r4, #0x8]
 *   @0x2a5cfc adcvs r5, r3, r0, lsl #7
 *   @0x2a5d00 ldr.w r3, [r4, #0xb8]
 *   @0x2a5d04 and r3, r3, #0x20
 *   @0x2a5d08 tst r3, r6
 *   @0x2a5d0c adds r2, r7, #0x1
 *   @0x2a5d10 ldr.w r3, [r4, #0xd4]
 *   @0x2a5d14 cbz r3, 0x2a5d84 <png_free_data+0x1c4>
 *   @0x2a5d18 strtmi r1, [r8], -r7, lsl #16
 *   @0x2a5d1c ldr.w r1, [r3, r8]
 *   @0x2a5d20 bl 0x2a6cfc <png_free>
 *   @0x2a5d24 ldr.w r3, [r4, #0xd4]
 *   @0x2a5d28 mov r0, r5
 *   @0x2a5d2c ldr r1, [r3, #0x8]
 *   @0x2a5d30 .word 0xf8d4ffe5
 *   @0x2a5d34 movwhs r2, #0xd4
 *   @0x2a5d38 str.w r3, [r2, r8]
 *   @0x2a5d3c ldr.w r2, [r4, #0xd4]
 *   @0x2a5d40 add r2, r8
 *   @0x2a5d44 b 0x2a5d84 <png_free_data+0x1c4>
 *   @0x2a5d48 ldrsblt r3, [r11, r8]!
 *   @0x2a5d4c mov.w r8, #0x0
 *   @0x2a5d50 ldr.w r3, [r4, #0xd8]
 *   @0x2a5d54 mov r0, r5
 *   @0x2a5d58 bge 0x2a5d6a <png_free_data+0x1aa>
 *   @0x2a5d5c mov r1, r4
 *   @0x2a5d60 add.w r8, r8, #0x1
 *   @0x2a5d64 bl 0x2a5bc0 <png_free_data>
 *   @0x2a5d68 b 0x2a5d50 <png_free_data+0x190>
 *   @0x2a5d6c .word 0xf00010d4
 *   @0x2a5d70 movwhs pc, #0xfc5
 *   @0x2a5d74 str.w r3, [r4, #0xd4]
 *   @0x2a5d78 str.w r3, [r4, #0xd8]
 *   @0x2a5d7c ldr r3, [r4, #0x8]
 *   @0x2a5d80 adcvs r5, r3, r0, lsl #6
 *   @0x2a5d84 ldr.w r1, [r5, #0x31c]
 *   @0x2a5d88 cbz r1, 0x2a5d96 <png_free_data+0x1d6>
 *   @0x2a5d8c bl 0x2a6cfc <png_free>
 *   @0x2a5d90 movs r3, #0x0
 *   @0x2a5d94 .word 0xf8d4331c
 *   @0x2a5d98 vst4.32 {d3, d4, d5, d6}, [r3:256], r8
 *   @0x2a5d9c eorsmi r7, r3, #0, #6
 *   @0x2a5da0 beq 0x2a5e02 <png_free_data+0x242>
 *   @0x2a5da4 beq 0x2a5dca <png_free_data+0x20a>
 *   @0x2a5da8 cmplt r3, #188
 *   @0x2a5dac mov.w r8, #0x14
 *   @0x2a5db0 mov r0, r5
 *   @0x2a5db4 strbmi pc, [r3], #-2055
 *   @0x2a5db8 ldr r1, [r3, #0x8]
 *   @0x2a5dbc .word 0xf8d4ff9f
 *   @0x2a5dc0 andhs r3, r0, #188
 *   @0x2a5dc4 add r3, r8
 *   @0x2a5dc8 b 0x2a5e02 <png_free_data+0x242>
 *   @0x2a5dcc biclt r3, r3, r0, asr #1
 *   @0x2a5dd0 mov.w r8, #0x0
 *   @0x2a5dd4 ldr.w r3, [r4, #0xc0]
 *   @0x2a5dd8 mov r0, r5
 *   @0x2a5ddc bge 0x2a5df0 <png_free_data+0x230>
 *   @0x2a5de0 mov r1, r4
 *   @0x2a5de4 .word 0xf1087200
 *   @0x2a5de8 .word 0xf7ff0801
 *   @0x2a5dec ldrb pc, [r1, r9, ror #29]!
 *   @0x2a5df0 ldr.w r1, [r4, #0xbc]
 *   @0x2a5df4 bl 0x2a6cfc <png_free>
 *   @0x2a5df8 movs r3, #0x0
 *   @0x2a5dfc .word 0xf8c430bc
 *   @0x2a5e00 .word 0xf8d430c0
 *   @0x2a5e04 .word 0xf00330b8
 *   @0x2a5e08 eorsmi r0, r3, #8, #6
 *   @0x2a5e0c beq 0x2a5e22 <png_free_data+0x262>
 *   @0x2a5e10 ldr r1, [r4, #0x7c]
 *   @0x2a5e14 movwhs pc, #0xf73
 *   @0x2a5e18 str r3, [r4, #0x7c]
 *   @0x2a5e1c bic r3, r3, #0x40
 *   @0x2a5e20 str r3, [r4, #0x8]
 *   @0x2a5e24 vst4.32 {d3, d4, d5, d6}, [r3:256], r8
 *   @0x2a5e28 eorsmi r5, r3, #128, #6
 *   @0x2a5e2c beq 0x2a5e44 <png_free_data+0x284>
 *   @0x2a5e30 ldr r1, [r4, #0x10]
 *   @0x2a5e34 stmvs r2!, {r0, r2, r3, r4, r6, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2a5e38 movs r3, #0x0
 *   @0x2a5e3c bic r2, r2, #0x8
 *   @0x2a5e40 strh r3, [r4, #0x14]
 *   @0x2a5e44 ldr.w r3, [r4, #0xb8]
 *   @0x2a5e48 and r3, r3, #0x40
 *   @0x2a5e4c tst r3, r6
 *   @0x2a5e50 ldr.w r3, [r4, #0xf8]
 *   @0x2a5e54 cbz r3, 0x2a5e8e <png_free_data+0x2ce>
 *   @0x2a5e58 strbmi r0, [r1], r0, lsl #16
 *   @0x2a5e5c ldr r3, [r4, #0x4]
 *   @0x2a5e60 bge 0x2a5e7e <png_free_data+0x2be>
 *   @0x2a5e64 qsub8mi r3, r8, r8
 *   @0x2a5e68 ldr.w r1, [r3, r8, lsl #2]
 *   @0x2a5e6c bl 0x2a6cfc <png_free>
 *   @0x2a5e70 ldr.w r3, [r4, #0xf8]
 *   @0x2a5e74 str.w r9, [r3, r8, lsl #2]
 *   @0x2a5e78 add.w r8, r8, #0x1
 *   @0x2a5e7c b 0x2a5e5c <png_free_data+0x29c>
 *   @0x2a5e80 ldr.w r1, [r4, #0xf8]
 *   @0x2a5e84 bl 0x2a6cfc <png_free>
 *   @0x2a5e88 movs r3, #0x0
 *   @0x2a5e8c stmvs r3!, {r3, r4, r5, r6, r7, r12, sp}
 *   @0x2a5e90 bic r3, r3, #0x8000
 *   @0x2a5e94 str r3, [r4, #0x8]
 *   @0x2a5e98 ldr.w r3, [r4, #0xb8]
 *   @0x2a5e9c bne 0x2a5eaa <png_free_data+0x2ea>
 *   @0x2a5ea0 .word 0xf8c40606
 *   @0x2a5ea4 pop {r3, r4, r5, r7, sp, lr}
 *   @0x2a5ea8 .word 0xf42683f8
 *   @0x2a5eac .word 0xf0264684
 *   @0x2a5eb0 b 0xb67738 <b2_toiTime+0x40e294>
 *   @0x2a5eb4 .word 0xf8c40306
 *   @0x2a5eb8 pop {r3, r4, r5, r7, r12, sp}
 *   @0x2a5ebc ldrlt r8, [r3, #-0x3f8]
 *
 * ══ §30/39 COggAudio::Tick(cARRAY_CLASS<CNoise*>*)  0x226590  size 764  191 条（0x226590..0x22688c）
 * @func 0x226590 0x22688c  size 764  191 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: COggAudio::Tick(cARRAY_CLASS<CNoise*>*)+0x118×3 / COggThread::Lock()×2 / COggThread::Unlock()×2 / COggAudio::Tick(cARRAY_CLASS<CNoise*>*)+0x138 / COggThread::Tick() / Audio_SetNoiseInactive(CNoise*) / COggAudio::Tick(cARRAY_CLASS<CNoise*>*)+0x224 / COggAudio::Tick(cARRAY_CLASS<CNoise*>*)+0x274
 * 字段偏移 top8: 0x4×10 / 0x14×6 / 0x808×5 / 0x10×5 / 0x8×4 / 0x804×3 / 0xc×3 / 0x802×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x226590 ldr r2, [r0, #0x14]
 *   @0x226594 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x226598 cmp r2, #0
 *   @0x22659c mov r10, r0
 *   @0x2265a0 mov r9, r1
 *   @0x2265a4 movgt r8, #0
 *   @0x2265a8 sub sp, sp, #28
 *   @0x2265ac movgt r11, r8
 *   @0x2265b0 movgt r1, r0
 *   @0x2265b4 movgt r10, r11
 *   @0x2265b8 bgt 0x2265d4 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x44>
 *   @0x2265bc b 0x2266cc <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x13c>
 *   @0x2265c0 add r10, r10, #1
 *   @0x2265c4 add r8, r8, #2096
 *   @0x2265c8 cmp r2, r10
 *   @0x2265cc add r8, r8, #4
 *   @0x2265d0 ble 0x2266c8 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x138>
 *   @0x2265d4 ldr r6, [r1]
 *   @0x2265d8 add r6, r6, r8
 *   @0x2265dc ldrb r3, [r6, #0x802]
 *   @0x2265e0 cmp r3, #0
 *   @0x2265e4 beq 0x2265c0 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x30>
 *   @0x2265e8 mov r0, r6
 *   @0x2265ec str r1, [sp, #0x4]
 *   @0x2265f0 bl 0x2247c0 <_ZN10COggThread4TickEv>
 *   @0x2265f4 ldr r0, [r6, #0x808]
 *   @0x2265f8 ldr r11, [r9]
 *   @0x2265fc cmp r0, #0
 *   @0x226600 ldr r1, [sp, #0x4]
 *   @0x226604 ble 0x2266a8 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x118>
 *   @0x226608 ldr r7, [r6, #0x804]
 *   @0x22660c ldr r3, [r7, #0x2b8]
 *   @0x226610 cmp r11, r3
 *   @0x226614 movgt r2, r11
 *   @0x226618 movgt r4, #0
 *   @0x22661c bgt 0x22664c <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0xbc>
 *   @0x226620 b 0x2266a8 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x118>
 *   @0x226624 add r4, r4, #1
 *   @0x226628 cmp r0, r4
 *   @0x22662c ble 0x2266a8 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x118>
 *   @0x226630 ldr r3, [r6, #0x804]
 *   @0x226634 add r7, r4, r4, lsl #1
 *   @0x226638 add r7, r3, r7, lsl #8
 *   @0x22663c ldr r3, [r7, #0x2b8]
 *   @0x226640 cmp r11, r3
 *   @0x226644 ble 0x2266a8 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x118>
 *   @0x226648 ldr r2, [r9]
 *   @0x22664c cmp r3, r2
 *   @0x226650 ldrlt r2, [r9, #0x4]
 *   @0x226654 movge r5, #0
 *   @0x226658 ldrlt r5, [r2, r3, lsl #2]
 *   @0x22665c ldrb r3, [r5, #0x5]
 *   @0x226660 cmp r3, #0
 *   @0x226664 beq 0x226624 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x94>
 *   @0x226668 ldrb r3, [r5, #0xc]
 *   @0x22666c cmp r3, #0
 *   @0x226670 beq 0x226624 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x94>
 *   @0x226674 mov r0, r6
 *   @0x226678 str r1, [sp, #0x4]
 *   @0x22667c bl 0x223a9c <_ZN10COggThread4LockEv>
 *   @0x226680 ldrb r7, [r7, #0x2d5]
 *   @0x226684 mov r0, r6
 *   @0x226688 bl 0x223aa4 <_ZN10COggThread6UnlockEv>
 *   @0x22668c cmp r7, #0
 *   @0x226690 ldr r1, [sp, #0x4]
 *   @0x226694 beq 0x2266b0 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x120>
 *   @0x226698 ldr r0, [r6, #0x808]
 *   @0x22669c add r4, r4, #1
 *   @0x2266a0 cmp r0, r4
 *   @0x2266a4 bgt 0x226630 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0xa0>
 *   @0x2266a8 ldr r2, [r1, #0x14]
 *   @0x2266ac b 0x2265c0 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x30>
 *   @0x2266b0 mov r0, r5
 *   @0x2266b4 str r1, [sp, #0x4]
 *   @0x2266b8 bl 0x21a048 <_Z22Audio_SetNoiseInactiveP6CNoise>
 *   @0x2266bc ldr r0, [r6, #0x808]
 *   @0x2266c0 ldr r1, [sp, #0x4]
 *   @0x2266c4 b 0x226624 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x94>
 *   @0x2266c8 mov r10, r1
 *   @0x2266cc ldr r1, [pc, #0x1b4]
 *   @0x2266d0 ldr r1, [pc, r1]
 *   @0x2266d4 str r1, [sp, #0x10]
 *   @0x2266d8 ldr r3, [r1]
 *   @0x2266dc subs r9, r3, #1
 *   @0x2266e0 lslpl r2, r9, #2
 *   @0x2266e4 strpl r2, [sp, #0x8]
 *   @0x2266e8 movpl r11, r10
 *   @0x2266ec bmi 0x226830 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x2a0>
 *   @0x2266f0 cmp r3, r9
 *   @0x2266f4 ble 0x2267b4 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x224>
 *   @0x2266f8 ldr r1, [sp, #0x10]
 *   @0x2266fc ldr r2, [sp, #0x8]
 *   @0x226700 ldr r3, [r1, #0x4]
 *   @0x226704 ldr r8, [r3, r2]
 *   @0x226708 cmp r8, #0
 *   @0x22670c beq 0x2267b4 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x224>
 *   @0x226710 ldrb r3, [r8, #0x27]
 *   @0x226714 cmp r3, #0
 *   @0x226718 beq 0x2267b4 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x224>
 *   @0x22671c ldr r4, [r11, #0x14]
 *   @0x226720 cmp r4, #0
 *   @0x226724 ble 0x226804 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x274>
 *   @0x226728 mov r10, #0
 *   @0x22672c str r9, [sp, #0x14]
 *   @0x226730 mov r9, r11
 *   @0x226734 mov r11, r10
 *   @0x226738 str r10, [sp, #0xc]
 *   @0x22673c ldr r7, [r9]
 *   @0x226740 add r7, r7, r11
 *   @0x226744 ldrb r3, [r7, #0x802]
 *   @0x226748 cmp r3, #0
 *   @0x22674c beq 0x22678c <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x1fc>
 *   @0x226750 ldr r0, [r7, #0x808]
 *   @0x226754 cmp r0, #0
 *   @0x226758 ble 0x22678c <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x1fc>
 *   @0x22675c mov r4, #0
 *   @0x226760 mov r5, r4
 *   @0x226764 ldr r6, [r7, #0x804]
 *   @0x226768 add r6, r6, r4
 *   @0x22676c ldr r3, [r6, #0x2bc]
 *   @0x226770 cmp r3, r8
 *   @0x226774 beq 0x2267d8 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x248>
 *   @0x226778 add r5, r5, #1
 *   @0x22677c add r4, r4, #768
 *   @0x226780 cmp r0, r5
 *   @0x226784 bgt 0x226764 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x1d4>
 *   @0x226788 ldr r4, [r9, #0x14]
 *   @0x22678c add r10, r10, #1
 *   @0x226790 add r11, r11, #2096
 *   @0x226794 cmp r4, r10
 *   @0x226798 add r11, r11, #4
 *   @0x22679c bgt 0x22673c <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x1ac>
 *   @0x2267a0 ldr r3, [sp, #0xc]
 *   @0x2267a4 mov r11, r9
 *   @0x2267a8 ldr r9, [sp, #0x14]
 *   @0x2267ac cmp r3, #0
 *   @0x2267b0 beq 0x226804 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x274>
 *   @0x2267b4 sub r9, r9, #1
 *   @0x2267b8 ldr r1, [sp, #0x8]
 *   @0x2267bc cmn r9, #1
 *   @0x2267c0 sub r1, r1, #4
 *   @0x2267c4 str r1, [sp, #0x8]
 *   @0x2267c8 beq 0x22682c <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x29c>
 *   @0x2267cc ldr r2, [sp, #0x10]
 *   @0x2267d0 ldr r3, [r2]
 *   @0x2267d4 b 0x2266f0 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x160>
 *   @0x2267d8 mov r0, r7
 *   @0x2267dc bl 0x223a9c <_ZN10COggThread4LockEv>
 *   @0x2267e0 mov r0, r7
 *   @0x2267e4 ldrb r6, [r6, #0x2d5]
 *   @0x2267e8 bl 0x223aa4 <_ZN10COggThread6UnlockEv>
 *   @0x2267ec ldr r0, [r7, #0x808]
 *   @0x2267f0 cmp r6, #0
 *   @0x2267f4 ldrne r2, [sp, #0xc]
 *   @0x2267f8 addne r2, r2, #1
 *   @0x2267fc strne r2, [sp, #0xc]
 *   @0x226800 b 0x226778 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x1e8>
 *   @0x226804 mov r0, r8
 *   @0x226808 bl 0x218f24 <_ZN12cAudio_SoundD2Ev>
 *   @0x22680c mov r0, r8
 *   @0x226810 bl 0x27d1d0 <_ZdlPv>
 *   @0x226814 ldr r1, [sp, #0x10]
 *   @0x226818 ldr r2, [sp, #0x8]
 *   @0x22681c ldr r3, [r1, #0x4]
 *   @0x226820 mov r1, #0
 *   @0x226824 str r1, [r3, r2]
 *   @0x226828 b 0x2267b4 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x224>
 *   @0x22682c mov r10, r11
 *   @0x226830 ldr r3, [r10, #0x4]
 *   @0x226834 cmp r3, #0
 *   @0x226838 movgt r4, #0
 *   @0x22683c bgt 0x226854 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x2c4>
 *   @0x226840 b 0x226880 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x2f0>
 *   @0x226844 ldr r3, [r10, #0x4]
 *   @0x226848 add r4, r4, #1
 *   @0x22684c cmp r3, r4
 *   @0x226850 ble 0x226880 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x2f0>
 *   @0x226854 ldr r2, [r10, #0x10]
 *   @0x226858 ldr r0, [r2, r4, lsl #2]
 *   @0x22685c cmp r0, #0
 *   @0x226860 beq 0x226848 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x2b8>
 *   @0x226864 bl 0x22510c <_ZN14COggSyncThread4TickEv>
 *   @0x226868 cmp r0, #0
 *   @0x22686c beq 0x226844 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x2b4>
 *   @0x226870 mov r0, r10
 *   @0x226874 mov r1, r4
 *   @0x226878 bl 0x225f2c <_ZN9COggAudio17Delete_SyncThreadEi>
 *   @0x22687c b 0x226844 <_ZN9COggAudio4TickEP12cARRAY_CLASSIP6CNoiseE+0x2b4>
 *   @0x226880 add sp, sp, #28
 *   @0x226884 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x226888 andseq r10, r12, r8, lsl #26
 *
 * ══ §31/39 GraphicsRecorder::AddPrims(ePrimType, int, void*)  0x188e28  size 760  190 条（0x188e28..0x189120）
 * @func 0x188e28 0x189120  size 760  190 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GraphicsRecorder::ReAllocVerts(SVertexNormal_Float*, int&, int&, int)×6 / GraphicsRecorder::AddPrims(ePrimType, int, void*)+0xf8×3 / 0xb65bc×2
 * 字段偏移 top8: 0x14×12 / 0x10×6 / 0x24×4 / 0x1c×3 / 0x2c×2 / 0xc×2 / 0x34×2 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x188e28 sub r1, r1, #2
 *   @0x188e2c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x188e30 mov r4, r0
 *   @0x188e34 sub sp, sp, #28
 *   @0x188e38 mov r5, r2
 *   @0x188e3c mov r9, r3
 *   @0x188e40 cmp r1, #4
 *   @0x188e44 addls pc, pc, r1, lsl #2
 *   @0x188e48 b 0x1890f8 <_ZN16GraphicsRecorder8AddPrimsE9ePrimTypeiPv+0x2d0>
 *   @0x188e4c b 0x188f28 <_ZN16GraphicsRecorder8AddPrimsE9ePrimTypeiPv+0x100>
 *   @0x188e50 b 0x189094 <_ZN16GraphicsRecorder8AddPrimsE9ePrimTypeiPv+0x26c>
 *   @0x188e54 b 0x188f64 <_ZN16GraphicsRecorder8AddPrimsE9ePrimTypeiPv+0x13c>
 *   @0x188e58 b 0x188f8c <_ZN16GraphicsRecorder8AddPrimsE9ePrimTypeiPv+0x164>
 *   @0x188e5c b 0x188e60 <_ZN16GraphicsRecorder8AddPrimsE9ePrimTypeiPv+0x38>
 *   @0x188e60 sub r3, r2, #2
 *   @0x188e64 ldr r6, [r0, #0x1c]
 *   @0x188e68 ldr r1, [r0, #0x14]
 *   @0x188e6c add r2, r4, #32
 *   @0x188e70 add r3, r3, r3, lsl #1
 *   @0x188e74 str r3, [sp]
 *   @0x188e78 add r3, r4, #28
 *   @0x188e7c add r6, r6, r6, lsl #3
 *   @0x188e80 bl 0x188cec <_ZN16GraphicsRecorder12ReAllocVertsEP19SVertexNormal_FloatRiS2_i>
 *   @0x188e84 cmp r5, #2
 *   @0x188e88 str r0, [r4, #0x14]
 *   @0x188e8c add r10, r0, r6, lsl #2
 *   @0x188e90 ble 0x188f20 <_ZN16GraphicsRecorder8AddPrimsE9ePrimTypeiPv+0xf8>
 *   @0x188e94 add r5, r5, r5, lsl #3
 *   @0x188e98 mov r11, r9
 *   @0x188e9c str r9, [sp, #0x14]
 *   @0x188ea0 add r5, r9, r5, lsl #2
 *   @0x188ea4 sub r5, r5, #72
 *   @0x188ea8 str r5, [sp, #0x10]
 *   @0x188eac ldr r8, [sp, #0x14]
 *   @0x188eb0 mov r7, r10
 *   @0x188eb4 add r6, r11, #36
 *   @0x188eb8 ldr r9, [sp, #0x10]
 *   @0x188ebc add r4, r11, #72
 *   @0x188ec0 add r5, r10, #36
 *   @0x188ec4 ldm r8!, {r0, r1, r2, r3}
 *   @0x188ec8 mov r11, r6
 *   @0x188ecc cmp r6, r9
 *   @0x188ed0 add r12, r10, #72
 *   @0x188ed4 add r10, r10, #108
 *   @0x188ed8 stm r7!, {r0, r1, r2, r3}
 *   @0x188edc ldm r8!, {r0, r1, r2, r3}
 *   @0x188ee0 stm r7!, {r0, r1, r2, r3}
 *   @0x188ee4 ldr r3, [r8]
 *   @0x188ee8 str r3, [r7]
 *   @0x188eec ldm r6!, {r0, r1, r2, r3}
 *   @0x188ef0 stm r5!, {r0, r1, r2, r3}
 *   @0x188ef4 ldm r6!, {r0, r1, r2, r3}
 *   @0x188ef8 stm r5!, {r0, r1, r2, r3}
 *   @0x188efc ldr r3, [r6]
 *   @0x188f00 str r3, [r5]
 *   @0x188f04 ldm r4!, {r0, r1, r2, r3}
 *   @0x188f08 stm r12!, {r0, r1, r2, r3}
 *   @0x188f0c ldm r4!, {r0, r1, r2, r3}
 *   @0x188f10 stm r12!, {r0, r1, r2, r3}
 *   @0x188f14 ldr r3, [r4]
 *   @0x188f18 str r3, [r12]
 *   @0x188f1c bne 0x188eac <_ZN16GraphicsRecorder8AddPrimsE9ePrimTypeiPv+0x84>
 *   @0x188f20 add sp, sp, #28
 *   @0x188f24 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x188f28 ldr r6, [r4, #0x2c]
 *   @0x188f2c add r2, r4, #48
 *   @0x188f30 ldr r1, [r0, #0x24]
 *   @0x188f34 add r3, r4, #44
 *   @0x188f38 str r5, [sp]
 *   @0x188f3c bl 0x188cec <_ZN16GraphicsRecorder12ReAllocVertsEP19SVertexNormal_FloatRiS2_i>
 *   @0x188f40 add r6, r6, r6, lsl #3
 *   @0x188f44 add r2, r5, r5, lsl #3
 *   @0x188f48 str r0, [r4, #0x24]
 *   @0x188f4c mov r1, r9
 *   @0x188f50 lsl r2, r2, #2
 *   @0x188f54 add r0, r0, r6, lsl #2
 *   @0x188f58 add sp, sp, #28
 *   @0x188f5c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x188f60 b 0xb65bc <memcpy@plt>
 *   @0x188f64 ldr r6, [r4, #0x1c]
 *   @0x188f68 add r2, r4, #32
 *   @0x188f6c ldr r1, [r0, #0x14]
 *   @0x188f70 add r3, r4, #28
 *   @0x188f74 str r5, [sp]
 *   @0x188f78 bl 0x188cec <_ZN16GraphicsRecorder12ReAllocVertsEP19SVertexNormal_FloatRiS2_i>
 *   @0x188f7c add r6, r6, r6, lsl #3
 *   @0x188f80 add r2, r5, r5, lsl #3
 *   @0x188f84 str r0, [r4, #0x14]
 *   @0x188f88 b 0x188f4c <_ZN16GraphicsRecorder8AddPrimsE9ePrimTypeiPv+0x124>
 *   @0x188f8c sub r5, r2, #2
 *   @0x188f90 str r5, [sp, #0x14]
 *   @0x188f94 ldr r12, [sp, #0x14]
 *   @0x188f98 add r2, r4, #32
 *   @0x188f9c ldr r5, [r0, #0x1c]
 *   @0x188fa0 ldr r1, [r0, #0x14]
 *   @0x188fa4 add r3, r12, r12, lsl #1
 *   @0x188fa8 str r3, [sp]
 *   @0x188fac add r3, r4, #28
 *   @0x188fb0 add r5, r5, r5, lsl #3
 *   @0x188fb4 bl 0x188cec <_ZN16GraphicsRecorder12ReAllocVertsEP19SVertexNormal_FloatRiS2_i>
 *   @0x188fb8 ldr r12, [sp, #0x14]
 *   @0x188fbc cmp r12, #0
 *   @0x188fc0 str r0, [r4, #0x14]
 *   @0x188fc4 add r10, r0, r5, lsl #2
 *   @0x188fc8 ble 0x188f20 <_ZN16GraphicsRecorder8AddPrimsE9ePrimTypeiPv+0xf8>
 *   @0x188fcc mov r12, #0
 *   @0x188fd0 mov r3, r9
 *   @0x188fd4 str r12, [sp, #0x10]
 *   @0x188fd8 mov r9, r12
 *   @0x188fdc b 0x18904c <_ZN16GraphicsRecorder8AddPrimsE9ePrimTypeiPv+0x224>
 *   @0x188fe0 ldm r8!, {r0, r1, r2, r3}
 *   @0x188fe4 stm r7!, {r0, r1, r2, r3}
 *   @0x188fe8 ldm r8!, {r0, r1, r2, r3}
 *   @0x188fec stm r7!, {r0, r1, r2, r3}
 *   @0x188ff0 ldr r3, [r8]
 *   @0x188ff4 str r3, [r7]
 *   @0x188ff8 ldm r6!, {r0, r1, r2, r3}
 *   @0x188ffc stm r5!, {r0, r1, r2, r3}
 *   @0x189000 ldm r6!, {r0, r1, r2, r3}
 *   @0x189004 stm r5!, {r0, r1, r2, r3}
 *   @0x189008 ldr r3, [r6]
 *   @0x18900c str r3, [r5]
 *   @0x189010 ldm r4!, {r0, r1, r2, r3}
 *   @0x189014 stm r12!, {r0, r1, r2, r3}
 *   @0x189018 ldm r4!, {r0, r1, r2, r3}
 *   @0x18901c stm r12!, {r0, r1, r2, r3}
 *   @0x189020 ldr r3, [r4]
 *   @0x189024 str r3, [r12]
 *   @0x189028 ldr r12, [sp, #0x10]
 *   @0x18902c add r9, r9, #1
 *   @0x189030 add r10, r10, #108
 *   @0x189034 mov r3, r11
 *   @0x189038 eor r12, r12, #1
 *   @0x18903c str r12, [sp, #0x10]
 *   @0x189040 ldr r12, [sp, #0x14]
 *   @0x189044 cmp r9, r12
 *   @0x189048 beq 0x188f20 <_ZN16GraphicsRecorder8AddPrimsE9ePrimTypeiPv+0xf8>
 *   @0x18904c ldr r2, [sp, #0x10]
 *   @0x189050 add r11, r3, #36
 *   @0x189054 add r8, r3, #72
 *   @0x189058 mov r7, r10
 *   @0x18905c cmp r2, #0
 *   @0x189060 add r5, r10, #36
 *   @0x189064 mov r4, r3
 *   @0x189068 add r12, r10, #72
 *   @0x18906c mov r6, r11
 *   @0x189070 bne 0x188fe0 <_ZN16GraphicsRecorder8AddPrimsE9ePrimTypeiPv+0x1b8>
 *   @0x189074 mov r1, r3
 *   @0x189078 mov r0, r10
 *   @0x18907c mov r2, #108
 *   @0x189080 str r3, [sp, #0xc]
 *   @0x189084 bl 0xb65bc <memcpy@plt>
 *   @0x189088 ldr r3, [sp, #0xc]
 *   @0x18908c add r11, r3, #36
 *   @0x189090 b 0x189028 <_ZN16GraphicsRecorder8AddPrimsE9ePrimTypeiPv+0x200>
 *   @0x189094 sub r5, r2, #1
 *   @0x189098 ldr r6, [r0, #0x2c]
 *   @0x18909c ldr r1, [r0, #0x24]
 *   @0x1890a0 add r2, r4, #48
 *   @0x1890a4 lsl r3, r5, #1
 *   @0x1890a8 str r3, [sp]
 *   @0x1890ac add r3, r4, #44
 *   @0x1890b0 add r6, r6, r6, lsl #3
 *   @0x1890b4 bl 0x188cec <_ZN16GraphicsRecorder12ReAllocVertsEP19SVertexNormal_FloatRiS2_i>
 *   @0x1890b8 cmp r5, #0
 *   @0x1890bc str r0, [r4, #0x24]
 *   @0x1890c0 add r3, r0, r6, lsl #2
 *   @0x1890c4 ble 0x188f20 <_ZN16GraphicsRecorder8AddPrimsE9ePrimTypeiPv+0xf8>
 *   @0x1890c8 mov r4, #0
 *   @0x1890cc mov r0, r3
 *   @0x1890d0 mov r1, r9
 *   @0x1890d4 mov r2, #72
 *   @0x1890d8 add r4, r4, #1
 *   @0x1890dc bl 0xb65bc <memcpy@plt>
 *   @0x1890e0 cmp r4, r5
 *   @0x1890e4 add r9, r9, #36
 *   @0x1890e8 add r3, r0, #72
 *   @0x1890ec bne 0x1890cc <_ZN16GraphicsRecorder8AddPrimsE9ePrimTypeiPv+0x2a4>
 *   @0x1890f0 add sp, sp, #28
 *   @0x1890f4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1890f8 ldr r6, [r4, #0x3c]
 *   @0x1890fc add r2, r4, #64
 *   @0x189100 ldr r1, [r0, #0x34]
 *   @0x189104 add r3, r4, #60
 *   @0x189108 str r5, [sp]
 *   @0x18910c bl 0x188cec <_ZN16GraphicsRecorder12ReAllocVertsEP19SVertexNormal_FloatRiS2_i>
 *   @0x189110 add r6, r6, r6, lsl #3
 *   @0x189114 add r2, r5, r5, lsl #3
 *   @0x189118 str r0, [r4, #0x34]
 *   @0x18911c b 0x188f4c <_ZN16GraphicsRecorder8AddPrimsE9ePrimTypeiPv+0x124>
 *
 * ══ §32/39 MonthFromTime(double)  0x244c68  size 760  190 条（0x244c68..0x244f60）
 * @func 0x244c68 0x244f60  size 760  190 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DayWithinYear(double) / InLeapYear(double) / MonthFromTime(double)+0x4c / MonthFromTime(double)+0x70 / MonthFromTime(double)+0xa4 / MonthFromTime(double)+0x100 / MonthFromTime(double)+0x130 / MonthFromTime(double)+0x164
 * 字段偏移 top8: 无
 * VFP 指令 92 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x244c68 push {r3, r4, r5, lr}
 *   @0x244c6c vpush {d8}
 *   @0x244c70 mov r4, r0
 *   @0x244c74 mov r5, r1
 *   @0x244c78 bl 0x244c28 <_Z13DayWithinYeard>
 *   @0x244c7c vmov d8, r0, r1
 *   @0x244c80 mov r0, r4
 *   @0x244c84 mov r1, r5
 *   @0x244c88 bl 0x244be8 <_Z10InLeapYeard>
 *   @0x244c8c vcmpe.f64 d8, #0
 *   @0x244c90 vmrs APSR_nzcv, fpscr
 *   @0x244c94 vmov d7, r0, r1
 *   @0x244c98 blt 0x244cb4 <_Z13MonthFromTimed+0x4c>
 *   @0x244c9c vmov.f64 d6, #3.100000e+01
 *   @0x244ca0 vcmpe.f64 d8, d6
 *   @0x244ca4 vmrs APSR_nzcv, fpscr
 *   @0x244ca8 movmi r0, #0
 *   @0x244cac movmi r1, #0
 *   @0x244cb0 bmi 0x244d3c <_Z13MonthFromTimed+0xd4>
 *   @0x244cb4 vmov.f64 d6, #3.100000e+01
 *   @0x244cb8 vcmpe.f64 d8, d6
 *   @0x244cbc vmrs APSR_nzcv, fpscr
 *   @0x244cc0 blt 0x244cd8 <_Z13MonthFromTimed+0x70>
 *   @0x244cc4 vldr d6, [pc, #572]
 *   @0x244cc8 vadd.f64 d6, d7, d6
 *   @0x244ccc vcmpe.f64 d8, d6
 *   @0x244cd0 vmrs APSR_nzcv, fpscr
 *   @0x244cd4 bmi 0x244e6c <_Z13MonthFromTimed+0x204>
 *   @0x244cd8 vldr d6, [pc, #552]
 *   @0x244cdc vcmpe.f64 d8, d6
 *   @0x244ce0 vmrs APSR_nzcv, fpscr
 *   @0x244ce4 bge 0x244d44 <_Z13MonthFromTimed+0xdc>
 *   @0x244ce8 vldr d6, [pc, #544]
 *   @0x244cec vcmpe.f64 d8, d6
 *   @0x244cf0 vmrs APSR_nzcv, fpscr
 *   @0x244cf4 blt 0x244d0c <_Z13MonthFromTimed+0xa4>
 *   @0x244cf8 vldr d6, [pc, #536]
 *   @0x244cfc vadd.f64 d6, d7, d6
 *   @0x244d00 vcmpe.f64 d8, d6
 *   @0x244d04 vmrs APSR_nzcv, fpscr
 *   @0x244d08 bmi 0x244ea4 <_Z13MonthFromTimed+0x23c>
 *   @0x244d0c vldr d6, [pc, #516]
 *   @0x244d10 vcmpe.f64 d8, d6
 *   @0x244d14 vmrs APSR_nzcv, fpscr
 *   @0x244d18 blt 0x244d68 <_Z13MonthFromTimed+0x100>
 *   @0x244d1c vldr d6, [pc, #508]
 *   @0x244d20 vadd.f64 d6, d7, d6
 *   @0x244d24 vcmpe.f64 d8, d6
 *   @0x244d28 vmrs APSR_nzcv, fpscr
 *   @0x244d2c bpl 0x244d68 <_Z13MonthFromTimed+0x100>
 *   @0x244d30 mov r1, #0
 *   @0x244d34 movt r1, #0x4010
 *   @0x244d38 mov r0, #0
 *   @0x244d3c vpop {d8}
 *   @0x244d40 pop {r3, r4, r5, pc}
 *   @0x244d44 vldr d6, [pc, #452]
 *   @0x244d48 vadd.f64 d6, d7, d6
 *   @0x244d4c vcmpe.f64 d8, d6
 *   @0x244d50 vmrs APSR_nzcv, fpscr
 *   @0x244d54 movmi r0, #0
 *   @0x244d58 movmi r1, #1073741824
 *   @0x244d5c bpl 0x244ce8 <_Z13MonthFromTimed+0x80>
 *   @0x244d60 vpop {d8}
 *   @0x244d64 pop {r3, r4, r5, pc}
 *   @0x244d68 vldr d6, [pc, #432]
 *   @0x244d6c vcmpe.f64 d8, d6
 *   @0x244d70 vmrs APSR_nzcv, fpscr
 *   @0x244d74 blt 0x244d98 <_Z13MonthFromTimed+0x130>
 *   @0x244d78 vldr d6, [pc, #424]
 *   @0x244d7c vadd.f64 d6, d7, d6
 *   @0x244d80 vcmpe.f64 d8, d6
 *   @0x244d84 vmrs APSR_nzcv, fpscr
 *   @0x244d88 movmi r1, #0
 *   @0x244d8c movmi r0, #0
 *   @0x244d90 movtmi r1, #0x4014
 *   @0x244d94 bmi 0x244d3c <_Z13MonthFromTimed+0xd4>
 *   @0x244d98 vldr d6, [pc, #392]
 *   @0x244d9c vcmpe.f64 d8, d6
 *   @0x244da0 vmrs APSR_nzcv, fpscr
 *   @0x244da4 bge 0x244e80 <_Z13MonthFromTimed+0x218>
 *   @0x244da8 vldr d6, [pc, #384]
 *   @0x244dac vcmpe.f64 d8, d6
 *   @0x244db0 vmrs APSR_nzcv, fpscr
 *   @0x244db4 blt 0x244dcc <_Z13MonthFromTimed+0x164>
 *   @0x244db8 vldr d6, [pc, #376]
 *   @0x244dbc vadd.f64 d6, d7, d6
 *   @0x244dc0 vcmpe.f64 d8, d6
 *   @0x244dc4 vmrs APSR_nzcv, fpscr
 *   @0x244dc8 bmi 0x244ef4 <_Z13MonthFromTimed+0x28c>
 *   @0x244dcc vldr d6, [pc, #356]
 *   @0x244dd0 vcmpe.f64 d8, d6
 *   @0x244dd4 vmrs APSR_nzcv, fpscr
 *   @0x244dd8 blt 0x244df0 <_Z13MonthFromTimed+0x188>
 *   @0x244ddc vldr d6, [pc, #348]
 *   @0x244de0 vadd.f64 d6, d7, d6
 *   @0x244de4 vcmpe.f64 d8, d6
 *   @0x244de8 vmrs APSR_nzcv, fpscr
 *   @0x244dec bmi 0x244ec4 <_Z13MonthFromTimed+0x25c>
 *   @0x244df0 vldr d6, [pc, #328]
 *   @0x244df4 vcmpe.f64 d8, d6
 *   @0x244df8 vmrs APSR_nzcv, fpscr
 *   @0x244dfc blt 0x244e14 <_Z13MonthFromTimed+0x1ac>
 *   @0x244e00 vldr d6, [pc, #320]
 *   @0x244e04 vadd.f64 d6, d7, d6
 *   @0x244e08 vcmpe.f64 d8, d6
 *   @0x244e0c vmrs APSR_nzcv, fpscr
 *   @0x244e10 bmi 0x244ed4 <_Z13MonthFromTimed+0x26c>
 *   @0x244e14 vldr d6, [pc, #300]
 *   @0x244e18 vcmpe.f64 d8, d6
 *   @0x244e1c vmrs APSR_nzcv, fpscr
 *   @0x244e20 blt 0x244e38 <_Z13MonthFromTimed+0x1d0>
 *   @0x244e24 vldr d6, [pc, #292]
 *   @0x244e28 vadd.f64 d6, d7, d6
 *   @0x244e2c vcmpe.f64 d8, d6
 *   @0x244e30 vmrs APSR_nzcv, fpscr
 *   @0x244e34 bmi 0x244ee4 <_Z13MonthFromTimed+0x27c>
 *   @0x244e38 vldr d6, [pc, #272]
 *   @0x244e3c vcmpe.f64 d8, d6
 *   @0x244e40 vmrs APSR_nzcv, fpscr
 *   @0x244e44 blt 0x244eb4 <_Z13MonthFromTimed+0x24c>
 *   @0x244e48 vldr d6, [pc, #264]
 *   @0x244e4c vadd.f64 d7, d7, d6
 *   @0x244e50 vmov.f64 d5, #1.100000e+01
 *   @0x244e54 vmov.f64 d6, #-1.000000e+00
 *   @0x244e58 vcmpe.f64 d8, d7
 *   @0x244e5c vmrs APSR_nzcv, fpscr
 *   @0x244e60 vmovpl r0, r1, d6
 *   @0x244e64 vmovmi r0, r1, d5
 *   @0x244e68 b 0x244d3c <_Z13MonthFromTimed+0xd4>
 *   @0x244e6c vpop {d8}
 *   @0x244e70 mov r0, #0
 *   @0x244e74 mov r1, #0
 *   @0x244e78 movt r1, #0x3ff0
 *   @0x244e7c pop {r3, r4, r5, pc}
 *   @0x244e80 vldr d6, [pc, #168]
 *   @0x244e84 vadd.f64 d6, d7, d6
 *   @0x244e88 vcmpe.f64 d8, d6
 *   @0x244e8c vmrs APSR_nzcv, fpscr
 *   @0x244e90 bpl 0x244da8 <_Z13MonthFromTimed+0x140>
 *   @0x244e94 mov r1, #0
 *   @0x244e98 mov r0, #0
 *   @0x244e9c movt r1, #0x4018
 *   @0x244ea0 b 0x244d3c <_Z13MonthFromTimed+0xd4>
 *   @0x244ea4 mov r1, #0
 *   @0x244ea8 mov r0, #0
 *   @0x244eac movt r1, #0x4008
 *   @0x244eb0 b 0x244d3c <_Z13MonthFromTimed+0xd4>
 *   @0x244eb4 mov r1, #0
 *   @0x244eb8 mov r0, #0
 *   @0x244ebc movt r1, #0xbff0
 *   @0x244ec0 b 0x244d3c <_Z13MonthFromTimed+0xd4>
 *   @0x244ec4 mov r1, #0
 *   @0x244ec8 mov r0, #0
 *   @0x244ecc movt r1, #0x4020
 *   @0x244ed0 b 0x244d3c <_Z13MonthFromTimed+0xd4>
 *   @0x244ed4 mov r1, #0
 *   @0x244ed8 mov r0, #0
 *   @0x244edc movt r1, #0x4022
 *   @0x244ee0 b 0x244d3c <_Z13MonthFromTimed+0xd4>
 *   @0x244ee4 mov r1, #0
 *   @0x244ee8 mov r0, #0
 *   @0x244eec movt r1, #0x4024
 *   @0x244ef0 b 0x244d3c <_Z13MonthFromTimed+0xd4>
 *   @0x244ef4 mov r1, #0
 *   @0x244ef8 mov r0, #0
 *   @0x244efc movt r1, #0x401c
 *   @0x244f00 b 0x244d3c <_Z13MonthFromTimed+0xd4>
 *   @0x244f04 nop
 *   @0x244f08 andeq r0, r0, r0
 *   @0x244f0c submi r8, sp, r0
 *   @0x244f10 andeq r0, r0, r0
 *   @0x244f14 subsmi r8, r6, r0
 *   @0x244f18 andeq r0, r0, r0
 *   @0x244f1c subsmi r0, lr, r0
 *   @0x244f20 andeq r0, r0, r0
 *   @0x244f24 rsbmi lr, r2, r0
 *   @0x244f28 andeq r0, r0, r0
 *   @0x244f2c rsbmi r10, r6, r0
 *   @0x244f30 andeq r0, r0, r0
 *   @0x244f34 rsbmi r8, r10, r0
 *   @0x244f38 andeq r0, r0, r0
 *   @0x244f3c rsbmi r6, lr, r0
 *   @0x244f40 andeq r0, r0, r0
 *   @0x244f44 rsbsmi r1, r1, r0
 *   @0x244f48 andeq r0, r0, r0
 *   @0x244f4c rsbsmi r0, r3, r0
 *   @0x244f50 andeq r0, r0, r0
 *   @0x244f54 rsbsmi lr, r4, r0
 *   @0x244f58 andeq r0, r0, r0
 *   @0x244f5c rsbsmi sp, r6, r0
 *
 * ══ §33/39 b2GearJoint::b2GearJoint(b2GearJointDef const*)  0x2e4588  size 760  190 条（0x2e4588..0x2e4880）
 * @func 0x2e4588 0x2e4880  size 760  190 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Joint::b2Joint(b2JointDef const*)
 * 字段偏移 top8: 0x14×3 / 0x50×3 / 0x30×3 / 0x34×3 / 0x18×2 / 0x44×2 / 0x48×2 / 0x4×2
 * VFP 指令 76 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e4588 push {r4, r5, r6, r7, r8, lr}
 *   @0x2e458c mov r5, r1
 *   @0x2e4590 mov r4, r0
 *   @0x2e4594 bl 0x2cdee0 <_ZN7b2JointC2EPK10b2JointDef>
 *   @0x2e4598 ldr r1, [r5, #0x14]
 *   @0x2e459c ldr r2, [r5, #0x18]
 *   @0x2e45a0 ldr r3, [pc, #0x2c8]
 *   @0x2e45a4 str r1, [r4, #0x44]
 *   @0x2e45a8 ldr r3, [pc, r3]
 *   @0x2e45ac str r2, [r4, #0x48]
 *   @0x2e45b0 add r3, r3, #8
 *   @0x2e45b4 str r3, [r4]
 *   @0x2e45b8 ldr r3, [r1, #0x4]
 *   @0x2e45bc ldr r6, [pc, #0x2b0]
 *   @0x2e45c0 sub r0, r3, #1
 *   @0x2e45c4 ldr r1, [pc, #0x2ac]
 *   @0x2e45c8 str r3, [r4, #0x4c]
 *   @0x2e45cc cmp r0, #1
 *   @0x2e45d0 ldr r2, [r2, #0x4]
 *   @0x2e45d4 ldr r6, [pc, r6]
 *   @0x2e45d8 movhi r0, #0
 *   @0x2e45dc movls r0, #1
 *   @0x2e45e0 add r1, pc, r1
 *   @0x2e45e4 ldr r3, [r6]
 *   @0x2e45e8 str r2, [r4, #0x50]
 *   @0x2e45ec blx r3
 *   @0x2e45f0 ldr r0, [r4, #0x50]
 *   @0x2e45f4 ldr r1, [pc, #0x280]
 *   @0x2e45f8 sub r0, r0, #1
 *   @0x2e45fc ldr r3, [r6]
 *   @0x2e4600 cmp r0, #1
 *   @0x2e4604 add r1, pc, r1
 *   @0x2e4608 movhi r0, #0
 *   @0x2e460c movls r0, #1
 *   @0x2e4610 blx r3
 *   @0x2e4614 ldr r2, [r4, #0x44]
 *   @0x2e4618 ldr r1, [r4, #0x4c]
 *   @0x2e461c ldr r3, [r2, #0x30]
 *   @0x2e4620 vldr s13, [r3, #12]
 *   @0x2e4624 vldr s15, [r3, #16]
 *   @0x2e4628 vldr s9, [r3, #20]
 *   @0x2e462c vldr s10, [r3, #24]
 *   @0x2e4630 vldr s14, [r3, #72]
 *   @0x2e4634 str r3, [r4, #0x54]
 *   @0x2e4638 cmp r1, #1
 *   @0x2e463c ldr r3, [r2, #0x34]
 *   @0x2e4640 vldr s12, [r3, #12]
 *   @0x2e4644 vldr s11, [r3, #16]
 *   @0x2e4648 vldr s7, [r3, #20]
 *   @0x2e464c vldr s8, [r3, #24]
 *   @0x2e4650 vldr s6, [r3, #72]
 *   @0x2e4654 str r3, [r4, #0x30]
 *   @0x2e4658 beq 0x2e47ec <_ZN11b2GearJointC2EPK14b2GearJointDef+0x264>
 *   @0x2e465c ldr r3, [r5, #0x14]
 *   @0x2e4660 add r7, r4, #108
 *   @0x2e4664 add r12, r4, #92
 *   @0x2e4668 add r8, r4, #124
 *   @0x2e466c add r1, r3, #68
 *   @0x2e4670 add r6, r3, #76
 *   @0x2e4674 add r2, r3, #84
 *   @0x2e4678 ldr r3, [r3, #0x64]
 *   @0x2e467c ldm r1, {r0, r1}
 *   @0x2e4680 vsub.f32 s15, s11, s15
 *   @0x2e4684 stm r7, {r0, r1}
 *   @0x2e4688 ldm r6, {r0, r1}
 *   @0x2e468c stm r12, {r0, r1}
 *   @0x2e4690 ldm r2, {r0, r1}
 *   @0x2e4694 str r3, [r4, #0x8c]
 *   @0x2e4698 vsub.f32 s1, s12, s13
 *   @0x2e469c stm r8, {r0, r1}
 *   @0x2e46a0 vldr s5, [r4, #96]
 *   @0x2e46a4 vldr s6, [r4, #92]
 *   @0x2e46a8 vldr s14, [r4, #112]
 *   @0x2e46ac vldr s2, [r4, #128]
 *   @0x2e46b0 vldr s3, [r4, #108]
 *   @0x2e46b4 vldr s4, [r4, #124]
 *   @0x2e46b8 vmul.f32 s11, s8, s5
 *   @0x2e46bc vmul.f32 s12, s7, s5
 *   @0x2e46c0 vmla.f32 s11, s7, s6
 *   @0x2e46c4 vnmls.f32 s12, s8, s6
 *   @0x2e46c8 vadd.f32 s11, s11, s15
 *   @0x2e46cc vmul.f32 s13, s11, s10
 *   @0x2e46d0 vadd.f32 s12, s12, s1
 *   @0x2e46d4 vmul.f32 s15, s11, s9
 *   @0x2e46d8 vmls.f32 s13, s9, s12
 *   @0x2e46dc vmla.f32 s15, s12, s10
 *   @0x2e46e0 vsub.f32 s14, s13, s14
 *   @0x2e46e4 vmul.f32 s14, s14, s2
 *   @0x2e46e8 vsub.f32 s15, s15, s3
 *   @0x2e46ec vmla.f32 s14, s15, s4
 *   @0x2e46f0 ldr r2, [r4, #0x48]
 *   @0x2e46f4 ldr r1, [r4, #0x50]
 *   @0x2e46f8 ldr r3, [r2, #0x30]
 *   @0x2e46fc vldr s12, [r3, #12]
 *   @0x2e4700 vldr s13, [r3, #16]
 *   @0x2e4704 vldr s8, [r3, #20]
 *   @0x2e4708 vldr s9, [r3, #24]
 *   @0x2e470c vldr s5, [r3, #72]
 *   @0x2e4710 str r3, [r4, #0x58]
 *   @0x2e4714 cmp r1, #1
 *   @0x2e4718 ldr r3, [r2, #0x34]
 *   @0x2e471c vldr s11, [r3, #12]
 *   @0x2e4720 vldr s10, [r3, #16]
 *   @0x2e4724 vldr s6, [r3, #20]
 *   @0x2e4728 vldr s7, [r3, #24]
 *   @0x2e472c vldr s4, [r3, #72]
 *   @0x2e4730 str r3, [r4, #0x34]
 *   @0x2e4734 ldr r3, [r5, #0x18]
 *   @0x2e4738 beq 0x2e4830 <_ZN11b2GearJointC2EPK14b2GearJointDef+0x2a8>
 *   @0x2e473c add r1, r3, #68
 *   @0x2e4740 add r6, r3, #76
 *   @0x2e4744 add r7, r4, #116
 *   @0x2e4748 add r2, r3, #84
 *   @0x2e474c ldm r1, {r0, r1}
 *   @0x2e4750 add r12, r4, #100
 *   @0x2e4754 ldr r3, [r3, #0x64]
 *   @0x2e4758 add r8, r4, #132
 *   @0x2e475c stm r7, {r0, r1}
 *   @0x2e4760 ldm r6, {r0, r1}
 *   @0x2e4764 vsub.f32 s13, s10, s13
 *   @0x2e4768 stm r12, {r0, r1}
 *   @0x2e476c ldm r2, {r0, r1}
 *   @0x2e4770 str r3, [r4, #0x90]
 *   @0x2e4774 stm r8, {r0, r1}
 *   @0x2e4778 vldr s4, [r4, #104]
 *   @0x2e477c vldr s5, [r4, #100]
 *   @0x2e4780 vldr s15, [r4, #120]
 *   @0x2e4784 vldr s1, [r4, #136]
 *   @0x2e4788 vldr s2, [r4, #116]
 *   @0x2e478c vmul.f32 s10, s4, s7
 *   @0x2e4790 vldr s3, [r4, #132]
 *   @0x2e4794 vsub.f32 s0, s11, s12
 *   @0x2e4798 vmla.f32 s10, s5, s6
 *   @0x2e479c vmul.f32 s11, s4, s6
 *   @0x2e47a0 vnmls.f32 s11, s5, s7
 *   @0x2e47a4 vadd.f32 s10, s10, s13
 *   @0x2e47a8 vmul.f32 s12, s9, s10
 *   @0x2e47ac vadd.f32 s11, s11, s0
 *   @0x2e47b0 vmul.f32 s13, s8, s10
 *   @0x2e47b4 vmls.f32 s12, s8, s11
 *   @0x2e47b8 vmla.f32 s13, s9, s11
 *   @0x2e47bc vsub.f32 s15, s12, s15
 *   @0x2e47c0 vmul.f32 s15, s15, s1
 *   @0x2e47c4 vsub.f32 s13, s13, s2
 *   @0x2e47c8 vmla.f32 s15, s13, s3
 *   @0x2e47cc vldr s13, [r5, #28]
 *   @0x2e47d0 mov r3, #0
 *   @0x2e47d4 vstr s13, [r4, #152]
 *   @0x2e47d8 str r3, [r4, #0x9c]
 *   @0x2e47dc mov r0, r4
 *   @0x2e47e0 vmla.f32 s14, s15, s13
 *   @0x2e47e4 vstr s14, [r4, #148]
 *   @0x2e47e8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2e47ec ldr r3, [r5, #0x14]
 *   @0x2e47f0 vsub.f32 s14, s6, s14
 *   @0x2e47f4 add r12, r4, #108
 *   @0x2e47f8 vldr s15, [r3, #116]
 *   @0x2e47fc add r1, r3, #68
 *   @0x2e4800 add r2, r3, #76
 *   @0x2e4804 add r7, r4, #92
 *   @0x2e4808 mov r6, #0
 *   @0x2e480c ldm r1, {r0, r1}
 *   @0x2e4810 stm r12, {r0, r1}
 *   @0x2e4814 ldm r2, {r0, r1}
 *   @0x2e4818 vsub.f32 s14, s14, s15
 *   @0x2e481c stm r7, {r0, r1}
 *   @0x2e4820 vstr s15, [r4, #140]
 *   @0x2e4824 str r6, [r4, #0x7c]
 *   @0x2e4828 str r6, [r4, #0x80]
 *   @0x2e482c b 0x2e46f0 <_ZN11b2GearJointC2EPK14b2GearJointDef+0x168>
 *   @0x2e4830 vsub.f32 s15, s4, s5
 *   @0x2e4834 add r1, r3, #68
 *   @0x2e4838 add r12, r4, #116
 *   @0x2e483c add r2, r3, #76
 *   @0x2e4840 ldm r1, {r0, r1}
 *   @0x2e4844 vldr s13, [r3, #116]
 *   @0x2e4848 add r7, r4, #100
 *   @0x2e484c mov r6, #0
 *   @0x2e4850 stm r12, {r0, r1}
 *   @0x2e4854 ldm r2, {r0, r1}
 *   @0x2e4858 stm r7, {r0, r1}
 *   @0x2e485c vstr s13, [r4, #144]
 *   @0x2e4860 str r6, [r4, #0x84]
 *   @0x2e4864 vsub.f32 s15, s15, s13
 *   @0x2e4868 str r6, [r4, #0x88]
 *   @0x2e486c b 0x2e47cc <_ZN11b2GearJointC2EPK14b2GearJointDef+0x244>
 *   @0x2e4870 andseq sp, r0, r4, lsl #12
 *   @0x2e4874 ldrsheq r12, [r0], -r4
 *   @0x2e4878 andeq r9, r7, r8, lsl r3
 *   @0x2e487c ldrdeq r9, r10, [r7], -r12
 *
 * ══ §34/39 C3D_Model::LoadFromFile(char const*)  0x163efc  size 756  189 条（0x163efc..0x1641f0）
 * @func 0x163efc 0x164200  size 772  193 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ReadLn(CStream*, char const*&)×3 / CStream::~CStream()×3 / operator delete(void*)×3 / operator new(unsigned int)×2 / C3D_Model::LoadFromFile(char const*)+0x270×2 / C3D_Model::Clear() / CStream::CStream(int) / CStream::LoadFromFile(char const*, int)
 * 字段偏移 top8: 0x8×5 / 0x48×3 / 0x4×3 / 0x4c×3 / 0x2×3 / 0x28×2 / 0xc×2 / 0x14×2
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x163efc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x163f00 sub sp, sp, #124
 *   @0x163f04 mov r7, r1
 *   @0x163f08 mov r6, #0
 *   @0x163f0c mov r5, r0
 *   @0x163f10 str r6, [sp, #0x48]
 *   @0x163f14 bl 0x163ce0 <_ZN9C3D_Model5ClearEv>
 *   @0x163f18 mov r0, #32
 *   @0x163f1c bl 0x27c524 <_Znwj>
 *   @0x163f20 mov r1, r6
 *   @0x163f24 mov r4, r0
 *   @0x163f28 bl 0x2010ec <_ZN7CStreamC2Ei>
 *   @0x163f2c mov r1, r7
 *   @0x163f30 mov r0, r4
 *   @0x163f34 mov r2, r6
 *   @0x163f38 bl 0x201358 <_ZN7CStream12LoadFromFileEPKci>
 *   @0x163f3c mov r0, r4
 *   @0x163f40 bl 0x201158 <_ZN7CStream9GetMemoryEv>
 *   @0x163f44 subs r7, r0, #0
 *   @0x163f48 beq 0x164190 <_ZN9C3D_Model12LoadFromFileEPKc+0x294>
 *   @0x163f4c add r7, sp, #72
 *   @0x163f50 mov r0, r4
 *   @0x163f54 mov r1, r7
 *   @0x163f58 bl 0x163dbc <_Z6ReadLnP7CStreamRPKc>
 *   @0x163f5c ldr r1, [pc, #0x280]
 *   @0x163f60 ldr r0, [sp, #0x48]
 *   @0x163f64 add r1, pc, r1
 *   @0x163f68 bl 0xb6574 <strcmp@plt>
 *   @0x163f6c cmp r0, #0
 *   @0x163f70 beq 0x163f98 <_ZN9C3D_Model12LoadFromFileEPKc+0x9c>
 *   @0x163f74 cmp r4, #0
 *   @0x163f78 beq 0x1641b4 <_ZN9C3D_Model12LoadFromFileEPKc+0x2b8>
 *   @0x163f7c mov r0, r4
 *   @0x163f80 bl 0x201328 <_ZN7CStreamD2Ev>
 *   @0x163f84 mov r0, r4
 *   @0x163f88 bl 0x27d1d0 <_ZdlPv>
 *   @0x163f8c mov r0, r6
 *   @0x163f90 add sp, sp, #124
 *   @0x163f94 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x163f98 mov r0, r4
 *   @0x163f9c mov r1, r7
 *   @0x163fa0 bl 0x163dbc <_Z6ReadLnP7CStreamRPKc>
 *   @0x163fa4 ldr r0, [sp, #0x48]
 *   @0x163fa8 cmp r0, #0
 *   @0x163fac ldreq r0, [r5]
 *   @0x163fb0 beq 0x163fbc <_ZN9C3D_Model12LoadFromFileEPKc+0xc0>
 *   @0x163fb4 bl 0xb66b8 <atoi@plt>
 *   @0x163fb8 str r0, [r5]
 *   @0x163fbc cmp r0, #0
 *   @0x163fc0 ble 0x16416c <_ZN9C3D_Model12LoadFromFileEPKc+0x270>
 *   @0x163fc4 ldr r2, [pc, #0x21c]
 *   @0x163fc8 lsl r1, r0, #2
 *   @0x163fcc mov r3, #162
 *   @0x163fd0 add r0, r5, #8
 *   @0x163fd4 add r2, pc, r2
 *   @0x163fd8 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x163fdc ldr r3, [r5]
 *   @0x163fe0 cmp r3, #0
 *   @0x163fe4 str r3, [r5, #0x4]
 *   @0x163fe8 ble 0x16416c <_ZN9C3D_Model12LoadFromFileEPKc+0x270>
 *   @0x163fec ldr r11, [pc, #0x1f8]
 *   @0x163ff0 add r10, sp, #76
 *   @0x163ff4 add r9, sp, #80
 *   @0x163ff8 add r8, sp, #84
 *   @0x163ffc add r11, pc, r11
 *   @0x164000 mov r6, #0
 *   @0x164004 add r12, sp, #88
 *   @0x164008 str r12, [sp, #0x28]
 *   @0x16400c add r12, sp, #92
 *   @0x164010 str r12, [sp, #0x2c]
 *   @0x164014 add r12, sp, #96
 *   @0x164018 str r12, [sp, #0x30]
 *   @0x16401c add r12, sp, #100
 *   @0x164020 str r12, [sp, #0x34]
 *   @0x164024 add r12, sp, #104
 *   @0x164028 str r12, [sp, #0x38]
 *   @0x16402c add r12, sp, #108
 *   @0x164030 str r12, [sp, #0x3c]
 *   @0x164034 add r12, sp, #112
 *   @0x164038 str r12, [sp, #0x40]
 *   @0x16403c add r12, sp, #116
 *   @0x164040 str r12, [sp, #0x44]
 *   @0x164044 mov r1, r10
 *   @0x164048 mov r0, r4
 *   @0x16404c mov r3, #0
 *   @0x164050 str r3, [sp, #0x4c]
 *   @0x164054 bl 0x163dbc <_Z6ReadLnP7CStreamRPKc>
 *   @0x164058 mov r0, #44
 *   @0x16405c ldr r7, [r5, #0x8]
 *   @0x164060 bl 0x27c524 <_Znwj>
 *   @0x164064 mov r1, r11
 *   @0x164068 mov r3, r9
 *   @0x16406c add r12, sp, #88
 *   @0x164070 str r0, [r7, r6, lsl #2]
 *   @0x164074 ldr r2, [r5, #0x8]
 *   @0x164078 ldr r0, [sp, #0x4c]
 *   @0x16407c ldr r2, [r2, r6, lsl #2]
 *   @0x164080 str r12, [sp, #0x4]
 *   @0x164084 add r12, sp, #92
 *   @0x164088 str r8, [sp]
 *   @0x16408c str r12, [sp, #0x8]
 *   @0x164090 add r12, sp, #96
 *   @0x164094 str r12, [sp, #0xc]
 *   @0x164098 add r12, sp, #100
 *   @0x16409c str r12, [sp, #0x10]
 *   @0x1640a0 add r12, sp, #104
 *   @0x1640a4 str r12, [sp, #0x14]
 *   @0x1640a8 add r12, sp, #108
 *   @0x1640ac str r12, [sp, #0x18]
 *   @0x1640b0 add r12, sp, #112
 *   @0x1640b4 str r12, [sp, #0x1c]
 *   @0x1640b8 add r12, sp, #116
 *   @0x1640bc str r12, [sp, #0x20]
 *   @0x1640c0 bl 0xb68f8 <sscanf@plt>
 *   @0x1640c4 ldr r3, [r5, #0x8]
 *   @0x1640c8 ldr r2, [sp, #0x50]
 *   @0x1640cc ldr r3, [r3, r6, lsl #2]
 *   @0x1640d0 str r2, [r3, #0x4]
 *   @0x1640d4 ldr r2, [sp, #0x54]
 *   @0x1640d8 str r2, [r3, #0x8]
 *   @0x1640dc ldr r2, [sp, #0x58]
 *   @0x1640e0 str r2, [r3, #0xc]
 *   @0x1640e4 vldr s12, [sp, #92]
 *   @0x1640e8 vstr s12, [r3, #16]
 *   @0x1640ec ldr r2, [sp, #0x60]
 *   @0x1640f0 str r2, [r3, #0x14]
 *   @0x1640f4 vldr s13, [sp, #100]
 *   @0x1640f8 vstr s13, [r3, #24]
 *   @0x1640fc vldr s14, [sp, #104]
 *   @0x164100 vstr s14, [r3, #28]
 *   @0x164104 ldr r1, [sp, #0x6c]
 *   @0x164108 ldr r2, [r3]
 *   @0x16410c str r1, [r3, #0x20]
 *   @0x164110 sub r2, r2, #3
 *   @0x164114 vldr s15, [sp, #112]
 *   @0x164118 vstr s15, [r3, #36]
 *   @0x16411c ldr r1, [sp, #0x74]
 *   @0x164120 str r1, [r3, #0x28]
 *   @0x164124 cmp r2, #6
 *   @0x164128 addls pc, pc, r2, lsl #2
 *   @0x16412c b 0x164154 <_ZN9C3D_Model12LoadFromFileEPKc+0x258>
 *   @0x164130 b 0x1641cc <_ZN9C3D_Model12LoadFromFileEPKc+0x2d0>
 *   @0x164134 b 0x164154 <_ZN9C3D_Model12LoadFromFileEPKc+0x258>
 *   @0x164138 b 0x1641d8 <_ZN9C3D_Model12LoadFromFileEPKc+0x2dc>
 *   @0x16413c b 0x164154 <_ZN9C3D_Model12LoadFromFileEPKc+0x258>
 *   @0x164140 b 0x1641c0 <_ZN9C3D_Model12LoadFromFileEPKc+0x2c4>
 *   @0x164144 b 0x164154 <_ZN9C3D_Model12LoadFromFileEPKc+0x258>
 *   @0x164148 b 0x16414c <_ZN9C3D_Model12LoadFromFileEPKc+0x250>
 *   @0x16414c vcvt.s32.f32 s15, s15
 *   @0x164150 vstr s15, [r3, #36]
 *   @0x164154 ldr r0, [sp, #0x4c]
 *   @0x164158 add r6, r6, #1
 *   @0x16415c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x164160 ldr r3, [r5]
 *   @0x164164 cmp r3, r6
 *   @0x164168 bgt 0x164044 <_ZN9C3D_Model12LoadFromFileEPKc+0x148>
 *   @0x16416c cmp r4, #0
 *   @0x164170 beq 0x164184 <_ZN9C3D_Model12LoadFromFileEPKc+0x288>
 *   @0x164174 mov r0, r4
 *   @0x164178 bl 0x201328 <_ZN7CStreamD2Ev>
 *   @0x16417c mov r0, r4
 *   @0x164180 bl 0x27d1d0 <_ZdlPv>
 *   @0x164184 mov r0, #1
 *   @0x164188 add sp, sp, #124
 *   @0x16418c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x164190 cmp r4, r6
 *   @0x164194 beq 0x1641b4 <_ZN9C3D_Model12LoadFromFileEPKc+0x2b8>
 *   @0x164198 mov r0, r4
 *   @0x16419c bl 0x201328 <_ZN7CStreamD2Ev>
 *   @0x1641a0 mov r0, r4
 *   @0x1641a4 bl 0x27d1d0 <_ZdlPv>
 *   @0x1641a8 mov r0, r7
 *   @0x1641ac add sp, sp, #124
 *   @0x1641b0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1641b4 mov r0, #0
 *   @0x1641b8 add sp, sp, #124
 *   @0x1641bc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1641c0 vcvt.s32.f32 s14, s14
 *   @0x1641c4 vstr s14, [r3, #28]
 *   @0x1641c8 b 0x164154 <_ZN9C3D_Model12LoadFromFileEPKc+0x258>
 *   @0x1641cc vcvt.s32.f32 s12, s12
 *   @0x1641d0 vstr s12, [r3, #16]
 *   @0x1641d4 b 0x164154 <_ZN9C3D_Model12LoadFromFileEPKc+0x258>
 *   @0x1641d8 vcvt.s32.f32 s13, s13
 *   @0x1641dc vstr s13, [r3, #24]
 *   @0x1641e0 b 0x164154 <_ZN9C3D_Model12LoadFromFileEPKc+0x258>
 *   @0x1641e4 ldrsheq r6, [lr], -r0
 *   @0x1641e8 andseq r6, lr, r0, asr #10
 *   @0x1641ec andseq r6, lr, r12, asr r5
 *
 * ══ §35/39 CInstance::Collision_Rectangle(float, float, float, float, bool)  0x1946f4  size 756  189 条（0x1946f4..0x1949e8）
 * @func 0x1946f4 0x1949e8  size 756  189 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8×6 / CInstance::SkeletonAnimation() / CSkeletonInstance::ComputeBoundingBox(tagYYRECT*, int, float, float, float, float, float) / Sprite_Data(int) / CSkeletonInstance::RectangleCollision(int, float, float, float, float, float, float, float, float, float) / CInstance::Compute_BoundingBox(bool) / CSprite::PreciseCollisionRectangle(int, tagYYRECT*, int, int, float, float, float, tagYYRECT*)
 * 字段偏移 top8: 0xa0×3 / 0x98×3 / 0x9c×3 / 0x4×3 / 0x8×3 / 0xb8×2 / 0xb4×2 / 0xc×2
 * VFP 指令 81 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1946f4 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x1946f8 vpush {d8, d9}
 *   @0x1946fc sub sp, sp, #52
 *   @0x194700 vldr s18, [sp, #96]
 *   @0x194704 mov r4, r0
 *   @0x194708 vmov s16, r3
 *   @0x19470c vmov s17, r1
 *   @0x194710 ldrb r7, [sp, #0x64]
 *   @0x194714 vmov s19, r2
 *   @0x194718 bl 0x193158 <_ZN9CInstance17SkeletonAnimationEv>
 *   @0x19471c subs r8, r0, #0
 *   @0x194720 ldrbeq r3, [r4, #0x64]
 *   @0x194724 beq 0x194790 <_ZN9CInstance19Collision_RectangleEffffb+0x9c>
 *   @0x194728 vldr s15, [r4, #144]
 *   @0x19472c vcvt.s32.f32 s15, s15
 *   @0x194730 ldr r5, [pc, #0x2ac]
 *   @0x194734 ldr r1, [r4, #0xa0]
 *   @0x194738 ldr r9, [r4, #0xb8]
 *   @0x19473c ldr r5, [pc, r5]
 *   @0x194740 ldr lr, [r4, #0x98]
 *   @0x194744 ldr r12, [r4, #0x9c]
 *   @0x194748 ldr r3, [r4, #0xb4]
 *   @0x19474c ldr r6, [r5]
 *   @0x194750 vmov r2, s15
 *   @0x194754 str r4, [r5]
 *   @0x194758 str r1, [sp, #0xc]
 *   @0x19475c add r1, r4, #232
 *   @0x194760 str r9, [sp]
 *   @0x194764 str lr, [sp, #0x4]
 *   @0x194768 str r12, [sp, #0x8]
 *   @0x19476c bl 0xbeda8 <_ZN17CSkeletonInstance18ComputeBoundingBoxEP9tagYYRECTifffff>
 *   @0x194770 str r6, [r5]
 *   @0x194774 cmp r0, #0
 *   @0x194778 ldrbeq r3, [r4, #0x64]
 *   @0x19477c movne r2, #0
 *   @0x194780 movne r3, r2
 *   @0x194784 movne r1, #1
 *   @0x194788 strbne r2, [r4, #0x64]
 *   @0x19478c strbne r1, [r4, #0xb0]
 *   @0x194790 cmp r3, #0
 *   @0x194794 bne 0x194960 <_ZN9CInstance19Collision_RectangleEffffb+0x26c>
 *   @0x194798 ldr r3, [r4, #0xf0]
 *   @0x19479c vcmpe.f32 s17, s16
 *   @0x1947a0 add r3, r3, #1
 *   @0x1947a4 vmov s12, r3
 *   @0x1947a8 vmrs APSR_nzcv, fpscr
 *   @0x1947ac vmovpl.f32 s14, s16
 *   @0x1947b0 vmovmi.f32 s14, s17
 *   @0x1947b4 vcvt.f32.s32 s15, s12
 *   @0x1947b8 vcmpe.f32 s14, s15
 *   @0x1947bc vmrs APSR_nzcv, fpscr
 *   @0x1947c0 bge 0x194950 <_ZN9CInstance19Collision_RectangleEffffb+0x25c>
 *   @0x1947c4 vcmpe.f32 s17, s16
 *   @0x1947c8 vldr s13, [r4, #232]
 *   @0x1947cc vcvt.f32.s32 s15, s13
 *   @0x1947d0 vmrs APSR_nzcv, fpscr
 *   @0x1947d4 vmovle.f32 s14, s16
 *   @0x1947d8 vmovgt.f32 s14, s17
 *   @0x1947dc vcmpe.f32 s14, s15
 *   @0x1947e0 vmrs APSR_nzcv, fpscr
 *   @0x1947e4 bmi 0x194950 <_ZN9CInstance19Collision_RectangleEffffb+0x25c>
 *   @0x1947e8 ldr r3, [r4, #0xf4]
 *   @0x1947ec vcmpe.f32 s19, s18
 *   @0x1947f0 add r3, r3, #1
 *   @0x1947f4 vmov s14, r3
 *   @0x1947f8 vmrs APSR_nzcv, fpscr
 *   @0x1947fc vcvt.f32.s32 s15, s14
 *   @0x194800 vmovpl.f32 s14, s18
 *   @0x194804 vmovmi.f32 s14, s19
 *   @0x194808 vcmpe.f32 s14, s15
 *   @0x19480c vmrs APSR_nzcv, fpscr
 *   @0x194810 bge 0x194950 <_ZN9CInstance19Collision_RectangleEffffb+0x25c>
 *   @0x194814 vcmpe.f32 s19, s18
 *   @0x194818 vldr s12, [r4, #236]
 *   @0x19481c vcvt.f32.s32 s15, s12
 *   @0x194820 vmrs APSR_nzcv, fpscr
 *   @0x194824 vmovle.f32 s14, s18
 *   @0x194828 vmovgt.f32 s14, s19
 *   @0x19482c vcmpe.f32 s14, s15
 *   @0x194830 vmrs APSR_nzcv, fpscr
 *   @0x194834 bmi 0x194950 <_ZN9CInstance19Collision_RectangleEffffb+0x25c>
 *   @0x194838 ldrb r3, [r4, #0x68]
 *   @0x19483c cmp r3, #0
 *   @0x194840 bne 0x194950 <_ZN9CInstance19Collision_RectangleEffffb+0x25c>
 *   @0x194844 cmp r7, #0
 *   @0x194848 beq 0x194970 <_ZN9CInstance19Collision_RectangleEffffb+0x27c>
 *   @0x19484c ldrb r3, [r4, #0xb0]
 *   @0x194850 cmp r3, #0
 *   @0x194854 beq 0x194970 <_ZN9CInstance19Collision_RectangleEffffb+0x27c>
 *   @0x194858 ldr r0, [r4, #0xac]
 *   @0x19485c cmp r0, #0
 *   @0x194860 ldrlt r0, [r4, #0x8c]
 *   @0x194864 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x194868 cmp r0, #0
 *   @0x19486c mov r5, r0
 *   @0x194870 beq 0x194950 <_ZN9CInstance19Collision_RectangleEffffb+0x25c>
 *   @0x194874 ldr r3, [r0, #0x18]
 *   @0x194878 cmp r3, #0
 *   @0x19487c beq 0x194950 <_ZN9CInstance19Collision_RectangleEffffb+0x25c>
 *   @0x194880 vcmpe.f32 s17, s16
 *   @0x194884 vmrs APSR_nzcv, fpscr
 *   @0x194888 vmovpl.f32 s15, s16
 *   @0x19488c vmovmi.f32 s15, s17
 *   @0x194890 vcvt.f64.f32 d6, s15
 *   @0x194894 vmov r0, r1, d6
 *   @0x194898 bl 0xb66e8 <lrint@plt>
 *   @0x19489c vcmpe.f32 s19, s18
 *   @0x1948a0 vmrs APSR_nzcv, fpscr
 *   @0x1948a4 vmovpl.f32 s15, s18
 *   @0x1948a8 vmovmi.f32 s15, s19
 *   @0x1948ac vcvt.f64.f32 d6, s15
 *   @0x1948b0 str r0, [sp, #0x20]
 *   @0x1948b4 vmov r0, r1, d6
 *   @0x1948b8 bl 0xb66e8 <lrint@plt>
 *   @0x1948bc vcmpe.f32 s17, s16
 *   @0x1948c0 vmrs APSR_nzcv, fpscr
 *   @0x1948c4 vmovle.f32 s15, s16
 *   @0x1948c8 vmovgt.f32 s15, s17
 *   @0x1948cc vcvt.f64.f32 d6, s15
 *   @0x1948d0 str r0, [sp, #0x24]
 *   @0x1948d4 vmov r0, r1, d6
 *   @0x1948d8 bl 0xb66e8 <lrint@plt>
 *   @0x1948dc vcmpe.f32 s19, s18
 *   @0x1948e0 vmrs APSR_nzcv, fpscr
 *   @0x1948e4 vmovle.f32 s15, s18
 *   @0x1948e8 vmovgt.f32 s15, s19
 *   @0x1948ec vcvt.f64.f32 d6, s15
 *   @0x1948f0 str r0, [sp, #0x28]
 *   @0x1948f4 vmov r0, r1, d6
 *   @0x1948f8 bl 0xb66e8 <lrint@plt>
 *   @0x1948fc cmp r8, #0
 *   @0x194900 str r0, [sp, #0x2c]
 *   @0x194904 beq 0x194978 <_ZN9CInstance19Collision_RectangleEffffb+0x284>
 *   @0x194908 vstr s17, [sp, #12]
 *   @0x19490c vstr s19, [sp, #16]
 *   @0x194910 vstr s16, [sp, #20]
 *   @0x194914 vstr s18, [sp, #24]
 *   @0x194918 vldr s15, [r4, #144]
 *   @0x19491c vcvt.s32.f32 s15, s15
 *   @0x194920 ldr r12, [r4, #0x98]
 *   @0x194924 mov r0, r8
 *   @0x194928 ldr r2, [r4, #0xb4]
 *   @0x19492c ldr r3, [r4, #0xb8]
 *   @0x194930 str r12, [sp]
 *   @0x194934 ldr lr, [r4, #0x9c]
 *   @0x194938 ldr r12, [r4, #0xa0]
 *   @0x19493c vmov r1, s15
 *   @0x194940 str lr, [sp, #0x4]
 *   @0x194944 str r12, [sp, #0x8]
 *   @0x194948 bl 0xbf434 <_ZN17CSkeletonInstance18RectangleCollisionEifffffffff>
 *   @0x19494c b 0x194954 <_ZN9CInstance19Collision_RectangleEffffb+0x260>
 *   @0x194950 mov r0, #0
 *   @0x194954 add sp, sp, #52
 *   @0x194958 vpop {d8, d9}
 *   @0x19495c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x194960 mov r0, r4
 *   @0x194964 mov r1, #1
 *   @0x194968 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb>
 *   @0x19496c b 0x194798 <_ZN9CInstance19Collision_RectangleEffffb+0xa4>
 *   @0x194970 mov r0, #1
 *   @0x194974 b 0x194954 <_ZN9CInstance19Collision_RectangleEffffb+0x260>
 *   @0x194978 vldr s15, [r4, #180]
 *   @0x19497c vcvt.f64.f32 d6, s15
 *   @0x194980 vldr s15, [r4, #144]
 *   @0x194984 vcvt.s32.f32 s15, s15
 *   @0x194988 vmov r0, r1, d6
 *   @0x19498c vmov r7, s15
 *   @0x194990 bl 0xb66e8 <lrint@plt>
 *   @0x194994 vldr s15, [r4, #184]
 *   @0x194998 vcvt.f64.f32 d6, s15
 *   @0x19499c mov r6, r0
 *   @0x1949a0 vmov r0, r1, d6
 *   @0x1949a4 bl 0xb66e8 <lrint@plt>
 *   @0x1949a8 ldr r12, [r4, #0x98]
 *   @0x1949ac ldr r2, [r4, #0x9c]
 *   @0x1949b0 mov r1, r7
 *   @0x1949b4 mov r3, r6
 *   @0x1949b8 str r12, [sp, #0x4]
 *   @0x1949bc str r2, [sp, #0x8]
 *   @0x1949c0 add r2, r4, #232
 *   @0x1949c4 ldr r12, [r4, #0xa0]
 *   @0x1949c8 str r12, [sp, #0xc]
 *   @0x1949cc add r12, sp, #32
 *   @0x1949d0 str r12, [sp, #0x10]
 *   @0x1949d4 str r0, [sp]
 *   @0x1949d8 mov r0, r5
 *   @0x1949dc bl 0x1e4c24 <_ZN7CSprite25PreciseCollisionRectangleEiP9tagYYRECTiifffS1_>
 *   @0x1949e0 b 0x194954 <_ZN9CInstance19Collision_RectangleEffffb+0x260>
 *   @0x1949e4 .word 0x002591f8
 *
 * ══ §36/39 b2ParticleSystem::JoinParticleGroupsCallback::operator()(int, int, int) const  0x2d5580  size 756  189 条（0x2d5580..0x2d5874）
 * @func 0x2d5580 0x2d5874  size 756  189 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ParticleSystem::JoinParticleGroupsCallback::operator()(int, int, int) const+0x48×3 / b2ParticleSystem::JoinParticleGroupsCallback::operator()(int, int, int) const+0x54 / b2BlockAllocator::Allocate(int) / 0xb65bc / b2BlockAllocator::Free(void*, int)
 * 字段偏移 top8: 0x10×7 / 0x8×3 / 0x4×3 / 0x2×3 / 0xc×3 / 0x98×3 / 0xa0×3 / 0x14×3
 * VFP 指令 94 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d5580 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2d5584 vpush {d8, d9, d10}
 *   @0x2d5588 mov r6, r0
 *   @0x2d558c ldr r0, [r0, #0x8]
 *   @0x2d5590 mov r5, r2
 *   @0x2d5594 mov r4, r1
 *   @0x2d5598 sub sp, sp, #36
 *   @0x2d559c ldr r2, [r0, #0x4]
 *   @0x2d55a0 cmp r2, r5
 *   @0x2d55a4 movle r1, #0
 *   @0x2d55a8 movgt r1, #1
 *   @0x2d55ac cmp r2, r4
 *   @0x2d55b0 addgt r1, r1, #1
 *   @0x2d55b4 cmp r2, r3
 *   @0x2d55b8 movgt r2, r1
 *   @0x2d55bc suble r2, r1, #1
 *   @0x2d55c0 cmp r2, #1
 *   @0x2d55c4 bls 0x2d55d4 <_ZNK16b2ParticleSystem26JoinParticleGroupsCallbackclEiii+0x54>
 *   @0x2d55c8 add sp, sp, #36
 *   @0x2d55cc vpop {d8, d9, d10}
 *   @0x2d55d0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2d55d4 ldr r7, [r6]
 *   @0x2d55d8 ldr r2, [r7, #0x30]
 *   @0x2d55dc ldr r11, [r2, r3, lsl #2]
 *   @0x2d55e0 ldr r8, [r2, r5, lsl #2]
 *   @0x2d55e4 ldr r12, [r2, r4, lsl #2]
 *   @0x2d55e8 and r1, r11, #16
 *   @0x2d55ec and r2, r1, r8
 *   @0x2d55f0 tst r2, r12
 *   @0x2d55f4 str r8, [sp, #0xc]
 *   @0x2d55f8 beq 0x2d55c8 <_ZNK16b2ParticleSystem26JoinParticleGroupsCallbackclEiii+0x48>
 *   @0x2d55fc ldr r9, [r7, #0x38]
 *   @0x2d5600 vmov.f32 s14, #4.000000e+00
 *   @0x2d5604 vldr s9, [r7, #32]
 *   @0x2d5608 add r10, r9, r4, lsl #3
 *   @0x2d560c add r8, r9, r5, lsl #3
 *   @0x2d5610 vldr s10, [r10, #4]
 *   @0x2d5614 vldr s12, [r8, #4]
 *   @0x2d5618 vldr s11, [r10]
 *   @0x2d561c vldr s13, [r8]
 *   @0x2d5620 add r9, r9, r3, lsl #3
 *   @0x2d5624 vldr s8, [r9]
 *   @0x2d5628 vldr s7, [r9, #4]
 *   @0x2d562c vsub.f32 s17, s10, s12
 *   @0x2d5630 vmul.f32 s15, s17, s17
 *   @0x2d5634 vsub.f32 s16, s11, s13
 *   @0x2d5638 vmla.f32 s15, s16, s16
 *   @0x2d563c vmul.f32 s14, s9, s14
 *   @0x2d5640 vcmpe.f32 s14, s15
 *   @0x2d5644 vmrs APSR_nzcv, fpscr
 *   @0x2d5648 ble 0x2d55c8 <_ZNK16b2ParticleSystem26JoinParticleGroupsCallbackclEiii+0x48>
 *   @0x2d564c vsub.f32 s19, s12, s7
 *   @0x2d5650 vmul.f32 s9, s19, s19
 *   @0x2d5654 vsub.f32 s18, s13, s8
 *   @0x2d5658 vmla.f32 s9, s18, s18
 *   @0x2d565c vcmpe.f32 s14, s9
 *   @0x2d5660 vmrs APSR_nzcv, fpscr
 *   @0x2d5664 ble 0x2d55c8 <_ZNK16b2ParticleSystem26JoinParticleGroupsCallbackclEiii+0x48>
 *   @0x2d5668 vsub.f32 s21, s7, s10
 *   @0x2d566c vmul.f32 s15, s21, s21
 *   @0x2d5670 vsub.f32 s20, s8, s11
 *   @0x2d5674 vmla.f32 s15, s20, s20
 *   @0x2d5678 vcmpe.f32 s14, s15
 *   @0x2d567c vmrs APSR_nzcv, fpscr
 *   @0x2d5680 ble 0x2d55c8 <_ZNK16b2ParticleSystem26JoinParticleGroupsCallbackclEiii+0x48>
 *   @0x2d5684 ldr r1, [r7, #0x9c]
 *   @0x2d5688 ldr r2, [r7, #0x98]
 *   @0x2d568c cmp r2, r1
 *   @0x2d5690 str r1, [sp, #0x10]
 *   @0x2d5694 bge 0x2d57cc <_ZNK16b2ParticleSystem26JoinParticleGroupsCallbackclEiii+0x24c>
 *   @0x2d5698 vmov.f32 s14, s7
 *   @0x2d569c str r0, [sp, #0x10]
 *   @0x2d56a0 vmov.f32 s15, s8
 *   @0x2d56a4 vldr s5, [pc, #452]
 *   @0x2d56a8 rsb r0, r2, r2, lsl #4
 *   @0x2d56ac ldr r1, [r6, #0x4]
 *   @0x2d56b0 vldr s6, [r1, #16]
 *   @0x2d56b4 vadd.f32 s13, s11, s13
 *   @0x2d56b8 ldr r1, [r7, #0xa0]
 *   @0x2d56bc ldr r6, [sp, #0x10]
 *   @0x2d56c0 vldr s9, [r6, #16]
 *   @0x2d56c4 ldr r6, [sp, #0xc]
 *   @0x2d56c8 lsl r0, r0, #2
 *   @0x2d56cc add r2, r2, #1
 *   @0x2d56d0 orr r11, r6, r11
 *   @0x2d56d4 str r4, [r1, r0]
 *   @0x2d56d8 orr r11, r11, r12
 *   @0x2d56dc add r12, r1, r0
 *   @0x2d56e0 str r11, [r12, #0xc]
 *   @0x2d56e4 str r5, [r12, #0x4]
 *   @0x2d56e8 str r3, [r12, #0x8]
 *   @0x2d56ec vadd.f32 s12, s10, s12
 *   @0x2d56f0 vadd.f32 s15, s13, s15
 *   @0x2d56f4 vadd.f32 s14, s12, s14
 *   @0x2d56f8 vmul.f32 s15, s15, s5
 *   @0x2d56fc vmul.f32 s14, s14, s5
 *   @0x2d5700 vsub.f32 s11, s11, s15
 *   @0x2d5704 vsub.f32 s10, s10, s14
 *   @0x2d5708 vstr s11, [r12, #20]
 *   @0x2d570c vstr s10, [r12, #24]
 *   @0x2d5710 vldr s12, [r8, #4]
 *   @0x2d5714 vldr s13, [r8]
 *   @0x2d5718 vsub.f32 s12, s12, s14
 *   @0x2d571c vsub.f32 s13, s13, s15
 *   @0x2d5720 vstr s12, [r12, #32]
 *   @0x2d5724 vstr s13, [r12, #28]
 *   @0x2d5728 vldr s12, [r9, #4]
 *   @0x2d572c vldr s13, [r9]
 *   @0x2d5730 vsub.f32 s14, s12, s14
 *   @0x2d5734 vsub.f32 s15, s13, s15
 *   @0x2d5738 vstr s14, [r12, #40]
 *   @0x2d573c vstr s15, [r12, #36]
 *   @0x2d5740 vldr s7, [r8, #4]
 *   @0x2d5744 vldr s11, [r9]
 *   @0x2d5748 vldr s10, [r10, #4]
 *   @0x2d574c vldr s8, [r8]
 *   @0x2d5750 vmul.f32 s13, s7, s11
 *   @0x2d5754 vldr s15, [r9, #4]
 *   @0x2d5758 vldr s5, [r10]
 *   @0x2d575c vmul.f32 s12, s10, s8
 *   @0x2d5760 vmul.f32 s14, s5, s15
 *   @0x2d5764 vnmls.f32 s13, s8, s15
 *   @0x2d5768 vnmls.f32 s12, s5, s7
 *   @0x2d576c vmul.f32 s15, s17, s21
 *   @0x2d5770 vmul.f32 s17, s17, s19
 *   @0x2d5774 vmul.f32 s19, s19, s21
 *   @0x2d5778 vnmls.f32 s14, s10, s11
 *   @0x2d577c vmla.f32 s15, s16, s20
 *   @0x2d5780 vmla.f32 s17, s16, s18
 *   @0x2d5784 vmla.f32 s19, s18, s20
 *   @0x2d5788 vadd.f32 s13, s12, s13
 *   @0x2d578c vadd.f32 s14, s13, s14
 *   @0x2d5790 vcmpe.f32 s6, s9
 *   @0x2d5794 vstr s14, [r12, #56]
 *   @0x2d5798 vneg.f32 s15, s15
 *   @0x2d579c vmrs APSR_nzcv, fpscr
 *   @0x2d57a0 vneg.f32 s17, s17
 *   @0x2d57a4 vstr s15, [r12, #44]
 *   @0x2d57a8 vneg.f32 s19, s19
 *   @0x2d57ac vstr s17, [r12, #48]
 *   @0x2d57b0 vmovmi.f32 s9, s6
 *   @0x2d57b4 vstr s19, [r12, #52]
 *   @0x2d57b8 vstr s9, [r12, #16]
 *   @0x2d57bc str r2, [r7, #0x98]
 *   @0x2d57c0 add sp, sp, #36
 *   @0x2d57c4 vpop {d8, d9, d10}
 *   @0x2d57c8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2d57cc cmp r2, #0
 *   @0x2d57d0 lslne lr, r2, #1
 *   @0x2d57d4 strne lr, [sp, #0x18]
 *   @0x2d57d8 rsbne r2, lr, r2, lsl #5
 *   @0x2d57dc moveq r0, #256
 *   @0x2d57e0 moveq r1, #15360
 *   @0x2d57e4 streq r0, [sp, #0x18]
 *   @0x2d57e8 lslne r1, r2, #2
 *   @0x2d57ec ldr r2, [r7, #0xa0]
 *   @0x2d57f0 ldr r0, [r7, #0xd4]
 *   @0x2d57f4 stmib sp, {r3, r12}
 *   @0x2d57f8 str r2, [sp, #0x14]
 *   @0x2d57fc bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2d5800 ldr lr, [sp, #0x10]
 *   @0x2d5804 ldr r1, [sp, #0x14]
 *   @0x2d5808 rsb r2, lr, lr, lsl #4
 *   @0x2d580c lsl r2, r2, #2
 *   @0x2d5810 str r2, [sp, #0x10]
 *   @0x2d5814 str r0, [sp, #0x1c]
 *   @0x2d5818 bl 0xb65bc <memcpy@plt>
 *   @0x2d581c ldr r0, [r7, #0xd4]
 *   @0x2d5820 ldr r2, [sp, #0x10]
 *   @0x2d5824 ldr r1, [sp, #0x14]
 *   @0x2d5828 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2d582c ldr r0, [r6, #0x8]
 *   @0x2d5830 ldr r1, [r6]
 *   @0x2d5834 vldr s11, [r10]
 *   @0x2d5838 ldr r2, [sp, #0x1c]
 *   @0x2d583c vldr s13, [r8]
 *   @0x2d5840 str r0, [sp, #0x10]
 *   @0x2d5844 vldr s10, [r10, #4]
 *   @0x2d5848 ldr r0, [sp, #0x18]
 *   @0x2d584c vldr s12, [r8, #4]
 *   @0x2d5850 str r2, [r7, #0xa0]
 *   @0x2d5854 vldr s15, [r9]
 *   @0x2d5858 ldr r2, [r1, #0x98]
 *   @0x2d585c mov r7, r1
 *   @0x2d5860 str r0, [r1, #0x9c]
 *   @0x2d5864 vldr s14, [r9, #4]
 *   @0x2d5868 ldmib sp, {r3, r12}
 *   @0x2d586c b 0x2d56a4 <_ZNK16b2ParticleSystem26JoinParticleGroupsCallbackclEiii+0x124>
 *   @0x2d5870 .word 0x3eaaaaab
 *
 * ══ §37/39 b2CollideEdgeAndCircle(b2Manifold*, b2EdgeShape const*, b2Transform const&, b2CircleShape const*, b2Transform const&)  0x2dceb0  size 756  189 条（0x2dceb0..0x2dd1a4）
 * @func 0x2dceb0 0x2dd1a4  size 756  189 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2CollideEdgeAndCircle(b2Manifold*, b2EdgeShape const*, b2Transform const&, b2CircleShape const*, b2Transform const&)+0x1b0 / b2CollideEdgeAndCircle(b2Manifold*, b2EdgeShape const*, b2Transform const&, b2CircleShape const*, b2Transform const&)+0x244 / 0xb6700
 * 字段偏移 top8: 0x3c×4 / 0x12×3 / 0x10×3 / 0x11×3 / 0x13×3 / 0x38×3 / 0x2c×3 / 0x28×2
 * VFP 指令 121 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2dceb0 push {r4, lr}
 *   @0x2dceb4 vpush {d8, d9}
 *   @0x2dceb8 sub sp, sp, #8
 *   @0x2dcebc vldr s14, [r3, #16]
 *   @0x2dcec0 vldr s7, [r3, #12]
 *   @0x2dcec4 vldr s1, [r2, #4]
 *   @0x2dcec8 ldr r12, [sp, #0x20]
 *   @0x2dcecc vldr s6, [r12, #12]
 *   @0x2dced0 vmul.f32 s12, s6, s14
 *   @0x2dced4 vldr s5, [r12, #8]
 *   @0x2dced8 vldr s15, [r12, #4]
 *   @0x2dcedc vldr s11, [r12]
 *   @0x2dcee0 vldr s13, [r2, #12]
 *   @0x2dcee4 vldr s2, [r2]
 *   @0x2dcee8 vldr s8, [r2, #8]
 *   @0x2dceec vldr s17, [r1, #16]
 *   @0x2dcef0 vldr s9, [r1, #24]
 *   @0x2dcef4 vldr s18, [r1, #12]
 *   @0x2dcef8 vldr s10, [r1, #20]
 *   @0x2dcefc vldr s3, [r1, #8]
 *   @0x2dcf00 mov r2, #0
 *   @0x2dcf04 vldr s4, [r3, #8]
 *   @0x2dcf08 mov r4, r0
 *   @0x2dcf0c str r2, [r0, #0x3c]
 *   @0x2dcf10 vmla.f32 s12, s7, s5
 *   @0x2dcf14 vmul.f32 s14, s5, s14
 *   @0x2dcf18 vnmls.f32 s14, s6, s7
 *   @0x2dcf1c vadd.f32 s15, s12, s15
 *   @0x2dcf20 vsub.f32 s15, s15, s1
 *   @0x2dcf24 vadd.f32 s11, s14, s11
 *   @0x2dcf28 vmul.f32 s14, s15, s13
 *   @0x2dcf2c vsub.f32 s11, s11, s2
 *   @0x2dcf30 vmul.f32 s15, s15, s8
 *   @0x2dcf34 vmls.f32 s14, s8, s11
 *   @0x2dcf38 vmla.f32 s15, s11, s13
 *   @0x2dcf3c vsub.f32 s6, s14, s17
 *   @0x2dcf40 vsub.f32 s12, s9, s17
 *   @0x2dcf44 vmul.f32 s13, s12, s6
 *   @0x2dcf48 vsub.f32 s7, s15, s18
 *   @0x2dcf4c vsub.f32 s16, s10, s18
 *   @0x2dcf50 vmla.f32 s13, s16, s7
 *   @0x2dcf54 vcmpe.f32 s13, #0
 *   @0x2dcf58 vadd.f32 s8, s3, s4
 *   @0x2dcf5c vmrs APSR_nzcv, fpscr
 *   @0x2dcf60 bls 0x2dd060 <_Z22b2CollideEdgeAndCircleP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK13b2CircleShapeS6_+0x1b0>
 *   @0x2dcf64 vsub.f32 s11, s9, s14
 *   @0x2dcf68 vmul.f32 s11, s12, s11
 *   @0x2dcf6c vsub.f32 s5, s10, s15
 *   @0x2dcf70 vmla.f32 s11, s16, s5
 *   @0x2dcf74 vcmpe.f32 s11, #0
 *   @0x2dcf78 vmrs APSR_nzcv, fpscr
 *   @0x2dcf7c bls 0x2dd0f4 <_Z22b2CollideEdgeAndCircleP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK13b2CircleShapeS6_+0x244>
 *   @0x2dcf80 vmul.f32 s3, s16, s16
 *   @0x2dcf84 vmul.f32 s4, s12, s12
 *   @0x2dcf88 vmov.f32 s2, #1.000000e+00
 *   @0x2dcf8c vadd.f32 s5, s3, s4
 *   @0x2dcf90 vdiv.f32 s5, s2, s5
 *   @0x2dcf94 vmul.f32 s9, s9, s13
 *   @0x2dcf98 vmul.f32 s13, s10, s13
 *   @0x2dcf9c vmla.f32 s9, s17, s11
 *   @0x2dcfa0 vmla.f32 s13, s18, s11
 *   @0x2dcfa4 vmls.f32 s14, s5, s9
 *   @0x2dcfa8 vmls.f32 s15, s5, s13
 *   @0x2dcfac vmul.f32 s14, s14, s14
 *   @0x2dcfb0 vmla.f32 s14, s15, s15
 *   @0x2dcfb4 vmul.f32 s8, s8, s8
 *   @0x2dcfb8 vcmpe.f32 s8, s14
 *   @0x2dcfbc vmrs APSR_nzcv, fpscr
 *   @0x2dcfc0 bmi 0x2dd054 <_Z22b2CollideEdgeAndCircleP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK13b2CircleShapeS6_+0x1a4>
 *   @0x2dcfc4 vmul.f32 s6, s16, s6
 *   @0x2dcfc8 vneg.f32 s19, s12
 *   @0x2dcfcc vmla.f32 s6, s19, s7
 *   @0x2dcfd0 vcmpe.f32 s6, #0
 *   @0x2dcfd4 vmrs APSR_nzcv, fpscr
 *   @0x2dcfd8 vnegmi.f32 s16, s16
 *   @0x2dcfdc vmulpl.f32 s4, s19, s19
 *   @0x2dcfe0 vmulmi.f32 s3, s16, s16
 *   @0x2dcfe4 vadd.f32 s4, s3, s4
 *   @0x2dcfe8 vsqrt.f32 s15, s4
 *   @0x2dcfec vcmp.f32 s15, s15
 *   @0x2dcff0 vmovmi.f32 s19, s12
 *   @0x2dcff4 vmrs APSR_nzcv, fpscr
 *   @0x2dcff8 bne 0x2dd188 <_Z22b2CollideEdgeAndCircleP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK13b2CircleShapeS6_+0x2d8>
 *   @0x2dcffc vldr s14, [pc, #412]
 *   @0x2dd000 add r3, r3, #12
 *   @0x2dd004 vcmpe.f32 s15, s14
 *   @0x2dd008 mov r1, #0
 *   @0x2dd00c mov r2, #1
 *   @0x2dd010 vstr s18, [r4, #48]
 *   @0x2dd014 vstr s17, [r4, #52]
 *   @0x2dd018 strb r2, [r4, #0x12]
 *   @0x2dd01c strb r1, [r4, #0x10]
 *   @0x2dd020 vmrs APSR_nzcv, fpscr
 *   @0x2dd024 vmovpl.f32 s14, #1.000000e+00
 *   @0x2dd028 strb r1, [r4, #0x11]
 *   @0x2dd02c strb r1, [r4, #0x13]
 *   @0x2dd030 vdivpl.f32 s15, s14, s15
 *   @0x2dd034 vmulpl.f32 s19, s19, s15
 *   @0x2dd038 vmulpl.f32 s16, s16, s15
 *   @0x2dd03c vstr s19, [r4, #40]
 *   @0x2dd040 vstr s16, [r4, #44]
 *   @0x2dd044 ldm r3, {r0, r1}
 *   @0x2dd048 str r2, [r4, #0x3c]
 *   @0x2dd04c str r2, [r4, #0x38]
 *   @0x2dd050 stm r4, {r0, r1}
 *   @0x2dd054 add sp, sp, #8
 *   @0x2dd058 vpop {d8, d9}
 *   @0x2dd05c pop {r4, pc}
 *   @0x2dd060 vmul.f32 s6, s6, s6
 *   @0x2dd064 vmla.f32 s6, s7, s7
 *   @0x2dd068 vmul.f32 s8, s8, s8
 *   @0x2dd06c vcmpe.f32 s8, s6
 *   @0x2dd070 vmrs APSR_nzcv, fpscr
 *   @0x2dd074 bmi 0x2dd054 <_Z22b2CollideEdgeAndCircleP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK13b2CircleShapeS6_+0x1a4>
 *   @0x2dd078 ldrb r2, [r1, #0x2c]
 *   @0x2dd07c cmp r2, #0
 *   @0x2dd080 beq 0x2dd0b0 <_Z22b2CollideEdgeAndCircleP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK13b2CircleShapeS6_+0x200>
 *   @0x2dd084 vsub.f32 s14, s17, s14
 *   @0x2dd088 vldr s12, [r1, #32]
 *   @0x2dd08c vldr s13, [r1, #28]
 *   @0x2dd090 vsub.f32 s12, s17, s12
 *   @0x2dd094 vmul.f32 s14, s12, s14
 *   @0x2dd098 vsub.f32 s15, s18, s15
 *   @0x2dd09c vsub.f32 s13, s18, s13
 *   @0x2dd0a0 vmla.f32 s14, s13, s15
 *   @0x2dd0a4 vcmpe.f32 s14, #0
 *   @0x2dd0a8 vmrs APSR_nzcv, fpscr
 *   @0x2dd0ac bgt 0x2dd054 <_Z22b2CollideEdgeAndCircleP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK13b2CircleShapeS6_+0x1a4>
 *   @0x2dd0b0 add r3, r3, #12
 *   @0x2dd0b4 mov r2, #0
 *   @0x2dd0b8 mov r1, #0
 *   @0x2dd0bc vstr s18, [r4, #48]
 *   @0x2dd0c0 vstr s17, [r4, #52]
 *   @0x2dd0c4 strb r2, [r4, #0x10]
 *   @0x2dd0c8 strb r2, [r4, #0x11]
 *   @0x2dd0cc mov r12, #1
 *   @0x2dd0d0 str r1, [r4, #0x28]
 *   @0x2dd0d4 strb r2, [r4, #0x12]
 *   @0x2dd0d8 str r1, [r4, #0x2c]
 *   @0x2dd0dc strb r2, [r4, #0x13]
 *   @0x2dd0e0 ldm r3, {r0, r1}
 *   @0x2dd0e4 str r2, [r4, #0x38]
 *   @0x2dd0e8 str r12, [r4, #0x3c]
 *   @0x2dd0ec stm r4, {r0, r1}
 *   @0x2dd0f0 b 0x2dd054 <_Z22b2CollideEdgeAndCircleP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK13b2CircleShapeS6_+0x1a4>
 *   @0x2dd0f4 vsub.f32 s14, s14, s9
 *   @0x2dd0f8 vmul.f32 s13, s14, s14
 *   @0x2dd0fc vsub.f32 s15, s15, s10
 *   @0x2dd100 vmla.f32 s13, s15, s15
 *   @0x2dd104 vmul.f32 s8, s8, s8
 *   @0x2dd108 vcmpe.f32 s8, s13
 *   @0x2dd10c vmrs APSR_nzcv, fpscr
 *   @0x2dd110 bmi 0x2dd054 <_Z22b2CollideEdgeAndCircleP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK13b2CircleShapeS6_+0x1a4>
 *   @0x2dd114 ldrb r2, [r1, #0x2d]
 *   @0x2dd118 cmp r2, #0
 *   @0x2dd11c beq 0x2dd144 <_Z22b2CollideEdgeAndCircleP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK13b2CircleShapeS6_+0x294>
 *   @0x2dd120 vldr s12, [r1, #40]
 *   @0x2dd124 vsub.f32 s12, s12, s9
 *   @0x2dd128 vldr s13, [r1, #36]
 *   @0x2dd12c vmul.f32 s14, s14, s12
 *   @0x2dd130 vsub.f32 s13, s13, s10
 *   @0x2dd134 vmla.f32 s14, s15, s13
 *   @0x2dd138 vcmpe.f32 s14, #0
 *   @0x2dd13c vmrs APSR_nzcv, fpscr
 *   @0x2dd140 bgt 0x2dd054 <_Z22b2CollideEdgeAndCircleP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK13b2CircleShapeS6_+0x1a4>
 *   @0x2dd144 add r3, r3, #12
 *   @0x2dd148 mov r2, #0
 *   @0x2dd14c mov r1, #0
 *   @0x2dd150 mov r12, #1
 *   @0x2dd154 vstr s10, [r4, #48]
 *   @0x2dd158 vstr s9, [r4, #52]
 *   @0x2dd15c strb r12, [r4, #0x10]
 *   @0x2dd160 strb r2, [r4, #0x11]
 *   @0x2dd164 strb r2, [r4, #0x12]
 *   @0x2dd168 str r1, [r4, #0x28]
 *   @0x2dd16c strb r2, [r4, #0x13]
 *   @0x2dd170 str r1, [r4, #0x2c]
 *   @0x2dd174 ldm r3, {r0, r1}
 *   @0x2dd178 str r12, [r4, #0x3c]
 *   @0x2dd17c str r2, [r4, #0x38]
 *   @0x2dd180 stm r4, {r0, r1}
 *   @0x2dd184 b 0x2dd054 <_Z22b2CollideEdgeAndCircleP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK13b2CircleShapeS6_+0x1a4>
 *   @0x2dd188 vmov r0, s4
 *   @0x2dd18c str r3, [sp, #0x4]
 *   @0x2dd190 bl 0xb6700 <sqrtf@plt>
 *   @0x2dd194 ldr r3, [sp, #0x4]
 *   @0x2dd198 vmov s15, r0
 *   @0x2dd19c b 0x2dcffc <_Z22b2CollideEdgeAndCircleP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK13b2CircleShapeS6_+0x14c>
 *   @0x2dd1a0 strlo r0, [r0], #-0
 *
 * ══ §38/39 F_DsGridGet_debug(RValue&, CInstance*, CInstance*, int, RValue*)  0x103d90  size 752  188 条（0x103d90..0x104080）
 * @func 0x103d90 0x104090  size 768  192 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / LOCK_RVALUE_MUTEX()×2 / UNLOCK_RVALUE_MUTEX()×2 / YYFree(void const*)×2 / operator delete(void*)×2 / F_DsGridGet_debug(RValue&, CInstance*, CInstance*, int, RValue*)+0x19c / F_DsGridGet_debug(RValue&, CInstance*, CInstance*, int, RValue*)+0x14c / F_DsGridGet_debug(RValue&, CInstance*, CInstance*, int, RValue*)+0x150
 * 字段偏移 top8: 0x4×15 / 0x8×8 / 0xc×7 / 0x30×1 / 0x28c×1 / 0x27c×1 / 0x2×1 / 0x18c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x103d90 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x103d94 sub sp, sp, #20
 *   @0x103d98 mov r1, #0
 *   @0x103d9c mov r6, r0
 *   @0x103da0 ldr r4, [sp, #0x30]
 *   @0x103da4 mov r0, r4
 *   @0x103da8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x103dac mov r1, #1
 *   @0x103db0 mov r5, r0
 *   @0x103db4 mov r0, r4
 *   @0x103db8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x103dbc mov r1, #2
 *   @0x103dc0 mov r7, r0
 *   @0x103dc4 mov r0, r4
 *   @0x103dc8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x103dcc cmp r5, #0
 *   @0x103dd0 mov r12, r0
 *   @0x103dd4 blt 0x103f2c <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x19c>
 *   @0x103dd8 ldr r2, [pc, #0x28c]
 *   @0x103ddc ldr r2, [pc, r2]
 *   @0x103de0 ldr r3, [r2]
 *   @0x103de4 cmp r5, r3
 *   @0x103de8 bge 0x103f2c <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x19c>
 *   @0x103dec ldr r3, [pc, #0x27c]
 *   @0x103df0 ldr r3, [pc, r3]
 *   @0x103df4 ldr r3, [r3, #0x4]
 *   @0x103df8 ldr r3, [r3, r5, lsl #2]
 *   @0x103dfc cmp r3, #0
 *   @0x103e00 beq 0x103f2c <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x19c>
 *   @0x103e04 cmp r7, #0
 *   @0x103e08 ldr r4, [r3, #0x4]
 *   @0x103e0c blt 0x103edc <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x14c>
 *   @0x103e10 cmp r7, r4
 *   @0x103e14 bge 0x103edc <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x14c>
 *   @0x103e18 cmp r0, #0
 *   @0x103e1c ldr r8, [r3, #0x8]
 *   @0x103e20 blt 0x103ee0 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x103e24 cmp r0, r8
 *   @0x103e28 bge 0x103ee0 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x103e2c mla r7, r4, r0, r7
 *   @0x103e30 ldr r2, [r6, #0xc]
 *   @0x103e34 ldr r8, [r3]
 *   @0x103e38 bic r3, r2, #-16777216
 *   @0x103e3c cmp r3, #1
 *   @0x103e40 add r5, r8, r7, lsl #4
 *   @0x103e44 beq 0x103fcc <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x23c>
 *   @0x103e48 cmp r3, #2
 *   @0x103e4c bne 0x103e74 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x103e50 sub r3, r2, #1
 *   @0x103e54 bic r3, r3, #-16777216
 *   @0x103e58 bic r3, r3, #3
 *   @0x103e5c cmp r3, #0
 *   @0x103e60 beq 0x10403c <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x2ac>
 *   @0x103e64 mov r2, #0
 *   @0x103e68 mov r3, #5
 *   @0x103e6c str r2, [r6, #0x8]
 *   @0x103e70 str r3, [r6, #0xc]
 *   @0x103e74 ldr r3, [r5, #0xc]
 *   @0x103e78 mov r1, #0
 *   @0x103e7c ldr r2, [r5, #0x8]
 *   @0x103e80 str r1, [r6]
 *   @0x103e84 str r3, [r6, #0xc]
 *   @0x103e88 ldr r3, [r5, #0xc]
 *   @0x103e8c str r2, [r6, #0x8]
 *   @0x103e90 bic r3, r3, #-16777216
 *   @0x103e94 cmp r3, #14
 *   @0x103e98 addls pc, pc, r3, lsl #2
 *   @0x103e9c b 0x103f24 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0x103ea0 b 0x103f50 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x1c0>
 *   @0x103ea4 b 0x103f8c <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x1fc>
 *   @0x103ea8 b 0x103f60 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x1d0>
 *   @0x103eac b 0x103f44 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x1b4>
 *   @0x103eb0 b 0x103f24 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0x103eb4 b 0x103f24 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0x103eb8 b 0x103fa4 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x214>
 *   @0x103ebc b 0x103f44 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x1b4>
 *   @0x103ec0 b 0x103f24 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0x103ec4 b 0x103f24 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0x103ec8 b 0x103f50 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x1c0>
 *   @0x103ecc b 0x103f24 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0x103ed0 b 0x103f24 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0x103ed4 b 0x103f50 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x1c0>
 *   @0x103ed8 b 0x103f44 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x1b4>
 *   @0x103edc ldr r8, [r3, #0x8]
 *   @0x103ee0 ldr r0, [pc, #0x18c]
 *   @0x103ee4 mov r2, r5
 *   @0x103ee8 ldr r1, [pc, #0x188]
 *   @0x103eec mov r3, r7
 *   @0x103ef0 ldr r0, [pc, r0]
 *   @0x103ef4 add r1, pc, r1
 *   @0x103ef8 ldr r0, [r0]
 *   @0x103efc ldr lr, [r0]
 *   @0x103f00 str r12, [sp]
 *   @0x103f04 stmib sp, {r4, r8}
 *   @0x103f08 ldr r12, [lr, #0xc]
 *   @0x103f0c blx r12
 *   @0x103f10 mov r3, #0
 *   @0x103f14 mov r2, #5
 *   @0x103f18 str r3, [r6]
 *   @0x103f1c str r2, [r6, #0xc]
 *   @0x103f20 str r3, [r6, #0x4]
 *   @0x103f24 add sp, sp, #20
 *   @0x103f28 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x103f2c ldr r0, [pc, #0x148]
 *   @0x103f30 mov r1, #0
 *   @0x103f34 add r0, pc, r0
 *   @0x103f38 add sp, sp, #20
 *   @0x103f3c pop {r4, r5, r6, r7, r8, r9, lr}
 *   @0x103f40 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x103f44 ldr r3, [r8, r7, lsl #4]
 *   @0x103f48 str r3, [r6]
 *   @0x103f4c b 0x103f24 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0x103f50 ldr r2, [r8, r7, lsl #4]
 *   @0x103f54 ldr r3, [r5, #0x4]
 *   @0x103f58 stm r6, {r2, r3}
 *   @0x103f5c b 0x103f24 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0x103f60 ldr r3, [r8, r7, lsl #4]
 *   @0x103f64 cmp r3, #0
 *   @0x103f68 str r3, [r6]
 *   @0x103f6c beq 0x103f24 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0x103f70 ldr r1, [r3, #0x8]
 *   @0x103f74 ldr r2, [r3]
 *   @0x103f78 cmp r1, #0
 *   @0x103f7c streq r6, [r3, #0x8]
 *   @0x103f80 add r2, r2, #1
 *   @0x103f84 str r2, [r3]
 *   @0x103f88 b 0x103f24 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0x103f8c ldr r3, [r8, r7, lsl #4]
 *   @0x103f90 cmp r3, #0
 *   @0x103f94 ldrne r2, [r3, #0x4]
 *   @0x103f98 addne r2, r2, #1
 *   @0x103f9c strne r2, [r3, #0x4]
 *   @0x103fa0 b 0x103f48 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x1b8>
 *   @0x103fa4 ldr r3, [r8, r7, lsl #4]
 *   @0x103fa8 str r3, [r6]
 *   @0x103fac ldr r3, [r8, r7, lsl #4]
 *   @0x103fb0 cmp r3, #0
 *   @0x103fb4 beq 0x103f24 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0x103fb8 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x103fbc ldr r1, [r8, r7, lsl #4]
 *   @0x103fc0 add sp, sp, #20
 *   @0x103fc4 pop {r4, r5, r6, r7, r8, r9, lr}
 *   @0x103fc8 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x103fcc ldr r4, [r6]
 *   @0x103fd0 cmp r4, #0
 *   @0x103fd4 beq 0x103ff4 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x264>
 *   @0x103fd8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x103fdc ldr r3, [r4, #0x4]
 *   @0x103fe0 sub r3, r3, #1
 *   @0x103fe4 str r3, [r4, #0x4]
 *   @0x103fe8 cmp r3, #0
 *   @0x103fec beq 0x104000 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x270>
 *   @0x103ff0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x103ff4 mov r3, #0
 *   @0x103ff8 str r3, [r6]
 *   @0x103ffc b 0x103e74 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x104000 ldr r0, [r4]
 *   @0x104004 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x104008 mov r3, #0
 *   @0x10400c str r3, [r4]
 *   @0x104010 str r3, [r4, #0x8]
 *   @0x104014 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x104018 ldr r9, [r4, #0x4]
 *   @0x10401c sub r9, r9, #1
 *   @0x104020 str r9, [r4, #0x4]
 *   @0x104024 cmp r9, #0
 *   @0x104028 beq 0x104048 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x2b8>
 *   @0x10402c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x104030 mov r0, r4
 *   @0x104034 bl 0x27d1d0 <_ZdlPv>
 *   @0x104038 b 0x103ff0 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x260>
 *   @0x10403c mov r0, r6
 *   @0x104040 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x104044 b 0x103e64 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x104048 ldr r0, [r4]
 *   @0x10404c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x104050 mov r0, r4
 *   @0x104054 str r9, [r4]
 *   @0x104058 str r9, [r4, #0x8]
 *   @0x10405c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x104060 mov r0, r4
 *   @0x104064 bl 0x27d1d0 <_ZdlPv>
 *   @0x104068 b 0x10402c <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x29c>
 *   @0x10406c eoreq r10, lr, r8, lsr #1
 *   @0x104070 mlaeq lr, r8, r0, r10
 *   @0x104074 eoreq r9, lr, r0, asr r10
 *   @0x104078 mlaeq r3, r8, r7, r4
 *   @0x10407c eoreq r3, r3, r8, asr #25
 *
 * ══ §39/39 Background_Add(char const*, bool, bool, bool)  0xc38d4  size 464  116 条（0xc38d4..0xc3aa4）
 * @func 0xc38d4 0xc3aa4  size 464  116 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xc394c→0x479cb8, 0xc3954→0x533c54, 0xc3a10→0x479cb8
 * 调用序列: 0xb65e0×2 / Background_CreateNew()×2 / operator new(unsigned int) / LoadSave::HTTP_Get(char const*, int, int (*)(HTTP_REQ_CONTEXT*, void*, int*), void (*)(HTTP_REQ_CONTEXT*), void*) / LoadSave::SaveFileExists(char const*) / LoadSave::BundleFileExists(char const*) / LoadSave::_GetBundleFileName(char*, int, char const*) / CBackground::LoadFromFile(char const*, bool, bool, bool, bool)
 * 字段偏移 top8: 0x40c×2 / 0x138×2 / 0x4×2 / 0x19c×1 / 0x198×1 / 0x178×1 / 0x160×1 / 0x13c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc38d4 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xc38d8 subs r5, r0, #0
 *   @0xc38dc ldr r4, [pc, #0x19c]
 *   @0xc38e0 mov r9, r3
 *   @0xc38e4 ldr r0, [pc, #0x198]
 *   @0xc38e8 sub sp, sp, #1040
 *   @0xc38ec add r4, pc, r4
 *   @0xc38f0 mov r8, r1
 *   @0xc38f4 mov r7, r2
 *   @0xc38f8 ldr r6, [r4, r0]
 *   @0xc38fc ldr r3, [r6]
 *   @0xc3900 str r3, [sp, #0x40c]
 *   @0xc3904 beq 0xc3a5c <_Z14Background_AddPKcbbb+0x188>
 *   @0xc3908 ldr r0, [pc, #0x178]
 *   @0xc390c mov r1, r5
 *   @0xc3910 mov r2, #7
 *   @0xc3914 add r0, pc, r0
 *   @0xc3918 bl 0xb65e0 <strncmp@plt>
 *   @0xc391c cmp r0, #0
 *   @0xc3920 beq 0xc3940 <_Z14Background_AddPKcbbb+0x6c>
 *   @0xc3924 ldr r0, [pc, #0x160]
 *   @0xc3928 mov r1, r5
 *   @0xc392c mov r2, #8
 *   @0xc3930 add r0, pc, r0
 *   @0xc3934 bl 0xb65e0 <strncmp@plt>
 *   @0xc3938 cmp r0, #0
 *   @0xc393c bne 0xc39d8 <_Z14Background_AddPKcbbb+0x104>
 *   @0xc3940 bl 0xc37d4 <_Z20Background_CreateNewv>
 *   @0xc3944 mov r0, #8
 *   @0xc3948 bl 0x27c524 <_Znwj>
 *   @0xc394c ldr r3, [pc, #0x13c]
 *   @0xc3950 cmp r7, #0
 *   @0xc3954 ldr lr, [pc, #0x138]
 *   @0xc3958 ldr r2, [pc, #0x138]
 *   @0xc395c mov r10, #1
 *   @0xc3960 movne r7, #2
 *   @0xc3964 moveq r7, #0
 *   @0xc3968 orr r8, r7, r8
 *   @0xc396c ldr r7, [r4, r3]
 *   @0xc3970 cmp r9, #0
 *   @0xc3974 ldr r3, [pc, #0x120]
 *   @0xc3978 mov r1, #7
 *   @0xc397c movne r9, #4
 *   @0xc3980 moveq r9, #0
 *   @0xc3984 orr r8, r8, r9
 *   @0xc3988 mov r12, r0
 *   @0xc398c str r8, [r0, #0x4]
 *   @0xc3990 mov r0, r5
 *   @0xc3994 ldr r5, [r7]
 *   @0xc3998 sub r5, r5, #1
 *   @0xc399c str r5, [r12]
 *   @0xc39a0 ldr lr, [r4, lr]
 *   @0xc39a4 strb r10, [lr]
 *   @0xc39a8 ldr r2, [r4, r2]
 *   @0xc39ac ldr r3, [r4, r3]
 *   @0xc39b0 str r12, [sp]
 *   @0xc39b4 bl 0x18fc68 <_ZN8LoadSave8HTTP_GetEPKciPFiP16HTTP_REQ_CONTEXTPvPiEPFvS3_ES4_>
 *   @0xc39b8 ldr r0, [r7]
 *   @0xc39bc sub r0, r0, #1
 *   @0xc39c0 ldr r2, [sp, #0x40c]
 *   @0xc39c4 ldr r3, [r6]
 *   @0xc39c8 cmp r2, r3
 *   @0xc39cc bne 0xc3a7c <_Z14Background_AddPKcbbb+0x1a8>
 *   @0xc39d0 add sp, sp, #1040
 *   @0xc39d4 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xc39d8 mov r0, r5
 *   @0xc39dc bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0xc39e0 cmp r0, #0
 *   @0xc39e4 bne 0xc3a64 <_Z14Background_AddPKcbbb+0x190>
 *   @0xc39e8 mov r0, r5
 *   @0xc39ec bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0xc39f0 cmp r0, #0
 *   @0xc39f4 beq 0xc3a5c <_Z14Background_AddPKcbbb+0x188>
 *   @0xc39f8 mov r2, r5
 *   @0xc39fc add r5, sp, #12
 *   @0xc3a00 mov r1, #1024
 *   @0xc3a04 mov r0, r5
 *   @0xc3a08 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc>
 *   @0xc3a0c bl 0xc37d4 <_Z20Background_CreateNewv>
 *   @0xc3a10 ldr r2, [pc, #0x78]
 *   @0xc3a14 mov r3, r7
 *   @0xc3a18 ldr r0, [pc, #0x80]
 *   @0xc3a1c eor r12, r8, #1
 *   @0xc3a20 mov r1, r5
 *   @0xc3a24 ldr r7, [r4, r2]
 *   @0xc3a28 add r0, pc, r0
 *   @0xc3a2c mov r2, r8
 *   @0xc3a30 ldr r0, [r0, #0x4]
 *   @0xc3a34 ldr lr, [r7]
 *   @0xc3a38 sub lr, lr, #-1073741823
 *   @0xc3a3c ldr r0, [r0, lr, lsl #2]
 *   @0xc3a40 stm sp, {r9, r12}
 *   @0xc3a44 bl 0xc2984 <_ZN11CBackground12LoadFromFileEPKcbbbb>
 *   @0xc3a48 cmp r0, #0
 *   @0xc3a4c bne 0xc39b8 <_Z14Background_AddPKcbbb+0xe4>
 *   @0xc3a50 ldr r3, [r7]
 *   @0xc3a54 sub r3, r3, #1
 *   @0xc3a58 str r3, [r7]
 *   @0xc3a5c mvn r0, #0
 *   @0xc3a60 b 0xc39c0 <_Z14Background_AddPKcbbb+0xec>
 *   @0xc3a64 mov r2, r5
 *   @0xc3a68 add r5, sp, #12
 *   @0xc3a6c mov r1, #1024
 *   @0xc3a70 mov r0, r5
 *   @0xc3a74 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0xc3a78 b 0xc3a0c <_Z14Background_AddPKcbbb+0x138>
 *   @0xc3a7c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0xc3a80 eorseq lr, r2, r4, ror #6
 *   @0xc3a84 .word 0xffffbd00
 *   @0xc3a88 eoreq sp, r6, r12, asr #3
 *   @0xc3a8c .word 0x0026d1b8
 *   @0xc3a90 .word 0xffffbcf8
 *   @0xc3a94 .word 0xffffbd04
 *   @0xc3a98 .word 0xffffbd08
 *   @0xc3a9c .word 0xffffbd0c
 *   @0xc3aa0 eorseq r6, r11, r0, lsl #5
 */
